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
 *	This entire module is excluded unless configured with WITH_RELATIVE
 *	===================================================================
 */

#ifdef WITH_RELATIVE


#include "fileio-relative.h"




/*
 *	fileio-relative.c
 *
 *	OpenCOBOL fileio component handling ORGANIZATION RELATIVE files.
 *
 *	The term "ordinal record number" is used in this module to mean
 *	the "file position indicator". 
 *	Within this module records are numbered 0 ... count_recs - 1
 *	COBOL RELATIVE KEY numbers records 1 ... count_recs
 *
*/






#ifdef WITH_RELATIVE_FIXED_RSZ
 
/*
 *	The structure of each record is:
 *	   char data[f->record_max] + char terminator
 *
 *	For "live" records, the terminator char is RELATIVE_FIXED_EOR
 *	default '\n' (new-line).
 *	For "dead" (deleted) records the terminator is replaced by NULL.
 *
*/
#define RSZ(f) (f->record_max + 1)
#define RELATIVE_FIXED_EOR '\n'


#else

/*
 *	The structure of each record is:
 *	   [cb_record] + char data[f->record_max]
 *
 *	cb_record is the byte count of data.
 *	For "dead" (deleted) records: cb_record = 0.
 *
*/

#define RSZ(f) (sizeof(int) + f->record_max)

#endif




#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-relative";
#endif




#define THROW_EXC(exc) { \
		cob_fileio_throw_exc(f, exc, COB_IO_CONTEXT_FILEIO_RELATIVE); \
		return(-1); \
	}


// LINUX errno 1..256     
#define THROW_EXC_EXT(exc, errno) { \
		cob_fileio_throw_ext(f, exc, COB_IO_CONTEXT_FILEIO_RELATIVE, COB_IO_REALM_COBOL, errno, strerror(errno)); \
		return(-1); \
	}



static int _relative_read_record(cob_file_t *f);
static int _relative_write_record(cob_file_t *f);




/*
 * Called once at program BOJ: initialise variables.
 *
 * Environmental variables referenced [default]:
 * NONE
*/
int cob_fileio_relative_initialise() {
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_initialise() %s\n", me 
		#ifdef WITH_RELATIVE_FIXED_RSZ
			, "FIXED_RSZ");
		#else
			, "VARIABLE_RSZ");
		#endif
#endif

	return(0);
}



/*
 * Called once at program EOJ: release resources.
 *
*/

int cob_fileio_relative_terminate() {

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_terminate()\n", me);
#endif

	return(0);
}







/*
 *	Open file - delegated to cob_fileio_generic_open()
 */
int cob_fileio_relative_open(
	  cob_file_t *f
	, const int mode) 
{
	int res;
	long rb;
	struct generic_file *f_generic;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_open(%s open_mode=%d) share_mode=%d lock_mode=%d\n"
		              , me, f->select_name, mode, f->share_mode, f->lock_mode);
#endif

	res = cob_fileio_generic_open(f, NULL, mode, COB_IO_CONTEXT_FILEIO_RELATIVE);
	if ((res == 0) && (mode == COB_OPEN_EXTEND)) {
		f_generic = f->file;
		rb = ftell(f_generic->file);
		f_generic->i_rec = rb / RSZ(f);
	}
	return(res);
}





/*
 *	Close file - delegated to cob_fileio_generic_close()
 */
int cob_fileio_relative_close(
	  cob_file_t *f
	, const int opt)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_close(opt=0x%x)\n", me, opt);
#endif

   return(cob_fileio_generic_close(f, opt, COB_IO_CONTEXT_FILEIO_RELATIVE));
}




/*
 * Set the ordinal record number to a selected record in the file.
 *
 */

int cob_fileio_relative_start(
	  cob_file_t *f
	, const int cond
	, cob_field *cobf_i_rec)
{
	int res;
        int rb_zrec;
        int i_zrec;
        int _cond;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_start(cond=%d  rec_no=%d)\n"
		      , me, cond, cob_get_int(cobf_i_rec));
