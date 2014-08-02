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





#include "libcob.h"

/*
 *	NOTES ON WRITING EXTERNAL FILE-HANDLER(s)
 *	-----------------------------------------
 *
 *	These notes explain how a developer can provide her own
 *	file-handler to supplement or substitute for the standard
 *	I-O provided by OpenCOBOL.
 *
 *	When OpenCOBOL is configured: ./configure --with-fileio-exchange
 *	the declaration: #define WITH_FILEIO_EXCHANGE 1
 *	is inserted in config.h
 *	With this config fileio.c will call cob_fileio_open_exchange() during
 *	initialisation and cob_fileio_close_exchange() upon termination. 
 *
 *	The function jump tables are passed as arguments to cob_fileio_open_exchange().
 *	There are 3 possible ways to manipulate the I-O sub-system:
 *
 *	1.	Function substitution. Simply replace the relevant entry in a
 *		function jump table with a reference to your own function. fileio.c
 *		will then call your function instead of its own.
 *
 *	2.	Function acceptance. Leave the entry in the function jump table
 *		unchanged. fileio.c will then call the standard function as normal.
 *
 *	3.	Function filtering. Store a reference to the function passed in the
 *		function jump table. Substitute your own function (as 1. above).
 *		When your function has completed, call the original	function to 
 *		perform standard I-O. This technique could be used for 
 *		filtering data, logging, tracing, etc.
 *
 *	In all circumstances, fileio.c will perform some preparatory processes
 *	before calling your code. For example, files will be checked to be open
 *	in the correct mode before I-O operations are performed on them.
 *
 *	The code in this unit illustrates some of the techniques you may use.
 *
 *	The alternative strategy to providing your own I-O handler is
 *	to replace a fileio code unit entirely.
 *	For example, suppose you want to implement COBOL INDEXED file 
 *	ORGANIZATION with MySQL support (instead of BDB).
 *	Then you could replace fileio-isam-bdb.c with your own code and
 *	make + make install the COBOL libraries - libcob - based on this.
 */



#include "fileio-misc.h"

static char *me = "EXTERNAL I-O Handler";




//	Store the vanilla functions (for the filter model)
static int	(*_relative_open) ();
static int	(*_sequential_open) ();
static int	(*_lineseq_open) ();
static int	(*_indexed_open) ();



//	Examples of custom I-O handling

int _my_relative_open(
	  cob_file_t *f
	, const int mode)
{
	int res;
	res = _relative_open(f, mode);
	printf("%s : %s OPEN RELATIVE file [res=%d]: %s\n"
	     , cob_fileio_get_now(), me, res, cob_fileio_get_full_name(f));
	return(res);
}


int _my_sequential_open(
	  cob_file_t *f
	, const int mode)
{
	int res;
	res = _sequential_open(f, mode);
	printf("%s : %s OPEN SEQUENTIAL file [res=%d]: %s\n"
	     , cob_fileio_get_now(), me, res, cob_fileio_get_full_name(f));
	return(res);
}


int _my_lineseq_open(
	  cob_file_t *f
	, const int mode)
{
	int res;
	res = _lineseq_open(f, mode);
	printf("%s : %s OPEN LINE-SEQUENTIAL file [res=%d]: %s\n"
	     , cob_fileio_get_now(), me, res, cob_fileio_get_full_name(f));
	return(res);
}


int _my_indexed_open(
	  cob_file_t *f
	, const int mode)
{
	int res;
	res = _indexed_open(f, mode);
	printf("%s : %s OPEN INDEXED file [res=%d]: %s\n"
	     , cob_fileio_get_now(), me, res, cob_fileio_get_full_name(f));
	return(res);
}


int _my_relative_delete(
	  cob_file_t *f)
{
	cob_fileio_report_io_error(
		  f
		, COB_IOEXC_NYI
		, COB_IO_CONTEXT_FILEIO_EXTERNAL
		, COB_IO_REALM_COBOL
		, "DEMO EXTERNAL I-O HANDLER: RELATIVE DELETE NYI");
	return(-1);
}



/*
 *	struct cob_fileio_funcs is defined in fileio-misc.h.
 *	For clarity, it is shown here:
 *	
 *	struct cob_fileio_funcs {
 *		int	(*open)      (cob_file_t *f, const int mode);
 *		int	(*close)     (cob_file_t *f, const int opt);
 *		int	(*start)     (cob_file_t *f, const int cond, cob_field *key);
 *		int	(*read)      (cob_file_t *f, cob_field *key, int opt);
 *		int	(*read_next) (cob_file_t *f, int opt);
 *		int	(*write)     (cob_file_t *f, const int cb_rsz, const int opt);
 *		int	(*rewrite)   (cob_file_t *f, const int cb_rsz, const int opt);
 *		int	(*delete)    (cob_file_t *f);
 *		int	(*sync)      (cob_file_t *f, const int opt);
 *		int	(*unlock)    (cob_file_t *f);
 *		int	(*erase)     (cob_file_t *f);
 *	};
 *
 *	Every function is expected to return 0 on success.
 *	On failure, return a non-zero result (the value is not significant).
 *	To report errors/exceptions use the exception handlers in fileio-misc.c:
 *		void fileio_report_io_error()
 *		void cob_fileio_throw_rts()
 *		void cob_fileio_throw_exc()
 *		void cob_fileio_throw_ext()
 *	
 */
int cob_fileio_open_exchange(
	  const struct cob_fileio_funcs *relative_funcs
	, const struct cob_fileio_funcs *sequential_funcs
	, const struct cob_fileio_funcs *lineseq_funcs
	, const struct cob_fileio_funcs *indexed_funcs)
{
	// Allocate & initialise resources ...

	// Switch the RELATIVE functions:
	_relative_open = relative_funcs->open;
	relative_funcs->open = _my_relative_open;
	relative_funcs->delete = _my_relative_delete;

	// Switch the SEQUENTIAL functions:
	_sequential_open = sequential_funcs->open;
	sequential_funcs->open = _my_sequential_open;

	// Switch the LINE-SEQUENTIAL functions:
	_lineseq_open = lineseq_funcs->open;
	lineseq_funcs->open = _my_lineseq_open;

	// Switch the INDEXED functions:
	_indexed_open = indexed_funcs->open;
	indexed_funcs->open = _my_indexed_open;

	return(0);
}



int cob_fileio_close_exchange(void)
{
	// Finalise and release resources ...
	return(0);
}




