#
# Makefile gnu-cobol-cpp/extras
#
# Copyright (C) 2012 Roger While
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

extrasdir = @COB_LIBRARY_PATH@
extras_DATA = CBL_OC_DUMP.$(COB_MODULE_EXT)

EXTRA_DIST = CBL_OC_DUMP.cob
CLEANFILES = CBL_OC_DUMP.$(COB_MODULE_EXT)

CBL_OC_DUMP.$(COB_MODULE_EXT): CBL_OC_DUMP.cob $(top_builddir)/cobc/cobc
	. $(top_builddir)/tests/atconfig; . $(top_builddir)/tests/atlocal; \
		cobc -m -Wall -std=mf -O $(top_srcdir)/extras/CBL_OC_DUMP.cob

