/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
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

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#ifdef	HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef	_WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

#include "cobc.h"
#include "tree.h"

struct system_table {
	const char		*const syst_name;
	const int		syst_params;
};

struct optim_table {
	const char		*const optim_name;
	const enum cb_optim	optim_val;
};

struct expr_node {
	/* The token of this node.
	 *  'x'                          - values (cb_tree)
	 *  '+', '-', '*', '/', '^'      - arithmetic operators
	 *  '=', '~', '<', '>', '[', ']' - relational operators
	 *  '!', '&', '|'                - logical operators
	 *  '(', ')'                     - parentheses
	 */
	int		token;
	/* The value itself if this node is a value */
	cb_tree		value;
};

#define START_STACK_SIZE	32
#define TOKEN(offset)		(expr_stack[expr_index + offset].token)
#define VALUE(offset)		(expr_stack[expr_index + offset].value)

#define dpush(x)		CB_ADD_TO_CHAIN (x, decimal_stack)

#define cb_emit(x) \
	current_statement->body = cb_list_add (current_statement->body, x)
#define cb_emit_list(l) \
	current_statement->body = cb_list_append (current_statement->body, l)

/* Global variables */

cb_tree				cb_debug_item;
cb_tree				cb_debug_line;
cb_tree				cb_debug_name;
cb_tree				cb_debug_sub_1;
cb_tree				cb_debug_sub_2;
cb_tree				cb_debug_sub_3;
cb_tree				cb_debug_contents;

size_t				suppress_warn = 0;

/* Local variables */

static cb_tree			decimal_stack = NULL;

static const char		*inspect_func;
static cb_tree			inspect_data;

static int			expr_op;		/* Last operator */
static cb_tree			expr_lh;		/* Last left hand */

static size_t			initialized = 0;
static size_t			overlapping = 0;

static int			expr_index;		/* Stack index */
static int			expr_stack_size;	/* Stack max size */
static struct expr_node		*expr_stack;		/* Expression node stack */

static const unsigned char	hexval[] = "0123456789ABCDEF";

#ifdef	HAVE_DESIGNATED_INITS
static const unsigned char	expr_prio[256] = {
	['x'] = 0,
	['^'] = 1,
	['*'] = 2,
	['/'] = 2,
	['+'] = 3,
	['-'] = 3,
	['='] = 4,
	['~'] = 4,
	['<'] = 4,
	['>'] = 4,
	['['] = 4,
	[']'] = 4,
	['!'] = 5,
	['&'] = 6,
	['|'] = 7,
	[')'] = 8,
	['('] = 9,
	[0] = 10
};

static const unsigned char	valid_char[256] = {
	['0'] = 1,
	['1'] = 1,
	['2'] = 1,
	['3'] = 1,
	['4'] = 1,
	['5'] = 1,
	['6'] = 1,
	['7'] = 1,
	['8'] = 1,
	['9'] = 1,
	['A'] = 1,
	['B'] = 1,
	['C'] = 1,
	['D'] = 1,
	['E'] = 1,
	['F'] = 1,
	['G'] = 1,
	['H'] = 1,
	['I'] = 1,
	['J'] = 1,
	['K'] = 1,
	['L'] = 1,
	['M'] = 1,
	['N'] = 1,
	['O'] = 1,
	['P'] = 1,
	['Q'] = 1,
	['R'] = 1,
	['S'] = 1,
	['T'] = 1,
	['U'] = 1,
	['V'] = 1,
	['W'] = 1,
	['X'] = 1,
	['Y'] = 1,
	['Z'] = 1,
	['_'] = 1,
	['a'] = 1,
	['b'] = 1,
	['c'] = 1,
	['d'] = 1,
	['e'] = 1,
	['f'] = 1,
	['g'] = 1,
	['h'] = 1,
	['i'] = 1,
	['j'] = 1,
	['k'] = 1,
	['l'] = 1,
	['m'] = 1,
	['n'] = 1,
	['o'] = 1,
	['p'] = 1,
	['q'] = 1,
	['r'] = 1,
	['s'] = 1,
	['t'] = 1,
	['u'] = 1,
	['v'] = 1,
	['w'] = 1,
	['x'] = 1,
	['y'] = 1,
	['z'] = 1
};
#else
static unsigned char		expr_prio[256];
static unsigned char		valid_char[256];
static const unsigned char	pvalid_char[] =
	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
#endif

/* EBCDIC referring to ASCII */
static const unsigned char	cob_refer_ascii[256] = {
	0x00, 0x01, 0x02, 0x03, 0x37, 0x2D, 0x2E, 0x2F,
	0x16, 0x05, 0x25, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x3C, 0x3D, 0x32, 0x26,
	0x18, 0x19, 0x3F, 0x27, 0x1C, 0x1D, 0x1E, 0x1F,
	0x40, 0x5A, 0x7F, 0x7B, 0x5B, 0x6C, 0x50, 0x7D,
	0x4D, 0x5D, 0x5C, 0x4E, 0x6B, 0x60, 0x4B, 0x61,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7,
	0xF8, 0xF9, 0x7A, 0x5E, 0x4C, 0x7E, 0x6E, 0x6F,
	0x7C, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7,
	0xC8, 0xC9, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6,
	0xD7, 0xD8, 0xD9, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6,
	0xE7, 0xE8, 0xE9, 0xAD, 0xE0, 0xBD, 0x5F, 0x6D,
	0x79, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
	0x88, 0x89, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96,
	0x97, 0x98, 0x99, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6,
	0xA7, 0xA8, 0xA9, 0xC0, 0x6A, 0xD0, 0xA1, 0x07,
	0x68, 0xDC, 0x51, 0x42, 0x43, 0x44, 0x47, 0x48,
	0x52, 0x53, 0x54, 0x57, 0x56, 0x58, 0x63, 0x67,
	0x71, 0x9C, 0x9E, 0xCB, 0xCC, 0xCD, 0xDB, 0xDD,
	0xDF, 0xEC, 0xFC, 0xB0, 0xB1, 0xB2, 0x3E, 0xB4,
	0x45, 0x55, 0xCE, 0xDE, 0x49, 0x69, 0x9A, 0x9B,
	0xAB, 0x9F, 0xBA, 0xB8, 0xB7, 0xAA, 0x8A, 0x8B,
	0xB6, 0xB5, 0x62, 0x4F, 0x64, 0x65, 0x66, 0x20,
	0x21, 0x22, 0x70, 0x23, 0x72, 0x73, 0x74, 0xBE,
	0x76, 0x77, 0x78, 0x80, 0x24, 0x15, 0x8C, 0x8D,
	0x8E, 0x41, 0x06, 0x17, 0x28, 0x29, 0x9D, 0x2A,
	0x2B, 0x2C, 0x09, 0x0A, 0xAC, 0x4A, 0xAE, 0xAF,
	0x1B, 0x30, 0x31, 0xFA, 0x1A, 0x33, 0x34, 0x35,
	0x36, 0x59, 0x08, 0x38, 0xBC, 0x39, 0xA0, 0xBF,
	0xCA, 0x3A, 0xFE, 0x3B, 0x04, 0xCF, 0xDA, 0x14,
	0xE1, 0x8F, 0x46, 0x75, 0xFD, 0xEB, 0xEE, 0xED,
	0x90, 0xEF, 0xB3, 0xFB, 0xB9, 0xEA, 0xBB, 0xFF
};

/* ASCII referring to EBCDIC */
static const unsigned char	cob_refer_ebcdic[256] = {
	0x00, 0x01, 0x02, 0x03, 0xEC, 0x09, 0xCA, 0x7F,
	0xE2, 0xD2, 0xD3, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0xEF, 0xC5, 0x08, 0xCB,
	0x18, 0x19, 0xDC, 0xD8, 0x1C, 0x1D, 0x1E, 0x1F,
	0xB7, 0xB8, 0xB9, 0xBB, 0xC4, 0x0A, 0x17, 0x1B,
	0xCC, 0xCD, 0xCF, 0xD0, 0xD1, 0x05, 0x06, 0x07,
	0xD9, 0xDA, 0x16, 0xDD, 0xDE, 0xDF, 0xE0, 0x04,
	0xE3, 0xE5, 0xE9, 0xEB, 0x14, 0x15, 0x9E, 0x1A,
	0x20, 0xC9, 0x83, 0x84, 0x85, 0xA0, 0xF2, 0x86,
	0x87, 0xA4, 0xD5, 0x2E, 0x3C, 0x28, 0x2B, 0xB3,
	0x26, 0x82, 0x88, 0x89, 0x8A, 0xA1, 0x8C, 0x8B,
	0x8D, 0xE1, 0x21, 0x24, 0x2A, 0x29, 0x3B, 0x5E,
	0x2D, 0x2F, 0xB2, 0x8E, 0xB4, 0xB5, 0xB6, 0x8F,
	0x80, 0xA5, 0x7C, 0x2C, 0x25, 0x5F, 0x3E, 0x3F,
	0xBA, 0x90, 0xBC, 0xBD, 0xBE, 0xF3, 0xC0, 0xC1,
	0xC2, 0x60, 0x3A, 0x23, 0x40, 0x27, 0x3D, 0x22,
	0xC3, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
	0x68, 0x69, 0xAE, 0xAF, 0xC6, 0xC7, 0xC8, 0xF1,
	0xF8, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,
	0x71, 0x72, 0xA6, 0xA7, 0x91, 0xCE, 0x92, 0xA9,
	0xE6, 0x7E, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
	0x79, 0x7A, 0xAD, 0xA8, 0xD4, 0x5B, 0xD6, 0xD7,
	0x9B, 0x9C, 0x9D, 0xFA, 0x9F, 0xB1, 0xB0, 0xAC,
	0xAB, 0xFC, 0xAA, 0xFE, 0xE4, 0x5D, 0xBF, 0xE7,
	0x7B, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
	0x48, 0x49, 0xE8, 0x93, 0x94, 0x95, 0xA2, 0xED,
	0x7D, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
	0x51, 0x52, 0xEE, 0x96, 0x81, 0x97, 0xA3, 0x98,
	0x5C, 0xF0, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	0x59, 0x5A, 0xFD, 0xF5, 0x99, 0xF7, 0xF6, 0xF9,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
	0x38, 0x39, 0xDB, 0xFB, 0x9A, 0xF4, 0xEA, 0xFF
};

/* System routines */

#undef	COB_SYSTEM_GEN
#define	COB_SYSTEM_GEN(x, y, z)	{ x, y },

static const struct system_table	system_tab[] = {
#include "libcob/system.def"
	{ NULL, 0 }
};

#undef	COB_SYSTEM_GEN

static const struct optim_table	bin_set_funcs[] = {
	{ NULL,			COB_OPTIM_MIN },
	{ "cob_setswp_u16",	COB_SETSWP_U16 },
	{ "cob_setswp_u24",	COB_SETSWP_U24 },
	{ "cob_setswp_u32",	COB_SETSWP_U32 },
	{ "cob_setswp_u40",	COB_SETSWP_U40 },
	{ "cob_setswp_u48",	COB_SETSWP_U48 },
	{ "cob_setswp_u56",	COB_SETSWP_U56 },
	{ "cob_setswp_u64",	COB_SETSWP_U64 },
	{ NULL,			COB_OPTIM_MIN },
	{ "cob_setswp_s16",	COB_SETSWP_S16 },
	{ "cob_setswp_s24",	COB_SETSWP_S24 },
	{ "cob_setswp_s32",	COB_SETSWP_S32 },
	{ "cob_setswp_s40",	COB_SETSWP_S40 },
	{ "cob_setswp_s48",	COB_SETSWP_S48 },
	{ "cob_setswp_s56",	COB_SETSWP_S56 },
	{ "cob_setswp_s64",	COB_SETSWP_S64 }
};

static const struct optim_table	bin_compare_funcs[] = {
	{ "cob_cmp_u8",		COB_CMP_U8 },
	{ "cob_cmp_u16",	COB_CMP_U16 },
	{ "cob_cmp_u24",	COB_CMP_U24 },
	{ "cob_cmp_u32",	COB_CMP_U32 },
	{ "cob_cmp_u40",	COB_CMP_U40 },
	{ "cob_cmp_u48",	COB_CMP_U48 },
	{ "cob_cmp_u56",	COB_CMP_U56 },
	{ "cob_cmp_u64",	COB_CMP_U64 },
	{ "cob_cmp_s8",		COB_CMP_S8 },
	{ "cob_cmp_s16",	COB_CMP_S16 },
	{ "cob_cmp_s24",	COB_CMP_S24 },
	{ "cob_cmp_s32",	COB_CMP_S32 },
	{ "cob_cmp_s40",	COB_CMP_S40 },
	{ "cob_cmp_s48",	COB_CMP_S48 },
	{ "cob_cmp_s56",	COB_CMP_S56 },
	{ "cob_cmp_s64",	COB_CMP_S64 },
	{ "cob_cmp_u8",		COB_CMP_U8 },
	{ "cob_cmpswp_u16",	COB_CMPSWP_U16 },
	{ "cob_cmpswp_u24",	COB_CMPSWP_U24 },
	{ "cob_cmpswp_u32",	COB_CMPSWP_U32 },
	{ "cob_cmpswp_u40",	COB_CMPSWP_U40 },
	{ "cob_cmpswp_u48",	COB_CMPSWP_U48 },
	{ "cob_cmpswp_u56",	COB_CMPSWP_U56 },
	{ "cob_cmpswp_u64",	COB_CMPSWP_U64 },
	{ "cob_cmp_s8",		COB_CMP_S8 },
	{ "cob_cmpswp_s16",	COB_CMPSWP_S16 },
	{ "cob_cmpswp_s24",	COB_CMPSWP_S24 },
	{ "cob_cmpswp_s32",	COB_CMPSWP_S32 },
	{ "cob_cmpswp_s40",	COB_CMPSWP_S40 },
	{ "cob_cmpswp_s48",	COB_CMPSWP_S48 },
	{ "cob_cmpswp_s56",	COB_CMPSWP_S56 },
	{ "cob_cmpswp_s64",	COB_CMPSWP_S64 }
};

static const struct optim_table	bin_add_funcs[] = {
	{ "cob_add_u8",		COB_ADD_U8 },
	{ "cob_add_u16",	COB_ADD_U16 },
	{ "cob_add_u24",	COB_ADD_U24 },
	{ "cob_add_u32",	COB_ADD_U32 },
	{ "cob_add_u40",	COB_ADD_U40 },
	{ "cob_add_u48",	COB_ADD_U48 },
	{ "cob_add_u56",	COB_ADD_U56 },
	{ "cob_add_u64",	COB_ADD_U64 },
	{ "cob_add_s8",		COB_ADD_S8 },
	{ "cob_add_s16",	COB_ADD_S16 },
	{ "cob_add_s24",	COB_ADD_S24 },
	{ "cob_add_s32",	COB_ADD_S32 },
	{ "cob_add_s40",	COB_ADD_S40 },
	{ "cob_add_s48",	COB_ADD_S48 },
	{ "cob_add_s56",	COB_ADD_S56 },
	{ "cob_add_s64",	COB_ADD_S64 },
	{ "cob_add_u8",		COB_ADD_U8 },
	{ "cob_addswp_u16",	COB_ADDSWP_U16 },
	{ "cob_addswp_u24",	COB_ADDSWP_U24 },
	{ "cob_addswp_u32",	COB_ADDSWP_U32 },
	{ "cob_addswp_u40",	COB_ADDSWP_U40 },
	{ "cob_addswp_u48",	COB_ADDSWP_U48 },
	{ "cob_addswp_u56",	COB_ADDSWP_U56 },
	{ "cob_addswp_u64",	COB_ADDSWP_U64 },
	{ "cob_add_s8",		COB_ADD_S8 },
	{ "cob_addswp_s16",	COB_ADDSWP_S16 },
	{ "cob_addswp_s24",	COB_ADDSWP_S24 },
	{ "cob_addswp_s32",	COB_ADDSWP_S32 },
	{ "cob_addswp_s40",	COB_ADDSWP_S40 },
	{ "cob_addswp_s48",	COB_ADDSWP_S48 },
	{ "cob_addswp_s56",	COB_ADDSWP_S56 },
	{ "cob_addswp_s64",	COB_ADDSWP_S64 }
};

static const struct optim_table	bin_sub_funcs[] = {
	{ "cob_sub_u8",		COB_SUB_U8 },
	{ "cob_sub_u16",	COB_SUB_U16 },
	{ "cob_sub_u24",	COB_SUB_U24 },
	{ "cob_sub_u32",	COB_SUB_U32 },
	{ "cob_sub_u40",	COB_SUB_U40 },
	{ "cob_sub_u48",	COB_SUB_U48 },
	{ "cob_sub_u56",	COB_SUB_U56 },
	{ "cob_sub_u64",	COB_SUB_U64 },
	{ "cob_sub_s8",		COB_SUB_S8 },
	{ "cob_sub_s16",	COB_SUB_S16 },
	{ "cob_sub_s24",	COB_SUB_S24 },
	{ "cob_sub_s32",	COB_SUB_S32 },
	{ "cob_sub_s40",	COB_SUB_S40 },
	{ "cob_sub_s48",	COB_SUB_S48 },
	{ "cob_sub_s56",	COB_SUB_S56 },
	{ "cob_sub_s64",	COB_SUB_S64 },
	{ "cob_sub_u8",		COB_SUB_U8 },
	{ "cob_subswp_u16",	COB_SUBSWP_U16 },
	{ "cob_subswp_u24",	COB_SUBSWP_U24 },
	{ "cob_subswp_u32",	COB_SUBSWP_U32 },
	{ "cob_subswp_u40",	COB_SUBSWP_U40 },
	{ "cob_subswp_u48",	COB_SUBSWP_U48 },
	{ "cob_subswp_u56",	COB_SUBSWP_U56 },
	{ "cob_subswp_u64",	COB_SUBSWP_U64 },
	{ "cob_sub_s8",		COB_SUB_S8 },
	{ "cob_subswp_s16",	COB_SUBSWP_S16 },
	{ "cob_subswp_s24",	COB_SUBSWP_S24 },
	{ "cob_subswp_s32",	COB_SUBSWP_S32 },
	{ "cob_subswp_s40",	COB_SUBSWP_S40 },
	{ "cob_subswp_s48",	COB_SUBSWP_S48 },
	{ "cob_subswp_s56",	COB_SUBSWP_S56 },
	{ "cob_subswp_s64",	COB_SUBSWP_S64 }
};

#if	defined(COB_NON_ALIGNED) && !defined(_MSC_VER)
static const struct optim_table	align_bin_compare_funcs[] = {
	{ "cob_cmp_u8",			COB_CMP_U8 },
	{ "cob_cmp_align_u16",		COB_CMP_ALIGN_U16 },
	{ "cob_cmp_u24",		COB_CMP_U24 },
	{ "cob_cmp_align_u32",		COB_CMP_ALIGN_U32 },
	{ "cob_cmp_u40",		COB_CMP_U40 },
	{ "cob_cmp_u48",		COB_CMP_U48 },
	{ "cob_cmp_u56",		COB_CMP_U56 },
	{ "cob_cmp_align_u64",		COB_CMP_ALIGN_U64 },
	{ "cob_cmp_s8",			COB_CMP_S8 },
	{ "cob_cmp_align_s16",		COB_CMP_ALIGN_S16 },
	{ "cob_cmp_s24",		COB_CMP_S24 },
	{ "cob_cmp_align_s32",		COB_CMP_ALIGN_S32 },
	{ "cob_cmp_s40",		COB_CMP_S40 },
	{ "cob_cmp_s48",		COB_CMP_S48 },
	{ "cob_cmp_s56",		COB_CMP_S56 },
	{ "cob_cmp_align_s64",		COB_CMP_ALIGN_S64 },
	{ "cob_cmp_u8",			COB_CMP_U8 },
	{ "cob_cmpswp_align_u16",	COB_CMPSWP_ALIGN_U16 },
	{ "cob_cmpswp_u24",		COB_CMPSWP_U24 },
	{ "cob_cmpswp_align_u32",	COB_CMPSWP_ALIGN_U32 },
	{ "cob_cmpswp_u40",		COB_CMPSWP_U40 },
	{ "cob_cmpswp_u48",		COB_CMPSWP_U48 },
	{ "cob_cmpswp_u56",		COB_CMPSWP_U56 },
	{ "cob_cmpswp_align_u64",	COB_CMPSWP_ALIGN_U64 },
	{ "cob_cmp_s8",			COB_CMP_S8 },
	{ "cob_cmpswp_align_s16",	COB_CMPSWP_ALIGN_S16 },
	{ "cob_cmpswp_s24",		COB_CMPSWP_S24 },
	{ "cob_cmpswp_align_s32",	COB_CMPSWP_ALIGN_S32 },
	{ "cob_cmpswp_s40",		COB_CMPSWP_S40 },
	{ "cob_cmpswp_s48",		COB_CMPSWP_S48 },
	{ "cob_cmpswp_s56",		COB_CMPSWP_S56 },
	{ "cob_cmpswp_align_s64",	COB_CMPSWP_ALIGN_S64 },
};

static const struct optim_table	align_bin_add_funcs[] = {
	{ "cob_add_u8",		COB_ADD_U8 },
	{ "cob_add_align_u16",	COB_ADD_ALIGN_U16 },
	{ "cob_add_u24",	COB_ADD_U24 },
	{ "cob_add_align_u32",	COB_ADD_ALIGN_U32 },
	{ "cob_add_u40",	COB_ADD_U40 },
	{ "cob_add_u48",	COB_ADD_U48 },
	{ "cob_add_u56",	COB_ADD_U56 },
	{ "cob_add_align_u64",	COB_ADD_ALIGN_U64 },
	{ "cob_add_s8",		COB_ADD_S8 },
	{ "cob_add_align_s16",	COB_ADD_ALIGN_S16 },
	{ "cob_add_s24",	COB_ADD_S24 },
	{ "cob_add_align_s32",	COB_ADD_ALIGN_S32 },
	{ "cob_add_s40",	COB_ADD_S40 },
	{ "cob_add_s48",	COB_ADD_S48 },
	{ "cob_add_s56",	COB_ADD_S56 },
	{ "cob_add_align_s64",	COB_ADD_ALIGN_S64 },
	{ "cob_add_u8",		COB_ADD_U8 },
	{ "cob_addswp_u16",	COB_ADDSWP_U16 },
	{ "cob_addswp_u24",	COB_ADDSWP_U24 },
	{ "cob_addswp_u32",	COB_ADDSWP_U32 },
	{ "cob_addswp_u40",	COB_ADDSWP_U40 },
	{ "cob_addswp_u48",	COB_ADDSWP_U48 },
	{ "cob_addswp_u56",	COB_ADDSWP_U56 },
	{ "cob_addswp_u64",	COB_ADDSWP_U64 },
	{ "cob_add_s8",		COB_ADD_S8 },
	{ "cob_addswp_s16",	COB_ADDSWP_S16 },
	{ "cob_addswp_s24",	COB_ADDSWP_S24 },
	{ "cob_addswp_s32",	COB_ADDSWP_S32 },
	{ "cob_addswp_s40",	COB_ADDSWP_S40 },
	{ "cob_addswp_s48",	COB_ADDSWP_S48 },
	{ "cob_addswp_s56",	COB_ADDSWP_S56 },
	{ "cob_addswp_s64",	COB_ADDSWP_S64 },
};

static const struct optim_table	align_bin_sub_funcs[] = {
	{ "cob_sub_u8",		COB_SUB_U8 },
	{ "cob_sub_align_u16",	COB_SUB_ALIGN_U16 },
	{ "cob_sub_u24",	COB_SUB_U24 },
	{ "cob_sub_align_u32",	COB_SUB_ALIGN_U32 },
	{ "cob_sub_u40",	COB_SUB_U40 },
	{ "cob_sub_u48",	COB_SUB_U48 },
	{ "cob_sub_u56",	COB_SUB_U56 },
	{ "cob_sub_align_u64",	COB_SUB_ALIGN_U64 },
	{ "cob_sub_s8",		COB_SUB_S8 },
	{ "cob_sub_align_s16",	COB_SUB_ALIGN_S16 },
	{ "cob_sub_s24",	COB_SUB_S24 },
	{ "cob_sub_align_s32",	COB_SUB_ALIGN_S32 },
	{ "cob_sub_s40",	COB_SUB_S40 },
	{ "cob_sub_s48",	COB_SUB_S48 },
	{ "cob_sub_s56",	COB_SUB_S56 },
	{ "cob_sub_align_s64",	COB_SUB_ALIGN_S64 },
	{ "cob_sub_u8",		COB_SUB_U8 },
	{ "cob_subswp_u16",	COB_SUBSWP_U16 },
	{ "cob_subswp_u24",	COB_SUBSWP_U24 },
	{ "cob_subswp_u32",	COB_SUBSWP_U32 },
	{ "cob_subswp_u40",	COB_SUBSWP_U40 },
	{ "cob_subswp_u48",	COB_SUBSWP_U48 },
	{ "cob_subswp_u56",	COB_SUBSWP_U56 },
	{ "cob_subswp_u64",	COB_SUBSWP_U64 },
	{ "cob_sub_s8",		COB_SUB_S8 },
	{ "cob_subswp_s16",	COB_SUBSWP_S16 },
	{ "cob_subswp_s24",	COB_SUBSWP_S24 },
	{ "cob_subswp_s32",	COB_SUBSWP_S32 },
	{ "cob_subswp_s40",	COB_SUBSWP_S40 },
	{ "cob_subswp_s48",	COB_SUBSWP_S48 },
	{ "cob_subswp_s56",	COB_SUBSWP_S56 },
	{ "cob_subswp_s64",	COB_SUBSWP_S64 },
};
#endif

/* Functions */

static cb_tree
cb_check_needs_break (cb_tree stmt)
{
	cb_tree		l;

	/* Check if last statement is GO TO */
	for (l = stmt; l; l = CB_CHAIN (l)) {
		if (!CB_CHAIN(l)) {
			break;
		}
	}
	if (l && CB_VALUE (l) && CB_STATEMENT_P (CB_VALUE (l))) {
		l = CB_STATEMENT(CB_VALUE(l))->body;
		if (l && CB_VALUE (l) && !CB_GOTO_P (CB_VALUE(l))) {
			/* Append a break */
			l = cb_build_direct ("break;", 0);
			return cb_list_add (stmt, l);
		}
	}
	return stmt;
}

static size_t
cb_validate_one (cb_tree x)
{
	cb_tree		y;

	if (x == cb_error_node) {
		return 1;
	}
	if (!x) {
		return 0;
	}
	if (CB_REFERENCE_P (x)) {
		y = cb_ref (x);
		if (y == cb_error_node) {
			return 1;
		}
		if (CB_FIELD_P (y)) {
			if (CB_FIELD (y)->level == 88) {
				cb_error_x (x, _("Invalid use of 88 level item"));
				return 1;
			}
			if (CB_FIELD (y)->flag_invalid) {
				return 1;
			}
		}
	}
	return 0;
}

static size_t
cb_validate_list (cb_tree l)
{
	for (; l; l = CB_CHAIN (l)) {
		if (cb_validate_one (CB_VALUE (l))) {
			return 1;
		}
	}
	return 0;
}

static cb_tree
cb_check_group_name (cb_tree x)
{
	cb_tree		y;

	if (x == cb_error_node) {
		return cb_error_node;
	}

	if (CB_REFERENCE_P (x)) {
		y = cb_ref (x);
		if (y == cb_error_node) {
			return cb_error_node;
		}
		if (CB_FIELD_P (y) && CB_FIELD (y)->children != NULL &&
		    CB_REFERENCE (x)->offset == NULL) {
			return x;
		}
	}

	cb_error_x (x, _("'%s' is not group name"), cb_name (x));
	return cb_error_node;
}

static cb_tree
cb_check_numeric_name (cb_tree x)
{
	if (x == cb_error_node) {
		return cb_error_node;
	}

	if (CB_REFERENCE_P (x) &&
	    CB_FIELD_P (cb_ref (x)) &&
	    CB_TREE_CATEGORY (x) == CB_CATEGORY_NUMERIC) {
		return x;
	}

	cb_error_x (x, _("'%s' is not a numeric name"), cb_name (x));
	return cb_error_node;
}

static cb_tree
cb_check_numeric_edited_name (cb_tree x)
{
	if (x == cb_error_node) {
		return cb_error_node;
	}

	if (CB_REFERENCE_P (x) &&
	    CB_FIELD_P (cb_ref (x)) &&
	    (CB_TREE_CATEGORY (x) == CB_CATEGORY_NUMERIC ||
	     CB_TREE_CATEGORY (x) == CB_CATEGORY_NUMERIC_EDITED)) {
		return x;
	}

	cb_error_x (x, _("'%s' is not numeric or numeric-edited name"), cb_name (x));
	return cb_error_node;
}

cb_tree
cb_check_numeric_value (cb_tree x)
{
	if (x == cb_error_node) {
		return cb_error_node;
	}

	if (CB_TREE_CATEGORY (x) == CB_CATEGORY_NUMERIC) {
		return x;
	}

	cb_error_x (x, _("'%s' is not a numeric value"), cb_name (x));
	return cb_error_node;
}

static cb_tree
cb_check_integer_value (cb_tree x)
{
	struct cb_literal	*l;
	struct cb_field		*f;
	cb_tree			y;

	if (x == cb_error_node) {
		return cb_error_node;
	}

	if (CB_TREE_CATEGORY (x) != CB_CATEGORY_NUMERIC) {
		goto invalid;
	}

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x != cb_zero) {
			goto invalid;
		}
		return x;
	case CB_TAG_LITERAL:
		l = CB_LITERAL (x);
		if (l->sign < 0 || l->scale > 0) {
			goto invliteral;
		}
		return x;
	case CB_TAG_REFERENCE:
		y = cb_ref (x);
		if (y == cb_error_node) {
			return cb_error_node;
		}
		f = CB_FIELD (y);
		if (f->pic->scale > 0) {
			goto invalid;
		}
		return x;
	case CB_TAG_BINARY_OP:
		/* TODO: need to check */
		return x;
	case CB_TAG_INTRINSIC:
		/* TODO: need to check */
		return x;
	default:
invalid:
		cb_error_x (x, _("'%s' is not an integer value"), cb_name (x));
		return cb_error_node;
	}
invliteral:
	cb_error_x (x, _("A positive numeric integer is required here"));
	return cb_error_node;
}

static void
cb_check_data_incompat (cb_tree x)
{
	struct cb_field		*f;

	if (!x || x == cb_error_node) {
		return;
	}
	if (!CB_REF_OR_FIELD_P (x) ||
	    CB_TREE_CATEGORY (x) != CB_CATEGORY_NUMERIC) {
		return;
	}
	f = CB_FIELD_PTR (x);
	if (cb_flag_correct_numeric && f->usage == CB_USAGE_DISPLAY) {
		cb_emit (CB_BUILD_FUNCALL_1 ("cob_correct_numeric", x));
	}
	if (CB_EXCEPTION_ENABLE (COB_EC_DATA_INCOMPATIBLE)) {
		if (f->usage == CB_USAGE_DISPLAY ||
		    f->usage == CB_USAGE_PACKED ||
		    f->usage == CB_USAGE_COMP_6) {
			cb_emit (CB_BUILD_FUNCALL_2 ("cob_check_numeric",
					x,
					CB_BUILD_STRING0 (f->name)));
		}
	}
}

static void
cb_check_lit_subs (struct cb_reference *r, const int numsubs,
		   const int numindex)
{
	cb_tree			l;
	cb_tree			v;
	struct cb_literal	*lt;
	int			size;

	/* Check for DPC and non-standard separator usage */
	if (!cb_relaxed_syntax_check ||
	    current_program->decimal_point != ',') {
		return;
	}
	if (numsubs > numindex) {
		return;
	}

	for (l = r->subs; l; l = CB_CHAIN (l)) {
		v = CB_VALUE (l);
		if (v == cb_error_node) {
			continue;
		}
		if (!CB_LITERAL_P (v)) {
			continue;
		}
		lt = CB_LITERAL (v);
		if (!lt->scale) {
			continue;
		}
		if (lt->scale == (int)lt->size) {
			lt->scale = 0;
			continue;
		}
		size = lt->size - lt->scale;
		v = cb_build_numsize_literal (&lt->data[size],
					      (size_t)lt->scale, lt->sign);
		CB_VALUE (l) = v;
		v = cb_build_numsize_literal (lt->data, (size_t)size, 0);
		CB_CHAIN (l) = CB_BUILD_CHAIN (v, CB_CHAIN (l));
	}
	return;
}



