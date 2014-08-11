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
 *    This entire module is excluded unless configured with one of
 *    WITH_INDEXED_CISAM   WITH_INDEXED_DISAM   WITH_INDEXED_VBISAM
 *    =============================================================
 */

#if defined(WITH_INDEXED_CISAM) || defined(WITH_INDEXED_DISAM) || defined(WITH_INDEXED_VBISAM)



/*
 * fileio-isam-xisam.c
 *
 * OpenCOBOL fileio interface to CISAM DISAM and VBISAM handling
 * ORGANIZATION INDEXED files.
 *
 *
*/



#include "fileio-isam.h"

#ifdef WITH_INDEXED_CISAM
#include "cisam.h"

#define isfullclose(isfd) isclose(isfd)
#define ISERASE(fid) iserase((char *)fid)
#define ISOPEN(fid, mode) isopen((char *)fid, mode)
#define ISBUILD(fid, rsz, key0, mode) isbuild(fid, rsz, key0, mode)
#endif

#ifdef WITH_INDEXED_DISAM
#include "disam.h"

#define isfullclose(isfd) isclose(isfd)
#define ISERASE(fid) iserase((char *)fid)
#define ISOPEN(fid, mode) isopen((char *)fid, mode)
#define ISBUILD(fid, rsz, key0, mode) isbuild(fid, rsz, key0, mode)
#endif

#ifdef WITH_INDEXED_VBISAM
#include "vbisam.h"

#ifndef VB_CHAR
#define VB_CHAR char
#endif
 
#define ISERASE(fid) iserase((VB_CHAR  *)fid)
#define ISOPEN(fid, mode) isopen((const VB_CHAR *)fid, mode)
#define ISBUILD(fid, rsz, key0, mode) isbuild((const VB_CHAR *)fid, rsz, key0, mode)

#endif

#define USE_WHOLE_KEY 0			// flags non-partial key used


/*
 * Fields required by ISAM file-handler (extra to struct cob_file).
 * Struct isam_file is malloc'd in cob_fileio_isam_open()
 * and is free'd when COBOL file is closed (implicitly or explicitly).
 *
 * keys[] stores the key_descriptors in a form native to the ISAM handler.
 * Only the keys referenced in the COBOL source are loaded into key[] (which
 * may be a sub-set of the keys declared to the ISAM handler) and they are
 * ordered same as in the COBOL source.
 * ix_isam_key[n] is ordinal number of each ISAMkey matching each COBOL key [n].
 *
 * Each COBOL INDEXED file is represented by:
 *		isfd .......... which is used to read, delete, etc out-of-phase;
 *		                all locks are taken on this file.
 *		isfd_cursor ... which is positioned at the current record;
 *		                it is advanced and retreated as records are read.
 *
 * SPARSE KEYS: not yet implemented (NYI)
*/


typedef struct {
	struct keydesc   kd;                         // key descriptor cf. keydesc in c|d|vbisam.h
	int              ix_isam_key;                // ordinal of ISAM key corresponding to COBOL key
} xkey_t;




typedef struct {
	cob_file_t      *cob_file;                   // corresponding file (SELECT/FD) in COBOL program
	char            *fid_idx;                    // fully-pathed external name of index-file
	char            *fid_dat;                    // fully-pathed external name of data-file
	int              isfd;                       // file-handle assigned by ISAM Handler on open() cf. notes above
	int              isfd_cursor;                // file-handle assigned by ISAM Handler on open() cf. notes above
	int              cb_key_max;                 // size of largest key
	int              cnt_key;                    // number of indexes referenced in COBOL - keys[cnt_key]
	xkey_t           *keys;                      // key descriptors (malloc)

	// current state:
	int              recnum;                     // ISAM (identity) value for current record
	char            *pb_record;                  // record workspace
	int              ix_key;                     // index in use (0..cnt_key-1)
	char            *key_p_r;                    // primary-key value of last record read
	char            *key_p_w;                    // primary-key value of last record written
	char            *key_p_d;                    // primary-key value of last record deleted
	char            *key_x_r;                    // value of key used on last read
} isam_file_t;





#if defined(WITH_INDEXED_VBISAM) && defined(VB_RTD)
	// Since VBISAM 2.1.1: access to isrecnum iserrno etc is no longer global
	vb_rtd_t *vbisam_rtd;

#define ISRECNUM vbisam_rtd->isrecnum
#define ISERRNO  vbisam_rtd->iserrno
#define ISRECLEN vbisam_rtd->isreclen

#else
	// CISAM | DISAM | VBISAM (early) these variables are simple globals
#define ISRECNUM isrecnum
#define ISERRNO  iserrno
#define ISRECLEN isreclen

#endif


#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-isam-xisam";
#endif





#define THROW_EXC(exc) \
	{	cob_fileio_throw_exc(f, exc, COB_IO_CONTEXT_FILEIO_INDEXED); return(-1); }


// Return value from ISAM functions is either: 
// >= 0 ... successful
// < 0 .... failed - error-code in ISERRNO

#define THROW_EXC_ISAM(exc) \
	{	cob_fileio_throw_ext(f, _isam_map_errno(ISERRNO, exc), COB_IO_CONTEXT_FILEIO_INDEXED \
			, COB_IO_REALM_BDB, ISERRNO, _xisam_get_error_text(ISERRNO)); \
		return(-1); \
	}


// LINUX errno 1..256
#define THROW_EXC_OS(exc) \
	{	cob_fileio_throw_ext(f, _isam_map_errno(errno, exc), COB_IO_CONTEXT_FILEIO_INDEXED \
			, COB_IO_REALM_OS, errno, strerror(errno)); \
		return(-1); \
	}





static int _xisam_open(
     cob_file_t *f
   , const int mode); 


static isam_file_t* _xisam_get_handle(cob_file_t *f);

static void _xisam_free_handle(cob_file_t *f);

static int _xisam_read_next(
     isam_file_t *f_isam
   , void *record);

static int _xisam_read_prior(
     isam_file_t *f_isam
   , void *record);

static int _xisam_retreat(
     isam_file_t *f_isam
   , void *record
   , int cond);

static int _xisam_copy_key_descriptors(
     cob_file_t *f
   , isam_file_t *f_isam);

static int _xisam_create_dset(
     isam_file_t *f_isam
   , char *root_name
   , int rsz
   , int mode);

static int _xisam_match_keys(isam_file_t *f_isam);

static int _xisam_extract_key(
     isam_file_t *f_isam
   , int ix_cob_key
   , const void *pb_rec
   , void *ret_key_value);

static int _xisam_reverse_extract_key(
     isam_file_t *f_isam);
	  
static int _xisam_keycmp(
     isam_file_t *f_isam
   , int ix_cob_key
   , const void *pb_rec
   , const void *pb_key);


