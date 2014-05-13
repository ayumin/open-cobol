/*
   Copyright (C) 2002,2003,2004,2005,2006,2007 Keisuke Nishida
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

#ifndef COB_COMMON_H
#define COB_COMMON_H

/* General type defines */
#define	cob_c8_t		char
#define	cob_s8_t		signed char
#define	cob_u8_t		unsigned char
#define	cob_s16_t		short
#define	cob_u16_t		unsigned short
#define	cob_s32_t		int
#define	cob_u32_t		unsigned int
#define	cob_sli_t		long int
#define	cob_uli_t		unsigned long int

#if	defined(_WIN32) && !defined(__MINGW32__) && !defined(__MINGW64__)

#define	cob_s64_t		__int64
#define	cob_u64_t		unsigned __int64

#define	COB_S64_C(x)		x ## I64
#define	COB_U64_C(x)		x ## UI64
#define	CB_FMT_LLD		"%I64d"
#define	CB_FMT_LLU		"%I64u"
#define	CB_FMT_PLLD		"%+*.*I64d"
#define	CB_FMT_PLLU		"%*.*I64u"
#define	CB_FMT_LLD_F		"%I64dI64"
#define	CB_FMT_LLU_F		"%I64uUI64"

#else

#define	cob_s64_t		long long
#define	cob_u64_t		unsigned long long

#define	COB_S64_C(x)		x ## LL
#define	COB_U64_C(x)		x ## ULL
#define	CB_FMT_LLD		"%lld"
#define	CB_FMT_LLU		"%llu"
#define	CB_FMT_PLLD		"%+*.*lld"
#define	CB_FMT_PLLU		"%*.*llu"
#define	CB_FMT_LLD_F		"%lldLL"
#define	CB_FMT_LLU_F		"%lluULL"

#endif

#define	cob_c8_ptr		cob_c8_t *
#define	cob_u8_ptr		cob_u8_t *
#define	cob_s8_ptr		cob_s8_t *
#define	cob_u16_ptr		cob_u16_t *
#define	cob_s16_ptr		cob_s16_t *
#define	cob_u32_ptr		cob_u32_t *
#define	cob_s32_ptr		cob_s32_t *
#define	cob_u64_ptr		cob_u64_t *
#define	cob_s64_ptr		cob_s64_t *

#define	cob_void_ptr		void *
#define	cob_field_ptr		cob_field *
#define	cob_file_ptr		cob_file *
#define	cob_module_ptr		cob_module *
#define	cob_screen_ptr		cob_screen *
#define	cob_file_key_ptr	cob_file_key *

/* Byte swap functions */

/*
   The original idea for the byteswap routines was taken from GLib.
   (Specifically glib/gtypes.h)
   GLib is licensed under the GNU Lesser General Public License.
*/

/* Generic swapping functions */

#undef	COB_BSWAP_16_CONSTANT
#undef	COB_BSWAP_32_CONSTANT
#undef	COB_BSWAP_64_CONSTANT
#undef	COB_BSWAP_16
#undef	COB_BSWAP_32
#undef	COB_BSWAP_64

#define COB_BSWAP_16_CONSTANT(val)	((cob_u16_t) (		\
    (((cob_u16_t)(val) & (cob_u16_t) 0x00FFU) << 8) |		\
    (((cob_u16_t)(val) & (cob_u16_t) 0xFF00U) >> 8)))

#define COB_BSWAP_32_CONSTANT(val)	((cob_u32_t) (		\
    (((cob_u32_t) (val) & (cob_u32_t) 0x000000FFU) << 24) |	\
    (((cob_u32_t) (val) & (cob_u32_t) 0x0000FF00U) <<  8) |	\
    (((cob_u32_t) (val) & (cob_u32_t) 0x00FF0000U) >>  8) |	\
    (((cob_u32_t) (val) & (cob_u32_t) 0xFF000000U) >> 24)))

#define COB_BSWAP_64_CONSTANT(val)	((cob_u64_t) (		\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x00000000000000FF)) << 56) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x000000000000FF00)) << 40) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x0000000000FF0000)) << 24) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x00000000FF000000)) <<  8) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x000000FF00000000)) >>  8) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x0000FF0000000000)) >> 24) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0x00FF000000000000)) >> 40) |	\
    (((cob_u64_t) (val) &					\
      (cob_u64_t) COB_U64_C(0xFF00000000000000)) >> 56)))

/* Machine/OS specific overrides */

#ifdef	__GNUC__

#if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val) (__builtin_bswap32 (val))
#define COB_BSWAP_64(val) (__builtin_bswap64 (val))

#elif	defined(__i386__)

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val)					\
       (__extension__						\
	({ register cob_u32_t __v,				\
	     __x = ((cob_u32_t) (val));				\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_32_CONSTANT (__x);			\
	   else							\
	     __asm__ ("bswap %0"				\
		      : "=r" (__v)				\
		      : "0" (__x));				\
	    __v; }))
#define COB_BSWAP_64(val)					\
       (__extension__						\
	({ union { cob_u64_t __ll;				\
		   cob_u32_t __l[2]; } __w, __r;		\
	   __w.__ll = ((cob_u64_t) (val));			\
	   if (__builtin_constant_p (__w.__ll))			\
	     __r.__ll = COB_BSWAP_64_CONSTANT (__w.__ll);	\
	   else							\
	     {							\
	       __r.__l[0] = COB_BSWAP_32 (__w.__l[1]);		\
	       __r.__l[1] = COB_BSWAP_32 (__w.__l[0]);		\
	     }							\
	   __r.__ll; }))

#elif defined (__ia64__)

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val)					\
       (__extension__						\
	 ({ register cob_u32_t __v,				\
	      __x = ((cob_u32_t) (val));			\
	    if (__builtin_constant_p (__x))			\
	      __v = COB_BSWAP_32_CONSTANT (__x);		\
	    else						\
	     __asm__ __volatile__ ("shl %0 = %1, 32 ;;"		\
				   "mux1 %0 = %0, @rev ;;"	\
				    : "=r" (__v)		\
				    : "r" (__x));		\
	    __v; }))
#define COB_BSWAP_64(val)					\
       (__extension__						\
	({ register cob_u64_t __v,				\
	     __x = ((cob_u64_t) (val));				\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_64_CONSTANT (__x);			\
	   else							\
	     __asm__ __volatile__ ("mux1 %0 = %1, @rev ;;"	\
				   : "=r" (__v)			\
				   : "r" (__x));		\
	   __v; }))

#elif defined (__x86_64__)

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val)					\
      (__extension__						\
	({ register cob_u32_t __v,				\
	     __x = ((cob_u32_t) (val));				\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_32_CONSTANT (__x);			\
	   else							\
	    __asm__ ("bswapl %0"				\
		     : "=r" (__v)				\
		     : "0" (__x));				\
	   __v; }))
#define COB_BSWAP_64(val)					\
       (__extension__						\
	({ register cob_u64_t __v,				\
	     __x = ((cob_u64_t) (val));				\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_64_CONSTANT (__x);			\
	   else							\
	     __asm__ ("bswapq %0"				\
		      : "=r" (__v)				\
		      : "0" (__x));				\
	   __v; }))

#else /* Generic gcc */

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val) (COB_BSWAP_32_CONSTANT (val))
#define COB_BSWAP_64(val) (COB_BSWAP_64_CONSTANT (val))

#endif

#elif defined (_MSC_VER)

#define COB_BSWAP_16(val) (_byteswap_ushort (val))
#define COB_BSWAP_32(val) (_byteswap_ulong (val))
#define COB_BSWAP_64(val) (_byteswap_uint64 (val))

#else /* Generic */

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val) (COB_BSWAP_32_CONSTANT (val))
#define COB_BSWAP_64(val) (COB_BSWAP_64_CONSTANT (val))

#endif

/* End byte swap functions */

/* Compiler characteristics */

#ifdef	_MSC_VER

#ifndef	_CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE	1
#endif
#include <malloc.h>
#include <io.h>
#include <fcntl.h>

/* Disable certain warnings */
/* Deprecated functions */
#pragma warning(disable: 4996)
/* Function declarations without parameter list */
#pragma warning(disable: 4255)

#define strncasecmp		_strnicmp
#define strcasecmp		_stricmp
#define snprintf		_snprintf
#define getpid			_getpid
#define access			_access

#define __attribute__(x)

#ifdef	S_ISDIR
#undef	S_ISDIR
#endif
#define S_ISDIR(x)		(((x) & _S_IFMT) == _S_IFDIR)

#ifdef	S_ISREG
#undef	S_ISREG
#endif
#define S_ISREG(x)		(((x) & _S_IFMT) == _S_IFREG)

#ifndef	_M_IA64
#ifdef	_WIN64
#define	__x86_64__
#else
#define	__i386__
#endif
#endif

#endif

#ifdef __BORLANDC__
#include <io.h>
#define _timeb		timeb
#define _ftime(a)	ftime(a)
#define strncasecmp	strnicmp
#define strcasecmp	stricmp
#define _setmode	setmode
#define _chdir		chdir
#endif

#include <setjmp.h>

#if	defined(_WIN32) || defined(__CYGWIN__)
#ifdef	COB_LIB_EXPIMP
	#define COB_EXPIMP	__declspec(dllexport) extern
#else
	#define COB_EXPIMP	__declspec(dllimport) extern
#endif
#else
	#define COB_EXPIMP	extern
#endif

#if	defined(__370__) || defined(_MSC_VER) || defined(__DECC) || \
	defined(__BORLANDC__) || defined(__WATCOMC__)
	#define COB_INLINE	__inline
#elif	defined(__INTEL_COMPILER)
	/* icc */
	#define COB_INLINE	inline
