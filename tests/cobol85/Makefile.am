#
# Makefile gnu-cobol-cpp/tests/cobol85
#
# Copyright (C) 2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2008-2012 Roger While
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

#
#MODULES = CM DB IC IF IX NC OB RL RW SG SM SQ ST

if COB_MAKE_IX
MODULES = NC SM IC SQ RL IX ST SG OB IF DB
else
MODULES = NC SM IC SQ RL ST SG OB IF DBNOIX
endif

#

EXTRA_DIST = EXEC85.conf.in expand.pl report.pl summary.pl summary.txt \
	summarynoix.txt NC.txt SM.txt IC.txt SQ.txt RL.txt IX.txt \
	ST.txt SG.txt OB.txt IF.txt DB.txt DBNOIX.txt RW.txt

#CLEANFILES = EXEC85 summary.log
#

COBOL = cobc -std=cobol85

COB85DIR = "`cd $(srcdir) && pwd`"

# MAKEFLAGS = --no-print-directory

#

test: $(MODULES)
	@for m in $(MODULES); do \
	  (cd $$m && make test) \
	done
	@echo
	@perl $(srcdir)/summary.pl $(MODULES) > summary.log
	@echo "Comparing total test results"
if COB_MAKE_IX
	diff $(srcdir)/summary.txt summary.log
else
	diff $(srcdir)/summarynoix.txt summary.log
endif
	@echo

diff:
	@for m in $(MODULES); do \
	  (diff $(srcdir)/$$m.txt $$m/report.txt) \
	done
if COB_MAKE_IX
	diff $(srcdir)/summary.txt summary.log
else
	diff $(srcdir)/summarynoix.txt summary.log
endif

clean-local:
	rm -rf copy copyalt $(MODULES) EXEC85 summary.log EXEC85.cob

$(MODULES): newcob.val EXEC85 $(srcdir)/EXEC85.conf.in
	@echo -n "Building module directory $@ ..."
	@echo "*SELECT-MODULE `echo $@ | sed 's/\(..\).*/\1/'`" > EXEC85.conf
	@cat $(srcdir)/EXEC85.conf.in >> EXEC85.conf
	@. ../atconfig; . ../atlocal; ./EXEC85
	@perl $(srcdir)/expand.pl newcob.tmp $@
	@rm -f newcob.tmp newcob.log EXEC85.conf
	@echo "test:" > $@/Makefile
	@echo "	@echo" >> $@/Makefile
	@echo "	@echo \"Performing tests for module directory $@\"" >> $@/Makefile
	@echo "	@. ../../atconfig; . ../../atlocal; perl $(COB85DIR)/report.pl" >> $@/Makefile
	@echo "	@echo" >> $@/Makefile
	@echo "	@echo \"Comparing test results for module directory $@\"" >> $@/Makefile
	@echo "	diff $(COB85DIR)/$@.txt report.txt" >> $@/Makefile
	@echo "	@echo" >> $@/Makefile
#	@echo "	. ../../atconfig; . ../../atlocal; perl $(COB85DIR)/report.pl -O" >> $@/Makefile
#	@echo "	diff $(COB85DIR)/$@.txt report.txt" >> $@/Makefile
	@echo " done"

EXEC85: newcob.val
	@echo "Extracting EXEC85 program"
	@sed -e '/^\*END/,$$d' -e '1,/^\*HEADER/d' \
	-e 's/^002700.*/           "newcob.val" ORGANIZATION LINE SEQUENTIAL./' \
	-e 's/^003000.*/           "newcob.tmp" ORGANIZATION LINE SEQUENTIAL./' \
	-e 's/^003100.*//' \
	-e 's/^003400.*/           "unused"./' \
	-e 's/^003700.*/           "newcob.log"./' \
	-e 's/^004000.*/           "EXEC85.conf" ORGANIZATION LINE SEQUENTIAL./' \
	newcob.val > EXEC85.cob
	@echo "Compiling EXEC85 program"
	@. ../atconfig; . ../atlocal; cobc -std=mf -x EXEC85.cob
#	@rm -f EXEC85.cob
