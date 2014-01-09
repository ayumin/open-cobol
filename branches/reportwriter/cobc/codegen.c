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
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#include "tarstamp.h"

#include "cobc.h"
#include "tree.h"

#ifdef	HAVE_ATTRIBUTE_ALIGNED
#define COB_ALIGN " __attribute__((aligned))"
#else
#define COB_ALIGN ""
#endif

#define COB_MAX_SUBSCRIPTS	16

#define COB_MALLOC_ALIGN	15

#define COB_INSIDE_SIZE		64

#define INITIALIZE_NONE		0
#define INITIALIZE_ONE		1
#define INITIALIZE_DEFAULT	2
#define INITIALIZE_COMPOUND	3

#define CB_NEED_HIGH		(1U << 0)
#define CB_NEED_LOW		(1U << 1)
#define CB_NEED_QUOTE		(1U << 2)
#define CB_NEED_SPACE		(1U << 3)
#define CB_NEED_ZERO		(1U << 4)

struct sort_list {
	struct sort_list	*next;
};

struct system_table {
	const char		*syst_name;
	const char		*syst_call;
};

struct label_list {
	struct label_list	*next;
	int			id;
	int			call_num;
};

struct string_list {
	struct string_list	*next;
	char			*text;
	int			id;
};

struct attr_list {
	struct attr_list	*next;
	unsigned char		*pic;
	int			id;
	int			type;
	cob_u32_t		digits;
	int			scale;
	cob_u32_t		flags;
	int			lenstr;
};

struct literal_list {
	struct literal_list	*next;
	struct cb_literal	*literal;
	cb_tree			x;
	int			id;
};

struct field_list {
	struct field_list	*next;
	struct cb_field		*f;
	cb_tree			x;
	const char		*curr_prog;
};

struct call_list {
	struct call_list	*next;
	const char		*callname;
};

struct base_list {
	struct base_list	*next;
	struct cb_field		*f;
	const char		*curr_prog;
};


/* Local variables */

static struct attr_list		*attr_cache = NULL;
static struct literal_list	*literal_cache = NULL;
static struct field_list	*field_cache = NULL;
static struct field_list	*local_field_cache = NULL;
static struct call_list		*call_cache = NULL;
static struct call_list		*func_call_cache = NULL;
static struct base_list		*base_cache = NULL;
static struct base_list		*globext_cache = NULL;
static struct base_list		*local_base_cache = NULL;
static struct string_list	*string_cache = NULL;
static char			*string_buffer = NULL;
static struct label_list	*label_cache = NULL;


static FILE			*output_target = NULL;
static FILE			*cb_local_file = NULL;
static const char		*excp_current_program_id = NULL;
static const char		*excp_current_section = NULL;
static const char		*excp_current_paragraph = NULL;
static struct cb_program	*current_prog = NULL;

static struct cb_label		*last_section = NULL;
static unsigned char		*litbuff = NULL;
static int			litsize = 0;

static unsigned int		needs_exit_prog = 0;
static unsigned int		needs_unifunc = 0;
static unsigned int		need_save_exception = 0;
static unsigned int		gen_nested_tab = 0;
static unsigned int		gen_alt_ebcdic = 0;
static unsigned int		gen_ebcdic_ascii = 0;
static unsigned int		gen_full_ebcdic = 0;
static unsigned int		gen_native = 0;
static unsigned int		gen_custom = 0;
static unsigned int		gen_figurative = 0;
static unsigned int		gen_dynamic = 0;
static int			generate_id = 0;

static int			param_id = 0;
static int			stack_id = 0;
static int			string_id;
static int			num_cob_fields = 0;
static int			non_nested_count = 0;
static int			loop_counter = 0;
static int			progid = 0;
static int			last_line = 0;
static cob_u32_t		field_iteration = 0;
static int			screenptr = 0;
static int			local_mem = 0;
static int			working_mem = 0;
static int			local_working_mem = 0;
static int			output_indent_level = 0;
static int			last_segment = 0;
static int			gen_if_level = 0;
static unsigned int		nolitcast = 0;

static unsigned int		inside_check = 0;
static unsigned int		inside_stack[COB_INSIDE_SIZE];

static unsigned int		i_counters[COB_MAX_SUBSCRIPTS];

#undef	COB_SYSTEM_GEN
#define	COB_SYSTEM_GEN(x, y, z)	{ x, #z },

static const struct system_table	system_tab[] = {
#include "libcob/system.def"
	{ NULL, NULL }
};

#undef	COB_SYSTEM_GEN

/* Declarations */
static void output (const char *, ...)		COB_A_FORMAT12;
static void output_line (const char *, ...)	COB_A_FORMAT12;
static void output_storage (const char *, ...)	COB_A_FORMAT12;
static void output_local (const char *, ...)	COB_A_FORMAT12;

static void output_stmt		(cb_tree);
static void output_integer	(cb_tree);
static void output_index	(cb_tree);
static void output_func_1	(const char *, cb_tree);
static void output_param	(cb_tree, int);
static void output_funcall	(cb_tree);

/* Local functions */

static struct cb_field *
cb_code_field (cb_tree x)
{
        if (likely(CB_REFERENCE_P (x))) {
                if (unlikely(!CB_REFERENCE (x)->value)) {
                        return CB_FIELD (cb_ref (x));
                }
                return CB_FIELD (CB_REFERENCE (x)->value);
        }
        return CB_FIELD (x);
}

static int
lookup_string (const char *p)
{
	struct string_list *stp;

	for (stp = string_cache; stp; stp = stp->next) {
		if (strcmp (p, stp->text) == 0) {
			return stp->id;
		}
	}
	stp = cobc_parse_malloc (sizeof (struct string_list));
	stp->text = cobc_parse_strdup (p);
	stp->id = string_id;
	stp->next = string_cache;
	string_cache = stp;
	return string_id++;
}

static void
lookup_call (const char *p)
{
	struct call_list *clp;

	for (clp = call_cache; clp; clp = clp->next) {
		if (strcmp (p, clp->callname) == 0) {
			return;
		}
	}
	clp = cobc_parse_malloc (sizeof (struct call_list));
	clp->callname = p;
	clp->next = call_cache;
	call_cache = clp;
}

static void
lookup_func_call (const char *p)
{
	struct call_list *clp;

	for (clp = func_call_cache; clp; clp = clp->next) {
		if (strcmp (p, clp->callname) == 0) {
			return;
		}
	}
	clp = cobc_parse_malloc (sizeof (struct call_list));
	clp->callname = p;
	clp->next = func_call_cache;
	func_call_cache = clp;
}

static struct attr_list *
attr_list_reverse (struct attr_list *p)
{
	struct attr_list	*next;
	struct attr_list	*last;

	last = NULL;
	for (; p; p = next) {
		next = p->next;
		p->next = last;
		last = p;
	}
	return last;
}

static struct string_list *
string_list_reverse (struct string_list *p)
{
	struct string_list	*next;
	struct string_list	*last;

	last = NULL;
	for (; p; p = next) {
		next = p->next;
		p->next = last;
		last = p;
	}
	return last;
}

static struct literal_list *
literal_list_reverse (struct literal_list *p)
{
	struct literal_list	*next;
	struct literal_list	*last;

	last = NULL;
	for (; p; p = next) {
		next = p->next;
		p->next = last;
		last = p;
	}
	return last;
}

static int field_cache_cmp (const void *mp1, const void *mp2) {
	const struct field_list	*fl1;
	const struct field_list	*fl2;
	int			ret;

	fl1 = (const struct field_list *)mp1;
	fl2 = (const struct field_list *)mp2;
	ret = strcasecmp (fl1->curr_prog, fl2->curr_prog);
	if (ret) {
		return ret;
	}
	return fl1->f->id - fl2->f->id;
}

static int base_cache_cmp (const void *mp1, const void *mp2) {
	const struct base_list	*fl1;
	const struct base_list	*fl2;

	fl1 = (const struct base_list *)mp1;
	fl2 = (const struct base_list *)mp2;
	return fl1->f->id - fl2->f->id;
}

/* Sort a structure linked list in place */
/* Assumed that pointer "next" is first item in structure */

static void *
list_cache_sort (void *inlist, int (*cmpfunc)(const void *mp1, const void *mp2))
{
	struct sort_list	*p;
	struct sort_list	*q;
	struct sort_list	*e;
	struct sort_list	*tail;
	struct sort_list	*list;
	size_t			insize;
	size_t			nmerges;
	size_t			psize;
	size_t			qsize;
	size_t			i;

	if (!inlist) {
		return NULL;
	}
	list = (struct sort_list *)inlist;
	insize = 1;
	for (;;) {
		p = list;
		list = NULL;
		tail = NULL;
		nmerges = 0;
		while (p) {
			nmerges++;
			q = p;
			psize = 0;
			for (i = 0; i < insize; i++) {
				psize++;
				q = q->next;
				if (!q) {
					break;
				}
			}
			qsize = insize;
			while (psize > 0 || (qsize > 0 && q)) {
				if (psize == 0) {
					e = q;
					q = q->next;
					if (qsize) {
						qsize--;
					}
				} else if (qsize == 0 || !q) {
					e = p;
					p = p->next;
					if (psize) {
						psize--;
					}
				} else if ((*cmpfunc) (p, q) <= 0) {
					e = p;
					p = p->next;
					if (psize) {
						psize--;
					}
				} else {
					e = q;
					q = q->next;
					if (qsize) {
						qsize--;
					}
				}
				if (tail) {
					tail->next = e;
				} else {
					list = e;
				}
				tail = e;
			}
			p = q;
		}
		tail->next = NULL;
		if (nmerges <= 1) {
			return (void *)list;
		}
		insize *= 2;
	}
}

/* Output routines */

static void
output (const char *fmt, ...)
{
	va_list		ap;

	if (output_target) {
		va_start (ap, fmt);
		vfprintf (output_target, fmt, ap);
		va_end (ap);
	}
}

static void
output_newline (void)
{
	if (output_target) {
		fputs ("\n", output_target);
	}
}

static void
output_prefix (void)
{
	int	i;

	if (output_target) {
		for (i = 0; i < output_indent_level; i++) {
			fputc (' ', output_target);
		}
	}
}

static void
output_line (const char *fmt, ...)
{
	va_list		ap;

	if (output_target) {
		output_prefix ();
		va_start (ap, fmt);
		vfprintf (output_target, fmt, ap);
		va_end (ap);
		fputc ('\n', output_target);
	}
}

static void
output_indent (const char *str)
{
	const char	*p;
	int		level;

	level = 2;
	for (p = str; *p == ' '; p++) {
		level++;
	}

	if (*p == '}' && strcmp (str, "})") != 0) {
		output_indent_level -= level;
	}

	output_line (str);

	if (*p == '{' && strcmp (str, ")}") != 0) {
		output_indent_level += level;
	}
}

static void
output_string (const unsigned char *s, const int size, const cob_u32_t llit)
{
	int	i;
	int	c;

	if (!s) {
		output ("NULL");
		return;
	}
	output ("\"");
	for (i = 0; i < size; i++) {
		c = s[i];
		if (!isprint (c)) {
			output ("\\%03o", c);
		} else if (c == '\"') {
			output ("\\%c", c);
		} else if ((c == '\\' || c == '?') && !llit) {
			output ("\\%c", c);
		} else {
			output ("%c", c);
		}
	}
	output ("\"");
}

static void
output_storage (const char *fmt, ...)
{
	va_list		ap;

	if (cb_storage_file) {
		va_start (ap, fmt);
		vfprintf (cb_storage_file, fmt, ap);
		va_end (ap);
	}
}

static void
output_local (const char *fmt, ...)
{
	va_list		ap;

	if (cb_local_file) {
		va_start (ap, fmt);
		vfprintf (cb_local_file, fmt, ap);
		va_end (ap);
	}
}

/* Field */

static struct cb_field *
real_field_founder (const struct cb_field *f)
{
	const struct cb_field		*ff;

	ff = f;
	while (ff->parent) {
		ff = ff->parent;
	}
	if (ff->redefines) {
		return ff->redefines;
	}
	return (struct cb_field *)ff;
}

static struct cb_field *
chk_field_variable_size (struct cb_field *f)
{
	struct cb_field		*p;
	struct cb_field		*fc;

	if (f->flag_vsize_done) {
		return f->vsize;
	}
	for (fc = f->children; fc; fc = fc->sister) {
		if (fc->depending) {
			f->vsize = fc;
			f->flag_vsize_done = 1;
			return fc;
		} else if ((p = chk_field_variable_size (fc)) != NULL) {
			f->vsize = p;
			f->flag_vsize_done = 1;
			return p;
		}
	}
	f->vsize = NULL;
	f->flag_vsize_done = 1;
	return NULL;
}

static unsigned int
chk_field_variable_address (struct cb_field *fld)
{
	struct cb_field		*p;
	struct cb_field		*f;

	if (fld->flag_vaddr_done) {
		return fld->vaddr;
	}
	f = fld;
	for (p = f->parent; p; f = f->parent, p = f->parent) {
		for (p = p->children; p != f; p = p->sister) {
			if (p->depending || chk_field_variable_size (p)) {
				fld->vaddr = 1;
				fld->flag_vaddr_done = 1;
				return 1;
			}
		}
	}
	fld->vaddr = 0;
	fld->flag_vaddr_done = 1;
	return 0;
}

static void
output_base (struct cb_field *f, const cob_u32_t no_output)
{
	struct cb_field		*f01;
	struct cb_field		*p;
	struct cb_field		*v;
	struct base_list	*bl;

	if (f->flag_item_78) {
		cobc_abort_pr (_("Unexpected CONSTANT item"));
		COBC_ABORT ();
	}

	f01 = real_field_founder (f);

	/* Base storage */

	if (!f01->flag_base) {
		if (f01->special_index > 1U) {
			bl = cobc_parse_malloc (sizeof (struct base_list));
			bl->f = f01;
			bl->curr_prog = excp_current_program_id;
			bl->next = local_base_cache;
			local_base_cache = bl;
		} else if (!f01->flag_external && !f01->flag_local_storage) {
/* RXWRXW
		if (!f01->flag_external && !f01->flag_local_storage) {
*/
			if (!f01->flag_local || f01->flag_is_global) {
				bl = cobc_parse_malloc (sizeof (struct base_list));
				bl->f = f01;
				bl->curr_prog = excp_current_program_id;
				if (f01->flag_is_global ||
				    current_prog->flag_file_global) {
					bl->next = base_cache;
					base_cache = bl;
				} else {
					bl->next = local_base_cache;
					local_base_cache = bl;
				}
			} else {
				if (current_prog->flag_global_use) {
					output_local ("unsigned char\t\t*%s%d = NULL;",
							CB_PREFIX_BASE, f01->id);
					output_local ("\t/* %s */\n", f01->name);
					output_local ("static unsigned char\t*save_%s%d;\n",
							CB_PREFIX_BASE, f01->id);
				} else {
					output_local ("unsigned char\t*%s%d = NULL;",
							CB_PREFIX_BASE, f01->id);
					output_local ("\t/* %s */\n", f01->name);
				}
			}
		}
		f01->flag_base = 1;
	}
	if (no_output) {
		return;
	}

	if (f01->special_index) {
		output ("(cob_u8_t *)&%s%d", CB_PREFIX_BASE, f01->id);
		return;
	} else if (f01->flag_local_storage) {
		if (f01->mem_offset) {
			output ("cob_local_ptr + %d", f01->mem_offset);
		} else {
			output ("cob_local_ptr");
		}
	} else {
		output ("%s%d", CB_PREFIX_BASE, f01->id);
	}

	if (chk_field_variable_address (f)) {
		for (p = f->parent; p; f = f->parent, p = f->parent) {
			for (p = p->children; p != f; p = p->sister) {
				v = chk_field_variable_size (p);
				if (v) {
					output (" + %d + ", v->offset - p->offset);
					if (v->size != 1) {
						output ("%d * ", v->size);
					}
					output_integer (v->depending);
				} else if (p->depending && cb_flag_odoslide) {
					output (" + ");
					if (p->size != 1) {
						output ("%d * ", p->size);
					}
					output_integer (p->depending);
				} else {
					output (" + %d", p->size * p->occurs_max);
				}
			}
		}
	} else if (f->offset > 0) {
		output (" + %d", f->offset);
	}
}

