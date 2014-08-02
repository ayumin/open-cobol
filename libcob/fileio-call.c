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





#include <dirent.h>
#include "fileio-misc.h"
#include "common.h"
#include "coblocal.h"

#include "config.h"





/*
 * fileio-call.c
 *
 *	OpenCOBOL fileio component providing a sub-set of the COBOL CALL
 *	subroutines that are associated with FILES.
 *	
 *	These functions are packaged by system.def & call.c to provide a COBOL
 *	CALL interface to functionality beyond normal COBOL.
 *
 *	There are two sets of functions:
 *		cob_sys_* are typically MicroFocus Library Routines
 *		cob_acuw_* are ACUCOBOL-GT Library Routines
 *
 *	Some annotation copied from this document:
 *	$ System Calls v1.1.1 for OC v1.1  Author: Vincent B Coen  dated 12/01/2009
 *	http://svn.wp0.org/add1/scratchpad/system-calls.txt
 *
 *
 *
 *	N O T E S   O N   R E T U R N   C O D E
 *	---------------------------------------
 *	All these routines return a C int (4-byte) value that is stored into RETURN-CODE
 *	(a field declared implicitly in the W-S of the COBOL app).
 *	The lower 2-bytes of RETURN-CODE are extracted and reversed into RETURN-STATUS
 *	which is a 2 byte short.
 *	If the routine is successful the RETURN-CODE register is set to zero.
 *	If the arguments passed to the routine are unacceptable, RETURN-COE -1 is returned.
 *	If it fails, the RETURN-CODE register contains a value which indicates the failure.
 *
 *	Where appropriate, the standard ANSI '74 file status value is returned.
 *	RETURN-STATUS can be interpreted as 2 characters. Example: "35" is file-not-found.
 *
 *	For all other cases, an extended error status is returned (9/nnn) where nnn
 *	is the (native os) runtime error number.
 *	The client should use RETURN-CODE / RETURN_STATUS and not have a RETURNING clause.
 *
 *	If RETURN-CODE is non-zero after calling a byte-stream routine, move RETURN_STATUS
 *	to a binary-short data item to process it. For example:
 *
 *		1   w-result-status binary-short.
 *		1   w-result-fs redefines w-result-status.
 *		 2  w-result-fs-1 pic x.
 *		 2  w-result-fs-2 pic x comp-x.
 *	. . .
 *	call "cob_sys_xxx_FILE" using <parameters>.
 *	if return-code not = 0
 *	   move return-status to w-result-status
 *     if (w-result-fs-1 = "9")
 *        display "!!! CALL error: native error-code = " w-result-fs-2
 *     else
 *        display "!!! CALL error: COBOL status-code = " w-result-fs
 *     end-if
 *  end-if.
 *
 */




#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-call";
#endif


// fileio-call uses a limited number of FILE STATUS KEY values
#define COB_STATUS_04_SUCCESS_INCOMPLETE 04
#define COB_STATUS_10_END_OF_FILE        10
#define COB_STATUS_14_OUT_OF_KEY_RANGE   14
#define COB_STATUS_21_KEY_INVALID        21
#define COB_STATUS_30_PERMANENT_ERROR    30
#define COB_STATUS_35_NOT_EXISTS         35



// convert the integer return-code 99 into XX
#define RETURN_CODE_XX(ret) ((((ret / 10) + '0') << 8) | ((ret % 10) + '0'))

// convert the integer return-code into 9X
#define RETURN_CODE_9N(erc) (('9' << 8) | (erc & 0xff))



static int COB_NOINLINE _call_open_file(
	  unsigned char *file_name
	, unsigned char  file_access
	, unsigned char *file_handle
	, const int file_flags);

static int _call_purge_directory(
	  char *dir_name);

static void * COB_NOINLINE _call_str_from_fld(
	  const cob_field *f);








/*
 *	The cob_sys_ I-O routines are organised into 3 groups:
 *	1.	Byte-stream I-O routines
 *	2.	File manipulation routines
 *	3.	ACU routines
 *
 *	When these routines take a file or directory name as
 *	an argument, the expanded file-name in a format acceptable
 *	to the host operating system should be used. The file-name  
 *	is NOT put through the COBOL file-name transformation.
 *
 *	Routine cob_sys_expand_filename may be used to obtain an
 *	expanded file-name from an internal file-name, using
 *	the COBOL file-name transformation.
 */




