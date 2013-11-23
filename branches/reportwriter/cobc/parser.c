/* A Bison parser, made by GNU Bison 2.6.4.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 358 of yacc.c  */
#line 28 "parser.y"

#include "config.h"

#include <stdlib.h>
#include <string.h>

#define	COB_IN_PARSER	1
#include "cobc.h"
#include "tree.h"

#ifndef	_STDLIB_H
#define	_STDLIB_H 1
#endif

#define YYSTYPE			cb_tree
#define yyerror			cb_error

#define PENDING(x)		cb_warning (_("'%s' not implemented"), x)
#define PENDINGDEV(x)		cb_warning (_("'%s' currently in development"), x)

#define emit_statement(x) \
do { \
  if (!skip_statements) { \
	CB_ADD_TO_CHAIN (x, current_program->exec_list); \
  } \
} while (0)

#define push_expr(type, node) \
  current_expr = cb_build_list (cb_int (type), node, current_expr)

/* Statement terminator definitions */
#define TERM_NONE		0
#define TERM_ACCEPT		1U
#define TERM_ADD		2U
#define TERM_CALL		3U
#define TERM_COMPUTE		4U
#define TERM_DELETE		5U
#define TERM_DISPLAY		6U
#define TERM_DIVIDE		7U
#define TERM_EVALUATE		8U
#define TERM_IF			9U
#define TERM_MULTIPLY		10U
#define TERM_PERFORM		11U
#define TERM_READ		12U
#define TERM_RECEIVE		13U
#define TERM_RETURN		14U
#define TERM_REWRITE		15U
#define TERM_SEARCH		16U
#define TERM_START		17U
#define TERM_STRING		18U
#define TERM_SUBTRACT		19U
#define TERM_UNSTRING		20U
#define TERM_WRITE		21U
#define TERM_MAX		22U

#define	TERMINATOR_WARNING(x,z)	terminator_warning (x, TERM_##z, #z)
#define	TERMINATOR_ERROR(x,z)	terminator_error (x, TERM_##z, #z)
#define	TERMINATOR_CLEAR(x,z)	terminator_clear (x, TERM_##z)

/* Defines for duplicate checks */
/* Note - We use <= 16 for common item definitons and */
/* > 16 for non-common item definitions eg. REPORT and SCREEN */
#define	SYN_CLAUSE_1		(1U << 0)
#define	SYN_CLAUSE_2		(1U << 1)
#define	SYN_CLAUSE_3		(1U << 2)
#define	SYN_CLAUSE_4		(1U << 3)
#define	SYN_CLAUSE_5		(1U << 4)
#define	SYN_CLAUSE_6		(1U << 5)
#define	SYN_CLAUSE_7		(1U << 6)
#define	SYN_CLAUSE_8		(1U << 7)
#define	SYN_CLAUSE_9		(1U << 8)
#define	SYN_CLAUSE_10		(1U << 9)
#define	SYN_CLAUSE_11		(1U << 10)
#define	SYN_CLAUSE_12		(1U << 11)
#define	SYN_CLAUSE_13		(1U << 12)
#define	SYN_CLAUSE_14		(1U << 13)
#define	SYN_CLAUSE_15		(1U << 14)
#define	SYN_CLAUSE_16		(1U << 15)
#define	SYN_CLAUSE_17		(1U << 16)
#define	SYN_CLAUSE_18		(1U << 17)
#define	SYN_CLAUSE_19		(1U << 18)
#define	SYN_CLAUSE_20		(1U << 19)
#define	SYN_CLAUSE_21		(1U << 20)
#define	SYN_CLAUSE_22		(1U << 21)
#define	SYN_CLAUSE_23		(1U << 22)
#define	SYN_CLAUSE_24		(1U << 23)
#define	SYN_CLAUSE_25		(1U << 24)
#define	SYN_CLAUSE_26		(1U << 25)
#define	SYN_CLAUSE_27		(1U << 26)
#define	SYN_CLAUSE_28		(1U << 27)
#define	SYN_CLAUSE_29		(1U << 28)
#define	SYN_CLAUSE_30		(1U << 29)
#define	SYN_CLAUSE_31		(1U << 30)
#define	SYN_CLAUSE_32		(1U << 31)

#define	EVAL_DEPTH		32
#define	PROG_DEPTH		16

/* Global variables */

struct cb_program		*current_program = NULL;
struct cb_statement		*current_statement = NULL;
struct cb_label			*current_section = NULL;
struct cb_label			*current_paragraph = NULL;
char				*cobc_glob_line = NULL;

cb_tree				cobc_printer_node = NULL;
int				functions_are_all = 0;
int				non_const_word = 0;
unsigned int			cobc_in_procedure = 0;
unsigned int			cobc_in_repository = 0;
unsigned int			cobc_force_literal = 0;
unsigned int			cobc_cs_check = 0;

/* Local variables */

static struct cb_statement	*main_statement;

static cb_tree			current_expr;
static struct cb_field		*current_field;
static struct cb_field		*control_field;
static struct cb_field		*description_field;
static struct cb_file		*current_file;
static struct cb_report		*current_report;
static struct cb_report		*report_instance;

static struct cb_file		*linage_file;
static cb_tree			next_label_list;

static char			*stack_progid[PROG_DEPTH];

static enum cb_storage		current_storage;

static cb_tree			perform_stack;
static cb_tree			qualifier;

static cb_tree			save_tree;
static cb_tree			start_tree;

static unsigned int		check_unreached;
static unsigned int		in_declaratives;
static unsigned int		in_debugging;
static unsigned int		current_linage;
static unsigned int		report_count;
static unsigned int		prog_end;
static unsigned int		use_global_ind;
static unsigned int		samearea;
static unsigned int		inspect_keyword;
static unsigned int		main_flag_set;
static int			next_label_id;
static int			eval_level;
static int			eval_inc;
static int			eval_inc2;
static int			depth;
static int			call_mode;
static int			size_mode;
static int			setattr_val_on;
static int			setattr_val_off;
static unsigned int		check_duplicate;
static unsigned int		check_pic_duplicate;
static unsigned int		check_comp_duplicate;
static unsigned int		skip_statements;
static unsigned int		start_debug;
static unsigned int		save_debug;
static unsigned int		needs_field_debug;
static unsigned int		needs_debug_item;
static unsigned int		env_div_seen;
static unsigned int		header_check;

static int			term_array[TERM_MAX];
static cb_tree			eval_check[EVAL_DEPTH][EVAL_DEPTH];

/* Defines for header presence */

#define	COBC_HD_ENVIRONMENT_DIVISION	(1U << 0)
#define	COBC_HD_CONFIGURATION_SECTION	(1U << 1)
#define	COBC_HD_SPECIAL_NAMES		(1U << 2)
#define	COBC_HD_INPUT_OUTPUT_SECTION	(1U << 3)
#define	COBC_HD_FILE_CONTROL		(1U << 4)
#define	COBC_HD_I_O_CONTROL		(1U << 5)
#define	COBC_HD_DATA_DIVISION		(1U << 6)
#define	COBC_HD_FILE_SECTION		(1U << 7)
#define	COBC_HD_WORKING_STORAGE_SECTION	(1U << 8)
#define	COBC_HD_LOCAL_STORAGE_SECTION	(1U << 9)
#define	COBC_HD_LINKAGE_SECTION		(1U << 10)
#define	COBC_HD_COMMUNICATIONS_SECTION	(1U << 11)
#define	COBC_HD_REPORT_SECTION		(1U << 12)
#define	COBC_HD_SCREEN_SECTION		(1U << 13)
#define	COBC_HD_PROCEDURE_DIVISION	(1U << 14)
#define	COBC_HD_PROGRAM_ID		(1U << 15)

/* Static functions */

static void
begin_statement (const char *name, const unsigned int term)
{
	if (cb_warn_unreachable && check_unreached) {
		cb_warning (_("Unreachable statement '%s'"), name);
	}
	current_paragraph->flag_statement = 1;
	current_statement = cb_build_statement (name);
	CB_TREE (current_statement)->source_file = cb_source_file;
	CB_TREE (current_statement)->source_line = cb_source_line;
	current_statement->statement = cobc_glob_line;
	current_statement->flag_in_debug = in_debugging;
	emit_statement (CB_TREE (current_statement));
	if (term) {
		term_array[term]++;
	}
	main_statement = current_statement;
}

static void
begin_implicit_statement (void)
{
	current_statement = cb_build_statement (NULL);
	current_statement->flag_in_debug = !!in_debugging;
	main_statement->body = cb_list_add (main_statement->body,
					    CB_TREE (current_statement));
}

static void
emit_entry (const char *name, const int encode, cb_tree using_list)
{
	cb_tree		l;
	cb_tree		label;
	cb_tree		x;
	struct cb_field	*f;
	int		parmnum;
	char		buff[COB_MINI_BUFF];

	snprintf (buff, (size_t)COB_MINI_MAX, "E$%s", name);
	label = cb_build_label (cb_build_reference (buff), NULL);
	if (encode) {
		CB_LABEL (label)->name = cb_encode_program_id (name);
		CB_LABEL (label)->orig_name = name;
	} else {
		CB_LABEL (label)->name = name;
		CB_LABEL (label)->orig_name = current_program->orig_program_id;
	}
	CB_LABEL (label)->flag_begin = 1;
	CB_LABEL (label)->flag_entry = 1;
	label->source_file = cb_source_file;
	label->source_line = cb_source_line;
	emit_statement (label);

	if (current_program->flag_debugging) {
		emit_statement (cb_build_debug (cb_debug_contents,
						"START PROGRAM", NULL));
	}

	parmnum = 1;
	for (l = using_list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (CB_VALID_TREE (x) && cb_ref (x) != cb_error_node) {
			f = CB_FIELD (cb_ref (x));
			if (f->level != 01 && f->level != 77) {
				cb_error_x (x, _("'%s' not level 01 or 77"), cb_name (x));
			}
			if (!current_program->flag_chained) {
				if (f->storage != CB_STORAGE_LINKAGE) {
					cb_error_x (x, _("'%s' is not in LINKAGE SECTION"), cb_name (x));
				}
				if (f->flag_item_based || f->flag_external) {
					cb_error_x (x, _("'%s' can not be BASED/EXTERNAL"), cb_name (x));
				}
				f->flag_is_pdiv_parm = 1;
			} else {
				if (f->storage != CB_STORAGE_WORKING) {
					cb_error_x (x, _("'%s' is not in WORKING-STORAGE SECTION"), cb_name (x));
				}
				f->flag_chained = 1;
				f->param_num = parmnum;
				parmnum++;
			}
			if (f->redefines) {
				cb_error_x (x, _("'%s' REDEFINES field not allowed here"), cb_name (x));
			}
		}
	}

	/* Check dangling LINKAGE items */
	if (cb_warn_linkage) {
		for (f = current_program->linkage_storage; f; f = f->sister) {
			if (current_program->returning) {
				if (cb_ref (current_program->returning) != cb_error_node) {
					if (f == CB_FIELD (cb_ref (current_program->returning))) {
						continue;
					}
				}
			}
			for (l = using_list; l; l = CB_CHAIN (l)) {
				x = CB_VALUE (l);
				if (CB_VALID_TREE (x) && cb_ref (x) != cb_error_node) {
					if (f == CB_FIELD (cb_ref (x))) {
						break;
					}
				}
			}
			if (!l && !f->redefines) {
				cb_warning (_("LINKAGE item '%s' is not a PROCEDURE USING parameter"), f->name);
			}
		}
	}

	/* Check returning item against using items when FUNCTION */
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		for (l = using_list; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			if (CB_VALID_TREE (x) && current_program->returning &&
			    cb_ref (x) == cb_ref (current_program->returning)) {
				cb_error_x (x, _("'%s' USING item duplicates RETURNING item"), cb_name (x));
			}
		}
	}

	for (l = current_program->entry_list; l; l = CB_CHAIN (l)) {
		if (strcmp ((const char *)name,
			    (const char *)(CB_LABEL(CB_PURPOSE(l))->name)) == 0) {
			cb_error_x (CB_TREE (current_statement),
				    _("ENTRY '%s' duplicated"), name);
		}
	}

	current_program->entry_list =
		cb_list_append (current_program->entry_list,
				CB_BUILD_PAIR (label, using_list));
}

static size_t
increment_depth (void)
{
	if (++depth >= PROG_DEPTH) {
		cb_error (_("Maximum nested program depth exceeded (%d)"),
			  PROG_DEPTH);
		return 1;
	}
	return 0;
}

static void
terminator_warning (cb_tree stmt, const unsigned int termid,
		    const char *name)
{
	check_unreached = 0;
	if (term_array[termid]) {
		term_array[termid]--;
		if (cb_warn_terminator) {
			cb_warning_x (stmt,
				_("%s statement not terminated by END-%s"),
				name, name);
		}
	}
	/* Free tree assocated with terminator */
	cobc_parse_free (stmt);
}

static void
terminator_error (cb_tree stmt, const unsigned int termid, const char *name)
{
	check_unreached = 0;
	cb_error_x (CB_TREE (current_statement),
			_("%s statement not terminated by END-%s"),
			name, name);
	if (term_array[termid]) {
		term_array[termid]--;
	}
	/* Free tree assocated with terminator */
	cobc_parse_free (stmt);
}

static void
terminator_clear (cb_tree stmt, const unsigned int termid)
{
	check_unreached = 0;
	if (term_array[termid]) {
		term_array[termid]--;
	}
	/* Free tree assocated with terminator */
	cobc_parse_free (stmt);
}

static int
literal_value (cb_tree x)
{
	if (x == cb_space) {
		return ' ';
	} else if (x == cb_zero) {
		return '0';
	} else if (x == cb_quote) {
		return cb_flag_apostrophe ? '\'' : '"';
	} else if (x == cb_null) {
		return 0;
	} else if (x == cb_low) {
		return 0;
	} else if (x == cb_high) {
		return 255;
	} else if (CB_TREE_CLASS (x) == CB_CLASS_NUMERIC) {
		return cb_get_int (x);
	} else {
		return CB_LITERAL (x)->data[0];
	}
}

static void
setup_use_file (struct cb_file *fileptr)
{
	struct cb_file	*newptr;

	if (fileptr->organization == COB_ORG_SORT) {
		cb_error (_("USE statement invalid for SORT file"));
	}
	if (fileptr->flag_global) {
		newptr = cobc_parse_malloc (sizeof(struct cb_file));
		*newptr = *fileptr;
		newptr->handler = current_section;
		newptr->handler_prog = current_program;
		if (!use_global_ind) {
			current_program->local_file_list =
				cb_list_add (current_program->local_file_list,
					     CB_TREE (newptr));
		} else {
			current_program->global_file_list =
				cb_list_add (current_program->global_file_list,
					     CB_TREE (newptr));
		}
	} else {
		fileptr->handler = current_section;
	}
}

static void
build_nested_special (const int ndepth)
{
	cb_tree		x;
	cb_tree		y;

	if (!ndepth) {
		return;
	}

	/* Inherit special name mnemonics from parent */
	for (x = current_program->mnemonic_spec_list; x; x = CB_CHAIN (x)) {
		y = cb_build_reference (cb_name(CB_PURPOSE(x)));
		if (CB_SYSTEM_NAME_P (CB_VALUE(x))) {
			cb_define (y, CB_VALUE(x));
		} else {
			cb_build_constant (y, CB_VALUE(x));
		}
	}
}

static void
clear_initial_values (void)
{
	perform_stack = NULL;
	current_statement = NULL;
	main_statement = NULL;
	qualifier = NULL;
	in_declaratives = 0;
	in_debugging = 0;
	use_global_ind = 0;
	check_duplicate = 0;
	check_pic_duplicate = 0;
	check_comp_duplicate = 0;
	skip_statements = 0;
	start_debug = 0;
	save_debug = 0;
	needs_field_debug = 0;
	needs_debug_item = 0;
	env_div_seen = 0;
	header_check = 0;
	next_label_id = 0;
	current_linage = 0;
	setattr_val_on = 0;
	setattr_val_off = 0;
	report_count = 0;
	current_storage = CB_STORAGE_WORKING;
	eval_level = 0;
	eval_inc = 0;
	eval_inc2 = 0;
	inspect_keyword = 0;
	check_unreached = 0;
	cobc_in_procedure = 0;
	cobc_in_repository = 0;
	cobc_force_literal = 0;
	non_const_word = 0;
	samearea = 1;
	memset ((void *)eval_check, 0, sizeof(eval_check));
	memset ((void *)term_array, 0, sizeof(term_array));
	linage_file = NULL;
	current_file = NULL;
	current_report = NULL;
	report_instance = NULL;
	next_label_list = NULL;
	if (cobc_glob_line) {
		free (cobc_glob_line);
		cobc_glob_line = NULL;
	}
}

static void
check_repeated (const char *clause, const unsigned int bitval)
{
	if (check_duplicate & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		check_duplicate |= bitval;
	}
}

static void
check_pic_repeated (const char *clause, const unsigned int bitval)
{
	if (check_pic_duplicate & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		check_pic_duplicate |= bitval;
	}
}

static void
check_comp_repeated (const char *clause, const unsigned int bitval)
{
	if (check_comp_duplicate & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		check_comp_duplicate |= bitval;
	}
}

static void
check_screen_attr (const char *clause, const int bitval)
{
	if (current_field->screen_flag & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		current_field->screen_flag |= bitval;
	}
}

static void
bit_set_attr (const cb_tree onoff, const int attrval)
{
	if (onoff == cb_int1) {
		setattr_val_on |= attrval;
	} else {
		setattr_val_off |= attrval;
	}
}

static void
check_attribs (cb_tree fgc, cb_tree bgc, cb_tree scroll,
	       cb_tree timeout, cb_tree prompt, int attribs)
{
	/* Attach attributes to current_statement */
	if (!current_statement->attr_ptr) {
		current_statement->attr_ptr =
			cobc_parse_malloc (sizeof(struct cb_attr_struct));
	}
	if (fgc) {
		current_statement->attr_ptr->fgc = fgc;
	}
	if (bgc) {
		current_statement->attr_ptr->bgc = bgc;
	}
	if (scroll) {
		current_statement->attr_ptr->scroll = scroll;
	}
	if (timeout) {
		current_statement->attr_ptr->timeout = timeout;
	}
	if (prompt) {
		current_statement->attr_ptr->prompt = prompt;
	}
	current_statement->attr_ptr->dispattrs |= attribs;
}

static void
check_set_usage (const enum cb_usage usage)
{
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	current_field->usage = usage;
}

static void
check_relaxed_syntax (const unsigned int lev)
{
	const char	*s;

	switch (lev) {
	case COBC_HD_ENVIRONMENT_DIVISION:
		s = "ENVIRONMENT DIVISION";
		break;
	case COBC_HD_CONFIGURATION_SECTION:
		s = "CONFIGURATION SECTION";
		break;
	case COBC_HD_SPECIAL_NAMES:
		s = "SPECIAL-NAMES";
		break;
	case COBC_HD_INPUT_OUTPUT_SECTION:
		s = "INPUT-OUTPUT SECTION";
		break;
	case COBC_HD_FILE_CONTROL:
		s = "FILE-CONTROL";
		break;
	case COBC_HD_I_O_CONTROL:
		s = "I-O-CONTROL";
		break;
	case COBC_HD_DATA_DIVISION:
		s = "DATA DIVISION";
		break;
	case COBC_HD_FILE_SECTION:
		s = "FILE SECTION";
		break;
	case COBC_HD_WORKING_STORAGE_SECTION:
		s = "WORKING-STORAGE SECTION";
		break;
	case COBC_HD_LOCAL_STORAGE_SECTION:
		s = "LOCAL-STORAGE SECTION";
		break;
	case COBC_HD_LINKAGE_SECTION:
		s = "LINKAGE SECTION";
		break;
	case COBC_HD_COMMUNICATIONS_SECTION:
		s = "COMMUNICATIONS SECTION";
		break;
	case COBC_HD_REPORT_SECTION:
		s = "REPORT SECTION";
		break;
	case COBC_HD_SCREEN_SECTION:
		s = "SCREEN SECTION";
		break;
	case COBC_HD_PROCEDURE_DIVISION:
		s = "PROCEDURE DIVISION";
		break;
	case COBC_HD_PROGRAM_ID:
		s = "PROGRAM-ID";
		break;
	default:
		s = "Unknown";
		break;
	}
	if (cb_relaxed_syntax_check) {
		cb_warning (_("%s header missing - assumed"), s);
	} else {
		cb_error (_("%s header missing"), s);
	}
}

static void
check_headers_present (const unsigned int lev1, const unsigned int lev2,
		       const unsigned int lev3, const unsigned int lev4)
{
	/* Lev1 is always present and checked */
	/* Lev2/3/4, if non-zero (forced) may be present */
	if (!(header_check & lev1)) {
		header_check |= lev1;
		check_relaxed_syntax (lev1);
	}
	if (lev2) {
		if (!(header_check & lev2)) {
			header_check |= lev2;
			check_relaxed_syntax (lev2);
		}
	}
	if (lev3) {
		if (!(header_check & lev3)) {
			header_check |= lev3;
			check_relaxed_syntax (lev3);
		}
	}
	if (lev4) {
		if (!(header_check & lev4)) {
			header_check |= lev4;
			check_relaxed_syntax (lev4);
		}
	}
}


/* Line 358 of yacc.c  */
#line 766 "parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_EOF = 0,
     ACCEPT = 258,
     ACCESS = 259,
     ADD = 260,
     ADDRESS = 261,
     ADVANCING = 262,
     AFTER = 263,
     ALL = 264,
     ALLOCATE = 265,
     ALPHABET = 266,
     ALPHABETIC = 267,
     ALPHABETIC_LOWER = 268,
     ALPHABETIC_UPPER = 269,
     ALPHANUMERIC = 270,
     ALPHANUMERIC_EDITED = 271,
     ALSO = 272,
     ALTER = 273,
     ALTERNATE = 274,
     AND = 275,
     ANY = 276,
     ARE = 277,
     AREA = 278,
     ARGUMENT_NUMBER = 279,
     ARGUMENT_VALUE = 280,
     AS = 281,
     ASCENDING = 282,
     ASCII = 283,
     ASSIGN = 284,
     AT = 285,
     ATTRIBUTE = 286,
     AUTO = 287,
     AUTOMATIC = 288,
     AWAY_FROM_ZERO = 289,
     BACKGROUND_COLOR = 290,
     BASED = 291,
     BEFORE = 292,
     BELL = 293,
     BINARY = 294,
     BINARY_C_LONG = 295,
     BINARY_CHAR = 296,
     BINARY_DOUBLE = 297,
     BINARY_LONG = 298,
     BINARY_SHORT = 299,
     BLANK = 300,
     BLINK = 301,
     BLOCK = 302,
     BOTTOM = 303,
     BY = 304,
     BYTE_LENGTH = 305,
     CALL = 306,
     CANCEL = 307,
     CF = 308,
     CH = 309,
     CHAINING = 310,
     CHARACTER = 311,
     CHARACTERS = 312,
     CLASS = 313,
     CLASSIFICATION = 314,
     CLOSE = 315,
     CODE = 316,
     CODE_SET = 317,
     COLLATING = 318,
     COL = 319,
     COLS = 320,
     COLUMN = 321,
     COLUMNS = 322,
     COMMA = 323,
     COMMAND_LINE = 324,
     COMMA_DELIM = 325,
     COMMIT = 326,
     COMMON = 327,
     COMP = 328,
     COMPUTE = 329,
     COMP_1 = 330,
     COMP_2 = 331,
     COMP_3 = 332,
     COMP_4 = 333,
     COMP_5 = 334,
     COMP_6 = 335,
     COMP_X = 336,
     CONCATENATE_FUNC = 337,
     CONDITION = 338,
     CONFIGURATION = 339,
     CONSTANT = 340,
     CONTAINS = 341,
     CONTENT = 342,
     CONTINUE = 343,
     CONTROL = 344,
     CONTROLS = 345,
     CONVERSION = 346,
     CONVERTING = 347,
     COPY = 348,
     CORRESPONDING = 349,
     COUNT = 350,
     CRT = 351,
     CRT_UNDER = 352,
     CURRENCY = 353,
     CURRENT_DATE_FUNC = 354,
     CURSOR = 355,
     CYCLE = 356,
     DATA = 357,
     DATE = 358,
     DAY = 359,
     DAY_OF_WEEK = 360,
     DE = 361,
     DEBUGGING = 362,
     DECIMAL_POINT = 363,
     DECLARATIVES = 364,
     DEFAULT = 365,
     DELETE = 366,
     DELIMITED = 367,
     DELIMITER = 368,
     DEPENDING = 369,
     DESCENDING = 370,
     DETAIL = 371,
     DISC = 372,
     DISK = 373,
     DISPLAY = 374,
     DISPLAY_OF_FUNC = 375,
     DIVIDE = 376,
     DIVISION = 377,
     DOWN = 378,
     DUPLICATES = 379,
     DYNAMIC = 380,
     EBCDIC = 381,
     EC = 382,
     ELSE = 383,
     END = 384,
     END_ACCEPT = 385,
     END_ADD = 386,
     END_CALL = 387,
     END_COMPUTE = 388,
     END_DELETE = 389,
     END_DISPLAY = 390,
     END_DIVIDE = 391,
     END_EVALUATE = 392,
     END_FUNCTION = 393,
     END_IF = 394,
     END_MULTIPLY = 395,
     END_PERFORM = 396,
     END_PROGRAM = 397,
     END_READ = 398,
     END_RETURN = 399,
     END_REWRITE = 400,
     END_SEARCH = 401,
     END_START = 402,
     END_STRING = 403,
     END_SUBTRACT = 404,
     END_UNSTRING = 405,
     END_WRITE = 406,
     ENTRY = 407,
     ENVIRONMENT = 408,
     ENVIRONMENT_NAME = 409,
     ENVIRONMENT_VALUE = 410,
     EOL = 411,
     EOP = 412,
     EOS = 413,
     EQUAL = 414,
     ERASE = 415,
     ERROR = 416,
     ESCAPE = 417,
     EVALUATE = 418,
     EVENT_STATUS = 419,
     EXCEPTION = 420,
     EXCEPTION_CONDITION = 421,
     EXCLUSIVE = 422,
     EXIT = 423,
     EXPONENTIATION = 424,
     EXTEND = 425,
     EXTERNAL = 426,
     FD = 427,
     FILE_CONTROL = 428,
     FILE_ID = 429,
     FILLER = 430,
     FINAL = 431,
     FIRST = 432,
     FLOAT_BINARY_128 = 433,
     FLOAT_BINARY_32 = 434,
     FLOAT_BINARY_64 = 435,
     FLOAT_DECIMAL_16 = 436,
     FLOAT_DECIMAL_34 = 437,
     FLOAT_DECIMAL_7 = 438,
     FLOAT_EXTENDED = 439,
     FLOAT_LONG = 440,
     FLOAT_SHORT = 441,
     FOOTING = 442,
     FOR = 443,
     FOREGROUND_COLOR = 444,
     FOREVER = 445,
     FORMATTED_CURRENT_FUNC = 446,
     FORMATTED_DATE_FUNC = 447,
     FORMATTED_DATETIME_FUNC = 448,
     FORMATTED_TIME_FUNC = 449,
     FREE = 450,
     FROM = 451,
     FROM_CRT = 452,
     FULL = 453,
     FUNCTION = 454,
     FUNCTION_ID = 455,
     FUNCTION_NAME = 456,
     GENERATE = 457,
     GIVING = 458,
     GLOBAL = 459,
     GO = 460,
     GOBACK = 461,
     GREATER = 462,
     GREATER_OR_EQUAL = 463,
     GROUP = 464,
     HEADING = 465,
     HIGHLIGHT = 466,
     HIGH_VALUE = 467,
     ID = 468,
     IDENTIFICATION = 469,
     IF = 470,
     IGNORE = 471,
     IGNORING = 472,
     IN = 473,
     INDEX = 474,
     INDEXED = 475,
     INDICATE = 476,
     INITIALIZE = 477,
     INITIALIZED = 478,
     INITIATE = 479,
     INPUT = 480,
     INPUT_OUTPUT = 481,
     INSPECT = 482,
     INTO = 483,
     INTRINSIC = 484,
     INVALID = 485,
     INVALID_KEY = 486,
     IS = 487,
     I_O = 488,
     I_O_CONTROL = 489,
     JUSTIFIED = 490,
     KEPT = 491,
     KEY = 492,
     KEYBOARD = 493,
     LABEL = 494,
     LAST = 495,
     LEADING = 496,
     LEFT = 497,
     LEFTLINE = 498,
     LENGTH = 499,
     LENGTH_OF = 500,
     LESS = 501,
     LESS_OR_EQUAL = 502,
     LIMIT = 503,
     LIMITS = 504,
     LINAGE = 505,
     LINAGE_COUNTER = 506,
     LINE = 507,
     LINE_COUNTER = 508,
     LINES = 509,
     LINKAGE = 510,
     LITERAL = 511,
     LOCALE = 512,
     LOCALE_DATE_FUNC = 513,
     LOCALE_TIME_FUNC = 514,
     LOCALE_TIME_FROM_FUNC = 515,
     LOCAL_STORAGE = 516,
     LOCK = 517,
     LOWER = 518,
     LOWER_CASE_FUNC = 519,
     LOWLIGHT = 520,
     LOW_VALUE = 521,
     MANUAL = 522,
     MEMORY = 523,
     MERGE = 524,
     MINUS = 525,
     MNEMONIC_NAME = 526,
     MODE = 527,
     MOVE = 528,
     MULTIPLE = 529,
     MULTIPLY = 530,
     NAME = 531,
     NATIONAL = 532,
     NATIONAL_EDITED = 533,
     NATIONAL_OF_FUNC = 534,
     NATIVE = 535,
     NEAREST_AWAY_FROM_ZERO = 536,
     NEAREST_EVEN = 537,
     NEAREST_TOWARD_ZERO = 538,
     NEGATIVE = 539,
     NEXT = 540,
     NEXT_PAGE = 541,
     NO = 542,
     NO_ECHO = 543,
     NORMAL = 544,
     NOT = 545,
     NOT_END = 546,
     NOT_EOP = 547,
     NOT_EQUAL = 548,
     NOT_EXCEPTION = 549,
     NOT_INVALID_KEY = 550,
     NOT_OVERFLOW = 551,
     NOT_SIZE_ERROR = 552,
     NO_ADVANCING = 553,
     NUMBER = 554,
     NUMBERS = 555,
     NUMERIC = 556,
     NUMERIC_EDITED = 557,
     NUMVALC_FUNC = 558,
     OBJECT_COMPUTER = 559,
     OCCURS = 560,
     OF = 561,
     OFF = 562,
     OMITTED = 563,
     ON = 564,
     ONLY = 565,
     OPEN = 566,
     OPTIONAL = 567,
     OR = 568,
     ORDER = 569,
     ORGANIZATION = 570,
     OTHER = 571,
     OUTPUT = 572,
     OVERLINE = 573,
     PACKED_DECIMAL = 574,
     PADDING = 575,
     PAGE = 576,
     PAGE_COUNTER = 577,
     PARAGRAPH = 578,
     PERFORM = 579,
     PH = 580,
     PF = 581,
     PICTURE = 582,
     PICTURE_SYMBOL = 583,
     PLUS = 584,
     POINTER = 585,
     POSITION = 586,
     POSITIVE = 587,
     PRESENT = 588,
     PREVIOUS = 589,
     PRINTER = 590,
     PRINTING = 591,
     PROCEDURE = 592,
     PROCEDURES = 593,
     PROCEED = 594,
     PROGRAM = 595,
     PROGRAM_ID = 596,
     PROGRAM_NAME = 597,
     PROGRAM_POINTER = 598,
     PROHIBITED = 599,
     PROMPT = 600,
     QUOTE = 601,
     RANDOM = 602,
     RD = 603,
     READ = 604,
     READY_TRACE = 605,
     RECORD = 606,
     RECORDING = 607,
     RECORDS = 608,
     RECURSIVE = 609,
     REDEFINES = 610,
     REEL = 611,
     REFERENCE = 612,
     REFERENCES = 613,
     RELATIVE = 614,
     RELEASE = 615,
     REMAINDER = 616,
     REMOVAL = 617,
     RENAMES = 618,
     REPLACE = 619,
     REPLACING = 620,
     REPORT = 621,
     REPORTING = 622,
     REPORTS = 623,
     REPOSITORY = 624,
     REPO_FUNCTION = 625,
     REQUIRED = 626,
     RESERVE = 627,
     RESET = 628,
     RESET_TRACE = 629,
     RETURN = 630,
     RETURNING = 631,
     REVERSE_FUNC = 632,
     REVERSE_VIDEO = 633,
     REVERSED = 634,
     REWIND = 635,
     REWRITE = 636,
     RF = 637,
     RH = 638,
     RIGHT = 639,
     ROLLBACK = 640,
     ROUNDED = 641,
     RUN = 642,
     SAME = 643,
     SCREEN = 644,
     SCREEN_CONTROL = 645,
     SCROLL = 646,
     SD = 647,
     SEARCH = 648,
     SECTION = 649,
     SECURE = 650,
     SEGMENT_LIMIT = 651,
     SELECT = 652,
     SEMI_COLON = 653,
     SENTENCE = 654,
     SEPARATE = 655,
     SEQUENCE = 656,
     SEQUENTIAL = 657,
     SET = 658,
     SHARING = 659,
     SIGN = 660,
     SIGNED = 661,
     SIGNED_INT = 662,
     SIGNED_LONG = 663,
     SIGNED_SHORT = 664,
     SIZE = 665,
     SIZE_ERROR = 666,
     SORT = 667,
     SORT_MERGE = 668,
     SOURCE = 669,
     SOURCE_COMPUTER = 670,
     SPACE = 671,
     SPECIAL_NAMES = 672,
     STANDARD = 673,
     STANDARD_1 = 674,
     STANDARD_2 = 675,
     START = 676,
     STATIC = 677,
     STATUS = 678,
     STDCALL = 679,
     STEP = 680,
     STOP = 681,
     STRING = 682,
     SUBSTITUTE_FUNC = 683,
     SUBSTITUTE_CASE_FUNC = 684,
     SUBTRACT = 685,
     SUM = 686,
     SUPPRESS = 687,
     SYMBOLIC = 688,
     SYNCHRONIZED = 689,
     SYSTEM_DEFAULT = 690,
     TALLYING = 691,
     TAPE = 692,
     TERMINATE = 693,
     TEST = 694,
     THAN = 695,
     THEN = 696,
     THRU = 697,
     TIME = 698,
     TIMEOUT = 699,
     TIMES = 700,
     TO = 701,
     TOK_AMPER = 702,
     TOK_CLOSE_PAREN = 703,
     TOK_COLON = 704,
     TOK_DIV = 705,
     TOK_DOT = 706,
     TOK_EQUAL = 707,
     TOK_FALSE = 708,
     TOK_FILE = 709,
     TOK_GREATER = 710,
     TOK_INITIAL = 711,
     TOK_LESS = 712,
     TOK_MINUS = 713,
     TOK_MUL = 714,
     TOK_NULL = 715,
     TOK_OVERFLOW = 716,
     TOK_OPEN_PAREN = 717,
     TOK_PLUS = 718,
     TOK_TRUE = 719,
     TOP = 720,
     TOWARD_GREATER = 721,
     TOWARD_LESSER = 722,
     TRAILING = 723,
     TRANSFORM = 724,
     TRIM_FUNC = 725,
     TRUNCATION = 726,
     TYPE = 727,
     UNDERLINE = 728,
     UNIT = 729,
     UNLOCK = 730,
     UNSIGNED = 731,
     UNSIGNED_INT = 732,
     UNSIGNED_LONG = 733,
     UNSIGNED_SHORT = 734,
     UNSTRING = 735,
     UNTIL = 736,
     UP = 737,
     UPDATE = 738,
     UPON = 739,
     UPON_ARGUMENT_NUMBER = 740,
     UPON_COMMAND_LINE = 741,
     UPON_ENVIRONMENT_NAME = 742,
     UPON_ENVIRONMENT_VALUE = 743,
     UPPER = 744,
     UPPER_CASE_FUNC = 745,
     USAGE = 746,
     USE = 747,
     USER = 748,
     USER_DEFAULT = 749,
     USER_FUNCTION_NAME = 750,
     USER_REPO_FUNCTION = 751,
     USING = 752,
     VALUE = 753,
     VARYING = 754,
     WAIT = 755,
     WHEN = 756,
     WHEN_COMPILED_FUNC = 757,
     WITH = 758,
     WORD = 759,
     WORDS = 760,
     WORKING_STORAGE = 761,
     WRITE = 762,
     YYYYDDD = 763,
     YYYYMMDD = 764,
     ZERO = 765,
     SHIFT_PREFER = 766
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 377 of yacc.c  */
#line 1344 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8011

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  813
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1890
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2694

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   766

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    16,    18,
      20,    21,    24,    29,    34,    38,    39,    41,    44,    45,
      47,    51,    52,    54,    58,    59,    60,    61,    82,    83,
      91,    97,    99,   101,   102,   105,   106,   110,   112,   115,
     117,   119,   121,   123,   124,   128,   129,   133,   134,   137,
     139,   141,   143,   145,   147,   148,   153,   154,   158,   159,
     163,   164,   169,   170,   173,   177,   180,   182,   185,   187,
     189,   191,   193,   199,   203,   207,   212,   214,   216,   218,
     220,   222,   225,   226,   231,   232,   235,   239,   241,   244,
     248,   252,   256,   258,   260,   261,   264,   266,   269,   272,
     275,   279,   281,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   304,   306,   308,   309,   313,   316,   320,
     324,   326,   327,   329,   333,   338,   339,   345,   347,   349,
     351,   353,   355,   357,   359,   362,   364,   368,   369,   374,
     376,   380,   382,   384,   386,   388,   390,   392,   395,   396,
     399,   403,   405,   408,   412,   414,   417,   419,   422,   427,
     429,   432,   434,   438,   443,   449,   450,   454,   458,   464,
     468,   473,   477,   481,   482,   486,   487,   490,   491,   494,
     495,   498,   499,   506,   510,   511,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     546,   552,   558,   564,   570,   572,   574,   576,   578,   579,
     583,   584,   586,   588,   590,   592,   593,   595,   597,   602,
     604,   606,   608,   615,   619,   624,   625,   627,   629,   630,
     636,   639,   642,   644,   645,   650,   656,   659,   663,   665,
     667,   671,   673,   676,   681,   686,   691,   693,   697,   702,
     707,   711,   713,   715,   719,   722,   725,   728,   729,   732,
     736,   738,   741,   743,   745,   751,   752,   754,   756,   758,
     759,   766,   768,   771,   774,   775,   778,   779,   783,   784,
     788,   789,   792,   795,   796,   802,   806,   808,   810,   811,
     814,   817,   820,   822,   824,   826,   828,   830,   832,   834,
     836,   838,   844,   845,   847,   849,   854,   861,   871,   872,
     876,   877,   880,   881,   884,   888,   894,   900,   902,   904,
     906,   908,   912,   918,   919,   922,   924,   926,   928,   933,
     936,   939,   944,   948,   951,   954,   957,   959,   962,   963,
     964,   970,   971,   972,   975,   978,   982,   985,   987,   988,
     993,   997,  1000,  1001,  1003,  1005,  1007,  1008,  1011,  1013,
    1016,  1019,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,
    1039,  1041,  1043,  1045,  1047,  1050,  1052,  1054,  1056,  1058,
    1060,  1062,  1064,  1066,  1068,  1074,  1077,  1080,  1081,  1084,
    1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,
    1106,  1108,  1110,  1112,  1115,  1119,  1120,  1123,  1126,  1128,
    1130,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1177,  1180,  1183,  1186,  1189,  1192,  1195,  1198,
    1201,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,
    1222,  1224,  1228,  1232,  1239,  1240,  1243,  1251,  1252,  1255,
    1256,  1260,  1262,  1263,  1269,  1271,  1273,  1274,  1278,  1280,
    1283,  1285,  1288,  1291,  1295,  1297,  1298,  1304,  1306,  1309,
    1311,  1315,  1316,  1321,  1324,  1329,  1332,  1335,  1336,  1337,
    1343,  1344,  1345,  1351,  1352,  1353,  1359,  1360,  1363,  1364,
    1371,  1372,  1375,  1378,  1381,  1385,  1387,  1389,  1392,  1395,
    1397,  1399,  1401,  1403,  1406,  1408,  1413,  1415,  1420,  1423,
    1424,  1427,  1429,  1431,  1433,  1435,  1437,  1441,  1446,  1451,
    1456,  1460,  1461,  1464,  1465,  1471,  1472,  1475,  1477,  1479,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,
    1501,  1503,  1505,  1507,  1511,  1513,  1515,  1518,  1521,  1523,
    1525,  1527,  1528,  1530,  1532,  1533,  1535,  1537,  1542,  1544,
    1547,  1550,  1552,  1557,  1558,  1562,  1564,  1566,  1570,  1577,
    1580,  1583,  1586,  1589,  1590,  1593,  1595,  1597,  1598,  1602,
    1605,  1609,  1612,  1615,  1617,  1622,  1625,  1629,  1630,  1631,
    1637,  1638,  1640,  1643,  1647,  1649,  1650,  1655,  1659,  1660,
    1663,  1666,  1669,  1671,  1673,  1676,  1679,  1681,  1683,  1685,
    1687,  1689,  1691,  1693,  1695,  1697,  1699,  1704,  1706,  1708,
    1714,  1720,  1724,  1728,  1730,  1732,  1734,  1736,  1738,  1740,
    1742,  1744,  1747,  1750,  1753,  1755,  1757,  1759,  1761,  1762,
    1764,  1766,  1767,  1769,  1771,  1775,  1778,  1779,  1780,  1781,
    1791,  1792,  1797,  1798,  1799,  1803,  1804,  1808,  1810,  1813,
    1818,  1819,  1822,  1825,  1826,  1830,  1834,  1839,  1844,  1848,
    1849,  1851,  1852,  1855,  1856,  1857,  1865,  1866,  1869,  1871,
    1873,  1876,  1878,  1880,  1881,  1888,  1889,  1892,  1895,  1897,
    1898,  1900,  1901,  1902,  1906,  1907,  1910,  1913,  1915,  1917,
    1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,  1937,
    1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,  1957,
    1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,  1975,  1977,
    1979,  1981,  1983,  1985,  1987,  1989,  1991,  1993,  1995,  1997,
    1999,  2001,  2003,  2005,  2007,  2009,  2011,  2014,  2017,  2018,
    2023,  2030,  2034,  2038,  2043,  2047,  2052,  2056,  2060,  2065,
    2070,  2074,  2079,  2083,  2088,  2094,  2098,  2103,  2107,  2111,
    2113,  2115,  2117,  2120,  2121,  2123,  2127,  2131,  2134,  2137,
    2140,  2144,  2148,  2152,  2153,  2155,  2156,  2160,  2161,  2164,
    2166,  2169,  2171,  2173,  2175,  2177,  2179,  2181,  2183,  2185,
    2187,  2189,  2191,  2196,  2198,  2200,  2202,  2204,  2206,  2208,
    2210,  2214,  2218,  2222,  2226,  2230,  2231,  2233,  2234,  2239,
    2244,  2250,  2257,  2258,  2261,  2262,  2264,  2265,  2269,  2273,
    2278,  2279,  2282,  2283,  2287,  2289,  2292,  2297,  2298,  2301,
    2302,  2307,  2314,  2315,  2317,  2319,  2321,  2322,  2323,  2327,
    2329,  2332,  2335,  2339,  2340,  2343,  2346,  2349,  2350,  2354,
    2357,  2362,  2364,  2366,  2368,  2370,  2371,  2374,  2375,  2378,
    2379,  2381,  2382,  2386,  2388,  2391,  2392,  2396,  2399,  2403,
    2404,  2406,  2410,  2414,  2417,  2418,  2423,  2428,  2429,  2431,
    2433,  2435,  2436,  2441,  2445,  2448,  2450,  2453,  2454,  2456,
    2457,  2462,  2466,  2470,  2474,  2478,  2483,  2486,  2491,  2493,
    2494,  2498,  2504,  2505,  2508,  2511,  2514,  2517,  2518,  2521,
    2523,  2525,  2526,  2529,  2530,  2532,  2534,  2537,  2539,  2542,
    2545,  2547,  2549,  2552,  2555,  2557,  2559,  2561,  2563,  2565,
    2569,  2573,  2577,  2581,  2582,  2584,  2585,  2590,  2595,  2602,
    2609,  2618,  2627,  2628,  2630,  2631,  2635,  2638,  2639,  2644,
    2647,  2649,  2653,  2655,  2657,  2659,  2662,  2664,  2666,  2669,
    2672,  2676,  2679,  2683,  2685,  2689,  2692,  2694,  2696,  2698,
    2699,  2702,  2703,  2705,  2706,  2710,  2711,  2713,  2715,  2718,
    2720,  2722,  2724,  2725,  2729,  2731,  2732,  2736,  2738,  2739,
    2743,  2747,  2748,  2752,  2754,  2755,  2762,  2766,  2769,  2771,
    2772,  2774,  2775,  2779,  2785,  2786,  2789,  2790,  2794,  2798,
    2799,  2802,  2804,  2807,  2812,  2814,  2816,  2818,  2820,  2822,
    2824,  2826,  2827,  2831,  2832,  2836,  2838,  2841,  2842,  2846,
    2849,  2851,  2853,  2855,  2858,  2860,  2862,  2864,  2865,  2869,
    2872,  2878,  2880,  2883,  2886,  2889,  2891,  2893,  2895,  2898,
    2900,  2903,  2908,  2911,  2912,  2914,  2916,  2918,  2920,  2925,
    2926,  2929,  2933,  2937,  2938,  2942,  2943,  2947,  2951,  2956,
    2957,  2962,  2967,  2974,  2975,  2977,  2978,  2982,  2987,  2993,
    2995,  2997,  2999,  3001,  3002,  3006,  3007,  3011,  3014,  3016,
    3017,  3021,  3024,  3025,  3030,  3033,  3034,  3036,  3038,  3040,
    3042,  3046,  3047,  3050,  3052,  3056,  3060,  3061,  3065,  3067,
    3069,  3071,  3075,  3083,  3084,  3089,  3097,  3098,  3101,  3102,
    3105,  3108,  3112,  3116,  3120,  3123,  3124,  3128,  3130,  3132,
    3133,  3135,  3137,  3138,  3142,  3145,  3147,  3148,  3153,  3158,
    3159,  3161,  3162,  3167,  3172,  3173,  3176,  3180,  3181,  3183,
    3185,  3186,  3191,  3196,  3203,  3204,  3207,  3208,  3211,  3213,
    3216,  3220,  3221,  3223,  3224,  3228,  3230,  3232,  3234,  3236,
    3238,  3240,  3242,  3244,  3246,  3248,  3253,  3257,  3259,  3262,
    3265,  3268,  3271,  3274,  3277,  3280,  3283,  3286,  3291,  3295,
    3300,  3302,  3305,  3309,  3311,  3314,  3318,  3322,  3323,  3327,
    3328,  3336,  3337,  3343,  3344,  3347,  3348,  3351,  3352,  3356,
    3357,  3360,  3365,  3366,  3369,  3374,  3375,  3380,  3385,  3386,
    3390,  3391,  3396,  3398,  3400,  3402,  3405,  3408,  3411,  3414,
    3416,  3418,  3421,  3423,  3424,  3426,  3427,  3432,  3435,  3436,
    3439,  3442,  3447,  3452,  3453,  3455,  3457,  3459,  3461,  3463,
    3464,  3469,  3475,  3477,  3480,  3482,  3486,  3490,  3491,  3496,
    3497,  3499,  3500,  3505,  3510,  3517,  3524,  3525,  3527,  3530,
    3531,  3533,  3534,  3538,  3540,  3543,  3544,  3548,  3554,  3555,
    3559,  3562,  3563,  3565,  3567,  3568,  3573,  3580,  3581,  3585,
    3587,  3591,  3594,  3597,  3600,  3604,  3605,  3609,  3610,  3614,
    3615,  3619,  3620,  3622,  3623,  3627,  3629,  3631,  3633,  3635,
    3643,  3644,  3646,  3648,  3650,  3652,  3654,  3656,  3661,  3663,
    3666,  3668,  3671,  3675,  3676,  3678,  3681,  3683,  3688,  3690,
    3692,  3694,  3695,  3700,  3706,  3707,  3710,  3711,  3716,  3720,
    3724,  3726,  3728,  3730,  3732,  3733,  3735,  3738,  3739,  3742,
    3743,  3746,  3749,  3750,  3753,  3754,  3757,  3760,  3761,  3764,
    3765,  3768,  3771,  3772,  3775,  3776,  3779,  3782,  3784,  3787,
    3789,  3791,  3794,  3797,  3800,  3802,  3804,  3807,  3810,  3813,
    3814,  3817,  3818,  3821,  3822,  3825,  3827,  3829,  3830,  3833,
    3835,  3838,  3841,  3843,  3845,  3847,  3849,  3851,  3853,  3855,
    3857,  3859,  3861,  3863,  3865,  3867,  3869,  3871,  3873,  3875,
    3877,  3879,  3881,  3883,  3885,  3887,  3889,  3891,  3894,  3896,
    3898,  3900,  3902,  3904,  3906,  3908,  3912,  3913,  3915,  3917,
    3921,  3925,  3927,  3931,  3935,  3937,  3941,  3943,  3946,  3949,
    3951,  3955,  3957,  3959,  3963,  3965,  3969,  3971,  3975,  3977,
    3980,  3983,  3985,  3987,  3989,  3992,  3994,  3996,  3998,  4001,
    4003,  4004,  4007,  4009,  4011,  4013,  4017,  4019,  4021,  4024,
    4026,  4028,  4030,  4033,  4035,  4037,  4039,  4041,  4043,  4045,
    4048,  4050,  4052,  4056,  4058,  4061,  4063,  4065,  4067,  4069,
    4072,  4075,  4078,  4083,  4087,  4089,  4091,  4094,  4096,  4098,
    4100,  4102,  4104,  4106,  4108,  4111,  4114,  4117,  4119,  4121,
    4123,  4125,  4127,  4129,  4131,  4133,  4135,  4137,  4139,  4141,
    4143,  4145,  4147,  4149,  4151,  4153,  4155,  4157,  4159,  4161,
    4163,  4165,  4167,  4169,  4172,  4174,  4178,  4181,  4184,  4186,
    4188,  4192,  4195,  4198,  4200,  4202,  4206,  4210,  4215,  4221,
    4223,  4225,  4227,  4229,  4231,  4233,  4235,  4237,  4239,  4241,
    4243,  4246,  4248,  4252,  4254,  4256,  4258,  4260,  4262,  4264,
    4266,  4269,  4275,  4281,  4287,  4292,  4298,  4304,  4310,  4313,
    4316,  4318,  4320,  4322,  4324,  4326,  4328,  4330,  4332,  4333,
    4338,  4344,  4345,  4349,  4352,  4354,  4358,  4362,  4364,  4368,
    4370,  4374,  4375,  4376,  4378,  4379,  4381,  4382,  4384,  4385,
    4388,  4389,  4392,  4393,  4395,  4397,  4398,  4400,  4401,  4403,
    4406,  4407,  4410,  4411,  4415,  4417,  4419,  4421,  4423,  4425,
    4427,  4429,  4431,  4432,  4435,  4437,  4439,  4441,  4443,  4445,
    4447,  4449,  4451,  4453,  4455,  4457,  4459,  4461,  4463,  4465,
    4467,  4469,  4471,  4473,  4475,  4477,  4479,  4481,  4483,  4485,
    4487,  4489,  4491,  4493,  4495,  4497,  4499,  4501,  4503,  4505,
    4507,  4509,  4511,  4513,  4515,  4517,  4519,  4521,  4523,  4525,
    4527,  4529,  4531,  4533,  4535,  4537,  4539,  4541,  4543,  4545,
    4547,  4549,  4551,  4553,  4555,  4557,  4559,  4561,  4563,  4565,
    4567,  4569,  4571,  4573,  4575,  4576,  4578,  4579,  4581,  4582,
    4584,  4585,  4587,  4588,  4590,  4591,  4593,  4594,  4596,  4597,
    4599,  4600,  4602,  4603,  4605,  4606,  4608,  4609,  4611,  4612,
    4614,  4615,  4617,  4618,  4620,  4621,  4623,  4624,  4626,  4629,
    4630,  4632,  4633,  4635,  4636,  4638,  4639,  4641,  4642,  4644,
    4646,  4647,  4649,  4650,  4652,  4654,  4655,  4657,  4659,  4660,
    4663,  4666,  4667,  4669,  4670,  4672,  4673,  4675,  4676,  4678,
    4680,  4681,  4683,  4684,  4686,  4687,  4690,  4692,  4694,  4695,
    4697,  4698,  4700,  4701,  4703,  4704,  4706,  4707,  4709,  4710,
    4712,  4713,  4715,  4716,  4718,  4719,  4721,  4724,  4725,  4727,
    4728,  4730,  4731,  4733,  4734,  4736,  4737,  4739,  4740,  4742,
    4743,  4745,  4746,  4748,  4750,  4751,  4753,  4754,  4758,  4759,
    4761,  4764,  4766,  4768,  4770,  4772,  4774,  4776,  4778,  4780,
    4782,  4784,  4786,  4788,  4790,  4792,  4794,  4796,  4798,  4800,
    4802,  4804,  4806,  4809,  4812,  4814,  4816,  4818,  4820,  4822,
    4824,  4827,  4829,  4833,  4836,  4838,  4840,  4842,  4845,  4847,
    4850,  4852,  4855,  4857,  4860,  4862,  4865,  4867,  4870,  4872,
    4875
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     513,     0,    -1,    -1,   514,   515,    -1,   518,    -1,   516,
      -1,   517,    -1,   516,   517,    -1,   520,    -1,   522,    -1,
      -1,   519,   528,    -1,   532,   528,   523,   524,    -1,   532,
     528,   523,   525,    -1,   534,   528,   526,    -1,    -1,   521,
      -1,   523,   521,    -1,    -1,   525,    -1,   142,   535,   451,
      -1,    -1,   527,    -1,   138,   535,   451,    -1,    -1,    -1,
      -1,   540,   541,   542,   603,   604,   606,   605,   638,   529,
     648,   649,   650,   530,   679,   732,   734,   736,   786,   531,
     800,    -1,    -1,   341,   451,   535,   536,   533,   537,   451,
      -1,   200,   451,   535,   536,   451,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1267,   538,  1283,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1299,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1267,  1217,  1310,    -1,  1316,
    1267,  1184,    -1,   396,  1267,  1217,    -1,  1255,    59,  1267,
     557,    -1,  1184,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1267,    96,    -1,  1217,  1267,  1188,    -1,
    1267,  1188,   574,    -1,   575,    -1,    -1,   575,    -1,  1035,
    1279,  1188,    -1,   575,  1035,  1279,  1188,    -1,    -1,    11,
    1188,   577,  1267,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1256,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1268,
     590,    -1,  1189,    -1,   589,  1189,    -1,  1218,    -1,   590,
    1218,    -1,    58,  1188,  1267,   592,    -1,   593,    -1,   592,
     593,    -1,  1220,    -1,  1220,   442,  1220,    -1,   257,  1188,
    1267,   256,    -1,    98,  1286,  1267,   256,   596,    -1,    -1,
    1299,   328,   256,    -1,   108,  1267,    68,    -1,   301,   405,
    1267,   468,   400,    -1,   100,  1267,  1183,    -1,    96,   423,
    1267,  1183,    -1,   390,  1267,  1183,    -1,   164,  1267,  1183,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1241,  1188,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1296,   614,   613,   615,    -1,    29,  1296,   614,   612,
     616,    -1,    29,  1296,   614,   119,   616,    -1,    29,  1296,
     614,   238,   616,    -1,    29,  1296,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1259,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1214,    -1,    -1,   256,    -1,  1214,    -1,     4,  1274,  1267,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1284,
    1269,  1267,   632,  1235,    -1,  1300,  1267,   504,    -1,   622,
     423,  1267,  1183,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1274,  1267,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1309,    -1,
     503,   262,   309,   274,  1309,    -1,   503,   385,    -1,   315,
    1267,   628,    -1,   628,    -1,   220,    -1,  1284,  1253,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1255,  1267,  1187,
      -1,   351,   113,  1267,   419,    -1,   351,  1269,  1267,   632,
      -1,  1183,    -1,  1183,   452,  1182,    -1,  1183,   414,  1267,
    1182,    -1,   359,  1269,  1267,  1183,    -1,   372,   635,  1250,
      -1,   287,    -1,  1217,    -1,   404,  1299,   637,    -1,     9,
    1280,    -1,   287,  1280,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1250,  1260,  1173,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1259,  1292,  1257,   645,    -1,   646,    -1,   645,   646,
      -1,  1174,   647,    -1,    -1,   331,  1217,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1174,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1267,   171,    -1,  1267,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1257,
    1217,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1257,  1217,  1256,    -1,   351,  1257,  1217,   446,  1217,  1256,
      -1,   351,  1267,   499,  1262,  1289,   661,   662,  1256,   660,
      -1,    -1,   114,  1278,  1183,    -1,    -1,  1261,  1217,    -1,
      -1,   446,  1217,    -1,   239,  1311,  1307,    -1,   498,   306,
     665,  1267,   666,    -1,   498,   306,   174,  1267,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1214,    -1,   102,  1311,
    1185,    -1,   250,  1267,  1187,  1273,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1299,   187,
    1252,  1187,    -1,   465,  1187,    -1,    48,  1187,    -1,   352,
    1274,  1267,   504,    -1,    62,  1267,   504,    -1,   677,   678,
      -1,   366,  1267,    -1,   368,  1249,    -1,  1188,    -1,   678,
    1188,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1233,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1267,   204,
      -1,  1221,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1277,   691,    -1,  1211,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1251,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1211,    -1,  1267,   171,   702,    -1,    -1,
      26,   256,    -1,  1267,   204,    -1,   327,    -1,   706,    -1,
     491,  1267,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1287,    -1,    41,   476,    -1,
      44,  1287,    -1,    44,   476,    -1,    43,  1287,    -1,    43,
     476,    -1,    42,  1287,    -1,    42,   476,    -1,    40,  1287,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1288,   241,  1245,    -1,  1288,   468,
    1245,    -1,   305,  1217,   713,  1294,   714,   711,    -1,    -1,
     425,  1217,    -1,   305,  1217,   713,  1294,   714,   715,   718,
      -1,    -1,   446,  1217,    -1,    -1,   114,  1278,  1183,    -1,
     716,    -1,    -1,   716,   717,  1269,  1267,  1182,    -1,    27,
      -1,   115,    -1,    -1,   220,  1254,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1285,    -1,   434,  1270,
      -1,    45,  1297,   510,    -1,    36,    -1,    -1,   498,  1268,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1221,
      -1,  1221,   442,  1221,    -1,    -1,  1298,   453,  1267,  1221,
      -1,   363,  1214,    -1,   363,  1214,   442,  1214,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1175,   740,   741,   451,   757,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1267,   204,
      -1,    61,  1267,  1201,    -1,   743,    -1,   748,    -1,  1324,
     744,    -1,   745,   746,    -1,   745,    -1,   746,    -1,   176,
      -1,   747,    -1,   746,   747,    -1,  1210,    -1,   321,  1272,
     749,   750,    -1,  1219,    -1,  1219,  1308,  1219,  1302,    -1,
    1219,  1308,    -1,    -1,   750,   751,    -1,   752,    -1,   753,
      -1,   754,    -1,   755,    -1,   756,    -1,   210,  1267,  1219,
      -1,   177,  1317,  1267,  1219,    -1,   240,  1318,  1267,  1219,
      -1,   240,  1317,  1267,  1219,    -1,   187,  1267,  1219,    -1,
      -1,   757,   758,    -1,    -1,   686,   687,   759,   760,   451,
      -1,    -1,   760,   761,    -1,   762,    -1,   766,    -1,   774,
      -1,   704,    -1,   785,    -1,   709,    -1,   721,    -1,   780,
      -1,   723,    -1,   783,    -1,   769,    -1,   725,    -1,   772,
      -1,   784,    -1,   710,    -1,   773,    -1,   472,  1267,   763,
      -1,  1322,    -1,  1320,    -1,  1318,   764,    -1,  1319,   765,
      -1,  1317,    -1,  1321,    -1,  1323,    -1,    -1,  1210,    -1,
     176,    -1,    -1,  1210,    -1,   176,    -1,   285,   209,  1267,
     767,    -1,  1217,    -1,   329,  1217,    -1,   768,  1281,    -1,
     285,    -1,   431,  1277,  1194,   770,    -1,    -1,   373,  1278,
     771,    -1,  1210,    -1,   176,    -1,   333,   501,  1150,    -1,
     499,  1210,   196,  1196,    49,  1196,    -1,   775,   776,    -1,
     252,   777,    -1,   778,   779,    -1,   329,   778,    -1,    -1,
     299,   232,    -1,   299,    -1,  1219,    -1,    -1,   309,   285,
     321,    -1,   781,   782,    -1,  1301,  1276,  1268,    -1,  1302,
    1249,    -1,   329,  1217,    -1,  1219,    -1,   414,  1267,  1196,
    1242,    -1,   209,  1264,    -1,   491,  1267,   119,    -1,    -1,
      -1,   389,   394,   451,   787,   788,    -1,    -1,   789,    -1,
     790,   451,    -1,   789,   790,   451,    -1,   696,    -1,    -1,
     686,   687,   791,   792,    -1,   686,     1,   451,    -1,    -1,
     792,   793,    -1,    45,   252,    -1,    45,   389,    -1,    38,
      -1,    46,    -1,   160,   156,    -1,   160,   158,    -1,   211,
      -1,   265,    -1,   378,    -1,   473,    -1,   318,    -1,   243,
      -1,    32,    -1,   395,    -1,   371,    -1,   198,    -1,   345,
      56,  1267,  1201,    -1,   345,    -1,   456,    -1,   252,  1275,
    1267,   796,  1203,    -1,  1301,  1275,  1267,   797,  1203,    -1,
     189,  1267,  1203,    -1,    35,  1267,  1203,    -1,   705,    -1,
     723,    -1,   799,    -1,   721,    -1,   709,    -1,   725,    -1,
     704,    -1,   798,    -1,   497,  1210,    -1,   196,  1202,    -1,
     446,  1210,    -1,   329,    -1,   463,    -1,   270,    -1,   458,
      -1,    -1,   794,    -1,   795,    -1,    -1,   794,    -1,   795,
      -1,   305,  1217,  1294,    -1,  1267,   204,    -1,    -1,    -1,
      -1,   337,   122,   804,   812,   451,   801,   813,   802,   815,
      -1,    -1,   803,   826,   451,   815,    -1,    -1,    -1,   497,
     805,   807,    -1,    -1,    55,   806,   807,    -1,   808,    -1,
     807,   808,    -1,   809,   810,   811,   504,    -1,    -1,  1254,
     357,    -1,  1254,   498,    -1,    -1,   410,  1267,    32,    -1,
     410,  1267,   110,    -1,   476,   410,  1267,    32,    -1,   476,
     410,  1267,  1217,    -1,   410,  1267,  1217,    -1,    -1,   312,
      -1,    -1,   376,   504,    -1,    -1,    -1,   109,   451,   814,
     815,   129,   109,   451,    -1,    -1,   815,   816,    -1,   817,
      -1,   820,    -1,   826,   451,    -1,   821,    -1,   451,    -1,
      -1,   504,   394,   822,   451,   818,   819,    -1,    -1,  1106,
     451,    -1,   504,   451,    -1,   504,    -1,    -1,  1217,    -1,
      -1,    -1,   824,   825,   826,    -1,    -1,   827,   828,    -1,
     826,   828,    -1,   829,    -1,   844,    -1,   849,    -1,   853,
      -1,   858,    -1,   873,    -1,   876,    -1,   884,    -1,   880,
      -1,   885,    -1,   886,    -1,   891,    -1,   905,    -1,   909,
      -1,   912,    -1,   926,    -1,   929,    -1,   932,    -1,   935,
      -1,   939,    -1,   940,    -1,   944,    -1,   954,    -1,   957,
      -1,   974,    -1,   976,    -1,   979,    -1,   983,    -1,   989,
      -1,  1001,    -1,  1009,    -1,  1010,    -1,  1013,    -1,  1014,
      -1,  1018,    -1,  1023,    -1,  1024,    -1,  1032,    -1,  1047,
      -1,  1057,    -1,  1066,    -1,  1071,    -1,  1078,    -1,  1082,
      -1,  1084,    -1,  1087,    -1,  1090,    -1,  1094,    -1,  1119,
      -1,   285,   399,    -1,     1,  1246,    -1,    -1,     3,   830,
     831,   843,    -1,   832,   834,   838,   839,   840,  1127,    -1,
    1210,   196,   833,    -1,  1210,   196,  1302,    -1,  1210,   196,
     103,   509,    -1,  1210,   196,   103,    -1,  1210,   196,   104,
     508,    -1,  1210,   196,   104,    -1,  1210,   196,   105,    -1,
    1210,   196,   162,   237,    -1,  1210,   196,   165,   423,    -1,
    1210,   196,   443,    -1,  1210,   196,   493,   276,    -1,  1210,
     196,    69,    -1,  1210,   196,   155,  1127,    -1,  1210,   196,
     153,  1199,  1127,    -1,  1210,   196,    24,    -1,  1210,   196,
      25,  1127,    -1,  1210,   196,  1177,    -1,  1210,   196,   504,
      -1,  1210,    -1,   308,    -1,   254,    -1,   252,   299,    -1,
      -1,   835,    -1,  1252,   836,   837,    -1,  1252,   837,   836,
      -1,  1252,   836,    -1,  1252,   837,    -1,    30,  1199,    -1,
     252,  1275,  1203,    -1,  1301,  1275,  1203,    -1,   331,  1275,
    1203,    -1,    -1,   197,    -1,    -1,   272,  1267,    47,    -1,
      -1,   503,   841,    -1,   842,    -1,   841,   842,    -1,    32,
      -1,    38,    -1,    46,    -1,    91,    -1,   198,    -1,   211,
      -1,   243,    -1,   263,    -1,   265,    -1,   288,    -1,   318,
      -1,   345,    56,  1267,  1201,    -1,   345,    -1,   371,    -1,
     378,    -1,   395,    -1,   473,    -1,   483,    -1,   489,    -1,
     189,  1267,  1203,    -1,    35,  1267,  1203,    -1,   391,   482,
    1149,    -1,   391,   123,  1149,    -1,   444,  1248,  1204,    -1,
      -1,   130,    -1,    -1,     5,   845,   846,   848,    -1,  1192,
     446,  1169,  1133,    -1,  1192,   847,   203,  1169,  1133,    -1,
      94,  1210,   446,  1210,  1242,  1133,    -1,    -1,   446,  1193,
      -1,    -1,   131,    -1,    -1,    10,   850,   851,    -1,  1210,
    1236,   852,    -1,  1163,    57,  1237,   852,    -1,    -1,   376,
    1191,    -1,    -1,    18,   854,   855,    -1,   856,    -1,   855,
     856,    -1,  1179,   446,   857,  1179,    -1,    -1,   339,   446,
      -1,    -1,    51,   859,   860,   872,    -1,   861,  1202,   862,
     867,   870,   871,    -1,    -1,   422,    -1,   424,    -1,   271,
      -1,    -1,    -1,   497,   863,   864,    -1,   865,    -1,   864,
     865,    -1,   866,   308,    -1,   866,   810,  1193,    -1,    -1,
    1254,   357,    -1,  1254,    87,    -1,  1254,   498,    -1,    -1,
     868,  1266,  1210,    -1,   868,   869,    -1,   868,     6,  1277,
    1210,    -1,   376,    -1,   203,    -1,   460,    -1,   308,    -1,
      -1,  1305,   823,    -1,    -1,   294,   823,    -1,    -1,   132,
      -1,    -1,    52,   874,   875,    -1,  1201,    -1,   875,  1201,
      -1,    -1,    60,   877,   878,    -1,  1174,   879,    -1,   878,
    1174,   879,    -1,    -1,  1312,    -1,  1312,  1260,   362,    -1,
    1299,   287,   380,    -1,  1299,   262,    -1,    -1,    74,   881,
     882,   883,    -1,  1169,  1303,  1163,  1133,    -1,    -1,   133,
      -1,    71,    -1,    88,    -1,    -1,   111,   887,   888,   890,
      -1,  1174,  1284,  1146,    -1,   454,   889,    -1,  1174,    -1,
     889,  1174,    -1,    -1,   134,    -1,    -1,   119,   892,   893,
     904,    -1,  1201,   487,  1130,    -1,  1201,   488,  1130,    -1,
    1201,   485,  1130,    -1,  1201,   486,  1130,    -1,  1192,   897,
     901,  1130,    -1,   894,  1130,    -1,  1193,   503,   902,  1130,
      -1,   896,    -1,    -1,   894,   895,   896,    -1,  1193,   835,
     898,   839,   900,    -1,    -1,   484,  1177,    -1,   484,   504,
      -1,   484,   335,    -1,   484,    96,    -1,    -1,   484,   899,
      -1,    96,    -1,    97,    -1,    -1,   503,   902,    -1,    -1,
     298,    -1,   903,    -1,   902,   903,    -1,    38,    -1,    45,
     252,    -1,    45,   389,    -1,    46,    -1,    91,    -1,   160,
     156,    -1,   160,   158,    -1,   211,    -1,   265,    -1,   318,
      -1,   378,    -1,   473,    -1,   189,  1267,  1203,    -1,    35,
    1267,  1203,    -1,   391,   482,  1149,    -1,   391,   123,  1149,
      -1,    -1,   135,    -1,    -1,   121,   906,   907,   908,    -1,
    1193,   228,  1169,  1133,    -1,  1193,   228,  1193,   203,  1169,
    1133,    -1,  1193,    49,  1193,   203,  1169,  1133,    -1,  1193,
     228,  1193,   203,  1170,   361,  1170,  1133,    -1,  1193,    49,
    1193,   203,  1170,   361,  1170,  1133,    -1,    -1,   136,    -1,
      -1,   152,   910,   911,    -1,   256,   862,    -1,    -1,   163,
     913,   914,   925,    -1,   915,   917,    -1,   916,    -1,   915,
      17,   916,    -1,  1151,    -1,   464,    -1,   453,    -1,   918,
     920,    -1,   918,    -1,   919,    -1,   918,   919,    -1,   921,
     823,    -1,   501,   316,   823,    -1,   501,   922,    -1,   921,
     501,   922,    -1,   923,    -1,   922,    17,   923,    -1,  1152,
     924,    -1,    21,    -1,   464,    -1,   453,    -1,    -1,   442,
    1151,    -1,    -1,   137,    -1,    -1,   168,   927,   928,    -1,
      -1,   340,    -1,   199,    -1,   324,   101,    -1,   324,    -1,
     394,    -1,   323,    -1,    -1,   195,   930,   931,    -1,  1190,
      -1,    -1,   202,   933,   934,    -1,  1214,    -1,    -1,   205,
     936,   937,    -1,  1295,  1178,   938,    -1,    -1,   114,  1278,
    1210,    -1,   206,    -1,    -1,   215,   941,  1150,  1293,   942,
     943,    -1,   823,   128,   823,    -1,   128,   823,    -1,   823,
      -1,    -1,   139,    -1,    -1,   222,   945,   946,    -1,  1190,
     947,   948,   949,   953,    -1,    -1,  1299,   175,    -1,    -1,
       9,  1295,   498,    -1,   952,  1295,   498,    -1,    -1,   365,
     950,    -1,   951,    -1,   950,   951,    -1,   952,  1258,    49,
    1193,    -1,    12,    -1,    15,    -1,   301,    -1,    16,    -1,
     302,    -1,   277,    -1,   278,    -1,    -1,  1293,  1295,   110,
      -1,    -1,   224,   955,   956,    -1,  1175,    -1,   956,  1175,
      -1,    -1,   227,   958,   959,    -1,   960,   961,    -1,  1210,
      -1,  1221,    -1,  1224,    -1,   962,   964,    -1,   962,    -1,
     964,    -1,   965,    -1,    -1,   436,   963,   966,    -1,   365,
     968,    -1,    92,  1199,   446,  1200,   972,    -1,   967,    -1,
     966,   967,    -1,  1199,   188,    -1,    57,   972,    -1,     9,
      -1,   241,    -1,   468,    -1,  1199,   972,    -1,   969,    -1,
     968,   969,    -1,    57,    49,  1199,   972,    -1,   970,   971,
      -1,    -1,     9,    -1,   241,    -1,   177,    -1,   468,    -1,
    1199,    49,  1200,   972,    -1,    -1,   972,   973,    -1,    37,
    1265,  1193,    -1,     8,  1265,  1193,    -1,    -1,   269,   975,
    1049,    -1,    -1,   273,   977,   978,    -1,  1193,   446,  1190,
      -1,    94,  1193,   446,  1190,    -1,    -1,   275,   980,   981,
     982,    -1,  1193,    49,  1169,  1133,    -1,  1193,    49,  1193,
     203,  1169,  1133,    -1,    -1,   140,    -1,    -1,   311,   984,
     985,    -1,   986,   987,  1173,   988,    -1,   985,   986,   987,
    1173,   988,    -1,   225,    -1,   317,    -1,   233,    -1,   170,
      -1,    -1,   404,  1299,   637,    -1,    -1,  1299,   287,   380,
      -1,  1299,   262,    -1,   379,    -1,    -1,   324,   990,   991,
      -1,   995,   996,    -1,    -1,   996,   992,   823,   993,    -1,
     996,   994,    -1,    -1,   141,    -1,   141,    -1,   451,    -1,
    1179,    -1,  1179,   442,  1179,    -1,    -1,  1202,   445,    -1,
     190,    -1,   997,   481,   998,    -1,   997,   499,   999,    -1,
      -1,  1299,   439,  1124,    -1,   168,    -1,  1150,    -1,  1000,
      -1,   999,     8,  1000,    -1,  1210,   196,  1193,    49,  1193,
     481,  1150,    -1,    -1,   349,  1002,  1003,  1008,    -1,  1174,
    1239,  1284,  1004,  1005,  1006,  1007,    -1,    -1,   228,  1210,
      -1,    -1,   217,   262,    -1,  1299,   262,    -1,  1299,   236,
     262,    -1,  1299,   287,   262,    -1,  1299,   216,   262,    -1,
    1299,   500,    -1,    -1,   237,  1267,  1210,    -1,  1146,    -1,
    1140,    -1,    -1,   143,    -1,   350,    -1,    -1,   360,  1011,
    1012,    -1,  1171,  1122,    -1,   374,    -1,    -1,   375,  1015,
    1016,  1017,    -1,  1174,  1284,  1004,  1139,    -1,    -1,   144,
      -1,    -1,   381,  1019,  1020,  1022,    -1,  1171,  1122,  1021,
    1146,    -1,    -1,  1299,   262,    -1,  1299,   287,   262,    -1,
      -1,   145,    -1,   385,    -1,    -1,   393,  1025,  1026,  1031,
      -1,  1172,  1027,  1028,  1029,    -1,     9,  1172,  1028,   501,
    1151,   823,    -1,    -1,   499,  1210,    -1,    -1,   129,   823,
      -1,  1030,    -1,  1030,  1029,    -1,   501,  1150,   823,    -1,
      -1,   146,    -1,    -1,   403,  1033,  1034,    -1,  1037,    -1,
    1038,    -1,  1041,    -1,  1042,    -1,  1043,    -1,  1045,    -1,
     309,    -1,   307,    -1,   482,    -1,   123,    -1,   153,  1199,
     446,  1199,    -1,  1207,    31,  1039,    -1,  1040,    -1,  1039,
    1040,    -1,    38,  1035,    -1,    46,  1035,    -1,   211,  1035,
      -1,   265,  1035,    -1,   378,  1035,    -1,   473,  1035,    -1,
     243,  1035,    -1,   318,  1035,    -1,  1190,   446,   152,  1198,
      -1,  1190,   446,  1193,    -1,  1190,  1036,    49,  1193,    -1,
    1044,    -1,  1043,  1044,    -1,  1176,   446,  1035,    -1,  1046,
      -1,  1045,  1046,    -1,  1190,   446,   464,    -1,  1190,   446,
     453,    -1,    -1,   412,  1048,  1049,    -1,    -1,  1208,  1051,
    1053,  1054,  1050,  1055,  1056,    -1,    -1,  1051,  1278,   717,
    1269,  1052,    -1,    -1,  1052,  1214,    -1,    -1,  1315,  1263,
      -1,    -1,  1300,  1267,  1183,    -1,    -1,   497,  1173,    -1,
     225,   337,  1267,   995,    -1,    -1,   203,  1173,    -1,   317,
     337,  1267,   995,    -1,    -1,   421,  1058,  1059,  1065,    -1,
    1174,  1061,  1060,  1146,    -1,    -1,  1299,  1314,  1163,    -1,
      -1,   237,  1267,  1062,  1210,    -1,   177,    -1,   240,    -1,
    1156,    -1,  1240,  1157,    -1,  1240,  1158,    -1,  1240,  1159,
      -1,  1240,  1160,    -1,  1063,    -1,  1064,    -1,   290,  1156,
      -1,   293,    -1,    -1,   147,    -1,    -1,   426,   387,  1067,
    1068,    -1,   426,  1070,    -1,    -1,   376,  1193,    -1,   203,
    1193,    -1,  1299,   161,  1291,  1069,    -1,  1299,   289,  1291,
    1069,    -1,    -1,  1193,    -1,   256,    -1,   416,    -1,   510,
      -1,   346,    -1,    -1,   427,  1072,  1073,  1077,    -1,  1074,
     228,  1210,  1076,  1136,    -1,  1075,    -1,  1074,  1075,    -1,
    1193,    -1,   112,  1254,   410,    -1,   112,  1254,  1193,    -1,
      -1,  1299,   330,  1267,  1210,    -1,    -1,   148,    -1,    -1,
     430,  1079,  1080,  1081,    -1,  1192,   196,  1169,  1133,    -1,
    1192,   196,  1193,   203,  1169,  1133,    -1,    94,  1210,   196,
    1210,  1242,  1133,    -1,    -1,   149,    -1,   432,  1083,    -1,
      -1,   336,    -1,    -1,   438,  1085,  1086,    -1,  1175,    -1,
    1086,  1175,    -1,    -1,   469,  1088,  1089,    -1,  1210,   196,
    1199,   446,  1200,    -1,    -1,   475,  1091,  1092,    -1,  1174,
    1093,    -1,    -1,   351,    -1,   353,    -1,    -1,   480,  1095,
    1096,  1105,    -1,  1210,  1097,  1100,  1076,  1104,  1136,    -1,
      -1,   112,  1254,  1098,    -1,  1099,    -1,  1098,   313,  1099,
      -1,  1234,  1199,    -1,   228,  1101,    -1,  1100,  1101,    -1,
    1210,  1102,  1103,    -1,    -1,   113,  1262,  1210,    -1,    -1,
      95,  1262,  1210,    -1,    -1,   436,  1262,  1210,    -1,    -1,
     150,    -1,    -1,   492,  1107,  1108,    -1,  1109,    -1,  1112,
      -1,  1116,    -1,  1117,    -1,  1110,  1248,  1290,  1304,  1282,
    1278,  1111,    -1,    -1,   204,    -1,  1173,    -1,   225,    -1,
     317,    -1,   233,    -1,   170,    -1,  1260,   107,  1278,  1113,
      -1,  1114,    -1,  1113,  1114,    -1,  1180,    -1,     9,   338,
      -1,     9,  1115,  1214,    -1,    -1,   358,    -1,   358,   306,
      -1,   306,    -1,  1110,    37,   367,  1210,    -1,  1118,    -1,
     166,    -1,   127,    -1,    -1,   507,  1120,  1121,  1126,    -1,
    1171,  1122,  1123,  1021,  1125,    -1,    -1,   196,  1206,    -1,
      -1,  1124,  1247,  1203,  1271,    -1,  1124,  1247,  1177,    -1,
    1124,  1247,   321,    -1,    37,    -1,     8,    -1,  1146,    -1,
    1143,    -1,    -1,   151,    -1,  1128,  1129,    -1,    -1,   165,
     823,    -1,    -1,   294,   823,    -1,  1131,  1132,    -1,    -1,
     165,   823,    -1,    -1,   294,   823,    -1,  1134,  1135,    -1,
      -1,   411,   823,    -1,    -1,   297,   823,    -1,  1137,  1138,
      -1,    -1,   461,   823,    -1,    -1,   296,   823,    -1,  1141,
    1142,    -1,  1141,    -1,  1141,  1142,    -1,  1141,    -1,  1142,
      -1,   129,   823,    -1,   291,   823,    -1,  1144,  1145,    -1,
    1144,    -1,  1145,    -1,   157,   823,    -1,   292,   823,    -1,
    1147,  1148,    -1,    -1,   231,   823,    -1,    -1,   295,   823,
      -1,    -1,  1205,  1313,    -1,  1151,    -1,  1152,    -1,    -1,
    1153,  1154,    -1,  1155,    -1,  1154,   232,    -1,  1154,  1155,
      -1,  1193,    -1,   462,    -1,   448,    -1,   463,    -1,   458,
      -1,   459,    -1,   450,    -1,   169,    -1,  1156,    -1,  1157,
      -1,  1158,    -1,  1159,    -1,  1160,    -1,   293,    -1,   290,
      -1,    20,    -1,   313,    -1,   308,    -1,   301,    -1,    12,
      -1,    13,    -1,    14,    -1,   332,    -1,   284,    -1,   452,
      -1,   159,  1295,    -1,   455,    -1,   207,    -1,   457,    -1,
     246,    -1,   208,    -1,   247,    -1,  1163,    -1,  1161,  1162,
    1163,    -1,    -1,    70,    -1,   398,    -1,  1163,   463,  1164,
      -1,  1163,   458,  1164,    -1,  1164,    -1,  1164,   459,  1165,
      -1,  1164,   450,  1165,    -1,  1165,    -1,  1166,   169,  1165,
      -1,  1166,    -1,   463,  1167,    -1,   458,  1167,    -1,  1167,
      -1,   462,  1163,   448,    -1,  1196,    -1,   251,    -1,   251,
    1306,   504,    -1,   253,    -1,   253,  1306,   504,    -1,   322,
      -1,   322,  1306,   504,    -1,  1170,    -1,  1169,  1170,    -1,
    1191,  1242,    -1,  1214,    -1,  1214,    -1,  1174,    -1,  1173,
    1174,    -1,   504,    -1,   504,    -1,  1177,    -1,  1176,  1177,
      -1,   271,    -1,    -1,  1178,  1179,    -1,  1180,    -1,  1214,
      -1,  1181,    -1,  1181,  1306,  1181,    -1,   256,    -1,  1183,
      -1,  1182,  1183,    -1,  1214,    -1,   504,    -1,  1186,    -1,
    1185,  1186,    -1,   504,    -1,  1183,    -1,   256,    -1,   504,
      -1,   504,    -1,  1191,    -1,  1190,  1191,    -1,  1212,    -1,
    1222,    -1,     6,  1277,  1211,    -1,  1193,    -1,  1192,  1193,
      -1,  1210,    -1,  1221,    -1,  1224,    -1,  1168,    -1,   245,
    1211,    -1,   245,  1222,    -1,   245,  1224,    -1,     6,  1277,
    1197,  1198,    -1,     6,  1277,  1211,    -1,   271,    -1,  1196,
      -1,  1194,  1196,    -1,  1210,    -1,  1222,    -1,  1224,    -1,
    1210,    -1,  1222,    -1,  1224,    -1,  1168,    -1,   245,  1211,
      -1,   245,  1222,    -1,   245,  1224,    -1,   340,    -1,   152,
      -1,  1211,    -1,   256,    -1,  1210,    -1,  1222,    -1,  1210,
      -1,  1221,    -1,  1210,    -1,   256,    -1,  1210,    -1,   256,
      -1,  1224,    -1,  1207,    -1,  1217,    -1,   510,    -1,  1207,
      -1,  1219,    -1,  1207,    -1,  1217,    -1,  1210,    -1,  1221,
      -1,  1224,    -1,  1209,    -1,  1209,    -1,  1214,    -1,  1214,
    1215,    -1,  1211,    -1,  1214,  1215,  1216,    -1,  1214,  1215,
      -1,  1214,  1216,    -1,  1214,    -1,  1213,    -1,  1214,  1215,
    1216,    -1,  1214,  1215,    -1,  1214,  1216,    -1,  1214,    -1,
     504,    -1,   504,  1306,  1214,    -1,   462,  1161,   448,    -1,
     462,  1163,   449,   448,    -1,   462,  1163,   449,  1163,   448,
      -1,   256,    -1,   256,    -1,   256,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,
      -1,  1222,    -1,     9,  1223,    -1,  1223,    -1,  1222,   447,
    1223,    -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,
     212,    -1,   266,    -1,   460,    -1,  1225,  1228,    -1,  1226,
     462,  1195,   448,  1228,    -1,  1227,   462,  1161,   448,  1228,
      -1,   470,   462,  1230,   448,  1228,    -1,   303,   462,  1231,
     448,    -1,   258,   462,  1232,   448,  1228,    -1,   259,   462,
    1232,   448,  1228,    -1,   260,   462,  1232,   448,  1228,    -1,
     201,  1229,    -1,   495,  1229,    -1,    99,    -1,   502,    -1,
     490,    -1,   264,    -1,   377,    -1,    82,    -1,   428,    -1,
     429,    -1,    -1,   462,  1163,   449,   448,    -1,   462,  1163,
     449,  1163,   448,    -1,    -1,   462,  1161,   448,    -1,   462,
     448,    -1,  1195,    -1,  1195,  1162,   241,    -1,  1195,  1162,
     468,    -1,  1195,    -1,  1195,  1162,  1195,    -1,  1163,    -1,
    1163,  1162,  1183,    -1,    -1,    -1,     9,    -1,    -1,  1315,
      -1,    -1,   223,    -1,    -1,   223,  1238,    -1,    -1,   446,
    1200,    -1,    -1,   285,    -1,   334,    -1,    -1,   290,    -1,
      -1,   312,    -1,   290,   312,    -1,    -1,   386,  1243,    -1,
      -1,   272,  1267,  1244,    -1,    34,    -1,   281,    -1,   282,
      -1,   283,    -1,   344,    -1,   466,    -1,   467,    -1,   471,
      -1,    -1,   400,  1255,    -1,   451,    -1,     3,    -1,     5,
      -1,    10,    -1,    18,    -1,    51,    -1,    52,    -1,    60,
      -1,    71,    -1,    74,    -1,    88,    -1,   111,    -1,   119,
      -1,   121,    -1,   128,    -1,   152,    -1,   163,    -1,   168,
      -1,   195,    -1,   202,    -1,   205,    -1,   206,    -1,   215,
      -1,   222,    -1,   224,    -1,   227,    -1,   269,    -1,   273,
      -1,   275,    -1,   285,    -1,   311,    -1,   324,    -1,   349,
      -1,   360,    -1,   375,    -1,   381,    -1,   385,    -1,   393,
      -1,   403,    -1,   412,    -1,   421,    -1,   426,    -1,   427,
      -1,   430,    -1,   432,    -1,   438,    -1,   469,    -1,   475,
      -1,   480,    -1,   507,    -1,   130,    -1,   131,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   139,    -1,   140,    -1,   141,    -1,   143,    -1,   144,
      -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,    -1,     7,    -1,    -1,     8,
      -1,    -1,    22,    -1,    -1,    23,    -1,    -1,    26,    -1,
      -1,    30,    -1,    -1,    39,    -1,    -1,    49,    -1,    -1,
      56,    -1,    -1,    57,    -1,    -1,    86,    -1,    -1,   102,
      -1,    -1,   454,    -1,    -1,   188,    -1,    -1,   196,    -1,
      -1,   218,    -1,    -1,   314,    -1,   218,   314,    -1,    -1,
     221,    -1,    -1,   456,    -1,    -1,   228,    -1,    -1,   232,
      -1,    -1,   232,    -1,    22,    -1,    -1,   237,    -1,    -1,
     242,    -1,   384,    -1,    -1,   252,    -1,   254,    -1,    -1,
     248,  1267,    -1,   249,  1249,    -1,    -1,   254,    -1,    -1,
     272,    -1,    -1,   299,    -1,    -1,   299,    -1,   300,    -1,
      -1,   306,    -1,    -1,   309,    -1,    -1,   423,   232,    -1,
     423,    -1,   232,    -1,    -1,   316,    -1,    -1,   321,    -1,
      -1,   337,    -1,    -1,   340,    -1,    -1,   351,    -1,    -1,
     384,    -1,    -1,   405,    -1,    -1,   406,    -1,    -1,   405,
      -1,   405,   232,    -1,    -1,   410,    -1,    -1,   418,    -1,
      -1,   423,    -1,    -1,   437,    -1,    -1,   441,    -1,    -1,
     445,    -1,    -1,   446,    -1,    -1,   446,    -1,   497,    -1,
      -1,   501,    -1,    -1,   501,   403,   446,    -1,    -1,   503,
      -1,    63,   401,    -1,   401,    -1,    66,    -1,    64,    -1,
      67,    -1,    65,    -1,   452,    -1,   159,    -1,   165,    -1,
     161,    -1,   165,    -1,   461,    -1,   218,    -1,   306,    -1,
     418,    -1,   308,    -1,   252,    -1,   254,    -1,   351,    -1,
     353,    -1,    57,    -1,   505,    -1,   351,  1267,    -1,   353,
    1249,    -1,   356,    -1,   474,    -1,   252,    -1,   254,    -1,
     410,    -1,   244,    -1,   503,   124,    -1,   124,    -1,   340,
      63,   401,    -1,    63,   401,    -1,   401,    -1,   116,    -1,
     106,    -1,    89,   210,    -1,    54,    -1,    89,   187,    -1,
      53,    -1,   321,   210,    -1,   325,    -1,   321,   187,    -1,
     326,    -1,   366,   210,    -1,   383,    -1,   366,   187,    -1,
     382,    -1,    89,  1267,    -1,    90,  1249,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1343,  1343,  1343,  1375,  1376,  1380,  1381,  1385,  1386,
    1390,  1390,  1413,  1420,  1427,  1433,  1434,  1435,  1439,  1440,
    1444,  1468,  1469,  1473,  1507,  1513,  1525,  1499,  1535,  1534,
    1572,  1607,  1608,  1612,  1613,  1616,  1617,  1621,  1630,  1639,
    1640,  1644,  1648,  1657,  1658,  1666,  1667,  1677,  1678,  1682,
    1683,  1684,  1685,  1686,  1693,  1692,  1705,  1706,  1709,  1710,
    1724,  1723,  1733,  1734,  1735,  1736,  1740,  1741,  1745,  1746,
    1747,  1748,  1752,  1759,  1766,  1773,  1784,  1788,  1792,  1796,
    1803,  1804,  1811,  1810,  1821,  1822,  1823,  1830,  1831,  1835,
    1839,  1851,  1855,  1856,  1861,  1864,  1871,  1876,  1887,  1900,
    1901,  1909,  1910,  1914,  1915,  1916,  1917,  1918,  1919,  1920,
    1921,  1922,  1923,  1924,  1925,  1933,  1932,  1951,  1961,  1974,
    1982,  1985,  1986,  1990,  2000,  2016,  2015,  2039,  2045,  2051,
    2057,  2063,  2069,  2079,  2083,  2090,  2094,  2099,  2098,  2109,
    2113,  2120,  2121,  2122,  2123,  2124,  2125,  2132,  2147,  2150,
    2157,  2165,  2169,  2180,  2200,  2208,  2219,  2220,  2226,  2247,
    2248,  2252,  2256,  2277,  2300,  2382,  2385,  2394,  2413,  2429,
    2447,  2465,  2482,  2498,  2499,  2506,  2507,  2516,  2517,  2528,
    2529,  2534,  2533,  2554,  2564,  2565,  2569,  2570,  2571,  2572,
    2573,  2574,  2575,  2576,  2577,  2578,  2579,  2580,  2581,  2588,
    2594,  2604,  2617,  2630,  2646,  2647,  2648,  2649,  2652,  2653,
    2659,  2660,  2664,  2668,  2669,  2674,  2677,  2678,  2685,  2693,
    2694,  2695,  2702,  2729,  2740,  2747,  2749,  2750,  2756,  2756,
    2763,  2768,  2773,  2780,  2781,  2782,  2786,  2797,  2798,  2802,
    2807,  2812,  2817,  2828,  2839,  2849,  2857,  2858,  2859,  2865,
    2876,  2883,  2884,  2890,  2898,  2899,  2900,  2906,  2907,  2908,
    2915,  2916,  2920,  2921,  2927,  2955,  2956,  2957,  2958,  2965,
    2964,  2980,  2981,  2985,  2988,  2989,  2995,  2996,  3004,  3005,
    3013,  3014,  3018,  3039,  3038,  3055,  3062,  3066,  3072,  3073,
    3077,  3087,  3102,  3103,  3104,  3105,  3106,  3107,  3108,  3109,
    3110,  3117,  3124,  3124,  3124,  3130,  3150,  3184,  3215,  3216,
    3223,  3224,  3228,  3229,  3236,  3247,  3252,  3263,  3264,  3268,
    3269,  3275,  3286,  3304,  3305,  3309,  3310,  3311,  3315,  3322,
    3329,  3338,  3350,  3402,  3417,  3418,  3422,  3434,  3476,  3478,
    3477,  3493,  3496,  3496,  3514,  3515,  3517,  3521,  3523,  3522,
    3557,  3570,  3578,  3583,  3589,  3598,  3608,  3611,  3623,  3624,
    3625,  3626,  3630,  3634,  3638,  3642,  3646,  3650,  3654,  3658,
    3662,  3666,  3670,  3674,  3678,  3689,  3690,  3694,  3695,  3699,
    3700,  3701,  3705,  3706,  3710,  3736,  3740,  3749,  3753,  3762,
    3763,  3764,  3765,  3766,  3767,  3768,  3769,  3770,  3771,  3772,
    3773,  3774,  3775,  3782,  3806,  3834,  3837,  3846,  3871,  3882,
    3883,  3887,  3891,  3895,  3899,  3903,  3907,  3911,  3915,  3919,
    3923,  3927,  3931,  3935,  3940,  3945,  3949,  3953,  3961,  3965,
    3969,  3977,  3981,  3985,  3989,  3993,  3997,  4001,  4005,  4009,
    4017,  4025,  4029,  4033,  4037,  4041,  4045,  4053,  4054,  4058,
    4059,  4065,  4071,  4083,  4101,  4102,  4111,  4135,  4136,  4139,
    4140,  4147,  4171,  4172,  4189,  4190,  4193,  4194,  4201,  4202,
    4207,  4218,  4229,  4240,  4251,  4280,  4279,  4288,  4289,  4293,
    4294,  4297,  4298,  4311,  4324,  4345,  4354,  4368,  4370,  4369,
    4389,  4391,  4390,  4406,  4408,  4407,  4417,  4418,  4425,  4424,
    4450,  4451,  4452,  4459,  4465,  4469,  4470,  4476,  4483,  4484,
    4485,  4489,  4496,  4497,  4501,  4511,  4548,  4552,  4557,  4563,
    4564,  4569,  4570,  4571,  4572,  4573,  4577,  4584,  4591,  4598,
    4605,  4611,  4612,  4617,  4616,  4637,  4638,  4642,  4643,  4644,
    4645,  4646,  4647,  4648,  4649,  4650,  4651,  4652,  4653,  4654,
    4655,  4656,  4657,  4661,  4668,  4672,  4676,  4677,  4678,  4682,
    4686,  4693,  4696,  4701,  4708,  4711,  4716,  4723,  4730,  4735,
    4740,  4747,  4754,  4762,  4763,  4767,  4771,  4778,  4785,  4789,
    4797,  4801,  4802,  4808,  4809,  4810,  4814,  4820,  4821,  4828,
    4835,  4836,  4840,  4845,  4852,  4860,  4868,  4876,  4878,  4877,
    4898,  4899,  4903,  4904,  4908,  4910,  4909,  4966,  4984,  4985,
    4989,  4993,  4997,  5001,  5005,  5009,  5013,  5017,  5021,  5025,
    5029,  5033,  5037,  5041,  5045,  5049,  5053,  5058,  5062,  5066,
    5071,  5076,  5081,  5086,  5087,  5088,  5089,  5090,  5091,  5092,
    5093,  5094,  5101,  5106,  5115,  5116,  5120,  5121,  5126,  5129,
    5133,  5141,  5144,  5148,  5156,  5167,  5175,  5177,  5187,  5176,
    5214,  5214,  5247,  5251,  5250,  5264,  5263,  5283,  5284,  5289,
    5296,  5298,  5302,  5312,  5314,  5322,  5330,  5338,  5367,  5398,
    5400,  5410,  5415,  5438,  5440,  5439,  5475,  5476,  5480,  5481,
    5482,  5499,  5500,  5511,  5510,  5560,  5561,  5565,  5613,  5626,
    5629,  5648,  5653,  5647,  5666,  5666,  5696,  5703,  5704,  5705,
    5706,  5707,  5708,  5709,  5710,  5711,  5712,  5713,  5714,  5715,
    5716,  5717,  5718,  5719,  5720,  5721,  5722,  5723,  5724,  5725,
    5726,  5727,  5728,  5729,  5730,  5731,  5732,  5733,  5734,  5735,
    5736,  5737,  5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,
    5746,  5747,  5748,  5749,  5750,  5751,  5752,  5766,  5778,  5777,
    5786,  5792,  5796,  5800,  5805,  5810,  5815,  5820,  5824,  5828,
    5832,  5836,  5841,  5845,  5849,  5853,  5857,  5861,  5865,  5872,
    5873,  5880,  5881,  5885,  5886,  5890,  5891,  5892,  5893,  5894,
    5898,  5902,  5903,  5906,  5907,  5910,  5911,  5917,  5918,  5922,
    5923,  5927,  5931,  5935,  5939,  5943,  5947,  5951,  5955,  5959,
    5963,  5967,  5971,  5975,  5979,  5983,  5987,  5991,  5995,  5999,
    6003,  6007,  6011,  6015,  6019,  6026,  6030,  6041,  6040,  6049,
    6053,  6057,  6063,  6064,  6071,  6075,  6086,  6085,  6094,  6098,
    6110,  6111,  6119,  6118,  6127,  6128,  6132,  6138,  6138,  6145,
    6144,  6154,  6174,  6178,  6183,  6188,  6209,  6213,  6212,  6229,
    6230,  6235,  6243,  6267,  6269,  6273,  6282,  6295,  6298,  6302,
    6306,  6329,  6330,  6334,  6335,  6340,  6343,  6351,  6355,  6363,
    6367,  6378,  6377,  6385,  6389,  6400,  6399,  6407,  6412,  6420,
    6421,  6422,  6423,  6424,  6432,  6431,  6440,  6447,  6451,  6461,
    6472,  6490,  6489,  6498,  6502,  6506,  6511,  6519,  6523,  6534,
    6533,  6543,  6547,  6551,  6555,  6559,  6563,  6564,  6573,  6575,
    6574,  6582,  6591,  6598,  6602,  6606,  6610,  6620,  6622,  6626,
    6627,  6630,  6632,  6639,  6640,  6644,  6645,  6650,  6654,  6658,
    6662,  6666,  6670,  6674,  6678,  6682,  6686,  6690,  6694,  6698,
    6702,  6706,  6710,  6717,  6721,  6732,  6731,  6740,  6744,  6748,
    6752,  6756,  6763,  6767,  6778,  6777,  6785,  6805,  6804,  6828,
    6836,  6837,  6842,  6853,  6864,  6878,  6882,  6889,  6890,  6895,
    6904,  6913,  6918,  6927,  6928,  6933,  6995,  6996,  6997,  7001,
    7002,  7006,  7010,  7021,  7020,  7032,  7033,  7051,  7065,  7087,
    7109,  7129,  7155,  7154,  7162,  7173,  7172,  7181,  7194,  7193,
    7206,  7215,  7219,  7230,  7243,  7242,  7251,  7255,  7259,  7266,
    7270,  7281,  7280,  7288,  7296,  7297,  7301,  7302,  7303,  7308,
    7311,  7318,  7322,  7330,  7337,  7338,  7339,  7340,  7341,  7342,
    7343,  7348,  7351,  7361,  7360,  7368,  7375,  7388,  7387,  7396,
    7400,  7404,  7408,  7415,  7416,  7417,  7418,  7425,  7424,  7438,
    7448,  7457,  7458,  7462,  7463,  7464,  7465,  7466,  7467,  7471,
    7472,  7476,  7481,  7488,  7489,  7490,  7491,  7492,  7496,  7524,
    7527,  7534,  7538,  7548,  7547,  7560,  7559,  7567,  7571,  7582,
    7581,  7590,  7594,  7601,  7605,  7616,  7615,  7623,  7644,  7668,
    7669,  7670,  7671,  7675,  7676,  7680,  7681,  7682,  7683,  7695,
    7694,  7705,  7711,  7710,  7721,  7729,  7737,  7744,  7748,  7761,
    7768,  7780,  7783,  7788,  7792,  7803,  7810,  7811,  7815,  7816,
    7819,  7820,  7825,  7836,  7835,  7844,  7871,  7872,  7877,  7880,
    7884,  7888,  7892,  7896,  7900,  7907,  7908,  7912,  7913,  7917,
    7921,  7931,  7942,  7941,  7949,  7959,  7970,  7969,  7978,  7985,
    7989,  8000,  7999,  8011,  8020,  8023,  8027,  8034,  8038,  8048,
    8060,  8059,  8068,  8072,  8081,  8082,  8087,  8090,  8098,  8102,
    8109,  8117,  8121,  8132,  8131,  8145,  8146,  8147,  8148,  8149,
    8150,  8154,  8155,  8159,  8160,  8166,  8175,  8182,  8183,  8187,
    8191,  8195,  8199,  8203,  8207,  8211,  8215,  8224,  8228,  8237,
    8246,  8247,  8251,  8260,  8261,  8265,  8269,  8280,  8279,  8288,
    8287,  8318,  8321,  8341,  8342,  8345,  8346,  8354,  8355,  8360,
    8365,  8375,  8391,  8396,  8406,  8423,  8422,  8432,  8445,  8448,
    8456,  8459,  8464,  8469,  8477,  8478,  8479,  8480,  8481,  8482,
    8486,  8494,  8495,  8499,  8503,  8514,  8513,  8523,  8536,  8539,
    8543,  8547,  8555,  8567,  8570,  8577,  8578,  8579,  8580,  8587,
    8586,  8595,  8602,  8603,  8607,  8608,  8609,  8613,  8614,  8618,
    8622,  8633,  8632,  8641,  8645,  8649,  8656,  8660,  8670,  8681,
    8682,  8689,  8688,  8696,  8703,  8716,  8715,  8723,  8737,  8736,
    8744,  8757,  8759,  8760,  8768,  8767,  8776,  8784,  8785,  8790,
    8791,  8796,  8803,  8804,  8809,  8816,  8817,  8821,  8822,  8826,
    8827,  8831,  8835,  8846,  8845,  8854,  8855,  8856,  8857,  8861,
    8888,  8891,  8903,  8913,  8918,  8923,  8928,  8936,  8974,  8975,
    8979,  9017,  9027,  9050,  9051,  9052,  9053,  9057,  9087,  9096,
    9097,  9104,  9103,  9115,  9125,  9126,  9131,  9134,  9138,  9142,
    9149,  9150,  9154,  9155,  9159,  9163,  9175,  9178,  9179,  9188,
    9189,  9198,  9201,  9202,  9211,  9212,  9223,  9226,  9227,  9236,
    9237,  9249,  9252,  9254,  9264,  9265,  9277,  9278,  9282,  9283,
    9284,  9288,  9297,  9308,  9309,  9310,  9314,  9323,  9334,  9339,
    9340,  9349,  9350,  9361,  9365,  9375,  9382,  9389,  9389,  9399,
    9400,  9401,  9405,  9414,  9415,  9417,  9418,  9419,  9420,  9421,
    9423,  9424,  9425,  9426,  9427,  9428,  9430,  9431,  9432,  9434,
    9435,  9436,  9437,  9438,  9441,  9442,  9446,  9447,  9451,  9452,
    9456,  9457,  9461,  9465,  9471,  9475,  9481,  9482,  9483,  9487,
    9488,  9489,  9493,  9494,  9495,  9499,  9503,  9507,  9508,  9509,
    9512,  9513,  9523,  9535,  9544,  9556,  9565,  9577,  9592,  9593,
    9598,  9607,  9613,  9633,  9637,  9658,  9699,  9713,  9714,  9719,
    9725,  9726,  9731,  9743,  9744,  9745,  9752,  9763,  9764,  9768,
    9776,  9784,  9788,  9795,  9804,  9805,  9811,  9825,  9842,  9846,
    9853,  9854,  9855,  9862,  9866,  9873,  9874,  9875,  9876,  9877,
    9881,  9885,  9889,  9893,  9897,  9918,  9922,  9929,  9930,  9931,
    9935,  9936,  9937,  9938,  9939,  9943,  9947,  9954,  9955,  9959,
    9960,  9964,  9965,  9969,  9970,  9981,  9982,  9986,  9987,  9988,
    9992,  9993,  9994, 10001, 10002, 10006, 10007, 10011, 10012, 10013,
   10019, 10023, 10027, 10028, 10032, 10036, 10043, 10050, 10057, 10067,
   10074, 10084, 10094, 10104, 10117, 10121, 10129, 10137, 10141, 10151,
   10166, 10189, 10212, 10228, 10229, 10230, 10231, 10232, 10233, 10237,
   10241, 10258, 10262, 10269, 10270, 10271, 10272, 10273, 10274, 10275,
   10281, 10285, 10289, 10293, 10297, 10301, 10305, 10309, 10313, 10317,
   10324, 10325, 10329, 10330, 10331, 10335, 10336, 10337, 10341, 10345,
   10349, 10356, 10360, 10364, 10371, 10378, 10385, 10395, 10402, 10412,
   10419, 10431, 10439, 10440, 10444, 10445, 10449, 10450, 10455, 10458,
   10466, 10469, 10476, 10478, 10479, 10483, 10484, 10488, 10489, 10490,
   10495, 10498, 10511, 10515, 10523, 10527, 10531, 10535, 10539, 10543,
   10547, 10551, 10558, 10559, 10565, 10566, 10567, 10568, 10569, 10570,
   10571, 10572, 10573, 10574, 10575, 10576, 10577, 10578, 10579, 10580,
   10581, 10582, 10583, 10584, 10585, 10586, 10587, 10588, 10589, 10590,
   10591, 10592, 10593, 10594, 10595, 10596, 10597, 10598, 10599, 10600,
   10601, 10602, 10603, 10604, 10605, 10606, 10607, 10608, 10609, 10610,
   10611, 10612, 10613, 10614, 10615, 10616, 10617, 10618, 10619, 10620,
   10621, 10622, 10623, 10624, 10625, 10626, 10627, 10628, 10629, 10630,
   10631, 10632, 10633, 10634, 10641, 10641, 10642, 10642, 10643, 10643,
   10644, 10644, 10645, 10645, 10646, 10646, 10647, 10647, 10648, 10648,
   10649, 10649, 10650, 10650, 10651, 10651, 10652, 10652, 10653, 10653,
   10654, 10654, 10655, 10655, 10656, 10656, 10657, 10657, 10657, 10658,
   10658, 10659, 10659, 10660, 10660, 10661, 10661, 10662, 10662, 10662,
   10663, 10663, 10664, 10664, 10664, 10665, 10665, 10665, 10666, 10666,
   10666, 10667, 10667, 10668, 10668, 10669, 10669, 10670, 10670, 10670,
   10671, 10671, 10672, 10672, 10673, 10673, 10673, 10673, 10674, 10674,
   10675, 10675, 10676, 10676, 10677, 10677, 10678, 10678, 10679, 10679,
   10680, 10680, 10681, 10681, 10682, 10682, 10682, 10683, 10683, 10684,
   10684, 10685, 10685, 10686, 10686, 10687, 10687, 10688, 10688, 10689,
   10689, 10690, 10690, 10690, 10691, 10691, 10692, 10692, 10693, 10693,
   10697, 10697, 10698, 10698, 10699, 10699, 10700, 10700, 10701, 10701,
   10702, 10702, 10703, 10703, 10704, 10704, 10705, 10705, 10706, 10706,
   10707, 10707, 10708, 10708, 10709, 10709, 10710, 10710, 10711, 10711,
   10712, 10712, 10715, 10716, 10717, 10721, 10721, 10722, 10722, 10723,
   10723, 10724, 10724, 10725, 10725, 10726, 10726, 10727, 10727, 10728,
   10728
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "ACCEPT", "ACCESS", "ADD",
  "ADDRESS", "ADVANCING", "AFTER", "ALL", "ALLOCATE", "ALPHABET",
  "ALPHABETIC", "\"ALPHABETIC-LOWER\"", "\"ALPHABETIC-UPPER\"",
  "ALPHANUMERIC", "\"ALPHANUMERIC-EDITED\"", "ALSO", "ALTER", "ALTERNATE",
  "AND", "ANY", "ARE", "AREA", "\"ARGUMENT-NUMBER\"", "\"ARGUMENT-VALUE\"",
  "AS", "ASCENDING", "ASCII", "ASSIGN", "AT", "ATTRIBUTE", "AUTO",
  "AUTOMATIC", "\"AWAY-FROM-ZERO\"", "\"BACKGROUND-COLOR\"", "BASED",
  "BEFORE", "BELL", "BINARY", "\"BINARY-C-LONG\"", "\"BINARY-CHAR\"",
  "\"BINARY-DOUBLE\"", "\"BINARY-LONG\"", "\"BINARY-SHORT\"", "BLANK",
  "BLINK", "BLOCK", "BOTTOM", "BY", "\"BYTE-LENGTH\"", "CALL", "CANCEL",
  "CF", "CH", "CHAINING", "CHARACTER", "CHARACTERS", "CLASS",
  "CLASSIFICATION", "CLOSE", "CODE", "\"CODE-SET\"", "COLLATING", "COL",
  "COLS", "COLUMN", "COLUMNS", "COMMA", "\"COMMAND-LINE\"",
  "\"comma delimiter\"", "COMMIT", "COMMON", "COMP", "COMPUTE",
  "\"COMP-1\"", "\"COMP-2\"", "\"COMP-3\"", "\"COMP-4\"", "\"COMP-5\"",
  "\"COMP-6\"", "\"COMP-X\"", "\"FUNCTION CONCATENATE\"", "CONDITION",
  "CONFIGURATION", "CONSTANT", "CONTAINS", "CONTENT", "CONTINUE",
  "CONTROL", "CONTROLS", "CONVERSION", "CONVERTING", "COPY",
  "CORRESPONDING", "COUNT", "CRT", "\"CRT-UNDER\"", "CURRENCY",
  "\"FUNCTION CURRENT-DATE\"", "CURSOR", "CYCLE", "DATA", "DATE", "DAY",
  "\"DAY-OF-WEEK\"", "DE", "DEBUGGING", "\"DECIMAL-POINT\"",
  "DECLARATIVES", "DEFAULT", "DELETE", "DELIMITED", "DELIMITER",
  "DEPENDING", "DESCENDING", "DETAIL", "DISC", "DISK", "DISPLAY",
  "\"FUNCTION DISPLAY-OF\"", "DIVIDE", "DIVISION", "DOWN", "DUPLICATES",
  "DYNAMIC", "EBCDIC", "EC", "ELSE", "END", "\"END-ACCEPT\"",
  "\"END-ADD\"", "\"END-CALL\"", "\"END-COMPUTE\"", "\"END-DELETE\"",
  "\"END-DISPLAY\"", "\"END-DIVIDE\"", "\"END-EVALUATE\"",
  "\"END FUNCTION\"", "\"END-IF\"", "\"END-MULTIPLY\"", "\"END-PERFORM\"",
  "\"END PROGRAM\"", "\"END-READ\"", "\"END-RETURN\"", "\"END-REWRITE\"",
  "\"END-SEARCH\"", "\"END-START\"", "\"END-STRING\"", "\"END-SUBTRACT\"",
  "\"END-UNSTRING\"", "\"END-WRITE\"", "ENTRY", "ENVIRONMENT",
  "\"ENVIRONMENT-NAME\"", "\"ENVIRONMENT-VALUE\"", "EOL", "EOP", "EOS",
  "EQUAL", "ERASE", "ERROR", "ESCAPE", "EVALUATE", "\"EVENT STATUS\"",
  "EXCEPTION", "\"EXCEPTION CONDITION\"", "EXCLUSIVE", "EXIT",
  "\"Exponentiation operator\"", "EXTEND", "EXTERNAL", "FD",
  "\"FILE-CONTROL\"", "\"FILE-ID\"", "FILLER", "FINAL", "FIRST",
  "\"FLOAT-BINARY-128\"", "\"FLOAT-BINARY-32\"", "\"FLOAT-BINARY-64\"",
  "\"FLOAT-DECIMAL-16\"", "\"FLOAT-DECIMAL-34\"", "\"FLOAT-DECIMAL-7\"",
  "\"FLOAT-EXTENDED\"", "\"FLOAT-LONG\"", "\"FLOAT-SHORT\"", "FOOTING",
  "FOR", "\"FOREGROUND-COLOR\"", "FOREVER",
  "\"FUNCTION FORMATTED-CURRENT-DATE\"", "\"FUNCTION FORMATTED-DATE\"",
  "\"FUNCTION FORMATTED-DATETIME\"", "\"FUNCTION FORMATTED-TIME\"", "FREE",
  "FROM", "\"FROM CRT\"", "FULL", "FUNCTION", "\"FUNCTION-ID\"",
  "\"FUNCTION\"", "GENERATE", "GIVING", "GLOBAL", "GO", "GOBACK",
  "GREATER", "\"GREATER OR EQUAL\"", "GROUP", "HEADING", "HIGHLIGHT",
  "\"HIGH-VALUE\"", "ID", "IDENTIFICATION", "IF", "IGNORE", "IGNORING",
  "IN", "INDEX", "INDEXED", "INDICATE", "INITIALIZE", "INITIALIZED",
  "INITIATE", "INPUT", "\"INPUT-OUTPUT\"", "INSPECT", "INTO", "INTRINSIC",
  "INVALID", "\"INVALID KEY\"", "IS", "\"I-O\"", "\"I-O-CONTROL\"",
  "JUSTIFIED", "KEPT", "KEY", "KEYBOARD", "LABEL", "LAST", "LEADING",
  "LEFT", "LEFTLINE", "LENGTH", "\"LENGTH OF\"", "LESS",
  "\"LESS OR EQUAL\"", "LIMIT", "LIMITS", "LINAGE", "\"LINAGE-COUNTER\"",
  "LINE", "\"LINE-COUNTER\"", "LINES", "LINKAGE", "\"Literal\"", "LOCALE",
  "\"FUNCTION LOCALE-DATE\"", "\"FUNCTION LOCALE-TIME\"",
  "\"FUNCTION LOCALE-TIME-FROM-SECONDS\"", "\"LOCAL-STORAGE\"", "LOCK",
  "LOWER", "\"FUNCTION LOWER-CASE\"", "LOWLIGHT", "\"LOW-VALUE\"",
  "MANUAL", "MEMORY", "MERGE", "MINUS", "\"MNEMONIC NAME\"", "MODE",
  "MOVE", "MULTIPLE", "MULTIPLY", "NAME", "NATIONAL",
  "\"NATIONAL-EDITED\"", "\"FUNCTION NATIONAL-OF\"", "NATIVE",
  "\"NEAREST-AWAY-FROM-ZERO\"", "\"NEAREST-EVEN\"",
  "\"NEAREST-TOWARD-ZERO\"", "NEGATIVE", "NEXT", "\"NEXT PAGE\"", "NO",
  "\"NO-ECHO\"", "NORMAL", "NOT", "\"NOT END\"", "\"NOT EOP\"",
  "\"NOT EQUAL\"", "\"NOT EXCEPTION\"", "\"NOT INVALID KEY\"",
  "\"NOT OVERFLOW\"", "\"NOT SIZE ERROR\"", "\"NO ADVANCING\"", "NUMBER",
  "NUMBERS", "NUMERIC", "\"NUMERIC-EDITED\"", "\"FUNCTION NUMVAL-C\"",
  "\"OBJECT-COMPUTER\"", "OCCURS", "OF", "OFF", "OMITTED", "ON", "ONLY",
  "OPEN", "OPTIONAL", "OR", "ORDER", "ORGANIZATION", "OTHER", "OUTPUT",
  "OVERLINE", "\"PACKED-DECIMAL\"", "PADDING", "PAGE", "\"PAGE-COUNTER\"",
  "PARAGRAPH", "PERFORM", "PH", "PF", "PICTURE", "\"PICTURE SYMBOL\"",
  "PLUS", "POINTER", "POSITION", "POSITIVE", "PRESENT", "PREVIOUS",
  "PRINTER", "PRINTING", "PROCEDURE", "PROCEDURES", "PROCEED", "PROGRAM",
  "\"PROGRAM-ID\"", "\"Program name\"", "\"PROGRAM-POINTER\"",
  "PROHIBITED", "PROMPT", "QUOTE", "RANDOM", "RD", "READ",
  "\"READY TRACE\"", "RECORD", "RECORDING", "RECORDS", "RECURSIVE",
  "REDEFINES", "REEL", "REFERENCE", "REFERENCES", "RELATIVE", "RELEASE",
  "REMAINDER", "REMOVAL", "RENAMES", "REPLACE", "REPLACING", "REPORT",
  "REPORTING", "REPORTS", "REPOSITORY", "\"Intrinsic function name\"",
  "REQUIRED", "RESERVE", "RESET", "\"RESET TRACE\"", "RETURN", "RETURNING",
  "\"FUNCTION REVERSE\"", "\"REVERSE-VIDEO\"", "REVERSED", "REWIND",
  "REWRITE", "RF", "RH", "RIGHT", "ROLLBACK", "ROUNDED", "RUN", "SAME",
  "SCREEN", "\"SCREEN-CONTROL\"", "SCROLL", "SD", "SEARCH", "SECTION",
  "SECURE", "\"SEGMENT-LIMIT\"", "SELECT", "\"semi-colon\"", "SENTENCE",
  "SEPARATE", "SEQUENCE", "SEQUENTIAL", "SET", "SHARING", "SIGN", "SIGNED",
  "\"SIGNED-INT\"", "\"SIGNED-LONG\"", "\"SIGNED-SHORT\"", "SIZE",
  "\"SIZE ERROR\"", "SORT", "\"SORT-MERGE\"", "SOURCE",
  "\"SOURCE-COMPUTER\"", "SPACE", "\"SPECIAL-NAMES\"", "STANDARD",
  "\"STANDARD-1\"", "\"STANDARD-2\"", "START", "STATIC", "STATUS",
  "STDCALL", "STEP", "STOP", "STRING", "\"FUNCTION SUBSTITUTE\"",
  "\"FUNCTION SUBSTITUTE-CASE\"", "SUBTRACT", "SUM", "SUPPRESS",
  "SYMBOLIC", "SYNCHRONIZED", "\"SYSTEM-DEFAULT\"", "TALLYING", "TAPE",
  "TERMINATE", "TEST", "THAN", "THEN", "THRU", "TIME", "TIMEOUT", "TIMES",
  "TO", "\"&\"", "\")\"", "\":\"", "\"/\"", "\".\"", "\"=\"", "\"FALSE\"",
  "\"FILE\"", "\">\"", "\"INITIAL\"", "\"<\"", "\"-\"", "\"*\"",
  "\"NULL\"", "\"OVERFLOW\"", "\"(\"", "\"+\"", "\"TRUE\"", "TOP",
  "\"TOWARD-GREATER\"", "\"TOWARD-LESSER\"", "TRAILING", "TRANSFORM",
  "\"FUNCTION TRIM\"", "TRUNCATION", "TYPE", "UNDERLINE", "UNIT", "UNLOCK",
  "UNSIGNED", "\"UNSIGNED-INT\"", "\"UNSIGNED-LONG\"",
  "\"UNSIGNED-SHORT\"", "UNSTRING", "UNTIL", "UP", "UPDATE", "UPON",
  "\"UPON ARGUMENT-NUMBER\"", "\"UPON COMMAND-LINE\"",
  "\"UPON ENVIRONMENT-NAME\"", "\"UPON ENVIRONMENT-VALUE\"", "UPPER",
  "\"FUNCTION UPPER-CASE\"", "USAGE", "USE", "USER", "\"USER-DEFAULT\"",
  "\"User FUNCTION\"", "\"User FUNCTION name\"", "USING", "VALUE",
  "VARYING", "WAIT", "WHEN", "\"FUNCTION WHEN-COMPILED\"", "WITH",
  "\"Identifier\"", "WORDS", "\"WORKING-STORAGE\"", "WRITE", "YYYYDDD",
  "YYYYMMDD", "ZERO", "SHIFT_PREFER", "$accept", "start", "$@1",
  "nested_list", "nested_progs", "source_element", "simple_prog", "$@2",
  "program_definition", "program_mandatory", "function_definition",
  "nested_prog", "end_program", "end_mandatory", "end_function",
  "end_function_mandatory", "program_body", "$@3", "$@4", "$@5",
  "program_identification", "$@6", "function_identification",
  "program_name", "as_literal", "program_type", "program_type_clause",
  "_init_or_recurs", "environment_header", "configuration_header",
  "configuration_list", "configuration_paragraph",
  "source_computer_paragraph", "$@7", "source_computer_entry",
  "with_debugging_mode", "object_computer_paragraph", "$@8",
  "object_computer_entry", "object_clauses_list", "object_clauses",
  "object_computer_memory", "object_computer_sequence",
  "object_computer_segment", "object_computer_class", "locale_class",
  "computer_words", "repository_paragraph", "$@9", "repository_entry",
  "repository_list", "repository_name", "user_or_intrinsic",
  "_as_literal_intrinsic", "repository_name_list",
  "special_names_paragraph", "special_names_entry", "special_name_list",
  "special_name", "mnemonic_name_clause", "$@10", "mnemonic_choices",
  "special_name_mnemonic_on_off", "on_off_clauses", "alphabet_name_clause",
  "@11", "alphabet_definition", "alphabet_literal_list",
  "alphabet_literal", "@12", "alphabet_also_sequence", "alphabet_lits",
  "symbolic_characters_clause", "sym_in_word", "symbolic_collection",
  "symbolic_chars_list", "symbolic_chars_phrase", "char_list",
  "integer_list", "class_name_clause", "class_item_list", "class_item",
  "locale_clause", "currency_sign_clause", "with_pic_symbol",
  "decimal_point_clause", "numeric_sign_clause", "cursor_clause",
  "crt_status_clause", "screen_control", "event_status",
  "input_output_header", "file_control_header", "i_o_control_header",
  "file_control_sequence", "file_control_entry", "$@13",
  "select_clause_sequence", "select_clause", "assign_clause",
  "device_name", "_line_adv_file", "_ext_clause", "assignment_name",
  "opt_assignment_name", "access_mode_clause", "access_mode",
  "alternative_record_key_clause", "collating_sequence_clause",
  "file_status_clause", "file_or_sort", "lock_mode_clause", "$@14",
  "lock_mode", "lock_with", "organization_clause", "organization",
  "padding_character_clause", "record_delimiter_clause",
  "record_key_clause", "opt_splitk", "relative_key_clause",
  "reserve_clause", "no_or_integer", "sharing_clause", "sharing_option",
  "opt_i_o_control", "i_o_control_list", "i_o_control_clause",
  "same_clause", "same_option", "multiple_file_tape_clause", "$@15",
  "multiple_file_list", "multiple_file", "multiple_file_position",
  "data_division_header", "file_section_header",
  "file_description_sequence", "file_description",
  "file_description_entry", "$@16", "file_type",
  "file_description_clause_sequence", "file_description_clause",
  "block_contains_clause", "_records_or_characters", "record_clause",
  "record_depending", "opt_from_integer", "opt_to_integer",
  "label_records_clause", "value_of_clause", "file_id", "valueof_name",
  "data_records_clause", "linage_clause", "linage_sequence",
  "linage_lines", "linage_footing", "linage_top", "linage_bottom",
  "recording_mode_clause", "code_set_clause", "report_clause",
  "report_keyword", "rep_name_list", "working_storage_section", "$@17",
  "record_description_list", "$@18", "record_description_list_2",
  "data_description", "$@19", "level_number", "entry_name", "const_name",
  "const_global", "lit_or_length", "con_identifier", "fp32_usage",
  "fp64_usage", "fp128_usage", "pointer_len", "constant_entry",
  "constant_source", "data_description_clause_sequence",
  "data_description_clause", "redefines_clause", "external_clause",
  "as_extname", "global_clause", "picture_clause", "usage_clause", "usage",
  "float_usage", "double_usage", "sign_clause", "report_occurs_clause",
  "occurs_step", "occurs_clause", "occurs_to_integer", "occurs_depending",
  "occurs_keys", "occurs_key_list", "ascending_or_descending",
  "occurs_indexed", "occurs_index_list", "occurs_index",
  "justified_clause", "synchronized_clause", "blank_clause",
  "based_clause", "value_clause", "$@20", "value_item_list", "value_item",
  "false_is", "renames_clause", "any_length_clause",
  "local_storage_section", "$@21", "linkage_section", "$@22",
  "report_section", "$@23", "report_description_sequence",
  "report_description", "$@24", "report_description_options",
  "report_description_option", "control_clause", "control_field_list",
  "control_final_tag", "identifier_list", "control_identifier",
  "page_limit_clause", "page_line_column", "page_heading_list",
  "page_detail", "heading_clause", "first_detail", "last_heading",
  "last_detail", "footing_clause", "report_group_description_list",
  "report_group_description_entry", "$@25", "report_group_options",
  "report_group_option", "type_clause", "type_option",
  "control_heading_final", "control_footing_final", "next_group_clause",
  "next_group_plus", "next_page", "sum_clause_list", "reset_clause",
  "data_or_final", "present_when_condition", "varying_clause",
  "line_clause", "line_keyword_clause", "line_clause_options", "number_is",
  "line_clause_integer", "line_clause_next_page", "column_clause",
  "col_keyword_clause", "col_or_plus", "source_clause",
  "group_indicate_clause", "report_usage_clause", "screen_section", "$@26",
  "opt_screen_description_list", "screen_description_list",
  "screen_description", "$@27", "screen_options", "screen_option",
  "plus_plus", "minus_minus", "screen_line_plus_minus",
  "screen_col_plus_minus", "screen_occurs_clause", "global_screen_opt",
  "procedure_division", "$@28", "$@29", "$@30", "procedure_using_chaining",
  "$@31", "$@32", "procedure_param_list", "procedure_param",
  "procedure_type", "size_optional", "procedure_optional",
  "procedure_returning", "procedure_declaratives", "$@33",
  "procedure_list", "procedure", "section_header", "$@34",
  "opt_use_statement", "paragraph_header", "invalid_statement",
  "opt_segment", "statement_list", "@35", "@36", "statements", "$@37",
  "statement", "accept_statement", "$@38", "accept_body",
  "accp_identifier", "lines_or_number", "opt_at_line_column",
  "at_line_column", "line_number", "column_number", "opt_at_from",
  "opt_at_block", "opt_accp_attr", "accp_attrs", "accp_attr", "end_accept",
  "add_statement", "$@39", "add_body", "add_to", "end_add",
  "allocate_statement", "$@40", "allocate_body", "allocate_returning",
  "alter_statement", "$@41", "alter_body", "alter_entry", "_proceed_to",
  "call_statement", "$@42", "call_body", "mnemonic_conv", "call_using",
  "$@43", "call_param_list", "call_param", "call_type", "call_returning",
  "return_give", "null_or_omitted", "call_on_exception",
  "call_not_on_exception", "end_call", "cancel_statement", "$@44",
  "cancel_body", "close_statement", "$@45", "close_body", "close_option",
  "compute_statement", "$@46", "compute_body", "end_compute",
  "commit_statement", "continue_statement", "delete_statement", "$@47",
  "delete_body", "delete_file_list", "end_delete", "display_statement",
  "$@48", "display_body", "display_list", "$@49", "display_atom",
  "display_upon", "display_upon_crt", "crt_under", "with_clause",
  "with_no_adv_clause", "disp_attrs", "disp_attr", "end_display",
  "divide_statement", "$@50", "divide_body", "end_divide",
  "entry_statement", "$@51", "entry_body", "evaluate_statement", "$@52",
  "evaluate_body", "evaluate_subject_list", "evaluate_subject",
  "evaluate_condition_list", "evaluate_case_list", "evaluate_case",
  "evaluate_other", "evaluate_when_list", "evaluate_object_list",
  "evaluate_object", "opt_evaluate_thru_expr", "end_evaluate",
  "exit_statement", "$@53", "exit_body", "free_statement", "$@54",
  "free_body", "generate_statement", "$@55", "generate_body",
  "goto_statement", "$@56", "go_body", "goto_depending",
  "goback_statement", "if_statement", "$@57", "if_else_statements",
  "end_if", "initialize_statement", "$@58", "initialize_body",
  "initialize_filler", "initialize_value", "initialize_replacing",
  "initialize_replacing_list", "initialize_replacing_item",
  "initialize_category", "initialize_default", "initiate_statement",
  "$@59", "initiate_body", "inspect_statement", "$@60", "inspect_body",
  "send_identifier", "inspect_list", "inspect_tallying", "$@61",
  "inspect_replacing", "inspect_converting", "tallying_list",
  "tallying_item", "replacing_list", "replacing_item", "rep_keyword",
  "replacing_region", "inspect_region", "inspect_before_after",
  "merge_statement", "$@62", "move_statement", "$@63", "move_body",
  "multiply_statement", "$@64", "multiply_body", "end_multiply",
  "open_statement", "$@65", "open_body", "open_mode", "open_sharing",
  "open_option", "perform_statement", "$@66", "perform_body", "$@67",
  "end_perform", "term_or_dot", "perform_procedure", "perform_option",
  "perform_test", "cond_or_exit", "perform_varying_list",
  "perform_varying", "read_statement", "$@68", "read_body", "read_into",
  "with_lock", "read_key", "read_handler", "end_read", "ready_statement",
  "release_statement", "$@69", "release_body", "reset_statement",
  "return_statement", "$@70", "return_body", "end_return",
  "rewrite_statement", "$@71", "rewrite_body", "write_lock", "end_rewrite",
  "rollback_statement", "search_statement", "$@72", "search_body",
  "search_varying", "search_at_end", "search_whens", "search_when",
  "end_search", "set_statement", "$@73", "set_body", "on_or_off",
  "up_or_down", "set_environment", "set_attr", "set_attr_clause",
  "set_attr_one", "set_to", "set_up_down", "set_to_on_off_sequence",
  "set_to_on_off", "set_to_true_false_sequence", "set_to_true_false",
  "sort_statement", "$@74", "sort_body", "@75", "sort_key_list",
  "opt_key_list", "sort_duplicates", "sort_collating", "sort_input",
  "sort_output", "start_statement", "$@76", "start_body", "sizelen_clause",
  "start_key", "start_op", "disallowed_op", "not_equal_op", "end_start",
  "stop_statement", "$@77", "stop_returning", "_opt_status",
  "stop_literal", "string_statement", "$@78", "string_body",
  "string_item_list", "string_item", "opt_with_pointer", "end_string",
  "subtract_statement", "$@79", "subtract_body", "end_subtract",
  "suppress_statement", "_printing", "terminate_statement", "$@80",
  "terminate_body", "transform_statement", "$@81", "transform_body",
  "unlock_statement", "$@82", "unlock_body", "opt_record",
  "unstring_statement", "$@83", "unstring_body", "unstring_delimited",
  "unstring_delimited_list", "unstring_delimited_item", "unstring_into",
  "unstring_into_item", "unstring_into_delimiter", "unstring_into_count",
  "unstring_tallying", "end_unstring", "use_statement", "$@84",
  "use_phrase", "use_file_exception", "use_global",
  "use_file_exception_target", "use_debugging", "debugging_list",
  "debugging_target", "all_refs", "use_reporting", "use_exception",
  "use_ex_keyw", "write_statement", "$@85", "write_body", "from_option",
  "write_option", "before_or_after", "write_handler", "end_write",
  "on_accp_exception", "opt_on_accp_exception",
  "opt_not_on_accp_exception", "on_disp_exception",
  "opt_on_disp_exception", "opt_not_on_disp_exception", "on_size_error",
  "opt_on_size_error", "opt_not_on_size_error", "on_overflow",
  "opt_on_overflow", "opt_not_on_overflow", "return_at_end", "at_end",
  "at_end_clause", "not_at_end_clause", "at_eop", "at_eop_clause",
  "not_at_eop_clause", "invalid_key", "opt_invalid_key_sentence",
  "opt_not_invalid_key_sentence", "_opt_scroll_lines", "condition", "expr",
  "partial_expr", "$@86", "expr_tokens", "expr_token", "eq", "gt", "lt",
  "ge", "le", "exp_list", "e_sep", "exp", "exp_term", "exp_factor",
  "exp_unary", "exp_atom", "line_linage_page_counter", "arithmetic_x_list",
  "arithmetic_x", "record_name", "table_name", "file_name_list",
  "file_name", "report_name", "mnemonic_name_list", "mnemonic_name",
  "procedure_name_list", "procedure_name", "label", "integer_label",
  "reference_list", "reference", "single_reference", "opt_reference_list",
  "opt_reference", "reference_or_literal", "undefined_word", "unique_word",
  "target_x_list", "target_x", "x_list", "x", "report_x_list", "expr_x",
  "arith_x", "prog_or_entry", "alnum_or_id", "simple_value",
  "simple_all_value", "id_or_lit", "id_or_lit_or_func", "num_id_or_lit",
  "positive_id_or_lit", "pos_num_id_or_lit", "from_parameter",
  "sub_identifier", "sort_identifier", "sub_identifier_1", "identifier",
  "identifier_1", "target_identifier", "target_identifier_1",
  "qualified_word", "subref", "refmod", "integer", "symbolic_integer",
  "report_integer", "class_value", "literal", "basic_literal",
  "basic_value", "function", "func_no_parm", "func_one_parm",
  "func_multi_parm", "func_refmod", "func_args", "trim_args",
  "numvalc_args", "locale_dt_args", "not_const_word", "flag_all",
  "flag_duplicates", "flag_initialized", "flag_initialized_to",
  "to_init_val", "flag_next", "flag_not", "flag_optional", "flag_rounded",
  "round_mode", "round_choice", "flag_separate", "error_stmt_recover",
  "_advancing", "_after", "_are", "_area", "_as", "_at", "_binary", "_by",
  "_character", "_characters", "_contains", "_data", "_file", "_for",
  "_from", "_in", "_in_order", "_indicate", "_initial", "_into", "_is",
  "_is_are", "_key", "_left_or_right", "_line_or_lines", "_limits",
  "_lines", "_mode", "_number", "_numbers", "_of", "_on", "_onoff_status",
  "_other", "_page", "_procedure", "_program", "_record", "_right",
  "_sign", "_signed", "_sign_is", "_size", "_standard", "_status", "_tape",
  "_then", "_times", "_to", "_to_using", "_when", "_when_set_to", "_with",
  "coll_sequence", "column_or_col", "columns_or_cols", "comp_equal",
  "exception_or_error", "exception_or_overflow", "in_of", "label_option",
  "line_or_lines", "lock_records", "object_char_or_word", "records",
  "reel_or_unit", "scroll_line_or_lines", "size_or_length", "with_dups",
  "prog_coll_sequence", "detail_keyword", "ch_keyword", "cf_keyword",
  "ph_keyword", "pf_keyword", "rh_keyword", "rf_keyword",
  "control_keyword", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   512,   514,   513,   515,   515,   516,   516,   517,   517,
     519,   518,   520,   521,   522,   523,   523,   523,   524,   524,
     525,   526,   526,   527,   529,   530,   531,   528,   533,   532,
     534,   535,   535,   536,   536,   537,   537,   538,   538,   538,
     538,   539,   539,   540,   540,   541,   541,   542,   542,   543,
     543,   543,   543,   543,   545,   544,   546,   546,   547,   547,
     549,   548,   550,   550,   550,   550,   551,   551,   552,   552,
     552,   552,   553,   554,   555,   556,   557,   557,   557,   557,
     558,   558,   560,   559,   561,   561,   561,   562,   562,   563,
     563,   563,   564,   564,   565,   565,   566,   566,   567,   568,
     568,   569,   569,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   572,   571,   573,   573,   573,
     573,   574,   574,   575,   575,   577,   576,   578,   578,   578,
     578,   578,   578,   579,   579,   580,   580,   581,   580,   582,
     582,   583,   583,   583,   583,   583,   583,   584,   585,   585,
     586,   587,   587,   588,   589,   589,   590,   590,   591,   592,
     592,   593,   593,   594,   595,   596,   596,   597,   598,   599,
     600,   601,   602,   603,   603,   604,   604,   605,   605,   606,
     606,   608,   607,   607,   609,   609,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   611,
     611,   611,   611,   611,   612,   612,   612,   612,   613,   613,
     614,   614,   614,   615,   615,   616,   616,   616,   617,   618,
     618,   618,   619,   620,   621,   622,   622,   622,   624,   623,
     625,   625,   625,   626,   626,   626,   626,   627,   627,   628,
     628,   628,   628,   629,   630,   631,   632,   632,   632,   633,
     634,   635,   635,   636,   637,   637,   637,   638,   638,   638,
     639,   639,   640,   640,   641,   642,   642,   642,   642,   644,
     643,   645,   645,   646,   647,   647,   648,   648,   649,   649,
     650,   650,   651,   653,   652,   652,   654,   654,   655,   655,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   657,   658,   658,   658,   659,   659,   659,   660,   660,
     661,   661,   662,   662,   663,   664,   664,   665,   665,   666,
     666,   667,   668,   669,   669,   670,   670,   670,   671,   672,
     673,   674,   675,   676,   677,   677,   678,   678,   679,   680,
     679,   681,   682,   681,   683,   683,   683,   684,   685,   684,
     684,   686,   687,   687,   687,   688,   689,   689,   690,   690,
     690,   690,   691,   691,   691,   691,   691,   691,   691,   691,
     691,   691,   691,   691,   691,   692,   692,   693,   693,   694,
     694,   694,   695,   695,   696,   697,   697,   698,   698,   699,
     699,   699,   699,   699,   699,   699,   699,   699,   699,   699,
     699,   699,   699,   700,   701,   702,   702,   703,   704,   705,
     705,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   707,   707,   708,
     708,   709,   709,   710,   711,   711,   712,   713,   713,   714,
     714,   715,   716,   716,   717,   717,   718,   718,   719,   719,
     720,   721,   722,   723,   724,   726,   725,   727,   727,   728,
     728,   729,   729,   730,   730,   731,   731,   732,   733,   732,
     734,   735,   734,   736,   737,   736,   738,   738,   740,   739,
     741,   741,   741,   742,   742,   742,   742,   743,   744,   744,
     744,   745,   746,   746,   747,   748,   749,   749,   749,   750,
     750,   751,   751,   751,   751,   751,   752,   753,   754,   755,
     756,   757,   757,   759,   758,   760,   760,   761,   761,   761,
     761,   761,   761,   761,   761,   761,   761,   761,   761,   761,
     761,   761,   761,   762,   763,   763,   763,   763,   763,   763,
     763,   764,   764,   764,   765,   765,   765,   766,   767,   767,
     767,   768,   769,   770,   770,   771,   771,   772,   773,   774,
     775,   776,   776,   777,   777,   777,   778,   779,   779,   780,
     781,   781,   782,   782,   783,   784,   785,   786,   787,   786,
     788,   788,   789,   789,   790,   791,   790,   790,   792,   792,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   794,   794,   795,   795,   796,   796,
     796,   797,   797,   797,   798,   799,   800,   801,   802,   800,
     803,   800,   804,   805,   804,   806,   804,   807,   807,   808,
     809,   809,   809,   810,   810,   810,   810,   810,   810,   811,
     811,   812,   812,   813,   814,   813,   815,   815,   816,   816,
     816,   816,   816,   818,   817,   819,   819,   820,   821,   822,
     822,   824,   825,   823,   827,   826,   826,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   830,   829,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   832,
     832,   833,   833,   834,   834,   835,   835,   835,   835,   835,
     836,   837,   837,   838,   838,   839,   839,   840,   840,   841,
     841,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   843,   843,   845,   844,   846,
     846,   846,   847,   847,   848,   848,   850,   849,   851,   851,
     852,   852,   854,   853,   855,   855,   856,   857,   857,   859,
     858,   860,   861,   861,   861,   861,   862,   863,   862,   864,
     864,   865,   865,   866,   866,   866,   866,   867,   867,   867,
     867,   868,   868,   869,   869,   870,   870,   871,   871,   872,
     872,   874,   873,   875,   875,   877,   876,   878,   878,   879,
     879,   879,   879,   879,   881,   880,   882,   883,   883,   884,
     885,   887,   886,   888,   888,   889,   889,   890,   890,   892,
     891,   893,   893,   893,   893,   893,   893,   893,   894,   895,
     894,   896,   897,   897,   897,   897,   897,   898,   898,   899,
     899,   900,   900,   901,   901,   902,   902,   903,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   904,   904,   906,   905,   907,   907,   907,
     907,   907,   908,   908,   910,   909,   911,   913,   912,   914,
     915,   915,   916,   916,   916,   917,   917,   918,   918,   919,
     920,   921,   921,   922,   922,   923,   923,   923,   923,   924,
     924,   925,   925,   927,   926,   928,   928,   928,   928,   928,
     928,   928,   930,   929,   931,   933,   932,   934,   936,   935,
     937,   938,   938,   939,   941,   940,   942,   942,   942,   943,
     943,   945,   944,   946,   947,   947,   948,   948,   948,   949,
     949,   950,   950,   951,   952,   952,   952,   952,   952,   952,
     952,   953,   953,   955,   954,   956,   956,   958,   957,   959,
     960,   960,   960,   961,   961,   961,   961,   963,   962,   964,
     965,   966,   966,   967,   967,   967,   967,   967,   967,   968,
     968,   969,   969,   970,   970,   970,   970,   970,   971,   972,
     972,   973,   973,   975,   974,   977,   976,   978,   978,   980,
     979,   981,   981,   982,   982,   984,   983,   985,   985,   986,
     986,   986,   986,   987,   987,   988,   988,   988,   988,   990,
     989,   991,   992,   991,   991,   993,   993,   994,   994,   995,
     995,   996,   996,   996,   996,   996,   997,   997,   998,   998,
     999,   999,  1000,  1002,  1001,  1003,  1004,  1004,  1005,  1005,
    1005,  1005,  1005,  1005,  1005,  1006,  1006,  1007,  1007,  1008,
    1008,  1009,  1011,  1010,  1012,  1013,  1015,  1014,  1016,  1017,
    1017,  1019,  1018,  1020,  1021,  1021,  1021,  1022,  1022,  1023,
    1025,  1024,  1026,  1026,  1027,  1027,  1028,  1028,  1029,  1029,
    1030,  1031,  1031,  1033,  1032,  1034,  1034,  1034,  1034,  1034,
    1034,  1035,  1035,  1036,  1036,  1037,  1038,  1039,  1039,  1040,
    1040,  1040,  1040,  1040,  1040,  1040,  1040,  1041,  1041,  1042,
    1043,  1043,  1044,  1045,  1045,  1046,  1046,  1048,  1047,  1050,
    1049,  1051,  1051,  1052,  1052,  1053,  1053,  1054,  1054,  1055,
    1055,  1055,  1056,  1056,  1056,  1058,  1057,  1059,  1060,  1060,
    1061,  1061,  1061,  1061,  1062,  1062,  1062,  1062,  1062,  1062,
    1063,  1064,  1064,  1065,  1065,  1067,  1066,  1066,  1068,  1068,
    1068,  1068,  1068,  1069,  1069,  1070,  1070,  1070,  1070,  1072,
    1071,  1073,  1074,  1074,  1075,  1075,  1075,  1076,  1076,  1077,
    1077,  1079,  1078,  1080,  1080,  1080,  1081,  1081,  1082,  1083,
    1083,  1085,  1084,  1086,  1086,  1088,  1087,  1089,  1091,  1090,
    1092,  1093,  1093,  1093,  1095,  1094,  1096,  1097,  1097,  1098,
    1098,  1099,  1100,  1100,  1101,  1102,  1102,  1103,  1103,  1104,
    1104,  1105,  1105,  1107,  1106,  1108,  1108,  1108,  1108,  1109,
    1110,  1110,  1111,  1111,  1111,  1111,  1111,  1112,  1113,  1113,
    1114,  1114,  1114,  1115,  1115,  1115,  1115,  1116,  1117,  1118,
    1118,  1120,  1119,  1121,  1122,  1122,  1123,  1123,  1123,  1123,
    1124,  1124,  1125,  1125,  1126,  1126,  1127,  1128,  1128,  1129,
    1129,  1130,  1131,  1131,  1132,  1132,  1133,  1134,  1134,  1135,
    1135,  1136,  1137,  1137,  1138,  1138,  1139,  1139,  1140,  1140,
    1140,  1141,  1142,  1143,  1143,  1143,  1144,  1145,  1146,  1147,
    1147,  1148,  1148,  1149,  1149,  1150,  1151,  1153,  1152,  1154,
    1154,  1154,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  1156,  1156,  1157,  1157,
    1158,  1158,  1159,  1160,  1161,  1161,  1162,  1162,  1162,  1163,
    1163,  1163,  1164,  1164,  1164,  1165,  1165,  1166,  1166,  1166,
    1167,  1167,  1168,  1168,  1168,  1168,  1168,  1168,  1169,  1169,
    1170,  1171,  1172,  1173,  1173,  1174,  1175,  1176,  1176,  1177,
    1178,  1178,  1179,  1180,  1180,  1180,  1181,  1182,  1182,  1183,
    1184,  1185,  1185,  1186,  1187,  1187,  1188,  1189,  1190,  1190,
    1191,  1191,  1191,  1192,  1192,  1193,  1193,  1193,  1193,  1193,
    1193,  1193,  1193,  1193,  1193,  1194,  1194,  1195,  1195,  1195,
    1196,  1196,  1196,  1196,  1196,  1196,  1196,  1197,  1197,  1198,
    1198,  1199,  1199,  1200,  1200,  1201,  1201,  1202,  1202,  1202,
    1203,  1203,  1203,  1204,  1204,  1205,  1205,  1206,  1206,  1206,
    1207,  1208,  1209,  1209,  1210,  1211,  1211,  1211,  1211,  1212,
    1213,  1213,  1213,  1213,  1214,  1214,  1215,  1216,  1216,  1217,
    1218,  1219,  1220,  1220,  1220,  1220,  1220,  1220,  1220,  1221,
    1221,  1222,  1222,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,  1224,
    1225,  1225,  1226,  1226,  1226,  1227,  1227,  1227,  1228,  1228,
    1228,  1229,  1229,  1229,  1230,  1230,  1230,  1231,  1231,  1232,
    1232,  1233,  1234,  1234,  1235,  1235,  1236,  1236,  1237,  1237,
    1238,  1238,  1239,  1239,  1239,  1240,  1240,  1241,  1241,  1241,
    1242,  1242,  1243,  1243,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1245,  1245,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1247,  1247,  1248,  1248,  1249,  1249,
    1250,  1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,
    1255,  1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,  1259,
    1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1263,  1264,
    1264,  1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,  1268,
    1269,  1269,  1270,  1270,  1270,  1271,  1271,  1271,  1272,  1272,
    1272,  1273,  1273,  1274,  1274,  1275,  1275,  1276,  1276,  1276,
    1277,  1277,  1278,  1278,  1279,  1279,  1279,  1279,  1280,  1280,
    1281,  1281,  1282,  1282,  1283,  1283,  1284,  1284,  1285,  1285,
    1286,  1286,  1287,  1287,  1288,  1288,  1288,  1289,  1289,  1290,
    1290,  1291,  1291,  1292,  1292,  1293,  1293,  1294,  1294,  1295,
    1295,  1296,  1296,  1296,  1297,  1297,  1298,  1298,  1299,  1299,
    1300,  1300,  1301,  1301,  1302,  1302,  1303,  1303,  1304,  1304,
    1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,
    1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,
    1315,  1315,  1316,  1316,  1316,  1317,  1317,  1318,  1318,  1319,
    1319,  1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323,  1324,
    1324
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     1,     1,
       0,     2,     4,     4,     3,     0,     1,     2,     0,     1,
       3,     0,     1,     3,     0,     0,     0,    20,     0,     7,
       5,     1,     1,     0,     2,     0,     3,     1,     2,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     0,     4,     0,     3,     0,     3,
       0,     4,     0,     2,     3,     2,     1,     2,     1,     1,
       1,     1,     5,     3,     3,     4,     1,     1,     1,     1,
       1,     2,     0,     4,     0,     2,     3,     1,     2,     3,
       3,     3,     1,     1,     0,     2,     1,     2,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     2,     3,     3,
       1,     0,     1,     3,     4,     0,     5,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     0,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       3,     1,     2,     3,     1,     2,     1,     2,     4,     1,
       2,     1,     3,     4,     5,     0,     3,     3,     5,     3,
       4,     3,     3,     0,     3,     0,     2,     0,     2,     0,
       2,     0,     6,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     1,     1,     1,     1,     0,     3,
       0,     1,     1,     1,     1,     0,     1,     1,     4,     1,
       1,     1,     6,     3,     4,     0,     1,     1,     0,     5,
       2,     2,     1,     0,     4,     5,     2,     3,     1,     1,
       3,     1,     2,     4,     4,     4,     1,     3,     4,     4,
       3,     1,     1,     3,     2,     2,     2,     0,     2,     3,
       1,     2,     1,     1,     5,     0,     1,     1,     1,     0,
       6,     1,     2,     2,     0,     2,     0,     3,     0,     3,
       0,     2,     2,     0,     5,     3,     1,     1,     0,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     1,     1,     4,     6,     9,     0,     3,
       0,     2,     0,     2,     3,     5,     5,     1,     1,     1,
       1,     3,     5,     0,     2,     1,     1,     1,     4,     2,
       2,     4,     3,     2,     2,     2,     1,     2,     0,     0,
       5,     0,     0,     2,     2,     3,     2,     1,     0,     4,
       3,     2,     0,     1,     1,     1,     0,     2,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     0,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     6,     0,     2,     7,     0,     2,     0,
       3,     1,     0,     5,     1,     1,     0,     3,     1,     2,
       1,     2,     2,     3,     1,     0,     5,     1,     2,     1,
       3,     0,     4,     2,     4,     2,     2,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     2,     0,     6,
       0,     2,     2,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     2,     1,     4,     1,     4,     2,     0,
       2,     1,     1,     1,     1,     1,     3,     4,     4,     4,
       3,     0,     2,     0,     5,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     1,
       1,     0,     1,     1,     0,     1,     1,     4,     1,     2,
       2,     1,     4,     0,     3,     1,     1,     3,     6,     2,
       2,     2,     2,     0,     2,     1,     1,     0,     3,     2,
       3,     2,     2,     1,     4,     2,     3,     0,     0,     5,
       0,     1,     2,     3,     1,     0,     4,     3,     0,     2,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     5,
       5,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     0,     1,
       1,     0,     1,     1,     3,     2,     0,     0,     0,     9,
       0,     4,     0,     0,     3,     0,     3,     1,     2,     4,
       0,     2,     2,     0,     3,     3,     4,     4,     3,     0,
       1,     0,     2,     0,     0,     7,     0,     2,     1,     1,
       2,     1,     1,     0,     6,     0,     2,     2,     1,     0,
       1,     0,     0,     3,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     4,
       6,     3,     3,     4,     3,     4,     3,     3,     4,     4,
       3,     4,     3,     4,     5,     3,     4,     3,     3,     1,
       1,     1,     2,     0,     1,     3,     3,     2,     2,     2,
       3,     3,     3,     0,     1,     0,     3,     0,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     0,     1,     0,     4,     4,
       5,     6,     0,     2,     0,     1,     0,     3,     3,     4,
       0,     2,     0,     3,     1,     2,     4,     0,     2,     0,
       4,     6,     0,     1,     1,     1,     0,     0,     3,     1,
       2,     2,     3,     0,     2,     2,     2,     0,     3,     2,
       4,     1,     1,     1,     1,     0,     2,     0,     2,     0,
       1,     0,     3,     1,     2,     0,     3,     2,     3,     0,
       1,     3,     3,     2,     0,     4,     4,     0,     1,     1,
       1,     0,     4,     3,     2,     1,     2,     0,     1,     0,
       4,     3,     3,     3,     3,     4,     2,     4,     1,     0,
       3,     5,     0,     2,     2,     2,     2,     0,     2,     1,
       1,     0,     2,     0,     1,     1,     2,     1,     2,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     0,     1,     0,     4,     4,     6,     6,
       8,     8,     0,     1,     0,     3,     2,     0,     4,     2,
       1,     3,     1,     1,     1,     2,     1,     1,     2,     2,
       3,     2,     3,     1,     3,     2,     1,     1,     1,     0,
       2,     0,     1,     0,     3,     0,     1,     1,     2,     1,
       1,     1,     0,     3,     1,     0,     3,     1,     0,     3,
       3,     0,     3,     1,     0,     6,     3,     2,     1,     0,
       1,     0,     3,     5,     0,     2,     0,     3,     3,     0,
       2,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     2,     0,     3,     2,
       1,     1,     1,     2,     1,     1,     1,     0,     3,     2,
       5,     1,     2,     2,     2,     1,     1,     1,     2,     1,
       2,     4,     2,     0,     1,     1,     1,     1,     4,     0,
       2,     3,     3,     0,     3,     0,     3,     3,     4,     0,
       4,     4,     6,     0,     1,     0,     3,     4,     5,     1,
       1,     1,     1,     0,     3,     0,     3,     2,     1,     0,
       3,     2,     0,     4,     2,     0,     1,     1,     1,     1,
       3,     0,     2,     1,     3,     3,     0,     3,     1,     1,
       1,     3,     7,     0,     4,     7,     0,     2,     0,     2,
       2,     3,     3,     3,     2,     0,     3,     1,     1,     0,
       1,     1,     0,     3,     2,     1,     0,     4,     4,     0,
       1,     0,     4,     4,     0,     2,     3,     0,     1,     1,
       0,     4,     4,     6,     0,     2,     0,     2,     1,     2,
       3,     0,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     3,     4,
       1,     2,     3,     1,     2,     3,     3,     0,     3,     0,
       7,     0,     5,     0,     2,     0,     2,     0,     3,     0,
       2,     4,     0,     2,     4,     0,     4,     4,     0,     3,
       0,     4,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     1,     0,     1,     0,     4,     2,     0,     2,
       2,     4,     4,     0,     1,     1,     1,     1,     1,     0,
       4,     5,     1,     2,     1,     3,     3,     0,     4,     0,
       1,     0,     4,     4,     6,     6,     0,     1,     2,     0,
       1,     0,     3,     1,     2,     0,     3,     5,     0,     3,
       2,     0,     1,     1,     0,     4,     6,     0,     3,     1,
       3,     2,     2,     2,     3,     0,     3,     0,     3,     0,
       3,     0,     1,     0,     3,     1,     1,     1,     1,     7,
       0,     1,     1,     1,     1,     1,     1,     4,     1,     2,
       1,     2,     3,     0,     1,     2,     1,     4,     1,     1,
       1,     0,     4,     5,     0,     2,     0,     4,     3,     3,
       1,     1,     1,     1,     0,     1,     2,     0,     2,     0,
       2,     2,     0,     2,     0,     2,     2,     0,     2,     0,
       2,     2,     0,     2,     0,     2,     2,     1,     2,     1,
       1,     2,     2,     2,     1,     1,     2,     2,     2,     0,
       2,     0,     2,     0,     2,     1,     1,     0,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     2,     2,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     3,     1,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     4,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     2,     2,     1,     1,
       3,     2,     2,     1,     1,     3,     3,     4,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     5,     5,     4,     5,     5,     5,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       5,     0,     3,     2,     1,     3,     3,     1,     3,     1,
       3,     0,     0,     1,     0,     1,     0,     1,     0,     2,
       0,     2,     0,     1,     1,     0,     1,     0,     1,     2,
       0,     2,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       0,     1,     0,     1,     1,     0,     1,     1,     0,     2,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       0,     1,     0,     1,     0,     2,     1,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     1,     0,     1,     0,     3,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     1,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,    10,     1,     0,     0,     3,     5,     6,     4,
      43,     8,     9,    43,    43,     0,     0,     7,     0,    11,
      45,    15,    21,    32,    31,    33,    33,     0,     0,    47,
      16,    18,    43,     0,    14,    22,     0,     0,    28,    44,
       0,   173,     0,    17,    12,    19,    15,     0,    34,    30,
    1765,    46,     0,     0,     0,  1810,  1765,  1765,  1765,     0,
       0,     0,     0,     0,  1765,     0,     0,  1742,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1766,     0,     0,  1496,   125,  1765,
    1765,  1811,  1765,     0,     0,     0,     0,  1765,  1765,    60,
      82,     0,    54,    98,  1743,     0,  1765,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1804,    39,  1765,     0,     0,     0,  1564,   169,  1489,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1497,
     150,   151,  1767,   154,  1569,  1192,  1191,   116,   120,  1794,
    1765,     0,   100,   149,   176,   177,    38,  1805,    36,     0,
    1576,  1572,  1577,  1575,  1573,  1578,  1574,   158,   159,   161,
     170,   165,  1852,  1853,     0,   163,     0,  1741,     0,     0,
       0,  1765,  1874,    80,    61,  1740,    66,    68,    69,    70,
      71,  1740,     0,  1765,     0,    83,     0,    87,    55,    58,
     152,  1769,  1768,   155,     0,  1794,  1797,  1796,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1839,   164,     0,  1565,   168,  1873,  1765,
       0,     0,    65,    67,    63,    81,  1740,  1765,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1570,
     153,   156,     0,  1795,   123,   118,   119,   122,   178,     0,
       0,  1638,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1872,    74,    64,     0,
    1490,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1639,   181,  1748,   266,   267,   268,  1730,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1749,  1823,  1731,  1750,
       0,   278,   259,   138,   139,  1860,  1861,    72,  1806,  1824,
    1744,  1751,     0,     0,     0,   280,     0,  1783,  1806,  1831,
       0,   239,     0,  1765,  1740,  1770,   241,     0,  1841,  1838,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1736,  1765,  1745,     0,  1475,   264,  1473,   277,     0,    25,
     140,  1784,  1765,  1807,  1770,  1832,  1833,   210,  1840,   242,
    1806,  1765,  1765,  1771,  1765,  1765,   251,  1730,   252,     0,
    1765,  1783,  1737,     0,     0,   270,   271,   274,  1474,   279,
     286,   287,   338,   281,   341,     0,     0,  1765,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1798,  1798,
       0,   253,     0,  1765,   240,   223,   272,     0,   273,     0,
     487,   282,  1621,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1495,  1494,   243,   244,   245,   246,   249,  1799,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1624,   216,   201,   217,   202,  1748,
     203,   200,   213,   199,   214,  1765,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1765,  1871,     0,   222,  1625,   209,
       0,   247,  1487,     0,   231,   230,   341,   488,     0,     0,
     597,   345,   350,   387,   356,  1744,  1765,     0,     0,  1765,
    1744,  1783,  1765,  1728,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1870,   248,
    1488,     0,   236,   340,   341,   491,     0,     0,    26,  1765,
    1732,     0,     0,     0,  1765,  1728,     0,     0,     0,     0,
       0,  1765,   334,  1729,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   660,     0,   474,   411,  1812,
    1812,  1812,  1812,  1812,  1834,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1808,   446,     0,   422,   408,   423,   424,     0,
       0,  1815,   426,   427,   425,  1772,   429,   430,   428,  1765,
    1767,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1733,     0,   384,     0,   357,   312,   332,  1862,  1863,
    1493,   321,  1491,  1855,  1854,   314,  1781,  1742,  1754,     0,
    1765,   318,   317,  1765,   337,     0,  1858,  1859,   234,   492,
     496,   598,     0,    27,   704,   485,   486,  1813,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1835,     0,
    1809,   471,   457,   403,  1558,   483,  1816,  1773,  1774,   472,
       0,     0,   405,   407,  1652,  1652,   386,     0,  1790,  1587,
       0,     0,  1583,  1588,  1586,  1584,  1589,  1585,   385,   358,
    1579,  1581,     0,   302,  1492,  1782,   323,     0,   305,  1755,
    1817,   331,     0,     0,   235,   495,   600,   662,     0,     0,
     473,     0,  1827,     0,  1556,  1557,     0,   410,   475,   477,
     479,     0,   404,  1740,   451,   452,  1580,  1791,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1742,
    1818,   310,   319,   316,   320,   315,     0,   497,     0,   604,
     599,   601,     0,   665,   663,   681,     0,   758,   827,   836,
     842,   849,   881,   885,   899,   894,   900,   901,   909,   955,
     964,   967,   993,  1002,  1005,  1008,  1013,  1014,  1021,  1043,
    1047,  1083,  1085,  1089,     0,  1095,  1109,  1133,  1151,  1152,
    1155,  1156,  1161,  1169,  1170,  1183,  1217,  1235,     0,  1269,
    1281,  1289,  1291,   686,  1295,  1298,  1304,  1351,   706,   707,
     708,   709,   710,   711,   712,   713,   715,   714,   716,   717,
     718,   719,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   755,   705,   458,
    1828,   459,  1605,  1600,  1611,     0,  1462,  1464,     0,     0,
       0,  1603,     0,  1466,  1604,  1606,  1607,     0,     0,     0,
       0,  1602,  1611,  1601,  1446,  1444,  1451,  1454,  1456,  1459,
    1523,  1461,  1520,  1554,  1521,  1522,  1608,     0,     0,     0,
    1555,   484,   481,   478,     0,   406,  1653,   361,   374,  1582,
       0,     0,   324,   325,   326,   327,     0,   306,  1753,   312,
       0,  1476,   498,     0,   605,     0,   602,   670,   670,     0,
       0,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1704,  1705,  1706,  1707,  1708,
    1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,  1722,  1723,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1654,  1700,  1701,  1702,
    1703,   757,     0,     0,     0,     0,   852,     0,     0,     0,
       0,     0,     0,     0,  1407,   995,     0,     0,  1829,  1407,
       0,     0,     0,     0,     0,     0,   756,     0,  1121,     0,
       0,     0,     0,     0,     0,     0,     0,  1265,  1268,  1255,
    1266,  1267,  1257,     0,     0,  1290,  1288,     0,   704,     0,
       0,     0,     0,  1792,   462,     0,  1598,  1524,  1525,  1526,
       0,     0,     0,     0,     0,     0,     0,  1458,     0,  1457,
       0,  1599,  1447,  1448,  1566,     0,     0,     0,     0,     0,
       0,     0,     0,  1590,     0,     0,     0,     0,   476,     0,
     480,   330,   329,  1734,  1742,   311,     0,   607,   608,   603,
    1739,   670,   667,   673,     0,   670,   682,   657,   780,   825,
     783,   779,  1790,     0,     0,  1514,   834,  1508,   832,  1503,
    1505,  1506,  1507,   837,     0,  1626,  1486,   843,   844,     0,
    1482,  1484,  1483,   855,   853,   854,   879,     0,  1536,   882,
     883,  1535,   886,   889,  1790,   897,     0,  1468,  1640,  1500,
    1559,  1563,  1501,     0,   907,  1806,  1583,   953,  1372,   918,
     922,  1503,     0,  1505,   962,     0,   856,   965,   974,   973,
     991,     0,   970,   972,  1406,     0,   997,  1001,   999,   996,
    1000,   994,  1003,  1004,  1498,  1006,  1007,  1830,  1009,  1480,
    1825,  1405,  1022,  1024,  1044,  1045,  1048,     0,  1050,  1051,
    1052,  1084,  1221,  1551,  1552,     0,  1086,     0,  1093,     0,
    1102,  1099,  1101,  1100,  1096,  1103,  1123,  1486,  1110,  1121,
    1112,     0,  1119,     0,  1537,  1483,  1539,     0,  1149,  1632,
    1153,  1354,  1471,  1159,  1806,  1167,  1354,     0,  1181,  1174,
    1472,     0,  1479,  1184,  1185,  1186,  1187,  1188,  1189,  1210,
    1190,  1213,     0,  1477,     0,     0,  1550,  1563,  1218,  1253,
    1240,  1258,  1738,  1279,     0,  1272,  1274,     0,  1286,     0,
    1292,  1293,   692,   698,   687,   688,   689,   691,     0,  1296,
       0,  1299,  1301,  1321,  1307,  1364,  1354,  1793,     0,   466,
     461,  1613,  1446,  1444,  1463,  1465,  1446,     0,     0,     0,
    1446,  1517,  1518,  1519,     0,  1467,  1460,  1446,     0,  1445,
    1567,     0,  1450,  1449,  1453,  1452,  1455,     0,     0,  1446,
       0,  1765,  1735,     0,   308,     0,  1765,  1814,   668,  1765,
       0,   679,   671,   672,   683,   826,   759,  1735,   793,   784,
       0,     0,     0,     0,  1509,  1510,  1511,   835,   828,     0,
       0,  1504,  1628,  1627,   840,   845,   847,     0,   880,   850,
    1538,   856,   884,   889,  1864,  1865,   887,     0,   890,     0,
     898,   895,  1847,  1846,  1469,     0,  1642,  1470,  1561,  1562,
     904,   905,   908,   902,  1399,   954,   910,   701,     0,   916,
    1374,     0,   933,     0,   927,  1372,  1372,  1372,  1372,   963,
     956,     0,     0,   857,   966,   992,   968,  1407,  1407,   969,
     976,   977,   701,  1431,  1432,  1433,  1427,  1829,  1419,  1439,
    1442,  1441,  1443,  1435,  1426,  1425,  1430,  1429,  1428,  1434,
    1414,  1418,  1436,  1438,  1440,  1416,  1417,  1413,  1415,  1408,
    1409,  1420,  1421,  1422,  1423,  1424,  1412,   998,  1499,  1011,
    1826,   701,  1026,     0,  1046,     0,  1073,  1057,  1049,  1054,
    1055,  1056,  1225,     0,  1553,     0,     0,  1094,  1090,     0,
    1103,  1838,     0,  1111,  1117,  1118,   701,  1114,  1407,     0,
       0,  1122,     0,  1150,  1134,  1633,  1634,  1806,     0,  1154,
    1160,  1157,  1136,  1168,  1162,  1164,  1176,  1182,  1171,     0,
    1176,     0,  1531,  1532,  1211,  1214,     0,     0,  1478,  1194,
       0,  1193,     0,     0,  1561,  1254,  1236,  1242,  1765,  1243,
    1238,     0,     0,  1256,     0,     0,  1280,  1270,     0,  1273,
       0,  1287,  1282,     0,  1294,   699,   697,   690,     0,  1302,
    1303,  1300,  1322,  1305,  1738,     0,  1365,  1352,  1356,   460,
    1738,   456,   464,   465,  1770,  1612,     0,  1608,  1608,  1608,
       0,  1594,     0,  1608,  1568,     0,  1608,  1608,  1837,     0,
     328,  1792,   307,   502,  1765,  1765,  1728,  1778,   531,   501,
     505,   506,     0,     0,   622,  1765,   612,  1834,   613,  1843,
    1842,     0,  1765,     0,   625,   616,   621,  1785,   617,     0,
     620,   627,   624,   618,   623,     0,   628,   619,     0,   639,
     633,   637,   636,   634,   638,   609,   640,   635,     0,  1785,
       0,  1765,   680,     0,     0,   658,   789,   794,   795,  1785,
    1785,   787,   788,  1785,   775,  1367,  1845,  1844,   772,   764,
     766,   767,     0,  1367,     0,     0,     0,   781,   770,     0,
     778,   761,   777,   762,  1528,  1527,     0,  1513,     0,  1790,
    1377,   833,  1563,  1501,     0,  1630,   840,     0,   838,     0,
       0,  1485,   867,   888,   893,     0,     0,  1502,  1377,  1765,
    1641,  1560,   906,   701,   903,  1401,  1373,   702,   920,  1734,
     701,  1371,   926,   925,   924,   923,   934,  1372,  1765,   937,
       0,   940,   941,     0,  1765,   944,   945,   946,   947,     0,
     948,  1372,   935,     0,   795,   913,   914,   911,   912,     0,
    1377,     0,   863,   971,   986,   988,   987,   981,   983,   989,
    1407,   978,   975,  1407,   979,  1437,  1410,  1411,  1792,  1010,
    1481,   701,  1018,  1019,  1829,  1034,  1035,  1037,  1039,  1040,
    1036,  1038,  1029,  1829,  1025,     0,  1074,     0,  1076,  1075,
    1077,  1059,  1069,     0,     0,  1053,  1227,     0,  1756,     0,
    1087,  1377,     0,     0,     0,  1105,  1115,  1128,  1124,  1129,
    1125,  1130,     0,  1120,  1361,  1360,  1127,  1136,  1355,  1547,
    1548,  1549,     0,     0,  1399,     0,   701,     0,  1175,     0,
       0,     0,  1212,     0,  1216,  1215,  1208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1196,  1197,  1635,  1399,
       0,  1260,  1259,  1821,  1821,  1275,  1276,  1277,     0,  1377,
       0,     0,   700,     0,  1622,     0,  1277,  1164,  1724,     0,
    1765,  1620,  1595,  1596,  1597,  1618,  1615,  1616,  1593,  1609,
       0,  1591,  1592,   482,     0,     0,  1889,  1890,  1765,  1728,
       0,   499,   503,   511,   507,   509,   510,   512,   514,     0,
     610,   611,   614,   615,     0,   642,  1786,  1765,  1827,  1765,
     643,   641,   655,  1765,   674,   675,   678,     0,   669,   684,
     686,  1765,   797,     0,     0,   785,   786,     0,   701,   776,
    1369,   763,   765,  1367,   773,   768,   769,   782,   771,  1530,
    1512,  1529,  1640,     0,   701,   829,  1379,  1561,  1562,  1377,
       0,  1629,   839,   841,   848,   846,   872,   871,   875,  1763,
     892,   891,   896,     0,  1400,   701,  1398,   704,  1375,   915,
       0,   938,   939,   942,   943,     0,  1403,  1403,   936,   917,
     929,   930,   928,   931,     0,   957,     0,   858,   859,   673,
       0,  1407,  1407,   985,   701,   982,     0,  1017,   701,  1020,
    1015,     0,     0,  1041,     0,     0,     0,  1070,  1072,     0,
    1065,  1079,  1066,  1067,  1058,  1061,  1079,  1219,  1765,  1770,
       0,  1757,  1226,  1088,  1091,     0,  1105,  1104,  1108,  1097,
       0,  1116,  1113,     0,     0,  1138,  1137,   701,  1158,  1387,
    1163,  1165,     0,  1177,  1407,  1407,  1172,  1178,  1195,  1207,
    1209,  1199,  1200,  1201,  1205,  1202,  1206,  1203,  1204,  1198,
    1636,  1252,     0,  1249,  1250,  1244,     0,  1237,  1869,  1868,
       0,  1822,  1263,  1263,  1382,     0,  1640,  1283,     0,   693,
       0,  1623,  1308,  1309,     0,  1312,  1315,  1319,  1313,  1399,
    1725,     0,   470,   467,   468,     0,  1610,   309,   504,  1779,
    1780,  1571,   519,   516,   352,   532,   508,   513,  1542,   632,
    1540,  1541,   631,   648,   654,     0,   651,   676,   677,   686,
     704,     0,     0,  1367,   790,   792,   791,  1368,   701,  1366,
     774,  1377,  1502,  1378,   701,  1376,  1560,   830,  1631,  1533,
    1534,  1850,  1851,   877,   701,  1790,  1764,   874,   873,   869,
       0,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1643,
    1402,     0,   950,   949,   952,     0,  1545,  1546,   951,     0,
     921,  1377,  1468,  1377,  1468,   860,   861,     0,   865,   864,
     866,   984,   990,   980,  1012,  1016,  1027,  1030,  1031,  1746,
    1023,  1829,  1028,  1079,  1079,     0,  1064,  1062,  1063,  1068,
    1229,     0,  1223,  1758,  1377,  1098,  1107,     0,  1131,     0,
       0,  1145,     0,  1391,   701,  1386,  1166,   701,   701,  1179,
    1251,  1241,  1245,  1246,  1247,  1248,  1239,  1261,  1264,  1262,
     701,  1271,  1384,  1765,  1377,  1377,   695,  1297,  1622,  1311,
    1754,  1317,  1754,  1382,   701,   701,  1353,  1363,  1394,  1395,
    1362,  1359,  1358,  1775,   469,   463,   515,  1856,  1857,   518,
     354,   533,   646,   644,   647,   645,   649,   650,     0,   626,
     652,   653,     0,   704,   796,   801,  1765,   802,   803,   804,
    1765,   805,   806,   807,   808,   809,   810,   811,   813,   814,
     815,     0,   816,  1726,   817,   818,   819,   798,   799,   760,
    1370,   831,  1380,   701,   851,   876,     0,   868,  1866,  1867,
    1404,   932,   959,     0,   958,     0,   862,  1032,  1747,     0,
       0,  1060,  1071,  1079,  1761,  1761,  1080,     0,     0,  1232,
    1228,  1222,  1092,  1106,     0,  1139,  1765,  1399,     0,     0,
    1140,     0,  1144,  1392,  1173,  1180,  1383,   701,  1381,     0,
    1285,  1284,  1323,   694,     0,  1310,     0,  1754,  1314,     0,
    1306,  1396,  1397,  1393,  1776,  1777,  1357,     0,  1765,  1765,
       0,   520,   521,   522,   523,   524,   525,     0,   535,   629,
     630,     0,     0,     0,  1765,  1403,  1403,  1727,     0,   800,
     878,   870,  1377,  1377,     0,  1042,  1078,  1762,     0,     0,
    1765,  1230,     0,     0,  1220,  1224,     0,     0,  1135,  1148,
    1389,  1390,  1147,  1143,  1141,  1142,  1385,  1278,  1330,   696,
    1316,     0,  1320,  1876,  1875,  1765,     0,     0,  1878,     0,
    1765,  1765,   517,  1814,     0,   821,   820,     0,   823,   822,
     824,  1543,  1544,   961,   960,  1033,  1082,  1081,     0,  1233,
    1765,  1407,  1146,  1388,  1350,  1349,  1331,  1324,  1325,  1726,
    1326,  1327,  1328,  1348,     0,  1318,     0,   530,   526,  1877,
       0,     0,  1759,   583,     0,     0,     0,  1765,  1790,   534,
    1765,  1765,     0,   540,   542,   551,   543,   545,   548,   536,
     537,   538,   547,   549,   552,   539,     0,   544,     0,   546,
     550,   541,  1787,  1728,   685,   812,  1231,     0,  1132,     0,
    1819,  1792,   527,   529,   528,  1760,   595,   585,   580,  1765,
     457,  1407,     0,     0,     0,     0,     0,     0,   579,   587,
     586,     0,   589,   593,  1788,  1789,  1767,   591,  1234,     0,
    1820,     0,     0,   584,     0,  1827,   577,  1640,   573,  1515,
    1880,     0,     0,  1882,  1884,     0,  1888,  1886,   553,   558,
     561,   564,   555,   559,   554,   560,   596,     0,   582,     0,
     581,   592,   590,  1347,  1849,  1848,  1802,  1343,  1337,  1338,
    1340,   571,     0,   567,  1800,   568,   459,   594,  1792,   572,
    1516,  1879,  1883,  1881,  1887,  1885,   563,   556,   562,   566,
     557,   565,     0,     0,  1803,  1792,  1346,  1341,  1344,     0,
    1339,   569,  1801,   570,   454,     0,     0,   588,     0,  1345,
    1342,     0,   453,   576,   574,   575,   578,  1336,  1333,  1335,
    1334,  1329,  1332,   455
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    30,
      12,    31,    44,    45,    34,    35,    19,   320,   432,   615,
      32,    50,    14,    25,    37,    95,   131,   132,    20,    29,
      41,    69,    70,   148,   208,   267,    71,   145,   194,   195,
     196,   197,   198,   199,   200,   331,   201,    72,   146,   205,
     206,   207,   262,   304,   263,    73,    74,    75,    76,    77,
     116,   157,   276,   158,    78,   133,   237,   238,   239,   324,
     343,   240,    79,   121,    80,   150,   151,   152,   270,    81,
     177,   178,    82,    83,   244,    84,    85,    86,    87,    88,
      89,    90,   123,   224,   165,   225,   335,   348,   373,   374,
     478,   479,   440,   513,   506,   375,   468,   376,   377,   378,
     379,   380,   381,   520,   544,   382,   383,   384,   385,   386,
     484,   387,   388,   417,   389,   451,   285,   286,   287,   288,
     319,   289,   315,   425,   426,   458,   341,   355,   399,   433,
     434,   503,   435,   534,   566,   567,   827,   568,  1662,  1009,
     763,   569,   570,   703,   833,   571,   572,   828,  1002,  1003,
    1004,  1005,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   758,   814,
     815,   816,   817,   818,   500,   683,   589,   661,   662,   663,
     792,   664,   665,   666,   667,   668,   669,   670,  2545,  2682,
     671,   782,  1144,  1379,  1380,  1644,  1641,  2153,  2154,   672,
     673,   674,   675,   676,   992,   788,   789,  1178,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1186,  1416,
    1669,  1670,  1954,  1955,  1956,  1957,  1671,  2162,  2316,  2431,
    2432,  2433,  2434,  2435,  2436,  1951,  2165,  2438,  2493,  2549,
    2550,  2618,  2657,  2660,  2551,  2643,  2644,  2552,  2649,  2684,
    2553,  2554,  2555,  2556,  2588,  2578,  2589,  2630,  2557,  2558,
    2592,  2559,  2560,  2561,   588,   776,   840,   841,   842,  1188,
    1417,  1705,  2326,  2327,  2328,  2332,  1706,  1707,   713,  1424,
    1980,   714,   845,  1018,  1017,  1191,  1192,  1193,  1421,  1713,
    1020,  1715,  2179,  1138,  1364,  1365,  2296,  2413,  1366,  1367,
    1921,  1776,  1777,  2027,  1368,   779,   898,   899,  1092,  1199,
    1200,  1741,  1428,  1484,  1721,  1722,  1718,  1982,  2183,  2357,
    2358,  1426,   900,  1093,  1206,  1440,  1438,   901,  1094,  1213,
    1758,   902,  1095,  1217,  1218,  1760,   903,  1096,  1226,  1227,
    1494,  1812,  2047,  2048,  2049,  2018,  2019,  2209,  2203,  2364,
    1449,   904,  1097,  1229,   905,  1098,  1232,  1456,   906,  1099,
    1235,  1461,   907,   908,   909,  1100,  1244,  1470,  1473,   910,
    1101,  1247,  1248,  1478,  1249,  1482,  1804,  2042,  2230,  1787,
    1801,  1802,  1476,   911,  1102,  1254,  1490,   912,  1103,  1257,
     913,  1104,  1260,  1261,  1262,  1499,  1500,  1501,  1822,  1502,
    1817,  1818,  2053,  1496,   914,  1105,  1271,   915,  1106,  1272,
     916,  1107,  1275,   917,  1108,  1278,  1829,   918,   919,  1109,
    1833,  2060,   920,  1110,  1282,  1542,  1842,  2063,  2247,  2248,
    2249,  2250,   921,  1111,  1284,   922,  1112,  1286,  1287,  1548,
    1549,  1854,  1550,  1551,  2074,  2075,  1851,  1852,  1853,  2068,
    2256,  2386,   923,  1113,   924,  1114,  1296,   925,  1115,  1298,
    1558,   926,  1117,  1304,  1305,  1562,  2089,   927,  1118,  1308,
    1566,  2092,  1567,  1309,  1310,  1311,  1868,  1870,  1871,   928,
    1119,  1318,  1883,  2271,  2397,  2468,  1574,   929,   930,  1120,
    1320,   931,   932,  1121,  1323,  1581,   933,  1122,  1325,  1884,
    1584,   934,   935,  1123,  1328,  1590,  1887,  2106,  2107,  1588,
     936,  1124,  1333,   159,  1602,  1334,  1335,  1906,  1907,  1336,
    1337,  1338,  1339,  1340,  1341,   937,  1125,  1291,  2260,  1552,
    2391,  1856,  2077,  2389,  2464,   938,  1126,  1349,  1909,  1610,
    2122,  2123,  2124,  1606,   939,  1351,  1613,  2287,  1132,   940,
    1133,  1353,  1354,  1355,  2134,  1617,   941,  1134,  1358,  1622,
     942,  1136,   943,  1137,  1360,   944,  1139,  1369,   945,  1140,
    1371,  1631,   946,  1141,  1373,  1635,  2142,  2143,  1926,  2145,
    2301,  2418,  2303,  1633,  2414,  2478,  2517,  2518,  2519,  2691,
    2520,  2638,  2639,  2669,  2521,  2522,  2523,   947,  1142,  1375,
    1579,  1927,  1876,  2306,  1637,  1989,  1990,  2189,  1479,  1480,
    1781,  2005,  2006,  2195,  2291,  2292,  2408,  2098,  2469,  2099,
    2275,  2307,  2308,  2309,  1774,  1775,  2026,  2224,  1280,  1281,
    1264,  1265,  1529,  1530,  1531,  1532,  1533,  1534,  1535,   974,
    1165,  1383,   976,   977,   978,   979,  1207,  1236,  1464,  1321,
    1329,   395,   396,  1012,  1342,  1343,  1539,  1312,  1220,  1221,
     541,   481,   301,   691,   692,   482,    98,   153,  1273,  1238,
    1208,  1441,  2608,  1390,   981,  1746,  2000,  2076,  2198,  1230,
    1313,  2169,  2500,  2225,  1878,  2170,  1292,  1346,  1210,   983,
    1239,  1240,   734,   784,   785,  2171,   271,  2590,   179,  1211,
     760,   761,  1212,   986,   987,   988,  1173,  1146,  1398,  1394,
    1387,   501,  2144,   537,  1444,  1756,  2011,  1577,  2126,   282,
    1467,  1770,  2219,   794,  1091,  2151,  2448,   604,   339,   684,
    1430,   423,  1194,   202,   115,   393,  2379,   337,   352,  1010,
     770,  2082,  2576,  2458,  2210,    96,   214,   414,   739,  2426,
    1950,   766,   402,  1967,  2596,   798,  1378,   218,   488,  2673,
    2665,   168,   390,   731,   102,   719,   680,   831,  2601,  2132,
     350,  1541,   951,  1279,   407,   729,  1179,  1317,   391,  1723,
    1743,  1465,  2636,  2204,   184,   695,  2319,   708,   347,   596,
    1458,  2370,  2130,   538,   203,  2485,  2491,  2621,  2622,  2623,
    2624,  2625,  1673
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2362
static const yytype_int16 yypact[] =
{
   -2362,   263,   563, -2362,  -185,  -179, -2362,   563, -2362, -2362,
     587, -2362, -2362,   587,   587,   -39,   -39, -2362,   717, -2362,
     768,   524,   789, -2362, -2362,   943,   943,   605,   761, -2362,
   -2362,   145,   587,   -39, -2362, -2362,   828,   711, -2362, -2362,
     797,  1719,   -39, -2362, -2362, -2362,   524,   838, -2362, -2362,
     408, -2362,   664,   664,   883,   798,  1066,  1066,  1066,   932,
     664,   936,   952,   973,  1066,   980,  1015,  1277, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,   852, -2362, -2362, -2362, -2362,
    1165, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1261,  1047,   145, -2362, -2362,  1059,   165, -2362, -2362,  1066,
    1066, -2362,  1066,  1017,  1450,  1017,  1091,  1066,  1066, -2362,
   -2362,  1017, -2362, -2362, -2362,  1042,  1132,  1119, -2362, -2362,
    1067, -2362,  1122, -2362, -2362, -2362, -2362,   502, -2362, -2362,
   -2362,  1243, -2362,  1066,  1118,  1017,  1330,    -9, -2362, -2362,
   -2362, -2362, -2362,  1332,  1121,   722,  1398, -2362,  1099, -2362,
    1042, -2362,    35, -2362, -2362, -2362, -2362, -2362,  1151,   411,
    1066,     9, -2362, -2362, -2362,   358, -2362, -2362, -2362,    39,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1118, -2362,  1162,
   -2362,  -143, -2362, -2362,  1017, -2362,  1206, -2362,  1209,  1197,
    1551,  1066, -2362, -2362, -2362,   755, -2362, -2362, -2362, -2362,
   -2362,   631,  1566,  1066,    50, -2362,    75, -2362, -2362,   -20,
   -2362, -2362, -2362, -2362,  1370,   411, -2362,  1397,   664,   664,
   -2362,  1151,  1181,    55,   -40, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   786, -2362,
      90, -2362,  1118, -2362, -2362,  1305, -2362, -2362, -2362,  1066,
    1233,  1381, -2362, -2362, -2362, -2362,   931,  1066,  1139,  1415,
     -48, -2362,  1619,   459,  1198, -2362, -2362,  1199,  1541, -2362,
    1370, -2362,   664, -2362, -2362, -2362, -2362,  1151, -2362,  1204,
    1344, -2362,   664, -2362,  -106, -2362,    83, -2362, -2362, -2362,
   -2362, -2362,   786, -2362,  1403,  1381, -2362, -2362, -2362,   505,
   -2362, -2362, -2362,  1404, -2362, -2362, -2362, -2362, -2362,  1391,
   -2362, -2362, -2362, -2362, -2362,  1210, -2362, -2362, -2362,  1643,
    1567,  1217, -2362, -2362,   786, -2362, -2362,    18, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1235, -2362,  1482,
    1553,  1219, -2362,  1659, -2362, -2362, -2362, -2362,  1642, -2362,
    1592, -2362,  1175,  1231,  1289, -2362,   786,  1412,  1335,   301,
    1286, -2362,  1287,  1066,  1634,   211,    12,   983, -2362,  1189,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1272,
   -2362,  1435, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1657,  1066, -2362,  1175, -2362,  1175, -2362, -2362,  1248,    -8,
   -2362, -2362,  1066, -2362,  1469, -2362, -2362,   780, -2362, -2362,
     710,  1066,  1066, -2362,  1066,  1066, -2362,  1643, -2362,    84,
    1066,  1412, -2362,  1306,  1208,  1175, -2362,  1382, -2362, -2362,
   -2362, -2362,  1218, -2362,  1221,    61,   284,  1066, -2362, -2362,
    1161, -2362, -2362,   -69,  1295,  1017,  1017, -2362,  1406,  1406,
    1416, -2362,  1017,  1066, -2362, -2362, -2362,  1381, -2362,  1334,
    1470, -2362, -2362,  1282, -2362, -2362, -2362, -2362, -2362,  1017,
   -2362, -2362,   -53,   -53,  1729,   -53, -2362, -2362,   -53,   135,
   -2362, -2362, -2362, -2362, -2362,   758, -2362, -2362, -2362, -2362,
   -2362, -2362,   658, -2362,  1288,  1346,  1483,  -195,  1290,  6473,
   -2362,  1238, -2362, -2362,   -24, -2362, -2362, -2362, -2362,  1210,
   -2362, -2362, -2362, -2362, -2362,  1066,  1017,  1240, -2362,  1240,
   -2362, -2362,  1304,  1352,  1393, -2362,  1309, -2362,  1311, -2362,
    1678, -2362,  1680, -2362,  1734, -2362,  1644, -2362, -2362, -2362,
    1017,  1017, -2362,   -52, -2362, -2362,  1221, -2362,  1321,  1373,
    1384, -2362, -2362, -2362,    43,  1592,  1066,  1123,  1123,  1066,
       4,  1412,  1066,  1752, -2362,  1472, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,   664,   993, -2362,  1017,
   -2362,  1466, -2362, -2362,  1221, -2362,  1328,  1388, -2362,  6781,
     565,  1580,  1381,  1283,  1066,  1752,  1285,   448,   -69,  1381,
    1291,  1066, -2362, -2362, -2362,   -44,   664, -2362, -2362, -2362,
     543, -2362,  1221, -2362,  1337,   844,   802, -2362, -2362,  -160,
     461,   525,   538,   550,  1292, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1407, -2362,  1381, -2362, -2362, -2362, -2362,  1017,
    1017,  1560, -2362, -2362, -2362,   422, -2362, -2362, -2362,  1066,
     167, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1041,
    -127, -2362,  1293, -2362,  1125, -2362,  1348, -2362, -2362, -2362,
   -2362,  1285, -2362, -2362, -2362, -2362,  1544,    44,  1577,  1296,
    1066, -2362, -2362,  1066, -2362,  1138, -2362, -2362, -2362, -2362,
   -2362, -2362,  1677, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1297,
   -2362, -2362,  1355, -2362,  1340,  1361, -2362, -2362, -2362, -2362,
    6948,   378,  1779, -2362,  1408,  1408, -2362,  1148,  1503, -2362,
    1050,  1050, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1365, -2362,  1381,    94, -2362, -2362, -2362,  1381, -2362, -2362,
    1411, -2362,   176,   176, -2362,  1465,  1310,    23,  2667,  3789,
   -2362,  1381,  1377,  7359,  1362, -2362,  1017, -2362,   378, -2362,
    1383,  1572, -2362,  1634, -2362, -2362, -2362, -2362,  1050,  1372,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,  1148, -2362, -2362, -2362, -2362,    34,  1277,
   -2362,   501, -2362, -2362, -2362, -2362,  1325, -2362,  6291, -2362,
   -2362,  1310,  1379, -2362, -2362,  1455,  4173, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1436, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   487, -2362,
   -2362,  1496, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  1720, -2362, -2362,  1375,  2192,    -9,    -9,  1376,  1385,
    1386, -2362,  1390,    -9, -2362, -2362, -2362,  7463,  7359,  7463,
    1396, -2362,  1375, -2362,   208,   904,  -188, -2362,  1664, -2362,
   -2362, -2362, -2362, -2362,  1365, -2362,  1401,  1405,  1414,  7359,
   -2362, -2362,   483, -2362,   378, -2362, -2362, -2362, -2362, -2362,
     -69,   -69, -2362, -2362, -2362, -2362,  1652, -2362, -2362,  1348,
    1381, -2362, -2362,  1392, -2362,  1399, -2362,    59,    59,  1342,
    1417, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  -177,  4710,  7359,   327,   455,   360,  1175,   701,
     577,  5635,  5684,  1588,   959,   814,   701,  1017,  1409, -2362,
     701,  1325,  2123,  1017,  4794,  5684, -2362,   854,  3656,  1175,
    1017,  1175,  1017,    85,   466,  1017,  1175, -2362, -2362, -2362,
   -2362, -2362, -2362,  4980,  5016, -2362, -2362,  1325,   150,  1017,
    1175,  1017,  1017,  1550, -2362,  2798, -2362, -2362,  1365, -2362,
    1378,  1387,  7359,  7359,  7359,  2192,  1420, -2362,   856, -2362,
    2192, -2362, -2362, -2362, -2362,  7359,  7086,  7359,  7359,  7359,
    7359,  7359,  7359, -2362,  2192,  7359,   904,  1476, -2362,  1432,
   -2362, -2362, -2362,  1839,  1277, -2362,   222, -2362, -2362, -2362,
   -2362,   290, -2362,  -175,  -145,   295, -2362, -2362, -2362,  1756,
     654,  1692,  1503,  1017,  2192, -2362,  1759, -2362,  5069, -2362,
   -2362, -2362, -2362, -2362,   157,   715, -2362,   327, -2362,  1446,
   -2362,    -9, -2362, -2362, -2362, -2362,  1763,  2159, -2362,   360,
   -2362, -2362,  1175,  1012,  1503,  1764,   469, -2362,  1510, -2362,
   -2362,  1340,  1365,  1175,  1771,  1335,  1114,  1772,  5282, -2362,
    5335,   158,  1154,  1216,  1773,   118,  1424, -2362, -2362, -2362,
    1774,    47, -2362, -2362, -2362,  4672, -2362, -2362,  1811, -2362,
   -2362, -2362, -2362,   701, -2362, -2362, -2362, -2362, -2362, -2362,
    1484, -2362, -2362,   683,  1325, -2362, -2362,   102, -2362, -2362,
   -2362, -2362, -2362, -2362,  1464,  5684, -2362,  1485,  1788,  1880,
   -2362, -2362, -2362, -2362,   854,  1531, -2362,  1491, -2362,  5204,
      -5,   741,  1502,  1495, -2362,   398, -2362,  1508,  1805,   816,
   -2362,  1753, -2362,  1808,  1335,  1809,  1753,  1017,  1804,  1454,
   -2362,  1001, -2362, -2362, -2362, -2362, -2362, -2362,  1685, -2362,
     701, -2362,   -42, -2362,    48,  1927, -2362,    52, -2362,  1812,
     800,   -41,  1911,  1813,  4087, -2362, -2362,  1017,  1814,  5413,
    1325, -2362, -2362,   508, -2362, -2362, -2362, -2362,  3518, -2362,
    1769, -2362,  1163,  1817,  1856,  1818,  1753, -2362,  1017,  1750,
     205, -2362,   210,   967, -2362, -2362,   351,  1523,  1526,  1530,
     247, -2362,  1365, -2362,  1533, -2362, -2362,   267,  1538,   967,
   -2362,   887,  -188,  -188, -2362, -2362, -2362,   994,  1539,   335,
    1542,  1066, -2362,   -69,  1876,  1540,   391,  6998, -2362,  1066,
    1582,  1682, -2362, -2362,  1886, -2362, -2362,  1001,  1799, -2362,
     723,  1512,    -6,  1552, -2362,  1365, -2362, -2362, -2362,  5945,
    1796, -2362,  1777, -2362,  1626, -2362,  1665,  1747, -2362, -2362,
   -2362,  1424, -2362,  1012, -2362, -2362, -2362,    -3,   -11,  1017,
   -2362, -2362, -2362, -2362, -2362,  7359,  1735, -2362,  1362, -2362,
    1175, -2362, -2362, -2362,  1775, -2362, -2362, -2362,  5684, -2362,
    1715,    57,  1714,  1819,  1529,  1852,  1852,  1852,  1852, -2362,
   -2362,  5684,  5945, -2362, -2362, -2362, -2362,   959,   221, -2362,
    1517, -2362,  1518, -2362, -2362, -2362, -2362,  1409, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  4405,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,     8,
   -2362,  1893,  1433,  1847, -2362,  1001,   136, -2362, -2362,  1660,
   -2362, -2362,   115,  7359, -2362,  1578,   701, -2362, -2362,  5945,
    1531,  1189,  1175, -2362, -2362, -2362, -2362, -2362,  1858,  1017,
     327, -2362,  1258, -2362, -2362, -2362, -2362,  1335,  2123, -2362,
   -2362, -2362,  1800, -2362, -2362,   488,  1898, -2362, -2362,  1017,
    1898,  1583, -2362,  1365, -2362, -2362,   656,  1151, -2362, -2362,
    1316, -2362,  1982,   690,    73, -2362, -2362, -2362,  1066, -2362,
     465,  5684,  5684, -2362,    21,  5606, -2362, -2362,  1017, -2362,
    1836, -2362, -2362,  5945, -2362,  1381, -2362, -2362,  1001, -2362,
   -2362, -2362, -2362, -2362,  1911,  1810, -2362, -2362,  1258, -2362,
    1911, -2362, -2362, -2362,  1469, -2362,  1017,  1401,  1401,  1401,
    2192, -2362,   -75,  1401, -2362,  7208,  1401,  1401, -2362,   378,
   -2362,  1550, -2362, -2362,  1066,  1066,  1752,   934, -2362, -2362,
   -2362, -2362,  1829,   -47, -2362,  1066, -2362,   -89, -2362, -2362,
   -2362,  1366,  1066,  2159, -2362, -2362, -2362,  1738, -2362,  1381,
   -2362,  1978, -2362, -2362, -2362,  1017, -2362, -2362,  1017, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1835,  1738,
     142,  1066, -2362,  1536,  1591, -2362, -2362, -2362,  1778,  1738,
    1738,   109,  1792,  1738, -2362,  1882, -2362, -2362, -2362,  1547,
    1537, -2362,  1001,  1882,  1816,  1628,  1760, -2362, -2362,  1784,
   -2362, -2362, -2362, -2362, -2362, -2362,   366, -2362,  1017,  1503,
     697, -2362,   -33,   -66,   701,  1620,  1626,   701, -2362,  1621,
     327, -2362,    30, -2362, -2362,  1688,  1708, -2362,   853,  1066,
   -2362, -2362, -2362, -2362, -2362,  1776, -2362, -2362, -2362,  2042,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1852,  1066, -2362,
     528, -2362, -2362,  1371,  1066, -2362, -2362, -2362, -2362,   -14,
   -2362,  1227, -2362,  1124,  1778, -2362, -2362, -2362, -2362,  1870,
     697,  1871,    46, -2362, -2362, -2362, -2362,  2058, -2362,  1635,
     195, -2362, -2362,   221, -2362, -2362, -2362, -2362,  1550, -2362,
   -2362, -2362,  1948,  1939,  1409, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1716,  1409, -2362,  1636, -2362,  2031, -2362, -2362,
   -2362,   620, -2362,  1001,  1002, -2362,    62,   205,   -18,   701,
     701,   697,  1884,  1175,    84,   905,  1949, -2362, -2362, -2362,
    2081, -2362,  1896, -2362, -2362, -2362, -2362,  1800, -2362, -2362,
   -2362, -2362,  1017,  1966,  1775,   938, -2362,  1596, -2362,  1598,
    1001,   987, -2362,   366, -2362, -2362, -2362,  5684,  1151,  1151,
    1151,  1151,  1151,  1151,  1151,  1151,   690, -2362,   520,  1775,
     470, -2362, -2362,  1675,  1675, -2362, -2362,   412,  1017,   697,
    1900,  1650, -2362,  1661,  2097,  1017,  -140,   488,  2101,  1606,
    1066, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     927, -2362, -2362, -2362,  1017,   360, -2362, -2362,  1066,  1752,
    1857,  1310, -2362, -2362, -2362,  1017,  1017, -2362, -2362,   200,
   -2362, -2362, -2362, -2362,   200, -2362, -2362,  1066,  1377,  1066,
   -2362, -2362, -2362,  1066, -2362, -2362, -2362,   183, -2362, -2362,
   -2362,  1066,  1609,   200,   200, -2362, -2362,   200, -2362, -2362,
    1820, -2362, -2362,  1882, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1510,    -6, -2362, -2362,  1821,    -1,  1912,   697,
    1003, -2362, -2362, -2362, -2362, -2362, -2362, -2362,    13,    65,
   -2362, -2362, -2362,   752, -2362, -2362, -2362, -2362, -2362, -2362,
     200, -2362, -2362, -2362, -2362,   200,   369,   369, -2362, -2362,
   -2362, -2362, -2362,  1613,   701, -2362,   701,  1049, -2362,   413,
      11,   221, -2362, -2362, -2362,  2058,  1017, -2362, -2362, -2362,
   -2362,  1622,  1597,   110,  1623,  1003,  1001, -2362, -2362,  2070,
   -2362, -2362, -2362, -2362,  1002, -2362,  1934, -2362,  1066,  1469,
    1815, -2362, -2362,   701, -2362,   701,   905, -2362, -2362, -2362,
    1014, -2362, -2362,  1017,  5684,  1185, -2362, -2362, -2362,  1832,
   -2362, -2362,  1862, -2362, -2362, -2362, -2362,  1598, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     -38, -2362,  1017, -2362, -2362, -2362,  1044, -2362, -2362, -2362,
    7359, -2362,  5684,  5684,  1666,  1795,  1510, -2362,   701, -2362,
    1003, -2362,  1822, -2362,  1001, -2362,  2013,  1695, -2362,   714,
   -2362,   566, -2362,  1606, -2362,  1017, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,  1278,   -62, -2362,  1017, -2362, -2362, -2362,
   -2362, -2362, -2362,   875, -2362,   360,   875, -2362, -2362, -2362,
     156,  2091,  2718,  1882, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  1730,  1937, -2362, -2362, -2362,  1940, -2362, -2362, -2362,
   -2362, -2362, -2362,  1848, -2362,  1503, -2362, -2362, -2362, -2362,
    1017, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  3266, -2362, -2362, -2362,  1281, -2362, -2362, -2362,  1819,
   -2362,   697,  1783,   697,  1785, -2362, -2362,  5684, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1597, -2362,  2043,
   -2362,  1409, -2362, -2362, -2362,  1003,  1275, -2362, -2362,  1275,
     -78,  1017, -2362, -2362,   697, -2362, -2362,  1767, -2362,  2099,
    1887,  1913,   738, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,   967, -2362, -2362, -2362,
   -2362, -2362,  1855,  1066,  1730,   697,  1662, -2362,  2097, -2362,
    1577,  2060,  1577,  1666, -2362, -2362, -2362, -2362,  1861, -2362,
   -2362, -2362, -2362,  1308, -2362,  1017,  1007, -2362, -2362,  1857,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   200, -2362,
   -2362, -2362,   200,   -17, -2362, -2362,  1066, -2362, -2362, -2362,
    1066, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  2100, -2362,
   -2362,    45, -2362,  2149, -2362, -2362, -2362,  2718, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,  1017, -2362, -2362, -2362,
   -2362,  1819, -2362,   701, -2362,   701, -2362, -2362, -2362,  2110,
    2050,  1275,  1275, -2362,  1706,  1706, -2362,  1826,  1175,   510,
   -2362,  1017, -2362, -2362,  5684, -2362,  1066,   650,  1902,  1903,
   -2362,  1904, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1017,
   -2362, -2362, -2362, -2362,  1717, -2362,  1017,  1577, -2362,  1017,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1294,  1066,  1066,
    1434, -2362, -2362, -2362, -2362, -2362, -2362,  1498, -2362, -2362,
   -2362,  2062,   200,   200,  1066,   369,   369, -2362,   379, -2362,
   -2362, -2362,  1730,  1730,  5684, -2362,  1275, -2362,  5684,  5684,
    1066,  1175,  1175,  1830, -2362, -2362,  1691,  1017, -2362, -2362,
    1832, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1089, -2362,
   -2362,  1017, -2362, -2362, -2362,  1066,  1857,  1857, -2362,  1959,
    1066,  1066, -2362,  1806,  1722, -2362, -2362,   360, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   327,  1175,
    1066, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1284,
   -2362, -2362, -2362, -2362,  2067, -2362,  1857, -2362, -2362, -2362,
    1857,  1857,  1955,  1878,  1969,  1381,  1679,  1066,  1503, -2362,
    1066,  1066,  1017, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,   -30, -2362,   540, -2362,
   -2362, -2362,  1182,  1752, -2362, -2362, -2362,   327, -2362,  1823,
    1761,  1550, -2362, -2362, -2362, -2362, -2362,  1951, -2362,  1066,
    1355, -2362,  7501,  7501,  1270,  2065,  1990,  1857, -2362,  1885,
   -2362,  1381, -2362, -2362, -2362, -2362,   167, -2362, -2362,  1017,
   -2362,  1314,    70, -2362,   815,  1377, -2362,  1510,  7479, -2362,
   -2362,   876,  1130, -2362, -2362,  1168, -2362, -2362, -2362, -2362,
     -22,   -19, -2362, -2362, -2362, -2362, -2362,  7501, -2362,  1906,
   -2362, -2362, -2362, -2362, -2362, -2362,  1850,   791,    70, -2362,
   -2362, -2362,  1381, -2362,  1868, -2362,  1720, -2362,  1550, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  2146,  1875, -2362,  1550, -2362, -2362,  1892,  1017,
   -2362, -2362, -2362, -2362,  1781,     3,  7501, -2362,   -27, -2362,
   -2362,  1381, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1175, -2362
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2362, -2362, -2362, -2362, -2362,  2194, -2362, -2362, -2362,   949,
   -2362,  2153, -2362,  2111, -2362, -2362,   929, -2362, -2362, -2362,
    1279, -2362, -2362,  1395,  2176, -2362, -2362,  2082, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  2007,
     872, -2362, -2362, -2362, -2362, -2362,  2066, -2362, -2362, -2362,
   -2362,  2009, -2362, -2362, -2362, -2362, -2362, -2362,  2141, -2362,
   -2362, -2362, -2362,  1996, -2362, -2362, -2362, -2362,  1981, -2362,
   -2362,   823, -2362, -2362, -2362, -2362,  2071, -2362, -2362, -2362,
   -2362,  2051, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1022, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1711, -2362,  1824, -2362, -2362, -2362,
    1758, -2362, -2362, -2362, -2362,   367, -2362, -2362,  1947, -2362,
   -2362, -2362, -2362, -2362,  1825, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1226, -2362, -2362, -2362,  1463, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   278,
   -2362, -2362,  1741, -2362,  -753,  -822, -2362, -2362, -2362,   458,
   -2362, -2362, -2362, -2362,   219, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -1389,   825,  1500,   323,   646, -1388, -2362, -2362,
   -2362,  -337,  -402, -2362, -2362,   388, -2362, -2362,    98, -1386,
   -2362, -1383, -2362, -1382, -2362, -2362,  1467, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,   297, -1755, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,  -334, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1426, -2362,
   -2362, -2362,    80,    95, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  1255,   292, -2362,   227, -2362,
   -2362, -2362, -2362, -1344, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -1358, -2362, -2362,  -696, -2362,  1501, -2362, -2362, -2362,
   -2362, -2362, -2362,  1077,   557,   560, -2362,   478, -2362, -2362,
     -74, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     529, -2362, -2362, -2362,  1069, -2362, -2362, -2362, -2362, -2362,
     833, -2362, -2362,   240, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,   836, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,   812, -2362, -2362, -2362, -2362, -2362,
      66, -1760, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,   799, -2362, -2362,   794, -2362, -2362,
     476,   251, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,    56,
     764, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,   759, -2362, -2362,   233, -2362,   460, -2362, -2362,
   -1555, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1006,   753,   226, -2362, -2362, -2362,
   -2362, -2362, -2362, -2281,  1005, -2362, -2362, -2362,   223, -2362,
   -2362, -2362,   438, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   392,
   -2362, -2362, -2362, -2362, -2362, -2362,   728,   213, -2362, -2362,
   -2362, -2362, -2362,  -151, -2362, -2362, -2362, -2362,   415, -2362,
   -2362, -2362,   984, -2362,   985, -2362, -2362,  1202, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,   190, -2362, -2362,
   -2362, -2362, -2362,   974,   403, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,    33, -2362,   406,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  -305, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    -207, -2362,   696, -2362, -2362, -1641, -2362, -2362,  -297, -2362,
   -2362, -1662, -2362, -2362,    38, -2362, -2362, -2362, -2362,   -61,
   -1432, -2362, -2362,    40, -1818, -2362, -2362, -1940, -1528, -1074,
   -1437, -2362, -2362,   809, -1650,   218,   224,   225,   228,     1,
     -25,  -764,   389,   423, -2362,   599,  -572, -1354,  -996,  -861,
    1026, -1538,  -392,  -219, -2362, -1297, -2362, -1037, -2361,   902,
    -535,   -91,  2056, -2362,  1667,  -556,    36,  2205, -1064, -1055,
     126,  -974, -2362, -1097, -1254, -2362,   468, -1266, -1410, -1090,
   -1159, -1792, -2362, -2362, -2362, -1102, -2362,  -843,   748,  -640,
   -2362, -2362,  -103, -1192,  -763,   -99,  2089, -1710,  2120,  -671,
    1094,  -494,  -401, -2362, -2362, -2362,   -26,  1400, -2362, -2362,
     349, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -1950, -2362, -2362,  1618, -2362, -2362,  -154,  -591,  1952, -2362,
    1187, -2362, -1302,  -278,  -598,   895, -2362,  1859, -1421, -2362,
   -1453, -2362, -2362,   -21, -2362,    16,  -654,  -356, -2362, -2362,
   -2362, -2362,   339,  -171, -2362, -1187, -1526,  2156,  1924, -2362,
   -2362, -2362,  -331, -2362, -2362,  1098, -2362, -2362, -2362,   464,
   -2362,   311, -1929, -1469, -2362, -2362, -2362,  -156,   519, -1381,
   -1565, -2362, -2362, -2362,  -155, -2362, -2362,  1681, -2362,  1827,
   -2362, -2362, -2362,   832, -2362, -1777,  -204, -2362, -2362, -2362,
   -2362, -2362, -2362
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1839
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   689,   579,   741,   215,   139,   733,
     415,  1252,   138,   759,   141,  1432,  1014,   160,   778,   975,
     147,   990,  1345,   838,  1865,   245,  1857,   404,  1699,  1701,
    1263,  1702,   139,   427,  1703,  1704,  1709,  1766,  1825,  2174,
    1869,  2038,   696,   464,   180,  1598,  1283,  1459,   437,  1468,
    1615,  1274,  2191,   268,  1234,  1274,   279,   211,  1219,   259,
    1344,  1819,   463,  1397,  1497,  1591,  2100,   226,  1451,  1274,
     790,  2205,   103,   104,   105,   345,   264,  1408,   843,  2637,
     111,   246,  1000, -1552,   321,  1750,   411, -1838,   838,    99,
     392,  2127,  1994,   448,  1327,  1190,   107,  2228,  2238,   768,
     535,   114,  1554,  1237, -1553,   220,  2022,   291,  1190,  2036,
     821,   821,  2441,   529,   744,   134,   135,   790,   136,  1209,
   -1838,  1507,  1828,   143,   144,   360,   215,  1251,  1255,  1953,
     700,  1198,   161, -1738,  1742,  1944,  1564, -1579,  1810,  1452,
    1297,  1299, -1792,  2687,  1824,  1846,  1744,  2387,  2045,   169,
    -661,   825,   297,  1782,  2656,  1604,  -659,  2659,   821,  1356,
    1209,  1716,  1611,  1960,   430,   227,  1936,  1491,  2445,   701,
   -1558,  1599,  2172,  1679,  1974,  1680,   219,   351,  2201,  2683,
    1219,   -96,  1913,  1832,  1785, -1838,  2294,   480,  1427,   211,
   -1838,  2184,  2185,  1847,  1545,  2186,   327,   221,  2688,  2084,
    2080,  2167, -1556,   505,  1158,  1861,  2689,   251,  1866,   182,
     581,   980,  1422,   419,  1442,  2177,  1814,    23,  1538,   258,
   -1825, -1838, -1734,  1415, -1734,  1176,  2161,  2566,  1538,  1332,
   -1792,  1007,  1642,  2016,   283,  1419,    94,   127,  2222,   535,
    2163,  2640,  1814,  2223, -1770,   316,   717, -1765, -1838,   413,
   -1807,   228,  1975,   796,   274,   275,   525,  2137,  2125,  1764,
     749,  1326,  1169,     3,  1216,   295,    15,   212,   418,  1919,
    1293,  1170,    16,   299,   204,    94,  1596,  2640,  1162,  1845,
    1162,  1376,  1293,  -500,  1765,  1274,  2598,    42,  -661,  1538,
    2690,  1536,  -661,  2206,  -659,   229,  2081,   183,  -659,  2587,
    1961,  1420,  2056,    24,   752,   230,   317,   318,   311, -1621,
    1914,  -500,  -500,  1848,   753,  1147,   718,  1162,   314,   231,
    1643,  1555,   -96,  1180,   412,  2086,  1216,   137,  1332,   999,
    1214,  2310,  1924,   582,  1745,  1612,   128,  1162,  1929,  1190,
     139,   745,   139,   139,  1190,   280,  1492,  2197,   284,   139,
    -661, -1750,  2190,  1423,   485,   486,  -659,   283,   493,  2313,
     243,   491,  1923,   243,   137,  2061,   139,   281,  2239,   507,
     507,   449,   507,  2207,  2064,   507,   514,  1849,   485,   410,
    1356,   823,   985,  1819,   431,   232,  1819,   747,  1386,  1386,
    1386,   512,  1783,  1937,   754,   980,   980,   980,   154,   212,
    2009,  1399,  1401, -1738,  1597,  1162,  2017,   424,  1407,   465,
   -1734,  2167,   728,   139,  1522,  2024, -1738,   980,   436,  2388,
     260,  1162,  2028,  1263,  1377,   542,  -500,   443,   444,   783,
     445,   446,   832,   450,  1362,   137,   452,   139,   139,   154,
    1720,  1289,  2320,  1237,  1181,  1182,  1565,   826,   413,   542,
     580,   137,  1664,   469,  -500,   233,   154,   137,   234,   235,
     702,   989,   243,   368,   755,  1751,  1993,  1546,  2037,   492,
    2280,   284,  1234,  2057,  2202,  1234,   139,   394,  1469,   536,
    1665,  1666,   137,   243,   255,   137,     5,  1363,   580, -1734,
     767,  -661,  1860,   686,  1600,   139,  1237,  -659,   137,  1001,
     697,  1274,  1830, -1765,  1779,  2498,  2499,   137,   756,  2240,
    2050,  2054,   137,    97,   783,   996, -1770,  1809,  1811,   129,
     844,  2259,   980,   346,  1965,  2208,   265,  2446,  2103,  2361,
    1601,   540,   292,  1873,   322,   989,  2439,   243,  1547,   149,
    2440,  1538,  2359,  -500, -1738,   732,   261,   735,  1498,   236,
     577,  1540,   137,  1935,  1149,  1536, -1825, -1738,   757, -1637,
    2007,  1784,  2003,  1237,  1434,   394,   985,   985,   985,  2372,
     591,  2374,   593,   980,   137,   598,   600,  2278,   602,  2472,
     980,   980,   980,  1216,  1469,  1862,  1414,  2069,   985,   137,
     749,   681,   222,   980,   980,   980,   980,   980,   980,   980,
     980,  1362,  2392,   980,  1850,   679,  1163,  1362,  1163,  2437,
     688,  2038,   607, -1807,  1819,  1167,  1228,   699,   536,  1331,
    1168,   130,  1999,    94,  2108,   154,  1896,  1237,  1462,  1846,
    2187,   466,  2410,  2411,   752,  2161,  2180,  1911,  1912,   137,
      94,  1916,   704,   216,   753,  1163,  2193, -1738,  1815,  1920,
    2495,  2496, -1738,  2490,  1363,  2253,  1164,  2647,  1645,  1816,
    1363,  1483,  1234,   824,   737,  1163,  -666,  2220,   829,   834,
     834,  -664,  1006,  -500,  1815,   740,  2646,  1847,   749,  1507,
     137,   749,   949,   991,  1427,  1816,   467,   187,   305,  1234,
    2231,   517,  2233,   985,   188, -1617,  2243,  1008,  2381,  2382,
    2245,  1768,  2013,  1234,   137,  1771,  1233,  1234,  1245, -1838,
    2168,  1290,  1667,  2462,  2128, -1614,   772,  1316, -1734,   773,
   -1734,  2236,   752,  2015,   754,   752,  1223,  1319,  1898,  1324,
    2297,  2264,   753,  1163,  1350,   753,  1899,  1332,  2502,  2273,
      18,  -666, -1838,  1127,   985,  2050,  -664,   405,  1372,  1163,
   -1838,   985,   985,   985,  1393,   223,   693, -1752,  1237,  1393,
     453,   682,   328,     4,   985,   985,   985,   985,   985,   985,
     985,   985, -1520,  1393,   985, -1838,  2527,  2528,   187,  2097,
    2031, -1740,  2380,  1657,  2295,   188,  2211,  1679, -1738,  1680,
    2503,  2504,  1747, -1738,   755,  2083,  2161,  1848,   406, -1619,
    2254,  1150,  1151,  1436,  1274,  1538,   738,  2619,  1156,  1167,
    2120,   187,   754,  2121,  1168,   754,  2572,   705,   188,  1767,
    2573,  2574,   154,  1419,   583,   518,  1316,  2463,  2456,   306,
    2360,   137, -1073,  1128,   217,  2333,  2362,  1332,   756,    27,
    1453,  1771,  1668, -1558,  -656,  2383,  2365,  2416,  2593,  2419,
    2461,  1471,    28,   117,  2312,  2158,   129,  1660, -1838,   -35,
     783,  1849,   611,    52,   137,     5,   694,   717,   749,  2591,
     137,  2304,  2492,   137,  1129, -1838, -1073,  1224,  2299,  1225,
    2129,  1773,   755,   137, -1520,   755, -1073,  2311,   757,  1420,
     709,  1940,  1285,   980,   706,   749,   707,   139,   139,   189,
     601,  1900,  1625,  1130,     5,   438, -1734,  1880,  1316,   749,
      53,  1185,   752,   749,  1474,   243,  2403,  2032,  1361,  2404,
    2405,  1463,   753,  2110,  2509,   519,   756,    33,  2563,   756,
     361,   717,  2406,  1901,  2226,  2226, -1836,   720,  1443,   752,
     329,  2274,    21,    22,   717,  1773,  2421,  2422,    54,   753,
      55,   439,    56,   752,  2398,  1902,   717,   752,   130,  1626,
      57,    46,   362,   753,  2481,  2471, -1073,   753,   243,    36,
     137,   190,  1522,   137,  2399,  1719,   757,  1607,  2242,   757,
      43,   980,  -656,  2568,  1177, -1734,  -656,   187,  1943,  2008,
     189,   243,  1222,  1582,   188,   839,  1241,  1131,   228,   330,
    2400,   722,   754,  1241,  1276,  2450,  2305,  1241,  1903,   300,
    1294,  2070,   747,  1266,   724,  1315,    58,  1322,  2366,  1322,
    1330,  1347,  1294,   189,  1300,  2401,   726,   191,  1538,   754,
    2277,  1243,   192,  2212,  2213,  2214, -1073,  1608,  2513,  1322,
    1609,    43,   229,   754,  -656,  2602,   715,   754,  2232,  2476,
    2234,   799,   230,  2606,  1720,  -863,    39,  2524,  -863,  2071,
     839,   403,   190,  2651,   985,  1544,  1447,   253,  1904,   441,
     137,   154,   755,   819,   819,  1947,  2168,  1457,  1772,  1301,
   -1073,   394,   254,   980,    48,  2329,  2529,  1302,  1850,  1237,
     800,   801,   802,   803,   804,   190,  2215,  2666,  1190,   755,
    2641,  1575,  1891,   716,  2543,  2544,  2001,  2546,  2004,    60,
    2547,  2548,  2562,   755,  1222,   325,   756,   755,   191,  1585,
    2269,   819,  2675,   192, -1073,   626,   627,  1543,   253,  2667,
   -1073,  -863,   232,  1241,   747,   255, -1738,  1267,  1268,  2678,
    2692,  1624,  1237,   756,  2642,  2322,  1382,   344,  -863,  2668,
    1576,   191,   985,    61,  1269,    40,   192,   756,  2288,  2288,
     137,   756,    49,  1905,   608, -1520,   757, -1838,    97,  1638,
    1241,  1303,   515, -1520, -1520,   748,  1409,  1881, -1520,   400,
    1241,   712,  1948,  1949,  2427,  -656,   243,   137,  1805,  1806,
    1807,  1808, -1838,   757,  2428,  1614, -1750,   609,  2164,   189,
    2101,   137,   233,   101,  2323,   137,   252,   757,  1270,   822,
     516,   757,   742,   749,   749,   749,  2514,  2429,  2216,  2217,
    2040,  2041,  1568,  2218,  1330,  2102,   193,  1250,   805,   806,
     807,   808,   809,   810,   811,   639,   640,  1241,  2402,   154,
    1569,  1241,    64,  2072,  2196,   743,  1877,  2430,    51,  1393,
    -863,  1509,  1510,  2001,   985,  2515,   997,   752,   752,   752,
    1359,  -863,  1788,  2376,  2004,  1789,  1874,   753,   753,   753,
     416,   190,  1790,  1791, -1838,   139,  2266,   351,   470,   471,
     472,    13,  1316,  2384,  2088,    67,    13,  1639,  1930,    93,
    1511,  1512,  2447,  2516,  -863,  1875,   236,  1457,    94, -1838,
    -863,  2267,  -863,   118,  1396,  -863,   100,  -863,  -863,  -863,
     139,  1167,  2385,  -863,  1167,  -863,  1168,  2652,  1792,  1168,
    -863,  2569,  1202,  2610,  2488,   747,   106,   191,  2607,  2609,
     170,  2221,   192,  2324,   114,  1654,  1752,   749,  2325,  2200,
    2653,   108,  2321,  2226,  2226,  1167,  2501,   754,   754,   754,
    1168,  2583,  -863,  1166,  2650,  2654,    68,  -863,  2160,  2611,
     749,  1646,  1167,  2192,    94,  1650,  2286,  1168,  1454,   750,
     751,  -863,  1652,  2662,   171,  2156,  2483,  2452,  2655,  2453,
     812,   752,   298,   120,   172,  1167,  2484,  1793,   154,  1752,
    1168,   753,  1477,   813,  2200,  -863,   820,   820,   952,   473,
    2483, -1838,  2270,   109,   752,  1864, -1738,  2565,   243,   394,
    2484,    26,  1258,   474,   753,   953,  1794,   755,   755,   755,
    2466, -1838,  2686,  1259,   110,  1167,  -863,  1659,    47,  1885,
    1168,   112,  1672,  1708,   122,  1710,  1222,    91,  1795,   155,
    1894,   156,  1834,  1655,   820,  1835,  1892, -1838,  1836,  1837,
     592,  1895,  1167,  1241,  1910,   599,  1752,  1168,   155,  -863,
     156,   756,   756,   756,   173,  -863,   113,  1222,  1893,  2200,
    2073,   754, -1838,   428,   594,  2634,   595,  -863,  -863,  2635,
    2505,  2594,  2595,  1418,  2506,  2507,  1455,  1418,  2488,   706,
    2029,   707,  1796,  1241,   754,   508,   475,   510,   124,  1523,
     511,  1524,  1388,  1389,  2039,   137,   137,   137,   476,  -863,
     126,   757,   757,   757,  1629,   243,  1630,   954,   140,  -863,
    1752,   137,  1962,  2489,  1963,  -863,  1922,  2033,   749,  2034,
    2317,   982,  2318,  2368,   174,  2369,  1724,  1725,  1973,  -863,
    2483,   755,   142,   139,  -863,  1797,   149, -1738,  1983,  1984,
    2484,  -863,  1987,  -863,   137,  1931,  1402,  1403,   980,  -863,
    2424,  1204,  2425,  1726,   755,  1727,  1157,   956,  1159,   957,
     162,   163,   752,   164,   958,   959,   960,  1726,   175,  1727,
     961,  1728,   753,   167,  2200,   756,   181,  1205,   185,   186,
    1968,  2612,  1404,  1405,  1406,  2613,  2614,   204,   477, -1536,
   -1536, -1536, -1536,   193,   242,  1798,   247,   249,   756,  1835,
     248,  1976,  1836,  1837,   250,  1729,  1730,  1731,  1799,   962,
    2315,  1932,  1933,  1934,  1908,   257,   269,  1938,   176,   273,
    1941,  1942,   278,   294,   296,   757,  2615,   154,   963,  1485,
    1486,  1487,  1488,   300,   302,   303,   357,  1241,   309,   307,
     308,  1241,  2616,  2617,  1241,   312,   313,  1222,   757,   326,
     333,   358,   754,   334,   336,  1732,   338,  1733,   342,   340,
     351,   359,   349,   354,  1734,   353,   356,  1735,   392,   394,
    1945,  1946,   397,   398,   401, -1838,   403,   408,   243,   409,
     187,  1959,   243,   964,   428,   420,   422,   421,  1964,   429,
    1800, -1535, -1535, -1535, -1535,   360,   413,  1241,   454,  2090,
    1838,  1839,   455,   457,   483,   982,   982,   982,   721,   723,
     725,   727,   487,  2262,   459,  -342,   490,  1977,   494,   985,
      52,   495,   755,   502,  1840,  1841,   509,   982,   523,   521,
     522,   527,   533,   543,   965,   966,   548,  2111,  2112,  2113,
    2114,  2115,  2116,  2117,  2118,   547,  1241,  1241,  1241,   549,
     551,  2135,   552,  -355,  1736,   554,  1737,   586,   578,  1894,
    2135,  1885,   585,   587,   603,   610,   756,    53,   605,   613,
    1895,   555,   614,  1332,   685,  2023,   970,   687,   711,   690,
     698,   730,   736,   728,   762,   769,   556,   746,   765,   777,
     771,   781,   783,   786,  2030,   791,   971,   780,   793,   797,
    2035,   972,   823,   836, -1621,    54,  1241,    55,   973,    56,
     137,   830,   950,   998,   989,   994,   757,    57,   995,  1011,
    1016,  1019,  1135,  1171,  1143,  1116,   557,  1145,  1152,  1183,
    1201,   139,  1215,  1187,  1256,  1231,  1196,  1153,  1154,  1253,
    1189,   624,  1155,  2157,  1788,  1277,  1294,  1789,  1160,  1377,
    1288,  1294,   361,  1172,  1790,  1791,  1314,  1174,  1197,  1412,
    1679,  1726,  1680,  1727,  1838,  1839,  1175,   984,  2178,  1410,
    1294,  1294,  1384,    58,  1294,  1411,  1425,  1370,  1431,  1374,
    1437,  1385,  1446,   982,   362,  1448,  1466,  1460,  1840,  1841,
     982,   982,   982,  1391,  -228,  1472,  1241,  1475,  1391,  1489,
    1792,  1495,  1537,   982,   982,   982,   982,   982,   982,   982,
     982,  1493,  1391,   982,  1395,  1540,  1553,  1294,  1557,  1559,
    2090,  1556,  1294,  1294,  1294,  1561, -1538,  2227,  2227,  2272,
    1571,  1241,  2632,  1241,  1570,    59,  2155,  1572,  1573,  1578,
    1587,  1433,  1580,  1589,  1583,  1738,  1332,   363,  1603,  1605,
    1190,  1616,   364,  1621,  2159,  1628,    94,  1632,  1634,  1636,
    1640,  1647,  2597,   558,  1648,  1314,    60,  1231,  1649,  1793,
    1241,  1651,  1241,  2173,   559,  2175,  1653,  1656,  1658,  2176,
    1661,  1663,  1711,   365,  1712,  1714,  1717,  2181,  1748,  1754,
    1755,   366,  1757,  1216,  1759,  1739,  1773,  1769,  1794,  1780,
     980,   980,  1786,  1803,   367,  2532,  1740,  1477,  1820,  1823,
      61,  1831,  1844,    62,  1859,  1546,  1867,  1886,  1882,  1890,
    1795,  1897,  1918,  1952,  1969,  1241,   980,  1966,  1925,  1972,
    1978,   642,  1979,   368,  1719,  1992,   369,  1988,  1294,  1148,
    1981,  1996,   139,  1995,   370,   980,  1991,  1314,  2533,  1997,
    1998,   984,   984,   984,   542,  -225,  2010,  2014,  2020,   428,
    2021,  2025,  1427,  2044,  2046,  2051,  2058,  2052,  2059,  1592,
    2066,  2062,  2065,   984,  1796,   560,   561,  2085,    63,  2093,
    2091,  2534,  2094,   371,  2261,  2097,   372,  2104,  2131,  2105,
     562,  2139,   563,  2138,   980,  1620,  2141,  2140,  2150,    64,
    2152,  2535,  2182,  2161,  2188, -1557,  2229,   428,  2194,  2255,
    2246,  2252,  2258,  2274,  2276,  2293,  2300,  2290,  1241,  2263,
    1241,  2302,   747,   646,    65,  2298,    66,  1797,  2334,  2536,
   -1513,  2004,  2363, -1555,  2373,  2378,  2375,  2393,  2394,  2395,
    2396,  2407,    67,  2305,  2412,  2417,  2444,  2447,   139,  2454,
    2455,  1241,  2457,  2460,  2473,  2474,  2475,  2510,  2479,  2529,
    2390,  2494,  2511,  2564,  2571,  1592,  2575,  2577,  2579,  2600,
    2581,   985,   985,  2603,  2626,   564,  2627,  2664,   984,  2672,
    2599,  2663,  1241,  1242,  2629,  2676,  2677,  1798,  2679,    92,
    1242,    17,    38,   125,  1242,   952,  2681,   985,   256,   166,
    1799,   651,   139,   982,   209,   266,   119,   277,  1242,   290,
    2537,   210,   953,    68,   580,  1294,   985,   504,   241,  1294,
     545,  2087,   565,   323,   442,  1184,   835,  2538,   526,   984,
     787,   952,  1700,  2605,  2674,  2079,   984,   984,   984,  1392,
     456,  2314,  2166,  2628,  1392,   993,  2330,  2539,   953,   984,
     984,   984,   984,   984,   984,   984,   984,  1015,  1392,   984,
    1241,  2331,  1241,  1195,   952,   985,  2237,  1429,  2540,  1986,
     948,  1985,  2043,  2449,  1762,  2012,  1445,  2235,  2465,  1763,
    1778,   953,  1800,  1592,  1821,  2371,  1813,  2541,  1435,  2055,
     428,   982,  2241,  2377,   660,  2542,  1843,  2257,  1855,  2409,
    1560,  2067,  2265,  1863,  1563,  2095,  2268,  1872,  1889,  2149,
    2279,  2119,  1594,  2289,   954,  1595,  1879,  1348,  1619,  2147,
    1242,  2415,  2148,  2670,  1928,   749,  2470,  1888,  1827,  1294,
    1294,  2420,  1294,  1294,  2282,  1294,  2227,  2227,  2423,  1761,
    2283,  2284,  2442,  1586,  2285,   332,  2443,   213,   764,   310,
     954,  2109,   293,   795,  2459,  2570,  1917,  1242,   539,   447,
    1413,   272,  1161,   489,  2251,  2078,  1592,  1242,  2133,   752,
    2620,   958,   959,   960,  1858,   597,   774,   961,     0,   753,
       0,     0,     0,   954,     0,     0,     0,     0,  1391,     0,
       0,     0,     0,   982,   749,  1222,     0,     0,     0,     0,
       0,     0,  2467,     0,     0,  1450,     0,   958,   959,   960,
       0,  1958,     0,   961,     0,  1593,   962,     0,     0,     0,
       0,  1314,     0,     0,  1242,     0,  2580,     0,  1242,     0,
       0,     0,     0,  1970,  2486,  2487,  1971,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
    2497,     0,   962,     0,  1222,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,     0,  2508,     0,     0,     0,
    1592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2631,     0,     0,   962,  2002,     0,     0,  1222,
     964,  2526,     0,     0,     0,  2645,  2530,  2531,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1593,     0,     0,     0,     0,  2567,     0,     0,     0,
       0,     0,     0,  1753,     0,  1222,   964,     0,   754,   755,
       0,     0,     0,  2671,     0,     0,     0,     0,     0,     0,
       0,   965,   966,  2582,     0,     0,  2584,  2585,     0,   984,
       0,     0,     0,     0,     0,     0,  2680,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2693,   756,     0,     0,  1753,   965,   966,     0,
       0,     0,     0,   970,     0,  2604,     0,     0,     0,     0,
       0,  1592,  1592,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,   971,     0,     0,     0,     0,   972,     0,
     965,   966,     0,     0,     0,   973,     0,   137,     0,   970,
    2096,     0,     0,   757,     0,     0,     0,     0,  1592,  1593,
       0,     0,     0,     0,     0,     0,     0,   984,     0,   971,
    1242,     0,   756,  1753,   972,     0,     0,     0,     0,     0,
       0,   973,   970,   137,     0,     0,  2136,     0,   846,     0,
     847,     0,   848,  2146,  2146,     0,     0,   849,     0,     0,
       0,     0,   971,     0,     0,   850,     0,   972,     0,     0,
    1242,     0,     0,  1231,   973,     0,   137,     0,     0,     0,
       0,     0,   757,  1958,  1958,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1753,   851,   852,
       0,     0,  1593,     0,     0,     0,     0,   853,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   854,     0,
       0,   855,     0,     0,  1392,     0,     0,     0,     0,   984,
    2335,     0,     0,  2336,     0,   856,  2337,     0,  2199,     0,
       0,     0,     0,     0,  2338,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   857,     0,
       0,     0,     0,     0,     0,     0,   858,     0,   859,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2244,     0,     0,     0,     0,  2339,
       0,     0,     0,  2199,  1592,     0,     0,     0,     0,   860,
       0,     0,  1592,     0,     0,     0,  1593,     0,     0,     0,
     861,     0,     0,     0,     0,   862,     0,     0,     0,     0,
       0,  1872,     0,     0,  1242,     0,     0,     0,  1242,     0,
       0,  1242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   863,     0,     0,     0,     0,     0,     0,   864,
    2281,     0,   865,   866,     0,     0,     0,     0,   982,     0,
     952,     0,   867,     0,     0,     0,     0,     0,  2199,   868,
       0,   869,  1592,     0,   870,     0,     0,   953,     0,     0,
       0,     0,     0,     0,  1242,     0,     0,  2340,     0,     0,
       0,     0,     0,     0,  1958,     0,  2341,     0,     0,     0,
       0,     0,     0,  1231,     0,     0,     0,     0,     0,  2342,
       0,     0,     0,     0,     0,     0,   871,     0,     0,     0,
     872,     0,   873,     0,     0,     0,     0,  1593,  1593,     0,
       0,     0,   874,  1242,  1242,  1242,     0,     0,  2367,     0,
       0,  2343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   875,     0,
       0,  2344,     0,  2345,  1593,     0,     0,     0,     0,     0,
       0,   876,     0,     0,     0,     0,     0,     0,     0,   954,
       0,     0,     0,  2199,     0,     0,  2346,     0,     0,     0,
     749,     0,     0,  1242,     0,     0,   877,   878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   879,     0,     0,
       0,     0,     0,     0,     0,     0,  2347,     0,     0,     0,
       0,   880,   881,   955,     0,     0,     0,     0,   882,   956,
       0,   957,   883,     0,   752,     0,   958,   959,   960,     0,
     884,     0,   961,  2348,   753,     0,     0,     0,     0,     0,
     885,     0,     0,     0,     0,     0,     0,     0,     0,   886,
       0,     0,     0,     0,     0,     0,     0,     0,   887,  2349,
       0,     0,     0,   888,   889,     0,  2350,   890,     0,   891,
       0,   962,     0,  1242,     0,   892,     0,     0,     0,  2351,
       0,     0,     0,  2352,  2451,     0,     0,     0,   893,     0,
     963,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   894,     0,  1242,     0,
    1242,     0,   895,     0,   754,     0,     0,   896,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2477,     0,     0,
    1593,     0,  2353,     0,  2480,     0,     0,  2482,  1593,     0,
       0,     0,     0,     0,   897,   964,     0,  1242,     0,  1242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2354,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2355,     0,     0,     0,     0,     0,  2356,     0,     0,
       0,     0,     0,     0,   755,  2512,     0,     0,     0,     0,
       0,     0,     0,     0,   984,     0,   965,   966,     0,  2525,
       0,     0,  1242,     0,     0,     0,     0,     0,  1593,     0,
       0,     0,     0,     0,     0,  1231,  1381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   967,     0,   756,     0,
     968,   969,     0,     0,     0,     0,     0,   846,   970,   847,
       0,   848,     0,     0,     0,     0,   849,     0,     0,     0,
       0,     0,     0,     0,   850,     0,     0,     0,   971,     0,
    2586,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
       0,     0,     0,     0,     0,     0,     0,   851,   852,     0,
       0,     0,     0,     0,     0,  1242,   853,  1242,     0,     0,
     982,   982,     0,     0,     0,     0,     0,   854,     0,     0,
     855,     0,     0,     0,     0,     0,     0,  2633,     0,     0,
       0,     0,     0,     0,   856,     0,   982,     0,  1242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2658,  2661,
       0,     0,     0,     0,     0,   982,     0,   857,     0,     0,
       0,     0,     0,     0,     0,   858,     0,   859,     0,  1242,
       0,     0,     0,     0,  -703,     0,  -703,  -703,  -703,  -703,
    -703,  -703,  -703,  -703,     0,  -703,  -703,  -703,     0,  -703,
    -703,  -703,  -703,  -703,  -703,  -703,  -703,  -703,   860,     0,
       0,     0,     0,  2685,   982,     0,     0,     0,     0,   861,
       0,     0,     0,     0,   862,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   863,     0,     0,     0,     0,     0,  1242,   864,  1242,
       0,   865,   866,     0,     0,     0,     0,     0,     0,     0,
       0,   867,     0,     0,     0,     0,     0,     0,   868,     0,
     869,     0,     0,   870,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   846,
       0,   847,     0,   848,     0,     0,     0,     0,   849,     0,
       0,     0,     0,     0,     0,   871,   850,     0,     0,   872,
       0,   873,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   874,     0,     0,     0,     0,     0,  -703,  -703,     0,
    -703,  -703,  -703,  -703,     0,     0,     0,     0,     0,   851,
     852,     0,     0,     0,     0,     0,     0,   875,   853,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   854,
     876,     0,   855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   856,     0,     0,     0,
       0,     0,     0,     0,     0,   877,   878,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   879,     0,     0,   857,
       0,     0,     0,     0,     0,     0,     0,   858,     0,   859,
     880,   881,     0,     0,     0,     0,     0,   882,     0,     0,
       0,   883,     0,     0,     0,     0,     0,     0,     0,   884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   885,
     860,     0,     0,     0,     0,     0,   984,   984,   886,     0,
       0,   861,     0,     0,     0,     0,   862,   887,     0,     0,
       0,     0,   888,   889,     0,     0,   890,     0,   891,     0,
       0,     0,   984,     0,   892,     0,     0,     0,     0,     0,
       0,     0,     0,   863,     0,     0,     0,  -703,     0,     0,
     864,   984,     0,   865,   866,     0,     0,     0,     0,     0,
       0,     0,     0,   867,     0,   894,     0,     0,   952,     0,
     868,   895,   869,     0,     0,   870,   896,     0,     0,     0,
       0,     0,     0,     0,     0,   953,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -703,     0,     0,
     984,     0,     0,   897,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   871,     0,     0,
     846,   872,   847,   873,   848,     0,     0,     0,     0,   849,
       0,     0,     0,   874,     0,     0,     0,   850,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   875,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     851,   852,   876,     0,     0,     0,  1306,     0,     0,   853,
       0,     0,     0,     0,     0,     0,     0,   954,     0,     0,
     854,     0,     0,   855,     0,     0,     0,   877,   878,     0,
       0,     0,     0,     0,     0,     0,     0,   856,   879,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   880,   881,     0,     0,     0,     0,     0,   882,
     857,     0,     0,   883,     0,     0,     0,     0,   858,     0,
     859,   884,  1307,     0,   958,   959,   960,     0,     0,     0,
     961,   885,     0,     0,     0,     0,     0,     0,     0,     0,
     886,     0,     0,     0,     0,     0,     0,     0,     0,   887,
       0,   860,     0,     0,   888,   889,     0,     0,   890,     0,
     891,     0,   861,     0,     0,     0,   892,   862,     0,   962,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   863,     0,     0,   894,     0,     0,
       0,   864,     0,   895,   865,   866,     0,     0,   896,     0,
       0,     0,     0,     0,   867,     0,     0,     0,     0,     0,
       0,   868,     0,   869,     0,     0,   870,     0,     0,     0,
       0,     0,     0,     0,     0,   897,     0,     0,     0,     0,
       0,     0,     0,   964,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   871,     0,
       0,     0,   872,     0,   873,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   874,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,     0,
       0,     0,     0,  1202,     0, -1838,   747,     0,     0,     0,
     875,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   876,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1126,   877,   878,
       0,     0,     0,     0,     0,     0,   971,     0,     0,   879,
       0,   972,     0,     0,     0, -1126,     0,     0,   973,   243,
     137,     0,     0,   880,   881,     0,     0,     0,     0,   952,
     882,     0,     0,     0,   883,     0,  1021,     0,  1022,     0,
       0,     0,   884,  1023,     0,     0,   953,     0,     0,     0,
       0,  1024,   885,     0,     0,     0,     0,     0,     0,  1352,
       0,   886,     0,     0,     0,     0,     0,     0,     0,     0,
     887,     0,     0,     0,     0,   888,   889,     0,     0,   890,
       0,   891,     0,     0,  1025,  1026,     0,   892,     0,     0,
       0,     0,     0,  1027,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1028,     0,     0,  1029,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   894,     0,
       0,  1030,     0,     0,   895,     0,     0,     0,     0,   896,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1031,     0,     0,     0,   954,     0,
       0,     0,  1032,     0,  1033,     0,   897,     0,     0,   749,
       0,  1034,     0,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1042,     0,  1043,  1044,  1045,  1618,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,     0,     0,     0,     0,
       0,     0,  1204,     0,     0,     0,  1056,     0,   956,     0,
     957,  1057,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1058,     0,
       0,     0,     0,     0,     0,  1059,     0,     0,  1060,  1061,
       0,     0,     0,     0,     0,     0,     0,     0,  1062,     0,
     962,     0,     0,     0,     0,  1063,     0,  1064,     0,     0,
    1065,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,  1202,     0,     0,   747,     0,     0,  1503,  1504,  1505,
       0,     0,     0,     0,     0,  1506,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,  1066,     0,     0,     0,  1067,     0,  1068,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1069,     0,
       0,     0,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1070,     0,     0,   952,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1071,     0,     0,
       0,     0,     0,   755,   953,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,  1072,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1073,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,  1074,     0,
       0,     0,     0,     0,  1075,     0,     0,   970,  1076,     0,
       0,     0,     0,     0,  1507,     0,  1077,     0,     0,     0,
       0,     0,     0,     0,  1508,     0,  1078,   971,     0,     0,
       0,     0,   972,     0,     0,  1079,     0,     0,     0,   973,
       0,   137,     0,     0,  1080,     0,     0,   757,     0,  1081,
    1082,     0,     0,  1083,     0,  1084,   954,     0,     0,     0,
       0,  1085,  1509,  1510,     0,     0,     0,   749,     0,     0,
       0,     0,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1826,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,     0,  1088,     0,
    1204,  1511,  1512,  1089,     0,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,     0,     0,  1205,     0,  1202,     0,
    1090,   747,     0,     0,  1503,  1504,  1505,     0,     0,  1513,
       0,     0,  1506,     0,     0,  1514,     0,     0,  1515,     0,
       0,     0,     0,     0,     0,     0,  1516,     0,   962,     0,
       0,     0,     0,  1517,     0,     0,  1202,     0,  1518,   747,
       0,     0,     0,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1519,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
    1202,     0,     0,   747,  1203,     0,     0,     0,     0,   953,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1507,     0,   965,   966,     0,     0,     0,     0,     0,
       0,  1508,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1520,     0,  1521,     0,  1522,     0,     0,
    1523,     0,  1524,  1525,  1526,   756,     0,  1527,  1528,     0,
       0,     0,     0,   954,     0,   970,   952,     0,     0,  1509,
    1510,     0,     0,     0,   749,     0,     0,     0,  1295,     0,
       0,     0,     0,   953,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,   954,     0,     0,     0,   757,     0,  1204,  1511,  1512,
       0,     0,   749,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
       0,     0,     0,  1205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1204,  1513,     0,     0,     0,
       0,   956,  1514,   957,     0,  1515,   752,     0,   958,   959,
     960,     0,     0,  1516,   961,   962,   753,     0,     0,     0,
    1517,  1205,     0,     0,     0,  1518,  1202,     0,     0,   747,
       0,     0,     0,     0,   963,   954,     0,     0,     0,     0,
       0,     0,     0,     0,  1519,     0,   749,     0,     0,     0,
       0,     0,     0,   962,     0,     0,     0,     0,   754,     0,
       0,     0,  1202,     0,     0,   747,     0,     0,     0,     0,
       0,     0,   963,     0,     0,     0,     0,     0,     0,  1204,
       0,     0,     0,     0,     0,   956,     0,   957,     0,   964,
     752,     0,   958,   959,   960,     0,   754,     0,   961,     0,
     753,     0,   952,     0,     0,  1205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1202,     0,     0,   747,   953,
       0,     0,     0,     0,     0,     0,     0,   964,   755,     0,
       0,     0,  1352,     0,     0,     0,     0,   962,   952,     0,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
    1357,     0,     0,     0,     0,   953,   963,     0,     0,     0,
    1520,     0,  1521,     0,  1522,     0,   755,  1523,     0,  1524,
    1525,  1526,   756,     0,  1527,  1528,     0,     0,   965,   966,
     754,     0,   970,     0,     0,     0,     0,     0,     0,     0,
       0,   952,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   971,     0,     0,     0,     0,   972,   953,     0,
     756,   964,     0,     0,   973,     0,   137,     0,     0,     0,
     970,   954,   757,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   749,     0,     0,     0,     0,     0,     0,     0,
     971,     0,     0,     0,     0,   972,     0,     0,     0,     0,
     755,     0,   973,     0,   137,     0,     0,   954,     0,     0,
     757,     0,   965,   966,     0,  1204,     0,     0,   749,     0,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1205,     0,     0,   756,     0,     0,     0,     0,     0,
       0,  1204,     0,     0,   970,     0,     0,   956,     0,   957,
     954,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,   749,   753,   962,   971,     0,   952,  1205,  -919,   972,
       0,  -919,     0,     0,     0,     0,   973,     0,   137,     0,
       0,     0,   963,   953,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1204,     0,     0,     0,     0,   962,
     956,     0,   957,     0,     0,   752,   754,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,   963,     0,
    1205,  1202,     0,     0,   747,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   964,     0,     0,
       0,     0,   754,     0,  -919,     0,     0,     0,     0,     0,
       0,     0,   962,     0,     0,     0,     0,     0,     0,     0,
       0,  -919,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   963,     0,   964,  1306,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,   954,     0,     0,   965,   966,
       0,     0,     0,     0,     0,   754,     0,   952,     0,  1202,
       0,     0,   747,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   755,     0,   953,     0,     0,     0,     0,     0,
     756,     0,     0,     0,   965,   966,   964,  1477,     0,     0,
     970,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1450,     0,   958,   959,   960,     0,     0,     0,   961,     0,
     971,     0,     0,     0,     0,   972,   756,     0,     0,     0,
       0,     0,   973,  -919,   137,   755,   970,     0,     0,     0,
     757,     0,     0,     0,  -919,   952,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,   971,   962,     0,     0,
       0,   972,   953,     0,     0,  1439,     0,     0,   973,     0,
     137,     0,     0,     0,     0,     0,   757,  -919,     0,   756,
       0,     0,     0,  -919,     0,  -919,   954,     0,  -919,   970,
    -919,  -919,  -919,     0,     0,     0,  -919,   749,  -919,     0,
       0,     0,     0,  -919,     0,     0,     0,     0,     0,   971,
       0,     0,     0,     0,   972,     0,     0,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
    1204,   964,     0,     0,     0,  -919,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,  -919,     0,  1205,     0,     0,  1623,
       0,     0,  1202,     0,   954,   747,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   749,     0,     0,  -919,     0,
       0,     0,   965,   966,     0,     0,     0,     0,   962,     0,
       0,  1202,     0, -1838,   747,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   963,  1204,  -919,
       0,     0,     0,     0,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,   970,     0,     0,   961,     0,   753,
       0,   754,     0,     0,  1205, -1126,     0,     0,   952,     0,
    1202,     0,     0,   747,   971,     0,     0,     0,  -919,   972,
       0,     0,     0, -1126,     0,   953,   973,   243,   137,     0,
    -919,  -919,   964,     0,     0,     0,   962,   952,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   953,   963,     0,     0,     0,     0,
       0,     0,  -919,     0,     0,     0,     0,     0,     0,     0,
       0,   755,  -919,     0,     0,     0,     0,     0,     0,   754,
       0,     0,     0,   965,   966,     0,   952,     0,     0,     0,
       0,     0,  -919,     0,     0,     0,     0,  -919,     0,     0,
       0,     0,     0,   953,  -919,     0,  -919,     0,     0,     0,
     964,     0,  -919,     0,     0,   756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   749,  1481,
       0,     0,     0,     0,     0,   971,     0,     0,     0,   755,
     972,     0,     0,     0,     0,     0,   954,   973,     0,   137,
       0,   965,   966,     0,     0,   757,     0,   749,     0,     0,
       0,  1204,     0,     0,     0,     0,     0,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,   756,     0,     0,     0,  1205,     0,     0,
    1204,     0,     0,   970,     0,   954,   956,     0,   957,     0,
       0,  1246,     0,   958,   959,   960,   749,     0,     0,   961,
       0,   753,     0,   971,     0,     0,  1205,     0,   972,   962,
       0,     0,     0,     0,     0,   973,     0,   137,     0,     0,
       0,     0,     0,   757,     0,     0,     0,     0,   963,  1204,
       0,     0,     0,     0,     0,   956,     0,   957,   962,     0,
     752,     0,   958,   959,   960,     0,     0,     0,   961,     0,
     753,  1749,   754,     0,   747,  1205,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,   964,     0,     0,     0,   962,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   963,     0,     0,     0,
       0,     0,   964,     0,     0,     0,  1915,     0,     0,     0,
       0,     0,   755,     0,     0,     0,     0,   952,     0,     0,
     754,     0,     0,     0,   965,   966,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,     0,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   964,     0,   965,   966,     0,   756,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   756,   971,     0,     0,     0,
     755,   972,     0,     0,     0,   970,     0,     0,   973,     0,
     137,     0,   965,   966,     0,     0,   757,     0,     0,     0,
       0,     0,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,     0,     0,     0,   756,   757,   954,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,   749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   971,     0,     0,     0,     0,   972,
       0,     0,     0,     0,     0,     0,   973,     0,   137,     0,
    1204,     0,     0,     0,   757,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,     0,     0,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   962,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,  1013,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   964,  -352,     0,     0,  -352,     0,     0,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,  -352,     0,     0,
       0,   755,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,   965,   966,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   756,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,   970,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,  -352,     0,     0,     0,   757,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   529,     0,     0,  -352,
    -352,  -352,  -352,  -352,   528,     0,  -352,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,  -352,     0,  -352,
       0,     0,     0,     0,  -352,  -352,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,  -352,
    -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,
       0,     0,     0,  -352,     0,     0,  -352,     0,     0,     0,
       0,     0,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,  -352,     0,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,   529,     0,
       0,  -352,  -352,  -352,  -352,  -352,     0,     0,  -352,  -352,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,  -352,     0,  -352,  -352,
    -352,     0,     0,     0,     0,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,  -352,     0,     0,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,  -352,  -352,
       0,     0,  -352,     0,     0,   530,     0,     0,     0,     0,
    -352,     0,   616,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,   617,     0,     0,
     618,   619,   620,   621,   622,   623,   624,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   625,     0,   626,   627,   628,   629,
     630,   631,   632,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
    -352,  -352,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,  -352,  -352,     0,     0,     0,     0,     0,     0,   634,
     635,   636,   637,   638,  -352,     0,   639,   640,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,   530,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   618,   619,   620,
     621,   622,   623,     0,     0,     0,     0,     0,     0,     0,
     641,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,   642,     0,     0,     0,
       0,   625, -1814,   626,   627,   628,   629,   630,   631,   632,
    1674,     0,     0,  1675,     0,     0,  1676,   618,   619,   620,
     621,   622,   623,  1677,  1678,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,     0,
       0,     0,  1679,     0,  1680,     0,     0,   633,     0,     0,
       0,   625,     0,   626,   627,   628,   629,   630,   631,   632,
       0,     0,     0,     0,     0,     0,   644,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     645,     0,     0,     0,     0,     0,     0,     0,   646,     0,
       0,   647,     0,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,   648,     0,   634,   635,   636,   637,
     638,     0,     0,   639,   640,     0,   649,     0,     0,     0,
       0,     0,     0,     0,   650,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1681,     0,
       0,     0,     0,     0,     0,     0,     0,   641,   952,     0,
       0,     0,     0,     0,     0,     0,   634,   635,   636,   637,
     638,     0,     0,   639,   640,   953,   651,  1682,   652,   653,
     654,     0,     0,     0,  1683,     0,  1684,     0,     0,     0,
       0,     0, -1765,     0,     0,     0,     0,     0,     0,  1685,
       0,     0,     0,     0,     0,   655,     0,   641,     0,     0,
       0,     0,     0,     0,     0,   643,     0,     0,     0,     0,
      94,     0,  -349,   642,     0,     0,     0,     0,     0,     0,
       0,  1686,     0,     0,     0,     0,     0,     0,     0, -1814,
    1687,     0,     0,     0,     0,     0,     0,     0,   656,   657,
     658,     0,     0,  1688,     0,     0,     0,   645,     0,     0,
       0,     0,   659,     0,     0,   643,     0,     0,   647,   660,
       0,     0,     0,     0,     0,     0,     0,   954,     0,     0,
     952,   648,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,     0,  1689,     0,     0,     0,   953,     0,     0,
       0,     0,     0,     0,     0,     0,  1690,   645,     0,     0,
       0,     0,     0,     0,     0,   646,     0,     0,   647,     0,
       0,   955,     0,     0,     0,     0,     0,   956,     0,   957,
       0,   648,   752,  1691,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,   652,   653,   654,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1692,
       0,     0,     0,     0,     0,     0,  1693,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   962,
       0,     0,     0,  1694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   651,     0,   652,   653,   654,   963,   954,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     749,     0,     0,     0,     0,   656,   657,   658,     0,     0,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,   952,     0,     0,  1695,     0,     0,     0,     0,  -606,
       0,     0,     0,   955,  1696,     0,     0,     0,   953,   956,
       0,   957,     0,   964,   752,     0,   958,   959,   960,     0,
       0,  1697,   961,     0,   753,   656,   657,   658,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   659,
       0,     0,     0,     0,     0,  1698,   660,     0,     0,     0,
       0,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,   962,     0,     0,   965,   966,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     963,     0,     0,     0,  1400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   967,   952,   756,     0,   968,   969,
       0,     0,     0,     0,   754,     0,   970,     0,     0,     0,
     954,   952,   953,     0,     0,     0,     0,     0,     0,     0,
       0,   749,     0,     0,     0,     0,   971,     0,   953,     0,
       0,   972,     0,   952,     0,   964,     0,     0,   973,     0,
     137,     0,     0,     0,     0,     0,   757,     0,     0,     0,
     953,     0,     0,     0,   955,     0,     0,     0,     0,     0,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,   755,   753,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1939,     0,     0,     0,
       0,     0,   962,     0,   954,     0,   967,     0,   756,     0,
     968,   969,     0,     0,     0,   749,     0,     0,   970,     0,
     954,   963,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   749,     0,     0,     0,     0,     0,     0,   971,     0,
       0,     0,   954,   972,     0,   754,     0,     0,   955,     0,
     973,     0,   137,   749,   956,     0,   957,     0,   757,   752,
       0,   958,   959,   960,   955,     0,     0,   961,     0,   753,
     956,     0,   957,     0,     0,   752,   964,   958,   959,   960,
       0,     0,     0,   961,     0,   753,   955,     0,     0,     0,
       0,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,   962,   753,     0,     0,
       0,     0,     0,     0,     0,   755,     0,     0,     0,     0,
       0,     0,   962,     0,     0,   963,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   963,     0,     0,   962,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,     0,     0,   967,     0,   756,
       0,   968,   969,   963,     0,   754,     0,     0,     0,   970,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     964,     0,     0,     0,     0,     0,     0,   754,     0,   971,
       0,     0,  2648,     0,   972,     0,   964,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
       0,     0,     0,     0,     0,     0,     0,     0,   964,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   965,   966,     0,     0,   755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,   756,     0,   968,     0,     0,     0,   965,
     966,     0,     0,   970,     0,     0,     0,     0,     0,   756,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,   971,     0,     0,     0,     0,   972,     0,
       0,   756,     0,     0,     0,   973,     0,   137,     0,   971,
       0,   970,     0,   757,   972,     0,     0,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-2362)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   595,   540,   660,   158,   111,   649,
     366,  1101,   103,   684,   105,  1202,   838,   116,   714,   783,
     111,   784,  1124,   776,  1562,   181,  1552,   358,  1417,  1417,
    1104,  1417,   135,   425,  1417,  1417,  1417,  1458,  1507,  1968,
    1568,  1801,   598,   435,   135,  1342,  1110,  1234,   404,  1241,
    1352,  1106,  2002,   209,     6,  1110,     1,    22,  1095,     9,
    1124,  1498,     1,  1160,    17,  1331,  1884,    28,  1227,  1124,
     741,     6,    56,    57,    58,    57,     1,  1174,    55,     9,
      64,   184,    48,    31,     1,  1439,   364,   107,   841,    53,
      86,  1909,  1733,     9,     9,    49,    60,  2037,    87,   697,
     124,    57,  1294,  1099,    31,    96,  1768,    17,    49,   123,
     750,   751,   129,   175,   241,    99,   100,   788,   102,  1093,
     161,   159,   114,   107,   108,    63,   277,  1101,  1102,   176,
     174,   308,   116,    87,  1431,  1661,   141,   203,  1492,  1229,
    1114,  1115,    27,   170,  1502,     9,   152,   225,  1810,   133,
       0,    57,   251,    96,   176,  1347,     0,   176,   798,  1133,
    1134,  1427,   203,   252,   172,   126,   241,    49,   123,   213,
     203,   123,  1964,    64,    32,    66,   160,   188,   165,   176,
    1217,   229,   161,  1541,  1481,   328,  2136,   256,    30,    22,
     330,  1983,  1984,    57,    92,  1987,   295,   161,   225,  1861,
     218,  1956,   203,   256,   968,  1559,   233,   191,  1566,   218,
     262,   783,   357,   369,    57,    32,    21,   256,  1273,   203,
     110,   187,    64,     1,    66,   989,   256,  2508,  1283,   271,
     115,   829,    27,   203,   274,   410,   232,    72,  2030,   124,
    1950,  2602,    21,  2035,   232,   351,   406,   204,   289,   237,
      39,   212,   110,   747,   218,   219,   451,  1919,  1908,   262,
     212,  1122,   450,     0,   256,   249,   451,   232,   367,  1623,
    1113,   459,   451,   257,   199,   232,  1340,  2638,    70,  1545,
      70,  1142,  1125,    61,   287,  1340,  2567,   142,   138,  1344,
     317,  1265,   142,   228,   138,   256,   314,   306,   142,   329,
     389,   476,  1828,   342,   256,   266,   412,   413,   272,   504,
     289,    89,    90,   177,   266,   955,   476,    70,   282,   280,
     115,  1295,   370,   994,   113,  1863,   256,   504,   271,   823,
    1094,  2149,  1634,   385,   340,   376,   171,    70,  1640,    49,
     443,   468,   445,   446,    49,   290,   228,  2009,   388,   452,
     200,   362,  1993,   498,   445,   446,   200,   274,   457,  2151,
     503,   452,  1628,   503,   504,  1834,   469,   312,   357,   472,
     473,   287,   475,   308,  1843,   478,   479,   241,   469,   363,
    1354,   447,   783,  1820,   392,   346,  1823,     9,  1152,  1153,
    1154,   256,   335,   468,   346,   967,   968,   969,   256,   232,
    1754,  1165,  1166,   357,   446,    70,   376,   391,  1172,   125,
     252,  2166,   501,   516,   452,  1773,   357,   989,   402,   497,
     370,    70,  1780,  1497,   309,   516,   204,   411,   412,   462,
     414,   415,   256,   349,   451,   504,   420,   540,   541,   256,
     331,  1112,   504,  1439,  1000,  1001,   451,   353,   237,   540,
     541,   504,    61,   437,   232,   416,   256,   504,   419,   420,
     504,   462,   503,   401,   416,  1439,  1732,   365,   482,   453,
    2120,   388,     6,  1831,   461,     6,   579,   504,  1241,   503,
      89,    90,   504,   503,   504,   504,   341,   504,   579,   331,
     446,   341,  1556,   592,   446,   598,  1492,   341,   504,   465,
     599,  1556,  1539,   499,  1478,  2445,  2446,   504,   460,   498,
    1812,   316,   504,   504,   462,   793,   504,  1491,  1492,   354,
     497,  2076,  1094,   505,  1683,   460,   451,   482,  1886,  2191,
     482,   515,   442,  1570,   451,   462,  2328,   503,   436,   504,
    2332,  1596,  2183,   321,   498,   644,   496,   650,   501,   510,
     534,   441,   504,  1650,   955,  1529,   446,   498,   510,   504,
    1752,   504,  1749,  1559,  1204,   504,   967,   968,   969,  2231,
     554,  2233,   556,  1145,   504,   559,   560,  2105,   562,  2397,
    1152,  1153,  1154,   256,  1347,  1559,  1184,  1853,   989,   504,
     212,    26,   234,  1165,  1166,  1167,  1168,  1169,  1170,  1171,
    1172,   451,  2264,  1175,   468,   589,   398,   451,   398,  2319,
     594,  2371,   576,   402,  2051,   458,   256,   601,   503,   153,
     463,   456,   256,   232,  1890,   256,  1600,  1623,   159,     9,
    1988,   347,  2294,  2295,   256,   256,  1980,  1611,  1612,   504,
     232,  1615,   606,   232,   266,   398,  2004,   357,   453,  1623,
    2442,  2443,   357,  2430,   504,  2065,   448,  2607,   448,   464,
     504,   503,     6,   762,   242,   398,   376,  2025,   767,   772,
     773,   376,   828,   451,   453,   659,  2605,    57,   212,   159,
     504,   212,   781,   786,    30,   464,   402,    56,   229,     6,
    2044,    33,  2046,  1094,    63,   448,  2054,   196,  2253,  2254,
    2058,  1465,  1757,     6,   504,  1468,  1098,     6,  1100,   244,
     510,  1112,   321,   203,   244,   448,   700,  1118,    64,   703,
      66,   308,   256,  1760,   346,   256,   271,  1119,    38,  1121,
    2140,  2085,   266,   398,  1126,   266,    46,   271,  2448,  2097,
     153,   451,   330,   256,  1145,  2047,   451,   446,  1140,   398,
     262,  1152,  1153,  1154,  1155,   397,   308,   256,  1754,  1160,
     421,   196,   257,   200,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,  1172,    57,  1174,  1175,   287,  2486,  2487,    56,   129,
     252,    59,  2251,   448,  2138,    63,    34,    64,   498,    66,
    2452,  2453,  1432,   498,   416,  1859,   256,   177,   497,   448,
    2066,   956,   957,  1204,  1859,  1860,   384,  2584,   963,   458,
     290,    56,   346,   293,   463,   346,  2526,   274,    63,  1459,
    2530,  2531,   256,   410,   546,   167,  1227,   317,  2383,   370,
    2188,   504,   212,   346,   423,  2179,  2194,   271,   460,   122,
    1232,  1604,   451,   445,     0,  2255,  2204,  2300,  2558,  2302,
    2388,  1243,    84,     1,  2151,  1945,   354,  1413,   175,   451,
     462,   241,   584,    11,   504,   341,   418,   406,   212,   329,
     504,   157,  2437,   504,   387,   410,   256,   422,  2144,   424,
     410,   231,   416,   504,   169,   416,   266,   321,   510,   476,
     612,  1655,  1111,  1465,   351,   212,   353,  1000,  1001,   268,
     561,   211,   394,   416,   341,   125,   252,  1578,  1309,   212,
      58,  1010,   256,   212,  1245,   503,  2274,   389,  1137,  2277,
    2278,   452,   266,  1897,  2462,   267,   460,   138,  2493,   460,
     220,   406,  2290,   243,  2036,  2037,   453,   476,   223,   256,
     435,   291,    13,    14,   406,   231,  2304,  2305,    96,   266,
      98,   171,   100,   256,   216,   265,   406,   256,   456,   451,
     108,    32,   252,   266,  2417,  2397,   346,   266,   503,    26,
     504,   340,   452,   504,   236,   252,   510,   177,  2052,   510,
      31,  1553,   138,  2511,   501,   331,   142,    56,  1659,  1752,
     268,   503,  1095,  1324,    63,   776,  1099,   510,   212,   494,
     262,   476,   346,  1106,  1107,  2363,   292,  1110,   318,   504,
    1113,     9,     9,   199,   476,  1118,   164,  1120,  2205,  1122,
    1123,  1124,  1125,   268,   170,   287,   476,   396,  2083,   346,
    2104,   454,   401,   281,   282,   283,   416,   237,  2470,  1142,
     240,    92,   256,   346,   200,  2571,   244,   346,  2044,  2407,
    2046,     1,   266,  2581,   331,     6,   451,  2478,     9,    57,
     841,   351,   340,   187,  1465,  1284,  1221,   195,   378,   359,
     504,   256,   416,   750,   751,  1666,   510,  1233,  1470,   225,
     460,   504,   451,  1655,   256,  2175,   210,   233,   468,  2085,
      40,    41,    42,    43,    44,   340,   344,   306,    49,   416,
     285,   285,   446,   301,  2493,  2493,  1746,  2493,   411,   257,
    2493,  2493,  2493,   416,  1217,   292,   460,   416,   396,  1326,
    2094,   798,  2648,   401,   504,    75,    76,  1283,   256,   338,
     510,    82,   346,  1236,     9,   504,    87,   323,   324,  2665,
    2678,  1360,  2138,   460,   329,   270,  1145,   324,    99,   358,
     334,   396,  1553,   301,   340,   394,   401,   460,  2132,  2133,
     504,   460,   451,   473,   171,   450,   510,   262,   504,  1376,
    1273,   317,   414,   458,   459,    50,  1175,  1578,   463,   356,
    1283,   337,   248,   249,   177,   341,   503,   504,  1485,  1486,
    1487,  1488,   287,   510,   187,  1351,   107,   204,  1951,   268,
     262,   504,   416,   405,   329,   504,   451,   510,   394,   751,
     452,   510,   171,   212,   212,   212,   127,   210,   466,   467,
      96,    97,   481,   471,  1327,   287,   504,  1101,   178,   179,
     180,   181,   182,   183,   184,   185,   186,  1340,   500,   256,
     499,  1344,   390,   241,  2007,   204,  1577,   240,   451,  1650,
     201,   207,   208,  1893,  1655,   166,   798,   256,   256,   256,
    1134,   212,    35,  2237,   411,    38,     8,   266,   266,   266,
     287,   340,    45,    46,   262,  1378,   262,   188,   117,   118,
     119,     2,  1683,     8,   379,   433,     7,  1378,  1644,   451,
     246,   247,     8,   204,   245,    37,   510,  1453,   232,   287,
     251,   287,   253,   451,   448,   256,   423,   258,   259,   260,
    1413,   458,    37,   264,   458,   266,   463,   187,    91,   463,
     271,    37,     6,    53,    54,     9,   394,   396,  2582,  2583,
     212,  2027,   401,   458,    57,   448,  1439,   212,   463,  2010,
     210,   405,  2164,  2445,  2446,   458,  2448,   346,   346,   346,
     463,  2538,   303,   449,  2608,   187,   504,   308,  1949,    89,
     212,  1386,   458,  2003,   232,  1390,  2130,   463,   356,   244,
     245,   322,  1397,  2627,   256,   448,   106,  2373,   210,  2375,
     330,   256,   451,   218,   266,   458,   116,   160,   256,  1492,
     463,   266,   165,   343,  2065,   346,   750,   751,    82,   238,
     106,   216,   217,   451,   256,  1561,   357,  2497,   503,   504,
     116,    16,   453,   252,   266,    99,   189,   416,   416,   416,
    2394,   236,  2676,   464,   451,   458,   377,  1411,    33,  1585,
     463,   451,  1416,  1417,   173,  1419,  1539,    42,   211,   307,
     453,   309,     9,   449,   798,    12,  1597,   262,    15,    16,
     555,   464,   458,  1556,  1610,   560,  1559,   463,   307,   410,
     309,   460,   460,   460,   346,   416,   451,  1570,   152,  2140,
     468,   346,   287,  1865,   351,   161,   353,   428,   429,   165,
    2454,   299,   300,  1191,  2458,  2459,   474,  1195,    54,   351,
    1787,   353,   265,  1596,   346,   473,   335,   475,   451,   455,
     478,   457,  1153,  1154,  1801,   504,   504,   504,   347,   460,
     451,   510,   510,   510,   351,   503,   353,   201,    68,   470,
    1623,   504,   156,    89,   158,   476,  1625,   156,   212,   158,
     252,   783,   254,   252,   416,   254,    24,    25,  1709,   490,
     106,   416,   451,  1646,   495,   318,   504,   498,  1719,  1720,
     116,   502,  1723,   504,   504,  1646,  1167,  1168,  2130,   510,
     252,   245,   254,    65,   416,    67,   967,   251,   969,   253,
     451,   504,   256,   451,   258,   259,   260,    65,   460,    67,
     264,    69,   266,   340,  2255,   460,   256,   271,   256,   468,
    1689,   321,  1169,  1170,  1171,   325,   326,   199,   437,   485,
     486,   487,   488,   504,   442,   378,   400,   410,   460,    12,
     401,  1710,    15,    16,    63,   103,   104,   105,   391,   303,
    2155,  1647,  1648,  1649,  1608,    59,   256,  1653,   510,   232,
    1656,  1657,   451,   328,   401,   510,   366,   256,   322,   485,
     486,   487,   488,   504,   229,    26,     4,  1750,   107,   451,
     451,  1754,   382,   383,  1757,   451,   312,  1760,   510,   256,
     256,    19,   346,   272,   454,   153,    23,   155,   451,   102,
     188,    29,   437,   454,   162,   122,    17,   165,    86,   504,
    1664,  1665,   451,   394,   272,   500,   351,   401,   503,   402,
      56,  1675,   503,   377,  2086,   423,    39,   262,  1682,   451,
     473,   485,   486,   487,   488,    63,   237,  1810,   402,  1865,
     277,   278,   504,   331,   419,   967,   968,   969,   620,   621,
     622,   623,   316,  2079,   506,   504,   310,  1711,   394,  2130,
      11,   261,   416,   451,   301,   302,     7,   989,   255,   451,
     394,   451,   504,   503,   428,   429,   394,  1898,  1899,  1900,
    1901,  1902,  1903,  1904,  1905,   451,  1859,  1860,  1861,   366,
     451,  1917,   451,    85,   252,    85,   254,   394,   124,   453,
    1926,  1927,   451,   389,    22,   309,   460,    58,   306,   451,
     464,    47,   394,   271,   204,  1769,   470,   504,   451,   504,
     499,   384,   232,   501,   446,   218,    62,   504,   254,   122,
     504,   446,   462,   442,  1788,    26,   490,   510,   400,   306,
    1794,   495,   447,   348,   504,    96,  1919,    98,   502,   100,
     504,   410,   445,   451,   462,   442,   510,   108,   256,   504,
     451,   376,   336,   169,   114,   399,   102,   462,   462,   187,
    1092,  1944,  1094,   451,   256,  1097,   504,   462,   462,  1101,
     451,    45,   462,  1944,    35,   446,  1959,    38,   462,   309,
    1112,  1964,   220,   462,    45,    46,  1118,   462,   451,    30,
      64,    65,    66,    67,   277,   278,   462,   783,  1977,   403,
    1983,  1984,   504,   164,  1987,   453,   130,  1139,   196,  1141,
     131,   504,   446,  1145,   252,   132,   386,   133,   301,   302,
    1152,  1153,  1154,  1155,   262,   134,  2009,   135,  1160,   136,
      91,   137,   101,  1165,  1166,  1167,  1168,  1169,  1170,  1171,
    1172,   497,  1174,  1175,   504,   441,   462,  2030,   140,    49,
    2086,   446,  2035,  2036,  2037,   404,   445,  2036,  2037,  2095,
     445,  2044,  2596,  2046,   442,   226,  1930,   439,   143,   196,
     146,  1203,   144,   499,   145,   443,   271,   315,    31,   147,
      49,   148,   320,   149,  1948,   196,   232,   150,   112,   151,
     220,   448,  2563,   239,   448,  1227,   257,  1229,   448,   160,
    2083,   448,  2085,  1967,   250,  1969,   448,   448,   446,  1973,
     114,   451,   410,   351,   312,   109,   197,  1981,   446,   203,
     223,   359,   376,   256,   339,   493,   231,   272,   189,   294,
    2582,  2583,   298,   484,   372,   209,   504,   165,   501,   501,
     301,   128,   175,   304,   446,   365,   168,   129,   228,   446,
     211,    49,   196,   204,    56,  2138,  2608,   299,   228,   204,
     504,   235,   451,   401,   252,   508,   404,   165,  2151,   955,
     272,   423,  2155,   237,   412,  2627,   509,  1309,   252,   299,
     276,   967,   968,   969,  2155,   423,   446,   446,   380,  2461,
     362,   295,    30,   203,   203,    17,   128,   442,   139,  1331,
      49,   365,   446,   989,   265,   351,   352,   203,   369,     8,
     141,   285,   196,   451,  2078,   129,   454,   501,   423,   501,
     366,   451,   368,   203,  2676,  1357,     9,   446,     7,   390,
     504,   305,   503,   256,   294,   203,   503,  2509,   297,    49,
     498,   498,   188,   291,   262,   330,   113,   461,  2231,   314,
    2233,   436,     9,   327,   415,   313,   417,   318,    47,   333,
     203,   411,   294,   203,   361,   102,   361,   380,    49,   262,
     237,   296,   433,   292,   492,    95,    56,     8,  2261,    49,
     110,  2264,   456,   337,   262,   262,   262,   337,   451,   210,
    2261,   109,   481,   451,   107,  1427,   221,   299,   209,   418,
     501,  2582,  2583,   232,   119,   451,   196,   337,  1094,   321,
     367,   285,  2295,  1099,   309,    49,   321,   378,   306,    46,
    1106,     7,    26,    92,  1110,    82,   425,  2608,   201,   127,
     391,   405,  2315,  1465,   148,   206,    75,   221,  1124,   238,
     414,   150,    99,   504,  2315,  2328,  2627,   469,   177,  2332,
     519,  1864,   498,   286,   410,  1009,   773,   431,   497,  1145,
     740,    82,  1417,  2580,  2646,  1857,  1152,  1153,  1154,  1155,
     425,  2153,  1955,  2587,  1160,   788,  2176,   451,    99,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,   841,  1174,  1175,
    2373,  2176,  2375,  1018,    82,  2676,  2049,  1200,   472,  1722,
     779,  1721,  1804,  2357,  1451,  1756,  1217,  2047,  2391,  1453,
    1478,    99,   473,  1545,  1500,  2229,  1497,   491,  1204,  1823,
    2692,  1553,  2051,  2247,   498,   499,  1542,  2074,  1549,  2293,
    1304,  1851,  2086,  1560,  1309,  1877,  2093,  1569,  1590,  1927,
    2107,  1906,  1338,  2133,   201,  1340,  1578,  1125,  1354,  1926,
    1236,  2298,  1926,  2638,  1638,   212,  2397,  1589,  1529,  2442,
    2443,  2303,  2445,  2446,  2126,  2448,  2445,  2446,  2308,  1447,
    2126,  2126,  2336,  1327,  2126,   299,  2340,   152,   691,   270,
     201,  1893,   242,   745,  2385,  2519,  1618,  1273,   509,   417,
    1183,   215,   972,   449,  2063,  1856,  1628,  1283,  1914,   256,
    2584,   258,   259,   260,  1552,   558,   705,   264,    -1,   266,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,  1650,    -1,
      -1,    -1,    -1,  1655,   212,  2508,    -1,    -1,    -1,    -1,
      -1,    -1,  2396,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,  1673,    -1,   264,    -1,  1331,   303,    -1,    -1,    -1,
      -1,  1683,    -1,    -1,  1340,    -1,  2535,    -1,  1344,    -1,
      -1,    -1,    -1,  1695,  2428,  2429,  1698,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
    2444,    -1,   303,    -1,  2567,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,  2460,    -1,    -1,    -1,
    1732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2591,    -1,    -1,   303,  1748,    -1,    -1,  2602,
     377,  2485,    -1,    -1,    -1,  2604,  2490,  2491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1427,    -1,    -1,    -1,    -1,  2510,    -1,    -1,    -1,
      -1,    -1,    -1,  1439,    -1,  2638,   377,    -1,   346,   416,
      -1,    -1,    -1,  2642,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,  2537,    -1,    -1,  2540,  2541,    -1,  1465,
      -1,    -1,    -1,    -1,    -1,    -1,  2669,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2681,   460,    -1,    -1,  1492,   428,   429,    -1,
      -1,    -1,    -1,   470,    -1,  2579,    -1,    -1,    -1,    -1,
      -1,  1853,  1854,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
     428,   429,    -1,    -1,    -1,   502,    -1,   504,    -1,   470,
    1882,    -1,    -1,   510,    -1,    -1,    -1,    -1,  1890,  1545,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1553,    -1,   490,
    1556,    -1,   460,  1559,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,   470,   504,    -1,    -1,  1918,    -1,     1,    -1,
       3,    -1,     5,  1925,  1926,    -1,    -1,    10,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    18,    -1,   495,    -1,    -1,
    1596,    -1,    -1,  1945,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,  1955,  1956,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1623,    51,    52,
      -1,    -1,  1628,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,  1650,    -1,    -1,    -1,    -1,  1655,
      32,    -1,    -1,    35,    -1,    88,    38,    -1,  2010,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2056,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,  2065,  2066,    -1,    -1,    -1,    -1,   152,
      -1,    -1,  2074,    -1,    -1,    -1,  1732,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,  2093,    -1,    -1,  1750,    -1,    -1,    -1,  1754,    -1,
      -1,  1757,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,
    2122,    -1,   205,   206,    -1,    -1,    -1,    -1,  2130,    -1,
      82,    -1,   215,    -1,    -1,    -1,    -1,    -1,  2140,   222,
      -1,   224,  2144,    -1,   227,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,  1810,    -1,    -1,   189,    -1,    -1,
      -1,    -1,    -1,    -1,  2166,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,  2175,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,    -1,  1853,  1854,    -1,
      -1,    -1,   285,  1859,  1860,  1861,    -1,    -1,  2210,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,
      -1,   263,    -1,   265,  1890,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,  2255,    -1,    -1,   288,    -1,    -1,    -1,
     212,    -1,    -1,  1919,    -1,    -1,   349,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,
      -1,   374,   375,   245,    -1,    -1,    -1,    -1,   381,   251,
      -1,   253,   385,    -1,   256,    -1,   258,   259,   260,    -1,
     393,    -1,   264,   345,   266,    -1,    -1,    -1,    -1,    -1,
     403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   371,
      -1,    -1,    -1,   426,   427,    -1,   378,   430,    -1,   432,
      -1,   303,    -1,  2009,    -1,   438,    -1,    -1,    -1,   391,
      -1,    -1,    -1,   395,  2366,    -1,    -1,    -1,   451,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,  2044,    -1,
    2046,    -1,   475,    -1,   346,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2409,    -1,    -1,
    2066,    -1,   444,    -1,  2416,    -1,    -1,  2419,  2074,    -1,
      -1,    -1,    -1,    -1,   507,   377,    -1,  2083,    -1,  2085,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,    -1,    -1,    -1,    -1,   489,    -1,    -1,
      -1,    -1,    -1,    -1,   416,  2467,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2130,    -1,   428,   429,    -1,  2481,
      -1,    -1,  2138,    -1,    -1,    -1,    -1,    -1,  2144,    -1,
      -1,    -1,    -1,    -1,    -1,  2497,   448,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,   460,    -1,
     462,   463,    -1,    -1,    -1,    -1,    -1,     1,   470,     3,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,   490,    -1,
    2542,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,  2231,    60,  2233,    -1,    -1,
    2582,  2583,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,  2599,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,  2608,    -1,  2264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2620,  2621,
      -1,    -1,    -1,    -1,    -1,  2627,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,  2295,
      -1,    -1,    -1,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,  2675,  2676,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,  2373,   202,  2375,
      -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,
     224,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,   269,    18,    -1,    -1,   273,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   285,    -1,    -1,    -1,    -1,    -1,   291,   292,    -1,
     294,   295,   296,   297,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,   311,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
     324,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   349,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
     374,   375,    -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,
     152,    -1,    -1,    -1,    -1,    -1,  2582,  2583,   412,    -1,
      -1,   163,    -1,    -1,    -1,    -1,   168,   421,    -1,    -1,
      -1,    -1,   426,   427,    -1,    -1,   430,    -1,   432,    -1,
      -1,    -1,  2608,    -1,   438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,   451,    -1,    -1,
     202,  2627,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,   469,    -1,    -1,    82,    -1,
     222,   475,   224,    -1,    -1,   227,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,    -1,
    2676,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
       1,   273,     3,   275,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,   285,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,   324,    -1,    -1,    -1,   190,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    -1,   349,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,   360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    -1,   381,
     111,    -1,    -1,   385,    -1,    -1,    -1,    -1,   119,    -1,
     121,   393,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,   403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      -1,   152,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    -1,   163,    -1,    -1,    -1,   438,   168,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,   469,    -1,    -1,
      -1,   202,    -1,   475,   205,   206,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,   224,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,   439,     9,    -1,    -1,    -1,
     311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,   349,   350,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,   360,
      -1,   495,    -1,    -1,    -1,   499,    -1,    -1,   502,   503,
     504,    -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    82,
     381,    -1,    -1,    -1,   385,    -1,     3,    -1,     5,    -1,
      -1,    -1,   393,    10,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    18,   403,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,
      -1,   432,    -1,    -1,    51,    52,    -1,   438,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,
      -1,    88,    -1,    -1,   475,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   119,    -1,   121,    -1,   507,    -1,    -1,   212,
      -1,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,   139,   140,   141,   228,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,   163,    -1,   251,    -1,
     253,   168,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,   205,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,
     303,    -1,    -1,    -1,    -1,   222,    -1,   224,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,   273,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,    -1,   416,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,   375,    -1,
      -1,    -1,    -1,    -1,   381,    -1,    -1,   470,   385,    -1,
      -1,    -1,    -1,    -1,   159,    -1,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,    -1,   403,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,   412,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,   421,    -1,    -1,   510,    -1,   426,
     427,    -1,    -1,   430,    -1,   432,   201,    -1,    -1,    -1,
      -1,   438,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,
      -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,   475,    -1,
     245,   246,   247,   480,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,   271,    -1,     6,    -1,
     507,     9,    -1,    -1,    12,    13,    14,    -1,    -1,   284,
      -1,    -1,    20,    -1,    -1,   290,    -1,    -1,   293,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,   303,    -1,
      -1,    -1,    -1,   308,    -1,    -1,     6,    -1,   313,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,     9,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,    -1,   450,    -1,   452,    -1,    -1,
     455,    -1,   457,   458,   459,   460,    -1,   462,   463,    -1,
      -1,    -1,    -1,   201,    -1,   470,    82,    -1,    -1,   207,
     208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    99,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,   201,    -1,    -1,    -1,   510,    -1,   245,   246,   247,
      -1,    -1,   212,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   284,    -1,    -1,    -1,
      -1,   251,   290,   253,    -1,   293,   256,    -1,   258,   259,
     260,    -1,    -1,   301,   264,   303,   266,    -1,    -1,    -1,
     308,   271,    -1,    -1,    -1,   313,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,   322,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,   377,
     256,    -1,   258,   259,   260,    -1,   346,    -1,   264,    -1,
     266,    -1,    82,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,   416,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,   303,    82,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    99,   322,    -1,    -1,    -1,
     448,    -1,   450,    -1,   452,    -1,   416,   455,    -1,   457,
     458,   459,   460,    -1,   462,   463,    -1,    -1,   428,   429,
     346,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    99,    -1,
     460,   377,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
     470,   201,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
     416,    -1,   502,    -1,   504,    -1,    -1,   201,    -1,    -1,
     510,    -1,   428,   429,    -1,   245,    -1,    -1,   212,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,   470,    -1,    -1,   251,    -1,   253,
     201,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,   212,   266,   303,   490,    -1,    82,   271,     6,   495,
      -1,     9,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,   322,    99,   510,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   303,
     251,    -1,   253,    -1,    -1,   256,   346,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,   322,    -1,
     271,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,
      -1,    -1,   346,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,    -1,   377,   190,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,   346,    -1,    82,    -1,     6,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     460,    -1,    -1,    -1,   428,   429,   377,   165,    -1,    -1,
     470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     490,    -1,    -1,    -1,    -1,   495,   460,    -1,    -1,    -1,
      -1,    -1,   502,   201,   504,   416,   470,    -1,    -1,    -1,
     510,    -1,    -1,    -1,   212,    82,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,   303,    -1,    -1,
      -1,   495,    99,    -1,    -1,   446,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,   245,    -1,   460,
      -1,    -1,    -1,   251,    -1,   253,   201,    -1,   256,   470,
     258,   259,   260,    -1,    -1,    -1,   264,   212,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
     245,   377,    -1,    -1,    -1,   303,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,    -1,   322,    -1,   271,    -1,    -1,   196,
      -1,    -1,     6,    -1,   201,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,   346,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,   303,    -1,
      -1,     6,    -1,   439,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   245,   377,
      -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,   470,    -1,    -1,   264,    -1,   266,
      -1,   346,    -1,    -1,   271,   481,    -1,    -1,    82,    -1,
       6,    -1,    -1,     9,   490,    -1,    -1,    -1,   416,   495,
      -1,    -1,    -1,   499,    -1,    99,   502,   503,   504,    -1,
     428,   429,   377,    -1,    -1,    -1,   303,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   322,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   416,   470,    -1,    -1,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    -1,   428,   429,    -1,    82,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    99,   502,    -1,   504,    -1,    -1,    -1,
     377,    -1,   510,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   484,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,   416,
     495,    -1,    -1,    -1,    -1,    -1,   201,   502,    -1,   504,
      -1,   428,   429,    -1,    -1,   510,    -1,   212,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,   460,    -1,    -1,    -1,   271,    -1,    -1,
     245,    -1,    -1,   470,    -1,   201,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,   212,    -1,    -1,   264,
      -1,   266,    -1,   490,    -1,    -1,   271,    -1,   495,   303,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,   322,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,   303,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,     6,   346,    -1,     9,   271,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,   377,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,   410,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    82,    -1,    -1,
     346,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,   428,   429,    -1,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,   490,    -1,    -1,    -1,
     416,   495,    -1,    -1,    -1,   470,    -1,    -1,   502,    -1,
     504,    -1,   428,   429,    -1,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,   460,   510,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,   212,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,
     245,    -1,    -1,    -1,   510,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    32,    -1,    -1,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,
      -1,   416,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,   160,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,   178,
     179,   180,   181,   182,     1,    -1,   185,   186,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,    -1,    -1,    -1,    21,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    36,
     219,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,   232,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,   345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,    -1,
      -1,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,   405,    -1,   407,   408,
     409,    -1,    -1,    -1,    -1,   232,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,   477,   478,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,
      -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,   497,   498,
      -1,    -1,   319,    -1,    -1,   504,    -1,    -1,    -1,    -1,
     327,    -1,    21,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,   355,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,
     407,   408,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477,   478,   479,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,   181,   182,   491,    -1,   185,   186,    -1,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    73,   241,    75,    76,    77,    78,    79,    80,    81,
      32,    -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,
      -1,    -1,    64,    -1,    66,    -1,    -1,   119,    -1,    -1,
      -1,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,   355,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    99,   405,   189,   407,   408,
     409,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,   434,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,
     232,    -1,   451,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,    -1,    -1,   265,    -1,    -1,    -1,   319,    -1,    -1,
      -1,    -1,   491,    -1,    -1,   277,    -1,    -1,   330,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      82,   343,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,   305,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,   343,   256,   345,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,   407,   408,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   405,    -1,   407,   408,   409,   322,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,   477,   478,   479,    -1,    -1,
      -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,   446,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,   245,   456,    -1,    -1,    -1,    99,   251,
      -1,   253,    -1,   377,   256,    -1,   258,   259,   260,    -1,
      -1,   473,   264,    -1,   266,   477,   478,   479,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,
      -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   458,    82,   460,    -1,   462,   463,
      -1,    -1,    -1,    -1,   346,    -1,   470,    -1,    -1,    -1,
     201,    82,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,   490,    -1,    99,    -1,
      -1,   495,    -1,    82,    -1,   377,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,
      99,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,   416,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,
      -1,    -1,   303,    -1,   201,    -1,   458,    -1,   460,    -1,
     462,   463,    -1,    -1,    -1,   212,    -1,    -1,   470,    -1,
     201,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,    -1,   201,   495,    -1,   346,    -1,    -1,   245,    -1,
     502,    -1,   504,   212,   251,    -1,   253,    -1,   510,   256,
      -1,   258,   259,   260,   245,    -1,    -1,   264,    -1,   266,
     251,    -1,   253,    -1,    -1,   256,   377,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,   303,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,   322,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,    -1,    -1,   303,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,   460,
      -1,   462,   463,   322,    -1,   346,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,   490,
      -1,    -1,   373,    -1,   495,    -1,   377,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,   460,    -1,   462,    -1,    -1,    -1,   428,
     429,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,   460,    -1,    -1,    -1,   502,    -1,   504,    -1,   490,
      -1,   470,    -1,   510,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   513,   514,     0,   200,   341,   515,   516,   517,   518,
     519,   520,   522,   532,   534,   451,   451,   517,   153,   528,
     540,   528,   528,   256,   342,   535,   535,   122,    84,   541,
     521,   523,   532,   138,   526,   527,    26,   536,   536,   451,
     394,   542,   142,   521,   524,   525,   528,   535,   256,   451,
     533,   451,    11,    58,    96,    98,   100,   108,   164,   226,
     257,   301,   304,   369,   390,   415,   417,   433,   504,   543,
     544,   548,   559,   567,   568,   569,   570,   571,   576,   584,
     586,   591,   594,   595,   597,   598,   599,   600,   601,   602,
     603,   535,   523,   451,   232,   537,  1267,   504,  1188,  1188,
     423,   405,  1286,  1267,  1267,  1267,   394,  1188,   405,   451,
     451,  1267,   451,   451,    57,  1256,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1267,  1267,  1267,   504,  1183,  1214,
      68,  1183,   451,  1267,  1267,   549,   560,  1183,   545,   504,
     587,   588,   589,  1189,   256,   307,   309,   573,   575,  1035,
    1217,  1267,   451,   504,   451,   606,   539,   340,  1283,  1267,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1220,
    1183,   256,   218,   306,  1306,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1255,  1316,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1189,  1268,  1035,   232,   423,  1279,  1267,
      96,  1188,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1299,  1214,   400,   401,   410,
      63,  1267,   451,   552,   451,   504,   551,    59,  1267,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1299,   256,
     590,  1218,  1279,   232,  1188,  1188,   574,   575,   451,     1,
     290,   312,  1241,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1220,   328,  1267,   401,  1217,   451,  1267,
     504,  1184,   229,    26,   565,   229,   370,   451,   451,   107,
    1218,  1188,   451,   312,  1188,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1217,   257,   435,
     494,   557,  1184,   256,   272,   608,   454,  1259,    23,  1250,
     102,   648,   451,   582,   583,    57,   505,  1310,   609,   437,
    1292,   188,  1260,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1284,  1300,    86,  1257,   504,  1173,  1174,   451,   394,   650,
     583,   272,  1274,   351,  1284,   446,   497,  1296,   401,   402,
    1267,  1255,   113,   237,  1269,  1269,   287,   635,  1217,  1299,
     423,   262,    39,  1253,  1267,   645,   646,  1174,  1174,   451,
     172,   392,   530,   651,   652,   654,  1267,  1269,   125,   171,
     614,   359,   628,  1267,  1267,  1267,  1267,  1250,     9,   287,
     349,   637,  1267,  1274,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1174,   125,   347,   402,   618,  1267,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1183,  1187,   419,   632,  1183,  1183,   316,  1280,  1280,
     310,  1183,  1267,  1217,   394,   261,   732,   683,   684,   686,
     696,  1233,   451,   653,   632,   256,   616,  1214,   616,     7,
     616,   616,   256,   615,  1214,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1235,  1315,  1259,
    1267,  1182,  1183,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1267,   124,  1182,
    1183,   262,   385,   681,   733,   451,   394,   389,   786,   698,
     689,  1267,  1257,  1267,   351,   353,  1311,  1311,  1267,  1257,
    1267,  1274,  1267,    22,  1249,   306,   678,  1188,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1267,
    1288,    26,   196,   697,  1251,   204,  1217,   504,  1267,  1249,
     504,  1185,  1186,   308,   418,  1307,  1187,  1217,   499,  1267,
     174,   213,   504,   665,  1188,   274,   351,   353,  1309,   681,
     737,   451,   337,   800,   803,   244,   301,   406,   476,  1287,
     476,  1287,   476,  1287,   476,  1287,   476,  1287,   501,  1297,
     384,  1285,  1217,  1211,  1214,  1214,   232,   242,   384,  1270,
    1267,  1268,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1221,
    1222,  1223,   446,   662,  1186,   254,  1273,   446,  1256,   218,
    1262,   504,  1267,  1267,  1309,   738,   787,   122,   826,   827,
     510,   446,   713,   462,  1215,  1216,   442,   706,   727,   728,
    1221,    26,   702,   400,  1245,  1245,  1223,   306,  1277,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1211,   691,   447,  1217,    57,   353,   658,   669,  1217,
     410,  1289,   256,   666,  1214,   666,   348,   739,   686,   696,
     788,   789,   790,    55,   497,   804,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   828,   829,
     844,   849,   853,   858,   873,   876,   880,   884,   885,   886,
     891,   905,   909,   912,   926,   929,   932,   935,   939,   940,
     944,   954,   957,   974,   976,   979,   983,   989,  1001,  1009,
    1010,  1013,  1014,  1018,  1023,  1024,  1032,  1047,  1057,  1066,
    1071,  1078,  1082,  1084,  1087,  1090,  1094,  1119,   828,  1217,
     445,  1294,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1161,  1163,  1164,  1165,  1166,  1167,
    1168,  1196,  1210,  1211,  1222,  1224,  1225,  1226,  1227,   462,
    1216,  1214,   726,   728,   442,   256,  1255,   691,   451,  1223,
      48,   465,   670,   671,   672,   673,  1299,  1256,   196,   661,
    1261,   504,  1175,     1,   687,   790,   451,   806,   805,   376,
     812,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1246,   830,   845,   850,   854,   859,   874,   877,   881,
     887,   892,   906,   910,   913,   927,   930,   933,   936,   941,
     945,   955,   958,   975,   977,   980,   399,   984,   990,  1002,
    1011,  1015,  1019,  1025,  1033,  1048,  1058,   256,   346,   387,
     416,   510,  1070,  1072,  1079,   336,  1083,  1085,   815,  1088,
    1091,  1095,  1120,   114,   714,   462,  1229,  1211,  1222,  1224,
    1306,  1306,   462,   462,   462,   462,  1306,  1167,  1163,  1167,
     462,  1229,    70,   398,   448,  1162,   449,   458,   463,   450,
     459,   169,   462,  1228,   462,   462,  1163,   501,   729,  1298,
    1221,  1187,  1187,   187,   662,  1217,   740,   451,   791,   451,
      49,   807,   808,   809,  1254,   807,   504,   451,   308,   831,
     832,  1210,     6,    94,   245,   271,   846,  1168,  1192,  1193,
    1210,  1221,  1224,   851,  1163,  1210,   256,   855,   856,  1179,
    1180,  1181,  1214,   271,   422,   424,   860,   861,   256,   875,
    1201,  1210,   878,  1174,     6,   882,  1169,  1170,  1191,  1212,
    1213,  1214,  1222,   454,   888,  1174,   256,   893,   894,   896,
    1192,  1193,  1201,  1210,   907,  1193,   256,   911,   453,   464,
     914,   915,   916,  1151,  1152,  1153,   199,   323,   324,   340,
     394,   928,   931,  1190,  1191,   934,  1214,   446,   937,  1295,
    1150,  1151,   946,  1190,   956,  1175,   959,   960,  1210,  1221,
    1224,  1049,  1208,  1209,  1214,    94,   978,  1193,   981,  1193,
     170,   225,   233,   317,   985,   986,   190,   256,   991,   995,
     996,   997,  1179,  1202,  1210,  1214,  1224,  1299,  1003,  1174,
    1012,  1171,  1214,  1016,  1174,  1020,  1171,     9,  1026,  1172,
    1214,   153,   271,  1034,  1037,  1038,  1041,  1042,  1043,  1044,
    1045,  1046,  1176,  1177,  1190,  1207,  1209,  1214,  1049,  1059,
    1174,  1067,   112,  1073,  1074,  1075,  1193,    94,  1080,  1192,
    1086,  1175,   451,   504,   816,   817,   820,   821,   826,  1089,
    1210,  1092,  1174,  1096,  1210,  1121,  1171,   309,  1278,   715,
     716,   448,  1161,  1163,   504,   504,  1163,  1232,  1232,  1232,
    1195,  1210,  1222,  1224,  1231,   504,   448,  1195,  1230,  1163,
     448,  1163,  1164,  1164,  1165,  1165,  1165,  1163,  1195,  1161,
     403,   453,    30,  1252,  1256,     1,   741,   792,   808,   410,
     476,   810,   357,   498,   801,   130,   843,    30,   834,   835,
    1252,   196,  1277,  1210,  1211,  1222,  1224,   131,   848,   446,
     847,  1193,    57,   223,  1236,   856,   446,  1306,   132,   872,
     256,  1202,  1201,  1174,   356,   474,   879,  1299,  1312,  1277,
     133,   883,   159,   452,  1170,  1303,   386,  1242,  1215,  1216,
     889,  1174,   134,   890,  1284,   135,   904,   165,   895,  1130,
    1131,   484,   897,   503,   835,   485,   486,   487,   488,   136,
     908,    49,   228,   497,   862,   137,   925,    17,   501,   917,
     918,   919,   921,    12,    13,    14,    20,   159,   169,   207,
     208,   246,   247,   284,   290,   293,   301,   308,   313,   332,
     448,   450,   452,   455,   457,   458,   459,   462,   463,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1193,   101,  1191,  1178,
     441,  1293,   947,  1299,  1175,    92,   365,   436,   961,   962,
     964,   965,  1051,   462,  1215,  1193,   446,   140,   982,    49,
     986,   404,   987,   996,   141,   451,   992,   994,   481,   499,
     442,   445,   439,   143,  1008,   285,   334,  1239,   196,  1122,
     144,  1017,  1284,   145,  1022,  1122,  1172,   146,  1031,   499,
    1027,  1199,  1210,  1222,  1044,  1046,  1190,   446,  1177,   123,
     446,   482,  1036,    31,  1215,   147,  1065,   177,   237,   240,
    1061,   203,   376,  1068,  1299,  1254,   148,  1077,   228,  1075,
    1210,   149,  1081,   196,  1175,   394,   451,   451,   196,   351,
     353,  1093,   150,  1105,   112,  1097,   151,  1126,  1122,  1183,
     220,   718,    27,   115,   717,   448,  1162,   448,   448,   448,
    1162,   448,  1162,   448,   448,   449,   448,   448,   446,  1267,
    1187,   114,   660,   451,    61,    89,    90,   321,   451,   742,
     743,   748,  1267,  1324,    32,    35,    38,    45,    46,    64,
      66,   160,   189,   196,   198,   211,   243,   252,   265,   305,
     318,   345,   371,   378,   395,   446,   456,   473,   497,   704,
     705,   709,   721,   723,   725,   793,   798,   799,  1267,  1301,
    1267,   410,   312,   811,   109,   813,  1199,   197,   838,   252,
     331,   836,   837,  1301,    24,    25,    65,    67,    69,   103,
     104,   105,   153,   155,   162,   165,   252,   254,   443,   493,
     504,   833,  1177,  1302,   152,   340,  1197,  1211,   446,     6,
    1169,  1193,  1214,  1222,   203,   223,  1237,   376,   852,   339,
     857,  1181,   862,   879,   262,   287,  1260,  1211,  1163,   272,
    1243,  1216,  1174,   231,  1146,  1147,   823,   824,   896,  1193,
     294,  1132,    96,   335,   504,  1177,   298,   901,    35,    38,
      45,    46,    91,   160,   189,   211,   265,   318,   378,   391,
     473,   902,   903,   484,   898,  1130,  1130,  1130,  1130,  1193,
    1169,  1193,   863,   916,    21,   453,   464,   922,   923,  1152,
     501,   919,   920,   501,   823,  1295,   232,  1155,   114,   938,
    1179,   128,   823,   942,     9,    12,    15,    16,   277,   278,
     301,   302,   948,   952,   175,  1199,     9,    57,   177,   241,
     468,   968,   969,   970,   963,   964,  1053,  1278,  1315,   446,
    1190,  1169,  1193,   987,  1299,  1173,   823,   168,   998,  1150,
     999,  1000,  1210,  1179,     8,    37,  1124,  1284,  1206,  1210,
    1221,  1224,   228,  1004,  1021,  1299,   129,  1028,  1210,  1028,
     446,   446,  1035,   152,   453,   464,  1193,    49,    38,    46,
     211,   243,   265,   318,   378,   473,  1039,  1040,  1267,  1060,
    1299,  1193,  1193,   161,   289,   410,  1193,  1210,   196,  1169,
    1193,   822,  1217,  1199,  1254,   228,  1100,  1123,  1124,  1254,
    1269,  1183,  1228,  1228,  1228,  1195,   241,   468,  1228,   448,
    1163,  1228,  1228,  1221,  1278,  1267,  1267,  1249,   248,   249,
    1272,   757,   204,   176,   744,   745,   746,   747,  1210,  1267,
     252,   389,   156,   158,  1267,  1202,   299,  1275,  1217,    56,
    1210,  1210,   204,  1275,    32,   110,  1217,  1267,   504,   451,
     802,   272,   839,  1275,  1275,   837,   836,  1275,   165,  1127,
    1128,   509,   508,  1199,  1127,   237,   423,   299,   276,   256,
    1198,  1211,  1210,  1277,   411,  1133,  1134,  1215,  1216,  1169,
     446,  1238,   852,  1191,   446,  1179,   203,   376,   867,   868,
     380,   362,  1133,  1267,   823,   295,  1148,   825,   823,  1130,
    1267,   252,   389,   156,   158,  1267,   123,   482,   903,  1130,
      96,    97,   899,   839,   203,  1133,   203,   864,   865,   866,
    1254,    17,   442,   924,   316,   922,  1278,   823,   128,   139,
     943,  1295,   365,   949,  1295,   446,    49,   969,   971,  1199,
       9,    57,   241,   468,   966,   967,  1199,  1054,  1300,   717,
     218,   314,  1263,  1190,  1133,   203,  1173,   637,   379,   988,
    1299,   141,   993,     8,   196,  1004,  1210,   129,  1139,  1141,
    1146,   262,   287,   823,   501,   501,  1029,  1030,  1199,  1198,
    1193,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1040,
     290,   293,  1062,  1063,  1064,  1156,  1240,  1146,   244,   410,
    1314,   423,  1291,  1291,  1076,  1299,  1210,  1133,   203,   451,
     446,     9,  1098,  1099,  1234,  1101,  1210,  1076,  1101,  1021,
       7,  1247,   504,   719,   720,  1267,   448,  1183,  1201,  1267,
    1249,   256,   749,  1219,   686,   758,   746,   747,   510,  1203,
    1207,  1217,  1203,  1267,  1294,  1267,  1267,    32,  1217,   814,
     815,  1267,   503,   840,  1203,  1203,  1203,   823,   294,  1129,
    1127,  1242,  1211,   823,   297,  1135,  1216,  1133,  1200,  1210,
    1221,   165,   461,   870,  1305,     6,   228,   308,   460,   869,
    1266,    34,   281,   282,   283,   344,   466,   467,   471,  1244,
     823,   826,  1203,  1203,  1149,  1205,  1207,  1217,  1149,   503,
     900,  1169,  1170,  1169,  1170,   865,   308,   810,    87,   357,
     498,   923,  1151,   823,  1210,   823,   498,   950,   951,   952,
     953,  1293,   498,  1200,  1199,    49,   972,   967,   188,   972,
    1050,  1267,  1269,   314,  1169,   988,   262,   287,  1000,  1193,
     217,  1005,  1299,   823,   291,  1142,   262,  1151,  1150,  1029,
    1156,  1210,  1157,  1158,  1159,  1160,  1163,  1069,  1193,  1069,
     461,  1136,  1137,   330,  1242,  1169,   818,  1200,   313,  1199,
     113,  1102,   436,  1104,   157,   292,  1125,  1143,  1144,  1145,
    1146,   321,  1177,  1203,   720,  1182,   750,   252,   254,  1308,
     504,   687,   270,   329,   458,   463,   794,   795,   796,  1201,
     794,   795,   797,   815,    47,    32,    35,    38,    46,    91,
     189,   198,   211,   243,   263,   265,   288,   318,   345,   371,
     378,   391,   395,   444,   473,   483,   489,   841,   842,  1127,
     823,  1133,   823,   294,   871,   823,  1277,  1210,   252,   254,
    1313,   902,  1133,   361,  1133,   361,  1193,   951,   102,  1258,
    1295,   972,   972,  1200,     8,    37,   973,   225,   497,  1055,
    1183,  1052,  1133,   380,    49,   262,   237,  1006,   216,   236,
     262,   287,   500,   823,   823,   823,   823,   296,  1138,  1267,
    1133,  1133,   492,   819,  1106,  1099,  1262,    95,  1103,  1262,
    1136,   823,   823,  1145,   252,   254,  1271,   177,   187,   210,
     240,   751,   752,   753,   754,   755,   756,  1219,   759,  1203,
    1203,   129,  1267,  1267,    56,   123,   482,     8,  1248,   842,
     823,  1210,  1170,  1170,    49,   110,   972,   456,  1265,  1265,
     337,  1173,   203,   317,  1056,  1214,  1193,  1267,  1007,  1140,
    1141,  1142,  1146,   262,   262,   262,   823,  1210,  1107,   451,
    1210,  1262,  1210,   106,   116,  1317,  1267,  1267,    54,    89,
    1317,  1318,  1302,   760,   109,  1203,  1203,  1267,  1149,  1149,
    1204,  1207,  1219,  1133,  1133,  1193,  1193,  1193,  1267,  1173,
     337,   481,  1210,  1142,   127,   166,   204,  1108,  1109,  1110,
    1112,  1116,  1117,  1118,  1260,  1210,  1267,  1219,  1219,   210,
    1267,  1267,   209,   252,   285,   305,   333,   414,   431,   451,
     472,   491,   499,   704,   709,   710,   721,   723,   725,   761,
     762,   766,   769,   772,   773,   774,   775,   780,   781,   783,
     784,   785,  1301,  1302,   451,  1201,   995,  1267,  1150,    37,
    1248,   107,  1219,  1219,  1219,   221,  1264,   299,   777,   209,
    1217,   501,  1267,  1277,  1267,  1267,  1210,   329,   776,   778,
    1219,   329,   782,  1219,   299,   300,  1276,  1249,   995,   367,
     418,  1290,  1278,   232,  1267,   713,  1150,  1196,  1194,  1196,
      53,    89,   321,   325,   326,   366,   382,   383,   763,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,   119,   196,   778,   309,
     779,  1217,  1268,  1210,   161,   165,  1304,     9,  1113,  1114,
    1180,   285,   329,   767,   768,  1217,  1294,  1242,   373,   770,
    1196,   187,   187,   210,   187,   210,   176,   764,  1210,   176,
     765,  1210,  1196,   285,   337,  1282,   306,   338,   358,  1115,
    1114,  1217,   321,  1281,   714,  1278,    49,   321,  1278,   306,
    1214,   425,   711,   176,   771,  1210,  1196,   170,   225,   233,
     317,  1111,  1173,  1217
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YYLVAL_INITIALIZE
# define YYLVAL_INITIALIZE()
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  YYLVAL_INITIALIZE ();
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1813 of yacc.c  */
#line 1343 "parser.y"
    {
	clear_initial_values ();
	current_program = NULL;
	cobc_cs_check = 0;
	prog_end = 0;
	depth = 0;
	main_flag_set = 0;
	current_program = cb_build_program (NULL, 0);
	cb_build_registers ();
  }
    break;

  case 3:
/* Line 1813 of yacc.c  */
#line 1354 "parser.y"
    {
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
	if (depth > 1) {
		cb_error (_("Multiple PROGRAM-ID's without matching END PROGRAM"));
	}
	if (cobc_flag_main && !main_flag_set) {
		cb_error (_("Executable requested but no program found"));
	}
	if (errorcount > 0) {
		YYABORT;
	}
	if (!current_program->entry_list) {
		emit_entry (current_program->program_id, 0, NULL);
	}
  }
    break;

  case 10:
/* Line 1813 of yacc.c  */
#line 1390 "parser.y"
    {
	cb_tree		l;

	current_section = NULL;
	current_paragraph = NULL;
	prog_end = 1;
	if (increment_depth ()) {
		YYABORT;
	}
	l = cb_build_alphanumeric_literal (demangle_name,
					   strlen (demangle_name));
	current_program->program_id = cb_build_program_id (l, NULL, 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if (!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = cobc_flag_main;
	}
	check_relaxed_syntax (COBC_HD_PROGRAM_ID);
  }
    break;

  case 20:
/* Line 1813 of yacc.c  */
#line 1445 "parser.y"
    {
	char	*s;

	if (CB_LITERAL_P ((yyvsp[(2) - (3)]))) {
		s = (char *)(CB_LITERAL ((yyvsp[(2) - (3)]))->data);
	} else {
		s = (char *)(CB_NAME ((yyvsp[(2) - (3)])));
	}
	if (depth) {
		depth--;
	}
	if (strcmp (stack_progid[depth], s)) {
		cb_error (_("END PROGRAM '%s' is different to PROGRAM-ID '%s'"),
			s, stack_progid[depth]);
	}
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
  }
    break;

  case 23:
/* Line 1813 of yacc.c  */
#line 1474 "parser.y"
    {
	char	*s;

	if (CB_LITERAL_P ((yyvsp[(2) - (3)]))) {
		s = (char *)(CB_LITERAL ((yyvsp[(2) - (3)]))->data);
	} else {
		s = (char *)(CB_NAME ((yyvsp[(2) - (3)])));
	}
	if (depth) {
		depth--;
	}
	if (strcmp (stack_progid[depth], s)) {
		cb_error (_("END FUNCTION '%s' is different to FUNCTION-ID '%s'"),
			s, stack_progid[depth]);
	}
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
  }
    break;

  case 24:
/* Line 1813 of yacc.c  */
#line 1507 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:
/* Line 1813 of yacc.c  */
#line 1513 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:
/* Line 1813 of yacc.c  */
#line 1525 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:
/* Line 1813 of yacc.c  */
#line 1535 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	if (CB_LITERAL_P ((yyvsp[(3) - (4)]))) {
		stack_progid[depth] = (char *)(CB_LITERAL ((yyvsp[(3) - (4)]))->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME ((yyvsp[(3) - (4)])));
	}
	if (prog_end) {
		if (!current_program->flag_validated) {
			current_program->flag_validated = 1;
			cb_validate_program_body (current_program);
		}
		clear_initial_values ();
		current_program = cb_build_program (current_program, depth);
		build_nested_special (depth);
		cb_build_registers ();
	} else {
		prog_end = 1;
	}
	if (increment_depth ()) {
		YYABORT;
	}
	current_program->program_id = cb_build_program_id ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]), 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if (!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = !!cobc_flag_main;
	}
  }
    break;

  case 29:
/* Line 1813 of yacc.c  */
#line 1566 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:
/* Line 1813 of yacc.c  */
#line 1573 "parser.y"
    {
#if	0	/* RXWRXW - FUNCTION-ID */
	cb_error (_("FUNCTION-ID is not yet implemented"));
#endif
	current_section = NULL;
	current_paragraph = NULL;
	if (CB_LITERAL_P ((yyvsp[(3) - (5)]))) {
		stack_progid[depth] = (char *)(CB_LITERAL ((yyvsp[(3) - (5)]))->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME ((yyvsp[(3) - (5)])));
	}
	if (prog_end) {
		if (!current_program->flag_validated) {
			current_program->flag_validated = 1;
			cb_validate_program_body (current_program);
		}
		clear_initial_values ();
		current_program = cb_build_program (current_program, depth);
		build_nested_special (depth);
		cb_build_registers ();
	} else {
		prog_end = 1;
	}
	if (increment_depth ()) {
		YYABORT;
	}
	current_program->program_id = cb_build_program_id ((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), 1);
	current_program->prog_type = CB_FUNCTION_TYPE;
	current_program->flag_recursive = 1;
	cobc_cs_check = 0;
  }
    break;

  case 33:
/* Line 1813 of yacc.c  */
#line 1612 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:
/* Line 1813 of yacc.c  */
#line 1613 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:
/* Line 1813 of yacc.c  */
#line 1622 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  }
    break;

  case 38:
/* Line 1813 of yacc.c  */
#line 1631 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  }
    break;

  case 41:
/* Line 1813 of yacc.c  */
#line 1645 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:
/* Line 1813 of yacc.c  */
#line 1649 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:
/* Line 1813 of yacc.c  */
#line 1659 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:
/* Line 1813 of yacc.c  */
#line 1668 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if (current_program->nested_level) {
		cb_error (_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  }
    break;

  case 54:
/* Line 1813 of yacc.c  */
#line 1693 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("SOURCE-COMPUTER", SYN_CLAUSE_1);
	if (warningopt && (check_comp_duplicate & SYN_CLAUSE_2)) {
		cb_warning (_("Phrases in non-standard order"));
	}
  }
    break;

  case 59:
/* Line 1813 of yacc.c  */
#line 1711 "parser.y"
    {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item ();
  }
    break;

  case 60:
/* Line 1813 of yacc.c  */
#line 1724 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:
/* Line 1813 of yacc.c  */
#line 1753 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:
/* Line 1813 of yacc.c  */
#line 1760 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:
/* Line 1813 of yacc.c  */
#line 1767 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:
/* Line 1813 of yacc.c  */
#line 1774 "parser.y"
    {
	if (current_program->classification) {
		cb_error (_("Duplicate CLASSIFICATION clause"));
	} else {
		current_program->classification = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 76:
/* Line 1813 of yacc.c  */
#line 1785 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:
/* Line 1813 of yacc.c  */
#line 1789 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:
/* Line 1813 of yacc.c  */
#line 1793 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:
/* Line 1813 of yacc.c  */
#line 1797 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:
/* Line 1813 of yacc.c  */
#line 1811 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:
/* Line 1813 of yacc.c  */
#line 1816 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:
/* Line 1813 of yacc.c  */
#line 1824 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:
/* Line 1813 of yacc.c  */
#line 1836 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:
/* Line 1813 of yacc.c  */
#line 1840 "parser.y"
    {
	cb_tree		x;

	if ((yyvsp[(3) - (3)])) {
		x = (yyvsp[(3) - (3)]);
	} else {
		x = (yyvsp[(2) - (3)]);
	}
	current_program->user_spec_list =
		cb_list_add (current_program->user_spec_list, x);
  }
    break;

  case 94:
/* Line 1813 of yacc.c  */
#line 1861 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:
/* Line 1813 of yacc.c  */
#line 1865 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:
/* Line 1813 of yacc.c  */
#line 1872 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:
/* Line 1813 of yacc.c  */
#line 1877 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:
/* Line 1813 of yacc.c  */
#line 1888 "parser.y"
    {
	check_duplicate = 0;
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	header_check |= COBC_HD_SPECIAL_NAMES;
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	}
  }
    break;

  case 100:
/* Line 1813 of yacc.c  */
#line 1902 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:
/* Line 1813 of yacc.c  */
#line 1933 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		save_tree = NULL;
	} else {
		save_tree = lookup_system_name (CB_NAME ((yyvsp[(1) - (1)])));
		if (!save_tree) {
			cb_error_x ((yyvsp[(1) - (1)]), _("Invalid system-name '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
		}
	}
  }
    break;

  case 117:
/* Line 1813 of yacc.c  */
#line 1952 "parser.y"
    {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_DEVICE_CONSOLE) {
			cb_error_x (save_tree, _("Invalid CRT clause"));
		} else {
			current_program->flag_console_is_crt = 1;
		}
	}
  }
    break;

  case 118:
/* Line 1813 of yacc.c  */
#line 1962 "parser.y"
    {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_FEATURE_CONVENTION) {
			cb_error_x (save_tree, _("Invalid special names clause"));
		} else if (CB_VALID_TREE ((yyvsp[(3) - (3)]))) {
			CB_SYSTEM_NAME(save_tree)->value = (yyvsp[(1) - (3)]);
			cb_define ((yyvsp[(3) - (3)]), save_tree);
			CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
					(yyvsp[(3) - (3)]), save_tree);
		}
	}
  }
    break;

  case 119:
/* Line 1813 of yacc.c  */
#line 1975 "parser.y"
    {
	if (save_tree && CB_VALID_TREE ((yyvsp[(2) - (3)]))) {
		cb_define ((yyvsp[(2) - (3)]), save_tree);
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
				(yyvsp[(2) - (3)]), save_tree);
	}
  }
    break;

  case 123:
/* Line 1813 of yacc.c  */
#line 1991 "parser.y"
    {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ((yyvsp[(3) - (3)]), save_tree, (yyvsp[(1) - (3)]) == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, (yyvsp[(3) - (3)]), x);
	}
  }
    break;

  case 124:
/* Line 1813 of yacc.c  */
#line 2001 "parser.y"
    {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ((yyvsp[(4) - (4)]), save_tree, (yyvsp[(2) - (4)]) == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, (yyvsp[(4) - (4)]), x);
	}
  }
    break;

  case 125:
/* Line 1813 of yacc.c  */
#line 2016 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		(yyval) = NULL;
	} else {
		/* Returns null on error */
		(yyval) = cb_build_alphabet_name ((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 126:
/* Line 1813 of yacc.c  */
#line 2029 "parser.y"
    {
	if ((yyvsp[(3) - (5)])) {
		current_program->alphabet_name_list =
			cb_list_add (current_program->alphabet_name_list, (yyvsp[(3) - (5)]));
	}
	cobc_cs_check = 0;
  }
    break;

  case 127:
/* Line 1813 of yacc.c  */
#line 2040 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:
/* Line 1813 of yacc.c  */
#line 2046 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:
/* Line 1813 of yacc.c  */
#line 2052 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:
/* Line 1813 of yacc.c  */
#line 2058 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:
/* Line 1813 of yacc.c  */
#line 2064 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:
/* Line 1813 of yacc.c  */
#line 2070 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:
/* Line 1813 of yacc.c  */
#line 2080 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:
/* Line 1813 of yacc.c  */
#line 2084 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:
/* Line 1813 of yacc.c  */
#line 2091 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:
/* Line 1813 of yacc.c  */
#line 2095 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:
/* Line 1813 of yacc.c  */
#line 2099 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:
/* Line 1813 of yacc.c  */
#line 2103 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:
/* Line 1813 of yacc.c  */
#line 2110 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:
/* Line 1813 of yacc.c  */
#line 2114 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:
/* Line 1813 of yacc.c  */
#line 2120 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:
/* Line 1813 of yacc.c  */
#line 2121 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:
/* Line 1813 of yacc.c  */
#line 2122 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:
/* Line 1813 of yacc.c  */
#line 2123 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:
/* Line 1813 of yacc.c  */
#line 2124 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:
/* Line 1813 of yacc.c  */
#line 2125 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:
/* Line 1813 of yacc.c  */
#line 2133 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else if ((yyvsp[(1) - (2)])) {
		CB_CHAIN_PAIR (current_program->symbolic_char_list, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 148:
/* Line 1813 of yacc.c  */
#line 2147 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:
/* Line 1813 of yacc.c  */
#line 2151 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:
/* Line 1813 of yacc.c  */
#line 2159 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:
/* Line 1813 of yacc.c  */
#line 2166 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:
/* Line 1813 of yacc.c  */
#line 2170 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  }
    break;

  case 153:
/* Line 1813 of yacc.c  */
#line 2181 "parser.y"
    {
	cb_tree		l1;
	cb_tree		l2;

	if (cb_list_length ((yyvsp[(1) - (3)])) != cb_list_length ((yyvsp[(3) - (3)]))) {
		cb_error (_("Invalid SYMBOLIC clause"));
		(yyval) = NULL;
	} else {
		l1 = (yyvsp[(1) - (3)]);
		l2 = (yyvsp[(3) - (3)]);
		for (; l1; l1 = CB_CHAIN (l1), l2 = CB_CHAIN (l2)) {
			CB_PURPOSE (l1) = CB_VALUE (l2);
		}
		(yyval) = (yyvsp[(1) - (3)]);
	}
  }
    break;

  case 154:
/* Line 1813 of yacc.c  */
#line 2201 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 155:
/* Line 1813 of yacc.c  */
#line 2209 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 156:
/* Line 1813 of yacc.c  */
#line 2219 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 157:
/* Line 1813 of yacc.c  */
#line 2220 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:
/* Line 1813 of yacc.c  */
#line 2227 "parser.y"
    {
	cb_tree		x;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		x = cb_build_class_name ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		if (x) {
			current_program->class_name_list =
				cb_list_add (current_program->class_name_list, x);
		}
	}
  }
    break;

  case 159:
/* Line 1813 of yacc.c  */
#line 2247 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 160:
/* Line 1813 of yacc.c  */
#line 2248 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:
/* Line 1813 of yacc.c  */
#line 2253 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:
/* Line 1813 of yacc.c  */
#line 2257 "parser.y"
    {
	if (CB_TREE_CLASS ((yyvsp[(1) - (3)])) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P ((yyvsp[(1) - (3)])) && CB_LITERAL ((yyvsp[(1) - (3)]))->size != 1) {
		cb_error (_("CLASS literal with THRU must have size 1"));
	}
	if (CB_TREE_CLASS ((yyvsp[(3) - (3)])) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P ((yyvsp[(3) - (3)])) && CB_LITERAL ((yyvsp[(3) - (3)]))->size != 1) {
		cb_error (_("CLASS literal with THRU must have size 1"));
	}
	if (literal_value ((yyvsp[(1) - (3)])) <= literal_value ((yyvsp[(3) - (3)]))) {
		(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	} else {
		(yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
	}
  }
    break;

  case 163:
/* Line 1813 of yacc.c  */
#line 2278 "parser.y"
    {
	cb_tree	l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		l = cb_build_locale_name ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		if (l) {
			current_program->locale_list =
				cb_list_add (current_program->locale_list, l);
		}
	}
  }
    break;

  case 164:
/* Line 1813 of yacc.c  */
#line 2301 "parser.y"
    {
	unsigned char	*s = CB_LITERAL ((yyvsp[(4) - (5)]))->data;
	unsigned int	error_ind = 0;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		error_ind = 1;
	}
	check_repeated ("CURRENCY", SYN_CLAUSE_1);
	if ((yyvsp[(5) - (5)])) {
		PENDING ("PICTURE SYMBOL");
	}
	if (CB_LITERAL ((yyvsp[(4) - (5)]))->size != 1) {
		cb_error_x ((yyvsp[(4) - (5)]), _("Invalid currency sign '%s'"), (char *)s);
		error_ind = 1;
	}
	switch (*s) {
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
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'N':
	case 'P':
	case 'R':
	case 'S':
	case 'V':
	case 'X':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'n':
	case 'p':
	case 'r':
	case 's':
	case 'v':
	case 'x':
	case 'z':
	case '+':
	case '-':
	case ',':
	case '.':
	case '*':
	case '/':
	case ';':
	case '(':
	case ')':
	case '=':
	case '\'':
	case '"':
	case ' ':
		cb_error_x ((yyvsp[(4) - (5)]), _("Invalid currency sign '%s'"), (char *)s);
		break;
	default:
		if (!error_ind) {
			current_program->currency_symbol = s[0];
		}
		break;
	}
  }
    break;

  case 165:
/* Line 1813 of yacc.c  */
#line 2382 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:
/* Line 1813 of yacc.c  */
#line 2386 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:
/* Line 1813 of yacc.c  */
#line 2395 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("DECIMAL-POINT", SYN_CLAUSE_2);
		current_program->decimal_point = ',';
		current_program->numeric_separator = '.';
	}
  }
    break;

  case 168:
/* Line 1813 of yacc.c  */
#line 2414 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		current_program->flag_trailing_separate = 1;
	}
  }
    break;

  case 169:
/* Line 1813 of yacc.c  */
#line 2430 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("CURSOR", SYN_CLAUSE_3);
		current_program->cursor_pos = (yyvsp[(3) - (3)]);
	}
  }
    break;

  case 170:
/* Line 1813 of yacc.c  */
#line 2448 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("CRT STATUS", SYN_CLAUSE_4);
		current_program->crt_status = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 171:
/* Line 1813 of yacc.c  */
#line 2466 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("SCREEN CONTROL", SYN_CLAUSE_5);
		PENDING ("SCREEN CONTROL");
	}
  }
    break;

  case 172:
/* Line 1813 of yacc.c  */
#line 2483 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("EVENT STATUS", SYN_CLAUSE_6);
		PENDING ("EVENT STATUS");
	}
  }
    break;

  case 174:
/* Line 1813 of yacc.c  */
#line 2500 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:
/* Line 1813 of yacc.c  */
#line 2508 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:
/* Line 1813 of yacc.c  */
#line 2518 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:
/* Line 1813 of yacc.c  */
#line 2534 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       COBC_HD_FILE_CONTROL, 0);
	check_duplicate = 0;
	if (CB_INVALID_TREE ((yyvsp[(3) - (3)]))) {
		YYERROR;
	}

	/* Build new file */
	current_file = build_file ((yyvsp[(3) - (3)]));
	current_file->optional = CB_INTEGER ((yyvsp[(2) - (3)]))->val;

	/* Add file to current program list */
	CB_ADD_TO_CHAIN (CB_TREE (current_file), current_program->file_list);
  }
    break;

  case 182:
/* Line 1813 of yacc.c  */
#line 2551 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:
/* Line 1813 of yacc.c  */
#line 2555 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  }
    break;

  case 199:
/* Line 1813 of yacc.c  */
#line 2589 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:
/* Line 1813 of yacc.c  */
#line 2595 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_fileid = 1;
	}
  }
    break;

  case 201:
/* Line 1813 of yacc.c  */
#line 2605 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("stdout", (size_t)6);
		current_file->special = COB_SELECT_STDOUT;
	}
  }
    break;

  case 202:
/* Line 1813 of yacc.c  */
#line 2618 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("stdin", (size_t)5);
		current_file->special = COB_SELECT_STDIN;
	}
  }
    break;

  case 203:
/* Line 1813 of yacc.c  */
#line 2631 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("LPT1", (size_t)4);
	}
  }
    break;

  case 209:
/* Line 1813 of yacc.c  */
#line 2654 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:
/* Line 1813 of yacc.c  */
#line 2661 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:
/* Line 1813 of yacc.c  */
#line 2674 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:
/* Line 1813 of yacc.c  */
#line 2686 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:
/* Line 1813 of yacc.c  */
#line 2693 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:
/* Line 1813 of yacc.c  */
#line 2694 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:
/* Line 1813 of yacc.c  */
#line 2695 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:
/* Line 1813 of yacc.c  */
#line 2703 "parser.y"
    {
	struct cb_alt_key *p;
	struct cb_alt_key *l;

	p = cobc_parse_malloc (sizeof (struct cb_alt_key));
	p->key = (yyvsp[(5) - (6)]);
	p->duplicates = CB_INTEGER ((yyvsp[(6) - (6)]))->val;
	p->next = NULL;

	/* Add to the end of list */
	if (current_file->alt_key_list == NULL) {
		current_file->alt_key_list = p;
	} else {
		l = current_file->alt_key_list;
		for (; l->next; l = l->next) {
			;
		}
		l->next = p;
	}
  }
    break;

  case 223:
/* Line 1813 of yacc.c  */
#line 2730 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 224:
/* Line 1813 of yacc.c  */
#line 2741 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 228:
/* Line 1813 of yacc.c  */
#line 2756 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 230:
/* Line 1813 of yacc.c  */
#line 2764 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 231:
/* Line 1813 of yacc.c  */
#line 2769 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 232:
/* Line 1813 of yacc.c  */
#line 2774 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 235:
/* Line 1813 of yacc.c  */
#line 2783 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 236:
/* Line 1813 of yacc.c  */
#line 2787 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 239:
/* Line 1813 of yacc.c  */
#line 2803 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 240:
/* Line 1813 of yacc.c  */
#line 2808 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 241:
/* Line 1813 of yacc.c  */
#line 2813 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 242:
/* Line 1813 of yacc.c  */
#line 2818 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 243:
/* Line 1813 of yacc.c  */
#line 2829 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 244:
/* Line 1813 of yacc.c  */
#line 2840 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 245:
/* Line 1813 of yacc.c  */
#line 2850 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 246:
/* Line 1813 of yacc.c  */
#line 2857 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 247:
/* Line 1813 of yacc.c  */
#line 2858 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 248:
/* Line 1813 of yacc.c  */
#line 2859 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 249:
/* Line 1813 of yacc.c  */
#line 2866 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 250:
/* Line 1813 of yacc.c  */
#line 2877 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 253:
/* Line 1813 of yacc.c  */
#line 2891 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  }
    break;

  case 254:
/* Line 1813 of yacc.c  */
#line 2898 "parser.y"
    { (yyval) = NULL; }
    break;

  case 255:
/* Line 1813 of yacc.c  */
#line 2899 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 256:
/* Line 1813 of yacc.c  */
#line 2900 "parser.y"
    { (yyval) = NULL; }
    break;

  case 259:
/* Line 1813 of yacc.c  */
#line 2909 "parser.y"
    {
	yyerrok;
  }
    break;

  case 264:
/* Line 1813 of yacc.c  */
#line 2928 "parser.y"
    {
	cb_tree l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	switch (CB_INTEGER ((yyvsp[(2) - (5)]))->val) {
	case 0:
		/* SAME AREA */
		break;
	case 1:
		/* SAME RECORD */
		for (l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN (l)) {
			if (CB_VALID_TREE (CB_VALUE (l))) {
				CB_FILE (cb_ref (CB_VALUE (l)))->same_clause = samearea;
			}
		}
		samearea++;
		break;
	case 2:
		/* SAME SORT-MERGE */
		break;
	}
  }
    break;

  case 265:
/* Line 1813 of yacc.c  */
#line 2955 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 266:
/* Line 1813 of yacc.c  */
#line 2956 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 267:
/* Line 1813 of yacc.c  */
#line 2957 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 268:
/* Line 1813 of yacc.c  */
#line 2958 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 269:
/* Line 1813 of yacc.c  */
#line 2965 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 270:
/* Line 1813 of yacc.c  */
#line 2970 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
    break;

  case 277:
/* Line 1813 of yacc.c  */
#line 2997 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 279:
/* Line 1813 of yacc.c  */
#line 3006 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 282:
/* Line 1813 of yacc.c  */
#line 3020 "parser.y"
    {
	if (CB_VALID_TREE (current_file)) {
		if (CB_VALID_TREE ((yyvsp[(2) - (2)]))) {
			if (current_file->reports) {
				cb_error (_("RECORD description invalid with REPORT"));
			} else {
				finalize_file (current_file, CB_FIELD ((yyvsp[(2) - (2)])));
			}
		} else if (!current_file->reports) {
			cb_error (_("RECORD description missing or invalid"));
		}
	}
  }
    break;

  case 283:
/* Line 1813 of yacc.c  */
#line 3039 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION,
			       COBC_HD_FILE_SECTION, 0, 0);
	check_duplicate = 0;
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)])) || cb_ref ((yyvsp[(2) - (2)])) == cb_error_node) {
		YYERROR;
	}
	current_file = CB_FILE (cb_ref ((yyvsp[(2) - (2)])));
	if (CB_VALID_TREE (current_file)) {
		if ((yyvsp[(1) - (2)])) {
			current_file->organization = COB_ORG_SORT;
		}
	}
  }
    break;

  case 285:
/* Line 1813 of yacc.c  */
#line 3056 "parser.y"
    {
	yyerrok;
  }
    break;

  case 286:
/* Line 1813 of yacc.c  */
#line 3063 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 287:
/* Line 1813 of yacc.c  */
#line 3067 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 290:
/* Line 1813 of yacc.c  */
#line 3078 "parser.y"
    {
	check_repeated ("EXTERNAL", SYN_CLAUSE_1);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_global) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	current_file->flag_external = 1;
  }
    break;

  case 291:
/* Line 1813 of yacc.c  */
#line 3088 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_2);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_external) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		current_file->flag_global = 1;
		current_program->flag_file_global = 1;
	}
  }
    break;

  case 301:
/* Line 1813 of yacc.c  */
#line 3118 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 305:
/* Line 1813 of yacc.c  */
#line 3131 "parser.y"
    {
	check_repeated ("RECORD", SYN_CLAUSE_4);
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if (warningopt) {
			cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_max = cb_get_int ((yyvsp[(3) - (4)]));
		if (current_file->record_max < 1)  {
			current_file->record_max = 1;
			cb_error (_("RECORD clause invalid"));
		}
		if (current_file->record_max > MAX_FD_RECORD)  {
			current_file->record_max = MAX_FD_RECORD;
			cb_error (_("RECORD size exceeds maximum allowed (%d)"),
				  MAX_FD_RECORD);
		}
	}
  }
    break;

  case 306:
/* Line 1813 of yacc.c  */
#line 3151 "parser.y"
    {
	int	error_ind = 0;

	check_repeated ("RECORD", SYN_CLAUSE_4);
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if (warningopt) {
			cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_min = cb_get_int ((yyvsp[(3) - (6)]));
		current_file->record_max = cb_get_int ((yyvsp[(5) - (6)]));
		if (current_file->record_min < 0)  {
			current_file->record_min = 0;
			error_ind = 1;
		}
		if (current_file->record_max < 1)  {
			current_file->record_max = 1;
			error_ind = 1;
		}
		if (current_file->record_max > MAX_FD_RECORD)  {
			current_file->record_max = MAX_FD_RECORD;
			cb_error (_("RECORD size exceeds maximum allowed (%d)"),
				  MAX_FD_RECORD);
			error_ind = 1;
		}
		if (current_file->record_max <= current_file->record_min)  {
			error_ind = 1;
		}
		if (error_ind) {
			cb_error (_("RECORD clause invalid"));
		}
	}
  }
    break;

  case 307:
/* Line 1813 of yacc.c  */
#line 3186 "parser.y"
    {
	int	error_ind = 0;

	check_repeated ("RECORD", SYN_CLAUSE_4);
	current_file->record_min = (yyvsp[(6) - (9)]) ? cb_get_int ((yyvsp[(6) - (9)])) : 0;
	current_file->record_max = (yyvsp[(7) - (9)]) ? cb_get_int ((yyvsp[(7) - (9)])) : 0;
	if ((yyvsp[(6) - (9)]) && current_file->record_min < 0)  {
		current_file->record_min = 0;
		error_ind = 1;
	}
	if ((yyvsp[(7) - (9)]) && current_file->record_max < 1)  {
		current_file->record_max = 1;
		error_ind = 1;
	}
	if ((yyvsp[(7) - (9)]) && current_file->record_max > MAX_FD_RECORD)  {
		current_file->record_max = MAX_FD_RECORD;
		cb_error (_("RECORD size exceeds maximum allowed (%d)"),
			  MAX_FD_RECORD);
		error_ind = 1;
	}
	if (((yyvsp[(6) - (9)]) || (yyvsp[(7) - (9)])) && current_file->record_max <= current_file->record_min)  {
		error_ind = 1;
	}
	if (error_ind) {
		cb_error (_("RECORD clause invalid"));
	}
  }
    break;

  case 309:
/* Line 1813 of yacc.c  */
#line 3217 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 310:
/* Line 1813 of yacc.c  */
#line 3223 "parser.y"
    { (yyval) = NULL; }
    break;

  case 311:
/* Line 1813 of yacc.c  */
#line 3224 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 312:
/* Line 1813 of yacc.c  */
#line 3228 "parser.y"
    { (yyval) = NULL; }
    break;

  case 313:
/* Line 1813 of yacc.c  */
#line 3229 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 314:
/* Line 1813 of yacc.c  */
#line 3237 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 315:
/* Line 1813 of yacc.c  */
#line 3248 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 316:
/* Line 1813 of yacc.c  */
#line 3253 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 321:
/* Line 1813 of yacc.c  */
#line 3276 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 322:
/* Line 1813 of yacc.c  */
#line 3288 "parser.y"
    {
	check_repeated ("LINAGE", SYN_CLAUSE_8);
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("LINAGE clause with wrong file type"));
	} else {
		current_file->linage = (yyvsp[(3) - (5)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		if (current_linage == 0) {
			linage_file = current_file;
		}
		current_linage++;
	}
  }
    break;

  case 328:
/* Line 1813 of yacc.c  */
#line 3316 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 329:
/* Line 1813 of yacc.c  */
#line 3323 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 330:
/* Line 1813 of yacc.c  */
#line 3330 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 331:
/* Line 1813 of yacc.c  */
#line 3339 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 332:
/* Line 1813 of yacc.c  */
#line 3351 "parser.y"
    {
	check_repeated ("CODE SET", SYN_CLAUSE_10);
	if (CB_VALID_TREE ((yyvsp[(3) - (3)]))) {
		cb_tree			x;
		struct cb_alphabet_name	*al;

		x = cb_ref ((yyvsp[(3) - (3)]));
		if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
		    current_file->organization != COB_ORG_SEQUENTIAL) {
			cb_error (_("CODE-SET clause invalid for file type"));
		}
		if (!CB_ALPHABET_NAME_P (x)) {
			cb_error_x ((yyvsp[(3) - (3)]), _("Alphabet-name is expected '%s'"), cb_name ((yyvsp[(3) - (3)])));
		} else {
			al = CB_ALPHABET_NAME (x);
			switch (al->alphabet_type) {
#ifdef	COB_EBCDIC_MACHINE
			case CB_ALPHABET_ASCII:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if (warningopt) {
					cb_warning_x ((yyvsp[(3) - (3)]), _("Ignoring CODE-SET '%s'"),
						      cb_name ((yyvsp[(3) - (3)])));
				}
				break;
#else
			case CB_ALPHABET_EBCDIC:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if (warningopt) {
					cb_warning_x ((yyvsp[(3) - (3)]), _("Ignoring CODE-SET '%s'"),
						      cb_name ((yyvsp[(3) - (3)])));
				}
				break;
#endif
			}
			if (warningopt) {
				PENDING ("CODE-SET");
			}
		}
	}
  }
    break;

  case 333:
/* Line 1813 of yacc.c  */
#line 3403 "parser.y"
    {
	check_repeated ("REPORT", SYN_CLAUSE_11);
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("REPORT clause with wrong file type"));
	} else {
		current_file->reports = (yyvsp[(2) - (2)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		current_file->flag_line_adv = 1;
	}
  }
    break;

  case 336:
/* Line 1813 of yacc.c  */
#line 3423 "parser.y"
    {
	current_report = build_report ((yyvsp[(1) - (1)]));
	current_report->file = current_file;
	current_program->report_list =
				cb_list_add (current_program->report_list,
					     CB_TREE (current_report));
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 337:
/* Line 1813 of yacc.c  */
#line 3435 "parser.y"
    {
	current_report = build_report ((yyvsp[(2) - (2)]));
	current_report->file = current_file;
	current_program->report_list =
				cb_list_add (current_program->report_list,
					     CB_TREE (current_report));
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 339:
/* Line 1813 of yacc.c  */
#line 3478 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 340:
/* Line 1813 of yacc.c  */
#line 3484 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 341:
/* Line 1813 of yacc.c  */
#line 3493 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 342:
/* Line 1813 of yacc.c  */
#line 3496 "parser.y"
    {
	current_field = NULL;
	control_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 343:
/* Line 1813 of yacc.c  */
#line 3503 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 348:
/* Line 1813 of yacc.c  */
#line 3523 "parser.y"
    {
	cb_tree x;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (2)]));
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	} else {
		current_field = CB_FIELD (x);
		check_pic_duplicate = 0;
	}
  }
    break;

  case 349:
/* Line 1813 of yacc.c  */
#line 3538 "parser.y"
    {
	if (!qualifier && (current_field->level == 88 ||
	    current_field->level == 66 || current_field->flag_item_78)) {
		cb_error (_("Item requires a data name"));
	}
	if (!qualifier) {
		current_field->flag_filler = 1;
	}
	if (current_field->level == 88) {
		cb_validate_88_item (current_field);
	}
	if (current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item (current_field, 0);
	}
	if (!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 350:
/* Line 1813 of yacc.c  */
#line 3558 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
    break;

  case 351:
/* Line 1813 of yacc.c  */
#line 3571 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 352:
/* Line 1813 of yacc.c  */
#line 3578 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 353:
/* Line 1813 of yacc.c  */
#line 3584 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 354:
/* Line 1813 of yacc.c  */
#line 3590 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 355:
/* Line 1813 of yacc.c  */
#line 3599 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 356:
/* Line 1813 of yacc.c  */
#line 3608 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 357:
/* Line 1813 of yacc.c  */
#line 3612 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  }
    break;

  case 358:
/* Line 1813 of yacc.c  */
#line 3623 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 359:
/* Line 1813 of yacc.c  */
#line 3624 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 360:
/* Line 1813 of yacc.c  */
#line 3625 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 361:
/* Line 1813 of yacc.c  */
#line 3626 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 362:
/* Line 1813 of yacc.c  */
#line 3631 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 363:
/* Line 1813 of yacc.c  */
#line 3635 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 364:
/* Line 1813 of yacc.c  */
#line 3639 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 365:
/* Line 1813 of yacc.c  */
#line 3643 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 366:
/* Line 1813 of yacc.c  */
#line 3647 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 367:
/* Line 1813 of yacc.c  */
#line 3651 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 368:
/* Line 1813 of yacc.c  */
#line 3655 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 369:
/* Line 1813 of yacc.c  */
#line 3659 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 370:
/* Line 1813 of yacc.c  */
#line 3663 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 371:
/* Line 1813 of yacc.c  */
#line 3667 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 372:
/* Line 1813 of yacc.c  */
#line 3671 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 373:
/* Line 1813 of yacc.c  */
#line 3675 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 374:
/* Line 1813 of yacc.c  */
#line 3679 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
    break;

  case 384:
/* Line 1813 of yacc.c  */
#line 3711 "parser.y"
    {
	cb_tree x;
	int	level;

	cobc_cs_check = 0;
	level = cb_get_level ((yyvsp[(1) - (5)]));
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (5)]));
	if (level != 1) {
		cb_error (_("CONSTANT item not at 01 level"));
	} else if ((yyvsp[(5) - (5)])) {
		x = cb_build_constant ((yyvsp[(2) - (5)]), (yyvsp[(5) - (5)]));
		CB_FIELD (x)->flag_item_78 = 1;
		CB_FIELD (x)->level = 1;
		cb_needs_01 = 1;
		if ((yyvsp[(4) - (5)])) {
			CB_FIELD (x)->flag_is_global = 1;
		}
		/* Ignore return value */
		(void)cb_validate_78_item (CB_FIELD (x), 0);
	}
  }
    break;

  case 385:
/* Line 1813 of yacc.c  */
#line 3737 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 386:
/* Line 1813 of yacc.c  */
#line 3741 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 387:
/* Line 1813 of yacc.c  */
#line 3749 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 388:
/* Line 1813 of yacc.c  */
#line 3755 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 403:
/* Line 1813 of yacc.c  */
#line 3783 "parser.y"
    {
	check_pic_repeated ("REDEFINES", SYN_CLAUSE_1);
	if ((yyvsp[(0) - (2)]) != NULL) {
		if (cb_relaxed_syntax_check) {
			cb_warning_x ((yyvsp[(2) - (2)]), _("REDEFINES clause should follow entry-name"));
		} else {
			cb_error_x ((yyvsp[(2) - (2)]), _("REDEFINES clause must follow entry-name"));
		}
	}

	current_field->redefines = cb_resolve_redefines (current_field, (yyvsp[(2) - (2)]));
	if (current_field->redefines == NULL) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
		YYERROR;
	}
  }
    break;

  case 404:
/* Line 1813 of yacc.c  */
#line 3807 "parser.y"
    {
	check_pic_repeated ("EXTERNAL", SYN_CLAUSE_2);
	if (current_storage != CB_STORAGE_WORKING) {
		cb_error (_("EXTERNAL not allowed here"));
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("EXTERNAL only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("EXTERNAL requires a data name"));
#if	0	/* RXWRXW - Global/External */
	} else if (current_field->flag_is_global) {
		cb_error (_("GLOBAL and EXTERNAL are mutually exclusive"));
#endif
	} else if (current_field->flag_item_based) {
		cb_error (_("BASED and EXTERNAL are mutually exclusive"));
	} else if (current_field->redefines) {
		cb_error (_("EXTERNAL and REDEFINES are mutually exclusive"));
	} else if (current_field->flag_occurs) {
		cb_error (_("EXTERNAL and OCCURS are mutually exclusive"));
	} else {
		current_field->flag_external = 1;
		current_program->flag_has_external = 1;
	}
  }
    break;

  case 405:
/* Line 1813 of yacc.c  */
#line 3834 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 406:
/* Line 1813 of yacc.c  */
#line 3838 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 407:
/* Line 1813 of yacc.c  */
#line 3847 "parser.y"
    {
	check_pic_repeated ("GLOBAL", SYN_CLAUSE_3);
	if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("GLOBAL only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("GLOBAL requires a data name"));
#if	0	/* RXWRXW - Global/External */
	} else if (current_field->flag_external) {
		cb_error (_("GLOBAL and EXTERNAL are mutually exclusive"));
#endif
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else if (current_storage == CB_STORAGE_LOCAL) {
		cb_error (_("GLOBAL not allowed here"));
	} else {
		current_field->flag_is_global = 1;
	}
  }
    break;

  case 408:
/* Line 1813 of yacc.c  */
#line 3872 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 411:
/* Line 1813 of yacc.c  */
#line 3888 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 412:
/* Line 1813 of yacc.c  */
#line 3892 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 413:
/* Line 1813 of yacc.c  */
#line 3896 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 414:
/* Line 1813 of yacc.c  */
#line 3900 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 415:
/* Line 1813 of yacc.c  */
#line 3904 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 416:
/* Line 1813 of yacc.c  */
#line 3908 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 417:
/* Line 1813 of yacc.c  */
#line 3912 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 418:
/* Line 1813 of yacc.c  */
#line 3916 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 419:
/* Line 1813 of yacc.c  */
#line 3920 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 420:
/* Line 1813 of yacc.c  */
#line 3924 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 421:
/* Line 1813 of yacc.c  */
#line 3928 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 422:
/* Line 1813 of yacc.c  */
#line 3932 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 423:
/* Line 1813 of yacc.c  */
#line 3936 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 424:
/* Line 1813 of yacc.c  */
#line 3941 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 425:
/* Line 1813 of yacc.c  */
#line 3946 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 426:
/* Line 1813 of yacc.c  */
#line 3950 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 427:
/* Line 1813 of yacc.c  */
#line 3954 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 428:
/* Line 1813 of yacc.c  */
#line 3962 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 429:
/* Line 1813 of yacc.c  */
#line 3966 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 430:
/* Line 1813 of yacc.c  */
#line 3970 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 431:
/* Line 1813 of yacc.c  */
#line 3978 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 432:
/* Line 1813 of yacc.c  */
#line 3982 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 433:
/* Line 1813 of yacc.c  */
#line 3986 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 434:
/* Line 1813 of yacc.c  */
#line 3990 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 435:
/* Line 1813 of yacc.c  */
#line 3994 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 436:
/* Line 1813 of yacc.c  */
#line 3998 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 437:
/* Line 1813 of yacc.c  */
#line 4002 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 438:
/* Line 1813 of yacc.c  */
#line 4006 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 439:
/* Line 1813 of yacc.c  */
#line 4010 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 440:
/* Line 1813 of yacc.c  */
#line 4018 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 441:
/* Line 1813 of yacc.c  */
#line 4026 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 442:
/* Line 1813 of yacc.c  */
#line 4030 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 443:
/* Line 1813 of yacc.c  */
#line 4034 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 444:
/* Line 1813 of yacc.c  */
#line 4038 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 445:
/* Line 1813 of yacc.c  */
#line 4042 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 446:
/* Line 1813 of yacc.c  */
#line 4046 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 451:
/* Line 1813 of yacc.c  */
#line 4066 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 452:
/* Line 1813 of yacc.c  */
#line 4072 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 453:
/* Line 1813 of yacc.c  */
#line 4085 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_7);
	if (current_field->depending && !((yyvsp[(3) - (6)]))) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (6)]) ? cb_get_int ((yyvsp[(2) - (6)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (6)]) ? cb_get_int ((yyvsp[(3) - (6)])) : cb_get_int ((yyvsp[(2) - (6)]));
	current_field->indexes++;
	if (current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error (_("Maximum OCCURS depth exceeded (%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	current_field->flag_occurs = 1;
  }
    break;

  case 455:
/* Line 1813 of yacc.c  */
#line 4103 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 456:
/* Line 1813 of yacc.c  */
#line 4113 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_7);
	if (current_field->depending && !((yyvsp[(3) - (7)]))) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (7)]) ? cb_get_int ((yyvsp[(2) - (7)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (7)]) ? cb_get_int ((yyvsp[(3) - (7)])) : cb_get_int ((yyvsp[(2) - (7)]));
	current_field->indexes++;
	if (current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error (_("Maximum OCCURS depth exceeded (%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	if (current_field->flag_item_based) {
		cb_error (_("BASED and OCCURS are mutually exclusive"));
	} else if (current_field->flag_external) {
		cb_error (_("EXTERNAL and OCCURS are mutually exclusive"));
	}
	current_field->flag_occurs = 1;
  }
    break;

  case 457:
/* Line 1813 of yacc.c  */
#line 4135 "parser.y"
    { (yyval) = NULL; }
    break;

  case 458:
/* Line 1813 of yacc.c  */
#line 4136 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 460:
/* Line 1813 of yacc.c  */
#line 4141 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 461:
/* Line 1813 of yacc.c  */
#line 4148 "parser.y"
    {
	if ((yyvsp[(1) - (1)])) {
		cb_tree		l;
		struct cb_key	*keys;
		int		i;
		int		nkeys;

		l = (yyvsp[(1) - (1)]);
		nkeys = cb_list_length ((yyvsp[(1) - (1)]));
		keys = cobc_parse_malloc (sizeof (struct cb_key) * nkeys);

		for (i = 0; i < nkeys; i++) {
			keys[i].dir = CB_PURPOSE_INT (l);
			keys[i].key = CB_VALUE (l);
			l = CB_CHAIN (l);
		}
		current_field->keys = keys;
		current_field->nkeys = nkeys;
	}
  }
    break;

  case 462:
/* Line 1813 of yacc.c  */
#line 4171 "parser.y"
    { (yyval) = NULL; }
    break;

  case 463:
/* Line 1813 of yacc.c  */
#line 4174 "parser.y"
    {
	cb_tree l;

	for (l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = (yyvsp[(2) - (5)]);
		if (qualifier && !CB_REFERENCE(CB_VALUE(l))->chain &&
		    strcasecmp (CB_NAME(CB_VALUE(l)), CB_NAME(qualifier))) {
			CB_REFERENCE(CB_VALUE(l))->chain = qualifier;
		}
	}
	(yyval) = cb_list_append ((yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 464:
/* Line 1813 of yacc.c  */
#line 4189 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 465:
/* Line 1813 of yacc.c  */
#line 4190 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 467:
/* Line 1813 of yacc.c  */
#line 4195 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 468:
/* Line 1813 of yacc.c  */
#line 4201 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 469:
/* Line 1813 of yacc.c  */
#line 4203 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 470:
/* Line 1813 of yacc.c  */
#line 4208 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 471:
/* Line 1813 of yacc.c  */
#line 4219 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 472:
/* Line 1813 of yacc.c  */
#line 4230 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 473:
/* Line 1813 of yacc.c  */
#line 4241 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 474:
/* Line 1813 of yacc.c  */
#line 4252 "parser.y"
    {
	check_pic_repeated ("BASED", SYN_CLAUSE_11);
	if (current_storage != CB_STORAGE_WORKING &&
	    current_storage != CB_STORAGE_LINKAGE &&
	    current_storage != CB_STORAGE_LOCAL) {
		cb_error (_("BASED not allowed here"));
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("BASED only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("BASED requires a data name"));
	} else if (current_field->flag_external) {
		cb_error (_("BASED and EXTERNAL are mutually exclusive"));
	} else if (current_field->redefines) {
		cb_error (_("BASED and REDEFINES are mutually exclusive"));
	} else if (current_field->flag_any_length) {
		cb_error (_("BASED and ANY LENGTH are mutually exclusive"));
	} else if (current_field->flag_occurs) {
		cb_error (_("BASED and OCCURS are mutually exclusive"));
	} else {
		current_field->flag_item_based = 1;
	}
  }
    break;

  case 475:
/* Line 1813 of yacc.c  */
#line 4280 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 477:
/* Line 1813 of yacc.c  */
#line 4288 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 478:
/* Line 1813 of yacc.c  */
#line 4289 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 479:
/* Line 1813 of yacc.c  */
#line 4293 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 480:
/* Line 1813 of yacc.c  */
#line 4294 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 482:
/* Line 1813 of yacc.c  */
#line 4299 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 483:
/* Line 1813 of yacc.c  */
#line 4312 "parser.y"
    {
	check_pic_repeated ("RENAMES", SYN_CLAUSE_13);
	if (cb_ref ((yyvsp[(2) - (2)])) != cb_error_node) {
		if (CB_FIELD (cb_ref ((yyvsp[(2) - (2)])))->level == 01 ||
		    CB_FIELD (cb_ref ((yyvsp[(2) - (2)])))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD (cb_ref ((yyvsp[(2) - (2)])));
			current_field->pic = current_field->redefines->pic;
		}
	}
  }
    break;

  case 484:
/* Line 1813 of yacc.c  */
#line 4325 "parser.y"
    {
	check_pic_repeated ("RENAMES", SYN_CLAUSE_13);
	if (cb_ref ((yyvsp[(2) - (4)])) != cb_error_node && cb_ref ((yyvsp[(4) - (4)])) != cb_error_node) {
		if (CB_FIELD (cb_ref ((yyvsp[(2) - (4)])))->level == 01 ||
		    CB_FIELD (cb_ref ((yyvsp[(2) - (4)])))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else if (CB_FIELD (cb_ref ((yyvsp[(4) - (4)])))->level == 01 ||
		    CB_FIELD (cb_ref ((yyvsp[(4) - (4)])))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD (cb_ref ((yyvsp[(2) - (4)])));
			current_field->rename_thru = CB_FIELD (cb_ref ((yyvsp[(4) - (4)])));
		}
	}
  }
    break;

  case 485:
/* Line 1813 of yacc.c  */
#line 4346 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  }
    break;

  case 486:
/* Line 1813 of yacc.c  */
#line 4355 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
		current_field->flag_any_numeric = 1;
	}
  }
    break;

  case 488:
/* Line 1813 of yacc.c  */
#line 4370 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  }
    break;

  case 489:
/* Line 1813 of yacc.c  */
#line 4379 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 491:
/* Line 1813 of yacc.c  */
#line 4391 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 492:
/* Line 1813 of yacc.c  */
#line 4397 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 494:
/* Line 1813 of yacc.c  */
#line 4408 "parser.y"
    {
	current_storage = CB_STORAGE_REPORT;
	description_field = NULL;
	current_program->flag_report = 1;
	cb_clear_real_field ();
  }
    break;

  case 498:
/* Line 1813 of yacc.c  */
#line 4425 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  }
    break;

  case 499:
/* Line 1813 of yacc.c  */
#line 4435 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	current_program->report_storage = description_field;
	current_program->flag_report = 1;
	if(current_report->records == NULL)
		current_report->records = description_field;
	finalize_report (current_report, description_field);
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 502:
/* Line 1813 of yacc.c  */
#line 4453 "parser.y"
    {
	yyerrok;
  }
    break;

  case 503:
/* Line 1813 of yacc.c  */
#line 4460 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	current_report->global = 1;
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 504:
/* Line 1813 of yacc.c  */
#line 4466 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 507:
/* Line 1813 of yacc.c  */
#line 4477 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 511:
/* Line 1813 of yacc.c  */
#line 4490 "parser.y"
    {
      current_report->control_final = 1;
  }
    break;

  case 514:
/* Line 1813 of yacc.c  */
#line 4502 "parser.y"
    {
	/* Add field to current control list */
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), current_report->controls);
  }
    break;

  case 515:
/* Line 1813 of yacc.c  */
#line 4513 "parser.y"
    {
	check_repeated ("PAGE", SYN_CLAUSE_4);
	if (!current_report->heading) {
		current_report->heading = 1;
	}
	if (!current_report->first_detail) {
		current_report->first_detail = current_report->heading;
	}
	if (!current_report->last_control) {
		if (current_report->last_detail) {
			current_report->last_control = current_report->last_detail;
		} else if (current_report->footing) {
			current_report->last_control = current_report->footing;
		} else {
			current_report->last_control = current_report->lines;
		}
	}
	if (!current_report->last_detail && !current_report->footing) {
		current_report->last_detail = current_report->lines;
		current_report->footing = current_report->lines;
	} else if (!current_report->last_detail) {
		current_report->last_detail = current_report->footing;
	} else if (!current_report->footing) {
		current_report->footing = current_report->last_detail;
	}
	if (current_report->heading > current_report->first_detail ||
	    current_report->first_detail > current_report->last_control ||
	    current_report->last_control > current_report->last_detail ||
	    current_report->last_detail > current_report->footing) {
		cb_error (_("Invalid PAGE clause"));
	}
  }
    break;

  case 516:
/* Line 1813 of yacc.c  */
#line 4549 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 517:
/* Line 1813 of yacc.c  */
#line 4553 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  }
    break;

  case 518:
/* Line 1813 of yacc.c  */
#line 4558 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  }
    break;

  case 526:
/* Line 1813 of yacc.c  */
#line 4578 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 527:
/* Line 1813 of yacc.c  */
#line 4585 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 528:
/* Line 1813 of yacc.c  */
#line 4592 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 529:
/* Line 1813 of yacc.c  */
#line 4599 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 530:
/* Line 1813 of yacc.c  */
#line 4606 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 533:
/* Line 1813 of yacc.c  */
#line 4617 "parser.y"
    {
	cb_tree	x;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (2)]));
	check_pic_duplicate = 0;
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	}

	current_field = CB_FIELD (x);
	if (!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 553:
/* Line 1813 of yacc.c  */
#line 4662 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 554:
/* Line 1813 of yacc.c  */
#line 4669 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_HEADING;
  }
    break;

  case 555:
/* Line 1813 of yacc.c  */
#line 4673 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_PAGE_HEADING;
  }
    break;

  case 558:
/* Line 1813 of yacc.c  */
#line 4679 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_DETAIL;
  }
    break;

  case 559:
/* Line 1813 of yacc.c  */
#line 4683 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_PAGE_FOOTING;
  }
    break;

  case 560:
/* Line 1813 of yacc.c  */
#line 4687 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_FOOTING;
  }
    break;

  case 561:
/* Line 1813 of yacc.c  */
#line 4693 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING;
  }
    break;

  case 562:
/* Line 1813 of yacc.c  */
#line 4697 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING;
      current_field->report_control = (yyvsp[(1) - (1)]);
  }
    break;

  case 563:
/* Line 1813 of yacc.c  */
#line 4702 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING_FINAL;
  }
    break;

  case 564:
/* Line 1813 of yacc.c  */
#line 4708 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING;
  }
    break;

  case 565:
/* Line 1813 of yacc.c  */
#line 4712 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING;
      current_field->report_control = (yyvsp[(1) - (1)]);
  }
    break;

  case 566:
/* Line 1813 of yacc.c  */
#line 4717 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING_FINAL;
  }
    break;

  case 567:
/* Line 1813 of yacc.c  */
#line 4724 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 568:
/* Line 1813 of yacc.c  */
#line 4731 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_LINE;
      current_field->next_group_line = cb_get_int((yyvsp[(1) - (1)]));
  }
    break;

  case 569:
/* Line 1813 of yacc.c  */
#line 4736 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
      current_field->next_group_line = cb_get_int((yyvsp[(2) - (2)]));
  }
    break;

  case 570:
/* Line 1813 of yacc.c  */
#line 4741 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PAGE;
  }
    break;

  case 571:
/* Line 1813 of yacc.c  */
#line 4748 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_PAGE;
  }
    break;

  case 572:
/* Line 1813 of yacc.c  */
#line 4755 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
	current_field->report_sum_list = (yyvsp[(3) - (4)]);
	build_sum_counter( current_report, current_field);
  }
    break;

  case 575:
/* Line 1813 of yacc.c  */
#line 4768 "parser.y"
    {
      current_field->report_reset = (yyvsp[(1) - (1)]);
  }
    break;

  case 576:
/* Line 1813 of yacc.c  */
#line 4772 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_RESET_FINAL;
  }
    break;

  case 577:
/* Line 1813 of yacc.c  */
#line 4779 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 579:
/* Line 1813 of yacc.c  */
#line 4790 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
	current_field->report_flag |= COB_REPORT_LINE;
  }
    break;

  case 582:
/* Line 1813 of yacc.c  */
#line 4803 "parser.y"
    {
	current_field->report_flag |= COB_REPORT_LINE_PLUS;
  }
    break;

  case 586:
/* Line 1813 of yacc.c  */
#line 4815 "parser.y"
    {
      current_field->report_line = cb_get_int((yyvsp[(1) - (1)]));
  }
    break;

  case 588:
/* Line 1813 of yacc.c  */
#line 4822 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_LINE_NEXT_PAGE;
  }
    break;

  case 589:
/* Line 1813 of yacc.c  */
#line 4829 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 592:
/* Line 1813 of yacc.c  */
#line 4841 "parser.y"
    {
	current_field->report_column = cb_get_int ((yyvsp[(2) - (2)]));
	current_field->report_flag |= COB_REPORT_COLUMN_PLUS;
  }
    break;

  case 593:
/* Line 1813 of yacc.c  */
#line 4846 "parser.y"
    {
	current_field->report_column = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 594:
/* Line 1813 of yacc.c  */
#line 4853 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
	current_field->report_source = (yyvsp[(3) - (4)]);
  }
    break;

  case 595:
/* Line 1813 of yacc.c  */
#line 4861 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
	current_field->report_flag |= COB_REPORT_GROUP_INDICATE;
  }
    break;

  case 596:
/* Line 1813 of yacc.c  */
#line 4869 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 598:
/* Line 1813 of yacc.c  */
#line 4878 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 599:
/* Line 1813 of yacc.c  */
#line 4885 "parser.y"
    {
	struct cb_field *p;

	if (description_field) {
		for (p = description_field; p; p = p->sister) {
			cb_validate_field (p);
		}
		current_program->screen_storage = description_field;
		current_program->flag_screen = 1;
	}
  }
    break;

  case 605:
/* Line 1813 of yacc.c  */
#line 4910 "parser.y"
    {
	cb_tree	x;
	int	flags;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (2)]));
	check_pic_duplicate = 0;
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	}

	current_field = CB_FIELD (x);
	if (current_field->parent) {
		flags = current_field->parent->screen_flag;
		flags &= ~COB_SCREEN_BLANK_LINE;
		flags &= ~COB_SCREEN_BLANK_SCREEN;
		flags &= ~COB_SCREEN_ERASE_EOL;
		flags &= ~COB_SCREEN_ERASE_EOS;
		flags &= ~COB_SCREEN_LINE_PLUS;
		flags &= ~COB_SCREEN_LINE_MINUS;
		flags &= ~COB_SCREEN_COLUMN_PLUS;
		flags &= ~COB_SCREEN_COLUMN_MINUS;
		current_field->screen_flag |= flags;
		current_field->screen_foreg = current_field->parent->screen_foreg;
		current_field->screen_backg = current_field->parent->screen_backg;
		current_field->screen_prompt = current_field->parent->screen_prompt;
	}
  }
    break;

  case 606:
/* Line 1813 of yacc.c  */
#line 4941 "parser.y"
    {
	if (!qualifier && (current_field->level == 88 ||
	    current_field->level == 66 ||
	    current_field->flag_item_78)) {
		cb_error (_("Item requires a data name"));
	}
	if (current_field->screen_flag & COB_SCREEN_INITIAL) {
		if (!(current_field->screen_flag & COB_SCREEN_INPUT)) {
			cb_error (_("INITIAL specified on non-input field"));
		}
	}
	if (!qualifier) {
		current_field->flag_filler = 1;
	}
	if (current_field->level == 88) {
		cb_validate_88_item (current_field);
	}
	if (current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item (current_field, 0);
	}
	if (!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 607:
/* Line 1813 of yacc.c  */
#line 4967 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
#if	1	/* RXWRXW Screen field */
	if (current_field) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
	}
#endif
	current_field = cb_get_real_field ();
  }
    break;

  case 610:
/* Line 1813 of yacc.c  */
#line 4990 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 611:
/* Line 1813 of yacc.c  */
#line 4994 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 612:
/* Line 1813 of yacc.c  */
#line 4998 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 613:
/* Line 1813 of yacc.c  */
#line 5002 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 614:
/* Line 1813 of yacc.c  */
#line 5006 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 615:
/* Line 1813 of yacc.c  */
#line 5010 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 616:
/* Line 1813 of yacc.c  */
#line 5014 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 617:
/* Line 1813 of yacc.c  */
#line 5018 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 618:
/* Line 1813 of yacc.c  */
#line 5022 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 619:
/* Line 1813 of yacc.c  */
#line 5026 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 620:
/* Line 1813 of yacc.c  */
#line 5030 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 621:
/* Line 1813 of yacc.c  */
#line 5034 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 622:
/* Line 1813 of yacc.c  */
#line 5038 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 623:
/* Line 1813 of yacc.c  */
#line 5042 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 624:
/* Line 1813 of yacc.c  */
#line 5046 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 625:
/* Line 1813 of yacc.c  */
#line 5050 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 626:
/* Line 1813 of yacc.c  */
#line 5054 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 627:
/* Line 1813 of yacc.c  */
#line 5059 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 628:
/* Line 1813 of yacc.c  */
#line 5063 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 629:
/* Line 1813 of yacc.c  */
#line 5067 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 630:
/* Line 1813 of yacc.c  */
#line 5072 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 631:
/* Line 1813 of yacc.c  */
#line 5077 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 632:
/* Line 1813 of yacc.c  */
#line 5082 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 641:
/* Line 1813 of yacc.c  */
#line 5095 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 642:
/* Line 1813 of yacc.c  */
#line 5102 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 643:
/* Line 1813 of yacc.c  */
#line 5107 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 648:
/* Line 1813 of yacc.c  */
#line 5126 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 649:
/* Line 1813 of yacc.c  */
#line 5130 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 650:
/* Line 1813 of yacc.c  */
#line 5134 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 651:
/* Line 1813 of yacc.c  */
#line 5141 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 652:
/* Line 1813 of yacc.c  */
#line 5145 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 653:
/* Line 1813 of yacc.c  */
#line 5149 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 654:
/* Line 1813 of yacc.c  */
#line 5157 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 655:
/* Line 1813 of yacc.c  */
#line 5168 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 657:
/* Line 1813 of yacc.c  */
#line 5177 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	cb_set_system_names ();
	header_check |= COBC_HD_PROCEDURE_DIVISION;
  }
    break;

  case 658:
/* Line 1813 of yacc.c  */
#line 5187 "parser.y"
    {
	if (current_program->flag_main && !current_program->flag_chained && (yyvsp[(3) - (7)])) {
		cb_error (_("Executable program requested but PROCEDURE/ENTRY has USING clause"));
	}
	/* Main entry point */
	emit_entry (current_program->program_id, 0, (yyvsp[(3) - (7)]));
	current_program->num_proc_params = cb_list_length ((yyvsp[(3) - (7)]));
	if (current_program->source_name) {
		emit_entry (current_program->source_name, 1, (yyvsp[(3) - (7)]));
	}
  }
    break;

  case 659:
/* Line 1813 of yacc.c  */
#line 5199 "parser.y"
    {
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
	}
	if (current_section) {
		if (current_section->exit_label) {
			emit_statement (current_section->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_section));
	}
  }
    break;

  case 660:
/* Line 1813 of yacc.c  */
#line 5214 "parser.y"
    {
	cb_tree label;

	/* No PROCEDURE DIVISION header ! */
	/* Only a statement is allowed as first element */
	/* Thereafter, sections/paragraphs may be used */
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	label = cb_build_reference ("MAIN SECTION");
	current_section = CB_LABEL (cb_build_label (label, NULL));
	current_section->flag_section = 1;
	current_section->flag_dummy_section = 1;
	current_section->flag_skip_label = !!skip_statements;
	current_section->flag_declaratives = !!in_declaratives;
	CB_TREE (current_section)->source_file = cb_source_file;
	CB_TREE (current_section)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_section));
	label = cb_build_reference ("MAIN PARAGRAPH");
	current_paragraph = CB_LABEL (cb_build_label (label, NULL));
	current_paragraph->flag_declaratives = !!in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_dummy_paragraph = 1;
	CB_TREE (current_paragraph)->source_file = cb_source_file;
	CB_TREE (current_paragraph)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_paragraph));
	cb_set_system_names ();
  }
    break;

  case 662:
/* Line 1813 of yacc.c  */
#line 5247 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 663:
/* Line 1813 of yacc.c  */
#line 5251 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 664:
/* Line 1813 of yacc.c  */
#line 5256 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 665:
/* Line 1813 of yacc.c  */
#line 5264 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
    break;

  case 666:
/* Line 1813 of yacc.c  */
#line 5273 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 667:
/* Line 1813 of yacc.c  */
#line 5283 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 668:
/* Line 1813 of yacc.c  */
#line 5285 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 669:
/* Line 1813 of yacc.c  */
#line 5290 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 671:
/* Line 1813 of yacc.c  */
#line 5299 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 672:
/* Line 1813 of yacc.c  */
#line 5303 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 674:
/* Line 1813 of yacc.c  */
#line 5315 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 675:
/* Line 1813 of yacc.c  */
#line 5323 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 676:
/* Line 1813 of yacc.c  */
#line 5331 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 677:
/* Line 1813 of yacc.c  */
#line 5339 "parser.y"
    {
	unsigned char *s = CB_LITERAL ((yyvsp[(4) - (4)]))->data;

	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else if (CB_LITERAL ((yyvsp[(4) - (4)]))->size != 1) {
		cb_error_x ((yyvsp[(4) - (4)]), _("Invalid value for SIZE"));
	} else {
		size_mode = CB_SIZE_UNSIGNED;
		switch (*s) {
		case '1':
			size_mode |= CB_SIZE_1;
			break;
		case '2':
			size_mode |= CB_SIZE_2;
			break;
		case '4':
			size_mode |= CB_SIZE_4;
			break;
		case '8':
			size_mode |= CB_SIZE_8;
			break;
		default:
			cb_error_x ((yyvsp[(4) - (4)]), _("Invalid value for SIZE"));
			break;
		}
	}
  }
    break;

  case 678:
/* Line 1813 of yacc.c  */
#line 5368 "parser.y"
    {
	unsigned char *s = CB_LITERAL ((yyvsp[(3) - (3)]))->data;

	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else if (CB_LITERAL ((yyvsp[(3) - (3)]))->size != 1) {
		cb_error_x ((yyvsp[(3) - (3)]), _("Invalid value for SIZE"));
	} else {
		size_mode = 0;
		switch (*s) {
		case '1':
			size_mode = CB_SIZE_1;
			break;
		case '2':
			size_mode = CB_SIZE_2;
			break;
		case '4':
			size_mode = CB_SIZE_4;
			break;
		case '8':
			size_mode = CB_SIZE_8;
			break;
		default:
			cb_error_x ((yyvsp[(3) - (3)]), _("Invalid value for SIZE"));
			break;
		}
	}
  }
    break;

  case 680:
/* Line 1813 of yacc.c  */
#line 5401 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 681:
/* Line 1813 of yacc.c  */
#line 5410 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 682:
/* Line 1813 of yacc.c  */
#line 5416 "parser.y"
    {
	struct cb_field	*f;

	if (cb_ref ((yyvsp[(2) - (2)])) != cb_error_node) {
		f = CB_FIELD_PTR ((yyvsp[(2) - (2)]));
/* RXWRXW
		if (f->storage != CB_STORAGE_LINKAGE) {
			cb_error (_("RETURNING item is not defined in LINKAGE SECTION"));
		} else if (f->level != 1 && f->level != 77) {
*/
		if (f->level != 1 && f->level != 77) {
			cb_error (_("RETURNING item must have level 01"));
		} else {
			if (current_program->prog_type == CB_FUNCTION_TYPE) {
				f->flag_is_returning = 1;
			}
			current_program->returning = (yyvsp[(2) - (2)]);
		}
	}
  }
    break;

  case 684:
/* Line 1813 of yacc.c  */
#line 5440 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 685:
/* Line 1813 of yacc.c  */
#line 5446 "parser.y"
    {
	if (needs_field_debug) {
		start_debug = 1;
	}
	in_declaratives = 0;
	in_debugging = 0;
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
		current_paragraph = NULL;
	}
	if (current_section) {
		if (current_section->exit_label) {
			emit_statement (current_section->exit_label);
		}
		current_section->flag_fatal_check = 1;
		emit_statement (cb_build_perform_exit (current_section));
		current_section = NULL;
	}
	skip_statements = 0;
	emit_statement (cb_build_comment ("END DECLARATIVES"));
  }
    break;

  case 690:
/* Line 1813 of yacc.c  */
#line 5483 "parser.y"
    {
	if (next_label_list) {
		cb_tree	plabel;
		char	name[32];

		snprintf (name, sizeof(name), "L$%d", next_label_id);
		plabel = cb_build_label (cb_build_reference (name), NULL);
		CB_LABEL (plabel)->flag_next_sentence = 1;
		emit_statement (plabel);
		current_program->label_list =
			cb_list_append (current_program->label_list, next_label_list);
		next_label_list = NULL;
		next_label_id++;
	}
	/* check_unreached = 0; */
  }
    break;

  case 692:
/* Line 1813 of yacc.c  */
#line 5501 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 693:
/* Line 1813 of yacc.c  */
#line 5511 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (4)]), 0) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph/section */
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
	}
	if (current_section) {
		if (current_section->exit_label) {
			emit_statement (current_section->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_section));
	}
	if (current_program->flag_debugging && !in_debugging) {
		if (current_paragraph || current_section) {
			emit_statement (cb_build_comment (
					"DEBUGGING - Fall through"));
			emit_statement (cb_build_debug (cb_debug_contents,
					"FALL THROUGH", NULL));
		}
	}

	/* Begin a new section */
	current_section = CB_LABEL (cb_build_label ((yyvsp[(1) - (4)]), NULL));
	if ((yyvsp[(3) - (4)])) {
		current_section->segment = cb_get_int ((yyvsp[(3) - (4)]));
	}
	current_section->flag_section = 1;
	/* Careful here, one negation */
	current_section->flag_real_label = !in_debugging;
	current_section->flag_declaratives = !!in_declaratives;
	current_section->flag_skip_label = !!skip_statements;
	CB_TREE (current_section)->source_file = cb_source_file;
	CB_TREE (current_section)->source_line = cb_source_line;
	current_paragraph = NULL;
  }
    break;

  case 694:
/* Line 1813 of yacc.c  */
#line 5555 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 697:
/* Line 1813 of yacc.c  */
#line 5566 "parser.y"
    {
	cb_tree label;

	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (2)]), 1) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph */
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
		if (current_program->flag_debugging && !in_debugging) {
			emit_statement (cb_build_comment (
					"DEBUGGING - Fall through"));
			emit_statement (cb_build_debug (cb_debug_contents,
					"FALL THROUGH", NULL));
		}
	}

	/* Begin a new paragraph */
	if (!current_section) {
		label = cb_build_reference ("MAIN SECTION");
		current_section = CB_LABEL (cb_build_label (label, NULL));
		current_section->flag_section = 1;
		current_section->flag_dummy_section = 1;
		current_section->flag_declaratives = !!in_declaratives;
		current_section->flag_skip_label = !!skip_statements;
		CB_TREE (current_section)->source_file = cb_source_file;
		CB_TREE (current_section)->source_line = cb_source_line;
		emit_statement (CB_TREE (current_section));
	}
	current_paragraph = CB_LABEL (cb_build_label ((yyvsp[(1) - (2)]), current_section));
	current_paragraph->flag_declaratives =!! in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_real_label = !in_debugging;
	current_paragraph->segment = current_section->segment;
	CB_TREE (current_paragraph)->source_file = cb_source_file;
	CB_TREE (current_paragraph)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_paragraph));
  }
    break;

  case 698:
/* Line 1813 of yacc.c  */
#line 5614 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 699:
/* Line 1813 of yacc.c  */
#line 5626 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 700:
/* Line 1813 of yacc.c  */
#line 5630 "parser.y"
    {
	if (in_declaratives) {
		cb_error (_("SECTION segment invalid within DECLARATIVE"));
	}
	if (cb_verify (cb_section_segments, "SECTION segment")) {
		current_program->flag_segments = 1;
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 701:
/* Line 1813 of yacc.c  */
#line 5648 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 702:
/* Line 1813 of yacc.c  */
#line 5653 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 703:
/* Line 1813 of yacc.c  */
#line 5658 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 704:
/* Line 1813 of yacc.c  */
#line 5666 "parser.y"
    {
	cb_tree label;

	if (!current_section) {
		label = cb_build_reference ("MAIN SECTION");
		current_section = CB_LABEL (cb_build_label (label, NULL));
		current_section->flag_section = 1;
		current_section->flag_dummy_section = 1;
		current_section->flag_skip_label = !!skip_statements;
		current_section->flag_declaratives = !!in_declaratives;
		CB_TREE (current_section)->source_file = cb_source_file;
		CB_TREE (current_section)->source_line = cb_source_line;
		emit_statement (CB_TREE (current_section));
	}
	if (!current_paragraph) {
		label = cb_build_reference ("MAIN PARAGRAPH");
		current_paragraph = CB_LABEL (cb_build_label (label, NULL));
		current_paragraph->flag_declaratives = !!in_declaratives;
		current_paragraph->flag_skip_label = !!skip_statements;
		current_paragraph->flag_dummy_paragraph = 1;
		CB_TREE (current_paragraph)->source_file = cb_source_file;
		CB_TREE (current_paragraph)->source_line = cb_source_line;
		emit_statement (CB_TREE (current_paragraph));
	}
	check_headers_present (COBC_HD_PROCEDURE_DIVISION, 0, 0, 0);
  }
    break;

  case 705:
/* Line 1813 of yacc.c  */
#line 5693 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 706:
/* Line 1813 of yacc.c  */
#line 5697 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 756:
/* Line 1813 of yacc.c  */
#line 5753 "parser.y"
    {
	if (cb_verify (cb_next_sentence_phrase, "NEXT SENTENCE")) {
		cb_tree label;
		char	name[32];

		begin_statement ("NEXT SENTENCE", 0);
		sprintf (name, "L$%d", next_label_id);
		label = cb_build_reference (name);
		next_label_list = cb_list_add (next_label_list, label);
		emit_statement (cb_build_goto (label, NULL));
	}
	check_unreached = 0;
  }
    break;

  case 757:
/* Line 1813 of yacc.c  */
#line 5767 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 758:
/* Line 1813 of yacc.c  */
#line 5778 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 760:
/* Line 1813 of yacc.c  */
#line 5788 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 761:
/* Line 1813 of yacc.c  */
#line 5793 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 762:
/* Line 1813 of yacc.c  */
#line 5797 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 763:
/* Line 1813 of yacc.c  */
#line 5801 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 764:
/* Line 1813 of yacc.c  */
#line 5806 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 765:
/* Line 1813 of yacc.c  */
#line 5811 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 766:
/* Line 1813 of yacc.c  */
#line 5816 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 767:
/* Line 1813 of yacc.c  */
#line 5821 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 768:
/* Line 1813 of yacc.c  */
#line 5825 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 769:
/* Line 1813 of yacc.c  */
#line 5829 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 770:
/* Line 1813 of yacc.c  */
#line 5833 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 771:
/* Line 1813 of yacc.c  */
#line 5837 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 772:
/* Line 1813 of yacc.c  */
#line 5842 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 773:
/* Line 1813 of yacc.c  */
#line 5846 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 774:
/* Line 1813 of yacc.c  */
#line 5850 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 775:
/* Line 1813 of yacc.c  */
#line 5854 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 776:
/* Line 1813 of yacc.c  */
#line 5858 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 777:
/* Line 1813 of yacc.c  */
#line 5862 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 778:
/* Line 1813 of yacc.c  */
#line 5866 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 780:
/* Line 1813 of yacc.c  */
#line 5874 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 783:
/* Line 1813 of yacc.c  */
#line 5885 "parser.y"
    { (yyval) = NULL; }
    break;

  case 784:
/* Line 1813 of yacc.c  */
#line 5886 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 785:
/* Line 1813 of yacc.c  */
#line 5890 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 786:
/* Line 1813 of yacc.c  */
#line 5891 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 787:
/* Line 1813 of yacc.c  */
#line 5892 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 788:
/* Line 1813 of yacc.c  */
#line 5893 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 789:
/* Line 1813 of yacc.c  */
#line 5894 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 790:
/* Line 1813 of yacc.c  */
#line 5898 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 791:
/* Line 1813 of yacc.c  */
#line 5902 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 792:
/* Line 1813 of yacc.c  */
#line 5903 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 796:
/* Line 1813 of yacc.c  */
#line 5912 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 801:
/* Line 1813 of yacc.c  */
#line 5928 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 802:
/* Line 1813 of yacc.c  */
#line 5932 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 803:
/* Line 1813 of yacc.c  */
#line 5936 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 804:
/* Line 1813 of yacc.c  */
#line 5940 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 805:
/* Line 1813 of yacc.c  */
#line 5944 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 806:
/* Line 1813 of yacc.c  */
#line 5948 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 807:
/* Line 1813 of yacc.c  */
#line 5952 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 808:
/* Line 1813 of yacc.c  */
#line 5956 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 809:
/* Line 1813 of yacc.c  */
#line 5960 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 810:
/* Line 1813 of yacc.c  */
#line 5964 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 811:
/* Line 1813 of yacc.c  */
#line 5968 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 812:
/* Line 1813 of yacc.c  */
#line 5972 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 813:
/* Line 1813 of yacc.c  */
#line 5976 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 814:
/* Line 1813 of yacc.c  */
#line 5980 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 815:
/* Line 1813 of yacc.c  */
#line 5984 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 816:
/* Line 1813 of yacc.c  */
#line 5988 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 817:
/* Line 1813 of yacc.c  */
#line 5992 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 818:
/* Line 1813 of yacc.c  */
#line 5996 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 819:
/* Line 1813 of yacc.c  */
#line 6000 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 820:
/* Line 1813 of yacc.c  */
#line 6004 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 821:
/* Line 1813 of yacc.c  */
#line 6008 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 822:
/* Line 1813 of yacc.c  */
#line 6012 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 823:
/* Line 1813 of yacc.c  */
#line 6016 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 824:
/* Line 1813 of yacc.c  */
#line 6020 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 825:
/* Line 1813 of yacc.c  */
#line 6027 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 826:
/* Line 1813 of yacc.c  */
#line 6031 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 827:
/* Line 1813 of yacc.c  */
#line 6041 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 829:
/* Line 1813 of yacc.c  */
#line 6050 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 830:
/* Line 1813 of yacc.c  */
#line 6054 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 831:
/* Line 1813 of yacc.c  */
#line 6058 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 833:
/* Line 1813 of yacc.c  */
#line 6065 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 834:
/* Line 1813 of yacc.c  */
#line 6072 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 835:
/* Line 1813 of yacc.c  */
#line 6076 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 836:
/* Line 1813 of yacc.c  */
#line 6086 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 838:
/* Line 1813 of yacc.c  */
#line 6095 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 839:
/* Line 1813 of yacc.c  */
#line 6099 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 840:
/* Line 1813 of yacc.c  */
#line 6110 "parser.y"
    { (yyval) = NULL; }
    break;

  case 841:
/* Line 1813 of yacc.c  */
#line 6111 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 842:
/* Line 1813 of yacc.c  */
#line 6119 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 846:
/* Line 1813 of yacc.c  */
#line 6133 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 849:
/* Line 1813 of yacc.c  */
#line 6145 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 851:
/* Line 1813 of yacc.c  */
#line 6160 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(2) - (6)])) &&
	    current_program->prog_type == CB_PROGRAM_TYPE &&
	    !current_program->flag_recursive &&
	    !strcmp ((const char *)(CB_LITERAL((yyvsp[(2) - (6)]))->data), current_program->orig_program_id)) {
		cb_warning_x ((yyvsp[(2) - (6)]), _("Recursive program call - assuming RECURSIVE attribute"));
		current_program->flag_recursive = 1;
	}
	cb_emit_call ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]), (yyvsp[(1) - (6)]));
  }
    break;

  case 852:
/* Line 1813 of yacc.c  */
#line 6174 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 853:
/* Line 1813 of yacc.c  */
#line 6179 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 854:
/* Line 1813 of yacc.c  */
#line 6184 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 855:
/* Line 1813 of yacc.c  */
#line 6189 "parser.y"
    {
	cb_tree		x;

	x = cb_ref ((yyvsp[(1) - (1)]));
	if (CB_VALID_TREE (x)) {
		if (CB_SYSTEM_NAME(x)->token != CB_FEATURE_CONVENTION) {
			cb_error_x ((yyvsp[(1) - (1)]), _("Invalid mnemonic name"));
			(yyval) = NULL;
		} else {
			(yyval) = CB_SYSTEM_NAME(x)->value;
		}
	} else {
		(yyval) = NULL;
	}
	cobc_cs_check = 0;
  }
    break;

  case 856:
/* Line 1813 of yacc.c  */
#line 6209 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 857:
/* Line 1813 of yacc.c  */
#line 6213 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 858:
/* Line 1813 of yacc.c  */
#line 6218 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 859:
/* Line 1813 of yacc.c  */
#line 6229 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 860:
/* Line 1813 of yacc.c  */
#line 6231 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 861:
/* Line 1813 of yacc.c  */
#line 6236 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 862:
/* Line 1813 of yacc.c  */
#line 6244 "parser.y"
    {
	int	save_mode;

	save_mode = call_mode;
	if (call_mode != CB_CALL_BY_REFERENCE) {
		if (CB_FILE_P ((yyvsp[(3) - (3)])) || (CB_REFERENCE_P ((yyvsp[(3) - (3)])) &&
		    CB_FILE_P (CB_REFERENCE ((yyvsp[(3) - (3)]))->value))) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid file name reference"));
		} else if (call_mode == CB_CALL_BY_VALUE) {
			if (cb_category_is_alpha ((yyvsp[(3) - (3)]))) {
				cb_warning_x ((yyvsp[(3) - (3)]),
					      _("BY CONTENT assumed for alphanumeric item"));
				save_mode = CB_CALL_BY_CONTENT;
			}
		}
	}
	(yyval) = CB_BUILD_PAIR (cb_int (save_mode), (yyvsp[(3) - (3)]));
	CB_SIZES ((yyval)) = size_mode;
	call_mode = save_mode;
  }
    break;

  case 864:
/* Line 1813 of yacc.c  */
#line 6270 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 865:
/* Line 1813 of yacc.c  */
#line 6274 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 866:
/* Line 1813 of yacc.c  */
#line 6283 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 867:
/* Line 1813 of yacc.c  */
#line 6295 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 868:
/* Line 1813 of yacc.c  */
#line 6299 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 869:
/* Line 1813 of yacc.c  */
#line 6303 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 870:
/* Line 1813 of yacc.c  */
#line 6307 "parser.y"
    {
	struct cb_field	*f;

	if (cb_ref ((yyvsp[(4) - (4)])) != cb_error_node) {
		f = CB_FIELD_PTR ((yyvsp[(4) - (4)]));
		if (f->level != 1 && f->level != 77) {
			cb_error (_("RETURNING item must have level 01 or 77"));
			(yyval) = NULL;
		} else if (f->storage != CB_STORAGE_LINKAGE &&
			   !f->flag_item_based) {
			cb_error (_("RETURNING item is neither in LINKAGE SECTION nor is it BASED"));
			(yyval) = NULL;
		} else {
			(yyval) = cb_build_address ((yyvsp[(4) - (4)]));
		}
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 875:
/* Line 1813 of yacc.c  */
#line 6340 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 876:
/* Line 1813 of yacc.c  */
#line 6345 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 877:
/* Line 1813 of yacc.c  */
#line 6352 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 878:
/* Line 1813 of yacc.c  */
#line 6357 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 879:
/* Line 1813 of yacc.c  */
#line 6364 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 880:
/* Line 1813 of yacc.c  */
#line 6368 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 881:
/* Line 1813 of yacc.c  */
#line 6378 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 883:
/* Line 1813 of yacc.c  */
#line 6386 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 884:
/* Line 1813 of yacc.c  */
#line 6390 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 885:
/* Line 1813 of yacc.c  */
#line 6400 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 887:
/* Line 1813 of yacc.c  */
#line 6408 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 888:
/* Line 1813 of yacc.c  */
#line 6413 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 889:
/* Line 1813 of yacc.c  */
#line 6420 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 890:
/* Line 1813 of yacc.c  */
#line 6421 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 891:
/* Line 1813 of yacc.c  */
#line 6422 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 892:
/* Line 1813 of yacc.c  */
#line 6423 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 893:
/* Line 1813 of yacc.c  */
#line 6424 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 894:
/* Line 1813 of yacc.c  */
#line 6432 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 896:
/* Line 1813 of yacc.c  */
#line 6441 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 897:
/* Line 1813 of yacc.c  */
#line 6448 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 898:
/* Line 1813 of yacc.c  */
#line 6452 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 899:
/* Line 1813 of yacc.c  */
#line 6462 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 900:
/* Line 1813 of yacc.c  */
#line 6473 "parser.y"
    {
	size_t	save_unreached;

	/* Do not check unreached for CONTINUE */
	save_unreached = check_unreached;
	check_unreached = 0;
	begin_statement ("CONTINUE", 0);
	cb_emit_continue ();
	check_unreached = save_unreached;
  }
    break;

  case 901:
/* Line 1813 of yacc.c  */
#line 6490 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 903:
/* Line 1813 of yacc.c  */
#line 6499 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 905:
/* Line 1813 of yacc.c  */
#line 6507 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 906:
/* Line 1813 of yacc.c  */
#line 6512 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 907:
/* Line 1813 of yacc.c  */
#line 6520 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 908:
/* Line 1813 of yacc.c  */
#line 6524 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 909:
/* Line 1813 of yacc.c  */
#line 6534 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 911:
/* Line 1813 of yacc.c  */
#line 6544 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 912:
/* Line 1813 of yacc.c  */
#line 6548 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 913:
/* Line 1813 of yacc.c  */
#line 6552 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 914:
/* Line 1813 of yacc.c  */
#line 6556 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 915:
/* Line 1813 of yacc.c  */
#line 6560 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 917:
/* Line 1813 of yacc.c  */
#line 6565 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 919:
/* Line 1813 of yacc.c  */
#line 6575 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 921:
/* Line 1813 of yacc.c  */
#line 6583 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 922:
/* Line 1813 of yacc.c  */
#line 6591 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 923:
/* Line 1813 of yacc.c  */
#line 6599 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 924:
/* Line 1813 of yacc.c  */
#line 6603 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 925:
/* Line 1813 of yacc.c  */
#line 6607 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 926:
/* Line 1813 of yacc.c  */
#line 6611 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 932:
/* Line 1813 of yacc.c  */
#line 6633 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 933:
/* Line 1813 of yacc.c  */
#line 6639 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 934:
/* Line 1813 of yacc.c  */
#line 6640 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 937:
/* Line 1813 of yacc.c  */
#line 6651 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 938:
/* Line 1813 of yacc.c  */
#line 6655 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 939:
/* Line 1813 of yacc.c  */
#line 6659 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 940:
/* Line 1813 of yacc.c  */
#line 6663 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 941:
/* Line 1813 of yacc.c  */
#line 6667 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 942:
/* Line 1813 of yacc.c  */
#line 6671 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 943:
/* Line 1813 of yacc.c  */
#line 6675 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 944:
/* Line 1813 of yacc.c  */
#line 6679 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 945:
/* Line 1813 of yacc.c  */
#line 6683 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 946:
/* Line 1813 of yacc.c  */
#line 6687 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 947:
/* Line 1813 of yacc.c  */
#line 6691 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 948:
/* Line 1813 of yacc.c  */
#line 6695 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 949:
/* Line 1813 of yacc.c  */
#line 6699 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 950:
/* Line 1813 of yacc.c  */
#line 6703 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 951:
/* Line 1813 of yacc.c  */
#line 6707 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 952:
/* Line 1813 of yacc.c  */
#line 6711 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 953:
/* Line 1813 of yacc.c  */
#line 6718 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 954:
/* Line 1813 of yacc.c  */
#line 6722 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 955:
/* Line 1813 of yacc.c  */
#line 6732 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 957:
/* Line 1813 of yacc.c  */
#line 6741 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 958:
/* Line 1813 of yacc.c  */
#line 6745 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 959:
/* Line 1813 of yacc.c  */
#line 6749 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 960:
/* Line 1813 of yacc.c  */
#line 6753 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 961:
/* Line 1813 of yacc.c  */
#line 6757 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 962:
/* Line 1813 of yacc.c  */
#line 6764 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 963:
/* Line 1813 of yacc.c  */
#line 6768 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 964:
/* Line 1813 of yacc.c  */
#line 6778 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 966:
/* Line 1813 of yacc.c  */
#line 6786 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("ENTRY is invalid in nested program"));
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("ENTRY is invalid in a user FUNCTION"));
	} else if (cb_verify (cb_entry_statement, "ENTRY")) {
		if (!cobc_check_valid_name ((char *)(CB_LITERAL ((yyvsp[(1) - (2)]))->data), 1U)) {
			emit_entry ((char *)(CB_LITERAL ((yyvsp[(1) - (2)]))->data), 1, (yyvsp[(2) - (2)]));
		}
	}
	check_unreached = 0;
  }
    break;

  case 967:
/* Line 1813 of yacc.c  */
#line 6805 "parser.y"
    {
	begin_statement ("EVALUATE", TERM_EVALUATE);
	eval_level++;
	if (eval_level >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_level = 0;
		eval_inc = 0;
		eval_inc2 = 0;
		YYERROR;
	} else {
		for (eval_inc = 0; eval_inc < EVAL_DEPTH; ++eval_inc) {
			eval_check[eval_level][eval_inc] = NULL;
		}
		eval_inc = 0;
		eval_inc2 = 0;
	}
  }
    break;

  case 969:
/* Line 1813 of yacc.c  */
#line 6829 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 970:
/* Line 1813 of yacc.c  */
#line 6836 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 971:
/* Line 1813 of yacc.c  */
#line 6838 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 972:
/* Line 1813 of yacc.c  */
#line 6843 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	eval_check[eval_level][eval_inc++] = (yyvsp[(1) - (1)]);
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
    break;

  case 973:
/* Line 1813 of yacc.c  */
#line 6854 "parser.y"
    {
	(yyval) = cb_true;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
    break;

  case 974:
/* Line 1813 of yacc.c  */
#line 6865 "parser.y"
    {
	(yyval) = cb_false;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
    break;

  case 975:
/* Line 1813 of yacc.c  */
#line 6879 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 976:
/* Line 1813 of yacc.c  */
#line 6883 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 977:
/* Line 1813 of yacc.c  */
#line 6889 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 978:
/* Line 1813 of yacc.c  */
#line 6891 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 979:
/* Line 1813 of yacc.c  */
#line 6897 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 980:
/* Line 1813 of yacc.c  */
#line 6906 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 981:
/* Line 1813 of yacc.c  */
#line 6914 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 982:
/* Line 1813 of yacc.c  */
#line 6920 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 983:
/* Line 1813 of yacc.c  */
#line 6927 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 984:
/* Line 1813 of yacc.c  */
#line 6929 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 985:
/* Line 1813 of yacc.c  */
#line 6934 "parser.y"
    {
	cb_tree	not;
	cb_tree	e1;
	cb_tree	e2;
	cb_tree	x;
	cb_tree	parm1;

	not = cb_int0;
	e2 = (yyvsp[(2) - (2)]);
	x = NULL;
	parm1 = (yyvsp[(1) - (2)]);
	if (eval_check[eval_level][eval_inc2]) {
		/* Check if the first token is NOT */
		/* It may belong to the EVALUATE, however see */
		/* below when it may be part of a partial expression */
		if (CB_PURPOSE_INT (parm1) == '!') {
			/* Pop stack if subject not TRUE / FALSE */
			not = cb_int1;
			x = parm1;
			parm1 = CB_CHAIN (parm1);
		}
		/* Partial expression handling */
		switch (CB_PURPOSE_INT (parm1)) {
		/* Relational conditions */
		case '<':
		case '>':
		case '[':
		case ']':
		case '~':
		case '=':
		/* Class conditions */
		case '9':
		case 'A':
		case 'L':
		case 'U':
		case 'P':
		case 'N':
		case 'O':
		case 'C':
			if (e2) {
				cb_error_x (e2, _("Invalid THROUGH usage"));
				e2 = NULL;
			}
			not = CB_PURPOSE (parm1);
			if (x) {
				/* Rebind the NOT to the partial expression */
				parm1 = cb_build_list (cb_int ('!'), NULL, parm1);
			}
			/* Insert subject at head of list */
			parm1 = cb_build_list (cb_int ('x'),
					    eval_check[eval_level][eval_inc2], parm1);
			break;
		}
	}

	/* Build expr now */
	e1 = cb_build_expr (parm1);

	eval_inc2++;
	(yyval) = CB_BUILD_PAIR (not, CB_BUILD_PAIR (e1, e2));
  }
    break;

  case 986:
/* Line 1813 of yacc.c  */
#line 6995 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 987:
/* Line 1813 of yacc.c  */
#line 6996 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 988:
/* Line 1813 of yacc.c  */
#line 6997 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 989:
/* Line 1813 of yacc.c  */
#line 7001 "parser.y"
    { (yyval) = NULL; }
    break;

  case 990:
/* Line 1813 of yacc.c  */
#line 7002 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 991:
/* Line 1813 of yacc.c  */
#line 7007 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 992:
/* Line 1813 of yacc.c  */
#line 7011 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 993:
/* Line 1813 of yacc.c  */
#line 7021 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 994:
/* Line 1813 of yacc.c  */
#line 7026 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 996:
/* Line 1813 of yacc.c  */
#line 7034 "parser.y"
    {
	if (in_declaratives && use_global_ind) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PROGRAM is not allowed within a USE GLOBAL procedure"));
	}
	if (current_program->prog_type != CB_PROGRAM_TYPE) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PROGRAM only allowed within a PROGRAM type"));
	}
	if (current_program->flag_main) {
		check_unreached = 0;
	} else {
		check_unreached = 1;
	}
	current_statement->name = (const char *)"EXIT PROGRAM";
	cb_emit_exit (0);
  }
    break;

  case 997:
/* Line 1813 of yacc.c  */
#line 7052 "parser.y"
    {
	if (in_declaratives && use_global_ind) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT FUNCTION is not allowed within a USE GLOBAL procedure"));
	}
	if (current_program->prog_type != CB_FUNCTION_TYPE) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT FUNCTION only allowed within a FUNCTION type"));
	}
	check_unreached = 1;
	current_statement->name = (const char *)"EXIT FUNCTION";
	cb_emit_exit (0);
  }
    break;

  case 998:
/* Line 1813 of yacc.c  */
#line 7066 "parser.y"
    {
	struct cb_perform	*p;
	cb_tree			plabel;
	char			name[64];

	if (!perform_stack) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PERFORM is only valid with inline PERFORM"));
	} else if (CB_VALUE (perform_stack) != cb_error_node) {
		p = CB_PERFORM (CB_VALUE (perform_stack));
		if (!p->cycle_label) {
			sprintf (name, "EXIT PERFORM CYCLE %d", cb_id);
			p->cycle_label = cb_build_reference (name);
			plabel = cb_build_label (p->cycle_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PERFORM CYCLE";
		cb_emit_goto (CB_LIST_INIT (p->cycle_label), NULL);
	}
  }
    break;

  case 999:
/* Line 1813 of yacc.c  */
#line 7088 "parser.y"
    {
	struct cb_perform	*p;
	cb_tree			plabel;
	char			name[64];

	if (!perform_stack) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PERFORM is only valid with inline PERFORM"));
	} else if (CB_VALUE (perform_stack) != cb_error_node) {
		p = CB_PERFORM (CB_VALUE (perform_stack));
		if (!p->exit_label) {
			sprintf (name, "EXIT PERFORM %d", cb_id);
			p->exit_label = cb_build_reference (name);
			plabel = cb_build_label (p->exit_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PERFORM";
		cb_emit_goto (CB_LIST_INIT (p->exit_label), NULL);
	}
  }
    break;

  case 1000:
/* Line 1813 of yacc.c  */
#line 7110 "parser.y"
    {
	cb_tree	plabel;
	char	name[64];

	if (!current_section) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT SECTION is only valid with an active SECTION"));
	} else {
		if (!current_section->exit_label) {
			sprintf (name, "EXIT SECTION %d", cb_id);
			current_section->exit_label = cb_build_reference (name);
			plabel = cb_build_label (current_section->exit_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT SECTION";
		cb_emit_goto (CB_LIST_INIT (current_section->exit_label), NULL);
	}
  }
    break;

  case 1001:
/* Line 1813 of yacc.c  */
#line 7130 "parser.y"
    {
	cb_tree	plabel;
	char	name[64];

	if (!current_paragraph) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PARAGRAPH is only valid with an active PARAGRAPH"));
	} else {
		if (!current_paragraph->exit_label) {
			sprintf (name, "EXIT PARAGRAPH %d", cb_id);
			current_paragraph->exit_label = cb_build_reference (name);
			plabel = cb_build_label (current_paragraph->exit_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PARAGRAPH";
		cb_emit_goto (CB_LIST_INIT (current_paragraph->exit_label), NULL);
	}
  }
    break;

  case 1002:
/* Line 1813 of yacc.c  */
#line 7155 "parser.y"
    {
	begin_statement ("FREE", 0);
  }
    break;

  case 1004:
/* Line 1813 of yacc.c  */
#line 7163 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 1005:
/* Line 1813 of yacc.c  */
#line 7173 "parser.y"
    {
	begin_statement ("GENERATE", 0);
  }
    break;

  case 1007:
/* Line 1813 of yacc.c  */
#line 7182 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
		cb_emit_generate((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1008:
/* Line 1813 of yacc.c  */
#line 7194 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1010:
/* Line 1813 of yacc.c  */
#line 7207 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1011:
/* Line 1813 of yacc.c  */
#line 7215 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1012:
/* Line 1813 of yacc.c  */
#line 7220 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1013:
/* Line 1813 of yacc.c  */
#line 7231 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	cb_emit_exit (1U);
  }
    break;

  case 1014:
/* Line 1813 of yacc.c  */
#line 7243 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1016:
/* Line 1813 of yacc.c  */
#line 7252 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1017:
/* Line 1813 of yacc.c  */
#line 7256 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1018:
/* Line 1813 of yacc.c  */
#line 7260 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1019:
/* Line 1813 of yacc.c  */
#line 7267 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1020:
/* Line 1813 of yacc.c  */
#line 7271 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1021:
/* Line 1813 of yacc.c  */
#line 7281 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1023:
/* Line 1813 of yacc.c  */
#line 7290 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1024:
/* Line 1813 of yacc.c  */
#line 7296 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1025:
/* Line 1813 of yacc.c  */
#line 7297 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1026:
/* Line 1813 of yacc.c  */
#line 7301 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1027:
/* Line 1813 of yacc.c  */
#line 7302 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1028:
/* Line 1813 of yacc.c  */
#line 7303 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1029:
/* Line 1813 of yacc.c  */
#line 7308 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1030:
/* Line 1813 of yacc.c  */
#line 7312 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1031:
/* Line 1813 of yacc.c  */
#line 7319 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1032:
/* Line 1813 of yacc.c  */
#line 7324 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1033:
/* Line 1813 of yacc.c  */
#line 7331 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1034:
/* Line 1813 of yacc.c  */
#line 7337 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1035:
/* Line 1813 of yacc.c  */
#line 7338 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1036:
/* Line 1813 of yacc.c  */
#line 7339 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1037:
/* Line 1813 of yacc.c  */
#line 7340 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1038:
/* Line 1813 of yacc.c  */
#line 7341 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1039:
/* Line 1813 of yacc.c  */
#line 7342 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1040:
/* Line 1813 of yacc.c  */
#line 7343 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1041:
/* Line 1813 of yacc.c  */
#line 7348 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1042:
/* Line 1813 of yacc.c  */
#line 7352 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1043:
/* Line 1813 of yacc.c  */
#line 7361 "parser.y"
    {
	begin_statement ("INITIATE", 0);
  }
    break;

  case 1045:
/* Line 1813 of yacc.c  */
#line 7369 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	    cb_emit_initiate((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1046:
/* Line 1813 of yacc.c  */
#line 7376 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	    cb_emit_initiate((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1047:
/* Line 1813 of yacc.c  */
#line 7388 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1050:
/* Line 1813 of yacc.c  */
#line 7401 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1051:
/* Line 1813 of yacc.c  */
#line 7405 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1052:
/* Line 1813 of yacc.c  */
#line 7409 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1057:
/* Line 1813 of yacc.c  */
#line 7425 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1058:
/* Line 1813 of yacc.c  */
#line 7429 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1059:
/* Line 1813 of yacc.c  */
#line 7439 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1060:
/* Line 1813 of yacc.c  */
#line 7449 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1061:
/* Line 1813 of yacc.c  */
#line 7457 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1062:
/* Line 1813 of yacc.c  */
#line 7458 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1063:
/* Line 1813 of yacc.c  */
#line 7462 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1064:
/* Line 1813 of yacc.c  */
#line 7463 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1065:
/* Line 1813 of yacc.c  */
#line 7464 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1066:
/* Line 1813 of yacc.c  */
#line 7465 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1067:
/* Line 1813 of yacc.c  */
#line 7466 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1068:
/* Line 1813 of yacc.c  */
#line 7467 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1069:
/* Line 1813 of yacc.c  */
#line 7471 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1070:
/* Line 1813 of yacc.c  */
#line 7472 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1071:
/* Line 1813 of yacc.c  */
#line 7477 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1072:
/* Line 1813 of yacc.c  */
#line 7482 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1073:
/* Line 1813 of yacc.c  */
#line 7488 "parser.y"
    { /* Nothing */ }
    break;

  case 1074:
/* Line 1813 of yacc.c  */
#line 7489 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1075:
/* Line 1813 of yacc.c  */
#line 7490 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1076:
/* Line 1813 of yacc.c  */
#line 7491 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1077:
/* Line 1813 of yacc.c  */
#line 7492 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1078:
/* Line 1813 of yacc.c  */
#line 7497 "parser.y"
    {
	switch (inspect_keyword) {
		case 1:
			(yyval) = cb_build_replacing_all ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 2:
			(yyval) = cb_build_replacing_leading ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 3:
			(yyval) = cb_build_replacing_first ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 4:
			(yyval) = cb_build_replacing_trailing ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		default:
			cb_error_x (CB_TREE (current_statement),
				    _("INSPECT missing a keyword"));
			(yyval) = cb_build_replacing_all ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
	}
  }
    break;

  case 1079:
/* Line 1813 of yacc.c  */
#line 7524 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1080:
/* Line 1813 of yacc.c  */
#line 7528 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1081:
/* Line 1813 of yacc.c  */
#line 7535 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1082:
/* Line 1813 of yacc.c  */
#line 7539 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1083:
/* Line 1813 of yacc.c  */
#line 7548 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1085:
/* Line 1813 of yacc.c  */
#line 7560 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1087:
/* Line 1813 of yacc.c  */
#line 7568 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1088:
/* Line 1813 of yacc.c  */
#line 7572 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1089:
/* Line 1813 of yacc.c  */
#line 7582 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1091:
/* Line 1813 of yacc.c  */
#line 7591 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1092:
/* Line 1813 of yacc.c  */
#line 7595 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1093:
/* Line 1813 of yacc.c  */
#line 7602 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1094:
/* Line 1813 of yacc.c  */
#line 7606 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1095:
/* Line 1813 of yacc.c  */
#line 7616 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1097:
/* Line 1813 of yacc.c  */
#line 7624 "parser.y"
    {
	cb_tree l;
	cb_tree x;

	if ((yyvsp[(2) - (4)]) && (yyvsp[(4) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	if ((yyvsp[(4) - (4)])) {
		x = (yyvsp[(4) - (4)]);
	} else {
		x = (yyvsp[(2) - (4)]);
	}
	for (l = (yyvsp[(3) - (4)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(1) - (4)]), x);
		}
	}
  }
    break;

  case 1098:
/* Line 1813 of yacc.c  */
#line 7645 "parser.y"
    {
	cb_tree l;
	cb_tree x;

	if ((yyvsp[(3) - (5)]) && (yyvsp[(5) - (5)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	if ((yyvsp[(5) - (5)])) {
		x = (yyvsp[(5) - (5)]);
	} else {
		x = (yyvsp[(3) - (5)]);
	}
	for (l = (yyvsp[(4) - (5)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(2) - (5)]), x);
		}
	}
  }
    break;

  case 1099:
/* Line 1813 of yacc.c  */
#line 7668 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1100:
/* Line 1813 of yacc.c  */
#line 7669 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1101:
/* Line 1813 of yacc.c  */
#line 7670 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1102:
/* Line 1813 of yacc.c  */
#line 7671 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1103:
/* Line 1813 of yacc.c  */
#line 7675 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1104:
/* Line 1813 of yacc.c  */
#line 7676 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1105:
/* Line 1813 of yacc.c  */
#line 7680 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1106:
/* Line 1813 of yacc.c  */
#line 7681 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1107:
/* Line 1813 of yacc.c  */
#line 7682 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1108:
/* Line 1813 of yacc.c  */
#line 7684 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1109:
/* Line 1813 of yacc.c  */
#line 7695 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1111:
/* Line 1813 of yacc.c  */
#line 7706 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1112:
/* Line 1813 of yacc.c  */
#line 7711 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1113:
/* Line 1813 of yacc.c  */
#line 7717 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1114:
/* Line 1813 of yacc.c  */
#line 7722 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1115:
/* Line 1813 of yacc.c  */
#line 7730 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1116:
/* Line 1813 of yacc.c  */
#line 7738 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1117:
/* Line 1813 of yacc.c  */
#line 7745 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1118:
/* Line 1813 of yacc.c  */
#line 7749 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-2) - (1)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-2) - (1)]), PERFORM);
	}
	/* Put the dot token back into the stack for reparse */
	cb_unput_dot ();
  }
    break;

  case 1119:
/* Line 1813 of yacc.c  */
#line 7762 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1120:
/* Line 1813 of yacc.c  */
#line 7769 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1121:
/* Line 1813 of yacc.c  */
#line 7780 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1122:
/* Line 1813 of yacc.c  */
#line 7784 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1123:
/* Line 1813 of yacc.c  */
#line 7789 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1124:
/* Line 1813 of yacc.c  */
#line 7793 "parser.y"
    {
	cb_tree varying;

	if (!(yyvsp[(3) - (3)])) {
		(yyval) = cb_build_perform_forever (NULL);
	} else {
		varying = CB_LIST_INIT (cb_build_perform_varying (NULL, NULL, NULL, (yyvsp[(3) - (3)])));
		(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), varying);
	}
  }
    break;

  case 1125:
/* Line 1813 of yacc.c  */
#line 7804 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1126:
/* Line 1813 of yacc.c  */
#line 7810 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1127:
/* Line 1813 of yacc.c  */
#line 7811 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1128:
/* Line 1813 of yacc.c  */
#line 7815 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1129:
/* Line 1813 of yacc.c  */
#line 7816 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1130:
/* Line 1813 of yacc.c  */
#line 7819 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1131:
/* Line 1813 of yacc.c  */
#line 7821 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1132:
/* Line 1813 of yacc.c  */
#line 7826 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1133:
/* Line 1813 of yacc.c  */
#line 7836 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1135:
/* Line 1813 of yacc.c  */
#line 7845 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		struct cb_file	*cf;

		cf = CB_FILE(cb_ref ((yyvsp[(1) - (7)])));
		if ((yyvsp[(5) - (7)]) && (cf->lock_mode & COB_LOCK_AUTOMATIC)) {
			cb_error_x (CB_TREE (current_statement),
				    _("LOCK clause invalid with file LOCK AUTOMATIC"));
		} else if ((yyvsp[(6) - (7)]) &&
		      (cf->organization != COB_ORG_RELATIVE &&
		       cf->organization != COB_ORG_INDEXED)) {
			cb_error_x (CB_TREE (current_statement),
				    _("KEY clause invalid with this file type"));
		} else if (current_statement->handler_id == COB_EC_I_O_INVALID_KEY &&
			   (cf->organization != COB_ORG_RELATIVE &&
			    cf->organization != COB_ORG_INDEXED)) {
			cb_error_x (CB_TREE (current_statement),
				    _("INVALID KEY clause invalid with this file type"));
		} else {
			cb_emit_read ((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(5) - (7)]));
		}
	}
  }
    break;

  case 1136:
/* Line 1813 of yacc.c  */
#line 7871 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1137:
/* Line 1813 of yacc.c  */
#line 7872 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1138:
/* Line 1813 of yacc.c  */
#line 7877 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1139:
/* Line 1813 of yacc.c  */
#line 7881 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1140:
/* Line 1813 of yacc.c  */
#line 7885 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1141:
/* Line 1813 of yacc.c  */
#line 7889 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1142:
/* Line 1813 of yacc.c  */
#line 7893 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1143:
/* Line 1813 of yacc.c  */
#line 7897 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1144:
/* Line 1813 of yacc.c  */
#line 7901 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1145:
/* Line 1813 of yacc.c  */
#line 7907 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1146:
/* Line 1813 of yacc.c  */
#line 7908 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1149:
/* Line 1813 of yacc.c  */
#line 7918 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1150:
/* Line 1813 of yacc.c  */
#line 7922 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1151:
/* Line 1813 of yacc.c  */
#line 7932 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1152:
/* Line 1813 of yacc.c  */
#line 7942 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1154:
/* Line 1813 of yacc.c  */
#line 7950 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1155:
/* Line 1813 of yacc.c  */
#line 7960 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1156:
/* Line 1813 of yacc.c  */
#line 7970 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1158:
/* Line 1813 of yacc.c  */
#line 7979 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1159:
/* Line 1813 of yacc.c  */
#line 7986 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1160:
/* Line 1813 of yacc.c  */
#line 7990 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1161:
/* Line 1813 of yacc.c  */
#line 8000 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1163:
/* Line 1813 of yacc.c  */
#line 8012 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1164:
/* Line 1813 of yacc.c  */
#line 8020 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1165:
/* Line 1813 of yacc.c  */
#line 8024 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1166:
/* Line 1813 of yacc.c  */
#line 8028 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1167:
/* Line 1813 of yacc.c  */
#line 8035 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1168:
/* Line 1813 of yacc.c  */
#line 8039 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1169:
/* Line 1813 of yacc.c  */
#line 8049 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1170:
/* Line 1813 of yacc.c  */
#line 8060 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1172:
/* Line 1813 of yacc.c  */
#line 8069 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1173:
/* Line 1813 of yacc.c  */
#line 8074 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1174:
/* Line 1813 of yacc.c  */
#line 8081 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1175:
/* Line 1813 of yacc.c  */
#line 8082 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1176:
/* Line 1813 of yacc.c  */
#line 8087 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1177:
/* Line 1813 of yacc.c  */
#line 8092 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1178:
/* Line 1813 of yacc.c  */
#line 8099 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1179:
/* Line 1813 of yacc.c  */
#line 8103 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1180:
/* Line 1813 of yacc.c  */
#line 8111 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1181:
/* Line 1813 of yacc.c  */
#line 8118 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1182:
/* Line 1813 of yacc.c  */
#line 8122 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1183:
/* Line 1813 of yacc.c  */
#line 8132 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1184:
/* Line 1813 of yacc.c  */
#line 8139 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1191:
/* Line 1813 of yacc.c  */
#line 8154 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1192:
/* Line 1813 of yacc.c  */
#line 8155 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1193:
/* Line 1813 of yacc.c  */
#line 8159 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1194:
/* Line 1813 of yacc.c  */
#line 8160 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1195:
/* Line 1813 of yacc.c  */
#line 8167 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1196:
/* Line 1813 of yacc.c  */
#line 8176 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1199:
/* Line 1813 of yacc.c  */
#line 8188 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1200:
/* Line 1813 of yacc.c  */
#line 8192 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1201:
/* Line 1813 of yacc.c  */
#line 8196 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1202:
/* Line 1813 of yacc.c  */
#line 8200 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1203:
/* Line 1813 of yacc.c  */
#line 8204 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1204:
/* Line 1813 of yacc.c  */
#line 8208 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1205:
/* Line 1813 of yacc.c  */
#line 8212 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1206:
/* Line 1813 of yacc.c  */
#line 8216 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1207:
/* Line 1813 of yacc.c  */
#line 8225 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1208:
/* Line 1813 of yacc.c  */
#line 8229 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1209:
/* Line 1813 of yacc.c  */
#line 8238 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1212:
/* Line 1813 of yacc.c  */
#line 8252 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1215:
/* Line 1813 of yacc.c  */
#line 8266 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1216:
/* Line 1813 of yacc.c  */
#line 8270 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1217:
/* Line 1813 of yacc.c  */
#line 8280 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1219:
/* Line 1813 of yacc.c  */
#line 8288 "parser.y"
    {
	cb_tree		x;

	x = cb_ref ((yyvsp[(1) - (4)]));
	if (CB_VALID_TREE (x)) {
		if (CB_INVALID_TREE ((yyvsp[(2) - (4)]))) {
			if (CB_FILE_P (x)) {
				cb_error (_("File sort requires KEY phrase"));
			} else {
				cb_error (_("Table sort without keys not implemented yet"));
			}
			(yyval) = NULL;
		} else {
			cb_emit_sort_init ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			(yyval)= (yyvsp[(1) - (4)]);
		}
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 1220:
/* Line 1813 of yacc.c  */
#line 8309 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1221:
/* Line 1813 of yacc.c  */
#line 8318 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1222:
/* Line 1813 of yacc.c  */
#line 8323 "parser.y"
    {
	cb_tree l;
	cb_tree lparm;

	if ((yyvsp[(5) - (5)]) == NULL) {
		l = CB_LIST_INIT (NULL);
	} else {
		l = (yyvsp[(5) - (5)]);
	}
	lparm = l;
	for (; l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = (yyvsp[(3) - (5)]);
	}
	(yyval) = cb_list_append ((yyvsp[(1) - (5)]), lparm);
  }
    break;

  case 1223:
/* Line 1813 of yacc.c  */
#line 8341 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1224:
/* Line 1813 of yacc.c  */
#line 8342 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1226:
/* Line 1813 of yacc.c  */
#line 8347 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1227:
/* Line 1813 of yacc.c  */
#line 8354 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1228:
/* Line 1813 of yacc.c  */
#line 8355 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1229:
/* Line 1813 of yacc.c  */
#line 8360 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1230:
/* Line 1813 of yacc.c  */
#line 8366 "parser.y"
    {
	if ((yyvsp[(0) - (2)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(0) - (2)])))) {
			cb_error (_("USING invalid with table SORT"));
		} else {
			cb_emit_sort_using ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  }
    break;

  case 1231:
/* Line 1813 of yacc.c  */
#line 8376 "parser.y"
    {
	if ((yyvsp[(0) - (4)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(0) - (4)])))) {
			cb_error (_("INPUT PROCEDURE invalid with table SORT"));
		} else if (current_statement->flag_merge) {
			cb_error (_("INPUT PROCEDURE invalid with MERGE"));
		} else {
			cb_emit_sort_input ((yyvsp[(4) - (4)]));
		}
	}
  }
    break;

  case 1232:
/* Line 1813 of yacc.c  */
#line 8391 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1233:
/* Line 1813 of yacc.c  */
#line 8397 "parser.y"
    {
	if ((yyvsp[(-1) - (2)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(-1) - (2)])))) {
			cb_error (_("GIVING invalid with table SORT"));
		} else {
			cb_emit_sort_giving ((yyvsp[(-1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  }
    break;

  case 1234:
/* Line 1813 of yacc.c  */
#line 8407 "parser.y"
    {
	if ((yyvsp[(-1) - (4)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(-1) - (4)])))) {
			cb_error (_("OUTPUT PROCEDURE invalid with table SORT"));
		} else {
			cb_emit_sort_output ((yyvsp[(4) - (4)]));
		}
	}
  }
    break;

  case 1235:
/* Line 1813 of yacc.c  */
#line 8423 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1237:
/* Line 1813 of yacc.c  */
#line 8433 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1238:
/* Line 1813 of yacc.c  */
#line 8445 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1239:
/* Line 1813 of yacc.c  */
#line 8449 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1240:
/* Line 1813 of yacc.c  */
#line 8456 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1241:
/* Line 1813 of yacc.c  */
#line 8460 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1242:
/* Line 1813 of yacc.c  */
#line 8465 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1243:
/* Line 1813 of yacc.c  */
#line 8470 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1244:
/* Line 1813 of yacc.c  */
#line 8477 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1245:
/* Line 1813 of yacc.c  */
#line 8478 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1246:
/* Line 1813 of yacc.c  */
#line 8479 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1247:
/* Line 1813 of yacc.c  */
#line 8480 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1248:
/* Line 1813 of yacc.c  */
#line 8481 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1249:
/* Line 1813 of yacc.c  */
#line 8482 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1250:
/* Line 1813 of yacc.c  */
#line 8487 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1253:
/* Line 1813 of yacc.c  */
#line 8500 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1254:
/* Line 1813 of yacc.c  */
#line 8504 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1255:
/* Line 1813 of yacc.c  */
#line 8514 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1256:
/* Line 1813 of yacc.c  */
#line 8518 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1257:
/* Line 1813 of yacc.c  */
#line 8524 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
    break;

  case 1258:
/* Line 1813 of yacc.c  */
#line 8536 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1259:
/* Line 1813 of yacc.c  */
#line 8540 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1260:
/* Line 1813 of yacc.c  */
#line 8544 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1261:
/* Line 1813 of yacc.c  */
#line 8548 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1262:
/* Line 1813 of yacc.c  */
#line 8556 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1263:
/* Line 1813 of yacc.c  */
#line 8567 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1264:
/* Line 1813 of yacc.c  */
#line 8571 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1265:
/* Line 1813 of yacc.c  */
#line 8577 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1266:
/* Line 1813 of yacc.c  */
#line 8578 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1267:
/* Line 1813 of yacc.c  */
#line 8579 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1268:
/* Line 1813 of yacc.c  */
#line 8580 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1269:
/* Line 1813 of yacc.c  */
#line 8587 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1271:
/* Line 1813 of yacc.c  */
#line 8596 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1272:
/* Line 1813 of yacc.c  */
#line 8602 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1273:
/* Line 1813 of yacc.c  */
#line 8603 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1274:
/* Line 1813 of yacc.c  */
#line 8607 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1275:
/* Line 1813 of yacc.c  */
#line 8608 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1276:
/* Line 1813 of yacc.c  */
#line 8609 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1277:
/* Line 1813 of yacc.c  */
#line 8613 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1278:
/* Line 1813 of yacc.c  */
#line 8614 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1279:
/* Line 1813 of yacc.c  */
#line 8619 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1280:
/* Line 1813 of yacc.c  */
#line 8623 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1281:
/* Line 1813 of yacc.c  */
#line 8633 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1283:
/* Line 1813 of yacc.c  */
#line 8642 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1284:
/* Line 1813 of yacc.c  */
#line 8646 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1285:
/* Line 1813 of yacc.c  */
#line 8650 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1286:
/* Line 1813 of yacc.c  */
#line 8657 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1287:
/* Line 1813 of yacc.c  */
#line 8661 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1288:
/* Line 1813 of yacc.c  */
#line 8671 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	cb_emit_suppress(control_field);
  }
    break;

  case 1291:
/* Line 1813 of yacc.c  */
#line 8689 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
  }
    break;

  case 1293:
/* Line 1813 of yacc.c  */
#line 8697 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	    cb_emit_terminate((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1294:
/* Line 1813 of yacc.c  */
#line 8704 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	    cb_emit_terminate((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1295:
/* Line 1813 of yacc.c  */
#line 8716 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1297:
/* Line 1813 of yacc.c  */
#line 8724 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1298:
/* Line 1813 of yacc.c  */
#line 8737 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1300:
/* Line 1813 of yacc.c  */
#line 8745 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (2)]))) {
		if (CB_FILE (cb_ref ((yyvsp[(1) - (2)])))->organization == COB_ORG_SORT) {
			cb_error_x (CB_TREE (current_statement),
				    _("UNLOCK invalid for SORT files"));
		} else {
			cb_emit_unlock ((yyvsp[(1) - (2)]));
		}
	}
  }
    break;

  case 1304:
/* Line 1813 of yacc.c  */
#line 8768 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1306:
/* Line 1813 of yacc.c  */
#line 8778 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1307:
/* Line 1813 of yacc.c  */
#line 8784 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1308:
/* Line 1813 of yacc.c  */
#line 8786 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1309:
/* Line 1813 of yacc.c  */
#line 8790 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1310:
/* Line 1813 of yacc.c  */
#line 8792 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1311:
/* Line 1813 of yacc.c  */
#line 8797 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1312:
/* Line 1813 of yacc.c  */
#line 8803 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1313:
/* Line 1813 of yacc.c  */
#line 8805 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1314:
/* Line 1813 of yacc.c  */
#line 8810 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1315:
/* Line 1813 of yacc.c  */
#line 8816 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1316:
/* Line 1813 of yacc.c  */
#line 8817 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1317:
/* Line 1813 of yacc.c  */
#line 8821 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1318:
/* Line 1813 of yacc.c  */
#line 8822 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1319:
/* Line 1813 of yacc.c  */
#line 8826 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1320:
/* Line 1813 of yacc.c  */
#line 8827 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1321:
/* Line 1813 of yacc.c  */
#line 8832 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1322:
/* Line 1813 of yacc.c  */
#line 8836 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1323:
/* Line 1813 of yacc.c  */
#line 8846 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1329:
/* Line 1813 of yacc.c  */
#line 8863 "parser.y"
    {
	if (!in_declaratives) {
		cb_error (_("USE statement must be within DECLARATIVES"));
	} else if (!current_section) {
		cb_error (_("SECTION header missing before USE statement"));
	} else {
		current_section->flag_begin = 1;
		current_section->flag_return = 1;
		current_section->flag_declarative_exit = 1;
		current_section->flag_real_label = 1;
		current_section->flag_skip_label = 0;
		CB_EXCEPTION_ENABLE (COB_EC_I_O) = 1;
		if (use_global_ind) {
			current_section->flag_global = 1;
			current_program->global_list =
				cb_list_add (current_program->global_list,
					     CB_TREE (current_section));
		}
		emit_statement (cb_build_comment ("USE AFTER ERROR"));
	}
  }
    break;

  case 1330:
/* Line 1813 of yacc.c  */
#line 8888 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1331:
/* Line 1813 of yacc.c  */
#line 8892 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1332:
/* Line 1813 of yacc.c  */
#line 8904 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1333:
/* Line 1813 of yacc.c  */
#line 8914 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1334:
/* Line 1813 of yacc.c  */
#line 8919 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1335:
/* Line 1813 of yacc.c  */
#line 8924 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1336:
/* Line 1813 of yacc.c  */
#line 8929 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1337:
/* Line 1813 of yacc.c  */
#line 8937 "parser.y"
    {
	cb_tree		plabel;
	char		name[64];

	if (!in_declaratives) {
		cb_error (_("USE statement must be within DECLARATIVES"));
	} else if (current_program->nested_level) {
		cb_error (_("USE DEBUGGING not supported in contained program"));
	} else {
		in_debugging = 1;
		current_section->flag_begin = 1;
		current_section->flag_return = 1;
		current_section->flag_declarative_exit = 1;
		current_section->flag_real_label = 0;
		current_section->flag_is_debug_sect = 1;
		if (!needs_debug_item) {
			needs_debug_item = 1;
			cb_build_debug_item ();
		}
		if (!current_program->flag_debugging) {
			skip_statements = 1;
			current_section->flag_skip_label = 1;
		} else {
			current_program->flag_gen_debug = 1;
			sprintf (name, "EXIT SECTION %d", cb_id);
			plabel = cb_build_reference (name);
			plabel = cb_build_label (plabel, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
			current_section->exit_label = plabel;
			emit_statement (cb_build_comment ("USE FOR DEBUGGING"));
		}
	}
  }
    break;

  case 1340:
/* Line 1813 of yacc.c  */
#line 8980 "parser.y"
    {
	cb_tree		l;
	cb_tree		x;
	cb_tree		z;

	if (current_program->flag_debugging) {
		CB_REFERENCE ((yyvsp[(1) - (1)]))->debug_section = current_section;
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_debug_code = 1;
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_all_debug = 0;
		z = CB_LIST_INIT ((yyvsp[(1) - (1)]));
		current_program->debug_list =
			cb_list_append (current_program->debug_list, z);
		/* Check backward refs to file/data names */
		/* Label refs will be checked later (forward/backward ref) */
		if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
			l = CB_VALUE(CB_WORD_ITEMS ((yyvsp[(1) - (1)])));
			switch (CB_TREE_TAG (l)) {
			case CB_TAG_FILE:
				CB_FILE (l)->debug_section = current_section;
				CB_FILE (l)->flag_fl_debug = 1;
				break;
			case CB_TAG_FIELD:
				x = cb_ref ((yyvsp[(1) - (1)]));
				if (CB_INVALID_TREE (x)) {
					break;
				}
				needs_field_debug = 1;
				CB_FIELD (x)->debug_section = current_section;
				CB_FIELD (x)->flag_field_debug = 1;
				CB_PURPOSE (z) = x;
				break;
			default:
				break;
			}
		}
	}
  }
    break;

  case 1341:
/* Line 1813 of yacc.c  */
#line 9018 "parser.y"
    {
	if (current_program->flag_debugging) {
		if (current_program->all_procedure) {
			cb_error (_("Duplicate USE DEBUGGING ON ALL PROCEDURES"));
		} else {
			current_program->all_procedure = current_section;
		}
	}
  }
    break;

  case 1342:
/* Line 1813 of yacc.c  */
#line 9028 "parser.y"
    {
	cb_tree		x;

	if (current_program->flag_debugging) {
		/* Reference must be a data item */
		x = cb_ref ((yyvsp[(3) - (3)]));
		if (CB_INVALID_TREE (x) || !CB_FIELD_P (x)) {
			cb_error (_("Invalid target for DEBUGGING ALL"));
		} else {
			needs_field_debug = 1;
			CB_FIELD (x)->debug_section = current_section;
			CB_FIELD (x)->flag_field_debug = 1;
			CB_FIELD (x)->flag_all_debug = 1;
			CB_REFERENCE ((yyvsp[(3) - (3)]))->debug_section = current_section;
			CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_debug_code = 1;
			CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_all_debug = 1;
			CB_CHAIN_PAIR (current_program->debug_list, x, (yyvsp[(3) - (3)]));
		}
	}
  }
    break;

  case 1347:
/* Line 1813 of yacc.c  */
#line 9058 "parser.y"
    {
	char wrk[80];
	cb_tree x;
	struct cb_field		*f;
	struct cb_report	*r;

	x = cb_ref ((yyvsp[(4) - (4)]));
	if (!CB_FIELD_P (x)) {
		(yyval) = cb_error_node;
	} else {
		control_field = f = CB_FIELD (x);
		f->report_decl_id = current_section->id;
		if((r = f->report) != NULL) {
			r->has_declarative = 1;
		}
	}
	sprintf(wrk,"USE BEFORE REPORTING %s is l_%d",cb_name((yyvsp[(4) - (4)])),current_section->id);
	current_section->flag_real_label = 1;
	current_section->flag_declaratives = 1;
	current_section->flag_begin = 1;
	current_section->flag_return = 1;
	current_section->flag_declarative_exit = 1;
	current_section->flag_real_label = 1;
	current_section->flag_skip_label = 0;
	emit_statement (cb_build_comment (strdup(wrk)));
  }
    break;

  case 1348:
/* Line 1813 of yacc.c  */
#line 9088 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1351:
/* Line 1813 of yacc.c  */
#line 9104 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1353:
/* Line 1813 of yacc.c  */
#line 9116 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1354:
/* Line 1813 of yacc.c  */
#line 9125 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1355:
/* Line 1813 of yacc.c  */
#line 9126 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1356:
/* Line 1813 of yacc.c  */
#line 9131 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1357:
/* Line 1813 of yacc.c  */
#line 9135 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1358:
/* Line 1813 of yacc.c  */
#line 9139 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1359:
/* Line 1813 of yacc.c  */
#line 9143 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1360:
/* Line 1813 of yacc.c  */
#line 9149 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1361:
/* Line 1813 of yacc.c  */
#line 9150 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1364:
/* Line 1813 of yacc.c  */
#line 9160 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1365:
/* Line 1813 of yacc.c  */
#line 9164 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1368:
/* Line 1813 of yacc.c  */
#line 9181 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1370:
/* Line 1813 of yacc.c  */
#line 9191 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1373:
/* Line 1813 of yacc.c  */
#line 9204 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1375:
/* Line 1813 of yacc.c  */
#line 9214 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1378:
/* Line 1813 of yacc.c  */
#line 9229 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1380:
/* Line 1813 of yacc.c  */
#line 9239 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1383:
/* Line 1813 of yacc.c  */
#line 9256 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1385:
/* Line 1813 of yacc.c  */
#line 9267 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1391:
/* Line 1813 of yacc.c  */
#line 9290 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1392:
/* Line 1813 of yacc.c  */
#line 9299 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1396:
/* Line 1813 of yacc.c  */
#line 9316 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1397:
/* Line 1813 of yacc.c  */
#line 9325 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1400:
/* Line 1813 of yacc.c  */
#line 9342 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1402:
/* Line 1813 of yacc.c  */
#line 9352 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1403:
/* Line 1813 of yacc.c  */
#line 9362 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1404:
/* Line 1813 of yacc.c  */
#line 9366 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1405:
/* Line 1813 of yacc.c  */
#line 9376 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1406:
/* Line 1813 of yacc.c  */
#line 9383 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1407:
/* Line 1813 of yacc.c  */
#line 9389 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1408:
/* Line 1813 of yacc.c  */
#line 9393 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1412:
/* Line 1813 of yacc.c  */
#line 9406 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1413:
/* Line 1813 of yacc.c  */
#line 9414 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1414:
/* Line 1813 of yacc.c  */
#line 9415 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1415:
/* Line 1813 of yacc.c  */
#line 9417 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1416:
/* Line 1813 of yacc.c  */
#line 9418 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1417:
/* Line 1813 of yacc.c  */
#line 9419 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1418:
/* Line 1813 of yacc.c  */
#line 9420 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1419:
/* Line 1813 of yacc.c  */
#line 9421 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1420:
/* Line 1813 of yacc.c  */
#line 9423 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1421:
/* Line 1813 of yacc.c  */
#line 9424 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1422:
/* Line 1813 of yacc.c  */
#line 9425 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1423:
/* Line 1813 of yacc.c  */
#line 9426 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1424:
/* Line 1813 of yacc.c  */
#line 9427 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1425:
/* Line 1813 of yacc.c  */
#line 9428 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1426:
/* Line 1813 of yacc.c  */
#line 9430 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1427:
/* Line 1813 of yacc.c  */
#line 9431 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1428:
/* Line 1813 of yacc.c  */
#line 9432 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1429:
/* Line 1813 of yacc.c  */
#line 9434 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1430:
/* Line 1813 of yacc.c  */
#line 9435 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1431:
/* Line 1813 of yacc.c  */
#line 9436 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1432:
/* Line 1813 of yacc.c  */
#line 9437 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1433:
/* Line 1813 of yacc.c  */
#line 9438 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1434:
/* Line 1813 of yacc.c  */
#line 9441 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1435:
/* Line 1813 of yacc.c  */
#line 9442 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1444:
/* Line 1813 of yacc.c  */
#line 9472 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1445:
/* Line 1813 of yacc.c  */
#line 9476 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1449:
/* Line 1813 of yacc.c  */
#line 9487 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1450:
/* Line 1813 of yacc.c  */
#line 9488 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1451:
/* Line 1813 of yacc.c  */
#line 9489 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1452:
/* Line 1813 of yacc.c  */
#line 9493 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1453:
/* Line 1813 of yacc.c  */
#line 9494 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1454:
/* Line 1813 of yacc.c  */
#line 9495 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1455:
/* Line 1813 of yacc.c  */
#line 9500 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1456:
/* Line 1813 of yacc.c  */
#line 9503 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1457:
/* Line 1813 of yacc.c  */
#line 9507 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1458:
/* Line 1813 of yacc.c  */
#line 9508 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1459:
/* Line 1813 of yacc.c  */
#line 9509 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1460:
/* Line 1813 of yacc.c  */
#line 9512 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1461:
/* Line 1813 of yacc.c  */
#line 9513 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1462:
/* Line 1813 of yacc.c  */
#line 9524 "parser.y"
    {
	if (current_linage > 1) {
		cb_error (_("LINAGE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if (current_linage == 0) {
		cb_error (_("Invalid LINAGE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = linage_file->linage_ctr;
	}
  }
    break;

  case 1463:
/* Line 1813 of yacc.c  */
#line 9536 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1464:
/* Line 1813 of yacc.c  */
#line 9545 "parser.y"
    {
	if (report_count > 1) {
		cb_error (_("LINE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if (report_count == 0) {
		cb_error (_("Invalid LINE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = report_instance->line_counter;
	}
  }
    break;

  case 1465:
/* Line 1813 of yacc.c  */
#line 9557 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1466:
/* Line 1813 of yacc.c  */
#line 9566 "parser.y"
    {
	if (report_count > 1) {
		cb_error (_("PAGE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if (report_count == 0) {
		cb_error (_("Invalid PAGE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = report_instance->page_counter;
	}
  }
    break;

  case 1467:
/* Line 1813 of yacc.c  */
#line 9578 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1468:
/* Line 1813 of yacc.c  */
#line 9592 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1469:
/* Line 1813 of yacc.c  */
#line 9594 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1470:
/* Line 1813 of yacc.c  */
#line 9599 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1471:
/* Line 1813 of yacc.c  */
#line 9607 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1472:
/* Line 1813 of yacc.c  */
#line 9614 "parser.y"
    {
	cb_tree x;

	x = cb_ref ((yyvsp[(1) - (1)]));
	if (!CB_FIELD_P (x)) {
		(yyval) = cb_error_node;
	} else if (!CB_FIELD (x)->index_list) {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' not indexed"), cb_name ((yyvsp[(1) - (1)])));
		cb_error_x (x, _("'%s' defined here"), cb_name (x));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1473:
/* Line 1813 of yacc.c  */
#line 9634 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1474:
/* Line 1813 of yacc.c  */
#line 9638 "parser.y"
    {
	cb_tree		l;

	if (CB_VALID_TREE ((yyvsp[(2) - (2)]))) {
		for (l = (yyvsp[(1) - (2)]); l; l = CB_CHAIN (l)) {
			if (CB_VALID_TREE (CB_VALUE (l)) &&
			    !strcasecmp (CB_NAME ((yyvsp[(2) - (2)])), CB_NAME (CB_VALUE (l)))) {
				cb_error_x ((yyvsp[(2) - (2)]), _("Multiple reference to '%s' "),
					    CB_NAME ((yyvsp[(2) - (2)])));
				break;
			}
		}
		if (!l) {
			(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  }
    break;

  case 1475:
/* Line 1813 of yacc.c  */
#line 9659 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1476:
/* Line 1813 of yacc.c  */
#line 9700 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1477:
/* Line 1813 of yacc.c  */
#line 9713 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1478:
/* Line 1813 of yacc.c  */
#line 9715 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1479:
/* Line 1813 of yacc.c  */
#line 9719 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1480:
/* Line 1813 of yacc.c  */
#line 9725 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1481:
/* Line 1813 of yacc.c  */
#line 9727 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1482:
/* Line 1813 of yacc.c  */
#line 9732 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1485:
/* Line 1813 of yacc.c  */
#line 9746 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1486:
/* Line 1813 of yacc.c  */
#line 9753 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1487:
/* Line 1813 of yacc.c  */
#line 9763 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1488:
/* Line 1813 of yacc.c  */
#line 9764 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1489:
/* Line 1813 of yacc.c  */
#line 9769 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1490:
/* Line 1813 of yacc.c  */
#line 9777 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1491:
/* Line 1813 of yacc.c  */
#line 9785 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1492:
/* Line 1813 of yacc.c  */
#line 9789 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1493:
/* Line 1813 of yacc.c  */
#line 9796 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1496:
/* Line 1813 of yacc.c  */
#line 9812 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1497:
/* Line 1813 of yacc.c  */
#line 9826 "parser.y"
    {
	if (CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_duped || CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = NULL;
	} else {
		CB_WORD_COUNT ((yyvsp[(1) - (1)]))++;
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1498:
/* Line 1813 of yacc.c  */
#line 9843 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1499:
/* Line 1813 of yacc.c  */
#line 9847 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1502:
/* Line 1813 of yacc.c  */
#line 9856 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1503:
/* Line 1813 of yacc.c  */
#line 9863 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1504:
/* Line 1813 of yacc.c  */
#line 9867 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1509:
/* Line 1813 of yacc.c  */
#line 9878 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1510:
/* Line 1813 of yacc.c  */
#line 9882 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1511:
/* Line 1813 of yacc.c  */
#line 9886 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1512:
/* Line 1813 of yacc.c  */
#line 9890 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1513:
/* Line 1813 of yacc.c  */
#line 9894 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1514:
/* Line 1813 of yacc.c  */
#line 9898 "parser.y"
    {
	cb_tree		x;
	cb_tree		switch_id;

	x = cb_ref ((yyvsp[(1) - (1)]));
	if (CB_VALID_TREE (x)) {
		if (CB_SYSTEM_NAME (x)->category != CB_SWITCH_NAME) {
			cb_error_x (x, _("Invalid mnemonic identifier"));
			(yyval) = cb_error_node;
		} else {
			switch_id = cb_int (CB_SYSTEM_NAME (x)->token);
			(yyval) = CB_BUILD_FUNCALL_1 ("cob_switch_value", switch_id);
		}
	} else {
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1515:
/* Line 1813 of yacc.c  */
#line 9919 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1516:
/* Line 1813 of yacc.c  */
#line 9923 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1524:
/* Line 1813 of yacc.c  */
#line 9940 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1525:
/* Line 1813 of yacc.c  */
#line 9944 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1526:
/* Line 1813 of yacc.c  */
#line 9948 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1542:
/* Line 1813 of yacc.c  */
#line 9995 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1550:
/* Line 1813 of yacc.c  */
#line 10019 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1551:
/* Line 1813 of yacc.c  */
#line 10023 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1552:
/* Line 1813 of yacc.c  */
#line 10027 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1553:
/* Line 1813 of yacc.c  */
#line 10028 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1554:
/* Line 1813 of yacc.c  */
#line 10032 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1555:
/* Line 1813 of yacc.c  */
#line 10037 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1556:
/* Line 1813 of yacc.c  */
#line 10044 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1557:
/* Line 1813 of yacc.c  */
#line 10051 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1558:
/* Line 1813 of yacc.c  */
#line 10058 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1559:
/* Line 1813 of yacc.c  */
#line 10068 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1560:
/* Line 1813 of yacc.c  */
#line 10075 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (3)]))) {
		CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1561:
/* Line 1813 of yacc.c  */
#line 10085 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (2)]))) {
		CB_REFERENCE ((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1562:
/* Line 1813 of yacc.c  */
#line 10095 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (2)]))) {
		CB_REFERENCE ((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1563:
/* Line 1813 of yacc.c  */
#line 10105 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)]))) {
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1564:
/* Line 1813 of yacc.c  */
#line 10118 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1565:
/* Line 1813 of yacc.c  */
#line 10122 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1566:
/* Line 1813 of yacc.c  */
#line 10130 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1567:
/* Line 1813 of yacc.c  */
#line 10138 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1568:
/* Line 1813 of yacc.c  */
#line 10142 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1569:
/* Line 1813 of yacc.c  */
#line 10152 "parser.y"
    {
	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign < 0 || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1570:
/* Line 1813 of yacc.c  */
#line 10167 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		n = cb_get_int ((yyvsp[(1) - (1)]));
		if (n < 1 || n > 256) {
			cb_error (_("Invalid SYMBOLIC integer"));
			(yyval) = cb_int1;
		} else {
			(yyval) = (yyvsp[(1) - (1)]);
		}
	}
  }
    break;

  case 1571:
/* Line 1813 of yacc.c  */
#line 10190 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		n = cb_get_int ((yyvsp[(1) - (1)]));
		if (n < 1) {
			cb_error (_("Invalid integer"));
			(yyval) = cb_int1;
		} else {
			(yyval) = (yyvsp[(1) - (1)]);
		}
	}
  }
    break;

  case 1572:
/* Line 1813 of yacc.c  */
#line 10213 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) == CB_CATEGORY_NUMERIC) {
		if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
			cb_error (_("Integer value expected"));
		} else {
			n = cb_get_int ((yyvsp[(1) - (1)]));
			if (n < 1 || n > 256) {
				cb_error (_("Invalid CLASS value"));
			}
		}
	}
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1573:
/* Line 1813 of yacc.c  */
#line 10228 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1574:
/* Line 1813 of yacc.c  */
#line 10229 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1575:
/* Line 1813 of yacc.c  */
#line 10230 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1576:
/* Line 1813 of yacc.c  */
#line 10231 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1577:
/* Line 1813 of yacc.c  */
#line 10232 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1578:
/* Line 1813 of yacc.c  */
#line 10233 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1579:
/* Line 1813 of yacc.c  */
#line 10238 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1580:
/* Line 1813 of yacc.c  */
#line 10242 "parser.y"
    {
	struct cb_literal	*l;

	if (CB_LITERAL_P ((yyvsp[(2) - (2)]))) {
		/* We must not alter the original definition */
		l = cobc_parse_malloc (sizeof(struct cb_literal));
		*l = *(CB_LITERAL((yyvsp[(2) - (2)])));
		l->all = 1;
		(yyval) = CB_TREE (l);
	} else {
		(yyval) = (yyvsp[(2) - (2)]);
	}
  }
    break;

  case 1581:
/* Line 1813 of yacc.c  */
#line 10259 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1582:
/* Line 1813 of yacc.c  */
#line 10263 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1583:
/* Line 1813 of yacc.c  */
#line 10269 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1584:
/* Line 1813 of yacc.c  */
#line 10270 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1585:
/* Line 1813 of yacc.c  */
#line 10271 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1586:
/* Line 1813 of yacc.c  */
#line 10272 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1587:
/* Line 1813 of yacc.c  */
#line 10273 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1588:
/* Line 1813 of yacc.c  */
#line 10274 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1589:
/* Line 1813 of yacc.c  */
#line 10275 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1590:
/* Line 1813 of yacc.c  */
#line 10282 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1591:
/* Line 1813 of yacc.c  */
#line 10286 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1592:
/* Line 1813 of yacc.c  */
#line 10290 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1593:
/* Line 1813 of yacc.c  */
#line 10294 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1594:
/* Line 1813 of yacc.c  */
#line 10298 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1595:
/* Line 1813 of yacc.c  */
#line 10302 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1596:
/* Line 1813 of yacc.c  */
#line 10306 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1597:
/* Line 1813 of yacc.c  */
#line 10310 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1598:
/* Line 1813 of yacc.c  */
#line 10314 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1599:
/* Line 1813 of yacc.c  */
#line 10318 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1608:
/* Line 1813 of yacc.c  */
#line 10342 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1609:
/* Line 1813 of yacc.c  */
#line 10346 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1610:
/* Line 1813 of yacc.c  */
#line 10350 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1611:
/* Line 1813 of yacc.c  */
#line 10357 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1612:
/* Line 1813 of yacc.c  */
#line 10361 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1613:
/* Line 1813 of yacc.c  */
#line 10365 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1614:
/* Line 1813 of yacc.c  */
#line 10372 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1615:
/* Line 1813 of yacc.c  */
#line 10379 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1616:
/* Line 1813 of yacc.c  */
#line 10386 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1617:
/* Line 1813 of yacc.c  */
#line 10396 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1618:
/* Line 1813 of yacc.c  */
#line 10403 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1619:
/* Line 1813 of yacc.c  */
#line 10413 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1620:
/* Line 1813 of yacc.c  */
#line 10420 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1621:
/* Line 1813 of yacc.c  */
#line 10431 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1622:
/* Line 1813 of yacc.c  */
#line 10439 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1623:
/* Line 1813 of yacc.c  */
#line 10440 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1624:
/* Line 1813 of yacc.c  */
#line 10444 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1625:
/* Line 1813 of yacc.c  */
#line 10445 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1626:
/* Line 1813 of yacc.c  */
#line 10449 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1627:
/* Line 1813 of yacc.c  */
#line 10450 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1628:
/* Line 1813 of yacc.c  */
#line 10455 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1629:
/* Line 1813 of yacc.c  */
#line 10459 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1630:
/* Line 1813 of yacc.c  */
#line 10466 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1631:
/* Line 1813 of yacc.c  */
#line 10470 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1632:
/* Line 1813 of yacc.c  */
#line 10477 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1633:
/* Line 1813 of yacc.c  */
#line 10478 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1634:
/* Line 1813 of yacc.c  */
#line 10479 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1635:
/* Line 1813 of yacc.c  */
#line 10483 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1636:
/* Line 1813 of yacc.c  */
#line 10484 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1637:
/* Line 1813 of yacc.c  */
#line 10488 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1638:
/* Line 1813 of yacc.c  */
#line 10489 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1639:
/* Line 1813 of yacc.c  */
#line 10490 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1640:
/* Line 1813 of yacc.c  */
#line 10495 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1641:
/* Line 1813 of yacc.c  */
#line 10499 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1642:
/* Line 1813 of yacc.c  */
#line 10511 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1643:
/* Line 1813 of yacc.c  */
#line 10516 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1644:
/* Line 1813 of yacc.c  */
#line 10524 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1645:
/* Line 1813 of yacc.c  */
#line 10528 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1646:
/* Line 1813 of yacc.c  */
#line 10532 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1647:
/* Line 1813 of yacc.c  */
#line 10536 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1648:
/* Line 1813 of yacc.c  */
#line 10540 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1649:
/* Line 1813 of yacc.c  */
#line 10544 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1650:
/* Line 1813 of yacc.c  */
#line 10548 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1651:
/* Line 1813 of yacc.c  */
#line 10552 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1652:
/* Line 1813 of yacc.c  */
#line 10558 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1653:
/* Line 1813 of yacc.c  */
#line 10559 "parser.y"
    { (yyval) = cb_int1; }
    break;


/* Line 1813 of yacc.c  */
#line 17736 "parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2076 of yacc.c  */
#line 10730 "parser.y"

