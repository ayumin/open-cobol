/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While

   This file is part of GNU Cobol.

   The GNU Cobol runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GNU Cobol.  If not, see <http://www.gnu.org/licenses/>.




   OpenCOBOL fileio module. Re-engineered by BCS/JR. 2013
 */




#include "fileio-misc.h"


/*
 *	This entire module is excluded unless configured with WITH_INDEXED_ODBC
 *	=======================================================================
 *
 */

#if	defined(WITH_INDEXED_ODBC)



/*
 *	fileio-isam-odbc.c
 *
 *	OpenCOBOL fileio interface using ODBC to communicate with a SQL database
 *	server to provide handling for ORGANIZATION INDEXED files.
 *
 *	Each indexed file in a COBOL program is stored as a table in DB. The table
 *	is created when the COBOL file is OPENed OUTPUT.
 *	Each record written to the file inserts a row in the table.
 *
 *	The table design:
 *	1.	Each row has these fields:
 *		id       unique IDENTITY field (required to order DUPLICATES)
 *		type     0..data-record   1..control-record
 *		key_0    primary key
 *		key_1    first secondary key (if any)
 *		key_N    Nth secondary key (if any)
 *		rsz      record-size [field omitted if fixed-size records]
 *		data     data as read from or written to FILE FD
 *
 *	2.	There is a control record for each key declared in the COBOL file.
 *	3.	Keys are type BINARY.
 *		(1) This enables us to defeat the DB Server's 
 *		attempts to use collations. We want purely binary ordering.
 *		(2) Keys may contain non-character data (unfortunately) so SQL
 *		CHAR and VARCHAR are not used.
 *	4.	Data is type BINARY. Unless "big" when it's VARBINARY(MAX). 
 *	
 */



/*
 *	Connection Strings - DB and Table Selection
 *
 *
 *	Environmental variables:
 *		COB_ODBC_DSN ........ name of DSN 
 *		COB_ODBC_SERVER ..... name of database server known to ODBC Manager (NOT tcp/ip server name)
 *		COB_ODBC_DB ......... name of database
 *		COB_ODBC_UID ........ user (login) name
 *		COB_ODBC_PWD ........ user (login) password
 *
 *	Connection is made with either DSN or SERVER. A database qualification may be given: COB_ODBC_DB.
 *	DSN and SERVER are mutually exclusive. Whichever is declared by the user is called the
 *	"data_source" in this code and may affect the way file-names are interpreted.
 *		                            
 *	COBOL app FILE-NAME to DB table name mapping:
 *	#ifdef WITH_ODBC_DYNAMIC_CONNECTION
 *		Each COBOL expanded file-name is interpreted as:
 *			+3 segments :: data_source/database_name/table_name ("/" replaced by "_")
 *			 3 segments :: data_source/database_name/table_name
 *			 2 segments :: database_name/table_name
 *			 1 segment  :: table_name
 *		
 *		$VAR values are substituted for missing segments.
 *		This means that a COBOL app may access concurrently tables in 
 *		different databases on different servers. 
 *
 *	#ifndef WITH_ODBC_DYNAMIC_CONNECTION
 *		$VAR values are used for data_source & database names.
 *		All tables are located in the same database.
 *		The entire file-name is copied to table_name.
 *		
 *	The segment separators ("/") in table_name are
 *	replaced by "_".
 */


/*
 *	DB Connections:
 *	There is a "cursor" for each open file. Each cursor uses a separate connection.
 *	The "command" prepared statements share a single connection per SERVER + DB.
 *
 *	NYI Reconnect on lost connection.
 */

/*
 *	Sparse Keys:
 *	SQL/DB doesn't intrinsically support "sparse keys". When a row is
 *	INSERTed or UPDATEd, we cannot suppress the entry of fields into indexes.
 *	So to support sparse keys in COBOL we simply pretend these keys don't
 *	exist (and don't return them to the COBOL program).
 *	This is achieved by adding to the WHERE clause in the SELECT:
 *		WHERE (key_n != 0x'SPARSE_KEY_VALUE')
 *	On WRITE/REWRITE the new keys are separately pre-checked for duplicates.
 *
 *	The side-effect is that if another COBOL program subsequently opens the 
 *	file without declaring "suppress when all ...", it will read all
 *	the sparse keys as duplicates.
 */


#include "fileio-isam.h"
#include "sql.h"
#include "sqlext.h"

#define CB_AD_HOC 2051                           // misc buffer size :: min 2(CB_KEY_MAX) + 3

#define DEFAULT_MAX_BINARY 255                   // used if fail to interrogate DS for BINARY(MAX)
#define CB_BLOB_BLOCK 1024                       // BLOB DATA is read in blocks of this size

#ifdef WITH_ODBC_DYNAMIC_CONNECTION
#define MAX_CONNECTION 20                        // max connections: each server (from env and/or table_names)
#else
#define MAX_CONNECTION 1                         // single connection: server (from environment) 
#endif

#define UNSC unsigned char
#define SQLC SQLCHAR



#define CURSOR_FIRST    0
#define CURSOR_LT       1
#define CURSOR_LE       2
#define CURSOR_EQ       3
#define CURSOR_GE       4
#define CURSOR_GT       5
#define CURSOR_LAST     6
#define CURSOR_CURRENT  7

#define CURSOR_ADVANCE  0
#define CURSOR_RETREAT  1
		
 

#ifdef WITH_FILEIO_TRACE

#define KEY_TRAIL_START     0
#define KEY_TRAIL_READ      1
#define KEY_TRAIL_WRITE     2
#define KEY_TRAIL_REWRITE   3
#define KEY_TRAIL_DELETE    4
#define KEY_TRAIL_MAX       5

static const char *trail_caption[] = {
		  "START"
		, "READ"
		, "WRITE"
		, "REWRITE"
		, "DELETE"
};

#endif




typedef struct {
	int              c_io;                       // i-o count
	time_t           time;                       // time i-o occured
	char            *pb_pkey_value;              // pointer to primary-key value
	char            *pb_skey_value;              // pointer to secondary-key value (iff ix_key > 0)
	int              ix_key;                     // active index used to read record
	                                             // (ix_key > 0 if record was read by secondary-key value pb_skey_value)
} key_log_t;




/*
 * The file-position-indicator (fpi) records the current
 * position in the file. It is reset by READ and START.
 * READ NEXT is relative to the fpi.
 * (WRITE, REWRITE and DELETE do NOT change fpi).
*/
typedef struct {                                 // current record/row ::
	int              tf_is_set;                  // is loaded
	int              ix_key;                     // was read using this index (0..c_key-1)
	char           **key_value;                  // has value of key_0 ... key_n (malloc'd array of pointers)
	int              id;                         // is this IDENTITY 
} fpi_t;




typedef struct {
	int				 rb;                         // byte offset to start of component relative to start of record
	int				 cb;                         // byte-count size of component 
} component_t;


typedef struct {                                 // description of key - loaded from COBOL app or key-dictionary
	cob_field       *cob_field_key;              // pointer to matching key in struct cob_file. NULL if undeclared in COBOL
	int              cob_ix_key;                 // index to f->keys
	SQLLEN           cb_key;                     // byte-count size of composite-key 
	int              tf_duplicates;              // true if duplicate values OK for this key
	int              tf_suppress;                // true if some values suppressed for this key
	UNSC             ch_suppress;                // skip row if tf_suppress && (key == all this char)
	int              c_comp;                     // count of components
	component_t      comp[COB_MAX_KEYCOMP];      // components constituting key
} keydef_t;



typedef struct {                                 // row - as read from and written to DB table
	long             id;                         // field: id
	long             rsz;                        // field: rsz (variable length recs only)
	char            *data;                       // field: data
	char           **key_value;                  // field: key_0 ... key_n (malloc'd array of pointers)
	int              tf_found;                   // 0 -> SELECT...NOT_FOUND
} row_t;




typedef struct {
	char            *dsn;                        // name of DSN (or NULL)
	char            *driver_name;                // name of ODBC Driver (or NULL)
	char            *server_name;                // name of DB server (or NULL)
	char            *db_name;                    // name of database (on connect)
	char            *uid;                        // user id
	char            *pwd;                        // user password
	char            *extra;                      // supplementary for connection string
} con_props_t;



typedef struct {
	con_props_t      properties;
	char            *dbms_name;                  // title of db-server
	char            *server_name;                // name of DB server (discovered) at connection
	char            *db_name;                    // name of database (discovered) at connection
	char            *string;                     // coined connection string used
	SQLHDBC          h_dbc;                      // ODBC connection handle
	int              c_client;                   // count of files using this connection
	int              tf_is_made;                 // connection is allocated
	int              tf_is_open;                 // connection is currently open
	int              tf_is_sqlserver;            // TSQL :: VARBINARY(MAX) for N > 8000
	SQLINTEGER       max_binary;                 // max number of bytes allowed in BINARY(N)
} connection_t;


typedef struct {
	connection_t	 con;                        // ODBC connection used for this cursor
	SQLHSTMT         h_stmt;                     // currently active prepared statement
	int              direction;                  // direction of travel when cursor opened
	int              tf_resynch;                 // cursor invalidated and must be re-opened
} cursor_t;





/*
 * Fields required by ISAM file-handler (extra to struct cob_file).
 * Struct idx_file is malloc'd in cob_fileio_isam_open()
 * and is free'd when COBOL file is closed (implicitly or explicitly).
 *
 * A pointer (*file) in each COBOL file struct cob_file_t links 
 * to the corresponding struct idx_file.
 */
typedef struct {
	cob_file_t      *cob_file;                   // corresponding file (SELECT/FD) in COBOL program
	char            *db_name;                    // name of DB storing this file/table
	char            *table_name;                 // name of table in DB storing this file
	char            *dbt;                        // convenience for SQL stringing: <db-name>..<table-name>
	int              cb_key_max;                 // size of largest key
	int              c_key;                      // number of indexes referenced in COBOL - keydef[c_key]
	keydef_t        *keydef;                     // key descriptors (malloc)
	int              tf_fixed_rsz;               // file uses a fixed record-length
	int              tf_index_with_duplicates;   // one or more indexes permit duplicate values
	long             data_size;                  // length of row field [data]

	// current state:
	connection_t    *con_command;                // connection (in pool) used for INSERT/UPDATE/DELETE on this file
	cursor_t         cursor;                     // cursor opened for this file
	row_t            row;                        // row just read or written to DB table
	fpi_t            fpi;                        // file-position-indicator
	int              ix_key;                     // index in use (0..c_key-1)
	SQLLEN           cb_key_sig;                 // count of bytes in key to SELECT on
	char            *key_p_w;                    // primary-key value of last record written
	char            *key_work;                   // workspace for key_value
	int              fd_rsz;                     // bytes in (COBOL) record data
	SQLHSTMT         h_insert;                   // prepared SQL statements
	SQLHSTMT         h_update;
	SQLHSTMT         h_delete;

#ifdef WITH_FILEIO_TRACE
	key_log_t key_trail[KEY_TRAIL_MAX];          // audit-trail of latest IO actions
#endif
} idx_file_t;





typedef struct {
	const char      *fn;
	SQLHANDLE        handle;
	SQLSMALLINT      handle_type;
	SQLCHAR          odbc_state[7];
	SQLINTEGER       primary_erc;
	int              cb_msg_max;
	char            *msg;
} error_state_t;


#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-isam-odbc";
#endif


static SQLHENV h_env;                  // ODBC environment handle
static char bfr[CB_AD_HOC];            // buffer for misc. use



/*
 *	The environmental variables used to CONNECT to DB Server.
 *	[cf cob_fileio_isam_initialise() for var names]
 */
static con_props_t env_con_prop;



/*
 *	It is common for a COBOL app to open many files assigned to the same SERVER + DB.
 *	For efficiency we avoid opening an ODBC Connection for individual files
 *	but instead piggy-back on the already open connection.
 *	If #ifndef WITH_ODBC_DYNAMIC_CONNECTION then there is ONE connection, determined
 *	by environmental variables.
 */
static connection_t connection_pool[MAX_CONNECTION];


// when an ODBC function fails, _odbc_extract_error() is invoked to load this entity
static error_state_t error_state;


// scratchpad for SQL
static char sql[1024], *p_sql;

// ensure DB PASSWORD is not logged in-the-clear.
static int tf_show_password = 0;


static SQLLEN data_grab_flag;          // used to trigger SQL_NEED_DATA






/*
 *	When doing CREATE table, we need to state field types
 *	native to the target DB server.
 *	We use either: BINARY(N) or for large fields varBINARY.
 */

#define DATA_IS_BIG(con, cb) (cb > con->max_binary)

#define SQL_FIELD_TYPE(con, cb) \
	(DATA_IS_BIG(con, cb) ? (con->tf_is_sqlserver ? "VARBINARY(MAX)" : "VARBINARY(%ld)") \
	                      : "BINARY(%ld)")






// Add macros here for documented ODBC states
#define EXC_IS_CANNOT_CONNECT (!strcmp((char *)error_state.odbc_state, "08001"))
#define EXC_IS_DUPLICATE_CONNECT (!strcmp((char *)error_state.odbc_state, "08002"))
#define EXC_IS_NO_CONNECT (!strcmp((char *)error_state.odbc_state, "08003"))
#define EXC_IS_DUPLICATE_KEY (!strcmp((char *)error_state.odbc_state, "23000"))




#define THROW_EXC(exc) \
	{ cob_fileio_throw_exc(f_idx->cob_file, exc, COB_IO_CONTEXT_FILEIO_INDEXED); return(-1); }


/*
 * Return value from ODBC functions is tested: 
 * 	if (SQL_SUCCEEDED(res)) ...
 *
 * Functions may return: SQL_SUCCESS or SQL_SUCCESS_WITH_INFO for both of which SQL_SUCCEEDED() returns true.
 *
 * Error texts are retrieved by calling function: _odbc_extract_error("SQLAllocHandle for dbc", envh, SQL_HANDLE_ENV);
 *
 */

#define SET_EXC_ODBC(fn, handle, handle_type, exc) \
	{	_odbc_extract_error(fn, handle, handle_type); \
		cob_fileio_throw_ext(f_idx->cob_file \
		                   , exc \
		                   , COB_IO_CONTEXT_FILEIO_INDEXED \
		                   , COB_IO_REALM_ODBC \
		                   , error_state.primary_erc \
		                   , error_state.msg); \
	}


#define THROW_EXC_ODBC(fn, handle, handle_type, exc) \
	{	SET_EXC_ODBC(fn, handle, handle_type, exc); \
		return(-1); \
	}


// LINUX errno 1..256
#define THROW_EXC_OS(exc) \
	{	cob_fileio_throw_ext(f_idx->cob_file, exc, COB_IO_CONTEXT_FILEIO_INDEXED \
			, COB_IO_REALM_OS, errno, strerror(errno)); \
		return(-1); \
	}






static int _odbc_open_file(
	  cob_file_t *f
	, const int mode) 


static idx_file_t *_odbc_get_handle(
	  cob_file_t *f);

static void _odbc_set_key_descriptors(
	  idx_file_t *f_idx
	, keydef_t *keys);

static void _odbc_free_handle(
	  cob_file_t *f);

static void _odbc_free_connection(
	  connection_t *con);

static void _odbc_malloc_fpi(
	  idx_file_t *f_idx);

static void _odbc_free_fpi(
	  idx_file_t *f_idx);

static void _odbc_set_fpi(
	  idx_file_t *f_idx);

static void _odbc_malloc_row(
	  idx_file_t *f_idx
	, row_t *row);

static void _odbc_free_row(
	  idx_file_t *f_idx
	, row_t *row);

