/*
   Copyright (C) 2004-2010 Roger While

   This file is part of GNU Cobol.

   The GNU Cobol compiler is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Cobol; see the file COPYING. If not, write to
   the Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301 USA
*/


#include	"config.h"
#include	"defaults.h"

#include	<stdio.h>
#include        <stdlib.h>
#include	<string.h>
#include        <errno.h>
#include	"libcob.h"
#include	"tarstamp.h"

#ifdef	HAVE_KPATHSEA_GETOPT_H
#include <kpathsea/getopt.h>
#else
#ifdef	HAVE_GETOPT_H
#include <getopt.h>
#else
#include "lib/getopt.h"
#endif
#endif

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

static const char short_options[] = "hVM:";

static const struct option long_options[] = {
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'V'},
	{"module", required_argument, NULL, 'M'},
	{NULL, 0, NULL, 0}
};

/**
 * Display cobcrun build and version date
 */
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
	puts ("Copyright (C) 2004-2009 Roger While, 2014 Brian Tiffin");
	printf ("Built    %s\nPackaged %s\n", buff, COB_TAR_DATE);
}

/**
 * Display cobcrun help
 */
static void
cobcrun_print_usage (void)
{
	printf ("Usage: cobcrun [-Mmodule] PROGRAM [param ...]");
	printf ("\n\n");
	printf ("or   : cobcrun --help");
	printf ("\n");
	printf ("       Display this message");
	printf ("\n\n");
	printf ("or   : cobcrun --version, -V");
	printf ("\n");
	printf ("       Display runtime version");
	printf ("\n");
	printf ("       where -Mmodule prepends any directory to the");
	printf ("\n");
	printf ("           Dynamic Link loader library search path");
	printf ("\n");
	printf ("           and any basename to the module preload list");
	printf ("\n");
	printf ("           COB_LIBRARY_PATH and COB_PRE_LOAD");
	printf ("\n\n");
}

/**
 * split into path and file, or just path, or just file
 *  Note: strndup and strdup memory needs to be freed
 */
static void
cobcrun_split_path_file(char** p, char** f, char *pf)
{
	 char *slash = pf, *next;

	 while ((next = strpbrk(slash + 1, "\\/"))) slash = next;
	 if (pf != slash) slash++;

	 *p = strndup(pf, slash - pf);
	 *f = strdup(slash);
}

/**
 * Prepend a new directory path to the library search COB_LIBRARY_PATH
 * and setup a module COB_PRE_LOAD, for each component included.
 */
static int
cobcrun_initial_module (char *module_argument)
{
	int envop_return;
	char *pathname, *filename;
	char env_space[COB_MEDIUM_BUFF], *envptr;

	if (!module_argument) {
	    return 1;
	}

	/* See if we have a /dir/path/module, or a /dir/path/ or a module (no slash) */
	cobcrun_split_path_file(&pathname, &filename, module_argument);

	if (pathname && *pathname) {
	    memset(env_space, 0, COB_MEDIUM_BUFF);
	    envptr = getenv("COB_LIBRARY_PATH");
	    if (envptr) {
		snprintf(env_space, COB_MEDIUM_BUFF, "%s:%s", pathname, envptr);
	    } else {
		snprintf(env_space, COB_MEDIUM_BUFF, "%s", pathname);
	    }
	    envop_return = setenv("COB_LIBRARY_PATH", env_space, 1);
	    if (envop_return) {
		fprintf(stderr, "Problem with setenv COB_LIBRARY_PATH: %d\n", errno);
		return 1;
	    }
	    free(pathname);
	}

	if (filename && *filename) {
	    memset(env_space, 0, COB_MEDIUM_BUFF);
	    envptr = getenv("COB_PRE_LOAD");
	    if (envptr) {
		snprintf(env_space, COB_MEDIUM_BUFF, "%s:%s", filename, envptr);
	    } else {
		snprintf(env_space, COB_MEDIUM_BUFF, "%s", filename);
	    }
	    envop_return = setenv("COB_PRE_LOAD", filename, 1);
	    if (envop_return) {
		fprintf(stderr, "Problem with setenv COB_PRE_LOAD: %d\n", errno);
		return 1;
	    }
	    free(filename);
	}    
	return 0;
}

/**
 * Process command line arguments; help, version, and module setting
 *     skip is set to 1 if the argv array needs to adjust for -M arg
 */
static int
process_command_line (int argc, char *argv[], int *skip)
{
	int			c, idx;

	/* At least one option or module name needed */
	if (argc <= 1) {
		cobcrun_print_usage ();
		return 1;
	}

	/* Translate first command line argument from WIN to UNIX style */
	if (strrchr(argv[1], '/') == argv[1]) {
		argv[1][0] = '-';
	}

	/* Process first command line argument only if not a module */
	if (argv[1][0] != '-') {
		return 99;
	}

	c = getopt_long_only (argc, argv, short_options, long_options, &idx);
	if (c > 0) {
		switch (c) {
		case '?':
			return 1;
		case 'h':
			cobcrun_print_usage ();
			return 0;
		case 'V':
			cobcrun_print_version ();
			return 0;
		case 'M':
			if (cobcrun_initial_module (optarg)) {
				return 1;
			}
			*skip = optind;
			return 99;
		}
	}

	return 99;
}

/**
 * cobcrun, for invoking entry points from dynamic sharded object libraries
 */
int
main (int argc, char **argv)
{
	int pcl_return, skip;
	
	union {
		int	(*func)();
		void	*func_void;
	} unifunc;
	
#ifdef	HAVE_SETLOCALE
	setlocale (LC_ALL, "");
#endif

	
	skip = 1;
	pcl_return = process_command_line (argc, argv, &skip);

	if (pcl_return != 99) {
		return pcl_return;
	}

	/* -M with no program */
	if (skip >= argc) {
		fprintf (stderr, "-M path but no PROGRAM name\n");
		return 1;
	}

	if (strlen (argv[skip]) > 31) {
		fprintf (stderr, "Invalid PROGRAM name\n");
		return 1;
	}

	/* Initialize the COBOL system, resolve the PROGRAM name */
	/*   and invoke, wrapped in a STOP RUN, if found */
	cob_init (argc - skip, &argv[skip]);
	unifunc.func_void = cob_resolve (argv[skip]);
	if (unifunc.func_void == NULL) {
		cob_call_error ();
	}
	cob_stop_run ( unifunc.func() );
}