#ifdef WITH_FILEIO_TRACE
static char *_xisam_dump_keys(
     isam_file_t *f_isam);
#endif



static int _xisam_translate_lock_mode(
     cob_file_t *f
   , int cob_lock);

static int _isam_map_errno(
     int errnum
   , int erc_generic);

static char *_xisam_get_error_text(
     int errnum);







/*
 * Called once at program BOJ: initialise variables.
 *
 * Environmental variables referenced [default]:
 * NONE
*/

int cob_fileio_isam_initialise()
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1) {
		fprintf(stderr, "%s: cob_fileio_isam_initialise() using: %s\n", me, 
#ifdef WITH_INDEXED_CISAM
				"CISAM"
#endif
#ifdef WITH_INDEXED_DISAM
				"DISAM"
#endif
#ifdef WITH_INDEXED_VBISAM
				"VBISAM"
#endif

	);}
#endif

#if defined(WITH_INDEXED_VBISAM) && defined(VB_RTD)
	vbisam_rtd = VB_GET_RTD;
#endif

	return(0);
}





/*
 * Called once at program EOJ: release resources.
 *
*/

int cob_fileio_isam_terminate()
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_terminate()\n", me);
#endif

#ifdef WITH_INDEXED_CISAM
	iscleanup();
#endif

	return(0);
}







/*
 * Open an ISAM .idx and .dat dataset.
 * This function wrapper is to ensure resources are released if file-open fails.
 * 
*/

int cob_fileio_isam_open(cob_file_t *f
                       , const int mode)
{
	int fs;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
                fprintf(stderr, "%s: cob_fileio_isam_open(%s open_mode=%d) share_mode=%d lock_mode=%d\n"
                              , me, f->select_name, mode, f->share_mode, f->lock_mode);
#endif

	fs = _xisam_open(f, mode);
	if (fs != 0) {
		_xisam_free_handle(f);
	}
	return(fs);
}




/*
 * Open an ISAM .idx and .dat dataset.
 *
 * Memory may be malloc'd for the file handle.
 * This function is wrapped to ensure resources are released if 
 * we exit prematurely.
 * 
 *	.idx            .dat        INPUT                    OUTPUT or I-O	
 *	exists          exists      SUCCESS                  SUCCESS
 *	missing         exists      Note 1                   COB_IOEXC_ISAM_DIVORCED
 *	exists          missing     Note 1                   COB_IOEXC_ISAM_DIVORCED
 *	missing         missing     Note 1                   COB_STATUS_00_SUCCESS
 *
 *  Note 1: if f->flag_optional SUCCESS + optional-file-missing 
 *          else COB_IOEXC_FILE_MISSING
 *  Note 2: if OUTPUT: any existing dataset is overwritten (without first opening it).
 *
*/

static int _xisam_open(
     cob_file_t *f
   , const int mode) 
{
	int res;
	int tf_exists_idx = 0, tf_exists_dat = 0;
	int lock_mode = 0;
	int rsz_mode = 0;
	isam_file_t *f_isam;
	struct stat st;


#if defined(ISVARLEN)
	if (f->record_min != f->record_max) {
		rsz_mode = ISVARLEN;
		ISRECLEN = f->record_min;
	}
#endif

	f_isam = _xisam_get_handle(f);
	f_isam->fid_idx = cob_malloc(strlen(f->fid) + 5);
	sprintf(f_isam->fid_idx, "%s.idx", f->fid);
	tf_exists_idx = (stat(f_isam->fid_idx, &st) == 0);
	f_isam->fid_dat = cob_malloc(strlen(f->fid) + 5);
	sprintf(f_isam->fid_dat, "%s.dat", f->fid);
	tf_exists_dat = (stat(f_isam->fid_dat, &st) == 0);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: index-file '%s' %sfound.  data-file '%s' %sfound.\n"
		              , me
		              , f_isam->fid_idx, tf_exists_idx ? " " : "NOT "
		              , f_isam->fid_dat, tf_exists_dat ? " " : "NOT ");
#endif


	if (0 != _xisam_copy_key_descriptors(f, f_isam))
		return(-1);

	if (tf_exists_idx && tf_exists_dat) {
		// check if file can be shared
		f->fileuid.inode = st.st_ino; 
    		if (0 != cob_fileio_sharing_open_file(f, mode)) {
			THROW_EXC(COB_IOEXC_FSHARE_LOCK);  
		}
	}
	lock_mode = ISMANULOCK;
	if ((f->lock_mode == COB_LOCK_AUTOMATIC) && (mode != COB_OPEN_INPUT)) 
		lock_mode = ISAUTOLOCK;

	switch(mode) {
	case COB_OPEN_INPUT:
		if (!tf_exists_idx || !tf_exists_dat) {
			if (f->flag_optional) {
				f->tf_optional_is_missing = 1;
				return(0);
			}
			THROW_EXC(COB_IOEXC_FILE_MISSING);
		}
		f_isam->isfd = ISOPEN(f->fid, ISINPUT | lock_mode | rsz_mode);
		break;
	case COB_OPEN_OUTPUT:
		if (tf_exists_idx && tf_exists_dat) {
			// DISAM iserase (sometimes) returns -1 and ISERRNO = 0 ... but file is removed anyway
			if ((ISERASE(f->fid) != 0) && (ISERRNO != 0)) {
				THROW_EXC_ISAM(COB_IOEXC_ISAM_DROP);
			}
		} else if (tf_exists_idx != tf_exists_dat) {
			THROW_EXC(COB_IOEXC_ISAM_DIVORCED);
		}
		if (0 != _xisam_create_dset(f_isam, f->fid, f->record_max, ISOUTPUT | rsz_mode)) {
			THROW_EXC_ISAM(COB_IOEXC_ERROR);
		}
		f_isam->isfd = ISOPEN(f->fid, ISINOUT | lock_mode | rsz_mode);
		break;
	case COB_OPEN_I_O:
		// fall thru
	case COB_OPEN_EXTEND:
		if (!tf_exists_idx && !tf_exists_dat) {
			if (!f->flag_optional) {
				THROW_EXC(COB_IOEXC_FILE_MISSING);
			}
			if (0 != _xisam_create_dset(f_isam, f->fid, f->record_max, ISINOUT | rsz_mode)) {
				THROW_EXC_ISAM(COB_IOEXC_ERROR);
			}
			f->tf_optional_was_created = 1;
		} else if (tf_exists_idx != tf_exists_dat) {
			THROW_EXC(COB_IOEXC_ISAM_DIVORCED);
		} 
		f_isam->isfd = ISOPEN(f->fid, ISINOUT | lock_mode | rsz_mode);
		break;
	}
	if (f_isam->isfd == -1) {
		THROW_EXC_ISAM(COB_IOEXC_ISAM_DROP);
	}
	res = _xisam_match_keys(f_isam);
	if (res == -1) {
		#ifdef  WITH_FILEIO_TRACE
		if (trace_level > 2)
			fprintf(stderr, "%s: failed to get key descriptors from handler ierrno=%d\n", me, ISERRNO);
		#endif
		THROW_EXC(COB_IOEXC_ISAM_BAD_DICT);
	}
	if (res == 1) {
		/*
		 * Only the COBOL primary-key [0] is mandated to match isam-handler.
		 * Missing/mismatched COBOL secondary keys set f_isam->ix_isam_key[ix] = -1.
		 * This defers f-status errors from OPEN to 1st START/READ which throw status = "9N".
		*/
		if (f_isam->keys[0].ix_isam_key == -1) {
			#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 2)
				fprintf(stderr, "%s: primary key in COBOL declaration not indexed\n", me);
			#endif
			THROW_EXC(COB_IOEXC_ISAM_NINDEX);
		}
	}
	if (!tf_exists_dat) {
		// set SHARING for newly created file
		if (stat(f_isam->fid_dat, &st) != 0) { 
			THROW_EXC_OS(COB_IOEXC_ERROR);  
		}
		f->fileuid.inode = st.st_ino; 
		if (0 != cob_fileio_sharing_open_file(f, mode)) {
			THROW_EXC(COB_IOEXC_FSHARE_LOCK);  
		}
	}
	f_isam->isfd_cursor = -1; 
	if (mode != COB_OPEN_OUTPUT) {
		// open a second isfd to use as cursor indicating our current position in the index
		f_isam->isfd_cursor = ISOPEN(f->fid, ISINPUT | rsz_mode);
		if (f_isam->isfd_cursor == -1) {
			THROW_EXC_ISAM(COB_IOEXC_ISAM_DROP);
		}
	}
	f_isam->pb_record = (char *)cob_malloc(f->record_max);		
	f_isam->ix_key = 0;            // primary-key is "active key" after ISAM open

	if (mode == COB_OPEN_EXTEND) {
		// ANS85: fpi -> after last logical record
		f->tf_beyond_eof = 1;
	}
	return(0);
}





