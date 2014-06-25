/*
   Copyright (C) 2004-2012 Roger While
   Copyright (C) 2012,2014 Simon Sobisch
   Copyright (C) 2013 Sergey Kashyrin

   This file is part of GNU Cobol C++.

   The GNU Cobol C++ compiler is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol C++ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.
*/


#include	"config.h"
#include	"defaults.h"

#include	<stdio.h>
#include	<stdlib.h>
#include	<stddef.h>
#include	<string.h>
#include	"libcob.h"
#include	"tarstamp.h"

#include "libcob/cobgetopt.h"

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

static const char short_options[] = "hiV";

#define	CB_NO_ARG	no_argument

static const struct option long_options[] = {
	{"help",		CB_NO_ARG, NULL, 'h'},
	{"info",		CB_NO_ARG, NULL, 'i'},
	{"version",   	CB_NO_ARG, NULL, 'V'},
	{NULL, 0, NULL, 0}
};

#if	defined(ENABLE_NLS) && defined(COB_NLS_RUNTIME)
#include "lib/gettext.h"
#define _(s)		gettext(s)
#define N_(s)		gettext_noop(s)
#else
#define _(s)		s
#define N_(s)		s
#endif

#define	CB_IMSG_SIZE	24
#define	CB_IVAL_SIZE	(80 - CB_IMSG_SIZE - 4)

static void COB_NOINLINE
print_version(void)
{
	char buff[64];
	memset(buff, 0, sizeof(buff));
	char month[64];
	memset(month, 0, sizeof(month));
	int day = 0;
	int year = 0;
	sscanf(__DATE__, "%s %d %d", month, &day, &year);
	if(day && year) {
		sprintf(buff, "%s %2.2d %4.4d %s", month, day, year, __TIME__);
	} else {
		sprintf(buff, "%s %s", __DATE__, __TIME__);
	}
	printf("cobcrun (%s) %s.%d\n",
		PACKAGE_NAME, PACKAGE_VERSION, PATCH_LEVEL);
	puts("Copyright (C) 2004-2012 Roger While");
	puts("Copyright (C) 2013 Sergey Kashyrin");
	puts(_("This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."));
	printf(_("Built     %s"), buff);
	putchar('\n');
	printf(_("Packaged  %s"), COB_TAR_DATE);
	putchar('\n');
}

static void COB_NOINLINE
print_usage(void)
{
	puts(_("Usage: cobcrun PROGRAM [param ...]"));
	puts(_("or   : cobcrun --help (-h)"));
	puts(_("       Print this help"));
	puts(_("or   : cobcrun --version (-V)"));
	puts(_("       Print version information"));
	puts(_("or   : cobcrun --info (-i)"));
	puts(_("       Print build information"));
}

