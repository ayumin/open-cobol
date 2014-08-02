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
 *	The header file for OpenCOBOL fileio :: sort module
 *
*/



#ifndef FILEIO_SORT_H
#define FILEIO_SORT_H




COB_EXPIMP int cob_fileio_sort_initialise(void);


COB_EXPIMP int cob_fileio_sort_terminate(void);


COB_EXPIMP void cob_file_sort_using(
	  cob_file_t *sort_file
	, cob_file_t *data_file);


COB_EXPIMP void cob_file_sort_giving(
	  cob_file_t *sort_file
	, const size_t varcnt
	, ...);


COB_EXPIMP void cob_file_sort_init(
	  cob_file_t *f
	, const int nkeys
	, const unsigned char *collating_sequence
	, void *sort_return
	, cob_field *fnstatus);


COB_EXPIMP void cob_file_sort_init_key(
	  cob_file_t *f
	, cob_field *field
	, const int flag
	, size_t offset);


COB_EXPIMP void cob_file_sort_close(cob_file_t *f);


COB_EXPIMP void cob_file_release(cob_file_t *f);


COB_EXPIMP void cob_file_return(cob_file_t *f);



#endif     // FILEIO_SORT_H


