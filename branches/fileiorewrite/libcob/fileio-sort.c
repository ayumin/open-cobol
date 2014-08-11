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




#include <stdarg.h>
#include "fileio-misc.h"
#include "fileio-sort.h"


/*
 *	fileio-sort.c
 *	
 *	OpenCOBOL fileio component handling SORT/MERGE.
 *	
 *	The COBOL source statement:
 *	
 *		sort file1
 *		   on ascending key file1-key1
 *		   on ascending key file1-key2
 *		   using file2
 *		   giving file3.
 *
 *	Generates C statements:
 *		cob_file_sort_init (h_FILE1, 2, 0, b_2, &f_24);
 *		cob_file_sort_init_key (h_FILE1, &f_6, 0, 0);
 *		cob_file_sort_init_key (h_FILE1, &f_7, 0, 1);
 *		cob_file_sort_using (h_FILE1, h_FILE2);
 *		cob_file_sort_giving (h_FILE1, 1, h_FILE3);
 *		cob_file_sort_close (h_FILE1);
 *
 *	
 */





#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-sort";
#endif



#ifndef O_BINARY
#define O_BINARY        0
#endif

#ifndef O_LARGEFILE
#define O_LARGEFILE     0
#endif





#define SORT_RESULT_END      1
#define SORT_RESULT_ABORT    2
#define SORT_RESULT_ERROR    3
#define SORT_RESULT_NOPEN    4


int sort_memory = 128;           // max size permitted to malloc (Mb) for SUNs
                                 // released to sort (before work-files needed)


/*
 *	sort_unit represents each record released to the SORT.
 *	sort_unit-s are stored in the queues, compared and
 *	swapped.
 *
 *	CAUTION: The record data is stored in sort_unit.record_data;
 *	this means extra space is malloc'd for sort_unit.
 *
 *	The abbreviation SUN refers to a sort_unit.
 *
 *	When a limit is exceeded, the SUNs in each queue are
 *	sorted then flushed to disk. Otherwise, sorting takes
 *	place in memory.
 */

#define CB_SUN (sizeof(sort_unit_t) + f_sort->cb_record - 1)
#define CB_SUN_ON_DISK (sizeof(int) + f_sort->cb_record)

typedef struct sort_unit {
	struct sort_unit       *next_sun;              // chain to next sun
	char                    tf_eob;                // true: this is last SUN in an ordered block
	struct {
		int             serial;                // unique serialised int 
		unsigned char   record_data[1];        // (extended) area to store record
	} disk_sun;                                    // part of SUN persisted when flushed to disk
} sort_unit_t;



typedef struct {
	sort_unit_t        *first_sun;             // pointer to head of chain 
	sort_unit_t        *last_sun;              // pointer to tail of chain 
	int                 cnt_sun;               // count SUNs in chain 
} sort_chain_t;



typedef struct {
	FILE               *fp;
	int                 cnt_sun;               // count SUNs in work-file
} workfile_t;





typedef struct {
	cob_file_t          *cob_file;             // corresponding file (SELECT/SD) in COBOL program
	int                 *pi_sort_return;       // returns int sort status to client
	cob_field           *fnstatus;             // client's file status field
	char                 tf_retrieving;        // true: has entered sort phase (after release phase)
	char                 tf_wfiles_used;       // true: work-files were required (sorted data > mem allocated)
	int                  i_serial;             // incremented by 1 as each record released
	int                  i_wfile;              // indicates which of 2 work-files receives next block of SUNs
	int                  cnt_sun_max;          // max number of SUNs allowed in memory (cf. sort_memory)
	size_t               cb_record;            // data-record size
	sort_unit_t         *q_free_sun;           // queue of recyclable SUNs
	int                  iq_final;             // number of queue containing final sorted SUNs
	sort_chain_t         queue[4];             // queues used to store and sort SUNs
	workfile_t           file[4];              // workfiles used to save SUN queues when insufficient memory
} sort_file_t;



static char *dir_temp;                         // name of folder used to store temporary work-files

#ifndef _WIN32
static int i_sort_file = 0;                    // qualifier used to generate a unique filename
static pid_t pid_sort_file = 0;                // pid of this process
#endif







#define SET_EXC(exc) \
	cob_fileio_throw_exc(f_sort->cob_file, exc, COB_IO_CONTEXT_FILEIO_SORT);

#define SET_EXC_OS(exc, errno) \
	cob_fileio_throw_ext(f_sort->cob_file, exc, COB_IO_CONTEXT_FILEIO_SORT \
			, COB_IO_REALM_OS, errno, strerror(errno)); \






