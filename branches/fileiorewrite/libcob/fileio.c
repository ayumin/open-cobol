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
 * This module provides a set of functions that are called from the C code
 * emitted by the OpenCOBOL Compiler. After verifying the general context
 * of the call, control passes to the specialized function appropriate
 * to the file ORGANIZATION. These specialised functions are held in:
 *		fileio-relative.c
 *		fileio-sequential.c
 *		and one (cf. configure) of the interfaces to the various ISAM file handlers:
 *			fileio-isam-bdb.c		Config: WITH_INDEXED_BDB_1 Pre BDB 4.1
 *			                   		        WITH_INDEXED_BDB DB 4.1 BDB 5.3 and later
 *			fileio-isam-xisam.c		(CISAM | DISAM | VBISAM)
 *
 * fileio-sort.c implements the SORT functions.
 * fileio.call.c provides the COBOL CALL interface that relates to I-O.
 * fileio-misc.c provides shared functions to fileio*
 * fileio-stats.c generates an XML file that summarises IO within a process.
 */




#include "fileio-misc.h"
#include "fileio-isam.h"
#include "fileio-relative.h"
#include "fileio-sequential.h"
#include "fileio-stats.h"







#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio";
#endif


cob_global *app_globals;                  // from args passed to fileio_init()
runtime_env *app_env;


char *cob_file_path;                      // set from $COB_FILE_PATH - used to locate files

int synchronise = COB_SYNC_NONE;          // set from $COB_SYNC - determine how files are flushed


typedef struct file_list_entry {
	cob_file_t *file;
	struct file_list_entry *next;
} file_list_entry_type;


static file_list_entry_type *file_list = NULL;  // as each file is initialised, it is added to this list










static void _fileio_reset_file(cob_file_t *f);

static int get_cb_write(
	  cob_file_t *f
	, cob_field *rec);







/*
 *	Dummy functions used to intercept illegal IO calls. 
 *	These functions plug entries in the IO jump-table
 *	that should never be called 
 *	(e.g. START on ORGANIZATION SEQUENTIAL).
 *
 *	After logging, etc, these functions all simply throw:
 *		COB_IOEXC_ILLEGAL
 */
static char *_fileio_void_stats(
	  cob_file_t *f
	, const char *tabs);

static int _fileio_illegal_open(
	  cob_file_t *f
	, const int mode);

static int _fileio_illegal_close(
	  cob_file_t *f
	, const int opt);

static int _fileio_illegal_start(
	  cob_file_t *f
	, const int cond
	, cob_field *key);

static int _fileio_illegal_read(
	  cob_file_t *f
	, cob_field *key
	, const int opt);

static int _fileio_illegal_read_next(
	  cob_file_t *f
	, const int opt);

static int _fileio_illegal_write(
	  cob_file_t *f
	, const int cb_rsz
	, const int opt);

static int _fileio_illegal_rewrite(
	  cob_file_t *f
	, const int cb_rsz
	, const int opt);

static int _fileio_illegal_delete(
	  cob_file_t *f);

static int _fileio_illegal_sync(
	  cob_file_t *f
	, const int opt);

static int _fileio_illegal_unlock(
	  cob_file_t *f);

static int _fileio_illegal_erase(
	  cob_file_t *f);

static int _fileio_illegal_io(
	  cob_file_t *f
	, const char *io);



/*
 *	The functions required by fileio for ORGANIZATION INDEXED.
 *	These functions are provided by one of the various
 *	fileio INDEXED modules: fileio-isam-bdb or fileio-isam-xisam.
 */
static const struct cob_fileio_funcs indexed_funcs = {
	  cob_fileio_isam_open
	, cob_fileio_isam_close
	, cob_fileio_isam_start
	, cob_fileio_isam_read
	, cob_fileio_isam_read_next
	, cob_fileio_isam_write
	, cob_fileio_isam_rewrite
	, cob_fileio_isam_delete
	, cob_fileio_isam_sync
	, cob_fileio_isam_unlock
	, cob_fileio_isam_erase
	, cob_fileio_isam_stats
};





/*
 *	The functions required by fileio for ORGANIZATION SEQUENTIAL.
 *	These functions are provided by module: fileio-sequential.
 */
static const struct cob_fileio_funcs sequential_funcs = {
	  cob_fileio_sequential_open
	, cob_fileio_sequential_close
	, _fileio_illegal_start
	, _fileio_illegal_read
	, cob_fileio_sequential_read
	, cob_fileio_sequential_write
	, cob_fileio_sequential_rewrite
	, _fileio_illegal_delete
	, cob_fileio_sequential_sync
	, cob_fileio_sequential_unlock
	, cob_fileio_sequential_erase
	, _fileio_void_stats
};


/*
 *	The functions required by fileio for ORGANIZATION LINE SEQUENTIAL.
 *	These functions are provided by module: fileio-sequential.
 */
