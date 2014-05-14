/*
   Copyright (C) 2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While

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


#include "config.h"
#include "defaults.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#include "cobc.h"

enum cb_config_type {
	CB_ANY = 0,
	CB_INT,			/* integer */
	CB_STRING,		/* "..." */
	CB_BOOLEAN,		/* 'yes', 'no' */
	CB_SUPPORT		/* 'ok', 'archaic', 'obsolete',
				   'skip', 'ignore', 'unconformable' */
};

/* Global variables */

#undef	CB_CONFIG_ANY
#undef	CB_CONFIG_INT
#undef	CB_CONFIG_STRING
#undef	CB_CONFIG_BOOLEAN
#undef	CB_CONFIG_SUPPORT

#define CB_CONFIG_ANY(type,var,name)	type		var = (type)0;
#define CB_CONFIG_INT(var,name)		int		var = 0;
#define CB_CONFIG_STRING(var,name)	const char	*var = NULL;
#define CB_CONFIG_BOOLEAN(var,name)	int		var = 0;
#define CB_CONFIG_SUPPORT(var,name)	enum cb_support	var = CB_OK;

#include "config.def"

#undef	CB_CONFIG_ANY
#undef	CB_CONFIG_INT
#undef	CB_CONFIG_STRING
#undef	CB_CONFIG_BOOLEAN
#undef	CB_CONFIG_SUPPORT

#define CB_CONFIG_ANY(type,var,name)	, {CB_ANY, name, (void *)&var, NULL}
#define CB_CONFIG_INT(var,name)		, {CB_INT, name, (void *)&var, NULL}
#define CB_CONFIG_STRING(var,name)	, {CB_STRING, name, (void *)&var, NULL}
#define CB_CONFIG_BOOLEAN(var,name)	, {CB_BOOLEAN, name, (void *)&var, NULL}
#define CB_CONFIG_SUPPORT(var,name)	, {CB_SUPPORT, name, (void *)&var, NULL}

/* Local variables */

static struct config_struct {
	const enum cb_config_type	type;
	const char			*name;
	void				*var;
	char				*val;
} config_table[] = {
	{CB_STRING, "include", NULL, NULL}
	, {CB_STRING, "not-reserved", NULL, NULL}
#include "config.def"
};

#undef	CB_CONFIG_ANY
#undef	CB_CONFIG_INT
#undef	CB_CONFIG_STRING
#undef	CB_CONFIG_BOOLEAN
#undef	CB_CONFIG_SUPPORT

#define	CB_CONFIG_SIZE	sizeof(config_table) / sizeof(struct config_struct)

/* Local functions */

static char *
read_string (const char *text)
{
	char			*p;
	char			*s;

	s = cobc_main_strdup (text);
	if (*s == '\"') {
		s++;
	}
	for (p = s; *p; p++) {
		if (*p == '\"') {
			*p = '\0';
		}
	}
	return s;
}

static void
invalid_value (const char *fname, const int line, const char *name)
{
	fprintf (stderr, "%s:%d: ", fname, line);
	fprintf (stderr, _("Invalid value for '%s'"), name);
	putc ('\n', stderr);
	fflush (stderr);
}

static void
unsupported_value (const char *fname, const int line, const char *val)
{
	fprintf (stderr, "%s:%d: ", fname, line);
	fprintf (stderr, _("'%s' not supported"), val);
	putc ('\n', stderr);
	fflush (stderr);
}

/* Global functions */

int
cb_load_std (const char *name)
{
	return cb_load_conf (name, 1, 1);
}