static int _odbc_create_table(
	  idx_file_t *f_idx);

static int _odbc_table_exists(
	  idx_file_t *f_idx);

static int _odbc_create_key_dict(
	  idx_file_t *f_idx);

static int _odbc_get_db_key_descriptors(
	  idx_file_t *f_idx
	, keydef_t  **keys_ret
	, int *pc_keys);

static void _odbc_get_cobol_key_descriptors(
	  cob_file_t *f
	, keydef_t **keys_ret
	, int *c_key_ret);

static int _odbc_match_keys(
	  cob_file_t *f
	, keydef_t *keys
	, int c_key);

static int _odbc_get_key_ix(
	  idx_file_t *f_idx
	, cob_field *key_cobol);

static int _odbc_check_sparse_keys(
	  idx_file_t *f_idx
	, int *tf_is_dup);

static int _odbc_compose_key(
	  keydef_t *key
	, const void *pb_rec
	, char *pb_key_value);


static int _odbc_compose_row(
	  cob_file_t *f
	, unsigned char *cob_rec
	, const int cb_rec);


static void _odbc_extract_error(
	  const char *fn
	, SQLHANDLE handle
	, SQLSMALLINT handle_type);

static void _odbc_cat_msg(
	  char *msg);



static void _odbc_init_con_props(
	  con_props_t *props_in
	, con_props_t *props_out);

static int _odbc_prepare_connection(
	  cob_file_t *f
	, connection_t *con);


static int _odbc_connect(
	  cob_file_t *f
	, connection_t *con);

static char *_odbc_preen_filename(
	  char *fid);

static int _odbc_open_table(
	  cob_file_t *f);



#ifdef WITH_ODBC_DYNAMIC_CONNECTION

static int _odbc_modulate_properties(
	  cob_file_t *f
	, con_props_t *con_props_dft
	, con_props_t *con_props_ret);

static int _odbc_set_connection(
	  cob_file_t *f
	, con_props_t *con_props
	, connection_t **con_ret);

static int _odbc_parse_file_name(
	  char *server_name
	, char *db_name
	, char *table_name
	, char *file_name);

#endif



static int _odbc_make_insert_statement(
	  idx_file_t *f_idx);

static int _odbc_make_update_statement(
	  idx_file_t *f_idx);

static int _odbc_make_delete_statement(
	  idx_file_t *f_idx);

static int _odbc_resynch_cursor(
	  idx_file_t *f_idx);

static int _odbc_make_cursor(
	  idx_file_t *f_idx
	, int ix_key
	, int mode);

static int _odbc_execute_statement(
	  idx_file_t *f_idx
	, SQLHSTMT stmt);

static int _odbc_execute_sql(
	  idx_file_t *f_idx
	, char *sql
	, SQLHSTMT *h_stmt_ret);

static int _odbc_fetch_record(
	  idx_file_t *f_idx
	, SQLHSTMT *h_stmt
	, row_t *row);


static int _odbc_lock_record(
	  cob_file_t *f
	, int cob_lock);


static int _odbc_unlock_records(idx_file_t *f_idx);


#ifdef WITH_FILEIO_TRACE
static void _odbc_log_key(
	  idx_file_t *f_idx
	, int ix_key
	, char *pb_primary_key
	, char *pb_active_key
	, key_log_t *log_entry);

static char *_odbc_dump_file_description(
	  cob_file_t *f
	, int tf_show_counts);
#endif







/*
 *	Called once at program BOJ: initialise variables.
 *
 * 	Environmental variables referenced [default]:
 *		COB_ODBC_DSN         [NONE]
 *		COB_ODBC_SERVER      [NONE]
 *		COB_ODBC_DB          [NONE]
 *		COB_ODBC_DRIVER      [NONE]
 *		COB_ODBC_UID         [NONE]
 *		COB_ODBC_PWD         [NONE]
 *		COB_ODBC_EXTRA       [NONE]
 *		COB_ODBC_SHOW_PWD    [No]
 */
int cob_fileio_isam_initialise()
{

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 1) {
		fprintf(stderr, "%s: cob_fileio_isam_initialise() using: ODBC database server :: %s\n"
			, me
#ifdef WITH_ODBC_DYNAMIC_CONNECTION
			, "DYNAMIC_CONNECTION"
#else
			, "STATIC_CONNECTION"
#endif
);
	} 
#endif

	int ix;
	char *pb;

	for (ix = 0; ix < MAX_CONNECTION; ++ix) { 
		connection_pool[ix].tf_is_made = 0;
	}
	h_env = NULL;
	env_con_prop.dsn = getenv("COB_ODBC_DSN");
	env_con_prop.server_name = getenv("COB_ODBC_SERVER");
	env_con_prop.db_name = getenv("COB_ODBC_DB");
	env_con_prop.driver_name = getenv("COB_ODBC_DRIVER");
	env_con_prop.uid = getenv("COB_ODBC_UID");
	env_con_prop.pwd = getenv("COB_ODBC_PWD");
	env_con_prop.extra = getenv("COB_ODBC_EXTRA");

	pb = getenv("COB_ODBC_SHOW_PWD");
	tf_show_password = 0;
	if ((pb != NULL) 
		&& ((*pb == 'y') || (*pb == 'Y') || (*pb == '1') || (*pb == 't'))) {
		tf_show_password = 1;
	}
	return(0);
}





/*
 * Called once at program EOJ: release resources.
 *
 */
int cob_fileio_isam_terminate()
{
	int ix;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_terminate()\n", me);
#endif

	for (ix = 0; ix < MAX_CONNECTION; ++ix) {
		if (connection_pool[ix].tf_is_made) {
			_odbc_free_connection(&connection_pool[ix]);
		}
	}
	if (h_env != NULL)
		SQLFreeHandle(SQL_HANDLE_ENV, h_env);
	return(0);
}







/*
 * Open db table.
 * This function wraps the real file_open to ensure resources
 * are released if file_open fails.
 * 
 */
int cob_fileio_isam_open(
	  cob_file_t *f
	, const int mode)
{
	int res;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_open(%s open_mode=%d) share_mode=%d lock_mode=%d\n"
		              , me, f->select_name, mode, f->share_mode, f->lock_mode);
#endif

	res = _odbc_open_file(f, mode);
	if (res != 0) {
		_odbc_free_handle(f);
	} 
	return(res);
}






/*
 *	Close the ISAM file releasing all resources
 */
int cob_fileio_isam_close(
	  cob_file_t *f
	, const int opt)
{
	idx_file_t *f_idx = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_close(%s opt=%d)\n"
		              , me, f->select_name, opt);
#endif

	if (f_idx == NULL) return(0);
	cob_fileio_sharing_close_file(f); 
	_odbc_free_handle(f);
	f->open_mode = COB_OPEN_CLOSED;
	f->tf_is_locked = (opt == COB_CLOSE_LOCK);
	return(0);
}






/*
 *	Set the file position indicator to a selected record in the file.
 *
 *	The value of the key is extracted from the record-data.
 */
int cob_fileio_isam_start(
	  cob_file_t *f
	, const int cond
	, cob_field *key)
{
	idx_file_t *f_idx = f->file;
	int res, ix_key, cb_key, cursor_mode;
	char *pb_key_value;

	ix_key = _odbc_get_key_ix(f_idx, key);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_start(%s cond=%d cb_key=%d key=%s)\n"
		      , me, f->select_name, cond, key->size
		      , (ix_key != -1) ? cob_fileio_key_to_str(f->keys + f_idx->keydef[ix_key].cob_ix_key) 
		                       : "ILLEGAL-KEY");
#endif

	if ((ix_key == -1)) {
		// there is no matching key in db table.
		// deferred from COBOL OPEN, now throw exception
		THROW_EXC(COB_IOEXC_ISAM_NINDEX);
	}
	cb_key = f_idx->keydef[ix_key].cb_key;
	_odbc_compose_key(&f_idx->keydef[ix_key], f->record->data, f_idx->row.key_value[ix_key]);

	// Use size of key field; this may indicate a partial key  
	if ((key->size < 1) || (key->size >= cb_key)) {
		f_idx->cb_key_sig = cb_key; 
	} else {
		f_idx->cb_key_sig = key->size;
	}
	// copy key_value for comparison later
	pb_key_value = cob_malloc(cb_key);	
	memcpy(pb_key_value, f_idx->row.key_value[ix_key], cb_key);
	switch(cond) {
		case COB_LT:
			cursor_mode = CURSOR_LT;
			break;
		case COB_LE:
			cursor_mode = CURSOR_LE;
			break;
		case COB_EQ:
			cursor_mode = CURSOR_EQ;
			break;
		case COB_GE:
			cursor_mode = CURSOR_GE;
			break;
		case COB_GT:
			/*
				Given keys :: "AAA001" "AAA002" "AAA003" "BBB001" etc
				For partial key: START key > "AAA"
				SELECT data WHERE key > "AAA" returns "AAA001"
				COBOL specs "BBB001" should be returned.
				Solution: pack key with trailing 0xFF and SELECT on whole key.
			 */
			if (f_idx->cb_key_sig != cb_key) {
				memset(f_idx->row.key_value[ix_key] + f_idx->cb_key_sig
				     , 0xff
				     , cb_key - f_idx->cb_key_sig);
				f_idx->cb_key_sig = cb_key;
			}
			cursor_mode = CURSOR_GT;
			break;
		default:
			fprintf(stderr, "!!! Internal Error :: illegal START condition [%d]\n", cond);
			THROW_EXC(COB_IOEXC_INTERNAL);
	}
	if (0 == (res = _odbc_make_cursor(f_idx, ix_key, cursor_mode))) {
		res = _odbc_fetch_record(f_idx, f_idx->cursor.h_stmt, &f_idx->row);
	}
	if ((res == 0) && f_idx->row.tf_found && (cond == COB_EQ)) {
		// check cursor has not started at next key value
		if (memcmp(f_idx->row.key_value[ix_key], pb_key_value, f_idx->cb_key_sig)) {
			free(pb_key_value);
			THROW_EXC(COB_IOEXC_NOREC);
		}
	}
	free(pb_key_value);
	if (res != 0) {
		return(-1);
	}
	if (!f_idx->row.tf_found) {
		if ((cond == COB_GE) || (cond == COB_GT)) {
			f->tf_beyond_eof = 1;
		}
		THROW_EXC(COB_IOEXC_NOREC);
	}
	_odbc_set_fpi(f_idx);

#ifdef WITH_FILEIO_TRACE
	_odbc_log_key(f_idx
	            , f_idx->fpi.ix_key
                , f_idx->fpi.key_value[0]
                , f_idx->fpi.key_value[ix_key]
	            , &f_idx->key_trail[KEY_TRAIL_START]);
#endif

	return(0);
} 



	



/*
 *	Read the record with the specified key (RANDOM READ).
 */
int cob_fileio_isam_read(
	  cob_file_t *f
	, cob_field *key
	, const int opt)
{
	idx_file_t *f_idx = f->file;
	int ix_key, res;

	ix_key = _odbc_get_key_ix(f_idx, key);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_read(%s opt=%d  key=%s)\n"
		      , me, f->select_name, opt
		      , (ix_key != -1) ? cob_fileio_key_to_str(f->keys + f_idx->keydef[ix_key].cob_ix_key) 
		                       : "ILLEGAL-KEY");
#endif

	if ((ix_key == -1)) {
		// there is no matching key in db table.
		// deferred from COBOL OPEN, now throw exception
		THROW_EXC(COB_IOEXC_ISAM_NINDEX);
	}
	// Use size of key field; this may indicate a partial key  
	if ((key->size < 1) || (key->size > f_idx->keydef[ix_key].cb_key)) 
		f_idx->cb_key_sig = f_idx->keydef[ix_key].cb_key; 
	else
		f_idx->cb_key_sig = key->size;
	memset(f_idx->row.key_value[ix_key], '\0', f_idx->keydef[ix_key].cb_key);
	memcpy(f_idx->row.key_value[ix_key], key->data, f_idx->cb_key_sig);
	if (0 == (res = _odbc_make_cursor(f_idx, ix_key, CURSOR_EQ))) 
		res = _odbc_fetch_record(f_idx, f_idx->cursor.h_stmt, &f_idx->row);
	if (res != 0) 
		return(-1);
	if (!f_idx->row.tf_found) {
		THROW_EXC(COB_IOEXC_NOREC);
	}
	// check cursor has not started at next key value
	if (memcmp(f_idx->row.key_value[ix_key], key->data, f_idx->cb_key_sig))  {
		THROW_EXC(COB_IOEXC_NOREC);
	} 
	if (0 != (res = _odbc_lock_record(f, opt))) 
		THROW_EXC(COB_IOEXC_REC_LOCKED);
	if (!f_idx->tf_fixed_rsz) 
		f->record->size = f_idx->row.rsz;
	memcpy(f->record->data, f_idx->row.data, f_idx->fd_rsz);
	_odbc_set_fpi(f_idx);

#ifdef WITH_FILEIO_TRACE
	_odbc_log_key(f_idx
	            , f_idx->fpi.ix_key
                , f_idx->fpi.key_value[0]
                , f_idx->fpi.key_value[ix_key]
                , &f_idx->key_trail[KEY_TRAIL_READ]);
#endif

	return(0);
}



/*
 *	Read the next record based on the current-record (SEQUENTIAL READ) and the options given.
 *	The client may have changed the file record-contents, so if required to
 *	re-establish the position, ensure the last-read-key is used.
 *	Example: based on a file with primary-key: PK  and alternate-key: SK
 *		File records: PK0 SK0, PK1 SK1, PK2 SK2, P3 SK3 ...
 *		START key  = SK0
 *		READ NEXT -> PK0 SK0
 *		REWRITE with SK0 changed to SKn
 *		READ NEXT -> PK1 SK1 ....... is correct
 *		READ NEXT -> PKn+1 SKn+1 ... would be incorrect
 *		
 */

int cob_fileio_isam_read_next(
	  cob_file_t *f
	, const int opt) 
{
	idx_file_t *f_idx = f->file;
	int stat, ix_key, res = 0;
	int tf_skip_fetch = 0;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_read_next(%s opt=%d)\n"
		              , me, f->select_name, opt);
