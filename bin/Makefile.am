#
# Makefile gnucobol/bin
#
# Copyright (C) 2004-2012 Roger While
# Copyright (C) 2012 Simon Sobisch
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

bin_SCRIPTS=cob-config
bin_PROGRAMS = cobcrun
cobcrun_SOURCES = cobcrun.c

AM_LDFLAGS = $(COB_EXPORT_DYN)
cobcrun_CFLAGS = $(AM_CFLAGS) -I$(top_srcdir)
cobcrun_LDADD = $(top_builddir)/lib/libsupport.a $(top_builddir)/libcob/libcob.la
