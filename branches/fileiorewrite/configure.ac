#
# Configure template for GNU Cobol
# Process this file with autoconf to produce a configure script.
#
# Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2007-2012 Roger While
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

AC_PREREQ([2.64])

AC_INIT([GNU Cobol],
	[2.0],
	[open-cobol-list@lists.sourceforge.net],
	[gnu-cobol],
	[http://sourceforge.net/projects/open-cobol/])
AC_CONFIG_SRCDIR([libcob.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_TESTDIR([tests])
AC_CONFIG_MACRO_DIR([m4])

# Note for SUN Solaris (gcc)
# export/setenv CFLAGS "-m64 -mptr64"
# export/setenv LDFLAGS "-m64 -mptr64 -L/usr/local/lib/sparcv9"
# ./configure --libdir=/usr/local/lib/sparcv9
#
# Hack for AIX 64 bit (gcc)
# Required -
# export/setenv CFLAGS=-maix64
# export/setenv LDFLAGS=-maix64

if echo $CFLAGS | grep 'aix64' 1>/dev/null 2>&1
then
	if test -f /usr/ccs/bin/ar
	then
		AR="/usr/ccs/bin/ar -X64"
	else
		AR="ar -X64"
	fi
	NM="/usr/ccs/bin/nm -X64 -B"
fi

AM_INIT_AUTOMAKE([gnu no-texinfo.tex])
AM_MAINTAINER_MODE

# Autoheader templates
AH_TEMPLATE([WITH_RELATIVE], [The ORGANIZATION RELATIVE handler: standard])
AH_TEMPLATE([WITH_RELATIVE_NONE], [The ORGANIZATION RELATIVE handler: none])
AH_TEMPLATE([WITH_SEQUENTIAL], [The ORGANIZATION SEQUENTIAL handler: standard])
AH_TEMPLATE([WITH_SEQUENTIAL_NONE], [The ORGANIZATION SEQUENTIAL handler: none])
AH_TEMPLATE([WITH_INDEXED_CISAM], [The ORGANIZATION INDEXED handler: CISAM ])
AH_TEMPLATE([WITH_INDEXED_DISAM], [The ORGANIZATION INDEXED handler: DISAM])
AH_TEMPLATE([WITH_INDEXED_VBISAM], [The ORGANIZATION INDEXED handler: VBISAM])
AH_TEMPLATE([WITH_INDEXED_BDB], [The ORGANIZATION INDEXED handler: Berkeley DB])
AH_TEMPLATE([WITH_INDEXED_BDB_1], [The ORGANIZATION INDEXED handler: Berkeley DB < 4.1])
AH_TEMPLATE([WITH_INDEXED_ODBC], [The ORGANIZATION INDEXED handler: ODBC DB])
AH_TEMPLATE([WITH_INDEXED_NONE], [The ORGANIZATION INDEXED handler: none])
AH_TEMPLATE([WITH_ODBC_DYNAMIC_CONNECTION], [Get ODBC SERVER & DB from file name])
AH_TEMPLATE([WITH_VARSEQ], [Define variable sequential file format])
AH_TEMPLATE([WITH_RELATIVE_FIXED_RSZ], [Use fixed length records for relative file format])
AH_TEMPLATE([WITH_FILEIO_TRACE], [Include code to trace file i-o])
AH_TEMPLATE([WITH_FILEIO_STATS], [Include code to generate file i-o stats])
AH_TEMPLATE([WITH_FILEIO_LOG], [Include code to log file i-o])
AH_TEMPLATE([WITH_FILEIO_SHARING], [Include code to implement COBOL file sharing])
AH_TEMPLATE([WITH_FILEIO_EXCHANGE], [Include code to call external file-handler])
AH_TEMPLATE([WITH_FILE_STATUS_ANSI85], [Use ANSI85 file-status codes])
AH_TEMPLATE([WITH_FILE_STATUS_EXTENDED], [Use extended file-status codes: 9, cob_errno])
AH_TEMPLATE([WITH_FILE_STATUS_NATIVE], [Use errno in file-status codes: 8, errno])
AH_TEMPLATE([WITH_FILE_STATUS_RM], [Use RM file-status codes: 9, N])

AH_TEMPLATE([COB_IGNORE_NUMBER_ZONE], [Ignore zone on number conversion])
AH_TEMPLATE([COB_TREAT_NULL_AS_ZERO], [Interpret nulls in numerics as zeros])
AH_TEMPLATE([COB_EXPERIMENTAL], [Enable experimental code (Developers only!)])
AH_TEMPLATE([COB_PARAM_CHECK], [Enable CALL parameter checking])
AH_TEMPLATE([COB_EXPORT_DYN], [Compile/link option for exporting symbols])
AH_TEMPLATE([COB_PIC_FLAGS], [Compile/link option for PIC code])
AH_TEMPLATE([COB_SHARED_OPT], [Compile/link option for shared code])
AH_TEMPLATE([COB_STRIP_CMD], [Strip command])
AH_TEMPLATE([USE_LIBDL], [Use system dynamic loader])
AH_TEMPLATE([HAVE_DLADDR], [Has dladdr function])
AH_TEMPLATE([PATCH_LEVEL], [Define a patch level])
AH_TEMPLATE([HAVE_PSIGN_OPT], [Has -Wno-pointer-sign])
AH_TEMPLATE([HAVE_ATTRIBUTE_ALIGNED], [Has __attribute__((aligned))])
AH_TEMPLATE([HAVE_TIMEZONE], [Has timezone variable])
AH_TEMPLATE([COB_EXEEXT], [Executable extension])
AH_TEMPLATE([COB_KEYWORD_INLINE], [Keyword for inline])
AH_TEMPLATE([COB_NO_SELFOPEN], [Can not dlopen self])
AH_TEMPLATE([COB_STRFTIME], [Can use strftime for timezone])
AH_TEMPLATE([COB_LI_IS_LL], [long int is long long])
AH_TEMPLATE([WITH_CURSES], [curses library for extended SCREEN I/O])
AH_TEMPLATE([HAVE_COLOR_SET], [curses has color_set function])
AH_TEMPLATE([HAVE_CURSES_FREEALL], [ncurses has _nc_freeall function])
AH_TEMPLATE([HAVE_USE_LEGACY_CODING], [ncurses has use_legacy_coding function])
AH_TEMPLATE([HAVE_DESIGNATED_INITS], [Has designated initializers])
AH_TEMPLATE([HAVE_NANO_SLEEP], [Has nanosleep function])
AH_TEMPLATE([HAVE_RAISE], [Has raise function])
AH_TEMPLATE([HAVE_FINITE_IEEEFP_H],
	[Declaration of finite function in ieeefp.h instead of math.h])

save_libs="$LIBS"

# Basic capability tests

AC_PROG_CC([gcc xlc cc])
AC_PROG_CC_STDC

AC_PROG_CPP

AC_USE_SYSTEM_EXTENSIONS

LT_INIT([dlopen win32-dll])

AC_PROG_EGREP
AM_PROG_CC_C_O
# Stop tests for C++ and Fortran
AC_DEFUN([AC_PROG_F77], [])
AC_DEFUN([AC_PROG_CXX], [])
AC_PROG_LN_S
AC_PROG_INSTALL

# AC_LIBTOOL_DLOPEN
# AC_LIBTOOL_WIN32_DLL
# AC_PROG_LIBTOOL

AC_PROG_MAKE_SET
AC_LIB_RPATH

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdint.h sys/types.h signal.h fcntl.h malloc.h locale.h \
	stddef.h wchar.h dlfcn.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_BIGENDIAN
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_CHECK_TYPES([sig_atomic_t], [], [], [[#include <signal.h>]])

# Don't use AC_C_INLINE here. We need the value

AC_MSG_CHECKING([for inline keyword])
for cob_keyw in __inline __inline__ inline
do
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
		#ifndef __cplusplus
		typedef int foo_t;
		static $cob_keyw foo_t foo () { return 0; }
		#endif]], [[
		#ifndef __cplusplus
		return foo ();
		#else
		choke me
		#endif]])],
		[AC_DEFINE_UNQUOTED([COB_KEYWORD_INLINE], [$cob_keyw]) break],
		[],
		[])
done
AC_MSG_RESULT([$cob_keyw])
unset cob_keyw

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([memmove memset setlocale fcntl strerror strcasecmp])
AC_CHECK_FUNCS([strchr strrchr strdup strstr strtol gettimeofday localeconv])
AC_CHECK_FUNCS([readlink getexecname canonicalize_file_name realpath])
AC_CHECK_FUNCS([strcoll strxfrm])

# Check for timezone
AC_MSG_CHECKING([for timezone variable access])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <time.h>]],
	[[timezone = 3600;]])],
	[AC_DEFINE([HAVE_TIMEZONE], [1]) AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])])