#endif


	if (!f_idx->fpi.tf_is_set)
		THROW_EXC(COB_IOEXC_NOREC);
	ix_key = f_idx->fpi.ix_key;
	if ((f->lock_mode & COB_LOCK_AUTOMATIC) && !f->tf_lock_many)
		_odbc_unlock_records(f->file);

	f_idx->cb_key_sig = f_idx->keydef[ix_key].cb_key;
	stat = COB_IOEXC_R_XEOF;
	if ((opt & 0x0F) == COB_READ_FIRST) {
		res = _odbc_make_cursor(f_idx, ix_key, CURSOR_FIRST);
	} else if ((opt & 0x0F) == COB_READ_LAST) {
		res = _odbc_make_cursor(f_idx, ix_key, CURSOR_LAST);
	} else if ((opt & 0x0F) == COB_READ_NEXT) {
		if (f->tf_beyond_eof)
			THROW_EXC(COB_IOEXC_R_XEOF);
		if (f->tf_beyond_bof) {
			res = _odbc_make_cursor(f_idx, ix_key, CURSOR_FIRST);
		} else if (f_idx->cursor.tf_resynch
		           || (f_idx->cursor.direction == CURSOR_RETREAT)) {
			res = _odbc_resynch_cursor(f_idx);
		}
	} else if ((opt & 0x0F) == COB_READ_PREVIOUS) {
		if (f->tf_beyond_bof)
			THROW_EXC(COB_IOEXC_R_XBOF);
		if (f->tf_beyond_eof) {
			res = _odbc_make_cursor(f_idx, ix_key, CURSOR_LAST);
		} else if (f_idx->cursor.tf_resynch
		           || (f_idx->cursor.direction == CURSOR_ADVANCE)) {
			res = _odbc_resynch_cursor(f_idx);
		}
	} else if ((opt & 0x0F) == COB_READ_CURRENT) {
		stat = COB_IOEXC_NOREC;
		// START will have read record
		tf_skip_fetch = 1;
	} else {
		fprintf(stderr, "!!! Internal Error :: illegal READ NEXT option [%d]\n", opt & 0x0F);
		THROW_EXC(COB_IOEXC_INTERNAL);
	}
	if (res != 0)
		return(res);
	if (!tf_skip_fetch) 
		res = _odbc_fetch_record(f_idx, f_idx->cursor.h_stmt, &f_idx->row);
	if (res != 0) 
		return(-1);
	if (!f_idx->row.tf_found) 
		THROW_EXC(stat);

	if ((opt & 0x0F) == COB_READ_CURRENT) {
		while (1) {
			if (memcmp(f_idx->row.key_value[ix_key]
			         , f_idx->fpi.key_value[ix_key]
			         , f_idx->keydef[ix_key].cb_key)
				|| (f_idx->row.id > f_idx->fpi.id))  {
				THROW_EXC(stat);
			}
			if (f_idx->row.id == f_idx->fpi.id) {
				break;
			}
			res = _odbc_fetch_record(f_idx, f_idx->cursor.h_stmt, &f_idx->row);
			if (res != 0) {
				return(-1);
			}
			if (!f_idx->row.tf_found) {
				THROW_EXC(stat);
			}
		}
	} 
	if (0 != (res = _odbc_lock_record(f, opt))) 
		THROW_EXC(stat);

	if (!f_idx->tf_fixed_rsz) 
		f->record->size = f_idx->row.rsz;
	memcpy(f->record->data, f_idx->row.data, f_idx->fd_rsz);
	_odbc_set_fpi(f_idx);


#ifdef WITH_FILEIO_TRACE
	_odbc_log_key(f_idx
	            , f_idx->fpi.ix_key
                , f_idx->fpi.key_value[0]
                , f_idx->fpi.key_value[ix_key]
                , &f_idx->key_trail[KEY_TRAIL_READ]);
#endif

	return(0);
}





/*
 *  Write the file record of cb_rec bytes.
 *	This adds a new row to the DB table which is assigned a  
 *  unique primary-key (ID), the COBOL PRIMARY KEY and possible
 *  secondary-keys.
 */

int cob_fileio_isam_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	idx_file_t *f_idx = f->file;
	int tf_dup;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_write(%s, rsz=%d, opt=%d)\n"
		              , me, f->select_name, cb_rec, opt);
#endif

	_odbc_compose_row(f, f->record->data, cb_rec);
	if ((f->access_mode == COB_ACCESS_SEQUENTIAL)
		&& (-1 == memcmp(f_idx->row.key_value[0]
		               , f_idx->key_p_w
		               , f_idx->keydef[0].cb_key)))
		THROW_EXC(COB_IOEXC_ISAM_KEY_ASC);

	if (0 != _odbc_check_sparse_keys(f_idx, &tf_dup))
		return(-1);
	if (tf_dup)
		THROW_EXC(COB_IOEXC_ISAM_DUP);

	if (0 != _odbc_execute_statement(f_idx, f_idx->h_insert)) {
		if (EXC_IS_DUPLICATE_KEY) {
			THROW_EXC(COB_IOEXC_ISAM_DUP);
		}
		return(-1);
	}
	f_idx->cursor.tf_resynch = 1;
	memcpy(f_idx->key_p_w, f_idx->row.key_value[0], f_idx->keydef[0].cb_key); 
 
#ifdef WITH_FILEIO_TRACE
	_odbc_log_key(f_idx, 0, f_idx->key_p_w, NULL, &f_idx->key_trail[KEY_TRAIL_WRITE]);
#endif
	return(0);
}






/*
 *	Rewrite the file record of cb_rec bytes, identified by its primary-key.
 *	The secondary-keys may have changed value. 
 */

int cob_fileio_isam_rewrite(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	idx_file_t *f_idx = f->file;
	int res, ix_key, tf_dup;
	row_t row_old;
	SQLHSTMT h_stmt;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_rewrite(%s, rsz=%d, opt=%d)\n"
		              , me, f->select_name, cb_rec, opt);
#endif

	_odbc_compose_row(f, f->record->data, cb_rec);
	if (f->access_mode == COB_ACCESS_SEQUENTIAL) {
		// check primary-key matches current (i.e. must rewrite prior read record)
	    res = memcmp(f_idx->fpi.key_value[0], f_idx->row.key_value[0], f_idx->keydef[0].cb_key);
		if (res != 0)
			THROW_EXC(COB_IOEXC_ISAM_KEY_ASC);
	}

	if (0 != _odbc_check_sparse_keys(f_idx, &tf_dup))
		return(-1);
	if (tf_dup)
		THROW_EXC(COB_IOEXC_ISAM_DUP);

	// (re-)read target record
	_odbc_malloc_row(f_idx, &row_old);
	sprintf(sql, "SELECT * FROM %s WHERE key_0 = %s"
	      , f_idx->dbt       
	      , cob_fileio_format_SQL_literal(f_idx->row.key_value[0], f_idx->keydef[0].cb_key, bfr));
	if (0 == (res = _odbc_execute_sql(f_idx, sql, &h_stmt))) { 
		if (0 == (res = _odbc_fetch_record(f_idx, h_stmt, &row_old))) {
			if (f_idx->row.tf_found) {
				/*
				 * If the rewrite changes any secondary keys, we must invalidate
				 * our cursor. This is because COBOL expects READ NEXT to reflect
				 * the changed state of the keys - and retrieve the associated data
				 * accordingly. There is no warranted "dynamic recordset" in ODBC.
				 */
				for (ix_key = 1; ix_key < f_idx->c_key; ++ix_key) {
				    if (0 != memcmp(row_old.key_value[ix_key]
					              , f_idx->row.key_value[ix_key]
					              , f_idx->keydef[ix_key].cb_key)) {
						f_idx->cursor.tf_resynch = 1;
						break;
					}
				}
			}
		}
	}
	SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
	_odbc_free_row(f_idx, &row_old);
	if (res != 0) 
		return(-1);
	if (!f_idx->row.tf_found) 
		THROW_EXC(COB_IOEXC_NOREC);

	if (0 != _odbc_execute_statement(f_idx, f_idx->h_update)) {
		if (EXC_IS_DUPLICATE_KEY) {
			THROW_EXC(COB_IOEXC_ISAM_DUP);
		}
		return(-1);
	}
	if (f_idx->tf_index_with_duplicates) {
		/* A secondary key has attribute DUPLICATE KEY; so we
		 * must DELETE and WRITE record to get a new ID.
		 * COBOL expects duplicate key-values to be ordered in sequence
		 * WRITE / REWRITE occurs. It is ID which vectors duplicates.
		 */
		_odbc_execute_statement(f_idx, f_idx->h_delete);
		if (0 != _odbc_execute_statement(f_idx, f_idx->h_insert)) {
			return(-1);
		}
	}		

#ifdef WITH_FILEIO_TRACE
	_odbc_log_key(f_idx, 0, f_idx->fpi.key_value[0], NULL, &f_idx->key_trail[KEY_TRAIL_REWRITE]);
#endif

	return(0);
}








/*
 *  Delete the record identified by its primary-key.
 */

int cob_fileio_isam_delete(cob_file_t *f)
{
	idx_file_t *f_idx = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_delete(%s)\n"
		              , me, f->select_name);
#endif

	_odbc_compose_row(f, f->record->data, f->record->size);
	if (0 != _odbc_execute_statement(f_idx, f_idx->h_delete))
		return(-1);
	f_idx->cursor.tf_resynch = 1;

#ifdef WITH_FILEIO_TRACE
	_odbc_log_key(f_idx, 0, f_idx->fpi.key_value[0], NULL, &f_idx->key_trail[KEY_TRAIL_DELETE]);
#endif

	return(0);
}









/*
 *	Flush the underlying files so that all current data is
 *	written to disk.
 *	Relying on ISAM isflush(), the mode argument is ignored.
 */

int cob_fileio_isam_sync(
	  cob_file_t *f
	, const int mode)
{
	idx_file_t *f_idx = f->file;
	f_idx->cursor.tf_resynch = 1;
	THROW_EXC(COB_IOEXC_NYI);  
}




/*
 *	Release any/all locks held on a file.
 */

int cob_fileio_isam_unlock(cob_file_t *f)
{
	idx_file_t *f_idx = f->file;
	THROW_EXC(COB_IOEXC_NYI);  
}



/*
 *	f is an INDEXED file, not open. DROP the
 *	matching table in the DB.
 */ 

int cob_fileio_isam_erase(cob_file_t *f)
{
	int res = 0;
	char fid[FILENAME_MAX], dbt[FILENAME_MAX];
	idx_file_t *f_idx;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_erase(%s)\n"
		              , me, f->select_name);
#endif

	cob_field_to_string(f->assign, fid, FILENAME_MAX);
	cob_fileio_locate_file(fid, fid, FILENAME_MAX);
	f->fid = fid;
	f_idx = _odbc_get_handle(f);

	if (0 != _odbc_open_table(f))
		return(-1);

	sprintf(dbt, "[%s]..[%s]", f_idx->db_name, f_idx->table_name); 
	f_idx->dbt = dbt;


	if (_odbc_table_exists(f_idx)) {
		sprintf(sql, "DROP TABLE %s", f_idx->dbt);
		res = _odbc_execute_sql(f_idx, sql, NULL);
	} else {
		cob_fileio_throw_exc(f, COB_IOEXC_OK_NOFILE, COB_IO_CONTEXT_FILEIO_INDEXED);
		res = -1;
	}

	// ensure our locals not free()-d
	f->fid = f_idx->dbt = NULL;          
	_odbc_free_handle(f);
	return(res);
}







/*
 *	Coin some info about myself in XML for fileio-stats.
 *	The pointer returned is malloc'd and should be free'd
 *	by the client. Called at BOJ.
 */

char *cob_fileio_isam_stats_env(const char *indent)
{
	char *xml = cob_malloc(1000);
    char *pb = xml;

	pb += sprintf(pb, "%s<isam_handler version=\"0x%x\" >\n", indent, ODBCVER);
	pb += sprintf(pb, "%s\tODBC Database\n", indent);
	pb += sprintf(pb, "%s</isam_handler>\n", indent);

	pb += sprintf(pb, "%s<ODBC_dsn var=\"COB_ODBC_DSN\" value=\"%s\" >\n"
	      , indent, getenv("COB_ODBC_DSN"));
	pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.dsn);
	pb += sprintf(pb, "%s</ODBC_dsn>\n", indent);


	pb += sprintf(pb, "%s<ODBC_server var=\"COB_ODBC_SERVER\" value=\"%s\" >\n"
	      , indent, getenv("COB_ODBC_SERVER"));
	pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.server_name); 
	pb += sprintf(pb, "%s</ODBC_server>\n", indent);

	pb += sprintf(pb, "%s<ODBC_db var=\"COB_ODBC_DB\" value=\"%s\" >\n"
	      , indent, getenv("COB_ODBC_DB"));
	pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.db_name);
	pb += sprintf(pb, "%s</ODBC_db>\n", indent);

	pb += sprintf(pb, "%s<ODBC_driver var=\"COB_ODBC_DRIVER\" value=\"%s\" >\n"
	      , indent, getenv("COB_ODBC_DRIVER"));
	pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.driver_name);
	pb += sprintf(pb, "%s</ODBC_driver>\n", indent);

	if (env_con_prop.extra != NULL) {
		pb += sprintf(pb, "%s<ODBC_extra var=\"COB_ODBC_EXTRA\" value=\"%s\" >\n"
		      , indent, getenv("COB_ODBC_EXTRA"));
		pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.extra);
		pb += sprintf(pb, "%s</ODBC_extra>\n", indent);
	}

	pb += sprintf(pb, "%s<ODBC_uid var=\"COB_ODBC_UID\" value=\"%s\" >\n"
	      , indent, getenv("COB_ODBC_UID"));
	pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.uid);
	pb += sprintf(pb, "%s</ODBC_uid>\n", indent);

	if (tf_show_password) {
		pb += sprintf(pb, "%s<ODBC_pwd var=\"COB_ODBC_PWD\" value=\"%s\" >\n"
		      , indent, getenv("COB_ODBC_PWD"));
		pb += sprintf(pb, "%s\t%s\n", indent, env_con_prop.pwd);
		pb += sprintf(pb, "%s</ODBC_pwd>\n", indent);
	}

	xml = realloc(xml, strlen(xml) + 1);
	return(xml);
}




/*
 *	Coin some info about myself in XML for fileio-stats.
 *	The pointer returned is malloc'd and should be free'd
 *	by the client. Called after FILE OPEN.
 */

char *cob_fileio_isam_stats(
	  cob_file_t *f
	, const char *indent)
{
	idx_file_t *f_idx = f->file;
	if (f_idx == NULL) return(NULL);

	char *xml = cob_malloc(1000);
    char *pb = xml;
	char *pb2;
	connection_t *con;

	
	if (f_idx->con_command == NULL) {
		pb += sprintf(pb, "%s<ODBC_connection> NONE </ODBC_connection>", indent);
	} else {
		con = f_idx->con_command;
		strcpy(bfr, con->string);
		if (!tf_show_password) {
			// strike PWD
			pb2 = strcasestr(bfr, "PWD=");
			if (pb2 != NULL) {
				pb2 += 4;
				while ((*pb2 != '\0') && (*pb2 != ';') && (*pb2 != ')')) {
					*pb2++ = '*';
				}
			}
		} 
		pb += sprintf(pb, "%s<ODBC_connection>\n", indent);
		pb += sprintf(pb, "%s\t<dsn> %s </dsn>\n"
		      , indent, con->properties.dsn);  
		pb += sprintf(pb, "%s\t<server> %s </server>\n"
		      , indent, con->properties.server_name);
		pb += sprintf(pb, "%s\t<driver> %s </driver>\n"
		      , indent, (con->properties.driver_name == NULL) ? "ANON" : con->properties.driver_name);
		pb += sprintf(pb, "%s\t<dbms> %s </dbms>\n"
		      , indent, con->dbms_name);
		pb += sprintf(pb, "%s\t<is-sql-server> %s </is-sql-server>\n"
		      , indent, con->tf_is_sqlserver ? "YES" : "NO");
		pb += sprintf(pb, "%s\t<binary_max_size> %d </binary_max_size>\n"
		      , indent, (int)con->max_binary);
		pb += sprintf(pb, "%s\t<string> %s </string>\n"
		      , indent, bfr);      // connection-string (with password struck)
		pb += sprintf(pb, "%s\t<negotiated> %s </negotiated>\n"
		      , indent, con->tf_is_made ? "YES" : "NO");
		pb += sprintf(pb, "%s\t<connected> %s </connected>\n"
		      , indent, con->tf_is_open ? "YES" : "NO");
		pb += sprintf(pb, "%s</ODBC_connection>\n", indent);
	}
	pb += sprintf(pb, "%s<database> %s </database>\n"
	      , indent, f_idx->db_name);
	pb += sprintf(pb, "%s<table_name> %s </table_name>\n"
	      , indent, f_idx->table_name);
	pb += sprintf(pb, "%s<entity_name> %s </entity_name>\n"
	      , indent, f_idx->dbt);
	pb += sprintf(pb, "%s<key_count> %d </key_count>\n"
	      , indent, f_idx->c_key);
	pb += sprintf(pb, "%s<max_key_length> %d </max_key_length>\n"
	      , indent, f_idx->cb_key_max);
	pb += sprintf(pb, "%s<fixed_rsz> %s </fixed_rsz>\n"
	      , indent, f_idx->tf_fixed_rsz ? "YES" : "NO");

	xml = realloc(xml, strlen(xml) + 1);
	return(xml);
}