static void
output_data (cb_tree x)
{
	struct cb_literal	*l;
	struct cb_reference	*r;
	struct cb_field		*f;
	cb_tree			lsub;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_LITERAL:
		l = CB_LITERAL (x);
		if (CB_TREE_CLASS (x) == CB_CLASS_NUMERIC) {
			output ("(cob_u8_ptr)\"%s%s\"", (char *)l->data,
				(l->sign < 0) ? "-" : (l->sign > 0) ? "+" : "");
		} else {
			output ("(cob_u8_ptr)");
			output_string (l->data, (int) l->size, l->llit);
		}
		break;
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (x);
		f = CB_FIELD (r->value);

		/* Base address */
		output_base (f, 0);

		/* Subscripts */
		if (r->subs) {
			lsub = r->subs;
			for (; f && lsub; f = f->parent) {
				if (f->flag_occurs) {
					output (" + ");
					if (f->size != 1) {
						output ("%d * ", f->size);
					}
					output_index (CB_VALUE (lsub));
					lsub = CB_CHAIN (lsub);
				}
			}
		}

		/* Offset */
		if (r->offset) {
			output (" + ");
			output_index (r->offset);
		}
		break;
	case CB_TAG_FIELD:
		f = CB_FIELD (x);
		output("/* %s */",f->name);
		/* Base address */
		output_base (f, 0);
		break;
	case CB_TAG_CAST:
		output ("&");
		output_param (x, 0);
		break;
	case CB_TAG_INTRINSIC:
		output ("cob_procedure_params[%u]->data",
			field_iteration);
		break;
	case CB_TAG_CONST:
		if (x == cb_null) {
			output ("NULL");
			return;
		}
		/* Fall through */
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

static void
output_size (const cb_tree x)
{
	struct cb_literal	*l;
	struct cb_reference	*r;
	struct cb_field		*f;
	struct cb_field		*p;
	struct cb_field		*q;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		output ("1");
		break;
	case CB_TAG_LITERAL:
		l = CB_LITERAL (x);
		output ("%d", (int)(l->size + ((l->sign != 0) ? 1 : 0)));
		break;
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (x);
		f = CB_FIELD (r->value);
		if (f->flag_no_field) {
			output ("0");
			break;
		}
		if (r->length) {
			output_integer (r->length);
		} else if (r->offset) {
			if (f->flag_any_length) {
				output ("%s%d.size - ", CB_PREFIX_FIELD, f->id);
			} else {
				output ("%d - ", f->size);
			}
			output_index (r->offset);
		} else {
			p = chk_field_variable_size (f);
			q = f;

again:
			if (!cb_flag_odoslide && p && p->flag_odo_item) {
				q = p;
				output ("%d", p->size * p->occurs_max);
			} else if (p && (!r->flag_receiving ||
				   !cb_field_subordinate (cb_code_field (p->depending),
							  q))) {
				if (p->offset - q->offset > 0) {
					output ("%d + ", p->offset - q->offset);
				}
				if (p->size != 1) {
					output ("%d * ", p->size);
				}
				output_integer (p->depending);
				q = p;
			} else {
				output ("%d", q->size);
			}

			for (; q != f; q = q->parent) {
				if (q->sister && !q->sister->redefines) {
					q = q->sister;
					p = q->depending ? q : chk_field_variable_size (q);
					output (" + ");
					goto again;
				}
			}
		}
		break;
	case CB_TAG_FIELD:
		output ("(int)%s%d.size", CB_PREFIX_FIELD, CB_FIELD (x)->id);
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

static int
lookup_attr (const int type, const cob_u32_t digits, const int scale,
	     const cob_u32_t flags, unsigned char *pic, const int lenstr)
{
	struct attr_list *l;

	/* Search attribute cache */
	for (l = attr_cache; l; l = l->next) {
		if (type == l->type &&
		    digits == l->digits &&
		    scale == l->scale &&
		    flags == l->flags &&
		    ((pic == l->pic) || (pic && l->pic && lenstr == l->lenstr &&
		     memcmp ((char *)pic, (char *)(l->pic), (size_t)lenstr) == 0))) {
			return l->id;
		}
	}

	/* Cache new attribute */

	l = cobc_parse_malloc (sizeof (struct attr_list));
	l->id = cb_attr_id;
	l->type = type;
	l->digits = digits;
	l->scale = scale;
	l->flags = flags;
	l->pic = pic;
	l->lenstr = lenstr;
	l->next = attr_cache;
	attr_cache = l;

	return cb_attr_id++;
}

static char *
user_func_upper (const char *func)
{
	unsigned char	*s;
	char		*rets;

	rets = cb_encode_program_id (func);
	for (s = (unsigned char *)rets; *s; s++) {
		if (islower ((int)*s)) {
			*s = (cob_u8_t)toupper ((int)*s);
		}
	}
	return rets;
}

static void
output_attr (const cb_tree x)
{
	struct cb_literal	*l;
	struct cb_reference	*r;
	struct cb_field		*f;
	int			id;
	int			type;
	cob_u32_t		flags;

	id = 0;
	switch (CB_TREE_TAG (x)) {
	case CB_TAG_LITERAL:
		l = CB_LITERAL (x);
		if (CB_TREE_CLASS (x) == CB_CLASS_NUMERIC) {
			flags = 0;
			if (l->sign != 0) {
				flags = COB_FLAG_HAVE_SIGN | COB_FLAG_SIGN_SEPARATE;
			}
			id = lookup_attr (COB_TYPE_NUMERIC_DISPLAY,
					  l->size, l->scale, flags, NULL, 0);
		} else {
			if (l->all) {
				id = lookup_attr (COB_TYPE_ALPHANUMERIC_ALL, 0, 0, 0, NULL, 0);
			} else {
				id = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
			}
		}
		break;
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (x);
		f = CB_FIELD (r->value);
		flags = 0;
		if (r->offset) {
			id = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
		} else {
			type = cb_tree_type (x, f);
			switch (type) {
			case COB_TYPE_GROUP:
			case COB_TYPE_ALPHANUMERIC:
				if (f->flag_justified) {
					id = lookup_attr (type, 0, 0, COB_FLAG_JUSTIFIED, NULL, 0);
				} else {
					id = lookup_attr (type, 0, 0, 0, NULL, 0);
				}
				break;
			default:
				if (f->pic->have_sign) {
					flags |= COB_FLAG_HAVE_SIGN;
					if (f->flag_sign_separate) {
						flags |= COB_FLAG_SIGN_SEPARATE;
					}
					if (f->flag_sign_leading) {
						flags |= COB_FLAG_SIGN_LEADING;
					}
				}
				if (f->flag_blank_zero) {
					flags |= COB_FLAG_BLANK_ZERO;
				}
				if (f->flag_justified) {
					flags |= COB_FLAG_JUSTIFIED;
				}
				if (f->flag_binary_swap) {
					flags |= COB_FLAG_BINARY_SWAP;
				}
				if (f->flag_real_binary) {
					flags |= COB_FLAG_REAL_BINARY;
				}
				if (f->flag_is_pointer) {
					flags |= COB_FLAG_IS_POINTER;
				}
				if (cb_binary_truncate &&
				    f->usage == CB_USAGE_BINARY &&
				    !f->flag_real_binary) {
					flags |= COB_FLAG_BINARY_TRUNC;
				}

				switch (f->usage) {
				case CB_USAGE_COMP_6:
					flags |= COB_FLAG_NO_SIGN_NIBBLE;
					break;
				case CB_USAGE_DOUBLE:
				case CB_USAGE_FLOAT:
				case CB_USAGE_LONG_DOUBLE:
#if	0	/* RXWRXW - Floating ind */
				case CB_USAGE_FP_BIN32:
				case CB_USAGE_FP_BIN64:
				case CB_USAGE_FP_BIN128:
				case CB_USAGE_FP_DEC64:
				case CB_USAGE_FP_DEC128:
#endif
					flags |= COB_FLAG_IS_FP;
					break;
				default:
					break;
				}

				id = lookup_attr (type, f->pic->digits,
						  f->pic->scale, flags,
						  (cob_u8_ptr) f->pic->str,
						  f->pic->lenstr);
				break;
			}
		}
		break;
	case CB_TAG_ALPHABET_NAME:
		id = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}

	output ("&%s%d", CB_PREFIX_ATTR, id);
}

static void
output_field (cb_tree x)
{
	output ("{");
	output_size (x);
	output (", ");
	output_data (x);
	output (", ");
	output_attr (x);
	output ("}");
}

/*
 * Emit cob_field with comments
 */
static void
output_emit_field(cb_tree x, const char *cmt)
{
	struct cb_field *f = cb_code_field (x);
	if(f
	&& !(f->report_flag & COB_REPORT_REF_EMITED)) {
		f->report_flag |= COB_REPORT_REF_EMITED;
		output ("static cob_field %s%d\t= ", CB_PREFIX_FIELD, f->id);
		output_field (x);
		if(cmt
		&& strlen(cmt) > 0)
			output_local(";\t/* %s %s */\n",cmt,f->name);
		else
			output_local(";\t/* %s */\n",f->name);
	}
}

/* Literal */

static int
lookup_literal (cb_tree x)
{

	struct cb_literal	*literal;
	struct literal_list	*l;
	FILE			*savetarget;

	literal = CB_LITERAL (x);
	/* Search literal cache */
	for (l = literal_cache; l; l = l->next) {
		if (CB_TREE_CLASS (literal) == CB_TREE_CLASS (l->literal) &&
		    literal->size == l->literal->size &&
		    literal->all == l->literal->all &&
		    literal->sign == l->literal->sign &&
		    literal->scale == l->literal->scale &&
		    memcmp (literal->data, l->literal->data,
			    (size_t)literal->size) == 0) {
			return l->id;
		}
	}

	/* Output new literal */
	savetarget = output_target;
	output_target = NULL;
	output_field (x);

	output_target = savetarget;

	/* Cache it */
	l = cobc_parse_malloc (sizeof (struct literal_list));
	l->id = cb_literal_id;
	l->literal = literal;
	l->x = x;
	l->next = literal_cache;
	literal_cache = l;

	return cb_literal_id++;
}

/* Integer */

static void
output_integer (cb_tree x)
{
	struct cb_binary_op	*p;
	struct cb_cast		*cp;
	struct cb_field		*f;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x == cb_zero) {
			output ("0");
		} else if (x == cb_null) {
			output ("(cob_u8_ptr)NULL");
		} else {
			output ("%s", CB_CONST (x)->val);
		}
		break;
	case CB_TAG_INTEGER:
		if (CB_INTEGER (x)->hexval) {
			output ("0x%X", CB_INTEGER (x)->val);
		} else {
			output ("%d", CB_INTEGER (x)->val);
		}
		break;
	case CB_TAG_LITERAL:
		output ("%d", cb_get_int (x));
		break;
	case CB_TAG_BINARY_OP:
		p = CB_BINARY_OP (x);
		if (p->flag) {
			if (!cb_fits_int (p->x) || !cb_fits_int (p->y)) {
				output ("cob_get_int (");
				output_param (x, -1);
				output (")");
				break;
			}
		}
		if (p->op == '^') {
			output ("(int) pow (");
			output_integer (p->x);
			output (", ");
			output_integer (p->y);
			output (")");
		} else {
			output ("(");
			output_integer (p->x);
			output (" %c ", p->op);
			output_integer (p->y);
			output (")");
		}
		break;
	case CB_TAG_CAST:
		cp = CB_CAST (x);
		switch (cp->cast_type) {
		case CB_CAST_ADDRESS:
			output ("(");
			output_data (cp->val);
			output (")");
			break;
		case CB_CAST_PROGRAM_POINTER:
			output ("cob_call_field (");
			output_param (x, -1);
			if (current_prog->nested_prog_list) {
				gen_nested_tab = 1;
				output (", cob_nest_tab, 0, %d)", cb_fold_call);
			} else {
				output (", NULL, 0, %d)", cb_fold_call);
			}
			break;
		default:
			cobc_abort_pr (_("Unexpected cast type %d"),
				 (int)cp->cast_type);
			COBC_ABORT ();
		}
		break;
	case CB_TAG_REFERENCE:
		f = cb_code_field (x);
		switch (f->usage) {
		case CB_USAGE_INDEX:
			if (f->special_index) {
				output_base (f, 1U);
				output ("%s%d", CB_PREFIX_BASE, f->id);
				return;
			}
			/* Fall through */
		case CB_USAGE_LENGTH:
			output ("(*(int *) (");
			output_data (x);
			output ("))");
			return;

		case CB_USAGE_POINTER:
#ifdef	COB_NON_ALIGNED
			output ("(cob_get_pointer (");
			output_data (x);
			output ("))");
#else
			output ("(*(unsigned char **) (");
			output_data (x);
			output ("))");
#endif
			return;

		case CB_USAGE_PROGRAM_POINTER:
#ifdef	COB_NON_ALIGNED
			output ("(cob_get_prog_pointer (");
			output_data (x);
			output ("))");
#else
			output ("(*(void **) (");
			output_data (x);
			output ("))");
#endif
			return;

		case CB_USAGE_DISPLAY:
			if (f->pic && f->pic->scale >= 0 &&
			    f->size - f->pic->scale > 0 &&
			    f->size - f->pic->scale <= 9 &&
			    f->pic->have_sign == 0 &&
			    !cb_ebcdic_sign) {
				optimize_defs[COB_GET_NUMDISP] = 1;
				output ("cob_get_numdisp (");
				output_data (x);
				output (", %d)", f->size - f->pic->scale);
				return;
			}
			break;

		case CB_USAGE_PACKED:
			if (f->pic->scale == 0 && f->pic->digits < 10) {
				optimize_defs[COB_GET_PACKED_INT] = 1;
				output_func_1 ("cob_get_packed_int", x);
				return;
			}
			break;

		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
			if (f->size == 1) {
				output ("(*(");
				if (!f->pic->have_sign) {
					output ("cob_u8_ptr) (");
				} else {
					output ("cob_s8_ptr) (");
				}
				output_data (x);
				output ("))");
				return;
			}
#ifdef	COB_NON_ALIGNED
			if (f->storage != CB_STORAGE_LINKAGE && f->indexes == 0 && (
#ifdef	COB_SHORT_BORK
				(f->size == 2 && (f->offset % 4 == 0)) ||
#else
				(f->size == 2 && (f->offset % 2 == 0)) ||
#endif
				(f->size == 4 && (f->offset % 4 == 0)) ||
				(f->size == 8 && (f->offset % 8 == 0)))) {
#else
			if (f->size == 2 || f->size == 4 || f->size == 8) {
#endif
				if (f->flag_binary_swap) {
					output ("((");
					switch (f->size) {
					case 2:
						if (!f->pic->have_sign) {
							output ("unsigned short)COB_BSWAP_16(");
						} else {
							output ("short)COB_BSWAP_16(");
						}
						break;
					case 4:
						if (!f->pic->have_sign) {
							output ("unsigned int)COB_BSWAP_32(");
						} else {
							output ("int)COB_BSWAP_32(");
						}
						break;
					case 8:
						if (!f->pic->have_sign) {
							output ("cob_u64_t)COB_BSWAP_64(");
						} else {
							output ("cob_s64_t)COB_BSWAP_64(");
						}
						break;
					default:
						break;
					}
					output ("*(");
					switch (f->size) {
					case 2:
						output ("short *)(");
						break;
					case 4:
						output ("int *)(");
						break;
					case 8:
						output ("cob_s64_t *)(");
						break;
					default:
						break;
					}
					output_data (x);
					output (")))");
					return;
				} else {
					output ("(*(");
					switch (f->size) {
					case 2:
						if (!f->pic->have_sign) {
							output ("unsigned short *)(");
						} else {
							output ("short *)(");
						}
						break;
					case 4:
						if (!f->pic->have_sign) {
							output ("unsigned int *)(");
						} else {
							output ("int *)(");
						}
						break;
					case 8:
						if (!f->pic->have_sign) {
							output ("cob_u64_ptr)(");
						} else {
							output ("cob_s64_ptr)(");
						}
						break;
					default:
						break;
					}
					output_data (x);
					output ("))");
					return;
				}
			}
			if (f->pic->have_sign == 0) {
				output ("(unsigned int)");
			}
			break;

		default:
			break;
		}

		output_func_1 ("cob_get_int", x);
		break;
	case CB_TAG_INTRINSIC:
		output ("cob_get_int (");
		output_param (x, -1);
		output (")");
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

static void
output_long_integer (cb_tree x)
{
	struct cb_binary_op	*p;
	struct cb_cast		*cp;
	struct cb_field		*f;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x == cb_zero) {
			output ("0");
		} else if (x == cb_null) {
			output ("(cob_u8_ptr)NULL");
		} else {
			output ("%s", CB_CONST (x)->val);
		}
		break;
	case CB_TAG_INTEGER:
		if (CB_INTEGER (x)->hexval) {
			output ("0x%X", CB_INTEGER (x)->val);
		} else {
			output ("%d", CB_INTEGER (x)->val);
		}
		break;
	case CB_TAG_LITERAL:
		output (CB_FMT_LLD_F, cb_get_long_long (x));
		break;
	case CB_TAG_BINARY_OP:
		p = CB_BINARY_OP (x);
		if (p->flag) {
			if (!cb_fits_long_long (p->x) ||
			    !cb_fits_long_long (p->y)) {
				output ("cob_get_llint (");
				output_param (x, -1);
				output (")");
				break;
			}
		}
		if (p->op == '^') {
			output ("(cob_s64_t) pow (");
			output_long_integer (p->x);
			output (", ");
			output_long_integer (p->y);
			output (")");
		} else {
			output ("(");
			output_long_integer (p->x);
			output (" %c ", p->op);
			output_long_integer (p->y);
			output (")");
		}
		break;
	case CB_TAG_CAST:
		cp = CB_CAST (x);
		switch (cp->cast_type) {
		case CB_CAST_ADDRESS:
			output ("(");
			output_data (cp->val);
			output (")");
			break;
		case CB_CAST_PROGRAM_POINTER:
			output ("cob_call_field (");
			output_param (x, -1);
			if (current_prog->nested_prog_list) {
				gen_nested_tab = 1;
				output (", cob_nest_tab, 0, %d)", cb_fold_call);
			} else {
				output (", NULL, 0, %d)", cb_fold_call);
			}
			break;
		default:
			cobc_abort_pr (_("Unexpected cast type %d"),
				 (int)cp->cast_type);
			COBC_ABORT ();
		}
		break;
	case CB_TAG_REFERENCE:
		f = cb_code_field (x);
		switch (f->usage) {
		case CB_USAGE_INDEX:
			if (f->special_index) {
				output_base (f, 1U);
				output ("(cob_s64_t)%s%d", CB_PREFIX_BASE, f->id);
				return;
			}
			/* Fall through */
		case CB_USAGE_LENGTH:
			output ("(cob_s64_t)(*(int *) (");
			output_data (x);
			output ("))");
			return;

		case CB_USAGE_POINTER:
#ifdef	COB_NON_ALIGNED
			output ("(cob_get_pointer (");
			output_data (x);
			output ("))");
#else
			output ("(*(unsigned char **) (");
			output_data (x);
			output ("))");
#endif
			return;

		case CB_USAGE_PROGRAM_POINTER:
#ifdef	COB_NON_ALIGNED
			output ("(cob_get_prog_pointer (");
			output_data (x);
			output ("))");
#else
			output ("(*(void **) (");
			output_data (x);
			output ("))");
#endif
			return;

		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
			if (f->size == 1) {
				output ("(*(");
				if (!f->pic->have_sign) {
					output ("cob_u8_ptr) (");
				} else {
					output ("cob_s8_ptr) (");
				}
				output_data (x);
				output ("))");
				return;
			}
#ifdef	COB_NON_ALIGNED
			if (f->storage != CB_STORAGE_LINKAGE && f->indexes == 0 && (
#ifdef	COB_SHORT_BORK
				(f->size == 2 && (f->offset % 4 == 0)) ||
#else
				(f->size == 2 && (f->offset % 2 == 0)) ||
#endif
				(f->size == 4 && (f->offset % 4 == 0)) ||
				(f->size == 8 && (f->offset % 8 == 0)))) {
#else
			if (f->size == 2 || f->size == 4 || f->size == 8) {
#endif
				if (f->flag_binary_swap) {
					output ("((");
					switch (f->size) {
					case 2:
						if (!f->pic->have_sign) {
							output ("unsigned short)COB_BSWAP_16(");
						} else {
							output ("short)COB_BSWAP_16(");
						}
						break;
					case 4:
						if (!f->pic->have_sign) {
							output ("unsigned int)COB_BSWAP_32(");
						} else {
							output ("int)COB_BSWAP_32(");
						}
						break;
					case 8:
						if (!f->pic->have_sign) {
							output ("cob_u64_t)COB_BSWAP_64(");
						} else {
							output ("cob_s64_t)COB_BSWAP_64(");
						}
						break;
					default:
						break;
					}
					output ("*(");
					switch (f->size) {
					case 2:
						output ("short *)(");
						break;
					case 4:
						output ("int *)(");
						break;
					case 8:
						output ("cob_s64_t *)(");
						break;
					default:
						break;
					}
					output_data (x);
					output (")))");
					return;
				} else {
					output ("(*(");
					switch (f->size) {
					case 2:
						if (!f->pic->have_sign) {
							output ("unsigned short *)(");
						} else {
							output ("short *)(");
						}
						break;
					case 4:
						if (!f->pic->have_sign) {
							output ("unsigned int *)(");
						} else {
							output ("int *)(");
						}
						break;
					case 8:
						if (!f->pic->have_sign) {
							output ("cob_u64_ptr)(");
						} else {
							output ("cob_s64_ptr)(");
						}
						break;
					default:
						break;
					}
					output_data (x);
					output ("))");
					return;
				}
			}
#if	0	/* RXWRXW - unsigned */
			if (f->pic->have_sign == 0) {
				output ("(unsigned int)");
			}
#endif
			break;

		default:
			break;
		}

		output_func_1 ("cob_get_llint", x);
		break;
	case CB_TAG_INTRINSIC:
		output ("cob_get_llint (");
		output_param (x, -1);
		output (")");
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

static void
output_index (cb_tree x)
{
	switch (CB_TREE_TAG (x)) {
	case CB_TAG_INTEGER:
		output ("%d", CB_INTEGER (x)->val - 1);
		break;
	case CB_TAG_LITERAL:
		output ("%d", cb_get_int (x) - 1);
		break;
	default:
		output ("(");
		output_integer (x);
		output (" - 1)");
		break;
	}
}

/* Parameter */

static void
output_param (cb_tree x, int id)
{
	struct cb_reference	*r;
	struct cb_field		*f;
	struct cb_field		*ff;
	struct cb_cast		*cp;
	struct cb_binary_op	*bp;
	struct field_list	*fl;
	FILE			*savetarget;
	struct cb_intrinsic	*ip;
	struct cb_alphabet_name	*abp;
	struct cb_alphabet_name	*rbp;
	cb_tree			l;
	char			*func;
	int			n;
	int			sav_stack_id;
	char			fname[12];

	param_id = id;

	if (x == NULL) {
		output ("NULL");
		return;
	}

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x == cb_quote) {
			gen_figurative |= CB_NEED_QUOTE;
		} else if (x == cb_norm_low) {
			gen_figurative |= CB_NEED_LOW;
		} else if (x == cb_norm_high) {
			gen_figurative |= CB_NEED_HIGH;
		} else if (x == cb_space) {
			gen_figurative |= CB_NEED_SPACE;
		} else if (x == cb_zero) {
			gen_figurative |= CB_NEED_ZERO;
		}
		output ("%s", CB_CONST (x)->val);
		break;
	case CB_TAG_INTEGER:
		output_integer (x);
		break;
	case CB_TAG_STRING:
		output_string (CB_STRING (x)->data, (int) CB_STRING (x)->size, 0);
		break;
	case CB_TAG_LOCALE_NAME:
		output_param (CB_LOCALE_NAME(x)->list, id);
		break;
	case CB_TAG_ALPHABET_NAME:
		abp = CB_ALPHABET_NAME (x);
		switch (abp->alphabet_type) {
		case CB_ALPHABET_ASCII:
#ifdef	COB_EBCDIC_MACHINE
			gen_ebcdic_ascii = 1;
			output ("cob_ebcdic_ascii");
			break;
#endif
			/* Fall through for ASCII */
		case CB_ALPHABET_NATIVE:
			if (current_prog->collating_sequence) {
				gen_native = 1;
				output ("cob_native");
			} else {
				output ("NULL");
			}
			break;
		case CB_ALPHABET_EBCDIC:
#ifdef	COB_EBCDIC_MACHINE
			if (current_prog->collating_sequence) {
				gen_native = 1;
				output ("cob_native");
			} else {
				output ("NULL");
			}
#else
			if (cb_flag_alt_ebcdic) {
				gen_alt_ebcdic = 1;
				output ("cob_a2e");
			} else {
				gen_full_ebcdic = 1;
				output ("cob_ascii_ebcdic");
			}
#endif
			break;
		case CB_ALPHABET_CUSTOM:
			gen_custom = 1;
			output ("%s%s", CB_PREFIX_SEQUENCE, abp->cname);
			break;
		default:
			break;
		}
		break;
	case CB_TAG_CAST:
		cp = CB_CAST (x);
		switch (cp->cast_type) {
		case CB_CAST_INTEGER:
			output_integer (cp->val);
			break;
		case CB_CAST_LONG_INT:
			output_long_integer (cp->val);
			break;
		case CB_CAST_ADDRESS:
			output_data (cp->val);
			break;
		case CB_CAST_ADDR_OF_ADDR:
			output ("&");
			output_data (cp->val);
			break;
		case CB_CAST_LENGTH:
			output_size (cp->val);
			break;
		case CB_CAST_PROGRAM_POINTER:
			output_param (cp->val, id);
			break;
		default:
			break;
		}
		break;
	case CB_TAG_DECIMAL:
		output ("d%d", CB_DECIMAL (x)->id);
		break;
	case CB_TAG_FILE:
		output ("%s%s", CB_PREFIX_FILE, CB_FILE (x)->cname);
		break;
	case CB_TAG_REPORT:
		output ("&%s%s", CB_PREFIX_REPORT, CB_REPORT (CB_VALUE (x))->cname);
		break;
	case CB_TAG_REPORT_LINE:
		r = CB_REFERENCE (x);
		f = CB_FIELD (r->value);
		output ("&%s%d", CB_PREFIX_REPORT_LINE, f->id);
		break;
	case CB_TAG_LITERAL:
#if	0	/* RXWRXW - Const */
		output ("&%s%d.vf", CB_PREFIX_CONST, lookup_literal (x));
#else
		if (nolitcast) {
			output ("&%s%d", CB_PREFIX_CONST, lookup_literal (x));
		} else {
			output ("(cob_field *)&%s%d", CB_PREFIX_CONST,
				lookup_literal (x));
		}
#endif
		break;
	case CB_TAG_FIELD:
		/* TODO: remove me */
		output_param (cb_build_field_reference (CB_FIELD (x), NULL), id);
		break;
	case CB_TAG_REFERENCE:
		r = CB_REFERENCE (x);
		if (CB_LOCALE_NAME_P (r->value)) {
			output_param (CB_LOCALE_NAME(r->value)->list, id);
			break;
		}
		if (r->check) {
			inside_stack[inside_check++] = 0;
			if (inside_check >= COB_INSIDE_SIZE) {
				cobc_abort_pr (_("Internal statement stack depth exceeded -> %d"),
						COB_INSIDE_SIZE);
				COBC_ABORT ();
			}
			output ("\n");
			output_prefix ();
			output ("(");
			n = output_indent_level;
			output_indent_level = 0;
			for (l = r->check; l; l = CB_CHAIN (l)) {
				sav_stack_id = stack_id;
				output_stmt (CB_VALUE (l));
				stack_id = sav_stack_id;
				if (l == r->check) {
					output_indent_level = n;
				}
			}
		}

		if (CB_FILE_P (r->value)) {
			output ("%s%s", CB_PREFIX_FILE, CB_FILE (r->value)->cname);
			if (r->check) {
				if (inside_check) {
					--inside_check;
				}
				output (" )");
			}
			break;
		}
		if (CB_ALPHABET_NAME_P (r->value)) {
			rbp = CB_ALPHABET_NAME (r->value);
			switch (rbp->alphabet_type) {
			case CB_ALPHABET_ASCII:
#ifdef	COB_EBCDIC_MACHINE
				gen_ebcdic_ascii = 2;
				output ("&f_ebcdic_ascii");
				break;
#endif
			/* Fall through for ASCII */
			case CB_ALPHABET_NATIVE:
				gen_native = 2;
				output ("&f_native");
				break;
			case CB_ALPHABET_EBCDIC:
#ifdef	COB_EBCDIC_MACHINE
				gen_native = 2;
				output ("&f_native");
#else
				gen_full_ebcdic = 2;
				output ("&f_ascii_ebcdic");
#endif
				break;
			case CB_ALPHABET_CUSTOM:
				gen_custom = 1;
				output ("&%s%s", CB_PREFIX_FIELD, rbp->cname);
				break;
			default:
				break;
			}
			if (r->check) {
				if (inside_check) {
					--inside_check;
				}
				output (" )");
			}
			break;
		}

		f = CB_FIELD (r->value);

		ff = real_field_founder (f);

		if (ff->flag_external) {
			f->flag_external = 1;
			f->flag_local = 1;
		} else if (ff->flag_item_based) {
			f->flag_local = 1;
		}

		if (!r->subs && !r->offset && f->count > 0 &&
		    !chk_field_variable_size (f) &&
		    !chk_field_variable_address (f)) {
			if (!f->flag_field) {
				savetarget = output_target;
				output_target = NULL;
				output_field (x);

				fl = cobc_parse_malloc (sizeof (struct field_list));
				fl->x = x;
				fl->f = f;
				fl->curr_prog = excp_current_program_id;
				if (f->special_index != 2 && (f->flag_is_global ||
				    current_prog->flag_file_global)) {
					fl->next = field_cache;
					field_cache = fl;
				} else {
					fl->next = local_field_cache;
					local_field_cache = fl;
				}

				f->flag_field = 1;
				output_target = savetarget;
			}
			if (f->flag_local) {
#if	0	/* RXWRXW - Any data pointer */
				if (f->flag_any_length && f->flag_anylen_done) {
					output ("&%s%d",
						CB_PREFIX_FIELD, f->id);
				} else {
#endif
				output ("COB_SET_DATA (%s%d, ",
					CB_PREFIX_FIELD, f->id);
				output_data (x);
				output (")");
#if	0	/* RXWRXW - Any data pointer */
				f->flag_anylen_done = 1;
				}
#endif
			} else {
				if (screenptr && f->storage == CB_STORAGE_SCREEN) {
					output ("&s_%d", f->id);
				} else {
					output ("&%s%d", CB_PREFIX_FIELD, f->id);
				}
			}
		} else {
			if (stack_id >= num_cob_fields) {
				num_cob_fields = stack_id + 1;
			}
			sprintf (fname, "f%d", stack_id++);
			if (inside_check != 0) {
				if (inside_stack[inside_check - 1] != 0) {
					inside_stack[inside_check - 1] = 0;
					output (",\n");
					output_prefix ();
				}
			}
			output ("COB_SET_FLD(%s, ", fname);
			output_size (x);
			output (", ");
			output_data (x);
			output (", ");
			output_attr (x);
			output (")");
		}

		if (r->check) {
			if (inside_check) {
				--inside_check;
			}
			output (" )");
		}
		break;
	case CB_TAG_BINARY_OP:
		bp = CB_BINARY_OP (x);
		output ("cob_intr_binop (");
		output_param (bp->x, id);
		output (", ");
		output ("%d", bp->op);
		output (", ");
		output_param (bp->y, id);
		output (")");
		break;
	case CB_TAG_INTRINSIC:
		ip = CB_INTRINSIC (x);
		if (ip->isuser) {
			func = user_func_upper (cb_name(ip->name));
			lookup_func_call (func);
#if	0	/* RXWRXW Func */
			output ("cob_user_function (func_%s, &cob_dyn_%u, ",
				func, gen_dynamic);
#else
			output ("func_%s.funcfld (&cob_dyn_%u",
				func, gen_dynamic);
#endif
			gen_dynamic++;
			if (ip->intr_field || ip->args) {
				output (", ");
			}
#if	0	/* RXWRXW Func */
			if (ip->intr_tab->refmod) {
				if (ip->offset) {
					output_integer (ip->offset);
					output (", ");
				} else {
					output ("0, ");
				}
				if (ip->length) {
					output_integer (ip->length);
				} else {
					output ("0");
				}
				if (ip->intr_field || ip->args) {
					output (", ");
				}
			}
#endif
		} else {
			output ("%s (", ip->intr_tab->intr_routine);
			if (ip->intr_tab->refmod) {
				if (ip->offset) {
					output_integer (ip->offset);
					output (", ");
				} else {
					output ("0, ");
				}
				if (ip->length) {
					output_integer (ip->length);
				} else {
					output ("0");
				}
				if (ip->intr_field || ip->args) {
					output (", ");
				}
			}
		}
		if (ip->intr_field) {
			if (ip->intr_field == cb_int0) {
				output ("NULL");
			} else if (ip->intr_field == cb_int1) {
				output ("%d", cb_list_length (ip->args));
			} else {
				output_param (ip->intr_field, id);
			}
			if (ip->args) {
				output (", ");
			}
		}
		for (l = ip->args; l; l = CB_CHAIN (l)) {
			output_param (CB_VALUE (l), id);
			id++;
			param_id++;
			if (CB_CHAIN (l)) {
				output (", ");
			}
		}
		output (")");
		break;
	case CB_TAG_FUNCALL:
		output_funcall (x);
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

/*
 * Emit case for each control Declaratives
 * for GENERATE to execute
 */
static void
cb_emit_decl_case(struct cb_report *r, struct cb_field *f)
{
	struct cb_field         *p;
	for (p = f; p; p = p->sister) {
		if(p->report_decl_id) {
			output ("\tcase %d:\t/* %s */\n",p->report_decl_id,p->name);
			output ("\t\tframe_ptr++;\n");
			output ("\t\tframe_ptr->perform_through = %d;\n",p->report_decl_id);
			output ("\t\tframe_ptr->return_address_ptr = &&genbgn_%d;\n",generate_id);
			output ("\t\tgoto %s%d;\n",CB_PREFIX_LABEL,p->report_decl_id);
			output ("\t\tbreak;\n");
		}
		if(p->children) {
			cb_emit_decl_case(r, p->children);
		}
	}
}
/* Function call */

static void
output_funcall (cb_tree x)
{
	struct cb_funcall	*p;
	cb_tree			l;
	int			i;
	struct cb_report	*r;

	p = CB_FUNCALL (x);
	if (p->name[0] == '$') {
		switch (p->name[1]) {
		case 'E':
			/* Set of one character */
			output ("*(");
			output_data (p->argv[0]);
			output (") = ");
			output_param (p->argv[1], 1);
			break;
		case 'F':
			/* Move of one character */
			output ("*(");
			output_data (p->argv[0]);
			output (") = *(");
			output_data (p->argv[1]);
			output (")");
			break;
		case 'G':
			/* Test of one character */
			output ("(int)(*(");
			output_data (p->argv[0]);
			if (p->argv[1] == cb_space) {
				output (") - ' ')");
			} else if (p->argv[1] == cb_zero) {
				output (") - '0')");
			} else if (p->argv[1] == cb_low) {
				output ("))");
			} else if (p->argv[1] == cb_high) {
				output (") - 255)");
			} else if (CB_LITERAL_P (p->argv[1])) {
				output (") - %d)", *(CB_LITERAL (p->argv[1])->data));
			} else {
				output (") - *(");
				output_data (p->argv[1]);
				output ("))");
			}
			break;
		case 'R':	/* Generate REPORT line */
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			generate_id++;
			if(r->has_declarative) {
				output("{\n");
				output("static\tint ctl;\n");
				output("\tctl = 0;\n");
				output("\tgoto gen_%d;\n",generate_id);
				output("genbgn_%d:\n",generate_id);
				output("\tframe_ptr--;\n");
				output("gen_%d:\n",generate_id);
				if(r->id) {
					output ("\tframe_ptr++;\n");
					output ("\tframe_ptr->perform_through = 0;\n");
					output ("\tframe_ptr->return_address_ptr = &&rwg_%d;\n",generate_id);
					output ("\tgoto %s%d;\n","rwmove_",r->id);
					output("rwg_%d:\n",generate_id);
					output("\tframe_ptr--;\n");
				}
				output("\tctl = cob_report_generate (");
				output_param (p->argv[0], 0);
				output(", ");
				output_param (p->argv[1], 1);
				output(", ctl);\n");
				output("\tswitch(ctl) {\n");
				cb_emit_decl_case(r,r->records);
				output("\t}\n");
				output("}");
			} else {
				if(r->id) {
					output ("\tframe_ptr++;\n");
					output ("\tframe_ptr->perform_through = 0;\n");
					output ("\tframe_ptr->return_address_ptr = &&rwg_%d;\n",generate_id);
					output ("\tgoto %s%d;\n","rwmove_",r->id);
					output("rwg_%d:\n",generate_id);
					output("\tframe_ptr--;\n\t");
				}
				output ("cob_report_generate (");
				output_param (p->argv[0], 0);
				output(", ");
				output_param (p->argv[1], 1);
				output (", 0)");
			}
			break;
		case 'T':	/* Terminate REPORT */
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			generate_id++;
			if(r->has_declarative) {
				output("{\n");
				output("static\tint ctl;\n");
				output("\tctl = 0;\n");
				output("\tgoto gen_%d;\n",generate_id);
				output("genbgn_%d:\n",generate_id);
				output("\tframe_ptr--;\n");
				output("gen_%d:\n",generate_id);
				if(r->id) {
					output ("\tframe_ptr++;\n");
					output ("\tframe_ptr->perform_through = 0;\n");
					output ("\tframe_ptr->return_address_ptr = &&rwt_%d;\n",generate_id);
					output ("\tgoto %s%d;\n","rwfoot_",r->id);
					output("rwt_%d:\n",generate_id);
					output("\tframe_ptr--;\n");
				}
				output("\tctl = cob_report_terminate (");
				output_param (p->argv[0], 0);
				output(", ctl);\n");
				output("\tswitch(ctl) {\n");
				cb_emit_decl_case(r,r->records);
				output("\t}\n");
				output("}");
			} else {
				if(r->id) {
					output ("\tframe_ptr++;\n");
					output ("\tframe_ptr->return_address_ptr = &&rwt_%d;\n",generate_id);
					output ("\tgoto %s%d;\n","rwfoot_",r->id);
					output("rwt_%d:\n",generate_id);
					output("\tframe_ptr--;\n\t");
				}
				output ("cob_report_terminate (");
				output_param (p->argv[0], 0);
				output (", 0)");
			}
			break;
		case 'M':	/* Move data for REPORT */
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			output("\tgoto rwexit_%d;\n",r->id);
			output("rwmove_%d: ",r->id);
			break;
		case 't':	/* Label for MOVE for just Footings */
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			output("rwfoot_%d: ",r->id);
			break;
		case 'm':	/* End of Move data for REPORT */
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			output("\tgoto *frame_ptr->return_address_ptr;\n");
			output("rwexit_%d: ",r->id);
			break;
		case 'I':	/* Initiate REPORT */
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			if(r->t_lines) {
				output (" /* Page Limit is %s */\n",cb_name (r->t_lines));
				output ("%s%s.def_lines = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_lines);
				output (";\n");
			}
			if(r->t_columns) {
				output (" /* Page Limit is %s */\n",cb_name (r->t_columns));
				output ("%s%s.def_cols = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_columns);
				output (";\n");
			}
			if(r->t_heading) {
				output (" /* Heading is %s */\n",cb_name (r->t_heading));
				output ("%s%s.def_heading = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_heading);
				output (";\n");
			}
			if(r->t_footing) {
				output (" /* Footing is %s */\n",cb_name (r->t_footing));
				output ("%s%s.def_footing = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_footing);
				output (";\n");
			}
			if(r->t_first_detail) {
				output (" /* First Detail is %s */\n",cb_name (r->t_first_detail));
				output ("%s%s.def_first_detail = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_first_detail);
				output (";\n");
			}
			if(r->t_last_detail) {
				output (" /* Last Detail is %s */\n",cb_name (r->t_last_detail));
				output ("%s%s.def_last_detail = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_last_detail);
				output (";\n");
			}
			if(r->t_last_control) {
				output (" /* Last Control is %s */\n",cb_name (r->t_last_control));
				output ("%s%s.def_last_control = ", CB_PREFIX_REPORT, r->cname);
				output_integer(r->t_last_control);
				output (";\n");
			}
			output ("cob_report_initiate (");
			output_param (p->argv[0], 0);
			output (")");
			break;
		case 'S':	/* Suppress flag on */
			output ("%s",CB_PREFIX_REPORT_LINE);
			output_param (p->argv[1], 0);
			output (".suppress = 1;\n");
			r = CB_REPORT(CB_VALUE(p->argv[0]));
			output("cob_report_suppress (");
			output_param (p->argv[0], 0);
			output(", ");
			output ("&%s",CB_PREFIX_REPORT_LINE);
			output_param (p->argv[1], 0);
			output(");");
			break;
		default:
			cobc_abort_pr (_("Unexpected function %s"), p->name);
			COBC_ABORT ();
		}
		return;
	}
	screenptr = p->screenptr;
	output ("%s (", p->name);
	for (i = 0; i < p->argc; i++) {
		if (p->varcnt && i + 1 == p->argc) {
			output ("%d, ", p->varcnt);
			for (l = p->argv[i]; l; l = CB_CHAIN (l)) {
				if (CB_VALUE (l) && CB_LITERAL_P (CB_VALUE (l))) {
					nolitcast = p->nolitcast;
				}
				output_param (CB_VALUE (l), i);
				nolitcast = 0;
				i++;
				if (CB_CHAIN (l)) {
					output (", ");
				}
			}
		} else {
			if (p->argv[i] && CB_LITERAL_P (p->argv[i])) {
				nolitcast = p->nolitcast;
			}
			output_param (p->argv[i], i);
			nolitcast = 0;
			if (i + 1 < p->argc) {
				output (", ");
			}
		}
	}
	output (")");
	nolitcast = 0;
	screenptr = 0;
}

static void
output_func_1 (const char *name, cb_tree x)
{
	output ("%s (", name);
	output_param (x, param_id);
	output (")");
}

/* Condition */

static void
output_cond (cb_tree x, const int save_flag)
{
	struct cb_binary_op	*p;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CONST:
		if (x == cb_true) {
			output ("1");
		} else if (x == cb_false) {
			output ("0");
		} else {
			cobc_abort_pr (_("Unexpected constant"));
			COBC_ABORT ();
		}
		break;
	case CB_TAG_BINARY_OP:
		p = CB_BINARY_OP (x);
		switch (p->op) {
		case '!':
			output ("!");
			output_cond (p->x, save_flag);
			break;

		case '&':
		case '|':
			output ("(");
			output_cond (p->x, save_flag);
			output (p->op == '&' ? " && " : " || ");
			output_newline ();
			output_prefix ();
			output ("    ");
			output_cond (p->y, save_flag);
			output (")");
			break;

		case '=':
		case '<':
		case '[':
		case '>':
		case ']':
		case '~':
			output ("((int)");
			output_cond (p->x, save_flag);
			switch (p->op) {
			case '=':
				output (" == 0");
				break;
			case '<':
				output (" < 0");
				break;
			case '[':
				output (" <= 0");
				break;
			case '>':
				output (" > 0");
				break;
			case ']':
				output (" >= 0");
				break;
			case '~':
				output (" != 0");
				break;
			default:
				/* FIXME - Check */
				break;
			}
			output (")");
			break;

		default:
			output_integer (x);
			break;
		}
		break;
	case CB_TAG_FUNCALL:
		if (save_flag) {
			output ("(ret = ");
		}
		output_funcall (x);
		if (save_flag) {
			output (")");
		}
		break;
	case CB_TAG_LIST:
		if (save_flag) {
			output ("(ret = ");
		}
		inside_stack[inside_check++] = 0;
		if (inside_check >= COB_INSIDE_SIZE) {
			cobc_abort_pr (_("Internal statement stack depth exceeded -> %d"),
					COB_INSIDE_SIZE);
			COBC_ABORT ();
		}
		output ("(\n");
		for (; x; x = CB_CHAIN (x)) {
			output_stmt (CB_VALUE (x));
		}
		if (inside_check) {
			--inside_check;
		}
		output (")");
		if (save_flag) {
			output (")");
		}
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

/* MOVE */

static void
output_move (cb_tree src, cb_tree dst)
{
	cb_tree		x;

	/* Suppress warnings */
	suppress_warn = 1;
	x = cb_build_move (src, dst);
	if (x != cb_error_node) {
		output_stmt (x);
	}
	suppress_warn = 0;
}

/* INITIALIZE */

static int
initialize_type (struct cb_initialize *p, struct cb_field *f, const int topfield)
{
	cb_tree		l;
	int		type;

	if (f->flag_item_78) {
		cobc_abort_pr (_("Unexpected CONSTANT item"));
		COBC_ABORT ();
	}

	if (f->flag_chained) {
		return INITIALIZE_ONE;
	}

	if (f->flag_external && !p->flag_init_statement) {
		return INITIALIZE_NONE;
	}

	if (f->redefines && (!topfield || !p->flag_init_statement)) {
		return INITIALIZE_NONE;
	}

	if (f->flag_filler && p->flag_no_filler_init && !f->children) {
		return INITIALIZE_NONE;
	}

	if (p->val && f->values) {
		return INITIALIZE_ONE;
	}

	if (f->children) {
		type = initialize_type (p, f->children, 0);
		if (type == INITIALIZE_ONE) {
			return INITIALIZE_COMPOUND;
		}
		for (f = f->children->sister; f; f = f->sister) {
			if (type != initialize_type (p, f, 0)) {
				return INITIALIZE_COMPOUND;
			}
		}
		return type;
	} else {
		for (l = p->rep; l; l = CB_CHAIN (l)) {
			if ((int)CB_PURPOSE_INT (l) == (int)CB_TREE_CATEGORY (f)) {
				return INITIALIZE_ONE;
			}
		}
	}

	if (p->flag_default) {
		if (cb_default_byte >= 0 && !p->flag_init_statement) {
			return INITIALIZE_DEFAULT;
		}
		switch (f->usage) {
		case CB_USAGE_FLOAT:
		case CB_USAGE_DOUBLE:
		case CB_USAGE_LONG_DOUBLE:
		case CB_USAGE_FP_BIN32:
		case CB_USAGE_FP_BIN64:
		case CB_USAGE_FP_BIN128:
		case CB_USAGE_FP_DEC64:
		case CB_USAGE_FP_DEC128:
			return INITIALIZE_ONE;
		default:
			break;
		}
		switch (CB_TREE_CATEGORY (f)) {
		case CB_CATEGORY_NUMERIC_EDITED:
		case CB_CATEGORY_ALPHANUMERIC_EDITED:
		case CB_CATEGORY_NATIONAL_EDITED:
			return INITIALIZE_ONE;
		default:
			if (cb_tree_type (CB_TREE (f), f) == COB_TYPE_NUMERIC_PACKED) {
				return INITIALIZE_ONE;
			} else {
				return INITIALIZE_DEFAULT;
			}
		}
	}

	return INITIALIZE_NONE;
}

static int
initialize_uniform_char (const struct cb_field *f,
			 const struct cb_initialize *p)
{
	int	c;

	if (f->children) {
		c = initialize_uniform_char (f->children, p);
		for (f = f->children->sister; f; f = f->sister) {
			if (!f->redefines) {
				if (c != initialize_uniform_char (f, p)) {
					return -1;
				}
			}
		}
		return c;
	} else {
		if (cb_default_byte >= 0 && !p->flag_init_statement) {
			return cb_default_byte;
		}
		switch (cb_tree_type (CB_TREE (f), f)) {
		case COB_TYPE_NUMERIC_BINARY:
			return 0;
		case COB_TYPE_NUMERIC_DISPLAY:
			return '0';
		case COB_TYPE_ALPHANUMERIC:
			return ' ';
		default:
			return -1;
		}
	}
}

static void
output_figurative (cb_tree x, const struct cb_field *f, const int value,
		   const int init_occurs)
{
	output_prefix ();
	/* Check for non-standard 01 OCCURS */
	if (init_occurs) {
		output ("memset (");
		output_data (x);
		output (", %d, %d);\n", value, f->occurs_max);
	} else if (f->size == 1) {
		output ("*(cob_u8_ptr)(");
		output_data (x);
		output (") = %d;\n", value);
	} else {
		output ("memset (");
		output_data (x);
		if (CB_REFERENCE_P(x) && CB_REFERENCE(x)->length) {
			output (", %d, ", value);
			output_size (x);
			output (");\n");
		} else {
			output (", %d, %d);\n", value, f->size);
		}
	}
}

static void
output_initialize_literal (cb_tree x, struct cb_field *f,
			   struct cb_literal *l, const int init_occurs)
{
	int	i;
	int	n;
	int	size;
	int	lsize;

	/* Check for non-standard 01 OCCURS */
	if (init_occurs) {
		size = f->occurs_max;
		lsize = (int)l->size;
		/* Check truncated literal */
		if (lsize > f->size) {
			lsize = f->size;
		}
	} else {
		size = f->size;
		lsize = (int)l->size;
	}
	if (lsize == 1) {
		output_prefix ();
		output ("memset (");
		output_data (x);
		if (CB_REFERENCE_P(x) && CB_REFERENCE(x)->length) {
			output (", %d, ", l->data[0]);
			output_size (x);
			output (");\n");
		} else {
			output (", %d, %d);\n", l->data[0], size);
		}
		return;
	}
	if (lsize >= size) {
		output_prefix ();
		output ("memcpy (");
		output_data (x);
		output (", ");
		output_string (l->data, size, l->llit);
		output (", %d);\n", size);
		return;
	}
	i = size / lsize;
	i_counters[0] = 1;
	output_line ("for (i0 = 0; i0 < %d; i0++)", i);
	output_indent ("{");
	output_prefix ();
	output ("memcpy (");
	output_data (x);
	output (" + (i0 * %d), ", lsize);
	output_string (l->data, lsize, l->llit);
	output (", %d);\n", lsize);
	output_indent ("}");
	n = size % lsize;
	if (n) {
		output_prefix ();
		output ("memcpy (");
		output_data (x);
		output (" + (i0 * %d), ", lsize);
		output_string (l->data, n, l->llit);
		output (", %d);\n", n);
	}
}

static void
output_initialize_fp_bindec (cb_tree x, struct cb_field *f)
{
	output_prefix ();
	output ("memset (");
	output_data (x);
	output (", 0, %d);\n", (int)f->size);
}

static void
output_initialize_fp (cb_tree x, struct cb_field *f)
{
	output_prefix ();
	if (f->usage == CB_USAGE_FLOAT) {
		output ("{float temp = 0.0;");
	} else {
		output ("{double temp = 0.0;");
	}
	output (" memcpy (");
	output_data (x);
	output (", (void *)&temp, sizeof(temp));}\n");
}

static void
output_initialize_uniform (cb_tree x, const int c, const int size)
{
	output_prefix ();
	if (size == 1) {
		output ("*(cob_u8_ptr)(");
		output_data (x);
		output (") = %d;\n", c);
	} else {
		output ("memset (");
		output_data (x);
		if (CB_REFERENCE_P(x) && CB_REFERENCE(x)->length) {
			output (", %d, ", c);
			output_size (x);
			output (");\n");
		} else {
			output (", %d, %d);\n", c, size);
		}
	}
}

static void
output_initialize_one (struct cb_initialize *p, cb_tree x)
{
	struct cb_field		*f;
	cb_tree			value;
	cb_tree			lrp;
	struct cb_literal	*l;
	size_t			lsize;
	cob_u32_t		inci;
	int			i;
	int			n;
	int			size;
	int			offset;
	int			init_occurs;
	unsigned char		buffchar;

	f = cb_code_field (x);

	/* CHAINING */
	if (f->flag_chained) {
		output_prefix ();
		output ("cob_chain_setup (");
		output_data (x);
		output (", %d, %d);\n", f->param_num, f->size);
		return;
	}
	/* Initialize by value */
	if (p->val && f->values) {
		value = CB_VALUE (f->values);
		/* Check for non-standard OCCURS */
		if ((f->level == 1 || f->level == 77) &&
		    f->flag_occurs && !p->flag_init_statement) {
			init_occurs = 1;
		} else {
			init_occurs = 0;
		}
		if (value == cb_space) {
			output_figurative (x, f, ' ', init_occurs);
			return;
		} else if (value == cb_low) {
			output_figurative (x, f, 0, init_occurs);
			return;
		} else if (value == cb_high) {
			output_figurative (x, f, 255, init_occurs);
			return;
		} else if (value == cb_quote) {
			if (cb_flag_apostrophe) {
				output_figurative (x, f, '\'', init_occurs);
			} else {
				output_figurative (x, f, '"', init_occurs);
			}
			return;
		} else if (value == cb_zero && f->usage == CB_USAGE_DISPLAY) {
			if (!f->flag_sign_separate && !f->flag_blank_zero) {
				output_figurative (x, f, '0', init_occurs);
			} else {
				output_move (cb_zero, x);
			}
			return;
		} else if (value == cb_null && f->usage == CB_USAGE_DISPLAY) {
			output_figurative (x, f, 0, init_occurs);
			return;
		} else if (CB_LITERAL_P (value) && CB_LITERAL (value)->all) {
			/* ALL literal */
			output_initialize_literal (x, f,
						   CB_LITERAL (value), init_occurs);
			return;
		} else if (CB_CONST_P (value) ||
			   CB_TREE_CLASS (value) == CB_CLASS_NUMERIC) {
			/* Figurative literal, numeric literal */
			/* Check for non-standard 01 OCCURS */
			if (init_occurs) {
				i_counters[0] = 1;
				output_line ("for (i0 = 1; i0 <= %d; i0++)",
					     f->occurs_max);
				output_indent ("{");
				CB_REFERENCE (x)->subs =
					CB_BUILD_CHAIN (cb_i[0], CB_REFERENCE (x)->subs);
				output_move (value, x);
				CB_REFERENCE (x)->subs =
					CB_CHAIN (CB_REFERENCE (x)->subs);
				output_indent ("}");
			} else {
				output_move (value, x);
			}
			return;
		}
		/* Alphanumeric literal */
		/* We do not use output_move here because
		   we do not want to have the value be edited. */

		l = CB_LITERAL (value);

		/* Check for non-standard 01 OCCURS */
		if (init_occurs) {
			output_initialize_literal (x, f, l, 1);
			return;
		}

		size = f->size;

		if (size == 1) {
			output_prefix ();
			output ("*(cob_u8_ptr)(");
			output_data (x);
			output (") = %u;\n", l->data[0]);
			return;
		}

		buffchar = l->data[0];
		for (lsize = 0; lsize < l->size; lsize++) {
			if (l->data[lsize] != buffchar) {
				break;
			}
		}
		if (lsize == l->size) {
			output_prefix ();
			output ("memset (");
			output_data (x);
			output (", %u, %d);\n", (unsigned int)buffchar,
				(int)lsize);
			if ((int)l->size < (int)size) {
				output_prefix ();
				output ("memset (");
				output_data (x);
				output (" + %d, ' ', %d);\n",
					(int)lsize, (int)(size - lsize));
			}
			return;
		}

		if (size > litsize) {
			litsize = size + 128;
			if (litbuff) {
				litbuff = cobc_main_realloc (litbuff, (size_t)litsize);
			} else {
				litbuff = cobc_main_malloc ((size_t)litsize);
			}
		}

		if ((int)l->size >= (int)size) {
			memcpy (litbuff, l->data, (size_t)size);
		} else {
			memcpy (litbuff, l->data, (size_t)l->size);
			memset (litbuff + l->size, ' ', (size_t)(size - l->size));
		}

		buffchar = *(litbuff + size - 1);
		n = 0;
		for (i = size - 1; i >= 0; i--, n++) {
			if (*(litbuff + i) != buffchar) {
				break;
			}
		}
		if (i < 0) {
			output_prefix ();
			output ("memset (");
			output_data (x);
			output (", %u, %d);\n", (unsigned int)buffchar, size);
			return;
		}

		if (n > 2) {
			offset = size - n;
			size -= n;
		} else {
			offset = 0;
		}

		inci = 0;
		for (; size > 509; size -= 509, inci += 509) {
			output_prefix ();
			output ("memcpy (");
			output_data (x);
			if (!inci) {
				output (", ");
			} else {
				output (" + %u, ", inci);
			}
			output_string (litbuff + inci, 509, l->llit);
			output (", 509);\n");
		}

		output_prefix ();
		output ("memcpy (");
		output_data (x);
		if (!inci) {
			output (", ");
		} else {
			output (" + %u, ", inci);
		}
		output_string (litbuff + inci, size, l->llit);
		output (", %d);\n", size);

		if (offset) {
			output_prefix ();
			output ("memset (");
			output_data (x);
			output (" + %d, %u, %d);\n",
				offset, (unsigned int)buffchar, n);
		}
		return;
	}

	/* Initialize replacing */
	if (!f->children) {
		for (lrp = p->rep; lrp; lrp = CB_CHAIN (lrp)) {
			if ((int)CB_PURPOSE_INT (lrp) == (int)CB_TREE_CATEGORY (x)) {
				output_move (CB_VALUE (lrp), x);
				return;
			}
		}
	}

	/* Initialize by default */
	if (p->flag_default) {
		switch (f->usage) {
		case CB_USAGE_FLOAT:
		case CB_USAGE_DOUBLE:
		case CB_USAGE_LONG_DOUBLE:
			output_initialize_fp (x, f);
			return;
		case CB_USAGE_FP_BIN32:
		case CB_USAGE_FP_BIN64:
		case CB_USAGE_FP_BIN128:
		case CB_USAGE_FP_DEC64:
		case CB_USAGE_FP_DEC128:
			output_initialize_fp_bindec (x, f);
			return;
		default:
			break;
		}
		switch (CB_TREE_CATEGORY (x)) {
		case CB_CATEGORY_NUMERIC:
		case CB_CATEGORY_NUMERIC_EDITED:
			output_move (cb_zero, x);
			break;
		case CB_CATEGORY_ALPHANUMERIC_EDITED:
		case CB_CATEGORY_NATIONAL:
		case CB_CATEGORY_NATIONAL_EDITED:
			output_move (cb_space, x);
			break;
		default:
			cobc_abort_pr (_("Unexpected tree category %d"),
				 (int)CB_TREE_CATEGORY (x));
			COBC_ABORT ();
		}
	}
}

static void
output_initialize_compound (struct cb_initialize *p, cb_tree x)
{
	struct cb_field	*ff;
	struct cb_field	*f;
	struct cb_field	*last_field;
	cb_tree		c;
	size_t		size;
	int		type;
	int		last_char;
	int		i;

	ff = cb_code_field (x);
	for (f = ff->children; f; f = f->sister) {
		type = initialize_type (p, f, 0);
		c = cb_build_field_reference (f, x);

		switch (type) {
		case INITIALIZE_NONE:
			break;
		case INITIALIZE_DEFAULT:
			last_field = f;
			last_char = initialize_uniform_char (f, p);

			if (last_char != -1) {
				if (f->flag_occurs) {
					CB_REFERENCE (c)->subs =
					    CB_BUILD_CHAIN (cb_int1,
						      CB_REFERENCE (c)->subs);
				}

				for (; f->sister; f = f->sister) {
					if (!f->sister->redefines) {
						if (initialize_type (p, f->sister, 0) != INITIALIZE_DEFAULT ||
						    initialize_uniform_char (f->sister, p) != last_char) {
							break;
						}
					}
				}

				if (f->sister) {
					size = f->sister->offset - last_field->offset;
				} else {
					size = ff->offset + ff->size - last_field->offset;
				}

				output_initialize_uniform (c, last_char, (int) size);
				break;
			}
			/* Fall through */
		default:
			if (f->flag_occurs) {
				/* Begin occurs loop */
				i = f->indexes;
				i_counters[i] = 1;
				output_line ("for (i%d = 1; i%d <= %d; i%d++)",
					     i, i, f->occurs_max, i);
				output_indent ("{");
				CB_REFERENCE (c)->subs =
				    CB_BUILD_CHAIN (cb_i[i], CB_REFERENCE (c)->subs);
			}

			if (type == INITIALIZE_ONE) {
				output_initialize_one (p, c);
			} else {
				output_initialize_compound (p, c);
			}

			if (f->flag_occurs) {
				/* Close loop */
				CB_REFERENCE (c)->subs = CB_CHAIN (CB_REFERENCE (c)->subs);
				output_indent ("}");
			}
		}
	}
}

static void
output_initialize (struct cb_initialize *p)
{
	struct cb_field		*f;
	cb_tree			x;
	int			c;
	int			type;

	f = cb_code_field (p->var);
	type = initialize_type (p, f, 1);
	/* Check for non-standard OCCURS */
	if ((f->level == 1 || f->level == 77) &&
	    f->flag_occurs && !p->flag_init_statement) {
		switch (type) {
		case INITIALIZE_NONE:
			return;
		case INITIALIZE_ONE:
			output_initialize_one (p, p->var);
			return;
		case INITIALIZE_DEFAULT:
			c = initialize_uniform_char (f, p);
			if (c != -1) {
				output_initialize_uniform (p->var, c, f->occurs_max);
				return;
			}
			/* Fall through */
		case INITIALIZE_COMPOUND:
			i_counters[0] = 1;
			output_line ("for (i0 = 1; i0 <= %d; i0++)", f->occurs_max);
			output_indent ("{");
			x = cb_build_field_reference (f, NULL);
			CB_REFERENCE (x)->subs =
				CB_BUILD_CHAIN (cb_i[0], CB_REFERENCE (x)->subs);
			output_initialize_compound (p, x);
			CB_REFERENCE (x)->subs =
				CB_CHAIN (CB_REFERENCE (x)->subs);
			output_indent ("}");
			return;
		default:
			break;
		}
	}
	switch (type) {
	case INITIALIZE_NONE:
		return;
	case INITIALIZE_ONE:
		output_initialize_one (p, p->var);
		return;
	case INITIALIZE_DEFAULT:
		c = initialize_uniform_char (f, p);
		if (c != -1) {
			output_initialize_uniform (p->var, c, f->size);
			return;
		}
		/* Fall through */
	case INITIALIZE_COMPOUND:
		output_initialize_compound (p, p->var);
		return;
	default:
		break;
	}
}

/* SEARCH */

static void
output_occurs (struct cb_field *p)
{
	if (p->depending) {
		output_integer (p->depending);
	} else {
		output ("%d", p->occurs_max);
	}
}

static void
output_search_whens (cb_tree table, cb_tree var, cb_tree stmt, cb_tree whens)
{
	cb_tree		l;
	struct cb_field *p;
	cb_tree		idx;

	idx = NULL;
	p = cb_code_field (table);
	/* Determine the index to use */
	if (var) {
		for (l = p->index_list; l; l = CB_CHAIN (l)) {
			if (cb_ref (CB_VALUE (l)) == cb_ref (var)) {
				idx = var;
			}
		}
	}
	if (!idx) {
		idx = CB_VALUE (p->index_list);
	}

	/* Start loop */
	output_line ("for (;;) {");
	output_indent_level += 2;

	/* End test */
	output_prefix ();
	output ("if (");
	output_integer (idx);
	output (" > ");
	output_occurs (p);
	output (")\n");
	output_indent ("{");
	output_line ("/* Table end */");
	if (stmt) {
		output_stmt (stmt);
	} else {
		output_line ("break;");
	}
	output_indent ("}");

	/* WHEN test */
	output_stmt (whens);

	/* Iteration */
	output_newline ();
	output_prefix ();
	output_integer (idx);
	output ("++;\n");
	if (var && var != idx) {
		output_move (idx, var);
	}
	output_line ("/* Iterate */");
	/* End loop */
	output_indent_level -= 2;
	output_line ("}");
}

static void
output_search_all (cb_tree table, cb_tree stmt, cb_tree cond, cb_tree when)
{
	struct cb_field *p;
	cb_tree		idx;

	p = cb_code_field (table);
	idx = CB_VALUE (p->index_list);
	/* Header */
	output_indent ("{");
	output_line ("int ret;");
	output_line ("int head = %d - 1;", p->occurs_min);
	output_prefix ();
	output ("int tail = ");
	output_occurs (p);
	output (" + 1;\n");

	/* Start loop */
	output_line ("for (;;)");
	output_indent ("{");

	/* End test */
	output_line ("if (head >= tail - 1)");
	output_indent ("{");
	output_line ("/* Table end */");
	if (stmt) {
		output_stmt (stmt);
	} else {
		output_line ("break;");
	}
	output_indent ("}");

	/* Next index */
	output_prefix ();
	output_integer (idx);
	output (" = (head + tail) / 2;\n");
	output_newline ();

	/* WHEN test */
	output_line ("/* WHEN */");
	output_prefix ();
	output ("if (");
	output_cond (cond, 1);
	output (")\n");
	output_indent ("{");
	output_stmt (when);
	output_indent ("}");

	output_line ("if (ret < 0)");
	output_prefix ();
	output ("  head = ");
	output_integer (idx);
	output (";\n");
	output_line ("else");
	output_prefix ();
	output ("  tail = ");
	output_integer (idx);
	output (";\n");
	output_indent ("}");
	output_indent ("}");
}

static void
output_search (struct cb_search *p)
{
	if (p->flag_all) {
		output_search_all (p->table, p->end_stmt,
				   CB_IF (p->whens)->test, CB_IF (p->whens)->stmt1);
	} else {
		output_search_whens (p->table, p->var, p->end_stmt, p->whens);
	}
}

/* CALL */

static void
output_call_by_value_args (cb_tree x, cb_tree l)
{
	struct cb_field	*f;
	const char	*s;
	cob_s64_t	val;
	cob_u64_t	uval;
	int		sizes;
	int		sign;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_CAST:
		output_integer (x);
		return;
	case CB_TAG_INTRINSIC:
		if (CB_INTRINSIC(x)->intr_tab->category == CB_CATEGORY_NUMERIC) {
			output ("cob_get_int (");
			output_param (x, -1);
			output (")");
		} else {
			output_data (x);
		}
		return;
	case CB_TAG_LITERAL:
		if (CB_TREE_CLASS (x) != CB_CLASS_NUMERIC) {
			output ("%d", CB_LITERAL (x)->data[0]);
			return;
		}
		if (CB_SIZES_INT_UNSIGNED(l)) {
			uval = cb_get_u_long_long (x);
			switch (CB_SIZES_INT (l)) {
			case CB_SIZE_AUTO:
				if (uval > UINT_MAX) {
					output ("(cob_u64_t)");
					output (CB_FMT_LLU_F, uval);
					return;
				}
				/* Fall through to case 4 */
			case CB_SIZE_4:
				output ("(cob_u32_t)");
				output (CB_FMT_LLU_F, uval);
				return;
			case CB_SIZE_1:
				output ("(cob_u8_t)");
				output (CB_FMT_LLU_F, uval);
				return;
			case CB_SIZE_2:
				output ("(cob_u16_t)");
				output (CB_FMT_LLU_F, uval);
				return;
			case CB_SIZE_8:
				output ("(cob_u64_t)");
				output (CB_FMT_LLU_F, uval);
				return;
			default:
				cobc_abort_pr (_("Unexpected size"));
				COBC_ABORT ();
			}
		}
		val = cb_get_long_long (x);
		switch (CB_SIZES_INT (l)) {
		case CB_SIZE_AUTO:
			if (val > INT_MAX) {
				output ("(cob_s64_t)");
				output (CB_FMT_LLD_F, val);
				return;
			}
			/* Fall through to case 4 */
		case CB_SIZE_4:
			output ("(cob_s32_t)");
			output (CB_FMT_LLD_F, val);
			return;
		case CB_SIZE_1:
			output ("(cob_s8_t)");
			output (CB_FMT_LLD_F, val);
			return;
		case CB_SIZE_2:
			output ("(cob_s16_t)");
			output (CB_FMT_LLD_F, val);
			return;
		case CB_SIZE_8:
			output ("(cob_s64_t)");
			output (CB_FMT_LLD_F, val);
			return;
		default:
			cobc_abort_pr (_("Unexpected size"));
			COBC_ABORT ();
		}
		return;
	default:
		f = cb_code_field (x);
		switch (f->usage) {
		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
		case CB_USAGE_PACKED:
		case CB_USAGE_DISPLAY:
		case CB_USAGE_COMP_6:
			sizes = CB_SIZES_INT (l);
			sign = 0;
			if (sizes == CB_SIZE_AUTO) {
				if (f->pic->have_sign) {
					sign = 1;
				}
				if (f->usage == CB_USAGE_PACKED ||
				    f->usage == CB_USAGE_DISPLAY ||
				    f->usage == CB_USAGE_COMP_6) {
					sizes = f->pic->digits - f->pic->scale;
				} else {
					sizes = f->size;
				}
				switch (sizes) {
				case 0:
					sizes = CB_SIZE_4;
					break;
				case 1:
					sizes = CB_SIZE_1;
					break;
				case 2:
					sizes = CB_SIZE_2;
					break;
				case 3:
					sizes = CB_SIZE_4;
					break;
				case 4:
					sizes = CB_SIZE_4;
					break;
				case 5:
					sizes = CB_SIZE_8;
					break;
				case 6:
					sizes = CB_SIZE_8;
					break;
				case 7:
					sizes = CB_SIZE_8;
					break;
				default:
					sizes = CB_SIZE_8;
					break;
				}
			} else {
				if (!CB_SIZES_INT_UNSIGNED(l)) {
					sign = 1;
				}
			}
			switch (sizes) {
			case CB_SIZE_1:
				if (sign) {
					s = "cob_c8_t";
				} else {
					s = "cob_u8_t";
				}
				break;
			case CB_SIZE_2:
				if (sign) {
					s = "cob_s16_t";
				} else {
					s = "cob_u16_t";
				}
				break;
			case CB_SIZE_4:
				if (sign) {
					s = "cob_s32_t";
				} else {
					s = "cob_u32_t";
				}
				break;
			case CB_SIZE_8:
				if (sign) {
					s = "cob_s64_t";
				} else {
					s = "cob_u64_t";
				}
				break;
			default:
				if (sign) {
					s = "cob_s32_t";
				} else {
					s = "cob_u32_t";
				}
				break;
			}
			output ("(%s)(", s);
			output_integer (x);
			output (")");
			return;
		case CB_USAGE_INDEX:
		case CB_USAGE_LENGTH:
		case CB_USAGE_POINTER:
		case CB_USAGE_PROGRAM_POINTER:
			output_integer (x);
			return;
		case CB_USAGE_FLOAT:
			output ("*(float *)(");
			output_data (x);
			output (")");
			return;
		case CB_USAGE_DOUBLE:
			output ("*(double *)(");
			output_data (x);
			output (")");
			return;
		case CB_USAGE_LONG_DOUBLE:
			output ("*(long double *)(");
			output_data (x);
			output (")");
			return;
		case CB_USAGE_FP_BIN32:
			output ("*(cob_u32_t *)(");
			output_data (x);
			output (")");
			return;
		case CB_USAGE_FP_BIN64:
		case CB_USAGE_FP_DEC64:
			output ("*(cob_u64_t *)(");
			output_data (x);
			output (")");
			return;
		case CB_USAGE_FP_BIN128:
		case CB_USAGE_FP_DEC128:
			output ("*(cob_fp_128 *)(");
			output_data (x);
			output (")");
			return;
		default:
			output ("*(");
			output_data (x);
			output (")");
			return;
		}
	}
}

static void
output_bin_field (const cb_tree x, const cob_u32_t id)
{
	int		i;
	cob_u32_t	size;
	cob_u32_t	aflags;
	cob_u32_t	digits;

	if (!CB_NUMERIC_LITERAL_P (x)) {
		return;
	}
	aflags = 0;
	if (cb_fits_int (x)) {
		size = 4;
		aflags = COB_FLAG_HAVE_SIGN;
	} else {
		size = 8;
		if (CB_LITERAL (x)->sign < 0) {
			aflags = COB_FLAG_HAVE_SIGN;
		}
	}
	if (size == 8) {
		digits = 18;
	} else {
		digits = 9;
	}
	aflags |= COB_FLAG_REAL_BINARY;
	i = lookup_attr (COB_TYPE_NUMERIC_BINARY, digits, 0, aflags, NULL, 0);
	output_line ("cob_field\tcontent_fb_%u = { %u, content_%u.data, &%s%d };",
		     id, size, id, CB_PREFIX_ATTR, i);
}

static void
output_call (struct cb_call *p)
{
	cb_tree				x;
	cb_tree				l;
	struct cb_literal		*lp;
	struct nested_list		*nlp;
	char				*callp;
	char				*system_call;
	const struct system_table	*psyst;
	const char			*convention;
	struct cb_text_list		*ctl;
	char				*s;
	cob_u32_t			n;
	size_t				retptr;
	size_t				gen_exit_program;
	size_t				dynamic_link;
	size_t				need_brace;
#if	0	/* RXWRXW - Clear params */
	cob_u32_t			parmnum;
#endif

	system_call = NULL;
	retptr = 0;
	gen_exit_program = 0;
	dynamic_link = 1;
	if (p->call_returning && p->call_returning != cb_null &&
	    CB_TREE_CLASS(p->call_returning) == CB_CLASS_POINTER) {
		retptr = 1;
	}

#ifdef	_WIN32
	if (p->convention & CB_CONV_STDCALL) {
		convention = "_std";
	} else {
		convention = "";
	}
#else
	convention = "";
#endif

	/* System routine entry points */
	if (p->is_system) {
#if	0	/* RXWRXW - system */
		lp = CB_LITERAL (p->name);
		for (psyst = system_tab; psyst->syst_name; psyst++) {
			if (!strcmp((const char *)lp->data,
			    (const char *)psyst->syst_name)) {
				system_call = (char *)psyst->syst_call;
				dynamic_link = 0;
				break;
			}
		}
#else
		n = p->is_system - 1U;
		psyst = &system_tab[n];
		system_call = (char *)psyst->syst_call;
		dynamic_link = 0;
#endif
	}

	if (dynamic_link && CB_LITERAL_P (p->name)) {
		if (cb_flag_static_call || (p->convention & CB_CONV_STATIC_LINK)) {
			dynamic_link = 0;
		}
		lp = CB_LITERAL (p->name);
		for (ctl = cb_static_call_list; ctl; ctl = ctl->next) {
			if (!strcmp((const char *)lp->data, ctl->text)) {
				dynamic_link = 0;
				break;
			}
		}
		for (ctl = cb_early_exit_list; ctl; ctl = ctl->next) {
			if (!strcmp((const char *)lp->data, ctl->text)) {
				gen_exit_program = 1;
				break;
			}
		}
	}
	need_brace = 0;

#ifdef	COB_NON_ALIGNED
	if (dynamic_link && retptr) {
		if (!need_brace) {
			need_brace = 1;
			output_indent ("{");
		}
		output_line ("void *temptr;");
	}
#endif

	if (CB_REFERENCE_P (p->name) &&
	    CB_FIELD_P (CB_REFERENCE (p->name)->value) &&
	    CB_FIELD (CB_REFERENCE (p->name)->value)->usage == CB_USAGE_PROGRAM_POINTER) {
		dynamic_link = 0;
	}

	/* Set up arguments */
	for (l = p->args, n = 1; l; l = CB_CHAIN (l), n++) {
		x = CB_VALUE (l);
		switch (CB_PURPOSE_INT (l)) {
		case CB_CALL_BY_REFERENCE:
			if (CB_NUMERIC_LITERAL_P (x) || CB_BINARY_OP_P (x)) {
				if (!need_brace) {
					need_brace = 1;
					output_indent ("{");
				}
				output_line ("cob_content\tcontent_%u;", n);
				output_bin_field (x, n);
			} else if (CB_CAST_P (x)) {
				if (!need_brace) {
					need_brace = 1;
					output_indent ("{");
				}
				output_line ("void *ptr_%u;", n);
			}
			break;
		case CB_CALL_BY_CONTENT:
			if (CB_CAST_P (x)) {
				if (!need_brace) {
					need_brace = 1;
					output_indent ("{");
				}
				output_line ("void *ptr_%u;", n);
			} else if (CB_TREE_TAG (x) != CB_TAG_INTRINSIC &&
			    x != cb_null && !(CB_CAST_P (x))) {
				if (!need_brace) {
					need_brace = 1;
					output_indent ("{");
				}
				output_line ("union {");
				output_prefix ();
				output ("\tunsigned char data[");
				if (CB_NUMERIC_LITERAL_P (x) ||
				    CB_BINARY_OP_P (x) || CB_CAST_P(x)) {
					output ("8");
				} else {
					if (CB_REF_OR_FIELD_P (x)) {
						output ("%u", (cob_u32_t)cb_code_field (x)->size);
					} else {
						output_size (x);
					}
				}
				output ("];\n");
				output_line ("\tcob_s64_t     datall;");
				output_line ("\tcob_u64_t     dataull;");
				output_line ("\tint           dataint;");
				output_line ("} content_%u;", n);
				output_bin_field (x, n);
			}
			break;
		default:
			break;
		}
	}

	if (need_brace) {
		output_newline ();
	}

	for (l = p->args, n = 1; l; l = CB_CHAIN (l), n++) {
		x = CB_VALUE (l);
		switch (CB_PURPOSE_INT (l)) {
		case CB_CALL_BY_REFERENCE:
			if (CB_NUMERIC_LITERAL_P (x)) {
				output_prefix ();
				if (cb_fits_int (x)) {
					output ("content_%u.dataint = ", n);
					output ("%d", cb_get_int (x));
				} else {
					if (CB_LITERAL (x)->sign >= 0) {
						output ("content_%u.dataull = ", n);
						output (CB_FMT_LLU_F,
							cb_get_u_long_long (x));
					} else {
						output ("content_%u.datall = ", n);
						output (CB_FMT_LLD_F,
							cb_get_long_long (x));
					}
				}
				output (";\n");
			} else if (CB_BINARY_OP_P (x)) {
				output_prefix ();
				output ("content_%u.dataint = ", n);
				output_integer (x);
				output (";\n");
			} else if (CB_CAST_P (x)) {
				output_prefix ();
				output ("ptr_%u = ", n);
				output_integer (x);
				output (";\n");
			}
			break;
		case CB_CALL_BY_CONTENT:
			if (CB_CAST_P (x)) {
				output_prefix ();
				output ("ptr_%u = ", n);
				output_integer (x);
				output (";\n");
			} else if (CB_TREE_TAG (x) != CB_TAG_INTRINSIC) {
				if (CB_NUMERIC_LITERAL_P (x)) {
					output_prefix ();
					if (cb_fits_int (x)) {
						output ("content_%u.dataint = ", n);
						output ("%d", cb_get_int (x));
					} else {
						if (CB_LITERAL (x)->sign >= 0) {
							output ("content_%u.dataull = ", n);
							output (CB_FMT_LLU_F,
								cb_get_u_long_long (x));
						} else {
							output ("content_%u.datall = ", n);
							output (CB_FMT_LLD_F,
								cb_get_long_long (x));
						}
					}
					output (";\n");
				} else if (CB_REF_OR_FIELD_P (x) &&
					   CB_TREE_CATEGORY (x) == CB_CATEGORY_NUMERIC &&
					   cb_code_field (x)->usage == CB_USAGE_LENGTH) {
					output_prefix ();
					output ("content_%u.dataint = ", n);
					output_integer (x);
					output (";\n");
				} else if (x != cb_null && !(CB_CAST_P (x))) {
					output_prefix ();
					output ("memcpy (content_%u.data, ", n);
					output_data (x);
					output (", ");
					output_size (x);
					output (");\n");
				}
			}
			break;
		default:
			break;
		}
	}

	/* Set up parameter types */
	n = 0;
	for (l = p->args; l; l = CB_CHAIN (l), n++) {
		x = CB_VALUE (l);
		field_iteration = n;
		output_prefix ();
		output ("cob_procedure_params[%u] = ", n);
		switch (CB_TREE_TAG (x)) {
		case CB_TAG_LITERAL:
			if (CB_NUMERIC_LITERAL_P (x) &&
			    CB_PURPOSE_INT (l) != CB_CALL_BY_VALUE) {
				output ("&content_fb_%u", n + 1);
				break;
			}
			/* Fall through */
		case CB_TAG_FIELD:
		case CB_TAG_INTRINSIC:
			output_param (x, -1);
			break;
		case CB_TAG_REFERENCE:
			switch (CB_TREE_TAG (CB_REFERENCE(x)->value)) {
			case CB_TAG_LITERAL:
			case CB_TAG_FIELD:
			case CB_TAG_INTRINSIC:
				output_param (x, -1);
				break;
			default:
				output ("NULL");
				break;
			}
			break;
		default:
			output ("NULL");
			break;
		}
		output (";\n");
	}

#if	0	/* RXWRXW - Clear params */
	/* Clear extra parameters */
	if (n > COB_MAX_FIELD_PARAMS - 4) {
		parmnum = COB_MAX_FIELD_PARAMS - n;
	} else {
		parmnum = 4;
	}
	parmnum *= sizeof(cob_field *);
	output_line ("memset (&(cob_procedure_params[%u]), 0, %u);",
		     n, parmnum);
#endif

	/* Set number of parameters */
	output_prefix ();
	output ("cob_glob_ptr->cob_call_params = %u;\n", n);

	/* Function name */
	output_prefix ();
	/* Special for program pointers */
	if (CB_REFERENCE_P (p->name) &&
	    CB_FIELD_P (CB_REFERENCE (p->name)->value) &&
	    CB_FIELD (CB_REFERENCE (p->name)->value)->usage ==
	    CB_USAGE_PROGRAM_POINTER) {
		needs_unifunc = 1;
		output ("cob_unifunc.funcvoid = ");
		output_integer (p->name);
		output (";\n");
		output_prefix ();
		if (p->call_returning == cb_null) {
			output ("cob_unifunc.funcnull");
		} else if (retptr) {
#ifdef	COB_NON_ALIGNED
			output ("temptr");
#else
			output_integer (p->call_returning);
#endif
			output (" = cob_unifunc.funcptr");
		} else {
			if (p->convention & CB_CONV_NO_RET_UPD) {
				output ("(void)cob_unifunc.funcint");
			} else {
				output_integer (current_prog->cb_return_code);
				output (" = cob_unifunc.funcint");
			}
		}
	} else if (!dynamic_link) {
		/* Static link */
		if (p->call_returning != cb_null) {
			if (retptr) {
#ifdef	COB_NON_ALIGNED
				output ("temptr");
#else
				output_integer (p->call_returning);
#endif
				output (" = (void *)");
			} else if (!(p->convention & CB_CONV_NO_RET_UPD)) {
				output_integer (current_prog->cb_return_code);
				output (" = ");
			} else {
				output ("(void)");
			}
		}
		if (system_call) {
			output ("%s", system_call);
		} else {
			callp = cb_encode_program_id ((char *)(CB_LITERAL (p->name)->data));
			/* Check contained progs */
			nlp = current_prog->nested_prog_list;
			for (; nlp; nlp = nlp->next) {
				if (!strcmp (callp, nlp->nested_prog->program_id)) {
					break;
				}
			}
			if (nlp) {
				output ("%s_%d__", callp,
					nlp->nested_prog->toplev_count);
			} else {
				output ("%s", callp);
			}
		}
	} else {
		/* Dynamic link */
		if (CB_LITERAL_P (p->name)) {
			s = (char *)(CB_LITERAL (p->name)->data);
			callp = cb_encode_program_id (s);
			lookup_call (callp);
			/* Check contained progs */
			nlp = current_prog->nested_prog_list;
			for (; nlp; nlp = nlp->next) {
				if (!strcmp (callp, nlp->nested_prog->program_id)) {
					break;
				}
			}
			output ("if (unlikely(call_%s.funcvoid == NULL)) {\n", callp);
			output_prefix ();
			if (nlp) {
				output ("  call_%s.funcint = %s_%d__;\n",
					callp, callp,
					nlp->nested_prog->toplev_count);
			} else {
				output ("  call_%s.funcvoid = ", callp);
				output ("cob_resolve_cobol (");
				output_string ((const unsigned char *)s,
						(int)strlen (s), 0);
				output (", %d, %d);\n", cb_fold_call, !p->stmt1);
			}
			output_prefix ();
			output ("}\n");
		} else {
			callp = NULL;
			needs_unifunc = 1;
			output ("cob_unifunc.funcvoid = cob_call_field (");
			output_param (p->name, -1);
			if (current_prog->nested_prog_list) {
				gen_nested_tab = 1;
				output (", cob_nest_tab, %d, %d);\n",
					!p->stmt1, cb_fold_call);
			} else {
				output (", NULL, %d, %d);\n",
					!p->stmt1, cb_fold_call);
			}
		}
		if (p->stmt1) {
			if (callp) {
				output_line ("if (unlikely(call_%s.funcvoid == NULL))", callp);
			} else {
				output_line ("if (unlikely(cob_unifunc.funcvoid == NULL))");
			}
			output_line ("{");
			output_indent_level += 2;
			output_stmt (p->stmt1);
			output_indent_level -= 2;
			output_line ("}");
			output_line ("else");
			output_indent ("{");
		}
		output_prefix ();
		if (p->call_returning == cb_null) {
			if (callp) {
				output ("call_%s.funcnull%s", callp, convention);
			} else {
				output ("cob_unifunc.funcnull%s", convention);
			}
		} else if (retptr) {
#ifdef	COB_NON_ALIGNED
			output ("temptr");
#else
			output_integer (p->call_returning);
#endif
			if (callp) {
				output (" = call_%s.funcptr%s", callp, convention);
			} else {
				output (" = cob_unifunc.funcptr%s", convention);
			}
		} else {
			if (!(p->convention & CB_CONV_NO_RET_UPD)) {
				output_integer (current_prog->cb_return_code);
				output (" = ");
			} else {
				output ("(void)");
			}
			if (callp) {
				output ("call_%s.funcint%s", callp, convention);
			} else {
				output ("cob_unifunc.funcint%s", convention);
			}
		}
	}

	/* Arguments */
	output (" (");
	for (l = p->args, n = 1; l; l = CB_CHAIN (l), n++) {
		x = CB_VALUE (l);
		field_iteration = n - 1U;
		switch (CB_PURPOSE_INT (l)) {
		case CB_CALL_BY_REFERENCE:
			if (CB_NUMERIC_LITERAL_P (x) || CB_BINARY_OP_P (x)) {
				output ("content_%u.data", n);
			} else if (CB_REFERENCE_P (x) && CB_FILE_P (cb_ref (x))) {
				output_param (cb_ref (x), -1);
			} else if (CB_CAST_P (x)) {
				output ("&ptr_%u", n);
			} else {
				output_data (x);
			}
			break;
		case CB_CALL_BY_CONTENT:
			if (CB_TREE_TAG (x) != CB_TAG_INTRINSIC && x != cb_null) {
				if (CB_CAST_P (x)) {
					output ("&ptr_%u", n);
				} else {
					output ("content_%u.data", n);
				}
			} else {
				output_data (x);
			}
			break;
		case CB_CALL_BY_VALUE:
			output_call_by_value_args (x, l);
			break;
		default:
			break;
		}
		if (CB_CHAIN (l)) {
			output (", ");
		}
	}

	output (");\n");

	if (p->call_returning) {
		if (p->call_returning == cb_null) {
			output_prefix ();
			output_integer (current_prog->cb_return_code);
			output (" = 0;\n");
		} else if (!retptr) {
			output_move (current_prog->cb_return_code,
				     p->call_returning);
#ifdef	COB_NON_ALIGNED
		} else {
			output_prefix ();
			output ("memcpy (");
			output_data (p->call_returning);
			output (", &temptr, %u);\n", (cob_u32_t)sizeof (void *));
#endif
		}
	}
	if (gen_exit_program) {
		needs_exit_prog = 1;
		output_line ("if (unlikely(module->flag_exit_program)) {");
		output_line ("\tmodule->flag_exit_program = 0;");
		output_line ("\tgoto exit_program;");
		output_line ("}");
	}
	if (p->stmt2) {
		output_stmt (p->stmt2);
	}

	if (dynamic_link && p->stmt1) {
		output_indent ("}");
	}

	if (need_brace) {
		output_indent ("}");
	}
}

/* SET ATTRIBUTE */

static void
output_set_attribute (const struct cb_field *f,
		      const int val_on, const int val_off)
{
	if (val_on) {
		output_line ("s_%d.attr |= 0x%x;", f->id, val_on);
	}
	if (val_off) {
		output_line ("s_%d.attr &= ~0x%x;", f->id, val_off);
	}
}

/* CANCEL */

static void
output_cancel (struct cb_cancel *p)
{
	struct nested_list	*nlp;
	char			*callp;
	char			*s;
	int			i;

	if (CB_LITERAL_P (p->target)) {
		s = (char *)(CB_LITERAL (p->target)->data);
		callp = cb_encode_program_id (s);
		nlp = current_prog->nested_prog_list;
		for (; nlp; nlp = nlp->next) {
			if (!strcmp (callp, nlp->nested_prog->program_id)) {
				break;
			}
		}
		if (nlp) {
			output_prefix ();
			output ("(void)%s_%d_ (-1", callp,
				nlp->nested_prog->toplev_count);
			for (i = 0; i < nlp->nested_prog->num_proc_params; ++i) {
				output (", NULL");
			}
			output (");\n");
		} else {
			output ("cob_cancel (");
			output_string ((const unsigned char *)s,
					(int)strlen (s), 0);
			output (");\n");
		}
		return;
	}
	output_prefix ();
	output ("cob_cancel_field (");
	output_param (p->target, -1);
	if (current_prog->nested_prog_list) {
		gen_nested_tab = 1;
		output (", cob_nest_tab");
	} else {
		output (", NULL");
	}
	output (");\n");
}

/* PERFORM */

static void
output_perform_call (struct cb_label *lb, struct cb_label *le)
{
	struct cb_para_label	*p;
	struct label_list	*l;

	if (lb == current_prog->all_procedure || lb->flag_is_debug_sect) {
		output_line ("/* DEBUGGING Callback PERFORM %s */",
			     (const char *)lb->name);
	} else if (lb == le) {
		output_line ("/* PERFORM %s */", (const char *)lb->name);
	} else {
		output_line ("/* PERFORM %s THRU %s */", (const char *)lb->name,
			     (const char *)le->name);
	}

	/* Save current independent segment pointers */
	if (current_prog->flag_segments && last_section &&
	    last_section->section_id != lb->section_id) {
		p = last_section->para_label;
		for (; p; p = p->next) {
			if (p->para->segment > 49 &&
			    p->para->flag_alter) {
				output_line ("save_label_%s%d = label_%s%d;",
					     CB_PREFIX_LABEL, p->para->id,
					     CB_PREFIX_LABEL, p->para->id);
			}
		}
	}
	/* Zap target independent labels */
	if (current_prog->flag_segments && last_segment != lb->segment) {
		if (lb->flag_section) {
			p = lb->para_label;
		} else if (lb->section) {
			p = lb->section->para_label;
		} else {
			p = NULL;
		}
		for (; p; p = p->next) {
			if (p->para->segment > 49 &&
			    p->para->flag_alter) {
				output_line ("label_%s%d = 0;",
					     CB_PREFIX_LABEL, p->para->id);
			}
		}
	}

	/* Update debugging name */
	if (current_prog->flag_gen_debug && lb->flag_real_label &&
	    (current_prog->all_procedure || lb->flag_debugging_mode)) {
		output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)lb->name, NULL));
	}

	output_line ("frame_ptr++;");
	if (cb_flag_stack_check) {
		output_line ("if (unlikely(frame_ptr == frame_overflow))");
		output_line ("    cob_fatal_error (COB_FERROR_STACK);");
	}
	output_line ("frame_ptr->perform_through = %d;", le->id);
	if (!cb_flag_computed_goto) {
		l = cobc_parse_malloc (sizeof (struct label_list));
		l->next = label_cache;
		l->id = cb_id;
		if (label_cache == NULL) {
			l->call_num = 0;
		} else {
			l->call_num = label_cache->call_num + 1;
		}
		label_cache = l;
		output_line ("frame_ptr->return_address_num = %d;", l->call_num);
		output_line ("goto %s%d;", CB_PREFIX_LABEL, lb->id);
		output_line ("%s%d:", CB_PREFIX_LABEL, cb_id);
	} else {
		output_line ("frame_ptr->return_address_ptr = &&%s%d;",
			     CB_PREFIX_LABEL, cb_id);
		output_line ("goto %s%d;", CB_PREFIX_LABEL, lb->id);
		output_line ("%s%d:", CB_PREFIX_LABEL, cb_id);
	}
	output_line ("frame_ptr--;");
	cb_id++;

	if (current_prog->flag_segments && last_section &&
	    last_section->section_id != lb->section_id) {
		/* Restore current independent segment pointers */
		p = last_section->para_label;
		for (; p; p = p->next) {
			if (p->para->segment > 49 &&
			    p->para->flag_alter) {
				output_line ("label_%s%d = save_label_%s%d;",
					     CB_PREFIX_LABEL, p->para->id,
					     CB_PREFIX_LABEL, p->para->id);
			}
		}
		/* Zap target independent labels */
		if (lb->flag_section) {
			p = lb->para_label;
		} else if (lb->section) {
			p = lb->section->para_label;
		} else {
			p = NULL;
		}
		for (; p; p = p->next) {
			if (p->para->segment > 49 &&
			    p->para->flag_alter) {
				output_line ("label_%s%d = 0;",
					     CB_PREFIX_LABEL, p->para->id);
			}
		}
	}
}

static void
output_perform_exit (struct cb_label *l)
{
	if (l->flag_global) {
		output_newline ();
		output_line ("/* Implicit GLOBAL DECLARATIVE return */");
		output_line ("if (entry == %d) {", l->id);
		output_line ("  cob_module_leave (module);");
		if (cb_flag_stack_on_heap || current_prog->flag_recursive) {
			output_line ("  free (frame_stack);");
			output_line ("  free (cob_procedure_params);");
			output_line ("  cob_cache_free (module);");
		}
		output_line ("  return 0;");
		output_line ("}");
	}
	output_newline ();

	if (l->flag_declarative_exit) {
		output_line ("/* Implicit DECLARATIVE return */");
	} else if (l->flag_default_handler) {
		output_line ("/* Implicit Default Error Handler return */");
	} else {
		output_line ("/* Implicit PERFORM return */");
	}

	if (cb_perform_osvs && current_prog->prog_type == CB_PROGRAM_TYPE) {
		output_line
		    ("for (temp_index = frame_ptr; temp_index->perform_through; temp_index--) {");
		output_line ("  if (temp_index->perform_through == %d) {", l->id);
		output_line ("    frame_ptr = temp_index;");
		if (!cb_flag_computed_goto) {
			output_line ("    goto P_switch;");
		} else {
			output_line ("    goto *frame_ptr->return_address_ptr;");
		}
		output_line ("  }");
		output_line ("}");
	} else {
		output_line ("if (frame_ptr->perform_through == %d)", l->id);
		if (!cb_flag_computed_goto) {
			output_line ("  goto P_switch;");
		} else {
			output_line ("  goto *frame_ptr->return_address_ptr;");
		}
	}

	if (l->flag_fatal_check) {
		output_newline ();
		output_line ("/* Fatal error if reached */");
		output_line ("cob_fatal_error (COB_FERROR_GLOBAL);");
	}
}

static void
output_funcall_debug (cb_tree x)
{
	struct cb_funcall	*p;
	cb_tree			l;
	cb_tree			z;
	int			i;

	p = CB_FUNCALL (x);
	if (p->name[0] == '$') {
		z = p->argv[0];
		if (CB_REF_OR_FIELD_P (z) &&
		    cb_code_field (z)->flag_field_debug) {
			/* DEBUG */
			output_stmt (cb_build_debug (cb_debug_name,
				     (const char *)cb_code_field (z)->name, NULL));
			output_stmt (cb_build_debug (cb_debug_contents,
						     NULL, z));
			output_perform_call (cb_code_field (z)->debug_section,
					     cb_code_field (z)->debug_section);
		}
		z = p->argv[1];
		if (CB_REF_OR_FIELD_P (z) &&
		    cb_code_field (z)->flag_field_debug) {
			/* DEBUG */
			output_stmt (cb_build_debug (cb_debug_name,
				     (const char *)cb_code_field (z)->name, NULL));
			output_stmt (cb_build_debug (cb_debug_contents,
						     NULL, z));
			output_perform_call (cb_code_field (z)->debug_section,
					     cb_code_field (z)->debug_section);
		}
		return;
	}
	for (i = 0; i < p->argc; i++) {
		if (p->varcnt && i + 1 == p->argc) {
			for (l = p->argv[i]; l; l = CB_CHAIN (l)) {
				output_param (CB_VALUE (l), i);
				z = CB_VALUE (l);
				if (CB_REF_OR_FIELD_P (z) &&
				    cb_code_field (z)->flag_field_debug) {
					/* DEBUG */
					output_stmt (cb_build_debug (cb_debug_name,
						     (const char *)cb_code_field (z)->name, NULL));
					output_stmt (cb_build_debug (cb_debug_contents,
								     NULL, z));
					output_perform_call (cb_code_field (z)->debug_section,
							     cb_code_field (z)->debug_section);
				}
				i++;
			}
		} else {
			z = p->argv[i];
			if (CB_REF_OR_FIELD_P (z) &&
			    cb_code_field (z)->flag_field_debug) {
				/* DEBUG */
				output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)cb_code_field (z)->name, NULL));
				output_stmt (cb_build_debug (cb_debug_contents,
							     NULL, z));
				output_perform_call (cb_code_field (z)->debug_section,
						     cb_code_field (z)->debug_section);
			}
		}
	}
}

static void
output_cond_debug (cb_tree x)
{
	struct cb_binary_op	*p;

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_FUNCALL:
		output_funcall_debug (x);
		break;
	case CB_TAG_LIST:
		break;
	case CB_TAG_BINARY_OP:
		p = CB_BINARY_OP (x);
		switch (p->op) {
		case '!':
			output_cond_debug (p->x);
			break;

		case '&':
		case '|':
			output_cond_debug (p->x);
			output_cond_debug (p->y);
			break;

		case '=':
		case '<':
		case '[':
		case '>':
		case ']':
		case '~':
			output_cond_debug (p->x);
			break;

		default:
			if (CB_REF_OR_FIELD_P (x) &&
			    cb_code_field (x)->flag_field_debug) {
				output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)cb_code_field (x)->name, NULL));
				output_stmt (cb_build_debug (cb_debug_contents,
							     NULL, x));
				output_perform_call (cb_code_field (x)->debug_section,
						     cb_code_field (x)->debug_section);
			}
			break;
		}
		break;
	default:
		break;
	}
}