# Check for designated initializers
AC_MSG_CHECKING([for designated initializers])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
	[[static const unsigned char valid_char[256] = {
		@<:@'0'@:>@ = 1,
		@<:@'1'@:>@ = 1 };
	]])],
	[AC_DEFINE([HAVE_DESIGNATED_INITS], [1]) AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])])

# Check gcc/icc
COB_USES_GCC_ICC=no
COB_USES_GCC_ONLY=no
COB_USES_ICC_ONLY=no

AC_RUN_IFELSE([AC_LANG_PROGRAM([[]], [[
	#ifdef __GNUC__
	return 0;
	#else
	return 1;
	#endif]])],
	[COB_USES_GCC_ICC=yes],
	[],
	[])

AC_RUN_IFELSE([AC_LANG_PROGRAM([[]], [[
	#if	defined(__GNUC__) && !defined(__INTEL_COMPILER)
	return 0;
	#else
	return 1;
	#endif]])],
	[COB_USES_GCC_ONLY=yes],
	[],
	[])

AC_RUN_IFELSE([AC_LANG_PROGRAM([[]], [[
	#ifdef __INTEL_COMPILER
	return 0;
	#else
	return 1;
	#endif]])],
	[COB_USES_ICC_ONLY=yes],
	[],
	[])

COB_CC="$CC"
if test "$COB_USES_ICC_ONLY" = "yes"
then
	LIBCOB_LIBS="-limf -lm"
else
	LIBCOB_LIBS="-lm"
fi

# Configure options.

AC_ARG_WITH([curses],
  [  --with-curses           (GNU Cobol) Used curses library for extended SCREEN I/O (default=check)],
  [case "$with_curses" in
    ncursesw | ncurses | pdcurses | curses | check | no)
		USE_NCURSES="$with_curses"
		;;
    *)
		AC_MSG_ERROR([Wrong value for --with-curses, must be one of the following
  ncursesw, ncurses, pdcurses, curses  (use only the specified library)
  check  (use whatever curses libary is usable, disable if no curses usable)
  no  (disable curses usage)])
		;;
  esac],
  [USE_NCURSES="check"])

AC_ARG_WITH(relative,
  [  --with-relative         (GNU Cobol) RELATIVE Handler [[default=yes]]],
  [ case "$with_relative" in
		yes )
			WITH_RELATIVE=1
			AC_DEFINE(WITH_RELATIVE)
			;;
		no )
			WITH_RELATIVE_NONE=1
			AC_DEFINE(WITH_RELATIVE_NONE)
			;;
		* )
			AC_MSG_ERROR(["--with-relative expects: yes no"])
    esac ],
  [
		# default if no ref to --with-relative
		WITH_RELATIVE=1
		AC_DEFINE(WITH_RELATIVE)
  ])


AC_ARG_WITH(sequential,
  [  --with-sequential       (GNU Cobol) SEQUENTIAL Handler [[default=yes]]],
  [ case "$with_sequential" in
		yes )
			WITH_SEQUENTIAL=1
			AC_DEFINE(WITH_SEQUENTIAL)
			;;
		no )
			WITH_SEQUENTIAL_NONE=1
			AC_DEFINE(WITH_SEQUENTIAL_NONE)
			;;
		* )
			AC_MSG_ERROR(["--with-sequential expects: yes no"])
    esac ],
  [
		# default if no ref to --with-sequential
		WITH_SEQUENTIAL=1
		AC_DEFINE(WITH_SEQUENTIAL)
  ])


do_cobol85_IX_tests="yes"

AC_ARG_WITH(indexed,
  [  --with-indexed          (GNU Cobol) INDEXED Handler :: yes | no | cisam | disam | vbisam | bdb | bdb1 | odbc | odbc_dsn [[default=bdb]]],
  [ case "$with_indexed" in
    	cisam ) 
			AC_CHECK_HEADERS([isam.h], , AC_MSG_ERROR(isam.h is required for CISAM))
			AC_CHECK_LIB([ifisam], [isopen], , AC_MSG_ERROR(libifisam is required for CISAM), [ifisamx])
			WITH_INDEXED_CISAM=1
			AC_DEFINE(WITH_INDEXED_CISAM)
			LIBCOB_LIBS="$LIBCOB_LIBS -lifisam -lifisamx"
			;;
		disam )
			AC_CHECK_HEADERS([disam.h], , AC_MSG_ERROR(disam.h is required for DISAM))
			AC_CHECK_LIB([disam], [isopen], , AC_MSG_ERROR(libdisam is required for DISAM))
			WITH_INDEXED_DISAM=1
			AC_DEFINE(WITH_INDEXED_DISAM)
			LIBCOB_LIBS="$LIBCOB_LIBS -ldisam"
			;;
		vbisam )
			AC_CHECK_HEADERS([vbisam.h], , AC_MSG_ERROR(vbisam.h is required for VBISAM))
			AC_CHECK_LIB([vbisam], [isopen], , AC_MSG_ERROR(libvbisam is required for VBISAM))
			WITH_INDEXED_VBISAM=1
			AC_DEFINE(WITH_INDEXED_VBISAM)
			LIBCOB_LIBS="$LIBCOB_LIBS -lvbisam"
			;;
		bdb | yes )	   # default
			# Checks postponed
			WITH_INDEXED_BDB=1
			;;
		bdb1 )
			AC_CHECK_HEADERS([db1.h], , AC_MSG_ERROR(Berkeley DB db1.h is required for BDB1. Please copy or link db.h to db1.h))
			AC_SEARCH_LIBS([dbopen], [db1], , AC_MSG_ERROR(library libdb1 is required for BDB1. Please copy or link libdb to libdb1))
			LIBCOB_LIBS="$LIBCOB_LIBS ${ac_cv_search_dbopen}"
			WITH_INDEXED_BDB_1=1
			AC_DEFINE(WITH_INDEXED_BDB_1)
			;;
		odbc )
			AC_CHECK_HEADERS([sql.h], , AC_MSG_ERROR(sql.h is required for ODBC DB))
			AC_CHECK_HEADERS([sqlext.h], , AC_MSG_ERROR(sqlext.h is required for ODBC DB))
			AC_CHECK_LIB([odbc], [SQLAllocHandle], , AC_MSG_ERROR(libodbc is required for ODBC DB))
			WITH_INDEXED_ODBC=1
			AC_DEFINE(WITH_INDEXED_ODBC)
			LIBCOB_LIBS="$LIBCOB_LIBS -lodbc"
			;;
		no )
			WITH_INDEXED_NONE=1
			AC_DEFINE(WITH_INDEXED_NONE)
			do_cobol85_IX_tests="no"
			;;
		* )
			AC_MSG_ERROR(["--with-indexed expects: cisam disam vbisam bdb bdb1 odbc yes no"])
    esac ],
  [
		# default if no ref to --with-indexed
		# Checks postponed
		WITH_INDEXED_BDB=1

  ])


