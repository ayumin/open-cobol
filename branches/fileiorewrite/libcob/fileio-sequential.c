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
 *	This entire module is excluded unless configured with WITH_SEQUENTIAL
 *	=====================================================================
 */

#ifdef WITH_SEQUENTIAL

#include "fileio-sequential.h"




/*
 *	fileio-sequential.c
 *	
 *	OpenCOBOL fileio component handling ORGANIZATION [LINE] SEQUENTIAL files.
 *	
 *	ORGANIZATION SEQUENTIAL:
 *	Records may be fixed or variable length.
 *	1. FIXED LENGTH.
 *		Indicated by: f->record_min == f->record_max
 *		Each record is exactly f->record->size bytes - without added terminator.
 *	2. VARIABLE LENGTH.
 *		Indicated by: f->record_min != f->record_max
 *		Each record comprises: record-size + record-data.
 *		The format of record-size is determined by environment variables.
 *	
 *	ORGANIZATION LINE SEQUENTIAL:
 *	Records are variable length. Records are separated by a record delimiter (default '\n').
 *	Options exist to truncate trailing spaces from records.
 *	
 *	The functions in this module are common to SEQUENTIAL and LINE SEQUENTIAL
 *	except for: cob_fileio_line_sequential_read() 
 *	            cob_fileio_line_sequential_write()
 *	
 *	f->special != 0 indicates we are handling std files (stdin stdout stderr).
 *		ASSIGN to KEYBOARD -> stdin
 *		ASSIGN to DISPLAY  -> stdout
 *	Currently, there is no special handling for these file-types: fileio diverts
 *	their reads & writes to the line-sequential module.
 *	
 *	
*/





/*
** Config option WITH_VARSEQ determines how RSZ is encoded:
**
** WITH_VARSEQ  ALGORITHM          RSZ=10            100           1000          65536
**           0  2byte + 2byte-spare    00 0a 00 00   00 64 00 00   03 e8 00 00   illegal     
**           1  4byte                  00 00 00 0a   00 00 00 64   00 00 03 e8   00 01 00 00
**           2  native*                0a 00 00 00   64 00 00 00   e8 03 00 00   00 00 01 00
**           3  2byte                  00 0a         00 64         03 e8         illegal
**
** * Uses native encoding i.e. f->record->size is read/written for sizeof(f->record->size)
**   bytes (no mapping). This produces files that may be non-portable (across 
**   different architectures). Above results for INTEL - 32 bit int.
*/



#if WITH_VARSEQ == 0
#define MAX_RSZ 0xffff

#ifdef WORDS_BIGENDIAN

#define GET_RSZ	(fread(recsize.sbuff, 4, 1, f_generic->file) == 1) ? recsize.sshort[0] : -1

#define PUT_RSZ(rsz) \
			recsize.sint = 0; \
			recsize.sshort[0] = rsz; \
			erc = fwrite(recsize.sbuff, 4, 1, f_generic->file);
#else

#define GET_RSZ	(fread(recsize.sbuff, 4, 1, f_generic->file) == 1) ? COB_BSWAP_16(recsize.sshort[0]) : -1

#define PUT_RSZ(rsz) \
			recsize.sint = 0; \
			recsize.sshort[0] = COB_BSWAP_16((unsigned short)rsz); \
			erc = fwrite(recsize.sbuff, 4, 1, f_generic->file);

#endif
#endif



#if WITH_VARSEQ == 1
#define MAX_RSZ 0xffffffff

#ifdef WORDS_BIGENDIAN

#define GET_RSZ	(fread(recsize.sbuff, 4, 1, f_generic->file) == 1) ? recsize.sint : -1

#define PUT_RSZ(rsz) \
			recsize.sint = rsz; \
			erc = fwrite(recsize.sbuff, 4, 1, f_generic->file);
#else

#define GET_RSZ	(fread(recsize.sbuff, 4, 1, f_generic->file) == 1) ? COB_BSWAP_32(recsize.sint) : -1

#define PUT_RSZ(rsz) \
			recsize.sint = COB_BSWAP_32((unsigned int)rsz); \
			erc = fwrite(recsize.sbuff, 4, 1, f_generic->file);
#endif
#endif





#if WITH_VARSEQ == 2
#define MAX_RSZ MAX_INT

#define GET_RSZ	(fread(&recsize.sint, sizeof(int), 1, f_generic->file) == 1) ? recsize.sint : -1