static int _sort_cmp(
	  const unsigned char *s1
	, const unsigned char *s2
	, const size_t size
	, const unsigned char *col);

static int _sort_compare(
	  sort_unit_t *sun1
	, sort_unit_t *sun2
	, cob_file_t *cob_file);

static void _sort_free_queue(
	  sort_unit_t *q);

static sort_unit_t *_sort_get_new_sun(
	  sort_file_t *f_sort);

static FILE * COB_NOINLINE _sort_open_tmpfile(
	  sort_file_t *f_sort);

static void COB_NOINLINE _sort_initialise_temp_file(
	  sort_file_t *f_sort
	, const int n);

static int _sort_queues(
	  sort_file_t *f_sort);

static int _sort_workfiles(
	  sort_file_t *f_sort);

static int _sort_read_next_sun(
	  sort_file_t *f_sort
	, const int iq);

static int _sort_write_sun(
	  sort_file_t *f_sort
	, FILE *fp
	, sort_unit_t *sun);

static int _sort_write_eob(
	  sort_file_t *f_sort
	, FILE *fp);

static int _sort_flush_queue(
	  sort_file_t *f_sort
	, const int iq);

static void _sort_copy_record (
	  cob_file_t *to
	, cob_file_t *from);

static int _sort_process(
	  sort_file_t *f_sort);

static int _sort_submit_record(
	  sort_file_t *f_sort
	, const unsigned char *pb_record);

static int _sort_retrieve(
	  sort_file_t *f_sort
	, unsigned char *pb_record);















/*
 *	Called once at program BOJ: initialise variables.
 *
 *	Environmental variables referenced [default]:
 *	COB_SORT_MEMORY :: size of malloc-d w/space [128Mb]
 *	                   < 1024*1024 ... Mbytes else bytes
 *
 *	TMPDIR TMP TEMP :: name of directory to store temporary work-files [/tmp]	 
 */
int cob_fileio_sort_initialise() {
	const char *s;
	int n;

	if ((s = getenv("COB_SORT_MEMORY")) != NULL) {
		n = atoi(s);
		if (n >= 1024*1024) {
			sort_memory = n / (1024*1024);
		} else if (n > 0) {
			sort_memory = n;
		}
	}
	dir_temp = cob_malloc(FILENAME_MAX);
	cob_fileio_get_dirtmp(dir_temp);
	dir_temp = realloc(dir_temp, strlen(dir_temp)+1);

#ifndef _WIN32
	pid_sort_file = getpid();
#endif


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sort_initialise() sort_memory=%dMb  dir_temp='%s'\n"
		      , me, sort_memory, dir_temp);
#endif

	return(0);
}








/*
 *	Called once at program EOJ: release resources.
 *
 */

int cob_fileio_sort_terminate() {

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_sort_terminate()\n", me);
#endif

	return(0);
}






/*
 *	Prepare a sort file for processing.
 */

void cob_file_sort_init(
	  cob_file_t *f
	, const int cnt_keys
	, const unsigned char *collating_sequence
	, void *sort_return
	, cob_field *fnstatus)
{
	sort_file_t *f_sort;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_file_sort_init()\n", me);
#endif

	cob_fileio_begin(f, COB_IO_VERB_SORT_OPEN);
	f_sort = cob_malloc(sizeof (sort_file_t));
	f_sort->tf_retrieving = 0;
	f_sort->tf_wfiles_used = 0;
	f_sort->cb_record = f->record_max;
	f_sort->fnstatus = fnstatus;
	f_sort->cob_file = f;
	f_sort->cnt_sun_max = (sort_memory * 1024 * 1024) / CB_SUN;
	f_sort->pi_sort_return = (int *)sort_return;
	*f_sort->pi_sort_return = 0;

	f->file = f_sort;
	f->keys = cob_malloc(sizeof(cob_file_key_t) * cnt_keys);
	f->nkeys = 0;
	if (collating_sequence) {
		f->sort_collating = collating_sequence;
	} else {
		f->sort_collating = APP_MODULE->collating_sequence;
	}
	cob_fileio_save_status(f, f_sort->fnstatus);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: exit cob_file_sort_init() rsz=%d  cnt_keys=%d  cnt_sun_max=%d\n"
              , me, f_sort->cb_record, cnt_keys, f_sort->cnt_sun_max);
#endif

}




/*
 *	Note the keys to be used for the sort.
 */

