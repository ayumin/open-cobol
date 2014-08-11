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





/*
 *	The header file for OpenCOBOL fileio :: miscellaneous supporting functions
 *	Clients: #include this header file FIRST :: it includes "config.h".
 */


#ifndef FILEIO_MISC_H
#define FILEIO_MISC_H


#include "config.h"     // ALWAYS FIRST - it determines which other .h are included




/*
 * Select Large Files (if there is an option: e.g. on 32-bit implementing LARGEFILE)
 * These definitions effect /usr/include/features.h - which documents them.
 *  _LARGEFILE_SOURCE    Some more functions for correct standard I/O.
 *  _LARGEFILE64_SOURCE  Additional functionality from LFS for large files.
 *  _FILE_OFFSET_BITS=N  Select default filesystem interface.
 * 
 * cf. http://www.unix.org/version2/whatsnew/lfs20mar.html 
*/    
 

#define _LARGEFILE_SOURCE               1
#define _LARGEFILE64_SOURCE             1
#define _FILE_OFFSET_BITS               64





#ifdef  _AIX
	#define _LARGE_FILES                    1
#endif

#if defined(__hpux__) && !defined(__LP64__)
	#define _APP32_64BIT_OFF_T              1
#endif



#ifdef HAVE_UNISTD_H
	#include <unistd.h>
#endif

#include <ctype.h>
#include <values.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#ifdef HAVE_FCNTL_H
	#include <fcntl.h>
#endif



// Force symbol exports on all fileio modules
#define COB_LIB_EXPIMP


#if defined(_WIN32)
//      Under MinGw path names are formed LINUX style - unsure about the rest
	#define FILE_NAME_SEPARATOR '/'
// 	#define FILE_NAME_SEPARATOR '\\'

	// <windows.h> checks for WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN 5
	#include <windows.h>
	#include <direct.h>
	#include <io.h>

	#ifndef __WATCOMC__
		#define fdcobsync       _commit
	#else
		#define fdcobsync       fsync
	#endif

	#if !defined(__BORLANDC__) && !defined(__WATCOMC__)
		#define getcwd          _getcwd
		#define chdir           _chdir
		#define mkdir           _mkdir
		#define rmdir           _rmdir
		#define open            _open
		#define close           _close
		#define unlink          _unlink
		#define fdopen          _fdopen
		#define lseek           _lseeki64
	#endif


	#define off_t           cob_s64_t

#else   // Not _WIN32
	#define FILE_NAME_SEPARATOR '/'
	#define GetTempPath(FILENAME_MAX, dir_temp) strcpy(dir_temp, "/tmp")      // last resort
	#if   defined(HAVE_FDATASYNC)
		#define fdcobsync       fdatasync
	#else
		#define fdcobsync       fsync
	#endif
#endif


#include "libcob.h"
#include "coblocal.h"
#include "fileio.h"





/*
 *	NOTE rewrite variable length records.
 *	MicroFocus: REWRITE :: GENERAL RULES
 *	<< The number of character positions in the record referenced by record-name
 *	must be equal to the number of character positions in the record being replaced. >>
 *	This rule appears to have been restricted by OpenCOBOL to ORANIZATION SEQUENTIAL
 *	files:
         if (f->organization == COB_ORG_SEQUENTIAL) {
                if (f->record->size != rec->size) {
                        RETURN_STATUS (COB_STATUS_44_RECORD_OVERFLOW);
                }

                if (f->record_size) {
                        if (f->record->size != (size_t)cob_get_int (f->record_size)) {
                                RETURN_STATUS (COB_STATUS_44_RECORD_OVERFLOW);
                        }
                }
        }
 *	There is confusion in COBOL85 tests:
 *      RL207 has checks for file-status "44" commented out.
 *	RL207 attempts to replace a 125b record with 128b (and expects success).
 *
 *      IX121 checks for "44" but IX112 accepts "00" and "44" as PASSES.
 *
 *	These macros implements the MF rule - until verified when they can
 *	be subsumed into config.h MF.
 *    
 */
//   #define IMPLEMENT_RL_FS_44 
#define IMPLEMENT_IX_FS_44 




#define     EBADARG         102     // Illegal argument 
#define     EBADKEY         103     // Illegal key desc  


// trace_level = 0 even when #ifdef WITH_FILEIO_TRACE is false
extern int trace_level;



runtime_env *app_env;                     // ptr to COBOL Environment (passed to fileio_init())
cob_global *app_globals;                  // ptr to COBOL Globals struct (passed to fileio_init())