#define PUT_RSZ(rsz) erc = fwrite(&rsz, sizeof(int), 1, f_generic->file)
#endif



#if WITH_VARSEQ == 3
#define MAX_RSZ 0xffff

#ifdef WORDS_BIGENDIAN

#define GET_RSZ	(fread(recsize.sbuff, 2, 1, f_generic->file) == 1) ? recsize.sshort[0] : -1

#define PUT_RSZ(rsz) \
			recsize.sint = 0; \
			recsize.sshort[0] = rsz; \
			erc = fwrite(recsize.sbuff, 2, 1, f_generic->file); 

#else

#define GET_RSZ	(fread(recsize.sbuff, 2, 1, f_generic->file) == 1) ? COB_BSWAP_16(recsize.sshort[0]) : -1

#define PUT_RSZ(rsz) \
			recsize.sint = 0; \
			recsize.sshort[0] = COB_BSWAP_16((unsigned short)rsz); \
			erc = fwrite(recsize.sbuff, 2, 1, f_generic->file); 
#endif
#endif




#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-sequential";
#endif


static int tf_ls_nulls = 0;		// insert a NUL (x00) before any character <= 0x1f
static int tf_ls_fixed = 0;		// treat LINE-SEQUENTIAL as SEQUENTIAL (i.e. don't trim trailing spaces)


static int eop_status = 0;




#define THROW_EXC(exc) { \
		cob_fileio_throw_exc(f, exc, COB_IO_CONTEXT_FILEIO_SEQUENTIAL); \
		return(-1); \
	}


// LINUX errno 1..256     
#define THROW_EXC_EXT(exc, errno) { \
		cob_fileio_throw_ext(f, exc, COB_IO_CONTEXT_FILEIO_SEQUENTIAL, COB_IO_REALM_COBOL, errno, strerror(errno)); \
		return(-1); \
	}


#define THROW_EXC_LS(exc) { \
		cob_fileio_throw_exc(f, exc, COB_IO_CONTEXT_FILEIO_LINE_SEQ); \
		return(-1); \
	}


// LINUX errno 1..256     
#define THROW_EXC_EXT_LS(exc, errno) { \
		cob_fileio_throw_ext(f, exc, COB_IO_CONTEXT_FILEIO_LINE_SEQ, COB_IO_REALM_COBOL, errno, strerror(errno)); \
		return(-1); \
	}






static int _sequential_file_write_opt(
	  cob_file_t *f
	, const int opt);

static int _sequential_linage_write_opt(
	  cob_file_t *f
	, const int opt);

static int _sequential_grab_linage(cob_file_t *f);




/*
 *	Initialise the OpenCOBOL fileio SEQUENTIAL sub-system.
 *	Called once per application execution cycle, prior to any IO.
 *	
 *	Environmental variables referenced [default]:
 *	COB_LS_NULLS :: insert a NUL (x00) before any character <= 0x1f [false]
 *	COB_LS_FIXED :: treat LINE-SEQUENTIAL as SEQUENTIAL
 *	                (i.e. don't trim trailing spaces) [false] 
 *	COB_UNIX_LF  :: on LINE-SEQUENTIAL add "b" for BINARY to open-mode.
 *	                This inhibits map '\n" to 0xOD0A - ON SOME SYSTEMS.
 *	                (It has no effect on LINUX & MinGW.)
*/

int cob_fileio_sequential_initialise() {

	tf_ls_nulls = cob_fileio_get_tf("COB_LS_NULLS");
	tf_ls_fixed = cob_fileio_get_tf("COB_LS_FIXED");
	tf_ls_binary = cob_fileio_get_tf("COB_UNIX_LF");

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_initialise() WITH_VARSEQ=%d  COB_LS_NULLS=%d  COB_LS_FIXED=%d\n"
		              , me, WITH_VARSEQ, tf_ls_nulls, tf_ls_fixed);
#endif

	return(0);
}





/*
 * Called once at program EOJ: release resources.
 *
 */

int cob_fileio_sequential_terminate() {

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_terminate()\n", me);
#endif

	return(0);
}








/*
 *	Open file - delegated to cob_fileio_generic_open()
 */
int cob_fileio_sequential_open(
	  cob_file_t *f 
	, const int mode) 
{
	int res;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_open(%s open_mode=%d) share_mode=%d lock_mode=%d\n"
		              , me, f->select_name, mode, f->share_mode, f->lock_mode);