#elif	defined(__GNUC__)
	/* gcc */
	#define COB_INLINE	__inline__
#elif	defined(__STDC_VERSION__) && __STDC_VERSION__ > 199900L
	/* C99 and C++ */
	#define COB_INLINE	inline
#elif	defined(COB_KEYWORD_INLINE)
	#define COB_INLINE	COB_KEYWORD_INLINE
#else
	#define COB_INLINE
#endif

/* Also OK for icc which defines __GNUC__ */

#if	defined(__GNUC__) || (defined(__xlc__) && __IBMC__ >= 700)
#define	COB_A_NORETURN	__attribute__((noreturn))
#define	COB_A_FORMAT12	__attribute__((format(printf, 1, 2)))
#define	COB_A_FORMAT23	__attribute__((format(printf, 2, 3)))
#define	COB_A_FORMAT34	__attribute__((format(printf, 3, 4)))
#else
#define	COB_A_NORETURN
#define	COB_A_FORMAT12
#define	COB_A_FORMAT23
#define	COB_A_FORMAT34
#endif

#ifdef	_MSC_VER
#define	DECLNORET	__declspec(noreturn)
#else
#define	DECLNORET
#endif

#if	defined(__GNUC__)
#define	optim_memcpy(x,y,z)	__builtin_memcpy (x, y, z)
#else
#define	optim_memcpy(x,y,z)	memcpy (x, y, z)
#endif

#if	defined(__GNUC__) && (__GNUC__ >= 3)
#define likely(x)	__builtin_expect((long int)!!(x), 1L)
#define unlikely(x)	__builtin_expect((long int)!!(x), 0L)
#define	COB_A_MALLOC	__attribute__((malloc))
#define	COB_HAVE_STEXPR	1

#if	__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)
#define	COB_NOINLINE	__attribute__((noinline))
#define	COB_A_INLINE	__attribute__((always_inline))
#else
#define	COB_NOINLINE
#define	COB_A_INLINE
#endif

#if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)
#define	COB_A_COLD	__attribute__((cold))
#else
#define	COB_A_COLD
#endif

#elif	defined(__xlc__) && __IBMC__ >= 700

#if	__IBMC__ >= 900
#define likely(x)	__builtin_expect((long int)!!(x), 1L)
#define unlikely(x)	__builtin_expect((long int)!!(x), 0L)
#else
#define likely(x)	(x)
#define unlikely(x)	(x)
#endif
#define	COB_NOINLINE	__attribute__((noinline))
#define	COB_A_INLINE	__attribute__((always_inline))
#define	COB_A_MALLOC
#define	COB_A_COLD
#if	__IBMC__ >= 800
#define	COB_HAVE_STEXPR	1
#else
#undef	COB_HAVE_STEXPR
#endif

#elif	defined(__SUNPRO_C) && __SUNPRO_C >= 0x590

#define likely(x)	(x)
#define unlikely(x)	(x)
#define	COB_A_MALLOC	__attribute__((malloc))
#define	COB_NOINLINE	__attribute__((noinline))
#define	COB_A_INLINE	__attribute__((always_inline))
#define	COB_A_COLD
#define	COB_HAVE_STEXPR	1

#else

#define likely(x)	(x)
#define unlikely(x)	(x)
#define	COB_A_MALLOC
#define	COB_NOINLINE
#define	COB_A_INLINE
#define	COB_A_COLD
#undef	COB_HAVE_STEXPR

#endif

/* Prevent unwanted verbosity when using icc */
#ifdef	__INTEL_COMPILER

/* Unreachable code */
#pragma warning ( disable : 111 )
/* Declared but never referenced */
#pragma warning ( disable : 177 )
/* Format conversion */
#pragma warning ( disable : 181 )
/* Enumerated type mixed with other type */
#pragma warning ( disable : 188 )
/* #undefine tested for zero */
#pragma warning ( disable : 193 )
/* Set but not used */
#pragma warning ( disable : 593 )
/* Parameter not referenced */
#pragma warning ( disable : 869 )
/* Operands are evaluated in unspecified order */
#pragma warning ( disable : 981 )
/* Missing return at end of non-void function */
/* Note - occurs because we have a non-returning abort call in cobc */
#pragma warning ( disable : 1011 )
/* Declaration in same source as definition */
#pragma warning ( disable : 1419 )
/* Shadowed variable - 1599 and 1944 are essentially the same */
#pragma warning ( disable : 1599 )
#pragma warning ( disable : 1944 )
/* Possible loss of precision */
#pragma warning ( disable : 2259 )

#endif

#if !defined(__i386__) && !defined(__x86_64__) && !defined(__powerpc__) && !defined(__powerpc64__) && !defined(__ppc__) && !defined(__amd64__)
	#define	COB_NON_ALIGNED
	/* Some DEC Alphas can only load shorts at 4-byte aligned addresses */
	#ifdef	__alpha
		#define COB_SHORT_BORK
	#endif
	#if defined(_MSC_VER)
		#define COB_ALLOW_UNALIGNED
	#else
		#define __unaligned
	#endif
#else
	#define COB_ALLOW_UNALIGNED
	#define __unaligned
#endif

/* End compiler stuff */

/* EBCDIC determination */

#if	' ' == 0x40
#define	COB_EBCDIC_MACHINE
#else
#undef	COB_EBCDIC_MACHINE
#endif

/* Macro to prevent unused parameter warning */

#define	COB_UNUSED(z)	do { (void)(z); } while (0)

/* Buffer size definitions */

#define	COB_MINI_BUFF		256
#define	COB_SMALL_BUFF		1024
#define	COB_NORMAL_BUFF		2048
#define	COB_FILE_BUFF		4096
#define	COB_MEDIUM_BUFF		8192
#define	COB_LARGE_BUFF		16384
#define	COB_MINI_MAX		(COB_MINI_BUFF - 1)
#define	COB_SMALL_MAX		(COB_SMALL_BUFF - 1)
#define	COB_NORMAL_MAX		(COB_NORMAL_BUFF - 1)
#define	COB_FILE_MAX		(COB_FILE_BUFF - 1)
#define	COB_MEDIUM_MAX		(COB_MEDIUM_BUFF - 1)
#define	COB_LARGE_MAX		(COB_LARGE_BUFF - 1)

/* Perform stack size */
#define	COB_STACK_SIZE		255

/* Maximum size of file records */
#define	MAX_FD_RECORD		65535

/* Maximum number of parameters */
#define	COB_MAX_FIELD_PARAMS	36

/* Maximum number of field digits */
#define	COB_MAX_DIGITS		38

/* Max digits in binary field */
#define	COB_MAX_BINARY		39

/* Maximum number of cob_decimal structures */
#define	COB_MAX_DEC_STRUCT	32

/* Program return types */
#define	COB_RET_TYPE_INT	0
#define	COB_RET_TYPE_PTR	1
#define	COB_RET_TYPE_VOID	2

/* Fold case types */
#define	COB_FOLD_UPPER		1
#define	COB_FOLD_LOWER		2

/* Locale types */
#define	COB_LC_COLLATE		0
#define	COB_LC_CTYPE		1
#define	COB_LC_MESSAGES		2
#define	COB_LC_MONETARY		3
#define	COB_LC_NUMERIC		4
#define	COB_LC_TIME		5
#define	COB_LC_ALL		6
#define	COB_LC_USER		7
#define	COB_LC_CLASS		8

/* Field types */

#define COB_TYPE_UNKNOWN		0x00
#define COB_TYPE_GROUP			0x01U
#define COB_TYPE_BOOLEAN		0x02U

#define COB_TYPE_NUMERIC		0x10U
#define COB_TYPE_NUMERIC_DISPLAY	0x10U
#define COB_TYPE_NUMERIC_BINARY		0x11U
#define COB_TYPE_NUMERIC_PACKED		0x12U
#define COB_TYPE_NUMERIC_FLOAT		0x13U
#define COB_TYPE_NUMERIC_DOUBLE		0x14U
#define COB_TYPE_NUMERIC_L_DOUBLE	0x15U
#define COB_TYPE_NUMERIC_FP_DEC64	0x16U
#define COB_TYPE_NUMERIC_FP_DEC128	0x17U
#define COB_TYPE_NUMERIC_FP_BIN32	0x18U
#define COB_TYPE_NUMERIC_FP_BIN64	0x19U
#define COB_TYPE_NUMERIC_FP_BIN128	0x1AU

#define COB_TYPE_NUMERIC_EDITED		0x24U

#define COB_TYPE_ALPHANUMERIC		0x21U
#define COB_TYPE_ALPHANUMERIC_ALL	0x22U
#define COB_TYPE_ALPHANUMERIC_EDITED	0x23U

#define COB_TYPE_NATIONAL		0x40U
#define COB_TYPE_NATIONAL_EDITED	0x41U

/* Field flags */

#define COB_FLAG_HAVE_SIGN		(1U << 0)	/* 0x0001 */
#define COB_FLAG_SIGN_SEPARATE		(1U << 1)	/* 0x0002 */
#define COB_FLAG_SIGN_LEADING		(1U << 2)	/* 0x0004 */
#define COB_FLAG_BLANK_ZERO		(1U << 3)	/* 0x0008 */
#define COB_FLAG_JUSTIFIED		(1U << 4)	/* 0x0010 */
#define COB_FLAG_BINARY_SWAP		(1U << 5)	/* 0x0020 */
#define COB_FLAG_REAL_BINARY		(1U << 6)	/* 0x0040 */
#define COB_FLAG_IS_POINTER		(1U << 7)	/* 0x0080 */
#define COB_FLAG_NO_SIGN_NIBBLE		(1U << 8)	/* 0x0100 */
#define COB_FLAG_IS_FP			(1U << 9)	/* 0x0200 */
#define COB_FLAG_REAL_SIGN		(1U << 10)	/* 0x0400 */
#define COB_FLAG_BINARY_TRUNC		(1U << 11)	/* 0x0800 */

