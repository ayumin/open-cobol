/*
   Copyright (C) 2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2009 Roger While

   This file is part of GNU Cobol.

   The GNU Cobol runtime library is free software; you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with GNU Cobol; see the file COPYING.LIB. If not,
   write to the Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301 USA
*/

#ifndef COB_COMMON_H
#define COB_COMMON_H

/* Byte swap functions */

/*
   The original idea for the byteswap routines was taken from GLib.
   (Specifically glib/gtypes.h)
   GLib is licensed under the GNU Lesser General Public License.
*/

/* Generic swapping functions */

#define COB_BSWAP_16_CONSTANT(val)	((unsigned short) (	\
    (unsigned short) ((unsigned short) (val) >> 8) |		\
    (unsigned short) ((unsigned short) (val) << 8)))

#define COB_BSWAP_32_CONSTANT(val)	((unsigned int) (		\
    (((unsigned int) (val) & (unsigned int) 0x000000ffU) << 24) |	\
    (((unsigned int) (val) & (unsigned int) 0x0000ff00U) <<  8) |	\
    (((unsigned int) (val) & (unsigned int) 0x00ff0000U) >>  8) |	\
    (((unsigned int) (val) & (unsigned int) 0xff000000U) >> 24)))

#define COB_BSWAP_64_CONSTANT(val)	((unsigned long long) (	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x00000000000000ffULL) << 56) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x000000000000ff00ULL) << 40) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x0000000000ff0000ULL) << 24) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x00000000ff000000ULL) <<  8) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x000000ff00000000ULL) >>  8) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x0000ff0000000000ULL) >> 24) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0x00ff000000000000ULL) >> 40) |	\
    (((unsigned long long) (val) &				\
      (unsigned long long) 0xff00000000000000ULL) >> 56)))

/* Machine/OS specific overrides */

#if defined (__GNUC__) && (__GNUC__ >= 2)
#if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val) (__builtin_bswap32 (val))
#define COB_BSWAP_64(val) (__builtin_bswap64 (val))

#elif	defined(__i386__)

#define COB_BSWAP_16(val)				\
     (__extension__						\
      ({ register unsigned short int __v, __x = ((unsigned short) (val));	\
	 if (__builtin_constant_p (__x))			\
	   __v = COB_BSWAP_16_CONSTANT (__x);			\
	 else							\
	   __asm__ ("rorw $8, %w0"				\
		    : "=r" (__v)				\
 		    : "0" (__x)					\
 		    : "cc");					\
	 __v; }))
#define COB_BSWAP_32(val)				\
       (__extension__						\
	({ register unsigned int __v, __x = ((unsigned int) (val));	\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_32_CONSTANT (__x);			\
	   else							\
	     __asm__ ("bswap %0"				\
		      : "=r" (__v)				\
		      : "0" (__x));				\
	    __v; }))
#define COB_BSWAP_64(val)				\
       (__extension__						\
	({ union { unsigned long long __ll;			\
		   unsigned int __l[2]; } __w, __r;		\
	   __w.__ll = ((unsigned long long) (val));		\
	   if (__builtin_constant_p (__w.__ll))			\
	     __r.__ll = COB_BSWAP_64_CONSTANT (__w.__ll);	\
	   else							\
	     {							\
	       __r.__l[0] = COB_BSWAP_32 (__w.__l[1]);		\
	       __r.__l[1] = COB_BSWAP_32 (__w.__l[0]);		\
	     }							\
	   __r.__ll; }))

#elif defined (__ia64__)

#define COB_BSWAP_16(val)				\
       (__extension__						\
	({ register unsigned short __v, __x = ((unsigned short) (val));	\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_16_CONSTANT (__x);			\
	   else							\
	     __asm__ __volatile__ ("shl %0 = %1, 48 ;;"		\
				   "mux1 %0 = %0, @rev ;;"	\
				    : "=r" (__v)		\
				    : "r" (__x));		\
	    __v; }))
#define COB_BSWAP_32(val)				\
       (__extension__						\
	 ({ register unsigned int __v, __x = ((unsigned int) (val));	\
	    if (__builtin_constant_p (__x))			\
	      __v = COB_BSWAP_32_CONSTANT (__x);		\
	    else						\
	     __asm__ __volatile__ ("shl %0 = %1, 32 ;;"		\
				   "mux1 %0 = %0, @rev ;;"	\
				    : "=r" (__v)		\
				    : "r" (__x));		\
	    __v; }))
#define COB_BSWAP_64(val)				\
       (__extension__						\
	({ register unsigned long long __v,			\
	     __x = ((unsigned long long) (val));		\
	   if (__builtin_constant_p (__x))			\
	     __v = COB_BSWAP_64_CONSTANT (__x);			\
	   else							\
	     __asm__ __volatile__ ("mux1 %0 = %1, @rev ;;"	\
				   : "=r" (__v)			\
				   : "r" (__x));		\
	   __v; }))

#elif defined (__x86_64__)

#define COB_BSWAP_16(val)				\
     (__extension__						\
      ({ register unsigned short int __v, __x = ((unsigned short) (val));	\
	 if (__builtin_constant_p (__x))			\
	   __v = COB_BSWAP_16_CONSTANT (__x);			\
	 else							\
	   __asm__ ("rorw $8, %w0"				\
		    : "=r" (__v)				\
 		    : "0" (__x)					\
 		    : "cc");					\
	 __v; }))
#define COB_BSWAP_32(val)				\
       (__extension__						\
	 ({ register unsigned int __v, __x = ((unsigned int) (val));	\
	    if (__builtin_constant_p (__x))			\
	      __v = COB_BSWAP_32_CONSTANT (__x);			\
	    else						\
	     __asm__ ("bswapl %0"				\
		      : "=r" (__v)				\
		      : "0" (__x));				\
	    __v; }))
