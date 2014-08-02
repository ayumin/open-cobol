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
 *	The header file for fileio_stats
 *
 */


#ifndef FILEIO_STATS_H
#define FILEIO_STATS_H


#include "fileio.h"
#include "fileio-misc.h"


extern
int cob_fileio_stats_initialise(void);

extern
int cob_fileio_stats_initialise_file(
	  cob_file_t *f);

extern
int cob_fileio_stats_open_file(
	  cob_file_t *f
	, exception_t *exc
	, char *(*fn_file_xml) (cob_file_t *, const char *));

extern
int cob_fileio_stats_close_file(
	  cob_file_t *f
	, int opt
	, exception_t *exc);

extern
int cob_fileio_stats_terminate(void);

#endif		// FILEIO_STATS_H