/* List system routines */

void
cb_list_system (void)
{
	const struct system_table	*psyst;
	const char			*s;
	size_t				n;

	putchar ('\n');
	printf (_("System routine\t\t\tParameters"));
	puts ("\n");
	for (psyst = system_tab; psyst->syst_name; psyst++) {
		switch (*(unsigned char *)(psyst->syst_name)) {
		case 'C':
		case 'S':
			printf ("%s", psyst->syst_name);
			break;
		case 0xF4:
			printf ("X\"F4\"");
			break;
		case 0xF5:
			printf ("X\"F5\"");
			break;
		case 0x91:
			printf ("X\"91\"");
			break;
		case 0xE4:
			printf ("X\"E4\"");
			break;
		case 0xE5:
			printf ("X\"E5\"");
			break;
		default:
			break;
		}
		n = strlen (psyst->syst_name);
		switch (n / 8) {
		case 0:
			s = "\t\t\t\t";
			break;
		case 1:
			s = "\t\t\t";
			break;
		case 2:
			s = "\t\t";
			break;
		default:
			s = "\t";
			break;
		}
		printf ("%s%d\n", s, psyst->syst_params);
	}
}

/* Check if tree is an INDEX */
size_t
cb_check_index_p (cb_tree x)
{
	struct cb_field	*f;

	if (!CB_REF_OR_FIELD_P (x)) {
		return 0;
	}
	f = CB_FIELD_PTR (x);
	if (f->usage == CB_USAGE_INDEX && !f->children) {
		return 1;
	}
	return 0;
}

/* Check if a field reference requires debugging */

void
cb_check_field_debug (cb_tree fld)
{
	cb_tree		l;
	cb_tree		x;
	cb_tree		z;
	size_t		size;
	size_t		found;
	char		buff[COB_MINI_BUFF];

	/* Basic reference check */
	if (CB_WORD_COUNT (fld) > 0) {
		if (!CB_WORD_ITEMS (fld)) {
			return;
		}
		z = CB_VALUE(CB_WORD_ITEMS (fld));
		if (!CB_FIELD_P (z)) {
			return;
		}
		x = cb_ref (fld);
		if (x == cb_error_node) {
			return;
		}
	} else {
		return;
	}

	found = 0;
	/* Check if reference is being debugged */
	for (l = current_program->debug_list; l; l = CB_CHAIN (l)) {
		if (!CB_PURPOSE (l)) {
			continue;
		}
		if (x == CB_PURPOSE (l)) {
			if (CB_REFERENCE (fld)->flag_target ||
			    CB_REFERENCE (CB_VALUE (l))->flag_all_debug) {
				found = 1;
			}
			break;
		}
	}
	if (!found) {
		return;
	}

	found = 0;
	/* Found it - check if it is already in the statement list */
	for (l = current_statement->debug_nodups; l; l = CB_CHAIN (l)) {
		if (CB_VALUE (l) == x) {
			found = 1;
			break;
		}
	}
	if (found) {
		return;
	}

	/* Set up debug info */
	strcpy (buff, CB_FIELD(x)->name);
	size = strlen (buff);
	for (l = CB_REFERENCE (fld)->chain; l; l = CB_REFERENCE (l)->chain) {
		z = cb_ref (l);
		if (z != cb_error_node) {
			size += strlen (CB_FIELD (z)->name);
			size += 4;
			if (size >= sizeof(buff)) {
				break;
			}
			strcat (buff, " OF ");
			strcat (buff, CB_FIELD (z)->name);
		}
	}
	current_statement->debug_nodups =
		cb_list_add (current_statement->debug_nodups, x);
	current_statement->debug_check =
		cb_list_add (current_statement->debug_check,
			     cb_build_debug (cb_debug_name, buff, NULL));
	current_statement->debug_check =
		cb_list_add (current_statement->debug_check,
			     cb_build_debug (cb_debug_contents, NULL, fld));
	found = 0;
	CB_REFERENCE (fld)->subs = cb_list_reverse (CB_REFERENCE (fld)->subs);
	l = CB_REFERENCE (fld)->subs;
	for (; l && found < 3; l = CB_CHAIN (l), ++found) {
		switch (found) {
		case 0:
			current_statement->debug_check =
				cb_list_add (current_statement->debug_check,
					     cb_build_move (CB_VALUE (l),
							    cb_debug_sub_1));
			break;
		case 1:
			current_statement->debug_check =
				cb_list_add (current_statement->debug_check,
					     cb_build_move (CB_VALUE (l),
							    cb_debug_sub_2));
			break;
		case 2:
			current_statement->debug_check =
				cb_list_add (current_statement->debug_check,
					     cb_build_move (CB_VALUE (l),
							    cb_debug_sub_3));
			break;
		default:
			break;
		}
	}
	CB_REFERENCE (fld)->subs = cb_list_reverse (CB_REFERENCE (fld)->subs);

	for (; found < 3; ++found) {
		switch (found) {
		case 0:
			current_statement->debug_check =
				cb_list_add (current_statement->debug_check,
					     CB_BUILD_FUNCALL_3 ("memset",
						CB_BUILD_CAST_ADDRESS (cb_debug_sub_1),
						cb_int (' '),
						CB_BUILD_CAST_LENGTH (cb_debug_sub_1)));
			break;
		case 1:
			current_statement->debug_check =
				cb_list_add (current_statement->debug_check,
					     CB_BUILD_FUNCALL_3 ("memset",
						CB_BUILD_CAST_ADDRESS (cb_debug_sub_2),
						cb_int (' '),
						CB_BUILD_CAST_LENGTH (cb_debug_sub_2)));
			break;
		case 2:
			current_statement->debug_check =
				cb_list_add (current_statement->debug_check,
					     CB_BUILD_FUNCALL_3 ("memset",
						CB_BUILD_CAST_ADDRESS (cb_debug_sub_3),
						cb_int (' '),
						CB_BUILD_CAST_LENGTH (cb_debug_sub_3)));
			break;
		default:
			break;
		}
	}

	current_statement->debug_check =
		cb_list_add (current_statement->debug_check,
			     cb_build_debug_call (CB_FIELD(x)->debug_section));
}

/* Program registers */

void
cb_build_registers (void)
{
#if !defined(__linux__) && !defined(__CYGWIN__) && defined(HAVE_TIMEZONE)
	long	contz;
#endif
	cb_tree		x;
	struct tm	*tlt;
	time_t		t;
	char		buff[48];

	/* RETURN-CODE */
	if (!current_program->nested_level) {
		x = cb_build_index (cb_build_reference ("RETURN-CODE"),
				    cb_zero, 0, NULL);
		CB_FIELD_PTR (x)->special_index = 1;
		current_program->cb_return_code = x;
	}

	/* SORT-RETURN */
	x = cb_build_index (cb_build_reference ("SORT-RETURN"),
			    cb_zero, 0, NULL);
	CB_FIELD_PTR (x)->flag_no_init = 1;
	current_program->cb_sort_return = x;

	/* NUMBER-OF-CALL-PARAMETERS */
	x = cb_build_index (cb_build_reference ("NUMBER-OF-CALL-PARAMETERS"),
			    cb_zero, 0, NULL);
	CB_FIELD_PTR (x)->flag_no_init = 1;
	CB_FIELD_PTR (x)->flag_local = 1;
	CB_FIELD_PTR (x)->special_index = 2;
	current_program->cb_call_params = x;

	t = time (NULL);
	tlt = localtime (&t);
	/* Leap seconds ? */
	if (tlt->tm_sec >= 60) {
		tlt->tm_sec = 59;
	}

	/* WHEN-COMPILED */
	memset (buff, 0, sizeof (buff));
	strftime (buff, (size_t)17, "%m/%d/%y%H.%M.%S", tlt);
	cb_build_constant (cb_build_reference ("WHEN-COMPILED"),
			   cb_build_alphanumeric_literal (buff, (size_t)16));

	/* FUNCTION WHEN-COMPILED */
	memset (buff, 0, sizeof (buff));
#if defined(__linux__) || defined(__CYGWIN__)
	strftime (buff, (size_t)22, "%Y%m%d%H%M%S00%z", tlt);
#elif defined(HAVE_TIMEZONE)
	strftime (buff, (size_t)17, "%Y%m%d%H%M%S00", tlt);
	if (timezone <= 0) {
		contz = -timezone;
		buff[16] = '+';
	} else {
		contz = timezone;
		buff[16] = '-';
	}
	sprintf (&buff[17], "%2.2ld%2.2ld", contz / 3600, contz % 60);
#else
	strftime (buff, (size_t)22, "%Y%m%d%H%M%S0000000", tlt);
#endif
	cb_intr_whencomp = cb_build_alphanumeric_literal (buff, (size_t)21);

}

char *
cb_encode_program_id (const char *name)
{
	unsigned char		*p;
	const unsigned char	*s;
	const unsigned char	*t;
	unsigned char		buff[COB_MINI_BUFF];

	s = NULL;
	for (t = (const unsigned char *)name; *t; t++) {
		if (*t == (unsigned char)'/' || *t == (unsigned char)'\\') {
			s = t + 1;
		}
	}
	if (!s) {
		s = (const unsigned char *)name;
	}
	p = buff;
	/* Encode the initial digit */
	if (*s <= (unsigned char)'9' && *s >= (unsigned char)'0') {
		*p++ = (unsigned char)'_';
	}
	/* Encode invalid letters */
	for (; *s; s++) {
		if (likely(valid_char[*s])) {
			*p++ = *s;
		} else {
			*p++ = (unsigned char)'_';
			if (*s == (unsigned char)'-') {
				*p++ = (unsigned char)'_';
			} else {
				*p++ = hexval[*s / 16U];
				*p++ = hexval[*s % 16U];
			}
		}
	}
	*p = 0;

	/* Check case folding */
	if (unlikely(cb_fold_call)) {
		if (cb_fold_call == COB_FOLD_UPPER) {
			for (p = buff; *p; p++) {
				if (islower (*p)) {
					*p = (cob_u8_t)toupper (*p);
				}
			}
		} else if (cb_fold_call == COB_FOLD_LOWER) {
			for (p = buff; *p; p++) {
				if (isupper (*p)) {
					*p = (cob_u8_t)tolower (*p);
				}
			}
		}
	}

	return cobc_check_string ((char *)buff);
}

char *
cb_build_program_id (cb_tree name, cb_tree alt_name, const cob_u32_t is_func)
{
	char		*s;
	unsigned char	*p;

	if (alt_name) {
		current_program->orig_program_id =
			cobc_check_string ((char *)CB_LITERAL (alt_name)->data);
		s = cb_encode_program_id ((char *)CB_LITERAL (alt_name)->data);
	} else if (CB_LITERAL_P (name)) {
		current_program->orig_program_id =
			cobc_check_string ((char *)CB_LITERAL (name)->data);
		s = cb_encode_program_id ((char *)CB_LITERAL (name)->data);
	} else {
		current_program->orig_program_id =
			cobc_check_string (CB_NAME (name));
		s = cb_encode_program_id (CB_NAME (name));
	}
	(void)cobc_check_valid_name (current_program->orig_program_id, 2U);
	if (is_func) {
		for (p = (unsigned char *)s; *p; ++p) {
			if (islower ((int)*p)) {
				*p = (cob_u8_t)toupper ((int)*p);
			}
		}
	}
	return s;
}

cb_tree
cb_define_switch_name (cb_tree name, cb_tree sname, const int flag)
{
	cb_tree		switch_id;
	cb_tree		value;

	if (!name || name == cb_error_node) {
		return NULL;
	}
	if (!sname || sname == cb_error_node ||
	    CB_SYSTEM_NAME (sname)->category != CB_SWITCH_NAME) {
		cb_error_x (name, _("ON/OFF usage requires a SWITCH name"));
		return NULL;
	}
	switch_id = cb_int (CB_SYSTEM_NAME (sname)->token);
	value = CB_BUILD_FUNCALL_1 ("cob_get_switch", switch_id);
	if (flag == 0) {
		value = CB_BUILD_NEGATION (value);
	}
	cb_build_constant (name, value);
	return value;
}

cb_tree
cb_build_section_name (cb_tree name, const int sect_or_para)
{
	cb_tree x;

	if (name == cb_error_node) {
		return cb_error_node;
	}

	if (CB_WORD_COUNT (name) > 0) {
		x = CB_VALUE (CB_WORD_ITEMS (name));
		/* Used as a non-label name or used as a section name.
		   Duplicate paragraphs are allowed if not referenced;
		   Checked in typeck.c */
		if (!CB_LABEL_P (x) || sect_or_para == 0 ||
		    (sect_or_para && CB_LABEL_P (x) &&
		    CB_LABEL (x)->flag_section)) {
			redefinition_error (name);
			return cb_error_node;
		}
	}

	return name;
}

cb_tree
cb_build_assignment_name (struct cb_file *cfile, cb_tree name)
{
	const char	*s;
	const char	*p;

	if (name == cb_error_node) {
		return cb_error_node;
	}
	/* For special assignment */
	if (name == NULL) {
		return NULL;
	}

	switch (CB_TREE_TAG (name)) {
	case CB_TAG_LITERAL:
		return name;

	case CB_TAG_REFERENCE:
		s = CB_NAME (name);
		if (cb_assign_clause == CB_ASSIGN_MF) {
			if (cfile->flag_ext_assign) {
				p = strrchr (s, '-');
				if (p) {
					s = p + 1;
				}
				return cb_build_alphanumeric_literal (s, strlen (s));
			}
			current_program->reference_list =
			    cb_list_add (current_program->reference_list, name);
			return name;
		} else if (cb_assign_clause == CB_ASSIGN_IBM) {
			/* Check organization */
			if (strncmp (s, "S-", (size_t)2) == 0 ||
			    strncmp (s, "AS-", (size_t)3) == 0) {
				goto org;
			}
			/* Skip the device label if exists */
			if ((p = strchr (s, '-')) != NULL) {
				s = p + 1;
			}
			/* Check organization again */
			if (strncmp (s, "S-", (size_t)2) == 0 ||
			    strncmp (s, "AS-", (size_t)3) == 0) {
org:
				/* Skip it for now */
				s = strchr (s, '-') + 1;
			}
			/* Convert the name into literal */
			if (warningopt) {
				cb_warning (_("ASSIGN interpreted as %s"), s);
			}
			return cb_build_alphanumeric_literal (s, strlen (s));
		}
		/* Fall through for CB_ASSIGN_COBOL2002 */
		/* To be looked at */
	default:
		return cb_error_node;
	}
}

cb_tree
cb_build_index (cb_tree x, cb_tree values, const unsigned int indexed_by,
		struct cb_field *qual)
{
	struct cb_field	*f;

	f = CB_FIELD (cb_build_field (x));
	f->usage = CB_USAGE_INDEX;
	cb_validate_field (f);
	if (values) {
		f->values = CB_LIST_INIT (values);
	}
	if (qual) {
		f->index_qual = qual;
	}
	f->flag_indexed_by = !!indexed_by;
	CB_FIELD_ADD (current_program->working_storage, f);
	return x;
}

cb_tree
cb_build_address (cb_tree x)
{
	cb_tree			v;
	struct cb_reference	*r;
	const char		*name;
	int			numsubs;
	int			refsubs;

	if (x == cb_error_node) {
		return cb_error_node;
	}
	if (!CB_REFERENCE_P (x)) {
		return CB_BUILD_CAST_ADDRESS (x);
	}

	r = CB_REFERENCE (x);
	name = r->word->name;
	v = cb_ref (x);
	if (v == cb_error_node) {
		return cb_error_node;
	}

	refsubs = cb_list_length (r->subs);
	if (CB_FIELD_P (v)) {
		numsubs = CB_FIELD (v)->indexes;
		if (refsubs > numsubs) {
			goto subserror;
		} else if (refsubs < numsubs) {
			if (!cb_relaxed_syntax_check) {
				goto subserror;
			} else {
				cb_warning_x (x,
					    _("Subscripts missing for '%s' - Defaulting to 1"),
					    name);
				for (; refsubs < numsubs; ++refsubs) {
					CB_ADD_TO_CHAIN (cb_one, r->subs);
				}
			}
		}
	} else {
		numsubs = 0;
		if (r->subs) {
			goto subserror;
		}
		if (r->offset) {
			cb_error_x (x, _("'%s' cannot be reference modified"), name);
			return cb_error_node;
		}
	}

	return CB_BUILD_CAST_ADDRESS (x);

subserror:
	switch (numsubs) {
	case 0:
		cb_error_x (x, _("'%s' cannot be subscripted"), name);
		break;
	case 1:
		cb_error_x (x, _("'%s' requires 1 subscript"), name);
		break;
	default:
		cb_error_x (x, _("'%s' requires %d subscripts"),
			    name, numsubs);
		break;
	}
	return cb_error_node;
}

cb_tree
cb_build_identifier (cb_tree x, const int subchk)
{
	struct cb_reference	*r;
	struct cb_field		*f;
	struct cb_field		*p;
	const char		*name;
	cb_tree			v;
	cb_tree			e1;
	cb_tree			e2;
	cb_tree			l;
	cb_tree			sub;
	int			offset;
	int			length;
	int			n;
	int			numsubs;
	int			refsubs;
	int			pseudosize;

	if (x == cb_error_node) {
		return cb_error_node;
	}

	r = CB_REFERENCE (x);
	name = r->word->name;

	/* Resolve reference */
	v = cb_ref (x);
	if (v == cb_error_node) {
		return cb_error_node;
	}

	/* Check if it is a data name */
	if (!CB_FIELD_P (v)) {
		if (r->subs) {
			cb_error_x (x, _("'%s' cannot be subscripted"), name);
			return cb_error_node;
		}
		if (r->offset) {
			cb_error_x (x, _("'%s' cannot be reference modified"), name);
			return cb_error_node;
		}
		return x;
	}
	f = CB_FIELD (v);

	/* BASED check */
	if (CB_EXCEPTION_ENABLE (COB_EC_BOUND_PTR)) {
		p = cb_field_founder (f);
		if (p->redefines) {
			p = p->redefines;
		}
		if (current_statement && !current_statement->flag_no_based &&
			strcmp(current_statement->name, "FREE")) {
			if (p->flag_item_based ||
			   (f->storage == CB_STORAGE_LINKAGE &&
			    !p->flag_is_pdiv_parm)) {
				current_statement->null_check = CB_BUILD_FUNCALL_2 (
					"cob_check_based",
					cb_build_address (cb_build_field_reference (p, NULL)),
					CB_BUILD_STRING0 (name));
			}
		}
	}

	for (l = r->subs; l; l = CB_CHAIN (l)) {
		if (CB_BINARY_OP_P (CB_VALUE (l))) {
			/* Set special flag for codegen */
			CB_BINARY_OP(CB_VALUE(l))->flag = 1;
		}
	}

	/* Check the number of subscripts */
	numsubs = cb_list_length (r->subs);
	cb_check_lit_subs (r, numsubs, f->indexes);
	if (subchk) {
		if (!f->indexes) {
			cb_error_x (x, _("'%s' has no OCCURS clause"), name);
			return cb_error_node;
		}
		numsubs = f->indexes - 1;
	} else {
		numsubs = f->indexes;
	}
	refsubs = cb_list_length (r->subs);
	if (!r->flag_all && refsubs != numsubs) {
		if (refsubs > numsubs) {
			goto refsubserr;
		} else if (refsubs < numsubs) {
			if (!cb_relaxed_syntax_check) {
				goto refsubserr;
			} else {
				cb_warning_x (x,
					    _("Subscripts missing for '%s' - Defaulting to 1"),
					    name);
				for (; refsubs < numsubs; ++refsubs) {
					CB_ADD_TO_CHAIN (cb_one, r->subs);
				}
			}
		}
	}

	/* Subscript check */
	if (!r->flag_all && r->subs) {
		l = r->subs;
		for (p = f; p; p = p->parent) {
			if (!p->flag_occurs) {
				continue;
			}

#if	1	/* RXWRXW - Sub check */
			if (!l) {
				break;
			}
#endif
			sub = cb_check_integer_value (CB_VALUE (l));
			l = CB_CHAIN (l);
			if (sub == cb_error_node) {
				continue;
			}

			/* Compile-time check */
			if (CB_LITERAL_P (sub)) {
				n = cb_get_int (sub);
				if (n < 1 || n > p->occurs_max) {
					cb_error_x (x, _("Subscript of '%s' out of bounds: %d"),
						    name, n);
				}
			}

			/* Run-time check */
			if (CB_EXCEPTION_ENABLE (COB_EC_BOUND_SUBSCRIPT)) {
				if (p->depending) {
					e1 = CB_BUILD_FUNCALL_4 ("cob_check_odo",
						 cb_build_cast_int (p->depending),
						 cb_int (p->occurs_min),
						 cb_int (p->occurs_max),
						 CB_BUILD_STRING0
						 ((CB_FIELD_PTR (p->depending)->name)));
					e2 = CB_BUILD_FUNCALL_4 ("cob_check_subscript",
						 cb_build_cast_int (sub),
						 cb_int1,
						 cb_build_cast_int (p->depending),
						 CB_BUILD_STRING0 (name));
					r->check = cb_list_add (r->check, e1);
					r->check = cb_list_add (r->check, e2);
				} else {
					if (!CB_LITERAL_P (sub)) {
						e1 = CB_BUILD_FUNCALL_4 ("cob_check_subscript",
							cb_build_cast_int (sub),
							cb_int1,
							cb_int (p->occurs_max),
							CB_BUILD_STRING0 (name));
						r->check = cb_list_add (r->check, e1);
					}
				}
			}
		}
	}

	if (subchk) {
		r->subs = cb_list_reverse (r->subs);
		r->subs = cb_list_add (r->subs, cb_int1);
		r->subs = cb_list_reverse (r->subs);
	}

	/* Reference modification check */
	if ( f->usage == CB_USAGE_NATIONAL ) {
		pseudosize = f->size / 2;
	} else {
		pseudosize = f->size;
	}
	if (r->offset) {
		/* Compile-time check */
		if (CB_LITERAL_P (r->offset)) {
			offset = cb_get_int (r->offset);
			if (f->flag_any_length) {
				if (offset < 1) {
					cb_error_x (x, _("Offset of '%s' out of bounds: %d"), name, offset);
				} else if (r->length && CB_LITERAL_P (r->length)) {
					length = cb_get_int (r->length);
					if (length < 1) {
						cb_error_x (x, _("Length of '%s' out of bounds: %d"),
							    name, length);
					}
				}
			} else {
				if (offset < 1 || offset > pseudosize) {
					cb_error_x (x, _("Offset of '%s' out of bounds: %d"), name, offset);
				} else if (r->length && CB_LITERAL_P (r->length)) {
					length = cb_get_int (r->length);
					if (length < 1 || length > pseudosize - offset + 1) {
						cb_error_x (x, _("Length of '%s' out of bounds: %d"),
							    name, length);
					}
				}
			}
		}

		/* Run-time check */
		if (CB_EXCEPTION_ENABLE (COB_EC_BOUND_REF_MOD)) {
			if (f->flag_any_length || !CB_LITERAL_P (r->offset) ||
			    (r->length && !CB_LITERAL_P (r->length))) {
				e1 = CB_BUILD_FUNCALL_4 ("cob_check_ref_mod",
							 cb_build_cast_int (r->offset),
							 r->length ?
							  cb_build_cast_int (r->length) :
							  cb_int1,
							 f->flag_any_length ?
							  CB_BUILD_CAST_LENGTH (v) :
							  cb_int (pseudosize),
							 CB_BUILD_STRING0 (f->name));
				r->check = cb_list_add (r->check, e1);
			}
		}
	}

	if (f->storage == CB_STORAGE_CONSTANT) {
		return CB_VALUE (f->values);
	}

	return x;

refsubserr:
	switch (numsubs) {
	case 0:
		cb_error_x (x, _("'%s' cannot be subscripted"), name);
		break;
	case 1:
		cb_error_x (x, _("'%s' requires 1 subscript"), name);
		break;
	default:
		cb_error_x (x, _("'%s' requires %d subscripts"),
			    name, f->indexes);
		break;
	}
	return cb_error_node;
}

static cb_tree
cb_build_length_1 (cb_tree x)
{
	struct cb_field *f;
	cb_tree		e;
	cb_tree		size;

	f = CB_FIELD (cb_ref (x));

	if (cb_field_variable_size (f) == NULL) {
		/* Constant size */
		return cb_int (cb_field_size (x));
	}
	/* Variable size */
	e = NULL;
	for (f = f->children; f; f = f->sister) {
		size = cb_build_length_1 (cb_build_field_reference (f, x));
		if (f->depending) {
			if (!cb_flag_odoslide && f->flag_odo_item) {
				size = cb_build_binary_op (size, '*',
							   cb_int (f->occurs_max));
			} else {
				size = cb_build_binary_op (size, '*',
							   f->depending);
			}
		} else if (f->occurs_max > 1) {
			size = cb_build_binary_op (size, '*',
						   cb_int (f->occurs_max));
		}
		e = e ? cb_build_binary_op (e, '+', size) : size;
	}
	return e;
}

cb_tree
cb_build_const_length (cb_tree x)
{
	struct cb_field		*f;
	char			buff[32];

	if (x == cb_error_node) {
		return cb_error_node;
	}
	if (CB_INTEGER_P (x)) {
		sprintf (buff, "%d", CB_INTEGER(x)->val);
		return cb_build_numeric_literal (0, buff, 0);
	}
	if (CB_REFERENCE_P (x)) {
		if (cb_ref (x) == cb_error_node) {
			return cb_error_node;
		}
		if (CB_REFERENCE (x)->offset) {
			cb_error (_("Reference modification not allowed here"));
			return cb_error_node;
		}
	}

	memset (buff, 0, sizeof (buff));
	f = CB_FIELD (cb_ref (x));
	if (f->flag_any_length) {
		cb_error (_("ANY LENGTH item not allowed here"));
		return cb_error_node;
	}
	if (f->level == 88) {
		cb_error (_("88 level item not allowed here"));
		return cb_error_node;
	}
	if (cb_field_variable_size (f)) {
		cb_error (_("Variable length item not allowed here"));
		return cb_error_node;
	}
	if (f->redefines) {
		cb_validate_field (f->redefines);
		if (f->rename_thru) {
			cb_validate_field (f->rename_thru);
		}
		cb_validate_field (f);
		sprintf (buff, "%d", f->size);
	} else {
		cb_validate_field (f);
		sprintf (buff, "%d", f->memory_size);
	}
	return cb_build_numeric_literal (0, buff, 0);
}

cb_tree
cb_build_length (cb_tree x)
{
	struct cb_field		*f;
	struct cb_literal	*l;
	cb_tree			temp;
	char			buff[32];

	if (x == cb_error_node) {
		return cb_error_node;
	}
	if (CB_REFERENCE_P (x) && cb_ref (x) == cb_error_node) {
		return cb_error_node;
	}

	if (CB_LITERAL_P (x)) {
		l = CB_LITERAL (x);
		sprintf (buff, "%d", (int)l->size);
		return cb_build_numeric_literal (0, buff, 0);
	}
	if (CB_INTRINSIC_P (x)) {
		return cb_build_any_intrinsic (CB_LIST_INIT (x));
	}
	if (CB_REF_OR_FIELD_P (x)) {
		if (CB_REFERENCE_P (x) && CB_REFERENCE (x)->offset) {
			return cb_build_any_intrinsic (CB_LIST_INIT (x));
		}
		f = CB_FIELD (cb_ref (x));
		if (f->flag_any_length) {
			return cb_build_any_intrinsic (CB_LIST_INIT (x));
		}
		if (cb_field_variable_size (f) == NULL) {
			sprintf (buff, "%d", cb_field_size (x));
			return cb_build_numeric_literal (0, buff, 0);
		}
	}
	temp = cb_build_index (cb_build_filler (), NULL, 0, NULL);
	CB_FIELD (cb_ref (temp))->usage = CB_USAGE_LENGTH;
	CB_FIELD (cb_ref (temp))->count++;
	cb_emit (cb_build_assign (temp, cb_build_length_1 (x)));
	return temp;
}

cb_tree
cb_build_ppointer (cb_tree x)
{
	struct cb_field	*f;

	if (x == cb_error_node ||
	    (CB_REFERENCE_P (x) && cb_ref (x) == cb_error_node)) {
		return cb_error_node;
	}

	if (CB_REFERENCE_P (x)) {
		f = CB_FIELD_PTR (cb_ref(x));
		f->count++;
	}
	return CB_BUILD_CAST_PPOINTER (x);
}

/* Validate program */

static int
get_value (cb_tree x)
{
	if (x == cb_space) {
		return ' ';
	} else if (x == cb_zero) {
		return '0';
	} else if (x == cb_quote) {
		return cb_flag_apostrophe ? '\'' : '"';
	} else if (x == cb_norm_low) {
		return 0;
	} else if (x == cb_norm_high) {
		return 255;
	} else if (x == cb_null) {
		return 0;
	} else if (CB_TREE_CLASS (x) == CB_CLASS_NUMERIC) {
		return cb_get_int (x) - 1;
	}
	return CB_LITERAL (x)->data[0];
}

static void
cb_validate_collating (struct cb_program *prog)
{
	cb_tree		x;

	x = cb_ref (prog->collating_sequence);
	if (!CB_ALPHABET_NAME_P (x)) {
		cb_error_x (prog->collating_sequence, _("'%s' is not an alphabet name"),
			    cb_name (prog->collating_sequence));
		prog->collating_sequence = NULL;
		return;
	}
	if (CB_ALPHABET_NAME (x)->alphabet_type != CB_ALPHABET_CUSTOM) {
		return;
	}
	if (CB_ALPHABET_NAME (x)->low_val_char) {
		cb_low = cb_build_alphanumeric_literal ("\0", (size_t)1);
		CB_LITERAL(cb_low)->data[0] = CB_ALPHABET_NAME (x)->low_val_char;
		CB_LITERAL(cb_low)->all = 1;
	}
	if (CB_ALPHABET_NAME (x)->high_val_char != 255){
		cb_high = cb_build_alphanumeric_literal ("\0", (size_t)1);
		CB_LITERAL(cb_high)->data[0] = CB_ALPHABET_NAME (x)->high_val_char;
		CB_LITERAL(cb_high)->all = 1;
	}
}

