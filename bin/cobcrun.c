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

#include "lib/cobgetopt.h"

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
}

static void
cobcrun_var_print (const char *msg, const char *val, const unsigned int env)
{
	char	*p;
	char	*token;
	size_t	n;
	size_t	lablen;
	size_t	toklen;

	if (!env) {
		printf ("%-*.*s : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
	} else {
		printf ("  %s: ", _("env"));
		lablen = CB_IMSG_SIZE - 2 - strlen(_("env")) - 2;
		printf ("%-*.*s : ", lablen, lablen, msg);
	}
	if (strlen(val) <= CB_IVAL_SIZE) {
		printf("%s\n", val);
		return;
	}
	p = strdup (val);
	if (!p) {
		fputs (_("Memory allocation failure"), stderr);
		putc ('\n', stderr);
		return;
	}
	n = 0;
	token = strtok (p, " ");
	for (; token; token = strtok (NULL, " ")) {
		toklen = strlen (token) + 1;
		if ((n + toklen) > CB_IVAL_SIZE) {
			if (n) {
				printf ("\n%*.*s", CB_IMSG_SIZE + 3,
					CB_IMSG_SIZE + 3, " ");
			}
			n = 0;
		}
		printf ("%s%s", (n ? " " : ""), token);
		n += toklen;
	}
	putchar ('\n');
	free (p);
}

static void
cobcrun_print_info (void)
{
	char	buff[16];
	char	*s;

	cobcrun_print_version ();
	putchar ('\n');
	puts (_("Build information"));
	cobcrun_var_print (_("Build environment"),	COB_BLD_BUILD, 0);
	cobcrun_var_print ("CC",			COB_BLD_CC, 0);
	cobcrun_var_print ("CPPFLAGS",		COB_BLD_CPPFLAGS, 0);
	cobcrun_var_print ("CFLAGS",		COB_BLD_CFLAGS, 0);
	cobcrun_var_print ("LD",			COB_BLD_LD, 0);
	cobcrun_var_print ("LDFLAGS",		COB_BLD_LDFLAGS, 0);
	putchar ('\n');
	puts (_("GNU Cobol information"));
#if 0 /* Simon: is this relevant for cobcrun? */
	cobcrun_var_print ("COB_CC",		COB_CC, 0);
	cobcrun_var_print ("COB_CFLAGS",		COB_CFLAGS, 0);
	cobcrun_var_print ("COB_LDFLAGS",		COB_LDFLAGS, 0);
	cobcrun_var_print ("COB_LIBS",		COB_LIBS, 0);
	cobcrun_var_print ("COB_CONFIG_DIR",	COB_CONFIG_DIR, 0);
	cobcrun_var_print ("COB_COPY_DIR",		COB_COPY_DIR, 0);
#endif
	if ((s = getenv ("COB_LIBRARY_PATH")) != NULL) {
		cobcrun_var_print ("COB_LIBRARY_PATH",	s, 1);
	}
	cobcrun_var_print ("COB_MODULE_EXT",	COB_MODULE_EXT, 0);
	cobcrun_var_print ("COB_EXEEXT",		COB_EXEEXT, 0);

#if	defined(USE_LIBDL) || defined(_WIN32)
	cobcrun_var_print (_("Dynamic loading"),	_("System"), 0);
#else
	cobcrun_var_print (_("Dynamic loading"),	_("Libtool"), 0);
#endif

#ifdef	COB_PARAM_CHECK
	cobcrun_var_print ("\"CBL_\" param check",	_("Enabled"), 0);
#else
	cobcrun_var_print ("\"CBL_\" param check",	_("Disabled"), 0);
#endif

	snprintf (buff, sizeof(buff), "%d", WITH_VARSEQ);
	cobcrun_var_print (_("Variable format"),	buff, 0);
	if ((s = getenv ("COB_VARSEQ_FORMAT")) != NULL) {
		cobcrun_var_print ("COB_VARSEQ_FORMAT", s, 1);
	}

#ifdef	COB_LI_IS_LL
	cobcrun_var_print ("BINARY-C-LONG",	_("8 bytes"), 0);
#else
	cobcrun_var_print ("BINARY-C-LONG",	_("4 bytes"), 0);
#endif

#ifdef	WITH_SEQRA_EXTFH
	cobcrun_var_print (_("Sequential handler"),	_("External"), 0);
#else
	cobcrun_var_print (_("Sequential handler"),	_("Internal"), 0);
#endif
#ifdef	WITH_INDEX_EXTFH
	cobcrun_var_print (_("ISAM handler"),		_("External"), 0);
#endif
#ifdef	WITH_DB
	cobcrun_var_print (_("ISAM handler"),		_("BDB"), 0);
#endif
#ifdef	WITH_CISAM
	cobcrun_var_print (_("ISAM handler"),		_("C-ISAM (Experimental)"), 0);
#endif
#ifdef	WITH_DISAM
	cobcrun_var_print (_("ISAM handler"),		_("D-ISAM (Experimental)"), 0);
#endif
#ifdef	WITH_VBISAM
	cobcrun_var_print (_("ISAM handler"),		_("VBISAM (Experimental)"), 0);
#endif
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

	/* Translate first command line argument from WIN to UNIX style */
	if (argv[1][0] == '/') {
		argv[1][0] = '-';
	}

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
			/* --help */
			cobcrun_print_info ();
			return 0;

		case 'V':
			/* --version */
			cobcrun_print_version ();
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