static const struct cob_fileio_funcs lineseq_funcs = {
	  cob_fileio_sequential_open
	, cob_fileio_sequential_close
	, _fileio_illegal_start
	, _fileio_illegal_read
	, cob_fileio_line_sequential_read
	, cob_fileio_line_sequential_write
	, _fileio_illegal_rewrite
	, _fileio_illegal_delete
	, cob_fileio_sequential_sync
	, cob_fileio_sequential_unlock
	, cob_fileio_sequential_erase
	, _fileio_void_stats
};




/*
 *	The functions required by fileio for ORGANIZATION RELATIVE.
 *	These functions are provided by module: fileio-relative.
 */
static const struct cob_fileio_funcs relative_funcs = {
	  cob_fileio_relative_open
	, cob_fileio_relative_close
	, cob_fileio_relative_start
	, cob_fileio_relative_read
	, cob_fileio_relative_read_next
	, cob_fileio_relative_write
	, cob_fileio_relative_rewrite
	, cob_fileio_relative_delete
	, cob_fileio_relative_sync
	, cob_fileio_relative_unlock
	, cob_fileio_relative_erase
	, _fileio_void_stats
};



/*
 *	This is a list of the "illegal" functions.
 *  Here primarily to supress compile-time warnings like:
 *		 fileio.c:986: warning: '_fileio_illegal_write' defined but not used
 */
static const struct cob_fileio_funcs illegal_funcs = {
	  _fileio_illegal_open
	, _fileio_illegal_close
	, _fileio_illegal_start
	, _fileio_illegal_read
	, _fileio_illegal_read_next
	, _fileio_illegal_write
	, _fileio_illegal_rewrite
	, _fileio_illegal_delete
	, _fileio_illegal_sync
	, _fileio_illegal_unlock
	, _fileio_illegal_erase
	, _fileio_void_stats
};




// Configuration may deny service for: SEQUENTIAL, RELATIVE, INDEXED

static const struct cob_fileio_funcs *fileio_funcs[COB_ORG_MAX] = {
#ifdef WITH_SEQUENTIAL_NONE 
	  &illegal_funcs
#else
	  &sequential_funcs
#endif

#ifdef WITH_SEQUENTIAL_NONE 
	, &illegal_funcs
#else
	, &lineseq_funcs
#endif

#ifdef WITH_RELATIVE_NONE 
	, &illegal_funcs
#else
	, &relative_funcs
#endif

#ifdef WITH_INDEXED_NONE 
	, &illegal_funcs
#else
	, &indexed_funcs
#endif

	, &illegal_funcs
};







/*
 *	Initialise the OpenCOBOL fileio sub-system.
 *	Called once per application execution cycle, prior to any IO.
 *	Execution is halted if any exceptions are encountered in fileio
 *	initialisation.
 *
 *	Environmental variables referenced [default]:
 *	COB_FILEIO_TRACE :: 0..no trace    n..trace detail increases with n [0]
 *	COB_SYNC      :: Y..logical flush  P..physical flush [no flush/sync]
 *	COB_FILE_PATH :: default root directory when forming external file-names [NULL] 
 */

