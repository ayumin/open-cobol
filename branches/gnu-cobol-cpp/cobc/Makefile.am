#
# Makefile gnu-cobol-cpp/cobc
#
# Copyright (C) 2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2008-2012 Roger While
# Copyright (C) 2013 Sergey Kashyrin
#
# This file is part of GNU Cobol C++.
#
# The GNU Cobol C++ compiler is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# GNU Cobol C++ is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.

bin_PROGRAMS = cobc
cobc_SOURCES = cobc.cpp cobc.h config.cpp tree.cpp tree.h reserved.cpp error.cpp \
	parser.cpp parser.hpp scanner.cpp field.cpp typeck.cpp codegen.cpp ppparse.cpp \
	ppparse.hpp pplex.cpp config.def flag.def warning.def codeoptim.def \
	ppparse.def codeoptim.cpp naming.cpp utils.cpp vcache.h

cobc_CFLAGS = -I$(top_srcdir)
cobc_LDADD = $(COBC_LIBS) $(top_builddir)/libcob/libcob.la $(top_builddir)/lib/libsupport.a

BUILT_SOURCES = parser.cpp parser.hpp scanner.cpp ppparse.cpp ppparse.hpp pplex.cpp
EXTRA_DIST = ppparse.y pplex.l parser.y scanner.l
CLEANFILES = parser.output ppparse.output

.l.cpp:
	LC_CTYPE=C flex -s -o$@ $<

.y.cpp:
	bison -o $@ $<
