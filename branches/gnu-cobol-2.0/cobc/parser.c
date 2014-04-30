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
#define YYLAST   7771

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  809
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1882
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2690

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
    3621,  3623,  3631,  3632,  3634,  3636,  3638,  3640,  3642,  3644,
    3649,  3651,  3654,  3656,  3659,  3663,  3664,  3666,  3669,  3671,
    3676,  3678,  3680,  3682,  3683,  3688,  3694,  3695,  3698,  3699,
    3704,  3708,  3712,  3714,  3716,  3718,  3720,  3721,  3723,  3726,
    3727,  3730,  3731,  3734,  3737,  3738,  3741,  3742,  3745,  3748,
    3749,  3752,  3753,  3756,  3759,  3760,  3763,  3764,  3767,  3770,
    3772,  3775,  3777,  3779,  3782,  3785,  3788,  3790,  3792,  3795,
    3798,  3801,  3802,  3805,  3806,  3809,  3810,  3813,  3815,  3817,
    3818,  3821,  3823,  3826,  3829,  3831,  3833,  3835,  3837,  3839,
    3841,  3843,  3845,  3847,  3849,  3851,  3853,  3855,  3857,  3859,
    3861,  3863,  3865,  3867,  3869,  3871,  3873,  3875,  3877,  3879,
    3882,  3884,  3886,  3888,  3890,  3892,  3894,  3896,  3900,  3901,
    3903,  3905,  3909,  3913,  3915,  3919,  3923,  3925,  3929,  3931,
    3934,  3937,  3939,  3943,  3945,  3947,  3951,  3953,  3957,  3959,
    3963,  3965,  3968,  3971,  3973,  3975,  3977,  3980,  3982,  3984,
    3986,  3989,  3991,  3992,  3995,  3997,  3999,  4001,  4005,  4007,
    4009,  4012,  4014,  4016,  4018,  4021,  4023,  4025,  4027,  4029,
    4031,  4033,  4036,  4038,  4040,  4044,  4046,  4049,  4051,  4053,
    4055,  4057,  4060,  4063,  4066,  4071,  4075,  4077,  4079,  4082,
    4084,  4086,  4088,  4090,  4092,  4094,  4096,  4099,  4102,  4105,
    4107,  4109,  4111,  4113,  4115,  4117,  4119,  4121,  4123,  4125,
    4127,  4129,  4131,  4133,  4135,  4137,  4139,  4141,  4143,  4145,
    4147,  4149,  4151,  4153,  4155,  4157,  4160,  4162,  4166,  4169,
    4172,  4174,  4176,  4180,  4183,  4186,  4188,  4190,  4194,  4198,
    4203,  4209,  4211,  4213,  4215,  4217,  4219,  4221,  4223,  4225,
    4227,  4229,  4231,  4234,  4236,  4240,  4242,  4244,  4246,  4248,
    4250,  4252,  4254,  4257,  4263,  4269,  4275,  4280,  4286,  4292,
    4298,  4301,  4304,  4306,  4308,  4310,  4312,  4314,  4316,  4318,
    4320,  4321,  4326,  4332,  4333,  4337,  4340,  4342,  4346,  4350,
    4352,  4356,  4358,  4362,  4363,  4364,  4366,  4367,  4369,  4370,
    4372,  4373,  4376,  4377,  4380,  4381,  4383,  4385,  4386,  4388,
    4389,  4391,  4394,  4395,  4398,  4399,  4403,  4405,  4407,  4409,
    4411,  4413,  4415,  4417,  4419,  4420,  4423,  4425,  4427,  4429,
    4431,  4433,  4435,  4437,  4439,  4441,  4443,  4445,  4447,  4449,
    4451,  4453,  4455,  4457,  4459,  4461,  4463,  4465,  4467,  4469,
    4471,  4473,  4475,  4477,  4479,  4481,  4483,  4485,  4487,  4489,
    4491,  4493,  4495,  4497,  4499,  4501,  4503,  4505,  4507,  4509,
    4511,  4513,  4515,  4517,  4519,  4521,  4523,  4525,  4527,  4529,
    4531,  4533,  4535,  4537,  4539,  4541,  4543,  4545,  4547,  4549,
    4551,  4553,  4555,  4557,  4559,  4561,  4563,  4564,  4566,  4567,
    4569,  4570,  4572,  4573,  4575,  4576,  4578,  4579,  4581,  4582,
    4584,  4585,  4587,  4588,  4590,  4591,  4593,  4594,  4596,  4597,
    4599,  4600,  4602,  4603,  4605,  4606,  4608,  4609,  4611,  4612,
    4614,  4615,  4617,  4620,  4621,  4623,  4624,  4626,  4627,  4629,
    4630,  4632,  4633,  4635,  4637,  4638,  4640,  4641,  4643,  4645,
    4646,  4648,  4650,  4651,  4654,  4657,  4658,  4660,  4661,  4663,
    4664,  4666,  4667,  4669,  4671,  4672,  4674,  4675,  4677,  4678,
    4681,  4683,  4685,  4686,  4688,  4689,  4691,  4692,  4694,  4695,
    4697,  4698,  4700,  4701,  4703,  4704,  4706,  4707,  4709,  4712,
    4713,  4715,  4716,  4718,  4719,  4721,  4722,  4724,  4725,  4727,
    4728,  4730,  4731,  4733,  4734,  4736,  4738,  4739,  4741,  4742,
    4746,  4747,  4749,  4752,  4754,  4756,  4758,  4760,  4762,  4764,
    4766,  4768,  4770,  4772,  4774,  4776,  4778,  4780,  4782,  4784,
    4786,  4788,  4790,  4792,  4794,  4797,  4800,  4802,  4804,  4806,
    4808,  4810,  4812,  4815,  4817,  4821,  4824,  4826,  4828,  4830,
    4833,  4835,  4838,  4840,  4843,  4845,  4848,  4850,  4853,  4855,
    4858,  4860,  4863
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
    1206,    -1,   206,   924,    -1,    -1,   215,   937,  1146,  1289,
     938,   939,    -1,   818,   128,   818,    -1,   128,   818,    -1,
     818,    -1,    -1,   139,    -1,    -1,   222,   941,   942,    -1,
    1186,   943,   944,   945,   949,    -1,    -1,  1295,   175,    -1,
      -1,     9,  1291,   498,    -1,   948,  1291,   498,    -1,    -1,
     365,   946,    -1,   947,    -1,   946,   947,    -1,   948,  1254,
      49,  1189,    -1,    12,    -1,    15,    -1,   301,    -1,    16,
      -1,   302,    -1,   277,    -1,   278,    -1,    -1,  1289,  1291,
     110,    -1,    -1,   224,   951,   952,    -1,  1171,    -1,   952,
    1171,    -1,    -1,   227,   954,   955,    -1,   956,   957,    -1,
    1206,    -1,  1217,    -1,  1220,    -1,   958,   960,    -1,   958,
      -1,   960,    -1,   961,    -1,    -1,   436,   959,   962,    -1,
     365,   964,    -1,    92,  1195,   446,  1196,   968,    -1,   963,
      -1,   962,   963,    -1,  1195,   188,    -1,    57,   968,    -1,
       9,    -1,   241,    -1,   468,    -1,  1195,   968,    -1,   965,
      -1,   964,   965,    -1,    57,    49,  1195,   968,    -1,   966,
     967,    -1,    -1,     9,    -1,   241,    -1,   177,    -1,   468,
      -1,  1195,    49,  1196,   968,    -1,    -1,   968,   969,    -1,
      37,  1262,  1189,    -1,     8,  1262,  1189,    -1,    -1,   269,
     971,  1045,    -1,    -1,   273,   973,   974,    -1,  1189,   446,
    1186,    -1,    94,  1189,   446,  1186,    -1,    -1,   275,   976,
     977,   978,    -1,  1189,    49,  1165,  1129,    -1,  1189,    49,
    1189,   203,  1165,  1129,    -1,    -1,   140,    -1,    -1,   311,
     980,   981,    -1,   982,   983,  1169,   984,    -1,   981,   982,
     983,  1169,   984,    -1,   225,    -1,   317,    -1,   233,    -1,
     170,    -1,    -1,   404,  1295,   637,    -1,    -1,  1295,   287,
     380,    -1,  1295,   262,    -1,   379,    -1,    -1,   324,   986,
     987,    -1,   991,   992,    -1,    -1,   992,   988,   818,   989,
      -1,   992,   990,    -1,    -1,   141,    -1,   141,    -1,   451,
      -1,  1175,    -1,  1175,   442,  1175,    -1,    -1,  1198,   445,
      -1,   190,    -1,   993,   481,   994,    -1,   993,   499,   995,
      -1,    -1,  1295,   439,  1120,    -1,   168,    -1,  1146,    -1,
     996,    -1,   995,     8,   996,    -1,  1206,   196,  1189,    49,
    1189,   481,  1146,    -1,    -1,   349,   998,   999,  1004,    -1,
    1170,  1235,  1280,  1000,  1001,  1002,  1003,    -1,    -1,   228,
    1206,    -1,    -1,   217,   262,    -1,  1295,   262,    -1,  1295,
     236,   262,    -1,  1295,   287,   262,    -1,  1295,   216,   262,
      -1,  1295,   500,    -1,    -1,   237,  1264,  1206,    -1,  1142,
      -1,  1136,    -1,    -1,   143,    -1,   350,    -1,    -1,   360,
    1007,  1008,    -1,  1167,  1118,    -1,   374,    -1,    -1,   375,
    1011,  1012,  1013,    -1,  1170,  1280,  1000,  1135,    -1,    -1,
     144,    -1,    -1,   381,  1015,  1016,  1018,    -1,  1167,  1118,
    1017,  1142,    -1,    -1,  1295,   262,    -1,  1295,   287,   262,
      -1,    -1,   145,    -1,   385,    -1,    -1,   393,  1021,  1022,
    1027,    -1,  1168,  1023,  1024,  1025,    -1,     9,  1168,  1024,
     501,  1147,   818,    -1,    -1,   499,  1206,    -1,    -1,   129,
     818,    -1,  1026,    -1,  1026,  1025,    -1,   501,  1146,   818,
      -1,    -1,   146,    -1,    -1,   403,  1029,  1030,    -1,  1033,
      -1,  1034,    -1,  1037,    -1,  1038,    -1,  1039,    -1,  1041,
      -1,   309,    -1,   307,    -1,   482,    -1,   123,    -1,   153,
    1195,   446,  1195,    -1,  1203,    31,  1035,    -1,  1036,    -1,
    1035,  1036,    -1,    38,  1031,    -1,    46,  1031,    -1,   211,
    1031,    -1,   265,  1031,    -1,   378,  1031,    -1,   473,  1031,
      -1,   243,  1031,    -1,   318,  1031,    -1,  1186,   446,   152,
    1194,    -1,  1186,   446,  1189,    -1,  1186,  1032,    49,  1189,
      -1,  1040,    -1,  1039,  1040,    -1,  1172,   446,  1031,    -1,
    1042,    -1,  1041,  1042,    -1,  1186,   446,   464,    -1,  1186,
     446,   453,    -1,    -1,   412,  1044,  1045,    -1,    -1,  1204,
    1047,  1049,  1050,  1046,  1051,  1052,    -1,    -1,  1047,  1275,
     717,  1266,  1048,    -1,    -1,  1048,  1210,    -1,    -1,  1311,
    1260,    -1,    -1,  1296,  1264,  1179,    -1,    -1,   497,  1169,
      -1,   225,   337,  1264,   991,    -1,    -1,   203,  1169,    -1,
     317,   337,  1264,   991,    -1,    -1,   421,  1054,  1055,  1061,
      -1,  1170,  1057,  1056,  1142,    -1,    -1,  1295,  1310,  1159,
      -1,    -1,   237,  1264,  1058,  1206,    -1,   177,    -1,   240,
      -1,  1152,    -1,  1236,  1153,    -1,  1236,  1154,    -1,  1236,
    1155,    -1,  1236,  1156,    -1,  1059,    -1,  1060,    -1,   290,
    1152,    -1,   293,    -1,    -1,   147,    -1,    -1,   426,   387,
    1063,  1064,    -1,   426,  1066,    -1,    -1,   863,  1189,    -1,
    1295,   161,  1287,  1065,    -1,  1295,   289,  1287,  1065,    -1,
      -1,  1189,    -1,   256,    -1,   416,    -1,   510,    -1,   346,
      -1,    -1,   427,  1068,  1069,  1073,    -1,  1070,   228,  1206,
    1072,  1132,    -1,  1071,    -1,  1070,  1071,    -1,  1189,    -1,
     112,  1250,   410,    -1,   112,  1250,  1189,    -1,    -1,  1295,
     330,  1264,  1206,    -1,    -1,   148,    -1,    -1,   430,  1075,
    1076,  1077,    -1,  1188,   196,  1165,  1129,    -1,  1188,   196,
    1189,   203,  1165,  1129,    -1,    94,  1206,   196,  1206,  1238,
    1129,    -1,    -1,   149,    -1,   432,  1079,    -1,    -1,   336,
      -1,    -1,   438,  1081,  1082,    -1,  1171,    -1,  1082,  1171,
      -1,    -1,   469,  1084,  1085,    -1,  1206,   196,  1195,   446,
    1196,    -1,    -1,   475,  1087,  1088,    -1,  1170,  1089,    -1,
      -1,   351,    -1,   353,    -1,    -1,   480,  1091,  1092,  1101,
      -1,  1206,  1093,  1096,  1072,  1100,  1132,    -1,    -1,   112,
    1250,  1094,    -1,  1095,    -1,  1094,   313,  1095,    -1,  1230,
    1195,    -1,   228,  1097,    -1,  1096,  1097,    -1,  1206,  1098,
    1099,    -1,    -1,   113,  1259,  1206,    -1,    -1,    95,  1259,
    1206,    -1,    -1,   436,  1259,  1206,    -1,    -1,   150,    -1,
      -1,   492,  1103,  1104,    -1,  1105,    -1,  1108,    -1,  1112,
      -1,  1113,    -1,  1106,  1244,  1286,  1300,  1278,  1275,  1107,
      -1,    -1,   204,    -1,  1169,    -1,   225,    -1,   317,    -1,
     233,    -1,   170,    -1,  1257,   107,  1275,  1109,    -1,  1110,
      -1,  1109,  1110,    -1,  1176,    -1,     9,   338,    -1,     9,
    1111,  1210,    -1,    -1,   358,    -1,   358,   306,    -1,   306,
      -1,  1106,    37,   367,  1206,    -1,  1114,    -1,   166,    -1,
     127,    -1,    -1,   507,  1116,  1117,  1122,    -1,  1167,  1118,
    1119,  1017,  1121,    -1,    -1,   196,  1202,    -1,    -1,  1120,
    1243,  1199,  1268,    -1,  1120,  1243,  1173,    -1,  1120,  1243,
     321,    -1,    37,    -1,     8,    -1,  1142,    -1,  1139,    -1,
      -1,   151,    -1,  1124,  1125,    -1,    -1,   165,   818,    -1,
      -1,   294,   818,    -1,  1127,  1128,    -1,    -1,   165,   818,
      -1,    -1,   294,   818,    -1,  1130,  1131,    -1,    -1,   411,
     818,    -1,    -1,   297,   818,    -1,  1133,  1134,    -1,    -1,
     461,   818,    -1,    -1,   296,   818,    -1,  1137,  1138,    -1,
    1137,    -1,  1137,  1138,    -1,  1137,    -1,  1138,    -1,   129,
     818,    -1,   291,   818,    -1,  1140,  1141,    -1,  1140,    -1,
    1141,    -1,   157,   818,    -1,   292,   818,    -1,  1143,  1144,
      -1,    -1,   231,   818,    -1,    -1,   295,   818,    -1,    -1,
    1201,  1309,    -1,  1147,    -1,  1148,    -1,    -1,  1149,  1150,
      -1,  1151,    -1,  1150,   232,    -1,  1150,  1151,    -1,  1189,
      -1,   462,    -1,   448,    -1,   463,    -1,   458,    -1,   459,
      -1,   450,    -1,   169,    -1,  1152,    -1,  1153,    -1,  1154,
      -1,  1155,    -1,  1156,    -1,   293,    -1,   290,    -1,    20,
      -1,   313,    -1,   308,    -1,   301,    -1,    12,    -1,    13,
      -1,    14,    -1,   332,    -1,   284,    -1,   452,    -1,   159,
    1291,    -1,   455,    -1,   207,    -1,   457,    -1,   246,    -1,
     208,    -1,   247,    -1,  1159,    -1,  1157,  1158,  1159,    -1,
      -1,    70,    -1,   398,    -1,  1159,   463,  1160,    -1,  1159,
     458,  1160,    -1,  1160,    -1,  1160,   459,  1161,    -1,  1160,
     450,  1161,    -1,  1161,    -1,  1162,   169,  1161,    -1,  1162,
      -1,   463,  1163,    -1,   458,  1163,    -1,  1163,    -1,   462,
    1159,   448,    -1,  1192,    -1,   251,    -1,   251,  1302,   504,
      -1,   253,    -1,   253,  1302,   504,    -1,   322,    -1,   322,
    1302,   504,    -1,  1166,    -1,  1165,  1166,    -1,  1187,  1238,
      -1,  1210,    -1,  1210,    -1,  1170,    -1,  1169,  1170,    -1,
     504,    -1,   504,    -1,  1173,    -1,  1172,  1173,    -1,   271,
      -1,    -1,  1174,  1175,    -1,  1176,    -1,  1210,    -1,  1177,
      -1,  1177,  1302,  1177,    -1,   256,    -1,  1179,    -1,  1178,
    1179,    -1,  1210,    -1,   504,    -1,  1182,    -1,  1181,  1182,
      -1,   504,    -1,  1179,    -1,   256,    -1,   504,    -1,   504,
      -1,  1187,    -1,  1186,  1187,    -1,  1208,    -1,  1218,    -1,
       6,  1274,  1207,    -1,  1189,    -1,  1188,  1189,    -1,  1206,
      -1,  1217,    -1,  1220,    -1,  1164,    -1,   245,  1207,    -1,
     245,  1218,    -1,   245,  1220,    -1,     6,  1274,  1193,  1194,
      -1,     6,  1274,  1207,    -1,   271,    -1,  1192,    -1,  1190,
    1192,    -1,  1206,    -1,  1218,    -1,  1220,    -1,  1206,    -1,
    1218,    -1,  1220,    -1,  1164,    -1,   245,  1207,    -1,   245,
    1218,    -1,   245,  1220,    -1,   340,    -1,   152,    -1,  1207,
      -1,   256,    -1,  1206,    -1,  1218,    -1,  1206,    -1,  1217,
      -1,  1206,    -1,   256,    -1,  1206,    -1,   256,    -1,  1220,
      -1,  1203,    -1,  1213,    -1,   510,    -1,  1203,    -1,  1215,
      -1,  1203,    -1,  1213,    -1,  1206,    -1,  1217,    -1,  1220,
      -1,  1205,    -1,  1205,    -1,  1210,    -1,  1210,  1211,    -1,
    1207,    -1,  1210,  1211,  1212,    -1,  1210,  1211,    -1,  1210,
    1212,    -1,  1210,    -1,  1209,    -1,  1210,  1211,  1212,    -1,
    1210,  1211,    -1,  1210,  1212,    -1,  1210,    -1,   504,    -1,
     504,  1302,  1210,    -1,   462,  1157,   448,    -1,   462,  1159,
     449,   448,    -1,   462,  1159,   449,  1159,   448,    -1,   256,
      -1,   256,    -1,   256,    -1,   256,    -1,   416,    -1,   510,
      -1,   346,    -1,   212,    -1,   266,    -1,   460,    -1,  1218,
      -1,     9,  1219,    -1,  1219,    -1,  1218,   447,  1219,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   460,    -1,  1221,  1224,    -1,  1222,   462,  1191,
     448,  1224,    -1,  1223,   462,  1157,   448,  1224,    -1,   470,
     462,  1226,   448,  1224,    -1,   303,   462,  1227,   448,    -1,
     258,   462,  1228,   448,  1224,    -1,   259,   462,  1228,   448,
    1224,    -1,   260,   462,  1228,   448,  1224,    -1,   201,  1225,
      -1,   495,  1225,    -1,    99,    -1,   502,    -1,   490,    -1,
     264,    -1,   377,    -1,    82,    -1,   428,    -1,   429,    -1,
      -1,   462,  1159,   449,   448,    -1,   462,  1159,   449,  1159,
     448,    -1,    -1,   462,  1157,   448,    -1,   462,   448,    -1,
    1191,    -1,  1191,  1158,   241,    -1,  1191,  1158,   468,    -1,
    1191,    -1,  1191,  1158,  1191,    -1,  1159,    -1,  1159,  1158,
    1179,    -1,    -1,    -1,     9,    -1,    -1,  1311,    -1,    -1,
     223,    -1,    -1,   223,  1234,    -1,    -1,   446,  1196,    -1,
      -1,   285,    -1,   334,    -1,    -1,   290,    -1,    -1,   312,
      -1,   290,   312,    -1,    -1,   386,  1239,    -1,    -1,   272,
    1264,  1240,    -1,    34,    -1,   281,    -1,   282,    -1,   283,
      -1,   344,    -1,   466,    -1,   467,    -1,   471,    -1,    -1,
     400,  1251,    -1,   451,    -1,     3,    -1,     5,    -1,    10,
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
      -1,   248,  1264,    -1,   249,  1245,    -1,    -1,   254,    -1,
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
      57,    -1,   505,    -1,   351,  1264,    -1,   353,  1245,    -1,
     356,    -1,   474,    -1,   252,    -1,   254,    -1,   410,    -1,
     244,    -1,   503,   124,    -1,   124,    -1,   340,    63,   401,
      -1,    63,   401,    -1,   401,    -1,   116,    -1,   106,    -1,
      89,   210,    -1,    54,    -1,    89,   187,    -1,    53,    -1,
     321,   210,    -1,   325,    -1,   321,   187,    -1,   326,    -1,
     366,   210,    -1,   383,    -1,   366,   187,    -1,   382,    -1,
      89,  1264,    -1,    90,  1245,    -1
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
    7051,  7058,  7057,  7070,  7079,  7083,  7094,  7110,  7109,  7118,
    7122,  7126,  7133,  7137,  7148,  7147,  7155,  7163,  7164,  7168,
    7169,  7170,  7175,  7178,  7185,  7189,  7197,  7204,  7205,  7206,
    7207,  7208,  7209,  7210,  7215,  7218,  7228,  7227,  7236,  7242,
    7254,  7253,  7262,  7266,  7270,  7274,  7281,  7282,  7283,  7284,
    7291,  7290,  7304,  7314,  7323,  7324,  7328,  7329,  7330,  7331,
    7332,  7333,  7337,  7338,  7342,  7347,  7354,  7355,  7356,  7357,
    7358,  7362,  7390,  7393,  7400,  7404,  7414,  7413,  7426,  7425,
    7433,  7437,  7448,  7447,  7456,  7460,  7467,  7471,  7482,  7481,
    7489,  7510,  7534,  7535,  7536,  7537,  7541,  7542,  7546,  7547,
    7548,  7549,  7561,  7560,  7571,  7577,  7576,  7587,  7595,  7603,
    7610,  7614,  7627,  7634,  7646,  7649,  7654,  7658,  7669,  7676,
    7677,  7681,  7682,  7685,  7686,  7691,  7702,  7701,  7710,  7737,
    7738,  7743,  7746,  7750,  7754,  7758,  7762,  7766,  7773,  7774,
    7778,  7779,  7783,  7787,  7797,  7808,  7807,  7815,  7825,  7836,
    7835,  7844,  7851,  7855,  7866,  7865,  7877,  7886,  7889,  7893,
    7900,  7904,  7914,  7926,  7925,  7934,  7938,  7947,  7948,  7953,
    7956,  7964,  7968,  7975,  7983,  7987,  7998,  7997,  8011,  8012,
    8013,  8014,  8015,  8016,  8020,  8021,  8025,  8026,  8032,  8041,
    8048,  8049,  8053,  8057,  8061,  8065,  8069,  8073,  8077,  8081,
    8090,  8094,  8103,  8112,  8113,  8117,  8126,  8127,  8131,  8135,
    8146,  8145,  8154,  8153,  8184,  8187,  8207,  8208,  8211,  8212,
    8220,  8221,  8226,  8231,  8241,  8257,  8262,  8272,  8289,  8288,
    8298,  8311,  8314,  8322,  8325,  8330,  8335,  8343,  8344,  8345,
    8346,  8347,  8348,  8352,  8360,  8361,  8365,  8369,  8380,  8379,
    8389,  8402,  8405,  8409,  8417,  8429,  8432,  8439,  8440,  8441,
    8442,  8449,  8448,  8457,  8464,  8465,  8469,  8470,  8471,  8475,
    8476,  8480,  8484,  8495,  8494,  8503,  8507,  8511,  8518,  8522,
    8532,  8543,  8544,  8551,  8550,  8559,  8565,  8577,  8576,  8584,
    8598,  8597,  8605,  8618,  8620,  8621,  8629,  8628,  8637,  8645,
    8646,  8651,  8652,  8657,  8664,  8665,  8670,  8677,  8678,  8682,
    8683,  8687,  8688,  8692,  8696,  8707,  8706,  8715,  8716,  8717,
    8718,  8722,  8749,  8752,  8764,  8774,  8779,  8784,  8789,  8797,
    8835,  8836,  8840,  8880,  8890,  8913,  8914,  8915,  8916,  8920,
    8929,  8938,  8939,  8946,  8945,  8957,  8967,  8968,  8973,  8976,
    8980,  8984,  8991,  8992,  8996,  8997,  9001,  9005,  9017,  9020,
    9021,  9030,  9031,  9040,  9043,  9044,  9053,  9054,  9065,  9068,
    9069,  9078,  9079,  9091,  9094,  9096,  9106,  9107,  9119,  9120,
    9124,  9125,  9126,  9130,  9139,  9150,  9151,  9152,  9156,  9165,
    9176,  9181,  9182,  9191,  9192,  9203,  9207,  9217,  9224,  9231,
    9231,  9241,  9242,  9243,  9247,  9256,  9257,  9259,  9260,  9261,
    9262,  9263,  9265,  9266,  9267,  9268,  9269,  9270,  9272,  9273,
    9274,  9276,  9277,  9278,  9279,  9280,  9283,  9284,  9288,  9289,
    9293,  9294,  9298,  9299,  9303,  9307,  9313,  9317,  9323,  9324,
    9325,  9329,  9330,  9331,  9335,  9336,  9337,  9341,  9345,  9349,
    9350,  9351,  9354,  9355,  9365,  9377,  9386,  9398,  9407,  9419,
    9434,  9435,  9440,  9449,  9455,  9475,  9479,  9500,  9541,  9555,
    9556,  9561,  9567,  9568,  9573,  9585,  9586,  9587,  9594,  9605,
    9606,  9610,  9618,  9626,  9630,  9637,  9646,  9647,  9653,  9667,
    9684,  9688,  9695,  9696,  9697,  9704,  9708,  9715,  9716,  9717,
    9718,  9719,  9723,  9727,  9731,  9735,  9739,  9760,  9764,  9771,
    9772,  9773,  9777,  9778,  9779,  9780,  9781,  9785,  9789,  9796,
    9797,  9801,  9802,  9806,  9807,  9811,  9812,  9823,  9824,  9828,
    9829,  9830,  9834,  9835,  9836,  9843,  9844,  9848,  9849,  9853,
    9854,  9855,  9861,  9865,  9869,  9870,  9874,  9878,  9885,  9892,
    9899,  9909,  9916,  9926,  9936,  9946,  9959,  9963,  9971,  9979,
    9983,  9993, 10008, 10031, 10054, 10070, 10071, 10072, 10073, 10074,
   10075, 10079, 10083, 10100, 10104, 10111, 10112, 10113, 10114, 10115,
   10116, 10117, 10123, 10127, 10131, 10135, 10139, 10143, 10147, 10151,
   10155, 10159, 10166, 10167, 10171, 10172, 10173, 10177, 10178, 10179,
   10183, 10187, 10191, 10198, 10202, 10206, 10213, 10220, 10227, 10237,
   10244, 10254, 10261, 10273, 10281, 10282, 10286, 10287, 10291, 10292,
   10297, 10300, 10308, 10311, 10318, 10320, 10321, 10325, 10326, 10330,
   10331, 10332, 10337, 10340, 10353, 10357, 10365, 10369, 10373, 10377,
   10381, 10385, 10389, 10393, 10400, 10401, 10407, 10408, 10409, 10410,
   10411, 10412, 10413, 10414, 10415, 10416, 10417, 10418, 10419, 10420,
   10421, 10422, 10423, 10424, 10425, 10426, 10427, 10428, 10429, 10430,
   10431, 10432, 10433, 10434, 10435, 10436, 10437, 10438, 10439, 10440,
   10441, 10442, 10443, 10444, 10445, 10446, 10447, 10448, 10449, 10450,
   10451, 10452, 10453, 10454, 10455, 10456, 10457, 10458, 10459, 10460,
   10461, 10462, 10463, 10464, 10465, 10466, 10467, 10468, 10469, 10470,
   10471, 10472, 10473, 10474, 10475, 10476, 10483, 10483, 10484, 10484,
   10485, 10485, 10486, 10486, 10487, 10487, 10488, 10488, 10489, 10489,
   10490, 10490, 10491, 10491, 10492, 10492, 10493, 10493, 10494, 10494,
   10495, 10495, 10496, 10496, 10497, 10497, 10498, 10498, 10499, 10499,
   10500, 10500, 10500, 10501, 10501, 10502, 10502, 10503, 10503, 10504,
   10504, 10505, 10505, 10505, 10506, 10506, 10507, 10507, 10507, 10508,
   10508, 10508, 10509, 10509, 10509, 10510, 10510, 10511, 10511, 10512,
   10512, 10513, 10513, 10513, 10514, 10514, 10515, 10515, 10516, 10516,
   10516, 10516, 10517, 10517, 10518, 10518, 10519, 10519, 10520, 10520,
   10521, 10521, 10522, 10522, 10523, 10523, 10524, 10524, 10524, 10525,
   10525, 10526, 10526, 10527, 10527, 10528, 10528, 10529, 10529, 10530,
   10530, 10531, 10531, 10532, 10532, 10532, 10533, 10533, 10534, 10534,
   10535, 10535, 10539, 10539, 10540, 10540, 10541, 10541, 10542, 10542,
   10543, 10543, 10544, 10544, 10545, 10545, 10546, 10546, 10547, 10547,
   10548, 10548, 10549, 10549, 10550, 10550, 10551, 10551, 10552, 10552,
   10553, 10553, 10554, 10554, 10557, 10558, 10559, 10563, 10563, 10564,
   10564, 10565, 10565, 10566, 10566, 10567, 10567, 10568, 10568, 10569,
   10569, 10570, 10570
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
     955,   958,   984,   995,   998,  1001,   993,  1007,  1014,  1036,
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
       0,     0,     0,     0,  1399,   986,     0,     0,  1821,   863,
     862,     0,  1006,  1399,     0,     0,     0,     0,     0,     0,
     747,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,  1257,  1260,  1248,  1258,  1259,  1250,     0,     0,  1282,
    1280,     0,   695,     0,     0,     0,     0,  1786,   462,     0,
    1590,  1516,  1517,  1518,     0,     0,     0,     0,     0,     0,
       0,  1450,     0,  1449,     0,  1591,  1439,  1440,  1558,     0,
       0,     0,     0,     0,     0,     0,     0,  1582,     0,     0,
       0,     0,   476,     0,   480,   330,   329,  1726,  1734,   311,
       0,   598,   599,   594,  1731,   661,   658,   664,     0,   661,
     673,   648,   771,   816,   774,   770,  1784,     0,     0,  1506,
     825,  1500,   823,  1495,  1497,  1498,  1499,   828,     0,  1618,
    1478,   834,   835,     0,  1474,  1476,  1475,   846,   844,   845,
     870,     0,  1528,   873,   874,  1527,   877,   880,  1784,   888,
       0,  1460,  1632,  1492,  1551,  1555,  1493,     0,   898,  1798,
    1575,   944,  1364,   909,   913,  1495,     0,  1497,   953,     0,
     847,   956,   965,   964,   982,     0,   961,   963,  1398,     0,
     988,   992,   990,   993,   991,   985,   996,   997,  1490,   999,
    1000,  1822,  1002,  1472,   994,  1817,  1397,  1015,  1017,  1037,
    1038,  1041,     0,  1043,  1044,  1045,  1077,  1214,  1543,  1544,
       0,  1079,     0,  1086,     0,  1095,  1092,  1094,  1093,  1089,
    1096,  1116,  1478,  1103,  1114,  1105,     0,  1112,     0,  1529,
    1475,  1531,     0,  1142,  1624,  1146,  1346,  1463,  1152,  1798,
    1160,  1346,     0,  1174,  1167,  1464,     0,  1471,  1177,  1178,
    1179,  1180,  1181,  1182,  1203,  1183,  1206,     0,  1469,     0,
       0,  1542,  1555,  1211,  1246,  1233,  1251,  1730,  1271,     0,
    1264,  1266,     0,  1278,     0,  1284,  1285,   683,   689,   678,
     679,   680,   682,     0,  1288,     0,  1291,  1293,  1313,  1299,
    1356,  1346,  1787,     0,   466,   461,  1605,  1438,  1436,  1455,
    1457,  1438,     0,     0,     0,  1438,  1509,  1510,  1511,     0,
    1459,  1452,  1438,     0,  1437,  1559,     0,  1442,  1441,  1445,
    1444,  1447,     0,     0,  1438,     0,  1759,  1727,     0,   308,
       0,  1759,  1806,   659,  1759,     0,   670,   662,   663,   674,
     817,   750,  1727,   784,   775,     0,     0,     0,     0,  1501,
    1502,  1503,   826,   819,     0,     0,  1496,  1620,  1619,   831,
     836,   838,     0,   871,   841,  1530,   847,   875,   880,  1856,
    1857,   878,     0,   881,     0,   889,   886,  1839,  1838,  1461,
       0,  1634,  1462,  1553,  1554,   895,   896,   899,   893,  1391,
     945,   901,   692,     0,   907,  1366,     0,   924,     0,   918,
    1364,  1364,  1364,  1364,   954,   947,     0,     0,   848,   957,
     983,   959,  1399,  1399,   960,   967,   968,   692,  1423,  1424,
    1425,  1419,  1821,  1411,  1431,  1434,  1433,  1435,  1427,  1418,
    1417,  1422,  1421,  1420,  1426,  1406,  1410,  1428,  1430,  1432,
    1408,  1409,  1405,  1407,  1400,  1401,  1412,  1413,  1414,  1415,
    1416,  1404,   989,   987,  1491,  1004,  1818,   692,  1019,     0,
    1039,     0,  1066,  1050,  1042,  1047,  1048,  1049,  1218,     0,
    1545,     0,     0,  1087,  1083,     0,  1096,  1830,     0,  1104,
    1110,  1111,   692,  1107,  1399,     0,     0,  1115,     0,  1143,
    1127,  1625,  1626,  1798,     0,  1147,  1153,  1150,  1129,  1161,
    1155,  1157,  1169,  1175,  1164,     0,  1169,     0,  1523,  1524,
    1204,  1207,     0,     0,  1470,  1187,     0,  1186,     0,     0,
    1553,  1247,  1229,  1235,  1759,  1236,  1231,     0,  1249,     0,
       0,  1272,  1262,     0,  1265,     0,  1279,  1274,     0,  1286,
     690,   688,   681,     0,  1294,  1295,  1292,  1314,  1297,  1730,
       0,  1357,  1344,  1348,   460,  1730,   456,   464,   465,  1764,
    1604,     0,  1600,  1600,  1600,     0,  1586,     0,  1600,  1560,
       0,  1600,  1600,  1829,     0,   328,  1786,   307,   502,  1759,
    1759,  1720,  1772,   527,   501,   505,   506,     0,  1742,   613,
    1759,   603,  1826,   604,  1835,  1834,     0,  1759,     0,   616,
     607,   612,  1779,   608,     0,   611,   618,   615,   609,   614,
       0,   619,   610,     0,   630,   624,   628,   627,   625,   629,
     600,   631,   626,     0,  1779,     0,  1759,   671,     0,     0,
     649,   780,   785,   786,  1779,  1779,   778,   779,  1779,   766,
    1359,  1837,  1836,   763,   755,   757,   758,     0,  1359,     0,
       0,     0,   772,   761,     0,   769,   752,   768,   753,  1520,
    1519,     0,  1505,     0,  1784,  1369,   824,  1555,  1493,     0,
    1622,   831,     0,   829,     0,     0,  1477,   858,   879,   884,
       0,     0,  1494,  1369,  1759,  1633,  1552,   897,   692,   894,
    1393,  1365,   693,   911,  1726,   692,  1363,   917,   916,   915,
     914,   925,  1364,  1759,   928,     0,   931,   932,     0,  1759,
     935,   936,   937,   938,     0,   939,  1364,   926,     0,   786,
     904,   905,   902,   903,     0,  1369,     0,   854,   962,   977,
     979,   978,   972,   974,   980,  1399,   969,   966,  1399,   970,
    1429,  1402,  1403,  1786,  1003,  1473,   692,  1011,  1012,  1821,
    1027,  1028,  1030,  1032,  1033,  1029,  1031,  1022,  1821,  1018,
       0,  1067,     0,  1069,  1068,  1070,  1052,  1062,     0,     0,
    1046,  1220,     0,  1750,     0,  1080,  1369,     0,     0,     0,
    1098,  1108,  1121,  1117,  1122,  1118,  1123,     0,  1113,  1353,
    1352,  1120,  1129,  1347,  1539,  1540,  1541,     0,     0,  1391,
       0,   692,     0,  1168,     0,     0,     0,  1205,     0,  1209,
    1208,  1201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1189,  1190,  1627,  1391,     0,  1252,  1813,  1813,  1267,
    1268,  1269,     0,  1369,     0,     0,   691,     0,  1614,     0,
    1269,  1157,  1716,     0,  1759,  1612,  1587,  1588,  1589,  1610,
    1607,  1608,  1585,  1601,     0,  1583,  1584,   482,     0,     0,
    1881,  1882,  1759,  1720,     0,   499,   503,  1743,   507,     0,
       0,   601,   602,   605,   606,     0,   633,  1780,  1759,  1819,
    1759,   634,   632,   646,  1759,   665,   666,   669,     0,   660,
     675,   677,  1759,   788,     0,     0,   776,   777,     0,   692,
     767,  1361,   754,   756,  1359,   764,   759,   760,   773,   762,
    1522,  1504,  1521,  1632,     0,   692,   820,  1371,  1553,  1554,
    1369,     0,  1621,   830,   832,   839,   837,   866,  1757,   883,
     882,   887,     0,  1392,   692,  1390,   695,  1367,   906,     0,
     929,   930,   933,   934,     0,  1395,  1395,   927,   908,   920,
     921,   919,   922,     0,   948,     0,   849,   850,   664,     0,
    1399,  1399,   976,   692,   973,     0,  1010,   692,  1013,  1008,
       0,     0,  1034,     0,     0,     0,  1063,  1065,     0,  1058,
    1072,  1059,  1060,  1051,  1054,  1072,  1212,  1759,  1764,     0,
    1751,  1219,  1081,  1084,     0,  1098,  1097,  1101,  1090,     0,
    1109,  1106,     0,     0,  1131,  1130,   692,  1151,  1379,  1156,
    1158,     0,  1170,  1399,  1399,  1165,  1171,  1188,  1200,  1202,
    1192,  1193,  1194,  1198,  1195,  1199,  1196,  1197,  1191,  1628,
    1245,     0,  1242,  1243,  1237,     0,  1230,  1861,  1860,     0,
    1814,  1255,  1255,  1374,     0,  1632,  1275,     0,   684,     0,
    1615,  1300,  1301,     0,  1304,  1307,  1311,  1305,  1391,  1717,
       0,   470,   467,   468,     0,  1602,   309,   504,  1773,  1774,
    1563,   515,   512,   352,   528,   508,   509,  1534,   623,  1532,
    1533,   622,   639,   645,     0,   642,   667,   668,   677,   695,
       0,     0,  1359,   781,   783,   782,  1360,   692,  1358,   765,
    1369,  1494,  1370,   692,  1368,  1552,   821,  1623,  1525,  1526,
    1842,  1843,   868,   692,  1784,  1758,   865,   864,   860,     0,
    1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1635,  1394,
       0,   941,   940,   943,     0,  1537,  1538,   942,     0,   912,
    1369,  1460,  1369,  1460,   851,   852,     0,   856,   855,   857,
     975,   981,   971,  1005,  1009,  1020,  1023,  1024,  1738,  1016,
    1821,  1021,  1072,  1072,     0,  1057,  1055,  1056,  1061,  1222,
       0,  1216,  1752,  1369,  1091,  1100,     0,  1124,     0,     0,
    1138,     0,  1383,   692,  1378,  1159,   692,   692,  1172,  1244,
    1234,  1238,  1239,  1240,  1241,  1232,  1253,  1256,  1254,   692,
    1263,  1376,  1759,  1369,  1369,   686,  1289,  1614,  1303,  1748,
    1309,  1748,  1374,   692,   692,  1345,  1355,  1386,  1387,  1354,
    1351,  1350,  1769,   469,   463,   511,  1848,  1849,   514,   354,
     529,   510,   637,   635,   638,   636,   640,   641,     0,   617,
     643,   644,     0,   695,   787,   792,  1759,   793,   794,   795,
    1759,   796,   797,   798,   799,   800,   801,   802,   804,   805,
     806,     0,   807,  1718,   808,   809,   810,   789,   790,   751,
    1362,   822,  1372,   692,   842,   867,     0,   859,  1858,  1859,
    1396,   923,   950,     0,   949,     0,   853,  1025,  1739,     0,
       0,  1053,  1064,  1072,  1755,  1755,  1073,     0,     0,  1225,
    1221,  1215,  1085,  1099,     0,  1132,  1759,  1391,     0,     0,
    1133,     0,  1137,  1384,  1166,  1173,  1375,   692,  1373,     0,
    1277,  1276,  1315,   685,     0,  1302,     0,  1748,  1306,     0,
    1298,  1388,  1389,  1385,  1770,  1771,  1349,     0,  1759,  1759,
       0,   516,   517,   518,   519,   520,   521,     0,   531,   620,
     621,     0,     0,     0,  1759,  1395,  1395,  1719,     0,   791,
     869,   861,  1369,  1369,     0,  1035,  1071,  1756,     0,     0,
    1759,  1223,     0,     0,  1213,  1217,     0,     0,  1128,  1141,
    1381,  1382,  1140,  1136,  1134,  1135,  1377,  1270,  1322,   687,
    1308,     0,  1312,  1868,  1867,  1759,     0,     0,  1870,     0,
    1759,  1759,   513,  1806,     0,   812,   811,     0,   814,   813,
     815,  1535,  1536,   952,   951,  1026,  1075,  1074,     0,  1226,
    1759,  1399,  1139,  1380,  1342,  1341,  1323,  1316,  1317,  1718,
    1318,  1319,  1320,  1340,     0,  1310,     0,   526,   522,  1869,
       0,     0,  1753,  1781,  1720,     0,     0,     0,  1759,  1784,
     530,  1759,  1759,     0,   536,   538,   547,   539,   541,   544,
     532,   533,   534,   543,   545,   548,   535,     0,   540,     0,
     542,   546,   537,  1781,  1720,   676,   803,  1224,     0,  1125,
       0,  1811,  1786,   523,   525,   524,  1754,   586,  1782,  1783,
    1761,   572,  1759,   457,  1399,     0,     0,     0,     0,     0,
     580,     0,   570,   576,   579,     0,   573,   581,   584,  1761,
     575,  1227,     0,  1812,     0,     0,   571,     0,  1819,   568,
    1632,   564,  1507,  1872,     0,     0,  1874,  1876,     0,  1880,
    1878,   549,   553,   557,   557,   551,   555,   550,   556,   587,
       0,   578,   577,   583,   582,   574,  1339,  1841,  1840,  1794,
    1335,  1329,  1330,  1332,   562,   459,   585,  1786,   563,  1508,
    1871,  1875,  1873,  1879,  1877,   560,   552,   560,   554,     0,
    1795,  1786,  1338,  1333,  1336,     0,  1331,   454,     0,     0,
     559,   558,     0,     0,  1337,  1334,     0,   453,   567,   565,
     566,   561,   569,  1328,  1325,  1327,  1326,  1321,  1324,   455
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
     792,   664,   665,   666,   667,   668,   669,   670,  2546,  2677,
     671,   782,  1148,  1384,  1385,  1649,  1646,  2152,  2153,   672,
     673,   674,   675,   676,   992,   788,   789,  1182,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1190,  1421,
    1674,  1675,  1958,  2165,  1676,  2161,  2315,  2431,  2432,  2433,
    2434,  2435,  2436,  1955,  2164,  2438,  2493,  2550,  2551,  2621,
    2656,  2670,  2552,  2553,  2648,  2679,  2554,  2555,  2556,  2557,
    2558,  2559,  2592,  2593,  2596,  2597,  2560,  2561,  2562,   588,
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
    2414,  2478,  2517,  2518,  2519,  2687,  2520,  2641,  2642,  2665,
    2521,  2522,  2523,   947,  1146,  1380,  1585,  1931,  1881,  2305,
    1642,  1990,  1991,  2188,  1484,  1485,  1786,  2006,  2007,  2194,
    2290,  2291,  2408,  2097,  2469,  2098,  2274,  2306,  2307,  2308,
    1779,  1780,  2025,  2223,  1285,  1286,  1268,  1269,  1534,  1535,
    1536,  1537,  1538,  1539,  1540,   974,  1169,  1388,   976,   977,
     978,   979,  1211,  1240,  1469,  1326,  1334,   395,   396,  1012,
    1347,  1348,  1545,  1317,  1224,  1225,   541,   481,   301,   691,
     692,   482,    98,   153,  1277,  1242,  1212,  1446,  2611,  1395,
     981,  1751,  2001,  2075,  2197,  1234,  1318,  2168,  2500,  2224,
    1883,  2169,  1297,  1351,  1214,   983,  1243,  1244,   734,   784,
     785,  2170,   271,  2594,   179,  1215,   760,   761,  1216,   986,
     987,   988,  1177,  1150,  1403,  1399,  1392,   501,  2143,   537,
    1449,  1761,  2012,  1583,  2125,   282,  1472,  1775,  2218,   794,
    1091,  2150,  2448,   604,   339,   684,  1435,   423,  1198,   202,
     115,   393,  2379,   337,  1959,   352,  1010,   770,  2081,  2577,
    2458,  2209,    96,   214,   414,   739,  2426,  1954,   766,   402,
    1968,  2580,   798,  1383,   218,   488,  2661,   168,   390,   731,
     102,   719,   680,   831,  2604,  2131,   350,  1547,   951,  1283,
     407,   729,  1183,  1322,   391,  1728,  1748,  1470,  2639,  2203,
     184,   695,  2318,   708,   347,   596,  1463,  2370,  2129,   538,
     203,  2485,  2491,  2624,  2625,  2626,  2627,  2628,  1678
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2339
static const yytype_int16 yypact[] =
{
   -2339,   263,   507, -2339,  -204,   265, -2339,   507, -2339, -2339,
     622, -2339, -2339,   622,   622,   -40,   -40, -2339,   753, -2339,
     824,   635,   853, -2339, -2339,  1013,  1013,   610,   757, -2339,
   -2339,    15,   622,   -40, -2339, -2339,   868,   726, -2339, -2339,
     740,  1413,   -40, -2339, -2339, -2339,   635,   777, -2339, -2339,
     -86, -2339,   758,   758,   848,   879,  1058,  1058,  1058,   922,
     758,   948,   917,   920,  1058,   938,   946,  1379, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,  1143, -2339, -2339, -2339, -2339,
    1225, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    1273,  1005,    15, -2339, -2339,  1028,    60, -2339, -2339,  1058,
    1058, -2339,  1058,   980,  1423,   980,  1046,  1058,  1058, -2339,
   -2339,   980, -2339, -2339, -2339,   996,   872,  1052, -2339, -2339,
    1019, -2339,  1063, -2339, -2339, -2339, -2339,   376, -2339, -2339,
   -2339,  1187, -2339,  1058,  1069,   980,  1268,   -16, -2339, -2339,
   -2339, -2339, -2339,  1278,  1067,   823,  1342, -2339,  1045, -2339,
     996, -2339,    42, -2339, -2339, -2339, -2339, -2339,  1010,   -78,
    1058,   119, -2339, -2339, -2339,   -59, -2339, -2339, -2339,   796,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1069, -2339,  1100,
   -2339,  -167, -2339, -2339,   980, -2339,  1154, -2339,  1163,  1161,
    1512,  1058, -2339, -2339, -2339,  1009, -2339, -2339, -2339, -2339,
   -2339,   801,  1524,  1058,    90, -2339,   102, -2339, -2339,   172,
   -2339, -2339, -2339, -2339,  1331,   -78, -2339,  1356,   758,   758,
   -2339,  1010,  1140,   137,   403, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   -75, -2339,
     112, -2339,  1069, -2339, -2339,  1264, -2339, -2339, -2339,  1058,
    1200,  1348, -2339, -2339, -2339, -2339,  1204,  1058,  1108,  1386,
     499, -2339,  1606,   530,  1185, -2339, -2339,  1186,  1535, -2339,
    1331, -2339,   758, -2339, -2339, -2339, -2339,  1010, -2339,  1192,
    1333, -2339,   758, -2339,   814, -2339,    89, -2339, -2339, -2339,
   -2339, -2339,   -75, -2339,  1393,  1348, -2339, -2339, -2339,   609,
   -2339, -2339, -2339,  1394, -2339, -2339, -2339, -2339, -2339,  1382,
   -2339, -2339, -2339, -2339, -2339,  1203, -2339, -2339, -2339,  1638,
    1561,  1214, -2339, -2339,   -75, -2339, -2339,    34, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1230, -2339,  1480,
    1550,  1219, -2339,  1658, -2339, -2339, -2339, -2339,  2526, -2339,
    1591, -2339,  1175,  1232,  1286, -2339,   -75,  1416,  1334,   535,
    1288, -2339,  1292,  1058,  1634,   100,   -82,   856, -2339,  1194,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1272,
   -2339,  1436, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    1660,  1058, -2339,  1175, -2339,  1175, -2339, -2339,  1249,   521,
   -2339, -2339,  1058, -2339,  1464, -2339, -2339,   683, -2339, -2339,
     978,  1058,  1058, -2339,  1058,  1058, -2339,  1638, -2339,   117,
    1058,  1416, -2339,  1300,  1199,  1175, -2339,  1373, -2339, -2339,
   -2339, -2339,  1201, -2339,  1202,    71,     3,  1058, -2339, -2339,
    1169, -2339, -2339,   -92,  1289,   980,   980, -2339,  1395,  1395,
    1399, -2339,   980,  1058, -2339, -2339, -2339,  1348, -2339,  1311,
    1449, -2339, -2339,  1265, -2339, -2339, -2339, -2339, -2339,   980,
   -2339, -2339,     6,     6,  1708,     6, -2339, -2339,     6,     8,
   -2339, -2339, -2339, -2339, -2339,   701, -2339, -2339, -2339, -2339,
   -2339, -2339,   569, -2339,  1267,  1325,  1466,   526,  1274,  6300,
   -2339,  1220, -2339, -2339,   -13, -2339, -2339, -2339, -2339,  1203,
   -2339, -2339, -2339, -2339, -2339,  1058,   980,  1223, -2339,  1223,
   -2339, -2339,  1277,  1329,  1363, -2339,  1281, -2339,  1282, -2339,
    1646, -2339,  1649, -2339,  1262, -2339,  1611, -2339, -2339, -2339,
     980,   980, -2339,   -54, -2339, -2339,  1202, -2339,  1285,  1343,
    1349, -2339, -2339, -2339,   850,  1591,  1058,  1117,  1117,  1058,
      86,  1416,  1058,  1717, -2339,  1435, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339,   758,    73, -2339,   980,
   -2339,  1437, -2339, -2339,  1202, -2339,  1293,  1353, -2339,  6608,
     762,  1545,  1348,  1246,  1058,  1717,  1255,   666,   -92,  1348,
    1266,  1058, -2339, -2339, -2339,   -21,   758, -2339, -2339, -2339,
     735, -2339,  1202, -2339,  1315,   935,   746, -2339, -2339,  -194,
    -181,   363,   398,   455,  1271, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339,  1385, -2339,  1348, -2339, -2339, -2339, -2339,   980,
     980,  1541, -2339, -2339, -2339,   -69, -2339, -2339, -2339,  1058,
     120, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   860,
    -100, -2339,  1279, -2339,   550, -2339,  1330, -2339, -2339, -2339,
   -2339,  1255, -2339, -2339, -2339, -2339,  1521,    52,  1559,  1283,
    1058, -2339, -2339,  1058, -2339,  1136, -2339, -2339, -2339, -2339,
   -2339, -2339,  1656, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1269,
   -2339, -2339,  1339, -2339,  1324,  1346, -2339, -2339, -2339, -2339,
    1917,    48,  1763, -2339,  1397,  1397, -2339,  1280,  1487, -2339,
    1118,  1118, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    1347, -2339,  1348,    63, -2339, -2339, -2339,  1348, -2339, -2339,
    1388, -2339,    10,    10, -2339,  1447,  1295,    41,  2684,  3869,
   -2339,  1348,  1355,  6868,  1340, -2339,   980, -2339,    48, -2339,
    1364,  1549, -2339,  1634, -2339, -2339, -2339, -2339,  1118,  1357,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339,  1280, -2339, -2339, -2339, -2339,    20,  1379,
   -2339,    30, -2339, -2339, -2339, -2339,  1303, -2339,  6118, -2339,
   -2339,  1295,  1359, -2339, -2339,  1438,  4253, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339,   495, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339,  1412, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   676, -2339,
   -2339,  1476, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339,  1699, -2339, -2339,  1360,  2820,   -16,   -16,  1361,  1365,
    1367, -2339,  1369,   -16, -2339, -2339, -2339,  7141,  6868,  7141,
    1370, -2339,  1360, -2339,   219,   893,  -189, -2339,  1648, -2339,
   -2339, -2339, -2339, -2339,  1347, -2339,  1371,  1374,  1375,  6868,
   -2339, -2339,  -217, -2339,    48, -2339, -2339, -2339, -2339, -2339,
     -92,   -92, -2339, -2339, -2339, -2339,  1628, -2339, -2339,  1330,
    1348, -2339, -2339,  1368, -2339,  1384, -2339,   131,   131,  1317,
    1387, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339,   -97,  3850,  6868,   401,   644,   433,  1175,   461,
     716,  5536,  5628,  1570,   956,  1037,   461,   980,  1396, -2339,
   -2339,  5628, -2339, -2339,   461,  1303,  1314,   980,  4790,  5628,
   -2339,    -4,  3700,  1175,   980,  1175,   980,    58,   368,   980,
    1175, -2339, -2339, -2339, -2339, -2339, -2339,  4850,  5031, -2339,
   -2339,  1303,    85,   980,  1175,   980,   980,  1525, -2339,  3578,
   -2339, -2339,  1347, -2339,  1335,  1336,  6868,  6868,  6868,  2820,
    1337, -2339,  1032, -2339,  2820, -2339, -2339, -2339, -2339,  6868,
    6717,  6868,  6868,  6868,  6868,  6868,  6868, -2339,  2820,  6868,
     893,  1440, -2339,  1398, -2339, -2339, -2339,  1818,  1379, -2339,
     736, -2339, -2339, -2339, -2339,    43, -2339,   400,   464,   347,
   -2339, -2339, -2339,  1719,    94,  1657,  1487,   980,  2820, -2339,
    1721, -2339,  5058, -2339, -2339, -2339, -2339, -2339,   175,   689,
   -2339,   401, -2339,  1408, -2339,   -16, -2339, -2339, -2339, -2339,
    1723,  1885, -2339,   433, -2339, -2339,  1175,   702,  1487,  1725,
     389, -2339,  1470, -2339, -2339,  1324,  1347,  1175,  1726,  1334,
    1070,  1724,  5154, -2339,  5170,   140,  1111,  1123,  1727,   139,
    1376, -2339, -2339, -2339,  1728,    78, -2339, -2339, -2339,  4752,
   -2339, -2339,  1760,   495, -2339, -2339, -2339,   461, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,  1425, -2339, -2339,   424,  1303,
   -2339, -2339,    56, -2339, -2339, -2339, -2339, -2339, -2339,  1402,
    5628, -2339,  1421,  1730,  1822, -2339, -2339, -2339, -2339,    -4,
    1468, -2339,  1429, -2339,  4169,   -31,   741,  1433,  1439, -2339,
     869, -2339,  1441,  1740,   672, -2339,  1690, -2339,  1743,  1334,
    1744,  1690,   980,  1742,  1391, -2339,   751, -2339, -2339, -2339,
   -2339, -2339, -2339,  1620, -2339,   461, -2339,   -87, -2339,   355,
    1861, -2339,    67, -2339,  1746,   761,   531,  1846,  1748,  2760,
   -2339, -2339,   980,  1750,  5431,  1303, -2339, -2339,   648, -2339,
   -2339, -2339, -2339,  3592, -2339,  1701, -2339,  1157,  1752,  1788,
    1755,  1690, -2339,   980,  1683,   685, -2339,   237,   882, -2339,
   -2339,   405,  1462,  1463,  1467,   251, -2339,  1347, -2339,  1471,
   -2339, -2339,   254,  1472,   882, -2339,  1035,  -189,  -189, -2339,
   -2339, -2339,   918,  1473,   262,  1478,  1058, -2339,   -92,  1798,
    1465,   724,  6825, -2339,  1058,  1504,  1610, -2339, -2339,  1809,
   -2339, -2339,   751,  1731, -2339,   654,  2114,   -35,  1479, -2339,
    1347, -2339, -2339, -2339,  5644,  1735, -2339,  1704, -2339,  1554,
   -2339,  1595,  1691, -2339, -2339, -2339,  1376, -2339,   702, -2339,
   -2339, -2339,   -14,   556,   980, -2339, -2339, -2339, -2339, -2339,
    6868,  1674, -2339,  1340, -2339,  1175, -2339, -2339, -2339,  1718,
   -2339, -2339, -2339,  5628, -2339,  1668,   144,  1652,  1275,  1481,
    1786,  1786,  1786,  1786, -2339, -2339,  5628,  5644, -2339, -2339,
   -2339, -2339,   956,   197, -2339,  1451, -2339,  1469, -2339, -2339,
   -2339, -2339,  1396, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339,  4485, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,   -34, -2339,  1835,  1180,  1789,
   -2339,   751,   110, -2339, -2339,  1601, -2339, -2339,   141,  6868,
   -2339,  1522,   461, -2339, -2339,  5644,  1468,  1194,  1175, -2339,
   -2339, -2339, -2339, -2339,  1801,   980,   401, -2339,  1038, -2339,
   -2339, -2339, -2339,  1334,  1314, -2339, -2339, -2339,  1747, -2339,
   -2339,   485,  1843, -2339, -2339,   980,  1843,  1530, -2339,  1347,
   -2339, -2339,   235,  1010, -2339, -2339,  1174, -2339,  1929,   730,
      70, -2339, -2339, -2339,  1058, -2339,  -122,  5628, -2339,    38,
    5447, -2339, -2339,   980, -2339,  1784, -2339, -2339,  5644, -2339,
    1348, -2339, -2339,   751, -2339, -2339, -2339, -2339, -2339,  1846,
    1754, -2339, -2339,  1038, -2339,  1846, -2339, -2339, -2339,  1464,
   -2339,   980,  1371,  1371,  1371,  2820, -2339,   415,  1371, -2339,
    6990,  1371,  1371, -2339,    48, -2339,  1525, -2339, -2339,  1058,
    1058,  1717,   585, -2339, -2339, -2339, -2339,  1779,  1810, -2339,
    1058, -2339,   -73, -2339, -2339, -2339,  1372,  1058,  1885, -2339,
   -2339, -2339,  1688, -2339,  1348, -2339,  1932, -2339, -2339, -2339,
     980, -2339, -2339,   980, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339,  1785,  1688,   785,  1058, -2339,  1495,  1540,
   -2339, -2339, -2339,  1732,  1688,  1688,   189,  1753,  1688, -2339,
    1837, -2339, -2339, -2339,  1491,  1499, -2339,   751,  1837,  1771,
    1586,  1712, -2339, -2339,  1736, -2339, -2339, -2339, -2339, -2339,
   -2339,   438, -2339,   980,  1487,   476, -2339,   293,    97,   461,
    1567,  1554,   461, -2339,  1569,   401, -2339,   495, -2339, -2339,
    1637,  1654, -2339,   682,  1058, -2339, -2339, -2339, -2339, -2339,
    1729, -2339, -2339, -2339,  1988, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339,  1786,  1058, -2339,   586, -2339, -2339,  1389,  1058,
   -2339, -2339, -2339, -2339,   -10, -2339,  1636, -2339,  1242,  1732,
   -2339, -2339, -2339, -2339,  1819,   476,  1820,   127, -2339, -2339,
   -2339, -2339,  2004, -2339,  1584,   173, -2339, -2339,   197, -2339,
   -2339, -2339, -2339,  1525, -2339, -2339, -2339,  1900,  1890,  1396,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1667,  1396, -2339,
    1587, -2339,  1986, -2339, -2339, -2339,   704, -2339,   751,   943,
   -2339,    64,   685,    -8,   461,   461,   476,  1834,  1175,   117,
     870,  1897, -2339, -2339, -2339,  2031, -2339,  1844, -2339, -2339,
   -2339, -2339,  1747, -2339, -2339, -2339, -2339,   980,  1912,  1718,
     750, -2339,  1542, -2339,  1543,   751,   973, -2339,   438, -2339,
   -2339, -2339,  5628,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,   730, -2339,   503,  1718,   -46, -2339,  1619,  1619, -2339,
   -2339,   349,   980,   476,  1847,  1598, -2339,  1600,  2044,   980,
     426,   485,  2048,  1553,  1058, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339,  1059, -2339, -2339, -2339,   980,   433,
   -2339, -2339,  1058,  1717,  1803,  1295, -2339, -2339, -2339,   980,
     247, -2339, -2339, -2339, -2339,   247, -2339, -2339,  1058,  1355,
    1058, -2339, -2339, -2339,  1058, -2339, -2339, -2339,   104, -2339,
   -2339, -2339,  1058,  1557,   247,   247, -2339, -2339,   247, -2339,
   -2339,  1767, -2339, -2339,  1837, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339,  1470,   -35, -2339, -2339,  1765,   301,  1860,
     476,   713, -2339, -2339, -2339, -2339, -2339,   -25,    82, -2339,
   -2339, -2339,   483, -2339, -2339, -2339, -2339, -2339, -2339,   247,
   -2339, -2339, -2339, -2339,   247,   440,   440, -2339, -2339, -2339,
   -2339, -2339,  1571,   461, -2339,   461,  2322, -2339,   562,    21,
     197, -2339, -2339, -2339,  2004,   980, -2339, -2339, -2339, -2339,
    1572,  1490,   245,  1573,   713,   751, -2339, -2339,  2023, -2339,
   -2339, -2339, -2339,   943, -2339,  1887, -2339,  1058,  1464,  1762,
   -2339, -2339,   461, -2339,   461,   870, -2339, -2339, -2339,   884,
   -2339, -2339,   980,  5628,   766, -2339, -2339, -2339,  1799, -2339,
   -2339,  1815, -2339, -2339, -2339, -2339,  1543, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,    28,
   -2339,   980, -2339, -2339, -2339,   643, -2339, -2339, -2339,  6868,
   -2339,  5628,  5628,  1630,  1759,  1470, -2339,   461, -2339,   713,
   -2339,  1780, -2339,   751, -2339,  1979,  1664, -2339,   728, -2339,
     646, -2339,  1553, -2339,   980, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339,  1298,   -30, -2339,   980, -2339, -2339, -2339, -2339,
   -2339, -2339,   490, -2339,   433,   490, -2339, -2339, -2339,   384,
    2047,  1939,  1837, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    1693,  1898, -2339, -2339, -2339,  1902, -2339, -2339, -2339, -2339,
   -2339, -2339,  1813, -2339,  1487, -2339, -2339, -2339, -2339,   980,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    3340, -2339, -2339, -2339,  1332, -2339, -2339, -2339,  1275, -2339,
     476,  1749,   476,  1751, -2339, -2339,  5628, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339,  1490, -2339,  2006, -2339,
    1396, -2339, -2339, -2339,   713,  1210, -2339, -2339,  1210,   -66,
     980, -2339, -2339,   476, -2339, -2339,  1733, -2339,  2062,  1852,
    1878,   505, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,   882, -2339, -2339, -2339, -2339,
   -2339,  1823,  1058,  1693,   476,  1626, -2339,  2044, -2339,  1559,
    2025,  1559,  1630, -2339, -2339, -2339, -2339,  1829, -2339, -2339,
   -2339, -2339,  1377, -2339,   980,  1229, -2339, -2339,  1803, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   247, -2339,
   -2339, -2339,   247,   196, -2339, -2339,  1058, -2339, -2339, -2339,
    1058, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  2066, -2339,
   -2339,    -9, -2339,  2115, -2339, -2339, -2339,  1939, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339,   980, -2339, -2339, -2339,
   -2339,  1275, -2339,   461, -2339,   461, -2339, -2339, -2339,  2075,
    2015,  1210,  1210, -2339,  1670,  1670, -2339,  1793,  1175,   -26,
   -2339,   980, -2339, -2339,  5628, -2339,  1058,   600,  1869,  1870,
   -2339,  1871, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   980,
   -2339, -2339, -2339, -2339,  1684, -2339,   980,  1559, -2339,   980,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1152,  1058,  1058,
    1017, -2339, -2339, -2339, -2339, -2339, -2339,  1568, -2339, -2339,
   -2339,  2037,   247,   247,  1058,   440,   440, -2339,   447, -2339,
   -2339, -2339,  1693,  1693,  5628, -2339,  1210, -2339,  5628,  5628,
    1058,  1175,  1175,  1797, -2339, -2339,  1666,   980, -2339, -2339,
    1799, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1184, -2339,
   -2339,   980, -2339, -2339, -2339,  1058,  1803,  1803, -2339,  1938,
    1058,  1058, -2339,  2609,  1700, -2339, -2339,   433, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   401,  1175,
    1058, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1217,
   -2339, -2339, -2339, -2339,  2045, -2339,  1803, -2339, -2339, -2339,
    1803,  1803,  1933,  1083,  1717,  1944,  1348,  1655,  1058,  1487,
   -2339,  1058,  1058,   980, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339,   -53, -2339,   -51,
   -2339, -2339, -2339,  1083,  1717, -2339, -2339, -2339,   401, -2339,
    1791,  1737,  1525, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
     120, -2339,  1058,  1339, -2339,  7261,  7261,  1241,  2040,  1965,
   -2339,  1348,   -53, -2339, -2339,  1348,   -51, -2339, -2339,   120,
   -2339, -2339,   980, -2339,  1257,    53, -2339,   -53,  1355, -2339,
    1470,  7245, -2339, -2339,  1003,  1023, -2339, -2339,  1072, -2339,
   -2339, -2339, -2339,   -41,   -41, -2339, -2339, -2339, -2339, -2339,
    7261, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1826,
     830,    53, -2339, -2339, -2339,  1699, -2339,  1525, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,  1851, -2339,  1851, -2339,  2116,
   -2339,  1525, -2339, -2339,  1862,   980, -2339,  1741,    -5,  1848,
   -2339, -2339,  7261,   -36, -2339, -2339,  1348, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1175, -2339
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2339, -2339, -2339, -2339, -2339,  2160, -2339, -2339, -2339,   211,
   -2339,  2124, -2339,  2079, -2339, -2339,  1251, -2339, -2339, -2339,
    1383, -2339, -2339,  1237,  2146, -2339, -2339,  2046, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  1973,
     731, -2339, -2339, -2339, -2339, -2339,  2027, -2339, -2339, -2339,
   -2339,  1970, -2339, -2339, -2339, -2339, -2339, -2339,  2102, -2339,
   -2339, -2339, -2339,  1957, -2339, -2339, -2339, -2339,  1942, -2339,
   -2339,   810, -2339, -2339, -2339, -2339,  2034, -2339, -2339, -2339,
   -2339,  2008, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339,   977, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339,  1671, -2339,  1776, -2339, -2339, -2339,
    1720, -2339, -2339, -2339, -2339,   318, -2339, -2339,  1906, -2339,
   -2339, -2339, -2339, -2339,  1768, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    1188, -2339, -2339, -2339,  1422, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   623,
   -2339, -2339,  1702, -2339,  -755,  -820, -2339, -2339, -2339,   328,
   -2339, -2339, -2339, -2339,     2, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -1397,   774,  1458,   494,   524, -1392, -2339, -2339,
   -2339,  -383,  -444, -2339, -2339,   341, -2339, -2339,    54, -1388,
   -2339, -1386, -2339, -1384, -2339, -2339,  1417, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    -417,  -449, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2338, -2339,  -387, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339,  1380, -2339, -2339, -2339,    35,    37, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
    1195,   268, -2339,   166, -2339, -2339, -2339, -2339, -1791, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339,  -875, -2339, -2339,  -694,
   -2339,  1443, -2339, -2339, -2339, -2339, -2339, -2339,  1011,   493,
     498, -2339,   417, -2339, -2339,  -129, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,   469, -2339, -2339, -2339,  1012,
   -2339, -2339, -2339, -2339, -2339,   775, -2339, -2339,   186, -2339,
   -2339, -1254, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339,   776, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   752,
   -2339, -2339, -2339, -2339, -2339,     9, -1751, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   737,
   -2339, -2339,   733, -2339, -2339,   412,   191, -2339, -2339, -2339,
   -2339, -2339,   969, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,    -3,   696, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,   691, -2339,
   -2339,   176, -2339,   392, -2339, -2339, -1954, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
     941,   686,   168, -2339, -2339, -2339, -2339, -2339, -2339, -2274,
     937, -2339, -2339, -2339,   162, -2339, -2339, -2339,   373, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339,   325, -2339, -2339, -2339, -2339,
   -2339, -2339,   662,   153, -2339, -2339, -2339, -2339, -2339,  -152,
   -2339, -2339, -2339, -2339,   350, -2339, -2339, -2339,   921, -2339,
     923, -2339, -2339,  1137, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339,   133, -2339, -2339, -2339, -2339, -2339,   914,
     344, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339,   -22, -2339,   348, -2339, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -2339, -2339,  -364, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339,  -291, -2339,   637, -2339,
   -2339, -1664, -2339, -2339,  -711, -2339, -2339, -1666, -2339, -2339,
     -20, -2339, -2339, -2339, -2339,  -116, -1614, -2339, -2339,   -24,
   -1820, -2339, -2339, -1851, -1533, -1054, -1419, -2339, -2339,   755,
   -1766,   160,   161,   165,   167,    55,   -11,  -759,   304,   364,
   -2339,   679,  -717, -1379, -1010,   111,   955, -1542,  -392,  -972,
   -2339, -1303, -2339, -1039, -1732,   839,  -529,   -98,  1994, -2339,
    1603,  -556,    40,  2143, -1065, -1053,  -855,  -550, -2339, -1081,
   -1207, -2339,   399, -1276, -1424, -1089, -1154, -1211, -2339, -2339,
   -2339, -1112, -2339,   121,   909,  -635, -2339, -2339,  -103, -1187,
    -730,   -99,  2028, -1872,  2057,  -665,  1539,  -504,  -566, -2339,
   -2339, -2339,   -93,  1328, -2339, -2339,   361, -2339, -2339, -2339,
   -2339, -2339, -2339, -2339, -2339, -2339, -1957, -2339, -2339,  1556,
   -2339, -2339,  -216,  -591,  1888, -2339,  1115, -2339, -1306,  -258,
    -592,   894, -2339,  1795, -2339, -1423, -2339, -2106, -2339, -2339,
     -79, -2339,   -29,  -651,  -356, -2339, -2339, -2339, -2339,  -128,
    -370,  -255, -1191, -1536,  2094,  1863, -2339, -2339,  -335, -2339,
   -2339,   998, -2339, -2339, -2339,   397, -2339,   256, -1924, -1460,
   -2339, -2339, -2339,  -150,   458, -1383, -2170, -2339, -2339, -2339,
    -718, -2339, -2339,  1615, -2339,  1758, -2339, -2339, -2339,   763,
   -2339, -2279,  -264, -2339, -2339, -2339, -2339, -2339, -2339
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1831
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   689,   138,   215,   141,   139,   741,
     415,   579,  1256,   147,   733,  1437,  1350,   160,  1014,   759,
     778,   838,  1862,   404,   975,  1704,  1870,   103,   104,   105,
    1706,   245,   139,   427,  1707,   111,  1708,   180,  1709,  1714,
    1771,  1874,   696,   464,  1604,  2173,  2190,  1464,   437,  1288,
    1267,  1620,  1830,  1278,   990,  2037,  1223,   747,  1473,   268,
    1597,  1278,  2640,  1349,   211,  1755,   980,  1332,  1000,  2099,
     134,   135,   463,   136,  1995,  1278,   790,  1456,   143,   144,
    1833,   246,  2162,  1402,  1824,  -652,   838,   161,  2204,  1241,
     321,   345,  1194,    99,  2126,  1502,   843,  1413, -1544,   259,
     107, -1545,  1617,   264,   169,   768,   411,  2021,  2237,   114,
    1570,   535,  1560,  2035,  2445,   821,   821,  1749,  1815,  1851,
     825,  2258, -1830,   790,  1432,   215,   448,   360,   465,   291,
    1948,   219,   127,  1747,  2683,  2655,  2176,   228,   279, -1799,
    2200,   744,   211,  1290,  1457,   529,    94,  2124,  1551,  2044,
   -1764,  2490,   297,   700,   216,   413,  1721,    42, -1726,  2387,
   -1726, -1830,   251,   821,   480,  1610,  1305,  1852, -1786,  1366,
    1432,  2678,   392,   737,   258,   222,  1194,  2462,  2293,  1961,
    1194,   229,  1223,  1790,  1337,  2227,  1866,  1512,  1496,  2684,
    2179,   230,   701,  2416,  1819,  2419,   327,  2685,  2127,  1917,
    2083,   221,   182,  2160, -1726,  2160, -1726, -1830,   581,  1162,
    2079,  1202,   717,   412, -1730,   220,    23,   985,  1819,   419,
     295,  1306,  1220,  -652,  1544,   717,  1008,  -652,   299,  1307,
    1180,   128,  1447,  2590,  2567,  1544, -1828,  1007,  1154,  1155,
    1787,  1238,    43,   796,   608,  1160,  1254,    15,  1769,  1923,
     980,   980,   980,  1684,  2632,  1685, -1786,  2136,   274,   275,
     749,  1173,   505,     3,   512,   535,   832,  2492,   418,  2644,
    1174,   232,   980,  1770,   212,  1850,  2591,   609,  2595, -1830,
    1602,  2686,   718,  1364,  1181,  -652, -1746,  1853, -1830,  1166,
     183,  2463,  1278,   453,  2601,   720,  1544,  2055,  2381,  2382,
   -1571,   204,    24,    43,   752,  1750,  2080,  1166,  2622,  1220,
    2205,  2481,   311,  1308,   753,   738,  1962,  1550,    94,   999,
    1151,  1166,   314,  2564,  1166,  2441,  2085,  1918,  2309,  1184,
    2189,   582,  1166,  1928,   410,  1218,   243,   413,   223,  1933,
     139,   233,   139,   139,  2196,   217, -1726,   485,   486,   139,
     466,  1854,   212,  2279,   491, -1817,     5,  1927,   493,  1603,
     154,  1238,   424,   283,  2128,   -35,   139,  1497,   745,   507,
     507,   485,   507,   436,  1238,   507,   514,   980,  2238,  2060,
    2010,   243,   443,   444,  -650,   445,   446,  2333,  2063,  1153,
    2206,   452, -1726,  1629,   754,  1238,  1194,  1391,  1391,  1391,
   -1730,   985,   985,   985,   449,   467,  1824,   137,   469,  1824,
    1404,  1406,   137,   139,   129,  1337,   826,  1412,   542,  -657,
    1571,  1552, -1764,   985,   492, -1726,  -652,   280,   728,  2456,
    1238,  2388,   980,   601,  1241,   236,  2201,   139,   139,   980,
     980,   980,   542,   580,  1185,  1186,  2437,   749,  1267,   281,
    1382,  1294,   980,   980,   980,   980,   980,   980,   980,   980,
     260,  1994,   980,   137,   755,   368,   450,  1238,   394,   137,
     137, -1726,  2036,  2446,  2319,  1166,   139,   284,  1605,  1788,
    1527,   580,  1238,   702, -1730,  1001,   540,  1241, -1730,  2053,
     536,   752,  1553,   686,  -657,   139, -1550,  1865,   767,   137,
     697,   753, -1799,   154, -1548,   577,  1835,  1452,   756,  1278,
     137,  2049,   137,  2018,   137,  1474,   130,  2210,  2359,  2239,
    1725,  1336,  -650,   243,  2361,   591,  -650,   593,   985,   783,
     598,   600,   989,   602,  1966,   996,  1367,  1878,   844,   346,
     322, -1730,  2207,  1213,   823,   732,   149,   735,  1467,  1544,
    1295,  1255,  1259,   265,   292,  1241,  1321,   137,   757,   747,
     679,  1284,   137,  2004,  2372,   688,  2374,   749,  1302,  1304,
    2008,  2277,   699,  1439,  1939,   394,  2502,  2472,  1855,  1503,
     749,   754,  2068,   985,  -650, -1759,   261,  1361,  1213,  1368,
     985,   985,   985,  1398,  2498,  2499,  1419,  2392,  1398, -1830,
     748,   749,   517,   985,   985,   985,   985,   985,   985,   985,
     985,   752,  1398,   985,  2527,  2528,   607,  1167,  1241,  2107,
    2037,   753,  1474,    97,   752, -1730,  1820,  2410,  2411, -1730,
     740,  1824,  1829,  1171,   753,  1167,   749,  1821,  1172,  1337,
    2252, -1629,  1441,  1488,   536,   752,   704,  1367,  1789,  1167,
    1820,   755,  1167,  2646,  2573,   753,  1940,  1220,  2574,  2575,
    1167,  1821,  1512,   824,  2230,  1321,  2232,  1168,   829,   834,
     834,   772,  1837,   749,   773,   243,   255,   283,  1006, -1830,
     752,  1896,   949,   991,  2645,  1650,  1546,  2598,   749,  1232,
     753, -1817, -1830,   430,  2000,   756,   154,  1871,  1109, -1609,
    1368,   754, -1606,  2160, -1730,  2263,  1237,     4,  1249,  2014,
    1662,  1773,  1647,  1851,   754,  2296,    16,   752,  1684,  1541,
    1685,  2398,   747,  -655,  2598,  -650,  2016,   753,   -96,  2096,
     129,  1324,   752,  1329,  1109,   754,   518,  1420,  1355,   137,
    2049,  2399,   753,  1776,   351,   757, -1512, -1830,  1321,  1241,
    1561,   137,  1377,   980,  2171,   783, -1830,  2167,  2294,   305,
    2322,  1852,   749,   989,  2211,  2212,  2213,  2400,  1903,   717,
     754,   755, -1830,  2183,  2184,    18,  1904,  2185,   839,  1810,
    1811,  1812,  1813,  2471,   755,  1669,  2503,  2504,   681,  2253,
    2380,   284,  2401,  2119,   750,   751,  2120,  -500,  -655,  2082,
    1648,  1606,  1752,  1167,   717,   755,   752,   754,   438,  1361,
    1424,  1278,  1544,  1670,  1671,   756,   753,  1975,  2221,  2323,
   -1830,  1427,   754,  2222,   226,  -500,  -500,  2214,   756,  1772,
    2383,  1778,   130,  1952,  1953,  1367,   519,  1607,  2030,   722,
     755,  1468,   980,   839,  1458, -1730,  2461,  2311,     5,   756,
    1514,  1515,   243, -1611,   439,  1476,  2513,   187, -1512,   137,
    2157,   717,  1665,  1171,   188,   757,   328,  2298,  1172,   -96,
    2235,  1110,   137,  2643,   724,    27,  1425,   755,   757,   187,
    1776,  1853, -1732,  1941,   756,  2303,   188,  2005,  1368,  1516,
    1517,  2273,   755,   137,  1756,  1976,   754,   139,   139,   757,
     306,  1944,   154,  2023,   985,   137,  1724,  1110,    28,  2643,
    2027,  1189,  1448,   431,  1479,  1227, -1066,  1337, -1744,  1885,
    2509,   756,   227,  2225,  2225,   749,   253,   243,   137,   243,
     137,   726,  1131,  1784,   757,  -647,   756,   137,  1613,  2312,
    -500,  1905,   137,   980,   137,  1854,  1814,  1816,  2324,  2215,
    2216,   137,  2069,  2325,  2217,  1527,    94,  1581,   682,  1778,
   -1066,  2056,  1428,   749, -1830,   137,   755,  2310,  -500,   752,
   -1066,   757,  1424,  1906,   693,  2031,     5,   525,  2569,   753,
     137,   405, -1830,  2269,  1541,  1725,   757,   253,   243, -1830,
     715,    33,  1226,   985,  1588,  1907,  1245,  2241,  1614,  1947,
    2070,  1615, -1830,  1245,  1280,  2402,  1582,   752,   228,   705,
     756,  1245,  2100,  2366,  1299,  1867,  2102,   753,  1886,  1320,
    2304,  1327,  1132,  1327,  1335,  1352,  1299,  2009, -1830,  1544,
   -1613,   742,   406,  2231,   243,  2233,  2605,  2101,  1425,    36,
    1591,   154,  1630,  1327,   329,  1672,  1879,   716,  1908,  2276,
   -1066,  2609,   229, -1830, -1759,  2524,  1901,  -500,  1459,   754,
     757,    39,   230,  1133,   743,   187,  1228,  1916,  1229,   189,
    1920,  2488,   188,  -647,  1241,  1880,   231,  -647,  1924,   822,
    1951,  2028,    94,  1777,   694,  2329,   706,  1462,   707,  1398,
    1643,   189,  1134,  2005,   985,  2038,  2544,   754,  1528,  1631,
    1529,  2545,   325,   330,    94,  2547,  2489,  2548,  1909,  2549,
    2563,  2668,   154,   300,  2186,   515,  2002,  2439,  1226,   799,
   -1066,  2440,  1321,  2483,    48,  2673,   997,  1241,   154,   755,
    2192,  2688, -1830,  2484,   344,  -647,  2662,  1245,  1549, -1512,
    1171,   190,   232,   416,   117,  1172,  2265, -1512, -1512,  2219,
     137,    40, -1512,   516,    52,   749,  2167, -1830,   800,   801,
     802,   803,   804,   190, -1066,   316,   400,   755,  2663,   583,
    1247,  2266,  1855,   756,  1245,  1673,  1460,    49,  2242,   155,
    1206,   156,  2244,   747,  2071,  1245,  1135,  -500,  2664,  1839,
    2650,    51,  1840,   626,   627,  1841,  1842,   191,   361,   752,
    2163,    53,   192,  1910,  1387,   243,  1619,   611, -1066,   753,
    2651,   756,   233,  2529, -1066,   234,   235,   137,  2384,   191,
     394,  2272,  1574,   757,   192,  2447,   317,   318,    93,  1335,
     362,  2495,  2496,  2652,  1414,   709,  1270,  1331,  1298,    54,
    1575,    55,  1245,    56,   819,   819,  1245,  2385,  1882,  2087,
    1298,    57,   254,    26,  2570,   137,   952,  1381,  2483,  2653,
     187,   757,    97,  2002,    21,    22, -1830,   188,  2484,   243,
      47,   100,   712,   953,   820,   820,  -647,   189,  2195,    91,
     139,   170,  2654,    46,   101,  1644,   470,   471,   472,   754,
      94, -1744,   819,  1934,  2613,  2488,   805,   806,   807,   808,
     809,   810,   811,   639,   640,   255,   236,    58,  1462,   555,
    1793,  2514,  2360,  1794, -1550,   139,   106,   155,  2362,   156,
    1795,  1796,   820,   747,   556,   171,  1898,   193,  2365,   403,
    2614,   783,  2220,  2225,  2225,   172,  2501,   441,  2039,  2040,
    1171,  1757,  1170,  2320,  1974,  1172,  2199,  2483,  2586,   190,
    2515,  1171,  2109,   108,  1984,  1985,  1172,  2484,  1988,   755,
    1271,  1272,  2159,  2452,   557,  2453,  1797,  1660,   109,  2191,
    2285,   110,   351,   243,   394,   954,  1171,  1273,  2610,  2612,
    1651,  1172,  2578,  2579,  1655,    13,   749,  1664,  2516,   112,
      13,  1657,  1677,  1713,  1757,  1715,   952,   113,  2403,  2199,
      60,  2404,  2405,   756,  2649,   191,  2427,   473,  2566,  1262,
     192,  2072,   980,   953,  2406,   173,  2428,  1869,  2637,  1208,
    1263,   474,  2638,  2659,    52,   956,  1899,   957,  2421,  2422,
     752,  1274,   958,   959,   960,  1798,   114,  1900,   961,  2429,
     753,  1890,  1226,   120,    61,  1209,   122,   137,   812,   592,
     508,  1897,   510,   757,   599,   511,   124,  1843,  1844,  1245,
     252,   813,  1757,  1423,  1799,  2682,  1915,  1423,   594,  2430,
     595,    53,   189,  1226,  2199,  1407,  1408,   962,   428,   126,
    1401,  1845,  1846,  1659,   137,   174,  1800,   706,  2450,   707,
    1171,   140,   749,  1171,    94,  1172,   963,   142,  1172,  1245,
     149,   558,  1840,   162,   475,  1841,  1842,  2155,  1634,    54,
    1635,    55,   559,    56,   164,   954,   476,  1171,  1393,  1394,
     754,    57,  1172,   163,   181,  1757,   749,   167,  1963,   175,
    1964,  1926,  2476,    64,   185,   186,   752,  1409,  1410,  1411,
    1801,   204,   242,  2268,   190,  2032,   753,  2033,   139,   193,
    2316,   964,  2317,  1935,   247, -1528, -1528, -1528, -1528,  1936,
    1937,  1938,  2615,   985,   248,  1942,  2616,  2617,  1945,  1946,
     752,   249,   958,   959,   960,   250,    67,    58,   961,   176,
     753,  2287,  2287,   257,  2368,  1913,  2369,   269,   273,  2199,
     755,   278,   294,  1802,   118,  1969,  1490,  1491,  1492,  1493,
     191,   296,   965,   966,   154,   192,   477,  2618, -1527, -1527,
   -1527, -1527,   300,   560,   561,   302,  1977,   962,   721,   723,
     725,   727,   137,  2619,  2620,  2314,   754,  1899,   562,  2424,
     563,  2425,   303,  1731,   756,  1732,   307,   308,  1900,    59,
    1949,  1950,   309,   312,   970,   313,  1161,    68,  1163,   326,
     333,  1960,  1245,  1803,   334,   298,  1245,   336,  1965,  1245,
     754,   338,  1226,   340,   971,   342,  1804,   349,   351,   972,
      60,  1793,   353,   354,  1794,   356,   973,   392,   137,   394,
     398,  1795,  1796,   397,   757,   403,  2376,  1978,   401,   408,
     187,   964,   982,   428,   409,   420,   755,   243,   421,   422,
     429,   413,   454,   455,   457,   494,  -342,   459,   483,   490,
     495,   487,  1245,   564,    61,   509,   502,    62,   521,   522,
    2089,   523,  2261,   548,   533,   527,   543,  1797,   547,   549,
     755,  -355,   551,   552,   554,   578,   585,   586,   587,   603,
     756,   605,   965,   966,   613,  2022,   610,   614,  1805,   685,
     687,  2110,  2111,  2112,  2113,  2114,  2115,  2116,  2117,   690,
     565,  1245,  1245,  1245,  2029,   698,   711,  1843,  1844,   730,
    2034,  2134,   728,   736,   756,   765,   762,   769,   777,   780,
    2134,  1890,    63,   746,   970,   781,   783,   771,   786,   791,
     757,  1845,  1846,   797,   823,   836,  1798,   793,   830, -1613,
     950,  1482,   989,    64,   971,   995,   994,  1011,   998,   972,
    1016,  1120,  1139,  1147,  1019,  1187,   973,  1175,   137,  1191,
    1245,  1200,  1149,  1156,   757,  1799,  1260,  1157,    65,  1158,
      66,  1159,  1164,  1176,  1382,  1193,  1178,  1179,  1201,  1389,
    1390,  1400,  1281,  1415,  2466,   139,    67,  1800,  1417,  1430,
    2156,  1416,  1442,  1436,  1451,  1453,  1471,  1299,  1465,  1480,
    1477,  1542,  1299,  1494,  1559,  1500,  1546,  1562,   980,   980,
    1563,  1565,  1567,  1498, -1530,  1576,   982,   982,   982,  2177,
    1578,  1299,  1299,  1579,  1577,  1299,  1584,  1586,  1593,  1589,
    1595,  1337,  1609,  1611,   980,  1194,  1621,  1633,   982,  1626,
    1639,  1801,  1637,  1645,  2505,  2154,  1641,  1245,  2506,  2507,
    1652,  1653,  1666,   980,  1716,  1654,  1668,    68,  1719,  1656,
    1658,  1661,  1717,  2158,  1663,  1753,  1299,  1760,  1722,  2606,
    1762,  1299,  1299,  1299,  1764,  2089,  2226,  2226,  1759,  2172,
    1245,  2174,  1245,  2581,  2271,  2175,  1774,  1220,  2635,  1778,
    1791,  1482,  1825,  2180,  1802,   980,   618,   619,   620,   621,
     622,   623,  1785,  1836,  1849,  1808,  1552,   952,  1864,  1872,
    1828,  2335,  1891,  2600,  2336,  1887,  1895,  2337,  1902,  1245,
    1922,  1245,  1929,  1956,   953,  2338,  1957,  1967,  1970,  1973,
     625,  1980,   626,   627,   628,   629,   630,   631,   632,  1979,
    1992,  1205,  1989,  1219,  1982,  1724,  1235,  1993,  1996,  1997,
    1257,  1998,  1999,  2011,  1803,  2015,  2020,  2019,  1432,   985,
     985,  2050,  2043,  2045,  2024,  1293,  2051,  1804,  2057,  2058,
    2339,  1319,  2061,  2064,  1245,  2065,   633,  2084,  2090,  2092,
    2093,  2096,  2130,  2103,  2104,   985,  2139,  1299,  2260,  2138,
    2137,   139,  1375,  2140,  1379,  2149,   542,  2151,   982,  2160,
    2181,  2187,  2193, -1549,   985,   982,   982,   982,  1396,   428,
    2245,  2251,  2254,  1396,  2228,  2257,  2262,  2275,   982,   982,
     982,   982,   982,   982,   982,   982,   954,  1396,   982,  2292,
    2273,  2289,  2299,  2297,  2334,   634,   635,   636,   637,   638,
    2301, -1505,   639,   640,  2005, -1547,   985,  2363,  2378,  1805,
    2373,  2394,  2375,  2393,  2395,  2396,  1438,   428,  2412,  2407,
    2417,  2304,  2444,  2447,  2454,  2455,  2457,  1245,  2340,  1245,
    2460,  2473,  2474,  2475,  2510,  2479,   641,  2341,  1729,  1730,
    1319,  1455,  1235,   958,   959,   960,  2494,  2511,  2529,   961,
    2342,  2565,  2572,  2582,  2576,  2603,  2584,   139,  2602,  2629,
    1245,  2630,  2390,  2660,  2669,  2672,  2676,    17,  2674,  2681,
      92,   125,    38,   166,   256,   209,   266,   119,   277,  1731,
     290,  1732,  2343,  1733,   210,   241,   442,  2086,   962,   504,
     545,  1245,   323,   456,   643,   835,  1705,  1188,   787,   526,
    2608,  2667,  2344,  2078,  2345,   993,  2313,  2658,  2671,  2634,
    2330,   139,  2331,  1199,  2236,  1434,   580,  1734,  1735,  1736,
    1987,  1015,   948,  1319,  1986,  1299,  2042,  2346,  2449,  1299,
    2013,  1767,  2234,  1450,  1768,  1783,   645,  2371,  1826,  1818,
    2054,  2240,  1543,  2377,  1848,  1598,  1860,   647,  2066,  2256,
    1566,  1569,  1868,  2264,  2267,  2094,  2148,  2347,  1894,  2278,
     648,  2118,   964,  2409,  1600,  2288,  1353,  1737,  1601,  1738,
    1245,  1625,  1245,  1624,  2146,  2415,  1739,  2666,  2147,  1740,
    1932,  2470,  2420,  2423,  2348,  2281,  2282,  1592,  2465,  1832,
    2283,  1766,  2284,   332,   764,   213,   428,  2108,   310,   293,
    1165,   795,  1418,  2571,   539,   447,  2459,  2442,  2599,   272,
    2349,  2443,   489,   965,   966,  2132,   597,  2350,  2250,  2077,
     774,  1863,   984,  2623,   652,   653,   654,     0,  -854,     0,
    2351,  -854,     0,     0,  2352,     0,     0,     0,     0,  1299,
    1299,  1598,  1299,  1299,     0,  1299,  2226,  2226,     0,     0,
       0,     0,     0,     0,     0,   970,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1741,  2467,  1742,     0,
       0,  1194,     0,     0,     0,   971,     0,     0,     0,   982,
     972,     0,     0,  2353,     0,  1337,     0,   973,     0,   137,
       0,     0,     0,     0,   656,   657,   658,     0,     0,  2486,
    2487,     0,     0,     0,  -854,  1226,     0,     0,     0, -1730,
       0,     0,  2354,     0,     0,  2497,     0,     0,     0,     0,
       0,  -854,  2355,     0,     0,     0,     0,     0,  2356,     0,
       0,  2508,     0,     0,     0,     0,     0,  2583,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2526,     0,     0,     0,
    1598,  2530,  2531,     0,     0,  1226,     0,     0,   982,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2568,     0,     0,  1877,     0,     0,     0,     0,     0,
       0,     0,  2631,  1884,  1152,     0,  2633,     0,     0,     0,
       0,     0,  1226,     0,  1893,     0,   984,   984,   984,  2585,
       0,     0,  2587,  2588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -854,     0,     0,     0,     0,   984,     0,
     357,     0,  1921,     0,  -854,     0,     0,     0,  1226,     0,
       0,     0,  1598,     0,     0,   358,     0,     0,     0,     0,
       0,     0,     0,  2607,     0,   359,     0,  1743,     0,     0,
       0,     0,  2675,     0,  1396,     0,     0,  -854,     0,   982,
       0,     0,     0,  -854,     0,  -854,     0,  2689,  -854,     0,
    -854,  -854,  -854,     0,     0,     0,  -854,     0,  -854,   360,
       0,     0,     0,  -854,     0,     0,     0,  1319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1744,     0,  1971,
       0,     0,  1972,     0,     0,     0,     0,     0,  1745,     0,
       0,     0,     0,     0,     0,  -854,     0,     0,     0,     0,
    -854,     0,     0,   984,     0,     0,     0,     0,  1246,     0,
       0,     0,     0,     0,  -854,  1246,  1598,     0,     0,     0,
       0,     0,     0,  1246,   624,     0,     0,     0,     0,     0,
       0,     0,  2003,     0,     0,     0,     0,  1246,  -854,     0,
       0,     0,     0,  1684,  1731,  1685,  1732,     0,     0, -1730,
       0,     0,     0,     0,     0,   846,     0,   847,   984,   848,
       0,     0,     0,     0,   849,   984,   984,   984,  1397,  -854,
       0,     0,   850,  1397,     0,     0,     0,     0,   984,   984,
     984,   984,   984,   984,   984,   984,     0,  1397,   984,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -854,     0,     0,   851,   852,     0,  -854,     0,
       0,     0,     0,     0,   853,     0,   361,  1440,     0,     0,
    -854,  -854,     0,     0,     0,   854,     0,     0,   855,     0,
       0,     0,     0,     0,     0,     0,  1206,  1598,  1598,   747,
       0,     0,   856,     0,     0,     0,     0,     0,   362,  1246,
       0,     0,  -854,     0,     0,     0,     0,     0,  -228,     0,
       0,     0,  -854,     0,     0,   857,  2095,     0,  -854,     0,
       0,     0,     0,   858,  1598,   859,     0,     0,     0,     0,
       0,     0,  -854,     0,     0,     0,  1246,  -854,  2532,     0,
   -1730,     0,     0,     0,  -854,     0,  -854,  1246,     0,     0,
       0,  2135,  -854,     0,     0,     0,   860,     0,  2145,  2145,
       0,   363,   952,     0,   642,     0,   364,   861,     0,     0,
       0,     0,   862,     0,     0,     0,     0,     0,  1235,   953,
       0,  2533,     0,  2534,     0,     0,     0,     0,  2166,     0,
       0,     0,  1357,     0,     0,  1599,     0,   365,     0,   863,
       0,     0,     0,     0,  1246,   366,   864,     0,  1246,   865,
     866,     0,     0,     0,  2535,     0,     0,     0,   367,   867,
       0,     0,   952,     0,     0,     0,   868,     0,   869,     0,
       0,   870,     0,     0,  2536,     0,     0,     0,     0,   953,
    2198,     0,     0,     0,     0,     0,     0,   368,     0,     0,
     369,     0,     0,     0,     0,     0,   646,     0,   370,     0,
       0,     0,  2537,     0,     0,     0,     0,     0,     0,  -225,
       0,     0,     0,   871,     0,     0,     0,   872,     0,   873,
       0,   954,     0,     0,  2243,     0,     0,     0,     0,   874,
       0,  1599,   749,  2198,  1598,     0,     0,   371,     0,     0,
     372,     0,  1598,  1758,     0,     0,     0,     0,  1623,     0,
       0,     0,     0,     0,     0,   875,     0,     0,     0,     0,
       0,  1877,     0,     0,     0,  1208,     0,     0,   876,   984,
       0,   956,     0,   957,   651,     0,   752,     0,   958,   959,
     960,   954,     0,  2538,   961,     0,   753,     0,     0,     0,
    2280,  1209,   749,   877,   878,     0,  1758,     0,   982,     0,
    2539,     0,     0,     0,   879,     0,     0,     0,  2198,     0,
       0,     0,  1598,     0,     0,     0,     0,     0,   880,   881,
    2540,     0,     0,   962,     0,   882,     0,     0,     0,   883,
       0,     0,     0,     0,  2321,     0,   752,   884,   958,   959,
     960,  2541,   963,  1235,   961,     0,   753,   885,     0,     0,
    1599,     0,     0,     0,     0,     0,   886,     0,   984,     0,
    2542,  1246,     0,     0,  1758,   887,   754,   660,  2543,     0,
     888,   889,     0,     0,   890,     0,   891,     0,  2367,     0,
       0,     0,   892,   962,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   893,     0,   964,     0,     0,
       0,  1246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   894,     0,     0,     0,     0,     0,   895,
       0,     0,     0,  2198,   896,     0,   754,  1758,     0,     0,
       0,     0,  1599,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,   897,     0,     0,  1397,     0,     0,   964,     0,   984,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     756,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
     971,     0,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,  2451,  1599,     0,     0,     0,
     756,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,  1246,     0,     0,     0,  1246,     0,
       0,  1246,     0,     0,     0,     0,     0,     0,     0,     0,
     971,     0,     0,     0,     0,   972,     0,     0,  2477,     0,
       0,     0,   973,     0,   137,  2480,     0,     0,  2482,     0,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   846,     0,   847,     0,   848,     0,     0,     0,     0,
     849,     0,     0,     0,  1246,     0,     0,     0,   850,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2525,   851,   852,     0,     0,     0,     0,  1599,  1599,     0,
     853,     0,     0,  1246,  1246,  1246,  1235,     0,     0,     0,
       0,   854,     0,     0,   855,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   856,     0,
       0,     0,     0,     0,  1599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   857,  2589,     0,     0,     0,     0,     0,     0,   858,
       0,   859,  1246,     0,     0,     0,     0,     0,  -694,     0,
    -694,  -694,  -694,  -694,  -694,  -694,  -694,  -694,     0,  -694,
    -694,  -694,     0,  -694,  -694,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,   860,     0,   982,   982,     0,     0,     0,     0,
       0,     0,     0,   861,     0,     0,     0,     0,   862,     0,
       0,  2636,     0,     0,     0,     0,     0,     0,     0,     0,
     982,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2657,  2657,     0,   863,     0,     0,     0,   982,
       0,     0,   864,     0,     0,   865,   866,     0,     0,  1246,
       0,     0,     0,     0,     0,   867,     0,     0,     0,     0,
       0,     0,   868,     0,   869,     0,     0,   870,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2680,     0,     0,
       0,   982,  1246,     0,  1246,     0,     0,     0,     0,     0,
       0,     0,     0,   846,     0,   847,     0,   848,     0,     0,
       0,     0,   849,     0,  1599,     0,     0,     0,     0,   871,
     850,     0,  1599,   872,     0,   873,     0,     0,     0,     0,
       0,  1246,     0,  1246,     0,   874,     0,     0,     0,     0,
       0,  -694,  -694,     0,  -694,  -694,  -694,  -694,     0,     0,
       0,     0,     0,   851,   852,     0,     0,     0,     0,     0,
       0,   875,   853,     0,     0,     0,     0,     0,     0,     0,
     952,     0,     0,   854,   876,     0,   855,     0,   984,     0,
       0,     0,     0,     0,     0,     0,  1246,   953,     0,     0,
     856,     0,  1599,     0,     0,     0,     0,     0,     0,   877,
     878,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     879,     0,     0,   857,     0,     0,     0,     0,     0,     0,
       0,   858,     0,   859,   880,   881,     0,     0,     0,     0,
       0,   882,     0,     0,     0,   883,     0,     0,     0,     0,
       0,     0,     0,   884,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   885,   860,     0,     0,     0,     0,     0,
       0,     0,   886,     0,     0,   861,     0,     0,     0,     0,
     862,   887,     0,     0,     0,     0,   888,   889,     0,  1246,
     890,  1246,   891,     0,     0,     0,     0,     0,   892,   954,
       0,     0,   952,     0,     0,     0,     0,   863,     0,     0,
     749,  -694,     0,     0,   864,     0,     0,   865,   866,   953,
       0,     0,  1246,     0,     0,     0,     0,   867,     0,   894,
       0,     0,     0,     0,   868,   895,   869,     0,     0,   870,
     896,     0,     0,   955,     0,     0,     0,     0,     0,   956,
       0,   957,     0,  1246,   752,     0,   958,   959,   960,     0,
       0,  -694,   961,     0,   753,     0,     0,   897,     0,     0,
       0,     0,     0,     0,     0,     0,  1206,     0,     0,   747,
       0,   871,     0,     0,     0,   872,     0,   873,     0,     0,
     846,     0,   847,     0,   848,     0,     0,   874,     0,   849,
       0,   962,     0,     0,     0,     0,     0,   850,     0,     0,
    1311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     963,   954,     0,   875,     0,     0,     0,     0,     0,     0,
       0,     0,  1246,     0,  1246,     0,   876,     0,     0,     0,
     851,   852,     0,     0,   754,     0,     0,     0,     0,   853,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
     854,   877,   878,   855,  1207,     0,     0,     0,     0,   953,
       0,     0,   879,     0,     0,   964,  1312,   856,   958,   959,
     960,     0,     0,     0,   961,     0,   880,   881,     0,     0,
       0,     0,     0,   882,     0,     0,     0,   883,     0,     0,
     857,     0,     0,     0,     0,   884,     0,     0,   858,     0,
     859,     0,     0,     0,   755,   885,     0,     0,     0,     0,
       0,     0,     0,   962,   886,     0,   965,   966,     0,     0,
       0,     0,     0,   887,     0,     0,     0,     0,   888,   889,
       0,   860,   890,     0,   891,     0,  1386,     0,     0,     0,
     892,     0,   861,     0,     0,     0,   967,   862,   756,     0,
     968,   969,     0,  1632,     0,     0,     0,     0,   970,     0,
       0,   954,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   894,   749,     0,   863,     0,     0,   895,   971,     0,
       0,   864,   896,   972,   865,   866,     0,   964,     0,     0,
     973,     0,   137,     0,   867,     0,     0,     0,   757,     0,
       0,   868,     0,   869,     0,  1208,   870,     0,     0,   897,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1209,     0,     0,   984,   984,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,     0,   871, -1830,
       0,     0,   872,     0,   873,     0,     0,     0,     0,     0,
     984,     0,     0,   962,   874,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   984,
     970,     0,   963,     0,     0,     0,     0,     0,     0,     0,
     875, -1119,     0,     0,     0,     0,     0,     0,     0,     0,
     971,     0,     0,   876,     0,   972,   754,     0,     0, -1119,
       0,     0,   973,   243,   137,     0,     0,     0,     0,     0,
       0,   984,     0,     0,     0,     0,     0,     0,   877,   878,
       0,     0,     0,     0,     0,     0,     0,   964,     0,   879,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   880,   881,     0,     0,     0,     0,     0,
     882,   952,     0,     0,   883,     0,  1021,     0,  1022,     0,
       0,     0,   884,  1023,     0,     0,   755,     0,   953,     0,
       0,  1024,   885,     0,     0,     0,     0,     0,   965,   966,
       0,   886,     0,     0,     0,     0,     0,     0,     0,     0,
     887,     0,     0,     0,     0,   888,   889,     0,     0,   890,
       0,   891,     0,     0,  1025,  1026,     0,   892,     0,     0,
     756,     0,     0,  1027,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,  1028,     0,     0,  1029,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   894,     0,
     971,  1030,     0,     0,   895,   972,     0,     0,     0,   896,
       0,     0,   973,     0,   137,     0,     0,     0,     0,  1311,
     757,     0,     0,     0,  1031,     0,     0,     0,     0,     0,
     954,     0,  1032,     0,  1033,     0,   897,     0,     0,     0,
       0,  1034,     0,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1042,     0,  1043,  1044,  1045,     0,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1056,     0,     0,     0,
       0,  1057,     0,     0,     0,  1455,     0,   958,   959,   960,
       0,     0,     0,   961,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1058,     0,
       0,     0,     0,     0,     0,  1059,     0,     0,  1060,  1061,
       0,     0,     0,     0,     0,     0,     0,     0,  1062,     0,
       0,     0,   962,     0,     0,  1063,     0,  1064,     0,     0,
    1065,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1206,     0,     0,   747,     0,     0,  1508,  1509,  1510,
       0,     0,     0,     0,     0,  1511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1066,     0,     0,     0,  1067,     0,  1068,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1069,     0,
       0,     0,     0,     0,     0,     0,   964,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1070,     0,     0,   952,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1071,     0,     0,
       0,     0,     0,     0,   953,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   965,   966,     0,
       0,     0,  1072,     0,     0,     0,     0,     0, -1830,     0,
       0,     0,     0,  1073,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1074,     0,
       0,     0,     0,     0,  1075,     0,     0,     0,  1076,   970,
       0,     0,     0,     0,  1512,     0,  1077,     0,     0,     0,
   -1119,     0,     0,     0,  1513,     0,  1078,     0,     0,   971,
       0,     0,     0,     0,   972,  1079,     0,     0, -1119,     0,
       0,   973,   243,   137,  1080,     0,     0,     0,     0,  1081,
    1082,     0,     0,  1083,     0,  1084,   954,     0,     0,     0,
       0,  1085,  1514,  1515,     0,     0,     0,   749,     0,     0,
       0,     0,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1831,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,     0,  1088,     0,
    1208,  1516,  1517,  1089,     0,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,     0,     0,  1209,     0,  1206,     0,
    1090,   747,     0,     0,  1508,  1509,  1510,     0,     0,  1518,
       0,     0,  1511,     0,     0,  1519,     0,     0,  1520,     0,
       0,     0,     0,     0,     0,     0,  1521,     0,   962,     0,
       0,     0,     0,  1522,     0,     0,  1206,     0,  1523,   747,
       0,     0,     0,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1524,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   953,     0,     0,     0,     0,  1206,     0,     0,   747,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1300,     0,     0,     0,     0,   953,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1512,     0,   965,   966,     0,     0,     0,     0,     0,
       0,  1513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   952,  1525,     0,  1526,     0,  1527,     0,     0,
    1528,     0,  1529,  1530,  1531,   756,     0,  1532,  1533,   953,
       0,     0,     0,   954,     0,   970,     0,     0,     0,  1514,
    1515,     0,  1357,     0,   749,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,   954,     0,     0,     0,   757,     0,  1208,  1516,  1517,
       0,     0,   749,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
       0,     0,     0,  1209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1208,  1518,  1206,     0,     0,
     747,   956,  1519,   957,     0,  1520,   752,     0,   958,   959,
     960,   954,     0,  1521,   961,   962,   753,     0,     0,     0,
    1522,  1209,   749,     0,  1206,  1523,     0,   747,     0,     0,
       0,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1524,     0,     0,     0,     0,     0,
       0,     0,     0,   962,     0,  1208,     0,     0,   754,     0,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,   963,   952,   961,     0,   753,     0,     0,     0,
       0,  1209,     0,     0,     0,  1362,     0,     0,     0,   964,
     953,     0,     0,     0,     0,     0,   754,     0,     0,     0,
     952,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   962,     0,     0,     0,   953,     0,     0,
    -910,     0,     0,  -910,     0,     0,     0,   964,   755,     0,
       0,     0,   963,     0,     0,     0,  1206,     0,     0,   747,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,     0,     0,     0,
    1525,     0,  1526,     0,  1527,     0,   755,  1528,     0,  1529,
    1530,  1531,   756,     0,  1532,  1533,     0,     0,   965,   966,
       0,     0,   970,     0,     0,     0,     0,   964,     0,     0,
       0,     0,   954,     0,     0,     0,  -910,     0,     0,     0,
       0,     0,   971,   749,     0,     0,     0,   972,     0,     0,
     756,     0,   952,  -910,   973,     0,   137,     0,     0,   954,
     970,     0,   757,     0,     0,     0,   755,     0,     0,   953,
     749,     0,     0,     0,     0,     0,  1208,     0,   965,   966,
     971,     0,   956,     0,   957,   972,     0,   752,     0,   958,
     959,   960,   973,     0,   137,   961,     0,   753,     0,     0,
     757,     0,  1209,  1208,     0,     0,     0,     0,     0,   956,
     756,   957,     0,     0,   752,     0,   958,   959,   960,  1482,
     970,     0,   961,     0,   753,     0,     0,     0,     0,  1209,
       0,     0,     0,     0,   962,     0,     0,     0,     0,     0,
     971,     0,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   973,   963,   137,  -910,     0,     0,     0,     0,
     757,   962,     0,     0,     0,     0,  -910,     0,     0,     0,
       0,   954,     0,     0,     0,     0,     0,   754,     0,     0,
     963,     0,   749,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -910,
       0,     0,     0,     0,   754,  -910,     0,  -910,   964,     0,
    -910,     0,  -910,  -910,  -910,  1208,     0,     0,  -910,     0,
    -910,   956,     0,   957,     0,  -910,   752,     0,   958,   959,
     960,     0,     0,     0,   961,   964,   753,  1206,     0,     0,
     747,  1209,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,  1206,     0,     0,   747,  -910,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   962,   755,     0,  -910,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,   966,     0,     0,
       0,   756,   963,     0,     0,     0,     0,     0,     0,     0,
    -910,   970,     0,     0,  1444,     0,     0,     0,     0,     0,
       0,     0,     0,   952,     0,     0,   754,     0,   756,     0,
       0,   971,     0,     0,     0,     0,   972,     0,   970,   952,
     953,  -910,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,  1206,     0,     0,   747,   953,   964,   971,     0,
       0,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
    -910,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -910,  -910,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -910,     0,     0,     0,   952,     0,
       0,     0,     0,     0,  -910,     0,     0,  1628,     0,     0,
     756,     0,   954,     0,  1206,   953,     0,   747,     0,     0,
     970,     0,     0,   749,  -910,     0,     0,     0,   954,  -910,
    1754,     0,     0,   747,  1486,     0,  -910,     0,  -910,   749,
     971,     0,     0,     0,  -910,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,  1208,     0,     0,     0,
     757,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,  1208,     0,     0,   961,     0,   753,   956,     0,
     957,     0,  1209,   752,     0,   958,   959,   960,     0,     0,
     952,   961,     0,   753,     0,     0,     0,     0,  1209,     0,
       0,     0,     0,     0,     0,     0,   952,   953,     0,     0,
       0,     0,     0,     0,   962,     0,     0,   954,     0,     0,
       0,     0,     0,   953,     0,     0,     0,     0,   749,     0,
     962,     0,     0,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,     0,     0,     0,     0,   754,     0,     0,
       0,  1208,     0,     0,     0,     0,     0,   956,     0,   957,
       0,     0,  1250,   754,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,  1209,   964,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   964,     0,     0,     0,     0,   954,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   962,
     749,     0,     0,     0,     0,   954,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,   749,  1919,   963,   965,
     966,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1208,     0,   965,   966,     0,     0,   956,
       0,   957,   754,     0,   752,     0,   958,   959,   960,  1208,
       0,   756,   961,     0,   753,   956,     0,   957,     0,  1209,
     752,   970,   958,   959,   960,     0,     0,   756,   961,     0,
     753,     0,     0,   964,     0,  1209,     0,   970,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,   962,     0,   973,     0,   137,     0,   971,     0,     0,
       0,   757,   972,     0,     0,     0,     0,   962,     0,   973,
     963,   137,   755,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,   965,   966,   963,     0,     0,     0,
       0,     0,     0,     0,   754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,   756,     0,     0,     0,
       0,     0,     0,     0,     0,   964,   970,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   964,     0,     0,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,     0,     0,     0,     0,   973,     0,
     137,     0,     0,     0,   755,     0,   757,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,   966,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   965,   966,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,   971,  1013,
       0,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,     0,   137,     0,   971,     0,     0,     0,   757,   972,
       0,     0,     0,     0,     0,     0,   973,     0,   137,     0,
    -352,     0,     0,  -352,   757,     0,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,  -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   529,     0,     0,  -352,  -352,  -352,  -352,
    -352,   528,     0,  -352,  -352,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,  -352,     0,  -352,     0,     0,     0,
       0,  -352,  -352,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,  -352,  -352,     0,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,
    -352,     0,     0,  -352,     0,     0,     0,     0,     0,  -352,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,  -352,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,   529,     0,     0,  -352,  -352,
    -352,  -352,  -352,     0,     0,  -352,  -352,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,  -352,     0,  -352,  -352,  -352,     0,     0,
       0,     0,  -352,     0,     0,  -352,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,  -352,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,  -352,     0,     0,     0,  -352,  -352,  -352,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,  -352,  -352,     0,     0,  -352,
       0,     0,   530,     0,     0,     0,     0,  -352,     0,   616,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,   617,     0,     0,   618,   619,   620,
     621,   622,   623,   624,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,     0,   626,   627,   628,   629,   630,   631,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,  -352,  -352,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,  -352,  -352,
       0,     0,     0,     0,     0,     0,   634,   635,   636,   637,
     638,  -352,     0,   639,   640,     0,     0,     0,  -352,   952,
       0,     0,     0,     0,   530,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   953,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,   642,     0,     0,     0,     0,     0, -1806,
       0,     0,     0,     0,     0,     0,     0,  1679,     0,     0,
    1680,     0,     0,  1681,   618,   619,   620,   621,   622,   623,
    1682,  1683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   643,     0,     0,     0,  1684,
       0,  1685,     0,     0,     0,     0,     0,     0,   625,     0,
     626,   627,   628,   629,   630,   631,   632,     0,     0,     0,
       0,     0,     0,   644,     0,     0,     0,     0,   954,     0,
       0,     0,     0,     0,     0,     0,     0,   645,     0,   749,
       0,     0,     0,     0,     0,   646,     0,     0,   647,     0,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
     952,   648,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   955,   649,     0,     0,     0,   953,   956,     0,
     957,   650,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,  1686,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   634,   635,   636,   637,   638,     0,     0,
     639,   640,     0,   651,  1687,   652,   653,   654,     0,     0,
     962,  1688,     0,  1689,     0,     0,     0,     0,     0, -1759,
       0,     0,     0,     0,     0,     0,  1690,     0,     0,   963,
       0,     0,   655,     0,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,  -349,
     642,     0,     0,   754,     0,     0,     0,     0,  1691,   954,
       0,     0,   952,     0,     0,     0, -1806,  1692,     0,     0,
     749,     0,     0,     0,     0,   656,   657,   658,     0,   953,
    1693,     0,     0,     0,   964,     0,     0,     0,     0,   659,
       0,     0,   643,     0,     0,     0,   660,     0,     0,     0,
       0,     0,     0,   955,     0,     0,     0,     0,     0,   956,
       0,   957,     0,     0,   752,     0,   958,   959,   960,     0,
    1694,     0,   961,   755,   753,     0,     0,     0,     0,     0,
       0,     0,     0,  1695,   645,   965,   966,     0,     0,     0,
       0,     0,   646,     0,     0,   647,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1405,     0,     0,   648,     0,
    1696,   962,     0,     0,     0,   967,     0,   756,     0,   968,
     969,     0,     0,     0,     0,     0,     0,   970,     0,     0,
     963,   954,     0,     0,     0,     0,  1697,     0,     0,     0,
       0,     0,   749,  1698,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,   754,     0,     0,     0,     0,   973,
    1699,   137,     0,   952,     0,     0,     0,   757,     0,     0,
     651,     0,   652,   653,   654,   955,     0,     0,     0,     0,
     953,   956,     0,   957,     0,   964,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1700,     0,     0,     0,     0,  -597,     0,     0,     0,
       0,  1701,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,   962,     0,     0,   965,   966,  1702,     0,
       0,     0,   656,   657,   658,     0,     0,     0,     0,     0,
       0,     0,   963,     0,     0,     0,   659,     0,     0,     0,
       0,     0,  1703,   660,     0,     0,   967,   952,   756,     0,
     968,   969,     0,     0,     0,     0,   754,     0,   970,     0,
       0,     0,   954,   952,   953,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,     0,     0,   971,     0,
     953,     0,     0,   972,     0,     0,     0,   964,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
       0,     0,     0,     0,     0,     0,   955,     0,     0,     0,
       0,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,   755,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1943,     0,
       0,     0,     0,     0,   962,     0,   954,     0,   967,     0,
     756,     0,   968,   969,     0,     0,     0,   749,     0,     0,
     970,     0,   954,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,     0,     0,     0,     0,
     971,     0,     0,     0,     0,   972,     0,   754,     0,     0,
     955,     0,   973,     0,   137,     0,   956,     0,   957,     0,
     757,   752,     0,   958,   959,   960,   955,     0,     0,   961,
       0,   753,   956,     0,   957,     0,     0,   752,   964,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   962,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,   962,     0,     0,   963,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   756,     0,   968,     0,     0,     0,   754,     0,     0,
       0,   970,     0,     0,     0,     0,     0,     0,  2647,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,   964,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   965,   966,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,     0,     0,     0,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,   971,     0,     0,     0,   757,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-2339))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   595,   103,   158,   105,   111,   660,
     366,   540,  1101,   111,   649,  1206,  1128,   116,   838,   684,
     714,   776,  1558,   358,   783,  1422,  1568,    56,    57,    58,
    1422,   181,   135,   425,  1422,    64,  1422,   135,  1422,  1422,
    1463,  1574,   598,   435,  1347,  1969,  2003,  1238,   404,  1114,
    1104,  1357,  1512,  1106,   784,  1806,  1095,     9,  1245,   209,
    1336,  1114,     9,  1128,    22,  1444,   783,     9,    48,  1889,
      99,   100,     1,   102,  1738,  1128,   741,  1231,   107,   108,
     114,   184,  1954,  1164,  1503,     0,   841,   116,     6,  1099,
       1,    57,    49,    53,  1914,    17,    55,  1178,    31,     9,
      60,    31,  1356,     1,   133,   697,   364,  1773,    87,    57,
     141,   124,  1299,   123,   123,   750,   751,   152,  1497,     9,
      57,  2075,   244,   788,    30,   277,     9,    63,   125,    17,
    1666,   160,    72,  1436,   170,   176,    32,   212,     1,    39,
     165,   241,    22,  1115,  1233,   175,   232,  1913,    92,  1815,
     232,  2430,   251,   174,   232,   237,  1432,   142,    64,   225,
      66,   328,   191,   798,   256,  1352,   170,    57,    27,  1141,
      30,   176,    86,   242,   203,   234,    49,   203,  2135,   252,
      49,   256,  1221,  1486,   271,  2036,  1565,   159,    49,   225,
    1981,   266,   213,  2299,    21,  2301,   295,   233,   244,   161,
    1866,   161,   218,   256,    64,   256,    66,   187,   262,   968,
     218,   308,   406,   113,    87,    96,   256,   783,    21,   369,
     249,   225,   256,   138,  1277,   406,   196,   142,   257,   233,
     989,   171,    57,   286,  2508,  1288,   453,   829,   956,   957,
      96,     6,    31,   747,   171,   963,  1101,   451,   262,  1628,
     967,   968,   969,    64,  2592,    66,   115,  1923,   218,   219,
     212,   450,   256,     0,   256,   124,   256,  2437,   367,  2607,
     459,   346,   989,   287,   232,  1551,   329,   204,   329,   107,
    1345,   317,   476,  1138,   501,   200,   256,   177,   410,    70,
     306,   317,  1345,   421,  2568,   476,  1349,  1833,  2252,  2253,
     203,   199,   342,    92,   256,   340,   314,    70,  2587,   256,
     228,  2417,   272,   317,   266,   384,   389,  1289,   232,   823,
     955,    70,   282,  2493,    70,   129,  1868,   289,  2148,   994,
    1994,   385,    70,  1639,   363,  1094,   503,   237,   397,  1645,
     443,   416,   445,   446,  2010,   423,   252,   445,   446,   452,
     347,   241,   232,  2119,   452,   110,   341,  1633,   457,   446,
     256,     6,   391,   274,   410,   451,   469,   228,   468,   472,
     473,   469,   475,   402,     6,   478,   479,  1094,   357,  1839,
    1759,   503,   411,   412,     0,   414,   415,  2178,  1848,   955,
     308,   420,   252,  1365,   346,     6,    49,  1156,  1157,  1158,
     357,   967,   968,   969,   287,   402,  1825,   504,   437,  1828,
    1169,  1170,   504,   516,   354,   271,   353,  1176,   516,   376,
     451,   365,   504,   989,   453,   331,   341,   290,   501,  2383,
       6,   497,  1149,   561,  1444,   510,   461,   540,   541,  1156,
    1157,  1158,   540,   541,  1000,  1001,  2318,   212,  1502,   312,
     309,  1116,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
     370,  1737,  1179,   504,   416,   401,   349,     6,   504,   504,
     504,   331,   482,   482,   504,    70,   579,   388,   123,   335,
     452,   579,     6,   504,   357,   465,   515,  1497,   357,   316,
     503,   256,   436,   592,   451,   598,   203,  1562,   446,   504,
     599,   266,   402,   256,   203,   534,  1545,  1225,   460,  1562,
     504,  1817,   504,  1767,   504,  1245,   456,    34,  2182,   498,
     331,   153,   138,   503,  2190,   554,   142,   556,  1094,   462,
     559,   560,   462,   562,  1688,   793,   451,  1576,   497,   505,
     451,   498,   460,  1093,   447,   644,   504,   650,   159,  1602,
    1116,  1101,  1102,   451,   442,  1565,  1122,   504,   510,     9,
     589,  1111,   504,  1754,  2230,   594,  2232,   212,  1118,  1119,
    1757,  2104,   601,  1208,  1655,   504,  2448,  2397,   468,   501,
     212,   346,  1858,  1149,   200,   499,   496,  1137,  1138,   504,
    1156,  1157,  1158,  1159,  2445,  2446,  1188,  2263,  1164,   175,
      50,   212,    33,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,   256,  1178,  1179,  2486,  2487,   576,   398,  1628,  1895,
    2371,   266,  1352,   504,   256,   498,   453,  2293,  2294,   498,
     659,  2050,  1507,   458,   266,   398,   212,   464,   463,   271,
    2064,   504,  1208,   503,   503,   256,   606,   451,   504,   398,
     453,   416,   398,  2610,  2526,   266,   241,   256,  2530,  2531,
     398,   464,   159,   762,  2043,  1231,  2045,   448,   767,   772,
     773,   700,  1547,   212,   703,   503,   504,   274,   828,   330,
     256,   446,   781,   786,  2608,   448,   441,  2559,   212,   256,
     266,   446,   161,   172,   256,   460,   256,  1572,   203,   448,
     504,   346,   448,   256,   357,  2084,  1098,   200,  1100,  1762,
     448,  1470,    27,     9,   346,  2139,   451,   256,    64,  1269,
      66,   216,     9,   376,  2596,   341,  1765,   266,   229,   129,
     354,  1123,   256,  1125,   203,   346,   167,     1,  1130,   504,
    2046,   236,   266,  1473,   188,   510,    57,   262,  1314,  1759,
    1300,   504,  1144,  1470,  1965,   462,   330,   510,  2137,   229,
     270,    57,   212,   462,   281,   282,   283,   262,    38,   406,
     346,   416,   287,  1984,  1985,   153,    46,  1988,   776,  1490,
    1491,  1492,  1493,  2397,   416,    61,  2452,  2453,    26,  2065,
    2250,   388,   287,   290,   244,   245,   293,    61,   451,  1864,
     115,   446,  1437,   398,   406,   416,   256,   346,   125,  1359,
     410,  1864,  1865,    89,    90,   460,   266,    32,  2029,   329,
     289,   357,   346,  2034,    28,    89,    90,   344,   460,  1464,
    2254,   231,   456,   248,   249,   451,   267,   482,   252,   476,
     416,   452,  1559,   841,  1236,   498,  2388,  2150,   341,   460,
     207,   208,   503,   448,   171,  1247,  2470,    56,   169,   504,
    1949,   406,  1418,   458,    63,   510,   257,  2143,   463,   370,
     308,   376,   504,  2605,   476,   122,   476,   416,   510,    56,
    1610,   177,    59,   468,   460,   157,    63,   411,   504,   246,
     247,   291,   416,   504,  1444,   110,   346,  1000,  1001,   510,
     370,  1660,   256,  1778,  1470,   504,   252,   376,    84,  2641,
    1785,  1010,   223,   392,  1249,   271,   212,   271,   362,  1584,
    2462,   460,   126,  2035,  2036,   212,   195,   503,   504,   503,
     504,   476,   256,  1483,   510,     0,   460,   504,   177,  2150,
     204,   211,   504,  1660,   504,   241,  1496,  1497,   458,   466,
     467,   504,     9,   463,   471,   452,   232,   285,   196,   231,
     256,  1836,   498,   212,   262,   504,   416,   321,   232,   256,
     266,   510,   410,   243,   308,   389,   341,   451,  2511,   266,
     504,   446,   216,   217,  1534,   331,   510,   256,   503,   287,
     244,   138,  1095,  1559,  1329,   265,  1099,  2051,   237,  1664,
      57,   240,   236,  1106,  1107,   500,   334,   256,   212,   274,
     460,  1114,   262,  2204,  1117,  1565,  1891,   266,  1584,  1122,
     292,  1124,   346,  1126,  1127,  1128,  1129,  1757,   262,  2082,
     504,   171,   497,  2043,   503,  2045,  2572,   287,   476,    26,
    1331,   256,   394,  1146,   435,   321,     8,   301,   318,  2103,
     346,  2584,   256,   287,   204,  2478,  1606,   321,   356,   346,
     510,   451,   266,   387,   204,    56,   422,  1617,   424,   268,
    1620,    54,    63,   138,  2084,    37,   280,   142,  1628,   751,
    1671,  1792,   232,  1475,   418,  2174,   351,  1237,   353,  1655,
    1381,   268,   416,   411,  1660,  1806,  2493,   346,   455,   451,
     457,  2493,   292,   494,   232,  2493,    89,  2493,   378,  2493,
    2493,  2647,   256,   504,  1989,   414,  1751,  2328,  1221,     1,
     416,  2332,  1688,   106,   256,  2661,   798,  2137,   256,   416,
    2005,  2673,   262,   116,   324,   200,   306,  1240,  1288,   450,
     458,   340,   346,   287,     1,   463,   262,   458,   459,  2024,
     504,   394,   463,   452,    11,   212,   510,   287,    40,    41,
      42,    43,    44,   340,   460,   351,   356,   416,   338,   546,
     454,   287,   468,   460,  1277,   451,   474,   451,  2053,   307,
       6,   309,  2057,     9,   241,  1288,   510,   451,   358,     9,
     187,   451,    12,    75,    76,    15,    16,   396,   220,   256,
    1955,    58,   401,   473,  1149,   503,  1356,   584,   504,   266,
     187,   460,   416,   210,   510,   419,   420,   504,     8,   396,
     504,  2096,   481,   510,   401,     8,   412,   413,   451,  1332,
     252,  2442,  2443,   210,  1179,   612,   199,  1126,  1117,    96,
     499,    98,  1345,   100,   750,   751,  1349,    37,  1583,   379,
    1129,   108,   451,    16,    37,   504,    82,  1146,   106,   187,
      56,   510,   504,  1898,    13,    14,   500,    63,   116,   503,
      33,   423,   337,    99,   750,   751,   341,   268,  2008,    42,
    1383,   212,   210,    32,   405,  1383,   117,   118,   119,   346,
     232,   107,   798,  1649,    53,    54,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   504,   510,   164,  1458,    47,
      35,   127,  2187,    38,   445,  1418,   394,   307,  2193,   309,
      45,    46,   798,     9,    62,   256,   152,   504,  2203,   351,
      89,   462,  2026,  2445,  2446,   266,  2448,   359,    96,    97,
     458,  1444,   449,  2163,  1714,   463,  2011,   106,  2539,   340,
     166,   458,  1902,   405,  1724,  1725,   463,   116,  1728,   416,
     323,   324,  1953,  2373,   102,  2375,    91,   449,   451,  2004,
    2129,   451,   188,   503,   504,   201,   458,   340,  2585,  2586,
    1391,   463,   299,   300,  1395,     2,   212,  1416,   204,   451,
       7,  1402,  1421,  1422,  1497,  1424,    82,   451,  2273,  2064,
     257,  2276,  2277,   460,  2611,   396,   177,   238,  2497,   453,
     401,   468,  2129,    99,  2289,   346,   187,  1567,   161,   245,
     464,   252,   165,  2630,    11,   251,   453,   253,  2303,  2304,
     256,   394,   258,   259,   260,   160,    57,   464,   264,   210,
     266,  1591,  1545,   218,   301,   271,   173,   504,   330,   555,
     473,  1603,   475,   510,   560,   478,   451,   277,   278,  1562,
     451,   343,  1565,  1195,   189,  2672,  1616,  1199,   351,   240,
     353,    58,   268,  1576,  2139,  1171,  1172,   303,  1870,   451,
     448,   301,   302,   448,   504,   416,   211,   351,  2363,   353,
     458,    68,   212,   458,   232,   463,   322,   451,   463,  1602,
     504,   239,    12,   451,   335,    15,    16,   448,   351,    96,
     353,    98,   250,   100,   451,   201,   347,   458,  1157,  1158,
     346,   108,   463,   504,   256,  1628,   212,   340,   156,   460,
     158,  1630,  2407,   390,   256,   468,   256,  1173,  1174,  1175,
     265,   199,   442,  2093,   340,   156,   266,   158,  1651,   504,
     252,   377,   254,  1651,   400,   485,   486,   487,   488,  1652,
    1653,  1654,   321,  2129,   401,  1658,   325,   326,  1661,  1662,
     256,   410,   258,   259,   260,    63,   433,   164,   264,   510,
     266,  2131,  2132,    59,   252,  1614,   254,   256,   232,  2254,
     416,   451,   328,   318,   451,  1694,   485,   486,   487,   488,
     396,   401,   428,   429,   256,   401,   437,   366,   485,   486,
     487,   488,   504,   351,   352,   229,  1715,   303,   620,   621,
     622,   623,   504,   382,   383,  2154,   346,   453,   366,   252,
     368,   254,    26,    65,   460,    67,   451,   451,   464,   226,
    1669,  1670,   107,   451,   470,   312,   967,   504,   969,   256,
     256,  1680,  1755,   378,   272,   451,  1759,   454,  1687,  1762,
     346,    23,  1765,   102,   490,   451,   391,   437,   188,   495,
     257,    35,   122,   454,    38,    17,   502,    86,   504,   504,
     394,    45,    46,   451,   510,   351,  2236,  1716,   272,   401,
      56,   377,   783,  2085,   402,   423,   416,   503,   262,    39,
     451,   237,   402,   504,   331,   394,   504,   506,   419,   310,
     261,   316,  1815,   451,   301,     7,   451,   304,   451,   394,
    1870,   255,  2078,   394,   504,   451,   503,    91,   451,   366,
     416,    85,   451,   451,    85,   124,   451,   394,   389,    22,
     460,   306,   428,   429,   451,  1774,   309,   394,   473,   204,
     504,  1903,  1904,  1905,  1906,  1907,  1908,  1909,  1910,   504,
     498,  1864,  1865,  1866,  1793,   499,   451,   277,   278,   384,
    1799,  1921,   501,   232,   460,   254,   446,   218,   122,   510,
    1930,  1931,   369,   504,   470,   446,   462,   504,   442,    26,
     510,   301,   302,   306,   447,   348,   160,   400,   410,   504,
     445,   165,   462,   390,   490,   256,   442,   504,   451,   495,
     451,   399,   336,   114,   376,   187,   502,   169,   504,   451,
    1923,   504,   462,   462,   510,   189,   256,   462,   415,   462,
     417,   462,   462,   462,   309,   451,   462,   462,   451,   504,
     504,   504,   446,   403,  2394,  1948,   433,   211,    30,   130,
    1948,   453,   131,   196,   446,   132,   386,  1960,   133,   135,
     134,   101,  1965,   136,   462,   137,   441,   446,  2585,  2586,
     140,    49,   404,   497,   445,   442,   967,   968,   969,  1978,
     439,  1984,  1985,   143,   445,  1988,   196,   144,   146,   145,
     499,   271,    31,   147,  2611,    49,   148,   196,   989,   149,
     112,   265,   150,   220,  2454,  1934,   151,  2010,  2458,  2459,
     448,   448,   114,  2630,   410,   448,   451,   504,   109,   448,
     448,   448,   312,  1952,   446,   446,  2029,   223,   197,  2580,
     376,  2034,  2035,  2036,   339,  2085,  2035,  2036,   203,  1968,
    2043,  1970,  2045,  2534,  2094,  1974,   272,   256,  2599,   231,
     298,   165,   501,  1982,   318,  2672,    39,    40,    41,    42,
      43,    44,   294,   128,   175,   484,   365,    82,   446,   168,
     501,    32,   129,  2564,    35,   228,   446,    38,    49,  2082,
     196,  2084,   228,   204,    99,    46,   176,   299,    56,   204,
      73,   451,    75,    76,    77,    78,    79,    80,    81,   504,
     509,  1092,   165,  1094,   272,   252,  1097,   508,   237,   423,
    1101,   299,   276,   446,   378,   446,   362,   380,    30,  2585,
    2586,    17,   203,   203,   295,  1116,   442,   391,   128,   139,
      91,  1122,   365,   446,  2137,    49,   119,   203,   141,     8,
     196,   129,   423,   501,   501,  2611,   446,  2150,  2077,   451,
     203,  2154,  1143,     9,  1145,     7,  2154,   504,  1149,   256,
     503,   294,   297,   203,  2630,  1156,  1157,  1158,  1159,  2461,
     498,   498,    49,  1164,   503,   188,   314,   262,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,   201,  1178,  1179,   330,
     291,   461,   113,   313,    47,   178,   179,   180,   181,   182,
     436,   203,   185,   186,   411,   203,  2672,   294,   102,   473,
     361,    49,   361,   380,   262,   237,  1207,  2509,   492,   296,
      95,   292,    56,     8,    49,   110,   456,  2230,   189,  2232,
     337,   262,   262,   262,   337,   451,   219,   198,    24,    25,
    1231,   256,  1233,   258,   259,   260,   109,   481,   210,   264,
     211,   451,   107,   209,   221,   418,   501,  2260,   367,   119,
    2263,   196,  2260,   337,   313,    49,   425,     7,   306,   321,
      46,    92,    26,   127,   201,   148,   206,    75,   221,    65,
     238,    67,   243,    69,   150,   177,   410,  1869,   303,   469,
     519,  2294,   286,   425,   277,   773,  1422,  1009,   740,   497,
    2583,  2645,   263,  1862,   265,   788,  2152,  2624,  2657,  2596,
    2175,  2314,  2175,  1018,  2048,  1204,  2314,   103,   104,   105,
    1727,   841,   779,  1314,  1726,  2328,  1809,   288,  2357,  2332,
    1761,  1456,  2046,  1221,  1458,  1483,   319,  2228,  1505,  1502,
    1828,  2050,  1273,  2246,  1548,  1336,  1555,   330,  1856,  2073,
    1309,  1314,  1566,  2085,  2092,  1882,  1931,   318,  1596,  2106,
     343,  1911,   377,  2292,  1343,  2132,  1129,   153,  1345,   155,
    2373,  1362,  2375,  1359,  1930,  2297,   162,  2641,  1930,   165,
    1643,  2397,  2302,  2307,   345,  2125,  2125,  1332,  2391,  1534,
    2125,  1452,  2125,   299,   691,   152,  2688,  1898,   270,   242,
     972,   745,  1187,  2519,   509,   417,  2385,  2336,  2563,   215,
     371,  2340,   449,   428,   429,  1918,   558,   378,  2062,  1861,
     705,  1558,   783,  2587,   407,   408,   409,    -1,     6,    -1,
     391,     9,    -1,    -1,   395,    -1,    -1,    -1,    -1,  2442,
    2443,  1432,  2445,  2446,    -1,  2448,  2445,  2446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,  2396,   254,    -1,
      -1,    49,    -1,    -1,    -1,   490,    -1,    -1,    -1,  1470,
     495,    -1,    -1,   444,    -1,   271,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,   477,   478,   479,    -1,    -1,  2428,
    2429,    -1,    -1,    -1,    82,  2508,    -1,    -1,    -1,    87,
      -1,    -1,   473,    -1,    -1,  2444,    -1,    -1,    -1,    -1,
      -1,    99,   483,    -1,    -1,    -1,    -1,    -1,   489,    -1,
      -1,  2460,    -1,    -1,    -1,    -1,    -1,  2536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2485,    -1,    -1,    -1,
    1551,  2490,  2491,    -1,    -1,  2568,    -1,    -1,  1559,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2510,    -1,    -1,  1575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2591,  1584,   955,    -1,  2595,    -1,    -1,    -1,
      -1,    -1,  2605,    -1,  1595,    -1,   967,   968,   969,  2538,
      -1,    -1,  2541,  2542,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   989,    -1,
       4,    -1,  1623,    -1,   212,    -1,    -1,    -1,  2641,    -1,
      -1,    -1,  1633,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2582,    -1,    29,    -1,   443,    -1,    -1,
      -1,    -1,  2665,    -1,  1655,    -1,    -1,   245,    -1,  1660,
      -1,    -1,    -1,   251,    -1,   253,    -1,  2676,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    63,
      -1,    -1,    -1,   271,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   493,    -1,  1700,
      -1,    -1,  1703,    -1,    -1,    -1,    -1,    -1,   504,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
     308,    -1,    -1,  1094,    -1,    -1,    -1,    -1,  1099,    -1,
      -1,    -1,    -1,    -1,   322,  1106,  1737,    -1,    -1,    -1,
      -1,    -1,    -1,  1114,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1753,    -1,    -1,    -1,    -1,  1128,   346,    -1,
      -1,    -1,    -1,    64,    65,    66,    67,    -1,    -1,   357,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,  1149,     5,
      -1,    -1,    -1,    -1,    10,  1156,  1157,  1158,  1159,   377,
      -1,    -1,    18,  1164,    -1,    -1,    -1,    -1,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,    -1,  1178,  1179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   410,    -1,    -1,    51,    52,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    60,    -1,   220,  1208,    -1,    -1,
     428,   429,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,  1858,  1859,     9,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,   252,  1240,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,   470,    -1,    -1,   111,  1887,    -1,   476,    -1,
      -1,    -1,    -1,   119,  1895,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,  1277,   495,   209,    -1,
     498,    -1,    -1,    -1,   502,    -1,   504,  1288,    -1,    -1,
      -1,  1922,   510,    -1,    -1,    -1,   152,    -1,  1929,  1930,
      -1,   315,    82,    -1,   235,    -1,   320,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,  1949,    99,
      -1,   252,    -1,   254,    -1,    -1,    -1,    -1,  1959,    -1,
      -1,    -1,   112,    -1,    -1,  1336,    -1,   351,    -1,   195,
      -1,    -1,    -1,    -1,  1345,   359,   202,    -1,  1349,   205,
     206,    -1,    -1,    -1,   285,    -1,    -1,    -1,   372,   215,
      -1,    -1,    82,    -1,    -1,    -1,   222,    -1,   224,    -1,
      -1,   227,    -1,    -1,   305,    -1,    -1,    -1,    -1,    99,
    2011,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
     404,    -1,    -1,    -1,    -1,    -1,   327,    -1,   412,    -1,
      -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,   423,
      -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,   275,
      -1,   201,    -1,    -1,  2055,    -1,    -1,    -1,    -1,   285,
      -1,  1432,   212,  2064,  2065,    -1,    -1,   451,    -1,    -1,
     454,    -1,  2073,  1444,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,    -1,    -1,
      -1,  2092,    -1,    -1,    -1,   245,    -1,    -1,   324,  1470,
      -1,   251,    -1,   253,   405,    -1,   256,    -1,   258,   259,
     260,   201,    -1,   414,   264,    -1,   266,    -1,    -1,    -1,
    2121,   271,   212,   349,   350,    -1,  1497,    -1,  2129,    -1,
     431,    -1,    -1,    -1,   360,    -1,    -1,    -1,  2139,    -1,
      -1,    -1,  2143,    -1,    -1,    -1,    -1,    -1,   374,   375,
     451,    -1,    -1,   303,    -1,   381,    -1,    -1,    -1,   385,
      -1,    -1,    -1,    -1,  2165,    -1,   256,   393,   258,   259,
     260,   472,   322,  2174,   264,    -1,   266,   403,    -1,    -1,
    1551,    -1,    -1,    -1,    -1,    -1,   412,    -1,  1559,    -1,
     491,  1562,    -1,    -1,  1565,   421,   346,   498,   499,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,    -1,  2209,    -1,
      -1,    -1,   438,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   451,    -1,   377,    -1,    -1,
      -1,  1602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,   475,
      -1,    -1,    -1,  2254,   480,    -1,   346,  1628,    -1,    -1,
      -1,    -1,  1633,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,   507,    -1,    -1,  1655,    -1,    -1,   377,    -1,  1660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,
     510,    -1,    -1,    -1,    -1,  2366,  1737,    -1,    -1,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,  1755,    -1,    -1,    -1,  1759,    -1,
      -1,  1762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,  2409,    -1,
      -1,    -1,   502,    -1,   504,  2416,    -1,    -1,  2419,    -1,
     510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,  1815,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2467,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2481,    51,    52,    -1,    -1,    -1,    -1,  1858,  1859,    -1,
      60,    -1,    -1,  1864,  1865,  1866,  2497,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,  1895,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,  2543,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,  1923,    -1,    -1,    -1,    -1,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,  2585,  2586,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,  2602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2623,  2624,    -1,   195,    -1,    -1,    -1,  2630,
      -1,    -1,   202,    -1,    -1,   205,   206,    -1,    -1,  2010,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2668,    -1,    -1,
      -1,  2672,  2043,    -1,  2045,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,    -1,     5,    -1,    -1,
      -1,    -1,    10,    -1,  2065,    -1,    -1,    -1,    -1,   269,
      18,    -1,  2073,   273,    -1,   275,    -1,    -1,    -1,    -1,
      -1,  2082,    -1,  2084,    -1,   285,    -1,    -1,    -1,    -1,
      -1,   291,   292,    -1,   294,   295,   296,   297,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    71,   324,    -1,    74,    -1,  2129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2137,    99,    -1,    -1,
      88,    -1,  2143,    -1,    -1,    -1,    -1,    -1,    -1,   349,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,   374,   375,    -1,    -1,    -1,    -1,
      -1,   381,    -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   403,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,    -1,   163,    -1,    -1,    -1,    -1,
     168,   421,    -1,    -1,    -1,    -1,   426,   427,    -1,  2230,
     430,  2232,   432,    -1,    -1,    -1,    -1,    -1,   438,   201,
      -1,    -1,    82,    -1,    -1,    -1,    -1,   195,    -1,    -1,
     212,   451,    -1,    -1,   202,    -1,    -1,   205,   206,    99,
      -1,    -1,  2263,    -1,    -1,    -1,    -1,   215,    -1,   469,
      -1,    -1,    -1,    -1,   222,   475,   224,    -1,    -1,   227,
     480,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,  2294,   256,    -1,   258,   259,   260,    -1,
      -1,   501,   264,    -1,   266,    -1,    -1,   507,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,
      -1,   269,    -1,    -1,    -1,   273,    -1,   275,    -1,    -1,
       1,    -1,     3,    -1,     5,    -1,    -1,   285,    -1,    10,
      -1,   303,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   201,    -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2373,    -1,  2375,    -1,   324,    -1,    -1,    -1,
      51,    52,    -1,    -1,   346,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,   349,   350,    74,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,   360,    -1,    -1,   377,   256,    88,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   374,   375,    -1,    -1,
      -1,    -1,    -1,   381,    -1,    -1,    -1,   385,    -1,    -1,
     111,    -1,    -1,    -1,    -1,   393,    -1,    -1,   119,    -1,
     121,    -1,    -1,    -1,   416,   403,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   412,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,   426,   427,
      -1,   152,   430,    -1,   432,    -1,   448,    -1,    -1,    -1,
     438,    -1,   163,    -1,    -1,    -1,   458,   168,   460,    -1,
     462,   463,    -1,   451,    -1,    -1,    -1,    -1,   470,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   469,   212,    -1,   195,    -1,    -1,   475,   490,    -1,
      -1,   202,   480,   495,   205,   206,    -1,   377,    -1,    -1,
     502,    -1,   504,    -1,   215,    -1,    -1,    -1,   510,    -1,
      -1,   222,    -1,   224,    -1,   245,   227,    -1,    -1,   507,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,    -1,  2585,  2586,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   439,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,
    2611,    -1,    -1,   303,   285,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2630,
     470,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,   324,    -1,   495,   346,    -1,    -1,   499,
      -1,    -1,   502,   503,   504,    -1,    -1,    -1,    -1,    -1,
      -1,  2672,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    -1,
     381,    82,    -1,    -1,   385,    -1,     3,    -1,     5,    -1,
      -1,    -1,   393,    10,    -1,    -1,   416,    -1,    99,    -1,
      -1,    18,   403,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,
      -1,   432,    -1,    -1,    51,    52,    -1,   438,    -1,    -1,
     460,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,
     490,    88,    -1,    -1,   475,   495,    -1,    -1,    -1,   480,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,   190,
     510,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     201,    -1,   119,    -1,   121,    -1,   507,    -1,    -1,    -1,
      -1,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,   205,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,   303,    -1,    -1,   222,    -1,   224,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,   273,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,   439,    -1,
      -1,    -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,
      -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,   385,   470,
      -1,    -1,    -1,    -1,   159,    -1,   393,    -1,    -1,    -1,
     481,    -1,    -1,    -1,   169,    -1,   403,    -1,    -1,   490,
      -1,    -1,    -1,    -1,   495,   412,    -1,    -1,   499,    -1,
      -1,   502,   503,   504,   421,    -1,    -1,    -1,    -1,   426,
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
      -1,    99,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,   448,    -1,   450,    -1,   452,    -1,    -1,
     455,    -1,   457,   458,   459,   460,    -1,   462,   463,    99,
      -1,    -1,    -1,   201,    -1,   470,    -1,    -1,    -1,   207,
     208,    -1,   112,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,   201,    -1,    -1,    -1,   510,    -1,   245,   246,   247,
      -1,    -1,   212,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   284,     6,    -1,    -1,
       9,   251,   290,   253,    -1,   293,   256,    -1,   258,   259,
     260,   201,    -1,   301,   264,   303,   266,    -1,    -1,    -1,
     308,   271,   212,    -1,     6,   313,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,   245,    -1,    -1,   346,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,   322,    82,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    94,    -1,    -1,    -1,   377,
      99,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,    -1,    99,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    -1,   377,   416,    -1,
      -1,    -1,   322,    -1,    -1,    -1,     6,    -1,    -1,     9,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,
     448,    -1,   450,    -1,   452,    -1,   416,   455,    -1,   457,
     458,   459,   460,    -1,   462,   463,    -1,    -1,   428,   429,
      -1,    -1,   470,    -1,    -1,    -1,    -1,   377,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,   490,   212,    -1,    -1,    -1,   495,    -1,    -1,
     460,    -1,    82,    99,   502,    -1,   504,    -1,    -1,   201,
     470,    -1,   510,    -1,    -1,    -1,   416,    -1,    -1,    99,
     212,    -1,    -1,    -1,    -1,    -1,   245,    -1,   428,   429,
     490,    -1,   251,    -1,   253,   495,    -1,   256,    -1,   258,
     259,   260,   502,    -1,   504,   264,    -1,   266,    -1,    -1,
     510,    -1,   271,   245,    -1,    -1,    -1,    -1,    -1,   251,
     460,   253,    -1,    -1,   256,    -1,   258,   259,   260,   165,
     470,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,   322,   504,   201,    -1,    -1,    -1,    -1,
     510,   303,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
     322,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,   346,   251,    -1,   253,   377,    -1,
     256,    -1,   258,   259,   260,   245,    -1,    -1,   264,    -1,
     266,   251,    -1,   253,    -1,   271,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,   377,   266,     6,    -1,    -1,
       9,   271,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,     9,   303,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   416,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,   460,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     346,   470,    -1,    -1,   446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,   346,    -1,   460,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,   470,    82,
      99,   377,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,     6,    -1,    -1,     9,    99,   377,   490,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,   196,    -1,    -1,
     460,    -1,   201,    -1,     6,    99,    -1,     9,    -1,    -1,
     470,    -1,    -1,   212,   490,    -1,    -1,    -1,   201,   495,
       6,    -1,    -1,     9,   484,    -1,   502,    -1,   504,   212,
     490,    -1,    -1,    -1,   510,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,   245,    -1,    -1,    -1,
     510,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,   245,    -1,    -1,   264,    -1,   266,   251,    -1,
     253,    -1,   271,   256,    -1,   258,   259,   260,    -1,    -1,
      82,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   212,    -1,
     303,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,   346,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,   377,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
     212,    -1,    -1,    -1,    -1,   201,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   410,   322,   428,
     429,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,   428,   429,    -1,    -1,   251,
      -1,   253,   346,    -1,   256,    -1,   258,   259,   260,   245,
      -1,   460,   264,    -1,   266,   251,    -1,   253,    -1,   271,
     256,   470,   258,   259,   260,    -1,    -1,   460,   264,    -1,
     266,    -1,    -1,   377,    -1,   271,    -1,   470,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,   303,    -1,   502,    -1,   504,    -1,   490,    -1,    -1,
      -1,   510,   495,    -1,    -1,    -1,    -1,   303,    -1,   502,
     322,   504,   416,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,   416,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,   490,     1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,   490,    -1,    -1,    -1,   510,   495,
      -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,
      32,    -1,    -1,    35,   510,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,    -1,    -1,   178,   179,   180,   181,
     182,     1,    -1,   185,   186,    -1,    -1,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,    -1,
      -1,    21,   204,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    36,   219,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
     232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,   241,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   343,    -1,   345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,   219,
      -1,    -1,    -1,   405,    -1,   407,   408,   409,    -1,    -1,
      -1,    -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,   456,    -1,    -1,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,    -1,
      -1,   473,    -1,    -1,    -1,   477,   478,   479,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,   491,
      -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,   319,
      -1,    -1,   504,    -1,    -1,    -1,    -1,   327,    -1,    21,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   343,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   405,    -1,   407,   408,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   181,
     182,   491,    -1,   185,   186,    -1,    -1,    -1,   498,    82,
      -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    64,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,   212,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      82,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   355,    -1,    -1,    -1,    99,   251,    -1,
     253,   363,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    -1,   405,   189,   407,   408,   409,    -1,    -1,
     303,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,   322,
      -1,    -1,   434,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,   451,
     235,    -1,    -1,   346,    -1,    -1,    -1,    -1,   243,   201,
      -1,    -1,    82,    -1,    -1,    -1,   468,   252,    -1,    -1,
     212,    -1,    -1,    -1,    -1,   477,   478,   479,    -1,    99,
     265,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,   491,
      -1,    -1,   277,    -1,    -1,    -1,   498,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
     305,    -1,   264,   416,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   319,   428,   429,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,   343,    -1,
     345,   303,    -1,    -1,    -1,   458,    -1,   460,    -1,   462,
     463,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
     322,   201,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,
      -1,    -1,   212,   378,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,   346,    -1,    -1,    -1,    -1,   502,
     395,   504,    -1,    82,    -1,    -1,    -1,   510,    -1,    -1,
     405,    -1,   407,   408,   409,   245,    -1,    -1,    -1,    -1,
      99,   251,    -1,   253,    -1,   377,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   446,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,   428,   429,   473,    -1,
      -1,    -1,   477,   478,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,   497,   498,    -1,    -1,   458,    82,   460,    -1,
     462,   463,    -1,    -1,    -1,    -1,   346,    -1,   470,    -1,
      -1,    -1,   201,    82,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   490,    -1,
      99,    -1,    -1,   495,    -1,    -1,    -1,   377,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,   416,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,
      -1,    -1,    -1,    -1,   303,    -1,   201,    -1,   458,    -1,
     460,    -1,   462,   463,    -1,    -1,    -1,   212,    -1,    -1,
     470,    -1,   201,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,   346,    -1,    -1,
     245,    -1,   502,    -1,   504,    -1,   251,    -1,   253,    -1,
     510,   256,    -1,   258,   259,   260,   245,    -1,    -1,   264,
      -1,   266,   251,    -1,   253,    -1,    -1,   256,   377,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   322,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,   462,    -1,    -1,    -1,   346,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,   377,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,   490,    -1,    -1,    -1,   510,   495,    -1,    -1,    -1,
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
     882,   887,   901,   905,   908,   922,   926,   929,   932,   203,
     376,   863,   924,   937,   941,   951,   954,   971,   973,   976,
     399,   980,   986,   998,  1007,  1011,  1015,  1021,  1029,  1044,
    1054,   256,   346,   387,   416,   510,  1066,  1068,  1075,   336,
    1079,  1081,   810,  1084,  1087,  1091,  1116,   114,   714,   462,
    1225,  1207,  1218,  1220,  1302,  1302,   462,   462,   462,   462,
    1302,  1163,  1159,  1163,   462,  1225,    70,   398,   448,  1158,
     449,   458,   463,   450,   459,   169,   462,  1224,   462,   462,
    1159,   501,   729,  1294,  1217,  1183,  1183,   187,   662,  1213,
     740,   451,   786,   451,    49,   802,   803,   804,  1250,   802,
     504,   451,   308,   826,   827,  1206,     6,    94,   245,   271,
     841,  1164,  1188,  1189,  1206,  1217,  1220,   846,  1159,  1206,
     256,   850,   851,  1175,  1176,  1177,  1210,   271,   422,   424,
     855,   856,   256,   870,  1197,  1206,   873,  1170,     6,   877,
    1165,  1166,  1187,  1208,  1209,  1210,  1218,   454,   883,  1170,
     256,   888,   889,   891,  1188,  1189,  1197,  1206,   902,  1189,
     256,   906,   453,   464,   909,   910,   911,  1147,  1148,  1149,
     199,   323,   324,   340,   394,   923,   927,  1186,  1187,   930,
    1210,   446,   933,  1291,  1189,  1146,  1147,   942,  1186,   952,
    1171,   955,   956,  1206,  1217,  1220,  1045,  1204,  1205,  1210,
      94,   974,  1189,   977,  1189,   170,   225,   233,   317,   981,
     982,   190,   256,   987,   991,   992,   993,  1175,  1198,  1206,
    1210,  1220,  1295,   999,  1170,  1008,  1167,  1210,  1012,  1170,
    1016,  1167,     9,  1022,  1168,  1210,   153,   271,  1030,  1033,
    1034,  1037,  1038,  1039,  1040,  1041,  1042,  1172,  1173,  1186,
    1203,  1205,  1210,  1045,  1055,  1170,  1063,   112,  1069,  1070,
    1071,  1189,    94,  1076,  1188,  1082,  1171,   451,   504,   811,
     812,   815,   816,   821,  1085,  1206,  1088,  1170,  1092,  1206,
    1117,  1167,   309,  1275,   715,   716,   448,  1157,  1159,   504,
     504,  1159,  1228,  1228,  1228,  1191,  1206,  1218,  1220,  1227,
     504,   448,  1191,  1226,  1159,   448,  1159,  1160,  1160,  1161,
    1161,  1161,  1159,  1191,  1157,   403,   453,    30,  1248,  1252,
       1,   741,   787,   803,   410,   476,   805,   357,   498,   796,
     130,   838,    30,   829,   830,  1248,   196,  1274,  1206,  1207,
    1218,  1220,   131,   843,   446,   842,  1189,    57,   223,  1232,
     851,   446,  1302,   132,   867,   256,  1198,  1197,  1170,   356,
     474,   874,  1295,  1308,  1274,   133,   878,   159,   452,  1166,
    1299,   386,  1238,  1211,  1212,   884,  1170,   134,   885,  1280,
     135,   899,   165,   890,  1126,  1127,   484,   892,   503,   830,
     485,   486,   487,   488,   136,   903,    49,   228,   497,   857,
     137,   920,    17,   501,   912,   913,   914,   916,    12,    13,
      14,    20,   159,   169,   207,   208,   246,   247,   284,   290,
     293,   301,   308,   313,   332,   448,   450,   452,   455,   457,
     458,   459,   462,   463,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1189,   101,   924,  1187,  1174,   441,  1289,   943,  1295,
    1171,    92,   365,   436,   957,   958,   960,   961,  1047,   462,
    1211,  1189,   446,   140,   978,    49,   982,   404,   983,   992,
     141,   451,   988,   990,   481,   499,   442,   445,   439,   143,
    1004,   285,   334,  1235,   196,  1118,   144,  1013,  1280,   145,
    1018,  1118,  1168,   146,  1027,   499,  1023,  1195,  1206,  1218,
    1040,  1042,  1186,   446,  1173,   123,   446,   482,  1032,    31,
    1211,   147,  1061,   177,   237,   240,  1057,   863,  1064,  1295,
    1250,   148,  1073,   228,  1071,  1206,   149,  1077,   196,  1171,
     394,   451,   451,   196,   351,   353,  1089,   150,  1101,   112,
    1093,   151,  1122,  1118,  1179,   220,   718,    27,   115,   717,
     448,  1158,   448,   448,   448,  1158,   448,  1158,   448,   448,
     449,   448,   448,   446,  1264,  1183,   114,   660,   451,    61,
      89,    90,   321,   451,   742,   743,   746,  1264,  1320,    32,
      35,    38,    45,    46,    64,    66,   160,   189,   196,   198,
     211,   243,   252,   265,   305,   318,   345,   371,   378,   395,
     446,   456,   473,   497,   704,   705,   709,   721,   723,   725,
     788,   793,   794,  1264,  1297,  1264,   410,   312,   806,   109,
     808,  1195,   197,   833,   252,   331,   831,   832,  1297,    24,
      25,    65,    67,    69,   103,   104,   105,   153,   155,   162,
     165,   252,   254,   443,   493,   504,   828,  1173,  1298,   152,
     340,  1193,  1207,   446,     6,  1165,  1189,  1210,  1218,   203,
     223,  1233,   376,   847,   339,   852,  1177,   857,   874,   262,
     287,  1257,  1207,  1159,   272,  1239,  1212,  1170,   231,  1142,
    1143,   818,   819,   891,  1189,   294,  1128,    96,   335,   504,
    1173,   298,   896,    35,    38,    45,    46,    91,   160,   189,
     211,   265,   318,   378,   391,   473,   897,   898,   484,   893,
    1126,  1126,  1126,  1126,  1189,  1165,  1189,   858,   911,    21,
     453,   464,   917,   918,  1148,   501,   914,   915,   501,   818,
    1291,   232,  1151,   114,   934,  1175,   128,   818,   938,     9,
      12,    15,    16,   277,   278,   301,   302,   944,   948,   175,
    1195,     9,    57,   177,   241,   468,   964,   965,   966,   959,
     960,  1049,  1275,  1311,   446,  1186,  1165,  1189,   983,  1295,
    1169,   818,   168,   994,  1146,   995,   996,  1206,  1175,     8,
      37,  1120,  1280,  1202,  1206,  1217,  1220,   228,  1000,  1017,
    1295,   129,  1024,  1206,  1024,   446,   446,  1031,   152,   453,
     464,  1189,    49,    38,    46,   211,   243,   265,   318,   378,
     473,  1035,  1036,  1264,  1056,  1295,  1189,   161,   289,   410,
    1189,  1206,   196,  1165,  1189,   817,  1213,  1195,  1250,   228,
    1096,  1119,  1120,  1250,  1266,  1179,  1224,  1224,  1224,  1191,
     241,   468,  1224,   448,  1159,  1224,  1224,  1217,  1275,  1264,
    1264,  1245,   248,   249,  1269,   755,   204,   176,   744,  1256,
    1264,   252,   389,   156,   158,  1264,  1198,   299,  1272,  1213,
      56,  1206,  1206,   204,  1272,    32,   110,  1213,  1264,   504,
     451,   797,   272,   834,  1272,  1272,   832,   831,  1272,   165,
    1123,  1124,   509,   508,  1195,  1123,   237,   423,   299,   276,
     256,  1194,  1207,  1206,  1274,   411,  1129,  1130,  1211,  1212,
    1165,   446,  1234,   847,  1187,   446,  1175,   862,   863,   380,
     362,  1129,  1264,   818,   295,  1144,   820,   818,  1126,  1264,
     252,   389,   156,   158,  1264,   123,   482,   898,  1126,    96,
      97,   894,   834,   203,  1129,   203,   859,   860,   861,  1250,
      17,   442,   919,   316,   917,  1275,   818,   128,   139,   939,
    1291,   365,   945,  1291,   446,    49,   965,   967,  1195,     9,
      57,   241,   468,   962,   963,  1195,  1050,  1296,   717,   218,
     314,  1260,  1186,  1129,   203,  1169,   637,   379,   984,  1295,
     141,   989,     8,   196,  1000,  1206,   129,  1135,  1137,  1142,
     262,   287,   818,   501,   501,  1025,  1026,  1195,  1194,  1189,
    1031,  1031,  1031,  1031,  1031,  1031,  1031,  1031,  1036,   290,
     293,  1058,  1059,  1060,  1152,  1236,  1142,   244,   410,  1310,
     423,  1287,  1287,  1072,  1295,  1206,  1129,   203,   451,   446,
       9,  1094,  1095,  1230,  1097,  1206,  1072,  1097,  1017,     7,
    1243,   504,   719,   720,  1264,   448,  1179,  1197,  1264,  1245,
     256,   747,  1215,   686,   756,   745,  1206,   510,  1199,  1203,
    1213,  1199,  1264,  1290,  1264,  1264,    32,  1213,   809,   810,
    1264,   503,   835,  1199,  1199,  1199,   818,   294,  1125,  1123,
    1238,  1207,   818,   297,  1131,  1212,  1129,  1196,  1206,  1217,
     165,   461,   865,  1301,     6,   228,   308,   460,   864,  1263,
      34,   281,   282,   283,   344,   466,   467,   471,  1240,   818,
     821,  1199,  1199,  1145,  1201,  1203,  1213,  1145,   503,   895,
    1165,  1166,  1165,  1166,   860,   308,   805,    87,   357,   498,
     918,  1147,   818,  1206,   818,   498,   946,   947,   948,   949,
    1289,   498,  1196,  1195,    49,   968,   963,   188,   968,  1046,
    1264,  1266,   314,  1165,   984,   262,   287,   996,  1189,   217,
    1001,  1295,   818,   291,  1138,   262,  1147,  1146,  1025,  1152,
    1206,  1153,  1154,  1155,  1156,  1159,  1065,  1189,  1065,   461,
    1132,  1133,   330,  1238,  1165,   813,  1196,   313,  1195,   113,
    1098,   436,  1100,   157,   292,  1121,  1139,  1140,  1141,  1142,
     321,  1173,  1199,   720,  1178,   748,   252,   254,  1304,   504,
     687,  1206,   270,   329,   458,   463,   789,   790,   791,  1197,
     789,   790,   792,   810,    47,    32,    35,    38,    46,    91,
     189,   198,   211,   243,   263,   265,   288,   318,   345,   371,
     378,   391,   395,   444,   473,   483,   489,   836,   837,  1123,
     818,  1129,   818,   294,   866,   818,  1274,  1206,   252,   254,
    1309,   897,  1129,   361,  1129,   361,  1189,   947,   102,  1254,
    1291,   968,   968,  1196,     8,    37,   969,   225,   497,  1051,
    1179,  1048,  1129,   380,    49,   262,   237,  1002,   216,   236,
     262,   287,   500,   818,   818,   818,   818,   296,  1134,  1264,
    1129,  1129,   492,   814,  1102,  1095,  1259,    95,  1099,  1259,
    1132,   818,   818,  1141,   252,   254,  1268,   177,   187,   210,
     240,   749,   750,   751,   752,   753,   754,  1215,   757,  1199,
    1199,   129,  1264,  1264,    56,   123,   482,     8,  1244,   837,
     818,  1206,  1166,  1166,    49,   110,   968,   456,  1262,  1262,
     337,  1169,   203,   317,  1052,  1210,  1189,  1264,  1003,  1136,
    1137,  1138,  1142,   262,   262,   262,   818,  1206,  1103,   451,
    1206,  1259,  1206,   106,   116,  1313,  1264,  1264,    54,    89,
    1313,  1314,  1298,   758,   109,  1199,  1199,  1264,  1145,  1145,
    1200,  1203,  1215,  1129,  1129,  1189,  1189,  1189,  1264,  1169,
     337,   481,  1206,  1138,   127,   166,   204,  1104,  1105,  1106,
    1108,  1112,  1113,  1114,  1257,  1206,  1264,  1215,  1215,   210,
    1264,  1264,   209,   252,   254,   285,   305,   333,   414,   431,
     451,   472,   491,   499,   704,   709,   710,   721,   723,   725,
     759,   760,   764,   765,   768,   769,   770,   771,   772,   773,
     778,   779,   780,  1297,  1298,   451,  1197,   991,  1264,  1146,
      37,  1244,   107,  1215,  1215,  1215,   221,  1261,   299,   300,
    1273,  1245,   209,  1213,   501,  1264,  1274,  1264,  1264,  1206,
     286,   329,   774,   775,  1215,   329,   776,   777,  1215,  1273,
    1245,   991,   367,   418,  1286,  1275,  1265,  1264,   713,  1146,
    1192,  1190,  1192,    53,    89,   321,   325,   326,   366,   382,
     383,   761,  1313,  1314,  1315,  1316,  1317,  1318,  1319,   119,
     196,  1213,   775,  1213,   777,  1265,  1206,   161,   165,  1300,
       9,  1109,  1110,  1176,   775,  1290,  1238,   373,   766,  1192,
     187,   187,   210,   187,   210,   176,   762,  1206,   762,  1192,
     337,  1278,   306,   338,   358,  1111,  1110,   714,  1275,   313,
     763,   763,    49,  1275,   306,  1210,   425,   711,   176,   767,
    1206,   321,  1192,   170,   225,   233,   317,  1107,  1169,  1213
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
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  }
    break;

  case 1007:

