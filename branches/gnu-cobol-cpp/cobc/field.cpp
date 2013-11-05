/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While
   Copyright (C) 2013 Sergey Kashyrin

   This file is part of GNU Cobol C++.

   The GNU Cobol C++ compiler is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol C++ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#include "cobc.h"
#include "tree.h"

/* Global variables */

cb_tree			cb_depend_check = NULL;
size_t			cb_needs_01 = 0;

/* Local variables */

static cb_field *	last_real_field = NULL;
static int			occur_align_size = 0;
static const int	pic_digits[] = { 2, 4, 7, 9, 12, 14, 16, 18 };

int
cb_get_level(cb_tree x)
{
	if(CB_INVALID_TREE(x)) {
		return 0;
	}
	const char * name = CB_NAME(x);
	int level = 0;
	/* Get level */
	for(const unsigned char * p = (const unsigned char *)name; *p; p++) {
		if(!isdigit((int)(*p))) {
			goto level_error;
		}
		level = level * 10 +(*p - '0');
		if(level > 88) {
			goto level_error;
		}
	}

	/* Check level */
	switch(level) {
	case 66:
	case 77:
	case 78:
	case 88:
		break;
	default:
		if(level < 1 || level > 49) {
			goto level_error;
		}
		break;
	}

	return level;

level_error:
	cb_error_x(x, _("Invalid level number '%s'"), name);
	return 0;
}

cb_tree
cb_build_field_tree(cb_tree level, cb_tree name, cb_field * last_field,
					enum cb_storage storage, cb_file * fn,
					const int expl_level)
{
	int lv;

	if(!expl_level) {
		if(level == cb_error_node || name == cb_error_node) {
			return cb_error_node;
		}
		/* Check the level number */
		lv = cb_get_level(level);
		if(!lv) {
			return cb_error_node;
		}
	} else {
		lv = expl_level;
	}

	/* Build the field */
	cb_reference * r = CB_REFERENCE(name);
	cb_field * f = CB_FIELD(cb_build_field(name));

	f->storage = storage;
	last_real_field = last_field;
	if(lv == 78) {
		f->level = 01;
		f->flag_item_78 = 1;
		return f;
	} else {
		f->level = lv;
	}
	if(f->level == 01 && storage == CB_STORAGE_FILE && fn) {
		if(fn->flag_external) {
			f->flag_external = 1;
			current_program->flag_has_external = 1;
		} else if(fn->flag_global) {
			f->flag_is_global = 1;
		}
	}
	if(last_field) {
		if(last_field->level == 77 && f->level != 01 &&
				f->level != 77 && f->level != 66 && f->level != 88) {
			cb_error_x(name, _("Level number must begin with 01 or 77"));
			return cb_error_node;
		}
	}

	/* Checks for redefinition */
	if(cb_warn_redefinition && r->word->count > 1 && !r->flag_filler_ref) {
		if(f->level == 01 || f->level == 77) {
			redefinition_warning(name, NULL);
		} else {
			for(cb_tree l = r->word->items; l; l = CB_CHAIN(l)) {
				cb_tree x = CB_VALUE(l);
				if(!CB_FIELD_P(x) ||
						CB_FIELD(x)->level == 01 ||
						CB_FIELD(x)->level == 77 ||
						(last_field && f->level == last_field->level &&
						 CB_FIELD(x)->parent == last_field->parent))
				{
					redefinition_warning(name, x);
					break;
				}
			}
		}
	}

	if(last_field && last_field->level == 88) {
		last_field = last_field->parent;
	}

	/* Link the field into the tree */
	if(f->level == 01 || f->level == 77) {
		/* Top level */
		cb_needs_01 = 0;
		if(last_field) {
			cb_field_founder(last_field)->sister = f;
		}
	} else if(!last_field || cb_needs_01) {
		/* Invalid top level */
		cb_error_x(name, _("Level number must begin with 01 or 77"));
		return cb_error_node;
	} else if(f->level == 66) {
		/* Level 66 */
		f->parent = cb_field_founder(last_field);
		cb_field * p;
		for(p = f->parent->children; p && p->sister; p = p->sister) ;
		if(p) {
			p->sister = f;
		}
	} else if(f->level == 88) {
		/* Level 88 */
		f->parent = last_field;
	} else if(f->level > last_field->level) {
		/* Lower level */
		last_field->children = f;
		f->parent = last_field;
	} else if(f->level == last_field->level) {
		/* Same level */
same_level:
		last_field->sister = f;
		f->parent = last_field->parent;
	} else {
		/* Upper level */
		cb_field * p;
		for(p = last_field->parent; p; p = p->parent) {
			if(p->level == f->level) {
				last_field = p;
				goto same_level;
			}
			if(cb_relax_level_hierarchy && p->level < f->level) {
				break;
			}
		}
		if(cb_relax_level_hierarchy) {
			cb_tree dummy_fill = cb_build_filler();
			cb_field * field_fill = CB_FIELD(cb_build_field(dummy_fill));
			cb_warning_x(name,
						 _("No previous data item of level %02d"),
						 f->level);
			field_fill->level = f->level;
			field_fill->flag_filler = 1;
			field_fill->storage = storage;
			field_fill->children = p->children;
			field_fill->parent = p;
			for(p = p->children; p; p = p->sister) {
				p->parent = field_fill;
			}
			field_fill->parent->children = field_fill;
			field_fill->sister = f;
			f->parent = field_fill->parent;
			/* last_field = field_fill; */
		} else {
			cb_error_x(name,
					   _("No previous data item of level %02d"),
					   f->level);
			return cb_error_node;
		}
	}

	/* Inherit parents properties */
	if(f->parent) {
		f->usage = f->parent->usage;
		f->indexes = f->parent->indexes;
		f->flag_sign_leading = f->parent->flag_sign_leading;
		f->flag_sign_separate = f->parent->flag_sign_separate;
		f->flag_is_global = f->parent->flag_is_global;
	}
	return f;
}

