/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While

   This file is part of GNU Cobol.

   The GNU Cobol runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GNU Cobol.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "config.h"
#include "defaults.h"
#include "tarstamp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#include <math.h>
#ifdef HAVE_FINITE_IEEEFP_H
#include <ieeefp.h>
#endif

#include <time.h>

#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef	HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef	_WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>
#include <io.h>
#include <fcntl.h>
#endif

#ifdef	HAVE_SIGNAL_H
#include <signal.h>
#endif

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

#include "libcob/cobgetopt.h"

#define	CB_IMSG_SIZE	24
#define	CB_IVAL_SIZE	(80 - CB_IMSG_SIZE - 4)

/* Stringify macros */
#define CB_STRINGIFY(s)			#s
#define CB_XSTRINGIFY(s)		CB_STRINGIFY(s)

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

struct cob_alloc_cache {
	struct cob_alloc_cache	*next;		/* Pointer to next */
	void			*cob_pointer;	/* Pointer to malloced space */
	size_t			size;		/* Item size */
};

/* EXTERNAL structure */

struct cob_external {
	struct cob_external	*next;		/* Pointer to next */
	void			*ext_alloc;	/* Pointer to malloced space */
	char			*ename;		/* External name */
	int			esize;		/* Item size */
};

#define COB_ERRBUF_SIZE		1024

/* Local variables */

static int			cob_initialized = 0;
static int			cob_argc;
static char			**cob_argv;
static struct cob_alloc_cache	*cob_alloc_base;
static const char		*cob_last_sfile;

static cob_global		*cobglobptr;
static runtime_env		*runtimeptr;

static char			*runtime_err_str;

static const cob_field_attr	const_alpha_attr =
				{COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL};

static char			*cob_local_env;
static char			*cob_user_name;
static int			current_arg;
static unsigned char		*commlnptr;
static size_t			commlncnt;
static size_t			cob_local_env_size;

static struct cob_external	*basext;

static size_t			sort_nkeys;
static cob_file_key_t  	*sort_keys;
static const unsigned char	*sort_collate;

static const char		*cob_current_program_id;
static const char		*cob_current_section;
static const char		*cob_current_paragraph;
static const char		*cob_source_file;
static const char		*cob_source_statement;
static const char		*cob_trace_env;
static FILE			*cob_trace_file;
static unsigned int		cob_source_line;
static unsigned int		cob_line_trace;

static char				*strbuff = NULL;

#if	defined(HAVE_SIGNAL_H) && defined(HAVE_SIG_ATOMIC_T)
static volatile sig_atomic_t	sig_is_handled = 0;
#endif

/* Function Pointer for external signal handling */
static void		(*cob_ext_sighdl) (int) = NULL;

#undef	COB_EXCEPTION
#define COB_EXCEPTION(code,tag,name,critical)	name,
static const char		* const cob_exception_tab_name[] = {
	"None",		/* COB_EC_ZERO */
#include "exception.def"
	"Invalid"	/* COB_EC_MAX */
};

#undef	COB_EXCEPTION
#define COB_EXCEPTION(code,tag,name,critical)	0x##code,
static const int		cob_exception_tab_code[] = {
	0,		/* COB_EC_ZERO */
#include "exception.def"
	0		/* COB_EC_MAX */
};

#undef	COB_EXCEPTION

#define EXCEPTION_TAB_SIZE	sizeof(cob_exception_tab_code) / sizeof(int)

/* Switches */
#define	COB_SWITCH_MAX	16

static int		cob_switch[COB_SWITCH_MAX];

/* Runtime exit handling */
static struct exit_handlerlist {
	struct exit_handlerlist	*next;
	int			(*proc)(void);
} *exit_hdlrs;

/* Runtime error handling */
static struct handlerlist {
	struct handlerlist	*next;
	int			(*proc)(char *s);
} *hdlrs;


/* Local variables */

static progid_t progid;


/* Local functions */

static void
cob_exit_common (void)
{
	struct cob_external	*p;
	struct cob_external	*q;
	struct cob_alloc_cache	*x;
	struct cob_alloc_cache	*y;

#ifdef	HAVE_SETLOCALE
	if (cobglobptr->cob_locale_orig) {
		(void) setlocale (LC_ALL, cobglobptr->cob_locale_orig);
		free (cobglobptr->cob_locale_orig);
	}
	if (cobglobptr->cob_locale) {
		free (cobglobptr->cob_locale);
	}
	if (cobglobptr->cob_locale_ctype) {
		free (cobglobptr->cob_locale_ctype);
	}
	if (cobglobptr->cob_locale_collate) {
		free (cobglobptr->cob_locale_collate);
	}
	if (cobglobptr->cob_locale_messages) {
		free (cobglobptr->cob_locale_messages);
	}
	if (cobglobptr->cob_locale_monetary) {
		free (cobglobptr->cob_locale_monetary);
	}
	if (cobglobptr->cob_locale_numeric) {
		free (cobglobptr->cob_locale_numeric);
	}
	if (cobglobptr->cob_locale_time) {
		free (cobglobptr->cob_locale_time);
	}
#endif

	if (cob_user_name) {
		free (cob_user_name);
	}
	if (commlnptr) {
		free (commlnptr);
	}
	if (cob_local_env) {
		free (cob_local_env);
	}

	/* Free library routine stuff */

	if (cobglobptr->cob_term_buff) {
		free (cobglobptr->cob_term_buff);
	}

	/* Free cached externals */
	for (p = basext; p;) {
		q = p;
		p = p->next;
		if (q->ename) {
			free (q->ename);
		}
		if (q->ext_alloc) {
			free (q->ext_alloc);
		}
		free (q);
	}

	/* Free cached mallocs */
	for (x = cob_alloc_base; x;) {
		y = x;
		x = x->next;
		free (y->cob_pointer);
		free (y);
	}

	/* Free last stuff */
	if (runtime_err_str) {
		free (runtime_err_str);
	}
	if (cobglobptr) {
		if (cobglobptr->cob_main_argv0) {
			free ((void *)(cobglobptr->cob_main_argv0));
		}
		free (cobglobptr);
	}
	cobglobptr = NULL;
	cob_initialized = 0;
}

static void
cob_terminate_routines (void)
{
	if (!cob_initialized) {
		return;
	}
	if (!cobglobptr) {
		return;
	}

	if (cob_trace_file && cob_trace_file != stderr) {
		fclose (cob_trace_file);
		cob_trace_file = NULL;
	}

	cob_exit_screen ();
	cob_exit_fileio ();
	cob_exit_intrinsic ();
	cob_exit_strings ();
	cob_exit_numeric ();
	cob_exit_call ();
	cob_exit_common ();
}

#ifdef	HAVE_SIGNAL_H
static void COB_A_NORETURN
cob_sig_handler_ex (int sig)
{
	/* call external signal handler if registered */
	if (cob_ext_sighdl != NULL) {
		(*cob_ext_sighdl) (sig);
		cob_ext_sighdl = NULL;
	}
#ifdef	SIGSEGV
	if (sig == SIGSEGV) {
		exit (SIGSEGV);
	}
#endif
#ifdef	HAVE_RAISE
	raise (sig);
#else
	kill (getpid(), sig);
#endif
	exit (sig);
}

static void COB_A_NORETURN
cob_sig_handler (int sig)
{
	const char *signal_name;

#if	defined(HAVE_SIGACTION) && !defined(SA_RESETHAND)
	struct sigaction	sa;
#endif

#ifdef	HAVE_SIG_ATOMIC_T
	if (sig_is_handled) {
		cob_sig_handler_ex(sig);
	}
	sig_is_handled = 1;
#endif

	switch (sig) {
#ifdef	SIGINT
	case SIGINT:
		signal_name = "SIGINT";
		break;
#endif
#ifdef	SIGHUP
	case SIGHUP:
		signal_name = "SIGHUP";
		break;
#endif
#ifdef	SIGQUIT
	case SIGQUIT:
		signal_name = "SIGQUIT";
		break;
#endif
#ifdef	SIGTERM
	case SIGTERM:
		signal_name = "SIGTERM";
		break;
#endif
#ifdef	SIGPIPE
	case SIGPIPE:
		signal_name = "SIGPIPE";
		break;
#endif
#ifdef	SIGSEGV
	case SIGSEGV:
		signal_name = "SIGSEGV";
		break;
#endif
	default:
		signal_name = "unkown";
		fprintf(stderr, "Caught wrong signal: %d\n", sig);
		break;
	}

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
	cob_exit_screen ();
	putc ('\n', stderr);
	if (cob_source_file) {
		fprintf (stderr, "%s: %u: ", cob_source_file, cob_source_line);
	}

#ifdef	SIGSEGV
	if (sig == SIGSEGV) {
		fprintf (stderr, _("Attempt to reference unallocated memory"));
	} else {
		fprintf (stderr, _("Caught Signal"));
	}
#else
	fprintf (stderr, _("Caught Signal"));
#endif
	putc (' ', stderr);
	fprintf (stderr, _("(Signal %s)"), signal_name);
	putc ('\n', stderr);

	if (cob_initialized) {
		cob_terminate_routines ();
		fprintf (stderr, _("Abnormal termination - File contents may be incorrect"));
	}
	putc ('\n', stderr);
	fflush (stderr);

	cob_sig_handler_ex(sig);
}
#endif

static void
cob_set_signal (void)
{
#ifdef	HAVE_SIGNAL_H

#ifdef	HAVE_SIGACTION
	struct sigaction	sa;
	struct sigaction	osa;

	memset (&sa, 0, sizeof(sa));
	sa.sa_handler = cob_sig_handler;
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
	/* Take direct control of segmentation violation */
	(void)sigemptyset (&sa.sa_mask);
	(void)sigaction (SIGSEGV, &sa, NULL);
#endif

#else

#ifdef	SIGINT
	if (signal (SIGINT, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGINT, cob_sig_handler);
	}
#endif
#ifdef	SIGHUP
	if (signal (SIGHUP, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGHUP, cob_sig_handler);
	}
#endif
#ifdef	SIGQUIT
	if (signal (SIGQUIT, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGQUIT, cob_sig_handler);
	}
#endif
#ifdef	SIGTERM
	if (signal (SIGTERM, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGTERM, cob_sig_handler);
	}
#endif
#ifdef	SIGPIPE
	if (signal (SIGPIPE, SIG_IGN) != SIG_IGN) {
		(void)signal (SIGPIPE, cob_sig_handler);
	}
#endif
#ifdef	SIGSEGV
	/* Take direct control of segmentation violation */
	(void)signal (SIGSEGV, cob_sig_handler);
#endif

#endif
#endif
}

/* ASCII Sign
 * positive: 0123456789
 * negative: pqrstuvwxy
 */

static int
cob_get_sign_ascii (unsigned char *p)
{
#ifdef	COB_EBCDIC_MACHINE
	switch (*p) {
	case 'p':
		*p = (unsigned char)'0';
		return -1;
	case 'q':
		*p = (unsigned char)'1';
		return -1;
	case 'r':
		*p = (unsigned char)'2';
		return -1;
	case 's':
		*p = (unsigned char)'3';
		return -1;
	case 't':
		*p = (unsigned char)'4';
		return -1;
	case 'u':
		*p = (unsigned char)'5';
		return -1;
	case 'v':
		*p = (unsigned char)'6';
		return -1;
	case 'w':
		*p = (unsigned char)'7';
		return -1;
	case 'x':
		*p = (unsigned char)'8';
		return -1;
	case 'y':
		*p = (unsigned char)'9';
		return -1;
	}
	*p = (unsigned char)'0';
	return 1;
#else
	if (*p >= (unsigned char)'p' && *p <= (unsigned char)'y') {
		*p &= ~64U;
		return -1;
	}
	*p = (unsigned char)'0';
	return 1;
#endif
}

static void
cob_put_sign_ascii (unsigned char *p)
{
#ifdef	COB_EBCDIC_MACHINE
	switch (*p) {
	case '0':
		*p = (unsigned char)'p';
		return;
	case '1':
		*p = (unsigned char)'q';
		return;
	case '2':
		*p = (unsigned char)'r';
		return;
	case '3':
		*p = (unsigned char)'s';
		return;
	case '4':
		*p = (unsigned char)'t';
		return;
	case '5':
		*p = (unsigned char)'u';
		return;
	case '6':
		*p = (unsigned char)'v';
		return;
	case '7':
		*p = (unsigned char)'w';
		return;
	case '8':
		*p = (unsigned char)'x';
		return;
	case '9':
		*p = (unsigned char)'y';
		return;
	default:
		*p = (unsigned char)'0';
	}
#else
	*p |= 64U;
#endif
}

/* EBCDIC Sign
 * positive: {ABCDEFGHI
 * negative: }JKLMNOPQR
 */

static int
cob_get_sign_ebcdic (unsigned char *p)
{
	switch (*p) {
	case '{':
		*p = (unsigned char)'0';
		return 1;
	case 'A':
		*p = (unsigned char)'1';
		return 1;
	case 'B':
		*p = (unsigned char)'2';
		return 1;
	case 'C':
		*p = (unsigned char)'3';
		return 1;
	case 'D':
		*p = (unsigned char)'4';
		return 1;
	case 'E':
		*p = (unsigned char)'5';
		return 1;
	case 'F':
		*p = (unsigned char)'6';
		return 1;
	case 'G':
		*p = (unsigned char)'7';
		return 1;
	case 'H':
		*p = (unsigned char)'8';
		return 1;
	case 'I':
		*p = (unsigned char)'9';
		return 1;
	case '}':
		*p = (unsigned char)'0';
		return -1;
	case 'J':
		*p = (unsigned char)'1';
		return -1;
	case 'K':
		*p = (unsigned char)'2';
		return -1;
	case 'L':
		*p = (unsigned char)'3';
		return -1;
	case 'M':
		*p = (unsigned char)'4';
		return -1;
	case 'N':
		*p = (unsigned char)'5';
		return -1;
	case 'O':
		*p = (unsigned char)'6';
		return -1;
	case 'P':
		*p = (unsigned char)'7';
		return -1;
	case 'Q':
		*p = (unsigned char)'8';
		return -1;
	case 'R':
		*p = (unsigned char)'9';
		return -1;
	default:
		/* What to do here */
		*p = (unsigned char)('0' + (*p & 0x0F));
		if (*p > (unsigned char)'9') {
			*p = (unsigned char)'0';
		}
		return 1;
	}
}

