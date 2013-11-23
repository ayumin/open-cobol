#
# Makefile gnucobol/doc
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

info_TEXINFOS = gnucobol.texi
gnucobol_TEXINFOS = cbhelp.tex cbinfo.tex cbrese.tex \
	cbintr.tex cbsyst.tex cbmnem.tex cbconf.tex
EXTRA_DIST = gnucobol.pdf cobcinfo.sh cbhelp.tex cbinfo.tex cbrese.tex \
	cbintr.tex cbsyst.tex cbmnem.tex cbconf.tex
TEXINFO_TEX = ../texinfo.tex
AM_MAKEINFOHTMLFLAGS = --no-headers --no-split
CLEANFILES = *.aux  *.cp *.fn *.ky *.log *.pg *.toc *.tp *.vr *.vrs
TEXI2DVI = texi2dvi -I $(srcdir)
