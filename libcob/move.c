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


#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

static cob_global	*cobglobptr;

#if	0	/* RXWRXW local edit symbols */
static unsigned int	cob_locale_edit;
static unsigned char	cob_lc_dec;
static unsigned char	cob_lc_thou;
#endif

static const cob_field_attr	const_alpha_attr =
				{COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL};
static const cob_field_attr	const_binll_attr =
				{COB_TYPE_NUMERIC_BINARY, 20, 0,
				 COB_FLAG_HAVE_SIGN, NULL};

static const int	cob_exp10[10] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,
	1000000000
};

static const cob_s64_t	cob_exp10_ll[19] = {
	COB_S64_C(1),
	COB_S64_C(10),
	COB_S64_C(100),
	COB_S64_C(1000),
	COB_S64_C(10000),
	COB_S64_C(100000),
	COB_S64_C(1000000),
	COB_S64_C(10000000),
	COB_S64_C(100000000),
	COB_S64_C(1000000000),
	COB_S64_C(10000000000),
	COB_S64_C(100000000000),
	COB_S64_C(1000000000000),
	COB_S64_C(10000000000000),
	COB_S64_C(100000000000000),
	COB_S64_C(1000000000000000),
	COB_S64_C(10000000000000000),
	COB_S64_C(100000000000000000),
	COB_S64_C(1000000000000000000)
};

static COB_INLINE int
cob_min_int (const int x, const int y)
{
	if (x < y) {
		return x;
	}
	return y;
}

static COB_INLINE int
cob_max_int (const int x, const int y)
{
	if (x > y) {
		return x;
	}
	return y;
}

static COB_INLINE COB_A_INLINE void
own_byte_memcpy (unsigned char *s1, const unsigned char *s2, size_t size)
{
	do {
		*s1++ = *s2++;
	} while (--size);
}

static int
cob_packed_get_sign (const cob_field *f)
{
	unsigned char	*p;

	if (!COB_FIELD_HAVE_SIGN (f)) {
		return 0;
	}
	p = f->data + f->size - 1;
	return ((*p & 0x0F) == 0x0D) ? -1 : 1;
}

static void
store_common_region (cob_field *f, const unsigned char *data,
		     const size_t size, const int scale)
{
	const unsigned char	*p;
	unsigned char		*q;
	size_t			csize;
	size_t			cinc;
	int			lf1 = -scale;
	int			lf2 = -COB_FIELD_SCALE (f);
	int			hf1 = (int) size + lf1;
	int			hf2 = (int) COB_FIELD_SIZE (f) + lf2;
	int			lcf;
	int			gcf;

	lcf = cob_max_int (lf1, lf2);
	gcf = cob_min_int (hf1, hf2);
	memset (COB_FIELD_DATA (f), '0', COB_FIELD_SIZE (f));
	if (gcf > lcf) {
		csize = (size_t)(gcf - lcf);
		p = data + hf1 - gcf;
		q = COB_FIELD_DATA (f) + hf2 - gcf;
		for (cinc = 0; cinc < csize; ++cinc, ++p, ++q) {
			if (unlikely(*p == ' ' || *p == 0)) {
				*q = (unsigned char)'0';
			} else {
				*q = *p;
			}
		}
	}
}

static COB_INLINE COB_A_INLINE cob_s64_t
cob_binary_mget_sint64 (const cob_field * const f)
{
	cob_s64_t	n = 0;
	size_t		fsiz = 8U - f->size;

#ifndef WORDS_BIGENDIAN
	if (COB_FIELD_BINARY_SWAP (f)) {
		if (COB_FIELD_HAVE_SIGN (f)) {
			own_byte_memcpy ((unsigned char *)&n, f->data, f->size);
			n = COB_BSWAP_64 (n);
			/* Shift with sign */
			n >>= 8 * fsiz;
		} else {
			own_byte_memcpy (((unsigned char *)&n) + fsiz, f->data, f->size);
			n = COB_BSWAP_64 (n);
		}
	} else {
		if (COB_FIELD_HAVE_SIGN (f)) {
			own_byte_memcpy (((unsigned char *)&n) + fsiz, f->data, f->size);
			/* Shift with sign */
			n >>= 8 * fsiz;
		} else {
			own_byte_memcpy ((unsigned char *)&n, f->data, f->size);
		}
	}
#else	/* WORDS_BIGENDIAN */
	if (COB_FIELD_HAVE_SIGN (f)) {
		own_byte_memcpy ((unsigned char *)&n, f->data, f->size);
		/* Shift with sign */
		n >>= 8 * fsiz;
	} else {
		own_byte_memcpy (((unsigned char *)&n) + fsiz, f->data, f->size);
	}
#endif	/* WORDS_BIGENDIAN */
	return n;
}

static COB_INLINE COB_A_INLINE cob_u64_t
cob_binary_mget_uint64 (const cob_field * const f)
{
	cob_u64_t		n = 0;
	size_t			fsiz = 8U - f->size;

#ifndef WORDS_BIGENDIAN
	if (COB_FIELD_BINARY_SWAP (f)) {
		own_byte_memcpy (((unsigned char *)&n) + fsiz, f->data, f->size);
		n = COB_BSWAP_64 (n);
	} else {
		own_byte_memcpy ((unsigned char *)&n, f->data, f->size);
	}
#else	/* WORDS_BIGENDIAN */
	own_byte_memcpy (((unsigned char *)&n) + fsiz, f->data, f->size);
#endif	/* WORDS_BIGENDIAN */

	return n;
}