cb_field *
cb_resolve_redefines(cb_field * field, cb_tree redefines)
{
	cb_reference * r = CB_REFERENCE(redefines);
	const char * name = CB_NAME(redefines);
	cb_tree x = field;

	/* Check qualification */
	if(r->chain) {
		cb_error_x(x, _("'%s' cannot be qualified here"), name);
		return NULL;
	}

	/* Check subscripts */
	if(r->subs) {
		cb_error_x(x, _("'%s' cannot be subscripted here"), name);
		return NULL;
	}

	cb_field * f;
	/* Resolve the name in the current group(if any) */
	if(field->parent && field->parent->children) {
		for(f = field->parent->children; f; f = f->sister) {
			if(strcasecmp(f->name, name) == 0) {
				break;
			}
		}
		if(f == NULL) {
			cb_error_x(x, _("'%s' is not defined in '%s'"), name, field->parent->name);
			return NULL;
		}
	} else {
		/* Get last defined name */
		cb_tree candidate = NULL;
		for(cb_tree items = r->word->items; items; items = CB_CHAIN(items)) {
			if(CB_FIELD_P(CB_VALUE(items))) {
				candidate = CB_VALUE(items);
			}
		}
		if(!candidate) {
			undefined_error(redefines);
			return NULL;
		}
		f = CB_FIELD_PTR(candidate);
	}

	/* Check level number */
	if(f->level != field->level) {
		cb_error_x(x, _("Level number of REDEFINES entries must be identical"));
		return NULL;
	}
	if(f->level == 66 || f->level == 88) {
		cb_error_x(x, _("Level number of REDEFINES entry cannot be 66 or 88"));
		return NULL;
	}

	if(!cb_indirect_redefines && f->redefines) {
		cb_error_x(x, _("'%s' not the original definition"), f->name);
		return NULL;
	}

	/* Return the original definition */
	while(f->redefines) {
		f = f->redefines;
	}
	return f;
}

static void
validate_field_clauses(cb_tree x, cb_field * f)
{
	if(f->flag_blank_zero) {
		cb_error_x(x, _("BLANK ZERO not compatible with USAGE"));
	}
	if(f->flag_sign_leading || f->flag_sign_separate) {
		cb_error_x(x, _("SIGN clause not compatible with USAGE"));
	}
}

static unsigned int
check_picture_item(cb_tree x, cb_field * f)
{
	char pic[24];

	if(f->storage == CB_STORAGE_SCREEN) {
		/* RXWRXW Fixme - Corner cases */
		if(f->values) {
			sprintf(pic, "X(%d)", (int)CB_LITERAL(CB_VALUE(f->values))->size);
		} else if(f->screen_from) {
			sprintf(pic, "X(%d)", (int)CB_FIELD_PTR(f->screen_from)->size);
		} else if(f->screen_to) {
			sprintf(pic, "X(%d)", (int)CB_FIELD_PTR(f->screen_to)->size);
		} else {
			f->flag_no_field = 1;
			strcpy(pic, "X(1)");
		}
		f->pic = CB_PICTURE(cb_build_picture(pic));
		return 0;
	}
	if(f->flag_item_78) {
		if(!f->values || CB_VALUE(f->values) == cb_error_node) {
			level_require_error(x, "VALUE");
			return 1;
		}
		f->count++;
		cb_literal * lp = CB_LITERAL(CB_VALUE(f->values));
		if(CB_NUMERIC_LITERAL_P(CB_VALUE(f->values))) {
			memset(pic, 0, sizeof(pic));
			char * pp = pic;
			if(lp->sign) {
				*pp++ = 'S';
			}
			int vorint = (int)lp->size - lp->scale;
			if(vorint) {
				pp += sprintf(pp, "9(%d)", vorint);
			}
			if(lp->scale) {
				sprintf(pp, "V9(%d)", lp->scale);
			}
			if(lp->size < 10) {
				f->usage = CB_USAGE_COMP_5;
			} else {
				f->usage = CB_USAGE_DISPLAY;
			}
			f->pic = CB_PICTURE(cb_build_picture(pic));
			f->pic->category = CB_CATEGORY_NUMERIC;
		} else {
			sprintf(pic, "X(%d)", (int)lp->size);
			f->pic = CB_PICTURE(cb_build_picture(pic));
			f->pic->category = CB_CATEGORY_ALPHANUMERIC;
			f->usage = CB_USAGE_DISPLAY;
		}
		return 0;
	}
	if(f->level == 1) {
		cb_error_x(x, _("PICTURE clause required for '%s'"),
				   cb_name(x));
		return 1;
	}
	if(!f->values || CB_VALUE(f->values) == cb_error_node) {
		cb_error_x(x, _("PICTURE clause required for '%s'"),
				   cb_name(x));
		return 1;
	}
	if(CB_NUMERIC_LITERAL_P(CB_VALUE(f->values))) {
		cb_error_x(x, _("A non-numeric literal is expected for '%s'"),
				   cb_name(x));
		return 1;
	}
	int vorint = (int)CB_LITERAL(CB_VALUE(f->values))->size;
	if(warningopt) {
		cb_warning_x(x, _("Defining implicit picture size %d for '%s'"), vorint, cb_name(x));
	}
	sprintf(pic, "X(%d)", vorint);
	f->pic = CB_PICTURE(cb_build_picture(pic));
	f->pic->category = CB_CATEGORY_ALPHANUMERIC;
	f->usage = CB_USAGE_DISPLAY;
	return 0;
}