/*
 *	B Y T E _ S T R E A M   R O U T I N E S
 *
 *	Any file can be opened as a byte-stream. No logical structure
 *	is superimposed on the file-data by these routines.
 *	You simply read/write N bytes at offset O.
 *	The file_handle (int/4b) is returned by cob_sys_create_file()
 *	and cob_sys_open_file(); it is passed to all the other routines.
 */



/*
 *	Create a new file specified as file_name and open it as a
 *	byte-stream file to be accessed via cob_sys_write_file or cob_sys_read_file.
 *	If a file of the same name exists, it will be overwritten.
 *	On success: returns 0 and the file handle is returned in file_handle.
 *	On failure: returns non-zero (cf. comments at top)
 */

int cob_sys_create_file(
	  unsigned char *file_name      // space or null terminated
	, unsigned char *file_access	// 1...INPUT  2...OUTPUT   3...I-O
	, unsigned char *file_lock		// ignored
	, unsigned char *file_dev		// ignored
	, unsigned char *file_handle)   // returned fh
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_create_file(%s, %u)\n", me, file_name, *file_access);
#endif
        COB_UNUSED (file_lock);
        COB_UNUSED (file_dev);
	COB_CHK_PARMS(cob_sys_create_file, 5);
	return(_call_open_file(file_name, *file_access, file_handle, O_CREAT | O_TRUNC));
}






/*
 *	Open a file for use as a byte-stream file
 *	to be accessed via cob_sys_write_file or cob_sys_read_file.
 *	On success: returns 0 and the file handle is returned in file_handle.
 *	On failure: returns non-zero (cf. comments at top)
 */

int cob_sys_open_file(
	  unsigned char *file_name      // space or null terminated
	, unsigned char *file_access    // 1...INPUT  2...OUTPUT   3...I-O
	, unsigned char *file_lock      // ignored
	, unsigned char *file_dev       // ignored
	, unsigned char *file_handle)   // returned fh
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_open_file(%s, %u)\n", me, file_name, *file_access);
#endif

        COB_UNUSED (file_lock);
        COB_UNUSED (file_dev);
	COB_CHK_PARMS(cob_sys_open_file, 5);
	return(_call_open_file(file_name, *file_access, file_handle, 0));
}








/*
 *	Read file_len bytes of data, starting at byte number file_offset,
 *	from the byte-stream file defined by file_handle into the
 *	indicated buffer. It is assumed that buffer has capacity to store
 *	at least file_len bytes. 
 *	On success: returns 0 and if (flags & 0x80) then current file-size
 *	            is returned in file_len. 
 *	On failure:  retuns non-zero (cf. comments at top)
 *	
 *	NOTE: Earlier versions of this API gave no indication of under-read.
 *	      It does NOT return to client a count of bytes actually read.
 *	      This version treats an under-read same as EOF: returning 10.
 *	      (January 2013)
 */

int cob_sys_read_file(
	  unsigned char *file_handle
	, unsigned char *file_offset   // offset in the file at which to read (long/8b)
	, unsigned char *file_len      // number of bytes to read (<= 0 to skip read) (int/4b)
	, unsigned char *flags         // 0x80 to return fsz -> file_offset (char/1b)
	, unsigned char *buffer)       // bytes read into here
{
	long long rb;
	int fd;
	size_t cb_want, cb_read;
	int res = 0;
	struct stat st;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_read_file(0x%x)\n", me, *file_handle);
#endif

	COB_CHK_PARMS(cob_sys_read_file, 5);

	memcpy(&fd, file_handle, 4);
	memcpy(&rb, file_offset, 8);
	memcpy(&cb_want, file_len, 4);
#ifndef	WORDS_BIGENDIAN
	rb = COB_BSWAP_64(rb);
	cb_want = COB_BSWAP_32(cb_want);
#endif

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: ... rb=%ld cb=%d\n", me, (long)rb, cb_want);
#endif


	if (lseek(fd, (off_t)rb, SEEK_SET) < 0) 
		return(COB_STATUS_14_OUT_OF_KEY_RANGE);

	if (cb_want > 0) {
		cb_read = read(fd, buffer, cb_want);
		if (cb_read < 0)
			return(RETURN_CODE_9N(errno));
		if (cb_read != cb_want) 
			res = RETURN_CODE_XX(COB_STATUS_10_END_OF_FILE);
	}
	if (*flags & 0x80) {
		if (fstat(fd, &st) < 0) 
			return(RETURN_CODE_9N(errno));
		rb = st.st_size;
#ifndef	WORDS_BIGENDIAN
		rb = COB_BSWAP_64(rb);
#endif
		memcpy(file_offset, &rb, 8);
	}
	return(res);
}