static void
output_perform_once (struct cb_perform *p)
{
	if (p->body && CB_PAIR_P (p->body)) {
		output_perform_call (CB_LABEL (cb_ref (CB_PAIR_X (p->body))),
				     CB_LABEL (cb_ref (CB_PAIR_Y (p->body))));
	} else {
		output_stmt (p->body);
	}
	if (p->cycle_label) {
		output_stmt (cb_ref (p->cycle_label));
	}
}

static void
output_perform_until (struct cb_perform *p, cb_tree l)
{
	struct cb_perform_varying	*v;
	struct cb_field			*f;
	cb_tree				next;

	if (l == NULL) {
		/* Perform body at the end */
		output_perform_once (p);
		return;
	}

	v = CB_PERFORM_VARYING (CB_VALUE (l));
	next = CB_CHAIN (l);

	output_line ("for (;;)");
	output_indent ("{");

	if (next && CB_PERFORM_VARYING (CB_VALUE (next))->name) {
		output_move (CB_PERFORM_VARYING (CB_VALUE (next))->from,
			     CB_PERFORM_VARYING (CB_VALUE (next))->name);
		/* DEBUG */
		if (current_prog->flag_gen_debug) {
			f = CB_FIELD (cb_ref (CB_PERFORM_VARYING (CB_VALUE (next))->name));
			if (f->flag_field_debug) {
				output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)f->name, NULL));
				output_stmt (cb_build_debug (cb_debug_contents,
							     NULL, CB_PERFORM_VARYING (CB_VALUE (next))->name));
				output_perform_call (f->debug_section,
						     f->debug_section);
			}
		}

	}

	if (p->test == CB_AFTER) {
		output_perform_until (p, next);
	}

	/* DEBUG */
	if (current_prog->flag_gen_debug) {
		output_cond_debug (v->until);
	}

	output_prefix ();
	output ("if (");
	output_cond (v->until, 0);
	output (")\n");
	output_line ("  break;");

	if (p->test == CB_BEFORE) {
		output_perform_until (p, next);
	}

	if (v->step) {
		output_stmt (v->step);
	}

	output_indent ("}");
}