void cob_file_sort_init_key(
	  cob_file_t *f
	, cob_field *field
	, const int tf_ascending
	, size_t offset)
{
#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 3)
		fprintf(stderr, "%s: cob_file_sort_init_key()[%d] %s\n"
                      , me, f->nkeys, tf_ascending ? "ASC" : "DESC");
#endif
	f->keys[f->nkeys].tf_ascending = tf_ascending;
	f->keys[f->nkeys].field = field;
	f->keys[f->nkeys].offset = offset;
	f->nkeys++;
}




/*
 *	Close a sort file, releasing all associated resources.
 */

void cob_file_sort_close(cob_file_t *f)
{
	sort_file_t *f_sort = f->file;
	cob_field *fnstatus = NULL;
	int i;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_file_sort_close()\n", me);
#endif

	cob_fileio_begin(f, COB_IO_VERB_SORT_CLOSE);
	if (f_sort != NULL) {
		fnstatus = f_sort->fnstatus;
		_sort_free_queue(f_sort->q_free_sun);
		for (i = 0; i < 4; i++) {
			_sort_free_queue(f_sort->queue[i].first_sun);
			if (f_sort->file[i].fp != NULL) {
				if (0 != fclose(f_sort->file[i].fp)) {
					SET_EXC_OS(COB_IOEXC_ERROR, errno);
				}
			}
		}
		free(f_sort);
	}
	f->file = NULL;
	cob_fileio_save_status(f, f_sort->fnstatus);
}






/*
 *	Release records in data_file to the sort file f.
 *	The data file is opened. Each record is read and submitted
 *	to the sort. The data file is then closed.
 */	

void cob_file_sort_using(
	  cob_file_t *f
	, cob_file_t *data_file)
{
	sort_file_t *f_sort = f->file;
	exception_t exc_save;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_file_sort_using()\n", me);
#endif

	cob_fileio_begin(f, COB_IO_VERB_SORT_USING);
	cob_open(data_file, COB_OPEN_INPUT, COB_SHARE_ALL, COB_LOCK_MANUAL, 0, NULL);
	if (COB_EXC_OK) {
		while(COB_EXC_OK) {
			cob_read(data_file, NULL, NULL, COB_READ_NEXT);
			if (COB_EXC_OK) {
				_sort_copy_record(f, data_file);
				_sort_submit_record(f_sort, f->record->data);
			}
		}
		// ensure any exc thrown in close() doesn't mask original exc
		exc_save = exc;
		cob_close(data_file, NULL, COB_CLOSE_NORMAL, 0);
		exc = exc_save;
	}
	cob_fileio_save_status(f, f_sort->fnstatus);
	return;
}





/*
 *	Sort the released records and write the results to
 *	one or more files. 
 */

void cob_file_sort_giving(
	  cob_file_t *f
	, const size_t varcnt
	, ...)
{
	int i, opt;
	exception_t exc_save;
	va_list args;
	cob_file_t **f_op;
	sort_file_t *f_sort = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 0)
		fprintf(stderr, "%s: cob_file_sort_giving()\n", me);
#endif


	cob_fileio_begin(f, COB_IO_VERB_SORT_GIVING);
	f_op = cob_malloc(varcnt * sizeof(cob_file_t *));
	va_start(args, varcnt);
	for (i = 0; i < varcnt; i++) {
		f_op[i] = va_arg(args, cob_file_t *);
	}
	va_end(args);
	for (i = 0; i < varcnt; i++) {
		cob_open(f_op[i], COB_OPEN_OUTPUT, COB_SHARE_EXCLUSIVE, COB_LOCK_MANUAL, 0, NULL);
		if (!COB_EXC_OK) {
			break;
		}
	}
	while (COB_EXC_OK) {
		_sort_retrieve(f_sort, f->record->data);
		if (COB_EXC_OK) {
			for (i = 0; i < varcnt; i++) {
				opt = 0;
				if (f_op[i]->special ||
			    	(f_op[i]->organization == COB_ORG_LINE_SEQUENTIAL)) {
					opt = COB_WRITE_BEFORE | COB_WRITE_LINES | 1;
				}
				_sort_copy_record(f_op[i], f);
				cob_write(f_op[i], f_op[i]->record, opt, NULL, 0);
			}
		}
	}
	// ensure any exc thrown in close() doesn't mask original exc
	exc_save = exc;
	for (i = 0; i < varcnt; i++) {
		cob_close(f_op[i], NULL, COB_CLOSE_NORMAL, 0);
	}
	exc = exc_save;
	cob_fileio_save_status(f, f_sort->fnstatus);
	free(f_op);
}



/*
 *	Release record in record-area to the sort file f.
 */