#define COB_FIELD_HAVE_SIGN(f)		((f)->attr->flags & COB_FLAG_HAVE_SIGN)
#define COB_FIELD_SIGN_SEPARATE(f)	((f)->attr->flags & COB_FLAG_SIGN_SEPARATE)
#define COB_FIELD_SIGN_LEADING(f)	((f)->attr->flags & COB_FLAG_SIGN_LEADING)
#define COB_FIELD_BLANK_ZERO(f)		((f)->attr->flags & COB_FLAG_BLANK_ZERO)
#define COB_FIELD_JUSTIFIED(f)		((f)->attr->flags & COB_FLAG_JUSTIFIED)
#define COB_FIELD_BINARY_SWAP(f)	((f)->attr->flags & COB_FLAG_BINARY_SWAP)
#define COB_FIELD_REAL_BINARY(f)	((f)->attr->flags & COB_FLAG_REAL_BINARY)
#define COB_FIELD_IS_POINTER(f)		((f)->attr->flags & COB_FLAG_IS_POINTER)
#define COB_FIELD_NO_SIGN_NIBBLE(f)	((f)->attr->flags & COB_FLAG_NO_SIGN_NIBBLE)
#define COB_FIELD_IS_FP(f)		((f)->attr->flags & COB_FLAG_IS_FP)
#define COB_FIELD_REAL_SIGN(f)		((f)->attr->flags & COB_FLAG_REAL_SIGN)
#define COB_FIELD_BINARY_TRUNC(f)	((f)->attr->flags & COB_FLAG_BINARY_TRUNC)

#define	COB_FLAG_LEADSEP		\
	(COB_FLAG_SIGN_SEPARATE | COB_FLAG_SIGN_LEADING)

#define COB_FIELD_SIGN_LEADSEP(f)	\
	(((f)->attr->flags & COB_FLAG_LEADSEP) == COB_FLAG_LEADSEP)

#define COB_FIELD_TYPE(f)	((f)->attr->type)
#define COB_FIELD_DIGITS(f)	((f)->attr->digits)
#define COB_FIELD_SCALE(f)	((f)->attr->scale)
#define COB_FIELD_FLAGS(f)	((f)->attr->flags)
#define COB_FIELD_PIC(f)	((f)->attr->pic)

#define COB_FIELD_DATA(f)	\
	((f)->data + (COB_FIELD_SIGN_LEADSEP (f) ? 1 : 0))

#define COB_FIELD_SIZE(f)	\
	(COB_FIELD_SIGN_SEPARATE (f) ? f->size - 1 : f->size)

#define COB_FIELD_IS_NUMERIC(f)	(COB_FIELD_TYPE (f) & COB_TYPE_NUMERIC)
#define COB_FIELD_IS_NUMDISP(f)	(COB_FIELD_TYPE (f) == COB_TYPE_NUMERIC_DISPLAY)
#define COB_FIELD_IS_ALNUM(f)	(COB_FIELD_TYPE (f) == COB_TYPE_ALPHANUMERIC)
#define COB_FIELD_IS_NATIONAL(f)	(COB_FIELD_TYPE (f) & COB_TYPE_NATIONAL)


#define	COB_DISPLAY_SIGN_ASCII	0
#define	COB_DISPLAY_SIGN_EBCDIC	1

#define	COB_NATIONAL_SIZE	2

#define	COB_SET_FLD(v,x,y,z)	(v.size = x, v.data = y, v.attr = z, &v)
#define	COB_SET_DATA(x,z)	(x.data = z, &x)

/* Fatal error definitions */

#define COB_FERROR_NONE		0
#define COB_FERROR_CANCEL	1
#define COB_FERROR_INITIALIZED	2
#define COB_FERROR_CODEGEN	3
#define COB_FERROR_CHAINING	4
#define COB_FERROR_STACK	5
#define COB_FERROR_GLOBAL	6
#define COB_FERROR_MEMORY	7
#define COB_FERROR_MODULE	8
#define COB_FERROR_RECURSIVE	9
#define COB_FERROR_SCR_INP	10
#define COB_FERROR_FILE		11
#define COB_FERROR_FUNCTION	12

/* Exception identifier enumeration */

#undef	COB_EXCEPTION
#define	COB_EXCEPTION(code,tag,name,critical)	tag,

enum cob_exception_id {
	COB_EC_ZERO = 0,
#include <libcob/exception.def>
	COB_EC_MAX
};

#undef	COB_EXCEPTION


/* File attributes */

/* File version */
#define	COB_FILE_VERSION	1

/* Start conditions */
/* Note that COB_NE is disallowed */
#define COB_EQ			1	/* x == y */
#define COB_LT			2	/* x <  y */
#define COB_LE			3	/* x <= y */
#define COB_GT			4	/* x >  y */
#define COB_GE			5	/* x >= y */
#define COB_NE			6	/* x != y */
#define COB_FI			7	/* First */
#define COB_LA			8	/* Last */

#define COB_ASCENDING		0
#define COB_DESCENDING		1

#define COB_FILE_MODE		0644

/* Organization */

#define COB_ORG_SEQUENTIAL	0
#define COB_ORG_LINE_SEQUENTIAL	1
#define COB_ORG_RELATIVE	2
#define COB_ORG_INDEXED		3
#define COB_ORG_SORT		4
#define COB_ORG_MAX		5

/* Access mode */

#define COB_ACCESS_SEQUENTIAL	1
#define COB_ACCESS_DYNAMIC	2
#define COB_ACCESS_RANDOM	3

/* SELECT features */

#define	COB_SELECT_FILE_STATUS	(1U << 0)
#define	COB_SELECT_EXTERNAL	(1U << 1)
#define	COB_SELECT_LINAGE	(1U << 2)
#define	COB_SELECT_SPLITKEY	(1U << 3)
#define	COB_SELECT_STDIN	(1U << 4)
#define	COB_SELECT_STDOUT	(1U << 5)
#define	COB_SELECT_TEMPORARY	(1U << 6)

#define COB_FILE_SPECIAL(x)	\
	((x)->flag_select_features & (COB_SELECT_STDIN | COB_SELECT_STDOUT))
#define COB_FILE_STDIN(x)	((x)->flag_select_features & COB_SELECT_STDIN)
#define COB_FILE_STDOUT(x)	((x)->flag_select_features & COB_SELECT_STDOUT)
#define COB_FILE_TEMPORARY(x)	((x)->flag_select_features & COB_SELECT_TEMPORARY)

/* Lock mode */

#define COB_LOCK_EXCLUSIVE	(1U << 0)
#define COB_LOCK_MANUAL		(1U << 1)
#define COB_LOCK_AUTOMATIC	(1U << 2)
#define COB_LOCK_MULTIPLE	(1U << 3)
#define COB_LOCK_OPEN_EXCLUSIVE	(1U << 4)

#define COB_FILE_EXCLUSIVE	(COB_LOCK_EXCLUSIVE | COB_LOCK_OPEN_EXCLUSIVE)

/* Open mode */

#define COB_OPEN_CLOSED		0
#define COB_OPEN_INPUT		1
#define COB_OPEN_OUTPUT		2
#define COB_OPEN_I_O		3
#define COB_OPEN_EXTEND		4
#define COB_OPEN_LOCKED		5

/* Close options */

#define COB_CLOSE_NORMAL	0
#define COB_CLOSE_LOCK		1
#define COB_CLOSE_NO_REWIND	2
#define COB_CLOSE_UNIT		3
#define COB_CLOSE_UNIT_REMOVAL	4

/* Write options */

#define COB_WRITE_MASK		0x0000FFFF

#define COB_WRITE_LINES		0x00010000
#define COB_WRITE_PAGE		0x00020000
#define COB_WRITE_CHANNEL	0x00040000
#define COB_WRITE_AFTER		0x00100000
#define COB_WRITE_BEFORE	0x00200000
#define COB_WRITE_EOP		0x00400000
#define COB_WRITE_LOCK		0x00800000
#define COB_WRITE_NO_LOCK	0x01000000

/* Read options */

#define COB_READ_NEXT		(1 << 0)
#define COB_READ_PREVIOUS	(1 << 1)
#define COB_READ_FIRST		(1 << 2)
#define COB_READ_LAST		(1 << 3)
#define COB_READ_LOCK		(1 << 4)
#define COB_READ_NO_LOCK	(1 << 5)
#define COB_READ_KEPT_LOCK	(1 << 6)
#define COB_READ_WAIT_LOCK	(1 << 7)
#define COB_READ_IGNORE_LOCK	(1 << 8)

#define COB_READ_MASK		\
	(COB_READ_NEXT | COB_READ_PREVIOUS | COB_READ_FIRST | COB_READ_LAST)

/* I-O status */