/*
 *	Close the ISAM file releasing all resources
 */


int cob_fileio_isam_close(
     cob_file_t *f
   , const int opt)
{
	isam_file_t *f_isam = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_close(%s opt=%d)\n"
		              , me, f->select_name, opt);
#endif

	if (f_isam == NULL) return(0);
	cob_fileio_sharing_close_file(f); 
	if (f_isam->isfd >= 0) isfullclose(f_isam->isfd);
	if (f_isam->isfd_cursor >= 0) isfullclose(f_isam->isfd_cursor);
	_xisam_free_handle(f);
	f->open_mode = COB_OPEN_CLOSED;
	f->tf_is_locked = (opt == COB_CLOSE_LOCK);
	return(0);
}





/*
 *	Set the file position indicator to a selected record in the file.
 *
 *	ISAM supports positioning by: ISFIRST ISLAST ISEQUAL ISGREAT ISGTEQ
 *	COBOL supports: COB_EQ COB_GE COB_GT COB_LE COB_LT
 *	Because there is no direct equivalent, COB_LE COB_LT are implemented
 *	by starting for the next highest key and retreating to its predecessor.
 *
 *	The value of the key is extracted from the record-data.
 */


int cob_fileio_isam_start(
	  cob_file_t *f
	, const int cond
	, cob_field *key)
{
	isam_file_t *f_isam = f->file;
	int res, ix_key, cb_key, mode;
	char tf_found_key = 0;

	for (ix_key = 0; ix_key < f_isam->cnt_key; ix_key++) {
		if (f->keys[ix_key].field->data == key->data) {
			tf_found_key = (f_isam->keys[ix_key].ix_isam_key != -1);
			break;
		}
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_start(%s cond=%d  key=%s)\n"
		      , me, f->select_name, cond
		      , tf_found_key ? cob_fileio_key_to_str(f->keys + ix_key) 
		                     : "ILLEGAL-KEY");
#endif

	if (!tf_found_key) {
		// there is no matching key in isam-handler.
		// deferred from COBOL OPEN, now throw exception
		THROW_EXC(COB_IOEXC_ISAM_NINDEX);
	}
	f_isam->ix_key = ix_key;
	// Use size of data field; this may indicate a partial key  
	if ((key->size < 1) || (key->size > f_isam->keys[ix_key].kd.k_len)) 
		cb_key = USE_WHOLE_KEY; 
	else
		cb_key = key->size;
	switch (cond) {
	case COB_FI:
		mode = ISFIRST;
		break;
	case COB_EQ:
		mode = ISEQUAL;
		break;
	case COB_GE:
		mode = ISGTEQ;
		break;
	case COB_GT:
		mode = ISGREAT;
		break;
	case COB_LE:
		mode = ISGREAT;
		break;
	case COB_LT:
		mode = ISGTEQ;
		break;
	case COB_LA:
		mode = ISLAST;
		break;
	default:
		THROW_EXC(COB_IOEXC_ISAM_ILLEGAL);
	}
 
	res = isstart(f_isam->isfd_cursor, &f_isam->keys[ix_key].kd, cb_key, (void *)f->record->data, mode);
	if (res != 0) {
		switch (cond) {
		case COB_FI:		// fall thru
		case COB_EQ:		// fall thru
		case COB_LA:
			mode = ISEQUAL;
			THROW_EXC(COB_IOEXC_NOREC);
		case COB_GE:
		case COB_GT:
			f->tf_beyond_eof = (ISERRNO == ENOREC);
			THROW_EXC(COB_IOEXC_NOREC);
		case COB_LE:
		case COB_LT:
			if (ISERRNO == ENOREC) {
				// need to retreat onto highest-key
				f->tf_beyond_eof = 1;
				break;
			}
			THROW_EXC(COB_IOEXC_NOREC);
		default:
			THROW_EXC(COB_IOEXC_ISAM_ILLEGAL);
		}
	}
	if ((cond == COB_LE) || (cond == COB_LT)) {
		// ensure no change is made to clients record area
		memcpy(f_isam->pb_record, f->record->data, f->record_max);
		if (-1 == _xisam_retreat(f_isam, f_isam->pb_record, cond))
			THROW_EXC(COB_IOEXC_NOREC);
	}
	f_isam->recnum = ISRECNUM;
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
	isam_file_t *f_isam = f->file;
	int ix_key, lock_mode;
	char tf_found_key = 0;

	for (ix_key = 0; ix_key < f_isam->cnt_key; ix_key++) {
		if (f->keys[ix_key].field->data == key->data) {
			tf_found_key = (f_isam->keys[ix_key].ix_isam_key != -1);
			break;
		}
	}


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_read(%s opt=%d  key=%s)\n"
		      , me, f->select_name, opt
		      , tf_found_key ? cob_fileio_key_to_str(f->keys + ix_key) 
		                     : "ILLEGAL-KEY");