static void COB_NOINLINE
cobc_var_print(const char *msg, const char *val)
{
	printf("%-*.*s : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
	if(strlen(val) <= CB_IVAL_SIZE) {
		printf("%s\n", val);
		return;
	}
	char * p = strdup(val);
	if(!p) {
		fputs(_("Memory allocation failure"), stderr);
		putc('\n', stderr);
		return;
	}
	size_t n = 0;
	for(char * token = strtok(p, " "); token; token = strtok(NULL, " ")) {
		size_t toklen = strlen(token) + 1;
		if((n + toklen) > CB_IVAL_SIZE) {
			if(n) {
				printf("\n%*.*s", CB_IMSG_SIZE + 3,
					CB_IMSG_SIZE + 3, " ");
			}
			n = 0;
		}
		printf("%s%s", (n ? " " : ""), token);
		n += toklen;
	}
	putchar('\n');
	free(p);
}

static void COB_NOINLINE
print_info(void)
{
	print_version();
	puts(_("Build information"));
	cobc_var_print("Build environment",	COB_BLD_BUILD);
	cobc_var_print("CC",				COB_BLD_CC);
	cobc_var_print("CFLAGS",			COB_BLD_CFLAGS);
	cobc_var_print("LD",				COB_BLD_LD);
	cobc_var_print("LDFLAGS",			COB_BLD_LDFLAGS);
	putchar('\n');
	puts(_("GNU Cobol C++ information"));
	cobc_var_print("COB_CC",			COB_CC);
	cobc_var_print("COB_CFLAGS",		COB_CFLAGS);
	cobc_var_print("COB_LDFLAGS",		COB_LDFLAGS);
	cobc_var_print("COB_LIBS",			COB_LIBS);
	cobc_var_print("COB_CONFIG_DIR",	COB_CONFIG_DIR);
	cobc_var_print("COB_COPY_DIR",		COB_COPY_DIR);
	cobc_var_print("COB_LIBRARY_PATH",	COB_LIBRARY_PATH);
	cobc_var_print("COB_MODULE_EXT",	COB_MODULE_EXT);
	cobc_var_print("COB_EXEEXT",		COB_EXEEXT);

#if	defined(USE_LIBDL) || defined(_WIN32)
	cobc_var_print(_("Dynamic loading"),	_("System"));
#else
	cobc_var_print(_("Dynamic loading"),	_("Libtool"));
#endif

#ifdef	COB_PARAM_CHECK
	cobc_var_print("\"CBL_\" param check",	_("Enabled"));
#else
	cobc_var_print("\"CBL_\" param check",	_("Disabled"));
#endif

	char buff[4];
	sprintf(buff, "%d", WITH_VARSEQ);
	cobc_var_print(_("Variable format"),	buff);

#ifdef	COB_LI_IS_LL
	cobc_var_print("BINARY-C-LONG",	_("8 bytes"));
#else
	cobc_var_print("BINARY-C-LONG",	_("4 bytes"));
#endif

#ifdef	WITH_SEQRA_EXTFH
	cobc_var_print(_("Sequential handler"),	_("External"));
#else
	cobc_var_print(_("Sequential handler"),	_("Internal"));
#endif
#ifdef	WITH_INDEX_EXTFH
	cobc_var_print(_("ISAM handler"),		_("External"));
#endif
#ifdef	WITH_DB
	cobc_var_print(_("ISAM handler"),		_("BDB"));
#endif
#ifdef	WITH_CISAM
	cobc_var_print(_("ISAM handler"),		_("C-ISAM (Experimental)"));
#endif
#ifdef	WITH_DISAM
	cobc_var_print(_("ISAM handler"),		_("D-ISAM (Experimental)"));
#endif
#ifdef	WITH_VBISAM
	cobc_var_print(_("ISAM handler"),		_("VBISAM (Experimental)"));
#endif
}

static int
process_command_line (int argc, char *argv[])
{
	/* At least one option or module name needed */
	if (argc <= 1) {
		print_usage();
		return 1;
	}

	/* Translate first command line argument from WIN to UNIX style */
	if (argv[1][0] == '/') {
		argv[1][0] = '-';
		}

	/* Process first command line argument only if not a module */
	if (argv[1][0] != '-') {
		return 99;
	}

	int	idx;
	int c = cob_getopt_long_long (argc, argv, short_options,
					  long_options, &idx, 1);
	if (c > 0) {
		switch (c) {
		case '?':
			/* Unknown option or ambiguous */
			return 1;

		case 'h':
			/* --help */
			print_usage();
			return 0;

		case 'i':
			/* --help */
			print_info();
			return 0;

		case 'V':
			/* --version */
			print_version ();
			return 0;
		}
	}

	return 99;
}

int
main (int argc, char **argv)
{

#ifdef	HAVE_SETLOCALE
	setlocale (LC_ALL, "");
#endif

	int pcl_return = process_command_line (argc, argv);

	if (pcl_return != 99) {
		return pcl_return;
	}
	if(strlen(argv[1]) > 31) {
		fputs(_("PROGRAM name exceeds 31 characters"), stderr);
		putc('\n', stderr);
		return 1;
	}
	cob_init(argc - 1, &argv[1]);
	cob_call_union unifunc;
	unifunc.funcvoid = cob_resolve(argv[1]);
	if(unifunc.funcvoid == NULL) {
		cob_call_error();
	}
	cob_stop_run(unifunc.funcint());
}