static void
cob_put_sign_ebcdic (unsigned char *p, const int sign)
{
	if (sign < 0) {
		switch (*p) {
		case '0':
			*p = (unsigned char)'}';
			return;
		case '1':
			*p = (unsigned char)'J';
			return;
		case '2':
			*p = (unsigned char)'K';
			return;
		case '3':
			*p = (unsigned char)'L';
			return;
		case '4':
			*p = (unsigned char)'M';
			return;
		case '5':
			*p = (unsigned char)'N';
			return;
		case '6':
			*p = (unsigned char)'O';
			return;
		case '7':
			*p = (unsigned char)'P';
			return;
		case '8':
			*p = (unsigned char)'Q';
			return;
		case '9':
			*p = (unsigned char)'R';
			return;
		default:
			/* What to do here */
			*p = (unsigned char)'{';
			return;
		}
	}
	switch (*p) {
	case '0':
		*p = (unsigned char)'{';
		return;
	case '1':
		*p = (unsigned char)'A';
		return;
	case '2':
		*p = (unsigned char)'B';
		return;
	case '3':
		*p = (unsigned char)'C';
		return;
	case '4':
		*p = (unsigned char)'D';
		return;
	case '5':
		*p = (unsigned char)'E';
		return;
	case '6':
		*p = (unsigned char)'F';
		return;
	case '7':
		*p = (unsigned char)'G';
		return;
	case '8':
		*p = (unsigned char)'H';
		return;
	case '9':
		*p = (unsigned char)'I';
		return;
	default:
		/* What to do here */
		*p = (unsigned char)'{';
		return;
	}
}

static int
common_cmpc (const unsigned char *s1, const unsigned int c,
	     const size_t size, const unsigned char *col)
{
	size_t			i;
	int			ret;

	if (unlikely(col)) {
		for (i = 0; i < size; ++i) {
			if ((ret = col[s1[i]] - col[c]) != 0) {
				return ret;
			}
		}
	} else {
		for (i = 0; i < size; ++i) {
			if ((ret = s1[i] - c) != 0) {
				return ret;
			}
		}
	}
	return 0;
}

static int
common_cmps (const unsigned char *s1, const unsigned char *s2,
	     const size_t size, const unsigned char *col)
{
	size_t			i;
	int			ret;

	if (unlikely(col)) {
		for (i = 0; i < size; ++i) {
			if ((ret = col[s1[i]] - col[s2[i]]) != 0) {
				return ret;
			}
		}
	} else {
		for (i = 0; i < size; ++i) {
			if ((ret = s1[i] - s2[i]) != 0) {
				return ret;
			}
		}
	}
	return 0;
}

static int
cob_cmp_all (cob_field *f1, cob_field *f2)
{
	unsigned char		*data;
	const unsigned char	*s;
	size_t			size;
	int			ret;
	int			sign;

	size = f1->size;
	data = f1->data;
	sign = COB_GET_SIGN (f1);
	s = COB_MODULE_PTR->collating_sequence;
	if (f2->size == 1) {
		ret = common_cmpc (data, f2->data[0], size, s);
		goto end;
	}
	ret = 0;
	while (size >= f2->size) {
		if ((ret = common_cmps (data, f2->data, f2->size, s)) != 0) {
			goto end;
		}
		size -= f2->size;
		data += f2->size;
	}
	if (size > 0) {
		ret = common_cmps (data, f2->data, size, s);
	}

end:
	if (COB_FIELD_TYPE (f1) != COB_TYPE_NUMERIC_PACKED) {
		COB_PUT_SIGN (f1, sign);
	}
	return ret;
}

static int
cob_cmp_alnum (cob_field *f1, cob_field *f2)
{
	const unsigned char	*s;
	size_t			min;
	int			ret;
	int			sign1;
	int			sign2;

	sign1 = COB_GET_SIGN (f1);
	sign2 = COB_GET_SIGN (f2);
	min = (f1->size < f2->size) ? f1->size : f2->size;
	s = COB_MODULE_PTR->collating_sequence;

	/* Compare common substring */
	if ((ret = common_cmps (f1->data, f2->data, min, s)) != 0) {
		goto end;
	}

	/* Compare the rest (if any) with spaces */
	if (f1->size > f2->size) {
		ret = common_cmpc (f1->data + min, ' ', f1->size - min, s);
	} else if (f1->size < f2->size) {
		ret = -common_cmpc (f2->data + min, ' ', f2->size - min, s);
	}

end:
	if (COB_FIELD_TYPE (f1) != COB_TYPE_NUMERIC_PACKED) {
		COB_PUT_SIGN (f1, sign1);
	}
	if (COB_FIELD_TYPE (f2) != COB_TYPE_NUMERIC_PACKED) {
		COB_PUT_SIGN (f2, sign2);
	}
	return ret;
}

static int
sort_compare (const void *data1, const void *data2)
{
	size_t		i;
	int		cmp;
	cob_field	f1;
	cob_field	f2;

	for (i = 0; i < sort_nkeys; ++i) {
		f1 = f2 = *sort_keys[i].field;
		f1.data = (unsigned char *)data1 + sort_keys[i].offset;
		f2.data = (unsigned char *)data2 + sort_keys[i].offset;
		if (COB_FIELD_IS_NUMERIC(&f1)) {
			cmp = cob_numeric_cmp (&f1, &f2);
		} else {
			cmp = common_cmps (f1.data, f2.data, f1.size, sort_collate);
		}
		if (cmp != 0) {
			return sort_keys[i].tf_ascending ? cmp : -cmp;
		}
	}
	return 0;
}

static void
cob_memcpy (cob_field *dst, const void *src, const size_t size)
{
	cob_field	temp;

	if (!dst->size) {
		return;
	}
	temp.size = size;
	temp.data = (cob_u8_ptr)src;
	temp.attr = &const_alpha_attr;
	cob_move (&temp, dst);
}

static void
cob_check_trace_file (void)
{
	if (!cob_trace_env) {
		cob_trace_file = stderr;
		return;
	}
	if (!cobglobptr->cob_unix_lf) {
		cob_trace_file = fopen (cob_trace_env, "w");
	} else {
		cob_trace_file = fopen (cob_trace_env, "wb");
	}
	if (!cob_trace_file) {
		cob_trace_file = stderr;
	}
}

static void
cob_rescan_env_vals (void)
{
	char	*s;

	/* termio */
	s = getenv("COB_REDIRECT_DISPLAY");
	if (s) {
		runtimeptr->cob_disp_to_stderr_env = cob_save_env_value(runtimeptr->cob_disp_to_stderr_env, s);

		if (*s == 'Y' || *s == 'y' || *s == '1') {
		cobglobptr->cob_disp_to_stderr = 1;
	} else {
		cobglobptr->cob_disp_to_stderr = 0;
	}
	}

	/* screenio */

	/* BELL disposition */
	/* Default to BEEP */
	cobglobptr->cob_beep_value = 0;
	s = getenv("COB_BELL");
	if (s) {
		runtimeptr->cob_beep_str_env = cob_save_env_value(
				runtimeptr->cob_beep_str_env, s);

		if (!strcasecmp(s, "FLASH")) {
			cobglobptr->cob_beep_value = 1;
		} else if (!strcasecmp(s, "SPEAKER")) {
			cobglobptr->cob_beep_value = 2;
		} else {
			/* NO/NONE/OFF/0 */
			switch (*s) {
			case 'n':
			case 'N':
			case 'o':
			case 'O':
			case '0':
				cobglobptr->cob_beep_value = 9;
				break;
			default:
				break;
			}
		}
	}

	/* TIMEOUT scaling */
	cobglobptr->cob_timeout_scale = 1000;
	s = getenv ("COB_TIMEOUT_SCALE");
	if (s) {
		runtimeptr->cob_timeout_scale_env = cob_save_env_value(
				runtimeptr->cob_timeout_scale_env, s);

		if (*s == '1') {
			cobglobptr->cob_timeout_scale = 100;
		} else if (*s == '2') {
			cobglobptr->cob_timeout_scale = 10;
		} else if (*s == '3') {
			cobglobptr->cob_timeout_scale = 1;
		}
	}

	/* Extended ACCEPT status returns */
	cobglobptr->cob_extended_status = 0;
	cobglobptr->cob_use_esc = 0;
	s = getenv ("COB_SCREEN_EXCEPTIONS");
	if (s) {
		runtimeptr->cob_extended_status_env = cob_save_env_value(
				runtimeptr->cob_extended_status_env, s);

		if (*s == 'Y' || *s == 'y' || *s == '1') {
			cobglobptr->cob_extended_status = 1;
			s = getenv ("COB_SCREEN_ESC");
			if (s) {
				runtimeptr->cob_use_esc_env = cob_save_env_value(
						runtimeptr->cob_use_esc_env, s);

				if (*s == 'Y' || *s == 'y' || *s == '1') {
					cobglobptr->cob_use_esc = 1;
				}
			}
		}
	}
}

/* Global functions */

int
cob_get_exception_code (void)
{
	return cobglobptr->cob_exception_code;
}

const char *
cob_get_exception_name (void)
{
	size_t	n;

	for (n = 0; n < EXCEPTION_TAB_SIZE; ++n) {
		if (cobglobptr->cob_exception_code == cob_exception_tab_code[n]) {
			return cob_exception_tab_name[n];
		}
	}
	return NULL;
}

void
cob_set_exception (const int id)
{
	cobglobptr->cob_exception_code = cob_exception_tab_code[id];
	if (cobglobptr->cob_exception_code) {
		cobglobptr->cob_got_exception = 1;
		cobglobptr->cob_orig_statement = cob_source_statement;
		cobglobptr->cob_orig_line = cob_source_line;
		cobglobptr->cob_orig_program_id = cob_current_program_id;
		cobglobptr->cob_orig_section = cob_current_section;
		cobglobptr->cob_orig_paragraph = cob_current_paragraph;
	}
}

void
cob_accept_exception_status (cob_field *f)
{
	cob_set_int (f, cobglobptr->cob_exception_code);
}

void
cob_accept_user_name (cob_field *f)
{
	if (cob_user_name) {
		cob_memcpy (f, cob_user_name,
			    strlen (cob_user_name));
	} else {
		cob_memcpy (f, " ", (size_t)1);
	}
}

void *
cob_malloc (const size_t size)
{
	void	*mptr;

	mptr = calloc ((size_t)1, size);
	if (unlikely(!mptr)) {
		cob_fatal_error (COB_FERROR_MEMORY);
	}
	return mptr;
}

void *
cob_fast_malloc (const size_t size)
{
	void	*mptr;

	mptr = malloc (size);
	if (unlikely(!mptr)) {
		cob_fatal_error (COB_FERROR_MEMORY);
	}
	return mptr;
}

char *
cob_strdup (const char *p)
{
	char	*mptr;
	size_t	len;

	len = strlen (p);
	mptr = (char *) cob_malloc (len + 1U);
	memcpy (mptr, p, len);
	return mptr;
}

/* Caching versions of malloc/free */
void *
cob_cache_malloc (const size_t size)
{
	struct cob_alloc_cache	*cache_ptr;
	void			*mptr;

	cache_ptr = cob_malloc (sizeof (struct cob_alloc_cache));
	mptr = cob_malloc (size);
	cache_ptr->cob_pointer = mptr;
	cache_ptr->size = size;
	cache_ptr->next = cob_alloc_base;
	cob_alloc_base = cache_ptr;
	return mptr;
}

void *
cob_cache_realloc (void *ptr, const size_t size)
{
	struct cob_alloc_cache	*cache_ptr;
	void			*mptr;

	if (!ptr) {
		return cob_cache_malloc (size);
	}
	cache_ptr = cob_alloc_base;
	for (; cache_ptr; cache_ptr = cache_ptr->next) {
		if (ptr == cache_ptr->cob_pointer) {
			if (size <= cache_ptr->size) {
				return ptr;
			}
			mptr = cob_malloc (size);
			memcpy (mptr, cache_ptr->cob_pointer, cache_ptr->size);
			free (cache_ptr->cob_pointer);
			cache_ptr->cob_pointer = mptr;
			cache_ptr->size = size;
			return mptr;
		}
	}
	return ptr;
}

void
cob_cache_free (void *ptr)
{
	struct cob_alloc_cache	*cache_ptr;
	struct cob_alloc_cache	*prev_ptr;

	if (!ptr) {
		return;
	}
	cache_ptr = cob_alloc_base;
	prev_ptr = cob_alloc_base;
	for (; cache_ptr; cache_ptr = cache_ptr->next) {
		if (ptr == cache_ptr->cob_pointer) {
			free (cache_ptr->cob_pointer);
			if (cache_ptr == cob_alloc_base) {
				cob_alloc_base = cache_ptr->next;
			} else {
				prev_ptr->next = cache_ptr->next;
			}
			free (cache_ptr);
			return;
		}
		prev_ptr = cache_ptr;
	}
}

