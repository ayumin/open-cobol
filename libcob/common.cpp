/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While
   Copyright (C) 2013 Sergey Kashyrin

   This file is part of GNU Cobol C++.

   The GNU Cobol C++ runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol C++ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.
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

#include <new>          // std::set_new_handler

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

struct cob_alloc_cache {
	cob_alloc_cache *	next;			/* Pointer to next */
	char *				cob_pointer;	/* Pointer to malloced space */
	size_t				size;			/* Item size */
};

/* EXTERNAL structure */

struct cob_external {
	cob_external *	next;		/* Pointer to next */
	char *			ext_alloc;	/* Pointer to malloced space */
	char *			ename;		/* External name */
	int				esize;		/* Item size */
};

#define COB_ERRBUF_SIZE		1024

/* Local variables */

static int				cob_initialized = 0;
static int				cob_argc;
static char **			cob_argv;
static cob_alloc_cache * cob_alloc_base;
static const char *		cob_last_sfile;

static cob_global *		cobglobptr;

static char *			runtime_err_str;

static const cob_field_attr	const_alpha_attr(COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL);

static char *			cob_local_env;
static char *			cob_user_name;
static int				current_arg;
static unsigned char *	commlnptr;
static size_t			commlncnt;
static size_t			cob_local_env_size;

static cob_external *	basext;

static size_t			sort_nkeys;
static cob_file_key *	sort_keys;
static const unsigned char * sort_collate;

static const char *		cob_current_program_id;
static const char *		cob_current_section;
static const char *		cob_current_paragraph;
static const char *		cob_source_file;
static const char *		cob_source_statement;
static const char *		cob_trace_env;
static FILE *			cob_trace_file;
static unsigned int		cob_source_line;
static unsigned int		cob_line_trace;

#if	defined(HAVE_SIGNAL_H) && defined(HAVE_SIG_ATOMIC_T)
static volatile sig_atomic_t	sig_is_handled = 0;
#endif

/* Function Pointer for external signal handling */
static void		(*cob_ext_sighdl) (int) = NULL;

#undef	COB_EXCEPTION
#define COB_EXCEPTION(code,tag,name,critical)	name,
static const char * const cob_exception_tab_name[] = {
	"None",		/* COB_EC_ZERO */
#include "exception.def"
	"Invalid"	/* COB_EC_MAX */
};

#undef	COB_EXCEPTION
#define COB_EXCEPTION(code,tag,name,critical)	0x##code,
static const int cob_exception_tab_code[] = {
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
	exit_handlerlist * next;
	int (*proc)(void);
} * exit_hdlrs;

/* Runtime error handling */
static struct handlerlist {
	handlerlist * next;
	int (*proc)(char * s);
} * hdlrs;

/* Local functions */

static void
cob_exit_common(void)
{
#ifdef	HAVE_SETLOCALE
	if(cobglobptr->cob_locale_orig) {
		(void) setlocale(LC_ALL, cobglobptr->cob_locale_orig);
		delete [] cobglobptr->cob_locale_orig;
	}
	if(cobglobptr->cob_locale) {
		delete [] cobglobptr->cob_locale;
	}
	if(cobglobptr->cob_locale_ctype) {
		delete [] cobglobptr->cob_locale_ctype;
	}
	if(cobglobptr->cob_locale_collate) {
		delete [] cobglobptr->cob_locale_collate;
	}
	if(cobglobptr->cob_locale_messages) {
		delete [] cobglobptr->cob_locale_messages;
	}
	if(cobglobptr->cob_locale_monetary) {
		delete [] cobglobptr->cob_locale_monetary;
	}
	if(cobglobptr->cob_locale_numeric) {
		delete [] cobglobptr->cob_locale_numeric;
	}
	if(cobglobptr->cob_locale_time) {
		delete [] cobglobptr->cob_locale_time;
	}
#endif

	if(cob_user_name) {
		delete [] cob_user_name;
	}
	if(commlnptr) {
		delete [] commlnptr;
	}
	if(cob_local_env) {
		delete [] cob_local_env;
	}

	/* Free library routine stuff */
	if(cobglobptr && cobglobptr->cob_term_buff) {
		delete [] cobglobptr->cob_term_buff;
	}

	/* Free cached externals */
	for(cob_external * p = basext; p;) {
		cob_external * q = p;
		p = p->next;
		if(q->ename) {
			delete [] q->ename;
		}
		if(q->ext_alloc) {
			delete [] q->ext_alloc;
		}
		delete q;
	}

	/* Free cached mallocs */
	for(cob_alloc_cache * x = cob_alloc_base; x;) {
		cob_alloc_cache * y = x;
		x = x->next;
		delete [] y->cob_pointer;
		delete y;
	}

	/* Free last stuff */
	if(runtime_err_str) {
		delete [] runtime_err_str;
	}
	if(cobglobptr) {
		if(cobglobptr->cob_main_argv0) {
			delete [] cobglobptr->cob_main_argv0;
		}
		delete cobglobptr;
	}
	cobglobptr = NULL;
	cob_initialized = 0;
}

static void
cob_terminate_routines(void)
{
	if(!cob_initialized) {
		return;
	}
	if(!cobglobptr) {
		return;
	}

	if(cob_trace_file && cob_trace_file != stderr) {
		fclose(cob_trace_file);
		cob_trace_file = NULL;
	}

	cob_exit_screen();
	cob_exit_fileio();
	cob_exit_intrinsic();
	cob_exit_strings();
	cob_exit_numeric();
	cob_exit_call();
	cob_exit_common();
}

#ifdef	HAVE_SIGNAL_H
extern "C" void COB_A_NORETURN
cob_sig_handler_ex(int sig)
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
		raise(sig);
#else
		kill(getpid(), sig);
#endif
		exit(sig);
}