#define COB_STATUS_00_SUCCESS			00
#define COB_STATUS_02_SUCCESS_DUPLICATE		02
#define COB_STATUS_04_SUCCESS_INCOMPLETE	04
#define COB_STATUS_05_SUCCESS_OPTIONAL		05
#define COB_STATUS_07_SUCCESS_NO_UNIT		07
#define COB_STATUS_10_END_OF_FILE		10
#define COB_STATUS_14_OUT_OF_KEY_RANGE		14
#define COB_STATUS_21_KEY_INVALID		21
#define COB_STATUS_22_KEY_EXISTS		22
#define COB_STATUS_23_KEY_NOT_EXISTS		23
#define COB_STATUS_24_KEY_BOUNDARY		24
#define COB_STATUS_30_PERMANENT_ERROR		30
#define COB_STATUS_31_INCONSISTENT_FILENAME	31
#define COB_STATUS_34_BOUNDARY_VIOLATION	34
#define COB_STATUS_35_NOT_EXISTS		35
#define COB_STATUS_37_PERMISSION_DENIED		37
#define COB_STATUS_38_CLOSED_WITH_LOCK		38
#define COB_STATUS_39_CONFLICT_ATTRIBUTE	39
#define COB_STATUS_41_ALREADY_OPEN		41
#define COB_STATUS_42_NOT_OPEN			42
#define COB_STATUS_43_READ_NOT_DONE		43
#define COB_STATUS_44_RECORD_OVERFLOW		44
#define COB_STATUS_46_READ_ERROR		46
#define COB_STATUS_47_INPUT_DENIED		47
#define COB_STATUS_48_OUTPUT_DENIED		48
#define COB_STATUS_49_I_O_DENIED		49
#define COB_STATUS_51_RECORD_LOCKED		51
#define COB_STATUS_57_I_O_LINAGE		57
#define COB_STATUS_61_FILE_SHARING		61
#define COB_STATUS_91_NOT_AVAILABLE		91

/* Special status */
/* Used by extfh handler */
#define	COB_NOT_CONFIGURED			32768

/* End File attributes */

/* Number store defines */
#define COB_STORE_ROUND			(1 << 0)
#define COB_STORE_KEEP_ON_OVERFLOW	(1 << 1)
#define COB_STORE_TRUNC_ON_OVERFLOW	(1 << 2)

#define COB_STORE_AWAY_FROM_ZERO	(1 << 4)
#define COB_STORE_NEAR_AWAY_FROM_ZERO	(1 << 5)
#define COB_STORE_NEAR_EVEN		(1 << 6)
#define COB_STORE_NEAR_TOWARD_ZERO	(1 << 7)
#define COB_STORE_PROHIBITED		(1 << 8)
#define COB_STORE_TOWARD_GREATER	(1 << 9)
#define COB_STORE_TOWARD_LESSER		(1 << 10)
#define COB_STORE_TRUNCATION		(1 << 11)

#define COB_STORE_MASK					\
	(COB_STORE_ROUND | COB_STORE_KEEP_ON_OVERFLOW |	\
	 COB_STORE_TRUNC_ON_OVERFLOW)

/* Screen attribute defines */
#define COB_SCREEN_BLACK		0
#define COB_SCREEN_BLUE			1
#define COB_SCREEN_GREEN		2
#define COB_SCREEN_CYAN			3
#define COB_SCREEN_RED			4
#define COB_SCREEN_MAGENTA		5
#define COB_SCREEN_YELLOW		6
#define COB_SCREEN_WHITE		7

#define COB_SCREEN_LINE_PLUS		(1 << 0)
#define COB_SCREEN_LINE_MINUS		(1 << 1)
#define COB_SCREEN_COLUMN_PLUS		(1 << 2)
#define COB_SCREEN_COLUMN_MINUS		(1 << 3)
#define COB_SCREEN_AUTO			(1 << 4)
#define COB_SCREEN_BELL			(1 << 5)
#define COB_SCREEN_BLANK_LINE		(1 << 6)
#define COB_SCREEN_BLANK_SCREEN		(1 << 7)
#define COB_SCREEN_BLINK		(1 << 8)
#define COB_SCREEN_ERASE_EOL		(1 << 9)
#define COB_SCREEN_ERASE_EOS		(1 << 10)
#define COB_SCREEN_FULL			(1 << 11)
#define COB_SCREEN_HIGHLIGHT		(1 << 12)
#define COB_SCREEN_LOWLIGHT		(1 << 13)
#define COB_SCREEN_REQUIRED		(1 << 14)
#define COB_SCREEN_REVERSE		(1 << 15)
#define COB_SCREEN_SECURE		(1 << 16)
#define COB_SCREEN_UNDERLINE		(1 << 17)
#define COB_SCREEN_OVERLINE		(1 << 18)
#define COB_SCREEN_PROMPT		(1 << 19)
#define COB_SCREEN_UPDATE		(1 << 20)
#define COB_SCREEN_INPUT		(1 << 21)
#define COB_SCREEN_SCROLL_DOWN		(1 << 22)
#define COB_SCREEN_INITIAL		(1 << 23)
#define COB_SCREEN_NO_ECHO		(1 << 24)
#define COB_SCREEN_LEFTLINE		(1 << 25)
#define COB_SCREEN_NO_DISP		(1 << 26)
#define COB_SCREEN_EMULATE_NL		(1 << 27)
#define COB_SCREEN_UPPER		(1 << 28)
#define COB_SCREEN_LOWER		(1 << 29)

#define COB_SCREEN_TYPE_GROUP		0
#define COB_SCREEN_TYPE_FIELD		1
#define COB_SCREEN_TYPE_VALUE		2
#define COB_SCREEN_TYPE_ATTRIBUTE	3

/* End Screen attribute defines */

/* Report attribute defines */

#define COB_REPORT_LINE			(1 << 0)
#define COB_REPORT_LINE_PLUS		(1 << 1)
#define COB_REPORT_COLUMN_PLUS		(1 << 2)
#define COB_REPORT_RESET_FINAL		(1 << 3)
#define COB_REPORT_HEADING		(1 << 4)
#define COB_REPORT_FOOTING		(1 << 5)
#define COB_REPORT_PAGE_HEADING		(1 << 6)
#define COB_REPORT_PAGE_FOOTING		(1 << 7)
#define COB_REPORT_CONTROL_HEADING	(1 << 8)
#define COB_REPORT_CONTROL_HEADING_FINAL (1 << 9)
#define COB_REPORT_CONTROL_FOOTING	(1 << 10)
#define COB_REPORT_CONTROL_FOOTING_FINAL (1 << 11)
#define COB_REPORT_DETAIL		(1 << 12)
#define COB_REPORT_NEXT_GROUP_LINE	(1 << 13)
#define COB_REPORT_NEXT_GROUP_PLUS	(1 << 14)
#define COB_REPORT_NEXT_GROUP_PAGE	(1 << 15)
#define COB_REPORT_LINE_NEXT_PAGE	(1 << 16)
#define COB_REPORT_NEXT_PAGE		(1 << 17)
#define COB_REPORT_GROUP_INDICATE	(1 << 18)

#define COB_REPORT_REF_EMITED		(1 << 31)
#define COB_REPORT_LINE_EMITED		(1 << 30)
#define COB_REPORT_SUM_EMITED		(1 << 29)
#define COB_REPORT_EMITED		(COB_REPORT_REF_EMITED|COB_REPORT_LINE_EMITED|COB_REPORT_SUM_EMITED)

/* End Report attribute defines */

/* Structure/union declarations */


/* Field attribute structure */

typedef struct {
	unsigned short	type;		/* Field type */
	unsigned short	digits;		/* Digit count */
	signed short	scale;		/* Field scale */
	unsigned short	flags;		/* Field flags */
	const char	*pic;		/* Pointer to picture string */
} cob_field_attr;

/* Field structure */

typedef struct {
	size_t			size;		/* Field size */
	unsigned char		*data;		/* Pointer to field data */
	const cob_field_attr	*attr;		/* Pointer to attribute */
} cob_field;

#if	0	/* RXWRXW - Constant field */
/* Field structure for constants */

typedef struct {
	const size_t		size;		/* Field size */
	const unsigned char	*data;		/* Pointer to field data */
	const cob_field_attr	*attr;		/* Pointer to attribute */
} cob_const_field;


/* Union for field constants */

typedef union {
	const cob_const_field	cf;
	cob_field		vf;
} cob_fld_union;
#endif

/* Representation of 128 bit FP */

typedef struct {
	cob_u64_t	fpval[2];
} cob_fp_128;

/* Internal representation of decimal numbers */
/* n = value / 10 ^ scale */
/* Decimal structure */

typedef struct {
	mpz_t		value;			/* GMP value definition */
	int		scale;			/* Decimal scale */
} cob_decimal;

/* Perform stack structure */

struct cob_frame {
	void		*return_address_ptr;	/* Return address pointer */
	unsigned int	perform_through;	/* Perform number */
	unsigned int	return_address_num;	/* Return address number */
};

/* Call union structures */

typedef union {
	unsigned char data[8];
	cob_s64_t     datall;
	cob_u64_t     dataull;
	int           dataint;
} cob_content;

typedef union {
	void		*(*funcptr)();	/* Function returning "void *" */
	void		(*funcnull)();	/* Function returning nothing */
	cob_field	*(*funcfld)();	/* Function returning "cob_field *" */
	int		(*funcint)();	/* Function returning "int" */
	void		*funcvoid;	/* Redefine to "void *" */
#ifdef	_WIN32
	/* stdcall variants */
	void		*(__stdcall *funcptr_std)();
	void		(__stdcall *funcnull_std)();
	cob_field	*(__stdcall *funcfld_std)();
	int		(__stdcall *funcint_std)();
#endif
} cob_call_union;

struct cob_call_struct {
	const char		*cob_cstr_name;		/* Call name */
	cob_call_union		cob_cstr_call;		/* Call entry */
	cob_call_union		cob_cstr_cancel;	/* Cancel entry */
};

/* Screen structure */
typedef struct __cob_screen {
	struct __cob_screen	*next;		/* Pointer to next */
	struct __cob_screen	*child;		/* For COB_SCREEN_TYPE_GROUP */
	cob_field		*field;		/* For COB_SCREEN_TYPE_FIELD */
	cob_field		*value;		/* For COB_SCREEN_TYPE_VALUE */
	cob_field		*line;		/* LINE */
	cob_field		*column;	/* COLUMN */
	cob_field		*foreg;		/* FOREGROUND */
	cob_field		*backg;		/* BACKGROUND */
	cob_field		*prompt;	/* PROMPT */
	int			type;		/* Structure type */
	int			occurs;		/* OCCURS */
	int			attr;		/* COB_SCREEN_TYPE_ATTRIBUTE */
} cob_screen;