static COB_INLINE COB_A_INLINE void
cob_binary_mset_sint64 (cob_field *f, cob_s64_t n)
{
#ifndef WORDS_BIGENDIAN
	unsigned char	*s;

	if (COB_FIELD_BINARY_SWAP (f)) {
		n = COB_BSWAP_64 (n);
		s = ((unsigned char *)&n) + 8 - f->size;
	} else {
		s = (unsigned char *)&n;
	}
	own_byte_memcpy (f->data, s, f->size);
#else	/* WORDS_BIGENDIAN */
	own_byte_memcpy (f->data, ((unsigned char *)&n) + 8 - f->size, f->size);
#endif	/* WORDS_BIGENDIAN */
}

static COB_INLINE COB_A_INLINE void
cob_binary_mset_uint64 (cob_field *f, cob_u64_t n)
{
#ifndef WORDS_BIGENDIAN
	unsigned char	*s;

	if (COB_FIELD_BINARY_SWAP (f)) {
		n = COB_BSWAP_64 (n);
		s = ((unsigned char *)&n) + 8 - f->size;
	} else {
		s = (unsigned char *)&n;
	}
	own_byte_memcpy (f->data, s, f->size);
#else	/* WORDS_BIGENDIAN */
	own_byte_memcpy (f->data, ((unsigned char *)&n) + 8 - f->size, f->size);
#endif	/* WORDS_BIGENDIAN */
}

/* Display */

static void
cob_move_alphanum_to_display (cob_field *f1, cob_field *f2)
{
	unsigned char	*p;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*e1;
	unsigned char	*e2;
	int		sign;
	int		count;
	int		size;
	unsigned char	c;
	unsigned char	dec_pt;
	unsigned char	num_sep;

	/* Initialize */
	s1 = f1->data;
	e1 = s1 + f1->size;
	s2 = COB_FIELD_DATA (f2);
	e2 = s2 + COB_FIELD_SIZE (f2);
	memset (f2->data, '0', f2->size);

	/* Skip white spaces */
	for (; s1 < e1; ++s1) {
		if (!isspace (*s1)) {
			break;
		}
	}

	/* Check for sign */
	sign = 0;
	if (s1 != e1) {
		if (*s1 == '+' || *s1 == '-') {
			sign = (*s1++ == '+') ? 1 : -1;
		}
	}

	dec_pt = COB_MODULE_PTR->decimal_point;
	num_sep = COB_MODULE_PTR->numeric_separator;

	/* Count the number of digits before decimal point */
	count = 0;
	for (p = s1; p < e1 && *p != dec_pt; ++p) {
		if (isdigit (*p)) {
			++count;
		}
	}

	/* Find the start position */
	size = (int) COB_FIELD_SIZE (f2) - COB_FIELD_SCALE(f2);
	if (count < size) {
		s2 += size - count;
	} else {
		while (count-- > size) {
			while (!isdigit (*s1++)) {
				;
			}
		}
	}

	/* Move */
	count = 0;
	for (; s1 < e1 && s2 < e2; ++s1) {
		c = *s1;
		if (isdigit (c)) {
			*s2++ = c;
		} else if (c == dec_pt) {
			if (count++ > 0) {
				goto error;
			}
		} else if (!(isspace (c) || c == num_sep)) {
			goto error;
		}
	}

	COB_PUT_SIGN (f2, sign);
	return;

error:
	memset (f2->data, '0', f2->size);
	COB_PUT_SIGN (f2, 0);
}

static void
cob_move_display_to_display (cob_field *f1, cob_field *f2)
{
	int	sign;

	sign = COB_GET_SIGN (f1);
	store_common_region (f2, COB_FIELD_DATA (f1), COB_FIELD_SIZE (f1),
			     COB_FIELD_SCALE (f1));

	COB_PUT_SIGN (f1, sign);
	COB_PUT_SIGN (f2, sign);
}

static void
cob_move_display_to_alphanum (cob_field *f1, cob_field *f2)
{
	unsigned char	*data1;
	unsigned char	*data2;
	size_t		size1;
	size_t		size2;
	int		sign;
	int		diff;
	int		zero_size;

	data1 = COB_FIELD_DATA (f1);
	size1 = COB_FIELD_SIZE (f1);
	sign = COB_GET_SIGN (f1);
	if (unlikely(COB_FIELD_SCALE(f1) < 0)) {
		/* Scaling */
		zero_size = (int)-COB_FIELD_SCALE(f1);
	} else {
		zero_size = 0;
	}
	data2 = f2->data;
	size2 = f2->size;
	if (unlikely(COB_FIELD_JUSTIFIED (f2))) {
		/* Justified right */
		if (zero_size) {
			/* Implied 0 ('P's) */
			zero_size = cob_min_int (zero_size, (int)size2);
			size2 -= zero_size;
			memset (data2 + size2, '0', (size_t) zero_size);
		}
		if (size2) {
			diff = (int)(size2 - size1);
			if (diff > 0) {
				/* Padding */
				memset (data2, ' ', (size_t)diff);
				data2 += diff;
				size2 -= diff;
			}
			memcpy (data2, data1 + size1 - size2, size2);
		}
	} else {
		diff = (int)(size2 - size1);
		if (diff < 0) {
			memcpy (data2, data1, size2);
		} else {
			memcpy (data2, data1, size1);
			if (zero_size) {
				/* Implied 0 ('P's) */
				zero_size = cob_min_int (zero_size, diff);
				memset (data2 + size1, '0', (size_t)zero_size);
				diff -= zero_size;
			}
			if (diff) {
				/* Padding */
				memset (data2 + size1 + zero_size, ' ',
					(size_t)diff);
			}
		}
	}

	COB_PUT_SIGN (f1, sign);
}

