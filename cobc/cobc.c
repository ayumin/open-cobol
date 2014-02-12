/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2006-2012 Roger While

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
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef	HAVE_SIGNAL_H
#include <signal.h>
#endif

#ifdef	_WIN32
#define	WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

#include "tarstamp.h"

#include "cobc.h"
#include "tree.h"

#include "lib/cobgetopt.h"

struct strcache {
	struct strcache	*next;
	void		*val;
};

/* Compile level */
#define	CB_LEVEL_PREPROCESS	1
#define	CB_LEVEL_TRANSLATE	2
#define	CB_LEVEL_COMPILE	3
#define	CB_LEVEL_ASSEMBLE	4
#define	CB_LEVEL_MODULE		5
#define	CB_LEVEL_LIBRARY	6
#define	CB_LEVEL_EXECUTABLE	7

/* Info display limits */
#define	CB_IMSG_SIZE		24
#define	CB_IVAL_SIZE		(74 - CB_IMSG_SIZE - 4)

#define	COBC_ADD_STR(v,x,y,z)	cobc_add_str (&v, &v##_size, x, y, z);
#define	COBC_INV_PAR		_("Invalid %s parameter")

/* C version info */
#ifdef	__VERSION__
#define OC_C_VERSION_PRF	""
#define OC_C_VERSION	CB_XSTRINGIFY(__VERSION__)
#elif	defined(__xlc__)
#define OC_C_VERSION_PRF	"(IBM) "
#define OC_C_VERSION	CB_XSTRINGIFY(__xlc__)
#elif	defined(_MSC_VER)
#define OC_C_VERSION_PRF	"(Microsoft) "
#define OC_C_VERSION	CB_XSTRINGIFY(_MSC_VER)
#elif	defined(__BORLANDC__)
#define OC_C_VERSION_PRF	"(Borland) "
#define OC_C_VERSION	CB_XSTRINGIFY(__BORLANDC__)
#elif	defined(__WATCOMC__)
#define OC_C_VERSION_PRF	"(Watcom) "
#define OC_C_VERSION	CB_XSTRINGIFY(__WATCOMC__)
#elif	defined(__INTEL_COMPILER)
#define OC_C_VERSION_PRF	"(Intel) "
#define OC_C_VERSION	CB_XSTRINGIFY(__INTEL_COMPILER)
#else
#define OC_C_VERSION_PRF	""
#define OC_C_VERSION	"unknown"
#endif

#if	defined(_MSC_VER) || defined(__WATCOMC__) || defined(__BORLANDC__)
#define PATHSEPS ";"
#else
#define PATHSEPS ":"
#endif

#define	CB_TEXT_LIST_ADD(y,z)	y = cb_text_list_add (y, z)
#define	CB_TEXT_LIST_CHK(y,z)	y = cb_text_list_chk (y, z)

#ifdef	_MSC_VER
#define	CB_COPT_1	" /O1"
#define	CB_COPT_2	" /O2"
#define	CB_COPT_S	" /Os"
#elif   defined(__BORLANDC__)
#define	CB_COPT_1	" -O"
#define	CB_COPT_2	" -O2"
#define	CB_COPT_S	" -O1"
#elif defined(__hpux) && !defined(__GNUC__)
#define	CB_COPT_1	" -O"
#define	CB_COPT_2	" +O2"
#define	CB_COPT_S	" +O2 +Osize"
#elif   defined(__WATCOMC__)
#define	CB_COPT_1	" -ot"
#define	CB_COPT_2	" -ox"
#define	CB_COPT_S	" -os"
#elif   defined(__SUNPRO_C)
#define	CB_COPT_1	" -xO1"
#define	CB_COPT_2	" -xO2"
#define	CB_COPT_S	" -xO1 -xspace"
#elif	defined(__xlc__)
#define	CB_COPT_1	" -O"
#define	CB_COPT_2	" -O2"
#define	CB_COPT_S	" -O"
#else
#define	CB_COPT_1	" -O"
#define	CB_COPT_2	" -O2"
#define	CB_COPT_S	" -Os"
#endif

/* Global variables */

const char		*cb_source_file = NULL;
char			*cb_oc_build_stamp = NULL;
const char		*demangle_name = NULL;
const char		*cb_storage_file_name = NULL;
struct cb_text_list	*cb_include_list = NULL;
struct cb_text_list	*cb_intrinsic_list = NULL;
struct cb_text_list	*cb_extension_list = NULL;
struct cb_text_list	*cb_static_call_list = NULL;
struct cb_text_list	*cb_early_exit_list = NULL;
char			**cb_saveargv = NULL;
const char		*cob_config_dir = NULL;
FILE			*cb_storage_file = NULL;
FILE			*cb_listing_file = NULL;
#if	0	/* RXWRXW - source format */
char			*source_name = NULL;
#endif

struct noreserve	*cobc_nores_base = NULL;

int			cb_source_format = CB_FORMAT_FIXED;	/* Default format */
int			cb_id = 0;
int			cb_attr_id = 0;
int			cb_literal_id = 0;
int			cb_field_id = 0;
int			cobc_flag_main = 0;
int			cb_flag_main = 0;
int			cobc_wants_debug = 0;
int			cb_flag_functions_all = 0;

int			errorcount = 0;
int			warningcount = 0;
int			exit_option = 0;
int			warningopt = 0;
int			no_physical_cancel = 0;
int			cb_source_line = 0;
int			cb_saveargc = 0;
unsigned int		cobc_gen_listing = 0;

cob_u32_t		optimize_defs[COB_OPTIM_MAX] = { 0 };

#undef	COB_EXCEPTION
#define	COB_EXCEPTION(code,tag,name,critical) {name, 0x##code, 0},
struct cb_exception cb_exception_table[] = {
	{NULL, 0, 0},		/* CB_EC_ZERO */
#include "libcob/exception.def"
	{NULL, 0, 0}		/* CB_EC_MAX */
};
#undef	COB_EXCEPTION

#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ
#define	CB_FLAG(var,pdok,name,doc)	int var = 0;
#define	CB_FLAG_RQ(var,pdok,name,def,opt,doc)	int var = def;
#define	CB_FLAG_NQ(pdok,name,opt,doc)
#include "flag.def"
#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ

#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)	int var = 0;
#define	CB_NOWARNDEF(var,name,doc)	int var = 0;
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF

/* Local variables */

#if	defined(HAVE_SIGNAL_H) && defined(HAVE_SIG_ATOMIC_T)
static volatile sig_atomic_t	sig_is_handled = 0;
#endif

static struct cb_define_struct	*cb_define_list = NULL;

static struct cobc_mem_struct	*cobc_mainmem_base = NULL;
static struct cobc_mem_struct	*cobc_parsemem_base = NULL;
static struct cobc_mem_struct	*cobc_plexmem_base = NULL;

static const char	*cobc_cc;		/* C compiler */
static char		*cobc_cflags;		/* C compiler flags */
static char		*cobc_libs;		/* -l... */
static char		*cobc_lib_paths;	/* -L... */
static char		*cobc_include;		/* -I... */
static char		*cobc_ldflags;		/* -Q / COB_LDFLAGS */
static const char	*cobc_tmpdir;		/* temporary directory */

static size_t		cobc_cflags_size;
static size_t		cobc_libs_size;
static size_t		cobc_lib_paths_size;
static size_t		cobc_include_size;
static size_t		cobc_ldflags_size;

static size_t		cobc_cc_len;
static size_t		cobc_cflags_len;
static size_t		cobc_libs_len;
static size_t		cobc_lib_paths_len;
static size_t		cobc_include_len;
static size_t		cobc_ldflags_len;
static size_t		cobc_export_dyn_len;
static size_t		cobc_shared_opt_len;
static size_t		cobc_pic_flags_len;

static char		*save_temps_dir;
static struct strcache	*base_string;

static char		*cobc_list_dir;
static char		*cobc_list_file;

static char		*output_name;
static char		*cobc_buffer;
static char		*cobc_objects_buffer;
static char		*output_name_buff;
static char		*basename_buffer;

static size_t		cobc_objects_len;
static size_t		basename_len;
static size_t		cobc_buffer_size;

static struct filename	*file_list;

static unsigned int	cb_compile_level = 0;

static int		iargs;

static size_t		wants_nonfinal = 0;
static size_t		cobc_flag_module = 0;
static size_t		cobc_flag_library = 0;
static size_t		save_temps = 0;
static size_t		save_all_src = 0;
static size_t		save_c_src = 0;
static size_t		verbose_output = 0;
static size_t		cob_iteration = 0;
static size_t		cob_optimize = 0;
#ifndef _WIN32
static pid_t		cob_process_id = 0;
#endif

#ifdef	_MSC_VER
#if	_MSC_VER >= 1400
static const char	*manicmd;
#endif
static const char	*manilink;
static size_t		manilink_len;
#endif

static size_t		strip_output = 0;
static size_t		gflag_set = 0;
static size_t		aflag_set = 0;

static const char	*const cob_csyns[] = {
#ifndef	COB_EBCDIC_MACHINE
	"NULL",
	"P_cancel",
	"P_initialize",
	"P_ret_initialize",
	"P_switch",
#endif
#ifdef	COB_EBCDIC_MACHINE
	"_float128",
#endif
	"_Bool",
	"_Complex",
	"_Imaginary",
#ifndef	COB_EBCDIC_MACHINE
	"_float128",
#endif
	"alignof",
	"asm",
	"auto",
	"bool",
	"break",
	"case",
	"catch",
	"char",
	"class",
	"const",
	"const_cast",
	"continue",
	"default",
	"delete",
	"do",
	"double",
	"dynamic_cast",
	"else",
	"enum",
	"exit_program",
	"explicit",
	"extern",
	"false",
	"float",
	"for",
	"frame_pointer",
	"frame_stack",
	"friend",
	"goto",
	"if",
	"inline",
	"int",
	"long",
	"mutable",
	"namespace",
	"new",
	"offsetof",
	"operator",
	"private",
	"protected",
	"public",
	"register",
	"reinterpret_cast",
	"restrict",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"static_cast",
	"struct",
	"switch",
	"template",
	"this",
	"throw",
	"true",
	"try",
	"typedef",
	"typeid",
	"typename",
	"typeof",
	"union",
	"unsigned",
	"using",
	"virtual",
	"void",
	"volatile",
#ifndef	COB_EBCDIC_MACHINE
	"wchar_t"
#else
	"wchar_t",
	"NULL",
	"P_cancel",
	"P_initialize",
	"P_ret_initialize",
	"P_switch"
#endif
};

#define COB_NUM_CSYNS	sizeof(cob_csyns) / sizeof(char *)

static const char short_options[] = "hVivECScbmxOPgwo:I:L:l:D:K:k:";

#define	CB_NO_ARG	no_argument
#define	CB_RQ_ARG	required_argument
#define	CB_OP_ARG	optional_argument

static const struct option long_options[] = {
	{"help",		CB_NO_ARG, NULL, 'h'},
	{"version",		CB_NO_ARG, NULL, 'V'},
#if	1	/* getopt_long_only has a problem with eg. -xv - remove */
	{"verbose",		CB_NO_ARG, NULL, 'v'},
#endif
	{"info",		CB_NO_ARG, NULL, 'i'},
	{"list-reserved",	CB_NO_ARG, NULL, '5'},
	{"list-intrinsics",	CB_NO_ARG, NULL, '6'},
	{"list-mnemonics",	CB_NO_ARG, NULL, '7'},
	{"list-system",		CB_NO_ARG, NULL, '8'},
	{"O2",			CB_NO_ARG, NULL, '9'},
	{"Os",			CB_NO_ARG, NULL, 's'},
	{"save-temps",		CB_OP_ARG, NULL, '_'},
	{"std",			CB_RQ_ARG, NULL, '$'},
	{"conf",		CB_RQ_ARG, NULL, '&'},
	{"debug",		CB_NO_ARG, NULL, 'd'},
	{"ext",			CB_RQ_ARG, NULL, 'e'},
	{"free",		CB_NO_ARG, &cb_source_format, CB_FORMAT_FREE},
	{"fixed",		CB_NO_ARG, &cb_source_format, CB_FORMAT_FIXED},
	{"static",		CB_NO_ARG, &cb_flag_static_call, 1},
	{"dynamic",		CB_NO_ARG, &cb_flag_static_call, 0},
	{"Q",			CB_RQ_ARG, NULL, 'Q'},
	{"A",			CB_RQ_ARG, NULL, 'A'},
	{"P",			CB_OP_ARG, NULL, 'P'},
	{"Xref",		CB_NO_ARG, NULL, 'X'},
	{"Wall",		CB_NO_ARG, NULL, 'W'},
	{"W",			CB_NO_ARG, NULL, 'Z'},

#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ
#define	CB_FLAG(var,pdok,name,doc)			\
	{"f"name,		CB_NO_ARG, &var, 1},	\
	{"fno-"name,		CB_NO_ARG, &var, 0},
#define	CB_FLAG_RQ(var,pdok,name,def,opt,doc)		\
	{"f"name,		CB_RQ_ARG, NULL, opt},
#define	CB_FLAG_NQ(pdok,name,opt,doc)			\
	{"f"name,		CB_RQ_ARG, NULL, opt},
#include "flag.def"
#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ

#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)			\
	{"W"name,		CB_NO_ARG, &var, 1},	\
	{"Wno-"name,		CB_NO_ARG, &var, 0},
#define	CB_NOWARNDEF(var,name,doc)			\
	{"W"name,		CB_NO_ARG, &var, 1},	\
	{"Wno-"name,		CB_NO_ARG, &var, 0},
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF

	{NULL,			0, NULL, 0}
};

#undef	CB_ARG_NO
#undef	CB_ARG_RQ
#undef	CB_ARG_NQ
#undef	CB_ARG_OP

/* Prototype */
static void COB_A_NORETURN	cobc_abort_terminate (void);

/* cobc functions */

static void
cobc_free_mem (void)
{
	struct cobc_mem_struct	*reps;
	struct cobc_mem_struct	*repsl;

	if (save_temps_dir) {
		free (save_temps_dir);
		save_temps_dir = NULL;
	}
	if (cobc_list_dir) {
		free (cobc_list_dir);
		cobc_list_dir = NULL;
	}
	if (cobc_list_file) {
		free (cobc_list_file);
		cobc_list_file = NULL;
	}
	for (reps = cobc_plexmem_base; reps; ) {
		repsl = reps;
		reps = reps->next;
		free (repsl);
	}
	cobc_plexmem_base = NULL;
	for (reps = cobc_parsemem_base; reps; ) {
		repsl = reps;
		reps = reps->next;
		free (repsl);
	}
	cobc_parsemem_base = NULL;
	for (reps = cobc_mainmem_base; reps; ) {
		repsl = reps;
		reps = reps->next;
		free (repsl);
	}
	cobc_mainmem_base = NULL;
}

