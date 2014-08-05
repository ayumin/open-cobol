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
 *	A collection of functions providing internal support to the fileio modules
 */







#include <ctype.h>
#include <values.h>
#include "config.h"
#include "fileio-misc.h"





#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-misc";
#endif


#define STOPPER (int)0xEFFFFFFF       // MinGW no MAXINT declared`




typedef struct {
	char           flag[6];         // targets for locks - content irrelevant (cf. SHARE_IS)
	cob_fileuid_t  fileuid;         // unique id for file
} cob_lock_t;



#ifdef WITH_FILEIO_SHARING

#define SHARE_IS_BUSY       0
#define SHARE_IS_EXCLUSIVE  1
#define SHARE_IS_READ_ONLY  2
#define SHARE_IS_ALL        3
#define SHARE_IS_WRITING    4
#define SHARE_IS_READING    5

static FILE *f_lock;

#endif


static const int status_key_1[] = {
	  0                             // 0x 
	, COB_EC_I_O_AT_END             // 1x 
	, COB_EC_I_O_INVALID_KEY        // 2x 
	, COB_EC_I_O_PERMANENT_ERROR    // 3x 
	, COB_EC_I_O_LOGIC_ERROR        // 4x 
	, COB_EC_I_O_RECORD_OPERATION   // 5x 
	, COB_EC_I_O_FILE_SHARING       // 6x 
	, COB_EC_I_O                    // unused 
	, COB_EC_I_O_IMP                // 8x 
	, COB_EC_I_O_IMP                // 9x 
};





#undef  COB_IO_EXCEPTION
#define COB_IO_EXCEPTION(code, state, status, tag, def)   ,{code, state, status, tag, def}
static struct {
	const int code;
	const char state; 	
	const char status_key[2];
	const int tag;
	const char *def;
} io_exception[] = {
	  {0, 0, "  ", 0, ""}
#include "fileio-exception.def"
	, {STOPPER, 0, "  ", STOPPER, ""}
};



exception_t exc;


// Must match enum cob_exception_context
const char *cob_exception_context_cap[] = {
	  "File I-O"
	, "RELATIVE File I-O"
	, "SEQUENTIAL File I-O"
	, "LINE SEQUENTIAL File I-O"
	, "INDEXED File I-O"
	, "CALL Routine"
	, "SORT Routine"
};




// Must match enum cob_exception_realm
const char *cob_exception_realm_cap[] = {
	  "COBOL RTS"
	, "Operating System"
	, "ISAM Package"
	, "BDB Package"
	, "ODBC Handler"
};



// Must match enum cob_exception_verb
const char *cob_exception_verb_cap[] = {
	  "open-file"
	, "close-file"
	, "start-file"
	, "read-record"
	, "write-record"
	, "rewrite-record"
	, "delete-record"
	, "erase-file"
	, "unlock-records"
	, "call-routine"
	, "sort-open-file"
	, "sort-close-file"
	, "sort-using"
	, "sort-giving"
	, "sort-release"
	, "sort-return"
};



// Must match enum cob_exception_state
const char *cob_exception_state_cap[] = {
	   "Success"
	,  "Fatal"
	,  "Recoverable"
};


// Set from $COB_FILEIO_TRACE: 1: fileio   2: fileio-modules  3: details
// May be referenced even when #ifdef WITH_FILEIO_TRACE is false
int trace_level = 0;                       




#define SET_STATUS_KEY(fs, b1, b2) 	{fs[0] = b1; fs[1] = b2;}
#define CPY_STATUS_KEY(fs1, fs2) 	{fs1[0] = fs2[0]; fs1[1] = fs2[1];}


static void _fileio_map_file_name(
	  char *pb_dest 
	, int *rb_dest
	, char *pb_token);

static int _fileio_open_native(
	  cob_file_t *f
	, char *filename
	, int cob_mode);

static int _fileio_open_special(
	  cob_file_t *f
	, const char stdxxx
	, const int cob_mode);

static int _fileio_open_pipe(
	  cob_file_t *f
	, const char *command
	, const int cob_mode);

static char _fileio_isPrintable(
	  char *s
	, int n);



#ifdef WITH_FILEIO_SHARING

static char _fileio_share_access_ok(
	  int open_mode
	, int share_mode
	, int rb);

static char _fileio_get_sentinel(
	  long rb);

static int _fileio_set_sentinel(
	  long rb); 

#endif



// Reset exception_state at start of a new IO operation.
void cob_fileio_begin(
	  cob_file_t *f
	, enum cob_exception_verb verb)
{
	exc.tf_thrown = 0;
	exc.file = f;
	exc.verb = verb;
	exc.state = COB_IO_STATE_SUCCESS;
	exc.context = COB_IO_CONTEXT_FILEIO;
	exc.realm = COB_IO_REALM_COBOL;
	exc.erc_cobol = 0;
	exc.msg_cobol = NULL;
	exc.erc_native = 0;
	exc.msg_native = NULL;
	SET_STATUS_KEY(exc.status_key, '0', '0');
}




/*
 *	When an exception is detected in the main fileio run-time system,
 *	it is thrown here.
 *	Example: attempting IO on a FILE that is not OPEN.
 *	
 */
void cob_fileio_throw_rts(
	  cob_file_t *f
	, enum cob_exception_id id)
{

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_fileio_throw_rts(%d, %s)\n"
		      , me, io_exception[id].code, f->select_name);
#endif

	exc.file = app_globals->cob_error_file = f;
	exc.context = COB_IO_CONTEXT_FILEIO;
	exc.realm = COB_IO_REALM_COBOL;
	exc.erc_cobol = io_exception[id].code;
	exc.msg_cobol = (char *)io_exception[id].def;
	CPY_STATUS_KEY(exc.status_key, io_exception[id].status_key);
	exc.state = io_exception[id].state;
	exc.tf_thrown = 1;

#ifdef WITH_FILE_STATUS_ANSI85
	return;
#endif