#endif

	if (!tf_found_key) {
		// there is no matching key in isam-handler.
		// deferred from COBOL OPEN, now throw exception
		THROW_EXC(COB_IOEXC_ISAM_NINDEX);
	}
	if (f_isam->ix_key != ix_key) {				// Switch to this index 
		isstart(f_isam->isfd, &f_isam->keys[ix_key].kd, USE_WHOLE_KEY, (void *)f->record->data, ISEQUAL);
		f_isam->ix_key = ix_key;
	}
	lock_mode = _xisam_translate_lock_mode(f, opt);
	if ((lock_mode & ISLOCK) && !f->tf_lock_many) 
		isrelease(f_isam->isfd);


	switch(opt & 0x0F) {

	case COB_READ_NEXT:
	case COB_READ_PREVIOUS:
		fprintf(stderr, "!!! UNEXPECTED cob_fileio_isam_read opt=%d\n", opt);
		THROW_EXC(COB_IOEXC_ILLEGAL);

	case COB_READ_FIRST:
		if (isread(f_isam->isfd, (void *)f->record->data, ISFIRST | lock_mode) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		break;
	case COB_READ_LAST:
		if (isread(f_isam->isfd, (void *)f->record->data, ISLAST | lock_mode) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		break;
	default:
		if (isread(f_isam->isfd, (void *)f->record->data, ISEQUAL | lock_mode) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_NOREC);
		break;
	}
	_xisam_extract_key(f_isam, 0, f->record->data, f_isam->key_p_r);
	_xisam_extract_key(f_isam, ix_key, f->record->data, f_isam->key_x_r);
	f_isam->recnum = ISRECNUM;
#if defined(ISVARLEN)
	if (f->record_min != f->record_max) 
		f->record->size = ISRECLEN;
#endif

	// position isfd_cursor so that READ NEXT, READ PREVIOUS are relative to the current key
	isstart(f_isam->isfd_cursor, &f_isam->keys[ix_key].kd, USE_WHOLE_KEY, (void *)f->record->data, ISEQUAL);
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
	isam_file_t *f_isam = f->file;
	int lock_mode, direction;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_read_next(%s opt=%d)\n"
		              , me, f->select_name, opt);
#endif

 	lock_mode = _xisam_translate_lock_mode(f, opt);
	if ((lock_mode & ISLOCK) && !f->tf_lock_many) {
		isrelease(f_isam->isfd);
	}
	// use isfd_cursor to set the new record-position
	switch (direction = opt & 0x0F) {
	case COB_READ_CURRENT:
		if (isread(f_isam->isfd_cursor, (void *)f_isam->pb_record, ISCURR) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		break;
	case COB_READ_NEXT:
		_xisam_reverse_extract_key(f_isam);
		if (_xisam_read_next(f_isam, (void *)f_isam->pb_record) != 0) {
			if (f->tf_beyond_eof)
				THROW_EXC(COB_IOEXC_R_XEOF);
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		}
		break;
	case COB_READ_PREVIOUS:
		_xisam_reverse_extract_key(f_isam);
		if (_xisam_read_prior(f_isam, (void *)f_isam->pb_record) != 0) {
			if (f->tf_beyond_bof)
				THROW_EXC(COB_IOEXC_R_XEOF);
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		}
		break;
	case COB_READ_FIRST:
		if (isread(f_isam->isfd_cursor, (void *)f_isam->pb_record, ISFIRST) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		break;
	case COB_READ_LAST:
		if (isread(f_isam->isfd_cursor, (void *)f_isam->pb_record, ISLAST) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
		break;
	default:
		_xisam_reverse_extract_key(f_isam);
		if (isread(f_isam->isfd_cursor, (void *)f_isam->pb_record, ISEQUAL) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_NOREC);
		break;
	}
	// now read and lock current-record
	memcpy(f->record->data, f_isam->pb_record, f->record_max);
	if (isread(f_isam->isfd, (void *)f->record->data, ISEQUAL | lock_mode) != 0) 
		THROW_EXC_ISAM(COB_IOEXC_R_XEOF);
	_xisam_extract_key(f_isam, 0, f->record->data, f_isam->key_p_r);
	_xisam_extract_key(f_isam, f_isam->ix_key, f->record->data, f_isam->key_x_r);
	f_isam->recnum = ISRECNUM;

#if defined(ISVARLEN)
	if (f->record_min != f->record_max) 
		f->record->size = ISRECLEN;
#endif
	return(0);
}






/*
 *  Write the file record of cb_rec bytes.
 *	This adds a new row which is indexed by a unique 
 *  primary-key and possible secondary-keys
 *  which may be duplicated (declared in file SELECT).
 */

int cob_fileio_isam_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	isam_file_t *f_isam = f->file;
	char new_key[f_isam->cb_key_max];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_write(%s, rsz=%d, opt=%d)\n"
		              , me, f->select_name, cb_rec, opt);
#endif

#if defined(ISVARLEN)
	if (f->record_min != f->record_max)
		ISRECLEN = cb_rec;
#endif

	_xisam_extract_key(f_isam, 0, f->record->data, new_key);
	if ((f->access_mode == COB_ACCESS_SEQUENTIAL)
		&& (-1 == memcmp(new_key
		               , f_isam->key_p_w
		               , f_isam->cb_key_max))) {
		THROW_EXC(COB_IOEXC_ISAM_KEY_ASC);
	}
	if (iswrite(f_isam->isfd, (void *)f->record->data) != 0) {
		if ((ISERRNO == EDUPL)
			&& (f->open_mode == COB_OPEN_OUTPUT)) 
				THROW_EXC(COB_IOEXC_ISAM_DUP);
		THROW_EXC_ISAM(COB_IOEXC_ERROR);
	} else {
      	memcpy(f_isam->key_p_w, new_key, f_isam->cb_key_max);
	}
	return(0);
}









/*
 *	Rewrite the file record of cb_rec bytes, identified by its primary-key.
 *	The secondary-keys may have changed value. This replaces the
 *	the row identified by its primary-key and reindexes the secondary-keys.
 */

int cob_fileio_isam_rewrite(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	isam_file_t *f_isam = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_rewrite(%s, rsz=%d, opt=%d)\n"
		              , me, f->select_name, cb_rec, opt);
#endif

	if ((f->access_mode == COB_ACCESS_SEQUENTIAL)
	    && (_xisam_keycmp(f_isam, 0, f->record->data, f_isam->key_p_r) != 0)) 
		THROW_EXC(COB_IOEXC_ISAM_KEY_ASC);

	// read original record using primary-key 
	memcpy(f_isam->pb_record, f->record->data, f->record_max);
	if (f_isam->ix_key != 0) {
		if (isstart(f_isam->isfd, &f_isam->keys[0].kd, USE_WHOLE_KEY
		          , (void *)f_isam->pb_record, ISEQUAL) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_NOREC);
	}	
	if (isread(f_isam->isfd, (void *)f_isam->pb_record, ISEQUAL) != 0) 
		THROW_EXC_ISAM(COB_IOEXC_NOREC);

#ifdef IMPLEMENT_IX_FS_44
	// All ORGANIZATIONs length of new record must = record being replaced
	if (cb_rec != ISRECLEN) {
#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 3) {
				fprintf(stderr, "%s: illegal attempt to rewrite INDEXED record of different length\n", me);
				fprintf(stderr, "%s: ... Prior rec read = %d bytes. New record to write = %d bytes.\n"
				      , me, ISRECLEN, cb_rec);
			}
#endif
			THROW_EXC(COB_IOEXC_REWRITE_RSZ);	
	}