#endif

	f_generic->i_rec = cob_get_int(cobf_i_rec) - 1;

	// Must handle START LT|LE N where N is beyond EOF
	fseek(f_generic->file, 0, SEEK_END);
	rb_zrec = ftell(f_generic->file) - RSZ(f);
	i_zrec = rb_zrec / RSZ(f);
        _cond = cond;
	if (cond == COB_FI) {
		f_generic->i_rec = 0;
		_cond = COB_GE;
        } else if (cond == COB_LT) {
		if (f_generic->i_rec > i_zrec) {
			f_generic->i_rec = i_zrec;
                } else {
			f_generic->i_rec--;
                }
        } else if (cond == COB_LE) {
		if (f_generic->i_rec > i_zrec) {
			f_generic->i_rec = i_zrec;
                }
	} else if ((cond == COB_GT) || (cond == COB_GE)) {
		if (f_generic->i_rec < 0)
			f_generic->i_rec = 0;
		if (cond == COB_GT) 
			f_generic->i_rec++;
	} else if (cond == COB_LA) {
		f_generic->i_rec = i_zrec;
		_cond = COB_LE;
	}

	while (1) {
		res = _relative_read_record(f);
		switch(res) {
			case 0:
				// return if a live record 
				/*
				 *  NYI To set user's external RELATIVE KEY or not ?
				 *  f->record->size = f_generic->cb_rec;
				 *  cob_set_int(cobf_i_rec, f_generic->i_rec + 1);
                                 */
				return(0);
			case -1:
				THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
				return(-1);
			case 1: 
				THROW_EXC(COB_IOEXC_NOREC);
				return(-1);
			case 2:
				// skip dead record
				switch (_cond) {
					case COB_EQ:
						THROW_EXC(COB_IOEXC_NOREC);
						return(-1);
					case COB_LT:
					case COB_LE:
						f_generic->i_rec--;
						break;
					case COB_GT:
					case COB_GE:
						f_generic->i_rec++;
						break;
				}
				break;
			case 3:
				THROW_EXC(COB_IOEXC_RSZ);
				return(-1);
		}

	}
	return(-1);
}









/*
 *	Read the n'th record (where n is cobf_i_rec).
 *	Arg: opt is ignored.
 */
int cob_fileio_relative_read(
	  cob_file_t *f
	, cob_field *cobf_i_rec
	, const int opt)
{
	int res;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_read(rec_no=%d)\n", me, cob_get_int(cobf_i_rec));
#endif

	f_generic->i_rec = cob_get_int(cobf_i_rec) - 1;
	res = _relative_read_record(f);
	switch(res) {
		case 0:
			if (f->record_size != NULL)
				cob_set_int(f->record_size, f_generic->cb_rec);
			if (f_generic->cb_rec < f->record_max)
				memset(f->record->data, ' ', f->record_max);
			memcpy(f->record->data, f_generic->pb_rec, f_generic->cb_rec);
			return(0);
		case -1:
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
			return(-1);
		case 1:
		case 2:
			THROW_EXC(COB_IOEXC_NOREC);
			return(-1);
		case 3:
			THROW_EXC(COB_IOEXC_RSZ);
			return(-1);
	}
	return(-1);
}







/*
 *	Read the next record following the current record.
 *	Arg: opt is ignored except for COB_READ_CURRENT.
 */

int cob_fileio_relative_read_next(
	  cob_file_t *f
	, const int opt)
{
	int res;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_read_next(opt=x%x) i_rec=%d\n"
		      , me, opt, f_generic->i_rec);
#endif

	// 1st read-next after START consumes record positioned by START
	// otherwise advance to next record
	if (!((opt & 0x0F) == COB_READ_CURRENT)) {
		f_generic->i_rec++;
	}
	while (1) {
		res = _relative_read_record(f);
		switch(res) {
			case 0:
				if (f->keys[0].field != NULL) {
					// report-back ordinal record number we have read
					cob_set_int (f->keys[0].field, 0);
					if (cob_add_int (f->keys[0].field, f_generic->i_rec + 1,
						COB_STORE_KEEP_ON_OVERFLOW) != 0) {
						THROW_EXC(COB_IOEXC_REL_KEY_2BIG);
						return(-1);
					}	
				}	
				if (f->record_size != NULL) 
					cob_set_int(f->record_size, f_generic->cb_rec);
				if (f_generic->cb_rec < f->record_max)
 					memset(f->record->data, ' ', f->record_max);
				memcpy(f->record->data, f_generic->pb_rec, f_generic->cb_rec);
				return(0);
			case -1:
				THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
				return(-1);
			case 1:
				THROW_EXC(COB_IOEXC_R_XEOF);
				return(-1);
			case 2:
				f_generic->i_rec++;
				break;
			case 3:
				THROW_EXC(COB_IOEXC_RSZ);
				return(-1);
		}
	}
	return(-1);
}








