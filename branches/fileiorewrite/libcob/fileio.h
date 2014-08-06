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
 *	The header file for fileio external API.
 *	The entities declared in this header file are referenced
 *	by the "c" s-code emitted by the OpenCOBOL compiler.
 *	Declarations "private" to the fileio module but shared in common
 *	may be found in fileio-misc.h
 */




#ifndef COB_FILEIO_H
#define COB_FILEIO_H

#include <sys/stat.h>

#if HAVE_SYSLOG_H
#include <syslog.h>
#endif

#define	COB_FILE_VERSION	2

#define UNSI unsigned int

#define COB_EQ			(UNSI)1 	
#define COB_LT			(UNSI)2
#define COB_LE			(UNSI)3
#define COB_GT			(UNSI)4
#define COB_GE			(UNSI)5
#define COB_NE			(UNSI)6
#define COB_FI			(UNSI)7
#define COB_LA			(UNSI)8

#define COB_ASCENDING  (UNSI)0
#define COB_DESCENDING (UNSI)1

#define COB_FILE_MODE 0644




#define COB_ORG_SEQUENTIAL       (UNSI)0
#define COB_ORG_LINE_SEQUENTIAL  (UNSI)1
#define COB_ORG_RELATIVE         (UNSI)2
#define COB_ORG_INDEXED          (UNSI)3
#define COB_ORG_SORT             (UNSI)4
#define COB_ORG_MAX              (UNSI)5



#define COB_ACCESS_SEQUENTIAL    (UNSI)1
#define COB_ACCESS_DYNAMIC       (UNSI)2
#define COB_ACCESS_RANDOM        (UNSI)3


#define COB_SELECT_FILE_STATUS  (1U << 0)
#define COB_SELECT_EXTERNAL     (1U << 1)
#define COB_SELECT_LINAGE       (1U << 2)
#define COB_SELECT_SPLITKEY     (1U << 3)
#define COB_SELECT_STDIN        (1U << 4)
#define COB_SELECT_STDOUT       (1U << 5)
#define COB_SELECT_TEMPORARY    (1U << 6)


#define COB_SHARE_ALL       (UNSI)0
#define COB_SHARE_READ_ONLY (UNSI)1
#define COB_SHARE_EXCLUSIVE (UNSI)2


#define COB_LOCK_MANUAL    (UNSI)0
#define COB_LOCK_AUTOMATIC (UNSI)1
#define COB_LOCK_EXCLUSIVE (UNSI)2




#define COB_OPEN_CLOSED (UNSI)0
#define COB_OPEN_INPUT  (UNSI)1
#define COB_OPEN_OUTPUT (UNSI)2
#define COB_OPEN_I_O    (UNSI)3
#define COB_OPEN_EXTEND (UNSI)4




#define COB_CLOSE_NORMAL       (UNSI)0
#define COB_CLOSE_LOCK         (UNSI)1
#define COB_CLOSE_NO_REWIND    (UNSI)2
#define COB_CLOSE_UNIT         (UNSI)3
#define COB_CLOSE_UNIT_REMOVAL (UNSI)4



#define COB_WRITE_MASK     0x0000ffff
#define COB_WRITE_LINES    0x00010000
#define COB_WRITE_PAGE     0x00020000
#define COB_WRITE_CHANNEL  0x00040000
#define COB_WRITE_AFTER    0x00100000
#define COB_WRITE_BEFORE   0x00200000
#define COB_WRITE_EOP      0x00400000
#define COB_WRITE_LOCK     0x00800000




#define COB_READ_CURRENT     0
#define COB_READ_NEXT        (1U << 0)
#define COB_READ_PREVIOUS    (1U << 1)
#define COB_READ_FIRST       (1U << 2)
#define COB_READ_LAST        (1U << 3)
#define COB_READ_LOCK        (1U << 4)
#define COB_READ_NO_LOCK     (1U << 5)
#define COB_READ_KEPT_LOCK   (1U << 6)
#define COB_READ_WAIT_LOCK   (1U << 7)
#define COB_READ_IGNORE_LOCK (1U << 8)



#define COB_SYNC_NONE     (UNSI)0
#define COB_SYNC_LOGICAL  (UNSI)1
#define COB_SYNC_PHYSICAL (UNSI)2





/* Need some value that does not conflict with errno for OPEN/LINAGE */
#define	COB_LINAGE_INVALID	16384
/* Need value that does not conflict with errno 30 (EROFS) for OPEN */
#define	COB_NOT_CONFIGURED	32768

#define ESHARE 1001                // find suitable SHARE_VIOLATION in errno




#define COB_MAX_KEYCOMP 8         // max number of parts in a compound key
                                  // synch with disam.h :: NPARTS 




typedef struct cob_file_key {
	cob_field *field;                               // key field 
	int        tf_duplicates;                       // WITH DUPLICATES (for RELATIVE/INDEXED) 
	int        tf_ascending;                        // ASCENDING/DESCENDING (for SORT)
	int        tf_suppress;                         // supress keys where all chars = char_suppress
	int        char_suppress;                       // key supression character 
	size_t     offset;                              // Offset of field 
	int        count_components;                    // 0..1::simple-key  2..n::split-key  
	cob_field  *component[COB_MAX_KEYCOMP];         // key-components iff split-key  
} cob_file_key_t;


/*
 *  The first 4 cob_fields are NULL or constants, corresponding to :
 *     FD file-name LINAGE <linage> LINES FOOTING <foot> TOP <top> BOTTOM <bot>
 *  cob_control is externalized current line-count.
 *
 *  Those values are converted to int equivalents when the file is opened.
 */ 
