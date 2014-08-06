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






#include "config.h"

/*
 * This entire module is excluded unless configured
 *		WITH_INDEXED_BDB | WITH_INDEXED_BDB_1
 */

#if defined(WITH_INDEXED_BDB) || defined(WITH_INDEXED_BDB_1)


#include "fileio-misc.h"
#include "fileio-isam.h"


/*
 *
 *	There are currently (2013) two implementations of the OpenCOBOL 
 *	fileio interface to BERKELEY DB:
 *
 *	1. Configuration defined: WITH_INDEXED_BDB
 *	Built & tested with BERKELEY DB 5.3.21 and BDB 4.1.
 *
 *	2. Configuration defined: WITH_INDEXED_BDB_1
 *	Built & tested with BERKELEY DB 1.85.
 *	BDB 1.85 is dated SEP-1994
 *	BDB 1.85 does not support record locking, cursors, environment, etc.
 *	
 *
 *	The implementation strategy is to code for the later releases of
 *	BDB. In this code-unit, the first half of the functions use
 *	the BDB 4.1 api. Reverse compatibility is provided by 
 *	implementing the new features in BDB 4.1 (just the features we
 *	actually use) using BDB 1.8. This constitutes the second half
 *	of this code-unit. The names of these functions are prefixed
 *	with: _bdb1_
 */

/*
 *	Keys declared in COBOL source program v. BDB File.
 *
 *	Unlike various ISAM implementations, BDB doesn't use key
 *	definitions. (When updating the db, the key and data are
 *	passed to put() as separate DBT-s.) This would require an exact
 *	correspondence between key declaration (order and size) in COBOL
 *	client and the BDB file(s) opened.
 *	To provide enhanced flexibility and integrity, OpenCOBOL persists 
 *	key definitions into a key-dictionary when a file is created.
 *	OpenCOBOL uses this information to match keys declared
 *	in the COBOL app with the BDB databases. 
 *	If a dictionary is missing it is created from the key declarations
 *	in the COBOL client. A COBOL program may declare a key for which
 *	there is no DB - so long as it is NOT referenced in a START/READ.
 *	A COBOL program may declare fewer keys than defined in the
 *	dictionary. In any case, the PRIMARY-KEY must match. When updating
 *	the file, all known keys are indexed - irrespective of whether or
 *	not they are declared in the COBOL app.
 *
 *	WITH_INDEXED_BDB_1:
 *	BDB 1.8 provides no support for the COBOL rule:
 *		"For an INDEXED file being sequentially accessed, records having
 *		the same duplicate value in an alternate record key ... are made
 *		available in the same order in which they were written."
 *	This is implemented by suffixing a serialised number to the key of
 *	each duplicate written. 
 *
 *	WITH_INDEXED_BDB:
 * 	cf. Berkeley DB Reference Guide ref.
 *	Chapter 10.  Berkeley DB Concurrent Data Store Applications
 *	Using BDB sub-system DB_INIT_CDB (which automates intra-DB locking) precludes
 *	read Cursor(s) open concurrently with a write Cursor or any update op e.g. DB->put. 
 *	Therefore a (START READ-NEXT) cursor cannot be kept open to hold our position
 *	between calls from the client.
 */

/*
 *	Sparse Keys:
 *	BDB handles sparse keys nicely: our callback function simply returns
 *	DB_DONOTINDEX when key is not to be entered into a secondary index.
 */


#ifdef WITH_INDEXED_BDB_1

#include <db1.h>


#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-isam-bdb-1";
#endif

typedef unsigned int     u_int32_t;
typedef unsigned long    irec_t;
 
#define db_lockmode_t int

#define DB_VERSION_STRING "Pre 4.1"
#define DB_VERSION_MAJOR  1
#define DB_VERSION_MINOR  85
#define DB_VERSION_PATCH  0

#undef  __P
#define __P(protos)     protos

#ifdef _WIN32
#define INITIAL_FLAGS	O_BINARY
#else
#define INITIAL_FLAGS	0
#endif


#define DB_RDONLY    0x01
#define DB_CREATE    0x02
#define DB_READWRITE 0x04

#define DB_CURRENT              1
#define DB_FIRST                2
#define DB_LAST                 3 
#define DB_NEXT                 4
#define DB_PREV                 5
#define DB_SET                  6
#define DB_SET_RANGE            7
#define DB_GET_BOTH             8 

#define DB_NOOVERWRITE         R_NOOVERWRITE

#define DB_DBT_APPMALLOC       0x001       // Callback allocated memory.
#define DB_DUP                 0x0000002


#define DB_NOTFOUND             (-30989)   // Key/data pair not found (EOF)
#define DB_KEYEXIST             (-30996)   // The key/data pair already exists
#define DB_DONOTINDEX           (-30666)   // Returned by call-back func - sparse keys

// These are padding declarations of no significance
#define ENV_CACHE_SIZE 0
#define C_LOCKS_GRANULARITY 0
#define DB_INIT_CDB 0
#define DB_INIT_MPOOL 0

#define DB_LOCK_ABORT 0
#define DB_LOCK_NOWAIT 0
#define DB_LOCK_RECORD 0
#define DB_LOCK_REMOVE 0
#define DB_LOCK_SET_TIMEOUT 0
#define DB_LOCK_SWITCH 0
#define DB_LOCK_UPGRADE 0
#define DB_LOCK_WRITE 0

#undef  DB_TXN                 // name clash & not implemented in 1.85
#undef  DB_LOCK                // name clash & not implemented in 1.85

#endif     // WITH_INDEXED_BDB_1




#ifdef WITH_INDEXED_BDB

#include <db.h>

#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-isam-bdb";
#endif


#define DB_READWRITE DB_CREATE
#define INITIAL_FLAGS	0
#define ENV_CACHE_SIZE 1            // Mb default BDB cache size (cf. cob_fileio_isam_initialise()) 
#define C_LOCKS_GRANULARITY 100     // chunks allocated for concurrent locks per file


#define BDB DB                      // BDB is synonym for DB. (BDB is a fiction invented for BDB 1.8.)

#endif    // WITH_INDEXED_BDB









// These MACROS rely upon f_idx being current.

#define DSET_I(i) f_idx->dset[i]                    
#define PDSET DSET_I(0)    

#define BDB_I(i) DSET_I(i).bdb                    
#define PDB BDB_I(0)    
               
#define CB_KEY(i) DSET_I(i).cb_key

// --------------------------------------------


// an arbitrary stopper: used to limit number of files sought when removing s-key indexes.
#define MAX_SECONDARY_KEYS 100 


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


struct __idx_file;       typedef struct __idx_file idx_file_t;



#ifdef WITH_INDEXED_BDB_1

struct __db_env;         typedef struct __db_env DB_ENV;
struct __bdb;            typedef struct __bdb BDB;
struct __dbc;            typedef struct __dbc DBC;
struct __db_txn;         typedef struct __db_txn DB_TXN;
struct __db_lock_u;      typedef struct __db_lock_u DB_LOCK;
struct __db_association; typedef struct __db_association DB_ASSOCIATION;


struct __db_env {
	char *home;
	BTREEINFO btreeinfo;

	// incomplete list - only the DB_ENV funcs we actually invoke.
 	int (*close) __P((DB_ENV *, u_int32_t));
	int (*dbremove) __P((DB_ENV *, DB_TXN *, const char *, const char *, u_int32_t));
	int (*get_data_dirs) __P((DB_ENV *, const char ***));
	int (*get_home) __P((DB_ENV *, const char **));
	int (*get_tmp_dir) __P((DB_ENV *, const char **));
	int (*lock_get) __P((DB_ENV *, u_int32_t, u_int32_t
	                   , const DBT *, db_lockmode_t, DB_LOCK *));
	int (*lock_id) __P((DB_ENV *, u_int32_t *));
	int (*lock_id_free) __P((DB_ENV *, u_int32_t));
	int (*lock_put) __P((DB_ENV *, DB_LOCK *));
	int (*open) __P((DB_ENV *, const char *, u_int32_t, int));
	int (*remove) __P((DB_ENV *, const char *, u_int32_t));
	int (*set_alloc) __P((DB_ENV *, void *(*)(size_t)
	                    , void *(*)(void *, size_t), void (*)(void *)));
	int (*set_cachesize) __P((DB_ENV *, u_int32_t, u_int32_t, int));
	void (*set_errfile) __P((DB_ENV *, FILE *));
	void (*set_msgfile) __P((DB_ENV *, FILE *));
  };



struct __bdb {
	idx_file_t *f_idx;
	int ix_dset;
	DB *db;                       // the TRUE BDB database object
	u_int32_t flags;              // qualifying db.
	char *f_name;                 // physical file-name - malloc'd
	DBC *dbc;                     // cursor open on this BDB
	int tf_duplicates;            // duplicate key-values allowed in this index
	irec_t irec;                  // record serialisation (duplicate keys only)
	DB_ASSOCIATION *db_ass;       // for primary only: associated DBs - malloc'd array
	int free_ass;                 // count of free items in db_ass
	int next_ass;                 // index to next free item in db_ass


	// incomplete list - only the DB funcs we actually invoke.
	int (*associate) __P((BDB *, DB_TXN *, BDB *, int (*)(BDB *, const DBT *
	                    , const DBT *, DBT *), u_int32_t));
	int (*close) __P((BDB *, u_int32_t));
	int (*cursor) __P((BDB *, DB_TXN *, DBC **, u_int32_t));
	int (*del) __P((BDB *, DB_TXN *, DBT *, u_int32_t));
	int (*fd) __P((BDB *, int *));
	int (*open) __P((BDB *, DB_TXN *, const char *, const char *, DBTYPE, u_int32_t, int));
	int (*put) __P((BDB *, DB_TXN *, DBT *, DBT *, u_int32_t));
	int (*set_flags) __P((BDB *, u_int32_t));
	int (*sync) __P((BDB *, u_int32_t));

 };

struct __dbc {
	BDB  *bdb;                    // BDB on which this cursor is operating
	DBT dbt_curkey;               // key used to get current record
	DBT dbt_curkey_p;             // primary-key of current record

	// incomplete list - only the DB CURSOR funcs we actually invoke.
	int (*c_close) __P((DBC *));    
	int (*c_get) __P((DBC *, DBT *, DBT *, u_int32_t));
	int (*c_pget) __P((DBC *, DBT *, DBT *, DBT *, u_int32_t));
};



struct __db_txn {
	int pad;
};

struct __db_lock_u {
	int pad;
};

struct __db_association {
	BDB *bdb;
	int (*fn_callback) __P((BDB *, const DBT *, const DBT *, DBT *)); 
};

#endif          // WITH_INDEXED_BDB_1





/*
 * A pointer (*file) in each COBOL file struct cob_file_t links 
 * to the corresponding struct idx_file.
 *
 * BDB uses a separate "database" (DB) for each index.
 * idx_file->dset[0]->db stores the primary-key and the record data.
 * idx_file->dset[n]->db stores n'th secondary key and corresponding
 * primary-key.
 * When a COBOL indexed file is opened, first the primary DB is opened;
 * then each secondary DB is opened and "associated" with the primary.
 * This delegates responsibility for maintenance of secondary indices
 * to BDB.
 * For an indexed file with a primary-key and N secondary-keys, there
 * are N+1 dset struct-s, ordered to match the BDB datasets.
 * However, for an existing file, the COBOL source might declare only
 * a subset of the keys and not necessarily in matching
 * order. (cf. notes on key-dictionary above.) 
 * 
 * To emphasise that the n'th key in cob_file_t is NOT necessarily the
 * n'th key in idx_file:
 *		the index to cob_file->keys is named ix_key;
 *		the index to f_idx->dset is named ix_dset;
 *
*/

typedef struct {
	int              c_io;                       // i-o count
	time_t           time;                       // time i-o occured
	char            *pb_pkey_data;               // pointer to primary-key value
	char            *pb_skey_data;               // pointer to secondary-key value (iff ix_dset > 0)
	int              ix_dset;                    // active index used to read record	                                             // (ix_dset > 0 if record was read by secondary-key value pb_skey_data)
} key_log_t;


typedef struct {
	int              rb;                         // byte offset to start of component relative to start of record
	int              cb;                         // byte-count size of component 
} component_t;



typedef struct {                                     // description of key - loaded from COBOL app or key-dictionary
	BDB             *bdb;                        // BDB managing this key		
	cob_field       *cob_field_key;              // pointer to matching key in struct cob_file. NULL if undeclared in COBOL
	int              cb_key;                     // byte-count size of composite-key
	int              tf_duplicates;              // true if duplicate values OK for this key
	int              tf_suppress;                // true if some values suppressed for this key
	unsigned char    ch_suppress;                // skip row if tf_suppress && (key == all this char)
	int              c_comp;                     // count of components
	component_t      comp[COB_MAX_KEYCOMP];      // components constituting key
} dset_t;



/*
 * The file-position-indicator (fpi) records the current
 * position in the file. It is reset by READ and START.
 * READ NEXT is relative to the fpi.
 * (WRITE, REWRITE and DELETE do NOT change fpi).
*/
typedef struct {                                 
	int              tf_is_set;                  // there is a current record
	int              ix_dset;                    // index used to get current record (0..c_dset-1)
	char            *pb_key_data;                // value of key used to get current record
	char            *pb_pkey_data;               // value of primary-key of current record
} fpi_t;



/*
 *	Used to identify record to be locked by BDB
*/
typedef struct {
	int              f;                          // file-descriptor of primary-db (as determined by BDB)
	char             key_data[];                 // value of primary-key of row to be locked
} lock_sig_t;



struct __idx_file {
	cob_file_t      *cob_file;                   // corresponding file (SELECT/FD) in COBOL program
	char             fid_db[FILENAME_MAX];       // fully-pathed external root-name of DB
	int              cb_key_max;                 // size of largest key
	int              c_dset;                     // number of keys in DB - dset[c_dset]
	dset_t          *dset;                       // array of c_dset entries (malloc)

	// current state: 
	fpi_t            fpi;
	DBT              dbt_record;                 // record area
	char            *pb_record_bfr;              // malloc'd record w/space                   
	DBT              dbt_key;                    // key area 
	char            *pb_key_bfr;                 // malloc'd key w/space

	char            *key_p_w;                    // primary-key value of last record written

	DB_LOCK         *list_locks;                 // malloc'd list of locks currently held on this file
	int              c_locks;                    // count locks in list
	int              c_locks_max;                // no of locks for which there is space in list     
	lock_sig_t      *lock_signature;             // w-s allocated when file opened

#ifdef WITH_FILEIO_TRACE
	key_log_t key_trail[KEY_TRAIL_MAX];          // audit-trail of latest IO actions
#endif
};


/*
 * Most calls originate with COBOL client. The client passes
 * *cob_file; using cob_file->file we get idx_file directly.
 *
 * But BDB call-back method passes *DB containing the index/key 
 * of reference; we need to search a list of open files to
 * determine the corresponding idx_file. 
*/
static struct file_list_member {
	idx_file_t              *f_idx;
	struct file_list_member *next;
} *file_list = NULL;




static const char          *bdb_home = NULL;            // Base for BDB Environment ($DB_HOME)
static long                 bdb_cache_size;             // Environment cache size (Mb) (0 to use default from BDB)
static DB_ENV              *bdb_env;                    // BDB Environment
static u_int32_t            uniqid;                     // Unique id assigned by BDB to this process
static DBC                 *cursor = NULL;              // Global to facilitate abort/clean-up
static const char         **bdb_data_dir = NULL;        // NULL-terminated array of directories



#define MAKE_DBT(_dbt, _data, _size) \
	{ memset(&_dbt, 0, sizeof(DBT)); \
	  _dbt.data = _data; \
	  _dbt.size = _size; }


// DB Cursor operations

#define DBC_GET(_flags) \
	cursor->c_get(cursor, &f_idx->dbt_key, &f_idx->dbt_record, _flags)

#define CLOSE_CURSOR \
	if (cursor != NULL) {cursor->c_close(cursor); cursor = NULL;}