static unsigned int
validate_field_1(cb_field * f)
{
	if(f->flag_invalid) {
		return 1;
	}
	cb_tree x = f;
	if(f->flag_any_length) {
		if(f->storage != CB_STORAGE_LINKAGE) {
			cb_error_x(x, _("'%s' ANY LENGTH only allowed in LINKAGE"), cb_name(x));
			return 1;
		}
		if(f->level != 01) {
			cb_error_x(x, _("'%s' ANY LENGTH must be 01 level"), cb_name(x));
			return 1;
		}
		if(f->flag_item_based || f->flag_external) {
			cb_error_x(x, _("'%s' ANY LENGTH can not be BASED/EXTERNAL"), cb_name(x));
			return 1;
		}
		if(f->flag_occurs || f->depending ||
				f->children || f->values || f->flag_blank_zero) {
			cb_error_x(x, _("'%s' ANY LENGTH has invalid definition"), cb_name(x));
			return 1;
		}
		if(!f->pic) {
			if(f->flag_any_numeric) {
				f->pic = CB_PICTURE(cb_build_picture("9"));
			} else {
				f->pic = CB_PICTURE(cb_build_picture("X"));
			}
#if	0	/* RXWRXW - ANY length */
			cb_error_x(x, _("'%s' ANY LENGTH must have a PICTURE"), cb_name(x));
			return 1;
#endif
		}
		if(f->pic->size != 1 || f->usage != CB_USAGE_DISPLAY) {
			cb_error_x(x, _("'%s' ANY LENGTH has invalid definition"), cb_name(x));
			return 1;
		}
		f->count++;
		return 0;
	}

	if(f->level == 77) {
		if(f->storage != CB_STORAGE_WORKING &&
				f->storage != CB_STORAGE_LOCAL &&
				f->storage != CB_STORAGE_LINKAGE) {
			cb_error_x(x, _("'%s' 77 level not allowed here"), cb_name(x));
		}
	}
	if(f->flag_external) {
		if(f->level != 01 && f->level != 77) {
			cb_error_x(x, _("'%s' EXTERNAL must be specified at 01/77 level"), cb_name(x));
		}
		if(f->storage != CB_STORAGE_WORKING &&
				f->storage != CB_STORAGE_FILE) {
			cb_error_x(x, _("'%s' EXTERNAL can only be specified in WORKING-STORAGE section"),
					   cb_name(x));
		}
		if(f->flag_item_based) {
			cb_error_x(x, _("'%s' EXTERNAL and BASED are mutually exclusive"), cb_name(x));
		}
		if(f->redefines) {
			cb_error_x(x, _("'%s' EXTERNAL not allowed with REDEFINES"), cb_name(x));
		}
	}
	if(f->flag_item_based) {
		if(f->storage != CB_STORAGE_WORKING &&
				f->storage != CB_STORAGE_LOCAL &&
				f->storage != CB_STORAGE_LINKAGE) {
			cb_error_x(x, _("'%s' BASED not allowed here"), cb_name(x));
		}
		if(f->redefines) {
			cb_error_x(x, _("'%s' BASED not allowed with REDEFINES"), cb_name(x));
		}
		if(f->level != 01 && f->level != 77) {
			cb_error_x(x, _("'%s' BASED only allowed at the 01 and 77 levels"), cb_name(x));
		}
	}
	if(f->level == 66) {
		if(!f->redefines) {
			level_require_error(x, "RENAMES");
			return 1;
		}
		if(f->flag_occurs) {
			level_except_error(x, "RENAMES");
		}
		return 0;
	}

	/* Validate OCCURS */
	if(f->flag_occurs) {
		if((!cb_verify(cb_top_level_occurs_clause, "01/77 OCCURS") &&
				(f->level == 01 || f->level == 77)) ||
				(f->level == 66 || f->level == 88)) {
			level_redundant_error(x, "OCCURS");
		}
		for(cb_tree l = f->index_list; l; l = CB_CHAIN(l)) {
			CB_FIELD_PTR(CB_VALUE(l))->flag_is_global = f->flag_is_global;
		}
	}

	/* Validate OCCURS DEPENDING */
	if(f->depending) {
		/* The data item that contains a OCCURS DEPENDING clause shall not
		   be subordinate to a data item that has an OCCURS clause */
		for(cb_field * p = f->parent; p; p = p->parent) {
			if(p->flag_occurs) {
				cb_error_x(p,
						   _("'%s' cannot have the OCCURS clause due to '%s'"),
						   cb_name(p),
						   cb_name(x));
				break;
			}
		}

		/* Cache field for later checking */
		cb_depend_check = cb_list_add(cb_depend_check, x);
	}

	/* Validate REDEFINES */
	if(f->redefines) {
		/* Check OCCURS */
		if(f->redefines->flag_occurs) {
			cb_warning_x(x, _("The original definition '%s' should not have OCCURS"),
						 f->redefines->name);
		}

		/* Check definition */
		for(cb_field * p = f->redefines->sister; p && p != f; p = p->sister) {
			if(!p->redefines) {
				cb_error_x(x, _("REDEFINES must follow the original definition"));
				break;
			}
		}

		/* Check variable occurrence */
		if(f->depending || cb_field_variable_size(f)) {
			cb_error_x(x, _("'%s' cannot be variable length"), f->name);
		}
		if(cb_field_variable_size(f->redefines)) {
			cb_error_x(x,
					   _("The original definition '%s' cannot be variable length"),
					   f->redefines->name);
		}
	}

	if(f->children) {
		/* Group item */

		if(f->pic) {
			group_error(x, "PICTURE");
		}
		if(f->flag_justified) {
			group_error(x, "JUSTIFIED RIGHT");
		}
		if(f->flag_blank_zero) {
			group_error(x, "BLANK WHEN ZERO");
		}

		unsigned int ret = 0;
		if(f->storage == CB_STORAGE_SCREEN &&
				(f->screen_from || f->screen_to || f->values || f->pic)) {
			cb_error_x(x, _("SCREEN group item '%s' has invalid clause"),
					   cb_name(x));
			ret = 1;
		}
		for(f = f->children; f; f = f->sister) {
			ret |= validate_field_1(f);
		}
		if(ret) {
			return 1;
		}
	} else {
		/* Elementary item */

		bool need_picture;
		/* Validate PICTURE */
		switch(f->usage) {
		case CB_USAGE_INDEX:
		case CB_USAGE_LENGTH:
		case CB_USAGE_OBJECT:
		case CB_USAGE_POINTER:
		case CB_USAGE_PROGRAM_POINTER:
		case CB_USAGE_FLOAT:
		case CB_USAGE_DOUBLE:
		case CB_USAGE_LONG_DOUBLE:
		case CB_USAGE_FP_BIN32:
		case CB_USAGE_FP_BIN64:
		case CB_USAGE_FP_BIN128:
		case CB_USAGE_FP_DEC64:
		case CB_USAGE_FP_DEC128:
		case CB_USAGE_SIGNED_CHAR:
		case CB_USAGE_SIGNED_SHORT:
		case CB_USAGE_SIGNED_INT:
		case CB_USAGE_SIGNED_LONG:
		case CB_USAGE_UNSIGNED_CHAR:
		case CB_USAGE_UNSIGNED_SHORT:
		case CB_USAGE_UNSIGNED_INT:
		case CB_USAGE_UNSIGNED_LONG:
		case CB_USAGE_PROGRAM:
			need_picture = false;
			break;
		default:
			need_picture = true;
			break;
		}

		if(f->pic == NULL && need_picture) {
			if(check_picture_item(x, f)) {
				return 1;
			}
		}
		if(f->pic != NULL && !need_picture) {
			cb_error_x(x, _("'%s' cannot have PICTURE clause"),
					   cb_name(x));
		}

		/* Validate USAGE */
		switch(f->usage) {
		case CB_USAGE_DISPLAY:
			if(current_program->flag_trailing_separate &&
					f->pic &&
					f->pic->category == CB_CATEGORY_NUMERIC &&
					!f->flag_sign_leading) {
				f->flag_sign_separate = 1;
			}
			break;
		case CB_USAGE_SIGNED_CHAR:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-CHAR", 2, 1);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_SIGNED_SHORT:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-SHORT", 4, 1);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_SIGNED_INT:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-LONG", 9, 1);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_SIGNED_LONG:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-DOUBLE", 18, 1);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_UNSIGNED_CHAR:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-CHAR", 2, 0);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_UNSIGNED_SHORT:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-SHORT", 4, 0);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_UNSIGNED_INT:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-LONG", 9, 0);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_UNSIGNED_LONG:
			f->usage = CB_USAGE_COMP_5;
			f->pic = cb_build_binary_picture("BINARY-DOUBLE", 18, 0);
			f->flag_real_binary = 1;
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_BINARY:
		case CB_USAGE_PACKED:
		case CB_USAGE_BIT:
			if(f->pic->category != CB_CATEGORY_NUMERIC) {
				cb_error_x(x, _("'%s' PICTURE clause not compatible with USAGE"), cb_name(x));
			}
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_COMP_6:
			if(f->pic->category != CB_CATEGORY_NUMERIC) {
				cb_error_x(x, _("'%s' PICTURE clause not compatible with USAGE"), cb_name(x));
			}
			if(f->pic->have_sign) {
				cb_warning_x(x, _("'%s' COMP-6 with sign - Changing to COMP-3"), cb_name(x));
				f->usage = CB_USAGE_PACKED;
			}
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
			if(f->pic) {
				if(f->pic->category != CB_CATEGORY_NUMERIC &&
						f->pic->category != CB_CATEGORY_ALPHANUMERIC) {
					cb_error_x(x, _("'%s' PICTURE clause not compatible with USAGE"), cb_name(x));
				}
			}
			validate_field_clauses(x, f);
			break;
		case CB_USAGE_POINTER:
		case CB_USAGE_PROGRAM_POINTER:
		case CB_USAGE_PROGRAM:
		case CB_USAGE_FLOAT:
		case CB_USAGE_DOUBLE:
		case CB_USAGE_LONG_DOUBLE:
		case CB_USAGE_FP_BIN32:
		case CB_USAGE_FP_BIN64:
		case CB_USAGE_FP_BIN128:
		case CB_USAGE_FP_DEC64:
		case CB_USAGE_FP_DEC128:
		case CB_USAGE_INDEX:
			validate_field_clauses(x, f);
			break;
		default:
			break;
		}

		/* Validate SIGN */

		/* Validate JUSTIFIED RIGHT */
		if(f->flag_justified) {
			switch(f->pic->category) {
			case CB_CATEGORY_ALPHABETIC:
			case CB_CATEGORY_ALPHANUMERIC:
				break;
			default:
				cb_error_x(x, _("'%s' cannot have JUSTIFIED RIGHT"), cb_name(x));
				break;
			}
		}

		/* Validate SYNCHRONIZED */

		/* Validate BLANK ZERO */
		if(f->flag_blank_zero) {
			int n = 0;
			switch(f->pic->category) {
			case CB_CATEGORY_NUMERIC:
				/* Reconstruct the picture string */
				if(f->pic->scale > 0) {
					/* Enough for genned string */
					f->pic->str = (char *) cobc_parse_malloc((size_t)32);
					unsigned char * pstr = (unsigned char *)(f->pic->str);
					if(f->pic->have_sign) {
						*pstr++ = '+';
						int vorint = 1;
						memcpy(pstr, (void *)&vorint, sizeof(int));
						pstr += sizeof(int);
						n = 5;
					}
					*pstr++ = '9';
					int vorint = (int)f->pic->digits - f->pic->scale;
					memcpy(pstr, (void *)&vorint, sizeof(int));
					pstr += sizeof(int);
					*pstr++ = 'V';
					vorint = 1;
					memcpy(pstr, (void *)&vorint, sizeof(int));
					pstr += sizeof(int);
					*pstr++ = '9';
					vorint = f->pic->scale;
					memcpy(pstr, (void *)&vorint, sizeof(int));
					f->pic->size++;
					n += 15;
				} else {
					/* Enough for genned string */
					f->pic->str = (char *) cobc_parse_malloc((size_t)16);
					unsigned char * pstr = (unsigned char *)(f->pic->str);
					if(f->pic->have_sign) {
						*pstr++ = '+';
						int vorint = 1;
						memcpy(pstr, (void *)&vorint, sizeof(int));
						pstr += sizeof(int);
						n = 5;
					}
					*pstr++ = '9';
					int vorint = f->pic->digits;
					memcpy(pstr, (void *)&vorint, sizeof(int));
					n += 5;
				}
				f->pic->lenstr = n;
				f->pic->category = CB_CATEGORY_NUMERIC_EDITED;
				break;
			case CB_CATEGORY_NUMERIC_EDITED:
				break;
			default:
				cb_error_x(x, _("'%s' cannot have BLANK WHEN ZERO"), cb_name(x));
				break;
			}
		}

		/* Validate VALUE */
		if(f->values) {
			if(CB_PAIR_P(CB_VALUE(f->values)) || CB_CHAIN(f->values)) {
				cb_error_x(x, _("Only level 88 item may have multiple values"));
			}

			/* ISO+IEC+1989-2002: 13.16.42.2-10 */
			for(cb_field * p = f; p; p = p->parent) {
				if(p->redefines) {
					cb_error_x(x, _("Entries under REDEFINES cannot have a VALUE clause"));
				}
				if(p->flag_external && cb_warn_external_val) {
					cb_warning_x(x, _("Initial VALUE clause ignored for EXTERNAL item"));
				}
			}
		}
	}

	return 0;
}