#endif

	res = cob_fileio_generic_open(f, NULL, mode, COB_IO_CONTEXT_FILEIO_SEQUENTIAL);
	if (res == 0) {
		if (unlikely(f->flag_select_features & COB_SELECT_LINAGE)) {
			if (_sequential_grab_linage(f) != 0) {
				THROW_EXC(COB_IOEXC_SEQ_LINAGE);
			}
			f->linage->tf_needs_top = 1;
			cob_set_int(f->linage->cob_control, 1);
		} else {
			f->linage = NULL;
		}
	}
	return(res);
}








/*
 *	Close file - delegated to cob_fileio_generic_close()
 */

int cob_fileio_sequential_close(
	  cob_file_t *f
	, const int opt)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_close(%s opt=x%x)\n"
		              , me, f->select_name, opt);
#endif
	return(cob_fileio_generic_close(f, opt, COB_IO_CONTEXT_FILEIO_SEQUENTIAL));
}






/*
 *	SEQUENTIAL READ 
 *	(For LINE SEQUENTIAL READ see cob_fileio_line_sequential_read()).
 *	Read the next record. The file may be reading either fixed-length records
 *	or variable-length records (cf. notes above).
 *	For variable-length:
 *		If rsz of next record on file is less than record-area size, the 
 *		extra space is padded with spaces.
 *		If rsz of next record on file is more than record-area size, the
 *		extra data is skipped.
 *	
 *	Arg: opt is ignored.
 */

int cob_fileio_sequential_read(
	  cob_file_t *f
	, const int opt)
{
	int cb_get, cb_got, rsz;
	struct generic_file *f_generic = f->file;

#if	WITH_VARSEQ == 0 || WITH_VARSEQ == 1 || WITH_VARSEQ == 3
	union {
		unsigned char	sbuff[4];
		unsigned short	sshort[2];
		unsigned int	sint;
	} recsize;
#endif

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_read(%s opt=x%x)\n"
		              , me, f->select_name, opt);
#endif

	if (f->record_min != f->record_max) {
		if (-1 == (rsz = GET_RSZ)) {
			if (ferror(f_generic->file)) {
				THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
			} else {
				THROW_EXC(COB_IOEXC_R_XEOF);
			}
		}
		cb_get = (rsz > f->record_max) ? f->record_max : rsz;
	} else {
		cb_get = rsz = f->record_max;
	}
	cb_got = fread(f->record->data, 1, cb_get, f_generic->file);
	if (cb_got != cb_get) {
		if (ferror(f_generic->file)) {
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
		}
		if (cb_got == 0) {
			THROW_EXC(COB_IOEXC_R_XEOF);
		}
		THROW_EXC(COB_IOEXC_OK_RSZ);
	}
	if (cb_got < f->record_max) {
		// pad the record-area with spaces 
		memset(f->record->data+cb_got, ' ', f->record_max - cb_got);
	}
	if (cb_got < rsz) {
		// skip truncated record part
		fseek(f_generic->file, rsz - cb_got, SEEK_CUR);
	}
	f_generic->cb_rec = rsz; 
	if (f->record_size) {
		cob_set_int(f->record_size, cb_got);
	}
	return(0);
}




/*
 *	SEQUENTIAL WRITE
 *	(For LINE SEQUENTIAL WRITE see cob_fileio_line_sequential_write()).
 *	If opt & COB_WRITE_AFTER advance line/page.
 *	Write the record.
 *	If opt & COB_WRITE_BEFORE advance line/page.
 *	The length of the record to be written is cb_rec.
 *	
 */

int cob_fileio_sequential_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	int	erc;
	struct generic_file *f_generic = f->file;

#if	WITH_VARSEQ == 0 || WITH_VARSEQ == 1 || WITH_VARSEQ == 3
	union {
		unsigned char	sbuff[4];
		unsigned short	sshort[2];
		unsigned int	sint;
	} recsize;
#endif

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_write(%s, rsz=%d, opt=x%x)\n"
		              , me, f->select_name, cb_rec, opt);
