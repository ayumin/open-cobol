#
# Makefile gnu-cobol-cpp/bin
#
# Copyright (C) 2004-2012 Roger While
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

bin_SCRIPTS=cob-config
bin_PROGRAMS = cobcrun
cobcrun_SOURCES = cobcrun.cpp

AM_LDFLAGS = $(COB_EXPORT_DYN)
cobcrun_CPPFLAGS = $(AM_CPPFLAGS) -I$(top_srcdir)
cobcrun_LDADD = $(top_builddir)/libcob/libcob.la