static void
cob_move_alphanum_to_alphanum (cob_field *f1, cob_field *f2)
{
	unsigned char	*data1;
	unsigned char	*data2;
	size_t		size1;
	size_t		size2;

	data1 = f1->data;
	size1 = f1->size;
	data2 = f2->data;
	size2 = f2->size;
	if (size1 >= size2) {
		/* Move string with truncation */
		if (COB_FIELD_JUSTIFIED (f2)) {
			memcpy (data2, data1 + size1 - size2, size2);
		} else {
			memcpy (data2, data1, size2);
		}
	} else {
		/* Move string with padding */
		if (COB_FIELD_JUSTIFIED (f2)) {
			memset (data2, ' ', size2 - size1);
			memcpy (data2 + size2 - size1, data1, size1);
		} else {
			memcpy (data2, data1, size1);
			memset (data2 + size1, ' ', size2 - size1);
		}
	}
}

/* Packed decimal */

static void
cob_move_display_to_packed (cob_field *f1, cob_field *f2)
{
	unsigned char	*data1;
	unsigned char	*data2;
	unsigned char	*p;
	size_t		digits1;
	size_t		digits2;
	size_t		i;
	size_t		offset;
	int		sign;
	int		scale1;
	int		scale2;
	unsigned char	n;

	sign = COB_GET_SIGN (f1);
	data1 = COB_FIELD_DATA (f1);
	digits1 = COB_FIELD_DIGITS (f1);
	scale1 = COB_FIELD_SCALE (f1);
	data2 = f2->data;
	digits2 = COB_FIELD_DIGITS (f2);
	scale2 = COB_FIELD_SCALE (f2);

	/* Pack string */
	memset (f2->data, 0, f2->size);
	if (COB_FIELD_NO_SIGN_NIBBLE (f2)) {
		offset = digits2 % 2;
	} else {
		offset = 1 - (digits2 % 2);
	}
	p = data1 + (digits1 - scale1) - (digits2 - scale2);
	for (i = offset; i < digits2 + offset; ++i, ++p) {
		n = (data1 <= p && p < data1 + digits1 && *p != ' ') ?
			COB_D2I (*p) : 0;
		if (i % 2 == 0) {
			data2[i / 2] = n << 4;
		} else {
			data2[i / 2] |= n;
		}
	}

	COB_PUT_SIGN (f1, sign);
	if (COB_FIELD_NO_SIGN_NIBBLE (f2)) {
		return;
	}
	p = f2->data + f2->size - 1;
	if (!COB_FIELD_HAVE_SIGN (f2)) {
		*p = (*p & 0xF0) | 0x0F;
	} else if (sign < 0) {
		*p = (*p & 0xF0) | 0x0D;
	} else {
		*p = (*p & 0xF0) | 0x0C;
	}
}

static void
cob_move_packed_to_display (cob_field *f1, cob_field *f2)
{
	unsigned char	*data;
	size_t		i;
	size_t		offset;
	int		sign;
	unsigned char	buff[256];

	/* Unpack string */
	data = f1->data;
	if (COB_FIELD_NO_SIGN_NIBBLE (f1)) {
		sign = 0;
		offset = COB_FIELD_DIGITS(f1) % 2;
	} else {
		sign = cob_packed_get_sign (f1);
		offset = 1 - (COB_FIELD_DIGITS(f1) % 2);
	}
	for (i = offset; i < COB_FIELD_DIGITS(f1) + offset; ++i) {
		if (i % 2 == 0) {
			buff[i - offset] = COB_I2D (data[i / 2] >> 4);
		} else {
			buff[i - offset] = COB_I2D (data[i / 2] & 0x0F);
		}
	}

	/* Store */
	store_common_region (f2, buff, (size_t)COB_FIELD_DIGITS (f1),
			     COB_FIELD_SCALE (f1));

	COB_PUT_SIGN (f2, sign);
}

/* Floating point */

static void
cob_move_fp_to_fp (cob_field *src, cob_field *dst)
{
	double	dfp;
	float	ffp;

	if (COB_FIELD_TYPE (src) == COB_TYPE_NUMERIC_FLOAT) {
		memcpy ((void *)&ffp, src->data, sizeof(float));
		dfp = (double)ffp;
	} else {
		memcpy ((void *)&dfp, src->data, sizeof(double));
		ffp = (float)dfp;
	}
	if (COB_FIELD_TYPE (dst) == COB_TYPE_NUMERIC_FLOAT) {
		memcpy (dst->data, (void *)&ffp, sizeof(float));
	} else {
		memcpy (dst->data, (void *)&dfp, sizeof(double));
	}
}

/* Binary integer */


static void
cob_move_binary_to_binary (cob_field *f1, cob_field *f2)
{
	union {
		cob_u64_t		val;
		cob_s64_t		val2;
	}		ul64;
	unsigned int	sign;

	sign = 0;
	if (COB_FIELD_HAVE_SIGN (f1)) {
		ul64.val2 = cob_binary_mget_sint64 (f1);
		if (ul64.val2 < 0) {
			sign = 1;
		}
	} else {
		ul64.val = cob_binary_mget_uint64 (f1);
	}
	if (COB_FIELD_HAVE_SIGN (f2)) {
		cob_binary_mset_sint64 (f2, ul64.val2);
	} else {
		if (sign) {
			cob_binary_mset_uint64 (f2, (cob_u64_t)(-ul64.val2));
		} else {
			cob_binary_mset_uint64 (f2, ul64.val);
		}
	}
}