void cob_init_fileio(
     cob_global *globals
   , runtime_env *env)
{
	char *s;
	int n, res;

#ifdef WITH_FILEIO_TRACE
	if ((s = getenv("COB_FILEIO_TRACE")) != NULL) {
		if ((*s >= '0') && (*s <= '9')) {
			trace_level = *s - '0';
		} else {
			if (cob_fileio_get_tf(s)) {
				trace_level = 2;
			}
		}
	}
	env->cob_fileio_trace_env = cob_save_env_value(env->cob_fileio_trace_env, s);
	env->cob_fileio_trace = &trace_level;
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_init_fileio() trace-level=%d\n", me, trace_level);
#endif


#ifdef WITH_FILEIO_LOG
	progid_t progid = cob_get_progid();
	openlog(progid.program_name, LOG_PID, LOG_USER);
	syslog(LOG_USER | LOG_INFO, "BOJ : COBOL: %s %s.%d"
         , progid.source_file_name, progid.version, progid.patch);
#endif

	app_globals = globals;
	app_env = (runtime_env *)env;
	if ((s = getenv("COB_SYNC")) != NULL) {
		if (*s == 'Y' || *s == 'y') {
			synchronise = COB_SYNC_LOGICAL;
		}
		if (*s == 'P' || *s == 'p') {
			synchronise = COB_SYNC_PHYSICAL;
		}
	}
	env->cob_do_sync_env = cob_save_env_value(env->cob_do_sync_env, s);
	env->cob_do_sync = &synchronise;
	cob_file_path = NULL;
	if ((s = getenv("COB_FILE_PATH")) != NULL) {
		// check not empty string
		for (n = 0; n < strlen(s); ++n) {
			if (*(s+n) != ' ') {
				cob_file_path = s;
				break;
			}
		}
	}
	env->cob_file_path_env = cob_save_env_value(env->cob_file_path_env, s);
	env->cob_file_path = cob_file_path;
	res = 0;
	if (0 != (res = cob_fileio_sharing_initialise())) 
		fprintf(stderr, "libcob: fileio: !!! failed to initialise sharing sub-system\n");
#ifndef WITH_SEQUENTIAL_NONE
	if (0 == res) {
		if (0 != (res = cob_fileio_sequential_initialise()))
			fprintf(stderr, "libcob: fileio: !!! failed to initialise sequential sub-system\n");
	}
#endif
#ifndef WITH_RELATIVE_NONE
	if (0 == res) {
		if (0 != (res = cob_fileio_relative_initialise()))
			fprintf(stderr, "libcob: fileio: !!! failed to initialise relative sub-system\n");
	}
#endif
#ifndef WITH_INDEXED_NONE
	if (0 == res) {
		if (0 != (res = cob_fileio_isam_initialise()))
			fprintf(stderr, "libcob: fileio: !!! failed to initialise isam sub-system\n");
	}
#endif
	if (0 == res) {
		if (0 != (res = cob_fileio_sort_initialise()))
			fprintf(stderr, "libcob: fileio: !!! failed to initialise sort sub-system\n");
	}

	if (0 == res) {
		if (0 != (res = cob_fileio_stats_initialise()))
			fprintf(stderr, "libcob: fileio: !!! failed to initialise stats sub-system\n");
	}

	if (0 != res) 
		cob_stop_run(res);

#ifdef WITH_FILEIO_EXCHANGE
	if (0 != (res = cob_fileio_open_exchange(
			  &relative_funcs
			, &sequential_funcs
			, &lineseq_funcs
			, &indexed_funcs)))
		cob_stop_run(res);
#endif


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0) {
		fprintf(stderr, "%s: synchronise=%d  cob_file_path=%s  trace_level=%d\n"
		              , me, synchronise, cob_file_path, trace_level); 	
		fprintf(stderr, "%s: exit cob_init_fileio()\n", me);
	}
#endif

}




/*
 *	Terminate the OpenCOBOL fileio sub-system.
 *	Called once per application execution cycle, prior to STOP RUN.
 *	Each file in our list of opened-files is closed if it is still open.
 *	The teminate function of each fileio sub-module is called to release
 *	resources.
 *	Make no further calls to fileio after calling cob_exit_fileio().
 */
void cob_exit_fileio(void)
{
	char assign_name[COB_SMALL_BUFF];
	file_list_entry_type *list;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0) 
		fprintf(stderr, "\n%s: cob_exit_fileio()\n", me);
#endif

	for (list = file_list; list != NULL; list = list->next) {
		if (list->file->open_mode != COB_OPEN_CLOSED) {
			cob_field_to_string(list->file->assign, assign_name, COB_SMALL_BUFF);
			cob_close (list->file, NULL, 0, 0);
			fprintf (stderr, "WARNING - Implicit CLOSE of %s (\"%s\")\n",
				list->file->select_name, assign_name);
			fflush (stderr);
		}
	}

#ifdef WITH_FILEIO_EXCHANGE
	cob_fileio_close_exchange();
#endif


	cob_fileio_sharing_terminate();
	cob_fileio_stats_terminate();
	cob_fileio_sort_terminate();

#ifndef WITH_SEQUENTIAL_NONE
	cob_fileio_sequential_terminate();
#endif

#ifndef WITH_RELATIVE_NONE
	cob_fileio_relative_terminate();
#endif

#ifndef WITH_INDEXED_NONE
	cob_fileio_isam_terminate();
#endif


#ifdef WITH_FILEIO_LOG
	syslog(LOG_USER | LOG_INFO, "EOJ");
	closelog();
#endif


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0) 
		fprintf(stderr, "%s: exit cob_exit_fileio()\n", me);
#endif

}







/*
 *	Initialise the internal fields for use with a COBOL FILE.
 *	This function should be invoked immediateley after the
 *	"public" fields in COBOL FILE structure have been initialised.
 *	If not, this function is called when the file is opened
 *	for the first time.
 *	The file is added to the list of known files.
 * 
 */
void cob_initialise_file(cob_file_t *f)
{
	char tf_found = 0;
 	file_list_entry_type *list;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_initialise_file()\n", me);
#endif


	f->file = NULL;
	f->assign_name = NULL;
	f->open_mode = COB_OPEN_CLOSED;
	f->tf_is_locked = 0;
	_fileio_reset_file(f);
	f->tf_initialised = 1;

	for (list = file_list; list != NULL; list = list->next) {
		if (f == list->file) {
			tf_found = 1;
			break;
		}
	}
	if (!tf_found) {
		list = cob_malloc(sizeof(file_list_entry_type));
		list->file = f;
		list->next = file_list;
		file_list = list;
	}
}




