/*
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


#ifndef COB_LOCAL_H
#define COB_LOCAL_H

#ifdef	HAVE_STRINGS_H
#include <strings.h>
#endif

/* We use this file to define/prototype things that should not be
   exported to user space
*/

#if	defined(_MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__)
#include <float.h>
#define	finite		_finite
#endif

#ifdef __hpux
#define	finite		isfinite
#endif

#if	defined(ENABLE_NLS) && defined(COB_NLS_RUNTIME)
#include "lib/gettext.h"
#define _(s)		gettext(s)
#define N_(s)		gettext_noop(s)
#else
#define _(s)		s
#define N_(s)		s
#endif


#if	defined(_WIN32) || defined(__CYGWIN__) || defined(__HP_aCC)
#define COB_HIDDEN
#elif	defined(__GNUC__) && __GNUC__ >= 4
/* Also OK for icc which defines __GNUC__ */
#define COB_HIDDEN	__attribute__ ((visibility("hidden")))
#elif	defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#include <ieeefp.h>
/* Note - >= 0x590 supports gcc syntax */
#define COB_HIDDEN	__hidden
#else
#define COB_HIDDEN
#endif

#ifndef	F_OK
#define	F_OK		0
#endif

#ifndef	X_OK
#define	X_OK		1
#endif

#ifndef	W_OK
#define	W_OK		2
#endif

#ifndef	R_OK
#define	R_OK		4
#endif

/* Stacked field depth */
#define COB_DEPTH_LEVEL		32

/* Not-A-Number */
#define COB_DECIMAL_NAN		-32768

/* Infinity */
#define COB_DECIMAL_INF		-32767

/* GMP decimal default */
#define COB_MPZ_DEF			1024UL

/* GMP floating precision */
#define COB_MPF_PREC		2048UL

/* Complex calculation cutoff value */
/* This MUST be <= COB_MPF_PREC */
#define COB_MPF_CUTOFF		1024UL


/* Floating-decimal */
#ifdef	WORDS_BIGENDIAN
#define	COB_128_MSW(x)		x[0]
#define	COB_128_LSW(x)		x[1]
#define	COB_MPZ_ENDIAN		1
#else
#define	COB_128_MSW(x)		x[1]
#define	COB_128_LSW(x)		x[0]
#define	COB_MPZ_ENDIAN		-1
#endif

/* Mask for inf/nan */
#define	COB_DEC_SPECIAL		COB_U64_C(0x7800000000000000)
/* Mask for extended */
#define	COB_DEC_EXTEND		COB_U64_C(0x6000000000000000)
/* Mask for sign */
#define	COB_DEC_SIGN		COB_U64_C(0x8000000000000000)

#define	COB_64_IS_SPECIAL(x)	((x & COB_DEC_SPECIAL) == COB_DEC_SPECIAL)
#define	COB_128_IS_SPECIAL(x)	\
	((COB_128_MSW(x) & COB_DEC_SPECIAL) == COB_DEC_SPECIAL)
#define	COB_64_IS_EXTEND(x)	((x & COB_DEC_EXTEND) == COB_DEC_EXTEND)
#define	COB_128_IS_EXTEND(x)	\
	((COB_128_MSW(x) & COB_DEC_EXTEND) == COB_DEC_EXTEND)

/* Exponent 1 - 10 bits after sign bit */
#define	COB_64_EXPO_1		COB_U64_C(0x7FE0000000000000)
/* Significand 1 */
#define	COB_64_SIGF_1		COB_U64_C(0x001FFFFFFFFFFFFF)
/* Exponent 2 - 10 bits after (sign bit + 2) */
#define	COB_64_EXPO_2		COB_U64_C(0x1FF8000000000000)
/* Significand 2 */
#define	COB_64_SIGF_2		COB_U64_C(0x0007FFFFFFFFFFFF)
/* Extended or bit */
#define	COB_64_OR_EXTEND	COB_U64_C(0x0020000000000000)

/* Exponent 1 - 14 bits after sign bit */
#define	COB_128_EXPO_1		COB_U64_C(0x7FFE000000000000)
/* Significand 1 */
#define	COB_128_SIGF_1		COB_U64_C(0x0001FFFFFFFFFFFF)
/* Exponent 2 - 14 bits after (sign bit + 2) */
#define	COB_128_EXPO_2		COB_U64_C(0x1FFF800000000000)
/* Significand 2 */
#define	COB_128_SIGF_2		COB_U64_C(0x00007FFFFFFFFFFF)
/* Extended or bit */
#define	COB_128_OR_EXTEND	COB_U64_C(0x0002000000000000)