#define DBC_PRIMARY_DB(dbc) \
	dbc->bdb->f_idx->dset[0].bdb->db

#define DBC_IX(dbc) \
	dbc->bdb->ix_dset


#define THROW_EXC(exc) \
	{	cob_fileio_throw_exc(f, exc, COB_IO_CONTEXT_FILEIO_INDEXED); return(-1); }


// Return value from BDB functions is either: 
// LINUX errno 1..256     BDB errno -30,800 to -30,999
#define THROW_EXC_BDB(exc, errno) \
	{	cob_fileio_throw_ext(f, _bdb_map_errno(errno, exc), COB_IO_CONTEXT_FILEIO_INDEXED \
			, COB_IO_REALM_BDB, (errno < 0) ? -(errno + 30799) : errno, db_strerror(errno)); \
		return(-1); \
	}

// LINUX errno 1..256
#define THROW_EXC_OS(exc, errno) \
	{	cob_fileio_throw_ext(f, _bdb_map_errno(errno, exc), COB_IO_CONTEXT_FILEIO_INDEXED \
			, COB_IO_REALM_OS, errno, strerror(errno)); \
		return(-1); \
	}

#define CC_THROW_EXC(exc) \
	{	if (cursor != NULL) {cursor->c_close(cursor); cursor = NULL;} \
		THROW_EXC(exc); \
	}

#define CC_THROW_EXC_BDB(exc, errno) \
	{	if (cursor != NULL) {cursor->c_close(cursor); cursor = NULL;} \
		THROW_EXC_BDB(exc, errno); \
	}







static int _bdb_open(
	  cob_file_t *f
	, const int mode); 

static idx_file_t *_bdb_get_handle(cob_file_t *f);

static void _bdb_set_key_descriptors(
	  idx_file_t *f_idx
	, dset_t *keys);

static void _bdb_free_handle(cob_file_t *f);

static int _bdb_join_environment(char *bdb_home);

static int _bdb_db_exists(
	  char *ret_filename
	, char *filename);

static void _bdb_get_cobol_key_descriptors(
	  cob_file_t *f
	, dset_t **keys_ret
	, int *c_keys_ret);

static int _bdb_get_bdb_key_descriptors(
	  idx_file_t *f_idx
	, dset_t **keys_ret
	, int *c_keys);

static char *_bdb_read_next_line(
	  char *pb
	, FILE *f_dict
	, char *line);

static int _bdb_create_key_dict(
	  idx_file_t *f_idx);

static int _bdb_match_keys(
	  cob_file_t *f
	, dset_t *keys
	, int c_keys);

static int _bdb_extract_key(
	  BDB *sdb
	, const DBT *primary_key
	, const DBT *record
	, DBT *secondary_key);

static void _bdb_create_fpi(idx_file_t *f_idx);

static void _bdb_destroy_fpi(fpi_t *fpi);

static void _bdb_set_fpi_key(
	  fpi_t *fpi
	, int ix_dset
	, DBT dbt_key);

static void _bdb_set_fpi_primary_key(
	  idx_file_t *f_idx
	, char *pb_record);


static int _bdb_compose_key(
	  dset_t *key
	, const void *pb_rec
	, char *pb_key);

static int _bdb_key_is_sparse(
	  dset_t *key
	, char *pb_key_value);

static int _bdb_get_key_ix(
	  idx_file_t *f_idx
	, cob_field *key_cobol);

static int _bdb_select_record(
	  cob_file_t *f
	, const int cond
	, cob_field *key
	, const int opt);

static int _bdb_get_current_record(
	  idx_file_t *f_idx
	, int direction
	, int *tf_got_next);


static int _bdb_lock_record(
	  cob_file_t *f
	, int cob_lock);

static int _bdb_lock(
	  idx_file_t *f_idx
	, char *pb_primary_key
	, int tf_wait_on_lock
	, DB_LOCK *ret_lock);

static int _bdb_unlock_all(void);

static int _bdb_unlock_records(idx_file_t *f_idx);

static int _bdb_unlock(DB_LOCK *db_lock);

static int _bdb_delete_dbs(char *fid_db);

static int _bdb_map_errno(
	  int errnum
	, int erc_generic);



#ifdef WITH_FILEIO_TRACE

// Assist funcs for trace/diagnostics


static char *_bdb_lock_str(DB_LOCK *lock);

static void _bdb_log_key(
	  idx_file_t *f_idx
	, int ix_dset
	, char *pb_primary_key
	, char *pb_active_key
	, key_log_t *log_key);

static char *_bdb_dump_file_description(cob_file_t *f, int tf_show_counts);

#endif



#ifdef WITH_INDEXED_BDB_1


static int db_create(
	  BDB **db_ret
	, DB_ENV *env
	, u_int32_t flags);

static int db_env_create(
	  DB_ENV **env_ret
	, u_int32_t flags);

static char *db_strerror(int errnum); 



#endif


/*
 * Called once at program BOJ: initialise variables.
 *
 * Environmental variables referenced [default]:
 * DB_HOME ... names BDB Environment directory to use [NULL]
 * DB_CACHE .. size (Mb) of cache requested in DB Environment [BDB default]
 *
 * Hierarchy determining size of BDB cache (cb_cache):
 * 1. if env-variable COB_BDB_CACHE_SIZE != 0
 *    ... cb_cache = $COB_BDB_CACHE_SIZE Mb
 * 2. if env-variable COB_BDB_CACHE_SIZE == 0
 *    ... cb_cache = default as determined by BDB
 * 3. otherwise
 *    ... cb_cache = ENV_CACHE_SIZE Mb
*/

int cob_fileio_isam_initialise() 
{
	int res = 0;
	char *s;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_initialise()\n", me);
#endif

	_bdb_join_environment(getenv("DB_HOME"));
	if ((s = getenv("COB_BDB_CACHE_SIZE")) != NULL) {
		bdb_cache_size = atoi(s);
		if (bdb_cache_size < 0) bdb_cache_size = 0;  // sanity check: use BDB default
	} else {
		bdb_cache_size = ENV_CACHE_SIZE;
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1) {
		fprintf(stderr, "%s: bdb_cache_size=%ld\n", me, bdb_cache_size);
		fprintf(stderr, "%s: exit cob_fileio_isam_initialise() res=%d\n", me, res);
	}
#endif

	return(res);
}





/*
 * Called once at program EOJ: release resources (if any allocated).
 *
*/

int cob_fileio_isam_terminate()
{


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_terminate()\n", me);
#endif

	if (bdb_env != NULL) {
		_bdb_unlock_all();
 		bdb_env->lock_id_free(bdb_env, uniqid);
 		bdb_env->close(bdb_env, 0);
	}
	return(0);
}







/*
 * Open the BSB DB-s that comprise the dataset.
 * This function is a wrapper to ensure resources are released if 
 * file-open fails.
 * 
*/

int cob_fileio_isam_open(cob_file_t *f
                       , const int mode)
{
	int fs;
	struct file_list_member *flm;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_open(%s open_mode=%d) share_mode=%d lock_mode=%d\n"
		              , me, f->select_name, mode, f->share_mode, f->lock_mode);
#endif


	fs = _bdb_open(f, mode);
	if (fs != 0) {
		cob_fileio_isam_close(f, 0);
	} else {
		// Add this file to our list of open files
		flm = cob_malloc(sizeof(struct file_list_member));
		flm->f_idx = f->file;
		flm->next = file_list;
		file_list = flm;
	}
	return(fs);
}




/*
 *	Open the BDB DB-s that comprise the dataset.
 *
 *	Memory may be malloc'd for the file handle.
 *	This function is wrapped to ensure resources are released if file-open fails.
 *	The root DB and all the related DB-s (1 per index/key) are opened.
 *
 *	If the DB files don't exist:
 *		INPUT:      if f->flag_optional --> COB_IOEXC_OK_NOFILE
 *		            else                --> COB_IOEXC_FILE_MISSING
 *		I-O      @  if f->flag_optional --> COB_IOEXC_OK_NOFILE
 *		            else                --> COB_IOEXC_FILE_MISSING
 *		OUTPUT:  @  
 *
 * 	@ File is created. Any existing dataset is overwritten (without first opening it).#
 *
 *	If an index can't be found to match key in COBOL app: COB_IOEXC_ISAM_NINDEX
 */

static int _bdb_open(
	  cob_file_t *f
	, const int mode) 
{
	int res, flags, ix_dset;
	int tf_exists_db = 0, tf_persist_key_dict = 0;
	char fid[FILENAME_MAX];
	idx_file_t *f_idx;
	dset_t *keys;
        struct stat st;
 
	f_idx = _bdb_get_handle(f);
	tf_exists_db = _bdb_db_exists(f_idx->fid_db, f->fid);
	flags = 0;

	switch(mode) {
	case COB_OPEN_INPUT:
		if (!tf_exists_db) { 
			if (!f->flag_optional) 
				THROW_EXC(COB_IOEXC_FILE_MISSING);
			f->tf_optional_is_missing = 1;
		}
		flags |= DB_RDONLY;
		break;
	case COB_OPEN_OUTPUT:
  		if (tf_exists_db) {
			if (0 != (res = _bdb_delete_dbs(f_idx->fid_db)))
				THROW_EXC_BDB(COB_IOEXC_ISAM_DROP, res);
			tf_exists_db = 0;
		}
		flags |= DB_CREATE;
		break;
	case COB_OPEN_I_O:			// fall thru
	case COB_OPEN_EXTEND:
		if (!tf_exists_db) {
			if (!f->flag_optional) 
				THROW_EXC(COB_IOEXC_FILE_MISSING);
			f->tf_optional_was_created = 1;
		}
		flags |= DB_READWRITE;
		break;
	}
	if (!tf_exists_db) {
		// For a new FILE we will write a key-dict (later) based on COBOL 
		_bdb_get_cobol_key_descriptors(f, &keys, &f_idx->c_dset); 
		tf_persist_key_dict = 1;
	} else {
	    //  For an existing BDB we can provide flexibility with key
		//  declarations in COBOL source - but this requires a key dictionary.
		if (0 != _bdb_get_bdb_key_descriptors(f_idx, &keys, &f_idx->c_dset)) {
			_bdb_get_cobol_key_descriptors(f, &keys, &f_idx->c_dset); 
			tf_persist_key_dict = 1;
		} else {
			res = _bdb_match_keys(f, keys, f_idx->c_dset);
			if (res == -1) {
#ifdef WITH_FILEIO_TRACE
				if (trace_level > 3)
					fprintf(stderr, "%s: failed to get key descriptors from dictionary\n", me);
#endif
				THROW_EXC(COB_IOEXC_ISAM_BAD_DICT);
			}
			if (res == 1) {
				/*
				 * Only the COBOL primary-key [0] is mandated to match isam-handler.
				 * Missing/mismatched COBOL secondary keys set DSET[n].cob_field_key = NULL.
				 * This defers f-status errors from OPEN to 1st START/READ which throws: COB_IOEXC_ISAM_NINDEX.
				 */
				if (keys->cob_field_key == NULL) {
#ifdef WITH_FILEIO_TRACE
					if (trace_level > 2)
						fprintf(stderr, "%s: primary key in COBOL declaration not indexed\n", me);
#endif
					THROW_EXC(COB_IOEXC_ISAM_NINDEX);
				}
			}
		}
	}
	_bdb_set_key_descriptors(f_idx, keys);

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 4) {
		char *pb;
		fprintf(stderr, "BDB-ISAM FILE @ OPEN: %s\n", pb = _bdb_dump_file_description(f, 0));
		free(pb);
	}
#endif

	if (f->tf_optional_is_missing)
		return(0);

	// open DB managing primary-key
	if (0 != (res = db_create(&PDB, bdb_env, 0)))
		THROW_EXC_BDB(COB_IOEXC_ISAM_CREATE, res);

#ifdef WITH_INDEXED_BDB_1
	// provide reverse references for BDB I functions
	PDB->f_idx = f_idx;
	PDB->ix_dset = 0;
#endif	

	if (0 != (res = PDB->open(PDB, NULL, f_idx->fid_db, NULL
						    , DB_BTREE, flags, COB_FILE_MODE)))
		THROW_EXC_BDB(COB_IOEXC_ISAM_OPEN, res);

	// check if file can be shared
	PDB->fd(PDB, &f->fileuid.fildes); 
        f->fileuid.inode = (fstat(f->fileuid.fildes, &st) == 0) ? st.st_ino : -1;
   	if (0 != cob_fileio_sharing_open_file(f, mode)) {
		THROW_EXC(COB_IOEXC_FSHARE_LOCK);  
	}
	f_idx->lock_signature->f = f->fileuid.fildes;

	// open each secondary db and associate with primary db
	for (ix_dset = 1; ix_dset < f_idx->c_dset; ix_dset++) {
		BDB_I(ix_dset) = NULL;
		sprintf(fid, "%s.%d", f_idx->fid_db, ix_dset);
		if (0 != (res = db_create(&BDB_I(ix_dset), bdb_env, 0))) 
			THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);

#ifdef WITH_INDEXED_BDB_1
			BDB_I(ix_dset)->f_idx = f_idx;
			BDB_I(ix_dset)->ix_dset = ix_dset;
#endif	

		if (DSET_I(ix_dset).tf_duplicates) 
			BDB_I(ix_dset)->set_flags(BDB_I(ix_dset), DB_DUP);
		if (0 != (res = BDB_I(ix_dset)->open(BDB_I(ix_dset), NULL, fid, NULL
			                            , DB_BTREE, flags, COB_FILE_MODE)))
			THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
		if (0 != (res = PDB->associate(PDB, NULL, BDB_I(ix_dset), _bdb_extract_key, 0))) 
			THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	}
	if (tf_persist_key_dict)
		_bdb_create_key_dict(f_idx);

	if (mode == COB_OPEN_EXTEND) {
		// ANS85: fpi -> after last logical record
		f->tf_beyond_eof = 1;
	} else {
		f->tf_beyond_bof = 1;
	}
	f_idx->fpi.tf_is_set = 1;
	return(0);
}






/*
 *  Release all resources associated with file.
*/

int cob_fileio_isam_close(cob_file_t *f
                        , const int opt)
{
	int ix_dset;
	idx_file_t *f_idx = f->file;
	struct file_list_member *flm_this, *flm_prior;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1) {
		fprintf(stderr, "%s: cob_fileio_isam_close(%s opt=%d)\n"
		              , me, f->select_name, opt);
		if (trace_level > 4) {
			char *pb;
			fprintf(stderr, "BDB-ISAM FILE @ CLOSE: %s\n", pb = _bdb_dump_file_description(f, 1));
			free(pb);
		}
	}
#endif

	_bdb_unlock_records(f->file);
	if ((f_idx != NULL) && (f_idx->dset != NULL)) {
		for (ix_dset = f_idx->c_dset - 1; ix_dset >= 0; --ix_dset) {
			if (BDB_I(ix_dset) != NULL) {
				BDB_I(ix_dset)->close(BDB_I(ix_dset), 0);
				BDB_I(ix_dset) = NULL;
			}
		}
		_bdb_free_handle(f);

		// remove this file from the chain of open-files
		flm_prior = NULL;
		for (flm_this = file_list; flm_this != NULL; flm_this = flm_this->next) {
			if (flm_this->f_idx == f_idx) {
				if (flm_prior == NULL) {
					file_list = flm_this->next;
				} else {
					flm_prior->next = flm_this->next;
				}
				free(flm_this);
				break;
			}
			flm_prior = flm_this;
		}
	}
	cob_fileio_sharing_close_file(f); 
	f->open_mode = COB_OPEN_CLOSED;
	f->tf_is_locked = (opt == COB_CLOSE_LOCK);
	return(0);
}






/*
 *  Set the file position indicator to a selected record in the file.
 *
 *  BDB CURSOR supports positioning by:
 *     DB_FIRST, DB_LAST DB_NEXT DB_PREV DB_CURRENT DB_SET DB_SET_RANGE
 *
 *	The value of the key is extracted from the record-data.
 */