void
cob_set_location (const char *sfile, const unsigned int sline,
		  const char *csect, const char *cpara,
		  const char *cstatement)
{
	const char	*s;

	cob_current_program_id = COB_MODULE_PTR->module_name;
	cob_source_file = sfile;
	cob_source_line = sline;
	cob_current_section = csect;
	cob_current_paragraph = cpara;
	if (cstatement) {
		cob_source_statement = cstatement;
	}
	if (cob_line_trace) {
		if (!cob_trace_file) {
			cob_check_trace_file ();
		}
		if (!cob_last_sfile || strcmp (cob_last_sfile, sfile)) {
			cob_last_sfile = sfile;
			fprintf (cob_trace_file, "Source :    '%s'\n", sfile);
		}
		if (COB_MODULE_PTR->module_name) {
			s = COB_MODULE_PTR->module_name;
		} else {
			s = "Unknown";
		}
		fprintf (cob_trace_file,
			 "Program-Id: %-16s Statement: %-21.21s  Line: %u\n",
			 s, cstatement ? (char *)cstatement : "Unknown",
			 sline);
		fflush (cob_trace_file);
	}
}


void
cob_trace_section (const char *para, const char *source, const int line)
{
	const char	*s;

	if (cob_line_trace) {
		if (!cob_trace_file) {
			cob_check_trace_file ();
		}
		if (source &&
		    (!cob_last_sfile || strcmp (cob_last_sfile, source))) {
			cob_last_sfile = source;
			fprintf (cob_trace_file, "Source:     '%s'\n", source);
		}
		if (COB_MODULE_PTR->module_name) {
			s = COB_MODULE_PTR->module_name;
		} else {
			s = "Unknown";
		}
		fprintf (cob_trace_file, "Program-Id: %-16s ", s);
		if (line) {
			fprintf (cob_trace_file, "%-34.34sLine: %d\n", para, line);
		} else {
			fprintf (cob_trace_file, "%s\n", para);
		}
		fflush (cob_trace_file);
	}
}


void
cob_set_progid (
	  char *prog
	, char *source
	, char *packver
	, int   patchlev
	, char *compile_date
	, char *compile_host)
{
	progid.program_name = prog;
	progid.source_file_name = (source == NULL) ? (char *)"ANON" : source;
	progid.version = packver;
	progid.patch = patchlev;
	progid.compile_date = compile_date;
	progid.compile_host = compile_host;
}



progid_t
cob_get_progid (void)
{
	return(progid);
}



void
cob_ready_trace (void)
{
	cob_line_trace = 1;
}

void
cob_reset_trace (void)
{
	cob_line_trace = 0;
}

unsigned char *
cob_get_pointer (const void *srcptr)
{
	void	*tmptr;

	memcpy (&tmptr, srcptr, sizeof (void *));
	return (cob_u8_ptr)tmptr;
}

void *
cob_get_prog_pointer (const void *srcptr)
{
	void	*tmptr;

	memcpy (&tmptr, srcptr, sizeof (void *));
	return tmptr;
}

void
cob_field_to_string (const cob_field *f, void *str, const size_t maxsize)
{
	unsigned char	*s;
	size_t		count;
	size_t		i;

	count = 0;
	if (unlikely(f->size == 0)) {
		return;
	}
	i = f->size - 1;
	for (; ;) {
		if (f->data[i] && f->data[i] != (unsigned char)' ') {
			count = i + 1;
			break;
		}
		if (!i) {
			break;
		}
		--i;
	}
	if (count > maxsize) {
		count = maxsize;
	}
	s = (unsigned char *)str;
	for (i = 0; i < count; ++i) {
		s[i] = f->data[i];
	}
	s[i] = 0;
}

void
cob_stop_run (const int status)
{
	struct exit_handlerlist	*h;

	if (!cob_initialized) {
		exit (1);
	}
	if (exit_hdlrs != NULL) {
		h = exit_hdlrs;
		while (h != NULL) {
			h->proc ();
			h = h->next;
		}
	}
	cob_terminate_routines ();
	exit (status);
}

void
cob_runtime_error (const char *fmt, ...)
{
	struct handlerlist	*h;
	struct handlerlist	*hp;
	char			*p;
	va_list			ap;

#if	1	/* RXWRXW - Exit screen */
	/* Exit screen mode early */
	cob_exit_screen ();
#endif

	if (hdlrs != NULL) {
		if (runtime_err_str) {
			p = runtime_err_str;
			if (cob_source_file) {
				sprintf (runtime_err_str, "%s: %u: ",
					 cob_source_file, cob_source_line);
				p = runtime_err_str + strlen (runtime_err_str);
			}
			va_start (ap, fmt);
			vsprintf (p, fmt, ap);
			va_end (ap);
		}
		h = hdlrs;
		while (h != NULL) {
			if (runtime_err_str) {
				h->proc (runtime_err_str);
			} else {
				h->proc ((char *)_("Malloc error"));
			}
			hp = h;
			h = h->next;
			free (hp);
		}
		hdlrs = NULL;
	}

	/* Prefix */
	if (cob_source_file) {
		fprintf (stderr, "%s: %u: ", cob_source_file, cob_source_line);
	}
	fputs ("libcob: ", stderr);

	/* Body */
	va_start (ap, fmt);
	vfprintf (stderr, fmt, ap);
	va_end (ap);

	/* Postfix */
	putc ('\n', stderr);
	fflush (stderr);
}

void
cob_fatal_error (const int fatal_error)
{

	switch (fatal_error) {
	case COB_FERROR_NONE:
		cob_runtime_error (_("cob_init() has not been called"));
		break;
	case COB_FERROR_CANCEL:
		cob_runtime_error (_("Attempt to CANCEL active program"));
		break;
	case COB_FERROR_INITIALIZED:
		cob_runtime_error (_("cob_init() has not been called"));
		break;
	case COB_FERROR_CODEGEN:
		cob_runtime_error (_("Codegen error - Please report this"));
		break;
	case COB_FERROR_CHAINING:
		cob_runtime_error (_("Recursive call of chained program"));
		break;
	case COB_FERROR_STACK:
		cob_runtime_error (_("Stack overflow, possible PERFORM depth exceeded"));
		break;
	case COB_FERROR_GLOBAL:
		cob_runtime_error (_("Invalid entry/exit in GLOBAL USE procedure"));
		break;
	case COB_FERROR_MEMORY:
		cob_runtime_error (_("Unable to allocate memory"));
		break;
	case COB_FERROR_MODULE:
		cob_runtime_error (_("Invalid entry into module"));
		break;
	case COB_FERROR_RECURSIVE:
		cob_runtime_error (_("Invalid recursive COBOL CALL"));
		break;
	case COB_FERROR_FILE:
       		cob_display_file_exception();
		cob_runtime_error (_("Failure in fileio subsystem"));
		break;
	case COB_FERROR_FUNCTION:
		cob_runtime_error (_("Attempt to use non-implemented function"));
		break;
	default:
		cob_runtime_error (_("Unknown failure : %d"), fatal_error);
		break;
	}
	cob_stop_run (1);
}

cob_global *
cob_get_global_ptr (void)
{
	if (unlikely(!cob_initialized)) {
		cob_fatal_error (COB_FERROR_INITIALIZED);
	}
	return cobglobptr;
}

void
cob_module_enter (cob_module **module, cob_global **mglobal,
		  const int auto_init)
{
	/* Check initialized */
	if (unlikely(!cob_initialized)) {
		if (auto_init) {
			cob_init (0, NULL);
		} else {
			cob_fatal_error (COB_FERROR_INITIALIZED);
		}
	}

	/* Set global pointer */
	*mglobal = cobglobptr;

	/* Check module pointer */
	if (!*module) {
		*module = cob_cache_malloc (sizeof(cob_module));
	}

#if	0	/* RXWRXW - Params */
	/* Save parameter count */
	(*module)->module_num_params = cobglobptr->cob_call_params;
#endif

	/* Push module pointer */
	(*module)->next = COB_MODULE_PTR;
	COB_MODULE_PTR = *module;
}

void
cob_module_leave (cob_module *module)
{
	COB_UNUSED (module);
	/* Pop module pointer */
	COB_MODULE_PTR = COB_MODULE_PTR->next;
}

void *
cob_save_func (cob_field **savefld, const int params,
	       const int eparams, ...)
{
	struct cob_func_loc	*fl;
	va_list			args;
	int			numparams;
	int			n;

	if (unlikely(params > eparams)) {
		numparams = eparams;
	} else {
		numparams = params;
	}

	/* Allocate return field */
	*savefld = cob_malloc (sizeof (cob_field));
	/* Allocate save area */
	fl = cob_malloc (sizeof(struct cob_func_loc));
	fl->func_params = cob_malloc (sizeof(void *) * ((size_t)numparams + 1U));
	fl->data = cob_malloc (sizeof(void *) * ((size_t)numparams + 1U));

	/* Save values */
	fl->save_module = COB_MODULE_PTR->next;
	fl->save_call_params = cobglobptr->cob_call_params;
	fl->save_proc_parms = COB_MODULE_PTR->cob_procedure_params;
	fl->save_num_params = COB_MODULE_PTR->module_num_params;

	/* Set current values */
	COB_MODULE_PTR->cob_procedure_params = fl->func_params;
	cobglobptr->cob_call_params = numparams;
	if (numparams) {
		va_start (args, eparams);
		for (n = 0; n < numparams; ++n) {
			fl->func_params[n] = va_arg (args, cob_field *);
			if (fl->func_params[n]) {
				fl->data[n] = fl->func_params[n]->data;
			}
		}
		va_end (args);
	}
	return fl;
}

void
cob_restore_func (struct cob_func_loc *fl)
{
	/* Restore calling environment */
	cobglobptr->cob_call_params = fl->save_call_params;
#if	0	/* RXWRXW - MODNEXT */
	COB_MODULE_PTR->next = fl->save_module;
#endif
	COB_MODULE_PTR->cob_procedure_params = fl->save_proc_parms;
	COB_MODULE_PTR->module_num_params = fl->save_num_params;
	free (fl->data);
	free (fl->func_params);
	free (fl);
}

void
cob_check_version (const char *prog, const char *packver, const int patchlev)
{
	if (strcmp (packver, PACKAGE_VERSION) || patchlev != PATCH_LEVEL) {
		cob_runtime_error (_("Error - Version mismatch"));
		cob_runtime_error (_("%s has version/patch level %s/%d"), prog,
				   packver, patchlev);
		cob_runtime_error (_("Library has version/patch level %s/%d"),
				   PACKAGE_VERSION, PATCH_LEVEL);
		cob_stop_run (1);
	}
}

void
cob_parameter_check (const char *funcname, const int numparms)
{
	if (cobglobptr->cob_call_params < numparms) {
		cob_runtime_error (_("CALL to %s requires %d parameters"),
				   funcname, numparms);
		cob_stop_run (1);
	}
}

void
cob_correct_numeric (cob_field *f)
{
	unsigned char	*p;
	unsigned char	*data;
	size_t		size;
	size_t		i;

	if (!COB_FIELD_IS_NUMDISP(f)) {
		return;
	}
	size = f->size;
	data = f->data;
	if (COB_FIELD_HAVE_SIGN (f)) {
		/* Adjust for sign byte */
		size--;
		if (unlikely(COB_FIELD_SIGN_LEADING (f))) {
			p = f->data;
			data = p + 1;
		} else {
			p = f->data + f->size - 1;
		}
		if (unlikely(COB_FIELD_SIGN_SEPARATE (f))) {
			if (*p != '+' && *p != '-') {
				*p = '+';
			}
		} else if (unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			switch (*p) {
			case '{':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case '}':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
				break;
			case '0':
				*p = '{';
				break;
			case '1':
				*p = 'A';
				break;
			case '2':
				*p = 'B';
				break;
			case '3':
				*p = 'C';
				break;
			case '4':
				*p = 'D';
				break;
			case '5':
				*p = 'E';
				break;
			case '6':
				*p = 'F';
				break;
			case '7':
				*p = 'G';
				break;
			case '8':
				*p = 'H';
				break;
			case '9':
				*p = 'I';
				break;
			case 0:
			case ' ':
				*p = '{';
				break;
			default:
				break;
			}
		} else {
			if(!*p || *p == ' ') {
				*p = '0';
			}
		}
	} else {
		p = f->data + f->size - 1;
		if (unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			switch (*p) {
			case 0:
			case ' ':
			case '{':
			case '}':
				*p = '0';
				break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
				*p = '1' + (*p - 'A');
				break;
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
				*p = '1' + (*p - 'J');
				break;
			default:
				break;
			}
		} else {
			switch (*p) {
			case 0:
			case ' ':
			case 'p':
				*p = '0';
				break;
			case 'q':
				*p = '1';
				break;
			case 'r':
				*p = '2';
				break;
			case 's':
				*p = '3';
				break;
			case 't':
				*p = '4';
				break;
			case 'u':
				*p = '5';
				break;
			case 'v':
				*p = '6';
				break;
			case 'w':
				*p = '7';
				break;
			case 'x':
				*p = '8';
				break;
			case 'y':
				*p = '9';
				break;
			default:
				break;
			}
		}
	}
	for (i = 0, p = data; i < size; ++i, ++p) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break;
		case 0:
		case ' ':
			*p = '0';
			break;
		default:
			if ((*p & 0x0F) <= 9) {
				*p = (*p & 0x0F) + '0';
			}
			break;
		}
	}
}

static int
cob_check_numdisp (const cob_field *f)
{
	unsigned char	*p;
	unsigned char	*data;
	size_t		size;
	size_t		i;

	size = f->size;
	data = f->data;
	if (COB_FIELD_HAVE_SIGN (f)) {
		/* Adjust for sign byte */
		size--;
		if (unlikely(COB_FIELD_SIGN_LEADING (f))) {
			p = f->data;
			data = p + 1;
		} else {
			p = f->data + f->size - 1;
		}
		if (unlikely(COB_FIELD_SIGN_SEPARATE (f))) {
			if (*p != '+' && *p != '-') {
				return 0;
			}
		} else if (unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			switch (*p) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '{':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case '}':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
				break;
			default:
				return 0;
			}
		} else {
			switch (*p) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
				break;
			default:
				return 0;
			}
		}
	}
	for (i = 0; i < size; ++i) {
		if (!isdigit (data[i])) {
			return 0;
		}
	}
	return 1;
}