static void
setup_parameters(cb_field * f)
{
	/* Determine the class */
	if(f->children) {
		/* Group field */
		unsigned int flag_local = f->flag_local;
		for(f = f->children; f; f = f->sister) {
			f->flag_local = !!flag_local;
			setup_parameters(f);
		}
	} else {
		/* Regular field */
		switch(f->usage) {
		case CB_USAGE_BINARY:
#ifndef WORDS_BIGENDIAN
			if(cb_binary_byteorder == CB_BYTEORDER_BIG_ENDIAN) {
				f->flag_binary_swap = 1;
			}
#endif
			break;

		case CB_USAGE_INDEX:
			f->pic = CB_PICTURE(cb_build_picture("S9(9)"));
			break;

		case CB_USAGE_LENGTH:
			f->pic = CB_PICTURE(cb_build_picture("9(9)"));
			break;

		case CB_USAGE_POINTER:
		case CB_USAGE_PROGRAM_POINTER:
			f->pic = CB_PICTURE(cb_build_picture("9(10)"));
			break;
		case CB_USAGE_FLOAT:
			f->pic = CB_PICTURE(cb_build_picture("S9(7)V9(8)"));
			break;
		case CB_USAGE_DOUBLE:
			f->pic = CB_PICTURE(cb_build_picture("S9(17)V9(17)"));
			break;
		case CB_USAGE_FP_DEC64:
			/* RXWRXW - Scale Fix me */
			f->pic = CB_PICTURE(cb_build_picture("S9(17)V9(16)"));
			break;
		case CB_USAGE_FP_DEC128:
			/* RXWRXW - Scale Fix me */
			f->pic = CB_PICTURE(cb_build_picture("S999V9(34)"));
			break;

		case CB_USAGE_COMP_5:
		case CB_USAGE_COMP_X:
			if(f->pic->category == CB_CATEGORY_ALPHANUMERIC) {
				char pic[8];
				if(f->pic->size > 8) {
					strcpy(pic, "9(36)");
				} else {
					sprintf(pic, "9(%d)", pic_digits[f->pic->size - 1]);
				}
				f->pic = CB_PICTURE(cb_build_picture(pic));
			}
#ifndef WORDS_BIGENDIAN
			if(f->usage == CB_USAGE_COMP_X &&
					cb_binary_byteorder == CB_BYTEORDER_BIG_ENDIAN) {
				f->flag_binary_swap = 1;
			}
#endif
			break;

		default:
			break;
		}
	}
}