static void
output_perform (struct cb_perform *p)
{
	struct cb_perform_varying	*v;
	struct cb_field			*f;

	switch (p->perform_type) {
	case CB_PERFORM_EXIT:
		if (CB_LABEL (p->data)->flag_return) {
			output_perform_exit (CB_LABEL (p->data));
		}
		break;
	case CB_PERFORM_ONCE:
		output_perform_once (p);
		break;
	case CB_PERFORM_TIMES:
		output_prefix ();
		output ("for (n%d = ", loop_counter);
		output_param (cb_build_cast_llint (p->data), 0);
		output ("; n%d > 0; n%d--)\n", loop_counter, loop_counter);
		loop_counter++;
		output_indent ("{");
		output_perform_once (p);
		output_indent ("}");
		break;
	case CB_PERFORM_UNTIL:
		v = CB_PERFORM_VARYING (CB_VALUE (p->varying));
		if (v->name) {
			output_move (v->from, v->name);
			/* DEBUG */
			if (current_prog->flag_gen_debug) {
				f = CB_FIELD (cb_ref (v->name));
				if (f->flag_field_debug) {
					output_stmt (cb_build_debug (cb_debug_name,
						     (const char *)f->name, NULL));
					output_stmt (cb_build_debug (cb_debug_contents,
								     NULL, v->name));
					output_perform_call (f->debug_section,
							     f->debug_section);
				}
			}

		}
		output_perform_until (p, p->varying);
		break;
	case CB_PERFORM_FOREVER:
		output_prefix ();
		output ("for (;;)\n");
		output_indent ("{");
		output_perform_once (p);
		output_indent ("}");
		break;
	default:
		break;
	}
	if (p->exit_label) {
		output_stmt (cb_ref (p->exit_label));
	}
}

static void
output_file_error (struct cb_file *pfile)
{
	struct cb_file		*fl;
	cb_tree			l;

	if (current_prog->flag_gen_debug) {
		output_stmt (cb_build_debug (cb_debug_contents,
					     "USE PROCEDURE", NULL));
	}
	for (l =  current_prog->local_file_list; l; l = CB_CHAIN (l)) {
		fl = CB_FILE(CB_VALUE (l));
		if (!strcmp (pfile->name, fl->name)) {
			output_perform_call (fl->handler,
					     fl->handler);
			return;
		}
	}
	for (l =  current_prog->global_file_list; l; l = CB_CHAIN (l)) {
		fl = CB_FILE(CB_VALUE (l));
		if (!strcmp (pfile->name, fl->name)) {
			if (fl->handler_prog == current_prog) {
				output_perform_call (fl->handler,
						     fl->handler);
			} else {
				if (fl->handler_prog->nested_level) {
					output_line ("%s_%d_ (%d);",
						fl->handler_prog->program_id,
						fl->handler_prog->toplev_count,
						fl->handler->id);
				} else {
					output_line ("%s_ (%d);",
						fl->handler_prog->program_id,
						fl->handler->id);
				}
			}
			return;
		}
	}
	output_perform_call (pfile->handler, pfile->handler);
}

/* GO TO */

static void
output_goto_1 (cb_tree x)
{
	struct cb_label		*lb;
	struct cb_para_label	*p;

	lb = CB_LABEL (cb_ref (x));
	if (current_prog->flag_segments && last_segment != lb->segment) {
		/* Zap independent labels */
		if (lb->flag_section) {
			p = lb->para_label;
		} else if (lb->section) {
			p = lb->section->para_label;
		} else {
			p = NULL;
		}
		for (; p; p = p->next) {
			if (p->para->segment > 49 &&
			    p->para->flag_alter) {
				output_line ("label_%s%d = 0;",
					     CB_PREFIX_LABEL, p->para->id);
			}
		}
	}

	/* Check for debugging on procedure */
	if (current_prog->flag_gen_debug && lb->flag_real_label &&
	    (current_prog->all_procedure || lb->flag_debugging_mode)) {
		output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)lb->name, NULL));
		output_move (cb_space, cb_debug_contents);
	}

	output_line ("goto %s%d;", CB_PREFIX_LABEL, lb->id);
}

static void
output_goto (struct cb_goto *p)
{
	cb_tree		l;
	struct cb_field	*f;
	int		i;

	i = 1;
	if (p->depending) {
		/* Check for debugging on the DEPENDING item */
		if (current_prog->flag_gen_debug) {
			f = CB_FIELD (cb_ref (p->depending));
			if (f->flag_all_debug) {
				output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)f->name, NULL));
				output_stmt (cb_build_debug (cb_debug_contents,
							     NULL, p->depending));
				output_perform_call (f->debug_section,
						     f->debug_section);
			}
		}
		output_prefix ();
		output ("switch (");
		output_param (cb_build_cast_int (p->depending), 0);
		output (")\n");
		output_indent ("{");
		for (l = p->target; l; l = CB_CHAIN (l)) {
			output_indent_level -= 2;
			output_line ("case %d:", i++);
			output_indent_level += 2;
			output_goto_1 (CB_VALUE (l));
		}
		output_indent ("}");
	} else if (p->target == NULL) {
		/* EXIT PROGRAM/FUNCTION */
		needs_exit_prog = 1;
		if (cb_flag_implicit_init || current_prog->nested_level ||
		    current_prog->prog_type == CB_FUNCTION_TYPE) {
			output_line ("goto exit_program;");
		} else {
			/* Ignore if not a callee */
			output_line ("if (module->next)");
			output_line ("  goto exit_program;");
		}
	} else if (p->target == cb_int1) {
		needs_exit_prog = 1;
		output_line ("goto exit_program;");
	} else {
		output_goto_1 (p->target);
	}
}

/* ALTER */

static void
output_alter (struct cb_alter *p)
{
	struct cb_label	*l1;
	struct cb_label	*l2;

	l1 = CB_LABEL (CB_REFERENCE(p->source)->value);
	l2 = CB_LABEL (CB_REFERENCE(p->target)->value);
	output_line ("label_%s%d = %d;", CB_PREFIX_LABEL, l1->id, l2->id);

	/* Check for debugging on procedure name */
	if (current_prog->flag_gen_debug && l1->flag_real_label &&
	    (current_prog->all_procedure || l1->flag_debugging_mode)) {
		output_stmt (cb_build_debug (cb_debug_name,
					     (const char *)l1->name, NULL));
		output_stmt (cb_build_debug (cb_debug_contents,
					     (const char *)l2->name, NULL));
		if (current_prog->all_procedure) {
			output_perform_call (current_prog->all_procedure,
					     current_prog->all_procedure);
		} else if (l1->flag_debugging_mode) {
			output_perform_call (l1->debug_section,
					     l1->debug_section);
		}
	}
}

/* Output statement */

static void
output_ferror_stmt (struct cb_statement *p, const int code)
{
	output_line ("if (unlikely(cob_glob_ptr->cob_exception_code != 0))");
	output_indent ("{");
	if (p->handler1) {
		if ((code & 0x00ff) == 0) {
			output_line ("if ((cob_glob_ptr->cob_exception_code & 0xff00) == 0x%04x)",
			     code);
		} else {
			output_line ("if (cob_glob_ptr->cob_exception_code == 0x%04x)", code);
		}
		output_indent ("{");
		output_stmt (p->handler1);
		output_indent ("}");
		output_line ("else");
		output_indent ("{");
	}
	output_file_error (CB_FILE (p->file));
	output_indent ("}");
	if (p->handler1) {
		output_indent ("}");
	}
	if (p->handler2 || p->handler3) {
		output_line ("else");
		output_indent ("{");
		if (p->handler3) {
			output_stmt (p->handler3);
		}
		if (p->handler2) {
			output_stmt (p->handler2);
		}
		output_indent ("}");
	}
}

static void
output_section_info (struct cb_label *lp)
{
	if (CB_TREE (lp) == cb_standard_error_handler) {
		return;
	}
	if (lp->flag_dummy_exit) {
		return;
	}
	if (lp->flag_section) {
		if (!lp->flag_dummy_section) {
			sprintf (string_buffer, "Section:   %s", lp->orig_name);
		} else {
			sprintf (string_buffer, "Section:   (None)");
		}
	} else if (lp->flag_entry) {
		sprintf (string_buffer, "Entry:     %s", lp->orig_name);
	} else {
		if (!lp->flag_dummy_paragraph) {
			sprintf (string_buffer, "Paragraph: %s", lp->orig_name);
		} else {
			sprintf (string_buffer, "Paragraph: (None)");
		}
	}
	if (CB_TREE (lp)->source_file) {
		output_line ("cob_trace_section (%s%d, %s%d, %d);",
			     CB_PREFIX_STRING,
			     lookup_string (string_buffer),
			     CB_PREFIX_STRING,
			     lookup_string (CB_TREE (lp)->source_file),
			     CB_TREE (lp)->source_line);
	} else {
		output_line ("cob_trace_section (%s%d, NULL, %d);",
			     CB_PREFIX_STRING,
			     lookup_string (string_buffer),
			     CB_TREE (lp)->source_line);
	}
}

static void
output_trace_info (cb_tree x, struct cb_statement *p)
{
	output_prefix ();
	output ("cob_set_location (%s%d, %d, ",
		CB_PREFIX_STRING,
		lookup_string (x->source_file),
		x->source_line);
	if (excp_current_section) {
		output ("%s%d, ",
			CB_PREFIX_STRING, lookup_string (excp_current_section));
	} else {
		output ("NULL, ");
	}
	if (excp_current_paragraph) {
		output ("%s%d, ",
			CB_PREFIX_STRING, lookup_string (excp_current_paragraph));
	} else {
		output ("NULL, ");
	}
	if (p->name) {
		output ("%s%d);\n",
			CB_PREFIX_STRING, lookup_string (p->name));
	} else {
		output ("NULL);\n");
	}
}

static void
output_label_info (cb_tree x, struct cb_label *lp)
{
	if (lp->flag_dummy_section || lp->flag_dummy_paragraph) {
		return;
	}

	output_newline ();

	if (lp->flag_dummy_exit) {
		output_line ("/* Implicit EXIT label */");
		return;
	} else if (lp->flag_next_sentence) {
		output_line ("/* Implicit NEXT SENTENCE label */");
		return;
	}

	output_prefix ();
	if (x->source_file) {
		output ("/* Line: %-10d: ", x->source_line);
	} else {
		output ("/* ");
	}
	if (lp->flag_section) {
		output ("Section   %-24s", (const char *)lp->name);
		excp_current_section = (const char *)lp->name;
		excp_current_paragraph = NULL;
	} else {
		if (lp->flag_entry) {
			output ("Entry     %-24s", lp->orig_name);
			excp_current_section = NULL;
			excp_current_paragraph = NULL;
		} else {
			output ("Paragraph %-24s", (const char *)lp->name);
			excp_current_paragraph = (const char *)lp->name;
		}
	}
	if (x->source_file) {
		output (": %s */\n", x->source_file);
	} else {
		output ("*/\n");
	}
}

static void
output_alter_check (struct cb_label *lp)
{
	struct cb_alter_id	*aid;

	output_local ("static int\tlabel_%s%d = 0;\n",
		     CB_PREFIX_LABEL, lp->id);
	if (current_prog->flag_segments) {
		output_local ("static int\tsave_label_%s%d = 0;\n",
			     CB_PREFIX_LABEL, lp->id);
	}
	output_newline ();
	output_line ("/* ALTER processing */");
	output_line ("switch (label_%s%d)",
		     CB_PREFIX_LABEL, lp->id);
	output_indent ("{");
	for (aid = lp->alter_gotos; aid; aid = aid->next) {
			output_line ("case %d:", aid->goto_id);
			output_line ("goto %s%d;", CB_PREFIX_LABEL, aid->goto_id);
	}
	output_indent ("}");
	output_newline ();
}