void cob_file_release(cob_file_t *f)
{
	sort_file_t *f_sort = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_file_release()\n", me);
#endif

	cob_fileio_begin(f, COB_IO_VERB_SORT_RELEASE);
	_sort_submit_record(f_sort, f->record->data);
	cob_fileio_save_status(f, f_sort->fnstatus);
}





/*
 *	Fetch the next sorted record and place it in f->record
 */

void cob_file_return(cob_file_t *f)
{
	sort_file_t *f_sort = f->file;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_file_return()\n", me);
#endif

	cob_fileio_begin(f, COB_IO_VERB_SORT_RETURN);
	_sort_retrieve(f_sort, f->record->data);
	cob_fileio_save_status(f, f_sort->fnstatus);
}













/*
 *   P R I V A T E   F U N C T I O N S
 */



/*
 *	Compare the first size bytes of strings s1 and s2
 *	using the optional collating sequence col.
 *	Return:
 *		-1 if s1 <  s2
 *		 0 if s1 == s2
 *		+1 if s1  > s2
 */

static int _sort_cmp(
	  const unsigned char *s1
	, const unsigned char *s2
	, const size_t size
	, const unsigned char *col)
{
	size_t i;
	int ret;

	if (unlikely(col != NULL)) {
		for (i = 0; i < size; i++) {
			if ((ret = col[s1[i]] - col[s2[i]]) != 0) {
				return ret;
			}
		}
	} else {
		for (i = 0; i < size; i++) {
			if ((ret = s1[i] - s2[i]) != 0) {
				return ret;
			}
		}
	}
	return 0;
}






/*
 *	Compare the sort units sun1 and sun2.
 *	Comparison is achieved by, for each sort-key,
 *	extracting the key value from the record data
 *	in the SUN and performing either a COBOL
 *	numeric comparison or our own string comparison.
 *
 *		-1 if sun1 <  sun2
 *		 0 if sun1 == sun2
 *		+1 if sun1  > sun2
 */

static int _sort_compare(
	  sort_unit_t *sun1
	, sort_unit_t *sun2
	, cob_file_t *cob_file)
{
	size_t i;
	int cmp;
	cob_field f1, f2;

	for (i = 0; i < cob_file->nkeys; i++) {
		// make 2 independent copies of key-field
		f1 = f2 = *(cob_file->keys[i].field);      
		f1.data = sun1->disk_sun.record_data + cob_file->keys[i].offset;
		f2.data = sun2->disk_sun.record_data + cob_file->keys[i].offset;
		if (COB_FIELD_IS_NUMERIC(&f1)) {
			cmp = cob_numeric_cmp(&f1, &f2);
		} else {
			cmp = _sort_cmp(f1.data, f2.data, f1.size, cob_file->sort_collating);
		}
		if (cmp != 0) {
			return((cob_file->keys[i].tf_ascending) ? cmp : -cmp);
		}
	}
	if (sun1->disk_sun.serial < sun1->disk_sun.serial) {
		return(-1);
	}
	return(1);
}






/*
 *	Free every SUN in list q
 */

static void _sort_free_queue(sort_unit_t *q)
{
	sort_unit_t	*next;
	while (q != NULL) {
		next = q->next_sun;
		free(q);
		q = next;
	}
}



/*
 *	Return the address of a free SUN.
 *	A SUN will be recycled from the free-sun queue if any are
 *	available. Otherwise space is malloc-d.
 */

static sort_unit_t *_sort_get_new_sun(sort_file_t *f_sort)
{
	sort_unit_t *sun;

	if (f_sort->q_free_sun != NULL) {
		// pop one off the top of the free-sun-queue
		sun = f_sort->q_free_sun;
		f_sort->q_free_sun = sun->next_sun;
	} else {
		sun = cob_malloc(CB_SUN);
	}
	return sun;
}




/*
 *	Return an open FILE to be used as a workfile
 *	On error: sets exception and returns NULL
 */

static FILE * COB_NOINLINE _sort_open_tmpfile(sort_file_t *f_sort)
{
	FILE *fp;
	int fd;
	char fid[FILENAME_MAX];

#ifdef _WIN32
	GetTempFileName (dir_temp, "cob", 0, fid);
	DeleteFile(fid);
	if (0 > (fd = _open(fid, _O_CREAT | _O_TRUNC | _O_RDWR | _O_BINARY, 0660))) {
		SET_EXC_OS(COB_IOEXC_ERROR, errno);
		return(NULL);
	}
	if (trace_level == 0)
		_unlink(fid);			// ensure temp file "removed" on close
	fp = _fdopen(fd, "w+b");
	if (fp == NULL) {
		SET_EXC_OS(COB_IOEXC_ERROR, errno);
		_close(fd);
	}

#else

	sprintf(fid, "%s/sort_file%d_%d", dir_temp, pid_sort_file, i_sort_file);
	i_sort_file++;
	if (0 > (fd = open(fid, O_CREAT | O_TRUNC | O_RDWR | O_BINARY | O_LARGEFILE, 0660))) {
		SET_EXC_OS(COB_IOEXC_ERROR, errno);
		return(NULL);
	}
	if (trace_level == 0)
		unlink(fid);	 		// ensure temp file "removed" on close
	fp = fdopen(fd, "w+b");
	if (fp == NULL) {
		SET_EXC_OS(COB_IOEXC_ERROR, errno);
		close(fd);
	}

#endif


#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _sort_open_tmpfile() => '%s'\n", me, fid);
#endif

	return fp;
}