/*
 *	Called when the file struct has been fully initialised.
 */
void cob_assign_file(cob_file_t *f)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_assign_file(%s)\n", me, f->select_name);
#endif

	f->special = (f->flag_select_features & COB_SELECT_STDIN) ? 1
	           : (f->flag_select_features & COB_SELECT_STDOUT) ? 2
	// NYI     : (f->flag_select_features & COB_SELECT_STDERR) ? 3
                   : 0;
	cob_fileio_stats_initialise_file(f);
}




/*
 *	Implements the OPEN FILE statement.
 *	The struct representing FILE is reset (or initialised
 *	if necessary).
 *	If the file was previously closed with a lock; or is
 *	already open: a non-zero file-status code is returned.
 *	Otherwise, the open function registered for the ORGANIZATION
 *	is invoked.
 *	Arg "share_mode" is of type COB_SHARE_... 
 *	Arg "lock_mode" is of type COB_LOCK_... 
 */
void cob_open(
	  cob_file_t *f
	, const int open_mode
	, const int share_mode
	, const int lock_mode
	, const int lock_many
	, cob_field *fnstatus)
{
	char root_name[FILENAME_MAX];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_open(%s open_mode=%d share_mode=%d lock_mode=%d lock_many=%d)\n"
		              , me, f->select_name, open_mode, share_mode, lock_mode, lock_many);
#endif

	if (!f->tf_initialised)
		cob_initialise_file(f);         // B&B: if compiler didn't initialise FILE ... do it now
	cob_fileio_begin(f, COB_IO_VERB_OPEN);
	if (f->tf_is_locked) {
		// file was previously closed with lock 
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_LOCKED);
	} else if (f->open_mode != COB_OPEN_CLOSED) {
		// file is already open 
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_2XOPEN);
	} else {
		_fileio_reset_file(f);
		f->last_open_mode = open_mode;
		f->lock_mode = lock_mode;
		f->tf_lock_many = lock_many;
		// process COB_LOCK_EXCLUSIVE as COB_SHARE_EXCLUSIVE
		f->share_mode = (lock_mode == COB_LOCK_EXCLUSIVE) ? COB_SHARE_EXCLUSIVE : share_mode;

		if (f->special == 0) {
			cob_field_to_string(f->assign, root_name, FILENAME_MAX);
			cob_fileio_locate_file(root_name, root_name, FILENAME_MAX);
			if (*root_name == '\0') {
				cob_fileio_throw_rts(f, COB_IOEXC_FNAME_VOID);
			} else {
				if (f->fid != NULL) 
					free(f->fid);
				f->fid = cob_malloc(strlen(root_name) + 1);
				strcpy(f->fid, root_name);
				// make a copy of ASSIGN file-name.
				// its value may change later leading to misidentification of physical file.  
				if (f->assign_name != NULL) 
					free(f->assign_name);
				f->assign_name = cob_malloc(strlen(root_name) + 1);
				strcpy(f->assign_name, root_name);
			}
		} else {
			f->assign_name = cob_malloc(7);
			switch(f->special) {
				case 1: strcpy(f->assign_name, "STDIN");
						if (open_mode != COB_OPEN_INPUT)
							cob_fileio_throw_rts(f, COB_IOEXC_FILE_ACCESS);
					break; 
				case 2: strcpy(f->assign_name, "STDOUT");
						if (open_mode != COB_OPEN_OUTPUT)
							cob_fileio_throw_rts(f, COB_IOEXC_FILE_ACCESS);
					break; 
				case 3: strcpy(f->assign_name, "STDERR");
						if (open_mode != COB_OPEN_OUTPUT)
							cob_fileio_throw_rts(f, COB_IOEXC_FILE_ACCESS);
					break; 
			}
		}
		if (!COB_EXC_THROWN) {
			fileio_funcs[(int)f->organization]->open(f, open_mode);
			if (COB_EXC_OK) {
				f->open_mode = open_mode;
			}
		}
	}
	if (COB_EXC_OK) {
		if (f->tf_optional_is_missing
			|| f->tf_optional_was_created) {
			cob_fileio_throw_rts(f, COB_IOEXC_OK_NOFILE);
		}
	}
	cob_fileio_save_status(f, fnstatus);
	cob_fileio_stats_open_file(f, &exc, fileio_funcs[(int)f->organization]->stats);

#ifdef WITH_FILEIO_LOG
	syslog(LOG_USER | LOG_INFO, "File open [fs=%s]: '%s' "
		 , COB_EXC_FS_STR, cob_fileio_get_full_name(f));
#endif

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n\n%s: File OPEN (fs=%s): %s\n"
		              , me, COB_EXC_FS_STR, cob_fileio_get_full_name(f));
#endif

}