if test "$WITH_INDEXED_BDB" = "1"
	then
	AC_MSG_NOTICE([Checks for Berkeley DB ...])

	AC_CHECK_HEADERS([db.h], [], AC_MSG_ERROR([Berkeley DB db.h is required for BDB]), [])

	# BDB header exists. Extract major/minor number pair
	COB_BDB_HEADER=''
	AC_RUN_IFELSE([AC_LANG_SOURCE([[
		#include <stdio.h>
		#include <db.h>
		int main (int argc, char **argv)
		{
			(void)argv;
			if (argc > 1)
				printf ("%d.%d\n", DB_VERSION_MAJOR, DB_VERSION_MINOR);
			return 0;
		}
		]])],
		[COB_BDB_HEADER=`./conftest$ac_exeext x`],
		[AC_MSG_ERROR([Unable to extract Berkeley DB version information from db.h])],
		[])
	if test "x$COB_BDB_HEADER" = "x"
	then
		AC_MSG_ERROR([Unable to extract Berkeley DB version information])
	fi
	AC_MSG_CHECKING([for Berkeley DB db.h version >= 4.1])
	COB_BDB_HEADER_MAJOR=$(echo $COB_BDB_HEADER | cut -d. -f1)
	if test $COB_BDB_HEADER_MAJOR -gt 4
	then
		AC_MSG_RESULT([yes ($COB_BDB_HEADER)])
	else
		COB_BDB_HEADER_MINOR=$(echo $COB_BDB_HEADER | cut -d. -f2)
		if test $COB_BDB_HEADER_MAJOR -eq 4 -a $COB_BDB_HEADER_MINOR -ge 1
		then
			AC_MSG_RESULT([yes ($COB_BDB_HEADER)])
		else
			AC_MSG_RESULT([no ($COB_BDB_HEADER)])
			AC_MSG_ERROR([Berkeley DB db.h has incompatible version])
		fi
	fi
	MYOLDLIBS="$LIBS"
	cob_got_db=no
	AC_MSG_CHECKING([for Berkeley DB library with version $COB_BDB_HEADER])
	for cobdb in db db-$COB_BDB_HEADER
	do
		LIBS="$MYOLDLIBS -l$cobdb"
		AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>
		#include <db.h>]], [[
		int major, minor, patch;
		db_version (&major, &minor, &patch);
		if (major == DB_VERSION_MAJOR && minor == DB_VERSION_MINOR) {
			return 0;
		}
		return 1;]])],
		[AC_DEFINE(WITH_INDEXED_BDB)
		cob_got_db=yes
		LIBCOB_LIBS="$LIBCOB_LIBS -l$cobdb"
		break],
		[],
		[])
	done
	LIBS="$MYOLDLIBS"
	if test "$cob_got_db" = "yes"
	then
		AC_MSG_RESULT([yes])
		AC_MSG_NOTICE([BDB library version $COB_BDB_HEADER found as -l$cobdb])
	else
		AC_MSG_RESULT([no])
		AC_MSG_ERROR([BDB library version $COB_BDB_HEADER not found])
	fi
	unset cobdb
	unset cob_got_db
	unset COB_BDB_HEADER
fi

AC_ARG_WITH(file-status,
  [  --with-file-status      (GNU Cobol) File-status codes :: ansi85 | ext\[ended\] | native | rm [[default=ext]]],
  [ case "$with_file_status" in
		ansi85 )
			WITH_FILE_STATUS_ANSI85=1
			AC_DEFINE(WITH_FILE_STATUS_ANSI85)
			;;
		ext | extended )
			WITH_FILE_STATUS_EXTENDED=1
			AC_DEFINE(WITH_FILE_STATUS_EXTENDED)
			;;
		native )
			WITH_FILE_STATUS_NATIVE=1
			AC_DEFINE(WITH_FILE_STATUS_NATIVE)
			;;
		rm | RM )
			WITH_FILE_STATUS_RM=1
			AC_DEFINE(WITH_FILE_STATUS_RM)
			;;
		* )
			AC_MSG_ERROR(["--with-file-status expects: ansi85 ext\[ended\] native rm"])
    esac ],
  [
		# default if no ref to --with-file-status
		WITH_FILE_STATUS_EXTENDED=1
		AC_DEFINE(WITH_FILE_STATUS_EXTENDED)
  ])



AC_ARG_WITH([dl],
  [  --with-dl               (GNU Cobol) Use system dynamic loader [[default=yes]]],
  [case $with_dl in  
    yes)
		;;
    no)
		;;
    *)		AC_MSG_ERROR([[--with/without-dl can not have a value]])
		;;
   esac],
  [with_dl=yes])

AC_ARG_ENABLE([debug],
  [  --enable-debug                (GNU Cobol) Enable -g C compiler debug option],
  [],
  [enable_debug=no])

AC_ARG_ENABLE([experimental],
  [  --enable-experimental         (GNU Cobol) Enable experimental code (Developers only!)],
  [if test "$enable_experimental" = "yes"
   then
	AC_DEFINE([COB_EXPERIMENTAL], [1])
   fi],
  [])

AC_ARG_ENABLE([param-check],
  [  --enable-param-check    (GNU Cobol) Enable CALL parameter checking (default no)],
  [if test "$enable_param_check" = "yes"
   then
	AC_DEFINE([COB_PARAM_CHECK], [1])
   fi],
  [])

AC_ARG_ENABLE(ignore-number-zone,
  [  --enable-ignore-number-zone   (GNU Cobol) disregard top 4 bits of numeric character],
  [if test "$enable_ignore_number_zone" = "yes"
   then
	AC_DEFINE(COB_IGNORE_NUMBER_ZONE)
   fi])