/* Module structure */

typedef struct __cob_module {
	struct __cob_module	*next;			/* Next pointer */
	cob_field		**cob_procedure_params;	/* Arguments */
	const char		*module_name;		/* Module name */
	const char		*module_formatted_date;	/* Module full date */
	const char		*module_source;		/* Module source */
	cob_call_union		module_entry;		/* Module entry */
	cob_call_union		module_cancel;		/* Module cancel */
	const unsigned char	*collating_sequence;	/* COLLATING */
	cob_field		*crt_status;		/* CRT STATUS */
	cob_field		*cursor_pos;		/* CURSOR */
	unsigned int		*module_ref_count;	/* Module ref count */
	const char		**module_path;		/* Module path */

	unsigned int		module_active;		/* Module is active */
	unsigned int		module_date;		/* Module num date */
	unsigned int		module_time;		/* Module num time */
	unsigned int		module_type;		/* Module type */
	unsigned int		module_param_cnt;	/* Module param count */
	unsigned int		module_returning;	/* Module return type */
	int			module_num_params;	/* Module arg count */

	unsigned char		ebcdic_sign;		/* DISPLAY SIGN */
	unsigned char		decimal_point;		/* DECIMAL POINT */
	unsigned char		currency_symbol;	/* CURRENCY */
	unsigned char		numeric_separator;	/* Separator */

	unsigned char		flag_filename_mapping;	/* Mapping */
	unsigned char		flag_binary_truncate;	/* Truncation */
	unsigned char		flag_pretty_display;	/* Pretty display */
	unsigned char		flag_host_sign;		/* Host sign */

	unsigned char		flag_no_phys_canc;	/* No physical cancel */
	unsigned char		flag_main;		/* Main module */
	unsigned char		flag_fold_call;		/* Fold case */
	unsigned char		flag_exit_program;	/* Exit after CALL */
} cob_module;


/* User function structure */

struct cob_func_loc {
	cob_field		*ret_fld;
	cob_field		**save_proc_parms;
	cob_field		**func_params;
	unsigned char		**data;
	cob_module		*save_module;
	int			save_call_params;
	int			save_num_params;
};

/* File connector */

/* Key structure */

typedef struct {
	cob_field	*field;	/* Key field */
	int		flag;	/* WITH DUPLICATES (for RELATIVE/INDEXED) */
				/* ASCENDING/DESCENDING (for SORT) */
	unsigned int	offset;	/* Offset of field */
} cob_file_key;


/* File structure */

typedef struct {
	const char		*select_name;		/* Name in SELECT */
	unsigned char		*file_status;		/* FILE STATUS */
	cob_field		*assign;		/* ASSIGN TO */
	cob_field		*record;		/* Record area */
	cob_field		*variable_record;	/* Record size variable */
	cob_file_key		*keys;			/* ISAM/RANDOM/SORT keys */
	void			*file;			/* File specific pointer */
	void			*linorkeyptr;		/* LINAGE or SPLIT KEY */
	const unsigned char	*sort_collating;	/* SORT collating */
	void			*extfh_ptr;		/* For EXTFH usage */
	size_t			record_min;		/* Record min size */
	size_t			record_max;		/* Record max size */
	size_t			nkeys;			/* Number of keys */
	int			fd;			/* File descriptor */

	unsigned char		organization;		/* ORGANIZATION */
	unsigned char		access_mode;		/* ACCESS MODE */
	unsigned char		lock_mode;		/* LOCK MODE */
	unsigned char		open_mode;		/* OPEN MODE */
	unsigned char		flag_optional;		/* OPTIONAL */
	unsigned char		last_open_mode;		/* Mode given by OPEN */
	unsigned char		flag_operation;		/* File type specific */
	unsigned char		flag_nonexistent;	/* Nonexistent file */

	unsigned char		flag_end_of_file;	/* Reached end of file */
	unsigned char		flag_begin_of_file;	/* Reached start of file */
	unsigned char		flag_first_read;	/* OPEN/START read flag */
	unsigned char		flag_read_done;		/* READ successful */
	unsigned char		flag_select_features;	/* SELECT features */
	unsigned char		flag_needs_nl;		/* Needs NL at close */
	unsigned char		flag_needs_top;		/* Linage needs top */
	unsigned char		file_version;		/* File I/O version */

} cob_file;


/* Linage structure */

typedef struct {
	cob_field		*linage;		/* LINAGE */
	cob_field		*linage_ctr;		/* LINAGE-COUNTER */
	cob_field		*latfoot;		/* LINAGE FOOTING */
	cob_field		*lattop;		/* LINAGE AT TOP */
	cob_field		*latbot;		/* LINAGE AT BOTTOM */
	int			lin_lines;		/* Current Linage */
	int			lin_foot;		/* Current Footage */
	int			lin_top;		/* Current Top */
	int			lin_bot;		/* Current Bottom */
} cob_linage;


/********************/
/* Report structure */
/********************/

/* for each SUM field of each line in the report */
typedef struct cob_report_sum_ {
	struct cob_report_sum_	*next;			/* Next field */
	cob_field		*f;			/* Field to be summed */
} cob_report_sum;

/* for each field of each line in the report */
typedef struct cob_report_field_ {
	struct cob_report_field_ *next;			/* Next field */
	cob_field		*f;			/* Field definition */
	cob_field		*source;		/* Field SOURCE */
	cob_field		*control;		/* CONTROL Field */
	char			*litval;		/* Literal value */
	int			litlen;			/* Length of literal string */
	int			flags;
	int			line;
	int			column;
	int			step_count;
	int			next_group_line;	/* NEXT GROUP line or PLUS line; see flags */
	unsigned int		group_indicate:1;	/* field had GROUP INDICATE */
	unsigned int		suppress:1;		/* SUPPRESS display of this field */
} cob_report_field;

/* for each line of a report */
typedef struct cob_report_line_ {
	struct cob_report_line_	*sister;		/* Next line */
	struct cob_report_line_	*child;			/* Child line */
	cob_report_field	*fields;		/* List of fields on this line */
	cob_field		*control;		/* CONTROL Field */
	int			use_decl;		/* Label# of Declaratives code */
	int			flags;			/* flags defined with line */
	int			line;			/* 'LINE' value */
	int			step_count;
	int			next_group_line;
	int			report_flags;		/* flags ORed with upper level flags */
	unsigned int		suppress:1;		/* SUPPRESS printing this line */
} cob_report_line;

/* for each 'line referencing a control field' of the report */
typedef struct cob_report_control_ref_ {
	struct cob_report_control_ref_ *next;		/* Next control_ref */
	cob_report_line		*ref_line;		/* Report Line with this control field */
} cob_report_control_ref;

/* for each 'control field' of the report */
typedef struct cob_report_control_ {
	struct cob_report_control_ *next;		/* Next control */
	const char		*name;			/* Control field name */
	cob_field		*f;			/* Field definition */
	cob_field		*val;			/* previous field value */
	cob_field		*sf;			/* save field value */
	cob_report_control_ref	*control_ref;		/* References to this control field */
	int			sequence;		/* Order of Control Break */
	unsigned int		data_change:1;		/* Control field data did change */
	unsigned int		has_heading:1;		/* CONTROL HEADING */
	unsigned int		has_footing:1;		/* CONTROL FOOTING */
	unsigned int		suppress:1;		/* SUPPRESS printing this break */
} cob_report_control;

/* for each SUM counter in the report */
typedef struct cob_report_sumctr_ {
	struct cob_report_sumctr_ *next;		/* Next sum counter */
	const char		*name;			/* Name of this SUM counter */
	cob_report_sum		*sum;			/* list of fields to be summed */
	cob_field		*counter;		/* Field to hold the SUM counter */
	cob_field		*f;			/* Data Field for SUM counter */
	cob_report_control	*control;		/* RESET when this control field changes */
	unsigned int		reset_final:1;		/* RESET on FINAL */
	unsigned int		control_final:1;	/* CONTROL FOOTING FINAL */
	unsigned int		subtotal:1;		/* This is a 'subtotal' counter */
	unsigned int		crossfoot:1;		/* This is a 'crossfoot' counter */
} cob_report_sum_ctr;

/* main report table for each RD */
typedef struct cob_report_ {
	const char		*report_name;		/* Report name */
	struct cob_report_	*next;			/* Next report */
	cob_file		*report_file;		/* Report file */
	cob_field		*page_counter;		/* PAGE-COUNTER */
	cob_field		*line_counter;		/* LINE-COUNTER */
	cob_report_line		*first_line;		/* First defined LINE of report */
	cob_report_control	*controls;		/* control fields of report */
	cob_report_sum_ctr	*sum_counters;		/* List of SUM counters in report */
	int			def_lines;		/* Default lines */
	int			def_cols;		/* Default columns */
	int			def_heading;		/* Default heading */
	int			def_first_detail;	/* Default first detail */
	int			def_last_control;	/* Default last control */
	int			def_last_detail;	/* Default last detail */
	int			def_footing;		/* Default footing */
	int			curr_page;		/* Current page */
	int			curr_line;		/* Current line on page */
	int			curr_cols;		/* Current column on line */
	int			curr_status;		/* Current status */
	int			next_value;		/* NEXT GROUP Line/Page/Plus value */
	unsigned int		control_final:1;	/* CONTROL FINAL declared */
	unsigned int		global:1;		/* IS GLOBAL declared */
	unsigned int		first_detail:1;		/* First Detail on page */
	unsigned int		in_page_footing:1;	/* doing page footing now */
	unsigned int		in_page_heading:1;	/* doing page heading now */
	unsigned int		first_generate:1;	/* Ready for first GENERATE */
	unsigned int		initiate_done:1;	/* INITIATE has been done */
	unsigned int		next_line:1;		/* Advance to line on next DETAIL */
	unsigned int		next_line_plus:1;	/* Advance to plus line on next DETAIL */
	unsigned int		next_page:1;		/* Advance to next page on next DETAIL */
	unsigned int		next_just_set:1;	/* NEXT xxx was just set so ignore */
	unsigned int		in_report_footing:1;	/* doing report footing now */
	unsigned int		incr_line:1;		/* 'curr_lines' should be incremented */
} cob_report;
/***************************/
/* End of Report structure */
/***************************/