/*
 *	Implements the CLOSE FILE statement.
 *	If the file is not currently open: a non-zero file-status
 *	code is returned.
 *	Otherwise, the close function registered for the ORGANIZATION
 *	is invoked.
 *	Arg tf_cancel is currently ignored.     
 */

void cob_close(
	  cob_file_t *f
	, cob_field *fnstatus 
	, const int opt
        , const int tf_cancel)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_close(%s, opt=%d)\n", me, f->select_name, opt);
#endif

	cob_fileio_begin(f, COB_IO_VERB_CLOSE);
	f->tf_read_is_done = 0;
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPEN);
	} else if (f->tf_optional_is_missing) {
		f->open_mode = COB_OPEN_CLOSED;
	} else {
		fileio_funcs[(int)f->organization]->close(f, opt);
	}
	cob_fileio_save_status(f, fnstatus);
	cob_fileio_stats_close_file(f, opt, &exc);

#ifdef WITH_FILEIO_LOG
	cob_io_stats_t total, good;
	total = f->io_stats[0];
	good = f->io_stats[1];

	syslog(LOG_USER | LOG_INFO
		, "File close [fs=%s]: %s  Attempted/Completed: S=%d/%d R=%d/%d W=%d/%d U=%d/%d D=%d/%d" 
		, COB_EXC_FS_STR, f->select_name
		, total.cnt_start, good.cnt_start, total.cnt_read, good.cnt_read, total.cnt_write, good.cnt_write
		, total.cnt_rewrite, good.cnt_rewrite, total.cnt_delete, good.cnt_delete);
#endif

}





/*
 *	Implements the START FILE statement.
 *	The file must be currently open for input and not for
 *	RANDOM access, otherwise a non-zero file-status
 *	code is returned.
 *	The start function registered for the ORGANIZATION
 *	is invoked.
 */
void cob_start(
	  cob_file_t *f
	, const int cond
	, cob_field *key
	, cob_field *cb_key
	, cob_field *fnstatus)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_start(%s, con=%d, key @ 0x%lx, cb_key=%d)\n"
		      , me, f->select_name, cond, (long)key
		      , (cb_key == NULL) ? -1 : cob_get_int(cb_key));
#endif

	cob_fileio_begin(f, COB_IO_VERB_START);
	f->io_stats[0].cnt_start += 1;
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_S_ON_XIP);	
	} else if ((f->open_mode == COB_OPEN_OUTPUT)
	    || (f->open_mode == COB_OPEN_EXTEND)) {
		cob_fileio_throw_rts(f, COB_IOEXC_S_ON_XIP);	
	} else if (f->access_mode == COB_ACCESS_RANDOM) {
		cob_fileio_throw_rts(f, COB_IOEXC_XMODE_S);	
	} else if (f->tf_optional_is_missing) {
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPT);
	} else {	
		if (cb_key != NULL) key->size = cob_get_int(cb_key);
		fileio_funcs[(int)f->organization]->start(f, cond, key);
	}
	cob_fileio_save_status(f, fnstatus);
	if (COB_EXC_OK) {
		f->tf_beyond_eof = 0;
		f->tf_beyond_bof = 0;
	}
	f->tf_read_is_done = 0;
	f->tf_is_first_read = 1;
	f->tf_started = 1;           // regardless of success/failure
	if (COB_EXC_OK)
		f->io_stats[1].cnt_start += 1;
}







/*
 *	Implements the READ FILE statement.
 *	The file must be currently open for input otherwise a
 *	non-zero file-status code is returned.
 *	If a non-null value is given for key then the read is
 *	RANDOM; otherwise the READ is SEQUENTIAL. For SEQUENTIAL
 *	reads, the boundary conditions are checked and if the read
 *	would result in an illegal read, a non-zero file-status code
 *	is returned.
 *	Otherwise, either the read function or the read_next function
 *	registered for the ORGANIZATION is invoked.
 */
void cob_read(
	  cob_file_t *f
	, cob_field *key
	, cob_field *fnstatus
	, int opt)
{
	char tf_previously_started = f->tf_started;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_read(%s, opt=%d, key @ 0x%lx)\n"
		      , me, f->select_name, opt, (long)key);