AC_ARG_ENABLE(treat-null-as-zero,
  [  --enable-treat-null-as-zero   (GNU Cobol) interpret nulls in numeric fields as zeros],
  [if test "$enable_treat_null_as_zero" = "yes"
   then
	AC_DEFINE(COB_TREAT_NULL_AS_ZERO)
   fi])

AC_ARG_ENABLE(relative-fixed,
  [  --enable-relative-fixed       (GNU Cobol) use fixed length records on relative format],
  [if test "$enable_relative_fixed" = "yes"
   then
	AC_DEFINE(WITH_RELATIVE_FIXED_RSZ)
   fi])

AC_ARG_ENABLE(fileio-trace,
  [  --enable-fileio-trace         (GNU Cobol) enable code to generate diagnostic trace of file io],
  [if test "$enable_fileio_trace" = "yes"
   then
	AC_DEFINE(WITH_FILEIO_TRACE)
   fi])

AC_ARG_ENABLE(fileio-stats,
  [  --enable-fileio-stats         (GNU Cobol) enable code to generate file io statistics],
  [if test "$enable_fileio_stats" = "yes"
   then
	AC_DEFINE(WITH_FILEIO_STATS)
   fi])

AC_ARG_ENABLE(fileio-log,
  [  --enable-fileio-log           (GNU Cobol) enable code to generate file io log],
  [if test "$enable_fileio_log" = "yes"
   then
    # Some non LINUX environments might not support syslog
	AC_CHECK_HEADERS([syslog.h], , AC_MSG_ERROR(syslog is required for file io log. syslog.h not found))
	AC_DEFINE(WITH_FILEIO_LOG)
   fi])

AC_ARG_ENABLE(fileio-sharing,
  [  --enable-fileio-sharing       (GNU Cobol) enable code to control file sharing],
  [if test "$enable_fileio_sharing" = "yes"
   then
	AC_DEFINE(WITH_FILEIO_SHARING)
   fi])

AC_ARG_ENABLE(fileio-exchange,
  [  --enable-fileio-exchange      (GNU Cobol) enable code to call external file-handler],
  [if test "$enable_fileio_exchange" = "yes"
   then
	AC_DEFINE(WITH_FILEIO_EXCHANGE)
   fi])

AC_ARG_ENABLE(odbc_dynamic_connection,
  [  --enable-odbc_dynamic_connection (GNU Cobol) extract ODBC SERVER and DB names from COBOL file-name],
  [if test "$enable_odbc_dynamic_connection" = "yes"
   then
	AC_DEFINE(WITH_ODBC_DYNAMIC_CONNECTION)
   fi])

AC_ARG_WITH([patch-level],
  [  --with-patch-level      (GNU Cobol) Define a patch level [[default=0]]],
  [case $with_patch_level in  
    yes)	AC_MSG_ERROR([[You must give --with-patch-level an argument.]])
		;;
    no)		AC_MSG_ERROR([[--without-patch-level not supported.]])
		;;
    [[0-9]]*)
		;;
    *)		AC_MSG_ERROR([[You must use a numeric patch level]])
		;;
  esac],
  [with_patch_level=0])

AC_DEFINE_UNQUOTED([PATCH_LEVEL], [$with_patch_level])

AC_ARG_WITH([varseq],
  [  --with-varseq           (GNU Cobol) Define variable sequential format [[default=0]]],
  [case $with_varseq in
    yes)        AC_MSG_ERROR([[You must give --with-varseq an argument.]])
                ;;
    no)         AC_MSG_ERROR([[--without-varseq not supported.]])
                ;;
    [[0-3]])
                ;;
    *)          AC_MSG_ERROR([[Invalid --with-varseq argument]])
                ;;
  esac],
  [with_varseq=0])

AC_DEFINE_UNQUOTED([WITH_VARSEQ], [$with_varseq])


# Checks for gmp.
AC_MSG_NOTICE([Checks for GMP ...])
AC_CHECK_HEADERS([gmp.h], [], AC_MSG_ERROR([gmp.h (GMP) is required]), [])

AC_CHECK_LIB([gmp], [__gmpz_init],
	[LIBCOB_LIBS="$LIBCOB_LIBS -lgmp"],
	AC_MSG_ERROR([GMP is required]), [])

# Check just major/minor levels between header and library
MYOLDLIBS=$LIBS
LIBS="$MYOLDLIBS -lgmp"
# get GMP version from header
AC_RUN_IFELSE([AC_LANG_SOURCE([[
	#include <stdio.h>
	#include <gmp.h>
	int main (int argc, char **argv)
	{
		(void)argv;
		if (argc > 1)
			printf ("%d.%d\n", __GNU_MP_VERSION, __GNU_MP_VERSION_MINOR);
		return 0;
	}
	]])],
	[COB_GMP_HEADER=`./conftest$ac_exeext x`],
	[AC_MSG_ERROR([Unable to extract GMP version information from gmp.h])],
	[])
if test "x$COB_GMP_HEADER" = "x"
then
	AC_MSG_ERROR([Unable to extract GMP version information])
fi

# get GMP version from lib
AC_RUN_IFELSE([AC_LANG_SOURCE([[
	#include <stdio.h>
	#include <gmp.h>
	int main (int argc, char **argv)
	{
		(void)argv;
		if (argc > 1)
			puts (gmp_version);
		return 0;
	}
	]])],
	[COB_GMP_LIB=`./conftest$ac_exeext x`],
	[AC_MSG_ERROR([Unable to extract GMP version information from gmp_version])],
	[])
if test "x$COB_GMP_LIB" = "x"
then
	AC_MSG_ERROR([Unable to extract GMP version information])
fi

AC_MSG_CHECKING([matching GMP version])
COB_GMP_LIB_MAJOR=$(echo $COB_GMP_LIB | cut -d. -f1)
COB_GMP_LIB_MINOR=$(echo $COB_GMP_LIB | cut -d. -f2)

if test "$COB_GMP_HEADER" == "$COB_GMP_LIB_MAJOR.$COB_GMP_LIB_MINOR"
then
	AC_MSG_RESULT([yes ($COB_GMP_HEADER)])
else
	AC_MSG_RESULT([no ($COB_GMP_HEADER / $COB_GMP_LIB)])
	AC_MSG_ERROR([Unable to use GMP - Please check config.log])
fi
LIBS=$MYOLDLIBS


# Solaris has nanosleep in other libraries
AC_MSG_CHECKING([for nanosleep])
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <time.h>]],
  [[nanosleep (NULL, NULL);]])],
  [AC_DEFINE([HAVE_NANO_SLEEP], [1]) AC_MSG_RESULT([yes])],
  [AC_CHECK_LIB([rt], [nanosleep], [], [], [])
   if test "x$ac_cv_lib_rt_nanosleep" = "xyes"
   then
     AC_DEFINE([HAVE_NANO_SLEEP], [1])
     AC_MSG_RESULT([yes])
     LIBCOB_LIBS="$LIBCOB_LIBS -lrt"
   else
     AC_CHECK_LIB([posix4], [nanosleep], [], [], [])
     if test "x$ac_cv_lib_posix4_nanosleep" = "xyes"
     then
       AC_DEFINE([HAVE_NANO_SLEEP], [1])
       AC_MSG_RESULT([yes])
       LIBCOB_LIBS="$LIBCOB_LIBS -lposix4"
     else
       AC_MSG_RESULT([no])
     fi
   fi])