/*
 *	Initialise the n'th work-file of sort-file f_sort.
 *	On first time (for n) a temporary file is opened.
 *	On successive occasions, the existing file is rewound.
 *	The count is zero'd.
 *	This function does not return if an error is thrown.
 */ 

static void COB_NOINLINE _sort_initialise_temp_file(
	  sort_file_t *f_sort
	, const int n)
{

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _sort_initialise_temp_file(n=%d)\n", me, n);
#endif

	if (f_sort->file[n].fp == NULL) {
		f_sort->file[n].fp = _sort_open_tmpfile(f_sort);
		if (f_sort->file[n].fp == NULL) {
			cob_runtime_error("SORT is unable to acquire temporary file");
			cob_stop_run(1);
		}
	} else {
		rewind(f_sort->file[n].fp);
	}
	f_sort->file[n].cnt_sun = 0;
}







/*
 *	The heart of the sort algorithm.
 *	SYNOPSIS: there are 4 sort queues used: Q0 Q1 Q2 Q3
 *	On entry, Q0 and Q1 contain the SUNs to be sorted, in
 *	an unsorted order (i.e. same order as the records were 
 *	released to the sort). Each SUN was flagged tf_eob = true.
 *
 *	Initially: the 2 source queues (SQ0 SQ1) are Q0 and Q1. The
 *  destination queues (DQ0 DQ1) are Q2 and Q3.
 *	The top SUN in SQ0 is compared to the top SUN in SQ1. The 
 *	SUN with the lower key is moved to DQ0.
 *	When a SUN with tf_eob has been moved, the SUN in DQ0 is
 *	is set tf_eob = true; NO MORE SUNs are consumed from that
 *	source. When both SQ0 and SQ1 are blocked the destination
 *	queue is switched to its partner DQ1.
 *	This process repeats until all the SUNs in SQ0 and SQ1
 *	have been consumed. At this stage DQ0 and DQ1 will contain
 *	runs (of arbitrary length) of sorted SUNs; the last SUN
 *	in each run has tf_eob set.
 *	The process is reiterated with DQ0, DQ1 substituting for
 *	SQ0, SQ1; and SQ0, SQ1 becoming empty DQ0, DQ1.
 *	This continues until all the SUNs are in one DQ in
 *	sorted order.
 *	The number of the final queue is returned to the caller.  
 */

static int _sort_queues(sort_file_t *f_sort)
{
	sort_unit_t	*sun;
	int source, destination, move, cmp;
	char tf_eob[2];

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _sort_queues()\n", me);
#endif

	source = 0;
	while (f_sort->queue[source + 1].cnt_sun != 0) {
		// establish destination: SQ0 == 0 -> 2   SQ0 == 2 -> 0
		destination = source ^ 2;
		f_sort->queue[destination].cnt_sun = f_sort->queue[destination + 1].cnt_sun = 0;
		f_sort->queue[destination].first_sun = f_sort->queue[destination + 1].first_sun = NULL;
		while (1) {
			tf_eob[0] = (f_sort->queue[source].cnt_sun == 0);
			tf_eob[1] = (f_sort->queue[source + 1].cnt_sun == 0);
			if (tf_eob[0] && tf_eob[1]) {
				break;
			}
			while (!tf_eob[0] || !tf_eob[1]) {
				// determine which SQ to take SUN from
				if (tf_eob[0]) {
					move = 1;
				} else if (tf_eob[1]) {
					move = 0;
				} else {
					cmp = _sort_compare(f_sort->queue[source].first_sun
					                  , f_sort->queue[source + 1].first_sun
					                  , f_sort->cob_file);
					move = cmp < 0 ? 0 : 1;
				}
				sun = f_sort->queue[source + move].first_sun;
				if (sun->tf_eob) {
					// last SUN in current run - consume no more
					tf_eob[move] = 1;
				}
				// move the target SUN from SQ to DQ
				f_sort->queue[source + move].first_sun = sun->next_sun;
				if (f_sort->queue[destination].first_sun == NULL) {
					f_sort->queue[destination].first_sun = sun;
				} else {
					f_sort->queue[destination].last_sun->next_sun = sun;
				}
				f_sort->queue[destination].last_sun = sun;
				f_sort->queue[source + move].cnt_sun--;
				f_sort->queue[destination].cnt_sun++;
				sun->next_sun = NULL;
				sun->tf_eob = 0;
			}
			// mark last SUN moved as last in sorted run (block)
			f_sort->queue[destination].last_sun->tf_eob = 1;
			// flip/flop destinations: Q0 <--> Q1  Q2 <--> Q3
			destination ^= 1;
		}
		// switch SQ0 <- DQ0
		// destination == 0 || 1 ... SQ0 <- 0
		// destination == 2 || 3 ... SQ0 <- 2
		source = destination & 2;
	}
	return(source);
}