/*
 *	Write file_len bytes of data from buffer to 
 *	byte-stream file defined by file_handle starting at byte
 *	number file_offset.
 *	On success: returns 0. 
 *	On failure:  retuns non-zero (cf. comments at top)
 *	
 *	NOTE: Earlier versions of this API gave no indication of under-write.
 *	      It does NOT return to client a count of bytes actually written.
 *	      This version returns 30 if under-write. (January 2013)
 */


int cob_sys_write_file(
	  unsigned char *file_handle
	, unsigned char *file_offset    // offset in the file at which to write (long/8b)
	, unsigned char *file_len       // number of bytes to write  (<= 0 set fsz to file_offset) (int/4b)
	, unsigned char *flags          // ignored
	, unsigned char *buffer)        // bytes written from here
{
	long long rb;
	int fd;
	size_t cb_togo, cb_written;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_write_file(0x%x)\n", me, *file_handle);
#endif

        COB_UNUSED (flags);
	COB_CHK_PARMS(cob_sys_write_file, 5);

	memcpy(&fd, file_handle, 4);
	memcpy(&rb, file_offset, 8);
	memcpy(&cb_togo, file_len, 4);
#ifndef WORDS_BIGENDIAN
	rb = COB_BSWAP_64(rb);
	cb_togo = COB_BSWAP_32(cb_togo);
#endif
	if (lseek(fd, (off_t)rb, SEEK_SET) < 0) 
		return(RETURN_CODE_XX(COB_STATUS_14_OUT_OF_KEY_RANGE));

	cb_written = write(fd, buffer, cb_togo);
	if (cb_written < 0)
		return(RETURN_CODE_9N(errno));
	if (cb_written != cb_togo)
		return(RETURN_CODE_XX(COB_STATUS_30_PERMANENT_ERROR));
	return(0);
}





/*
 *	Close a bytestream file previously opened by either
 *	the cob_sys_open_file or cob_sys_create_file subroutines.
 */

int cob_sys_close_file(unsigned char *file_handle)
{
	int fd;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_close_file(0x%x)\n", me, *file_handle);
#endif

	COB_CHK_PARMS(cob_sys_close_file, 1);

	memcpy(&fd, file_handle, 4);
	if (close(fd) < 0) 
		return(RETURN_CODE_9N(errno));
	return(0);
}





/*
 *	Flush any as-yet unwritten memory buffers for the (output) file
 *	whose file-handle is specified as the argument to disk.
 *	Since the file is implemented at a low-level (not streamed),
 *	this function is redundant and here for compatibility.
 */

int cob_sys_flush_file(unsigned char *file_handle)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_flush_file(0x%x)\n", me, *file_handle);
#endif

	COB_CHK_PARMS(cob_sys_flush_file, 1);

	return(0);
}









/*
 *	F I L E   M A N I P U L A T I O N   R O U T I N E S
 */



/*
 *	Make directory-path (an alphanumeric literal or identifier)
 *	the current directory.
 */

int cob_sys_change_dir(unsigned char *dir)
{
	char *fn;
	int res;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_change_dir(%s)\n", me, dir);
#endif

	COB_CHK_PARMS(cob_sys_change_dir, 1);

	if (!APP_MODULE->cob_procedure_params[0]) 
		return(-1);
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	res = chdir(fn);
	if (res != 0) {
    	res = (errno == 2) ? RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS)
		                   : RETURN_CODE_9N(errno);
	}
	free(fn);
	return(res);
}






/*
 *	Retrieve the size of the file specified as the file-name argument
 *	(an alphanumeric literal or identifier) and the date/time that
 *	file was last modified.
 */

int cob_sys_check_file_exist(
	  unsigned char *file_name
	, unsigned char *file_info)          // >= 16 bytes
{
	char *fn;
	struct tm *tm;
	long long sz;
	struct stat	st;
	short y;
	char d, m, hh, mm, ss;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_check_file_exist(%s)\n", me, file_name);
#endif
	COB_CHK_PARMS(cob_sys_check_file_exist, 2);

	if (!APP_MODULE->cob_procedure_params[0]) 
		return(-1);
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	if (stat(fn, &st) < 0) {
		free(fn);
		return(RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS));
	}
	free(fn);
	sz = st.st_size;
	tm = localtime(&st.st_mtime);
	d = (char)tm->tm_mday;
	m = (char)tm->tm_mon + 1;
	y = tm->tm_year + 1900;
	hh = (char)tm->tm_hour;
	mm = (char)tm->tm_min;
	ss = (char)tm->tm_sec;