void
cb_validate_program_environment (struct cb_program *prog)
{
	cb_tree			x;
	cb_tree			y;
	cb_tree			l;
	cb_tree			ls;
	struct cb_alphabet_name	*ap;
	struct cb_class_name	*cp;
	unsigned char		*data;
	size_t			dupls;
	size_t			unvals;
	size_t			count;
	int			lower;
	int			upper;
	int			size;
	int			n;
	int			i;
	int			lastval;
	int			tableval;
	int			values[256];
	int			charvals[256];

	/* Check ALPHABET clauses */
	/* Complicated by difference between code set and collating sequence */
	for (l = current_program->alphabet_name_list; l; l = CB_CHAIN (l)) {
		ap = CB_ALPHABET_NAME (CB_VALUE (l));

		/* Native */
		if (ap->alphabet_type == CB_ALPHABET_NATIVE) {
			for (n = 0; n < 256; n++) {
				ap->values[n] = n;
				ap->alphachr[n] = n;
			}
			continue;
		}

		/* ASCII */
		if (ap->alphabet_type == CB_ALPHABET_ASCII) {
			for (n = 0; n < 256; n++) {
#ifdef	COB_EBCDIC_MACHINE
				ap->values[n] = (int)cob_refer_ascii[n];
				ap->alphachr[n] = (int)cob_refer_ascii[n];
#else
				ap->values[n] = n;
				ap->alphachr[n] = n;
#endif
			}
			continue;
		}

		/* EBCDIC */
		if (ap->alphabet_type == CB_ALPHABET_EBCDIC) {
			for (n = 0; n < 256; n++) {
#ifdef	COB_EBCDIC_MACHINE
				ap->values[n] = n;
				ap->alphachr[n] = n;
#else
				ap->values[n] = (int)cob_refer_ebcdic[n];
				ap->alphachr[n] = (int)cob_refer_ebcdic[n];
#endif
			}
			continue;
		}

		/* Custom alphabet */
		dupls = 0;
		unvals = 0;
		count = 0;
		lastval = 0;
		tableval = 0;
		for (n = 0; n < 256; n++) {
			values[n] = -1;
			charvals[n] = -1;
			ap->values[n] = -1;
			ap->alphachr[n] = -1;
		}
		ap->low_val_char = 0;
		ap->high_val_char = 255;
		for (y = ap->custom_list; y; y = CB_CHAIN (y)) {
			if (count > 255) {
				unvals = 1;
				break;
			}
			x = CB_VALUE (y);
			if (CB_PAIR_P (x)) {
				/* X THRU Y */
				lower = get_value (CB_PAIR_X (x));
				upper = get_value (CB_PAIR_Y (x));
				lastval = upper;
				if (!count) {
					ap->low_val_char = lower;
				}
				if (lower < 0 || lower > 255) {
					unvals = 1;
					continue;
				}
				if (upper < 0 || upper > 255) {
					unvals = 1;
					continue;
				}
				if (lower <= upper) {
					for (i = lower; i <= upper; i++) {
						if (values[i] != -1) {
							dupls = 1;
						}
						values[i] = i;
						charvals[i] = i;
						ap->alphachr[tableval] = i;
						ap->values[i] = tableval++;
						count++;
					}
				} else {
					for (i = lower; i >= upper; i--) {
						if (values[i] != -1) {
							dupls = 1;
						}
						values[i] = i;
						charvals[i] = i;
						ap->alphachr[tableval] = i;
						ap->values[i] = tableval++;
						count++;
					}
				}
			} else if (CB_LIST_P (x)) {
				/* X ALSO Y ... */
				if (!count) {
					ap->low_val_char = get_value (CB_VALUE (x));
				}
				for (ls = x; ls; ls = CB_CHAIN (ls)) {
					n = get_value (CB_VALUE (ls));
					if (!CB_CHAIN (ls)) {
						lastval = n;
					}
					if (n < 0 || n > 255) {
						unvals = 1;
						continue;
					}
					if (values[n] != -1) {
						dupls = 1;
					}
					values[n] = n;
					ap->values[n] = tableval;
					if (ls == x) {
						ap->alphachr[tableval] = n;
						charvals[n] = n;
					}
					count++;
				}
				tableval++;
			} else {
				/* Literal */
				if (CB_NUMERIC_LITERAL_P (x)) {
					n = get_value (x);
					lastval = n;
					if (!count) {
						ap->low_val_char = n;
					}
					if (n < 0 || n > 255) {
						unvals = 1;
						continue;
					}
					if (values[n] != -1) {
						dupls = 1;
					}
					values[n] = n;
					charvals[n] = n;
					ap->alphachr[tableval] = n;
					ap->values[n] = tableval++;
					count++;
				} else if (CB_LITERAL_P (x)) {
					size = (int)CB_LITERAL (x)->size;
					data = CB_LITERAL (x)->data;
					if (!count) {
						ap->low_val_char = data[0];
					}
					lastval = data[size - 1];
					for (i = 0; i < size; i++) {
						n = data[i];
						if (values[n] != -1) {
							dupls = 1;
						}
						values[n] = n;
						charvals[n] = n;
						ap->alphachr[tableval] = n;
						ap->values[n] = tableval++;
						count++;
					}
				} else {
					n = get_value (x);
					lastval = n;
					if (!count) {
						ap->low_val_char = n;
					}
					if (n < 0 || n > 255) {
						unvals = 1;
						continue;
					}
					if (values[n] != -1) {
						dupls = 1;
					}
					values[n] = n;
					charvals[n] = n;
					ap->alphachr[tableval] = n;
					ap->values[n] = tableval++;
					count++;
				}
			}
		}
		if (dupls || unvals) {
			if (dupls) {
				cb_error_x (l, _("Duplicate character values in alphabet '%s'"),
					    cb_name (CB_VALUE(l)));
			}
			if (unvals) {
				cb_error_x (l, _("Invalid character values in alphabet '%s'"),
					    cb_name (CB_VALUE(l)));
			}
			ap->low_val_char = 0;
			ap->high_val_char = 255;
			continue;
		}
		/* Calculate HIGH-VALUE */
		/* If all 256 values have been specified, */
		/* HIGH-VALUE is the last one */
		/* Otherwise if HIGH-VALUE has been specified, find the highest */
		/* value that has not been used */
		if (count == 256) {
			ap->high_val_char = lastval;
		} else if (values[255] != -1) {
			for (n = 254; n >= 0; n--) {
				if (values[n] == -1) {
					ap->high_val_char = n;
					break;
				}
			}
		}

		/* Get rest of code set */
		for (n = tableval; n < 256; ++n) {
			for (i = 0; i < 256; ++i) {
				if (charvals[i] < 0) {
					charvals[i] = 0;
					ap->alphachr[n] = i;
					break;
				}
			}
		}

		/* Fill in missing characters */
		for (n = 0; n < 256; n++) {
			if (ap->values[n] < 0) {
				ap->values[n] = tableval++;
			}
		}
	}

	/* Reset HIGH/LOW-VALUES */
	cb_low = cb_norm_low;
	cb_high = cb_norm_high;

	/* Check and generate SYMBOLIC clauses */
	for (l = current_program->symbolic_char_list; l; l = CB_CHAIN (l)) {
		if (CB_VALUE (l)) {
			y = cb_ref (CB_VALUE (l));
			if (y == cb_error_node) {
				continue;
			}
			if (!CB_ALPHABET_NAME_P (y)) {
				cb_error_x (y, _("Invalid ALPHABET name"));
				continue;
			}
		} else {
			y = NULL;
		}
		cb_build_symbolic_chars (CB_PURPOSE (l), y);
	}

	/* Check CLASS clauses */
	for (l = current_program->class_name_list; l; l = CB_CHAIN (l)) {
		dupls = 0;
		memset (values, 0, sizeof(values));
		cp = CB_CLASS_NAME (CB_VALUE (l));
		for (y = cp->list; y; y = CB_CHAIN (y)) {
			x = CB_VALUE (y);
			if (CB_PAIR_P (x)) {
				/* X THRU Y */
				lower = get_value (CB_PAIR_X (x));
				upper = get_value (CB_PAIR_Y (x));
				for (i = lower; i <= upper; i++) {
					if (values[i]) {
						dupls = 1;
					}
					values[i] = 1;
				}
			} else {
				if (CB_NUMERIC_LITERAL_P (x)) {
					n = get_value (x);
					if (values[n]) {
						dupls = 1;
					}
					values[n] = 1;
				} else if (CB_LITERAL_P (x)) {
					size = (int)CB_LITERAL (x)->size;
					data = CB_LITERAL (x)->data;
					for (i = 0; i < size; i++) {
						n = data[i];
						if (values[n]) {
							dupls = 1;
						}
						values[n] = 1;
					}
				} else {
					n = get_value (x);
					if (values[n]) {
						dupls = 1;
					}
					values[n] = 1;
				}
			}
		}
		if (dupls) {
			if (!cb_relaxed_syntax_check) {
				cb_error_x (CB_VALUE(l),
					    _("Duplicate values in class '%s'"),
					    cb_name (CB_VALUE(l)));
			} else {
				cb_warning_x (CB_VALUE(l),
					    _("Duplicate values in class '%s'"),
					    cb_name (CB_VALUE(l)));
			}
		}
	}

	/* Resolve the program collating sequence */
	if (prog->collating_sequence) {
		cb_validate_collating (prog);
	}

	/* Resolve the program classification */
	if (prog->classification && prog->classification != cb_int1) {
		x = cb_ref (prog->classification);
		if (!CB_LOCALE_NAME_P (x)) {
			cb_error_x (prog->classification,
				    _("'%s' is not a locale name"),
				    cb_name (prog->classification));
			prog->classification = NULL;
			return;
		}
	}
}

void
cb_build_debug_item (void)
{
	cb_tree			l;
	cb_tree			x;
	cb_tree			assign;

	/* Set up DEBUG-ITEM */
	l = cb_build_reference ("DEBUG-ITEM");
	assign = cb_build_field_tree (NULL, l, NULL, CB_STORAGE_WORKING,
				 NULL, 1);
	CB_FIELD (assign)->values = CB_LIST_INIT (cb_space);
	cb_debug_item = l;

	l = cb_build_reference ("DEBUG-LINE");
	x = cb_build_field_tree (NULL, l, CB_FIELD(assign),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("9(6)"));
	cb_validate_field (CB_FIELD (x));
	cb_debug_line = l;

	l = cb_build_filler ();
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X"));
	CB_FIELD (x)->flag_filler = 1;
	cb_validate_field (CB_FIELD (x));

	l = cb_build_reference ("DEBUG-NAME");
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X(31)"));
	cb_validate_field (CB_FIELD (x));
	cb_debug_name = l;

	l = cb_build_filler ();
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X"));
	CB_FIELD (x)->flag_filler = 1;
	cb_validate_field (CB_FIELD (x));

	l = cb_build_reference ("DEBUG-SUB-1");
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("S9(4)"));
	CB_FIELD (x)->flag_sign_leading = 1;
	CB_FIELD (x)->flag_sign_separate = 1;
	cb_validate_field (CB_FIELD (x));
	cb_debug_sub_1 = l;

	l = cb_build_filler ();
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X"));
	CB_FIELD (x)->flag_filler = 1;
	cb_validate_field (CB_FIELD (x));

	l = cb_build_reference ("DEBUG-SUB-2");
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("S9(4)"));
	CB_FIELD (x)->flag_sign_leading = 1;
	CB_FIELD (x)->flag_sign_separate = 1;
	cb_validate_field (CB_FIELD (x));
	cb_debug_sub_2 = l;

	l = cb_build_filler ();
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X"));
	CB_FIELD (x)->flag_filler = 1;
	cb_validate_field (CB_FIELD (x));

	l = cb_build_reference ("DEBUG-SUB-3");
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("S9(4)"));
	CB_FIELD (x)->flag_sign_leading = 1;
	CB_FIELD (x)->flag_sign_separate = 1;
	cb_validate_field (CB_FIELD (x));
	cb_debug_sub_3 = l;

	l = cb_build_filler ();
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X"));
	CB_FIELD (x)->flag_filler = 1;
	cb_validate_field (CB_FIELD (x));

	l = cb_build_reference ("DEBUG-CONTENTS");
	x = cb_build_field_tree (NULL, l, CB_FIELD(x),
				 CB_STORAGE_WORKING, NULL, 3);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture ("X(31)"));
	cb_validate_field (CB_FIELD (x));
	cb_debug_contents = l;

	cb_validate_field (CB_FIELD (assign));
	CB_FIELD_ADD (current_program->working_storage, CB_FIELD (assign));
}

void
cb_validate_program_data (struct cb_program *prog)
{
	cb_tree			l;
	cb_tree			x;
	cb_tree			assign;
	struct cb_field		*p;
	struct cb_field		*q;
	struct cb_field		*depfld;
	struct cb_file		*f;
	struct cb_report	*rep;
	unsigned char		*c;
	char			buff[COB_MINI_BUFF];

	for (l = current_program->report_list; l; l = CB_CHAIN (l)) {
		/* Set up LINE-COUNTER / PAGE-COUNTER */
		rep = CB_REPORT (CB_VALUE (l));
		snprintf (buff, (size_t)COB_MINI_MAX,
			  "LINE-COUNTER %s", rep->cname);
		x = cb_build_field (cb_build_reference (buff));
		CB_FIELD (x)->usage = CB_USAGE_UNSIGNED_INT;
		CB_FIELD (x)->values = CB_LIST_INIT (cb_zero);
		CB_FIELD (x)->count++;
		cb_validate_field (CB_FIELD (x));
		rep->line_counter = cb_build_field_reference (CB_FIELD (x), NULL);
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD (x));
		snprintf (buff, (size_t)COB_MINI_MAX,
			  "PAGE-COUNTER %s", rep->cname);
		x = cb_build_field (cb_build_reference (buff));
		CB_FIELD (x)->usage = CB_USAGE_UNSIGNED_INT;
		CB_FIELD (x)->values = CB_LIST_INIT (cb_zero);
		CB_FIELD (x)->count++;
		cb_validate_field (CB_FIELD (x));
		rep->page_counter = cb_build_field_reference (CB_FIELD (x), NULL);
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD (x));
	}

	for (l = current_program->file_list; l; l = CB_CHAIN (l)) {
		f = CB_FILE (CB_VALUE (l));
		if (!f->flag_finalized) {
			finalize_file (f, NULL);
		}
	}

	/* Build undeclared assignment name now */
	if (cb_assign_clause == CB_ASSIGN_MF) {
		for (l = current_program->file_list; l; l = CB_CHAIN (l)) {
			assign = CB_FILE (CB_VALUE (l))->assign;
			if (!assign) {
				continue;
			}
			if (CB_REFERENCE_P (assign)) {
				for (x = current_program->file_list; x; x = CB_CHAIN (x)) {
					if (!strcmp (CB_FILE (CB_VALUE (x))->name,
					     CB_NAME (assign))) {
						redefinition_error (assign);
					}
				}
				p = check_level_78 (CB_NAME (assign));
				if (p) {
					c = (unsigned char *)CB_LITERAL(CB_VALUE(p->values))->data;
					assign = CB_TREE (build_literal (CB_CATEGORY_ALPHANUMERIC, c, strlen ((char *)c)));
					CB_FILE (CB_VALUE (l))->assign = assign;
				}
			}
			if (CB_REFERENCE_P (assign) &&
			    CB_WORD_COUNT (assign) == 0) {
				if (cb_warn_implicit_define) {
					cb_warning (_("'%s' will be implicitly defined"), CB_NAME (assign));
				}
				x = cb_build_implicit_field (assign, COB_SMALL_BUFF);
				CB_FIELD (x)->count++;
				p = current_program->working_storage;
				if (p) {
					while (p->sister) {
						p = p->sister;
					}
					p->sister = CB_FIELD (x);
				} else {
					current_program->working_storage = CB_FIELD (x);
				}
			}
			if (CB_REFERENCE_P (assign)) {
				x = cb_ref (assign);
				if (CB_FIELD_P (x) && CB_FIELD (x)->level == 88) {
					cb_error_x (assign, _("ASSIGN data item '%s' invalid"), CB_NAME (assign));
				}
			}
		}
	}

	if (prog->cursor_pos) {
		x = cb_ref (prog->cursor_pos);
		if (x == cb_error_node) {
			prog->cursor_pos = NULL;
		} else if (CB_FIELD(x)->size != 6 && CB_FIELD(x)->size != 4) {
			cb_error_x (prog->cursor_pos, _("'%s' CURSOR is not 4 or 6 characters long"),
				    cb_name (prog->cursor_pos));
			prog->cursor_pos = NULL;
		}
	}
	if (prog->crt_status) {
		x = cb_ref (prog->crt_status);
		if (x == cb_error_node) {
			prog->crt_status = NULL;
		} else if (CB_FIELD(x)->size != 4) {
			cb_error_x (prog->crt_status, _("'%s' CRT STATUS is not 4 characters long"),
				    cb_name (prog->crt_status));
			prog->crt_status = NULL;
		}
	} else {
		l = cb_build_reference ("COB-CRT-STATUS");
		p = CB_FIELD (cb_build_field (l));
		p->usage = CB_USAGE_DISPLAY;
		p->pic = CB_PICTURE (cb_build_picture ("9(4)"));
		cb_validate_field (p);
		p->flag_no_init = 1;
		/* Do not initialize/bump ref count here
		p->values = CB_LIST_INIT (cb_zero);
		p->count++;
		*/
		CB_FIELD_ADD (current_program->working_storage, p);
		prog->crt_status = l;
	}

	/* Resolve all references so far */
	for (l = cb_list_reverse (prog->reference_list); l; l = CB_CHAIN (l)) {
		cb_ref (CB_VALUE (l));
	}

	/* Check ODO items */
	for (l = cb_depend_check; l; l = CB_CHAIN (l)) {
		x = CB_VALUE(l);
		if (x == cb_error_node) {
			continue;
		}
		q = CB_FIELD_PTR (x);
		if (cb_ref (q->depending) != cb_error_node) {
			depfld = CB_FIELD_PTR (q->depending);
		} else {
			depfld = NULL;
		}
		/* The data item that contains a OCCURS DEPENDING clause must be
		   the last data item in the group */
		for (p = q; p->parent; p = p->parent) {
			for (; p->sister; p = p->sister) {
				if (p->sister == depfld) {
						cb_error_x (x,
							    _("'%s' ODO field item invalid here"),
							    p->sister->name);
				}
				if (!p->sister->redefines) {
					if (!cb_complex_odo) {
						cb_error_x (x,
							    _("'%s' cannot have OCCURS DEPENDING"),
							    cb_name (x));
						break;
					}
					p->flag_odo_item = 1;
				}
			}
		}
		/* If the field is GLOBAL, then the ODO must also be GLOBAL */
		if (q->flag_is_global && depfld) {
			if (!depfld->flag_is_global) {
				cb_error_x (x, _("'%s' ODO item must have GLOBAL attribute"),
					depfld->name);
			}
		}
	}
	cb_depend_check = NULL;
	cb_needs_01 = 0;

	for (l = current_program->file_list; l; l = CB_CHAIN (l)) {
		f = CB_FILE (CB_VALUE (l));
		if (CB_VALID_TREE(f->record_depending)) {
			x = f->record_depending;
			if (cb_ref (x) != cb_error_node) {
#if	0			/* RXWRXW - This breaks old legacy programs */
				if (CB_REF_OR_FIELD_P(x)) {
					p = CB_FIELD_PTR (x);
					switch (p->storage) {
					case CB_STORAGE_WORKING:
					case CB_STORAGE_LOCAL:
					case CB_STORAGE_LINKAGE:
						break;
					default:
						cb_error (_("RECORD DEPENDING item must be in WORKING/LOCAL/LINKAGE section"));
					}
				} else {
#endif
				if (!CB_REF_OR_FIELD_P(x)) {
					cb_error (_("Invalid RECORD DEPENDING item"));
				}
			}
		}
	}
}

void
cb_validate_program_body (struct cb_program *prog)
{
	cb_tree			l;
	cb_tree			x;
	cb_tree			v;
	struct cb_label		*save_section;
	struct cb_label		*save_paragraph;
	struct cb_alter_id	*aid;
	struct cb_label		*l1;
	struct cb_label		*l2;
	struct cb_field		*f;
	int			size;

	/* Resolve all labels */
	save_section = current_section;
	save_paragraph = current_paragraph;
	for (l = cb_list_reverse (prog->label_list); l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		current_section = CB_REFERENCE (x)->section;
		current_paragraph = CB_REFERENCE (x)->paragraph;
		v = cb_ref (x);
		/* Check refs in to / out of DECLARATIVES */
		if (CB_LABEL_P (v)) {
			if (CB_REFERENCE (x)->flag_in_decl &&
			    !CB_LABEL (v)->flag_declaratives) {
				if (!cb_relaxed_syntax_check) {
					cb_error_x (x, _("'%s' is not in DECLARATIVES"),
						    CB_LABEL (v)->name);
				} else {
					cb_warning_x (x, _("'%s' is not in DECLARATIVES"),
						    CB_LABEL (v)->name);
				}
			}
			if (CB_LABEL (v)->flag_declaratives &&
			    !CB_REFERENCE (x)->flag_in_decl &&
			    !CB_REFERENCE (x)->flag_decl_ok) {
				cb_error_x (x, _("Invalid reference to '%s' (In DECLARATIVES)"), CB_LABEL (v)->name);
			}
			CB_LABEL (v)->flag_begin = 1;
			if (CB_REFERENCE (x)->length) {
				CB_LABEL (v)->flag_return = 1;
			}
		} else if (v != cb_error_node) {
			cb_error_x (x, _("'%s' not a procedure name"), cb_name (x));
		}
	}

	/* Resolve DEBUG references */
	/* For data items, we may need to adjust the size of DEBUG-CONTENTS */
	/* Basic size of DEBUG-CONTENTS is 31 */
	size = 31;
	for (l = prog->debug_list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		current_section = CB_REFERENCE (x)->section;
		current_paragraph = CB_REFERENCE (x)->paragraph;
		v = cb_ref (x);
		if (v == cb_error_node) {
			continue;
		}
		switch (CB_TREE_TAG (v)) {
		case CB_TAG_LABEL:
			if (current_program->all_procedure) {
				cb_error_x (x, _("'%s' - DEBUGGING target invalid with ALL PROCEDURES"),
					    cb_name (x));
			}
			if (!CB_LABEL (v)->flag_real_label) {
				cb_error_x (x, _("'%s' - DEBUGGING target invalid"),
					    cb_name (x));
			}
			CB_LABEL (v)->debug_section =
				CB_REFERENCE (x)->debug_section;
			CB_LABEL (v)->flag_debugging_mode = 1;
			break;
		case CB_TAG_FILE:
			break;
		case CB_TAG_FIELD:
			if (CB_FIELD (v)->size > size) {
				size = CB_FIELD (v)->size;
			}
			break;
		default:
			cb_error_x (x, _("'%s' is not a valid DEBUGGING target"),
				    cb_name (x));
			break;
		}
	}
	/* If necessary, adjust size of DEBUG-CONTENTS (and DEBUG-ITEM) */
	if (current_program->flag_debugging) {
		if (size != 31) {
			f = CB_FIELD_PTR (cb_debug_contents);
			f->size = size;
			f->memory_size = size;
			size -= 31;
			f = CB_FIELD_PTR (cb_debug_item);
			f->size += size;
			f->memory_size += size;
		}
	}

	/* Build ALTER ids - We need to remove duplicates */
	for (l = prog->alter_list; l; l = CB_CHAIN (l)) {
		if (CB_PURPOSE (l) == cb_error_node) {
			continue;
		}
		if (CB_VALUE (l) == cb_error_node) {
			continue;
		}
		x = CB_PURPOSE (l);
		v = CB_VALUE (l);
		if (CB_REFERENCE (x)->value == cb_error_node) {
			continue;
		}
		if (CB_REFERENCE (v)->value == cb_error_node) {
			continue;
		}
		l1 = CB_LABEL (CB_REFERENCE (x)->value);
		l2 = CB_LABEL (CB_REFERENCE (v)->value);
		current_section = CB_REFERENCE (x)->section;
		current_paragraph = CB_REFERENCE (x)->paragraph;
		/* First statement in paragraph must be a GO TO */
		if (!l1->flag_first_is_goto) {
			cb_error_x (x, _("'%s' is not an alterable paragraph"),
				    l1->name);
			continue;
		}
		for (aid = l1->alter_gotos; aid; aid = aid->next) {
			if (aid->goto_id == l2->id) {
				break;
			}
		}
		if (!aid) {
			aid = cobc_parse_malloc (sizeof(struct cb_alter_id));
			aid->next = l1->alter_gotos;
			aid->goto_id = l2->id;
			l1->alter_gotos = aid;
		}
		for (aid = prog->alter_gotos; aid; aid = aid->next) {
			if (aid->goto_id == l1->id) {
				break;
			}
		}
		if (!aid) {
			aid = cobc_parse_malloc (sizeof(struct cb_alter_id));
			aid->next = prog->alter_gotos;
			aid->goto_id = l1->id;
			prog->alter_gotos = aid;
		}
	}

	current_section = save_section;
	current_paragraph = save_paragraph;
	cobc_cs_check = 0;

	prog->file_list = cb_list_reverse (prog->file_list);
	prog->exec_list = cb_list_reverse (prog->exec_list);
}

/* Expressions */

static void
cb_expr_init (void)
{
	if (initialized == 0) {
		initialized = 1;
		/* Init stack */
		expr_stack_size = START_STACK_SIZE;
		expr_stack = cobc_main_malloc (sizeof (struct expr_node) * START_STACK_SIZE);
	} else {
		memset (expr_stack, 0, expr_stack_size * sizeof (struct expr_node));
	}
	expr_op = 0;
	expr_lh = NULL;
	/* First three entries are dummies */
	expr_index = 3;
}

static int
expr_chk_cond (cb_tree expr_1, cb_tree expr_2)
{
	struct cb_field		*f1;
	struct cb_field		*f2;
	int			is_ptr_1;
	int			is_ptr_2;

	/* 88 level is invalid here */
	/* Likewise combination of pointer and non-pointer */
	is_ptr_1 = 0;
	is_ptr_2 = 0;
	if (CB_REF_OR_FIELD_P (expr_1)) {
		f1 = CB_FIELD_PTR (expr_1);
		if (f1->level == 88) {
			return 1;
		}
		if (f1->flag_is_pointer) {
			is_ptr_1 = 1;
		}
	} else if (CB_CAST_P (expr_1)) {
		switch (CB_CAST (expr_1)->cast_type) {
		case CB_CAST_ADDRESS:
		case CB_CAST_ADDR_OF_ADDR:
		case CB_CAST_PROGRAM_POINTER:
			is_ptr_1 = 1;
			break;
		default:
			break;
		}
	} else if (expr_1 == cb_null) {
		is_ptr_1 = 1;
	}
	if (CB_REF_OR_FIELD_P (expr_2)) {
		f2 = CB_FIELD_PTR (expr_2);
		if (f2->level == 88) {
			return 1;
		}
		if (f2->flag_is_pointer) {
			is_ptr_2 = 1;
		}
	} else if (CB_CAST_P (expr_2)) {
		switch (CB_CAST (expr_2)->cast_type) {
		case CB_CAST_ADDRESS:
		case CB_CAST_ADDR_OF_ADDR:
		case CB_CAST_PROGRAM_POINTER:
			is_ptr_2 = 1;
			break;
		default:
			break;
		}
	} else if (expr_2 == cb_null) {
		is_ptr_2 = 1;
	}
	return is_ptr_1 ^ is_ptr_2;
}

static int
expr_reduce (int token)
{
	/* Example:
	 * index: -3  -2  -1   0
	 * token: 'x' '*' 'x' '+' ...
	 */

	int	op;

	while (expr_prio[TOKEN (-2)] <= expr_prio[token]) {
		/* Reduce the expression depending on the last operator */
		op = TOKEN (-2);
		switch (op) {
		case 'x':
			return 0;

		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			/* Arithmetic operators: 'x' op 'x' */
			if (TOKEN (-1) != 'x' || TOKEN (-3) != 'x') {
				return -1;
			}
			TOKEN (-3) = 'x';
			VALUE (-3) = cb_build_binary_op (VALUE (-3), op, VALUE (-1));
			expr_index -= 2;
			break;

		case '!':
			/* Negation: '!' 'x' */
			if (TOKEN (-1) != 'x') {
				return -1;
			}
			/* 'x' '=' 'x' '|' '!' 'x' */
			if (expr_lh) {
				if (CB_TREE_CLASS (VALUE (-1)) != CB_CLASS_BOOLEAN) {
					VALUE (-1) = cb_build_binary_op (expr_lh, expr_op, VALUE (-1));
				}
			}
			TOKEN (-2) = 'x';
			VALUE (-2) = CB_BUILD_NEGATION (VALUE (-1));
			expr_index -= 1;
			break;

		case '&':
		case '|':
			/* Logical AND/OR: 'x' op 'x' */
			if (TOKEN (-1) != 'x' || TOKEN (-3) != 'x') {
				return -1;
			}
			/* 'x' '=' 'x' '|' 'x' */
			if (expr_lh) {
				if (CB_TREE_CLASS (VALUE (-1)) != CB_CLASS_BOOLEAN) {
					VALUE (-1) = cb_build_binary_op (expr_lh, expr_op, VALUE (-1));
				}
				if (CB_TREE_CLASS (VALUE (-3)) != CB_CLASS_BOOLEAN) {
					VALUE (-3) = cb_build_binary_op (expr_lh, expr_op, VALUE (-3));
				}
			}
			/* Warning for complex expressions without explicit parentheses
			   (i.e., "a OR b AND c" or "a AND b OR c") */
			if (cb_warn_parentheses && op == '|') {
				if ((CB_BINARY_OP_P (VALUE (-3)) &&
				     CB_BINARY_OP (VALUE (-3))->op == '&') ||
				    (CB_BINARY_OP_P (VALUE (-1)) &&
				     CB_BINARY_OP (VALUE (-1))->op == '&')) {
					cb_warning (_("Suggest parentheses around AND within OR"));
				}
			}
			TOKEN (-3) = 'x';
			VALUE (-3) = cb_build_binary_op (VALUE (-3), op,
							 VALUE (-1));
			expr_index -= 2;
			break;

		case '(':
		case ')':
			return 0;

		default:
			/* Relational operators */
			if (TOKEN (-1) != 'x') {
				return -1;
			}
			switch (TOKEN (-3)) {
			case 'x':
				/* Simple condition: 'x' op 'x' */
				if (VALUE (-3) == cb_error_node ||
				    VALUE (-1) == cb_error_node) {
					VALUE (-3) = cb_error_node;
				} else {
					expr_lh = VALUE (-3);
					if (expr_chk_cond (expr_lh, VALUE (-1))) {
						VALUE (-3) = cb_error_node;
						return 1;
					}
					expr_op = op;
					TOKEN (-3) = 'x';
					if (CB_TREE_CLASS (VALUE (-1)) != CB_CLASS_BOOLEAN) {
						VALUE (-3) = cb_build_binary_op (expr_lh, op, VALUE (-1));
					} else {
						VALUE (-3) = VALUE (-1);
					}
				}
				expr_index -= 2;
				break;
			case '&':
			case '|':
				/* Complex condition: 'x' '=' 'x' '|' op 'x' */
				if (VALUE (-1) == cb_error_node) {
					VALUE (-2) = cb_error_node;
				} else {
					expr_op = op;
					TOKEN (-2) = 'x';
					if (CB_TREE_CLASS (VALUE (-1)) != CB_CLASS_BOOLEAN && expr_lh) {
						VALUE (-2) = cb_build_binary_op (expr_lh, op, VALUE (-1));
					} else {
						VALUE (-2) = VALUE (-1);
					}
				}
				expr_index -= 1;
				break;
			default:
				return -1;
			}
			break;
		}
	}

	/* Handle special case "op OR x AND" */
	if (token == '&' && TOKEN (-2) == '|' &&
	    CB_TREE_CLASS (VALUE (-1)) != CB_CLASS_BOOLEAN) {
		TOKEN (-1) = 'x';
		VALUE (-1) = cb_build_binary_op (expr_lh, expr_op, VALUE (-1));
	}

	return 0;
}

static void
cb_expr_shift_sign (const int op)
{
	int	have_not;

	if (TOKEN (-1) == '!') {
		have_not = 1;
		expr_index--;
	} else {
		have_not = 0;
	}
	(void)expr_reduce ('=');
	if (TOKEN (-1) == 'x') {
		VALUE (-1) = cb_build_binary_op (VALUE (-1), op, cb_zero);
		if (have_not) {
			VALUE (-1) = CB_BUILD_NEGATION (VALUE (-1));
		}
	}
}

static void
cb_expr_shift_class (const char *name)
{
	int	have_not;

	if (TOKEN (-1) == '!') {
		have_not = 1;
		expr_index--;
	} else {
		have_not = 0;
	}
	(void)expr_reduce ('=');
	if (TOKEN (-1) == 'x') {
		VALUE (-1) = CB_BUILD_FUNCALL_1 (name, VALUE (-1));
		if (have_not) {
			VALUE (-1) = CB_BUILD_NEGATION (VALUE (-1));
		}
	}
}