#endif


	if (cb_rec > MAX_RSZ) {
		THROW_EXC(COB_IOEXC_VAR_RSZ);
	}
	if (opt & COB_WRITE_AFTER) {
		erc = _sequential_file_write_opt(f, opt);
		if (erc != 0) 
			return(-1);
		f->tf_needs_nl = 1;
	}
	if (f->record_min != f->record_max) {
		PUT_RSZ(cb_rec);
		if (erc != 1) {
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
		}
	}
	if (fwrite(f->record->data, cb_rec, 1, f_generic->file) != 1) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
	}
	if (opt & COB_WRITE_BEFORE) {
		erc = _sequential_file_write_opt(f, opt);
		if (erc != 0) {
			return(-1);
		}
		f->tf_needs_nl = 0;
	}
	return(0);
}







/*
 *	Overwrite the current by rewinding f->record->size bytes 
 *	and writing f->record->size bytes from f->record->data.
 *	The length of the record to be written is f->record->size;
 *	it must equal the current record.
 *	
 */

int cob_fileio_sequential_rewrite(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	int rb;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_rewrite(%s, rsz=%d, opt=x%x)\n"
		              , me, f->select_name, cb_rec, opt);
#endif


	// All ORGANIZATIONs length of new record must = record being replaced
	if (cb_rec != f_generic->cb_rec) {
		#ifdef  WITH_FILEIO_TRACE
			if (trace_level > 3) {
				fprintf(stderr, "%s: illegal attempt to rewrite SEQUENTIAL record of different length\n", me);
				fprintf(stderr, "%s: ... Prior rec read = %d bytes. New record to write = %d bytes.\n"
				      , me, f_generic->cb_rec, cb_rec);
			}
		#endif
		THROW_EXC(COB_IOEXC_REWRITE_RSZ);	
	}
	//  Explicit reposition because MinGW loses current file position after fwrite()
	rb = ftell(f_generic->file);
	if (fseek(f_generic->file, -(off_t)f_generic->cb_rec, SEEK_CUR)) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
	}
	if (fwrite(f->record->data, f_generic->cb_rec, 1, f_generic->file) != 1) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
	}
	if (fseek(f_generic->file, rb, SEEK_SET)) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
	}
	return(0);
}






/*
 * Synchronise the file by flushing the underlying file
 */

int cob_fileio_sequential_sync(
	  cob_file_t *f
	, const int mode)
{
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_sync(%s mode=%d)\n"
		              , me, f->select_name, mode);
#endif

	if (0 != fflush(f_generic->file)) {
		THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
	}
	if (mode == COB_SYNC_PHYSICAL) {
		if (0 != fdcobsync(fileno(f_generic->file))) {
			THROW_EXC_EXT(COB_IOEXC_ERROR, errno);
		}
	}
	return(0);
}





/*
 *	Flush the underlying file and remove all record locks.
 *	delegated to cob_fileio_generic_unlock()
 */

int cob_fileio_sequential_unlock(cob_file_t *f)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sequential_unlock(%s)\n"
		              , me, f->select_name);
#endif

	return(cob_fileio_generic_unlock(f, COB_IO_CONTEXT_FILEIO_SEQUENTIAL));	
}





/*
 *	Delete the file - delegated to cob_fileio_generic_erase()
 */

int cob_fileio_sequential_erase(cob_file_t *f)
{
	return(cob_fileio_generic_erase(f, COB_IO_CONTEXT_FILEIO_SEQUENTIAL));	
}










/*
 *	LINE SEQUENTIAL READ
 *	(For SEQUENTIAL READ see cob_fileio_sequential_read()).
 *	Read the next record. Each record is terminated by a NL character.
 *	If rsz of next record on file is less than f->record->size, the 
 *	extra space is padded with spaces.
 *	If rsz of next record on file is more than f->record->size, the
 *	extra data is skipped.
 *	
 *	Arg: opt is ignored.
 */


int cob_fileio_line_sequential_read(
	  cob_file_t *f
	, const int opt)
{
	struct generic_file *f_generic = f->file;
	unsigned char *pb_rec;
	int cb_rec = 0;
	int n;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_line_sequential_read(%s opt=x%x)\n"
		              , me, f->select_name, opt);