static void
compute_binary_size(cb_field * f, const int size)
{
	if(cb_binary_size == CB_BINARY_SIZE_1_2_4_8) {
		f->size = ((size <= 2) ? 1 :
				   (size <= 4) ? 2 :
				   (size <= 9) ? 4 :(size <= 18) ? 8 : 16);
		return;
	}
	if(cb_binary_size == CB_BINARY_SIZE_2_4_8) {
		if(f->flag_real_binary && size <= 2) {
			f->size = 1;
		} else {
			f->size = ((size <= 4) ? 2 :
					   (size <= 9) ? 4 :(size <= 18) ? 8 : 16);
		}
		return;
	}
	if(cb_binary_size != CB_BINARY_SIZE_1__8) {
		f->size = size;
		return;
	}
	if(f->pic->have_sign) {
		switch(size) {
		case 0:
		case 1:
		case 2:
			f->size = 1;
			return;
		case 3:
		case 4:
			f->size = 2;
			return;
		case 5:
		case 6:
			f->size = 3;
			return;
		case 7:
		case 8:
		case 9:
			f->size = 4;
			return;
		case 10:
		case 11:
			f->size = 5;
			return;
		case 12:
		case 13:
		case 14:
			f->size = 6;
			return;
		case 15:
		case 16:
			f->size = 7;
			return;
		case 17:
		case 18:
			f->size = 8;
			return;
		case 19:
		case 20:
		case 21:
			f->size = 9;
			return;
		case 22:
		case 23:
			f->size = 10;
			return;
		case 24:
		case 25:
		case 26:
			f->size = 11;
			return;
		case 27:
		case 28:
			f->size = 12;
			return;
		case 29:
		case 30:
		case 31:
			f->size = 13;
			return;
		case 32:
		case 33:
			f->size = 14;
			return;
		case 34:
		case 35:
			f->size = 15;
			return;
		default:
			f->size = 16;
			return;
		}
	}
	switch(size) {
	case 0:
	case 1:
	case 2:
		f->size = 1;
		return;
	case 3:
	case 4:
		f->size = 2;
		return;
	case 5:
	case 6:
	case 7:
		f->size = 3;
		return;
	case 8:
	case 9:
		f->size = 4;
		return;
	case 10:
	case 11:
	case 12:
		f->size = 5;
		return;
	case 13:
	case 14:
		f->size = 6;
		return;
	case 15:
	case 16:
		f->size = 7;
		return;
	case 17:
	case 18:
	case 19:
		f->size = 8;
		return;
	case 20:
	case 21:
		f->size = 9;
		return;
	case 22:
	case 23:
	case 24:
		f->size = 10;
		return;
	case 25:
	case 26:
		f->size = 11;
		return;
	case 27:
	case 28:
		f->size = 12;
		return;
	case 29:
	case 30:
	case 31:
		f->size = 13;
		return;
	case 32:
	case 33:
		f->size = 14;
		return;
	case 34:
	case 35:
	case 36:
		f->size = 15;
		return;
	default:
		f->size = 16;
		return;
	}
}