extern "C" void COB_A_NORETURN
cob_sig_handler(int sig)
{
	const char *signal_name;

#if	defined(HAVE_SIGACTION) && !defined(SA_RESETHAND)
	struct sigaction	sa;
#endif

#ifdef	HAVE_SIG_ATOMIC_T
	if(sig_is_handled) {
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
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_DFL;
	(void)sigemptyset(&sa.sa_mask);
	(void)sigaction(sig, &sa, NULL);
#endif
#else
	(void)signal(sig, SIG_DFL);
#endif
	cob_exit_screen();
	putc('\n', stderr);
	if(cob_source_file) {
		fprintf(stderr, "%s: %u: ", cob_source_file, cob_source_line);
	}

#ifdef	SIGSEGV
	if(sig == SIGSEGV) {
		fprintf(stderr, _("Attempt to reference unallocated memory"));
	} else {
		fprintf (stderr, _("Caught Signal"));
	}
#else
	fprintf (stderr, _("Caught Signal"));
#endif
	putc(' ', stderr);
	fprintf(stderr, _("(Signal %s)"), signal_name);
	putc('\n', stderr);

	if(cob_initialized) {
		cob_terminate_routines();
		fprintf(stderr, _("Abnormal termination - File contents may be incorrect"));
	}
	putc('\n', stderr);
	fflush(stderr);

	cob_sig_handler_ex(sig);
}
#endif

static void (*old_handler)() = NULL;

static void COB_A_NORETURN
cobc_mem_handler()
{
	if(old_handler != NULL) {
		old_handler();
	}
	cob_fatal_error(COB_FERROR_MEMORY);
}

static void
cob_set_signal(void)
{
	old_handler = std::set_new_handler(cobc_mem_handler);
#ifdef	HAVE_SIGNAL_H

#ifdef	HAVE_SIGACTION
	struct sigaction	sa;
	struct sigaction	osa;

	memset(&sa, 0, sizeof(sa));
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
	(void)sigaction(SIGINT, NULL, &osa);
	if(osa.sa_handler != SIG_IGN) {
		(void)sigemptyset(&sa.sa_mask);
		(void)sigaction(SIGINT, &sa, NULL);
	}
#endif
#ifdef	SIGHUP
	(void)sigaction(SIGHUP, NULL, &osa);
	if(osa.sa_handler != SIG_IGN) {
		(void)sigemptyset(&sa.sa_mask);
		(void)sigaction(SIGHUP, &sa, NULL);
	}
#endif
#ifdef	SIGQUIT
	(void)sigaction(SIGQUIT, NULL, &osa);
	if(osa.sa_handler != SIG_IGN) {
		(void)sigemptyset(&sa.sa_mask);
		(void)sigaction(SIGQUIT, &sa, NULL);
	}
#endif
#ifdef	SIGTERM
	(void)sigaction(SIGTERM, NULL, &osa);
	if(osa.sa_handler != SIG_IGN) {
		(void)sigemptyset(&sa.sa_mask);
		(void)sigaction(SIGTERM, &sa, NULL);
	}
#endif
#ifdef	SIGPIPE
	(void)sigaction(SIGPIPE, NULL, &osa);
	if(osa.sa_handler != SIG_IGN) {
		(void)sigemptyset(&sa.sa_mask);
		(void)sigaction(SIGPIPE, &sa, NULL);
	}
#endif
#ifdef	SIGSEGV
	/* Take direct control of segmentation violation */
	(void)sigemptyset(&sa.sa_mask);
	(void)sigaction(SIGSEGV, &sa, NULL);
#endif

#else

#ifdef	SIGINT
	if(signal(SIGINT, SIG_IGN) != SIG_IGN) {
		(void)signal(SIGINT, cob_sig_handler);
	}
#endif
#ifdef	SIGHUP
	if(signal(SIGHUP, SIG_IGN) != SIG_IGN) {
		(void)signal(SIGHUP, cob_sig_handler);
	}
#endif
#ifdef	SIGQUIT
	if(signal(SIGQUIT, SIG_IGN) != SIG_IGN) {
		(void)signal(SIGQUIT, cob_sig_handler);
	}
#endif
#ifdef	SIGTERM
	if(signal(SIGTERM, SIG_IGN) != SIG_IGN) {
		(void)signal(SIGTERM, cob_sig_handler);
	}
#endif
#ifdef	SIGPIPE
	if(signal(SIGPIPE, SIG_IGN) != SIG_IGN) {
		(void)signal(SIGPIPE, cob_sig_handler);
	}
#endif
#ifdef	SIGSEGV
	/* Take direct control of segmentation violation */
	(void)signal(SIGSEGV, cob_sig_handler);
#endif

#endif
#endif
}

/* ASCII Sign
 * positive: 0123456789
 * negative: pqrstuvwxy
 */

static int
cob_get_sign_ascii(unsigned char * p)
{
#ifdef	COB_EBCDIC_MACHINE
	switch(*p) {
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
	if(*p >= (unsigned char)'p' && *p <= (unsigned char)'y') {
		*p &= ~64U;
		return -1;
	}
	*p = (unsigned char)'0';
	return 1;
#endif
}

static void
cob_put_sign_ascii(unsigned char * p)
{
#ifdef	COB_EBCDIC_MACHINE
	switch(*p) {
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
cob_get_sign_ebcdic(unsigned char * p)
{
	switch(*p) {
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
		*p = (unsigned char)('0' +(*p & 0x0F));
		if(*p >(unsigned char)'9') {
			*p = (unsigned char)'0';
		}
		return 1;
	}
}

static void
cob_put_sign_ebcdic(unsigned char * p, const int sign)
{
	if(sign < 0) {
		switch(*p) {
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
	switch(*p) {
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
common_cmpc(const unsigned char * s1, const unsigned int c,
			const size_t size, const unsigned char * col)
{
	if(unlikely(col)) {
		for(size_t i = 0; i < size; ++i) {
			int ret = col[s1[i]] - col[c];
			if(ret != 0) {
				return ret;
			}
		}
	} else {
		for(size_t i = 0; i < size; ++i) {
			int ret = s1[i] - c;
			if(ret != 0) {
				return ret;
			}
		}
	}
	return 0;
}

static int
common_cmps(const unsigned char * s1, const unsigned char * s2,
			const size_t size, const unsigned char * col)
{
	if(unlikely(col)) {
		for(size_t i = 0; i < size; ++i) {
			int ret = col[s1[i]] - col[s2[i]];
			if(ret != 0) {
				return ret;
			}
		}
	} else {
		for(size_t i = 0; i < size; ++i) {
			int ret = s1[i] - s2[i];
			if(ret != 0) {
				return ret;
			}
		}
	}
	return 0;
}

static int
cob_cmp_all(cob_field * f1, cob_field * f2)
{
	size_t size = f1->size;
	unsigned char * data = f1->data;
	int sign = COB_GET_SIGN(f1);
	const unsigned char * s = COB_MODULE_PTR->collating_sequence;
	int ret = 0;
	if(f2->size == 1) {
		ret = common_cmpc(data, f2->data[0], size, s);
	} else {
		while(size >= f2->size) {
			if((ret = common_cmps(data, f2->data, f2->size, s)) != 0) {
				size = 0;
				break;
			}
			size -= f2->size;
			data += f2->size;
		}
		if(size > 0) {
			ret = common_cmps(data, f2->data, size, s);
		}
	}
	if(COB_FIELD_TYPE(f1) != COB_TYPE_NUMERIC_PACKED) {
		COB_PUT_SIGN(f1, sign);
	}
	return ret;
}

static int
cob_cmp_alnum(cob_field * f1, cob_field * f2)
{
	int sign1 = COB_GET_SIGN(f1);
	int sign2 = COB_GET_SIGN(f2);
	size_t min = (f1->size < f2->size) ? f1->size : f2->size;
	const unsigned char * s = COB_MODULE_PTR->collating_sequence;

	/* Compare common substring */
	int ret = common_cmps(f1->data, f2->data, min, s);
	if(ret == 0) {
		/* Compare the rest(if any) with spaces */
		if(f1->size > f2->size) {
			ret = common_cmpc(f1->data + min, ' ', f1->size - min, s);
		} else if(f1->size < f2->size) {
			ret = -common_cmpc(f2->data + min, ' ', f2->size - min, s);
		}
	}
	if(COB_FIELD_TYPE(f1) != COB_TYPE_NUMERIC_PACKED) {
		COB_PUT_SIGN(f1, sign1);
	}
	if(COB_FIELD_TYPE(f2) != COB_TYPE_NUMERIC_PACKED) {
		COB_PUT_SIGN(f2, sign2);
	}
	return ret;
}

static int
sort_compare(const void * data1, const void * data2)
{
	for(size_t i = 0; i < sort_nkeys; ++i) {
		cob_field f1 = *sort_keys[i].field;
		cob_field f2 = f1;
		f1.data = (unsigned char *)data1 + sort_keys[i].offset;
		f2.data = (unsigned char *)data2 + sort_keys[i].offset;
		int cmp;
		if(COB_FIELD_IS_NUMERIC(&f1)) {
			cmp = cob_numeric_cmp(&f1, &f2);
		} else {
			cmp = common_cmps(f1.data, f2.data, f1.size, sort_collate);
		}
		if(cmp != 0) {
			return(sort_keys[i].flag == COB_ASCENDING) ? cmp : -cmp;
		}
	}
	return 0;
}

static void
cob_memcpy(cob_field * dst, const void * src, const size_t size)
{
	if(!dst->size) {
		return;
	}
	cob_field temp(size, (cob_u8_ptr)src, &const_alpha_attr);
	cob_move(&temp, dst);
}

static void
cob_check_trace_file(void)
{
	if(!cob_trace_env) {
		cob_trace_file = stderr;
		return;
	}
	if(!cobglobptr->cob_unix_lf) {
		cob_trace_file = fopen(cob_trace_env, "w");
	} else {
		cob_trace_file = fopen(cob_trace_env, "wb");
	}
	if(!cob_trace_file) {
		cob_trace_file = stderr;
	}
}

static void
cob_rescan_env_vals(void)
{
	/* termio */
	char * s = getenv("COB_REDIRECT_DISPLAY");
	if(s &&(*s == 'Y' || *s == 'y' || *s == '1')) {
		cobglobptr->cob_disp_to_stderr = 1;
	} else {
		cobglobptr->cob_disp_to_stderr = 0;
	}

	/* screenio */

	/* BELL disposition */
	/* Default to BEEP */
	cobglobptr->cob_beep_value = 0;
	s = getenv("COB_BELL");
	if(s) {
		if(!strcasecmp(s, "FLASH")) {
			cobglobptr->cob_beep_value = 1;
		} else if(!strcasecmp(s, "SPEAKER")) {
			cobglobptr->cob_beep_value = 2;
		} else {
			/* NO/NONE/OFF/0 */
			switch(*s) {
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
	s = getenv("COB_TIMEOUT_SCALE");
	if(s) {
		if(*s == '1') {
			cobglobptr->cob_timeout_scale = 100;
		} else if(*s == '2') {
			cobglobptr->cob_timeout_scale = 10;
		} else if(*s == '3') {
			cobglobptr->cob_timeout_scale = 1;
		}
	}

	/* Extended ACCEPT status returns */
	cobglobptr->cob_extended_status = 0;
	cobglobptr->cob_use_esc = 0;
	s = getenv("COB_SCREEN_EXCEPTIONS");
	if(s) {
		if(*s == 'Y' || *s == 'y' || *s == '1') {
			cobglobptr->cob_extended_status = 1;
			s = getenv("COB_SCREEN_ESC");
			if(s) {
				if(*s == 'Y' || *s == 'y' || *s == '1') {
					cobglobptr->cob_use_esc = 1;
				}
			}
		}
	}
}

/* Global functions */

int
cob_get_exception_code(void)
{
	return cobglobptr->cob_exception_code;
}

const char *
cob_get_exception_name(void)
{
	for(size_t n = 0; n < EXCEPTION_TAB_SIZE; ++n) {
		if(cobglobptr->cob_exception_code == cob_exception_tab_code[n]) {
			return cob_exception_tab_name[n];
		}
	}
	return NULL;
}

void
cob_set_exception(const int id)
{
	cobglobptr->cob_exception_code = cob_exception_tab_code[id];
	if(cobglobptr->cob_exception_code) {
		cobglobptr->cob_got_exception = 1;
		cobglobptr->cob_orig_statement = cob_source_statement;
		cobglobptr->cob_orig_line = cob_source_line;
		cobglobptr->cob_orig_program_id = cob_current_program_id;
		cobglobptr->cob_orig_section = cob_current_section;
		cobglobptr->cob_orig_paragraph = cob_current_paragraph;
	}
}

void
cob_accept_exception_status(cob_field * f)
{
	cob_set_int(f, cobglobptr->cob_exception_code);
}

void
cob_accept_user_name(cob_field * f)
{
	if(cob_user_name) {
		cob_memcpy(f, cob_user_name,
				   strlen(cob_user_name));
	} else {
		cob_memcpy(f, " ", (size_t)1);
	}
}

char *
cob_malloc(const size_t size)
{
	char * mptr = new char[size];
	memset(mptr, 0, size);
	return mptr;
}

void
cob_free(void * mptr)
{
	delete [](char *) mptr;
}

char *
cob_strdup(const char * p)
{
	size_t len = strlen((const char *) p);
	char * mptr = new char[len + 1];
	memcpy(mptr, p, len + 1);
	return mptr;
}

/* Caching versions of new/delete */
char *
cob_cache_malloc(const size_t size)
{
	cob_alloc_cache	* cache_ptr = new cob_alloc_cache;
	char * mptr = new char[size];
	memset(mptr, 0, size);
	cache_ptr->cob_pointer = mptr;
	cache_ptr->size = size;
	cache_ptr->next = cob_alloc_base;
	cob_alloc_base = cache_ptr;
	return mptr;
}

char *
cob_cache_realloc(char * ptr, const size_t size)
{
	if(!ptr) {
		return cob_cache_malloc(size);
	}
	for(cob_alloc_cache * cache_ptr = cob_alloc_base; cache_ptr; cache_ptr = cache_ptr->next) {
		if(ptr == cache_ptr->cob_pointer) {
			if(size <= cache_ptr->size) {
				return ptr;
			}
			char * mptr = new char[size];
			memcpy(mptr, cache_ptr->cob_pointer, cache_ptr->size);
			memset(mptr + cache_ptr->size, 0, size - cache_ptr->size);
			delete [] cache_ptr->cob_pointer;
			cache_ptr->cob_pointer = mptr;
			cache_ptr->size = size;
			return mptr;
		}
	}
	return ptr;
}

void
cob_cache_free(void * ptr)
{
	if(!ptr) {
		return;
	}
	cob_alloc_cache * prev_ptr = cob_alloc_base;
	for(cob_alloc_cache * cache_ptr = cob_alloc_base; cache_ptr; cache_ptr = cache_ptr->next) {
		if(ptr == cache_ptr->cob_pointer) {
			delete [](char *) ptr;
			if(cache_ptr == cob_alloc_base) {
				cob_alloc_base = cache_ptr->next;
			} else {
				prev_ptr->next = cache_ptr->next;
			}
			delete cache_ptr;
			return;
		}
		prev_ptr = cache_ptr;
	}
}

void
cob_set_location(const char * sfile, const unsigned int sline,
				 const char * csect, const char * cpara,
				 const char * cstatement)
{
	cob_current_program_id = COB_MODULE_PTR->module_name;
	cob_source_file = sfile;
	cob_source_line = sline;
	cob_current_section = csect;
	cob_current_paragraph = cpara;
	if(cstatement) {
		cob_source_statement = cstatement;
	}
	if(cob_line_trace) {
		if(!cob_trace_file) {
			cob_check_trace_file();
		}
		if(!cob_last_sfile || strcmp(cob_last_sfile, sfile)) {
			cob_last_sfile = sfile;
			fprintf(cob_trace_file, "Source :    '%s'\n", sfile);
		}
		fprintf(cob_trace_file,
				"Program-Id: %-16s Statement: %-21.21s  Line: %u\n",
				COB_MODULE_PTR->module_name ? COB_MODULE_PTR->module_name : "Unknown",
				cstatement ?(char *)cstatement : "Unknown",
				sline);
		fflush(cob_trace_file);
	}
}


void
cob_trace_section(const char * para, const char * source, const int line)
{
	if(cob_line_trace) {
		if(!cob_trace_file) {
			cob_check_trace_file();
		}
		if(source &&
				(!cob_last_sfile || strcmp(cob_last_sfile, source))) {
			cob_last_sfile = source;
			fprintf(cob_trace_file, "Source:     '%s'\n", source);
		}
		fprintf(cob_trace_file, "Program-Id: %-16s ",
			    COB_MODULE_PTR->module_name ? COB_MODULE_PTR->module_name : "Unknown");
		if(line) {
			fprintf(cob_trace_file, "%-34.34sLine: %d\n", para, line);
		} else {
			fprintf(cob_trace_file, "%s\n", para);
		}
		fflush(cob_trace_file);
	}
}

void
cob_ready_trace(void)
{
	cob_line_trace = 1;
}

void
cob_reset_trace(void)
{
	cob_line_trace = 0;
}

unsigned char *
cob_get_pointer(const void * srcptr)
{
	void * tmptr;
	memcpy(&tmptr, srcptr, sizeof(void *));
	return(cob_u8_ptr)tmptr;
}

void *
cob_get_prog_pointer(const void * srcptr)
{
	void * tmptr;
	memcpy(&tmptr, srcptr, sizeof(void *));
	return tmptr;
}

void
cob_field_to_string(const cob_field * f, void * str, const size_t maxsize)
{
	if(unlikely(f->size == 0)) {
		return;
	}
	size_t count = 0;
	size_t i = f->size - 1;
	for(; ;) {
		if(f->data[i] && f->data[i] != (unsigned char)' ') {
			count = i + 1;
			break;
		}
		if(!i) {
			break;
		}
		--i;
	}
	if(count > maxsize) {
		count = maxsize;
	}
	unsigned char * s = (unsigned char *)str;
	for(i = 0; i < count; ++i) {
		s[i] = f->data[i];
	}
	s[i] = 0;
}

void
cob_stop_run(const int status)
{
	if(!cob_initialized) {
		exit(1);
	}
	if(exit_hdlrs != NULL) {
		exit_handlerlist * h = exit_hdlrs;
		while(h != NULL) {
			h->proc();
			h = h->next;
		}
	}
	cob_terminate_routines();
	exit(status);
}

void
cob_runtime_error(const char * fmt, ...)
{
	va_list			ap;

#if	1	/* RXWRXW - Exit screen */
	/* Exit screen mode early */
	cob_exit_screen();
#endif

	if(hdlrs != NULL) {
		if(runtime_err_str) {
			char * p = runtime_err_str;
			if(cob_source_file) {
				sprintf(runtime_err_str, "%s: %u: ",
						cob_source_file, cob_source_line);
				p = runtime_err_str + strlen(runtime_err_str);
			}
			va_start(ap, fmt);
			vsprintf(p, fmt, ap);
			va_end(ap);
		}
		handlerlist * h = hdlrs;
		while(h != NULL) {
			if(runtime_err_str) {
				h->proc(runtime_err_str);
			} else {
				h->proc((char *)_("Malloc error"));
			}
			handlerlist * hp = h;
			h = h->next;
			delete hp;
		}
		hdlrs = NULL;
	}

	/* Prefix */
	if(cob_source_file) {
		fprintf(stderr, "%s: %u: ", cob_source_file, cob_source_line);
	}
	fputs("libcob: ", stderr);

	/* Body */
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	/* Postfix */
	putc('\n', stderr);
	fflush(stderr);
}

void
cob_fatal_error(const int fatal_error)
{
	switch(fatal_error) {
	case COB_FERROR_NONE:
		cob_runtime_error(_("cob_init() has not been called"));
		break;
	case COB_FERROR_CANCEL:
		cob_runtime_error(_("Attempt to CANCEL active program"));
		break;
	case COB_FERROR_INITIALIZED:
		cob_runtime_error(_("cob_init() has not been called"));
		break;
	case COB_FERROR_CODEGEN:
		cob_runtime_error(_("Codegen error - Please report this"));
		break;
	case COB_FERROR_CHAINING:
		cob_runtime_error(_("Recursive call of chained program"));
		break;
	case COB_FERROR_STACK:
		cob_runtime_error(_("Stack overflow, possible PERFORM depth exceeded"));
		break;
	case COB_FERROR_GLOBAL:
		cob_runtime_error(_("Invalid entry/exit in GLOBAL USE procedure"));
		break;
	case COB_FERROR_MEMORY:
		cob_runtime_error(_("Unable to allocate memory"));
		break;
	case COB_FERROR_MODULE:
		cob_runtime_error(_("Invalid entry into module"));
		break;
	case COB_FERROR_RECURSIVE:
		cob_runtime_error(_("Invalid recursive COBOL CALL"));
		break;
	case COB_FERROR_FILE:
		{
			unsigned char * file_status = cobglobptr->cob_error_file->file_status;
			int status = COB_D2I(file_status[0]) * 10 + COB_D2I(file_status[1]);
			const char * msg;
			switch(status) {
			case COB_STATUS_10_END_OF_FILE:
				msg = _("End of file");
				break;
			case COB_STATUS_14_OUT_OF_KEY_RANGE:
				msg = _("Key out of range");
				break;
			case COB_STATUS_21_KEY_INVALID:
				msg = _("Key order not ascending");
				break;
			case COB_STATUS_22_KEY_EXISTS:
				msg = _("Record key already exists");
				break;
			case COB_STATUS_23_KEY_NOT_EXISTS:
				msg = _("Record key does not exist");
				break;
			case COB_STATUS_30_PERMANENT_ERROR:
				msg = _("Permanent file error");
				break;
			case COB_STATUS_35_NOT_EXISTS:
				msg = _("File does not exist");
				break;
			case COB_STATUS_37_PERMISSION_DENIED:
				msg = _("Permission denied");
				break;
			case COB_STATUS_41_ALREADY_OPEN:
				msg = _("File already open");
				break;
			case COB_STATUS_42_NOT_OPEN:
				msg = _("File not open");
				break;
			case COB_STATUS_43_READ_NOT_DONE:
				msg = _("READ must be executed first");
				break;
			case COB_STATUS_44_RECORD_OVERFLOW:
				msg = _("Record overflow");
				break;
			case COB_STATUS_46_READ_ERROR:
				msg = _("Failed to read");
				break;
			case COB_STATUS_47_INPUT_DENIED:
				msg = _("READ/START not allowed");
				break;
			case COB_STATUS_48_OUTPUT_DENIED:
				msg = _("WRITE not allowed");
				break;
			case COB_STATUS_49_I_O_DENIED:
				msg = _("DELETE/REWRITE not allowed");
				break;
			case COB_STATUS_51_RECORD_LOCKED:
				msg = _("Record locked by another file connector");
				break;
			case COB_STATUS_57_I_O_LINAGE:
				msg = _("LINAGE values invalid");
				break;
			case COB_STATUS_61_FILE_SHARING:
				msg = _("File sharing conflict");
				break;
			case COB_STATUS_91_NOT_AVAILABLE:
				msg = _("Runtime library is not configured for this operation");
				break;
			default:
				msg = _("Unknown file error");
				break;
			}
			char * filename = new char[COB_FILE_BUFF];
			cob_field_to_string(cobglobptr->cob_error_file->assign,
								filename, (size_t)COB_FILE_MAX);
			cob_runtime_error(_("%s (Status = %02d) File : '%s'"),
							  msg, status, filename);
			delete [] filename;
			break;
		}
	case COB_FERROR_FUNCTION:
		cob_runtime_error(_("Attempt to use non-implemented function"));
		break;
	default:
		cob_runtime_error(_("Unknown failure : %d"), fatal_error);
		break;
	}
	cob_stop_run(1);
}

cob_global *
cob_get_global_ptr(void)
{
	if(unlikely(!cob_initialized)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	return cobglobptr;
}

void
cob_module_enter(cob_module ** module, cob_global ** mglobal,
				 const int auto_init)
{
	/* Check initialized */
	if(unlikely(!cob_initialized)) {
		if(auto_init) {
			cob_init(0, NULL);
		} else {
			cob_fatal_error(COB_FERROR_INITIALIZED);
		}
	}

	/* Set global pointer */
	*mglobal = cobglobptr;

	/* Check module pointer */
	if(!*module) {
		*module = (cob_module *) cob_cache_malloc(sizeof(cob_module));
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
cob_module_leave(cob_module * module)
{
	COB_UNUSED(module);
	/* Pop module pointer */
	COB_MODULE_PTR = COB_MODULE_PTR->next;
}

void *
cob_save_func(cob_field ** savefld, const int params,
			  const int eparams, ...)
{
	va_list			args;

	int numparams = (unlikely(params > eparams)) ? eparams : params;
	/* Allocate return field */
	*savefld = (cob_field *) cob_malloc(sizeof(cob_field));
	/* Allocate save area */
	cob_func_loc * fl = new cob_func_loc;
	fl->func_params = new cob_field *[numparams + 1];
	fl->data = new unsigned char *[numparams + 1];

	/* Save values */
	fl->save_module = COB_MODULE_PTR->next;
	fl->save_call_params = cobglobptr->cob_call_params;
	fl->save_proc_parms = COB_MODULE_PTR->cob_procedure_params;
	fl->save_num_params = COB_MODULE_PTR->module_num_params;

	/* Set current values */
	COB_MODULE_PTR->cob_procedure_params = fl->func_params;
	cobglobptr->cob_call_params = numparams;
	if(numparams) {
		va_start(args, eparams);
		for(int n = 0; n < numparams; ++n) {
			fl->func_params[n] = va_arg(args, cob_field *);
			if(fl->func_params[n]) {
				fl->data[n] = fl->func_params[n]->data;
			}
		}
		va_end(args);
	}
	return fl;
}

void
cob_restore_func(cob_func_loc * fl)
{
	/* Restore calling environment */
	cobglobptr->cob_call_params = fl->save_call_params;
#if	0	/* RXWRXW - MODNEXT */
	COB_MODULE_PTR->next = fl->save_module;
#endif
	COB_MODULE_PTR->cob_procedure_params = fl->save_proc_parms;
	COB_MODULE_PTR->module_num_params = fl->save_num_params;
	delete [] fl->data;
	delete [] fl->func_params;
	delete fl;
}

void
cob_check_version(const char * prog, const char * packver, const int patchlev)
{
	if(strcmp(packver, PACKAGE_VERSION) || patchlev > PATCH_LEVEL) {
		cob_runtime_error(_("Error - Version mismatch"));
		cob_runtime_error(_("%s has version/patch level %s/%d"), prog,
						  packver, patchlev);
		cob_runtime_error(_("Library has version/patch level %s/%d"),
						  PACKAGE_VERSION, PATCH_LEVEL);
		cob_stop_run(1);
	}
}

void
cob_parameter_check(const char * funcname, const int numparms)
{
	if(cobglobptr->cob_call_params < numparms) {
		cob_runtime_error(_("CALL to %s requires %d parameters"),
						  funcname, numparms);
		cob_stop_run(1);
	}
}

void
cob_correct_numeric(cob_field * f)
{
	if(!COB_FIELD_IS_NUMDISP(f)) {
		return;
	}
	size_t size = f->size;
	unsigned char * data = f->data;
	if(COB_FIELD_HAVE_SIGN(f)) {
		/* Adjust for sign byte */
		size--;
		unsigned char * p;
		if(unlikely(COB_FIELD_SIGN_LEADING(f))) {
			p = f->data;
			data = p + 1;
		} else {
			p = f->data + f->size - 1;
		}
		if(unlikely(COB_FIELD_SIGN_SEPARATE(f))) {
			if(*p != '+' && *p != '-') {
				*p = '+';
			}
		} else if(unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			switch(*p) {
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
		unsigned char * p = f->data + f->size - 1;
		if(unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			switch(*p) {
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
				*p = '1' +(*p - 'A');
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
				*p = '1' +(*p - 'J');
				break;
			default:
				break;
			}
		} else {
			switch(*p) {
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
	unsigned char * p = data;
	for(size_t i = 0; i < size; ++i, ++p) {
		switch(*p) {
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
			if((*p & 0x0F) <= 9) {
				*p = (*p & 0x0F) + '0';
			}
			break;
		}
	}
}

static int
cob_check_numdisp(const cob_field * f)
{
	size_t size = f->size;
	unsigned char * data = f->data;
	if(COB_FIELD_HAVE_SIGN(f)) {
		/* Adjust for sign byte */
		size--;
		unsigned char * p;
		if(unlikely(COB_FIELD_SIGN_LEADING(f))) {
			p = f->data;
			data = p + 1;
		} else {
			p = f->data + f->size - 1;
		}
		if(unlikely(COB_FIELD_SIGN_SEPARATE(f))) {
			if(*p != '+' && *p != '-') {
				return 0;
			}
		} else if(unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			switch(*p) {
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
			switch(*p) {
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
	for(size_t i = 0; i < size; ++i) {
		if(!isdigit(data[i])) {
			return 0;
		}
	}
	return 1;
}

/* Sign */

int
cob_real_get_sign(cob_field * f)
{
	unsigned char * p;

	switch(COB_FIELD_TYPE(f)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		/* Locate sign */
		if(unlikely(COB_FIELD_SIGN_LEADING(f))) {
			p = f->data;
		} else {
			p = f->data + f->size - 1;
		}

		/* Get sign */
		if(unlikely(COB_FIELD_SIGN_SEPARATE(f))) {
			return(*p == '-') ? -1 : 1;
		}
		if(*p >= (unsigned char)'0' && *p <= (unsigned char)'9') {
			return 1;
		}
		if(*p == ' ') {
#if	0	/* RXWRXW - Space sign */
			*p = (unsigned char)'0';
#endif
			return 1;
		}
		if(unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			return cob_get_sign_ebcdic(p);
		}
		return cob_get_sign_ascii(p);
	case COB_TYPE_NUMERIC_PACKED:
		if(COB_FIELD_NO_SIGN_NIBBLE(f)) {
			return 1;
		}
		p = f->data + f->size - 1;
		return((*p & 0x0F) == 0x0D) ? -1 : 1;
	}
	return 0;
}

void
cob_real_put_sign(cob_field * f, const int sign)
{
	unsigned char * p;

	switch(COB_FIELD_TYPE(f)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		/* Locate sign */
		if(unlikely(COB_FIELD_SIGN_LEADING(f))) {
			p = f->data;
		} else {
			p = f->data + f->size - 1;
		}

		/* Put sign */
		if(unlikely(COB_FIELD_SIGN_SEPARATE(f))) {
			unsigned char c = (sign < 0) ? (cob_u8_t)'-' : (cob_u8_t)'+';
			if(*p != c) {
				*p = c;
			}
		} else if(unlikely(COB_MODULE_PTR->ebcdic_sign)) {
			cob_put_sign_ebcdic(p, sign);
		} else if(sign < 0) {
			cob_put_sign_ascii(p);
		}
		return;
	case COB_TYPE_NUMERIC_PACKED:
		if(COB_FIELD_NO_SIGN_NIBBLE(f)) {
			return;
		}
		p = f->data + f->size - 1;
		if(sign < 0) {
			*p = (*p & 0xF0) | 0x0D;
		} else {
			*p = (*p & 0xF0) | 0x0C;
		}
		return;
	}
}

/* Registration of external handlers */
void
cob_reg_sighnd(void (*sighnd) (int))
{
	cob_ext_sighdl = sighnd;
};

/* Switch */

int
cob_get_switch(const int n)
{
	if(n < 0 || n >(COB_SWITCH_MAX - 1)) {
		return 0;
	}
	return cob_switch[n];
}

void
cob_set_switch(const int n, const int flag)
{
	if(n < 0 || n >(COB_SWITCH_MAX - 1)) {
		return;
	}
	if(flag == 0) {
		cob_switch[n] = 0;
	} else if(flag == 1) {
		cob_switch[n] = 1;
	}
}

int
cob_cmp(cob_field * f1, cob_field * f2)
{
	if(COB_FIELD_IS_NUMERIC(f1) && COB_FIELD_IS_NUMERIC(f2)) {
		return cob_numeric_cmp(f1, f2);
	}
	if(COB_FIELD_TYPE(f2) == COB_TYPE_ALPHANUMERIC_ALL) {
		if(f2->size == 1 && f2->data[0] == '0' &&
				COB_FIELD_IS_NUMERIC(f1)) {
			return cob_cmp_int(f1, 0);
		}
		return cob_cmp_all(f1, f2);
	}
	if(COB_FIELD_TYPE(f1) == COB_TYPE_ALPHANUMERIC_ALL) {
		if(f1->size == 1 && f1->data[0] == '0' &&
				COB_FIELD_IS_NUMERIC(f2)) {
			return -cob_cmp_int(f2, 0);
		}
		return -cob_cmp_all(f2, f1);
	}
	if(COB_FIELD_IS_NUMERIC(f1) && COB_FIELD_TYPE(f1) != COB_TYPE_NUMERIC_DISPLAY) {
		unsigned char buff[256];
		cob_field_attr attr = *f1->attr;
		attr.type = COB_TYPE_NUMERIC_DISPLAY;
		attr.flags &= ~COB_FLAG_HAVE_SIGN;
		cob_field temp(COB_FIELD_DIGITS(f1), buff, &attr);
		cob_move(f1, &temp);
		f1 = &temp;
	}
	if(COB_FIELD_IS_NUMERIC(f2) && COB_FIELD_TYPE(f2) != COB_TYPE_NUMERIC_DISPLAY) {
		unsigned char buff[256];
		cob_field_attr attr = *f2->attr;
		attr.type = COB_TYPE_NUMERIC_DISPLAY;
		attr.flags &= ~COB_FLAG_HAVE_SIGN;
		cob_field temp(COB_FIELD_DIGITS(f2), buff, &attr);
		cob_move(f2, &temp);
		f2 = &temp;
	}
	return cob_cmp_alnum(f1, f2);
}

/* Class check */

int
cob_is_omitted(const cob_field * f)
{
	return f->data == NULL;
}

int
cob_is_numeric(const cob_field * f)
{

	switch(COB_FIELD_TYPE(f)) {
	case COB_TYPE_NUMERIC_BINARY:
		return 1;
	case COB_TYPE_NUMERIC_FLOAT:
		{
			float fpf;
			memcpy(&fpf, f->data, sizeof(float));
			return !finite((double)fpf);
		}
	case COB_TYPE_NUMERIC_DOUBLE:
		{
			double fpd;
			memcpy(&fpd, f->data, sizeof(double));
			return !finite(fpd);
		}
	case COB_TYPE_NUMERIC_PACKED:
		{
			/* Check digits */
			size_t i;
			for(i = 0; i < f->size - 1; ++i) {
				if((f->data[i] & 0xF0) > 0x90 ||
						(f->data[i] & 0x0F) > 0x09) {
					return 0;
				}
			}
			/* Check high nibble of last byte */
			if((f->data[i] & 0xF0) > 0x90) {
				return 0;
			}

			if(COB_FIELD_NO_SIGN_NIBBLE(f)) {
				/* COMP-6 - Check last nibble */
				if((f->data[i] & 0x0F) > 0x09) {
					return 0;
				}
				return 1;
			}

			/* Check sign */
			int sign = f->data[i] & 0x0F;
			if(COB_FIELD_HAVE_SIGN(f)) {
				if(sign == 0x0C || sign == 0x0D) {
					return 1;
				}
				if(COB_MODULE_PTR->flag_host_sign &&
						sign == 0x0F) {
					return 1;
				}
			} else if(sign == 0x0F) {
				return 1;
			}
			return 0;
		}
	case COB_TYPE_NUMERIC_DISPLAY:
		return cob_check_numdisp(f);
	case COB_TYPE_NUMERIC_FP_DEC64:
#ifdef	WORDS_BIGENDIAN
		return(f->data[0] & 0x78U) != 0x78U;
#else
		return(f->data[7] & 0x78U) != 0x78U;
#endif
	case COB_TYPE_NUMERIC_FP_DEC128:
#ifdef	WORDS_BIGENDIAN
		return(f->data[0] & 0x78U) != 0x78U;
#else
		return(f->data[15] & 0x78U) != 0x78U;
#endif
	default:
		for(size_t i = 0; i < f->size; ++i) {
			if(!isdigit(f->data[i])) {
				return 0;
			}
		}
		return 1;
	}
}

int
cob_is_alpha(const cob_field * f)
{
	for(size_t i = 0; i < f->size; ++i) {
		if(!isalpha(f->data[i]) && f->data[i] != (unsigned char)' ') {
			return 0;
		}
	}
	return 1;
}

int
cob_is_upper(const cob_field * f)
{
	for(size_t i = 0; i < f->size; ++i) {
		if(!isupper(f->data[i]) && f->data[i] != (unsigned char)' ') {
			return 0;
		}
	}
	return 1;
}

int
cob_is_lower(const cob_field * f)
{
	for(size_t i = 0; i < f->size; ++i) {
		if(!islower(f->data[i]) && f->data[i] != (unsigned char)' ') {
			return 0;
		}
	}
	return 1;
}

/* Table sort */

void
cob_table_sort_init(const size_t nkeys, const unsigned char * collating_sequence)
{
	sort_nkeys = 0;
	sort_keys = new cob_file_key[nkeys];
	if(collating_sequence) {
		sort_collate = collating_sequence;
	} else {
		sort_collate = COB_MODULE_PTR->collating_sequence;
	}
}

void
cob_table_sort_init_key(cob_field * field, const int flag,
						const unsigned int offset)
{
	sort_keys[sort_nkeys].field = field;
	sort_keys[sort_nkeys].flag = flag;
	sort_keys[sort_nkeys].offset = offset;
	sort_nkeys++;
}

void
cob_table_sort(cob_field * f, const int n)
{
	qsort(f->data, (size_t) n, f->size, sort_compare);
	delete [] sort_keys;
}

/* Run-time error checking */

void
cob_check_based(const unsigned char * x, const char * name)
{
	if(!x) {
		cob_runtime_error(_("BASED/LINKAGE item '%s' has NULL address"), name);
		cob_stop_run(1);
	}
}

void
cob_check_numeric(const cob_field * f, const char * name)
{
	if(!cob_is_numeric(f)) {
		char * buff = new char[COB_SMALL_BUFF];
		char * p = buff;
		unsigned char * data = f->data;
		for(size_t i = 0; i < f->size; ++i) {
			if(isprint(data[i])) {
				*p++ = data[i];
			} else {
				p += sprintf(p, "\\%03o", data[i]);
			}
		}
		*p = '\0';
		cob_runtime_error(_("'%s' not numeric: '%s'"), name, buff);
		delete [] buff;
		cob_stop_run(1);
	}
}

void
cob_check_odo(const int i, const int min,
			  const int max, const char * name)
{
	/* Check OCCURS DEPENDING ON item */
	if(i < min || max < i) {
		cob_set_exception(COB_EC_BOUND_ODO);
		cob_runtime_error(_("OCCURS DEPENDING ON '%s' out of bounds: %d"), name, i);
		cob_stop_run(1);
	}
}

void
cob_check_subscript(const int i, const int min,
					const int max, const char * name)
{
	/* Check subscript */
	if(i < min || max < i) {
		cob_set_exception(COB_EC_BOUND_SUBSCRIPT);
		cob_runtime_error(_("Subscript of '%s' out of bounds: %d"), name, i);
		cob_stop_run(1);
	}
}

void
cob_check_ref_mod(const int offset, const int length,
				  const int size, const char * name)
{
	/* Check offset */
	if(offset < 1 || offset > size) {
		cob_set_exception(COB_EC_BOUND_REF_MOD);
		cob_runtime_error(_("Offset of '%s' out of bounds: %d"), name, offset);
		cob_stop_run(1);
	}

	/* Check length */
	if(length < 1 || offset + length - 1 > size) {
		cob_set_exception(COB_EC_BOUND_REF_MOD);
		cob_runtime_error(_("Length of '%s' out of bounds: %d"), name, length);
		cob_stop_run(1);
	}
}

void *
cob_external_addr(const char * exname, const int exlength)
{
	/* Locate or allocate EXTERNAL item */
	for(cob_external * eptr = basext; eptr; eptr = eptr->next) {
		if(!strcmp(exname, eptr->ename)) {
			if(exlength > eptr->esize) {
				cob_runtime_error(_("EXTERNAL item '%s' previously allocated with size %d, requested size is %d"),
								  exname, eptr->esize, exlength);
				cob_stop_run(1);
			}
			cobglobptr->cob_initial_external = 0;
			return eptr->ext_alloc;
		}
	}
	cob_external * eptr = new cob_external;
	eptr->next = basext;
	eptr->esize = exlength;
	size_t len = strlen(exname) + 1;
	eptr->ename = new char[len];
	memcpy(eptr->ename, exname, len);
	eptr->ext_alloc = cob_malloc((size_t)exlength);
	basext = eptr;
	cobglobptr->cob_initial_external = 1;
	return eptr->ext_alloc;
}

/* Extended ACCEPT/DISPLAY */

void
cob_accept_date(cob_field * f)
{
	time_t t = time(NULL);
	char s[8];
	strftime(s, (size_t)7, "%y%m%d", localtime(&t));
	cob_memcpy(f, s, (size_t)6);
}

void
cob_accept_date_yyyymmdd(cob_field * f)
{
	time_t t = time(NULL);
	char s[12];
	strftime(s, (size_t)9, "%Y%m%d", localtime(&t));
	cob_memcpy(f, s, (size_t)8);
}

void
cob_accept_day(cob_field * f)
{
	time_t t = time(NULL);
	char s[8];
	strftime(s, (size_t)6, "%y%j", localtime(&t));
	cob_memcpy(f, s, (size_t)5);
}

void
cob_accept_day_yyyyddd(cob_field * f)
{
	time_t t = time(NULL);
	char s[12];
	strftime(s, (size_t)8, "%Y%j", localtime(&t));
	cob_memcpy(f, s, (size_t)7);
}

void
cob_accept_day_of_week(cob_field * f)
{
	time_t t = time(NULL);
	struct tm * tm = localtime(&t);
	unsigned char c;
	if(tm->tm_wday == 0) {
		c = (unsigned char)'7';
	} else {
		c = (unsigned char)(tm->tm_wday + '0');
	}
	cob_memcpy(f, &c, 1);
}

void
cob_accept_time(cob_field * f)
{
	char s[12];

#ifdef	_WIN32
	SYSTEMTIME	syst;
	GetLocalTime(&syst);
	sprintf(s, "%2.2d%2.2d%2.2d%2.2d", syst.wHour, syst.wMinute,
			syst.wSecond, syst.wMilliseconds / 10);
#else
#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	struct timeval tmv;
	gettimeofday(&tmv, NULL);
	time_t t = tmv.tv_sec;
#else
	time_t t = time(NULL);
#endif
	struct tm * tlt = localtime(&t);
	/* Leap seconds ? */
	if(tlt->tm_sec >= 60) {
		tlt->tm_sec = 59;
	}
	strftime(s, (size_t)9, "%H%M%S00", tlt);
#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	char buff2[8];
	sprintf(buff2, "%2.2ld", (long int)(tmv.tv_usec / 10000));
	memcpy(&s[6], buff2, (size_t)2);
#endif
#endif
	cob_memcpy(f, s, (size_t)8);
}

void
cob_display_command_line(cob_field * f)
{
	if(commlnptr) {
		delete [] commlnptr;
	}
	commlnptr = new unsigned char[f->size + 1];
	commlncnt = f->size;
	memcpy(commlnptr, f->data, commlncnt + 1);
}

void
cob_accept_command_line(cob_field * f)
{
	if(commlncnt) {
		cob_memcpy(f, commlnptr, commlncnt);
		return;
	}

	if(cob_argc <= 1) {
		cob_memcpy(f, " ", 1);
		return;
	}

	size_t size = 0;
	for(int i = 1; i < cob_argc; ++i) {
		size += strlen(cob_argv[i]) + 1;
		if(size > f->size) {
			break;
		}
	}
	char * buff = new char[size];
	buff[0] = ' ';
	size = 0;
	for(int i = 1; i < cob_argc; ++i) {
		size_t len = strlen(cob_argv[i]);
		memcpy(buff + size, cob_argv[i], len);
		size += len;
		if(i != cob_argc - 1) {
			buff[size++] = ' ';
		}
		if(size > f->size) {
			break;
		}
	}
	cob_memcpy(f, buff, size);
	delete [] buff;
}

/* Argument number */

void
cob_display_arg_number(cob_field * f)
{
	cob_field_attr attr(COB_TYPE_NUMERIC_BINARY, 9, 0, 0, NULL);
	int		n;
	cob_field temp(4, (unsigned char *)&n, &attr);
	cob_move(f, &temp);
	if(n < 0 || n >= cob_argc) {
		cob_set_exception(COB_EC_IMP_DISPLAY);
		return;
	}
	current_arg = n;
}

void
cob_accept_arg_number(cob_field * f)
{
	cob_field_attr attr(COB_TYPE_NUMERIC_BINARY, 9, 0, 0, NULL);
	int n = cob_argc - 1;
	cob_field temp(4, (unsigned char *)&n, &attr);
	cob_move(&temp, f);
}

void
cob_accept_arg_value(cob_field * f)
{
	if(current_arg >= cob_argc) {
		cob_set_exception(COB_EC_IMP_ACCEPT);
		return;
	}
	cob_memcpy(f, cob_argv[current_arg],
			   strlen(cob_argv[current_arg]));
	current_arg++;
}

/* Environment variable */

void
cob_display_environment(const cob_field * f)
{
	if(cob_local_env_size < f->size) {
		cob_local_env_size = f->size;
		if(cob_local_env) {
			delete [] cob_local_env;
		}
		cob_local_env = new char[cob_local_env_size + 1];
	}
	cob_field_to_string(f, cob_local_env, cob_local_env_size);
	if(unlikely(cobglobptr->cob_env_mangle)) {
		for(size_t i = 0; i < strlen(cob_local_env); ++i) {
			if(!isalnum(cob_local_env[i] & 0xFF)) {
				cob_local_env[i] = '_';
			}
		}
	}
}

void
cob_display_env_value(const cob_field * f)
{
	if(!cob_local_env) {
		cob_set_exception(COB_EC_IMP_DISPLAY);
		return;
	}
	if(!*cob_local_env) {
		cob_set_exception(COB_EC_IMP_DISPLAY);
		return;
	}
	char * env2 = new char[f->size + 1];
	cob_field_to_string(f, env2, f->size);
	size_t len = strlen(cob_local_env) + strlen(env2) + 3U;
	char * p = new char[len];
	sprintf(p, "%s=%s", cob_local_env, env2);
	delete [] env2;
	if(putenv(p) != 0) {
		cob_set_exception(COB_EC_IMP_DISPLAY);
		return;
	}
	/* Rescan term/screen variables */
	cob_rescan_env_vals();
}

void
cob_set_environment(const cob_field * f1, const cob_field * f2)
{
	cob_display_environment(f1);
	cob_display_env_value(f2);
}

void
cob_get_environment(const cob_field * envname, cob_field * envval)
{
	if(envname->size == 0 || envval->size == 0) {
		cob_set_exception(COB_EC_IMP_ACCEPT);
		return;
	}

	char * buff = new char[envname->size + 1];
	cob_field_to_string(envname, buff, envname->size);
	if(unlikely(cobglobptr->cob_env_mangle)) {
		for(size_t size = 0; size < strlen(buff); ++size) {
			if(!isalnum((int)buff[size])) {
				buff[size] = '_';
			}
		}
	}
	const char * p = getenv(buff);
	if(!p) {
		cob_set_exception(COB_EC_IMP_ACCEPT);
		p = " ";
	}
	cob_memcpy(envval, p, strlen(p));
	delete [] buff;
}

void
cob_accept_environment(cob_field * f)
{
	const char * p = NULL;

	if(cob_local_env) {
		p = getenv(cob_local_env);
	}
	if(!p) {
		cob_set_exception(COB_EC_IMP_ACCEPT);
		p = " ";
	}
	cob_memcpy(f, p, strlen(p));
}

void
cob_chain_setup(void * data, const size_t parm, const size_t size)
{
	memset(data, ' ', size);
	if(parm <= (size_t)cob_argc - 1) {
		size_t len = strlen(cob_argv[parm]);
		if(len <= size) {
			memcpy(data, cob_argv[parm], len);
		} else {
			memcpy(data, cob_argv[parm], size);
		}
	} else {
		memset(data, ' ', size);
	}
	cobglobptr->cob_call_params = cob_argc - 1;
}

void
cob_allocate(unsigned char ** dataptr, cob_field * retptr,
			 cob_field * sizefld, cob_field * initialize)
{
	/* ALLOCATE */
	cobglobptr->cob_exception_code = 0;
	char * mptr = NULL;
	int fsize = cob_get_int(sizefld);
	if(fsize > 0) {
		cob_alloc_cache * cache_ptr = new cob_alloc_cache;
		mptr = new char[fsize];
		if(!mptr || !cache_ptr) {
			cob_set_exception(COB_EC_STORAGE_NOT_AVAIL);
			delete cache_ptr;
		} else {
			if(initialize) {
				cob_field temp((size_t)fsize, (unsigned char *) mptr, &const_alpha_attr);
				cob_move(initialize, &temp);
			} else {
				memset(mptr, 0, (size_t)fsize);
			}
			cache_ptr->cob_pointer = mptr;
			cache_ptr->size = (size_t)fsize;
			cache_ptr->next = cob_alloc_base;
			cob_alloc_base = cache_ptr;
		}
	}
	if(dataptr) {
		*dataptr = (unsigned char *) mptr;
	}
	if(retptr) {
		*(char **)(retptr->data) = mptr;
	}
}

void
cob_free_alloc(unsigned char ** ptr1, unsigned char * ptr2)
{
	/* FREE */
	cobglobptr->cob_exception_code = 0;
	cob_alloc_cache * cache_ptr = cob_alloc_base;
	cob_alloc_cache * prev_ptr = cob_alloc_base;
	if(ptr1 && *ptr1) {
		void * vptr1 = *ptr1;
		for(; cache_ptr; cache_ptr = cache_ptr->next) {
			if(vptr1 == cache_ptr->cob_pointer) {
				delete [] cache_ptr->cob_pointer;
				if(cache_ptr == cob_alloc_base) {
					cob_alloc_base = cache_ptr->next;
				} else {
					prev_ptr->next = cache_ptr->next;
				}
				delete cache_ptr;
				*ptr1 = NULL;
				return;
			}
			prev_ptr = cache_ptr;
		}
		cob_set_exception(COB_EC_STORAGE_NOT_ALLOC);
		return;
	}
	if(ptr2 && *(void **)ptr2) {
		for(; cache_ptr; cache_ptr = cache_ptr->next) {
			if(*(void **)ptr2 == cache_ptr->cob_pointer) {
				delete [] cache_ptr->cob_pointer;
				if(cache_ptr == cob_alloc_base) {
					cob_alloc_base = cache_ptr->next;
				} else {
					prev_ptr->next = cache_ptr->next;
				}
				delete cache_ptr;
				*(void **)ptr2 = NULL;
				return;
			}
			prev_ptr = cache_ptr;
		}
		cob_set_exception(COB_EC_STORAGE_NOT_ALLOC);
		return;
	}
}

char *
cob_getenv(const char * name)
{
	if(name) {
		char * p = getenv(name);
		if(p) {
			return cob_strdup(p);
		}
	}
	return NULL;
}

int
cob_putenv(char * name)
{
	if(name && strchr(name, '=')) {
		int ret = putenv(cob_strdup(name));
		if(!ret) {
			cob_rescan_env_vals();
		}
		return ret;
	}
	return -1;
}

int
cob_extern_init(void)
{
	cob_init(0, NULL);
	return 0;
}

void *
cob_command_line(int flags, int * pargc, char *** pargv,
				 char *** penvp, char ** pname)
{
#if	0	/* RXWRXW cob_command_line */
	char	**	spenvp;
	char	*	spname;
#else
	COB_UNUSED(penvp);
	COB_UNUSED(pname);
#endif

	COB_UNUSED(flags);

	if(!cob_initialized) {
		cob_runtime_error(_("'cobcommandline' - Runtime has not been initialized"));
		cob_stop_run(1);
	}
	if(pargc && pargv) {
		cob_argc = *pargc;
		cob_argv = *pargv;
	}

#if	0	/* RXWRXW cob_command_line */
	if(penvp) {
		spenvp = *penvp;
	}
	if(pname) {
		spname = *pname;
	}
#endif

	/* What are we supposed to return here? */
	return NULL;
}

int
cob_tidy(void)
{
	if(!cob_initialized) {
		exit(1);
	}
	if(exit_hdlrs != NULL) {
		exit_handlerlist * h = exit_hdlrs;
		while(h != NULL) {
			h->proc();
			h = h->next;
		}
	}
	cob_terminate_routines();
	return 0;
}

/* System routines */

int
cob_sys_exit_proc(const void * dispo, const void * pptr)
{
	COB_CHK_PARMS(CBL_EXIT_PROC, 2);
	int (**p)(void);
	memcpy(&p, &pptr, sizeof(void *));
	if(!p || !*p) {
		return -1;
	}

	exit_handlerlist * hp = NULL;
	exit_handlerlist * h = exit_hdlrs;
	/* Remove handler anyway */
	while(h != NULL) {
		if(h->proc == *p) {
			if(hp != NULL) {
				hp->next = h->next;
			} else {
				exit_hdlrs = h->next;
			}
			if(hp) {
				delete hp;
			}
			break;
		}
		hp = h;
		h = h->next;
	}
	const unsigned char	* x = (unsigned char *) dispo;
	if(*x != 0 && *x != 2 && *x != 3) {
		/* Remove handler */
		return 0;
	}
	h = new exit_handlerlist;
	h->next = exit_hdlrs;
	h->proc = *p;
	exit_hdlrs = h;
	return 0;
}

int
cob_sys_error_proc(const void * dispo, const void * pptr)
{
	COB_CHK_PARMS(CBL_ERROR_PROC, 2);
	int (**p)(char *s);
	memcpy(&p, &pptr, sizeof(void *));
	if(!p || !*p) {
		return -1;
	}

	handlerlist * hp = NULL;
	handlerlist * h = hdlrs;
	/* Remove handler anyway */
	while(h != NULL) {
		if(h->proc == *p) {
			if(hp != NULL) {
				hp->next = h->next;
			} else {
				hdlrs = h->next;
			}
			if(hp) {
				delete hp;
			}
			break;
		}
		hp = h;
		h = h->next;
	}
	const unsigned char * x = (unsigned char *) dispo;
	if(*x != 0) {
		/* Remove handler */
		return 0;
	}
	h = new handlerlist;
	h->next = hdlrs;
	h->proc = *p;
	hdlrs = h;
	return 0;
}

int
cob_sys_system(const void * cmdline)
{
	COB_CHK_PARMS(SYSTEM, 1);
	if(COB_MODULE_PTR->cob_procedure_params[0]) {
		const char * cmd = (char *) cmdline;
		int i = (int) COB_MODULE_PTR->cob_procedure_params[0]->size;
		if(unlikely(i > COB_MEDIUM_MAX)) {
			cob_runtime_error(_("Parameter to SYSTEM call is larger than 8192 characters"));
			cob_stop_run(1);
		}
		i--;
		for(; i >= 0; --i) {
			if(cmd[i] != ' ' && cmd[i] != 0) {
				break;
			}
		}
		if(i >= 0) {
			char * buff = new char[i + 1];
			memcpy(buff, cmd, i + 1);
			if(cobglobptr->cob_screen_initialized) {
				cob_screen_set_mode(0);
			}
			i = system(buff);
			delete [] buff;
			if(cobglobptr->cob_screen_initialized) {
				cob_screen_set_mode(1U);
			}
			return i;
		}
	}
	return 1;
}

int
cob_sys_and(const void * p1, void * p2, const int length)
{
	const cob_u8_ptr	data_1 = (const unsigned char *) p1;
	cob_u8_ptr		data_2 = (unsigned char *) p2;
	size_t			n;

	COB_CHK_PARMS(CBL_AND, 3);

	if(length <= 0) {
		return 0;
	}
	for(n = 0; n <(size_t)length; ++n) {
		data_2[n] &= data_1[n];
	}
	return 0;
}

int
cob_sys_or(const void * p1, void * p2, const int length)
{
	COB_CHK_PARMS(CBL_OR, 3);
	if(length <= 0) {
		return 0;
	}
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_2[n] |= data_1[n];
	}
	return 0;
}

int
cob_sys_nor(const void * p1, void * p2, const int length)
{
	COB_CHK_PARMS(CBL_NOR, 3);
	if(length <= 0) {
		return 0;
	}
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_2[n] = ~(data_1[n] | data_2[n]);
	}
	return 0;
}

int
cob_sys_xor(const void * p1, void * p2, const int length)
{
	COB_CHK_PARMS(CBL_XOR, 3);
	if(length <= 0) {
		return 0;
	}
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_2[n] ^= data_1[n];
	}
	return 0;
}

int
cob_sys_imp(const void * p1, void * p2, const int length)
{
	COB_CHK_PARMS(CBL_IMP, 3);
	if(length <= 0) {
		return 0;
	}
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_2[n] = (~data_1[n]) | data_2[n];
	}
	return 0;
}

int
cob_sys_nimp(const void * p1, void * p2, const int length)
{
	COB_CHK_PARMS(CBL_NIMP, 3);
	if(length <= 0) {
		return 0;
	}
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_2[n] = data_1[n] &(~data_2[n]);
	}
	return 0;
}

int
cob_sys_eq(const void * p1, void * p2, const int length)
{
	COB_CHK_PARMS(CBL_EQ, 3);
	if(length <= 0) {
		return 0;
	}
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_2[n] = ~(data_1[n] ^ data_2[n]);
	}
	return 0;
}

int
cob_sys_not(void * p1, const int length)
{
	COB_CHK_PARMS(CBL_NOT, 2);
	if(length <= 0) {
		return 0;
	}
	unsigned char * data_1 = (unsigned char *) p1;
	for(size_t n = 0; n <(size_t)length; ++n) {
		data_1[n] = ~data_1[n];
	}
	return 0;
}

int
cob_sys_xf4(void * p1, const void * p2)
{
	COB_CHK_PARMS(CBL_XF4, 2);
	unsigned char * data_1 = (unsigned char *) p1;
	const unsigned char * data_2 = (const unsigned char *) p2;
	*data_1 = 0;
	for(size_t n = 0; n < 8; ++n) {
		*data_1 |= (data_2[n] & 1) <<(7 - n);
	}
	return 0;
}

int
cob_sys_xf5(const void * p1, void * p2)
{
	COB_CHK_PARMS(CBL_XF5, 2);
	const unsigned char * data_1 = (const unsigned char *) p1;
	unsigned char * data_2 = (unsigned char *) p2;
	for(size_t n = 0; n < 8; ++n) {
		data_2[n] = (*data_1 &(1 <<(7 - n))) ? 1 : 0;
	}
	return 0;
}

int
cob_sys_x91(void * p1, const void * p2, void * p3)
{
	unsigned char * result = (unsigned char *) p1;
	const unsigned char * func = (const unsigned char *) p2;
	unsigned char * parm = (unsigned char *) p3;

	switch(*func) {
	case 11:
		/* Set switches */
		for(size_t i = 0; i < 8; ++i, ++parm) {
			if(*parm == 0) {
				cob_switch[i] = 0;
			} else if(*parm == 1) {
				cob_switch[i] = 1;
			}
		}
		*result = 0;
		break;
	case 12:
		/* Get switches */
		for(size_t i = 0; i < 8; ++i, ++parm) {
			*parm = (unsigned char)cob_switch[i];
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
cob_sys_toupper(void * p1, const int length)
{
	COB_CHK_PARMS(CBL_TOUPPER, 2);
	unsigned char * data = (unsigned char *) p1;
	if(length > 0) {
		for(size_t n = 0; n < (size_t)length; ++n) {
			if(islower(data[n])) {
				data[n] = (cob_u8_t)toupper(data[n]);
			}
		}
	}
	return 0;
}

int
cob_sys_tolower(void * p1, const int length)
{
	COB_CHK_PARMS(CBL_TOLOWER, 2);
	unsigned char * data = (unsigned char *) p1;
	if(length > 0) {
		for(size_t n = 0; n < (size_t)length; ++n) {
			if(isupper(data[n])) {
				data[n] = (cob_u8_t)tolower(data[n]);
			}
		}
	}
	return 0;
}

int
cob_sys_oc_nanosleep(const void * data)
{
	COB_UNUSED(data);
	COB_CHK_PARMS(CBL_OC_NANOSLEEP, 1);

	if(COB_MODULE_PTR->cob_procedure_params[0]) {
		cob_s64_t nsecs = cob_get_llint(COB_MODULE_PTR->cob_procedure_params[0]);
		if(nsecs > 0) {
#ifdef	_WIN32
			unsigned int msecs = (unsigned int)(nsecs / 1000000);
			if(msecs > 0) {
				Sleep(msecs);
			}
#elif	defined(__370__) || defined(__OS400__)
			unsigned int msecs = (unsigned int)(nsecs / 1000000000);
			if(msecs > 0) {
				sleep(msecs);
			}
#elif	defined(HAVE_NANO_SLEEP)
			struct timespec	tsec;
			tsec.tv_sec = nsecs / 1000000000;
			tsec.tv_nsec = nsecs % 1000000000;
			nanosleep(&tsec, NULL);
#else
			unsigned int msecs = (unsigned int)(nsecs / 1000000000);
			if(msecs > 0) {
				sleep(msecs);
			}
#endif
		}
	}
	return 0;
}

int
cob_sys_getpid(void)
{
	return(int)getpid();
}

int
cob_sys_return_args(void * data)
{
	COB_UNUSED(data);
	COB_CHK_PARMS(C$NARG, 1);

	if(COB_MODULE_PTR->cob_procedure_params[0]) {
		cob_set_int(COB_MODULE_PTR->cob_procedure_params[0],
					COB_MODULE_PTR->module_num_params);
	}
	return 0;
}

int
cob_sys_calledby(void * data)
{
	COB_CHK_PARMS(C$CALLEDBY, 1);

	if(!COB_MODULE_PTR->cob_procedure_params[0]) {
		return -1;
	}
	size_t size = COB_MODULE_PTR->cob_procedure_params[0]->size;
	memset(data, ' ', size);
	if(!COB_MODULE_PTR->next) {
		return 0;
	}
	size_t msize = strlen(COB_MODULE_PTR->next->module_name);
	if(msize > size) {
		msize = size;
	}
	memcpy(data, COB_MODULE_PTR->next->module_name, msize);
	return 1;
}

int
cob_sys_parameter_size(void * data)
{
	COB_UNUSED(data);
	COB_CHK_PARMS(C$PARAMSIZE, 1);

	if(COB_MODULE_PTR->cob_procedure_params[0]) {
		int n = cob_get_int(COB_MODULE_PTR->cob_procedure_params[0]);
		if(n > 0 && n <= COB_MODULE_PTR->module_num_params) {
			n--;
			if(COB_MODULE_PTR->next &&
					COB_MODULE_PTR->next->cob_procedure_params[n]) {
				return(int)COB_MODULE_PTR->next->cob_procedure_params[n]->size;
			}
		}
	}
	return 0;
}

int
cob_sys_sleep(const void * data)
{
	COB_UNUSED(data);
	COB_CHK_PARMS(C$SLEEP, 1);

	if(COB_MODULE_PTR->cob_procedure_params[0]) {
		int n = cob_get_int(COB_MODULE_PTR->cob_procedure_params[0]);
		if(n > 0 && n < 3600*24*7) {
#ifdef	_WIN32
			Sleep(n*1000);
#else
			sleep((unsigned int)n);
#endif
		}
	}
	return 0;
}

int
cob_sys_printable(void * p1, ...)
{
	va_list			args;

	COB_CHK_PARMS(C$PRINTABLE, 1);

	if(!COB_MODULE_PTR->cob_procedure_params[0]) {
		return 0;
	}
	unsigned char * data = (unsigned char *) p1;
	size_t datalen = COB_MODULE_PTR->cob_procedure_params[0]->size;
	unsigned char dotrep;
	if(cobglobptr->cob_call_params > 1) {
		va_start(args, p1);
		unsigned char * dotptr = va_arg(args, unsigned char *);
		va_end(args);
		dotrep = *dotptr;
	} else {
		dotrep = (unsigned char)'.';
	}
	for(size_t n = 0; n < datalen; ++n) {
		if(!isprint(data[n])) {
			data[n] = dotrep;
		}
	}
	return 0;
}

int
cob_sys_justify(void * p1, ...)
{
	va_list		args;

	COB_CHK_PARMS(C$JUSTIFY, 1);

	if(!COB_MODULE_PTR->cob_procedure_params[0]) {
		return 0;
	}
	unsigned char * data = (unsigned char *) p1;
	size_t datalen = COB_MODULE_PTR->cob_procedure_params[0]->size;
	if(datalen < 2) {
		return 0;
	}
	if(data[0] != ' ' && data[datalen - 1] != ' ') {
		return 0;
	}
	size_t left;
	for(left = 0; left < datalen; ++left) {
		if(data[left] != ' ') {
			break;
		}
	}
	if(left == datalen) {
		return 0;
	}
	size_t right = 0;
	for(size_t n = datalen - 1; ; --n, ++right) {
		if(data[n] != ' ') {
			break;
		}
		if(n == 0) {
			break;
		}
	}
	size_t movelen = datalen - left - right;
	size_t shifting = 0;
	if(cobglobptr->cob_call_params > 1) {
		va_start(args, p1);
		unsigned char * direction = va_arg(args, unsigned char *);
		va_end(args);
		if(*direction == 'L') {
			shifting = 1;
		} else if(*direction == 'C') {
			shifting = 2;
		}
	}
	switch(shifting) {
	case 1:
		memmove(data, &data[left], movelen);
		memset(&data[movelen], ' ', datalen - movelen);
		break;
	case 2:
		{
			size_t centrelen = (left + right) / 2;
			memmove(&data[centrelen], &data[left], movelen);
			memset(data, ' ', centrelen);
			if((left + right) % 2) {
				memset(&data[centrelen + movelen], ' ', centrelen + 1);
			} else {
				memset(&data[centrelen + movelen], ' ', centrelen);
			}
			break;
		}
	default:
		memmove(&data[left + right], &data[left], movelen);
		memset(data, ' ', datalen - movelen);
		break;
	}
	return 0;
}

void
cob_set_locale(cob_field * locale, const int category)
{
#ifdef	HAVE_SETLOCALE
	char * p = NULL;
	char * buff = NULL;

	if(locale) {
		if(locale->size == 0) {
			return;
		}
		buff = new char[locale->size + 1];
		cob_field_to_string(locale, buff, locale->size);
	}

	switch(category) {
	case COB_LC_COLLATE:
		p = setlocale(LC_COLLATE, buff);
		break;
	case COB_LC_CTYPE:
		p = setlocale(LC_CTYPE, buff);
		break;
#ifdef	LC_MESSAGES
	case COB_LC_MESSAGES:
		p = setlocale(LC_MESSAGES, buff);
		break;
#endif
	case COB_LC_MONETARY:
		p = setlocale(LC_MONETARY, buff);
		break;
	case COB_LC_NUMERIC:
		p = setlocale(LC_NUMERIC, buff);
		break;
	case COB_LC_TIME:
		p = setlocale(LC_TIME, buff);
		break;
	case COB_LC_ALL:
		p = setlocale(LC_ALL, buff);
		break;
	case COB_LC_USER:
		if(cobglobptr->cob_locale_orig) {
			p = setlocale(LC_ALL, cobglobptr->cob_locale_orig);
			(void)setlocale(LC_NUMERIC, "C");
		}
		break;
	case COB_LC_CLASS:
		if(cobglobptr->cob_locale_ctype) {
			p = setlocale(LC_CTYPE, cobglobptr->cob_locale_ctype);
		}
		break;
	}
	if(buff) {
		delete [] buff;
	}
	if(!p) {
		cob_set_exception(COB_EC_LOCALE_MISSING);
		return;
	}
	p = setlocale(LC_ALL, NULL);
	if(p) {
		if(cobglobptr->cob_locale) {
			delete [] cobglobptr->cob_locale;
		}
		cobglobptr->cob_locale = cob_strdup(p);
	}
#else
	cob_set_exception(COB_EC_LOCALE_MISSING);
#endif
}


#ifdef __hpux
extern "C" void allow_unaligned_data_access();
#endif

void
cob_init(const int argc, char ** argv)
{
	char * s;
#if	defined(HAVE_READLINK) || defined(HAVE_GETEXECNAME)
	const char * path;
#endif

	if(cob_initialized) {
		return;
	}

	cobglobptr = NULL;

	cob_set_signal();
#ifdef __hpux
	// Link with -lunalign
	allow_unaligned_data_access();
#endif

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
	runtime_err_str = new char[COB_ERRBUF_SIZE];

	/* Get global structure */
	cobglobptr = new cob_global;
	memset(cobglobptr, 0, sizeof(cob_global));

	cob_initialized = 1;

	if(argc) {
		cobglobptr->cob_first_init = 1;
	}

#ifdef	HAVE_SETLOCALE
	/* Prime the locale from user settings */
	s = setlocale(LC_ALL, "");
	if(s) {
		/* Save initial values */
		cobglobptr->cob_locale_orig = cob_strdup(s);
		s = setlocale(LC_CTYPE, NULL);
		if(s) {
			cobglobptr->cob_locale_ctype = cob_strdup(s);
		}
		s = setlocale(LC_COLLATE, NULL);
		if(s) {
			cobglobptr->cob_locale_collate = cob_strdup(s);
		}
#ifdef	LC_MESSAGES
		s = setlocale(LC_MESSAGES, NULL);
		if(s) {
			cobglobptr->cob_locale_messages = cob_strdup(s);
		}
#endif
		s = setlocale(LC_MONETARY, NULL);
		if(s) {
			cobglobptr->cob_locale_monetary = cob_strdup(s);
		}
		s = setlocale(LC_NUMERIC, NULL);
		if(s) {
			cobglobptr->cob_locale_numeric = cob_strdup(s);
		}
		s = setlocale(LC_TIME, NULL);
		if(s) {
			cobglobptr->cob_locale_time = cob_strdup(s);
		}
		/* Set to standard "C" locale for COBOL */
		setlocale(LC_NUMERIC, "C");
		setlocale(LC_CTYPE, "C");
		/* Save changed locale */
		s = setlocale(LC_ALL, NULL);
		if(s) {
			cobglobptr->cob_locale = cob_strdup(s);
		}
	}
#endif

#ifdef	_WIN32
	/* Allows running of tests under Win */
	s = getenv("COB_UNIX_LF");
	if(s &&(*s == 'Y' || *s == 'y' || *s == '1')) {
		cobglobptr->cob_unix_lf = 1;
		_setmode(_fileno(stdin), _O_BINARY);
		_setmode(_fileno(stdout), _O_BINARY);
		_setmode(_fileno(stderr), _O_BINARY);
	}
#endif

	cob_init_numeric(cobglobptr);
	cob_init_strings();
	cob_init_move(cobglobptr);
	cob_init_intrinsic(cobglobptr);
	cob_init_fileio(cobglobptr);
	cob_init_call(cobglobptr);
	cob_init_screenio(cobglobptr);
	cob_init_termio(cobglobptr);

	/* Set up library routine stuff */

	cobglobptr->cob_term_buff = (unsigned char *) cob_malloc((size_t)COB_MEDIUM_BUFF);
	cob_rescan_env_vals();

	/* Set switches */
	for(int i = 0; i < COB_SWITCH_MAX; ++i) {
		sprintf(runtime_err_str, "COB_SWITCH_%d", i);
		s = getenv(runtime_err_str);
		if(s &&(*s == '1' || strcasecmp(s, "ON") == 0)) {
			cob_switch[i] = 1;
		} else {
			cob_switch[i] = 0;
		}
	}

	/* Trace enable */
	s = getenv("COB_SET_TRACE");
	if(s &&(*s == 'Y' || *s == 'y' || *s == '1')) {
		cob_line_trace = 1;
	}

	/* Trace file */
	s = getenv("COB_TRACE_FILE");
	if(s) {
		cob_trace_env = cob_strdup(s);
		cob_trace_file = NULL;
	} else {
		cob_trace_env = NULL;
		cob_trace_file = stderr;
	}

	/* Disable runtime warnings */
	s = getenv("COB_DISABLE_WARNINGS");
	if(s &&(*s == 'Y' || *s == 'y' || *s == '1')) {
		cobglobptr->cob_display_warn = 0;
	} else {
		cobglobptr->cob_display_warn = 1;
	}

	/* Mangle environment names */
	s = getenv("COB_ENV_MANGLE");
	if(s &&(*s == 'Y' || *s == 'y' || *s == '1')) {
		cobglobptr->cob_env_mangle = 1;
	}

	/* Get user name */
	s = getenv("USERNAME");
	if(s) {
		cob_user_name = cob_strdup(s);
	} else {
		s = getenv("LOGNAME");
		if(s) {
			cob_user_name = cob_strdup(s);
		} else {
#ifdef	_WIN32
			unsigned long bsiz = COB_ERRBUF_SIZE;
			if(GetUserName(runtime_err_str, &bsiz)) {
				cob_user_name = cob_strdup(runtime_err_str);
			}
#elif	!defined(__OS400__)
			s = getlogin();
			if(s) {
				cob_user_name = cob_strdup(s);
			}
#endif
		}
	}
	if(!cob_user_name) {
		cob_user_name = cob_strdup(_("Unknown"));
	}

	/* This must be last in this function as we do early return */
	/* from certain ifdef's */

#ifdef	_WIN32
	s = new char[COB_LARGE_BUFF];
	int i = GetModuleFileNameA(NULL, s, COB_LARGE_MAX);
	if(i > 0 && i < COB_LARGE_BUFF) {
		cobglobptr->cob_main_argv0 = cob_strdup(s);
		delete [] s;
		return;
	}
	delete [] s;
#elif	defined(HAVE_READLINK)
	path = NULL;
	if(!access("/proc/self/exe", R_OK)) {
		path = "/proc/self/exe";
	} else if(!access("/proc/curproc/file", R_OK)) {
		path = "/proc/curproc/file";
	} else if(!access("/proc/self/path/a.out", R_OK)) {
		path = "/proc/self/path/a.out";
	}
	if(path) {
		s = new char[COB_LARGE_BUFF];
		int i = (int)readlink(path, s, (size_t)COB_LARGE_MAX);
		if(i > 0 && i < COB_LARGE_BUFF) {
			cobglobptr->cob_main_argv0 = cob_strdup(s);
			delete [] s;
			return;
		}
		delete [] s;
	}
#endif

#ifdef	HAVE_GETEXECNAME
	path = getexecname();
	if(path) {
#ifdef	HAVE_REALPATH
		s = new char[COB_LARGE_BUFF];
		if(realpath(path, s) != NULL) {
			cobglobptr->cob_main_argv0 = cob_strdup(s);
		} else {
			cobglobptr->cob_main_argv0 = cob_strdup(path);
		}
		delete [] s;
#else
		cobglobptr->cob_main_argv0 = cob_strdup(path);
#endif
		return;
	}
#endif

	if(argc && argv && argv[0]) {
#ifdef	_WIN32
		/* Returns malloced path or NULL */
		cobglobptr->cob_main_argv0 = _fullpath(NULL, argv[0], 1);
#elif	defined(HAVE_CANONICALIZE_FILE_NAME)
		/* Returns malloced path or NULL */
		cobglobptr->cob_main_argv0 = canonicalize_file_name(argv[0]);
#elif	defined(HAVE_REALPATH)
		s = new char[COB_LARGE_BUFF];
		if(realpath(argv[0], s) != NULL) {
			cobglobptr->cob_main_argv0 = cob_strdup(s);
		}
		delete [] s;
#endif
		if(!cobglobptr->cob_main_argv0) {
			cobglobptr->cob_main_argv0 = cob_strdup(argv[0]);
		}
	} else {
		cobglobptr->cob_main_argv0 = cob_strdup(_("Unknown"));
	}
	/* The above must be last in this function as we do early return */
	/* from certain ifdef's */
}