# Check for raise (optional)
AC_MSG_CHECKING([for raise])
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <signal.h>]],
  [[raise (SIGINT);]])],
  [AC_DEFINE([HAVE_RAISE], [1]) AC_MSG_RESULT([yes])],
  [AC_MSG_RESULT([no])],
  [])

# Check prototype for finite in math.h (alternative ieeefp.h)
AC_MSG_CHECKING([prototype for finite in <math.h>])
AC_EGREP_HEADER(finite, math.h, AC_MSG_RESULT([yes]),
	[AC_MSG_RESULT([no])
	AC_MSG_CHECKING([prototype for finite in <ieeefp.h>])
	AC_EGREP_HEADER(finite, ieeefp.h,
	[AC_DEFINE([HAVE_FINITE_IEEEFP_H], [1]) AC_MSG_RESULT([yes])],
	AC_MSG_ERROR([
		Declaration for finite function neither in math.h nor in ieeefp.h]))
	])

AC_CHECK_FUNCS([fdatasync sigaction])

# Checks for gettext.

case $host_os in
  darwin* | rhapsody*)
	;;
  *)
	gt_cv_func_CFPreferencesCopyAppValue=no
	gt_cv_func_CFLocaleCopyCurrent=no
	;;
esac

# Disable for Cygwin
AC_RUN_IFELSE([AC_LANG_PROGRAM([[]], [[
	#ifdef __CYGWIN__
	return 0;
	#else
	return 1;
	#endif]])],
	[enable_nls=no],
	[],
	[])

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.17])
if test "x$LTLIBINTL" != "x"
then
  COBC_LIBS="$COBC_LIBS $LTLIBINTL"
  LIBCOB_LIBS="$LIBCOB_LIBS $LTLIBINTL"
fi

# Checks for internationalization stuff
# AM_ICONV
AM_LANGINFO_CODESET


# Checks for ncurses/pdcurses/curses.
AC_MSG_NOTICE([Checks for curses ...])

if test "$USE_NCURSES" = "ncursesw" -o "$USE_NCURSES" = "check"
then
  AC_CHECK_LIB([ncursesw], [initscr], [], [], [])
  if test "x$ac_cv_lib_ncursesw_initscr" = "xyes"
  then
    AC_CHECK_HEADERS([ncursesw/ncurses.h], [USE_NCURSES="ncursesw"],
      [AC_CHECK_HEADERS([ncursesw/curses.h], [USE_NCURSES="ncursesw"],
        [if test "$USE_NCURSES" = "ncursesw"
         then
           USE_NCURSES="missing_header"
         fi], [])], [])      
    if test "$USE_NCURSES" = "ncursesw"
    then
      LIBCOB_LIBS="$LIBCOB_LIBS -lncursesw"
    fi
  else
    if test "$USE_NCURSES" = "ncursesw"
    then
      USE_NCURSES="missing_lib"
    fi
  fi
fi

if test "$USE_NCURSES" = "ncurses" -o "$USE_NCURSES" = "check"
then
  AC_CHECK_LIB([ncurses], [initscr], [], [], [])
  if test "x$ac_cv_lib_ncurses_initscr" = "xyes"
  then
    AC_CHECK_HEADERS([ncurses.h], [USE_NCURSES="ncurses"],
      [AC_CHECK_HEADERS([ncurses/ncurses.h], [USE_NCURSES="ncurses"],
         [AC_CHECK_HEADERS([curses.h], [USE_NCURSES="ncurses"],
           [if test "$USE_NCURSES" = "ncurses"
            then
              USE_NCURSES="missing_header"
            fi], [])], [])], [])
    if test "$USE_NCURSES" = "ncurses"
    then
      LIBCOB_LIBS="$LIBCOB_LIBS -lncurses"
    fi
  else
    if test "$USE_NCURSES" = "ncurses"
    then
      USE_NCURSES="missing_lib"
    fi
  fi
fi


if test "$USE_NCURSES" = "pdcurses" -o "$USE_NCURSES" = "check"
then
  AC_CHECK_LIB([pdcurses], [initscr], [], [], [])
  if test "x$ac_cv_lib_pdcurses_initscr" = "xyes"
  then
    AC_CHECK_HEADERS([pdcurses.h], [USE_NCURSES="pdcurses"],
      [AC_CHECK_HEADERS([curses.h], [USE_NCURSES="pdcurses"],
         [if test "$USE_NCURSES" = "pdcurses"
          then
            USE_NCURSES="missing_header"
          fi], [])], [])
    if test "$USE_NCURSES" = "pdcurses"
    then
      LIBCOB_LIBS="$LIBCOB_LIBS -lpdcurses"
    fi
  else
    if test "$USE_NCURSES" = "pdcurses"
    then
      USE_NCURSES="missing_lib"
    fi
  fi
fi

if test "$USE_NCURSES" = "curses" -o "$USE_NCURSES" = "check"
then
  AC_CHECK_LIB([curses], [initscr], [], [], [])
  if test "x$ac_cv_lib_curses_initscr" = "xyes"
  then
    AC_CHECK_HEADERS([curses.h], [USE_NCURSES="curses"],
      [if test "$USE_NCURSES" = "pdcurses"
       then
         USE_NCURSES="missing_header"
       fi], [])
    if test "$USE_NCURSES" != "no"
    then
      LIBCOB_LIBS="$LIBCOB_LIBS -lcurses"
    fi
  fi
else
  if test "$USE_NCURSES" = "curses"
  then
    USE_NCURSES="missing_lib"
  fi
fi

case "$USE_NCURSES" in
  check)
	USE_NCURSES="not_found"
	;;
  missing_lib)
	AC_MSG_ERROR([[Not able to link configured library $with_curses]])
	;;
  missing_header)
	AC_MSG_ERROR([[No header found for configured library $with_curses]])
	;;
esac

if test "$USE_NCURSES" = "ncurses" -o "$USE_NCURSES" = "ncursesw"
then
    AC_MSG_CHECKING([for ncurses _nc_freeall function])
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[
    extern void _nc_freeall (void);]],
    [[_nc_freeall ();]])],
    [AC_DEFINE([HAVE_CURSES_FREEALL], [1]) AC_MSG_RESULT([yes])],
    [AC_MSG_RESULT([no])],
    [])
    AC_MSG_CHECKING([for ncurses use_legacy_coding function])
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[
    extern void use_legacy_coding (void);]],
    [[use_legacy_coding ();]])],
    [AC_DEFINE([HAVE_USE_LEGACY_CODING], [1]) AC_MSG_RESULT([yes])],
    [AC_MSG_RESULT([no])],
    [])
fi