static void
cob_move_display_to_binary (cob_field *f1, cob_field *f2)
{
	unsigned char	*data1;
	cob_u64_t	val;
	cob_s64_t	val2;
	size_t		i, size;
	size_t		size1;
	int		sign;

	size1 = COB_FIELD_SIZE (f1);
	data1 = COB_FIELD_DATA (f1);
	sign = COB_GET_SIGN (f1);
	/* Get value */
	val = 0;
	size = size1 - COB_FIELD_SCALE(f1) + COB_FIELD_SCALE(f2);
	for (i = 0; i < size; ++i) {
		if (val) {
			val *= 10;
		}
		if (i < size1) {
			val += COB_D2I (data1[i]);
		}
	}

	if (COB_FIELD_BINARY_TRUNC (f2) &&
	    !COB_FIELD_REAL_BINARY(f2)) {
		val %= cob_exp10_ll[(int)COB_FIELD_DIGITS(f2)];
	}

	if (COB_FIELD_HAVE_SIGN (f2)) {
		if (sign < 0) {
			val2 = -(cob_s64_t)val;
		} else {
			val2 = val;
		}
		cob_binary_mset_sint64 (f2, val2);
	} else {
		cob_binary_mset_uint64 (f2, val);
	}

	COB_PUT_SIGN (f1, sign);
}

static void
cob_move_binary_to_display (cob_field *f1, cob_field *f2)
{
	cob_u64_t		val;
	cob_s64_t		val2;
	int			i;
	int			sign;
	char			buff[32];

	sign = 1;
	/* Get value */
	if (COB_FIELD_HAVE_SIGN (f1)) {
		val2 = cob_binary_mget_sint64 (f1);
		if (val2 < 0) {
			sign = -1;
			val = -(cob_u64_t)val2;
		} else {
			val = val2;
		}
	} else {
		val = cob_binary_mget_uint64 (f1);
	}

	/* Convert to string */
	i = 20;
	while (val > 0) {
		buff[--i] = (char) COB_I2D (val % 10);
		val /= 10;
	}

	/* Store */
	store_common_region (f2, (cob_u8_ptr)buff + i, (size_t)(20 - i),
		COB_FIELD_SCALE(f1));

	COB_PUT_SIGN (f2, sign);
}

/* Edited */

static void
cob_move_display_to_edited (cob_field *f1, cob_field *f2)
{
	const char	*p;
	unsigned char	*min;
	unsigned char	*max;
	unsigned char	*src;
	unsigned char	*dst;
	unsigned char	*end;
	unsigned char	*decimal_point;
	int		sign;
	int		neg;
	int		count;
	int		count_sign;
	int		count_curr;
	int		trailing_sign;
	int		trailing_curr;
	int		is_zero;
	int		suppress_zero;
	int		sign_first;
	int		p_is_left;
	int		repeat;
	int		n;
	unsigned char	pad;
	unsigned char	x;
	unsigned char	c;
	unsigned char	sign_symbol;
	unsigned char	curr_symbol;
	unsigned char	dec_symbol;
	unsigned char	currency;

	decimal_point = NULL;
	count = 0;
	count_sign = 1;
	count_curr = 1;
	trailing_sign = 0;
	trailing_curr = 0;
	is_zero = 1;
	suppress_zero = 1;
	sign_first = 0;
	p_is_left = 0;
	pad = ' ';
	sign_symbol = 0;
	curr_symbol = 0;

	currency = COB_MODULE_PTR->currency_symbol;

	if (COB_MODULE_PTR->decimal_point == ',') {
		dec_symbol = ',';
	} else {
		dec_symbol = '.';
	}

	sign = COB_GET_SIGN (f1);
	neg = (sign < 0) ? 1 : 0;
	/* Count the number of digit places before decimal point */
	for (p = COB_FIELD_PIC (f2); *p; p += 5) {
		c = p[0];
		memcpy ((unsigned char *)&repeat, p + 1, sizeof(int));
		if (c == '9' || c == 'Z' || c == '*') {
			count += repeat;
			count_sign = 0;
			count_curr = 0;
		} else if (count_curr && c == currency) {
			count += repeat;
		} else if (count_sign && (c == '+' || c == '-')) {
			count += repeat;
		} else if (c == 'P') {
			if (count == 0) {
				p_is_left = 1;
				break;
			} else {
				count += repeat;
				count_sign = 0;
				count_curr = 0;
			}
		} else if (c == 'V' || c == dec_symbol) {
			break;
		}
	}

	min = COB_FIELD_DATA (f1);
	max = min + COB_FIELD_SIZE (f1);
	src = max - COB_FIELD_SCALE(f1) - count;
	dst = f2->data;
	end = f2->data + f2->size;
	for (p = COB_FIELD_PIC (f2); *p;) {
		c = *p++;	/* PIC char */
		memcpy ((void *)&n, p, sizeof(int));	/* PIC char count */
		p += sizeof(int);
		for (; n > 0; n--, ++dst) {
			switch (c) {
			case '0':
			case '/':
				*dst = c;
				break;

			case 'B':
				*dst = suppress_zero ? pad : 'B';
				break;

			case 'P':
				if (p_is_left) {
					++src;
					--dst;
				}
				break;

			case '9':
				*dst = (min <= src && src < max) ? *src++ : (src++, '0');
				if (*dst != '0') {
					is_zero = suppress_zero = 0;
				}
				suppress_zero = 0;
				trailing_sign = 1;
				trailing_curr = 1;
				break;

			case 'V':
				--dst;
				decimal_point = dst;
				break;

			case '.':
			case ',':
				if (c == dec_symbol) {
					*dst = dec_symbol;
					decimal_point = dst;
				} else {
					if (suppress_zero) {
						*dst = pad;
					} else {
						*dst = c;
					}
				}
				break;

			case 'C':
			case 'D':
				end = dst;
				/* Check negative and not zero */
				if (neg && !is_zero) {
					if (c == 'C') {
						memcpy (dst, "CR", (size_t)2);
					} else {
						memcpy (dst, "DB", (size_t)2);
					}
				} else {
					memset (dst, ' ', (size_t)2);
				}
				dst++;
				break;

			case 'Z':
			case '*':
				x = (min <= src && src < max) ? *src++ : (src++, '0');
				if (x != '0') {
					is_zero = suppress_zero = 0;
				}
				pad = (c == '*') ? '*' : ' ';
				*dst = suppress_zero ? pad : x;
				trailing_sign = 1;
				trailing_curr = 1;
				break;

			case '+':
			case '-':
				x = (min <= src && src < max) ? *src++ : (src++, '0');
				if (x != '0') {
					is_zero = suppress_zero = 0;
				}
				if (trailing_sign) {
					/* Check negative and not zero */
					if (neg && !is_zero) {
						*dst = '-';
					} else if (c == '+') {
						*dst = '+';
					} else {
						*dst = ' ';
					}
					--end;
				} else if (dst == f2->data || suppress_zero) {
					*dst = pad;
					sign_symbol = c;
					if (!curr_symbol) {
						++sign_first;
					}
				} else {
					*dst = x;
				}
				break;

			default:
				if (c == currency) {
					x = (min <= src && src < max) ? *src++ : (src++, '0');
					if (x != '0') {
						is_zero = suppress_zero = 0;
					}
					if (trailing_curr) {
						*dst = currency;
						--end;
					} else if (dst == f2->data || suppress_zero) {
						*dst = pad;
						curr_symbol = currency;
					} else {
						*dst = x;
					}
					break;
				}

				*dst = '?';	/* Invalid PIC */
			}
		}
	}

	if (sign_symbol) {
		/* Check negative and not zero */
		if (neg && !is_zero) {
			sign_symbol = '-';
		} else if (sign_symbol != '+') {
			sign_symbol = ' ';
		}
	}

	if (suppress_zero || (is_zero && COB_FIELD_BLANK_ZERO (f2))) {
		/* All digits are zeros */
		if (pad == ' ' || COB_FIELD_BLANK_ZERO (f2)) {
			memset (f2->data, ' ', f2->size);
		} else {
			for (dst = f2->data; dst < f2->data + f2->size; ++dst) {
				if (*dst != dec_symbol) {
					*dst = pad;
				}
			}
		}
	} else {
		/* Put zero after the decimal point if necessary */
		if (decimal_point) {
			for (dst = decimal_point + 1; dst < end; ++dst) {
				switch (*dst) {
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
				case ',':
				case '+':
				case '-':
				case '/':
				case 'B':
					break;
				default:
					*dst = '0';
				}
			}
		}

		/* Put sign or currency symbol at the beginning */
		if (sign_symbol || curr_symbol) {
			for (dst = end - 1; dst > f2->data; --dst) {
				if (*dst == ' ') {
					break;
				}
			}
			if (sign_symbol && curr_symbol) {
				if (sign_first) {
					*dst = curr_symbol;
					--dst;
					if (dst >= f2->data) {
						*dst = sign_symbol;
					}
				} else {
					*dst = sign_symbol;
					--dst;
					if (dst >= f2->data) {
						*dst = curr_symbol;
					}
				}
			} else if (sign_symbol) {
				*dst = sign_symbol;
			} else {
				*dst = curr_symbol;
			}
		}

		/* Replace all 'B's by pad */
		count = 0;
		for (dst = f2->data; dst < end; ++dst) {
			if (*dst == 'B') {
				if (count == 0) {
					*dst = pad;
				} else {
					*dst = ' ';
				}
			} else {
				++count;
			}
		}
	}

	COB_PUT_SIGN (f1, sign);
}