/*
 *	P R I V A T E   F U N C T I O N S
 *	---------------------------------
 */


/*
 * Open a db table.
 *
 * Memory may be malloc'd for the file handle.
 * This function is wrapped to ensure resources are released if 
 * we exit prematurely.
 * 
 *	table           INPUT                    OUTPUT or I-O	
 *	exists          SUCCESS                  SUCCESS
 *	missing         Note 1                   COB_STATUS_00_SUCCESS
 *
 *  Note 1: if f->flag_optional SUCCESS + optional-file-missing 
 *          else COB_IOEXC_FILE_MISSING
 *  Note 2: if OUTPUT: any existing table is overwritten (without first opening it).
 *
 *
*/

static int _odbc_open_file(
	  cob_file_t *f
	, const int mode) 
{
	int res;
	int tf_exists = 0, tf_persist_key_dict = 0;
	idx_file_t *f_idx;
	keydef_t *keys;
	SQLSMALLINT cb;

	f_idx = _odbc_get_handle(f);
	if (0 != _odbc_open_table(f))
		return(-1);

	f_idx->dbt = cob_malloc(strlen(f_idx->db_name) + strlen(f_idx->table_name) + 7);
	sprintf(f_idx->dbt, "[%s]..[%s]", f_idx->db_name, f_idx->table_name); 

	// open connection for the cursor
	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC, h_env, &f_idx->cursor.con.h_dbc)))
		THROW_EXC_ODBC("SQLAllocHandle", h_env, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	if (!SQL_SUCCEEDED(SQLDriverConnect(
			  f_idx->cursor.con.h_dbc
			, NULL
			, (UNSC *)f_idx->con_command->string, SQL_NTS
			, (UNSC *)bfr, CB_AD_HOC
			, &cb
			, SQL_DRIVER_NOPROMPT)))
		THROW_EXC_ODBC("SQLDriverConnect", h_env, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_CONNECT);

	tf_exists = _odbc_table_exists(f_idx);

	#ifdef  WITH_FILEIO_TRACE
		if (trace_level > 3)
			fprintf(stderr, "%s: DB table %s%sfound.\n", me
		 	              , f_idx->dbt, tf_exists ? " " : " NOT ");
	#endif

	switch(mode) {
	case COB_OPEN_INPUT:
		if (!tf_exists) { 
			if (!f->flag_optional) 
				THROW_EXC(COB_IOEXC_FILE_MISSING);
			f->tf_optional_is_missing = 1;
		}
		break;
	case COB_OPEN_OUTPUT:
  		if (tf_exists) {
			sprintf(sql, "DROP TABLE %s", f_idx->dbt);
			if (0 != _odbc_execute_sql(f_idx, sql, NULL)) {
				THROW_EXC(COB_IOEXC_ISAM_DROP);
			}
			tf_exists = 0;
		}
		break;
	case COB_OPEN_I_O:			// fall thru
	case COB_OPEN_EXTEND:
		if (!tf_exists) {
			if (!f->flag_optional) 
				THROW_EXC(COB_IOEXC_FILE_MISSING);
			f->tf_optional_was_created = 1;
		}
		break;
	}

	if (f->tf_optional_is_missing)
		return(0);

	if (!tf_exists) {
		_odbc_get_cobol_key_descriptors(f, &keys, &f_idx->c_key); 
		_odbc_set_key_descriptors(f_idx, keys);
		if (0 != _odbc_create_table(f_idx))
			return(-1);
		// For a new FILE we will write a key-dict (later)
		tf_persist_key_dict = 1;
	} else {
	    //  For an existing file we can provide flexibility with key
		//  declarations in COBOL source - but this requires a key dictionary.
		if (0 != _odbc_get_db_key_descriptors(f_idx, &keys, &f_idx->c_key)) {
			_odbc_get_cobol_key_descriptors(f, &keys, &f_idx->c_key); 
			tf_persist_key_dict = 1;
		} else {
			res = _odbc_match_keys(f, keys, f_idx->c_key);
			if (res == -1) {
				#ifdef  		WITH_FILEIO_TRACE
				if (trace_level > 3)
					fprintf(stderr, "%s: failed to match key descriptors from dictionary\n", me);
				#endif
				THROW_EXC(COB_IOEXC_ISAM_BAD_DICT);
			}
			if (res == 1) {
			/*
			 * Only the COBOL primary-key [0] is mandated to match isam-handler.
			 * Missing/mismatched COBOL secondary keys set keydef[n].cob_field_key = NULL.
			 * This defers f-status errors from OPEN to 1st START/READ which throws: COB_IOEXC_ISAM_NINDEX.
			 */
				if (keys->cob_field_key == NULL) {
					#ifdef  WITH_FILEIO_TRACE
					if (trace_level > 3)
						fprintf(stderr, "%s: primary key in COBOL declaration not indexed\n", me);
					#endif
					THROW_EXC(COB_IOEXC_ISAM_NINDEX);
				}
			}
		}
		_odbc_set_key_descriptors(f_idx, keys);
	}


	#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4) {
		char *pb;
		fprintf(stderr, "ODBC-ISAM FILE @ OPEN: %s\n", pb = _odbc_dump_file_description(f, 0));
		free(pb);
	}
	#endif

	// check if file can be shared
   	if (0 != cob_fileio_sharing_open_file(f, mode)) {
		THROW_EXC(COB_IOEXC_FSHARE_LOCK);  
	}
	if (tf_persist_key_dict) {
		if (0 != _odbc_create_key_dict(f_idx)) {
			THROW_EXC(COB_IOEXC_ISAM_CREATE_DICT);
		}
	}
	f_idx->ix_key = 0;
	f_idx->cursor.h_stmt = NULL;
	f_idx->fd_rsz = f->record_max;
	f_idx->fpi.tf_is_set = 1;
	if (mode == COB_OPEN_EXTEND) {
		// ANS85: fpi -> after last logical record
		f->tf_beyond_eof = 1;
	} else if (mode != COB_OPEN_OUTPUT) {
		// establish a cursor
		res = _odbc_make_cursor(f_idx, 0, CURSOR_FIRST);
		if (res != 0) return(-1);
		_odbc_set_fpi(f_idx);
	}
	res = 0;
	if (mode != COB_OPEN_INPUT) {
		res = _odbc_make_insert_statement(f_idx);
		if (res == 0) _odbc_make_update_statement(f_idx);
		if (res == 0) _odbc_make_delete_statement(f_idx);
	}
	return(res);
}



/*
 *	Prepare idx_file_t for COBOL file f.
 */

static idx_file_t *_odbc_get_handle(cob_file_t *f)
{
	idx_file_t *f_idx;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_get_handle(%s)\n", me, f->select_name);
#endif

	f_idx = (idx_file_t *)cob_malloc(sizeof(idx_file_t));

	// storage for key-values is malloc-d when 
    // we know size of largest key indexed
	f_idx->db_name = NULL;     
	f_idx->table_name = NULL;     
	f_idx->dbt = NULL;     
	f_idx->key_p_w = NULL;
	f_idx->key_work = NULL;
	f_idx->row.data = NULL;
	f_idx->row.key_value = NULL;
	f_idx->c_key = f->nkeys;
	f_idx->tf_fixed_rsz = (f->record_min == f->record_max);

	f->file = f_idx;
	f_idx->cob_file = f;

#ifdef WITH_FILEIO_TRACE
	int ix;
	for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) {
		f_idx->key_trail[ix].c_io = 0;
		f_idx->key_trail[ix].ix_key = -1;
		f_idx->key_trail[ix].pb_pkey_value = NULL;
		f_idx->key_trail[ix].pb_skey_value = NULL;
		f_idx->key_trail[ix].time = time(NULL);
	}
#endif

	return(f_idx);
}





/*
 *	Allocate memory to store key info in f_idx.
 *	Set key info in f_idx from given keydef[].
 *	Allocate memory to store current values of keys.
 */
static void _odbc_set_key_descriptors(
	  idx_file_t *f_idx
	, keydef_t *keys)
{
	int ix_key, rsz, cb_dict;
	keydef_t *keydef;

#ifdef  WITH_FILEIO_TRACE
	int ix;
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_set_key_descriptors() %d indices\n", me, f_idx->c_key);
#endif

	f_idx->keydef = cob_malloc(sizeof(keydef_t) * f_idx->c_key);
	f_idx->cb_key_max = -1;

	for (ix_key = 0, keydef = keys; ix_key < f_idx->c_key; ++ix_key, ++keydef) {
		f_idx->keydef[ix_key] = *keydef;
		if (keydef->tf_duplicates) {
			f_idx->tf_index_with_duplicates = 1;
		}
		if (f_idx->cb_key_max < keydef->cb_key) {
			f_idx->cb_key_max = keydef->cb_key;
		}
	}
	free(keys);
	f_idx->key_p_w = cob_malloc(f_idx->cb_key_max + 1);
	f_idx->key_work = cob_malloc(f_idx->cb_key_max + 1);

	// The minimum data length is determined by the greater of
	//		(1) f_idx->cob_file->record_max
	//		(2) the size of the largest key dictionary entry.
	rsz = 0;
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		cb_dict = (14 * f_idx->keydef[ix_key].c_comp) + 1; 	// 6n.6n:[6n.6n ...]_D
		if (cb_dict > rsz) rsz = cb_dict;
	}
	if (f_idx->cob_file->record_max > rsz) 
		rsz = f_idx->cob_file->record_max;
	f_idx->data_size = rsz;

	_odbc_malloc_row(f_idx, &f_idx->row);
	_odbc_malloc_fpi(f_idx);

#ifdef WITH_FILEIO_TRACE
	for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) {
		f_idx->key_trail[ix].pb_pkey_value = (char *)cob_malloc(f_idx->cb_key_max + 1);
		f_idx->key_trail[ix].pb_skey_value = (char *)cob_malloc(f_idx->cb_key_max + 1);
	}
#endif

}





/*
 *	Free all memory allocated within idx_file_t
 */

static void _odbc_free_handle(cob_file_t *f)
{
	idx_file_t *f_idx = f->file;
	connection_t *con;

	if (f_idx == NULL)
		return;

#ifdef  WITH_FILEIO_TRACE
	int ix;
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_free_handle(%s)\n", me, f->select_name);
	for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) { 
		free(f_idx->key_trail[ix].pb_pkey_value);
		free(f_idx->key_trail[ix].pb_skey_value);
	}
#endif

	if (f_idx->cursor.h_stmt != NULL) {
		SQLFreeHandle(SQL_HANDLE_STMT, f_idx->cursor.h_stmt);
		f_idx->cursor.h_stmt = NULL;
	}
	if (f_idx->con_command != NULL) {
		con = f_idx->con_command;
		if (con->tf_is_made) { 
			// leave non-dynamic single connection open        
			if (con->c_client != -1) {
				if (con->c_client <= 1) {
					_odbc_free_connection(con);
				} else {
					--con->c_client;
				}
			}
		}
		f_idx->con_command = NULL;
	}
	_odbc_free_fpi(f_idx);
	if (f_idx->row.data != NULL)
		_odbc_free_row(f_idx, &f_idx->row);
	if (f_idx->db_name!= NULL) 
		free(f_idx->db_name);
	if (f_idx->table_name != NULL)
		free(f_idx->table_name);
	if (f_idx->dbt != NULL)
		free(f_idx->dbt);
	free(f_idx->keydef);
	if (f_idx->key_p_w != NULL)
		free(f_idx->key_p_w);
	if (f_idx->key_work != NULL)
		free(f_idx->key_work);
	free(f_idx);
	f->file = NULL;
}






/*
 *	Free all memory allocated within connection_t
 */

static void _odbc_free_connection(connection_t *con)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_free_connection(0x%lx DSN=%s  SERVER=%s)\n"
		      , me, (long)con, con->properties.dsn, con->properties.server_name);
#endif

	if (con->h_dbc != NULL) 
		SQLFreeHandle(SQL_HANDLE_DBC, con->h_dbc);

	if (con->properties.dsn != NULL) free(con->properties.dsn);
	if (con->properties.driver_name != NULL) free(con->properties.driver_name);
	if (con->properties.server_name != NULL) free(con->properties.server_name);
	if (con->properties.db_name != NULL) free(con->properties.db_name);
	if (con->properties.uid != NULL) free(con->properties.uid);
	if (con->properties.pwd != NULL) free(con->properties.pwd);
	if (con->properties.extra != NULL) free(con->properties.extra);

	if (con->server_name != NULL) free(con->server_name);
	if (con->db_name != NULL) free(con->db_name);
	if (con->dbms_name != NULL) free(con->dbms_name);
	con->tf_is_made = con->c_client = 0;
}







/*
 *	Allocate memory for the file-position-indicator.
 */
static void _odbc_malloc_fpi(idx_file_t *f_idx)
{
	int ix_key;
	f_idx->fpi.tf_is_set = 0;
	f_idx->fpi.ix_key = 0;		// open using PRIMARY-KEY
	f_idx->fpi.key_value = cob_malloc(sizeof(char *) * f_idx->c_key);
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		f_idx->fpi.key_value[ix_key] = cob_malloc(f_idx->keydef[ix_key].cb_key + 1); 
	}
}




/*
 *	Free memory used for the file-position-indicator.
 */
static void _odbc_free_fpi(idx_file_t *f_idx)
{
	int ix_key;
	if (f_idx->fpi.key_value != NULL) {
		for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
			free(f_idx->fpi.key_value[ix_key]);
		}
		free(f_idx->fpi.key_value);
		f_idx->fpi.key_value = NULL;
	}
}




/*
 *	Note the key-values used to establish the current fpi
 */
static void _odbc_set_fpi(idx_file_t *f_idx)
{
	int ix_key;

	f_idx->fpi.tf_is_set = 1;
	f_idx->fpi.ix_key = f_idx->ix_key;
	f_idx->fpi.id = f_idx->row.id;
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		memcpy(f_idx->fpi.key_value[ix_key]
		     , f_idx->row.key_value[ix_key]
		     , f_idx->keydef[ix_key].cb_key);
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3) {
		ix_key = f_idx->ix_key;
		fprintf(stderr, "%s: _odbc_set_fpi() ix_key=%d  key=%s\n"
	          , me, ix_key
		      , cob_fileio_fmtstr(f_idx->fpi.key_value[ix_key], f_idx->keydef[ix_key].cb_key));
	}
#endif
}




/*
 *	Malloc space for the row (record) read/written to table (file).
 */ 
static void _odbc_malloc_row(
	  idx_file_t *f_idx
	, row_t *row)
{
	int ix_key;

	row->data = cob_malloc(f_idx->data_size + 1); 
	row->key_value = cob_malloc(sizeof(char *) * f_idx->c_key);
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		row->key_value[ix_key] = cob_malloc(f_idx->keydef[ix_key].cb_key + 1); 
	}
}



/*
 *	Free space allocated for the row (record).
 */ 
static void _odbc_free_row(
	  idx_file_t *f_idx
	, row_t *row)
{
	int ix_key;

	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		free(row->key_value[ix_key]); 
	}
	free(row->key_value);  
	free(row->data);  
}





/*
 *	Create a new empty table in the database.
 *	Add the keys declared in the COBOL source as table constraints.
 *
 *	Return 0 on success, -1 on failure.
 */

