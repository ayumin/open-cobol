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
 *	The header file for OpenCOBOL fileio :: relative organization
 *
*/


#ifndef FILEIO_RELATIVE_H
#define FILEIO_RELATIVE_H

#include "fileio.h"


extern int cob_fileio_relative_initialise(void);

extern int cob_fileio_relative_terminate(void);

extern int cob_fileio_relative_open(
	  cob_file_t *f  
	, const int mode); 

extern int cob_fileio_relative_close(
	  cob_file_t *f
	, const int opt);

extern int cob_fileio_relative_start(
	  cob_file_t *f
	, const int cond
	, cob_field *cobf_i_rec);

extern int cob_fileio_relative_read(
	  cob_file_t *f
 	, cob_field *cobf_i_rec
	, const int opt);

extern int cob_fileio_relative_read_next(
	  cob_file_t *f
	, const int opt);

extern int cob_fileio_relative_write(
	  cob_file_t *f
	, const int cb_rec
	, const int opt);

extern int cob_fileio_relative_rewrite(
	  cob_file_t *f
	, const int cb_rec
	, const int opt);

extern int cob_fileio_relative_delete(cob_file_t *f);

extern int cob_fileio_relative_sync(
	  cob_file_t *f
	, const int mode);

extern int cob_fileio_relative_unlock(cob_file_t *f);

extern int cob_fileio_relative_erase(cob_file_t *f);



#endif      // FILEIO_RELATIVE_H