#endif



#if defined(ISVARLEN)
	if (f->record_min != f->record_max)
		ISRECLEN = cb_rec;
#endif

	if (isrewrite(f_isam->isfd, (void *)f->record->data) != 0)
		THROW_EXC_ISAM(COB_IOEXC_ERROR);

	if ((f->lock_mode == COB_LOCK_AUTOMATIC) && !f->tf_lock_many)
		isrelease(f_isam->isfd);

	if (f_isam->ix_key != 0) {
		// revert to original index
		// CAUTION: rewrite may have changed 2ndry key, so use ISGTEQ
		if (isstart(f_isam->isfd, &f_isam->keys[f_isam->ix_key].kd, USE_WHOLE_KEY
	          , (void *)f_isam->pb_record, ISGTEQ) != 0) 
			THROW_EXC_ISAM(COB_IOEXC_ERROR);
	} 
	_xisam_extract_key(f_isam, 0, f->record->data, f_isam->key_p_w);
	return(0);
}







/*
 *  Delete the record identified by its primary-key.
 */

int cob_fileio_isam_delete(cob_file_t *f)
{
	isam_file_t *f_isam = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_delete(%s)\n"
		              , me, f->select_name);
#endif

	if (isread(f_isam->isfd, (void *)f->record->data, ISEQUAL | ISLOCK) != 0) 
		THROW_EXC_ISAM(COB_IOEXC_NOREC);
	if (isdelete(f_isam->isfd, (void *)f->record->data) != 0) 
		THROW_EXC_ISAM(COB_IOEXC_ERROR);
    _xisam_extract_key(f_isam, 0, f->record->data, f_isam->key_p_d);
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
	isam_file_t *f_isam = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_sync(%s mode=%d)\n"
		              , me, f->select_name, mode);
#endif

	if (f_isam)
		isflush(f_isam->isfd);
	return(0);
}






/*
 *	Release any/all locks held on a file.
 */

int cob_fileio_isam_unlock(cob_file_t *f)
{
	isam_file_t *f_isam = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_unlock(%s)\n"
		              , me, f->select_name);
#endif

	if (f_isam != NULL)
		isrelease(f_isam->isfd);
	return(0);
}






/*
 *	f is an INDEXED file, not open. Using the filename in f,
 *	physically delete the files representing the index file.
 *	The .idx and .dat set are deleted.
 */ 

int cob_fileio_isam_erase(cob_file_t *f)
{
	int ret;
	char root_name[FILENAME_MAX], fid[FILENAME_MAX];
	struct stat st;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_isam_erase(%s)\n"
		              , me, f->select_name);
#endif

	cob_field_to_string(f->assign, root_name, FILENAME_MAX);
	cob_fileio_locate_file(root_name, root_name, FILENAME_MAX);
	sprintf(fid, "%s.dat", root_name);
	if (stat(fid, &st) == 0) {
		ret = ISERASE(root_name);
		// NYI: permission-denied, etc
		return(ret);
	}
	THROW_EXC(COB_IOEXC_OK_NOFILE);
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

	pb += sprintf(pb, "%s<isam_handler>\n", indent);

#if defined(WITH_INDEXED_CISAM)
	pb += sprintf(pb, "%s\tC-ISAM\n", indent);
#elif defined(WITH_INDEXED_DISAM)
	pb += sprintf(pb, "%s\tD-ISAM\n", indent);
#elif defined(WITH_INDEXED_VBISAM) && defined(VB_RTD)
	pb += sprintf(pb, "%s\tVB-ISAM (with RTD)\n", indent);
#elif defined(WITH_INDEXED_VBISAM) 
	pb += sprintf(pb, "%s\tVB-ISAM\n", indent);
#else
	pb += sprintf(pb, "%s\tundefined\n", indent);
#endif 
	pb += sprintf(pb, "%s</<isam_handler>\n", indent);

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
	isam_file_t *f_isam = f->file;
	if (f_isam == NULL) return(NULL);

	char *xml = cob_malloc(1000);
    char *pb = xml;

	pb += sprintf(pb, "%s<index_file_name> %s </index_file_name>\n"
		      , indent, f_isam->fid_idx);
	pb += sprintf(pb, "%s<data_file_name> %s </data_file_name>\n"
		      , indent, f_isam->fid_dat);

	xml = realloc(xml, strlen(xml) + 1);
	return(xml);
}




/*
 *	P R I V A T E   F U N C T I O N S
 *	---------------------------------
 */








/*
 * Prepare isam_file_t for COBOL file f.
*/

static isam_file_t *_xisam_get_handle(cob_file_t *f)
{
	isam_file_t *f_isam;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_get_handle(%s)\n", me, f->select_name);
#endif

	f_isam = (isam_file_t *)cob_malloc(sizeof(isam_file_t));
	f_isam->fid_idx = NULL;     
	f_isam->fid_dat = NULL;     
	f_isam->key_p_r = NULL;
	f_isam->key_p_w = NULL;
	f_isam->key_p_d = NULL;
	f_isam->key_x_r = NULL;
	f_isam->pb_record = NULL;
	f_isam->cnt_key = f->nkeys;
	f_isam->keys = cob_malloc(sizeof(xkey_t) * f->nkeys);
	// storage for key-values (primary, read, write, delete)
	// is malloc-d when we know size of largest key indexed

	f->file = f_isam;
	f_isam->cob_file = f;
	return(f_isam);
}






/*
 * Free all memory allocated within isam_file_t
*/