static int _odbc_create_table(
	  idx_file_t *f_idx)
{
	int ix_key;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _odbc_create_table(%s server_name=[%s]  table=%s)\n"
		              , me, f_idx->cob_file->select_name, f_idx->con_command->properties.server_name, f_idx->dbt);
#endif

	p_sql = sql;
	p_sql += sprintf(p_sql, "CREATE TABLE %s(\n", f_idx->dbt);
	p_sql += sprintf(p_sql, "  id int IDENTITY NOT NULL\n");
	p_sql += sprintf(p_sql, ", is_control bit NOT NULL default 0\n");
	p_sql += sprintf(p_sql, ", key_0 BINARY(%d) NOT NULL\n", (int)f_idx->keydef[0].cb_key);

	for (ix_key = 1; ix_key < f_idx->c_key; ++ix_key) {
		p_sql += sprintf(p_sql, ", key_%d BINARY(%d)\n"	
			, ix_key, (int)f_idx->keydef[ix_key].cb_key);
	}
	if (!f_idx->tf_fixed_rsz) {
		p_sql += sprintf(p_sql, ", rsz int\n");
	}

	sprintf(bfr, SQL_FIELD_TYPE(f_idx->con_command, f_idx->data_size), f_idx->data_size);
	p_sql += sprintf(p_sql, ", data %s\n", bfr);
	p_sql += sprintf(p_sql, ")");
	if (0 != _odbc_execute_sql(f_idx, sql, NULL)) {
#ifdef WITH_FILEIO_TRACE
		if (trace_level > 1) {
			fprintf(stderr, "!!! Error :: failed to create database table\n%s\n", sql);
		}
#endif
		return(-1);
	}
	p_sql = sql;
	p_sql += sprintf(p_sql, "ALTER TABLE %s\n", f_idx->dbt);
	p_sql += sprintf(p_sql, "ADD CONSTRAINT [PK_%s] PRIMARY KEY (is_control, key_0)\n", f_idx->table_name);
	if (0 != _odbc_execute_sql(f_idx, sql, NULL)) {
#ifdef WITH_FILEIO_TRACE
		if (trace_level > 1) {
			fprintf(stderr, "!!! Error :: failed to constrain database table\n%s\n", sql);
		}
#endif
		return(-1);
	}
	p_sql = sql;
	for (ix_key = 1; ix_key < f_idx->c_key; ++ix_key) {
		if (!f_idx->keydef[ix_key].tf_duplicates
			&& !f_idx->keydef[ix_key].tf_suppress) {
			p_sql += sprintf(p_sql, "ALTER TABLE %s\n", f_idx->dbt);
			p_sql += sprintf(p_sql, "ADD CONSTRAINT [UK%s_%d] UNIQUE (is_control, key_%d)\n"
				, f_idx->table_name, ix_key, ix_key);
		}
	}
	if (p_sql != sql) {
		if (0 != _odbc_execute_sql(f_idx, sql, NULL)) {
#ifdef WITH_FILEIO_TRACE
			if (trace_level > 1) {
				fprintf(stderr, "!!! Error :: failed to constrain database table\n%s\n", sql);
			}
#endif
			return(-1);
		}
	}
	return(0);
}







static int _odbc_table_exists(
	  idx_file_t *f_idx)
{
	int res;
	sprintf(sql, "SELECT TOP 0 * FROM %s", f_idx->dbt);
	res = _odbc_execute_sql(f_idx, sql, NULL);
	// ensure any exceptions are NOT returned to client
	cob_fileio_begin(f_idx->cob_file, COB_IO_VERB_OPEN);
	return(res == 0); 
}




/*
 *	Using the keys stored in f_idx,
 *	store a key-dictionary in control records.
 *
 */
static int _odbc_create_key_dict(idx_file_t *f_idx)
{
	int ix_key, ix_row, ix_comp;
	char *p_sql_x;
	keydef_t key;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_create_key_dict(%s)\n", me, f_idx->dbt);
#endif

	p_sql = sql;
	p_sql += sprintf(p_sql, "INSERT %s (is_control", f_idx->dbt);
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		p_sql += sprintf(p_sql, ", key_%d", ix_key);
	}
	p_sql += sprintf(p_sql, ", data) values(1");
	p_sql_x = p_sql;
	for (ix_row = 0; ix_row < f_idx->c_key; ++ix_row) {
		p_sql = p_sql_x;
		for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
			p_sql += sprintf(p_sql, ", %d", ix_row);
		}
		key = f_idx->keydef[ix_row];
		p_sql += sprintf(p_sql, ", CAST('%d.%d", key.comp[0].rb, key.comp[0].cb);
		for (ix_comp = 1; ix_comp < key.c_comp; ++ix_comp) {
			p_sql += sprintf(p_sql, ":%d.%d", key.comp[ix_comp].rb, key.comp[ix_comp].cb);
		}
		p_sql += sprintf(p_sql, "%s' AS BINARY))", key.tf_duplicates ? "_D" : "");
		if (0 != _odbc_execute_sql(f_idx, sql, NULL)) {
			fprintf(stderr, "!!! Internal Error :: failed to add key-dictionary to table\n%s\n", sql);
			THROW_EXC(COB_IOEXC_INTERNAL);
		}
		p_sql = p_sql_x;
	}
	return(0);
}





/*
 * Read a key-dictionary to construct the key definitions.
 *
 * Returns 0 if successful.
 *     Pointer to the manufactured keys is returned in keys
 *     which is an array of *pc_keys entries.
 * Returns -1 if unsuccessful.
 *     The key-dictionary should be ignored and 
 *     the key defs from COBOL source used instead.
 *
 */
static int _odbc_get_db_key_descriptors(
	  idx_file_t *f_idx
	, keydef_t  **keys_ret
	, int *pc_keys)
{
	int res, rb_comp, cb_comp, cb;
	long c_key;
	int ix_key, ix_comp;
	char *pb;
	keydef_t *key;
	SQLHSTMT h_stmt;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_get_db_key_descriptors()\n", me);
#endif

	*keys_ret = NULL;
	sprintf(sql, "SELECT count(*) as cnt FROM %s WHERE is_control = 1", f_idx->dbt);
	if (0 != _odbc_execute_sql(f_idx, sql, &h_stmt)) 
		return(-1);
	res = SQLFetch(h_stmt);
	if (!SQL_SUCCEEDED(res)) {
		SET_EXC_ODBC("SQLFetch", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
		SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
		return(-1);
	}
	res = SQLGetData(h_stmt, 1, SQL_C_LONG, &c_key, 0, NULL);
	if (!SQL_SUCCEEDED(res)) {
		SET_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
		SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
		return(-1);
	}
	SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);

	// Data in dictionary rows is ALWAYS alphanumeric
	sprintf(sql, "SELECT CAST(data as VARCHAR) FROM %s WHERE is_control = 1 ORDER BY key_0", f_idx->dbt);
	if (0 != _odbc_execute_sql(f_idx, sql, &h_stmt)) 
		return(-1);
	/*
	 *   Each key def is stored in own row (is_control == 1)
	 *   Key format (for key of m+1 components):
	 *        rb0.cb0[:rb1.cb1[... :rbm.cbm][_D]]
	 */
	f_idx->c_key = c_key;
	*keys_ret = (keydef_t *)cob_malloc(sizeof(keydef_t) * c_key);
	for (ix_key = 0, key = *keys_ret; ix_key < c_key; ++ix_key, ++key) {
		res = SQLFetch(h_stmt);
		if (!SQL_SUCCEEDED(res)) {
			SET_EXC_ODBC("SQLFetch", h_stmt, SQL_HANDLE_STMT
				, (res == SQL_NO_DATA) ? COB_IOEXC_ISAM_ODBC_CONTROLS : COB_IOEXC_ISAM_ODBC_HANDLE);
			SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
			return(-1);
		}
		memset(bfr, '\0', 50);
		res = SQLGetData(h_stmt, 1, SQL_C_CHAR, bfr, CB_AD_HOC, NULL);
		if (!SQL_SUCCEEDED(res)) {
			SET_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
			SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
			return(-1);
		}
		pb = bfr;
		if (EOF == sscanf(pb, "%d.%d%n", &rb_comp, &cb_comp, &cb)) 
			goto exit_error;
		key->comp[0].rb = rb_comp;
		key->comp[0].cb = cb_comp;
		key->cb_key = cb_comp;
		key->tf_duplicates = 0;
		key->cob_field_key = NULL;
		pb += cb;
		for (ix_comp = 1; ix_comp < COB_MAX_KEYCOMP; ++ix_comp) {
			if (*pb == ':') {
				++pb;
				rb_comp = cb_comp = -1;
				sscanf(pb, "%d.%d%n", &rb_comp, &cb_comp, &cb);
				if ((rb_comp < 0) || (cb_comp < 1))
					goto exit_error;
				key->comp[ix_comp].rb = rb_comp;
				key->comp[ix_comp].cb = cb_comp;
				key->cb_key += cb_comp;
				pb += cb;
				continue;
			} 
			if (*pb == '_') {
				++pb;
				if (*pb == 'D') {
					++pb;
					key->tf_duplicates = 1;
				} else {
					goto exit_error;
				}
			};
			break;
		}
		key->c_comp = ix_comp;
	}			
	SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
	return(0);

exit_error:

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: !!! invalid key dictionary. Current line: %s\n", me, bfr);
#endif
	SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
	return(-1);
}



/*
 * Use key declarations from COBOL source to construct the key definitions.
 *
 * Returns 0 if successful.
 *     Pointer to the manufactured keys is returned in keys_ret
 *     which is an array of *c_key_ret entries.
 * Returns -1 if unsuccessful.
 *
 */
static void _odbc_get_cobol_key_descriptors(
	  cob_file_t *f
	, keydef_t **keys_ret
	, int *c_key_ret)
{
	int ix_key, ix_comp;
	cob_file_key_t *cob_key;
	keydef_t *kd;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_get_cobol_key_descriptors(%s)\n", me, f->select_name);
#endif

	*c_key_ret = f->nkeys;
	*keys_ret = (keydef_t *)cob_malloc(sizeof(keydef_t) * f->nkeys);
	for (ix_key = 0, kd = *keys_ret, cob_key = f->keys;
         ix_key < f->nkeys;
         ix_key++, kd++, cob_key++)
	{
		kd->cob_ix_key = ix_key;
		kd->cob_field_key = cob_key->field;
		kd->tf_duplicates = cob_key->flag;
		kd->tf_suppress = cob_key->tf_suppress;
		kd->ch_suppress = cob_key->char_suppress;
		kd->cb_key = cob_key->field->size;
		if (cob_key->count_components <= 1) {    // simple key - single field
			kd->c_comp = 1;
			kd->comp[0].rb = cob_key->offset;
			kd->comp[0].cb = cob_key->field->size;
		} else {                                 // composite (or "split") key  
			kd->c_comp = cob_key->count_components;
			for (ix_comp = 0; ix_comp < cob_key->count_components; ++ix_comp) {
				kd->comp[ix_comp].rb = cob_key->component[ix_comp]->data - f->record->data;
				kd->comp[ix_comp].cb = cob_key->component[ix_comp]->size;
			}
		}
	}
}





/*
 *	The keys have been loaded into f->keys from the COBOL SELECT.
 *	Check these keys are a subset of keys in the key-dictionary
 *	for this file [arg: keys]. The order of declaration is unimportant.
 *	Keys for which there is no matching index get
 *	keydef->cob_field_key = NULL. 
 *	Superfluous keys in the index are ignored.
 *  
 *	Returns:
 *		-1 encountered error.
 *		 0 if key found in ISAM for each key in COBOL SELECT
 *		 1 if COBOL SELECT references any key for which there is
 *          no matching index.
*/

static int _odbc_match_keys(
	  cob_file_t *f
	, keydef_t *keys
	, int c_key)
{
	int res, ix_key1, ix_key2, ix_comp;
	cob_file_key_t *cob_key;
	keydef_t *kd;
	int tf_matched;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_match_keys(%s)\n", me, f->select_name);
#endif
	
	res = 0;
	for (ix_key1 = 0; ix_key1 < f->nkeys; ++ix_key1) {
		cob_key = f->keys+ix_key1;
		tf_matched = 0;
		for (ix_key2 = 0; ix_key2 < c_key; ++ix_key2) {
			kd = keys + ix_key2;
			if (kd->cob_field_key != NULL) continue;
			if ((cob_key->field->size != kd->cb_key)
			   || (cob_key->flag != kd->tf_duplicates))
				continue;
			if (cob_key->count_components <= 1) {    // simple key - single field
				if ((kd->c_comp != 1)
				   || (cob_key->offset != kd->comp[0].rb)
				   || (cob_key->field->size != kd->comp[0].cb))
					continue;
			} else {                                 // composite (or "split") key  
				if (cob_key->count_components != kd->c_comp)
					continue;
				for (ix_comp = 0; ix_comp < kd->c_comp; ++ix_comp) {
					if (((cob_key->component[ix_comp]->data - f->record->data) != kd->comp[ix_comp].rb)
					   || (cob_key->component[ix_comp]->size != kd->comp[ix_comp].cb))
						break;
				}
				if (ix_comp != kd->c_comp)
					continue;
			}

#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 3)
				fprintf(stderr, "%s: COBOL key %d [0x%lx] matches ODBC key %d)\n"
				      , me, ix_key1, (long)cob_key->field, ix_key2);
#endif
			tf_matched = 1;
			kd->cob_ix_key = ix_key1;
			kd->cob_field_key = cob_key->field;
			kd->tf_suppress = cob_key->tf_suppress;
			kd->ch_suppress = cob_key->char_suppress;
			break;
		}
		if (!tf_matched) res = 1;
	}
	return(res);
}




/*
 *	Given a pointer to a key in the struct cob_file_t (of the COBOL
 *	source program), find the corresponding key-descriptor in
 *	idx_file_t.
 *	Keys are considered as matched if their data-pointers are equal. This
 *	supports START KEY = <data-field-subordinate-to-a-key-but-aligned-on-left>.
 *	If matched, the ODBC prepared statements are made for this key.
 *
 *	On success: return the ordinal index to dset corresponding to the key.
 *	On failure: return -1.
 */
static int _odbc_get_key_ix(
	  idx_file_t *f_idx
	, cob_field *key_cobol)
{
	int ix_key;
	int tf_found = 0;
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		if ((f_idx->keydef[ix_key].cob_field_key != NULL)
			&& (f_idx->keydef[ix_key].cob_field_key->data == key_cobol->data)) {
			tf_found = 1;
			break;
		}
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_get_key_ix() -> %d\n", me, (tf_found ? ix_key : -1));
#endif

	return(tf_found ? ix_key : -1);
}






/*
 *	There is no way to "suppress" sparse keys from the DB.
 *	So we cannot make the keys that might be sparse UNIQUE.
 *	This function checks for duplicates using data in f_idx->row.
 *	On success: returns 0
 *		tf_is_dup = true if any sparse key is a duplicate.
 *		an existing .
 *	On failure: returns -1 and throws the EXCEPTION. 
 */