/*
 *	Using the same algorithms as _sort_queues(): sort/merge
 *	workfiles 0 and 1.
 *	On success: the number of the final queue/file is returned.
 *	Otherwise: sets exception and returns -1  
 */

static int _sort_workfiles(sort_file_t *f_sort)
{
	int iq, source, destination, move, cmp;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _sort_workfiles()\n", me);
#endif


	// place a new SUN at the top of each queue
	for (iq = 0; iq < 4; iq++) {
		f_sort->queue[iq].first_sun = f_sort->q_free_sun;
		f_sort->q_free_sun = f_sort->q_free_sun->next_sun;
		f_sort->queue[iq].first_sun->next_sun = NULL;
	}
	rewind(f_sort->file[0].fp);
	rewind(f_sort->file[1].fp);
	_sort_initialise_temp_file(f_sort, 2);
	_sort_initialise_temp_file(f_sort, 3);
	source = 0;
	while (f_sort->file[source].cnt_sun > 1) {
		destination = source ^ 2;
		f_sort->file[destination].cnt_sun = 0;
		f_sort->file[destination + 1].cnt_sun = 0;
		while (f_sort->file[source].cnt_sun > 0) {
			if (unlikely(0 != _sort_read_next_sun(f_sort, source))) {
				return(-1);
			}
			if (f_sort->file[source + 1].cnt_sun > 0) {
				if (unlikely(0 != _sort_read_next_sun(f_sort, source + 1))) {
					return(-1);
				}
			} else {
				f_sort->queue[source + 1].first_sun->tf_eob = 1;
			}
			while (!f_sort->queue[source].first_sun->tf_eob
			       || !f_sort->queue[source + 1].first_sun->tf_eob) {
				if (f_sort->queue[source].first_sun->tf_eob) {
					move = 1;
				} else if (f_sort->queue[source + 1].first_sun->tf_eob) {
					move = 0;
				} else {
					cmp = _sort_compare(f_sort->queue[source].first_sun
					                  , f_sort->queue[source + 1].first_sun
					                  , f_sort->cob_file);
					move = (cmp < 0) ? 0 : 1;
				}
				if (unlikely(0 != _sort_write_sun(
					  f_sort
					, f_sort->file[destination].fp
				    , f_sort->queue[source + move].first_sun))) {
					return(-1);
				}
				if (unlikely(0 != _sort_read_next_sun(f_sort, source + move))) {
					return(-1);
				}
			}
			f_sort->file[destination].cnt_sun++;
			if (unlikely(0 != _sort_write_eob(f_sort, f_sort->file[destination].fp))) {
				return(-1);
			}
			f_sort->file[source].cnt_sun--;
			f_sort->file[source + 1].cnt_sun--;
			destination ^= 1;
		}
		source = destination & 2;
		rewind(f_sort->file[0].fp);
		rewind(f_sort->file[1].fp);
		rewind(f_sort->file[2].fp);
		rewind(f_sort->file[3].fp);
	}
	return(source);
}









/*
 *	Read a SUN from the work-file associated with SUN queue iq.
 *	The data is read into first_sun on the selected queue.
 *	Only on EOF is first_sun.tf_eob set true.
 *
 *	Returns 0 on success (including no SUN read). 
 *	Returns -1 if error encountered (exc set)
 */ 