#ifdef WITH_FILE_STATUS_RM
	// replace some status-key values by RM "9N" 
	switch(io_exception[id].code) {
		case COB_IOEXC_SEQ_U_NOREAD:
		case COB_IOEXC_SEQ_D_NOREAD:
		case COB_IOEXC_XMODE_S:
		case COB_IOEXC_XMODE_R:
		case COB_IOEXC_XMODE_W:
		case COB_IOEXC_XMODE_U:
		case COB_IOEXC_XMODE_D:
			CPY_STATUS_KEY(exc.status_key, "90";
			break;
		case COB_IOEXC_FILE_NOPEN:
			CPY_STATUS_KEY(exc.status_key, "91";
			break;
		case COB_IOEXC_FILE_2XOPEN:
			CPY_STATUS_KEY(exc.status_key, "92";
			break;
		case COB_IOEXC_FILE_LOCKED:
			CPY_STATUS_KEY(exc.status_key, "93";
			break;
		case COB_IOEXC_FILE_MISSING:
		case COB_IOEXC_FILE_NPERM:
		case COB_IOEXC_FILE_ACCESS:
		case COB_IOEXC_FSHARE_LOCK:
			CPY_STATUS_KEY(exc.status_key, "94";
			break;
		case COB_IOEXC_FNAME_VOID:
		case COB_IOEXC_FNAME_BAD:
		case COB_IOEXC_FNAME_2BIG:
			CPY_STATUS_KEY(exc.status_key, "95";
			break;
		case COB_IOEXC_SEQ_READ_BOF:
		case COB_IOEXC_SEQ_READ_EOF:
			CPY_STATUS_KEY(exc.status_key, "96";
			break;
		case COB_IOEXC_ISAM_NINDEX:
		case COB_IOEXC_ISAM_BAD_DICT:
		case COB_IOEXC_ISAM_CREATE:
		case COB_IOEXC_ISAM_OPEN:
		case COB_IOEXC_ISAM_FAILED:
			CPY_STATUS_KEY(exc.status_key, "98";
			break;
		case COB_IOEXC_FILE_LOCKED:
		case COB_IOEXC_REC_LOCKED:
			CPY_STATUS_KEY(exc.status_key, "99";
			break;
	}
	return;
#endif

#if defined(WITH_FILE_STATUS_EXTENDED) || defined(WITH_FILE_STATUS_NATIVE)
	if (!strncmp(exc.status_key, "30", 2)) {
		// this is the problematic "no further info" status-key
		// substitute 9/rts-erc
		SET_STATUS_KEY(exc.status_key, '9', (unsigned char)exc.erc_cobol);
	}
#endif

}




/*
 *	When an exception is detected in the subsidiary fileio 
 *	run-time system, it is thrown here.
 *	Example: ISAM attempting OPEN FILE IO that is not found.
 *	
 */
void cob_fileio_throw_exc(
	  cob_file_t *f
	, enum cob_exception_id id
	, enum cob_exception_context context)
{

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_fileio_throw_exc(%d)\n"
		      , me, context);
#endif
	cob_fileio_throw_rts(f, id);
	exc.context = context;
}





/*
 *	When an exception is detected outside the fileio run-time system,
 *	it is thrown here.
 *	Example: OS errors, ISAM errors, BDB.
 *	
 */
void cob_fileio_throw_ext(
	  cob_file_t *f
	, enum cob_exception_id id
	, enum cob_exception_context context 
	, enum cob_exception_realm realm
	, int erc_native
	, char *msg_native)
{

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_fileio_throw_ext(%d, %d, %d, %s)\n"
		      , me, context, realm, erc_native, msg_native);
#endif

	cob_fileio_throw_rts(f, id);
	exc.realm = realm;
	exc.context = context;
	exc.erc_native = erc_native;
	exc.msg_native = msg_native;

#ifdef WITH_FILE_STATUS_NATIVE
	if ((exc.status_key[0] == '9')
		&& (io_exception[id].code == COB_IOEXC_ERROR)) {
		// return more precise native errrno
		SET_STATUS_KEY(exc.status_key, '8', (unsigned char)erc_native);
	}
#endif
}






		
/*
 *	Copy the status-key in the exception object into
 *	the 2 byte COBOL FILE STATUS of f, and optionally fnstatus.
 *	The COBOL exception trap is reset.
 */

void cob_fileio_save_status(
	  cob_file_t *f
	, cob_field *fnstatus)
{

#ifdef WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_fileio_save_status(%s, status-key=%c%c)\n"
		      , me, f->select_name, exc.status_key[0], exc.status_key[1]);
#endif

	app_globals->cob_error_file = f;
	app_globals->cob_exception_code = 0;
 	CPY_STATUS_KEY(f->file_status, exc.status_key);
	if (fnstatus != NULL) {
		CPY_STATUS_KEY(fnstatus->data, exc.status_key);
	}
	if (!((exc.status_key[0] == '5')
	   && (exc.status_key[1] == '2'))) {
		cob_set_exception(status_key_1[exc.status_key[0] & 0x0f]);
	}
}







/*
 *	Return a string that represents the given status-key.
 *	The returned string may be in form XX or 9/nnn
 *	The mem for the string is recycled on each call.
 */
char *cob_fileio_status_to_str(char status_key[])
{
	unsigned int fs1;
	static char fs[6];

	if (status_key[0] == '9') {
		fs1 = (unsigned char)status_key[1];
		sprintf(fs, "%c/%03u", status_key[0], fs1);
	} else {
		sprintf(fs, "%c%c", status_key[0], status_key[1]);
	}
	return(fs);
}



/*
 *	Return the message describing the given status-key.
 */

const char *cob_fileio_status_msg(char status_key[])
{

#undef COB_STATUS

#define COB_STATUS(status_number, status_id, status_def) ,{status_number, status_def}
        static struct {
                const int no;
                const char *descrp;
        } status_keys[] = {
                  {-1, ""}
#include "fileio-status.def"
                , {STOPPER, ""}
        };

#undef COB_STATUS


	int no, ix;

	if (status_key[0] == '8')
		no = 80;
	else if (status_key[0] == '9')
		no = 90;
	else
		no = INT_STATUS_KEY(status_key);

	for (ix = 0; status_keys[ix].no != STOPPER; ++ix) {
		if (status_keys[ix].no == no) {
			return(status_keys[ix].descrp);
		}
	}
	return("undefined status-key value");
}






void cob_default_error_handle(void)
{
	char *pb_txt;
	char txt[800];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_default_error_handle()\n", me);
#endif

	if (!COB_EXC_THROWN) {
		cob_runtime_error("!!! Internal error: EXCEPTION not set");
		return;
	}
	pb_txt = txt;
	// Line 1:
	pb_txt += sprintf(pb_txt, "Exception encountered while processing FILE: %s\n"
                , cob_fileio_get_full_name(exc.file));
	// Line 2:
	pb_txt += sprintf(pb_txt, "....... STATUS-KEY:       %s [%s]\n"
	            , cob_fileio_status_to_str(exc.status_key)
	            , cob_fileio_status_msg(exc.status_key));
	// Line 3:
	pb_txt += sprintf(pb_txt, "....... COBOL RTS ERRNO: %3d [%s]\n"
	            , exc.erc_cobol, exc.msg_cobol);
	// Line 4: only if native error
	if (exc.erc_native != 0)
		pb_txt += sprintf(pb_txt, "....... NATIVE ERRNO:    %3d [%s]\n"
		            , exc.erc_native, exc.msg_native);
	// Line 5:
	pb_txt += sprintf(pb_txt, "....... %s :: %s :: %s :: %s"
	            , cob_exception_context_cap[exc.context]
	            , cob_exception_realm_cap[exc.realm]		
	            , cob_exception_verb_cap[exc.verb]		
	            , cob_exception_state_cap[exc.state]
	);

#ifdef WITH_FILEIO_LOG
	syslog(LOG_USER | LOG_INFO, txt);
#endif
	cob_runtime_error(txt);
}



void cob_fileio_report_io_error(
	  cob_file_t *f
	, enum cob_exception_id id
	, enum cob_exception_context context 
	, enum cob_exception_realm realm
	, const char *msg)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_report_io_error(%d, %d, %d, msg='%s', fid='%s')\n"
	              , me, id, context, realm, msg, cob_fileio_get_full_name(f));	
#endif

	cob_fileio_throw_ext(f, id, context, realm, -1, (char *)msg);
	cob_fileio_save_status(f, NULL);
}





/*
 *	Open C stream for ORGANIZATION RELATIVE | SEQUENTIAL | LINE SEQUENTIAL
*/
int cob_fileio_generic_open(
	  cob_file_t *f
	, char *filename
	, const int mode
	, enum cob_exception_context context)
{
	int res;
	struct generic_file *f_generic;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_generic_open(%s file-name=%s  mode=%d)\n"
		      , me, f->select_name, filename, mode);
#endif

	f->file = f_generic = cob_malloc(sizeof(struct generic_file)); 
	f_generic->file = NULL;
	f_generic->pb_rec = NULL;
	f_generic->isaPipe = 0;
	f_generic->i_rec = -1;
	f_generic->cb_rec = 0;

	if (f->special != 0) {
		res = _fileio_open_special(f, f->special, mode);
	} else {
	    if (filename == NULL)
			filename = f->fid;
		if ((*filename == '>') || (*filename == '<')) 
			res = _fileio_open_pipe(f, filename, mode);
		else 
			res = _fileio_open_native(f, filename, mode);
	}
	if (res == 0) { 
		if (f_generic->isaPipe || (f->special != 0)) 
			return(0);
		if (0 == (res = cob_fileio_sharing_open_file(f, mode))) 
			return(0);
		res = errno;
	}
	if (f_generic->pb_rec != NULL)
		free(f_generic->pb_rec);
	free(f_generic);
	if (f->tf_optional_is_missing) {
		// defer reporting error until first I-O on optional file
		f->open_mode = mode;
		f->tf_beyond_eof = 1;
		f->tf_beyond_bof = 1;
		return(0);
	}	
	switch(res) {
	case ENOENT:
		if (mode == COB_OPEN_OUTPUT) {
			cob_fileio_throw_ext(f, COB_IOEXC_ERROR, context, COB_IO_REALM_OS, res, strerror(res));
		} else {
			cob_fileio_throw_exc(f, COB_IOEXC_FILE_MISSING, context);
		}
		break;
	case EACCES:
	case EISDIR:
	case EROFS:
		cob_fileio_throw_exc(f, COB_IOEXC_FILE_NPERM, context);
		break;
	case EAGAIN:
	case ESHARE:
		cob_fileio_throw_exc(f, COB_IOEXC_FSHARE_LOCK, context);
		break;
	default:
		cob_fileio_throw_ext(f, COB_IOEXC_ERROR, context, COB_IO_REALM_OS, res, strerror(res));
	}
	return(-1);
}




/*
 *	Open native FILE.
 *	Return native error-code.
*/

static int _fileio_open_native(
	  cob_file_t *f
	, char *filename
	, int cob_mode)
{
	char tf_file_exists;
	const char *mode;
	struct stat st;
	FILE *fp = NULL;


	struct generic_file *f_generic;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _fileio_open_native(%s file-name=%s  mode=%d)\n"
		      , me, f->select_name, filename, cob_mode);
#endif

	tf_file_exists =
		(0 == access(filename, (cob_mode == COB_OPEN_INPUT) ? R_OK : W_OK));

	switch (cob_mode) {
	case COB_OPEN_INPUT:
		if (!tf_file_exists) {
			if (f->flag_optional) {
				f->tf_optional_is_missing = 1;
			}
			return(errno);
		}
		break;
	case COB_OPEN_OUTPUT:
		break;
	case COB_OPEN_I_O:
		if (!tf_file_exists) {
			if (f->flag_optional) {
				f->tf_optional_was_created = 1;
				cob_mode = COB_OPEN_OUTPUT;
			} else {
				return(errno);
			}
		}
		break;
	case COB_OPEN_EXTEND:
		if (!tf_file_exists) {
			if (f->flag_optional) {
				f->tf_optional_was_created = 1;
			} else {
				return(errno);
			}
		}
		break;
	default:
		return(EPERM);
	}



#if !defined(_WIN32) || defined(_MSC_VER)
	switch (cob_mode) {
	case COB_OPEN_INPUT:
		mode = (f->organization == COB_ORG_LINE_SEQUENTIAL) ? "r" : "rb";
		break;
	case COB_OPEN_OUTPUT:
		if (f->organization == COB_ORG_RELATIVE)
			mode = "wb+";
		else if (f->organization == COB_ORG_LINE_SEQUENTIAL)
 			mode = "w";
		else
 			mode = "wb";
		break;
	case COB_OPEN_I_O:
		mode = (f->organization == COB_ORG_LINE_SEQUENTIAL) ? "r+" : "rb+";
		break;
	case COB_OPEN_EXTEND:
		mode = (f->organization == COB_ORG_LINE_SEQUENTIAL) ? "a+" : "ab+";
		break;
	default:
		return(EPERM);
	}
#else
	switch (cob_mode) {
	case COB_OPEN_INPUT:
		mode = "rb";
		break;
	case COB_OPEN_OUTPUT:
		mode = (f->organization == COB_ORG_RELATIVE) ? "wb+" : "wb";
		break;
	case COB_OPEN_I_O:
		mode = "rb+";
		break;
	case COB_OPEN_EXTEND:
		mode = "ab+";
		break;
	}
#endif

	fp = fopen(filename, mode);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: exit _fileio_open_native %s: \"%s\" [%d]\n"
		      , me, mode, filename, (fp == NULL) ? errno : 0);
#endif

	if (fp == NULL)
		return(errno);
	if (cob_mode == COB_OPEN_EXTEND)
		fseek(fp, (off_t)0, SEEK_END);
	f_generic = f->file;
	f_generic->file = fp;
	f_generic->pb_rec = cob_malloc(f->record_max);
	f->fileuid.inode = (fstat(fileno(fp), &st) == 0) ? st.st_ino : -1; 

	return(0);
}