static int _odbc_check_sparse_keys(
	  idx_file_t *f_idx
	, int *tf_is_dup)
{
	int res, ix_key, ix_ch, cb_key;
	char *p_sql_top;
	SQLHSTMT h_stmt;

	*tf_is_dup = 0;
	if (f_idx->c_key < 2)
		return(0);

	p_sql = sql;
	p_sql += sprintf(p_sql, "SELECT TOP 1 Id FROM %s WHERE (is_control = 0)", f_idx->dbt);
	cob_fileio_format_SQL_literal(f_idx->row.key_value[0], f_idx->keydef[0].cb_key, bfr);
	p_sql += sprintf(p_sql, " AND (key_0 != %s)",  bfr);
	p_sql_top = p_sql;

	for (ix_key = 1; ix_key < f_idx->c_key; ++ix_key) {
		if (f_idx->keydef[ix_key].tf_duplicates
			|| !f_idx->keydef[ix_key].tf_suppress) {
			// no need to check here if duplicates ok or not sparse key
			continue;
		}
		cb_key = f_idx->keydef[ix_key].cb_key;
		for (ix_ch = 0; ix_ch < cb_key; ++ix_ch) {
			if (f_idx->row.key_value[ix_key][ix_ch] != f_idx->keydef[ix_key].ch_suppress) {
				break;
			}
		}
		if (ix_ch == cb_key) {
			// (new) key is effectively "invisible"
			continue;
		}
		p_sql = p_sql_top;
		cob_fileio_format_SQL_literal(f_idx->row.key_value[ix_key], f_idx->keydef[ix_key].cb_key, bfr);
		p_sql += sprintf(p_sql, " AND (key_%d = %s)", ix_key,  bfr);

		if (0 != _odbc_execute_sql(f_idx, sql, &h_stmt)) {
			return(-1);
		}	
		res = SQLFetch(h_stmt);
		SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);

		if (res == SQL_NO_DATA) {
			continue;
		}
		if (SQL_SUCCEEDED(res)) {
			*tf_is_dup = 1;
			return(0);
		}
		THROW_EXC_ODBC("SQLFetch", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_HANDLE);
	}
	return(0);
}




/*
 * For the specified key, extract the key-value from the given data record,
 * using the offset:length of the (component parts) of the key.
 * The (composited) key-value is formatted and written to pb_key_value.
 */
static int _odbc_compose_key(
	  keydef_t *key
	, const void *pb_rec
	, char *pb_key_value)
{
	int ix;
	char *pb_val = pb_key_value;
	for (ix = 0; ix < key->c_comp; ++ix) {
		memcpy(pb_val 
		     , pb_rec + key->comp[ix].rb
		     , key->comp[ix].cb);
		pb_val += key->comp[ix].cb; 
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _odbc_compose_key() -> %s\n"
		      , me, cob_fileio_fmtstr(pb_key_value, key->cb_key));
#endif
	return(0);
}






/*
 *	Extract fields from the COBOL record that is in cob_rec.
 *	Place the results in f_idx->row.
 */
static int _odbc_compose_row(
	  cob_file_t *f
	, unsigned char *cob_rec
	, const int cb_rec)
{
	idx_file_t *f_idx = f->file;
	int ix_key;
	
#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_compose_row()\n", me);
#endif

	f_idx->row.rsz = cb_rec;
	memset(f_idx->row.data, '\0', f_idx->data_size);
	memcpy(f_idx->row.data, f->record->data, cb_rec);	
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		_odbc_compose_key(&f_idx->keydef[ix_key], cob_rec, f_idx->key_work);
		memcpy(f_idx->row.key_value[ix_key], f_idx->key_work, f_idx->keydef[ix_key].cb_key);
	}
	return(0);
}









/*
 * Grab the error state from the ODBC driver and transcribe into global: error_state
 * fn ... name of function called that returned NON-SUCCESS
 * handle ... the ODBC Handle being used.
 * handle_type ... the type of handle.
 */
static void _odbc_extract_error(
	  const char *fn
	, SQLHANDLE handle
	, SQLSMALLINT handle_type)
{
	int i = 0;
	char msg[512];
	SQLINTEGER native;
	SQLCHAR state[7];
	SQLCHAR text[256];
	SQLSMALLINT cb;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _odbc_extract_error(%s)\n", me, fn);
#endif

	error_state.fn = fn;
	error_state.handle = handle;
	error_state.handle_type = handle_type;
	if (error_state.cb_msg_max == 0) {
		error_state.cb_msg_max = 200;
		error_state.msg = cob_malloc(200);
	} 
	*error_state.msg = '\0';
	*error_state.odbc_state = '\0';
	error_state.primary_erc = -1;

	sprintf(msg, "fileio_isam_odbc :: ODBC error reported in: %s\n", fn);
	_odbc_cat_msg(msg);
	if (!SQL_SUCCEEDED(SQLGetDiagRec(handle_type, handle, 1, state, &native, text, sizeof(text), &cb))) {
		_odbc_cat_msg((char *)"No further information");
		return;
	}
	memcpy(error_state.odbc_state, state, 7);
	error_state.primary_erc = native;
	sprintf(msg, "1 : %s :: %ld :: %s\n", state, native, text);
	_odbc_cat_msg(msg);
	for (i = 2; ; ++i) {
		if (!SQL_SUCCEEDED(SQLGetDiagRec(handle_type, handle, i, state, &native, text, sizeof(text), &cb))) {
			break;
		}
		sprintf(msg, "%d : %s :: %ld :: %s\n", i, state, native, text);
		_odbc_cat_msg(msg);
	}
}




/*
 *	Concatenate the text in msg to global error_state.msg.
 */
static void _odbc_cat_msg(char *msg)
{
	int cb_req;
	cb_req = strlen(error_state.msg) + strlen(msg) + 2;
	if (cb_req > error_state.cb_msg_max) {
		error_state.cb_msg_max += cb_req;
		error_state.msg = realloc(error_state.msg, error_state.cb_msg_max);
	} 
	if (*error_state.msg != '\0')
		strcat(error_state.msg, "\n");
	strcat(error_state.msg, msg);
}








/*
 *	Transcribe the fields in props_in to props_out.
 *	Space is malloc-d as needed.
 */
static void _odbc_init_con_props(
	  con_props_t *props_in
	, con_props_t *props_out)
{

#define COPY_FIELD(in, out) \
	if (in == NULL) \
		out = NULL; \
	else { \
		out = cob_malloc(strlen(in) + 1); \
		strcpy(out, in); \
	}

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_init_con_props()\n", me);
#endif

	COPY_FIELD(props_in->dsn, props_out->dsn);
	COPY_FIELD(props_in->driver_name, props_out->driver_name);
	COPY_FIELD(props_in->server_name, props_out->server_name);
	COPY_FIELD(props_in->db_name, props_out->db_name);
	COPY_FIELD(props_in->uid, props_out->uid);
	COPY_FIELD(props_in->pwd, props_out->pwd);
	COPY_FIELD(props_in->extra, props_out->extra);

#undef COPY_FIELD
}




/*
 *	Using the given properties in con, construct a connection string
 *	and prepare the connection.
 */
static int _odbc_prepare_connection(
	  cob_file_t *f
	, connection_t *con)
{
	idx_file_t *f_idx = f->file;	
	char *pb;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_prepare_connection()\n", me);
#endif

	con->tf_is_made = 0;
	// sanity checks
	if ((con->properties.dsn == NULL) && (con->properties.server_name == NULL)) 
		THROW_EXC(COB_IOEXC_ISAM_ODBC_DSN_OR_SERVER_NAME);
	if ((con->properties.dsn != NULL) && (con->properties.server_name != NULL)) 
		THROW_EXC(COB_IOEXC_ISAM_ODBC_DSN_AND_SERVER_NAME);

	con->tf_is_made = 1;
	con->h_dbc = NULL;
	con->tf_is_open = 0;
	con->c_client = 0;
	con->string = cob_malloc(1000);
	pb = con->string;
	*pb = '\0';
	if (con->properties.dsn != NULL)
		pb += sprintf(pb, "DSN=%s;", con->properties.dsn);
	if (con->properties.server_name != NULL)
		pb += sprintf(pb, "SERVERNAME=%s;", con->properties.server_name);
	if (con->properties.db_name != NULL)
		pb += sprintf(pb, "DATABASE=%s;", con->properties.db_name);
	if (con->properties.driver_name != NULL)
		pb += sprintf(pb, "DRIVER=%s;", con->properties.driver_name);
	if (con->properties.uid != NULL) {
		pb += sprintf(pb, "UID=%s;PWD=%s;", con->properties.uid, con->properties.pwd);
	} else {
		pb += sprintf(pb, "Trusted_Connection=yes;");
	}
	if (con->properties.extra != NULL) 
		pb += sprintf(pb, "%s;", con->properties.extra);
	con->string = realloc(con->string, strlen(con->string) + 1);
	return(0);
}





/*
 *	Connect to the DB Server using the connection string in
 *	arg con.
 *	Success returns 0 and DBC handle is placed in con->h_dbc.
 *	Failure reurns -1.
 *	
 */

static int _odbc_connect(
	  cob_file_t *f
	, connection_t *con)
{
	idx_file_t *f_idx = f->file;
	SQLRETURN ret;
	SQLSMALLINT cb;
	SQLHSTMT h_stmt;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_connect() using: %s\n", me, con->string);
#endif

	error_state.cb_msg_max = 0;
	if (con->string == NULL)
		THROW_EXC(COB_IOEXC_ISAM_ODBC_NO_CON_STRING);

	if (h_env == NULL) {
		if (!SQL_SUCCEEDED(ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &h_env))) {
			THROW_EXC_ODBC("SQLAllocHandle", SQL_NULL_HANDLE, SQL_HANDLE_ENV, COB_IOEXC_ISAM_ODBC_HANDLE);
		}
		if (!SQL_SUCCEEDED(ret = SQLSetEnvAttr(h_env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, SQL_IS_INTEGER))) {
			THROW_EXC_ODBC("SQLSetEnvAttr", h_env, SQL_HANDLE_ENV, COB_IOEXC_ISAM_ODBC_HANDLE);
		}
	}
	// open connection to db server
	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC, h_env, &con->h_dbc))) {
		THROW_EXC_ODBC("SQLAllocHandle", h_env, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	}
	ret = SQLDriverConnect(con->h_dbc
                         , NULL                 // no ODBC dialog so no WINDOW 
                         , (UNSC *)con->string, SQL_NTS
                         , (UNSC *)bfr, CB_AD_HOC
                         , &cb
                         , SQL_DRIVER_NOPROMPT);

	if (!SQL_SUCCEEDED(ret)) {
		THROW_EXC_ODBC("SQLDriverConnect", con->h_dbc, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_CONNECT);
	}

	// discover actual SERVER_NAME & DATABASE_NAME we are connected to.
	*bfr = '\0';
	SQLGetInfo(con->h_dbc, SQL_SERVER_NAME, (SQLPOINTER)bfr, CB_AD_HOC, NULL);
	if (*bfr != '\0') {
		if (con->server_name != NULL) free(con->server_name);
		con->server_name = cob_malloc(strlen(bfr) + 1);	
		strcpy(con->server_name, bfr);
	}	
	*bfr = '\0';
	SQLGetInfo(con->h_dbc, SQL_DATABASE_NAME, (SQLPOINTER)bfr, CB_AD_HOC, NULL);
	if (*bfr != '\0') {
		if (con->db_name != NULL) free(con->db_name);	
		con->db_name = cob_malloc(strlen(bfr) + 1);	
		strcpy(con->db_name, bfr);
	}	

	// discover type of server we are connected to.
	if (SQL_SUCCEEDED(SQLGetInfo(con->h_dbc, SQL_DBMS_NAME, (SQLPOINTER)bfr, CB_AD_HOC, NULL))) {
		con->tf_is_sqlserver = (NULL != strcasestr(bfr, "SQL SERVER"));
		con->dbms_name = cob_malloc(strlen(bfr) +1);
		strcpy(con->dbms_name, bfr);
	} else {
		con->dbms_name = cob_malloc(5);
		strcpy(con->dbms_name, "ANON");
		con->tf_is_sqlserver = 0;
	}
	con->max_binary = DEFAULT_MAX_BINARY;
	if (SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, con->h_dbc, &h_stmt))) {
		if (SQL_SUCCEEDED(SQLGetTypeInfo(h_stmt, SQL_BINARY))) {
			if (SQL_SUCCEEDED(SQLFetch(h_stmt))) {
				// get COLUMN_SIZE i.e. max bytes storable in BINARY
				SQLGetData(h_stmt, 3, SQL_INTEGER, &con->max_binary, 0, NULL);
			}
		}
		SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
	}

	con->tf_is_open = 1;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 5) {
		fprintf(stderr, "%s: connected SERVER = [%s]   DB = [%s]\n"
		      , me, con->server_name, con->db_name);
		fprintf(stderr, "%s: _odbc_connect() MAX BINARY: %d is_SQL_SERVER: %s\n"
		      , me, (int)con->max_binary, con->tf_is_sqlserver ? "yes" : "no");
	}
#endif
			 
	return(0);
}




/*
 *	Given a COBOL expanded file-name, substitute
 *	'_' for '-' and FILE_NAME_SEPARATOR
 *
 *	Return a pointer to the table_name produced
 *	- malloc-d space.
 */
static char *_odbc_preen_filename(char *fid)
{
	char *table_name, *pb;
	table_name = cob_malloc(strlen(fid) + 1);
	if (*fid == FILE_NAME_SEPARATOR) {
		strcpy(table_name, fid + 1);
	} else {
		strcpy(table_name, fid);
	}
	for (pb = table_name; *pb; ++pb) {
		if ((*pb == '-')
			|| (*pb == FILE_NAME_SEPARATOR)) {
			*pb = '_';
		}
	}
	return(table_name);
}






#ifndef WITH_ODBC_DYNAMIC_CONNECTION


/*
 *	
 *	There is a single connection in use. All files reside
 *	in tables in the same database on the same server.
 *	If the connection has already been opened it is re-used.	
 *	Otherwise, for the first time, the connection properties
 *	are set from the environment; the connection string is
 *	prepared; the connection is opened.
 *
 *	On success: returns 0 and f_idx->con_command is set to
 *		the connection.
 *		f_idx->table_name is the name of the DB table to be used.
 *	On failure: returns non-zero value and exceptions are thrown.
 */


static int _odbc_open_table(
	  cob_file_t *f) 
{
	idx_file_t *f_idx = f->file;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_open_table()\n", me);
#endif

	if (!connection_pool[0].tf_is_made) {
		_odbc_init_con_props(&env_con_prop, &connection_pool[0].properties);
		if (0 != _odbc_prepare_connection(f, &connection_pool[0])) {
			return(-1);
		}
		if (0 != _odbc_connect(f, &connection_pool[0])) {         
			return(-1);
		}
		connection_pool[0].c_client = -1;         // ensure not freed (until EOJ)
	}
	if (!connection_pool[0].tf_is_open) 
		THROW_EXC(COB_IOEXC_ISAM_ODBC_CONNECT);

	f_idx->con_command = &connection_pool[0];
	f_idx->db_name = cob_malloc(strlen(f_idx->con_command->db_name) + 1);
	strcpy(f_idx->db_name, f_idx->con_command->db_name);
	f_idx->table_name = _odbc_preen_filename(f->fid);
	return(0);
}

#endif






#ifdef WITH_ODBC_DYNAMIC_CONNECTION



/*
 *	
 *	Connections start with properties from the environment
 *	which are modulated by the COBOL file name.
 *	Therefore the connections are re-made when each file is opened.
 *	If a suitable connection has already been opened it is re-used.	
 *	Otherwise, the connection properties are set;
 *	the connection string is prepared; the connection is opened.
 *
 *	On success: returns 0 and f_idx->con_command is set to
 *		the connection.
 *		f_idx->table_name is the name of the DB table to be used.
 *	On failure: returns non-zero value and exceptions are thrown.
 */