int
cb_load_conf (const char *fname, const int check_nodef, const int prefix_dir)
{
	char			*s;
	const unsigned char	*x;
	char			*e;
	const char		*name;
	const char		*val;
	void			*var;
	FILE			*fp;
	struct noreserve	*noresptr;
	size_t			size;
	size_t			i;
	size_t			j;
	int			ret;
	int			saveret;
	int			line;
	char			buff[COB_SMALL_BUFF];

	/* Initialize the config table */
	if (check_nodef) {
		for (i = 0; i < CB_CONFIG_SIZE; i++) {
			config_table[i].val = NULL;
		}
	}

	if (prefix_dir) {
		snprintf (buff, (size_t)COB_SMALL_MAX,
			  "%s%s%s", cob_config_dir, SLASH_STR, fname);
		name = buff;
	} else {
		name = fname;
	}
	/* Open the config file */
	fp = fopen (name, "r");
	if (fp == NULL) {
		fflush (stderr);
		fprintf (stderr, "%s: %s", name,
			 _("No such file or directory"));
		fflush (stderr);
		return -1;
	}

	/* Read the config file */
	ret = 0;
	line = 0;
	while (fgets (buff, COB_SMALL_BUFF, fp)) {
		line++;

		/* Skip comments */
		if (buff[0] == '#' || buff[0] == '\n') {
			continue;
		}

		/* Skip blank lines */
		for (x = (const unsigned char *)buff; *x; x++) {
			if (isgraph (*x)) {
				break;
			}
		}
		if (!*x) {
			continue;
		}

		/* Get tag */
		s = strpbrk (buff, " \t:=");
		if (!s) {
			fprintf (stderr, "%s:%d: ", fname, line);
			fputs (_("Invalid line"), stderr);
			putc ('\n', stderr);
			fflush (stderr);
			ret = -1;
			continue;
		}
		*s = 0;

		/* Find entry */
		for (i = 0; i < CB_CONFIG_SIZE; i++) {
			if (strcmp (buff, config_table[i].name) == 0) {
				break;
			}
		}
		if (i == CB_CONFIG_SIZE) {
			fprintf (stderr, "%s:%d: ", fname, line);
			fprintf (stderr, _("Unknown tag '%s'"), buff);
			putc ('\n', stderr);
			fflush (stderr);
			ret = -1;
			continue;
		}

		/* Get value */
		for (s++; *s && strchr (" \t:=", *s); s++) {
			;
		}
		e = s + strlen (s) - 1;
		for (; e >= s && strchr (" \t\r\n", *e); e--) {
			;
		}
		e[1] = 0;
		config_table[i].val = s;

		/* Set value */
		name = config_table[i].name;
		var = config_table[i].var;
		val = config_table[i].val;
		switch (config_table[i].type) {
		case CB_ANY:
			if (strcmp (name, "assign-clause") == 0) {
				if (strcmp (val, "cobol2002") == 0) {
					unsupported_value (fname, line, val);
					ret = -1;
				} else if (strcmp (val, "mf") == 0) {
					cb_assign_clause = CB_ASSIGN_MF;
				} else if (strcmp (val, "ibm") == 0) {
					cb_assign_clause = CB_ASSIGN_IBM;
				} else {
					invalid_value (fname, line, name);
					ret = -1;
				}
			} else if (strcmp (name, "binary-size") == 0) {
				if (strcmp (val, "2-4-8") == 0) {
					cb_binary_size = CB_BINARY_SIZE_2_4_8;
				} else if (strcmp (val, "1-2-4-8") == 0) {
					cb_binary_size = CB_BINARY_SIZE_1_2_4_8;
				} else if (strcmp (val, "1--8") == 0) {
					cb_binary_size = CB_BINARY_SIZE_1__8;
				} else {
					invalid_value (fname, line, name);
					ret = -1;
				}
			} else if (strcmp (name, "binary-byteorder") == 0) {
				if (strcmp (val, "native") == 0) {
					cb_binary_byteorder = CB_BYTEORDER_NATIVE;
				} else if (strcmp (val, "big-endian") == 0) {
					cb_binary_byteorder = CB_BYTEORDER_BIG_ENDIAN;
				} else {
					invalid_value (fname, line, name);
					ret = -1;
				}
			}
			break;
		case CB_INT:
			for (j = 0; val[j]; j++) {
				if (val[j] < '0' || val[j] > '9') {
					invalid_value (fname, line, name);
					ret = -1;
					break;
				}
			}
			*((int *)var) = atoi (val);
			break;
		case CB_STRING:
			val = read_string (val);

			if (strcmp (name, "include") == 0) {
				/* Include another conf file */
				saveret = ret;
				if (cb_load_conf (val, 0, 1) != 0) {
					fclose (fp);
					return -1;
				}
				ret = saveret;
			} else if (strcmp (name, "not-reserved") == 0) {
				size = strlen (val);
				noresptr = cobc_main_malloc (sizeof (struct noreserve) + size + 1U);
				noresptr->noresword = (char *)noresptr + sizeof (struct noreserve);
				memcpy (noresptr->noresword, val, size);
				noresptr->next = cobc_nores_base;
				cobc_nores_base = noresptr;
			} else {
				*((const char **)var) = val;
			}
			break;
		case CB_BOOLEAN:
			if (strcmp (val, "yes") == 0) {
				*((int *)var) = 1;
			} else if (strcmp (val, "no") == 0) {
				*((int *)var) = 0;
			} else {
				invalid_value (fname, line, name);
				ret = -1;
			}
			break;
		case CB_SUPPORT:
			if (strcmp (val, "ok") == 0) {
				*((enum cb_support *)var) = CB_OK;
			} else if (strcmp (val, "warning") == 0) {
				*((enum cb_support *)var) = CB_WARNING;
			} else if (strcmp (val, "archaic") == 0) {
				*((enum cb_support *)var) = CB_ARCHAIC;
			} else if (strcmp (val, "obsolete") == 0) {
				*((enum cb_support *)var) = CB_OBSOLETE;
			} else if (strcmp (val, "skip") == 0) {
				*((enum cb_support *)var) = CB_SKIP;
			} else if (strcmp (val, "ignore") == 0) {
				*((enum cb_support *)var) = CB_IGNORE;
			} else if (strcmp (val, "error") == 0) {
				*((enum cb_support *)var) = CB_ERROR;
			} else if (strcmp (val, "unconformable") == 0) {
				*((enum cb_support *)var) = CB_UNCONFORMABLE;
			} else {
				invalid_value (fname, line, name);
				ret = -1;
			}
			break;
		default:
			fprintf (stderr, "%s:%d: ", fname, line);
			fprintf (stderr, _("Invalid type for '%s'"), name);
			putc ('\n', stderr);
			fflush (stderr);
			ret = -1;
			break;
		}
	}
	fclose (fp);

	/* Checks for no definition */
	if (check_nodef) {
		for (i = 2U; i < CB_CONFIG_SIZE; i++) {
			if (config_table[i].val == NULL) {
				fprintf (stderr, _("%s: No definition of '%s'"),
					 fname, config_table[i].name);
				putc ('\n', stderr);
				fflush (stderr);
				ret = -1;
			}
		}
	}

	return ret;
}