/* Sign */

int
cob_real_get_sign (cob_field *f)
{
	unsigned char	*p;

	switch (COB_FIELD_TYPE (f)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		/* Locate sign */
		if (unlikely(COB_FIELD_SIGN_LEADING (f))) {
			p = f->data;
		} else {
			p = f->data + f->size - 1;
		}

		/* Get sign */
		if (unlikely(COB_FIELD_SIGN_SEPARATE (f))) {
			return (*p == '-') ? -1 : 1;
		}
		if (*p >= (unsigned char)'0' && *p <= (unsigned char)'9') {
			return 1;
		}
		if (*p == ' ') {
#if	0	/* RXWRXW - Space sign */
			*p = (unsigned char)'0';
#endif
			return 1;
		}
		if (unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			return cob_get_sign_ebcdic (p);
		}
		return cob_get_sign_ascii (p);
	case COB_TYPE_NUMERIC_PACKED:
		if (COB_FIELD_NO_SIGN_NIBBLE (f)) {
			return 1;
		}
		p = f->data + f->size - 1;
		return ((*p & 0x0F) == 0x0D) ? -1 : 1;
	}
	return 0;
}

void
cob_real_put_sign (cob_field *f, const int sign)
{
	unsigned char	*p;
	unsigned char	c;

	switch (COB_FIELD_TYPE (f)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		/* Locate sign */
		if (unlikely(COB_FIELD_SIGN_LEADING (f))) {
			p = f->data;
		} else {
			p = f->data + f->size - 1;
		}

		/* Put sign */
		if (unlikely(COB_FIELD_SIGN_SEPARATE (f))) {
			c = (sign < 0) ? (cob_u8_t)'-' : (cob_u8_t)'+';
			if (*p != c) {
				*p = c;
			}
		} else if (unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			cob_put_sign_ebcdic (p, sign);
		} else if (sign < 0) {
			cob_put_sign_ascii (p);
		}
		return;
	case COB_TYPE_NUMERIC_PACKED:
		if (COB_FIELD_NO_SIGN_NIBBLE (f)) {
			return;
		}
		p = f->data + f->size - 1;
		if (sign < 0) {
			*p = (*p & 0xF0) | 0x0D;
		} else {
			*p = (*p & 0xF0) | 0x0C;
		}
		return;
	}
}

/* Registration of external handlers */
void
cob_reg_sighnd	(void (*sighnd) (int))
{
	cob_ext_sighdl = sighnd;
};

/* Switch */

int
cob_get_switch (const int n)
{
	if (n < 0 || n > (COB_SWITCH_MAX - 1)) {
		return 0;
	}
	return cob_switch[n];
}

void
cob_set_switch (const int n, const int flag)
{
	if (n < 0 || n > (COB_SWITCH_MAX - 1)) {
		return;
	}
	if (flag == 0) {
		cob_switch[n] = 0;
	} else if (flag == 1) {
		cob_switch[n] = 1;
	}
}

int
cob_cmp (cob_field *f1, cob_field *f2)
{
	cob_field	temp;
	cob_field_attr	attr;
	unsigned char	buff[256];

	if (COB_FIELD_IS_NUMERIC (f1) && COB_FIELD_IS_NUMERIC (f2)) {
		return cob_numeric_cmp (f1, f2);
	}
	if (COB_FIELD_TYPE (f2) == COB_TYPE_ALPHANUMERIC_ALL) {
		if (f2->size == 1 && f2->data[0] == '0' &&
		    COB_FIELD_IS_NUMERIC (f1)) {
			return cob_cmp_int (f1, 0);
		}
		return cob_cmp_all (f1, f2);
	}
	if (COB_FIELD_TYPE (f1) == COB_TYPE_ALPHANUMERIC_ALL) {
		if (f1->size == 1 && f1->data[0] == '0' &&
		    COB_FIELD_IS_NUMERIC (f2)) {
			return -cob_cmp_int (f2, 0);
		}
		return -cob_cmp_all (f2, f1);
	}
	if (COB_FIELD_IS_NUMERIC (f1) &&
	    COB_FIELD_TYPE (f1) != COB_TYPE_NUMERIC_DISPLAY) {
		temp.size = COB_FIELD_DIGITS(f1);
		temp.data = buff;
		temp.attr = &attr;
		attr = *f1->attr;
		attr.type = COB_TYPE_NUMERIC_DISPLAY;
		attr.flags &= ~COB_FLAG_HAVE_SIGN;
		cob_move (f1, &temp);
		f1 = &temp;
	}
	if (COB_FIELD_IS_NUMERIC (f2) &&
	    COB_FIELD_TYPE (f2) != COB_TYPE_NUMERIC_DISPLAY) {
		temp.size = COB_FIELD_DIGITS(f2);
		temp.data = buff;
		temp.attr = &attr;
		attr = *f2->attr;
		attr.type = COB_TYPE_NUMERIC_DISPLAY;
		attr.flags &= ~COB_FLAG_HAVE_SIGN;
		cob_move (f2, &temp);
		f2 = &temp;
	}
	return cob_cmp_alnum (f1, f2);
}

/* Class check */

int
cob_is_omitted (const cob_field *f)
{
	return f->data == NULL;
}

int
cob_is_numeric (const cob_field *f)
{
	size_t		i;
	union {
		float		fpf;
		double		fpd;
	} fval;
	int		sign;

	switch (COB_FIELD_TYPE (f)) {
	case COB_TYPE_NUMERIC_BINARY:
		return 1;
	case COB_TYPE_NUMERIC_FLOAT:
		memcpy (&fval.fpf, f->data, sizeof(float));
		return !finite ((double)fval.fpf);
	case COB_TYPE_NUMERIC_DOUBLE:
		memcpy (&fval.fpd, f->data, sizeof(double));
		return !finite (fval.fpd);
	case COB_TYPE_NUMERIC_PACKED:
		/* Check digits */
		for (i = 0; i < f->size - 1; ++i) {
			if ((f->data[i] & 0xF0) > 0x90 ||
			    (f->data[i] & 0x0F) > 0x09) {
				return 0;
			}
		}
		/* Check high nibble of last byte */
		if ((f->data[i] & 0xF0) > 0x90) {
			return 0;
		}

		if (COB_FIELD_NO_SIGN_NIBBLE (f)) {
			/* COMP-6 - Check last nibble */
			if ((f->data[i] & 0x0F) > 0x09) {
				return 0;
			}
			return 1;
		}

		/* Check sign */
		sign = f->data[i] & 0x0F;
		if (COB_FIELD_HAVE_SIGN (f)) {
			if (sign == 0x0C || sign == 0x0D) {
				return 1;
			}
			if (COB_MODULE_PTR->flag_host_sign &&
			    sign == 0x0F) {
				return 1;
			}
		} else if (sign == 0x0F) {
			return 1;
		}
		return 0;
	case COB_TYPE_NUMERIC_DISPLAY:
		return cob_check_numdisp (f);
	case COB_TYPE_NUMERIC_FP_DEC64:
#ifdef	WORDS_BIGENDIAN
		return (f->data[0] & 0x78U) != 0x78U;
#else
		return (f->data[7] & 0x78U) != 0x78U;
#endif
	case COB_TYPE_NUMERIC_FP_DEC128:
#ifdef	WORDS_BIGENDIAN
		return (f->data[0] & 0x78U) != 0x78U;
#else
		return (f->data[15] & 0x78U) != 0x78U;
#endif
	default:
		for (i = 0; i < f->size; ++i) {
			if (!isdigit (f->data[i])) {
				return 0;
			}
		}
		return 1;
	}
}

int
cob_is_alpha (const cob_field *f)
{
	size_t	i;

	for (i = 0; i < f->size; ++i) {
		if (!isalpha (f->data[i]) && f->data[i] != (unsigned char)' ') {
			return 0;
		}
	}
	return 1;
}

int
cob_is_upper (const cob_field *f)
{
	size_t	i;

	for (i = 0; i < f->size; ++i) {
		if (!isupper (f->data[i]) && f->data[i] != (unsigned char)' ') {
			return 0;
		}
	}
	return 1;
}

int
cob_is_lower (const cob_field *f)
{
	size_t	i;

	for (i = 0; i < f->size; ++i) {
		if (!islower (f->data[i]) && f->data[i] != (unsigned char)' ') {
			return 0;
		}
	}
	return 1;
}

/* Table sort */

void
cob_table_sort_init (const size_t nkeys, const unsigned char *collating_sequence)
{
	sort_nkeys = 0;
	sort_keys = cob_malloc (nkeys * sizeof (cob_file_key_t));
	if (collating_sequence) {
		sort_collate = collating_sequence;
	} else {
		sort_collate = COB_MODULE_PTR->collating_sequence;
	}
}

void
cob_table_sort_init_key (cob_field *field, const int tf_ascending,
			 const unsigned int offset)
{
	sort_keys[sort_nkeys].field = field;
	sort_keys[sort_nkeys].tf_ascending = tf_ascending;
	sort_keys[sort_nkeys].offset = offset;
	sort_nkeys++;
}

void
cob_table_sort (cob_field *f, const int n)
{
	qsort (f->data, (size_t) n, f->size, sort_compare);
	free (sort_keys);
}

/* Run-time error checking */

void
cob_check_based (const unsigned char *x, const char *name)
{
	if (!x) {
		cob_runtime_error (_("BASED/LINKAGE item '%s' has NULL address"), name);
		cob_stop_run (1);
	}
}

void
cob_check_numeric (const cob_field *f, const char *name)
{
	unsigned char	*data;
	char		*p;
	char		*buff;
	size_t		i;

	if (!cob_is_numeric (f)) {
		buff = cob_fast_malloc ((size_t)COB_SMALL_BUFF);
		p = buff;
		data = f->data;
		for (i = 0; i < f->size; ++i) {
			if (isprint (data[i])) {
				*p++ = data[i];
			} else {
				p += sprintf (p, "\\%03o", data[i]);
			}
		}
		*p = '\0';
		cob_runtime_error (_("'%s' not numeric: '%s'"), name, buff);
		free (buff);
		cob_stop_run (1);
	}
}

void
cob_check_odo (const int i, const int min,
	       const int max, const char *name)
{
	/* Check OCCURS DEPENDING ON item */
	if (i < min || max < i) {
		cob_set_exception (COB_EC_BOUND_ODO);
		cob_runtime_error (_("OCCURS DEPENDING ON '%s' out of bounds: %d"), name, i);
		cob_stop_run (1);
	}
}

void
cob_check_subscript (const int i, const int min,
		     const int max, const char *name)
{
	/* Check subscript */
	if (i < min || max < i) {
		cob_set_exception (COB_EC_BOUND_SUBSCRIPT);
		cob_runtime_error (_("Subscript of '%s' out of bounds: %d"), name, i);
		cob_stop_run (1);
	}
}

void
cob_check_ref_mod (const int offset, const int length,
		   const int size, const char *name)
{
	/* Check offset */
	if (offset < 1 || offset > size) {
		cob_set_exception (COB_EC_BOUND_REF_MOD);
		cob_runtime_error (_("Offset of '%s' out of bounds: %d"), name, offset);
		cob_stop_run (1);
	}

	/* Check length */
	if (length < 1 || offset + length - 1 > size) {
		cob_set_exception (COB_EC_BOUND_REF_MOD);
		cob_runtime_error (_("Length of '%s' out of bounds: %d"), name, length);
		cob_stop_run (1);
	}
}

void *
cob_external_addr (const char *exname, const int exlength)
{
	struct cob_external *eptr;

	/* Locate or allocate EXTERNAL item */
	for (eptr = basext; eptr; eptr = eptr->next) {
		if (!strcmp (exname, eptr->ename)) {
			if (exlength > eptr->esize) {
				cob_runtime_error (_("EXTERNAL item '%s' previously allocated with size %d, requested size is %d"),
						   exname, eptr->esize, exlength);
				cob_stop_run (1);
			}
			cobglobptr->cob_initial_external = 0;
			return eptr->ext_alloc;
		}
	}
	eptr = cob_malloc (sizeof (struct cob_external));
	eptr->next = basext;
	eptr->esize = exlength;
	eptr->ename = cob_malloc (strlen (exname) + 1U);
	strcpy (eptr->ename, exname);
	eptr->ext_alloc = cob_malloc ((size_t)exlength);
	basext = eptr;
	cobglobptr->cob_initial_external = 1;
	return eptr->ext_alloc;
}

/* Extended ACCEPT/DISPLAY */

void
cob_accept_date (cob_field *f)
{
	time_t	t;
	char	s[8];

	t = time (NULL);
	strftime (s, (size_t)7, "%y%m%d", localtime (&t));
	cob_memcpy (f, s, (size_t)6);
}

void
cob_accept_date_yyyymmdd (cob_field *f)
{
	time_t	t;
	char	s[12];

	t = time (NULL);
	strftime (s, (size_t)9, "%Y%m%d", localtime (&t));
	cob_memcpy (f, s, (size_t)8);
}

void
cob_accept_day (cob_field *f)
{
	time_t	t;
	char	s[8];

	t = time (NULL);
	strftime (s, (size_t)6, "%y%j", localtime (&t));
	cob_memcpy (f, s, (size_t)5);
}

void
cob_accept_day_yyyyddd (cob_field *f)
{
	time_t	t;
	char	s[12];

	t = time (NULL);
	strftime (s, (size_t)8, "%Y%j", localtime (&t));
	cob_memcpy (f, s, (size_t)7);
}

