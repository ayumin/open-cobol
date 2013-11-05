/*
   Copyright (C) 2013 Sergey Kashyrin

   This file is part of GNU Cobol C++.

   The GNU Cobol C++ compiler is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol C++ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "config.h"

#ifndef	_GNU_SOURCE
#define _GNU_SOURCE	1
#endif

#include <stdio.h>

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

COB_EXPIMP int CBL_ERROR_PROC(unsigned char *, unsigned char *);

int CBL_ERROR_PROC(unsigned char * x, unsigned char * pptr)
{
	return cob_sys_error_proc(x, pptr);
}
