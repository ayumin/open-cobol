#!/bin/sh
# cobcinfo.sh gnucobol/doc
#
# Copyright (C) 2010,2012 Roger While
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

docdir=`dirname $0`
confdir=`dirname $0`/../config

echo "@verbatim"         >$docdir/cbhelp.tex
cobc --help             >>$docdir/cbhelp.tex
echo "@end verbatim"    >>$docdir/cbhelp.tex
echo ""                 >>$docdir/cbhelp.tex

echo "@verbatim"         >$docdir/cbinfo.tex
cobc --info             >>$docdir/cbinfo.tex
echo "@end verbatim"    >>$docdir/cbinfo.tex
echo ""                 >>$docdir/cbinfo.tex

echo "@verbatim"         >$docdir/cbrese.tex
cobc --list-reserved    >>$docdir/cbrese.tex
echo "@end verbatim"    >>$docdir/cbrese.tex
echo ""                 >>$docdir/cbrese.tex

echo "@verbatim"         >$docdir/cbintr.tex
cobc --list-intrinsics  >>$docdir/cbintr.tex
echo "@end verbatim"    >>$docdir/cbintr.tex
echo ""                 >>$docdir/cbintr.tex

echo "@verbatim"         >$docdir/cbsyst.tex
cobc --list-system      >>$docdir/cbsyst.tex
echo "@end verbatim"    >>$docdir/cbsyst.tex
echo ""                 >>$docdir/cbsyst.tex

echo "@verbatim"         >$docdir/cbmnem.tex
cobc --list-mnemonics   >>$docdir/cbmnem.tex
echo "@end verbatim"    >>$docdir/cbmnem.tex
echo ""                 >>$docdir/cbmnem.tex

echo "@verbatim"             >$docdir/cbconf.tex
cat $confdir/default.conf   >>$docdir/cbconf.tex
echo "@end verbatim"        >>$docdir/cbconf.tex
echo ""                     >>$docdir/cbconf.tex