static int
compute_size(cb_field * f)
{
	if(f->level == 66) {
		/* Rename */
		if(f->rename_thru) {
			f->size = f->rename_thru->offset + f->rename_thru->size -
					  f->redefines->offset;
		} else {
			f->size = f->redefines->size;
		}
		return f->size;
	}

	if(f->children) {
		/* Groups */
		if(f->flag_synchronized && warningopt) {
			cb_warning_x(f, _("Ignoring SYNCHRONIZED for group item '%s'"),
						 cb_name(f));
		}
		int size = 0;
		occur_align_size = 1;
		for(cb_field * c = f->children; c; c = c->sister) {
			if(c->redefines) {
				c->offset = c->redefines->offset;
				compute_size(c);
				/* Increase the size if redefinition is larger */
				if(c->level != 66 &&
						c->size * c->occurs_max >
						c->redefines->size * c->redefines->occurs_max) {
					if(cb_larger_redefines_ok) {
						cb_warning_x(c,
									 _("Size of '%s' larger than size of '%s'"),
									 c->name, c->redefines->name);
						size +=
							(c->size * c->occurs_max) -
							(c->redefines->size *
							 c->redefines->occurs_max);
					} else {
						cb_error_x(c,
								   _("Size of '%s' larger than size of '%s'"),
								   c->name, c->redefines->name);
					}
				}
			} else {
				c->offset = f->offset + size;
				size += compute_size(c) * c->occurs_max;

				/* Word alignment */
				if(c->flag_synchronized &&
						cb_verify(cb_synchronized_clause, "SYNC")) {
					int align_size = 1;
					switch(c->usage) {
					case CB_USAGE_BINARY:
					case CB_USAGE_COMP_5:
					case CB_USAGE_COMP_X:
					case CB_USAGE_FLOAT:
					case CB_USAGE_DOUBLE:
					case CB_USAGE_LONG_DOUBLE:
					case CB_USAGE_FP_BIN32:
					case CB_USAGE_FP_BIN64:
					case CB_USAGE_FP_BIN128:
					case CB_USAGE_FP_DEC64:
					case CB_USAGE_FP_DEC128:
						if(c->size == 2 ||
								c->size == 4 ||
								c->size == 8 ||
								c->size == 16) {
							align_size = c->size;
						}
						break;
					case CB_USAGE_INDEX:
					case CB_USAGE_LENGTH:
						align_size = sizeof(int);
						break;
					case CB_USAGE_OBJECT:
					case CB_USAGE_POINTER:
					case CB_USAGE_PROGRAM_POINTER:
					case CB_USAGE_PROGRAM:
						align_size = sizeof(void *);
						break;
					default:
						break;
					}
					if(c->offset % align_size != 0) {
						int pad = align_size -(c->offset % align_size);
						c->offset += pad;
						size += pad;
					}
					if(align_size > occur_align_size) {
						occur_align_size = align_size;
					}
				}
			}
		}
		if(f->occurs_max > 1 &&(size % occur_align_size) != 0) {
			int pad = occur_align_size -(size % occur_align_size);
			size += pad;
			f->offset += pad;
		}
		f->size = size;
	} else {
		/* Elementary item */
		int size;
		switch(f->usage) {
		case CB_USAGE_COMP_X:
			if(f->pic->category == CB_CATEGORY_ALPHANUMERIC) {
				break;
			}
			size = f->pic->size;
			f->size = ((size <= 2) ? 1 :(size <= 4) ? 2 :
					   (size <= 7) ? 3 :(size <= 9) ? 4 :
					   (size <= 12) ? 5 :(size <= 14) ? 6 :
					   (size <= 16) ? 7 :(size <= 19) ? 8 :
					   (size <= 21) ? 9 :(size <= 24) ? 10 :
					   (size <= 26) ? 11 :(size <= 28) ? 12 :
					   (size <= 31) ? 13 :(size <= 33) ? 14 :
					   (size <= 36) ? 15 : 16);
			break;
		case CB_USAGE_BINARY:
		case CB_USAGE_COMP_5:
			size = f->pic->size;
#if	0	/* RXWRXW - Max binary */
			if(size > COB_MAX_BINARY) {
				f->flag_binary_swap = 0;
				size = 38;
				cb_error_x(CB_TREE(f),
						   _("'%s' binary field cannot be larger than %d digits"),
						   f->name, COB_MAX_BINARY);
			}
#else
			if(size > 18) {
				f->flag_binary_swap = 0;
				size = 18;
				cb_error_x(f,
						   _("'%s' binary field cannot be larger than %d digits"),
						   f->name, 18);
			}
#endif
			compute_binary_size(f, size);
			break;
		case CB_USAGE_DISPLAY:
			f->size = f->pic->size;
			if(f->pic->have_sign && f->flag_sign_separate) {
				f->size++;
			}
			break;
		case CB_USAGE_PACKED:
			f->size = f->pic->size / 2 + 1;
			break;
		case CB_USAGE_COMP_6:
			f->size = (f->pic->size + 1) / 2;
			break;
		case CB_USAGE_INDEX:
		case CB_USAGE_LENGTH:
			f->size = sizeof(int);
			break;
		case CB_USAGE_FLOAT:
			f->size = sizeof(float);
			break;
		case CB_USAGE_DOUBLE:
			f->size = sizeof(double);
			break;
		case CB_USAGE_LONG_DOUBLE:
			f->size = 16;
			break;
		case CB_USAGE_FP_BIN32:
			f->size = 4;
			break;
		case CB_USAGE_FP_BIN64:
		case CB_USAGE_FP_DEC64:
			f->size = 8;
			break;
		case CB_USAGE_FP_BIN128:
		case CB_USAGE_FP_DEC128:
			f->size = 16;
			break;
		case CB_USAGE_OBJECT:
		case CB_USAGE_POINTER:
		case CB_USAGE_PROGRAM_POINTER:
		case CB_USAGE_PROGRAM:
			f->size = sizeof(void *);
			break;
		default:
			cobc_abort_pr(_("Unexpected usage - %d"),
						  (int)f->usage);
			COBC_ABORT();
		}
	}

	/* The size of redefining field should not be larger than
	   the size of redefined field unless the redefined field
	   is level 01 and non-external */
	if(f->redefines && f->redefines->flag_external &&
			(f->size * f->occurs_max > f->redefines->size * f->redefines->occurs_max)) {
		if(cb_larger_redefines_ok) {
			cb_warning_x(f, _("Size of '%s' larger than size of '%s'"),
						 f->name, f->redefines->name);
		} else {
			cb_error_x(f, _("Size of '%s' larger than size of '%s'"),
					   f->name, f->redefines->name);
		}
	}

	return f->size;
}