static const char *
cobc_enum_explain (const enum cb_tag tag)
{
	switch (tag) {
	case CB_TAG_CONST:
		return "CONSTANT";
	case CB_TAG_INTEGER:
		return "INTEGER";
	case CB_TAG_STRING:
		return "STRING";
	case CB_TAG_ALPHABET_NAME:
		return "ALPHABET";
	case CB_TAG_CLASS_NAME:
		return "CLASS";
	case CB_TAG_LOCALE_NAME:
		return "LOCALE";
	case CB_TAG_SYSTEM_NAME:
		return "SYSTEM";
	case CB_TAG_LITERAL:
		return "LITERAL";
	case CB_TAG_DECIMAL:
		return "DECIMAL";
	case CB_TAG_FIELD:
		return "FIELD";
	case CB_TAG_FILE:
		return "FILE";
	case CB_TAG_REPORT:
		return "REPORT";
	case CB_TAG_REFERENCE:
		return "REFERENCE";
	case CB_TAG_BINARY_OP:
		return "BINARY OP";
	case CB_TAG_FUNCALL:
		return "FUNCTION CALL";
	case CB_TAG_CAST:
		return "CAST";
	case CB_TAG_INTRINSIC:
		return "INTRINSIC";
	case CB_TAG_LABEL:
		return "LABEL";
	case CB_TAG_ASSIGN:
		return "ASSIGN";
	case CB_TAG_INITIALIZE:
		return "INITIALIZE";
	case CB_TAG_SEARCH:
		return "SEARCH";
	case CB_TAG_CALL:
		return "CALL";
	case CB_TAG_GOTO:
		return "GO TO";
	case CB_TAG_IF:
		return "IF";
	case CB_TAG_PERFORM:
		return "PERFORM";
	case CB_TAG_STATEMENT:
		return "STATEMENT";
	case CB_TAG_CONTINUE:
		return "CONTINUE";
	case CB_TAG_CANCEL:
		return "CANCEL";
	case CB_TAG_ALTER:
		return "ALTER";
	case CB_TAG_SET_ATTR:
		return "SET ATTRIBUTE";
	case CB_TAG_PERFORM_VARYING:
		return "PERFORM";
	case CB_TAG_PICTURE:
		return "PICTURE";
	case CB_TAG_LIST:
		return "LIST";
	case CB_TAG_DIRECT:
		return "DIRECT";
	case CB_TAG_DEBUG:
		return "DEBUG";
	case CB_TAG_DEBUG_CALL:
		return "DEBUG CALL";
	default:
		break;
	}
	return "UNKNOWN";
}

/* Global functions */

void
cobc_abort_pr (const char *fmt, ...)
{
	va_list		ap;

	va_start (ap, fmt);
	vfprintf (stderr, fmt, ap);
	va_end (ap);
	putc ('\n', stderr);
	fflush (stderr);
}

void
cobc_too_many_errors (void)
{
	cobc_abort_pr (_("Too many errors - Aborting compilation"));
	cobc_abort_terminate ();
}

void
cobc_abort (const char *filename, const int linenum)
{
	cobc_abort_pr (_("%s:%d Internal compiler error"), filename, linenum);
	cobc_abort_terminate ();
}

void
cobc_dumb_abort (const char *filename, const int linenum)
{
	cobc_abort (filename, linenum);
}

void
cobc_tree_cast_error (const cb_tree x, const char *filename, const int linenum,
		      const enum cb_tag tagnum)
{
	cobc_abort_pr (_("%s:%d Invalid cast from '%s' type %s to type %s"),
		filename, linenum,
		x ? cb_name (x) : "NULL", 
		x ? cobc_enum_explain (CB_TREE_TAG(x)) : "None",
		cobc_enum_explain (tagnum));
	cobc_abort_terminate ();
}

#if	!defined(__GNUC__) && defined(COB_TREE_DEBUG)
cb_tree
cobc_tree_cast_check (const cb_tree x, const char *file,
		      const int line, const enum cb_tag tag)
{
	if (!x || x == cb_error_node || CB_TREE_TAG (x) != tag) {
		cobc_tree_cast_error (x, file, line, tag);
	}
	return x;
}
#endif

