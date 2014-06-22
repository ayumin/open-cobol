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

#include "cobc.h"
#include "tree.h"

#define PIC_ALPHABETIC		0x01
#define PIC_NUMERIC		0x02
#define PIC_NATIONAL		0x04
#define PIC_EDITED		0x08
#define PIC_ALPHANUMERIC	(PIC_ALPHABETIC | PIC_NUMERIC)
#define PIC_ALPHABETIC_EDITED	(PIC_ALPHABETIC | PIC_EDITED)
#define PIC_ALPHANUMERIC_EDITED	(PIC_ALPHANUMERIC | PIC_EDITED)
#define PIC_NUMERIC_EDITED	(PIC_NUMERIC | PIC_EDITED)
#define PIC_NATIONAL_EDITED	(PIC_NATIONAL | PIC_EDITED)

/* Local variables */

static const enum cb_class category_to_class_table[] = {
	CB_CLASS_UNKNOWN,	/* CB_CATEGORY_UNKNOWN */
	CB_CLASS_ALPHABETIC,	/* CB_CATEGORY_ALPHABETIC */
	CB_CLASS_ALPHANUMERIC,	/* CB_CATEGORY_ALPHANUMERIC */
	CB_CLASS_ALPHANUMERIC,	/* CB_CATEGORY_ALPHANUMERIC_EDITED */
	CB_CLASS_BOOLEAN,	/* CB_CATEGORY_BOOLEAN */
	CB_CLASS_INDEX,		/* CB_CATEGORY_INDEX */
	CB_CLASS_NATIONAL,	/* CB_CATEGORY_NATIONAL */
	CB_CLASS_NATIONAL,	/* CB_CATEGORY_NATIONAL_EDITED */
	CB_CLASS_NUMERIC,	/* CB_CATEGORY_NUMERIC */
	CB_CLASS_ALPHANUMERIC,	/* CB_CATEGORY_NUMERIC_EDITED */
	CB_CLASS_OBJECT,	/* CB_CATEGORY_OBJECT_REFERENCE */
	CB_CLASS_POINTER,	/* CB_CATEGORY_DATA_POINTER */
	CB_CLASS_POINTER	/* CB_CATEGORY_PROGRAM_POINTER */
};

static int category_is_alphanumeric[] = {
	0,	/* CB_CATEGORY_UNKNOWN */
	1,	/* CB_CATEGORY_ALPHABETIC */
	1,	/* CB_CATEGORY_ALPHANUMERIC */
	1,	/* CB_CATEGORY_ALPHANUMERIC_EDITED */
	0,	/* CB_CATEGORY_BOOLEAN */
	0,	/* CB_CATEGORY_INDEX */
	1,	/* CB_CATEGORY_NATIONAL */
	1,	/* CB_CATEGORY_NATIONAL_EDITED */
	0,	/* CB_CATEGORY_NUMERIC */
	1,	/* CB_CATEGORY_NUMERIC_EDITED */
	0,	/* CB_CATEGORY_OBJECT_REFERENCE */
	0,	/* CB_CATEGORY_DATA_POINTER */
	0	/* CB_CATEGORY_PROGRAM_POINTER */
};

struct int_node {
	struct int_node	*next;
	cb_tree		node;
	int		n;
};

static struct int_node		*int_node_table = NULL;
static char			*scratch_buff = NULL;
static char			*pic_buff = NULL;
static int			filler_id = 1;
static int			class_id = 0;
static int			toplev_count;
static struct cb_program	*container_progs[64];
static const char		* const cb_const_subs[] = {
	"i0",
	"i1",
	"i2",
	"i3",
	"i4",
	"i5",
	"i6",
	"i7",
	"i8",
	"i9",
	"i10",
	"i11",
	"i12",
	"i13",
	"i14",
	"i15",
	NULL
};

static struct cb_intrinsic_table	userbp =
	{ "USER FUNCTION", "cob_user_function", -1, 1,
	  CB_INTR_USER_FUNCTION, CB_CATEGORY_NUMERIC,
	  0, 0, 0 };

/* Global variables */

/* Constants */

cb_tree cb_any;
cb_tree cb_true;
cb_tree cb_false;
cb_tree cb_null;
cb_tree cb_zero;
cb_tree cb_one;
cb_tree cb_space;
cb_tree cb_low;
cb_tree cb_high;
cb_tree cb_norm_low;
cb_tree cb_norm_high;
cb_tree cb_quote;
cb_tree cb_int0;
cb_tree cb_int1;
cb_tree cb_int2;
cb_tree cb_int3;
cb_tree cb_int4;
cb_tree cb_int5;
cb_tree cb_i[COB_MAX_SUBSCRIPTS];
cb_tree cb_error_node;

cb_tree cb_intr_whencomp = NULL;

cb_tree cb_standard_error_handler = NULL;

unsigned int	gen_screen_ptr = 0;

/* Local functions */

static size_t
hash (const unsigned char *s)
{
	size_t	val;
	size_t	pos;

	/* Hash a name */
	/* We multiply by position to get a better distribution */
	val = 0;
	pos = 1;
	for (; *s; s++, pos++) {
		val += pos * toupper (*s);
	}
#if	0	/* RXWRXW - Hash remainder */
	return val % CB_WORD_HASH_SIZE;
#endif
	return val & CB_WORD_HASH_MASK;
}

static void
lookup_word (struct cb_reference *p, const char *name)
{
	struct cb_word	*w;
	size_t		val;

	val = hash ((const unsigned char *)name);
	/* Find an existing word */
	if (likely(current_program)) {
		for (w = current_program->word_table[val]; w; w = w->next) {
			if (strcasecmp (w->name, name) == 0) {
				p->word = w;
				p->hashval = val;
				p->flag_duped = 1;
				return;
			}
		}
	}

	/* Create new word */
	w = cobc_parse_malloc (sizeof (struct cb_word));
	w->name = cobc_parse_strdup (name);

	/* Insert it into the table */
	if (likely(current_program)) {
		w->next = current_program->word_table[val];
		current_program->word_table[val] = w;
	}
	p->word = w;
	p->hashval = val;
}

static void
file_error (cb_tree name, const char *clause)
{
	cb_error_x (name, _("%s clause is required for file '%s'"), clause,
		    CB_NAME (name));
}

/* Tree */

static void *
make_tree (const enum cb_tag tag, const enum cb_category category,
	   const size_t size)
{
	cb_tree x;

	x = cobc_parse_malloc (size);
	x->tag = tag;
	x->category = category;
	return x;
}

static cb_tree
make_constant (const enum cb_category category, const char *val)
{
	struct cb_const *p;

	p = make_tree (CB_TAG_CONST, category, sizeof (struct cb_const));
	p->val = val;
	return CB_TREE (p);
}

static cb_tree
make_constant_label (const char *name)
{
	struct cb_label *p;

	p = CB_LABEL (cb_build_label (cb_build_reference (name), NULL));
	p->flag_begin = 1;
	return CB_TREE (p);
}

static size_t
cb_name_1 (char *s, cb_tree x)
{
	char			*orig;
	struct cb_funcall	*cbip;
	struct cb_binary_op	*cbop;
	struct cb_reference	*p;
	struct cb_field		*f;
	struct cb_intrinsic	*cbit;
	cb_tree			l;
	int			i;

	orig = s;
	if (!x) {
		strcpy (s, "(void pointer)");
		return strlen (orig);
	}
	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x == cb_any) {
			strcpy (s, "ANY");
		} else if (x == cb_true) {
			strcpy (s, "TRUE");
		} else if (x == cb_false) {
			strcpy (s, "FALSE");
		} else if (x == cb_null) {
			strcpy (s, "NULL");
		} else if (x == cb_zero) {
			strcpy (s, "ZERO");
		} else if (x == cb_space) {
			strcpy (s, "SPACE");
		} else if (x == cb_low || x == cb_norm_low) {
			strcpy (s, "LOW-VALUE");
		} else if (x == cb_high || x == cb_norm_high) {
			strcpy (s, "HIGH-VALUE");
		} else if (x == cb_quote) {
			strcpy (s, "QUOTE");
		} else if (x == cb_error_node) {
			strcpy (s, _("Internal error node"));
		} else {
			strcpy (s, _("Unknown constant"));
		}
		break;

	case CB_TAG_LITERAL:
		if (CB_TREE_CLASS (x) == CB_CLASS_NUMERIC) {
			strcpy (s, (char *)CB_LITERAL (x)->data);
		} else {
			sprintf (s, "\"%s\"", (char *)CB_LITERAL (x)->data);
		}
		break;

	case CB_TAG_FIELD:
		f = CB_FIELD (x);
		if (f->flag_filler) {
			strcpy (s, "FILLER");
		} else {
			strcpy (s, f->name);
		}
		break;

	case CB_TAG_REFERENCE:
		p = CB_REFERENCE (x);
		if (p->flag_filler_ref) {
			s += sprintf (s, "FILLER");
		} else {
			s += sprintf (s, "%s", p->word->name);
		}
		if (p->subs) {
			s += sprintf (s, " (");
			p->subs = cb_list_reverse (p->subs);
			for (l = p->subs; l; l = CB_CHAIN (l)) {
				s += cb_name_1 (s, CB_VALUE (l));
				s += sprintf (s, CB_CHAIN (l) ? ", " : ")");
			}
			p->subs = cb_list_reverse (p->subs);
		}
		if (p->offset) {
			s += sprintf (s, " (");
			s += cb_name_1 (s, p->offset);
			s += sprintf (s, ":");
			if (p->length) {
				s += cb_name_1 (s, p->length);
			}
			strcpy (s, ")");
		}
		if (p->chain) {
			s += sprintf (s, " in ");
			s += cb_name_1 (s, p->chain);
		}
		break;

	case CB_TAG_LABEL:
		sprintf (s, "%s", (char *)(CB_LABEL (x)->name));
		break;

	case CB_TAG_ALPHABET_NAME:
		sprintf (s, "%s", CB_ALPHABET_NAME (x)->name);
		break;

	case CB_TAG_CLASS_NAME:
		sprintf (s, "%s", CB_CLASS_NAME (x)->name);
		break;

	case CB_TAG_LOCALE_NAME:
		sprintf (s, "%s", CB_LOCALE_NAME (x)->name);
		break;

	case CB_TAG_BINARY_OP:
		cbop = CB_BINARY_OP (x);
		if (cbop->op == '@') {
			s += sprintf (s, "(");
			s += cb_name_1 (s, cbop->x);
			s += sprintf (s, ")");
		} else if (cbop->op == '!') {
			s += sprintf (s, "!");
			s += cb_name_1 (s, cbop->x);
		} else {
			s += sprintf (s, "(");
			s += cb_name_1 (s, cbop->x);
			s += sprintf (s, " %c ", cbop->op);
			s += cb_name_1 (s, cbop->y);
			strcpy (s, ")");
		}
		break;

	case CB_TAG_FUNCALL:
		cbip = CB_FUNCALL (x);
		s += sprintf (s, "%s", cbip->name);
		for (i = 0; i < cbip->argc; i++) {
			s += sprintf (s, (i == 0) ? "(" : ", ");
			s += cb_name_1 (s, cbip->argv[i]);
		}
		s += sprintf (s, ")");
		break;

	case CB_TAG_INTRINSIC:
		cbit = CB_INTRINSIC (x);
		if (cbit->isuser) {
			sprintf (s, "USER FUNCTION");
		} else {
			sprintf (s, "FUNCTION %s", cbit->intr_tab->name);
		}
		break;

	case CB_TAG_FILE:
		sprintf (s, "FILE %s", CB_FILE (x)->name);
		break;

	case CB_TAG_REPORT:
		sprintf (s, "REPORT %s", CB_REPORT (CB_VALUE (x))->name);
		break;

	default:
		sprintf (s, _("<Unexpected tree tag %d>"), (int)CB_TREE_TAG (x));
	}

	return strlen (orig);
}

static cb_tree
make_intrinsic (cb_tree name, struct cb_intrinsic_table *cbp, cb_tree args,
		cb_tree field, cb_tree refmod, const int isuser)
{
	struct cb_intrinsic *x;

#if	0	/* RXWRXW Leave in, we may need this */
	cb_tree			l;
	for (l = args; l; l = CB_CHAIN(l)) {
		switch (CB_TREE_TAG (CB_VALUE(l))) {
		case CB_TAG_CONST:
		case CB_TAG_INTEGER:
		case CB_TAG_LITERAL:
		case CB_TAG_DECIMAL:
		case CB_TAG_FIELD:
		case CB_TAG_REFERENCE:
		case CB_TAG_INTRINSIC:
			break;
		default:
			cb_error (_("FUNCTION %s has invalid/not supported arguments - Tag %d"),
				cbp->name, CB_TREE_TAG(l));
			return cb_error_node;

		}
	}
#endif

	x = make_tree (CB_TAG_INTRINSIC, cbp->category, sizeof (struct cb_intrinsic));
	x->name = name;
	x->args = args;
	x->intr_tab = cbp;
	x->intr_field = field;
	x->isuser = isuser;
	if (refmod) {
		x->offset = CB_PAIR_X (refmod);
		x->length = CB_PAIR_Y (refmod);
	}
	return CB_TREE (x);
}