if test "$USE_NCURSES" != "no" -a "$USE_NCURSES" != "not_found"
then
	AC_MSG_CHECKING([for curses color_set function])
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[
	#ifdef HAVE_NCURSESW_NCURSES_H
	#include <ncursesw/ncurses.h>
	#elif defined (HAVE_NCURSESW_CURSES_H)
	#include <ncursesw/curses.h>
	#elif defined (HAVE_NCURSES_H)
	#include <ncurses.h>
	#elif defined (HAVE_NCURSES_NCURSES_H)
	#include <ncurses/ncurses.h>
	#elif defined (HAVE_PDCURSES_H)
	#include <pdcurses.h>
	#elif defined (HAVE_CURSES_H)
	#include <curses.h>
	#endif]], [[
	color_set (0, NULL);]])],
	[AC_DEFINE([HAVE_COLOR_SET], [1]) AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])],
	[])
fi


# Checks for dl/ltdl.
DEFINE_DL="no"

AC_RUN_IFELSE([AC_LANG_PROGRAM([[]], [[
	#ifdef _WIN32
	return 0;
	#else
	return 1;
	#endif]])],
	[DEFINE_DL="yes"],
	[],
	[])

if test "$DEFINE_DL" = "no" -a "$with_dl" = "yes"
then
  if test "x$ac_cv_header_dlfcn_h" = "xyes"
  then
    AC_CHECK_LIB([c], [dlopen], [DEFINE_DL="yes"], [], [])
    if test "$DEFINE_DL" = "no"
    then
      AC_CHECK_LIB([dl], [dlopen], [DEFINE_DL="yes"], [], [])
      if test "$DEFINE_DL" = "yes"
      then
        AC_DEFINE([USE_LIBDL], [1])
        LIBCOB_LIBS="$LIBCOB_LIBS -ldl"
        AC_CHECK_LIB([dl], [dladdr], [AC_DEFINE([HAVE_DLADDR], [1])], [], [])
      else
        AC_CHECK_LIB([dld], [dlopen], [DEFINE_DL="yes"], [], [])
        if test "$DEFINE_DL" = "yes"
        then
          AC_DEFINE([USE_LIBDL], [1])
          LIBCOB_LIBS="$LIBCOB_LIBS -ldld"
          AC_CHECK_LIB([dld], [dladdr], [AC_DEFINE([HAVE_DLADDR], [1])], [], [])
        fi
      fi
    else
      AC_DEFINE([USE_LIBDL], [1])
      AC_CHECK_LIB([c], [dladdr], [AC_DEFINE([HAVE_DLADDR], [1])], [], [])
    fi
  fi
fi

if test "$DEFINE_DL" = "no"
then
  AC_CHECK_HEADERS([ltdl.h], [], AC_MSG_ERROR([ltdl.h is required]), [])
  AC_CHECK_LIB([ltdl], [lt_dlopen],
	[LIBCOB_LIBS="$LIBCOB_LIBS -lltdl"],
	AC_MSG_ERROR([libltdl is required]), [])
fi

# Checks for workable strftime
AC_MSG_CHECKING([for working strftime])
AC_RUN_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>
	#include <time.h>]], [[
	time_t	ticks;
	int	ret;
	char	buff[16];
	ticks = time(NULL);
	ret = strftime(buff, 15, "%z", localtime(&ticks));
	if (ret != 5) {
		return 1;
	}
	if (buff[0] != '+' && buff[0] != '-') {
		return 1;
	}
	return 0;]])],
	[AC_DEFINE([COB_STRFTIME], [1]) AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])],
	[])

# Checks for size of long
AC_MSG_CHECKING([if size of long int = size of long long])
AC_RUN_IFELSE([AC_LANG_PROGRAM([[]], [[
	if (sizeof(long int) == sizeof(long long))
		return 0;
	return 1;
	]])],
	[AC_DEFINE([COB_LI_IS_LL], [1]) AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])],
	[])

# Check gcc 4 pointer sign option
if test "$COB_USES_GCC_ONLY" = "yes"
then
	MYOLDCFLAGS="$CFLAGS"
	CFLAGS="$CFLAGS -Wno-pointer-sign"
	AC_MSG_CHECKING([for gcc pointer sign option])
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[int testint;]])],
		[AC_DEFINE([HAVE_PSIGN_OPT], [1]) AC_MSG_RESULT([yes])],
		[AC_MSG_RESULT([no])])
	CFLAGS="$MYOLDCFLAGS"
fi

#if test "$enable_debug" != "yes" -a "$COB_USES_GCC_ONLY" = "yes"
#then
#	MYOLDCFLAGS="$CFLAGS"
#	CFLAGS="$CFLAGS -fno-asynchronous-unwind-tables"
#	AC_MSG_CHECKING([for gcc unwind tables option])
#	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[int testint;]])],
#		[AC_DEFINE([HAVE_UNWIND_OPT], [1]) AC_MSG_RESULT([yes])],
#		[AC_MSG_RESULT([no])])
#	CFLAGS="$MYOLDCFLAGS"
#fi

# Check gcc wrapv option
# We MAY need this eventually for >= 4.4. 4.3 appears to be OK.
#if test "$COB_USES_GCC_ONLY" = "yes"
#then
#	MYOLDCFLAGS="$CFLAGS"
#	CFLAGS="$CFLAGS -fwrapv"
#	AC_MSG_CHECKING([for gcc -fwrapv option])
#	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[int testint;]])],
#		[AC_DEFINE([HAVE_FWRAPV_OPT], [1]) AC_MSG_RESULT([yes])],
#		[AC_MSG_RESULT([no])])
#		[],
#		[CFLAGS="$MYOLDCFLAGS"])
#	CFLAGS="$MYOLDCFLAGS"
#fi

# Check if aligned attribute works
AC_MSG_CHECKING([for aligned attribute])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]],
	[[char testchar[4] __attribute__((aligned));]])],
	[AC_DEFINE([HAVE_ATTRIBUTE_ALIGNED], [1]) AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])])

# GNU Cobol Configuration

if test "x$prefix" = "xNONE"
then
  if test "x$includedir" = "x\${prefix}/include"
  then
    COB_CFLAGS="-I${ac_default_prefix}/include"
  else
    COB_CFLAGS="-I${includedir}"
  fi
else
  if test "x$includedir" = "x\${prefix}/include"
  then
    if test "x$prefix" = "x/usr"
    then
      COB_CFLAGS=""
    else
      COB_CFLAGS="-I${prefix}/include"
    fi
  else
    COB_CFLAGS="-I${includedir}"
  fi
fi

if test "x$CPPFLAGS" != "x"
then
	COB_CFLAGS="$COB_CFLAGS $CPPFLAGS"
fi

COB_LIBS="-L$libdir -lcob ${LIBCOB_LIBS}"
COB_LDFLAGS=""
if test "x$LDFLAGS" != "x"
then
	COB_LIBS="$LDFLAGS $COB_LIBS"
	COB_LDFLAGS="$LDFLAGS"
fi

COB_CONFIG_DIR="$datadir/$PACKAGE_TARNAME/config"
COB_COPY_DIR="$datadir/$PACKAGE_TARNAME/copy"
COB_LIBRARY_PATH="$libdir/$PACKAGE_TARNAME"
COB_MODULE_EXT=`echo "$acl_cv_shlibext" | sed -e 's/dll\.a/dll/'`
LIBS="$save_libs"
COB_EXPORT_DYN="`eval echo $export_dynamic_flag_spec`"
COB_PIC_FLAGS=`echo "$lt_prog_compiler_pic" | sed -e 's/^ //'`
COB_SHARED_OPT="-shared"
COB_EXEEXT="$EXEEXT"