static void
cob_move_edited_to_display (cob_field *f1, cob_field *f2)
{
	unsigned char	*p;
	unsigned char	*buff;
	const char	*p1;
	size_t		i;
	int		sign = 0;
	int		scale = 0;
	int		count = 0;
	int		have_point = 0;
	int		cp;
	int		n;
	unsigned char	c;
	unsigned char	dec_pt;

	dec_pt = COB_MODULE_PTR->decimal_point;
	buff = cob_malloc (f1->size);
	p = buff;
	/* De-edit */
	for (i = 0; i < f1->size; ++i) {
		cp = f1->data[i];
		switch (cp) {
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
			*p++ = cp;
			if (have_point) {
				++scale;
			}
			break;
		case '.':
		case ',':
			if (cp == dec_pt) {
				have_point = 1;
			}
			break;
		case '-':
		case 'C':
			sign = -1;
			break;
		}
	}
	/* Count number of digit places after decimal point in case of 'V', 'P' */
	if (scale == 0) {
		for (p1 = COB_FIELD_PIC (f1); *p1; p1 += 5) {
			c = p1[0];
			memcpy ((void *)&n, p1 + 1, sizeof(int));
			if (c == '9' || c == '0' || c == 'Z' || c == '*') {
				if (have_point) {
					scale += n;
				} else {
					count += n;
				}
			} else if (c == 'P') {
				if (count == 0) {
					have_point = 1;
					scale += n;
				} else {
					scale -= n;
				}
			} else if (c == 'V') {
				have_point = 1;
			}
		}
	}

	/* Store */
	store_common_region (f2, buff, (size_t)(p - buff), scale);

	COB_PUT_SIGN (f2, sign);
	free (buff);
}