static cb_tree
global_check (struct cb_reference *r, cb_tree items, size_t *ambiguous)
{
	cb_tree			candidate;
	struct cb_field		*p;
	cb_tree			v;
	cb_tree			c;

	candidate = NULL;
	for (; items; items = CB_CHAIN (items)) {
		/* Find a candidate value by resolving qualification */
		v = CB_VALUE (items);
		c = r->chain;
		if (CB_FIELD_P (v)) {
			if (!CB_FIELD (v)->flag_is_global) {
				continue;
			}
			/* In case the value is a field, it might be qualified
			   by its parent names and a file name */
			if (CB_FIELD (v)->flag_indexed_by) {
				p = CB_FIELD (v)->index_qual;
			} else {
				p = CB_FIELD (v)->parent;
			}
			/* Resolve by parents */
			for (; p; p = p->parent) {
				if (c && strcasecmp (CB_NAME (c), p->name) == 0) {
					c = CB_REFERENCE (c)->chain;
				}
			}

			/* Resolve by file */
			if (c && CB_REFERENCE (c)->chain == NULL) {
				if (CB_WORD_COUNT (c) == 1 &&
				    CB_FILE_P (cb_ref (c)) &&
				    (CB_FILE (cb_ref (c)) == cb_field_founder (CB_FIELD (v))->file)) {
					c = CB_REFERENCE (c)->chain;
				}
			}
		}
		/* A well qualified value is a good candidate */
		if (c == NULL) {
			if (candidate == NULL) {
				/* Keep the first candidate */
				candidate = v;
			} else {
				/* Multiple candidates and possibly ambiguous */
				*ambiguous = 1;
			}
		}
	}
	return candidate;
}

/* Global functions */

char *
cb_to_cname (const char *s)
{
	char		*copy;
	unsigned char	*p;

	copy = cobc_parse_strdup (s);
	for (p = (unsigned char *)copy; *p; p++) {
		if (*p == '-' || *p == ' ') {
			*p = '_';
		} else {
			*p = (cob_u8_t)toupper (*p);
		}
	}
	return copy;
}

struct cb_literal *
build_literal (const enum cb_category category, const void *data,
	       const size_t size)
{
	struct cb_literal *p;

	p = make_tree (CB_TAG_LITERAL, category, sizeof (struct cb_literal));
	p->data = cobc_parse_malloc (size + 1U);
	p->size = size;
	memcpy (p->data, data, size);
	return p;
}

char *
cb_name (cb_tree x)
{
	char	*s;

	s = cobc_parse_malloc ((size_t)COB_NORMAL_BUFF);
	(void)cb_name_1 (s, x);
	return s;
}

enum cb_category
cb_tree_category (cb_tree x)
{
	struct cb_cast		*p;
	struct cb_reference	*r;
	struct cb_field		*f;

	if (x == cb_error_node) {
		return (enum cb_category)0;
	}
	if (x->category != CB_CATEGORY_UNKNOWN) {
		return x->category;
	}

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CAST:
		p = CB_CAST (x);
		switch (p->cast_type) {
		case CB_CAST_ADDRESS:
		case CB_CAST_ADDR_OF_ADDR:
			x->category = CB_CATEGORY_DATA_POINTER;
			break;
		case CB_CAST_PROGRAM_POINTER:
			x->category = CB_CATEGORY_PROGRAM_POINTER;
			break;
		default:
			cobc_abort_pr (_("Unexpected cast type -> %d"),
					(int)(p->cast_type));
			COBC_ABORT ();
		}
		break;
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (x);
		if (r->offset) {
			x->category = CB_CATEGORY_ALPHANUMERIC;
		} else {
			x->category = cb_tree_category (r->value);
		}
		break;
	case CB_TAG_FIELD:
		f = CB_FIELD (x);
		if (f->children) {
			x->category = CB_CATEGORY_ALPHANUMERIC;
		} else if (f->usage == CB_USAGE_POINTER && f->level != 88) {
			x->category = CB_CATEGORY_DATA_POINTER;
		} else if (f->usage == CB_USAGE_PROGRAM_POINTER && f->level != 88) {
			x->category = CB_CATEGORY_PROGRAM_POINTER;
		} else {
			switch (f->level) {
			case 66:
				if (f->rename_thru) {
					x->category = CB_CATEGORY_ALPHANUMERIC;
				} else {
					x->category = cb_tree_category (CB_TREE (f->redefines));
				}
				break;
			case 88:
				x->category = CB_CATEGORY_BOOLEAN;
				break;
			default:
				if (f->pic) {
					x->category = f->pic->category;
				} else {
					x->category = (enum cb_category)0;
				}
				break;
			}
		}
		break;
	case CB_TAG_ALPHABET_NAME:
	case CB_TAG_LOCALE_NAME:
		x->category = CB_CATEGORY_ALPHANUMERIC;
		break;
	case CB_TAG_BINARY_OP:
		x->category = CB_CATEGORY_BOOLEAN;
		break;
	case CB_TAG_INTRINSIC:
		x->category = CB_INTRINSIC(x)->intr_tab->category;
		break;
	default:
#if	0	/* RXWRXW - Tree tag */
		cobc_abort_pr (_("Unknown tree tag %d Category %d"),
				(int)CB_TREE_TAG (x), (int)x->category);
		COBC_ABORT ();
#endif
		return CB_CATEGORY_UNKNOWN;
	}

	return x->category;
}

enum cb_class
cb_tree_class (cb_tree x)
{

	return category_to_class_table[CB_TREE_CATEGORY (x)];
}

int
cb_category_is_alpha (cb_tree x)
{
	return category_is_alphanumeric[CB_TREE_CATEGORY (x)];
}

int
cb_tree_type (const cb_tree x, const struct cb_field *f)
{
	if (f->children) {
		return COB_TYPE_GROUP;
	}

	switch (CB_TREE_CATEGORY (x)) {
	case CB_CATEGORY_ALPHABETIC:
	case CB_CATEGORY_ALPHANUMERIC:
		return COB_TYPE_ALPHANUMERIC;
	case CB_CATEGORY_ALPHANUMERIC_EDITED:
		return COB_TYPE_ALPHANUMERIC_EDITED;
	case CB_CATEGORY_NUMERIC:
		switch (f->usage) {
		case CB_USAGE_DISPLAY:
			return COB_TYPE_NUMERIC_DISPLAY;
		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
		case CB_USAGE_INDEX:
		case CB_USAGE_LENGTH:
			return COB_TYPE_NUMERIC_BINARY;
		case CB_USAGE_FLOAT:
			return COB_TYPE_NUMERIC_FLOAT;
		case CB_USAGE_DOUBLE:
			return COB_TYPE_NUMERIC_DOUBLE;
		case CB_USAGE_PACKED:
		case CB_USAGE_COMP_6:
			return COB_TYPE_NUMERIC_PACKED;
		case CB_USAGE_LONG_DOUBLE:
			return COB_TYPE_NUMERIC_L_DOUBLE;
		case CB_USAGE_FP_BIN32:
			return COB_TYPE_NUMERIC_FP_BIN32;
		case CB_USAGE_FP_BIN64:
			return COB_TYPE_NUMERIC_FP_BIN64;
		case CB_USAGE_FP_BIN128:
			return COB_TYPE_NUMERIC_FP_BIN128;
		case CB_USAGE_FP_DEC64:
			return COB_TYPE_NUMERIC_FP_DEC64;
		case CB_USAGE_FP_DEC128:
			return COB_TYPE_NUMERIC_FP_DEC128;
		default:
			cobc_abort_pr (_("Unexpected numeric usage -> %d"),
					(int)f->usage);
			COBC_ABORT ();
		}
	case CB_CATEGORY_NUMERIC_EDITED:
		return COB_TYPE_NUMERIC_EDITED;
	case CB_CATEGORY_OBJECT_REFERENCE:
	case CB_CATEGORY_DATA_POINTER:
	case CB_CATEGORY_PROGRAM_POINTER:
		return COB_TYPE_NUMERIC_BINARY;
	default:
		cobc_abort_pr (_("Unexpected category -> %d"),
				(int)CB_TREE_CATEGORY (x));
		/* Use dumb variant */
		COBC_DUMB_ABORT ();
	}
	/* NOT REACHED */
	return 0;
}

int
cb_fits_int (const cb_tree x)
{
	struct cb_literal	*l;
	struct cb_field		*f;
	const char		*s;
	const unsigned char	*p;
	size_t			size;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_LITERAL:
		l = CB_LITERAL (x);
		if (l->scale > 0) {
			return 0;
		}
		for (size = 0, p = l->data; size < l->size; ++size, ++p) {
			if (*p != (unsigned char)'0') {
				break;
			}
		}
		size = l->size - size;
		if (size < 10) {
			return 1;
		}
		if (size > 10) {
			return 0;
		}
		if (l->sign < 0) {
			s = "2147483648";
		} else {
			s = "2147483647";
		}
		if (memcmp (p, s, (size_t)10) > 0) {
			return 0;
		}
		return 1;
	case CB_TAG_FIELD:
		f = CB_FIELD (x);
		if (f->children) {
			return 0;
		}
		switch (f->usage) {
		case CB_USAGE_INDEX:
		case CB_USAGE_LENGTH:
			return 1;
		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
			if (f->pic->scale <= 0 && f->size <= (int)sizeof (int)) {
				return 1;
			}
			return 0;
		case CB_USAGE_DISPLAY:
			if (f->size < 10) {
				if (!f->pic || f->pic->scale <= 0) {
					return 1;
				}
			}
			return 0;
		case CB_USAGE_PACKED:
		case CB_USAGE_COMP_6:
			if (f->pic->scale <= 0 && f->pic->digits < 10) {
				return 1;
			}
			return 0;
		default:
			return 0;
		}
	case CB_TAG_REFERENCE:
		return cb_fits_int (CB_REFERENCE (x)->value);
	case CB_TAG_INTEGER:
		return 1;
	default:
		return 0;
	}
}

int
cb_fits_long_long (const cb_tree x)
{
	struct cb_literal	*l;
	struct cb_field		*f;
	const char		*s;
	const unsigned char	*p;
	size_t			size;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_LITERAL:
		l = CB_LITERAL (x);
		if (l->scale > 0) {
			return 0;
		}
		for (size = 0, p = l->data; size < l->size; ++size, ++p) {
			if (*p != (unsigned char)'0') {
				break;
			}
		}
		size = l->size - size;
		if (size < 19) {
			return 1;
		}
		if (size > 19) {
			return 0;
		}
		if (l->sign < 0) {
			s = "9223372036854775808";
		} else {
			s = "9223372036854775807";
		}
		if (memcmp (p, s, (size_t)19) > 0) {
			return 0;
		}
		return 1;
	case CB_TAG_FIELD:
		f = CB_FIELD (x);
		if (f->children) {
			return 0;
		}
		switch (f->usage) {
		case CB_USAGE_INDEX:
		case CB_USAGE_LENGTH:
			return 1;
		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
			if (f->pic->scale <= 0 &&
			    f->size <= (int)sizeof (cob_s64_t)) {
				return 1;
			}
			return 0;
		case CB_USAGE_DISPLAY:
			if (f->pic->scale <= 0 && f->size < 19) {
				return 1;
			}
			return 0;
		case CB_USAGE_PACKED:
		case CB_USAGE_COMP_6:
			if (f->pic->scale <= 0 && f->pic->digits < 19) {
				return 1;
			}
			return 0;
		default:
			return 0;
		}
	case CB_TAG_REFERENCE:
		return cb_fits_long_long (CB_REFERENCE (x)->value);
	case CB_TAG_INTEGER:
		return 1;
	default:
		return 0;
	}
}

int
cb_get_int (const cb_tree x)
{
	struct cb_literal	*l;
#if	0	/* RXWRXW Fixme SZ */
	const char		*s;
	size_t			size;
#endif
	size_t			i;
	int			val;

	if(x == NULL)		return 0;
	if(x == cb_int0)	return 0;
	if(x == cb_int1)	return 1;
	if(x == cb_int2)	return 2;
	if(x == cb_int3)	return 3;
	if(x == cb_int4)	return 4;
	if(x == cb_int5)	return 5;
	if (!CB_LITERAL_P (x)) {
		cobc_abort_pr (_("Invalid literal cast - Aborting"));
		COBC_ABORT ();
	}
	l = CB_LITERAL (x);
	for (i = 0; i < l->size; i++) {
		if (l->data[i] != '0') {
			break;
		}
	}

#if	0	/* RXWRXW Fixme SZ */
	if (l->sign < 0) {
		s = "2147483648";
	} else {
		s = "2147483647";
	}
	size = l->size - i;
	if (size > 10U || (size == 10U && memcmp (&l->data[i], s, 10) > 0)) {
		cobc_abort_pr (_("Numeric literal exceeds limit - Aborting"));
		COBC_ABORT ();
	}
#endif

	val = 0;
	for (; i < l->size; i++) {
		val = val * 10 + l->data[i] - '0';
	}
	if (val && l->sign < 0) {
		val = -val;
	}
	return val;
}