static void
cb_expr_shift (int token, cb_tree value)
{
	switch (token) {
	case 'M':
		break;
	case 'x':
		/* Sign ZERO condition */
		if (value == cb_zero) {
			if (TOKEN (-1) == 'x' || TOKEN (-1) == '!') {
				cb_expr_shift_sign ('=');
				return;
			}
		}

		/* Unary sign */
		if ((TOKEN (-1) == '+' || TOKEN (-1) == '-') &&
		    TOKEN (-2) != 'x') {
			if (TOKEN (-1) == '-') {
				value = cb_build_binary_op (cb_zero, '-', value);
			}
			expr_index -= 1;
		}
		break;

	case '(':
		/* 'x' op '(' --> '(' 'x' op */
		switch (TOKEN (-1)) {
		case '=':
		case '~':
		case '<':
		case '>':
		case '[':
		case ']':
			expr_op = TOKEN (-1);
			if (TOKEN (-2) == 'x') {
				expr_lh = VALUE (-2);
			}
			break;
		default:
			break;
		}
		break;

	case ')':
		/* Enclosed by parentheses */
		(void)expr_reduce (token);
		if (TOKEN (-2) == '(') {
			value = CB_BUILD_PARENTHESIS (VALUE (-1));
			expr_index -= 2;
			cb_expr_shift ('x', value);
			return;
		}
		break;

	default:
		/* '<' '|' '=' --> '[' */
		/* '>' '|' '=' --> ']' */
		if (token == '=' && TOKEN (-1) == '|' &&
		    (TOKEN (-2) == '<' || TOKEN (-2) == '>')) {
			token = (TOKEN (-2) == '<') ? '[' : ']';
			expr_index -= 2;
		}

		/* '!' '=' --> '~', etc. */
		if (TOKEN (-1) == '!') {
			switch (token) {
			case '=':
				token = '~';
				expr_index--;
				break;
			case '~':
				token = '=';
				expr_index--;
				break;
			case '<':
				token = ']';
				expr_index--;
				break;
			case '>':
				token = '[';
				expr_index--;
				break;
			case '[':
				token = '>';
				expr_index--;
				break;
			case ']':
				token = '<';
				expr_index--;
				break;
			default:
				break;
			}
		}
		break;
	}

	/* Reduce */
	/* Catch invalid condition */
	if (expr_reduce (token) > 0) {
		return;
	}

	/* Allocate sufficient stack memory */
	if (expr_index >= expr_stack_size) {
		while (expr_stack_size <= expr_index) {
			expr_stack_size *= 2;
		}
		expr_stack = cobc_main_realloc (expr_stack, sizeof (struct expr_node) * expr_stack_size);
	}

	/* Put on the stack */
	TOKEN (0) = token;
	VALUE (0) = value;
	expr_index++;
}

static void
expr_expand (cb_tree *x)
{
	struct cb_binary_op	*p;

start:
	/* Remove parenthesis */
	if (CB_BINARY_OP_P (*x)) {
		p = CB_BINARY_OP (*x);
		if (p->op == '@') {
			*x = p->x;
			goto start;
		}
		expr_expand (&p->x);
		if (p->y) {
			expr_expand (&p->y);
		}
	}
}

static cb_tree
cb_expr_finish (void)
{
	/* Reduce all */
	(void)expr_reduce (0);

	if (expr_index != 4) {
		cb_error (_("Invalid expression"));
		return cb_error_node;
	}

	if (!expr_stack[3].value) {
		cb_error (_("Invalid expression"));
		return cb_error_node;
	}
	expr_expand (&expr_stack[3].value);
	if (expr_stack[3].token != 'x') {
		cb_error (_("Invalid expression"));
		return cb_error_node;
	}
	return expr_stack[3].value;
}

cb_tree
cb_build_expr (cb_tree list)
{
	cb_tree	l;
	int	op;

	cb_expr_init ();

	for (l = list; l; l = CB_CHAIN (l)) {
		op = CB_PURPOSE_INT (l);
		switch (op) {
		case '9':
			/* NUMERIC */
			cb_expr_shift_class ("cob_is_numeric");
			break;
		case 'A':
			/* ALPHABETIC */
			cb_expr_shift_class ("cob_is_alpha");
			break;
		case 'L':
			/* ALPHABETIC_LOWER */
			cb_expr_shift_class ("cob_is_lower");
			break;
		case 'U':
			/* ALPHABETIC_UPPER */
			cb_expr_shift_class ("cob_is_upper");
			break;
		case 'P':
			/* POSITIVE */
			cb_expr_shift_sign ('>');
			break;
		case 'N':
			/* NEGATIVE */
			cb_expr_shift_sign ('<');
			break;
		case 'O':
			/* OMITTED */
			if (current_statement) {
				current_statement->null_check = NULL;
			}
			cb_expr_shift_class ("cob_is_omitted");
			break;
		case 'C':
			/* CLASS */
			cb_expr_shift_class (CB_CLASS_NAME (cb_ref (CB_VALUE (l)))->cname);
			break;
		default:
			cb_expr_shift (op, CB_VALUE (l));
			break;
		}
	}

	return cb_expr_finish ();
}

/* Numerical operation */

static cb_tree
build_store_option (cb_tree x, cb_tree round_opt)
{
	struct cb_field	*f;
	int		opt;
	enum cb_usage	usage;

	f = CB_FIELD_PTR (x);
	usage = f->usage;
#if	0	/* RXWRXW - FP */
	if (usage == CB_USAGE_DOUBLE || usage == CB_USAGE_FLOAT) {
		/* Rounding on FP is useless */
		opt = 0;
	} else {
#endif
		opt = CB_INTEGER (round_opt)->val;
#if	0	/* RXWRXW - FP */
	}
#endif

	if (usage == CB_USAGE_COMP_5 || usage == CB_USAGE_COMP_X) {
		/* Do not check NOT ERROR case, so that we optimize */
		if (current_statement->handler1) {
			opt |= COB_STORE_KEEP_ON_OVERFLOW;
		}
	} else if (current_statement->handler_id) {
		/* There is a [NOT] ERROR/OVERFLOW/EXCEPTION - Set in parser */
		opt |= COB_STORE_KEEP_ON_OVERFLOW;
	} else if (usage == CB_USAGE_BINARY && cb_binary_truncate) {
		/* Truncate binary field to digits in picture */
		opt |= COB_STORE_TRUNC_ON_OVERFLOW;
	}

	return cb_int (opt);
}

static cb_tree
decimal_alloc (void)
{
	cb_tree x;

	x = cb_build_decimal (current_program->decimal_index);
	current_program->decimal_index++;
	if (current_program->decimal_index >= COB_MAX_DEC_STRUCT) {
		cobc_abort_pr (_("Internal decimal structure size exceeded - %d"),
				COB_MAX_DEC_STRUCT);
		COBC_ABORT ();
	}
	if (current_program->decimal_index > current_program->decimal_index_max) {
		current_program->decimal_index_max = current_program->decimal_index;
	}
	return x;
}

static void
decimal_free (void)
{
	current_program->decimal_index--;
}

static void
decimal_compute (const int op, cb_tree x, cb_tree y)
{
	const char *func;

	switch (op) {
	case '+':
		func = "cob_decimal_add";
		break;
	case '-':
		func = "cob_decimal_sub";
		break;
	case '*':
		func = "cob_decimal_mul";
		break;
	case '/':
		func = "cob_decimal_div";
		break;
	case '^':
		func = "cob_decimal_pow";
		break;
	default:
		cobc_abort_pr (_("Unexpected operation %d"), op);
		COBC_ABORT ();
	}
	dpush (CB_BUILD_FUNCALL_2 (func, x, y));
}

static void
decimal_expand (cb_tree d, cb_tree x)
{
	struct cb_literal	*l;
	struct cb_field		*f;
	struct cb_binary_op	*p;
	cb_tree			t;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x == cb_zero) {
			dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_set_llint", d,
				cb_int0));
		} else {
			cobc_abort_pr (_("Unexpected constant expansion"));
			COBC_ABORT ();
		}
		break;
	case CB_TAG_LITERAL:
		/* Set d, N */
		l = CB_LITERAL (x);
		if (l->size < 19 && l->scale == 0) {
			dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_set_llint", d,
				cb_build_cast_llint (x)));
		} else {
			dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_set_field", d, x));
		}
		break;
	case CB_TAG_REFERENCE:
		/* Set d, X */
		f = CB_FIELD_PTR (x);
		/* Check numeric */
		if (cb_flag_correct_numeric && f->usage == CB_USAGE_DISPLAY) {
			cb_emit (CB_BUILD_FUNCALL_1 ("cob_correct_numeric", x));
		}
		if (CB_EXCEPTION_ENABLE (COB_EC_DATA_INCOMPATIBLE)) {
			if (f->usage == CB_USAGE_DISPLAY ||
			    f->usage == CB_USAGE_PACKED ||
			    f->usage == CB_USAGE_COMP_6) {
				dpush (CB_BUILD_FUNCALL_2 ("cob_check_numeric",
							   x, CB_BUILD_STRING0 (f->name)));
			}
		}

		if ((f->usage == CB_USAGE_BINARY ||
		    f->usage == CB_USAGE_COMP_5 ||
		    f->usage == CB_USAGE_INDEX ||
		    f->usage == CB_USAGE_COMP_X) &&
		    !f->pic->scale &&
		    (f->size == 1 || f->size == 2 || f->size == 4 ||
		     f->size == 8)) {
			dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_set_llint", d, cb_build_cast_llint (x)));
		} else {
			dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_set_field", d, x));
		}
		break;
	case CB_TAG_BINARY_OP:
		/* Set d, X
		 * Set t, Y
		 * OP d, t */
		p = CB_BINARY_OP (x);
		t = decimal_alloc ();
		decimal_expand (d, p->x);
		decimal_expand (t, p->y);
		decimal_compute (p->op, d, t);
		decimal_free ();
		break;
	case CB_TAG_INTRINSIC:
		dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_set_field", d, x));
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

static void
decimal_assign (cb_tree x, cb_tree d, cb_tree round_opt)
{
	dpush (CB_BUILD_FUNCALL_3 ("cob_decimal_get_field", d, x,
				   build_store_option (x, round_opt)));
}

static cb_tree
cb_build_mul (cb_tree v, cb_tree n, cb_tree round_opt)
{
	cb_tree		opt;
	struct cb_field	*f;

	if (CB_INDEX_P (v)) {
		return cb_build_move (cb_build_binary_op (v, '*', n), v);
	}

	if (CB_REF_OR_FIELD_P (v)) {
		f = CB_FIELD_PTR (v);
		f->count++;
	}
	if (CB_REF_OR_FIELD_P (n)) {
		f = CB_FIELD_PTR (n);
		f->count++;
	}
	opt = build_store_option (v, round_opt);
	return CB_BUILD_FUNCALL_3 ("cob_mul", v, n, opt);
}

static cb_tree
cb_build_div (cb_tree v, cb_tree n, cb_tree round_opt)
{
	cb_tree		opt;
	struct cb_field	*f;

	if (CB_INDEX_P (v)) {
		return cb_build_move (cb_build_binary_op (v, '/', n), v);
	}

	if (CB_REF_OR_FIELD_P (v)) {
		f = CB_FIELD_PTR (v);
		f->count++;
	}
	if (CB_REF_OR_FIELD_P (n)) {
		f = CB_FIELD_PTR (n);
		f->count++;
	}
	opt = build_store_option (v, round_opt);
	return CB_BUILD_FUNCALL_3 ("cob_div", v, n, opt);
}

static cb_tree
build_decimal_assign (cb_tree vars, const int op, cb_tree val)
{
	cb_tree	l;
	cb_tree	t;
	cb_tree	s1;
	cb_tree	s2;
	cb_tree	d;

	d = decimal_alloc ();

	/* Set d, VAL */
	decimal_expand (d, val);

	s1 = NULL;
	if (op == 0) {
		for (l = vars; l; l = CB_CHAIN (l)) {
			/* Set VAR, d */
			decimal_assign (CB_VALUE (l), d, CB_PURPOSE (l));
			s2 = cb_list_reverse (decimal_stack);
			if (!s1) {
				s1 = s2;
			} else {
				s1 = cb_list_append (s1, s2);
			}
			decimal_stack = NULL;
		}
	} else {
		t = decimal_alloc ();
		for (l = vars; l; l = CB_CHAIN (l)) {
			/* Set t, VAR
			 * OP t, d
			 * set VAR, t
			 */
			decimal_expand (t, CB_VALUE (l));
			decimal_compute (op, t, d);
			decimal_assign (CB_VALUE (l), t, CB_PURPOSE (l));
			s2 = cb_list_reverse (decimal_stack);
			if (!s1) {
				s1 = s2;
			} else {
				s1 = cb_list_append (s1, s2);
			}
			decimal_stack = NULL;
		}
		decimal_free ();
	}

	decimal_free ();

	return s1;
}

void
cb_emit_arithmetic (cb_tree vars, const int op, cb_tree val)
{
	cb_tree		l;
	cb_tree		x;

	x = cb_check_numeric_value (val);

	if (op) {
		cb_list_map (cb_check_numeric_name, vars);
	} else {
		cb_list_map (cb_check_numeric_edited_name, vars);
	}

	if (cb_validate_one (x)) {
		return;
	}
	if (cb_validate_list (vars)) {
		return;
	}

	if (!CB_BINARY_OP_P (x)) {
		if (op == '+' || op == '-' || op == '*' || op == '/') {
			cb_check_data_incompat (x);
			for (l = vars; l; l = CB_CHAIN (l)) {
				cb_check_data_incompat (CB_VALUE (l));
				switch (op) {
				case '+':
					CB_VALUE (l) = cb_build_add (CB_VALUE (l), x, CB_PURPOSE (l));
					break;
				case '-':
					CB_VALUE (l) = cb_build_sub (CB_VALUE (l), x, CB_PURPOSE (l));
					break;
				case '*':
					CB_VALUE (l) = cb_build_mul (CB_VALUE (l), x, CB_PURPOSE (l));
					break;
				case '/':
					CB_VALUE (l) = cb_build_div (CB_VALUE (l), x, CB_PURPOSE (l));
					break;
				}
			}
			cb_emit_list (vars);
			return;
		}
	}
	if (x == cb_error_node) {
		return;
	}

	cb_emit_list (build_decimal_assign (vars, op, x));
}

/* Condition */

static cb_tree
build_cond_88 (cb_tree x)
{
	struct cb_field	*f;
	cb_tree		l;
	cb_tree		t;
	cb_tree		c1;
	cb_tree		c2;

	f = CB_FIELD_PTR (x);
	/* Refer to parents data storage */
	if (!f->parent) {
		/* Field is invalid */
		return cb_error_node;
	}
	x = cb_build_field_reference (f->parent, x);
	f->parent->count++;
	c1 = NULL;

	/* Build condition */
	for (l = f->values; l; l = CB_CHAIN (l)) {
		t = CB_VALUE (l);
		if (CB_PAIR_P (t)) {
			/* VALUE THRU VALUE */
			c2 = cb_build_binary_op (cb_build_binary_op (CB_PAIR_X (t), '[', x),
						 '&', cb_build_binary_op (x, '[', CB_PAIR_Y (t)));
		} else {
			/* VALUE */
			c2 = cb_build_binary_op (x, '=', t);
		}
		if (c1 == NULL) {
			c1 = c2;
		} else {
			c1 = cb_build_binary_op (c1, '|', c2);
		}
	}
	return c1;
}

static cb_tree
cb_build_optim_cond (struct cb_binary_op *p)
{
	struct cb_field	*f;
	const char	*s;
	size_t		n;

#if	0	/* RXWRXW - US */
	struct cb_field	*fy;
	if (CB_REF_OR_FIELD_P (p->y)) {
		fy = CB_FIELD_PTR (p->y);
		if (!fy->pic->have_sign && (fy->usage == CB_USAGE_BINARY ||
		    fy->usage == CB_USAGE_COMP_5 ||
		    fy->usage == CB_USAGE_COMP_X)) {
			return CB_BUILD_FUNCALL_2 ("cob_cmp_uint", p->x,
						   cb_build_cast_int (p->y));
		}
	}
#endif

	if (!CB_REF_OR_FIELD_P (p->x)) {
		return CB_BUILD_FUNCALL_2 ("cob_cmp_llint", p->x,
					    cb_build_cast_llint (p->y));
	}

	f = CB_FIELD_PTR (p->x);
#if	0	/* RXWRXW - SI */
	if (f->special_index) {
		return CB_BUILD_FUNCALL_2 ("cob_cmp_special",
			cb_build_cast_int (p->x),
			cb_build_cast_int (p->y));
	}
#endif
	if (f->pic->scale || f->flag_any_numeric) {
		return CB_BUILD_FUNCALL_2 ("cob_cmp_llint", p->x,
					    cb_build_cast_llint (p->y));
	}
	if (f->usage == CB_USAGE_PACKED) {
		if (f->pic->digits < 19) {
			optimize_defs[COB_CMP_PACKED_INT] = 1;
			return CB_BUILD_FUNCALL_2 ("cob_cmp_packed_int",
				p->x,
				cb_build_cast_llint (p->y));
		} else {
			return CB_BUILD_FUNCALL_2 ("cob_cmp_packed",
				p->x,
				cb_build_cast_llint (p->y));
		}
	}
	if (f->usage == CB_USAGE_COMP_6) {
		return CB_BUILD_FUNCALL_2 ("cob_cmp_packed",
			p->x,
			cb_build_cast_llint (p->y));
	}
	if (f->usage == CB_USAGE_DISPLAY &&
	    !f->flag_sign_leading && !f->flag_sign_separate) {
		if (cb_fits_long_long (p->x)) {
			return CB_BUILD_FUNCALL_4 ("cob_cmp_numdisp",
				CB_BUILD_CAST_ADDRESS (p->x),
				cb_int (f->size),
				cb_build_cast_llint (p->y),
				cb_int (f->pic->have_sign ? 1 : 0));
		}
		return CB_BUILD_FUNCALL_2 ("cob_cmp_llint", p->x,
					    cb_build_cast_llint (p->y));
	}
	if (f->usage == CB_USAGE_BINARY ||
	    f->usage == CB_USAGE_COMP_5 ||
	    f->usage == CB_USAGE_INDEX ||
	    f->usage == CB_USAGE_COMP_X) {
		n = (f->size - 1) + (8 * (f->pic->have_sign ? 1 : 0)) +
			(16 * (f->flag_binary_swap ? 1 : 0));
#if	defined(COB_NON_ALIGNED) && !defined(_MSC_VER)
		switch (f->size) {
		case 2:
#ifdef	COB_SHORT_BORK
			optimize_defs[bin_compare_funcs[n].optim_val] = 1;
			s = bin_compare_funcs[n].optim_name;
			break;
#endif
		case 4:
		case 8:
			if (f->storage != CB_STORAGE_LINKAGE &&
			    f->indexes == 0 && (f->offset % f->size) == 0) {
				optimize_defs[align_bin_compare_funcs[n].optim_val] = 1;
				s = align_bin_compare_funcs[n].optim_name;
			} else {
				optimize_defs[bin_compare_funcs[n].optim_val] = 1;
				s = bin_compare_funcs[n].optim_name;
			}
			break;
		default:
			optimize_defs[bin_compare_funcs[n].optim_val] = 1;
			s = bin_compare_funcs[n].optim_name;
			break;
		}
#else
		optimize_defs[bin_compare_funcs[n].optim_val] = 1;
		s = bin_compare_funcs[n].optim_name;
#endif
		if (s) {
			return CB_BUILD_FUNCALL_2 (s,
				CB_BUILD_CAST_ADDRESS (p->x),
				cb_build_cast_llint (p->y));
		}
	}
	return CB_BUILD_FUNCALL_2 ("cob_cmp_llint", p->x,
				   cb_build_cast_llint (p->y));
}

static int
cb_chk_num_cond (cb_tree x, cb_tree y)
{
	struct cb_field		*fx;
	struct cb_field		*fy;

	if (!CB_REF_OR_FIELD_P (x)) {
		return 0;
	}
	if (!CB_REF_OR_FIELD_P (y)) {
		return 0;
	}
	if (CB_TREE_CATEGORY (x) != CB_CATEGORY_NUMERIC) {
		return 0;
	}
	if (CB_TREE_CATEGORY (y) != CB_CATEGORY_NUMERIC) {
		return 0;
	}
	if (CB_TREE_CLASS (x) != CB_CLASS_NUMERIC) {
		return 0;
	}
	if (CB_TREE_CLASS (y) != CB_CLASS_NUMERIC) {
		return 0;
	}
	fx = CB_FIELD_PTR (x);
	fy = CB_FIELD_PTR (y);
	if (fx->usage != CB_USAGE_DISPLAY) {
		return 0;
	}
	if (fy->usage != CB_USAGE_DISPLAY) {
		return 0;
	}
	if (fx->pic->have_sign || fy->pic->have_sign) {
		return 0;
	}
	if (fx->size != fy->size) {
		return 0;
	}
	if (fx->pic->scale != fy->pic->scale) {
		return 0;
	}
	return 1;
}

static int
cb_chk_alpha_cond (cb_tree x)
{
	if (current_program->alphabet_name_list) {
		return 0;
	}
	if (CB_LITERAL_P (x)) {
		return 1;
	}
	if (!CB_REF_OR_FIELD_P (x)) {
		return 0;
	}
	if (CB_TREE_CATEGORY (x) != CB_CATEGORY_ALPHANUMERIC &&
	    CB_TREE_CATEGORY (x) != CB_CATEGORY_ALPHABETIC) {
		return 0;
	}
	if (cb_field_variable_size (CB_FIELD_PTR (x))) {
		return 0;
	}
	if (cb_field_size (x) < 0) {
		return 0;
	}
	return 1;
}

cb_tree
cb_build_cond (cb_tree x)
{
	struct cb_field		*f;
	struct cb_binary_op	*p;
	cb_tree			d1;
	cb_tree			d2;
	int			size1;
	int			size2;

	if (x == cb_error_node) {
		return cb_error_node;
	}
	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x != cb_any && x != cb_true && x != cb_false) {
			cb_error_x (CB_TREE(current_statement),
				    _("Invalid expression"));
			return cb_error_node;
		}
		return x;
	case CB_TAG_FUNCALL:
		return x;
	case CB_TAG_REFERENCE:
		if (!CB_FIELD_P (cb_ref (x))) {
			return cb_build_cond (cb_ref (x));
		}

		f = CB_FIELD_PTR (x);

		/* Level 88 condition */
		if (f->level == 88) {
			/* Build an 88 condition at every occurrence */
			/* as it may be subscripted */
			return cb_build_cond (build_cond_88 (x));
		}

		cb_error_x (x, _("Invalid expression"));
		return cb_error_node;
	case CB_TAG_BINARY_OP:
		p = CB_BINARY_OP (x);
		if (!p->x || p->x == cb_error_node) {
			return cb_error_node;
		}
		switch (p->op) {
		case '!':
			return CB_BUILD_NEGATION (cb_build_cond (p->x));
		case '&':
		case '|':
			if (!p->y || p->y == cb_error_node) {
				return cb_error_node;
			}
			return cb_build_binary_op (cb_build_cond (p->x), p->op, cb_build_cond (p->y));
		default:
			if (!p->y || p->y == cb_error_node) {
				return cb_error_node;
			}
			if (CB_INDEX_P (p->x) || CB_INDEX_P (p->y) ||
			    CB_TREE_CLASS (p->x) == CB_CLASS_POINTER ||
			    CB_TREE_CLASS (p->y) == CB_CLASS_POINTER) {
				x = cb_build_binary_op (p->x, '-', p->y);
			} else if (CB_BINARY_OP_P (p->x) ||
				   CB_BINARY_OP_P (p->y)) {
				/* Decimal comparison */
				d1 = decimal_alloc ();
				d2 = decimal_alloc ();

				decimal_expand (d1, p->x);
				decimal_expand (d2, p->y);
				dpush (CB_BUILD_FUNCALL_2 ("cob_decimal_cmp", d1, d2));
				decimal_free ();
				decimal_free ();
				x = cb_list_reverse (decimal_stack);
				decimal_stack = NULL;
			} else {
				/* DEBUG Bypass optimization for PERFORM */
				if (current_program->flag_debugging) {
					x = CB_BUILD_FUNCALL_2 ("cob_cmp", p->x, p->y);
					break;
				}
				if (cb_chk_num_cond (p->x, p->y)) {
					size1 = cb_field_size (p->x);
					x = CB_BUILD_FUNCALL_3 ("memcmp",
						CB_BUILD_CAST_ADDRESS (p->x),
						CB_BUILD_CAST_ADDRESS (p->y),
						cb_int (size1));
					break;
				}
				if (CB_TREE_CLASS (p->x) == CB_CLASS_NUMERIC &&
				    CB_TREE_CLASS (p->y) == CB_CLASS_NUMERIC &&
				    cb_fits_long_long (p->y)) {
					x = cb_build_optim_cond (p);
					break;
				}

				/* Field comparison */
				if ((CB_REF_OR_FIELD_P (p->x)) &&
				    (CB_TREE_CATEGORY (p->x) == CB_CATEGORY_ALPHANUMERIC ||
				     CB_TREE_CATEGORY (p->x) == CB_CATEGORY_ALPHABETIC) &&
				    cb_field_size (p->x) == 1 &&
				    !current_program->alphabet_name_list &&
				    (p->y == cb_space || p->y == cb_low ||
				     p->y == cb_high || p->y == cb_zero)) {
					x = CB_BUILD_FUNCALL_2 ("$G", p->x, p->y);
					break;
				}
				if (cb_chk_alpha_cond (p->x) &&
				    cb_chk_alpha_cond (p->y)) {
					size1 = cb_field_size (p->x);
					size2 = cb_field_size (p->y);
				} else {
					size1 = 0;
					size2 = 0;
				}
				if (size1 == 1 && size2 == 1) {
					x = CB_BUILD_FUNCALL_2 ("$G", p->x, p->y);
				} else if (size1 != 0 && size1 == size2) {
					x = CB_BUILD_FUNCALL_3 ("memcmp",
						CB_BUILD_CAST_ADDRESS (p->x),
						CB_BUILD_CAST_ADDRESS (p->y),
						cb_int (size1));
				} else {
					if (CB_TREE_CLASS (p->x) == CB_CLASS_NUMERIC && p->y == cb_zero) {
						x = cb_build_optim_cond (p);
					} else {
						x = CB_BUILD_FUNCALL_2 ("cob_cmp", p->x, p->y);
					}
				}
			}
		}
		return cb_build_binary_op (x, p->op, p->y);
	default:
		break;
	}
	cb_error_x (x, _("Invalid expression"));
	return cb_error_node;
}

/* ADD/SUBTRACT CORRESPONDING */

static cb_tree
cb_build_optim_add (cb_tree v, cb_tree n)
{
	size_t		z;
	const char	*s;
	struct cb_field	*f;

	if (CB_REF_OR_FIELD_P (v)) {
		f = CB_FIELD_PTR (v);
		if (!f->pic) {
			return CB_BUILD_FUNCALL_3 ("cob_add_int", v,
						   cb_build_cast_int (n),
						   cb_int0);
		}
		if (!f->pic->scale && (f->usage == CB_USAGE_BINARY ||
		    f->usage == CB_USAGE_COMP_5 ||
		    f->usage == CB_USAGE_COMP_X)) {
			z = (f->size - 1) + (8 * (f->pic->have_sign ? 1 : 0)) +
				(16 * (f->flag_binary_swap ? 1 : 0));
#if	defined(COB_NON_ALIGNED) && !defined(_MSC_VER)
			switch (f->size) {
			case 2:
#ifdef	COB_SHORT_BORK
				optimize_defs[bin_add_funcs[z].optim_val] = 1;
				s = bin_add_funcs[z].optim_name;
				break;
#endif
			case 4:
			case 8:
				if (f->storage != CB_STORAGE_LINKAGE &&
				    f->indexes == 0 &&
				    (f->offset % f->size) == 0) {
					optimize_defs[align_bin_add_funcs[z].optim_val] = 1;
					s = align_bin_add_funcs[z].optim_name;
				} else {
					optimize_defs[bin_add_funcs[z].optim_val] = 1;
					s = bin_add_funcs[z].optim_name;
				}
				break;
			default:
				optimize_defs[bin_add_funcs[z].optim_val] = 1;
				s = bin_add_funcs[z].optim_name;
				break;
			}
#else
			if (f->usage == CB_USAGE_COMP_5) {
				switch (f->size) {
				case 1:
				case 2:
				case 4:
				case 8:
					return cb_build_assign (v, cb_build_binary_op (v, '+', n));
				default:
					break;
				}
			}
			optimize_defs[bin_add_funcs[z].optim_val] = 1;
			s = bin_add_funcs[z].optim_name;
#endif
			if (s) {
				return CB_BUILD_FUNCALL_2 (s,
					CB_BUILD_CAST_ADDRESS (v),
					cb_build_cast_int (n));
			}
		} else if (!f->pic->scale && f->usage == CB_USAGE_PACKED &&
			   f->pic->digits < 10) {
			optimize_defs[COB_ADD_PACKED_INT] = 1;
			return CB_BUILD_FUNCALL_2 ("cob_add_packed_int",
				v, cb_build_cast_int (n));
		}
	}
	return CB_BUILD_FUNCALL_3 ("cob_add_int", v,
				   cb_build_cast_int (n), cb_int0);
}

static cb_tree
cb_build_optim_sub (cb_tree v, cb_tree n)
{
	size_t		z;
	const char	*s;
	struct cb_field	*f;

	if (CB_REF_OR_FIELD_P (v)) {
		f = CB_FIELD_PTR (v);
		if (!f->pic->scale && (f->usage == CB_USAGE_BINARY ||
		    f->usage == CB_USAGE_COMP_5 ||
		    f->usage == CB_USAGE_COMP_X)) {
			z = (f->size - 1) + (8 * (f->pic->have_sign ? 1 : 0)) +
				(16 * (f->flag_binary_swap ? 1 : 0));
#if	defined(COB_NON_ALIGNED) && !defined(_MSC_VER)
			switch (f->size) {
			case 2:
#ifdef	COB_SHORT_BORK
				optimize_defs[bin_sub_funcs[z].optim_val] = 1;
				s = bin_sub_funcs[z].optim_name;
				break;
#endif
			case 4:
			case 8:
				if (f->storage != CB_STORAGE_LINKAGE &&
				    f->indexes == 0 && (f->offset % f->size) == 0) {
					optimize_defs[align_bin_sub_funcs[z].optim_val] = 1;
					s = align_bin_sub_funcs[z].optim_name;
				} else {
					optimize_defs[bin_sub_funcs[z].optim_val] = 1;
					s = bin_sub_funcs[z].optim_name;
				}
				break;
			default:
				optimize_defs[bin_sub_funcs[z].optim_val] = 1;
				s = bin_sub_funcs[z].optim_name;
				break;
			}
#else
			if (f->usage == CB_USAGE_COMP_5) {
				switch (f->size) {
				case 1:
				case 2:
				case 4:
				case 8:
					return cb_build_assign (v, cb_build_binary_op (v, '-', n));
				default:
					break;
				}
			}
			optimize_defs[bin_sub_funcs[z].optim_val] = 1;
			s = bin_sub_funcs[z].optim_name;
#endif
			if (s) {
				return CB_BUILD_FUNCALL_2 (s,
					CB_BUILD_CAST_ADDRESS (v),
					cb_build_cast_int (n));
			}
		}
	}
	return CB_BUILD_FUNCALL_3 ("cob_sub_int", v,
				   cb_build_cast_int (n), cb_int0);
}

