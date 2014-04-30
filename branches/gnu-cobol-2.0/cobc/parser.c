/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
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



/* Line 268 of yacc.c  */
#line 768 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
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


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 1322 "parser.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7884

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  809
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1882
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2689

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
    2726,  2728,  2729,  2733,  2737,  2738,  2742,  2744,  2745,  2752,
    2756,  2759,  2761,  2762,  2764,  2765,  2769,  2775,  2776,  2779,
    2780,  2784,  2788,  2789,  2792,  2794,  2797,  2802,  2804,  2806,
    2808,  2810,  2812,  2814,  2816,  2817,  2821,  2822,  2826,  2828,
    2831,  2832,  2836,  2839,  2841,  2843,  2845,  2848,  2850,  2852,
    2854,  2855,  2859,  2862,  2868,  2870,  2873,  2876,  2879,  2881,
    2883,  2885,  2888,  2890,  2893,  2898,  2901,  2902,  2904,  2906,
    2908,  2910,  2915,  2916,  2919,  2923,  2927,  2928,  2932,  2933,
    2937,  2941,  2946,  2947,  2952,  2957,  2964,  2965,  2967,  2968,
    2972,  2977,  2983,  2985,  2987,  2989,  2991,  2992,  2996,  2997,
    3001,  3004,  3006,  3007,  3011,  3014,  3015,  3020,  3023,  3024,
    3026,  3028,  3030,  3032,  3036,  3037,  3040,  3042,  3046,  3050,
    3051,  3055,  3057,  3059,  3061,  3065,  3073,  3074,  3079,  3087,
    3088,  3091,  3092,  3095,  3098,  3102,  3106,  3110,  3113,  3114,
    3118,  3120,  3122,  3123,  3125,  3127,  3128,  3132,  3135,  3137,
    3138,  3143,  3148,  3149,  3151,  3152,  3157,  3162,  3163,  3166,
    3170,  3171,  3173,  3175,  3176,  3181,  3186,  3193,  3194,  3197,
    3198,  3201,  3203,  3206,  3210,  3211,  3213,  3214,  3218,  3220,
    3222,  3224,  3226,  3228,  3230,  3232,  3234,  3236,  3238,  3243,
    3247,  3249,  3252,  3255,  3258,  3261,  3264,  3267,  3270,  3273,
    3276,  3281,  3285,  3290,  3292,  3295,  3299,  3301,  3304,  3308,
    3312,  3313,  3317,  3318,  3326,  3327,  3333,  3334,  3337,  3338,
    3341,  3342,  3346,  3347,  3350,  3355,  3356,  3359,  3364,  3365,
    3370,  3375,  3376,  3380,  3381,  3386,  3388,  3390,  3392,  3395,
    3398,  3401,  3404,  3406,  3408,  3411,  3413,  3414,  3416,  3417,
    3422,  3425,  3426,  3429,  3434,  3439,  3440,  3442,  3444,  3446,
    3448,  3450,  3451,  3456,  3462,  3464,  3467,  3469,  3473,  3477,
    3478,  3483,  3484,  3486,  3487,  3492,  3497,  3504,  3511,  3512,
    3514,  3517,  3518,  3520,  3521,  3525,  3527,  3530,  3531,  3535,
    3541,  3542,  3546,  3549,  3550,  3552,  3554,  3555,  3560,  3567,
    3568,  3572,  3574,  3578,  3581,  3584,  3587,  3591,  3592,  3596,
    3597,  3601,  3602,  3606,  3607,  3609,  3610,  3614,  3616,  3618,
    3620,  3622,  3630,  3631,  3633,  3635,  3637,  3639,  3641,  3643,
    3648,  3650,  3653,  3655,  3658,  3662,  3663,  3665,  3668,  3670,
    3675,  3677,  3679,  3681,  3682,  3687,  3693,  3694,  3697,  3698,
    3703,  3707,  3711,  3713,  3715,  3717,  3719,  3720,  3722,  3725,
    3726,  3729,  3730,  3733,  3736,  3737,  3740,  3741,  3744,  3747,
    3748,  3751,  3752,  3755,  3758,  3759,  3762,  3763,  3766,  3769,
    3771,  3774,  3776,  3778,  3781,  3784,  3787,  3789,  3791,  3794,
    3797,  3800,  3801,  3804,  3805,  3808,  3809,  3812,  3814,  3816,
    3817,  3820,  3822,  3825,  3828,  3830,  3832,  3834,  3836,  3838,
    3840,  3842,  3844,  3846,  3848,  3850,  3852,  3854,  3856,  3858,
    3860,  3862,  3864,  3866,  3868,  3870,  3872,  3874,  3876,  3878,
    3881,  3883,  3885,  3887,  3889,  3891,  3893,  3895,  3899,  3900,
    3902,  3904,  3908,  3912,  3914,  3918,  3922,  3924,  3928,  3930,
    3933,  3936,  3938,  3942,  3944,  3946,  3950,  3952,  3956,  3958,
    3962,  3964,  3967,  3970,  3972,  3974,  3976,  3979,  3981,  3983,
    3985,  3988,  3990,  3991,  3994,  3996,  3998,  4000,  4004,  4006,
    4008,  4011,  4013,  4015,  4017,  4020,  4022,  4024,  4026,  4028,
    4030,  4032,  4035,  4037,  4039,  4043,  4045,  4048,  4050,  4052,
    4054,  4056,  4059,  4062,  4065,  4070,  4074,  4076,  4078,  4081,
    4083,  4085,  4087,  4089,  4091,  4093,  4095,  4098,  4101,  4104,
    4106,  4108,  4110,  4112,  4114,  4116,  4118,  4120,  4122,  4124,
    4126,  4128,  4130,  4132,  4134,  4136,  4138,  4140,  4142,  4144,
    4146,  4148,  4150,  4152,  4154,  4156,  4159,  4161,  4165,  4168,
    4171,  4173,  4175,  4179,  4182,  4185,  4187,  4189,  4193,  4197,
    4202,  4208,  4210,  4212,  4214,  4216,  4218,  4220,  4222,  4224,
    4226,  4228,  4230,  4233,  4235,  4239,  4241,  4243,  4245,  4247,
    4249,  4251,  4253,  4256,  4262,  4268,  4274,  4279,  4285,  4291,
    4297,  4300,  4303,  4305,  4307,  4309,  4311,  4313,  4315,  4317,
    4319,  4320,  4325,  4331,  4332,  4336,  4339,  4341,  4345,  4349,
    4351,  4355,  4357,  4361,  4362,  4363,  4365,  4366,  4368,  4369,
    4371,  4372,  4375,  4376,  4379,  4380,  4382,  4384,  4385,  4387,
    4388,  4390,  4393,  4394,  4397,  4398,  4402,  4404,  4406,  4408,
    4410,  4412,  4414,  4416,  4418,  4419,  4422,  4424,  4426,  4428,
    4430,  4432,  4434,  4436,  4438,  4440,  4442,  4444,  4446,  4448,
    4450,  4452,  4454,  4456,  4458,  4460,  4462,  4464,  4466,  4468,
    4470,  4472,  4474,  4476,  4478,  4480,  4482,  4484,  4486,  4488,
    4490,  4492,  4494,  4496,  4498,  4500,  4502,  4504,  4506,  4508,
    4510,  4512,  4514,  4516,  4518,  4520,  4522,  4524,  4526,  4528,
    4530,  4532,  4534,  4536,  4538,  4540,  4542,  4544,  4546,  4548,
    4550,  4552,  4554,  4556,  4558,  4560,  4562,  4563,  4565,  4566,
    4568,  4569,  4571,  4572,  4574,  4575,  4577,  4578,  4580,  4581,
    4583,  4584,  4586,  4587,  4589,  4590,  4592,  4593,  4595,  4596,
    4598,  4599,  4601,  4602,  4604,  4605,  4607,  4608,  4610,  4611,
    4613,  4614,  4616,  4619,  4620,  4622,  4623,  4625,  4626,  4628,
    4629,  4631,  4632,  4634,  4636,  4637,  4639,  4640,  4642,  4644,
    4645,  4647,  4649,  4650,  4653,  4656,  4657,  4659,  4660,  4662,
    4663,  4665,  4666,  4668,  4670,  4671,  4673,  4674,  4676,  4677,
    4680,  4682,  4684,  4685,  4687,  4688,  4690,  4691,  4693,  4694,
    4696,  4697,  4699,  4700,  4702,  4703,  4705,  4706,  4708,  4711,
    4712,  4714,  4715,  4717,  4718,  4720,  4721,  4723,  4724,  4726,
    4727,  4729,  4730,  4732,  4733,  4735,  4737,  4738,  4740,  4741,
    4745,  4746,  4748,  4751,  4753,  4755,  4757,  4759,  4761,  4763,
    4765,  4767,  4769,  4771,  4773,  4775,  4777,  4779,  4781,  4783,
    4785,  4787,  4789,  4791,  4793,  4796,  4799,  4801,  4803,  4805,
    4807,  4809,  4811,  4814,  4816,  4820,  4823,  4825,  4827,  4829,
    4832,  4834,  4837,  4839,  4842,  4844,  4847,  4849,  4852,  4854,
    4857,  4859,  4862
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
      -1,    -1,    26,   256,    -1,    -1,  1264,   538,  1279,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1295,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1264,  1213,  1306,    -1,  1312,
    1264,  1180,    -1,   396,  1264,  1213,    -1,  1251,    59,  1264,
     557,    -1,  1180,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1264,    96,    -1,  1213,  1264,  1184,    -1,
    1264,  1184,   574,    -1,   575,    -1,    -1,   575,    -1,  1031,
    1276,  1184,    -1,   575,  1031,  1276,  1184,    -1,    -1,    11,
    1184,   577,  1264,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1252,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1265,
     590,    -1,  1185,    -1,   589,  1185,    -1,  1214,    -1,   590,
    1214,    -1,    58,  1184,  1264,   592,    -1,   593,    -1,   592,
     593,    -1,  1216,    -1,  1216,   442,  1216,    -1,   257,  1184,
    1264,   256,    -1,    98,  1282,  1264,   256,   596,    -1,    -1,
    1295,   328,   256,    -1,   108,  1264,    68,    -1,   301,   405,
    1264,   468,   400,    -1,   100,  1264,  1179,    -1,    96,   423,
    1264,  1179,    -1,   390,  1264,  1179,    -1,   164,  1264,  1179,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1237,  1184,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1292,   614,   613,   615,    -1,    29,  1292,   614,   612,
     616,    -1,    29,  1292,   614,   119,   616,    -1,    29,  1292,
     614,   238,   616,    -1,    29,  1292,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1255,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1210,    -1,    -1,   256,    -1,  1210,    -1,     4,  1271,  1264,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1280,
    1266,  1264,   632,  1231,    -1,  1296,  1264,   504,    -1,   622,
     423,  1264,  1179,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1271,  1264,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1305,    -1,
     503,   262,   309,   274,  1305,    -1,   503,   385,    -1,   315,
    1264,   628,    -1,   628,    -1,   220,    -1,  1280,  1249,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1251,  1264,  1183,
      -1,   351,   113,  1264,   419,    -1,   351,  1266,  1264,   632,
      -1,  1179,    -1,  1179,   452,  1178,    -1,  1179,   414,  1264,
    1178,    -1,   359,  1266,  1264,  1179,    -1,   372,   635,  1246,
      -1,   287,    -1,  1213,    -1,   404,  1295,   637,    -1,     9,
    1277,    -1,   287,  1277,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1246,  1257,  1169,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1255,  1288,  1253,   645,    -1,   646,    -1,   645,   646,
      -1,  1170,   647,    -1,    -1,   331,  1213,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1170,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1264,   171,    -1,  1264,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1253,
    1213,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1253,  1213,  1252,    -1,   351,  1253,  1213,   446,  1213,  1252,
      -1,   351,  1264,   499,  1259,  1285,   661,   662,  1252,   660,
      -1,    -1,   114,  1275,  1179,    -1,    -1,  1258,  1213,    -1,
      -1,   446,  1213,    -1,   239,  1307,  1303,    -1,   498,   306,
     665,  1264,   666,    -1,   498,   306,   174,  1264,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1210,    -1,   102,  1307,
    1181,    -1,   250,  1264,  1183,  1270,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1295,   187,
    1248,  1183,    -1,   465,  1183,    -1,    48,  1183,    -1,   352,
    1271,  1264,   504,    -1,    62,  1264,   504,    -1,   677,   678,
      -1,   366,  1264,    -1,   368,  1245,    -1,  1184,    -1,   678,
    1184,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1229,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1264,   204,
      -1,  1217,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1274,   691,    -1,  1207,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1247,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1207,    -1,  1264,   171,   702,    -1,    -1,
      26,   256,    -1,  1264,   204,    -1,   327,    -1,   706,    -1,
     491,  1264,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1283,    -1,    41,   476,    -1,
      44,  1283,    -1,    44,   476,    -1,    43,  1283,    -1,    43,
     476,    -1,    42,  1283,    -1,    42,   476,    -1,    40,  1283,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1284,   241,  1241,    -1,  1284,   468,
    1241,    -1,   305,  1213,   713,  1290,   714,   711,    -1,    -1,
     425,  1213,    -1,   305,  1213,   713,  1290,   714,   715,   718,
      -1,    -1,   446,  1213,    -1,    -1,   114,  1275,  1179,    -1,
     716,    -1,    -1,   716,   717,  1266,  1264,  1178,    -1,    27,
      -1,   115,    -1,    -1,   220,  1250,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1281,    -1,   434,  1267,
      -1,    45,  1293,   510,    -1,    36,    -1,    -1,   498,  1265,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1217,
      -1,  1217,   442,  1217,    -1,    -1,  1294,   453,  1264,  1217,
      -1,   363,  1210,    -1,   363,  1210,   442,  1210,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1171,   740,   741,   451,   755,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1264,   204,
      -1,    61,  1264,  1197,    -1,   743,    -1,   746,    -1,  1320,
     744,    -1,  1256,   745,    -1,  1206,    -1,   745,  1206,    -1,
     321,  1269,   747,   748,    -1,  1215,    -1,  1215,  1304,  1215,
    1298,    -1,  1215,  1304,    -1,    -1,   748,   749,    -1,   750,
      -1,   751,    -1,   752,    -1,   753,    -1,   754,    -1,   210,
    1264,  1215,    -1,   177,  1313,  1264,  1215,    -1,   240,  1314,
    1264,  1215,    -1,   240,  1313,  1264,  1215,    -1,   187,  1264,
    1215,    -1,    -1,   755,   756,    -1,    -1,   686,   687,   757,
     758,   451,    -1,    -1,   758,   759,    -1,   760,    -1,   764,
      -1,   770,    -1,   704,    -1,   780,    -1,   709,    -1,   721,
      -1,   772,    -1,   723,    -1,   778,    -1,   765,    -1,   725,
      -1,   768,    -1,   779,    -1,   710,    -1,   769,    -1,   472,
    1264,   761,    -1,  1318,    -1,  1316,    -1,  1314,   762,    -1,
    1313,    -1,  1315,   762,    -1,  1317,    -1,  1319,    -1,    -1,
    1206,   763,    -1,   176,   763,    -1,    -1,   313,   321,    -1,
     285,   209,  1264,   775,    -1,   431,  1274,  1190,   766,    -1,
      -1,   373,  1275,   767,    -1,  1206,    -1,   176,    -1,   333,
     501,  1146,    -1,   499,  1206,   196,  1192,    49,  1192,    -1,
     771,   774,    -1,   252,  1273,  1265,    -1,   254,  1245,    -1,
     773,   776,    -1,  1297,  1273,  1265,    -1,  1298,  1245,    -1,
     775,    -1,   774,   775,    -1,   329,  1213,    -1,  1215,    -1,
     286,    -1,   777,    -1,   776,   777,    -1,   329,  1213,    -1,
    1215,    -1,   414,  1264,  1192,  1238,    -1,   209,  1261,    -1,
     491,  1264,   119,    -1,    -1,    -1,   389,   394,   451,   782,
     783,    -1,    -1,   784,    -1,   785,   451,    -1,   784,   785,
     451,    -1,   696,    -1,    -1,   686,   687,   786,   787,    -1,
     686,     1,   451,    -1,    -1,   787,   788,    -1,    45,   252,
      -1,    45,   389,    -1,    38,    -1,    46,    -1,   160,   156,
      -1,   160,   158,    -1,   211,    -1,   265,    -1,   378,    -1,
     473,    -1,   318,    -1,   243,    -1,    32,    -1,   395,    -1,
     371,    -1,   198,    -1,   345,    56,  1264,  1197,    -1,   345,
      -1,   456,    -1,   252,  1272,  1264,   791,  1199,    -1,  1297,
    1272,  1264,   792,  1199,    -1,   189,  1264,  1199,    -1,    35,
    1264,  1199,    -1,   705,    -1,   723,    -1,   794,    -1,   721,
      -1,   709,    -1,   725,    -1,   704,    -1,   793,    -1,   497,
    1206,    -1,   196,  1198,    -1,   446,  1206,    -1,   329,    -1,
     463,    -1,   270,    -1,   458,    -1,    -1,   789,    -1,   790,
      -1,    -1,   789,    -1,   790,    -1,   305,  1213,  1290,    -1,
    1264,   204,    -1,    -1,    -1,    -1,   337,   122,   799,   807,
     451,   796,   808,   797,   810,    -1,    -1,   798,   821,   451,
     810,    -1,    -1,    -1,   497,   800,   802,    -1,    -1,    55,
     801,   802,    -1,   803,    -1,   802,   803,    -1,   804,   805,
     806,   504,    -1,    -1,  1250,   357,    -1,  1250,   498,    -1,
      -1,   410,  1264,    32,    -1,   410,  1264,   110,    -1,   476,
     410,  1264,    32,    -1,   476,   410,  1264,  1213,    -1,   410,
    1264,  1213,    -1,    -1,   312,    -1,    -1,   376,   504,    -1,
      -1,    -1,   109,   451,   809,   810,   129,   109,   451,    -1,
      -1,   810,   811,    -1,   812,    -1,   815,    -1,   821,   451,
      -1,   816,    -1,   451,    -1,    -1,   504,   394,   817,   451,
     813,   814,    -1,    -1,  1102,   451,    -1,   504,   451,    -1,
     504,    -1,    -1,  1213,    -1,    -1,    -1,   819,   820,   821,
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
    1086,    -1,  1090,    -1,  1115,    -1,   285,   399,    -1,     1,
    1242,    -1,    -1,     3,   825,   826,   838,    -1,   827,   829,
     833,   834,   835,  1123,    -1,  1206,   196,   828,    -1,  1206,
     196,  1298,    -1,  1206,   196,   103,   509,    -1,  1206,   196,
     103,    -1,  1206,   196,   104,   508,    -1,  1206,   196,   104,
      -1,  1206,   196,   105,    -1,  1206,   196,   162,   237,    -1,
    1206,   196,   165,   423,    -1,  1206,   196,   443,    -1,  1206,
     196,   493,   276,    -1,  1206,   196,    69,    -1,  1206,   196,
     155,  1123,    -1,  1206,   196,   153,  1195,  1123,    -1,  1206,
     196,    24,    -1,  1206,   196,    25,  1123,    -1,  1206,   196,
    1173,    -1,  1206,   196,   504,    -1,  1206,    -1,   308,    -1,
     254,    -1,   252,   299,    -1,    -1,   830,    -1,  1248,   831,
     832,    -1,  1248,   832,   831,    -1,  1248,   831,    -1,  1248,
     832,    -1,    30,  1195,    -1,   252,  1272,  1199,    -1,  1297,
    1272,  1199,    -1,   331,  1272,  1199,    -1,    -1,   197,    -1,
      -1,   272,  1264,    47,    -1,    -1,   503,   836,    -1,   837,
      -1,   836,   837,    -1,    32,    -1,    38,    -1,    46,    -1,
      91,    -1,   198,    -1,   211,    -1,   243,    -1,   263,    -1,
     265,    -1,   288,    -1,   318,    -1,   345,    56,  1264,  1197,
      -1,   345,    -1,   371,    -1,   378,    -1,   395,    -1,   473,
      -1,   483,    -1,   489,    -1,   189,  1264,  1199,    -1,    35,
    1264,  1199,    -1,   391,   482,  1145,    -1,   391,   123,  1145,
      -1,   444,  1244,  1200,    -1,    -1,   130,    -1,    -1,     5,
     840,   841,   843,    -1,  1188,   446,  1165,  1129,    -1,  1188,
     842,   203,  1165,  1129,    -1,    94,  1206,   446,  1206,  1238,
    1129,    -1,    -1,   446,  1189,    -1,    -1,   131,    -1,    -1,
      10,   845,   846,    -1,  1206,  1232,   847,    -1,  1159,    57,
    1233,   847,    -1,    -1,   376,  1187,    -1,    -1,    18,   849,
     850,    -1,   851,    -1,   850,   851,    -1,  1175,   446,   852,
    1175,    -1,    -1,   339,   446,    -1,    -1,    51,   854,   855,
     867,    -1,   856,  1198,   857,   862,   865,   866,    -1,    -1,
     422,    -1,   424,    -1,   271,    -1,    -1,    -1,   497,   858,
     859,    -1,   860,    -1,   859,   860,    -1,   861,   308,    -1,
     861,   805,  1189,    -1,    -1,  1250,   357,    -1,  1250,    87,
      -1,  1250,   498,    -1,    -1,   863,  1263,  1206,    -1,   863,
     864,    -1,   863,     6,  1274,  1206,    -1,   376,    -1,   203,
      -1,   460,    -1,   308,    -1,    -1,  1301,   818,    -1,    -1,
     294,   818,    -1,    -1,   132,    -1,    -1,    52,   869,   870,
      -1,  1197,    -1,   870,  1197,    -1,    -1,    60,   872,   873,
      -1,  1170,   874,    -1,   873,  1170,   874,    -1,    -1,  1308,
      -1,  1308,  1257,   362,    -1,  1295,   287,   380,    -1,  1295,
     262,    -1,    -1,    74,   876,   877,   878,    -1,  1165,  1299,
    1159,  1129,    -1,    -1,   133,    -1,    71,    -1,    88,    -1,
      -1,   111,   882,   883,   885,    -1,  1170,  1280,  1142,    -1,
     454,   884,    -1,  1170,    -1,   884,  1170,    -1,    -1,   134,
      -1,    -1,   119,   887,   888,   899,    -1,  1197,   487,  1126,
      -1,  1197,   488,  1126,    -1,  1197,   485,  1126,    -1,  1197,
     486,  1126,    -1,  1188,   892,   896,  1126,    -1,   889,  1126,
      -1,  1189,   503,   897,  1126,    -1,   891,    -1,    -1,   889,
     890,   891,    -1,  1189,   830,   893,   834,   895,    -1,    -1,
     484,  1173,    -1,   484,   504,    -1,   484,   335,    -1,   484,
      96,    -1,    -1,   484,   894,    -1,    96,    -1,    97,    -1,
      -1,   503,   897,    -1,    -1,   298,    -1,   898,    -1,   897,
     898,    -1,    38,    -1,    45,   252,    -1,    45,   389,    -1,
      46,    -1,    91,    -1,   160,   156,    -1,   160,   158,    -1,
     211,    -1,   265,    -1,   318,    -1,   378,    -1,   473,    -1,
     189,  1264,  1199,    -1,    35,  1264,  1199,    -1,   391,   482,
    1145,    -1,   391,   123,  1145,    -1,    -1,   135,    -1,    -1,
     121,   901,   902,   903,    -1,  1189,   228,  1165,  1129,    -1,
    1189,   228,  1189,   203,  1165,  1129,    -1,  1189,    49,  1189,
     203,  1165,  1129,    -1,  1189,   228,  1189,   203,  1166,   361,
    1166,  1129,    -1,  1189,    49,  1189,   203,  1166,   361,  1166,
    1129,    -1,    -1,   136,    -1,    -1,   152,   905,   906,    -1,
     256,   857,    -1,    -1,   163,   908,   909,   920,    -1,   910,
     912,    -1,   911,    -1,   910,    17,   911,    -1,  1147,    -1,
     464,    -1,   453,    -1,   913,   915,    -1,   913,    -1,   914,
      -1,   913,   914,    -1,   916,   818,    -1,   501,   316,   818,
      -1,   501,   917,    -1,   916,   501,   917,    -1,   918,    -1,
     917,    17,   918,    -1,  1148,   919,    -1,    21,    -1,   464,
      -1,   453,    -1,    -1,   442,  1147,    -1,    -1,   137,    -1,
      -1,   168,   922,   923,    -1,    -1,   340,   924,    -1,   199,
      -1,   324,   101,    -1,   324,    -1,   394,    -1,   323,    -1,
      -1,   863,  1189,    -1,    -1,   195,   926,   927,    -1,  1186,
      -1,    -1,   202,   929,   930,    -1,  1210,    -1,    -1,   205,
     932,   933,    -1,  1291,  1174,   934,    -1,    -1,   114,  1275,
    1206,    -1,   206,    -1,    -1,   215,   937,  1146,  1289,   938,
     939,    -1,   818,   128,   818,    -1,   128,   818,    -1,   818,
      -1,    -1,   139,    -1,    -1,   222,   941,   942,    -1,  1186,
     943,   944,   945,   949,    -1,    -1,  1295,   175,    -1,    -1,
       9,  1291,   498,    -1,   948,  1291,   498,    -1,    -1,   365,
     946,    -1,   947,    -1,   946,   947,    -1,   948,  1254,    49,
    1189,    -1,    12,    -1,    15,    -1,   301,    -1,    16,    -1,
     302,    -1,   277,    -1,   278,    -1,    -1,  1289,  1291,   110,
      -1,    -1,   224,   951,   952,    -1,  1171,    -1,   952,  1171,
      -1,    -1,   227,   954,   955,    -1,   956,   957,    -1,  1206,
      -1,  1217,    -1,  1220,    -1,   958,   960,    -1,   958,    -1,
     960,    -1,   961,    -1,    -1,   436,   959,   962,    -1,   365,
     964,    -1,    92,  1195,   446,  1196,   968,    -1,   963,    -1,
     962,   963,    -1,  1195,   188,    -1,    57,   968,    -1,     9,
      -1,   241,    -1,   468,    -1,  1195,   968,    -1,   965,    -1,
     964,   965,    -1,    57,    49,  1195,   968,    -1,   966,   967,
      -1,    -1,     9,    -1,   241,    -1,   177,    -1,   468,    -1,
    1195,    49,  1196,   968,    -1,    -1,   968,   969,    -1,    37,
    1262,  1189,    -1,     8,  1262,  1189,    -1,    -1,   269,   971,
    1045,    -1,    -1,   273,   973,   974,    -1,  1189,   446,  1186,
      -1,    94,  1189,   446,  1186,    -1,    -1,   275,   976,   977,
     978,    -1,  1189,    49,  1165,  1129,    -1,  1189,    49,  1189,
     203,  1165,  1129,    -1,    -1,   140,    -1,    -1,   311,   980,
     981,    -1,   982,   983,  1169,   984,    -1,   981,   982,   983,
    1169,   984,    -1,   225,    -1,   317,    -1,   233,    -1,   170,
      -1,    -1,   404,  1295,   637,    -1,    -1,  1295,   287,   380,
      -1,  1295,   262,    -1,   379,    -1,    -1,   324,   986,   987,
      -1,   991,   992,    -1,    -1,   992,   988,   818,   989,    -1,
     992,   990,    -1,    -1,   141,    -1,   141,    -1,   451,    -1,
    1175,    -1,  1175,   442,  1175,    -1,    -1,  1198,   445,    -1,
     190,    -1,   993,   481,   994,    -1,   993,   499,   995,    -1,
      -1,  1295,   439,  1120,    -1,   168,    -1,  1146,    -1,   996,
      -1,   995,     8,   996,    -1,  1206,   196,  1189,    49,  1189,
     481,  1146,    -1,    -1,   349,   998,   999,  1004,    -1,  1170,
    1235,  1280,  1000,  1001,  1002,  1003,    -1,    -1,   228,  1206,
      -1,    -1,   217,   262,    -1,  1295,   262,    -1,  1295,   236,
     262,    -1,  1295,   287,   262,    -1,  1295,   216,   262,    -1,
    1295,   500,    -1,    -1,   237,  1264,  1206,    -1,  1142,    -1,
    1136,    -1,    -1,   143,    -1,   350,    -1,    -1,   360,  1007,
    1008,    -1,  1167,  1118,    -1,   374,    -1,    -1,   375,  1011,
    1012,  1013,    -1,  1170,  1280,  1000,  1135,    -1,    -1,   144,
      -1,    -1,   381,  1015,  1016,  1018,    -1,  1167,  1118,  1017,
    1142,    -1,    -1,  1295,   262,    -1,  1295,   287,   262,    -1,
      -1,   145,    -1,   385,    -1,    -1,   393,  1021,  1022,  1027,
      -1,  1168,  1023,  1024,  1025,    -1,     9,  1168,  1024,   501,
    1147,   818,    -1,    -1,   499,  1206,    -1,    -1,   129,   818,
      -1,  1026,    -1,  1026,  1025,    -1,   501,  1146,   818,    -1,
      -1,   146,    -1,    -1,   403,  1029,  1030,    -1,  1033,    -1,
    1034,    -1,  1037,    -1,  1038,    -1,  1039,    -1,  1041,    -1,
     309,    -1,   307,    -1,   482,    -1,   123,    -1,   153,  1195,
     446,  1195,    -1,  1203,    31,  1035,    -1,  1036,    -1,  1035,
    1036,    -1,    38,  1031,    -1,    46,  1031,    -1,   211,  1031,
      -1,   265,  1031,    -1,   378,  1031,    -1,   473,  1031,    -1,
     243,  1031,    -1,   318,  1031,    -1,  1186,   446,   152,  1194,
      -1,  1186,   446,  1189,    -1,  1186,  1032,    49,  1189,    -1,
    1040,    -1,  1039,  1040,    -1,  1172,   446,  1031,    -1,  1042,
      -1,  1041,  1042,    -1,  1186,   446,   464,    -1,  1186,   446,
     453,    -1,    -1,   412,  1044,  1045,    -1,    -1,  1204,  1047,
    1049,  1050,  1046,  1051,  1052,    -1,    -1,  1047,  1275,   717,
    1266,  1048,    -1,    -1,  1048,  1210,    -1,    -1,  1311,  1260,
      -1,    -1,  1296,  1264,  1179,    -1,    -1,   497,  1169,    -1,
     225,   337,  1264,   991,    -1,    -1,   203,  1169,    -1,   317,
     337,  1264,   991,    -1,    -1,   421,  1054,  1055,  1061,    -1,
    1170,  1057,  1056,  1142,    -1,    -1,  1295,  1310,  1159,    -1,
      -1,   237,  1264,  1058,  1206,    -1,   177,    -1,   240,    -1,
    1152,    -1,  1236,  1153,    -1,  1236,  1154,    -1,  1236,  1155,
      -1,  1236,  1156,    -1,  1059,    -1,  1060,    -1,   290,  1152,
      -1,   293,    -1,    -1,   147,    -1,    -1,   426,   387,  1063,
    1064,    -1,   426,  1066,    -1,    -1,   863,  1189,    -1,  1295,
     161,  1287,  1065,    -1,  1295,   289,  1287,  1065,    -1,    -1,
    1189,    -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,
      -1,   427,  1068,  1069,  1073,    -1,  1070,   228,  1206,  1072,
    1132,    -1,  1071,    -1,  1070,  1071,    -1,  1189,    -1,   112,
    1250,   410,    -1,   112,  1250,  1189,    -1,    -1,  1295,   330,
    1264,  1206,    -1,    -1,   148,    -1,    -1,   430,  1075,  1076,
    1077,    -1,  1188,   196,  1165,  1129,    -1,  1188,   196,  1189,
     203,  1165,  1129,    -1,    94,  1206,   196,  1206,  1238,  1129,
      -1,    -1,   149,    -1,   432,  1079,    -1,    -1,   336,    -1,
      -1,   438,  1081,  1082,    -1,  1171,    -1,  1082,  1171,    -1,
      -1,   469,  1084,  1085,    -1,  1206,   196,  1195,   446,  1196,
      -1,    -1,   475,  1087,  1088,    -1,  1170,  1089,    -1,    -1,
     351,    -1,   353,    -1,    -1,   480,  1091,  1092,  1101,    -1,
    1206,  1093,  1096,  1072,  1100,  1132,    -1,    -1,   112,  1250,
    1094,    -1,  1095,    -1,  1094,   313,  1095,    -1,  1230,  1195,
      -1,   228,  1097,    -1,  1096,  1097,    -1,  1206,  1098,  1099,
      -1,    -1,   113,  1259,  1206,    -1,    -1,    95,  1259,  1206,
      -1,    -1,   436,  1259,  1206,    -1,    -1,   150,    -1,    -1,
     492,  1103,  1104,    -1,  1105,    -1,  1108,    -1,  1112,    -1,
    1113,    -1,  1106,  1244,  1286,  1300,  1278,  1275,  1107,    -1,
      -1,   204,    -1,  1169,    -1,   225,    -1,   317,    -1,   233,
      -1,   170,    -1,  1257,   107,  1275,  1109,    -1,  1110,    -1,
    1109,  1110,    -1,  1176,    -1,     9,   338,    -1,     9,  1111,
    1210,    -1,    -1,   358,    -1,   358,   306,    -1,   306,    -1,
    1106,    37,   367,  1206,    -1,  1114,    -1,   166,    -1,   127,
      -1,    -1,   507,  1116,  1117,  1122,    -1,  1167,  1118,  1119,
    1017,  1121,    -1,    -1,   196,  1202,    -1,    -1,  1120,  1243,
    1199,  1268,    -1,  1120,  1243,  1173,    -1,  1120,  1243,   321,
      -1,    37,    -1,     8,    -1,  1142,    -1,  1139,    -1,    -1,
     151,    -1,  1124,  1125,    -1,    -1,   165,   818,    -1,    -1,
     294,   818,    -1,  1127,  1128,    -1,    -1,   165,   818,    -1,
      -1,   294,   818,    -1,  1130,  1131,    -1,    -1,   411,   818,
      -1,    -1,   297,   818,    -1,  1133,  1134,    -1,    -1,   461,
     818,    -1,    -1,   296,   818,    -1,  1137,  1138,    -1,  1137,
      -1,  1137,  1138,    -1,  1137,    -1,  1138,    -1,   129,   818,
      -1,   291,   818,    -1,  1140,  1141,    -1,  1140,    -1,  1141,
      -1,   157,   818,    -1,   292,   818,    -1,  1143,  1144,    -1,
      -1,   231,   818,    -1,    -1,   295,   818,    -1,    -1,  1201,
    1309,    -1,  1147,    -1,  1148,    -1,    -1,  1149,  1150,    -1,
    1151,    -1,  1150,   232,    -1,  1150,  1151,    -1,  1189,    -1,
     462,    -1,   448,    -1,   463,    -1,   458,    -1,   459,    -1,
     450,    -1,   169,    -1,  1152,    -1,  1153,    -1,  1154,    -1,
    1155,    -1,  1156,    -1,   293,    -1,   290,    -1,    20,    -1,
     313,    -1,   308,    -1,   301,    -1,    12,    -1,    13,    -1,
      14,    -1,   332,    -1,   284,    -1,   452,    -1,   159,  1291,
      -1,   455,    -1,   207,    -1,   457,    -1,   246,    -1,   208,
      -1,   247,    -1,  1159,    -1,  1157,  1158,  1159,    -1,    -1,
      70,    -1,   398,    -1,  1159,   463,  1160,    -1,  1159,   458,
    1160,    -1,  1160,    -1,  1160,   459,  1161,    -1,  1160,   450,
    1161,    -1,  1161,    -1,  1162,   169,  1161,    -1,  1162,    -1,
     463,  1163,    -1,   458,  1163,    -1,  1163,    -1,   462,  1159,
     448,    -1,  1192,    -1,   251,    -1,   251,  1302,   504,    -1,
     253,    -1,   253,  1302,   504,    -1,   322,    -1,   322,  1302,
     504,    -1,  1166,    -1,  1165,  1166,    -1,  1187,  1238,    -1,
    1210,    -1,  1210,    -1,  1170,    -1,  1169,  1170,    -1,   504,
      -1,   504,    -1,  1173,    -1,  1172,  1173,    -1,   271,    -1,
      -1,  1174,  1175,    -1,  1176,    -1,  1210,    -1,  1177,    -1,
    1177,  1302,  1177,    -1,   256,    -1,  1179,    -1,  1178,  1179,
      -1,  1210,    -1,   504,    -1,  1182,    -1,  1181,  1182,    -1,
     504,    -1,  1179,    -1,   256,    -1,   504,    -1,   504,    -1,
    1187,    -1,  1186,  1187,    -1,  1208,    -1,  1218,    -1,     6,
    1274,  1207,    -1,  1189,    -1,  1188,  1189,    -1,  1206,    -1,
    1217,    -1,  1220,    -1,  1164,    -1,   245,  1207,    -1,   245,
    1218,    -1,   245,  1220,    -1,     6,  1274,  1193,  1194,    -1,
       6,  1274,  1207,    -1,   271,    -1,  1192,    -1,  1190,  1192,
      -1,  1206,    -1,  1218,    -1,  1220,    -1,  1206,    -1,  1218,
      -1,  1220,    -1,  1164,    -1,   245,  1207,    -1,   245,  1218,
      -1,   245,  1220,    -1,   340,    -1,   152,    -1,  1207,    -1,
     256,    -1,  1206,    -1,  1218,    -1,  1206,    -1,  1217,    -1,
    1206,    -1,   256,    -1,  1206,    -1,   256,    -1,  1220,    -1,
    1203,    -1,  1213,    -1,   510,    -1,  1203,    -1,  1215,    -1,
    1203,    -1,  1213,    -1,  1206,    -1,  1217,    -1,  1220,    -1,
    1205,    -1,  1205,    -1,  1210,    -1,  1210,  1211,    -1,  1207,
      -1,  1210,  1211,  1212,    -1,  1210,  1211,    -1,  1210,  1212,
      -1,  1210,    -1,  1209,    -1,  1210,  1211,  1212,    -1,  1210,
    1211,    -1,  1210,  1212,    -1,  1210,    -1,   504,    -1,   504,
    1302,  1210,    -1,   462,  1157,   448,    -1,   462,  1159,   449,
     448,    -1,   462,  1159,   449,  1159,   448,    -1,   256,    -1,
     256,    -1,   256,    -1,   256,    -1,   416,    -1,   510,    -1,
     346,    -1,   212,    -1,   266,    -1,   460,    -1,  1218,    -1,
       9,  1219,    -1,  1219,    -1,  1218,   447,  1219,    -1,   256,
      -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,   266,
      -1,   460,    -1,  1221,  1224,    -1,  1222,   462,  1191,   448,
    1224,    -1,  1223,   462,  1157,   448,  1224,    -1,   470,   462,
    1226,   448,  1224,    -1,   303,   462,  1227,   448,    -1,   258,
     462,  1228,   448,  1224,    -1,   259,   462,  1228,   448,  1224,
      -1,   260,   462,  1228,   448,  1224,    -1,   201,  1225,    -1,
     495,  1225,    -1,    99,    -1,   502,    -1,   490,    -1,   264,
      -1,   377,    -1,    82,    -1,   428,    -1,   429,    -1,    -1,
     462,  1159,   449,   448,    -1,   462,  1159,   449,  1159,   448,
      -1,    -1,   462,  1157,   448,    -1,   462,   448,    -1,  1191,
      -1,  1191,  1158,   241,    -1,  1191,  1158,   468,    -1,  1191,
      -1,  1191,  1158,  1191,    -1,  1159,    -1,  1159,  1158,  1179,
      -1,    -1,    -1,     9,    -1,    -1,  1311,    -1,    -1,   223,
      -1,    -1,   223,  1234,    -1,    -1,   446,  1196,    -1,    -1,
     285,    -1,   334,    -1,    -1,   290,    -1,    -1,   312,    -1,
     290,   312,    -1,    -1,   386,  1239,    -1,    -1,   272,  1264,
    1240,    -1,    34,    -1,   281,    -1,   282,    -1,   283,    -1,
     344,    -1,   466,    -1,   467,    -1,   471,    -1,    -1,   400,
    1251,    -1,   451,    -1,     3,    -1,     5,    -1,    10,    -1,
      18,    -1,    51,    -1,    52,    -1,    60,    -1,    71,    -1,
      74,    -1,    88,    -1,   111,    -1,   119,    -1,   121,    -1,
     128,    -1,   152,    -1,   163,    -1,   168,    -1,   195,    -1,
     202,    -1,   205,    -1,   206,    -1,   215,    -1,   222,    -1,
     224,    -1,   227,    -1,   269,    -1,   273,    -1,   275,    -1,
     285,    -1,   311,    -1,   324,    -1,   349,    -1,   360,    -1,
     375,    -1,   381,    -1,   385,    -1,   393,    -1,   403,    -1,
     412,    -1,   421,    -1,   426,    -1,   427,    -1,   430,    -1,
     432,    -1,   438,    -1,   469,    -1,   475,    -1,   480,    -1,
     507,    -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,
     134,    -1,   135,    -1,   136,    -1,   137,    -1,   139,    -1,
     140,    -1,   141,    -1,   143,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,    -1,     7,    -1,    -1,     8,    -1,    -1,    22,
      -1,    -1,    23,    -1,    -1,    26,    -1,    -1,    30,    -1,
      -1,    39,    -1,    -1,    49,    -1,    -1,    56,    -1,    -1,
      57,    -1,    -1,    86,    -1,    -1,   102,    -1,    -1,   454,
      -1,    -1,   176,    -1,    -1,   188,    -1,    -1,   196,    -1,
      -1,   218,    -1,    -1,   314,    -1,   218,   314,    -1,    -1,
     221,    -1,    -1,   456,    -1,    -1,   228,    -1,    -1,   232,
      -1,    -1,   232,    -1,    22,    -1,    -1,   237,    -1,    -1,
     242,    -1,   384,    -1,    -1,   252,    -1,   254,    -1,    -1,
     248,  1264,    -1,   249,  1245,    -1,    -1,   254,    -1,    -1,
     272,    -1,    -1,   299,    -1,    -1,   299,    -1,   300,    -1,
      -1,   306,    -1,    -1,   309,    -1,    -1,   423,   232,    -1,
     423,    -1,   232,    -1,    -1,   316,    -1,    -1,   337,    -1,
      -1,   340,    -1,    -1,   351,    -1,    -1,   384,    -1,    -1,
     405,    -1,    -1,   406,    -1,    -1,   405,    -1,   405,   232,
      -1,    -1,   410,    -1,    -1,   418,    -1,    -1,   423,    -1,
      -1,   437,    -1,    -1,   441,    -1,    -1,   445,    -1,    -1,
     446,    -1,    -1,   446,    -1,   497,    -1,    -1,   501,    -1,
      -1,   501,   403,   446,    -1,    -1,   503,    -1,    63,   401,
      -1,   401,    -1,    66,    -1,    64,    -1,    67,    -1,    65,
      -1,   452,    -1,   159,    -1,   165,    -1,   161,    -1,   165,
      -1,   461,    -1,   218,    -1,   306,    -1,   418,    -1,   308,
      -1,   252,    -1,   254,    -1,   351,    -1,   353,    -1,    57,
      -1,   505,    -1,   351,  1264,    -1,   353,  1245,    -1,   356,
      -1,   474,    -1,   252,    -1,   254,    -1,   410,    -1,   244,
      -1,   503,   124,    -1,   124,    -1,   340,    63,   401,    -1,
      63,   401,    -1,   401,    -1,   116,    -1,   106,    -1,    89,
     210,    -1,    54,    -1,    89,   187,    -1,    53,    -1,   321,
     210,    -1,   325,    -1,   321,   187,    -1,   326,    -1,   366,
     210,    -1,   383,    -1,   366,   187,    -1,   382,    -1,    89,
    1264,    -1,    90,  1245,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1340,  1340,  1340,  1372,  1373,  1377,  1378,  1382,  1383,
    1387,  1387,  1410,  1417,  1424,  1430,  1431,  1432,  1436,  1437,
    1441,  1465,  1466,  1470,  1504,  1510,  1522,  1496,  1532,  1531,
    1569,  1604,  1605,  1609,  1610,  1613,  1614,  1618,  1627,  1636,
    1637,  1641,  1645,  1654,  1655,  1663,  1664,  1674,  1675,  1679,
    1680,  1681,  1682,  1683,  1690,  1689,  1702,  1703,  1706,  1707,
    1721,  1720,  1730,  1731,  1732,  1733,  1737,  1738,  1742,  1743,
    1744,  1745,  1749,  1756,  1763,  1770,  1781,  1785,  1789,  1793,
    1800,  1801,  1808,  1807,  1818,  1819,  1820,  1827,  1828,  1832,
    1836,  1848,  1852,  1853,  1858,  1861,  1868,  1873,  1884,  1897,
    1898,  1906,  1907,  1911,  1912,  1913,  1914,  1915,  1916,  1917,
    1918,  1919,  1920,  1921,  1922,  1930,  1929,  1948,  1958,  1971,
    1979,  1982,  1983,  1987,  1997,  2013,  2012,  2036,  2042,  2048,
    2054,  2060,  2066,  2076,  2080,  2087,  2091,  2096,  2095,  2106,
    2110,  2117,  2118,  2119,  2120,  2121,  2122,  2129,  2144,  2147,
    2154,  2162,  2166,  2177,  2197,  2205,  2216,  2217,  2223,  2244,
    2245,  2249,  2253,  2274,  2297,  2379,  2382,  2391,  2410,  2426,
    2444,  2462,  2479,  2495,  2496,  2503,  2504,  2512,  2513,  2523,
    2524,  2529,  2528,  2549,  2559,  2560,  2564,  2565,  2566,  2567,
    2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,  2576,  2583,
    2589,  2599,  2612,  2625,  2641,  2642,  2643,  2644,  2647,  2648,
    2654,  2655,  2659,  2663,  2664,  2669,  2672,  2673,  2680,  2688,
    2689,  2690,  2697,  2724,  2735,  2742,  2744,  2745,  2751,  2751,
    2758,  2763,  2768,  2775,  2776,  2777,  2781,  2792,  2793,  2797,
    2802,  2807,  2812,  2823,  2834,  2844,  2852,  2853,  2854,  2860,
    2871,  2878,  2879,  2885,  2893,  2894,  2895,  2901,  2902,  2903,
    2910,  2911,  2915,  2916,  2922,  2950,  2951,  2952,  2953,  2960,
    2959,  2975,  2976,  2980,  2983,  2984,  2990,  2991,  2999,  3000,
    3008,  3009,  3013,  3034,  3033,  3050,  3057,  3061,  3067,  3068,
    3072,  3082,  3097,  3098,  3099,  3100,  3101,  3102,  3103,  3104,
    3105,  3112,  3119,  3119,  3119,  3125,  3145,  3179,  3210,  3211,
    3218,  3219,  3223,  3224,  3231,  3242,  3247,  3258,  3259,  3263,
    3264,  3270,  3281,  3299,  3300,  3304,  3305,  3306,  3310,  3317,
    3324,  3333,  3345,  3397,  3412,  3413,  3417,  3427,  3466,  3468,
    3467,  3483,  3486,  3486,  3503,  3504,  3506,  3510,  3512,  3511,
    3546,  3559,  3567,  3572,  3578,  3587,  3597,  3600,  3612,  3613,
    3614,  3615,  3619,  3623,  3627,  3631,  3635,  3639,  3643,  3647,
    3651,  3655,  3659,  3663,  3667,  3678,  3679,  3683,  3684,  3688,
    3689,  3690,  3694,  3695,  3699,  3725,  3729,  3738,  3742,  3751,
    3752,  3753,  3754,  3755,  3756,  3757,  3758,  3759,  3760,  3761,
    3762,  3763,  3764,  3771,  3795,  3823,  3826,  3835,  3860,  3871,
    3872,  3876,  3880,  3884,  3888,  3892,  3896,  3900,  3904,  3908,
    3912,  3916,  3920,  3924,  3929,  3934,  3938,  3942,  3950,  3954,
    3958,  3966,  3970,  3974,  3978,  3982,  3986,  3990,  3994,  3998,
    4006,  4014,  4018,  4022,  4026,  4030,  4034,  4042,  4043,  4047,
    4048,  4054,  4060,  4072,  4090,  4091,  4100,  4124,  4125,  4128,
    4129,  4136,  4160,  4161,  4178,  4179,  4182,  4183,  4190,  4191,
    4196,  4207,  4218,  4229,  4240,  4269,  4268,  4277,  4278,  4282,
    4283,  4286,  4287,  4300,  4313,  4334,  4343,  4357,  4359,  4358,
    4378,  4380,  4379,  4395,  4397,  4396,  4405,  4406,  4413,  4412,
    4425,  4426,  4427,  4434,  4439,  4443,  4444,  4450,  4457,  4461,
    4462,  4468,  4505,  4509,  4514,  4520,  4521,  4526,  4527,  4528,
    4529,  4530,  4534,  4541,  4548,  4555,  4562,  4568,  4569,  4574,
    4573,  4580,  4581,  4585,  4586,  4587,  4588,  4589,  4590,  4591,
    4592,  4593,  4594,  4595,  4596,  4597,  4598,  4599,  4600,  4604,
    4611,  4612,  4613,  4614,  4615,  4616,  4617,  4620,  4621,  4622,
    4625,  4626,  4630,  4637,  4643,  4644,  4648,  4649,  4653,  4660,
    4664,  4671,  4672,  4676,  4683,  4684,  4688,  4689,  4693,  4694,
    4695,  4699,  4700,  4704,  4705,  4709,  4716,  4723,  4731,  4733,
    4732,  4753,  4754,  4758,  4759,  4764,  4766,  4765,  4822,  4840,
    4841,  4845,  4849,  4853,  4857,  4861,  4865,  4869,  4873,  4877,
    4881,  4885,  4889,  4893,  4897,  4901,  4905,  4909,  4914,  4918,
    4922,  4927,  4932,  4937,  4942,  4943,  4944,  4945,  4946,  4947,
    4948,  4949,  4950,  4957,  4962,  4971,  4972,  4976,  4977,  4982,
    4985,  4989,  4997,  5000,  5004,  5012,  5023,  5031,  5033,  5043,
    5032,  5070,  5070,  5103,  5107,  5106,  5120,  5119,  5139,  5140,
    5145,  5152,  5154,  5158,  5168,  5170,  5178,  5186,  5194,  5223,
    5254,  5256,  5266,  5271,  5298,  5300,  5299,  5335,  5336,  5340,
    5341,  5342,  5359,  5360,  5371,  5370,  5420,  5421,  5425,  5473,
    5486,  5489,  5508,  5513,  5507,  5526,  5526,  5556,  5563,  5564,
    5565,  5566,  5567,  5568,  5569,  5570,  5571,  5572,  5573,  5574,
    5575,  5576,  5577,  5578,  5579,  5580,  5581,  5582,  5583,  5584,
    5585,  5586,  5587,  5588,  5589,  5590,  5591,  5592,  5593,  5594,
    5595,  5596,  5597,  5598,  5599,  5600,  5601,  5602,  5603,  5604,
    5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,  5626,  5638,
    5637,  5646,  5652,  5656,  5660,  5665,  5670,  5675,  5680,  5684,
    5688,  5692,  5696,  5701,  5705,  5709,  5713,  5717,  5721,  5725,
    5732,  5733,  5740,  5741,  5745,  5746,  5750,  5751,  5752,  5753,
    5754,  5758,  5762,  5763,  5766,  5767,  5770,  5771,  5777,  5778,
    5782,  5783,  5787,  5791,  5795,  5799,  5803,  5807,  5811,  5815,
    5819,  5823,  5827,  5831,  5835,  5839,  5843,  5847,  5851,  5855,
    5859,  5863,  5867,  5871,  5875,  5879,  5886,  5890,  5901,  5900,
    5909,  5913,  5917,  5923,  5924,  5931,  5935,  5946,  5945,  5954,
    5958,  5970,  5971,  5979,  5978,  5987,  5988,  5992,  5998,  5998,
    6005,  6004,  6014,  6034,  6038,  6043,  6048,  6069,  6073,  6072,
    6089,  6090,  6095,  6103,  6127,  6129,  6133,  6142,  6155,  6158,
    6162,  6166,  6189,  6190,  6194,  6195,  6200,  6203,  6211,  6215,
    6223,  6227,  6238,  6237,  6245,  6249,  6260,  6259,  6267,  6272,
    6280,  6281,  6282,  6283,  6284,  6292,  6291,  6300,  6307,  6311,
    6321,  6332,  6350,  6349,  6358,  6362,  6366,  6371,  6379,  6383,
    6394,  6393,  6403,  6407,  6411,  6415,  6419,  6423,  6424,  6433,
    6435,  6434,  6442,  6451,  6458,  6462,  6466,  6470,  6480,  6482,
    6486,  6487,  6490,  6492,  6499,  6500,  6504,  6505,  6510,  6514,
    6518,  6522,  6526,  6530,  6534,  6538,  6542,  6546,  6550,  6554,
    6558,  6562,  6566,  6570,  6577,  6581,  6592,  6591,  6600,  6604,
    6608,  6612,  6616,  6623,  6627,  6638,  6637,  6645,  6665,  6664,
    6688,  6696,  6697,  6702,  6713,  6724,  6738,  6742,  6749,  6750,
    6755,  6764,  6773,  6778,  6787,  6788,  6793,  6855,  6856,  6857,
    6861,  6862,  6866,  6870,  6881,  6880,  6892,  6893,  6914,  6928,
    6950,  6972,  6992,  7015,  7016,  7024,  7023,  7031,  7042,  7041,
    7051,  7058,  7057,  7070,  7079,  7083,  7094,  7107,  7106,  7115,
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
    8715,  8719,  8746,  8749,  8761,  8771,  8776,  8781,  8786,  8794,
    8832,  8833,  8837,  8877,  8887,  8910,  8911,  8912,  8913,  8917,
    8926,  8935,  8936,  8943,  8942,  8954,  8964,  8965,  8970,  8973,
    8977,  8981,  8988,  8989,  8993,  8994,  8998,  9002,  9014,  9017,
    9018,  9027,  9028,  9037,  9040,  9041,  9050,  9051,  9062,  9065,
    9066,  9075,  9076,  9088,  9091,  9093,  9103,  9104,  9116,  9117,
    9121,  9122,  9123,  9127,  9136,  9147,  9148,  9149,  9153,  9162,
    9173,  9178,  9179,  9188,  9189,  9200,  9204,  9214,  9221,  9228,
    9228,  9238,  9239,  9240,  9244,  9253,  9254,  9256,  9257,  9258,
    9259,  9260,  9262,  9263,  9264,  9265,  9266,  9267,  9269,  9270,
    9271,  9273,  9274,  9275,  9276,  9277,  9280,  9281,  9285,  9286,
    9290,  9291,  9295,  9296,  9300,  9304,  9310,  9314,  9320,  9321,
    9322,  9326,  9327,  9328,  9332,  9333,  9334,  9338,  9342,  9346,
    9347,  9348,  9351,  9352,  9362,  9374,  9383,  9395,  9404,  9416,
    9431,  9432,  9437,  9446,  9452,  9472,  9476,  9497,  9538,  9552,
    9553,  9558,  9564,  9565,  9570,  9582,  9583,  9584,  9591,  9602,
    9603,  9607,  9615,  9623,  9627,  9634,  9643,  9644,  9650,  9664,
    9681,  9685,  9692,  9693,  9694,  9701,  9705,  9712,  9713,  9714,
    9715,  9716,  9720,  9724,  9728,  9732,  9736,  9757,  9761,  9768,
    9769,  9770,  9774,  9775,  9776,  9777,  9778,  9782,  9786,  9793,
    9794,  9798,  9799,  9803,  9804,  9808,  9809,  9820,  9821,  9825,
    9826,  9827,  9831,  9832,  9833,  9840,  9841,  9845,  9846,  9850,
    9851,  9852,  9858,  9862,  9866,  9867,  9871,  9875,  9882,  9889,
    9896,  9906,  9913,  9923,  9933,  9943,  9956,  9960,  9968,  9976,
    9980,  9990, 10005, 10028, 10051, 10067, 10068, 10069, 10070, 10071,
   10072, 10076, 10080, 10097, 10101, 10108, 10109, 10110, 10111, 10112,
   10113, 10114, 10120, 10124, 10128, 10132, 10136, 10140, 10144, 10148,
   10152, 10156, 10163, 10164, 10168, 10169, 10170, 10174, 10175, 10176,
   10180, 10184, 10188, 10195, 10199, 10203, 10210, 10217, 10224, 10234,
   10241, 10251, 10258, 10270, 10278, 10279, 10283, 10284, 10288, 10289,
   10294, 10297, 10305, 10308, 10315, 10317, 10318, 10322, 10323, 10327,
   10328, 10329, 10334, 10337, 10350, 10354, 10362, 10366, 10370, 10374,
   10378, 10382, 10386, 10390, 10397, 10398, 10404, 10405, 10406, 10407,
   10408, 10409, 10410, 10411, 10412, 10413, 10414, 10415, 10416, 10417,
   10418, 10419, 10420, 10421, 10422, 10423, 10424, 10425, 10426, 10427,
   10428, 10429, 10430, 10431, 10432, 10433, 10434, 10435, 10436, 10437,
   10438, 10439, 10440, 10441, 10442, 10443, 10444, 10445, 10446, 10447,
   10448, 10449, 10450, 10451, 10452, 10453, 10454, 10455, 10456, 10457,
   10458, 10459, 10460, 10461, 10462, 10463, 10464, 10465, 10466, 10467,
   10468, 10469, 10470, 10471, 10472, 10473, 10480, 10480, 10481, 10481,
   10482, 10482, 10483, 10483, 10484, 10484, 10485, 10485, 10486, 10486,
   10487, 10487, 10488, 10488, 10489, 10489, 10490, 10490, 10491, 10491,
   10492, 10492, 10493, 10493, 10494, 10494, 10495, 10495, 10496, 10496,
   10497, 10497, 10497, 10498, 10498, 10499, 10499, 10500, 10500, 10501,
   10501, 10502, 10502, 10502, 10503, 10503, 10504, 10504, 10504, 10505,
   10505, 10505, 10506, 10506, 10506, 10507, 10507, 10508, 10508, 10509,
   10509, 10510, 10510, 10510, 10511, 10511, 10512, 10512, 10513, 10513,
   10513, 10513, 10514, 10514, 10515, 10515, 10516, 10516, 10517, 10517,
   10518, 10518, 10519, 10519, 10520, 10520, 10521, 10521, 10521, 10522,
   10522, 10523, 10523, 10524, 10524, 10525, 10525, 10526, 10526, 10527,
   10527, 10528, 10528, 10529, 10529, 10529, 10530, 10530, 10531, 10531,
   10532, 10532, 10536, 10536, 10537, 10537, 10538, 10538, 10539, 10539,
   10540, 10540, 10541, 10541, 10542, 10542, 10543, 10543, 10544, 10544,
   10545, 10545, 10546, 10546, 10547, 10547, 10548, 10548, 10549, 10549,
   10550, 10550, 10551, 10551, 10554, 10555, 10556, 10560, 10560, 10561,
   10561, 10562, 10562, 10563, 10563, 10564, 10564, 10565, 10565, 10566,
   10566, 10567, 10567
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "control_keyword", 0
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
    1104,  1105,  1106,  1106,  1107,  1107,  1107,  1107,  1107,  1108,
    1109,  1109,  1110,  1110,  1110,  1111,  1111,  1111,  1111,  1112,
    1113,  1114,  1114,  1116,  1115,  1117,  1118,  1118,  1119,  1119,
    1119,  1119,  1120,  1120,  1121,  1121,  1122,  1122,  1123,  1124,
    1124,  1125,  1125,  1126,  1127,  1127,  1128,  1128,  1129,  1130,
    1130,  1131,  1131,  1132,  1133,  1133,  1134,  1134,  1135,  1135,
    1136,  1136,  1136,  1137,  1138,  1139,  1139,  1139,  1140,  1141,
    1142,  1143,  1143,  1144,  1144,  1145,  1145,  1146,  1147,  1149,
    1148,  1150,  1150,  1150,  1151,  1151,  1151,  1151,  1151,  1151,
    1151,  1151,  1151,  1151,  1151,  1151,  1151,  1151,  1151,  1151,
    1151,  1151,  1151,  1151,  1151,  1151,  1151,  1151,  1152,  1152,
    1153,  1153,  1154,  1154,  1155,  1156,  1157,  1157,  1158,  1158,
    1158,  1159,  1159,  1159,  1160,  1160,  1160,  1161,  1161,  1162,
    1162,  1162,  1163,  1163,  1164,  1164,  1164,  1164,  1164,  1164,
    1165,  1165,  1166,  1167,  1168,  1169,  1169,  1170,  1171,  1172,
    1172,  1173,  1174,  1174,  1175,  1176,  1176,  1176,  1177,  1178,
    1178,  1179,  1180,  1181,  1181,  1182,  1183,  1183,  1184,  1185,
    1186,  1186,  1187,  1187,  1187,  1188,  1188,  1189,  1189,  1189,
    1189,  1189,  1189,  1189,  1189,  1189,  1189,  1190,  1190,  1191,
    1191,  1191,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1193,
    1193,  1194,  1194,  1195,  1195,  1196,  1196,  1197,  1197,  1198,
    1198,  1198,  1199,  1199,  1199,  1200,  1200,  1201,  1201,  1202,
    1202,  1202,  1203,  1204,  1205,  1205,  1206,  1207,  1207,  1207,
    1207,  1208,  1209,  1209,  1209,  1209,  1210,  1210,  1211,  1212,
    1212,  1213,  1214,  1215,  1216,  1216,  1216,  1216,  1216,  1216,
    1216,  1217,  1217,  1218,  1218,  1219,  1219,  1219,  1219,  1219,
    1219,  1219,  1220,  1220,  1220,  1220,  1220,  1220,  1220,  1220,
    1220,  1220,  1221,  1221,  1222,  1222,  1222,  1223,  1223,  1223,
    1224,  1224,  1224,  1225,  1225,  1225,  1226,  1226,  1226,  1227,
    1227,  1228,  1228,  1229,  1230,  1230,  1231,  1231,  1232,  1232,
    1233,  1233,  1234,  1234,  1235,  1235,  1235,  1236,  1236,  1237,
    1237,  1237,  1238,  1238,  1239,  1239,  1240,  1240,  1240,  1240,
    1240,  1240,  1240,  1240,  1241,  1241,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1243,  1243,  1244,  1244,
    1245,  1245,  1246,  1246,  1247,  1247,  1248,  1248,  1249,  1249,
    1250,  1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,
    1255,  1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,  1259,
    1260,  1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1264,
    1264,  1265,  1265,  1265,  1266,  1266,  1267,  1267,  1267,  1268,
    1268,  1268,  1269,  1269,  1269,  1270,  1270,  1271,  1271,  1272,
    1272,  1273,  1273,  1273,  1274,  1274,  1275,  1275,  1276,  1276,
    1276,  1276,  1277,  1277,  1278,  1278,  1279,  1279,  1280,  1280,
    1281,  1281,  1282,  1282,  1283,  1283,  1284,  1284,  1284,  1285,
    1285,  1286,  1286,  1287,  1287,  1288,  1288,  1289,  1289,  1290,
    1290,  1291,  1291,  1292,  1292,  1292,  1293,  1293,  1294,  1294,
    1295,  1295,  1296,  1296,  1297,  1297,  1298,  1298,  1299,  1299,
    1300,  1300,  1301,  1301,  1302,  1302,  1303,  1303,  1304,  1304,
    1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,
    1310,  1310,  1311,  1311,  1312,  1312,  1312,  1313,  1313,  1314,
    1314,  1315,  1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,
    1319,  1320,  1320
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
       1,     0,     3,     3,     0,     3,     1,     0,     6,     3,
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
       1,     7,     0,     1,     1,     1,     1,     1,     1,     4,
       1,     2,     1,     2,     3,     0,     1,     2,     1,     4,
       1,     1,     1,     0,     4,     5,     0,     2,     0,     4,
       3,     3,     1,     1,     1,     1,     0,     1,     2,     0,
       2,     0,     2,     2,     0,     2,     0,     2,     2,     0,
       2,     0,     2,     2,     0,     2,     0,     2,     2,     1,
       2,     1,     1,     2,     2,     2,     1,     1,     2,     2,
       2,     0,     2,     0,     2,     0,     2,     1,     1,     0,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     2,
       2,     1,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     1,     1,     1,     2,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     3,     1,     1,
       2,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     2,     2,     2,     4,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     2,
       1,     1,     3,     2,     2,     1,     1,     3,     3,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     5,     4,     5,     5,     5,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     5,     0,     3,     2,     1,     3,     3,     1,
       3,     1,     3,     0,     0,     1,     0,     1,     0,     1,
       0,     2,     0,     2,     0,     1,     1,     0,     1,     0,
       1,     2,     0,     2,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     2,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     1,     0,     1,     0,     1,     1,     0,
       1,     1,     0,     2,     2,     0,     1,     0,     1,     0,
       1,     0,     1,     1,     0,     1,     0,     1,     0,     2,
       1,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     1,     0,     1,     0,     3,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     2
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
    1759,    46,     0,     0,     0,  1802,  1759,  1759,  1759,     0,
       0,     0,     0,     0,  1759,     0,     0,  1734,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1760,     0,     0,  1488,   125,  1759,
    1759,  1803,  1759,     0,     0,     0,     0,  1759,  1759,    60,
      82,     0,    54,    98,  1735,     0,  1759,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1796,    39,  1759,     0,     0,     0,  1556,   169,  1481,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1489,
     150,   151,  1761,   154,  1561,  1185,  1184,   116,   120,  1788,
    1759,     0,   100,   149,   176,   177,    38,  1797,    36,     0,
    1568,  1564,  1569,  1567,  1565,  1570,  1566,   158,   159,   161,
     170,   165,  1844,  1845,     0,   163,     0,  1733,     0,     0,
       0,  1759,  1866,    80,    61,  1732,    66,    68,    69,    70,
      71,  1732,     0,  1759,     0,    83,     0,    87,    55,    58,
     152,  1763,  1762,   155,     0,  1788,  1791,  1790,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1831,   164,     0,  1557,   168,  1865,  1759,
       0,     0,    65,    67,    63,    81,  1732,  1759,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1562,
     153,   156,     0,  1789,   123,   118,   119,   122,   178,     0,
       0,  1630,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1864,    74,    64,     0,
    1482,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1631,   181,  1740,   266,   267,   268,  1722,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1741,  1815,  1723,  1744,
       0,   278,   259,   138,   139,  1852,  1853,    72,  1798,  1816,
    1736,  1745,     0,     0,     0,   280,     0,  1777,  1798,  1823,
       0,   239,     0,  1759,  1732,  1764,   241,     0,  1833,  1830,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1728,  1759,  1737,     0,  1467,   264,  1465,   277,     0,    25,
     140,  1778,  1759,  1799,  1764,  1824,  1825,   210,  1832,   242,
    1798,  1759,  1759,  1765,  1759,  1759,   251,  1722,   252,     0,
    1759,  1777,  1729,     0,     0,   270,   271,   274,  1466,   279,
     286,   287,   338,   281,   341,     0,     0,  1759,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1792,  1792,
       0,   253,     0,  1759,   240,   223,   272,     0,   273,     0,
     487,   282,  1613,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1487,  1486,   243,   244,   245,   246,   249,  1793,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1616,   216,   201,   217,   202,  1740,
     203,   200,   213,   199,   214,  1759,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1759,  1863,     0,   222,  1617,   209,
       0,   247,  1479,     0,   231,   230,   341,   488,     0,     0,
     588,   345,   350,   387,   356,  1736,  1759,     0,     0,  1759,
    1736,  1777,  1759,  1720,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1862,   248,
    1480,     0,   236,   340,   341,   491,     0,     0,    26,  1759,
    1724,     0,     0,     0,  1759,  1720,     0,     0,     0,     0,
       0,  1759,   334,  1721,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   651,     0,   474,   411,  1804,
    1804,  1804,  1804,  1804,  1826,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1800,   446,     0,   422,   408,   423,   424,     0,
       0,  1807,   426,   427,   425,  1766,   429,   430,   428,  1759,
    1761,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1725,     0,   384,     0,   357,   312,   332,  1854,  1855,
    1485,   321,  1483,  1847,  1846,   314,  1775,  1734,  1748,     0,
    1759,   318,   317,  1759,   337,     0,  1850,  1851,   234,   492,
     496,   589,     0,    27,   695,   485,   486,  1805,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1827,     0,
    1801,   471,   457,   403,  1550,   483,  1808,  1767,  1768,   472,
       0,     0,   405,   407,  1644,  1644,   386,     0,  1784,  1579,
       0,     0,  1575,  1580,  1578,  1576,  1581,  1577,   385,   358,
    1571,  1573,     0,   302,  1484,  1776,   323,     0,   305,  1749,
    1809,   331,     0,     0,   235,   495,   591,   653,     0,     0,
     473,     0,  1819,     0,  1548,  1549,     0,   410,   475,   477,
     479,     0,   404,  1732,   451,   452,  1572,  1785,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1734,
    1810,   310,   319,   316,   320,   315,     0,   497,     0,   595,
     590,   592,     0,   656,   654,   672,     0,   749,   818,   827,
     833,   840,   872,   876,   890,   885,   891,   892,   900,   946,
     955,   958,   984,   995,   998,  1001,  1006,  1007,  1014,  1036,
    1040,  1076,  1078,  1082,     0,  1088,  1102,  1126,  1144,  1145,
    1148,  1149,  1154,  1162,  1163,  1176,  1210,  1228,     0,  1261,
    1273,  1281,  1283,   677,  1287,  1290,  1296,  1343,   697,   698,
     699,   700,   701,   702,   703,   704,   706,   705,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   696,   458,
    1820,   459,  1597,  1592,  1603,     0,  1454,  1456,     0,     0,
       0,  1595,     0,  1458,  1596,  1598,  1599,     0,     0,     0,
       0,  1594,  1603,  1593,  1438,  1436,  1443,  1446,  1448,  1451,
    1515,  1453,  1512,  1546,  1513,  1514,  1600,     0,     0,     0,
    1547,   484,   481,   478,     0,   406,  1645,   361,   374,  1574,
       0,     0,   324,   325,   326,   327,     0,   306,  1747,   312,
       0,  1468,   498,     0,   596,     0,   593,   661,   661,     0,
       0,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1661,  1662,  1663,  1664,  1665,
    1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1646,  1692,  1693,  1694,
    1695,   748,     0,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,  1399,   986,     0,     0,  1821,  1399,
       0,     0,     0,     0,     0,     0,   747,     0,  1114,     0,
       0,     0,     0,     0,     0,     0,     0,  1257,  1260,  1248,
    1258,  1259,  1250,     0,     0,  1282,  1280,     0,   695,     0,
       0,     0,     0,  1786,   462,     0,  1590,  1516,  1517,  1518,
       0,     0,     0,     0,     0,     0,     0,  1450,     0,  1449,
       0,  1591,  1439,  1440,  1558,     0,     0,     0,     0,     0,
       0,     0,     0,  1582,     0,     0,     0,     0,   476,     0,
     480,   330,   329,  1726,  1734,   311,     0,   598,   599,   594,
    1731,   661,   658,   664,     0,   661,   673,   648,   771,   816,
     774,   770,  1784,     0,     0,  1506,   825,  1500,   823,  1495,
    1497,  1498,  1499,   828,     0,  1618,  1478,   834,   835,     0,
    1474,  1476,  1475,   846,   844,   845,   870,     0,  1528,   873,
     874,  1527,   877,   880,  1784,   888,     0,  1460,  1632,  1492,
    1551,  1555,  1493,     0,   898,  1798,  1575,   944,  1364,   909,
     913,  1495,     0,  1497,   953,     0,   847,   956,   965,   964,
     982,     0,   961,   963,  1398,     0,   988,   992,   990,   993,
     991,   985,   996,   997,  1490,   999,  1000,  1822,  1002,  1472,
    1817,  1397,  1015,  1017,  1037,  1038,  1041,     0,  1043,  1044,
    1045,  1077,  1214,  1543,  1544,     0,  1079,     0,  1086,     0,
    1095,  1092,  1094,  1093,  1089,  1096,  1116,  1478,  1103,  1114,
    1105,     0,  1112,     0,  1529,  1475,  1531,     0,  1142,  1624,
    1146,  1346,  1463,  1152,  1798,  1160,  1346,     0,  1174,  1167,
    1464,     0,  1471,  1177,  1178,  1179,  1180,  1181,  1182,  1203,
    1183,  1206,     0,  1469,     0,     0,  1542,  1555,  1211,  1246,
    1233,  1251,  1730,  1271,     0,  1264,  1266,     0,  1278,     0,
    1284,  1285,   683,   689,   678,   679,   680,   682,     0,  1288,
       0,  1291,  1293,  1313,  1299,  1356,  1346,  1787,     0,   466,
     461,  1605,  1438,  1436,  1455,  1457,  1438,     0,     0,     0,
    1438,  1509,  1510,  1511,     0,  1459,  1452,  1438,     0,  1437,
    1559,     0,  1442,  1441,  1445,  1444,  1447,     0,     0,  1438,
       0,  1759,  1727,     0,   308,     0,  1759,  1806,   659,  1759,
       0,   670,   662,   663,   674,   817,   750,  1727,   784,   775,
       0,     0,     0,     0,  1501,  1502,  1503,   826,   819,     0,
       0,  1496,  1620,  1619,   831,   836,   838,     0,   871,   841,
    1530,   847,   875,   880,  1856,  1857,   878,     0,   881,     0,
     889,   886,  1839,  1838,  1461,     0,  1634,  1462,  1553,  1554,
     895,   896,   899,   893,  1391,   945,   901,   692,     0,   907,
    1366,     0,   924,     0,   918,  1364,  1364,  1364,  1364,   954,
     947,     0,     0,   848,   957,   983,   959,  1399,  1399,   960,
     967,   968,   692,  1423,  1424,  1425,  1419,  1821,  1411,  1431,
    1434,  1433,  1435,  1427,  1418,  1417,  1422,  1421,  1420,  1426,
    1406,  1410,  1428,  1430,  1432,  1408,  1409,  1405,  1407,  1400,
    1401,  1412,  1413,  1414,  1415,  1416,  1404,   989,   863,   862,
       0,   987,  1491,  1004,  1818,   692,  1019,     0,  1039,     0,
    1066,  1050,  1042,  1047,  1048,  1049,  1218,     0,  1545,     0,
       0,  1087,  1083,     0,  1096,  1830,     0,  1104,  1110,  1111,
     692,  1107,  1399,     0,     0,  1115,     0,  1143,  1127,  1625,
    1626,  1798,     0,  1147,  1153,  1150,  1129,  1161,  1155,  1157,
    1169,  1175,  1164,     0,  1169,     0,  1523,  1524,  1204,  1207,
       0,     0,  1470,  1187,     0,  1186,     0,     0,  1553,  1247,
    1229,  1235,  1759,  1236,  1231,     0,  1249,     0,     0,  1272,
    1262,     0,  1265,     0,  1279,  1274,     0,  1286,   690,   688,
     681,     0,  1294,  1295,  1292,  1314,  1297,  1730,     0,  1357,
    1344,  1348,   460,  1730,   456,   464,   465,  1764,  1604,     0,
    1600,  1600,  1600,     0,  1586,     0,  1600,  1560,     0,  1600,
    1600,  1829,     0,   328,  1786,   307,   502,  1759,  1759,  1720,
    1772,   527,   501,   505,   506,     0,  1742,   613,  1759,   603,
    1826,   604,  1835,  1834,     0,  1759,     0,   616,   607,   612,
    1779,   608,     0,   611,   618,   615,   609,   614,     0,   619,
     610,     0,   630,   624,   628,   627,   625,   629,   600,   631,
     626,     0,  1779,     0,  1759,   671,     0,     0,   649,   780,
     785,   786,  1779,  1779,   778,   779,  1779,   766,  1359,  1837,
    1836,   763,   755,   757,   758,     0,  1359,     0,     0,     0,
     772,   761,     0,   769,   752,   768,   753,  1520,  1519,     0,
    1505,     0,  1784,  1369,   824,  1555,  1493,     0,  1622,   831,
       0,   829,     0,     0,  1477,   858,   879,   884,     0,     0,
    1494,  1369,  1759,  1633,  1552,   897,   692,   894,  1393,  1365,
     693,   911,  1726,   692,  1363,   917,   916,   915,   914,   925,
    1364,  1759,   928,     0,   931,   932,     0,  1759,   935,   936,
     937,   938,     0,   939,  1364,   926,     0,   786,   904,   905,
     902,   903,     0,  1369,     0,   854,   962,   977,   979,   978,
     972,   974,   980,  1399,   969,   966,  1399,   970,  1429,  1402,
    1403,   994,  1786,  1003,  1473,   692,  1011,  1012,  1821,  1027,
    1028,  1030,  1032,  1033,  1029,  1031,  1022,  1821,  1018,     0,
    1067,     0,  1069,  1068,  1070,  1052,  1062,     0,     0,  1046,
    1220,     0,  1750,     0,  1080,  1369,     0,     0,     0,  1098,
    1108,  1121,  1117,  1122,  1118,  1123,     0,  1113,  1353,  1352,
    1120,  1129,  1347,  1539,  1540,  1541,     0,     0,  1391,     0,
     692,     0,  1168,     0,     0,     0,  1205,     0,  1209,  1208,
    1201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1189,  1190,  1627,  1391,     0,  1252,  1813,  1813,  1267,  1268,
    1269,     0,  1369,     0,     0,   691,     0,  1614,     0,  1269,
    1157,  1716,     0,  1759,  1612,  1587,  1588,  1589,  1610,  1607,
    1608,  1585,  1601,     0,  1583,  1584,   482,     0,     0,  1881,
    1882,  1759,  1720,     0,   499,   503,  1743,   507,     0,     0,
     601,   602,   605,   606,     0,   633,  1780,  1759,  1819,  1759,
     634,   632,   646,  1759,   665,   666,   669,     0,   660,   675,
     677,  1759,   788,     0,     0,   776,   777,     0,   692,   767,
    1361,   754,   756,  1359,   764,   759,   760,   773,   762,  1522,
    1504,  1521,  1632,     0,   692,   820,  1371,  1553,  1554,  1369,
       0,  1621,   830,   832,   839,   837,   866,  1757,   883,   882,
     887,     0,  1392,   692,  1390,   695,  1367,   906,     0,   929,
     930,   933,   934,     0,  1395,  1395,   927,   908,   920,   921,
     919,   922,     0,   948,     0,   849,   850,   664,     0,  1399,
    1399,   976,   692,   973,     0,  1010,   692,  1013,  1008,     0,
       0,  1034,     0,     0,     0,  1063,  1065,     0,  1058,  1072,
    1059,  1060,  1051,  1054,  1072,  1212,  1759,  1764,     0,  1751,
    1219,  1081,  1084,     0,  1098,  1097,  1101,  1090,     0,  1109,
    1106,     0,     0,  1131,  1130,   692,  1151,  1379,  1156,  1158,
       0,  1170,  1399,  1399,  1165,  1171,  1188,  1200,  1202,  1192,
    1193,  1194,  1198,  1195,  1199,  1196,  1197,  1191,  1628,  1245,
       0,  1242,  1243,  1237,     0,  1230,  1861,  1860,     0,  1814,
    1255,  1255,  1374,     0,  1632,  1275,     0,   684,     0,  1615,
    1300,  1301,     0,  1304,  1307,  1311,  1305,  1391,  1717,     0,
     470,   467,   468,     0,  1602,   309,   504,  1773,  1774,  1563,
     515,   512,   352,   528,   508,   509,  1534,   623,  1532,  1533,
     622,   639,   645,     0,   642,   667,   668,   677,   695,     0,
       0,  1359,   781,   783,   782,  1360,   692,  1358,   765,  1369,
    1494,  1370,   692,  1368,  1552,   821,  1623,  1525,  1526,  1842,
    1843,   868,   692,  1784,  1758,   865,   864,   860,     0,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1643,  1635,  1394,     0,
     941,   940,   943,     0,  1537,  1538,   942,     0,   912,  1369,
    1460,  1369,  1460,   851,   852,     0,   856,   855,   857,   975,
     981,   971,  1005,  1009,  1020,  1023,  1024,  1738,  1016,  1821,
    1021,  1072,  1072,     0,  1057,  1055,  1056,  1061,  1222,     0,
    1216,  1752,  1369,  1091,  1100,     0,  1124,     0,     0,  1138,
       0,  1383,   692,  1378,  1159,   692,   692,  1172,  1244,  1234,
    1238,  1239,  1240,  1241,  1232,  1253,  1256,  1254,   692,  1263,
    1376,  1759,  1369,  1369,   686,  1289,  1614,  1303,  1748,  1309,
    1748,  1374,   692,   692,  1345,  1355,  1386,  1387,  1354,  1351,
    1350,  1769,   469,   463,   511,  1848,  1849,   514,   354,   529,
     510,   637,   635,   638,   636,   640,   641,     0,   617,   643,
     644,     0,   695,   787,   792,  1759,   793,   794,   795,  1759,
     796,   797,   798,   799,   800,   801,   802,   804,   805,   806,
       0,   807,  1718,   808,   809,   810,   789,   790,   751,  1362,
     822,  1372,   692,   842,   867,     0,   859,  1858,  1859,  1396,
     923,   950,     0,   949,     0,   853,  1025,  1739,     0,     0,
    1053,  1064,  1072,  1755,  1755,  1073,     0,     0,  1225,  1221,
    1215,  1085,  1099,     0,  1132,  1759,  1391,     0,     0,  1133,
       0,  1137,  1384,  1166,  1173,  1375,   692,  1373,     0,  1277,
    1276,  1315,   685,     0,  1302,     0,  1748,  1306,     0,  1298,
    1388,  1389,  1385,  1770,  1771,  1349,     0,  1759,  1759,     0,
     516,   517,   518,   519,   520,   521,     0,   531,   620,   621,
       0,     0,     0,  1759,  1395,  1395,  1719,     0,   791,   869,
     861,  1369,  1369,     0,  1035,  1071,  1756,     0,     0,  1759,
    1223,     0,     0,  1213,  1217,     0,     0,  1128,  1141,  1381,
    1382,  1140,  1136,  1134,  1135,  1377,  1270,  1322,   687,  1308,
       0,  1312,  1868,  1867,  1759,     0,     0,  1870,     0,  1759,
    1759,   513,  1806,     0,   812,   811,     0,   814,   813,   815,
    1535,  1536,   952,   951,  1026,  1075,  1074,     0,  1226,  1759,
    1399,  1139,  1380,  1342,  1341,  1323,  1316,  1317,  1718,  1318,
    1319,  1320,  1340,     0,  1310,     0,   526,   522,  1869,     0,
       0,  1753,  1781,  1720,     0,     0,     0,  1759,  1784,   530,
    1759,  1759,     0,   536,   538,   547,   539,   541,   544,   532,
     533,   534,   543,   545,   548,   535,     0,   540,     0,   542,
     546,   537,  1781,  1720,   676,   803,  1224,     0,  1125,     0,
    1811,  1786,   523,   525,   524,  1754,   586,  1782,  1783,  1761,
     572,  1759,   457,  1399,     0,     0,     0,     0,     0,   580,
       0,   570,   576,   579,     0,   573,   581,   584,  1761,   575,
    1227,     0,  1812,     0,     0,   571,     0,  1819,   568,  1632,
     564,  1507,  1872,     0,     0,  1874,  1876,     0,  1880,  1878,
     549,   553,   557,   557,   551,   555,   550,   556,   587,     0,
     578,   577,   583,   582,   574,  1339,  1841,  1840,  1794,  1335,
    1329,  1330,  1332,   562,   459,   585,  1786,   563,  1508,  1871,
    1875,  1873,  1879,  1877,   560,   552,   560,   554,     0,  1795,
    1786,  1338,  1333,  1336,     0,  1331,   454,     0,     0,   559,
     558,     0,     0,  1337,  1334,     0,   453,   567,   565,   566,
     561,   569,  1328,  1325,  1327,  1326,  1321,  1324,   455
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
     434,   503,   435,   534,   566,   567,   827,   568,  1665,  1009,
     763,   569,   570,   703,   833,   571,   572,   828,  1002,  1003,
    1004,  1005,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   758,   814,
     815,   816,   817,   818,   500,   683,   589,   661,   662,   663,
     792,   664,   665,   666,   667,   668,   669,   670,  2545,  2676,
     671,   782,  1144,  1379,  1380,  1647,  1644,  2151,  2152,   672,
     673,   674,   675,   676,   992,   788,   789,  1178,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1186,  1416,
    1672,  1673,  1957,  2164,  1674,  2160,  2314,  2430,  2431,  2432,
    2433,  2434,  2435,  1954,  2163,  2437,  2492,  2549,  2550,  2620,
    2655,  2669,  2551,  2552,  2647,  2678,  2553,  2554,  2555,  2556,
    2557,  2558,  2591,  2592,  2595,  2596,  2559,  2560,  2561,   588,
     776,   840,   841,   842,  1188,  1417,  1708,  2325,  2326,  2327,
    2331,  1709,  1710,   713,  1424,  1980,   714,   845,  1018,  1017,
    1191,  1192,  1193,  1421,  1716,  1020,  1718,  2177,  1138,  1364,
    1365,  2294,  2412,  1366,  1367,  1924,  1779,  1780,  2025,  1368,
     779,   898,   899,  1092,  1199,  1200,  1744,  1428,  1484,  1724,
    1725,  1721,  1982,  2181,  2356,  2357,  1426,   900,  1093,  1206,
    1440,  1438,   901,  1094,  1213,  1761,   902,  1095,  1217,  1218,
    1763,   903,  1096,  1226,  1227,  1494,  1815,  2045,  2046,  2047,
    2016,  1540,  2207,  2201,  2363,  1449,   904,  1097,  1229,   905,
    1098,  1232,  1456,   906,  1099,  1235,  1461,   907,   908,   909,
    1100,  1244,  1470,  1473,   910,  1101,  1247,  1248,  1478,  1249,
    1482,  1807,  2040,  2228,  1790,  1804,  1805,  1476,   911,  1102,
    1254,  1490,   912,  1103,  1257,   913,  1104,  1260,  1261,  1262,
    1499,  1500,  1501,  1825,  1502,  1820,  1821,  2051,  1496,   914,
    1105,  1271,  1541,   915,  1106,  1272,   916,  1107,  1275,   917,
    1108,  1278,  1833,   918,   919,  1109,  1837,  2058,   920,  1110,
    1282,  1546,  1846,  2061,  2245,  2246,  2247,  2248,   921,  1111,
    1284,   922,  1112,  1286,  1287,  1552,  1553,  1858,  1554,  1555,
    2072,  2073,  1855,  1856,  1857,  2066,  2254,  2385,   923,  1113,
     924,  1114,  1296,   925,  1115,  1298,  1562,   926,  1117,  1304,
    1305,  1566,  2087,   927,  1118,  1308,  1570,  2090,  1571,  1309,
    1310,  1311,  1872,  1874,  1875,   928,  1119,  1318,  1887,  2269,
    2396,  2467,  1578,   929,   930,  1120,  1320,   931,   932,  1121,
    1323,  1585,   933,  1122,  1325,  1888,  1588,   934,   935,  1123,
    1328,  1594,  1891,  2104,  2105,  1592,   936,  1124,  1333,   159,
    1606,  1334,  1335,  1910,  1911,  1336,  1337,  1338,  1339,  1340,
    1341,   937,  1125,  1291,  2258,  1556,  2390,  1860,  2075,  2388,
    2463,   938,  1126,  1349,  1913,  1614,  2120,  2121,  2122,  1610,
     939,  1351,  1616,  2285,  1132,   940,  1133,  1353,  1354,  1355,
    2132,  1620,   941,  1134,  1358,  1625,   942,  1136,   943,  1137,
    1360,   944,  1139,  1369,   945,  1140,  1371,  1634,   946,  1141,
    1373,  1638,  2140,  2141,  1929,  2143,  2299,  2417,  2301,  1636,
    2413,  2477,  2516,  2517,  2518,  2686,  2519,  2640,  2641,  2664,
    2520,  2521,  2522,   947,  1142,  1375,  1583,  1930,  1880,  2304,
    1640,  1989,  1990,  2187,  1479,  1480,  1784,  2005,  2006,  2193,
    2289,  2290,  2407,  2096,  2468,  2097,  2273,  2305,  2306,  2307,
    1777,  1778,  2024,  2222,  1280,  1281,  1264,  1265,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,   974,  1165,  1383,   976,   977,
     978,   979,  1207,  1236,  1464,  1321,  1329,   395,   396,  1012,
    1342,  1343,  1543,  1312,  1220,  1221,   541,   481,   301,   691,
     692,   482,    98,   153,  1273,  1238,  1208,  1441,  2610,  1390,
     981,  1749,  2000,  2074,  2196,  1230,  1313,  2167,  2499,  2223,
    1882,  2168,  1292,  1346,  1210,   983,  1239,  1240,   734,   784,
     785,  2169,   271,  2593,   179,  1211,   760,   761,  1212,   986,
     987,   988,  1173,  1146,  1398,  1394,  1387,   501,  2142,   537,
    1444,  1759,  2011,  1581,  2124,   282,  1467,  1773,  2217,   794,
    1091,  2149,  2447,   604,   339,   684,  1430,   423,  1194,   202,
     115,   393,  2378,   337,  1958,   352,  1010,   770,  2080,  2576,
    2457,  2208,    96,   214,   414,   739,  2425,  1953,   766,   402,
    1967,  2579,   798,  1378,   218,   488,  2660,   168,   390,   731,
     102,   719,   680,   831,  2603,  2130,   350,  1545,   951,  1279,
     407,   729,  1179,  1317,   391,  1726,  1746,  1465,  2638,  2202,
     184,   695,  2317,   708,   347,   596,  1458,  2369,  2128,   538,
     203,  2484,  2490,  2623,  2624,  2625,  2626,  2627,  1676
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2382
static const yytype_int16 yypact[] =
{
   -2382,   238,   614, -2382,  -199,   226, -2382,   614, -2382, -2382,
     626, -2382, -2382,   626,   626,   485,   485, -2382,   595, -2382,
     729,   482,   836, -2382, -2382,   864,   864,   560,   762, -2382,
   -2382,     3,   626,   485, -2382, -2382,   844,   636, -2382, -2382,
     782,  1223,   485, -2382, -2382, -2382,   482,   823, -2382, -2382,
     -70, -2382,   749,   749,   824,   872,  1055,  1055,  1055,   938,
     749,   908,   923,   934,  1055,   937,   980,  1344, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382,  1193, -2382, -2382, -2382, -2382,
    1200, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    1264,   994,     3, -2382, -2382,  1012,   321, -2382, -2382,  1055,
    1055, -2382,  1055,   968,  1401,   968,  1032,  1055,  1055, -2382,
   -2382,   968, -2382, -2382, -2382,   985,   -20,  1051, -2382, -2382,
    1001, -2382,  1080, -2382, -2382, -2382, -2382,  -171, -2382, -2382,
   -2382,  1197, -2382,  1055,   575,   968,  1285,   -37, -2382, -2382,
   -2382, -2382, -2382,  1288,  1092,   719,  1391, -2382,  1087, -2382,
     985, -2382,    39, -2382, -2382, -2382, -2382, -2382,  1189,   -40,
    1055,    13, -2382, -2382, -2382,   465, -2382, -2382, -2382,   802,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,   575, -2382,  1167,
   -2382,  -182, -2382, -2382,   968, -2382,  1202, -2382,  1216,  1211,
    1559,  1055, -2382, -2382, -2382,  1111, -2382, -2382, -2382, -2382,
   -2382,   580,  1566,  1055,    59, -2382,    74, -2382, -2382,   -18,
   -2382, -2382, -2382, -2382,  1375,   -40, -2382,  1402,   749,   749,
   -2382,  1189,  1182,    56,   -83, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   653, -2382,
      60, -2382,   575, -2382, -2382,  1308, -2382, -2382, -2382,  1055,
    1236,  1383, -2382, -2382, -2382, -2382,  1144,  1055,  1137,  1416,
     586, -2382,  1620,   667,  1196, -2382, -2382,  1198,  1545, -2382,
    1375, -2382,   749, -2382, -2382, -2382, -2382,  1189, -2382,  1207,
    1347, -2382,   749, -2382,   858, -2382,   130, -2382, -2382, -2382,
   -2382, -2382,   653, -2382,  1408,  1383, -2382, -2382, -2382,   401,
   -2382, -2382, -2382,  1412, -2382, -2382, -2382, -2382, -2382,  1397,
   -2382, -2382, -2382, -2382, -2382,  1219, -2382, -2382, -2382,  1647,
    1572,  1224, -2382, -2382,   653, -2382, -2382,    84, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1240, -2382,  1488,
    1556,  1226, -2382,  1664, -2382, -2382, -2382, -2382,  2213, -2382,
    1596, -2382,  1181,  1235,  1293, -2382,   653,  1421,  1337,  -222,
    1294, -2382,  1292,  1055,  1640,    89,   -88,   -31, -2382,  1195,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1277,
   -2382,  1439, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    1665,  1055, -2382,  1181, -2382,  1181, -2382, -2382,  1252,   -59,
   -2382, -2382,  1055, -2382,  1468, -2382, -2382,    96, -2382, -2382,
     993,  1055,  1055, -2382,  1055,  1055, -2382,  1647, -2382,   116,
    1055,  1421, -2382,  1304,  1203,  1181, -2382,  1378, -2382, -2382,
   -2382, -2382,  1205, -2382,  1208,    65,   603,  1055, -2382, -2382,
    1280, -2382, -2382,   396,  1295,   968,   968, -2382,  1400,  1400,
    1409, -2382,   968,  1055, -2382, -2382, -2382,  1383, -2382,  1324,
    1460, -2382, -2382,  1271, -2382, -2382, -2382, -2382, -2382,   968,
   -2382, -2382,   403,   403,  1716,   403, -2382, -2382,   403,   437,
   -2382, -2382, -2382, -2382, -2382,   765, -2382, -2382, -2382, -2382,
   -2382, -2382,   602, -2382,  1273,  1332,  1473,   467,  1278,  6091,
   -2382,  1228, -2382, -2382,   -24, -2382, -2382, -2382, -2382,  1219,
   -2382, -2382, -2382, -2382, -2382,  1055,   968,  1230, -2382,  1230,
   -2382, -2382,  1283,  1341,  1370, -2382,  1287, -2382,  1289, -2382,
    1657, -2382,  1658, -2382,  1096, -2382,  1623, -2382, -2382, -2382,
     968,   968, -2382,   612, -2382, -2382,  1208, -2382,  1298,  1350,
    1363, -2382, -2382, -2382,  1036,  1596,  1055,  1148,  1148,  1055,
      17,  1421,  1055,  1732, -2382,  1449, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382,   749,   531, -2382,   968,
   -2382,  1447, -2382, -2382,  1208, -2382,  1307,  1369, -2382,  6399,
     706,  1563,  1383,  1266,  1055,  1732,  1268,   406,   396,  1383,
    1269,  1055, -2382, -2382, -2382,   -38,   749, -2382, -2382, -2382,
     891, -2382,  1208, -2382,  1318,   123,   660, -2382, -2382,  -184,
     578,   716,   743,   753,  1276, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382,  1394, -2382,  1383, -2382, -2382, -2382, -2382,   968,
     968,  1547, -2382, -2382, -2382,   -69, -2382, -2382, -2382,  1055,
     135, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   682,
     -77, -2382,  1279, -2382,   518, -2382,  1336, -2382, -2382, -2382,
   -2382,  1268, -2382, -2382, -2382, -2382,  1526,   200,  1568,  1286,
    1055, -2382, -2382,  1055, -2382,  1177, -2382, -2382, -2382, -2382,
   -2382, -2382,  1659, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1274,
   -2382, -2382,  1354, -2382,  1325,  1359, -2382, -2382, -2382, -2382,
    6566,   535,  1776, -2382,  1403,  1403, -2382,   687,  1498, -2382,
    1242,  1242, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    1358, -2382,  1383,    69, -2382, -2382, -2382,  1383, -2382, -2382,
    1396, -2382,   440,   440, -2382,  1459,  1305,    82,  2397,  3717,
   -2382,  1383,  1366,  7081,  1346, -2382,   968, -2382,   535, -2382,
    1368,  1561, -2382,  1640, -2382, -2382, -2382, -2382,  1242,  1361,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382,   687, -2382, -2382, -2382, -2382,   129,  1344,
   -2382,   679, -2382, -2382, -2382, -2382,  1314, -2382,  5909, -2382,
   -2382,  1305,  1371, -2382, -2382,  1444,  4101, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382,  1422, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  -109, -2382,
   -2382,  1487, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382,  1710, -2382, -2382,  1364,  7374,   -37,   -37,  1367,  1372,
    1374, -2382,  1377,   -37, -2382, -2382, -2382,  7097,  7081,  7097,
    1379, -2382,  1364, -2382,   240,   981,   982, -2382,  1656, -2382,
   -2382, -2382, -2382, -2382,  1358, -2382,  1380,  1381,  1384,  7081,
   -2382, -2382,   499, -2382,   535, -2382, -2382, -2382, -2382, -2382,
     396,   396, -2382, -2382, -2382, -2382,  1641, -2382, -2382,  1336,
    1383, -2382, -2382,  1376, -2382,  1386, -2382,   110,   110,  1327,
    1407, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382,   -79,  4015,  7081,   537,   620,   547,  1181,   681,
     710,  5307,  5427,  1589,  -220,   831,   681,   968,  1405, -2382,
     681,  1314,  3591,   968,  4638,  5427, -2382,   911,  2734,  1181,
     968,  1181,   968,    67,   378,   968,  1181, -2382, -2382, -2382,
   -2382, -2382, -2382,  3033,  4722, -2382, -2382,  1314,   313,   968,
    1181,   968,   968,  1539, -2382,  6704, -2382, -2382,  1358, -2382,
    1343,  1348,  7081,  7081,  7081,  7374,  1349, -2382,   913, -2382,
    7374, -2382, -2382, -2382, -2382,  7081,  6826,  7081,  7081,  7081,
    7081,  7081,  7081, -2382,  7374,  7081,   981,  1451, -2382,  1406,
   -2382, -2382, -2382,  1830,  1344, -2382,   271, -2382, -2382, -2382,
   -2382,   254, -2382,  -202,   752,   288, -2382, -2382, -2382,  1733,
     707,  1669,  1498,   968,  7374, -2382,  1735, -2382,  4908, -2382,
   -2382, -2382, -2382, -2382,    31,   906, -2382,   537, -2382,  1423,
   -2382,   -37, -2382, -2382, -2382, -2382,  1738,  1360, -2382,   547,
   -2382, -2382,  1181,   850,  1498,  1734,   680, -2382,  1485, -2382,
   -2382,  1325,  1358,  1181,  1739,  1337,   967,  1737,  4992, -2382,
    5030,   218,  1048,  1067,  1740,   171,  1385, -2382, -2382, -2382,
    1742,    50, -2382, -2382, -2382,  4600, -2382, -2382,  1773,   -48,
   -2382, -2382, -2382,   681, -2382, -2382, -2382, -2382, -2382, -2382,
    1434, -2382, -2382,   296,  1314, -2382, -2382,   308, -2382, -2382,
   -2382, -2382, -2382, -2382,  1424,  5427, -2382,  1431,  1743,  1836,
   -2382, -2382, -2382, -2382,   911,  1483, -2382,  1443, -2382,  4448,
     -49,  -239,  1448,  1446, -2382,   834, -2382,  1453,  1746,   664,
   -2382,  1697, -2382,  1750,  1337,  1751,  1697,   968,  1749,  1398,
   -2382,   796, -2382, -2382, -2382, -2382, -2382, -2382,  1627, -2382,
     681, -2382,   -91, -2382,   373,  1868, -2382,    42, -2382,  1753,
     941,   -13,  1852,  1754,  2680, -2382, -2382,   968,  1755,  5171,
    1314, -2382, -2382,   599, -2382, -2382, -2382, -2382,  3524, -2382,
    1707, -2382,  1206,  1757,  1793,  1758,  1697, -2382,   968,  1688,
     179, -2382,   268,   945, -2382, -2382,   322,  1462,  1463,  1464,
     328, -2382,  1358, -2382,  1465, -2382, -2382,   356,  1466,   945,
   -2382,   944,   982,   982, -2382, -2382, -2382,  1024,  1467,   362,
    1470,  1055, -2382,   396,  1803,  1469,   722,  6616, -2382,  1055,
    1508,  1607, -2382, -2382,  1812, -2382, -2382,   796,  1725, -2382,
     693,  1586,   -47,  1478, -2382,  1358, -2382, -2382, -2382,  5563,
    1723, -2382,  1706, -2382,  1557, -2382,  1609,  1690, -2382, -2382,
   -2382,  1385, -2382,   850, -2382, -2382, -2382,   -32,   428,   968,
   -2382, -2382, -2382, -2382, -2382,  7081,  1677, -2382,  1346, -2382,
    1181, -2382, -2382, -2382,  1719, -2382, -2382, -2382,  5427, -2382,
    1663,    -5,  1661,  1257,  1476,  1797,  1797,  1797,  1797, -2382,
   -2382,  5427,  5563, -2382, -2382, -2382, -2382,  -220,   207, -2382,
    1471, -2382,  1472, -2382, -2382, -2382, -2382,  1405, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  4333,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    5427, -2382, -2382,   -16, -2382,  1837,   953,  1791, -2382,   796,
      54, -2382, -2382,  1603, -2382, -2382,    79,  7081, -2382,  1523,
     681, -2382, -2382,  5563,  1483,  1195,  1181, -2382, -2382, -2382,
   -2382, -2382,  1802,   968,   537, -2382,  1149, -2382, -2382, -2382,
   -2382,  1337,  3591, -2382, -2382, -2382,  1748, -2382, -2382,   -86,
    1842, -2382, -2382,   968,  1842,  1533, -2382,  1358, -2382, -2382,
     221,  1189, -2382, -2382,  2631, -2382,  1932,   821,    48, -2382,
   -2382, -2382,  1055, -2382,  -130,  5427, -2382,    28,  5291, -2382,
   -2382,   968, -2382,  1786, -2382, -2382,  5563, -2382,  1383, -2382,
   -2382,   796, -2382, -2382, -2382, -2382, -2382,  1852,  1756, -2382,
   -2382,  1149, -2382,  1852, -2382, -2382, -2382,  1468, -2382,   968,
    1380,  1380,  1380,  7374, -2382,   -34,  1380, -2382,  6977,  1380,
    1380, -2382,   535, -2382,  1539, -2382, -2382,  1055,  1055,  1732,
    1261, -2382, -2382, -2382, -2382,  1779,  1810, -2382,  1055, -2382,
    -119, -2382, -2382, -2382,  1415,  1055,  1360, -2382, -2382, -2382,
    1689, -2382,  1383, -2382,  1933, -2382, -2382, -2382,   968, -2382,
   -2382,   968, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382,  1788,  1689,    83,  1055, -2382,  1486,  1542, -2382, -2382,
   -2382,  1722,  1689,  1689,   105,  1745,  1689, -2382,  1838, -2382,
   -2382, -2382,  1493,  1496, -2382,   796,  1838,  1768,  1584,  1696,
   -2382, -2382,  1747, -2382, -2382, -2382, -2382, -2382, -2382,   549,
   -2382,   968,  1498,   569, -2382,   -85,   -50,   681,  1562,  1557,
     681, -2382,  1564,   537, -2382,   -48, -2382, -2382,  1629,  1660,
   -2382,   724,  1055, -2382, -2382, -2382, -2382, -2382,  1724, -2382,
   -2382, -2382,  1994, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    1797,  1055, -2382,   -89, -2382, -2382,  1418,  1055, -2382, -2382,
   -2382, -2382,   -28, -2382,  2054, -2382,  1420,  1722, -2382, -2382,
   -2382, -2382,  1822,   569,  1823,   111, -2382, -2382, -2382, -2382,
    2010, -2382,  1588,   285, -2382, -2382,   207, -2382, -2382, -2382,
   -2382, -2382,  1539, -2382, -2382, -2382,  1900,  1892,  1405, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382,  1667,  1405, -2382,  1593,
   -2382,  1985, -2382, -2382, -2382,   701, -2382,   796,   241, -2382,
      44,   179,    -2,   681,   681,   569,  1832,  1181,   116,   627,
    1901, -2382, -2382, -2382,  2033, -2382,  1847, -2382, -2382, -2382,
   -2382,  1748, -2382, -2382, -2382, -2382,   968,  1915,  1719,  1046,
   -2382,  1544, -2382,  1546,   796,   881, -2382,   549, -2382, -2382,
   -2382,  5427,  1189,  1189,  1189,  1189,  1189,  1189,  1189,  1189,
     821, -2382,    11,  1719,   498, -2382,  1625,  1625, -2382, -2382,
     269,   968,   569,  1848,  1605, -2382,  1611,  2049,   968,   263,
     -86,  2052,  1560,  1055, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382,   971, -2382, -2382, -2382,   968,   547, -2382,
   -2382,  1055,  1732,  1804,  1305, -2382, -2382, -2382,   968,   462,
   -2382, -2382, -2382, -2382,   462, -2382, -2382,  1055,  1366,  1055,
   -2382, -2382, -2382,  1055, -2382, -2382, -2382,   106, -2382, -2382,
   -2382,  1055,  1558,   462,   462, -2382, -2382,   462, -2382, -2382,
    1769, -2382, -2382,  1838, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382,  1485,   -47, -2382, -2382,  1770,   -68,  1862,   569,
     656, -2382, -2382, -2382, -2382, -2382,   -33,   136, -2382, -2382,
   -2382,   657, -2382, -2382, -2382, -2382, -2382, -2382,   462, -2382,
   -2382, -2382, -2382,   462,   570,   570, -2382, -2382, -2382, -2382,
   -2382,  1569,   681, -2382,   681,  1255, -2382,   650,   117,   207,
   -2382, -2382, -2382,  2010,   968, -2382, -2382, -2382, -2382,  1571,
    1365,   249,  1573,   656,   796, -2382, -2382,  2017, -2382, -2382,
   -2382, -2382,   241, -2382,  1888, -2382,  1055,  1468,  1763, -2382,
   -2382,   681, -2382,   681,   627, -2382, -2382, -2382,  1068, -2382,
   -2382,   968,  5427,  1199, -2382, -2382, -2382,  1787, -2382, -2382,
    1818, -2382, -2382, -2382, -2382,  1546, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,     7, -2382,
     968, -2382, -2382, -2382,   638, -2382, -2382, -2382,  7081, -2382,
    5427,  5427,  1621,  1761,  1485, -2382,   681, -2382,   656, -2382,
    1771, -2382,   796, -2382,  1970,  1649, -2382,   635, -2382,   566,
   -2382,  1560, -2382,   968, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382,  1330,   -58, -2382,   968, -2382, -2382, -2382, -2382, -2382,
   -2382,   631, -2382,   547,   631, -2382, -2382, -2382,   314,  2039,
    2881,  1838, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1676,
    1885, -2382, -2382, -2382,  1890, -2382, -2382, -2382, -2382, -2382,
   -2382,  1800, -2382,  1498, -2382, -2382, -2382, -2382,   968, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  3272,
   -2382, -2382, -2382,  1334, -2382, -2382, -2382,  1257, -2382,   569,
    1736,   569,  1741, -2382, -2382,  5427, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382,  1365, -2382,  1993, -2382,  1405,
   -2382, -2382, -2382,   656,  1164, -2382, -2382,  1164,   -82,   968,
   -2382, -2382,   569, -2382, -2382,  1721, -2382,  2047,  1841,  1867,
     592, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382,   945, -2382, -2382, -2382, -2382, -2382,
    1809,  1055,  1676,   569,  1614, -2382,  2049, -2382,  1568,  2012,
    1568,  1621, -2382, -2382, -2382, -2382,  1816, -2382, -2382, -2382,
   -2382,  1335, -2382,   968,  1089, -2382, -2382,  1804, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,   462, -2382, -2382,
   -2382,   462,    22, -2382, -2382,  1055, -2382, -2382, -2382,  1055,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,  2053, -2382, -2382,
      -4, -2382,  2102, -2382, -2382, -2382,  2881, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382,   968, -2382, -2382, -2382, -2382,
    1257, -2382,   681, -2382,   681, -2382, -2382, -2382,  2062,  2002,
    1164,  1164, -2382,  1662,  1662, -2382,  1777,  1181,   381, -2382,
     968, -2382, -2382,  5427, -2382,  1055,   919,  1851,  1853, -2382,
    1855, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   968, -2382,
   -2382, -2382, -2382,  1668, -2382,   968,  1568, -2382,   968, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382,   950,  1055,  1055,  1262,
   -2382, -2382, -2382, -2382, -2382, -2382,  1538, -2382, -2382, -2382,
    2011,   462,   462,  1055,   570,   570, -2382,   604, -2382, -2382,
   -2382,  1676,  1676,  5427, -2382,  1164, -2382,  5427,  5427,  1055,
    1181,  1181,  1784, -2382, -2382,  1644,   968, -2382, -2382,  1787,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1061, -2382, -2382,
     968, -2382, -2382, -2382,  1055,  1804,  1804, -2382,  1912,  1055,
    1055, -2382,  1889,  1678, -2382, -2382,   547, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,   537,  1181,  1055,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1251, -2382,
   -2382, -2382, -2382,  2020, -2382,  1804, -2382, -2382, -2382,  1804,
    1804,  1909,  1265,  1732,  1922,  1383,  1631,  1055,  1498, -2382,
    1055,  1055,   968, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382,   897, -2382,   -41, -2382,
   -2382, -2382,  1265,  1732, -2382, -2382, -2382,   537, -2382,  1766,
    1717,  1539, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   135,
   -2382,  1055,  1354, -2382,  7352,  7352,  1450,  2015,  1940, -2382,
    1383,   897, -2382, -2382,  1383,   -41, -2382, -2382,   135, -2382,
   -2382,   968, -2382,  1239,    55, -2382,   897,  1366, -2382,  1485,
    7119, -2382, -2382,  1172,  1180, -2382, -2382,  1183, -2382, -2382,
   -2382, -2382,   -54,   -54, -2382, -2382, -2382, -2382, -2382,  7352,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1801,   914,
      55, -2382, -2382, -2382,  1710, -2382,  1539, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382,  1824, -2382,  1824, -2382,  2090, -2382,
    1539, -2382, -2382,  1834,   968, -2382,  1726,   -46,  1821, -2382,
   -2382,  7352,   563, -2382, -2382,  1383, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1181, -2382
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2382, -2382, -2382, -2382, -2382,  2137, -2382, -2382, -2382,   715,
   -2382,  2100, -2382,  2055, -2382, -2382,  1382, -2382, -2382, -2382,
    1436, -2382, -2382,  1160,  2122, -2382, -2382,  2022, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  1949,
     895, -2382, -2382, -2382, -2382, -2382,  2004, -2382, -2382, -2382,
   -2382,  1947, -2382, -2382, -2382, -2382, -2382, -2382,  2079, -2382,
   -2382, -2382, -2382,  1936, -2382, -2382, -2382, -2382,  1920, -2382,
   -2382,   -60, -2382, -2382, -2382, -2382,  2013, -2382, -2382, -2382,
   -2382,  1983, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382,  1015, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382,  1643, -2382,  1759, -2382, -2382, -2382,
    1695, -2382, -2382, -2382, -2382,   297, -2382, -2382,  1880, -2382,
   -2382, -2382, -2382, -2382,  1760, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    1158, -2382, -2382, -2382,  1395, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   714,
   -2382, -2382,  1673, -2382,  -758,  -823, -2382, -2382, -2382,   347,
   -2382, -2382, -2382, -2382,  -562, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -1393,   754,  1432,   507,   564, -1391, -2382, -2382,
   -2382,  -409,  -469, -2382, -2382,   315, -2382, -2382,    29, -1390,
   -2382, -1388, -2382, -1386, -2382, -2382,  1390, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    -442,  -474, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2352, -2382,  -412, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382,  1345, -2382, -2382, -2382,    14,    15, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
    1169,   279, -2382,   145, -2382, -2382, -2382, -2382, -1824, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -1040, -2382, -2382,  -700,
   -2382,  1414, -2382, -2382, -2382, -2382, -2382, -2382,   996,   472,
     474, -2382,   392, -2382, -2382,  -155, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382,   441, -2382, -2382, -2382,   987,
   -2382, -2382, -2382, -2382, -2382,   751, -2382, -2382,   160, -2382,
   -2382, -1254, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382,   755, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   728,
   -2382, -2382, -2382, -2382, -2382,   -15, -1760, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   721,
   -2382, -2382,   711, -2382, -2382,   387,   158, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382,   -25,   675, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,   670, -2382,
   -2382,   153, -2382,   371, -2382, -2382, -1319, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
     925,   663,   147, -2382, -2382, -2382, -2382, -2382, -2382, -1673,
     924, -2382, -2382, -2382,   143, -2382, -2382, -2382,   354, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382,   306, -2382, -2382, -2382, -2382,
   -2382, -2382,   647,   139, -2382, -2382, -2382, -2382, -2382,  -110,
   -2382, -2382, -2382, -2382,   336, -2382, -2382, -2382,   909, -2382,
     918, -2382, -2382,  1123, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382,   118, -2382, -2382, -2382, -2382, -2382,   907,
     333, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382,   -30, -2382,   334, -2382, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -2382, -2382,  -376, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382,  -269, -2382,   629, -2382,
   -2382, -1652, -2382, -2382,  -615, -2382, -2382, -1631, -2382, -2382,
     -29, -2382, -2382, -2382, -2382,  -129, -2179, -2382, -2382,   -27,
   -1839, -2382, -2382, -1794, -1537, -1062, -1436, -2382, -2382,   739,
   -1635,   150,   151,   154,   156,    63,    95,  -742,   411,   379,
   -2382,   661,  -633, -1368, -1065,   205,   954, -1538,  -392,  -295,
   -2382, -1297, -2382, -1059, -2381,   830,  -530,   -98,  1984, -2382,
    1591,  -552,    27,  2132, -1054, -1020,   177,  -915, -2382, -1075,
   -1235, -2382,   389, -1266, -1050, -1090, -1145, -1058, -2382, -2382,
   -2382, -1104, -2382,   247,   846,  -630, -2382, -2382,  -103, -1182,
    -761,   -99,  2018, -1845,  2048,  -672,  1085,  -542,  -548, -2382,
   -2382, -2382,   -52,  1319, -2382, -2382,   443, -2382, -2382, -2382,
   -2382, -2382, -2382, -2382, -2382, -2382, -1962, -2382, -2382,  1548,
   -2382, -2382,  -226,  -589,  1879, -2382,  1114, -2382, -1292,  -292,
    -619,   965, -2382,  1789, -2382, -1428, -2382, -2089, -2382, -2382,
     -84, -2382,    -6,  -656,  -357, -2382, -2382, -2382, -2382,  -242,
    -247,  -263, -1180, -1535,  2086,  1856, -2382, -2382,  -342, -2382,
   -2382,   947, -2382, -2382, -2382,   385, -2382,   243, -1929, -1452,
   -2382, -2382, -2382,  -156,   446, -1379, -2174, -2382, -2382, -2382,
    -100, -2382, -2382,  1602, -2382,  1752, -2382, -2382, -2382,   756,
   -2382, -2255,  -278, -2382, -2382, -2382, -2382, -2382, -2382
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1831
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   741,   138,   689,   141,   139,   415,
     579,  1252,   759,   147,   778,  1014,   404,   160,   838,   733,
    1345,  1861,  1432,   990,  1702,   245,  1704,  1705,  1869,  1706,
    1769,  1707,   139,   427,  1237,  1873,  1219,   180,  1712,  2172,
    2189,   975,  1263,   464,  2036,  1602,   696,   437,   215,  2098,
     103,   104,   105,   268,  1459,  1828,  1283,   279,   111,  1468,
    1618,   211,  1822,  1850,  2639,  1595,   463,  1497,   259,   790,
    1344,  1753,   411, -1544,  2125,   264,  1327,   291,   768, -1545,
      99,   246,  1451,   838,  1994,  1397,  1274,   107,  1442, -1830,
    1274,  1785,  1568,   134,   135,  2034,   136,  1615,  1832,  1408,
     535,   143,   144,   392,  1274,  1747, -1786,   360,  2161,   220,
     161,  1851,  1558,   430, -1830,  1974,   790,   529, -1550,  2444,
     821,   821,  2654,  -647,  1813,   448,   825,   169, -1799,  1947,
    2677,   321,  2199,  1960,  1745, -1548,   700,   843,  2175,  1452,
    2020,   345,  2203,  2386, -1764,    42, -1830,  1127, -1830,   413,
     980,  2440,   297, -1571,   219,  1538,  2178,   211,  1219,  1190,
    1190,  1719,    94,  2029,   744,  1608,  1507,   215,   821,  1682,
    1507,  1683,  2292,   737,  2489,   701, -1830,  1000,  1209,   453,
    1332,   182,  2043,   129,  1788,   251,  1251,  1255,   221,  1916,
    1538,   283,   216,  1975, -1786,  1865,   327,   258, -1730,  1297,
    1299, -1830,   412,   535,  2236,   796,  1645,  1939,  1419,  2415,
    1007,  2418,    94,   419,   839,  2159,  2078,  2470,  1356,  1209,
    1491,   438,   717,  2642,   405,   154,  1158,  1234,  1817,  1198,
    1767,  1852,   325,  1258,  2082,   985,   154,  1128,     3,  2631,
    1216,  2226,  1572,   295,  1259,   274,   275,  1176,  1427,    94,
    2068,   299,    15,  1542,  2643,  1768,   416,   114,  1922,  2642,
    1573,  -647,  2491,  1542,   344,  -647,  1332,   439,   418,   183,
    1961,   212,  1415,   204,  1420,   406, -1830,  2123,  1129,   839,
   -1830,   999, -1726,  1849, -1726,   130,  1600,   155,  2594,   156,
    2512,  2135,   718,  1748,  1646,  1853,   400,  2054,  2069,   311,
    2030,  2118,  1234,  1190,  2119,   284,  1817,  1130,  2308,   314,
    1162,  1216,  2079,  -652,  -650,   738, -1830,  1917,  2563,   601,
    1274,   243,  1180,  -647,  1542,  1147,   413,  2480,  1539,  2084,
    1786,  2621,  -500,   431,   980,   980,   980,  1190,  1162,   154,
     139,  2188,   139,   139,     5,  1927,   280,   485,   486,   139,
    1536,  1932,  1214,  2332,   491,  1601,   980,   410,   493, -1817,
    -500,  -500,   154,  1539,  2204,  1926,   139,   212,   281,   507,
     507,   485,   507,   243,  1237,   507,   514,   783,  2195,  1234,
    1559,   -35,   728,   217,  1234,   424,  2059,  1822,  1377,  2009,
    1822,   745,  1162,   127,   989,  2062,   436,   823,  1162,  1492,
    1549,  1131,  1569,   449,   283,   443,   444,  1149,   445,   446,
    1386,  1386,  1386,   139,   452,  2387, -1764,   243,   542,   985,
     985,   985,   826,  1399,  1401,   137,  1162,  1237,  2200,   260,
    1407,   469,  1162,   749,  1940,  1263,  1723,   139,   139,  1356,
    1289,   985,   542,   580,  2205,   368,  2318,   492,  1181,  1182,
     137,  -652,  -650,   749,  2035,  -652,  -650,   137,   137,  1522,
     712,   980,  1827,  1522,  -647,   450,   702, -1730, -1730,  1993,
   -1726, -1830,  2436,  1362,  2237,  -500,   139,   752,  2445,   536,
    1469,   580,  2070,  2278,  1834,   243,   255,   753,   137,  1167,
     243, -1799,   128,   686,  1168,   139,  1603,   752,  1237,  1787,
     697,   996,   292,  -500,   783,  1836,  1864,   753,   749,   540,
     989,  2017,   980,  -652,  -650,  1877, -1759,    97,   284,   980,
     980,   980,  1854,  2048,  1754,   265,  1363,   747,   577,  2358,
    1870,  1331,   980,   980,   980,   980,   980,   980,   980,   980,
    1274,  1965,   980,   149,   747,   732,   985,   735,   591, -1726,
     593,  1498,   752,   598,   600,   261,   602,  2471,  2360,   137,
   -1629,  1237,   753,  1782,  1290,  1414,  2276,   754,   748,   394,
    1316,   137,  2003,  2007,  1434,  1234,  1812,  1814,  1938,   844,
    1542,   322,   536,   679,  2461,   749,  1469,   754,   688,   346,
     749,  2067,  -500, -1830,  1001,   699,  2206,   985,  2371, -1830,
    2373,  2052,  2501,   607,   985,   985,   985,  1393, -1730, -1730,
    2036, -1730,  1393,  1822,  1536,  2238,   351,   985,   985,   985,
     985,   985,   985,   985,   985,  1831,  1393,   985,  2106,   752,
    -657,  2391,   243,   704,   752,   517,   187,   755,  1163,   753,
    2526,  2527,   754,   188,   753, -1730,   767,  2645,  1866,  1332,
    2497,  2498,   480,   740,  -652,  -650,  1436,   755,   328,   505,
    1818,  2409,  2410,   824,  -655,   747,  1163,  1895,   829,   834,
     834,  1819,  1006,  1550,  2229,   129,  2231,    16,  2644,  1316,
    2572,   756,   949,   991,  2573,  2574,  1234,  1234,  1164,  1900,
    1544,  2209,  1237,   512,   772, -1817,   832,   773,  2462,   222,
    1915,   756,   608,  1919,  2015,  -657,  1233,  1774,  1245,  2071,
    1850,  1923,   755,  2597,   693,  2262,  1648,    27,   154,   754,
    1163,  1483,  -500,  1771,   754,   137,  1163,  1319,   465,  1324,
     749,   757,   681,  2682,  1350,   609,  2022,  1427,  1818,  -655,
    2013,    23,  2126,  2026,  1551,   137,    43,   749,  1372,  1819,
    2597,   757, -1730,  2048,  1163,  2257,   756,  1682,  1851,  1683,
    1163,  1316,   750,   751,  1362,  1362,   243,   137,  2293,   518,
   -1611, -1726,   243, -1726,   752,   187, -1609,   130, -1732,    18,
    1167,   749,   188,  1667,   753,  1168, -1730,   170,  2683,   755,
   -1744,   752,  2302,  1216,   755,  2055,  2684,  2379,  2252,   243,
     137,   753,  1750,  1228, -1606,  1999,   757,    43,  2397,  2081,
    1660,  1668,  1669,    28,     4,   -96,  1285,  1363,  1363,  1604,
    2502,  2503,   154,     5,   694,   752,   154,    24,  2398,  1770,
     226,   171,   980,   756,  2566,   753,   329,  1332,   756,  1462,
    1453,   172,  1361,  1274,  1542,  1509,  1510,  1774,   189,  2460,
    2101,  1471,  2310,   742,  2399,  1605,  1150,  1151,  2156,  1902,
    2159,  1663,   223,  1156,   754,   228,  1776,  1903,   749,   519,
    1808,  1809,  1810,  1811,   581,  1008,  2297,   137,  1852,  2400,
    2685,   754,   137,   757,  1511,  1512,   743,  2309,   757, -1830,
      36,  1223,   749,   749,  2600,   330,   305,   139,   139,   749,
     137,  2321,   682,  1474,   715,   300,  2170,   137,  2127,   229,
    1884,  1185,   752, -1066, -1830,   754,  1943,   985,   525,   230,
     190,   173,   753,  2508,   980,  2182,  2183,  2303,   227,  2184,
    2224,  2224,  2380,  2381,   755, -1746,   752,   752,  2210,  2211,
    2212,   137,  1853,   752,   137,  1722,   753,   753,  2185,  1579,
     466,   755, -1828,   753,    94,     5,   -96, -1066,  2234, -1726,
    2322,   716,  1838, -1512,  2191,  1839,   137, -1066,  1840,  1841,
    2220, -1613,  2166,  2568,    33,  2221,   191,  2230,   756,  2232,
    2004,   192,  1586,  2218,   717,   755,  2108,   189,  2240,  1548,
    1946,   174,  1222,  1628,  2008,   756,  1241,   582,  1580,   232,
    1177,  2213,   754,  1241,  1276,   467,  2086,  1241,   749,   985,
    1294,    39,  2241,  2251,   228,  1315,  2243,  1322,  1237,  1322,
    1330,  1347,  1294,  2365,  1723,   980,   754,   754,   757,   756,
    1266,   254,  1904,   754,  1885,   175,  2604,   306, -1726,  1322,
    2275,   137,  1224,  1670,  1225,   757,  2608, -1066,  2095,  2523,
    1629,   137,   752,   137,   720,  2271,  2482,  1589,   229,   190,
    1419,  1542,   753,  2455,  1905,  1627,  2483,   394,   230,   233,
     137,  1237,   755,   137,   137, -1512,  2166,  1457,  1775,   757,
    1950,  1300,   231,  2328,   255,   176,  1906,    49,  2295,  2323,
     253,  2311,  2401,  1523,  2324,  1524,   755,   755,   822,  2543,
      48,  2544,  2546,   755,  2547,  1393,  2548,  1641,   137,  1422,
     985,  2667, -1830,  2562,  1222,   191,   756, -1066,  1611,  2001,
     192,  1447,   717,  2214,  2215,  2672,  1420,  1547,  2216,  1443,
     243,   394,  1463,  1241,  2687,  2004,  1301, -1830,  1316,  1907,
     756,   756,   754,   555,  1302,   997,  2359,   756,   232,   717,
    1776,   253,  2361,  2159,  1267,  1268,    40,  1878,   556,   717,
     137, -1066,  2364,   236,  1243,   705,   757,   187, -1744,  1854,
    1241,  1269,  2383,  1671,   188,  2027,    26,  2267,  1612,   515,
    1241,  1613,  1167,  2589,   137,   137,  1879,  1168,  2513,  2037,
     757,   757,   722,    47,   117,  1617,  2162,   757,   557,  1908,
     187,  2384,    91,  2382,    52, -1066,  1454,   188,  1382,   316,
    2272, -1066,   755,   361,   394,  2286,  2286,   516,   233,   724,
    2661,   234,   235,   193,  1330,  1270,  2590,  2514,  1303,   726,
    1842,  1843,  2402,    51,    52,  2403,  2404,  1241,  1409,  1881,
   -1759,  1241,   706,   799,   707,   362,  2194,   100,  2405,   351,
    1423,    53,  2662,    97,  1844,  1845,   756,   819,   819,  2446,
     583,  -854,  2420,  2421,  -854,  2515,  2426,  2001,    94,  2438,
     317,   318,  2663,  2439,    93,   139,  2427,   101,  1250, -1550,
    1642,    53,   800,   801,   802,   803,   804,    94,  2569,    54,
    1933,    55,  1791,    56,  1909,  1792,   783,  1457,   611,  2428,
     137,    57,  1793,  1794,  1190,   819,   757,  2451,  2099,  2452,
     139,  1359,   236,   108,   820,   820,  2487,   626,   627,    54,
    2375,    55,  2449,    56,  1455,  2219,   709,  1326,    94,  2429,
    2264,    57,   106,  2100,  1898,   558,  1755,  -854,  2198,  2319,
    2224,  2224, -1730,  2500,   403,  1899,   559,  1376,  1795,  2609,
    2611,  2488,   441,   243,  -854,  2265, -1512,    58,  2585,  2649,
    1293,  1396,   820,  2158, -1512, -1512,  2475,  2650,  2482, -1512,
    2652,  1167,  1293,  2190,   109,  2648,  1168,  1839,  2483,   189,
    1840,  1841,  2528,  2494,  2495,   110,  2284,    58,   112,  1755,
    2651,  2198,  1657,  2653,  2658,    21,    22,   470,   471,   472,
    2636,   114,  1167,  1167,  2637,  1662,  2565,  1168,  1168,  1868,
    1675,  1711,   189,  1713,    46, -1830,  2268,  1796,   120,  2154,
     805,   806,   807,   808,   809,   810,   811,   639,   640,  1167,
    1166,   113,  1169,  1889,  1168, -1830,  2681,   122,    13,  1167,
    1222,  1170,   952,    13,  1168,   124,  1797,   560,   561,    59,
      60,   190, -1528, -1528, -1528, -1528,  -854,  1241,  1914,   953,
    1755, -1830,   562,   126,   563,  1973,  2198,  -854,  1798,   140,
    1418,  1222,   137,  1658,  1418,  1983,  1984,   428,  2465,  1987,
      60,  1649,  1167,   142,   190,  1653, -1830,  1168,   508,   149,
     510,  1896,  1655,   511,    61,   980,   155,  1241,   156,   594,
    -854,   595,   162,  2612,  2487,   163,  -854,   191,  -854,  1951,
    1952,  -854,   192,  -854,  -854,  -854,  2038,  2039,   473,  -854,
     592,  -854,  1799,  1755,    61,   599,  -854,    62,   706,  1925,
     707,   164,   474,  1485,  1486,  1487,  1488,   167,  2504,  2613,
     191,   181,  2505,  2506,   185,   192,   139,   564,  1404,  1405,
    1406,  1934, -1527, -1527, -1527, -1527,  2482,  1632,  -854,  1633,
     186,   954,   252,  -854,  2577,  2578,  2483,   721,   723,   725,
     727,  1962,   812,  1963,  2031,  1800,  2032,  -854,  1402,  1403,
     985,  2198,  2315,    64,  2316,   813,  2367,  2423,  2368,  2424,
     204,   193,    63,  1968,   565,   298,  1388,  1389,  1935,  1936,
    1937,  -854,   247,  1729,  1941,  1730,  1912,  1944,  1945,   242,
    1727,  1728, -1730,    64,  1976,   475,  1450,   248,   958,   959,
     960,   249,   250,  2313,   961,   257,    67,   476,  1157,   982,
    1159,   269,  -854,   278,   273,  1801,   294,   296,    65,   154,
      66,   300,  1842,  1843,   118,   302,   303,   307,  1802,   308,
    1241,  1729,   309,  1730,  1241,  1731,    67,  1241,   312,   313,
    1222,  1948,  1949,   962,   326,  -854,  1844,  1845,   333,   334,
     338,  -854,  1959,   336,   340,   342,   351,   349,   353,  1964,
     354,   356,   392,  -854,  -854,   394,   397,   398,   403,  1732,
    1733,  1734,   428,   401,   409,   408,   187,    68,   243, -1830,
     420,   421,   243,   429,   422,   413,   454,   455,  1977,   457,
    1241,   459,  -342,  2088,   483,  -854,   487,   477,   494,   490,
    2260,   495,   502,   509,   521,  -854,   522,    68,   523,   527,
    1803,  -854,   533,   543,   547,   548,   549,   964,   551,  1735,
     552,  1736,  -355,   554,   586,  -854,   137,   578,  1737,   585,
    -854,  1738,   587, -1730,   603,   605,   610,  -854,   613,  -854,
    1241,  1241,  1241,   614,  2133,  -854,  2021,   685,   698,   711,
     687,  2614,   690,  2133,  1889,  2615,  2616,   728,   730,   736,
     765,   777,   762,   746,   780,  2028,   769,   783,   965,   966,
     771,  2033,  2109,  2110,  2111,  2112,  2113,  2114,  2115,  2116,
     781,   786,   791,   793,   797,   823,   830,   836,   989, -1613,
     994,   950,   998,   982,   982,   982,  2617,   995,  1011,  1241,
    1019,  1116,  1016,  1135,  1143,  1171,  1145,  1187,  1183,  1152,
     970,  1196,  2618,  2619,  1153,   982,  1154,  1189,  1739,  1155,
    1740,  1160,  1172,  1174,   139,  1256,  1175,  1384,  1377,  2155,
     971,  1277,  1385,  1395,  1410,   972,  1294,  1332,  1197,  1411,
    1412,  1294,   973,  1425,   137,  1431,  1437,  1460,   984,  1446,
    1448,  1466,  1475,  1472,  1537,  1544,  1489,  1560,  2176,  1495,
    1294,  1294,  1493,  1561,  1294,  1563,  1557,  1565, -1530,  1577,
    1574,  1575,  1576,  1582,  1584,  1591,  1587,  1593,  1332,  1607,
    1609,  1190,  1619,  1631,  1624,  1637,  1241,  1635,  1643,  1639,
    1650,  1651,  1652,  1654,  1656,  1659,  1661,  1664,  1714,  1715,
    1666,  1717,  1720,  2605,  1751,  1294,  1757,  2153,  2088,  1758,
    1294,  1294,  1294,  1760,   624,  2225,  2225,  2270,  1201,  1241,
    1215,  1241,  2634,  1231,  2580,  2157,  1216,  1253,  1762,  1772,
    1776,   980,   980,  1682,  1729,  1683,  1730,  1783,  1288,  1789,
    1806,  2171,  1477,  2173,  1314,  1835,  1848,  2174,  1550,  1863,
    1871,  1890,  1823,  1826,  2599,  2179,  1886,   980,  1241,  1894,
    1241,  1901,  1921,  1955,  1928,  1370,  1956,  1374,  1966,  1969,
    1978,   982,  1972,  1979,  1981,  1997,   980,  1722,   982,   982,
     982,  1391,  1991,  1988,  1992,  1995,  1391,  1996,  2010,  2018,
    2014,   982,   982,   982,   982,   982,   982,   982,   982,  2023,
    1391,   982,  2019,  1998,  1427,  2042,  2044,  2049,  2056,  1741,
    2050,  2057,  2060,  1241,  2064,  2083,   985,   985,   980,  2063,
    1148,  2091,  2089,  2092,  2095,  2102,  1294,  2103,  2129,  1433,
     139,  2136,   984,   984,   984,   542,  2137,  2138,  2139,  2148,
    2159,  2180,   985,  2186,  2150, -1549,  2253,  2192,   428,  2244,
    2259,  2250,  2227,  1314,   984,  1231,  2256,  2261,  2272,  1742,
    2274,   985,  2288,  2298,  2296,  2300,  2333,  2004, -1505,  1791,
    1743,  2291,  1792, -1547,  2362,  2377,  2393,  2372,  2531,  1793,
    1794,  2392,  2374,  2394,  2395,  2406,  2411,  2416,  2303,  2443,
    2446,  2453,  2454,  2472,  2459,  2473,   428,  2474,  2456,  2478,
    2493,  2509,  2528,   985,   642,  2510,  1241,  2571,  1241,  2564,
    2575,  2581,  2583,  2601,  2628,  2602,  2629,  2668,  2659,  2671,
    2673,  2532,  2680,  2533,    17,  1795,    92,   125,    38,   166,
     256,  2675,   209,   266,   119,  1314,   139,   277,   290,  1241,
     241,  2389,   545,   210,   504,  2085,   323,  1184,   835,   442,
     526,  1703,   787,  2607,  2534,  2666,  2077,  1596,   993,   984,
    2312,  2657,  2670,  2633,  1242,   456,  1015,  1195,  2329,  2330,
    1241,  1242,  2235,   948,  2535,  1242,  1429,  1986,  1985,  2041,
    2012,  2448,  1765,  1623,  1445,  2233,  1781,  2239,  1766,  1242,
     139,  1824,  2370,  2053,  1796,   580,   646,   357,  1816,  1477,
    2376,  1847,  2536,  1859,  1294,  2255,  2065,  1867,  1294,  1564,
     984,  2263,   358,  1567,  2266,  2093,  2147,   984,   984,   984,
    1392,  1893,   359,  1797,  2277,  1392,  2117,  1598,  1348,  2287,
     984,   984,   984,   984,   984,   984,   984,   984,  1599,  1392,
     984,  1622,  2145,  2146,  2665,  1798,  2414,  2469,  1830,  1241,
    1931,  1241,  2419,  1596,  2280,  2281,   360,  1764,  2282,  2422,
    2283,  1590,   764,   332,   213,  2408,  2107,  2464,   310,  1435,
     293,  1161,  2570,   795,   651,   428,   447,  1413,   539,  2598,
    2458,   272,  2131,  2537,  2249,   489,  2076,   774,  2622,     0,
     597,   982,  1862,     0,     0,     0,     0,     0,     0,  1799,
    2538,  1242,     0,     0,     0,     0,     0,     0,     0,  2441,
       0,     0,     0,  2442,     0,     0,     0,     0,  1294,  1294,
    2539,  1294,  1294,     0,  1294,  2225,  2225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1242,     0,
       0,  2540,     0,     0,     0,     0,     0,     0,  1242,     0,
       0,     0,  1800,     0,     0,     0,     0,     0,     0,     0,
    2541,     0,     0,     0,     0,     0,     0,   660,  2542,  2466,
       0,     0,     0,     0,     0,  1596,     0,     0,   846,     0,
     847,     0,   848,   982,  1222,     0,     0,   849,     0,     0,
       0,     0,     0,     0,     0,   850,  1597,     0,     0,  1876,
       0,  2485,  2486,     0,     0,  1242,     0,     0,  1883,  1242,
       0,     0,  1801,   361,     0,     0,  2582,  2496,     0,  1892,
       0,     0,     0,     0,     0,  1802,     0,     0,   851,   852,
       0,     0,     0,  2507,     0,     0,     0,   853,     0,     0,
       0,     0,     0,     0,  1222,   362,     0,  1920,   854,     0,
       0,   855,     0,     0,     0,  -228,     0,  1596,  2525,     0,
       0,     0,     0,  2529,  2530,   856,     0,     0,     0,     0,
       0,  2630,     0,     0,     0,  2632,     0,     0,     0,  1391,
       0,  1222,     0,  2567,   982,     0,     0,     0,   857,     0,
       0,     0,  1597,     0,     0,     0,   858,     0,   859,     0,
       0,     0,     0,     0,  1756,     0,     0,  1803,   363,     0,
       0,  2584,  1314,   364,  2586,  2587,     0,  1222,     0,     0,
       0,     0,     0,     0,  1970,     0,     0,  1971,     0,   860,
     984,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     861,  2674,     0,     0,   365,   862,     0,     0,     0,     0,
       0,     0,   366,     0,     0,  2606,  2688,  1756,     0,     0,
       0,  1596,     0,     0,     0,   367,     0,     0,     0,     0,
       0,     0,   863,     0,     0,     0,     0,  2002,     0,   864,
       0,     0,   865,   866,     0,     0,     0,     0,     0,     0,
       0,     0,   867,     0,   368,     0,     0,   369,     0,   868,
       0,   869,     0,     0,   870,   370,     0,     0,     0,     0,
       0,     0,     0,     0,  1597,     0,  -225,  1202,     0,     0,
     747,     0,   984,     0,     0,  1242,     0,     0,  1756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   371,     0,   871,   372,     0,     0,
     872,     0,   873,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   874,     0,     0,  1242,  1202,     0,     0,   747,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1596,  1596,     0,     0,     0,   875,     0,
       0,  1756,     0,   952,     0,     0,  1597,     0,     0,     0,
       0,   876,     0,     0,     0,     0,     0,     0,     0,     0,
     953,     0,  2094,     0,     0,     0,     0,     0,  1392,     0,
    1596,     0,     0,   984,     0,     0,   877,   878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   879,     0,     0,
       0,     0,   952,     0,     0,     0,     0,  2134,     0,     0,
       0,   880,   881,     0,  2144,  2144,     0,     0,   882,   953,
       0,     0,   883,  1897,     0,     0,     0,     0,     0,     0,
     884,     0,  1352,     0,  1231,     0,     0,     0,     0,     0,
     885,     0,     0,     0,  2165,     0,     0,     0,     0,   886,
       0,     0,     0,     0,     0,     0,   952,     0,   887,     0,
    1597,     0,     0,   888,   889,     0,     0,   890,     0,   891,
       0,     0,   954,   953,     0,   892,     0,     0,  1242,     0,
       0,     0,  1242,   749,     0,  1242,     0,     0,   893,     0,
       0,     0,     0,     0,     0,     0,  2197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   894,     0,     0,     0,
       0,     0,   895,     0,     0,     0,  1204,   896,     0,     0,
       0,   954,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,   749,     0,     0,   961,     0,   753,  1242,     0,
    2242,     0,  1205,     0,   897,     0,     0,     0,  1621,  2197,
    1596,     0,     0,  2334,     0,     0,  2335,     0,  1596,  2336,
       0,     0,     0,     0,  1306,  1204,     0,  2337,     0,     0,
       0,   956,     0,   957,   962,   954,   752,  1876,   958,   959,
     960,     0,  1597,  1597,   961,     0,   753,     0,  1242,  1242,
    1242,  1205,     0,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2279,     0,     0,     0,
       0,     0,  2338,     0,   982,     0,     0,   754,     0,  1597,
       0,     0,     0,   962,  2197,     0,     0,     0,  1596,     0,
    1307,     0,   958,   959,   960,     0,     0,     0,   961,     0,
       0,     0,   963,     0,     0,     0,     0,  1242,   964,     0,
    2320,     0,     0,     0,     0,     0,     0,     0,     0,  1231,
       0,     0,     0,     0,     0,     0,   754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   962,     0,  1202,
       0,     0,   747,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,  2366,     0,     0,   964,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2339,     0,     0,     0,     0,     0,     0,     0,     0,  2340,
       0,     0,     0,     0,  1898,     0,     0,     0,     0,     0,
       0,   756,  2341,     0,  1242,  1899,   755,     0,     0,  2197,
       0,   970,     0,     0,     0,     0,     0,     0,   965,   966,
       0,   964,     0,     0,     0,   952,     0,     0,     0,     0,
       0,   971,     0,     0,  2342,     0,   972,  1242,     0,  1242,
       0,     0,   953,   973,     0,   137,     0,     0,     0,     0,
     756,   757,     0,     0,  2343,  1352,  2344,     0,     0,  1597,
     970,     0,     0,     0,     0,     0,     0,  1597,     0,     0,
       0,     0,   965,   966,     0,     0,  1242,     0,  1242,  2345,
     971,     0,     0, -1830,     0,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,     0,     0,     0,     0,  2346,
       0,     0,     0,     0,   970,     0,     0,     0,     0,     0,
       0,  2450,     0,   984,     0, -1119,     0,     0,     0,     0,
       0,  1242,     0,     0,   971,     0,  2347,  1597,     0,   972,
       0,     0,     0, -1119,   954,     0,   973,   243,   137,     0,
       0,     0,     0,     0,     0,   749,     0,     0,     0,     0,
       0,     0,  2348,     0,  2476,     0,     0,     0,     0,  2349,
       0,  2479,     0,     0,  2481,     0,     0,     0,     0,     0,
       0,     0,  2350,   846,     0,   847,  2351,   848,  1204,     0,
       0,     0,   849,     0,   956,     0,   957,     0,     0,   752,
     850,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,     0,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,     0,  2511,     0,  1242,     0,  1242,     0,     0,     0,
       0,     0,     0,   851,   852,  2352,  2524,     0,     0,     0,
       0,     0,   853,     0,     0,     0,   962,     0,     0,     0,
       0,     0,  1231,   854,     0,     0,   855,  1242,     0,     0,
       0,     0,     0,     0,  2353,   963,     0,     0,     0,     0,
     856,     0,     0,     0,  2354,     0,     0,     0,     0,     0,
    2355,     0,     0,     0,     0,     0,     0,     0,  1242,   754,
       0,     0,     0,   857,     0,     0,     0,     0,  2588,     0,
       0,   858,     0,   859,     0,     0,     0,     0,     0,     0,
    -694,     0,  -694,  -694,  -694,  -694,  -694,  -694,  -694,  -694,
     964,  -694,  -694,  -694,     0,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,  -694,  -694,   860,     0,     0,     0,     0,     0,
     982,   982,     0,     0,     0,   861,     0,     0,     0,     0,
     862,     0,     0,     0,     0,     0,     0,  2635,     0,   755,
       0,     0,     0,     0,     0,     0,   982,  1242,     0,  1242,
       0,   965,   966,     0,     0,     0,     0,   863,  2656,  2656,
       0,     0,     0,     0,   864,   982,     0,   865,   866,     0,
       0,     0,     0,     0,     0,     0,     0,   867,     0,     0,
       0,     0,     0,   756,   868,     0,   869,     0,     0,   870,
       0,     0,     0,   970,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2679,     0,     0,     0,   982,     0,     0,
       0,     0,     0,   971,     0,   846,     0,   847,   972,   848,
       0,     0,     0,     0,   849,   973,     0,   137,     0,     0,
       0,   871,   850,   757,     0,   872,     0,   873,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   874,     0,     0,
       0,     0,     0,  -694,  -694,     0,  -694,  -694,  -694,  -694,
       0,     0,     0,     0,     0,   851,   852,     0,     0,     0,
       0,     0,     0,   875,   853,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   854,   876,     0,   855,     0,
     747,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   856,     0,     0,     0,     0,     0,     0,     0,
       0,   877,   878,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   879,     0,     0,   857,     0,     0,     0,     0,
       0,     0,     0,   858,     0,   859,   880,   881,     0,     0,
       0,     0,     0,   882,     0,     0,     0,   883,     0,     0,
       0,     0,     0,     0,     0,   884,     0,     0,     0,   984,
     984,     0,     0,   952,     0,   885,   860,     0,     0,     0,
       0,     0,     0,     0,   886,     0,     0,   861,     0,     0,
     953,     0,   862,   887,     0,   984,     0,     0,   888,   889,
       0,     0,   890,     0,   891,     0,     0,     0,     0,     0,
     892,     0,     0,     0,   984,     0,     0,     0,   846,   863,
     847,     0,   848,  -694,     0,     0,   864,   849,     0,   865,
     866,     0,     0,     0,     0,   850,     0,     0,     0,   867,
       0,   894,     0,     0,     0,     0,   868,   895,   869,     0,
       0,   870,   896,     0,     0,     0,   984,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   851,   852,
       0,     0,     0,  -694,     0,     0,     0,   853,     0,   897,
       0,     0,     0,     0,     0,     0,     0,     0,   854,     0,
       0,   855,   954,   871,     0,     0,     0,   872,     0,   873,
       0,     0,     0,   749,     0,   856,     0,     0,     0,   874,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   857,     0,
       0,     0,     0,     0,     0,   875,   858,     0,   859,     0,
       0,     0,     0,     0,     0,     0,     0,   752,   876,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   860,
       0,     0,     0,   877,   878,     0,     0,     0,     0,     0,
     861,     0,     0,     0,   879,   862,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,   880,   881,
       0,     0,     0,     0,     0,   882,     0,     0,     0,   883,
       0,     0,   863,     0,     0,     0,     0,   884,     0,   864,
       0,     0,   865,   866,     0,     0,     0,   885,     0,     0,
       0,     0,   867,     0,     0,     0,   886,   754,     0,   868,
       0,   869,     0,     0,   870,   887,     0,     0,     0,     0,
     888,   889,     0,     0,   890,     0,   891,     0,     0,     0,
       0,     0,   892,     0,     0,     0,     0,     0,   964,     0,
       0,     0,     0,     0,     0,  1630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   871,     0,     0,     0,
     872,     0,   873,   894,     0,     0,     0,     0,     0,   895,
       0,     0,   874,     0,   896,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,  1202,     0,     0,   747,     0,     0,     0,   875,     0,
       0,   897,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   876,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,     0,   877,   878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   879,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,   880,   881,   973,     0,   137,     0,   952,   882,     0,
       0,   757,   883,     0,  1021,     0,  1022,     0,     0,  1203,
     884,  1023,     0,     0,   953,     0,     0,     0,     0,  1024,
     885,     0,     0,     0,     0,     0,     0,     0,     0,   886,
       0,     0,     0,     0,     0,     0,     0,     0,   887,     0,
       0,     0,     0,   888,   889,     0,     0,   890,     0,   891,
       0,     0,  1025,  1026,     0,   892,     0,     0,     0,     0,
       0,  1027,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1028,     0,     0,  1029,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   894,     0,     0,  1030,
       0,     0,   895,     0,     0,     0,     0,   896,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1031,     0,     0,     0,   954,     0,     0,     0,
    1032,     0,  1033,     0,   897,     0,     0,   749,     0,  1034,
       0,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,     0,
    1043,  1044,  1045,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,  1054,  1055,     0,     0,     0,     0,     0,     0,
    1204,     0,     0,     0,  1056,     0,   956,     0,   957,  1057,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,     0,     0,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1058,     0,     0,     0,
       0,     0,     0,  1059,     0,     0,  1060,  1061,     0,     0,
       0,     0,     0,     0,     0,     0,  1062,     0,   962,     0,
       0,     0,     0,  1063,     0,  1064,     0,     0,  1065,     0,
       0,     0,     0,     0,     0,     0,     0,   963,     0,  1202,
       0,     0,   747,     0,     0,  1503,  1504,  1505,     0,     0,
       0,     0,     0,  1506,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
    1066,     0,     0,     0,  1067,     0,  1068,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1069,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1070,     0,     0,   952,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1071,     0,     0,     0,     0,
       0,   755,   953,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   965,   966,     0,     0,     0,     0,     0,
    1072,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1073,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   756,  1074,     0,     0,     0,
       0,     0,  1075,     0,     0,   970,  1076,     0,     0,     0,
       0,     0,  1507,     0,  1077,     0,     0,     0,     0,     0,
       0,     0,  1508,     0,  1078,   971,     0,     0,     0,     0,
     972,     0,     0,  1079,     0,     0,     0,   973,     0,   137,
       0,     0,  1080,     0,     0,   757,     0,  1081,  1082,     0,
     952,  1083,     0,  1084,   954,     0,     0,     0,     0,  1085,
    1509,  1510,     0,     0,     0,   749,     0,   953,     0,     0,
       0,     0,  1086,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1829,     0,     0,     0,     0,
    1087,     0,     0,     0,     0,     0,  1088,     0,  1204,  1511,
    1512,  1089,     0,     0,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,     0,     0,     0,  1205,     0,  1202,     0,  1090,   747,
       0,     0,  1503,  1504,  1505,     0,     0,  1513,     0,     0,
    1506,     0,     0,  1514,     0,     0,  1515,     0,     0,     0,
       0,     0,     0,     0,  1516,     0,   962,     0,  1306,     0,
       0,  1517,     0,     0,  1202,     0,  1518,   747,     0,   954,
       0,     0,     0,     0,     0,   963,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   953,
       0,     0,     0,     0,  1450,     0,   958,   959,   960,     0,
     964,     0,   961,     0,     0,     0,     0,     0,     0,     0,
     952,     0,     0,     0,     0,     0,     0,     0,  1202,     0,
       0,   747,  1295,     0,     0,     0,     0,   953,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,   962,     0,     0,     0,     0,     0,     0,     0,  1507,
       0,   965,   966,     0,     0,     0,     0,     0,     0,  1508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1520,     0,  1521,     0,  1522,     0,     0,  1523,     0,
    1524,  1525,  1526,   756,     0,  1527,  1528,     0,     0,     0,
       0,   954,     0,   970,   952,     0,     0,  1509,  1510,     0,
       0,     0,   749,     0,     0,     0,  1357,     0,     0,     0,
       0,   953,     0,   971,     0,   964,     0,     0,   972,     0,
       0,     0,     0,     0,     0,   973,     0,   137,     0,   954,
       0,     0,     0,   757,     0,  1204,  1511,  1512,     0,     0,
     749,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1205,     0,     0,     0,     0,   965,   966,     0,     0,
       0,     0,     0,  1204,  1513,     0,     0, -1830,     0,   956,
    1514,   957,     0,  1515,   752,     0,   958,   959,   960,     0,
       0,  1516,   961,   962,   753,     0,     0,     0,  1517,  1205,
       0,     0,     0,  1518,  1202,     0,     0,   747,   970,     0,
       0,     0,   963,   954,     0,     0,     0,     0,     0, -1119,
       0,     0,  1519,     0,   749,     0,     0,     0,   971,     0,
       0,   962,     0,   972,     0,     0,   754, -1119,     0,     0,
     973,   243,   137,     0,     0,     0,     0,     0,     0,     0,
     963,     0,     0,     0,     0,     0,     0,  1204,     0,     0,
       0,     0,     0,   956,     0,   957,     0,   964,   752,     0,
     958,   959,   960,     0,   754,     0,   961,     0,   753,     0,
     952,     0,     0,  1205,     0,     0,     0,     0,  -910,     0,
       0,  -910,     0,     0,     0,     0,     0,   953,     0,     0,
       0,     0,     0,     0,     0,   964,   755,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,  1202,     0,     0,   747,
       0,     0,     0,     0,   963,     0,     0,     0,  1520,     0,
    1521,     0,  1522,     0,   755,  1523,     0,  1524,  1525,  1526,
     756,     0,  1527,  1528,     0,     0,   965,   966,   754,     0,
     970,     0,     0,     0,  -910,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     971,  -910,     0,     0,     0,   972,     0,     0,   756,   964,
       0,     0,   973,     0,   137,     0,     0,     0,   970,   954,
     757,     0,   952,     0,     0,     0,     0,     0,     0,     0,
     749,     0,     0,     0,     0,     0,     0,     0,   971,   953,
       0,     0,     0,   972,     0,     0,     0,     0,   755,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
     965,   966,     0,  1204,     0,     0,     0,  1477,     0,   956,
       0,   957,     0,     0,   752,     0,   958,   959,   960,     0,
       0,     0,   961,     0,   753,     0,     0,  1202,     0,  1205,
     747,     0,   756,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,  -910,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -910,     0,     0,     0,     0,     0,
       0,   962,   971,     0,     0,     0,     0,   972,     0,     0,
       0,     0,     0,     0,   973,     0,   137,     0,     0,     0,
     963,   954,   757,     0,     0,     0,     0,  -910,     0,     0,
       0,     0,   749,  -910,     0,  -910,     0,     0,  -910,     0,
    -910,  -910,  -910,   952,   754,     0,  -910,     0,  -910,     0,
       0,     0,     0,  -910,     0,     0,     0,     0,     0,     0,
     953,     0,     0,     0,     0,  1204,     0,     0,     0,     0,
       0,   956,     0,   957,     0,   964,   752,     0,   958,   959,
     960,     0,     0,     0,   961,  -910,   753,  1202,     0,     0,
     747,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1202,  -910,     0,   747,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,   962,     0,     0,   965,   966,  -910,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   963,     0,  1439,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1626,   756,  -910,
       0,     0,   954,   952,     0,     0,   754,     0,   970,     0,
       0,     0,     0,   749,     0,     0,     0,     0,     0,   952,
     953,     0,     0,     0,     0,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,   953,   964,  -910,     0,
     973,     0,   137,     0,     0,     0,  1204,     0,   757,     0,
    -910,  -910,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,  1202,     0,   961,   747,   753,     0,     0,
       0,     0,  1205,     0,     0,     0,   755,     0,     0,     0,
       0,     0,  -910,     0,     0,     0,     0,     0,   965,   966,
       0,     0,  -910,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,     0,     0,
       0,     0,  -910,     0,     0,     0,     0,  -910,     0,     0,
     756,     0,   954,   963,  -910,     0,  -910,     0,     0,     0,
     970,     0,  -910,   749,     0,     0,     0,     0,   954,   952,
       0,     0,     0,     0,  1481,     0,     0,   754,     0,   749,
     971,     0,     0,     0,     0,   972,   953,     0,     0,     0,
       0,     0,   973,     0,   137,     0,  1204,     0,     0,     0,
     757,     0,   956,     0,   957,     0,     0,   752,   964,   958,
     959,   960,  1204,     0,     0,   961,     0,   753,   956,     0,
     957,     0,  1205,  1246,     0,   958,   959,   960,     0,  1752,
       0,   961,   747,   753,     0,     0,     0,     0,  1205,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,     0,     0,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   954,   963,
       0,   756,     0,     0,     0,     0,     0,   754,     0,   749,
       0,   970,     0,     0,     0,   952,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,   971,   953,     0,     0,     0,   972,     0,   964,     0,
       0,     0,  1204,   973,     0,   137,     0,     0,   956,     0,
     957,   757,     0,   752,   964,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1205,     0,
       0,  1918,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,   755,     0,     0,     0,     0,     0,     0,
     962,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,   954,     0,     0,   756,     0,     0,
       0,     0,     0,   754,     0,   749,     0,   970,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,   971,     0,     0,
       0,   757,   972,     0,   964,     0,     0,     0,  1204,   973,
       0,   137,     0,     0,   956,     0,   957,   757,     0,   752,
       0,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,     0,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   962,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   963,     0,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
    1013,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
     964,  -352,     0,     0,  -352,     0,     0,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,  -352,     0,     0,     0,   755,
       0,     0,  -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,   965,   966,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   756,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,   970,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   971,     0,     0,     0,     0,   972,     0,
       0,     0,     0,     0,     0,   973,     0,   137,     0,  -352,
       0,     0,     0,   757,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   529,     0,     0,  -352,  -352,  -352,
    -352,  -352,   528,     0,  -352,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,  -352,     0,  -352,     0,     0,
       0,     0,  -352,  -352,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,  -352,  -352,     0,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
    -352,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,  -352,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,   529,     0,     0,  -352,
    -352,  -352,  -352,  -352,     0,     0,  -352,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,  -352,     0,  -352,  -352,  -352,     0,
       0,     0,     0,  -352,     0,     0,  -352,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,  -352,     0,     0,     0,  -352,  -352,  -352,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,  -352,  -352,     0,     0,
    -352,     0,     0,   530,     0,     0,     0,     0,  -352,     0,
     616,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,   617,     0,     0,   618,   619,
     620,   621,   622,   623,   624,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   625,     0,   626,   627,   628,   629,   630,   631,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,   634,   635,   636,
     637,   638,  -352,     0,   639,   640,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   618,   619,   620,   621,   622,
     623,     0,     0,     0,     0,     0,     0,     0,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,   642,     0,     0,     0,     0,   625,
   -1806,   626,   627,   628,   629,   630,   631,   632,  1677,     0,
       0,  1678,     0,     0,  1679,   618,   619,   620,   621,   622,
     623,  1680,  1681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   643,     0,     0,     0,
    1682,     0,  1683,     0,     0,   633,     0,     0,     0,   625,
       0,   626,   627,   628,   629,   630,   631,   632,     0,     0,
       0,     0,     0,     0,   644,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,     0,
       0,     0,     0,     0,     0,     0,   646,     0,     0,   647,
       0,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,   648,     0,   634,   635,   636,   637,   638,     0,
       0,   639,   640,     0,   649,     0,     0,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1684,     0,     0,     0,
       0,     0,     0,     0,     0,   641,   952,     0,     0,     0,
       0,     0,     0,     0,   634,   635,   636,   637,   638,     0,
       0,   639,   640,   953,   651,  1685,   652,   653,   654,     0,
       0,     0,  1686,     0,  1687,     0,     0,     0,     0,     0,
   -1759,     0,     0,     0,     0,     0,     0,  1688,     0,     0,
       0,     0,     0,   655,     0,   641,     0,     0,     0,     0,
       0,     0,     0,   643,     0,     0,     0,     0,    94,     0,
    -349,   642,     0,     0,     0,     0,     0,     0,     0,  1689,
       0,     0,     0,     0,     0,     0,     0, -1806,  1690,     0,
       0,     0,     0,     0,     0,     0,   656,   657,   658,     0,
       0,  1691,     0,     0,     0,   645,     0,     0,     0,     0,
     659,     0,     0,   643,     0,     0,   647,   660,     0,     0,
       0,     0,     0,     0,     0,   954,     0,     0,   952,   648,
       0,     0,     0,     0,     0,     0,   749,     0,     0,     0,
       0,  1692,     0,     0,     0,   953,     0,     0,     0,     0,
       0,     0,     0,     0,  1693,   645,     0,     0,     0,     0,
       0,     0,     0,   646,     0,     0,   647,     0,     0,   955,
       0,     0,     0,     0,     0,   956,     0,   957,     0,   648,
     752,  1694,   958,   959,   960,     0,     0,     0,   961,     0,
     753,     0,     0,   652,   653,   654,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1695,     0,     0,
       0,     0,     0,     0,  1696,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   962,     0,     0,
       0,  1697,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,   652,   653,   654,   963,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,     0,   656,   657,   658,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,   952,
       0,     0,  1698,     0,     0,     0,     0,  -597,     0,     0,
       0,   955,  1699,     0,     0,     0,   953,   956,     0,   957,
       0,   964,   752,     0,   958,   959,   960,     0,     0,  1700,
     961,     0,   753,   656,   657,   658,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   659,     0,     0,
       0,     0,     0,  1701,   660,     0,     0,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,   962,
       0,     0,   965,   966,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   963,     0,
       0,     0,  1381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   967,   952,   756,     0,   968,   969,     0,     0,
       0,     0,   754,     0,   970,     0,     0,     0,   954,   952,
     953,     0,     0,     0,     0,     0,     0,     0,     0,   749,
       0,     0,     0,     0,   971,     0,   953,     0,     0,   972,
       0,   952,     0,   964,     0,     0,   973,     0,   137,     0,
       0,     0,     0,     0,   757,     0,     0,     0,   953,     0,
       0,     0,   955,     0,     0,     0,     0,     0,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,   755,   753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1400,     0,     0,     0,     0,     0,
     962,     0,   954,     0,   967,     0,   756,     0,   968,   969,
       0,     0,     0,   749,     0,     0,   970,     0,   954,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   749,
       0,     0,     0,     0,     0,     0,   971,     0,     0,     0,
     954,   972,     0,   754,     0,     0,   955,     0,   973,     0,
     137,   749,   956,     0,   957,     0,   757,   752,     0,   958,
     959,   960,   955,     0,     0,   961,     0,   753,   956,     0,
     957,     0,     0,   752,   964,   958,   959,   960,     0,     0,
       0,   961,     0,   753,   955,     0,     0,     0,     0,     0,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,   962,   753,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
     962,     0,     0,   963,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,   962,     0,     0,  1942,     0,   754,     0,     0,
       0,     0,     0,     0,   952,   967,     0,   756,     0,   968,
     969,   963,     0,   754,     0,     0,     0,   970,     0,     0,
       0,   953,     0,     0,     0,     0,   952,     0,   964,     0,
       0,     0,     0,     0,     0,   754,     0,   971,     0,     0,
       0,     0,   972,   953,   964,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,  2646,     0,     0,     0,   964,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,   755,     0,     0,     0,   967,
       0,   756,     0,   968,   969,     0,     0,   965,   966,     0,
       0,   970,     0,   954,     0,     0,     0,   756,     0,   968,
       0,     0,     0,     0,   749,     0,     0,   970,     0,     0,
       0,   971,     0,     0,     0,   954,   972,     0,     0,   756,
       0,     0,     0,   973,     0,   137,   749,   971,     0,   970,
       0,   757,   972,     0,     0,     0,     0,   955,     0,   973,
       0,   137,     0,   956,     0,   957,     0,   757,   752,   971,
     958,   959,   960,     0,   972,     0,   961,     0,   753,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
     752,     0,   958,   959,   960,     0,     0,     0,   961,     0,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,     0,   962,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   964,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   965,   966,     0,     0,     0,     0,     0,     0,
       0,     0,   756,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   970,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
       0,     0,   971,     0,   970,     0,     0,   972,     0,     0,
       0,     0,     0,     0,   973,     0,   137,     0,     0,     0,
       0,     0,   757,     0,   971,     0,     0,     0,     0,   972,
       0,     0,     0,     0,     0,     0,   973,     0,   137,     0,
       0,     0,     0,     0,   757
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-2382))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   660,   103,   595,   105,   111,   366,
     540,  1101,   684,   111,   714,   838,   358,   116,   776,   649,
    1124,  1556,  1202,   784,  1417,   181,  1417,  1417,  1566,  1417,
    1458,  1417,   135,   425,  1099,  1572,  1095,   135,  1417,  1968,
    2002,   783,  1104,   435,  1804,  1342,   598,   404,   158,  1888,
      56,    57,    58,   209,  1234,  1507,  1110,     1,    64,  1241,
    1352,    22,  1498,     9,     9,  1331,     1,    17,     9,   741,
    1124,  1439,   364,    31,  1913,     1,     9,    17,   697,    31,
      53,   184,  1227,   841,  1736,  1160,  1106,    60,    57,   107,
    1110,    96,   141,    99,   100,   123,   102,  1351,   114,  1174,
     124,   107,   108,    86,  1124,   152,    27,    63,  1953,    96,
     116,    57,  1294,   172,   244,    32,   788,   175,   203,   123,
     750,   751,   176,     0,  1492,     9,    57,   133,    39,  1664,
     176,     1,   165,   252,  1431,   203,   174,    55,    32,  1229,
    1771,    57,     6,   225,   232,   142,   328,   256,   161,   237,
     783,   129,   251,   203,   160,   203,  1980,    22,  1217,    49,
      49,  1427,   232,   252,   241,  1347,   159,   277,   798,    64,
     159,    66,  2134,   242,  2429,   213,   262,    48,  1093,   421,
     271,   218,  1813,   354,  1481,   191,  1101,  1102,   161,   161,
     203,   274,   232,   110,   115,  1563,   295,   203,    87,  1114,
    1115,   287,   113,   124,    87,   747,    27,   241,   410,  2298,
     829,  2300,   232,   369,   776,   256,   218,  2396,  1133,  1134,
      49,   125,   406,  2604,   446,   256,   968,     6,    21,   308,
     262,   177,   292,   453,  1865,   783,   256,   346,     0,  2591,
     256,  2035,   481,   249,   464,   218,   219,   989,    30,   232,
       9,   257,   451,  1273,  2606,   287,   287,    57,  1626,  2640,
     499,   138,  2436,  1283,   324,   142,   271,   171,   367,   306,
     389,   232,     1,   199,   476,   497,   289,  1912,   387,   841,
     410,   823,    64,  1549,    66,   456,  1340,   307,   329,   309,
    2469,  1922,   476,   340,   115,   241,   356,  1832,    57,   272,
     389,   290,     6,    49,   293,   388,    21,   416,  2147,   282,
      70,   256,   314,     0,     0,   384,   187,   289,  2492,   561,
    1340,   503,   994,   200,  1344,   955,   237,  2416,   376,  1867,
     335,  2586,    61,   392,   967,   968,   969,    49,    70,   256,
     443,  1993,   445,   446,   341,  1637,   290,   445,   446,   452,
    1265,  1643,  1094,  2177,   452,   446,   989,   363,   457,   110,
      89,    90,   256,   376,   228,  1631,   469,   232,   312,   472,
     473,   469,   475,   503,  1439,   478,   479,   462,  2009,     6,
    1295,   451,   501,   423,     6,   391,  1838,  1823,   309,  1757,
    1826,   468,    70,    72,   462,  1847,   402,   447,    70,   228,
      92,   510,   451,   287,   274,   411,   412,   955,   414,   415,
    1152,  1153,  1154,   516,   420,   497,   504,   503,   516,   967,
     968,   969,   353,  1165,  1166,   504,    70,  1492,   461,   370,
    1172,   437,    70,   212,   468,  1497,   331,   540,   541,  1354,
    1112,   989,   540,   541,   308,   401,   504,   453,  1000,  1001,
     504,   138,   138,   212,   482,   142,   142,   504,   504,   452,
     337,  1094,  1502,   452,   341,   349,   504,   357,   357,  1735,
     252,   175,  2317,   451,   357,   204,   579,   256,   482,   503,
    1241,   579,   241,  2118,  1543,   503,   504,   266,   504,   458,
     503,   402,   171,   592,   463,   598,   123,   256,  1563,   504,
     599,   793,   442,   232,   462,  1545,  1560,   266,   212,   515,
     462,  1765,  1145,   200,   200,  1574,   499,   504,   388,  1152,
    1153,  1154,   468,  1815,  1439,   451,   504,     9,   534,  2181,
    1570,   153,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1560,  1686,  1175,   504,     9,   644,  1094,   650,   554,   331,
     556,   501,   256,   559,   560,   496,   562,  2396,  2189,   504,
     504,  1626,   266,  1478,  1112,  1184,  2103,   346,    50,   504,
    1118,   504,  1752,  1755,  1204,     6,  1491,  1492,  1653,   497,
    1600,   451,   503,   589,   203,   212,  1347,   346,   594,   505,
     212,  1857,   321,   330,   465,   601,   460,  1145,  2229,   330,
    2231,   316,  2447,   576,  1152,  1153,  1154,  1155,   498,   498,
    2370,   357,  1160,  2049,  1529,   498,   188,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1540,  1174,  1175,  1894,   256,
     376,  2262,   503,   606,   256,    33,    56,   416,   398,   266,
    2485,  2486,   346,    63,   266,   357,   446,  2609,  1563,   271,
    2444,  2445,   256,   659,   341,   341,  1204,   416,   257,   256,
     453,  2292,  2293,   762,   376,     9,   398,   446,   767,   772,
     773,   464,   828,   365,  2042,   354,  2044,   451,  2607,  1227,
    2525,   460,   781,   786,  2529,  2530,     6,     6,   448,  1604,
     441,    34,  1757,   256,   700,   446,   256,   703,   317,   234,
    1615,   460,   171,  1618,  1763,   451,  1098,  1468,  1100,   468,
       9,  1626,   416,  2558,   308,  2083,   448,   122,   256,   346,
     398,   503,   451,  1465,   346,   504,   398,  1119,   125,  1121,
     212,   510,    26,   170,  1126,   204,  1776,    30,   453,   451,
    1760,   256,   244,  1783,   436,   504,    31,   212,  1140,   464,
    2595,   510,   498,  2045,   398,  2074,   460,    64,    57,    66,
     398,  1309,   244,   245,   451,   451,   503,   504,  2136,   167,
     448,    64,   503,    66,   256,    56,   448,   456,    59,   153,
     458,   212,    63,    61,   266,   463,   498,   212,   225,   416,
     362,   256,   157,   256,   416,  1835,   233,  2249,  2064,   503,
     504,   266,  1432,   256,   448,   256,   510,    92,   216,  1863,
     448,    89,    90,    84,   200,   229,  1111,   504,   504,   446,
    2451,  2452,   256,   341,   418,   256,   256,   342,   236,  1459,
      28,   256,  1465,   460,  2507,   266,   435,   271,   460,   159,
    1232,   266,  1137,  1863,  1864,   207,   208,  1608,   268,  2387,
    1890,  1243,  2149,   171,   262,   482,   956,   957,  1948,    38,
     256,  1413,   397,   963,   346,   212,   231,    46,   212,   267,
    1485,  1486,  1487,  1488,   262,   196,  2142,   504,   177,   287,
     317,   346,   504,   510,   246,   247,   204,   321,   510,   262,
      26,   271,   212,   212,  2567,   494,   229,  1000,  1001,   212,
     504,   270,   196,  1245,   244,   504,  1964,   504,   410,   256,
    1582,  1010,   256,   212,   287,   346,  1658,  1465,   451,   266,
     340,   346,   266,  2461,  1557,  1983,  1984,   292,   126,  1987,
    2034,  2035,  2251,  2252,   416,   256,   256,   256,   281,   282,
     283,   504,   241,   256,   504,   252,   266,   266,  1988,   285,
     347,   416,   453,   266,   232,   341,   370,   256,   308,   252,
     329,   301,     9,    57,  2004,    12,   504,   266,    15,    16,
    2028,   504,   510,  2510,   138,  2033,   396,  2042,   460,  2044,
     411,   401,  1324,  2023,   406,   416,  1901,   268,  2050,  1284,
    1662,   416,  1095,   394,  1755,   460,  1099,   385,   334,   346,
     501,   344,   346,  1106,  1107,   402,   379,  1110,   212,  1557,
    1113,   451,  2052,  2063,   212,  1118,  2056,  1120,  2083,  1122,
    1123,  1124,  1125,  2203,   331,  1658,   346,   346,   510,   460,
     199,   451,   211,   346,  1582,   460,  2571,   370,   331,  1142,
    2102,   504,   422,   321,   424,   510,  2583,   346,   129,  2477,
     451,   504,   256,   504,   476,  2095,   106,  1326,   256,   340,
     410,  2081,   266,  2382,   243,  1360,   116,   504,   266,   416,
     504,  2136,   416,   504,   504,   169,   510,  1233,  1470,   510,
    1669,   170,   280,  2173,   504,   510,   265,   451,  2138,   458,
     195,  2149,   500,   455,   463,   457,   416,   416,   751,  2492,
     256,  2492,  2492,   416,  2492,  1653,  2492,  1376,   504,   357,
    1658,  2646,   262,  2492,  1217,   396,   460,   416,   177,  1749,
     401,  1221,   406,   466,   467,  2660,   476,  1283,   471,   223,
     503,   504,   452,  1236,  2672,   411,   225,   287,  1686,   318,
     460,   460,   346,    47,   233,   798,  2186,   460,   346,   406,
     231,   256,  2192,   256,   323,   324,   394,     8,    62,   406,
     504,   460,  2202,   510,   454,   274,   510,    56,   107,   468,
    1273,   340,     8,   451,    63,  1790,    16,  2092,   237,   414,
    1283,   240,   458,   286,   504,   504,    37,   463,   127,  1804,
     510,   510,   476,    33,     1,  1351,  1954,   510,   102,   378,
      56,    37,    42,  2253,    11,   504,   356,    63,  1145,   351,
     291,   510,   416,   220,   504,  2130,  2131,   452,   416,   476,
     306,   419,   420,   504,  1327,   394,   329,   166,   317,   476,
     277,   278,  2272,   451,    11,  2275,  2276,  1340,  1175,  1581,
     204,  1344,   351,     1,   353,   252,  2007,   423,  2288,   188,
     498,    58,   338,   504,   301,   302,   460,   750,   751,     8,
     546,     6,  2302,  2303,     9,   204,   177,  1897,   232,  2327,
     412,   413,   358,  2331,   451,  1378,   187,   405,  1101,   445,
    1378,    58,    40,    41,    42,    43,    44,   232,    37,    96,
    1647,    98,    35,   100,   473,    38,   462,  1453,   584,   210,
     504,   108,    45,    46,    49,   798,   510,  2372,   262,  2374,
    1413,  1134,   510,   405,   750,   751,    54,    75,    76,    96,
    2235,    98,  2362,   100,   474,  2025,   612,  1122,   232,   240,
     262,   108,   394,   287,   453,   239,  1439,    82,  2010,  2162,
    2444,  2445,    87,  2447,   351,   464,   250,  1142,    91,  2584,
    2585,    89,   359,   503,    99,   287,   450,   164,  2538,   187,
    1113,   448,   798,  1952,   458,   459,  2406,   187,   106,   463,
     187,   458,  1125,  2003,   451,  2610,   463,    12,   116,   268,
      15,    16,   210,  2441,  2442,   451,  2128,   164,   451,  1492,
     210,  2063,   448,   210,  2629,    13,    14,   117,   118,   119,
     161,    57,   458,   458,   165,  1411,  2496,   463,   463,  1565,
    1416,  1417,   268,  1419,    32,   216,   217,   160,   218,   448,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   458,
     449,   451,   450,  1589,   463,   236,  2671,   173,     2,   458,
    1543,   459,    82,     7,   463,   451,   189,   351,   352,   226,
     257,   340,   485,   486,   487,   488,   201,  1560,  1614,    99,
    1563,   262,   366,   451,   368,  1712,  2138,   212,   211,    68,
    1191,  1574,   504,   449,  1195,  1722,  1723,  1869,  2393,  1726,
     257,  1386,   458,   451,   340,  1390,   287,   463,   473,   504,
     475,  1601,  1397,   478,   301,  2128,   307,  1600,   309,   351,
     245,   353,   451,    53,    54,   504,   251,   396,   253,   248,
     249,   256,   401,   258,   259,   260,    96,    97,   238,   264,
     555,   266,   265,  1626,   301,   560,   271,   304,   351,  1628,
     353,   451,   252,   485,   486,   487,   488,   340,  2453,    89,
     396,   256,  2457,  2458,   256,   401,  1649,   451,  1169,  1170,
    1171,  1649,   485,   486,   487,   488,   106,   351,   303,   353,
     468,   201,   451,   308,   299,   300,   116,   620,   621,   622,
     623,   156,   330,   158,   156,   318,   158,   322,  1167,  1168,
    2128,  2253,   252,   390,   254,   343,   252,   252,   254,   254,
     199,   504,   369,  1692,   498,   451,  1153,  1154,  1650,  1651,
    1652,   346,   400,    65,  1656,    67,  1612,  1659,  1660,   442,
      24,    25,   357,   390,  1713,   335,   256,   401,   258,   259,
     260,   410,    63,  2153,   264,    59,   433,   347,   967,   783,
     969,   256,   377,   451,   232,   378,   328,   401,   415,   256,
     417,   504,   277,   278,   451,   229,    26,   451,   391,   451,
    1753,    65,   107,    67,  1757,    69,   433,  1760,   451,   312,
    1763,  1667,  1668,   303,   256,   410,   301,   302,   256,   272,
      23,   416,  1678,   454,   102,   451,   188,   437,   122,  1685,
     454,    17,    86,   428,   429,   504,   451,   394,   351,   103,
     104,   105,  2084,   272,   402,   401,    56,   504,   503,   500,
     423,   262,   503,   451,    39,   237,   402,   504,  1714,   331,
    1813,   506,   504,  1869,   419,   460,   316,   437,   394,   310,
    2077,   261,   451,     7,   451,   470,   394,   504,   255,   451,
     473,   476,   504,   503,   451,   394,   366,   377,   451,   153,
     451,   155,    85,    85,   394,   490,   504,   124,   162,   451,
     495,   165,   389,   498,    22,   306,   309,   502,   451,   504,
    1863,  1864,  1865,   394,  1920,   510,  1772,   204,   499,   451,
     504,   321,   504,  1929,  1930,   325,   326,   501,   384,   232,
     254,   122,   446,   504,   510,  1791,   218,   462,   428,   429,
     504,  1797,  1902,  1903,  1904,  1905,  1906,  1907,  1908,  1909,
     446,   442,    26,   400,   306,   447,   410,   348,   462,   504,
     442,   445,   451,   967,   968,   969,   366,   256,   504,  1922,
     376,   399,   451,   336,   114,   169,   462,   451,   187,   462,
     470,   504,   382,   383,   462,   989,   462,   451,   252,   462,
     254,   462,   462,   462,  1947,   256,   462,   504,   309,  1947,
     490,   446,   504,   504,   403,   495,  1959,   271,   451,   453,
      30,  1964,   502,   130,   504,   196,   131,   133,   783,   446,
     132,   386,   135,   134,   101,   441,   136,   446,  1977,   137,
    1983,  1984,   497,   140,  1987,    49,   462,   404,   445,   143,
     442,   445,   439,   196,   144,   146,   145,   499,   271,    31,
     147,    49,   148,   196,   149,   112,  2009,   150,   220,   151,
     448,   448,   448,   448,   448,   448,   446,   114,   410,   312,
     451,   109,   197,  2579,   446,  2028,   203,  1933,  2084,   223,
    2033,  2034,  2035,   376,    45,  2034,  2035,  2093,  1092,  2042,
    1094,  2044,  2598,  1097,  2533,  1951,   256,  1101,   339,   272,
     231,  2584,  2585,    64,    65,    66,    67,   294,  1112,   298,
     484,  1967,   165,  1969,  1118,   128,   175,  1973,   365,   446,
     168,   129,   501,   501,  2563,  1981,   228,  2610,  2081,   446,
    2083,    49,   196,   204,   228,  1139,   176,  1141,   299,    56,
     504,  1145,   204,   451,   272,   299,  2629,   252,  1152,  1153,
    1154,  1155,   509,   165,   508,   237,  1160,   423,   446,   380,
     446,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,   295,
    1174,  1175,   362,   276,    30,   203,   203,    17,   128,   443,
     442,   139,   365,  2136,    49,   203,  2584,  2585,  2671,   446,
     955,     8,   141,   196,   129,   501,  2149,   501,   423,  1203,
    2153,   203,   967,   968,   969,  2153,   451,   446,     9,     7,
     256,   503,  2610,   294,   504,   203,    49,   297,  2460,   498,
    2076,   498,   503,  1227,   989,  1229,   188,   314,   291,   493,
     262,  2629,   461,   113,   313,   436,    47,   411,   203,    35,
     504,   330,    38,   203,   294,   102,    49,   361,   209,    45,
      46,   380,   361,   262,   237,   296,   492,    95,   292,    56,
       8,    49,   110,   262,   337,   262,  2508,   262,   456,   451,
     109,   337,   210,  2671,   235,   481,  2229,   107,  2231,   451,
     221,   209,   501,   367,   119,   418,   196,   313,   337,    49,
     306,   252,   321,   254,     7,    91,    46,    92,    26,   127,
     201,   425,   148,   206,    75,  1309,  2259,   221,   238,  2262,
     177,  2259,   519,   150,   469,  1868,   286,  1009,   773,   410,
     497,  1417,   740,  2582,   285,  2644,  1861,  1331,   788,  1094,
    2151,  2623,  2656,  2595,  1099,   425,   841,  1018,  2174,  2174,
    2293,  1106,  2047,   779,   305,  1110,  1200,  1725,  1724,  1807,
    1759,  2356,  1451,  1357,  1217,  2045,  1478,  2049,  1453,  1124,
    2313,  1500,  2227,  1826,   160,  2313,   327,     4,  1497,   165,
    2245,  1546,   333,  1553,  2327,  2072,  1855,  1564,  2331,  1304,
    1145,  2084,    19,  1309,  2091,  1881,  1930,  1152,  1153,  1154,
    1155,  1594,    29,   189,  2105,  1160,  1910,  1338,  1125,  2131,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1340,  1174,
    1175,  1354,  1929,  1929,  2640,   211,  2296,  2396,  1529,  2372,
    1641,  2374,  2301,  1427,  2124,  2124,    63,  1447,  2124,  2306,
    2124,  1327,   691,   299,   152,  2291,  1897,  2390,   270,  1204,
     242,   972,  2518,   745,   405,  2687,   417,  1183,   509,  2562,
    2384,   215,  1917,   414,  2061,   449,  1860,   705,  2586,    -1,
     558,  1465,  1556,    -1,    -1,    -1,    -1,    -1,    -1,   265,
     431,  1236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2335,
      -1,    -1,    -1,  2339,    -1,    -1,    -1,    -1,  2441,  2442,
     451,  2444,  2445,    -1,  2447,  2444,  2445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1273,    -1,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,
      -1,    -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     491,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,  2395,
      -1,    -1,    -1,    -1,    -1,  1549,    -1,    -1,     1,    -1,
       3,    -1,     5,  1557,  2507,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,  1331,    -1,    -1,  1573,
      -1,  2427,  2428,    -1,    -1,  1340,    -1,    -1,  1582,  1344,
      -1,    -1,   378,   220,    -1,    -1,  2535,  2443,    -1,  1593,
      -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,    51,    52,
      -1,    -1,    -1,  2459,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,  2567,   252,    -1,  1621,    71,    -1,
      -1,    74,    -1,    -1,    -1,   262,    -1,  1631,  2484,    -1,
      -1,    -1,    -1,  2489,  2490,    88,    -1,    -1,    -1,    -1,
      -1,  2590,    -1,    -1,    -1,  2594,    -1,    -1,    -1,  1653,
      -1,  2604,    -1,  2509,  1658,    -1,    -1,    -1,   111,    -1,
      -1,    -1,  1427,    -1,    -1,    -1,   119,    -1,   121,    -1,
      -1,    -1,    -1,    -1,  1439,    -1,    -1,   473,   315,    -1,
      -1,  2537,  1686,   320,  2540,  2541,    -1,  2640,    -1,    -1,
      -1,    -1,    -1,    -1,  1698,    -1,    -1,  1701,    -1,   152,
    1465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,  2664,    -1,    -1,   351,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   359,    -1,    -1,  2581,  2675,  1492,    -1,    -1,
      -1,  1735,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,  1751,    -1,   202,
      -1,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,    -1,   401,    -1,    -1,   404,    -1,   222,
      -1,   224,    -1,    -1,   227,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1549,    -1,   423,     6,    -1,    -1,
       9,    -1,  1557,    -1,    -1,  1560,    -1,    -1,  1563,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   451,    -1,   269,   454,    -1,    -1,
     273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   285,    -1,    -1,  1600,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1857,  1858,    -1,    -1,    -1,   311,    -1,
      -1,  1626,    -1,    82,    -1,    -1,  1631,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,  1886,    -1,    -1,    -1,    -1,    -1,  1653,    -1,
    1894,    -1,    -1,  1658,    -1,    -1,   349,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,  1921,    -1,    -1,
      -1,   374,   375,    -1,  1928,  1929,    -1,    -1,   381,    99,
      -1,    -1,   385,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     393,    -1,   112,    -1,  1948,    -1,    -1,    -1,    -1,    -1,
     403,    -1,    -1,    -1,  1958,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,   421,    -1,
    1735,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,   432,
      -1,    -1,   201,    99,    -1,   438,    -1,    -1,  1753,    -1,
      -1,    -1,  1757,   212,    -1,  1760,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2010,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,
      -1,    -1,   475,    -1,    -1,    -1,   245,   480,    -1,    -1,
      -1,   201,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,   212,    -1,    -1,   264,    -1,   266,  1813,    -1,
    2054,    -1,   271,    -1,   507,    -1,    -1,    -1,   228,  2063,
    2064,    -1,    -1,    32,    -1,    -1,    35,    -1,  2072,    38,
      -1,    -1,    -1,    -1,   190,   245,    -1,    46,    -1,    -1,
      -1,   251,    -1,   253,   303,   201,   256,  2091,   258,   259,
     260,    -1,  1857,  1858,   264,    -1,   266,    -1,  1863,  1864,
    1865,   271,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2120,    -1,    -1,    -1,
      -1,    -1,    91,    -1,  2128,    -1,    -1,   346,    -1,  1894,
      -1,    -1,    -1,   303,  2138,    -1,    -1,    -1,  2142,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,  1922,   377,    -1,
    2164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2173,
      -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,     6,
      -1,    -1,     9,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,  2208,    -1,    -1,   377,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,
      -1,   460,   211,    -1,  2009,   464,   416,    -1,    -1,  2253,
      -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,   377,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,   243,    -1,   495,  2042,    -1,  2044,
      -1,    -1,    99,   502,    -1,   504,    -1,    -1,    -1,    -1,
     460,   510,    -1,    -1,   263,   112,   265,    -1,    -1,  2064,
     470,    -1,    -1,    -1,    -1,    -1,    -1,  2072,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,  2081,    -1,  2083,   288,
     490,    -1,    -1,   439,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,
     510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,  2365,    -1,  2128,    -1,   481,    -1,    -1,    -1,    -1,
      -1,  2136,    -1,    -1,   490,    -1,   345,  2142,    -1,   495,
      -1,    -1,    -1,   499,   201,    -1,   502,   503,   504,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,  2408,    -1,    -1,    -1,    -1,   378,
      -1,  2415,    -1,    -1,  2418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   391,     1,    -1,     3,   395,     5,   245,    -1,
      -1,    -1,    10,    -1,   251,    -1,   253,    -1,    -1,   256,
      18,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2466,    -1,  2229,    -1,  2231,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,   444,  2480,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,   303,    -1,    -1,    -1,
      -1,    -1,  2496,    71,    -1,    -1,    74,  2262,    -1,    -1,
      -1,    -1,    -1,    -1,   473,   322,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2293,   346,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,  2542,    -1,
      -1,   119,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     377,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
    2584,  2585,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,  2601,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,  2610,  2372,    -1,  2374,
      -1,   428,   429,    -1,    -1,    -1,    -1,   195,  2622,  2623,
      -1,    -1,    -1,    -1,   202,  2629,    -1,   205,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,   460,   222,    -1,   224,    -1,    -1,   227,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2667,    -1,    -1,    -1,  2671,    -1,    -1,
      -1,    -1,    -1,   490,    -1,     1,    -1,     3,   495,     5,
      -1,    -1,    -1,    -1,    10,   502,    -1,   504,    -1,    -1,
      -1,   269,    18,   510,    -1,   273,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,
      -1,    -1,    -1,   291,   292,    -1,   294,   295,   296,   297,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,   311,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,   324,    -1,    74,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,   374,   375,    -1,    -1,
      -1,    -1,    -1,   381,    -1,    -1,    -1,   385,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,  2584,
    2585,    -1,    -1,    82,    -1,   403,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   412,    -1,    -1,   163,    -1,    -1,
      99,    -1,   168,   421,    -1,  2610,    -1,    -1,   426,   427,
      -1,    -1,   430,    -1,   432,    -1,    -1,    -1,    -1,    -1,
     438,    -1,    -1,    -1,  2629,    -1,    -1,    -1,     1,   195,
       3,    -1,     5,   451,    -1,    -1,   202,    10,    -1,   205,
     206,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,   215,
      -1,   469,    -1,    -1,    -1,    -1,   222,   475,   224,    -1,
      -1,   227,   480,    -1,    -1,    -1,  2671,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,   501,    -1,    -1,    -1,    60,    -1,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,   201,   269,    -1,    -1,    -1,   273,    -1,   275,
      -1,    -1,    -1,   212,    -1,    88,    -1,    -1,    -1,   285,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   311,   119,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   324,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   349,   350,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   360,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,   374,   375,
      -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,   385,
      -1,    -1,   195,    -1,    -1,    -1,    -1,   393,    -1,   202,
      -1,    -1,   205,   206,    -1,    -1,    -1,   403,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,   412,   346,    -1,   222,
      -1,   224,    -1,    -1,   227,   421,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,    -1,    -1,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
     273,    -1,   275,   469,    -1,    -1,    -1,    -1,    -1,   475,
      -1,    -1,   285,    -1,   480,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,     6,    -1,    -1,     9,    -1,    -1,    -1,   311,    -1,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    -1,   349,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,   374,   375,   502,    -1,   504,    -1,    82,   381,    -1,
      -1,   510,   385,    -1,     3,    -1,     5,    -1,    -1,    94,
     393,    10,    -1,    -1,    99,    -1,    -1,    -1,    -1,    18,
     403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,   432,
      -1,    -1,    51,    52,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    88,
      -1,    -1,   475,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     119,    -1,   121,    -1,   507,    -1,    -1,   212,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,   163,    -1,   251,    -1,   253,   168,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,   205,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,   303,    -1,
      -1,    -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,
      -1,   416,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,   375,    -1,    -1,    -1,
      -1,    -1,   381,    -1,    -1,   470,   385,    -1,    -1,    -1,
      -1,    -1,   159,    -1,   393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,    -1,   403,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,   412,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,   421,    -1,    -1,   510,    -1,   426,   427,    -1,
      82,   430,    -1,   432,   201,    -1,    -1,    -1,    -1,   438,
     207,   208,    -1,    -1,    -1,   212,    -1,    99,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    -1,    -1,    -1,   475,    -1,   245,   246,
     247,   480,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,    -1,    -1,   271,    -1,     6,    -1,   507,     9,
      -1,    -1,    12,    13,    14,    -1,    -1,   284,    -1,    -1,
      20,    -1,    -1,   290,    -1,    -1,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   301,    -1,   303,    -1,   190,    -1,
      -1,   308,    -1,    -1,     6,    -1,   313,     9,    -1,   201,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
     377,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,     9,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,   450,    -1,   452,    -1,    -1,   455,    -1,
     457,   458,   459,   460,    -1,   462,   463,    -1,    -1,    -1,
      -1,   201,    -1,   470,    82,    -1,    -1,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    99,    -1,   490,    -1,   377,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,   201,
      -1,    -1,    -1,   510,    -1,   245,   246,   247,    -1,    -1,
     212,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,   245,   284,    -1,    -1,   439,    -1,   251,
     290,   253,    -1,   293,   256,    -1,   258,   259,   260,    -1,
      -1,   301,   264,   303,   266,    -1,    -1,    -1,   308,   271,
      -1,    -1,    -1,   313,     6,    -1,    -1,     9,   470,    -1,
      -1,    -1,   322,   201,    -1,    -1,    -1,    -1,    -1,   481,
      -1,    -1,   332,    -1,   212,    -1,    -1,    -1,   490,    -1,
      -1,   303,    -1,   495,    -1,    -1,   346,   499,    -1,    -1,
     502,   503,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,   377,   256,    -1,
     258,   259,   260,    -1,   346,    -1,   264,    -1,   266,    -1,
      82,    -1,    -1,   271,    -1,    -1,    -1,    -1,     6,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,   448,    -1,
     450,    -1,   452,    -1,   416,   455,    -1,   457,   458,   459,
     460,    -1,   462,   463,    -1,    -1,   428,   429,   346,    -1,
     470,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    99,    -1,    -1,    -1,   495,    -1,    -1,   460,   377,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,   470,   201,
     510,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    99,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,   416,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
     428,   429,    -1,   245,    -1,    -1,    -1,   165,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,     6,    -1,   271,
       9,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,   303,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
     322,   201,   510,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   212,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    82,   346,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,   253,    -1,   377,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,   303,   266,     6,    -1,    -1,
       9,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   322,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,   428,   429,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,   446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   460,   377,
      -1,    -1,   201,    82,    -1,    -1,   346,    -1,   470,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    82,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    99,   377,   416,    -1,
     502,    -1,   504,    -1,    -1,    -1,   245,    -1,   510,    -1,
     428,   429,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,     6,    -1,   264,     9,   266,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
     460,    -1,   201,   322,   502,    -1,   504,    -1,    -1,    -1,
     470,    -1,   510,   212,    -1,    -1,    -1,    -1,   201,    82,
      -1,    -1,    -1,    -1,   484,    -1,    -1,   346,    -1,   212,
     490,    -1,    -1,    -1,    -1,   495,    99,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,   245,    -1,    -1,    -1,
     510,    -1,   251,    -1,   253,    -1,    -1,   256,   377,   258,
     259,   260,   245,    -1,    -1,   264,    -1,   266,   251,    -1,
     253,    -1,   271,   256,    -1,   258,   259,   260,    -1,     6,
      -1,   264,     9,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   322,
      -1,   460,    -1,    -1,    -1,    -1,    -1,   346,    -1,   212,
      -1,   470,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    99,    -1,    -1,    -1,   495,    -1,   377,    -1,
      -1,    -1,   245,   502,    -1,   504,    -1,    -1,   251,    -1,
     253,   510,    -1,   256,   377,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,   201,    -1,    -1,   460,    -1,    -1,
      -1,    -1,    -1,   346,    -1,   212,    -1,   470,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,   490,    -1,    -1,
      -1,   510,   495,    -1,   377,    -1,    -1,    -1,   245,   502,
      -1,   504,    -1,    -1,   251,    -1,   253,   510,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
       1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
     377,    32,    -1,    -1,    35,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,   416,
      -1,    -1,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,   160,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,    -1,   178,   179,   180,
     181,   182,     1,    -1,   185,   186,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,
      -1,    -1,    21,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    36,   219,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,   345,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   175,    -1,    -1,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,
     371,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,   405,    -1,   407,   408,   409,    -1,
      -1,    -1,    -1,   232,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,
     451,    -1,    -1,    -1,    -1,   456,    -1,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,
      -1,    -1,   473,    -1,    -1,    -1,   477,   478,   479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,
     491,    -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,
     319,    -1,    -1,   504,    -1,    -1,    -1,    -1,   327,    -1,
      21,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,   355,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,   407,   408,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
     181,   182,   491,    -1,   185,   186,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    73,
     241,    75,    76,    77,    78,    79,    80,    81,    32,    -1,
      -1,    35,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,   119,    -1,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    99,   405,   189,   407,   408,   409,    -1,
      -1,    -1,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,    -1,   434,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,   232,    -1,
     451,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,    -1,
      -1,   265,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,
     491,    -1,    -1,   277,    -1,    -1,   330,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    82,   343,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,   305,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   318,   319,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,   330,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,   343,
     256,   345,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,    -1,   407,   408,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,
      -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,   407,   408,   409,   322,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,   477,   478,   479,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,   446,    -1,    -1,    -1,    -1,   451,    -1,    -1,
      -1,   245,   456,    -1,    -1,    -1,    99,   251,    -1,   253,
      -1,   377,   256,    -1,   258,   259,   260,    -1,    -1,   473,
     264,    -1,   266,   477,   478,   479,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,
      -1,    -1,    -1,   497,   498,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   458,    82,   460,    -1,   462,   463,    -1,    -1,
      -1,    -1,   346,    -1,   470,    -1,    -1,    -1,   201,    82,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,   490,    -1,    99,    -1,    -1,   495,
      -1,    82,    -1,   377,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    99,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,   416,   266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,
     303,    -1,   201,    -1,   458,    -1,   460,    -1,   462,   463,
      -1,    -1,    -1,   212,    -1,    -1,   470,    -1,   201,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
     201,   495,    -1,   346,    -1,    -1,   245,    -1,   502,    -1,
     504,   212,   251,    -1,   253,    -1,   510,   256,    -1,   258,
     259,   260,   245,    -1,    -1,   264,    -1,   266,   251,    -1,
     253,    -1,    -1,   256,   377,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,   303,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,   322,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,   303,    -1,    -1,   448,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    82,   458,    -1,   460,    -1,   462,
     463,   322,    -1,   346,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    82,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,   346,    -1,   490,    -1,    -1,
      -1,    -1,   495,    99,   377,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,   373,    -1,    -1,    -1,   377,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,   458,
      -1,   460,    -1,   462,   463,    -1,    -1,   428,   429,    -1,
      -1,   470,    -1,   201,    -1,    -1,    -1,   460,    -1,   462,
      -1,    -1,    -1,    -1,   212,    -1,    -1,   470,    -1,    -1,
      -1,   490,    -1,    -1,    -1,   201,   495,    -1,    -1,   460,
      -1,    -1,    -1,   502,    -1,   504,   212,   490,    -1,   470,
      -1,   510,   495,    -1,    -1,    -1,    -1,   245,    -1,   502,
      -1,   504,    -1,   251,    -1,   253,    -1,   510,   256,   490,
     258,   259,   260,    -1,   495,    -1,   264,    -1,   266,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,   470,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,    -1,    -1,   510
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
     603,   535,   523,   451,   232,   537,  1264,   504,  1184,  1184,
     423,   405,  1282,  1264,  1264,  1264,   394,  1184,   405,   451,
     451,  1264,   451,   451,    57,  1252,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1264,  1264,  1264,   504,  1179,  1210,
      68,  1179,   451,  1264,  1264,   549,   560,  1179,   545,   504,
     587,   588,   589,  1185,   256,   307,   309,   573,   575,  1031,
    1213,  1264,   451,   504,   451,   606,   539,   340,  1279,  1264,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1216,
    1179,   256,   218,   306,  1302,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1251,  1312,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1185,  1265,  1031,   232,   423,  1276,  1264,
      96,  1184,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1295,  1210,   400,   401,   410,
      63,  1264,   451,   552,   451,   504,   551,    59,  1264,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1295,   256,
     590,  1214,  1276,   232,  1184,  1184,   574,   575,   451,     1,
     290,   312,  1237,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1216,   328,  1264,   401,  1213,   451,  1264,
     504,  1180,   229,    26,   565,   229,   370,   451,   451,   107,
    1214,  1184,   451,   312,  1184,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1213,   257,   435,
     494,   557,  1180,   256,   272,   608,   454,  1255,    23,  1246,
     102,   648,   451,   582,   583,    57,   505,  1306,   609,   437,
    1288,   188,  1257,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1280,  1296,    86,  1253,   504,  1169,  1170,   451,   394,   650,
     583,   272,  1271,   351,  1280,   446,   497,  1292,   401,   402,
    1264,  1251,   113,   237,  1266,  1266,   287,   635,  1213,  1295,
     423,   262,    39,  1249,  1264,   645,   646,  1170,  1170,   451,
     172,   392,   530,   651,   652,   654,  1264,  1266,   125,   171,
     614,   359,   628,  1264,  1264,  1264,  1264,  1246,     9,   287,
     349,   637,  1264,  1271,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1170,   125,   347,   402,   618,  1264,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1179,  1183,   419,   632,  1179,  1179,   316,  1277,  1277,
     310,  1179,  1264,  1213,   394,   261,   732,   683,   684,   686,
     696,  1229,   451,   653,   632,   256,   616,  1210,   616,     7,
     616,   616,   256,   615,  1210,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1231,  1311,  1255,
    1264,  1178,  1179,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1264,   124,  1178,
    1179,   262,   385,   681,   733,   451,   394,   389,   781,   698,
     689,  1264,  1253,  1264,   351,   353,  1307,  1307,  1264,  1253,
    1264,  1271,  1264,    22,  1245,   306,   678,  1184,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1264,
    1284,    26,   196,   697,  1247,   204,  1213,   504,  1264,  1245,
     504,  1181,  1182,   308,   418,  1303,  1183,  1213,   499,  1264,
     174,   213,   504,   665,  1184,   274,   351,   353,  1305,   681,
     737,   451,   337,   795,   798,   244,   301,   406,   476,  1283,
     476,  1283,   476,  1283,   476,  1283,   476,  1283,   501,  1293,
     384,  1281,  1213,  1207,  1210,  1210,   232,   242,   384,  1267,
    1264,  1265,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1217,
    1218,  1219,   446,   662,  1182,   254,  1270,   446,  1252,   218,
    1259,   504,  1264,  1264,  1305,   738,   782,   122,   821,   822,
     510,   446,   713,   462,  1211,  1212,   442,   706,   727,   728,
    1217,    26,   702,   400,  1241,  1241,  1219,   306,  1274,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1207,   691,   447,  1213,    57,   353,   658,   669,  1213,
     410,  1285,   256,   666,  1210,   666,   348,   739,   686,   696,
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
    1067,  1074,  1078,  1080,  1083,  1086,  1090,  1115,   823,  1213,
     445,  1290,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1157,  1159,  1160,  1161,  1162,  1163,
    1164,  1192,  1206,  1207,  1218,  1220,  1221,  1222,  1223,   462,
    1212,  1210,   726,   728,   442,   256,  1251,   691,   451,  1219,
      48,   465,   670,   671,   672,   673,  1295,  1252,   196,   661,
    1258,   504,  1171,     1,   687,   785,   451,   801,   800,   376,
     807,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1242,   825,   840,   845,   849,   854,   869,   872,   876,
     882,   887,   901,   905,   908,   922,   926,   929,   932,   937,
     941,   951,   954,   971,   973,   976,   399,   980,   986,   998,
    1007,  1011,  1015,  1021,  1029,  1044,  1054,   256,   346,   387,
     416,   510,  1066,  1068,  1075,   336,  1079,  1081,   810,  1084,
    1087,  1091,  1116,   114,   714,   462,  1225,  1207,  1218,  1220,
    1302,  1302,   462,   462,   462,   462,  1302,  1163,  1159,  1163,
     462,  1225,    70,   398,   448,  1158,   449,   458,   463,   450,
     459,   169,   462,  1224,   462,   462,  1159,   501,   729,  1294,
    1217,  1183,  1183,   187,   662,  1213,   740,   451,   786,   451,
      49,   802,   803,   804,  1250,   802,   504,   451,   308,   826,
     827,  1206,     6,    94,   245,   271,   841,  1164,  1188,  1189,
    1206,  1217,  1220,   846,  1159,  1206,   256,   850,   851,  1175,
    1176,  1177,  1210,   271,   422,   424,   855,   856,   256,   870,
    1197,  1206,   873,  1170,     6,   877,  1165,  1166,  1187,  1208,
    1209,  1210,  1218,   454,   883,  1170,   256,   888,   889,   891,
    1188,  1189,  1197,  1206,   902,  1189,   256,   906,   453,   464,
     909,   910,   911,  1147,  1148,  1149,   199,   323,   324,   340,
     394,   923,   927,  1186,  1187,   930,  1210,   446,   933,  1291,
    1146,  1147,   942,  1186,   952,  1171,   955,   956,  1206,  1217,
    1220,  1045,  1204,  1205,  1210,    94,   974,  1189,   977,  1189,
     170,   225,   233,   317,   981,   982,   190,   256,   987,   991,
     992,   993,  1175,  1198,  1206,  1210,  1220,  1295,   999,  1170,
    1008,  1167,  1210,  1012,  1170,  1016,  1167,     9,  1022,  1168,
    1210,   153,   271,  1030,  1033,  1034,  1037,  1038,  1039,  1040,
    1041,  1042,  1172,  1173,  1186,  1203,  1205,  1210,  1045,  1055,
    1170,  1063,   112,  1069,  1070,  1071,  1189,    94,  1076,  1188,
    1082,  1171,   451,   504,   811,   812,   815,   816,   821,  1085,
    1206,  1088,  1170,  1092,  1206,  1117,  1167,   309,  1275,   715,
     716,   448,  1157,  1159,   504,   504,  1159,  1228,  1228,  1228,
    1191,  1206,  1218,  1220,  1227,   504,   448,  1191,  1226,  1159,
     448,  1159,  1160,  1160,  1161,  1161,  1161,  1159,  1191,  1157,
     403,   453,    30,  1248,  1252,     1,   741,   787,   803,   410,
     476,   805,   357,   498,   796,   130,   838,    30,   829,   830,
    1248,   196,  1274,  1206,  1207,  1218,  1220,   131,   843,   446,
     842,  1189,    57,   223,  1232,   851,   446,  1302,   132,   867,
     256,  1198,  1197,  1170,   356,   474,   874,  1295,  1308,  1274,
     133,   878,   159,   452,  1166,  1299,   386,  1238,  1211,  1212,
     884,  1170,   134,   885,  1280,   135,   899,   165,   890,  1126,
    1127,   484,   892,   503,   830,   485,   486,   487,   488,   136,
     903,    49,   228,   497,   857,   137,   920,    17,   501,   912,
     913,   914,   916,    12,    13,    14,    20,   159,   169,   207,
     208,   246,   247,   284,   290,   293,   301,   308,   313,   332,
     448,   450,   452,   455,   457,   458,   459,   462,   463,  1150,
    1151,  1152,  1153,  1154,  1155,  1156,  1189,   101,   203,   376,
     863,   924,  1187,  1174,   441,  1289,   943,  1295,  1171,    92,
     365,   436,   957,   958,   960,   961,  1047,   462,  1211,  1189,
     446,   140,   978,    49,   982,   404,   983,   992,   141,   451,
     988,   990,   481,   499,   442,   445,   439,   143,  1004,   285,
     334,  1235,   196,  1118,   144,  1013,  1280,   145,  1018,  1118,
    1168,   146,  1027,   499,  1023,  1195,  1206,  1218,  1040,  1042,
    1186,   446,  1173,   123,   446,   482,  1032,    31,  1211,   147,
    1061,   177,   237,   240,  1057,   863,  1064,  1295,  1250,   148,
    1073,   228,  1071,  1206,   149,  1077,   196,  1171,   394,   451,
     451,   196,   351,   353,  1089,   150,  1101,   112,  1093,   151,
    1122,  1118,  1179,   220,   718,    27,   115,   717,   448,  1158,
     448,   448,   448,  1158,   448,  1158,   448,   448,   449,   448,
     448,   446,  1264,  1183,   114,   660,   451,    61,    89,    90,
     321,   451,   742,   743,   746,  1264,  1320,    32,    35,    38,
      45,    46,    64,    66,   160,   189,   196,   198,   211,   243,
     252,   265,   305,   318,   345,   371,   378,   395,   446,   456,
     473,   497,   704,   705,   709,   721,   723,   725,   788,   793,
     794,  1264,  1297,  1264,   410,   312,   806,   109,   808,  1195,
     197,   833,   252,   331,   831,   832,  1297,    24,    25,    65,
      67,    69,   103,   104,   105,   153,   155,   162,   165,   252,
     254,   443,   493,   504,   828,  1173,  1298,   152,   340,  1193,
    1207,   446,     6,  1165,  1189,  1210,  1218,   203,   223,  1233,
     376,   847,   339,   852,  1177,   857,   874,   262,   287,  1257,
    1207,  1159,   272,  1239,  1212,  1170,   231,  1142,  1143,   818,
     819,   891,  1189,   294,  1128,    96,   335,   504,  1173,   298,
     896,    35,    38,    45,    46,    91,   160,   189,   211,   265,
     318,   378,   391,   473,   897,   898,   484,   893,  1126,  1126,
    1126,  1126,  1189,  1165,  1189,   858,   911,    21,   453,   464,
     917,   918,  1148,   501,   914,   915,   501,   818,  1291,   232,
    1151,  1189,   114,   934,  1175,   128,   818,   938,     9,    12,
      15,    16,   277,   278,   301,   302,   944,   948,   175,  1195,
       9,    57,   177,   241,   468,   964,   965,   966,   959,   960,
    1049,  1275,  1311,   446,  1186,  1165,  1189,   983,  1295,  1169,
     818,   168,   994,  1146,   995,   996,  1206,  1175,     8,    37,
    1120,  1280,  1202,  1206,  1217,  1220,   228,  1000,  1017,  1295,
     129,  1024,  1206,  1024,   446,   446,  1031,   152,   453,   464,
    1189,    49,    38,    46,   211,   243,   265,   318,   378,   473,
    1035,  1036,  1264,  1056,  1295,  1189,   161,   289,   410,  1189,
    1206,   196,  1165,  1189,   817,  1213,  1195,  1250,   228,  1096,
    1119,  1120,  1250,  1266,  1179,  1224,  1224,  1224,  1191,   241,
     468,  1224,   448,  1159,  1224,  1224,  1217,  1275,  1264,  1264,
    1245,   248,   249,  1269,   755,   204,   176,   744,  1256,  1264,
     252,   389,   156,   158,  1264,  1198,   299,  1272,  1213,    56,
    1206,  1206,   204,  1272,    32,   110,  1213,  1264,   504,   451,
     797,   272,   834,  1272,  1272,   832,   831,  1272,   165,  1123,
    1124,   509,   508,  1195,  1123,   237,   423,   299,   276,   256,
    1194,  1207,  1206,  1274,   411,  1129,  1130,  1211,  1212,  1165,
     446,  1234,   847,  1187,   446,  1175,   862,   863,   380,   362,
    1129,  1264,   818,   295,  1144,   820,   818,  1126,  1264,   252,
     389,   156,   158,  1264,   123,   482,   898,  1126,    96,    97,
     894,   834,   203,  1129,   203,   859,   860,   861,  1250,    17,
     442,   919,   316,   917,  1275,   818,   128,   139,   939,  1291,
     365,   945,  1291,   446,    49,   965,   967,  1195,     9,    57,
     241,   468,   962,   963,  1195,  1050,  1296,   717,   218,   314,
    1260,  1186,  1129,   203,  1169,   637,   379,   984,  1295,   141,
     989,     8,   196,  1000,  1206,   129,  1135,  1137,  1142,   262,
     287,   818,   501,   501,  1025,  1026,  1195,  1194,  1189,  1031,
    1031,  1031,  1031,  1031,  1031,  1031,  1031,  1036,   290,   293,
    1058,  1059,  1060,  1152,  1236,  1142,   244,   410,  1310,   423,
    1287,  1287,  1072,  1295,  1206,  1129,   203,   451,   446,     9,
    1094,  1095,  1230,  1097,  1206,  1072,  1097,  1017,     7,  1243,
     504,   719,   720,  1264,   448,  1179,  1197,  1264,  1245,   256,
     747,  1215,   686,   756,   745,  1206,   510,  1199,  1203,  1213,
    1199,  1264,  1290,  1264,  1264,    32,  1213,   809,   810,  1264,
     503,   835,  1199,  1199,  1199,   818,   294,  1125,  1123,  1238,
    1207,   818,   297,  1131,  1212,  1129,  1196,  1206,  1217,   165,
     461,   865,  1301,     6,   228,   308,   460,   864,  1263,    34,
     281,   282,   283,   344,   466,   467,   471,  1240,   818,   821,
    1199,  1199,  1145,  1201,  1203,  1213,  1145,   503,   895,  1165,
    1166,  1165,  1166,   860,   308,   805,    87,   357,   498,   918,
    1147,   818,  1206,   818,   498,   946,   947,   948,   949,  1289,
     498,  1196,  1195,    49,   968,   963,   188,   968,  1046,  1264,
    1266,   314,  1165,   984,   262,   287,   996,  1189,   217,  1001,
    1295,   818,   291,  1138,   262,  1147,  1146,  1025,  1152,  1206,
    1153,  1154,  1155,  1156,  1159,  1065,  1189,  1065,   461,  1132,
    1133,   330,  1238,  1165,   813,  1196,   313,  1195,   113,  1098,
     436,  1100,   157,   292,  1121,  1139,  1140,  1141,  1142,   321,
    1173,  1199,   720,  1178,   748,   252,   254,  1304,   504,   687,
    1206,   270,   329,   458,   463,   789,   790,   791,  1197,   789,
     790,   792,   810,    47,    32,    35,    38,    46,    91,   189,
     198,   211,   243,   263,   265,   288,   318,   345,   371,   378,
     391,   395,   444,   473,   483,   489,   836,   837,  1123,   818,
    1129,   818,   294,   866,   818,  1274,  1206,   252,   254,  1309,
     897,  1129,   361,  1129,   361,  1189,   947,   102,  1254,  1291,
     968,   968,  1196,     8,    37,   969,   225,   497,  1051,  1179,
    1048,  1129,   380,    49,   262,   237,  1002,   216,   236,   262,
     287,   500,   818,   818,   818,   818,   296,  1134,  1264,  1129,
    1129,   492,   814,  1102,  1095,  1259,    95,  1099,  1259,  1132,
     818,   818,  1141,   252,   254,  1268,   177,   187,   210,   240,
     749,   750,   751,   752,   753,   754,  1215,   757,  1199,  1199,
     129,  1264,  1264,    56,   123,   482,     8,  1244,   837,   818,
    1206,  1166,  1166,    49,   110,   968,   456,  1262,  1262,   337,
    1169,   203,   317,  1052,  1210,  1189,  1264,  1003,  1136,  1137,
    1138,  1142,   262,   262,   262,   818,  1206,  1103,   451,  1206,
    1259,  1206,   106,   116,  1313,  1264,  1264,    54,    89,  1313,
    1314,  1298,   758,   109,  1199,  1199,  1264,  1145,  1145,  1200,
    1203,  1215,  1129,  1129,  1189,  1189,  1189,  1264,  1169,   337,
     481,  1206,  1138,   127,   166,   204,  1104,  1105,  1106,  1108,
    1112,  1113,  1114,  1257,  1206,  1264,  1215,  1215,   210,  1264,
    1264,   209,   252,   254,   285,   305,   333,   414,   431,   451,
     472,   491,   499,   704,   709,   710,   721,   723,   725,   759,
     760,   764,   765,   768,   769,   770,   771,   772,   773,   778,
     779,   780,  1297,  1298,   451,  1197,   991,  1264,  1146,    37,
    1244,   107,  1215,  1215,  1215,   221,  1261,   299,   300,  1273,
    1245,   209,  1213,   501,  1264,  1274,  1264,  1264,  1206,   286,
     329,   774,   775,  1215,   329,   776,   777,  1215,  1273,  1245,
     991,   367,   418,  1286,  1275,  1265,  1264,   713,  1146,  1192,
    1190,  1192,    53,    89,   321,   325,   326,   366,   382,   383,
     761,  1313,  1314,  1315,  1316,  1317,  1318,  1319,   119,   196,
    1213,   775,  1213,   777,  1265,  1206,   161,   165,  1300,     9,
    1109,  1110,  1176,   775,  1290,  1238,   373,   766,  1192,   187,
     187,   210,   187,   210,   176,   762,  1206,   762,  1192,   337,
    1278,   306,   338,   358,  1111,  1110,   714,  1275,   313,   763,
     763,    49,  1275,   306,  1210,   425,   711,   176,   767,  1206,
     321,  1192,   170,   225,   233,   317,  1107,  1169,  1213
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
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


