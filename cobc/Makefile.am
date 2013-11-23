#
# Makefile gnucobol/cobc
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

bin_PROGRAMS = cobc
cobc_SOURCES = cobc.c cobc.h config.c tree.c tree.h reserved.c error.c \
	parser.c parser.h scanner.c field.c typeck.c codegen.c ppparse.c \
	ppparse.h pplex.c config.def flag.def warning.def codeoptim.def \
	ppparse.def cobgetopt.c cobgetopt.h codeoptim.c

cobc_CFLAGS = -I$(top_srcdir)
# cobc_LDADD = $(COBC_LIBS) $(top_builddir)/lib/libsupport.a
cobc_LDADD = $(COBC_LIBS)

BUILT_SOURCES = parser.c parser.h scanner.c ppparse.c ppparse.h pplex.c
EXTRA_DIST = ppparse.y pplex.l parser.y scanner.l
CLEANFILES = parser.output ppparse.output

.l.c:
	LC_CTYPE=C flex -s -o$@ $<

.y.c:
	bison -g -o $@ $<