cb_tree
cb_build_add (cb_tree v, cb_tree n, cb_tree round_opt)
{
	cb_tree		opt;
	struct cb_field	*f;

#ifdef	COB_NON_ALIGNED
	if (CB_INDEX_P (v)) {
		return cb_build_move (cb_build_binary_op (v, '+', n), v);
	}
	if (CB_TREE_CLASS (v) == CB_CLASS_POINTER) {
		optimize_defs[COB_POINTER_MANIP] = 1;
		return CB_BUILD_FUNCALL_3 ("cob_pointer_manip", v, n, cb_int0);
	}
#else
	if (CB_INDEX_P (v) || CB_TREE_CLASS (v) == CB_CLASS_POINTER) {
		return cb_build_move (cb_build_binary_op (v, '+', n), v);
	}
#endif

	if (CB_REF_OR_FIELD_P (v)) {
		f = CB_FIELD_PTR (v);
		f->count++;
	}
	if (CB_REF_OR_FIELD_P (n)) {
		f = CB_FIELD_PTR (n);
		f->count++;
	}
	if (round_opt == cb_high) {
		/* Short circuit from tree.c for perform */
		if (cb_fits_int (n)) {
			return cb_build_optim_add (v, n);
		} else {
			return CB_BUILD_FUNCALL_3 ("cob_add", v, n, cb_int0);
		}
	}
	opt = build_store_option (v, round_opt);
	if (opt == cb_int0 && cb_fits_int (n)) {
		return cb_build_optim_add (v, n);
	}
	return CB_BUILD_FUNCALL_3 ("cob_add", v, n, opt);
}

cb_tree
cb_build_sub (cb_tree v, cb_tree n, cb_tree round_opt)
{
	cb_tree		opt;
	struct cb_field	*f;

#ifdef	COB_NON_ALIGNED
	if (CB_INDEX_P (v)) {
		return cb_build_move (cb_build_binary_op (v, '-', n), v);
	}
	if (CB_TREE_CLASS (v) == CB_CLASS_POINTER) {
		optimize_defs[COB_POINTER_MANIP] = 1;
		return CB_BUILD_FUNCALL_3 ("cob_pointer_manip", v, n, cb_int1);
	}
#else
	if (CB_INDEX_P (v) || CB_TREE_CLASS (v) == CB_CLASS_POINTER) {
		return cb_build_move (cb_build_binary_op (v, '-', n), v);
	}
#endif

	if (CB_REF_OR_FIELD_P (v)) {
		f = CB_FIELD_PTR (v);
		f->count++;
	}
	if (CB_REF_OR_FIELD_P (n)) {
		f = CB_FIELD_PTR (n);
		f->count++;
	}
	opt = build_store_option (v, round_opt);
	if (opt == cb_int0 && cb_fits_int (n)) {
		return cb_build_optim_sub (v, n);
	}
	return CB_BUILD_FUNCALL_3 ("cob_sub", v, n, opt);
}

static unsigned int
emit_corresponding (cb_tree (*func) (cb_tree f1, cb_tree f2, cb_tree f3),
		    cb_tree x1, cb_tree x2, cb_tree opt)
{
	struct cb_field *f1, *f2;
	cb_tree		t1;
	cb_tree		t2;
	unsigned int	found;

	found = 0;
	for (f1 = CB_FIELD_PTR (x1)->children; f1; f1 = f1->sister) {
		if (!f1->redefines && !f1->flag_occurs) {
			for (f2 = CB_FIELD_PTR (x2)->children; f2; f2 = f2->sister) {
				if (!f2->redefines && !f2->flag_occurs) {
					if (strcmp (f1->name, f2->name) == 0) {
						t1 = cb_build_field_reference (f1, x1);
						t2 = cb_build_field_reference (f2, x2);
						if (f1->children && f2->children) {
							found += emit_corresponding (func, t1, t2, opt);
						} else {
							found++;
							cb_emit (func (t1, t2, opt));
						}
					}
				}
			}
		}
	}
	return found;
}

void
cb_emit_corresponding (cb_tree (*func) (cb_tree f1, cb_tree f2, cb_tree f3),
		       cb_tree x1, cb_tree x2, cb_tree opt)
{
	x1 = cb_check_group_name (x1);
	x2 = cb_check_group_name (x2);

	if (cb_validate_one (x1)) {
		return;
	}
	if (cb_validate_one (x2)) {
		return;
	}

	if (!emit_corresponding (func, x1, x2, opt)) {
		if (cb_warn_corresponding) {
			cb_warning_x (x2, _("No CORRESPONDING items found"));
		}
	}
}

static unsigned int
emit_move_corresponding (cb_tree x1, cb_tree x2)
{
	struct cb_field *f1, *f2;
	cb_tree		t1;
	cb_tree		t2;
	unsigned int	found;

	found = 0;
	for (f1 = CB_FIELD_PTR (x1)->children; f1; f1 = f1->sister) {
		if (!f1->redefines && !f1->flag_occurs) {
			for (f2 = CB_FIELD_PTR (x2)->children; f2; f2 = f2->sister) {
				if (!f2->redefines && !f2->flag_occurs) {
					if (strcmp (f1->name, f2->name) == 0) {
						t1 = cb_build_field_reference (f1, x1);
						t2 = cb_build_field_reference (f2, x2);
						if (f1->children && f2->children) {
							found += emit_move_corresponding (t1, t2);
						} else {
							cb_emit (cb_build_move (t1, t2));
							found++;
						}
					}
				}
			}
		}
	}
	return found;
}

void
cb_emit_move_corresponding (cb_tree x1, cb_tree x2)
{
	cb_tree		l;
	cb_tree		v;

	x1 = cb_check_group_name (x1);
	if (cb_validate_one (x1)) {
		return;
	}
	for (l = x2; l; l = CB_CHAIN(l)) {
		v = CB_VALUE(l);
		v = cb_check_group_name (v);
		if (cb_validate_one (v)) {
			return;
		}
		if (!emit_move_corresponding (x1, v)) {
			if (cb_warn_corresponding) {
				cb_warning_x (v, _("No CORRESPONDING items found"));
			}
		}
	}
}

static void
output_screen_from (struct cb_field *p, const unsigned int sisters)
{
	int type;

	if (sisters && p->sister) {
		output_screen_from (p->sister, 1U);
	}
	if (p->children) {
		output_screen_from (p->children, 1U);
	}

	type = (p->children ? COB_SCREEN_TYPE_GROUP :
		p->values ? COB_SCREEN_TYPE_VALUE :
		(p->size > 0) ? COB_SCREEN_TYPE_FIELD : COB_SCREEN_TYPE_ATTRIBUTE);
	if (type == COB_SCREEN_TYPE_FIELD && p->screen_from) {
		/* Bump reference count */
		p->count++;
		cb_emit (CB_BUILD_FUNCALL_2 ("cob_move", p->screen_from,
					     CB_TREE (p)));
	}
}

static void
output_screen_to (struct cb_field *p, const unsigned int sisters)
{
	int type;

	if (sisters && p->sister) {
		output_screen_to (p->sister, 1U);
	}
	if (p->children) {
		output_screen_to (p->children, 1U);
	}

	type = (p->children ? COB_SCREEN_TYPE_GROUP :
		p->values ? COB_SCREEN_TYPE_VALUE :
		(p->size > 0) ? COB_SCREEN_TYPE_FIELD : COB_SCREEN_TYPE_ATTRIBUTE);
	if (type == COB_SCREEN_TYPE_FIELD && p->screen_to) {
		/* Bump reference count */
		p->count++;
		cb_emit (CB_BUILD_FUNCALL_2 ("cob_move", CB_TREE (p), p->screen_to));
	}
}

/* ACCEPT statement */

static void
cb_gen_field_accept (cb_tree var, cb_tree pos, cb_tree fgc, cb_tree bgc,
		     cb_tree scroll, cb_tree timeout, cb_tree prompt,
		     int dispattrs)
{
	cb_tree		line;
	cb_tree		column;

	if (!pos) {
		cb_emit (CB_BUILD_FUNCALL_9 ("cob_field_accept",
			var, NULL, NULL, fgc, bgc, scroll,
			timeout, prompt, cb_int (dispattrs)));
	} else if (CB_LIST_P (pos)) {
		line = CB_PAIR_X (pos);
		column = CB_PAIR_Y (pos);
		cb_emit (CB_BUILD_FUNCALL_9 ("cob_field_accept",
			var, line, column, fgc, bgc, scroll,
			timeout, prompt, cb_int (dispattrs)));
	} else {
		cb_emit (CB_BUILD_FUNCALL_9 ("cob_field_accept",
			var, pos, NULL, fgc, bgc, scroll,
			timeout, prompt, cb_int (dispattrs)));
	}
}

void
cb_emit_accept (cb_tree var, cb_tree pos, struct cb_attr_struct *attr_ptr)
{
	cb_tree		line;
	cb_tree		column;
	cb_tree		fgc;
	cb_tree		bgc;
	cb_tree		scroll;
	cb_tree		timeout;
	cb_tree		prompt;
	int		dispattrs;

	if (attr_ptr) {
		fgc = attr_ptr->fgc;
		bgc = attr_ptr->bgc;
		scroll = attr_ptr->scroll;
		timeout = attr_ptr->timeout;
		prompt = attr_ptr->prompt;
		dispattrs = attr_ptr->dispattrs;
	} else {
		fgc = NULL;
		bgc = NULL;
		scroll = NULL;
		timeout = NULL;
		prompt = NULL;
		dispattrs = 0;
	}

	if (cb_validate_one (var)) {
		return;
	}
	if (cb_validate_one (pos)) {
		return;
	}
	if (cb_validate_one (fgc)) {
		return;
	}
	if (cb_validate_one (bgc)) {
		return;
	}
	if (cb_validate_one (scroll)) {
		return;
	}
	if (cb_validate_one (timeout)) {
		return;
	}
	if (cb_validate_one (prompt)) {
		return;
	}

	if (prompt) {
		/* PROMPT character - 1 character identifier or literal */
		if (CB_LITERAL_P (prompt)) {
			if (CB_LITERAL (prompt)->size != 1) {
				cb_error_x (prompt, _("Invalid PROMPT literal"));
				return;
			}
		} else {
			if (CB_FIELD_PTR (prompt)->size != 1) {
				cb_error_x (prompt, _("Invalid PROMPT identifier"));
				return;
			}
		}
	}

#if	0	/* RXWRXW - Screen */
	if ((CB_REF_OR_FIELD_P (var)) &&
	     CB_FIELD (cb_ref (var))->storage == CB_STORAGE_SCREEN) {
		current_program->flag_screen = 1;
	}
#endif

	if (current_program->flag_screen) {
		/* Bump ref count to force CRT STATUS field generation */
		if (current_program->crt_status) {
			CB_FIELD_PTR (current_program->crt_status)->count++;
		}
		if ((CB_REF_OR_FIELD_P (var)) &&
		     CB_FIELD (cb_ref (var))->storage == CB_STORAGE_SCREEN) {
			output_screen_from (CB_FIELD (cb_ref (var)), 0);
			gen_screen_ptr = 1;
			if (pos) {
				if (CB_LIST_P (pos)) {
					line = CB_PAIR_X (pos);
					column = CB_PAIR_Y (pos);
					cb_emit (CB_BUILD_FUNCALL_4 ("cob_screen_accept",
						var, line, column, timeout));
				} else {
					cb_emit (CB_BUILD_FUNCALL_4 ("cob_screen_accept",
						var, pos, NULL, timeout));
				}
			} else {
				cb_emit (CB_BUILD_FUNCALL_4 ("cob_screen_accept",
					var, NULL, NULL, timeout));
			}
			gen_screen_ptr = 0;
			output_screen_to (CB_FIELD (cb_ref (var)), 0);
		} else {
			if (var == cb_null) {
				var = NULL;
			}
			if (pos || fgc || bgc || scroll || dispattrs) {
				cb_gen_field_accept (var, pos, fgc, bgc, scroll,
						     timeout, prompt, dispattrs);
			} else {
				cb_emit (CB_BUILD_FUNCALL_9 ("cob_field_accept",
					var, NULL, NULL, fgc, bgc,
					scroll, timeout, prompt,
					cb_int (dispattrs)));
			}
		}
	} else if (pos || fgc || bgc || scroll || dispattrs) {
		/* Bump ref count to force CRT STATUS field generation */
		if (current_program->crt_status) {
			CB_FIELD_PTR (current_program->crt_status)->count++;
		}
		if (var == cb_null) {
			var = NULL;
		}
		cb_gen_field_accept (var, pos, fgc, bgc, scroll,
				     timeout, prompt, dispattrs);
	} else {
		if (var == cb_null) {
			var = NULL;
		}
		cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept", var));
	}
}

void
cb_emit_accept_line_or_col (cb_tree var, const int l_or_c)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_2 ("cob_screen_line_col", var, cb_int (l_or_c)));
}

void
cb_emit_accept_escape_key (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_escape_key", var));
}

void
cb_emit_accept_exception_status (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_exception_status", var));
}

void
cb_emit_accept_user_name (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_user_name", var));
}

void
cb_emit_accept_date (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_date", var));
}

void
cb_emit_accept_date_yyyymmdd (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_date_yyyymmdd", var));
}

void
cb_emit_accept_day (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_day", var));
}

void
cb_emit_accept_day_yyyyddd (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_day_yyyyddd", var));
}

void
cb_emit_accept_day_of_week (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_day_of_week", var));
}

void
cb_emit_accept_time (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_time", var));
}

void
cb_emit_accept_command_line (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_command_line", var));
}

void
cb_emit_get_environment (cb_tree envvar, cb_tree envval)
{
	if (cb_validate_one (envvar)) {
		return;
	}
	if (cb_validate_one (envval)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_2 ("cob_get_environment", envvar, envval));
}

void
cb_emit_accept_environment (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_environment", var));
}

void
cb_emit_accept_arg_number (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_arg_number", var));
}

void
cb_emit_accept_arg_value (cb_tree var)
{
	if (cb_validate_one (var)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept_arg_value", var));
}

void
cb_emit_accept_mnemonic (cb_tree var, cb_tree mnemonic)
{
	if (cb_validate_one (var)) {
		return;
	}
	if (cb_ref (mnemonic) == cb_error_node) {
		return;
	}
	switch (CB_SYSTEM_NAME (cb_ref (mnemonic))->token) {
	case CB_DEVICE_CONSOLE:
	case CB_DEVICE_SYSIN:
		cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept", var));
		break;
	default:
		cb_error_x (mnemonic, _("Invalid input device '%s'"),
			    cb_name (mnemonic));
		break;
	}
}

void
cb_emit_accept_name (cb_tree var, cb_tree name)
{
	cb_tree		sys;

	if (cb_validate_one (var)) {
		return;
	}

	/* Allow direct reference to a device name */
	sys = lookup_system_name (CB_NAME (name));
	if (sys) {
		switch (CB_SYSTEM_NAME (sys)->token) {
		case CB_DEVICE_CONSOLE:
		case CB_DEVICE_SYSIN:
			if (!cb_relaxed_syntax_check) {
				cb_warning_x (name, _("'%s' is not defined in SPECIAL-NAMES"), CB_NAME (name));
			}
			cb_emit (CB_BUILD_FUNCALL_1 ("cob_accept", var));
			return;
		default:
			cb_error_x (name, _("Invalid input device '%s'"),
				    cb_name (name));
			return;
		}
	}

	cb_error_x (name, _("'%s' is not defined in SPECIAL-NAMES"),
		    CB_NAME (name));
}

/* ALLOCATE statement */

void
cb_emit_allocate (cb_tree target1, cb_tree target2, cb_tree size,
		  cb_tree initialize)
{
	cb_tree		x;
	char		buff[32];

	if (cb_validate_one (target1)) {
		return;
	}
	if (cb_validate_one (target2)) {
		return;
	}
	if (cb_validate_one (size)) {
		return;
	}
	if (cb_validate_one (initialize)) {
		return;
	}
	if (target1) {
		if (!(CB_REFERENCE_P(target1) &&
		      CB_FIELD_PTR (target1)->flag_item_based)) {
			cb_error_x (CB_TREE(current_statement),
				_("Target of ALLOCATE is not a BASED item"));
			return;
		}
	}
	if (target2) {
		if (!(CB_REFERENCE_P(target2) &&
		      CB_TREE_CLASS (target2) == CB_CLASS_POINTER)) {
			cb_error_x (CB_TREE(current_statement),
				_("Target of RETURNING is not a data pointer"));
			return;
		}
	}
	if (size) {
		if (CB_TREE_CLASS (size) != CB_CLASS_NUMERIC) {
			cb_error_x (CB_TREE(current_statement),
				_("The CHARACTERS field of ALLOCATE must be numeric"));
			return;
		}
	}
	if (target1) {
		sprintf (buff, "%d", CB_FIELD_PTR (target1)->memory_size);
		x = cb_build_numeric_literal (0, buff, 0);
		cb_emit (CB_BUILD_FUNCALL_4 ("cob_allocate",
			 CB_BUILD_CAST_ADDR_OF_ADDR (target1),
			 target2, x, NULL));
	} else {
		if (initialize && !cb_category_is_alpha (initialize)) {
			cb_error_x (CB_TREE(current_statement),
				_("INITIALIZED TO item is not alphanumeric"));
		}
		cb_emit (CB_BUILD_FUNCALL_4 ("cob_allocate",
			 NULL, target2, size, initialize));
	}
	if (initialize && target1) {
		current_statement->handler2 =
			cb_build_initialize (target1, cb_true, NULL, 1, 0, 0);
	}
}


/* ALTER statement */

void
cb_emit_alter (cb_tree source, cb_tree target)
{
	if (source == cb_error_node) {
		return;
	}
	if (target == cb_error_node) {
		return;
	}
	CB_REFERENCE(source)->flag_alter_code = 1;
	cb_emit (cb_build_alter (source, target));
}

/* CALL statement */

void
cb_emit_call (cb_tree prog, cb_tree par_using, cb_tree returning,
	      cb_tree on_exception, cb_tree not_on_exception,
	      cb_tree convention)
{
	cb_tree				l;
	cb_tree				x;
	struct cb_field			*f;
	const struct system_table	*psyst;
	const char			*p;
	const char			*entry;
	cob_s64_t			val;
	cob_s64_t			valmin;
	cob_s64_t			valmax;
	cob_u32_t			is_sys_call;
	cob_u32_t			is_sys_idx;
	int				error_ind;
	int				call_conv;
	int				numargs;

	if (CB_INTRINSIC_P (prog)) {
		if (CB_INTRINSIC(prog)->intr_tab->category != CB_CATEGORY_ALPHANUMERIC) {
			cb_error_x (CB_TREE (current_statement),
				    _("Only alphanumeric FUNCTION types are allowed here"));
			return;
		}
	}
	if (returning && returning != cb_null) {
		if (CB_TREE_CLASS(returning) != CB_CLASS_NUMERIC &&
		    CB_TREE_CLASS(returning) != CB_CLASS_POINTER) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid RETURNING field"));
			return;
		}
	}

	error_ind = 0;
	numargs = 0;

	if (convention) {
		if (CB_INTEGER_P (convention)) {
			call_conv = CB_INTEGER (convention)->val;
		} else {
			call_conv = cb_get_int (convention);
		}
	} else {
		call_conv = 0;
	}
#ifndef	_WIN32
	if (call_conv & CB_CONV_STDCALL) {
		call_conv &= ~CB_CONV_STDCALL;
		if (warningopt) {
			cb_warning (_("STDCALL not available on this platform"));
		}
	}
#elif	defined(_WIN64)
	if (call_conv & CB_CONV_STDCALL) {
		if (warningopt) {
			cb_warning (_("STDCALL used on 64-bit Windows platform"));
		}
	}
#endif
	if ((call_conv & CB_CONV_STATIC_LINK) && !CB_LITERAL_P (prog)) {
		cb_error_x (CB_TREE (current_statement),
			    _("STATIC CALL convention requires a literal program name"));
		error_ind = 1;
	}

	for (l = par_using; l; l = CB_CHAIN (l), numargs++) {
		x = CB_VALUE (l);
		if (x == cb_error_node) {
			error_ind = 1;
			continue;
		}
		if (CB_NUMERIC_LITERAL_P (x)) {
			if (CB_PURPOSE_INT (l) != CB_CALL_BY_VALUE) {
				continue;
			}
			if (CB_SIZES_INT_UNSIGNED(l) &&
			    CB_LITERAL (x)->sign < 0) {
				cb_error_x (x, _("Numeric literal is negative"));
				error_ind = 1;
				continue;
			}
			val = 0;
			valmin = 0;
			valmax = 0;
			switch (CB_SIZES_INT (l)) {
			case CB_SIZE_1:
				val = cb_get_long_long (x);
				if (CB_SIZES_INT_UNSIGNED(l)) {
					valmin = 0;
					valmax = UCHAR_MAX;
				} else {
					valmin = CHAR_MIN;
					valmax = CHAR_MAX;
				}
				break;
			case CB_SIZE_2:
				val = cb_get_long_long (x);
				if (CB_SIZES_INT_UNSIGNED(l)) {
					valmin = 0;
					valmax = USHRT_MAX;
				} else {
					valmin = SHRT_MIN;
					valmax = SHRT_MAX;
				}
				break;
			case CB_SIZE_4:
				val = cb_get_long_long (x);
				if (CB_SIZES_INT_UNSIGNED(l)) {
					valmin = 0;
					valmax = UINT_MAX;
				} else {
					valmin = INT_MIN;
					valmax = INT_MAX;
				}
				break;
			case CB_SIZE_8:
			case CB_SIZE_AUTO:
				if (CB_SIZES_INT_UNSIGNED(l)) {
					if (CB_LITERAL (x)->size < 20) {
						break;
					}
					if (CB_LITERAL (x)->size > 20) {
						valmin = 1;
						break;
					}
					if (memcmp (CB_LITERAL (x)->data,
						    "18446744073709551615",
						    (size_t)20) > 0) {
						valmin = 1;
						break;
					}
				} else {
					if (CB_LITERAL (x)->size < 19) {
						break;
					}
					if (CB_LITERAL (x)->size > 19) {
						valmin = 1;
						break;
					}
					if (memcmp (CB_LITERAL (x)->data,
						    "9223372036854775807",
						    (size_t)19) > 0) {
						valmin = 1;
						break;
					}
				}
				break;
			default:
				break;
			}
			if (!valmin && !valmax) {
				continue;
			}
			if (val < valmin || val > valmax) {
				cb_error_x (x, _("Numeric literal exceeds size limits"));
				error_ind = 1;
			}
			continue;
		}
		if (CB_CONST_P (x) && x != cb_null) {
			cb_error_x (x, _("Figurative constant invalid here"));
			error_ind = 1;
			continue;
		}
		if ((CB_REFERENCE_P (x) && CB_FIELD_P(CB_REFERENCE(x)->value)) ||
		    CB_FIELD_P (x)) {
			f = CB_FIELD_PTR (x);
			if (f->level == 88) {
				cb_error_x (x, _("'%s' is not a valid data name"), CB_NAME (x));
				error_ind = 1;
				continue;
			}
			if (f->flag_any_length &&
			    CB_PURPOSE_INT (l) != CB_CALL_BY_REFERENCE) {
				cb_error_x (x, _("'%s' ANY LENGTH item not passed BY REFERENCE"), CB_NAME (x));
				error_ind = 1;
				continue;
			}
			if (cb_warn_call_params &&
			    CB_PURPOSE_INT (l) == CB_CALL_BY_REFERENCE) {
				if (f->level != 01 && f->level != 77) {
					cb_warning_x (x, _("'%s' is not a 01 or 77 level item"), CB_NAME (x));
				}
			}
		}
	}

	is_sys_call = 0;
	if (CB_LITERAL_P(prog)) {
		entry = NULL;
		p = (const char *)CB_LITERAL(prog)->data;
		for (; *p; ++p) {
			if (*p == '/' || *p == '\\') {
				entry = p + 1;
			}
		}
		if (!entry) {
			entry = (const char *)CB_LITERAL(prog)->data;
		}
		is_sys_idx = 1;
		for (psyst = system_tab; psyst->syst_name; psyst++, is_sys_idx++) {
			if (!strcmp(entry, (const char *)psyst->syst_name)) {
				if (psyst->syst_params > cb_list_length (par_using)) {
					cb_error_x (CB_TREE (current_statement),
						    _("Wrong number of CALL parameters for '%s'"),
						    (char *)psyst->syst_name);
					return;
				}
				is_sys_call = is_sys_idx;
				break;
			}
		}
	}

	if (error_ind) {
		return;
	}
	if (numargs > current_program->max_call_param) {
		current_program->max_call_param = numargs;
	}
	cb_emit (cb_build_call (prog, par_using, on_exception, not_on_exception,
		 returning, is_sys_call, call_conv));
}

/* CANCEL statement */

void
cb_emit_cancel (cb_tree prog)
{
	if (cb_validate_one (prog)) {
		return;
	}
	cb_emit (cb_build_cancel (prog));
}

/* CLOSE statement */

void
cb_emit_close (cb_tree file, cb_tree opt)
{
	struct cb_file	*f;

	if (file == cb_error_node) {
		return;
	}
	file = cb_ref (file);
	if (file == cb_error_node) {
		return;
	}
	current_statement->file = file;
	f = CB_FILE (file);

	if (f->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on SORT files"));
	}

	cb_emit (CB_BUILD_FUNCALL_4 ("cob_close", file,
				     f->file_status, opt, cb_int0));

	/* Check for file debugging */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    CB_FILE(file)->flag_fl_debug) {
		cb_emit (cb_build_debug (cb_debug_name, f->name, NULL));
		cb_emit (cb_build_move (cb_space, cb_debug_contents));
		cb_emit (cb_build_debug_call (f->debug_section));
	}
}

/* COMMIT statement */

void
cb_emit_commit (void)
{
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_commit"));
}

/* CONTINUE statement */

void
cb_emit_continue (void)
{
	cb_emit (cb_build_continue ());
}

/* DELETE statement */

void
cb_emit_delete (cb_tree file)
{
	struct cb_file	*f;

	if (file == cb_error_node) {
		return;
	}
	file = cb_ref (file);
	if (file == cb_error_node) {
		return;
	}
	current_statement->file = file;
	f = CB_FILE (file);

	if (f->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on SORT files"));
		return;
	} else if (f->organization == COB_ORG_LINE_SEQUENTIAL) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on LINE SEQUENTIAL files"));
		return;
	}

	/* Check for file debugging */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    f->flag_fl_debug) {
		/* Gen callback after delete but before exception test */
		current_statement->flag_callback = 1;
	}

	cb_emit (CB_BUILD_FUNCALL_2 ("cob_delete", file,
				     f->file_status));
}

void
cb_emit_delete_file (cb_tree file)
{
	if (file == cb_error_node) {
		return;
	}
	file = cb_ref (file);
	if (file == cb_error_node) {
		return;
	}
	if (CB_FILE (file)->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on SORT files"));
		return;
	}

	/* Check for file debugging */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    CB_FILE(file)->flag_fl_debug) {
		/* Gen callback after delete but before exception test */
		current_statement->flag_callback = 1;
	}

	cb_emit (CB_BUILD_FUNCALL_2 ("cob_delete_file", file,
				     CB_FILE(file)->file_status));
}

/* DISPLAY statement */