int cob_fileio_isam_start(cob_file_t *f
                        , const int cond
                        , cob_field *key)
{
	int res;

#ifdef  WITH_FILEIO_TRACE
	idx_file_t *f_idx = f->file;
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_start(%s cond=%d  key @ 0x%lx)\n"
		              , me, f->select_name, cond, (long)key);
#endif

	if ((f->lock_mode == COB_LOCK_AUTOMATIC) && !f->tf_lock_many) 
		_bdb_unlock_records(f->file);

	if (0 != (res = _bdb_select_record(f, cond, key, 0)))
		return(-1);

#ifdef WITH_FILEIO_TRACE
	_bdb_log_key(f_idx
	           , f_idx->fpi.ix_dset
	           , f_idx->fpi.pb_pkey_data
	           , f_idx->fpi.pb_key_data
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
	int res;
	idx_file_t *f_idx = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_read(%s opt=%d  key @ 0x%lx)\n"
		              , me, f->select_name, opt, (long)key);
#endif


	if ((f->lock_mode == COB_LOCK_AUTOMATIC) && !f->tf_lock_many)
		_bdb_unlock_records(f->file);

	if (0 != (res = _bdb_select_record(f, COB_EQ, key, opt))) 
		return(-1);
	if (0 != (res = _bdb_lock_record(f, opt))) 
		THROW_EXC_BDB(COB_IOEXC_REC_LOCKED, res);
	if (f->record_max > f_idx->dbt_record.size)
		memset(f->record->data, ' ', f->record_max);
	memcpy(f->record->data, f_idx->dbt_record.data, f_idx->dbt_record.size);
	if (f->record_size != NULL)
		cob_set_int(f->record_size, f_idx->dbt_record.size);

#ifdef WITH_FILEIO_TRACE
	_bdb_log_key(f_idx
	               , f_idx->fpi.ix_dset
	               , f_idx->fpi.pb_pkey_data
	               , f_idx->fpi.pb_key_data
	               , &f_idx->key_trail[KEY_TRAIL_READ]);
#endif
	return(0);
}







/*
 * Read the next record relative to the current-record (SEQUENTIAL READ)
 * and the options given.
*/

int cob_fileio_isam_read_next(
	  cob_file_t *f
	, const int opt) 
{
	idx_file_t *f_idx = f->file;
	int res, stat, mode, direction, ix_dset, tf_got_next;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_read_next(%s opt=%d)\n"
		              , me, f->select_name, opt);
#endif

	if (!f_idx->fpi.tf_is_set)
		CC_THROW_EXC(COB_IOEXC_NOREC);
	ix_dset = f_idx->fpi.ix_dset;
	if ((f->lock_mode == COB_LOCK_AUTOMATIC) && !f->tf_lock_many)
		_bdb_unlock_records(f->file);

	if (0 != (res = BDB_I(ix_dset)->cursor(BDB_I(ix_dset), NULL, &cursor, 0)))
		CC_THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	MAKE_DBT(f_idx->dbt_key, f_idx->pb_key_bfr, CB_KEY(ix_dset));

	stat = COB_IOEXC_R_XEOF;
	direction = opt & 0x0F;
	switch(direction) {
	case COB_READ_CURRENT:
		if (0 != (res = _bdb_get_current_record(f_idx, DB_CURRENT, &tf_got_next)))
			CC_THROW_EXC_BDB(COB_IOEXC_NOREC, res);
		mode = DB_CURRENT; 
		break;
	case COB_READ_NEXT:
		if (f->tf_beyond_eof)
			CC_THROW_EXC(COB_IOEXC_R_XEOF);
		if (f->tf_beyond_bof)
			mode = DB_FIRST;
		else {
			if (0 != (res = _bdb_get_current_record(f_idx, DB_NEXT, &tf_got_next)))
				CC_THROW_EXC_BDB(COB_IOEXC_R_XEOF, res);
			if (f->tf_started && f->tf_is_first_read)
				mode = DB_CURRENT;
			else
				mode = tf_got_next ? DB_CURRENT : DB_NEXT;
		}
		break;
	case COB_READ_PREVIOUS:
		if (f->tf_beyond_bof)
			CC_THROW_EXC(COB_IOEXC_R_XBOF);
		if (f->tf_beyond_eof)
			mode = DB_LAST;
		else {
			if (0 != (res = _bdb_get_current_record(f_idx, DB_PREV, &tf_got_next)))
				CC_THROW_EXC_BDB(COB_IOEXC_R_XEOF, res);
			if (f->tf_started && f->tf_is_first_read) 
				mode = DB_CURRENT;
			else 
				mode =  tf_got_next ? DB_CURRENT : DB_PREV;
		}
		break;
	case COB_READ_FIRST:
		mode =  DB_FIRST;
		break;
	case COB_READ_LAST:
		mode =  DB_LAST;
		break;
	default:
		mode = DB_SET; 
		stat = COB_IOEXC_NOREC;
		_bdb_compose_key(&DSET_I(ix_dset), f->record->data, f_idx->dbt_key.data);
		break;
	}
	MAKE_DBT(f_idx->dbt_record, f->record->data, f->record_max);
	res = DBC_GET(mode);
	if (res != 0) 
		CC_THROW_EXC_BDB(stat, res);
	if (0 != (res = _bdb_lock_record(f, opt))) 
		CC_THROW_EXC_BDB(COB_IOEXC_REC_LOCKED, res);
	if (f->record_max > f_idx->dbt_record.size)
		memset(f->record->data, ' ', f->record_max);
	memcpy(f->record->data, f_idx->dbt_record.data, f_idx->dbt_record.size);
	if (f->record_size != NULL)
		cob_set_int(f->record_size, f_idx->dbt_record.size);
        
	_bdb_set_fpi_key(&f_idx->fpi, ix_dset, f_idx->dbt_key);
	_bdb_set_fpi_primary_key(f_idx, (char *)f->record->data);

#ifdef WITH_FILEIO_TRACE
	_bdb_log_key(f_idx
	            , f_idx->fpi.ix_dset
                , f_idx->fpi.pb_pkey_data
                , f_idx->fpi.pb_key_data
                , &f_idx->key_trail[KEY_TRAIL_READ]);
#endif

	CLOSE_CURSOR;
	return(0);
}




/*
 *  Write the file record. This adds a new row which is
 *  indexed by a unique primary-key and possibly secondary-keys
 *  which may be duplicated (as declared in file SELECT).
*/

int cob_fileio_isam_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	int res;
	idx_file_t *f_idx = f->file;
	DB_LOCK db_lock;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_write(%s, rsz=%d, opt=%d)\n"
		              , me, f->select_name, cb_rec, opt);
#endif

	// Because DB files have been "associated", a simple update
	// via the primary-dset is all that's required.
	MAKE_DBT(f_idx->dbt_key, f_idx->pb_key_bfr, CB_KEY(0));
	_bdb_compose_key(&PDSET, (char *)f->record->data, f_idx->dbt_key.data);
	MAKE_DBT(f_idx->dbt_record, f->record->data, cb_rec);
	if ((f->access_mode == COB_ACCESS_SEQUENTIAL)
		&& (-1 == memcmp(f_idx->dbt_key.data
		               , f_idx->key_p_w
		               , f_idx->dbt_key.size)))
		THROW_EXC(COB_IOEXC_ISAM_KEY_ASC);

	if (opt & COB_WRITE_LOCK) {
		if (0 != (res = _bdb_lock(f_idx, f_idx->dbt_key.data, 0, &db_lock))) {
			THROW_EXC_BDB(COB_IOEXC_REC_LOCKED, res);
		}
	}

	if (0 != (res = PDB->put(PDB, NULL, &f_idx->dbt_key, &f_idx->dbt_record, DB_NOOVERWRITE))) {
		if (opt & COB_WRITE_LOCK) {
			_bdb_unlock(&db_lock);
		}
		// BDB appears to return EINVAL if attempt made to add illegal duplicate key-value
		if (res == EINVAL) res = DB_KEYEXIST;
		THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	}
	memcpy(f_idx->key_p_w, f_idx->dbt_key.data, f_idx->dbt_key.size); 
	if (opt & COB_WRITE_LOCK) 
		f_idx->list_locks[f_idx->c_locks++] = db_lock;


#ifdef WITH_FILEIO_TRACE
	_bdb_log_key(f_idx, 0, f_idx->dbt_key.data, NULL, &f_idx->key_trail[KEY_TRAIL_WRITE]);
#endif

	return(0);
}





/*
 * Rewrite the file record identified by its primary-key.
 * The secondary-keys may have changed value. This replaces the
 * the row identified by its primary-key and reindexes the secondary-keys.
 * Rewrite doesn't change the fpi.
*/

int cob_fileio_isam_rewrite(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	int res;
	idx_file_t *f_idx = f->file;
	DB_LOCK db_lock;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_rewrite(%s, rsz=%d, opt=%d)\n"
		              , me, f->select_name, cb_rec, opt);
#endif


	MAKE_DBT(f_idx->dbt_key, f_idx->pb_key_bfr, CB_KEY(0));
	_bdb_compose_key(&PDSET, (char *)f->record->data, f_idx->dbt_key.data);
	if (f->access_mode == COB_ACCESS_SEQUENTIAL) {
		// check primary-key matches current (i.e. must rewrite prior read record)
	    res = memcmp(f_idx->fpi.pb_pkey_data, f_idx->dbt_key.data, CB_KEY(0));
		if (res != 0)
			THROW_EXC(COB_IOEXC_ISAM_KEY_ASC);
	}
	if (0 != (res = PDB->cursor(PDB, NULL, &cursor, 0))) {
		THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	}
	// read record using primary-key & rewrite it with new record-data
	if (0 != (res = DBC_GET(DB_SET))) 
		CC_THROW_EXC_BDB(COB_IOEXC_NOREC, res);

#ifdef IMPLEMENT_IX_FS_44
	// All ORGANIZATIONs length of new record must = record being replaced
	if (cb_rec != f_idx->dbt_record.size) {
#ifdef  WITH_FILEIO_TRACE
		if (trace_level > 3) {
			fprintf(stderr, "%s: illegal attempt to rewrite INDEXED record of different length\n", me);
			fprintf(stderr, "%s: ... Prior rec read = %d bytes. New record to write = %d bytes.\n"
			      , me, f_idx->dbt_record.size, cb_rec);
		}
#endif
		CC_THROW_EXC(COB_IOEXC_REWRITE_RSZ);	
	}
#endif


	memcpy(f_idx->pb_record_bfr, f_idx->dbt_record.data, f_idx->dbt_record.size);
	CLOSE_CURSOR;
	MAKE_DBT(f_idx->dbt_record, f->record->data, cb_rec);

	// N.B. we lock outside of the transaction
	if (0 != (res = _bdb_lock(f_idx, f_idx->dbt_key.data, 0, &db_lock)))
		THROW_EXC_BDB(COB_IOEXC_REC_LOCKED, res);

	if (0 != (res = PDB->put(PDB, NULL, &f_idx->dbt_key, &f_idx->dbt_record, 0))) {
		_bdb_unlock(&db_lock);
		// BDB appears to return EINVAL if attempt made to add illegal duplicate key-value
		if (res == EINVAL) res = DB_KEYEXIST;
		THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	}
	if (opt & COB_WRITE_LOCK) 
		f_idx->list_locks[f_idx->c_locks++] = db_lock;
	else
		_bdb_unlock(&db_lock);


#ifdef WITH_FILEIO_TRACE
	_bdb_log_key(f_idx, 0, f_idx->dbt_key.data, NULL, &f_idx->key_trail[KEY_TRAIL_REWRITE]);
#endif

	return(0);
}




/*
 *  Delete the record identified by its primary-key.
*/
int cob_fileio_isam_delete(cob_file_t *f)
{
	int res;
	idx_file_t *f_idx = f->file;
	DB_LOCK db_lock;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_delete(%s)\n"
		              , me, f->select_name);
#endif

	// Because DB files have been "associated", a simple delete
	// via the primary-dset is all that's required
	MAKE_DBT(f_idx->dbt_key, f_idx->pb_key_bfr, CB_KEY(0));
	_bdb_compose_key(&PDSET, (char *)f->record->data, f_idx->dbt_key.data);

	if (0 != (res = _bdb_lock(f_idx, f_idx->dbt_key.data, 0, &db_lock))) {
		THROW_EXC_BDB(COB_IOEXC_REC_LOCKED, res);
	}
	if (0 != (res = PDB->del(PDB, NULL, &f_idx->dbt_key, 0))) {
		THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	}
	_bdb_unlock(&db_lock);

#ifdef WITH_FILEIO_TRACE
	_bdb_log_key(f_idx, 0, f_idx->dbt_key.data, NULL, &f_idx->key_trail[KEY_TRAIL_DELETE]);
#endif

	return(0);
}





/*
 *	Flush the underlying files so that all current data is
 *	written to disk.
 *	BDB DB->sync() is called for each index.
 *	If the mode argument == COB_SYNC_PHYSICAL then 
 *	additionaly the file-stream under DB is flushed at fileio
 *	level.
 */

int cob_fileio_isam_sync(
	  cob_file_t *f
	, const int mode)
{
	idx_file_t *f_idx = f->file;
	int i, n;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_sync(%s mode=%d)\n"
		              , me, f->select_name, mode);
#endif

	for (i = 0; i < f_idx->c_dset; i++) {
		if (BDB_I(i)) {
			BDB_I(i)->sync(BDB_I(i), 0);
			if (mode == COB_SYNC_PHYSICAL) 
				fdcobsync(BDB_I(i)->fd (BDB_I(i), &n));
		}
	}
	return(0);
}




/*
 *	Release any/all locks held on a file.
 */

int cob_fileio_isam_unlock(cob_file_t *f)
{
	idx_file_t *f_idx = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_unlock(%s)\n"
		              , me, f->select_name);
#endif

	_bdb_unlock_records(f_idx);
	return(0);
}









/*
 *	f is an INDEXED file, not open. Using the filename in f,
 *	physically delete the files representing the index file.
 *	Each DB corresponding to each key is deleted.
 *	The key dictionary is deleted too.
 */ 

int cob_fileio_isam_erase(cob_file_t *f)
{
	int res;
	char root_name[FILENAME_MAX], fid[FILENAME_MAX];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_erase(%s)\n"
		              , me, f->select_name);
#endif

	cob_field_to_string(f->assign, root_name, FILENAME_MAX);
	cob_fileio_locate_file(root_name, root_name, FILENAME_MAX);
	if (_bdb_db_exists(fid, root_name)) { 
		res = _bdb_delete_dbs(fid);
		return(res);
	} else {
		THROW_EXC(COB_IOEXC_OK_NOFILE);
	}
}




/*
 *	Coin some info about myself in XML for fileio-stats.
 *	The pointer returned is malloc'd and should be free'd
 *	by the client. 
 */
char *cob_fileio_isam_stats_env(const char *indent)
{
	char *xml = cob_malloc(1000);
	char *pb = xml;

#if defined(DB_VERSION_FULL_STRING) && defined(DB_VERSION_STRING) 
	pb += sprintf(pb, "%s<isam_handler version=\"%s\" >\n", indent , DB_VERSION_STRING);
	pb += sprintf(pb, "%s\t%s\n", indent, DB_VERSION_FULL_STRING);
#else 
	pb += sprintf(pb, "%s<isam_handler version=\"%d.%d.%d\" >\n"
	            , indent, DB_VERSION_MAJOR, DB_VERSION_MINOR, DB_VERSION_PATCH);
#if defined(DB_VERSION_STRING)
	pb += sprintf(pb, "%s\t%s\n", indent, DB_VERSION_STRING);
#endif
#endif

	pb += sprintf(pb, "%s</isam_handler>\n", indent);

	pb += sprintf(pb, "%s<BDB_directory var=\"DB_HOME\" value=\"%s\" >\n"
	      , indent, getenv("DB_HOME"));
	pb += sprintf(pb, "%s\t%s\n", indent, bdb_home);
	pb += sprintf(pb, "%s</BDB_directory>\n", indent);

	pb += sprintf(pb, "%s<BDB_env_cache_size var=\"COB_BDB_CACHE_SIZE\" value=\"%s\" >\n"
	      , indent, getenv("COB_BDB_CACHE_SIZE"));
	pb += sprintf(pb, "%s\t%ld Mb\n", indent, bdb_cache_size);
	pb += sprintf(pb, "%s</BDB_env_cache_size>\n", indent);

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

	char *xml = cob_malloc(400);
    char *pb = xml;

	pb += sprintf(pb, "%s<primary_file_name> %s </primary_file_name>\n"
		      , indent, f_idx->fid_db);

	xml = realloc(xml, strlen(xml) + 1);
	return(xml);
}