cob_s64_t
cb_get_long_long (const cb_tree x)
{
	struct cb_literal	*l;
	const char		*s;
	size_t			i;
	size_t			size;
	cob_s64_t		val;

	if (!CB_LITERAL_P (x)) {
		cobc_abort_pr (_("Invalid literal cast - Aborting"));
		COBC_ABORT ();
	}
	l = CB_LITERAL (x);
	for (i = 0; i < l->size; i++) {
		if (l->data[i] != '0') {
			break;
		}
	}

	size = l->size - i;
	if (size > 19U) {
		cobc_abort_pr (_("Numeric literal exceeds limit - Aborting"));
		COBC_ABORT ();
	}
	if (size == 19U) {
		if (l->sign < 0) {
			s = "9223372036854775808";
		} else {
			s = "9223372036854775807";
		}
		if (memcmp (&(l->data[i]), s, (size_t)19) > 0) {
			cobc_abort_pr (_("Numeric literal exceeds limit - Aborting"));
			COBC_ABORT ();
		}
	}

	val = 0;
	for (; i < l->size; i++) {
		val = val * 10 + (l->data[i] & 0x0F);
	}
	if (val && l->sign < 0) {
		val = -val;
	}
	return val;
}

cob_u64_t
cb_get_u_long_long (const cb_tree x)
{
	struct cb_literal	*l;
	size_t			i;
	size_t			size;
	cob_u64_t		val;

	l = CB_LITERAL (x);
	for (i = 0; i < l->size; i++) {
		if (l->data[i] != '0') {
			break;
		}
	}

	size = l->size - i;
	if (size > 20U) {
		cobc_abort_pr (_("Numeric literal exceeds limit - Aborting"));
		COBC_ABORT ();
	}
	if (size == 20U) {
		if (memcmp (&(l->data[i]), "18446744073709551615", (size_t)20) > 0) {
			cobc_abort_pr (_("Numeric literal exceeds limit - Aborting"));
			COBC_ABORT ();
		}
	}
	val = 0;
	for (; i < l->size; i++) {
		val = val * 10 + (l->data[i] & 0x0F);
	}
	return val;
}

void
cb_init_constants (void)
{
	int	i;

	cb_error_node = make_constant (CB_CATEGORY_UNKNOWN, NULL);
	cb_any = make_constant (CB_CATEGORY_UNKNOWN, NULL);
	cb_true = make_constant (CB_CATEGORY_BOOLEAN, "1");
	cb_false = make_constant (CB_CATEGORY_BOOLEAN, "0");
	cb_null = make_constant (CB_CATEGORY_DATA_POINTER, "0");
	cb_zero = make_constant (CB_CATEGORY_NUMERIC, "&cob_all_zero");
	cb_space = make_constant (CB_CATEGORY_ALPHANUMERIC, "&cob_all_space");
	cb_low = make_constant (CB_CATEGORY_ALPHANUMERIC, "&cob_all_low");
	cb_norm_low = cb_low;
	cb_high = make_constant (CB_CATEGORY_ALPHANUMERIC, "&cob_all_high");
	cb_norm_high = cb_high;
	cb_quote = make_constant (CB_CATEGORY_ALPHANUMERIC, "&cob_all_quote");
	cb_one = cb_build_numeric_literal (0, "1", 0);
	cb_int0 = cb_int (0);
	cb_int1 = cb_int (1);
	cb_int2 = cb_int (2);
	cb_int3 = cb_int (3);
	cb_int4 = cb_int (4);
	cb_int5 = cb_int (5);
	for (i = 0; i < COB_MAX_SUBSCRIPTS; i++) {
		cb_i[i] = make_constant (CB_CATEGORY_NUMERIC, cb_const_subs[i]);
	}
	cb_standard_error_handler = make_constant_label ("Default Error Handler");
	CB_LABEL (cb_standard_error_handler)->flag_default_handler = 1;
	memset (container_progs, 0, sizeof(container_progs));
}

/* List */

cb_tree
cb_build_list (cb_tree purpose, cb_tree value, cb_tree chain)
{
	struct cb_list *p;

	p = make_tree (CB_TAG_LIST, CB_CATEGORY_UNKNOWN, sizeof (struct cb_list));
	p->chain = chain;
	p->value = value;
	p->purpose = purpose;
	return CB_TREE (p);
}

cb_tree
cb_list_append (cb_tree l1, cb_tree l2)
{
	cb_tree	l;

	if (l1 == NULL) {
		return l2;
	}
	l = l1;
	while (CB_CHAIN (l)) {
		l = CB_CHAIN (l);
	}
	CB_CHAIN (l) = l2;
	return l1;
}

cb_tree
cb_list_add (cb_tree l, cb_tree x)
{
	return cb_list_append (l, CB_LIST_INIT (x));
}

cb_tree
cb_pair_add (cb_tree l, cb_tree x, cb_tree y)
{
	return cb_list_append (l, CB_BUILD_PAIR (x, y));
}

cb_tree
cb_list_reverse (cb_tree l)
{
	cb_tree	next;
	cb_tree	last;

	last = NULL;
	for (; l; l = next) {
		next = CB_CHAIN (l);
		CB_CHAIN (l) = last;
		last = l;
	}
	return last;
}

int
cb_list_length (cb_tree l)
{
	int	n;

	if (l == cb_error_node) {
		return 0;
	}
	n = 0;
	for (; l; l = CB_CHAIN (l)) {
		n++;
	}
	return n;
}

void
cb_list_map (cb_tree (*func) (cb_tree x), cb_tree l)
{
	for (; l; l = CB_CHAIN (l)) {
		CB_VALUE (l) = func (CB_VALUE (l));
	}
}

/* Link value into the reference */

const char *
cb_define (cb_tree name, cb_tree val)
{
	struct cb_word *w;

	w = CB_REFERENCE (name)->word;
	w->items = cb_list_add (w->items, val);
	w->count++;
	val->source_file = name->source_file;
	val->source_line = name->source_line;
	CB_REFERENCE (name)->value = val;
	return w->name;
}

/* Program */

static struct nested_list *
add_contained_prog (struct nested_list *parent_list, struct cb_program *child_prog)
{
	struct nested_list	*nlp;

	/* Check for reuse */
	for (nlp = parent_list; nlp; nlp = nlp->next) {
		if (nlp->nested_prog == child_prog) {
			return parent_list;
		}
	}
	nlp = cobc_parse_malloc (sizeof (struct nested_list));
	nlp->next = parent_list;
	nlp->nested_prog = child_prog;
	return nlp;
}

struct cb_program *
cb_build_program (struct cb_program *last_program, const int nest_level)
{
	struct cb_program	*p;
	struct cb_program	*q;

	if (!last_program) {
		toplev_count = 0;
	}
	cb_reset_78 ();
	cobc_in_procedure = 0;
	cobc_in_repository = 0;
	cobc_cs_check = 0;
	cb_clear_real_field ();

	p = cobc_parse_malloc (sizeof (struct cb_program));
	p->word_table = cobc_parse_malloc (CB_WORD_TABLE_SIZE);

	p->next_program = last_program;
	p->nested_level = nest_level;
	p->decimal_point = '.';
	p->currency_symbol = '$';
	p->numeric_separator = ',';
	/* Save current program as actual at it's level */
	container_progs[nest_level] = p;
	if (nest_level) {
		/* Contained program */
		/* Inherit from upper level */
		p->global_file_list = last_program->global_file_list;
		p->collating_sequence = last_program->collating_sequence;
		p->classification = last_program->classification;
		p->mnemonic_spec_list = last_program->mnemonic_spec_list;
		p->class_spec_list = last_program->class_spec_list;
		p->interface_spec_list = last_program->interface_spec_list;
		p->function_spec_list = last_program->function_spec_list;
		p->user_spec_list = last_program->user_spec_list;
		p->program_spec_list = last_program->program_spec_list;
		p->property_spec_list = last_program->property_spec_list;
		p->alphabet_name_list = last_program->alphabet_name_list;
		p->symbolic_char_list = last_program->symbolic_char_list;
		p->class_name_list = last_program->class_name_list;
		p->locale_list = last_program->locale_list;
		p->decimal_point = last_program->decimal_point;
		p->numeric_separator = last_program->numeric_separator;
		p->currency_symbol = last_program->currency_symbol;
		p->flag_trailing_separate = last_program->flag_trailing_separate;
		p->flag_console_is_crt = last_program->flag_console_is_crt;
		/* RETURN-CODE is global for contained programs */
		p->cb_return_code = last_program->cb_return_code;
		CB_FIELD_PTR (last_program->cb_return_code)->flag_is_global = 1;
		p->toplev_count = last_program->toplev_count;
		/* Add program to itself for possible recursion */
		p->nested_prog_list = add_contained_prog (p->nested_prog_list, p);
		/* Add contained program to it's parent */
		q = container_progs[nest_level - 1];
		q->nested_prog_list = add_contained_prog (q->nested_prog_list, p);
	} else {
		/* Top level program */
		p->toplev_count = toplev_count++;
		functions_are_all = cb_flag_functions_all;
		cb_reset_global_78 ();
	}
	return p;
}

void
cb_add_common_prog (struct cb_program *prog)
{
	struct cb_program	*q;

	/* Here we are sure that nested >= 1 */
	q = container_progs[prog->nested_level - 1];
	q->common_prog_list = add_contained_prog (q->common_prog_list, prog);
}

void
cb_insert_common_prog (struct cb_program *prog, struct cb_program *comprog)
{
	prog->nested_prog_list = add_contained_prog (prog->nested_prog_list,
						     comprog);
}

/* Integer */

cb_tree
cb_int (const int n)
{
	struct cb_integer	*x;
	struct int_node		*p;

	for (p = int_node_table; p; p = p->next) {
		if (p->n == n) {
			return p->node;
		}
	}

	/* Do not use make_tree here */
	x = cobc_main_malloc (sizeof (struct cb_integer));
	x->common.tag = CB_TAG_INTEGER;
	x->common.category = CB_CATEGORY_NUMERIC;
	x->val = n;

	p = cobc_main_malloc (sizeof (struct int_node));
	p->n = n;
	p->node = CB_TREE (x);
	p->next = int_node_table;
	int_node_table = p;
	return CB_TREE (x);
}

cb_tree
cb_int_hex (const int n)
{
	cb_tree		x;

	x = cb_int (n);
	CB_INTEGER (x)->hexval = 1;
	return x;
}

/* String */

cb_tree
cb_build_string (const void *data, const size_t size)
{
	struct cb_string *p;

	p = make_tree (CB_TAG_STRING, CB_CATEGORY_ALPHANUMERIC,
		       sizeof (struct cb_string));
	p->size = size;
	p->data = data;
	return CB_TREE (p);
}

/* Code output and comment */

cb_tree
cb_build_comment (const char *str)
{
	struct cb_direct *p;

	p = make_tree (CB_TAG_DIRECT, CB_CATEGORY_ALPHANUMERIC,
		       sizeof (struct cb_direct));
	p->line = str;
	CB_TREE (p)->source_file = cb_source_file;
	CB_TREE (p)->source_line = cb_source_line;
	return CB_TREE (p);
}

cb_tree
cb_build_direct (const char *str, const unsigned int flagnl)
{
	cb_tree		x;

	x = cb_build_comment (str);
	CB_DIRECT (x)->flag_is_direct = 1;
	CB_DIRECT (x)->flag_new_line = flagnl;
	return x;
}

/* DEBUG */

cb_tree
cb_build_debug (const cb_tree target, const char *str, const cb_tree fld)
{
	struct cb_debug	*p;

	p = make_tree (CB_TAG_DEBUG, CB_CATEGORY_ALPHANUMERIC,
		       sizeof (struct cb_debug));
	p->target = target;
	if (str) {
		p->value = cobc_parse_strdup (str);
		p->fld = NULL;
		p->size = strlen (str);
	} else {
		p->value = NULL;
		p->fld = fld;
		p->size = (size_t)CB_FIELD_PTR (fld)->size;
	}
	CB_TREE (p)->source_file = cb_source_file;
	CB_TREE (p)->source_line = cb_source_line;
	return CB_TREE (p);
}

/* DEBUG Callback */