#define COB_BSWAP_64(val)				\
       (__extension__						\
	({ register unsigned long long __v, __x = ((unsigned long long) (val));	\
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

#else /* generic */

#define COB_BSWAP_16(val) (COB_BSWAP_16_CONSTANT (val))
#define COB_BSWAP_32(val) (COB_BSWAP_32_CONSTANT (val))
#define COB_BSWAP_64(val) (COB_BSWAP_64_CONSTANT (val))

#endif

/* End byte swap functions */

/* Compiler characteristics */

#ifdef _MSC_VER

#ifndef	_CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE	1
#endif

#define inline _inline
#include <malloc.h>
#include <io.h>
#include <fcntl.h>
#pragma warning(disable: 4996)
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#define snprintf		_snprintf
#define getpid			_getpid

#define __attribute__(x)

#ifdef	S_ISDIR
#undef	S_ISDIR
#endif
#define S_ISDIR(x)		(((x) & _S_IFMT) == _S_IFDIR)


#ifndef	_M_IA64
#ifdef	_WIN64
#define	__x86_64__
#else
#define	__i386__
#endif
#endif

#endif /* _MSC_VER */

#ifdef	__370__

#define inline __inline
#ifndef __timespec_struct
#define __timespec_struct 1
	struct timespec {
		time_t tv_sec;
		long   tv_nsec;
	};
#endif
#endif

#include <setjmp.h>

#if	defined(_WIN32) || defined(__CYGWIN__)
#ifdef	COB_LIB_EXPIMP
	#define COB_EXPIMP 	__declspec(dllexport) extern
#else
	#define COB_EXPIMP 	__declspec(dllimport) extern
#endif
#else
	#define COB_EXPIMP 	extern
#endif

#if	defined(__370__) || defined(_MSC_VER)
	#define COB_INLINE	__inline
#elif	defined(__INTEL_COMPILER)
	/* icc */
	#define COB_INLINE	inline
#elif	defined(__GNUC__)
	/* gcc */
	#define COB_INLINE	__inline__
#elif defined(COB_HAS_INLINE)
	#define COB_INLINE inline
#else
	#define COB_INLINE
#endif

/* Also OK for icc which defines __GNUC__ */

#if	defined(__GNUC__)
#define	COB_A_NORETURN	__attribute__((noreturn))
#define	COB_A_FORMAT10	__attribute__((format(printf, 1, 0)))
#define	COB_A_FORMAT12	__attribute__((format(printf, 1, 2)))
#define	COB_A_FORMAT23	__attribute__((format(printf, 2, 3)))
#define	COB_A_FORMAT34	__attribute__((format(printf, 3, 4)))
#else
#define	COB_A_NORETURN
#define	COB_A_FORMAT10
#define	COB_A_FORMAT12
#define	COB_A_FORMAT23
#define	COB_A_FORMAT34
#endif

#ifdef	_MSC_VER
#define	DECLNORET	__declspec(noreturn)
#else
#define	DECLNORET
#endif

#if defined(__GNUC__) && (__GNUC__ >= 3)
#define likely(x)	__builtin_expect(!!(x), 1)
#define unlikely(x)	__builtin_expect(!!(x), 0)
#define	COB_A_MALLOC	__attribute__((malloc))
#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)
#define	COB_NOINLINE	__attribute__((noinline))
#else
#define	COB_NOINLINE
#endif
#else
#define likely(x)	(x)
#define unlikely(x)	(x)
#define	COB_A_MALLOC
#define	COB_NOINLINE
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
#define	COB_MEDIUM_BUFF		8192
#define	COB_LARGE_BUFF		16384
#define	COB_MINI_MAX		(COB_MINI_BUFF - 1)
#define	COB_SMALL_MAX		(COB_SMALL_BUFF - 1)
#define	COB_NORMAL_MAX		(COB_NORMAL_BUFF - 1)
#define	COB_MEDIUM_MAX		(COB_MEDIUM_BUFF - 1)
#define	COB_LARGE_MAX		(COB_LARGE_BUFF - 1)

/* Perform stack size */
#define	COB_STACK_SIZE		255

/* Maximum number of parameters */
#define	COB_MAX_FIELD_PARAMS	64

/* Field */

/* field types */

#define COB_TYPE_UNKNOWN		0x00
#define COB_TYPE_GROUP			0x01
#define COB_TYPE_BOOLEAN		0x02

#define COB_TYPE_NUMERIC		0x10
#define COB_TYPE_NUMERIC_DISPLAY	0x10
#define COB_TYPE_NUMERIC_BINARY		0x11
#define COB_TYPE_NUMERIC_PACKED		0x12
#define COB_TYPE_NUMERIC_FLOAT		0x13
#define COB_TYPE_NUMERIC_DOUBLE		0x14
#define COB_TYPE_NUMERIC_EDITED		0x24

#define COB_TYPE_ALPHANUMERIC		0x21
#define COB_TYPE_ALPHANUMERIC_ALL	0x22
#define COB_TYPE_ALPHANUMERIC_EDITED	0x23

#define COB_TYPE_NATIONAL		0x40
#define COB_TYPE_NATIONAL_EDITED	0x41

/* field flags */

#define COB_FLAG_HAVE_SIGN		0x01
#define COB_FLAG_SIGN_SEPARATE		0x02
#define COB_FLAG_SIGN_LEADING		0x04
#define COB_FLAG_BLANK_ZERO		0x08
#define COB_FLAG_JUSTIFIED		0x10
#define COB_FLAG_BINARY_SWAP		0x20
#define COB_FLAG_REAL_BINARY		0x40
#define COB_FLAG_IS_POINTER		0x80

#define COB_FIELD_HAVE_SIGN(f)		((f)->attr->flags & COB_FLAG_HAVE_SIGN)
#define COB_FIELD_SIGN_SEPARATE(f)	((f)->attr->flags & COB_FLAG_SIGN_SEPARATE)
#define COB_FIELD_SIGN_LEADING(f)	((f)->attr->flags & COB_FLAG_SIGN_LEADING)
#define COB_FIELD_BLANK_ZERO(f)		((f)->attr->flags & COB_FLAG_BLANK_ZERO)
#define COB_FIELD_JUSTIFIED(f)		((f)->attr->flags & COB_FLAG_JUSTIFIED)
#define COB_FIELD_BINARY_SWAP(f)	((f)->attr->flags & COB_FLAG_BINARY_SWAP)
#define COB_FIELD_REAL_BINARY(f)	((f)->attr->flags & COB_FLAG_REAL_BINARY)
#define COB_FIELD_IS_POINTER(f)		((f)->attr->flags & COB_FLAG_IS_POINTER)

#define cob_get_sign(f)	(COB_FIELD_HAVE_SIGN (f) ? cob_real_get_sign (f) : 0)
#define cob_put_sign(f,s) if (COB_FIELD_HAVE_SIGN (f)) cob_real_put_sign (f, s)

#define COB_FIELD_TYPE(f)	((f)->attr->type)
#define COB_FIELD_DIGITS(f)	((f)->attr->digits)
#define COB_FIELD_SCALE(f)	((f)->attr->scale)
#define COB_FIELD_FLAGS(f)	((f)->attr->flags)
#define COB_FIELD_PIC(f)	((f)->attr->pic)

#define COB_FIELD_DATA(f)						  \
  ((f)->data +								  \
   ((COB_FIELD_SIGN_SEPARATE (f) && COB_FIELD_SIGN_LEADING (f)) ? 1 : 0))
#define COB_FIELD_SIZE(f)						\
  ((f)->size - (COB_FIELD_SIGN_SEPARATE (f) ? 1 : 0))

#define COB_FIELD_IS_NUMERIC(f)	(COB_FIELD_TYPE (f) & COB_TYPE_NUMERIC)


/* SIGN */

/*
 * positive: 0123456789
 * negative: pqrstuvwxy
 */
#define GET_SIGN_ASCII(x) x -= 0x40
#define PUT_SIGN_ASCII(x) x += 0x40

#define	COB_DISPLAY_SIGN_ASCII	0
#define	COB_DISPLAY_SIGN_EBCDIC	1

/* Fatal error definitions */

#define COB_FERROR_INITIALIZED	0
#define COB_FERROR_CODEGEN	1
#define COB_FERROR_CHAINING	2
#define COB_FERROR_STACK	3

/* Exception identifier enumeration */

#undef	COB_EXCEPTION
#define	COB_EXCEPTION(code,tag,name,critical)	tag,

enum cob_exception_id {
	COB_EC_ZERO,
#include <libcob/exception.def>
	COB_EC_MAX
};

#undef	COB_EXCEPTION


/* File attributes */

/* File version */
#define	COB_FILE_VERSION	0

/* Start conditions */
#define COB_EQ			1 	/* x == y */
#define COB_LT			2 	/* x <  y */
#define COB_LE			3 	/* x <= y */
#define COB_GT			4 	/* x >  y */
#define COB_GE			5 	/* x >= y */
#define COB_NE			6 	/* x != y */

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

#define	COB_SELECT_FILE_STATUS	0x01
#define	COB_SELECT_EXTERNAL	0x02
#define	COB_SELECT_LINAGE	0x04
#define	COB_SELECT_SPLITKEY	0x08

/* Lock mode */

#define COB_LOCK_EXCLUSIVE	1
#define COB_LOCK_MANUAL		2
#define COB_LOCK_AUTOMATIC	4
#define COB_LOCK_MULTIPLE	8
#define COB_LOCK_MASK		0x7

/* Open mode */

#define COB_OPEN_CLOSED		0
#define COB_OPEN_INPUT 		1
#define COB_OPEN_OUTPUT		2
#define COB_OPEN_I_O 		3
#define COB_OPEN_EXTEND		4
#define COB_OPEN_LOCKED		5

/* Close options */

#define COB_CLOSE_NORMAL	0
#define COB_CLOSE_LOCK		1
#define COB_CLOSE_NO_REWIND	2
#define COB_CLOSE_UNIT		3
#define COB_CLOSE_UNIT_REMOVAL	4

/* Write options */

#define COB_WRITE_MASK		0x0000ffff

#define COB_WRITE_LINES		0x00010000
#define COB_WRITE_PAGE		0x00020000
#define COB_WRITE_CHANNEL	0x00040000
#define COB_WRITE_AFTER		0x00100000
#define COB_WRITE_BEFORE	0x00200000
#define COB_WRITE_EOP		0x00400000
#define COB_WRITE_LOCK		0x00800000

/* Read options */

#define COB_READ_NEXT		0x01
#define COB_READ_PREVIOUS	0x02
#define COB_READ_FIRST		0x04
#define COB_READ_LAST		0x08
#define COB_READ_LOCK		0x10
#define COB_READ_NO_LOCK	0x20
#define COB_READ_KEPT_LOCK	0x40
#define COB_READ_WAIT_LOCK	0x80
#define COB_READ_IGNORE_LOCK	0x100

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
#define COB_STATUS_52_EOP			52
#define COB_STATUS_57_I_O_LINAGE		57
#define COB_STATUS_61_FILE_SHARING		61
#define COB_STATUS_91_NOT_AVAILABLE		91

/* Special status */

/* Need some value that does not conflict with errno for OPEN/LINAGE */
#define	COB_LINAGE_INVALID	16384
/* Need value that does not conflict with errno 30 (EROFS) for OPEN */
#define	COB_NOT_CONFIGURED	32768

/* End File attributes */

/* Number store defines */
#define COB_STORE_ROUND			0x01
#define COB_STORE_KEEP_ON_OVERFLOW	0x02
#define COB_STORE_TRUNC_ON_OVERFLOW	0x04

/* Screen attribute defines */
#define COB_SCREEN_BLACK	0
#define COB_SCREEN_BLUE		1
#define COB_SCREEN_GREEN	2
#define COB_SCREEN_CYAN		3
#define COB_SCREEN_RED		4
#define COB_SCREEN_MAGENTA	5
#define COB_SCREEN_YELLOW	6
#define COB_SCREEN_WHITE	7

#define COB_SCREEN_LINE_PLUS	0x00000001
#define COB_SCREEN_LINE_MINUS	0x00000002
#define COB_SCREEN_COLUMN_PLUS	0x00000004
#define COB_SCREEN_COLUMN_MINUS	0x00000008

#define COB_SCREEN_AUTO		0x00000010
#define COB_SCREEN_BELL		0x00000020
#define COB_SCREEN_BLANK_LINE	0x00000040
#define COB_SCREEN_BLANK_SCREEN	0x00000080
#define COB_SCREEN_BLINK	0x00000100
#define COB_SCREEN_ERASE_EOL	0x00000200
#define COB_SCREEN_ERASE_EOS	0x00000400
#define COB_SCREEN_FULL		0x00000800
#define COB_SCREEN_HIGHLIGHT	0x00001000
#define COB_SCREEN_LOWLIGHT	0x00002000
#define COB_SCREEN_REQUIRED	0x00004000
#define COB_SCREEN_REVERSE	0x00008000
#define COB_SCREEN_SECURE	0x00010000
#define COB_SCREEN_UNDERLINE	0x00020000
#define COB_SCREEN_OVERLINE	0x00040000
#define COB_SCREEN_PROMPT	0x00080000
#define COB_SCREEN_UPDATE	0x00100000
#define COB_SCREEN_INPUT	0x00200000
#define COB_SCREEN_SCROLL_DOWN	0x00400000

#define COB_SCREEN_TYPE_GROUP		0
#define COB_SCREEN_TYPE_FIELD		1
#define COB_SCREEN_TYPE_VALUE		2
#define COB_SCREEN_TYPE_ATTRIBUTE	3

/* End Screen attribute defines */

/* Global variables */

COB_EXPIMP int			cob_initialized;
COB_EXPIMP int			cob_exception_code;

COB_EXPIMP struct cob_module	*cob_current_module;

COB_EXPIMP int			cob_call_params;
COB_EXPIMP int			cob_save_call_params;
COB_EXPIMP int			cob_initial_external;

/* convert a digit (e.g., '0') into an integer (e.g., 0) */
#define cob_d2i(x)		((x) - '0')

/* convert an integer (e.g., 0) into a digit (e.g., '0') */
#define cob_i2d(x)		((x) + '0')


/* Structure/union declarations */

typedef unsigned char *	ucharptr;

/* External */

struct cob_external {
	struct cob_external	*next;
	char			*ext_alloc;
	char			*ename;
	int			esize;
};

/* Field attribute structure */

typedef struct {
	unsigned char	type;		/* Field type */
	unsigned char	digits;		/* Digit count */
	signed char	scale;		/* Field scale */
	unsigned char	flags;		/* Field flags */
	const char	*pic;		/* Pointer to picture string */
} cob_field_attr;

/* Field structure */

typedef struct {
	size_t			size;		/* Field size */
	unsigned char		*data;		/* Pointer to field data */
	const cob_field_attr	*attr;		/* Pointer to attribute */
} cob_field;

/* Internal representation of decimal numbers */
/* n = value / 10 ^ scale */
/* Decimal structure */

typedef struct {
	mpz_t		value;			/* GMP value definition */
	int		scale;			/* Decimal scale */
} cob_decimal;

typedef struct __cob_screen cob_screen;

struct __cob_screen {
	cob_screen		*next;
	cob_screen		*child;		/* for COB_SCREEN_TYPE_GROUP */
	cob_field		*field;		/* for COB_SCREEN_TYPE_FIELD */
	cob_field		*value;		/* for COB_SCREEN_TYPE_VALUE */
	cob_field		*line;
	cob_field		*column;
	cob_field		*foreg;
	cob_field		*backg;
	int			type;
	int			occurs;
	int			attr;		/* for COB_SCREEN_TYPE_ATTRIBUTE */
};


/* Module structure */

struct cob_module {
	struct cob_module		*next;
	const unsigned char		*collating_sequence;
	cob_field			*crt_status;
	cob_field			*cursor_pos;
	cob_field			**cob_procedure_parameters;
	const unsigned char		display_sign;
	const unsigned char		decimal_point;
	const unsigned char		currency_symbol;
	const unsigned char		numeric_separator;
	const unsigned char		flag_filename_mapping;
	const unsigned char		flag_binary_truncate;
	const unsigned char		flag_pretty_display;
	const unsigned char		spare8;
};
/* File connector */

/* Key structure */

struct cob_file_key {
	cob_field	*field;	/* key field */
	int		flag;	/* WITH DUPLICATES (for RELATIVE/INDEXED) */
				/* ASCENDING/DESCENDING (for SORT) */
	size_t		offset;	/* Offset of field */
};


/* File structure */

typedef struct {
	const char		*select_name;		/* Name in SELECT */
	unsigned char		*file_status;		/* FILE STATUS */
	cob_field		*assign;		/* ASSIGN TO */
	cob_field		*record;		/* record area */
	cob_field		*record_size;		/* record size depending on */
	struct cob_file_key	*keys;			/* RELATIVE/RECORD/SORT keys */
	void			*file;			/* file specific data pointer */
	void			*linorkeyptr;		/* LINAGE pointer or SPLIT KEY */
	const unsigned char	*sort_collating;	/* SORT collating */
	void			*extfh_ptr;		/* For EXTFH usage */
	size_t			record_min;		/* record min size */
	size_t			record_max;		/* record max size */
	size_t			nkeys;			/* number of keys */

	char			organization;		/* ORGANIZATION */
	char			access_mode;		/* ACCESS MODE */
	char			lock_mode;		/* LOCKMODE */
	char			open_mode;		/* OPEN MODE */
	char			flag_optional;		/* OPTIONAL */
	char			last_open_mode;		/* open mode given by OPEN */
	char			special;		/* Special file */
	char			flag_nonexistent;	/* nonexistent file */

	char			flag_end_of_file;	/* reached the end of file */
	char			flag_begin_of_file;	/* reached beginning of file */
	char			flag_first_read;	/* first READ after OPEN/START */
	char			flag_read_done;		/* last READ successfully done */
	char			flag_select_features;	/* SELECT features */
	char			flag_needs_nl;		/* LS file needs NL at close */
	char			flag_needs_top;		/* Linage needs top */
	char			file_version;		/* File I/O version */

} cob_file;


/* Linage structure */

struct linage_struct {
	cob_field		*linage;		/* LINAGE */
	cob_field		*linage_ctr;		/* LINAGE-COUNTER */
	cob_field		*latfoot;		/* LINAGE FOOTING */
	cob_field		*lattop;		/* LINAGE AT TOP */
	cob_field		*latbot;		/* LINAGE AT BOTTOM */
	int			lin_lines;		/* Current Linage */
	int			lin_foot;		/* Current Footage */
	int			lin_top;		/* Current Top */
	int			lin_bot;		/* Current Bottom */
};


/* File I/O function pointer structure */

/* Struct cob_fileio_funcs
	(*open)		(file, filename, mode, sharing);
	(*close)	(file, opt);
	(*start)	(file, cond, key);
	(*read)		(file, key, read_opts);
	(*read next)	(file, read_opts);
	(*write)	(file, opt);
	(*rewrite)	(file, opt);
	(*delete)	(file);
*/

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

COB_EXPIMP cob_field		cob_zero;		/* ZERO */
COB_EXPIMP cob_field		cob_space;		/* SPACE */
COB_EXPIMP cob_field		cob_high;		/* HIGH-VALUE */
COB_EXPIMP cob_field		cob_low;		/* LOW-VALUE */
COB_EXPIMP cob_field		cob_quote;		/* QUOTE */
COB_EXPIMP cob_field		cob_one;		/* Numeric ONE */


/*******************************/
/* Function declarations */

/*******************************/
/* Functions in common.c */

/* General functions */

COB_EXPIMP void cob_init		(const int, char **);
COB_EXPIMP void cob_module_enter	(struct cob_module *);
COB_EXPIMP void cob_module_leave	(struct cob_module *);

COB_EXPIMP void cobexit		(const int) COB_A_NORETURN;
DECLNORET COB_EXPIMP void cob_stop_run	(const int) COB_A_NORETURN;
DECLNORET COB_EXPIMP void cob_fatal_error	(const unsigned int) COB_A_NORETURN;
COB_EXPIMP void cob_runtime_error	(const char *, ...)  COB_A_FORMAT10;

COB_EXPIMP void *cob_malloc		(const size_t)  COB_A_MALLOC;

COB_EXPIMP void cob_check_version		(const char *, const char *,
						 const int);

COB_EXPIMP const char *cob_get_exception_name	(const int);

COB_EXPIMP void cob_accept_arg_number	(cob_field *);
COB_EXPIMP void cob_accept_arg_value	(cob_field *);
COB_EXPIMP void cob_accept_command_line	(cob_field *);

COB_EXPIMP void cob_set_exception		(const int);
COB_EXPIMP void cob_accept_date		(cob_field *);
COB_EXPIMP void cob_accept_date_yyyymmdd	(cob_field *);
COB_EXPIMP void cob_accept_day		(cob_field *);
COB_EXPIMP void cob_accept_day_yyyyddd	(cob_field *);
COB_EXPIMP void cob_accept_day_of_week	(cob_field *);
COB_EXPIMP void cob_accept_environment	(cob_field *);
COB_EXPIMP void cob_accept_time		(cob_field *);
COB_EXPIMP void cob_display_command_line	(cob_field *);
COB_EXPIMP void cob_display_environment	(const cob_field *);
COB_EXPIMP void cob_display_env_value	(const cob_field *);
COB_EXPIMP void cob_display_arg_number	(cob_field *);
COB_EXPIMP void cob_get_environment		(const cob_field *, cob_field *);
COB_EXPIMP void	cob_set_environment		(const cob_field *,
						 const cob_field *);
COB_EXPIMP void cob_chain_setup		(void *, const size_t,
						 const size_t);
COB_EXPIMP void cob_allocate		(unsigned char **, cob_field *,
					 cob_field *);
COB_EXPIMP void cob_free_alloc		(unsigned char **, unsigned char *);
COB_EXPIMP int  cobinit			(void);
COB_EXPIMP int  cobtidy			(void);
COB_EXPIMP void *cobcommandline		(int, int *, char ***,
					 char ***, char **);
COB_EXPIMP char *cobgetenv			(const char *);
COB_EXPIMP int  cobputenv			(char *);

/* System routines */
COB_EXPIMP int CBL_ERROR_PROC	(unsigned char *, unsigned char *);
COB_EXPIMP int CBL_EXIT_PROC	(unsigned char *, unsigned char *);
COB_EXPIMP int SYSTEM		(const unsigned char *);
COB_EXPIMP int CBL_AND		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_OR		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_NOR		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_XOR		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_IMP		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_NIMP		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_EQ		(unsigned char *, unsigned char *, const int);
COB_EXPIMP int CBL_NOT		(unsigned char *, const int);
COB_EXPIMP int CBL_XF4		(unsigned char *, unsigned char *);
COB_EXPIMP int CBL_XF5		(unsigned char *, unsigned char *);
COB_EXPIMP int CBL_X91		(unsigned char *, const unsigned char *,
				 unsigned char *);
COB_EXPIMP int CBL_TOUPPER		(unsigned char *, const int);
COB_EXPIMP int CBL_TOLOWER		(unsigned char *, const int);
COB_EXPIMP int CBL_OC_NANOSLEEP	(unsigned char *);
COB_EXPIMP int cob_acuw_getpid	(void);
COB_EXPIMP int cob_return_args	(unsigned char *);
COB_EXPIMP int cob_parameter_size	(unsigned char *);
COB_EXPIMP int cob_acuw_sleep	(unsigned char *);
COB_EXPIMP int cob_acuw_justify	(unsigned char *, ...);

/* Utilities */

COB_EXPIMP unsigned char	*cob_external_addr	(const char *, const int);
COB_EXPIMP unsigned char	*cob_get_pointer	(const unsigned char *);
COB_EXPIMP void		*cob_get_prog_pointer	(const unsigned char *);
COB_EXPIMP void		cob_set_location	(const char *, const char *,
						 const unsigned int, const char *,
						 const char *, const char *);
COB_EXPIMP void		cob_ready_trace		(void);
COB_EXPIMP void		cob_reset_trace		(void);

/* Switch */

COB_EXPIMP int		cob_get_switch		(const int);
COB_EXPIMP void		cob_set_switch		(const int, const int);

/* Comparison */

COB_EXPIMP int		cob_cmp			(cob_field *, cob_field *);

/* Class check */

COB_EXPIMP int		cob_is_omitted		(const cob_field *);
COB_EXPIMP int		cob_is_numeric		(const cob_field *);
COB_EXPIMP int		cob_is_alpha		(const cob_field *);
COB_EXPIMP int		cob_is_upper		(const cob_field *);
COB_EXPIMP int		cob_is_lower		(const cob_field *);

/* Table sort */

COB_EXPIMP void 	cob_table_sort_init	(const int, const unsigned char *);
COB_EXPIMP void 	cob_table_sort_init_key	(const int, cob_field *,
					 const size_t);
COB_EXPIMP void cob_table_sort			(cob_field *, const int);

/* Run-time error checking */

COB_EXPIMP void cob_check_numeric			(const cob_field *, const char *);
COB_EXPIMP void cob_check_based			(const unsigned char *,
						 const char *);
COB_EXPIMP void cob_check_odo			(const int, const int,
						 const int, const char *);
COB_EXPIMP void cob_check_subscript			(const int, const int,
						 const int, const char *);
COB_EXPIMP void cob_check_ref_mod			(const int, const int,
						 const int, const char *);

/* Comparison functions */
COB_EXPIMP int cob_numeric_cmp			(cob_field *, cob_field *);

/*******************************/
/* Functions in strings.c */

COB_EXPIMP void cob_inspect_init		(cob_field *, const int);
COB_EXPIMP void cob_inspect_start		(void);
COB_EXPIMP void cob_inspect_before		(const cob_field *);
COB_EXPIMP void cob_inspect_after		(const cob_field *);
COB_EXPIMP void cob_inspect_characters	(cob_field *);
COB_EXPIMP void cob_inspect_all		(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_leading		(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_first		(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_trailing	(cob_field *, cob_field *);
COB_EXPIMP void cob_inspect_converting	(const cob_field *, const cob_field *);
COB_EXPIMP void cob_inspect_finish		(void);

COB_EXPIMP void cob_string_init		(cob_field *, cob_field *);
COB_EXPIMP void cob_string_delimited	(cob_field *);
COB_EXPIMP void cob_string_append		(cob_field *);
COB_EXPIMP void cob_string_finish		(void);

COB_EXPIMP void cob_unstring_init		(cob_field *, cob_field *, const size_t);
COB_EXPIMP void cob_unstring_delimited	(cob_field *, const int);
COB_EXPIMP void cob_unstring_into		(cob_field *, cob_field *, cob_field *);
COB_EXPIMP void cob_unstring_tallying	(cob_field *);
COB_EXPIMP void cob_unstring_finish		(void);

/*******************************/
/* Functions in move.c */

COB_EXPIMP void		cob_move	(cob_field *, cob_field *);
COB_EXPIMP void		cob_set_int	(cob_field *, const int);
COB_EXPIMP int		cob_get_int	(cob_field *);

/*******************************/
/* Functions in numeric.c */

COB_EXPIMP void	cob_decimal_init	(cob_decimal *);
COB_EXPIMP void	cob_decimal_set_field	(cob_decimal *, cob_field *);
COB_EXPIMP int	cob_decimal_get_field	(cob_decimal *, cob_field *, const int);
COB_EXPIMP void	cob_decimal_add		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_sub		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_mul		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_div		(cob_decimal *, cob_decimal *);
COB_EXPIMP void	cob_decimal_pow		(cob_decimal *, cob_decimal *);
COB_EXPIMP int	cob_decimal_cmp		(cob_decimal *, cob_decimal *);

COB_EXPIMP int	cob_add			(cob_field *, cob_field *, const int);
COB_EXPIMP int	cob_sub			(cob_field *, cob_field *, const int);
COB_EXPIMP int	cob_add_int		(cob_field *, const int);
COB_EXPIMP int	cob_sub_int		(cob_field *, const int);
COB_EXPIMP int	cob_div_quotient	(cob_field *, cob_field *,
					 cob_field *, const int);
COB_EXPIMP int	cob_div_remainder	(cob_field *, const int);

COB_EXPIMP int	cob_cmp_int		(cob_field *, const int);
COB_EXPIMP int	cob_cmp_uint		(cob_field *, const unsigned int);
COB_EXPIMP int	cob_cmp_packed		(cob_field *, int);
COB_EXPIMP int	cob_cmp_numdisp		(const unsigned char *,
					 const size_t, const int);
COB_EXPIMP int	cob_cmp_sign_numdisp	(const unsigned char *,
					 const size_t, const int);
COB_EXPIMP int	cob_cmp_long_numdisp	(const unsigned char *,
					 const size_t, const int);
COB_EXPIMP void	cob_set_packed_zero	(cob_field *);
COB_EXPIMP void	cob_set_packed_int	(cob_field *, const int);

COB_EXPIMP int	cob_cmp_long_sign_numdisp	(const unsigned char *,
						 const size_t, const int);

/*******************************/
/* Functions in call.c */

DECLNORET COB_EXPIMP void	cob_call_error		(void) COB_A_NORETURN;


COB_EXPIMP void		cob_set_cancel		(const char *, void *, void *);
COB_EXPIMP void		*cob_resolve		(const char *);
COB_EXPIMP void		*cob_resolve_1		(const char *);
COB_EXPIMP const char	*cob_resolve_error	(void);

COB_EXPIMP void		*cob_call_resolve	(const cob_field *);
COB_EXPIMP void		*cob_call_resolve_1	(const cob_field *);
COB_EXPIMP void		cob_field_cancel	(const cob_field *);
COB_EXPIMP void		cobcancel		(const char *);
COB_EXPIMP int		cobcall			(const char *, const int, void **);
COB_EXPIMP int		cobfunc			(const char *, const int, void **);
COB_EXPIMP void		*cobsavenv		(struct cobjmp_buf *);
COB_EXPIMP void		*cobsavenv2		(struct cobjmp_buf *, const int);
COB_EXPIMP void		coblongjmp		(struct cobjmp_buf *);

#define	cobsetjmp(x)	setjmp (cobsavenv (x))


/*******************************/
/* Functions in screenio.c */

COB_EXPIMP int	cob_screen_mode;

COB_EXPIMP void cob_screen_line_col	(cob_field *, const int);
COB_EXPIMP void cob_screen_display	(cob_screen *, cob_field *,
					 cob_field *);
COB_EXPIMP void cob_screen_accept	(cob_screen *, cob_field *,
					 cob_field *);
COB_EXPIMP void cob_field_display	(cob_field *, cob_field *, cob_field *,
				 cob_field *, cob_field *, cob_field *,
				 const int);
COB_EXPIMP void cob_field_accept	(cob_field *, cob_field *, cob_field *,
				 cob_field *, cob_field *, cob_field *,
				 const int);

/*******************************/
/* Functions in termio.c */

COB_EXPIMP void cob_display	(const int, const int, const int, ...);
COB_EXPIMP void cob_accept	(cob_field *);

/*******************************/
/* Functions in fileio.c */

COB_EXPIMP cob_file	*cob_error_file;

COB_EXPIMP void cob_default_error_handle	(void);

COB_EXPIMP void cob_open		(cob_file *, const int, const int, cob_field *);
COB_EXPIMP void cob_close		(cob_file *, const int, cob_field *);
COB_EXPIMP void cob_read		(cob_file *, cob_field *, cob_field *, int);
COB_EXPIMP void cob_rewrite		(cob_file *, cob_field *, const int, cob_field *);
COB_EXPIMP void cob_delete		(cob_file *, cob_field *);
COB_EXPIMP void cob_start		(cob_file *, const int, cob_field *, cob_field *);
COB_EXPIMP void cob_write		(cob_file *, cob_field *, const int, cob_field *);

COB_EXPIMP void cob_unlock_file	(cob_file *, cob_field *);
COB_EXPIMP void cob_commit		(void);
COB_EXPIMP void cob_rollback	(void);

/* File system routines */
COB_EXPIMP int CBL_OPEN_FILE	(unsigned char *, unsigned char *,
				 unsigned char *, unsigned char *,
				 unsigned char *);
COB_EXPIMP int CBL_CREATE_FILE	(unsigned char *, unsigned char *,
				 unsigned char *, unsigned char *,
				 unsigned char *);
COB_EXPIMP int CBL_READ_FILE	(unsigned char *, unsigned char *,
				 unsigned char *, unsigned char *,
				 unsigned char *);
COB_EXPIMP int CBL_WRITE_FILE	(unsigned char *, unsigned char *,
				 unsigned char *, unsigned char *,
				 unsigned char *);
COB_EXPIMP int CBL_CLOSE_FILE	(unsigned char *);
COB_EXPIMP int CBL_FLUSH_FILE	(unsigned char *);
COB_EXPIMP int CBL_DELETE_FILE	(unsigned char *);
COB_EXPIMP int CBL_COPY_FILE	(unsigned char *, unsigned char *);
COB_EXPIMP int CBL_CHECK_FILE_EXIST	(unsigned char *, unsigned char *);
COB_EXPIMP int CBL_RENAME_FILE	(unsigned char *, unsigned char *);
COB_EXPIMP int CBL_GET_CURRENT_DIR	(const int, const int, unsigned char *);
COB_EXPIMP int CBL_CHANGE_DIR	(unsigned char *);
COB_EXPIMP int CBL_CREATE_DIR	(unsigned char *);
COB_EXPIMP int CBL_DELETE_DIR	(unsigned char *);
COB_EXPIMP int cob_acuw_chdir	(unsigned char *, unsigned char *);
COB_EXPIMP int cob_acuw_mkdir	(unsigned char *);
COB_EXPIMP int cob_acuw_copyfile	(unsigned char *, unsigned char *, unsigned char *);
COB_EXPIMP int cob_acuw_file_info	(unsigned char *, unsigned char *);
COB_EXPIMP int cob_acuw_file_delete	(unsigned char *, unsigned char *);

/* SORT routines */
COB_EXPIMP void	cob_file_sort_init	(cob_file *, const int,
					 const unsigned char *,
					 void *, cob_field *);
COB_EXPIMP void	cob_file_sort_init_key	(cob_file *, const int,
					 cob_field *, size_t);
COB_EXPIMP void	cob_file_sort_close	(cob_file *);
COB_EXPIMP void	cob_file_sort_using	(cob_file *, cob_file *);
COB_EXPIMP void	cob_file_sort_giving	(cob_file *, const size_t, ...);
COB_EXPIMP void	cob_file_release	(cob_file *);
COB_EXPIMP void	cob_file_return		(cob_file *);

/*******************************/
/* Functions in intrinsic.c */

COB_EXPIMP cob_field *cob_intr_binop		(cob_field *, int, cob_field *);
COB_EXPIMP cob_field *cob_intr_current_date		(const int, const int);
COB_EXPIMP cob_field *cob_intr_when_compiled	(const int, const int, cob_field *);
COB_EXPIMP cob_field *cob_intr_exception_file	(void);
COB_EXPIMP cob_field *cob_intr_exception_location	(void);
COB_EXPIMP cob_field *cob_intr_exception_status	(void);
COB_EXPIMP cob_field *cob_intr_exception_statement	(void);
COB_EXPIMP cob_field *cob_intr_char			(cob_field *);
COB_EXPIMP cob_field *cob_intr_ord			(cob_field *);
COB_EXPIMP cob_field *cob_intr_stored_char_length	(cob_field *);
COB_EXPIMP cob_field *cob_intr_combined_datetime	(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_date_of_integer	(cob_field *);
COB_EXPIMP cob_field *cob_intr_day_of_integer	(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer_of_date	(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer_of_day	(cob_field *);
COB_EXPIMP cob_field *cob_intr_test_date_yyyymmdd	(cob_field *);
COB_EXPIMP cob_field *cob_intr_test_day_yyyyddd	(cob_field *);
COB_EXPIMP cob_field *cob_intr_factorial		(cob_field *);

COB_EXPIMP cob_field *cob_intr_exp			(cob_field *);
COB_EXPIMP cob_field *cob_intr_exp10		(cob_field *);
COB_EXPIMP cob_field *cob_intr_abs			(cob_field *);
COB_EXPIMP cob_field *cob_intr_acos			(cob_field *);
COB_EXPIMP cob_field *cob_intr_asin			(cob_field *);
COB_EXPIMP cob_field *cob_intr_atan			(cob_field *);
COB_EXPIMP cob_field *cob_intr_cos			(cob_field *);
COB_EXPIMP cob_field *cob_intr_log			(cob_field *);
COB_EXPIMP cob_field *cob_intr_log10		(cob_field *);
COB_EXPIMP cob_field *cob_intr_sin			(cob_field *);
COB_EXPIMP cob_field *cob_intr_sqrt			(cob_field *);
COB_EXPIMP cob_field *cob_intr_tan			(cob_field *);

COB_EXPIMP cob_field *cob_intr_upper_case		(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_lower_case		(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_reverse		(const int, const int,
							 cob_field *);
COB_EXPIMP cob_field *cob_intr_concatenate		(const int, const int,
						 const int, ...);
COB_EXPIMP cob_field *cob_intr_substitute		(const int, const int,
						 const int, ...);
COB_EXPIMP cob_field *cob_intr_substitute_case	(const int, const int,
						 const int, ...);
COB_EXPIMP cob_field *cob_intr_trim			(const int, const int,
						 cob_field *, const int);
COB_EXPIMP cob_field *cob_intr_length		(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer		(cob_field *);
COB_EXPIMP cob_field *cob_intr_integer_part		(cob_field *);
COB_EXPIMP cob_field *cob_intr_fraction_part	(cob_field *);
COB_EXPIMP cob_field *cob_intr_sign			(cob_field *);
COB_EXPIMP cob_field *cob_intr_numval		(cob_field *);
COB_EXPIMP cob_field *cob_intr_numval_c		(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_annuity		(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_mod			(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_rem			(cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_sum			(const int, ...);
COB_EXPIMP cob_field *cob_intr_ord_min		(const int, ...);
COB_EXPIMP cob_field *cob_intr_ord_max		(const int, ...);
COB_EXPIMP cob_field *cob_intr_min			(const int, ...);
COB_EXPIMP cob_field *cob_intr_max			(const int, ...);
COB_EXPIMP cob_field *cob_intr_midrange		(const int, ...);
COB_EXPIMP cob_field *cob_intr_median		(const int, ...);
COB_EXPIMP cob_field *cob_intr_mean			(const int, ...);
COB_EXPIMP cob_field *cob_intr_range		(const int, ...);
COB_EXPIMP cob_field *cob_intr_random		(const int, ...);
COB_EXPIMP cob_field *cob_intr_variance		(const int, ...);
COB_EXPIMP cob_field *cob_intr_standard_deviation	(const int, ...);
COB_EXPIMP cob_field *cob_intr_present_value	(const int, ...);
COB_EXPIMP cob_field *cob_intr_year_to_yyyy		(const int, ...);
COB_EXPIMP cob_field *cob_intr_date_to_yyyymmdd	(const int, ...);
COB_EXPIMP cob_field *cob_intr_day_to_yyyyddd	(const int, ...);
COB_EXPIMP cob_field *cob_intr_locale_date		(const int, const int,
						 cob_field *, cob_field *);
COB_EXPIMP cob_field *cob_intr_locale_time		(const int, const int,
						 cob_field *, cob_field *);

COB_EXPIMP cob_field *cob_intr_seconds_past_midnight	(void);
COB_EXPIMP cob_field *cob_intr_lcl_time_from_secs		(const int, const int,
							 cob_field *, cob_field *);

COB_EXPIMP cob_field *cob_intr_seconds_from_formatted_time	(cob_field *,
							 cob_field *);


/*******************************/

#endif /* COB_COMMON_H */