static int _sort_read_next_sun (
	  sort_file_t *f_sort
	, const int iq)
{
	sort_unit_t *sun = f_sort->queue[iq].first_sun;
	if (1 != fread(&(sun->disk_sun), CB_SUN_ON_DISK, 1, f_sort->file[iq].fp)) {
		if (feof(f_sort->file[iq].fp)) {
			sun->tf_eob = 1;
			return(0);
		} else {
			SET_EXC_OS(COB_IOEXC_ERROR, errno);
			return(-1);
		}
	}
	sun->tf_eob = (sun->disk_sun.serial == -1) ? 1 : 0;
	if (trace_level > 1)
		getc(f_sort->file[iq].fp);     // skip record separator - diagnostic aid
	return(0);
}






/*
 *	Write a SUN to workfile.
 *	Returns 0 on success.
 *	Returns -1 if error encountered (exc set)
 */
static int _sort_write_sun(
	  sort_file_t *f_sort
	, FILE *fp
	, sort_unit_t *sun)
{
	if (1 != fwrite(&(sun->disk_sun), CB_SUN_ON_DISK, 1, fp)) {
		SET_EXC_OS(COB_IOEXC_ERROR, errno);
		return(-1);
	}
	if (trace_level > 1)
		putc('\n', fp);            // record separator - diagnostic aid
	return(0);
}








/*
 *	Write a trailer SUN to workfile.
 *	SUN with serial = -1 is used to mark end-of-block.
 *	Returns 0 on success.
 *	Returns -1 if error encountered (exc set)
 */
static int _sort_write_eob(
	  sort_file_t *f_sort
	, FILE *fp)
{
	sort_unit_t sun_eob;

	memset(&sun_eob, '\0', sizeof(sun_eob));
	sun_eob.disk_sun.serial =-1;
	return(_sort_write_sun(f_sort, fp, &sun_eob));
}






/*
 *	Write the contents of the selected queue to its associated work-file.
 *	Each SUN in the queue is returned to the free SUN chain.
 *	Returns 0 on success.
 *	Returns -1 if error encountered (exc set)
 */
static int _sort_flush_queue(
	  sort_file_t *f_sort
	, const int iq)
{
	sort_unit_t *sun;
	FILE *fp = f_sort->file[f_sort->i_wfile].fp;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _sort_flush_queue()\n", me);
#endif

	while (1) {
		sun = f_sort->queue[iq].first_sun;
		if (sun == NULL) {
			break;
		}
		if (0 != _sort_write_sun(f_sort, fp, sun)) {
			return(-1);
		}
		f_sort->queue[iq].first_sun = sun->next_sun;
		sun->next_sun = f_sort->q_free_sun;
		f_sort->q_free_sun = sun;
	}
	f_sort->queue[iq].cnt_sun = 0;
	f_sort->file[f_sort->i_wfile].cnt_sun++;
	if (0 != _sort_write_eob(f_sort, fp)) {
		return(-1);
	}
	return(0);
}






/*
 *	Copy the record data of the file "from" to the record area
 *	of file "to".
 *	Short records are padded with spaces. Long records are truncated.
 */

static void _sort_copy_record (
	  cob_file_t *to
	, cob_file_t *from)
{
	int cb;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _sort_copy_record()\n", me);
#endif

	cb = (to->record->size <= from->record->size) ?
	     to->record->size : from->record->size;
	memcpy(to->record->data, from->record->data, cb);
	if (cb < to->record->size)
		memset(to->record->data + cb, ' ', to->record->size - cb);
}





/*
 *	Invoked when the first request is made to return a record
 *	from the sort.
 *	The active queues are sorted.
 *	If this is an in-memory sort:
 *		f_sort->iq_final is set and this method exits.
 *	Otherwise:
 *		The queues are flushed to the workfiles. 
 *		The workfiles are merge/sorted
 *	Returns 0 on success.
 *	Returns -1 if error encountered (exc set)
 */

static int _sort_process(sort_file_t *f_sort)
{
	int	iq;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: _sort_process()\n", me);
#endif

	f_sort->tf_retrieving = 1;
	iq = _sort_queues(f_sort);
	if (f_sort->tf_wfiles_used) {
		if (0 != _sort_flush_queue(f_sort, iq)) {
			return(-1);
		}
		iq = _sort_workfiles(f_sort);
		if ((iq == -1) 
			|| (0 != _sort_read_next_sun(f_sort, iq))
			|| (0 != _sort_read_next_sun(f_sort, iq + 1))) {
			return(-1);
		}
	}
	f_sort->iq_final = iq;
	return 0;
}






/*
 *	Release data at pb_record to sort_file.
 *	If the combined length of queues 0 and 1 has
 *	reached the limit on max number of SUNs in memory:
 *
 *	A new SUN is obtained and loaded with the data
 *	from pb_record. SUN is added to queue 0 or 1
 *	depending on which queue is shorter.
 *
 *	Returns 0 on success.
 *	Returns -1 if error encountered (exc set)
 */