#endif

	pb_rec = f->record->data;
	for (; ;) {
		n = getc(f_generic->file);
		if (unlikely(n == EOF)) {
			if (cb_rec == 0) {
				THROW_EXC_LS(COB_IOEXC_R_XEOF);
			}
			break;
		}
		if (unlikely((n == 0) && tf_ls_nulls)) {
			n = getc(f_generic->file);
			if (n == EOF) {
				THROW_EXC_LS(COB_IOEXC_RECSHORT);
			}
		} else {
			if (n == '\r')
				continue;
			if (n == '\n')
				break;
		}
		if (likely(cb_rec < f->record_max)) {
			*pb_rec++ = n;
			cb_rec++;
		}
	}
	if (cb_rec < f->record_max) {
		// pad the record with spaces 
		memset(pb_rec, ' ', f->record_max - cb_rec);
	}
	if (f->record_size) {
		cob_set_int(f->record_size, cb_rec);
	}
	return(0);
}








/*
 *	LINE SEQUENTIAL WRITE
 *	(For SEQUENTIAL WRITE see cob_fileio_sequential_write()).
 *	cb_rec is the length of the line prior to truncation of trailing spaces. 
 *	If opt & COB_WRITE_AFTER advance line/page.
 *	Write the record.
 *	If opt & COB_WRITE_BEFORE advance line/page.
 *	
 */

int cob_fileio_line_sequential_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt)
{
	struct generic_file *f_generic = f->file;
	unsigned char *pb_rec;
	int cb_write;
	int i;
	int erc;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_line_sequential_write(%s opt=x%x)\n"
		              , me, f->select_name, opt);
#endif


	// determine the size to be written
	if (unlikely(tf_ls_fixed)) {
		cb_write = cb_rec;
	} else {
		for (i = cb_rec - 1; i >= 0; i--) {
			if (f->record->data[i] != ' ') {
				break;
			}
		}
		cb_write = i + 1;
	}
	if (unlikely(f->flag_select_features & COB_SELECT_LINAGE)) {
		if (f->linage->tf_needs_top) {
			f->linage->tf_needs_top = 0;
			for (i = 0; i < f->linage->i_top; i++) {
				putc('\n', f_generic->file);
			}
		}
	}
	if (opt & COB_WRITE_AFTER) {
		erc = _sequential_file_write_opt(f, opt);
		if (erc != 0) 
			return(erc);
		f->tf_needs_nl = 1;
	}
	if (cb_write > 0) {
		if (unlikely(tf_ls_nulls)) {
			for (i = 0, pb_rec = f->record->data; i < cb_write; i++, pb_rec++) {
				if (*pb_rec < ' ') {
					putc(0, f_generic->file);
				}
				putc((int)(*pb_rec), f_generic->file);
			}
		} else {
			if (unlikely(fwrite (f->record->data, cb_write, 1, f_generic->file) != 1)) {
				THROW_EXC_EXT_LS(COB_IOEXC_ERROR, errno);
			}
		}
	}
	if (unlikely(f->flag_select_features & COB_SELECT_LINAGE)) 
		putc ('\n', f_generic->file);
	if (opt & COB_WRITE_BEFORE) {
		erc = _sequential_file_write_opt(f, opt);
		if (erc != 0) 
			return(erc);
		f->tf_needs_nl = 0;
	}
	if (unlikely(eop_status)) {
		eop_status = 0;
		THROW_EXC_LS(COB_IOEXC_LSEQ_PAGE);
	}
	return(0);
}



/*
 *	Coin some info about myself in XML for fileio-stats.
 *	The pointer returned is malloc'd and should be free'd
 *	by the client. 
 */

char *cob_fileio_sequential_stats_env(const char *indent)
{
	char *xml = cob_malloc(1000);
	char *pb = xml;

	pb += sprintf(pb, "%s<prefix_null_to_control_char var=\"COB_LS_NULLS\" value=\"%s\" >\n"
	            , indent, getenv("COB_LS_NULLS"));
	pb += sprintf(pb, "%s\t%d\n", indent, tf_ls_nulls);
	pb += sprintf(pb, "%s</prefix_null_to_control_char>\n", indent);
	pb += sprintf(pb, "%s<retain_trailing_spaces var=\"COB_LS_FIXED\" value=\"%s\" >\n"
	            , indent, getenv("COB_LS_FIXED"));
	pb += sprintf(pb, "%s\t%d\n", indent, tf_ls_fixed);
	pb += sprintf(pb, "%s</retain_trailing_spaces>\n", indent);
	xml = realloc(xml, strlen(xml) + 1);
	return(xml);
}