static void
output_stmt (cb_tree x)
{
	struct cb_statement	*p;
	struct cb_label		*lp;
	struct cb_assign	*ap;
	struct cb_if		*ip;
	struct cb_para_label	*pal;
	struct cb_set_attr	*sap;
#ifdef	COB_NON_ALIGNED
	struct cb_cast		*cp;
#endif
	size_t			size;
	int			code;

	stack_id = 0;
	if (x == NULL) {
		output_line (";");
		return;
	}
	if (unlikely(x == cb_error_node)) {
		cobc_abort_pr (_("Unexpected error_node parameter"));
		COBC_ABORT ();
	}

	if (inside_check != 0) {
		if (inside_stack[inside_check - 1] != 0) {
			inside_stack[inside_check - 1] = 0;
			output (",\n");
		}
	}

	switch (CB_TREE_TAG (x)) {
	case CB_TAG_STATEMENT:
		p = CB_STATEMENT (x);
		/* Output source location as a comment */
		if (p->name) {
			output_newline ();
			output_line ("/* Line: %-10d: %-19.19s: %s */",
				     x->source_line, p->name, x->source_file);
		}
		if (x->source_file) {
			if (cb_flag_source_location) {
				/* Output source location as code */
				output_trace_info (x, p);
			}
			if (current_prog->flag_gen_debug &&
			    !p->flag_in_debug) {
				output_prefix ();
				output ("memcpy (");
				output_data (cb_debug_line);
				output (", \"%6d\", 6);\n", x->source_line);
			}
			last_line = x->source_line;
		}

#if	0	/* RXWRXW - Exception */
		if (p->handler1 || p->handler2 ||
		    (p->file && CB_EXCEPTION_ENABLE (COB_EC_I_O))) {
#else
		if (!p->file && (p->handler1 || p->handler2)) {
#endif
			output_line ("cob_glob_ptr->cob_exception_code = 0;");
		}

		if (p->null_check) {
			output_stmt (p->null_check);
		}

		if (p->body) {
			output_stmt (p->body);
		}

		/* Output field debugging statements */
		if (current_prog->flag_gen_debug && p->debug_check) {
			output_stmt (p->debug_check);
		}

		/* Special debugging callback for START / DELETE */
		/* Must be done immediately after I/O and before */
		/* status check */
		if (current_prog->flag_gen_debug && p->file && p->flag_callback) {
			output_line ("save_exception_code = cob_glob_ptr->cob_exception_code;");
			output_stmt (cb_build_debug (cb_debug_name,
				     CB_FILE(p->file)->name, NULL));
			output_move (cb_space, cb_debug_contents);
			output_perform_call (CB_FILE(p->file)->debug_section,
					     CB_FILE(p->file)->debug_section);
			output_line ("cob_glob_ptr->cob_exception_code = save_exception_code;");
			need_save_exception = 1;
		}

		if (p->handler1 || p->handler2 ||
		    (p->file && CB_EXCEPTION_ENABLE (COB_EC_I_O))) {
			code = CB_EXCEPTION_CODE (p->handler_id);
			if (p->file) {
				output_ferror_stmt (p, code);
			} else {
				if (p->handler1) {
					if ((code & 0x00ff) == 0) {
						output_line ("if (unlikely((cob_glob_ptr->cob_exception_code & 0xff00) == 0x%04x))",
						     code);
					} else {
						output_line ("if (unlikely(cob_glob_ptr->cob_exception_code == 0x%04x))", code);
					}
					output_indent ("{");
					output_stmt (p->handler1);
					output_indent ("}");
					if (p->handler2) {
						output_line ("else");
					}
				}
				if (p->handler2) {
					if (p->handler1 == NULL) {
						output_line ("if (!cob_glob_ptr->cob_exception_code)");
					}
					output_indent ("{");
					output_stmt (p->handler2);
					output_indent ("}");
				}
			}
		}
		break;
	case CB_TAG_LABEL:
		lp = CB_LABEL (x);
		if (lp->flag_skip_label) {
			break;
		}
		output_label_info (x, lp);
		if (lp->flag_section) {
			for (pal = lp->para_label; pal; pal = pal->next) {
				if (pal->para->segment > 49 &&
				    pal->para->flag_alter) {
					output_line ("label_%s%d = 0;",
						     CB_PREFIX_LABEL, pal->para->id);
				}
			}
			last_segment = lp->segment;
			last_section = lp;
		}
		if (lp->flag_begin) {
			output_line ("%s%d:;", CB_PREFIX_LABEL, lp->id);
		}

		/* Check for runtime debug flag */
		if (current_prog->flag_debugging && lp->flag_is_debug_sect) {
			output_line ("if (!cob_debugging_mode)");
			output_line ("\tgoto %s%d;",
				CB_PREFIX_LABEL, CB_LABEL (lp->exit_label)->id);
		}

		if (cb_flag_trace) {
			output_section_info (lp);
		}

		/* Check procedure debugging */
		if (current_prog->flag_gen_debug && lp->flag_real_label) {
			output_stmt (cb_build_debug (cb_debug_name,
				     (const char *)lp->name, NULL));
			if (current_prog->all_procedure) {
				output_perform_call (current_prog->all_procedure,
						     current_prog->all_procedure);
			} else if (lp->flag_debugging_mode) {
				output_perform_call (lp->debug_section,
						     lp->debug_section);
			}
		}

		/* Check ALTER processing */
		if (lp->flag_alter) {
			output_alter_check (lp);
		}

		break;
	case CB_TAG_FUNCALL:
		output_prefix ();
		output_funcall (x);
		if (inside_check == 0) {
			output (";\n");
		} else {
			inside_stack[inside_check - 1] = 1;
		}
		break;
	case CB_TAG_ASSIGN:
		ap = CB_ASSIGN (x);
#ifdef	COB_NON_ALIGNED
		/* Nonaligned */
		if (CB_TREE_CLASS (ap->var) == CB_CLASS_POINTER ||
		    CB_TREE_CLASS (ap->val) == CB_CLASS_POINTER) {
			/* Pointer assignment */
			output_indent ("{");
			output_line ("void *temp_ptr;");

			/* temp_ptr = source address; */
			output_prefix ();
			if (ap->val == cb_null || ap->val == cb_zero) {
				/* MOVE NULL ... */
				output ("temp_ptr = 0;\n");
			} else if (CB_TREE_TAG (ap->val) == CB_TAG_CAST) {
				/* MOVE ADDRESS OF val ... */
				cp = CB_CAST (ap->val);
				output ("temp_ptr = ");
				switch (cp->cast_type) {
				case CB_CAST_ADDRESS:
					output_data (cp->val);
					break;
				case CB_CAST_PROGRAM_POINTER:
					output ("cob_call_field (");
					output_param (ap->val, -1);
					if (current_prog->nested_prog_list) {
						gen_nested_tab = 1;
						output (", cob_nest_tab, 0, %d)",
							cb_fold_call);
					} else {
						output (", NULL, 0, %d)",
							cb_fold_call);
					}
					break;
				default:
					cobc_abort_pr (_("Unexpected cast type %d"),
							cp->cast_type);
					COBC_ABORT ();
				}
				output (";\n");
			} else {
				/* MOVE val ... */
				output ("memcpy(&temp_ptr, ");
				output_data (ap->val);
				output (", sizeof(temp_ptr));\n");
			}

			/* Destination address = temp_ptr; */
			output_prefix ();
			if (CB_TREE_TAG (ap->var) == CB_TAG_CAST) {
				/* SET ADDRESS OF var ... */
				cp = CB_CAST (ap->var);
				if (cp->cast_type != CB_CAST_ADDRESS) {
					cobc_abort_pr (_("Unexpected tree type %d"),
							cp->cast_type);
					COBC_ABORT ();
				}
				output_data (cp->val);
				output (" = temp_ptr;\n");
			} else {
				/* MOVE ... TO var */
				output ("memcpy(");
				output_data (ap->var);
				output (", &temp_ptr, sizeof(temp_ptr));\n");
			}

			output_indent ("}");
		} else {
			/* Numeric assignment */
			output_prefix ();
			output_integer (ap->var);
			output (" = ");
			output_integer (ap->val);
			if (inside_check == 0) {
				output (";\n");
			} else {
				inside_stack[inside_check - 1] = 1;
			}
		}
#else	/* Nonaligned */
		output_prefix ();
		output_integer (ap->var);
		output (" = ");
		output_integer (ap->val);
		if (inside_check == 0) {
			output (";\n");
		} else {
			inside_stack[inside_check - 1] = 1;
		}
#endif	/* Nonaligned */
		break;
	case CB_TAG_INITIALIZE:
		output_initialize (CB_INITIALIZE (x));
		break;
	case CB_TAG_SEARCH:
		output_search (CB_SEARCH (x));
		break;
	case CB_TAG_CALL:
		output_call (CB_CALL (x));
		break;
	case CB_TAG_GOTO:
		output_goto (CB_GOTO (x));
		break;
	case CB_TAG_CANCEL:
		output_cancel (CB_CANCEL (x));
		break;
	case CB_TAG_SET_ATTR:
		sap = CB_SET_ATTR (x);
		output_set_attribute (sap->fld, sap->val_on, sap->val_off);
		break;
	case CB_TAG_ALTER:
		output_alter (CB_ALTER (x));
		break;
	case CB_TAG_IF:
		ip = CB_IF (x);
		if (!ip->is_if) {
			output_newline ();
			output_line ("/* WHEN */");
			output_newline ();
		}
		gen_if_level++;
		code = 0;
		output_prefix ();
		if(ip->is_if == 2
		&& ip->stmt1 == NULL
		&& ip->stmt2 != NULL) {	/* Really PRESENT WHEN for Report field */
			struct cb_field *p = (struct cb_field *)ip->stmt2;
			output_line ("/* PRESENT WHEN */");
			output_prefix ();
			output ("if (");
			output_cond (ip->test, 0);
			output (")\n");
			output_line ("{");
			output("\t%s%d.suppress = 0;\n",CB_PREFIX_REPORT_FIELD,p->id);
			output_line ("} else {");
			output("\t%s%d.suppress = 1;\n",CB_PREFIX_REPORT_FIELD,p->id);
			output_line ("}");
			gen_if_level--;
			break;
		}
		if(ip->is_if == 3
		&& ip->stmt1 == NULL
		&& ip->stmt2 != NULL) {	/* Really PRESENT WHEN for Report line */
			struct cb_field *p = (struct cb_field *)ip->stmt2;
			output_line ("/* PRESENT WHEN */");
			output_prefix ();
			output ("if (");
			output_cond (ip->test, 0);
			output (")\n");
			output_line ("{");
			output("\t%s%d.suppress = 0;\n",CB_PREFIX_REPORT_LINE,p->id);
			output_line ("} else {");
			output("\t%s%d.suppress = 1;\n",CB_PREFIX_REPORT_LINE,p->id);
			output_line ("}");
			gen_if_level--;
			break;
		}
		output ("if (");
		output_cond (ip->test, 0);
		output (")\n");
		output_line ("{");
		output_indent_level += 2;
		if (ip->stmt1) {
			output_stmt (ip->stmt1);
		} else {
			output_line ("; /* Nothing */");
		}
		if (gen_if_level > cb_if_cutoff) {
			if (ip->stmt2) {
				code = cb_id++;
				output_line ("goto l_%d;", code);
			}
		}
		output_indent_level -= 2;
		output_line ("}");
		if (ip->stmt2) {
			if (gen_if_level <= cb_if_cutoff) {
				output_line ("else");
				output_line ("{");
				output_indent_level += 2;
			}
			if (ip->is_if) {
				output_line ("/* ELSE */");
			} else {
				output_line ("/* WHEN */");
			}
			output_stmt (ip->stmt2);
			if (gen_if_level <= cb_if_cutoff) {
				output_indent_level -= 2;
				output_line ("}");
			} else {
				output_line ("l_%d:;", code);
			}
		}
		gen_if_level--;
		break;
	case CB_TAG_PERFORM:
		output_perform (CB_PERFORM (x));
		break;
	case CB_TAG_CONTINUE:
		output_prefix ();
		output (";\n");
		break;
	case CB_TAG_LIST:
		if (cb_flag_extra_brace) {
			output_indent ("{");
		}
		for (; x; x = CB_CHAIN (x)) {
			output_stmt (CB_VALUE (x));
		}
		if (cb_flag_extra_brace) {
			output_indent ("}");
		}
		break;
	case CB_TAG_REFERENCE:
		output_stmt (CB_REFERENCE(x)->value);
		break;
	case CB_TAG_DIRECT:
		if (CB_DIRECT (x)->flag_is_direct) {
			if (CB_DIRECT (x)->flag_new_line) {
				output_newline ();
			}
			output_line ("%s", (const char *)(CB_DIRECT (x)->line));
		} else {
			output_newline ();
			output_line ("/* %s */", (const char *)(CB_DIRECT (x)->line));
		}
		break;
	case CB_TAG_DEBUG:
		if (!current_prog->flag_gen_debug) {
			break;
		}
		output_prefix ();
		size = cb_code_field (CB_DEBUG(x)->target)->size;
		if (CB_DEBUG(x)->value) {
			if (size <= CB_DEBUG(x)->size) {
				output ("memcpy (");
				output_data (CB_DEBUG(x)->target);
				output (", %s%d, %d);\n", CB_PREFIX_STRING,
					lookup_string (CB_DEBUG(x)->value),
					(int)size);
			} else {
				output ("memcpy (");
				output_data (CB_DEBUG(x)->target);
				output (", %s%d, %d);\n", CB_PREFIX_STRING,
					lookup_string (CB_DEBUG(x)->value),
					(int)CB_DEBUG(x)->size);
				output_prefix ();
				output ("memset (");
				output_data (CB_DEBUG(x)->target);
				code = (int)(size - CB_DEBUG(x)->size);
				output (" + %d, ' ', %d);\n",
					(int)CB_DEBUG(x)->size, code);

			}
		} else {
			if (size <= CB_DEBUG(x)->size) {
				output ("memcpy (");
				output_data (CB_DEBUG(x)->target);
				output (", ");
				output_data (CB_DEBUG(x)->fld);
				output (", %d);\n", (int)size);
			} else {
				output ("memcpy (");
				output_data (CB_DEBUG(x)->target);
				output (", ");
				output_data (CB_DEBUG(x)->fld);
				output (", %d);\n", (int)CB_DEBUG(x)->size);
				output_prefix ();
				output ("memset (");
				output_data (CB_DEBUG(x)->target);
				code = (int)(size - CB_DEBUG(x)->size);
				output (" + %d, ' ', %d);\n",
					(int)CB_DEBUG(x)->size, code);
			}
		}
		break;
	case CB_TAG_DEBUG_CALL:
		output_perform_call (CB_DEBUG_CALL(x)->target,
				     CB_DEBUG_CALL(x)->target);
		break;
	default:
		cobc_abort_pr (_("Unexpected tree tag %d"), (int)CB_TREE_TAG (x));
		COBC_ABORT ();
	}
}

/* File definition */

static int
output_file_allocation (struct cb_file *f)
{

	if (f->flag_global) {
#if	0	/* RXWRXW - Global status */
		if (f->file_status) {
			/* Force status into main storage file */
			CB_FIELD_PTR (f->file_status)->flag_is_global = 1;
		}
#endif
		output_storage ("\n/* Global file %s */\n", f->name);
	} else {
		output_local ("\n/* File %s */\n", f->name);
	}
	/* Output RELATIVE/RECORD KEY's */
	if (f->organization == COB_ORG_RELATIVE ||
	    f->organization == COB_ORG_INDEXED) {
		if (f->flag_global) {
			output_storage ("static cob_file_key\t*%s%s = NULL;\n",
				CB_PREFIX_KEYS, f->cname);
		} else {
			output_local ("static cob_file_key\t*%s%s = NULL;\n",
				CB_PREFIX_KEYS, f->cname);
		}
	}
	if (f->flag_global) {
		output_storage ("static cob_file\t\t*%s%s = NULL;\n",
			CB_PREFIX_FILE, f->cname);
		output_storage ("static unsigned char\t%s%s_status[4];\n",
			CB_PREFIX_FILE, f->cname);
	} else {
		output_local ("static cob_file\t\t*%s%s = NULL;\n",
			CB_PREFIX_FILE, f->cname);
		output_local ("static unsigned char\t%s%s_status[4];\n",
			CB_PREFIX_FILE, f->cname);
	}

	if (f->code_set) {
		gen_native = 1;
		switch (f->code_set->alphabet_type) {
		case CB_ALPHABET_ASCII:
			gen_ebcdic_ascii = 1;
			break;
		case CB_ALPHABET_EBCDIC:
			gen_full_ebcdic = 1;
			break;
		case CB_ALPHABET_CUSTOM:
			gen_custom = 1;
			break;
		default:
			break;
		}
	}

	if (f->linage) {
		return 1;
	}
	return 0;
}

static void
output_file_initialization (struct cb_file *f)
{
	struct cb_alt_key	*l;
	int			nkeys;
	int			features;

	nkeys = 1;
	if (f->flag_external) {
		output_line ("%s%s = cob_external_addr (\"%s\", sizeof(cob_file));",
			     CB_PREFIX_FILE, f->cname, f->cname);
		output_line ("if (cob_glob_ptr->cob_initial_external)");
		output_indent ("{");
		if (f->linage) {
			output_line ("%s%s->linorkeyptr = cob_cache_malloc (sizeof(cob_linage));", CB_PREFIX_FILE, f->cname);
		}
	} else {
		output_line ("if (!%s%s)", CB_PREFIX_FILE, f->cname);
		output_indent ("{");
		output_line ("%s%s = cob_cache_malloc (sizeof(cob_file));", CB_PREFIX_FILE, f->cname);
		if (f->linage) {
			output_line ("%s%s->linorkeyptr = cob_cache_malloc (sizeof(cob_linage));", CB_PREFIX_FILE, f->cname);
		}
		output_indent ("}");
	}
	/* Output RELATIVE/RECORD KEY's */
	if (f->organization == COB_ORG_RELATIVE
	 || f->organization == COB_ORG_INDEXED) {
		for (l = f->alt_key_list; l; l = l->next) {
			nkeys++;
		}
		output_line ("if (!%s%s)", CB_PREFIX_KEYS, f->cname);
		output_indent ("{");
		output_line ("%s%s = cob_cache_malloc (sizeof (cob_file_key) * %d);",
			     CB_PREFIX_KEYS, f->cname, nkeys);
		output_indent ("}");
		nkeys = 1;
		output_prefix ();
		output ("%s%s->field = ", CB_PREFIX_KEYS, f->cname);
		output_param (f->key, -1);
		output (";\n");
		output_prefix ();
		output ("%s%s->flag = 0;\n", CB_PREFIX_KEYS, f->cname);
		output_prefix ();
		if (f->key) {
			output ("%s%s->offset = %d;\n", CB_PREFIX_KEYS, f->cname,
				cb_code_field (f->key)->offset);
		} else {
			output ("%s%s->offset = 0;\n", CB_PREFIX_KEYS, f->cname);
		}
		for (l = f->alt_key_list; l; l = l->next) {
			output_prefix ();
			output ("(%s%s + %d)->field = ", CB_PREFIX_KEYS, f->cname,
				nkeys);
			output_param (l->key, -1);
			output (";\n");
			output_prefix ();
			output ("(%s%s + %d)->flag = %d;\n", CB_PREFIX_KEYS,
				f->cname, nkeys, l->duplicates);
			output_prefix ();
			output ("(%s%s + %d)->offset = %d;\n", CB_PREFIX_KEYS,
				f->cname, nkeys, cb_code_field (l->key)->offset);
			nkeys++;
		}
	}

	output_line ("%s%s->select_name = (const char *)\"%s\";", CB_PREFIX_FILE,
		     f->cname, f->name);
	if (f->flag_external && !f->file_status) {
		output_line ("%s%s->file_status = cob_external_addr (\"%s%s_status\", 4);",
			     CB_PREFIX_FILE, f->cname, CB_PREFIX_FILE, f->cname);
	} else {
		output_line ("%s%s->file_status = %s%s_status;", CB_PREFIX_FILE,
			     f->cname, CB_PREFIX_FILE, f->cname);
		output_line ("memset (%s%s_status, '0', 2);", CB_PREFIX_FILE,
			     f->cname);
	}
	output_prefix ();
	output ("%s%s->assign = ", CB_PREFIX_FILE, f->cname);
	output_param (f->assign, -1);
	output (";\n");
	output_prefix ();
	output ("%s%s->record = ", CB_PREFIX_FILE, f->cname);
	output_param (CB_TREE (f->record), -1);
	output (";\n");
	output_prefix ();
	output ("%s%s->variable_record = ", CB_PREFIX_FILE, f->cname);
	if (f->record_depending) {
		output_param (f->record_depending, -1);
	} else {
		output ("NULL");
	}
	output (";\n");
	output_line ("%s%s->record_min = %d;", CB_PREFIX_FILE,
		     f->cname, f->record_min);
	output_line ("%s%s->record_max = %d;", CB_PREFIX_FILE,
		     f->cname, f->record_max);
	if (f->organization == COB_ORG_RELATIVE
	 || f->organization == COB_ORG_INDEXED) {
		output_line ("%s%s->nkeys = %d;", CB_PREFIX_FILE,
			     f->cname, nkeys);
		output_line ("%s%s->keys = %s%s;", CB_PREFIX_FILE,
			     f->cname, CB_PREFIX_KEYS, f->cname);
	} else {
		output_line ("%s%s->nkeys = 0;", CB_PREFIX_FILE, f->cname);
		output_line ("%s%s->keys = NULL;", CB_PREFIX_FILE, f->cname);
	}
	output_line ("%s%s->file = NULL;", CB_PREFIX_FILE, f->cname);

	if (f->linage) {
		output_line ("lingptr = %s%s->linorkeyptr;",
				CB_PREFIX_FILE, f->cname);
		output_prefix ();
		output ("lingptr->linage = ");
		output_param (f->linage, -1);
		output (";\n");
		output_prefix ();
		output ("lingptr->linage_ctr = ");
		output_param (f->linage_ctr, -1);
		output (";\n");
		if (f->latfoot) {
			output_prefix ();
			output ("lingptr->latfoot = ");
			output_param (f->latfoot, -1);
			output (";\n");
		} else {
			output_line ("lingptr->latfoot = NULL;");
		}
		if (f->lattop) {
			output_prefix ();
			output ("lingptr->lattop = ");
			output_param (f->lattop, -1);
			output (";\n");
		} else {
			output_line ("lingptr->lattop = NULL;");
		}
		if (f->latbot) {
			output_prefix ();
			output ("lingptr->latbot = ");
			output_param (f->latbot, -1);
			output (";\n");
		} else {
			output_line ("lingptr->latbot = NULL;");
		}
		output_line ("lingptr->lin_lines = 0;");
		output_line ("lingptr->lin_foot = 0;");
		output_line ("lingptr->lin_top = 0;");
		output_line ("lingptr->lin_bot = 0;");
	}

	output_line ("%s%s->fd = -1;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->organization = %d;", CB_PREFIX_FILE, f->cname,
		     f->organization);
	output_line ("%s%s->access_mode = %d;", CB_PREFIX_FILE, f->cname,
		     f->access_mode);
	output_line ("%s%s->lock_mode = %d;", CB_PREFIX_FILE, f->cname,
		     f->lock_mode);
	output_line ("%s%s->open_mode = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_optional = %d;", CB_PREFIX_FILE, f->cname,
		     f->optional);
	output_line ("%s%s->last_open_mode = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_operation = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_nonexistent = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_end_of_file = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_begin_of_file = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_first_read = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_read_done = 0;", CB_PREFIX_FILE, f->cname);
	features = 0;
	if (f->file_status) {
		features |= COB_SELECT_FILE_STATUS;
	}
	if (f->linage) {
		features |= COB_SELECT_LINAGE;
	}
	if (f->flag_ext_assign) {
		features |= COB_SELECT_EXTERNAL;
	}
	if (f->special) {
		/* Special assignment */
		features |= f->special;
	}
	output_line ("%s%s->flag_select_features = %d;", CB_PREFIX_FILE, f->cname,
		     features);
	output_line ("%s%s->flag_needs_nl = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->flag_needs_top = 0;", CB_PREFIX_FILE, f->cname);
	output_line ("%s%s->file_version = %d;", CB_PREFIX_FILE, f->cname,
		     COB_FILE_VERSION);
	if (f->flag_external) {
		output_indent ("}");
	}
}

/* Screen definition */

static void
output_screen_definition (struct cb_field *p)
{
	int	type;

	if (p->sister) {
		output_screen_definition (p->sister);
	}
	if (p->children) {
		output_screen_definition (p->children);
	}

	type = (p->children ? COB_SCREEN_TYPE_GROUP :
		p->values ? COB_SCREEN_TYPE_VALUE :
		(p->size > 0) ? COB_SCREEN_TYPE_FIELD : COB_SCREEN_TYPE_ATTRIBUTE);
	if (type == COB_SCREEN_TYPE_FIELD || type == COB_SCREEN_TYPE_VALUE) {
		p->count++;
	}

	output_local ("static cob_screen\ts_%d;\n", p->id);
}

static void
output_screen_init (struct cb_field *p)
{
	int	type;

	type = (p->children ? COB_SCREEN_TYPE_GROUP :
		p->values ? COB_SCREEN_TYPE_VALUE :
		(p->size > 0) ? COB_SCREEN_TYPE_FIELD : COB_SCREEN_TYPE_ATTRIBUTE);
	output_prefix ();
	output ("cob_set_screen (&s_%d, ", p->id);

	if (p->sister && p->sister->level != 1) {
		output ("&s_%d, ", p->sister->id);
	} else {
		output ("NULL, ");
	}
	if (type == COB_SCREEN_TYPE_GROUP) {
		output ("&s_%d, ", p->children->id);
	} else {
		output ("NULL, ");
	}
	output_newline ();
	output_prefix ();
	output ("\t\t  ");
	if (type == COB_SCREEN_TYPE_FIELD) {
		output_param (cb_build_field_reference (p, NULL), -1);
		output (", ");
	} else {
		output ("NULL, ");
	}
	if (type == COB_SCREEN_TYPE_VALUE) {
		/* Need a field reference here */
		output_param (cb_build_field_reference (p, NULL), -1);
		output (", ");
	} else {
		output ("NULL, ");
	}

	if (p->screen_line) {
		output_param (p->screen_line, 0);
		output (", ");
	} else {
		output ("NULL, ");
	}
	output_newline ();
	output_prefix ();
	output ("\t\t  ");
	if (p->screen_column) {
		output_param (p->screen_column, 0);
		output (", ");
	} else {
		output ("NULL, ");
	}
	if (p->screen_foreg) {
		output_param (p->screen_foreg, 0);
		output (", ");
	} else {
		output ("NULL, ");
	}
	if (p->screen_backg) {
		output_param (p->screen_backg, 0);
		output (", ");
	} else {
		output ("NULL, ");
	}
	output_newline ();
	output_prefix ();
	output ("\t\t  ");
	if (p->screen_prompt) {
		output_param (p->screen_prompt, 0);
		output (", ");
	} else {
		output ("NULL, ");
	}
	output ("%d, %d, 0x%x);\n", type, p->occurs_min, p->screen_flag);

	if (p->children) {
		output_screen_init (p->children);
	}
	if (p->sister) {
		output_screen_init (p->sister);
	}
}

static void
compute_report_rcsz (struct cb_field *p)
{
    	if(p == NULL)
	    return;
	if (p->sister) {
		compute_report_rcsz (p->sister);
	}
	if (p->children) {
		compute_report_rcsz (p->children);
	}
	p->count++;
}

/* Report data definition */

/* Individual fields of the report(s) */
static int report_col_pos = 0;
static void
output_report_data (struct cb_field *p)
{
    	if(p == NULL)
	    return;
	if(p->storage == CB_STORAGE_REPORT) {
		if((p->report_flag & COB_REPORT_LINE))
			report_col_pos = 0;
		if(p->report_flag & COB_REPORT_COLUMN_PLUS) {
			p->report_column = report_col_pos + p->report_column;
			p->report_flag &= ~COB_REPORT_COLUMN_PLUS;
		}
		report_col_pos = p->report_column + p->size;
		if(!(p->report_flag & COB_REPORT_REF_EMITED)) {
			p->report_flag |= COB_REPORT_REF_EMITED;
			output ("static cob_field %s%d\t= ", CB_PREFIX_FIELD, p->id);
			output_field (cb_build_field_reference (p, NULL));
			if(p->report_column == 0)
				output_local(";\t/* %s */\n",p->name);
			else
				output_local(";\t/* col %3d */\n", p->report_column);
		}
		if(p->report_sum_counter) {
			output_emit_field(p->report_sum_counter,NULL);
		}
		if(p->report_source) {
			output_emit_field(p->report_source,"SOURCE");
		}
		if(p->report_control) {
			output_emit_field(p->report_control,"CONTROL");
		}
		if (p->children) {
			output_report_data (p->children);
		}
	}
	if (p->sister) {
		output_report_data (p->sister);
	}
}

static void
output_report_sum_control_field (struct cb_field *p)
{
	cb_tree	l,x;
    	if(p == NULL)
	    return;
	if(p->storage == CB_STORAGE_REPORT) {
		if(p->level == 01) {
			output_base(p,1U);
		}
		if(p->report_sum_counter) {
			output_base(cb_code_field(p->report_sum_counter),1U);
		}
		for (l = p->report_sum_list; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			output_base(cb_code_field(x),1);
		}
		if (p->children) {
			output_report_sum_control_field (p->children);
		}
	}
	if (p->sister) {
		output_report_sum_control_field (p->sister);
	}
}

static void
output_report_sumed_field (struct cb_field *p)
{
	cb_tree	l,x;
	struct cb_field *f;
    	if(p == NULL)
	    return;
	if(p->storage == CB_STORAGE_REPORT) {
		for (l = p->report_sum_list; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			f = cb_code_field(x);
			if (f->storage == CB_STORAGE_WORKING
			&& !(f->report_flag & COB_REPORT_REF_EMITED)) {
				output ("static cob_field %s%d\t= ", 
						CB_PREFIX_FIELD, f->id);
				output_field (cb_build_field_reference (f, NULL));
				output (";\t/* %s */\n", f->name);
				f->report_flag |= COB_REPORT_REF_EMITED;
			}
		}
		if (p->children) {
			output_report_sumed_field (p->children);
		}
	}
	if (p->sister) {
		output_report_sumed_field (p->sister);
	}
}

/* Report definition */

static void
output_report_control(struct cb_report *p, int id, cb_tree ctl, cb_tree nx)
{
	struct cb_field *s;
	struct cb_field *f;
	cb_tree	l,x;
	int	i,bfound,prvid,seq;

	x = CB_VALUE (ctl);
	s = cb_code_field(x);
	if(nx) {
		output_report_control(p, id, nx, CB_CHAIN(nx));
	}
	output_local("/* Report %s: CONTROL %s */\n",p->name,s->name);
	prvid = 0;
	for(i = 0; i < p->num_lines; i++) {
		if(p->line_ids[i]->report_control) {
			struct cb_field *c = cb_code_field (p->line_ids[i]->report_control);
			if(c == s) {
				f = p->line_ids[i];
				if(f->report_flag & COB_REPORT_CONTROL_HEADING) {
					output_local("/* CONTROL HEADING: %s */\n",s->name);
				} else if(f->report_flag & COB_REPORT_CONTROL_FOOTING) {
					output_local("/* CONTROL FOOTING: %s */\n",s->name);
				}
				output_local("static cob_report_control_ref %s%d = {",
						CB_PREFIX_REPORT_REF,p->line_ids[i]->id);
				if(prvid == 0) {
					output_local("NULL,");
				} else {
					output_local("&%s%d,",CB_PREFIX_REPORT_REF,prvid);
				}
				output_local("&%s%d",CB_PREFIX_REPORT_LINE,p->line_ids[i]->id);
				output_local("};\n");
				prvid = p->line_ids[i]->id;
			}
		}
	}
	output_local ("static cob_report_control   %s%d_%d\t= {", CB_PREFIX_REPORT_CONTROL,id,s->id);
	if(nx) {
		output_local("&%s%d_%d,",CB_PREFIX_REPORT_CONTROL,id,cb_code_field(CB_VALUE(nx))->id);
	} else {
		output_local("NULL,");
	}
	output_local ("\"%s\",",s->name);
	output_local("&%s%d,NULL,NULL",CB_PREFIX_FIELD,s->id);
	bfound = 0;
	/* CB_PREFIX_REPORT_REF */
	for(i= p->num_lines-1; i >= 0; i--) {
		if(p->line_ids[i]->report_control) {
			struct cb_field *c = cb_code_field (p->line_ids[i]->report_control);
			if(c == s) {
				bfound = 1;
				output_local(",&%s%d",CB_PREFIX_REPORT_REF,p->line_ids[i]->id);
				break;
			}
		}
	}
	if(!bfound) {
		printf("Control field %s is not referenced in report\n",s->name);
		output_local(",NULL");
	}
	seq = i = 0;
	for (l = p->controls; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		f = cb_code_field(x);
		i++;
		if(s == f) {
			seq = i;
			break;
		}
	}
	output_local(",%d,0,0,0,0",seq);
	output_local("};\n");
}

static void
output_report_def_fields (int bgn, int id, struct cb_field *f, struct cb_report *r)
{
	struct cb_field *n = NULL;
    	if(f == NULL)
	    return;
	if(bgn == 0
	&& (f->report_flag & COB_REPORT_LINE)) {	/* Start of next Line */
		return;
	}
	if (f->children
	&& f->storage == CB_STORAGE_REPORT
	&& f->report == r) {
		output_report_def_fields (0,id,n=f->children,r);
	}
	if (f->sister) {
		output_report_def_fields (0,id,n=f->sister,r);
	}
	if(f->report_source || f->report_control) {
		output_local("\t\t/* ");
		if(f->report_source) {
			struct cb_field *s = cb_code_field (f->report_source);
			if(s) output_local("SOURCE %s; ",s->name);
		} 
		if(f->report_control) {
			struct cb_field *s = cb_code_field (f->report_control);
			if(s) output_local("CONTROL %s; ",s->name);
		}
		output_local("*/\n");
	}
	output_local ("static cob_report_field %s%d\t= {", CB_PREFIX_REPORT_FIELD,f->id);
	if(n == NULL)
		output_local("NULL,");
	else
		output_local("&%s%d,",CB_PREFIX_REPORT_FIELD,n->id);
	output_local("&%s%d,",CB_PREFIX_FIELD,f->id);
	if(f->report_source) {
		output_param (f->report_source, 0);
	} else if(f->report_sum_counter) {
		output_local("/*SUM*/");
		output_param (f->report_sum_counter, 0);
	} else {
		output_local("NULL");	
	}
	output_local(",");	
	if(f->report_control) {
		output_param (f->report_control, 0);
	} else {
		output_local("NULL");	
	}
	output_local(",");	
	if (f->values) {
		struct cb_literal	*l;
		cb_tree	value = CB_VALUE (f->values);

		if (CB_TREE_TAG (value) == CB_TAG_LITERAL) {
			l = CB_LITERAL (value);
			if (l->all) {
				char *val = (char *)calloc(1, f->size + 2);
				memset(val,l->data[0],f->size);
				output_local("\"%.*s\",%d,",
						(int) f->size, val, (int)f->size);
				free((void*) val);
			} else {
				output_local("\"%.*s\",%d,",
						(int) l->size, l->data, (int)l->size);
			}
		} else {
			output_local("NULL,0,");	
		}
	} else {
		output_local("NULL,0,");	
	}
	output_local("%d,%d,%d,%d,%d",f->report_flag&~COB_REPORT_EMITED,
					f->report_line, f->report_column,
					f->step_count,f->next_group_line);
	output_local ("};\n");
}

static void
output_report_define_lines (int top, struct cb_field *f, struct cb_report *r)
{
	struct cb_field *n, *c;
	char	fname[64];
	int	fld_id;

    	if(f == NULL)
	    return;
	n = f->sister;
	c = f->children;
	if(n
	&& n->storage != CB_STORAGE_REPORT)
		n = NULL;
	if(n
	&& n->report != r)
		n = NULL;
	if(c
	&& c->storage != CB_STORAGE_REPORT)
		c = NULL;
	if(n
	&& (n->report_flag & COB_REPORT_LINE)) {
		output_report_define_lines(top, n, r);
	}
	if(c
	&& (c->report_flag & COB_REPORT_LINE)) {
		output_report_define_lines(0, c, r);
	} else {
		c = NULL;
	}
	if(!top)
		c = NULL;

	if(f->report_flag & COB_REPORT_LINE_EMITED)	/* Was this already emited? */
		return;
	f->report_flag |= COB_REPORT_LINE_EMITED;

	if(memcmp(f->name,"FILLER ",7) == 0) {
		if(f->report_flag & COB_REPORT_PAGE_HEADING) {
			strcpy(fname,"PAGE HEADING");
		} else if(f->report_flag & COB_REPORT_PAGE_FOOTING) {
			strcpy(fname,"PAGE HEADING");
		} else if(f->report_flag & COB_REPORT_HEADING) {
			strcpy(fname,"REPORT HEADING");
		} else if(f->report_flag & COB_REPORT_FOOTING) {
			strcpy(fname,"REPORT FOOTING");
		} else if(f->report_flag & COB_REPORT_CONTROL_HEADING) {
			strcpy(fname,"CONTROL HEADING");
		} else if(f->report_flag & COB_REPORT_CONTROL_FOOTING) {
			strcpy(fname,"CONTROL FOOTING");
		} else if(f->report_flag & COB_REPORT_CONTROL_FOOTING_FINAL) {
			strcpy(fname,"CONTROL FOOTING FINAL");
		} else if(f->report_flag & COB_REPORT_CONTROL_HEADING_FINAL) {
			strcpy(fname,"CONTROL HEADING FINAL");
		} else {
			strcpy(fname,"");
		}
		if(f->report_control) {
			sprintf(&fname[strlen(fname)]," %s",cb_code_field(f->report_control)->name);
		}
		if(strlen(fname) > 1)
			strcat(fname," of ");
	} else {
		sprintf(fname,"%s of ",f->name);
	}
	output_local("\n/* %s%s ",fname,r->name);
	if((f->report_flag & COB_REPORT_LINE)
	&& f->children
	&& (f->children->report_flag & COB_REPORT_LINE)) {
		printf("Warning: Ignoring nested LINE %s %d\n",
			(f->report_flag & COB_REPORT_LINE_PLUS)?"PLUS":"",
			f->report_line);
		f->report_line = 0;
		f->report_flag &= ~COB_REPORT_LINE_PLUS;
		f->report_flag &= ~COB_REPORT_LINE;
	}
	if(f->report_flag & COB_REPORT_LINE)
		output_local("LINE %s %d ",
			(f->report_flag & COB_REPORT_LINE_PLUS)?"PLUS":"",
			f->report_line);
	output_local("*/\n");
	fld_id = 0;
	if((f->report_flag & COB_REPORT_LINE)
	&& f->children != NULL) {
		output_report_def_fields (1,f->id,f->children,r);
		fld_id = f->children->id;
	} else if(f->children == NULL) {
		if(f->report_flag & COB_REPORT_LINE) {
			output_report_def_fields (1,f->id,f,r);
			fld_id = f->id;
		}
	}
	output_local ("static cob_report_line  %s%d\t= {", CB_PREFIX_REPORT_LINE,f->id);
	if(n == NULL)
		output_local("NULL,");
	else
		output_local("&%s%d,",CB_PREFIX_REPORT_LINE,n->id);
	if(c == NULL)
		output_local("NULL,");
	else
		output_local("&%s%d,",CB_PREFIX_REPORT_LINE,c->id);
	if(fld_id != 0) 
		output_local("&%s%d,",CB_PREFIX_REPORT_FIELD,fld_id);
	else
		output_local("NULL,");
	if(f->report_control) {
		output_param (f->report_control, 0);
	} else {
		output_local("NULL");	
	}
	output_local(",%d",f->report_decl_id);
	if(f->report_decl_id)
		output_local("/* Declaratives */");
	output_local(",%d,%d,%d,%d",f->report_flag&~COB_REPORT_EMITED,
				f->report_line, f->step_count,f->next_group_line);
	output_local(",%d,0",f->report_flag&~COB_REPORT_EMITED);
	output_local ("};\n");
}

static int sum_prv = 0;
static int sum_nxt = 0;
static int r_ctl_id = 0;

/* Find data field for given internal SUM counter */
struct cb_field *
get_sum_data_field(struct cb_report *r, struct cb_field *f)
{
	int	k;
	for(k=0; k < r->num_sums; k++) {
		if(r->sums[k*2 + 0] == f)
			return r->sums[k*2 + 1];
		if(r->sums[k*2 + 1] == f)
			return r->sums[k*2 + 0];
	}
	return NULL;
}

/*
 * Generate list of SUM counters
 */
static void
output_report_sum_counters (int top, struct cb_field *f, struct cb_report *r)
{
	struct cb_field *n, *c, *p, *z;
	cb_tree	l,x;
	char	fname[64];
	int	rsid,rsseq,rsprv;
	int	ctl_foot,sub_ttl,cross_foot;

    	if(f == NULL)
	    return;
	n = f->sister;
	c = f->children;
	if(n
	&& n->storage != CB_STORAGE_REPORT)
		n = NULL;
	if(n
	&& n->report != r)
		n = NULL;
	if(c
	&& c->storage != CB_STORAGE_REPORT)
		c = NULL;
	if(n) {
		output_report_sum_counters(top, n, r);
	}
	if(c) {
		output_report_sum_counters(0, c, r);
	} else {
		c = NULL;
	}
	if(!top)
		c = NULL;

	if(f->report_sum_list == NULL)
		return;
	if(f->report_flag & COB_REPORT_SUM_EMITED)	/* Was this already emited? */
		return;
	f->report_flag |= COB_REPORT_SUM_EMITED;

	if(memcmp(f->name,"FILLER ",7) == 0) {
		if(f->report_flag & COB_REPORT_PAGE_HEADING) {
			strcpy(fname,"PAGE HEADING");
		} else if(f->report_flag & COB_REPORT_PAGE_FOOTING) {
			strcpy(fname,"PAGE HEADING");
		} else if(f->report_flag & COB_REPORT_CONTROL_HEADING) {
			strcpy(fname,"CONTROL HEADING");
		} else if(f->report_flag & COB_REPORT_CONTROL_FOOTING) {
			strcpy(fname,"CONTROL FOOTING");
		} else if(f->report_flag & COB_REPORT_CONTROL_FOOTING_FINAL) {
			strcpy(fname,"CONTROL FOOTING FINAL");
		} else if(f->report_flag & COB_REPORT_CONTROL_HEADING_FINAL) {
			strcpy(fname,"CONTROL HEADING FINAL");
		} else {
			strcpy(fname,"");
		}
		if(f->report_control) {
			sprintf(&fname[strlen(fname)]," %s",cb_code_field(f->report_control)->name);
		}
	} else {
		sprintf(fname,"%s",f->name);
	}
	output_local("\n/* %s SUM ",fname);
	for (l = f->report_sum_list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		output_local("%s ",cb_code_field(x)->name);
	}
	if(f->report_flag & COB_REPORT_RESET_FINAL)
		output_local(" RESET ON FINAL ");
	if(f->report_reset) {
		x = CB_VALUE(f->report_reset);
		output_local(" RESET ON %s ",cb_code_field(x)->name);
	}
	output_local("*/\n");
	ctl_foot = sub_ttl = cross_foot = 0;
	rsid = f->id;
	rsseq = rsprv = 0;
	for (l = f->report_sum_list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		output_local("static cob_report_sum %s%d_%d = {",CB_PREFIX_REPORT_SUM,rsid,++rsseq);
		if(rsprv) {
			output_local("&%s%d_%d,",CB_PREFIX_REPORT_SUM,rsid,rsprv);
		} else {
			output_local("NULL,");
		}
		z = get_sum_data_field(r, cb_code_field(x));
		if(z) {
			output_local("&%s%d",CB_PREFIX_FIELD, z->id);
			sub_ttl = 1;
		} else {
			output_local("&%s%d",CB_PREFIX_FIELD, cb_code_field(x)->id);
		}
		output_local ("};");
		output_local ("\n");
		rsprv = rsseq;
	}
	output_local ("static cob_report_sum_ctr %s%d = {", CB_PREFIX_REPORT_SUM_CTR,++sum_nxt);
	if(sum_prv) {
		output_local("&%s%d,",CB_PREFIX_REPORT_SUM_CTR,sum_prv);
	} else {
		output_local("NULL,");
	}
	output_local ("\"%s\",",fname);
	output_local("&%s%d_%d,",CB_PREFIX_REPORT_SUM,rsid,rsprv);
	if(f->report_sum_counter) {
		output_local("&%s%d,",CB_PREFIX_FIELD, cb_code_field(CB_VALUE(f->report_sum_counter))->id);
	} else {
		output_local("NULL,");
	}
	z = get_sum_data_field(r, cb_code_field(CB_VALUE(f->report_sum_counter)));
	if(z) {
		output_local("&%s%d,",CB_PREFIX_FIELD, z->id);
	} else {
		output_local("NULL,");
	}
	for(p=f; p; p = p->parent) {
		if(p->report_control) {
			x = CB_VALUE(p->report_control);
			output_local("&%s%d_%d,",CB_PREFIX_REPORT_CONTROL,r_ctl_id,cb_code_field(x)->id);
			break;
		} else if(p->report_flag & COB_REPORT_CONTROL_FOOTING_FINAL) {
			ctl_foot = 1;
			output_local("NULL,");
			break;
		}
	}
	if(p == NULL) {
		output_local("NULL, /* No CONTROL field */");
	}
	if(f->report_flag & COB_REPORT_RESET_FINAL)
		output_local("1");
	else
		output_local("0");
	output_local(",%d,%d,%d",ctl_foot,sub_ttl,cross_foot);
	output_local ("};\n");
	sum_prv = sum_nxt;
}

static void
output_report_definition (struct cb_report *p, struct cb_report *n)
{
	int	i;
	struct cb_field *s = NULL;
	cb_tree	l,x;

	output_local("\n");
	for(i= p->num_lines-1; i >= 0; i--) {
		if(p->line_ids[i]->level == 1)
			output_report_define_lines(1,p->line_ids[i], p);
	}
	output_local ("\n");
	if(p->controls) {
		for (l = p->controls; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			s = cb_code_field(x);
			s->count++;
		}
		output_report_control(p,++r_ctl_id,p->controls,CB_CHAIN(p->controls));
		output_local ("\n");
	}
	sum_prv = 0;
	for(i= p->num_lines-1; i >= 0; i--) {
		if(p->line_ids[i]->level == 1)
			output_report_sum_counters(1,p->line_ids[i], p);
	}

	output_local ("\n");
	output_local ("static cob_report %s%s = {\n", CB_PREFIX_REPORT,p->cname);
	output_local ("\t\t\"%s\",\n\t\t",p->name);
	if(n != NULL) {
		output_local ("&%s%s,", CB_PREFIX_REPORT, n->cname);
	} else {
		output_local ("NULL,");
	}
	output_local ("NULL,");	/* Address set at run-time */
	if (p->page_counter) {
		output_param (p->page_counter, 0);
		output_local (",");
	} else {
		output_local("NULL,");
	}
	if (p->line_counter) {
		output_param (p->line_counter, 0);
		output_local (",");
	} else {
		output_local("NULL,");
	}
	if(p->num_lines > 0) {
		output_local ("&%s%d,",CB_PREFIX_REPORT_LINE,p->line_ids[0]->id);
	} else {
		output_local("NULL,");
	}
	if(p->controls) {
		x = CB_VALUE (p->controls);
		s = cb_code_field(x);
		output_local ("&%s%d_%d,",CB_PREFIX_REPORT_CONTROL,r_ctl_id,s->id);
	} else {
		output_local("NULL,");
	}
	if(sum_prv > 0) {
		output_local("&%s%d,",CB_PREFIX_REPORT_SUM_CTR,sum_prv);
	} else {
		output_local("NULL,");
	}
	output_local ("\n");
	output_local ("\t\t%d,%d,%d,%d,%d,%d,%d,\n",
			p->lines,p->columns,p->heading,
			p->first_detail,p->last_control,
			p->last_detail,p->footing);
	output_local ("\t\t0,0,0,0,0,");
	output_local ("%d,%d\n",p->control_final,p->global);
	output_local ("};\n");
}

static void
output_report_list(cb_tree	l, cb_tree n)
{
	cb_tree nl;
	struct cb_report	*rep, *nxrep;

	rep = CB_REPORT(CB_VALUE(l));
	if(n != NULL) {
		nxrep = CB_REPORT(CB_VALUE(n));
	} else {
		nxrep = NULL;
	}
	nl = CB_CHAIN (l);
	output_emit_field(rep->line_counter,NULL);
	output_emit_field(rep->page_counter,NULL);
	if(nl) {
	    output_report_list(nl, CB_CHAIN (nl));
	}
	output_report_definition (rep, nxrep);
}

static void
output_report_init (struct cb_report *rep)
{
	output_prefix ();
	output ("cob_set_report (&%s%s, ", CB_PREFIX_REPORT,rep->cname);

	if (rep->file) {
		output ("%s%s", CB_PREFIX_FILE, rep->file->cname);
	} else {
		output ("NULL");
	}
	output (");\n");

}

/* Alphabet-name */

static int
literal_value (cb_tree x)
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
	} else {
		return CB_LITERAL (x)->data[0];
	}
}

