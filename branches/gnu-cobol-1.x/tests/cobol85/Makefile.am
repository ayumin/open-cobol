#
# Makefile gnucobol/tests/cobol85
# Process this file with automake to produce Makefile.in
#
# Copyright (C) 2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2008-2011 Roger While
#
# This file is part of GNU Cobol.
#
# The GNU Cobol compiler is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2 of the
# License, or (at your option) any later version.
#
# GNU Cobol is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Cobol; see the file COPYING. If not, write to
# the Free Software Foundation, 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA

#MODULES = CM DB IC IF IX NC OB RL RW SG SM SQ ST
MODULES = NC SM IC SQ RL IX ST SG OB IF

EXTRA_DIST = EXEC85.conf.in expand.pl report.pl summary.pl summary.txt \
	NC.txt SM.txt IC.txt SQ.txt RL.txt IX.txt ST.txt SG.txt OB.txt IF.txt ifedit.sh
CLEANFILES = EXEC85 summary.log

COBOL = cobc -std=cobol85

COB85DIR = "`cd $(srcdir) && pwd`"

test: $(MODULES)
	@for m in $(MODULES); do \
	  (cd $$m && make test) \
	done
	perl $(srcdir)/summary.pl $(MODULES) > summary.log
	test -e $(srcdir)/summary.txt && diff $(srcdir)/summary.txt summary.log

save:
	@for m in $(MODULES); do \
	  (cp $$m/report.txt $$m.txt) \
	done
	cp summary.log summary.txt

diff:
	@for m in $(MODULES); do \
	  (diff $$m.txt $$m/report.txt) \
	done
	diff summary.txt summary.log

clean-local:
	rm -rf copy copyalt $(MODULES)

$(MODULES): newcob.val EXEC85 $(srcdir)/EXEC85.conf.in
	@echo -n "Building module $@..."
	@sed 's/@MODULE@/$@/' $(srcdir)/EXEC85.conf.in > EXEC85.conf
	@. ../atconfig; . ../atlocal; export PATH; ./EXEC85
	@$(srcdir)/ifedit.sh
	@perl $(srcdir)/expand.pl newcob.tmp
	@rm -f newcob.tmp newcob.log EXEC85.conf
	@echo "test:"               > $@/Makefile
	@echo "	. ../../atconfig; . ../../atlocal; export PATH; perl $(COB85DIR)/report.pl" >> $@/Makefile
	@echo "	diff $(COB85DIR)/$@.txt report.txt" >> $@/Makefile
	@echo "	. ../../atconfig; . ../../atlocal; export PATH; perl $(COB85DIR)/report.pl -O" >> $@/Makefile
	@echo "	diff $(COB85DIR)/$@.txt report.txt" >> $@/Makefile
	@echo "done"

EXEC85: newcob.val
	@perl -pe 'BEGIN{<>; <>;} exit if /^\*END/;' newcob.val		     \
	| sed -e 's/XXXXX001.*/"newcob.val" ORGANIZATION LINE SEQUENTIAL./'  \
	      -e 's/XXXXX002.*/"newcob.tmp" ORGANIZATION LINE SEQUENTIAL./'  \
	      -e 's/XXXXX003.*/"unused"./'				     \
	      -e 's/XXXXX055.*/"newcob.log"./'				     \
	      -e 's/XXXXX058.*/"EXEC85.conf" ORGANIZATION LINE SEQUENTIAL./' \
	      -e 's/ORGANIZATION SEQUENTIAL.*//'			     \
	    > EXEC85.cob
	. ../atconfig; . ../atlocal; export PATH; $(COBOL) -x EXEC85.cob
	@rm -f EXEC85.cob