/*
 *	P R I V A T E   F U N C T I O N S
 *	---------------------------------
 */



/*
 * Prepare idx_file_t for COBOL file f.
*/

static idx_file_t *_bdb_get_handle(cob_file_t *f)
{
	idx_file_t *f_idx;


#ifdef  WITH_FILEIO_TRACE
	int ix;
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_get_handle(%s)\n", me, f->select_name);
#endif

	f_idx = (idx_file_t *)cob_malloc(sizeof(idx_file_t));
	f_idx->c_dset = f->nkeys;

	// initialise DBT struct used to pass record-data to BDB
	f_idx->pb_record_bfr = cob_malloc(f->record_max);
	MAKE_DBT(f_idx->dbt_record, f_idx->pb_record_bfr, f->record_max);

	// storage for key info is malloc-d when we know details of keys
	f_idx->dset = NULL;
	f_idx->pb_key_bfr = NULL;
	f_idx->key_p_w = NULL;
	f->file = f_idx;
	f_idx->cob_file = f;

	// locks-list is malloc'd when needed
	f_idx->list_locks = NULL;
	f_idx->c_locks = f_idx->c_locks_max = 0;     


#ifdef WITH_FILEIO_TRACE
	for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) {
		f_idx->key_trail[ix].c_io = 0;
		f_idx->key_trail[ix].ix_dset = -1;
		f_idx->key_trail[ix].pb_pkey_data = NULL;
		f_idx->key_trail[ix].pb_skey_data = NULL;
		f_idx->key_trail[ix].time = time(NULL);
	}
#endif

	return(f_idx);
}




/*
 *	Set key info in f_idx from given keys[].
 *	Allocate memory to store current values of keys.
 */

static void _bdb_set_key_descriptors(
	  idx_file_t *f_idx
	, dset_t *keys)
{
	int ix_dset;
	dset_t *key;

#ifdef  WITH_FILEIO_TRACE
	int ix;
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_set_key_descriptors() %d indices\n", me, f_idx->c_dset);
#endif

	f_idx->dset = cob_malloc(sizeof(dset_t) * f_idx->c_dset);
	f_idx->cb_key_max = -1;
	key = keys;
	for (ix_dset = 0; ix_dset < f_idx->c_dset; ++ix_dset, ++key) {
		DSET_I(ix_dset) = *key;
		BDB_I(ix_dset) = NULL;
		if (f_idx->cb_key_max < key->cb_key) {
			f_idx->cb_key_max = key->cb_key;
		}
	}
	free(keys);
	f_idx->pb_key_bfr = (char *)cob_malloc(f_idx->cb_key_max);
	f_idx->key_p_w = (char *)cob_malloc(f_idx->cb_key_max);
	f_idx->lock_signature = (lock_sig_t *)cob_malloc(sizeof(int) + CB_KEY(0));
	_bdb_create_fpi(f_idx);


#ifdef WITH_FILEIO_TRACE
	for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) {
		f_idx->key_trail[ix].pb_pkey_data = (char *)cob_malloc(f_idx->cb_key_max);
		f_idx->key_trail[ix].pb_skey_data = (char *)cob_malloc(f_idx->cb_key_max);
	}
#endif

}



/*
 *	Free all memory allocated within struct f->file
 */

static void _bdb_free_handle(cob_file_t *f)
{
	idx_file_t *f_idx = f->file;

	if (f_idx == NULL) return;

#ifdef  WITH_FILEIO_TRACE
	int ix;
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_free_handle(%s)\n", me, f->select_name);
	for (ix = 0; ix < KEY_TRAIL_MAX; ++ix) { 
		free(f_idx->key_trail[ix].pb_pkey_data);
		free(f_idx->key_trail[ix].pb_skey_data);
	}
#endif

	if (f_idx->list_locks != NULL)
		free(f_idx->list_locks);

	_bdb_destroy_fpi(&f_idx->fpi);	
	if (f_idx->pb_record_bfr != NULL) {
		free(f_idx->pb_record_bfr);
		f_idx->pb_record_bfr = NULL;
	}
	if (f_idx->pb_key_bfr != NULL) {
		free(f_idx->pb_key_bfr);
		f_idx->pb_key_bfr = NULL;
	}
	if (f_idx->key_p_w != NULL) {
		free(f_idx->key_p_w);
		f_idx->key_p_w = NULL;
	}
	if (f_idx->lock_signature != NULL) {
		free(f_idx->lock_signature);
		f_idx->lock_signature = NULL;
	}
	if (f_idx->dset != NULL) {
		free(f_idx->dset);
		f_idx->dset = NULL;
	}

	free(f_idx);
	f->file = NULL;

}







/*
 *	Establish BDB environment in: bdb_env
 */


static int _bdb_join_environment(char *home)
{
	int flags, res, gb, b;

#ifdef  WITH_FILEIO_TRACE
	const char *pb_arg;
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_join_environment(bdb_home=%s)\n", me, home);
#endif

	bdb_env = NULL;
	bdb_home = home;
	res = db_env_create(&bdb_env, 0);
	if (res != 0) {
		cob_runtime_error("Can't join BDB environment \"%s\", db_env_create(): %d %s\n"
		                , home, res, db_strerror(res));
		cob_stop_run(1);
	}

	if (bdb_cache_size > 0) {
		// use bdb_cache_size Mb.
		// BDB takes arg1: Gbytes   and   arg2: bytes
		gb = bdb_cache_size / 1024;
		b = (bdb_cache_size % 1024) * 1024 * 1024;
		bdb_env->set_cachesize(bdb_env, gb, b, 0);
	}
	bdb_env->set_errfile(bdb_env, stderr);
	bdb_env->set_msgfile(bdb_env, stderr);
	bdb_env->set_alloc(bdb_env, cob_malloc, realloc, free);
	bdb_env->get_data_dirs(bdb_env, &bdb_data_dir);
	flags = DB_CREATE | DB_INIT_CDB | DB_INIT_MPOOL;
	res = bdb_env->open(bdb_env, bdb_home, flags, 0);
	if (res == EINVAL) {  		// 22 possible incompatible data-store
		if (0 == bdb_env->remove(bdb_env, bdb_home, 0)) {
			res = bdb_env->open(bdb_env, bdb_home, flags, 0);
		}
	}	
	if (res != 0) {
		cob_runtime_error("Can't join BDB environment, env_open: %d %s\n", res, db_strerror(res));
		bdb_env->close(bdb_env, 0);
		cob_stop_run(1);
		return(-1);
	}
	bdb_env->lock_id(bdb_env, &uniqid);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3) {
		fprintf(stderr, "%s: BDB environment:\n", me);
		bdb_env->get_home(bdb_env, &pb_arg);
		fprintf(stderr, "%s:    home dir: %s\n", me, pb_arg);
		fprintf(stderr, "%s:    data dir: %s\n", me, (bdb_data_dir == NULL) ? "NULL" : bdb_data_dir[0]);
		bdb_env->get_tmp_dir(bdb_env, &pb_arg);
		fprintf(stderr, "%s:     tmp dir: %s\n", me, pb_arg);
		fprintf(stderr, "%s:   locker-id: 0x%x\n", me, uniqid);
	}
#endif

	return(0);
}







/*
 *	Given the name of a BDB file, check if it exists.
 *
 *	The order of search for the physical file:
 *	1. Seek filename (only) if it is absolute.
 *	2. If a list of DB data directories has been supplied,
 *	   prepend each one in turn to filename; if the resulting
 *	   name is relative, prepend also the DB home directory name.
 *	   If the resulting filename matches an existing file, use it.
 *	3. Otherwise, prepend the DB home directory name to filename
 *	   and if the resulting filename matches an existing file,
 *	   use it.
 *	4. Finally, check for filename in the current-directory.
 *
 *	Returns 1 if a file can be found to match filename. The
 *	fully-pathed filename is returned in ret_filename.
 *
 *	Otherwise, returns 0 and filename is transcribed
 *	unchanged to ret_filename.
 *
*/
static int _bdb_db_exists(char *ret_filename, char *filename)
{
	int i, tf_exists = 0;
	struct stat st;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_db_exists(filename=%s)\n", me, filename);
#endif

	if (cob_fileio_is_absolute(filename)) {
		strcpy(ret_filename, filename);
		tf_exists = (stat(filename, &st) == 0);
		goto exit;
	}

	for (i = 0; bdb_data_dir && bdb_data_dir[i]; ++i) {
		if (cob_fileio_is_absolute((char *)bdb_data_dir[i]))
			sprintf(ret_filename, "%s/%s", bdb_data_dir[i], filename);
		else
			sprintf(ret_filename, "%s/%s/%s",
				  bdb_home, bdb_data_dir[i], filename);
		if ((tf_exists = (stat(ret_filename, &st) == 0)))
			goto exit;
	}
	if (i == 0) {
		sprintf (ret_filename, "%s/%s", bdb_home, filename);
		if ((tf_exists = (stat(ret_filename, &st) == 0)))
			goto exit;
	}
	strcpy(ret_filename, filename);
	tf_exists = (stat(ret_filename, &st) == 0);
	goto exit;

exit:

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: ... \"%s\" is %s\n"
		              , me, ret_filename, tf_exists ? "found" : "missing");
#endif

	return(tf_exists);
}




/*
 * Use key declarations from COBOL source to construct the key definitions.
 *
 * Returns 0 if successful.
 *     Pointer to the manufactured keys is returned in keys_ret
 *     which is an array of *c_keys_ret entries.
 * Returns -1 if unsuccessful.
 *
 */