static void
output_alphabet_name_definition (struct cb_alphabet_name *p)
{
	int		i;

	if (p->alphabet_type != CB_ALPHABET_CUSTOM) {
		return;
	}

	/* Output the table */
	output_local ("static const unsigned char %s%s[256] = {\n",
		      CB_PREFIX_SEQUENCE, p->cname);
	for (i = 0; i < 256; i++) {
		if (i == 255) {
			output_local (" %d", p->values[i]);
		} else {
			output_local (" %d,", p->values[i]);
		}
		if (i % 16 == 15) {
			output_local ("\n");
		}
	}
	output_local ("};\n");
	i = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
	output_local ("static cob_field %s%s = { 256, (cob_u8_ptr)%s%s, &%s%d };\n",
		CB_PREFIX_FIELD, p->cname,
		CB_PREFIX_SEQUENCE, p->cname,
		CB_PREFIX_ATTR, i);
	output_local ("\n");
}

/* Class definition */

static void
output_class_name_definition (struct cb_class_name *p)
{
	cb_tree		l;
	cb_tree		x;
	unsigned char	*data;
	size_t		i;
	size_t		size;
	int		n;
	int		lower;
	int		upper;
	int		vals[256];

	output_line ("static int");
	output_line ("%s (cob_field *f)", p->cname);
	output_indent ("{");
	output_line ("size_t\ti;\n");
	output_line ("for (i = 0; i < f->size; i++)");
	output_indent ("{");
	output_line ("switch (f->data[i]) {");
	memset (vals, 0, sizeof(vals));
	for (l = p->list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (CB_PAIR_P (x)) {
			lower = literal_value (CB_PAIR_X (x));
			upper = literal_value (CB_PAIR_Y (x));
			for (n = lower; n <= upper; ++n) {
				vals[n] = 1;
			}
		} else {
			if (CB_NUMERIC_LITERAL_P (x)) {
				vals[literal_value (x)] = 1;
			} else if (x == cb_space) {
				vals[' '] = 1;
			} else if (x == cb_zero) {
				vals['0'] = 1;
			} else if (x == cb_quote) {
				if (cb_flag_apostrophe) {
					vals['\''] = 1;
				} else {
					vals['"'] = 1;
				}
			} else if (x == cb_null) {
				vals[0] = 1;
			} else if (x == cb_low) {
				vals[0] = 1;
			} else if (x == cb_high) {
				vals[255] = 1;
			} else {
				size = CB_LITERAL (x)->size;
				data = CB_LITERAL (x)->data;
				for (i = 0; i < size; i++) {
					vals[data[i]] = 1;
				}
			}
		}
	}
	for (i = 0; i < 256; ++i) {
		if (vals[i]) {
			output_line ("case %d:", (int)i);
		}
	}
	output_line ("    break;");
	output_line ("default:");
	output_line ("    return 0;");
	output_line ("}");
	output_indent ("}");
	output_line ("return 1;");
	output_indent ("}");
	output_newline ();
}

static void
output_initial_values (struct cb_field *f)
{
	struct cb_field	*p;
	cb_tree		x;

	for (p = f; p; p = p->sister) {
		x = cb_build_field_reference (p, NULL);
		if (p->flag_item_based) {
			continue;
		}
		/* For special registers */
		if (p->flag_no_init && !p->count) {
			continue;
		}
		output_stmt (cb_build_initialize (x, cb_true, NULL, 1, 0, 0));
	}
}

static void
output_error_handler (struct cb_program *prog)
{
	struct handler_struct	*hstr;
	size_t			seen;
	int			i;
	int			n;
	int			parmnum;

	output_newline ();
	seen = 0;
	for (i = COB_OPEN_INPUT; i <= COB_OPEN_EXTEND; i++) {
		if (prog->global_handler[i].handler_label) {
			seen = 1;
			break;
		}
	}
	output_stmt (cb_standard_error_handler);
	output_newline ();
	if (seen) {
		output_line ("switch (cob_glob_ptr->cob_error_file->last_open_mode)");
		output_indent ("{");
		for (i = COB_OPEN_INPUT; i <= COB_OPEN_EXTEND; i++) {
			hstr = &prog->global_handler[i];
			if (hstr->handler_label) {
				output_line ("case %d:", i);
				output_indent ("{");
				if (prog == hstr->handler_prog) {
					output_perform_call (hstr->handler_label,
							     hstr->handler_label);
				} else {
					output_prefix ();
					if (hstr->handler_prog->nested_level) {
						output ("%s_%d_ (%d",
							hstr->handler_prog->program_id,
							hstr->handler_prog->toplev_count,
							hstr->handler_label->id);
					} else {
						output ("%s_ (%d",
							hstr->handler_prog->program_id,
							hstr->handler_label->id);
					}
					parmnum = cb_list_length (hstr->handler_prog->parameter_list);
					for (n = 0; n < parmnum; n++) {
						output (", NULL");
					}
					output (");\n");
				}
				output_line ("break;");
				output_indent ("}");
			}
		}
		output_line ("default:");
		output_indent ("{");
	}
	output_line ("if (!(cob_glob_ptr->cob_error_file->flag_select_features & COB_SELECT_FILE_STATUS)) {");
	output_line ("\tcob_fatal_error (COB_FERROR_FILE);");
	output_line ("}");
	if (seen) {
		output_line ("break;");
		output_indent ("}");
		output_indent ("}");
	}
	output_perform_exit (CB_LABEL (cb_standard_error_handler));
	output_newline ();
	output_line ("/* Fatal error if reached */");
	output_line ("cob_fatal_error (COB_FERROR_CODEGEN);");
	output_newline ();
}

static void
output_module_init (struct cb_program *prog)
{
#if	0	/* Module comments */
	output ("/* Next pointer, Parameter list pointer, Module name, */\n");
	output ("/* Module formatted date, Module source, */\n");
	output ("/* Module entry, Module cancel, */\n");
	output ("/* Collating, CRT status, CURSOR, */\n");
	output ("/* Module reference count, Module path, Module active, */\n");
	output ("/* Module date, Module time, */\n");
	output ("/* Module type, Number of USING params, Return type */\n");
	output ("/* Current param count */\n");
	output ("/* Display sign, Decimal point, Currency symbol, */\n");
	output ("/* Numeric separator, File name mapping, Binary truncate, */\n");
	output ("/* Alternate numeric display, Host sign, No physical cancel */\n");
	output ("/* Flag main program, Fold call, Exit after CALL */\n\n");
#endif

	/* Do not initialize next pointer, parameter list pointer, param count */
	output_line ("/* Initialize module structure */");
	output_line ("module->module_name = \"%s\";", prog->orig_program_id);
	output_line ("module->module_formatted_date = COB_MODULE_FORMATTED_DATE;");
	output_line ("module->module_source = COB_SOURCE_FILE;");
	if (!prog->nested_level) {
		output_line ("module->module_entry.funcptr = (void *(*)())%s;",
			     prog->program_id);
		if (prog->prog_type == CB_FUNCTION_TYPE) {
			output_line ("module->module_cancel.funcptr = NULL;");
		} else {
			output_line ("module->module_cancel.funcptr = (void *(*)())%s_;",
				     prog->program_id);
		}
	} else {
		output_line ("module->module_entry.funcvoid = NULL;");
		output_line ("module->module_cancel.funcvoid = NULL;");
	}

	if (prog->collating_sequence) {
		output_prefix ();
		output ("module->collating_sequence = ");
		output_param (cb_ref (prog->collating_sequence), -1);
		output (";\n");
	} else {
		output_line ("module->collating_sequence = NULL;");
	}
	if (prog->crt_status && cb_code_field (prog->crt_status)->count) {
		output_prefix ();
		output ("module->crt_status = ");
		output_param (cb_ref (prog->crt_status), -1);
		output (";\n");
	} else {
		output_line ("module->crt_status = NULL;");
	}
	if (prog->cursor_pos) {
		output_prefix ();
		output ("module->cursor_pos = ");
		output_param (cb_ref (prog->cursor_pos), -1);
		output (";\n");
	} else {
		output_line ("module->cursor_pos = NULL;");
	}
	if (!cobc_flag_main && non_nested_count > 1) {
		output_line ("module->module_ref_count = &cob_reference_count;");
	} else {
		output_line ("module->module_ref_count = NULL;");
	}
	output_line ("module->module_path = &cob_module_path;");
	output_line ("module->module_active = 0;");
	output_line ("module->module_date = COB_MODULE_DATE;");
	output_line ("module->module_time = COB_MODULE_TIME;");
	output_line ("module->module_type = %d;", (int)prog->prog_type);
	output_line ("module->module_param_cnt = %d;", prog->num_proc_params);
	output_line ("module->module_returning = 0;");
	output_line ("module->ebcdic_sign = %d;", cb_ebcdic_sign);
	output_line ("module->decimal_point = '%c';", prog->decimal_point);
	output_line ("module->currency_symbol = '%c';", prog->currency_symbol);
	output_line ("module->numeric_separator = '%c';", prog->numeric_separator);
	output_line ("module->flag_filename_mapping = %d;", cb_filename_mapping);
	output_line ("module->flag_binary_truncate = %d;", cb_binary_truncate);
	output_line ("module->flag_pretty_display = %d;", cb_pretty_display);
	output_line ("module->flag_host_sign = %d;", cb_host_sign);
	output_line ("module->flag_no_phys_canc = %d;", no_physical_cancel);
	output_line ("module->flag_main = %d;", cobc_flag_main);
	output_line ("module->flag_fold_call = %d;", cb_fold_call);
	output_line ("module->flag_exit_program = 0;");
	output_newline ();
}