if test "$enable_debug" != "yes" -a "x$CFLAGS" != "x"
then
	CFLAGS=`echo "$CFLAGS" | sed -e 's/-g//' -e 's/^ //' -e 's/ $//'`
fi

# Include CFLAGS in COB_CFLAGS without optimization/debug options

cob_temp_flags=""
if test "x$CFLAGS" != "x"
then
	cob_temp_flags=`echo "$CFLAGS" | sed -e 's/-g//' -e 's/ $//' -e 's/^ //'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/@<:@+-@:>@O@<:@0-9s@:>@//' -e 's/ $//' -e 's/^ //'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/-O//' -e 's/ $//' -e 's/^ //'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/-fmessage-length=0//'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/-D_FORTIFY_SOURCE=.//'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/-fstack-protector//'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/-funwind-tables//'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/-fasynchronous-unwind-tables//'`
	cob_temp_flags=`echo "$cob_temp_flags" | sed -e 's/  */ /g' -e 's/ $//' -e 's/^ //'`
fi

if test "x$cob_temp_flags" != "x"
then
	COB_CFLAGS="$COB_CFLAGS $cob_temp_flags"
fi
unset cob_temp_flags

if test "$COB_USES_GCC_ICC" = "yes"
then
	if test "x$CFLAGS" != "x"
	then
		CFLAGS="$CFLAGS -pipe"
	else
		CFLAGS="-pipe"
	fi
	if test "x$COB_CFLAGS" != "x"
	then
		COB_CFLAGS="$COB_CFLAGS -pipe"
	else
		COB_CFLAGS="-pipe"
	fi
fi

# Special stuff

AH_VERBATIM([_XOPEN_SOURCE_EXTENDED],
[/* Define to 1 if on HPUX.  */
#ifndef _XOPEN_SOURCE_EXTENDED
# undef _XOPEN_SOURCE_EXTENDED
#endif])dnl

COB_FIX_LIB="$COB_EXPORT_DYN"
COB_FIX_LIBTOOL=""
case $host_os in
  mingw*)
	if test "$prefix" = "NONE"
	then
	COB_CONFIG_DIR="`cd /usr && pwd -W`/local/share/$PACKAGE_TARNAME/config"
	COB_COPY_DIR="`cd /usr && pwd -W`/local/share/$PACKAGE_TARNAME/copy"
	fi
	COB_EXPORT_DYN="-Wl,--export-all-symbols -Wl,--enable-auto-import -Wl,--enable-auto-image-base"
	COB_FIX_LIB=""
	COB_FIX_LIBTOOL="-Wl,--enable-auto-import"
	;;
  cygwin*)
	COB_EXPORT_DYN="-Wl,--export-all-symbols -Wl,--enable-auto-import -Wl,--enable-auto-image-base"
	COB_FIX_LIB=""
	COB_FIX_LIBTOOL="-Wl,--enable-auto-import"
	;;
  darwin* | rhapsody*)
	COB_SHARED_OPT="-bundle -flat_namespace -undefined suppress"
	;;
  hpux*)
	if test "$COB_USES_GCC_ICC" != "yes"
	then
		COB_SHARED_OPT="-b"
		AC_DEFINE([_XOPEN_SOURCE_EXTENDED], [1])
		rm -f hptest*
		echo 'int main() { return 0; }' > hptest.c
		${CC} ${CFLAGS} +Olit=all -o hptest hptest.c > hptest.out 2>&1
		if test $? -ne 0 -o -s hptest.out
		then
			CFLAGS="$CFLAGS +ESlit +O2"
			COB_CFLAGS="$COB_CFLAGS +ESlit -w"
		else
			CFLAGS="$CFLAGS +Olit=all +O2"
			COB_CFLAGS="$COB_CFLAGS +Olit=all -w"
		fi
		rm -f hptest*
	fi
	;;
  aix*)
	COB_EXPORT_DYN="-Wl,-bexpfull -Wl,-brtl"
	if test "$COB_USES_GCC_ICC" != "yes"
	then
		CFLAGS="$CFLAGS -O2 -Q -qro -qroconst"
		COB_SHARED_OPT="-G"
		COB_FIX_LIB=""
		# COB_FIX_LIB="-Wc,-G $COB_EXPORT_DYN"
		# COB_CFLAGS="$COB_CFLAGS -qchars=signed"
	else
		COB_FIX_LIB="$COB_EXPORT_DYN"
	fi
	;;
  solaris*)
	if test "$COB_USES_GCC_ICC" != "yes"
	then
		CFLAGS="$CFLAGS -xO2 -xstrconst"
		COB_CFLAGS="$COB_CFLAGS -xstrconst"
		COB_SHARED_OPT="-G"
	fi
	;;
esac

if test "$COB_USES_GCC_ONLY" = "yes" && test "$with_gnu_ld" = "yes"
then
	MYOLDLDFLAGS="$LDFLAGS"
	LDFLAGS="$LDFLAGS -Wl,-z,relro,-z,now,-O1"
	AC_MSG_CHECKING([for ld bind now option])
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[int testint;]])],
		[AC_MSG_RESULT([yes])],
		[LDFLAGS=$MYOLDLDFLAGS
		 AC_MSG_RESULT([no])])
	unset MYOLDLDFLAGS
	CFLAGS="$CFLAGS -finline-functions -fsigned-char -Wall -Wwrite-strings -Wmissing-prototypes -Wno-format-y2k"
	if test "$enable_debug" != "yes"
	then
		CFLAGS="$CFLAGS -U_FORTIFY_SOURCE"
	fi
elif test "$COB_USES_ICC_ONLY" = "yes"
then
	CFLAGS="$CFLAGS -finline-functions -Wall -wd1419 -vec-report0 -opt-report 0"
fi

if test "x$lt_cv_dlopen_self" != "xyes"
then
	AC_DEFINE([COB_NO_SELFOPEN], [1])
fi



unset COB_USES_GCC_ICC
unset COB_USES_GCC_ONLY
unset COB_USES_ICC_ONLY
unset MYOLDCFLAGS
unset MYOLDLIBS
unset MYOCLIBS

# Generate the output

AM_CONDITIONAL([COB_MAKE_IX], [test $do_cobol85_IX_tests = "yes"])

AC_DEFINE_UNQUOTED([COB_EXPORT_DYN], ["$COB_EXPORT_DYN"])
AC_DEFINE_UNQUOTED([COB_PIC_FLAGS], ["$COB_PIC_FLAGS"])
AC_DEFINE_UNQUOTED([COB_SHARED_OPT], ["$COB_SHARED_OPT"])
AC_DEFINE_UNQUOTED([COB_EXEEXT], ["$COB_EXEEXT"])
if test "x$striplib" != "x"
then
	AC_DEFINE_UNQUOTED([COB_STRIP_CMD], ["$striplib"])