/*
 *	Write a record.
 *	If access is SEQUENTIAL, the ordinal record number is incremented 
 *	by 1. Otherwise the RELATIVE KEY value is used.
 *	The length of the record to be written is f->record->size.
 *	Upon successful write, the RELATIVE KEY value is set to indicate
 *	the record just written.
 *	Arg: opt is ignored.
 */

int cob_fileio_relative_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	int res;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_write(i_rec=%d, rsz=%d)\n", me
		      , ((f->access_mode == COB_ACCESS_SEQUENTIAL)
		        ? f_generic->i_rec+1
		        : cob_get_int(f->keys[0].field) - 1)
		      , cb_rec);
#endif

	if (f->access_mode == COB_ACCESS_SEQUENTIAL) {
		f_generic->i_rec++;
	} else {
		f_generic->i_rec = cob_get_int(f->keys[0].field) - 1;
	}
	res = _relative_read_record(f);
	switch(res) {
		case 0:
			THROW_EXC(COB_IOEXC_WRITE_DUP);
			return(-1);
		case -1:
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
			return(-1);
		case 1:
		case 2:
			f_generic->cb_rec = cb_rec;
			if (_relative_write_record(f) != 0) {
				THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
				return(-1);
			}
			if ((f->access_mode == COB_ACCESS_SEQUENTIAL) 
	 			&& (f->keys[0].field != NULL)) {
				// report-back ordinal record number we have just written
				cob_set_int(f->keys[0].field, f_generic->i_rec + 1);
			}
			return(0);
		case 3:
			THROW_EXC(COB_IOEXC_RSZ);
			return(-1);
	}
	return(-1);
}







/*
 *	Rewrite a record of cb_rec bytes.
 *	If access is SEQUENTIAL, there must be a current record (checked in fileio);
 *	the current record is overwritten. 
 *	Otherwise the RELATIVE KEY value is used.
 *	In all cases the length of the record being written must equal the 
 *	current record. (cf. NOTE rewrite variable length records [fileio-misc.h]
 *	Arg: opt is ignored.
 */

int cob_fileio_relative_rewrite(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	int res;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_rewrite(i_rec=%d, rsz=%d)\n", me
		      , ((f->access_mode == COB_ACCESS_SEQUENTIAL)
		        ? f_generic->i_rec
		        : cob_get_int(f->keys[0].field) - 1)
		      , cb_rec);
#endif

	if (f->access_mode != COB_ACCESS_SEQUENTIAL) {
		f_generic->i_rec = cob_get_int(f->keys[0].field) - 1;
		res = _relative_read_record(f);
		switch(res) {
			case -1:
				THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
				return(-1);
			case 1:
			case 2:
				THROW_EXC(COB_IOEXC_NOREC);
				return(-1);
			case 3:
				THROW_EXC(COB_IOEXC_RSZ);
				return(-1);
		}
	}
#ifdef IMPLEMENT_RL_FS_44
	// All ORGANIZATIONs length of new record must = record being replaced
	if (cb_rec != f_generic->cb_rec) {
#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 3) {
				fprintf(stderr, "%s: illegal attempt to rewrite RELATIVE record of different length\n", me);
				fprintf(stderr, "%s: ... Prior rec read = %d bytes. New record to write = %d bytes.\n"
				      , me, f_generic->cb_rec, cb_rec);
			}
#endif
			THROW_EXC(COB_IOEXC_REWRITE_RSZ);	
	}