#ifndef WORDS_BIGENDIAN
	sz = COB_BSWAP_64(sz);
	y = COB_BSWAP_16(y);
#endif
	memcpy(file_info, &sz, 8);
	file_info[8] = d;
	file_info[9] = m;
	memcpy(file_info+10, &y, 2);
	file_info[12] = hh;
	file_info[13] = mm;
	file_info[14] = ss;
	file_info[15] = 0;
	return(0);
}





/*
 *	Copy file src-file-path to dest-file-path as if it were done
 *	via the “CP” (Unix) or “COPY” (Windows) command.
 *	This is implemented as open()...{read()...write()}n ...close().
 *	Returns: 0...success: file was deleted.
 *	        -1...parameters error
 *	       128...failed.
 */

int cob_sys_copy_file(
	  unsigned char *filename_ip
	, unsigned char *filename_op)
{
	char *fid_ip, *fid_op, *bfr;
	int res, fd_ip, fd_op;
	size_t cb_read, cb_write;

#ifdef	O_BINARY
	int	flag = O_BINARY;
#else
	int	flag = 0;
#endif

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_copy_file(%s, %s)\n", me, filename_ip, filename_op);
#endif
	COB_CHK_PARMS(cob_sys_copy_file, 2);

	if (!APP_MODULE->cob_procedure_params[0] 
		|| !APP_MODULE->cob_procedure_params[1])
		return(-1);

	fid_ip = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	flag |= O_RDONLY;
	fd_ip = open(fid_ip, flag, 0);
	free(fid_ip);
	if (fd_ip < 0) {
		return(RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS));
	}
	fid_op = _call_str_from_fld(APP_MODULE->cob_procedure_params[1]);
	flag &= ~O_RDONLY;
	flag |= O_CREAT | O_TRUNC | O_WRONLY;
	fd_op = open(fid_op, flag, 0660);
	free(fid_op);
	if (fd_op < 0) {
		close(fd_ip);
		return(RETURN_CODE_XX(COB_STATUS_30_PERMANENT_ERROR));
	}
	bfr = cob_malloc(BUFSIZ);
	while(1) {
		cb_read = read(fd_ip, bfr, BUFSIZ);
		if (cb_read == 0) {
			res = 0;         // EOF: success
			break;
		}
		if (cb_read < 0) {
			res = RETURN_CODE_9N(errno);
			break;
		}
		cb_write = write(fd_op, bfr, cb_read);
		if (cb_write != cb_read) {
			res = RETURN_CODE_9N(errno);
			break;
		}
	}
	free(bfr);
	close(fd_ip);
	close(fd_op);
	return(res);
}





/*
 *	Create a new directory – the name of which is supplied
 *	as the argument (an alphanumeric literal or identifier).
 *	Only the lowest-level directory (last) in the specified
 *	path can be created – all others must already exist.
 */ 

int cob_sys_create_dir(unsigned char *dir)
{
	char *fn;
	int res;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_create_dir(%s)\n", me, dir);
#endif
	COB_CHK_PARMS(cob_sys_create_dir, 1);

	if (!APP_MODULE->cob_procedure_params[0]) {
		return(-1);
	}
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
#ifdef	_WIN32
	res = mkdir(fn);
#else
	res = mkdir(fn, 0770);
#endif
	if (res != 0)
		res = RETURN_CODE_9N(errno);
	free(fn);
	return(res);
}






/*
 *	Delete an empty directory – the name of which is supplied
 *	as the argument (an alphanumeric literal or identifier).
 *	Only the lowest-level directory in the path will be deleted.
 *	The directory must be empty.
 *	To delete recursively all the contents of a directory
 *	see cob_sys_purge_dir.
 */

int cob_sys_delete_dir(unsigned char *dir)
{
	char *fn;
	int res;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_delete_dir(%s)\n", me, dir);
#endif

	COB_CHK_PARMS(cob_sys_delete_dir, 1);

	if (!APP_MODULE->cob_procedure_params[0]) {
		return(-1);
	}
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	res = rmdir(fn);
	if (res != 0) {
    	res = (errno == 2) ? RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS)
		                   : RETURN_CODE_9N(errno);
	}
	free(fn);
	return(res);
}