/*
 *	Standard files are always "open" and never "closed".
 *	Simply check mode is appropriate for usage and
 *	remember which std file is to be used with COBOL file f.
 *  
*/
static int _fileio_open_special(
	  cob_file_t *f
	, const char stdxxx
	, const int cob_mode)
{
	struct generic_file *f_generic;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _fileio_open_special(%s std=%d mode=%d)\n"
		              , me, f->select_name, stdxxx, cob_mode);
#endif

	f_generic = f->file;
	switch(stdxxx) {
	case 1:
		if (cob_mode != COB_OPEN_INPUT) 
			return(EBADARG);
		f_generic->file = stdin;
		break;
	case 2:
		if (cob_mode != COB_OPEN_OUTPUT)
			return(EBADARG);
		f_generic->file = stdout;
		break;
	case 3:
		if (cob_mode != COB_OPEN_OUTPUT)
			return(EBADARG);
		f_generic->file = stderr;
		break;
	default:
		return(EBADARG);
	}
	return(0);
}




/*
 * Open a pipe: the 'filename' is a command, which is used to start a process,
 * to which data is written or read.
*/
static int _fileio_open_pipe(
	  cob_file_t *f
	, const char *command
	, const int cob_mode)
{
	const char *fopenMode;
	struct generic_file *f_generic;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _fileio_open_pipe(%s cmd=\"%s\" mode=%d)\n"
		              , me, f->select_name, command, cob_mode);
#endif

	if ((cob_mode == COB_OPEN_OUTPUT) && (*command == '>'))
		fopenMode = "w";
	else if ((cob_mode == COB_OPEN_INPUT) && (*command == '<'))
		fopenMode = "r";
	else
		return(EINVAL);
	if ((f->organization != COB_ORG_SEQUENTIAL) &&
		(f->organization != COB_ORG_LINE_SEQUENTIAL))
		return(EBADARG);
	f_generic = f->file; 
	f_generic->file = popen(command+1, fopenMode);
	if (f_generic->file == NULL)
		return(errno);
	f_generic->pb_rec = cob_malloc(f->record_max);
	f_generic->isaPipe = 1;
	return(0);
}