static void _xisam_free_handle(cob_file_t *f)
{
	isam_file_t *f_isam = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_free_handle(%s)\n", me, f->select_name);
#endif

	if (f_isam == NULL) return;
	if (f_isam->fid_idx != NULL) free(f_isam->fid_idx);
	if (f_isam->fid_dat != NULL) free(f_isam->fid_dat);
	free(f_isam->keys);
	if (f_isam->key_p_r != NULL) free(f_isam->key_p_r);
	if (f_isam->key_p_w != NULL) free(f_isam->key_p_w);
	if (f_isam->key_p_d != NULL) free(f_isam->key_p_d);
	if (f_isam->key_x_r != NULL) free(f_isam->key_x_r);
	if (f_isam->pb_record != NULL) free(f_isam->pb_record);
	free(f_isam);
	f->file = NULL;
}



/*
 *	Read the next record using the cursor.
 *	When iterating an index in natural order, ISAM will return EENDFILE [110]
 *	if it encounters a record that has been deleted from the recordset.
 *	In this eventuality, we have to re-establish the recordset by isstart()
 *	until we fall off the back of the file.
*/ 
static int _xisam_read_next(
	  isam_file_t *f_isam
	, void *record)
{
	int res, ix_key;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_read_next()\n", me);
#endif


	ix_key = f_isam->ix_key;
	res = isread(f_isam->isfd_cursor, record, ISNEXT);
	if (res == 0) 
		return(0);
	if ((ISERRNO != EENDFILE) && (ISERRNO != ENOCURR))
		return(-1);
	res = isstart(f_isam->isfd_cursor, &f_isam->keys[ix_key].kd, USE_WHOLE_KEY, record, ISGREAT);
	if (res == 0)
		return(_xisam_read_next(f_isam, record));
	if (ISERRNO == ENOREC)
		f_isam->cob_file->tf_beyond_eof = 1;		
	return(-1);
}






/*
 * When iterating an index in reverse order, ISAM will return ENOCURR [112]
 * if it encounters a record that has been deleted from the recordset.
 * In this eventuality, we have to re-establish the recordset by isstart()
 * until we fall off the front of the file.
*/ 
static int _xisam_read_prior(
	  isam_file_t *f_isam
	, void *record)
{
	int res, ix_key;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_read_prior()\n", me);
#endif

	ix_key = f_isam->ix_key;
	res = isread(f_isam->isfd_cursor, record, ISPREV);
	if (res == 0) 
		return(0);
	if (ISERRNO != ENOCURR) {
		if (ISERRNO == EENDFILE)
			f_isam->cob_file->tf_beyond_bof = 1;		
		return(-1);
	}
	res = isstart(f_isam->isfd_cursor, &f_isam->keys[ix_key].kd, USE_WHOLE_KEY, record, ISGTEQ);
	if (res == 0)
		return(_xisam_read_prior(f_isam, record));
	return(-1);
}








/*
 * Sometimes it is necesssary to retreat to find the record with
 * the previous key value.
 * ISAM operates on START GREATER_THAN - there is no LESS_THAN equivalent.
 * Given key-set: key_0 key_1 .... key_n-1 key_n
 *
 * START REQUEST:           CURRENT KEY         RETURN
 * key COB_LE key_-1        key_0               tf_beyond_bof
 * key COB_LE key_0         key_1               key_0
 * key COB_LE key_1         key_2               key_1
 * key COB_LE key_n         tf_beyond_eof       key_n 
 * key COB_LT key_0         key_0               tf_beyond_bof
 * key COB_LT key_1         key_1               key_0
 * key COB_LT key_n         key_n               key_n-1
 * key COB_LT key_n+1       tf_beyond_eof       key_n 
 *
*/ 
static int _xisam_retreat(
	  isam_file_t *f_isam
	, void *record
	, int cond)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_retreat(ix_key=%d  cond=%d)\n"
		              , me, f_isam->ix_key, cond);
#endif

	if (f_isam->cob_file->tf_beyond_eof) {
		f_isam->cob_file->tf_beyond_eof = 0;
		return(isstart(f_isam->isfd_cursor, &f_isam->keys[f_isam->ix_key].kd, USE_WHOLE_KEY, record, ISLAST));
	}
	return(_xisam_read_prior(f_isam, record));
}





/*
 *	Copy key descriptors from COBOL format to ISAM format
 */
static int _xisam_copy_key_descriptors(
	  cob_file_t *f
	, isam_file_t *f_isam)
{
	int ix_key, ix_component;
	struct keydesc *kd;
	cob_file_key_t key;


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_copy_key_descriptors(%s)\n", me, f->select_name);
#endif

	f_isam->cb_key_max = -1;
	for (ix_key = 0; ix_key < f->nkeys; ix_key++) {
		key = f->keys[ix_key];
		if (key.tf_suppress) {
			fprintf(stderr, "!!! Feature SPARSE KEYS not implemented with C/VBISAM\n");
			THROW_EXC(COB_IOEXC_NYI);
		}
		kd = &f_isam->keys[ix_key].kd;
		memset (kd, 0, sizeof(struct keydesc));
		kd->k_flags = key.tf_duplicates ? ISDUPS : ISNODUPS;
		kd->k_len = key.field->size;
		if (f_isam->cb_key_max < kd->k_len) {
			f_isam->cb_key_max = kd->k_len;
		}
		kd->k_start = key.offset;
		kd->k_type = CHARTYPE;
		if (key.count_components <= 1) {     // simple key - single field
			kd->k_part[0].kp_start = key.offset;
			kd->k_part[0].kp_leng = key.field->size;
			kd->k_part[0].kp_type = CHARTYPE;
			kd->k_nparts = 1;
		} else {                             // composite (or "split") key  
			for (ix_component = 0; ix_component < key.count_components; ++ix_component) {
				kd->k_part[ix_component].kp_start = key.component[ix_component]->data - f->record->data;
				kd->k_part[ix_component].kp_leng = key.component[ix_component]->size;
				kd->k_part[ix_component].kp_type = CHARTYPE;
			} 
			kd->k_nparts = ix_component;
		}
	}
	f_isam->key_p_r = (char *)cob_malloc(f_isam->cb_key_max);
	f_isam->key_p_w = (char *)cob_malloc(f_isam->cb_key_max);
	f_isam->key_p_d = (char *)cob_malloc(f_isam->cb_key_max);
	f_isam->key_x_r = (char *)cob_malloc(f_isam->cb_key_max);
	return(0);
}








/*
 * Create a new empty isam dataset.
 * Add the keys declared in the COBOL source to the new dataset.
 *
 * The file must be opened with ISEXCLLOCK to allow isaddindex() to work.  
 * On exit the file is CLOSED and must be reopened to apply the correct mode.
 * Return 0 on success, -1 on failure.
*/

static int _xisam_create_dset(
	  isam_file_t *f_isam
	, char *root_name
	, int rsz
	, int mode)
{
	int isfd, k;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _xisam_create_dset(%s root-name=%s  rsz=%d  mode=0x%x)\n"
		              , me, f_isam->cob_file->select_name, root_name, rsz, mode);
	if (trace_level > 3)
		fprintf(stderr, "%s: index for keys: %s"
		              , me, _xisam_dump_keys(f_isam));	