#endif

	f_generic->cb_rec = cb_rec;
	if (_relative_write_record(f) != 0) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
		return(-1);
	}
	return(0);
}






/*
 *	Delete the record at the RELATIVE KEY value.
 */

int cob_fileio_relative_delete(cob_file_t *f)
{
	int res;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_delete(rec_no=%d)\n"
		      , me, cob_get_int(f->keys[0].field));
#endif

	f_generic->i_rec = cob_get_int(f->keys[0].field) - 1;
	res = _relative_read_record(f);
	switch(res) {
		case -1:
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
			return(-1);
		case 1:
		case 2:
			THROW_EXC(COB_IOEXC_NOREC);
			return(-1);
		case 3:
			THROW_EXC(COB_IOEXC_RSZ);
			return(-1);
	}
	f_generic->cb_rec = 0;
	if (_relative_write_record(f) != 0) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
		return(-1);
	}
	return(0);
}












/*
 * Synchronise the file by flushing the underlying file
 */

int cob_fileio_relative_sync(
	  cob_file_t *f
	, const int mode)
{
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_sync(mode=%d)\n", me, mode);
#endif

	if (0 != fflush(f_generic->file)) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
		return(-1);
	}
	if (mode == COB_SYNC_PHYSICAL) {
		if (0 != fdcobsync(fileno(f_generic->file))) {
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
			return(-1);
		}
	}
	return(0);
}






/*
 *	Flush the underlying file and remove all record locks.
 *	delegated to cob_fileio_generic_unlock()
 */

int cob_fileio_relative_unlock(cob_file_t *f)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_unlock()\n", me);
#endif

	return(cob_fileio_generic_unlock(f, COB_IO_CONTEXT_FILEIO_RELATIVE));	
}







/*
 *	Delete the file - delegated to cob_fileio_generic_erase()
 */
int cob_fileio_relative_erase(cob_file_t *f)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_relative_erase()\n", me);
#endif

	return(cob_fileio_generic_erase(f, COB_IO_CONTEXT_FILEIO_RELATIVE));	
}










#ifdef WITH_RELATIVE_FIXED_RSZ

/*
 *	Read the record at ordinal: f_generic->i_rec.
 *	If successful:
 *	   f_generic->cb_rec = record-size (a constant for the file).
 *	   f_generic->pb_rec stores the record-data.
 *	   f_generic->file is positioned at the 1st char of the next record. 
 *
 *
 *	Returns: 
 *	-1 if an i-o error occurs. 
 *	 0 if a record was read successfully.
 *	 1 i_rec is outside range: 0..(file-size - 1)
 *	 2 no record exists because the record-terminator
 *	   indicates the record has been deleted.
 *
*/

#ifdef  WITH_FILEIO_TRACE
	#define RETURN(res) { if (trace_level > 1) fprintf(stderr, " --> %d\n", res); return(res); }
#else
	#define RETURN(res) return(res)
#endif

static int _relative_read_record(cob_file_t *f)
{
        int rb, rb_zrec;
        char terminator;
        struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
        if (trace_level > 1)
                fprintf(stderr, "%s: _relative_read_record() FIXED_RSZ i_rec=%d ", me, f_generic->i_rec);
#endif

        f_generic->cb_rec = 0;
        rb = f_generic->i_rec * RSZ(f);
        fseek(f_generic->file, 0, SEEK_END);
        rb_zrec = ftell(f_generic->file) - RSZ(f);
        if ((rb < 0) || (rb > rb_zrec))
                RETURN(1);

        if ((0 != fseek(f_generic->file, rb, SEEK_SET))
         || (1 != fread(f_generic->pb_rec, RSZ(f) - 1, 1, f_generic->file))
     || (1 != fread(&terminator, 1, 1, f_generic->file)))
                RETURN(-1);
        if (terminator != RELATIVE_FIXED_EOR)
                RETURN(2);

        f_generic->cb_rec = f->record_max;
        RETURN(0);
}

#undef RETURN