cb_tree
cb_build_debug_call (struct cb_label *target)
{
	struct cb_debug_call	*p;

	p = make_tree (CB_TAG_DEBUG_CALL, CB_CATEGORY_ALPHANUMERIC,
		       sizeof (struct cb_debug_call));
	p->target = target;
	CB_TREE (p)->source_file = cb_source_file;
	CB_TREE (p)->source_line = cb_source_line;
	return CB_TREE (p);
}

/* Alphabet-name */

cb_tree
cb_build_alphabet_name (cb_tree name)
{
	struct cb_alphabet_name *p;

	if (!name || name == cb_error_node) {
		return NULL;
	}
	p = make_tree (CB_TAG_ALPHABET_NAME, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_alphabet_name));
	p->name = cb_define (name, CB_TREE (p));
	p->cname = cb_to_cname (p->name);
	return CB_TREE (p);
}

/* Class-name */

cb_tree
cb_build_class_name (cb_tree name, cb_tree list)
{
	struct cb_class_name	*p;

	if (!name || name == cb_error_node) {
		return NULL;
	}
	p = make_tree (CB_TAG_CLASS_NAME, CB_CATEGORY_BOOLEAN,
		       sizeof (struct cb_class_name));
	p->name = cb_define (name, CB_TREE (p));
	if (!scratch_buff) {
		scratch_buff = cobc_main_malloc ((size_t)COB_MINI_BUFF);
	}
	snprintf (scratch_buff, (size_t)COB_MINI_MAX, "cob_is_%s_%d",
		  cb_to_cname (p->name), class_id++);
	p->cname = cobc_parse_strdup (scratch_buff);
	p->list = list;
	return CB_TREE (p);
}

/* Locale-name */

cb_tree
cb_build_locale_name (cb_tree name, cb_tree list)
{
	struct cb_class_name	*p;

	if (!name || name == cb_error_node) {
		return NULL;
	}
	if (!CB_LITERAL_P (list) || CB_NUMERIC_LITERAL_P (list)) {
		cb_error (_("Invalid LOCALE literal"));
		return cb_error_node;
	}
	p = make_tree (CB_TAG_LOCALE_NAME, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_locale_name));
	p->name = cb_define (name, CB_TREE (p));
	p->cname = cb_to_cname (p->name);
	p->list = list;
	return CB_TREE (p);
}

/* System-name */

cb_tree
cb_build_system_name (const enum cb_system_name_category category, const int token)
{
	struct cb_system_name *p;

	p = make_tree (CB_TAG_SYSTEM_NAME, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_system_name));
	p->category = category;
	p->token = token;
	return CB_TREE (p);
}

/* Literal */

cb_tree
cb_build_numeric_literal (const int sign, const void *data,
			  const int scale)
{
	struct cb_literal *p;

	p = build_literal (CB_CATEGORY_NUMERIC, data, strlen (data));
	p->sign = (short)sign;
	p->scale = scale;
	return CB_TREE (p);
}

cb_tree
cb_build_numsize_literal (const void *data, const size_t size, const int sign)
{
	struct cb_literal *p;

	p = build_literal (CB_CATEGORY_NUMERIC, data, size);
	p->sign = (short)sign;
	return CB_TREE (p);
}

cb_tree
cb_build_alphanumeric_literal (const void *data, const size_t size)
{
	return CB_TREE (build_literal (CB_CATEGORY_ALPHANUMERIC, data, size));
}

cb_tree
cb_concat_literals (const cb_tree x1, const cb_tree x2)
{
	unsigned char		*data1;
	unsigned char		*data2;
	struct cb_literal	*p;
	size_t			size1;
	size_t			size2;

	if (x1 == cb_error_node || x2 == cb_error_node) {
		return cb_error_node;
	}
	if (CB_LITERAL_P (x1)) {
		data1 = CB_LITERAL (x1)->data;
		size1 = CB_LITERAL (x1)->size;
	} else if (CB_CONST_P (x1)) {
		size1 = 1;
		if (x1 == cb_space) {
			data1 = (unsigned char *)" ";
		} else if (x1 == cb_zero) {
			data1 = (unsigned char *)"0";
		} else if (x1 == cb_quote) {
			if (cb_flag_apostrophe) {
				data1 = (unsigned char *)"'";
			} else {
				data1 = (unsigned char *)"\"";
			}
		} else if (x1 == cb_norm_low) {
			data1 = (unsigned char *)"\0";
		} else if (x1 == cb_norm_high) {
			data1 = (unsigned char *)"\255";
		} else if (x1 == cb_null) {
			data1 = (unsigned char *)"\0";
		} else {
			return cb_error_node;
		}
	} else {
		return cb_error_node;
	}
	if (CB_LITERAL_P (x2)) {
		data2 = CB_LITERAL (x2)->data;
		size2 = CB_LITERAL (x2)->size;
	} else if (CB_CONST_P (x2)) {
		size2 = 1;
		if (x2 == cb_space) {
			data2 = (unsigned char *)" ";
		} else if (x2 == cb_zero) {
			data2 = (unsigned char *)"0";
		} else if (x2 == cb_quote) {
			if (cb_flag_apostrophe) {
				data2 = (unsigned char *)"'";
			} else {
				data2 = (unsigned char *)"\"";
			}
		} else if (x2 == cb_norm_low) {
			data2 = (unsigned char *)"\0";
		} else if (x2 == cb_norm_high) {
			data2 = (unsigned char *)"\255";
		} else if (x2 == cb_null) {
			data2 = (unsigned char *)"\0";
		} else {
			return cb_error_node;
		}
	} else {
		return cb_error_node;
	}
	p = make_tree (CB_TAG_LITERAL, CB_CATEGORY_ALPHANUMERIC,
			sizeof (struct cb_literal));
	p->data = cobc_parse_malloc (size1 + size2 + 1U);
	p->size = size1 + size2;
	memcpy (p->data, data1, size1);
	memcpy (p->data + size1, data2, size2);
	return CB_TREE (p);
}

/* Decimal */

cb_tree
cb_build_decimal (const int id)
{
	struct cb_decimal *p;

	p = make_tree (CB_TAG_DECIMAL, CB_CATEGORY_NUMERIC,
		       sizeof (struct cb_decimal));
	p->id = id;
	return CB_TREE (p);
}

/* Picture */

struct cb_picture *
cb_build_binary_picture (const char *str, const cob_u32_t size,
			 const cob_u32_t sign)
{
	struct cb_picture	*pic;

	pic = make_tree (CB_TAG_PICTURE, CB_CATEGORY_NUMERIC,
			 sizeof (struct cb_picture));
	pic->orig = cobc_check_string (str);
	pic->size = size;
	pic->digits = size;
	pic->scale = 0;
	pic->have_sign = sign;
	pic->category = CB_CATEGORY_NUMERIC;
	return pic;
}

cb_tree
cb_build_picture (const char *str)
{
	struct cb_picture	*pic;
	const unsigned char	*p;
	size_t			idx;
	size_t			buffcnt;
	cob_u32_t		at_beginning;
	cob_u32_t		at_end;
	cob_u32_t		p_char_seen;
	cob_u32_t		s_char_seen;
	cob_u32_t		dp_char_seen;
	cob_u32_t		real_digits;
	cob_u32_t		c_count;
	cob_u32_t		s_count;
	cob_u32_t		v_count;
	cob_u32_t		allocated;
	cob_u32_t		x_digits;
	cob_u32_t		digits;
	int			category;
	int			size;
	int			scale;
	int			i;
	int			n;
	unsigned char		c;
	unsigned char		lastonechar;
	unsigned char		lasttwochar;

	pic = make_tree (CB_TAG_PICTURE, CB_CATEGORY_UNKNOWN,
			 sizeof (struct cb_picture));
	if (strlen (str) > 50) {
		goto error;
	}
	if (!pic_buff) {
		pic_buff = cobc_main_malloc ((size_t)COB_SMALL_BUFF);
	}

	idx = 0;
	buffcnt = 0;
	p_char_seen = 0;
	s_char_seen = 0;
	dp_char_seen = 0;
	category = 0;
	size = 0;
	allocated = 0;
	digits = 0;
	x_digits = 0;
	real_digits = 0;
	scale = 0;
	c_count = 0;
	s_count = 0;
	v_count = 0;
	lastonechar = 0;
	lasttwochar = 0;

	for (p = (const unsigned char *)str; *p; p++) {
		n = 1;
		c = *p;
repeat:
		/* Count the number of repeated chars */
		while (p[1] == c) {
			p++, n++;
		}

		/* Add parenthesized numbers */
		if (p[1] == '(') {
			i = 0;
			p += 2;
			for (; *p == '0'; p++) {
				;
			}
			for (; *p != ')'; p++) {
				if (!isdigit (*p)) {
					goto error;
				} else {
					allocated++;
					if (allocated > 9) {
						goto error;
					}
					i = i * 10 + (*p - '0');
				}
			}
			if (i == 0) {
				goto error;
			}
			n += i - 1;
			goto repeat;
		}

		/* Check grammar and category */
		/* FIXME: need more error checks */
		switch (c) {
		case 'A':
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			category |= PIC_ALPHABETIC;
			x_digits += n;
			break;

		case 'X':
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			category |= PIC_ALPHANUMERIC;
			x_digits += n;
			break;

		case '9':
			category |= PIC_NUMERIC;
			digits += n;
			real_digits += n;
			if (v_count) {
				scale += n;
			}
			break;

		case 'N':
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			category |= PIC_NATIONAL;
			x_digits += n;
			break;

		case 'S':
			category |= PIC_NUMERIC;
			if (category & PIC_ALPHABETIC) {
				goto error;
			}
			s_count++;
			if (s_count > 1 || idx != 0) {
				goto error;
			}
			s_char_seen = 1;
			continue;

		case ',':
		case '.':
			category |= PIC_NUMERIC_EDITED;
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			if (c != current_program->decimal_point) {
				break;
			}
			dp_char_seen = 1;
			/* fall through */
		case 'V':
			category |= PIC_NUMERIC;
			if (category & PIC_ALPHABETIC) {
				goto error;
			}
			v_count++;
			if (v_count > 1) {
				goto error;
			}
			break;

		case 'P':
			category |= PIC_NUMERIC;
			if (category & PIC_ALPHABETIC) {
				goto error;
			}
			if (p_char_seen || dp_char_seen) {
				goto error;
			}
			at_beginning = 0;
			at_end = 0;
			switch (buffcnt) {
			case 0:
				/* P..... */
				at_beginning = 1;
				break;
			case 1:
				/* VP.... */
				/* SP.... */
				if (lastonechar == 'V' || lastonechar == 'S') {
					at_beginning = 1;
				}
				break;
			case 2:
				/* SVP... */
				if (lasttwochar == 'S' && lastonechar == 'V') {
					at_beginning = 1;
				}
				break;
			default:
				break;
			}
			if (p[1] == 0 || (p[1] == 'V' && p[2] == 0)) {
				/* .....P */
				/* ....PV */
				at_end = 1;
			}
			if (!at_beginning && !at_end) {
				goto error;
			}
			p_char_seen = 1;
			if (at_beginning) {
				/* Implicit V */
				v_count++;
			}
			digits += n;
			if (v_count) {
				scale += n;
			} else {
				scale -= n;
			}
			break;

		case '0':
		case 'B':
		case '/':
			category |= PIC_EDITED;
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			break;

		case '*':
		case 'Z':
			category |= PIC_NUMERIC_EDITED;
			if (category & PIC_ALPHABETIC) {
				goto error;
			}
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			digits += n;
			if (v_count) {
				scale += n;
			}
			break;

		case '+':
		case '-':
			category |= PIC_NUMERIC_EDITED;
			if (category & PIC_ALPHABETIC) {
				goto error;
			}
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			if(s_count == 0) {
				digits += n - 1;
			} else {
				digits += n;
			}
			s_count++;
			/* FIXME: need more check */
			break;

		case 'C':
			category |= PIC_NUMERIC_EDITED;
			if (!(p[1] == 'R' && p[2] == 0)) {
				goto error;
			}
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			p++;
			s_count++;
			break;

		case 'D':
			category |= PIC_NUMERIC_EDITED;
			if (!(p[1] == 'B' && p[2] == 0)) {
				goto error;
			}
			if (s_char_seen || p_char_seen) {
				goto error;
			}
			p++;
			s_count++;
			break;

		default:
			if (c == current_program->currency_symbol) {
				category |= PIC_NUMERIC_EDITED;
				if(c_count == 0) {
					digits += n - 1;
					c_count = n - 1;
				} else {
					digits += n;
					c_count += n;
				}
				break;
			}

			goto error;
		}

		/* Calculate size */
		if (c != 'V' && c != 'P') {
			size += n;
		}
		if (c == 'C' || c == 'D') {
			size += n;
		}
		if (c == 'N') {
			size += n * (COB_NATIONAL_SIZE - 1);
		}

		/* Store in the buffer */
		pic_buff[idx++] = c;
		lasttwochar = lastonechar;
		lastonechar = c;
		memcpy (&pic_buff[idx], (void *)&n, sizeof(int));
		idx += sizeof(int);
		++buffcnt;
	}
	pic_buff[idx] = 0;

	if (size == 0 && v_count) {
		goto error;
	}
	/* Set picture */
	pic->orig = cobc_check_string (str);
	pic->size = size;
	pic->digits = digits;
	pic->scale = scale;
	pic->have_sign = s_count;
	pic->real_digits = real_digits;

	/* Set picture category */
	switch (category) {
	case PIC_ALPHABETIC:
		pic->category = CB_CATEGORY_ALPHABETIC;
		break;
	case PIC_NUMERIC:
		pic->category = CB_CATEGORY_NUMERIC;
		if (digits > COB_MAX_DIGITS) {
			cb_error (_("Numeric field cannot be larger than %d digits"), COB_MAX_DIGITS);
		}
		break;
	case PIC_ALPHANUMERIC:
	case PIC_NATIONAL:
		pic->category = CB_CATEGORY_ALPHANUMERIC;
		break;
	case PIC_NUMERIC_EDITED:
		pic->str = cobc_parse_malloc (idx + 1);
		memcpy (pic->str, pic_buff, idx);
		pic->category = CB_CATEGORY_NUMERIC_EDITED;
		pic->lenstr = idx;
		break;
	case PIC_EDITED:
	case PIC_ALPHABETIC_EDITED:
	case PIC_ALPHANUMERIC_EDITED:
	case PIC_NATIONAL_EDITED:
		pic->str = cobc_parse_malloc (idx + 1);
		memcpy (pic->str, pic_buff, idx);
		pic->category = CB_CATEGORY_ALPHANUMERIC_EDITED;
		pic->lenstr = idx;
		pic->digits = x_digits;
		break;
	default:
		goto error;
	}
	goto end;

error:
	cb_error (_("Invalid picture string - '%s'"), str);

end:
	return CB_TREE (pic);
}