#define APP_MODULE app_globals->cob_current_module

extern char *cob_file_path;               // set from $COB_FILE_PATH - used to locate files




// used to identify context of fileio exceptions:
enum cob_exception_context {
	  COB_IO_CONTEXT_FILEIO
	, COB_IO_CONTEXT_FILEIO_RELATIVE
	, COB_IO_CONTEXT_FILEIO_SEQUENTIAL
	, COB_IO_CONTEXT_FILEIO_LINE_SEQ
	, COB_IO_CONTEXT_FILEIO_INDEXED
	, COB_IO_CONTEXT_FILEIO_CALL
	, COB_IO_CONTEXT_FILEIO_SORT
	, COB_IO_CONTEXT_FILEIO_EXTERNAL
};

extern const char *cob_exception_context_cap[];




// used to identify source of "native" errno when
// handling fileio exceptions:
enum cob_exception_realm {
	  COB_IO_REALM_COBOL
	, COB_IO_REALM_OS
	, COB_IO_REALM_ISAM
	, COB_IO_REALM_BDB
	, COB_IO_REALM_ODBC
};

extern const char *cob_exception_realm_cap[];


// used to identify COBOL action being performed when
// handling fileio exceptions:
enum cob_exception_verb {
	  COB_IO_VERB_OPEN
	, COB_IO_VERB_CLOSE
	, COB_IO_VERB_START
	, COB_IO_VERB_READ
	, COB_IO_VERB_WRITE
	, COB_IO_VERB_REWRITE
	, COB_IO_VERB_DELETE
	, COB_IO_VERB_ERASE
	, COB_IO_VERB_UNLOCK
	, COB_IO_VERB_CALL
	, COB_IO_VERB_SORT_OPEN
	, COB_IO_VERB_SORT_CLOSE
	, COB_IO_VERB_SORT_USING
	, COB_IO_VERB_SORT_GIVING
	, COB_IO_VERB_SORT_RELEASE
	, COB_IO_VERB_SORT_RETURN
};

extern const char *cob_exception_verb_cap[];




// used to define state after exception thrown
// Important these values match values for 'state' in fileio-exception.def
enum cob_exception_state {
	  COB_IO_STATE_SUCCESS     = 0
	, COB_IO_STATE_FATAL       = 1
	, COB_IO_STATE_RECOVERABLE = 2
};

extern const char *cob_exception_state_cap[];



struct generic_file {
	FILE *file;
	int   isaPipe;            // this file is a pipe          
	int   i_rec;              // ordinal (0...filesize-1) of current record 
	int   cb_rec;             // count of bytes in current record 
	char *pb_rec;             // record-buffer (used internally - f->record is preserved until SUCCESS)
};


// Exception state
typedef struct {
	int                        tf_thrown;       // true if exception state is set
	cob_file_t                *file;            // file being handled when exc thrown
	enum cob_exception_state   state;           // impact of exception
	enum cob_exception_context context;         // the fileio module
	enum cob_exception_realm   realm;           // causer of error (e.g. BDB or LINUX OS)
	enum cob_exception_verb    verb;            // COBOL I-O action being performed 
	int                        erc_cobol;       // selected from fileio-exception.def
	char                      *msg_cobol;       // message from fileio-exception.def
	int                        erc_native;      // errno from OS, ISAM Handler or BDB
	char                      *msg_native;      // any message associated with erc
	char                       status_key[2];   // COBOL FILE STATUS extrapolated from erc_cobol 
} exception_t;


// The exception object declared in fileio-misc.c and globally accessible
extern exception_t exc;

#define COB_EXC_THROWN      (exc.tf_thrown == 1)
#define COB_EXC_OK          (exc.state == COB_IO_STATE_SUCCESS)
#define COB_EXC_RECOVERABLE (exc.state == COB_IO_STATE_RECOVERABLE)
#define COB_EXC_FATAL       (exc.state == COB_IO_STATE_FATAL)
#define COB_EXC_FS_STR      (cob_fileio_status_to_str(exc.status_key))

#define INT_STATUS_KEY(fs)          (((fs[0] - '0') * 10) + (fs[1] - '0'))



// declare the fileio exception codes: COB_IO_EC_*

#undef  COB_IO_EXCEPTION
#define COB_IO_EXCEPTION(code, fatal, status, tag, def)   ,tag

enum cob_exception_tags {
	  COB_IO_EC_ZERO
#include "fileio-exception.def"
	, COB_IO_EC_MAX
};