/*
 *	Close C stream for ORGANIZATION RELATIVE | SEQUENTIAL | LINE SEQUENTIAL
 *	NOTE: If opt == COB_CLOSE_UNIT or COB_CLOSE_UNIT_REMOVAL
 *	      the file is flushed but NOT closed. 
*/


int cob_fileio_generic_close(
	  cob_file_t *f
	, const int opt
	, enum cob_exception_context context)
{
	int exc_id = 0;
	enum cob_exception_realm realm = COB_IO_REALM_COBOL;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_generic_close(%s opt=%d)\n"
		      , me, f->select_name, opt);
#endif
	if ((f_generic == NULL) || (f->special != 0)) {
		// special files are NEVER physically closed
		f->open_mode = COB_OPEN_CLOSED;
		return(0);
	}
	switch (opt) {
	case COB_CLOSE_NORMAL:
	case COB_CLOSE_LOCK:
	case COB_CLOSE_NO_REWIND:
		if (f->organization == COB_ORG_LINE_SEQUENTIAL) {
			if (f->tf_needs_nl && !(f->flag_select_features & COB_SELECT_LINAGE)) {
				f->tf_needs_nl = 0;
				putc('\n', f_generic->file);
			}
		}
		cob_fileio_generic_unlock(f, context);
		fclose(f_generic->file);
		if (opt == COB_CLOSE_NO_REWIND) {
			f->open_mode = COB_OPEN_CLOSED;
			exc_id = COB_IOEXC_OK_REEL; 
		}
		break;
	case COB_CLOSE_UNIT:
	case COB_CLOSE_UNIT_REMOVAL:
		fflush(f_generic->file);
		cob_fileio_throw_exc(f, COB_IOEXC_OK_REEL, context);
		// N.B. file is NOT closed logically
		return(0);
	default:
		exc_id = COB_IOEXC_ERROR;
		realm = COB_IO_REALM_OS;
	}
	if (f_generic->pb_rec != NULL)
		free(f_generic->pb_rec);
	free(f_generic);
	cob_fileio_sharing_close_file(f); 
	f->file = NULL;
	f->open_mode = COB_OPEN_CLOSED;
	f->tf_is_locked = (opt == COB_CLOSE_LOCK);
	if (exc_id != 0) {
		if (realm == COB_IO_REALM_OS) {
			cob_fileio_throw_ext(f, exc_id, context, realm, errno, strerror(errno));
		} else {
			cob_fileio_throw_exc(f, exc_id, context);
		}
		return(-1);
	}
	return(0);
}




/*
 *	Unlock C stream for ORGANIZATION RELATIVE | SEQUENTIAL | LINE SEQUENTIAL
*/

int cob_fileio_generic_unlock(
	  cob_file_t *f
	, enum cob_exception_context context)
{
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_generic_unlock(%s)\n", me, f->select_name);
#endif

	if (f_generic == NULL)
		return(0);
	fflush(f_generic->file);
	fdcobsync(fileno(f_generic->file));
	if ((f->special != 0) || f_generic->isaPipe) 
		return(0);


#ifdef HAVE_FCNTL
	struct flock lock;
	memset((unsigned char *)&lock, 0, sizeof (struct flock));
	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	fcntl(fileno(f_generic->file), F_SETLK, &lock);
#endif
	return(0);
}



/*
 *	Physically delete the file using its expanded filename
*/

int cob_fileio_generic_erase(
	  cob_file_t *f
	, enum cob_exception_context context)
{
	char fid[FILENAME_MAX];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_generic_erase(%s)\n", me, f->select_name);
#endif

	if (f->special != 0)
		return(0);
 	if ((f->file != NULL)
		&& (((struct generic_file *)f->file)->isaPipe)) 
			return(0);

	cob_field_to_string(f->assign, fid, FILENAME_MAX);
	cob_fileio_locate_file(fid, fid, FILENAME_MAX);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: deleting file: \"%s\")\n", me, fid);
#endif

	if (0 != unlink(fid)) {
		cob_fileio_throw_ext(f, COB_IOEXC_ERROR, context, COB_IO_REALM_OS, errno, strerror(errno));
		return(-1);
	}
	return(0);
}









/*
 *	Using var_name, get a boolean value from the environment.
 *	Return 1 if a variable of that name exists in environment
 *	and the first char value is one of: 1 y Y t T. 
 *	Otherwise return 0.
 */
int cob_fileio_get_tf(const char *var_name) 
{
	char *var;
	var = getenv(var_name);
	if (var != NULL) {
		if ((*var == '1')
		  || (*var == 'Y') || (*var == 'y')
		  || (*var == 'T') || (*var == 't')) {
			return(1);
		}
	}
	return(0);
}