static void
cob_move_alphanum_to_edited (cob_field *f1, cob_field *f2)
{
	const char	*p;
	unsigned char	*max;
	unsigned char	*src;
	unsigned char	*dst;
	int		sign;
	int		n;
	unsigned char	c;

	sign = COB_GET_SIGN (f1);
	src = COB_FIELD_DATA (f1);
	max = src + COB_FIELD_SIZE (f1);
	dst = f2->data;
	for (p = COB_FIELD_PIC (f2); *p;) {
		c = *p++;	/* PIC char */
		memcpy ((void *)&n, p, sizeof(int));	/* PIC char count */
		p += sizeof(int);
		for (; n > 0; --n) {
			switch (c) {
			case 'A':
			case 'X':
			case '9':
				*dst++ = (src < max) ? *src++ : ' ';
				break;
			case '0':
			case '/':
				*dst++ = c;
				break;
			case 'B':
				*dst++ = ' ';
				break;
			default:
				*dst++ = '?';	/* Invalid PIC */
			}
		}
	}
	COB_PUT_SIGN (f1, sign);
}

/* MOVE dispatcher */

static void
indirect_move (void (*func) (cob_field *src, cob_field *dst),
	       cob_field *src, cob_field *dst,
	       const size_t size, const int scale)
{
	cob_field	temp;
	cob_field_attr	attr;

	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, size, scale,
			COB_FLAG_HAVE_SIGN, NULL);
	temp.size = size;
	temp.data = cob_malloc (size);
	temp.attr = &attr;
	func (src, &temp);
	cob_move (&temp, dst);
	free (temp.data);
}

static void
cob_move_all (cob_field *src, cob_field *dst)
{
	unsigned char		*p;
	size_t			i;
	size_t			digcount;
	cob_field		temp;
	cob_field_attr		attr;

	if (likely(COB_FIELD_IS_ALNUM(dst))) {
		if (likely(src->size == 1)) {
			memset (dst->data, src->data[0], dst->size);
		} else {
			digcount = src->size;
			for (i = 0; i < dst->size; ++i) {
				dst->data[i] = src->data[i % digcount];
			}
		}
		return;
	}
	COB_ATTR_INIT (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL);
	if (COB_FIELD_IS_NUMERIC(dst)) {
		digcount = COB_MAX_DIGITS;
		attr.type = COB_TYPE_NUMERIC_DISPLAY;
		attr.digits = COB_MAX_DIGITS;
	} else {
		digcount = dst->size;
	}
	p = cob_malloc (digcount);
	temp.size = digcount;
	temp.data = p;
	temp.attr = &attr;
	if (likely(src->size == 1)) {
		memset (p, src->data[0], digcount);
	} else {
		for (i = 0; i < digcount; ++i) {
			p[i] = src->data[i % src->size];
		}
	}

	cob_move (&temp, dst);
	free (p);
}