static void _bdb_get_cobol_key_descriptors(
	  cob_file_t *f
	, dset_t **keys_ret
	, int *c_keys_ret)
{
	int ix_dset, ix_comp;
	cob_file_key_t *cob_key;
	dset_t *idx_key;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_get_cobol_key_descriptors(%s)\n", me, f->select_name);
#endif

	*c_keys_ret = f->nkeys;
	*keys_ret = (dset_t *)cob_malloc(sizeof(dset_t) * f->nkeys);
	for (ix_dset = 0, idx_key = *keys_ret, cob_key = f->keys;
         ix_dset < f->nkeys;
         ix_dset++, idx_key++, cob_key++)
	{
		idx_key->cob_field_key = cob_key->field;
		idx_key->tf_duplicates = cob_key->tf_duplicates;
		idx_key->tf_suppress = cob_key->tf_suppress;
		idx_key->ch_suppress = cob_key->char_suppress;
		idx_key->cb_key = cob_key->field->size;
		if (cob_key->count_components <= 1) {    // simple key - single field
			idx_key->c_comp = 1;
			idx_key->comp[0].rb = cob_key->offset;
			idx_key->comp[0].cb = cob_key->field->size;
		} else {                                 // composite (or "split") key  
			idx_key->c_comp = cob_key->count_components;
			for (ix_comp = 0; ix_comp < cob_key->count_components; ++ix_comp) {
				idx_key->comp[ix_comp].rb = cob_key->component[ix_comp]->data - f->record->data;
				idx_key->comp[ix_comp].cb = cob_key->component[ix_comp]->size;
			}
		}
	}
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
static int _bdb_get_bdb_key_descriptors(
	  idx_file_t *f_idx
	, dset_t  **keys_ret
	, int *pc_keys)
{
	int rb_comp, cb_comp, cb, c_keys;
	int ix_dset, ix_comp;
	char *pb, line[1001];
	char fid[FILENAME_MAX];
	dset_t *key;
	FILE *f_dict;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_get_bdb_key_descriptors(%s.dict)\n", me, f_idx->fid_db);
#endif

	*keys_ret = NULL;
	sprintf(fid, "%s.dict", f_idx->fid_db);
	if (NULL == (f_dict = fopen(fid, "r")))
		return(-1);
	/*
	 *   Key def format: c_keys\n key_0\n [key_1\n ... [key_n\n]]
	 *   Key format (for key of m components):
	 *        rb0.cb0[:rb1.cb1[... :rbm.cbm][_D]]
	 */
	if (NULL == (pb = _bdb_read_next_line(NULL, f_dict, line)))
		goto exit_error; 
	if (1 < sscanf(pb, "c_keys=%d%n", pc_keys, &cb))
		goto exit_error;
	pb += cb; 
	if (*pc_keys < 1)
		goto exit_error;
	c_keys = *pc_keys;
	key = (dset_t *)cob_malloc(sizeof(dset_t) * c_keys);
	*keys_ret = key;
	f_idx->c_dset = c_keys;
	for (ix_dset = 0; ix_dset < c_keys; ++ix_dset, ++key) {
		if (NULL == (pb = _bdb_read_next_line(pb, f_dict, line)))
			goto exit_error; 
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
	fclose(f_dict);
	return(0);

exit_error:
	fclose(f_dict);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: !!! invalid key dictionary. Current line: %s\n", me, line);
#endif

	return(-1);
}


/*
 * If pb is not NULL: check blank up to end-of-string.
 * Read characters from FILE stream f into buffer line.
 * Return a pointer to 1st non-empty char in line.
 * On EOF return NULL.
 */
static char *_bdb_read_next_line(
	  char *pb
	, FILE *f_dict
	, char *line) {
	static char whitespace[] = {' ', '\t', '\n', '\r', '\0'};
	if (pb != NULL) {
		for(; *pb != '\0'; ++pb) {
			if (NULL == strchr(whitespace, *pb))
				return(NULL);
		}
	}
	while(1) {
		if (NULL == fgets(line, 1000, f_dict))
			return(NULL);
		pb = line;
		while ((*pb != '\0') && (NULL != strchr(whitespace, *pb))) ++pb; 
		if ((*pb == '#') || (*pb == '\0'))
			continue;
		return(pb);
	}
}






/*
 * Using the keys stored in f_idx,
 * persist a key-dictionary.
 *
 */
static int _bdb_create_key_dict(idx_file_t *f_idx)
{
	int ix_dset, ix_comp;
	char fid[FILENAME_MAX];
	dset_t key;
	FILE *f_dict;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_create_key_dict(%s.dict)\n", me, f_idx->fid_db);
#endif

	sprintf(fid, "%s.dict", f_idx->fid_db);
	f_dict = fopen(fid, "w");
	fprintf(f_dict, "# FILE: %s => %s\n"
	              , f_idx->cob_file->select_name, f_idx->cob_file->fid);
	fprintf(f_dict, "c_keys=%d\n", f_idx->c_dset);
	for (ix_dset = 0; ix_dset < f_idx->c_dset; ++ix_dset) {
		key = DSET_I(ix_dset);
		fprintf(f_dict, "%d.%d", key.comp[0].rb, key.comp[0].cb);
		for (ix_comp = 1; ix_comp < key.c_comp; ++ix_comp) {
			fprintf(f_dict, ":%d.%d", key.comp[ix_comp].rb, key.comp[ix_comp].cb);
		} 
		if (key.tf_duplicates)
			fputs("_D", f_dict);
		fputs("\n", f_dict);
	}

#ifdef DEFFILEMODE 
	fchmod(fileno(f_dict), DEFFILEMODE);		// ensure all users have access to dict
#endif

	fclose(f_dict);
	return(0);
}


/*
 *	The keys have been loaded into f->keys from the COBOL SELECT.
 *	Check these keys are a subset of keys in the key-dictionary
 *	for this file [arg: keys]. The order of declaration is unimportant; all
 *	ordinal references passed to disam must be indirected via
 *	idx_key->cob_field_key.
 *	Keys for which there is no matching index get idx_key->cob_field_key = NULL. 
 *	Superfluous keys in the index are ignored.
 *  
 *	Returns:
 *		-1 encountered error.
 *		 0 if key found in ISAM for each key in COBOL SELECT
 *		 1 if COBOL SELECT references any key for which there is
 *          no matching index.
*/

static int _bdb_match_keys(
	  cob_file_t *f
	, dset_t *keys
	, int c_keys)
{
	int res, ix_key1, ix_key2, ix_comp;
	cob_file_key_t *cob_key;
	dset_t *idx_key;
	int tf_matched;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_match_keys(%s)\n", me, f->select_name);
#endif
	
	res = 0;
	for (ix_key1 = 0; ix_key1 < f->nkeys; ++ix_key1) {
		cob_key = f->keys+ix_key1;
		tf_matched = 0;
		for (ix_key2 = 0; ix_key2 < c_keys; ++ix_key2) {
			idx_key = keys + ix_key2;
			if (idx_key->cob_field_key != NULL) continue;
			if ((cob_key->field->size != idx_key->cb_key)
			   || (cob_key->tf_duplicates != idx_key->tf_duplicates))
				continue;
			if (cob_key->count_components <= 1) {    // simple key - single field
				if ((idx_key->c_comp != 1)
				   || (cob_key->offset != idx_key->comp[0].rb)
				   || (cob_key->field->size != idx_key->comp[0].cb))
					continue;
			} else {                                 // composite (or "split") key  
				if (cob_key->count_components != idx_key->c_comp)
					continue;
				for (ix_comp = 0; ix_comp < idx_key->c_comp; ++ix_comp) {
					if (((cob_key->component[ix_comp]->data - f->record->data) != idx_key->comp[ix_comp].rb)
					   || (cob_key->component[ix_comp]->size != idx_key->comp[ix_comp].cb))
						break;
				}
				if (ix_comp != idx_key->c_comp)
					continue;
			}

#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 3)
				fprintf(stderr, "%s: COBOL key %d [0x%lx] matches BDB key %d)\n"
				      , me, ix_key1, (long)cob_key->field, ix_key2);
#endif
	
			tf_matched = 1;
			idx_key->cob_field_key = cob_key->field;
			idx_key->tf_suppress = cob_key->tf_suppress;
			idx_key->ch_suppress = cob_key->char_suppress;
			break;
		}
		if (!tf_matched) res = 1;
	}
	return(res);
}






/*
 * Callback function for BDB associate().
 * Given a data record, extract the key-value for secondary-key
 * sdb and return it in secondary_key.
*/
int _bdb_extract_key(
	  BDB *sdb
	, const DBT *primary_key
	, const DBT *record
	, DBT *secondary_key)
{
	int ix_dset, res = 0;
	int tf_sdb_found = 0;
	idx_file_t	*f_idx;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_extract_key() BDB associate call-back\n", me);
#endif

	// map sdb => f_idx
	struct file_list_member *member = file_list;
	while(member != NULL) {
		f_idx = member->f_idx;
		for (ix_dset = 1; ix_dset < f_idx->c_dset; ++ix_dset) {
			if (BDB_I(ix_dset) == sdb) {
				tf_sdb_found = 1;
				break;
			}
		}
		if (tf_sdb_found) break;
		member = member->next;
	}
	if (tf_sdb_found) {
		// ensure call-back key buffer does NOT recycle memory between calls.
		// (If we refer to same bfr between consecutive calls BDB breaks.)
#ifdef WITH_INDEXED_BDB
		secondary_key->flags = DB_DBT_APPMALLOC;
#endif
		secondary_key->data = cob_malloc(CB_KEY(ix_dset));
		secondary_key->size = CB_KEY(ix_dset);
		_bdb_compose_key(&DSET_I(ix_dset), record->data, secondary_key->data);
		if (_bdb_key_is_sparse(&DSET_I(ix_dset), secondary_key->data)) {
			res = DB_DONOTINDEX;
		}
	} else {
		res = -1;
	}
	return(res);
}







/*
 * Allocate memory for the file-position-indicator.
*/
static void _bdb_create_fpi(idx_file_t *f_idx)
{
	f_idx->fpi.tf_is_set = 0;
	f_idx->fpi.ix_dset = 0;								// open using PRIMARY-KEY
	f_idx->fpi.pb_pkey_data = cob_malloc(CB_KEY(0));
	f_idx->fpi.pb_key_data = cob_malloc(f_idx->cb_key_max);
}


/*
 * Free memory used for the file-position-indicator.
*/
static void _bdb_destroy_fpi(fpi_t *fpi)
{
	if (fpi->pb_pkey_data != NULL) {
		free(fpi->pb_pkey_data);
		fpi->pb_pkey_data = NULL;
	}
	if (fpi->pb_key_data != NULL) {
		free(fpi->pb_key_data);
		fpi->pb_key_data = NULL;
	}
}




/*
 * Note the key-value used to establish the current fpi
*/
static void _bdb_set_fpi_key(
	  fpi_t *fpi
	, int ix_dset
	, DBT dbt_key)
{
	fpi->tf_is_set = 1;
	fpi->ix_dset = ix_dset;
	memcpy(fpi->pb_key_data, dbt_key.data, dbt_key.size);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_set_fpi_key() ix_dset=%d  akey=%s\n"
	          , me, ix_dset
		      , cob_fileio_fmtstr(dbt_key.data, dbt_key.size));
#endif
}



/*
 * Note the primary key-value of the current record
*/
static void _bdb_set_fpi_primary_key(
	  idx_file_t *f_idx
	, char *pb_record)
{
	_bdb_compose_key(&PDSET, pb_record, f_idx->fpi.pb_pkey_data);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_set_fpi_primary_key() pkey=%s\n"
	          , me
		      , cob_fileio_fmtstr(f_idx->fpi.pb_pkey_data, CB_KEY(0)));
#endif
}





/*
 * For the specified key, extract the key-value from the given data record,
 * using the offset:length of the (component parts) of the key.
 * The (composited) key-value is written to pb_key.
 */
static int _bdb_compose_key(
	  dset_t *key
	, const void *pb_rec
	, char *pb_key)
{
	int ix;
	char *pb_val = pb_key;

	for (ix = 0; ix < key->c_comp; ++ix) {
		memcpy(pb_val 
		     , pb_rec + key->comp[ix].rb
		     , key->comp[ix].cb);
		pb_val += key->comp[ix].cb; 
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_compose_key() -> %s\n", me, cob_fileio_fmtstr(pb_key, key->cb_key));
#endif
	return(0);
}





/*
 *	Return true if, for the given key:
 *		1.	Flag tf_suppress is true.
 *		2.	The given value is comprised entirely 
 *			of the character: key->ch_suppress.
 */
static int _bdb_key_is_sparse(
	  dset_t *key
	, char *pb_key_value)
{
	int cb;
	if (!key->tf_suppress)
		return(0);
	cb = key->cb_key;
	while (cb > 0) {
		if (*pb_key_value++ != key->ch_suppress) {
			return(0);
		}
		--cb;
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 5)
		fprintf(stderr, "%s: _bdb_key_is_sparse() -> true\n", me);
#endif
	return(1);
}
	



/*
 *	Given a pointer to a key in the struct cob_file_t (of the COBOL
 *	source program), find the corresponding key-descriptor in
 *	idx_file_t.
 *	Keys are considered as matched if their data-pointers are equal. This
 *	supports START KEY = <data-field-subordinate-to-a-key-but-aligned-on-left>.
 *
 *	On success: return the ordinal index to dset corresponding to the key.
 *	On failure: return -1.
 */
static int _bdb_get_key_ix(
	  idx_file_t *f_idx
	, cob_field *key_cobol)
{
	int ix_dset;
	int tf_found = 0;
	for (ix_dset = 0; ix_dset < f_idx->c_dset; ++ix_dset) {
		if ((DSET_I(ix_dset).cob_field_key != NULL)
			&& (DSET_I(ix_dset).cob_field_key->data == key_cobol->data)) {
			tf_found = 1;
			break;
		}
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_get_key_ix() -> %d\n", me, (tf_found ? ix_dset : -1));
#endif

	return(tf_found ? ix_dset : -1);
}




/*
 *	Read a record identified by its key and the comparitor cond.
 *	If successful: fpi is set to the record and 0 is returned.
 *	Otherwise: an exception is thrown and -1 returned.
 */
 

static int _bdb_select_record(
	  cob_file_t *f
	, const int cond
	, cob_field *key
	, const int opt)
{
	idx_file_t *f_idx = f->file;
	int res, ix_dset, cb_match, _cond;
	int tf_key_matches = 0;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_select_record(cond=%d  key @ 0x%lx)\n"
		              , me, cond, (long)key);
#endif

	ix_dset = _bdb_get_key_ix(f_idx, key);
	if (ix_dset == -1) {
		// There is no matching key-def in bdb datasets.
		// Deferred from COBOL OPEN, now return f-stat 9N
		THROW_EXC(COB_IOEXC_ISAM_NINDEX);
	}
	if (0 != (res = BDB_I(ix_dset)->cursor(BDB_I(ix_dset), NULL, &cursor, 0)))
		THROW_EXC_BDB(COB_IOEXC_ISAM_FAILED, res);
	
	MAKE_DBT(f_idx->dbt_key, f_idx->pb_key_bfr, CB_KEY(ix_dset));

	if (cond == COB_FI) {
		memset(f_idx->dbt_key.data, 0x00, f_idx->dbt_key.size);
                _cond = COB_GE;
		cb_match = f_idx->dbt_key.size;
        } else if (cond == COB_LA) {
		memset(f_idx->dbt_key.data, 0xff, f_idx->dbt_key.size);
                _cond = COB_LE;
		cb_match = f_idx->dbt_key.size;
        } else {
                _cond = cond;
		// Use size of data field; this may indicate a partial key  
		if ((key->size >= 1) && (key->size < DSET_I(ix_dset).cb_key))
			f_idx->dbt_key.size = key->size;
		cb_match = f_idx->dbt_key.size;
		_bdb_compose_key(&DSET_I(ix_dset), f->record->data, f_idx->dbt_key.data);
	}
	MAKE_DBT(f_idx->dbt_record, f_idx->pb_record_bfr, f->record_max);

	// Get the record in the database greater or equal to the given key-value.
	res = DBC_GET(DB_SET_RANGE);
	if (res == 0) 
		tf_key_matches = (0 == memcmp(f_idx->dbt_key.data, f_idx->pb_key_bfr, cb_match));

	switch(_cond) {
	case COB_EQ:
		res = ((res == 0) && tf_key_matches) ? 0 : DB_NOTFOUND;
		break;

	case COB_LT:	// fall-through
	case COB_LE:
		if (res != 0) {
			res = DBC_GET(DB_LAST);
		} else {
			if ((_cond == COB_LT) || !tf_key_matches) {
				res = DBC_GET(DB_PREV);
			}
		}
		if (res != 0) f->tf_beyond_bof = 1;
		break;

	case COB_GT:
		// skip until key NE given key-value
		while ((res == 0) && (0 == memcmp(f_idx->dbt_key.data, f_idx->pb_key_bfr, cb_match))) {
			res = DBC_GET(DB_NEXT);
		}
		if (res != 0) f->tf_beyond_eof = 1;
		break;

	case COB_GE:			 
		if (res != 0) f->tf_beyond_eof = 1;
		break;

	default:
		res = -1;
	}

	if (res != 0)
		CC_THROW_EXC(COB_IOEXC_NOREC);

	// set file-position-indicator (for READ-NEXT)
	_bdb_set_fpi_key(&f_idx->fpi, ix_dset, f_idx->dbt_key);
	_bdb_set_fpi_primary_key(f_idx, f_idx->dbt_record.data);
	CLOSE_CURSOR; 
	return(0);
}





/*
 *	Position the open cursor on the current record (as
 *	indicated by f_idx->fpi.pb_pkey_data).
 *	If the record matching the key has been deleted,
 *	move to the prior or next (depending on direction).
 * 
 *	Return 0 on success otherwise BDB return code.
 */

static int _bdb_get_current_record(
	  idx_file_t *f_idx
	, int direction
	, int *tf_got_next)
{
	int res;
	int tf_key_matches;
	DBT dbt_primary_key;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_get_current_record(dir=%s) ix_dset=%d  pkey=%s  akey=%s\n"
	          , me
		      , (direction == DB_PREV) ? "PREV" :
		        (direction == DB_NEXT) ? "NEXT" :
		        (direction == DB_CURRENT) ? "CURRENT" : "ILLEGAL"
		      , f_idx->fpi.ix_dset
		      , cob_fileio_strtohuman(f_idx->fpi.pb_pkey_data, CB_KEY(0), 0)
		      , cob_fileio_strtohuman(f_idx->fpi.pb_key_data, CB_KEY(f_idx->fpi.ix_dset), 1));
#endif

	MAKE_DBT(f_idx->dbt_key, f_idx->fpi.pb_key_data, CB_KEY(f_idx->fpi.ix_dset)); 
	MAKE_DBT(f_idx->dbt_record, f_idx->pb_record_bfr, f_idx->cob_file->record_max);

	// Get the record in the database greater or equal to the current key.
	if (DSET_I(f_idx->fpi.ix_dset).tf_duplicates) {
		// to read the current duplicate, supply duplicate-key value & primary-key-value
		MAKE_DBT(dbt_primary_key, f_idx->fpi.pb_pkey_data, CB_KEY(0));
		res = cursor->c_pget(cursor, &f_idx->dbt_key, &dbt_primary_key, &f_idx->dbt_record, DB_GET_BOTH);
	} else {
		res = DBC_GET(DB_SET_RANGE);
	}
	*tf_got_next = 0;
	if (res == 0) 
		tf_key_matches = (0 == memcmp(f_idx->dbt_key.data, f_idx->fpi.pb_key_data, f_idx->dbt_key.size));
	if ((res == 0) && tf_key_matches)
		return(0);
	if (direction == DB_CURRENT) 
		return(-1);
	if (direction == DB_PREV) 
		res = DBC_GET(DB_PREV);
	if (res == 0) {
		*tf_got_next = 1;
	}
	return(res);
}




/*
 *	Check the lock-mode for file f and,
 *	if warranted, take a lock as indicated by cob_lock.
 *
 *	The options in cob_lock:
 *		COB_READ_LOCK
 *		COB_READ_NO_LOCK
 *		COB_READ_WAIT_LOCK
 *		COB_READ_IGNORE_LOCK
 *	are mutually exclusive (although bit-masked values).
 *	If successful: the lock is added to the list of locks
 *	on the file.
 *	Return 0 on success otherwise BDB return code.
 */