/*
 *	Write the record to ordinal: f_generic->i_rec.
 *	Record-data is fetched from f->record->data of length f->record_max.
 *	If f_generic->cb_rec > 0 then a "live" record is written
 *	otherwise a "dead" record is written.
 *	Returns:
 *	 0 ... success
 *  -1 ... failed (errno will be set)
 *
*/
static int _relative_write_record(cob_file_t *f)
{
	int rb;
	char eor;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _relative_write_record() FIXED_RSZ\n", me);
#endif

	eor = (f_generic->cb_rec > 0) ? RELATIVE_FIXED_EOR : '0';
	rb = f_generic->i_rec * RSZ(f);
	if ((0 != fseek(f_generic->file, rb, SEEK_SET)) 
     || (1 != fwrite(f->record->data, RSZ(f) - 1, 1, f_generic->file))
     || (1 != fwrite(&eor, 1, 1, f_generic->file)))
		return(-1);
   return(0);
}

#endif     // WITH_RELATIVE_FIXED_RSZ













#ifndef WITH_RELATIVE_FIXED_RSZ

/*
 *	Read the record at ordinal: f_generic->i_rec.
 *	If successful:
 *		f_generic->cb_rec = record-size (may vary from rec to rec).
 *		f_generic->pb_rec stores the record-data.
 *		f_generic->file is positioned at the 1st char of the next record. 
 *
 *
 *	Returns: 
 *		-1 if an i-o error occurs. 
 *		 0 if a record was read successfully.
 *		 1 i_rec is outside range: 0..(file-size - 1)
 *		 2 no record exists because the record-length is 0
 *		   indicating the record has been deleted.
 *		 3 rsz on record is bigger than max-record-size.
 *
 */


#ifdef  WITH_FILEIO_TRACE
	#define RETURN(res) { if (trace_level > 1) fprintf(stderr, " --> %d\n", res); return(res); }
#else
	#define RETURN(res) return(res)
#endif


static int _relative_read_record(cob_file_t *f)
{
        int cb, rb, rb_zrec;
        struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
        if (trace_level > 1)
                fprintf(stderr, "%s: _relative_read_record() VARIABLE RSZ i_rec=%d ", me, f_generic->i_rec);
#endif

        f_generic->cb_rec = 0;
        rb = f_generic->i_rec * RSZ(f);
        fseek(f_generic->file, 0, SEEK_END);
        rb_zrec = ftell(f_generic->file) - RSZ(f);
        if ((rb < 0) || (rb > rb_zrec))
                RETURN(1);

        if ((0 != fseek(f_generic->file, rb, SEEK_SET))
         || (1 != fread(&cb, sizeof(int), 1, f_generic->file)))
                RETURN(-1);

#ifdef  WITH_FILEIO_TRACE
        if (trace_level > 8)
                fprintf(stderr, "rb=%ld  cb=%d ", ftell(f_generic->file), cb);
#endif

        if (cb < 1)
                RETURN(2);
        if (cb > RSZ(f))
                RETURN(3);
        if (1 != fread(f_generic->pb_rec, RSZ(f) - sizeof(int), 1, f_generic->file))
                RETURN(-1);
        f_generic->cb_rec = cb;
        RETURN(0);

}

#undef RETURN


/*
 *	Write the record to ordinal: f_generic->i_rec.
 *	Record-data is fetched from f->record->data.
 *	First, the record-length (f_generic->cb_rec) is written
 *	followed by the data itself. The combined record is a fixed
 *	RSZ bytes long.
 *
 *	Returns:
 *	 0 ... success
 *	-1 ... failed (errno will be set)
 *
*/
static int _relative_write_record(cob_file_t *f)
{
	int rb;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _relative_write_record() VARIABLE RSZ\n", me);
#endif

	rb = f_generic->i_rec * RSZ(f);
	if ((0 != fseek(f_generic->file, rb, SEEK_SET)) 
     || (1 != fwrite(&f_generic->cb_rec, sizeof(int), 1, f_generic->file))
     || (1 != fwrite(f->record->data, RSZ(f) - sizeof(int), 1, f_generic->file)))
      return(-1);
   return(0);
}



#endif		// ! WITH_RELATIVE_FIXED_RSZ



#endif      // WITH_RELATIVE