/* Global variable structure */

typedef struct __cob_global {
	cob_file		*cob_error_file;	/* Last error file */
	cob_module		*cob_current_module;	/* Current module */
	const char		*cob_orig_statement;	/* Statement */
	const char		*cob_orig_program_id;	/* Program ID */
	const char		*cob_orig_section;	/* Section */
	const char		*cob_orig_paragraph;	/* Paragraph */
	const char		*cob_main_argv0;	/* Main program */
	char			*cob_locale;		/* Program locale */
	char			*cob_locale_orig;	/* Initial locale */
	char			*cob_locale_ctype;	/* Initial locale */
	char			*cob_locale_collate;	/* Initial locale */
	char			*cob_locale_messages;	/* Initial locale */
	char			*cob_locale_monetary;	/* Initial locale */
	char			*cob_locale_numeric;	/* Initial locale */
	char			*cob_locale_time;	/* Initial locale */

	int			cob_exception_code;	/* Last exception code */
	int			cob_call_params;	/* Current arguments */
	int			cob_initial_external;	/* First external ref */
	unsigned int		cob_orig_line;		/* Program source line */
	unsigned int		cob_got_exception;	/* Exception active */
	unsigned int		cob_screen_initialized;	/* Screen initialized */
	unsigned int		cob_unix_lf;		/* Use POSIX LF */
	unsigned int		cob_display_warn;	/* Display warnings */
	unsigned int		cob_first_init;		/* First call after init */
	unsigned int		cob_env_mangle;		/* Mangle env names */

	/* Library routine variables */

	/* screenio / termio */
	unsigned char		*cob_term_buff;		/* Screen I/O buffer */

	unsigned int		cob_disp_to_stderr;	/* Redirect to stderr */
	unsigned int		cob_beep_value;		/* Bell disposition */
	int			cob_accept_status;	/* ACCEPT STATUS */
	int			cob_timeout_scale;	/* timeout scale */
	unsigned int		cob_extended_status;	/* Extended status */
	unsigned int		cob_use_esc;		/* Check ESC key */
	int			cob_max_y;		/* Screen max y */
	int			cob_max_x;		/* Screen max x */

} cob_global;

/* File I/O function pointer structure */
struct cob_fileio_funcs {
	int	(*open)		(cob_file *, char *, const int, const int);
	int	(*close)	(cob_file *, const int);
	int	(*start)	(cob_file *, const int, cob_field *);
	int	(*read)		(cob_file *, cob_field *, const int);
	int	(*read_next)	(cob_file *, const int);
	int	(*write)	(cob_file *, const int);
	int	(*rewrite)	(cob_file *, const int);
	int	(*fdelete)	(cob_file *);
};

/* Low level jump structure */
struct cobjmp_buf {
	int	cbj_int[4];
	void	*cbj_ptr[4];
	jmp_buf	cbj_jmp_buf;
	void	*cbj_ptr_rest[2];
};

/*******************************/

/* Function declarations */

/*******************************/
/* Functions in common.c */

/* General functions */

COB_EXPIMP cob_global		*cob_get_global_ptr	(void);

COB_EXPIMP void	cob_init			(const int, char **);
COB_EXPIMP void	cob_module_enter		(cob_module **, cob_global **,
						 const int);
COB_EXPIMP void	cob_module_leave		(cob_module *);

DECLNORET COB_EXPIMP void	cob_stop_run	(const int) COB_A_NORETURN;
DECLNORET COB_EXPIMP void	cob_fatal_error	(const int) COB_A_NORETURN;

COB_EXPIMP void	*cob_malloc			(const size_t) COB_A_MALLOC;
COB_EXPIMP void	*cob_fast_malloc		(const size_t) COB_A_MALLOC;
COB_EXPIMP void	*cob_cache_malloc		(const size_t) COB_A_MALLOC;
COB_EXPIMP void	*cob_cache_realloc		(void *, const size_t);
COB_EXPIMP void	cob_cache_free			(void *);
COB_EXPIMP void	cob_set_locale			(cob_field *, const int);

COB_EXPIMP void	cob_check_version		(const char *, const char *,
						 const int);

COB_EXPIMP void	*cob_save_func			(cob_field **, const int,
						 const int, ...);
COB_EXPIMP void	cob_restore_func		(struct cob_func_loc *);

COB_EXPIMP void	cob_accept_arg_number		(cob_field *);
COB_EXPIMP void	cob_accept_arg_value		(cob_field *);
COB_EXPIMP void	cob_accept_command_line		(cob_field *);
COB_EXPIMP void	cob_accept_date			(cob_field *);
COB_EXPIMP void	cob_accept_date_yyyymmdd	(cob_field *);
COB_EXPIMP void	cob_accept_day			(cob_field *);
COB_EXPIMP void	cob_accept_day_yyyyddd		(cob_field *);
COB_EXPIMP void	cob_accept_day_of_week		(cob_field *);
COB_EXPIMP void	cob_accept_environment		(cob_field *);
COB_EXPIMP void	cob_accept_exception_status	(cob_field *);
COB_EXPIMP void	cob_accept_time			(cob_field *);
COB_EXPIMP void	cob_accept_user_name		(cob_field *);
COB_EXPIMP void	cob_display_command_line	(cob_field *);
COB_EXPIMP void	cob_display_environment		(const cob_field *);
COB_EXPIMP void	cob_display_env_value		(const cob_field *);
COB_EXPIMP void	cob_display_arg_number		(cob_field *);
COB_EXPIMP void	cob_get_environment		(const cob_field *, cob_field *);
COB_EXPIMP void	cob_set_environment		(const cob_field *,
						 const cob_field *);
COB_EXPIMP void	cob_chain_setup			(void *, const size_t,
						 const size_t);
COB_EXPIMP void	cob_allocate			(unsigned char **, cob_field *,
						 cob_field *, cob_field *);
COB_EXPIMP void	cob_free_alloc			(unsigned char **, unsigned char *);
COB_EXPIMP int	cob_extern_init			(void);
COB_EXPIMP int	cob_tidy			(void);
COB_EXPIMP void	*cob_command_line		(int, int *, char ***,
						 char ***, char **);
COB_EXPIMP char	*cob_getenv			(const char *);
COB_EXPIMP int	cob_putenv			(char *);

#define	cobgetenv(x)			cob_getenv (x)
#define	cobputenv(x)			cob_putenv (x)
#define	cobtidy()			cob_tidy ()
#define	cobinit()			cob_extern_init ()
#define	cobexit(x)			cob_stop_run (x)
#define	cobcommandline(v,w,x,y,z)	cob_command_line (v,w,x,y,z)

/* System routines */
COB_EXPIMP int	cob_sys_exit_proc	(const void *, const void *);
COB_EXPIMP int	cob_sys_error_proc	(const void *, const void *);
COB_EXPIMP int	cob_sys_system		(const void *);
COB_EXPIMP int	cob_sys_and		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_or		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_nor		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_xor		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_imp		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_nimp		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_eq		(const void *, void *, const int);
COB_EXPIMP int	cob_sys_not		(void *, const int);
COB_EXPIMP int	cob_sys_xf4		(void *, const void *);
COB_EXPIMP int	cob_sys_xf5		(const void *, void *);
COB_EXPIMP int	cob_sys_x91		(void *, const void *, void *);
COB_EXPIMP int	cob_sys_toupper		(void *, const int);
COB_EXPIMP int	cob_sys_tolower		(void *, const int);
COB_EXPIMP int	cob_sys_oc_nanosleep	(const void *);
COB_EXPIMP int	cob_sys_getpid		(void);
COB_EXPIMP int	cob_sys_return_args	(void *);
COB_EXPIMP int	cob_sys_parameter_size	(void *);
COB_EXPIMP int	cob_sys_sleep		(const void *);
COB_EXPIMP int	cob_sys_calledby	(void *);
COB_EXPIMP int	cob_sys_justify		(void *, ...);
COB_EXPIMP int	cob_sys_printable	(void *, ...);

/* Utilities */

COB_EXPIMP void	cob_set_location	(const char *, const unsigned int,
					 const char *, const char *,
					 const char *);
COB_EXPIMP void	cob_trace_section	(const char *, const char *, const int);

COB_EXPIMP void			*cob_external_addr	(const char *, const int);
COB_EXPIMP unsigned char	*cob_get_pointer	(const void *);
COB_EXPIMP void			*cob_get_prog_pointer	(const void *);
COB_EXPIMP void			cob_ready_trace		(void);
COB_EXPIMP void			cob_reset_trace		(void);

/* Switch */

COB_EXPIMP int	cob_get_switch		(const int);
COB_EXPIMP void	cob_set_switch		(const int, const int);

/* Comparison */

COB_EXPIMP int	cob_cmp			(cob_field *, cob_field *);
COB_EXPIMP int	cob_cmp_float		(cob_field *, cob_field *);

/* Class check */

