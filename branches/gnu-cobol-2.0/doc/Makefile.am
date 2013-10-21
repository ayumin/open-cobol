#
# Makefile opencobol/doc
#
# Copyright (C) 2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2008-2012 Roger While
#
# This file is part of OpenCOBOL.
#
# The OpenCOBOL compiler is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# OpenCOBOL is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with OpenCOBOL.  If not, see <http://www.gnu.org/licenses/>.

info_TEXINFOS = opencobol.texi
opencobol_TEXINFOS = cbhelp.tex cbinfo.tex cbrese.tex \
	cbintr.tex cbsyst.tex cbmnem.tex cbconf.tex
EXTRA_DIST = opencobol.pdf cobcinfo.sh cbhelp.tex cbinfo.tex cbrese.tex \
	cbintr.tex cbsyst.tex cbmnem.tex cbconf.tex
TEXINFO_TEX = ../texinfo.tex
AM_MAKEINFOHTMLFLAGS = --no-headers --no-split
CLEANFILES = *.aux  *.cp *.fn *.ky *.log *.pg *.toc *.tp *.vr *.vrs
TEXI2DVI = texi2dvi -I $(srcdir)