/* Field */

cb_tree
cb_build_field (cb_tree name)
{
	struct cb_field *p;

	p = make_tree (CB_TAG_FIELD, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_field));
	p->id = cb_field_id++;
	p->name = cb_define (name, CB_TREE (p));
	p->ename = NULL;
	p->usage = CB_USAGE_DISPLAY;
	p->storage = CB_STORAGE_WORKING;
	p->occurs_max = 1;
	return CB_TREE (p);
}

cb_tree
cb_build_implicit_field (cb_tree name, const int len)
{
	cb_tree	x;
	char	pic[32];

	x = cb_build_field (name);
	memset (pic, 0, sizeof(pic));
	snprintf (pic, sizeof(pic), "X(%d)", len);
	CB_FIELD (x)->pic = CB_PICTURE (cb_build_picture (pic));
	cb_validate_field (CB_FIELD (x));
	return x;
}

cb_tree
cb_build_constant (cb_tree name, cb_tree value)
{
	cb_tree x;

	x = cb_build_field (name);
	x->category = cb_tree_category (value);
	CB_FIELD (x)->storage = CB_STORAGE_CONSTANT;
	CB_FIELD (x)->values = CB_LIST_INIT (value);
	return x;
}

/* Add new field to hold data from given field */
cb_tree
cb_field_dup(struct cb_field *f)
{
	cb_tree		x;
	struct cb_field *s;
	char		buff[COB_MINI_BUFF],pic[30];
	int		dec,dig;

	snprintf (buff, (size_t)COB_MINI_MAX, "COPY OF %s", f->name);
	x = cb_build_field (cb_build_reference (buff));
	if(f->pic->category == CB_CATEGORY_NUMERIC
	|| f->pic->category == CB_CATEGORY_NUMERIC_EDITED) {
		dig = f->pic->digits;
		if((dec = f->pic->scale) > 0) {
			if((dig-dec) == 0) {
				sprintf(pic,"SV9(%d)",dec);
			} else if((dig-dec) < 0) {
				sprintf(pic,"SP(%d)V9(%d)",-(dig-dec),dec);
			} else {
				sprintf(pic,"S9(%d)V9(%d)",dig-dec,dec);
			}
		} else {
			sprintf(pic,"S9(%d)",dig);
		}
	} else {
		sprintf(pic,"X(%d)",f->size);
	}
	s = CB_FIELD (x);
	s->pic 	= CB_PICTURE (cb_build_picture (pic));
	if(f->pic->category == CB_CATEGORY_NUMERIC
	|| f->pic->category == CB_CATEGORY_NUMERIC_EDITED) {
		s->values	= CB_LIST_INIT (cb_zero);
	} else {
		s->values	= CB_LIST_INIT (cb_space);
	}
	s->storage	= CB_STORAGE_WORKING;
	s->usage	= CB_USAGE_DISPLAY;
	s->count++;
	cb_validate_field (s);
	CB_FIELD_ADD (current_program->working_storage, s);
	return  cb_build_field_reference (s, NULL);
}

#if	0	/* RXWRXW - Field */
struct cb_field *
CB_FIELD_PTR (cb_tree x)
{
	if (CB_REFERENCE_P (x)) {
		return CB_FIELD (cb_ref (x));
	}
	return CB_FIELD (x);
}
#endif

struct cb_field *
cb_field_add (struct cb_field *f, struct cb_field *p)
{
	struct cb_field *t;

	if (f == NULL) {
		return p;
	}
	for (t = f; t->sister; t = t->sister) {
		;
	}
	t->sister = p;
	return f;
}

struct cb_field *
cb_field_founder (const struct cb_field *f)
{
	const struct cb_field	*ff;

	ff = f;
	while (ff->parent) {
		ff = ff->parent;
	}
	return (struct cb_field *)ff;
}

struct cb_field *
cb_field_variable_size (const struct cb_field *f)
{
	struct cb_field		*p;
	struct cb_field		*fc;

	for (fc = f->children; fc; fc = fc->sister) {
		if (fc->depending) {
			return fc;
		} else if ((p = cb_field_variable_size (fc)) != NULL) {
			return p;
		}
	}
	return NULL;
}

unsigned int
cb_field_variable_address (const struct cb_field *fld)
{
	const struct cb_field		*p;
	const struct cb_field		*f;

	f = fld;
	for (p = f->parent; p; f = f->parent, p = f->parent) {
		for (p = p->children; p != f; p = p->sister) {
			if (p->depending || cb_field_variable_size (p)) {
				return 1;
			}
		}
	}
	return 0;
}

/* Check if field 'pfld' is subordinate to field 'f' */

int
cb_field_subordinate (const struct cb_field *pfld, const struct cb_field *f)
{
	struct cb_field		*p;

	for (p = pfld->parent; p; p = p->parent) {
		if (p == f) {
			return 1;
		}
	}
	return 0;
}

/* SYMBOLIC CHARACTERS */

void
cb_build_symbolic_chars (const cb_tree sym_list, const cb_tree alphabet)
{
	cb_tree			l;
	cb_tree			x;
	cb_tree			x2;
	struct cb_alphabet_name	*ap;
	int			n;
	unsigned char		buff[4];

	if (alphabet) {
		ap = CB_ALPHABET_NAME (alphabet);
	} else {
		ap = NULL;
	}
	for (l = sym_list; l; l = CB_CHAIN (l)) {
		n = cb_get_int (CB_PURPOSE (l)) - 1;
		if (ap) {
			buff[0] = (unsigned char)ap->alphachr[n];
		} else {
			buff[0] = (unsigned char)n;
		}
		buff[1] = 0;
		x2 = cb_build_alphanumeric_literal (buff, (size_t)1);
		CB_LITERAL (x2)->all = 1;
		x = cb_build_constant (CB_VALUE (l), x2);
		CB_FIELD (x)->flag_item_78 = 1;
		CB_FIELD (x)->flag_is_global = 1;
		CB_FIELD (x)->level = 1;
		(void)cb_validate_78_item (CB_FIELD (x), 0);
	}
}

/* Report */

struct cb_report *
build_report (cb_tree name)
{
	struct cb_report *p;
	cb_tree		x,y;
	char		buff[COB_MINI_BUFF];

	p = make_tree (CB_TAG_REPORT, CB_CATEGORY_UNKNOWN, sizeof (struct cb_report));
	p->name = cb_define (name, CB_TREE (p));
	p->cname = cb_to_cname (p->name);

	/* Set up LINE-COUNTER / PAGE-COUNTER */
	snprintf (buff, (size_t)COB_MINI_MAX,
		  "LINE-COUNTER of %s", p->name);
	x = cb_build_field (cb_build_reference (buff));
	CB_FIELD (x)->usage	= CB_USAGE_UNSIGNED_INT;
	CB_FIELD (x)->values	= CB_LIST_INIT (cb_zero);
	CB_FIELD (x)->storage	= CB_STORAGE_WORKING;
	CB_FIELD (x)->count++;
	cb_validate_field (CB_FIELD (x));
	p->line_counter = cb_build_field_reference (CB_FIELD (x), NULL);
	CB_FIELD_ADD (current_program->working_storage, CB_FIELD (x));

	snprintf (buff, (size_t)COB_MINI_MAX,
		  "PAGE-COUNTER of %s", p->name);
	y = cb_build_field (cb_build_reference (buff));
	CB_FIELD (y)->usage	= CB_USAGE_UNSIGNED_INT;
	CB_FIELD (y)->values	= CB_LIST_INIT (cb_zero);
	CB_FIELD (y)->storage	= CB_STORAGE_WORKING;
	CB_FIELD (y)->count++;
	cb_validate_field (CB_FIELD (y));
	p->page_counter = cb_build_field_reference (CB_FIELD (y), NULL);
	CB_FIELD_ADD (current_program->working_storage, CB_FIELD (y));

	return p;
}

/* Add SUM counter to program */
void
build_sum_counter(struct cb_report *r, struct cb_field *f)
{
	cb_tree		x;
	struct cb_field *s;
	char		buff[COB_MINI_BUFF],pic[30];
	int		dec,dig;

	/* Set up SUM COUNTER */
	if(f->flag_filler) {
		snprintf (buff, (size_t)COB_MINI_MAX, "SUM OF %s", 
					CB_FIELD(CB_VALUE(f->report_sum_list))->name);
	} else {
		snprintf (buff, (size_t)COB_MINI_MAX, "SUM %s", f->name);
	}
	x = cb_build_field (cb_build_reference (buff));
	if(f->pic->digits == 0)
		dig = 16;
	else if(f->pic->digits > 17)
		dig = 18;
	else
		dig = f->pic->digits + 2;
	if((dec = f->pic->scale) > 0) {
		if((dig-dec) == 0) {
			sprintf(pic,"SV9(%d)",dec);
		} else if((dig-dec) < 0) {
			sprintf(pic,"SP(%d)V9(%d)",-(dig-dec),dec);
		} else {
			sprintf(pic,"S9(%d)V9(%d)",dig-dec,dec);
		}
	} else {
		sprintf(pic,"S9(%d)",dig);
	}
	s = CB_FIELD (x);
	s->pic 	= CB_PICTURE (cb_build_picture (pic));
	s->values	= CB_LIST_INIT (cb_zero);
	s->storage	= CB_STORAGE_WORKING;
	s->usage	= CB_USAGE_DISPLAY;
	s->count++;
	cb_validate_field (s);
	f->report_sum_counter = cb_build_field_reference (s, NULL);
	CB_FIELD_ADD (current_program->working_storage, s);

	if(r->sums == NULL) {
		r->sums = cobc_parse_malloc((r->num_sums+2) * sizeof(struct cb_field *) * 2);
	} else {
		r->sums = cobc_parse_realloc(r->sums,
					(r->num_sums+2) * sizeof(struct cb_field *) * 2);
	}
	r->sums[r->num_sums*2 + 0] = s;
	r->sums[r->num_sums*2 + 1] = f;
	r->sums[r->num_sums*2 + 2] = NULL;
	r->sums[r->num_sums*2 + 3] = NULL;
	r->num_sums++;
}

/* File */

struct cb_file *
build_file (cb_tree name)
{
	struct cb_file *p;

	p = make_tree (CB_TAG_FILE, CB_CATEGORY_UNKNOWN, sizeof (struct cb_file));
	p->name = cb_define (name, CB_TREE (p));
	p->cname = cb_to_cname (p->name);

	p->organization = COB_ORG_SEQUENTIAL;
	p->access_mode = COB_ACCESS_SEQUENTIAL;
	p->handler = CB_LABEL (cb_standard_error_handler);
	p->handler_prog = current_program;
	return p;
}

