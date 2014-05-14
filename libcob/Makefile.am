#
# Makefile gnucobol/libcob
#
# Copyright (C) 2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2008-2012 Roger While
#
# This file is part of GNU Cobol.
#
# The GNU Cobol compiler is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# GNU Cobol is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Cobol.  If not, see <http://www.gnu.org/licenses/>.

lib_LTLIBRARIES = libcob.la
libcob_la_SOURCES = common.c move.c numeric.c strings.c \
	fileio.c call.c intrinsic.c termio.c screenio.c cobgetopt.c

libcob_la_CFLAGS = $(AM_CFLAGS) -I$(top_srcdir)
libcob_la_LIBADD = $(LIBCOB_LIBS)
libcob_la_LDFLAGS = $(COB_FIX_LIBTOOL) -version-info 4:0:0 -no-undefined
AM_LDFLAGS = $(COB_FIX_LIB)

EXTRA_DIST = coblocal.h system.def
pkgincludedir = $(includedir)/libcob
pkginclude_HEADERS = common.h cobgetopt.h exception.def

install-data-hook:
	rm -f $(includedir)/libcob/byteswap.h
	rm -f $(includedir)/libcob/call.h
	rm -f $(includedir)/libcob/fileio.h
	rm -f $(includedir)/libcob/termio.h
	rm -f $(includedir)/libcob/screenio.h
	rm -f $(includedir)/libcob/move.h
	rm -f $(includedir)/libcob/numeric.h
	rm -f $(includedir)/libcob/strings.h
	rm -f $(includedir)/libcob/intrinsic.h
	rm -f $(includedir)/libcob/codegen.h
	rm -f $(includedir)/libcob/system.def