/*
 *	Return a printable representation of value of COBOL key.
 *	Returns a pointer to a buffer that is overwritten on each call.
*/

char *cob_fileio_key_to_str(cob_file_key_t *cob_key) 
{
	char *pb_key_txt;
	int cb, ix_comp;
	char *pb_key, *pb;
	cob_field *key_field;

	if (cob_key == NULL)
		return((char *)"NIL");
	key_field = cob_key->field;
	if (key_field->size < 1)
		return((char *)"EMPTY");
	pb_key = cob_malloc(key_field->size + 1);

	if (cob_key->count_components == 0) {
		memcpy(pb_key, key_field->data, key_field->size);
	} else {
		pb = pb_key;
		for (ix_comp = 0; ix_comp < cob_key->count_components; ++ix_comp) {
			cb = cob_key->component[ix_comp]->size;
			memcpy(pb, cob_key->component[ix_comp]->data, cb);
			pb += cb;
		}
	}
	pb_key_txt = cob_fileio_fmtstr(pb_key, key_field->size);
	free(pb_key);
 	return(pb_key_txt);
}






/*
 *  Represent the string (pb_str:cb_str) in human readable form.
 *  If the string is alphanumeric, it is returned in quotes.
 *  Otherwise, the hexadecimal representation is returned - prefixed
 *  by 0x.
 *  The pointer returned points to malloc-d space which is
 *  managed in a pool. Space from the same pool is recycled on each call.
 *	This supports usage such as:
 *		printf("Some text ... %s more text %s\n"
 *		     , cob_fileio_strtohuman(pb1, cb1, 0)
 *		     , cob_fileio_strtohuman(pb2, cb2, 1));
 *	without the second call overwriting the first.		 
 */
char *cob_fileio_strtohuman(
	  char *pb_str
	, int cb_str
	, int ix_pool)
{
	typedef struct {
		char *pb_txt;
		int   cb_txt;
	} pool_t;

	static int tf_initialised = 0;
	static pool_t pool[20];

	int ix;
	pool_t *p;
	if (!tf_initialised) {
		for (ix = 0; ix < 20; ++ix) {
			pool[ix].pb_txt = NULL;
			pool[ix].cb_txt = -1;
		}
		tf_initialised = 1;
	}
	if (ix_pool > 19) ix_pool = 19;
	p = pool + ix_pool;
	if (_fileio_isPrintable((void *)pb_str, cb_str)) {
		if (p->cb_txt < cb_str + 3) {
			if (p->pb_txt != NULL)
				free(p->pb_txt);
			p->pb_txt = cob_malloc(p->cb_txt = cb_str + 3);
		}
		sprintf(p->pb_txt, "\"%.*s\"", cb_str,  pb_str);
	} else {
		if (p->cb_txt < (2 *cb_str) + 3) {
			if (p->pb_txt != NULL)
				free(p->pb_txt);
			p->pb_txt = cob_malloc(p->cb_txt = (2 *cb_str) + 3);
		}
		sprintf(p->pb_txt, "0x%s", cob_fileio_strtohex(NULL, pb_str, cb_str));
	}
	return(p->pb_txt);
}





/*
 *	Convenience call to cob_fileio_strtohuman()
 *	CAUTION: cannot be used more than once simultaneously.
 */
char *cob_fileio_fmtstr(
	  char *pb_str
	, int cb_str)
{
	return(cob_fileio_strtohuman(pb_str, cb_str, 0));
}



	


/*
 *	Convert string pb_str of cb_str chars to a hexadecimal representation.
 *	pb_hex should point to space for the hex-text. If pb_hex is NULL space
 *	is malloc'd; malloc'd space is recycled on each call - DO NOT free() it.
 *	A pointer to pb_hex is returned which points to a NULL terminated string.
*/
char *cob_fileio_strtohex(
	  char *pb_hex
	, char *pb_str
	, int cb_str)
{
	static char hexChar[] = "0123456789abcdef";
	static char *pb_txt = NULL;
	int ix;
	char *pb;
	if (pb_hex == NULL) {
		if (pb_txt == NULL)
			pb_txt = malloc((cb_str * 2) + 1);
		else
			pb_txt = realloc(pb_txt, (cb_str * 2) + 1);
      	pb_hex = pb_txt;
	} else {
		if (pb_txt != NULL) {
			free(pb_txt);
			pb_txt = NULL;
		}
	}
	pb = pb_hex;
	for (ix = 0; ix < cb_str; ++ix) {
		*pb++ = hexChar[*((unsigned char *)pb_str) >> 4];
		*pb++ = hexChar[*((unsigned char *)pb_str) & 0x0f];
		pb_str += 1;
	}
	*pb = '\0';
	return(pb_hex);
}



static char _fileio_isPrintable(char *s, int n)
{
	while (n-- > 0) {
		if (!((*s == ' ') || isgraph(*s))) return(0);
		++s;
	}
	return(1);
}





/*
 *	Given a string at pb_txt of cb_txt bytes, return it 
 *	represented suitable for insertion in an SQL command.
 *	By preference, the returned string is as a character
 *	literal in single quotes. Otherwise, the result is of
 *	the form: x'HEXADECIMAL'.
 *	The returned string is stored in pb_scratch which
 *	is a pointer to workspace supplied by the client.
 *	Returns a pointer to pb_scratch.
 */
char *cob_fileio_format_SQL_literal(
	  char *pb_txt
	, int cb_txt
	, char *pb_scratch)
{
	if (_fileio_isPrintable(pb_txt, cb_txt)) {
		sprintf(pb_scratch, "'%.*s'"
		      , cb_txt, pb_txt);
	} else {
		sprintf(pb_scratch, "0x%s"
		      , cob_fileio_strtohex(NULL, pb_txt, cb_txt));
	}		
	return(pb_scratch);
}








/*
 *	Return the current date + time as a string (in standard format)
 *	WARNING: the returned string is recycled each call (NOT malloc'd)
 */
char *cob_fileio_get_now(void)
{
	static char now[24];
	time_t rawtime;
	struct tm *timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
    strftime(now, 23, "%d-%b-%Y %H:%M:%S", timeinfo);
	return(now);
}


/*
 *	A file's full name is defined as:
 *		<internal SELECT name> :: <ASSIGN name> :: <external pathed name>
 *	Space is malloc'd and recycled on each call - DO NOT free() it.
 *	Returns: a pointer to the full file-name (a NULL terminated string).
*/