#endif

	cob_fileio_begin(f, COB_IO_VERB_READ);
	f->io_stats[0].cnt_read += 1;
	f->tf_read_is_done = 0;
	f->tf_started = 0;
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_R_ON_XIP);
	} else if ((f->open_mode == COB_OPEN_OUTPUT)
	    || (f->open_mode == COB_OPEN_EXTEND)) {
		cob_fileio_throw_rts(f, COB_IOEXC_R_ON_XIP);	
	} else if (f->tf_optional_is_missing) {
		// COBOL specs SEQUENTIAL 1st READ -> "10" nth READ -> "23"  
		if (!f->tf_is_first_read || (key != NULL)) {
			cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPT);	
		} else {
			cob_fileio_throw_rts(f, COB_IOEXC_R_XEOF);	
			f->tf_is_first_read = 0;
		}
	} else {
		if (key == NULL) {
			/*
			 * Sequential read at the end of file is an error 
			 * irespective of read-direction and start-conditions ...
			 * if start failed then 1st following read-next fails: fs = 21
                         */
			if (tf_previously_started
				&& (f->tf_beyond_bof || f->tf_beyond_eof)) {
				cob_fileio_throw_rts(f, COB_IOEXC_NOREC);	
			} else if (f->tf_beyond_eof && !(opt & COB_READ_PREVIOUS)) {
				cob_fileio_throw_rts(f, COB_IOEXC_SEQ_READ_EOF);	
			} else if (f->tf_beyond_bof && !(opt & COB_READ_NEXT)) {
				cob_fileio_throw_rts(f, COB_IOEXC_SEQ_READ_BOF);	
			}
		}
	}
	if (!COB_EXC_OK) {
		cob_fileio_save_status(f, fnstatus);
		return;
	}
	if (key != NULL) {
		fileio_funcs[(int)f->organization]->read(f, key, opt);
	} else {
		if (tf_previously_started) {
			// after isam start: positioned on next record to read
			opt = (opt & 0xfffffff0) | COB_READ_CURRENT;
		}
		fileio_funcs[(int)f->organization]->read_next(f, opt);
	}
	cob_fileio_save_status(f, fnstatus);

	if (COB_EXC_OK) {
		f->tf_is_first_read = 0;
		f->tf_read_is_done = 1;
		f->tf_beyond_eof = 0;
		f->tf_beyond_bof = 0;
		f->io_stats[1].cnt_read += 1;
	} else {
		if (INT_STATUS_KEY(exc.status_key) == 10) {          // END_OF_FILE
			if (opt & COB_READ_PREVIOUS) {
				f->tf_beyond_bof = 1;
			} else {
				f->tf_beyond_eof = 1;
			}
		}
	}
}




/*
 *	Compiler emits cob_read_next as distinct to cob_read() with NULL key.      
 *	Need to investigate the distinction but for now delegate to cob_read().
 */
void cob_read_next(
          cob_file_t *f
        , cob_field *fnstatus
        , int opt)
{

#ifdef  WITH_FILEIO_TRACE
        if (trace_level > 0)
                fprintf(stderr, "\n%s: cob_read_next(%s, opt=%d)\n"
                      , me, f->select_name, opt);
#endif
	return(cob_read(f, NULL, fnstatus, opt));
}






/*
 *	Implements the WRITE FILE statement.
 *	The file must be currently open for output.
 *	If the access mode is SEQUENTIAL then the file should be
 *	open OUTPUT or EXTEND. 
 *	If the access mode is not SEQUENTIAL then the file should be
 *	open OUTPUT or I-O. 
 *	Otherwise a non-zero file-status code is returned.
 *	The write function registered for the ORGANIZATION
 *	is invoked.
 *	Optionally (depending on opt) the synch function registered
 *	for the ORGANIZATION is invoked.
 */
void cob_write(
	  cob_file_t *f
	, cob_field *rec
	, const int opt
	, cob_field *fnstatus
        , const unsigned int tf_check_eop)
{
	int cb_write = get_cb_write(f, rec);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_write(%s, opt=0x%x, check_eop=%u) rsz=%d\n"
		      , me, f->select_name, opt, tf_check_eop, cb_write);

#endif

	cob_fileio_begin(f, COB_IO_VERB_WRITE);
	f->io_stats[0].cnt_write += 1;
	f->tf_read_is_done = 0;
	f->tf_started = 0;
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_W_ON_XOP);
	} else if (f->open_mode == COB_OPEN_INPUT) {
		cob_fileio_throw_rts(f, COB_IOEXC_W_ON_XOP);	
	} else if (f->access_mode == COB_ACCESS_SEQUENTIAL) {
		if (f->open_mode == COB_OPEN_I_O) {
			cob_fileio_throw_rts(f, COB_IOEXC_SEQ_W_IO);	
		}
		if (f->linage != NULL) {
			f->linage->tf_check_eop = (char)tf_check_eop;
		}
	} else if (f->open_mode == COB_OPEN_EXTEND) {
		cob_fileio_throw_rts(f, COB_IOEXC_W_EXTEND);
	} else if (f->tf_optional_is_missing) {
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPT);	
	}
	if (COB_EXC_OK) {
		if ((cb_write < f->record_min) || (cb_write > f->record_max)) {
			cob_fileio_throw_rts(f, COB_IOEXC_VAR_RSZ);	
		} else {
			fileio_funcs[(int)f->organization]->write(f, cb_write, opt);
		}
	}
	cob_fileio_save_status(f, fnstatus);
	if (COB_EXC_OK) {
		f->record->size = cb_write;
		f->io_stats[1].cnt_write += 1;
		if (synchronise) {
			fileio_funcs[(int)f->organization]->sync(f, synchronise);
		}
	}
}