#define COB_ATTR_INIT(u,v,x,y,z)	do { \
	attr.type = u; \
	attr.digits = v; \
	attr.scale = x; \
	attr.flags = y; \
	attr.pic = z; \
	} while(0)

#define COB_GET_SIGN(f)		(COB_FIELD_HAVE_SIGN (f) ? cob_real_get_sign (f) : 0)
#define COB_PUT_SIGN(f,s)	do { if (COB_FIELD_HAVE_SIGN (f)) cob_real_put_sign (f, s); } while(0)

#ifdef	COB_PARAM_CHECK
#define	COB_CHK_PARMS(x,z)	cob_parameter_check (#x, z)
#else
#define	COB_CHK_PARMS(x,z)
#endif

/* Convert a digit (e.g., '0') into an integer (e.g., 0) */
#define COB_D2I(x)		((x) & 0x0F)
#if	0	/* RXWRXW - D2I */
#define COB_D2I(x)		((x) - '0')
#endif

/* Convert an integer (e.g., 0) into a digit (e.g., '0') */
#define COB_I2D(x)		((x) + '0')

#define	COB_MODULE_PTR		cobglobptr->cob_current_module
#define	COB_TERM_BUFF		cobglobptr->cob_term_buff
#define	COB_DISP_TO_STDERR	cobglobptr->cob_disp_to_stderr
#define	COB_BEEP_VALUE		cobglobptr->cob_beep_value
#define	COB_ACCEPT_STATUS	cobglobptr->cob_accept_status
#define	COB_TIMEOUT_SCALE	cobglobptr->cob_timeout_scale
#define	COB_EXTENDED_STATUS	cobglobptr->cob_extended_status
#define	COB_USE_ESC			cobglobptr->cob_use_esc
#define	COB_MAX_Y_COORD		cobglobptr->cob_max_y
#define	COB_MAX_X_COORD		cobglobptr->cob_max_x

#ifdef __cplusplus
extern "C" {
#endif

/* Local function prototypes */
COB_HIDDEN void		cob_init_numeric(cob_global *);
COB_HIDDEN void		cob_init_termio(cob_global *);
COB_HIDDEN void		cob_init_fileio(cob_global *);
COB_HIDDEN void		cob_init_call(cob_global *);
COB_HIDDEN void		cob_init_intrinsic(cob_global *);
COB_HIDDEN void		cob_init_strings(void);
COB_HIDDEN void		cob_init_move(cob_global *);
COB_HIDDEN void		cob_init_screenio(cob_global *);

COB_HIDDEN void		cob_exit_screen(void);

COB_HIDDEN void		cob_exit_numeric(void);
COB_HIDDEN void		cob_exit_fileio(void);
COB_HIDDEN void		cob_exit_call(void);
COB_HIDDEN void		cob_exit_intrinsic(void);
COB_HIDDEN void		cob_exit_strings(void);

COB_HIDDEN char *	cob_strdup(const char *);

COB_HIDDEN int		cob_real_get_sign(cob_field *);
COB_HIDDEN void		cob_real_put_sign(cob_field *, const int);

COB_HIDDEN void		cob_decimal_setget_fld(cob_field *, cob_field *, const int);
COB_HIDDEN void		cob_decimal_move_temp(cob_field *, cob_field *);
COB_HIDDEN void		cob_print_ieeedec(const cob_field *, FILE *);
COB_HIDDEN void		cob_print_realbin(const cob_field *, FILE *, const int);

COB_HIDDEN void		cob_screen_set_mode(const cob_u32_t);
COB_HIDDEN void		cob_set_exception(const int);
COB_HIDDEN int		cob_get_exception_code(void);
COB_HIDDEN const char * cob_get_exception_name(void);
COB_HIDDEN void		cob_field_to_string(const cob_field *, void *, const size_t);
COB_HIDDEN void		cob_parameter_check(const char *, const int);
COB_HIDDEN void		cob_runtime_error(const char *, ...) COB_A_FORMAT12;

#ifdef __cplusplus
}
#endif

#undef	COB_HIDDEN

#endif	/* COB_LOCAL_H */