/*
 *	Delete the file specified by the argument (an 
 *	alphanumeric literal or identifier) just as if that
 *	were done using the “RM” (Unix) or “ERASE” (Windows) command.
 *	Returns: 0...success: file was deleted.
 *	        -1...parameters error
 *	    errrno...failed.
 */

int cob_sys_delete_file (unsigned char *file_name)
{
	char *fn;
	int	res;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_delete_file(%s)\n", me, file_name);
#endif

	COB_CHK_PARMS(cob_sys_delete_file, 1);

	if (!APP_MODULE->cob_procedure_params[0]) {
		return(-1);
	}
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	res = unlink(fn);
	if (res != 0) {
    	res = (errno == 2) ? RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS)
		                   : RETURN_CODE_9N(errno);
	}
	free(fn);
	return(res);
}




/*
 *	Run filename_ip through the COBOL file-name transformation
 *	and return the result in filename_op.
 *	Assume the COBOL source contains "ASSIGN TO <fid>" or 
 *	"VALUE OF FILE-ID <fid>", then use 
 *	"CALL cob_sys_expand_filename using <fid>, <path>"
 *	to get the actual, fully expanded name in <path> of the file 
 *	that would actually be opened by an OPEN statement.
 *	If the expanded name contans spaces, it will be quoted.  
 */

int cob_sys_expand_filename(
	  unsigned char *filename_ip
	, unsigned char *cb_filename_max    // int
	, unsigned char *filename_op)
{
	int cb_max, cb_fid;
	int	tf_quote;
	char *fn, *fid_exp;

	memcpy(&cb_max, cb_filename_max, 4);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_expand_filename(%s, %d)\n", me, filename_ip, cb_max);
#endif

	COB_CHK_PARMS(cob_sys_get_current_dir, 3);

	if (cb_max < 1)
		return(RETURN_CODE_9N(128));

	memset(filename_op, ' ', cb_max);
	fid_exp = cob_malloc(cb_max + 10);  // +10 in order to check overflow
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	cob_fileio_locate_file(fn, fid_exp, cb_max + 10);
	free(fn);
	cb_fid = strlen(fid_exp);
	tf_quote = (strchr(fid_exp, ' ') != NULL) ? 1 : 0;
	if ((cb_fid + (tf_quote ? 2 : 0)) > cb_max) {
		free(fid_exp);
		return(RETURN_CODE_9N(128));
	}
	if (tf_quote) {
		*filename_op = '"';
		memcpy(filename_op+1, fid_exp, cb_fid);
		*(filename_op + cb_fid + 1) = '"';
	} else {
		memcpy(filename_op, fid_exp, cb_fid);
	}
	free(fid_exp);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: cob_sys_expand_filename() -> %*s\n"
		      , me, tf_quote ? cb_fid+2 : cb_fid, filename_op);
#endif

	return(0);
}






/*
 *	Retrieve the fully-qualified pathname of the current directory,
 *	saving up to cb_name_max characters of that name into
 *	the specified buffer. If the directory name contans spaces,
 *	it will be quoted.
 *	NOTE: Original implementation used getcwd(NULL, 0).
 *	      LINUX doc (for both "man 2 getcwd" and "man 3 getcwd")
 *	      states:
 *	      "If buf is NULL, the behaviour of getcwd() is undefined."
 */

int cob_sys_get_current_dir(
	  unsigned char *flags			// int must be 0
	, unsigned char *cb_name_max    // int
	, unsigned char *pb_name)
{
	char cwd[FILENAME_MAX];
	size_t cb_cwd;
	int cb_max;
	int	tf_quote;

	memcpy(&cb_max, cb_name_max, 4);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_get_current_dir(%d)\n", me, cb_max);
#endif

	COB_CHK_PARMS(cob_sys_get_current_dir, 3);

	if (cb_max < 1)
		return(RETURN_CODE_9N(128));
	if (*flags != 0)
		return(RETURN_CODE_9N(129));
	memset(pb_name, ' ', cb_max);
	if (NULL == getcwd(cwd, FILENAME_MAX))
		return(RETURN_CODE_9N(errno));

	cb_cwd = strlen(cwd);
	tf_quote = (strchr(cwd, ' ') != NULL) ? 1 : 0;
	if ((cb_cwd + (tf_quote ? 2 : 0)) > cb_max)
		return(RETURN_CODE_9N(128));
	if (tf_quote) {
		*pb_name = '"';
		memcpy(pb_name+1, cwd, cb_cwd);
		*(pb_name + cb_cwd + 1) = '"';
	} else {
		memcpy(pb_name, cwd, cb_cwd);
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: cob_sys_get_current_dir() -> %*s\n"
		      , me, tf_quote ? cb_cwd+2 : cb_cwd, pb_name);
#endif

	return(0);
}