static int _bdb_lock_record(
	  cob_file_t *f
	, int cob_lock) 
{
#ifdef WITH_INDEXED_BDB_1
	return(0);
#endif

	int res;
	idx_file_t *f_idx = f->file;
	DB_LOCK db_lock;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_lock_record()\n", me);
#endif

	if (f->open_mode == COB_OPEN_INPUT) {
		// only files opened for writing may lock
		return(0);
	}
	if (f->lock_mode == COB_LOCK_EXCLUSIVE) {
		// the entire file is locked - ignore any record locking
		return(0);
	}
	if (cob_lock & COB_READ_IGNORE_LOCK) {
		return(0);
	}
	_bdb_compose_key(&PDSET, f_idx->dbt_record.data, f_idx->pb_key_bfr);
	if (f->lock_mode == COB_LOCK_MANUAL) {
		if (cob_lock & COB_READ_LOCK) 
			res = _bdb_lock(f_idx, f_idx->pb_key_bfr, 0, &db_lock);
		else if (cob_lock & COB_READ_WAIT_LOCK) 
			res = _bdb_lock(f_idx, f_idx->pb_key_bfr, 1, &db_lock);
		else return(0);
	} else if (f->lock_mode == COB_LOCK_AUTOMATIC) {
		res = _bdb_lock(f_idx, f_idx->pb_key_bfr, 1, &db_lock);
	} else return(0);

	if (res != 0) return(res);

	// check if heap of locks already full
	if (f_idx->c_locks == f_idx->c_locks_max) {
		f_idx->c_locks_max += C_LOCKS_GRANULARITY;
		if (f_idx->list_locks != NULL) 
			f_idx->list_locks = realloc(f_idx->list_locks, f_idx->c_locks_max * sizeof(DB_LOCK));
		else
			f_idx->list_locks = cob_malloc(f_idx->c_locks_max * sizeof(DB_LOCK));
	}
	f_idx->list_locks[f_idx->c_locks++] = db_lock;
	return(0);
}







/*
 *	Acquire a lock on a record in f_idx with stated key.
 *	The locking service supported by BDB is used.
 *	At this level, locks are implemented independently of
 *	the associated file-data.
 *	If successful returns 0.
 *	Otherwise returns the non-zero result-code from BDB. 
*/ 

static int _bdb_lock(
	  idx_file_t *f_idx
	, char *pb_primary_key
	, int tf_wait_on_lock
	, DB_LOCK *ret_lock)
{
#ifdef WITH_INDEXED_BDB_1
	ret_lock->pad = 0;
	return(0);
#endif

	int res;
	DBT dbt;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_lock(wait=%d)\n", me, tf_wait_on_lock);
#endif

	MAKE_DBT(dbt, f_idx->lock_signature, sizeof(int) + CB_KEY(0)); 
	memcpy(f_idx->lock_signature->key_data, pb_primary_key, CB_KEY(0));
	res = bdb_env->lock_get(bdb_env
	                      , uniqid
	                      , tf_wait_on_lock ? 0 : DB_LOCK_NOWAIT 
	                      , &dbt
	                      , DB_LOCK_WRITE
	                      , ret_lock);
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: res=%d lock=0x%s)\n", me, res, _bdb_lock_str(ret_lock));
#endif
	return(res);

}




#if (1)

/*
	BCS/JR 1 May 2013 this appears to fail - temporarily unconditionally exclude
	Is it necessary to explicitly unlock when process termination is imminent?
*/

static int _bdb_unlock_all(void)
{
	return(0);
}

#else


/*
 *	Tell BDB to release all locks held for us.
 *	Return 0 on success otherwise BDB return code.
 */

static int _bdb_unlock_all(void)
{
	int res;
	DB_LOCKREQ lock_request[1];
	
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_unlock_all(x%x)\n", me, uniqid);
#endif

	memset(lock_request, '\0', sizeof(DB_LOCKREQ));
	lock_request[0].op = DB_LOCK_PUT_ALL;
	res = bdb_env->lock_vec(bdb_env, uniqid, 0, lock_request, 1, NULL);
	
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb_unlock_all(0x%x) -> %d\n", me, uniqid, res);
#endif
	
	return(res);
}

#endif		// exclusion









/*
 *	Release all the locks held on records in f_idx.
 *	Remove the lock from the lock-heap for f_idx.
 *	Return 0 on success otherwise BDB return code.
 */
static int _bdb_unlock_records(idx_file_t *f_idx)
{
#ifdef WITH_INDEXED_BDB_1
	return(0);
#endif

	int res1, res2 = 0;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_unlock_records()\n", me);
#endif
	while (f_idx->c_locks > 0) {
		--f_idx->c_locks;
		res1 = bdb_env->lock_put(bdb_env, f_idx->list_locks + f_idx->c_locks);
		if (res1 != 0) res2 = res1;
	}
	return(res2);
}



/*
 *	Release the lock indicated by db_lock
 *	Return 0 on success otherwise BDB return code.
 */
static int _bdb_unlock(DB_LOCK *db_lock)
{
#ifdef WITH_INDEXED_BDB_1
	return(0);
#endif
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb_unlock(0x%s)\n", me, _bdb_lock_str(db_lock));
#endif

	return(bdb_env->lock_put(bdb_env, db_lock));
}





/*
 *	Delete the files in the set <fid_db> <fid_db>.1 <fid_db>.2, etc.
 *	The key dictionary <fid_db>.dict is deleted too.
 *	Return 0 on success otherwise BDB return code.
 */ 

static int _bdb_delete_dbs(char *fid_db)
{
	int ix, res;
	char fid[FILENAME_MAX];
	struct stat st;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _bdb_delete_dbs(%s)\n", me, fid_db);
#endif

	sprintf(fid, "%s.dict", fid_db);
	unlink(fid);
	res = 0;
	// Cycle through all possible secondary key-files.
	// If BDB refuses to delete any existing <fid_db>.n then return.
	for (ix = 1; ix < MAX_SECONDARY_KEYS; ix++) {
		sprintf(fid, "%s.%d", fid_db, ix);
		if (0 == stat(fid, &st)) {
			if (0 != (res = bdb_env->dbremove(bdb_env, NULL, fid, NULL, 0))) {
				break;
			}
		}
	}
	if (res == 0) {
		if (0 == stat(fid_db, &st)) {
			res = bdb_env->dbremove(bdb_env, NULL, fid_db, NULL, 0);
		}
	}
	return(res);
}





/*
 *	For some OS errno we can determine a COBOL RTS error code.
 *	For the rest, we use the generic code supplied.
 */


static int _bdb_map_errno(
	  int errnum
	, int erc_generic)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _bdb_map_errno(errno=%d  dflt=%d)\n", me, errnum, erc_generic);
#endif

	switch(errnum) {
	case 0:
		return(0);
	case EPERM:
		return(COB_IOEXC_FILE_NPERM);
	case EACCES:
		return(COB_IOEXC_FILE_ACCESS);
	case EISDIR:
		return(COB_IOEXC_FILE_ISADIR);
	case ENOENT:
		return(COB_IOEXC_FILE_MISSING);
    case ESHARE:
		return(COB_IOEXC_FSHARE_LOCK);
	case DB_KEYEXIST:
		return(COB_IOEXC_ISAM_DUP);
	}
	return(erc_generic);
}





#ifdef WITH_FILEIO_TRACE

// Development + diagnostic aids

static char *_bdb_lock_str(DB_LOCK *lock) {
	int i;
	char *pb_bfr;
	unsigned char *pb_lock;
	static char *bfr = NULL;

	if (bfr == NULL) {
		bfr = cob_malloc(sizeof(DB_LOCK) * 3);
	}
	pb_bfr = bfr;
	pb_lock = (unsigned char *)lock;
	for (i = 0; i < sizeof(DB_LOCK); ++i, ++pb_lock, pb_bfr += 3) {
		sprintf(pb_bfr, "%2.2x ",  *pb_lock);
	}
	*pb_bfr = '\0';
	return(bfr);
}



static void _bdb_log_key(
	  idx_file_t *f_idx
	, int ix_dset
	, char *pb_primary_key
	, char *pb_active_key
	, key_log_t *log_entry)
{
	if (pb_active_key != NULL)
		ix_dset = -1;
	++log_entry->c_io;
	log_entry->ix_dset = ix_dset;
   	memcpy(log_entry->pb_pkey_data, pb_primary_key, CB_KEY(0));
	if (ix_dset > 0) 
   		memcpy(log_entry->pb_skey_data, pb_active_key, CB_KEY(ix_dset));
}





/*
 *	Return a human-readable description of index-file (current state).
 *	Space is malloc-d and should be freed by the client. 
 */
static char *_bdb_dump_file_description(
	  cob_file_t *f
	, int tf_show_counts) 
{
	int cb_space = 4000;
	int ix, ix_dset, ix_comp, cb_txt = 0;
	char txt[cb_space];
	char *pb;
	key_log_t klog;
	struct tm *tm;
	idx_file_t *f_idx = f->file;

	cb_txt += sprintf(txt, "INDEXED-FILE IMPLEMENTATION: Berkeley DB [%s]\n", DB_VERSION_STRING);
	cb_txt += sprintf(txt+cb_txt, "root-db-name: \"%s\"\n", f_idx->fid_db);
	cb_txt += sprintf(txt+cb_txt, "key-count = %d       max-key-size = %d       current-index = %d\n"
	               , f_idx->c_dset, f_idx->cb_key_max, f_idx->fpi.ix_dset);
	if (f_idx->pb_key_bfr == NULL) {
		cb_txt += sprintf(txt+cb_txt, "Keys not yet defined\n");

	} else {
		for(ix_dset = 0; ix_dset < f_idx->c_dset; ++ix_dset) {
			cb_txt += sprintf(txt+cb_txt, "KEY %d: COBOL x0%lx : %s : size = %db   fields :: "
			                , ix_dset
			                , (long)DSET_I(ix_dset).cob_field_key
							, DSET_I(ix_dset).tf_duplicates ? "DUPLICATES" : "UNIQUE"
		        	        , DSET_I(ix_dset).cb_key);
			for(ix_comp = 0; ix_comp < DSET_I(ix_dset).c_comp; ++ix_comp) {
				cb_txt += sprintf(txt+cb_txt, "%c%d.%d"
				                , (ix_comp == 0) ? ' ' : ':'
					            , DSET_I(ix_dset).comp[ix_comp].rb
					            , DSET_I(ix_dset).comp[ix_comp].cb);
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
					                , cob_fileio_fmtstr(klog.pb_pkey_data, PDSET.cb_key));
					if (klog.ix_dset > 0) {
						cb_txt += sprintf(txt+cb_txt, "%30s%.2d ::", " ", klog.ix_dset);
						cb_txt += sprintf(txt+cb_txt, "%s\n"
					                    , cob_fileio_fmtstr(klog.pb_skey_data, DSET_I(klog.ix_dset).cb_key));
					}
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
           







#ifdef WITH_INDEXED_BDB_1

/*
 *	From hereon the code relates to BDB pre 4.1.
 *	This code DOES NOT implement features introduced
 *	in BDB 4.1; rather it provides a 4.1 style api to
 *	the rest of this unit. Mainly it simply delegates
 *	to the earlier BDB libs but many of the 4.1 features are 
 *	simply voided. For example: record locking is unsupported.
 *
 *	All these functions are defined in BDB 4.1+. They all
 *	return 0 on success or errno on failure.
 *	In those functions receiving a DB_TXN *txn arg - it is
 *	always ignored.
 *
 *	DUPLICATE KEY HANDLING:
 *	BDB 4.1+ returns duplicate keys in the order in which
 *	they were added. BDB 1.8 returns them in an unspecified
 *	order. For each index which can contain duplicate keys:
 *	1.	There is a related serial number: irec.
 *	2.	Every key is suffixed with irec.
 *	3.	On each WRITE irec is incremented.
 *	4.	A (hidden) trailer record stores the current value
 *		of irec.
 */


static void _bdb1_bdb_init(BDB **bdb_ret);

static void _bdb1_db_env_init(DB_ENV  **db_env_ret);

static int _bdb1_check_keys(
	  BDB *bdb
	, DBT *dbt_key_p
	, DBT *dbt_new_record
	, int tf_rewrite
	, int *tf_ok);

static int _bdb1_prep_irec(
	  BDB *bdb
	, DBT *dbt_key
	, DBT *dbt_irec);

static int _bdb1_bump_irec(BDB *bdb);

static int _bdb1_isa_trailer(
	  BDB *bdb
	, DBT *dbt_key);

static void _bdb1_dbc_init(DBC **dbc_ret);

static int _bdb1_dbc_close(DBC *dbc);

static int _bdb1_dbc_create(
	  BDB *bdb
	, DBC **dbc_ret
	, u_int32_t flags);


/*
 *	This function is used to plug the jump table where the BDB II function
 *	is invoked but has no effect in BDB I.
 */
static int _bdb1_void()
{
	return(0);
}





//	DB_ENV functions


/*
 *	Create a new environment and initialise its fields.
 */
static int db_env_create(
	  DB_ENV **env_ret
	, u_int32_t flags)
{
	DB_ENV *db_env;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_create(flags=%d)\n", me, flags);
#endif

	_bdb1_db_env_init(&db_env);
	db_env->btreeinfo.flags = 0;
	db_env->btreeinfo.cachesize = 0;
	db_env->btreeinfo.maxkeypage = 0;
	db_env->btreeinfo.minkeypage = 0;
	db_env->btreeinfo.psize = 0;
	db_env->btreeinfo.compare = NULL;
	db_env->btreeinfo.prefix = NULL;
	db_env->btreeinfo.lorder = 0;
	*env_ret = db_env;
	return(0);
}


/*
 *	Close the environment, freeing any allocated storage.
 */

static int _bdb1_env_close(
	  DB_ENV *db_env
	, u_int32_t flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_close(flags=%d)\n", me, flags);
#endif

	if (db_env != NULL) {
		if (db_env->home != NULL) {
			free(db_env->home);
		}
		free(db_env);
	}
	return(0);
}



/*
 *	Remove a database. For our purposes, each physical file stores
 *	the index for a single key. We don't support multiple databases in
 *	the same physical file.
 *	<fid> is the fully pathed filename of the physical file.
 *	<database> is ignored.
 */
static int _bdb1_env_dbremove(
	  DB_ENV *db_env
	, DB_TXN *txn
	, const char *fid
	, const char *database
	, u_int32_t flags)
{
	int res = 0;
	char path[FILENAME_MAX];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_dbremove(fid=%s)\n", me, fid);
#endif
	if (_bdb_db_exists(path, (char *)fid)) {
		if (0 != unlink(path)) {
			res = errno;
		}
	} else {
		res = ENOENT;
	}
	return(res);
}

 


/*
 *	A void function.
 */
static int _bdb1_env_get_data_dirs(
	  DB_ENV *db_env
	, const char ***pb_dir_ret)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_get_data_dirs()\n", me);
#endif

	*pb_dir_ret = NULL;
	return(0);
}



/*
 *	Return the HOME for the environment.
 */
static int _bdb1_env_get_home(
	  DB_ENV *db_env
	, const char **ppb_home_ret)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_get_home()\n", me);
#endif

	*ppb_home_ret = db_env->home;
	return(0);
}





/*
 *	Return the pathed name of the directory used to store temporary files.
 */
static int _bdb1_env_get_tmp_dir(
	  DB_ENV *db_env
	, const char **ppb_tmp_dir_ret)
{
	static char *pb_tmp_dir = NULL;

	char fname[FILENAME_MAX];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_get_tmp_dir()\n", me);
#endif

	cob_fileio_get_dirtmp(fname);
	if (pb_tmp_dir == NULL) {
		pb_tmp_dir = (char *)cob_malloc(strlen(fname) + 1);
	} else {
		pb_tmp_dir = (char *)realloc(pb_tmp_dir, strlen(fname) + 1);
	}	
	strcpy(pb_tmp_dir, fname);
	*ppb_tmp_dir_ret = pb_tmp_dir;
	return(0);
}



/*
 *	Open the environment using the given HOME.
 *	Currently does nothing.
 */
static int _bdb1_env_open(
	  DB_ENV *db_env
	, const char *home
	, u_int32_t flags
	, int i)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_open()\n", me);
#endif
	if (home == NULL)
		home = "./";
	db_env->home = (char *)cob_malloc(strlen(home) + 1);
	strcpy(db_env->home, home);
	return(0);
}





/*
 *	Set the cache size to be used by BDB.
 */
static int _bdb1_env_set_cachesize(
	  DB_ENV *db_env
	, u_int32_t gbytes
	, u_int32_t bytes
	, int flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_env_set_cachesize(%dGb, %db)\n"
		      , me, gbytes, bytes);
#endif

	db_env->btreeinfo.cachesize = (gbytes * 1024 * 1024 * 1024) + bytes;
	return(0);
}