char *cob_fileio_get_full_name(
	  cob_file_t *f)
{
	static int cb_file_name = -1;
	static char *pb_file_name = NULL;
	int cb;

	cb = 9 + strlen(f->select_name);
	if ((f->special == 0) && (f->assign_name != NULL)) {
		cb += strlen(f->assign_name);
		if (f->fid != NULL) {
			cb += strlen(f->fid);
		}
	}
	if (cb > cb_file_name) {
		if (cb_file_name == -1) {
			pb_file_name = cob_malloc(cb);
		} else {
			pb_file_name = realloc(pb_file_name, cb);
		}
		cb_file_name = cb;
	} 
	strcpy(pb_file_name, f->select_name);
	if ((f->special == 0) && (f->assign_name != NULL)) {
		strcat(pb_file_name, " :: ");
		strcat(pb_file_name, f->assign_name);
		if (f->fid != NULL) {
			strcat(pb_file_name, " :: ");
			strcat(pb_file_name, f->fid);
		}
	}
	return(pb_file_name);
}






/*
 *	Return true if filename is special.
*/
int cob_fileio_is_special(char *filename) 
{
 	if (   (strlen(filename) < 1)
		|| (*filename == '<')
		|| (*filename == '>')
		|| (*filename == '|')) {
		return(1);
	}
	return(0);
}



/*
 *	Return true if filename is absolute.
*/
int cob_fileio_is_absolute(char *filename) 
{
 	if (   (strlen(filename) < 1)
		|| (*filename == FILE_NAME_SEPARATOR)
		|| (*filename == '.')
		|| (*filename == '<')
		|| (*filename == '>')
		|| (*filename == '|')) {
		return(1);
	}

#ifdef _WIN32
	// check Windows "D:\" 
	if (isalpha(*filename)
	   && (*(filename+1) == ':')
	   && (*(filename+2) == FILE_NAME_SEPARATOR)) {
		return(1);
	}
#endif

	return(0);
}



/*
 *	Copy the name of the directory being used to
 *	store temporary files into pb_dirtmp (which
 *	should point to a space of at least FILENAME_MAX
 *	bytes).
 */

int cob_fileio_get_dirtmp(char *pb_dirtmp)
{
	char *pb_dir;
	if (((pb_dir = getenv("TMPDIR")) == NULL) &&
    	((pb_dir = getenv("TMP")) == NULL) &&
    	((pb_dir = getenv("TEMP")) == NULL)) {
		GetTempPath(FILENAME_MAX, pb_dirtmp);
	}
	if (pb_dir != NULL) {
		strcpy(pb_dirtmp, pb_dir);
	}
	return(0);
}



/*
 *	If the COBOL config denies file-name mapping then the given file-name
 *	is returned unchanged.
 *	Given the COBOL internal name for a file, map it to an external file name.
 *	This operates on sub-strings of the given file-name (separated by '/');
 *	supersedes original OpenCobol function which matches on the file-name as a single string.
 *	(1) file-names starting with any of [< > | ] are never mapped.
 *	(2) after token substitution from the environment, if the path doesn't
 *	   start with "/" or "." then value for env-var COB_FILE_PATH is prefixed.
 *	
 *	If the built file name is longer than cb_max_filename then it is truncated.
 *	The filename (a null-terminated string) is copied to ret_filename.
 *	It's safe for filename and ret_filename to overlap.
*/


int cob_fileio_locate_file(
	  char *filename              // file-name to expand (usually f->assign)
	, char *ret_filename          // returned expanded file-name
	, int cb_max_filename)        // max permitted length of returned file-name
{
	int rb_int, rb_ext, cb;
	char *pb1, *pb2;
	char wrk_filename[FILENAME_MAX+1];
	char token[FILENAME_MAX+1];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_locate_file(file-name=%s  cb_max=%d)\n"
		      , me, filename, cb_max_filename);
#endif

	// protect against arg[0] and arg[1] overlapping
	strcpy(wrk_filename, filename);
	if (!APP_MODULE->flag_filename_mapping
		|| cob_fileio_is_special(filename)) {
		// no mapping - return original filename
		cb = strlen(filename);
		if (cb >= cb_max_filename)
			cb = cb_max_filename - 1;
		strncpy(ret_filename, wrk_filename, cb);
		*(ret_filename + cb) = '\0';

#ifdef  WITH_FILEIO_TRACE
		if (trace_level > 2)
			fprintf(stderr, "%s: file-name (unmapped) -> \"%s\"\n", me, ret_filename);
#endif

 		return(0);
	}
	if (cb_max_filename > FILENAME_MAX)
		cb_max_filename = FILENAME_MAX;         // self-protection 

	// truncate trailing spaces
	for (rb_int = strlen(wrk_filename) - 1; rb_int >= 0; --rb_int) {
		if (wrk_filename[rb_int] != ' ')
			break;
		wrk_filename[rb_int] = '\0';
	}
	// copy filename into token until end-of-string or '}' or '/'
	// is encountered. Append expanded token to ret_filename and continue
	// until end-of-string. 
	rb_ext = 0;
	pb1 = wrk_filename;
	pb2 = token;
	for (rb_int = 0; ; ++rb_int) {
		if ((rb_int == cb_max_filename) || (*pb1 == '\0')) {
			*pb2 = '\0';
			_fileio_map_file_name(ret_filename, &rb_ext, token);
			break;
		}
		if (*pb1 == '}') {
			*pb2++ = '}';
			*pb2 = '\0';
			_fileio_map_file_name(ret_filename, &rb_ext, token);
			pb2 = token;
		} else if (*pb1 == FILE_NAME_SEPARATOR) {
			*pb2 = '\0';
			if (strlen(token) > 0)
				_fileio_map_file_name(ret_filename, &rb_ext, token);
			*(ret_filename + rb_ext) = FILE_NAME_SEPARATOR;
			++rb_ext;
			pb2 = token;
		} else {
			*pb2++ = *pb1;
		}
		++pb1;
	}
	*(ret_filename + rb_ext) = '\0';
	// having expanded filename, if not "absolute" prepend cob_file_path
	if (!cob_fileio_is_absolute(ret_filename)
		&& (cob_file_path != NULL)) {
		sprintf(token, "%s/%s", cob_file_path, ret_filename);
		strcpy(ret_filename, token);
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: file-name (mapped) -> \"%s\"\n", me, ret_filename);
#endif

	return(0); 
}






/*
 *	Given a string (token), substitute from environment in the COBOL manner.
 *	Mapping occurs in this order:
 *	(1) $token and ${token} ... maps to env variable "token" or stands.
 *	(2) token ... maps to to env variable "dd_token"
 *	(3) token ... maps to to env variable "DD_token"
 *	(4) token ... maps to to env variable "token"
 *	
 *	
*/
static void _fileio_map_file_name(
	  char *pb_dest                // pointer to start of target string
	, int *rb_dest                 // pointer to rb; writing starts at pb_dest + *rb_dest
	                               // *rb_dest is advanced so on return indicates length of string in pb_dest
	, char *pb_token)              // string token to be processed
 {
   char *pb_in = pb_token;
   char *pb_out = pb_dest + *rb_dest;
   char *pb_env;
   char *pb_tmp;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2) {
		fprintf(stderr, "%s: _fileio_map_file_name(token=\"%s\")", me, pb_token);
		if (*rb_dest > 0) 
			fprintf(stderr, "  ++\"%.*s\"", *rb_dest, pb_dest);
		fputc('\n', stderr);
	}