void
cb_emit_env_name (cb_tree value)
{
	if (cb_validate_one (value)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_display_environment", value));
}

void
cb_emit_env_value (cb_tree value)
{
	if (cb_validate_one (value)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_display_env_value", value));
}

void
cb_emit_arg_number (cb_tree value)
{
	if (cb_validate_one (value)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_display_arg_number", value));
}

void
cb_emit_command_line (cb_tree value)
{
	if (cb_validate_one (value)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_display_command_line", value));
}

void
cb_emit_display (cb_tree values, cb_tree upon, cb_tree no_adv, cb_tree pos,
		 struct cb_attr_struct *attr_ptr)
{
	cb_tree		l;
	cb_tree		x;
	cb_tree		line;
	cb_tree		column;
	cb_tree		p;
	cb_tree		fgc;
	cb_tree		bgc;
	cb_tree		scroll;
	int		dispattrs;

	if (attr_ptr) {
		fgc = attr_ptr->fgc;
		bgc = attr_ptr->bgc;
		scroll = attr_ptr->scroll;
		dispattrs = attr_ptr->dispattrs;
	} else {
		fgc = NULL;
		bgc = NULL;
		scroll = NULL;
		dispattrs = 0;
	}

	if (cb_validate_list (values)) {
		return;
	}
	if (cb_validate_one (pos)) {
		return;
	}
	if (cb_validate_one (fgc)) {
		return;
	}
	if (cb_validate_one (bgc)) {
		return;
	}
	if (cb_validate_one (scroll)) {
		return;
	}
	for (l = values; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (x == cb_error_node) {
			return;
		}

		switch (CB_TREE_TAG (x)) {
		case CB_TAG_LITERAL:
		case CB_TAG_INTRINSIC:
		case CB_TAG_CONST:
		case CB_TAG_STRING:
		case CB_TAG_INTEGER:
			break;
		case CB_TAG_REFERENCE:
			if (!CB_FIELD_P(CB_REFERENCE(x)->value)) {
				cb_error_x (x, _("'%s' is an invalid type for DISPLAY operand"), cb_name (x));
				return;
			}
			break;
		default:
			cb_error_x (x, _("Invalid type for DISPLAY operand"));
			return;
		}
	}
	if (upon == cb_error_node) {
		return;
	}

	x = CB_VALUE (values);
	if ((CB_REF_OR_FIELD_P (x)) &&
	     CB_FIELD (cb_ref (x))->storage == CB_STORAGE_SCREEN) {
		output_screen_from (CB_FIELD (cb_ref (x)), 0);
		gen_screen_ptr = 1;
		if (pos) {
			if (CB_PAIR_P (pos)) {
				line = CB_PAIR_X (pos);
				column = CB_PAIR_Y (pos);
				if (line == cb_int0) {
					line = NULL;
				}
				cb_emit (CB_BUILD_FUNCALL_3 ("cob_screen_display",
					 x, line, column));
			} else {
				cb_emit (CB_BUILD_FUNCALL_3 ("cob_screen_display",
					 x, pos, NULL));
			}
		} else {
			cb_emit (CB_BUILD_FUNCALL_3 ("cob_screen_display", x,
				NULL, NULL));
		}
		gen_screen_ptr = 0;
	} else if (pos || fgc || bgc || scroll || dispattrs || upon == cb_null) {
		for (l = values; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			if (x == cb_space) {
				dispattrs |= COB_SCREEN_ERASE_EOS;
				dispattrs |= COB_SCREEN_NO_DISP;
			} else if (x == cb_low) {
				dispattrs |= COB_SCREEN_NO_DISP;
			} else if (CB_LITERAL_P (x) && CB_LITERAL (x)->all &&
				   CB_LITERAL (x)->size == 1) {
				if (CB_LITERAL (x)->data[0] == 1) {
					dispattrs |= COB_SCREEN_ERASE_EOL;
					dispattrs |= COB_SCREEN_NO_DISP;
				} else if (CB_LITERAL (x)->data[0] == 2) {
					cb_emit (CB_BUILD_FUNCALL_0 ("cob_sys_clear_screen"));
					return;
				} else if (CB_LITERAL (x)->data[0] == 7) {
					dispattrs |= COB_SCREEN_BELL;
					dispattrs |= COB_SCREEN_NO_DISP;
				}
			}
			if (!pos) {
				cb_emit (CB_BUILD_FUNCALL_7 ("cob_field_display",
					x, NULL, NULL, fgc, bgc,
					scroll, cb_int (dispattrs)));
			} else if (CB_PAIR_P (pos)) {
				line = CB_PAIR_X (pos);
				column = CB_PAIR_Y (pos);
				if (line == cb_int0) {
					line = NULL;
				}
				cb_emit (CB_BUILD_FUNCALL_7 ("cob_field_display",
					x, line, column, fgc, bgc,
					scroll, cb_int (dispattrs)));
			} else {
				cb_emit (CB_BUILD_FUNCALL_7 ("cob_field_display",
					x, pos, NULL, fgc, bgc,
					scroll, cb_int (dispattrs)));
			}
		}
	} else {
		/* DISPLAY x ... [UPON device-name] */
		p = CB_BUILD_FUNCALL_3 ("cob_display", upon, no_adv, values);
		CB_FUNCALL(p)->varcnt = cb_list_length (values);
		CB_FUNCALL(p)->nolitcast = 1;
		cb_emit (p);
		for (l = values; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			if (CB_FIELD_P (x)) {
				CB_FIELD (cb_ref (x))->count++;
			}
		}
	}
}

cb_tree
cb_build_display_mnemonic (cb_tree x)
{
	if (x == cb_error_node) {
		return cb_int0;
	}
	if (cb_ref (x) == cb_error_node) {
		return cb_int0;
	}

	switch (CB_SYSTEM_NAME (cb_ref (x))->token) {
	case CB_DEVICE_CONSOLE:
	case CB_DEVICE_SYSOUT:
		return cb_int0;
	case CB_DEVICE_SYSERR:
		return cb_int1;
	default:
		cb_error_x (x, _("Invalid output device"));
		return cb_int0;
	}
}

cb_tree
cb_build_display_name (cb_tree x)
{
	const char	*name;
	cb_tree		sys;

	if (x == cb_error_node) {
		return cb_error_node;
	}
	name = CB_NAME (x);
	/* Allow direct reference to a device name */
	sys = lookup_system_name (name);
	if (sys) {
		switch (CB_SYSTEM_NAME (sys)->token) {
		case CB_DEVICE_CONSOLE:
		case CB_DEVICE_SYSOUT:
			if (!cb_relaxed_syntax_check) {
				cb_warning_x (x, _("'%s' is not defined in SPECIAL-NAMES"), name);
			}
			return cb_int0;
		case CB_DEVICE_SYSERR:
			if (!cb_relaxed_syntax_check) {
				cb_warning_x (x, _("'%s' is not defined in SPECIAL-NAMES"), name);
			}
			return cb_int1;
		default:
			cb_error_x (x, _("'%s' is not an output device"), name);
			return cb_error_node;
		}
	}

	cb_error_x (x, _("'%s' is not defined in SPECIAL-NAMES"), name);
	return cb_error_node;
}

/* DIVIDE statement */

void
cb_emit_divide (cb_tree dividend, cb_tree divisor, cb_tree quotient,
		cb_tree remainder)
{
	if (cb_validate_one (dividend)) {
		return;
	}
	if (cb_validate_one (divisor)) {
		return;
	}
	CB_VALUE (quotient) = cb_check_numeric_edited_name (CB_VALUE (quotient));
	CB_VALUE (remainder) = cb_check_numeric_edited_name (CB_VALUE (remainder));

	if (cb_validate_one (CB_VALUE (quotient))) {
		return;
	}
	if (cb_validate_one (CB_VALUE (remainder))) {
		return;
	}

	cb_emit (CB_BUILD_FUNCALL_4 ("cob_div_quotient", dividend, divisor,
				     CB_VALUE (quotient),
				     build_store_option (CB_VALUE (quotient),
							 CB_PURPOSE (quotient))));
	cb_emit (CB_BUILD_FUNCALL_2 ("cob_div_remainder", CB_VALUE (remainder),
				     build_store_option (CB_VALUE (remainder),
							 cb_int0)));
}

/* EVALUATE statement */

static cb_tree
evaluate_test (cb_tree s, cb_tree o)
{
	cb_tree		x;
	cb_tree		y;
	cb_tree		t;
	int		flag;

	/* ANY is always true */
	if (o == cb_any) {
		return cb_true;
	}

	/* Object TRUE or FALSE */
	if (o == cb_true) {
		return s;
	}
	if (o == cb_false) {
		return CB_BUILD_NEGATION (s);
	}

	flag = CB_PURPOSE_INT (o);
	x = CB_PAIR_X (CB_VALUE (o));
	y = CB_PAIR_Y (CB_VALUE (o));

	/* Subject TRUE or FALSE */
	if (s == cb_true) {
		return flag ? CB_BUILD_NEGATION (x) : x;
	}
	if (s == cb_false) {
		return flag ? x : CB_BUILD_NEGATION (x);
	}

	/* x THRU y */
	if (y) {
		t = cb_build_binary_op (cb_build_binary_op (x, '[', s),
					'&',
					cb_build_binary_op (s, '[', y));

		return flag ? CB_BUILD_NEGATION (t) : t;
	}

	if (CB_REFERENCE_P(x) && CB_FIELD_P(CB_REFERENCE(x)->value) &&
	    CB_FIELD(CB_REFERENCE(x)->value)->level == 88) {
		cb_error_x (CB_TREE (current_statement),
			    _("Invalid use of 88 level in WHEN expression"));
		return NULL;
	}

	/* Regular comparison */
	switch (flag) {
	case 0:
		/* Equal comparison */
		return cb_build_binary_op (s, '=', x);
	case 1:
		/* Unequal comparison */
		return cb_build_binary_op (s, '~', x);
	default:
		/* Class and relational conditions */
		return x;
	}
}

static void
build_evaluate (cb_tree subject_list, cb_tree case_list, cb_tree labid)
{
	cb_tree		c1;
	cb_tree		c2;
	cb_tree		c3;
	cb_tree		subjs;
	cb_tree		whens;
	cb_tree		objs;
	cb_tree		stmt;

	if (case_list == NULL) {
		return;
	}

	whens = CB_VALUE (case_list);
	stmt = CB_VALUE (whens);
	whens = CB_CHAIN (whens);
	c1 = NULL;

	/* For each WHEN sequence */
	for (; whens; whens = CB_CHAIN (whens)) {
		c2 = NULL;
		/* Single WHEN test */
		for (subjs = subject_list, objs = CB_VALUE (whens);
		     subjs && objs;
		     subjs = CB_CHAIN (subjs), objs = CB_CHAIN (objs)) {
			c3 = evaluate_test (CB_VALUE (subjs), CB_VALUE (objs));
			if (c3 == NULL || c3 == cb_error_node) {
				return;
			}

			if (c2 == NULL) {
				c2 = c3;
			} else {
				c2 = cb_build_binary_op (c2, '&', c3);
				if (c2 == cb_error_node) {
					return;
				}
			}
		}
		if (subjs || objs) {
			cb_error (_("Wrong number of WHEN parameters"));
		}
		/* Connect multiple WHEN's */
		if (c1 == NULL) {
			c1 = c2;
		} else {
			c1 = cb_build_binary_op (c1, '|', c2);
			if (c1 == cb_error_node) {
				return;
			}
		}
	}

	if (c1 == NULL) {
		cb_emit (cb_build_comment ("WHEN OTHER"));
		cb_emit (stmt);
	} else {
		c2 = stmt;
		/* Check if last statement is GO TO */
		for (c3 = stmt; c3; c3 = CB_CHAIN (c3)) {
			if (!CB_CHAIN(c3)) {
				break;
			}
		}
		if (c3 && CB_VALUE (c3) && CB_STATEMENT_P (CB_VALUE (c3))) {
			c3 = CB_STATEMENT(CB_VALUE(c3))->body;
			if (c3 && CB_VALUE (c3) && !CB_GOTO_P (CB_VALUE(c3))) {
				/* Append the jump */
				c2 = cb_list_add (stmt, labid);
			}
		}
		cb_emit (cb_build_if (cb_build_cond (c1), c2, NULL, 0));
		build_evaluate (subject_list, CB_CHAIN (case_list), labid);
	}
}

void
cb_emit_evaluate (cb_tree subject_list, cb_tree case_list)
{
	cb_tree	x;
	char	sbuf[16];

	snprintf (sbuf, sizeof(sbuf), "goto %s%d;", CB_PREFIX_LABEL, cb_id);
	x = cb_build_direct (cobc_parse_strdup (sbuf), 0);
	build_evaluate (subject_list, case_list, x);
	snprintf (sbuf, sizeof(sbuf), "%s%d:;", CB_PREFIX_LABEL, cb_id);
	cb_emit (cb_build_comment ("End EVALUATE"));
	cb_emit (cb_build_direct (cobc_parse_strdup (sbuf), 0));
	cb_id++;
}

/* FREE statement */

void
cb_emit_free (cb_tree vars)
{
	cb_tree		l;
	struct cb_field	*f;
	int		i;

	if (cb_validate_list (vars)) {
		return;
	}
	for (l = vars, i = 1; l; l = CB_CHAIN (l), i++) {
		if (CB_TREE_CLASS (CB_VALUE (l)) == CB_CLASS_POINTER) {
			if (CB_CAST_P (CB_VALUE (l))) {
				f = CB_FIELD_PTR (CB_CAST (CB_VALUE(l))->val);
				if (!f->flag_item_based) {
					cb_error_x (CB_TREE (current_statement),
						_("Target %d of FREE is not a BASED data item"), i);
				}
				cb_emit (CB_BUILD_FUNCALL_2 ("cob_free_alloc",
					CB_BUILD_CAST_ADDRESS (CB_VALUE (l)), NULL));
			} else {
				cb_emit (CB_BUILD_FUNCALL_2 ("cob_free_alloc",
					NULL, CB_BUILD_CAST_ADDRESS (CB_VALUE (l))));
			}
		} else if (CB_REF_OR_FIELD_P (CB_VALUE (l))) {
				f = CB_FIELD_PTR (CB_VALUE (l));
				if (!f->flag_item_based) {
					cb_error_x (CB_TREE (current_statement),
						_("Target %d of FREE is not a BASED data item"), i);
				}
				cb_emit (CB_BUILD_FUNCALL_2 ("cob_free_alloc",
					CB_BUILD_CAST_ADDR_OF_ADDR (CB_VALUE (l)), NULL));
		} else {
			cb_error_x (CB_TREE (current_statement),
				_("Target %d of FREE must be a data pointer"), i);
		}
	}
}

/* GO TO statement */

void
cb_emit_goto (cb_tree target, cb_tree depending)
{
	if (target == cb_error_node) {
		return;
	}
	if (target == NULL) {
		cb_verify (cb_goto_statement_without_name, "GO TO without procedure-name");
	} else if (depending) {
		/* GO TO procedure-name ... DEPENDING ON identifier */
		if (cb_check_numeric_value (depending) == cb_error_node) {
			return;
		}
		cb_check_data_incompat (depending);
		cb_emit (cb_build_goto (target, depending));
	} else if (CB_CHAIN (target)) {
			cb_error_x (CB_TREE (current_statement),
				    _("GO TO with multiple procedure-names"));
	} else {
		/* GO TO procedure-name */
		cb_emit (cb_build_goto (CB_VALUE (target), NULL));
	}
}

void
cb_emit_exit (const unsigned int goback)
{
	if (goback) {
		cb_emit (cb_build_goto (cb_int1, NULL));
	} else {
		cb_emit (cb_build_goto (NULL, NULL));
	}
}

/* IF statement */

void
cb_emit_if (cb_tree cond, cb_tree stmt1, cb_tree stmt2)
{
	cb_emit (cb_build_if (cond, stmt1, stmt2, 1));
}

cb_tree
cb_build_if_check_break (cb_tree cond, cb_tree stmts)
{
	cb_tree		stmt_lis;

	stmt_lis = cb_check_needs_break (stmts);
	return cb_build_if (cond, stmt_lis, NULL, 0);
}

/* INITIALIZE statement */

void
cb_emit_initialize (cb_tree vars, cb_tree fillinit, cb_tree value,
		    cb_tree replacing, cb_tree def)
{
	cb_tree		l;
	unsigned int	no_fill_init;
	unsigned int	def_init;

	if (cb_validate_list (vars)) {
		return;
	}
	if (value == NULL && replacing == NULL) {
		def = cb_true;
	}
	no_fill_init = (fillinit == NULL);
	def_init = (def != NULL);
	for (l = vars; l; l = CB_CHAIN (l)) {
		cb_emit (cb_build_initialize (CB_VALUE (l), value, replacing,
					      def_init, 1, no_fill_init));
	}
}

/* INSPECT statement */

static void
validate_inspect (cb_tree x, cb_tree y, const unsigned int replconv)
{
	cb_tree			l;
	struct cb_reference	*r;
	size_t			size1;
	size_t			size2;
	int			offset;

	size1 = 0;
	size2 = 0;
	switch (CB_TREE_TAG(x)) {
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (x);
		l = cb_ref (x);
		if (l == cb_error_node) {
			return;
		}
		if (CB_REF_OR_FIELD_P (l)) {
			size1 = CB_FIELD_PTR (x)->size;
		} else if (CB_ALPHABET_NAME_P (l)) {
			size1 = 256;
		}
		if (size1 && r->offset) {
			if (!CB_LITERAL_P (r->offset)) {
				return;
			}
			offset = cb_get_int (r->offset);
			if (r->length) {
				if (!CB_LITERAL_P (r->length)) {
					return;
				}
				size1 = cb_get_int (r->length);
			} else {
				size1 -= (offset - 1);
			}
		}
		break;
	case CB_TAG_LITERAL:
		size1 = CB_LITERAL(x)->size;
		break;
	case CB_TAG_CONST:
		size1 = 1;
		break;
	default:
		break;
	}
	switch (CB_TREE_TAG(y)) {
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (y);
		l = cb_ref (y);
		if (l == cb_error_node) {
			return;
		}
		if (CB_REF_OR_FIELD_P (l)) {
			size2 = CB_FIELD_PTR (y)->size;
		} else if (CB_ALPHABET_NAME_P (l)) {
			size2 = 256;
		}
		if (size2 && r->offset) {
			if (!CB_LITERAL_P (r->offset)) {
				return;
			}
			offset = cb_get_int (r->offset);
			if (r->length) {
				if (!CB_LITERAL_P (r->length)) {
					return;
				}
				size2 = cb_get_int (r->length);
			} else {
				size2 -= (offset - 1);
			}
		}
		break;
	case CB_TAG_LITERAL:
		size2 = CB_LITERAL(y)->size;
		break;
	default:
		break;
	}
	if (size1 && size2 && size1 != size2) {
		if (replconv == 1) {
			cb_error_x (CB_TREE (current_statement),
					_("%s operands differ in size"), "REPLACING");
		} else {
			cb_error_x (CB_TREE (current_statement),
					_("%s operands differ in size"), "CONVERTING");
		}
	}
}

void
cb_emit_inspect (cb_tree var, cb_tree body, cb_tree replacing,
		 const unsigned int replconv)
{
	switch (CB_TREE_TAG(var)) {
	case CB_TAG_REFERENCE:
		break;
	case CB_TAG_INTRINSIC:
		if (replconv) {
			goto rep_error;
		}
		switch (CB_TREE_CATEGORY(var)) {
		case CB_CATEGORY_ALPHABETIC:
		case CB_CATEGORY_ALPHANUMERIC:
		case CB_CATEGORY_NATIONAL:
			break;
		default:
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid target for INSPECT"));
			return;
		}
		break;
	case CB_TAG_LITERAL:
		if (replconv) {
			goto rep_error;
		}
		break;
	default:
		goto rep_error;
	}
	cb_emit (CB_BUILD_FUNCALL_2 ("cob_inspect_init", var, replacing));
	cb_emit_list (body);
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_inspect_finish"));
	return;
rep_error:
	if (replconv == 1) {
		cb_error_x (CB_TREE (current_statement),
				_("Invalid target for %s"), "REPLACING");
	} else {
		cb_error_x (CB_TREE (current_statement),
				_("Invalid target for %s"), "CONVERTING");
	}
}

void
cb_init_tallying (void)
{
	inspect_func = NULL;
	inspect_data = NULL;
}

cb_tree
cb_build_tallying_data (cb_tree x)
{
	inspect_data = x;
	return NULL;
}

cb_tree
cb_build_tallying_characters (cb_tree l)
{
	if (inspect_data == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("Data name expected before CHARACTERS"));
	}
	inspect_func = NULL;
	return cb_list_add (l, CB_BUILD_FUNCALL_1 ("cob_inspect_characters", inspect_data));
}

cb_tree
cb_build_tallying_all (void)
{
	if (inspect_data == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("Data name expected before ALL"));
	}
	inspect_func = "cob_inspect_all";
	return NULL;
}

cb_tree
cb_build_tallying_leading (void)
{
	if (inspect_data == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("Data name expected before LEADING"));
	}
	inspect_func = "cob_inspect_leading";
	return NULL;
}

cb_tree
cb_build_tallying_trailing (void)
{
	if (inspect_data == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("Data name expected before TRAILING"));
	}
	inspect_func = "cob_inspect_trailing";
	return NULL;
}

cb_tree
cb_build_tallying_value (cb_tree x, cb_tree l)
{
	if (inspect_func == NULL) {
		cb_error_x (x, _("ALL, LEADING or TRAILING expected before '%s'"), cb_name (x));
	}
	return cb_list_add (l, CB_BUILD_FUNCALL_2 (inspect_func, inspect_data, x));
}

cb_tree
cb_build_replacing_characters (cb_tree x, cb_tree l)
{
	if (CB_LITERAL_P (x) && CB_LITERAL(x)->size != 1) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operand has wrong size"));
	}
	return cb_list_add (l, CB_BUILD_FUNCALL_1 ("cob_inspect_characters", x));
}

cb_tree
cb_build_replacing_all (cb_tree x, cb_tree y, cb_tree l)
{
	validate_inspect (x, y, 1);
	return cb_list_add (l, CB_BUILD_FUNCALL_2 ("cob_inspect_all", y, x));
}

cb_tree
cb_build_replacing_leading (cb_tree x, cb_tree y, cb_tree l)
{
	validate_inspect (x, y, 1);
	return cb_list_add (l, CB_BUILD_FUNCALL_2 ("cob_inspect_leading", y, x));
}

cb_tree
cb_build_replacing_first (cb_tree x, cb_tree y, cb_tree l)
{
	validate_inspect (x, y, 1);
	return cb_list_add (l, CB_BUILD_FUNCALL_2 ("cob_inspect_first", y, x));
}

cb_tree
cb_build_replacing_trailing (cb_tree x, cb_tree y, cb_tree l)
{
	validate_inspect (x, y, 1);
	return cb_list_add (l, CB_BUILD_FUNCALL_2 ("cob_inspect_trailing", y, x));
}

cb_tree
cb_build_converting (cb_tree x, cb_tree y, cb_tree l)
{
	validate_inspect (x, y, 2);
	return cb_list_add (l, CB_BUILD_FUNCALL_2 ("cob_inspect_converting", x, y));
}

cb_tree
cb_build_inspect_region_start (void)
{
	return CB_LIST_INIT (CB_BUILD_FUNCALL_0 ("cob_inspect_start"));
}

/* MOVE statement */

static void
warning_destination (cb_tree x)
{
	struct cb_reference	*r;
	struct cb_field		*f;
	cb_tree			loc;

	r = CB_REFERENCE (x);
	f = CB_FIELD (r->value);
	loc = CB_TREE (f);

	if (r->offset) {
		return;
	}

	if (!strcmp (f->name, "RETURN-CODE") ||
	    !strcmp (f->name, "SORT-RETURN") ||
	    !strcmp (f->name, "NUMBER-OF-CALL-PARAMETERS")) {
		cb_warning (_("Internal register '%s' defined as BINARY-LONG"),
			    f->name);
	} else if (f->flag_real_binary) {
		cb_warning_x (loc, _("'%s' defined here as USAGE %s"),
			      f->name, f->pic->orig);
	} else if (f->usage == CB_USAGE_FLOAT) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT"),
			      f->name);
	} else if (f->usage == CB_USAGE_DOUBLE) {
		cb_warning_x (loc, _("'%s' defined here as USAGE DOUBLE"),
			      f->name);
	} else if (f->usage == CB_USAGE_LONG_DOUBLE) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT EXTENDED"),
			      f->name);
	} else if (f->usage == CB_USAGE_FP_BIN32) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT-BINARY-7"),
			      f->name);
	} else if (f->usage == CB_USAGE_FP_BIN64) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT-BINARY-16"),
			      f->name);
	} else if (f->usage == CB_USAGE_FP_BIN128) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT-BINARY-34"),
			      f->name);
	} else if (f->usage == CB_USAGE_FP_DEC64) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT-DECIMAL-16"),
			      f->name);
	} else if (f->usage == CB_USAGE_FP_DEC128) {
		cb_warning_x (loc, _("'%s' defined here as USAGE FLOAT-DECIMAL-34"),
			      f->name);
	} else if (f->pic) {
		cb_warning_x (loc, _("'%s' defined here as PIC %s"),
			      cb_name (loc), f->pic->orig);
	} else {
		cb_warning_x (loc, _("'%s' defined here as a group of length %d"),
			      cb_name (loc), f->size);
	}
}

static void
move_warning (cb_tree src, cb_tree dst, const unsigned int value_flag,
	      const int flag, const int src_flag, const char *msg)
{
	cb_tree		loc;

	if (suppress_warn) {
		return;
	}
	loc = src->source_line ? src : dst;
	if (value_flag) {
		/* VALUE clause */
		if (CB_LITERAL_P (src)) {
			cb_warning_x (dst, msg);
		} else {
			cb_warning_x (loc, msg);
		}
	} else {
		/* MOVE statement */
		if (flag) {
			if (CB_LITERAL_P (src)) {
				cb_warning_x (dst, msg);
			} else {
				cb_warning_x (loc, msg);
			}
			if (src_flag) {
				warning_destination (src);
			}
			warning_destination (dst);
		}
	}

	return;
}

static int
count_pic_alphanumeric_edited (struct cb_field *field)
{
	unsigned char	*p;
	int		count;
	int		repeat;

	/* Count number of free places in an alphanumeric edited field */
	count = 0;
	for (p = (unsigned char *)(field->pic->str); *p; p += 5) {
		if (*p == '9' || *p == 'A' || *p == 'X') {
			memcpy ((void *)&repeat, p + 1, sizeof(int));
			count += repeat;
		}
	}
	return count;
}

static size_t
cb_check_overlapping (cb_tree src, cb_tree dst,
		      struct cb_field *src_f, struct cb_field *dst_f)
{
	struct cb_field	*f1;
	struct cb_field	*ff1;
	struct cb_field	*ff2;
	cb_tree		loc;
	int		src_size;
	int		dst_size;
	int		src_off;
	int		dst_off;

	src_size = cb_field_size (src);
	dst_size = cb_field_size (dst);

	if (src_size <= 0 || dst_size <= 0 ||
	    cb_field_variable_size (src_f) ||
	    cb_field_variable_size (dst_f)) {
		return 0;
	}
	/* Check basic overlapping */
	for (f1 = src_f->children; f1; f1 = f1->sister) {
		if (f1 == dst_f) {
			goto overlapret;
		}
	}
	for (f1 = dst_f->children; f1; f1 = f1->sister) {
		if (f1 == src_f) {
			goto overlapret;
		}
	}
	ff1 = cb_field_founder (src_f);
	ff2 = cb_field_founder (dst_f);
	if (ff1->redefines) {
		ff1 = ff1->redefines;
	}
	if (ff2->redefines) {
		ff2 = ff2->redefines;
	}
	if (ff1 != ff2) {
		return 0;
	}
	/* Check literal occurs? */
	if (src_f->indexes || dst_f->indexes) {
		return 0;
	}
	/* Check reference modification ? */
	if (CB_REFERENCE_P (src) && CB_REFERENCE(src)->offset) {
		return 0;
	}
	if (CB_REFERENCE_P (dst) && CB_REFERENCE(dst)->offset) {
		return 0;
	}
	src_off = src_f->offset;
	dst_off = dst_f->offset;
	if (src_off >= dst_off && src_off < (dst_off + dst_size)) {
		goto overlapret;
	}
	if (src_off < dst_off && (src_off + src_size) > dst_off) {
		goto overlapret;
	}
	return 0;
overlapret:
	loc = src->source_line ? src : dst;
	if (cb_warn_overlap && !suppress_warn) {
		cb_warning_x (loc, _("Overlapping MOVE may produce unpredictable results"));
	}
	return 1;
}

int
validate_move (cb_tree src, cb_tree dst, const unsigned int is_value)
{
	struct cb_field		*fdst;
	struct cb_field		*fsrc;
	struct cb_literal	*l;
	unsigned char		*p;
	cb_tree			loc;
	cob_s64_t		val;
	size_t			i;
	size_t			is_numeric_edited;
	int			src_scale_mod;
	int			dst_scale_mod;
	int			dst_size_mod;
	int			size;
	int			most_significant;
	int			least_significant;

	loc = src->source_line ? src : dst;
	is_numeric_edited = 0;
	overlapping = 0;
	if (CB_REFERENCE_P (dst)) {
		if (CB_ALPHABET_NAME_P(CB_REFERENCE(dst)->value)) {
			goto invalid;
		}
		if (CB_FILE_P(CB_REFERENCE(dst)->value)) {
			goto invalid;
		}
	}
	if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_BOOLEAN) {
		cb_error_x (loc, _("Invalid destination for MOVE"));
		return -1;
	}

	if (CB_TREE_CLASS (dst) == CB_CLASS_POINTER) {
		if (CB_TREE_CLASS (src) == CB_CLASS_POINTER) {
			return 0;
		} else {
			goto invalid;
		}
	}

	fdst = CB_FIELD_PTR (dst);
	switch (CB_TREE_TAG (src)) {
	case CB_TAG_CONST:
		if (src == cb_space) {
			if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC ||
			    (CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC_EDITED && !is_value)) {
				if (!cb_relaxed_syntax_check || is_value) {
					goto invalid;
				}
				cb_warning_x (loc, _("Source is non-numeric - substituting zero"));
			}
		} else if (src == cb_zero) {
			if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_ALPHABETIC) {
				goto invalid;
			}
		} else if (src == cb_low || src == cb_high || src == cb_quote) {
			if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC ||
			    CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC_EDITED) {
				if (!cb_relaxed_syntax_check || is_value) {
					goto invalid;
				}
				cb_warning_x (loc, _("Source is non-numeric - substituting zero"));
			}
		}
		break;
	case CB_TAG_LITERAL:
		l = CB_LITERAL (src);
		if (CB_TREE_CLASS (src) == CB_CLASS_NUMERIC) {
			/* Numeric literal */
			if (l->all) {
				goto invalid;
			}
			if (fdst->usage == CB_USAGE_DOUBLE ||
			    fdst->usage == CB_USAGE_FLOAT ||
			    fdst->usage == CB_USAGE_LONG_DOUBLE ||
			    fdst->usage == CB_USAGE_FP_BIN32 ||
			    fdst->usage == CB_USAGE_FP_BIN64 ||
			    fdst->usage == CB_USAGE_FP_BIN128 ||
			    fdst->usage == CB_USAGE_FP_DEC64 ||
			    fdst->usage == CB_USAGE_FP_DEC128) {
				break;
			}
			most_significant = -999;
			least_significant = 999;

			/* Compute the most significant figure place */
			for (i = 0; i < l->size; i++) {
				if (l->data[i] != '0') {
					break;
				}
			}
			if (i != l->size) {
				most_significant = (int) (l->size - l->scale - i - 1);
			}

			/* Compute the least significant figure place */
			for (i = 0; i < l->size; i++) {
				if (l->data[l->size - i - 1] != '0') {
					break;
				}
			}
			if (i != l->size) {
				least_significant = (int) (-l->scale + i);
			}

			/* Value check */
			switch (CB_TREE_CATEGORY (dst)) {
			case CB_CATEGORY_ALPHANUMERIC:
			case CB_CATEGORY_ALPHANUMERIC_EDITED:
				if (is_value) {
					goto expect_alphanumeric;
				}
				if (l->scale == 0) {
					goto expect_alphanumeric;
				}
				goto non_integer_move;
			case CB_CATEGORY_NUMERIC:
				if (fdst->pic->scale < 0) {
					/* Check for PIC 9(n)P(m) */
					if (least_significant < -fdst->pic->scale) {
						goto value_mismatch;
					}
				} else if (fdst->pic->scale > fdst->pic->size) {
					/* Check for PIC P(n)9(m) */
					if (most_significant >= fdst->pic->size - fdst->pic->scale) {
						goto value_mismatch;
					}
				}
				break;
			case CB_CATEGORY_NUMERIC_EDITED:
				if (is_value) {
					goto expect_alphanumeric;
				}

				/* TODO */
				break;
			case CB_CATEGORY_ALPHABETIC:
				if (is_value) {
					goto expect_alphanumeric;
				}
				/* Coming from codegen */
				if (!suppress_warn) {
					goto invalid;
				}
#if	1	/* RXWRXW - Initialize warn */
				if (warningopt) {
					cb_warning_x (loc, _("Numeric move to ALPHABETIC"));
				}
#endif
				break;
			default:
				if (is_value) {
					goto expect_alphanumeric;
				}
				goto invalid;
			}

			/* Sign check */
			if (l->sign != 0 && !fdst->pic->have_sign) {
				if (is_value) {
					cb_error_x (loc, _("Data item not signed"));
					return -1;
				}
				if (cb_warn_constant) {
					cb_warning_x (loc, _("Ignoring sign"));
				}
			}

			/* Size check */
			if (fdst->flag_real_binary ||
			    ((fdst->usage == CB_USAGE_COMP_5 ||
			      fdst->usage == CB_USAGE_COMP_X ||
			      fdst->usage == CB_USAGE_BINARY) &&
			      fdst->pic->scale == 0)) {
				p = l->data;
				for (i = 0; i < l->size; i++) {
					if (l->data[i] != '0') {
						p = &l->data[i];
						break;
					}
				}
				i = l->size - i;
				switch (fdst->size) {
				case 1:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-128) ||
						    val > COB_S64_C(127)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(255)) {
							goto numlit_overflow;
						}
					}
					break;
				case 2:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-32768) ||
						    val > COB_S64_C(32767)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(65535)) {
							goto numlit_overflow;
						}
					}
					break;
				case 3:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-8388608) ||
						    val > COB_S64_C(8388607)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(16777215)) {
							goto numlit_overflow;
						}
					}
					break;
				case 4:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-2147483648) ||
						    val > COB_S64_C(2147483647)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(4294967295)) {
							goto numlit_overflow;
						}
					}
					break;
				case 5:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-549755813888) ||
						    val > COB_S64_C(549755813887)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(1099511627775)) {
							goto numlit_overflow;
						}
					}
					break;
				case 6:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-140737488355328) ||
						    val > COB_S64_C(140737488355327)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(281474976710655)) {
							goto numlit_overflow;
						}
					}
					break;
				case 7:
					if (i > 18) {
						goto numlit_overflow;
					}
					val = cb_get_long_long (src);
					if (fdst->pic->have_sign) {
						if (val < COB_S64_C(-36028797018963968) ||
						    val > COB_S64_C(36028797018963967)) {
							goto numlit_overflow;
						}
					} else {
						if (val > COB_S64_C(72057594037927935)) {
							goto numlit_overflow;
						}
					}
					break;
				default:
					if (fdst->pic->have_sign) {
						if (i < 19) {
							break;
						}
						if (i > 19) {
							goto numlit_overflow;
						}
						if (memcmp (p, "9223372036854775807", (size_t)19) > 0) {
							goto numlit_overflow;
						}
					} else {
						if (i < 20) {
							break;
						}
						if (i > 20) {
							goto numlit_overflow;
						}
						if (memcmp (p, "18446744073709551615", (size_t)20) > 0) {
							goto numlit_overflow;
						}
					}
					break;
				}
				return 0;
			}
			if (least_significant < -fdst->pic->scale) {
				goto size_overflow;
			}
			if (fdst->pic->scale > 0) {
				size = fdst->pic->digits - fdst->pic->scale;
			} else {
				size = fdst->pic->digits;
			}
			if (most_significant >= size) {
				goto size_overflow;
			}
		} else {
			/* Alphanumeric literal */

			/* Value check */
			switch (CB_TREE_CATEGORY (dst)) {
			case CB_CATEGORY_ALPHABETIC:
				for (i = 0; i < l->size; i++) {
					if (!isalpha (l->data[i]) &&
					    l->data[i] != ' ') {
						goto value_mismatch;
					}
				}
				break;
			case CB_CATEGORY_NUMERIC:
				goto expect_numeric;
			case CB_CATEGORY_NUMERIC_EDITED:
				if (!is_value) {
					goto expect_numeric;
				}

				/* TODO: validate the value */
				break;
			default:
				break;
			}

			/* Size check */
			size = cb_field_size (dst);
			if (size > 0 && (int)l->size > size) {
				goto size_overflow;
			}
		}
		break;
	case CB_TAG_FIELD:
	case CB_TAG_REFERENCE:
		if (CB_REFERENCE_P(src) &&
		    CB_ALPHABET_NAME_P(CB_REFERENCE(src)->value)) {
			break;
		}
		if (CB_REFERENCE_P(src) &&
		    CB_FILE_P(CB_REFERENCE(src)->value)) {
			goto invalid;
		}
		fsrc = CB_FIELD_PTR (src);
		size = cb_field_size (src);
		if (size < 0) {
			size = fsrc->size;
		}

		/* Check basic overlapping */
		overlapping = cb_check_overlapping (src, dst, fsrc, fdst);

		/* Non-elementary move */
		if (fsrc->children || fdst->children) {
			if (size > fdst->size) {
				goto size_overflow_1;
			}
			break;
		}

		/* Elementary move */
		switch (CB_TREE_CATEGORY (src)) {
		case CB_CATEGORY_ALPHANUMERIC:
			switch (CB_TREE_CATEGORY (dst)) {
			case CB_CATEGORY_NUMERIC:
			case CB_CATEGORY_NUMERIC_EDITED:
				if (size > (int)fdst->pic->digits) {
					goto size_overflow_2;
				}
				break;
			case CB_CATEGORY_ALPHANUMERIC_EDITED:
				if (size > count_pic_alphanumeric_edited (fdst)) {
					goto size_overflow_1;
				}
				break;
			default:
				if (size > fdst->size) {
					goto size_overflow_1;
				}
				break;
			}
			break;
		case CB_CATEGORY_ALPHABETIC:
		case CB_CATEGORY_ALPHANUMERIC_EDITED:
			switch (CB_TREE_CATEGORY (dst)) {
			case CB_CATEGORY_NUMERIC:
			case CB_CATEGORY_NUMERIC_EDITED:
				goto invalid;
			case CB_CATEGORY_ALPHANUMERIC_EDITED:
				if (size > count_pic_alphanumeric_edited(fdst)) {
					goto size_overflow_1;
				}
				break;
			default:
				if (size > fdst->size) {
					goto size_overflow_1;
				}
				break;
			}
			break;
		case CB_CATEGORY_NUMERIC:
		case CB_CATEGORY_NUMERIC_EDITED:
			switch (CB_TREE_CATEGORY (dst)) {
			case CB_CATEGORY_ALPHABETIC:
				goto invalid;
			case CB_CATEGORY_ALPHANUMERIC_EDITED:
				is_numeric_edited = 1;
				/* Drop through */
			case CB_CATEGORY_ALPHANUMERIC:
				if (!fsrc->pic) {
					return -1;
				}
				if (is_numeric_edited) {
					dst_size_mod = count_pic_alphanumeric_edited (fdst);
				} else {
					dst_size_mod = fdst->size;
				}
				if (CB_TREE_CATEGORY (src) == CB_CATEGORY_NUMERIC &&
				    fsrc->pic->scale > 0) {
					goto non_integer_move;
				}
				if (CB_TREE_CATEGORY (src) == CB_CATEGORY_NUMERIC &&
				    (int)fsrc->pic->digits > dst_size_mod) {
					goto size_overflow_2;
				}
				if (CB_TREE_CATEGORY (src) == CB_CATEGORY_NUMERIC_EDITED &&
				    fsrc->size > dst_size_mod) {
					goto size_overflow_1;
				}
				break;
			default:
				if (!fsrc->pic) {
					return -1;
				}
				if (!fdst->pic) {
					return -1;
				}
				src_scale_mod = fsrc->pic->scale < 0 ?
						0 : fsrc->pic->scale;
				dst_scale_mod = fdst->pic->scale < 0 ?
						0 : fdst->pic->scale;
				if (fsrc->pic->digits - src_scale_mod >
				    fdst->pic->digits - dst_scale_mod ||
				    src_scale_mod > dst_scale_mod) {
					goto size_overflow_2;
				}
				break;
			}
			break;
		default:
			cb_error_x (loc, _("Invalid source for MOVE"));
			return -1;
		}
		break;
	case CB_TAG_INTEGER:
	case CB_TAG_BINARY_OP:
	case CB_TAG_INTRINSIC:
	case CB_TAG_FUNCALL:
		/* TODO: check this */
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"),
				(int)CB_TREE_TAG (src));
		COBC_ABORT ();
	}
	return 0;