/*
 *	Return the value of var_name from the environment or
 *	COB_STATUS_21_KEY_INVALID if no such variable.
 */

int cob_sys_get_envvar(
	  unsigned char *var_name
	, unsigned char *cb_value_max    // int
	, unsigned char *var_value)
{
	char *vn, *val;
	int	cb, cb_max;

	memcpy(&cb_max, cb_value_max, 4);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_get_envvar(%s, %d)\n", me, var_name, cb_max);
#endif

	COB_CHK_PARMS(cob_sys_get_envvar, 3);

	if (!APP_MODULE->cob_procedure_params[0]) {
		return(-1);
	}
	vn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	val = getenv(vn);
	free(vn);
	if (val == NULL)
		return(RETURN_CODE_XX(COB_STATUS_21_KEY_INVALID));
	cb = strlen(val);
	if (cb_max < cb)
		return(RETURN_CODE_9N(128));
	memset(var_value, ' ', cb_max);
	memcpy(var_value, val, cb);
	return(0);
}




/*
 *	Delete all files in a directory – the name of which is supplied
 *	as the argument (an alphanumeric literal or identifier).
 *	The contents of the named directory (both sub-directories
 *	and files) are deleted. The directory itself may then be
 *	removed by CALL cob_sys_delete_dir.
 *	On encountering any file that cannot be deleted the process
 *	continues but the parent directory will not be deleted.
 */

int cob_sys_purge_dir(unsigned char *dir_name)
{
	char *fn;
	int res;
	struct stat st;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_purge_dir(%s)\n", me, dir_name);
#endif

	COB_CHK_PARMS(cob_sys_purge_dir, 1);

	if (!APP_MODULE->cob_procedure_params[0]) {
		return(-1);
	}
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	if (stat(fn, &st) < 0) {
		free(fn);
		return(RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS));
	}
	res = _call_purge_directory(fn);
	free(fn);
	if (res == -1)
		res = RETURN_CODE_9N(errno);
	else if (res != 0)
		res = RETURN_CODE_XX(COB_STATUS_04_SUCCESS_INCOMPLETE);
	return(res);
}






/*
 * Rename the file filename_ip to filename_op.
 */

int cob_sys_rename_file(
	  unsigned char *filename_ip
	, unsigned char *filename_op)
{
	char *fid_ip;
	char *fid_op;
	int	res;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_sys_rename_file(%s, %s)\n", me, filename_ip, filename_op);
#endif
	COB_CHK_PARMS(cob_sys_rename_file, 2);

	if (!APP_MODULE->cob_procedure_params[0]
		|| !APP_MODULE->cob_procedure_params[1]) {
		return(-1);
	}
	fid_ip = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	fid_op = _call_str_from_fld(APP_MODULE->cob_procedure_params[1]);
	res = rename(fid_ip, fid_op);
	if (res != 0) {
    	res = (errno == 2) ? RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS)
		                   : RETURN_CODE_9N(errno);
	}
	free(fid_ip);
	free(fid_op);
	return(res);
}






/*
 *	Report the current exception by calling the fileio default error handler.
 *	If no exception has been thrown: simply returns.
 */

int cob_sys_report_io_exception(void)
{
	if (COB_EXC_THROWN)
		cob_default_error_handle();
	return(0);
}



/*
 *	Start/stop the TRACE mechanism in fileio.
 *	To stop: trace_level = 0
 *	To start: trace_level > 0
 *	If COBOL not configured with WITH_FILEIO_TRACE
 *	then this call is ignored.
 */
int cob_sys_trace_fileio(unsigned char *new_trace_level)
{
#ifdef  WITH_FILEIO_TRACE

	int itl;
	if ((*new_trace_level < '0') || (*new_trace_level > '9')) {
		itl = 9;
	} else {
		itl = *new_trace_level - '0';
	}
	if (itl == 0) {
		if (trace_level != 0) {
			fprintf(stderr, "%s %s :: trace terminated by request.\n\n"
			      , me, cob_fileio_get_now()); 
			fflush(stderr);
			trace_level = 0;
		}
	} else {
		if (trace_level == 0) {
			fprintf(stderr, "\n\n%s %s :: trace restarted by request.\n"
			      , me, cob_fileio_get_now()); 
		}
		trace_level = itl;
	}
#endif

	return(0);
}

