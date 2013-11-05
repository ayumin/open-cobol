#
# Makefile gnu-cobol-cpp/tests
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

SUBDIRS = cobol85

TESTSUITE = $(srcdir)/testsuite

testsuite_sources = \
	testsuite.src/syn_copy.at \
	testsuite.src/syn_definition.at \
	testsuite.src/syn_expression.at \
	testsuite.src/syn_multiply.at \
	testsuite.src/syn_redefines.at \
	testsuite.src/syn_value.at \
	testsuite.src/syn_move.at \
	testsuite.src/syn_set.at \
	testsuite.src/syn_occurs.at \
	testsuite.src/syn_misc.at \
	testsuite.src/syn_subscripts.at \
	testsuite.src/run_fundamental.at \
	testsuite.src/run_accept.at \
	testsuite.src/run_initialize.at \
	testsuite.src/run_misc.at \
	testsuite.src/run_refmod.at \
	testsuite.src/run_subscripts.at \
	testsuite.src/run_extensions.at \
	testsuite.src/run_returncode.at \
	testsuite.src/run_functions.at \
	testsuite.src/data_binary.at \
	testsuite.src/data_display.at \
	testsuite.src/data_packed.at \
	testsuite.src/data_pointer.at \
	testsuite.src/numeric-dump.cob \
	testsuite.src/numeric-display.cob

EXTRA_DIST = $(srcdir)/package.m4 $(TESTSUITE) \
	$(srcdir)/testsuite.at \
	$(testsuite_sources)

DISTCLEANFILES = atconfig

check-local: $(TESTSUITE)
	@$(TESTSUITE) $(TESTSUITEFLAGS) || rm -f testsuite.dir/at-job-fifo
	@rm -f testsuite.dir/at-job-fifo

clean-local:
	rm -rf *.dir *.log

$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	@echo "creating $(srcdir)/package.m4"
	@{								   \
	  echo '# Signature of the current package.';			   \
	  echo 'm4_define([AT_PACKAGE_NAME],	  [@PACKAGE_NAME@])';	   \
	  echo 'm4_define([AT_PACKAGE_TARNAME],	  [@PACKAGE_TARNAME@])';   \
	  echo 'm4_define([AT_PACKAGE_VERSION],	  [@PACKAGE_VERSION@])';   \
	  echo 'm4_define([AT_PACKAGE_STRING],	  [@PACKAGE_STRING@])';    \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [@PACKAGE_BUGREPORT@])'; \
	  echo 'm4_define([AT_PACKAGE_URL],       [@PACKAGE_URL@])'; \
	} > $(srcdir)/package.m4

$(TESTSUITE): $(testsuite_sources) $(srcdir)/package.m4 $(srcdir)/testsuite.at
	autom4te --language=autotest -I $(srcdir) -I $(srcdir)/testsuite.src -o $(srcdir)/testsuite $(srcdir)/testsuite.at
	chmod +x $(srcdir)/testsuite