void
cob_accept_day_of_week (cob_field *f)
{
	struct tm	*tm;
	time_t		t;
	unsigned char	s[4];

	t = time (NULL);
	tm = localtime (&t);
	if (tm->tm_wday == 0) {
		s[0] = (unsigned char)'7';
	} else {
		s[0] = (unsigned char)(tm->tm_wday + '0');
	}
	cob_memcpy (f, s, (size_t)1);
}

void
cob_accept_time (cob_field *f)
{
#ifdef	_WIN32
	SYSTEMTIME	syst;
#else
	struct tm	*tlt;
	time_t		t;
#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	struct timeval	tmv;
	char		buff2[8];
#endif
#endif
	char		s[12];

#ifdef	_WIN32
	GetLocalTime (&syst);
	sprintf (s, "%2.2d%2.2d%2.2d%2.2d", syst.wHour, syst.wMinute,
		syst.wSecond, syst.wMilliseconds / 10);
#else
#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	gettimeofday (&tmv, NULL);
	t = tmv.tv_sec;
#else
	t = time (NULL);
#endif
	tlt = localtime (&t);
	/* Leap seconds ? */
	if (tlt->tm_sec >= 60) {
		tlt->tm_sec = 59;
	}
	strftime (s, (size_t)9, "%H%M%S00", tlt);
#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	sprintf(buff2, "%2.2ld", (long int)(tmv.tv_usec / 10000));
	memcpy (&s[6], buff2, (size_t)2);
#endif
#endif
	cob_memcpy (f, s, (size_t)8);
}

void
cob_display_command_line (cob_field *f)
{
	if (commlnptr) {
		free (commlnptr);
	}
	commlnptr = cob_malloc (f->size + 1U);
	commlncnt = f->size;
	memcpy (commlnptr, f->data, commlncnt);
}

void
cob_accept_command_line (cob_field *f)
{
	char	*buff;
	size_t	i;
	size_t	size;
	size_t	len;

	if (commlncnt) {
		cob_memcpy (f, commlnptr, commlncnt);
		return;
	}

	if (cob_argc <= 1) {
		cob_memcpy (f, " ", (size_t)1);
		return;
	}

	size = 0;
	for (i = 1; i < (size_t)cob_argc; ++i) {
		size += (strlen (cob_argv[i]) + 1);
		if (size > f->size) {
			break;
		}
	}
	buff = cob_malloc (size);
	buff[0] = ' ';
	size = 0;
	for (i = 1; i < (size_t)cob_argc; ++i) {
		len = strlen (cob_argv[i]);
		memcpy (buff + size, cob_argv[i], len);
		size += len;
		if (i != (size_t)cob_argc - 1U) {
			buff[size++] = ' ';
		}
		if (size > f->size) {
			break;
		}
	}
	cob_memcpy (f, buff, size);
	free (buff);
}

/* Argument number */

void
cob_display_arg_number (cob_field *f)
{
	int		n;
	cob_field_attr	attr;
	cob_field	temp;

	temp.size = 4;
	temp.data = (unsigned char *)&n;
	temp.attr = &attr;
	COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9, 0, 0, NULL);
	cob_move (f, &temp);
	if (n < 0 || n >= cob_argc) {
		cob_set_exception (COB_EC_IMP_DISPLAY);
		return;
	}
	current_arg = n;
}

void
cob_accept_arg_number (cob_field *f)
{
	int		n;
	cob_field_attr	attr;
	cob_field	temp;

	n = cob_argc - 1;
	temp.size = 4;
	temp.data = (unsigned char *)&n;
	temp.attr = &attr;
	COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9, 0, 0, NULL);
	cob_move (&temp, f);
}

void
cob_accept_arg_value (cob_field *f)
{
	if (current_arg >= cob_argc) {
		cob_set_exception (COB_EC_IMP_ACCEPT);
		return;
	}
	cob_memcpy (f, cob_argv[current_arg],
		    strlen (cob_argv[current_arg]));
	current_arg++;
}

/* Environment variable */

void
cob_display_environment (const cob_field *f)
{
	size_t	i;

	if (cob_local_env_size < f->size) {
		cob_local_env_size = f->size;
		if (cob_local_env) {
			free (cob_local_env);
		}
		cob_local_env = cob_malloc (cob_local_env_size + 1U);
	}
	cob_field_to_string (f, cob_local_env, cob_local_env_size);
	if (unlikely(cobglobptr->cob_env_mangle)) {
		for (i = 0; i < strlen (cob_local_env); ++i) {
			if (!isalnum ((int)cob_local_env[i])) {
				cob_local_env[i] = '_';
			}
		}
	}
}

void
cob_display_env_value (const cob_field *f)
{
	char	*p;
	char	*env2;
	size_t	len;

	if (!cob_local_env) {
		cob_set_exception (COB_EC_IMP_DISPLAY);
		return;
	}
	if (!*cob_local_env) {
		cob_set_exception (COB_EC_IMP_DISPLAY);
		return;
	}
	env2 = cob_malloc (f->size + 1U);
	cob_field_to_string (f, env2, f->size);
	len = strlen (cob_local_env) + strlen (env2) + 3U;
	p = cob_fast_malloc (len);
	sprintf (p, "%s=%s", cob_local_env, env2);
	free (env2);
	if (putenv (p) != 0) {
		cob_set_exception (COB_EC_IMP_DISPLAY);
		return;
	}
	/* Rescan term/screen variables */
	cob_rescan_env_vals ();
}

void
cob_set_environment (const cob_field *f1, const cob_field *f2)
{
	cob_display_environment (f1);
	cob_display_env_value (f2);
}

void
cob_get_environment (const cob_field *envname, cob_field *envval)
{
	const char	*p;
	char		*buff;
	size_t		size;

	if (envname->size == 0 || envval->size == 0) {
		cob_set_exception (COB_EC_IMP_ACCEPT);
		return;
	}

	buff = cob_malloc (envname->size + 1U);
	cob_field_to_string (envname, buff, envname->size);
	if (unlikely(cobglobptr->cob_env_mangle)) {
		for (size = 0; size < strlen (buff); ++size) {
			if (!isalnum ((int)buff[size])) {
				buff[size] = '_';
			}
		}
	}
	p = getenv (buff);
	if (!p) {
		cob_set_exception (COB_EC_IMP_ACCEPT);
		p = " ";
	}
	cob_memcpy (envval, p, strlen (p));
	free (buff);
}

void
cob_accept_environment (cob_field *f)
{
	const char *p = NULL;

	if (cob_local_env) {
		p = getenv (cob_local_env);
	}
	if (!p) {
		cob_set_exception (COB_EC_IMP_ACCEPT);
		p = " ";
	}
	cob_memcpy (f, p, strlen (p));
}

void
cob_chain_setup (void *data, const size_t parm, const size_t size)
{
	size_t	len;

	memset (data, ' ', size);
	if (parm <= (size_t)cob_argc - 1) {
		len = strlen (cob_argv[parm]);
		if (len <= size) {
			memcpy (data, cob_argv[parm], len);
		} else {
			memcpy (data, cob_argv[parm], size);
		}
	} else {
		memset (data, ' ', size);
	}
	cobglobptr->cob_call_params = cob_argc - 1;
}

void
cob_allocate (unsigned char **dataptr, cob_field *retptr,
	      cob_field *sizefld, cob_field *initialize)
{
	void			*mptr;
	struct cob_alloc_cache	*cache_ptr;
	int			fsize;
	cob_field		temp;

	/* ALLOCATE */
	cobglobptr->cob_exception_code = 0;
	mptr = NULL;
	fsize = cob_get_int (sizefld);
	if (fsize > 0) {
		cache_ptr = cob_malloc (sizeof (struct cob_alloc_cache));
		mptr = malloc ((size_t)fsize);
		if (!mptr) {
			cob_set_exception (COB_EC_STORAGE_NOT_AVAIL);
			free (cache_ptr);
		} else {
			if (initialize) {
				temp.size = (size_t)fsize;
				temp.data = mptr;
				temp.attr = &const_alpha_attr;
				cob_move (initialize, &temp);
			} else {
				memset (mptr, 0, (size_t)fsize);
			}
			cache_ptr->cob_pointer = mptr;
			cache_ptr->size = (size_t)fsize;
			cache_ptr->next = cob_alloc_base;
			cob_alloc_base = cache_ptr;
		}
	}
	if (dataptr) {
		*dataptr = mptr;
	}
	if (retptr) {
		*(void **)(retptr->data) = mptr;
	}
}

void
cob_free_alloc (unsigned char **ptr1, unsigned char *ptr2)
{
	struct cob_alloc_cache	*cache_ptr;
	struct cob_alloc_cache	*prev_ptr;
	void			*vptr1;

	/* FREE */
	cobglobptr->cob_exception_code = 0;
	cache_ptr = cob_alloc_base;
	prev_ptr = cob_alloc_base;
	if (ptr1 && *ptr1) {
		vptr1 = *ptr1;
		for (; cache_ptr; cache_ptr = cache_ptr->next) {
			if (vptr1 == cache_ptr->cob_pointer) {
				free (cache_ptr->cob_pointer);
				if (cache_ptr == cob_alloc_base) {
					cob_alloc_base = cache_ptr->next;
				} else {
					prev_ptr->next = cache_ptr->next;
				}
				free (cache_ptr);
				*ptr1 = NULL;
				return;
			}
			prev_ptr = cache_ptr;
		}
		cob_set_exception (COB_EC_STORAGE_NOT_ALLOC);
		return;
	}
	if (ptr2 && *(void **)ptr2) {
		for (; cache_ptr; cache_ptr = cache_ptr->next) {
			if (*(void **)ptr2 == cache_ptr->cob_pointer) {
				free (cache_ptr->cob_pointer);
				if (cache_ptr == cob_alloc_base) {
					cob_alloc_base = cache_ptr->next;
				} else {
					prev_ptr->next = cache_ptr->next;
				}
				free (cache_ptr);
				*(void **)ptr2 = NULL;
				return;
			}
			prev_ptr = cache_ptr;
		}
		cob_set_exception (COB_EC_STORAGE_NOT_ALLOC);
		return;
	}
}

char *
cob_getenv (const char *name)
{
	char	*p;

	if (name) {
		p = getenv (name);
		if (p) {
			return cob_strdup (p);
		}
	}
	return NULL;
}

int
cob_putenv (char *name)
{
	int	ret;

	if (name && strchr (name, '=')) {
		ret = putenv (cob_strdup(name));
		if (!ret) {
			cob_rescan_env_vals ();
		}
		return ret;
	}
	return -1;
}

int
cob_extern_init (void)
{
	cob_init (0, NULL);
	return 0;
}

void *
cob_command_line (int flags, int *pargc, char ***pargv,
		  char ***penvp, char **pname)
{
#if	0	/* RXWRXW cob_command_line */
	char		**spenvp;
	char		*spname;
#else
	COB_UNUSED (penvp);
	COB_UNUSED (pname);
#endif

	COB_UNUSED (flags);

	if (!cob_initialized) {
		cob_runtime_error (_("'cobcommandline' - Runtime has not been initialized"));
		cob_stop_run (1);
	}
	if (pargc && pargv) {
		cob_argc = *pargc;
		cob_argv = *pargv;
	}

#if	0	/* RXWRXW cob_command_line */
	if (penvp) {
		spenvp = *penvp;
	}
	if (pname) {
		spname = *pname;
	}
#endif

	/* What are we supposed to return here? */
	return NULL;
}

int
cob_tidy (void)
{
	struct exit_handlerlist	*h;

	if (!cob_initialized) {
		exit (1);
	}
	if (exit_hdlrs != NULL) {
		h = exit_hdlrs;
		while (h != NULL) {
			h->proc ();
			h = h->next;
		}
	}
	cob_terminate_routines ();
	return 0;
}

/* System routines */

int
cob_sys_exit_proc (const void *dispo, const void *pptr)
{
	struct exit_handlerlist *hp;
	struct exit_handlerlist *h;
	const unsigned char	*x;
	int			(**p)(void);

	COB_CHK_PARMS (CBL_EXIT_PROC, 2);

	memcpy (&p, &pptr, sizeof (void *));
	if (!p || !*p) {
		return -1;
	}

	hp = NULL;
	h = exit_hdlrs;
	/* Remove handler anyway */
	while (h != NULL) {
		if (h->proc == *p) {
			if (hp != NULL) {
				hp->next = h->next;
			} else {
				exit_hdlrs = h->next;
			}
			if (hp) {
				free (hp);
			}
			break;
		}
		hp = h;
		h = h->next;
	}
	x = dispo;
	if   (*x != 0 && *x != 2 && *x != 3) {
		/* Remove handler */
		return 0;
	}
	h = cob_malloc (sizeof(struct exit_handlerlist));
	h->next = exit_hdlrs;
	h->proc = *p;
	exit_hdlrs = h;
	return 0;
}

int
cob_sys_error_proc (const void *dispo, const void *pptr)
{
	struct handlerlist	*hp = NULL;
	struct handlerlist	*h = hdlrs;
	const unsigned char	*x;
	int			(**p)(char *s);

	COB_CHK_PARMS (CBL_ERROR_PROC, 2);

	memcpy (&p, &pptr, sizeof (void *));
	if (!p || !*p) {
		return -1;
	}

	hp = NULL;
	h = hdlrs;
	/* Remove handler anyway */
	while (h != NULL) {
		if (h->proc == *p) {
			if (hp != NULL) {
				hp->next = h->next;
			} else {
				hdlrs = h->next;
			}
			if (hp) {
				free (hp);
			}
			break;
		}
		hp = h;
		h = h->next;
	}
	x = dispo;
	if (*x != 0) {
		/* Remove handler */
		return 0;
	}
	h = cob_malloc (sizeof(struct handlerlist));
	h->next = hdlrs;
	h->proc = *p;
	hdlrs = h;
	return 0;
}