void
cob_move (cob_field *src, cob_field *dst)
{
	int		opt;
	cob_field	temp;
	unsigned char	data[4];

	if (src == dst) {
		return;
	}
	if (dst->size == 0) {
		return;
	}
	if (unlikely(src->size == 0)) {
		temp.size = 1;
		temp.data = data;
		temp.attr = &const_alpha_attr;
		data[0] = ' ';
		data[1] = 0;
		src = &temp;
	}
	if (COB_FIELD_TYPE (src) == COB_TYPE_ALPHANUMERIC_ALL) {
		cob_move_all (src, dst);
		return;
	}

	/* Non-elementary move */
	if (COB_FIELD_TYPE (src) == COB_TYPE_GROUP ||
	    COB_FIELD_TYPE (dst) == COB_TYPE_GROUP) {
		cob_move_alphanum_to_alphanum (src, dst);
		return;
	}

	opt = 0;
	if (COB_FIELD_TYPE (dst) == COB_TYPE_NUMERIC_BINARY) {
		if (COB_FIELD_BINARY_TRUNC (dst) &&
		    !COB_FIELD_REAL_BINARY(dst)) {
			opt = COB_STORE_TRUNC_ON_OVERFLOW;
		}
	}

	/* Elementary move */
	switch (COB_FIELD_TYPE (src)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		case COB_TYPE_NUMERIC_DISPLAY:
			cob_move_display_to_display (src, dst);
			return;
		case COB_TYPE_NUMERIC_PACKED:
			cob_move_display_to_packed (src, dst);
			return;
		case COB_TYPE_NUMERIC_BINARY:
			cob_move_display_to_binary (src, dst);
			return;
		case COB_TYPE_NUMERIC_EDITED:
			cob_move_display_to_edited (src, dst);
			return;
		case COB_TYPE_ALPHANUMERIC_EDITED:
			if (COB_FIELD_SCALE(src) < 0 ||
			    COB_FIELD_SCALE(src) > COB_FIELD_DIGITS(src)) {
				/* Expand P's */
				indirect_move (cob_move_display_to_display, src, dst,
					      (size_t)cob_max_int ((int)COB_FIELD_DIGITS(src), (int)COB_FIELD_SCALE(src)),
					      cob_max_int (0, (int)COB_FIELD_SCALE(src)));
				return;
			} else {
				cob_move_alphanum_to_edited (src, dst);
				return;
			}
		default:
			cob_move_display_to_alphanum (src, dst);
			return;
		}

	case COB_TYPE_NUMERIC_PACKED:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_DISPLAY:
			cob_move_packed_to_display (src, dst);
			return;
		case COB_TYPE_NUMERIC_BINARY:
			cob_decimal_setget_fld (src, dst, opt);
			return;
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		default:
			indirect_move (cob_move_packed_to_display, src, dst,
					(size_t)(COB_FIELD_DIGITS(src)),
					COB_FIELD_SCALE(src));
			return;
		}

	case COB_TYPE_NUMERIC_BINARY:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_BINARY:
			if (COB_FIELD_SCALE(src) == COB_FIELD_SCALE(dst)) {
				cob_move_binary_to_binary (src, dst);
				return;
			}
			cob_decimal_setget_fld (src, dst, opt);
			return;
		case COB_TYPE_NUMERIC_DISPLAY:
			cob_move_binary_to_display (src, dst);
			return;
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		case COB_TYPE_NUMERIC_EDITED:
			indirect_move (cob_move_binary_to_display, src, dst,
				       (size_t)COB_MAX_DIGITS,
				       COB_FIELD_SCALE(src));
			return;
		default:
			indirect_move (cob_move_binary_to_display, src, dst,
				       (size_t)(COB_FIELD_DIGITS(src)),
				       COB_FIELD_SCALE(src));
			return;
		}

	case COB_TYPE_NUMERIC_EDITED:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_DISPLAY:
			cob_move_edited_to_display (src, dst);
			return;
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_BINARY:
		case COB_TYPE_NUMERIC_EDITED:
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			indirect_move (cob_move_edited_to_display, src, dst,
					(size_t)(2 * COB_MAX_DIGITS),
					COB_MAX_DIGITS);
			return;
		case COB_TYPE_ALPHANUMERIC_EDITED:
			cob_move_alphanum_to_edited (src, dst);
			return;
		default:
			cob_move_alphanum_to_alphanum (src, dst);
			return;
		}

	case COB_TYPE_NUMERIC_DOUBLE:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_DOUBLE:
			memcpy (dst->data, src->data, sizeof(double));
			return;
		case COB_TYPE_NUMERIC_FLOAT:
			cob_move_fp_to_fp (src, dst);
			return;
		case COB_TYPE_NUMERIC_BINARY:
			cob_decimal_setget_fld (src, dst, opt);
			return;
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_DISPLAY:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		default:
			cob_decimal_move_temp (src, dst);
			return;
		}

	case COB_TYPE_NUMERIC_FLOAT:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_FLOAT:
			memcpy (dst->data, src->data, sizeof(float));
			return;
		case COB_TYPE_NUMERIC_DOUBLE:
			cob_move_fp_to_fp (src, dst);
			return;
		case COB_TYPE_NUMERIC_BINARY:
			cob_decimal_setget_fld (src, dst, opt);
			return;
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_DISPLAY:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		default:
			cob_decimal_move_temp (src, dst);
			return;
		}

	case COB_TYPE_NUMERIC_FP_DEC64:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_BINARY:
			cob_decimal_setget_fld (src, dst, opt);
			return;
		case COB_TYPE_NUMERIC_FP_DEC64:
			memcpy (dst->data, src->data, (size_t)8);
			return;
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_DISPLAY:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC128:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		default:
			cob_decimal_move_temp (src, dst);
			return;
		}
	case COB_TYPE_NUMERIC_FP_DEC128:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_BINARY:
			cob_decimal_setget_fld (src, dst, opt);
			return;
		case COB_TYPE_NUMERIC_FP_DEC128:
			memcpy (dst->data, src->data, (size_t)16);
			return;
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_DISPLAY:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
			cob_decimal_setget_fld (src, dst, 0);
			return;
		default:
			cob_decimal_move_temp (src, dst);
			return;
		}
	default:
		switch (COB_FIELD_TYPE (dst)) {
		case COB_TYPE_NUMERIC_DISPLAY:
			cob_move_alphanum_to_display (src, dst);
			return;
		case COB_TYPE_NUMERIC_PACKED:
		case COB_TYPE_NUMERIC_BINARY:
		case COB_TYPE_NUMERIC_EDITED:
		case COB_TYPE_NUMERIC_FLOAT:
		case COB_TYPE_NUMERIC_DOUBLE:
		case COB_TYPE_NUMERIC_L_DOUBLE:
		case COB_TYPE_NUMERIC_FP_BIN32:
		case COB_TYPE_NUMERIC_FP_BIN64:
		case COB_TYPE_NUMERIC_FP_BIN128:
		case COB_TYPE_NUMERIC_FP_DEC64:
		case COB_TYPE_NUMERIC_FP_DEC128:
			indirect_move (cob_move_alphanum_to_display, src, dst,
					(size_t)(2* COB_MAX_DIGITS),
					COB_MAX_DIGITS);
			return;
		case COB_TYPE_ALPHANUMERIC_EDITED:
			cob_move_alphanum_to_edited (src, dst);
			return;
		default:
			cob_move_alphanum_to_alphanum (src, dst);
			return;
		}
	}
}

/* Convenience functions */

static int
cob_packed_get_int (cob_field *f1)
{
	unsigned char	*data;
	size_t		i;
	size_t		offset;
	int		val = 0;
	int		sign;

	data = f1->data;
	if (COB_FIELD_NO_SIGN_NIBBLE (f1)) {
		sign = 0;
		offset = COB_FIELD_DIGITS(f1) % 2;
	} else {
		sign = cob_packed_get_sign (f1);
		offset = 1 - (COB_FIELD_DIGITS(f1) % 2);
	}
	for (i = offset; i < COB_FIELD_DIGITS(f1) - COB_FIELD_SCALE(f1) + offset; ++i) {
		val *= 10;
		if (i % 2 == 0) {
			val += data[i / 2] >> 4;
		} else {
			val += data[i / 2] & 0x0F;
		}
	}
	if (sign < 0) {
		val = -val;
	}
	return val;
}

static cob_s64_t
cob_packed_get_long_long (cob_field *f1)
{
	unsigned char	*data;
	size_t		i;
	size_t		offset;
	cob_s64_t	val = 0;
	int		sign;

	data = f1->data;
	if (COB_FIELD_NO_SIGN_NIBBLE (f1)) {
		sign = 0;
		offset = COB_FIELD_DIGITS(f1) % 2;
	} else {
		sign = cob_packed_get_sign (f1);
		offset = 1 - (COB_FIELD_DIGITS(f1) % 2);
	}
	for (i = offset; i < COB_FIELD_DIGITS(f1) - COB_FIELD_SCALE(f1) + offset; ++i) {
		val *= 10;
		if (i % 2 == 0) {
			val += data[i / 2] >> 4;
		} else {
			val += data[i / 2] & 0x0F;
		}
	}
	if (sign < 0) {
		val = -val;
	}
	return val;
}