static void
output_internal_function (struct cb_program *prog, cb_tree parameter_list)
{
	cb_tree			l;
	cb_tree			l2;
	struct cb_field		*f;
	struct cb_program	*next_prog;
	struct cb_file		*fl;
	struct cb_report	*rep;
	char			*p;
	struct label_list	*pl;
	struct cb_alter_id	*cpl;
	struct call_list	*clp;
	struct base_list	*bl;
	FILE			*savetarget;
	const char		*s;
	int			i;
	cob_u32_t		inc;
	int			parmnum;
	int			seen;
	int			anyseen;

	/* Program function */
#if	0	/* RXWRXW USERFUNC */
	if (prog->prog_type == CB_FUNCTION_TYPE) {
		output ("static cob_field *\n%s_ (const int entry, cob_field **cob_parms",
			prog->program_id);
#else
	if (prog->prog_type == CB_FUNCTION_TYPE) {
		output ("static cob_field *\n%s_ (const int entry",
			prog->program_id);
#endif
	} else if (!prog->nested_level) {
		output ("static int\n%s_ (const int entry",
			prog->program_id);
	} else {
		output ("static int\n%s_%d_ (const int entry",
			prog->program_id, prog->toplev_count);
	}
	parmnum = 0;
#if	0	/* RXWRXW USERFUNC */
	if (!prog->flag_chained && prog->prog_type != CB_FUNCTION_TYPE) {
#else
	if (!prog->flag_chained) {
#endif
		for (l = parameter_list; l; l = CB_CHAIN (l)) {
			if (l == parameter_list) {
				output (", ");
			}
			if (parmnum && !(parmnum % 2)) {
				output ("\n\t");
			}
			output ("cob_u8_t *%s%d",
				CB_PREFIX_BASE, cb_code_field (CB_VALUE (l))->id);
			if (CB_CHAIN (l)) {
				output (", ");
			}
			parmnum++;
		}
	}
	output (")\n");
	output_indent ("{");

	/* Program local variables */
	output_line ("/* Program local variables */");
	output_line ("#include \"%s\"", prog->local_include->local_name);
	output_newline ();

	/* Alphabet-names */
	if (prog->alphabet_name_list) {
		for (l = prog->alphabet_name_list; l; l = CB_CHAIN (l)) {
			output_alphabet_name_definition (CB_ALPHABET_NAME (CB_VALUE (l)));
		}
	}

	/* Module initialization indicator */
	output_local ("/* Module initialization indicator */\n");
	output_local ("static unsigned int\tinitialized = 0;\n\n");

	output_local ("/* Module structure pointer */\n");
#if	0	/* RXWRXW - MODULE */
	if (prog->flag_recursive) {
		output_local ("cob_module\t\t*module;\n\n");
	} else {
		output_local ("static cob_module\tmodule_data;\n");
		output_local ("static cob_module\t*module = &module_data;\n\n");
	}
#else
	if (prog->flag_recursive) {
		output_local ("cob_module\t\t*module = NULL;\n\n");
	} else {
		output_local ("static cob_module\t*module = NULL;\n\n");
	}
#endif

#if	1	/* RXWRXW - GLOBPTR */
	output_local ("/* Global variable pointer */\n");
	output_local ("cob_global\t\t*cob_glob_ptr;\n\n");
#endif

	/* Decimal structures */
	if (prog->decimal_index_max) {
		output_local ("/* Decimal structures */\n");
		for (i = 0; i < prog->decimal_index_max; i++) {
			output_local ("cob_decimal\t*d%d;\n", i);
		}
		output_local ("\n");
	}

	/* External items */
	seen = 0;
	for (f = prog->working_storage; f; f = f->sister) {
		if (f->flag_external) {
			if (f->flag_is_global) {
				bl = cobc_parse_malloc (sizeof (struct base_list));
				bl->f = f;
				bl->curr_prog = excp_current_program_id;
				bl->next = globext_cache;
				globext_cache = bl;
				continue;
			}
			if (!seen) {
				seen = 1;
				output_local ("/* EXTERNAL items */\n");
			}
			output_local ("static unsigned char\t*%s%d = NULL;",
				      CB_PREFIX_BASE, f->id);
			output_local ("  /* %s */\n", f->name);
		}
	}
	if (seen) {
		output_local ("\n");
	}
	for (l = prog->file_list; l; l = CB_CHAIN (l)) {
		f = CB_FILE (CB_VALUE (l))->record;
		if (f->flag_external) {
			if (f->flag_is_global) {
				bl = cobc_parse_malloc (sizeof (struct base_list));
				bl->f = f;
				bl->curr_prog = excp_current_program_id;
				bl->next = globext_cache;
				globext_cache = bl;
				continue;
			}
			output_local ("static unsigned char\t*%s%d = NULL;",
				      CB_PREFIX_BASE, f->id);
			output_local ("  /* %s */\n", f->name);
		}
	}

	/* Files */
	if (prog->file_list) {
		i = 0;
		for (l = prog->file_list; l; l = CB_CHAIN (l)) {
			i += output_file_allocation (CB_FILE (CB_VALUE (l)));
		}
		if (i) {
			output_local ("\n/* LINAGE pointer */\n");
			output_local ("static cob_linage\t\t*lingptr;\n");
		}
	}

	/* BASED working-storage */
	i = 0;
	for (f = prog->working_storage; f; f = f->sister) {
		if (f->redefines) {
			continue;
		}
		if (f->flag_item_based) {
			if (!i) {
				i = 1;
				output_local("\n/* BASED WORKING-STORAGE SECTION */\n");
			}
			output_local ("static unsigned char\t*%s%d = NULL; /* %s */\n",
				CB_PREFIX_BASE, f->id, f->name);
		}
	}
	if (i) {
		output_local ("\n");
	}

	/* BASED local-storage */
	i = 0;
	for (f = prog->local_storage; f; f = f->sister) {
		if (f->redefines) {
			continue;
		}
		if (f->flag_item_based) {
			if (!i) {
				i = 1;
				output_local("\n/* BASED LOCAL-STORAGE */\n");
			}
			output_local ("static unsigned char\t*%s%d = NULL; /* %s */\n",
				CB_PREFIX_BASE, f->id, f->name);
		}
	}
	if (i) {
		output_local ("\n");
	}

#if	0	/* RXWRXW USERFUNC */
	if (prog->prog_type == CB_FUNCTION_TYPE) {
		/* USING parameters for user FUNCTION */
		seen = 0;
		for (l = parameter_list; l; l = CB_CHAIN (l)) {
			f = cb_code_field (CB_VALUE (l));
			if (!seen) {
				seen = 1;
				output_local ("\n/* USING parameters */\n");
			}
			output_local ("unsigned char\t*%s%d = NULL;  /* %s */\n",
				     CB_PREFIX_BASE, f->id, f->name);
		}
		if (seen) {
			output_local ("\n");
		}
	}
#endif

	/* Dangling linkage section items */
	seen = 0;
	for (f = prog->linkage_storage; f; f = f->sister) {
		if (f->redefines) {
			continue;
		}
		for (l = parameter_list; l; l = CB_CHAIN (l)) {
			if (f == cb_code_field (CB_VALUE (l))) {
				break;
			}
		}
		if (l == NULL) {
			if (!seen) {
				seen = 1;
				output_local ("\n/* LINKAGE SECTION (Items not referenced by USING clause) */\n");
			}
			if (!f->flag_is_returning) {
				output_local ("static ");
			}
			output_local ("unsigned char\t*%s%d = NULL;  /* %s */\n",
				     CB_PREFIX_BASE, f->id, f->name);
		}
	}
	if (seen) {
		output_local ("\n");
	}

	/* Screens */
	if (prog->screen_storage) {
		optimize_defs[COB_SET_SCREEN] = 1;
		output_local ("\n/* Screens */\n\n");
		output_screen_definition (prog->screen_storage);
		output_local ("\n");
	}

	if (prog->report_storage) {
		optimize_defs[COB_SET_REPORT] = 1;
	}

	/* ANY LENGTH items */
	i = 0;
	anyseen = 0;
	for (l = parameter_list; l; l = CB_CHAIN (l), i++) {
		f = cb_code_field (CB_VALUE (l));
		if (f->flag_any_length) {
			anyseen = 1;
#if	0	/* RXWRXW - Any */
			output_local ("/* ANY LENGTH variable */\n");
			output_local ("cob_field\t\t*cob_anylen;\n\n");
#endif
			break;
		}
	}

	/* Save variables for global callback */
	if (prog->flag_global_use && parameter_list) {
		output_local ("/* Parameter save */\n");
		for (l = parameter_list; l; l = CB_CHAIN (l)) {
			f = cb_code_field (CB_VALUE (l));
			output_local ("static unsigned char\t*save_%s%d;\n",
				CB_PREFIX_BASE, f->id);
		}
		output_local ("\n");
	}

	/* Runtime DEBUGGING MODE variable */
	if (prog->flag_debugging) {
		output_line ("char\t\t*s;");
		output_newline ();
	}

	/* Start of function proper */
	output_line ("/* Start of function code */");
	output_newline ();

	/* CANCEL callback */
	if (prog->prog_type == CB_PROGRAM_TYPE) {
		output_line ("/* CANCEL callback */");
		output_line ("if (unlikely(entry < 0)) {");
		output_line ("\tgoto P_cancel;");
		output_line ("}");
		output_newline ();
	}

#if	0	/* RXWRXW - MODULEALL */
	/* Recursive module initialization */
	if (prog->flag_recursive) {
		output_line ("/* Allocate cob_module structure */");
		output_line ("module = cob_malloc (sizeof(cob_module));");
		output_newline ();
	}
#endif


	output_line ("/* Check initialized, check module allocated, */");
	output_line ("/* set global pointer, */");
	output_line ("/* push module stack, save call parameter count */");
#if	0	/* RXWRXW - MODULEALL */
	output_line ("cob_module_enter (module, &cob_glob_ptr, %d);",
		      cb_flag_implicit_init);
#else
	output_line ("cob_module_enter (&module, &cob_glob_ptr, %d);",
		      cb_flag_implicit_init);
#endif
	output_newline ();

	/* Recursive module initialization */
	if (prog->flag_recursive) {
		output_module_init (prog);
	}

	output_line ("/* Set address of module parameter list */");
	if (cb_flag_stack_on_heap || prog->flag_recursive) {
		if (prog->max_call_param) {
			i = prog->max_call_param;
		} else {
			i = 1;
		}
		output_line ("cob_procedure_params = cob_malloc (%dU * sizeof(void *));",
			     i);
	}
	output_line ("module->cob_procedure_params = cob_procedure_params;");
	output_newline ();

#if	0	/* RXWRXW USERFUNC */
	if (prog->prog_type == CB_FUNCTION_TYPE) {
		parmnum = 0;
		for (l = parameter_list; l; l = CB_CHAIN (l), parmnum++) {
			f = cb_code_field (CB_VALUE (l));
			output_line ("if (cob_parms[%d])", parmnum);
			output_line (" %s%d = cob_parms[%d]->data;",
				     CB_PREFIX_BASE, f->id, parmnum);
			output_line ("else");
			output_line (" %s%d = NULL;",
				     CB_PREFIX_BASE, f->id);
		}
		output_newline ();
	}
#endif

	output_line ("/* Set frame stack pointer */");
	if (cb_flag_stack_on_heap || prog->flag_recursive) {
		if (prog->flag_recursive && cb_stack_size == 255) {
			i = 63;
		} else {
			i = cb_stack_size;
		}
		output_line ("frame_stack = cob_malloc (%dU * sizeof(struct cob_frame));",
			     i);
		output_line ("frame_ptr = frame_stack;");
		if (cb_flag_stack_check) {
			output_line ("frame_overflow = frame_ptr + %d - 1;",
				     i);
		}
	} else {
		output_line ("frame_ptr = frame_stack;");
		output_line ("frame_ptr->perform_through = 0;");
		if (cb_flag_stack_check) {
			output_line ("frame_overflow = frame_ptr + %d - 1;",
				     cb_stack_size);
		}
	}
	output_newline ();

	/* Initialization */
	output_line ("/* Initialize program */");
	output_line ("if (unlikely(initialized == 0)) {");
	output_line ("\tgoto P_initialize;");
	if (prog->flag_chained) {
		output_line ("} else {");
		output_line ("\tcob_fatal_error (COB_FERROR_CHAINING);");
	}
	output_line ("}");
	output_line ("P_ret_initialize:");
	output_newline ();

	/* Set up LOCAL-STORAGE size */
	if (prog->local_storage) {
		for (f = prog->local_storage; f; f = f->sister) {
			if (f->flag_item_based || f->flag_local_alloced) {
				continue;
			}
			if (f->redefines) {
				continue;
			}
			if (f->flag_item_78) {
				cobc_abort_pr (_("Unexpected CONSTANT item"));
				COBC_ABORT ();
			}
			f->flag_local_storage = 1;
			f->flag_local_alloced = 1;
			f->mem_offset = local_mem;
			/* Round up to COB_MALLOC_ALIGN + 1 bytes */
			/* Caters for current types */
			local_mem += ((f->memory_size + COB_MALLOC_ALIGN) &
					~COB_MALLOC_ALIGN);
		}
	}

	if (prog->decimal_index_max) {
		output_line ("/* Allocate decimal numbers */");
		output_prefix ();
		if (prog->flag_recursive) {
			output ("cob_decimal_push (%d", prog->decimal_index_max);
		} else {
			output ("cob_decimal_alloc (%d", prog->decimal_index_max);
		}
		for (i = 0; i < prog->decimal_index_max; i++) {
			output (", &d%d", i);
		}
		output (");\n");
		output_newline ();
	}

	/* Global entry dispatch */
	if (prog->global_list) {
		output_line ("/* Global entry dispatch */");
		output_newline ();
		for (l = prog->global_list; l; l = CB_CHAIN (l)) {
			output_line ("if (unlikely(entry == %d)) {",
					CB_LABEL (CB_VALUE (l))->id);
			i = 0;
			if (local_mem) {
				output_line ("\tcob_local_ptr = cob_local_save;");
			}
			for (l2 = parameter_list; l2; l2 = CB_CHAIN (l2), i++) {
				f = cb_code_field (CB_VALUE (l2));
				output_line ("\t%s%d = save_%s%d;",
					CB_PREFIX_BASE, f->id,
					CB_PREFIX_BASE, f->id);
			}
			output_line ("\tgoto %s%d;",
					CB_PREFIX_LABEL,
					CB_LABEL (CB_VALUE (l))->id);
			output_line ("}");
		}
		output_newline ();
	}

	if (cb_flag_recursive && !prog->flag_recursive) {
		output_line ("/* Check active count */");
		output_line ("if (unlikely(module->module_active)) {");
		output_line ("\tcob_fatal_error (COB_FERROR_RECURSIVE);");
		output_line ("}");
	}
	if (!prog->flag_recursive) {
		output_line ("/* Increment module active */");
		output_line ("module->module_active++;");
		output_newline ();
	}

	if (!cobc_flag_main && non_nested_count > 1) {
		output_line ("/* Increment module reference count */");
		output_line ("cob_reference_count++;");
		output_newline ();
	}

	/* Initialize W/S unconditionally when INITIAL program */
	if (prog->flag_initial) {
		output_line ("/* Initalize INITIAL program WORKING-STORAGE */");
		output_initial_values (prog->working_storage);
		output_newline ();
		for (l = prog->file_list; l; l = CB_CHAIN (l)) {
			output_file_initialization (CB_FILE (CB_VALUE (l)));
		}
		output_newline ();
	}

	/* Allocate / initialize LOCAL storage */
	if (prog->local_storage) {
		if (local_mem) {
			output_line ("/* Allocate LOCAL storage */");
			output_line ("cob_local_ptr = cob_malloc (%dU);",
				     local_mem);
			if (prog->flag_global_use) {
				output_line ("cob_local_save = cob_local_ptr;");
			}
		}
		output_newline ();
		output_line ("/* Initialialize LOCAL storage */");
		output_initial_values (prog->local_storage);
		output_newline ();
	}

	/* Call parameters */
	if (cb_code_field (prog->cb_call_params)->count) {
		output_line ("/* Set NUMBER-OF-CALL-PARAMETERS */");
		output_prefix ();
		output_integer (prog->cb_call_params);
		output (" = cob_glob_ptr->cob_call_params;\n");
		output_newline ();
	}

#if	1	/* RXWRXW - Save call params */
	output_line ("/* Save number of call params */");
	output_line ("module->module_num_params = cob_glob_ptr->cob_call_params;");
	output_newline ();
#endif

	/* Set up ANY length items */
	i = 0;
	if (anyseen) {
		output_line ("/* Initialize ANY LENGTH parameters */");
	}
	for (l = parameter_list; l; l = CB_CHAIN (l), i++) {
		f = cb_code_field (CB_VALUE (l));
		if (f->flag_any_length) {
			/* Force field cache */
			savetarget = output_target;
			output_target = NULL;
			output_param (CB_VALUE (l), i);
			output_target = savetarget;

			output_line ("if (cob_glob_ptr->cob_call_params > %d && %s%d%s)",
				i, "module->next->cob_procedure_params[",
				i, "]");
			if (f->flag_any_numeric) {
				/* Copy complete structure */
				output_line ("  %s%d = *(%s%d%s);",
					     CB_PREFIX_FIELD, f->id,
					     "module->next->cob_procedure_params[",
					     i, "]");
			} else {
				/* Copy size */
				output_line ("  %s%d.size = %s%d%s;",
					     CB_PREFIX_FIELD, f->id,
					     "module->next->cob_procedure_params[",
					     i, "]->size");
			}
			output_prefix ();
			output ("%s%d.data = ", CB_PREFIX_FIELD, f->id);
			output_data (CB_VALUE (l));
			output (";\n");
#if	0	/* RXWRXW - Num check */
			if (CB_EXCEPTION_ENABLE (COB_EC_DATA_INCOMPATIBLE) &&
			    f->flag_any_numeric &&
			    (f->usage == CB_USAGE_DISPLAY ||
			     f->usage == CB_USAGE_PACKED ||
			     f->usage == CB_USAGE_COMP_6)) {
				output_line ("cob_check_numeric (&%s%d, %s%d);",
					     CB_PREFIX_FIELD 
					     f->id,
					     CB_PREFIX_STRING,
					     lookup_string (f->name));
			}
#endif
		}
	}
	if (anyseen) {
		output_newline ();
	}

	if (prog->prog_type == CB_FUNCTION_TYPE) {
		output_prefix ();
		output_data (prog->returning);
		output (" = cob_malloc (");
		output_size (prog->returning);
		output ("U);\n\n");
	}

	if (prog->flag_global_use && parameter_list) {
		output_line ("/* Parameter save */");
		for (l = parameter_list; l; l = CB_CHAIN (l)) {
			f = cb_code_field (CB_VALUE (l));
			output_line ("save_%s%d = %s%d;",
				CB_PREFIX_BASE, f->id,
				CB_PREFIX_BASE, f->id);
		}
		output_newline ();
	}

	/* Classification */
	if (prog->classification) {
		if (prog->classification == cb_int1) {
			output_line ("cob_set_locale (NULL, COB_LC_CLASS);");
		} else {
			output_prefix ();
			output ("cob_set_locale (");
			output_param  (prog->classification, -1);
			output (", COB_LC_CTYPE);");
		}
		output_newline ();
	}

	/* Entry dispatch */
	output_line ("/* Entry dispatch */");
	if (cb_list_length (prog->entry_list) > 1) {
		output_newline ();
		output_line ("switch (entry)");
		output_line ("  {");
		for (i = 0, l = prog->entry_list; l; l = CB_CHAIN (l)) {
			output_line ("  case %d:", i++);
			output_line ("    goto %s%d;", CB_PREFIX_LABEL,
				     CB_LABEL (CB_PURPOSE (l))->id);
		}
		output_line ("  }");
		output_line ("/* This should never be reached */");
		output_line ("cob_fatal_error (COB_FERROR_MODULE);");
		output_newline ();
	} else {
		l = prog->entry_list;
		output_line ("goto %s%d;", CB_PREFIX_LABEL,
			     CB_LABEL (CB_PURPOSE (l))->id);
		output_newline ();
	}

	/* PROCEDURE DIVISION */
	output_line ("/* PROCEDURE DIVISION */");
	for (l = prog->exec_list; l; l = CB_CHAIN (l)) {
		output_stmt (CB_VALUE (l));
	}
	output_newline ();

	/* End of program */
	output_line ("/* Program exit */");
	output_newline ();

	if (needs_exit_prog) {
		output_line ("exit_program:");
		output_newline ();
	}

	if (!prog->flag_recursive) {
		output_line ("/* Decrement module active count */");
		output_line ("if (module->module_active) {");
		output_line ("\tmodule->module_active--;");
		output_line ("}");
		output_newline ();
	}

	if (!cobc_flag_main && non_nested_count > 1) {
		output_line ("/* Decrement module reference count */");
		output_line ("if (cob_reference_count) {");
		output_line ("\tcob_reference_count--;");
		output_line ("}");
		output_newline ();
	}

	/* Implicit CANCEL for INITIAL program */
	if (prog->flag_initial) {
		output_line ("/* CANCEL for INITIAL program */");
		output_prefix ();
		if (!prog->nested_level) {
			output ("%s_ (-1", prog->program_id);
		} else {
			output ("%s_%d_ (-1", prog->program_id,
				prog->toplev_count);
		}
		if (!prog->flag_chained) {
			for (l = parameter_list; l; l = CB_CHAIN (l)) {
				output (", NULL");
			}
		}
		output (");\n");
		output_newline ();
	}

	if (gen_dynamic) {
		output_line ("/* Deallocate dynamic FUNCTION-ID fields */");
		for (inc = 0; inc < gen_dynamic; inc++) {
			output_line ("if (cob_dyn_%u) {", inc);
			output_line ("  if (cob_dyn_%u->data) {", inc);
			output_line ("    free (cob_dyn_%u->data);", inc);
			output_line ("  }");
			output_line ("  free (cob_dyn_%u);", inc);
			output_line ("  cob_dyn_%u = NULL;", inc);
			output_line ("}");
		}
		output_newline ();
	}

	if (prog->local_storage) {
		output_line ("/* Deallocate LOCAL storage */");
		if (local_mem) {
			output_line ("if (cob_local_ptr) {");
			output_line ("\tfree (cob_local_ptr);");
			output_line ("\tcob_local_ptr = NULL;");
			if (current_prog->flag_global_use) {
				output_line ("\tcob_local_save = NULL;");
			}
			output_line ("}");
		}
		for (f = prog->local_storage; f; f = f->sister) {
			if (f->flag_item_based) {
				output_line ("if (%s%d) {", CB_PREFIX_BASE, f->id);
				output_line ("\tcob_free_alloc (&%s%d, NULL);",
					     CB_PREFIX_BASE, f->id);
				output_line ("\t%s%d = NULL;",
					     CB_PREFIX_BASE, f->id);
				output_line ("}");
			}
		}
		output_newline ();
	}

	if (prog->decimal_index_max && prog->flag_recursive) {
		output_line ("/* Free decimal structures */");
		output_prefix ();
		output ("cob_decimal_pop (%d", prog->decimal_index_max);
		for (i = 0; i < prog->decimal_index_max; i++) {
			output (", d%d", i);
		}
		output (");\n");
		output_newline ();
	}

	if (cb_flag_stack_on_heap || prog->flag_recursive) {
		output_line ("/* Free frame stack / call parameters */");
		output_line ("free (frame_stack);");
		output_line ("free (cob_procedure_params);");
		output_newline ();
	}

	if (cb_flag_trace) {
		output_line ("/* Trace program exit */");
		sprintf (string_buffer, "Exit:      %s", excp_current_program_id);
		output_line ("cob_trace_section (%s%d, NULL, 0);",
			     CB_PREFIX_STRING,
			     lookup_string (string_buffer));
		output_newline ();
	}

	output_line ("/* Pop module stack */");
	output_line ("cob_module_leave (module);");
	output_newline ();

	if (prog->flag_recursive) {
		output_line ("/* Free cob_module structure */");
#if	1	/* RXWRXW Mod */
		output_line ("cob_cache_free (module);");
#else
		output_line ("free (module);");
#endif
		output_newline ();
	}

	output_line ("/* Program return */");
#if	1	/* RXWRXW - PROCRET */
	if (prog->returning) {
		output_move (prog->returning, prog->cb_return_code);
	}
#endif
	output_prefix ();
	output ("return ");
	if (prog->prog_type == CB_FUNCTION_TYPE) {
		output_param (prog->returning, -1);
	} else {
		output_integer (prog->cb_return_code);
	}
	output (";\n");

	/* Error handlers */
	if (prog->file_list || prog->flag_gen_error) {
		output_error_handler (prog);
	}

	/* Frame stack jump table for compiler without computed goto */
	if (!cb_flag_computed_goto) {
		output_newline ();
		output_line ("/* Frame stack jump table */");
		output_line ("P_switch:");
		if (label_cache) {
			output_line (" switch (frame_ptr->return_address_num) {");
			for (pl = label_cache; pl; pl = pl->next) {
				output_line (" case %d:", pl->call_num);
				output_line ("   goto %s%d;", CB_PREFIX_LABEL,
					     pl->id);
			}
			output_line (" }");
		}
		output_line (" cob_fatal_error (COB_FERROR_CODEGEN);");
		output_newline ();
	}

	/* Program initialization */

#if	0	/* RXWRXW WS */
	if (prog->working_storage) {
		for (f = prog->working_storage; f; f = f->sister) {
			if (f->flag_item_based || f->flag_local_alloced) {
				continue;
			}
			if (f->redefines || f->flag_external) {
				continue;
			}
#if	0	/* RXWRXW - Check global */
			if (f->flag_is_global) {
				continue;
			}
#endif
			if (f->flag_no_init && !f->count) {
				continue;
			}
			if (f->flag_item_78) {
				cobc_abort_pr (_("Unexpected CONSTANT item"));
				COBC_ABORT ();
			}
			if (f->flag_is_global) {
				f->mem_offset = working_mem;
				working_mem += ((f->memory_size + COB_MALLOC_ALIGN) &
						~COB_MALLOC_ALIGN);
			} else {
				f->mem_offset = local_working_mem;
				local_working_mem += ((f->memory_size + COB_MALLOC_ALIGN) &
						~COB_MALLOC_ALIGN);
			}
		}
	}
#endif

	output_newline ();
	output_line ("/* Program initialization */");
	output_line ("P_initialize:");
	output_newline ();

	/* Check matching version */
	if (!prog->nested_level) {
		output_line ("cob_check_version (COB_SOURCE_FILE, COB_PACKAGE_VERSION, COB_PATCH_LEVEL);");
		output_newline ();
	}

	/* Resolve user functions */
	for (clp = func_call_cache; clp; clp = clp->next) {
		output_line ("func_%s.funcvoid = cob_resolve_func (\"%s\");",
			      clp->callname, clp->callname);
	}

	if (cobc_flag_main && !prog->nested_level) {
		output_line ("cob_module_path = cob_glob_ptr->cob_main_argv0;");
		output_newline ();
	}

	/* Module initialization */
	if (!prog->flag_recursive) {
		output_module_init (prog);
	}


	/* Check runtime DEBUGGING MODE variable */
	if (prog->flag_debugging) {
		output_line ("if ((s = getenv (\"COB_SET_DEBUG\")) && (*s == 'Y' || *s == 'y' || *s == '1'))");
		output_line ("\tcob_debugging_mode = 1;");
		output_newline ();
	}

	/* Setup up CANCEL callback */
	if (!prog->nested_level && prog->prog_type == CB_PROGRAM_TYPE) {
		output_line ("/* Initialize cancel callback */");
#if	0	/* RXWRXW CA */
		if (!cb_flag_implicit_init) {
			output_line ("if (module->next)");
		}
#endif
		output_line ("cob_set_cancel (module);");
		output_newline ();
	}

	/* Initialize EXTERNAL files */
	for (l = prog->file_list; l; l = CB_CHAIN (l)) {
		f = CB_FILE (CB_VALUE (l))->record;
		if (f->flag_external) {
			strcpy (string_buffer, f->name);
			for (p = string_buffer; *p; p++) {
				if (*p == '-' || *p == ' ') {
					*p = '_';
				}
			}
			output_line ("%s%d = cob_external_addr (\"%s\", %d);",
				     CB_PREFIX_BASE, f->id, string_buffer,
				     CB_FILE (CB_VALUE (l))->record_max);
		}
	}

	/* Initialize WORKING-STORAGE EXTERNAL items */
	for (f = prog->working_storage; f; f = f->sister) {
		if (f->redefines) {
			continue;
		}
		if (!f->flag_external) {
			continue;
		}
		output_prefix ();
		output_base (f, 0);
		output (" = cob_external_addr (\"%s\", %d);\n",
			f->ename, f->size);
	}

	/* Initialize WORKING-STORAGE/files if not INITIAL program */
	if (!prog->flag_initial) {
		if (prog->working_storage) {
			output_line ("/* Initialize WORKING-STORAGE */");
			output_initial_values (prog->working_storage);
			output_newline ();
		}
		if (prog->file_list) {
			output_newline ();
			for (l = prog->file_list; l; l = CB_CHAIN (l)) {
				output_file_initialization (CB_FILE (CB_VALUE (l)));
			}
			output_newline ();
		}
	}

	if (prog->screen_storage) {
		output_line ("/* Initialize SCREEN items */");
		/* Initialize items with VALUE */
		output_initial_values (prog->screen_storage);
		output_screen_init (prog->screen_storage);
		output_newline ();
	}

	if (prog->report_storage) {
		output_line ("/* Initialize REPORT data items */");
		/* Initialize items with VALUE */
		for (l = prog->report_list; l; l = CB_CHAIN (l)) {
			struct cb_report *rep;
			rep = CB_REPORT(CB_VALUE(l));
			if(rep) {
				output_initial_values (rep->records);
			}
		}
		output_newline ();
	}
	/* Reports */
	if(prog->report_list) {
		optimize_defs[COB_SET_REPORT] = 1;
		output_line ("\n/* Init Reports */\n");
		for (l = prog->report_list; l; l = CB_CHAIN (l)) {
			rep = CB_REPORT(CB_VALUE(l));
			output_report_init (rep);
		}
		output_newline ();
	}

	output_line ("initialized = 1;");
	output_line ("goto P_ret_initialize;");

	/* Set up CANCEL callback code */

	if (prog->prog_type != CB_PROGRAM_TYPE) {
		goto prog_cancel_end;
	}

	output_newline ();
	output_line ("/* CANCEL callback handling */");
	output_line ("P_cancel:");
	output_newline ();
	output_line ("if (!initialized) {");
	output_line ("\treturn 0;");
	output_line ("}");
	output_line ("if (module->module_active) {");
	output_line ("\tcob_fatal_error (COB_FERROR_CANCEL);");
	output_line ("}");
	output_newline ();

	if (prog->flag_main) {
		goto cancel_end;
	}

	next_prog = prog->next_program;

	/* Check for implicit cancel of contained programs */
	for (; next_prog; next_prog = next_prog->next_program) {
		if (next_prog->nested_level == prog->nested_level + 1) {
			output_prefix ();
			output ("(void)%s_%d_ (-1", next_prog->program_id,
				next_prog->toplev_count);
			for (i = 0; i < next_prog->num_proc_params; ++i) {
				output (", NULL");
			}
			output (");\n");
		}
	}

	/* Close files on cancel */
	for (l = prog->file_list; l; l = CB_CHAIN (l)) {
		fl = CB_FILE (CB_VALUE (l));
		if (fl->organization != COB_ORG_SORT) {
			output_line ("cob_close (%s%s, NULL, COB_CLOSE_NORMAL, 1);",
					CB_PREFIX_FILE, fl->cname);
			if (!fl->flag_external) {
				if (fl->linage) {
					output_line ("cob_cache_free (%s%s->linorkeyptr);",
						     CB_PREFIX_FILE, fl->cname);
				}
				if (fl->organization == COB_ORG_RELATIVE ||
				    fl->organization == COB_ORG_INDEXED) {
					output_line ("cob_cache_free (%s%s);",
						     CB_PREFIX_KEYS, fl->cname);
					output_line ("%s%s = NULL;",
						     CB_PREFIX_KEYS, fl->cname);
				}
				output_line ("cob_cache_free (%s%s);",
						CB_PREFIX_FILE, fl->cname);
				output_line ("%s%s = NULL;",
						CB_PREFIX_FILE, fl->cname);
			}
		} else {
			output_line ("cob_cache_free (%s%s);",
					CB_PREFIX_FILE, fl->cname);
			output_line ("%s%s = NULL;",
					CB_PREFIX_FILE, fl->cname);
		}
	}

	/* Clear alter indicators */
	for (cpl = prog->alter_gotos; cpl; cpl = cpl->next) {
		output_line ("label_%s%d = 0;",
			     CB_PREFIX_LABEL, cpl->goto_id);
		if (prog->flag_segments) {
			output_line ("save_label_%s%d = 0;",
				     CB_PREFIX_LABEL, cpl->goto_id);
		}
	}

	/* Release based storage */
	for (f = prog->working_storage; f; f = f->sister) {
		if (f->flag_item_based) {
			output_line ("if (%s%d) {", CB_PREFIX_BASE, f->id);
			output_line ("\tcob_free_alloc (&%s%d, NULL);",
				     CB_PREFIX_BASE, f->id);
			output_line ("}");
		}
	}

	/* Reset DEBUGGING mode */
	if (prog->flag_debugging) {
		output_line ("cob_debugging_mode = 0;");
	}

	/* Clear CALL pointers */
	for (clp = call_cache; clp; clp = clp->next) {
		output_line ("call_%s.funcvoid = NULL;", clp->callname);
	}
	for (clp = func_call_cache; clp; clp = clp->next) {
		output_line ("func_%s.funcvoid = NULL;", clp->callname);
	}

	/* Clear sticky-linkage pointers */
	if (cb_sticky_linkage) {
		for (l = prog->parameter_list; l; l = CB_CHAIN (l)) {
			output_line ("cob_parm_%d = NULL;",
				      cb_code_field (CB_VALUE (l))->id);
		}
	}

	/* Clear RETURN-CODE */
	if (!prog->nested_level) {
		output_prefix ();
		output_integer (current_prog->cb_return_code);
		output (" = 0;\n");
	}

#if	1	/* RXWRXW Mod */
	output_line ("cob_cache_free (module);");
	output_line ("module = NULL;");
#endif
	output_newline ();

cancel_end:
	output_line ("initialized = 0;");
	output_line ("return 0;");
	output_newline ();
	/* End of CANCEL callback code */

prog_cancel_end:
	output_indent ("}");
	output_newline ();
	if (prog->prog_type == CB_FUNCTION_TYPE) {
		s = "FUNCTION-ID";
	} else {
		s = "PROGRAM-ID";
	}
	output_line ("/* End %s '%s' */", s, prog->orig_program_id);
	output_newline ();
}

static void
output_entry_function (struct cb_program *prog, cb_tree entry,
		       cb_tree parameter_list, const int gencode)
{
	const char		*entry_name;
	cb_tree			using_list;
	cb_tree			l;
	cb_tree			l1;
	cb_tree			l2;
	struct cb_field		*f;
	struct cb_field		*f1;
	struct cb_field		*f2;
	const char		*s;
	const char		*s2;
	const char		*s_prefix;
	const char		*s_type[COB_MAX_FIELD_PARAMS];
	cob_u32_t		parmnum;
	cob_u32_t		n;
#if	0	/* RXWRXW - UFUNC */
	cob_u32_t		n2;
#endif
	int			sticky_ids[COB_MAX_FIELD_PARAMS];
	int			sticky_nonp[COB_MAX_FIELD_PARAMS];

	entry_name = CB_LABEL (CB_PURPOSE (entry))->name;
	using_list = CB_VALUE (entry);

	if (gencode) {
		output ("/* ENTRY '%s' */\n\n", entry_name);
	}

#if	defined(_WIN32) || defined(__CYGWIN__)
	if (!gencode && !prog->nested_level) {
		output ("__declspec(dllexport) ");
	}
#endif

	if (unlikely(prog->prog_type == CB_FUNCTION_TYPE)) {
		if (gencode) {
			output ("cob_field *\n");
		} else {
			output ("cob_field\t\t*");
		}
		output ("%s (", entry_name);
		if (!gencode) {
			output ("cob_field **, const int");
		} else {
			output ("cob_field **cob_fret, const int cob_pam");
		}
		parmnum = 0;
		if (using_list) {
			output (", ");
			n = 0;
			for (l = using_list; l; l = CB_CHAIN (l), ++n, ++parmnum) {
				if (!gencode) {
					output ("cob_field *");
				} else {
					output ("cob_field *f%u", n);
				}
				if (CB_CHAIN (l)) {
					output (", ");
				}
			}
		}
		if (gencode) {
			output (")\n");
		} else {
			/* Finish prototype and return */
			output (");\n");
			return;
		}
		output ("{\n");
		output ("  struct cob_func_loc\t*floc;\n\n");
		output ("  /* Save environment */\n");
		output ("  floc = cob_save_func (cob_fret, cob_pam, %u",
			parmnum);
#if	0	/* RXWRXW - UFUNC */
		if (!using_list) {
			output ("  floc->ret_fld = %s_ (0);\n", prog->program_id);
			output ("  **cob_fret = *floc->ret_fld;\n");
			output ("  cob_restore_func (floc);\n");
			output ("  return *cob_fret;\n}\n\n");
			return;
		}
		output ("  switch (cob_pam) {\n");
		for (n = 0; n <= parmnum; ++n) {
			if (!n) {
				output ("  case 0:\n");
				output ("    break;\n");
				continue;
			}
			output ("  case %u:\n", n);
			if (n == parmnum) {
				output ("  default:\n");
			}
			for (n2 = 0; n2 < n; ++n2) {
				output ("    if (f%u) {\n", n2);
				output ("      floc->func_params[%u] = f%u;\n",
					n2, n2);
				output ("      floc->data[%u] = f%u->data;\n",
					n2, n2);
				output ("    }\n");
				output ("    break;\n");
			}
		}
#else
		for (n = 0; n < parmnum; ++n) {
			output (", f%u", n);
		}
#endif
		output (");\n");

		output ("  floc->ret_fld = %s_ (0", prog->program_id);
		if (parmnum != 0) {
			output (", ");
			for (n = 0; n < parmnum; ++n) {
				output ("floc->data[%u]", n);
				if (n != parmnum - 1) {
					output (", ");
				}
			}
		}
		output (");\n");
		output ("  **cob_fret = *floc->ret_fld;\n");
		output ("  /* Restore environment */\n");
		output ("  cob_restore_func (floc);\n");
		output ("  return *cob_fret;\n}\n\n");
		return;
	}
	if (prog->nested_level) {
		if (gencode) {
			output ("static int\n");
		} else {
			output ("static int\t\t");
		}
	} else {
		if (prog->flag_main && !prog->flag_recursive) {
			output ("static ");
		}
		if (gencode) {
			output ("int\n");
		} else {
			output ("int\t\t\t");
		}
	}

	if (prog->nested_level) {
		output ("%s_%d__ (", entry_name, prog->toplev_count);
	} else {
		output ("%s (", entry_name);
	}
	if (prog->flag_chained) {
		using_list = NULL;
		parameter_list = NULL;
	}
	if (!gencode && !using_list) {
		output ("void);\n");
		return;
	}

	memset (sticky_ids, 0, sizeof(sticky_ids));
	memset (sticky_nonp, 0, sizeof(sticky_ids));

	n = 0;
	for (l = using_list; l; l = CB_CHAIN (l), ++n) {
		f = cb_code_field (CB_VALUE (l));
		switch (CB_PURPOSE_INT (l)) {
		case CB_CALL_BY_VALUE:
			if (f->usage == CB_USAGE_FLOAT) {
				if (gencode) {
					output ("float %s%d",
						CB_PREFIX_BASE, f->id);
				} else {
					output ("float");
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			} else if (f->usage == CB_USAGE_DOUBLE) {
				if (gencode) {
					output ("double %s%d",
						CB_PREFIX_BASE, f->id);
				} else {
					output ("double");
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			} else if (f->usage == CB_USAGE_LONG_DOUBLE) {
				if (gencode) {
					output ("long double %s%d",
						CB_PREFIX_BASE, f->id);
				} else {
					output ("long double");
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			} else if (f->usage == CB_USAGE_FP_BIN32) {
				if (gencode) {
					output ("cob_u32_t %s%d",
						CB_PREFIX_BASE, f->id);
				} else {
					output ("cob_u32_t");
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			} else if (f->usage == CB_USAGE_FP_BIN64 ||
				   f->usage == CB_USAGE_FP_DEC64) {
				if (gencode) {
					output ("cob_u64_t %s%d",
						CB_PREFIX_BASE, f->id);
				} else {
					output ("cob_u64_t");
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			} else if (f->usage == CB_USAGE_FP_BIN128 ||
				   f->usage == CB_USAGE_FP_DEC128) {
				if (gencode) {
					output ("cob_fp_128 %s%d",
						CB_PREFIX_BASE, f->id);
				} else {
					output ("cob_fp_128");
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			} else if (CB_TREE_CLASS (CB_VALUE (l)) == CB_CLASS_NUMERIC) {
				s = "";
				switch (CB_SIZES_INT (l)) {
				case CB_SIZE_1:
					if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
						s = "cob_u8_t";
					} else {
						s = "cob_c8_t";
					}
					break;
				case CB_SIZE_2:
					if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
						s = "cob_u16_t";
					} else {
						s = "cob_s16_t";
					}
					break;
				case CB_SIZE_4:
					if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
						s = "cob_u32_t";
					} else {
						s = "cob_s32_t";
					}
					break;
				case CB_SIZE_8:
					if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
						s = "cob_u64_t";
					} else {
						s = "cob_s64_t";
					}
					break;
				default:
					break;
				}
				if (gencode) {
					output ("%s %s%d",
						s, CB_PREFIX_BASE, f->id);
				} else {
					output ("%s", s);
				}
				if (cb_sticky_linkage) {
					s_type[n] = "";
				} else {
					s_type[n] = "(cob_u8_ptr)&";
				}
				break;
			}
			/* Fall through */
		case CB_CALL_BY_REFERENCE:
		case CB_CALL_BY_CONTENT:
			if (gencode) {
				output ("cob_u8_t *%s%d",
					CB_PREFIX_BASE, f->id);
			} else {
				output ("cob_u8_t *");
			}
			s_type[n] = "";
			break;
		default:
			break;
		}
		if (CB_CHAIN (l)) {
			output (", ");
		}
	}

	if (gencode) {
		output (")\n");
	} else {
		/* Finish prototype and return */
		output (");\n");
		return;
	}

	output ("{\n");

	/* We have to cater for sticky-linkage here at the entry point site */
	/* Doing it in the internal function is too late as we */
	/* then do not have the information as to possible ENTRY clauses */

	parmnum = 0;
	/* Sticky linkage parameters */
	if (cb_sticky_linkage && using_list) {
		for (l = using_list; l; l = CB_CHAIN (l), parmnum++) {
			f = cb_code_field (CB_VALUE (l));
			sticky_ids[parmnum] = f->id;
			switch (CB_PURPOSE_INT (l)) {
			case CB_CALL_BY_VALUE:
				s = NULL;
				s2 = "0";
				if (f->usage == CB_USAGE_FLOAT) {
					s = "float";
				} else if (f->usage == CB_USAGE_DOUBLE) {
					s = "double";
				} else if (f->usage == CB_USAGE_LONG_DOUBLE) {
					s = "long double";
				} else if (f->usage == CB_USAGE_FP_BIN32) {
					s = "cob_u32_t";
				} else if (f->usage == CB_USAGE_FP_BIN64 ||
					   f->usage == CB_USAGE_FP_DEC64) {
					s = "cob_u64_t";
				} else if (f->usage == CB_USAGE_FP_BIN128 ||
					   f->usage == CB_USAGE_FP_DEC128) {
					s = "cob_fp_128";
					s2 = "{{0, 0}}";
				} else if (CB_TREE_CLASS (CB_VALUE (l)) == CB_CLASS_NUMERIC) {
					switch (CB_SIZES_INT (l)) {
					case CB_SIZE_1:
						if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
							s = "cob_u8_t";
						} else {
							s = "cob_c8_t";
						}
						break;
					case CB_SIZE_2:
						if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
							s = "cob_u16_t";
						} else {
							s = "cob_s16_t";
						}
						break;
					case CB_SIZE_4:
						if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
							s = "cob_u32_t";
						} else {
							s = "cob_s32_t";
						}
						break;
					case CB_SIZE_8:
						if (CB_SIZES(l) & CB_SIZE_UNSIGNED) {
							s = "cob_u64_t";
						} else {
							s = "cob_s64_t";
						}
						break;
					default:
						break;
					}
				}
				if (s) {
					output ("  static %s\tcob_parm_l_%d = %s;\n",
						s, f->id, s2);
					sticky_nonp[parmnum] = 1;
					break;
				}
				/* Fall through */
			case CB_CALL_BY_REFERENCE:
			case CB_CALL_BY_CONTENT:
				break;
			default:
				break;
			}
		}
	}

	/* By value pointer fields */
	for (l2 = using_list; l2; l2 = CB_CHAIN (l2)) {
		f2 = cb_code_field (CB_VALUE (l2));
		if (CB_PURPOSE_INT (l2) == CB_CALL_BY_VALUE &&
		    (f2->usage == CB_USAGE_POINTER ||
		     f2->usage == CB_USAGE_PROGRAM_POINTER)) {
			output ("  unsigned char\t\t*ptr_%d;\n", f2->id);
		}
	}

	/* Sticky linkage set up */
	if (cb_sticky_linkage && using_list) {
		parmnum = 0;
		output ("  switch (cob_get_global_ptr ()->cob_call_params) {\n");
		for (l = using_list; l; l = CB_CHAIN (l), parmnum++) {
			output ("  case %u:\n", parmnum);
			for (n = 0; n < parmnum; ++n) {
				if (sticky_nonp[n]) {
					output ("\tcob_parm_l_%d = %s%d;\n",
						sticky_ids[n], CB_PREFIX_BASE,
						sticky_ids[n]);
					output ("\tcob_parm_%d = (cob_u8_ptr)&cob_parm_l_%d;\n",
						sticky_ids[n],
						sticky_ids[n]);
				} else {
					output ("\tcob_parm_%d = %s%d;\n",
						sticky_ids[n], CB_PREFIX_BASE,
						sticky_ids[n]);
				}
			}
			output ("\tbreak;\n");
		}
		output ("  default:\n");
		for (n = 0; n < parmnum; ++n) {
			if (sticky_nonp[n]) {
				output ("\tcob_parm_l_%d = %s%d;\n",
					sticky_ids[n], CB_PREFIX_BASE,
					sticky_ids[n]);
				output ("\tcob_parm_%d = (cob_u8_ptr)&cob_parm_l_%d;\n",
					sticky_ids[n],
					sticky_ids[n]);
			} else {
				output ("\tcob_parm_%d = %s%d;\n",
					sticky_ids[n], CB_PREFIX_BASE,
					sticky_ids[n]);
			}
		}
		output ("\tbreak;\n");
		output ("  }\n");
	}

	if (cb_sticky_linkage) {
		s_prefix = "cob_parm_";
	} else {
		s_prefix = CB_PREFIX_BASE;
	}

	for (l2 = using_list; l2; l2 = CB_CHAIN (l2)) {
		f2 = cb_code_field (CB_VALUE (l2));
		if (CB_PURPOSE_INT (l2) == CB_CALL_BY_VALUE &&
		    (f2->usage == CB_USAGE_POINTER ||
		     f2->usage == CB_USAGE_PROGRAM_POINTER)) {
			output ("  ptr_%d = %s%d;\n",
				f2->id, s_prefix, f2->id);
		}
	}

	if (!prog->nested_level) {
		output ("  return %s_ (%d", prog->program_id, progid++);
	} else {
		output ("  return %s_%d_ (%d", prog->program_id,
			prog->toplev_count, progid++);
	}

	if (!using_list && !parameter_list) {
		output (");\n");
		output ("}\n\n");
		return;
	}

	for (l1 = parameter_list; l1; l1 = CB_CHAIN (l1)) {
		f1 = cb_code_field (CB_VALUE (l1));
		n = 0;
		for (l2 = using_list; l2; l2 = CB_CHAIN (l2), ++n) {
			f2 = cb_code_field (CB_VALUE (l2));
			if (strcasecmp (f1->name, f2->name) == 0) {
				switch (CB_PURPOSE_INT (l2)) {
				case CB_CALL_BY_VALUE:
					if (f2->usage == CB_USAGE_POINTER ||
					    f2->usage == CB_USAGE_PROGRAM_POINTER) {
						output (", (cob_u8_ptr)&ptr_%d", f2->id);
						break;
					}
					/* Fall through */
				case CB_CALL_BY_REFERENCE:
				case CB_CALL_BY_CONTENT:
					output (", %s%s%d",
						s_type[n], s_prefix, f2->id);
					break;
				default:
					break;
				}
				break;
			}
		}
		if (l2 == NULL) {
			if (cb_sticky_linkage) {
				output (", %s%d",
					s_prefix, f1->id);
			} else {
				output (", NULL");
			}
		}
	}
	output (");\n");
	output ("}\n\n");
}

static void
output_main_function (struct cb_program *prog)
{
	output_line ("/* Main function */");
	output_line ("int");
	output_line ("main (int argc, char **argv)");
	output_indent ("{");
	output_line ("cob_init (argc, argv);");
	output_line ("cob_stop_run (%s ());", prog->program_id);
	output_indent ("}\n");
}

static void
output_header (FILE *fp, const char *locbuff, const struct cb_program *cp)
{
	int	i;

	if (fp) {
		fprintf (fp, "/* Generated by            cobc %s.%d */\n",
			 PACKAGE_VERSION, PATCH_LEVEL);
		fprintf (fp, "/* Generated from          %s */\n", cb_source_file);
		fprintf (fp, "/* Generated at            %s */\n", locbuff);
		fprintf (fp, "/* GNU Cobol build date    %s */\n", cb_oc_build_stamp);
		fprintf (fp, "/* GNU Cobol package date  %s */\n", COB_TAR_DATE);
		fprintf (fp, "/* Compile command         ");
		for (i = 0; i < cb_saveargc; i++) {
			fprintf (fp, "%s ", cb_saveargv[i]);
		}
		fprintf (fp, "*/\n\n");
		if (cp) {
			fprintf (fp, "/* Program local variables for '%s' */\n\n",
				 cp->orig_program_id);
		}
	}
}

void
codegen (struct cb_program *prog, const int nested)
{
	cb_tree			l;
	struct attr_list	*j;
	struct literal_list	*m;
	struct field_list	*k;
	struct string_list	*stp;
	struct call_list	*clp;
	struct base_list	*blp;
	unsigned char		*s;
	struct nested_list	*nlp;
	struct cb_program	*cp;
#if	0	/* RXWRXW - Const */
	struct cb_literal	*lp;
#endif
	cb_tree			l1;
	cb_tree			l2;
	const char		*prevprog;
	struct tm		*loctime;
	cob_u32_t		inc;
#if	0	/* RXWRXW - Sticky */
	int			save_sticky;
#endif
	int			i;
	int			found;
	enum cb_optim		optidx;
	time_t			sectime;

	/* Clear local program stuff */
	current_prog = prog;
	param_id = 0;
	stack_id = 0;
	num_cob_fields = 0;
	progid = 0;
	loop_counter = 0;
	output_indent_level = 0;
	last_line = 0;
	needs_exit_prog = 0;
	gen_custom = 0;
	gen_nested_tab = 0;
	gen_dynamic = 0;
	gen_if_level = 0;
	local_mem = 0;
	local_working_mem = 0;
	need_save_exception = 0;
	last_segment = 0;
	last_section = NULL;
	call_cache = NULL;
	func_call_cache = NULL;
	label_cache = NULL;
	local_base_cache = NULL;
	local_field_cache = NULL;
	inside_check = 0;
	for (i = 0; i < COB_INSIDE_SIZE; ++i) {
		inside_stack[i] = 0;
	}
	excp_current_program_id = prog->orig_program_id;
	excp_current_section = NULL;
	excp_current_paragraph = NULL;
	memset ((void *)i_counters, 0, sizeof (i_counters));
#if	0	/* RXWRXW - Sticky */
	save_sticky = cb_sticky_linkage;
#endif

	output_target = yyout;
	cb_local_file = current_prog->local_include->local_fp;

	if (!nested) {
		/* First iteration */
		gen_alt_ebcdic = 0;
		gen_ebcdic_ascii = 0;
		gen_full_ebcdic = 0;
		gen_native = 0;
		gen_figurative = 0;
		non_nested_count = 0;
		working_mem = 0;
		attr_cache = NULL;
		base_cache = NULL;
		globext_cache = NULL;
		literal_cache = NULL;
		field_cache = NULL;
		string_cache = NULL;
		string_id = 1;
		if (!string_buffer) {
			string_buffer = cobc_main_malloc ((size_t)COB_MINI_BUFF);
		}

		sectime = time (NULL);
		loctime = localtime (&sectime);
		/* Leap seconds ? */
		if (loctime->tm_sec >= 60) {
			loctime->tm_sec = 59;
		}
		if (loctime) {
			strftime (string_buffer, (size_t)COB_MINI_MAX,
				  "%b %d %Y %H:%M:%S", loctime);
		} else {
			strcpy (string_buffer, "Unknown");
		}
		output_header (output_target, string_buffer, NULL);
		output_header (cb_storage_file, string_buffer, NULL);
		for (cp = prog; cp; cp = cp->next_program) {
			output_header (cp->local_include->local_fp,
					string_buffer, cp);
		}

#ifndef	_GNU_SOURCE
#ifdef	_XOPEN_SOURCE_EXTENDED
		output ("#ifndef\t_XOPEN_SOURCE_EXTENDED\n");
		output ("#define\t_XOPEN_SOURCE_EXTENDED 1\n");
		output ("#endif\n");
#endif
#endif
		output ("#include <stdio.h>\n");
		output ("#include <stdlib.h>\n");
		output ("#include <stddef.h>\n");
		output ("#include <string.h>\n");
		output ("#include <math.h>\n");
#ifdef	WORDS_BIGENDIAN
		output ("#define  WORDS_BIGENDIAN 1\n");
#endif
#ifdef	COB_KEYWORD_INLINE
		output ("#define  COB_KEYWORD_INLINE %s\n",
			CB_XSTRINGIFY(COB_KEYWORD_INLINE));
#endif
		output ("#include <libcob.h>\n\n");

		output ("#define  COB_SOURCE_FILE\t\t\"%s\"\n",
			cb_source_file);
		output ("#define  COB_PACKAGE_VERSION\t\t\"%s\"\n",
			PACKAGE_VERSION);
		output ("#define  COB_PATCH_LEVEL\t\t%d\n",
			PATCH_LEVEL);
		/* string_buffer has formatted date from above */
		output ("#define  COB_MODULE_FORMATTED_DATE\t\"%s\"\n",
			string_buffer);
		if (loctime) {
			i = ((loctime->tm_year + 1900) * 10000) +
			    ((loctime->tm_mon + 1) * 100) +
			    loctime->tm_mday;
			output ("#define  COB_MODULE_DATE\t\t%d\n", i);
			i = (loctime->tm_hour * 10000) +
			    (loctime->tm_min * 100) +
			    loctime->tm_sec;
			output ("#define  COB_MODULE_TIME\t\t%d\n", i);
		} else {
			output ("#define  COB_MODULE_DATE\t\t0\n");
			output ("#define  COB_MODULE_TIME\t\t0\n");
		}

		output_newline ();
		output ("/* Global variables */\n");
		output ("#include \"%s\"\n\n", cb_storage_file_name);

		output ("/* Function prototypes */\n\n");
		for (cp = prog; cp; cp = cp->next_program) {
			/* Build parameter list */
			for (l = cp->entry_list; l; l = CB_CHAIN (l)) {
				for (l1 = CB_VALUE (l); l1; l1 = CB_CHAIN (l1)) {
					for (l2 = cp->parameter_list; l2; l2 = CB_CHAIN (l2)) {
						if (strcasecmp (cb_code_field (CB_VALUE (l1))->name,
								cb_code_field (CB_VALUE (l2))->name) == 0) {
							break;
						}
					}
					if (l2 == NULL) {
						cp->parameter_list = cb_list_add (cp->parameter_list, CB_VALUE (l1));
					}
				}
			}
			if (cp->flag_main) {
				if (!cp->flag_recursive) {
					output ("static int\t\t%s ();\n",
						cp->program_id);
				} else {
					output ("int\t\t\t%s ();\n",
						cp->program_id);
				}
			} else {
				for (l = cp->entry_list; l; l = CB_CHAIN (l)) {
					output_entry_function (cp, l, cp->parameter_list, 0);
				}
			}
			if (cp->prog_type == CB_FUNCTION_TYPE) {
				non_nested_count++;
#if	0	/* RXWRXW USERFUNC */
				output ("static cob_field\t*%s_ (const int, cob_field **",
#else
				output ("static cob_field\t*%s_ (const int",
#endif
					cp->program_id);
			} else if (!cp->nested_level) {
				non_nested_count++;
				output ("static int\t\t%s_ (const int",
					cp->program_id);
			} else {
				output ("static int\t\t%s_%d_ (const int",
					cp->program_id, cp->toplev_count);
			}
#if	0	/* RXWRXW USERFUNC */
			if (!cp->flag_chained && cp->prog_type != CB_FUNCTION_TYPE) {
#else
			if (!cp->flag_chained) {
#endif
				for (l = cp->parameter_list; l; l = CB_CHAIN (l)) {
					output (", cob_u8_t *");
					if (cb_sticky_linkage) {
						output_storage ("static cob_u8_t\t\t\t*cob_parm_%d = NULL;\n",
								cb_code_field (CB_VALUE (l))->id);
					}
				}
			}
#if	0	/* RXWRXW - NOINLINE */
			if (cb_flag_stack_check) {
				output (") COB_NOINLINE;\n");
			} else {
#endif
				output (");\n");
#if	0	/* RXWRXW - NOINLINE */
			}
#endif
		}
		output ("\n");
	}

	/* Class-names */
	if (!prog->nested_level && prog->class_name_list) {
		output ("/* Class names */\n");
		for (l = prog->class_name_list; l; l = CB_CHAIN (l)) {
			output_class_name_definition (CB_CLASS_NAME (CB_VALUE (l)));
		}
	}

	/* Main function */
	if (prog->flag_main) {
		output_main_function (prog);
	}

	/* Functions */
	if (!nested) {
		output ("/* Functions */\n\n");
	}

	if (prog->prog_type == CB_FUNCTION_TYPE) {
		output ("/* FUNCTION-ID '%s' */\n\n", prog->orig_program_id);
	} else {
		output ("/* PROGRAM-ID '%s' */\n\n", prog->orig_program_id);
	}

	for (l = prog->entry_list; l; l = CB_CHAIN (l)) {
		output_entry_function (prog, l, prog->parameter_list, 1);
	}

	output_internal_function (prog, prog->parameter_list);

	if (!prog->next_program) {
		output ("/* End functions */\n\n");
	}

	if (gen_native || gen_full_ebcdic ||
	    gen_ebcdic_ascii || prog->alphabet_name_list) {
		(void)lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
	}

	output_target = cb_storage_file;

	/* Program local stuff */

	/* CALL cache */
	if (needs_unifunc || call_cache || func_call_cache) {
		output_local ("\n/* Call pointers */\n");
	}
	if (needs_unifunc) {
		output_local ("cob_call_union\t\tcob_unifunc;\n");
	}
	for (clp = call_cache; clp; clp = clp->next) {
		output_local ("static cob_call_union\tcall_%s;\n",
			      clp->callname);
	}
	for (clp = func_call_cache; clp; clp = clp->next) {
		output_local ("static cob_call_union\tfunc_%s;\n",
			      clp->callname);
	}
	needs_unifunc = 0;

	/* Nested / contained list */
	if (prog->nested_prog_list && gen_nested_tab) {
		/* Generate contained prog list */
		output_local ("\n/* Nested call table */\n");
		output_local ("static struct cob_call_struct\tcob_nest_tab[] = {\n");
		nlp = prog->nested_prog_list;
		for (; nlp; nlp = nlp->next) {
			if (nlp->nested_prog == prog) {
#if	0	/* RXWRXW Fix recursive */
				if (!prog->flag_recursive) {
					continue;
				}
#endif
				output_local ("\t{ \"%s\", { (void *(*)())%s_%d__ }, { NULL } },\n",
					nlp->nested_prog->orig_program_id,
					nlp->nested_prog->program_id,
					nlp->nested_prog->toplev_count);
			} else {
				output_local ("\t{ \"%s\", { (void *(*)())%s_%d__ }, { (void *(*)())%s_%d_ } },\n",
					nlp->nested_prog->orig_program_id,
					nlp->nested_prog->program_id,
					nlp->nested_prog->toplev_count,
					nlp->nested_prog->program_id,
					nlp->nested_prog->toplev_count);
			}
		}
		output_local ("\t{ NULL, { NULL }, { NULL } }\n");
		output_local ("};\n");
	}

	/* Report data fields */
	if (prog->report_storage) {
		for (l = prog->report_list; l; l = CB_CHAIN (l)) {
			struct cb_report *rep;
			rep = CB_REPORT(CB_VALUE(l));
			if(rep) {
				compute_report_rcsz (rep->records);
			}
		}
	}
	/* Local indexes */
	found = 0;
	for (i = 0; i < COB_MAX_SUBSCRIPTS; i++) {
		if (i_counters[i]) {
			if (!found) {
				found = 1;
				output_local ("\n/* Subscripts */\n");
			}
			output_local ("int\t\ti%d;\n", i);
		}
	}

	/* PERFORM TIMES counters */
	if (loop_counter) {
		output_local ("\n/* Loop counters */\n");
		for (i = 0; i < loop_counter; i++) {
			output_local ("cob_s64_t\tn%d = 0;\n", i);
		}
		output_local ("\n");
	}

	/* Local implicit fields */
	if (num_cob_fields) {
		output_local ("\n/* Local cob_field items */\n");
		for (i = 0; i < num_cob_fields; i++) {
			output_local ("cob_field\t\tf%d;\n", i);
		}
		output_local ("\n");
	}

	/* Debugging fields */
	if (prog->flag_debugging) {
		output_local ("\n/* DEBUG runtime switch */\n");
		output_local ("static int\tcob_debugging_mode = 0;\n");
	}
	if (need_save_exception) {
		output_local ("\n/* DEBUG exception code save */\n");
		output_local ("int\t\tsave_exception_code = 0;\n");
	}

	/* LOCAL storage pointer */
	if (prog->local_storage && local_mem) {
		output_local ("\n/* LOCAL storage pointer */\n");
		output_local ("unsigned char\t\t*cob_local_ptr = NULL;\n");
		if (current_prog->flag_global_use) {
			output_local ("static unsigned char\t*cob_local_save = NULL;\n");
		}
	}

	/* Call parameter stack */
	output_local ("\n/* Call parameters */\n");
	if (cb_flag_stack_on_heap || prog->flag_recursive) {
		output_local ("cob_field\t\t**cob_procedure_params;\n");
	} else {
		if (prog->max_call_param) {
			i = prog->max_call_param;
		} else {
			i = 1;
		}
		output_local ("cob_field\t\t*cob_procedure_params[%d];\n", i);
	}

	/* Frame stack */
	output_local ("\n/* Perform frame stack */\n");
	if (cb_perform_osvs && current_prog->prog_type == CB_PROGRAM_TYPE) {
		output_local ("struct cob_frame\t*temp_index;\n");
	}
	if (cb_flag_stack_check) {
		output_local ("struct cob_frame\t*frame_overflow;\n");
	}
	output_local ("struct cob_frame\t*frame_ptr;\n");
	if (cb_flag_stack_on_heap || prog->flag_recursive) {
		output_local ("struct cob_frame\t*frame_stack;\n\n");
	} else {
		output_local ("struct cob_frame\tframe_stack[%d];\n\n",
			      cb_stack_size);
	}

	if (gen_dynamic) {
		output_local ("\n/* Dynamic field FUNCTION-ID pointers */\n");
		for (inc = 0; inc < gen_dynamic; inc++) {
			output_local ("cob_field\t*cob_dyn_%u = NULL;\n",
				      inc);
		}
	}

	if(prog->report_storage) {
		output_target = current_prog->local_include->local_fp;
		for (l = prog->report_list; l; l = CB_CHAIN (l)) {
			struct cb_report *rep;
			rep = CB_REPORT(CB_VALUE(l));
			if(rep) {
				output_report_sum_control_field (rep->records);
			}
		}
	}

	if (local_base_cache) {
		output_local ("\n/* Local Data storage */\n");
		local_base_cache = list_cache_sort (local_base_cache,
						    &base_cache_cmp);
		for (blp = local_base_cache; blp; blp = blp->next) {
			if (blp->f->special_index > 1) {
				output_local ("int              %s%d;",
						CB_PREFIX_BASE, blp->f->id);
				output_local ("\t/* %s */\n", blp->f->name);
			} else if (blp->f->special_index) {
				output_local ("static int       %s%d;",
						CB_PREFIX_BASE, blp->f->id);
				output_local ("\t/* %s */\n", blp->f->name);
			} else {
				if( !(blp->f->report_flag & COB_REPORT_REF_EMITED)) {
					output_local ("static cob_u8_t  %s%d[%d]%s;",
							CB_PREFIX_BASE, blp->f->id,
							blp->f->memory_size, COB_ALIGN);
					output_local ("\t/* %s */\n", blp->f->name);
				}
			}
		}
		output_local ("\n/* End of local data storage */\n\n");
	}

	if (local_field_cache) {
		/* Switch to local storage file */
		output_target = current_prog->local_include->local_fp;
		output_local ("\n/* Fields */\n");
		local_field_cache = list_cache_sort (local_field_cache,
						     &field_cache_cmp);
		for (k = local_field_cache; k; k = k->next) {
			output ("static cob_field %s%d\t= ", CB_PREFIX_FIELD,
				k->f->id);
			if (!k->f->flag_local) {
				output_field (k->x);
			} else {
				output ("{");
				output_size (k->x);
				output (", NULL, ");
				output_attr (k->x);
				output ("}");
			}
			if (k->f->flag_filler) {
				output (";\t/* Implicit FILLER */\n");
			} else {
				output (";\t/* %s */\n", k->f->name);
			}
			k->f->report_flag |= COB_REPORT_REF_EMITED;
		}
		/* Report special fields */
		if (prog->report_storage) {
			struct cb_field		*f;
			struct cb_report *rep;
			for (l = prog->report_list; l; l = CB_CHAIN (l)) {
				rep = CB_REPORT(CB_VALUE(l));
				for(f=rep->records; f; f=f->sister) {
					if (f->storage == CB_STORAGE_WORKING
					&& !(f->report_flag & COB_REPORT_REF_EMITED)) {
						output ("static cob_field %s%d\t= ", 
								CB_PREFIX_FIELD, f->id);
						output_field (cb_build_field_reference (f, NULL));
						output (";\t/* %s */\n", f->name);
						f->report_flag |= COB_REPORT_REF_EMITED;
					}
				}
			}
			for (l = prog->report_list; l; l = CB_CHAIN (l)) {
				rep = CB_REPORT(CB_VALUE(l));
				if(rep) {
					output_report_sumed_field (rep->records);
				}
			}
		}
		output_local ("\n/* End of fields */\n\n");
		/* Switch to main storage file */
		output_target = cb_storage_file;
	}
	/* Report data fields */
	if (prog->report_storage) {
		struct cb_report	*rep;
		output_target = current_prog->local_include->local_fp;
		output_local ("\n/* Report data fields */\n\n");
		for (l = prog->report_list; l; l = CB_CHAIN (l)) {
			rep = CB_REPORT(CB_VALUE(l));
			if(rep) {
				output_emit_field(rep->line_counter,NULL);
				output_emit_field(rep->page_counter,NULL);
				report_col_pos = 0;
				output_report_data(rep->records);
				output_local ("\n");
			}
		}
		output_local ("\n");
		output_target = cb_storage_file;
	}
	/* Reports */
	if(prog->report_list) {
		/* Switch to local storage file */
		output_target = current_prog->local_include->local_fp;
		optimize_defs[COB_SET_REPORT] = 1;
		output_local ("\n/* Reports */\n");
		output_report_list(prog->report_list, CB_CHAIN (prog->report_list));
		output_local ("\n/* End of Reports */\n");
		/* Switch to main storage file */
		output_target = cb_storage_file;
	}

	/* Skip to next nested program */

	if (prog->next_program) {
		codegen (prog->next_program, 1);
		return;
	}

	/* Finalize the main include file */

#if	0	/* RXWRXW - GLOBPTR */
	output_storage ("\n/* Global variable pointer */\n");
	output_storage ("static cob_global\t\t*cob_glob_ptr = NULL;\n");
#endif

	if (!cobc_flag_main && non_nested_count > 1) {
		output_storage ("\n/* Module reference count */\n");
		output_storage ("static unsigned int\t\tcob_reference_count = 0;\n");
	}

	output_storage ("\n/* Module path */\n");
	output_storage ("static const char\t\t*cob_module_path = NULL;\n");

	if (globext_cache) {
		output_storage ("\n/* GLOBAL EXTERNAL pointers */\n");
		globext_cache = list_cache_sort (globext_cache, &base_cache_cmp);
		for (blp = globext_cache; blp; blp = blp->next) {
			output_storage ("static unsigned char\t\t*%s%d = NULL;",
					CB_PREFIX_BASE, blp->f->id);
			output_storage ("\t/* %s */\n", blp->f->name);
		}
	}

	if (base_cache) {
		output_storage ("\n/* Data storage */\n");
		base_cache = list_cache_sort (base_cache, &base_cache_cmp);
		prevprog = NULL;
		for (blp = base_cache; blp; blp = blp->next) {
			if (blp->curr_prog != prevprog) {
				prevprog = blp->curr_prog;
				output_storage ("\n/* PROGRAM-ID : %s */\n",
						prevprog);
			}
			if (blp->f->special_index) {
				output_storage ("static int       %s%d;",
						CB_PREFIX_BASE, blp->f->id);
			} else {
				output_storage ("static cob_u8_t  %s%d[%d]%s;",
						CB_PREFIX_BASE, blp->f->id,
						blp->f->memory_size, COB_ALIGN);
			}
			output_storage ("\t/* %s */\n", blp->f->name);
		}
		output_storage ("\n/* End of data storage */\n\n");
	}

	/* Attributes */
	if (attr_cache || gen_figurative) {
		output_storage ("\n/* Attributes */\n\n");
		attr_cache = attr_list_reverse (attr_cache);
		for (j = attr_cache; j; j = j->next) {
			output_storage ("static const cob_field_attr %s%d =\t",
					CB_PREFIX_ATTR, j->id);
			output_storage ("{0x%02x, %3u, %3d, 0x%04x, ",
					j->type, j->digits,
					j->scale, j->flags);
			if (j->pic) {
				output_storage ("\"");
				for (s = j->pic; *s; s += 5) {
					output_storage ("%c\\%03o\\%03o\\%03o\\%03o",
						s[0], s[1], s[2], s[3], s[4]);
				}
				output_storage ("\"");
			} else {
				output_storage ("NULL");
			}
			output_storage ("};\n");
		}
		if (gen_figurative) {
			output_storage ("\nstatic const cob_field_attr cob_all_attr = ");
			output_storage ("{0x%02x, 0, 0, 0, NULL};\n",
					COB_TYPE_ALPHANUMERIC_ALL);
		}
		output_storage ("\n");
	}

	if (field_cache) {
		output_storage ("\n/* Fields */\n");
		field_cache = list_cache_sort (field_cache, &field_cache_cmp);
		prevprog = NULL;
		for (k = field_cache; k; k = k->next) {
			if (k->curr_prog != prevprog) {
				prevprog = k->curr_prog;
				output_storage ("\n/* PROGRAM-ID : %s */\n",
						prevprog);
			}
			output ("static cob_field %s%d\t= ", CB_PREFIX_FIELD,
				k->f->id);
			if (!k->f->flag_local) {
				output_field (k->x);
			} else {
				output ("{");
				output_size (k->x);
				output (", NULL, ");
				output_attr (k->x);
				output ("}");
			}
			if (k->f->flag_filler) {
				output (";\t/* Implicit FILLER */\n");
			} else {
				output (";\t/* %s */\n", k->f->name);
			}
		}
		output_storage ("\n/* End of fields */\n\n");
	}

	/* Literals, figuratives, constants */
	if (literal_cache || gen_figurative) {
		output_storage ("\n/* Constants */\n");
		literal_cache = literal_list_reverse (literal_cache);
		for (m = literal_cache; m; m = m->next) {
#if	0	/* RXWRXW - Const */
			output ("static const cob_fld_union %s%d\t= ",
				CB_PREFIX_CONST, m->id);
			output ("{");
			output_size (m->x);
			output (", ");
			lp = CB_LITERAL (m->x);
			if (CB_TREE_CLASS (m->x) == CB_CLASS_NUMERIC) {
				output ("\"%s%s\"", (char *)lp->data,
					(lp->sign < 0) ? "-" : (lp->sign > 0) ? "+" : "");
			} else {
				output_string (lp->data, (int) lp->size, lp->llit);
			}
			output (", ");
			output_attr (m->x);
			output ("}");
#else
			output ("static const cob_field %s%d\t= ",
				CB_PREFIX_CONST, m->id);
			output_field (m->x);
#endif
			output (";\n");
		}
		if (gen_figurative) {
			output ("\n");
			if (gen_figurative & CB_NEED_LOW) {
				output ("static cob_field cob_all_low\t= ");
				output ("{1, ");
				output ("(cob_u8_ptr)\"\\0\", ");
				output ("&cob_all_attr};\n");
			}
			if (gen_figurative & CB_NEED_HIGH) {
				output ("static cob_field cob_all_high\t= ");
				output ("{1, ");
				output ("(cob_u8_ptr)\"\\xff\", ");
				output ("&cob_all_attr};\n");
			}
			if (gen_figurative & CB_NEED_QUOTE) {
				output ("static cob_field cob_all_quote\t= ");
				output ("{1, ");
				if (cb_flag_apostrophe) {
					output ("(cob_u8_ptr)\"'\", ");
				} else {
					output ("(cob_u8_ptr)\"\\\"\", ");
				}
				output ("&cob_all_attr};\n");
			}
			if (gen_figurative & CB_NEED_SPACE) {
				output ("static cob_field cob_all_space\t= ");
				output ("{1, ");
				output ("(cob_u8_ptr)\" \", ");
				output ("&cob_all_attr};\n");
			}
			if (gen_figurative & CB_NEED_ZERO) {
				output ("static cob_field cob_all_zero\t= ");
				output ("{1, ");
				output ("(cob_u8_ptr)\"0\", ");
				output ("&cob_all_attr};\n");
			}
		}
		output ("\n");
	}

	/* Collating tables */
	if (gen_alt_ebcdic) {
		output_storage ("\n/* ASCII to EBCDIC translate table (restricted) */\n");
		output ("static const unsigned char\tcob_a2e[256] = {\n");
		/* Restricted table */
		output ("\t0x00, 0x01, 0x02, 0x03, 0x1D, 0x19, 0x1A, 0x1B,\n");
		output ("\t0x0F, 0x04, 0x16, 0x06, 0x07, 0x08, 0x09, 0x0A,\n");
		output ("\t0x0B, 0x0C, 0x0D, 0x0E, 0x1E, 0x1F, 0x1C, 0x17,\n");
		output ("\t0x10, 0x11, 0x20, 0x18, 0x12, 0x13, 0x14, 0x15,\n");
		output ("\t0x21, 0x27, 0x3A, 0x36, 0x28, 0x30, 0x26, 0x38,\n");
		output ("\t0x24, 0x2A, 0x29, 0x25, 0x2F, 0x2C, 0x22, 0x2D,\n");
		output ("\t0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A,\n");
		output ("\t0x7B, 0x7C, 0x35, 0x2B, 0x23, 0x39, 0x32, 0x33,\n");
		output ("\t0x37, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D,\n");
		output ("\t0x5E, 0x5F, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,\n");
		output ("\t0x67, 0x68, 0x69, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,\n");
		output ("\t0x70, 0x71, 0x72, 0x7D, 0x6A, 0x7E, 0x7F, 0x31,\n");
		output ("\t0x34, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41,\n");
		output ("\t0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,\n");
		output ("\t0x4A, 0x4B, 0x4C, 0x4E, 0x4F, 0x50, 0x51, 0x52,\n");
		output ("\t0x53, 0x54, 0x55, 0x56, 0x2E, 0x60, 0x4D, 0x05,\n");
		output ("\t0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,\n");
		output ("\t0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,\n");
		output ("\t0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,\n");
		output ("\t0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,\n");
		output ("\t0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,\n");
		output ("\t0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,\n");
		output ("\t0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7,\n");
		output ("\t0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,\n");
		output ("\t0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7,\n");
		output ("\t0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,\n");
		output ("\t0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7,\n");
		output ("\t0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,\n");
		output ("\t0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7,\n");
		output ("\t0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,\n");
		output ("\t0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7,\n");
		output ("\t0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF\n");
		output ("};\n");
		output_storage ("\n");
	}
	if (gen_full_ebcdic) {
		output_storage ("\n/* ASCII to EBCDIC table */\n");
		output ("static const unsigned char\tcob_ascii_ebcdic[256] = {\n");
		output ("\t0x00, 0x01, 0x02, 0x03, 0x37, 0x2D, 0x2E, 0x2F,\n");
		output ("\t0x16, 0x05, 0x25, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,\n");
		output ("\t0x10, 0x11, 0x12, 0x13, 0x3C, 0x3D, 0x32, 0x26,\n");
		output ("\t0x18, 0x19, 0x3F, 0x27, 0x1C, 0x1D, 0x1E, 0x1F,\n");
		output ("\t0x40, 0x5A, 0x7F, 0x7B, 0x5B, 0x6C, 0x50, 0x7D,\n");
		output ("\t0x4D, 0x5D, 0x5C, 0x4E, 0x6B, 0x60, 0x4B, 0x61,\n");
		output ("\t0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7,\n");
		output ("\t0xF8, 0xF9, 0x7A, 0x5E, 0x4C, 0x7E, 0x6E, 0x6F,\n");
		output ("\t0x7C, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7,\n");
		output ("\t0xC8, 0xC9, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6,\n");
		output ("\t0xD7, 0xD8, 0xD9, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6,\n");
		output ("\t0xE7, 0xE8, 0xE9, 0xAD, 0xE0, 0xBD, 0x5F, 0x6D,\n");
		output ("\t0x79, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,\n");
		output ("\t0x88, 0x89, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96,\n");
		output ("\t0x97, 0x98, 0x99, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6,\n");
		output ("\t0xA7, 0xA8, 0xA9, 0xC0, 0x6A, 0xD0, 0xA1, 0x07,\n");
		output ("\t0x68, 0xDC, 0x51, 0x42, 0x43, 0x44, 0x47, 0x48,\n");
		output ("\t0x52, 0x53, 0x54, 0x57, 0x56, 0x58, 0x63, 0x67,\n");
		output ("\t0x71, 0x9C, 0x9E, 0xCB, 0xCC, 0xCD, 0xDB, 0xDD,\n");
		output ("\t0xDF, 0xEC, 0xFC, 0xB0, 0xB1, 0xB2, 0x3E, 0xB4,\n");
		output ("\t0x45, 0x55, 0xCE, 0xDE, 0x49, 0x69, 0x9A, 0x9B,\n");
		output ("\t0xAB, 0x9F, 0xBA, 0xB8, 0xB7, 0xAA, 0x8A, 0x8B,\n");
		output ("\t0xB6, 0xB5, 0x62, 0x4F, 0x64, 0x65, 0x66, 0x20,\n");
		output ("\t0x21, 0x22, 0x70, 0x23, 0x72, 0x73, 0x74, 0xBE,\n");
		output ("\t0x76, 0x77, 0x78, 0x80, 0x24, 0x15, 0x8C, 0x8D,\n");
		output ("\t0x8E, 0x41, 0x06, 0x17, 0x28, 0x29, 0x9D, 0x2A,\n");
		output ("\t0x2B, 0x2C, 0x09, 0x0A, 0xAC, 0x4A, 0xAE, 0xAF,\n");
		output ("\t0x1B, 0x30, 0x31, 0xFA, 0x1A, 0x33, 0x34, 0x35,\n");
		output ("\t0x36, 0x59, 0x08, 0x38, 0xBC, 0x39, 0xA0, 0xBF,\n");
		output ("\t0xCA, 0x3A, 0xFE, 0x3B, 0x04, 0xCF, 0xDA, 0x14,\n");
		output ("\t0xE1, 0x8F, 0x46, 0x75, 0xFD, 0xEB, 0xEE, 0xED,\n");
		output ("\t0x90, 0xEF, 0xB3, 0xFB, 0xB9, 0xEA, 0xBB, 0xFF\n");
		output ("};\n");
		if (gen_full_ebcdic > 1) {
			i = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
			output
			    ("static cob_field f_ascii_ebcdic = { 256, (cob_u8_ptr)cob_ascii_ebcdic, &%s%d };\n",
			     CB_PREFIX_ATTR, i);
		}
		output_storage ("\n");
	}
	if (gen_ebcdic_ascii) {
		output_storage ("\n/* EBCDIC to ASCII table */\n");
		output ("static const unsigned char\tcob_ebcdic_ascii[256] = {\n");
		output ("\t0x00, 0x01, 0x02, 0x03, 0xEC, 0x09, 0xCA, 0x7F,\n");
		output ("\t0xE2, 0xD2, 0xD3, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,\n");
		output ("\t0x10, 0x11, 0x12, 0x13, 0xEF, 0xC5, 0x08, 0xCB,\n");
		output ("\t0x18, 0x19, 0xDC, 0xD8, 0x1C, 0x1D, 0x1E, 0x1F,\n");
		output ("\t0xB7, 0xB8, 0xB9, 0xBB, 0xC4, 0x0A, 0x17, 0x1B,\n");
		output ("\t0xCC, 0xCD, 0xCF, 0xD0, 0xD1, 0x05, 0x06, 0x07,\n");
		output ("\t0xD9, 0xDA, 0x16, 0xDD, 0xDE, 0xDF, 0xE0, 0x04,\n");
		output ("\t0xE3, 0xE5, 0xE9, 0xEB, 0x14, 0x15, 0x9E, 0x1A,\n");
		output ("\t0x20, 0xC9, 0x83, 0x84, 0x85, 0xA0, 0xF2, 0x86,\n");
		output ("\t0x87, 0xA4, 0xD5, 0x2E, 0x3C, 0x28, 0x2B, 0xB3,\n");
		output ("\t0x26, 0x82, 0x88, 0x89, 0x8A, 0xA1, 0x8C, 0x8B,\n");
		output ("\t0x8D, 0xE1, 0x21, 0x24, 0x2A, 0x29, 0x3B, 0x5E,\n");
		output ("\t0x2D, 0x2F, 0xB2, 0x8E, 0xB4, 0xB5, 0xB6, 0x8F,\n");
		output ("\t0x80, 0xA5, 0x7C, 0x2C, 0x25, 0x5F, 0x3E, 0x3F,\n");
		output ("\t0xBA, 0x90, 0xBC, 0xBD, 0xBE, 0xF3, 0xC0, 0xC1,\n");
		output ("\t0xC2, 0x60, 0x3A, 0x23, 0x40, 0x27, 0x3D, 0x22,\n");
		output ("\t0xC3, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,\n");
		output ("\t0x68, 0x69, 0xAE, 0xAF, 0xC6, 0xC7, 0xC8, 0xF1,\n");
		output ("\t0xF8, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,\n");
		output ("\t0x71, 0x72, 0xA6, 0xA7, 0x91, 0xCE, 0x92, 0xA9,\n");
		output ("\t0xE6, 0x7E, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,\n");
		output ("\t0x79, 0x7A, 0xAD, 0xA8, 0xD4, 0x5B, 0xD6, 0xD7,\n");
		output ("\t0x9B, 0x9C, 0x9D, 0xFA, 0x9F, 0xB1, 0xB0, 0xAC,\n");
		output ("\t0xAB, 0xFC, 0xAA, 0xFE, 0xE4, 0x5D, 0xBF, 0xE7,\n");
		output ("\t0x7B, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,\n");
		output ("\t0x48, 0x49, 0xE8, 0x93, 0x94, 0x95, 0xA2, 0xED,\n");
		output ("\t0x7D, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,\n");
		output ("\t0x51, 0x52, 0xEE, 0x96, 0x81, 0x97, 0xA3, 0x98,\n");
		output ("\t0x5C, 0xF0, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,\n");
		output ("\t0x59, 0x5A, 0xFD, 0xF5, 0x99, 0xF7, 0xF6, 0xF9,\n");
		output ("\t0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,\n");
		output ("\t0x38, 0x39, 0xDB, 0xFB, 0x9A, 0xF4, 0xEA, 0xFF\n");
		output ("};\n");
		if (gen_ebcdic_ascii > 1) {
			i = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
			output
			    ("static cob_field f_ebcdic_ascii = { 256, (cob_u8_ptr)cob_ebcdic_ascii, &%s%d };\n",
			     CB_PREFIX_ATTR, i);
		}
		output_storage ("\n");
	}
	if (gen_native) {
		output_storage ("\n/* NATIVE table */\n");
		output ("static const unsigned char\tcob_native[256] = {\n");
		output ("\t0, 1, 2, 3, 4, 5, 6, 7,\n");
		output ("\t8, 9, 10, 11, 12, 13, 14, 15,\n");
		output ("\t16, 17, 18, 19, 20, 21, 22, 23,\n");
		output ("\t24, 25, 26, 27, 28, 29, 30, 31,\n");
		output ("\t32, 33, 34, 35, 36, 37, 38, 39,\n");
		output ("\t40, 41, 42, 43, 44, 45, 46, 47,\n");
		output ("\t48, 49, 50, 51, 52, 53, 54, 55,\n");
		output ("\t56, 57, 58, 59, 60, 61, 62, 63,\n");
		output ("\t64, 65, 66, 67, 68, 69, 70, 71,\n");
		output ("\t72, 73, 74, 75, 76, 77, 78, 79,\n");
		output ("\t80, 81, 82, 83, 84, 85, 86, 87,\n");
		output ("\t88, 89, 90, 91, 92, 93, 94, 95,\n");
		output ("\t96, 97, 98, 99, 100, 101, 102, 103,\n");
		output ("\t104, 105, 106, 107, 108, 109, 110, 111,\n");
		output ("\t112, 113, 114, 115, 116, 117, 118, 119,\n");
		output ("\t120, 121, 122, 123, 124, 125, 126, 127,\n");
		output ("\t128, 129, 130, 131, 132, 133, 134, 135,\n");
		output ("\t136, 137, 138, 139, 140, 141, 142, 143,\n");
		output ("\t144, 145, 146, 147, 148, 149, 150, 151,\n");
		output ("\t152, 153, 154, 155, 156, 157, 158, 159,\n");
		output ("\t160, 161, 162, 163, 164, 165, 166, 167,\n");
		output ("\t168, 169, 170, 171, 172, 173, 174, 175,\n");
		output ("\t176, 177, 178, 179, 180, 181, 182, 183,\n");
		output ("\t184, 185, 186, 187, 188, 189, 190, 191,\n");
		output ("\t192, 193, 194, 195, 196, 197, 198, 199,\n");
		output ("\t200, 201, 202, 203, 204, 205, 206, 207,\n");
		output ("\t208, 209, 210, 211, 212, 213, 214, 215,\n");
		output ("\t216, 217, 218, 219, 220, 221, 222, 223,\n");
		output ("\t224, 225, 226, 227, 228, 229, 230, 231,\n");
		output ("\t232, 233, 234, 235, 236, 237, 238, 239,\n");
		output ("\t240, 241, 242, 243, 244, 245, 246, 247,\n");
		output ("\t248, 249, 250, 251, 252, 253, 254, 255\n");
		output ("};\n");
		if (gen_native > 1) {
			i = lookup_attr (COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL, 0);
			output
			    ("static cob_field f_native = { 256, (cob_u8_ptr)cob_native, &%s%d };\n",
			     CB_PREFIX_ATTR, i);
		}
		output_storage ("\n");
	}

	/* Strings */
	if (string_cache) {
		output_storage ("\n/* Strings */\n");
		string_cache = string_list_reverse (string_cache);
		for (stp = string_cache; stp; stp = stp->next) {
			output ("static const char %s%d[]\t= \"%s\";\n",
				CB_PREFIX_STRING, stp->id, stp->text);
		}
		output_storage ("\n");
	}

	/* Optimizer output */
	for (optidx = COB_OPTIM_MIN; optidx < COB_OPTIM_MAX; ++optidx) {
		if (optimize_defs[optidx]) {
			cob_gen_optim (optidx);
			output_storage ("\n");
		}
	}
}