static int _odbc_open_table(
	  cob_file_t *f) 
{
	idx_file_t *f_idx = f->file;
	con_props_t props;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_open_table()\n", me);
#endif

	if (0 != _odbc_modulate_properties(f, &env_con_prop, &props)) 
		return(-1);
	if (0 != _odbc_set_connection(f, &props, &f_idx->con_command)) 
		return(-1);

	if (!f_idx->con_command->tf_is_open) {
		if (0 != _odbc_prepare_connection(f, f_idx->con_command)) {
			return(-1);
		}
		if (0 != _odbc_connect(f, f_idx->con_command)) {
			return(-1);
		}
	}
	++f_idx->con_command->c_client;
	return(0);
}





/*
 *	The default connection properties are in props_dft.
 *	Parse f_idx->fid and merge SERVER_NAME / DB_NAME
 *	with the default props to get props_ret.
 *	Side effect: f_idx->table_name is assigned (malloc-d space).
 */
static int _odbc_modulate_properties(
	  cob_file_t *f
	, con_props_t *props_dft
	, con_props_t *props_ret)
{
	idx_file_t *f_idx = f->file;
	int cb_fid;
	char *table_name, *data_source_name, *db_name, **target;


#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_modulate_properties()\n", me);
#endif

	_odbc_init_con_props(props_dft, props_ret);

	if (*f->fid != FILE_NAME_SEPARATOR) {
		f_idx->table_name = _odbc_preen_filename(f->fid);
		return(0);
	}
	cb_fid = strlen(f->fid) + 1;
	data_source_name = cob_malloc(cb_fid);
	db_name = cob_malloc(cb_fid);
	table_name = cob_malloc(cb_fid);
	*data_source_name = *db_name = *table_name = '\0';
	_odbc_parse_file_name(data_source_name, db_name, table_name, f->fid);
	if (*data_source_name == '\0') {
		free(data_source_name);
	} else {
		// fid can deliver DSN or SERVER depending on how env was set
		target = (props_dft->dsn == NULL)
		       ? &(props_ret->server_name)
		       : &(props_ret->dsn);
		if (*target != NULL) {
			free(*target);
		}
		*target  = data_source_name;
	}
	if (*db_name == '\0') {
		free(db_name);
	} else {
		if (props_ret->db_name != NULL) {
			free(props_ret->db_name);
		}
		props_ret->db_name = db_name;
	}
	f_idx->db_name = cob_malloc(strlen(db_name) + 1);
	strcpy(f_idx->db_name, db_name);
	f_idx->table_name = _odbc_preen_filename(table_name);
	free(table_name);

	return(0);
}






/*
 *	Given the connection properties in <con_props>,
 *	search the connection pool for a matching connection
 *	and return a pointer to it in con_ret.
 *	If no match is found: initialise a new connection
 *	with the given properties and return a pointer to it.
 */

static int _odbc_set_connection(
	  cob_file_t *f
	, con_props_t *con_props
	, connection_t **con_ret)
{
	idx_file_t *f_idx = f->file;
	int ix_pool;
	connection_t *con;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _odbc_set_connection()\n", me);
#endif

	// search for connection already made for data-source
	for (ix_pool = 0; ix_pool < MAX_CONNECTION; ++ix_pool) {
		con = &connection_pool[ix_pool];
		if (con->tf_is_made) {
			if ((con_props->dsn != NULL)
				&& !strcmp(con->properties.dsn, con_props->dsn))
				break;
			if ((con_props->server_name != NULL)
				&& !strcmp(con->properties.server_name, con_props->server_name)) 
				break;
		}
	}
	if (ix_pool < MAX_CONNECTION) {
		*con_ret = con;
#ifdef WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: recycling connection :: 0x%lx\n", me, (long)con);
#endif
		return(0);
	}
	// search for 1st free connection in pool
	for (ix_pool = 0; ix_pool < MAX_CONNECTION; ++ix_pool) {
		con = &connection_pool[ix_pool];
		if (!con->tf_is_made)
			break;
	}
	if (ix_pool == MAX_CONNECTION) {
		THROW_EXC(COB_IOEXC_ISAM_TOO_MANY_DB_CONNECTIONS);
	}
	_odbc_init_con_props(con_props, &con->properties);
	con->server_name = NULL;
	con->db_name = NULL;
	con->dbms_name = NULL;
	con->tf_is_made = 1;
	*con_ret = con;
	return(0);
}



/*
 *	Examine the segments of the expanded file-name and
 *	rip up to 3 fields: data_source, db, table.
 *	Possible segments:
 * 		/file-name
 *		/db-name/file-name
 *		/data_source/db-name/file-name 
 *
 *	Where no value is ripped for a field, the field is
 *	left uchanged.
 */

static int _odbc_parse_file_name(
	  char *data_source
	, char *db_name
	, char *table_name
	, char *file_name)
{
	int c_segs = 1;
	char *pb1, *pb2;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _odbc_parse_file_name(%s)\n", me, file_name);
#endif

	pb1 = file_name + 1;
	while (*(pb1++)) {
		c_segs += (*pb1 == FILE_NAME_SEPARATOR) ? 1 : 0;
	}
	if (c_segs > 3) c_segs = 3;
	pb1 = file_name + 1;
	switch (c_segs) {
		case 1:
			strcpy(table_name, pb1);
			break;
		case 2:
			pb2 = db_name;
			while (*pb1 && (*pb1 != FILE_NAME_SEPARATOR)) {
				*pb2++ = *pb1++;
			}
			*pb2 = '\0';
			pb1++;
			pb2 = table_name;
			while (*pb1) {
				*pb2++ = *pb1++;
			}
			*pb2 = '\0';
			break;
		case 3:
			pb2 = data_source;
			while (*pb1 && (*pb1 != FILE_NAME_SEPARATOR)) {
				*pb2++ = *pb1++;
			}
			*pb2 = '\0';
			pb1++;
			pb2 = db_name;
			while (*pb1 && (*pb1 != FILE_NAME_SEPARATOR)) {
				*pb2++ = *pb1++;
			}
			*pb2 = '\0';
			pb1++;
			pb2 = table_name;
			while (*pb1) {
				*pb2++ = *pb1++;
			}
			*pb2 = '\0';
			break;
	}

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _odbc_parse_file_name(%s) --> %s :: %s :: %s\n"
		      , me, file_name, data_source, db_name, table_name);
#endif
	return(0);
}



#endif  // WITH_ODBC_DYNAMIC_CONNECTION





/*
 *	Prepare an ODBC statement designed to INSERT a new row into the
 *	DB table. All parameters are bound to fields in f_idx. If the
 *	COBOL record size is very large, the data for field "data" is
 *	passed dynamically when the statement is executed.
 */

static int _odbc_make_insert_statement(
	  idx_file_t *f_idx)
{
	int ix_key, i_arg, res = 0;
	SQLHSTMT h_stmt;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _odbc_make_insert_statement()\n", me);
#endif

	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, f_idx->con_command->h_dbc, &h_stmt))) 
		THROW_EXC_ODBC("SQLAllocHandle", f_idx->con_command->h_dbc, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	f_idx->h_insert = h_stmt;
	p_sql = sql;
	p_sql += sprintf(p_sql, "INSERT INTO %s (", f_idx->dbt);
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		p_sql += sprintf(p_sql, "key_%d, ", ix_key);
	}
	if (!f_idx->tf_fixed_rsz) {
		p_sql += sprintf(p_sql, "rsz, ");
	}
	p_sql += sprintf(p_sql, "data) values (");
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		p_sql += sprintf(p_sql, "?, ");
	}
	if (!f_idx->tf_fixed_rsz) {
		p_sql += sprintf(p_sql, "?, ");
	}
	p_sql += sprintf(p_sql, "?)");

	i_arg = 1;
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
			, SQL_C_BINARY, SQL_BINARY
			, f_idx->keydef[ix_key].cb_key, 0
			, (SQLPOINTER) f_idx->row.key_value[ix_key]
			, (SQLLEN) f_idx->keydef[ix_key].cb_key
		    , &f_idx->keydef[ix_key].cb_key);
		if (!SQL_SUCCEEDED(res)) break;
	}
	if (SQL_SUCCEEDED(res) && !f_idx->tf_fixed_rsz) {
		res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
			, SQL_C_SLONG, SQL_INTEGER
			, 0, 0
			, (SQLPOINTER) &f_idx->row.rsz, 0
		    , NULL);
	}
	if (SQL_SUCCEEDED(res)) {
		if (DATA_IS_BIG(f_idx->con_command, f_idx->data_size)) {
			res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
				, SQL_C_BINARY, SQL_LONGVARBINARY
				, f_idx->data_size, 0
				, (SQLPOINTER) f_idx->row.data, 0
			    , &data_grab_flag);
		} else {
			res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
				, SQL_C_BINARY, SQL_BINARY
				, f_idx->data_size, 0
				, (SQLPOINTER) f_idx->row.data
				, (SQLLEN) f_idx->row.rsz
			    , (SQLLEN *) &f_idx->row.rsz);
		}
	}
	if (!SQL_SUCCEEDED(res)) 
		THROW_EXC_ODBC("SQLBindParameter", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_BIND);

	#ifdef WITH_FILEIO_TRACE
		if (trace_level > 8)
			fprintf(stderr, "%s: Prepare SQL: %s\n", me, sql);
	#endif
	if (0 != SQLPrepare(h_stmt, (SQLC *)sql, strlen(sql)))
		THROW_EXC_ODBC("SQLPrepare", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_PREPARE);
	return(0);
}




/*
 *	Prepare an ODBC statement designed to UPDATE a row in the
 *	DB table. All parameters are bound to fields in f_idx. If the
 *	COBOL record size is very large, the data for field "data" is
 *	passed dynamically when the statement is executed.
 */

static int _odbc_make_update_statement(
	  idx_file_t *f_idx)
{
	int ix_key, i_arg, res = 0;
	SQLHSTMT h_stmt;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _odbc_make_update_statement()\n", me);
#endif

	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, f_idx->con_command->h_dbc, &h_stmt))) 
		THROW_EXC_ODBC("SQLAllocHandle", f_idx->con_command->h_dbc, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	f_idx->h_update = h_stmt;
	p_sql = sql;
	p_sql += sprintf(p_sql, "UPDATE %s SET ", f_idx->dbt);
	// primary key is immutable
	for (ix_key = 1; ix_key < f_idx->c_key; ++ix_key) {
		p_sql += sprintf(p_sql, "key_%d = ?, ", ix_key);
	}
	if (!f_idx->tf_fixed_rsz) {
		p_sql += sprintf(p_sql, "rsz = ?, ");
	}
	p_sql += sprintf(p_sql, "data = ? ");
	p_sql += sprintf(p_sql, "WHERE (is_control = 0) AND (key_0 = ?)");

	i_arg = 1;
	for (ix_key = 1; ix_key < f_idx->c_key; ++ix_key) {
		res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
			, SQL_C_BINARY, SQL_BINARY
			, f_idx->keydef[ix_key].cb_key, 0
			, (SQLPOINTER) f_idx->row.key_value[ix_key]
			, (SQLLEN) f_idx->keydef[ix_key].cb_key
		    , (SQLLEN *) &f_idx->keydef[ix_key].cb_key);
		if (!SQL_SUCCEEDED(res)) break;
	}
	if (SQL_SUCCEEDED(res) && !f_idx->tf_fixed_rsz) {
		res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
			, SQL_C_SLONG, SQL_INTEGER
			, 0, 0
			, (SQLPOINTER) &f_idx->row.rsz, 0
		    , NULL);
	}
	if (SQL_SUCCEEDED(res)) {
		if (DATA_IS_BIG(f_idx->con_command, f_idx->data_size)) {
			res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
				, SQL_C_BINARY, SQL_LONGVARBINARY
				, f_idx->data_size, 0
				, (SQLPOINTER) f_idx->row.data, 0
			    , &data_grab_flag);
		} else {
			res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
				, SQL_C_BINARY, SQL_BINARY
				, f_idx->data_size, 0
				, (SQLPOINTER) f_idx->row.data
				, (SQLLEN) f_idx->data_size
			    , (SQLLEN *) &f_idx->data_size);
		}
	}
	ix_key = 0;
	if (SQL_SUCCEEDED(res)) {
		res = SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
			, SQL_C_BINARY, SQL_BINARY
			, f_idx->keydef[ix_key].cb_key, 0
			, (SQLPOINTER) f_idx->row.key_value[ix_key]
			, (SQLLEN) f_idx->keydef[ix_key].cb_key
		    , (SQLLEN *) &f_idx->keydef[ix_key].cb_key);
	}
	if (!SQL_SUCCEEDED(res)) 
		THROW_EXC_ODBC("SQLBindParameter", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_BIND);

	#ifdef WITH_FILEIO_TRACE
		if (trace_level > 8)
			fprintf(stderr, "%s: Prepare SQL: %s\n", me, sql);
	#endif
	if (0 != SQLPrepare(h_stmt, (SQLC *)sql, strlen(sql)))
		THROW_EXC_ODBC("SQLPrepare", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_PREPARE);
	return(0);
}






/*
 *	Prepare an ODBC statement designed to DELETE a row in the
 *	DB table. Parameter key_0 is bound to primary-key in f_idx. 
 */
static int _odbc_make_delete_statement(
	  idx_file_t *f_idx)
{
	int i_arg;
	SQLHSTMT h_stmt;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _odbc_make_delete_statement()\n", me);
#endif

	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, f_idx->con_command->h_dbc, &h_stmt))) 
		THROW_EXC_ODBC("SQLAllocHandle", f_idx->con_command->h_dbc, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	f_idx->h_delete = h_stmt;
	p_sql = sql;
	p_sql += sprintf(p_sql, "DELETE %s WHERE (is_control = 0) AND (key_0 = ?)", f_idx->dbt);

	i_arg = 1;
	if (!SQL_SUCCEEDED(SQLBindParameter(h_stmt, i_arg++, SQL_PARAM_INPUT
			, SQL_C_BINARY, SQL_BINARY
			, f_idx->keydef[0].cb_key, 0
			, (SQLPOINTER) f_idx->row.key_value[0]
			, (SQLLEN) f_idx->keydef[0].cb_key
		    , (SQLLEN *) &f_idx->keydef[0].cb_key)))
		THROW_EXC_ODBC("SQLBindParameter", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_BIND);

	#ifdef WITH_FILEIO_TRACE
		if (trace_level > 8)
			fprintf(stderr, "%s: Prepare SQL: %s\n", me, sql);
	#endif
	if (0 != SQLPrepare(h_stmt, (SQLC *)sql, strlen(sql)))
		THROW_EXC_ODBC("SQLPrepare", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_PREPARE);
	return(0);
}






/*
 *	Reopen the cursor and position it at the last read record
 */
static int _odbc_resynch_cursor(idx_file_t *f_idx)
{

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 6)
		fprintf(stderr, "%s: _odbc_resynch_cursor(%d)\n", me, f_idx->fpi.ix_key);
#endif
	
	f_idx->cb_key_sig = f_idx->keydef[f_idx->fpi.ix_key].cb_key;
	memcpy(f_idx->row.key_value[f_idx->fpi.ix_key]
	     , f_idx->fpi.key_value[f_idx->fpi.ix_key]
	     , f_idx->cb_key_sig);
	f_idx->row.id = f_idx->fpi.id;
	return(_odbc_make_cursor(f_idx, f_idx->fpi.ix_key, CURSOR_CURRENT));
}







/*
 *	Coin an SQL SELECT query to match given mode.
 *	The SQL is coined based on the current values of the active key
 *	and record ID (in f_idx).
 *	Allocate a SQL Statement and execute it.
 */
