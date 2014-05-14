/*
   Copyright (C) 2004-2012 Roger While
   Copyright (C) 2012,2014 Simon Sobisch

   This file is part of GNU Cobol.

   The GNU Cobol compiler is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Cobol.  If not, see <http://www.gnu.org/licenses/>.
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

static const char short_options[] = "hirV";

#define	CB_NO_ARG	no_argument

static const struct option long_options[] = {
	{"help",		CB_NO_ARG, NULL, 'h'},
	{"info",		CB_NO_ARG, NULL, 'i'},
	{"runtime-env",	CB_NO_ARG, NULL, 'r'},
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


static void
cobcrun_print_version (void)
{
	int	year;
	int	day;
	char	buff[64];
	char	month[64];

	memset (buff, 0, sizeof(buff));
	memset (month, 0, sizeof(month));
	day = 0;
	year = 0;
	sscanf (__DATE__, "%s %d %d", month, &day, &year);
	if (day && year) {
		sprintf (buff, "%s %2.2d %4.4d %s", month, day, year, __TIME__);
	} else {
		sprintf (buff, "%s %s", __DATE__, __TIME__);
	}
	printf ("cobcrun (%s) %s.%d\n",
		PACKAGE_NAME, PACKAGE_VERSION, PATCH_LEVEL);
	puts ("Copyright (C) 2004-2012 Roger While");
	puts ("Copyright (C) 2012,2014 Simon Sobisch");
	puts (_("This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."));
	printf (_("Built     %s"), buff);
	putchar ('\n');
	printf (_("Packaged  %s"), COB_TAR_DATE);
	putchar ('\n');
}

static void
cobcrun_print_usage (void)
{
	puts (_("Usage: cobcrun PROGRAM [param ...]"));
	puts (_("or   : cobcrun options"));
	putchar ('\n');
	puts (_("Options:"));
	puts (_("  -help                 Display this message"));
	puts (_("  -version, -V          Display runtime version"));
	puts (_("  -info, -i             Display runtime information (build/environment)"));
	puts (_("  -runtime-env, -r             Display runtime information (build/environment)"));
}

static int
process_command_line (int argc, char *argv[])
{
	int			c, idx;

	/* At least one option or module name needed */
	if (argc <= 1) {
		cobcrun_print_usage ();
		return 1;
	}

#ifdef _WIN32
	/* Translate first command line argument from WIN to UNIX style */
	if (strrchr(argv[1], '/') == argv[1]) {
		argv[1][0] = '-';
	}
#endif

	/* Process first command line argument only if not a module */
	if (argv[1][0] != '-') {
		return 99;
	}

	c = cob_getopt_long_long (argc, argv, short_options,
					  long_options, &idx, 1);
	if (c > 0) {
		switch (c) {
		case '?':
			/* Unknown option or ambiguous */
			return 1;

		case 'h':
			/* --help */
			cobcrun_print_usage ();
			return 0;

		case 'i':
			/* --info */
			print_info ();
			return 0;

		case 'r':
			/* --runtime-env */
			print_runtime_env ();
			return 0;

		case 'V':
			/* --version */
			cobcrun_print_version ();
			putchar('\n');
			print_version();
			return 0;
		}
	}

	return 99;
}

int
main (int argc, char **argv)
{
	int pcl_return;
	cob_call_union	unifunc;

#ifdef	HAVE_SETLOCALE
	setlocale (LC_ALL, "");
#endif

	pcl_return = process_command_line (argc, argv);

	if (pcl_return != 99) {
		return pcl_return;
	}
	if (strlen (argv[1]) > 31) {
		fputs (_("PROGRAM name exceeds 31 characters"), stderr);
		putc ('\n', stderr);
		return 1;
	}
	cob_init (argc - 1, &argv[1]);
	unifunc.funcvoid = cob_resolve (argv[1]);
	if (unifunc.funcvoid == NULL) {
		cob_call_error ();
	}
	cob_stop_run ( unifunc.funcint() );
}