int
cob_sys_system (const void *cmdline)
{
	const char	*cmd;
	char		*buff;
	int		i;

	COB_CHK_PARMS (SYSTEM, 1);

	if (COB_MODULE_PTR->cob_procedure_params[0]) {
		cmd = cmdline;
		i = (int)COB_MODULE_PTR->cob_procedure_params[0]->size;
		if (unlikely(i > COB_MEDIUM_MAX)) {
			cob_runtime_error (_("Parameter to SYSTEM call is larger than 8192 characters"));
			cob_stop_run (1);
		}
		i--;
		for (; i >= 0; --i) {
			if (cmd[i] != ' ' && cmd[i] != 0) {
				break;
			}
		}
		if (i >= 0) {
			buff = cob_malloc ((size_t)(i + 2));
			memcpy (buff, cmd, (size_t)(i + 1));
			if (cobglobptr->cob_screen_initialized) {
				cob_screen_set_mode (0);
			}
			i = system (buff);
			free (buff);
			if (cobglobptr->cob_screen_initialized) {
				cob_screen_set_mode (1U);
			}
			return i;
		}
	}
	return 1;
}

int
cob_sys_and (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_AND, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] &= data_1[n];
	}
	return 0;
}

int
cob_sys_or (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_OR, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] |= data_1[n];
	}
	return 0;
}

int
cob_sys_nor (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_NOR, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] = ~(data_1[n] | data_2[n]);
	}
	return 0;
}

int
cob_sys_xor (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_XOR, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] ^= data_1[n];
	}
	return 0;
}

int
cob_sys_imp (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_IMP, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] = (~data_1[n]) | data_2[n];
	}
	return 0;
}

int
cob_sys_nimp (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_NIMP, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] = data_1[n] & (~data_2[n]);
	}
	return 0;
}

int
cob_sys_eq (const void *p1, void *p2, const int length)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_EQ, 3);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_2[n] = ~(data_1[n] ^ data_2[n]);
	}
	return 0;
}

int
cob_sys_not (void *p1, const int length)
{
	cob_u8_ptr	data_1 = p1;
	size_t		n;

	COB_CHK_PARMS (CBL_NOT, 2);

	if (length <= 0) {
		return 0;
	}
	for (n = 0; n < (size_t)length; ++n) {
		data_1[n] = ~data_1[n];
	}
	return 0;
}

int
cob_sys_xf4 (void *p1, const void *p2)
{
	cob_u8_ptr		data_1 = p1;
	const cob_u8_ptr	data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_XF4, 2);

	*data_1 = 0;
	for (n = 0; n < 8; ++n) {
		*data_1 |= (data_2[n] & 1) << (7 - n);
	}
	return 0;
}

int
cob_sys_xf5 (const void *p1, void *p2)
{
	const cob_u8_ptr	data_1 = p1;
	cob_u8_ptr		data_2 = p2;
	size_t			n;

	COB_CHK_PARMS (CBL_XF5, 2);

	for (n = 0; n < 8; ++n) {
		data_2[n] = (*data_1 & (1 << (7 - n))) ? 1 : 0;
	}
	return 0;
}

int
cob_sys_x91 (void *p1, const void *p2, void *p3)
{
	cob_u8_ptr		result = p1;
	const cob_u8_ptr	func = p2;
	cob_u8_ptr		parm = p3;
	unsigned char		*p;
	size_t			i;

	switch (*func) {
	case 11:
		/* Set switches */
		p = parm;
		for (i = 0; i < 8; ++i, ++p) {
			if (*p == 0) {
				cob_switch[i] = 0;
			} else if (*p == 1) {
				cob_switch[i] = 1;
			}
		}
		*result = 0;
		break;
	case 12:
		/* Get switches */
		p = parm;
		for (i = 0; i < 8; ++i, ++p) {
			*p = (unsigned char)cob_switch[i];
		}
		*result = 0;
		break;
	case 16:
		/* Return number of call parameters */
		*parm = (unsigned char)COB_MODULE_PTR->module_num_params;
		*result = 0;
		break;
	default:
		*result = 1;
		break;
	}
	return 0;
}

int
cob_sys_toupper (void *p1, const int length)
{
	cob_u8_ptr	data = p1;
	size_t		n;

	COB_CHK_PARMS (CBL_TOUPPER, 2);

	if (length > 0) {
		for (n = 0; n < (size_t)length; ++n) {
			if (islower (data[n])) {
				data[n] = (cob_u8_t)toupper (data[n]);
			}
		}
	}
	return 0;
}

int
cob_sys_tolower (void *p1, const int length)
{
	cob_u8_ptr	data = p1;
	size_t		n;

	COB_CHK_PARMS (CBL_TOLOWER, 2);

	if (length > 0) {
		for (n = 0; n < (size_t)length; ++n) {
			if (isupper (data[n])) {
				data[n] = (cob_u8_t)tolower (data[n]);
			}
		}
	}
	return 0;
}

int
cob_sys_oc_nanosleep (const void *data)
{
	cob_s64_t	nsecs;
#if	defined(_WIN32) || defined(__370__) || defined(__OS400__)
	unsigned int	msecs;
#elif	defined(HAVE_NANO_SLEEP)
	struct timespec	tsec;
#else
	unsigned int	msecs;
#endif

	COB_UNUSED (data);

	COB_CHK_PARMS (CBL_OC_NANOSLEEP, 1);

	if (COB_MODULE_PTR->cob_procedure_params[0]) {
		nsecs = cob_get_llint (COB_MODULE_PTR->cob_procedure_params[0]);
		if (nsecs > 0) {
#ifdef	_WIN32
			msecs = (unsigned int)(nsecs / 1000000);
			if (msecs > 0) {
				Sleep (msecs);
			}
#elif	defined(__370__) || defined(__OS400__)
			msecs = (unsigned int)(nsecs / 1000000000);
			if (msecs > 0) {
				sleep (msecs);
			}
#elif	defined(HAVE_NANO_SLEEP)
			tsec.tv_sec = nsecs / 1000000000;
			tsec.tv_nsec = nsecs % 1000000000;
			nanosleep (&tsec, NULL);
#else
			msecs = (unsigned int)(nsecs / 1000000000);
			if (msecs > 0) {
				sleep (msecs);
			}
#endif
		}
	}
	return 0;
}

int
cob_sys_getpid (void)
{
	return (int)getpid ();
}

int
cob_sys_return_args (void *data)
{
	COB_UNUSED (data);

	COB_CHK_PARMS (C$NARG, 1);

	if (COB_MODULE_PTR->cob_procedure_params[0]) {
		cob_set_int (COB_MODULE_PTR->cob_procedure_params[0],
			     COB_MODULE_PTR->module_num_params);
	}
	return 0;
}

int
cob_sys_calledby (void *data)
{
	size_t		size;
	size_t		msize;

	COB_CHK_PARMS (C$CALLEDBY, 1);

	if (!COB_MODULE_PTR->cob_procedure_params[0]) {
		return -1;
	}
	size = COB_MODULE_PTR->cob_procedure_params[0]->size;
	memset (data, ' ', size);
	if (!COB_MODULE_PTR->next) {
		return 0;
	}
	msize = strlen (COB_MODULE_PTR->next->module_name);
	if (msize > size) {
		msize = size;
	}
	memcpy (data, COB_MODULE_PTR->next->module_name, msize);
	return 1;
}

int
cob_sys_parameter_size (void *data)
{
	int	n;

	COB_UNUSED (data);

	COB_CHK_PARMS (C$PARAMSIZE, 1);

	if (COB_MODULE_PTR->cob_procedure_params[0]) {
		n = cob_get_int (COB_MODULE_PTR->cob_procedure_params[0]);
		if (n > 0 && n <= COB_MODULE_PTR->module_num_params) {
			n--;
			if (COB_MODULE_PTR->next &&
			    COB_MODULE_PTR->next->cob_procedure_params[n]) {
				return (int)COB_MODULE_PTR->next->cob_procedure_params[n]->size;
			}
		}
	}
	return 0;
}

int
cob_sys_getopt_long_long (void* so, void* lo, void* idx, const int long_only, void* return_char, void* opt_val) {
	/*
	 * cob_argc is a static int containing argc from runtime
	 * cob_argv is a static char** containing argv from runtime
	 */

	size_t opt_val_size;
	size_t so_size;
	size_t lo_size;
	
	unsigned int lo_amount;

	int exit_status;

	char* shortoptions;

	struct option* longoptions;
	longoption_def* l;

	int longind;
	unsigned int i;
	int j;

	unsigned int optlen;
	unsigned int c;

	COB_UNUSED (idx);
	COB_UNUSED (lo);
	COB_UNUSED (so);

	COB_CHK_PARMS (CBL_OC_GETOPT, 6);

	/*
	 * Read in sizes of some parameters
	 */
	lo_size = COB_MODULE_PTR->cob_procedure_params[1]->size;
	so_size = COB_MODULE_PTR->cob_procedure_params[0]->size;
	opt_val_size = COB_MODULE_PTR->cob_procedure_params[5]->size;

	/*
	 * Buffering longoptions (cobol), target format (struct option)
	 */
	if (lo_size % sizeof(longoption_def) == 0) {
		lo_amount = (int)lo_size / sizeof(longoption_def);
		longoptions = (struct option*) cob_malloc(sizeof(struct option) * (lo_amount + 1U));
	}
	else {
		cob_runtime_error (_("Call to CBL_OC_GETOPT with wrong longoption size."));
		cob_stop_run (1);
	}

	if (COB_MODULE_PTR->cob_procedure_params[2]) {
		longind = cob_get_int (COB_MODULE_PTR->cob_procedure_params[2]);
	}

	/*
	 * Add 0-termination to strings.
	 */
	shortoptions = cob_malloc(so_size + 1U);
	cob_field_to_string(COB_MODULE_PTR->cob_procedure_params[0], shortoptions, so_size);

	l = (struct longoption_def*) (COB_MODULE_PTR->cob_procedure_params[1]->data);

	for(i=0; i < lo_amount; i++) {
		j = sizeof(l->name) - 1;
		while(j >= 0 && l->name[j] == 0x20) {
			l->name[j] = 0x00;
			j--;
		}
		longoptions->name = l->name;
		longoptions->has_arg = (int) l->has_option - '0';
		memcpy(&longoptions->flag, l->return_value_pointer, sizeof(char*));
		longoptions->val = (int)l->return_value;

		l = l + 1; /* +1 means pointer + 1*sizeof(longoption_def) */
		longoptions = longoptions + 1;
	}

	/*
	 * Appending final record, so getopt can spot the end of longoptions
	 */
	longoptions->name = NULL;
	longoptions->has_arg = 0;
	longoptions->flag = NULL;
	longoptions->val = 0;


	l -= lo_amount; /* Set pointer back to begin of longoptions */
	longoptions -= lo_amount;

	c = cob_getopt_long_long(cob_argc, cob_argv, shortoptions, longoptions, &longind, long_only);

	/*
	 * Write data back to Cobol
	 */
	if (c == '?' || c == ':' || c == 'W' || c == -1 || c == 0) exit_status = c;
	else exit_status = 3;
	
	cob_set_int(COB_MODULE_PTR->cob_procedure_params[2], longind);
	memcpy(return_char, &c, 1);
	if(cob_optarg != NULL) {
		memset(opt_val, 0x00, opt_val_size);
		
		optlen = strlen(cob_optarg);
		if (optlen > opt_val_size) {
			/* Returncode 2 for "Optionvalue too long => cut" */
			optlen = opt_val_size;
			exit_status = 2;
		}
		memcpy(opt_val, cob_optarg, optlen);
	}


	free(shortoptions);
	free(longoptions);

	return exit_status;

}

int
cob_sys_sleep (const void *data)
{
	int	n;

	COB_UNUSED (data);

	COB_CHK_PARMS (C$SLEEP, 1);

	if (COB_MODULE_PTR->cob_procedure_params[0]) {
		n = cob_get_int (COB_MODULE_PTR->cob_procedure_params[0]);
		if (n > 0 && n < 3600*24*7) {
#ifdef	_WIN32
			Sleep (n*1000);
#else
			sleep ((unsigned int)n);
#endif
		}
	}
	return 0;
}

int
cob_sys_printable (void *p1, ...)
{
	cob_u8_ptr		data;
	unsigned char		*dotptr;
	size_t			datalen;
	size_t			n;
	unsigned char		dotrep;
	va_list			args;

	COB_CHK_PARMS (C$PRINTABLE, 1);

	if (!COB_MODULE_PTR->cob_procedure_params[0]) {
		return 0;
	}
	data = p1;
	datalen = COB_MODULE_PTR->cob_procedure_params[0]->size;
	if (cobglobptr->cob_call_params > 1) {
		va_start (args, p1);
		dotptr = va_arg (args, unsigned char *);
		va_end (args);
		dotrep = *dotptr;
	} else {
		dotrep = (unsigned char)'.';
	}
	for (n = 0; n < datalen; ++n) {
		if (!isprint (data[n])) {
			data[n] = dotrep;
		}
	}
	return 0;
}