/*
 *	A C U   R O U T I N E S
 */



// FORMERLY:     cob_acuw_mkdir

int cob_sys_mkdir(unsigned char *dir)
{
	COB_CHK_PARMS(C$MAKEDIR, 1);

	if (app_globals->cob_call_params < 1)
		return(RETURN_CODE_9N(128));

	if (0 != cob_sys_create_dir(dir))	
		return(RETURN_CODE_9N(128));
	return(0);
}





// FORMERLY:     cob_acuw_chdir

int cob_sys_chdir(
	  unsigned char *dir
	, unsigned char *status)
{
	int	res;

	COB_CHK_PARMS(C$CHDIR, 2);

	if (app_globals->cob_call_params < 2)
		return(RETURN_CODE_9N(128));

	res = cob_sys_change_dir(dir);
	if (res != 0) 
		res = 128;
	cob_set_int(APP_MODULE->cob_procedure_params[1], res);
	return((res == 0) ? 0 : RETURN_CODE_9N(res));
}




// FORMERLY:     cob_acuw_copyfile

int cob_sys_copyfile(
	  unsigned char *fname1
	, unsigned char *fname2
	, unsigned char *file_type)
{
	/* RXW - Type is not yet evaluated */

	COB_CHK_PARMS(C$COPY, 3);

	if (app_globals->cob_call_params < 3)
		return(RETURN_CODE_9N(128));

	if (0 != cob_sys_copy_file(fname1, fname2))
		return(RETURN_CODE_9N(128));
	return(0);
}




// FORMERLY:     cob_acuw_file_info

int cob_sys_file_info(
	  unsigned char *file_name
	, unsigned char *file_info)
{
	char *fn;
	struct tm *tm;
	unsigned long long sz;
	unsigned int dt;
	short y;
	short d, m, hh, mm, ss;
	struct stat st;

	COB_CHK_PARMS(C$FILEINFO, 2);

	if (app_globals->cob_call_params < 2 || !APP_MODULE->cob_procedure_params[0]) 
		return(RETURN_CODE_9N(128));

	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	if (stat(fn, &st) < 0) {
		free(fn);
		return(RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS));
	}
	free(fn);
	sz = st.st_size;
	tm = localtime(&st.st_mtime);
	d = tm->tm_mday;
	m = tm->tm_mon + 1;
	y = tm->tm_year + 1900;
	hh = tm->tm_hour;
	mm = tm->tm_min;
	ss = tm->tm_sec;

#ifndef WORDS_BIGENDIAN
	sz = COB_BSWAP_64(sz);
#endif
	memcpy(file_info, &sz, 8);
	dt = (y * 10000) + (m * 100) + d;
#ifndef WORDS_BIGENDIAN
	dt = COB_BSWAP_32(dt);
#endif
	memcpy(file_info + 8, &dt, 4);
	dt = (hh * 1000000) + (mm * 10000) + (ss * 100);
#ifndef WORDS_BIGENDIAN
	dt = COB_BSWAP_32(dt);
#endif
	memcpy(file_info + 12, &dt, 4);
	return(0);
}





// FORMERLY:     cob_acuw_file_delete

int cob_sys_file_delete(
	  unsigned char *file_name
	, unsigned char *file_type)
{
	/* RXW - Type is not yet evaluated */
        COB_UNUSED (file_type);
	COB_CHK_PARMS(C$DELETE, 2);

	if (app_globals->cob_call_params < 2 || !APP_MODULE->cob_procedure_params[0]) 
		return(RETURN_CODE_9N(128));

	if (0 != cob_sys_delete_file(file_name))
		return(RETURN_CODE_9N(128));
	return(0);
}













/*
 *	Open a file for use as a byte-stream file
 *	to be accessed via cob_sys_write_file or cob_sys_read_file.
 *	On success: the file handle is returned in file_handle.
 */