#endif

   if (*pb_in == '$') {
      ++pb_in;
      if (*pb_in == '{') {
         ++pb_in;
         if (*(pb_in + strlen(pb_in) - 1) == '}')
            *(pb_in + strlen(pb_in) - 1) = '\0';
         else
            goto return_stet;
      }
      if ((pb_env = getenv(pb_in)) == NULL)
         goto return_stet;
      goto return_sub;
   }
   pb_tmp = (char *)malloc(strlen(pb_in) + 4);
   sprintf(pb_tmp, "dd_%s", pb_in);
   if (NULL == (pb_env = getenv(pb_tmp))) {
      pb_tmp[0] = pb_tmp[1] = 'D';
      if (NULL == (pb_env = getenv(pb_tmp))) {
         pb_env = getenv(pb_in);
      }
   }
   free(pb_tmp);
   if (pb_env == NULL)
      goto return_stet;
   goto return_sub;

return_stet:
   memcpy(pb_out, pb_token, strlen(pb_token));
   *rb_dest += strlen(pb_token);
   return;

return_sub:
   memcpy(pb_out, pb_env, strlen(pb_env));
   *rb_dest += strlen(pb_env);

#ifdef  WITH_FILEIO_TRACE
		if (trace_level > 2)
			fprintf(stderr, "%s: file-name (environmentalised) -> \"%.*s\"\n", me, *rb_dest, pb_dest);
#endif

   return;
}




#ifndef WITH_FILEIO_SHARING

// If not configured for COBOL FILE SHARING dummy all funcs()

int cob_fileio_sharing_initialise(void)
{
	return(0);
}

int cob_fileio_sharing_terminate(void)
{
	return(0);
}

int cob_fileio_sharing_open_file(
	  cob_file_t *f
	, int open_mode)
{
	return(0);
}

int cob_fileio_sharing_close_file(cob_file_t *f) 
{
	return(0);
}



#else			// WITH_FILEIO_SHARING


/*
 *	F I L E   S H A R I N G   S U P P O R T   F U N C T I O N S
 *  -----------------------------------------------------------
 *
 *	
 *	Uses sentinel bits in lock file to police access to COBOL files.
 *	In the COBOL SELECT clause:
 *			SHARING WITH ALL OTHER
 *			SHARING WITH NO OTHER
 *			SHARING READ ONLY
 *	
 *	Alternatively:
 *			LOCK MODE IS EXCLUSIVE
 *	
 *	Overridden:
 *		OPEN <mode> SHARING WITH ...
 *		OPEN <mode> <file> WITH LOCK
 *	
 *	While record-locking is left to underlying file handlers (BDB, ISAM, etc),
 *	whole-file locking is implemented separately from platform dependent
 *	file-locking to provide a uniform/consistent COBOL functionality.
 *	 
 *	Each open file in a COBOL program creates/updates an entry cob_lock_t in
 *	the lock-file.
 *
 *	A READ lock is taken on a sentinel; depending on the 
 *	SHARING mode used, the sentinel is one of: 
 *		SHARE_IS_EXCLUSIVE SHARE_IS_READ_ONLY or SHARE_IS_ALL.
 *
 *	A READ lock is taken on a sentinel; depending on the 
 *	OPEN mode used, the sentinel is either:  
 *		SHARE_IS_WRITING or SHARE_IS_READING.
 *
 *	For a file OPEN to succeed, there must be no conflict between the
 *	the OPEN/SHARE modes of the file opening and the locks obtained by other
 *	COBOL programs when they opened the same physical file.
 *
 *	The data-content of the sentinels is irrelevant to its purpose.
 *	OS locks are used to ensure that we don't rely solely upon 
 *	normal file CLOSE to cancel the sentinels. 
*/





/*
 *	Called once per COBOL program execution: prepare/open the SHARING lock file.
 *	Housekeeping the lock-file:
 *		Programs SHARING lock the header record of the lock-file.
 *		If no other programs are SHARING then we initialise the lock-file.
 */

int cob_fileio_sharing_initialise(void)
{
	cob_lock_t cob_lock;
	char fid_lock[FILENAME_MAX];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: cob_fileio_sharing_initialise()\n", me);
#endif

	cob_fileio_get_dirtmp(fid_lock);
	strcat(fid_lock, "/cobol.lck");
	f_lock = fopen(fid_lock, "r+");
	if (f_lock != NULL) {
		if (0 == _fileio_get_sentinel(0)) {
			// we have EXCLUSIVE use - initialise f_lock
			fclose(f_lock);
			unlink(fid_lock);
			f_lock = NULL;
		}
	}
	if (f_lock == NULL) {
		// create COBOL SHARING lock-file & make available to all
		f_lock = fopen(fid_lock, "w+");
		if (f_lock == NULL) {
			fprintf(stderr, "%s !!! failed to open \"%s\" [erc=%d]\n"
			              , me, fid_lock, errno);
			return(-1);
		} else {
			fchmod(fileno(f_lock), DEFFILEMODE);	// ensure all users have access
			cob_lock.fileuid.inode = -1;            // write a dummy header
			fwrite(&cob_lock, sizeof(cob_lock), 1, f_lock);
			fputc('\n', f_lock); 
			fclose(f_lock);			
			f_lock = fopen(fid_lock, "r+");
		}
	}
	_fileio_set_sentinel(0);


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: exit cob_fileio_sharing_initialise() %s [%d]\n"
		              , me, fid_lock, (f_lock == NULL) ? errno : 0);
#endif

	return((f_lock == NULL) ? -1 : 0);
}




/*
 *	Called once per COBOL program execution: release SHARING lock file.
 */
int cob_fileio_sharing_terminate(void)
{
	struct flock flock;
	if (f_lock != NULL) {
		flock.l_type = F_UNLCK;
		flock.l_whence = SEEK_SET;
		flock.l_start = 0;
		flock.l_len = sizeof(cob_lock_t);
		fcntl(fileno(f_lock), F_SETLK, &flock);
		fclose(f_lock);
		f_lock = NULL;
	}
	return(0);
}






/*
 *	Returns 0 if file OPEN approved.
 *	Otherwise returns -1
 *	and errno == ESHARE if FILE SHARING would be violated.
 */ 