/* Line 1806 of yacc.c  */
#line 7110 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1009:

/* Line 1806 of yacc.c  */
#line 7119 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1010:

/* Line 1806 of yacc.c  */
#line 7123 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1011:

/* Line 1806 of yacc.c  */
#line 7127 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1012:

/* Line 1806 of yacc.c  */
#line 7134 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1013:

/* Line 1806 of yacc.c  */
#line 7138 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7148 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1016:

/* Line 1806 of yacc.c  */
#line 7157 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7163 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1018:

/* Line 1806 of yacc.c  */
#line 7164 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1019:

/* Line 1806 of yacc.c  */
#line 7168 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7169 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7170 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7175 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7179 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7186 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1025:

/* Line 1806 of yacc.c  */
#line 7191 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7198 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7204 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7205 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7206 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7207 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7208 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1032:

/* Line 1806 of yacc.c  */
#line 7209 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7210 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7215 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1035:

/* Line 1806 of yacc.c  */
#line 7219 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7228 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7237 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1039:

/* Line 1806 of yacc.c  */
#line 7243 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1040:

/* Line 1806 of yacc.c  */
#line 7254 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7267 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1044:

/* Line 1806 of yacc.c  */
#line 7271 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1045:

/* Line 1806 of yacc.c  */
#line 7275 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1050:

/* Line 1806 of yacc.c  */
#line 7291 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1051:

/* Line 1806 of yacc.c  */
#line 7295 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1052:

/* Line 1806 of yacc.c  */
#line 7305 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1053:

/* Line 1806 of yacc.c  */
#line 7315 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1054:

/* Line 1806 of yacc.c  */
#line 7323 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7324 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1056:

/* Line 1806 of yacc.c  */
#line 7328 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1057:

/* Line 1806 of yacc.c  */
#line 7329 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1058:

/* Line 1806 of yacc.c  */
#line 7330 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1059:

/* Line 1806 of yacc.c  */
#line 7331 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7332 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7333 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7337 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1063:

/* Line 1806 of yacc.c  */
#line 7338 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1064:

/* Line 1806 of yacc.c  */
#line 7343 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1065:

/* Line 1806 of yacc.c  */
#line 7348 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1066:

/* Line 1806 of yacc.c  */
#line 7354 "parser.y"
    { /* Nothing */ }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7355 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7356 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7357 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7358 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
#line 7363 "parser.y"
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
#line 7390 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7394 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7401 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1075:

/* Line 1806 of yacc.c  */
#line 7405 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1076:

/* Line 1806 of yacc.c  */
#line 7414 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7426 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1080:

/* Line 1806 of yacc.c  */
#line 7434 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1081:

/* Line 1806 of yacc.c  */
#line 7438 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1082:

/* Line 1806 of yacc.c  */
#line 7448 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7457 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7461 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1086:

/* Line 1806 of yacc.c  */
#line 7468 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1087:

/* Line 1806 of yacc.c  */
#line 7472 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7482 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7490 "parser.y"
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
#line 7511 "parser.y"
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
#line 7534 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1093:

/* Line 1806 of yacc.c  */
#line 7535 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1094:

/* Line 1806 of yacc.c  */
#line 7536 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1095:

/* Line 1806 of yacc.c  */
#line 7537 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1096:

/* Line 1806 of yacc.c  */
#line 7541 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7542 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7546 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1099:

/* Line 1806 of yacc.c  */
#line 7547 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1100:

/* Line 1806 of yacc.c  */
#line 7548 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1101:

/* Line 1806 of yacc.c  */
#line 7550 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1102:

/* Line 1806 of yacc.c  */
#line 7561 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7572 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7577 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1106:

/* Line 1806 of yacc.c  */
#line 7583 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7588 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1108:

/* Line 1806 of yacc.c  */
#line 7596 "parser.y"
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
#line 7604 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1110:

/* Line 1806 of yacc.c  */
#line 7611 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
#line 7615 "parser.y"
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
#line 7628 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
#line 7635 "parser.y"
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
#line 7646 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1115:

/* Line 1806 of yacc.c  */
#line 7650 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1116:

/* Line 1806 of yacc.c  */
#line 7655 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
#line 7659 "parser.y"
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
#line 7670 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1119:

/* Line 1806 of yacc.c  */
#line 7676 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1120:

/* Line 1806 of yacc.c  */
#line 7677 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1121:

/* Line 1806 of yacc.c  */
#line 7681 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7682 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7685 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7687 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1125:

/* Line 1806 of yacc.c  */
#line 7692 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7702 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
#line 7711 "parser.y"
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
#line 7737 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1130:

/* Line 1806 of yacc.c  */
#line 7738 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1131:

/* Line 1806 of yacc.c  */
#line 7743 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1132:

/* Line 1806 of yacc.c  */
#line 7747 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7751 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1134:

/* Line 1806 of yacc.c  */
#line 7755 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1135:

/* Line 1806 of yacc.c  */
#line 7759 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1136:

/* Line 1806 of yacc.c  */
#line 7763 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7767 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1138:

/* Line 1806 of yacc.c  */
#line 7773 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1139:

/* Line 1806 of yacc.c  */
#line 7774 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1142:

/* Line 1806 of yacc.c  */
#line 7784 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1143:

/* Line 1806 of yacc.c  */
#line 7788 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1144:

/* Line 1806 of yacc.c  */
#line 7798 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7808 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1147:

/* Line 1806 of yacc.c  */
#line 7816 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1148:

/* Line 1806 of yacc.c  */
#line 7826 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1149:

/* Line 1806 of yacc.c  */
#line 7836 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 7845 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 7852 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1153:

/* Line 1806 of yacc.c  */
#line 7856 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1154:

/* Line 1806 of yacc.c  */
#line 7866 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 7878 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1157:

/* Line 1806 of yacc.c  */
#line 7886 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1158:

/* Line 1806 of yacc.c  */
#line 7890 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1159:

/* Line 1806 of yacc.c  */
#line 7894 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 7901 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 7905 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1162:

/* Line 1806 of yacc.c  */
#line 7915 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1163:

/* Line 1806 of yacc.c  */
#line 7926 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 7935 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 7940 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1167:

/* Line 1806 of yacc.c  */
#line 7947 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1168:

/* Line 1806 of yacc.c  */
#line 7948 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 7953 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 7958 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1171:

/* Line 1806 of yacc.c  */
#line 7965 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1172:

/* Line 1806 of yacc.c  */
#line 7969 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 7977 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 7984 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 7988 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1176:

/* Line 1806 of yacc.c  */
#line 7998 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1177:

/* Line 1806 of yacc.c  */
#line 8005 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1184:

/* Line 1806 of yacc.c  */
#line 8020 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1185:

/* Line 1806 of yacc.c  */
#line 8021 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1186:

/* Line 1806 of yacc.c  */
#line 8025 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1187:

/* Line 1806 of yacc.c  */
#line 8026 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1188:

/* Line 1806 of yacc.c  */
#line 8033 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1189:

/* Line 1806 of yacc.c  */
#line 8042 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1192:

/* Line 1806 of yacc.c  */
#line 8054 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1193:

/* Line 1806 of yacc.c  */
#line 8058 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1194:

/* Line 1806 of yacc.c  */
#line 8062 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1195:

/* Line 1806 of yacc.c  */
#line 8066 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1196:

/* Line 1806 of yacc.c  */
#line 8070 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1197:

/* Line 1806 of yacc.c  */
#line 8074 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1198:

/* Line 1806 of yacc.c  */
#line 8078 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1199:

/* Line 1806 of yacc.c  */
#line 8082 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1200:

/* Line 1806 of yacc.c  */
#line 8091 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1201:

/* Line 1806 of yacc.c  */
#line 8095 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1202:

/* Line 1806 of yacc.c  */
#line 8104 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1205:

/* Line 1806 of yacc.c  */
#line 8118 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1208:

/* Line 1806 of yacc.c  */
#line 8132 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1209:

/* Line 1806 of yacc.c  */
#line 8136 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1210:

/* Line 1806 of yacc.c  */
#line 8146 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
#line 8154 "parser.y"
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
#line 8175 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1214:

/* Line 1806 of yacc.c  */
#line 8184 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
#line 8189 "parser.y"
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
#line 8207 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1217:

/* Line 1806 of yacc.c  */
#line 8208 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1219:

/* Line 1806 of yacc.c  */
#line 8213 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1220:

/* Line 1806 of yacc.c  */
#line 8220 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1221:

/* Line 1806 of yacc.c  */
#line 8221 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8226 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1223:

/* Line 1806 of yacc.c  */
#line 8232 "parser.y"
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
#line 8242 "parser.y"
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
#line 8257 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1226:

/* Line 1806 of yacc.c  */
#line 8263 "parser.y"
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
#line 8273 "parser.y"
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
#line 8289 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1230:

/* Line 1806 of yacc.c  */
#line 8299 "parser.y"
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
#line 8311 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1232:

/* Line 1806 of yacc.c  */
#line 8315 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1233:

/* Line 1806 of yacc.c  */
#line 8322 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1234:

/* Line 1806 of yacc.c  */
#line 8326 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1235:

/* Line 1806 of yacc.c  */
#line 8331 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1236:

/* Line 1806 of yacc.c  */
#line 8336 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1237:

/* Line 1806 of yacc.c  */
#line 8343 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1238:

/* Line 1806 of yacc.c  */
#line 8344 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8345 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1240:

/* Line 1806 of yacc.c  */
#line 8346 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1241:

/* Line 1806 of yacc.c  */
#line 8347 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1242:

/* Line 1806 of yacc.c  */
#line 8348 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1243:

/* Line 1806 of yacc.c  */
#line 8353 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1246:

/* Line 1806 of yacc.c  */
#line 8366 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1247:

/* Line 1806 of yacc.c  */
#line 8370 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1248:

/* Line 1806 of yacc.c  */
#line 8380 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8384 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
#line 8390 "parser.y"
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
#line 8402 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1252:

/* Line 1806 of yacc.c  */
#line 8406 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
#line 8410 "parser.y"
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
#line 8418 "parser.y"
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
#line 8429 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8433 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1257:

/* Line 1806 of yacc.c  */
#line 8439 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1258:

/* Line 1806 of yacc.c  */
#line 8440 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8441 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8442 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1261:

/* Line 1806 of yacc.c  */
#line 8449 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8458 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8464 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1265:

/* Line 1806 of yacc.c  */
#line 8465 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8469 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8470 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8471 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1269:

/* Line 1806 of yacc.c  */
#line 8475 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8476 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8481 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8485 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1273:

/* Line 1806 of yacc.c  */
#line 8495 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1275:

/* Line 1806 of yacc.c  */
#line 8504 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8508 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1277:

/* Line 1806 of yacc.c  */
#line 8512 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8519 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8523 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1280:

/* Line 1806 of yacc.c  */
#line 8533 "parser.y"
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
#line 8551 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1285:

/* Line 1806 of yacc.c  */
#line 8560 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8566 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1287:

/* Line 1806 of yacc.c  */
#line 8577 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1289:

/* Line 1806 of yacc.c  */
#line 8585 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1290:

/* Line 1806 of yacc.c  */
#line 8598 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1292:

/* Line 1806 of yacc.c  */
#line 8606 "parser.y"
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
#line 8629 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1298:

/* Line 1806 of yacc.c  */
#line 8639 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1299:

/* Line 1806 of yacc.c  */
#line 8645 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1300:

/* Line 1806 of yacc.c  */
#line 8647 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1301:

/* Line 1806 of yacc.c  */
#line 8651 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1302:

/* Line 1806 of yacc.c  */
#line 8653 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1303:

/* Line 1806 of yacc.c  */
#line 8658 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1304:

/* Line 1806 of yacc.c  */
#line 8664 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8666 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1306:

/* Line 1806 of yacc.c  */
#line 8671 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1307:

/* Line 1806 of yacc.c  */
#line 8677 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1308:

/* Line 1806 of yacc.c  */
#line 8678 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1309:

/* Line 1806 of yacc.c  */
#line 8682 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1310:

/* Line 1806 of yacc.c  */
#line 8683 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1311:

/* Line 1806 of yacc.c  */
#line 8687 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1312:

/* Line 1806 of yacc.c  */
#line 8688 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1313:

/* Line 1806 of yacc.c  */
#line 8693 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1314:

/* Line 1806 of yacc.c  */
#line 8697 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1315:

/* Line 1806 of yacc.c  */
#line 8707 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1321:

/* Line 1806 of yacc.c  */
#line 8724 "parser.y"
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
#line 8749 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1323:

/* Line 1806 of yacc.c  */
#line 8753 "parser.y"
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
#line 8765 "parser.y"
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
#line 8775 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1326:

/* Line 1806 of yacc.c  */
#line 8780 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1327:

/* Line 1806 of yacc.c  */
#line 8785 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1328:

/* Line 1806 of yacc.c  */
#line 8790 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1329:

/* Line 1806 of yacc.c  */
#line 8798 "parser.y"
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
#line 8841 "parser.y"
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
#line 8881 "parser.y"
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
#line 8891 "parser.y"
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
#line 8921 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1340:

/* Line 1806 of yacc.c  */
#line 8930 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1343:

/* Line 1806 of yacc.c  */
#line 8946 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1345:

/* Line 1806 of yacc.c  */
#line 8958 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1346:

/* Line 1806 of yacc.c  */
#line 8967 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1347:

/* Line 1806 of yacc.c  */
#line 8968 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1348:

/* Line 1806 of yacc.c  */
#line 8973 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1349:

/* Line 1806 of yacc.c  */
#line 8977 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1350:

/* Line 1806 of yacc.c  */
#line 8981 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1351:

/* Line 1806 of yacc.c  */
#line 8985 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1352:

/* Line 1806 of yacc.c  */
#line 8991 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1353:

/* Line 1806 of yacc.c  */
#line 8992 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1356:

/* Line 1806 of yacc.c  */
#line 9002 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1357:

/* Line 1806 of yacc.c  */
#line 9006 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1360:

/* Line 1806 of yacc.c  */
#line 9023 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1362:

/* Line 1806 of yacc.c  */
#line 9033 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1365:

/* Line 1806 of yacc.c  */
#line 9046 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1367:

/* Line 1806 of yacc.c  */
#line 9056 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1370:

/* Line 1806 of yacc.c  */
#line 9071 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1372:

/* Line 1806 of yacc.c  */
#line 9081 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1375:

/* Line 1806 of yacc.c  */
#line 9098 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1377:

/* Line 1806 of yacc.c  */
#line 9109 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1383:

/* Line 1806 of yacc.c  */
#line 9132 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1384:

/* Line 1806 of yacc.c  */
#line 9141 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1388:

/* Line 1806 of yacc.c  */
#line 9158 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1389:

/* Line 1806 of yacc.c  */
#line 9167 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1392:

/* Line 1806 of yacc.c  */
#line 9184 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1394:

/* Line 1806 of yacc.c  */
#line 9194 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1395:

/* Line 1806 of yacc.c  */
#line 9204 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1396:

/* Line 1806 of yacc.c  */
#line 9208 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1397:

/* Line 1806 of yacc.c  */
#line 9218 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1398:

/* Line 1806 of yacc.c  */
#line 9225 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1399:

/* Line 1806 of yacc.c  */
#line 9231 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1400:

/* Line 1806 of yacc.c  */
#line 9235 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1404:

/* Line 1806 of yacc.c  */
#line 9248 "parser.y"
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
#line 9256 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9257 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1407:

/* Line 1806 of yacc.c  */
#line 9259 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1408:

/* Line 1806 of yacc.c  */
#line 9260 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1409:

/* Line 1806 of yacc.c  */
#line 9261 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1410:

/* Line 1806 of yacc.c  */
#line 9262 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1411:

/* Line 1806 of yacc.c  */
#line 9263 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1412:

/* Line 1806 of yacc.c  */
#line 9265 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1413:

/* Line 1806 of yacc.c  */
#line 9266 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1414:

/* Line 1806 of yacc.c  */
#line 9267 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9268 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9269 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9270 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1418:

/* Line 1806 of yacc.c  */
#line 9272 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1419:

/* Line 1806 of yacc.c  */
#line 9273 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1420:

/* Line 1806 of yacc.c  */
#line 9274 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1421:

/* Line 1806 of yacc.c  */
#line 9276 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9277 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9278 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9279 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9280 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9283 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1427:

/* Line 1806 of yacc.c  */
#line 9284 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1436:

/* Line 1806 of yacc.c  */
#line 9314 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1437:

/* Line 1806 of yacc.c  */
#line 9318 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1441:

/* Line 1806 of yacc.c  */
#line 9329 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1442:

/* Line 1806 of yacc.c  */
#line 9330 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1443:

/* Line 1806 of yacc.c  */
#line 9331 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1444:

/* Line 1806 of yacc.c  */
#line 9335 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1445:

/* Line 1806 of yacc.c  */
#line 9336 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1446:

/* Line 1806 of yacc.c  */
#line 9337 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1447:

/* Line 1806 of yacc.c  */
#line 9342 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1448:

/* Line 1806 of yacc.c  */
#line 9345 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1449:

/* Line 1806 of yacc.c  */
#line 9349 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1450:

/* Line 1806 of yacc.c  */
#line 9350 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1451:

/* Line 1806 of yacc.c  */
#line 9351 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1452:

/* Line 1806 of yacc.c  */
#line 9354 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1453:

/* Line 1806 of yacc.c  */
#line 9355 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9366 "parser.y"
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
#line 9378 "parser.y"
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
#line 9387 "parser.y"
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
#line 9399 "parser.y"
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
#line 9408 "parser.y"
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
#line 9420 "parser.y"
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
#line 9434 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9436 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1462:

/* Line 1806 of yacc.c  */
#line 9441 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9449 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1464:

/* Line 1806 of yacc.c  */
#line 9456 "parser.y"
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
#line 9476 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1466:

/* Line 1806 of yacc.c  */
#line 9480 "parser.y"
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
#line 9501 "parser.y"
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
#line 9542 "parser.y"
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
#line 9555 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1470:

/* Line 1806 of yacc.c  */
#line 9557 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9561 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1472:

/* Line 1806 of yacc.c  */
#line 9567 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1473:

/* Line 1806 of yacc.c  */
#line 9569 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1474:

/* Line 1806 of yacc.c  */
#line 9574 "parser.y"
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
#line 9588 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1478:

/* Line 1806 of yacc.c  */
#line 9595 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9605 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9606 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9611 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1482:

/* Line 1806 of yacc.c  */
#line 9619 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1483:

/* Line 1806 of yacc.c  */
#line 9627 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1484:

/* Line 1806 of yacc.c  */
#line 9631 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1485:

/* Line 1806 of yacc.c  */
#line 9638 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9654 "parser.y"
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
#line 9668 "parser.y"
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
#line 9685 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1491:

/* Line 1806 of yacc.c  */
#line 9689 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1494:

/* Line 1806 of yacc.c  */
#line 9698 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9705 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1496:

/* Line 1806 of yacc.c  */
#line 9709 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9720 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1502:

/* Line 1806 of yacc.c  */
#line 9724 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9728 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1504:

/* Line 1806 of yacc.c  */
#line 9732 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1505:

/* Line 1806 of yacc.c  */
#line 9736 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1506:

/* Line 1806 of yacc.c  */
#line 9740 "parser.y"
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
#line 9761 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1508:

/* Line 1806 of yacc.c  */
#line 9765 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1516:

/* Line 1806 of yacc.c  */
#line 9782 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1517:

/* Line 1806 of yacc.c  */
#line 9786 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1518:

/* Line 1806 of yacc.c  */
#line 9790 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1534:

/* Line 1806 of yacc.c  */
#line 9837 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1542:

/* Line 1806 of yacc.c  */
#line 9861 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1543:

/* Line 1806 of yacc.c  */
#line 9865 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1544:

/* Line 1806 of yacc.c  */
#line 9869 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1545:

/* Line 1806 of yacc.c  */
#line 9870 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1546:

/* Line 1806 of yacc.c  */
#line 9874 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1547:

/* Line 1806 of yacc.c  */
#line 9879 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1548:

/* Line 1806 of yacc.c  */
#line 9886 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1549:

/* Line 1806 of yacc.c  */
#line 9893 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1550:

/* Line 1806 of yacc.c  */
#line 9900 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1551:

/* Line 1806 of yacc.c  */
#line 9910 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1552:

/* Line 1806 of yacc.c  */
#line 9917 "parser.y"
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
#line 9927 "parser.y"
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
#line 9937 "parser.y"
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
#line 9947 "parser.y"
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
#line 9960 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1557:

/* Line 1806 of yacc.c  */
#line 9964 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1558:

/* Line 1806 of yacc.c  */
#line 9972 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1559:

/* Line 1806 of yacc.c  */
#line 9980 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1560:

/* Line 1806 of yacc.c  */
#line 9984 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1561:

/* Line 1806 of yacc.c  */
#line 9994 "parser.y"
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
#line 10009 "parser.y"
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
#line 10055 "parser.y"
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
#line 10070 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1566:

/* Line 1806 of yacc.c  */
#line 10071 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1567:

/* Line 1806 of yacc.c  */
#line 10072 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1568:

/* Line 1806 of yacc.c  */
#line 10073 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1569:

/* Line 1806 of yacc.c  */
#line 10074 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1570:

/* Line 1806 of yacc.c  */
#line 10075 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1571:

/* Line 1806 of yacc.c  */
#line 10080 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1572:

/* Line 1806 of yacc.c  */
#line 10084 "parser.y"
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
#line 10101 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1574:

/* Line 1806 of yacc.c  */
#line 10105 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1575:

/* Line 1806 of yacc.c  */
#line 10111 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1576:

/* Line 1806 of yacc.c  */
#line 10112 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1577:

/* Line 1806 of yacc.c  */
#line 10113 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 10114 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 10115 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1580:

/* Line 1806 of yacc.c  */
#line 10116 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1581:

/* Line 1806 of yacc.c  */
#line 10117 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1582:

/* Line 1806 of yacc.c  */
#line 10124 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1583:

/* Line 1806 of yacc.c  */
#line 10128 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1584:

/* Line 1806 of yacc.c  */
#line 10132 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1585:

/* Line 1806 of yacc.c  */
#line 10136 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 10140 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 10144 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 10148 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10152 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10156 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1591:

/* Line 1806 of yacc.c  */
#line 10160 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1600:

/* Line 1806 of yacc.c  */
#line 10184 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1601:

/* Line 1806 of yacc.c  */
#line 10188 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1602:

/* Line 1806 of yacc.c  */
#line 10192 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1603:

/* Line 1806 of yacc.c  */
#line 10199 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1604:

/* Line 1806 of yacc.c  */
#line 10203 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1605:

/* Line 1806 of yacc.c  */
#line 10207 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1606:

/* Line 1806 of yacc.c  */
#line 10214 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1607:

/* Line 1806 of yacc.c  */
#line 10221 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1608:

/* Line 1806 of yacc.c  */
#line 10228 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1609:

/* Line 1806 of yacc.c  */
#line 10238 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1610:

/* Line 1806 of yacc.c  */
#line 10245 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1611:

/* Line 1806 of yacc.c  */
#line 10255 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1612:

/* Line 1806 of yacc.c  */
#line 10262 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1613:

/* Line 1806 of yacc.c  */
#line 10273 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1614:

/* Line 1806 of yacc.c  */
#line 10281 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1615:

/* Line 1806 of yacc.c  */
#line 10282 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1616:

/* Line 1806 of yacc.c  */
#line 10286 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1617:

/* Line 1806 of yacc.c  */
#line 10287 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1618:

/* Line 1806 of yacc.c  */
#line 10291 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10292 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10297 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10301 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10308 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10312 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10319 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10320 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10321 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10325 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10326 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10330 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10331 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10332 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10337 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10341 "parser.y"
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
#line 10353 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10358 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10366 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10370 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10374 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10378 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10382 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10386 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10390 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10394 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10400 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1645:

/* Line 1806 of yacc.c  */
#line 10401 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1806 of yacc.c  */
#line 18486 "parser.c"
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
#line 10572 "parser.y"