#undef  COB_IO_EXCEPTION




/*
 *	The function jump table.
 *	Each type of ORGANIZATION provides a jump table. 
 *	fileio communicates with the code specific to each type
 *	of file ORGANIZATION via this table.
 */ 
struct cob_fileio_funcs {
	int	(*open)      (cob_file_t *f, const int open_mode);
	int	(*close)     (cob_file_t *f, const int opt);
	int	(*start)     (cob_file_t *f, const int cond, cob_field *key);
	int	(*read)      (cob_file_t *f, cob_field *key, int opt);
	int	(*read_next) (cob_file_t *f, int opt);
	int	(*write)     (cob_file_t *f, const int cb_rsz, const int opt);
	int	(*rewrite)   (cob_file_t *f, const int cb_rsz, const int opt);
	int	(*delete)    (cob_file_t *f);
	int	(*sync)      (cob_file_t *f, const int opt);
	int	(*unlock)    (cob_file_t *f);
	int	(*erase)     (cob_file_t *f);
	char *(*stats)   (cob_file_t *f, const char *tabs);
};


/*
 *	Set in fileio-sequential from $COB_UNIX_LF 
 *	Used in file_open to modify fopen() mode.
 */
extern int tf_ls_binary;



extern
void cob_fileio_begin(
	  cob_file_t *f
	, enum cob_exception_verb);

extern
void cob_fileio_throw_rts(
	  cob_file_t *f
	, enum cob_exception_id id);

extern
void cob_fileio_throw_exc(
	  cob_file_t *f
	, enum cob_exception_id id
	, enum cob_exception_context context);

extern
void cob_fileio_throw_ext(
	  cob_file_t *f
	, enum cob_exception_id id
	, enum cob_exception_context context 
	, enum cob_exception_realm realm
	, int erc_native
	, char *msg_native);

extern
void cob_fileio_save_status(
	  cob_file_t *f
	, cob_field *fnstatus);

extern
char *cob_fileio_status_to_str(
	  char status_key[2]);

extern
const char *cob_fileio_status_msg(
	  char status_key[]);

extern
void cob_fileio_error_handler(void);

extern
void cob_fileio_report_io_error(
	  cob_file_t *f
	, enum cob_exception_id id
	, enum cob_exception_context context 
	, enum cob_exception_realm realm
	, const char *msg);



extern
int cob_fileio_generic_open(
	  cob_file_t *f
	, char *filename
	, const int mode
	, enum cob_exception_context context);

extern
int cob_fileio_generic_close(
	  cob_file_t *f
	, const int opt
	, enum cob_exception_context context);

extern
int cob_fileio_generic_unlock(
	  cob_file_t *f
	, enum cob_exception_context context);

extern
int cob_fileio_generic_erase(
	  cob_file_t *f
	, enum cob_exception_context context);




extern
int cob_fileio_get_tf(
	  const char *var_name);

extern
char *cob_fileio_key_to_str(
	  cob_file_key_t *key); 

extern
char *cob_fileio_fmtstr( 
	  char *pb_str
	, int cb_str);

extern
char *cob_fileio_strtohuman(
	  char *pb_str
	, int cb_str
	, int ix_pool);

extern
char *cob_fileio_strtohex(
	  char *pb_hex
	, char *pb_str
	, int cb_str);

extern
char *cob_fileio_format_SQL_literal(
	  char *pb_txt
	, int cb_txt
	, char *pb_scratch);

extern
char *cob_fileio_get_now(void);

extern
char *cob_fileio_get_full_name(
	  cob_file_t *f);

extern
int cob_fileio_is_special(
	  char *filename); 

extern
int cob_fileio_is_absolute(
	  char *filename); 

extern
int cob_fileio_get_dirtmp(
	  char *pb_dirtmp);

extern
int cob_fileio_locate_file(
	  char *filename
	, char *ret_filename
	, int cb_max_filename);

extern
int cob_fileio_sharing_initialise(void);

extern
int cob_fileio_sharing_terminate(void);

extern
int cob_fileio_sharing_open_file(
	  cob_file_t *f
	, int open_mode);

extern
int cob_fileio_sharing_close_file(
	  cob_file_t *f); 

extern
int cob_fileio_open_exchange(
	  const struct cob_fileio_funcs *relative_funcs
	, const struct cob_fileio_funcs *sequential_funcs
	, const struct cob_fileio_funcs *lineseq_funcs
	, const struct cob_fileio_funcs *indexed_funcs);

extern
int cob_fileio_close_exchange(void);

#endif