COB_EXPIMP int	cob_is_omitted		(const cob_field *);
COB_EXPIMP int	cob_is_numeric		(const cob_field *);
COB_EXPIMP int	cob_is_alpha		(const cob_field *);
COB_EXPIMP int	cob_is_upper		(const cob_field *);
COB_EXPIMP int	cob_is_lower		(const cob_field *);

/* Table sort */

COB_EXPIMP void	cob_table_sort_init	(const size_t, const unsigned char *);
COB_EXPIMP void	cob_table_sort_init_key	(cob_field *, const int,
					 const unsigned int);
COB_EXPIMP void	cob_table_sort		(cob_field *, const int);

/* Run-time error checking */

COB_EXPIMP void	cob_check_numeric	(const cob_field *, const char *);
COB_EXPIMP void	cob_correct_numeric	(cob_field *);
COB_EXPIMP void	cob_check_based		(const unsigned char *,
					 const char *);
COB_EXPIMP void	cob_check_odo		(const int, const int,
					 const int, const char *);
COB_EXPIMP void	cob_check_subscript	(const int, const int,
					 const int, const char *);
COB_EXPIMP void	cob_check_ref_mod	(const int, const int,
					 const int, const char *);

/* Comparison functions */
COB_EXPIMP int	cob_numeric_cmp		(cob_field *, cob_field *);

/*******************************/
/* Functions in strings.c */