fi
AC_SUBST([COB_CC])
AC_SUBST([COB_CFLAGS])
AC_SUBST([COB_LDFLAGS])
AC_SUBST([COB_LIBS])
AC_SUBST([COB_CONFIG_DIR])
AC_SUBST([COB_COPY_DIR])
AC_SUBST([COB_LIBRARY_PATH])
AC_SUBST([COB_MODULE_EXT])
AC_SUBST([COBC_LIBS])
AC_SUBST([LIBCOB_LIBS])
AC_SUBST([COB_EXPORT_DYN])
AC_SUBST([COB_PIC_FLAGS])
AC_SUBST([COB_SHARED_OPT])
COB_BIGENDIAN="$ac_cv_c_bigendian"
AC_SUBST([COB_BIGENDIAN])
AC_SUBST([COB_FIX_LIB])
AC_SUBST([COB_FIX_LIBTOOL])
AC_SUBST([COB_KEYWORD_INLINE])
AC_SUBST([COB_PATCH_LEVEL], [$with_patch_level])

AC_CONFIG_FILES([bin/cob-config Makefile libcob/Makefile lib/Makefile
	cobc/Makefile bin/Makefile po/Makefile.in doc/Makefile
	config/Makefile copy/Makefile
	tests/atlocal tests/Makefile tests/cobol85/Makefile
	extras/Makefile])

AC_CONFIG_COMMANDS([chmod1], [chmod +x bin/cob-config])
AC_CONFIG_COMMANDS([chmod2], [chmod +x tests/atconfig])
AC_CONFIG_COMMANDS([chmod3], [chmod +x tests/atlocal])

AC_OUTPUT

AC_MSG_NOTICE([GNU Cobol Configuration:])
AC_MSG_NOTICE([ CC                ${CC}])
AC_MSG_NOTICE([ CFLAGS            ${CFLAGS}])
AC_MSG_NOTICE([ COB_CFLAGS        ${COB_CFLAGS}])
AC_MSG_NOTICE([ LDFLAGS           ${LDFLAGS}])
AC_MSG_NOTICE([ COB_LDFLAGS       ${COB_LDFLAGS}])
if test "x$COBC_LIBS" != "x"
then
  AC_MSG_NOTICE([ COBC_LIBS         ${COBC_LIBS}])
fi
AC_MSG_NOTICE([ COB_LIBS          ${COB_LIBS}])
AC_MSG_NOTICE([ COB_CONFIG_DIR    ${COB_CONFIG_DIR}])
AC_MSG_NOTICE([ COB_COPY_DIR      ${COB_COPY_DIR}])
AC_MSG_NOTICE([ COB_LIBRARY_PATH  ${COB_LIBRARY_PATH}])
AC_MSG_NOTICE([ COB_MODULE_EXT    ${COB_MODULE_EXT}])
AC_MSG_NOTICE([ COB_OBJECT_EXT    ${COB_OBJECT_EXT}])
AC_MSG_NOTICE([ COB_SHARED_OPT    ${COB_SHARED_OPT}])
AC_MSG_NOTICE([ COB_PIC_FLAGS     ${COB_PIC_FLAGS}])
AC_MSG_NOTICE([ COB_EXPORT_DYN    ${COB_EXPORT_DYN}])
if test "x$striplib" != "x"
then
  AC_MSG_NOTICE([ COB_STRIP_CMD     ${striplib}])
fi
if test "${DEFINE_DL}" = "yes" 
then
  AC_MSG_NOTICE([ Dynamic loading:  System])
else
  AC_MSG_NOTICE([ Dynamic loading:  Libtool])
fi
AC_MSG_NOTICE([ Use gettext for international messages:      ${USE_NLS}])
AC_MSG_NOTICE([ Use fcntl for file locking:                  ${ac_cv_func_fcntl}])
case "$USE_NCURSES" in
  not_found)
    AC_MSG_NOTICE([ screen I/O (no curses found):                NO])
	;;
  no)
    AC_MSG_NOTICE([ screen I/O (disabled)       :                NO])
	;;
  *)
    AC_MSG_NOTICE([ Use ncurses/pdcurses/curses for screen I/O:  ${USE_NCURSES}])
	;;
esac
AC_MSG_NOTICE([])
AC_MSG_NOTICE([GNU Cobol FILE I-O:])
if test "${WITH_RELATIVE}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION RELATIVE I-O:       standard])
fi
if test "${WITH_RELATIVE_NONE}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION RELATIVE I-O:       none])
fi

if test "${WITH_SEQUENTIAL}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION SEQUENTIAL I-O:     standard])
fi
if test "${WITH_SEQUENTIAL_NONE}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION SEQUENTIAL I-O:     none])
fi

if test "${WITH_INDEXED_CISAM}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        CISAM])
fi
if test "${WITH_INDEXED_DISAM}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        DISAM])
fi
if test "${WITH_INDEXED_VBISAM}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        VBISAM])
fi
if test "${WITH_INDEXED_BDB}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        Berkeley DB])
fi
if test "${WITH_INDEXED_BDB_1}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        Berkeley DB < 4.1])
fi
if test "${WITH_INDEXED_ODBC}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        ODBC Database])
  if test "$enable_odbc_dynamic_connection" = "yes"
  then
     AC_MSG_NOTICE([  Get ODBC SERVER and DB names from file-name: yes])
  fi
fi
if test "${WITH_INDEXED_NONE}" != ""
then
  AC_MSG_NOTICE([  Handler for ORGANIZATION INDEXED I-O:        none])
fi

if test "${WITH_FILE_STATUS_ANSI85}" != ""
then
  AC_MSG_NOTICE([  File Status Key coding:                      ANSI85])
fi
if test "${WITH_FILE_STATUS_EXTENDED}" != ""
then
  AC_MSG_NOTICE([  File Status Key coding:                      extended: 9/cobol_rts_errno])
fi
if test "${WITH_FILE_STATUS_NATIVE}" != ""
then
  AC_MSG_NOTICE([  File Status Key coding:                      native: 8/os_errno])
fi
if test "${WITH_FILE_STATUS_RM}" != ""
then
  AC_MSG_NOTICE([  File Status Key coding:                      RM: 9N])
fi

AC_MSG_NOTICE([  Use fcntl for file locking:                  ${ac_cv_func_fcntl}])
AC_MSG_NOTICE([  SEQUENTIAL variable length records style:    ${with_varseq}])
if test "$enable-relative-fixed" = "yes"
then
  AC_MSG_NOTICE([  Use fixed length records for RELATIVE:       yes])
fi
if test "$enable_fileio_trace" = "yes"
then
  AC_MSG_NOTICE([  Include code for fileio trace:               yes])
fi
if test "$enable_fileio_log" = "yes"
then
  AC_MSG_NOTICE([  Include code for fileio log:                 yes])
fi
if test "$enable_fileio_stats" = "yes"
then
  AC_MSG_NOTICE([  Include code for fileio stats:               yes])
fi
if test "$enable_fileio_sharing" = "yes"
then
  AC_MSG_NOTICE([  Include code for file sharing:               yes])
fi
if test "$enable_fileio_exchange" = "yes"
then
  AC_MSG_NOTICE([  Include code to call external file-handler:  yes])
fi
AC_MSG_NOTICE([])

unset DEFINE_DL