invalid:
	if (is_value) {
		cb_error_x (loc, _("Invalid VALUE clause"));
	} else {
		cb_error_x (loc, _("Invalid MOVE statement"));
	}
	return -1;

numlit_overflow:
	if (is_value) {
		cb_error_x (loc, _("Invalid VALUE clause - literal exceeds data size"));
		return -1;
	}
	if (cb_warn_constant && !suppress_warn) {
		cb_warning_x (loc, _("Numeric literal exceeds data size"));
	}
	return 0;

non_integer_move:
	if (!suppress_warn) {
		if (cb_move_noninteger_to_alphanumeric == CB_ERROR) {
			goto invalid;
		}
		cb_warning_x (loc, _("Move non-integer to alphanumeric"));
	}
	return 0;

expect_numeric:
	move_warning (src, dst, is_value, cb_warn_strict_typing, 0,
		    _("Numeric value is expected"));
	return 0;

expect_alphanumeric:
	move_warning (src, dst, is_value, cb_warn_strict_typing, 0,
		    _("Alphanumeric value is expected"));
	return 0;

value_mismatch:
	move_warning (src, dst, is_value, cb_warn_constant, 0,
		    _("Value does not fit the picture string"));
	return 0;

size_overflow:
	move_warning (src, dst, is_value, cb_warn_constant, 0,
		    _("Value size exceeds data size"));
	return 0;

size_overflow_1:
	move_warning (src, dst, is_value, cb_warn_truncate, 1,
		    _("Sending field larger than receiving field"));
	return 0;

size_overflow_2:
	move_warning (src, dst, is_value, cb_warn_truncate, 1,
		    _("Some digits may be truncated"));
	return 0;
}

static cb_tree
cb_build_memset (cb_tree x, const int c)
{
	int size = cb_field_size (x);

	if (size == 1) {
		return CB_BUILD_FUNCALL_2 ("$E", x, cb_int (c));
	}
	return CB_BUILD_FUNCALL_3 ("memset",
				   CB_BUILD_CAST_ADDRESS (x),
				   cb_int (c), CB_BUILD_CAST_LENGTH (x));
}

static cb_tree
cb_build_move_copy (cb_tree src, cb_tree dst)
{
	int	size;

	size = cb_field_size (dst);
	if (size == 1) {
		return CB_BUILD_FUNCALL_2 ("$F", dst, src);
	}
	if (overlapping) {
		overlapping = 0;
		return CB_BUILD_FUNCALL_3 ("memmove",
					   CB_BUILD_CAST_ADDRESS (dst),
					   CB_BUILD_CAST_ADDRESS (src),
					   CB_BUILD_CAST_LENGTH (dst));
	} else {
		return CB_BUILD_FUNCALL_3 ("memcpy",
					   CB_BUILD_CAST_ADDRESS (dst),
					   CB_BUILD_CAST_ADDRESS (src),
					   CB_BUILD_CAST_LENGTH (dst));
	}
}

static cb_tree
cb_build_move_num_zero (cb_tree x)
{
	struct cb_field		*f;

	f = CB_FIELD_PTR (x);
	switch (f->usage) {
	case CB_USAGE_BINARY:
	case CB_USAGE_COMP_5:
	case CB_USAGE_COMP_X:
		if (f->flag_binary_swap) {
			return cb_build_memset (x, 0);
		}
		switch (f->size) {
#ifdef	COB_NON_ALIGNED
		case 1:
			return cb_build_assign (x, cb_int0);
		case 2:
#ifdef	COB_SHORT_BORK
			if (f->storage != CB_STORAGE_LINKAGE && f->indexes == 0 &&
			   (f->offset % 4 == 0)) {
				return cb_build_assign (x, cb_int0);
			}
			break;
#endif
		case 4:
		case 8:
			if (f->storage != CB_STORAGE_LINKAGE && f->indexes == 0 &&
			   (f->offset % f->size == 0)) {
				return cb_build_assign (x, cb_int0);
			}
			break;
#else
		case 1:
		case 2:
		case 4:
		case 8:
			return cb_build_assign (x, cb_int0);
#endif
		default:
			break;
		}
		return cb_build_memset (x, 0);
	case CB_USAGE_DISPLAY:
		if (!cb_ebcdic_sign) {
			return cb_build_memset (x, '0');
		}
		if (f->pic && !f->pic->have_sign) {
			return cb_build_memset (x, '0');
		}
		break;
	case CB_USAGE_PACKED:
		return CB_BUILD_FUNCALL_1 ("cob_set_packed_zero", x);
	case CB_USAGE_COMP_6:
		return cb_build_memset (x, 0);
	default:
		break;
	}
	return CB_BUILD_FUNCALL_2 ("cob_move", cb_zero, x);
}

static cb_tree
cb_build_move_space (cb_tree x)
{
	switch (CB_TREE_CATEGORY (x)) {
	case CB_CATEGORY_NUMERIC:
	case CB_CATEGORY_ALPHABETIC:
	case CB_CATEGORY_ALPHANUMERIC:
		if (!CB_FIELD_PTR (x)->flag_any_length) {
			return cb_build_memset (x, ' ');
		}
		/* Fall through */
	default:
		return CB_BUILD_FUNCALL_2 ("cob_move", cb_space, x);
	}
}

static cb_tree
cb_build_move_zero (cb_tree x)
{
	switch (CB_TREE_CATEGORY (x)) {
	case CB_CATEGORY_NUMERIC:
		if (CB_FIELD_PTR (x)->flag_blank_zero) {
			return cb_build_move_space (x);
		} else if (CB_FIELD_PTR (x)->flag_sign_separate) {
			return CB_BUILD_FUNCALL_2 ("cob_move", cb_zero, x);
		} else {
			return cb_build_move_num_zero (x);
		}
	case CB_CATEGORY_ALPHABETIC:
	case CB_CATEGORY_ALPHANUMERIC:
		if (!CB_FIELD_PTR (x)->flag_any_length) {
			return cb_build_memset (x, '0');
		}
		/* Fall through */
	default:
		return CB_BUILD_FUNCALL_2 ("cob_move", cb_zero, x);
	}
}

static cb_tree
cb_build_move_high (cb_tree x)
{
	switch (CB_TREE_CATEGORY (x)) {
	case CB_CATEGORY_NUMERIC:
	case CB_CATEGORY_ALPHABETIC:
	case CB_CATEGORY_ALPHANUMERIC:
		if (CB_FIELD_PTR (x)->flag_any_length) {
			return CB_BUILD_FUNCALL_2 ("cob_move", cb_high, x);
		}
		if (cb_high == cb_norm_high) {
			return cb_build_memset (x, 255);
		}
		/* Fall through */
	default:
		return CB_BUILD_FUNCALL_2 ("cob_move", cb_high, x);
	}
}

static cb_tree
cb_build_move_low (cb_tree x)
{
	switch (CB_TREE_CATEGORY (x)) {
	case CB_CATEGORY_NUMERIC:
	case CB_CATEGORY_ALPHABETIC:
	case CB_CATEGORY_ALPHANUMERIC:
		if (CB_FIELD_PTR (x)->flag_any_length) {
			return CB_BUILD_FUNCALL_2 ("cob_move", cb_low, x);
		}
		if (cb_low == cb_norm_low) {
			return cb_build_memset (x, 0);
		}
		/* Fall through */
	default:
		return CB_BUILD_FUNCALL_2 ("cob_move", cb_low, x);
	}
}

static cb_tree
cb_build_move_quote (cb_tree x)
{
	switch (CB_TREE_CATEGORY (x)) {
	case CB_CATEGORY_NUMERIC:
	case CB_CATEGORY_ALPHABETIC:
	case CB_CATEGORY_ALPHANUMERIC:
		if (!CB_FIELD_PTR (x)->flag_any_length) {
			return cb_build_memset (x, cb_flag_apostrophe ? '\'' : '"');
		}
		/* Fall through */
	default:
		return CB_BUILD_FUNCALL_2 ("cob_move", cb_quote, x);
	}
}

#ifdef	COB_EBCDIC_MACHINE
static void
cob_put_sign_ascii (unsigned char *p)
{
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
	}
}
#endif

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
			*p = (unsigned char)'}';
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

static cb_tree
cb_build_move_literal (cb_tree src, cb_tree dst)
{
	struct cb_literal	*l;
	struct cb_field		*f;
	unsigned char		*buff;
	unsigned char		*p;
	enum cb_category	cat;
	int			i;
	int			diff;
	int			val;
	int			n;
	unsigned char		bbyte;

	l = CB_LITERAL (src);
	f = CB_FIELD_PTR (dst);
	cat = CB_TREE_CATEGORY (dst);

	if (l->all) {
		if (cat == CB_CATEGORY_NUMERIC ||
		    cat == CB_CATEGORY_NUMERIC_EDITED) {
			return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
		}
		if (l->size == 1) {
			return CB_BUILD_FUNCALL_3 ("memset",
					   CB_BUILD_CAST_ADDRESS (dst),
					   cb_int (l->data[0]),
					   CB_BUILD_CAST_LENGTH (dst));
		}
		bbyte = l->data[0];
		for (i = 0; i < (int)l->size; i++) {
			if (bbyte != l->data[i]) {
				break;
			}
			bbyte = l->data[i];
		}
		if (i == (int)l->size) {
			return CB_BUILD_FUNCALL_3 ("memset",
					   CB_BUILD_CAST_ADDRESS (dst),
					   cb_int (l->data[0]),
					   CB_BUILD_CAST_LENGTH (dst));
		}
		if (f->size > 128) {
			return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
		}
		buff = cobc_parse_malloc ((size_t)f->size);
		for (i = 0; i < f->size; i++) {
			buff[i] = l->data[i % l->size];
		}
		return CB_BUILD_FUNCALL_3 ("memcpy",
					   CB_BUILD_CAST_ADDRESS (dst),
					   cb_build_string (buff, (size_t)f->size),
					   CB_BUILD_CAST_LENGTH (dst));
	}

	if (cat == CB_CATEGORY_NUMERIC_EDITED) {
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}

	if ((cat == CB_CATEGORY_NUMERIC &&
	    f->usage == CB_USAGE_DISPLAY &&
	    f->pic->scale == l->scale &&
	    !f->flag_sign_leading && !f->flag_sign_separate &&
	    !f->flag_blank_zero) ||
	   ((cat == CB_CATEGORY_ALPHABETIC ||
	     cat == CB_CATEGORY_ALPHANUMERIC) &&
	    f->size < (int) (l->size + 16) &&
	    !cb_field_variable_size (f))) {
		buff = cobc_parse_malloc ((size_t)f->size);
		diff = (int) (f->size - l->size);
		if (cat == CB_CATEGORY_NUMERIC) {
			if (diff <= 0) {
				memcpy (buff, l->data - diff, (size_t)f->size);
			} else {
				memset (buff, '0', (size_t)diff);
				memcpy (buff + diff, l->data, (size_t)l->size);
			}
			/* Check all zeros */
			n = 0;
			for (p = buff; p < buff + f->size; p++) {
				if (*p != '0') {
					n = 1;
					break;
				}
			}
			if (f->pic->have_sign) {
				p = &buff[f->size - 1];
				if (!n) {
					/* Zeros */
					/* EBCDIC - store sign otherwise nothing */
					if (cb_ebcdic_sign) {
						cob_put_sign_ebcdic (p, 1);
					}
				} else if (cb_ebcdic_sign) {
					cob_put_sign_ebcdic (p, l->sign);
				} else if (l->sign < 0) {
#ifdef	COB_EBCDIC_MACHINE
					cob_put_sign_ascii (p);
#else
					*p += 0x40;
#endif
				}
			}
		} else {
			if (f->flag_justified) {
				if (diff <= 0) {
					memcpy (buff, l->data - diff, (size_t)f->size);
				} else {
					memset (buff, ' ', (size_t)diff);
					memcpy (buff + diff, l->data, (size_t)l->size);
				}
			} else {
				if (diff <= 0) {
					memcpy (buff, l->data, (size_t)f->size);
				} else {
					memcpy (buff, l->data, (size_t)l->size);
					memset (buff + l->size, ' ', (size_t)diff);
				}
			}
		}
		bbyte = *buff;
		if (f->size == 1) {
			cobc_parse_free (buff);
			return CB_BUILD_FUNCALL_2 ("$E", dst, cb_int (bbyte));
		}
		for (i = 0; i < f->size; i++) {
			if (bbyte != buff[i]) {
				break;
			}
		}
		if (i == f->size) {
			cobc_parse_free (buff);
			return CB_BUILD_FUNCALL_3 ("memset",
					   CB_BUILD_CAST_ADDRESS (dst),
					   cb_int (bbyte),
					   CB_BUILD_CAST_LENGTH (dst));
		}
		return CB_BUILD_FUNCALL_3 ("memcpy",
					   CB_BUILD_CAST_ADDRESS (dst),
					   cb_build_string (buff, (size_t)f->size),
					   CB_BUILD_CAST_LENGTH (dst));
	}

	if ((f->usage == CB_USAGE_BINARY ||
	    f->usage == CB_USAGE_COMP_5 ||
	    f->usage == CB_USAGE_COMP_X) &&
	    cb_fits_int (src) && f->size <= 8) {
		val = cb_get_int (src);
		n = f->pic->scale - l->scale;
		if ((l->size + n) > 9) {
			return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
		}
		for (; n > 0; n--) {
			val *= 10;
		}
		for (; n < 0; n++) {
			val /= 10;
		}
		if (val == 0) {
			return cb_build_move_num_zero (dst);
		}
		if (val < 0 && !f->pic->have_sign) {
			val = -val;
		}
		if (f->size == 1) {
			return cb_build_assign (dst, cb_int (val));
		}
		if (f->flag_binary_swap) {
			i = (f->size - 1) + (8 * (f->pic->have_sign ? 1 : 0));
			optimize_defs[bin_set_funcs[i].optim_val] = 1;
			return CB_BUILD_FUNCALL_2 (bin_set_funcs[i].optim_name,
				CB_BUILD_CAST_ADDRESS (dst),
				cb_int (val));
		}
		switch (f->size) {
		case 2:
#ifdef	COB_SHORT_BORK
			if (f->storage != CB_STORAGE_LINKAGE && f->indexes == 0 &&
			   (f->offset % 4 == 0)) {
				return cb_build_assign (dst, cb_int (val));
			}
			break;
#endif
		case 4:
		case 8:
#ifdef	COB_NON_ALIGNED
			if (f->storage != CB_STORAGE_LINKAGE && f->indexes == 0 &&
			   (f->offset % f->size == 0)) {
				return cb_build_assign (dst, cb_int (val));
			}
			break;
#else
			return cb_build_assign (dst, cb_int (val));
#endif
		default:
			break;
		}
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}

	if ((f->usage == CB_USAGE_PACKED || f->usage == CB_USAGE_COMP_6) &&
	    cb_fits_int (src)) {
		if (f->pic->scale < 0) {
			return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
		}
		val = cb_get_int (src);
		n = f->pic->scale - l->scale;
		if ((l->size + n) > 9) {
			return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
		}
		for (; n > 0; n--) {
			val *= 10;
		}
		for (; n < 0; n++) {
			val /= 10;
		}
		if (val == 0) {
			return cb_build_move_num_zero (dst);
		}
		if (val < 0 && !f->pic->have_sign) {
			val = -val;
		}
#if	1	/* RXWRXW - Set packed */
		return CB_BUILD_FUNCALL_2 ("cob_set_packed_int", dst,
					   cb_int (val));
#else
		return CB_BUILD_FUNCALL_2 ("cob_set_packed_int", dst,
					   cb_build_cast_llint (src));
#endif
	}
	return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
}

static cb_tree
cb_build_move_field (cb_tree src, cb_tree dst)
{
	struct cb_field	*src_f;
	struct cb_field	*dst_f;
	int		src_size;
	int		dst_size;

	src_f = CB_FIELD_PTR (src);
	src_size = cb_field_size (src);
	dst_f = CB_FIELD_PTR (dst);
	dst_size = cb_field_size (dst);

	if (dst_f->flag_any_length || src_f->flag_any_length) {
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}
	if (src_size > 0 && dst_size > 0 && src_size >= dst_size &&
	    !cb_field_variable_size (src_f) &&
	    !cb_field_variable_size (dst_f)) {
		switch (CB_TREE_CATEGORY (src)) {
		case CB_CATEGORY_ALPHABETIC:
			if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_ALPHABETIC ||
			    CB_TREE_CATEGORY (dst) == CB_CATEGORY_ALPHANUMERIC) {
				if (dst_f->flag_justified == 0) {
					return cb_build_move_copy (src, dst);
				}
			}
			break;
		case CB_CATEGORY_ALPHANUMERIC:
			if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_ALPHANUMERIC) {
				if (dst_f->flag_justified == 0) {
					return cb_build_move_copy (src, dst);
				}
			}
			break;
		case CB_CATEGORY_NUMERIC:
			if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC &&
			    src_f->usage == dst_f->usage &&
			    src_f->pic->size == dst_f->pic->size &&
			    src_f->pic->digits == dst_f->pic->digits &&
			    src_f->pic->scale == dst_f->pic->scale &&
			    src_f->pic->have_sign == dst_f->pic->have_sign &&
			    src_f->flag_binary_swap == dst_f->flag_binary_swap &&
			    src_f->flag_sign_leading == dst_f->flag_sign_leading &&
			    src_f->flag_sign_separate == dst_f->flag_sign_separate) {
				return cb_build_move_copy (src, dst);
			} else if (CB_TREE_CATEGORY (dst) == CB_CATEGORY_ALPHANUMERIC
				 && src_f->usage == CB_USAGE_DISPLAY
				 && src_f->pic->have_sign == 0
				 && !src_f->flag_sign_leading
				 && !src_f->flag_sign_separate) {
				return cb_build_move_copy (src, dst);
			}
			break;
		default:
			break;
		}
	}

	return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
}

cb_tree
cb_build_move (cb_tree src, cb_tree dst)
{
	struct cb_reference	*x;

	if (src == cb_error_node || dst == cb_error_node) {
		return cb_error_node;
	}

	if (validate_move (src, dst, 0) < 0) {
		return cb_error_node;
	}

#if	0	/* Flag receiving */
	if (CB_REFERENCE_P (src)) {
		CB_REFERENCE (src)->flag_receiving = 0;
	}
#endif

	if (CB_REFERENCE_P (dst)) {
		/* Clone reference */
		x = cobc_parse_malloc (sizeof(struct cb_reference));
		*x = *CB_REFERENCE (dst);
		x->flag_receiving = 1;
		dst = CB_TREE (x);
	}

	if ((src == cb_space || src == cb_low ||
	     src == cb_high || src == cb_quote) &&
	    (CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC ||
	     CB_TREE_CATEGORY (dst) == CB_CATEGORY_NUMERIC_EDITED)) {
		src = cb_zero;
	}

	if (CB_TREE_CLASS (dst) == CB_CLASS_POINTER ||
	    CB_TREE_CLASS (src) == CB_CLASS_POINTER) {
		return cb_build_assign (dst, src);
	}

	if (CB_REFERENCE_P (src) &&
	    CB_ALPHABET_NAME_P(CB_REFERENCE(src)->value)) {
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}
	if (CB_INDEX_P (dst)) {
		if (src == cb_null) {
			return cb_build_assign (dst, cb_zero);
		}
		return cb_build_assign (dst, src);
	}

	if (CB_INDEX_P (src)) {
		return CB_BUILD_FUNCALL_2 ("cob_set_int", dst,
					   cb_build_cast_int (src));
	}

	if (CB_INTRINSIC_P (src) || CB_INTRINSIC_P (dst)) {
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}

	if (CB_REFERENCE_P (src) && CB_REFERENCE (src)->check) {
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}
	if (CB_REFERENCE_P (dst) && CB_REFERENCE (dst)->check) {
		return CB_BUILD_FUNCALL_2 ("cob_move", src, dst);
	}

	/* Output optimal code */
	if (src == cb_zero) {
		return cb_build_move_zero (dst);
	} else if (src == cb_space) {
		return cb_build_move_space (dst);
	} else if (src == cb_high) {
		return cb_build_move_high (dst);
	} else if (src == cb_low) {
		return cb_build_move_low (dst);
	} else if (src == cb_quote) {
		return cb_build_move_quote (dst);
	} else if (CB_LITERAL_P (src)) {
		return cb_build_move_literal (src, dst);
	}
	return cb_build_move_field (src, dst);
}

void
cb_emit_move (cb_tree src, cb_tree dsts)
{
	cb_tree		l;
	cb_tree		x;
	cb_tree		m;
	unsigned int	tempval;

	if (cb_validate_one (src)) {
		return;
	}
	if (cb_validate_list (dsts)) {
		return;
	}

	cb_check_data_incompat (src);

	tempval = 0;
	if (cb_list_length (dsts) > 1) {
		if (CB_INTRINSIC_P (src) || (CB_REFERENCE_P (src) &&
		    (CB_REFERENCE (src)->subs || CB_REFERENCE (src)->offset))) {
			tempval = 1;
			cb_emit (CB_BUILD_FUNCALL_1 ("cob_put_indirect_field",
						     src));
		}
	}

	for (l = dsts; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (CB_LITERAL_P (x) || CB_CONST_P (x)) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid MOVE target - %s"), cb_name (x));
			continue;
		}
		if (!tempval) {
			m = cb_build_move (src, x);
		} else {
			m = CB_BUILD_FUNCALL_1 ("cob_get_indirect_field", x);
		}
		cb_emit (m);
	}
}

/* OPEN statement */

void
cb_emit_open (cb_tree file, cb_tree mode, cb_tree sharing)
{
	struct cb_file	*f;

	if (file == cb_error_node) {
		return;
	}
	file = cb_ref (file);
	if (file == cb_error_node) {
		return;
	}
	current_statement->file = file;
	f = CB_FILE (file);

	if (f->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on SORT files"));
		return;
	} else if (f->organization == COB_ORG_LINE_SEQUENTIAL &&
		   mode == cb_int (COB_OPEN_I_O)) {
		cb_error_x (CB_TREE (current_statement),
			    _("OPEN I-O not allowed on LINE SEQUENTIAL files"));
		return;
	}
	if (sharing == NULL) {
		if (f->sharing) {
			sharing = f->sharing;
		} else {
			sharing = cb_int0;
		}
	}

	cb_emit (CB_BUILD_FUNCALL_4 ("cob_open", file, mode,
		 sharing, f->file_status));

	/* Check for file debugging */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    f->flag_fl_debug) {
		cb_emit (cb_build_debug (cb_debug_name, f->name, NULL));
		cb_emit (cb_build_move (cb_space, cb_debug_contents));
		cb_emit (cb_build_debug_call (f->debug_section));
	}
}

/* PERFORM statement */

void
cb_emit_perform (cb_tree perform, cb_tree body)
{
	if (perform == cb_error_node) {
		return;
	}
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug && CB_PAIR_P (body)) {
		cb_emit (cb_build_debug (cb_debug_contents, "PERFORM LOOP", NULL));
	}
	CB_PERFORM (perform)->body = body;
	cb_emit (perform);
}

cb_tree
cb_build_perform_once (cb_tree body)
{
	cb_tree x;

	if (body == cb_error_node) {
		return cb_error_node;
	}
	x = cb_build_perform (CB_PERFORM_ONCE);
	CB_PERFORM (x)->body = body;
	return x;
}

cb_tree
cb_build_perform_times (cb_tree times)
{
	cb_tree		x;

	if (cb_check_integer_value (times) == cb_error_node) {
		return cb_error_node;
	}

	x = cb_build_perform (CB_PERFORM_TIMES);
	CB_PERFORM (x)->data = times;
	return x;
}

cb_tree
cb_build_perform_until (cb_tree condition, cb_tree varying)
{
	cb_tree		x;

	x = cb_build_perform (CB_PERFORM_UNTIL);
	CB_PERFORM (x)->test = condition;
	CB_PERFORM (x)->varying = varying;
	return x;
}

cb_tree
cb_build_perform_forever (cb_tree body)
{
	cb_tree		x;

	if (body == cb_error_node) {
		return cb_error_node;
	}
	x = cb_build_perform (CB_PERFORM_FOREVER);
	CB_PERFORM (x)->body = body;
	return x;
}

cb_tree
cb_build_perform_exit (struct cb_label *label)
{
	cb_tree		x;

	x = cb_build_perform (CB_PERFORM_EXIT);
	CB_PERFORM (x)->data = CB_TREE (label);
	return x;
}

/* READ statement */

void
cb_emit_read (cb_tree ref, cb_tree next, cb_tree into,
	      cb_tree key, cb_tree lock_opts)
{
	cb_tree		file;
	cb_tree		rec;
	cb_tree		x;
	struct cb_file	*f;
	int		read_opts;

	read_opts = 0;
	if (lock_opts == cb_int1) {
		read_opts = COB_READ_LOCK;
	} else if (lock_opts == cb_int2) {
		read_opts = COB_READ_NO_LOCK;
	} else if (lock_opts == cb_int3) {
		read_opts = COB_READ_IGNORE_LOCK;
	} else if (lock_opts == cb_int4) {
		read_opts = COB_READ_WAIT_LOCK;
	}
	if (ref == cb_error_node) {
		return;
	}
	file = cb_ref (ref);
	if (file == cb_error_node) {
		return;
	}
	f = CB_FILE (file);

	rec = cb_build_field_reference (f->record, ref);
	if (f->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on SORT files"));
		return;
	}
	if (next == cb_int1 || next == cb_int2 ||
	    f->access_mode == COB_ACCESS_SEQUENTIAL) {
		/* READ NEXT/PREVIOUS */
		if (next == cb_int2) {
			switch (f->organization) {
			case COB_ORG_INDEXED:
			case COB_ORG_RELATIVE:
				break;
			default:
				cb_error_x (CB_TREE (current_statement),
				_("READ PREVIOUS not allowed for this file type"));
				return;
			}
			read_opts |= COB_READ_PREVIOUS;
		} else {
			read_opts |= COB_READ_NEXT;
		}
		if (key) {
			cb_warning (_("KEY ignored with sequential READ"));
		}
		cb_emit (CB_BUILD_FUNCALL_3 ("cob_read_next", file,
			 f->file_status,
			 cb_int (read_opts)));
	} else {
		/* READ */
		/* DYNAMIC with [NOT] AT END */
		if (f->access_mode == COB_ACCESS_DYNAMIC &&
		    current_statement->handler_id == COB_EC_I_O_AT_END) {
			read_opts |= COB_READ_NEXT;
			cb_emit (CB_BUILD_FUNCALL_3 ("cob_read_next", file,
				 f->file_status,
				 cb_int (read_opts)));
		} else if (key || f->key) {
			cb_emit (CB_BUILD_FUNCALL_4 ("cob_read",
				 file, key ? key : f->key,
				 f->file_status, cb_int (read_opts)));
		} else {
			cb_emit (CB_BUILD_FUNCALL_3 ("cob_read_next", file,
				 f->file_status,
				 cb_int (read_opts)));
		}
	}
	if (into) {
		current_statement->handler3 = cb_build_move (rec, into);
	}

	/* Check for file debugging */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    f->flag_fl_debug) {
		if (into) {
			current_statement->handler3 =
				CB_LIST_INIT (current_statement->handler3);
		}
		x = cb_build_debug (cb_debug_name, f->name, NULL);
		current_statement->handler3 =
			cb_list_add (current_statement->handler3, x);
		x = cb_build_move (rec, cb_debug_contents);
		current_statement->handler3 =
			cb_list_add (current_statement->handler3, x);
		x = cb_build_debug_call (f->debug_section);
		current_statement->handler3 =
			cb_list_add (current_statement->handler3, x);
	}
	current_statement->file = file;
}