/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
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
  *++yyvsp = yylval;

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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 1504 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1510 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1522 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 1563 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1570 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1609 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1610 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1619 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1628 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1642 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1646 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1656 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1665 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if (current_program->nested_level) {
		cb_error (_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1690 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1708 "parser.y"
    {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item ();
  }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 1721 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1750 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1757 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1764 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1771 "parser.y"
    {
	if (current_program->classification) {
		cb_error (_("Duplicate CLASSIFICATION clause"));
	} else {
		current_program->classification = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1782 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1786 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1790 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1794 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1808 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1813 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1821 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1833 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1837 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1858 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1862 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1869 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1874 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1885 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1899 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1930 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1949 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1959 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1972 "parser.y"
    {
	if (save_tree && CB_VALID_TREE ((yyvsp[(2) - (3)]))) {
		cb_define ((yyvsp[(2) - (3)]), save_tree);
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
				(yyvsp[(2) - (3)]), save_tree);
	}
  }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1988 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 1998 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2013 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2026 "parser.y"
    {
	if ((yyvsp[(3) - (5)])) {
		current_program->alphabet_name_list =
			cb_list_add (current_program->alphabet_name_list, (yyvsp[(3) - (5)]));
	}
	cobc_cs_check = 0;
  }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 2037 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2043 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2049 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2055 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2061 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2067 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2077 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2081 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2088 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2092 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2096 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2100 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2107 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 2111 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2117 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2118 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2119 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2120 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2121 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2122 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2130 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2144 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 2148 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 2156 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 2163 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 2167 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 2178 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2198 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 2206 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 2216 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2217 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 2224 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2244 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2245 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2250 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2254 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2275 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2298 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2379 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2383 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2392 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2411 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2427 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2445 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2463 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2480 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2497 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2505 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2514 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2529 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2546 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2550 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2584 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2590 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2600 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2613 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2626 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2649 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2656 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2669 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2681 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2688 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2689 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2690 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2698 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2725 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2736 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2751 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2759 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2764 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2769 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2778 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2782 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2798 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2803 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2808 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2813 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2824 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2835 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2845 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2852 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2853 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2854 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2861 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2872 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2886 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2893 "parser.y"
    { (yyval) = NULL; }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2894 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2895 "parser.y"
    { (yyval) = NULL; }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2904 "parser.y"
    {
	yyerrok;
  }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2923 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 2950 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2951 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2952 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2953 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 2960 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2965 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 2992 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3001 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 3015 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3034 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3051 "parser.y"
    {
	yyerrok;
  }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3058 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3062 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3073 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3083 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3113 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 3126 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3146 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3181 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3212 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 3218 "parser.y"
    { (yyval) = NULL; }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 3219 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 3223 "parser.y"
    { (yyval) = NULL; }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 3224 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3232 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3243 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3248 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 3271 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3283 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3311 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 3318 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 3325 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3334 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3346 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3398 "parser.y"
    {
	check_repeated ("REPORT", SYN_CLAUSE_11);
	cb_warning (_("REPORT WRITER not implemented"));
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

/* Line 1806 of yacc.c  */
#line 3418 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3428 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3468 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 3474 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 3483 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 3486 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 3492 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 3512 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3527 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3547 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3560 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3567 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 3573 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 3579 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 3588 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 3597 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 3601 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3612 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 3613 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 3614 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 3615 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3620 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3624 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3628 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3632 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3636 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 3640 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 3644 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 3648 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 3652 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 3656 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 3660 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 3664 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 3668 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 3700 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3726 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 3730 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 3738 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3744 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 3772 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3796 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3823 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 3827 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 3836 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3861 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 3877 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 3881 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 3885 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 3889 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 3893 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3897 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 3901 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 3905 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 3909 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 3913 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 3917 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 3921 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 3925 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 3930 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 3935 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 3939 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 3943 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 3951 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 3955 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 3959 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 3967 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 3971 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 3975 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 3979 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 3983 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 3987 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 3991 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 3995 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 3999 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 4007 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 4015 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 4019 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 4023 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 4027 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 4031 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 4035 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 4055 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 4061 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 4074 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4092 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 4102 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4124 "parser.y"
    { (yyval) = NULL; }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 4125 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 4130 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 4137 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4160 "parser.y"
    { (yyval) = NULL; }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 4163 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4178 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 4179 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 4184 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 4190 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 4192 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 4197 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 4208 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 4219 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 4230 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 4241 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4269 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 4277 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 4278 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 4282 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 4283 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 4288 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 4301 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4314 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4335 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4344 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4359 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4368 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 4380 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 4386 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 4397 "parser.y"
    {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 4413 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4428 "parser.y"
    {
	yyerrok;
  }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 4435 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 4440 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 4451 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 4470 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4506 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 4510 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 4515 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  }
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 4535 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 4542 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 4549 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 4556 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 4563 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 4574 "parser.y"
    {
	check_pic_duplicate = 0;
  }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 4605 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 4631 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 4638 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  }
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 4654 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 4665 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 4677 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 4710 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  }
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 4717 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  }
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 4724 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 4733 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 4740 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4766 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4797 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4823 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4846 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 4850 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 4854 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 4858 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 4862 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 4866 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 4870 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 4874 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 4878 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 4882 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 4886 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 4890 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 4894 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 4898 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 4902 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 4906 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 4910 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 4915 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 619:

/* Line 1806 of yacc.c  */
#line 4919 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 4923 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 4928 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 4933 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 4938 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 4951 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 4958 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 4963 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 4982 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 4986 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 4990 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 4997 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 5001 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 5005 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 5013 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 5024 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 5033 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5043 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5055 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5070 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5103 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 5107 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 5112 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 5120 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5129 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 5139 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 5141 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 5146 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 5155 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 5159 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 5171 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 5179 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 5187 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 5195 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5224 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5257 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 5266 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 5272 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5300 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 5306 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5343 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5361 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 684:

/* Line 1806 of yacc.c  */
#line 5371 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5415 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 5426 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5474 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5486 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 691:

/* Line 1806 of yacc.c  */
#line 5490 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5508 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 693:

/* Line 1806 of yacc.c  */
#line 5513 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 694:

/* Line 1806 of yacc.c  */
#line 5518 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 695:

/* Line 1806 of yacc.c  */
#line 5526 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5553 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 697:

/* Line 1806 of yacc.c  */
#line 5557 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 747:

/* Line 1806 of yacc.c  */
#line 5613 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5627 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 749:

/* Line 1806 of yacc.c  */
#line 5638 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 751:

/* Line 1806 of yacc.c  */
#line 5648 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 752:

/* Line 1806 of yacc.c  */
#line 5653 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 753:

/* Line 1806 of yacc.c  */
#line 5657 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 754:

/* Line 1806 of yacc.c  */
#line 5661 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 755:

/* Line 1806 of yacc.c  */
#line 5666 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 756:

/* Line 1806 of yacc.c  */
#line 5671 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 757:

/* Line 1806 of yacc.c  */
#line 5676 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 758:

/* Line 1806 of yacc.c  */
#line 5681 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 759:

/* Line 1806 of yacc.c  */
#line 5685 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 760:

/* Line 1806 of yacc.c  */
#line 5689 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 761:

/* Line 1806 of yacc.c  */
#line 5693 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 762:

/* Line 1806 of yacc.c  */
#line 5697 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 763:

/* Line 1806 of yacc.c  */
#line 5702 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 764:

/* Line 1806 of yacc.c  */
#line 5706 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 765:

/* Line 1806 of yacc.c  */
#line 5710 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 766:

/* Line 1806 of yacc.c  */
#line 5714 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 767:

/* Line 1806 of yacc.c  */
#line 5718 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 768:

/* Line 1806 of yacc.c  */
#line 5722 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 769:

/* Line 1806 of yacc.c  */
#line 5726 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 771:

/* Line 1806 of yacc.c  */
#line 5734 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 774:

/* Line 1806 of yacc.c  */
#line 5745 "parser.y"
    { (yyval) = NULL; }
    break;

  case 775:

/* Line 1806 of yacc.c  */
#line 5746 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 776:

/* Line 1806 of yacc.c  */
#line 5750 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 777:

/* Line 1806 of yacc.c  */
#line 5751 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 778:

/* Line 1806 of yacc.c  */
#line 5752 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 779:

/* Line 1806 of yacc.c  */
#line 5753 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 780:

/* Line 1806 of yacc.c  */
#line 5754 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 781:

/* Line 1806 of yacc.c  */
#line 5758 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 782:

/* Line 1806 of yacc.c  */
#line 5762 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 783:

/* Line 1806 of yacc.c  */
#line 5763 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 787:

/* Line 1806 of yacc.c  */
#line 5772 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 792:

/* Line 1806 of yacc.c  */
#line 5788 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 793:

/* Line 1806 of yacc.c  */
#line 5792 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 794:

/* Line 1806 of yacc.c  */
#line 5796 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 795:

/* Line 1806 of yacc.c  */
#line 5800 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 796:

/* Line 1806 of yacc.c  */
#line 5804 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 797:

/* Line 1806 of yacc.c  */
#line 5808 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 798:

/* Line 1806 of yacc.c  */
#line 5812 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 799:

/* Line 1806 of yacc.c  */
#line 5816 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 800:

/* Line 1806 of yacc.c  */
#line 5820 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 801:

/* Line 1806 of yacc.c  */
#line 5824 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 802:

/* Line 1806 of yacc.c  */
#line 5828 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 803:

/* Line 1806 of yacc.c  */
#line 5832 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 804:

/* Line 1806 of yacc.c  */
#line 5836 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 805:

/* Line 1806 of yacc.c  */
#line 5840 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 806:

/* Line 1806 of yacc.c  */
#line 5844 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 807:

/* Line 1806 of yacc.c  */
#line 5848 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 808:

/* Line 1806 of yacc.c  */
#line 5852 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 809:

/* Line 1806 of yacc.c  */
#line 5856 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 810:

/* Line 1806 of yacc.c  */
#line 5860 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 811:

/* Line 1806 of yacc.c  */
#line 5864 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 812:

/* Line 1806 of yacc.c  */
#line 5868 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 813:

/* Line 1806 of yacc.c  */
#line 5872 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 814:

/* Line 1806 of yacc.c  */
#line 5876 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 815:

/* Line 1806 of yacc.c  */
#line 5880 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 816:

/* Line 1806 of yacc.c  */
#line 5887 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 817:

/* Line 1806 of yacc.c  */
#line 5891 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 818:

/* Line 1806 of yacc.c  */
#line 5901 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 820:

/* Line 1806 of yacc.c  */
#line 5910 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 821:

/* Line 1806 of yacc.c  */
#line 5914 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 822:

/* Line 1806 of yacc.c  */
#line 5918 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 824:

/* Line 1806 of yacc.c  */
#line 5925 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 825:

/* Line 1806 of yacc.c  */
#line 5932 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 826:

/* Line 1806 of yacc.c  */
#line 5936 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 827:

/* Line 1806 of yacc.c  */
#line 5946 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 829:

/* Line 1806 of yacc.c  */
#line 5955 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 830:

/* Line 1806 of yacc.c  */
#line 5959 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 5970 "parser.y"
    { (yyval) = NULL; }
    break;

  case 832:

/* Line 1806 of yacc.c  */
#line 5971 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 833:

/* Line 1806 of yacc.c  */
#line 5979 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 837:

/* Line 1806 of yacc.c  */
#line 5993 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 840:

/* Line 1806 of yacc.c  */
#line 6005 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 842:

/* Line 1806 of yacc.c  */
#line 6020 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6034 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 844:

/* Line 1806 of yacc.c  */
#line 6039 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 845:

/* Line 1806 of yacc.c  */
#line 6044 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 846:

/* Line 1806 of yacc.c  */
#line 6049 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6069 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 848:

/* Line 1806 of yacc.c  */
#line 6073 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 849:

/* Line 1806 of yacc.c  */
#line 6078 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6089 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 851:

/* Line 1806 of yacc.c  */
#line 6091 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 852:

/* Line 1806 of yacc.c  */
#line 6096 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 853:

/* Line 1806 of yacc.c  */
#line 6104 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6130 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 856:

/* Line 1806 of yacc.c  */
#line 6134 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 857:

/* Line 1806 of yacc.c  */
#line 6143 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 858:

/* Line 1806 of yacc.c  */
#line 6155 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 859:

/* Line 1806 of yacc.c  */
#line 6159 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 860:

/* Line 1806 of yacc.c  */
#line 6163 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 861:

/* Line 1806 of yacc.c  */
#line 6167 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6200 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 867:

/* Line 1806 of yacc.c  */
#line 6205 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 868:

/* Line 1806 of yacc.c  */
#line 6212 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 869:

/* Line 1806 of yacc.c  */
#line 6217 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 870:

/* Line 1806 of yacc.c  */
#line 6224 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 871:

/* Line 1806 of yacc.c  */
#line 6228 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 872:

/* Line 1806 of yacc.c  */
#line 6238 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 874:

/* Line 1806 of yacc.c  */
#line 6246 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 875:

/* Line 1806 of yacc.c  */
#line 6250 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 876:

/* Line 1806 of yacc.c  */
#line 6260 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 878:

/* Line 1806 of yacc.c  */
#line 6268 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 879:

/* Line 1806 of yacc.c  */
#line 6273 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 880:

/* Line 1806 of yacc.c  */
#line 6280 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 881:

/* Line 1806 of yacc.c  */
#line 6281 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 882:

/* Line 1806 of yacc.c  */
#line 6282 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 883:

/* Line 1806 of yacc.c  */
#line 6283 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 884:

/* Line 1806 of yacc.c  */
#line 6284 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 885:

/* Line 1806 of yacc.c  */
#line 6292 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 887:

/* Line 1806 of yacc.c  */
#line 6301 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 888:

/* Line 1806 of yacc.c  */
#line 6308 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 889:

/* Line 1806 of yacc.c  */
#line 6312 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 890:

/* Line 1806 of yacc.c  */
#line 6322 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 891:

/* Line 1806 of yacc.c  */
#line 6333 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6350 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 894:

/* Line 1806 of yacc.c  */
#line 6359 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 896:

/* Line 1806 of yacc.c  */
#line 6367 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 897:

/* Line 1806 of yacc.c  */
#line 6372 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 898:

/* Line 1806 of yacc.c  */
#line 6380 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 899:

/* Line 1806 of yacc.c  */
#line 6384 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 900:

/* Line 1806 of yacc.c  */
#line 6394 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 902:

/* Line 1806 of yacc.c  */
#line 6404 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 903:

/* Line 1806 of yacc.c  */
#line 6408 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 904:

/* Line 1806 of yacc.c  */
#line 6412 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 905:

/* Line 1806 of yacc.c  */
#line 6416 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 906:

/* Line 1806 of yacc.c  */
#line 6420 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 908:

/* Line 1806 of yacc.c  */
#line 6425 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 910:

/* Line 1806 of yacc.c  */
#line 6435 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 912:

/* Line 1806 of yacc.c  */
#line 6443 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 913:

/* Line 1806 of yacc.c  */
#line 6451 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 914:

/* Line 1806 of yacc.c  */
#line 6459 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 915:

/* Line 1806 of yacc.c  */
#line 6463 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 916:

/* Line 1806 of yacc.c  */
#line 6467 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 917:

/* Line 1806 of yacc.c  */
#line 6471 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 923:

/* Line 1806 of yacc.c  */
#line 6493 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 924:

/* Line 1806 of yacc.c  */
#line 6499 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 925:

/* Line 1806 of yacc.c  */
#line 6500 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 928:

/* Line 1806 of yacc.c  */
#line 6511 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 929:

/* Line 1806 of yacc.c  */
#line 6515 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 930:

/* Line 1806 of yacc.c  */
#line 6519 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 931:

/* Line 1806 of yacc.c  */
#line 6523 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 932:

/* Line 1806 of yacc.c  */
#line 6527 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 933:

/* Line 1806 of yacc.c  */
#line 6531 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 934:

/* Line 1806 of yacc.c  */
#line 6535 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 935:

/* Line 1806 of yacc.c  */
#line 6539 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 936:

/* Line 1806 of yacc.c  */
#line 6543 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 937:

/* Line 1806 of yacc.c  */
#line 6547 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 938:

/* Line 1806 of yacc.c  */
#line 6551 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 939:

/* Line 1806 of yacc.c  */
#line 6555 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 940:

/* Line 1806 of yacc.c  */
#line 6559 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 941:

/* Line 1806 of yacc.c  */
#line 6563 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 942:

/* Line 1806 of yacc.c  */
#line 6567 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 943:

/* Line 1806 of yacc.c  */
#line 6571 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 944:

/* Line 1806 of yacc.c  */
#line 6578 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 945:

/* Line 1806 of yacc.c  */
#line 6582 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 946:

/* Line 1806 of yacc.c  */
#line 6592 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 948:

/* Line 1806 of yacc.c  */
#line 6601 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 949:

/* Line 1806 of yacc.c  */
#line 6605 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 950:

/* Line 1806 of yacc.c  */
#line 6609 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 951:

/* Line 1806 of yacc.c  */
#line 6613 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 952:

/* Line 1806 of yacc.c  */
#line 6617 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 953:

/* Line 1806 of yacc.c  */
#line 6624 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 954:

/* Line 1806 of yacc.c  */
#line 6628 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 955:

/* Line 1806 of yacc.c  */
#line 6638 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 957:

/* Line 1806 of yacc.c  */
#line 6646 "parser.y"
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

  case 958:

/* Line 1806 of yacc.c  */
#line 6665 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6689 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 961:

/* Line 1806 of yacc.c  */
#line 6696 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 962:

/* Line 1806 of yacc.c  */
#line 6698 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 963:

/* Line 1806 of yacc.c  */
#line 6703 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6714 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6725 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6739 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 967:

/* Line 1806 of yacc.c  */
#line 6743 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 968:

/* Line 1806 of yacc.c  */
#line 6749 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 969:

/* Line 1806 of yacc.c  */
#line 6751 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 970:

/* Line 1806 of yacc.c  */
#line 6757 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 971:

/* Line 1806 of yacc.c  */
#line 6766 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 972:

/* Line 1806 of yacc.c  */
#line 6774 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 973:

/* Line 1806 of yacc.c  */
#line 6780 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 974:

/* Line 1806 of yacc.c  */
#line 6787 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 975:

/* Line 1806 of yacc.c  */
#line 6789 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 976:

/* Line 1806 of yacc.c  */
#line 6794 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6855 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 978:

/* Line 1806 of yacc.c  */
#line 6856 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 979:

/* Line 1806 of yacc.c  */
#line 6857 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 980:

/* Line 1806 of yacc.c  */
#line 6861 "parser.y"
    { (yyval) = NULL; }
    break;

  case 981:

/* Line 1806 of yacc.c  */
#line 6862 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 982:

/* Line 1806 of yacc.c  */
#line 6867 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 983:

/* Line 1806 of yacc.c  */
#line 6871 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 984:

/* Line 1806 of yacc.c  */
#line 6881 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 985:

/* Line 1806 of yacc.c  */
#line 6886 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 987:

/* Line 1806 of yacc.c  */
#line 6894 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6915 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6929 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6951 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6973 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 6993 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 7015 "parser.y"
    { (yyval) = NULL; }
    break;

  case 994:

/* Line 1806 of yacc.c  */
#line 7016 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 995:

/* Line 1806 of yacc.c  */
#line 7024 "parser.y"
    {
	begin_statement ("FREE", 0);
  }
    break;

  case 997:

/* Line 1806 of yacc.c  */
#line 7032 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 998:

/* Line 1806 of yacc.c  */
#line 7042 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  }
    break;

  case 1001:

/* Line 1806 of yacc.c  */
#line 7058 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 7071 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1004:

/* Line 1806 of yacc.c  */
#line 7079 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1005:

/* Line 1806 of yacc.c  */
#line 7084 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1006:

/* Line 1806 of yacc.c  */
#line 7095 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	cb_emit_exit (1U);
  }
    break;

  case 1007:

/* Line 1806 of yacc.c  */
#line 7107 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1009:

/* Line 1806 of yacc.c  */
#line 7116 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1010:

/* Line 1806 of yacc.c  */
#line 7120 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1011:

/* Line 1806 of yacc.c  */
#line 7124 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1012:

/* Line 1806 of yacc.c  */
#line 7131 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1013:

/* Line 1806 of yacc.c  */
#line 7135 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7145 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1016:

/* Line 1806 of yacc.c  */
#line 7154 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7160 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1018:

/* Line 1806 of yacc.c  */
#line 7161 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1019:

/* Line 1806 of yacc.c  */
#line 7165 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7166 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7167 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7172 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7176 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7183 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1025:

/* Line 1806 of yacc.c  */
#line 7188 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7195 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7201 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7202 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7203 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7204 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7205 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1032:

/* Line 1806 of yacc.c  */
#line 7206 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7207 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7212 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1035:

/* Line 1806 of yacc.c  */
#line 7216 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7225 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7234 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1039:

/* Line 1806 of yacc.c  */
#line 7240 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1040:

/* Line 1806 of yacc.c  */
#line 7251 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7264 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1044:

/* Line 1806 of yacc.c  */
#line 7268 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1045:

/* Line 1806 of yacc.c  */
#line 7272 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1050:

/* Line 1806 of yacc.c  */
#line 7288 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1051:

/* Line 1806 of yacc.c  */
#line 7292 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1052:

/* Line 1806 of yacc.c  */
#line 7302 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1053:

/* Line 1806 of yacc.c  */
#line 7312 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1054:

/* Line 1806 of yacc.c  */
#line 7320 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7321 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1056:

/* Line 1806 of yacc.c  */
#line 7325 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1057:

/* Line 1806 of yacc.c  */
#line 7326 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1058:

/* Line 1806 of yacc.c  */
#line 7327 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1059:

/* Line 1806 of yacc.c  */
#line 7328 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7329 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7330 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7334 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1063:

/* Line 1806 of yacc.c  */
#line 7335 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1064:

/* Line 1806 of yacc.c  */
#line 7340 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1065:

/* Line 1806 of yacc.c  */
#line 7345 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1066:

/* Line 1806 of yacc.c  */
#line 7351 "parser.y"
    { /* Nothing */ }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7352 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7353 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7354 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7355 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 7387 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7391 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7398 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1075:

/* Line 1806 of yacc.c  */
#line 7402 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1076:

/* Line 1806 of yacc.c  */
#line 7411 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7423 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1080:

/* Line 1806 of yacc.c  */
#line 7431 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1081:

/* Line 1806 of yacc.c  */
#line 7435 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1082:

/* Line 1806 of yacc.c  */
#line 7445 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7454 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7458 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1086:

/* Line 1806 of yacc.c  */
#line 7465 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1087:

/* Line 1806 of yacc.c  */
#line 7469 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7479 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7487 "parser.y"
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

  case 1091:

/* Line 1806 of yacc.c  */
#line 7508 "parser.y"
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

  case 1092:

/* Line 1806 of yacc.c  */
#line 7531 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1093:

/* Line 1806 of yacc.c  */
#line 7532 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1094:

/* Line 1806 of yacc.c  */
#line 7533 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1095:

/* Line 1806 of yacc.c  */
#line 7534 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1096:

/* Line 1806 of yacc.c  */
#line 7538 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7539 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7543 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1099:

/* Line 1806 of yacc.c  */
#line 7544 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1100:

/* Line 1806 of yacc.c  */
#line 7545 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1101:

/* Line 1806 of yacc.c  */
#line 7547 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1102:

/* Line 1806 of yacc.c  */
#line 7558 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7569 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7574 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1106:

/* Line 1806 of yacc.c  */
#line 7580 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7585 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1108:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 7601 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1110:

/* Line 1806 of yacc.c  */
#line 7608 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 7625 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 7643 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1115:

/* Line 1806 of yacc.c  */
#line 7647 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1116:

/* Line 1806 of yacc.c  */
#line 7652 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 7667 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1119:

/* Line 1806 of yacc.c  */
#line 7673 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1120:

/* Line 1806 of yacc.c  */
#line 7674 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1121:

/* Line 1806 of yacc.c  */
#line 7678 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7679 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7682 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7684 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1125:

/* Line 1806 of yacc.c  */
#line 7689 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7699 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 7734 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1130:

/* Line 1806 of yacc.c  */
#line 7735 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1131:

/* Line 1806 of yacc.c  */
#line 7740 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1132:

/* Line 1806 of yacc.c  */
#line 7744 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7748 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1134:

/* Line 1806 of yacc.c  */
#line 7752 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1135:

/* Line 1806 of yacc.c  */
#line 7756 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1136:

/* Line 1806 of yacc.c  */
#line 7760 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7764 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1138:

/* Line 1806 of yacc.c  */
#line 7770 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1139:

/* Line 1806 of yacc.c  */
#line 7771 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1142:

/* Line 1806 of yacc.c  */
#line 7781 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1143:

/* Line 1806 of yacc.c  */
#line 7785 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1144:

/* Line 1806 of yacc.c  */
#line 7795 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7805 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1147:

/* Line 1806 of yacc.c  */
#line 7813 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1148:

/* Line 1806 of yacc.c  */
#line 7823 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1149:

/* Line 1806 of yacc.c  */
#line 7833 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 7842 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 7849 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1153:

/* Line 1806 of yacc.c  */
#line 7853 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1154:

/* Line 1806 of yacc.c  */
#line 7863 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 7875 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1157:

/* Line 1806 of yacc.c  */
#line 7883 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1158:

/* Line 1806 of yacc.c  */
#line 7887 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1159:

/* Line 1806 of yacc.c  */
#line 7891 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 7898 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 7902 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1162:

/* Line 1806 of yacc.c  */
#line 7912 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1163:

/* Line 1806 of yacc.c  */
#line 7923 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 7932 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 7937 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1167:

/* Line 1806 of yacc.c  */
#line 7944 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1168:

/* Line 1806 of yacc.c  */
#line 7945 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 7950 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 7955 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1171:

/* Line 1806 of yacc.c  */
#line 7962 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1172:

/* Line 1806 of yacc.c  */
#line 7966 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 7974 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 7981 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 7985 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1176:

/* Line 1806 of yacc.c  */
#line 7995 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1177:

/* Line 1806 of yacc.c  */
#line 8002 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1184:

/* Line 1806 of yacc.c  */
#line 8017 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1185:

/* Line 1806 of yacc.c  */
#line 8018 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1186:

/* Line 1806 of yacc.c  */
#line 8022 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1187:

/* Line 1806 of yacc.c  */
#line 8023 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1188:

/* Line 1806 of yacc.c  */
#line 8030 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1189:

/* Line 1806 of yacc.c  */
#line 8039 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1192:

/* Line 1806 of yacc.c  */
#line 8051 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1193:

/* Line 1806 of yacc.c  */
#line 8055 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1194:

/* Line 1806 of yacc.c  */
#line 8059 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1195:

/* Line 1806 of yacc.c  */
#line 8063 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1196:

/* Line 1806 of yacc.c  */
#line 8067 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1197:

/* Line 1806 of yacc.c  */
#line 8071 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1198:

/* Line 1806 of yacc.c  */
#line 8075 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1199:

/* Line 1806 of yacc.c  */
#line 8079 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1200:

/* Line 1806 of yacc.c  */
#line 8088 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1201:

/* Line 1806 of yacc.c  */
#line 8092 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1202:

/* Line 1806 of yacc.c  */
#line 8101 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1205:

/* Line 1806 of yacc.c  */
#line 8115 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1208:

/* Line 1806 of yacc.c  */
#line 8129 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1209:

/* Line 1806 of yacc.c  */
#line 8133 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1210:

/* Line 1806 of yacc.c  */
#line 8143 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8172 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1214:

/* Line 1806 of yacc.c  */
#line 8181 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8204 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1217:

/* Line 1806 of yacc.c  */
#line 8205 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1219:

/* Line 1806 of yacc.c  */
#line 8210 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1220:

/* Line 1806 of yacc.c  */
#line 8217 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1221:

/* Line 1806 of yacc.c  */
#line 8218 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8223 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1223:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8254 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1226:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8286 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1230:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8308 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1232:

/* Line 1806 of yacc.c  */
#line 8312 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1233:

/* Line 1806 of yacc.c  */
#line 8319 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1234:

/* Line 1806 of yacc.c  */
#line 8323 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1235:

/* Line 1806 of yacc.c  */
#line 8328 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1236:

/* Line 1806 of yacc.c  */
#line 8333 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1237:

/* Line 1806 of yacc.c  */
#line 8340 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1238:

/* Line 1806 of yacc.c  */
#line 8341 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8342 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1240:

/* Line 1806 of yacc.c  */
#line 8343 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1241:

/* Line 1806 of yacc.c  */
#line 8344 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1242:

/* Line 1806 of yacc.c  */
#line 8345 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1243:

/* Line 1806 of yacc.c  */
#line 8350 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1246:

/* Line 1806 of yacc.c  */
#line 8363 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1247:

/* Line 1806 of yacc.c  */
#line 8367 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1248:

/* Line 1806 of yacc.c  */
#line 8377 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8381 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8399 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1252:

/* Line 1806 of yacc.c  */
#line 8403 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8426 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8430 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1257:

/* Line 1806 of yacc.c  */
#line 8436 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1258:

/* Line 1806 of yacc.c  */
#line 8437 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8438 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8439 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1261:

/* Line 1806 of yacc.c  */
#line 8446 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8455 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8461 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1265:

/* Line 1806 of yacc.c  */
#line 8462 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8466 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8467 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8468 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1269:

/* Line 1806 of yacc.c  */
#line 8472 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8473 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8478 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8482 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1273:

/* Line 1806 of yacc.c  */
#line 8492 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1275:

/* Line 1806 of yacc.c  */
#line 8501 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8505 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1277:

/* Line 1806 of yacc.c  */
#line 8509 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8516 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8520 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1280:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8548 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1285:

/* Line 1806 of yacc.c  */
#line 8557 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8563 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1287:

/* Line 1806 of yacc.c  */
#line 8574 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1289:

/* Line 1806 of yacc.c  */
#line 8582 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1290:

/* Line 1806 of yacc.c  */
#line 8595 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1292:

/* Line 1806 of yacc.c  */
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

/* Line 1806 of yacc.c  */
#line 8626 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1298:

/* Line 1806 of yacc.c  */
#line 8636 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1299:

/* Line 1806 of yacc.c  */
#line 8642 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1300:

/* Line 1806 of yacc.c  */
#line 8644 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1301:

/* Line 1806 of yacc.c  */
#line 8648 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1302:

/* Line 1806 of yacc.c  */
#line 8650 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1303:

/* Line 1806 of yacc.c  */
#line 8655 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1304:

/* Line 1806 of yacc.c  */
#line 8661 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8663 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1306:

/* Line 1806 of yacc.c  */
#line 8668 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1307:

/* Line 1806 of yacc.c  */
#line 8674 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1308:

/* Line 1806 of yacc.c  */
#line 8675 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1309:

/* Line 1806 of yacc.c  */
#line 8679 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1310:

/* Line 1806 of yacc.c  */
#line 8680 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1311:

/* Line 1806 of yacc.c  */
#line 8684 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1312:

/* Line 1806 of yacc.c  */
#line 8685 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1313:

/* Line 1806 of yacc.c  */
#line 8690 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1314:

/* Line 1806 of yacc.c  */
#line 8694 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1315:

/* Line 1806 of yacc.c  */
#line 8704 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1321:

/* Line 1806 of yacc.c  */
#line 8721 "parser.y"
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

  case 1322:

/* Line 1806 of yacc.c  */
#line 8746 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1323:

/* Line 1806 of yacc.c  */
#line 8750 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1324:

/* Line 1806 of yacc.c  */
#line 8762 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1325:

/* Line 1806 of yacc.c  */
#line 8772 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1326:

/* Line 1806 of yacc.c  */
#line 8777 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1327:

/* Line 1806 of yacc.c  */
#line 8782 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1328:

/* Line 1806 of yacc.c  */
#line 8787 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1329:

/* Line 1806 of yacc.c  */
#line 8795 "parser.y"
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

  case 1332:

/* Line 1806 of yacc.c  */
#line 8838 "parser.y"
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

  case 1333:

/* Line 1806 of yacc.c  */
#line 8878 "parser.y"
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

  case 1334:

/* Line 1806 of yacc.c  */
#line 8888 "parser.y"
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

  case 1339:

/* Line 1806 of yacc.c  */
#line 8918 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1340:

/* Line 1806 of yacc.c  */
#line 8927 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1343:

/* Line 1806 of yacc.c  */
#line 8943 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1345:

/* Line 1806 of yacc.c  */
#line 8955 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1346:

/* Line 1806 of yacc.c  */
#line 8964 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1347:

/* Line 1806 of yacc.c  */
#line 8965 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1348:

/* Line 1806 of yacc.c  */
#line 8970 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1349:

/* Line 1806 of yacc.c  */
#line 8974 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1350:

/* Line 1806 of yacc.c  */
#line 8978 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1351:

/* Line 1806 of yacc.c  */
#line 8982 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1352:

/* Line 1806 of yacc.c  */
#line 8988 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1353:

/* Line 1806 of yacc.c  */
#line 8989 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1356:

/* Line 1806 of yacc.c  */
#line 8999 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1357:

/* Line 1806 of yacc.c  */
#line 9003 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1360:

/* Line 1806 of yacc.c  */
#line 9020 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1362:

/* Line 1806 of yacc.c  */
#line 9030 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1365:

/* Line 1806 of yacc.c  */
#line 9043 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1367:

/* Line 1806 of yacc.c  */
#line 9053 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1370:

/* Line 1806 of yacc.c  */
#line 9068 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1372:

/* Line 1806 of yacc.c  */
#line 9078 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1375:

/* Line 1806 of yacc.c  */
#line 9095 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1377:

/* Line 1806 of yacc.c  */
#line 9106 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1383:

/* Line 1806 of yacc.c  */
#line 9129 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1384:

/* Line 1806 of yacc.c  */
#line 9138 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1388:

/* Line 1806 of yacc.c  */
#line 9155 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1389:

/* Line 1806 of yacc.c  */
#line 9164 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1392:

/* Line 1806 of yacc.c  */
#line 9181 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1394:

/* Line 1806 of yacc.c  */
#line 9191 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1395:

/* Line 1806 of yacc.c  */
#line 9201 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1396:

/* Line 1806 of yacc.c  */
#line 9205 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1397:

/* Line 1806 of yacc.c  */
#line 9215 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1398:

/* Line 1806 of yacc.c  */
#line 9222 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1399:

/* Line 1806 of yacc.c  */
#line 9228 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1400:

/* Line 1806 of yacc.c  */
#line 9232 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1404:

/* Line 1806 of yacc.c  */
#line 9245 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1405:

/* Line 1806 of yacc.c  */
#line 9253 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9254 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1407:

/* Line 1806 of yacc.c  */
#line 9256 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1408:

/* Line 1806 of yacc.c  */
#line 9257 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1409:

/* Line 1806 of yacc.c  */
#line 9258 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1410:

/* Line 1806 of yacc.c  */
#line 9259 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1411:

/* Line 1806 of yacc.c  */
#line 9260 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1412:

/* Line 1806 of yacc.c  */
#line 9262 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1413:

/* Line 1806 of yacc.c  */
#line 9263 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1414:

/* Line 1806 of yacc.c  */
#line 9264 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9265 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9266 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9267 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1418:

/* Line 1806 of yacc.c  */
#line 9269 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1419:

/* Line 1806 of yacc.c  */
#line 9270 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1420:

/* Line 1806 of yacc.c  */
#line 9271 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1421:

/* Line 1806 of yacc.c  */
#line 9273 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9274 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9275 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9276 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9277 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9280 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1427:

/* Line 1806 of yacc.c  */
#line 9281 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1436:

/* Line 1806 of yacc.c  */
#line 9311 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1437:

/* Line 1806 of yacc.c  */
#line 9315 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1441:

/* Line 1806 of yacc.c  */
#line 9326 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1442:

/* Line 1806 of yacc.c  */
#line 9327 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1443:

/* Line 1806 of yacc.c  */
#line 9328 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1444:

/* Line 1806 of yacc.c  */
#line 9332 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1445:

/* Line 1806 of yacc.c  */
#line 9333 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1446:

/* Line 1806 of yacc.c  */
#line 9334 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1447:

/* Line 1806 of yacc.c  */
#line 9339 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1448:

/* Line 1806 of yacc.c  */
#line 9342 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1449:

/* Line 1806 of yacc.c  */
#line 9346 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1450:

/* Line 1806 of yacc.c  */
#line 9347 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1451:

/* Line 1806 of yacc.c  */
#line 9348 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1452:

/* Line 1806 of yacc.c  */
#line 9351 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1453:

/* Line 1806 of yacc.c  */
#line 9352 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9363 "parser.y"
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

  case 1455:

/* Line 1806 of yacc.c  */
#line 9375 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1456:

/* Line 1806 of yacc.c  */
#line 9384 "parser.y"
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

  case 1457:

/* Line 1806 of yacc.c  */
#line 9396 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1458:

/* Line 1806 of yacc.c  */
#line 9405 "parser.y"
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

  case 1459:

/* Line 1806 of yacc.c  */
#line 9417 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1460:

/* Line 1806 of yacc.c  */
#line 9431 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9433 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1462:

/* Line 1806 of yacc.c  */
#line 9438 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9446 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1464:

/* Line 1806 of yacc.c  */
#line 9453 "parser.y"
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

  case 1465:

/* Line 1806 of yacc.c  */
#line 9473 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1466:

/* Line 1806 of yacc.c  */
#line 9477 "parser.y"
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

  case 1467:

/* Line 1806 of yacc.c  */
#line 9498 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1468:

/* Line 1806 of yacc.c  */
#line 9539 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1469:

/* Line 1806 of yacc.c  */
#line 9552 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1470:

/* Line 1806 of yacc.c  */
#line 9554 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9558 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1472:

/* Line 1806 of yacc.c  */
#line 9564 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1473:

/* Line 1806 of yacc.c  */
#line 9566 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1474:

/* Line 1806 of yacc.c  */
#line 9571 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1477:

/* Line 1806 of yacc.c  */
#line 9585 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1478:

/* Line 1806 of yacc.c  */
#line 9592 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9602 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9603 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9608 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1482:

/* Line 1806 of yacc.c  */
#line 9616 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1483:

/* Line 1806 of yacc.c  */
#line 9624 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1484:

/* Line 1806 of yacc.c  */
#line 9628 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1485:

/* Line 1806 of yacc.c  */
#line 9635 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9651 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1489:

/* Line 1806 of yacc.c  */
#line 9665 "parser.y"
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

  case 1490:

/* Line 1806 of yacc.c  */
#line 9682 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1491:

/* Line 1806 of yacc.c  */
#line 9686 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1494:

/* Line 1806 of yacc.c  */
#line 9695 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9702 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1496:

/* Line 1806 of yacc.c  */
#line 9706 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9717 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1502:

/* Line 1806 of yacc.c  */
#line 9721 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9725 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1504:

/* Line 1806 of yacc.c  */
#line 9729 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1505:

/* Line 1806 of yacc.c  */
#line 9733 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1506:

/* Line 1806 of yacc.c  */
#line 9737 "parser.y"
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

  case 1507:

/* Line 1806 of yacc.c  */
#line 9758 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1508:

/* Line 1806 of yacc.c  */
#line 9762 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1516:

/* Line 1806 of yacc.c  */
#line 9779 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1517:

/* Line 1806 of yacc.c  */
#line 9783 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1518:

/* Line 1806 of yacc.c  */
#line 9787 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1534:

/* Line 1806 of yacc.c  */
#line 9834 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1542:

/* Line 1806 of yacc.c  */
#line 9858 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1543:

/* Line 1806 of yacc.c  */
#line 9862 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1544:

/* Line 1806 of yacc.c  */
#line 9866 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1545:

/* Line 1806 of yacc.c  */
#line 9867 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1546:

/* Line 1806 of yacc.c  */
#line 9871 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1547:

/* Line 1806 of yacc.c  */
#line 9876 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1548:

/* Line 1806 of yacc.c  */
#line 9883 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1549:

/* Line 1806 of yacc.c  */
#line 9890 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1550:

/* Line 1806 of yacc.c  */
#line 9897 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1551:

/* Line 1806 of yacc.c  */
#line 9907 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1552:

/* Line 1806 of yacc.c  */
#line 9914 "parser.y"
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

  case 1553:

/* Line 1806 of yacc.c  */
#line 9924 "parser.y"
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

  case 1554:

/* Line 1806 of yacc.c  */
#line 9934 "parser.y"
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

  case 1555:

/* Line 1806 of yacc.c  */
#line 9944 "parser.y"
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

  case 1556:

/* Line 1806 of yacc.c  */
#line 9957 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1557:

/* Line 1806 of yacc.c  */
#line 9961 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1558:

/* Line 1806 of yacc.c  */
#line 9969 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1559:

/* Line 1806 of yacc.c  */
#line 9977 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1560:

/* Line 1806 of yacc.c  */
#line 9981 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1561:

/* Line 1806 of yacc.c  */
#line 9991 "parser.y"
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

  case 1562:

/* Line 1806 of yacc.c  */
#line 10006 "parser.y"
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

  case 1563:

/* Line 1806 of yacc.c  */
#line 10029 "parser.y"
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

  case 1564:

/* Line 1806 of yacc.c  */
#line 10052 "parser.y"
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

  case 1565:

/* Line 1806 of yacc.c  */
#line 10067 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1566:

/* Line 1806 of yacc.c  */
#line 10068 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1567:

/* Line 1806 of yacc.c  */
#line 10069 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1568:

/* Line 1806 of yacc.c  */
#line 10070 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1569:

/* Line 1806 of yacc.c  */
#line 10071 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1570:

/* Line 1806 of yacc.c  */
#line 10072 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1571:

/* Line 1806 of yacc.c  */
#line 10077 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1572:

/* Line 1806 of yacc.c  */
#line 10081 "parser.y"
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

  case 1573:

/* Line 1806 of yacc.c  */
#line 10098 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1574:

/* Line 1806 of yacc.c  */
#line 10102 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1575:

/* Line 1806 of yacc.c  */
#line 10108 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1576:

/* Line 1806 of yacc.c  */
#line 10109 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1577:

/* Line 1806 of yacc.c  */
#line 10110 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 10111 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 10112 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1580:

/* Line 1806 of yacc.c  */
#line 10113 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1581:

/* Line 1806 of yacc.c  */
#line 10114 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1582:

/* Line 1806 of yacc.c  */
#line 10121 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1583:

/* Line 1806 of yacc.c  */
#line 10125 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1584:

/* Line 1806 of yacc.c  */
#line 10129 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1585:

/* Line 1806 of yacc.c  */
#line 10133 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 10137 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 10141 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 10145 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10149 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10153 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1591:

/* Line 1806 of yacc.c  */
#line 10157 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1600:

/* Line 1806 of yacc.c  */
#line 10181 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1601:

/* Line 1806 of yacc.c  */
#line 10185 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1602:

/* Line 1806 of yacc.c  */
#line 10189 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1603:

/* Line 1806 of yacc.c  */
#line 10196 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1604:

/* Line 1806 of yacc.c  */
#line 10200 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1605:

/* Line 1806 of yacc.c  */
#line 10204 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1606:

/* Line 1806 of yacc.c  */
#line 10211 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1607:

/* Line 1806 of yacc.c  */
#line 10218 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1608:

/* Line 1806 of yacc.c  */
#line 10225 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1609:

/* Line 1806 of yacc.c  */
#line 10235 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1610:

/* Line 1806 of yacc.c  */
#line 10242 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1611:

/* Line 1806 of yacc.c  */
#line 10252 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1612:

/* Line 1806 of yacc.c  */
#line 10259 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1613:

/* Line 1806 of yacc.c  */
#line 10270 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1614:

/* Line 1806 of yacc.c  */
#line 10278 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1615:

/* Line 1806 of yacc.c  */
#line 10279 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1616:

/* Line 1806 of yacc.c  */
#line 10283 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1617:

/* Line 1806 of yacc.c  */
#line 10284 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1618:

/* Line 1806 of yacc.c  */
#line 10288 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10289 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10294 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10298 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10305 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10309 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10316 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10317 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10318 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10322 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10323 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10327 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10328 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10329 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10334 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10338 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1634:

/* Line 1806 of yacc.c  */
#line 10350 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10355 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10363 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10367 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10371 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10375 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10379 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10383 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10387 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10391 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10397 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1645:

/* Line 1806 of yacc.c  */
#line 10398 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1806 of yacc.c  */
#line 18505 "parser.c"
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 10569 "parser.y"