COB_EXPIMP void cob_inspect_init	(cob_field *, const cob_u32_t);
COB_EXPIMP void cob_inspect_start	(void);
COB_EXPIMP void cob_inspect_before	(const cob_field *);
COB_EXPIMP void cob_inspect_after	(const cob_field *);
COB_EXPIMP void cob_inspect_characters	(cob_field *);
COB_EXPIMP void cob_inspect_all		(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_leading	(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_first	(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_trailing	(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_converting	(const cob_field *, const cob_field *);
COB_EXPIMP void cob_inspect_finish	(void);

COB_EXPIMP void cob_string_init		(cob_field *, cob_field *);
COB_EXPIMP void cob_string_delimited	(cob_field *);
COB_EXPIMP void cob_string_append	(cob_field *);
COB_EXPIMP void cob_string_finish	(void);

COB_EXPIMP void cob_unstring_init	(cob_field *, cob_field *, const size_t);
COB_EXPIMP void cob_unstring_delimited	(cob_field *, const cob_u32_t);
COB_EXPIMP void cob_unstring_into	(cob_field *, cob_field *, cob_field *);
COB_EXPIMP void cob_unstring_tallying	(cob_field *);
COB_EXPIMP void cob_unstring_finish	(void);

/*******************************/
/* Functions in move.c */

COB_EXPIMP void		cob_move	(cob_field *, cob_field *);
COB_EXPIMP void		cob_set_int	(cob_field *, const int);
COB_EXPIMP int		cob_get_int	(cob_field *);
COB_EXPIMP cob_s64_t	cob_get_llint	(cob_field *);

/*******************************/
/* Functions in numeric.c */

COB_EXPIMP void	cob_decimal_init	(cob_decimal *);
COB_EXPIMP void cob_decimal_set_llint	(cob_decimal *, const cob_s64_t);
COB_EXPIMP void	cob_decimal_set_field	(cob_decimal *, cob_field *);
COB_EXPIMP int	cob_decimal_get_field	(cob_decimal *, cob_field *, const int);
COB_EXPIMP void	cob_decimal_add		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_sub		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_mul		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_div		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_pow		(cob_decimal *, cob_decimal *);
COB_EXPIMP int	cob_decimal_cmp		(cob_decimal *, cob_decimal *);

COB_EXPIMP void	cob_add			(cob_field *, cob_field *, const int);
COB_EXPIMP void	cob_sub			(cob_field *, cob_field *, const int);
COB_EXPIMP void	cob_mul			(cob_field *, cob_field *, const int);
COB_EXPIMP void	cob_div			(cob_field *, cob_field *, const int);
COB_EXPIMP int	cob_add_int		(cob_field *, const int, const int);
COB_EXPIMP int	cob_sub_int		(cob_field *, const int, const int);
COB_EXPIMP void	cob_div_quotient	(cob_field *, cob_field *,
					 cob_field *, const int);
COB_EXPIMP void	cob_div_remainder	(cob_field *, const int);

COB_EXPIMP int	cob_cmp_int		(cob_field *, const int);
COB_EXPIMP int	cob_cmp_uint		(cob_field *, const unsigned int);
COB_EXPIMP int	cob_cmp_llint		(cob_field *, const cob_s64_t);
COB_EXPIMP int	cob_cmp_packed		(cob_field *, const cob_s64_t);
COB_EXPIMP int	cob_cmp_numdisp		(const unsigned char *,
					 const size_t, const cob_s64_t,
					 const cob_u32_t);
COB_EXPIMP void	cob_set_packed_zero	(cob_field *);
COB_EXPIMP void	cob_set_packed_int	(cob_field *, const int);

COB_EXPIMP void	cob_decimal_alloc	(const cob_u32_t, ...);
COB_EXPIMP void	cob_decimal_push	(const cob_u32_t, ...);
COB_EXPIMP void	cob_decimal_pop		(const cob_u32_t, ...);

/*******************************/
/* Functions in call.c */

DECLNORET COB_EXPIMP void	cob_call_error		(void) COB_A_NORETURN;

COB_EXPIMP void		cob_set_cancel		(cob_module *);
COB_EXPIMP void		*cob_resolve		(const char *);
COB_EXPIMP void		*cob_resolve_cobol	(const char *, const int,
						 const int);
COB_EXPIMP void		*cob_resolve_func	(const char *);
COB_EXPIMP const char	*cob_resolve_error	(void);
COB_EXPIMP void		*cob_call_field		(const cob_field *,
						 const struct cob_call_struct *,
						 const unsigned int,
						 const int);
COB_EXPIMP void		cob_cancel_field	(const cob_field *,
						 const struct cob_call_struct *);
COB_EXPIMP void		cob_cancel		(const char *);
COB_EXPIMP int		cob_call		(const char *, const int, void **);
COB_EXPIMP int		cob_func		(const char *, const int, void **);
COB_EXPIMP void		*cob_savenv		(struct cobjmp_buf *);
COB_EXPIMP void		*cob_savenv2		(struct cobjmp_buf *, const int);
COB_EXPIMP void		cob_longjmp		(struct cobjmp_buf *);

#define	cobsetjmp(x)	setjmp (cob_savenv (x))
#define	coblongjmp(x)	cob_longjmp (x)
#define	cobsavenv(x)	cob_savenv (x)
#define	cobsavenv2(x,z)	cob_savenv2 (x, z)
#define	cobfunc(x,y,z)	cob_func (x, y, z)
#define	cobcall(x,y,z)	cob_call (x, y, z)
#define	cobcancel(x)	cob_cancel (x)

/*******************************/
/* Functions in screenio.c */

COB_EXPIMP void cob_screen_line_col	(cob_field *, const int);
COB_EXPIMP void cob_screen_display	(cob_screen *, cob_field *,
					 cob_field *);
COB_EXPIMP void cob_screen_accept	(cob_screen *, cob_field *,
					 cob_field *, cob_field *);
COB_EXPIMP void cob_field_display	(cob_field *, cob_field *, cob_field *,
					 cob_field *, cob_field *, cob_field *,
					 const int);
COB_EXPIMP void cob_field_accept	(cob_field *, cob_field *, cob_field *,
					 cob_field *, cob_field *, cob_field *,
					 cob_field *, cob_field *, const int);
COB_EXPIMP void cob_accept_escape_key	(cob_field *);
COB_EXPIMP int	cob_sys_clear_screen	(void);
COB_EXPIMP int	cob_sys_sound_bell	(void);
COB_EXPIMP int	cob_sys_get_csr_pos	(unsigned char *);
COB_EXPIMP int	cob_sys_get_scr_size	(unsigned char *, unsigned char *);

/*******************************/
/* Functions in termio.c */

COB_EXPIMP void cob_display	(const int, const int, const int, ...);
COB_EXPIMP void cob_accept	(cob_field *);

/*******************************/
/* Functions in fileio.c */

COB_EXPIMP void cob_open	(cob_file *, const int, const int, cob_field *);
COB_EXPIMP void cob_close	(cob_file *, cob_field *, const int, const int);
COB_EXPIMP void cob_read	(cob_file *, cob_field *, cob_field *, const int);
COB_EXPIMP void cob_read_next	(cob_file *, cob_field *, const int);
COB_EXPIMP void cob_rewrite	(cob_file *, cob_field *, const int, cob_field *);
COB_EXPIMP void cob_delete	(cob_file *, cob_field *);
COB_EXPIMP void cob_start	(cob_file *, const int, cob_field *,
				 cob_field *, cob_field *);
COB_EXPIMP void cob_write	(cob_file *, cob_field *, const int,
				 cob_field *, const unsigned int);

COB_EXPIMP void cob_delete_file	(cob_file *, cob_field *);
COB_EXPIMP void cob_unlock_file	(cob_file *, cob_field *);
COB_EXPIMP void cob_commit	(void);
COB_EXPIMP void cob_rollback	(void);

/* File system routines */
COB_EXPIMP int cob_sys_open_file	(unsigned char *, unsigned char *,
					 unsigned char *, unsigned char *,
					 unsigned char *);
COB_EXPIMP int cob_sys_create_file	(unsigned char *, unsigned char *,
					 unsigned char *, unsigned char *,
					 unsigned char *);
COB_EXPIMP int cob_sys_read_file	(unsigned char *, unsigned char *,
					 unsigned char *, unsigned char *,
					 unsigned char *);
COB_EXPIMP int cob_sys_write_file	(unsigned char *, unsigned char *,
					 unsigned char *, unsigned char *,
					 unsigned char *);
COB_EXPIMP int cob_sys_close_file	(unsigned char *);
COB_EXPIMP int cob_sys_flush_file	(unsigned char *);
COB_EXPIMP int cob_sys_delete_file	(unsigned char *);
COB_EXPIMP int cob_sys_copy_file	(unsigned char *, unsigned char *);
COB_EXPIMP int cob_sys_check_file_exist	(unsigned char *, unsigned char *);
COB_EXPIMP int cob_sys_rename_file	(unsigned char *, unsigned char *);
COB_EXPIMP int cob_sys_get_current_dir	(const int, const int, unsigned char *);
COB_EXPIMP int cob_sys_change_dir	(unsigned char *);
COB_EXPIMP int cob_sys_create_dir	(unsigned char *);
COB_EXPIMP int cob_sys_delete_dir	(unsigned char *);
COB_EXPIMP int cob_sys_chdir		(unsigned char *, unsigned char *);
COB_EXPIMP int cob_sys_mkdir		(unsigned char *);
COB_EXPIMP int cob_sys_copyfile		(unsigned char *, unsigned char *,
					 unsigned char *);
COB_EXPIMP int cob_sys_file_info	(unsigned char *, unsigned char *);
COB_EXPIMP int cob_sys_file_delete	(unsigned char *, unsigned char *);

/* SORT routines */
COB_EXPIMP void	cob_file_sort_init	(cob_file *, const unsigned int,
					 const unsigned char *,
					 void *, cob_field *);
COB_EXPIMP void	cob_file_sort_init_key	(cob_file *, cob_field *,
					 const int, const unsigned int);
COB_EXPIMP void	cob_file_sort_close	(cob_file *);
COB_EXPIMP void	cob_file_sort_using	(cob_file *, cob_file *);
COB_EXPIMP void	cob_file_sort_giving	(cob_file *, const size_t, ...);
COB_EXPIMP void	cob_file_release	(cob_file *);
COB_EXPIMP void	cob_file_return		(cob_file *);

/*******************************/
/* Functions in reportio.c */
COB_EXPIMP void cob_report_initiate	(cob_report *);
COB_EXPIMP int  cob_report_terminate	(cob_report *, int);
COB_EXPIMP int  cob_report_generate	(cob_report *, cob_report_line *, int);
COB_EXPIMP void cob_report_suppress	(cob_report *r, cob_report_line *l);

/*******************************/
/* Functions in intrinsic.c */

COB_EXPIMP void		cob_put_indirect_field		(cob_field *);
COB_EXPIMP void		cob_get_indirect_field		(cob_field *);
COB_EXPIMP cob_field *cob_switch_value			(const int);
COB_EXPIMP cob_field *cob_intr_binop			(cob_field *, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_current_date		(const int, const int);
COB_EXPIMP cob_field *cob_intr_when_compiled		(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_module_date		(void);
COB_EXPIMP cob_field *cob_intr_module_time		(void);
COB_EXPIMP cob_field *cob_intr_module_id		(void);
COB_EXPIMP cob_field *cob_intr_module_caller_id		(void);
COB_EXPIMP cob_field *cob_intr_module_source		(void);
COB_EXPIMP cob_field *cob_intr_module_formatted_date	(void);
COB_EXPIMP cob_field *cob_intr_module_path		(void);
COB_EXPIMP cob_field *cob_intr_exception_file		(void);
COB_EXPIMP cob_field *cob_intr_exception_location	(void);
COB_EXPIMP cob_field *cob_intr_exception_status		(void);
COB_EXPIMP cob_field *cob_intr_exception_statement	(void);
COB_EXPIMP cob_field *cob_intr_mon_decimal_point	(void);
COB_EXPIMP cob_field *cob_intr_num_decimal_point	(void);
COB_EXPIMP cob_field *cob_intr_mon_thousands_sep	(void);
COB_EXPIMP cob_field *cob_intr_num_thousands_sep	(void);
COB_EXPIMP cob_field *cob_intr_currency_symbol		(void);
COB_EXPIMP cob_field *cob_intr_char			(cob_field *);
COB_EXPIMP cob_field *cob_intr_ord			(cob_field *);
COB_EXPIMP cob_field *cob_intr_stored_char_length	(cob_field *);
COB_EXPIMP cob_field *cob_intr_combined_datetime	(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_date_of_integer		(cob_field *);
COB_EXPIMP cob_field *cob_intr_day_of_integer		(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer_of_date		(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer_of_day		(cob_field *);
COB_EXPIMP cob_field *cob_intr_test_date_yyyymmdd	(cob_field *);
COB_EXPIMP cob_field *cob_intr_test_day_yyyyddd		(cob_field *);
COB_EXPIMP cob_field *cob_intr_test_numval		(cob_field *);
COB_EXPIMP cob_field *cob_intr_test_numval_c		(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_test_numval_f		(cob_field *);
COB_EXPIMP cob_field *cob_intr_factorial		(cob_field *);

COB_EXPIMP cob_field *cob_intr_pi			(void);
COB_EXPIMP cob_field *cob_intr_e			(void);
COB_EXPIMP cob_field *cob_intr_exp			(cob_field *);
COB_EXPIMP cob_field *cob_intr_exp10			(cob_field *);
COB_EXPIMP cob_field *cob_intr_abs			(cob_field *);
COB_EXPIMP cob_field *cob_intr_acos			(cob_field *);
COB_EXPIMP cob_field *cob_intr_asin			(cob_field *);
COB_EXPIMP cob_field *cob_intr_atan			(cob_field *);
COB_EXPIMP cob_field *cob_intr_cos			(cob_field *);
COB_EXPIMP cob_field *cob_intr_log			(cob_field *);
COB_EXPIMP cob_field *cob_intr_log10			(cob_field *);
COB_EXPIMP cob_field *cob_intr_sin			(cob_field *);
COB_EXPIMP cob_field *cob_intr_sqrt			(cob_field *);
COB_EXPIMP cob_field *cob_intr_tan			(cob_field *);

COB_EXPIMP cob_field *cob_intr_upper_case		(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_lower_case		(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_reverse			(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_concatenate		(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_substitute		(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_substitute_case		(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_trim			(const int, const int,
							 cob_field *, const int);
COB_EXPIMP cob_field *cob_intr_length			(cob_field *);
COB_EXPIMP cob_field *cob_intr_byte_length		(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer			(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer_part		(cob_field *);
COB_EXPIMP cob_field *cob_intr_fraction_part		(cob_field *);
COB_EXPIMP cob_field *cob_intr_sign			(cob_field *);
COB_EXPIMP cob_field *cob_intr_lowest_algebraic		(cob_field *);
COB_EXPIMP cob_field *cob_intr_highest_algebraic	(cob_field *);
COB_EXPIMP cob_field *cob_intr_numval			(cob_field *);
COB_EXPIMP cob_field *cob_intr_numval_c			(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_numval_f			(cob_field *);
COB_EXPIMP cob_field *cob_intr_annuity			(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_mod			(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_rem			(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_sum			(const int, ...);
COB_EXPIMP cob_field *cob_intr_ord_min			(const int, ...);
COB_EXPIMP cob_field *cob_intr_ord_max			(const int, ...);
COB_EXPIMP cob_field *cob_intr_min			(const int, ...);
COB_EXPIMP cob_field *cob_intr_max			(const int, ...);
COB_EXPIMP cob_field *cob_intr_midrange			(const int, ...);
COB_EXPIMP cob_field *cob_intr_median			(const int, ...);
COB_EXPIMP cob_field *cob_intr_mean			(const int, ...);
COB_EXPIMP cob_field *cob_intr_range			(const int, ...);
COB_EXPIMP cob_field *cob_intr_random			(const int, ...);
COB_EXPIMP cob_field *cob_intr_variance			(const int, ...);
COB_EXPIMP cob_field *cob_intr_standard_deviation	(const int, ...);
COB_EXPIMP cob_field *cob_intr_present_value		(const int, ...);
COB_EXPIMP cob_field *cob_intr_year_to_yyyy		(const int, ...);
COB_EXPIMP cob_field *cob_intr_date_to_yyyymmdd		(const int, ...);
COB_EXPIMP cob_field *cob_intr_day_to_yyyyddd		(const int, ...);
COB_EXPIMP cob_field *cob_intr_locale_compare		(const int, ...);
COB_EXPIMP cob_field *cob_intr_locale_date		(const int, const int,
							 cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_locale_time		(const int, const int,
							 cob_field *, cob_field *);

COB_EXPIMP cob_field *cob_intr_seconds_past_midnight	(void);
COB_EXPIMP cob_field *cob_intr_lcl_time_from_secs	(const int, const int,
							 cob_field *, cob_field *);

COB_EXPIMP cob_field *cob_intr_seconds_from_formatted_time	(cob_field *,
								 cob_field *);

COB_EXPIMP cob_field *cob_intr_boolean_of_integer	(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_char_national		(cob_field *);
COB_EXPIMP cob_field *cob_intr_display_of		(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_exception_file_n		(void);
COB_EXPIMP cob_field *cob_intr_exception_location_n	(void);
COB_EXPIMP cob_field *cob_intr_formatted_current_date	(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_formatted_date		(const int, const int,
							 cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_formatted_datetime	(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_formatted_time		(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_integer_of_boolean	(cob_field *);
COB_EXPIMP cob_field *cob_intr_national_of		(const int, const int,
							 const int, ...);
COB_EXPIMP cob_field *cob_intr_standard_compare		(const int, ...);
COB_EXPIMP cob_field *cob_intr_test_formatted_datetime	(cob_field *, cob_field *);

COB_EXPIMP cob_field *cob_intr_integer_of_formatted_date	(cob_field *,
								 cob_field *);

/*******************************/

#endif	/* COB_COMMON_H */