void
validate_file (struct cb_file *f, cb_tree name)
{
	/* Check RECORD/RELATIVE KEY clause */
	switch (f->organization) {
	case COB_ORG_INDEXED:
		if (f->key == NULL) {
			file_error (name, "RECORD KEY");
		}
		break;
	case COB_ORG_RELATIVE:
		if (f->key == NULL && f->access_mode != COB_ACCESS_SEQUENTIAL) {
			file_error (name, "RELATIVE KEY");
		}
		if (f->alt_key_list) {
			cb_error_x (name, _("ALTERNATE clause invalid for this file type"));
			f->alt_key_list = NULL;
		}
		break;
	default:
		if (f->key) {
			cb_error_x (name, _("RECORD clause invalid for this file type"));
			f->key = NULL;
		}
		if (f->alt_key_list) {
			cb_error_x (name, _("ALTERNATE clause invalid for this file type"));
			f->alt_key_list = NULL;
		}
		if (f->access_mode == COB_ACCESS_DYNAMIC ||
		    f->access_mode == COB_ACCESS_RANDOM) {
			cb_error_x (name, _("ORGANIZATION clause invalid"));
		}
		break;
	}
}

void
finalize_file (struct cb_file *f, struct cb_field *records)
{
	struct cb_field		*p;
	struct cb_field		*v;
	struct cb_alt_key	*cbak;
	cb_tree			l;
	cb_tree			x;

	/* stdin/stderr and LINE ADVANCING are L/S */
	if (f->special || f->flag_line_adv) {
		f->organization = COB_ORG_LINE_SEQUENTIAL;
	}
	if (f->flag_fileid && !f->assign) {
		f->assign = cb_build_alphanumeric_literal (f->name,
							   strlen (f->name));
	}

	if (f->key && f->organization == COB_ORG_INDEXED &&
	    (l = cb_ref (f->key)) != cb_error_node) {
		v = cb_field_founder (CB_FIELD_PTR (l));
		for (p = records; p; p = p->sister) {
			if (p == v) {
				break;
			}
		}
		if (!p) {
			cb_error (_("Invalid KEY item '%s'"),
				  CB_FIELD_PTR (l)->name);
		}
	}
	if (f->alt_key_list) {
		for (cbak = f->alt_key_list; cbak; cbak = cbak->next) {
			l = cb_ref (cbak->key);
			if (l == cb_error_node) {
				continue;
			}
			v = cb_field_founder (CB_FIELD_PTR (l));
			for (p = records; p; p = p->sister) {
				if (p == v) {
					break;
				}
			}
			if (!p) {
				cb_error (_("Invalid KEY item '%s'"),
					    CB_FIELD_PTR (l)->name);
			}
		}
	}

	/* Check the record size if it is limited */
	for (p = records; p; p = p->sister) {
		if (f->record_max > 0
		&&  p->size > f->record_max) {
			f->record_max = p->size;
		}
	}
	for (p = records; p; p = p->sister) {
		if (f->record_min > 0) {
			if (p->size < f->record_min) {
				cb_error (_("Record size too small '%s'"),
					  p->name);
			}
		}
		if (f->record_max > 0) {
			if (p->size > f->record_max) {
				cb_error (_("Record size too large '%s' (%d)"),
					     p->name, p->size);
			}
		}
	}

	/* Compute the record size */
	if (f->record_min == 0) {
		if (records) {
			f->record_min = records->size;
		} else {
			f->record_min = 0;
		}
	}
	for (p = records; p; p = p->sister) {
		v = cb_field_variable_size (p);
		if (v && v->offset + v->size * v->occurs_min < f->record_min) {
			f->record_min = v->offset + v->size * v->occurs_min;
		}
		if (p->size < f->record_min) {
			f->record_min = p->size;
		}
		if (p->size > f->record_max) {
			f->record_max = p->size;
		}
	}

	if (f->record_max > MAX_FD_RECORD) {
		cb_error (_("Record size exceeds maximum allowed (%d) - File '%s'"),
			  MAX_FD_RECORD, f->name);
	}

	if (f->same_clause) {
		for (l = current_program->file_list; l; l = CB_CHAIN (l)) {
			if (CB_FILE (CB_VALUE (l))->same_clause == f->same_clause) {
				if (CB_FILE (CB_VALUE (l))->flag_finalized) {
					if (f->record_max > CB_FILE (CB_VALUE (l))->record->memory_size) {
						CB_FILE (CB_VALUE (l))->record->memory_size =
						    f->record_max;
					}
					f->record = CB_FILE (CB_VALUE (l))->record;
					for (p = records; p; p = p->sister) {
						p->file = f;
						p->redefines = f->record;
					}
					for (p = f->record->sister; p; p = p->sister) {
						if (!p->sister) {
							p->sister = records;
							break;
						}
					}
					f->flag_finalized = 1;
					return;
				}
			}
		}
	}
	/* Create record */
	if (f->record_max == 0) {
		f->record_max = 32;
		f->record_min = 32;
	}
	if (f->organization == COB_ORG_LINE_SEQUENTIAL) {
		f->record_min = 0;
	}
	if (!scratch_buff) {
		scratch_buff = cobc_main_malloc ((size_t)COB_MINI_BUFF);
	}
	snprintf (scratch_buff, (size_t)COB_MINI_MAX, "%s Record", f->name);
	f->record = CB_FIELD (cb_build_implicit_field (cb_build_reference (scratch_buff),
				f->record_max));
	f->record->sister = records;
	f->record->count++;
	if (f->flag_external) {
		current_program->flag_has_external = 1;
		f->record->flag_external = 1;
	}

	for (p = records; p; p = p->sister) {
		p->file = f;
		p->redefines = f->record;
#if	1	/* RXWRXW - Global/External */
		if (p->flag_is_global) {
			f->record->flag_is_global = 1;
		}
#endif
	}
	f->flag_finalized = 1;
	if (f->linage) {
		snprintf (scratch_buff, (size_t)COB_MINI_MAX,
			  "LINAGE-COUNTER %s", f->name);
		x = cb_build_field (cb_build_reference (scratch_buff));
		CB_FIELD (x)->usage = CB_USAGE_UNSIGNED_INT;
		CB_FIELD (x)->values = CB_LIST_INIT (cb_zero);
		CB_FIELD (x)->count++;
		cb_validate_field (CB_FIELD (x));
		f->linage_ctr = cb_build_field_reference (CB_FIELD (x), NULL);
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD (x));
	}
}

static struct cb_report *report_checked = NULL;
void
finalize_report (struct cb_report *r, struct cb_field *records)
{
	struct cb_field		*p;
	if(report_checked != r) {
		report_checked = r;
		if(r->lines > 9999)
			r->lines = 9999;
		if(r->heading < 0)
			r->heading = 0;
		if(r->first_detail < 1)
			r->first_detail = 1;
		if(r->t_lines == NULL
		&& r->t_columns == NULL
		&& r->t_heading == NULL
		&& r->t_first_detail == NULL
		&& r->t_last_detail == NULL
		&& r->t_last_control == NULL
		&& r->t_footing == NULL) {	/* No PAGE LIMITS set at run-time so check it now */
			if(r->first_detail <= 0) {
				cb_warning_x (CB_TREE(r), _("NO DETAIL line defined in report %s"),r->name);
			} else if(!(r->first_detail >= r->heading)) {
				cb_error_x (CB_TREE(r), _("PAGE LIMIT FIRST DETAIL should be >= HEADING"));
			} 
			if(r->footing > 0 && !(r->footing >= r->heading)) {
				cb_error_x (CB_TREE(r), _("PAGE LIMIT FOOTING should be >= HEADING"));
			} else if(r->last_detail > 0 && !(r->last_detail >= r->first_detail)) {
				cb_error_x (CB_TREE(r), _("PAGE LIMIT LAST DETAIL should be >= FIRST DETAIL"));
			} else if(r->footing > 0 && !(r->footing >= r->last_detail)) {
				cb_error_x (CB_TREE(r), _("PAGE LIMIT FOOTING should be >= LAST DETAIL"));
			} else if(!(r->lines >= r->footing)) {
				cb_error_x (CB_TREE(r), _("PAGE LIMIT LINES should be >= FOOTING"));
			}
		}
	}

	for (p = records; p; p = p->sister) {
		if(p->report != NULL)
		    continue;
		p->report = r;
		if(p->storage == CB_STORAGE_REPORT
		&& ((p->report_flag &  COB_REPORT_LINE) || p->level == 1)) {
			if(r->rcsz < p->size)
				r->rcsz = p->size;
			if(r->line_ids == NULL) {
				r->line_ids = cobc_parse_malloc((r->num_lines+2) * sizeof(struct cb_field *));
			} else {
				r->line_ids = cobc_parse_realloc(r->line_ids,
							(r->num_lines+2) * sizeof(struct cb_field *));
			}
			r->line_ids[r->num_lines++] = p;
			r->line_ids[r->num_lines] = NULL;	/* Clear next entry */
		} 
		if(p->report_source
		&& CB_REF_OR_FIELD_P (p->report_source)) {
			struct cb_field *f = CB_FIELD (cb_ref(p->report_source));
			if(f && f->count == 0)
				f->count++;
			if(CB_TREE_TAG (p->report_source) == CB_TAG_REFERENCE) {
				struct cb_reference     *ref;
				ref = CB_REFERENCE (p->report_source); 
				if(ref->offset || ref->subs || f->flag_local) {
					p->report_from = p->report_source;
					p->report_source = cb_field_dup(f);
				}
			}
		}
		if(p->report_sum_counter
		&& CB_REF_OR_FIELD_P (p->report_sum_counter)) {
			struct cb_field *f = CB_FIELD (cb_ref(p->report_sum_counter));
			if(f && f->count == 0)
				f->count++;
		}
		if (p->children) {
		    finalize_report(r,p->children);
		}
	}

	for (p = records; p; p = p->sister) {
		if(p->report != r)
			continue;
		if(p->storage == CB_STORAGE_REPORT
		&& ((p->report_flag &  COB_REPORT_LINE) || p->level == 1)) {
			if(p->size < r->rcsz)
				p->size = r->rcsz;
			if(p->memory_size < r->rcsz)
				p->memory_size = r->rcsz;
		}
		if(p->level == 1
		&& p->report != NULL
		&& p->report->file != NULL) {
			if(p->report->file->record_min < r->rcsz)
				p->report->file->record_min = r->rcsz;
			if(p->report->file->record_max < p->size)
				p->report->file->record_max = r->rcsz;
			if(p->report->file->record != NULL) {
				if(p->report->file->record->size < r->rcsz)
					p->report->file->record->size = r->rcsz;
			}
		}
	}
	if(r->file->record_max < r->rcsz)
		r->file->record_max = r->rcsz;
	if(r->rcsz < r->file->record_max)
		r->rcsz = r->file->record_max;
}


/* Reference */

cb_tree
cb_build_reference (const char *name)
{
	struct cb_reference *p;

	p = make_tree (CB_TAG_REFERENCE, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_reference));
	/* Look up / insert word into hash list */
	lookup_word (p, name);
	return CB_TREE (p);
}

cb_tree
cb_build_filler (void)
{
	cb_tree		x;
	char		name[20];

	sprintf (name, "FILLER %d", filler_id++);
	x = cb_build_reference (name);
	x->source_line = cb_source_line;
	CB_REFERENCE (x)->flag_filler_ref = 1;
	return x;
}

cb_tree
cb_build_field_reference (struct cb_field *f, cb_tree ref)
{
	cb_tree		x;
	struct cb_word	*word;

	x = cb_build_reference (f->name);
	word = CB_REFERENCE (x)->word;
	if (ref) {
		memcpy (x, ref, sizeof (struct cb_reference));
	}
	x->category = CB_CATEGORY_UNKNOWN;
	CB_REFERENCE (x)->word = word;
	CB_REFERENCE (x)->value = CB_TREE (f);
	return x;
}

static void
cb_define_system_name (const char *name)
{
	cb_tree x;
	cb_tree y;

	x = cb_build_reference (name);
	if (CB_WORD_COUNT (x) == 0) {
		y = lookup_system_name (name);
		/* Paranoid */
		if (y) {
			cb_define (x, y);
		}
	}
}

void
cb_set_system_names (void)
{
	cb_define_system_name ("CONSOLE");
	cb_define_system_name ("SYSIN");
	cb_define_system_name ("SYSIPT");
	cb_define_system_name ("STDIN");
	cb_define_system_name ("SYSOUT");
	cb_define_system_name ("STDOUT");
	cb_define_system_name ("SYSERR");
	cb_define_system_name ("STDERR");
	cb_define_system_name ("SYSLST");
	cb_define_system_name ("SYSLIST");
	cb_define_system_name ("FORMFEED");
}