int cob_fileio_sharing_open_file(
	  cob_file_t *f
	, int open_mode)
{
	char tf_found;
	long rb;
	cob_lock_t cob_lock;
	struct flock flock_info;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: cob_fileio_sharing_open_file(open=%d)  share=%d fileuid=%ld\n"
		              , me, open_mode, f->share_mode, (long)f->fileuid.inode);
#endif

	f->id_share = 0;
	if (f_lock == NULL)
		return(0);
	if (f->fileuid.inode == -1)          // inode is unknown - special file?
		return(0);

	// find entry in lock-file for fileuid
	rewind(f_lock);
	tf_found = 0;
	while (1) {
		if (1 != fread(&cob_lock, sizeof(cob_lock), 1, f_lock)) {
			break;
		}
		if (!memcmp(&cob_lock.fileuid, &f->fileuid, sizeof(f->fileuid))) {
			tf_found = 1;
			break;
		}
		fgetc(f_lock);     // skip '\n'
	}
	// implicitly in COBOL when open_mode is OUTPUT we need EXCLUSIVE SHARE
	if (open_mode == COB_OPEN_OUTPUT)
		f->share_mode = COB_SHARE_EXCLUSIVE;
	if (tf_found) {
		rb = ftell(f_lock) - sizeof(cob_lock);
		// prevent a race while we examine & update the lock-entry
		flock_info.l_type = F_WRLCK;
		flock_info.l_whence = SEEK_SET;
		flock_info.l_len = 1;
		flock_info.l_start = rb + SHARE_IS_BUSY;
		fcntl(fileno(f_lock), F_SETLKW, &flock_info);
		if (!_fileio_share_access_ok(open_mode, f->share_mode, rb)) {
			flock_info.l_type =  F_UNLCK;
			fcntl(fileno(f_lock), F_SETLKW, &flock_info);
			errno = ESHARE;
			#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 2)
				fprintf(stderr, "%s: share refusal: id_share=%ld\n", me, rb);
			#endif
			return(-1);
		}
	} else {
		// append new lock-entry for this file & lock it
		fseek(f_lock, 0, SEEK_END);
		rb = ftell(f_lock);
		memcpy(&cob_lock.fileuid, &f->fileuid, sizeof(f->fileuid));
		fwrite(&cob_lock, sizeof(cob_lock), 1, f_lock);
		fputc('\n', f_lock);   // for human legibilty
		flock_info.l_type = F_WRLCK;
		flock_info.l_whence = SEEK_SET;
		flock_info.l_len = 1;
		flock_info.l_start = rb + SHARE_IS_BUSY;
		fcntl(fileno(f_lock), F_SETLKW, &flock_info);
	}
	// file is OK to open - set SHARE flags
	f->id_share = rb;
	if (f->share_mode == COB_SHARE_EXCLUSIVE)
		_fileio_set_sentinel(rb + SHARE_IS_EXCLUSIVE);
	if (f->share_mode == COB_SHARE_READ_ONLY)
		_fileio_set_sentinel(rb + SHARE_IS_READ_ONLY);
	if (f->share_mode == COB_SHARE_ALL)
		_fileio_set_sentinel(rb + SHARE_IS_ALL);
	if ((open_mode == COB_OPEN_OUTPUT)
	 || (open_mode == COB_OPEN_I_O)
	 || (open_mode == COB_OPEN_EXTEND))
		_fileio_set_sentinel(rb + SHARE_IS_WRITING);
	if ((open_mode == COB_OPEN_INPUT)
	 || (open_mode == COB_OPEN_I_O))
		_fileio_set_sentinel(rb + SHARE_IS_READING);
	// end-of-race ... unlock
	flock_info.l_type = F_UNLCK;
	fcntl(fileno(f_lock), F_SETLKW, &flock_info);
	fflush(f_lock);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: share accepted: id_share=%ld\n", me, f->id_share);
#endif

	return(0);
}




/*
 *	Call when a file is closed: remove the related locks on f_lock.
 */

int cob_fileio_sharing_close_file(cob_file_t *f) 
{
	struct flock flock;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: cob_fileio_sharing_close_file()  id_share=%ld\n", me, f->id_share);
#endif

	if (f->id_share > 0) {
		flock.l_type = F_UNLCK;
		flock.l_whence = SEEK_SET;
		flock.l_start = f->id_share;
		flock.l_len = sizeof(cob_lock_t);
		fcntl(fileno(f_lock), F_SETLK, &flock);
	}
	return(0);
}





static char _fileio_share_access_ok(
	  int open_mode
	, int share_mode
	, int rb)
{
	char tf_reading, tf_writing;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _fileio_share_access_ok(open=%d  share=%d  rb=%d)\n"
		              , me, open_mode, share_mode, rb);
#endif

	if (_fileio_get_sentinel(rb + SHARE_IS_EXCLUSIVE)) {
		// this file is currently open SHARING WITH NO OTHER
		return(0);
	}
	tf_writing = _fileio_get_sentinel(rb + SHARE_IS_WRITING);
	tf_reading = _fileio_get_sentinel(rb + SHARE_IS_READING);

	if ((tf_writing || tf_reading) && (share_mode == COB_SHARE_EXCLUSIVE)) {
		// refuse exclusive access to file already open
		return(0);
	}
	if (_fileio_get_sentinel(rb + SHARE_IS_READ_ONLY)) {
		// this file is currently open SHARING WITH READ ONLY
		if ((open_mode != COB_OPEN_INPUT)
		  || ((share_mode == COB_SHARE_READ_ONLY) && tf_writing))
			return(0);
	} else {
		// this file is currently open SHARING WITH ALL OTHER or CLOSED
		if (tf_writing && (share_mode == COB_SHARE_READ_ONLY))
			return(0);
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: ... will share\n", me);
#endif

	return(1);
}



/*
 *	Test the sentinel in file fd at relative-byte rb.
 *	Testing is accomplished by checking to see if
 *	we would be permitted to get a write-lock on the byte.
 *	If allowed then it is not locked.
 *	Return 1 if byte is locked.
 *	Return 0 if byte is not locked.
*/

static char _fileio_get_sentinel(long rb) 
{
	struct flock flock;
	flock.l_type = F_WRLCK;
	flock.l_whence = SEEK_SET;
	flock.l_start = rb;
	flock.l_len = 1;
	fcntl(fileno(f_lock), F_GETLK, &flock);
	return(flock.l_type != F_UNLCK);
}




/*
 *	Set the sentinel in file fd at relative-byte rb.
 *	A read-lock is taken on the byte.
*/

static int _fileio_set_sentinel(long rb) 
{
	int res;
	struct flock flock;
	flock.l_type = F_RDLCK;
	flock.l_whence = SEEK_SET;
	flock.l_start = rb;
	flock.l_len = 1;
	res = fcntl(fileno(f_lock), F_SETLK, &flock);
	return(res);
}

#endif			// WITH_FILEIO_SHARING