void *
cobc_malloc (const size_t size)
{
	void	*mptr;

	mptr = calloc ((size_t)1, size);
	if (unlikely(!mptr)) {
		cobc_abort_pr (_("Cannot allocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	return mptr;
}

void *
cobc_strdup (const char *dupstr)
{
	void	*p;
	size_t	n;

#ifdef	COB_TREE_DEBUG
	if (unlikely(!dupstr)) {
		cobc_abort_pr (_("Call to cobc_strdup with NULL pointer"));
		cobc_abort_terminate ();
	}
#endif
	n = strlen (dupstr);
	p = cobc_malloc (n + 1);
	memcpy (p, dupstr, n);
	return p;
}

void *
cobc_realloc (void *prevptr, const size_t size)
{
	void	*mptr;

	mptr = realloc (prevptr, size);
	if (unlikely(!mptr)) {
		cobc_abort_pr (_("Cannot reallocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	return mptr;
}

/* Memory allocate/strdup/reallocate/free for complete execution */
void *
cobc_main_malloc (const size_t size)
{
	struct cobc_mem_struct	*m;

	m = calloc ((size_t)1, sizeof(struct cobc_mem_struct) + size);
	if (unlikely(!m)) {
		cobc_abort_pr (_("Cannot allocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	m->next = cobc_mainmem_base;
	m->memptr = (char *)m + sizeof(struct cobc_mem_struct);
	m->memlen = size;
	cobc_mainmem_base = m;
	return m->memptr;
}

void *
cobc_main_strdup (const char *dupstr)
{
	void	*p;
	size_t	n;

#ifdef	COB_TREE_DEBUG
	if (unlikely(!dupstr)) {
		cobc_abort_pr (_("Call to cobc_main_strdup with NULL pointer"));
		cobc_abort_terminate ();
	}
#endif
	n = strlen (dupstr);
	p = cobc_main_malloc (n + 1);
	memcpy (p, dupstr, n);
	return p;
}

void *
cobc_main_realloc (void *prevptr, const size_t size)
{
	struct cobc_mem_struct	*m;
	struct cobc_mem_struct	*curr;
	struct cobc_mem_struct	*prev;

	m = calloc ((size_t)1, sizeof(struct cobc_mem_struct) + size);
	if (unlikely(!m)) {
		cobc_abort_pr (_("Cannot allocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	m->memptr = (char *)m + sizeof(struct cobc_mem_struct);
	m->memlen = size;

	prev = NULL;
	for (curr = cobc_mainmem_base; curr; curr = curr->next) {
		if (curr->memptr == prevptr) {
			break;
		}
		prev = curr;
	}
	if (unlikely(!curr)) {
		cobc_abort_pr (_("Attempt to reallocate non-allocated memory - Aborting"));
		cobc_abort_terminate ();
	}
	m->next = curr->next;
	if (prev) {
		prev->next = m;
	} else {
		/* At mainmem_base */
		cobc_mainmem_base = m;
	}
	memcpy (m->memptr, curr->memptr, curr->memlen);
	free (curr);
	
	return m->memptr;
}

void
cobc_main_free (void *prevptr)
{
	struct cobc_mem_struct	*curr;
	struct cobc_mem_struct	*prev;

	prev = NULL;
	for (curr = cobc_mainmem_base; curr; curr = curr->next) {
		if (curr->memptr == prevptr) {
			break;
		}
		prev = curr;
	}
	if (!curr) {
		return;
	}
	if (prev) {
		prev->next = curr->next;
	} else {
		/* At mainmem_base */
		cobc_mainmem_base = curr->next;
	}
	free (curr);
}

/* Memory allocate/strdup/reallocate/free for parser */
void *
cobc_parse_malloc (const size_t size)
{
	struct cobc_mem_struct	*m;

	m = calloc ((size_t)1, sizeof(struct cobc_mem_struct) + size);
	if (unlikely(!m)) {
		cobc_abort_pr (_("Cannot allocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	m->next = cobc_parsemem_base;
	m->memptr = (char *)m + sizeof(struct cobc_mem_struct);
	m->memlen = size;
	cobc_parsemem_base = m;
	return m->memptr;
}

void *
cobc_parse_strdup (const char *dupstr)
{
	void	*p;
	size_t	n;

#ifdef	COB_TREE_DEBUG
	if (unlikely(!dupstr)) {
		cobc_abort_pr (_("Call to cobc_parse_strdup with NULL pointer"));
		cobc_abort_terminate ();
	}
#endif
	n = strlen (dupstr);
	p = cobc_parse_malloc (n + 1);
	memcpy (p, dupstr, n);
	return p;
}

void *
cobc_parse_realloc (void *prevptr, const size_t size)
{
	struct cobc_mem_struct	*m;
	struct cobc_mem_struct	*curr;
	struct cobc_mem_struct	*prev;

	m = calloc ((size_t)1, sizeof(struct cobc_mem_struct) + size);
	if (unlikely(!m)) {
		cobc_abort_pr (_("Cannot allocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	m->memptr = (char *)m + sizeof(struct cobc_mem_struct);
	m->memlen = size;

	prev = NULL;
	for (curr = cobc_parsemem_base; curr; curr = curr->next) {
		if (curr->memptr == prevptr) {
			break;
		}
		prev = curr;
	}
	if (unlikely(!curr)) {
		cobc_abort_pr (_("Attempt to reallocate non-allocated memory - Aborting"));
		cobc_abort_terminate ();
	}
	m->next = curr->next;
	if (prev) {
		prev->next = m;
	} else {
		/* At parsemem_base */
		cobc_parsemem_base = m;
	}
	memcpy (m->memptr, curr->memptr, curr->memlen);
	free (curr);
	
	return m->memptr;
}

void
cobc_parse_free (void *prevptr)
{
	struct cobc_mem_struct	*curr;
	struct cobc_mem_struct	*prev;

	prev = NULL;
	for (curr = cobc_parsemem_base; curr; curr = curr->next) {
		if (curr->memptr == prevptr) {
			break;
		}
		prev = curr;
	}
	if (!curr) {
		return;
	}
	if (prev) {
		prev->next = curr->next;
	} else {
		/* At parsemem_base */
		cobc_parsemem_base = curr->next;
	}
	free (curr);
}

/* Memory allocate/strdup/reallocate/free for preprocessor */
void *
cobc_plex_malloc (const size_t size)
{
	struct cobc_mem_struct	*m;

	m = calloc ((size_t)1, sizeof(struct cobc_mem_struct) + size);
	if (unlikely(!m)) {
		cobc_abort_pr (_("Cannot allocate %d bytes of memory - Aborting"),
				(int)size);
		cobc_abort_terminate ();
	}
	m->memptr = (char *)m + sizeof(struct cobc_mem_struct);
	m->next = cobc_plexmem_base;
	cobc_plexmem_base = m;
	return m->memptr;
}

void *
cobc_plex_strdup (const char *dupstr)
{
	void	*p;
	size_t	n;

#ifdef	COB_TREE_DEBUG
	if (unlikely(!dupstr)) {
		cobc_abort_pr (_("Call to cobc_plex_strdup with NULL pointer"));
		cobc_abort_terminate ();
	}
#endif
	n = strlen (dupstr);
	p = cobc_plex_malloc (n + 1);
	memcpy (p, dupstr, n);
	return p;
}

void *
cobc_check_string (const char *dupstr)
{
	struct strcache	*s;

#ifdef	COB_TREE_DEBUG
	if (unlikely(!dupstr)) {
		cobc_abort_pr (_("Call to cobc_check_string with NULL pointer"));
		cobc_abort_terminate ();
	}
#endif
	for (s = base_string; s; s = s->next) {
		if (!strcmp (dupstr, (const char *)s->val)) {
			return s->val;
		}
	}
	s = cobc_main_malloc (sizeof(struct strcache));
	s->next = base_string;
	s->val = cobc_main_strdup (dupstr);
	base_string = s;
	return s->val;
}

static struct cb_text_list *
cb_text_list_add (struct cb_text_list *list, const char *text)
{
	struct cb_text_list	*p;

	p = cobc_main_malloc (sizeof (struct cb_text_list));
	p->text = cobc_main_strdup (text);
	if (!list) {
		p->last = p;
		return p;
	}
	list->last->next = p;
	list->last = p;
	return list;
}

static struct cb_text_list *
cb_text_list_chk (struct cb_text_list *list, const char *text)
{
	struct cb_text_list	*p;

	for (p = list; p; p = p->next) {
		if (!strcmp (text, p->text)) {
			return list;
		}
	}
	return cb_text_list_add (list, text);
}

static unsigned int
cobc_set_value (struct cb_define_struct *p, const char *value)
{
	const char	*s;
	size_t		size;
	unsigned int	dot_seen;
	unsigned int	sign_seen;

	if (!value) {
		p->deftype = PLEX_DEF_NONE;
		p->value = NULL;
		p->sign = 0;
		p->int_part = 0;
		p->dec_part = 0;
		return 0;
	}

	/* Quoted value */
	if (*value == '"' || *value == '\'') {
		size = strlen (value) - 1U;
		if (value[0] != value[size]) {
			p->value = NULL;
			p->deftype = PLEX_DEF_NONE;
			return 1;
		}
		p->value = cobc_main_strdup (value);

		p->deftype = PLEX_DEF_LIT;
		p->sign = 0;
		p->int_part = 0;
		p->dec_part = 0;
		return 0;
	}

	/* Non-quoted value - Check if possible numeric */
	dot_seen = 0;
	sign_seen = 0;
	size = 0;
	s = value;
	if (*s == '+' || *s == '-') {
		sign_seen = 1;
		size++;
		s++;
	}
	for (; *s; ++s) {
		if (*s == '.') {
			if (dot_seen) {
				break;
			}
			dot_seen = 1;
			size++;
			continue;
		}
		if (*s > '9' || *s < '0') {
			break;
		}
		size++;
	}

	if (*s || size <= (dot_seen + sign_seen)) {
		/* Not numeric */
#if	0	/* RXWRXW - Lit warn */
		cobc_abort_pr (_("Warning - Assuming literal for unquoted '%s'"),
				value);
#endif
		size = strlen (value);
		p->value = cobc_main_malloc (size + 4U);
		sprintf (p->value, "'%s'", value);
		p->deftype = PLEX_DEF_LIT;
		p->sign = 0;
		p->int_part = 0;
		p->dec_part = 0;
		return 0;
	}

	p->value = cobc_main_strdup (value);
	p->deftype = PLEX_DEF_NUM;
	p->sign = 0;
	p->int_part = 0;
	p->dec_part = 0;
	return 0;
}

static int
cobc_bcompare (const void *p1, const void *p2)
{
	const void	**tptr;

	tptr = (const void **)p2;
	return strcmp (p1, *tptr);
}

static void
cobc_error_name (const char *name, const unsigned int source,
		 const unsigned int reason)
{
	const char	*s;

	s = "";
	switch (reason) {
	case 1:
		s = _(" - Length is < 1 or > 31");
		break;
	case 2:
		s = _(" - Name cannot begin with space or underscore");
		break;
	case 3:
		s = _(" - Name cannot begin with 'cob_' or 'COB_'");
		break;
	case 4:
		s = _(" - Name duplicates a 'C' keyword");
		break;
	case 5:
		s = _(" - Name cannot contain a directory separator");
		break;
	default:
		break;
	}
	switch (source) {
	case 0:
		/* basename */
		cobc_abort_pr (_("Invalid file base name '%s'%s"),
				name, s);
		break;
	case 1:
		/* ENTRY */
		cb_error (_("Invalid ENTRY '%s'%s"), name, s);
		break;
	case 2:
		/* PROGRAM-ID */
		cb_error (_("Invalid PROGRAM-ID '%s'%s"), name, s);
		break;
	default:
		cobc_abort_pr (_("Unknown name error '%s'%s"),
				name, s);
		break;
	}
}

size_t
cobc_check_valid_name (const char *name, const unsigned int prechk)
{
	const char	*p;
	size_t		len;

	for (p = name, len = 0; *p; p++, len++) {
		if (*p == '/' || *p == '\\') {
			cobc_error_name (name, prechk, 5U);
			return 1;
		}
	}
	if (len < 1) {
		cobc_error_name (name, prechk, 1U);
		return 1;
	}
	if (!cb_relaxed_syntax_check && len > 31) {
		cobc_error_name (name, prechk, 1U);
		return 1;
	}
	if (*name == '_' || *name == ' ') {
		cobc_error_name (name, prechk, 2U);
		return 1;
	}
	if (prechk && len > 3 &&
	    (!memcmp (name, "cob_", (size_t)4) ||
	     !memcmp (name, "COB_", (size_t)4))) {
		cobc_error_name (name, prechk, 3U);
		return 1;
	}
	if (bsearch (name, cob_csyns, COB_NUM_CSYNS,
		     sizeof (char *), cobc_bcompare)) {
		cobc_error_name (name, prechk, 4U);
		return 1;
	}
	return 0;
}

/* Local functions */

static void
cobc_chk_buff_size (const size_t bufflen)
{
	if (bufflen >= cobc_buffer_size) {
		cobc_buffer_size = bufflen + 32;
		cobc_buffer = cobc_main_realloc (cobc_buffer, cobc_buffer_size);
	}
}

static int
cobc_deciph_optarg (const char *p, const int allow_quote)
{
	const unsigned char	*s;
	size_t			len;
	size_t			i;
	int			n;

	len = strlen (p);
	if (!len) {
		return -1;
	}
	s = (const unsigned char *)p;
	if (allow_quote) {
		if (*s == '"' || *s == '\'') {
			if (len != 3 || *(s + 2) != *s) {
				return -1;
			}
			return (int)(*(s + 1));
		}
		if (*s < '0' || *s > '9') {
			if (len != 1) {
				return -1;
			}
			return (int)*s;
		}
	}
	n = 0;
	for (i = 0; i < len; ++i) {
		if (s[i] < '0' || s[i] > '9') {
			return -1;
		}
		n *= 10;
		n += (s[i] & 0x0F);
	}
	return n;
}

static void COB_A_NORETURN
cobc_err_exit (const char *fmt, ...)
{
	va_list		ap;

	fputs ("cobc: ", stderr);
	fputs (_("Error: "), stderr);
	va_start (ap, fmt);
	vfprintf (stderr, fmt, ap);
	va_end (ap);
	putc ('\n', stderr);
	fflush (stderr);
	cobc_free_mem ();
	exit (1);
}

static struct cb_define_struct *
cb_define_list_add (struct cb_define_struct *list, const char *text)
{
	struct cb_define_struct	*p;
	struct cb_define_struct	*l;
	char			*s;
	char			*x;

	x = cobc_strdup (text);
	s = strtok (x, "=");

	/* Check duplicate */
	for (l = list; l; l = l->next) {
		if (!strcasecmp (s, l->name)) {
			cobc_abort_pr (_("Duplicate define '%s' - Ignoring"), s);
			free (x);
			return list;
		}
	}

	p = cobc_main_malloc (sizeof (struct cb_define_struct));
	p->next = NULL;
	p->name = cobc_check_string (s);
	p->deftype = PLEX_DEF_NONE;
	s = strtok (NULL, "");
	if (cobc_set_value (p, s)) {
		free (x);
		return NULL;
	}

	free (x);

	if (!list) {
		p->last = p;
		return p;
	}
	list->last->next = p;
	list->last = p;
	return list;
}

static char *
cobc_stradd_dup (const char *str1, const char *str2)
{
	char	*p;
	size_t	m;
	size_t	n;

#ifdef	COB_TREE_DEBUG
	if (unlikely(!str1 || !str2)) {
		cobc_abort_pr (_("Call to cobc_stradd_dup with NULL pointer"));
		cobc_abort_terminate ();
	}
#endif
	m = strlen (str1);
	n = strlen (str2);
	p = cobc_main_malloc (m + n + 1);
	memcpy (p, str1, m);
	memcpy (p + m, str2, n);
	return p;
}

static char *
cobc_getenv (const char *env)
{
	char	*p;

	p = getenv (env);
	if (!p || *p == 0 || *p == ' ') {
		return NULL;
	}
	return cobc_main_strdup (p);
}

static void
cobc_add_str (char **var, size_t *cursize, const char *s1, const char *s2,
	      const char *s3)
{
	size_t	calcsize;

	if (!s1) {
		return;
	}

	calcsize = strlen (*var);
	calcsize += strlen (s1);
	if (s2) {
		calcsize += strlen (s2);
	}
	if (s3) {
		calcsize += strlen (s3);
	}
	if (calcsize >= 131072) {
		/* Arbitrary limit */
		cobc_err_exit (_("Parameter buffer size exceeded"));
	}
	if (calcsize >= *cursize) {
		while (*cursize <= calcsize) {
			*cursize *= 2;
		}
		*var = cobc_main_realloc (*var, *cursize);
	}
	strcat (*var, s1);
	if (s2) {
		strcat (*var, s2);
	}
	if (s3) {
		strcat (*var, s3);
	}
}

static void
cobc_check_action (const char *name)
{
	if (!name || access (name, F_OK)) {
		return;
	}
	if (!save_temps) {
		(void)unlink (name);
		return;
	}
	if (save_temps_dir) {
		char	temp_buff[COB_MEDIUM_BUFF];

		snprintf (temp_buff, (size_t)COB_MEDIUM_MAX,
			  "%s/%s", save_temps_dir, name);
		/* Remove possible target file - ignore return */
		(void)unlink (temp_buff);
		if (rename (name, temp_buff)) {
			cobc_abort_pr (_("Warning - Could not move temporary file to %s"),
					temp_buff);
		}
	}
}

static void
cobc_clean_up (const int status)
{
	struct filename		*fn;
	struct local_filename	*lf;
	cob_u32_t		i;

	if (cb_listing_file) {
		fclose (cb_listing_file);
		cb_listing_file = NULL;
	}
	if (cb_storage_file) {
		fclose (cb_storage_file);
		cb_storage_file = NULL;
	}
	if (ppin) {
		fclose (ppin);
		ppin = NULL;
	}

	if (ppout) {
		fclose (ppout);
		ppout = NULL;
	}
	if (yyin) {
		fclose (yyin);
		yyin = NULL;
	}

	if (yyout) {
		fclose (yyout);
		yyout = NULL;
	}

	for (fn = file_list; fn; fn = fn->next) {
		for (lf = fn->localfile; lf; lf = lf->next) {
			if (unlikely(lf->local_fp)) {
				fclose (lf->local_fp);
				lf->local_fp = NULL;
			}
		}
		if (fn->need_assemble &&
		    (status || cb_compile_level > CB_LEVEL_ASSEMBLE ||
		     (cb_compile_level == CB_LEVEL_ASSEMBLE && save_temps))) {
			cobc_check_action (fn->object);
		}
		if (save_all_src) {
			continue;
		}
		if (fn->need_preprocess &&
		    (status || cb_compile_level > CB_LEVEL_PREPROCESS ||
		     (cb_compile_level == CB_LEVEL_PREPROCESS && save_temps))) {
			cobc_check_action (fn->preprocess);
		}
		if (save_c_src) {
			continue;
		}
		if (fn->need_translate &&
		    (status || cb_compile_level > CB_LEVEL_TRANSLATE ||
		     (cb_compile_level == CB_LEVEL_TRANSLATE && save_temps))) {
			cobc_check_action (fn->translate);
			cobc_check_action (fn->trstorage);
			if (fn->localfile) {
				for (lf = fn->localfile; lf; lf = lf->next) {
					cobc_check_action (lf->local_name);
				}
			} else if (fn->translate) {
				/* If we get syntax errors, we do not
				   know the number of local include files */
				sprintf (cobc_buffer, "%s.l.h", fn->translate);
				for (i = 0; i < 30U; ++i) {
					if (i) {
						sprintf (cobc_buffer, "%s.l%u.h",
							fn->translate, i);
					}
					if (!access (cobc_buffer, F_OK)) {
						unlink (cobc_buffer);
					} else if (i) {
						break;
					}
				}
			}
		}
	}
	cobc_free_mem ();
	file_list = NULL;
}

static void COB_A_NORETURN
cobc_terminate (const char *str)
{
	int	save_errno;

	save_errno = errno;
	fprintf (stderr, "cobc: ");
	fflush (stderr);
	errno = save_errno;
	perror (str);
	fflush (stderr);
	cobc_clean_up (1);
	exit (1);
}

static void COB_A_NORETURN
cobc_abort_terminate (void)
{
	if (cb_source_file) {
		cobc_abort_pr (_("Aborting compile of %s at line %d"),
			 cb_source_file, cb_source_line);
	}
	cobc_clean_up (99);
	exit (99);
}

#ifdef	HAVE_SIGNAL_H
static void COB_A_NORETURN
cobc_sig_handler (int sig)
{
#if	defined(HAVE_SIGACTION) && !defined(SA_RESETHAND)
	struct sigaction	sa;
#endif

#ifdef	HAVE_SIG_ATOMIC_T
	if (sig_is_handled) {
#ifdef	HAVE_RAISE
		raise (sig);
#else
		kill (getpid (), sig);
#endif
		exit (sig);
	}
	sig_is_handled = 1;
#endif

#ifdef	HAVE_SIGACTION
#ifndef	SA_RESETHAND
	memset (&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_DFL;
	(void)sigemptyset (&sa.sa_mask);
	(void)sigaction (sig, &sa, NULL);
#endif
#else
	(void)signal (sig, SIG_DFL);
#endif

	save_temps = 0;
	cobc_clean_up (1);
#ifdef	HAVE_RAISE
	raise (sig);
#else
	kill (getpid (), sig);
#endif
	exit (sig);
}
#endif

/* Command line */

static void
cobc_print_version (void)
{
	printf ("cobc (%s) %s.%d\n",
		PACKAGE_NAME, PACKAGE_VERSION, PATCH_LEVEL);
	puts ("Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida");
	puts ("Copyright (C) 2006-2012 Roger While");
	puts ("Copyright (C) 2013 Ron Norman");
	puts (_("This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."));
	printf (_("Built     %s"), cb_oc_build_stamp);
	putchar ('\n');
	printf (_("Packaged  %s"), COB_TAR_DATE);
	putchar ('\n');
	printf (_("C version %s%s"), OC_C_VERSION_PRF, OC_C_VERSION);
	putchar ('\n');
}

static void
cobc_cmd_print (const char *cmd)
{
	char	*p;
	char	*token;
	size_t	n;
	size_t	toklen;

	fputs (_("Executing:"), stderr);
	/* Check if it fits in 80 characters */
	if (strlen (cmd) < 64) {
		fprintf (stderr, "\t%s\n", (char *)cmd);
		fflush (stderr);
		return;
	}
	putc ('\t', stderr);
	p = cobc_strdup (cmd);
	n = 0;
	token = strtok (p, " ");
	for (; token; token = strtok (NULL, " ")) {
		toklen = strlen (token) + 1;
		if ((n + toklen) > 63) {
			fprintf(stderr, "\n\t\t");
			n = 0;
		}
		fprintf (stderr, "%s%s", (n ? " " : ""), token);
		n += toklen;
	}
	free (p);
	putc ('\n', stderr);
	fflush (stderr);
}

static void
cobc_var_print (const char *msg, const char *val)
{
	char	*p;
	char	*token;
	size_t	n;
	size_t	toklen;

	printf ("%-*.*s : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
	if (strlen(val) <= CB_IVAL_SIZE) {
		printf("%s\n", val);
		return;
	}
	p = cobc_strdup (val);
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
cobc_print_info (void)
{
	char	buff[16];

	cobc_print_version ();
	puts (_("Build information"));
	cobc_var_print (_("Build environment"),	COB_BLD_BUILD);
	cobc_var_print ("CC",			COB_BLD_CC);
	cobc_var_print ("CPPFLAGS",		COB_BLD_CPPFLAGS);
	cobc_var_print ("CFLAGS",		COB_BLD_CFLAGS);
	cobc_var_print ("LD",			COB_BLD_LD);
	cobc_var_print ("LDFLAGS",		COB_BLD_LDFLAGS);
	putchar ('\n');
	puts (_("GNU Cobol information"));
	cobc_var_print ("COB_CC",		COB_CC);
	cobc_var_print ("COB_CFLAGS",		COB_CFLAGS);
	cobc_var_print ("COB_LDFLAGS",		COB_LDFLAGS);
	cobc_var_print ("COB_LIBS",		COB_LIBS);
	cobc_var_print ("COB_CONFIG_DIR",	COB_CONFIG_DIR);
	cobc_var_print ("COB_COPY_DIR",		COB_COPY_DIR);
	cobc_var_print ("COB_LIBRARY_PATH",	COB_LIBRARY_PATH);
	cobc_var_print ("COB_MODULE_EXT",	COB_MODULE_EXT);
	cobc_var_print ("COB_EXEEXT",		COB_EXEEXT);

#if	defined(USE_LIBDL) || defined(_WIN32)
	cobc_var_print (_("Dynamic loading"),	_("System"));
#else
	cobc_var_print (_("Dynamic loading"),	_("Libtool"));
#endif

#ifdef	COB_PARAM_CHECK
	cobc_var_print ("\"CBL_\" param check",	_("Enabled"));
#else
	cobc_var_print ("\"CBL_\" param check",	_("Disabled"));
#endif

	snprintf (buff, sizeof(buff), "%d", WITH_VARSEQ);
	cobc_var_print (_("Variable format"),	buff);

#ifdef	COB_LI_IS_LL
	cobc_var_print ("BINARY-C-LONG",	_("8 bytes"));
#else
	cobc_var_print ("BINARY-C-LONG",	_("4 bytes"));
#endif

#ifdef	WITH_SEQRA_EXTFH
	cobc_var_print (_("Sequential handler"),	_("External"));
#else
	cobc_var_print (_("Sequential handler"),	_("Internal"));
#endif
#ifdef	WITH_INDEX_EXTFH
	cobc_var_print (_("ISAM handler"),		_("External"));
#endif
#ifdef	WITH_DB
	cobc_var_print (_("ISAM handler"),		_("BDB"));
#endif
#ifdef	WITH_CISAM
	cobc_var_print (_("ISAM handler"),		_("C-ISAM (Experimental)"));
#endif
#ifdef	WITH_DISAM
	cobc_var_print (_("ISAM handler"),		_("D-ISAM (Experimental)"));
#endif
#ifdef	WITH_VBISAM
	cobc_var_print (_("ISAM handler"),		_("VBISAM (Experimental)"));
#endif
}

static void
cobc_print_warn (const char *name, const char *doc, const int wall)
{
	printf ("  -W%-19s %s", name, doc);
	if (!wall) {
		fputs ("\n\t\t\t", stdout);
		fputs (_("- NOT set with -Wall"), stdout);
	}
	putchar ('\n');
}

static void
cobc_print_flag (const char *name, const char *doc,
		 const int pdok, const int exten)
{
	const char	*bptr;
	char		buff[32];

	if (!pdok) {
		return;
	}
	if (!exten) {
		bptr = name;
	} else {
		snprintf (buff, sizeof(buff), "%s=<value>", name);
		bptr = buff;
	}
	printf ("  -f%-19s %s\n", bptr, doc);
}

static void
cobc_print_usage (void)
{
	puts (_("Usage: cobc [options] file ..."));
	putchar ('\n');
	puts (_("Options:"));
	puts (_("  -help                 Display this message"));
	puts (_("  -version, -V          Display compiler version"));
	puts (_("  -info, -i             Display compiler build information"));
	puts (_("  -v                    Display the commands invoked by the compiler"));
	puts (_("  -x                    Build an executable program"));
	puts (_("  -m                    Build a dynamically loadable module (default)"));
	puts (_("  -std=<dialect>        Warnings/features for a specific dialect :"));
	puts (_("                          cobol2002   Cobol 2002"));
	puts (_("                          cobol85     Cobol 85"));
	puts (_("                          ibm         IBM Compatible"));
	puts (_("                          mvs         MVS Compatible"));
	puts (_("                          bs2000      BS2000 Compatible"));
	puts (_("                          mf          Micro Focus Compatible"));
	puts (_("                          default     When not specified"));
	puts (_("                        See config/default.conf and config/*.conf"));
	puts (_("  -free                 Use free source format"));
	puts (_("  -fixed                Use fixed source format (default)"));
	puts (_("  -O, -O2, -Os          Enable optimization"));
	puts (_("  -g                    Enable C compiler debug / stack check / trace"));
	puts (_("  -debug                Enable all run-time error checking"));
	puts (_("  -o <file>             Place the output into <file>"));
	puts (_("  -b                    Combine all input files into a single"));
	puts (_("                        dynamically loadable module"));
	puts (_("  -E                    Preprocess only; do not compile or link"));
	puts (_("  -C                    Translation only; convert COBOL to C"));
	puts (_("  -S                    Compile only; output assembly file"));
	puts (_("  -c                    Compile and assemble, but do not link"));
	puts (_("  -P(=<dir or file>)    Generate preprocessed program listing (.lst)"));
	puts (_("  -Xref                 Generate cross reference through 'cobxref'"));
	puts (_("                        (V. Coen's 'cobxref' must be in path)"));
	puts (_("  -I <directory>        Add <directory> to copy/include search path"));
	puts (_("  -L <directory>        Add <directory> to library search path"));
	puts (_("  -l <lib>              Link the library <lib>"));
	puts (_("  -A <options>          Add <options> to the C compile phase"));
	puts (_("  -Q <options>          Add <options> to the C link phase"));
	puts (_("  -D <define>           DEFINE <define> to the COBOL compiler"));
	puts (_("  -K <entry>            Generate CALL to <entry> as static"));
	puts (_("  -conf=<file>          User defined dialect configuration - See -std="));
	puts (_("  -list-reserved        Display reserved words"));
	puts (_("  -list-intrinsics      Display intrinsic functions"));
	puts (_("  -list-mnemonics       Display mnemonic names"));
	puts (_("  -list-system          Display system routines"));
	puts (_("  -save-temps(=<dir>)   Save intermediate files"));
	puts (_("                        - Default : current directory"));
	puts (_("  -ext <extension>      Add default file extension"));

	putchar ('\n');

	puts (_("  -W                    Enable ALL warnings"));
	puts (_("  -Wall                 Enable all warnings except as noted below"));
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)		\
	cobc_print_warn (name, doc, 1);
#define	CB_NOWARNDEF(var,name,doc)		\
	cobc_print_warn (name, doc, 0);
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF

	putchar ('\n');

#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ
#define	CB_FLAG(var,pdok,name,doc)		\
	cobc_print_flag (name, doc, pdok, 0);
#define	CB_FLAG_RQ(var,pdok,name,def,opt,doc)	\
	cobc_print_flag (name, doc, pdok, 1);
#define	CB_FLAG_NQ(pdok,name,opt,doc)		\
	cobc_print_flag (name, doc, pdok, 1);
#include "flag.def"
#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ

	putchar ('\n');
}

static void
cobc_options_error_nonfinal (void)
{
	cobc_err_exit (_("Only one of options 'E', 'S', 'C', 'c' may be specified"));
}

static void
cobc_options_error_build (void)
{
	cobc_err_exit (_("Only one of options 'm', 'x', 'b' may be specified"));
}

static void
cobc_deciph_funcs (const char *opt)
{
	char	*p;
	char	*q;

	if (!strcasecmp (opt, "ALL")) {
		cb_flag_functions_all = 1;
		return;
	}

	p = cobc_strdup (opt);
	q = strtok (p, ",");
	while (q) {
		if (!lookup_intrinsic (q, 0, 1)) {
			cobc_err_exit (_("'%s' is not an intrinsic function"), q);
		}
		CB_TEXT_LIST_ADD (cb_intrinsic_list, q);
		q = strtok (NULL, ",");
	}
	free (p);
}

static int
process_command_line (const int argc, char **argv)
{
	struct cb_define_struct	*p;
	size_t			osize;
	int			c;
	int			idx;
	int			n;
	int 			argnum;
	enum cob_exception_id	i;
	struct stat		st;
	char			ext[COB_MINI_BUFF];

	/* Translate command line arguments from WIN to UNIX style */
	argnum = 1;
	while (++argnum <= argc) {
		if (argv[argnum - 1][0] == '/') {
			argv[argnum - 1][0] = '-';
		}
	}

	while ((c = cob_getopt_long_long (argc, argv, short_options,
					  long_options, &idx, 1)) >= 0) {
		switch (c) {
		case 0:
			/* Defined flag */
			break;

		case '?':
			/* Unknown option or ambiguous */
			cobc_free_mem ();
			exit (1);

		case 'h':
			/* --help */
			cobc_print_usage ();
			cobc_free_mem ();
			exit (0);

		case 'V':
			/* --version */
			cobc_print_version ();
			exit_option = 1;
			break;

		case 'i':
			/* --info */
			cobc_print_info ();
			exit_option = 1;
			break;

		case '5':
			/* --list-reserved */
			cb_list_reserved ();
			exit_option = 1;
			break;

		case '6':
			/* --list-intrinsics */
			cb_list_intrinsics ();
			exit_option = 1;
			break;

		case '7':
			/* --list-mnemonics */
			cb_list_mnemonics ();
			exit_option = 1;
			break;

		case '8':
			/* --list-system */
			cb_list_system ();
			exit_option = 1;
			break;

		case 'E':
			/* -E : Preprocess */
			if (wants_nonfinal) {
				cobc_options_error_nonfinal ();
			}
			wants_nonfinal = 1;
			cb_compile_level = CB_LEVEL_PREPROCESS;
			break;

		case 'C':
			/* -C : Generate C code */
			if (wants_nonfinal) {
				cobc_options_error_nonfinal ();
			}
			save_c_src = 1;
			wants_nonfinal = 1;
			cb_compile_level = CB_LEVEL_TRANSLATE;
			break;

		case 'S':
			/* -S : Generate assembler code */
			if (wants_nonfinal) {
				cobc_options_error_nonfinal ();
			}
			wants_nonfinal = 1;
			cb_compile_level = CB_LEVEL_COMPILE;
			break;

		case 'c':
			/* -c : Generate C object code */
			if (wants_nonfinal) {
				cobc_options_error_nonfinal ();
			}
			wants_nonfinal = 1;
			cb_compile_level = CB_LEVEL_ASSEMBLE;
			break;

		case 'b':
			/* -b : Generate combined library module */
			if (cobc_flag_main || cobc_flag_module) {
				cobc_options_error_build ();
			}
			cobc_flag_library = 1;
			no_physical_cancel = 1;
			cb_flag_implicit_init = 1;
			break;

		case 'm':
			/* -m : Generate loadable module (default) */
			if (cobc_flag_main || cobc_flag_library) {
				cobc_options_error_build ();
			}
			cobc_flag_module = 1;
			break;

		case 'x':
			/* -x : Generate executable */
			if (cobc_flag_module || cobc_flag_library) {
				cobc_options_error_build ();
			}
			cobc_flag_main = 1;
			cb_flag_main = 1;
			no_physical_cancel = 1;
			break;

		case 'v':
			/* -v : Verbose reporting */
			verbose_output = 1;
			break;

		case 'o':
			/* -o : Output file */
			osize = strlen (cob_optarg);
			if (osize > COB_SMALL_MAX) {
				cobc_err_exit (_("Invalid output file name"));
			}
			output_name = cobc_main_strdup (cob_optarg);
			/* Allocate buffer plus extension reserve */
			output_name_buff = cobc_main_malloc (osize + 32U);
			break;

		case 'O':
			/* -O : Optimize */
			cob_optimize = 1;
			COBC_ADD_STR (cobc_cflags, CB_COPT_1, NULL, NULL);
			break;

		case '9':
			/* -O2 : Optimize */
			cob_optimize = 1;
			strip_output = 1;
			COBC_ADD_STR (cobc_cflags, CB_COPT_2, NULL, NULL);
			break;

		case 's':
			/* -Os : Optimize */
			cob_optimize = 1;
			strip_output = 1;
			COBC_ADD_STR (cobc_cflags, CB_COPT_S, NULL, NULL);
			break;

		case 'g':
			/* -g : Generate C debug code */
			save_all_src = 1;
			gflag_set = 1;
			cb_flag_stack_check = 1;
			cb_flag_source_location = 1;
#ifndef	_MSC_VER
			COBC_ADD_STR (cobc_cflags, " -g", NULL, NULL);
#endif
			break;

		case '$':
			/* -std=<xx> : Specify dialect */
			snprintf (ext, (size_t)COB_MINI_MAX, "%s.conf", cob_optarg);
			if (cb_load_std (ext) != 0) {
				cobc_err_exit (_("Invalid option -std=%s"),
					       cob_optarg);
			}
			break;

		case '&':
			/* -conf=<xx> : Specify dialect configuration file */
			if (strlen (cob_optarg) > COB_SMALL_MAX) {
				cobc_err_exit (COBC_INV_PAR , "-conf");
			}
			if (cb_load_conf (cob_optarg, 1, 0) != 0) {
				cobc_free_mem ();
				exit (1);
			}
			break;

		case 'd':
			/* -debug : Turn on OC debugging */
			/* Turn on all exception conditions */
			for (i = (enum cob_exception_id)1; i < COB_EC_MAX; ++i) {
				CB_EXCEPTION_ENABLE (i) = 1;
			}
			cb_flag_source_location = 1;
			cb_flag_trace = 1;
			cb_flag_stack_check = 1;
			cobc_wants_debug = 1;
			break;

		case '_':
			/* --save-temps : Save intermediary files */
			save_temps = 1;
			if (cob_optarg) {
				if (stat (cob_optarg, &st) != 0 ||
				    !(S_ISDIR (st.st_mode))) {
					cobc_abort_pr (_("Warning - '%s' is not a directory, defaulting to current directory"), cob_optarg);
				} else {
					save_temps_dir = cobc_strdup (cob_optarg);
				}
			}
			break;

		case 'P':
			/* -P : Generate listing */
			if (cob_optarg) {
				if (!stat (cob_optarg, &st) && S_ISDIR (st.st_mode)) {
					cobc_list_dir = cobc_strdup (cob_optarg);
				} else {
					cobc_list_file = cobc_strdup (cob_optarg);
				}
			}
			if (!cobc_gen_listing) {
				cobc_gen_listing = 1;
			}
			break;

		case 'X':
			/* -Xref : Generate listing through 'cobxref' */
			cobc_gen_listing = 2;
			break;

		case 'D':
			/* -D xx(=yy) : Define variables */
			if (strlen (cob_optarg) > 64U) {
				cobc_err_exit (COBC_INV_PAR, "-D");
			}
			if (!strcasecmp (cob_optarg, "ebug")) {
				cobc_abort_pr (_("Warning - assuming '%s' is a DEFINE - did you intend to use -debug?"),
						cob_optarg);
			}
			p = cb_define_list_add (cb_define_list, cob_optarg);
			if (!p) {
				cobc_err_exit (COBC_INV_PAR, "-D");
			}
			cb_define_list = p;
			break;

		case 'I':
			/* -I <xx> : Include/copy directory */
			if (strlen (cob_optarg) > COB_SMALL_MAX) {
				cobc_err_exit (COBC_INV_PAR, "-I");
			}
			if (stat (cob_optarg, &st) != 0 ||
			    !(S_ISDIR (st.st_mode))) {
				break;
			}
#ifdef	_MSC_VER
			COBC_ADD_STR (cobc_include, " /I \"", cob_optarg, "\"");
#elif	defined (__WATCOMC__)
			COBC_ADD_STR (cobc_include, " -i\"", cob_optarg, "\"");
#else
			COBC_ADD_STR (cobc_include, " -I\"", cob_optarg, "\"");
#endif
			CB_TEXT_LIST_ADD (cb_include_list, cob_optarg);
			break;

		case 'L':
			/* -L <xx> : Directory for library search */
			if (strlen (cob_optarg) > COB_SMALL_MAX) {
				cobc_err_exit (COBC_INV_PAR, "-L");
			}
			if (stat (cob_optarg, &st) != 0 ||
			    !(S_ISDIR (st.st_mode))) {
				break;
			}
#ifdef	_MSC_VER
			COBC_ADD_STR (cobc_lib_paths, " /LIBPATH:\"", cob_optarg, "\"");
#else
			COBC_ADD_STR (cobc_lib_paths, " -L\"", cob_optarg, "\"");
#endif
			break;

		case 'l':
			/* -l <xx> : Add library to link phase */
			if (strlen (cob_optarg) > COB_SMALL_MAX) {
				cobc_err_exit (COBC_INV_PAR, "-l");
			}
#ifdef	_MSC_VER
			COBC_ADD_STR (cobc_libs, " \"", cob_optarg, "\"");
#else
			COBC_ADD_STR (cobc_libs, " -l\"", cob_optarg, "\"");
#endif
			break;

		case 'e':
			/* -e <xx> : Add an extension suffix */
			if (strlen (cob_optarg) > 15U) {
				cobc_err_exit (COBC_INV_PAR, "--ext");
			}
			snprintf (ext, (size_t)COB_MINI_MAX, ".%s", cob_optarg);
			CB_TEXT_LIST_ADD (cb_extension_list, ext);
			break;

		case 'K':
			/* -K <xx> : Define literal CALL to xx as static */
			if (strlen (cob_optarg) > 32U) {
				cobc_err_exit (COBC_INV_PAR, "-K");
			}
			CB_TEXT_LIST_ADD (cb_static_call_list, cob_optarg);
			break;

		case 'k':
			/* -k <xx> : Check for exit after CALL to xx  */
			/* This is to cater for legacy German DIN standard */
			/* Check after CALL if an exit program required */
			/* Not in --help as subject to change and highly specific */
			if (strlen (cob_optarg) > 32U) {
				cobc_err_exit (COBC_INV_PAR, "-k");
			}
			CB_TEXT_LIST_ADD (cb_early_exit_list, cob_optarg);
			break;

		case 1:
			/* -fstack-size=<xx> : Specify stack (perform) size */
			n = cobc_deciph_optarg (cob_optarg, 0);
			if (n < 16 || n > 512) {
				cobc_err_exit (COBC_INV_PAR, "-fstack-size");
			}
			cb_stack_size = n;
			break;

		case 2:
			/* -fif-cutoff=<xx> : Specify IF cutoff level */
			n = cobc_deciph_optarg (cob_optarg, 0);
			if (n < 1 || n > 512) {
				cobc_err_exit (COBC_INV_PAR, "-fif-cutoff");
			}
			cb_if_cutoff = n;
			break;

		case 3:
			/* -fsign=<ASCII/EBCDIC> : Specify display sign */
			if (!strcasecmp (cob_optarg, "EBCDIC")) {
				cb_ebcdic_sign = 1;
			} else if (!strcasecmp (cob_optarg, "ASCII")) {
				cb_ebcdic_sign = 0;
			} else {
				cobc_err_exit (COBC_INV_PAR, "-fsign");
			}
			break;

		case 4:
			/* -ffold-copy=<UPPER/LOWER> : COPY fold case */
			if (!strcasecmp (cob_optarg, "UPPER")) {
				cb_fold_copy = COB_FOLD_UPPER;
			} else if (!strcasecmp (cob_optarg, "LOWER")) {
				cb_fold_copy = COB_FOLD_LOWER;
			} else {
				cobc_err_exit (COBC_INV_PAR, "-ffold-copy");
			}
			break;

		case 5:
			/* -ffold-call=<UPPER/LOWER> : CALL/PROG-ID fold case */
			if (!strcasecmp (cob_optarg, "UPPER")) {
				cb_fold_call = COB_FOLD_UPPER;
			} else if (!strcasecmp (cob_optarg, "LOWER")) {
				cb_fold_call = COB_FOLD_LOWER;
			} else {
				cobc_err_exit (COBC_INV_PAR, "-ffold-call");
			}
			break;

		case 6:
			/* -fdefaultbyte=<xx> : Default initialization byte */
			n = cobc_deciph_optarg (cob_optarg, 1);
			if (n < 0 || n > 255) {
				cobc_err_exit (COBC_INV_PAR, "-fdefaultbyte");
			}
			cb_default_byte = n;
			break;

		case 10:
			/* -fintrinsics=<xx> : Intrinsic name or ALL */
			cobc_deciph_funcs (cob_optarg);
			break;

		case 'A':
			/* -A <xx> : Add options to C compile phase */
			COBC_ADD_STR (cobc_cflags, " ", cob_optarg, NULL);
			aflag_set = 1;
			break;

		case 'Q':
			/* -Q <xx> : Add options to C link phase */
			COBC_ADD_STR (cobc_ldflags, " ", cob_optarg, NULL);
			break;

		case 'w':
			/* -w(xx) : Turn off warnings */
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)	var = 0;
#define	CB_NOWARNDEF(var,name,doc)	var = 0;
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
			break;

		case 'W':
			/* -W : Turn on warnings */
			warningopt = 1;
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)	var = 1;
#define	CB_NOWARNDEF(var,name,doc)
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
			break;

		case 'Z':
			/* -W : Turn on all warnings */
			warningopt = 1;
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)	var = 1;
#define	CB_NOWARNDEF(var,name,doc)	var = 1;
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
			break;

		default:
			cobc_err_exit (_("Invalid option detected"));
		}
	}

	/* Exit if list options specified */
	if (exit_option) {
		cobc_free_mem ();
		exit (0);
	}

	/* Load default configuration file if necessary */
	if (cb_config_name == NULL) {
		if (cb_load_std ("default.conf") != 0) {
			cobc_err_exit (_("Failed to load the initial config file"));
		}
	}

	/* Check valid tab width */
	if (cb_tab_width < 1 || cb_tab_width > 8) {
		cobc_err_exit (_("Invalid tab-width value - %d"),
			 cb_tab_width);
	}

	/* Check valid text columns value */
	if (cb_text_column < 72 || cb_text_column > 255) {
		cobc_err_exit (_("Invalid text-column value - %d"),
			 cb_text_column);
	}

	/* Set relaxed syntax parameters */
	if (cb_flag_relaxed_syntax) {
		cb_relaxed_syntax_check = 1;
		cb_larger_redefines_ok = 1;
		cb_relax_level_hierarchy = 1;
		cb_top_level_occurs_clause = 1;
	}

	/* If C debug, do not strip output */
	if (gflag_set) {
		strip_output = 0;
	}

	if (cb_flag_traceall) {
		cb_flag_trace = 1;
		cb_flag_source_location = 1;
	}

	return cob_optind;
}

/* Reverse the list of programs */

static struct cb_program *
program_list_reverse (struct cb_program *p)
{
	struct cb_program	*next;
	struct cb_program	*last;

	last = NULL;
	for (; p; p = next) {
		next = p->next_program;
		p->next_program = last;
		last = p;
	}
	return last;
}

static void
process_env_copy_path (const char *p)
{
	char		*value;
	char		*token;
	struct stat	st;

	if (p == NULL || !*p || *p == ' ') {
		return;
	}

	/* Clone value for destructive strtok */
	value = cobc_strdup (p);

	/* Tokenize for path sep. */
	token = strtok (value, PATHSEPS);
	while (token) {
		if (!stat (token, &st) && (S_ISDIR (st.st_mode))) {
			CB_TEXT_LIST_CHK (cb_include_list, token);
		}
		token = strtok (NULL, PATHSEPS);
	}

	free (value);
	return;
}

#if	defined (_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
static void
file_stripext (char *buff)
{
	char	*endp;

	endp = buff + strlen (buff) - 1U;
	while (endp > buff) {
		if (*endp == '/' || *endp == '\\') {
			break;
		}
		if (*endp == '.') {
			*endp = 0;
		}
		--endp;
	}
}
#endif

static char *
file_basename (const char *filename)
{
	const char	*p;
	const char	*startp;
	const char	*endp;
	size_t		len;

	/* Remove directory name */
	startp = NULL;
	for (p = filename; *p; p++) {
		if (*p == '/' || *p == '\\') {
			startp = p;
		}
	}
	if (startp) {
		startp++;
	} else {
		startp = filename;
	}

	/* Remove extension */
	endp = strrchr (filename, '.');
	if (endp > startp) {
		len = endp - startp;
	} else {
		len = strlen (startp);
	}

	if (len >= basename_len) {
		basename_len = len + 16;
		basename_buffer = cobc_main_realloc (basename_buffer, basename_len);
	}
	/* Copy base name */
	memcpy (basename_buffer, startp, len);
	basename_buffer[len] = 0;
	return basename_buffer;
}

static const char *
file_extension (const char *filename)
{
	const char *p;

	p = strrchr (filename, '.');
	if (p) {
		return p + 1;
	}
	return "";
}

static char *
cobc_temp_name (const char *ext)
{
#ifdef	_WIN32
	char	buff[COB_MEDIUM_BUFF];
	char	temp[MAX_PATH];

	GetTempPath (MAX_PATH, temp);
	GetTempFileName (temp, "cob", 0, buff);
	DeleteFile (buff);
	/* Replace ".tmp" by EXT */
	strcpy (buff + strlen (buff) - 4, ext);
	return cobc_main_strdup (buff);
#else
	char	*buff;
	size_t	size;

	size = strlen (cobc_tmpdir) + strlen (ext) + 16U;
	buff = cobc_main_malloc (size);
	sprintf (buff, "%s/cob%d_%d%s", cobc_tmpdir, (int)cob_process_id,
		 (int)cob_iteration, ext);
	return buff;
#endif
}

static struct filename *
process_filename (const char *filename)
{
	const char	*extension;
	struct filename	*fn;
	struct filename	*ffn;
	char		*fbasename;
	char		*listptr;
	size_t		fsize;

	fsize = strlen (filename);
	if (fsize > COB_NORMAL_MAX) {
		cobc_abort_pr (_("Invalid file name parameter"));
		return NULL;
	}

#ifdef	__OS400__
	if (strchr (filename, '.') != NULL) {
#endif

	if (access (filename, R_OK) != 0) {
		cobc_terminate (filename);
	}

#ifdef	__OS400__
	}
#endif

	fbasename = file_basename (filename);
	extension = file_extension (filename);
	if (strcmp(extension, "lib") && strcmp(extension, "a")) {
		if (cobc_check_valid_name (fbasename, 0)) {
			return NULL;
		}
	}
	fn = cobc_main_malloc (sizeof (struct filename));
	fn->need_preprocess = 1;
	fn->need_translate = 1;
	fn->need_assemble = 1;
	fn->next = NULL;

	if (!file_list) {
		file_list = fn;
	} else {
		for (ffn = file_list; ffn->next; ffn = ffn->next)
			;
		ffn->next = fn;
	}

	fn->demangle_source = cb_encode_program_id (fbasename);

	/* Check input file type */
	if (strcmp (extension, "i") == 0) {
		/* Already preprocessed */
		fn->need_preprocess = 0;
	} else if (strcmp (extension, "c") == 0 ||
		   strcmp (extension, "s") == 0) {
		/* Already compiled */
		fn->need_preprocess = 0;
		fn->need_translate = 0;
#if	defined (_MSC_VER) || defined (__WATCOMC__) || defined (__BORLANDC__)
	} else if (strcmp (extension, "obj") == 0 ||
		   strcmp (extension, "lib") == 0) {
#elif	defined(__OS400__)
	} else if (extension[0] == 0) {
#else
	} else if (strcmp (extension, "o") == 0 ||
#if	defined(__MINGW32__) || defined(__MINGW64__)
		   strcmp (extension, "lib") == 0 ||
#endif
		   strcmp (extension, "a") == 0 ||
		   strcmp (extension, "so") == 0 ||
		   strcmp (extension, "dylib") == 0 ||
		   strcmp (extension, "sl") == 0) {
#endif
		/* Already assembled */
		fn->need_preprocess = 0;
		fn->need_translate = 0;
		fn->need_assemble = 0;
	}

	/* Set source filename */
	fn->source = cobc_main_strdup (filename);

	/* Set preprocess filename */
	if (!fn->need_preprocess) {
		fn->preprocess = cobc_main_strdup (fn->source);
	} else if (output_name && cb_compile_level == CB_LEVEL_PREPROCESS) {
		fn->preprocess = cobc_main_strdup (output_name);
	} else if (save_all_src || save_temps ||
		   cb_compile_level == CB_LEVEL_PREPROCESS) {
		fn->preprocess = cobc_stradd_dup (fbasename, ".i");
	} else {
		fn->preprocess = cobc_temp_name (".cob");
	}

	/* Set translate filename */
	if (!fn->need_translate) {
		fn->translate = cobc_main_strdup (fn->source);
	} else if (output_name && cb_compile_level == CB_LEVEL_TRANSLATE) {
		fn->translate = cobc_main_strdup (output_name);
	} else if (save_all_src || save_temps || save_c_src ||
		   cb_compile_level == CB_LEVEL_TRANSLATE) {
		fn->translate = cobc_stradd_dup (fbasename, ".c");
	} else {
		fn->translate = cobc_temp_name (".c");
	}
	fn->translate_len = strlen (fn->translate);

	/* Set storage filename */
	if (fn->need_translate) {
		fn->trstorage = cobc_stradd_dup (fn->translate, ".h");
	}

	/* Set object filename */
	if (!fn->need_assemble) {
		fn->object = cobc_main_strdup (fn->source);
	} else if (output_name && cb_compile_level == CB_LEVEL_ASSEMBLE) {
		fn->object = cobc_main_strdup (output_name);
	} else if (save_temps || cb_compile_level == CB_LEVEL_ASSEMBLE) {
#if	defined(_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
		fn->object = cobc_stradd_dup (fbasename, ".obj");
#else
		fn->object = cobc_stradd_dup (fbasename, ".o");
#endif
	} else {
#if	defined(_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
		fn->object = cobc_stradd_dup (fbasename, ".obj");
#else
		fn->object = cobc_temp_name (".o");
#endif
	}
	fn->object_len = strlen (fn->object);
	cobc_objects_len += fn->object_len + 8U;

	/* Set listing filename */
	if (cobc_gen_listing == 1) {
		if (cobc_list_file) {
			fn->listing_file = cobc_list_file;
		} else if (cobc_list_dir) {
			fsize = strlen (cobc_list_dir) + strlen (fbasename) + 8U;
			listptr = cobc_main_malloc (fsize);
			snprintf (listptr, fsize, "%s/%s.lst",
				  cobc_list_dir, fbasename);
			fn->listing_file = listptr;
		} else {
			fn->listing_file = cobc_stradd_dup (fbasename, ".lst");
		}
	} else if (cobc_gen_listing > 1) {
		fn->listing_file = cobc_stradd_dup (fbasename, ".xrf");
	}

	cob_iteration++;
	return fn;
}

#ifdef	__OS400__
static int
process (char *cmd)
{
	char	*buffptr;
	char	*name = NULL;
	char	*objname = NULL;
	char	*cobjname = NULL;
	char	*token;
	char	*incl[100];
	char	*defs[100];
	char	*objs[100];
	char	*libs[100];
	char	*optc[100];
	char	*optl[100];
	int	nincl = 0;
	int	ndefs = 0;
	int	nobjs = 0;
	int	nlibs = 0;
	int	noptc = 0;
	int	noptl = 0;
	int	dbg = 0;
	int	comp_only = 0;
	int	shared = 0;
	int	optimize = 0;
	int	i;
	int	len;
	int	ret;

	if (verbose_output) {
		cobc_cmd_print (cmd);
	}
	if (gflag_set) {
		dbg = 1;
	}
	token = strtok (cmd, " ");
	if (token != NULL) {
		/* Skip C compiler */
		token = strtok (NULL, " ");
	}
	for (; token; token = strtok (NULL, " ")) {
		if (*token != '-') {
			len = strlen (token);
			if (*token == '"') {
				len -= 2;
				++token;
				token[len] = 0;
			}
			if (token[len-2] == '.' && token[len-1] == 'c') {
				/* C source */
				name = token;
				continue;
			}
			/* Assuming module */
			objs[nobjs++] = token;
			continue;
		}
		++token;
		switch (*token) {
		case 'c':
			comp_only = 1;
			break;
		case 'I':
			++token;
			if (*token == 0) {
				token = strtok (NULL, " ");
			}
			if (*token == '"') {
				++token;
				token[strlen(token) - 1] = 0;
			}
			incl[nincl++] = token;
			break;
		case 'D':
			++token;
			if (*token == 0) {
				token = strtok (NULL, " ");
			}
			if (*token == '"') {
				++token;
				token[strlen(token) - 1] = 0;
			}
			defs[ndefs++] = token;
			break;
		case 'A':
			++token;
			optc[noptc++] = token;
			break;
		case 'Q':
			++token;
			optl[noptl++] = token;
			break;
		case 'o':
			++token;
			if (*token == 0) {
				token = strtok (NULL, " ");
			}
			if (*token == '"') {
				++token;
				token[strlen(token) - 1] = 0;
			}
			objname = token;
			break;
		case 'l':
			++token;
			if (*token == 0) {
				token = strtok (NULL, " ");
			}
			libs[nlibs++] = token;
			break;
		case 'G':
			shared = 1;
			break;
		case 'g':
			dbg = 1;
			break;
		case 'O':
			optimize = 1;
			break;
		default:
			cobc_abort_pr (_("Unknown option ignored:\t%s"),
				 token - 1);
		}
	}

	buffptr = cobc_malloc (COB_LARGE_BUFF);
	if (name != NULL) {
		/* Requires compilation */
		if (objname == NULL) {
			cobjname = file_basename (name);
		} else {
			cobjname = objname;
		}
		sprintf(buffptr, "CRTCMOD MODULE(%s) SRCSTMF('%s') ",
			cobjname, name);
		if (nincl > 0) {
			strcat (buffptr, "INCDIR(");
			for (i = 0; i < nincl; ++i) {
				if (i != 0) {
					strcat (buffptr, " ");
				}
				strcat (buffptr, "'");
				strcat (buffptr, incl[i]);
				strcat (buffptr, "' ");
			}
			strcat (buffptr, ") ");
		}
		if (ndefs > 0) {
			strcat (buffptr, "DEFINE(");
			for (i = 0; i < ndefs; ++i) {
				if (i != 0) {
					strcat (buffptr, " ");
				}
				strcat (buffptr, "'");
				strcat (buffptr, defs[i]);
				strcat (buffptr, "' ");
			}
			strcat (buffptr, ") ");
		}
		strcat (buffptr, "SYSIFCOPT(*IFSIO)");
		for (i = 0; i < noptc; ++i) {
			strcat (buffptr, " ");
			strcat (buffptr, optc[i]);
		}
		if (optimize) {
			strcat (buffptr, " OPTIMIZE(40)");
		}
		if (dbg) {
			strcat (buffptr, " DBGVIEW(*ALL)");
		}
		if (cobc_gen_listing) {
			strcat (buffptr, " OUTPUT(*PRINT)");
		}
		if (verbose_output) {
			cobc_cmd_print (buffptr);
		}
		ret = system (buffptr);
		if (verbose_output) {
			fputs (_("Return status:"), stderr);
			fprintf (stderr, "\t%d\n", ret);
			fflush (stderr);
		}
		if (comp_only || ret != 0) {
			free (buffptr);
			return ret;
		}
	}
	if (objname == NULL) {
		if (name != NULL) {
			objname = cobjname;
		} else if (nobjs > 0) {
			objname = objs[0];
		} else {
			objname = (char *)"AOUT";
		}
	}
	if (shared) {
		sprintf(buffptr, "CRTSRVPGM SRVPGM(%s) MODULE(", objname);
	} else {
		sprintf(buffptr, "CRTPGM PGM(%s) MODULE(", objname);
	}
	if (name != NULL) {
		strcat (buffptr, cobjname);
	}
	for (i = 0; i < nobjs; ++i) {
		if (i != 0 || name != NULL) {
			strcat (buffptr, " ");
		}
		strcat (buffptr, objs[i]);
	}
	strcat (buffptr, ")");
	if (nlibs > 0) {
		strcat (buffptr, " BNDSRVPGM(");
		for (i = 0; i < nlibs; ++i) {
			if (i != 0) {
				strcat (buffptr, " ");
			}
			strcat (buffptr, libs[i]);
		}
		strcat (buffptr, ")");
	}
	for (i = 0; i < noptl; ++i) {
		strcat (buffptr, " ");
		strcat (buffptr, optl[i]);
	}
	if (shared) {
		strcat (buffptr, " EXPORT(*ALL)");
	}
	if (verbose_output) {
		cobc_cmd_print (buffptr);
	}
	ret = system (buffptr);
	if (verbose_output) {
		fputs (_("Return status:"), stderr);
		fprintf (stderr, "\t%d\n", ret);
		fflush (stderr);
	}
	free (buffptr);
	return ret;
}

#else

static int
process (const char *cmd)
{
	char	*p;
	char	*buffptr;
	size_t	clen;
	int	ret;

#ifndef _MSC_VER
	if (likely(strchr (cmd, '$') == NULL)) {
		buffptr = (char *)cmd;
	} else {
		clen = strlen (cmd) + 64U;
		clen = clen + 6U;
		buffptr = (char *)cobc_malloc (clen);
		p = buffptr;
		/* Quote '$' */
		for (; *cmd; ++cmd) {
			if (*cmd == '$') {
				p += sprintf (p, "\\$");
			} else {
				*p++ = *cmd;
			}
		}
		*p = 0;
	}
#else
	/* Silence MSC output "Creating xyz..."
      Fixme: should only be done when used to process cl.exe
   */
	clen = strlen (cmd);
	if (!verbose_output) {
		clen += 7U;
	}
	if (likely(strchr (cmd, '$') == NULL)) {
		buffptr = (char *)cobc_malloc (clen);
		p = buffptr;
		/* Quote '$' */
		for (; *cmd; ++cmd) {
			*p++ = *cmd;
		}
	} else {
		clen += 64U;
		buffptr = (char *)cobc_malloc (clen);
		p = buffptr;
		/* Quote '$' */
		for (; *cmd; ++cmd) {
			if (*cmd == '$') {
				p += sprintf (p, "\\$");
			} else {
				*p++ = *cmd;
			}
		}
	}
	if (!verbose_output) {
		p += sprintf (p, " 1>NUL");
	}
	*p = 0;
#endif

	if (verbose_output) {
		cobc_cmd_print (buffptr);
	}

	ret = system (buffptr);

	if (unlikely(buffptr != cmd)) {
		free (buffptr);
	}

#ifdef	WIFSIGNALED
	if (WIFSIGNALED(ret)) {
#ifdef	SIGINT
		if (WTERMSIG(ret) == SIGINT) {
			cobc_sig_handler (SIGINT);
		}
#endif
#ifdef	SIGQUIT
		if (WTERMSIG(ret) == SIGQUIT) {
			cobc_sig_handler (SIGQUIT);
		}
#endif
	}
#endif
	if (verbose_output) {
		fputs (_("Return status:"), stderr);
		fprintf (stderr, "\t%d\n", ret);
		fflush (stderr);
	}
	return !!ret;
}
#endif

/* Preprocess source */

static int
preprocess (struct filename *fn)
{
	struct cobc_mem_struct	*m;
	struct cobc_mem_struct	*ml;
	int			save_source_format;
	int			save_fold_copy;
	int			save_fold_call;
	int			ret;

	errorcount = 0;

	ppout = fopen (fn->preprocess, "w");
	if (!ppout) {
		cobc_terminate (fn->preprocess);
	}

	if (ppopen (fn->source, NULL) != 0) {
		fclose (ppout);
		ppout = NULL;
		if (fn->preprocess) {
			(void)unlink (fn->preprocess);
		}
		cobc_free_mem ();
		exit (1);
	}

	if (verbose_output) {
		fputs (_("Preprocessing:"), stderr);
		fprintf (stderr, "\t%s -> %s\n",
			 fn->source, fn->preprocess);
		fflush (stderr);
	}

	if (cobc_gen_listing && !cobc_list_file) {
		cb_listing_file = fopen (fn->listing_file, "w");
		if (!cb_listing_file) {
			cobc_terminate (fn->listing_file);
		}
	}

	/* Reset pplex/ppparse variables */
	plex_clear_vars ();
	ppparse_clear_vars (cb_define_list);

	/* Save default flags in case program directives change them */
	save_source_format = cb_source_format;
	save_fold_copy = cb_fold_copy;
	save_fold_call = cb_fold_call;

	/* Preprocess */
	ppparse ();

	/* Restore default flags */
	cb_source_format = save_source_format;
	cb_fold_copy = save_fold_copy;
	cb_fold_call = save_fold_call;

	if (ppin) {
		fclose (ppin);
		ppin = NULL;
	}

	if (ppout) {
		fclose (ppout);
		ppout = NULL;
	}

	/* Release flex buffers - After file close */
	plex_call_destroy ();

	for (m = cobc_plexmem_base; m; ) {
		ml = m;
		m = m->next;
		free (ml);
	}
	cobc_plexmem_base = NULL;

	if (cobc_gen_listing && !cobc_list_file) {
		fclose (cb_listing_file);
		if (cobc_gen_listing > 1) {
			sprintf (cobc_buffer, "cobxref %s -R", fn->listing_file);
			if (verbose_output) {
				cobc_cmd_print (cobc_buffer);
			}
			ret = system (cobc_buffer);
			if (verbose_output) {
				fputs (_("Return status:"), stderr);
				fprintf (stderr, "\t%d\n", ret);
				fflush (stderr);
			}
			if (ret) {
				fputs (_("'cobxref' execution unsuccessful"),
					stderr);
				putc ('\n', stderr);
#ifdef	_WIN32
				fputs (_("Check that 'cobxref' is in %%PATH%%"),
					stderr);
#else
				fputs (_("Check that 'cobxref' is in $PATH"),
					stderr);
#endif
				putc ('\n', stderr);
				fputs (_("No listing produced"),
					stderr);
				putc ('\n', stderr);
				fflush (stderr);
			}
			unlink (fn->listing_file);
		}
		cb_listing_file = NULL;
	}

	if (verbose_output) {
		fputs (_("Return status:"), stderr);
		fprintf (stderr, "\t%d\n", errorcount);
		fflush (stderr);
	}
	return !!errorcount;
}

/* Create single-element C source */

static int
process_translate (struct filename *fn)
{
	struct cb_program	*p;
	struct cb_program	*q;
	struct cb_program	*r;
	struct nested_list	*nlp;
	struct handler_struct	*hstr1;
	struct handler_struct	*hstr2;
	struct local_filename	*lf;
	int			ret;
	int			i;

	/* Initialize */
	cb_source_file = NULL;
	cb_source_line = 0;
	errorcount = 0;

	/* Open the input file */
	yyin = fopen (fn->preprocess, "r");
	if (!yyin) {
		cobc_terminate (fn->preprocess);
	}

	if (verbose_output) {
		fputs (_("Parsing:"), stderr);
		fprintf (stderr, "\t%s (%s)\n", fn->preprocess, fn->source);
		fflush (stderr);
	}

	current_program = NULL;
	cb_init_constants ();

	/* Parse */
	ret = yyparse ();

	fclose (yyin);
	yyin = NULL;

	/* Release flex buffers - After file close */
	ylex_call_destroy ();

	if (verbose_output) {
		fputs (_("Return status:"), stderr);
		fprintf (stderr, "\t%d\n", ret);
		fflush (stderr);
	}

	if (ret || cb_flag_syntax_only) {
		return !!ret;
	}
	if (current_program && current_program->entry_list == NULL) {
		return 0;
	}

	/* Set up USE GLOBAL handlers */
	p = current_program;
	for (q = p; q; q = q->next_program) {
		q->global_file_list = cb_list_reverse (q->global_file_list);
		if (q->nested_level) {
			for (r = q->next_program; r; r = r->next_program) {
				if (r->nested_level >= q->nested_level) {
					continue;
				}
				for (i = COB_OPEN_INPUT; i <= COB_OPEN_EXTEND; ++i) {
					hstr1 = &q->global_handler[i];
					hstr2 = &r->global_handler[i];
					if (!hstr1->handler_label &&
					    hstr2->handler_label &&
					    hstr2->handler_label->flag_global) {
						hstr1->handler_label = hstr2->handler_label;
						hstr1->handler_prog = r;
					}
				}
				if (!r->nested_level) {
					break;
				}
			}
		}
	}

	if (verbose_output) {
		fputs (_("Translating:"), stderr);
		fprintf (stderr, "\t%s -> %s (%s)\n",
			 fn->preprocess, fn->translate, fn->source);
		fflush (stderr);
	}

	/* Open the output file */
	yyout = fopen (fn->translate, "w");
	if (!yyout) {
		cobc_terminate (fn->translate);
	}

	/* Open the common storage file */
	cb_storage_file_name = fn->trstorage;
	cb_storage_file = fopen (cb_storage_file_name, "w");
	if (!cb_storage_file) {
		cobc_terminate (cb_storage_file_name);
	}

	p = program_list_reverse (current_program);

	/* Set up local storage files */
	ret = 1;
	for (q = p; q; q = q->next_program, ret++) {
		lf = cobc_main_malloc (sizeof(struct local_filename));
		lf->local_name = cobc_main_malloc (fn->translate_len + 12U);
		if (q == p && !q->next_program) {
			sprintf (lf->local_name, "%s.l.h", fn->translate);
		} else {
			sprintf (lf->local_name, "%s.l%d.h", fn->translate, ret);
		}
		lf->local_fp = fopen (lf->local_name, "w");
		if (!lf->local_fp) {
			cobc_terminate (lf->local_name);
		}
		q->local_include = lf;
		lf->next = fn->localfile;
		fn->localfile = lf;
	}

	/* Entries for COMMON programs */
	for (q = p; q; q = q->next_program) {
		i = q->nested_level;
		for (nlp = q->common_prog_list; nlp; nlp = nlp->next) {
			for (r = q->next_program; r; r = r->next_program) {
				if (r->nested_level <= i) {
					break;
				}
				cb_insert_common_prog (r, nlp->nested_prog);
			}
		}
	}

	errorcount = 0;
	/* Translate to C */
	codegen (p, 0);

	/* Close files */
	fclose (cb_storage_file);
	cb_storage_file = NULL;
	fclose (yyout);
	yyout = NULL;
	for (q = p; q; q = q->next_program) {
		fclose (q->local_include->local_fp);
		q->local_include->local_fp = NULL;
	}
	return !!errorcount;
}

/* Create single-element assembly source */

static int
process_compile (struct filename *fn)
{
	char	*name;
	size_t	bufflen;
	size_t	size;

	if (output_name) {
		name = output_name;
	} else {
		name = file_basename (fn->source);
#ifndef	_MSC_VER
		strcat (name, ".s");
#endif
	}
	size = strlen (name);
#ifdef	_MSC_VER
	size *= 2U;
#endif

	bufflen = cobc_cc_len + cobc_cflags_len
			+ size + fn->translate_len
			+ cobc_include_len + 64U;

	cobc_chk_buff_size (bufflen);

#ifdef	_MSC_VER
	sprintf (cobc_buffer, gflag_set ?
		"%s /c %s %s /Od /MDd /Zi /FR /c /Fa\"%s\" /Fo\"%s\" \"%s\"" :
		"%s /c %s %s /MD /c /Fa\"%s\" /Fo\"%s\" \"%s\"",
			cobc_cc, cobc_cflags, cobc_include, name,
			name, fn->translate);
#elif defined(__WATCOMC__)
	sprintf (cobc_buffer, "%s -fe=\"%s\" -s %s %s %s", cobc_cc, name,
			cobc_cflags, cobc_include, fn->translate);
#else
	sprintf (cobc_buffer, "%s -S -o \"%s\" %s %s %s", cobc_cc, name,
			cobc_cflags, cobc_include, fn->translate);
#endif
	return process (cobc_buffer);
}

/* Create single-element assembled object */

static int
process_assemble (struct filename *fn)
{
	size_t		bufflen;
#ifdef	__OS400__
	char	*name;
#endif

	bufflen = cobc_cc_len + cobc_cflags_len + fn->object_len
			+ fn->translate_len + cobc_include_len
			+ cobc_pic_flags_len + 64U;

	cobc_chk_buff_size (bufflen);

#ifdef	_MSC_VER
	sprintf (cobc_buffer, gflag_set ?
		"%s /c %s %s /Od /MDd /Zi /FR /Fo\"%s\" \"%s\"" :
		"%s /c %s %s /MD /Fo\"%s\" \"%s\"",
			cobc_cc, cobc_cflags, cobc_include,
			fn->object, fn->translate);
#elif defined(__OS400__)
	name = (char *) fn->translate;
	if (name[0] != '/') {
		char	*p;

		p = cobc_main_malloc (COB_LARGE_BUFF);
		getcwd (p, COB_LARGE_BUFF);
		strcat (p, "/");
		strcat (p, name);
		name = p;
	}
	file_stripext ((char *) fn->object);
	sprintf (cobc_buffer, "%s -c %s %s -o %s %s",
		 cobc_cc, cobc_cflags, cobc_include,
		 fn->object, name);
#elif defined(__WATCOMC__)
	if (cb_compile_level == CB_LEVEL_MODULE ||
	    cb_compile_level == CB_LEVEL_LIBRARY) {
		sprintf (cobc_buffer, "%s -c %s %s %s -fe=\"%s\" \"%s\"",
			 cobc_cc, cobc_cflags, cobc_include,
			 COB_PIC_FLAGS, fn->object, fn->translate);
	} else {
		sprintf (cobc_buffer, "%s -c %s %s -fe=\"%s\" \"%s\"",
			 cobc_cc, cobc_cflags, cobc_include,
			 fn->object, fn->translate);
	}
#else
	if (cb_compile_level == CB_LEVEL_MODULE ||
	    cb_compile_level == CB_LEVEL_LIBRARY) {
		sprintf (cobc_buffer, "%s -c %s %s %s -o \"%s\" \"%s\"",
			 cobc_cc, cobc_cflags, cobc_include,
			 COB_PIC_FLAGS, fn->object, fn->translate);
	} else {
		sprintf (cobc_buffer, "%s -c %s %s -o \"%s\" \"%s\"",
			 cobc_cc, cobc_cflags, cobc_include,
			 fn->object, fn->translate);
	}
#endif
	return process (cobc_buffer);
}

/* Create single-element loadable object without intermediate stages */

static int
process_module_direct (struct filename *fn)
{
	char	*name;
	size_t	bufflen;
	size_t	size;
	int	ret;

	if (output_name) {
		name = output_name_buff;
		strcpy (name, output_name);
#if	defined(_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
		file_stripext (name);
#else
		if (strchr (output_name, '.') == NULL) {
			strcat (name, ".");
			strcat (name, COB_MODULE_EXT);
		}
#endif
	} else {
		name = file_basename (fn->source);
#if	!defined(_MSC_VER) && !defined(__OS400__) && !defined(__WATCOMC__) && !defined(__BORLANDC__)
		strcat (name, ".");
		strcat (name, COB_MODULE_EXT);
#endif
	}

	size = strlen (name);
#ifdef	_MSC_VER
	size *= 2U;
#endif

	bufflen = cobc_cc_len + cobc_cflags_len
			+ cobc_export_dyn_len + cobc_shared_opt_len
			+ size + fn->translate_len
			+ cobc_libs_len + cobc_ldflags_len + cobc_include_len
#ifdef	_MSC_VER
			+ manilink_len
#endif
			+ cobc_lib_paths_len + cobc_pic_flags_len + 128U;

	cobc_chk_buff_size (bufflen);

#ifdef	_MSC_VER
	sprintf (cobc_buffer, gflag_set ?
		"%s %s %s /Od /MDd /LDd /Zi /FR /Fe\"%s\" /Fo\"%s\" \"%s\" %s %s %s %s" :
		"%s %s %s /MD /LD /Fe\"%s\" /Fo\"%s\" \"%s\" %s %s %s %s",
			cobc_cc, cobc_cflags, cobc_include, name, name,
			fn->translate, cobc_libs,
			manilink, cobc_ldflags, cobc_lib_paths);
	ret = process (cobc_buffer);
#if	_MSC_VER >= 1400
	/* Embedding manifest */
	if (ret == 0) {
		sprintf (cobc_buffer,
			 "%s /manifest \"%s.dll.manifest\" /outputresource:\"%s.dll\";#2",
			 manicmd, name, name);
		ret = process (cobc_buffer);
		sprintf (cobc_buffer, "%s.dll.manifest", name);
		cobc_check_action (cobc_buffer);
	}
#endif
	sprintf (cobc_buffer, "%s.exp", name);
	cobc_check_action (cobc_buffer);
	sprintf (cobc_buffer, "%s.lib", name);
	cobc_check_action (cobc_buffer);
#else	/* _MSC_VER */
#ifdef	__OS400__
	if (fn->translate[0] != '/') {
		char	*p;

		p = cobc_main_malloc (COB_LARGE_BUFF);
		getcwd (p, COB_LARGE_BUFF);
		strcat (p, "/");
		strcat (p, fn->translate);
		fn->translate = p;
		fn->translate_len = strlen (p);
	}
#endif
#ifdef	__WATCOMC__
	sprintf (cobc_buffer, "%s %s %s %s %s %s -fe=\"%s\" \"%s\" %s %s %s",
		 cobc_cc, cobc_cflags, cobc_include, COB_SHARED_OPT,
		 COB_PIC_FLAGS, COB_EXPORT_DYN, name,
		 fn->translate, cobc_ldflags, cobc_libs, cobc_lib_paths);
#else
	sprintf (cobc_buffer, "%s %s %s %s %s %s -o \"%s\" \"%s\" %s %s %s",
		 cobc_cc, cobc_cflags, cobc_include, COB_SHARED_OPT,
		 COB_PIC_FLAGS, COB_EXPORT_DYN, name,
		 fn->translate, cobc_ldflags, cobc_libs, cobc_lib_paths);
#endif
	ret = process (cobc_buffer);
#ifdef	COB_STRIP_CMD
	if (strip_output && ret == 0) {
		sprintf (cobc_buffer, "%s \"%s\"", COB_STRIP_CMD, name);
		ret = process (cobc_buffer);
	}
#endif
#endif	/* _MSC_VER */
	return ret;
}

/* Create single-element loadable object */

static int
process_module (struct filename *fn)
{
	char	*name;
	size_t	bufflen;
	size_t	size;
	int	ret;

	if (output_name) {
		name = output_name_buff;
		strcpy (name, output_name);
#if	defined(_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
		file_stripext (name);
#else
		if (strchr (output_name, '.') == NULL) {
			strcat (name, ".");
			strcat (name, COB_MODULE_EXT);
		}
#endif
	} else {
		name = file_basename (fn->source);
#if	!defined(_MSC_VER) && !defined(__OS400__) && !defined(__WATCOMC__) &&! defined(__BORLANDC__)
		strcat (name, ".");
		strcat (name, COB_MODULE_EXT);
#endif
	}

	size = strlen (name);
	bufflen = cobc_cc_len + cobc_ldflags_len
			+ cobc_export_dyn_len + cobc_shared_opt_len
			+ size + fn->object_len + cobc_libs_len
#ifdef	_MSC_VER
			+ manilink_len
#endif
			+ cobc_lib_paths_len + cobc_pic_flags_len + 128U;

	cobc_chk_buff_size (bufflen);

#ifdef	_MSC_VER
	sprintf (cobc_buffer, gflag_set ?
		"%s /Od /MDd /LDd /Zi /FR /Fe\"%s\" \"%s\" %s %s %s %s" :
		"%s /MD /LD /Fe\"%s\" \"%s\" %s %s %s %s",
		cobc_cc, name, fn->object, cobc_libs,
		manilink, cobc_ldflags, cobc_lib_paths);
	ret = process (cobc_buffer);
#if	_MSC_VER >= 1400
	/* Embedding manifest */
	if (ret == 0) {
		sprintf (cobc_buffer,
			 "%s /manifest \"%s.dll.manifest\" /outputresource:\"%s.dll\";#2",
			 manicmd, name, name);
		ret = process (cobc_buffer);
		sprintf (cobc_buffer, "%s.dll.manifest", name);
		cobc_check_action (cobc_buffer);
	}
#endif
	sprintf (cobc_buffer, "%s.exp", name);
	cobc_check_action (cobc_buffer);
	sprintf (cobc_buffer, "%s.lib", name);
	cobc_check_action (cobc_buffer);
#else	/* _MSC_VER */
#ifdef	__WATCOMC__
	sprintf (cobc_buffer, "%s %s %s %s -fe=\"%s\" \"%s\" %s %s %s",
		 cobc_cc, COB_SHARED_OPT, COB_PIC_FLAGS, COB_EXPORT_DYN,
		 name, fn->object, cobc_ldflags, cobc_libs, cobc_lib_paths);
#else
	sprintf (cobc_buffer, "%s %s %s %s -o \"%s\" \"%s\" %s %s %s",
		 cobc_cc, COB_SHARED_OPT, COB_PIC_FLAGS, COB_EXPORT_DYN,
		 name, fn->object, cobc_ldflags, cobc_libs, cobc_lib_paths);
#endif
	ret = process (cobc_buffer);
#ifdef	COB_STRIP_CMD
	if (strip_output && ret == 0) {
		sprintf (cobc_buffer, "%s %s", COB_STRIP_CMD, name);
		ret = process (cobc_buffer);
	}
#endif
#endif	/* _MSC_VER */
	return ret;
}

/* Create multi-element loadable object */

static int
process_library (struct filename *l)
{
	struct filename	*f;
	char		*name;
	size_t		bufflen;
	size_t		size;
	int		ret;

	for (f = l; f; f = f->next) {
		strcat (cobc_objects_buffer, "\"");
		strcat (cobc_objects_buffer, f->object);
		strcat (cobc_objects_buffer, "\" ");
	}

	if (output_name) {
		name = output_name_buff;
		strcpy (name, output_name);
#if	defined(_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
		file_stripext (name);
#else
		if (strchr (output_name, '.') == NULL) {
			strcat (name, ".");
			strcat (name, COB_MODULE_EXT);
		}
#endif
	} else {
		name = file_basename (l->source);
#if	!defined(_MSC_VER) && !defined(__OS400__) && !defined(__WATCOMC__) && !defined(__BORLANDC__)
		strcat (name, ".");
		strcat (name, COB_MODULE_EXT);
#endif
	}

	size = strlen (name);
	bufflen = cobc_cc_len + cobc_ldflags_len
			+ cobc_export_dyn_len + cobc_shared_opt_len
			+ size + cobc_objects_len + cobc_libs_len
#ifdef	_MSC_VER
			+ manilink_len
#endif
			+ cobc_lib_paths_len + cobc_pic_flags_len + 64U;
	cobc_chk_buff_size (bufflen);

#ifdef	_MSC_VER
	sprintf (cobc_buffer, gflag_set ?
		"%s /Od /MDd /LDd /Zi /FR /Fe\"%s\" %s %s %s %s %s" :
		"%s /MD /LD /Fe\"%s\" %s %s %s %s %s",
		cobc_cc, name, cobc_objects_buffer, cobc_libs,
		manilink, cobc_ldflags, cobc_lib_paths);
	ret = process (cobc_buffer);
#if	_MSC_VER >= 1400
	/* Embedding manifest */
	if (ret == 0) {
		sprintf (cobc_buffer,
			 "%s /manifest \"%s.dll.manifest\" /outputresource:\"%s.dll\";#2",
			 manicmd, name, name);
		ret = process (cobc_buffer);
		sprintf (cobc_buffer, "%s.dll.manifest", name);
		cobc_check_action (cobc_buffer);
	}
	sprintf (cobc_buffer, "%s.exp", name);
	cobc_check_action (cobc_buffer);
	sprintf (cobc_buffer, "%s.lib", name);
	cobc_check_action (cobc_buffer);
#endif
#else	/* _MSC_VER */
#ifdef	__WATCOMC__
	sprintf (cobc_buffer, "%s %s %s %s -fe=\"%s\" %s %s %s %s",
		 cobc_cc, COB_SHARED_OPT, COB_PIC_FLAGS,
		 COB_EXPORT_DYN, name, cobc_objects_buffer,
		 cobc_ldflags, cobc_libs, cobc_lib_paths);
#else
	sprintf (cobc_buffer, "%s %s %s %s -o \"%s\" %s %s %s %s",
		 cobc_cc, COB_SHARED_OPT, COB_PIC_FLAGS,
		 COB_EXPORT_DYN, name, cobc_objects_buffer,
		 cobc_ldflags, cobc_libs, cobc_lib_paths);
#endif
	ret = process (cobc_buffer);
#ifdef	COB_STRIP_CMD
	if (strip_output && ret == 0) {
		sprintf (cobc_buffer, "%s \"%s\"", COB_STRIP_CMD, name);
		ret = process (cobc_buffer);
	}
#endif
#endif	/* _MSC_VER */
	return ret;
}

/* Create executable */

static int
process_link (struct filename *l)
{
	struct filename	*f;
	char		*name;
	size_t		bufflen;
	size_t		size;
	int		ret;

	for (f = l; f; f = f->next) {
#ifdef	__OS400__
		file_stripext ((char *) f->object);
		strcat (cobc_objects_buffer, f->object);
		strcat (cobc_objects_buffer, " ");
#else
		strcat (cobc_objects_buffer, "\"");
		strcat (cobc_objects_buffer, f->object);
		strcat (cobc_objects_buffer, "\" ");
#endif
	}

	if (output_name) {
#if	defined(_MSC_VER) || defined(__OS400__) || defined(__WATCOMC__) || defined(__BORLANDC__)
		name = cobc_main_strdup (output_name);
		file_stripext (name);
#else
		name = output_name;
#endif
	} else {
		name = file_basename (l->source);
	}

	size = strlen (name);
	bufflen = cobc_cc_len + cobc_ldflags_len
			+ cobc_export_dyn_len + size
			+ cobc_objects_len + cobc_libs_len
#ifdef	_MSC_VER
			+ manilink_len
#endif
			+ cobc_lib_paths_len + 64U;

	cobc_chk_buff_size (bufflen);

#ifdef	_MSC_VER
	sprintf (cobc_buffer, gflag_set ?
		"%s /Od /MDd /Zi /FR /Fe\"%s\" %s %s %s %s %s" :
		"%s /MD /Fe\"%s\" %s %s %s %s %s",
		cobc_cc, name, cobc_objects_buffer, cobc_libs,
		manilink, cobc_ldflags, cobc_lib_paths);
	ret = process (cobc_buffer);
#if	_MSC_VER >= 1400
	/* Embedding manifest */
	if (ret == 0) {
		sprintf (cobc_buffer,
			 "%s /manifest \"%s.exe.manifest\" /outputresource:\"%s.exe\";#1",
			 manicmd, name, name);
		ret = process (cobc_buffer);
		sprintf (cobc_buffer, "%s.exe.manifest", name);
		cobc_check_action (cobc_buffer);
	}
#endif
#else	/* _MSC_VER */
#ifdef	__WATCOMC__
	sprintf (cobc_buffer, "%s %s -fe=\"%s\" %s %s %s %s",
		 cobc_cc, COB_EXPORT_DYN, name, cobc_objects_buffer,
		 cobc_ldflags, cobc_libs, cobc_lib_paths);
#else
	sprintf (cobc_buffer, "%s %s -o \"%s\" %s %s %s %s",
		 cobc_cc, COB_EXPORT_DYN, name, cobc_objects_buffer,
		 cobc_ldflags, cobc_libs, cobc_lib_paths);
#endif

	ret = process (cobc_buffer);

#ifdef	__hpux
	if (ret == 0) {
		sprintf (cobc_buffer, "chatr -s +s enable \"%s%s\" 1>/dev/null 2>&1",
			 name, COB_EXEEXT);
		process (cobc_buffer);
	}
#endif

#ifdef	COB_STRIP_CMD
	if (strip_output && ret == 0) {
		sprintf (cobc_buffer, "%s \"%s%s\"",
			 COB_STRIP_CMD, name, COB_EXEEXT);
		ret = process (cobc_buffer);
	}
#endif

#endif	/* _MSC_VER */
	return ret;
}

/* Main function */
int
main (int argc, char **argv)
{
	struct filename		*fn;
	char			*p;
	struct cobc_mem_struct	*mptr;
	struct cobc_mem_struct	*mptrt;
	unsigned int		iparams;
	unsigned int		local_level;
	int			status;
	int			year;
	int			day;
	int			i;
	char			month[32];
#if	defined(HAVE_SIGNAL_H) && defined(HAVE_SIGACTION)
	struct sigaction	sa;
	struct sigaction	osa;
#endif

	file_list = NULL;
	cb_listing_file = NULL;
	ppin = NULL;
	ppout = NULL;
	yyin = NULL;
	yyout = NULL;

#ifdef	HAVE_SIGNAL_H

#ifdef	HAVE_SIGACTION
	memset (&sa, 0, sizeof(sa));
	sa.sa_handler = cobc_sig_handler;
#ifdef	SA_RESETHAND
	sa.sa_flags = SA_RESETHAND;
#else
	sa.sa_flags = 0;
#endif
#ifdef	SA_NOCLDSTOP
	sa.sa_flags |= SA_NOCLDSTOP;
#endif
#ifdef	SIGINT
	(void)sigaction (SIGINT, NULL, &osa);
	if (osa.sa_handler != SIG_IGN) {
		(void)sigemptyset (&sa.sa_mask);
		(void)sigaction (SIGINT, &sa, NULL);
	}
#endif
#ifdef	SIGHUP
	(void)sigaction (SIGHUP, NULL, &osa);
	if (osa.sa_handler != SIG_IGN) {
		(void)sigemptyset (&sa.sa_mask);
		(void)sigaction (SIGHUP, &sa, NULL);
	}
#endif
#ifdef	SIGQUIT
	(void)sigaction (SIGQUIT, NULL, &osa);
	if (osa.sa_handler != SIG_IGN) {
		(void)sigemptyset (&sa.sa_mask);
		(void)sigaction (SIGQUIT, &sa, NULL);
	}
#endif
#ifdef	SIGTERM
	(void)sigaction (SIGTERM, NULL, &osa);
	if (osa.sa_handler != SIG_IGN) {
		(void)sigemptyset (&sa.sa_mask);
		(void)sigaction (SIGTERM, &sa, NULL);
	}
#endif
#ifdef	SIGPIPE
	(void)sigaction (SIGPIPE, NULL, &osa);
	if (osa.sa_handler != SIG_IGN) {
		(void)sigemptyset (&sa.sa_mask);
		(void)sigaction (SIGPIPE, &sa, NULL);
	}
#endif
#ifdef	SIGSEGV
	/* Take direct control of segementation violation */
	(void)sigemptyset (&sa.sa_mask);
	(void)sigaction (SIGSEGV, &sa, NULL);
#endif

#else

#ifdef	SIGINT
	if (signal (SIGINT, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGINT, cobc_sig_handler);
	}
#endif
#ifdef	SIGHUP
	if (signal (SIGHUP, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGHUP, cobc_sig_handler);
	}
#endif
#ifdef	SIGQUIT
	if (signal (SIGQUIT, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGQUIT, cobc_sig_handler);
	}
#endif
#ifdef	SIGTERM
	if (signal (SIGTERM, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGTERM, cobc_sig_handler);
	}
#endif
#ifdef	SIGPIPE
	if (signal (SIGPIPE, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGPIPE, cobc_sig_handler);
	}
#endif
	/* Take direct control of segmentation violation */
#ifdef	SIGSEGV
	(void)signal (SIGSEGV, cobc_sig_handler);
#endif
#endif

#endif

	cb_saveargc = argc;
	cb_saveargv = argv;

	/* General buffers */
	cobc_buffer = cobc_main_malloc ((size_t)COB_LARGE_BUFF);
	cobc_buffer_size = COB_LARGE_MAX;
	basename_buffer = cobc_main_malloc ((size_t)COB_MINI_BUFF);
	basename_len = COB_MINI_MAX - 16;

	cobc_libs = cobc_main_malloc ((size_t)COB_SMALL_BUFF);
	cobc_lib_paths = cobc_main_malloc ((size_t)COB_SMALL_BUFF);
	cobc_cflags = cobc_main_malloc ((size_t)COB_MINI_BUFF);
	cobc_ldflags = cobc_main_malloc ((size_t)COB_MINI_BUFF);
	cobc_include = cobc_main_malloc ((size_t)COB_MINI_BUFF);

	cobc_libs_size = COB_SMALL_MAX;
	cobc_lib_paths_size = COB_SMALL_MAX;
	cobc_cflags_size = COB_MINI_MAX;
	cobc_include_size = COB_MINI_MAX;
	cobc_ldflags_size = COB_MINI_MAX;

	cb_source_file = NULL;
	save_temps_dir = NULL;
	base_string = NULL;
	cobc_objects_len = 0;
	cb_id = 1;
	cb_attr_id = 1;
	cb_literal_id = 1;
	cb_field_id = 1;
#ifdef	COB_EBCDIC_MACHINE
	cb_ebcdic_sign = 1;
#else
	cb_ebcdic_sign = 0;
#endif

#ifdef	_WIN32
	/* Allows running tests under Win */
	p = getenv ("COB_UNIX_LF");
	if (p && (*p == 'Y' || *p == 'y' || *p == '1')) {
		_setmode (_fileno (stdin), _O_BINARY);
		_setmode (_fileno (stdout), _O_BINARY);
		_setmode (_fileno (stderr), _O_BINARY);
	}
#endif

#ifdef	HAVE_SETLOCALE
	setlocale (LC_ALL, "");
	setlocale (LC_NUMERIC, "C");
#endif

#ifdef	ENABLE_NLS
	bindtextdomain (PACKAGE, LOCALEDIR);
	textdomain (PACKAGE);
#endif

#ifndef _WIN32
	cob_process_id = getpid ();
#endif

	/* Initialize variables */

	/* Set up build time stamp */
	memset (month, 0, sizeof(month));
	day = 0;
	year = 0;
	sscanf (__DATE__, "%s %d %d", month, &day, &year);
	if (day && year) {
		snprintf (cobc_buffer, (size_t)COB_MINI_MAX,
			  "%s %2.2d %4.4d %s", month, day, year, __TIME__);
	} else {
		snprintf (cobc_buffer, (size_t)COB_MINI_MAX,
			  "%s %s", __DATE__, __TIME__);
	}
	cb_oc_build_stamp = cobc_main_strdup (cobc_buffer);

	output_name = NULL;

	if ((p = cobc_getenv ("TMPDIR")) != NULL) {
		cobc_tmpdir = p;
	} else if ((p = cobc_getenv ("TMP")) != NULL ||
		   (p = cobc_getenv ("TEMP")) != NULL) {
		cobc_tmpdir = p;
		p = cobc_main_malloc (strlen (cobc_tmpdir) + 10);
		sprintf (p, "TMPDIR=%s", cobc_tmpdir);
		putenv (p);
	} else {
		cobc_tmpdir = "/tmp";
		putenv ((char *)"TMPDIR=/tmp");
	}

	cobc_cc = cobc_getenv ("COB_CC");
	if (cobc_cc == NULL) {
		cobc_cc = COB_CC;
	}

	cob_config_dir = cobc_getenv ("COB_CONFIG_DIR");
	if (cob_config_dir == NULL) {
		cob_config_dir = COB_CONFIG_DIR;
	}

	p = cobc_getenv ("COB_CFLAGS");
	if (p) {
		COBC_ADD_STR (cobc_cflags, p, NULL, NULL);
	} else {
		COBC_ADD_STR (cobc_cflags, COB_CFLAGS, NULL, NULL);
	}

	p = cobc_getenv ("COB_LDFLAGS");
	if (p) {
		COBC_ADD_STR (cobc_ldflags, p, NULL, NULL);
	} else {
		COBC_ADD_STR (cobc_ldflags, COB_LDFLAGS, NULL, NULL);
	}

	p = cobc_getenv ("COB_LIBS");
	if (p) {
		COBC_ADD_STR (cobc_libs, p, NULL, NULL);
	} else {
		COBC_ADD_STR (cobc_libs, COB_LIBS, NULL, NULL);
	}

	p = cobc_getenv ("COB_LDADD");
	if (p) {
		COBC_ADD_STR (cobc_libs, " ", p, NULL);
	}

	p = cobc_getenv ("COB_LIB_PATHS");
	if (p) {
		COBC_ADD_STR (cobc_lib_paths, p, NULL, NULL);
	} else {
		COBC_ADD_STR (cobc_lib_paths, " ", NULL, NULL);
	}

	/* Set default computed goto usage if appropriate */
#ifdef	__GNUC__
	cb_flag_computed_goto = 1;
#elif	defined(__SUNPRO_C) && __SUNPRO_C >= 0x570
	cb_flag_computed_goto = 1;
#elif	defined(__xlc__) && defined(__IBMC__) && __IBMC__ >= 700
	cb_flag_computed_goto = 1;
	COBC_ADD_STR (cobc_cflags, " -qlanglvl=extended",
		      NULL, NULL);
#endif

	/* Compiler special options */

#ifdef	__WATCOMC__
	/* -s = no overflow checks, otherwise need to code/link a CHK routine */
	COBC_ADD_STR (cobc_cflags, " -s -wcd=118", NULL, NULL);
#endif

#ifdef	__INTEL_COMPILER
	COBC_ADD_STR (cobc_cflags, " -vec-report0 -opt-report 0",
		      NULL, NULL);
#elif	defined(__GNUC__)
#if	0	/* RXWRXW - gcse */
	COBC_ADD_STR (cobc_cflags, " -Wno-unused -fsigned-char -fno-gcse",
		      NULL, NULL);
#else
	COBC_ADD_STR (cobc_cflags, " -Wno-unused -fsigned-char",
		      NULL, NULL);
#endif
	/* --param max-goto-duplication-insns=100000 */
#ifdef	HAVE_PSIGN_OPT
	COBC_ADD_STR (cobc_cflags, " -Wno-pointer-sign", NULL, NULL);
#endif

#elif defined(__xlc__)
	COBC_ADD_STR (cobc_cflags, " -qro -qroconst",
		      NULL, NULL);
#endif

	/* Enable default I/O exceptions */
	CB_EXCEPTION_ENABLE (COB_EC_I_O) = 1;

	/* Process command line arguments */
	iargs = process_command_line (argc, argv);

	/* Check the filename */
	if (iargs == argc) {
		cobc_err_exit (_("No input files"));
	}

	/* Windows stuff reliant upon verbose option */
#ifdef	_MSC_VER
	if (!verbose_output) {
		COBC_ADD_STR (cobc_cflags, " /nologo", NULL, NULL);
	}
#if	_MSC_VER >= 1400
	if (!verbose_output) {
		manicmd = "mt /nologo";
		manilink = "/link /nologo /manifest";
	} else {
		manicmd = "mt";
		manilink = "/link /manifest";
	}
#else
	manilink = "/link";
#endif
	manilink_len = strlen (manilink);
#endif

#ifdef	__WATCOMC__
	if (!verbose_output) {
		COBC_ADD_STR (cobc_cflags, " -q", NULL, NULL);
	}
#endif

#if	0	/* gcc opts */

#if	defined(__GNUC__) && !defined (__INTEL_COMPILER)
	if (!gflag_set && !cobc_wants_debug && !aflag_set) {
		COBC_ADD_STR (cobc_cflags, " -fomit-frame-pointer",
			      " -fno-asynchronous-unwind-tables",
			      " -U_FORTIFY_SOURCE");
#if	0	/* RXWRXW - Default opt */
		if (!cob_optimize) {
			COBC_ADD_STR (cobc_cflags, CB_COPT_1, NULL, NULL);
		}
#endif
#ifdef	HAVE_UNWIND_OPT
#endif
	}
#endif

#endif

	/* Append default extensions */
	CB_TEXT_LIST_ADD (cb_extension_list, ".CPY");
	CB_TEXT_LIST_ADD (cb_extension_list, ".CBL");
	CB_TEXT_LIST_ADD (cb_extension_list, ".COB");
	CB_TEXT_LIST_ADD (cb_extension_list, ".cpy");
	CB_TEXT_LIST_ADD (cb_extension_list, ".cbl");
	CB_TEXT_LIST_ADD (cb_extension_list, ".cob");
	CB_TEXT_LIST_ADD (cb_extension_list, "");

	/* Process COB_COPY_DIR and COBCPY environment variables */
	process_env_copy_path (getenv ("COB_COPY_DIR"));
	process_env_copy_path (getenv ("COBCPY"));

	/* Add default COB_COPY_DIR directory */
	CB_TEXT_LIST_CHK (cb_include_list, COB_COPY_DIR);

	/* Defaults are set here */
	if (!cb_flag_syntax_only) {
		if (!wants_nonfinal) {
			if (cobc_flag_main) {
				cb_compile_level = CB_LEVEL_EXECUTABLE;
			} else if (cobc_flag_module) {
				cb_compile_level = CB_LEVEL_MODULE;
			} else if (cobc_flag_library) {
				cb_compile_level = CB_LEVEL_LIBRARY;
			} else if (cb_compile_level == 0) {
				cb_compile_level = CB_LEVEL_MODULE;
				cobc_flag_module = 1;
			}
		}
		if (wants_nonfinal && cb_compile_level != CB_LEVEL_PREPROCESS &&
		    !cobc_flag_main && !cobc_flag_module && !cobc_flag_library) {
			cobc_flag_module = 1;
		}
	} else {
		cb_compile_level = CB_LEVEL_TRANSLATE;
		cobc_flag_main = 0;
		cobc_flag_module = 0;
		cobc_flag_library = 0;
	}

	if (output_name && cb_compile_level < CB_LEVEL_LIBRARY &&
	    (argc - iargs) > 1) {
		cobc_err_exit (_("-o option invalid in this combination"));
	}

	if (cb_flag_notrunc) {
		cb_binary_truncate = 0;
		cb_pretty_display = 0;
	}

	/* Compiler initialization */
#ifndef	HAVE_DESIGNATED_INITS
	cobc_init_scanner ();
	cobc_init_reserved ();
	cobc_init_typeck ();
#endif

	/* If -P=file specified, all lists go to this file */
	if (cobc_list_file) {
		cb_listing_file = fopen (cobc_list_file, "w");
		if (!cb_listing_file) {
			cobc_terminate (cobc_list_file);
		}
	}

	if (verbose_output) {
		fputs (_("Command line:\t"), stderr);
		for (i = 0; i < argc; ++i) {
			fprintf (stderr, "%s ", argv[i]);
		}
		putc ('\n', stderr);
		fflush (stderr);
	}

	cobc_cc_len = strlen (cobc_cc);
	cobc_cflags_len = strlen (cobc_cflags);
	cobc_libs_len = strlen (cobc_libs);
	cobc_lib_paths_len = strlen (cobc_lib_paths);
	cobc_include_len = strlen (cobc_include);
	cobc_ldflags_len = strlen (cobc_ldflags);
	cobc_export_dyn_len = strlen (COB_EXPORT_DYN);
	cobc_shared_opt_len = strlen (COB_SHARED_OPT);
	cobc_pic_flags_len = strlen (COB_PIC_FLAGS);

	/* Process input files */
	status = 0;
	iparams = 0;
	local_level = 0;
	while (iargs < argc) {
		/* Set up file parameters */
		fn = process_filename (argv[iargs++]);
		if (!fn) {
			cobc_clean_up (1);
			return 1;
		}
		cb_id = 1;
		cb_attr_id = 1;
		cb_literal_id = 1;
		cb_field_id = 1;
		demangle_name = fn->demangle_source;
		memset (optimize_defs, 0, sizeof(optimize_defs));
		iparams++;
		if (iparams > 1 && cb_compile_level == CB_LEVEL_EXECUTABLE) {
			local_level = cb_compile_level;
			cb_compile_level = CB_LEVEL_ASSEMBLE;
			cobc_flag_main = 0;
		}

		if (cb_compile_level >= CB_LEVEL_PREPROCESS &&
		    fn->need_preprocess) {
			/* Preprocess */
			fn->has_error = preprocess (fn);
			status |= fn->has_error;
		}
		if (cobc_list_file) {
			putc ('\n', cb_listing_file);
		}

		if (cb_compile_level < CB_LEVEL_TRANSLATE || fn->has_error) {
			continue;
		}
		if (fn->need_translate) {
			/* Parse / Translate (to C code) */
			fn->has_error = process_translate (fn);
			status |= fn->has_error;
			/* Free parse memory */
			for (mptr = cobc_parsemem_base; mptr; ) {
				mptrt = mptr;
				mptr = mptr->next;
				free (mptrt);
			}
			cobc_parsemem_base = NULL;
		}
		if (cb_compile_level < CB_LEVEL_COMPILE ||
		    cb_flag_syntax_only || fn->has_error) {
			continue;
		}
		if (cb_compile_level == CB_LEVEL_COMPILE) {
			/* Compile to assembler code */
			fn->has_error = process_compile (fn);
			status |= fn->has_error;
			continue;
		}

		if (cb_compile_level == CB_LEVEL_MODULE && fn->need_assemble) {
			/* Build module direct */
			fn->has_error = process_module_direct (fn);
			status |= fn->has_error;
		} else {
			/* Compile to object code */
			if (cb_compile_level >= CB_LEVEL_ASSEMBLE &&
			    fn->need_assemble) {
				fn->has_error = process_assemble (fn);
				status |= fn->has_error;
			}
			if (fn->has_error) {
				continue;
			}

			/* Build module */
			if (cb_compile_level == CB_LEVEL_MODULE) {
				fn->has_error = process_module (fn);
				status |= fn->has_error;
			}
		}
	}

	if (cobc_list_file) {
		fclose (cb_listing_file);
		cb_listing_file = NULL;
	}

	/* Clear rest of preprocess stuff */
	plex_clear_all ();

	/* Clear rest of parser stuff */
	ylex_clear_all ();

	if (local_level == CB_LEVEL_EXECUTABLE) {
		cb_compile_level = CB_LEVEL_EXECUTABLE;
	}

	if (cb_compile_level < CB_LEVEL_LIBRARY ||
	    status || cb_flag_syntax_only) {
		/* Finished */
		cobc_clean_up (status);
		return status;
	}

	/* Allocate objects buffer */
	cobc_objects_buffer = cobc_main_malloc (cobc_objects_len);

	/* Link */
	if (cb_compile_level == CB_LEVEL_LIBRARY) {
		/* Multi-program module */
		status = process_library (file_list);
	} else {
		/* Executable */
		status = process_link (file_list);
	}

	/* We have completed */
	cobc_clean_up (status);

	return status;
}