/*
 *	Set the stream BDB is to use for error reporting.
 *	Currently does nothing.
 */
static void _bdb1_env_set_errfile(
	  DB_ENV *db_env
	, FILE *f)
{
}


/*
 *	Set the stream BDB is to use for messages.
 *	Currently does nothing.
 */
static void _bdb1_env_set_msgfile(
	  DB_ENV *db_env
	, FILE *f)
{
}




/*
 *	Allocate memory for the BDB environment and initialise 
 *	it - particularly the function jump table.
 */
static void _bdb1_db_env_init(DB_ENV **env_ret)
{
	DB_ENV *db_env;
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb1_db_env_init()\n", me);
#endif
	db_env = (DB_ENV *)cob_malloc(sizeof(DB_ENV));
	db_env->home = NULL;

	db_env->close = &_bdb1_env_close;
	db_env->dbremove = &_bdb1_env_dbremove;
	db_env->get_data_dirs = &_bdb1_env_get_data_dirs;
	db_env->get_home = &_bdb1_env_get_home;
	db_env->get_tmp_dir = &_bdb1_env_get_tmp_dir;

	db_env->lock_get = &_bdb1_void;
	db_env->lock_id = &_bdb1_void;
	db_env->lock_id_free = &_bdb1_void;
	db_env->lock_put = &_bdb1_void;
	db_env->open = &_bdb1_env_open;
	db_env->remove = &_bdb1_void;
	db_env->set_alloc = &_bdb1_void;
	db_env->set_cachesize = &_bdb1_env_set_cachesize;
	db_env->set_errfile = &_bdb1_env_set_errfile;
	db_env->set_msgfile = &_bdb1_env_set_msgfile;

	*env_ret = db_env;
}








//	DB functions

/*
 *	Instantiate a new BDB database for either a primary or secondary
 *	key index. DB->open() is called before new DB is used.
 */
static int db_create(
	  BDB **bdb_ret
	, DB_ENV *env
	, u_int32_t flags)
{
	BDB *bdb;
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: db_create()\n", me);
#endif
	_bdb1_bdb_init(&bdb);
	*bdb_ret = bdb;
	return(0);
}






/*
 *	Given a BDB database for the primary index, associate it with a
 *	database for a secondary index.
 *	Association is the mechanism that allows us to automatically
 *	update secondary key indexes when receiving a single call to
 *	insert, update or delete the primary. This was a crucial feature
 *	introduced in later versions of BDB.
 */
static int _bdb1_db_associate(
	  BDB *bdb
	, DB_TXN *txn
	, BDB *bdb_secondary
	, int (*fn_callback)(BDB *, const DBT *, const DBT *, DBT *) 
	, u_int32_t flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_associate()\n", me);
#endif
	if (bdb->db_ass == NULL) {
		bdb->free_ass = 50;
		bdb->db_ass = (DB_ASSOCIATION *)cob_malloc(sizeof(DB_ASSOCIATION) * bdb->free_ass);
		bdb->next_ass = 0;
	} else if (bdb->free_ass == 0) {
		bdb->db_ass = (DB_ASSOCIATION *)realloc(bdb->db_ass, sizeof(DB_ASSOCIATION) * (bdb->next_ass + 50));
		bdb->free_ass = 50;
	}
	bdb->db_ass[bdb->next_ass].bdb = bdb_secondary;
	bdb->db_ass[bdb->next_ass].fn_callback = fn_callback;
	++bdb->next_ass;
	--bdb->free_ass;
	return(0);
}


/*
 *	Close a database freeing all allocated memory.
 */

static int _bdb1_db_close(
	  BDB *bdb
	, u_int32_t flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_close()\n", me);
#endif

	_bdb1_dbc_close(bdb->dbc);
	bdb->db->close(bdb->db);
	if (bdb->db_ass != NULL)
		free(bdb->db_ass);
	if (bdb->f_name != NULL)
		free(bdb->f_name);
	free(bdb);
	return(0);
}


/*
 *	Return a DBD cursor based on the given database.
 *	BDB Cursors where introduced in later versions of BDB.
 *	In BDB I we keep cursors open - return prepared DBC. 
 */
static int _bdb1_db_cursor(
	  BDB *bdb
	, DB_TXN *txn
	, DBC **dbc
	, u_int32_t flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_cursor()\n", me);
#endif
	*dbc = bdb->dbc;
	return(0);
}




/*
 *	Delete a record. A single call removes not only the key/record
 *	pair from the primary index but all the secondary keys for the
 *	the record in any ASSOCIATED indexes.
 */
static int _bdb1_db_del(
	  BDB *bdb
	, DB_TXN *txn
	, DBT *dbt_key_p
	, u_int32_t flags)
{
	int ix, res = 0;
	int cb_key_p;
	char *pb_key_p, *pb_key_s;
	dset_t *dset;
	DB_ASSOCIATION *ass;
	BDB *bdb_s;
	DB  *db_s;
	DBT _dbt_key_p;
	DBT _dbt_key_s;
	DBT _dbt_record;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_del(flags=0x%x)\n", me, flags);
#endif

	cb_key_p = dbt_key_p->size;
	pb_key_p = cob_malloc(cb_key_p);
	pb_key_s = cob_malloc(bdb->f_idx->cb_key_max);
	memcpy(pb_key_p, dbt_key_p->data, cb_key_p);
	if (bdb->db_ass != NULL) {
		// read the data record using primary key
		res = bdb->db->seq(bdb->db, dbt_key_p, &_dbt_record, R_CURSOR);
		for (ix = 0; (res == 0) && (ix < bdb->next_ass); ++ix) {
			ass = bdb->db_ass + ix;
			bdb_s = ass->bdb;
			db_s = bdb_s->db; 
			dset = &bdb_s->f_idx->dset[bdb_s->ix_dset];
			// extract the s-key value and delete it from the index 
			_bdb_compose_key(dset, _dbt_record.data, pb_key_s);
			MAKE_DBT(_dbt_key_p, pb_key_p, cb_key_p);
			MAKE_DBT(_dbt_key_s, pb_key_s, dset->cb_key);
			if (0 == (res = bdb_s->dbc->c_pget(bdb_s->dbc, &_dbt_key_s, &_dbt_key_p, &_dbt_record, DB_GET_BOTH))) {
				res = db_s->del(db_s, &_dbt_key_s, R_CURSOR);
				#ifdef  WITH_FILEIO_TRACE
					if (trace_level > 8)
						fprintf(stderr, "%s: S-KEY-%d DB->del :: %s  [res=%d]\n"
					    	  , me, ix, cob_fileio_fmtstr(pb_key_s, dset->cb_key), res);
				#endif
				db_s->sync(db_s, 0);
			}
		}
	}
	if (res == 0) {
		// delete record from primary db
		MAKE_DBT(_dbt_key_p, pb_key_p, cb_key_p);
		res = bdb->db->del(bdb->db, &_dbt_key_p, 0);
		#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 8)
				fprintf(stderr, "%s: P-KEY DB->del :: %s  [res=%d]\n"
				      , me, cob_fileio_fmtstr(pb_key_p, cb_key_p), res);
		#endif
		// If no sync then DBC don't see updates via DB->del()
		bdb->db->sync(bdb->db, 0);
	}
	if (res == RET_SPECIAL)	res = DB_NOTFOUND;
	free(pb_key_p);
	free(pb_key_s);
	return(res);
}





/*
 *	Return the underlying file-descriptor for a specified BDB database.
 */
static int _bdb1_db_fd(
	  BDB *bdb
	, int *fildes)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_fd()\n", me);
#endif
	*fildes = bdb->db->fd(bdb->db);
	return((*fildes < 0) ? -1 : 0);
}





/*
 *	After a BDB database (index) has been created, it may be opened.
 *	<f_name> is the pathed file name of the database file.
 *	<database> is ignored - we support 1 database per file.
 *	<type> is always DB_BTREE.
 *	<flags> is of type DB_CREATE, DB_READWRITE, etc.
 *	<mode> is of type LINUX file permissions (e.g. 666)
 */
static int _bdb1_db_open(
	  BDB  *bdb
	, DB_TXN *txn
	, const char *f_name
	, const char *database
	, DBTYPE type
	, u_int32_t flags
	, int mode)
{
	int res;
	char *pb;
	u_int32_t _flags;
	DBT dbt_key, dbt_irec;
	idx_file_t *f_idx = bdb->f_idx;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_open(flags=0x%x  mode=0x%x)\n"
		      , me, flags, mode);
#endif

	if (flags & DB_RDONLY) _flags = O_RDONLY;
	if (flags & DB_CREATE) _flags = O_RDWR | O_CREAT | O_TRUNC;
	if (flags & DB_READWRITE) _flags = O_RDWR | O_CREAT;

	BTREEINFO info = bdb_env->btreeinfo;
	if (bdb->flags & DB_DUP)
		info.flags |= R_DUP;
	bdb->db = dbopen(f_name, _flags, mode, type, &info);
	if (bdb->db == NULL)
		return(errno);
	if (bdb->f_name != NULL)
		free(bdb->f_name);
	bdb->f_name = (char *)cob_malloc(strlen(f_name) + 1);
	strcpy(bdb->f_name, f_name);
	bdb->tf_duplicates = DSET_I(bdb->ix_dset).tf_duplicates;
	if (bdb->tf_duplicates) {
		_bdb1_prep_irec(bdb, &dbt_key, &dbt_irec);
		pb = dbt_key.data;
		if (flags & DB_CREATE) {
			bdb->irec = 0;
			res = bdb->db->put(bdb->db, &dbt_key, &dbt_irec, 0);
		} else {
			if (0 == (res = bdb->db->get(bdb->db, &dbt_key, &dbt_irec, 0))) 
				bdb->irec = *(irec_t *)dbt_irec.data;
		}
		#ifdef WITH_FILEIO_TRACE
		if (trace_level > 8)
			fprintf(stderr, "%s: Index=%d Duplicate-key irec [res=%d] seed=%d\n"
			      , me, bdb->ix_dset, res, (int)bdb->irec);
		#endif
		free(pb);
		if (res != 0) {
			if (res == RET_SPECIAL)	res = DB_NOTFOUND;
			return(res);
		}	
	}
	// our cursor is opened and left open until DB is closed
	res = _bdb1_dbc_create(bdb, &bdb->dbc, 0);

	return(res);
}




/*
 *	Store a new record or re-store an existing one.
 *	A single call stores not only the key/record
 *	pair from the primary index but all the secondary keys for the
 *	the record in any ASSOCIATED indexes.
 *
 *	<dbt_key_p> is the primary key.
 *	<dbt_data> is the data record.
 *	<flags> DB_NOOVERWRITE indicates whether this is a 
 *	WRITE or REWRITE.
 */	

static int _bdb1_db_put(
	  BDB *bdb
	, DB_TXN *txn
	, DBT *dbt_key_p
	, DBT *dbt_data
	, u_int32_t flags)
{
	int ix, res = 0;
	int cb_key_p;
	int tf_ok = 0;
	int tf_rewrite;
	int tf_reindex_skeys;
	char *pb_cur_record;
	char *pb_key_p, *pb_key_1, *pb_key_2;
	irec_t irec;
	dset_t *dset;
	DB_ASSOCIATION *ass;
	BDB *bdb_s;
	DBT _dbt_key_p, _dbt_key_s;
	DBT dbt_old_record;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_put(flags=0x%x)\n", me, flags);
#endif

	tf_rewrite = !(flags & DB_NOOVERWRITE);
	// Check primary-key
	res = bdb->db->get(bdb->db, dbt_key_p, &dbt_old_record, 0);
	switch(res) {
		case 0:               // found
			if (!tf_rewrite) return(DB_KEYEXIST);
			break;
		case RET_SPECIAL:     // not-found
			if (tf_rewrite) return(DB_NOTFOUND);
			break;
		default:
			return(res);
	}
	// check all s-keys are acceptable before any updates done
	if (0 != (res = _bdb1_check_keys(bdb, dbt_key_p, dbt_data, tf_rewrite, &tf_ok)))
		return(res);
	if (!tf_ok) 
		return(DB_KEYEXIST);

	cb_key_p = dbt_key_p->size;
	pb_key_p = cob_malloc(cb_key_p);
	pb_key_1 = cob_malloc(bdb->f_idx->cb_key_max + sizeof(irec_t));
	pb_key_2 = cob_malloc(bdb->f_idx->cb_key_max + sizeof(irec_t));
	pb_cur_record = bdb->f_idx->pb_record_bfr;
	memcpy(pb_key_p, dbt_key_p->data, cb_key_p);
	tf_reindex_skeys = 1;
	if (tf_rewrite && (bdb->db_ass != NULL)) {
		tf_reindex_skeys = 0;
		// check if any s-key changed
		for (ix = 0; (res == 0) && (ix < bdb->next_ass); ++ix) {
			ass = bdb->db_ass + ix;
			bdb_s = ass->bdb;
			dset = &bdb_s->f_idx->dset[bdb_s->ix_dset];
			_bdb_compose_key(dset, pb_cur_record, pb_key_1);
			_bdb_compose_key(dset, dbt_data->data, pb_key_2);
			if (memcmp(pb_key_1, pb_key_2, dset->cb_key)) {
				tf_reindex_skeys = 1;
				break;
			}
		}
		if (tf_reindex_skeys) {
			// on REWRITE: if any s-key changed value then
			// delete existing record and insert new record.
			res = _bdb1_db_del(bdb, txn, dbt_key_p, 0);
		}
	}
	// store key_s + key_p in associated dbs (if any)
	if ((res == 0) && tf_reindex_skeys && (bdb->db_ass != NULL)) {
		for (ix = 0; (res == 0) && (ix < bdb->next_ass); ++ix) {
			ass = bdb->db_ass + ix;
			bdb_s = ass->bdb;
			dset = &bdb_s->f_idx->dset[bdb_s->ix_dset];
			_bdb_compose_key(dset, dbt_data->data, pb_key_2);
			if (_bdb_key_is_sparse(dset, pb_key_2)) 
				continue;
			if (bdb_s->tf_duplicates) {
				// Add suffix to key to make BDB vector in order of creation.
				// BDB ranks on key string value: ensure irec is ordered accordingly.
				#ifdef WORDS_BIGENDIAN
					irec = bdb_s->irec;
				#else
					irec = (sizeof(irec_t) == 4) ? COB_BSWAP_32(bdb_s->irec)
					                             : COB_BSWAP_64(bdb_s->irec);
				#endif
				memcpy(pb_key_2 + dset->cb_key, &irec, sizeof(irec_t));
				MAKE_DBT(_dbt_key_s, pb_key_2, dset->cb_key + sizeof(irec_t));
				_bdb1_bump_irec(bdb_s);
			} else {
				MAKE_DBT(_dbt_key_s, pb_key_2, dset->cb_key);
			}
			MAKE_DBT(_dbt_key_p, pb_key_p, cb_key_p);
			if (0 != (res = bdb_s->db->put(bdb_s->db, &_dbt_key_s, &_dbt_key_p, 0))) {
				res = (res == RET_SPECIAL) ? DB_KEYEXIST : errno;
			}
			#ifdef  WITH_FILEIO_TRACE
				if (trace_level > 8)
					fprintf(stderr, "%s: S-KEY-%d DB->put :: %s :: %s  [res=%d]\n"
					      , me, ix
					      , cob_fileio_strtohuman(_dbt_key_s.data, _dbt_key_s.size, 0)
					      , cob_fileio_strtohuman(pb_key_p, cb_key_p, 1)
					      , res);
			#endif
			bdb_s->db->sync(bdb_s->db, 0);
		}
	}
	if (res == 0) {
		MAKE_DBT(_dbt_key_p, pb_key_p, cb_key_p);
		// store record in primary db (overwriting if necessary)
		if (0 != (res = bdb->db->put(bdb->db, &_dbt_key_p, dbt_data, 0))) {
			res = (res == RET_SPECIAL) ? DB_KEYEXIST : errno;
		}
		#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 8)
				fprintf(stderr, "%s: P-KEY DB->put :: %s [res=%d]\n"
				      , me , cob_fileio_fmtstr(pb_key_p, cb_key_p), res);
		#endif
		// If no sync then DBC don't see updates via DB->put()
		bdb->db->sync(bdb->db, 0);
	}
	free(pb_key_p);
	free(pb_key_1);
	free(pb_key_2);
	return(res);
}