typedef struct cob_linage {
	cob_field *cob_linage;
	cob_field *cob_foot;
	cob_field *cob_top;
	cob_field *cob_bot;
	cob_field *cob_control;
	int        i_linage;
	int        i_foot;
	int        i_top;
	int        i_bot;
	int        tf_needs_top;
	int        tf_check_eop;
} cob_linage_t;



// Value that identifies a file system-wide uniquely.
// For most files this will be the inode number.
typedef struct cob_fileuid {
	union {
		ino_t      inode;
		long       tableid;
		int        fildes;
	};
} cob_fileuid_t;



typedef struct cob_io_stats {
	int               cnt_read;
	int               cnt_write;
	int               cnt_rewrite;
	int               cnt_delete;
	int               cnt_start;
} cob_io_stats_t;





typedef struct cob_file {
	// "public" fields referenced by cobc (i.e. C object files generated by cobc)
	const char           *select_name;            // name in SELECT 
	char                 *assign_name;            // name in assign cob_field AT TIME OF LATEST OPEN
	char                 *fid;                    // pathed root file-name: (base) physical file-name
	unsigned char        *file_status;            // FILE STATUS 
	cob_field            *assign;                 // ASSIGN TO 
	cob_field            *record;                 // record area
	cob_field            *record_size;            // record size current record (iff dec in COBOL)
	size_t                record_min;             // record min size 
	size_t                record_max;             // record max size 
	size_t                nkeys;                  // the number of keys 
	cob_file_key_t       *keys;                   // RELATIVE/RECORD/SORT keys 
	const unsigned char  *sort_collating;         // SORT collating 
	char                  organization;           // ORGANIZATION
	char                  access_mode;            // ACCESS MODE
	char                  last_open_mode;         // MODE used on most recent OPEN
	char                  file_version;           // file I/O version
	char                  flag_optional;          // OPTIONAL
	char                  flag_select_features;   // SELECT features
	char                  special;                // special file :: 1 stdin  2 stdout  3 stderr 
	cob_linage_t         *linage;                 // LINAGE info    

	// "private" fields used in fileio*.c 
	void                 *file;                   // pointer to DB | ISAM | FILE control-struct  
	char                  lock_mode;              // LOCK MODE established on OPEN
	char                  share_mode;             // SHARE MODE established on OPEN
	char                  open_mode;              // OPEN MODE 
	cob_fileuid_t         fileuid;                // system-wide unique identifier for this file
	long                  id_share;               // key to sharing locks
	unsigned int tf_lock_many :1;                 // LOCK MODE MULTIPLE established on OPEN
	unsigned int tf_optional_was_created : 1;     // at last OPEN nonexistent optional file was created
	unsigned int tf_optional_is_missing : 1;      // at last OPEN optional file was not found
	unsigned int tf_is_locked : 1;                // locked on prior close 
	unsigned int tf_beyond_bof : 1;               // reached beginning of file 
	unsigned int tf_beyond_eof : 1;               // reached the end of file 
	unsigned int tf_is_first_read : 1;            // first READ after OPEN/START 
	unsigned int tf_read_is_done : 1;             // last READ successful 
	unsigned int tf_needs_nl : 1;                 // LS file needs NL at close 
	unsigned int tf_started : 1;                  // START was previous call
	unsigned int tf_initialised : 1;              // this struct has been initialised
	cob_io_stats_t        io_stats[2];            // [0] count attempts     [1] count successes
} cob_file_t;





  
extern cob_file_t *cob_error_file;






// leave to coblocal.h :: cob_init_fileio() cob_exit_fileio()

COB_EXPIMP void cob_initialise_file(
	  cob_file_t *f);

COB_EXPIMP void cob_assign_file(
	  cob_file_t *f);

COB_EXPIMP void cob_open(
	  cob_file_t *f
	, const int open_mode
	, const int share_mode
	, const int lock_mode
	, const int lock_many
	, cob_field *fnstatus);

COB_EXPIMP void cob_close(
          cob_file_t *f
        , cob_field *fnstatus 
        , const int opt
        , const int tf_cancel);

COB_EXPIMP void cob_start(
	  cob_file_t *f
	, const int cond
	, cob_field *key
        , cob_field *cb_key
	, cob_field *fnstatus);

COB_EXPIMP void cob_read(
	  cob_file_t *f
	, cob_field *key
	, cob_field *fnstatus
	, int opt);

COB_EXPIMP void cob_read_next(
	  cob_file_t *f
	, cob_field *fnstatus
	, int opt);

COB_EXPIMP void cob_write(
	  cob_file_t *f
	, cob_field *rec
	, const int opt
	, cob_field *fnstatus
        , const unsigned int tf_check_eop);

COB_EXPIMP void cob_rewrite(
	  cob_file_t *f
	, cob_field *rec
	, const int opt
	, cob_field *fnstatus);

COB_EXPIMP void cob_delete(
	  cob_file_t *f
	, cob_field *fnstatus);

COB_EXPIMP void cob_erase(
	  cob_file_t *f
	, cob_field *fnstatus);

COB_EXPIMP void cob_unlock_file(
	  cob_file_t *f
	, cob_field *fnstatus);

COB_EXPIMP void cob_commit(void);

COB_EXPIMP void cob_rollback(void);

COB_EXPIMP void cob_display_file_exception(void);



// include other public function headers required by cobc


#include <libcob/fileio-call.h>
#include <libcob/fileio-sort.h>


#endif    // COB_FILEIO_H