static int _sort_submit_record(
	  sort_file_t *f_sort
	, const unsigned char *pb_record)
{
	sort_unit_t *sun;
	sort_chain_t *queue;
	int n;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 2)
		fprintf(stderr, "%s: _sort_submit_record()\n", me);
#endif

	if (f_sort == NULL) {
		SET_EXC(COB_IOEXC_CLOSED);
		return(-1);
	}
	if (f_sort->tf_retrieving) {
		SET_EXC(COB_IOEXC_SORT_OP);
		return(-1);
	}
	if (f_sort->queue[0].cnt_sun + f_sort->queue[1].cnt_sun >= f_sort->cnt_sun_max) {
		// too many items to sort in allotted memory - use work-files
		if (!f_sort->tf_wfiles_used) {
			_sort_initialise_temp_file(f_sort, 0);
			_sort_initialise_temp_file(f_sort, 1);
			f_sort->tf_wfiles_used = 1;
			f_sort->i_wfile = 0;
		}
		n = _sort_queues(f_sort);
		if (0 != _sort_flush_queue(f_sort, n)) {
			return(-1);
		}
		f_sort->i_wfile ^= 1;
	}
	sun = _sort_get_new_sun(f_sort);
	sun->tf_eob = 1;

	sun->disk_sun.serial = f_sort->i_serial;
	f_sort->i_serial++;
	memcpy(sun->disk_sun.record_data, pb_record, f_sort->cb_record);
	if (f_sort->queue[0].cnt_sun <= f_sort->queue[1].cnt_sun) {
		queue = &f_sort->queue[0];
	} else {
		queue = &f_sort->queue[1];
	}
	sun->next_sun = queue->first_sun;
	queue->first_sun = sun;
	queue->cnt_sun++;
	return 0;
}





/*
 *	Get the next (sorted) record from the sort file and
 *	write it to pb_record.
 *	If sorting is in memory:
 *		The top SUN is removed from the final-queue.
 *		The record-data in the SUN is copied to pb_record.
 *		The SUN is returned to the free chain.
 *	If sorting with workfiles:
 *		The top SUNs on the 2 final queues are compared
 *		and the lowest one chosen.	
 *		The record-data in the SUN is copied to pb_record.
 *		The chosen SUN is replaced at the top of the queue
 *		with the next on read from workfile.
 *
 *	Returns 0 on success.
 *	Returns -1 if error encountered (exc set)
 */

static int _sort_retrieve(
	  sort_file_t *f_sort
	, unsigned char *pb_record)
{

	int iq;
	sort_unit_t *top_sun1, *top_sun2;

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 4)
		fprintf(stderr, "%s: _sort_retrieve()\n", me);
#endif


	if (f_sort == NULL) {
		SET_EXC(COB_IOEXC_CLOSED);
		return(-1);
	}
	if (!f_sort->tf_retrieving) {
		// 1st time called - do the sort
		if (0 != _sort_process(f_sort)) {
			return(-1);
		}
	}
	if (f_sort->tf_wfiles_used) {
		top_sun1 = f_sort->queue[f_sort->iq_final].first_sun;
		top_sun2 = f_sort->queue[f_sort->iq_final + 1].first_sun;
		if (top_sun1->tf_eob) {
			if (top_sun2->tf_eob) {
				SET_EXC(COB_IOEXC_R_XEOF);
				return(-1);
			}
			iq = f_sort->iq_final + 1;
		} else if (top_sun2->tf_eob) {
			iq = f_sort->iq_final;
		} else {
			if (_sort_compare(top_sun1, top_sun2, f_sort->cob_file) < 0) {
				iq = f_sort->iq_final;
			} else {
				iq = f_sort->iq_final + 1;
			}
		}
		memcpy(pb_record, f_sort->queue[iq].first_sun->disk_sun.record_data, f_sort->cb_record);
		if (_sort_read_next_sun(f_sort, iq)) {
			return(-1);
		}
	} else {
		top_sun1 = f_sort->queue[f_sort->iq_final].first_sun;
		if (top_sun1 == NULL) {
			SET_EXC(COB_IOEXC_R_XEOF);
			return(-1);
		}
		memcpy(pb_record, top_sun1->disk_sun.record_data, f_sort->cb_record);
		f_sort->queue[f_sort->iq_final].first_sun = top_sun1->next_sun;
		top_sun1->next_sun = f_sort->q_free_sun;
		f_sort->q_free_sun = top_sun1;
	}
	return 0;
}