static int
cob_display_get_int (cob_field *f)
{
	unsigned char	*data;
	size_t		size;
	size_t		i;
	int		val = 0;
	int		sign;

	size = COB_FIELD_SIZE (f);
	data = COB_FIELD_DATA (f);
	sign = COB_GET_SIGN (f);
	/* Skip preceding zeros */
	for (i = 0; i < size; ++i) {
		if (COB_D2I (data[i]) != 0) {
			break;
		}
	}

	/* Get value */
	if (COB_FIELD_SCALE(f) < 0) {
		for (; i < size; ++i) {
			val = val * 10 + COB_D2I (data[i]);
		}
		val *= cob_exp10[(int)-COB_FIELD_SCALE(f)];
	} else {
		size -= COB_FIELD_SCALE(f);
		for (; i < size; ++i) {
			val = val * 10 + COB_D2I (data[i]);
		}
	}
	if (sign < 0) {
		val = -val;
	}

	COB_PUT_SIGN (f, sign);
	return val;
}

static cob_s64_t
cob_display_get_long_long (cob_field *f)
{
	unsigned char	*data;
	size_t		size;
	size_t		i;
	cob_s64_t	val = 0;
	int		sign;

	size = COB_FIELD_SIZE (f);
	data = COB_FIELD_DATA (f);
	sign = COB_GET_SIGN (f);
	/* Skip preceding zeros */
	for (i = 0; i < size; ++i) {
		if (COB_D2I (data[i]) != 0) {
			break;
		}
	}

	/* Get value */
	if (COB_FIELD_SCALE(f) < 0) {
		for (; i < size; ++i) {
			val = val * 10 + COB_D2I (data[i]);
		}
		val *= cob_exp10_ll[(int)-COB_FIELD_SCALE(f)];
	} else {
		size -= COB_FIELD_SCALE(f);
		for (; i < size; ++i) {
			val = val * 10 + COB_D2I (data[i]);
		}
	}
	if (sign < 0) {
		val = -val;
	}

	COB_PUT_SIGN (f, sign);
	return val;
}

void
cob_set_int (cob_field *f, const int n)
{
	cob_field	temp;
	cob_field_attr	attr;

	COB_ATTR_INIT  (COB_TYPE_NUMERIC_BINARY, 9, 0,
			COB_FLAG_HAVE_SIGN | COB_FLAG_REAL_BINARY, NULL);
	temp.size = 4;
	temp.data = (unsigned char *)&n;
	temp.attr = &attr;
	cob_move (&temp, f);
}

int
cob_get_int (cob_field *f)
{
	int		n;
	cob_s64_t	val;
	cob_field	temp;
	cob_field_attr	attr;

	switch (COB_FIELD_TYPE (f)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		return cob_display_get_int (f);
	case COB_TYPE_NUMERIC_PACKED:
		return cob_packed_get_int (f);
	case COB_TYPE_NUMERIC_BINARY:
		val = cob_binary_mget_sint64 (f);
		for (n = COB_FIELD_SCALE (f); n > 0 && val; --n) {
			val /= 10;
		}
		return (int)val;
	default:
		COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9, 0,
				COB_FLAG_HAVE_SIGN, NULL);
		temp.size = 4;
		temp.data = (unsigned char *)&n;
		temp.attr = &attr;
		cob_move (f, &temp);
		return n;
	}
}

cob_s64_t
cob_get_llint (cob_field *f)
{
	cob_s64_t	n;
	int		inc;
	cob_field	temp;

	switch (COB_FIELD_TYPE (f)) {
	case COB_TYPE_NUMERIC_DISPLAY:
		return cob_display_get_long_long (f);
	case COB_TYPE_NUMERIC_PACKED:
		return cob_packed_get_long_long (f);
	case COB_TYPE_NUMERIC_BINARY:
		n = cob_binary_mget_sint64 (f);
		for (inc = COB_FIELD_SCALE (f); inc > 0 && n; --inc) {
			n /= 10;
		}
		return n;
	default:
		temp.size = 8;
		temp.data = (unsigned char *)&n;
		temp.attr = &const_binll_attr;
		cob_move (f, &temp);
		return n;
	}
}

void
cob_init_move (cob_global *lptr, runtime_env* runtimeptr)
{
#if	0	/* RXWRXW - Local edit sym */
#ifdef	HAVE_LOCALECONV
	struct lconv	*p;
	char		*s;
#endif
#endif

	cobglobptr = lptr;

#if	0	/* RXWRXW localeconv */
	cob_locale_edit = 0;
	cob_lc_dec = 0;
	cob_lc_thou = 0;
#ifdef	HAVE_LOCALECONV
	s = getenv ("COB_LOCALE_NUMERIC_EDITED");
	if (s && (*s == 'Y' || *s == 'y' || *s == '1')) {
		p = localeconv ();
		if (strlen (p->mon_decimal_point) != 1) {
			return;
		}
		if (strlen (p->mon_thousands_sep) != 1) {
			return;
		}
		cob_locale_edit = 1;
		runtimeptr->cob_local_edit = &cob_local_edit;
		cob_lc_dec = *((unsigned char *)(p->mon_decimal_point));
		cob_lc_thou = *((unsigned char *)(p->mon_thousands_sep));
	}
#else
	COB_UNUSED(runtimeptr);
#endif
#else
	COB_UNUSED(runtimeptr);
#endif
}