int
cob_sys_justify (void *p1, ...)
{
	cob_u8_ptr	data;
	unsigned char	*direction;
	size_t		datalen;
	size_t		left;
	size_t		right;
	size_t		movelen;
	size_t		centrelen;
	size_t		n;
	size_t		shifting;
	va_list		args;

	COB_CHK_PARMS (C$JUSTIFY, 1);

	if (!COB_MODULE_PTR->cob_procedure_params[0]) {
		return 0;
	}
	data = p1;
	datalen = COB_MODULE_PTR->cob_procedure_params[0]->size;
	if (datalen < 2) {
		return 0;
	}
	if (data[0] != ' ' && data[datalen - 1] != ' ') {
		return 0;
	}
	for (left = 0; left < datalen; ++left) {
		if (data[left] != ' ') {
			break;
		}
	}
	if (left == datalen) {
		return 0;
	}
	right = 0;
	for (n = datalen - 1; ; --n, ++right) {
		if (data[n] != ' ') {
			break;
		}
		if (n == 0) {
			break;
		}
	}
	movelen = datalen - left - right;
	shifting = 0;
	if (cobglobptr->cob_call_params > 1) {
		va_start (args, p1);
		direction = va_arg (args, unsigned char *);
		va_end (args);
		if (*direction == 'L') {
			shifting = 1;
		} else if (*direction == 'C') {
			shifting = 2;
		}
	}
	switch (shifting) {
	case 1:
		memmove (data, &data[left], movelen);
		memset (&data[movelen], ' ', datalen - movelen);
		break;
	case 2:
		centrelen = (left + right) / 2;
		memmove (&data[centrelen], &data[left], movelen);
		memset (data, ' ', centrelen);
		if ((left + right) % 2) {
			memset (&data[centrelen + movelen], ' ', centrelen + 1);
		} else {
			memset (&data[centrelen + movelen], ' ', centrelen);
		}
		break;
	default:
		memmove (&data[left + right], &data[left], movelen);
		memset (data, ' ', datalen - movelen);
		break;
	}
	return 0;
}

void
cob_set_locale (cob_field *locale, const int category)
{
#ifdef	HAVE_SETLOCALE
	char	*p;
	char	*buff;

	p = NULL;
	if (locale) {
		if (locale->size == 0) {
			return;
		}
		buff = cob_malloc (locale->size + 1U);
		cob_field_to_string (locale, buff, locale->size);
	} else {
		buff = NULL;
	}

	switch (category) {
	case COB_LC_COLLATE:
		p = setlocale (LC_COLLATE, buff);
		break;
	case COB_LC_CTYPE:
		p = setlocale (LC_CTYPE, buff);
		break;
#ifdef	LC_MESSAGES
	case COB_LC_MESSAGES:
		p = setlocale (LC_MESSAGES, buff);
		break;
#endif
	case COB_LC_MONETARY:
		p = setlocale (LC_MONETARY, buff);
		break;
	case COB_LC_NUMERIC:
		p = setlocale (LC_NUMERIC, buff);
		break;
	case COB_LC_TIME:
		p = setlocale (LC_TIME, buff);
		break;
	case COB_LC_ALL:
		p = setlocale (LC_ALL, buff);
		break;
	case COB_LC_USER:
		if (cobglobptr->cob_locale_orig) {
			p = setlocale (LC_ALL, cobglobptr->cob_locale_orig);
			(void)setlocale (LC_NUMERIC, "C");
		}
		break;
	case COB_LC_CLASS:
		if (cobglobptr->cob_locale_ctype) {
			p = setlocale (LC_CTYPE, cobglobptr->cob_locale_ctype);
		}
		break;
	}
	if (buff) {
		free (buff);
	}
	if (!p) {
		cob_set_exception (COB_EC_LOCALE_MISSING);
		return;
	}
	p = setlocale (LC_ALL, NULL);
	if (p) {
		if (cobglobptr->cob_locale) {
			free (cobglobptr->cob_locale);
		}
		cobglobptr->cob_locale = cob_strdup (p);
	}
#else
	cob_set_exception (COB_EC_LOCALE_MISSING);
#endif
}

char*
cob_int_to_string(int i, char* number) {
	if(!number) return NULL;
	sprintf(number, "%i", i);
	return number;
}

char*
cob_int_to_formatted_bytestring(int i, char* number) {

	double d;
	char* strB;

	if(!number) return NULL;

	strB = (char*) cob_fast_malloc(3);

	if (i > (1024 * 1024)) {
		d = i / 1024.0 / 1024.0;
		strB = (char*) "MB";
	} else if (i > 1024) {
		d = i / 1024.0;
		strB = (char*) "kB";
	} else {
		d = 0;
		strB = (char*) "B";
	}
	sprintf(number, "%3.2f %s", d, strB);
	return number;
}

char*
cob_strcat(char* str1, char* str2) {
	size_t l = strlen(str1) + strlen(str2) + 1;

	if(!strbuff || strlen(strbuff) != l) {
		free(strbuff);
		strbuff = (char*) cob_fast_malloc(l);
	}

	sprintf(strbuff, "%s%s", str1, str2);
	return strbuff;
}

char*
cob_strjoin(char** strarray, int size, char* separator) {

	char* result;
	int i;

	if(!strarray || size <= 0 || !separator) return NULL;

	result = strarray[0];
	for (i = 1; i < size; i++) {
		result = cob_strcat(cob_strdup(result), separator);
		result = cob_strcat(cob_strdup(result), strarray[i]);
	}

	return result;
}

char* cob_save_env_value(char* env_var, char* env_val) {
	if (!env_val) return NULL;

	if (env_var) free(env_var);
	env_var = (char*) cob_fast_malloc(strlen(env_val) + 1);
	strcpy(env_var, env_val);

	return env_var;
}