#endif


#if defined(ISVARLEN)
	if (f_isam->cob_file->record_min != f_isam->cob_file->record_max)
		ISRECLEN = f_isam->cob_file->record_min;
#endif

	isfd = ISBUILD(root_name, rsz, &f_isam->keys[0].kd, mode | ISEXCLLOCK);
	f_isam->isfd = isfd;
	if (isfd == -1) return(-1);
	for (k = 1; k < f_isam->cnt_key; k++) {
		if (isaddindex(isfd, &f_isam->keys[k].kd) != 0)
			return(-1);
	}
	isfullclose(f_isam->isfd);
	f_isam->isfd = -1;
	return(0);
}




/*
 *	The keys have been loaded into f_isam from the COBOL SELECT.
 *	Check these keys are a subset of keys known to isam-handler
 *	for this file. The order of declaration is unimportant; all
 *	ordinal references passed to disam must be indirected via
 *	f_isam->keys[].ix_isam_key.
 *	Keys for which there is no matching index get ix_isam_key = -1. 
 *	Superfluous keys in the index are ignored.
 *  
 *	Returns:
 *		-1 encountered error.
 *		 0 if key found in ISAM for each key in COBOL SELECT
 *		 1 if COBOL SELECT references any key for which there is
 *		   no matching index.
*/
static int _xisam_match_keys(isam_file_t *f_isam)
{
	int res, i, ix_isam_key, ix_cob_key, c_isam_keys, c_comps, tf_matched;
	struct keydesc *kd_cob, kd_isam;
	struct dictinfo info;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_match_keys()\n", me);
#endif

	if (0 != isindexinfo(f_isam->isfd, (void *)&info, 0)) {
		return(-1);
	}
	c_isam_keys = info.di_nkeys & 0x7F;                  // Mask off ISVARLEN  
	res = 0;
	for (ix_cob_key = 0; ix_cob_key < f_isam->cnt_key; ++ix_cob_key) {
		kd_cob = &f_isam->keys[ix_cob_key].kd;
		f_isam->keys[ix_cob_key].ix_isam_key = -1;
		tf_matched = 0;
		for (ix_isam_key = 0; (ix_isam_key < c_isam_keys) && !tf_matched; ++ix_isam_key) {
			if (0 != isindexinfo(f_isam->isfd, &kd_isam, ix_isam_key+1)) {
				break;
			}
			c_comps = kd_cob->k_nparts;
			if (kd_isam.k_nparts != c_comps)
				continue;
			if (c_comps == 1) {
				// simple key - simple match
				if ((kd_isam.k_start == kd_cob->k_start) 
					&& (kd_isam.k_leng == kd_cob->k_leng) 
                                        && ((kd_isam.k_flags & ISDUPS) == (kd_cob->k_flags & ISDUPS))) {
					f_isam->keys[ix_cob_key].ix_isam_key = ix_isam_key;
					tf_matched = 1;
				}
			} else {
				// split-key - tricky match
                                if ((kd_isam.k_flags & ISDUPS) != (kd_cob->k_flags & ISDUPS))
					continue;
				for (i = 0; i < c_comps; ++i) {
					if ((kd_isam.k_part[i].kp_start != kd_cob->k_part[i].kp_start) 
						|| (kd_isam.k_part[i].kp_leng != kd_cob->k_part[i].kp_leng))
						break;
				}
				if (i == c_comps) {        // all key-components matched for rb:cb
					tf_matched = 1;
					f_isam->keys[ix_cob_key].ix_isam_key = ix_isam_key;
				}
			}
		}
		if (!tf_matched) res = 1;
	}
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: _xisam_match_keys() -> %d\n", me, res);
#endif
	return(res);
}






/*
 * Using the offset:length of the (component parts) of the iKey-th key,
 * extract the key-value from the given data record.
 * Arg: f_isam ... indexfile
 * Arg: ix_cob_key ... ordinal of key to use
 * Arg: pb_rec ... pointer to data-record
 * Arg: ret_key_value ... the (composed) key.
*/
static int _xisam_extract_key(
     isam_file_t *f_isam
   , int ix_cob_key
   , const void *pb_rec
   , void *ret_key_value)
{
	int ix;
	struct keydesc *kd_cob = &f_isam->keys[ix_cob_key].kd;
	char *p_val = ret_key_value;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_extract_key(ix_key=%d)\n", me, ix_cob_key);
#endif

	for (ix = 0; ix < kd_cob->k_nparts; ++ix) {
		memcpy(p_val 
		     , pb_rec + kd_cob->k_part[ix].kp_start
		     , kd_cob->k_part[ix].kp_leng);
		p_val += kd_cob->k_part[ix].kp_leng; 
	}
	return(0);
}






/*
 *	Reverse the _xisam_extract_key(). Given a composited value of a key,
 *	extract the component parts and copy them back into the record.
 *	The key is f_isam->ix_key; the record is f_isam->pb_record
 *	and the composited value is f->isam->key_x_r.
 */
static int _xisam_reverse_extract_key(isam_file_t *f_isam)
{
	int ix;
	struct keydesc *kd_cob = &f_isam->keys[f_isam->ix_key].kd;
	char *p_val = f_isam->key_x_r;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_reverse_extract_key(ix_key=%d)\n", me, f_isam->ix_key);
#endif

	for (ix = 0; ix < kd_cob->k_nparts; ++ix) {
		memcpy(f_isam->pb_record + kd_cob->k_part[ix].kp_start
             , p_val  
		     , kd_cob->k_part[ix].kp_leng);
		p_val += kd_cob->k_part[ix].kp_leng; 
	}
	return(0);
}





#ifdef WITH_FILEIO_TRACE
// debug aid

static char *_xisam_dump_keys(
     isam_file_t *f_isam)
{
	static char *str = NULL;
	static int cb_str_max = 0;

	int ix_key, ix_comp, cb_str_key;
	char str_key[1024];
	struct keydesc kd_cob;

	for (ix_key = 0; ix_key < f_isam->cnt_key; ++ix_key) {
		kd_cob = f_isam->keys[ix_key].kd;
		cb_str_key = sprintf(str_key
		                   , "Key %u x%u rb=%d cb=%d"
		                   , ix_key, kd_cob.k_nparts, kd_cob.k_start, kd_cob.k_leng);
		for (ix_comp = 0; ix_comp < kd_cob.k_nparts; ++ix_comp) {
			cb_str_key += sprintf(str_key+cb_str_key
			                    , " %d:%d"
			                    , kd_cob.k_part[ix_comp].kp_start, kd_cob.k_part[ix_comp].kp_leng);
		}
		str_key[cb_str_key++] = '\n';
		str_key[cb_str_key++] = 0;
		if (str == NULL) {
			cb_str_max = 10 * cb_str_key;
			str = cob_malloc(cb_str_max);
			*str = '\0';
		} else {
			if ((strlen(str) + cb_str_key) > cb_str_max) {
				cb_str_max += strlen(str) + cb_str_key + 1;
				str = realloc(str, cb_str_max);
			}
		}
		strcat(str, str_key);
	}
	return(str);
}