/* READY TRACE statement */

void
cb_emit_ready_trace (void)
{
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_ready_trace"));
}


/* RESET TRACE statement */

void
cb_emit_reset_trace (void)
{
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_reset_trace"));
}

/* REWRITE statement */

void
cb_emit_rewrite (cb_tree record, cb_tree from, cb_tree lockopt)
{
	cb_tree		file;
	struct cb_file	*f;
	int		opts;

	if (cb_validate_one (record)) {
		return;
	}
	if (cb_validate_one (from)) {
		return;
	}
	if (!CB_REF_OR_FIELD_P (cb_ref (record))) {
		cb_error_x (CB_TREE (current_statement),
			_("REWRITE requires a record name as subject"));
		return;
	}
	if (CB_FIELD_PTR (record)->storage != CB_STORAGE_FILE) {
		cb_error_x (CB_TREE (current_statement),
			_("REWRITE subject does not refer to a record name"));
		return;
	}

	file = CB_TREE (CB_FIELD (cb_ref (record))->file);
	if (!file || file == cb_error_node) {
		return;
	}
	current_statement->file = file;
	f = CB_FILE (file);
	opts = 0;

	if (f->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
		_("Operation not allowed on SORT files"));
		return;
	} else if (f->organization == COB_ORG_LINE_SEQUENTIAL) {
		cb_error_x (CB_TREE (current_statement),
			    _("Operation not allowed on LINE SEQUENTIAL files"));
		return;
	} else if (current_statement->handler_id == COB_EC_I_O_INVALID_KEY &&
		  (f->organization != COB_ORG_RELATIVE &&
		   f->organization != COB_ORG_INDEXED)) {
			cb_error_x (CB_TREE(current_statement),
			_("INVALID KEY clause invalid with this file type"));
		return;
	} else if ((f->lock_mode & COB_LOCK_AUTOMATIC) && lockopt) {
		cb_error_x (CB_TREE (current_statement),
		_("LOCK clause invalid with file LOCK AUTOMATIC"));
		return;
	} else if (lockopt == cb_int1) {
		opts = COB_WRITE_LOCK;
	}

	if (from) {
		cb_emit (cb_build_move (from, record));
	}

	/* Check debugging on record name */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    CB_FIELD_PTR (record)->flag_field_debug) {
		cb_emit (cb_build_debug (cb_debug_name,
					 CB_FIELD_PTR (record)->name, NULL));
		cb_emit (cb_build_move (record, cb_debug_contents));
		cb_emit (cb_build_debug_call (CB_FIELD_PTR (record)->debug_section));
	}
	cb_emit (CB_BUILD_FUNCALL_4 ("cob_rewrite", file, record,
			cb_int (opts), f->file_status));
}

/* RELEASE statement */

void
cb_emit_release (cb_tree record, cb_tree from)
{
	struct cb_field	*f;
	cb_tree		file;

	if (cb_validate_one (record)) {
		return;
	}
	if (cb_validate_one (from)) {
		return;
	}
	if (!CB_REF_OR_FIELD_P (cb_ref (record))) {
		cb_error_x (CB_TREE (current_statement),
			_("RELEASE requires a record name as subject"));
		return;
	}
	f = CB_FIELD_PTR (record);
	if (f->storage != CB_STORAGE_FILE) {
		cb_error_x (CB_TREE (current_statement),
			_("RELEASE subject does not refer to a record name"));
		return;
	}
	file = CB_TREE (f->file);
	if (CB_FILE (file)->organization != COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
			_("RELEASE not allowed on this record item"));
		return;
	}
	current_statement->file = file;
	if (from) {
		cb_emit (cb_build_move (from, record));
	}
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_file_release", file));
}

/* RETURN statement */

void
cb_emit_return (cb_tree ref, cb_tree into)
{
	cb_tree		file;
	cb_tree		rec;

	if (cb_validate_one (ref)) {
		return;
	}
	if (cb_validate_one (into)) {
		return;
	}
	file = cb_ref (ref);
	if (file == cb_error_node) {
		return;
	}
	rec = cb_build_field_reference (CB_FILE (file)->record, ref);
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_file_return", file));
	if (into) {
		current_statement->handler3 = cb_build_move (rec, into);
	}
	current_statement->file = file;
}

/* ROLLBACK statement */

void
cb_emit_rollback (void)
{
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_rollback"));
}

/* SEARCH statement */

static unsigned int
search_set_keys (struct cb_field *f, cb_tree x)
{
	struct cb_binary_op	*p;
	struct cb_field		*fldx;
	struct cb_field		*fldy;
	int			i;

	if (CB_REFERENCE_P (x)) {
		x = build_cond_88 (x);
		if (!x || x == cb_error_node) {
			return 1;
		}
	}

	p = CB_BINARY_OP (x);
	switch (p->op) {
	case '&':
		if (search_set_keys (f, p->x)) {
			return 1;
		}
		if (search_set_keys (f, p->y)) {
			return 1;
		}
		break;
	case '=':
		fldx = NULL;
		fldy = NULL;
		/* One of the operands must be a key reference */
		if (CB_REF_OR_FIELD_P (p->x)) {
			fldx = CB_FIELD_PTR (p->x);
		}
		if (CB_REF_OR_FIELD_P (p->y)) {
			fldy = CB_FIELD_PTR (p->y);
		}
		if (!fldx && !fldy) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid SEARCH ALL condition"));
			return 1;
		}

		for (i = 0; i < f->nkeys; ++i) {
			if (fldx == CB_FIELD_PTR (f->keys[i].key)) {
				f->keys[i].ref = p->x;
				f->keys[i].val = p->y;
				break;
			}
		}
		if (i == f->nkeys) {
			for (i = 0; i < f->nkeys; ++i) {
				if (fldy == CB_FIELD_PTR (f->keys[i].key)) {
					f->keys[i].ref = p->y;
					f->keys[i].val = p->x;
					break;
				}
			}
			if (i == f->nkeys) {
				cb_error_x (CB_TREE (current_statement),
					    _("Invalid SEARCH ALL condition"));
				return 1;
			}
		}
		break;
	default:
		cb_error_x (CB_TREE (current_statement),
			    _("Invalid SEARCH ALL condition"));
		return 1;
	}
	return 0;
}

static cb_tree
cb_build_search_all (cb_tree table, cb_tree cond)
{
	cb_tree		c1;
	cb_tree		c2;
	struct cb_field	*f;
	int		i;

	f = CB_FIELD_PTR (table);
	/* Set keys */
	for (i = 0; i < f->nkeys; i++) {
		f->keys[i].ref = NULL;
	}
	if (search_set_keys (f, cond)) {
		return NULL;
	}
	c1 = NULL;

	/* Build condition */
	for (i = 0; i < f->nkeys; i++) {
		if (f->keys[i].ref) {
			if (f->keys[i].dir == COB_ASCENDING) {
				c2 = cb_build_binary_op (f->keys[i].ref, '=',
							 f->keys[i].val);
			} else {
				c2 = cb_build_binary_op (f->keys[i].val, '=',
							 f->keys[i].ref);
			}
			if (c1 == NULL) {
				c1 = c2;
			} else {
				c1 = cb_build_binary_op (c1, '&', c2);
			}
		}
	}

	if (!c1) {
		return NULL;
	}
	return cb_build_cond (c1);
}

void
cb_emit_search (cb_tree table, cb_tree varying, cb_tree at_end, cb_tree whens)
{
	if (cb_validate_one (table)) {
		return;
	}
	if (cb_validate_one (varying)) {
		return;
	}
	if (table == cb_error_node) {
		return;
	}
	if (whens == cb_error_node) {
		return;
	}
	whens = cb_list_reverse (whens);
	cb_emit (cb_build_search (0, table, varying,
				  cb_check_needs_break (at_end), whens));
}

void
cb_emit_search_all (cb_tree table, cb_tree at_end, cb_tree when, cb_tree stmts)
{
	cb_tree		x;
	cb_tree		stmt_lis;

	if (cb_validate_one (table)) {
		return;
	}
	if (table == cb_error_node) {
		return;
	}
	if (when == cb_error_node) {
		return;
	}
	x = cb_build_search_all (table, when);
	if (!x) {
		return;
	}

	stmt_lis = cb_check_needs_break (stmts);
	cb_emit (cb_build_search (1, table, NULL,
				  cb_check_needs_break (at_end),
				  cb_build_if (x, stmt_lis, NULL, 0)));
}

/* SET statement */

void
cb_emit_setenv (cb_tree x, cb_tree y)
{
	cb_emit (CB_BUILD_FUNCALL_2 ("cob_set_environment", x, y));
}

void
cb_emit_set_to (cb_tree vars, cb_tree x)
{
	cb_tree		l;
	cb_tree		v;
	struct cb_cast	*p;
	enum cb_class	class;

	if (cb_validate_one (x)) {
		return;
	}
	if (cb_validate_list (vars)) {
		return;
	}

#if	0	/* RXWRXW - target check */
	/* Determine class of targets */
	for (l = vars; l; l = CB_CHAIN (l)) {
		if (CB_TREE_CLASS (CB_VALUE (l)) != CB_CLASS_UNKNOWN) {
			if (class == CB_CLASS_UNKNOWN) {
				class = CB_TREE_CLASS (CB_VALUE (l));
			} else if (class != CB_TREE_CLASS (CB_VALUE (l))) {
				break;
			}
		}
	}
	if (l || (class != CB_CLASS_INDEX && class != CB_CLASS_POINTER)) {
		cb_error_x (CB_TREE (current_statement),
			    _("The targets of SET must be either indexes or pointers"));
		return;
	}
#endif

	if (CB_CAST_P (x)) {
		p = CB_CAST (x);
		if (p->cast_type == CB_CAST_PROGRAM_POINTER) {
			for (l = vars; l; l = CB_CHAIN (l)) {
				v = CB_VALUE (l);
				if (!CB_REFERENCE_P (v)) {
					cb_error_x (CB_TREE (current_statement),
					_("SET targets must be PROGRAM-POINTER"));
					CB_VALUE (l) = cb_error_node;
				} else if (CB_FIELD(cb_ref(v))->usage != CB_USAGE_PROGRAM_POINTER) {
					cb_error_x (CB_TREE (current_statement),
					_("SET targets must be PROGRAM-POINTER"));
					CB_VALUE (l) = cb_error_node;
				}
			}
		}
	}
	/* Validate the targets */
	for (l = vars; l; l = CB_CHAIN (l)) {
		v = CB_VALUE (l);
		if (!CB_CAST_P (v)) {
			continue;
		}
		p = CB_CAST (v);
		if (p->cast_type == CB_CAST_ADDRESS &&
		    !CB_FIELD (cb_ref (p->val))->flag_item_based &&
		    CB_FIELD (cb_ref (p->val))->storage != CB_STORAGE_LINKAGE) {
			cb_error_x (p->val, _("The address of '%s' cannot be changed"),
				    cb_name (p->val));
			CB_VALUE (l) = cb_error_node;
		}
	}
	if (cb_validate_list (vars)) {
		return;
	}

	for (l = vars; l; l = CB_CHAIN (l)) {
		class = cb_tree_class (CB_VALUE (l));
		switch (class) {
		case CB_CLASS_INDEX:
		case CB_CLASS_NUMERIC:
		case CB_CLASS_POINTER:
			cb_check_data_incompat (x);
			cb_emit (cb_build_move (x, CB_VALUE (l)));
			break;
		default:
			cb_error_x (CB_TREE (current_statement),
				    _("SET target is invalid - '%s'"),
				    cb_name (CB_VALUE(l)));
			break;
		}
	}
}

void
cb_emit_set_up_down (cb_tree l, cb_tree flag, cb_tree x)
{
	if (cb_validate_one (x)) {
		return;
	}
	if (cb_validate_list (l)) {
		return;
	}
	for (; l; l = CB_CHAIN (l)) {
		if (flag == cb_int0) {
			cb_emit (cb_build_add (CB_VALUE (l), x, cb_int0));
		} else {
			cb_emit (cb_build_sub (CB_VALUE (l), x, cb_int0));
		}
	}
}

void
cb_emit_set_on_off (cb_tree l, cb_tree flag)
{
	struct cb_system_name *s;

	if (cb_validate_list (l)) {
		return;
	}
	for (; l; l = CB_CHAIN (l)) {
		s = CB_SYSTEM_NAME (cb_ref (CB_VALUE (l)));
		cb_emit (CB_BUILD_FUNCALL_2 ("cob_set_switch",
					     cb_int (s->token), flag));
	}
}

void
cb_emit_set_true (cb_tree l)
{
	cb_tree		x;
	struct cb_field *f;
	cb_tree		ref;
	cb_tree		val;

	for (; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (x == cb_error_node) {
			return;
		}
		if (!(CB_REFERENCE_P (x) && CB_FIELD_P(CB_REFERENCE(x)->value)) &&
		    !CB_FIELD_P (x)) {
			cb_error_x (x, _("Invalid SET statement"));
			return;
		}
		f = CB_FIELD_PTR (x);
		if (f->level != 88) {
			cb_error_x (x, _("Invalid SET statement"));
			return;
		}
		ref = cb_build_field_reference (f->parent, x);
		val = CB_VALUE (f->values);
		if (CB_PAIR_P (val)) {
			val = CB_PAIR_X (val);
		}
		cb_emit (cb_build_move (val, ref));
	}
}

void
cb_emit_set_false (cb_tree l)
{
	cb_tree		x;
	struct cb_field *f;
	cb_tree		ref;
	cb_tree		val;

	for (; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (x == cb_error_node) {
			return;
		}
		if (!(CB_REFERENCE_P (x) && CB_FIELD_P(CB_REFERENCE(x)->value)) &&
		    !CB_FIELD_P (x)) {
			cb_error_x (x, _("Invalid SET statement"));
			return;
		}
		f = CB_FIELD_PTR (x);
		if (f->level != 88) {
			cb_error_x (x, _("Invalid SET statement"));
			return;
		}
		if (!f->false_88) {
			cb_error_x (x, _("Field does not have FALSE clause"));
			return;
		}
		ref = cb_build_field_reference (f->parent, x);
		val = CB_VALUE (f->false_88);
		if (CB_PAIR_P (val)) {
			val = CB_PAIR_X (val);
		}
		cb_emit (cb_build_move (val, ref));
	}
}

void
cb_emit_set_attribute (cb_tree x, const int val_on, const int val_off)
{
	struct cb_field		*f;

	if (cb_validate_one (x)) {
		return;
	}
	if (!CB_REF_OR_FIELD_P (cb_ref (x))) {
		cb_error_x (CB_TREE (current_statement),
			_("SET ATTRIBUTE requires a screen item as subject"));
		return;
	}
	f = CB_FIELD_PTR (x);
	if (f->storage != CB_STORAGE_SCREEN) {
		cb_error_x (CB_TREE (current_statement),
			_("SET ATTRIBUTE subject does not refer to a screen item"));
		return;
	}
	cb_emit (cb_build_set_attribute (f, val_on, val_off));
}

/* SORT statement */

void
cb_emit_sort_init (cb_tree name, cb_tree keys, cb_tree col)
{
	cb_tree			l;
	struct cb_field		*f;

	if (cb_validate_list (keys)) {
		return;
	}
	if (cb_ref (name) == cb_error_node) {
		return;
	}
	for (l = keys; l; l = CB_CHAIN (l)) {
		if (CB_VALUE (l) == NULL) {
			CB_VALUE (l) = name;
		}
		cb_ref (CB_VALUE (l));
	}

	if (CB_FILE_P (cb_ref (name))) {
		if (CB_FILE (cb_ref (name))->organization != COB_ORG_SORT) {
			cb_error_x (name, _("Invalid SORT filename"));
		}
		CB_FIELD_PTR (current_program->cb_sort_return)->count++;
		cb_emit (CB_BUILD_FUNCALL_5 ("cob_file_sort_init", cb_ref (name),
					     cb_int (cb_list_length (keys)), col,
					     CB_BUILD_CAST_ADDRESS (current_program->cb_sort_return),
					     CB_FILE(cb_ref (name))->file_status));
		for (l = keys; l; l = CB_CHAIN (l)) {
			cb_emit (CB_BUILD_FUNCALL_4 ("cob_file_sort_init_key",
					cb_ref (name),
					CB_VALUE (l),
					CB_PURPOSE (l),
					cb_int (CB_FIELD_PTR (CB_VALUE(l))->offset)));
		}
	} else {
		if (keys == NULL) {
			cb_error_x (name, _("Table sort without keys not implemented yet"));
		}
		cb_emit (CB_BUILD_FUNCALL_2 ("cob_table_sort_init",
					     cb_int (cb_list_length (keys)), col));
		for (l = keys; l; l = CB_CHAIN (l)) {
			cb_emit (CB_BUILD_FUNCALL_3 ("cob_table_sort_init_key",
					CB_VALUE (l),
					CB_PURPOSE (l),
					cb_int (CB_FIELD_PTR (CB_VALUE(l))->offset)));
		}
		f = CB_FIELD (cb_ref (name));
		cb_emit (CB_BUILD_FUNCALL_2 ("cob_table_sort", name,
					     (f->depending
					      ? cb_build_cast_int (f->depending)
					      : cb_int (f->occurs_max))));
	}
}

void
cb_emit_sort_using (cb_tree file, cb_tree l)
{
	if (cb_validate_list (l)) {
		return;
	}
	for (; l; l = CB_CHAIN (l)) {
		if (CB_FILE (cb_ref(CB_VALUE(l)))->organization == COB_ORG_SORT) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid SORT USING parameter"));
		}
		cb_emit (CB_BUILD_FUNCALL_2 ("cob_file_sort_using",
			cb_ref (file), cb_ref (CB_VALUE (l))));
	}
}

void
cb_emit_sort_input (cb_tree proc)
{
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug) {
		cb_emit (cb_build_debug (cb_debug_contents, "SORT INPUT", NULL));
	}
	cb_emit (cb_build_perform_once (proc));
}

void
cb_emit_sort_giving (cb_tree file, cb_tree l)
{
	cb_tree		p;
	int		listlen;

	if (cb_validate_list (l)) {
		return;
	}
	for (p = l; p; p = CB_CHAIN (p)) {
		if (CB_FILE (cb_ref(CB_VALUE(p)))->organization == COB_ORG_SORT) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid SORT GIVING parameter"));
		}
	}
	listlen = cb_list_length (l);
	p = CB_BUILD_FUNCALL_2 ("cob_file_sort_giving", cb_ref (file), l);
	CB_FUNCALL(p)->varcnt = listlen;
	cb_emit (p);
}

void
cb_emit_sort_output (cb_tree proc)
{
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug) {
		if (current_statement->flag_merge) {
			cb_emit (cb_build_debug (cb_debug_contents,
						 "MERGE OUTPUT", NULL));
		} else {
			cb_emit (cb_build_debug (cb_debug_contents,
						 "SORT OUTPUT", NULL));
		}
	}
	cb_emit (cb_build_perform_once (proc));
}

void
cb_emit_sort_finish (cb_tree file)
{
	if (CB_FILE_P (cb_ref (file))) {
		cb_emit (CB_BUILD_FUNCALL_1 ("cob_file_sort_close", cb_ref (file)));
	}
}

/* START statement */

static unsigned int
check_valid_key (const struct cb_file *cbf, const struct cb_field *f)
{
	cb_tree			kfld;
	struct cb_alt_key	*cbak;
	struct cb_field		*f1;
	struct cb_field		*ff;

	if (cbf->organization != COB_ORG_INDEXED) {
		if (CB_FIELD_PTR (cbf->key) != f) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid key item"));
			return 1;
		}
		return 0;
	}

	ff = cb_field_founder (f);
	for (f1 = cbf->record; f1; f1 = f1->sister) {
		if (f1 == ff) {
			break;
		}
	}
	if (!f1) {
		cb_error_x (CB_TREE (current_statement), _("Invalid key item"));
		return 1;
	}

	kfld = cb_ref (cbf->key);
	if (kfld == cb_error_node) {
		return 1;
	}
	if (f->offset == CB_FIELD_PTR (kfld)->offset) {
		return 0;
	}
	for (cbak = cbf->alt_key_list; cbak; cbak = cbak->next) {
		kfld = cb_ref (cbak->key);
		if (kfld == cb_error_node) {
			return 1;
		}
		if (f->offset == CB_FIELD_PTR (kfld)->offset) {
			return 0;
		}
	}
	cb_error_x (CB_TREE (current_statement), _("Invalid key item"));
	return 1;
}

void
cb_emit_start (cb_tree file, cb_tree op, cb_tree key, cb_tree keylen)
{
	cb_tree			kfld;
	cb_tree			fl;
	cb_tree			cbtkey;
	struct cb_file		*f;

	if (cb_validate_one (key)) {
		return;
	}
	if (cb_validate_one (keylen)) {
		return;
	}
	if (file == cb_error_node) {
		return;
	}
	fl = cb_ref (file);
	if (fl == cb_error_node) {
		return;
	}
	f = CB_FILE (fl);

	if (f->organization != COB_ORG_INDEXED &&
	    f->organization != COB_ORG_RELATIVE) {
		cb_error_x (CB_TREE (current_statement),
			    _("START not allowed on SEQUENTIAL files"));
		return;
	}
	if (keylen && f->organization != COB_ORG_INDEXED) {
		cb_error_x (CB_TREE (current_statement),
			    _("LENGTH/SIZE clause only allowed on INDEXED files"));
		return;
	}
	if (f->access_mode == COB_ACCESS_RANDOM) {
		cb_error_x (CB_TREE (current_statement),
			    _("START not allowed with ACCESS MODE RANDOM"));
		return;
	}

	current_statement->file = fl;
	if (key) {
		kfld = cb_ref (key);
		if (kfld == cb_error_node) {
			return;
		}
		if (check_valid_key (f, CB_FIELD_PTR (kfld))) {
			return;
		}
		cbtkey = key;
	} else {
		cbtkey = f->key;
	}

	/* Check for file debugging */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    f->flag_fl_debug) {
		/* Gen callback after start but before exception test */
		current_statement->flag_callback = 1;
	}

	cb_emit (CB_BUILD_FUNCALL_5 ("cob_start", fl, op, cbtkey, keylen,
				     f->file_status));
}

/* STOP statement */

void
cb_emit_stop_run (cb_tree x)
{
	cb_emit (CB_BUILD_FUNCALL_1 ("cob_stop_run", cb_build_cast_int (x)));
}

/* STRING statement */

void
cb_emit_string (cb_tree items, cb_tree into, cb_tree pointer)
{
	cb_tree start;
	cb_tree l;
	cb_tree end;
	cb_tree dlm;

	if (cb_validate_one (into)) {
		return;
	}
	if (cb_validate_one (pointer)) {
		return;
	}
	start = items;
	cb_emit (CB_BUILD_FUNCALL_2 ("cob_string_init", into, pointer));
	while (start) {

		/* Find DELIMITED item */
		for (end = start; end; end = CB_CHAIN (end)) {
			if (CB_PAIR_P (CB_VALUE (end))) {
				break;
			}
		}

		/* cob_string_delimited */
		dlm = end ? CB_PAIR_X (CB_VALUE (end)) : NULL;
		if (dlm == cb_int0) {
			dlm = NULL;
		}
		cb_emit (CB_BUILD_FUNCALL_1 ("cob_string_delimited", dlm));

		/* cob_string_append */
		for (l = start; l != end; l = CB_CHAIN (l)) {
			cb_emit (CB_BUILD_FUNCALL_1 ("cob_string_append",
						     CB_VALUE (l)));
		}

		start = end ? CB_CHAIN (end) : NULL;
	}
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_string_finish"));
}

/* UNLOCK statement */

void
cb_emit_unlock (cb_tree ref)
{
	cb_tree	file;

	if (ref != cb_error_node) {
		file = cb_ref (ref);
		if (file != cb_error_node) {
			cb_emit (CB_BUILD_FUNCALL_2 ("cob_unlock_file",
				 file, CB_FILE(file)->file_status));
			current_statement->file = file;
		}
	}
}

/* UNSTRING statement */

void
cb_emit_unstring (cb_tree name, cb_tree delimited, cb_tree into,
		  cb_tree pointer, cb_tree tallying)
{
	if (cb_validate_one (name)) {
		return;
	}
	if (cb_validate_one (tallying)) {
		return;
	}
	if (cb_validate_list (delimited)) {
		return;
	}
	if (cb_validate_list (into)) {
		return;
	}
	cb_emit (CB_BUILD_FUNCALL_3 ("cob_unstring_init", name, pointer,
		cb_int (cb_list_length (delimited))));
	cb_emit_list (delimited);
	cb_emit_list (into);
	if (tallying) {
		cb_emit (CB_BUILD_FUNCALL_1 ("cob_unstring_tallying", tallying));
	}
	cb_emit (CB_BUILD_FUNCALL_0 ("cob_unstring_finish"));
}

cb_tree
cb_build_unstring_delimited (cb_tree all, cb_tree value)
{
	if (cb_validate_one (value)) {
		return cb_error_node;
	}
	return CB_BUILD_FUNCALL_2 ("cob_unstring_delimited", value, all);
}

cb_tree
cb_build_unstring_into (cb_tree name, cb_tree delimiter, cb_tree count)
{
	if (cb_validate_one (name)) {
		return cb_error_node;
	}
	if (delimiter == NULL) {
		delimiter = cb_int0;
	}
	if (count == NULL) {
		count = cb_int0;
	}
	return CB_BUILD_FUNCALL_3 ("cob_unstring_into", name, delimiter, count);
}

/* WRITE statement */

void
cb_emit_write (cb_tree record, cb_tree from, cb_tree opt, cb_tree lockopt)
{
	cb_tree		file;
	cb_tree		check_eop;
	struct cb_file	*f;

	if (cb_validate_one (record)) {
		return;
	}
	if (cb_validate_one (from)) {
		return;
	}
	if (!CB_REF_OR_FIELD_P (cb_ref (record))) {
		cb_error_x (CB_TREE (current_statement),
			_("WRITE requires a record name as subject"));
		return;
	}
	if (CB_FIELD_PTR (record)->storage != CB_STORAGE_FILE) {
		cb_error_x (CB_TREE (current_statement),
			_("WRITE subject does not refer to a record name"));
		return;
	}
	file = CB_TREE (CB_FIELD (cb_ref (record))->file);
	if (!file || file == cb_error_node) {
		return;
	}
	current_statement->file = file;
	f = CB_FILE (file);

	if (f->organization == COB_ORG_SORT) {
		cb_error_x (CB_TREE (current_statement),
		_("Operation not allowed on SORT files"));
	} else if (current_statement->handler_id == COB_EC_I_O_INVALID_KEY &&
		  (f->organization != COB_ORG_RELATIVE &&
		   f->organization != COB_ORG_INDEXED)) {
			cb_error_x (CB_TREE(current_statement),
			_("INVALID KEY clause invalid with this file type"));
	} else if (lockopt) {
		if (f->lock_mode & COB_LOCK_AUTOMATIC) {
			cb_error_x (CB_TREE (current_statement),
			_("LOCK clause invalid with file LOCK AUTOMATIC"));
		} else if (opt != cb_int0) {
			cb_error_x (CB_TREE (current_statement),
			_("LOCK clause invalid here"));
		} else if (lockopt == cb_int1) {
			opt = cb_int (COB_WRITE_LOCK);
		}
	}

	if (from) {
		cb_emit (cb_build_move (from, record));
	}

	/* Check debugging on record name */
	if (current_program->flag_debugging &&
	    !current_statement->flag_in_debug &&
	    CB_FIELD_PTR (record)->flag_field_debug) {
		cb_emit (cb_build_debug (cb_debug_name,
					 CB_FIELD_PTR (record)->name, NULL));
		cb_emit (cb_build_move (record, cb_debug_contents));
		cb_emit (cb_build_debug_call (CB_FIELD_PTR (record)->debug_section));
	}
	if (f->organization == COB_ORG_LINE_SEQUENTIAL &&
	    opt == cb_int0) {
		if (cb_flag_write_after || CB_FILE (file)->flag_line_adv) {
			opt = cb_int_hex (COB_WRITE_AFTER | COB_WRITE_LINES | 1);
		} else {
			opt = cb_int_hex (COB_WRITE_BEFORE | COB_WRITE_LINES | 1);
		}
	}
	if (current_statement->handler_id == COB_EC_I_O_EOP &&
	    current_statement->handler1) {
		check_eop = cb_int1;
	} else {
		check_eop = cb_int0;
	}
	cb_emit (CB_BUILD_FUNCALL_5 ("cob_write", file, record, opt,
				     f->file_status, check_eop));
}

cb_tree
cb_build_write_advancing_lines (cb_tree pos, cb_tree lines)
{
	cb_tree	e;
	int	opt;

	opt = (pos == CB_BEFORE) ? COB_WRITE_BEFORE : COB_WRITE_AFTER;
	opt |= COB_WRITE_LINES;
	if (CB_LITERAL_P (lines)) {
		opt |= cb_get_int (lines);
		return cb_int_hex (opt);
	}
	e = cb_build_binary_op (cb_int (opt), '+', lines);
	return cb_build_cast_int (e);
}

cb_tree
cb_build_write_advancing_mnemonic (cb_tree pos, cb_tree mnemonic)
{
	int	opt;
	int	token;

	if (mnemonic == cb_error_node) {
		return cb_int0;
	}
	if (cb_ref (mnemonic) == cb_error_node) {
		return cb_int0;
	}
	token = CB_SYSTEM_NAME (cb_ref (mnemonic))->token;
	switch (token) {
	case CB_FEATURE_FORMFEED:
		opt = (pos == CB_BEFORE) ? COB_WRITE_BEFORE : COB_WRITE_AFTER;
		return cb_int_hex (opt | COB_WRITE_PAGE);
	case CB_FEATURE_C01:
	case CB_FEATURE_C02:
	case CB_FEATURE_C03:
	case CB_FEATURE_C04:
	case CB_FEATURE_C05:
	case CB_FEATURE_C06:
	case CB_FEATURE_C07:
	case CB_FEATURE_C08:
	case CB_FEATURE_C09:
	case CB_FEATURE_C10:
	case CB_FEATURE_C11:
	case CB_FEATURE_C12:
		opt = (pos == CB_BEFORE) ? COB_WRITE_BEFORE : COB_WRITE_AFTER;
		return cb_int_hex (opt | COB_WRITE_CHANNEL | COB_WRITE_PAGE | token);
	default:
		cb_error_x (mnemonic, _("Invalid mnemonic name"));
		return cb_int0;
	}
}

cb_tree
cb_build_write_advancing_page (cb_tree pos)
{
	int opt = (pos == CB_BEFORE) ? COB_WRITE_BEFORE : COB_WRITE_AFTER;

	return cb_int_hex (opt | COB_WRITE_PAGE);
}

#ifndef	HAVE_DESIGNATED_INITS
void
cobc_init_typeck (void)
{
	const unsigned char	*p;

	memset (valid_char, 0, sizeof(valid_char));
	for (p = pvalid_char; *p; ++p) {
		valid_char[*p] = 1;
	}
	memset(expr_prio, 0, sizeof(expr_prio));
	expr_prio['x' & 0xFF] = 0;
	expr_prio['^' & 0xFF] = 1;
	expr_prio['*' & 0xFF] = 2;
	expr_prio['/' & 0xFF] = 2;
	expr_prio['+' & 0xFF] = 3;
	expr_prio['-' & 0xFF] = 3;
	expr_prio['=' & 0xFF] = 4;
	expr_prio['~' & 0xFF] = 4;
	expr_prio['<' & 0xFF] = 4;
	expr_prio['>' & 0xFF] = 4;
	expr_prio['[' & 0xFF] = 4;
	expr_prio[']' & 0xFF] = 4;
	expr_prio['!' & 0xFF] = 5;
	expr_prio['&' & 0xFF] = 6;
	expr_prio['|' & 0xFF] = 7;
	expr_prio[')' & 0xFF] = 8;
	expr_prio['(' & 0xFF] = 9;
	expr_prio[0] = 10;
}
#endif