/*
 *	Set the flags for a database.
 *	Currently only (flags & DB_DUP) is significant.
 */
static int _bdb1_db_set_flags(
	  BDB *bdb
	, u_int32_t flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_set_flags(0x%x)\n", me, flags);
#endif
	bdb->flags = flags;
	return(0);
}



/*
 *	Sync the database, flushing cache to disk.
 */
static int _bdb1_db_sync(
	  BDB *bdb
	, u_int32_t flags)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_db_sync()\n", me);
#endif
	return(bdb->db->sync(bdb->db, flags));
}



/*
 *	Allocate memory for the BDB database and initialise 
 *	it - particularly the function jump table.
 */
static void _bdb1_bdb_init(BDB **bdb_ret)
{
	BDB *bdb;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb1_bdb_init()\n", me);
#endif
	bdb = (BDB *)cob_malloc(sizeof(BDB));
	bdb->db_ass = NULL;

	bdb->associate = &_bdb1_db_associate;
	bdb->close = &_bdb1_db_close;
	bdb->cursor = &_bdb1_db_cursor;
	bdb->del = &_bdb1_db_del;
	bdb->fd = &_bdb1_db_fd;
	bdb->open = &_bdb1_db_open;
	bdb->put = &_bdb1_db_put;
	bdb->set_flags = &_bdb1_db_set_flags;
	bdb->sync = &_bdb1_db_sync;

	*bdb_ret = bdb;
}



/*
 *	Check each secondary index. The new key-value (extracted from new_record)
 *	is OK if:
 *		1. Duplicates are allowed.
 *		2. It is sparse.
 *		3. There is no existing key in the index with the same value.
 *		4. It is a REWRITE and the key is associated with the same primary-key.
 *
 */
static int _bdb1_check_keys(
	  BDB *bdb
	, DBT *dbt_key_p
	, DBT *dbt_new_record
	, int tf_rewrite
	, int *tf_ok)
{
	int ix, res = 0;
	DB_ASSOCIATION *ass;
	BDB *bdb_s;
	DBT _dbt_key_s, dbt_key_x;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb1_check_keys(%s)\n", me, tf_rewrite ? "REWRITE" : "WRITE");
#endif

	if (bdb->db_ass != NULL) {
		for (ix = 0; ix < bdb->next_ass; ++ix) {
			ass = bdb->db_ass + ix;
			bdb_s = ass->bdb;
			if (bdb_s->flags & DB_DUP)
				continue;
			res = ass->fn_callback(bdb_s, dbt_key_p, dbt_new_record, &_dbt_key_s);
			if (res == DB_DONOTINDEX)
				continue;
			if (res != 0)
				return(res);
			res = bdb_s->db->get(bdb_s->db, &_dbt_key_s, &dbt_key_x, 0);
			if (res == RET_SPECIAL)     // not-found
				continue;
			if (res != RET_SUCCESS)
				return(errno);
			if (tf_rewrite && !memcmp(dbt_key_p->data, dbt_key_x.data, dbt_key_x.size))
				continue;
			tf_ok = 0;
			return(0);
		}
	}
	*tf_ok = 1;
	return(0);
}



/*
 *	The irec trailer uses a key 1 byte longer than keys
 *	in same dset, so impossible to clash with user keys.
 *	Client should free() dbt_key->data.
 */

static int _bdb1_prep_irec(
	  BDB *bdb
	, DBT *dbt_key
	, DBT *dbt_irec)
{
	int cb_key;
	idx_file_t *f_idx = bdb->f_idx;
	cb_key = DSET_I(bdb->ix_dset).cb_key + sizeof(irec_t) + 1;
	dbt_key->data = cob_malloc(cb_key);
	dbt_key->size = cb_key;
	memset(dbt_key->data, 0xff, cb_key);
	dbt_irec->data = &bdb->irec;
	dbt_irec->size = sizeof(irec_t);
	return(0);
}



/*
 *	Increment the serial no for duplicate records.
 *	Store the new value in the trailer.
 */
static int _bdb1_bump_irec(BDB *bdb)
{
	int res;
	char *pb;
	DBT dbt_key, dbt_irec;

	bdb->irec++;
	_bdb1_prep_irec(bdb, &dbt_key, &dbt_irec);
	pb = dbt_key.data;
	res = bdb->db->put(bdb->db, &dbt_key, &dbt_irec, 0);
	free(pb);
	return(res);
}


/*
 *	Return 1 if the DBT is for a trailer.
 */
static int _bdb1_isa_trailer(
	  BDB *bdb
	, DBT *dbt_key)
{
	DBT dbt_key_irec, dbt_irec;

	_bdb1_prep_irec(bdb, &dbt_key_irec, &dbt_irec);
	if ((dbt_key->size == dbt_key_irec.size)
		&& (!memcmp(dbt_key->data, dbt_key_irec.data, dbt_key->size)))
		return(1);
	return(0);
}




// DBC functions


static int _bdb1_dbc_create(
	  BDB *bdb
	, DBC **dbc_ret
	, u_int32_t flags)
{
	int cb_key;
	DBC *dbc;
	idx_file_t *f_idx = bdb->f_idx;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_dbc_create()\n", me);
#endif
	_bdb1_dbc_init(&dbc);
	dbc->bdb = bdb;

	cb_key = DSET_I(bdb->ix_dset).cb_key;
	if (bdb->tf_duplicates) cb_key += sizeof(irec_t);
	MAKE_DBT(dbc->dbt_curkey, cob_malloc(cb_key), cb_key);
	cb_key = PDSET.cb_key;
	MAKE_DBT(dbc->dbt_curkey_p, cob_malloc(cb_key), cb_key);
	*dbc_ret = dbc;
	return(0);
}


static int _bdb1_dbc_close(DBC *dbc)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_dbc_close()\n", me);
#endif
	free(dbc->dbt_curkey.data);
	free(dbc->dbt_curkey_p.data);
	free(dbc);
	return(0);
}




/*
 *	Return a key/data pair from the index: dbc.
 *	Which key/data pair is returned depends on the value of mode.
 *
 *	<dbc>       The (pseudo) database cursor to use.
 *	<dbt_key_x> The key to use to select an entry in <dbc>.
 *	            The key returned.
 *	<dbt_key_p> Primary-key to use for DB_GET_BOTH.
 *	            The p-key returned.
 *	<dbt_data>	The data returned.
 *	<mode>      Indicate the method to use when finding the data.
 *
 *	Only a subset of BDB4.1 methods are implemented here:
 *	DB_SET match given secondary-key
 *	DB_GET_BOTH match given primary-key and secondary-key.
 *		This method may be used to select a specific row from an
 *		index with duplicate keys.
 *
 */
static int _bdb1_dbc_pget(
	  DBC *dbc
	, DBT *dbt_key_x
	, DBT *dbt_key_p
	, DBT *dbt_data
	, u_int32_t mode)
{
	int res, cb_key_s;
	char *pb_key_value_s;
	DBT _dbt_key_p;
	DB *db = dbc->bdb->db;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_dbc_pget(mode=%d)\n", me, mode);
#endif

	if (DBC_IX(dbc) == 0) {
		// primary index
		if (mode == DB_SET) {
			res = db->get(db, dbt_key_x, dbt_data, 0);
		} else {
			errno = EINVAL;
			res = RET_ERROR;
		}
		goto exit_func;
	}

	cb_key_s = dbt_key_x->size;
	pb_key_value_s = cob_malloc(cb_key_s);
	memcpy(pb_key_value_s, dbt_key_x->data, cb_key_s);
	switch(mode) {
		case DB_SET:
			res = db->get(db, dbt_key_x, &_dbt_key_p, 0);
			break;
		case DB_GET_BOTH:
			res = db->seq(db, dbt_key_x, &_dbt_key_p, R_CURSOR);
			while(res == 0) {
				if (memcmp(dbt_key_x->data, pb_key_value_s, cb_key_s)) {
					// moved onto next key-value
					res = DB_NOTFOUND;
					break;
				}	
				if (!memcmp(dbt_key_p->data, _dbt_key_p.data, dbt_key_p->size)) {
					// found entry matching p-key and s-key
					break;
				}
				res = db->seq(db, dbt_key_x, &_dbt_key_p, R_NEXT);
			}
			break;
		default:

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: !!! Internal Error: _bdb1_dbc_pget() illegal arg mode=%d\n", me, mode);
#endif
			errno = EINVAL;
			res = RET_ERROR;
	}
	free(pb_key_value_s);
	if (res != 0)
		goto exit_func;

	if (dbc->bdb->tf_duplicates)
		dbt_key_x->size -= sizeof(irec_t);
	// load current-keys - unless current-key was actual arg used
	if (dbc->dbt_curkey.data != dbt_key_x->data)
		memcpy(dbc->dbt_curkey.data, dbt_key_x->data, dbt_key_x->size);
	if (dbc->dbt_curkey_p.data != dbt_key_p->data)
		memcpy(dbc->dbt_curkey_p.data, dbt_key_p->data, dbt_key_p->size);

	// Now read record-data from primary.
	res = DBC_PRIMARY_DB(dbc)->seq(DBC_PRIMARY_DB(dbc), &_dbt_key_p, dbt_data, R_CURSOR);
	if (res != 0)
		goto exit_func;
	dbt_key_p->data = _dbt_key_p.data;		 
	dbt_key_p->size = _dbt_key_p.size;		 
	return(0);

exit_func:
	switch(res) {
		case RET_ERROR:	  return(errno);
		case RET_SPECIAL: return(DB_NOTFOUND);
		default: 	      return(0);
	}
}




/*
 *	Return the next record from a DB cursor, conditioned by <mode>.
 *	These are "cursory" notes. Read the BDB documentation for more detail.
 *	<dbc>       The (pseudo) database cursor to use.
 *	<dbt_key>   The key to use to select an entry: DB_SET & DB_SET_RANGE
 *	            The key returned.
 *	<dbt_data>  The record data returned.
 *	<mode> Cursors in BDB 4.1+ (used by us):
 *		DB_FIRST        record with the lowest key value.
 *		DB_LAST         record with the highest key value.
 *		DB_NEXT         next record in key order.
 *		DB_PREV         prior record in key order.
 *		DB_CURRENT		current record.
 *		DB_SET			record with key =  given key.
 *		DB_SET_RANGE	record with key >= given key.
 *
 *	We interpret DB_FIRST & DB_LAST in the context of the entire file. BDB 4.1
 *	operates differently, depending on key & DUPLICATES.
 *
 *	BDB 1.8 has no true cursor operations. We use sequential ops on DB.
 *	DB->seq uses:
 *		R_FIRST R_LAST R_NEXT R_PREV R_CURSOR
 */
static int _bdb1_dbc_get(
	  DBC *dbc
	, DBT *dbt_key
	, DBT *dbt_data
	, u_int32_t mode)
{
	int res = 0;
	DB *db = dbc->bdb->db;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _bdb1_dbc_get(mode=%d)\n", me, mode);
#endif

	switch(mode) {
		case DB_FIRST:
			res = db->seq(db, dbt_key, dbt_data, R_FIRST);
			if ((res == 0)
				&& dbc->bdb->tf_duplicates
				&& _bdb1_isa_trailer(dbc->bdb, dbt_key))
				res = RET_SPECIAL;
			break;
		case DB_LAST:
			res = db->seq(db, dbt_key, dbt_data, R_LAST);
			if ((res == 0) && dbc->bdb->tf_duplicates)
				res = db->seq(db, dbt_key, dbt_data, R_PREV);
			break;
		case DB_NEXT:
			res = db->seq(db, dbt_key, dbt_data, R_NEXT);
			if ((res == 0)
				&& dbc->bdb->tf_duplicates
				&& _bdb1_isa_trailer(dbc->bdb, dbt_key))
				res = RET_SPECIAL;
			break;
		case DB_PREV:
			res = db->seq(db, dbt_key, dbt_data, R_PREV);
			break;
		case DB_CURRENT:
			res = db->seq(db, dbt_key, dbt_data, R_PREV);
			if (res == 0)
				res = db->seq(db, dbt_key, dbt_data, R_NEXT);
			else
				res = db->seq(db, dbt_key, dbt_data, R_FIRST);
			break;
		case DB_SET:
			res = db->get(db, dbt_key, dbt_data, 0);
			break;
		case DB_SET_RANGE:
			res = db->seq(db, dbt_key, dbt_data, R_CURSOR);
			if ((res == 0)
				&& dbc->bdb->tf_duplicates
				&& _bdb1_isa_trailer(dbc->bdb, dbt_key))
				res = RET_SPECIAL;
			break;
		default:

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: !!! Internal Error: _bdb1_dbc_get() illegal arg mode=%d\n", me, mode);
#endif
			errno = EINVAL;
			goto exit_func;
	}
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 8) {
		char e[11];
		if (res == RET_ERROR)
			sprintf(e, "%d", errno);
		fprintf(stderr, "%s: exit _bdb1_dbc_get() => %s\n"
		      , me, (res == 0) ? "OK" : (res == RET_SPECIAL) ? "NOT-FOUND" : e);
	}
#endif
	if (res != 0)
		goto exit_func;
	if (DBC_IX(dbc) == 0) {
		memcpy(dbc->dbt_curkey.data, dbt_key->data, dbt_key->size);
		memcpy(dbc->dbt_curkey_p.data, dbt_key->data, dbt_key->size);
	} else {
		if (dbc->bdb->tf_duplicates)
			dbt_key->size -= sizeof(irec_t);
		memcpy(dbc->dbt_curkey.data, dbt_key->data, dbt_key->size);
		// On secondary indexes, we have just read primary-key as data.
		memcpy(dbc->dbt_curkey_p.data, dbt_data->data, dbt_data->size);
		// Now read record-data from primary.
		res = DBC_PRIMARY_DB(dbc)->get(DBC_PRIMARY_DB(dbc), dbt_data, dbt_data, 0);
		if (res != 0)
			goto exit_func;
	} 		 
	return(0);

exit_func:
	switch(res) {
		case RET_ERROR:	  return(errno);
		case RET_SPECIAL: return(DB_NOTFOUND);
		default: 	      return(0);
	}
}




/*
 *	Allocate memory for the BDB cursor (our version) and initialise 
 *	it - particularly the function jump table.
 */
static void _bdb1_dbc_init(DBC **dbc_ret)
{
	DBC *dbc;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _bdb1_dbc_init()\n", me);
#endif
	dbc = (DBC *)cob_malloc(sizeof(DBC));

	dbc->c_close = &_bdb1_void;              // see notes on cursor OPEN/CLOSE above
	dbc->c_get = &_bdb1_dbc_get;
	dbc->c_pget = &_bdb1_dbc_pget;

	*dbc_ret = dbc;
}




/*
 *	Return the message describing <errnum>.
 *	Most often this is delegated to the OS function strerror().
 *	However, BDB 4.1+ added its own error numbers. Only 2 are
 *	returned by our implementation.
 */
static char *db_strerror(int errnum) 
{
	static char errmsg[101];
	if ((errnum > 0) && (errnum < 500)) 
		return(strerror(errnum));
	switch(errnum) {
		case 0:
			return((char *)"Successful");
		case DB_NOTFOUND:
			return((char *)"Key/data pair not found");
		case DB_KEYEXIST:
			return((char *)"Key/data pair already exists");
		default:
			sprintf(errmsg, "BDB-1 error code = %d", errnum);
			return(errmsg);
	}
}


#endif         // WITH_INDEXED_BDB_1



#endif         // WITH_INDEXED_BDB | WITH_INDEXED_BDB_1



 