cb_tree
cb_ref (cb_tree x)
{
	struct cb_reference	*r;
	struct cb_field		*p;
	struct cb_label		*s;
	cb_tree			candidate;
	cb_tree			items;
	cb_tree			cb1;
	cb_tree			cb2;
	cb_tree			v;
	cb_tree			c;
	struct cb_program	*prog;
	struct cb_word		*w;
	size_t			val;
	size_t			ambiguous;

	if (CB_INVALID_TREE (x)) {
		return cb_error_node;
	}
	r = CB_REFERENCE (x);
	/* If this reference has already been resolved (and the value
	   has been cached), then just return the value */
	if (r->value) {
		return r->value;
	}

	/* Resolve the value */

	candidate = NULL;
	ambiguous = 0;
	items = r->word->items;
	for (; items; items = CB_CHAIN (items)) {
		/* Find a candidate value by resolving qualification */
		v = CB_VALUE (items);
		c = r->chain;
		switch (CB_TREE_TAG (v)) {
		case CB_TAG_FIELD:
			/* In case the value is a field, it might be qualified
			   by its parent names and a file name */
			if (CB_FIELD (v)->flag_indexed_by) {
				p = CB_FIELD (v)->index_qual;
			} else {
				p = CB_FIELD (v)->parent;
			}
			/* Resolve by parents */
			for (; p; p = p->parent) {
				if (c && strcasecmp (CB_NAME (c), p->name) == 0) {
					c = CB_REFERENCE (c)->chain;
				}
			}

			/* Resolve by file */
			if (c && CB_REFERENCE (c)->chain == NULL) {
				if (CB_WORD_COUNT (c) == 1 &&
				    CB_FILE_P (cb_ref (c)) &&
				    (CB_FILE (cb_ref (c)) == cb_field_founder (CB_FIELD (v))->file)) {
					c = CB_REFERENCE (c)->chain;
				}
			}

			break;
		case CB_TAG_LABEL:
			/* In case the value is a label, it might be qualified
			   by its section name */
			s = CB_LABEL (v)->section;

			/* Unqualified paragraph name referenced within the section
			   is resolved without ambiguity check if not duplicated */
			if (c == NULL && r->offset && s == CB_LABEL (r->offset)) {
				for (cb1 = CB_CHAIN (items); cb1; cb1 = CB_CHAIN (cb1)) {
					cb2 = CB_VALUE (cb1);
					if (s == CB_LABEL (cb2)->section) {
						ambiguous_error (x);
						goto error;
					}
				}
				candidate = v;
				goto end;
			}

			/* Resolve by section name */
			if (c && s && strcasecmp (CB_NAME (c), (char *)s->name) == 0) {
				c = CB_REFERENCE (c)->chain;
			}

			break;
		default:
			/* Other values cannot be qualified */
			break;
		}

		/* A well qualified value is a good candidate */
		if (c == NULL) {
			if (candidate == NULL) {
				/* Keep the first candidate */
				candidate = v;
			} else {
				/* Multiple candidates and possibly ambiguous */
				ambiguous = 1;
				/* Continue search because the reference might not
				   be ambiguous and exit loop by "goto end" later */
			}
		}
	}

	/* There is no candidate */
	if (candidate == NULL) {
		if (likely(current_program->nested_level <= 0)) {
			goto undef_error;
		}
		/* Nested program - check parents for GLOBAL candidate */
		ambiguous = 0;
/* RXWRXW
		val = hash ((const unsigned char *)r->word->name);
*/
		val = r->hashval;
		prog = current_program->next_program;
		for (; prog; prog = prog->next_program) {
			if (prog->nested_level >= current_program->nested_level) {
				continue;
			}
			for (w = prog->word_table[val]; w; w = w->next) {
				if (strcasecmp (r->word->name, w->name) == 0) {
					candidate = global_check (r, w->items, &ambiguous);
					if (candidate) {
						if (ambiguous) {
							ambiguous_error (x);
							goto error;
						}
						if (CB_FILE_P(candidate)) {
							current_program->flag_gen_error = 1;
						}
						goto end;
					}
				}
			}
			if (prog->nested_level == 0) {
				break;
			}
		}
		goto undef_error;
	}

	/* Reference is ambiguous */
	if (ambiguous) {
		ambiguous_error (x);
		goto error;
	}

end:
	if (CB_FIELD_P (candidate)) {
		CB_FIELD (candidate)->count++;
		if (CB_FIELD (candidate)->flag_invalid) {
			goto error;
		}
	} else if (CB_LABEL_P (candidate) && r->flag_alter_code) {
		CB_LABEL (candidate)->flag_alter = 1;
	}

	r->value = candidate;
	return r->value;

undef_error:
	undefined_error (x);
	/* Fall through */

error:
	r->value = cb_error_node;
	return cb_error_node;
}

/* Expression */

cb_tree
cb_build_binary_op (cb_tree x, const int op, cb_tree y)
{
	struct cb_binary_op	*p;
	enum cb_category	category = CB_CATEGORY_UNKNOWN;

	switch (op) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		/* Arithmetic operators */
		if (CB_TREE_CLASS (x) == CB_CLASS_POINTER ||
		    CB_TREE_CLASS (y) == CB_CLASS_POINTER) {
			category = CB_CATEGORY_DATA_POINTER;
			break;
		}
		x = cb_check_numeric_value (x);
		y = cb_check_numeric_value (y);
		if (x == cb_error_node || y == cb_error_node) {
			return cb_error_node;
		}
		category = CB_CATEGORY_NUMERIC;
		break;

	case '=':
	case '~':
	case '<':
	case '>':
	case '[':
	case ']':
		/* Relational operators */
		if ((CB_REF_OR_FIELD_P (x)) &&
		    CB_FIELD (cb_ref (x))->level == 88) {
			cb_error_x (x, _("Invalid expression"));
			return cb_error_node;
		}
		if ((CB_REF_OR_FIELD_P (y)) &&
		    CB_FIELD (cb_ref (y))->level == 88) {
			cb_error_x (y, _("Invalid expression"));
			return cb_error_node;
		}
		category = CB_CATEGORY_BOOLEAN;
		break;

	case '!':
	case '&':
	case '|':
		/* Logical operators */
		if (CB_TREE_CLASS (x) != CB_CLASS_BOOLEAN ||
		    (y && CB_TREE_CLASS (y) != CB_CLASS_BOOLEAN)) {
			cb_error_x (x, _("Invalid expression"));
			return cb_error_node;
		}
		category = CB_CATEGORY_BOOLEAN;
		break;

	case '@':
		/* Parentheses */
		category = CB_TREE_CATEGORY (x);
		break;

	default:
		cobc_abort_pr (_("Unexpected operator -> %d"), op);
		COBC_ABORT ();
	}

	p = make_tree (CB_TAG_BINARY_OP, category, sizeof (struct cb_binary_op));
	p->op = op;
	p->x = x;
	p->y = y;
	return CB_TREE (p);
}

cb_tree
cb_build_binary_list (cb_tree l, const int op)
{
	cb_tree e;

	e = CB_VALUE (l);
	for (l = CB_CHAIN (l); l; l = CB_CHAIN (l)) {
		e = cb_build_binary_op (e, op, CB_VALUE (l));
	}
	return e;
}

/* Function call */

cb_tree
cb_build_funcall (const char *name, const int argc,
		  const cb_tree a1, const cb_tree a2, const cb_tree a3,
		  const cb_tree a4, const cb_tree a5, const cb_tree a6,
		  const cb_tree a7, const cb_tree a8, const cb_tree a9,
		  const cb_tree a10)
{
	struct cb_funcall *p;

	p = make_tree (CB_TAG_FUNCALL, CB_CATEGORY_BOOLEAN,
		       sizeof (struct cb_funcall));
	p->name = name;
	p->argc = argc;
	p->varcnt = 0;
	p->screenptr = gen_screen_ptr;
	p->argv[0] = a1;
	p->argv[1] = a2;
	p->argv[2] = a3;
	p->argv[3] = a4;
	p->argv[4] = a5;
	p->argv[5] = a6;
	p->argv[6] = a7;
	p->argv[7] = a8;
	p->argv[8] = a9;
	p->argv[9] = a10;
	return CB_TREE (p);
}

/* Type cast */

cb_tree
cb_build_cast (const enum cb_cast_type type, const cb_tree val)
{
	struct cb_cast		*p;
	enum cb_category	category;

	if (type == CB_CAST_INTEGER) {
		category = CB_CATEGORY_NUMERIC;
	} else {
		category = CB_CATEGORY_UNKNOWN;
	}
	p = make_tree (CB_TAG_CAST, category, sizeof (struct cb_cast));
	p->cast_type = type;
	p->val = val;
	return CB_TREE (p);
}

cb_tree
cb_build_cast_int (const cb_tree val)
{
	struct cb_cast		*p;

	p = make_tree (CB_TAG_CAST, CB_CATEGORY_NUMERIC, sizeof (struct cb_cast));
	p->cast_type = CB_CAST_INTEGER;
	p->val = val;
	return CB_TREE (p);
}

cb_tree
cb_build_cast_llint (const cb_tree val)
{
	struct cb_cast		*p;

	p = make_tree (CB_TAG_CAST, CB_CATEGORY_NUMERIC, sizeof (struct cb_cast));
	p->cast_type = CB_CAST_LONG_INT;
	p->val = val;
	return CB_TREE (p);
}

/* Label */

cb_tree
cb_build_label (cb_tree name, struct cb_label *section)
{
	struct cb_label		*p;
	struct cb_para_label	*l;

	p = make_tree (CB_TAG_LABEL, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_label));
	p->id = cb_id++;
	p->name = cb_define (name, CB_TREE (p));
	p->orig_name = p->name;
	p->section = section;
	if (section) {
		l = cobc_parse_malloc (sizeof(struct cb_para_label));
		l->next = section->para_label;
		l->para= p;
		section->para_label = l;
		p->section_id = p->section->id;
	} else {
		p->section_id = p->id;
	}
	return CB_TREE (p);
}

/* Assign */

cb_tree
cb_build_assign (const cb_tree var, const cb_tree val)
{
	struct cb_assign *p;

	p = make_tree (CB_TAG_ASSIGN, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_assign));
	p->var = var;
	p->val = val;
	return CB_TREE (p);
}

/* INITIALIZE */

cb_tree
cb_build_initialize (const cb_tree var, const cb_tree val, const cb_tree rep,
		     const unsigned int def,
		     const unsigned int is_statement,
		     const unsigned int no_filler_init)
{
	struct cb_initialize *p;

	p = make_tree (CB_TAG_INITIALIZE, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_initialize));
	p->var = var;
	p->val = val;
	p->rep = rep;
	p->flag_default = (cob_u8_t)def;
	p->flag_init_statement = (cob_u8_t)is_statement;
	p->flag_no_filler_init = (cob_u8_t)no_filler_init;
	return CB_TREE (p);
}

/* SEARCH */

cb_tree
cb_build_search (const int flag_all, const cb_tree table, const cb_tree var,
		 const cb_tree end_stmt, const cb_tree whens)
{
	struct cb_search *p;

	p = make_tree (CB_TAG_SEARCH, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_search));
	p->flag_all = flag_all;
	p->table = table;
	p->var = var;
	p->end_stmt = end_stmt;
	p->whens = whens;
	return CB_TREE (p);
}

/* CALL */

cb_tree
cb_build_call (const cb_tree name, const cb_tree args, const cb_tree stmt1,
	       const cb_tree stmt2, const cb_tree returning,
	       const cob_u32_t is_system_call, const int convention)
{
	struct cb_call *p;

	p = make_tree (CB_TAG_CALL, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_call));
	p->name = name;
	p->args = args;
	p->stmt1 = stmt1;
	p->stmt2 = stmt2;
	p->call_returning = returning;
	p->is_system = is_system_call;
	p->convention = convention;
	return CB_TREE (p);
}

/* CANCEL */

cb_tree
cb_build_cancel (const cb_tree target)
{
	struct cb_cancel *p;

	p = make_tree (CB_TAG_CANCEL, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_cancel));
	p->target = target;
	return CB_TREE (p);
}

/* ALTER */

cb_tree
cb_build_alter (const cb_tree source, const cb_tree target)
{
	struct cb_alter *p;

	p = make_tree (CB_TAG_ALTER, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_alter));
	p->source = source;
	p->target = target;
	current_program->alter_list =
		cb_list_append (current_program->alter_list,
				CB_BUILD_PAIR (source, target));
	return CB_TREE (p);
}

/* GO TO */

cb_tree
cb_build_goto (const cb_tree target, const cb_tree depending)
{
	struct cb_goto *p;

	p = make_tree (CB_TAG_GOTO, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_goto));
	p->target = target;
	p->depending = depending;
	return CB_TREE (p);
}

/* IF */

cb_tree
cb_build_if (const cb_tree test, const cb_tree stmt1, const cb_tree stmt2,
	     const unsigned int is_if)
{
	struct cb_if *p;

	p = make_tree (CB_TAG_IF, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_if));
	p->test = test;
	p->stmt1 = stmt1;
	p->stmt2 = stmt2;
	p->is_if = is_if;
	return CB_TREE (p);
}

