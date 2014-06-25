/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 27 "parser.y"

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


/* Line 371 of yacc.c  */
#line 764 "parser.c"

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

/* Line 390 of yacc.c  */
#line 1342 "parser.c"

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYLAST   7727

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  811
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1886
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2696

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
    1397,  1400,  1405,  1407,  1412,  1415,  1416,  1419,  1421,  1423,
    1425,  1427,  1429,  1433,  1438,  1443,  1448,  1452,  1453,  1456,
    1457,  1463,  1464,  1467,  1469,  1471,  1473,  1475,  1477,  1479,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,
    1503,  1505,  1507,  1510,  1512,  1515,  1517,  1519,  1520,  1523,
    1526,  1527,  1530,  1535,  1540,  1541,  1545,  1547,  1549,  1553,
    1560,  1563,  1567,  1570,  1573,  1577,  1580,  1582,  1585,  1588,
    1590,  1592,  1594,  1597,  1600,  1602,  1607,  1610,  1614,  1615,
    1616,  1622,  1623,  1625,  1628,  1632,  1634,  1635,  1640,  1644,
    1645,  1648,  1651,  1654,  1656,  1658,  1661,  1664,  1666,  1668,
    1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,  1689,  1691,
    1693,  1699,  1705,  1709,  1713,  1715,  1717,  1719,  1721,  1723,
    1725,  1727,  1729,  1732,  1735,  1738,  1740,  1742,  1744,  1746,
    1747,  1749,  1751,  1752,  1754,  1756,  1760,  1763,  1764,  1765,
    1766,  1776,  1777,  1782,  1783,  1784,  1788,  1789,  1793,  1795,
    1798,  1803,  1804,  1807,  1810,  1811,  1815,  1819,  1824,  1829,
    1833,  1834,  1836,  1837,  1840,  1841,  1842,  1850,  1851,  1854,
    1856,  1858,  1861,  1863,  1865,  1866,  1873,  1874,  1877,  1880,
    1882,  1883,  1885,  1886,  1887,  1891,  1892,  1895,  1898,  1900,
    1902,  1904,  1906,  1908,  1910,  1912,  1914,  1916,  1918,  1920,
    1922,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,  1960,
    1962,  1964,  1966,  1968,  1970,  1972,  1974,  1976,  1978,  1980,
    1982,  1984,  1986,  1988,  1990,  1992,  1994,  1996,  1999,  2002,
    2003,  2008,  2015,  2019,  2023,  2028,  2032,  2037,  2041,  2045,
    2050,  2055,  2059,  2064,  2068,  2073,  2079,  2083,  2088,  2092,
    2096,  2098,  2100,  2102,  2105,  2106,  2108,  2112,  2116,  2119,
    2122,  2125,  2129,  2133,  2137,  2138,  2140,  2141,  2145,  2146,
    2149,  2151,  2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,
    2170,  2172,  2174,  2176,  2181,  2183,  2185,  2187,  2189,  2191,
    2193,  2195,  2199,  2203,  2207,  2211,  2215,  2216,  2218,  2219,
    2224,  2229,  2235,  2242,  2243,  2246,  2247,  2249,  2250,  2254,
    2258,  2263,  2264,  2267,  2268,  2272,  2274,  2277,  2282,  2283,
    2286,  2287,  2292,  2299,  2300,  2302,  2304,  2306,  2307,  2308,
    2312,  2314,  2317,  2320,  2324,  2325,  2328,  2331,  2334,  2335,
    2339,  2342,  2347,  2349,  2351,  2353,  2355,  2356,  2359,  2360,
    2363,  2364,  2366,  2367,  2371,  2373,  2376,  2377,  2381,  2384,
    2388,  2389,  2391,  2395,  2399,  2402,  2403,  2408,  2413,  2414,
    2416,  2418,  2420,  2421,  2426,  2430,  2433,  2435,  2438,  2439,
    2441,  2442,  2447,  2451,  2455,  2459,  2463,  2468,  2471,  2476,
    2478,  2479,  2483,  2489,  2490,  2493,  2496,  2499,  2502,  2503,
    2506,  2508,  2510,  2511,  2514,  2515,  2517,  2519,  2522,  2524,
    2527,  2530,  2532,  2534,  2537,  2540,  2542,  2544,  2546,  2548,
    2550,  2554,  2558,  2562,  2566,  2567,  2569,  2570,  2575,  2580,
    2587,  2594,  2603,  2612,  2613,  2615,  2616,  2620,  2623,  2624,
    2629,  2632,  2634,  2638,  2640,  2642,  2644,  2647,  2649,  2651,
    2654,  2657,  2661,  2664,  2668,  2670,  2674,  2677,  2679,  2681,
    2683,  2684,  2687,  2688,  2690,  2691,  2695,  2696,  2699,  2701,
    2704,  2706,  2708,  2710,  2711,  2714,  2715,  2719,  2721,  2722,
    2726,  2728,  2729,  2733,  2737,  2738,  2742,  2745,  2746,  2753,
    2757,  2760,  2762,  2763,  2765,  2766,  2770,  2776,  2777,  2780,
    2781,  2785,  2789,  2790,  2793,  2795,  2798,  2803,  2805,  2807,
    2809,  2811,  2813,  2815,  2817,  2818,  2822,  2823,  2827,  2829,
    2832,  2833,  2837,  2840,  2842,  2844,  2846,  2849,  2851,  2853,
    2855,  2856,  2860,  2863,  2869,  2871,  2874,  2877,  2880,  2882,
    2884,  2886,  2889,  2891,  2894,  2899,  2902,  2903,  2905,  2907,
    2909,  2911,  2916,  2917,  2920,  2924,  2928,  2929,  2933,  2934,
    2938,  2942,  2947,  2948,  2953,  2958,  2965,  2966,  2968,  2969,
    2973,  2978,  2984,  2986,  2988,  2990,  2992,  2993,  2997,  2998,
    3002,  3005,  3007,  3008,  3012,  3015,  3016,  3021,  3024,  3025,
    3027,  3029,  3031,  3033,  3037,  3038,  3041,  3043,  3047,  3051,
    3052,  3056,  3058,  3060,  3062,  3066,  3074,  3075,  3080,  3088,
    3089,  3092,  3093,  3096,  3099,  3103,  3107,  3111,  3114,  3115,
    3119,  3121,  3123,  3124,  3126,  3128,  3129,  3133,  3136,  3138,
    3139,  3144,  3149,  3150,  3152,  3153,  3158,  3163,  3164,  3167,
    3171,  3172,  3174,  3176,  3177,  3182,  3187,  3194,  3195,  3198,
    3199,  3202,  3204,  3207,  3211,  3212,  3214,  3215,  3219,  3221,
    3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,  3239,  3244,
    3248,  3250,  3253,  3256,  3259,  3262,  3265,  3268,  3271,  3274,
    3277,  3282,  3286,  3291,  3293,  3296,  3300,  3302,  3305,  3309,
    3313,  3314,  3318,  3319,  3327,  3328,  3334,  3335,  3338,  3339,
    3342,  3343,  3347,  3348,  3351,  3356,  3357,  3360,  3365,  3366,
    3371,  3376,  3377,  3381,  3382,  3387,  3389,  3391,  3393,  3396,
    3399,  3402,  3405,  3407,  3409,  3412,  3414,  3415,  3417,  3418,
    3423,  3426,  3427,  3430,  3435,  3440,  3441,  3443,  3445,  3447,
    3449,  3451,  3452,  3457,  3463,  3465,  3468,  3470,  3474,  3478,
    3479,  3484,  3485,  3487,  3488,  3493,  3498,  3505,  3512,  3513,
    3515,  3518,  3519,  3521,  3522,  3526,  3528,  3531,  3532,  3536,
    3542,  3543,  3547,  3550,  3551,  3553,  3555,  3556,  3561,  3568,
    3569,  3573,  3575,  3579,  3582,  3585,  3588,  3592,  3593,  3597,
    3598,  3602,  3603,  3607,  3608,  3610,  3611,  3615,  3617,  3619,
    3621,  3623,  3625,  3633,  3634,  3636,  3638,  3640,  3642,  3644,
    3646,  3651,  3653,  3656,  3658,  3661,  3665,  3666,  3668,  3671,
    3673,  3677,  3679,  3681,  3686,  3688,  3690,  3692,  3693,  3698,
    3704,  3705,  3708,  3709,  3714,  3718,  3722,  3724,  3726,  3728,
    3730,  3731,  3733,  3736,  3737,  3740,  3741,  3744,  3747,  3748,
    3751,  3752,  3755,  3758,  3759,  3762,  3763,  3766,  3769,  3770,
    3773,  3774,  3777,  3780,  3782,  3785,  3787,  3789,  3792,  3795,
    3798,  3800,  3802,  3805,  3808,  3811,  3812,  3815,  3816,  3819,
    3820,  3823,  3825,  3827,  3828,  3831,  3833,  3836,  3839,  3841,
    3843,  3845,  3847,  3849,  3851,  3853,  3855,  3857,  3859,  3861,
    3863,  3865,  3867,  3869,  3871,  3873,  3875,  3877,  3879,  3881,
    3883,  3885,  3887,  3889,  3892,  3894,  3896,  3898,  3900,  3902,
    3904,  3906,  3910,  3911,  3913,  3915,  3919,  3923,  3925,  3929,
    3933,  3935,  3939,  3941,  3944,  3947,  3949,  3953,  3955,  3957,
    3961,  3963,  3967,  3969,  3973,  3975,  3978,  3981,  3983,  3985,
    3987,  3990,  3992,  3994,  3996,  3999,  4001,  4002,  4005,  4007,
    4009,  4011,  4015,  4017,  4019,  4022,  4024,  4026,  4028,  4031,
    4033,  4035,  4037,  4039,  4041,  4043,  4046,  4048,  4050,  4054,
    4056,  4059,  4061,  4063,  4065,  4067,  4070,  4073,  4076,  4081,
    4085,  4087,  4089,  4092,  4094,  4096,  4098,  4100,  4102,  4104,
    4106,  4109,  4112,  4115,  4117,  4119,  4121,  4123,  4125,  4127,
    4129,  4131,  4133,  4135,  4137,  4139,  4141,  4143,  4145,  4147,
    4149,  4151,  4153,  4155,  4157,  4159,  4161,  4163,  4165,  4167,
    4170,  4172,  4176,  4179,  4182,  4184,  4186,  4190,  4193,  4196,
    4198,  4200,  4204,  4208,  4213,  4219,  4221,  4223,  4225,  4227,
    4229,  4231,  4233,  4235,  4237,  4239,  4241,  4244,  4246,  4250,
    4252,  4254,  4256,  4258,  4260,  4262,  4264,  4267,  4273,  4279,
    4285,  4290,  4296,  4302,  4308,  4311,  4314,  4316,  4318,  4320,
    4322,  4324,  4326,  4328,  4330,  4331,  4336,  4342,  4343,  4347,
    4350,  4352,  4356,  4360,  4362,  4366,  4368,  4372,  4373,  4374,
    4376,  4377,  4379,  4380,  4382,  4383,  4386,  4387,  4390,  4391,
    4393,  4395,  4396,  4398,  4399,  4401,  4404,  4405,  4408,  4409,
    4413,  4415,  4417,  4419,  4421,  4423,  4425,  4427,  4429,  4430,
    4433,  4435,  4437,  4439,  4441,  4443,  4445,  4447,  4449,  4451,
    4453,  4455,  4457,  4459,  4461,  4463,  4465,  4467,  4469,  4471,
    4473,  4475,  4477,  4479,  4481,  4483,  4485,  4487,  4489,  4491,
    4493,  4495,  4497,  4499,  4501,  4503,  4505,  4507,  4509,  4511,
    4513,  4515,  4517,  4519,  4521,  4523,  4525,  4527,  4529,  4531,
    4533,  4535,  4537,  4539,  4541,  4543,  4545,  4547,  4549,  4551,
    4553,  4555,  4557,  4559,  4561,  4563,  4565,  4567,  4569,  4571,
    4573,  4574,  4576,  4577,  4579,  4580,  4582,  4583,  4585,  4586,
    4588,  4589,  4591,  4592,  4594,  4595,  4597,  4598,  4600,  4601,
    4603,  4604,  4606,  4607,  4609,  4610,  4612,  4613,  4615,  4616,
    4618,  4619,  4621,  4622,  4624,  4625,  4627,  4630,  4631,  4633,
    4634,  4636,  4637,  4639,  4640,  4642,  4643,  4645,  4647,  4648,
    4650,  4651,  4653,  4655,  4656,  4658,  4660,  4661,  4664,  4667,
    4668,  4670,  4671,  4673,  4674,  4676,  4677,  4679,  4681,  4682,
    4684,  4685,  4687,  4688,  4691,  4693,  4695,  4696,  4698,  4699,
    4701,  4702,  4704,  4705,  4707,  4708,  4710,  4711,  4713,  4714,
    4716,  4717,  4719,  4722,  4723,  4725,  4726,  4728,  4729,  4731,
    4732,  4734,  4735,  4737,  4738,  4740,  4741,  4743,  4744,  4746,
    4748,  4749,  4751,  4752,  4756,  4757,  4759,  4762,  4764,  4766,
    4768,  4770,  4772,  4774,  4776,  4778,  4780,  4782,  4784,  4786,
    4788,  4790,  4792,  4794,  4796,  4798,  4800,  4802,  4804,  4807,
    4810,  4812,  4814,  4816,  4818,  4820,  4822,  4825,  4827,  4831,
    4834,  4836,  4838,  4840,  4843,  4845,  4848,  4850,  4853,  4855,
    4858,  4860,  4863,  4865,  4868,  4870,  4873
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
     648,   649,   650,   530,   679,   732,   734,   736,   781,   531,
     795,    -1,    -1,   341,   451,   535,   536,   533,   537,   451,
      -1,   200,   451,   535,   536,   451,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1266,   538,  1281,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1297,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1266,  1215,  1308,    -1,  1314,
    1266,  1182,    -1,   396,  1266,  1215,    -1,  1253,    59,  1266,
     557,    -1,  1182,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1266,    96,    -1,  1215,  1266,  1186,    -1,
    1266,  1186,   574,    -1,   575,    -1,    -1,   575,    -1,  1031,
    1278,  1186,    -1,   575,  1031,  1278,  1186,    -1,    -1,    11,
    1186,   577,  1266,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1254,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1267,
     590,    -1,  1187,    -1,   589,  1187,    -1,  1216,    -1,   590,
    1216,    -1,    58,  1186,  1266,   592,    -1,   593,    -1,   592,
     593,    -1,  1218,    -1,  1218,   442,  1218,    -1,   257,  1186,
    1266,   256,    -1,    98,  1284,  1266,   256,   596,    -1,    -1,
    1297,   328,   256,    -1,   108,  1266,    68,    -1,   301,   405,
    1266,   468,   400,    -1,   100,  1266,  1181,    -1,    96,   423,
    1266,  1181,    -1,   390,  1266,  1181,    -1,   164,  1266,  1181,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1239,  1186,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1294,   614,   613,   615,    -1,    29,  1294,   614,   612,
     616,    -1,    29,  1294,   614,   119,   616,    -1,    29,  1294,
     614,   238,   616,    -1,    29,  1294,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1257,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1212,    -1,    -1,   256,    -1,  1212,    -1,     4,  1273,  1266,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1282,
    1268,  1266,   632,  1233,    -1,  1298,  1266,   504,    -1,   622,
     423,  1266,  1181,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1273,  1266,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1307,    -1,
     503,   262,   309,   274,  1307,    -1,   503,   385,    -1,   315,
    1266,   628,    -1,   628,    -1,   220,    -1,  1282,  1251,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1253,  1266,  1185,
      -1,   351,   113,  1266,   419,    -1,   351,  1268,  1266,   632,
      -1,  1181,    -1,  1181,   452,  1180,    -1,  1181,   414,  1266,
    1180,    -1,   359,  1268,  1266,  1181,    -1,   372,   635,  1248,
      -1,   287,    -1,  1215,    -1,   404,  1297,   637,    -1,     9,
    1279,    -1,   287,  1279,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1248,  1259,  1171,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1257,  1290,  1255,   645,    -1,   646,    -1,   645,   646,
      -1,  1172,   647,    -1,    -1,   331,  1215,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1172,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1266,   171,    -1,  1266,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1255,
    1215,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1255,  1215,  1254,    -1,   351,  1255,  1215,   446,  1215,  1254,
      -1,   351,  1266,   499,  1261,  1287,   661,   662,  1254,   660,
      -1,    -1,   114,  1277,  1181,    -1,    -1,  1260,  1215,    -1,
      -1,   446,  1215,    -1,   239,  1309,  1305,    -1,   498,   306,
     665,  1266,   666,    -1,   498,   306,   174,  1266,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1212,    -1,   102,  1309,
    1183,    -1,   250,  1266,  1185,  1272,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1297,   187,
    1250,  1185,    -1,   465,  1185,    -1,    48,  1185,    -1,   352,
    1273,  1266,   504,    -1,    62,  1266,   504,    -1,   677,   678,
      -1,   366,  1266,    -1,   368,  1247,    -1,  1186,    -1,   678,
    1186,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1231,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1266,   204,
      -1,  1219,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1276,   691,    -1,  1209,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1249,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1209,    -1,  1266,   171,   702,    -1,    -1,
      26,   256,    -1,  1266,   204,    -1,   327,    -1,   706,    -1,
     491,  1266,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1285,    -1,    41,   476,    -1,
      44,  1285,    -1,    44,   476,    -1,    43,  1285,    -1,    43,
     476,    -1,    42,  1285,    -1,    42,   476,    -1,    40,  1285,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1286,   241,  1243,    -1,  1286,   468,
    1243,    -1,   305,  1215,   713,  1292,   714,   711,    -1,    -1,
     425,  1215,    -1,   305,  1215,   713,  1292,   714,   715,   718,
      -1,    -1,   446,  1215,    -1,    -1,   114,  1277,  1181,    -1,
     716,    -1,    -1,   716,   717,  1268,  1266,  1180,    -1,    27,
      -1,   115,    -1,    -1,   220,  1252,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1283,    -1,   434,  1269,
      -1,    45,  1295,   510,    -1,    36,    -1,    -1,   498,  1267,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1219,
      -1,  1219,   442,  1219,    -1,    -1,  1296,   453,  1266,  1219,
      -1,   363,  1212,    -1,   363,  1212,   442,  1212,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1173,   740,   741,   451,   755,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1266,   204,
      -1,    61,  1266,  1199,    -1,   743,    -1,   746,    -1,  1322,
     744,    -1,  1258,   745,    -1,  1208,    -1,   745,  1208,    -1,
     321,  1271,   747,   748,    -1,  1217,    -1,  1217,  1306,  1217,
    1300,    -1,  1217,  1306,    -1,    -1,   748,   749,    -1,   750,
      -1,   751,    -1,   752,    -1,   753,    -1,   754,    -1,   210,
    1266,  1217,    -1,   177,  1315,  1266,  1217,    -1,   240,  1316,
    1266,  1217,    -1,   240,  1315,  1266,  1217,    -1,   187,  1266,
    1217,    -1,    -1,   755,   756,    -1,    -1,   686,   687,   757,
     758,   451,    -1,    -1,   758,   759,    -1,   760,    -1,   764,
      -1,   770,    -1,   704,    -1,   780,    -1,   709,    -1,   721,
      -1,   772,    -1,   723,    -1,   778,    -1,   765,    -1,   725,
      -1,   768,    -1,   779,    -1,   710,    -1,   769,    -1,   472,
    1266,   761,    -1,  1320,    -1,  1318,    -1,  1316,   762,    -1,
    1315,    -1,  1317,   762,    -1,  1319,    -1,  1321,    -1,    -1,
    1208,   763,    -1,   176,   763,    -1,    -1,   313,   321,    -1,
     285,   209,  1266,   775,    -1,   431,  1276,  1192,   766,    -1,
      -1,   373,  1277,   767,    -1,  1208,    -1,   176,    -1,   333,
     501,  1148,    -1,   499,  1208,   196,  1194,    49,  1194,    -1,
     771,   774,    -1,   252,  1275,  1267,    -1,   254,  1247,    -1,
     773,   776,    -1,  1299,  1275,  1267,    -1,  1300,  1247,    -1,
     775,    -1,   774,   775,    -1,   329,  1215,    -1,  1217,    -1,
     286,    -1,   777,    -1,   776,   777,    -1,   329,  1215,    -1,
    1217,    -1,   414,  1266,  1194,  1240,    -1,   209,  1263,    -1,
     491,  1266,   119,    -1,    -1,    -1,   389,   394,   451,   782,
     783,    -1,    -1,   784,    -1,   785,   451,    -1,   784,   785,
     451,    -1,   696,    -1,    -1,   686,   687,   786,   787,    -1,
     686,     1,   451,    -1,    -1,   787,   788,    -1,    45,   252,
      -1,    45,   389,    -1,    38,    -1,    46,    -1,   160,   156,
      -1,   160,   158,    -1,   211,    -1,   265,    -1,   378,    -1,
     473,    -1,   318,    -1,   243,    -1,    32,    -1,   395,    -1,
     371,    -1,   198,    -1,   345,    56,  1266,  1199,    -1,   345,
      -1,   456,    -1,   252,  1274,  1266,   791,  1201,    -1,  1299,
    1274,  1266,   792,  1201,    -1,   189,  1266,  1201,    -1,    35,
    1266,  1201,    -1,   705,    -1,   723,    -1,   794,    -1,   721,
      -1,   709,    -1,   725,    -1,   704,    -1,   793,    -1,   497,
    1208,    -1,   196,  1200,    -1,   446,  1208,    -1,   329,    -1,
     463,    -1,   270,    -1,   458,    -1,    -1,   789,    -1,   790,
      -1,    -1,   789,    -1,   790,    -1,   305,  1215,  1292,    -1,
    1266,   204,    -1,    -1,    -1,    -1,   337,   122,   799,   807,
     451,   796,   808,   797,   810,    -1,    -1,   798,   821,   451,
     810,    -1,    -1,    -1,   497,   800,   802,    -1,    -1,    55,
     801,   802,    -1,   803,    -1,   802,   803,    -1,   804,   805,
     806,   504,    -1,    -1,  1252,   357,    -1,  1252,   498,    -1,
      -1,   410,  1266,    32,    -1,   410,  1266,   110,    -1,   476,
     410,  1266,    32,    -1,   476,   410,  1266,  1215,    -1,   410,
    1266,  1215,    -1,    -1,   312,    -1,    -1,   376,   504,    -1,
      -1,    -1,   109,   451,   809,   810,   129,   109,   451,    -1,
      -1,   810,   811,    -1,   812,    -1,   815,    -1,   821,   451,
      -1,   816,    -1,   451,    -1,    -1,   504,   394,   817,   451,
     813,   814,    -1,    -1,  1102,   451,    -1,   504,   451,    -1,
     504,    -1,    -1,  1215,    -1,    -1,    -1,   819,   820,   821,
      -1,    -1,   822,   823,    -1,   821,   823,    -1,   824,    -1,
     839,    -1,   844,    -1,   848,    -1,   853,    -1,   868,    -1,
     871,    -1,   879,    -1,   875,    -1,   880,    -1,   881,    -1,
     886,    -1,   900,    -1,   904,    -1,   907,    -1,   921,    -1,
     925,    -1,   928,    -1,   931,    -1,   935,    -1,   936,    -1,
     940,    -1,   950,    -1,   953,    -1,   970,    -1,   972,    -1,
     975,    -1,   979,    -1,   985,    -1,   997,    -1,  1005,    -1,
    1006,    -1,  1009,    -1,  1010,    -1,  1014,    -1,  1019,    -1,
    1020,    -1,  1028,    -1,  1043,    -1,  1053,    -1,  1062,    -1,
    1067,    -1,  1074,    -1,  1078,    -1,  1080,    -1,  1083,    -1,
    1086,    -1,  1090,    -1,  1117,    -1,   285,   399,    -1,     1,
    1244,    -1,    -1,     3,   825,   826,   838,    -1,   827,   829,
     833,   834,   835,  1125,    -1,  1208,   196,   828,    -1,  1208,
     196,  1300,    -1,  1208,   196,   103,   509,    -1,  1208,   196,
     103,    -1,  1208,   196,   104,   508,    -1,  1208,   196,   104,
      -1,  1208,   196,   105,    -1,  1208,   196,   162,   237,    -1,
    1208,   196,   165,   423,    -1,  1208,   196,   443,    -1,  1208,
     196,   493,   276,    -1,  1208,   196,    69,    -1,  1208,   196,
     155,  1125,    -1,  1208,   196,   153,  1197,  1125,    -1,  1208,
     196,    24,    -1,  1208,   196,    25,  1125,    -1,  1208,   196,
    1175,    -1,  1208,   196,   504,    -1,  1208,    -1,   308,    -1,
     254,    -1,   252,   299,    -1,    -1,   830,    -1,  1250,   831,
     832,    -1,  1250,   832,   831,    -1,  1250,   831,    -1,  1250,
     832,    -1,    30,  1197,    -1,   252,  1274,  1201,    -1,  1299,
    1274,  1201,    -1,   331,  1274,  1201,    -1,    -1,   197,    -1,
      -1,   272,  1266,    47,    -1,    -1,   503,   836,    -1,   837,
      -1,   836,   837,    -1,    32,    -1,    38,    -1,    46,    -1,
      91,    -1,   198,    -1,   211,    -1,   243,    -1,   263,    -1,
     265,    -1,   288,    -1,   318,    -1,   345,    56,  1266,  1199,
      -1,   345,    -1,   371,    -1,   378,    -1,   395,    -1,   473,
      -1,   483,    -1,   489,    -1,   189,  1266,  1201,    -1,    35,
    1266,  1201,    -1,   391,   482,  1147,    -1,   391,   123,  1147,
      -1,   444,  1246,  1202,    -1,    -1,   130,    -1,    -1,     5,
     840,   841,   843,    -1,  1190,   446,  1167,  1131,    -1,  1190,
     842,   203,  1167,  1131,    -1,    94,  1208,   446,  1208,  1240,
    1131,    -1,    -1,   446,  1191,    -1,    -1,   131,    -1,    -1,
      10,   845,   846,    -1,  1208,  1234,   847,    -1,  1161,    57,
    1235,   847,    -1,    -1,   376,  1189,    -1,    -1,    18,   849,
     850,    -1,   851,    -1,   850,   851,    -1,  1177,   446,   852,
    1177,    -1,    -1,   339,   446,    -1,    -1,    51,   854,   855,
     867,    -1,   856,  1200,   857,   862,   865,   866,    -1,    -1,
     422,    -1,   424,    -1,   271,    -1,    -1,    -1,   497,   858,
     859,    -1,   860,    -1,   859,   860,    -1,   861,   308,    -1,
     861,   805,  1191,    -1,    -1,  1252,   357,    -1,  1252,    87,
      -1,  1252,   498,    -1,    -1,   863,  1265,  1208,    -1,   863,
     864,    -1,   863,     6,  1276,  1208,    -1,   376,    -1,   203,
      -1,   460,    -1,   308,    -1,    -1,  1303,   818,    -1,    -1,
     294,   818,    -1,    -1,   132,    -1,    -1,    52,   869,   870,
      -1,  1199,    -1,   870,  1199,    -1,    -1,    60,   872,   873,
      -1,  1172,   874,    -1,   873,  1172,   874,    -1,    -1,  1310,
      -1,  1310,  1259,   362,    -1,  1297,   287,   380,    -1,  1297,
     262,    -1,    -1,    74,   876,   877,   878,    -1,  1167,  1301,
    1161,  1131,    -1,    -1,   133,    -1,    71,    -1,    88,    -1,
      -1,   111,   882,   883,   885,    -1,  1172,  1282,  1144,    -1,
     454,   884,    -1,  1172,    -1,   884,  1172,    -1,    -1,   134,
      -1,    -1,   119,   887,   888,   899,    -1,  1199,   487,  1128,
      -1,  1199,   488,  1128,    -1,  1199,   485,  1128,    -1,  1199,
     486,  1128,    -1,  1190,   892,   896,  1128,    -1,   889,  1128,
      -1,  1191,   503,   897,  1128,    -1,   891,    -1,    -1,   889,
     890,   891,    -1,  1191,   830,   893,   834,   895,    -1,    -1,
     484,  1175,    -1,   484,   504,    -1,   484,   335,    -1,   484,
      96,    -1,    -1,   484,   894,    -1,    96,    -1,    97,    -1,
      -1,   503,   897,    -1,    -1,   298,    -1,   898,    -1,   897,
     898,    -1,    38,    -1,    45,   252,    -1,    45,   389,    -1,
      46,    -1,    91,    -1,   160,   156,    -1,   160,   158,    -1,
     211,    -1,   265,    -1,   318,    -1,   378,    -1,   473,    -1,
     189,  1266,  1201,    -1,    35,  1266,  1201,    -1,   391,   482,
    1147,    -1,   391,   123,  1147,    -1,    -1,   135,    -1,    -1,
     121,   901,   902,   903,    -1,  1191,   228,  1167,  1131,    -1,
    1191,   228,  1191,   203,  1167,  1131,    -1,  1191,    49,  1191,
     203,  1167,  1131,    -1,  1191,   228,  1191,   203,  1168,   361,
    1168,  1131,    -1,  1191,    49,  1191,   203,  1168,   361,  1168,
    1131,    -1,    -1,   136,    -1,    -1,   152,   905,   906,    -1,
     256,   857,    -1,    -1,   163,   908,   909,   920,    -1,   910,
     912,    -1,   911,    -1,   910,    17,   911,    -1,  1149,    -1,
     464,    -1,   453,    -1,   913,   915,    -1,   913,    -1,   914,
      -1,   913,   914,    -1,   916,   818,    -1,   501,   316,   818,
      -1,   501,   917,    -1,   916,   501,   917,    -1,   918,    -1,
     917,    17,   918,    -1,  1150,   919,    -1,    21,    -1,   464,
      -1,   453,    -1,    -1,   442,  1149,    -1,    -1,   137,    -1,
      -1,   168,   922,   923,    -1,    -1,   340,   924,    -1,   199,
      -1,   324,   101,    -1,   324,    -1,   394,    -1,   323,    -1,
      -1,   863,  1191,    -1,    -1,   195,   926,   927,    -1,  1188,
      -1,    -1,   202,   929,   930,    -1,  1212,    -1,    -1,   205,
     932,   933,    -1,  1293,  1176,   934,    -1,    -1,   114,  1277,
    1208,    -1,   206,   924,    -1,    -1,   215,   937,  1148,  1291,
     938,   939,    -1,   818,   128,   818,    -1,   128,   818,    -1,
     818,    -1,    -1,   139,    -1,    -1,   222,   941,   942,    -1,
    1188,   943,   944,   945,   949,    -1,    -1,  1297,   175,    -1,
      -1,     9,  1293,   498,    -1,   948,  1293,   498,    -1,    -1,
     365,   946,    -1,   947,    -1,   946,   947,    -1,   948,  1256,
      49,  1191,    -1,    12,    -1,    15,    -1,   301,    -1,    16,
      -1,   302,    -1,   277,    -1,   278,    -1,    -1,  1291,  1293,
     110,    -1,    -1,   224,   951,   952,    -1,  1173,    -1,   952,
    1173,    -1,    -1,   227,   954,   955,    -1,   956,   957,    -1,
    1208,    -1,  1219,    -1,  1222,    -1,   958,   960,    -1,   958,
      -1,   960,    -1,   961,    -1,    -1,   436,   959,   962,    -1,
     365,   964,    -1,    92,  1197,   446,  1198,   968,    -1,   963,
      -1,   962,   963,    -1,  1197,   188,    -1,    57,   968,    -1,
       9,    -1,   241,    -1,   468,    -1,  1197,   968,    -1,   965,
      -1,   964,   965,    -1,    57,    49,  1197,   968,    -1,   966,
     967,    -1,    -1,     9,    -1,   241,    -1,   177,    -1,   468,
      -1,  1197,    49,  1198,   968,    -1,    -1,   968,   969,    -1,
      37,  1264,  1191,    -1,     8,  1264,  1191,    -1,    -1,   269,
     971,  1045,    -1,    -1,   273,   973,   974,    -1,  1191,   446,
    1188,    -1,    94,  1191,   446,  1188,    -1,    -1,   275,   976,
     977,   978,    -1,  1191,    49,  1167,  1131,    -1,  1191,    49,
    1191,   203,  1167,  1131,    -1,    -1,   140,    -1,    -1,   311,
     980,   981,    -1,   982,   983,  1171,   984,    -1,   981,   982,
     983,  1171,   984,    -1,   225,    -1,   317,    -1,   233,    -1,
     170,    -1,    -1,   404,  1297,   637,    -1,    -1,  1297,   287,
     380,    -1,  1297,   262,    -1,   379,    -1,    -1,   324,   986,
     987,    -1,   991,   992,    -1,    -1,   992,   988,   818,   989,
      -1,   992,   990,    -1,    -1,   141,    -1,   141,    -1,   451,
      -1,  1177,    -1,  1177,   442,  1177,    -1,    -1,  1200,   445,
      -1,   190,    -1,   993,   481,   994,    -1,   993,   499,   995,
      -1,    -1,  1297,   439,  1122,    -1,   168,    -1,  1148,    -1,
     996,    -1,   995,     8,   996,    -1,  1208,   196,  1191,    49,
    1191,   481,  1148,    -1,    -1,   349,   998,   999,  1004,    -1,
    1172,  1237,  1282,  1000,  1001,  1002,  1003,    -1,    -1,   228,
    1208,    -1,    -1,   217,   262,    -1,  1297,   262,    -1,  1297,
     236,   262,    -1,  1297,   287,   262,    -1,  1297,   216,   262,
      -1,  1297,   500,    -1,    -1,   237,  1266,  1208,    -1,  1144,
      -1,  1138,    -1,    -1,   143,    -1,   350,    -1,    -1,   360,
    1007,  1008,    -1,  1169,  1120,    -1,   374,    -1,    -1,   375,
    1011,  1012,  1013,    -1,  1172,  1282,  1000,  1137,    -1,    -1,
     144,    -1,    -1,   381,  1015,  1016,  1018,    -1,  1169,  1120,
    1017,  1144,    -1,    -1,  1297,   262,    -1,  1297,   287,   262,
      -1,    -1,   145,    -1,   385,    -1,    -1,   393,  1021,  1022,
    1027,    -1,  1170,  1023,  1024,  1025,    -1,     9,  1170,  1024,
     501,  1149,   818,    -1,    -1,   499,  1208,    -1,    -1,   129,
     818,    -1,  1026,    -1,  1026,  1025,    -1,   501,  1148,   818,
      -1,    -1,   146,    -1,    -1,   403,  1029,  1030,    -1,  1033,
      -1,  1034,    -1,  1037,    -1,  1038,    -1,  1039,    -1,  1041,
      -1,   309,    -1,   307,    -1,   482,    -1,   123,    -1,   153,
    1197,   446,  1197,    -1,  1205,    31,  1035,    -1,  1036,    -1,
    1035,  1036,    -1,    38,  1031,    -1,    46,  1031,    -1,   211,
    1031,    -1,   265,  1031,    -1,   378,  1031,    -1,   473,  1031,
      -1,   243,  1031,    -1,   318,  1031,    -1,  1188,   446,   152,
    1196,    -1,  1188,   446,  1191,    -1,  1188,  1032,    49,  1191,
      -1,  1040,    -1,  1039,  1040,    -1,  1174,   446,  1031,    -1,
    1042,    -1,  1041,  1042,    -1,  1188,   446,   464,    -1,  1188,
     446,   453,    -1,    -1,   412,  1044,  1045,    -1,    -1,  1206,
    1047,  1049,  1050,  1046,  1051,  1052,    -1,    -1,  1047,  1277,
     717,  1268,  1048,    -1,    -1,  1048,  1212,    -1,    -1,  1313,
    1262,    -1,    -1,  1298,  1266,  1181,    -1,    -1,   497,  1171,
      -1,   225,   337,  1266,   991,    -1,    -1,   203,  1171,    -1,
     317,   337,  1266,   991,    -1,    -1,   421,  1054,  1055,  1061,
      -1,  1172,  1057,  1056,  1144,    -1,    -1,  1297,  1312,  1161,
      -1,    -1,   237,  1266,  1058,  1208,    -1,   177,    -1,   240,
      -1,  1154,    -1,  1238,  1155,    -1,  1238,  1156,    -1,  1238,
    1157,    -1,  1238,  1158,    -1,  1059,    -1,  1060,    -1,   290,
    1154,    -1,   293,    -1,    -1,   147,    -1,    -1,   426,   387,
    1063,  1064,    -1,   426,  1066,    -1,    -1,   863,  1191,    -1,
    1297,   161,  1289,  1065,    -1,  1297,   289,  1289,  1065,    -1,
      -1,  1191,    -1,   256,    -1,   416,    -1,   510,    -1,   346,
      -1,    -1,   427,  1068,  1069,  1073,    -1,  1070,   228,  1208,
    1072,  1134,    -1,  1071,    -1,  1070,  1071,    -1,  1191,    -1,
     112,  1252,   410,    -1,   112,  1252,  1191,    -1,    -1,  1297,
     330,  1266,  1208,    -1,    -1,   148,    -1,    -1,   430,  1075,
    1076,  1077,    -1,  1190,   196,  1167,  1131,    -1,  1190,   196,
    1191,   203,  1167,  1131,    -1,    94,  1208,   196,  1208,  1240,
    1131,    -1,    -1,   149,    -1,   432,  1079,    -1,    -1,   336,
      -1,    -1,   438,  1081,  1082,    -1,  1173,    -1,  1082,  1173,
      -1,    -1,   469,  1084,  1085,    -1,  1208,   196,  1197,   446,
    1198,    -1,    -1,   475,  1087,  1088,    -1,  1172,  1089,    -1,
      -1,   351,    -1,   353,    -1,    -1,   480,  1091,  1092,  1101,
      -1,  1208,  1093,  1096,  1072,  1100,  1134,    -1,    -1,   112,
    1252,  1094,    -1,  1095,    -1,  1094,   313,  1095,    -1,  1232,
    1197,    -1,   228,  1097,    -1,  1096,  1097,    -1,  1208,  1098,
    1099,    -1,    -1,   113,  1261,  1208,    -1,    -1,    95,  1261,
    1208,    -1,    -1,   436,  1261,  1208,    -1,    -1,   150,    -1,
      -1,   492,  1103,  1104,    -1,  1105,    -1,  1108,    -1,  1112,
      -1,  1114,    -1,  1115,    -1,  1106,  1246,  1288,  1302,  1280,
    1277,  1107,    -1,    -1,   204,    -1,  1171,    -1,   225,    -1,
     317,    -1,   233,    -1,   170,    -1,  1259,   107,  1277,  1109,
      -1,  1110,    -1,  1109,  1110,    -1,  1178,    -1,     9,   338,
      -1,     9,  1111,  1212,    -1,    -1,   358,    -1,   358,   306,
      -1,   306,    -1,  1250,   340,  1113,    -1,   421,    -1,   129,
      -1,  1106,    37,   367,  1208,    -1,  1116,    -1,   166,    -1,
     127,    -1,    -1,   507,  1118,  1119,  1124,    -1,  1169,  1120,
    1121,  1017,  1123,    -1,    -1,   196,  1204,    -1,    -1,  1122,
    1245,  1201,  1270,    -1,  1122,  1245,  1175,    -1,  1122,  1245,
     321,    -1,    37,    -1,     8,    -1,  1144,    -1,  1141,    -1,
      -1,   151,    -1,  1126,  1127,    -1,    -1,   165,   818,    -1,
      -1,   294,   818,    -1,  1129,  1130,    -1,    -1,   165,   818,
      -1,    -1,   294,   818,    -1,  1132,  1133,    -1,    -1,   411,
     818,    -1,    -1,   297,   818,    -1,  1135,  1136,    -1,    -1,
     461,   818,    -1,    -1,   296,   818,    -1,  1139,  1140,    -1,
    1139,    -1,  1139,  1140,    -1,  1139,    -1,  1140,    -1,   129,
     818,    -1,   291,   818,    -1,  1142,  1143,    -1,  1142,    -1,
    1143,    -1,   157,   818,    -1,   292,   818,    -1,  1145,  1146,
      -1,    -1,   231,   818,    -1,    -1,   295,   818,    -1,    -1,
    1203,  1311,    -1,  1149,    -1,  1150,    -1,    -1,  1151,  1152,
      -1,  1153,    -1,  1152,   232,    -1,  1152,  1153,    -1,  1191,
      -1,   462,    -1,   448,    -1,   463,    -1,   458,    -1,   459,
      -1,   450,    -1,   169,    -1,  1154,    -1,  1155,    -1,  1156,
      -1,  1157,    -1,  1158,    -1,   293,    -1,   290,    -1,    20,
      -1,   313,    -1,   308,    -1,   301,    -1,    12,    -1,    13,
      -1,    14,    -1,   332,    -1,   284,    -1,   452,    -1,   159,
    1293,    -1,   455,    -1,   207,    -1,   457,    -1,   246,    -1,
     208,    -1,   247,    -1,  1161,    -1,  1159,  1160,  1161,    -1,
      -1,    70,    -1,   398,    -1,  1161,   463,  1162,    -1,  1161,
     458,  1162,    -1,  1162,    -1,  1162,   459,  1163,    -1,  1162,
     450,  1163,    -1,  1163,    -1,  1164,   169,  1163,    -1,  1164,
      -1,   463,  1165,    -1,   458,  1165,    -1,  1165,    -1,   462,
    1161,   448,    -1,  1194,    -1,   251,    -1,   251,  1304,   504,
      -1,   253,    -1,   253,  1304,   504,    -1,   322,    -1,   322,
    1304,   504,    -1,  1168,    -1,  1167,  1168,    -1,  1189,  1240,
      -1,  1212,    -1,  1212,    -1,  1172,    -1,  1171,  1172,    -1,
     504,    -1,   504,    -1,  1175,    -1,  1174,  1175,    -1,   271,
      -1,    -1,  1176,  1177,    -1,  1178,    -1,  1212,    -1,  1179,
      -1,  1179,  1304,  1179,    -1,   256,    -1,  1181,    -1,  1180,
    1181,    -1,  1212,    -1,   504,    -1,  1184,    -1,  1183,  1184,
      -1,   504,    -1,  1181,    -1,   256,    -1,   504,    -1,   504,
      -1,  1189,    -1,  1188,  1189,    -1,  1210,    -1,  1220,    -1,
       6,  1276,  1209,    -1,  1191,    -1,  1190,  1191,    -1,  1208,
      -1,  1219,    -1,  1222,    -1,  1166,    -1,   245,  1209,    -1,
     245,  1220,    -1,   245,  1222,    -1,     6,  1276,  1195,  1196,
      -1,     6,  1276,  1209,    -1,   271,    -1,  1194,    -1,  1192,
    1194,    -1,  1208,    -1,  1220,    -1,  1222,    -1,  1208,    -1,
    1220,    -1,  1222,    -1,  1166,    -1,   245,  1209,    -1,   245,
    1220,    -1,   245,  1222,    -1,   340,    -1,   152,    -1,  1209,
      -1,   256,    -1,  1208,    -1,  1220,    -1,  1208,    -1,  1219,
      -1,  1208,    -1,   256,    -1,  1208,    -1,   256,    -1,  1222,
      -1,  1205,    -1,  1215,    -1,   510,    -1,  1205,    -1,  1217,
      -1,  1205,    -1,  1215,    -1,  1208,    -1,  1219,    -1,  1222,
      -1,  1207,    -1,  1207,    -1,  1212,    -1,  1212,  1213,    -1,
    1209,    -1,  1212,  1213,  1214,    -1,  1212,  1213,    -1,  1212,
    1214,    -1,  1212,    -1,  1211,    -1,  1212,  1213,  1214,    -1,
    1212,  1213,    -1,  1212,  1214,    -1,  1212,    -1,   504,    -1,
     504,  1304,  1212,    -1,   462,  1159,   448,    -1,   462,  1161,
     449,   448,    -1,   462,  1161,   449,  1161,   448,    -1,   256,
      -1,   256,    -1,   256,    -1,   256,    -1,   416,    -1,   510,
      -1,   346,    -1,   212,    -1,   266,    -1,   460,    -1,  1220,
      -1,     9,  1221,    -1,  1221,    -1,  1220,   447,  1221,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   460,    -1,  1223,  1226,    -1,  1224,   462,  1193,
     448,  1226,    -1,  1225,   462,  1159,   448,  1226,    -1,   470,
     462,  1228,   448,  1226,    -1,   303,   462,  1229,   448,    -1,
     258,   462,  1230,   448,  1226,    -1,   259,   462,  1230,   448,
    1226,    -1,   260,   462,  1230,   448,  1226,    -1,   201,  1227,
      -1,   495,  1227,    -1,    99,    -1,   502,    -1,   490,    -1,
     264,    -1,   377,    -1,    82,    -1,   428,    -1,   429,    -1,
      -1,   462,  1161,   449,   448,    -1,   462,  1161,   449,  1161,
     448,    -1,    -1,   462,  1159,   448,    -1,   462,   448,    -1,
    1193,    -1,  1193,  1160,   241,    -1,  1193,  1160,   468,    -1,
    1193,    -1,  1193,  1160,  1193,    -1,  1161,    -1,  1161,  1160,
    1181,    -1,    -1,    -1,     9,    -1,    -1,  1313,    -1,    -1,
     223,    -1,    -1,   223,  1236,    -1,    -1,   446,  1198,    -1,
      -1,   285,    -1,   334,    -1,    -1,   290,    -1,    -1,   312,
      -1,   290,   312,    -1,    -1,   386,  1241,    -1,    -1,   272,
    1266,  1242,    -1,    34,    -1,   281,    -1,   282,    -1,   283,
      -1,   344,    -1,   466,    -1,   467,    -1,   471,    -1,    -1,
     400,  1253,    -1,   451,    -1,     3,    -1,     5,    -1,    10,
      -1,    18,    -1,    51,    -1,    52,    -1,    60,    -1,    71,
      -1,    74,    -1,    88,    -1,   111,    -1,   119,    -1,   121,
      -1,   128,    -1,   152,    -1,   163,    -1,   168,    -1,   195,
      -1,   202,    -1,   205,    -1,   206,    -1,   215,    -1,   222,
      -1,   224,    -1,   227,    -1,   269,    -1,   273,    -1,   275,
      -1,   285,    -1,   311,    -1,   324,    -1,   349,    -1,   360,
      -1,   375,    -1,   381,    -1,   385,    -1,   393,    -1,   403,
      -1,   412,    -1,   421,    -1,   426,    -1,   427,    -1,   430,
      -1,   432,    -1,   438,    -1,   469,    -1,   475,    -1,   480,
      -1,   507,    -1,   130,    -1,   131,    -1,   132,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   139,
      -1,   140,    -1,   141,    -1,   143,    -1,   144,    -1,   145,
      -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,
      -1,   151,    -1,    -1,     7,    -1,    -1,     8,    -1,    -1,
      22,    -1,    -1,    23,    -1,    -1,    26,    -1,    -1,    30,
      -1,    -1,    39,    -1,    -1,    49,    -1,    -1,    56,    -1,
      -1,    57,    -1,    -1,    86,    -1,    -1,   102,    -1,    -1,
     454,    -1,    -1,   176,    -1,    -1,   188,    -1,    -1,   196,
      -1,    -1,   218,    -1,    -1,   314,    -1,   218,   314,    -1,
      -1,   221,    -1,    -1,   456,    -1,    -1,   228,    -1,    -1,
     232,    -1,    -1,   232,    -1,    22,    -1,    -1,   237,    -1,
      -1,   242,    -1,   384,    -1,    -1,   252,    -1,   254,    -1,
      -1,   248,  1266,    -1,   249,  1247,    -1,    -1,   254,    -1,
      -1,   272,    -1,    -1,   299,    -1,    -1,   299,    -1,   300,
      -1,    -1,   306,    -1,    -1,   309,    -1,    -1,   423,   232,
      -1,   423,    -1,   232,    -1,    -1,   316,    -1,    -1,   337,
      -1,    -1,   340,    -1,    -1,   351,    -1,    -1,   384,    -1,
      -1,   405,    -1,    -1,   406,    -1,    -1,   405,    -1,   405,
     232,    -1,    -1,   410,    -1,    -1,   418,    -1,    -1,   423,
      -1,    -1,   437,    -1,    -1,   441,    -1,    -1,   445,    -1,
      -1,   446,    -1,    -1,   446,    -1,   497,    -1,    -1,   501,
      -1,    -1,   501,   403,   446,    -1,    -1,   503,    -1,    63,
     401,    -1,   401,    -1,    66,    -1,    64,    -1,    67,    -1,
      65,    -1,   452,    -1,   159,    -1,   165,    -1,   161,    -1,
     165,    -1,   461,    -1,   218,    -1,   306,    -1,   418,    -1,
     308,    -1,   252,    -1,   254,    -1,   351,    -1,   353,    -1,
      57,    -1,   505,    -1,   351,  1266,    -1,   353,  1247,    -1,
     356,    -1,   474,    -1,   252,    -1,   254,    -1,   410,    -1,
     244,    -1,   503,   124,    -1,   124,    -1,   340,    63,   401,
      -1,    63,   401,    -1,   401,    -1,   116,    -1,   106,    -1,
      89,   210,    -1,    54,    -1,    89,   187,    -1,    53,    -1,
     321,   210,    -1,   325,    -1,   321,   187,    -1,   326,    -1,
     366,   210,    -1,   383,    -1,   366,   187,    -1,   382,    -1,
      89,  1266,    -1,    90,  1247,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1340,  1340,  1340,  1372,  1373,  1377,  1378,  1382,  1383,
    1387,  1387,  1410,  1417,  1424,  1430,  1431,  1432,  1436,  1437,
    1441,  1465,  1466,  1470,  1504,  1510,  1522,  1496,  1532,  1531,
    1569,  1601,  1602,  1606,  1607,  1610,  1611,  1615,  1624,  1633,
    1634,  1638,  1642,  1651,  1652,  1660,  1661,  1671,  1672,  1676,
    1677,  1678,  1679,  1680,  1687,  1686,  1699,  1700,  1703,  1704,
    1718,  1717,  1727,  1728,  1729,  1730,  1734,  1735,  1739,  1740,
    1741,  1742,  1746,  1753,  1760,  1767,  1778,  1782,  1786,  1790,
    1797,  1798,  1805,  1804,  1815,  1816,  1817,  1824,  1825,  1829,
    1833,  1845,  1849,  1850,  1855,  1858,  1865,  1870,  1881,  1894,
    1895,  1903,  1904,  1908,  1909,  1910,  1911,  1912,  1913,  1914,
    1915,  1916,  1917,  1918,  1919,  1927,  1926,  1945,  1955,  1968,
    1976,  1979,  1980,  1984,  1994,  2010,  2009,  2033,  2039,  2045,
    2051,  2057,  2063,  2073,  2077,  2084,  2088,  2093,  2092,  2103,
    2107,  2114,  2115,  2116,  2117,  2118,  2119,  2126,  2141,  2144,
    2151,  2159,  2163,  2174,  2194,  2202,  2213,  2214,  2220,  2241,
    2242,  2246,  2250,  2271,  2294,  2376,  2379,  2388,  2407,  2423,
    2441,  2459,  2476,  2492,  2493,  2500,  2501,  2509,  2510,  2520,
    2521,  2526,  2525,  2546,  2556,  2557,  2561,  2562,  2563,  2564,
    2565,  2566,  2567,  2568,  2569,  2570,  2571,  2572,  2573,  2580,
    2586,  2596,  2609,  2622,  2638,  2639,  2640,  2641,  2644,  2645,
    2651,  2652,  2656,  2660,  2661,  2666,  2669,  2670,  2677,  2685,
    2686,  2687,  2694,  2721,  2732,  2739,  2741,  2742,  2748,  2748,
    2755,  2760,  2765,  2772,  2773,  2774,  2778,  2789,  2790,  2794,
    2799,  2804,  2809,  2820,  2831,  2841,  2849,  2850,  2851,  2857,
    2868,  2875,  2876,  2882,  2890,  2891,  2892,  2898,  2899,  2900,
    2907,  2908,  2912,  2913,  2919,  2947,  2948,  2949,  2950,  2957,
    2956,  2972,  2973,  2977,  2980,  2981,  2987,  2988,  2996,  2997,
    3005,  3006,  3010,  3031,  3030,  3047,  3054,  3058,  3064,  3065,
    3069,  3079,  3094,  3095,  3096,  3097,  3098,  3099,  3100,  3101,
    3102,  3109,  3116,  3116,  3116,  3122,  3142,  3176,  3207,  3208,
    3215,  3216,  3220,  3221,  3228,  3239,  3244,  3255,  3256,  3260,
    3261,  3267,  3278,  3296,  3297,  3301,  3302,  3303,  3307,  3314,
    3321,  3330,  3342,  3394,  3409,  3410,  3414,  3424,  3463,  3465,
    3464,  3480,  3483,  3483,  3500,  3501,  3503,  3507,  3509,  3508,
    3543,  3556,  3564,  3569,  3575,  3584,  3594,  3597,  3609,  3610,
    3611,  3612,  3616,  3620,  3624,  3628,  3632,  3636,  3640,  3644,
    3648,  3652,  3656,  3660,  3664,  3675,  3676,  3680,  3681,  3685,
    3686,  3687,  3691,  3692,  3696,  3722,  3726,  3735,  3739,  3748,
    3749,  3750,  3751,  3752,  3753,  3754,  3755,  3756,  3757,  3758,
    3759,  3760,  3761,  3768,  3792,  3820,  3823,  3832,  3857,  3868,
    3869,  3873,  3877,  3881,  3885,  3889,  3893,  3897,  3901,  3905,
    3909,  3913,  3917,  3921,  3926,  3931,  3935,  3939,  3947,  3951,
    3955,  3963,  3967,  3971,  3975,  3979,  3983,  3987,  3991,  3995,
    4003,  4011,  4015,  4019,  4023,  4027,  4031,  4039,  4040,  4044,
    4045,  4051,  4057,  4069,  4087,  4088,  4097,  4121,  4122,  4125,
    4126,  4133,  4157,  4158,  4175,  4176,  4179,  4180,  4187,  4188,
    4193,  4204,  4215,  4226,  4237,  4266,  4265,  4274,  4275,  4279,
    4280,  4283,  4284,  4297,  4310,  4331,  4340,  4354,  4356,  4355,
    4375,  4377,  4376,  4392,  4394,  4393,  4402,  4403,  4410,  4409,
    4422,  4423,  4424,  4431,  4436,  4440,  4441,  4447,  4454,  4458,
    4459,  4465,  4502,  4506,  4511,  4517,  4518,  4523,  4524,  4525,
    4526,  4527,  4531,  4538,  4545,  4552,  4559,  4565,  4566,  4571,
    4570,  4577,  4578,  4582,  4583,  4584,  4585,  4586,  4587,  4588,
    4589,  4590,  4591,  4592,  4593,  4594,  4595,  4596,  4597,  4601,
    4608,  4609,  4610,  4611,  4612,  4613,  4614,  4617,  4618,  4619,
    4622,  4623,  4627,  4634,  4640,  4641,  4645,  4646,  4650,  4657,
    4661,  4668,  4669,  4673,  4680,  4681,  4685,  4686,  4690,  4691,
    4692,  4696,  4697,  4701,  4702,  4706,  4713,  4720,  4728,  4730,
    4729,  4750,  4751,  4755,  4756,  4761,  4763,  4762,  4819,  4837,
    4838,  4842,  4846,  4850,  4854,  4858,  4862,  4866,  4870,  4874,
    4878,  4882,  4886,  4890,  4894,  4898,  4902,  4906,  4911,  4915,
    4919,  4924,  4929,  4934,  4939,  4940,  4941,  4942,  4943,  4944,
    4945,  4946,  4947,  4954,  4959,  4968,  4969,  4973,  4974,  4979,
    4982,  4986,  4994,  4997,  5001,  5009,  5020,  5028,  5030,  5040,
    5029,  5067,  5067,  5100,  5104,  5103,  5117,  5116,  5136,  5137,
    5142,  5149,  5151,  5155,  5165,  5167,  5175,  5183,  5191,  5220,
    5251,  5253,  5263,  5268,  5295,  5297,  5296,  5332,  5333,  5337,
    5338,  5339,  5356,  5357,  5368,  5367,  5417,  5418,  5422,  5470,
    5483,  5486,  5505,  5510,  5504,  5523,  5523,  5553,  5560,  5561,
    5562,  5563,  5564,  5565,  5566,  5567,  5568,  5569,  5570,  5571,
    5572,  5573,  5574,  5575,  5576,  5577,  5578,  5579,  5580,  5581,
    5582,  5583,  5584,  5585,  5586,  5587,  5588,  5589,  5590,  5591,
    5592,  5593,  5594,  5595,  5596,  5597,  5598,  5599,  5600,  5601,
    5602,  5603,  5604,  5605,  5606,  5607,  5608,  5609,  5623,  5635,
    5634,  5643,  5649,  5653,  5657,  5662,  5667,  5672,  5677,  5681,
    5685,  5689,  5693,  5698,  5702,  5706,  5710,  5714,  5718,  5722,
    5729,  5730,  5737,  5738,  5742,  5743,  5747,  5748,  5749,  5750,
    5751,  5755,  5759,  5760,  5763,  5764,  5767,  5768,  5774,  5775,
    5779,  5780,  5784,  5788,  5792,  5796,  5800,  5804,  5808,  5812,
    5816,  5820,  5824,  5828,  5832,  5836,  5840,  5844,  5848,  5852,
    5856,  5860,  5864,  5868,  5872,  5876,  5883,  5887,  5898,  5897,
    5906,  5910,  5914,  5920,  5921,  5928,  5932,  5943,  5942,  5951,
    5955,  5967,  5968,  5976,  5975,  5984,  5985,  5989,  5995,  5995,
    6002,  6001,  6011,  6031,  6035,  6040,  6045,  6066,  6070,  6069,
    6086,  6087,  6092,  6100,  6124,  6126,  6130,  6139,  6152,  6155,
    6159,  6163,  6186,  6187,  6191,  6192,  6197,  6200,  6208,  6212,
    6220,  6224,  6235,  6234,  6242,  6246,  6257,  6256,  6264,  6269,
    6277,  6278,  6279,  6280,  6281,  6289,  6288,  6297,  6304,  6308,
    6318,  6329,  6347,  6346,  6355,  6359,  6363,  6368,  6376,  6380,
    6391,  6390,  6400,  6404,  6408,  6412,  6416,  6420,  6421,  6430,
    6432,  6431,  6439,  6448,  6455,  6459,  6463,  6467,  6477,  6479,
    6483,  6484,  6487,  6489,  6496,  6497,  6501,  6502,  6507,  6511,
    6515,  6519,  6523,  6527,  6531,  6535,  6539,  6543,  6547,  6551,
    6555,  6559,  6563,  6567,  6574,  6578,  6589,  6588,  6597,  6601,
    6605,  6609,  6613,  6620,  6624,  6635,  6634,  6642,  6662,  6661,
    6685,  6693,  6694,  6699,  6710,  6721,  6735,  6739,  6746,  6747,
    6752,  6761,  6770,  6775,  6784,  6785,  6790,  6852,  6853,  6854,
    6858,  6859,  6863,  6867,  6878,  6877,  6889,  6890,  6911,  6925,
    6947,  6969,  6989,  7012,  7013,  7021,  7020,  7028,  7039,  7038,
    7048,  7055,  7054,  7067,  7076,  7080,  7091,  7107,  7106,  7115,
    7119,  7123,  7130,  7134,  7145,  7144,  7152,  7160,  7161,  7165,
    7166,  7167,  7172,  7175,  7182,  7186,  7194,  7201,  7202,  7203,
    7204,  7205,  7206,  7207,  7212,  7215,  7225,  7224,  7233,  7239,
    7251,  7250,  7259,  7263,  7267,  7271,  7278,  7279,  7280,  7281,
    7288,  7287,  7301,  7311,  7320,  7321,  7325,  7326,  7327,  7328,
    7329,  7330,  7334,  7335,  7339,  7344,  7351,  7352,  7353,  7354,
    7355,  7359,  7387,  7390,  7397,  7401,  7411,  7410,  7423,  7422,
    7430,  7434,  7445,  7444,  7453,  7457,  7464,  7468,  7479,  7478,
    7486,  7507,  7531,  7532,  7533,  7534,  7538,  7539,  7543,  7544,
    7545,  7546,  7558,  7557,  7568,  7574,  7573,  7584,  7592,  7600,
    7607,  7611,  7624,  7631,  7643,  7646,  7651,  7655,  7666,  7673,
    7674,  7678,  7679,  7682,  7683,  7688,  7699,  7698,  7707,  7734,
    7735,  7740,  7743,  7747,  7751,  7755,  7759,  7763,  7770,  7771,
    7775,  7776,  7780,  7784,  7794,  7805,  7804,  7812,  7822,  7833,
    7832,  7841,  7848,  7852,  7863,  7862,  7874,  7883,  7886,  7890,
    7897,  7901,  7911,  7923,  7922,  7931,  7935,  7944,  7945,  7950,
    7953,  7961,  7965,  7972,  7980,  7984,  7995,  7994,  8008,  8009,
    8010,  8011,  8012,  8013,  8017,  8018,  8022,  8023,  8029,  8038,
    8045,  8046,  8050,  8054,  8058,  8062,  8066,  8070,  8074,  8078,
    8087,  8091,  8100,  8109,  8110,  8114,  8123,  8124,  8128,  8132,
    8143,  8142,  8151,  8150,  8181,  8184,  8204,  8205,  8208,  8209,
    8217,  8218,  8223,  8228,  8238,  8254,  8259,  8269,  8286,  8285,
    8295,  8308,  8311,  8319,  8322,  8327,  8332,  8340,  8341,  8342,
    8343,  8344,  8345,  8349,  8357,  8358,  8362,  8366,  8377,  8376,
    8386,  8399,  8402,  8406,  8414,  8426,  8429,  8436,  8437,  8438,
    8439,  8446,  8445,  8454,  8461,  8462,  8466,  8467,  8468,  8472,
    8473,  8477,  8481,  8492,  8491,  8500,  8504,  8508,  8515,  8519,
    8529,  8540,  8541,  8548,  8547,  8556,  8562,  8574,  8573,  8581,
    8595,  8594,  8602,  8615,  8617,  8618,  8626,  8625,  8634,  8642,
    8643,  8648,  8649,  8654,  8661,  8662,  8667,  8674,  8675,  8679,
    8680,  8684,  8685,  8689,  8693,  8704,  8703,  8712,  8713,  8714,
    8715,  8716,  8720,  8747,  8750,  8762,  8772,  8777,  8782,  8787,
    8795,  8833,  8834,  8838,  8878,  8888,  8911,  8912,  8913,  8914,
    8918,  8927,  8933,  8943,  8952,  8961,  8962,  8969,  8968,  8980,
    8990,  8991,  8996,  8999,  9003,  9007,  9014,  9015,  9019,  9020,
    9024,  9028,  9040,  9043,  9044,  9053,  9054,  9063,  9066,  9067,
    9076,  9077,  9088,  9091,  9092,  9101,  9102,  9114,  9117,  9119,
    9129,  9130,  9142,  9143,  9147,  9148,  9149,  9153,  9162,  9173,
    9174,  9175,  9179,  9188,  9199,  9204,  9205,  9214,  9215,  9226,
    9230,  9240,  9247,  9254,  9254,  9264,  9265,  9266,  9270,  9279,
    9280,  9282,  9283,  9284,  9285,  9286,  9288,  9289,  9290,  9291,
    9292,  9293,  9295,  9296,  9297,  9299,  9300,  9301,  9302,  9303,
    9306,  9307,  9311,  9312,  9316,  9317,  9321,  9322,  9326,  9330,
    9336,  9340,  9346,  9347,  9348,  9352,  9353,  9354,  9358,  9359,
    9360,  9364,  9368,  9372,  9373,  9374,  9377,  9378,  9388,  9400,
    9409,  9421,  9430,  9442,  9457,  9458,  9463,  9472,  9478,  9498,
    9502,  9523,  9564,  9578,  9579,  9584,  9590,  9591,  9596,  9608,
    9609,  9610,  9617,  9628,  9629,  9633,  9641,  9649,  9653,  9660,
    9669,  9670,  9676,  9690,  9707,  9711,  9718,  9719,  9720,  9727,
    9731,  9738,  9739,  9740,  9741,  9742,  9746,  9750,  9754,  9758,
    9762,  9783,  9787,  9794,  9795,  9796,  9800,  9801,  9802,  9803,
    9804,  9808,  9812,  9819,  9820,  9824,  9825,  9829,  9830,  9834,
    9835,  9846,  9847,  9851,  9852,  9853,  9857,  9858,  9859,  9866,
    9867,  9871,  9872,  9876,  9877,  9878,  9884,  9888,  9892,  9893,
    9897,  9901,  9908,  9915,  9922,  9932,  9939,  9949,  9959,  9969,
    9982,  9986,  9994, 10002, 10006, 10016, 10031, 10054, 10077, 10093,
   10094, 10095, 10096, 10097, 10098, 10102, 10106, 10123, 10127, 10134,
   10135, 10136, 10137, 10138, 10139, 10140, 10146, 10150, 10154, 10158,
   10162, 10166, 10170, 10174, 10178, 10182, 10189, 10190, 10194, 10195,
   10196, 10200, 10201, 10202, 10206, 10210, 10214, 10221, 10225, 10229,
   10236, 10243, 10250, 10260, 10267, 10277, 10284, 10296, 10304, 10305,
   10309, 10310, 10314, 10315, 10320, 10323, 10331, 10334, 10341, 10343,
   10344, 10348, 10349, 10353, 10354, 10355, 10360, 10363, 10376, 10380,
   10388, 10392, 10396, 10400, 10404, 10408, 10412, 10416, 10423, 10424,
   10430, 10431, 10432, 10433, 10434, 10435, 10436, 10437, 10438, 10439,
   10440, 10441, 10442, 10443, 10444, 10445, 10446, 10447, 10448, 10449,
   10450, 10451, 10452, 10453, 10454, 10455, 10456, 10457, 10458, 10459,
   10460, 10461, 10462, 10463, 10464, 10465, 10466, 10467, 10468, 10469,
   10470, 10471, 10472, 10473, 10474, 10475, 10476, 10477, 10478, 10479,
   10480, 10481, 10482, 10483, 10484, 10485, 10486, 10487, 10488, 10489,
   10490, 10491, 10492, 10493, 10494, 10495, 10496, 10497, 10498, 10499,
   10506, 10506, 10507, 10507, 10508, 10508, 10509, 10509, 10510, 10510,
   10511, 10511, 10512, 10512, 10513, 10513, 10514, 10514, 10515, 10515,
   10516, 10516, 10517, 10517, 10518, 10518, 10519, 10519, 10520, 10520,
   10521, 10521, 10522, 10522, 10523, 10523, 10523, 10524, 10524, 10525,
   10525, 10526, 10526, 10527, 10527, 10528, 10528, 10528, 10529, 10529,
   10530, 10530, 10530, 10531, 10531, 10531, 10532, 10532, 10532, 10533,
   10533, 10534, 10534, 10535, 10535, 10536, 10536, 10536, 10537, 10537,
   10538, 10538, 10539, 10539, 10539, 10539, 10540, 10540, 10541, 10541,
   10542, 10542, 10543, 10543, 10544, 10544, 10545, 10545, 10546, 10546,
   10547, 10547, 10547, 10548, 10548, 10549, 10549, 10550, 10550, 10551,
   10551, 10552, 10552, 10553, 10553, 10554, 10554, 10555, 10555, 10555,
   10556, 10556, 10557, 10557, 10558, 10558, 10562, 10562, 10563, 10563,
   10564, 10564, 10565, 10565, 10566, 10566, 10567, 10567, 10568, 10568,
   10569, 10569, 10570, 10570, 10571, 10571, 10572, 10572, 10573, 10573,
   10574, 10574, 10575, 10575, 10576, 10576, 10577, 10577, 10580, 10581,
   10582, 10586, 10586, 10587, 10587, 10588, 10588, 10589, 10589, 10590,
   10590, 10591, 10591, 10592, 10592, 10593, 10593
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
  "identifier_list", "page_limit_clause", "page_line_column",
  "page_heading_list", "page_detail", "heading_clause", "first_detail",
  "last_heading", "last_detail", "footing_clause",
  "report_group_description_list", "report_group_description_entry",
  "$@25", "report_group_options", "report_group_option", "type_clause",
  "type_option", "control_final", "or_page", "next_group_clause",
  "sum_clause_list", "reset_clause", "data_or_final",
  "present_when_condition", "varying_clause", "line_clause",
  "line_keyword_clause", "column_clause", "col_keyword_clause",
  "report_line_integer_list", "line_or_plus", "report_col_integer_list",
  "col_or_plus", "source_clause", "group_indicate_clause",
  "report_usage_clause", "screen_section", "$@26",
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
  "exit_statement", "$@53", "exit_body", "exit_program_returning",
  "free_statement", "$@54", "free_body", "generate_statement", "$@55",
  "generate_body", "goto_statement", "$@56", "go_body", "goto_depending",
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
  "debugging_target", "all_refs", "use_start_end", "program_start_end",
  "use_reporting", "use_exception", "use_ex_keyw", "write_statement",
  "$@85", "write_body", "from_option", "write_option", "before_or_after",
  "write_handler", "end_write", "on_accp_exception",
  "opt_on_accp_exception", "opt_not_on_accp_exception",
  "on_disp_exception", "opt_on_disp_exception",
  "opt_not_on_disp_exception", "on_size_error", "opt_on_size_error",
  "opt_not_on_size_error", "on_overflow", "opt_on_overflow",
  "opt_not_on_overflow", "return_at_end", "at_end", "at_end_clause",
  "not_at_end_clause", "at_eop", "at_eop_clause", "not_at_eop_clause",
  "invalid_key", "opt_invalid_key_sentence",
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
  "_character", "_characters", "_contains", "_data", "_file", "_final",
  "_for", "_from", "_in", "_in_order", "_indicate", "_initial", "_into",
  "_is", "_is_are", "_key", "_left_or_right", "_line_or_lines", "_limits",
  "_lines", "_mode", "_number", "_numbers", "_of", "_on", "_onoff_status",
  "_other", "_procedure", "_program", "_record", "_right", "_sign",
  "_signed", "_sign_is", "_size", "_standard", "_status", "_tape", "_then",
  "_times", "_to", "_to_using", "_when", "_when_set_to", "_with",
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
     741,   741,   741,   742,   742,   742,   742,   743,   744,   745,
     745,   746,   747,   747,   747,   748,   748,   749,   749,   749,
     749,   749,   750,   751,   752,   753,   754,   755,   755,   757,
     756,   758,   758,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   760,
     761,   761,   761,   761,   761,   761,   761,   762,   762,   762,
     763,   763,   764,   765,   766,   766,   767,   767,   768,   769,
     770,   771,   771,   772,   773,   773,   774,   774,   775,   775,
     775,   776,   776,   777,   777,   778,   779,   780,   781,   782,
     781,   783,   783,   784,   784,   785,   786,   785,   785,   787,
     787,   788,   788,   788,   788,   788,   788,   788,   788,   788,
     788,   788,   788,   788,   788,   788,   788,   788,   788,   788,
     788,   788,   788,   788,   788,   788,   788,   788,   788,   788,
     788,   788,   788,   788,   788,   789,   789,   790,   790,   791,
     791,   791,   792,   792,   792,   793,   794,   795,   796,   797,
     795,   798,   795,   799,   800,   799,   801,   799,   802,   802,
     803,   804,   804,   804,   805,   805,   805,   805,   805,   805,
     806,   806,   807,   807,   808,   809,   808,   810,   810,   811,
     811,   811,   811,   811,   813,   812,   814,   814,   815,   816,
     817,   817,   819,   820,   818,   822,   821,   821,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   825,
     824,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     827,   827,   828,   828,   829,   829,   830,   830,   830,   830,
     830,   831,   832,   832,   833,   833,   834,   834,   835,   835,
     836,   836,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   838,   838,   840,   839,
     841,   841,   841,   842,   842,   843,   843,   845,   844,   846,
     846,   847,   847,   849,   848,   850,   850,   851,   852,   852,
     854,   853,   855,   856,   856,   856,   856,   857,   858,   857,
     859,   859,   860,   860,   861,   861,   861,   861,   862,   862,
     862,   862,   863,   863,   864,   864,   865,   865,   866,   866,
     867,   867,   869,   868,   870,   870,   872,   871,   873,   873,
     874,   874,   874,   874,   874,   876,   875,   877,   878,   878,
     879,   880,   882,   881,   883,   883,   884,   884,   885,   885,
     887,   886,   888,   888,   888,   888,   888,   888,   888,   889,
     890,   889,   891,   892,   892,   892,   892,   892,   893,   893,
     894,   894,   895,   895,   896,   896,   897,   897,   898,   898,
     898,   898,   898,   898,   898,   898,   898,   898,   898,   898,
     898,   898,   898,   898,   899,   899,   901,   900,   902,   902,
     902,   902,   902,   903,   903,   905,   904,   906,   908,   907,
     909,   910,   910,   911,   911,   911,   912,   912,   913,   913,
     914,   915,   916,   916,   917,   917,   918,   918,   918,   918,
     919,   919,   920,   920,   922,   921,   923,   923,   923,   923,
     923,   923,   923,   924,   924,   926,   925,   927,   929,   928,
     930,   932,   931,   933,   934,   934,   935,   937,   936,   938,
     938,   938,   939,   939,   941,   940,   942,   943,   943,   944,
     944,   944,   945,   945,   946,   946,   947,   948,   948,   948,
     948,   948,   948,   948,   949,   949,   951,   950,   952,   952,
     954,   953,   955,   956,   956,   956,   957,   957,   957,   957,
     959,   958,   960,   961,   962,   962,   963,   963,   963,   963,
     963,   963,   964,   964,   965,   965,   966,   966,   966,   966,
     966,   967,   968,   968,   969,   969,   971,   970,   973,   972,
     974,   974,   976,   975,   977,   977,   978,   978,   980,   979,
     981,   981,   982,   982,   982,   982,   983,   983,   984,   984,
     984,   984,   986,   985,   987,   988,   987,   987,   989,   989,
     990,   990,   991,   991,   992,   992,   992,   992,   992,   993,
     993,   994,   994,   995,   995,   996,   998,   997,   999,  1000,
    1000,  1001,  1001,  1001,  1001,  1001,  1001,  1001,  1002,  1002,
    1003,  1003,  1004,  1004,  1005,  1007,  1006,  1008,  1009,  1011,
    1010,  1012,  1013,  1013,  1015,  1014,  1016,  1017,  1017,  1017,
    1018,  1018,  1019,  1021,  1020,  1022,  1022,  1023,  1023,  1024,
    1024,  1025,  1025,  1026,  1027,  1027,  1029,  1028,  1030,  1030,
    1030,  1030,  1030,  1030,  1031,  1031,  1032,  1032,  1033,  1034,
    1035,  1035,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,
    1037,  1037,  1038,  1039,  1039,  1040,  1041,  1041,  1042,  1042,
    1044,  1043,  1046,  1045,  1047,  1047,  1048,  1048,  1049,  1049,
    1050,  1050,  1051,  1051,  1051,  1052,  1052,  1052,  1054,  1053,
    1055,  1056,  1056,  1057,  1057,  1057,  1057,  1058,  1058,  1058,
    1058,  1058,  1058,  1059,  1060,  1060,  1061,  1061,  1063,  1062,
    1062,  1064,  1064,  1064,  1064,  1065,  1065,  1066,  1066,  1066,
    1066,  1068,  1067,  1069,  1070,  1070,  1071,  1071,  1071,  1072,
    1072,  1073,  1073,  1075,  1074,  1076,  1076,  1076,  1077,  1077,
    1078,  1079,  1079,  1081,  1080,  1082,  1082,  1084,  1083,  1085,
    1087,  1086,  1088,  1089,  1089,  1089,  1091,  1090,  1092,  1093,
    1093,  1094,  1094,  1095,  1096,  1096,  1097,  1098,  1098,  1099,
    1099,  1100,  1100,  1101,  1101,  1103,  1102,  1104,  1104,  1104,
    1104,  1104,  1105,  1106,  1106,  1107,  1107,  1107,  1107,  1107,
    1108,  1109,  1109,  1110,  1110,  1110,  1111,  1111,  1111,  1111,
    1112,  1113,  1113,  1114,  1115,  1116,  1116,  1118,  1117,  1119,
    1120,  1120,  1121,  1121,  1121,  1121,  1122,  1122,  1123,  1123,
    1124,  1124,  1125,  1126,  1126,  1127,  1127,  1128,  1129,  1129,
    1130,  1130,  1131,  1132,  1132,  1133,  1133,  1134,  1135,  1135,
    1136,  1136,  1137,  1137,  1138,  1138,  1138,  1139,  1140,  1141,
    1141,  1141,  1142,  1143,  1144,  1145,  1145,  1146,  1146,  1147,
    1147,  1148,  1149,  1151,  1150,  1152,  1152,  1152,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,  1153,  1154,  1154,  1155,  1155,  1156,  1156,  1157,  1158,
    1159,  1159,  1160,  1160,  1160,  1161,  1161,  1161,  1162,  1162,
    1162,  1163,  1163,  1164,  1164,  1164,  1165,  1165,  1166,  1166,
    1166,  1166,  1166,  1166,  1167,  1167,  1168,  1169,  1170,  1171,
    1171,  1172,  1173,  1174,  1174,  1175,  1176,  1176,  1177,  1178,
    1178,  1178,  1179,  1180,  1180,  1181,  1182,  1183,  1183,  1184,
    1185,  1185,  1186,  1187,  1188,  1188,  1189,  1189,  1189,  1190,
    1190,  1191,  1191,  1191,  1191,  1191,  1191,  1191,  1191,  1191,
    1191,  1192,  1192,  1193,  1193,  1193,  1194,  1194,  1194,  1194,
    1194,  1194,  1194,  1195,  1195,  1196,  1196,  1197,  1197,  1198,
    1198,  1199,  1199,  1200,  1200,  1200,  1201,  1201,  1201,  1202,
    1202,  1203,  1203,  1204,  1204,  1204,  1205,  1206,  1207,  1207,
    1208,  1209,  1209,  1209,  1209,  1210,  1211,  1211,  1211,  1211,
    1212,  1212,  1213,  1214,  1214,  1215,  1216,  1217,  1218,  1218,
    1218,  1218,  1218,  1218,  1218,  1219,  1219,  1220,  1220,  1221,
    1221,  1221,  1221,  1221,  1221,  1221,  1222,  1222,  1222,  1222,
    1222,  1222,  1222,  1222,  1222,  1222,  1223,  1223,  1224,  1224,
    1224,  1225,  1225,  1225,  1226,  1226,  1226,  1227,  1227,  1227,
    1228,  1228,  1228,  1229,  1229,  1230,  1230,  1231,  1232,  1232,
    1233,  1233,  1234,  1234,  1235,  1235,  1236,  1236,  1237,  1237,
    1237,  1238,  1238,  1239,  1239,  1239,  1240,  1240,  1241,  1241,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1243,  1243,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1245,  1245,  1246,  1246,  1247,  1247,  1248,  1248,  1249,  1249,
    1250,  1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,
    1255,  1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,  1259,
    1260,  1260,  1261,  1261,  1262,  1262,  1262,  1263,  1263,  1264,
    1264,  1265,  1265,  1266,  1266,  1267,  1267,  1267,  1268,  1268,
    1269,  1269,  1269,  1270,  1270,  1270,  1271,  1271,  1271,  1272,
    1272,  1273,  1273,  1274,  1274,  1275,  1275,  1275,  1276,  1276,
    1277,  1277,  1278,  1278,  1278,  1278,  1279,  1279,  1280,  1280,
    1281,  1281,  1282,  1282,  1283,  1283,  1284,  1284,  1285,  1285,
    1286,  1286,  1286,  1287,  1287,  1288,  1288,  1289,  1289,  1290,
    1290,  1291,  1291,  1292,  1292,  1293,  1293,  1294,  1294,  1294,
    1295,  1295,  1296,  1296,  1297,  1297,  1298,  1298,  1299,  1299,
    1300,  1300,  1301,  1301,  1302,  1302,  1303,  1303,  1304,  1304,
    1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,
    1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,
    1314,  1315,  1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,
    1319,  1320,  1320,  1321,  1321,  1322,  1322
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
       2,     4,     1,     4,     2,     0,     2,     1,     1,     1,
       1,     1,     3,     4,     4,     4,     3,     0,     2,     0,
       5,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     2,     1,     2,     1,     1,     0,     2,     2,
       0,     2,     4,     4,     0,     3,     1,     1,     3,     6,
       2,     3,     2,     2,     3,     2,     1,     2,     2,     1,
       1,     1,     2,     2,     1,     4,     2,     3,     0,     0,
       5,     0,     1,     2,     3,     1,     0,     4,     3,     0,
       2,     2,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       5,     5,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     0,
       1,     1,     0,     1,     1,     3,     2,     0,     0,     0,
       9,     0,     4,     0,     0,     3,     0,     3,     1,     2,
       4,     0,     2,     2,     0,     3,     3,     4,     4,     3,
       0,     1,     0,     2,     0,     0,     7,     0,     2,     1,
       1,     2,     1,     1,     0,     6,     0,     2,     2,     1,
       0,     1,     0,     0,     3,     0,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       4,     6,     3,     3,     4,     3,     4,     3,     3,     4,
       4,     3,     4,     3,     4,     5,     3,     4,     3,     3,
       1,     1,     1,     2,     0,     1,     3,     3,     2,     2,
       2,     3,     3,     3,     0,     1,     0,     3,     0,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     0,     1,     0,     4,
       4,     5,     6,     0,     2,     0,     1,     0,     3,     3,
       4,     0,     2,     0,     3,     1,     2,     4,     0,     2,
       0,     4,     6,     0,     1,     1,     1,     0,     0,     3,
       1,     2,     2,     3,     0,     2,     2,     2,     0,     3,
       2,     4,     1,     1,     1,     1,     0,     2,     0,     2,
       0,     1,     0,     3,     1,     2,     0,     3,     2,     3,
       0,     1,     3,     3,     2,     0,     4,     4,     0,     1,
       1,     1,     0,     4,     3,     2,     1,     2,     0,     1,
       0,     4,     3,     3,     3,     3,     4,     2,     4,     1,
       0,     3,     5,     0,     2,     2,     2,     2,     0,     2,
       1,     1,     0,     2,     0,     1,     1,     2,     1,     2,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     0,     1,     0,     4,     4,     6,
       6,     8,     8,     0,     1,     0,     3,     2,     0,     4,
       2,     1,     3,     1,     1,     1,     2,     1,     1,     2,
       2,     3,     2,     3,     1,     3,     2,     1,     1,     1,
       0,     2,     0,     1,     0,     3,     0,     2,     1,     2,
       1,     1,     1,     0,     2,     0,     3,     1,     0,     3,
       1,     0,     3,     3,     0,     3,     2,     0,     6,     3,
       2,     1,     0,     1,     0,     3,     5,     0,     2,     0,
       3,     3,     0,     2,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     3,     1,     2,
       0,     3,     2,     1,     1,     1,     2,     1,     1,     1,
       0,     3,     2,     5,     1,     2,     2,     2,     1,     1,
       1,     2,     1,     2,     4,     2,     0,     1,     1,     1,
       1,     4,     0,     2,     3,     3,     0,     3,     0,     3,
       3,     4,     0,     4,     4,     6,     0,     1,     0,     3,
       4,     5,     1,     1,     1,     1,     0,     3,     0,     3,
       2,     1,     0,     3,     2,     0,     4,     2,     0,     1,
       1,     1,     1,     3,     0,     2,     1,     3,     3,     0,
       3,     1,     1,     1,     3,     7,     0,     4,     7,     0,
       2,     0,     2,     2,     3,     3,     3,     2,     0,     3,
       1,     1,     0,     1,     1,     0,     3,     2,     1,     0,
       4,     4,     0,     1,     0,     4,     4,     0,     2,     3,
       0,     1,     1,     0,     4,     4,     6,     0,     2,     0,
       2,     1,     2,     3,     0,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     3,     4,     1,     2,     3,     1,     2,     3,     3,
       0,     3,     0,     7,     0,     5,     0,     2,     0,     2,
       0,     3,     0,     2,     4,     0,     2,     4,     0,     4,
       4,     0,     3,     0,     4,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     1,     0,     1,     0,     4,
       2,     0,     2,     4,     4,     0,     1,     1,     1,     1,
       1,     0,     4,     5,     1,     2,     1,     3,     3,     0,
       4,     0,     1,     0,     4,     4,     6,     6,     0,     1,
       2,     0,     1,     0,     3,     1,     2,     0,     3,     5,
       0,     3,     2,     0,     1,     1,     0,     4,     6,     0,
       3,     1,     3,     2,     2,     2,     3,     0,     3,     0,
       3,     0,     3,     0,     1,     0,     3,     1,     1,     1,
       1,     1,     7,     0,     1,     1,     1,     1,     1,     1,
       4,     1,     2,     1,     2,     3,     0,     1,     2,     1,
       3,     1,     1,     4,     1,     1,     1,     0,     4,     5,
       0,     2,     0,     4,     3,     3,     1,     1,     1,     1,
       0,     1,     2,     0,     2,     0,     2,     2,     0,     2,
       0,     2,     2,     0,     2,     0,     2,     2,     0,     2,
       0,     2,     2,     1,     2,     1,     1,     2,     2,     2,
       1,     1,     2,     2,     2,     0,     2,     0,     2,     0,
       2,     1,     1,     0,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     2,     2,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     2,     2,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     0,     2,     1,     1,
       1,     3,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     2,     2,     2,     4,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     2,     2,     1,     1,     3,     2,     2,     1,
       1,     3,     3,     4,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     5,     5,
       4,     5,     5,     5,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     5,     0,     3,     2,
       1,     3,     3,     1,     3,     1,     3,     0,     0,     1,
       0,     1,     0,     1,     0,     2,     0,     2,     0,     1,
       1,     0,     1,     0,     1,     2,     0,     2,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     0,     1,
       0,     1,     1,     0,     1,     1,     0,     2,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     0,     1,
       0,     1,     0,     2,     1,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     2,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       0,     1,     0,     3,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     2,
       1,     1,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     2
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
    1763,    46,     0,     0,     0,  1806,  1763,  1763,  1763,     0,
       0,     0,     0,     0,  1763,     0,     0,  1738,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1764,     0,     0,  1492,   125,  1763,
    1763,  1807,  1763,     0,     0,     0,     0,  1763,  1763,    60,
      82,     0,    54,    98,  1739,     0,  1763,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1800,    39,  1763,     0,     0,     0,  1560,   169,  1485,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1493,
     150,   151,  1765,   154,  1565,  1185,  1184,   116,   120,  1792,
    1763,     0,   100,   149,   176,   177,    38,  1801,    36,     0,
    1572,  1568,  1573,  1571,  1569,  1574,  1570,   158,   159,   161,
     170,   165,  1848,  1849,     0,   163,     0,  1737,     0,     0,
       0,  1763,  1870,    80,    61,  1736,    66,    68,    69,    70,
      71,  1736,     0,  1763,     0,    83,     0,    87,    55,    58,
     152,  1767,  1766,   155,     0,  1792,  1795,  1794,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1835,   164,     0,  1561,   168,  1869,  1763,
       0,     0,    65,    67,    63,    81,  1736,  1763,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1566,
     153,   156,     0,  1793,   123,   118,   119,   122,   178,     0,
       0,  1634,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1868,    74,    64,     0,
    1486,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1635,   181,  1744,   266,   267,   268,  1726,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1745,  1819,  1727,  1748,
       0,   278,   259,   138,   139,  1856,  1857,    72,  1802,  1820,
    1740,  1749,     0,     0,     0,   280,     0,  1781,  1802,  1827,
       0,   239,     0,  1763,  1736,  1768,   241,     0,  1837,  1834,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1732,  1763,  1741,     0,  1471,   264,  1469,   277,     0,    25,
     140,  1782,  1763,  1803,  1768,  1828,  1829,   210,  1836,   242,
    1802,  1763,  1763,  1769,  1763,  1763,   251,  1726,   252,     0,
    1763,  1781,  1733,     0,     0,   270,   271,   274,  1470,   279,
     286,   287,   338,   281,   341,     0,     0,  1763,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1796,  1796,
       0,   253,     0,  1763,   240,   223,   272,     0,   273,     0,
     487,   282,  1617,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1491,  1490,   243,   244,   245,   246,   249,  1797,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1620,   216,   201,   217,   202,  1744,
     203,   200,   213,   199,   214,  1763,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1763,  1867,     0,   222,  1621,   209,
       0,   247,  1483,     0,   231,   230,   341,   488,     0,     0,
     588,   345,   350,   387,   356,  1740,  1763,     0,     0,  1763,
    1740,  1781,  1763,  1724,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1866,   248,
    1484,     0,   236,   340,   341,   491,     0,     0,    26,  1763,
    1728,     0,     0,     0,  1763,  1724,     0,     0,     0,     0,
       0,  1763,   334,  1725,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   651,     0,   474,   411,  1808,
    1808,  1808,  1808,  1808,  1830,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1804,   446,     0,   422,   408,   423,   424,     0,
       0,  1811,   426,   427,   425,  1770,   429,   430,   428,  1763,
    1765,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1729,     0,   384,     0,   357,   312,   332,  1858,  1859,
    1489,   321,  1487,  1851,  1850,   314,  1779,  1738,  1752,     0,
    1763,   318,   317,  1763,   337,     0,  1854,  1855,   234,   492,
     496,   589,     0,    27,   695,   485,   486,  1809,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1831,     0,
    1805,   471,   457,   403,  1554,   483,  1812,  1771,  1772,   472,
       0,     0,   405,   407,  1648,  1648,   386,     0,  1788,  1583,
       0,     0,  1579,  1584,  1582,  1580,  1585,  1581,   385,   358,
    1575,  1577,     0,   302,  1488,  1780,   323,     0,   305,  1753,
    1813,   331,     0,     0,   235,   495,   591,   653,     0,     0,
     473,     0,  1823,     0,  1552,  1553,     0,   410,   475,   477,
     479,     0,   404,  1736,   451,   452,  1576,  1789,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1738,
    1814,   310,   319,   316,   320,   315,     0,   497,     0,   595,
     590,   592,     0,   656,   654,   672,     0,   749,   818,   827,
     833,   840,   872,   876,   890,   885,   891,   892,   900,   946,
     955,   958,   984,   995,   998,  1001,   993,  1007,  1014,  1036,
    1040,  1076,  1078,  1082,     0,  1088,  1102,  1126,  1144,  1145,
    1148,  1149,  1154,  1162,  1163,  1176,  1210,  1228,     0,  1261,
    1273,  1281,  1283,   677,  1287,  1290,  1296,  1347,   697,   698,
     699,   700,   701,   702,   703,   704,   706,   705,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   696,   458,
    1824,   459,  1601,  1596,  1607,     0,  1458,  1460,     0,     0,
       0,  1599,     0,  1462,  1600,  1602,  1603,     0,     0,     0,
       0,  1598,  1607,  1597,  1442,  1440,  1447,  1450,  1452,  1455,
    1519,  1457,  1516,  1550,  1517,  1518,  1604,     0,     0,     0,
    1551,   484,   481,   478,     0,   406,  1649,   361,   374,  1578,
       0,     0,   324,   325,   326,   327,     0,   306,  1751,   312,
       0,  1472,   498,     0,   596,     0,   593,   661,   661,     0,
       0,  1651,  1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,
    1660,  1661,  1662,  1663,  1664,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,
    1690,  1691,  1692,  1693,  1694,  1695,  1650,  1696,  1697,  1698,
    1699,   748,     0,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,  1403,   986,     0,     0,  1825,   863,
     862,     0,  1006,  1403,     0,     0,     0,     0,     0,     0,
     747,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,  1257,  1260,  1248,  1258,  1259,  1250,     0,     0,  1282,
    1280,     0,   695,     0,     0,     0,     0,  1790,   462,     0,
    1594,  1520,  1521,  1522,     0,     0,     0,     0,     0,     0,
       0,  1454,     0,  1453,     0,  1595,  1443,  1444,  1562,     0,
       0,     0,     0,     0,     0,     0,     0,  1586,     0,     0,
       0,     0,   476,     0,   480,   330,   329,  1730,  1738,   311,
       0,   598,   599,   594,  1735,   661,   658,   664,     0,   661,
     673,   648,   771,   816,   774,   770,  1788,     0,     0,  1510,
     825,  1504,   823,  1499,  1501,  1502,  1503,   828,     0,  1622,
    1482,   834,   835,     0,  1478,  1480,  1479,   846,   844,   845,
     870,     0,  1532,   873,   874,  1531,   877,   880,  1788,   888,
       0,  1464,  1636,  1496,  1555,  1559,  1497,     0,   898,  1802,
    1579,   944,  1368,   909,   913,  1499,     0,  1501,   953,     0,
     847,   956,   965,   964,   982,     0,   961,   963,  1402,     0,
     988,   992,   990,   993,   991,   985,   996,   997,  1494,   999,
    1000,  1826,  1002,  1476,   994,  1821,  1401,  1015,  1017,  1037,
    1038,  1041,     0,  1043,  1044,  1045,  1077,  1214,  1547,  1548,
       0,  1079,     0,  1086,     0,  1095,  1092,  1094,  1093,  1089,
    1096,  1116,  1482,  1103,  1114,  1105,     0,  1112,     0,  1533,
    1479,  1535,     0,  1142,  1628,  1146,  1350,  1467,  1152,  1802,
    1160,  1350,     0,  1174,  1167,  1468,     0,  1475,  1177,  1178,
    1179,  1180,  1181,  1182,  1203,  1183,  1206,     0,  1473,     0,
       0,  1546,  1559,  1211,  1246,  1233,  1251,  1734,  1271,     0,
    1264,  1266,     0,  1278,     0,  1284,  1285,   683,   689,   678,
     679,   680,   682,     0,  1288,     0,  1291,  1293,  1313,  1299,
    1360,  1350,  1791,     0,   466,   461,  1609,  1442,  1440,  1459,
    1461,  1442,     0,     0,     0,  1442,  1513,  1514,  1515,     0,
    1463,  1456,  1442,     0,  1441,  1563,     0,  1446,  1445,  1449,
    1448,  1451,     0,     0,  1442,     0,  1763,  1731,     0,   308,
       0,  1763,  1810,   659,  1763,     0,   670,   662,   663,   674,
     817,   750,  1731,   784,   775,     0,     0,     0,     0,  1505,
    1506,  1507,   826,   819,     0,     0,  1500,  1624,  1623,   831,
     836,   838,     0,   871,   841,  1534,   847,   875,   880,  1860,
    1861,   878,     0,   881,     0,   889,   886,  1843,  1842,  1465,
       0,  1638,  1466,  1557,  1558,   895,   896,   899,   893,  1395,
     945,   901,   692,     0,   907,  1370,     0,   924,     0,   918,
    1368,  1368,  1368,  1368,   954,   947,     0,     0,   848,   957,
     983,   959,  1403,  1403,   960,   967,   968,   692,  1427,  1428,
    1429,  1423,  1825,  1415,  1435,  1438,  1437,  1439,  1431,  1422,
    1421,  1426,  1425,  1424,  1430,  1410,  1414,  1432,  1434,  1436,
    1412,  1413,  1409,  1411,  1404,  1405,  1416,  1417,  1418,  1419,
    1420,  1408,   989,   987,  1495,  1004,  1822,   692,  1019,     0,
    1039,     0,  1066,  1050,  1042,  1047,  1048,  1049,  1218,     0,
    1549,     0,     0,  1087,  1083,     0,  1096,  1834,     0,  1104,
    1110,  1111,   692,  1107,  1403,     0,     0,  1115,     0,  1143,
    1127,  1629,  1630,  1802,     0,  1147,  1153,  1150,  1129,  1161,
    1155,  1157,  1169,  1175,  1164,     0,  1169,     0,  1527,  1528,
    1204,  1207,     0,     0,  1474,  1187,     0,  1186,     0,     0,
    1557,  1247,  1229,  1235,  1763,  1236,  1231,     0,  1249,     0,
       0,  1272,  1262,     0,  1265,     0,  1279,  1274,     0,  1286,
     690,   688,   681,     0,  1294,  1295,  1292,  1314,  1297,  1734,
       0,  1361,  1348,  1352,   460,  1734,   456,   464,   465,  1768,
    1608,     0,  1604,  1604,  1604,     0,  1590,     0,  1604,  1564,
       0,  1604,  1604,  1833,     0,   328,  1790,   307,   502,  1763,
    1763,  1724,  1776,   527,   501,   505,   506,     0,  1746,   613,
    1763,   603,  1830,   604,  1839,  1838,     0,  1763,     0,   616,
     607,   612,  1783,   608,     0,   611,   618,   615,   609,   614,
       0,   619,   610,     0,   630,   624,   628,   627,   625,   629,
     600,   631,   626,     0,  1783,     0,  1763,   671,     0,     0,
     649,   780,   785,   786,  1783,  1783,   778,   779,  1783,   766,
    1363,  1841,  1840,   763,   755,   757,   758,     0,  1363,     0,
       0,     0,   772,   761,     0,   769,   752,   768,   753,  1524,
    1523,     0,  1509,     0,  1788,  1373,   824,  1559,  1497,     0,
    1626,   831,     0,   829,     0,     0,  1481,   858,   879,   884,
       0,     0,  1498,  1373,  1763,  1637,  1556,   897,   692,   894,
    1397,  1369,   693,   911,  1730,   692,  1367,   917,   916,   915,
     914,   925,  1368,  1763,   928,     0,   931,   932,     0,  1763,
     935,   936,   937,   938,     0,   939,  1368,   926,     0,   786,
     904,   905,   902,   903,     0,  1373,     0,   854,   962,   977,
     979,   978,   972,   974,   980,  1403,   969,   966,  1403,   970,
    1433,  1406,  1407,  1790,  1003,  1477,   692,  1011,  1012,  1825,
    1027,  1028,  1030,  1032,  1033,  1029,  1031,  1022,  1825,  1018,
       0,  1067,     0,  1069,  1068,  1070,  1052,  1062,     0,     0,
    1046,  1220,     0,  1754,     0,  1080,  1373,     0,     0,     0,
    1098,  1108,  1121,  1117,  1122,  1118,  1123,     0,  1113,  1357,
    1356,  1120,  1129,  1351,  1543,  1544,  1545,     0,     0,  1395,
       0,   692,     0,  1168,     0,     0,     0,  1205,     0,  1209,
    1208,  1201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1189,  1190,  1631,  1395,     0,  1252,  1817,  1817,  1267,
    1268,  1269,     0,  1373,     0,     0,   691,     0,  1618,     0,
    1269,  1157,  1720,     0,  1763,  1616,  1591,  1592,  1593,  1614,
    1611,  1612,  1589,  1605,     0,  1587,  1588,   482,     0,     0,
    1885,  1886,  1763,  1724,     0,   499,   503,  1747,   507,     0,
       0,   601,   602,   605,   606,     0,   633,  1784,  1763,  1823,
    1763,   634,   632,   646,  1763,   665,   666,   669,     0,   660,
     675,   677,  1763,   788,     0,     0,   776,   777,     0,   692,
     767,  1365,   754,   756,  1363,   764,   759,   760,   773,   762,
    1526,  1508,  1525,  1636,     0,   692,   820,  1375,  1557,  1558,
    1373,     0,  1625,   830,   832,   839,   837,   866,  1761,   883,
     882,   887,     0,  1396,   692,  1394,   695,  1371,   906,     0,
     929,   930,   933,   934,     0,  1399,  1399,   927,   908,   920,
     921,   919,   922,     0,   948,     0,   849,   850,   664,     0,
    1403,  1403,   976,   692,   973,     0,  1010,   692,  1013,  1008,
       0,     0,  1034,     0,     0,     0,  1063,  1065,     0,  1058,
    1072,  1059,  1060,  1051,  1054,  1072,  1212,  1763,  1768,     0,
    1755,  1219,  1081,  1084,     0,  1098,  1097,  1101,  1090,     0,
    1109,  1106,     0,     0,  1131,  1130,   692,  1151,  1383,  1156,
    1158,     0,  1170,  1403,  1403,  1165,  1171,  1188,  1200,  1202,
    1192,  1193,  1194,  1198,  1195,  1199,  1196,  1197,  1191,  1632,
    1245,     0,  1242,  1243,  1237,     0,  1230,  1865,  1864,     0,
    1818,  1255,  1255,  1378,     0,  1636,  1275,     0,   684,     0,
    1619,  1300,  1301,     0,  1304,  1307,  1311,  1305,  1395,  1721,
       0,   470,   467,   468,     0,  1606,   309,   504,  1777,  1778,
    1567,   515,   512,   352,   528,   508,   509,  1538,   623,  1536,
    1537,   622,   639,   645,     0,   642,   667,   668,   677,   695,
       0,     0,  1363,   781,   783,   782,  1364,   692,  1362,   765,
    1373,  1498,  1374,   692,  1372,  1556,   821,  1627,  1529,  1530,
    1846,  1847,   868,   692,  1788,  1762,   865,   864,   860,     0,
    1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1639,  1398,
       0,   941,   940,   943,     0,  1541,  1542,   942,     0,   912,
    1373,  1464,  1373,  1464,   851,   852,     0,   856,   855,   857,
     975,   981,   971,  1005,  1009,  1020,  1023,  1024,  1742,  1016,
    1825,  1021,  1072,  1072,     0,  1057,  1055,  1056,  1061,  1222,
       0,  1216,  1756,  1373,  1091,  1100,     0,  1124,     0,     0,
    1138,     0,  1387,   692,  1382,  1159,   692,   692,  1172,  1244,
    1234,  1238,  1239,  1240,  1241,  1232,  1253,  1256,  1254,   692,
    1263,  1380,  1763,  1373,  1373,   686,  1289,  1618,  1303,  1752,
    1309,  1752,  1378,   692,   692,  1349,  1359,  1390,  1391,  1358,
    1355,  1354,  1773,   469,   463,   511,  1852,  1853,   514,   354,
     529,   510,   637,   635,   638,   636,   640,   641,     0,   617,
     643,   644,     0,   695,   787,   792,  1763,   793,   794,   795,
    1763,   796,   797,   798,   799,   800,   801,   802,   804,   805,
     806,     0,   807,  1722,   808,   809,   810,   789,   790,   751,
    1366,   822,  1376,   692,   842,   867,     0,   859,  1862,  1863,
    1400,   923,   950,     0,   949,     0,   853,  1025,  1743,     0,
       0,  1053,  1064,  1072,  1759,  1759,  1073,     0,     0,  1225,
    1221,  1215,  1085,  1099,     0,  1132,  1763,  1395,     0,     0,
    1133,     0,  1137,  1388,  1166,  1173,  1379,   692,  1377,     0,
    1277,  1276,  1315,   685,     0,  1302,     0,  1752,  1306,     0,
    1298,  1392,  1393,  1389,  1774,  1775,  1353,     0,  1763,  1763,
       0,   516,   517,   518,   519,   520,   521,     0,   531,   620,
     621,     0,     0,     0,  1763,  1399,  1399,  1723,     0,   791,
     869,   861,  1373,  1373,     0,  1035,  1071,  1760,     0,     0,
    1763,  1223,     0,     0,  1213,  1217,     0,     0,  1128,  1141,
    1385,  1386,  1140,  1136,  1134,  1135,  1381,  1270,  1323,   687,
    1308,     0,  1312,  1872,  1871,  1763,     0,     0,  1874,     0,
    1763,  1763,   513,  1810,     0,   812,   811,     0,   814,   813,
     815,  1539,  1540,   952,   951,  1026,  1075,  1074,     0,  1226,
    1763,  1403,  1139,  1384,  1346,  1345,  1324,  1316,  1317,  1722,
    1318,  1319,  1320,  1321,  1344,     0,     0,  1310,     0,   526,
     522,  1873,     0,     0,  1757,  1785,  1724,     0,     0,     0,
    1763,  1788,   530,  1763,  1763,     0,   536,   538,   547,   539,
     541,   544,   532,   533,   534,   543,   545,   548,   535,     0,
     540,     0,   542,   546,   537,  1785,  1724,   676,   803,  1224,
       0,  1125,     0,  1815,     0,  1790,   523,   525,   524,  1758,
     586,  1786,  1787,  1765,   572,  1763,   457,  1403,     0,     0,
       0,     0,     0,   580,     0,   570,   576,   579,     0,   573,
     581,   584,  1765,   575,  1227,     0,  1816,     0,  1342,  1341,
    1340,     0,   571,     0,  1823,   568,  1636,   564,  1511,  1876,
       0,     0,  1878,  1880,     0,  1884,  1882,   549,   553,   557,
     557,   551,   555,   550,   556,   587,     0,   578,   577,   583,
     582,   574,  1343,  1845,  1844,  1798,  1336,  1330,  1331,  1333,
     562,   459,   585,  1790,   563,  1512,  1875,  1879,  1877,  1883,
    1881,   560,   552,   560,   554,     0,  1799,  1790,  1339,  1334,
    1337,     0,  1332,   454,     0,     0,   559,   558,     0,     0,
    1338,  1335,     0,   453,   567,   565,   566,   561,   569,  1329,
    1326,  1328,  1327,  1322,  1325,   455
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
     434,   503,   435,   534,   566,   567,   827,   568,  1667,  1009,
     763,   569,   570,   703,   833,   571,   572,   828,  1002,  1003,
    1004,  1005,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   758,   814,
     815,   816,   817,   818,   500,   683,   589,   661,   662,   663,
     792,   664,   665,   666,   667,   668,   669,   670,  2548,  2683,
     671,   782,  1148,  1384,  1385,  1649,  1646,  2152,  2153,   672,
     673,   674,   675,   676,   992,   788,   789,  1182,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1190,  1421,
    1674,  1675,  1958,  2165,  1676,  2161,  2315,  2431,  2432,  2433,
    2434,  2435,  2436,  1955,  2164,  2438,  2493,  2552,  2553,  2627,
    2662,  2676,  2554,  2555,  2654,  2685,  2556,  2557,  2558,  2559,
    2560,  2561,  2595,  2596,  2599,  2600,  2562,  2563,  2564,   588,
     776,   840,   841,   842,  1192,  1422,  1710,  2326,  2327,  2328,
    2332,  1711,  1712,   713,  1429,  1981,   714,   845,  1018,  1017,
    1195,  1196,  1197,  1426,  1718,  1020,  1720,  2178,  1142,  1369,
    1370,  2295,  2413,  1371,  1372,  1925,  1781,  1782,  2026,  1373,
     779,   898,   899,  1092,  1203,  1204,  1746,  1433,  1489,  1726,
    1727,  1723,  1983,  2182,  2357,  2358,  1431,   900,  1093,  1210,
    1445,  1443,   901,  1094,  1217,  1763,   902,  1095,  1221,  1222,
    1765,   903,  1096,  1230,  1231,  1499,  1817,  2046,  2047,  2048,
    2017,  1111,  2208,  2202,  2364,  1454,   904,  1097,  1233,   905,
    1098,  1236,  1461,   906,  1099,  1239,  1466,   907,   908,   909,
    1100,  1248,  1475,  1478,   910,  1101,  1251,  1252,  1483,  1253,
    1487,  1809,  2041,  2229,  1792,  1806,  1807,  1481,   911,  1102,
    1258,  1495,   912,  1103,  1261,   913,  1104,  1264,  1265,  1266,
    1504,  1505,  1506,  1827,  1507,  1822,  1823,  2052,  1501,   914,
    1105,  1275,  1112,   915,  1106,  1276,   916,  1107,  1279,   917,
    1108,  1282,  1834,   918,   919,  1113,  1838,  2059,   920,  1114,
    1287,  1548,  1847,  2062,  2246,  2247,  2248,  2249,   921,  1115,
    1289,   922,  1116,  1291,  1292,  1554,  1555,  1859,  1556,  1557,
    2073,  2074,  1856,  1857,  1858,  2067,  2255,  2386,   923,  1117,
     924,  1118,  1301,   925,  1119,  1303,  1564,   926,  1121,  1309,
    1310,  1568,  2088,   927,  1122,  1313,  1572,  2091,  1573,  1314,
    1315,  1316,  1873,  1875,  1876,   928,  1123,  1323,  1888,  2270,
    2397,  2468,  1580,   929,   930,  1124,  1325,   931,   932,  1125,
    1328,  1587,   933,  1126,  1330,  1889,  1590,   934,   935,  1127,
    1333,  1596,  1892,  2105,  2106,  1594,   936,  1128,  1338,   159,
    1608,  1339,  1340,  1911,  1912,  1341,  1342,  1343,  1344,  1345,
    1346,   937,  1129,  1296,  2259,  1558,  2391,  1861,  2076,  2389,
    2464,   938,  1130,  1354,  1914,  1616,  2121,  2122,  2123,  1612,
     939,  1356,  1618,  2286,  1136,   940,  1137,  1358,  1359,  1360,
    2133,  1622,   941,  1138,  1363,  1627,   942,  1140,   943,  1141,
    1365,   944,  1143,  1374,   945,  1144,  1376,  1636,   946,  1145,
    1378,  1640,  2141,  2142,  1930,  2144,  2300,  2418,  2302,  1638,
    2414,  2478,  2517,  2518,  2519,  2693,  2520,  2647,  2648,  2671,
    2521,  2610,  2522,  2523,  2524,   947,  1146,  1380,  1585,  1931,
    1881,  2305,  1642,  1990,  1991,  2188,  1484,  1485,  1786,  2006,
    2007,  2194,  2290,  2291,  2408,  2097,  2469,  2098,  2274,  2306,
    2307,  2308,  1779,  1780,  2025,  2223,  1285,  1286,  1268,  1269,
    1534,  1535,  1536,  1537,  1538,  1539,  1540,   974,  1169,  1388,
     976,   977,   978,   979,  1211,  1240,  1469,  1326,  1334,   395,
     396,  1012,  1347,  1348,  1545,  1317,  1224,  1225,   541,   481,
     301,   691,   692,   482,    98,   153,  1277,  1242,  1212,  1446,
    2617,  1395,   981,  1751,  2001,  2075,  2197,  1234,  1318,  2168,
    2500,  2224,  1883,  2169,  1297,  1351,  1214,   983,  1243,  1244,
     734,   784,   785,  2170,   271,  2597,   179,  1215,   760,   761,
    1216,   986,   987,   988,  1177,  1150,  1403,  1399,  1392,   501,
    2143,   537,  1449,  1761,  2012,  1583,  2125,   282,  1472,  1775,
    2218,   794,  1091,  2150,  2448,   604,   339,   684,  1435,   423,
    1198,   202,   115,   393,  2379,   337,  1959,   352,  1010,   770,
    2081,  2580,  2458,  2209,    96,   214,   414,   739,  2426,  1954,
     766,   402,  1968,  2583,   798,  1383,   218,   488,  2667,   168,
     390,   731,   102,   719,   680,   831,  2607,  2131,   350,  1547,
     951,  1283,   407,   729,  1183,  1322,   391,  1728,  1748,  1470,
    2645,  2203,   184,   695,  2318,   708,   347,   596,  1463,  2370,
    2129,   538,   203,  2485,  2491,  2630,  2631,  2632,  2633,  2634,
    1678
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2263
static const yytype_int16 yypact[] =
{
   -2263,   265,   -25, -2263,   289,   411, -2263,   -25, -2263, -2263,
     884, -2263, -2263,   884,   884,   -64,   -64, -2263,   590, -2263,
     990,   739,   977, -2263, -2263,  1211,  1211,   685,   873, -2263,
   -2263,     5,   884,   -64, -2263, -2263,  1026,   894, -2263, -2263,
     900,  1190,   -64, -2263, -2263, -2263,   739,   926, -2263, -2263,
     -42, -2263,   901,   901,   961,   992,  1188,  1188,  1188,  1034,
     901,  1036,   980,  1001,  1188,  1004,  1020,  1419, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,  1166, -2263, -2263, -2263, -2263,
    1268, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1335,  1068,     5, -2263, -2263,  1071,   697, -2263, -2263,  1188,
    1188, -2263,  1188,  1019,  1459,  1019,  1082,  1188,  1188, -2263,
   -2263,  1019, -2263, -2263, -2263,  1030,   -23,  1098, -2263, -2263,
    1046, -2263,  1106, -2263, -2263, -2263, -2263,  -163, -2263, -2263,
   -2263,  1222, -2263,  1188,  1323,  1019,  1305,   -31, -2263, -2263,
   -2263, -2263, -2263,  1309,  1100,   747,  1372, -2263,  1072, -2263,
    1030, -2263,    53, -2263, -2263, -2263, -2263, -2263,  1003,   -86,
    1188,    30, -2263, -2263, -2263,   450, -2263, -2263, -2263,  1227,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1323, -2263,  1130,
   -2263,  -168, -2263, -2263,  1019, -2263,  1181, -2263,  1182,  1174,
    1523,  1188, -2263, -2263, -2263,   408, -2263, -2263, -2263, -2263,
   -2263,   877,  1528,  1188,    97, -2263,    84, -2263, -2263,   -14,
   -2263, -2263, -2263, -2263,  1336,   -86, -2263,  1359,   901,   901,
   -2263,  1003,  1142,   129,   -88, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   742, -2263,
      71, -2263,  1323, -2263, -2263,  1269, -2263, -2263, -2263,  1188,
    1195,  1344, -2263, -2263, -2263, -2263,   925,  1188,  1102,  1379,
     518, -2263,  1575,   539,  1160, -2263, -2263,  1161,  1506, -2263,
    1336, -2263,   901, -2263, -2263, -2263, -2263,  1003, -2263,  1164,
    1314, -2263,   901, -2263,   567, -2263,   234, -2263, -2263, -2263,
   -2263, -2263,   742, -2263,  1366,  1344, -2263, -2263, -2263,   665,
   -2263, -2263, -2263,  1374, -2263, -2263, -2263, -2263, -2263,  1355,
   -2263, -2263, -2263, -2263, -2263,  1178, -2263, -2263, -2263,  1605,
    1531,  1191, -2263, -2263,   742, -2263, -2263,    12, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1198, -2263,  1456,
    1526,  1203, -2263,  1628, -2263, -2263, -2263, -2263,  1861, -2263,
    1567, -2263,  1156,  1217,  1277, -2263,   742,  1400,  1322,   622,
    1274, -2263,  1275,  1188,  1620,   237,   -78,   893, -2263,  1183,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1265,
   -2263,  1428, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1653,  1188, -2263,  1156, -2263,  1156, -2263, -2263,  1247,   480,
   -2263, -2263,  1188, -2263,  1462, -2263, -2263,   758, -2263, -2263,
     920,  1188,  1188, -2263,  1188,  1188, -2263,  1605, -2263,   527,
    1188,  1400, -2263,  1298,  1197,  1156, -2263,  1373, -2263, -2263,
   -2263, -2263,  1196, -2263,  1201,    54,   107,  1188, -2263, -2263,
     714, -2263, -2263,   125,  1284,  1019,  1019, -2263,  1390,  1390,
    1398, -2263,  1019,  1188, -2263, -2263, -2263,  1344, -2263,  1316,
    1452, -2263, -2263,  1264, -2263, -2263, -2263, -2263, -2263,  1019,
   -2263, -2263,   409,   409,  1711,   409, -2263, -2263,   409,   410,
   -2263, -2263, -2263, -2263, -2263,  -193, -2263, -2263, -2263, -2263,
   -2263, -2263,   139, -2263,  1271,  1332,  1465,   546,  1279,  5956,
   -2263,  1224, -2263, -2263,   -41, -2263, -2263, -2263, -2263,  1178,
   -2263, -2263, -2263, -2263, -2263,  1188,  1019,  1230, -2263,  1230,
   -2263, -2263,  1283,  1341,  1375, -2263,  1289, -2263,  1291, -2263,
    1658, -2263,  1659, -2263,   888, -2263,  1622, -2263, -2263, -2263,
    1019,  1019, -2263,   386, -2263, -2263,  1201, -2263,  1299,  1358,
    1364, -2263, -2263, -2263,    38,  1567,  1188,  1085,  1085,  1188,
      25,  1400,  1188,  1732, -2263,  1449, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   901,   991, -2263,  1019,
   -2263,  1447, -2263, -2263,  1201, -2263,  1307,  1365, -2263,  6264,
     131,  1556,  1344,  1262,  1188,  1732,  1263,  -108,   125,  1344,
    1270,  1188, -2263, -2263, -2263,   -65,   901, -2263, -2263, -2263,
     688, -2263,  1201, -2263,  1320,   707,   686, -2263, -2263,  -203,
    -180,   324,   395,   495,  1272, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  1388, -2263,  1344, -2263, -2263, -2263, -2263,  1019,
    1019,  1544, -2263, -2263, -2263,   563, -2263, -2263, -2263,  1188,
     634, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1015,
    -116, -2263,  1273, -2263,   687, -2263,  1333, -2263, -2263, -2263,
   -2263,  1263, -2263, -2263, -2263, -2263,  1527,    56,  1564,  1282,
    1188, -2263, -2263,  1188, -2263,  1095, -2263, -2263, -2263, -2263,
   -2263, -2263,  1665, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1280,
   -2263, -2263,  1343, -2263,  1334,  1353, -2263, -2263, -2263, -2263,
    6431,   263,  1772, -2263,  1401,  1401, -2263,  1451,  1494, -2263,
    1331,  1331, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1356, -2263,  1344,    61, -2263, -2263, -2263,  1344, -2263, -2263,
    1392, -2263,   437,   437, -2263,  1467,  1315,    98,  2474,  3714,
   -2263,  1344,  1391,  6946,  1354, -2263,  1019, -2263,   263, -2263,
    1395,  1561, -2263,  1620, -2263, -2263, -2263, -2263,  1331,  1383,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1451, -2263, -2263, -2263, -2263,   137,  1419,
   -2263,    11, -2263, -2263, -2263, -2263,  1337, -2263,  5774, -2263,
   -2263,  1315,  1387, -2263, -2263,  1463,  4098, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   -47, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1444, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   557, -2263,
   -2263,  1504, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263,  1733, -2263, -2263,  1384,  5407,   -31,   -31,  1386,  1396,
    1397, -2263,  1402,   -31, -2263, -2263, -2263,  6962,  6946,  6962,
    1407, -2263,  1384, -2263,    67,   880,   744, -2263,  1680, -2263,
   -2263, -2263, -2263, -2263,  1356, -2263,  1409,  1413,  1414,  6946,
   -2263, -2263,  -235, -2263,   263, -2263, -2263, -2263, -2263, -2263,
     125,   125, -2263, -2263, -2263, -2263,  1664, -2263, -2263,  1333,
    1344, -2263, -2263,  1403, -2263,  1412, -2263,   116,   116,  1349,
    1426, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  -173,  1779,  6946,   487,   550,   501,  1156,   613,
     548,  5094,  5275,  1604,   819,   971,   613,  1019,  1437, -2263,
   -2263,  5275, -2263, -2263,   613,  1337,  5371,  1019,  2759,  5275,
   -2263,   921,  3553,  1156,  1019,  1156,  1019,    52,   245,  1019,
    1156, -2263, -2263, -2263, -2263, -2263, -2263,  4012,  3581, -2263,
   -2263,  1337,    92,  1019,  1156,  1019,  1019,  1577, -2263,  6569,
   -2263, -2263,  1356, -2263,  1380,  1385,  6946,  6946,  6946,  5407,
    1399, -2263,   841, -2263,  5407, -2263, -2263, -2263, -2263,  6946,
    6691,  6946,  6946,  6946,  6946,  6946,  6946, -2263,  5407,  6946,
     880,  1484, -2263,  1439, -2263, -2263, -2263,  1864,  1419, -2263,
     360, -2263, -2263, -2263, -2263,   310, -2263,  -205,  -177,   340,
   -2263, -2263, -2263,  1765,   764,  1701,  1494,  1019,  5407, -2263,
    1769, -2263,  4635, -2263, -2263, -2263, -2263, -2263,   196,  1078,
   -2263,   487, -2263,  1455, -2263,   -31, -2263, -2263, -2263, -2263,
    1770,  2160, -2263,   501, -2263, -2263,  1156,   966,  1494,  1771,
     145, -2263,  1520, -2263, -2263,  1334,  1356,  1156,  1778,  1322,
    1010,  1780,  4695, -2263,  4763,   103,  1133,  1179,  1777,   653,
    1417, -2263, -2263, -2263,  1781,    50, -2263, -2263, -2263,  4597,
   -2263, -2263,  1815,   -47, -2263, -2263, -2263,   613, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,  1476, -2263, -2263,   424,  1337,
   -2263, -2263,   371, -2263, -2263, -2263, -2263, -2263, -2263,  1457,
    5275, -2263,  1474,  1782,  1872, -2263, -2263, -2263, -2263,   921,
    1521, -2263,  1483, -2263,  5999,     0,   794,  1488,  1489, -2263,
     728, -2263,  1496,  1800,   829, -2263,  1752, -2263,  1806,  1322,
    1807,  1752,  1019,  1808,  1458, -2263,  1308, -2263, -2263, -2263,
   -2263, -2263, -2263,  1684, -2263,   613, -2263,   -95, -2263,   282,
    1920, -2263,    58, -2263,  1809,   835,   474,  1910,  1814,   954,
   -2263, -2263,  1019,  1816,  4971,  1337, -2263, -2263,   633, -2263,
   -2263, -2263, -2263,  3525, -2263,  1767, -2263,  1110,  1818,  1852,
    1821,  1752, -2263,  1019,  1746,   183, -2263,    70,   922, -2263,
   -2263,   293,  1525,  1530,  1534,   210, -2263,  1356, -2263,  1535,
   -2263, -2263,   225,  1536,   922, -2263,   898,   744,   744, -2263,
   -2263, -2263,   952,  1537,   252,  1529,  1188, -2263,   125,  1855,
    1538,   156,  6481, -2263,  1188,  1566,  1662, -2263, -2263,  1877,
   -2263, -2263,  1308,  1790, -2263,   733,  1805,   -49,  1542, -2263,
    1356, -2263, -2263, -2263,  5335,  1787, -2263,  1773, -2263,  1616,
   -2263,  1654,  1738, -2263, -2263, -2263,  1417, -2263,   966, -2263,
   -2263, -2263,   834,   511,  1019, -2263, -2263, -2263, -2263, -2263,
    6946,  1723, -2263,  1354, -2263,  1156, -2263, -2263, -2263,  1774,
   -2263, -2263, -2263,  5275, -2263,  1706,   123,  1703,  2045,  1518,
    1838,  1838,  1838,  1838, -2263, -2263,  5275,  5335, -2263, -2263,
   -2263, -2263,   819,   168, -2263,  1503, -2263,  1505, -2263, -2263,
   -2263, -2263,  1437, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  4330, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   -12, -2263,  1879,  1554,  1833,
   -2263,  1308,    85, -2263, -2263,  1644, -2263, -2263,   101,  6946,
   -2263,  1565,   613, -2263, -2263,  5335,  1521,  1183,  1156, -2263,
   -2263, -2263, -2263, -2263,  1844,  1019,   487, -2263,   223, -2263,
   -2263, -2263, -2263,  1322,  5371, -2263, -2263, -2263,  1786, -2263,
   -2263,   375,  1886, -2263, -2263,  1019,  1886,  1570, -2263,  1356,
   -2263, -2263,   466,  1003, -2263, -2263,  2569, -2263,  1968,  1371,
      60, -2263, -2263, -2263,  1188, -2263,   443,  5275, -2263,    36,
    5067, -2263, -2263,  1019, -2263,  1823, -2263, -2263,  5335, -2263,
    1344, -2263, -2263,  1308, -2263, -2263, -2263, -2263, -2263,  1910,
    1792, -2263, -2263,   223, -2263,  1910, -2263, -2263, -2263,  1462,
   -2263,  1019,  1409,  1409,  1409,  5407, -2263,   220,  1409, -2263,
    6842,  1409,  1409, -2263,   263, -2263,  1577, -2263, -2263,  1188,
    1188,  1732,   570, -2263, -2263, -2263, -2263,  1817,  1846, -2263,
    1188, -2263,   -74, -2263, -2263, -2263,  1312,  1188,  2160, -2263,
   -2263, -2263,  1724, -2263,  1344, -2263,  1969, -2263, -2263, -2263,
    1019, -2263, -2263,  1019, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1822,  1724,   585,  1188, -2263,  1524,  1578,
   -2263, -2263, -2263,  1759,  1724,  1724,   655,  1784,  1724, -2263,
    1868, -2263, -2263, -2263,  1532,  1541, -2263,  1308,  1868,  1803,
    1621,  1753, -2263, -2263,  1785, -2263, -2263, -2263, -2263, -2263,
   -2263,   503, -2263,  1019,  1494,   200, -2263,   -60,   -67,   613,
    1607,  1616,   613, -2263,  1608,   487, -2263,   -47, -2263, -2263,
    1675,  1696, -2263,  -200,  1188, -2263, -2263, -2263, -2263, -2263,
    1768, -2263, -2263, -2263,  2030, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  1838,  1188, -2263,   -71, -2263, -2263,  1326,  1188,
   -2263, -2263, -2263, -2263,    -2, -2263,  1853, -2263,   860,  1759,
   -2263, -2263, -2263, -2263,  1859,   200,  1862,   112, -2263, -2263,
   -2263, -2263,  2049, -2263,  1626,   181, -2263, -2263,   168, -2263,
   -2263, -2263, -2263,  1577, -2263, -2263, -2263,  1943,  1933,  1437,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1708,  1437, -2263,
    1631, -2263,  2029, -2263, -2263, -2263,   845, -2263,  1308,  1084,
   -2263,    59,   183,   532,   613,   613,   200,  1876,  1156,   527,
     680,  1944, -2263, -2263, -2263,  2076, -2263,  1890, -2263, -2263,
   -2263, -2263,  1786, -2263, -2263, -2263, -2263,  1019,  1958,  1774,
     947, -2263,  1588, -2263,  1591,  1308,   899, -2263,   503, -2263,
   -2263, -2263,  5275,  1003,  1003,  1003,  1003,  1003,  1003,  1003,
    1003,  1371, -2263,    18,  1774,   481, -2263,  1670,  1670, -2263,
   -2263,  -159,  1019,   200,  1891,  1645, -2263,  1649,  2088,  1019,
     506,   375,  2091,  1595,  1188, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,   941, -2263, -2263, -2263,  1019,   501,
   -2263, -2263,  1188,  1732,  1847,  1315, -2263, -2263, -2263,  1019,
    -136, -2263, -2263, -2263, -2263,  -136, -2263, -2263,  1188,  1391,
    1188, -2263, -2263, -2263,  1188, -2263, -2263, -2263,   147, -2263,
   -2263, -2263,  1188,  1597,  -136,  -136, -2263, -2263,  -136, -2263,
   -2263,  1810, -2263, -2263,  1868, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1520,   -49, -2263, -2263,  1811,   -58,  1899,
     200,   692, -2263, -2263, -2263, -2263, -2263,   -38,    89, -2263,
   -2263, -2263,  1035, -2263, -2263, -2263, -2263, -2263, -2263,  -136,
   -2263, -2263, -2263, -2263,  -136,   531,   531, -2263, -2263, -2263,
   -2263, -2263,  1603,   613, -2263,   613,  1221, -2263,   555,   128,
     168, -2263, -2263, -2263,  2049,  1019, -2263, -2263, -2263, -2263,
    1609,  1149,   429,  1611,   692,  1308, -2263, -2263,  2061, -2263,
   -2263, -2263, -2263,  1084, -2263,  1923, -2263,  1188,  1462,  1798,
   -2263, -2263,   613, -2263,   613,   680, -2263, -2263, -2263,   981,
   -2263, -2263,  1019,  5275,  1393, -2263, -2263, -2263,  1824, -2263,
   -2263,  1854, -2263, -2263, -2263, -2263,  1591, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   -45,
   -2263,  1019, -2263, -2263, -2263,   649, -2263, -2263, -2263,  6946,
   -2263,  5275,  5275,  1660,  1789,  1520, -2263,   613, -2263,   692,
   -2263,  1801, -2263,  1308, -2263,  2007,  1686, -2263,   663, -2263,
     618, -2263,  1595, -2263,  1019, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  1251,   -56, -2263,  1019, -2263, -2263, -2263, -2263,
   -2263, -2263,   748, -2263,   501,   748, -2263, -2263, -2263,    99,
    2077,  3122,  1868, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1715,  1925, -2263, -2263, -2263,  1927, -2263, -2263, -2263, -2263,
   -2263, -2263,  1837, -2263,  1494, -2263, -2263, -2263, -2263,  1019,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    3207, -2263, -2263, -2263,  1278, -2263, -2263, -2263,  2045, -2263,
     200,  1776,   200,  1783, -2263, -2263,  5275, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,  1149, -2263,  2031, -2263,
    1437, -2263, -2263, -2263,   692,  1152, -2263, -2263,  1152,   -75,
    1019, -2263, -2263,   200, -2263, -2263,  1754, -2263,  2083,  1873,
    1901,     7, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   922, -2263, -2263, -2263, -2263,
   -2263,  1843,  1188,  1715,   200,  1648, -2263,  2088, -2263,  1564,
    2046,  1564,  1660, -2263, -2263, -2263, -2263,  1850, -2263, -2263,
   -2263, -2263,  1286, -2263,  1019,  1104, -2263, -2263,  1847, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  -136, -2263,
   -2263, -2263,  -136,    -6, -2263, -2263,  1188, -2263, -2263, -2263,
    1188, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  2087, -2263,
   -2263,     6, -2263,  2137, -2263, -2263, -2263,  3122, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,  1019, -2263, -2263, -2263,
   -2263,  2045, -2263,   613, -2263,   613, -2263, -2263, -2263,  2097,
    2037,  1152,  1152, -2263,  1692,  1692, -2263,  1812,  1156,   -15,
   -2263,  1019, -2263, -2263,  5275, -2263,  1188,   913,  1888,  1889,
   -2263,  1892, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1019,
   -2263, -2263, -2263, -2263,  1702, -2263,  1019,  1564, -2263,  1019,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1129,  1188,  1188,
     158, -2263, -2263, -2263, -2263, -2263, -2263,  1493, -2263, -2263,
   -2263,  2043,  -136,  -136,  1188,   531,   531, -2263,   559, -2263,
   -2263, -2263,  1715,  1715,  5275, -2263,  1152, -2263,  5275,  5275,
    1188,  1156,  1156,  1826, -2263, -2263,  1674,  1019, -2263, -2263,
    1824, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1338, -2263,
   -2263,  1019, -2263, -2263, -2263,  1188,  1847,  1847, -2263,  1948,
    1188,  1188, -2263,  2672,  1710, -2263, -2263,   501, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   487,  1156,
    1188, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1184,
   -2263, -2263, -2263, -2263, -2263,  1819,  2057, -2263,  1847, -2263,
   -2263, -2263,  1847,  1847,  1945,  1059,  1732,  1956,  1344,  1666,
    1188,  1494, -2263,  1188,  1188,  1019, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   -48,
   -2263,   -17, -2263, -2263, -2263,  1059,  1732, -2263, -2263, -2263,
     487, -2263,  1802,  1750,   204,  1577, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,   634, -2263,  1188,  1343, -2263,  7217,  7217,
    1313,  2051,  1976, -2263,  1344,   -48, -2263, -2263,  1344,   -17,
   -2263, -2263,   634, -2263, -2263,  1019, -2263,   725, -2263, -2263,
   -2263,    51, -2263,   -48,  1391, -2263,  1520,  6984, -2263, -2263,
     751,  1021, -2263, -2263,  1097, -2263, -2263, -2263, -2263,   -68,
     -68, -2263, -2263, -2263, -2263, -2263,  7217, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,  1836,   529,    51, -2263, -2263,
   -2263,  1733, -2263,  1577, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263,  1865, -2263,  1865, -2263,  2125, -2263,  1577, -2263, -2263,
    1869,  1019, -2263,  1755,   -21,  1856, -2263, -2263,  7217,   667,
   -2263, -2263,  1344, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1156, -2263
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2263, -2263, -2263, -2263, -2263,  2172, -2263, -2263, -2263,   914,
   -2263,  2136, -2263,  2092, -2263, -2263,  1310, -2263, -2263, -2263,
    1389, -2263, -2263,  1199,  2157, -2263, -2263,  2058, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1986,
     806, -2263, -2263, -2263, -2263, -2263,  2040, -2263, -2263, -2263,
   -2263,  1983, -2263, -2263, -2263, -2263, -2263, -2263,  2115, -2263,
   -2263, -2263, -2263,  1971, -2263, -2263, -2263, -2263,  1955, -2263,
   -2263,   569, -2263, -2263, -2263, -2263,  2050, -2263, -2263, -2263,
   -2263,  2019, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,   959, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1682, -2263,  1793, -2263, -2263, -2263,
    1730, -2263, -2263, -2263, -2263,   333, -2263, -2263,  1918, -2263,
   -2263, -2263, -2263, -2263,  1788, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1200, -2263, -2263, -2263,  1433, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   405,
   -2263, -2263,  1717, -2263,  -757,  -828, -2263, -2263, -2263,   170,
   -2263, -2263, -2263, -2263,  -527, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -1401,   793,  1477,   425,   428, -1391, -2263, -2263,
   -2263,  -368,  -430, -2263, -2263,   361, -2263, -2263,    75, -1388,
   -2263, -1386, -2263, -1384, -2263, -2263,  1434, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    -402,  -431, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -1276, -2263,  -364, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1405, -2263, -2263, -2263,    62,    63, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1218,   226, -2263,   192, -2263, -2263, -2263, -2263, -1842, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -1147, -2263, -2263,  -699,
   -2263,  1464, -2263, -2263, -2263, -2263, -2263, -2263,  1037,   520,
     524, -2263,   442, -2263, -2263,  -105, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   492, -2263, -2263, -2263,  1033,
   -2263, -2263, -2263, -2263, -2263,   799, -2263, -2263,   211, -2263,
   -2263, -1255, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,   802, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   778,
   -2263, -2263, -2263, -2263, -2263,    39, -1747, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   762,
   -2263, -2263,   761, -2263, -2263,   447,   221, -2263, -2263, -2263,
   -2263, -2263,  1005, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,    31,   731, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   721, -2263,
   -2263,   207, -2263,   426, -2263, -2263, -1963, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
     976,   720,   206, -2263, -2263, -2263, -2263, -2263, -2263, -1736,
     978, -2263, -2263, -2263,   201, -2263, -2263, -2263,   412, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   365, -2263, -2263, -2263, -2263,
   -2263, -2263,   701,   193, -2263, -2263, -2263, -2263, -2263,   -82,
   -2263, -2263, -2263, -2263,   389, -2263, -2263, -2263,   958, -2263,
     960, -2263, -2263,  1175, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,   171, -2263, -2263, -2263, -2263, -2263,   949,
     376, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,    17, -2263,   383, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  -331, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  -303, -2263,
     674, -2263, -2263, -1638, -2263, -2263,  -716, -2263, -2263, -1470,
   -2263, -2263,    19, -2263, -2263, -2263, -2263,   -79, -2183, -2263,
   -2263,    13, -1807, -2263, -2263, -1904, -1533, -1058, -1438, -2263,
   -2263,   785, -1755,   197,   199,   202,   203,  -927, -1141,  -741,
      16,   315, -2263,   608,  -391, -1392, -1013,   151,   993, -1545,
    -392,  -276, -2263, -1302, -2263, -1039, -1514,   878,  -529,   -98,
    2032, -2263,  1638,  -554,    37,  2180, -1066, -1048,    -7,  -384,
   -2263, -1068, -1330, -2263,   435, -1238, -1915, -1089, -1167, -1506,
   -2263, -2263, -2263, -1112, -2263,   261,   635,  -635, -2263, -2263,
    -103, -1182,  -758,   -99,  2064, -1886,  2094,  -664,  1441,  -546,
    -590, -2263, -2263, -2263,  -107,  1369, -2263, -2263,   255, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -1952, -2263,
   -2263,  1592, -2263, -2263,  -175,  -589,  1931, -2263, -1169, -2263,
   -1307,  -290,  -625,   843, -2263,  1840, -2263, -1423, -2263, -2135,
   -2263, -2263,   -35, -2263,   -29,  -656,  -357, -2263, -2263, -2263,
   -2263,   290,  -271,  -214, -1184, -1528,  2138,  1903, -2263, -2263,
    -334, -2263, -2263,  1062, -2263, -2263, -2263,   436, -2263,   294,
   -1920, -1455, -2263, -2263, -2263,  -156,   494, -1383, -1529, -2263,
   -2263, -2263,  -167, -2263, -2263,  1652, -2263,  1804, -2263, -2263,
   -2263,   800, -2263, -2262,  -231, -2263, -2263, -2263, -2263, -2263,
   -2263
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1835
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   741,   138,   689,   141,   139,   415,
    1014,   579,  1256,   147,   733,   778,  1350,   160,  1418,   838,
     759,  1704,  1437,  1870,   404,   245,   990,   103,   104,   105,
    1862,  1706,   139,   427,  1707,   111,  1708,   180,  1709,  1714,
    1771,  1874,   975,   464,   696,  1604,  1267,   437,  1288,  2173,
    1620,  2190,  1755,   268,  1464,   463,  1223,  1830,  1278,  2037,
    2646,  1332,  1349,  1473,  1456,  1824,  1278,  1502,  2162,   345,
     134,   135,   768,   136,   411,   211,   215,   790,   143,   144,
    1278,   246,  2099,   535,   838,   264,  1241,   161,   291, -1548,
      99, -1549,  -652, -1834,  1851,  2204,  1402,   107,  1597,  -650,
    1995,  1617,  1833,  1749,   169,  1815,   259,  2126,  2661,   700,
    1413,   392,  2258,   114,  1512,   821,   821,  1560,   825,   529,
     154,  2035,   360,  2441,   790,   744,   220,  2200, -1790,  2445,
     279,   219,  2227,  1432,  1747,  1202, -1575,  1166,  1948,  2179,
    1166,  1570,  1852, -1554,  1457, -1552,   216,    42,   701,  2252,
    2387,  1238,   297,   843, -1768,  2684,  1109,   681,  2124,   413,
   -1834,  1194,   251,   821,  2416,  1194,  2419, -1730,  2490, -1730,
    1610, -1834,   517,  1866,   258,     4,  1337,  1512,  1961,  2176,
    1427,  2030,  1223,  2293,  1790,  1000,   283,   182,  2462,  1819,
      94,   129,    23,   985,  1721,   215,   327,  1917,   221, -1734,
     693,   796,  1819,   717,  1007,  1424,  1238,  1008,  2160,    94,
    1647,  2005,  2488,   419,  2471,  2237, -1790,  1669, -1832,  1787,
     295,   515,  1387,  2398,  2296,   535,   717,  1162,   299,  1544,
    -652,  1879,   465,   154,  -652,   321,  1923,  -650,  2593,  2160,
    1544,  -650, -1763,  2399,  1220,  1670,  1671,  2489,  1180,   839,
    1651,  1238,  1414,  1447,  1655,   274,   275,    94,  1171,   516,
    1880,  1657,  1853,  1172,  2483,     3,  1181, -1750,   418,  2400,
      94,  1425,   747,   718,  2484,   183, -1803,   999,    24,  1602,
    1166,  2594,  2481,   204,   155,   212,   156,  2513,  1238,  2381,
    2382,  1750,  -652,   130,  2401,  1166,   720,  1278,  1648,  -650,
     284,  1544,  2463,  2021,  1467,  2055,   518,  1220,  2119,   311,
     694,  2120,  2598,  1850,   839,  1962,     5,  2205,  2031,   314,
    1151,  1428,  1166,  2085, -1834,  1918,  1854,   682,  2628,  1110,
    1184,   137,  1928,  2608,   410,   243,  2333,   217,  1933,  2383,
     139,  2309,   139,   139,   243,  2044,     5,   485,   486,   139,
     412,  1603,   745,  1218,   491, -1730,  2189,   749,   493,  1194,
    1829,  1420,   424,  1166,  2279,  1153,   139,  2010,   137,   507,
     507,   485,   507,   436,  2167,   507,   514,   985,   985,   985,
     823,   480,   443,   444,  2060,   445,   446,  1824,    94,  1194,
    1824,   452,   980,  2063,  1337,  1927,  2083,  2206,  1336,   985,
    1837,   752,   783,   154,   989,  1605,   519,  1527,   469,   -35,
    1382,   753,   749,   139,   826,  1391,  1391,  1391,   542,   280,
    2456,  -500,  2388,  2201,   492,  1871, -1768,   728,  1404,  1406,
    1238,  1241,  2437,  -652, -1730,  1412,   137,   139,   139,   702,
    -650,   281,   542,   580,  1267,  1367,  1185,  1186,  2319,  -500,
    -500,  1571,  1294,  2136,   466,   137,   752,   749,  1788,  2171,
     368,  1940,   536,  1551,   187,  1167,   753,   260,  1167, -1734,
    1527,   188,  1238, -1734,   413,   749,   139,  1672,  2183,  2184,
    2036,   580,  2185,   137,  1241,  2238,   540,  1474,  2446,   243,
     255,   754,   137,   686,   749,   139,  1865,  2053,  1368,  1994,
     697,   752,   767,   996,   985,   577,  1835,  2402,   283,   467,
    2049,   753,  2018,   292,  1278,  1168,  1337,   346,  1650,   752,
     783,  1966,   989,  2221, -1763,   591,  1295,   593,  2222,   753,
     598,   600,  1321,   602,    97,   265,   448,  1878,   752, -1821,
    2196,  2498,  2499,  1367,  2359,   732,   754,   735,   753,  2207,
    1367,  1503,  1241,  1855,  1544,   137,   137,   149,   394,   985,
     679,   755,  2502,  1419,  -500,   688,   985,   985,   985,  1398,
    2004,  2277,   699,  1439,  1398,  2008,   980,   980,   980,   985,
     985,   985,   985,   985,   985,   985,   985,  1939,  1398,   985,
    2472,   754,  -500,   261,  1474,   844,  1368,  1468,   980, -1834,
    2529,  2530,  1001,  1368,   536,   756,  1488,  1673,  1167,   754,
   -1734,  2005,  1824,   607, -1734,  1241,   755,  1975,  1441,  1238,
    2068,  1820,   284,  1167,  2037,  2609,  2239,  1789,   754,   137,
     740,  2023,  1821, -1633,  1820, -1834,   749, -1834,  2027, -1803,
     243,  1321,  2576,   704,  2312,  1821,  2577,  2578,   581,   137,
    1167,  2230,   430,  2232,  1171,   757,   211,  2107, -1613,  1172,
     756,   755, -1834,   824,  2652,   505,   512, -1734,   829,   834,
     834,   772,  1006, -1610,   773,  2601,   189,  1109,   749,   755,
     752,  -500,   949,   991,   222,   322,  -657, -1834,  1941,  2056,
     753,  1167,  2263,   832,  2651,  1976,   747, -1734,   755,   351,
    1662,   747,  1496,   980,   137,   756,  1237,  -647,  1249,  1213,
     757,   453,    27,  2601,  2014,  1776,  -655,  1255,  1259,  1684,
    2361,  1685,   752,   756,  1321,  2127,  2016,  1284,  1606,  1773,
     717,  1324,   753,  1329,  1302,  1304,  1552,   748,  1355,  2049,
      15, -1615,   756,  1220,  2102,  2294,  1241,   -96,   190,   137,
    2079,  1171,  1377,  1361,  1213,   757,  1172,  1232,   980,  2000,
    2372,  -657,  2374, -1834,  1607,   980,   980,   980,   305,   127,
     754,   582,  2569,   757,  1810,  1811,  1812,  1813,   980,   980,
     980,   980,   980,   980,   980,   980,   137,   154,   980,  1154,
    1155,  -655,   757,  2392,  1432,  2380,  1160,  1684,  2082,  1685,
     722,   717,  1752,   187,   191,   737, -1736,  1553, -1734,   192,
     188,  -500,   754,  1131,   449,  2160,  1278,  1544,  1952,  1953,
    2303,  1227,  2439,  2410,  2411,   749,  2440,  2253, -1730,  1772,
   -1730,   470,   471,   472,  2604,  2668, -1834,  2689, -1734,  1290,
     755,   154,  2186,  2461,  1458,  -647,  2080,   223,  2311,  -647,
    1110,   601,  1776, -1834,  1851,  1476,  1514,  1515,  2192,   252,
    2157,   325,    16,  2235,  1665,  1366,   212,  2669,   128,   752,
    1546,   724,   431, -1748,   154, -1821,   450,  2219,   243,   753,
     985,  1497,   755,   438,   756,  1541,  2643,  2670,   -96,  1337,
    2644,  2128,  2690,   344,  1778,  1516,  1517,   139,   139,   749,
    2691,   717,  1852,  1132,   749,  2298,  2242,  -647,  2492,   306,
    2244,  1189,  1896,   137,   137,  1479,  1561,  2509,   316,  1944,
    1885,   822,   328,  2225,  2225,   400,   756,   243,   137,   439,
     715,   750,   751,   187,   757,   555,  2495,  2496,  2656,  2310,
     188,   137, -1834,   752,  1133,    43,   243,   738,   752,  2272,
     556,   583,   473,   753,   228,  2304,  2039,  2040,   753,   754,
    1206,  2531,   705,   747,  2566,  1424,   474, -1834,   997,   985,
     137,   726,  1228,  1134,  1229,  1361,   757,   243,  2571,   317,
     318,   187,  2503,  2504,  2692,  1724,  1725,   716,   188,   611,
     557,   137,  1226,  2241,  1886,  1588,  1245,   525,   229,  2009,
    1947,   253,  1247,  1245,  1280,   137,    43,   137,   230,   243,
     137,  1245,  1613,  1550,  1299,   189, -1730,   709,  2322,  1320,
    2366,  1327,  1853,  1327,  1335,  1352,  1299,  1630,  1591,   755,
    2231,  1425,  2233,   754,  1544,   137,   952,    18,   754,   706,
    2360,   707,  2096,  1327,   712,  2276,  2362,  2611,  -647,   475,
   -1617,   129,   394,   953,  2615,  2526,  2365, -1066,  1452,  2087,
    1756,   476,   253,   137,  1725,  1398,  1357,  1135,   405,  2210,
     985,  1241,  1614,   756,    28,  1615,  2028,  2323,  1643,   980,
       5,  1462,  1951,  1777,  1631,  2329,  1854,   190,   232,  1629,
    2038,  1305,  2546,  2069,  1254, -1730,  1769,  2649,  1321,  1784,
     329, -1066,  2547,   755,  1528,  2549,  1529,  2550,   755,  2551,
    2565, -1066,  1814,  1816,  1581,    33,  2002,   137,  1226,   406,
      94,  1770,   137,   757,  1241,  2674,  2403,   558,  2167,  2404,
    2405,  1364,  1549,  2649,  2694, -1516,    39,  1245,   559,  2679,
     361,  2070,  2406,   191,  1778,   189,  1306,   756,   192,   154,
    1541,   477,   756,   130,  1307,   954,  2421,  2422,   233,   330,
    2384,  1840,   608,  1582,  1841,  1842,   749,   117,   980,   300,
    1270,   394,   362, -1554,  1245,   819,   819,    52,   820,   820,
     416,  1867,  1623,   243,   394,  1245,   742,  1407,  1408,  2385,
     783, -1066,  2447,   189,  1173,   609,   137,   757,  2163,  1208,
    1619,    52,   757,  1174,  2273,   956,  2324,   957,  2657,  2100,
     752,  2325,   958,   959,   960,    26,  2450,   190,   961,   743,
     753,  2572,  1901,   819,    53,  1209,   820,  -854, -1834,  1335,
    -854,  2658,    47,  1916,  2101,  2483,  1920,    36,  1308,   560,
     561,    91,  1245,  2265,  1924,  2484,  1245, -1516,    53,  1882,
    2195,   193,   236, -1834,   562,   226,   563,   962,  2616,  2618,
    2476, -1066,    54,  2002,    55,   190,    56,    40,  2266,   980,
    1194,   403,  1262,   191,    57,  1574,   963,  1331,   192,   441,
     139,  2427,    48,  1263,  2659,  1644,    54,  2655,    55,  1401,
      56,  2428,  1934,  1575,  1271,  1272,   749,  1381,    57,  1171,
     754,  1448,  1462,  -854,  1172, -1066,  2665,  2660, -1734,  2525,
     155,  1273,   156,  1855,  2429,   139,  2211,  2212,  2213,  2638,
    -854,   191,  1459,    21,    22,  2071,   192,  2220,   254,  1170,
      58,   964,   799,  2225,  2225,  2320,  2501,  2650,  1171,   564,
     752,  1757,    46,  1172,  2430,    49,  1659,  2199,  2688, -1066,
     753,    51,  1899,   227,    58, -1066,  1171,  2589,  2581,  2582,
    2452,  1172,  2453,  1900,  2159,  1274,  2619,  2488,  1417,  2191,
     755,   800,   801,   802,   803,   804,   298,    93,  1298,  2214,
    1171,   255,   965,   966,   100,  1172,   565,  1664,  2285,  2155,
    1298,    13,  1677,  1713,  1757,  1715,    13,   101,   592,  1171,
    2199,  1660,  2620,   599,  1172,    97,   626,   627,  2568,  1903,
    1171,  1869,  1393,  1394,   756,  1172,    59,  1904,   982,  2483,
      94,  1423,  -854,    60,   970,  1423,  1843,  1844,   106,  2484,
     754,   109,   508,  -854,   510,  1890,   594,   511,   595,   228,
    1460,   108,  1226,  1974,   971, -1748,   706,    60,   707,   972,
    1845,  1846,   110,  1984,  1985,   112,   973,  1988,   137,  1245,
    1915,  1634,  1757,  1635,   757,  2514,  -854,    61,  1963,   243,
    1964,   113,  -854,  1226,  -854,  2199,   114,  -854,   428,  -854,
    -854,  -854,  2032,   229,  2033,  -854,   120,  -854,  1409,  1410,
    1411,    61,  -854,   230,    62, -1532, -1532, -1532, -1532,  1245,
     755,  2215,  2216,  2316,  2515,  2317,  2217,   231,   122,   805,
     806,   807,   808,   809,   810,   811,   639,   640,  2109,   124,
     749,  1897,   126,   137,  -854,  1757,   351,   140, -1516,  -854,
    2368,  1926,  2369,   142,   149,   170, -1516, -1516,  2424,   985,
    2425, -1516,  2516,  -854,   756,  1936,  1937,  1938,   139,   162,
     163,  1942,  2072,  1935,  1945,  1946,    64,   164,  1731,    63,
    1732,   181,   167,  1839,   752,   185,  1840,  -854,   186,  1841,
    1842,   204,   242,   232,   753,  1161,   193,  1163, -1734,   171,
      64,   247,  1905,   248,   249,  1913,   250,   257,   137,   172,
    2199,   273,   269,   278,   757,  1969,   296,   294,  -854,    67,
     154,   303,   982,   982,   982,    65,   300,    66,   302, -1834,
    2269,   307,   308,   309,  1906,   312,  1977,   118,  1490,  1491,
    1492,  1493,   326,    67,   982,  2314,   313,   334,   338, -1834,
     333,  -854,   336,   340,  2621,   349,  1907,  -854,  2622,  2623,
    1949,  1950,   342,   233,   351,   356,   234,   235,   353,  -854,
    -854,  1960,  1245,   392,   754, -1834,  1245,   354,  1965,  1245,
     394,   812,  1226,   749, -1531, -1531, -1531, -1531,   397,   173,
      68,   398,   401,   403,   813,   408,   187,   409, -1730,  2624,
   -1834,  -854,   721,   723,   725,   727,   243,  1978,   420,  1908,
     421,  -854,   422,   428,    68,  2625,  2626,  -854,   429,   413,
     454,   455,   459,   483,   457,  -342,   487,   752,   490,  2268,
     494,  -854,  1245,   495,  2089,   502,  -854,   753,   509, -1734,
     523,  2261,   521,  -854,   755,  -854,   522,  1205,   533,  1219,
     527,  -854,  1235,   543,   547,   548,  1257,   236,   980,   174,
     551,   549,   552,  -355,   554,  2022,   578,  2287,  2287,  1909,
     585,  1293,   586,   587,   603,   605,   610,  1319,   613,   614,
     685,  1245,  1245,  1245,  2029,  2134,   687,   690,   756,   698,
    2034,   711,   730,   728,  2134,  1890,   736,   746,  1375,   762,
    1379,   765,   769,   175,   982,  1206,   771,   777,   747,   781,
     780,   982,   982,   982,  1396,   786,   783,   754,   791,  1396,
     797,   793,   830,   823,   982,   982,   982,   982,   982,   982,
     982,   982,   137,  1396,   982,   836,   989,   995,   757, -1617,
    1245,  2110,  2111,  2112,  2113,  2114,  2115,  2116,  2117,  1729,
    1730,  1843,  1844,   176,   998,   137,   950,   994,  1016,  1019,
    1139,  1011,  1438,  1120,  1910,   139,  1149,  1147,  1156,  1175,
    2156,  1187,  2376,  1200,  1191,  1845,  1846,  1299,  1157,  1158,
    1260,   952,  1299,  1193,  1159,   357,  1319,   755,  1235,  1164,
    1731,  1176,  1732,  1207,  1733,  1178,  1179,  1201,   953,  2177,
     358,  1299,  1299,  1281,  1389,  1299,  1382,  1415,  1793,  1390,
     359,  1794,  1416, -1834,  1417,  1430,   243,  1436,  1795,  1796,
    1442,  1451,  1453,  1400,  1465,  2154,  1471,  1245,  1734,  1735,
    1736,   756,  1477,  1494,  1498,  1480,  1542,  1546,  1500,  1559,
    1562,  1565,  1563,  2158,   360,  1567,  1299,  2612, -1534,  2089,
    1576,  1299,  1299,  1299,  1577,  1578,  2226,  2226,  2271,  2172,
    1245,  2174,  1245,  1579,  1797,  2175,  2641,  2584,  1584,  1319,
    1586,  1609,  1589,  2180,  1593,  1337,  1611,  1595,  1737,  1194,
    1738,   757,  1621,  1633,  1639,  1626,  1645,  1739,  1637,  1666,
    1740,  1598,  1641,  1652,  1717,  1663,  1716,  2603,  1653,  1245,
     954,  1245,  1654,  1656,  1658,  1661,  1719,  1722,  1753,  1668,
    1759,   749,  1762,  1764,  1220,  1774,  1760,  1625,   985,   985,
    1785,  1791,  1808,  1482,  1825,  1778,  1828,  1836,  1849,  1552,
    2466,  1864,  1872,  1798,  1887,  1891,  1895,  1902,  1482,  1922,
    1929,  1956,  1957,  1967,  1208,  1970,  1973,   985,  1979,  1980,
     956,  1982,   957,  1989,  1245,   752,  1724,   958,   959,   960,
    1996,  1992,  1799,   961,  1997,   753,   985,  1299,  2260,  1993,
    1209,   139,  1998,  2011,  2015,  2019,   542,  1741,  2020,  1742,
    1432,  1999,  2043,  2024,  1800,  2045,  2050,  1598,  2051,   428,
    2505,  2057,  2058,  2061,  2506,  2507,  1337,  2064,  2065,  2084,
    1793,   361,   962,  1794,  2092,  2090,  2093,  2096,   985,  2103,
    1795,  1796,  2104,  2130,  2137,  2139,  2138,  2140,  2149,  2151,
    2181,   963, -1553,  2160,  2187,   982,  2228,  2245,  2193,  2251,
    2254,  2257,  2262,   362,  2297,  2273,  2275,   428,  1801,  2292,
    2299,  2289,  2301,  -228,  2334,   754,  2005,  1245, -1509,  1245,
   -1551,  2363,  2394,  2378,  2393,  2395,  1797,  2373,  2396,  2407,
    2412,  2417,  2304,  2444,  2375,  2447,  2454,  2455,  2457,  2460,
    2473,  2474,  2494,  2479,  2475,  2511,   964,   139,  2531,  2574,
    1245,  2567,  2390,  2510,  2575,  2585,  2579,  2587,  2606,  2605,
    2635,  1802,  2636,  2666,  2678,  2680,   363,  2687,  2675,    17,
    2682,   364,    92,    38,   125,   166,  1598,   256,   209,   266,
     119,  1245,   277,   290,   982,   755,   241,   980,   980,   504,
     210,   545,  2086,   442,   323,  1798,   835,   965,   966,  1188,
    1877,   139,   365,   456,   526,  1705,   580,   787,  2614,  1884,
     366,  2673,   993,  2078,   984,  1299,   980,  2313,  2664,  1299,
    1893,  1803,  2677,   367,  1799,  2640,  1199,  2330,  2331,   756,
    2236,  1434,   952,   948,  1804,   980,  1015,  1987,  1743,   970,
    1986,  2042,  2449,  2013,  1450,  1767,  1800,  2234,  1921,   953,
    1768,  1783,   368,  2409,  1818,   369,  1826,  2371,  1598,   971,
    1245,  2240,  1245,   370,   972,  2054,  1860,  2377,  1543,  1848,
    2256,   973,  2066,   137,  -225,  1566,  1868,   980,  2465,   757,
    1396,  2264,  1569,  2267,  2094,   982,  2148,  1894,  1744,  2278,
    2118,  1600,   428,  2288,  1353,  1601,  2146,  2442,  1624,  1745,
    1801,  2443,   371,  2147,  2415,   372,  2672,  1932,  2470,  1832,
    2423,  2420,  2281,  1319,  2282,  1592,  1805,  2283,  2284,   764,
    1766,   332,   213,  2108,   310,  1971,   293,   795,  1972,  1299,
    1299,  1165,  1299,  1299,  2573,  1299,  2226,  2226,   447,   539,
    2459,  2602,   489,   272,  2132,  2077,  2250,   774,  1863,  2629,
       0,   954,   597,  1802,     0,     0,     0,  2467,     0,     0,
       0,     0,  1598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2003,     0,
       0,     0,     0,     0,     0,     0,  1152,     0,     0,  2486,
    2487,     0,     0,     0,     0,  1226,     0,     0,   984,   984,
     984,     0,     0,     0,     0,  2497,  1455,     0,   958,   959,
     960,     0,     0,  1803,   961,     0,     0,     0,     0,     0,
     984,  2508,     0,     0,     0,     0,  1804,     0,     0,  2586,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2528,     0,     0,     0,
       0,  2532,  2533,   962,     0,     0,     0,  1226,     0,     0,
       0,     0,     0,     0,     0,   846,     0,   847,     0,   848,
       0,  2570,     0,     0,   849,     0,     0,     0,     0,     0,
       0,     0,   850,  1598,  1598,  2637,     0,     0,     0,  2639,
       0,     0,     0,     0,     0,     0,     0,     0,  1226,     0,
       0,  2588,     0,     0,  2590,  2591,     0,     0,  1805,     0,
       0,     0,  2095,     0,     0,   851,   852,     0,     0,     0,
    1598,     0,     0,     0,   853,   984,     0,   964,     0,     0,
    1246,     0,     0,     0,  1226,   854,     0,  1246,   855,     0,
       0,     0,     0,     0,     0,  1246,  2613,  2135,     0,     0,
       0,     0,   856,     0,  2145,  2145,     0,     0,  2681,  1246,
       0,     0,     0,     0,     0,  1206,     0,     0,   747,     0,
       0,     0,     0,  2695,  1235,   857,     0,     0,   965,   966,
     984,     0,     0,   858,  2166,   859,     0,   984,   984,   984,
    1397,     0,     0,     0,     0,  1397,     0,     0,     0,     0,
     984,   984,   984,   984,   984,   984,   984,   984,     0,  1397,
     984,     0,     0,     0,     0,     0,   860,     0,     0,     0,
     970,     0,     0,     0,     0,     0,     0,   861,     0,     0,
       0,     0,   862,     0,     0,     0,  2198,     0,     0,  1440,
     971,   952,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,     0,     0,   953,   863,
       0,     0,     0,     0,     0,     0,   864,     0,     0,   865,
     866,  1246,     0,     0,     0,     0,     0,     0,     0,   867,
    2243,     0,     0,     0,     0,     0,   868,     0,   869,  2198,
    1598,   870,     0,     0,     0,     0,     0,     0,  1598,     0,
       0,     0,     0,     0,     0,     0,     0,   624,  1246,     0,
       0,  1898,     0,     0,     0,     0,     0,  1877,     0,  1246,
       0,     0,     0,     0,     0,     0,  1684,  1731,  1685,  1732,
       0,     0,     0,   871,     0,     0,     0,   872,     0,   873,
       0,     0,     0,     0,     0,     0,  2280,     0,     0,   874,
       0,     0,     0,     0,   982,  1206,     0,     0,   747,     0,
     954,     0,     0,     0,  2198,     0,     0,  1599,  1598,     0,
       0,   749,     0,     0,     0,   875,  1246,     0,     0,     0,
    1246,     0,     0,     0,     0,     0,     0,     0,   876,     0,
    2321,     0,     0,     0,     0,     0,     0,     0,     0,  1235,
       0,     0,     0,     0,  1208,     0,     0,     0,     0,     0,
     956,     0,   957,   877,   878,   752,     0,   958,   959,   960,
       0,     0,     0,   961,   879,   753,     0,     0,     0,     0,
    1209,   952,     0,     0,  2367,     0,     0,     0,   880,   881,
       0,     0,     0,  1300,     0,   882,     0,     0,   953,   883,
       0,     0,     0,     0,     0,     0,     0,   884,     0,     0,
       0,     0,   962,  1599,     0,     0,     0,   885,     0,     0,
       0,  2534,     0,     0,     0,  1758,   886,     0,     0,  2198,
       0,   963,     0,     0,     0,   887,     0,     0,     0,     0,
     888,   889,     0,     0,   890,     0,   891,   642,     0,     0,
       0,   984,   892,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,  2535,   893,  2536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1758,     0,
       0,     0,     0,   894,     0,     0,   964,     0,     0,   895,
       0,     0,     0,     0,   896,     0,     0,  2537,     0,     0,
     954,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   749,     0,     0,     0,     0,     0,  2538,     0,     0,
       0,   897,     0,     0,     0,   755,     0,     0,     0,     0,
       0,     0,  1599,     0,     0,     0,     0,   965,   966,   646,
     984,  2451,     0,  1246,  1208,  2539,  1758,     0,     0,     0,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
       0,     0,  1899,   961,     0,   753,     0,     0,     0,   756,
    1209,     0,     0,  1900,     0,     0,     0,     0,     0,   970,
       0,     0,     0,  1246,  2477,     0,     0,     0,     0,     0,
       0,  2480,     0,     0,  2482,     0,     0,     0,     0,   971,
       0,     0,   962,     0,   972,     0,     0,     0,     0,  1758,
       0,   973,     0,   137,  1599,     0,     0,   651,     0,   757,
       0,   963,     0,     0,     0,     0,  2540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1397,     0,     0,     0,
       0,   984,  2512,  2541,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2527,     0,     0,     0,
       0,     0,     0,  2542,     0,     0,     0,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,   964,     0,     0,     0,
       0,     0,     0,     0,  2543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2335,     0,     0,  2336,     0,     0,
    2337,     0,     0,  2544,     0,     0,     0,     0,  2338,     0,
     660,  2545,     0,     0,     0,   755,     0,     0,  1599,     0,
    2592,     0,     0,     0,     0,     0,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,  1246,     0,     0,     0,
    1246,     0,     0,  1246,     0,     0,     0,     0,   846,     0,
     847,     0,   848,  2339,     0,     0,     0,   849,     0,   756,
       0,     0,     0,   982,   982,   850,     0,     0,     0,   970,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2642,     0,     0,     0,     0,     0,     0,     0,     0,   971,
       0,     0,   982,     0,   972,     0,  1246,     0,   851,   852,
       0,   973,     0,   137,  2663,  2663,     0,   853,     0,   757,
       0,   982,     0,     0,     0,     0,     0,     0,   854,     0,
       0,   855,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   856,     0,     0,     0,  1599,
    1599,     0,     0,     0,     0,  1246,  1246,  1246,     0,  2686,
       0,  2340,     0,   982,     0,     0,     0,     0,   857,     0,
    2341,     0,     0,     0,     0,     0,   858,     0,   859,     0,
       0,     0,     0,  2342,     0,  -694,  1599,  -694,  -694,  -694,
    -694,  -694,  -694,  -694,  -694,     0,  -694,  -694,  -694,     0,
    -694,  -694,  -694,  -694,  -694,  -694,  -694,  -694,  -694,   860,
       0,     0,     0,     0,  1246,  2343,     0,     0,     0,     0,
     861,     0,     0,     0,     0,   862,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2344,     0,  2345,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   863,     0,     0,     0,     0,     0,     0,   864,
    2346,     0,   865,   866,     0,     0,     0,     0,     0,     0,
       0,     0,   867,     0,     0,     0,     0,     0,     0,   868,
       0,   869,     0,     0,   870,     0,     0,     0,     0,     0,
    2347,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2348,     0,     0,
       0,     0,     0,     0,     0,     0,   871,     0,     0,     0,
     872,     0,   873,     0,  1246,     0,  1246,     0,     0,     0,
       0,     0,   874,  2349,     0,     0,     0,     0,  -694,  -694,
    2350,  -694,  -694,  -694,  -694,     0,  1599,     0,     0,     0,
       0,     0,     0,  2351,  1599,     0,     0,  2352,   875,     0,
       0,     0,     0,  1246,     0,  1246,   846,     0,   847,     0,
     848,   876,     0,     0,     0,   849,     0,     0,     0,     0,
       0,     0,     0,   850,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   877,   878,     0,     0,
       0,     0,     0,     0,     0,     0,  2353,   879,     0,     0,
     984,     0,     0,     0,     0,     0,   851,   852,  1246,     0,
       0,   880,   881,     0,  1599,   853,     0,  1206,   882,     0,
     747,     0,   883,     0,     0,  2354,   854,     0,     0,   855,
     884,     0,     0,     0,     0,  2355,     0,     0,     0,     0,
     885,  2356,     0,   856,     0,     0,     0,     0,     0,   886,
       0,     0,     0,     0,     0,     0,     0,     0,   887,     0,
       0,     0,     0,   888,   889,   952,   857,   890,     0,   891,
       0,     0,     0,     0,   858,   892,   859,     0,     0,     0,
       0,     0,   953,     0,     0,     0,     0,     0,  -694,     0,
       0,     0,     0,   952,     0,     0,     0,     0,     0,     0,
       0,  1246,     0,  1246,     0,  1362,   894,   860,     0,     0,
     953,     0,   895,     0,     0,     0,     0,   896,   861,     0,
       0,     0,     0,   862,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1246,     0,     0,     0,  -694,     0,
       0,     0,     0,     0,   897,   846,     0,   847,     0,   848,
     863,     0,     0,     0,   849,     0,     0,   864,     0,     0,
     865,   866,   850,     0,     0,  1246,     0,     0,     0,     0,
     867,     0,     0,  1311,     0,     0,     0,   868,     0,   869,
       0,     0,   870,     0,   954,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   851,   852,     0,     0,     0,
       0,     0,     0,     0,   853,     0,     0,     0,     0,     0,
       0,     0,   954,     0,     0,   854,     0,     0,   855,     0,
       0,     0,     0,   749,   871,     0,     0,     0,   872,     0,
     873,     0,   856,     0,     0,     0,     0,     0,     0,  1312,
     874,   958,   959,   960,  1246,     0,  1246,   961,     0,     0,
       0,     0,     0,     0,     0,   857,  1208,     0,     0,     0,
       0,     0,   956,   858,   957,   859,   875,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,   876,
       0,     0,  1209,     0,     0,     0,   962,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   860,     0,     0,     0,
       0,     0,     0,     0,   877,   878,     0,   861,     0,     0,
       0,     0,   862,     0,   962,   879,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   880,
     881,     0,     0,   963,     0,     0,   882,     0,     0,   863,
     883,     0,     0,     0,     0,     0,   864,     0,   884,   865,
     866,     0,     0,     0,     0,     0,     0,   754,   885,   867,
     964,     0,     0,     0,     0,     0,   868,   886,   869,     0,
       0,   870,     0,     0,     0,     0,   887,     0,     0,     0,
       0,   888,   889,     0,     0,   890,     0,   891,   964,     0,
       0,     0,     0,   892,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1632,     0,     0,     0,
       0,   965,   966,   871,     0,     0,     0,   872,     0,   873,
       0,     0, -1834,     0,   894,     0,     0,   755,     0,   874,
     895,     0,     0,     0,     0,   896,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,  1206,     0,
       0,   747,     0,   970,     0,   875,     0,     0,     0,   984,
     984,     0,   897,     0, -1119,     0,     0,     0,   876,     0,
       0,   756,     0,   971,     0,     0,     0,     0,   972,     0,
       0,   970, -1119,     0,     0,   973,   243,   137,   984,     0,
       0,     0,     0,   877,   878,     0,     0,     0,     0,     0,
       0,   971,     0,     0,   879,     0,   972,   984,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,   880,   881,
       0,   757,     0,     0,   952,   882,     0,     0,     0,   883,
       0,  1021,     0,  1022,     0,     0,     0,   884,  1023,     0,
       0,   953,     0,     0,     0,     0,  1024,   885,     0,   984,
       0,     0,     0,     0,  1357,     0,   886,     0,     0,     0,
       0,     0,     0,     0,     0,   887,     0,     0,     0,     0,
     888,   889,     0,     0,   890,     0,   891,     0,     0,  1025,
    1026,     0,   892,     0,     0,     0,     0,     0,  1027,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1028,
       0,     0,  1029,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   894,     0,     0,  1030,     0,     0,   895,
       0,     0,     0,     0,   896,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1031,
       0,     0,     0,   954,     0,     0,     0,  1032,     0,  1033,
       0,   897,     0,     0,   749,     0,  1034,     0,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,     0,  1043,  1044,  1045,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,     0,     0,     0,     0,     0,     0,  1208,     0,     0,
       0,  1056,     0,   956,     0,   957,  1057,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
       0,     0,     0,  1209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1058,     0,     0,     0,     0,     0,     0,
    1059,     0,     0,  1060,  1061,     0,     0,     0,     0,     0,
       0,     0,     0,  1062,     0,   962,     0,     0,     0,     0,
    1063,     0,  1064,     0,     0,  1065,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,  1206,     0,     0,   747,
       0,     0,  1508,  1509,  1510,     0,     0,     0,     0,     0,
    1511,     0,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,     0,     0,     0,     0,     0,  1066,     0,     0,
       0,  1067,     0,  1068,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1069,     0,     0,     0,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1070,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1071,     0,     0,     0,     0,     0,   755,   953,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1073,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,  1074,     0,     0,     0,     0,     0,  1075,
       0,     0,   970,  1076,     0,     0,     0,     0,     0,  1512,
       0,  1077,     0,     0,     0,     0,     0,     0,     0,  1513,
       0,  1078,   971,     0,     0,     0,     0,   972,     0,     0,
    1079,     0,     0,     0,   973,     0,   137,     0,     0,  1080,
       0,     0,   757,     0,  1081,  1082,     0,     0,  1083,     0,
    1084,   954,     0,     0,     0,     0,  1085,  1514,  1515,     0,
       0,     0,   749,     0,     0,     0,     0,     0,     0,  1086,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1831,     0,     0,     0,     0,  1087,     0,     0,
       0,     0,     0,  1088,     0,  1208,  1516,  1517,  1089,     0,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1209,     0,  1206,     0,  1090,   747,     0,     0,  1508,
    1509,  1510,     0,     0,  1518,     0,     0,  1511,     0,     0,
    1519,     0,     0,  1520,     0,     0,     0,     0,     0,     0,
       0,  1521,     0,   962,     0,     0,     0,     0,  1522,     0,
       0,  1206,     0,  1523,   747,     0,     0,     0,     0,     0,
       0,     0,   963,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,     0,     0,   952,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   953,     0,     0,     0,
       0,  -910,     0,     0,  -910,     0,     0,   964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   952,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1512,     0,   965,   966,
       0,     0,     0,     0,     0,     0,  1513,     0,     0,  1206,
       0,     0,   747,     0,     0,     0,     0,  -910,  1525,     0,
    1526,     0,  1527,     0,     0,  1528,     0,  1529,  1530,  1531,
     756,     0,  1532,  1533,  -910,     0,     0,     0,   954,     0,
     970,     0,     0,     0,  1514,  1515,     0,     0,     0,   749,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     971,     0,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,   954,     0,     0,     0,
     757,     0,  1208,  1516,  1517,   952,     0,   749,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
    1482,   961,   953,   753,     0,     0,     0,     0,  1209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1208,  1518,     0,     0,     0,     0,   956,  1519,   957,     0,
    1520,   752,     0,   958,   959,   960,  -910,     0,  1521,   961,
     962,   753,     0,     0,     0,  1522,  1209,  -910,     0,     0,
    1523,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1524,
       0,     0,     0,     0,     0,     0,     0,     0,   962,     0,
    -910,     0,     0,   754,     0,     0,  -910,     0,  -910,     0,
       0,  -910,     0,  -910,  -910,  -910,     0,   963,     0,  -910,
       0,  -910,     0,     0,   954,     0,  -910,     0,     0,     0,
       0,     0,     0,     0,   964,   749,     0,  1206,     0,     0,
     747,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -910,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1208,     0,
       0,     0,   964,   755,   956,     0,   957,  -910,     0,   752,
       0,   958,   959,   960,     0,   965,   966,   961,     0,   753,
       0,     0,     0,     0,  1209,     0,     0,     0,     0,     0,
       0,  -910,     0,     0,     0,  1525,     0,  1526,     0,  1527,
       0,   755,  1528,   952,  1529,  1530,  1531,   756,     0,  1532,
    1533,     0,     0,   965,   966,     0,   962,   970,     0,     0,
     953,     0,  -910,  1206,     0,     0,   747,     0,     0,     0,
       0,  1444,     0,     0,     0,   963,     0,   971,     0,     0,
       0,     0,   972,     0,     0,   756,     0,     0,     0,   973,
    1206,   137,     0,   747,     0,   970,     0,   757,     0,   754,
       0,  -910,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -910,  -910,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
     964,     0,     0,     0,     0,   757,     0,     0,     0,   952,
       0,     0,     0,     0,     0,  -910,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -910,   953,  1628,     0,     0,
       0,     0,   954,     0,     0,     0,   952,     0,     0,   755,
       0,     0,     0,   749,     0,  -910,     0,     0,     0,     0,
    -910,   965,   966,   953,     0,     0,     0,  -910,     0,  -910,
       0,     0,     0,     0,     0,  -910,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1208,     0,     0,     0,
       0,     0,   956,   756,   957,     0,     0,   752,     0,   958,
     959,   960,     0,   970,     0,   961,     0,   753,     0,     0,
       0,     0,  1209,     0,     0,     0,     0,  1486,     0,     0,
       0,     0,     0,   971,     0,     0,     0,     0,   972,     0,
       0,     0,     0,     0,     0,   973,     0,   137,   954,     0,
       0,     0,     0,   757,   962,     0,     0,     0,     0,   749,
       0,  1206,     0,     0,   747,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,   954,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   749,     0,     0,     0,
       0,     0,  1208,     0,     0,     0,     0,   754,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1209,  1208,
       0,  1754,     0,     0,   747,   956,     0,   957,   964,     0,
    1250,     0,   958,   959,   960,     0,     0,   952,   961,     0,
     753,     0,     0,     0,     0,  1209,     0,     0,     0,     0,
     962,     0,     0,     0,   953,     0,     0,     0,     0,     0,
     747,     0,     0,     0,     0,     0,     0,   755,     0,   963,
       0,     0,     0,     0,     0,     0,     0,   962,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,   963,   952,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   756,     0,     0,   953,     0,     0,     0,     0,     0,
     754,   970,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,   952,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
     953,   964,     0,   973,     0,   137,   954,  1919,     0,     0,
       0,   757,     0,   755,     0,     0,     0,   749,     0,   952,
       0,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   953,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1208,     0,   965,   966,     0,     0,   956,   756,   957,     0,
       0,   752,     0,   958,   959,   960,   954,   970,     0,   961,
       0,   753,     0,     0,     0,     0,  1209,   749,     0,     0,
       0,     0,     0,     0,   756,     0,     0,   971,     0,     0,
       0,     0,   972,     0,   970,     0,     0,     0,     0,   973,
       0,   137,   954,     0,     0,     0,     0,   757,   962,     0,
    1208,     0,     0,   749,   971,     0,   956,     0,   957,   972,
       0,   752,     0,   958,   959,   960,   973,   963,   137,   961,
       0,   753,     0,     0,   757,     0,  1209,     0,   954,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   749,
       0,   754,     0,     0,     0,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,   962,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,   962,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   965,   966,     0,     0,     0,     0,     0,
     962,     0,   964,     0,     0,     0,     0,   754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,     0,   964,     0,
       0,   755,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   965,   966,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,  1013,     0,   973,     0,   137,
       0,     0,     0,     0,   964,   757,     0,   755,     0,     0,
       0,     0,     0,     0,     0,   756,     0,     0,     0,   965,
     966,     0,     0,     0,     0,   970,  -352,     0,     0,  -352,
       0,     0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,     0,     0,   755,     0,   971,     0,     0,     0,     0,
     972,   756,     0,     0,     0,   965,   966,   973,  -352,   137,
    -352,   970,     0,     0,     0,   757,     0,  -352,     0,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,
       0,   971,     0,     0,     0,     0,   972,   756,     0,     0,
       0,     0,     0,   973,     0,   137,     0,   970,     0,     0,
       0,   757,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   529,
       0,     0,  -352,  -352,  -352,  -352,  -352,   528,     0,  -352,
    -352,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
    -352,     0,  -352,     0,     0,     0,     0,  -352,  -352,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,  -352,  -352,     0,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,     0,     0,     0,     0,  -352,     0,     0,  -352,
       0,     0,     0,     0,     0,  -352,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,  -352,
       0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,  -352,
       0,   952,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,  -352,     0,     0,     0,     0,   953,     0,
       0,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,   529,     0,     0,  -352,  -352,  -352,  -352,  -352,     0,
       0,  -352,  -352,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,  -352,
       0,  -352,  -352,  -352,     0,     0,     0,     0,  -352,  1311,
       0,  -352,     0,     0,     0,     0,     0,  -352,     0,     0,
     954,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
    -352,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,  -352,     0,     0,
       0,  -352,  -352,  -352,     0,  1455,     0,   958,   959,   960,
       0,  -352,     0,   961,     0,  -352,     0,     0,     0,     0,
       0,  -352,  -352,     0,     0,  -352,     0,     0,   530,     0,
       0,     0,     0,  -352,     0,   616,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
     617,     0,   962,   618,   619,   620,   621,   622,   623,   624,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   625,     0,   626,
     627,   628,   629,   630,   631,   632,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,  -352,  -352,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   964,     0,     0,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,   965,   966,     0,
       0,     0,     0,  -352,  -352,  -352,     0,     0, -1834,     0,
       0,     0,   634,   635,   636,   637,   638,  -352,     0,   639,
     640,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
     530,     0,     0,     0,     0,     0,     0,     0,     0,   970,
     618,   619,   620,   621,   622,   623,     0,     0,     0,     0,
   -1119,     0,     0,   641,     0,     0,     0,     0,     0,   971,
       0,     0,     0,     0,   972,     0,    94,     0, -1119,   642,
       0,   973,   243,   137,   625, -1810,   626,   627,   628,   629,
     630,   631,   632,  1679,     0,     0,  1680,     0,     0,  1681,
     618,   619,   620,   621,   622,   623,  1682,  1683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,     0,     0,     0,  1684,     0,  1685,     0,     0,
     633,     0,     0,     0,   625,     0,   626,   627,   628,   629,
     630,   631,   632,     0,     0,     0,     0,     0,     0,   644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   645,     0,     0,     0,     0,     0,     0,
       0,   646,     0,     0,   647,     0,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,   648,     0,   634,
     635,   636,   637,   638,     0,     0,   639,   640,     0,   649,
       0,     0,     0,     0,     0,     0,     0,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1686,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   952,     0,     0,     0,     0,     0,     0,     0,   634,
     635,   636,   637,   638,     0,     0,   639,   640,   953,   651,
    1687,   652,   653,   654,     0,     0,     0,  1688,     0,  1689,
       0,     0,     0,     0,     0, -1763,     0,     0,     0,     0,
       0,     0,  1690,     0,     0,     0,     0,     0,   655,     0,
     641,     0,     0,     0,     0,     0,     0,     0,   643,     0,
       0,     0,     0,    94,     0,  -349,   642,     0,     0,     0,
       0,     0,     0,     0,  1691,     0,     0,     0,     0,     0,
       0,     0, -1810,  1692,     0,     0,     0,     0,     0,     0,
       0,   656,   657,   658,     0,     0,  1693,     0,     0,     0,
     645,     0,     0,     0,     0,   659,     0,     0,   643,     0,
       0,   647,   660,     0,     0,     0,     0,     0,     0,     0,
     954,     0,     0,   952,   648,     0,     0,     0,     0,     0,
       0,   749,     0,     0,     0,     0,  1694,     0,     0,     0,
     953,     0,     0,     0,     0,     0,     0,     0,     0,  1695,
     645,     0,     0,     0,     0,     0,     0,     0,   646,     0,
       0,   647,     0,     0,   955,     0,     0,     0,     0,     0,
     956,     0,   957,     0,   648,   752,  1696,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,   652,   653,
     654,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1697,     0,     0,     0,     0,     0,     0,  1698,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   962,     0,     0,     0,  1699,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   651,     0,   652,   653,
     654,   963,   954,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,     0,     0,   656,   657,
     658,     0,     0,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,   952,     0,     0,  1700,     0,     0,
       0,     0,  -597,     0,     0,     0,   955,  1701,     0,     0,
       0,   953,   956,     0,   957,     0,   964,   752,     0,   958,
     959,   960,     0,     0,  1702,   961,     0,   753,   656,   657,
     658,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   659,     0,     0,     0,     0,     0,  1703,   660,
       0,     0,     0,     0,     0,   755,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,     0,     0,  1386,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   967,   952,   756,
       0,   968,   969,     0,     0,     0,     0,   754,     0,   970,
       0,     0,     0,   954,   952,   953,     0,     0,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,   971,
       0,   953,     0,     0,   972,     0,   952,     0,   964,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
       0,     0,     0,   953,     0,     0,     0,   955,     0,     0,
       0,     0,     0,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,   755,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1405,
       0,     0,     0,     0,     0,   962,     0,   954,     0,   967,
       0,   756,     0,   968,   969,     0,     0,     0,   749,     0,
       0,   970,     0,   954,   963,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,     0,
       0,   971,     0,     0,     0,   954,   972,     0,   754,     0,
       0,   955,     0,   973,     0,   137,   749,   956,     0,   957,
       0,   757,   752,     0,   958,   959,   960,   955,     0,     0,
     961,     0,   753,   956,     0,   957,     0,     0,   752,   964,
     958,   959,   960,     0,     0,     0,   961,     0,   753,   955,
       0,     0,     0,     0,     0,   956,     0,   957,     0,     0,
     752,     0,   958,   959,   960,     0,     0,     0,   961,   962,
     753,     0,     0,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,     0,   962,     0,     0,   963,     0,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,     0,   962,     0,     0,
    1943,     0,   754,     0,     0,     0,     0,     0,     0,   952,
     967,     0,   756,     0,   968,   969,   963,     0,   754,     0,
       0,     0,   970,     0,     0,     0,   953,     0,     0,     0,
       0,     0,     0,   964,     0,     0,     0,     0,     0,     0,
     754,     0,   971,     0,     0,     0,     0,   972,     0,   964,
       0,     0,     0,     0,   973,     0,   137,     0,     0,     0,
       0,     0,   757,     0,     0,     0,     0,  2653,     0,     0,
       0,   964,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
     755,     0,     0,     0,   967,     0,   756,     0,   968,   969,
       0,     0,   965,   966,     0,     0,   970,     0,   954,     0,
       0,     0,   756,     0,   968,     0,     0,     0,     0,   749,
       0,     0,   970,     0,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,   756,     0,     0,     0,   973,     0,
     137,     0,   971,     0,   970,     0,   757,   972,     0,     0,
       0,     0,   955,     0,   973,     0,   137,     0,   956,     0,
     957,     0,   757,   752,   971,   958,   959,   960,     0,   972,
       0,   961,     0,   753,     0,     0,   973,     0,   137,     0,
       0,     0,     0,     0,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-2263)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   660,   103,   595,   105,   111,   366,
     838,   540,  1101,   111,   649,   714,  1128,   116,  1187,   776,
     684,  1422,  1206,  1568,   358,   181,   784,    56,    57,    58,
    1558,  1422,   135,   425,  1422,    64,  1422,   135,  1422,  1422,
    1463,  1574,   783,   435,   598,  1347,  1104,   404,  1114,  1969,
    1357,  2003,  1444,   209,  1238,     1,  1095,  1512,  1106,  1806,
       9,     9,  1128,  1245,  1231,  1503,  1114,    17,  1954,    57,
      99,   100,   697,   102,   364,    22,   158,   741,   107,   108,
    1128,   184,  1889,   124,   841,     1,  1099,   116,    17,    31,
      53,    31,     0,   107,     9,     6,  1164,    60,  1336,     0,
    1738,  1356,   114,   152,   133,  1497,     9,  1914,   176,   174,
    1178,    86,  2075,    57,   159,   750,   751,  1299,    57,   175,
     256,   123,    63,   129,   788,   241,    96,   165,    27,   123,
       1,   160,  2036,    30,  1436,   308,   203,    70,  1666,  1981,
      70,   141,    57,   203,  1233,   203,   232,   142,   213,  2064,
     225,     6,   251,    55,   232,   176,   203,    26,  1913,   237,
     328,    49,   191,   798,  2299,    49,  2301,    64,  2430,    66,
    1352,   330,    33,  1565,   203,   200,   271,   159,   252,    32,
     357,   252,  1221,  2135,  1486,    48,   274,   218,   203,    21,
     232,   354,   256,   783,  1432,   277,   295,   161,   161,    87,
     308,   747,    21,   406,   829,   410,     6,   196,   256,   232,
      27,   411,    54,   369,  2397,    87,   115,    61,   453,    96,
     249,   414,  1149,   216,  2139,   124,   406,   968,   257,  1277,
     138,     8,   125,   256,   142,     1,  1628,   138,   286,   256,
    1288,   142,   204,   236,   256,    89,    90,    89,   989,   776,
    1391,     6,  1179,    57,  1395,   218,   219,   232,   458,   452,
      37,  1402,   177,   463,   106,     0,   501,   256,   367,   262,
     232,   476,     9,   476,   116,   306,    39,   823,   342,  1345,
      70,   329,  2417,   199,   307,   232,   309,  2470,     6,  2252,
    2253,   340,   200,   456,   287,    70,   476,  1345,   115,   200,
     388,  1349,   317,  1773,   159,  1833,   167,   256,   290,   272,
     418,   293,   329,  1551,   841,   389,   341,   228,   389,   282,
     955,   498,    70,  1868,   187,   289,   241,   196,  2590,   376,
     994,   504,  1639,   129,   363,   503,  2178,   423,  1645,  2254,
     443,  2148,   445,   446,   503,  1815,   341,   445,   446,   452,
     113,   446,   468,  1094,   452,   252,  1994,   212,   457,    49,
    1507,     1,   391,    70,  2119,   955,   469,  1759,   504,   472,
     473,   469,   475,   402,   510,   478,   479,   967,   968,   969,
     447,   256,   411,   412,  1839,   414,   415,  1825,   232,    49,
    1828,   420,   783,  1848,   271,  1633,  1866,   308,   153,   989,
    1547,   256,   462,   256,   462,   123,   267,   452,   437,   451,
     309,   266,   212,   516,   353,  1156,  1157,  1158,   516,   290,
    2383,    61,   497,   461,   453,  1572,   504,   501,  1169,  1170,
       6,  1444,  2318,   341,   331,  1176,   504,   540,   541,   504,
     341,   312,   540,   541,  1502,   451,  1000,  1001,   504,    89,
      90,   451,  1116,  1923,   347,   504,   256,   212,   335,  1965,
     401,   241,   503,    92,    56,   398,   266,   370,   398,   357,
     452,    63,     6,   357,   237,   212,   579,   321,  1984,  1985,
     482,   579,  1988,   504,  1497,   357,   515,  1245,   482,   503,
     504,   346,   504,   592,   212,   598,  1562,   316,   504,  1737,
     599,   256,   446,   793,  1094,   534,  1545,   500,   274,   402,
    1817,   266,  1767,   442,  1562,   448,   271,   505,   448,   256,
     462,  1688,   462,  2029,   499,   554,  1116,   556,  2034,   266,
     559,   560,  1122,   562,   504,   451,     9,  1576,   256,   110,
    2010,  2445,  2446,   451,  2182,   644,   346,   650,   266,   460,
     451,   501,  1565,   468,  1602,   504,   504,   504,   504,  1149,
     589,   416,  2448,  1188,   204,   594,  1156,  1157,  1158,  1159,
    1754,  2104,   601,  1208,  1164,  1757,   967,   968,   969,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,  1655,  1178,  1179,
    2397,   346,   232,   496,  1352,   497,   504,   452,   989,   175,
    2486,  2487,   465,   504,   503,   460,   503,   451,   398,   346,
     498,   411,  2050,   576,   498,  1628,   416,    32,  1208,     6,
    1858,   453,   388,   398,  2371,   421,   498,   504,   346,   504,
     659,  1778,   464,   504,   453,   161,   212,   262,  1785,   402,
     503,  1231,  2528,   606,  2150,   464,  2532,  2533,   262,   504,
     398,  2043,   172,  2045,   458,   510,    22,  1895,   448,   463,
     460,   416,   287,   762,  2616,   256,   256,   357,   767,   772,
     773,   700,   828,   448,   703,  2561,   268,   203,   212,   416,
     256,   321,   781,   786,   234,   451,   376,   244,   468,  1836,
     266,   398,  2084,   256,  2614,   110,     9,   357,   416,   188,
     448,     9,    49,  1094,   504,   460,  1098,     0,  1100,  1093,
     510,   421,   122,  2599,  1762,  1473,   376,  1101,  1102,    64,
    2190,    66,   256,   460,  1314,   244,  1765,  1111,   446,  1470,
     406,  1123,   266,  1125,  1118,  1119,   365,    50,  1130,  2046,
     451,   448,   460,   256,  1891,  2137,  1759,   229,   340,   504,
     218,   458,  1144,  1137,  1138,   510,   463,   256,  1149,   256,
    2230,   451,  2232,   289,   482,  1156,  1157,  1158,   229,    72,
     346,   385,  2508,   510,  1490,  1491,  1492,  1493,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,   504,   256,  1179,   956,
     957,   451,   510,  2263,    30,  2250,   963,    64,  1864,    66,
     476,   406,  1437,    56,   396,   242,    59,   436,   498,   401,
      63,   451,   346,   256,   287,   256,  1864,  1865,   248,   249,
     157,   271,  2328,  2293,  2294,   212,  2332,  2065,    64,  1464,
      66,   117,   118,   119,  2570,   306,   330,   170,   498,  1115,
     416,   256,  1989,  2388,  1236,   138,   314,   397,  2150,   142,
     376,   561,  1610,   410,     9,  1247,   207,   208,  2005,   451,
    1949,   292,   451,   308,  1418,  1141,   232,   338,   171,   256,
     441,   476,   392,   362,   256,   446,   349,  2024,   503,   266,
    1470,   228,   416,   125,   460,  1269,   161,   358,   370,   271,
     165,   410,   225,   324,   231,   246,   247,  1000,  1001,   212,
     233,   406,    57,   346,   212,  2143,  2053,   200,  2437,   370,
    2057,  1010,   446,   504,   504,  1249,  1300,  2462,   351,  1660,
    1584,   751,   257,  2035,  2036,   356,   460,   503,   504,   171,
     244,   244,   245,    56,   510,    47,  2442,  2443,   187,   321,
      63,   504,   262,   256,   387,    31,   503,   384,   256,  2096,
      62,   546,   238,   266,   212,   292,    96,    97,   266,   346,
       6,   210,   274,     9,  2493,   410,   252,   287,   798,  1559,
     504,   476,   422,   416,   424,  1359,   510,   503,  2511,   412,
     413,    56,  2452,  2453,   317,   252,   331,   301,    63,   584,
     102,   504,  1095,  2051,  1584,  1329,  1099,   451,   256,  1757,
    1664,   195,   454,  1106,  1107,   504,    92,   504,   266,   503,
     504,  1114,   177,  1289,  1117,   268,   252,   612,   270,  1122,
    2204,  1124,   177,  1126,  1127,  1128,  1129,   394,  1331,   416,
    2043,   476,  2045,   346,  2082,   504,    82,   153,   346,   351,
    2187,   353,   129,  1146,   337,  2103,  2193,  2575,   341,   335,
     504,   354,   504,    99,  2587,  2478,  2203,   212,  1225,   379,
    1444,   347,   256,   504,   331,  1655,   112,   510,   446,    34,
    1660,  2084,   237,   460,    84,   240,  1792,   329,  1381,  1470,
     341,  1237,  1671,  1475,   451,  2174,   241,   340,   346,  1365,
    1806,   170,  2493,     9,  1101,   331,   262,  2611,  1688,  1483,
     435,   256,  2493,   416,   455,  2493,   457,  2493,   416,  2493,
    2493,   266,  1496,  1497,   285,   138,  1751,   504,  1221,   497,
     232,   287,   504,   510,  2137,  2653,  2273,   239,   510,  2276,
    2277,  1138,  1288,  2647,  2679,    57,   451,  1240,   250,  2667,
     220,    57,  2289,   396,   231,   268,   225,   460,   401,   256,
    1534,   437,   460,   456,   233,   201,  2303,  2304,   416,   494,
       8,    12,   171,   334,    15,    16,   212,     1,  1559,   504,
     199,   504,   252,   445,  1277,   750,   751,    11,   750,   751,
     287,  1565,   228,   503,   504,  1288,   171,  1171,  1172,    37,
     462,   346,     8,   268,   450,   204,   504,   510,  1955,   245,
    1356,    11,   510,   459,   291,   251,   458,   253,   187,   262,
     256,   463,   258,   259,   260,    16,  2363,   340,   264,   204,
     266,    37,  1606,   798,    58,   271,   798,     6,   262,  1332,
       9,   210,    33,  1617,   287,   106,  1620,    26,   317,   351,
     352,    42,  1345,   262,  1628,   116,  1349,   169,    58,  1583,
    2008,   504,   510,   287,   366,    28,   368,   303,  2588,  2589,
    2407,   416,    96,  1898,    98,   340,   100,   394,   287,  1660,
      49,   351,   453,   396,   108,   481,   322,  1126,   401,   359,
    1383,   177,   256,   464,   187,  1383,    96,  2617,    98,   448,
     100,   187,  1649,   499,   323,   324,   212,  1146,   108,   458,
     346,   223,  1458,    82,   463,   460,  2636,   210,    87,  2478,
     307,   340,   309,   468,   210,  1418,   281,   282,   283,  2595,
      99,   396,   356,    13,    14,   241,   401,  2026,   451,   449,
     164,   377,     1,  2445,  2446,  2163,  2448,  2613,   458,   451,
     256,  1444,    32,   463,   240,   451,   448,  2011,  2678,   504,
     266,   451,   453,   126,   164,   510,   458,  2541,   299,   300,
    2373,   463,  2375,   464,  1953,   394,    53,    54,    30,  2004,
     416,    40,    41,    42,    43,    44,   451,   451,  1117,   344,
     458,   504,   428,   429,   423,   463,   498,  1416,  2129,   448,
    1129,     2,  1421,  1422,  1497,  1424,     7,   405,   555,   458,
    2064,   449,    89,   560,   463,   504,    75,    76,  2497,    38,
     458,  1567,  1157,  1158,   460,   463,   226,    46,   783,   106,
     232,  1195,   201,   257,   470,  1199,   277,   278,   394,   116,
     346,   451,   473,   212,   475,  1591,   351,   478,   353,   212,
     474,   405,  1545,  1714,   490,   107,   351,   257,   353,   495,
     301,   302,   451,  1724,  1725,   451,   502,  1728,   504,  1562,
    1616,   351,  1565,   353,   510,   127,   245,   301,   156,   503,
     158,   451,   251,  1576,   253,  2139,    57,   256,  1870,   258,
     259,   260,   156,   256,   158,   264,   218,   266,  1173,  1174,
    1175,   301,   271,   266,   304,   485,   486,   487,   488,  1602,
     416,   466,   467,   252,   166,   254,   471,   280,   173,   178,
     179,   180,   181,   182,   183,   184,   185,   186,  1902,   451,
     212,  1603,   451,   504,   303,  1628,   188,    68,   450,   308,
     252,  1630,   254,   451,   504,   212,   458,   459,   252,  2129,
     254,   463,   204,   322,   460,  1652,  1653,  1654,  1651,   451,
     504,  1658,   468,  1651,  1661,  1662,   390,   451,    65,   369,
      67,   256,   340,     9,   256,   256,    12,   346,   468,    15,
      16,   199,   442,   346,   266,   967,   504,   969,   357,   256,
     390,   400,   211,   401,   410,  1614,    63,    59,   504,   266,
    2254,   232,   256,   451,   510,  1694,   401,   328,   377,   433,
     256,    26,   967,   968,   969,   415,   504,   417,   229,   216,
     217,   451,   451,   107,   243,   451,  1715,   451,   485,   486,
     487,   488,   256,   433,   989,  2154,   312,   272,    23,   236,
     256,   410,   454,   102,   321,   437,   265,   416,   325,   326,
    1669,  1670,   451,   416,   188,    17,   419,   420,   122,   428,
     429,  1680,  1755,    86,   346,   262,  1759,   454,  1687,  1762,
     504,   330,  1765,   212,   485,   486,   487,   488,   451,   346,
     504,   394,   272,   351,   343,   401,    56,   402,   340,   366,
     287,   460,   620,   621,   622,   623,   503,  1716,   423,   318,
     262,   470,    39,  2085,   504,   382,   383,   476,   451,   237,
     402,   504,   506,   419,   331,   504,   316,   256,   310,  2093,
     394,   490,  1815,   261,  1870,   451,   495,   266,     7,   498,
     255,  2078,   451,   502,   416,   504,   394,  1092,   504,  1094,
     451,   510,  1097,   503,   451,   394,  1101,   510,  2129,   416,
     451,   366,   451,    85,    85,  1774,   124,  2131,  2132,   378,
     451,  1116,   394,   389,    22,   306,   309,  1122,   451,   394,
     204,  1864,  1865,  1866,  1793,  1921,   504,   504,   460,   499,
    1799,   451,   384,   501,  1930,  1931,   232,   504,  1143,   446,
    1145,   254,   218,   460,  1149,     6,   504,   122,     9,   446,
     510,  1156,  1157,  1158,  1159,   442,   462,   346,    26,  1164,
     306,   400,   410,   447,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,   504,  1178,  1179,   348,   462,   256,   510,   504,
    1923,  1903,  1904,  1905,  1906,  1907,  1908,  1909,  1910,    24,
      25,   277,   278,   510,   451,   504,   445,   442,   451,   376,
     336,   504,  1207,   399,   473,  1948,   462,   114,   462,   169,
    1948,   187,  2236,   504,   451,   301,   302,  1960,   462,   462,
     256,    82,  1965,   451,   462,     4,  1231,   416,  1233,   462,
      65,   462,    67,    94,    69,   462,   462,   451,    99,  1978,
      19,  1984,  1985,   446,   504,  1988,   309,   403,    35,   504,
      29,    38,   453,   500,    30,   130,   503,   196,    45,    46,
     131,   446,   132,   504,   133,  1934,   386,  2010,   103,   104,
     105,   460,   134,   136,   497,   135,   101,   441,   137,   462,
     446,    49,   140,  1952,    63,   404,  2029,  2583,   445,  2085,
     442,  2034,  2035,  2036,   445,   439,  2035,  2036,  2094,  1968,
    2043,  1970,  2045,   143,    91,  1974,  2602,  2536,   196,  1314,
     144,    31,   145,  1982,   146,   271,   147,   499,   153,    49,
     155,   510,   148,   196,   112,   149,   220,   162,   150,   114,
     165,  1336,   151,   448,   312,   446,   410,  2566,   448,  2082,
     201,  2084,   448,   448,   448,   448,   109,   197,   446,   451,
     203,   212,   376,   339,   256,   272,   223,  1362,  2588,  2589,
     294,   298,   484,   165,   501,   231,   501,   128,   175,   365,
    2394,   446,   168,   160,   228,   129,   446,    49,   165,   196,
     228,   204,   176,   299,   245,    56,   204,  2617,   504,   451,
     251,   272,   253,   165,  2137,   256,   252,   258,   259,   260,
     237,   509,   189,   264,   423,   266,  2636,  2150,  2077,   508,
     271,  2154,   299,   446,   446,   380,  2154,   252,   362,   254,
      30,   276,   203,   295,   211,   203,    17,  1432,   442,  2461,
    2454,   128,   139,   365,  2458,  2459,   271,   446,    49,   203,
      35,   220,   303,    38,     8,   141,   196,   129,  2678,   501,
      45,    46,   501,   423,   203,   446,   451,     9,     7,   504,
     503,   322,   203,   256,   294,  1470,   503,   498,   297,   498,
      49,   188,   314,   252,   313,   291,   262,  2509,   265,   330,
     113,   461,   436,   262,    47,   346,   411,  2230,   203,  2232,
     203,   294,    49,   102,   380,   262,    91,   361,   237,   296,
     492,    95,   292,    56,   361,     8,    49,   110,   456,   337,
     262,   262,   109,   451,   262,   481,   377,  2260,   210,   340,
    2263,   451,  2260,   337,   107,   209,   221,   501,   418,   367,
     119,   318,   196,   337,    49,   306,   315,   321,   313,     7,
     425,   320,    46,    26,    92,   127,  1551,   201,   148,   206,
      75,  2294,   221,   238,  1559,   416,   177,  2588,  2589,   469,
     150,   519,  1869,   410,   286,   160,   773,   428,   429,  1009,
    1575,  2314,   351,   425,   497,  1422,  2314,   740,  2586,  1584,
     359,  2651,   788,  1862,   783,  2328,  2617,  2152,  2630,  2332,
    1595,   378,  2663,   372,   189,  2599,  1018,  2175,  2175,   460,
    2048,  1204,    82,   779,   391,  2636,   841,  1727,   443,   470,
    1726,  1809,  2357,  1761,  1221,  1456,   211,  2046,  1623,    99,
    1458,  1483,   401,  2292,  1502,   404,  1505,  2228,  1633,   490,
    2373,  2050,  2375,   412,   495,  1828,  1555,  2246,  1273,  1548,
    2073,   502,  1856,   504,   423,  1309,  1566,  2678,  2391,   510,
    1655,  2085,  1314,  2092,  1882,  1660,  1931,  1596,   493,  2106,
    1911,  1343,  2694,  2132,  1129,  1345,  1930,  2336,  1359,   504,
     265,  2340,   451,  1930,  2297,   454,  2647,  1643,  2397,  1534,
    2307,  2302,  2125,  1688,  2125,  1332,   473,  2125,  2125,   691,
    1452,   299,   152,  1898,   270,  1700,   242,   745,  1703,  2442,
    2443,   972,  2445,  2446,  2519,  2448,  2445,  2446,   417,   509,
    2385,  2565,   449,   215,  1918,  1861,  2062,   705,  1558,  2590,
      -1,   201,   558,   318,    -1,    -1,    -1,  2396,    -1,    -1,
      -1,    -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   955,    -1,    -1,  2428,
    2429,    -1,    -1,    -1,    -1,  2508,    -1,    -1,   967,   968,
     969,    -1,    -1,    -1,    -1,  2444,   256,    -1,   258,   259,
     260,    -1,    -1,   378,   264,    -1,    -1,    -1,    -1,    -1,
     989,  2460,    -1,    -1,    -1,    -1,   391,    -1,    -1,  2538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2485,    -1,    -1,    -1,
      -1,  2490,  2491,   303,    -1,    -1,    -1,  2570,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,    -1,     5,
      -1,  2510,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,  1858,  1859,  2594,    -1,    -1,    -1,  2598,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2611,    -1,
      -1,  2540,    -1,    -1,  2543,  2544,    -1,    -1,   473,    -1,
      -1,    -1,  1887,    -1,    -1,    51,    52,    -1,    -1,    -1,
    1895,    -1,    -1,    -1,    60,  1094,    -1,   377,    -1,    -1,
    1099,    -1,    -1,    -1,  2647,    71,    -1,  1106,    74,    -1,
      -1,    -1,    -1,    -1,    -1,  1114,  2585,  1922,    -1,    -1,
      -1,    -1,    88,    -1,  1929,  1930,    -1,    -1,  2671,  1128,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    -1,
      -1,    -1,    -1,  2682,  1949,   111,    -1,    -1,   428,   429,
    1149,    -1,    -1,   119,  1959,   121,    -1,  1156,  1157,  1158,
    1159,    -1,    -1,    -1,    -1,  1164,    -1,    -1,    -1,    -1,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,    -1,  1178,
    1179,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,  2011,    -1,    -1,  1208,
     490,    82,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    99,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,   205,
     206,  1240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
    2055,    -1,    -1,    -1,    -1,    -1,   222,    -1,   224,  2064,
    2065,   227,    -1,    -1,    -1,    -1,    -1,    -1,  2073,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,  1277,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,  2092,    -1,  1288,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,
      -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,  2121,    -1,    -1,   285,
      -1,    -1,    -1,    -1,  2129,     6,    -1,    -1,     9,    -1,
     201,    -1,    -1,    -1,  2139,    -1,    -1,  1336,  2143,    -1,
      -1,   212,    -1,    -1,    -1,   311,  1345,    -1,    -1,    -1,
    1349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
    2165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2174,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,   349,   350,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,   360,   266,    -1,    -1,    -1,    -1,
     271,    82,    -1,    -1,  2209,    -1,    -1,    -1,   374,   375,
      -1,    -1,    -1,    94,    -1,   381,    -1,    -1,    99,   385,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,
      -1,    -1,   303,  1432,    -1,    -1,    -1,   403,    -1,    -1,
      -1,   209,    -1,    -1,    -1,  1444,   412,    -1,    -1,  2254,
      -1,   322,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,   235,    -1,    -1,
      -1,  1470,   438,    -1,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,   451,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1497,    -1,
      -1,    -1,    -1,   469,    -1,    -1,   377,    -1,    -1,   475,
      -1,    -1,    -1,    -1,   480,    -1,    -1,   285,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,
      -1,   507,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,  1551,    -1,    -1,    -1,    -1,   428,   429,   327,
    1559,  2366,    -1,  1562,   245,   333,  1565,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,   453,   264,    -1,   266,    -1,    -1,    -1,   460,
     271,    -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,  1602,  2409,    -1,    -1,    -1,    -1,    -1,
      -1,  2416,    -1,    -1,  2419,    -1,    -1,    -1,    -1,   490,
      -1,    -1,   303,    -1,   495,    -1,    -1,    -1,    -1,  1628,
      -1,   502,    -1,   504,  1633,    -1,    -1,   405,    -1,   510,
      -1,   322,    -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,    -1,    -1,
      -1,  1660,  2467,   431,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2481,    -1,    -1,    -1,
      -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2497,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,
      38,    -1,    -1,   491,    -1,    -1,    -1,    -1,    46,    -1,
     498,   499,    -1,    -1,    -1,   416,    -1,    -1,  1737,    -1,
    2545,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1755,    -1,    -1,    -1,
    1759,    -1,    -1,  1762,    -1,    -1,    -1,    -1,     1,    -1,
       3,    -1,     5,    91,    -1,    -1,    -1,    10,    -1,   460,
      -1,    -1,    -1,  2588,  2589,    18,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2605,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,
      -1,    -1,  2617,    -1,   495,    -1,  1815,    -1,    51,    52,
      -1,   502,    -1,   504,  2629,  2630,    -1,    60,    -1,   510,
      -1,  2636,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,  1858,
    1859,    -1,    -1,    -1,    -1,  1864,  1865,  1866,    -1,  2674,
      -1,   189,    -1,  2678,    -1,    -1,    -1,    -1,   111,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
      -1,    -1,    -1,   211,    -1,   128,  1895,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,  1923,   243,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     288,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,
      -1,   224,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
     318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
     273,    -1,   275,    -1,  2043,    -1,  2045,    -1,    -1,    -1,
      -1,    -1,   285,   371,    -1,    -1,    -1,    -1,   291,   292,
     378,   294,   295,   296,   297,    -1,  2065,    -1,    -1,    -1,
      -1,    -1,    -1,   391,  2073,    -1,    -1,   395,   311,    -1,
      -1,    -1,    -1,  2082,    -1,  2084,     1,    -1,     3,    -1,
       5,   324,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   360,    -1,    -1,
    2129,    -1,    -1,    -1,    -1,    -1,    51,    52,  2137,    -1,
      -1,   374,   375,    -1,  2143,    60,    -1,     6,   381,    -1,
       9,    -1,   385,    -1,    -1,   473,    71,    -1,    -1,    74,
     393,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,
     403,   489,    -1,    88,    -1,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,   426,   427,    82,   111,   430,    -1,   432,
      -1,    -1,    -1,    -1,   119,   438,   121,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2230,    -1,  2232,    -1,    94,   469,   152,    -1,    -1,
      99,    -1,   475,    -1,    -1,    -1,    -1,   480,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2263,    -1,    -1,    -1,   501,    -1,
      -1,    -1,    -1,    -1,   507,     1,    -1,     3,    -1,     5,
     195,    -1,    -1,    -1,    10,    -1,    -1,   202,    -1,    -1,
     205,   206,    18,    -1,    -1,  2294,    -1,    -1,    -1,    -1,
     215,    -1,    -1,   190,    -1,    -1,    -1,   222,    -1,   224,
      -1,    -1,   227,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,   212,   269,    -1,    -1,    -1,   273,    -1,
     275,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     285,   258,   259,   260,  2373,    -1,  2375,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   245,    -1,    -1,    -1,
      -1,    -1,   251,   119,   253,   121,   311,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,   324,
      -1,    -1,   271,    -1,    -1,    -1,   303,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,   350,    -1,   163,    -1,    -1,
      -1,    -1,   168,    -1,   303,   360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,
     375,    -1,    -1,   322,    -1,    -1,   381,    -1,    -1,   195,
     385,    -1,    -1,    -1,    -1,    -1,   202,    -1,   393,   205,
     206,    -1,    -1,    -1,    -1,    -1,    -1,   346,   403,   215,
     377,    -1,    -1,    -1,    -1,    -1,   222,   412,   224,    -1,
      -1,   227,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,   426,   427,    -1,    -1,   430,    -1,   432,   377,    -1,
      -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,   428,   429,   269,    -1,    -1,    -1,   273,    -1,   275,
      -1,    -1,   439,    -1,   469,    -1,    -1,   416,    -1,   285,
     475,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,     9,    -1,   470,    -1,   311,    -1,    -1,    -1,  2588,
    2589,    -1,   507,    -1,   481,    -1,    -1,    -1,   324,    -1,
      -1,   460,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,   470,   499,    -1,    -1,   502,   503,   504,  2617,    -1,
      -1,    -1,    -1,   349,   350,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,   360,    -1,   495,  2636,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,   374,   375,
      -1,   510,    -1,    -1,    82,   381,    -1,    -1,    -1,   385,
      -1,     3,    -1,     5,    -1,    -1,    -1,   393,    10,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    18,   403,    -1,  2678,
      -1,    -1,    -1,    -1,   112,    -1,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,    -1,    -1,    51,
      52,    -1,   438,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   469,    -1,    -1,    88,    -1,    -1,   475,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,   201,    -1,    -1,    -1,   119,    -1,   121,
      -1,   507,    -1,    -1,   212,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   163,    -1,   251,    -1,   253,   168,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,   303,    -1,    -1,    -1,    -1,
     222,    -1,   224,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,   416,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,   375,    -1,    -1,    -1,    -1,    -1,   381,
      -1,    -1,   470,   385,    -1,    -1,    -1,    -1,    -1,   159,
      -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,   403,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
     412,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,   421,
      -1,    -1,   510,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,   201,    -1,    -1,    -1,    -1,   438,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,   469,    -1,    -1,
      -1,    -1,    -1,   475,    -1,   245,   246,   247,   480,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,     6,    -1,   507,     9,    -1,    -1,    12,
      13,    14,    -1,    -1,   284,    -1,    -1,    20,    -1,    -1,
     290,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,   303,    -1,    -1,    -1,    -1,   308,    -1,
      -1,     6,    -1,   313,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,     6,    -1,    -1,     9,    -1,    -1,   377,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,     6,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    82,   448,    -1,
     450,    -1,   452,    -1,    -1,   455,    -1,   457,   458,   459,
     460,    -1,   462,   463,    99,    -1,    -1,    -1,   201,    -1,
     470,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,   201,    -1,    -1,    -1,
     510,    -1,   245,   246,   247,    82,    -1,   212,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
     165,   264,    99,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   284,    -1,    -1,    -1,    -1,   251,   290,   253,    -1,
     293,   256,    -1,   258,   259,   260,   201,    -1,   301,   264,
     303,   266,    -1,    -1,    -1,   308,   271,   212,    -1,    -1,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
     245,    -1,    -1,   346,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,   322,    -1,   264,
      -1,   266,    -1,    -1,   201,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,   212,    -1,     6,    -1,    -1,
       9,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,   377,   416,   251,    -1,   253,   322,    -1,   256,
      -1,   258,   259,   260,    -1,   428,   429,   264,    -1,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,   448,    -1,   450,    -1,   452,
      -1,   416,   455,    82,   457,   458,   459,   460,    -1,   462,
     463,    -1,    -1,   428,   429,    -1,   303,   470,    -1,    -1,
      99,    -1,   377,     6,    -1,    -1,     9,    -1,    -1,    -1,
      -1,   446,    -1,    -1,    -1,   322,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,   460,    -1,    -1,    -1,   502,
       6,   504,    -1,     9,    -1,   470,    -1,   510,    -1,   346,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
     377,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    99,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    82,    -1,    -1,   416,
      -1,    -1,    -1,   212,    -1,   490,    -1,    -1,    -1,    -1,
     495,   428,   429,    99,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,   460,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,   470,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,   201,    -1,
      -1,    -1,    -1,   510,   303,    -1,    -1,    -1,    -1,   212,
      -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,   346,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,   245,
      -1,     6,    -1,    -1,     9,   251,    -1,   253,   377,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    82,   264,    -1,
     266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,   322,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     346,   470,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      99,   377,    -1,   502,    -1,   504,   201,   410,    -1,    -1,
      -1,   510,    -1,   416,    -1,    -1,    -1,   212,    -1,    82,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,   428,   429,    -1,    -1,   251,   460,   253,    -1,
      -1,   256,    -1,   258,   259,   260,   201,   470,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,   271,   212,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,   470,    -1,    -1,    -1,    -1,   502,
      -1,   504,   201,    -1,    -1,    -1,    -1,   510,   303,    -1,
     245,    -1,    -1,   212,   490,    -1,   251,    -1,   253,   495,
      -1,   256,    -1,   258,   259,   260,   502,   322,   504,   264,
      -1,   266,    -1,    -1,   510,    -1,   271,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,   346,    -1,    -1,    -1,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,   303,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
     303,    -1,   377,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,   377,    -1,
      -1,   416,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,     1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,   377,   510,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,   470,    32,    -1,    -1,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,   416,    -1,   490,    -1,    -1,    -1,    -1,
     495,   460,    -1,    -1,    -1,   428,   429,   502,    64,   504,
      66,   470,    -1,    -1,    -1,   510,    -1,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,   460,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,   470,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
      -1,    -1,   178,   179,   180,   181,   182,     1,    -1,   185,
     186,    -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,    -1,    -1,    -1,    21,   204,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    36,   219,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,   232,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,   241,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,   305,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   318,   319,    -1,    -1,    -1,    -1,    99,    -1,
      -1,   327,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,    -1,    -1,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,    -1,   371,    -1,    -1,    -1,    -1,
      -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,   405,
      -1,   407,   408,   409,    -1,    -1,    -1,    -1,   232,   190,
      -1,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     446,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,
     456,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   468,    -1,    -1,    -1,    -1,   473,    -1,    -1,
      -1,   477,   478,   479,    -1,   256,    -1,   258,   259,   260,
      -1,   305,    -1,   264,    -1,   491,    -1,    -1,    -1,    -1,
      -1,   497,   498,    -1,    -1,   319,    -1,    -1,   504,    -1,
      -1,    -1,    -1,   327,    -1,    21,   330,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,
      36,    -1,   303,    39,    40,    41,    42,    43,    44,    45,
      -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,   407,   408,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   468,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,   477,   478,   479,    -1,    -1,   439,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   491,    -1,   185,
     186,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,
     504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
     481,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,   232,    -1,   499,   235,
      -1,   502,   503,   504,    73,   241,    75,    76,    77,    78,
      79,    80,    81,    32,    -1,    -1,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,
     119,    -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,   305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   327,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,   355,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    99,   405,
     189,   407,   408,   409,    -1,    -1,    -1,   196,    -1,   198,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   434,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,
      -1,    -1,    -1,   232,    -1,   451,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   468,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   477,   478,   479,    -1,    -1,   265,    -1,    -1,    -1,
     319,    -1,    -1,    -1,    -1,   491,    -1,    -1,   277,    -1,
      -1,   330,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    82,   343,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,
      -1,   330,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,   343,   256,   345,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,   407,   408,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,   407,   408,
     409,   322,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   477,   478,
     479,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,   446,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,   245,   456,    -1,    -1,
      -1,    99,   251,    -1,   253,    -1,   377,   256,    -1,   258,
     259,   260,    -1,    -1,   473,   264,    -1,   266,   477,   478,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,   497,   498,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,   448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    82,   460,
      -1,   462,   463,    -1,    -1,    -1,    -1,   346,    -1,   470,
      -1,    -1,    -1,   201,    82,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   490,
      -1,    99,    -1,    -1,   495,    -1,    82,    -1,   377,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,    -1,    -1,    99,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,   416,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,
      -1,    -1,    -1,    -1,    -1,   303,    -1,   201,    -1,   458,
      -1,   460,    -1,   462,   463,    -1,    -1,    -1,   212,    -1,
      -1,   470,    -1,   201,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,   201,   495,    -1,   346,    -1,
      -1,   245,    -1,   502,    -1,   504,   212,   251,    -1,   253,
      -1,   510,   256,    -1,   258,   259,   260,   245,    -1,    -1,
     264,    -1,   266,   251,    -1,   253,    -1,    -1,   256,   377,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,   303,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   322,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,   303,    -1,    -1,
     448,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    82,
     458,    -1,   460,    -1,   462,   463,   322,    -1,   346,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
     346,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,   377,
      -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,   373,    -1,    -1,
      -1,   377,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,   458,    -1,   460,    -1,   462,   463,
      -1,    -1,   428,   429,    -1,    -1,   470,    -1,   201,    -1,
      -1,    -1,   460,    -1,   462,    -1,    -1,    -1,    -1,   212,
      -1,    -1,   470,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,   460,    -1,    -1,    -1,   502,    -1,
     504,    -1,   490,    -1,   470,    -1,   510,   495,    -1,    -1,
      -1,    -1,   245,    -1,   502,    -1,   504,    -1,   251,    -1,
     253,    -1,   510,   256,   490,   258,   259,   260,    -1,   495,
      -1,   264,    -1,   266,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510
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
     603,   535,   523,   451,   232,   537,  1266,   504,  1186,  1186,
     423,   405,  1284,  1266,  1266,  1266,   394,  1186,   405,   451,
     451,  1266,   451,   451,    57,  1254,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1266,  1266,  1266,   504,  1181,  1212,
      68,  1181,   451,  1266,  1266,   549,   560,  1181,   545,   504,
     587,   588,   589,  1187,   256,   307,   309,   573,   575,  1031,
    1215,  1266,   451,   504,   451,   606,   539,   340,  1281,  1266,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1218,
    1181,   256,   218,   306,  1304,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1253,  1314,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1187,  1267,  1031,   232,   423,  1278,  1266,
      96,  1186,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1297,  1212,   400,   401,   410,
      63,  1266,   451,   552,   451,   504,   551,    59,  1266,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1297,   256,
     590,  1216,  1278,   232,  1186,  1186,   574,   575,   451,     1,
     290,   312,  1239,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1218,   328,  1266,   401,  1215,   451,  1266,
     504,  1182,   229,    26,   565,   229,   370,   451,   451,   107,
    1216,  1186,   451,   312,  1186,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1215,   257,   435,
     494,   557,  1182,   256,   272,   608,   454,  1257,    23,  1248,
     102,   648,   451,   582,   583,    57,   505,  1308,   609,   437,
    1290,   188,  1259,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1282,  1298,    86,  1255,   504,  1171,  1172,   451,   394,   650,
     583,   272,  1273,   351,  1282,   446,   497,  1294,   401,   402,
    1266,  1253,   113,   237,  1268,  1268,   287,   635,  1215,  1297,
     423,   262,    39,  1251,  1266,   645,   646,  1172,  1172,   451,
     172,   392,   530,   651,   652,   654,  1266,  1268,   125,   171,
     614,   359,   628,  1266,  1266,  1266,  1266,  1248,     9,   287,
     349,   637,  1266,  1273,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1172,   125,   347,   402,   618,  1266,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1181,  1185,   419,   632,  1181,  1181,   316,  1279,  1279,
     310,  1181,  1266,  1215,   394,   261,   732,   683,   684,   686,
     696,  1231,   451,   653,   632,   256,   616,  1212,   616,     7,
     616,   616,   256,   615,  1212,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1233,  1313,  1257,
    1266,  1180,  1181,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1266,   124,  1180,
    1181,   262,   385,   681,   733,   451,   394,   389,   781,   698,
     689,  1266,  1255,  1266,   351,   353,  1309,  1309,  1266,  1255,
    1266,  1273,  1266,    22,  1247,   306,   678,  1186,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1266,
    1286,    26,   196,   697,  1249,   204,  1215,   504,  1266,  1247,
     504,  1183,  1184,   308,   418,  1305,  1185,  1215,   499,  1266,
     174,   213,   504,   665,  1186,   274,   351,   353,  1307,   681,
     737,   451,   337,   795,   798,   244,   301,   406,   476,  1285,
     476,  1285,   476,  1285,   476,  1285,   476,  1285,   501,  1295,
     384,  1283,  1215,  1209,  1212,  1212,   232,   242,   384,  1269,
    1266,  1267,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1219,
    1220,  1221,   446,   662,  1184,   254,  1272,   446,  1254,   218,
    1261,   504,  1266,  1266,  1307,   738,   782,   122,   821,   822,
     510,   446,   713,   462,  1213,  1214,   442,   706,   727,   728,
    1219,    26,   702,   400,  1243,  1243,  1221,   306,  1276,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1209,   691,   447,  1215,    57,   353,   658,   669,  1215,
     410,  1287,   256,   666,  1212,   666,   348,   739,   686,   696,
     783,   784,   785,    55,   497,   799,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   823,   824,
     839,   844,   848,   853,   868,   871,   875,   879,   880,   881,
     886,   900,   904,   907,   921,   925,   928,   931,   935,   936,
     940,   950,   953,   970,   972,   975,   979,   985,   997,  1005,
    1006,  1009,  1010,  1014,  1019,  1020,  1028,  1043,  1053,  1062,
    1067,  1074,  1078,  1080,  1083,  1086,  1090,  1117,   823,  1215,
     445,  1292,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1159,  1161,  1162,  1163,  1164,  1165,
    1166,  1194,  1208,  1209,  1220,  1222,  1223,  1224,  1225,   462,
    1214,  1212,   726,   728,   442,   256,  1253,   691,   451,  1221,
      48,   465,   670,   671,   672,   673,  1297,  1254,   196,   661,
    1260,   504,  1173,     1,   687,   785,   451,   801,   800,   376,
     807,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1244,   825,   840,   845,   849,   854,   869,   872,   876,
     882,   887,   901,   905,   908,   922,   926,   929,   932,   203,
     376,   863,   924,   937,   941,   951,   954,   971,   973,   976,
     399,   980,   986,   998,  1007,  1011,  1015,  1021,  1029,  1044,
    1054,   256,   346,   387,   416,   510,  1066,  1068,  1075,   336,
    1079,  1081,   810,  1084,  1087,  1091,  1118,   114,   714,   462,
    1227,  1209,  1220,  1222,  1304,  1304,   462,   462,   462,   462,
    1304,  1165,  1161,  1165,   462,  1227,    70,   398,   448,  1160,
     449,   458,   463,   450,   459,   169,   462,  1226,   462,   462,
    1161,   501,   729,  1296,  1219,  1185,  1185,   187,   662,  1215,
     740,   451,   786,   451,    49,   802,   803,   804,  1252,   802,
     504,   451,   308,   826,   827,  1208,     6,    94,   245,   271,
     841,  1166,  1190,  1191,  1208,  1219,  1222,   846,  1161,  1208,
     256,   850,   851,  1177,  1178,  1179,  1212,   271,   422,   424,
     855,   856,   256,   870,  1199,  1208,   873,  1172,     6,   877,
    1167,  1168,  1189,  1210,  1211,  1212,  1220,   454,   883,  1172,
     256,   888,   889,   891,  1190,  1191,  1199,  1208,   902,  1191,
     256,   906,   453,   464,   909,   910,   911,  1149,  1150,  1151,
     199,   323,   324,   340,   394,   923,   927,  1188,  1189,   930,
    1212,   446,   933,  1293,  1191,  1148,  1149,   942,  1188,   952,
    1173,   955,   956,  1208,  1219,  1222,  1045,  1206,  1207,  1212,
      94,   974,  1191,   977,  1191,   170,   225,   233,   317,   981,
     982,   190,   256,   987,   991,   992,   993,  1177,  1200,  1208,
    1212,  1222,  1297,   999,  1172,  1008,  1169,  1212,  1012,  1172,
    1016,  1169,     9,  1022,  1170,  1212,   153,   271,  1030,  1033,
    1034,  1037,  1038,  1039,  1040,  1041,  1042,  1174,  1175,  1188,
    1205,  1207,  1212,  1045,  1055,  1172,  1063,   112,  1069,  1070,
    1071,  1191,    94,  1076,  1190,  1082,  1173,   451,   504,   811,
     812,   815,   816,   821,  1085,  1208,  1088,  1172,  1092,  1208,
    1119,  1169,   309,  1277,   715,   716,   448,  1159,  1161,   504,
     504,  1161,  1230,  1230,  1230,  1193,  1208,  1220,  1222,  1229,
     504,   448,  1193,  1228,  1161,   448,  1161,  1162,  1162,  1163,
    1163,  1163,  1161,  1193,  1159,   403,   453,    30,  1250,  1254,
       1,   741,   787,   803,   410,   476,   805,   357,   498,   796,
     130,   838,    30,   829,   830,  1250,   196,  1276,  1208,  1209,
    1220,  1222,   131,   843,   446,   842,  1191,    57,   223,  1234,
     851,   446,  1304,   132,   867,   256,  1200,  1199,  1172,   356,
     474,   874,  1297,  1310,  1276,   133,   878,   159,   452,  1168,
    1301,   386,  1240,  1213,  1214,   884,  1172,   134,   885,  1282,
     135,   899,   165,   890,  1128,  1129,   484,   892,   503,   830,
     485,   486,   487,   488,   136,   903,    49,   228,   497,   857,
     137,   920,    17,   501,   912,   913,   914,   916,    12,    13,
      14,    20,   159,   169,   207,   208,   246,   247,   284,   290,
     293,   301,   308,   313,   332,   448,   450,   452,   455,   457,
     458,   459,   462,   463,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1191,   101,   924,  1189,  1176,   441,  1291,   943,  1297,
    1173,    92,   365,   436,   957,   958,   960,   961,  1047,   462,
    1213,  1191,   446,   140,   978,    49,   982,   404,   983,   992,
     141,   451,   988,   990,   481,   499,   442,   445,   439,   143,
    1004,   285,   334,  1237,   196,  1120,   144,  1013,  1282,   145,
    1018,  1120,  1170,   146,  1027,   499,  1023,  1197,  1208,  1220,
    1040,  1042,  1188,   446,  1175,   123,   446,   482,  1032,    31,
    1213,   147,  1061,   177,   237,   240,  1057,   863,  1064,  1297,
    1252,   148,  1073,   228,  1071,  1208,   149,  1077,   196,  1173,
     394,   451,   451,   196,   351,   353,  1089,   150,  1101,   112,
    1093,   151,  1124,  1120,  1181,   220,   718,    27,   115,   717,
     448,  1160,   448,   448,   448,  1160,   448,  1160,   448,   448,
     449,   448,   448,   446,  1266,  1185,   114,   660,   451,    61,
      89,    90,   321,   451,   742,   743,   746,  1266,  1322,    32,
      35,    38,    45,    46,    64,    66,   160,   189,   196,   198,
     211,   243,   252,   265,   305,   318,   345,   371,   378,   395,
     446,   456,   473,   497,   704,   705,   709,   721,   723,   725,
     788,   793,   794,  1266,  1299,  1266,   410,   312,   806,   109,
     808,  1197,   197,   833,   252,   331,   831,   832,  1299,    24,
      25,    65,    67,    69,   103,   104,   105,   153,   155,   162,
     165,   252,   254,   443,   493,   504,   828,  1175,  1300,   152,
     340,  1195,  1209,   446,     6,  1167,  1191,  1212,  1220,   203,
     223,  1235,   376,   847,   339,   852,  1179,   857,   874,   262,
     287,  1259,  1209,  1161,   272,  1241,  1214,  1172,   231,  1144,
    1145,   818,   819,   891,  1191,   294,  1130,    96,   335,   504,
    1175,   298,   896,    35,    38,    45,    46,    91,   160,   189,
     211,   265,   318,   378,   391,   473,   897,   898,   484,   893,
    1128,  1128,  1128,  1128,  1191,  1167,  1191,   858,   911,    21,
     453,   464,   917,   918,  1150,   501,   914,   915,   501,   818,
    1293,   232,  1153,   114,   934,  1177,   128,   818,   938,     9,
      12,    15,    16,   277,   278,   301,   302,   944,   948,   175,
    1197,     9,    57,   177,   241,   468,   964,   965,   966,   959,
     960,  1049,  1277,  1313,   446,  1188,  1167,  1191,   983,  1297,
    1171,   818,   168,   994,  1148,   995,   996,  1208,  1177,     8,
      37,  1122,  1282,  1204,  1208,  1219,  1222,   228,  1000,  1017,
    1297,   129,  1024,  1208,  1024,   446,   446,  1031,   152,   453,
     464,  1191,    49,    38,    46,   211,   243,   265,   318,   378,
     473,  1035,  1036,  1266,  1056,  1297,  1191,   161,   289,   410,
    1191,  1208,   196,  1167,  1191,   817,  1215,  1197,  1252,   228,
    1096,  1121,  1122,  1252,  1268,  1181,  1226,  1226,  1226,  1193,
     241,   468,  1226,   448,  1161,  1226,  1226,  1219,  1277,  1266,
    1266,  1247,   248,   249,  1271,   755,   204,   176,   744,  1258,
    1266,   252,   389,   156,   158,  1266,  1200,   299,  1274,  1215,
      56,  1208,  1208,   204,  1274,    32,   110,  1215,  1266,   504,
     451,   797,   272,   834,  1274,  1274,   832,   831,  1274,   165,
    1125,  1126,   509,   508,  1197,  1125,   237,   423,   299,   276,
     256,  1196,  1209,  1208,  1276,   411,  1131,  1132,  1213,  1214,
    1167,   446,  1236,   847,  1189,   446,  1177,   862,   863,   380,
     362,  1131,  1266,   818,   295,  1146,   820,   818,  1128,  1266,
     252,   389,   156,   158,  1266,   123,   482,   898,  1128,    96,
      97,   894,   834,   203,  1131,   203,   859,   860,   861,  1252,
      17,   442,   919,   316,   917,  1277,   818,   128,   139,   939,
    1293,   365,   945,  1293,   446,    49,   965,   967,  1197,     9,
      57,   241,   468,   962,   963,  1197,  1050,  1298,   717,   218,
     314,  1262,  1188,  1131,   203,  1171,   637,   379,   984,  1297,
     141,   989,     8,   196,  1000,  1208,   129,  1137,  1139,  1144,
     262,   287,   818,   501,   501,  1025,  1026,  1197,  1196,  1191,
    1031,  1031,  1031,  1031,  1031,  1031,  1031,  1031,  1036,   290,
     293,  1058,  1059,  1060,  1154,  1238,  1144,   244,   410,  1312,
     423,  1289,  1289,  1072,  1297,  1208,  1131,   203,   451,   446,
       9,  1094,  1095,  1232,  1097,  1208,  1072,  1097,  1017,     7,
    1245,   504,   719,   720,  1266,   448,  1181,  1199,  1266,  1247,
     256,   747,  1217,   686,   756,   745,  1208,   510,  1201,  1205,
    1215,  1201,  1266,  1292,  1266,  1266,    32,  1215,   809,   810,
    1266,   503,   835,  1201,  1201,  1201,   818,   294,  1127,  1125,
    1240,  1209,   818,   297,  1133,  1214,  1131,  1198,  1208,  1219,
     165,   461,   865,  1303,     6,   228,   308,   460,   864,  1265,
      34,   281,   282,   283,   344,   466,   467,   471,  1242,   818,
     821,  1201,  1201,  1147,  1203,  1205,  1215,  1147,   503,   895,
    1167,  1168,  1167,  1168,   860,   308,   805,    87,   357,   498,
     918,  1149,   818,  1208,   818,   498,   946,   947,   948,   949,
    1291,   498,  1198,  1197,    49,   968,   963,   188,   968,  1046,
    1266,  1268,   314,  1167,   984,   262,   287,   996,  1191,   217,
    1001,  1297,   818,   291,  1140,   262,  1149,  1148,  1025,  1154,
    1208,  1155,  1156,  1157,  1158,  1161,  1065,  1191,  1065,   461,
    1134,  1135,   330,  1240,  1167,   813,  1198,   313,  1197,   113,
    1098,   436,  1100,   157,   292,  1123,  1141,  1142,  1143,  1144,
     321,  1175,  1201,   720,  1180,   748,   252,   254,  1306,   504,
     687,  1208,   270,   329,   458,   463,   789,   790,   791,  1199,
     789,   790,   792,   810,    47,    32,    35,    38,    46,    91,
     189,   198,   211,   243,   263,   265,   288,   318,   345,   371,
     378,   391,   395,   444,   473,   483,   489,   836,   837,  1125,
     818,  1131,   818,   294,   866,   818,  1276,  1208,   252,   254,
    1311,   897,  1131,   361,  1131,   361,  1191,   947,   102,  1256,
    1293,   968,   968,  1198,     8,    37,   969,   225,   497,  1051,
    1181,  1048,  1131,   380,    49,   262,   237,  1002,   216,   236,
     262,   287,   500,   818,   818,   818,   818,   296,  1136,  1266,
    1131,  1131,   492,   814,  1102,  1095,  1261,    95,  1099,  1261,
    1134,   818,   818,  1143,   252,   254,  1270,   177,   187,   210,
     240,   749,   750,   751,   752,   753,   754,  1217,   757,  1201,
    1201,   129,  1266,  1266,    56,   123,   482,     8,  1246,   837,
     818,  1208,  1168,  1168,    49,   110,   968,   456,  1264,  1264,
     337,  1171,   203,   317,  1052,  1212,  1191,  1266,  1003,  1138,
    1139,  1140,  1144,   262,   262,   262,   818,  1208,  1103,   451,
    1208,  1261,  1208,   106,   116,  1315,  1266,  1266,    54,    89,
    1315,  1316,  1300,   758,   109,  1201,  1201,  1266,  1147,  1147,
    1202,  1205,  1217,  1131,  1131,  1191,  1191,  1191,  1266,  1171,
     337,   481,  1208,  1140,   127,   166,   204,  1104,  1105,  1106,
    1108,  1112,  1114,  1115,  1116,  1250,  1259,  1208,  1266,  1217,
    1217,   210,  1266,  1266,   209,   252,   254,   285,   305,   333,
     414,   431,   451,   472,   491,   499,   704,   709,   710,   721,
     723,   725,   759,   760,   764,   765,   768,   769,   770,   771,
     772,   773,   778,   779,   780,  1299,  1300,   451,  1199,   991,
    1266,  1148,    37,  1246,   340,   107,  1217,  1217,  1217,   221,
    1263,   299,   300,  1275,  1247,   209,  1215,   501,  1266,  1276,
    1266,  1266,  1208,   286,   329,   774,   775,  1217,   329,   776,
     777,  1217,  1275,  1247,   991,   367,   418,  1288,   129,   421,
    1113,  1277,  1267,  1266,   713,  1148,  1194,  1192,  1194,    53,
      89,   321,   325,   326,   366,   382,   383,   761,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,   119,   196,  1215,   775,  1215,
     777,  1267,  1208,   161,   165,  1302,     9,  1109,  1110,  1178,
     775,  1292,  1240,   373,   766,  1194,   187,   187,   210,   187,
     210,   176,   762,  1208,   762,  1194,   337,  1280,   306,   338,
     358,  1111,  1110,   714,  1277,   313,   763,   763,    49,  1277,
     306,  1212,   425,   711,   176,   767,  1208,   321,  1194,   170,
     225,   233,   317,  1107,  1171,  1215
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

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  YYUSE (yytype);
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
/* Line 1787 of yacc.c  */
#line 1340 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1351 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1387 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1442 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1471 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1504 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 1510 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 1522 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 1532 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1563 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 1570 "parser.y"
    {
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
/* Line 1787 of yacc.c  */
#line 1606 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 1607 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 1616 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1625 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1639 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 1643 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 1653 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 1662 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "CONFIGURATION SECTION");
	}
  }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 1687 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1705 "parser.y"
    {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item ();
  }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 1718 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 1747 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 1754 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 1761 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 1768 "parser.y"
    {
	if (current_program->classification) {
		cb_error (_("Duplicate CLASSIFICATION clause"));
	} else {
		current_program->classification = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 1779 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 1783 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 1787 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 1791 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 1805 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 1810 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 1818 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 1830 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 1834 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1855 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 1859 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 1866 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 1871 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 1882 "parser.y"
    {
	check_duplicate = 0;
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	header_check |= COBC_HD_SPECIAL_NAMES;
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	}
  }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 1896 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1927 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
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
/* Line 1787 of yacc.c  */
#line 1946 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1956 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1969 "parser.y"
    {
	if (save_tree && CB_VALID_TREE ((yyvsp[(2) - (3)]))) {
		cb_define ((yyvsp[(2) - (3)]), save_tree);
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
				(yyvsp[(2) - (3)]), save_tree);
	}
  }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1985 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 1995 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2010 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
		(yyval) = NULL;
	} else {
		/* Returns null on error */
		(yyval) = cb_build_alphabet_name ((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 2023 "parser.y"
    {
	if ((yyvsp[(3) - (5)])) {
		current_program->alphabet_name_list =
			cb_list_add (current_program->alphabet_name_list, (yyvsp[(3) - (5)]));
	}
	cobc_cs_check = 0;
  }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 2034 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 2040 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 2046 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 2052 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 2058 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 2064 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 2074 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 2078 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 2085 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 2089 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 2093 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 2097 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 2104 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 2108 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 2114 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 2115 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 2116 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 2117 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 2118 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 2119 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 2127 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else if ((yyvsp[(1) - (2)])) {
		CB_CHAIN_PAIR (current_program->symbolic_char_list, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 2141 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 2145 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 2153 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 2160 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 2164 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 2175 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2195 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 2203 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 2213 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 2214 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 2221 "parser.y"
    {
	cb_tree		x;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
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
/* Line 1787 of yacc.c  */
#line 2241 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 2242 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 2247 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 2251 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2272 "parser.y"
    {
	cb_tree	l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
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
/* Line 1787 of yacc.c  */
#line 2295 "parser.y"
    {
	unsigned char	*s = CB_LITERAL ((yyvsp[(4) - (5)]))->data;
	unsigned int	error_ind = 0;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
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
/* Line 1787 of yacc.c  */
#line 2376 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 2380 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 2389 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else {
		check_repeated ("DECIMAL-POINT", SYN_CLAUSE_2);
		current_program->decimal_point = ',';
		current_program->numeric_separator = '.';
	}
  }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 2408 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else {
		current_program->flag_trailing_separate = 1;
	}
  }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 2424 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else {
		check_repeated ("CURSOR", SYN_CLAUSE_3);
		current_program->cursor_pos = (yyvsp[(3) - (3)]);
	}
  }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 2442 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else {
		check_repeated ("CRT STATUS", SYN_CLAUSE_4);
		current_program->crt_status = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 2460 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else {
		check_repeated ("SCREEN CONTROL", SYN_CLAUSE_5);
		PENDING ("SCREEN CONTROL");
	}
  }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 2477 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "SPECIAL-NAMES");
	} else {
		check_repeated ("EVENT STATUS", SYN_CLAUSE_6);
		PENDING ("EVENT STATUS");
	}
  }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 2494 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2502 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2511 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2526 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2543 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 2547 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2581 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2587 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2597 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2610 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2623 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2646 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 2653 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2666 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2678 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2685 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2686 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2687 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2695 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2722 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2733 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 2748 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 2756 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 2761 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 2766 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 2775 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 2779 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 2795 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 2800 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 2805 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 2810 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 2821 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 2832 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 2842 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 2849 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 2850 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 2851 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 2858 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 2869 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 2883 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 2890 "parser.y"
    { (yyval) = NULL; }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 2891 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 2892 "parser.y"
    { (yyval) = NULL; }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 2901 "parser.y"
    {
	yyerrok;
  }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 2920 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 2947 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 2948 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 2949 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 2950 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 2957 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 2962 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 2989 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 2998 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3012 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3031 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3048 "parser.y"
    {
	yyerrok;
  }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3055 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3059 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3070 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3080 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_2);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_external) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("%s is invalid in a user FUNCTION"), "GLOBAL");
	} else {
		current_file->flag_global = 1;
		current_program->flag_file_global = 1;
	}
  }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3110 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 3123 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3143 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3178 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3209 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 3215 "parser.y"
    { (yyval) = NULL; }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 3216 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 3220 "parser.y"
    { (yyval) = NULL; }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 3221 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 3229 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 3240 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 3245 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 3268 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 3280 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3308 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 3315 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 3322 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 3331 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 3343 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3395 "parser.y"
    {
	check_repeated ("REPORT", SYN_CLAUSE_11);
	PENDING("REPORT WRITER");
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("REPORT clause with wrong file type"));
	} else {
		current_file->reports = (yyvsp[(2) - (2)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	}
  }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 3415 "parser.y"
    {
	current_report = build_report ((yyvsp[(1) - (1)]));
	current_report->file = current_file;
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 3425 "parser.y"
    {
	current_report = build_report ((yyvsp[(2) - (2)]));
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 3465 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 3471 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 3480 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 3483 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 3489 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 3509 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3524 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3544 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3557 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 3564 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 3570 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 3576 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 3585 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 3594 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 3598 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("%s is invalid in a user FUNCTION"), "GLOBAL");
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 3609 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 3610 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 3611 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 3612 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 3617 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 3621 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 3625 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 3629 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 3633 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 3637 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 3641 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 3645 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 3649 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 3653 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 3657 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 3661 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 3665 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 3697 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3723 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 3727 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 3735 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 3741 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 3769 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 3793 "parser.y"
    {
	check_pic_repeated ("EXTERNAL", SYN_CLAUSE_2);
	if (current_storage != CB_STORAGE_WORKING) {
		cb_error (_("%s not allowed here"), "EXTERNAL");
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("%s only allowed at 01/77 level"), "EXTERNAL");
	} else if (!qualifier) {
		cb_error (_("%s requires a data name"), "EXTERNAL");
#if	0	/* RXWRXW - Global/External */
	} else if (current_field->flag_is_global) {
		cb_error (_("%s and %s are mutually exclusive"), "GLOBAL", "EXTERNAL");
#endif
	} else if (current_field->flag_item_based) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "EXTERNAL");
	} else if (current_field->redefines) {
		cb_error (_("%s and %s are mutually exclusive"), "EXTERNAL", "REDEFINES");
	} else if (current_field->flag_occurs) {
		cb_error (_("%s and %s are mutually exclusive"), "EXTERNAL", "OCCURS");
	} else {
		current_field->flag_external = 1;
		current_program->flag_has_external = 1;
	}
  }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 3820 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 3824 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 3833 "parser.y"
    {
	check_pic_repeated ("GLOBAL", SYN_CLAUSE_3);
	if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("%s only allowed at 01/77 level"), "GLOBAL");
	} else if (!qualifier) {
		cb_error (_("%s requires a data name"), "GLOBAL");
#if	0	/* RXWRXW - Global/External */
	} else if (current_field->flag_external) {
		cb_error (_("%s and %s are mutually exclusive"), "GLOBAL", "EXTERNAL");
#endif
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("%s is invalid in a user FUNCTION"), "GLOBAL");
	} else if (current_storage == CB_STORAGE_LOCAL) {
		cb_error (_("%s not allowed here"), "GLOBAL");
	} else {
		current_field->flag_is_global = 1;
	}
  }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 3858 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 3874 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 3878 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 3882 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 3886 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 3890 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 3894 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 3898 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 3902 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 3906 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 3910 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 3914 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 3918 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 3922 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 3927 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 3932 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 3936 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 3940 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 3948 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 3952 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 3956 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 3964 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 3968 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 3972 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 3976 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 3980 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 3984 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 3988 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 3992 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 3996 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 4004 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 4012 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 4016 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 4020 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 4024 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 4028 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 4032 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 4052 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 4058 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 4071 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 4089 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 4099 "parser.y"
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
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "OCCURS");
	} else if (current_field->flag_external) {
		cb_error (_("%s and %s are mutually exclusive"), "EXTERNAL", "OCCURS");
	}
	current_field->flag_occurs = 1;
  }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 4121 "parser.y"
    { (yyval) = NULL; }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 4122 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 4127 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 4134 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 4157 "parser.y"
    { (yyval) = NULL; }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 4160 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 4175 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 4176 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 4181 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 4187 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 4189 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 4194 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 4205 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 4216 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 4227 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 4238 "parser.y"
    {
	check_pic_repeated ("BASED", SYN_CLAUSE_11);
	if (current_storage != CB_STORAGE_WORKING &&
	    current_storage != CB_STORAGE_LINKAGE &&
	    current_storage != CB_STORAGE_LOCAL) {
		cb_error (_("%s not allowed here"), "BASED");
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("%s only allowed at 01/77 level"), "BASED");
	} else if (!qualifier) {
		cb_error (_("%s requires a data name"), "BASED");
	} else if (current_field->flag_external) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "EXTERNAL");
	} else if (current_field->redefines) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "REDEFINES");
	} else if (current_field->flag_any_length) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "ANY LENGTH");
	} else if (current_field->flag_occurs) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "OCCURS");
	} else {
		current_field->flag_item_based = 1;
	}
  }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 4266 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 4274 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 4275 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 4279 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 4280 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 4285 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 4298 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 4311 "parser.y"
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
/* Line 1787 of yacc.c  */
#line 4332 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "ANY clause");
	} else {
		current_field->flag_any_length = 1;
	}
  }
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 4341 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("%s and %s are mutually exclusive"), "BASED", "ANY clause");
	} else {
		current_field->flag_any_length = 1;
		current_field->flag_any_numeric = 1;
	}
  }
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 4356 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("%s not allowed in nested programs"), "LOCAL-STORAGE");
	}
  }
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 4365 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 4377 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 4383 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 4394 "parser.y"
    {
	PENDING("REPORT SECTION");
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  }
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 4410 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  }
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 4425 "parser.y"
    {
	yyerrok;
  }
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 4432 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 4437 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 4448 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 4467 "parser.y"
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

  case 512:
/* Line 1787 of yacc.c  */
#line 4503 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 4507 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  }
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 4512 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  }
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 4532 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 4539 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 4546 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 4553 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 4560 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 4571 "parser.y"
    {
	check_pic_duplicate = 0;
  }
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 4602 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 4628 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 4635 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  }
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 4651 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 4662 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  }
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 4674 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 4707 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  }
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 4714 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  }
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 4721 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 4730 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 4737 "parser.y"
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

  case 596:
/* Line 1787 of yacc.c  */
#line 4763 "parser.y"
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

  case 597:
/* Line 1787 of yacc.c  */
#line 4794 "parser.y"
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

  case 598:
/* Line 1787 of yacc.c  */
#line 4820 "parser.y"
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

  case 601:
/* Line 1787 of yacc.c  */
#line 4843 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 602:
/* Line 1787 of yacc.c  */
#line 4847 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 603:
/* Line 1787 of yacc.c  */
#line 4851 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 604:
/* Line 1787 of yacc.c  */
#line 4855 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 605:
/* Line 1787 of yacc.c  */
#line 4859 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 4863 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 607:
/* Line 1787 of yacc.c  */
#line 4867 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 4871 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 4875 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 4879 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 4883 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 4887 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 4891 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 4895 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 4899 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 4903 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 4907 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 4912 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 4916 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 4920 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 4925 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 4930 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 4935 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 4948 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 4955 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 634:
/* Line 1787 of yacc.c  */
#line 4960 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 639:
/* Line 1787 of yacc.c  */
#line 4979 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 640:
/* Line 1787 of yacc.c  */
#line 4983 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 4987 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 642:
/* Line 1787 of yacc.c  */
#line 4994 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 4998 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 644:
/* Line 1787 of yacc.c  */
#line 5002 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 645:
/* Line 1787 of yacc.c  */
#line 5010 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 646:
/* Line 1787 of yacc.c  */
#line 5021 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 648:
/* Line 1787 of yacc.c  */
#line 5030 "parser.y"
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

  case 649:
/* Line 1787 of yacc.c  */
#line 5040 "parser.y"
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

  case 650:
/* Line 1787 of yacc.c  */
#line 5052 "parser.y"
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

  case 651:
/* Line 1787 of yacc.c  */
#line 5067 "parser.y"
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

  case 653:
/* Line 1787 of yacc.c  */
#line 5100 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 654:
/* Line 1787 of yacc.c  */
#line 5104 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 655:
/* Line 1787 of yacc.c  */
#line 5109 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 656:
/* Line 1787 of yacc.c  */
#line 5117 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
    break;

  case 657:
/* Line 1787 of yacc.c  */
#line 5126 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 658:
/* Line 1787 of yacc.c  */
#line 5136 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 659:
/* Line 1787 of yacc.c  */
#line 5138 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 660:
/* Line 1787 of yacc.c  */
#line 5143 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 662:
/* Line 1787 of yacc.c  */
#line 5152 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 663:
/* Line 1787 of yacc.c  */
#line 5156 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("%s not allowed in CHAINED programs"), "BY VALUE");
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 665:
/* Line 1787 of yacc.c  */
#line 5168 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 666:
/* Line 1787 of yacc.c  */
#line 5176 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 667:
/* Line 1787 of yacc.c  */
#line 5184 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 668:
/* Line 1787 of yacc.c  */
#line 5192 "parser.y"
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

  case 669:
/* Line 1787 of yacc.c  */
#line 5221 "parser.y"
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

  case 671:
/* Line 1787 of yacc.c  */
#line 5254 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 672:
/* Line 1787 of yacc.c  */
#line 5263 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 673:
/* Line 1787 of yacc.c  */
#line 5269 "parser.y"
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
		} else if(f->flag_occurs) {
			cb_error(_("RETURNING item should not have OCCURS"));
		} else if(f->storage == CB_STORAGE_LOCAL) {
			cb_error (_("RETURNING item should not be in LOCAL-STORAGE"));
		} else {
			if (current_program->prog_type == CB_FUNCTION_TYPE) {
				f->flag_is_returning = 1;
			}
			current_program->returning = (yyvsp[(2) - (2)]);
		}
	}
  }
    break;

  case 675:
/* Line 1787 of yacc.c  */
#line 5297 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 676:
/* Line 1787 of yacc.c  */
#line 5303 "parser.y"
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

  case 681:
/* Line 1787 of yacc.c  */
#line 5340 "parser.y"
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

  case 683:
/* Line 1787 of yacc.c  */
#line 5358 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 684:
/* Line 1787 of yacc.c  */
#line 5368 "parser.y"
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

  case 685:
/* Line 1787 of yacc.c  */
#line 5412 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 688:
/* Line 1787 of yacc.c  */
#line 5423 "parser.y"
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

  case 689:
/* Line 1787 of yacc.c  */
#line 5471 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 690:
/* Line 1787 of yacc.c  */
#line 5483 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 691:
/* Line 1787 of yacc.c  */
#line 5487 "parser.y"
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

  case 692:
/* Line 1787 of yacc.c  */
#line 5505 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 693:
/* Line 1787 of yacc.c  */
#line 5510 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 694:
/* Line 1787 of yacc.c  */
#line 5515 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 695:
/* Line 1787 of yacc.c  */
#line 5523 "parser.y"
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

  case 696:
/* Line 1787 of yacc.c  */
#line 5550 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 697:
/* Line 1787 of yacc.c  */
#line 5554 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 747:
/* Line 1787 of yacc.c  */
#line 5610 "parser.y"
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

  case 748:
/* Line 1787 of yacc.c  */
#line 5624 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 749:
/* Line 1787 of yacc.c  */
#line 5635 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 751:
/* Line 1787 of yacc.c  */
#line 5645 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 752:
/* Line 1787 of yacc.c  */
#line 5650 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 753:
/* Line 1787 of yacc.c  */
#line 5654 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 754:
/* Line 1787 of yacc.c  */
#line 5658 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 755:
/* Line 1787 of yacc.c  */
#line 5663 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 756:
/* Line 1787 of yacc.c  */
#line 5668 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 757:
/* Line 1787 of yacc.c  */
#line 5673 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 758:
/* Line 1787 of yacc.c  */
#line 5678 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 759:
/* Line 1787 of yacc.c  */
#line 5682 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 760:
/* Line 1787 of yacc.c  */
#line 5686 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 761:
/* Line 1787 of yacc.c  */
#line 5690 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 762:
/* Line 1787 of yacc.c  */
#line 5694 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 763:
/* Line 1787 of yacc.c  */
#line 5699 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 764:
/* Line 1787 of yacc.c  */
#line 5703 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 765:
/* Line 1787 of yacc.c  */
#line 5707 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 766:
/* Line 1787 of yacc.c  */
#line 5711 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 767:
/* Line 1787 of yacc.c  */
#line 5715 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 768:
/* Line 1787 of yacc.c  */
#line 5719 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 769:
/* Line 1787 of yacc.c  */
#line 5723 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 771:
/* Line 1787 of yacc.c  */
#line 5731 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 774:
/* Line 1787 of yacc.c  */
#line 5742 "parser.y"
    { (yyval) = NULL; }
    break;

  case 775:
/* Line 1787 of yacc.c  */
#line 5743 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 776:
/* Line 1787 of yacc.c  */
#line 5747 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 777:
/* Line 1787 of yacc.c  */
#line 5748 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 778:
/* Line 1787 of yacc.c  */
#line 5749 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 779:
/* Line 1787 of yacc.c  */
#line 5750 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 780:
/* Line 1787 of yacc.c  */
#line 5751 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 781:
/* Line 1787 of yacc.c  */
#line 5755 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 782:
/* Line 1787 of yacc.c  */
#line 5759 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 783:
/* Line 1787 of yacc.c  */
#line 5760 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 787:
/* Line 1787 of yacc.c  */
#line 5769 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 792:
/* Line 1787 of yacc.c  */
#line 5785 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 793:
/* Line 1787 of yacc.c  */
#line 5789 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 794:
/* Line 1787 of yacc.c  */
#line 5793 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 795:
/* Line 1787 of yacc.c  */
#line 5797 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 796:
/* Line 1787 of yacc.c  */
#line 5801 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 797:
/* Line 1787 of yacc.c  */
#line 5805 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 798:
/* Line 1787 of yacc.c  */
#line 5809 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 799:
/* Line 1787 of yacc.c  */
#line 5813 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 800:
/* Line 1787 of yacc.c  */
#line 5817 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 801:
/* Line 1787 of yacc.c  */
#line 5821 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 802:
/* Line 1787 of yacc.c  */
#line 5825 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 803:
/* Line 1787 of yacc.c  */
#line 5829 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 804:
/* Line 1787 of yacc.c  */
#line 5833 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 805:
/* Line 1787 of yacc.c  */
#line 5837 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 806:
/* Line 1787 of yacc.c  */
#line 5841 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 807:
/* Line 1787 of yacc.c  */
#line 5845 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 808:
/* Line 1787 of yacc.c  */
#line 5849 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 809:
/* Line 1787 of yacc.c  */
#line 5853 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 810:
/* Line 1787 of yacc.c  */
#line 5857 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 811:
/* Line 1787 of yacc.c  */
#line 5861 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 812:
/* Line 1787 of yacc.c  */
#line 5865 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 813:
/* Line 1787 of yacc.c  */
#line 5869 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 814:
/* Line 1787 of yacc.c  */
#line 5873 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 815:
/* Line 1787 of yacc.c  */
#line 5877 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 816:
/* Line 1787 of yacc.c  */
#line 5884 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 817:
/* Line 1787 of yacc.c  */
#line 5888 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 818:
/* Line 1787 of yacc.c  */
#line 5898 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 820:
/* Line 1787 of yacc.c  */
#line 5907 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 821:
/* Line 1787 of yacc.c  */
#line 5911 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 822:
/* Line 1787 of yacc.c  */
#line 5915 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 824:
/* Line 1787 of yacc.c  */
#line 5922 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 825:
/* Line 1787 of yacc.c  */
#line 5929 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 826:
/* Line 1787 of yacc.c  */
#line 5933 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 827:
/* Line 1787 of yacc.c  */
#line 5943 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 829:
/* Line 1787 of yacc.c  */
#line 5952 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 830:
/* Line 1787 of yacc.c  */
#line 5956 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 831:
/* Line 1787 of yacc.c  */
#line 5967 "parser.y"
    { (yyval) = NULL; }
    break;

  case 832:
/* Line 1787 of yacc.c  */
#line 5968 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 833:
/* Line 1787 of yacc.c  */
#line 5976 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 837:
/* Line 1787 of yacc.c  */
#line 5990 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 840:
/* Line 1787 of yacc.c  */
#line 6002 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 842:
/* Line 1787 of yacc.c  */
#line 6017 "parser.y"
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

  case 843:
/* Line 1787 of yacc.c  */
#line 6031 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 844:
/* Line 1787 of yacc.c  */
#line 6036 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 845:
/* Line 1787 of yacc.c  */
#line 6041 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 846:
/* Line 1787 of yacc.c  */
#line 6046 "parser.y"
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

  case 847:
/* Line 1787 of yacc.c  */
#line 6066 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 848:
/* Line 1787 of yacc.c  */
#line 6070 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 849:
/* Line 1787 of yacc.c  */
#line 6075 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 850:
/* Line 1787 of yacc.c  */
#line 6086 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 851:
/* Line 1787 of yacc.c  */
#line 6088 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 852:
/* Line 1787 of yacc.c  */
#line 6093 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 853:
/* Line 1787 of yacc.c  */
#line 6101 "parser.y"
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

  case 855:
/* Line 1787 of yacc.c  */
#line 6127 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 856:
/* Line 1787 of yacc.c  */
#line 6131 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("%s not allowed in CHAINED programs"), "BY CONTENT");
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 857:
/* Line 1787 of yacc.c  */
#line 6140 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("%s not allowed in CHAINED programs"), "BY VALUE");
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 858:
/* Line 1787 of yacc.c  */
#line 6152 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 859:
/* Line 1787 of yacc.c  */
#line 6156 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 860:
/* Line 1787 of yacc.c  */
#line 6160 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 861:
/* Line 1787 of yacc.c  */
#line 6164 "parser.y"
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

  case 866:
/* Line 1787 of yacc.c  */
#line 6197 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 867:
/* Line 1787 of yacc.c  */
#line 6202 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 868:
/* Line 1787 of yacc.c  */
#line 6209 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 869:
/* Line 1787 of yacc.c  */
#line 6214 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 870:
/* Line 1787 of yacc.c  */
#line 6221 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 871:
/* Line 1787 of yacc.c  */
#line 6225 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 872:
/* Line 1787 of yacc.c  */
#line 6235 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 874:
/* Line 1787 of yacc.c  */
#line 6243 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 875:
/* Line 1787 of yacc.c  */
#line 6247 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 876:
/* Line 1787 of yacc.c  */
#line 6257 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 878:
/* Line 1787 of yacc.c  */
#line 6265 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 879:
/* Line 1787 of yacc.c  */
#line 6270 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 880:
/* Line 1787 of yacc.c  */
#line 6277 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 881:
/* Line 1787 of yacc.c  */
#line 6278 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 882:
/* Line 1787 of yacc.c  */
#line 6279 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 883:
/* Line 1787 of yacc.c  */
#line 6280 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 884:
/* Line 1787 of yacc.c  */
#line 6281 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 885:
/* Line 1787 of yacc.c  */
#line 6289 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 887:
/* Line 1787 of yacc.c  */
#line 6298 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 888:
/* Line 1787 of yacc.c  */
#line 6305 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 889:
/* Line 1787 of yacc.c  */
#line 6309 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 890:
/* Line 1787 of yacc.c  */
#line 6319 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 891:
/* Line 1787 of yacc.c  */
#line 6330 "parser.y"
    {
	size_t	save_unreached;

	/* Do not check unreached for CONTINUE */
	save_unreached = check_unreached;
	check_unreached = 0;
	begin_statement ("CONTINUE", 0);
	cb_emit_continue ();
	check_unreached = (unsigned int) save_unreached;
  }
    break;

  case 892:
/* Line 1787 of yacc.c  */
#line 6347 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 894:
/* Line 1787 of yacc.c  */
#line 6356 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 896:
/* Line 1787 of yacc.c  */
#line 6364 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 897:
/* Line 1787 of yacc.c  */
#line 6369 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 898:
/* Line 1787 of yacc.c  */
#line 6377 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 899:
/* Line 1787 of yacc.c  */
#line 6381 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 900:
/* Line 1787 of yacc.c  */
#line 6391 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 902:
/* Line 1787 of yacc.c  */
#line 6401 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 903:
/* Line 1787 of yacc.c  */
#line 6405 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 904:
/* Line 1787 of yacc.c  */
#line 6409 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 905:
/* Line 1787 of yacc.c  */
#line 6413 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 906:
/* Line 1787 of yacc.c  */
#line 6417 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 908:
/* Line 1787 of yacc.c  */
#line 6422 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 910:
/* Line 1787 of yacc.c  */
#line 6432 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 912:
/* Line 1787 of yacc.c  */
#line 6440 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 913:
/* Line 1787 of yacc.c  */
#line 6448 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 914:
/* Line 1787 of yacc.c  */
#line 6456 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 915:
/* Line 1787 of yacc.c  */
#line 6460 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 916:
/* Line 1787 of yacc.c  */
#line 6464 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 917:
/* Line 1787 of yacc.c  */
#line 6468 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 923:
/* Line 1787 of yacc.c  */
#line 6490 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 924:
/* Line 1787 of yacc.c  */
#line 6496 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 925:
/* Line 1787 of yacc.c  */
#line 6497 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 928:
/* Line 1787 of yacc.c  */
#line 6508 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 929:
/* Line 1787 of yacc.c  */
#line 6512 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 930:
/* Line 1787 of yacc.c  */
#line 6516 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 931:
/* Line 1787 of yacc.c  */
#line 6520 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 932:
/* Line 1787 of yacc.c  */
#line 6524 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 933:
/* Line 1787 of yacc.c  */
#line 6528 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 934:
/* Line 1787 of yacc.c  */
#line 6532 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 935:
/* Line 1787 of yacc.c  */
#line 6536 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 936:
/* Line 1787 of yacc.c  */
#line 6540 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 937:
/* Line 1787 of yacc.c  */
#line 6544 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 938:
/* Line 1787 of yacc.c  */
#line 6548 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 939:
/* Line 1787 of yacc.c  */
#line 6552 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 940:
/* Line 1787 of yacc.c  */
#line 6556 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 941:
/* Line 1787 of yacc.c  */
#line 6560 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 942:
/* Line 1787 of yacc.c  */
#line 6564 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 943:
/* Line 1787 of yacc.c  */
#line 6568 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 944:
/* Line 1787 of yacc.c  */
#line 6575 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 945:
/* Line 1787 of yacc.c  */
#line 6579 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 946:
/* Line 1787 of yacc.c  */
#line 6589 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 948:
/* Line 1787 of yacc.c  */
#line 6598 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 949:
/* Line 1787 of yacc.c  */
#line 6602 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 950:
/* Line 1787 of yacc.c  */
#line 6606 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 951:
/* Line 1787 of yacc.c  */
#line 6610 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 952:
/* Line 1787 of yacc.c  */
#line 6614 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 953:
/* Line 1787 of yacc.c  */
#line 6621 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 954:
/* Line 1787 of yacc.c  */
#line 6625 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 955:
/* Line 1787 of yacc.c  */
#line 6635 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 957:
/* Line 1787 of yacc.c  */
#line 6643 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("%s is invalid in nested program"), "ENTRY");
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("%s is invalid in a user FUNCTION"), "ENTRY");
	} else if (cb_verify (cb_entry_statement, "ENTRY")) {
		if (!cobc_check_valid_name ((char *)(CB_LITERAL ((yyvsp[(1) - (2)]))->data), 1U)) {
			emit_entry ((char *)(CB_LITERAL ((yyvsp[(1) - (2)]))->data), 1, (yyvsp[(2) - (2)]));
		}
	}
	check_unreached = 0;
  }
    break;

  case 958:
/* Line 1787 of yacc.c  */
#line 6662 "parser.y"
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

  case 960:
/* Line 1787 of yacc.c  */
#line 6686 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 961:
/* Line 1787 of yacc.c  */
#line 6693 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 962:
/* Line 1787 of yacc.c  */
#line 6695 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 963:
/* Line 1787 of yacc.c  */
#line 6700 "parser.y"
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

  case 964:
/* Line 1787 of yacc.c  */
#line 6711 "parser.y"
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

  case 965:
/* Line 1787 of yacc.c  */
#line 6722 "parser.y"
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

  case 966:
/* Line 1787 of yacc.c  */
#line 6736 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 967:
/* Line 1787 of yacc.c  */
#line 6740 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 968:
/* Line 1787 of yacc.c  */
#line 6746 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 969:
/* Line 1787 of yacc.c  */
#line 6748 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 970:
/* Line 1787 of yacc.c  */
#line 6754 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 971:
/* Line 1787 of yacc.c  */
#line 6763 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 972:
/* Line 1787 of yacc.c  */
#line 6771 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 973:
/* Line 1787 of yacc.c  */
#line 6777 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 974:
/* Line 1787 of yacc.c  */
#line 6784 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 975:
/* Line 1787 of yacc.c  */
#line 6786 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 976:
/* Line 1787 of yacc.c  */
#line 6791 "parser.y"
    {
	cb_tree	not0;
	cb_tree	e1;
	cb_tree	e2;
	cb_tree	x;
	cb_tree	parm1;

	not0 = cb_int0;
	e2 = (yyvsp[(2) - (2)]);
	x = NULL;
	parm1 = (yyvsp[(1) - (2)]);
	if (eval_check[eval_level][eval_inc2]) {
		/* Check if the first token is NOT */
		/* It may belong to the EVALUATE, however see */
		/* below when it may be part of a partial expression */
		if (CB_PURPOSE_INT (parm1) == '!') {
			/* Pop stack if subject not TRUE / FALSE */
			not0 = cb_int1;
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
			not0 = CB_PURPOSE (parm1);
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
	(yyval) = CB_BUILD_PAIR (not0, CB_BUILD_PAIR (e1, e2));
  }
    break;

  case 977:
/* Line 1787 of yacc.c  */
#line 6852 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 978:
/* Line 1787 of yacc.c  */
#line 6853 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 979:
/* Line 1787 of yacc.c  */
#line 6854 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 980:
/* Line 1787 of yacc.c  */
#line 6858 "parser.y"
    { (yyval) = NULL; }
    break;

  case 981:
/* Line 1787 of yacc.c  */
#line 6859 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 982:
/* Line 1787 of yacc.c  */
#line 6864 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 983:
/* Line 1787 of yacc.c  */
#line 6868 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 984:
/* Line 1787 of yacc.c  */
#line 6878 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 985:
/* Line 1787 of yacc.c  */
#line 6883 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 987:
/* Line 1787 of yacc.c  */
#line 6891 "parser.y"
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
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	current_statement->name = (const char *)"EXIT PROGRAM";
	cb_emit_exit (0);
  }
    break;

  case 988:
/* Line 1787 of yacc.c  */
#line 6912 "parser.y"
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

  case 989:
/* Line 1787 of yacc.c  */
#line 6926 "parser.y"
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

  case 990:
/* Line 1787 of yacc.c  */
#line 6948 "parser.y"
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

  case 991:
/* Line 1787 of yacc.c  */
#line 6970 "parser.y"
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

  case 992:
/* Line 1787 of yacc.c  */
#line 6990 "parser.y"
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

  case 993:
/* Line 1787 of yacc.c  */
#line 7012 "parser.y"
    { (yyval) = NULL; }
    break;

  case 994:
/* Line 1787 of yacc.c  */
#line 7013 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 995:
/* Line 1787 of yacc.c  */
#line 7021 "parser.y"
    {
	begin_statement ("FREE", 0);
  }
    break;

  case 997:
/* Line 1787 of yacc.c  */
#line 7029 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 998:
/* Line 1787 of yacc.c  */
#line 7039 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  }
    break;

  case 1001:
/* Line 1787 of yacc.c  */
#line 7055 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1003:
/* Line 1787 of yacc.c  */
#line 7068 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1004:
/* Line 1787 of yacc.c  */
#line 7076 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1005:
/* Line 1787 of yacc.c  */
#line 7081 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1006:
/* Line 1787 of yacc.c  */
#line 7092 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  }
    break;

  case 1007:
/* Line 1787 of yacc.c  */
#line 7107 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1009:
/* Line 1787 of yacc.c  */
#line 7116 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1010:
/* Line 1787 of yacc.c  */
#line 7120 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1011:
/* Line 1787 of yacc.c  */
#line 7124 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1012:
/* Line 1787 of yacc.c  */
#line 7131 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1013:
/* Line 1787 of yacc.c  */
#line 7135 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1014:
/* Line 1787 of yacc.c  */
#line 7145 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1016:
/* Line 1787 of yacc.c  */
#line 7154 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1017:
/* Line 1787 of yacc.c  */
#line 7160 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1018:
/* Line 1787 of yacc.c  */
#line 7161 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1019:
/* Line 1787 of yacc.c  */
#line 7165 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1020:
/* Line 1787 of yacc.c  */
#line 7166 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1021:
/* Line 1787 of yacc.c  */
#line 7167 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1022:
/* Line 1787 of yacc.c  */
#line 7172 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1023:
/* Line 1787 of yacc.c  */
#line 7176 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1024:
/* Line 1787 of yacc.c  */
#line 7183 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1025:
/* Line 1787 of yacc.c  */
#line 7188 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1026:
/* Line 1787 of yacc.c  */
#line 7195 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1027:
/* Line 1787 of yacc.c  */
#line 7201 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1028:
/* Line 1787 of yacc.c  */
#line 7202 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1029:
/* Line 1787 of yacc.c  */
#line 7203 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1030:
/* Line 1787 of yacc.c  */
#line 7204 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1031:
/* Line 1787 of yacc.c  */
#line 7205 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1032:
/* Line 1787 of yacc.c  */
#line 7206 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1033:
/* Line 1787 of yacc.c  */
#line 7207 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1034:
/* Line 1787 of yacc.c  */
#line 7212 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1035:
/* Line 1787 of yacc.c  */
#line 7216 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1036:
/* Line 1787 of yacc.c  */
#line 7225 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1038:
/* Line 1787 of yacc.c  */
#line 7234 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1039:
/* Line 1787 of yacc.c  */
#line 7240 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1040:
/* Line 1787 of yacc.c  */
#line 7251 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1043:
/* Line 1787 of yacc.c  */
#line 7264 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1044:
/* Line 1787 of yacc.c  */
#line 7268 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1045:
/* Line 1787 of yacc.c  */
#line 7272 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1050:
/* Line 1787 of yacc.c  */
#line 7288 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1051:
/* Line 1787 of yacc.c  */
#line 7292 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1052:
/* Line 1787 of yacc.c  */
#line 7302 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1053:
/* Line 1787 of yacc.c  */
#line 7312 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1054:
/* Line 1787 of yacc.c  */
#line 7320 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1055:
/* Line 1787 of yacc.c  */
#line 7321 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1056:
/* Line 1787 of yacc.c  */
#line 7325 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1057:
/* Line 1787 of yacc.c  */
#line 7326 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1058:
/* Line 1787 of yacc.c  */
#line 7327 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1059:
/* Line 1787 of yacc.c  */
#line 7328 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1060:
/* Line 1787 of yacc.c  */
#line 7329 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1061:
/* Line 1787 of yacc.c  */
#line 7330 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1062:
/* Line 1787 of yacc.c  */
#line 7334 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1063:
/* Line 1787 of yacc.c  */
#line 7335 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1064:
/* Line 1787 of yacc.c  */
#line 7340 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1065:
/* Line 1787 of yacc.c  */
#line 7345 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1066:
/* Line 1787 of yacc.c  */
#line 7351 "parser.y"
    { /* Nothing */ }
    break;

  case 1067:
/* Line 1787 of yacc.c  */
#line 7352 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1068:
/* Line 1787 of yacc.c  */
#line 7353 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1069:
/* Line 1787 of yacc.c  */
#line 7354 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1070:
/* Line 1787 of yacc.c  */
#line 7355 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1071:
/* Line 1787 of yacc.c  */
#line 7360 "parser.y"
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

  case 1072:
/* Line 1787 of yacc.c  */
#line 7387 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1073:
/* Line 1787 of yacc.c  */
#line 7391 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1074:
/* Line 1787 of yacc.c  */
#line 7398 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1075:
/* Line 1787 of yacc.c  */
#line 7402 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1076:
/* Line 1787 of yacc.c  */
#line 7411 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1078:
/* Line 1787 of yacc.c  */
#line 7423 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1080:
/* Line 1787 of yacc.c  */
#line 7431 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1081:
/* Line 1787 of yacc.c  */
#line 7435 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1082:
/* Line 1787 of yacc.c  */
#line 7445 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1084:
/* Line 1787 of yacc.c  */
#line 7454 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1085:
/* Line 1787 of yacc.c  */
#line 7458 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1086:
/* Line 1787 of yacc.c  */
#line 7465 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1087:
/* Line 1787 of yacc.c  */
#line 7469 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1088:
/* Line 1787 of yacc.c  */
#line 7479 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1090:
/* Line 1787 of yacc.c  */
#line 7487 "parser.y"
    {
	cb_tree l;
	cb_tree x;

	if ((yyvsp[(2) - (4)]) && (yyvsp[(4) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("%s and %s are mutually exclusive"), "SHARING", "LOCK clauses");
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

  case 1091:
/* Line 1787 of yacc.c  */
#line 7508 "parser.y"
    {
	cb_tree l;
	cb_tree x;

	if ((yyvsp[(3) - (5)]) && (yyvsp[(5) - (5)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("%s and %s are mutually exclusive"), "SHARING", "LOCK clauses");
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

  case 1092:
/* Line 1787 of yacc.c  */
#line 7531 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1093:
/* Line 1787 of yacc.c  */
#line 7532 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1094:
/* Line 1787 of yacc.c  */
#line 7533 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1095:
/* Line 1787 of yacc.c  */
#line 7534 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1096:
/* Line 1787 of yacc.c  */
#line 7538 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1097:
/* Line 1787 of yacc.c  */
#line 7539 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1098:
/* Line 1787 of yacc.c  */
#line 7543 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1099:
/* Line 1787 of yacc.c  */
#line 7544 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1100:
/* Line 1787 of yacc.c  */
#line 7545 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1101:
/* Line 1787 of yacc.c  */
#line 7547 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1102:
/* Line 1787 of yacc.c  */
#line 7558 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1104:
/* Line 1787 of yacc.c  */
#line 7569 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1105:
/* Line 1787 of yacc.c  */
#line 7574 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1106:
/* Line 1787 of yacc.c  */
#line 7580 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1107:
/* Line 1787 of yacc.c  */
#line 7585 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1108:
/* Line 1787 of yacc.c  */
#line 7593 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1109:
/* Line 1787 of yacc.c  */
#line 7601 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1110:
/* Line 1787 of yacc.c  */
#line 7608 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1111:
/* Line 1787 of yacc.c  */
#line 7612 "parser.y"
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

  case 1112:
/* Line 1787 of yacc.c  */
#line 7625 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1113:
/* Line 1787 of yacc.c  */
#line 7632 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1114:
/* Line 1787 of yacc.c  */
#line 7643 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1115:
/* Line 1787 of yacc.c  */
#line 7647 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1116:
/* Line 1787 of yacc.c  */
#line 7652 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1117:
/* Line 1787 of yacc.c  */
#line 7656 "parser.y"
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

  case 1118:
/* Line 1787 of yacc.c  */
#line 7667 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1119:
/* Line 1787 of yacc.c  */
#line 7673 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1120:
/* Line 1787 of yacc.c  */
#line 7674 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1121:
/* Line 1787 of yacc.c  */
#line 7678 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1122:
/* Line 1787 of yacc.c  */
#line 7679 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1123:
/* Line 1787 of yacc.c  */
#line 7682 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1124:
/* Line 1787 of yacc.c  */
#line 7684 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1125:
/* Line 1787 of yacc.c  */
#line 7689 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1126:
/* Line 1787 of yacc.c  */
#line 7699 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1128:
/* Line 1787 of yacc.c  */
#line 7708 "parser.y"
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

  case 1129:
/* Line 1787 of yacc.c  */
#line 7734 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1130:
/* Line 1787 of yacc.c  */
#line 7735 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1131:
/* Line 1787 of yacc.c  */
#line 7740 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1132:
/* Line 1787 of yacc.c  */
#line 7744 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1133:
/* Line 1787 of yacc.c  */
#line 7748 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1134:
/* Line 1787 of yacc.c  */
#line 7752 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1135:
/* Line 1787 of yacc.c  */
#line 7756 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1136:
/* Line 1787 of yacc.c  */
#line 7760 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1137:
/* Line 1787 of yacc.c  */
#line 7764 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1138:
/* Line 1787 of yacc.c  */
#line 7770 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1139:
/* Line 1787 of yacc.c  */
#line 7771 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1142:
/* Line 1787 of yacc.c  */
#line 7781 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1143:
/* Line 1787 of yacc.c  */
#line 7785 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1144:
/* Line 1787 of yacc.c  */
#line 7795 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1145:
/* Line 1787 of yacc.c  */
#line 7805 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1147:
/* Line 1787 of yacc.c  */
#line 7813 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1148:
/* Line 1787 of yacc.c  */
#line 7823 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1149:
/* Line 1787 of yacc.c  */
#line 7833 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1151:
/* Line 1787 of yacc.c  */
#line 7842 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1152:
/* Line 1787 of yacc.c  */
#line 7849 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1153:
/* Line 1787 of yacc.c  */
#line 7853 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1154:
/* Line 1787 of yacc.c  */
#line 7863 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1156:
/* Line 1787 of yacc.c  */
#line 7875 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1157:
/* Line 1787 of yacc.c  */
#line 7883 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1158:
/* Line 1787 of yacc.c  */
#line 7887 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1159:
/* Line 1787 of yacc.c  */
#line 7891 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1160:
/* Line 1787 of yacc.c  */
#line 7898 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1161:
/* Line 1787 of yacc.c  */
#line 7902 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1162:
/* Line 1787 of yacc.c  */
#line 7912 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1163:
/* Line 1787 of yacc.c  */
#line 7923 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1165:
/* Line 1787 of yacc.c  */
#line 7932 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1166:
/* Line 1787 of yacc.c  */
#line 7937 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1167:
/* Line 1787 of yacc.c  */
#line 7944 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1168:
/* Line 1787 of yacc.c  */
#line 7945 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1169:
/* Line 1787 of yacc.c  */
#line 7950 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1170:
/* Line 1787 of yacc.c  */
#line 7955 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1171:
/* Line 1787 of yacc.c  */
#line 7962 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1172:
/* Line 1787 of yacc.c  */
#line 7966 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1173:
/* Line 1787 of yacc.c  */
#line 7974 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1174:
/* Line 1787 of yacc.c  */
#line 7981 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1175:
/* Line 1787 of yacc.c  */
#line 7985 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1176:
/* Line 1787 of yacc.c  */
#line 7995 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1177:
/* Line 1787 of yacc.c  */
#line 8002 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1184:
/* Line 1787 of yacc.c  */
#line 8017 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1185:
/* Line 1787 of yacc.c  */
#line 8018 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1186:
/* Line 1787 of yacc.c  */
#line 8022 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1187:
/* Line 1787 of yacc.c  */
#line 8023 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1188:
/* Line 1787 of yacc.c  */
#line 8030 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1189:
/* Line 1787 of yacc.c  */
#line 8039 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1192:
/* Line 1787 of yacc.c  */
#line 8051 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1193:
/* Line 1787 of yacc.c  */
#line 8055 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1194:
/* Line 1787 of yacc.c  */
#line 8059 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1195:
/* Line 1787 of yacc.c  */
#line 8063 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1196:
/* Line 1787 of yacc.c  */
#line 8067 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1197:
/* Line 1787 of yacc.c  */
#line 8071 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1198:
/* Line 1787 of yacc.c  */
#line 8075 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1199:
/* Line 1787 of yacc.c  */
#line 8079 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1200:
/* Line 1787 of yacc.c  */
#line 8088 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1201:
/* Line 1787 of yacc.c  */
#line 8092 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1202:
/* Line 1787 of yacc.c  */
#line 8101 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1205:
/* Line 1787 of yacc.c  */
#line 8115 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1208:
/* Line 1787 of yacc.c  */
#line 8129 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1209:
/* Line 1787 of yacc.c  */
#line 8133 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1210:
/* Line 1787 of yacc.c  */
#line 8143 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1212:
/* Line 1787 of yacc.c  */
#line 8151 "parser.y"
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

  case 1213:
/* Line 1787 of yacc.c  */
#line 8172 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1214:
/* Line 1787 of yacc.c  */
#line 8181 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1215:
/* Line 1787 of yacc.c  */
#line 8186 "parser.y"
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

  case 1216:
/* Line 1787 of yacc.c  */
#line 8204 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1217:
/* Line 1787 of yacc.c  */
#line 8205 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1219:
/* Line 1787 of yacc.c  */
#line 8210 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1220:
/* Line 1787 of yacc.c  */
#line 8217 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1221:
/* Line 1787 of yacc.c  */
#line 8218 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1222:
/* Line 1787 of yacc.c  */
#line 8223 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1223:
/* Line 1787 of yacc.c  */
#line 8229 "parser.y"
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

  case 1224:
/* Line 1787 of yacc.c  */
#line 8239 "parser.y"
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

  case 1225:
/* Line 1787 of yacc.c  */
#line 8254 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1226:
/* Line 1787 of yacc.c  */
#line 8260 "parser.y"
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

  case 1227:
/* Line 1787 of yacc.c  */
#line 8270 "parser.y"
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

  case 1228:
/* Line 1787 of yacc.c  */
#line 8286 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1230:
/* Line 1787 of yacc.c  */
#line 8296 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1231:
/* Line 1787 of yacc.c  */
#line 8308 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1232:
/* Line 1787 of yacc.c  */
#line 8312 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1233:
/* Line 1787 of yacc.c  */
#line 8319 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1234:
/* Line 1787 of yacc.c  */
#line 8323 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1235:
/* Line 1787 of yacc.c  */
#line 8328 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1236:
/* Line 1787 of yacc.c  */
#line 8333 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1237:
/* Line 1787 of yacc.c  */
#line 8340 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1238:
/* Line 1787 of yacc.c  */
#line 8341 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1239:
/* Line 1787 of yacc.c  */
#line 8342 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1240:
/* Line 1787 of yacc.c  */
#line 8343 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1241:
/* Line 1787 of yacc.c  */
#line 8344 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1242:
/* Line 1787 of yacc.c  */
#line 8345 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1243:
/* Line 1787 of yacc.c  */
#line 8350 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1246:
/* Line 1787 of yacc.c  */
#line 8363 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1247:
/* Line 1787 of yacc.c  */
#line 8367 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1248:
/* Line 1787 of yacc.c  */
#line 8377 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1249:
/* Line 1787 of yacc.c  */
#line 8381 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1250:
/* Line 1787 of yacc.c  */
#line 8387 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
    break;

  case 1251:
/* Line 1787 of yacc.c  */
#line 8399 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1252:
/* Line 1787 of yacc.c  */
#line 8403 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1253:
/* Line 1787 of yacc.c  */
#line 8407 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1254:
/* Line 1787 of yacc.c  */
#line 8415 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1255:
/* Line 1787 of yacc.c  */
#line 8426 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1256:
/* Line 1787 of yacc.c  */
#line 8430 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1257:
/* Line 1787 of yacc.c  */
#line 8436 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1258:
/* Line 1787 of yacc.c  */
#line 8437 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1259:
/* Line 1787 of yacc.c  */
#line 8438 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1260:
/* Line 1787 of yacc.c  */
#line 8439 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1261:
/* Line 1787 of yacc.c  */
#line 8446 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1263:
/* Line 1787 of yacc.c  */
#line 8455 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1264:
/* Line 1787 of yacc.c  */
#line 8461 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1265:
/* Line 1787 of yacc.c  */
#line 8462 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1266:
/* Line 1787 of yacc.c  */
#line 8466 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1267:
/* Line 1787 of yacc.c  */
#line 8467 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1268:
/* Line 1787 of yacc.c  */
#line 8468 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1269:
/* Line 1787 of yacc.c  */
#line 8472 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1270:
/* Line 1787 of yacc.c  */
#line 8473 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1271:
/* Line 1787 of yacc.c  */
#line 8478 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1272:
/* Line 1787 of yacc.c  */
#line 8482 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1273:
/* Line 1787 of yacc.c  */
#line 8492 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1275:
/* Line 1787 of yacc.c  */
#line 8501 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1276:
/* Line 1787 of yacc.c  */
#line 8505 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1277:
/* Line 1787 of yacc.c  */
#line 8509 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1278:
/* Line 1787 of yacc.c  */
#line 8516 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1279:
/* Line 1787 of yacc.c  */
#line 8520 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1280:
/* Line 1787 of yacc.c  */
#line 8530 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  }
    break;

  case 1283:
/* Line 1787 of yacc.c  */
#line 8548 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1285:
/* Line 1787 of yacc.c  */
#line 8557 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1286:
/* Line 1787 of yacc.c  */
#line 8563 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1287:
/* Line 1787 of yacc.c  */
#line 8574 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1289:
/* Line 1787 of yacc.c  */
#line 8582 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1290:
/* Line 1787 of yacc.c  */
#line 8595 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1292:
/* Line 1787 of yacc.c  */
#line 8603 "parser.y"
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

  case 1296:
/* Line 1787 of yacc.c  */
#line 8626 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1298:
/* Line 1787 of yacc.c  */
#line 8636 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1299:
/* Line 1787 of yacc.c  */
#line 8642 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1300:
/* Line 1787 of yacc.c  */
#line 8644 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1301:
/* Line 1787 of yacc.c  */
#line 8648 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1302:
/* Line 1787 of yacc.c  */
#line 8650 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1303:
/* Line 1787 of yacc.c  */
#line 8655 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1304:
/* Line 1787 of yacc.c  */
#line 8661 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1305:
/* Line 1787 of yacc.c  */
#line 8663 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1306:
/* Line 1787 of yacc.c  */
#line 8668 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1307:
/* Line 1787 of yacc.c  */
#line 8674 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1308:
/* Line 1787 of yacc.c  */
#line 8675 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1309:
/* Line 1787 of yacc.c  */
#line 8679 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1310:
/* Line 1787 of yacc.c  */
#line 8680 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1311:
/* Line 1787 of yacc.c  */
#line 8684 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1312:
/* Line 1787 of yacc.c  */
#line 8685 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1313:
/* Line 1787 of yacc.c  */
#line 8690 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1314:
/* Line 1787 of yacc.c  */
#line 8694 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1315:
/* Line 1787 of yacc.c  */
#line 8704 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1322:
/* Line 1787 of yacc.c  */
#line 8722 "parser.y"
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

  case 1323:
/* Line 1787 of yacc.c  */
#line 8747 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1324:
/* Line 1787 of yacc.c  */
#line 8751 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("%s is invalid in a user FUNCTION"), "GLOBAL");
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1325:
/* Line 1787 of yacc.c  */
#line 8763 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1326:
/* Line 1787 of yacc.c  */
#line 8773 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1327:
/* Line 1787 of yacc.c  */
#line 8778 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1328:
/* Line 1787 of yacc.c  */
#line 8783 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1329:
/* Line 1787 of yacc.c  */
#line 8788 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1330:
/* Line 1787 of yacc.c  */
#line 8796 "parser.y"
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

  case 1333:
/* Line 1787 of yacc.c  */
#line 8839 "parser.y"
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
				{
					x = cb_ref((yyvsp[(1) - (1)]));
					if(CB_INVALID_TREE(x)) {
						break;
					}
					needs_field_debug = 1;
					CB_FIELD(x)->debug_section = current_section;
					CB_FIELD(x)->flag_field_debug = 1;
					CB_PURPOSE(z) = x;
					break;
				}
			default:
				break;
			}
		}
	}
  }
    break;

  case 1334:
/* Line 1787 of yacc.c  */
#line 8879 "parser.y"
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

  case 1335:
/* Line 1787 of yacc.c  */
#line 8889 "parser.y"
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

  case 1340:
/* Line 1787 of yacc.c  */
#line 8919 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("%s is invalid in nested program"), "USE AT");
	}
  }
    break;

  case 1341:
/* Line 1787 of yacc.c  */
#line 8928 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM START"));
	/* emit_entry ("_START", 0, NULL); */
	PENDING ("USE AT PROGRAM START");
  }
    break;

  case 1342:
/* Line 1787 of yacc.c  */
#line 8934 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM END"));
	/* emit_entry ("_END", 0, NULL); */
	PENDING ("USE AT PROGRAM END");
  }
    break;

  case 1343:
/* Line 1787 of yacc.c  */
#line 8944 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1344:
/* Line 1787 of yacc.c  */
#line 8953 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1347:
/* Line 1787 of yacc.c  */
#line 8969 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1349:
/* Line 1787 of yacc.c  */
#line 8981 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1350:
/* Line 1787 of yacc.c  */
#line 8990 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1351:
/* Line 1787 of yacc.c  */
#line 8991 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1352:
/* Line 1787 of yacc.c  */
#line 8996 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1353:
/* Line 1787 of yacc.c  */
#line 9000 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1354:
/* Line 1787 of yacc.c  */
#line 9004 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1355:
/* Line 1787 of yacc.c  */
#line 9008 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1356:
/* Line 1787 of yacc.c  */
#line 9014 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1357:
/* Line 1787 of yacc.c  */
#line 9015 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1360:
/* Line 1787 of yacc.c  */
#line 9025 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1361:
/* Line 1787 of yacc.c  */
#line 9029 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1364:
/* Line 1787 of yacc.c  */
#line 9046 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1366:
/* Line 1787 of yacc.c  */
#line 9056 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1369:
/* Line 1787 of yacc.c  */
#line 9069 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1371:
/* Line 1787 of yacc.c  */
#line 9079 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1374:
/* Line 1787 of yacc.c  */
#line 9094 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1376:
/* Line 1787 of yacc.c  */
#line 9104 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1379:
/* Line 1787 of yacc.c  */
#line 9121 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1381:
/* Line 1787 of yacc.c  */
#line 9132 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1387:
/* Line 1787 of yacc.c  */
#line 9155 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1388:
/* Line 1787 of yacc.c  */
#line 9164 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1392:
/* Line 1787 of yacc.c  */
#line 9181 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1393:
/* Line 1787 of yacc.c  */
#line 9190 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1396:
/* Line 1787 of yacc.c  */
#line 9207 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1398:
/* Line 1787 of yacc.c  */
#line 9217 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1399:
/* Line 1787 of yacc.c  */
#line 9227 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1400:
/* Line 1787 of yacc.c  */
#line 9231 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1401:
/* Line 1787 of yacc.c  */
#line 9241 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1402:
/* Line 1787 of yacc.c  */
#line 9248 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1403:
/* Line 1787 of yacc.c  */
#line 9254 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1404:
/* Line 1787 of yacc.c  */
#line 9258 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1408:
/* Line 1787 of yacc.c  */
#line 9271 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1409:
/* Line 1787 of yacc.c  */
#line 9279 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1410:
/* Line 1787 of yacc.c  */
#line 9280 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1411:
/* Line 1787 of yacc.c  */
#line 9282 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1412:
/* Line 1787 of yacc.c  */
#line 9283 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1413:
/* Line 1787 of yacc.c  */
#line 9284 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1414:
/* Line 1787 of yacc.c  */
#line 9285 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1415:
/* Line 1787 of yacc.c  */
#line 9286 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1416:
/* Line 1787 of yacc.c  */
#line 9288 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1417:
/* Line 1787 of yacc.c  */
#line 9289 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1418:
/* Line 1787 of yacc.c  */
#line 9290 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1419:
/* Line 1787 of yacc.c  */
#line 9291 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1420:
/* Line 1787 of yacc.c  */
#line 9292 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1421:
/* Line 1787 of yacc.c  */
#line 9293 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1422:
/* Line 1787 of yacc.c  */
#line 9295 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1423:
/* Line 1787 of yacc.c  */
#line 9296 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1424:
/* Line 1787 of yacc.c  */
#line 9297 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1425:
/* Line 1787 of yacc.c  */
#line 9299 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1426:
/* Line 1787 of yacc.c  */
#line 9300 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1427:
/* Line 1787 of yacc.c  */
#line 9301 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1428:
/* Line 1787 of yacc.c  */
#line 9302 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1429:
/* Line 1787 of yacc.c  */
#line 9303 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1430:
/* Line 1787 of yacc.c  */
#line 9306 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1431:
/* Line 1787 of yacc.c  */
#line 9307 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1440:
/* Line 1787 of yacc.c  */
#line 9337 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1441:
/* Line 1787 of yacc.c  */
#line 9341 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1445:
/* Line 1787 of yacc.c  */
#line 9352 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1446:
/* Line 1787 of yacc.c  */
#line 9353 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1447:
/* Line 1787 of yacc.c  */
#line 9354 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1448:
/* Line 1787 of yacc.c  */
#line 9358 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1449:
/* Line 1787 of yacc.c  */
#line 9359 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1450:
/* Line 1787 of yacc.c  */
#line 9360 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1451:
/* Line 1787 of yacc.c  */
#line 9365 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1452:
/* Line 1787 of yacc.c  */
#line 9368 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1453:
/* Line 1787 of yacc.c  */
#line 9372 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1454:
/* Line 1787 of yacc.c  */
#line 9373 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1455:
/* Line 1787 of yacc.c  */
#line 9374 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1456:
/* Line 1787 of yacc.c  */
#line 9377 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1457:
/* Line 1787 of yacc.c  */
#line 9378 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1458:
/* Line 1787 of yacc.c  */
#line 9389 "parser.y"
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

  case 1459:
/* Line 1787 of yacc.c  */
#line 9401 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1460:
/* Line 1787 of yacc.c  */
#line 9410 "parser.y"
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

  case 1461:
/* Line 1787 of yacc.c  */
#line 9422 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1462:
/* Line 1787 of yacc.c  */
#line 9431 "parser.y"
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

  case 1463:
/* Line 1787 of yacc.c  */
#line 9443 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1464:
/* Line 1787 of yacc.c  */
#line 9457 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1465:
/* Line 1787 of yacc.c  */
#line 9459 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1466:
/* Line 1787 of yacc.c  */
#line 9464 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1467:
/* Line 1787 of yacc.c  */
#line 9472 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1468:
/* Line 1787 of yacc.c  */
#line 9479 "parser.y"
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

  case 1469:
/* Line 1787 of yacc.c  */
#line 9499 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1470:
/* Line 1787 of yacc.c  */
#line 9503 "parser.y"
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

  case 1471:
/* Line 1787 of yacc.c  */
#line 9524 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1472:
/* Line 1787 of yacc.c  */
#line 9565 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1473:
/* Line 1787 of yacc.c  */
#line 9578 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1474:
/* Line 1787 of yacc.c  */
#line 9580 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1475:
/* Line 1787 of yacc.c  */
#line 9584 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1476:
/* Line 1787 of yacc.c  */
#line 9590 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1477:
/* Line 1787 of yacc.c  */
#line 9592 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1478:
/* Line 1787 of yacc.c  */
#line 9597 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1481:
/* Line 1787 of yacc.c  */
#line 9611 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1482:
/* Line 1787 of yacc.c  */
#line 9618 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1483:
/* Line 1787 of yacc.c  */
#line 9628 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1484:
/* Line 1787 of yacc.c  */
#line 9629 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1485:
/* Line 1787 of yacc.c  */
#line 9634 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1486:
/* Line 1787 of yacc.c  */
#line 9642 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1487:
/* Line 1787 of yacc.c  */
#line 9650 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1488:
/* Line 1787 of yacc.c  */
#line 9654 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1489:
/* Line 1787 of yacc.c  */
#line 9661 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1492:
/* Line 1787 of yacc.c  */
#line 9677 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1493:
/* Line 1787 of yacc.c  */
#line 9691 "parser.y"
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

  case 1494:
/* Line 1787 of yacc.c  */
#line 9708 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1495:
/* Line 1787 of yacc.c  */
#line 9712 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1498:
/* Line 1787 of yacc.c  */
#line 9721 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1499:
/* Line 1787 of yacc.c  */
#line 9728 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1500:
/* Line 1787 of yacc.c  */
#line 9732 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1505:
/* Line 1787 of yacc.c  */
#line 9743 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1506:
/* Line 1787 of yacc.c  */
#line 9747 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1507:
/* Line 1787 of yacc.c  */
#line 9751 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1508:
/* Line 1787 of yacc.c  */
#line 9755 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1509:
/* Line 1787 of yacc.c  */
#line 9759 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1510:
/* Line 1787 of yacc.c  */
#line 9763 "parser.y"
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

  case 1511:
/* Line 1787 of yacc.c  */
#line 9784 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1512:
/* Line 1787 of yacc.c  */
#line 9788 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1520:
/* Line 1787 of yacc.c  */
#line 9805 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1521:
/* Line 1787 of yacc.c  */
#line 9809 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1522:
/* Line 1787 of yacc.c  */
#line 9813 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1538:
/* Line 1787 of yacc.c  */
#line 9860 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1546:
/* Line 1787 of yacc.c  */
#line 9884 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1547:
/* Line 1787 of yacc.c  */
#line 9888 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1548:
/* Line 1787 of yacc.c  */
#line 9892 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1549:
/* Line 1787 of yacc.c  */
#line 9893 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1550:
/* Line 1787 of yacc.c  */
#line 9897 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1551:
/* Line 1787 of yacc.c  */
#line 9902 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1552:
/* Line 1787 of yacc.c  */
#line 9909 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1553:
/* Line 1787 of yacc.c  */
#line 9916 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1554:
/* Line 1787 of yacc.c  */
#line 9923 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1555:
/* Line 1787 of yacc.c  */
#line 9933 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1556:
/* Line 1787 of yacc.c  */
#line 9940 "parser.y"
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

  case 1557:
/* Line 1787 of yacc.c  */
#line 9950 "parser.y"
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

  case 1558:
/* Line 1787 of yacc.c  */
#line 9960 "parser.y"
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

  case 1559:
/* Line 1787 of yacc.c  */
#line 9970 "parser.y"
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

  case 1560:
/* Line 1787 of yacc.c  */
#line 9983 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1561:
/* Line 1787 of yacc.c  */
#line 9987 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1562:
/* Line 1787 of yacc.c  */
#line 9995 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1563:
/* Line 1787 of yacc.c  */
#line 10003 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1564:
/* Line 1787 of yacc.c  */
#line 10007 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1565:
/* Line 1787 of yacc.c  */
#line 10017 "parser.y"
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

  case 1566:
/* Line 1787 of yacc.c  */
#line 10032 "parser.y"
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

  case 1567:
/* Line 1787 of yacc.c  */
#line 10055 "parser.y"
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

  case 1568:
/* Line 1787 of yacc.c  */
#line 10078 "parser.y"
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

  case 1569:
/* Line 1787 of yacc.c  */
#line 10093 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1570:
/* Line 1787 of yacc.c  */
#line 10094 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1571:
/* Line 1787 of yacc.c  */
#line 10095 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1572:
/* Line 1787 of yacc.c  */
#line 10096 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1573:
/* Line 1787 of yacc.c  */
#line 10097 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1574:
/* Line 1787 of yacc.c  */
#line 10098 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1575:
/* Line 1787 of yacc.c  */
#line 10103 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1576:
/* Line 1787 of yacc.c  */
#line 10107 "parser.y"
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

  case 1577:
/* Line 1787 of yacc.c  */
#line 10124 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1578:
/* Line 1787 of yacc.c  */
#line 10128 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1579:
/* Line 1787 of yacc.c  */
#line 10134 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1580:
/* Line 1787 of yacc.c  */
#line 10135 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1581:
/* Line 1787 of yacc.c  */
#line 10136 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1582:
/* Line 1787 of yacc.c  */
#line 10137 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1583:
/* Line 1787 of yacc.c  */
#line 10138 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1584:
/* Line 1787 of yacc.c  */
#line 10139 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1585:
/* Line 1787 of yacc.c  */
#line 10140 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1586:
/* Line 1787 of yacc.c  */
#line 10147 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1587:
/* Line 1787 of yacc.c  */
#line 10151 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1588:
/* Line 1787 of yacc.c  */
#line 10155 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1589:
/* Line 1787 of yacc.c  */
#line 10159 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1590:
/* Line 1787 of yacc.c  */
#line 10163 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1591:
/* Line 1787 of yacc.c  */
#line 10167 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1592:
/* Line 1787 of yacc.c  */
#line 10171 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1593:
/* Line 1787 of yacc.c  */
#line 10175 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1594:
/* Line 1787 of yacc.c  */
#line 10179 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1595:
/* Line 1787 of yacc.c  */
#line 10183 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1604:
/* Line 1787 of yacc.c  */
#line 10207 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1605:
/* Line 1787 of yacc.c  */
#line 10211 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1606:
/* Line 1787 of yacc.c  */
#line 10215 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1607:
/* Line 1787 of yacc.c  */
#line 10222 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1608:
/* Line 1787 of yacc.c  */
#line 10226 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1609:
/* Line 1787 of yacc.c  */
#line 10230 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1610:
/* Line 1787 of yacc.c  */
#line 10237 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1611:
/* Line 1787 of yacc.c  */
#line 10244 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1612:
/* Line 1787 of yacc.c  */
#line 10251 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1613:
/* Line 1787 of yacc.c  */
#line 10261 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1614:
/* Line 1787 of yacc.c  */
#line 10268 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1615:
/* Line 1787 of yacc.c  */
#line 10278 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1616:
/* Line 1787 of yacc.c  */
#line 10285 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1617:
/* Line 1787 of yacc.c  */
#line 10296 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1618:
/* Line 1787 of yacc.c  */
#line 10304 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1619:
/* Line 1787 of yacc.c  */
#line 10305 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1620:
/* Line 1787 of yacc.c  */
#line 10309 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1621:
/* Line 1787 of yacc.c  */
#line 10310 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1622:
/* Line 1787 of yacc.c  */
#line 10314 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1623:
/* Line 1787 of yacc.c  */
#line 10315 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1624:
/* Line 1787 of yacc.c  */
#line 10320 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1625:
/* Line 1787 of yacc.c  */
#line 10324 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1626:
/* Line 1787 of yacc.c  */
#line 10331 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1627:
/* Line 1787 of yacc.c  */
#line 10335 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1628:
/* Line 1787 of yacc.c  */
#line 10342 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1629:
/* Line 1787 of yacc.c  */
#line 10343 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1630:
/* Line 1787 of yacc.c  */
#line 10344 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1631:
/* Line 1787 of yacc.c  */
#line 10348 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1632:
/* Line 1787 of yacc.c  */
#line 10349 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1633:
/* Line 1787 of yacc.c  */
#line 10353 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1634:
/* Line 1787 of yacc.c  */
#line 10354 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1635:
/* Line 1787 of yacc.c  */
#line 10355 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1636:
/* Line 1787 of yacc.c  */
#line 10360 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1637:
/* Line 1787 of yacc.c  */
#line 10364 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1638:
/* Line 1787 of yacc.c  */
#line 10376 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1639:
/* Line 1787 of yacc.c  */
#line 10381 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1640:
/* Line 1787 of yacc.c  */
#line 10389 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1641:
/* Line 1787 of yacc.c  */
#line 10393 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1642:
/* Line 1787 of yacc.c  */
#line 10397 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1643:
/* Line 1787 of yacc.c  */
#line 10401 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1644:
/* Line 1787 of yacc.c  */
#line 10405 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1645:
/* Line 1787 of yacc.c  */
#line 10409 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1646:
/* Line 1787 of yacc.c  */
#line 10413 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1647:
/* Line 1787 of yacc.c  */
#line 10417 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1648:
/* Line 1787 of yacc.c  */
#line 10423 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1649:
/* Line 1787 of yacc.c  */
#line 10424 "parser.y"
    { (yyval) = cb_int1; }
    break;


/* Line 1787 of yacc.c  */
#line 17402 "parser.c"
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


/* Line 2050 of yacc.c  */
#line 10595 "parser.y"