static int _odbc_make_cursor(
	  idx_file_t *f_idx
	, int ix_key_of_ref
	, int mode)
{
	int ix_key;
	SQLHSTMT h_stmt;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 6)
		fprintf(stderr, "%s: _odbc_make_cursor(%d, %d)\n", me, ix_key_of_ref, mode);
#endif
	
	if (f_idx->cursor.h_stmt != NULL) {
		SQLFreeHandle(SQL_HANDLE_STMT, f_idx->cursor.h_stmt);
		f_idx->cursor.h_stmt = NULL;
	}
	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, f_idx->cursor.con.h_dbc, &f_idx->cursor.h_stmt))) 
		THROW_EXC_ODBC("SQLAllocHandle", f_idx->cursor.con.h_dbc, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	h_stmt = f_idx->cursor.h_stmt;
	f_idx->cursor.tf_resynch = 0;

	p_sql = sql;
	p_sql += sprintf(p_sql, "SELECT id, "); 
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		p_sql += sprintf(p_sql, "key_%d, ", ix_key);
	}
	if (!f_idx->tf_fixed_rsz) {
		p_sql += sprintf(p_sql, "rsz, ");
	}
	p_sql += sprintf(p_sql, "data FROM %s WHERE (is_control = 0)", f_idx->dbt);
 
	ix_key = ix_key_of_ref;
	if (f_idx->keydef[ix_key].tf_suppress) {
		memset(f_idx->key_work, f_idx->keydef[ix_key].ch_suppress, f_idx->keydef[ix_key].cb_key);
		cob_fileio_format_SQL_literal(f_idx->key_work, f_idx->keydef[ix_key].cb_key, bfr);
		p_sql += sprintf(p_sql, " AND (key_%d != %s)", ix_key, bfr);
	}
	cob_fileio_format_SQL_literal(f_idx->row.key_value[ix_key], f_idx->cb_key_sig, bfr);
	if (mode == CURSOR_FIRST) {
		f_idx->cursor.direction = CURSOR_ADVANCE;
	} else if (mode == CURSOR_LAST) {
		f_idx->cursor.direction = CURSOR_RETREAT;
	} else if (mode == CURSOR_CURRENT) {
		f_idx->cursor.direction = CURSOR_ADVANCE;
		p_sql += sprintf(p_sql, " AND ((key_%d > %s) OR ((key_%d = %s) AND (id >= %ld)))"
			, ix_key, bfr, ix_key, bfr, f_idx->row.id);
	} else {	
		f_idx->cursor.direction = ((mode == CURSOR_LT) || (mode == CURSOR_LE)) 
			? CURSOR_RETREAT : CURSOR_ADVANCE;
		p_sql += sprintf(p_sql, " AND (key_%d %s %s)"
		      , ix_key
		      ,   (mode == CURSOR_LT) ? "<"
		        : (mode == CURSOR_LE) ? "<="
		        : (mode == CURSOR_EQ) ? ">="
		        : (mode == CURSOR_GE) ? ">="
		        : (mode == CURSOR_GT) ? ">"
		        : "!!!"
		      , bfr);
	}
	sprintf(p_sql, " ORDER BY key_%d %s, id %s", ix_key
	      , (f_idx->cursor.direction == CURSOR_RETREAT) ? "DESC" :"ASC"
		  , (f_idx->cursor.direction == CURSOR_RETREAT) ? "DESC" :"ASC");

	#ifdef WITH_FILEIO_TRACE
		if (trace_level > 8)
			fprintf(stderr, "%s: Prepare SQL: %s\n", me, sql);
	#endif
	if (0 != SQLPrepare(h_stmt, (SQLC *)sql, strlen(sql)))
		THROW_EXC_ODBC("SQLPrepare", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_ODBC_PREPARE);
	f_idx->ix_key = ix_key_of_ref;
	return(_odbc_execute_statement(f_idx, f_idx->cursor.h_stmt));
}







/*
 *	Execute the given prepared statement.
 *
 *	Return 0 on success
 */
static int _odbc_execute_statement(
	  idx_file_t *f_idx
	, SQLHSTMT h_stmt)
{
	int res, cb, cb_block;
	char *pb;
	PTR parmID;
	
#ifdef WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _odbc_execute_statement()\n", me);
#endif

	if (DATA_IS_BIG(f_idx->con_command, f_idx->data_size)) {
		data_grab_flag = SQL_LEN_DATA_AT_EXEC(f_idx->row.rsz);
	}	res = SQLExecute(h_stmt);
	if (SQL_SUCCEEDED(res)) 
		return(0);
	if (res != SQL_NEED_DATA)
		THROW_EXC_ODBC("SQLExecute", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED);

	
#ifdef WITH_FILEIO_TRACE
	if (trace_level > 5)
		fprintf(stderr, "%s: ... feeding BIG data [%ld bytes]\n", me, f_idx->row.rsz);
#endif

	// the only field we feed is: [data] when BIG
	pb = f_idx->row.data;
	cb = f_idx->row.rsz;
	while (1) {
		// CAUTION: must call SQLParamData() 1 more time after feeding all data
		res = SQLParamData(h_stmt, &parmID);
		if (SQL_SUCCEEDED(res)) 
			break;
		if (res != SQL_NEED_DATA)
			THROW_EXC_ODBC("SQLParamData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED);
		if (cb == 0) {
			fprintf(stderr, "!!! Internal Error :: over-demand for data [%d bytes] from SQLParamData\n\n"
			      , (int)f_idx->row.rsz);
			THROW_EXC(COB_IOEXC_INTERNAL);
		}
		while (cb > 0) {
			cb_block = (cb > CB_BLOB_BLOCK) ? CB_BLOB_BLOCK : cb;
			res = SQLPutData(h_stmt, pb, cb_block);
			if (SQL_SUCCEEDED(res) || (res == SQL_NEED_DATA)) {
				cb -= cb_block;			
				pb += cb_block;
			} else {
				THROW_EXC_ODBC("SQLPutData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED);
			}
		}
	}
	// success is when we have sent f_idx->row.rsz bytes
	// and ODBC driver doesn't need more data
	if (cb != 0) {
		fprintf(stderr, "!!! Internal Error :: failed to send complete data via SQLPutData\n");
		fprintf(stderr, "                   :: sent %d of total %d bytes\n\n"
		      , (int)f_idx->row.rsz - cb, (int)f_idx->row.rsz);
		THROW_EXC(COB_IOEXC_INTERNAL);
	}
	if (res == SQL_NEED_DATA) {
		fprintf(stderr, "!!! Internal Error :: failed to send complete data [%d bytes] via SQLPutData\n\n"
		      , (int)f_idx->row.rsz);
		THROW_EXC(COB_IOEXC_INTERNAL);
	}
	return(0);
}







/*
 *	Execute an SQL query.
 *	A statement handle is allocated. The SQL is executed.
 *	The handle is returned in h_stmt_ret. The client should free the handle
 *	when finished with it. (This is the case when the SQL is expected
 *	to return rows.)
 *	Alternatively, if h_stmt_ret is NULL, the handle is freed before returning.
 *
 *	Returns: 0 if successful. Result SQL_NO_DATA is considered to be successful.
 *	        -1 otherwise.
 */

static int _odbc_execute_sql(
	  idx_file_t *f_idx
	, char *sql
	, SQLHSTMT *h_stmt_ret)
{
	int res;
	SQLHSTMT h_stmt;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _odbc_execute_sql()\n%.1000s\nEND-OF-SQL (1st 1000 chars)\n", me, sql);
#endif

	if (!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, f_idx->con_command->h_dbc, &h_stmt))) 
		THROW_EXC_ODBC("SQLAllocHandle", f_idx->con_command->h_dbc, SQL_HANDLE_DBC, COB_IOEXC_ISAM_ODBC_HANDLE);
	res = SQLExecDirect(h_stmt, (UNSC *)sql, strlen(sql));
	if (SQL_SUCCEEDED(res) || (res == SQL_NO_DATA)) { 
		if (h_stmt_ret == NULL) {
			SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
		} else {
			*h_stmt_ret = h_stmt;
		}
		return(0);
	}
	SET_EXC_ODBC("SQLExecute", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
	return(-1);
}








/*
 *	Fetch the next row using the cursor statement supplied.
 *	All cursor statements SELECT:
 *		id, key_0 [, key_1 ... key_n] [, rsz] , data	
 *
 *	Success: returns 0
 *		row returned: The struct f_idx->row is populated.
 *		              f_idx->row.tf_found == 1.
 *		no row:       f_idx->row.tf_found == 0.
 *
 *	Otherwise: throws an exception and returns -1.
 */
static int _odbc_fetch_record(
	  idx_file_t *f_idx
	, SQLHSTMT *h_stmt
	, row_t *row)
{
	int ix_key, i_arg, res;
	SQLLEN cb, cb_block;
	char *pb;

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _odbc_fetch_record() \n", me);
#endif

	row->tf_found = 0;
	i_arg = 1;
	res = SQLFetch(h_stmt);
	if (res == SQL_NO_DATA)
		return(0);
	if (!SQL_SUCCEEDED(SQLGetData(h_stmt, i_arg++, SQL_C_LONG, &row->id, 0, NULL)))
		THROW_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
	for (ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		res = SQLGetData(h_stmt, i_arg++, SQL_C_BINARY, row->key_value[ix_key], f_idx->keydef[ix_key].cb_key +1, NULL);
		if (!SQL_SUCCEEDED(res)) {
			THROW_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
		}
	}
	if (!f_idx->tf_fixed_rsz) {
		if (!SQL_SUCCEEDED(SQLGetData(h_stmt, i_arg++, SQL_C_LONG, &row->rsz, 0, NULL))) 
			THROW_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
	}
	if (DATA_IS_BIG(f_idx->con_command, f_idx->data_size)) {
	
#ifdef WITH_FILEIO_TRACE
	if (trace_level > 5)
		fprintf(stderr, "%s: ... fetching BIG data [%ld bytes]\n", me, f_idx->data_size);
#endif

		pb = row->data;
		cb = f_idx->data_size;
		while(cb > 0) { 
			cb_block = (cb > CB_BLOB_BLOCK) ? CB_BLOB_BLOCK : cb;
			res = SQLGetData(h_stmt, i_arg, SQL_C_BINARY, pb, cb_block, NULL);
			if (res == SQL_NO_DATA) {
				// the driver is short-changing us : we know cb_data is f_idx->data_size
				fprintf(stderr, "!!! Internal Error :: short block received from ODBC Driver: SQLGetData\n");
				THROW_EXC(COB_IOEXC_INTERNAL);
			}
			if (!SQL_SUCCEEDED(res)) {      // driver returns SUCCESS_WITH_INFO for intermediate blocks
				THROW_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
			}
			pb += cb_block;
			cb -= cb_block;
		}
	} else {
		res = SQLGetData(h_stmt, i_arg, SQL_C_BINARY, row->data, f_idx->data_size +1, NULL);
		if (!SQL_SUCCEEDED(res)) {
			THROW_EXC_ODBC("SQLGetData", h_stmt, SQL_HANDLE_STMT, COB_IOEXC_ISAM_FAILED)
		}
	}
	row->tf_found = 1;
	return(0);
}






static int _odbc_lock_record(
	  cob_file_t *f
	, int cob_lock)
{
	return(0);
}





static int _odbc_unlock_records(idx_file_t *f_idx)
{
	return(0);
}
 




		

#ifdef WITH_FILEIO_TRACE

// Development + diagnostic aids

static void _odbc_log_key(
	  idx_file_t *f_idx
	, int ix_key
	, char *pb_primary_key
	, char *pb_active_key
	, key_log_t *log_entry)
{
	if (pb_active_key != NULL)
		ix_key = -1;
	++log_entry->c_io;
	log_entry->ix_key = ix_key;
   	memcpy(log_entry->pb_pkey_value, pb_primary_key, f_idx->keydef[0].cb_key);
	if (ix_key > 0) 
   		memcpy(log_entry->pb_skey_value, pb_active_key, f_idx->keydef[ix_key].cb_key);
}





/*
 *	Return a human-readable description of index-file (current state).
 *	Space is malloc-d and should be freed by the client. 
 */
static char *_odbc_dump_file_description(
	  cob_file_t *f
	, int tf_show_counts) 
{
	int cb_space = 4000;
	int ix, ix_key, ix_comp, cb_txt = 0;
	char txt[cb_space];
	char *pb;
	key_log_t klog;
	struct tm *tm;
	idx_file_t *f_idx = f->file;
	cb_txt += sprintf(txt, "INDEXED-FILE IMPLEMENTATION: ODBC DB [%s]\n", SQL_SPEC_STRING);
	cb_txt += sprintf(txt+cb_txt, "db-table-name: \"%s\"\n", f_idx->dbt);
	cb_txt += sprintf(txt+cb_txt, "key-count = %d       max-key-size = %d       current-index = %d\n"
	               , f_idx->c_key, f_idx->cb_key_max, f_idx->fpi.ix_key);
	for(ix_key = 0; ix_key < f_idx->c_key; ++ix_key) {
		cb_txt += sprintf(txt+cb_txt, "KEY %d: COBOL x0%lx : %s"
		                , ix_key
		                , (long)f_idx->keydef[ix_key].cob_field_key
						, f_idx->keydef[ix_key].tf_duplicates ? "DUPLICATES" : "UNIQUE");
		if (f_idx->keydef[ix_key].tf_suppress) {
			cb_txt += sprintf(txt+cb_txt, " : SUPPRESS ALL 0x%2.2x", f_idx->keydef[ix_key].ch_suppress);
		}
		cb_txt += sprintf(txt+cb_txt, " : size = %db   fields :: "
		                , (int)f_idx->keydef[ix_key].cb_key);
		for(ix_comp = 0; ix_comp < f_idx->keydef[ix_key].c_comp; ++ix_comp) {
			cb_txt += sprintf(txt+cb_txt, "%c%d.%d"
			                , (ix_comp == 0) ? ' ' : ':'
				            , f_idx->keydef[ix_key].comp[ix_comp].rb
				            , f_idx->keydef[ix_key].comp[ix_comp].cb);
		}
		*(txt+cb_txt++) = '\n';
	}
	if (tf_show_counts) {
		cb_txt += sprintf(txt+cb_txt, "\nI-O          COUNT LAST                PRIMARY-KEY");      
		cb_txt += sprintf(txt+cb_txt, "\n                                       SECONDARY-KEY\n");      
		for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) {
			cb_txt += sprintf(txt+cb_txt, "%-10s", trail_caption[ix]);
			klog = f_idx->key_trail[ix];
			if (klog.c_io == 0) {
				cb_txt += sprintf(txt+cb_txt, "never\n");
			} else {
				tm = localtime(&klog.time);
				cb_txt += sprintf(txt+cb_txt, "%.8d %.4d-%.2d-%.2d %.2d:%.2d:%.2d "
				                , klog.c_io
				                , tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday
				                , tm->tm_hour, tm->tm_min, tm->tm_sec);
				cb_txt += sprintf(txt+cb_txt, "%s\n"
				                , cob_fileio_fmtstr(klog.pb_pkey_value, f_idx->keydef[0].cb_key));
				if (klog.ix_key > 0) {
					cb_txt += sprintf(txt+cb_txt, "%30s%.2d ::", " ", klog.ix_key);
					cb_txt += sprintf(txt+cb_txt, "%s\n"
				                    , cob_fileio_fmtstr(klog.pb_skey_value, f_idx->keydef[klog.ix_key].cb_key));
				}
			}
		}
	}
	*(txt+cb_txt) = '\0';
	pb = cob_malloc(cb_txt+1);
	strcpy(pb, txt);
	return(pb);
}

#endif			// WITH_FILEIO_TRACE
 

#endif          // WITH_INDEXED_ODBC