static int
validate_field_value(cb_field * f)
{
	if(f->values) {
		validate_move(CB_VALUE(f->values), f, true);
	}

	if(f->children) {
		for(f = f->children; f; f = f->sister) {
			validate_field_value(f);
		}
	}

	return 0;
}

void
cb_validate_field(cb_field * f)
{
	if(f->flag_is_verified) {
		return;
	}
	if(validate_field_1(f) != 0) {
		f->flag_invalid = 1;
		return;
	}
	if(f->flag_item_78) {
		f->flag_is_verified = 1;
		return;
	}

	/* Set up parameters */
	if(f->storage == CB_STORAGE_LOCAL ||
			f->storage == CB_STORAGE_LINKAGE ||
			f->flag_item_based) {
		f->flag_local = 1;
	}
	if(f->storage == CB_STORAGE_LINKAGE || f->flag_item_based) {
		f->flag_base = 1;
	}
	setup_parameters(f);

	/* Compute size */
	occur_align_size = 1;
	compute_size(f);
	if(!f->redefines) {
		f->memory_size = f->size * f->occurs_max;
	} else if(f->redefines->memory_size < f->size * f->occurs_max) {
		f->redefines->memory_size = f->size * f->occurs_max;
	}

	validate_field_value(f);
	if(f->flag_is_global) {
		f->count++;
		for(cb_field * c = f->children; c; c = c->sister) {
			c->flag_is_global = 1;
			c->count++;
		}
	}
	f->flag_is_verified = 1;
}