/* PERFORM */

cb_tree
cb_build_perform (const enum cb_perform_type type)
{
	struct cb_perform *p;

	p = make_tree (CB_TAG_PERFORM, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_perform));
	p->perform_type = type;
	return CB_TREE (p);
}

cb_tree
cb_build_perform_varying (cb_tree name, cb_tree from, cb_tree by, cb_tree until)
{
	struct cb_perform_varying	*p;
	cb_tree				x;
	cb_tree				l;

	p = make_tree (CB_TAG_PERFORM_VARYING, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_perform_varying));
	p->name = name;
	p->from = from;
	p->until = until;
	if (name) {
		if (name == cb_error_node) {
			p->step = NULL;
			return CB_TREE (p);
		}
		l = cb_ref (name);
		x = cb_build_add (name, by, cb_high);
		if (current_program->flag_debugging &&
		    !current_statement->flag_in_debug &&
		    CB_FIELD_P (l) && CB_FIELD (l)->flag_field_debug) {
			p->step = CB_LIST_INIT (x);
			x = cb_build_debug (cb_debug_name, CB_FIELD_PTR (name)->name,
					    NULL);
			p->step = cb_list_add (p->step, x);
			x = cb_build_debug (cb_debug_contents, NULL, name);
			p->step = cb_list_add (p->step, x);
			x = cb_build_debug_call (CB_FIELD_PTR (name)->debug_section);
			p->step = cb_list_add (p->step, x);
		} else {
			p->step = x;
		}
	} else {
		p->step = NULL;
	}
	return CB_TREE (p);
}

/* Statement */

struct cb_statement *
cb_build_statement (const char *name)
{
	struct cb_statement *p;

	p = make_tree (CB_TAG_STATEMENT, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_statement));
	p->name = name;
	return p;
}

/* CONTINUE */

cb_tree
cb_build_continue (void)
{
	struct cb_continue *p;

	p = make_tree (CB_TAG_CONTINUE, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_continue));
	return CB_TREE (p);
}

/* SET ATTRIBUTE */

cb_tree
cb_build_set_attribute (const struct cb_field *fld,
			const int val_on, const int val_off)
{
	struct cb_set_attr *p;

	p = make_tree (CB_TAG_SET_ATTR, CB_CATEGORY_UNKNOWN,
		       sizeof (struct cb_set_attr));
	p->fld = (struct cb_field *)fld;
	p->val_on = val_on;
	p->val_off = val_off;
	return CB_TREE (p);
}

/* FUNCTION */

cb_tree
cb_build_any_intrinsic (cb_tree args)
{
	struct cb_intrinsic_table	*cbp;

	cbp = lookup_intrinsic ("LENGTH", 0, 0);
	return make_intrinsic (NULL, cbp, args, NULL, NULL, 0);
}

cb_tree
cb_build_intrinsic (cb_tree name, cb_tree args, cb_tree refmod,
		    const int isuser)
{
	struct cb_intrinsic_table	*cbp;
	cb_tree				x;
	int				numargs;
	enum cb_category		catg;

	numargs = cb_list_length (args);

	if (unlikely(isuser)) {
		if (refmod && CB_LITERAL_P(CB_PAIR_X(refmod)) &&
		    cb_get_int (CB_PAIR_X(refmod)) < 1) {
			cb_error_x (name, _("FUNCTION '%s' has invalid reference modification"), CB_NAME(name));
			return cb_error_node;
		}
		if (refmod && CB_PAIR_Y(refmod) &&
		    CB_LITERAL_P(CB_PAIR_Y(refmod)) &&
		    cb_get_int (CB_PAIR_Y(refmod)) < 1) {
			cb_error_x (name, _("FUNCTION '%s' has invalid reference modification"), CB_NAME(name));
			return cb_error_node;
		}
		if (numargs > current_program->max_call_param) {
			current_program->max_call_param = numargs;
		}
		return make_intrinsic (name, &userbp, args, cb_int1, refmod, 1);
	}

	cbp = lookup_intrinsic (CB_NAME (name), 0, 1);
	if (!cbp) {
		cb_error_x (name, _("FUNCTION '%s' unknown"), CB_NAME (name));
		return cb_error_node;
	}
	if (!cbp->implemented) {
		cb_error_x (name, _("FUNCTION '%s' not implemented"),
			    cbp->name);
		return cb_error_node;
	}
	if ((cbp->args >= 0 && numargs != cbp->args) ||
	    (cbp->args < 0 && numargs < cbp->min_args)) {
		cb_error_x (name,
			    _("FUNCTION '%s' has wrong number of arguments"),
			    cbp->name);
		return cb_error_node;
	}
	if (refmod) {
		if (!cbp->refmod) {
			cb_error_x (name, _("FUNCTION '%s' can not have reference modification"), cbp->name);
			return cb_error_node;
		}
		if (CB_LITERAL_P(CB_PAIR_X(refmod)) &&
		    cb_get_int (CB_PAIR_X(refmod)) < 1) {
			cb_error_x (name, _("FUNCTION '%s' has invalid reference modification"), cbp->name);
			return cb_error_node;
		}
		if (CB_PAIR_Y(refmod) && CB_LITERAL_P(CB_PAIR_Y(refmod)) &&
		    cb_get_int (CB_PAIR_Y(refmod)) < 1) {
			cb_error_x (name, _("FUNCTION '%s' has invalid reference modification"), cbp->name);
			return cb_error_node;
		}
	}

	switch (cbp->intr_enum) {
	case CB_INTR_LENGTH:
	case CB_INTR_BYTE_LENGTH:
		x = CB_VALUE (args);
		if (CB_LITERAL_P (x)) {
			return cb_build_length (x);
		} else {
			return make_intrinsic (name, cbp, args, NULL, NULL, 0);
		}

	case CB_INTR_WHEN_COMPILED:
		if (refmod) {
			return make_intrinsic (name, cbp,
				CB_LIST_INIT (cb_intr_whencomp), NULL, refmod, 0);
		} else {
			return cb_intr_whencomp;
		}

	case CB_INTR_ABS:
	case CB_INTR_ACOS:
	case CB_INTR_ASIN:
	case CB_INTR_ATAN:
	case CB_INTR_COS:
	case CB_INTR_DATE_OF_INTEGER:
	case CB_INTR_DAY_OF_INTEGER:
	case CB_INTR_EXP:
	case CB_INTR_EXP10:
	case CB_INTR_FACTORIAL:
	case CB_INTR_FRACTION_PART:
	case CB_INTR_INTEGER:
	case CB_INTR_INTEGER_OF_DATE:
	case CB_INTR_INTEGER_OF_DAY:
	case CB_INTR_INTEGER_PART:
	case CB_INTR_LOG:
	case CB_INTR_LOG10:
	case CB_INTR_SIGN:
	case CB_INTR_SIN:
	case CB_INTR_SQRT:
	case CB_INTR_TAN:
	case CB_INTR_TEST_DATE_YYYYMMDD:
	case CB_INTR_TEST_DAY_YYYYDDD:
		x = CB_VALUE (args);
		if (cb_tree_category (x) != CB_CATEGORY_NUMERIC) {
			cb_error_x (name, _("FUNCTION '%s' has invalid parameter"), cbp->name);
			return cb_error_node;
		}
		return make_intrinsic (name, cbp, args, NULL, refmod, 0);

	case CB_INTR_ANNUITY:
	case CB_INTR_BOOLEAN_OF_INTEGER:
	case CB_INTR_CHAR:
	case CB_INTR_CHAR_NATIONAL:
	case CB_INTR_COMBINED_DATETIME:
	case CB_INTR_CURRENCY_SYMBOL:
	case CB_INTR_CURRENT_DATE:
	case CB_INTR_E:
	case CB_INTR_EXCEPTION_FILE:
	case CB_INTR_EXCEPTION_FILE_N:
	case CB_INTR_EXCEPTION_LOCATION:
	case CB_INTR_EXCEPTION_LOCATION_N:
	case CB_INTR_EXCEPTION_STATUS:
	case CB_INTR_EXCEPTION_STATEMENT:
	case CB_INTR_FORMATTED_CURRENT_DATE:
	case CB_INTR_FORMATTED_DATE:
	case CB_INTR_INTEGER_OF_BOOLEAN:
	case CB_INTR_INTEGER_OF_FORMATTED_DATE:
	case CB_INTR_LOCALE_DATE:
	case CB_INTR_LOCALE_TIME:
	case CB_INTR_LOCALE_TIME_FROM_SECS:
	case CB_INTR_LOWER_CASE:
	case CB_INTR_MOD:
	case CB_INTR_MODULE_CALLER_ID:
	case CB_INTR_MODULE_DATE:
	case CB_INTR_MODULE_FORMATTED_DATE:
	case CB_INTR_MODULE_ID:
	case CB_INTR_MODULE_PATH:
	case CB_INTR_MODULE_SOURCE:
	case CB_INTR_MODULE_TIME:
	case CB_INTR_MON_DECIMAL_POINT:
	case CB_INTR_MON_THOUSANDS_SEP:
	case CB_INTR_NUM_DECIMAL_POINT:
	case CB_INTR_NUM_THOUSANDS_SEP:
	case CB_INTR_NUMVAL:
	case CB_INTR_NUMVAL_C:
	case CB_INTR_NUMVAL_F:
	case CB_INTR_ORD:
	case CB_INTR_PI:
	case CB_INTR_REM:
	case CB_INTR_REVERSE:
	case CB_INTR_SECONDS_FROM_FORMATTED_TIME:
	case CB_INTR_SECONDS_PAST_MIDNIGHT:
	case CB_INTR_STORED_CHAR_LENGTH:
	case CB_INTR_TEST_FORMATTED_DATETIME:
	case CB_INTR_TEST_NUMVAL:
	case CB_INTR_TEST_NUMVAL_C:
	case CB_INTR_TEST_NUMVAL_F:
	case CB_INTR_TRIM:
	case CB_INTR_UPPER_CASE:
		return make_intrinsic (name, cbp, args, NULL, refmod, 0);

	case CB_INTR_HIGHEST_ALGEBRAIC:
	case CB_INTR_LOWEST_ALGEBRAIC:
		x = CB_VALUE (args);
		if (!CB_REF_OR_FIELD_P (x)) {
			cb_error_x (name, _("FUNCTION '%s' has invalid parameter"), cbp->name);
			return cb_error_node;
		}
		catg = cb_tree_category (x);
		if (catg != CB_CATEGORY_NUMERIC &&
		    catg != CB_CATEGORY_NUMERIC_EDITED) {
			cb_error_x (name, _("FUNCTION '%s' has invalid parameter"), cbp->name);
			return cb_error_node;
		}
		return make_intrinsic (name, cbp, args, NULL, refmod, 0);


	case CB_INTR_CONCATENATE:
	case CB_INTR_DISPLAY_OF:
	case CB_INTR_FORMATTED_DATETIME:
	case CB_INTR_FORMATTED_TIME:
	case CB_INTR_NATIONAL_OF:
		return make_intrinsic (name, cbp, args, cb_int1, refmod, 0);

	case CB_INTR_DATE_TO_YYYYMMDD:
	case CB_INTR_DAY_TO_YYYYDDD:
	case CB_INTR_LOCALE_COMPARE:
	case CB_INTR_MAX:
	case CB_INTR_MEAN:
	case CB_INTR_MEDIAN:
	case CB_INTR_MIDRANGE:
	case CB_INTR_MIN:
	case CB_INTR_ORD_MAX:
	case CB_INTR_ORD_MIN:
	case CB_INTR_PRESENT_VALUE:
	case CB_INTR_RANDOM:
	case CB_INTR_RANGE:
	case CB_INTR_STANDARD_COMPARE:
	case CB_INTR_STANDARD_DEVIATION:
	case CB_INTR_SUM:
	case CB_INTR_VARIANCE:
	case CB_INTR_YEAR_TO_YYYY:
		return make_intrinsic (name, cbp, args, cb_int1, NULL, 0);
	case CB_INTR_SUBSTITUTE:
	case CB_INTR_SUBSTITUTE_CASE:
		if ((numargs % 2) == 0) {
			cb_error_x (name, _("FUNCTION '%s' has wrong number of arguments"), cbp->name);
			return cb_error_node;
		}
#if	0	/* RXWRXW - Substitute param 1 */
		x = CB_VALUE (args);
		if (!CB_REF_OR_FIELD_P (x)) {
			cb_error_x (name, _("FUNCTION '%s' has invalid first parameter"), cbp->name);
			return cb_error_node;
		}
#endif
		return make_intrinsic (name, cbp, args, cb_int1, refmod, 0);

	default:
		cb_error_x (name, _("FUNCTION '%s' unknown"), CB_NAME (name));
		return cb_error_node;
	}
}