#endif





/*
 * Using the offset:length of the (component parts) of the iKey-th key,
 * extract the key-value from the given data record and compare it
 * to the given key-value.
 * Arg: f_isam ... indexfile
 * Arg: ix_cob_key ... ordinal of key to use
 * Arg: pb_rec ... pointer to data-record
 * Arg: pb_key ... the (composed) key.
 * Returns: -1 ... extracted key is less than given key.
 *           0 ... extracted key is equal to given key.
 *          +0 ... extracted key is greater than given key.
*/
static int _xisam_keycmp(
     isam_file_t *f_isam
   , int ix_cob_key
   , const void *pb_rec
   , const void *pb_key)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_keycmp(ix_key=%d)\n", me, ix_cob_key);
#endif

	char *pb_key2;
	int cmp;
	pb_key2 = malloc(f_isam->keys[ix_cob_key].kd.k_len);
	_xisam_extract_key(f_isam, ix_cob_key, pb_rec, pb_key2);
	cmp = memcmp(pb_key2, pb_key, f_isam->keys[f_isam->ix_key].kd.k_len);
	free(pb_key2);
	return(cmp);
}







static int _xisam_translate_lock_mode(
	  cob_file_t *f
	, int cob_lock) 
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _xisam_translate_lock_mode()\n", me);
#endif

	// only files opened I-O may lock
	if (f->open_mode == COB_OPEN_INPUT) 
		return(0);
	switch(f->lock_mode) {
	case COB_LOCK_EXCLUSIVE:
		// the entire file is locked - ignore any record locking
		return(0);
	case COB_LOCK_MANUAL:
		if (cob_lock & COB_READ_LOCK) 
			return(ISLOCK);
		if (cob_lock & COB_READ_WAIT_LOCK) 
			return(ISLCKW);
#ifdef ISSKIPLOCK
		if (cob_lock & COB_READ_IGNORE_LOCK) 
			return(ISSKIPLOCK);
#endif
		return(0);
	case COB_LOCK_AUTOMATIC:
		if (cob_lock & COB_READ_IGNORE_LOCK)
			return(0);
		return(ISLOCK);
	default:
		return(0);
	}
}





/*
 *	For some ISAM errno we can determine a COBOL RTS error code.
 *	For the rest, we use the generic code supplied.
 *
 *	The ISAM error codes are enumerated in the header file
 *	e.g. vbisam.h
 */

static int _isam_map_errno(
	  int errnum
	, int erc_generic)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _isam_map_errno(errno=%d  dflt=%d)\n", me, errnum, erc_generic);
#endif

	switch(errnum) {
	case 0:
		return(0);
	case ENOREC:
		return(COB_IOEXC_NOREC);
	case EENDFILE:
		return(COB_IOEXC_R_XEOF);
	case EPERM:
		return(COB_IOEXC_FILE_ACCESS);
	case EACCES:
		return(COB_IOEXC_FILE_ACCESS);
	case EISDIR:
		return(COB_IOEXC_FILE_ACCESS);
	case EDUPL:
		return(COB_IOEXC_WRITE_DUP);
	case EKEXISTS:
		return(COB_IOEXC_WRITE_DUP);
	case ENOENT:
		return(COB_IOEXC_FILE_MISSING);
	case ENOCURR:
		if (erc_generic == COB_IOEXC_R_XEOF)
			return(erc_generic);
		return(COB_IOEXC_NOREC);
	case ELOCKED:
		return(COB_IOEXC_REC_LOCKED);
	case EFLOCKED:
		return(COB_IOEXC_FSHARE_LOCK);
	}
	return(erc_generic);
}



/*
 *	Return text describing an ISAM error.
 */
static char *_xisam_get_error_text(int errnum)
{
	static struct {
		const int no;
		const char *msg;
	} error[] = {
		  { EDUPL, "Attempt to write record with duplicate key" }
		, { ENOTOPEN, "File is not open" }
		, { EBADARG, "A call argument is illegal" }
		, { EBADKEY, "Unacceptable value in key descriptor" }
		, { ETOOMANY, "Attempt to open more files than the maximum allowed" }
		, { EBADFILE, "ISAM file corrupt internally" }
		, { ENOTEXCL, "File must be open EXCLUSIVE to perform this action" }
		, { ELOCKED, "Access failure - entity locked by another process" }
		, { EKEXISTS, "Attempt to create the same index a second time" }
		, { EPRIMKEY, "Attempt to delete the primary index" }
		, { EENDFILE, "Attempt to access beyond the first/last record on file" }
		, { ENOREC, "Record not found" }
		, { ENOCURR, "Required current record not established" }
		, { EFLOCKED, "File is locked exclusively by another process" }
		, { EFNAME, "File-name is too long" }
		, { EBADMEM, "Failed to allocate memory" }
		, { ELOGREAD, "Log file: failed to read" }
		, { EBADLOG, "Log file: corrupted - bad format" }
		, { ELOGOPEN, "Log file: failed to open" }
		, { ELOGWRIT, "Log file: failed to write" }
		, { ENOTRANS, "A transaction is not in process" }
		, { ENOBEGIN, "A transaction BEGIN not found" }
		, { ENOPRIM, "There is no primary-key" }
		, { ENOLOG, "There is no logging" }
		, { ENOFREE, "There is no free disk space" }
		, { EROWSIZE, "Record length is too short or too long" }
		, { EAUDIT, "Audit trail exists" }
		, { ENOLOCKS, "No more locks" }
		, { EDEADLOK, "Deadlock avoidance" }
		, { ENOMANU, "Must be in ISMANULOCK mode" }
		, { EINTERUPT, "Interrupted isam call" }
		, { EBADFORMAT, "Locking or NODESIZE change" }
		, { -1, "ISAM error undefined: errno=nnnnnn" }
	};

	int ix;
	for (ix = 0; error[ix].no != -1; ++ix) {
		if (error[ix].no == errnum)
			return((char *)error[ix].msg);
	}
	sprintf((char *)error[ix].msg, "ISAM error undefined: errno=%.6d", errnum);
	return((char *)error[ix].msg);
}




#endif          // WITH_INDEXED_CISAM   WITH_INDEXED_DISAM   WITH_INDEXED_VBISAM