/*
 *	Implements the REWRITE FILE statement.
 *	The file must be currently open I-O.
 *	If the file-mode is SEQUENTIAL then there must be
 *	a current record established by a previous read.
 *
 *	The rewrite function registered for the ORGANIZATION
 *	is invoked.
 *	Optionally (depending on opt) the synch function registered
 *	for the ORGANIZATION is invoked.
 */
void cob_rewrite(
	  cob_file_t *f
	, cob_field *rec
	, const int opt
	, cob_field *fnstatus)
{
	int read_done = f->tf_read_is_done;
	int cb_write = get_cb_write(f, rec);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_rewrite(%s, opt=0x%x) rsz=%d\n"
		      , me, f->select_name, opt, cb_write);
#endif

	cob_fileio_begin(f, COB_IO_VERB_REWRITE);
	f->io_stats[0].cnt_rewrite += 1;
	f->tf_read_is_done = 0;
	f->tf_started = 0;
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_U_ON_XIO);
	} else if (f->open_mode != COB_OPEN_I_O) {
		cob_fileio_throw_rts(f, COB_IOEXC_U_ON_XIO);
	} else if (f->organization == COB_ORG_LINE_SEQUENTIAL) { 
		cob_fileio_throw_rts(f, COB_IOEXC_LSEQ_REWRITE);	
	} else if (f->tf_optional_is_missing) {
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPT);	
	} else if (f->access_mode == COB_ACCESS_SEQUENTIAL && !read_done) { 
		cob_fileio_throw_rts(f, COB_IOEXC_SEQ_U_NOREAD);
    }
	if (COB_EXC_OK) {
		fileio_funcs[(int)f->organization]->rewrite (f, cb_write, opt);
	}
	cob_fileio_save_status(f, fnstatus);
	if (COB_EXC_OK) {
		f->record->size = cb_write;
		f->io_stats[1].cnt_rewrite += 1;
		if (synchronise) {
			fileio_funcs[(int)f->organization]->sync(f, synchronise);
		}
	}
}




/*
 *	Implements the DELETE FILE RECORD statement.
 *	The file must be currently open I-O.
 *	If the file-mode is SEQUENTIAL then there must be
 *	a current record established by a previous read.
 *	Otherwise a non-zero file-status code is returned.
 *	The delete function registered for the ORGANIZATION
 *	is invoked.
 *	Optionally (depending on opt) the synch function registered
 *	for the ORGANIZATION is invoked.
 */
void cob_delete(
	  cob_file_t *f
	, cob_field *fnstatus)
{
	int	read_done = f->tf_read_is_done;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_delete(%s)\n", me, f->select_name);
#endif

	cob_fileio_begin(f, COB_IO_VERB_DELETE);
	f->io_stats[0].cnt_delete += 1;
	f->tf_read_is_done = 0;
	f->tf_started = 0;
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_D_ON_XIO);
	} else if (f->open_mode != COB_OPEN_I_O) {
		cob_fileio_throw_rts(f, COB_IOEXC_D_ON_XIO);
	} else if (f->tf_optional_is_missing) {
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPT);	
	} else if ((f->access_mode == COB_ACCESS_SEQUENTIAL) && !read_done) {
		cob_fileio_throw_rts(f, COB_IOEXC_SEQ_D_NOREAD);	
	} else {
		fileio_funcs[(int)f->organization]->delete(f);
	}
	cob_fileio_save_status(f, fnstatus);
	if (COB_EXC_OK) {
		f->io_stats[1].cnt_delete += 1;
		if (synchronise) {
			fileio_funcs[(int)f->organization]->sync(f, synchronise);
		}
	}
}







/*
 *	Implements DELETE FILE <file-name>.
 *	The file must not be currently open.
 *	The erase function registered for the ORGANIZATION
 *	is invoked.
 */
void cob_erase(
	  cob_file_t *f
	, cob_field *fnstatus)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_erase(%s)\n", me, f->select_name);
#endif

	cob_fileio_begin(f, COB_IO_VERB_ERASE);
	fileio_funcs[(int)f->organization]->erase(f);
	cob_fileio_save_status(f, fnstatus);
}







/*
 *	Remove all locks on the file.
 *	The file must be open.
 *	The unlock function registered for the ORGANIZATION
 *	is invoked.
 */
void cob_unlock_file(
	  cob_file_t *f
	, cob_field *fnstatus)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_unlock_file(%s)\n", me, f->select_name);
#endif

	cob_fileio_begin(f, COB_IO_VERB_UNLOCK);
	if (f->open_mode == COB_OPEN_CLOSED) {
		cob_fileio_throw_rts(f, COB_IOEXC_FILE_NOPEN);
	} else {
		fileio_funcs[(int)f->organization]->unlock(f);
	}
}