/*
 *	Skip lines/page depending on opt:
 *	opt flags:
 *		COB_WRITE_LINES ... write n NL-s where n = opt & COB_WRITE_MASK
 *		COB_WRITE_PAGE .... write a single FF  
 */

static int _sequential_file_write_opt (
	  cob_file_t *f
	, const int opt)
{
	int	i;
	struct generic_file *f_generic = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _sequential_file_write_opt(%s opt=x%x)\n"
		              , me, f->select_name, opt);
#endif

	if (unlikely(f->flag_select_features & COB_SELECT_LINAGE)) {
		return(_sequential_linage_write_opt(f, opt));
	}
	if (opt & COB_WRITE_LINES) {
		for (i = opt & COB_WRITE_MASK; i > 0; i--)
			putc('\n', f_generic->file);
	} else if (opt & COB_WRITE_PAGE) {
		putc('\f', f_generic->file);
	}
	return(0);
}









static int COB_NOINLINE _sequential_linage_write_opt(
	  cob_file_t *f
	, const int opt)
{
	struct generic_file *f_generic = f->file;
	int cursor, bookmark, i, n;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _sequential_linage_write_opt(%s opt=x%x)\n"
		              , me, f->select_name, opt);
#endif

	cursor = cob_get_int(f->linage->cob_control);
	if (cursor <= 0) 
		THROW_EXC(COB_IOEXC_SEQ_LINAGE);
	
	if (unlikely(opt & COB_WRITE_PAGE)) {
		n = f->linage->i_linage;
		for (; cursor < n; cursor++) {
			putc('\n', f_generic->file);
		}
		for (i = 0; i < f->linage->i_bot; i++) {
			putc('\n', f_generic->file);
		}
		if (0 != _sequential_grab_linage(f))
			THROW_EXC(COB_IOEXC_SEQ_LINAGE);
		for (i = 0; i < f->linage->i_top; i++) {
			putc('\n', f_generic->file);
		}
		cob_set_int (f->linage->cob_control, 1);
	} else if (opt & COB_WRITE_LINES) {
		bookmark = cursor + (opt & COB_WRITE_MASK);
		if ((opt & COB_WRITE_EOP) && f->linage->i_foot) {
			if (bookmark >= f->linage->i_foot) {
				eop_status = 1;
			}
		}
		if (bookmark > f->linage->i_linage) {
			if (opt & COB_WRITE_EOP) {
				eop_status = 1;
			}
			for (; cursor < f->linage->i_linage; cursor++) {
				putc('\n', f_generic->file);
			}
			for (i = 0; i < f->linage->i_bot; i++) {
				putc('\n', f_generic->file);
			}
			if (0 != _sequential_grab_linage(f))
				THROW_EXC(COB_IOEXC_SEQ_LINAGE);
			cob_set_int(f->linage->cob_control, 1);
			for (i = 0; i < f->linage->i_top; i++) {
				putc('\n', f_generic->file);
			}
		} else {
			for (i = (opt & COB_WRITE_MASK) - 1; i > 0; i--)
				putc('\n', f_generic->file);
			cob_set_int(f->linage->cob_control, bookmark);
		}
	}
	return(0);
}






/*
 *	Initialise LINAGE.
 *	Copy the Linage cob_field items into int format.
 *	Returns 0 on success.
 */
static int _sequential_grab_linage(cob_file_t *f)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _sequential_grab_linage(%s)\n"
		              , me, f->select_name);
#endif

	f->linage->i_top = 0;
	f->linage->i_foot = 0;
	f->linage->i_bot = 0;
	f->linage->i_linage = cob_get_int(f->linage->cob_linage);
	if (f->linage->i_linage < 1) {
		return(1);
	}
	if (f->linage->cob_foot) {
		f->linage->i_foot = cob_get_int(f->linage->cob_foot);
		if ((f->linage->i_foot < 1) || (f->linage->i_foot > f->linage->i_linage)) {
			return(1);
		}
	}
	if (f->linage->cob_top) {
		f->linage->i_top = cob_get_int (f->linage->cob_top);
		if (f->linage->i_top < 0) {
			return(1);
		}
	}
	if (f->linage->cob_bot) {
		f->linage->i_bot = cob_get_int (f->linage->cob_bot);
		if (f->linage->i_bot < 0) {
			return(1);
		}
	}
	return 0;
}


#endif	// WITH_SEQUENTIAL