void
cb_validate_88_item(cb_field * f)
{
	if(!f->values) {
		level_require_error(f, "VALUE");
		return;
	}

	if(f->pic || f->flag_occurs) {
		level_except_error(f, "VALUE");
		return;
	}
	if(CB_VALID_TREE(f->parent) && CB_TREE_CLASS(f->parent) == CB_CLASS_NUMERIC) {
		for(cb_tree l = f->values; l; l = CB_CHAIN(l)) {
			cb_tree t = CB_VALUE(l);
			if(t == cb_space || t == cb_low || t == cb_high || t == cb_quote) {
				cb_error_x(f, _("Literal type does not match data type"));
			}
		}
	}
}

cb_field *
cb_validate_78_item(cb_field * f, const cob_u32_t no78add)
{
	cob_u32_t noadd = no78add;
	if(CB_INVALID_TREE(f->values) ||
			CB_INVALID_TREE(CB_VALUE(f->values))) {
		level_require_error(f, "VALUE");
		noadd = 1;
	}

	if(f->pic || f->flag_occurs) {
		level_except_error(f, "VALUE");
		noadd = 1;
	}
	if(!noadd) {
		cb_add_78(f);
	}
	return last_real_field;
}

void
cb_clear_real_field(void)
{
	last_real_field = NULL;
}

cb_field *
cb_get_real_field(void)
{
	return last_real_field;
}