/*
 *	COMMIT is NYI therefore simply remove all locks on all files.
 */
void cob_commit(void)
{
	file_list_entry_type *list;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_commit()\n", me);
#endif

	cob_file_t *f;
	for (list = file_list; list != NULL; list = list->next) {
		f = list->file;
		if (f->open_mode != COB_OPEN_CLOSED)
			fileio_funcs[(int)f->organization]->unlock(f);
	}
}







/*
 *	ROLLBACK is NYI therefore simply remove all locks on all files.
 */
void cob_rollback(void)
{
	file_list_entry_type *list;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "\n%s: cob_rollback()\n", me);
#endif

	cob_file_t *f;
	for (list = file_list; list != NULL; list = list->next) {
		f = list->file;
		if (f->open_mode != COB_OPEN_CLOSED)
			fileio_funcs[(int)f->organization]->unlock(f);
	}
}




/*
 *	Expose fileio error-handler to external code.
 *	The error-handler displays info describing the last
 *	encountered fileio exception.
 */
void cob_display_file_exception(void)
{
	 cob_fileio_error_handler();
}





/*
 *	Reset file state ready for OPEN
 */ 

static void _fileio_reset_file(cob_file_t *f)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: _fileio_reset_file(%s)\n", me, f->select_name);
#endif

	f->tf_optional_was_created = 0;
	f->tf_optional_is_missing = 0;
	f->tf_beyond_bof = 1;
	f->tf_beyond_eof = 0;
	f->tf_started = 0;
	f->tf_is_first_read = 1;
	f->tf_read_is_done = 0;
	f->tf_needs_nl = 0;
}





/*
 *	For file f, calculate the number of bytes to write when
 *	writing record rec.
 */
static int get_cb_write(
	  cob_file_t *f
	, cob_field *rec)
{
	if (f->record_size != NULL) {
		// COBOL source has: RECORD VARYING DEPENDING ON f->record_size 
		return(cob_get_int(f->record_size));
	}
	if (f->record_max != f->record_min) {
		// variable length - use actual size of rec being written
		return(rec->size);
	} 
	// use fixed length of record area
	return(f->record_max);
}



static char *_fileio_void_stats(
	  cob_file_t *f
	, const char *tabs)
{
	return(NULL);
}



/*
 *	Dummy functions for illegal IO. 
 *	(e.g. START on ORGANIZATION SEQUENTIAL) 
 */

static int _fileio_illegal_open(
	  cob_file_t *f
	, const int mode)
{
	return(_fileio_illegal_io(f, "OPEN"));
}


static int _fileio_illegal_close(
	  cob_file_t *f
	, const int opt)
{
	return(_fileio_illegal_io(f, "CLOSE"));
}


static int _fileio_illegal_start(
	  cob_file_t *f
	, const int cond
	, cob_field *key)
{
	return(_fileio_illegal_io(f, "START"));
}


static int _fileio_illegal_read(
	  cob_file_t *f
	, cob_field *key
	, const int opt)
{
	return(_fileio_illegal_io(f, "READ"));
}


static int _fileio_illegal_read_next(
	  cob_file_t *f
	, const int opt)
{
	return(_fileio_illegal_io(f, "READ NEXT"));
}


static int _fileio_illegal_write(
	  cob_file_t *f
	, const int cb_rsz
	, const int opt)
{ 
	return(_fileio_illegal_io(f, "WRITE"));
}


static int _fileio_illegal_rewrite(
	  cob_file_t *f
	, const int cb_rsz
	, const int opt)
{
	return(_fileio_illegal_io(f, "REWRITE"));
}


static int _fileio_illegal_delete(cob_file_t *f)
{
	return(_fileio_illegal_io(f, "DELETE"));
}


static int _fileio_illegal_sync(
	  cob_file_t *f
	, const int opt)
{
	return(_fileio_illegal_io(f, "SYNC"));
}


static int _fileio_illegal_unlock(
	  cob_file_t *f)
{
	return(_fileio_illegal_io(f, "UNLOCK"));
}


static int _fileio_illegal_erase(
	  cob_file_t *f)
{
	return(_fileio_illegal_io(f, "ERASE"));
}



static int _fileio_illegal_io(
	  cob_file_t *f
	, const char *io)
{
#ifdef  WITH_FILEIO_TRACE
	fprintf(stderr, "%s: !!! illegal call: fileio %s :: %s\n"
	              , me, io, cob_fileio_get_full_name(f));	
#endif

#ifdef WITH_FILEIO_LOG
	syslog(LOG_USER | LOG_INFO
	     , "!!! Illegal call: %s on file %s"
	     , io, cob_fileio_get_full_name(f));
#endif

	cob_fileio_throw_rts(f, COB_IOEXC_ILLEGAL);
	cob_fileio_save_status(f, NULL);
	cob_fileio_error_handler();
	return(-1);
}