static int COB_NOINLINE _call_open_file(
	  unsigned char *file_name
	, unsigned char  file_access	// 1...INPUT  2...OUTPUT   3...I-O
	, unsigned char *file_handle
	, const int file_flags)
{
	char	*fn;
#ifdef O_BINARY
	int	flag = O_BINARY;
#else
	int	flag = 0;
#endif
	int	fd;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _call_open_file(%s, %u, 0x%x)\n", me, file_name, file_access, file_flags);
#endif

	memset(file_handle, -1, 4);
	if (!APP_MODULE->cob_procedure_params[0]) 
		return(-1);

	flag |= file_flags;
	switch(file_access) {
		case 1:
			flag |= O_RDONLY;
			break;
		case 2:
			flag |= O_CREAT | O_TRUNC | O_WRONLY;
			break;
		case 3:
			flag |= O_RDWR;
			break;
		default:
			return(-1);
	}
	fn = _call_str_from_fld(APP_MODULE->cob_procedure_params[0]);
	fd = open(fn, flag, 0660);
	free(fn);
	if (fd < 0) {
		if (errno == ENOENT)
			return(RETURN_CODE_XX(COB_STATUS_35_NOT_EXISTS));
		return(RETURN_CODE_9N(errno));
	}
	memcpy(file_handle, &fd, 4);
	return(0);
}




/*
 *	Delete the contents of the named directory.
 *	Returns:
 *		 0 ... success
 *		 1 ... one or more directory members could not be deleted.
 *		-1 ... error encountered cf. errno.
 */

#define EXIT_FUNC(res) if (cwd != NULL) free(cwd); return((res < 0) ? -1 : res); 

static int _call_purge_directory(char *dir_name)
{
	int res;
	size_t cb_max_dir_name = 1024;
	char *cwd = NULL;
	DIR* dir;
	struct dirent* ent;
	struct stat fstat;
 
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _call_purge_directory(%s)\n", me, dir_name);
#endif
	dir = opendir(dir_name);
	if (dir == NULL) {
		EXIT_FUNC(-1);
	}
	cwd = cob_malloc(cb_max_dir_name);
	if ((NULL == getcwd(cwd, cb_max_dir_name))
		|| (0 != chdir(dir_name))) {
		EXIT_FUNC(-2);     
	}

	// Phase 1: delete each entry in directory
	while (NULL != (ent = readdir(dir))) {
		if (!strcmp(ent->d_name, ".")
			|| !strcmp(ent->d_name, ".."))
			continue;
		if (0 != stat(ent->d_name, &fstat)) {
			EXIT_FUNC(-3);
		}
		if (fstat.st_mode & S_IFDIR) {
			if (0 == _call_purge_directory(ent->d_name)) {
				if (0 != rmdir(ent->d_name)) {
					EXIT_FUNC(-4);
				}
			}
		} else {
			if (0 != unlink(ent->d_name)) {
				EXIT_FUNC(-5);
			}
		}
	}
	rewinddir(dir);
	// Phase 2: check directory is now empty
	res = 0;
	while ((NULL != (ent = readdir(dir))) && (res == 0)) {
		if (strcmp(ent->d_name, ".")
			&&  strcmp(ent->d_name, "..")) { 
			EXIT_FUNC(1);
		}
	}
	closedir(dir);
	if (0 != chdir(cwd)) {
		EXIT_FUNC(-6);
	}
	EXIT_FUNC(0);       
}

#undef EXIT_FUNC



/*
 *	Extract a string from a parameter-field.
 *	Field param is interpreted as pointing to a left-aligned
 *	string, which may be quoted or not. Trailing spaces are truncated.
 *
 *	Returns: a pointer to the string in malloc'd space. It is
 *	the client's responsibility to free() the space when finished.
 */

static void * COB_NOINLINE _call_str_from_fld(
	  const cob_field *param)
{
	void *str;
	unsigned char *pb, c;
	int ix, cb;
	char tf_in_quotes = 0;

	if (param == NULL) {
		return(cob_malloc(1));
	}
	// find right-most non-empty char
	for (ix = (int)param->size - 1; ix >= 0; ix--) {
		if ((param->data[ix] != ' ') && (param->data[ix] != 0)) {
			break;
		}
	}
	cb = ix + 1;
	// cb is count of bytes in param string. 
	str = cob_malloc((size_t)(cb + 1));
	pb = str;
	for (ix = 0; ix < cb; ix++) {
		if (param->data[ix] == '"') {
			tf_in_quotes = !tf_in_quotes;
			continue;
		}
		*pb++ = c = param->data[ix];
		if (tf_in_quotes) 
			continue;
		if ((c == ' ') || (c == 0)) {
			*(pb-1) = 0;
			break;
		}
		
	}
	return(str);
}