static void var_print(const char *msg, const char *val, const char *default_val,
		const unsigned int format) {
	char	*p;
	char	*token;
	size_t	n;
	size_t	lablen;
	size_t	toklen;

	switch (format) {
	case 0:
		printf("%-*.*s : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
		break;
		case 1: {
		printf("  %s: ", _("env"));
		lablen = CB_IMSG_SIZE - 2 - strlen(_("env")) - 2;
		printf("%-*.*s : ", lablen, lablen, msg);
			break;
		}
	case 2:
		printf("    %-*.*s     : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
		break;
	case 3:
		printf("        %-*.*s : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
		break;
	default:
		printf("%-*.*s : ", CB_IMSG_SIZE, CB_IMSG_SIZE, msg);
		break;
	}

	if (!val && !default_val) {
		putchar('\n');
		return;
	} else if (val && default_val && ((format != 2 && val[0] == 0x30) || strcmp(val, default_val) == 0)) {
		val = cob_strcat((char*) default_val, (char*) _(" (default)"));
	} else if (!val && default_val) {
		val = default_val;
	}

	if (val && strlen(val) <= CB_IVAL_SIZE) {
		printf("%s", val);
		putchar ('\n');

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
				if (format == 2 || format == 3)
					printf("\n        %*.*s", CB_IMSG_SIZE + 3,
					CB_IMSG_SIZE + 3, " ");
				else
					printf("\n%*.*s", CB_IMSG_SIZE + 3, CB_IMSG_SIZE + 3, " ");
			}
			n = 0;
		}
		printf ("%s%s", (n ? " " : ""), token);
		n += toklen;
	}
	putchar ('\n');
	free (p);

}


void
print_runtime_env(void) {
	char* no_default;
	char* not_set;
	char* intstring;
	char* intstring2;

	printf("GNU Cobol runtime environment\n\n");
	printf("All values were resolved from current environment. \n\n");
	/* Alles aus common.c --> cob_init und cob_init_... - einigermaßen sinnvoll sortiert (ggf. Zwischenüberschriften ...*/

	if(!cob_initialized) {
		cob_init(cob_argc, cob_argv);
	}

	no_default = (char*) _("No");
	not_set = (char*) _("not set");
	intstring = (char*) cob_fast_malloc(10);
	intstring2 = (char*) cob_fast_malloc(10);

	printf(_("Call environment\n"));

	var_print("COB_LIBRARY_PATH", runtimeptr->cob_library_path_env, not_set,
			2);
	var_print("resolve_path",
			cob_strjoin(runtimeptr->resolve_path, *(runtimeptr->resolve_size),
					(char*) PATHSEPS), not_set, 3);
	var_print("COB_PRE_LOAD", runtimeptr->cob_preload_env, not_set, 2);
	var_print("base_preload_ptr",
			runtimeptr->cob_preload_resolved, not_set, 3);
	var_print("COB_LOAD_CASE", runtimeptr->name_convert_env, not_set, 2);
	var_print("name_convert",
			cob_int_to_string(*(runtimeptr->name_convert), intstring),
			no_default, 3);
	var_print("COB_PHYSICAL_CANCEL", runtimeptr->physical_cancel_env,
			not_set, 2);
	var_print("physical_cancel",
			cob_int_to_string(*(runtimeptr->physical_cancel), intstring),
			no_default, 3);

	printf(_("\n\nFile I/O\n"));
	var_print("COB_FILE_PATH", runtimeptr->cob_file_path_env, not_set, 2);
	var_print("cob_file_path", runtimeptr->cob_file_path, not_set, 3);

	var_print("COB_FILEIO_TRACE", runtimeptr->cob_fileio_trace_env, not_set, 2);
	var_print("cob_fileio_trace", cob_int_to_string(*(runtimeptr->cob_fileio_trace), intstring),
                        no_default, 3);

	var_print("COB_SYNC", runtimeptr->cob_do_sync_env, not_set, 2);
	var_print("cob_do_sync",
			cob_int_to_string(*(runtimeptr->cob_do_sync), intstring),
			no_default, 3);

#if defined(WITH_INDEXED_BDB) || defined(WITH_INDEXED_BDB_1)
	var_print("COB_BDB_CACHE_SIZE", runtimeptr->cob_bdb_cache_size_env, not_set, 2);
	var_print("cob_bdb_cache_size",
			cob_int_to_formatted_bytestring(*(runtimeptr->cob_bdb_cache_size), intstring),
                        no_default, 3);

	var_print("COB_BDB_HOME", runtimeptr->cob_bdb_home_env, not_set, 2);
	var_print("cob_bdb_home", runtimeptr->cob_bdb_home, not_set, 3);
#endif

#if defined(WITH_SEQUENTIAL)
	var_print("COB_LS_NULLS", runtimeptr->cob_ls_nulls_env, not_set, 2);
	var_print("cob_ls_nulls",
			cob_int_to_string(*(runtimeptr->cob_ls_nulls), intstring),
			no_default, 3);

	var_print("COB_LS_FIXED", runtimeptr->cob_ls_fixed_env, not_set, 2);
	var_print("cob_ls_fixed",
			cob_int_to_string(*(runtimeptr->cob_ls_fixed), intstring),
			no_default, 3);

	var_print("COB_LS_UNIX_LF", runtimeptr->cob_ls_unix_lf_env, not_set, 2);
	var_print("cob_ls_unix_lf",
			cob_int_to_string(*(runtimeptr->cob_ls_unix_lf), intstring),
			no_default, 3);
#endif

#if defined(WITH_FILEIO_STATS)
	var_print("COB_FILEIO_STATS", runtimeptr->cob_fileio_stats_env, not_set, 2);
	var_print("cob_fileio_stats",
			cob_int_to_string(*(runtimeptr->cob_fileio_stats), intstring),
			no_default, 3);

	var_print("COB_FILEIO_STATS_REPORT", runtimeptr->cob_fileio_stats_report_env, not_set, 2);
	var_print("cob_fileio_stats_report", runtimeptr->cob_fileio_stats_report, not_set, 3);

	var_print("COB_FILEIO_STATS_DIRECTORY", runtimeptr->cob_fileio_stats_directory_env, not_set, 2);
	var_print("cob_fileio_stats_directory", runtimeptr->cob_fileio_stats_directory, not_set, 3);
#endif

	var_print("COB_SORT_MEMORY", runtimeptr->cob_sort_memory_env, not_set, 2);
	var_print("cob_sort_memory",
			cob_int_to_formatted_bytestring(*(runtimeptr->cob_sort_memory),
					intstring),
			cob_int_to_formatted_bytestring(COB_SORT_MEMORY, intstring2), 3);
/* NYI
	var_print("COB_SORT_CHUNK", runtimeptr->cob_sort_chunk_env, not_set, 2);
	var_print("cob_sort_chunk",
			cob_int_to_formatted_bytestring(*(runtimeptr->cob_sort_chunk),
					intstring),
			cob_int_to_formatted_bytestring(COB_SORT_CHUNK, intstring2), 3);
NYI */

	if (runtimeptr->cob_local_edit) {
		printf(_("\n\nLocale Properties\n"));
		var_print("COB_LOCALE_NUMERIC_EDITED", runtimeptr->cob_local_edit_env,
				not_set, 2);
		var_print("cob_local_edit",
				cob_int_to_string(*(runtimeptr->cob_local_edit), intstring),
				no_default, 3);
	}

	printf(_("\n\nScreen I/O\n"));
	var_print("COB_REDIRECT_DISPLAY",
			runtimeptr->cob_disp_to_stderr_env, not_set, 2);
	var_print("cob_disp_to_stderr",
			cob_int_to_string(cobglobptr->cob_disp_to_stderr,
					intstring), no_default, 3);
	var_print("COB_BELL", runtimeptr->cob_beep_str_env, not_set, 2);
	var_print("cob_beep_value", cob_int_to_string(cobglobptr->cob_beep_value, intstring), (char*) "0", 3);
	var_print("COB_TIMEOUT_SCALE", runtimeptr->cob_timeout_scale_env,
			not_set, 2);
	var_print("cob_timeout_scale",
			cob_int_to_string(cobglobptr->cob_timeout_scale,
					intstring), _("1000"), 3);
	var_print("COB_SCREEN_EXCEPTIONS",
			runtimeptr->cob_extended_status_env, not_set, 2);
	var_print("cob_extended_status",
			cob_int_to_string(cobglobptr->cob_extended_status,
					intstring), no_default, 3);
	var_print("COB_SCREEN_ESC", runtimeptr->cob_use_esc_env,
			not_set, 2);
	var_print("cob_screen_esc",
			cob_int_to_string(cobglobptr->cob_use_esc, intstring),
			no_default, 3);
	
	printf(_("\n\nMiscellaneous\n"));
	var_print("COB_SET_TRACE", runtimeptr->cob_line_trace_env, not_set, 2);
	var_print("cob_line_trace", cob_int_to_string(cob_line_trace, intstring), no_default, 3);
	cob_check_trace_file();
	var_print("COB_TRACE_FILE", cob_trace_env, not_set, 2);
	if(cob_trace_file != stderr) {
		var_print("cob_trace_file", cob_trace_env, NULL, 3);
	}
	else {
		var_print("cob_trace_file", _("stderr (default)"), NULL, 3);
	}
	var_print("COB_DISABLE_WARNINGS",
			runtimeptr->cob_display_warn_env, not_set, 2);
	var_print("cob_display_warn",
			cob_int_to_string(cobglobptr->cob_display_warn,
					intstring), no_default, 3);
	var_print("COB_ENV_MANGLE", runtimeptr->cob_env_mangle_env,
			not_set, 2);
	var_print("cob_env_mangle",
			cob_int_to_string(cobglobptr->cob_env_mangle, intstring),
			no_default, 3);
}

void
print_version(void) {
	char* cobc_buffer;
	char month[32];
	int day, year;

	cobc_buffer = cob_fast_malloc((size_t) COB_MINI_MAX);

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

	printf ("libcob (%s) %s.%d\n",
		PACKAGE_NAME, PACKAGE_VERSION, PATCH_LEVEL);
	puts ("Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida");
	puts ("Copyright (C) 2006-2012 Roger While");
	puts ("Copyright (C) 2009,2010,2012,2014 Simon Sobisch");
	puts (_("This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."));
	printf (_("Built     %s"), cobc_buffer);
	putchar ('\n');
	printf (_("Packaged  %s"), COB_TAR_DATE);
	putchar ('\n');

}

void
print_info(void) {
	char	buff[16];
	char	*s;

	print_version ();
	putchar ('\n');
	puts (_("Build information"));
	var_print (_("Build environment"),	COB_BLD_BUILD, "", 0);
	var_print("CC", COB_BLD_CC, "", 0);
	var_print("CPPFLAGS", COB_BLD_CPPFLAGS, "", 0);
	var_print("CFLAGS", COB_BLD_CFLAGS, "", 0);
	var_print("LD", COB_BLD_LD, "", 0);
	var_print("LDFLAGS", COB_BLD_LDFLAGS, "", 0);
	putchar ('\n');
	printf(_("C version %s%s"), OC_C_VERSION_PRF, OC_C_VERSION);
	putchar ('\n');
	puts (_("GNU Cobol information"));

//	if ((s = getenv ("COB_LIBRARY_PATH")) != NULL) {
//		var_print ("COB_LIBRARY_PATH",	s, "", 1);
//	}
	var_print("COB_MODULE_EXT", COB_MODULE_EXT, "", 0);
	var_print("COB_EXEEXT", COB_EXEEXT, "", 0);

#if	defined(USE_LIBDL) || defined(_WIN32)
	var_print(_("Dynamic loading"), _("System"), "", 0);
#else
	var_print (_("Dynamic loading"),	_("Libtool"), "", 0);
#endif

#ifdef	COB_PARAM_CHECK
	var_print ("\"CBL_\" param check",	_("Enabled"), "", 0);
#else
	var_print("\"CBL_\" param check", _("Disabled"), "", 0);
#endif

	snprintf (buff, sizeof(buff), "%d", WITH_VARSEQ);
	var_print(_("Variable format"), buff, "", 0);
	if ((s = getenv ("COB_VARSEQ_FORMAT")) != NULL) {
		var_print("COB_VARSEQ_FORMAT", s, "", 1);
	}

#ifdef	COB_LI_IS_LL
	var_print ("BINARY-C-LONG",	_("8 bytes"), "", 0);
#else
	var_print("BINARY-C-LONG", _("4 bytes"), "", 0);
#endif

#ifdef	WITH_SEQRA_EXTFH
	var_print (_("Sequential handler"),	_("External"), "", 0);
#else
	var_print(_("Sequential handler"), _("Internal"), "", 0);
#endif
#ifdef	WITH_INDEX_EXTFH
	var_print (_("ISAM handler"),		_("External"), "", 0);
#endif
#ifdef	WITH_DB
	var_print (_("ISAM handler"),		_("BDB"), "", 0);
#endif
#ifdef	WITH_CISAM
	var_print (_("ISAM handler"),		_("C-ISAM (Experimental)"), "", 0);
#endif
#ifdef	WITH_DISAM
	var_print (_("ISAM handler"),		_("D-ISAM (Experimental)"), "", 0);
#endif
#ifdef	WITH_VBISAM
	var_print(_("ISAM handler"), _("VBISAM (Experimental)"), "", 0);
#endif
}


void
cob_init (const int argc, char **argv)
{
	char		*s;
#if	defined(HAVE_READLINK) || defined(HAVE_GETEXECNAME)
	const char	*path;
#endif
	int		i;

	if (cob_initialized) {
		return;
	}

	cobglobptr = NULL;
	runtimeptr = (struct runtime_env*) cob_malloc(sizeof(struct runtime_env));

	cob_set_signal ();

	cob_alloc_base = NULL;
	cob_local_env = NULL;
	cob_last_sfile = NULL;
	commlnptr = NULL;
	basext = NULL;
	sort_keys = NULL;
	sort_collate = NULL;
	cob_current_program_id = NULL;
	cob_current_section = NULL;
	cob_current_paragraph = NULL;
	cob_source_file = NULL;
	cob_source_statement = NULL;
	cob_user_name = NULL;
	exit_hdlrs = NULL;
	hdlrs = NULL;
	commlncnt = 0;
	sort_nkeys = 0;
	cob_source_line = 0;
	cob_line_trace = 0;
	cob_local_env_size = 0;

	current_arg = 1;

	cob_argc = argc;
	cob_argv = argv;

	/* Get emergency buffer */
	runtime_err_str = cob_fast_malloc ((size_t)COB_ERRBUF_SIZE);

	/* Get global structure */
	cobglobptr = cob_malloc (sizeof(cob_global));

	cob_initialized = 1;

	if (argc) {
		cobglobptr->cob_first_init = 1;
	}

#ifdef	HAVE_SETLOCALE
	/* Prime the locale from user settings */
	s = setlocale (LC_ALL, "");
	if (s) {
		/* Save initial values */
		cobglobptr->cob_locale_orig = cob_strdup (s);
		s = setlocale (LC_CTYPE, NULL);
		if (s) {
			cobglobptr->cob_locale_ctype = cob_strdup (s);
		}
		s = setlocale (LC_COLLATE, NULL);
		if (s) {
			cobglobptr->cob_locale_collate = cob_strdup (s);
		}
#ifdef	LC_MESSAGES
		s = setlocale (LC_MESSAGES, NULL);
		if (s) {
			cobglobptr->cob_locale_messages = cob_strdup (s);
		}
#endif
		s = setlocale (LC_MONETARY, NULL);
		if (s) {
			cobglobptr->cob_locale_monetary = cob_strdup (s);
		}
		s = setlocale (LC_NUMERIC, NULL);
		if (s) {
			cobglobptr->cob_locale_numeric = cob_strdup (s);
		}
		s = setlocale (LC_TIME, NULL);
		if (s) {
			cobglobptr->cob_locale_time = cob_strdup (s);
		}
		/* Set to standard "C" locale for COBOL */
		setlocale (LC_NUMERIC, "C");
		setlocale (LC_CTYPE, "C");
		/* Save changed locale */
		s = setlocale (LC_ALL, NULL);
		if (s) {
			cobglobptr->cob_locale = cob_strdup (s);
		}
	}
#endif

#ifdef	_WIN32
	/* Allows running of tests under Win */
	s = getenv ("COB_UNIX_LF");
	if (s) {
		runtimeptr->cob_unix_lf_env = cob_save_env_value(runtimeptr->cob_unix_lf_env, s);

		if (*s == 'Y' || *s == 'y' || *s == '1') {

		cobglobptr->cob_unix_lf = 1;
		_setmode (_fileno (stdin), _O_BINARY);
		_setmode (_fileno (stdout), _O_BINARY);
		_setmode (_fileno (stderr), _O_BINARY);
	}
	}
#endif

	/* Call inits with runtimeptr to get the adresses of all */
	cob_init_numeric(cobglobptr);
	cob_init_strings();
	cob_init_move(cobglobptr, runtimeptr);
	cob_init_intrinsic(cobglobptr);
	cob_init_fileio(cobglobptr, runtimeptr);
	cob_init_call(cobglobptr, runtimeptr);
	cob_init_screenio(cobglobptr);
	cob_init_termio(cobglobptr);

	/* Set up library routine stuff */
	cobglobptr->cob_term_buff = cob_malloc ((size_t)COB_MEDIUM_BUFF);
	cob_rescan_env_vals ();

	/* Set switches */
	for (i = 0; i < COB_SWITCH_MAX; ++i) {
		sprintf (runtime_err_str, "COB_SWITCH_%d", i);
		s = getenv (runtime_err_str);
		if (s && (*s == '1' || strcasecmp (s, "ON") == 0)) {
			cob_switch[i] = 1;
		} else {
			cob_switch[i] = 0;
		}
	}

	/* Trace enable */
	s = getenv ("COB_SET_TRACE");
	if (s) {
		runtimeptr->cob_line_trace_env = cob_save_env_value(runtimeptr->cob_line_trace_env, s);

		if (*s == 'Y' || *s == 'y' || *s == '1') {
		cob_line_trace = 1;
	}
	}

	/* Trace file */
	s = getenv ("COB_TRACE_FILE");
	if (s) {
		cob_trace_env = (const char*) cob_save_env_value((char*) cob_trace_env, s);
		cob_trace_file = NULL;
	} else {
		cob_trace_env = NULL;
		cob_trace_file = stderr;
	}

	/* Disable runtime warnings */
	s = getenv ("COB_DISABLE_WARNINGS");
	if (s) {
		runtimeptr->cob_display_warn_env = cob_save_env_value(runtimeptr->cob_display_warn_env, s);

		if (*s == 'Y' || *s == 'y' || *s == '1') {
			cobglobptr->cob_display_warn = 0;
		} else {
			cobglobptr->cob_display_warn = 1;
		}
	}

	/* Mangle environment names */
	s = getenv ("COB_ENV_MANGLE");
	if (s) {
		runtimeptr->cob_env_mangle_env = cob_save_env_value(runtimeptr->cob_env_mangle_env, s);

		if (*s == 'Y' || *s == 'y' || *s == '1') {
			cobglobptr->cob_env_mangle = 1;
		}
	}

	/* Get user name */
	s = getenv ("USERNAME");
	if (s) {
		cob_user_name = cob_strdup (s);
	} else {
		s = getenv ("LOGNAME");
		if (s) {
			cob_user_name = cob_strdup (s);
		} else {
#ifdef	_WIN32
			unsigned long bsiz = COB_ERRBUF_SIZE;
			if (GetUserName (runtime_err_str, &bsiz)) {
				cob_user_name = cob_strdup (runtime_err_str);
			}
#elif	!defined(__OS400__)
			s = getlogin ();
			if (s) {
				cob_user_name = cob_strdup (s);
			}
#endif
		}
	}
	if (!cob_user_name) {
		cob_user_name = cob_strdup (_("Unknown"));
	}

	/* This must be last in this function as we do early return */
	/* from certain ifdef's */

#ifdef	_WIN32
	s = cob_malloc ((size_t)COB_LARGE_BUFF);
	i = GetModuleFileNameA (NULL, s, COB_LARGE_MAX);
	if (i > 0 && i < COB_LARGE_BUFF) {
		cobglobptr->cob_main_argv0 = cob_strdup (s);
		free (s);
		return;
	}
	free (s);
#elif	defined(HAVE_READLINK)
	path = NULL;
	if (!access ("/proc/self/exe", R_OK)) {
		path = "/proc/self/exe";
	} else if (!access ("/proc/curproc/file", R_OK)) {
		path = "/proc/curproc/file";
	} else if (!access ("/proc/self/path/a.out", R_OK)) {
		path = "/proc/self/path/a.out";
	}
	if (path) {
		s = cob_malloc ((size_t)COB_LARGE_BUFF);
		i = (int)readlink (path, s, (size_t)COB_LARGE_MAX);
		if (i > 0 && i < COB_LARGE_BUFF) {
			cobglobptr->cob_main_argv0 = cob_strdup (s);
			free (s);
			return;
		}
		free (s);
	}
#endif

#ifdef	HAVE_GETEXECNAME
	path = getexecname ();
	if (path) {
#ifdef	HAVE_REALPATH
		s = cob_malloc ((size_t)COB_LARGE_BUFF);
		if (realpath (path, s) != NULL) {
			cobglobptr->cob_main_argv0 = cob_strdup (s);
		} else {
			cobglobptr->cob_main_argv0 = cob_strdup (path);
		}
		free (s);
#else
		cobglobptr->cob_main_argv0 = cob_strdup (path);
#endif
		return;
	}
#endif

	if (argc && argv && argv[0]) {
#ifdef	_WIN32
		/* Returns malloced path or NULL */
		cobglobptr->cob_main_argv0 = _fullpath (NULL, argv[0], 1);
#elif	defined(HAVE_CANONICALIZE_FILE_NAME)
		/* Returns malloced path or NULL */
		cobglobptr->cob_main_argv0 = canonicalize_file_name (argv[0]);
#elif	defined(HAVE_REALPATH)
		s = cob_malloc ((size_t)COB_LARGE_BUFF);
		if (realpath (argv[0], s) != NULL) {
			cobglobptr->cob_main_argv0 = cob_strdup (s);
		}
		free (s);
#endif
		if (!cobglobptr->cob_main_argv0) {
			cobglobptr->cob_main_argv0 = cob_strdup (argv[0]);
		}
	} else {
		cobglobptr->cob_main_argv0 = cob_strdup (_("Unknown"));
	}
	/* The above must be last in this function as we do early return */
	/* from certain ifdef's */
}
