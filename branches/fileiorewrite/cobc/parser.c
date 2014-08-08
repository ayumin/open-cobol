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
static struct cb_key_component  *key_component_list;

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
#line 769 "parser.c"

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
#line 1323 "parser.c"

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
#define YYLAST   8094

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  816
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1894
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2710

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
     604,   606,   608,   616,   626,   627,   630,   633,   635,   636,
     641,   645,   650,   651,   653,   655,   656,   662,   665,   668,
     670,   671,   676,   682,   685,   689,   691,   693,   697,   699,
     702,   707,   712,   717,   722,   726,   728,   730,   734,   737,
     740,   743,   744,   747,   751,   753,   756,   758,   760,   766,
     767,   769,   771,   773,   774,   781,   783,   786,   789,   790,
     793,   794,   798,   799,   803,   804,   807,   810,   811,   817,
     821,   823,   825,   826,   829,   832,   835,   837,   839,   841,
     843,   845,   847,   849,   851,   853,   859,   860,   862,   864,
     869,   876,   886,   887,   891,   892,   895,   896,   899,   903,
     909,   915,   917,   919,   921,   923,   927,   933,   934,   937,
     939,   941,   943,   948,   951,   954,   959,   963,   966,   969,
     972,   974,   977,   978,   979,   985,   986,   987,   990,   993,
     997,  1000,  1002,  1003,  1008,  1012,  1015,  1016,  1018,  1020,
    1022,  1023,  1026,  1028,  1031,  1034,  1038,  1040,  1042,  1044,
    1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1065,
    1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,  1089,
    1092,  1095,  1096,  1099,  1101,  1103,  1105,  1107,  1109,  1111,
    1113,  1115,  1117,  1119,  1121,  1123,  1125,  1127,  1130,  1134,
    1135,  1138,  1141,  1143,  1145,  1149,  1151,  1153,  1155,  1157,
    1159,  1161,  1163,  1165,  1167,  1169,  1171,  1173,  1175,  1177,
    1179,  1181,  1183,  1185,  1187,  1189,  1192,  1195,  1198,  1201,
    1204,  1207,  1210,  1213,  1216,  1219,  1221,  1223,  1225,  1227,
    1229,  1231,  1233,  1235,  1237,  1239,  1243,  1247,  1254,  1255,
    1258,  1266,  1267,  1270,  1271,  1275,  1277,  1278,  1284,  1286,
    1288,  1289,  1293,  1295,  1298,  1300,  1303,  1306,  1310,  1312,
    1313,  1319,  1321,  1324,  1326,  1330,  1331,  1336,  1339,  1344,
    1347,  1350,  1351,  1352,  1358,  1359,  1360,  1366,  1367,  1368,
    1374,  1375,  1378,  1379,  1386,  1387,  1390,  1393,  1396,  1400,
    1402,  1404,  1407,  1410,  1412,  1415,  1420,  1422,  1427,  1430,
    1431,  1434,  1436,  1438,  1440,  1442,  1444,  1448,  1453,  1458,
    1463,  1467,  1468,  1471,  1472,  1478,  1479,  1482,  1484,  1486,
    1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1514,  1518,  1520,  1522,  1525,  1527,  1530,
    1532,  1534,  1535,  1538,  1541,  1542,  1545,  1550,  1555,  1556,
    1560,  1562,  1564,  1568,  1575,  1578,  1582,  1585,  1588,  1592,
    1595,  1597,  1600,  1603,  1605,  1607,  1609,  1612,  1615,  1617,
    1622,  1625,  1629,  1630,  1631,  1637,  1638,  1640,  1643,  1647,
    1649,  1650,  1655,  1659,  1660,  1663,  1666,  1669,  1671,  1673,
    1676,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,
    1697,  1699,  1704,  1706,  1708,  1714,  1720,  1724,  1728,  1730,
    1732,  1734,  1736,  1738,  1740,  1742,  1744,  1747,  1750,  1753,
    1755,  1757,  1759,  1761,  1762,  1764,  1766,  1767,  1769,  1771,
    1775,  1778,  1779,  1780,  1781,  1791,  1792,  1797,  1798,  1799,
    1803,  1804,  1808,  1810,  1813,  1818,  1819,  1822,  1825,  1826,
    1830,  1834,  1839,  1844,  1848,  1849,  1851,  1852,  1855,  1856,
    1857,  1865,  1866,  1869,  1871,  1873,  1876,  1878,  1880,  1881,
    1888,  1889,  1892,  1895,  1897,  1898,  1900,  1901,  1902,  1906,
    1907,  1910,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,
    1929,  1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,
    1949,  1951,  1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,
    1969,  1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1987,
    1989,  1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2007,
    2009,  2011,  2014,  2017,  2018,  2023,  2030,  2034,  2038,  2043,
    2047,  2052,  2056,  2060,  2065,  2070,  2074,  2079,  2083,  2088,
    2094,  2098,  2103,  2107,  2111,  2113,  2115,  2117,  2120,  2121,
    2123,  2127,  2131,  2134,  2137,  2140,  2144,  2148,  2152,  2153,
    2155,  2156,  2160,  2161,  2164,  2166,  2169,  2171,  2173,  2175,
    2177,  2179,  2181,  2183,  2185,  2187,  2189,  2191,  2196,  2198,
    2200,  2202,  2204,  2206,  2208,  2210,  2214,  2218,  2222,  2226,
    2230,  2231,  2233,  2234,  2239,  2244,  2250,  2257,  2258,  2261,
    2262,  2264,  2265,  2269,  2273,  2278,  2279,  2282,  2283,  2287,
    2289,  2292,  2297,  2298,  2301,  2302,  2307,  2314,  2315,  2317,
    2319,  2321,  2322,  2323,  2327,  2329,  2332,  2335,  2339,  2340,
    2343,  2346,  2349,  2350,  2354,  2357,  2362,  2364,  2366,  2368,
    2370,  2371,  2374,  2375,  2378,  2379,  2381,  2382,  2386,  2388,
    2391,  2392,  2396,  2399,  2403,  2404,  2406,  2410,  2414,  2417,
    2418,  2423,  2428,  2429,  2431,  2433,  2435,  2436,  2441,  2445,
    2448,  2450,  2453,  2454,  2456,  2457,  2462,  2466,  2470,  2474,
    2478,  2483,  2486,  2491,  2493,  2494,  2498,  2504,  2505,  2508,
    2511,  2514,  2517,  2518,  2521,  2523,  2525,  2526,  2529,  2530,
    2532,  2534,  2537,  2539,  2542,  2545,  2547,  2549,  2552,  2555,
    2557,  2559,  2561,  2563,  2565,  2569,  2573,  2577,  2581,  2582,
    2584,  2585,  2590,  2595,  2602,  2609,  2618,  2627,  2628,  2630,
    2631,  2635,  2638,  2639,  2644,  2647,  2649,  2653,  2655,  2657,
    2659,  2662,  2664,  2666,  2669,  2672,  2676,  2679,  2683,  2685,
    2689,  2692,  2694,  2696,  2698,  2699,  2702,  2703,  2705,  2706,
    2710,  2711,  2714,  2716,  2719,  2721,  2723,  2725,  2726,  2729,
    2730,  2734,  2736,  2737,  2741,  2743,  2744,  2748,  2752,  2753,
    2757,  2760,  2761,  2768,  2772,  2775,  2777,  2778,  2780,  2781,
    2785,  2791,  2792,  2795,  2796,  2800,  2804,  2805,  2808,  2810,
    2813,  2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,  2833,
    2837,  2838,  2842,  2844,  2847,  2848,  2852,  2855,  2857,  2859,
    2861,  2864,  2866,  2868,  2870,  2871,  2875,  2878,  2884,  2886,
    2889,  2892,  2895,  2897,  2899,  2901,  2904,  2906,  2909,  2914,
    2917,  2918,  2920,  2922,  2924,  2926,  2931,  2932,  2935,  2939,
    2943,  2944,  2948,  2949,  2953,  2957,  2962,  2963,  2968,  2973,
    2980,  2981,  2983,  2984,  2988,  2993,  2999,  3001,  3003,  3005,
    3007,  3008,  3012,  3015,  3018,  3021,  3022,  3026,  3029,  3031,
    3032,  3036,  3039,  3040,  3045,  3048,  3049,  3051,  3053,  3055,
    3057,  3061,  3062,  3065,  3067,  3071,  3075,  3076,  3080,  3082,
    3084,  3086,  3090,  3098,  3099,  3104,  3112,  3113,  3116,  3117,
    3120,  3123,  3127,  3131,  3135,  3138,  3139,  3143,  3145,  3147,
    3148,  3150,  3152,  3153,  3157,  3160,  3162,  3163,  3168,  3173,
    3174,  3176,  3177,  3182,  3187,  3188,  3191,  3195,  3196,  3198,
    3200,  3201,  3206,  3211,  3218,  3219,  3222,  3223,  3226,  3228,
    3231,  3235,  3236,  3238,  3239,  3243,  3245,  3247,  3249,  3251,
    3253,  3255,  3257,  3259,  3261,  3263,  3268,  3272,  3274,  3277,
    3280,  3283,  3286,  3289,  3292,  3295,  3298,  3301,  3306,  3310,
    3315,  3317,  3320,  3324,  3326,  3329,  3333,  3337,  3338,  3342,
    3343,  3351,  3352,  3358,  3359,  3362,  3363,  3366,  3367,  3371,
    3372,  3375,  3380,  3381,  3384,  3389,  3390,  3395,  3400,  3401,
    3405,  3406,  3411,  3413,  3415,  3417,  3420,  3423,  3426,  3429,
    3431,  3433,  3436,  3438,  3439,  3441,  3442,  3447,  3450,  3451,
    3454,  3459,  3464,  3465,  3467,  3469,  3471,  3473,  3475,  3476,
    3481,  3487,  3489,  3492,  3494,  3498,  3502,  3503,  3508,  3509,
    3511,  3512,  3517,  3522,  3529,  3536,  3537,  3539,  3542,  3543,
    3545,  3546,  3550,  3552,  3555,  3556,  3560,  3566,  3567,  3571,
    3574,  3575,  3577,  3579,  3580,  3585,  3592,  3593,  3597,  3599,
    3603,  3606,  3609,  3612,  3616,  3617,  3621,  3622,  3626,  3627,
    3631,  3632,  3634,  3635,  3639,  3641,  3643,  3645,  3647,  3649,
    3657,  3658,  3660,  3662,  3664,  3666,  3668,  3670,  3675,  3677,
    3680,  3682,  3685,  3689,  3690,  3692,  3695,  3697,  3701,  3703,
    3705,  3710,  3712,  3714,  3716,  3717,  3722,  3728,  3729,  3732,
    3733,  3738,  3742,  3746,  3748,  3750,  3752,  3754,  3755,  3757,
    3760,  3761,  3764,  3765,  3768,  3771,  3772,  3775,  3776,  3779,
    3782,  3783,  3786,  3787,  3790,  3793,  3794,  3797,  3798,  3801,
    3804,  3806,  3809,  3811,  3813,  3816,  3819,  3822,  3824,  3826,
    3829,  3832,  3835,  3836,  3839,  3840,  3843,  3844,  3847,  3849,
    3851,  3852,  3855,  3857,  3860,  3863,  3865,  3867,  3869,  3871,
    3873,  3875,  3877,  3879,  3881,  3883,  3885,  3887,  3889,  3891,
    3893,  3895,  3897,  3899,  3901,  3903,  3905,  3907,  3909,  3911,
    3913,  3916,  3918,  3920,  3922,  3924,  3926,  3928,  3930,  3934,
    3935,  3937,  3939,  3943,  3947,  3949,  3953,  3957,  3959,  3963,
    3965,  3968,  3971,  3973,  3977,  3979,  3981,  3985,  3987,  3991,
    3993,  3997,  3999,  4002,  4005,  4007,  4009,  4011,  4014,  4016,
    4018,  4020,  4023,  4025,  4026,  4029,  4031,  4033,  4035,  4039,
    4041,  4043,  4046,  4048,  4050,  4052,  4055,  4057,  4059,  4061,
    4063,  4065,  4067,  4069,  4072,  4074,  4076,  4080,  4082,  4085,
    4087,  4089,  4091,  4093,  4096,  4099,  4102,  4107,  4111,  4113,
    4115,  4118,  4120,  4122,  4124,  4126,  4128,  4130,  4132,  4135,
    4138,  4141,  4143,  4145,  4147,  4149,  4151,  4153,  4155,  4157,
    4159,  4161,  4163,  4165,  4167,  4169,  4171,  4173,  4175,  4177,
    4179,  4181,  4183,  4185,  4187,  4189,  4191,  4193,  4196,  4198,
    4202,  4205,  4208,  4210,  4212,  4216,  4219,  4222,  4224,  4226,
    4230,  4234,  4239,  4245,  4247,  4249,  4251,  4253,  4255,  4257,
    4259,  4261,  4263,  4265,  4267,  4270,  4272,  4276,  4278,  4280,
    4282,  4284,  4286,  4288,  4290,  4293,  4299,  4305,  4311,  4316,
    4322,  4328,  4334,  4337,  4340,  4342,  4344,  4346,  4348,  4350,
    4352,  4354,  4356,  4357,  4362,  4368,  4369,  4373,  4376,  4378,
    4382,  4386,  4388,  4392,  4394,  4398,  4399,  4400,  4402,  4403,
    4405,  4406,  4408,  4409,  4412,  4413,  4416,  4417,  4419,  4421,
    4422,  4424,  4425,  4427,  4430,  4431,  4434,  4435,  4439,  4441,
    4443,  4445,  4447,  4449,  4451,  4453,  4455,  4456,  4459,  4461,
    4463,  4465,  4467,  4469,  4471,  4473,  4475,  4477,  4479,  4481,
    4483,  4485,  4487,  4489,  4491,  4493,  4495,  4497,  4499,  4501,
    4503,  4505,  4507,  4509,  4511,  4513,  4515,  4517,  4519,  4521,
    4523,  4525,  4527,  4529,  4531,  4533,  4535,  4537,  4539,  4541,
    4543,  4545,  4547,  4549,  4551,  4553,  4555,  4557,  4559,  4561,
    4563,  4565,  4567,  4569,  4571,  4573,  4575,  4577,  4579,  4581,
    4583,  4585,  4587,  4589,  4591,  4593,  4595,  4597,  4599,  4600,
    4602,  4603,  4605,  4606,  4608,  4609,  4611,  4612,  4614,  4615,
    4617,  4618,  4620,  4621,  4623,  4624,  4626,  4627,  4629,  4630,
    4632,  4633,  4635,  4636,  4638,  4639,  4641,  4642,  4644,  4645,
    4647,  4648,  4650,  4651,  4653,  4656,  4657,  4659,  4660,  4662,
    4663,  4665,  4666,  4668,  4669,  4671,  4673,  4674,  4676,  4677,
    4679,  4681,  4682,  4684,  4686,  4687,  4690,  4693,  4694,  4696,
    4697,  4699,  4700,  4702,  4703,  4705,  4707,  4708,  4710,  4711,
    4713,  4714,  4717,  4719,  4721,  4722,  4724,  4725,  4727,  4728,
    4730,  4731,  4733,  4734,  4736,  4737,  4739,  4740,  4742,  4743,
    4745,  4748,  4749,  4751,  4752,  4754,  4755,  4757,  4758,  4760,
    4761,  4763,  4764,  4766,  4767,  4769,  4770,  4772,  4774,  4775,
    4777,  4778,  4782,  4783,  4785,  4788,  4790,  4792,  4794,  4796,
    4798,  4800,  4802,  4804,  4806,  4808,  4810,  4812,  4814,  4816,
    4818,  4820,  4822,  4824,  4826,  4828,  4830,  4833,  4836,  4838,
    4840,  4842,  4844,  4846,  4848,  4851,  4853,  4857,  4860,  4862,
    4864,  4866,  4869,  4871,  4874,  4876,  4879,  4881,  4884,  4886,
    4889,  4891,  4894,  4896,  4899
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
      -1,   540,   541,   542,   603,   604,   606,   605,   641,   529,
     651,   652,   653,   530,   682,   735,   737,   739,   784,   531,
     798,    -1,    -1,   341,   451,   535,   536,   533,   537,   451,
      -1,   200,   451,   535,   536,   451,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1271,   538,  1286,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1302,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1271,  1220,  1313,    -1,  1319,
    1271,  1186,    -1,   396,  1271,  1220,    -1,  1258,    59,  1271,
     557,    -1,  1186,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1271,    96,    -1,  1220,  1271,  1191,    -1,
    1271,  1191,   574,    -1,   575,    -1,    -1,   575,    -1,  1035,
    1283,  1191,    -1,   575,  1035,  1283,  1191,    -1,    -1,    11,
    1191,   577,  1271,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1259,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1272,
     590,    -1,  1192,    -1,   589,  1192,    -1,  1221,    -1,   590,
    1221,    -1,    58,  1191,  1271,   592,    -1,   593,    -1,   592,
     593,    -1,  1223,    -1,  1223,   442,  1223,    -1,   257,  1191,
    1271,   256,    -1,    98,  1289,  1271,   256,   596,    -1,    -1,
    1302,   328,   256,    -1,   108,  1271,    68,    -1,   301,   405,
    1271,   468,   400,    -1,   100,  1271,  1185,    -1,    96,   423,
    1271,  1185,    -1,   390,  1271,  1185,    -1,   164,  1271,  1185,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1244,  1191,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     624,    -1,   625,    -1,   627,    -1,   631,    -1,   633,    -1,
     634,    -1,   635,    -1,   636,    -1,   637,    -1,   639,    -1,
      29,  1299,   614,   613,   615,    -1,    29,  1299,   614,   612,
     616,    -1,    29,  1299,   614,   119,   616,    -1,    29,  1299,
     614,   238,   616,    -1,    29,  1299,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1262,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1217,    -1,    -1,   256,    -1,  1217,    -1,     4,  1278,  1271,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,   351,
    1273,  1271,  1185,  1238,   623,    -1,    19,   351,  1273,  1271,
    1185,   452,   620,  1238,   623,    -1,    -1,   621,   622,    -1,
     620,   622,    -1,  1185,    -1,    -1,   432,   501,     9,  1202,
      -1,  1303,  1271,   504,    -1,   626,   423,  1271,  1185,    -1,
      -1,   454,    -1,   412,    -1,    -1,   628,   262,  1278,  1271,
     629,    -1,   267,   630,    -1,    33,   630,    -1,   167,    -1,
      -1,   503,   262,   309,  1312,    -1,   503,   262,   309,   274,
    1312,    -1,   503,   385,    -1,   315,  1271,   632,    -1,   632,
      -1,   220,    -1,  1287,  1256,   402,    -1,   359,    -1,   252,
     402,    -1,   320,  1258,  1271,  1190,    -1,   351,   113,  1271,
     419,    -1,   351,  1273,  1271,  1185,    -1,   359,  1273,  1271,
    1189,    -1,   372,   638,  1253,    -1,   287,    -1,  1220,    -1,
     404,  1302,   640,    -1,     9,  1284,    -1,   287,  1284,    -1,
     349,   310,    -1,    -1,   642,   451,    -1,   642,     1,   451,
      -1,   643,    -1,   642,   643,    -1,   644,    -1,   646,    -1,
     388,   645,  1253,  1264,  1175,    -1,    -1,   351,    -1,   412,
      -1,   413,    -1,    -1,   274,   647,  1262,  1295,  1260,   648,
      -1,   649,    -1,   648,   649,    -1,  1176,   650,    -1,    -1,
     331,  1220,    -1,    -1,   102,   122,   451,    -1,    -1,   454,
     394,   451,    -1,    -1,   653,   654,    -1,   655,   684,    -1,
      -1,   657,  1176,   656,   658,   451,    -1,   657,     1,   451,
      -1,   172,    -1,   392,    -1,    -1,   658,   659,    -1,  1271,
     171,    -1,  1271,   204,    -1,   660,    -1,   662,    -1,   666,
      -1,   667,    -1,   670,    -1,   671,    -1,   677,    -1,   678,
      -1,   679,    -1,    47,  1260,  1220,   665,   661,    -1,    -1,
     353,    -1,    57,    -1,   351,  1260,  1220,  1259,    -1,   351,
    1260,  1220,   446,  1220,  1259,    -1,   351,  1271,   499,  1266,
    1292,   664,   665,  1259,   663,    -1,    -1,   114,  1282,  1185,
      -1,    -1,  1265,  1220,    -1,    -1,   446,  1220,    -1,   239,
    1314,  1310,    -1,   498,   306,   668,  1271,   669,    -1,   498,
     306,   174,  1271,   669,    -1,   504,    -1,   213,    -1,   256,
      -1,  1217,    -1,   102,  1314,  1187,    -1,   250,  1271,  1190,
    1277,   672,    -1,    -1,   672,   673,    -1,   674,    -1,   675,
      -1,   676,    -1,  1302,   187,  1255,  1190,    -1,   465,  1190,
      -1,    48,  1190,    -1,   352,  1278,  1271,   504,    -1,    62,
    1271,   504,    -1,   680,   681,    -1,   366,  1271,    -1,   368,
    1252,    -1,  1191,    -1,   681,  1191,    -1,    -1,    -1,   506,
     394,   451,   683,   684,    -1,    -1,    -1,   685,   686,    -1,
     687,   451,    -1,   686,   687,   451,    -1,   686,   451,    -1,
     699,    -1,    -1,   689,   690,   688,   701,    -1,   689,     1,
     451,    -1,  1236,   504,    -1,    -1,   175,    -1,   504,    -1,
     504,    -1,    -1,  1271,   204,    -1,  1224,    -1,   245,   694,
      -1,   244,   694,    -1,    50,  1281,   694,    -1,  1214,    -1,
      41,    -1,    44,    -1,    43,    -1,    42,    -1,    40,    -1,
     698,    -1,   710,    -1,   711,    -1,   695,    -1,   696,    -1,
     697,    -1,     1,   451,    -1,   179,    -1,   183,    -1,   180,
      -1,   181,    -1,   178,    -1,   182,    -1,   184,    -1,   330,
      -1,   343,    -1,   689,   691,    85,   692,   700,    -1,  1254,
     693,    -1,   196,   504,    -1,    -1,   701,   702,    -1,   703,
      -1,   704,    -1,   706,    -1,   707,    -1,   708,    -1,   712,
      -1,   715,    -1,   724,    -1,   725,    -1,   726,    -1,   727,
      -1,   728,    -1,   733,    -1,   734,    -1,   355,  1214,    -1,
    1271,   171,   705,    -1,    -1,    26,   256,    -1,  1271,   204,
      -1,   327,    -1,   709,    -1,   491,  1271,   709,    -1,    39,
      -1,    73,    -1,   710,    -1,   711,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,   119,    -1,   219,
      -1,   319,    -1,   330,    -1,   343,    -1,   409,    -1,   407,
      -1,   408,    -1,   479,    -1,   477,    -1,   478,    -1,    41,
    1290,    -1,    41,   476,    -1,    44,  1290,    -1,    44,   476,
      -1,    43,  1290,    -1,    43,   476,    -1,    42,  1290,    -1,
      42,   476,    -1,    40,  1290,    -1,    40,   476,    -1,   179,
      -1,   180,    -1,   178,    -1,   181,    -1,   182,    -1,   277,
      -1,    75,    -1,   186,    -1,    76,    -1,   185,    -1,  1291,
     241,  1248,    -1,  1291,   468,  1248,    -1,   305,  1220,   716,
    1297,   717,   714,    -1,    -1,   425,  1220,    -1,   305,  1220,
     716,  1297,   717,   718,   721,    -1,    -1,   446,  1220,    -1,
      -1,   114,  1282,  1185,    -1,   719,    -1,    -1,   719,   720,
    1273,  1271,  1184,    -1,    27,    -1,   115,    -1,    -1,   220,
    1257,   722,    -1,   723,    -1,   722,   723,    -1,   504,    -1,
     235,  1288,    -1,   434,  1274,    -1,    45,  1300,   510,    -1,
      36,    -1,    -1,   498,  1272,   730,   729,   732,    -1,   731,
      -1,   730,   731,    -1,  1224,    -1,  1224,   442,  1224,    -1,
      -1,  1301,   453,  1271,  1224,    -1,   363,  1217,    -1,   363,
    1217,   442,  1217,    -1,    21,   244,    -1,    21,   301,    -1,
      -1,    -1,   261,   394,   451,   736,   684,    -1,    -1,    -1,
     255,   394,   451,   738,   684,    -1,    -1,    -1,   366,   394,
     451,   740,   741,    -1,    -1,   741,   742,    -1,    -1,   348,
    1177,   743,   744,   451,   758,    -1,    -1,   744,   745,    -1,
       1,   451,    -1,  1271,   204,    -1,    61,  1271,  1204,    -1,
     746,    -1,   749,    -1,  1327,   747,    -1,  1263,   748,    -1,
    1213,    -1,   748,  1213,    -1,   321,  1276,   750,   751,    -1,
    1222,    -1,  1222,  1311,  1222,  1305,    -1,  1222,  1311,    -1,
      -1,   751,   752,    -1,   753,    -1,   754,    -1,   755,    -1,
     756,    -1,   757,    -1,   210,  1271,  1222,    -1,   177,  1320,
    1271,  1222,    -1,   240,  1321,  1271,  1222,    -1,   240,  1320,
    1271,  1222,    -1,   187,  1271,  1222,    -1,    -1,   758,   759,
      -1,    -1,   689,   690,   760,   761,   451,    -1,    -1,   761,
     762,    -1,   763,    -1,   767,    -1,   773,    -1,   707,    -1,
     783,    -1,   712,    -1,   724,    -1,   775,    -1,   726,    -1,
     781,    -1,   768,    -1,   728,    -1,   771,    -1,   782,    -1,
     713,    -1,   772,    -1,   472,  1271,   764,    -1,  1325,    -1,
    1323,    -1,  1321,   765,    -1,  1320,    -1,  1322,   765,    -1,
    1324,    -1,  1326,    -1,    -1,  1213,   766,    -1,   176,   766,
      -1,    -1,   313,   321,    -1,   285,   209,  1271,   778,    -1,
     431,  1281,  1197,   769,    -1,    -1,   373,  1282,   770,    -1,
    1213,    -1,   176,    -1,   333,   501,  1152,    -1,   499,  1213,
     196,  1199,    49,  1199,    -1,   774,   777,    -1,   252,  1280,
    1272,    -1,   254,  1252,    -1,   776,   779,    -1,  1304,  1280,
    1272,    -1,  1305,  1252,    -1,   778,    -1,   777,   778,    -1,
     329,  1220,    -1,  1222,    -1,   286,    -1,   780,    -1,   779,
     780,    -1,   329,  1220,    -1,  1222,    -1,   414,  1271,  1199,
    1245,    -1,   209,  1268,    -1,   491,  1271,   119,    -1,    -1,
      -1,   389,   394,   451,   785,   786,    -1,    -1,   787,    -1,
     788,   451,    -1,   787,   788,   451,    -1,   699,    -1,    -1,
     689,   690,   789,   790,    -1,   689,     1,   451,    -1,    -1,
     790,   791,    -1,    45,   252,    -1,    45,   389,    -1,    38,
      -1,    46,    -1,   160,   156,    -1,   160,   158,    -1,   211,
      -1,   265,    -1,   378,    -1,   473,    -1,   318,    -1,   243,
      -1,    32,    -1,   395,    -1,   371,    -1,   198,    -1,   345,
      56,  1271,  1204,    -1,   345,    -1,   456,    -1,   252,  1279,
    1271,   794,  1206,    -1,  1304,  1279,  1271,   795,  1206,    -1,
     189,  1271,  1206,    -1,    35,  1271,  1206,    -1,   708,    -1,
     726,    -1,   797,    -1,   724,    -1,   712,    -1,   728,    -1,
     707,    -1,   796,    -1,   497,  1213,    -1,   196,  1205,    -1,
     446,  1213,    -1,   329,    -1,   463,    -1,   270,    -1,   458,
      -1,    -1,   792,    -1,   793,    -1,    -1,   792,    -1,   793,
      -1,   305,  1220,  1297,    -1,  1271,   204,    -1,    -1,    -1,
      -1,   337,   122,   802,   810,   451,   799,   811,   800,   813,
      -1,    -1,   801,   824,   451,   813,    -1,    -1,    -1,   497,
     803,   805,    -1,    -1,    55,   804,   805,    -1,   806,    -1,
     805,   806,    -1,   807,   808,   809,   504,    -1,    -1,  1257,
     357,    -1,  1257,   498,    -1,    -1,   410,  1271,    32,    -1,
     410,  1271,   110,    -1,   476,   410,  1271,    32,    -1,   476,
     410,  1271,  1220,    -1,   410,  1271,  1220,    -1,    -1,   312,
      -1,    -1,   376,   504,    -1,    -1,    -1,   109,   451,   812,
     813,   129,   109,   451,    -1,    -1,   813,   814,    -1,   815,
      -1,   818,    -1,   824,   451,    -1,   819,    -1,   451,    -1,
      -1,   504,   394,   820,   451,   816,   817,    -1,    -1,  1106,
     451,    -1,   504,   451,    -1,   504,    -1,    -1,  1220,    -1,
      -1,    -1,   822,   823,   824,    -1,    -1,   825,   826,    -1,
     824,   826,    -1,   827,    -1,   842,    -1,   847,    -1,   851,
      -1,   856,    -1,   871,    -1,   874,    -1,   882,    -1,   878,
      -1,   883,    -1,   884,    -1,   889,    -1,   903,    -1,   907,
      -1,   910,    -1,   924,    -1,   928,    -1,   931,    -1,   934,
      -1,   938,    -1,   939,    -1,   943,    -1,   953,    -1,   956,
      -1,   973,    -1,   975,    -1,   978,    -1,   982,    -1,   989,
      -1,  1001,    -1,  1009,    -1,  1010,    -1,  1013,    -1,  1014,
      -1,  1018,    -1,  1023,    -1,  1024,    -1,  1032,    -1,  1047,
      -1,  1057,    -1,  1066,    -1,  1071,    -1,  1078,    -1,  1082,
      -1,  1084,    -1,  1087,    -1,  1090,    -1,  1094,    -1,  1121,
      -1,   285,   399,    -1,     1,  1249,    -1,    -1,     3,   828,
     829,   841,    -1,   830,   832,   836,   837,   838,  1129,    -1,
    1213,   196,   831,    -1,  1213,   196,  1305,    -1,  1213,   196,
     103,   509,    -1,  1213,   196,   103,    -1,  1213,   196,   104,
     508,    -1,  1213,   196,   104,    -1,  1213,   196,   105,    -1,
    1213,   196,   162,   237,    -1,  1213,   196,   165,   423,    -1,
    1213,   196,   443,    -1,  1213,   196,   493,   276,    -1,  1213,
     196,    69,    -1,  1213,   196,   155,  1129,    -1,  1213,   196,
     153,  1202,  1129,    -1,  1213,   196,    24,    -1,  1213,   196,
      25,  1129,    -1,  1213,   196,  1179,    -1,  1213,   196,   504,
      -1,  1213,    -1,   308,    -1,   254,    -1,   252,   299,    -1,
      -1,   833,    -1,  1255,   834,   835,    -1,  1255,   835,   834,
      -1,  1255,   834,    -1,  1255,   835,    -1,    30,  1202,    -1,
     252,  1279,  1206,    -1,  1304,  1279,  1206,    -1,   331,  1279,
    1206,    -1,    -1,   197,    -1,    -1,   272,  1271,    47,    -1,
      -1,   503,   839,    -1,   840,    -1,   839,   840,    -1,    32,
      -1,    38,    -1,    46,    -1,    91,    -1,   198,    -1,   211,
      -1,   243,    -1,   263,    -1,   265,    -1,   288,    -1,   318,
      -1,   345,    56,  1271,  1204,    -1,   345,    -1,   371,    -1,
     378,    -1,   395,    -1,   473,    -1,   483,    -1,   489,    -1,
     189,  1271,  1206,    -1,    35,  1271,  1206,    -1,   391,   482,
    1151,    -1,   391,   123,  1151,    -1,   444,  1251,  1207,    -1,
      -1,   130,    -1,    -1,     5,   843,   844,   846,    -1,  1195,
     446,  1171,  1135,    -1,  1195,   845,   203,  1171,  1135,    -1,
      94,  1213,   446,  1213,  1245,  1135,    -1,    -1,   446,  1196,
      -1,    -1,   131,    -1,    -1,    10,   848,   849,    -1,  1213,
    1239,   850,    -1,  1165,    57,  1240,   850,    -1,    -1,   376,
    1194,    -1,    -1,    18,   852,   853,    -1,   854,    -1,   853,
     854,    -1,  1181,   446,   855,  1181,    -1,    -1,   339,   446,
      -1,    -1,    51,   857,   858,   870,    -1,   859,  1205,   860,
     865,   868,   869,    -1,    -1,   422,    -1,   424,    -1,   271,
      -1,    -1,    -1,   497,   861,   862,    -1,   863,    -1,   862,
     863,    -1,   864,   308,    -1,   864,   808,  1196,    -1,    -1,
    1257,   357,    -1,  1257,    87,    -1,  1257,   498,    -1,    -1,
     866,  1270,  1213,    -1,   866,   867,    -1,   866,     6,  1281,
    1213,    -1,   376,    -1,   203,    -1,   460,    -1,   308,    -1,
      -1,  1308,   821,    -1,    -1,   294,   821,    -1,    -1,   132,
      -1,    -1,    52,   872,   873,    -1,  1204,    -1,   873,  1204,
      -1,    -1,    60,   875,   876,    -1,  1176,   877,    -1,   876,
    1176,   877,    -1,    -1,  1315,    -1,  1315,  1264,   362,    -1,
    1302,   287,   380,    -1,  1302,   262,    -1,    -1,    74,   879,
     880,   881,    -1,  1171,  1306,  1165,  1135,    -1,    -1,   133,
      -1,    71,    -1,    88,    -1,    -1,   111,   885,   886,   888,
      -1,  1176,  1287,  1148,    -1,   454,   887,    -1,  1176,    -1,
     887,  1176,    -1,    -1,   134,    -1,    -1,   119,   890,   891,
     902,    -1,  1204,   487,  1132,    -1,  1204,   488,  1132,    -1,
    1204,   485,  1132,    -1,  1204,   486,  1132,    -1,  1195,   895,
     899,  1132,    -1,   892,  1132,    -1,  1196,   503,   900,  1132,
      -1,   894,    -1,    -1,   892,   893,   894,    -1,  1196,   833,
     896,   837,   898,    -1,    -1,   484,  1179,    -1,   484,   504,
      -1,   484,   335,    -1,   484,    96,    -1,    -1,   484,   897,
      -1,    96,    -1,    97,    -1,    -1,   503,   900,    -1,    -1,
     298,    -1,   901,    -1,   900,   901,    -1,    38,    -1,    45,
     252,    -1,    45,   389,    -1,    46,    -1,    91,    -1,   160,
     156,    -1,   160,   158,    -1,   211,    -1,   265,    -1,   318,
      -1,   378,    -1,   473,    -1,   189,  1271,  1206,    -1,    35,
    1271,  1206,    -1,   391,   482,  1151,    -1,   391,   123,  1151,
      -1,    -1,   135,    -1,    -1,   121,   904,   905,   906,    -1,
    1196,   228,  1171,  1135,    -1,  1196,   228,  1196,   203,  1171,
    1135,    -1,  1196,    49,  1196,   203,  1171,  1135,    -1,  1196,
     228,  1196,   203,  1172,   361,  1172,  1135,    -1,  1196,    49,
    1196,   203,  1172,   361,  1172,  1135,    -1,    -1,   136,    -1,
      -1,   152,   908,   909,    -1,   256,   860,    -1,    -1,   163,
     911,   912,   923,    -1,   913,   915,    -1,   914,    -1,   913,
      17,   914,    -1,  1153,    -1,   464,    -1,   453,    -1,   916,
     918,    -1,   916,    -1,   917,    -1,   916,   917,    -1,   919,
     821,    -1,   501,   316,   821,    -1,   501,   920,    -1,   919,
     501,   920,    -1,   921,    -1,   920,    17,   921,    -1,  1154,
     922,    -1,    21,    -1,   464,    -1,   453,    -1,    -1,   442,
    1153,    -1,    -1,   137,    -1,    -1,   168,   925,   926,    -1,
      -1,   340,   927,    -1,   199,    -1,   324,   101,    -1,   324,
      -1,   394,    -1,   323,    -1,    -1,   866,  1196,    -1,    -1,
     195,   929,   930,    -1,  1193,    -1,    -1,   202,   932,   933,
      -1,  1217,    -1,    -1,   205,   935,   936,    -1,  1298,  1180,
     937,    -1,    -1,   114,  1282,  1213,    -1,   206,   927,    -1,
      -1,   215,   940,  1152,  1296,   941,   942,    -1,   821,   128,
     821,    -1,   128,   821,    -1,   821,    -1,    -1,   139,    -1,
      -1,   222,   944,   945,    -1,  1193,   946,   947,   948,   952,
      -1,    -1,  1302,   175,    -1,    -1,     9,  1298,   498,    -1,
     951,  1298,   498,    -1,    -1,   365,   949,    -1,   950,    -1,
     949,   950,    -1,   951,  1261,    49,  1196,    -1,    12,    -1,
      15,    -1,   301,    -1,    16,    -1,   302,    -1,   277,    -1,
     278,    -1,    -1,  1296,  1298,   110,    -1,    -1,   224,   954,
     955,    -1,  1177,    -1,   955,  1177,    -1,    -1,   227,   957,
     958,    -1,   959,   960,    -1,  1213,    -1,  1224,    -1,  1227,
      -1,   961,   963,    -1,   961,    -1,   963,    -1,   964,    -1,
      -1,   436,   962,   965,    -1,   365,   967,    -1,    92,  1202,
     446,  1203,   971,    -1,   966,    -1,   965,   966,    -1,  1202,
     188,    -1,    57,   971,    -1,     9,    -1,   241,    -1,   468,
      -1,  1202,   971,    -1,   968,    -1,   967,   968,    -1,    57,
      49,  1202,   971,    -1,   969,   970,    -1,    -1,     9,    -1,
     241,    -1,   177,    -1,   468,    -1,  1202,    49,  1203,   971,
      -1,    -1,   971,   972,    -1,    37,  1269,  1196,    -1,     8,
    1269,  1196,    -1,    -1,   269,   974,  1049,    -1,    -1,   273,
     976,   977,    -1,  1196,   446,  1193,    -1,    94,  1196,   446,
    1193,    -1,    -1,   275,   979,   980,   981,    -1,  1196,    49,
    1171,  1135,    -1,  1196,    49,  1196,   203,  1171,  1135,    -1,
      -1,   140,    -1,    -1,   311,   983,   984,    -1,   985,   986,
    1175,   988,    -1,   984,   985,   986,  1175,   988,    -1,   225,
      -1,   317,    -1,   233,    -1,   170,    -1,    -1,   404,  1302,
     987,    -1,     9,  1284,    -1,   287,  1284,    -1,   349,   310,
      -1,    -1,  1302,   287,   380,    -1,  1302,   262,    -1,   379,
      -1,    -1,   324,   990,   991,    -1,   995,   996,    -1,    -1,
     996,   992,   821,   993,    -1,   996,   994,    -1,    -1,   141,
      -1,   141,    -1,   451,    -1,  1181,    -1,  1181,   442,  1181,
      -1,    -1,  1205,   445,    -1,   190,    -1,   997,   481,   998,
      -1,   997,   499,   999,    -1,    -1,  1302,   439,  1126,    -1,
     168,    -1,  1152,    -1,  1000,    -1,   999,     8,  1000,    -1,
    1213,   196,  1196,    49,  1196,   481,  1152,    -1,    -1,   349,
    1002,  1003,  1008,    -1,  1176,  1242,  1287,  1004,  1005,  1006,
    1007,    -1,    -1,   228,  1213,    -1,    -1,   217,   262,    -1,
    1302,   262,    -1,  1302,   236,   262,    -1,  1302,   287,   262,
      -1,  1302,   216,   262,    -1,  1302,   500,    -1,    -1,   237,
    1271,  1213,    -1,  1148,    -1,  1142,    -1,    -1,   143,    -1,
     350,    -1,    -1,   360,  1011,  1012,    -1,  1173,  1124,    -1,
     374,    -1,    -1,   375,  1015,  1016,  1017,    -1,  1176,  1287,
    1004,  1141,    -1,    -1,   144,    -1,    -1,   381,  1019,  1020,
    1022,    -1,  1173,  1124,  1021,  1148,    -1,    -1,  1302,   262,
      -1,  1302,   287,   262,    -1,    -1,   145,    -1,   385,    -1,
      -1,   393,  1025,  1026,  1031,    -1,  1174,  1027,  1028,  1029,
      -1,     9,  1174,  1028,   501,  1153,   821,    -1,    -1,   499,
    1213,    -1,    -1,   129,   821,    -1,  1030,    -1,  1030,  1029,
      -1,   501,  1152,   821,    -1,    -1,   146,    -1,    -1,   403,
    1033,  1034,    -1,  1037,    -1,  1038,    -1,  1041,    -1,  1042,
      -1,  1043,    -1,  1045,    -1,   309,    -1,   307,    -1,   482,
      -1,   123,    -1,   153,  1202,   446,  1202,    -1,  1210,    31,
    1039,    -1,  1040,    -1,  1039,  1040,    -1,    38,  1035,    -1,
      46,  1035,    -1,   211,  1035,    -1,   265,  1035,    -1,   378,
    1035,    -1,   473,  1035,    -1,   243,  1035,    -1,   318,  1035,
      -1,  1193,   446,   152,  1201,    -1,  1193,   446,  1196,    -1,
    1193,  1036,    49,  1196,    -1,  1044,    -1,  1043,  1044,    -1,
    1178,   446,  1035,    -1,  1046,    -1,  1045,  1046,    -1,  1193,
     446,   464,    -1,  1193,   446,   453,    -1,    -1,   412,  1048,
    1049,    -1,    -1,  1211,  1051,  1053,  1054,  1050,  1055,  1056,
      -1,    -1,  1051,  1282,   720,  1273,  1052,    -1,    -1,  1052,
    1217,    -1,    -1,  1318,  1267,    -1,    -1,  1303,  1271,  1185,
      -1,    -1,   497,  1175,    -1,   225,   337,  1271,   995,    -1,
      -1,   203,  1175,    -1,   317,   337,  1271,   995,    -1,    -1,
     421,  1058,  1059,  1065,    -1,  1176,  1061,  1060,  1148,    -1,
      -1,  1302,  1317,  1165,    -1,    -1,   237,  1271,  1062,  1213,
      -1,   177,    -1,   240,    -1,  1158,    -1,  1243,  1159,    -1,
    1243,  1160,    -1,  1243,  1161,    -1,  1243,  1162,    -1,  1063,
      -1,  1064,    -1,   290,  1158,    -1,   293,    -1,    -1,   147,
      -1,    -1,   426,   387,  1067,  1068,    -1,   426,  1070,    -1,
      -1,   866,  1196,    -1,  1302,   161,  1294,  1069,    -1,  1302,
     289,  1294,  1069,    -1,    -1,  1196,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,    -1,   427,  1072,  1073,  1077,
      -1,  1074,   228,  1213,  1076,  1138,    -1,  1075,    -1,  1074,
    1075,    -1,  1196,    -1,   112,  1257,   410,    -1,   112,  1257,
    1196,    -1,    -1,  1302,   330,  1271,  1213,    -1,    -1,   148,
      -1,    -1,   430,  1079,  1080,  1081,    -1,  1195,   196,  1171,
    1135,    -1,  1195,   196,  1196,   203,  1171,  1135,    -1,    94,
    1213,   196,  1213,  1245,  1135,    -1,    -1,   149,    -1,   432,
    1083,    -1,    -1,   336,    -1,    -1,   438,  1085,  1086,    -1,
    1177,    -1,  1086,  1177,    -1,    -1,   469,  1088,  1089,    -1,
    1213,   196,  1202,   446,  1203,    -1,    -1,   475,  1091,  1092,
      -1,  1176,  1093,    -1,    -1,   351,    -1,   353,    -1,    -1,
     480,  1095,  1096,  1105,    -1,  1213,  1097,  1100,  1076,  1104,
    1138,    -1,    -1,   112,  1257,  1098,    -1,  1099,    -1,  1098,
     313,  1099,    -1,  1237,  1202,    -1,   228,  1101,    -1,  1100,
    1101,    -1,  1213,  1102,  1103,    -1,    -1,   113,  1266,  1213,
      -1,    -1,    95,  1266,  1213,    -1,    -1,   436,  1266,  1213,
      -1,    -1,   150,    -1,    -1,   492,  1107,  1108,    -1,  1109,
      -1,  1112,    -1,  1116,    -1,  1118,    -1,  1119,    -1,  1110,
    1251,  1293,  1307,  1285,  1282,  1111,    -1,    -1,   204,    -1,
    1175,    -1,   225,    -1,   317,    -1,   233,    -1,   170,    -1,
    1264,   107,  1282,  1113,    -1,  1114,    -1,  1113,  1114,    -1,
    1182,    -1,     9,   338,    -1,     9,  1115,  1217,    -1,    -1,
     358,    -1,   358,   306,    -1,   306,    -1,  1255,   340,  1117,
      -1,   421,    -1,   129,    -1,  1110,    37,   367,  1213,    -1,
    1120,    -1,   166,    -1,   127,    -1,    -1,   507,  1122,  1123,
    1128,    -1,  1173,  1124,  1125,  1021,  1127,    -1,    -1,   196,
    1209,    -1,    -1,  1126,  1250,  1206,  1275,    -1,  1126,  1250,
    1179,    -1,  1126,  1250,   321,    -1,    37,    -1,     8,    -1,
    1148,    -1,  1145,    -1,    -1,   151,    -1,  1130,  1131,    -1,
      -1,   165,   821,    -1,    -1,   294,   821,    -1,  1133,  1134,
      -1,    -1,   165,   821,    -1,    -1,   294,   821,    -1,  1136,
    1137,    -1,    -1,   411,   821,    -1,    -1,   297,   821,    -1,
    1139,  1140,    -1,    -1,   461,   821,    -1,    -1,   296,   821,
      -1,  1143,  1144,    -1,  1143,    -1,  1143,  1144,    -1,  1143,
      -1,  1144,    -1,   129,   821,    -1,   291,   821,    -1,  1146,
    1147,    -1,  1146,    -1,  1147,    -1,   157,   821,    -1,   292,
     821,    -1,  1149,  1150,    -1,    -1,   231,   821,    -1,    -1,
     295,   821,    -1,    -1,  1208,  1316,    -1,  1153,    -1,  1154,
      -1,    -1,  1155,  1156,    -1,  1157,    -1,  1156,   232,    -1,
    1156,  1157,    -1,  1196,    -1,   462,    -1,   448,    -1,   463,
      -1,   458,    -1,   459,    -1,   450,    -1,   169,    -1,  1158,
      -1,  1159,    -1,  1160,    -1,  1161,    -1,  1162,    -1,   293,
      -1,   290,    -1,    20,    -1,   313,    -1,   308,    -1,   301,
      -1,    12,    -1,    13,    -1,    14,    -1,   332,    -1,   284,
      -1,   452,    -1,   159,  1298,    -1,   455,    -1,   207,    -1,
     457,    -1,   246,    -1,   208,    -1,   247,    -1,  1165,    -1,
    1163,  1164,  1165,    -1,    -1,    70,    -1,   398,    -1,  1165,
     463,  1166,    -1,  1165,   458,  1166,    -1,  1166,    -1,  1166,
     459,  1167,    -1,  1166,   450,  1167,    -1,  1167,    -1,  1168,
     169,  1167,    -1,  1168,    -1,   463,  1169,    -1,   458,  1169,
      -1,  1169,    -1,   462,  1165,   448,    -1,  1199,    -1,   251,
      -1,   251,  1309,   504,    -1,   253,    -1,   253,  1309,   504,
      -1,   322,    -1,   322,  1309,   504,    -1,  1172,    -1,  1171,
    1172,    -1,  1194,  1245,    -1,  1217,    -1,  1217,    -1,  1176,
      -1,  1175,  1176,    -1,   504,    -1,   504,    -1,  1179,    -1,
    1178,  1179,    -1,   271,    -1,    -1,  1180,  1181,    -1,  1182,
      -1,  1217,    -1,  1183,    -1,  1183,  1309,  1183,    -1,   256,
      -1,  1185,    -1,  1184,  1185,    -1,  1217,    -1,   504,    -1,
    1188,    -1,  1187,  1188,    -1,   504,    -1,   504,    -1,  1185,
      -1,   256,    -1,   504,    -1,   504,    -1,  1194,    -1,  1193,
    1194,    -1,  1215,    -1,  1225,    -1,     6,  1281,  1214,    -1,
    1196,    -1,  1195,  1196,    -1,  1213,    -1,  1224,    -1,  1227,
      -1,  1170,    -1,   245,  1214,    -1,   245,  1225,    -1,   245,
    1227,    -1,     6,  1281,  1200,  1201,    -1,     6,  1281,  1214,
      -1,   271,    -1,  1199,    -1,  1197,  1199,    -1,  1213,    -1,
    1225,    -1,  1227,    -1,  1213,    -1,  1225,    -1,  1227,    -1,
    1170,    -1,   245,  1214,    -1,   245,  1225,    -1,   245,  1227,
      -1,   340,    -1,   152,    -1,  1214,    -1,   256,    -1,  1213,
      -1,  1225,    -1,  1213,    -1,  1224,    -1,  1213,    -1,   256,
      -1,  1213,    -1,   256,    -1,  1227,    -1,  1210,    -1,  1220,
      -1,   510,    -1,  1210,    -1,  1222,    -1,  1210,    -1,  1220,
      -1,  1213,    -1,  1224,    -1,  1227,    -1,  1212,    -1,  1212,
      -1,  1217,    -1,  1217,  1218,    -1,  1214,    -1,  1217,  1218,
    1219,    -1,  1217,  1218,    -1,  1217,  1219,    -1,  1217,    -1,
    1216,    -1,  1217,  1218,  1219,    -1,  1217,  1218,    -1,  1217,
    1219,    -1,  1217,    -1,   504,    -1,   504,  1309,  1217,    -1,
     462,  1163,   448,    -1,   462,  1165,   449,   448,    -1,   462,
    1165,   449,  1165,   448,    -1,   256,    -1,   256,    -1,   256,
      -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,
      -1,   266,    -1,   460,    -1,  1225,    -1,     9,  1226,    -1,
    1226,    -1,  1225,   447,  1226,    -1,   256,    -1,   416,    -1,
     510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,    -1,
    1228,  1231,    -1,  1229,   462,  1198,   448,  1231,    -1,  1230,
     462,  1163,   448,  1231,    -1,   470,   462,  1233,   448,  1231,
      -1,   303,   462,  1234,   448,    -1,   258,   462,  1235,   448,
    1231,    -1,   259,   462,  1235,   448,  1231,    -1,   260,   462,
    1235,   448,  1231,    -1,   201,  1232,    -1,   495,  1232,    -1,
      99,    -1,   502,    -1,   490,    -1,   264,    -1,   377,    -1,
      82,    -1,   428,    -1,   429,    -1,    -1,   462,  1165,   449,
     448,    -1,   462,  1165,   449,  1165,   448,    -1,    -1,   462,
    1163,   448,    -1,   462,   448,    -1,  1198,    -1,  1198,  1164,
     241,    -1,  1198,  1164,   468,    -1,  1198,    -1,  1198,  1164,
    1198,    -1,  1165,    -1,  1165,  1164,  1185,    -1,    -1,    -1,
       9,    -1,    -1,  1318,    -1,    -1,   223,    -1,    -1,   223,
    1241,    -1,    -1,   446,  1203,    -1,    -1,   285,    -1,   334,
      -1,    -1,   290,    -1,    -1,   312,    -1,   290,   312,    -1,
      -1,   386,  1246,    -1,    -1,   272,  1271,  1247,    -1,    34,
      -1,   281,    -1,   282,    -1,   283,    -1,   344,    -1,   466,
      -1,   467,    -1,   471,    -1,    -1,   400,  1258,    -1,   451,
      -1,     3,    -1,     5,    -1,    10,    -1,    18,    -1,    51,
      -1,    52,    -1,    60,    -1,    71,    -1,    74,    -1,    88,
      -1,   111,    -1,   119,    -1,   121,    -1,   128,    -1,   152,
      -1,   163,    -1,   168,    -1,   195,    -1,   202,    -1,   205,
      -1,   206,    -1,   215,    -1,   222,    -1,   224,    -1,   227,
      -1,   269,    -1,   273,    -1,   275,    -1,   285,    -1,   311,
      -1,   324,    -1,   349,    -1,   360,    -1,   375,    -1,   381,
      -1,   385,    -1,   393,    -1,   403,    -1,   412,    -1,   421,
      -1,   426,    -1,   427,    -1,   430,    -1,   432,    -1,   438,
      -1,   469,    -1,   475,    -1,   480,    -1,   507,    -1,   130,
      -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   139,    -1,   140,    -1,   141,
      -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,   147,
      -1,   148,    -1,   149,    -1,   150,    -1,   151,    -1,    -1,
       7,    -1,    -1,     8,    -1,    -1,    22,    -1,    -1,    23,
      -1,    -1,    26,    -1,    -1,    30,    -1,    -1,    39,    -1,
      -1,    49,    -1,    -1,    56,    -1,    -1,    57,    -1,    -1,
      86,    -1,    -1,   102,    -1,    -1,   454,    -1,    -1,   176,
      -1,    -1,   188,    -1,    -1,   196,    -1,    -1,   218,    -1,
      -1,   314,    -1,   218,   314,    -1,    -1,   221,    -1,    -1,
     456,    -1,    -1,   228,    -1,    -1,   232,    -1,    -1,   232,
      -1,    22,    -1,    -1,   237,    -1,    -1,   242,    -1,   384,
      -1,    -1,   252,    -1,   254,    -1,    -1,   248,  1271,    -1,
     249,  1252,    -1,    -1,   254,    -1,    -1,   272,    -1,    -1,
     299,    -1,    -1,   299,    -1,   300,    -1,    -1,   306,    -1,
      -1,   309,    -1,    -1,   423,   232,    -1,   423,    -1,   232,
      -1,    -1,   316,    -1,    -1,   337,    -1,    -1,   340,    -1,
      -1,   351,    -1,    -1,   384,    -1,    -1,   405,    -1,    -1,
     406,    -1,    -1,   405,    -1,   405,   232,    -1,    -1,   410,
      -1,    -1,   418,    -1,    -1,   423,    -1,    -1,   437,    -1,
      -1,   441,    -1,    -1,   445,    -1,    -1,   446,    -1,    -1,
     446,    -1,   497,    -1,    -1,   501,    -1,    -1,   501,   403,
     446,    -1,    -1,   503,    -1,    63,   401,    -1,   401,    -1,
      66,    -1,    64,    -1,    67,    -1,    65,    -1,   452,    -1,
     159,    -1,   165,    -1,   161,    -1,   165,    -1,   461,    -1,
     218,    -1,   306,    -1,   418,    -1,   308,    -1,   252,    -1,
     254,    -1,   351,    -1,   353,    -1,    57,    -1,   505,    -1,
     351,  1271,    -1,   353,  1252,    -1,   356,    -1,   474,    -1,
     252,    -1,   254,    -1,   410,    -1,   244,    -1,   503,   124,
      -1,   124,    -1,   340,    63,   401,    -1,    63,   401,    -1,
     401,    -1,   116,    -1,   106,    -1,    89,   210,    -1,    54,
      -1,    89,   187,    -1,    53,    -1,   321,   210,    -1,   325,
      -1,   321,   187,    -1,   326,    -1,   366,   210,    -1,   383,
      -1,   366,   187,    -1,   382,    -1,    89,  1271,    -1,    90,
    1252,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1341,  1341,  1341,  1373,  1374,  1378,  1379,  1383,  1384,
    1388,  1388,  1411,  1418,  1425,  1431,  1432,  1433,  1437,  1438,
    1442,  1466,  1467,  1471,  1505,  1511,  1523,  1497,  1533,  1532,
    1570,  1605,  1606,  1610,  1611,  1614,  1615,  1619,  1628,  1637,
    1638,  1642,  1646,  1655,  1656,  1664,  1665,  1675,  1676,  1680,
    1681,  1682,  1683,  1684,  1691,  1690,  1703,  1704,  1707,  1708,
    1722,  1721,  1731,  1732,  1733,  1734,  1738,  1739,  1743,  1744,
    1745,  1746,  1750,  1757,  1764,  1771,  1782,  1786,  1790,  1794,
    1801,  1802,  1809,  1808,  1819,  1820,  1821,  1828,  1829,  1833,
    1837,  1849,  1853,  1854,  1859,  1862,  1869,  1874,  1885,  1898,
    1899,  1907,  1908,  1912,  1913,  1914,  1915,  1916,  1917,  1918,
    1919,  1920,  1921,  1922,  1923,  1931,  1930,  1949,  1959,  1972,
    1980,  1983,  1984,  1988,  1998,  2014,  2013,  2037,  2043,  2049,
    2055,  2061,  2067,  2077,  2081,  2088,  2092,  2097,  2096,  2107,
    2111,  2118,  2119,  2120,  2121,  2122,  2123,  2130,  2145,  2148,
    2155,  2163,  2167,  2178,  2198,  2206,  2217,  2218,  2224,  2245,
    2246,  2250,  2254,  2275,  2298,  2380,  2383,  2392,  2411,  2427,
    2445,  2463,  2480,  2496,  2497,  2504,  2505,  2513,  2514,  2524,
    2525,  2530,  2529,  2550,  2560,  2561,  2565,  2566,  2567,  2568,
    2569,  2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,  2584,
    2590,  2600,  2613,  2626,  2642,  2643,  2644,  2645,  2648,  2649,
    2655,  2656,  2660,  2664,  2665,  2670,  2673,  2674,  2681,  2689,
    2690,  2691,  2698,  2727,  2767,  2767,  2771,  2777,  2793,  2795,
    2810,  2821,  2828,  2830,  2831,  2837,  2837,  2844,  2849,  2854,
    2861,  2862,  2863,  2867,  2878,  2879,  2883,  2888,  2893,  2898,
    2909,  2920,  2930,  2941,  2952,  2959,  2960,  2966,  2973,  2974,
    2975,  2981,  2982,  2983,  2990,  2991,  2995,  2996,  3002,  3030,
    3031,  3032,  3033,  3040,  3039,  3055,  3056,  3060,  3063,  3064,
    3070,  3071,  3079,  3080,  3088,  3089,  3093,  3114,  3113,  3130,
    3137,  3141,  3147,  3148,  3152,  3162,  3177,  3178,  3179,  3180,
    3181,  3182,  3183,  3184,  3185,  3192,  3199,  3199,  3199,  3205,
    3225,  3259,  3290,  3291,  3298,  3299,  3303,  3304,  3311,  3322,
    3327,  3338,  3339,  3343,  3344,  3350,  3361,  3379,  3380,  3384,
    3385,  3386,  3390,  3397,  3404,  3413,  3425,  3477,  3492,  3493,
    3497,  3507,  3546,  3548,  3547,  3563,  3566,  3566,  3583,  3584,
    3586,  3590,  3592,  3591,  3626,  3639,  3647,  3652,  3658,  3667,
    3677,  3680,  3692,  3693,  3694,  3695,  3699,  3703,  3707,  3711,
    3715,  3719,  3723,  3727,  3731,  3735,  3739,  3743,  3747,  3758,
    3759,  3763,  3764,  3768,  3769,  3770,  3774,  3775,  3779,  3805,
    3809,  3818,  3822,  3831,  3832,  3833,  3834,  3835,  3836,  3837,
    3838,  3839,  3840,  3841,  3842,  3843,  3844,  3851,  3875,  3903,
    3906,  3915,  3940,  3951,  3952,  3956,  3960,  3964,  3968,  3972,
    3976,  3980,  3984,  3988,  3992,  3996,  4000,  4004,  4009,  4014,
    4018,  4022,  4030,  4034,  4038,  4046,  4050,  4054,  4058,  4062,
    4066,  4070,  4074,  4078,  4086,  4094,  4098,  4102,  4106,  4110,
    4114,  4122,  4123,  4127,  4128,  4134,  4140,  4152,  4170,  4171,
    4180,  4204,  4205,  4208,  4209,  4216,  4240,  4241,  4258,  4259,
    4262,  4263,  4270,  4271,  4276,  4287,  4298,  4309,  4320,  4349,
    4348,  4357,  4358,  4362,  4363,  4366,  4367,  4380,  4393,  4414,
    4423,  4437,  4439,  4438,  4458,  4460,  4459,  4475,  4477,  4476,
    4485,  4486,  4493,  4492,  4505,  4506,  4507,  4514,  4519,  4523,
    4524,  4530,  4537,  4541,  4542,  4548,  4585,  4589,  4594,  4600,
    4601,  4606,  4607,  4608,  4609,  4610,  4614,  4621,  4628,  4635,
    4642,  4648,  4649,  4654,  4653,  4660,  4661,  4665,  4666,  4667,
    4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,  4676,  4677,
    4678,  4679,  4680,  4684,  4691,  4692,  4693,  4694,  4695,  4696,
    4697,  4700,  4701,  4702,  4705,  4706,  4710,  4717,  4723,  4724,
    4728,  4729,  4733,  4740,  4744,  4751,  4752,  4756,  4763,  4764,
    4768,  4769,  4773,  4774,  4775,  4779,  4780,  4784,  4785,  4789,
    4796,  4803,  4811,  4813,  4812,  4833,  4834,  4838,  4839,  4844,
    4846,  4845,  4902,  4920,  4921,  4925,  4929,  4933,  4937,  4941,
    4945,  4949,  4953,  4957,  4961,  4965,  4969,  4973,  4977,  4981,
    4985,  4989,  4994,  4998,  5002,  5007,  5012,  5017,  5022,  5023,
    5024,  5025,  5026,  5027,  5028,  5029,  5030,  5037,  5042,  5051,
    5052,  5056,  5057,  5062,  5065,  5069,  5077,  5080,  5084,  5092,
    5103,  5111,  5113,  5123,  5112,  5150,  5150,  5183,  5187,  5186,
    5200,  5199,  5219,  5220,  5225,  5232,  5234,  5238,  5248,  5250,
    5258,  5266,  5274,  5303,  5334,  5336,  5346,  5351,  5378,  5380,
    5379,  5415,  5416,  5420,  5421,  5422,  5439,  5440,  5451,  5450,
    5500,  5501,  5505,  5553,  5566,  5569,  5588,  5593,  5587,  5606,
    5606,  5636,  5643,  5644,  5645,  5646,  5647,  5648,  5649,  5650,
    5651,  5652,  5653,  5654,  5655,  5656,  5657,  5658,  5659,  5660,
    5661,  5662,  5663,  5664,  5665,  5666,  5667,  5668,  5669,  5670,
    5671,  5672,  5673,  5674,  5675,  5676,  5677,  5678,  5679,  5680,
    5681,  5682,  5683,  5684,  5685,  5686,  5687,  5688,  5689,  5690,
    5691,  5692,  5706,  5718,  5717,  5726,  5732,  5736,  5740,  5745,
    5750,  5755,  5760,  5764,  5768,  5772,  5776,  5781,  5785,  5789,
    5793,  5797,  5801,  5805,  5812,  5813,  5820,  5821,  5825,  5826,
    5830,  5831,  5832,  5833,  5834,  5838,  5842,  5843,  5846,  5847,
    5850,  5851,  5857,  5858,  5862,  5863,  5867,  5871,  5875,  5879,
    5883,  5887,  5891,  5895,  5899,  5903,  5907,  5911,  5915,  5919,
    5923,  5927,  5931,  5935,  5939,  5943,  5947,  5951,  5955,  5959,
    5966,  5970,  5981,  5980,  5989,  5993,  5997,  6003,  6004,  6011,
    6015,  6026,  6025,  6034,  6038,  6050,  6051,  6059,  6058,  6067,
    6068,  6072,  6078,  6078,  6085,  6084,  6094,  6114,  6118,  6123,
    6128,  6149,  6153,  6152,  6169,  6170,  6175,  6183,  6207,  6209,
    6213,  6222,  6235,  6238,  6242,  6246,  6269,  6270,  6274,  6275,
    6280,  6283,  6291,  6295,  6303,  6307,  6318,  6317,  6325,  6329,
    6340,  6339,  6347,  6352,  6360,  6361,  6362,  6363,  6364,  6372,
    6371,  6380,  6387,  6391,  6401,  6412,  6430,  6429,  6438,  6442,
    6446,  6451,  6459,  6463,  6474,  6473,  6483,  6487,  6491,  6495,
    6499,  6503,  6504,  6513,  6515,  6514,  6522,  6531,  6538,  6542,
    6546,  6550,  6560,  6562,  6566,  6567,  6570,  6572,  6579,  6580,
    6584,  6585,  6590,  6594,  6598,  6602,  6606,  6610,  6614,  6618,
    6622,  6626,  6630,  6634,  6638,  6642,  6646,  6650,  6657,  6661,
    6672,  6671,  6680,  6684,  6688,  6692,  6696,  6703,  6707,  6718,
    6717,  6725,  6745,  6744,  6768,  6776,  6777,  6782,  6793,  6804,
    6818,  6822,  6829,  6830,  6835,  6844,  6853,  6858,  6867,  6868,
    6873,  6935,  6936,  6937,  6941,  6942,  6946,  6950,  6961,  6960,
    6972,  6973,  6994,  7008,  7030,  7052,  7072,  7095,  7096,  7104,
    7103,  7111,  7122,  7121,  7131,  7138,  7137,  7150,  7159,  7163,
    7174,  7190,  7189,  7198,  7202,  7206,  7213,  7217,  7228,  7227,
    7235,  7243,  7244,  7248,  7249,  7250,  7255,  7258,  7265,  7269,
    7277,  7284,  7285,  7286,  7287,  7288,  7289,  7290,  7295,  7298,
    7308,  7307,  7316,  7322,  7334,  7333,  7342,  7346,  7350,  7354,
    7361,  7362,  7363,  7364,  7371,  7370,  7384,  7394,  7403,  7404,
    7408,  7409,  7410,  7411,  7412,  7413,  7417,  7418,  7422,  7427,
    7434,  7435,  7436,  7437,  7438,  7442,  7470,  7473,  7480,  7484,
    7494,  7493,  7506,  7505,  7513,  7517,  7528,  7527,  7536,  7540,
    7547,  7551,  7562,  7561,  7569,  7584,  7602,  7603,  7604,  7605,
    7609,  7610,  7615,  7616,  7617,  7623,  7624,  7625,  7626,  7638,
    7637,  7648,  7654,  7653,  7664,  7672,  7680,  7687,  7691,  7704,
    7711,  7723,  7726,  7731,  7735,  7746,  7753,  7754,  7758,  7759,
    7762,  7763,  7768,  7779,  7778,  7787,  7814,  7815,  7820,  7823,
    7827,  7831,  7835,  7839,  7843,  7850,  7851,  7855,  7856,  7860,
    7864,  7874,  7885,  7884,  7892,  7902,  7913,  7912,  7921,  7928,
    7932,  7943,  7942,  7954,  7963,  7966,  7970,  7977,  7981,  7991,
    8003,  8002,  8011,  8015,  8024,  8025,  8030,  8033,  8041,  8045,
    8052,  8060,  8064,  8075,  8074,  8088,  8089,  8090,  8091,  8092,
    8093,  8097,  8098,  8102,  8103,  8109,  8118,  8125,  8126,  8130,
    8134,  8138,  8142,  8146,  8150,  8154,  8158,  8167,  8171,  8180,
    8189,  8190,  8194,  8203,  8204,  8208,  8212,  8223,  8222,  8231,
    8230,  8261,  8264,  8284,  8285,  8288,  8289,  8297,  8298,  8303,
    8308,  8318,  8334,  8339,  8349,  8366,  8365,  8375,  8388,  8391,
    8399,  8402,  8407,  8412,  8420,  8421,  8422,  8423,  8424,  8425,
    8429,  8437,  8438,  8442,  8446,  8457,  8456,  8466,  8479,  8482,
    8486,  8494,  8506,  8509,  8516,  8517,  8518,  8519,  8526,  8525,
    8534,  8541,  8542,  8546,  8547,  8548,  8552,  8553,  8557,  8561,
    8572,  8571,  8580,  8584,  8588,  8595,  8599,  8609,  8620,  8621,
    8628,  8627,  8636,  8642,  8654,  8653,  8661,  8675,  8674,  8682,
    8695,  8697,  8698,  8706,  8705,  8714,  8722,  8723,  8728,  8729,
    8734,  8741,  8742,  8747,  8754,  8755,  8759,  8760,  8764,  8765,
    8769,  8773,  8784,  8783,  8792,  8793,  8794,  8795,  8796,  8800,
    8827,  8830,  8842,  8852,  8857,  8862,  8867,  8875,  8913,  8914,
    8918,  8958,  8968,  8991,  8992,  8993,  8994,  8998,  9007,  9013,
    9023,  9032,  9041,  9042,  9049,  9048,  9060,  9070,  9071,  9076,
    9079,  9083,  9087,  9094,  9095,  9099,  9100,  9104,  9108,  9120,
    9123,  9124,  9133,  9134,  9143,  9146,  9147,  9156,  9157,  9168,
    9171,  9172,  9181,  9182,  9194,  9197,  9199,  9209,  9210,  9222,
    9223,  9227,  9228,  9229,  9233,  9242,  9253,  9254,  9255,  9259,
    9268,  9279,  9284,  9285,  9294,  9295,  9306,  9310,  9320,  9327,
    9334,  9334,  9344,  9345,  9346,  9350,  9359,  9360,  9362,  9363,
    9364,  9365,  9366,  9368,  9369,  9370,  9371,  9372,  9373,  9375,
    9376,  9377,  9379,  9380,  9381,  9382,  9383,  9386,  9387,  9391,
    9392,  9396,  9397,  9401,  9402,  9406,  9410,  9416,  9420,  9426,
    9427,  9428,  9432,  9433,  9434,  9438,  9439,  9440,  9444,  9448,
    9452,  9453,  9454,  9457,  9458,  9468,  9480,  9489,  9501,  9510,
    9522,  9537,  9538,  9543,  9552,  9558,  9578,  9582,  9603,  9644,
    9658,  9659,  9664,  9670,  9671,  9676,  9688,  9689,  9690,  9697,
    9708,  9709,  9713,  9721,  9729,  9733,  9740,  9750,  9759,  9760,
    9766,  9780,  9797,  9801,  9808,  9809,  9810,  9817,  9821,  9828,
    9829,  9830,  9831,  9832,  9836,  9840,  9844,  9848,  9852,  9873,
    9877,  9884,  9885,  9886,  9890,  9891,  9892,  9893,  9894,  9898,
    9902,  9909,  9910,  9914,  9915,  9919,  9920,  9924,  9925,  9936,
    9937,  9941,  9942,  9943,  9947,  9948,  9949,  9956,  9957,  9961,
    9962,  9966,  9967,  9968,  9974,  9978,  9982,  9983,  9987,  9991,
    9998, 10005, 10012, 10022, 10029, 10039, 10049, 10059, 10072, 10076,
   10084, 10092, 10096, 10106, 10121, 10144, 10167, 10183, 10184, 10185,
   10186, 10187, 10188, 10192, 10196, 10213, 10217, 10224, 10225, 10226,
   10227, 10228, 10229, 10230, 10236, 10240, 10244, 10248, 10252, 10256,
   10260, 10264, 10268, 10272, 10279, 10280, 10284, 10285, 10286, 10290,
   10291, 10292, 10296, 10300, 10304, 10311, 10315, 10319, 10326, 10333,
   10340, 10350, 10357, 10367, 10374, 10386, 10394, 10395, 10399, 10400,
   10404, 10405, 10410, 10413, 10421, 10424, 10431, 10433, 10434, 10438,
   10439, 10443, 10444, 10445, 10450, 10453, 10466, 10470, 10478, 10482,
   10486, 10490, 10494, 10498, 10502, 10506, 10513, 10514, 10520, 10521,
   10522, 10523, 10524, 10525, 10526, 10527, 10528, 10529, 10530, 10531,
   10532, 10533, 10534, 10535, 10536, 10537, 10538, 10539, 10540, 10541,
   10542, 10543, 10544, 10545, 10546, 10547, 10548, 10549, 10550, 10551,
   10552, 10553, 10554, 10555, 10556, 10557, 10558, 10559, 10560, 10561,
   10562, 10563, 10564, 10565, 10566, 10567, 10568, 10569, 10570, 10571,
   10572, 10573, 10574, 10575, 10576, 10577, 10578, 10579, 10580, 10581,
   10582, 10583, 10584, 10585, 10586, 10587, 10588, 10589, 10596, 10596,
   10597, 10597, 10598, 10598, 10599, 10599, 10600, 10600, 10601, 10601,
   10602, 10602, 10603, 10603, 10604, 10604, 10605, 10605, 10606, 10606,
   10607, 10607, 10608, 10608, 10609, 10609, 10610, 10610, 10611, 10611,
   10612, 10612, 10613, 10613, 10613, 10614, 10614, 10615, 10615, 10616,
   10616, 10617, 10617, 10618, 10618, 10618, 10619, 10619, 10620, 10620,
   10620, 10621, 10621, 10621, 10622, 10622, 10622, 10623, 10623, 10624,
   10624, 10625, 10625, 10626, 10626, 10626, 10627, 10627, 10628, 10628,
   10629, 10629, 10629, 10629, 10630, 10630, 10631, 10631, 10632, 10632,
   10633, 10633, 10634, 10634, 10635, 10635, 10636, 10636, 10637, 10637,
   10637, 10638, 10638, 10639, 10639, 10640, 10640, 10641, 10641, 10642,
   10642, 10643, 10643, 10644, 10644, 10645, 10645, 10645, 10646, 10646,
   10647, 10647, 10648, 10648, 10652, 10652, 10653, 10653, 10654, 10654,
   10655, 10655, 10656, 10656, 10657, 10657, 10658, 10658, 10659, 10659,
   10660, 10660, 10661, 10661, 10662, 10662, 10663, 10663, 10664, 10664,
   10665, 10665, 10666, 10666, 10667, 10667, 10670, 10671, 10672, 10676,
   10676, 10677, 10677, 10678, 10678, 10679, 10679, 10680, 10680, 10681,
   10681, 10682, 10682, 10683, 10683
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
  "alternative_record_key_clause", "split_key_list", "$@14", "split_key",
  "suppress_clause", "collating_sequence_clause", "file_status_clause",
  "file_or_sort", "lock_mode_clause", "$@15", "lock_mode", "lock_with",
  "organization_clause", "organization", "padding_character_clause",
  "record_delimiter_clause", "record_key_clause", "relative_key_clause",
  "reserve_clause", "no_or_integer", "sharing_clause", "sharing_option",
  "opt_i_o_control", "i_o_control_list", "i_o_control_clause",
  "same_clause", "same_option", "multiple_file_tape_clause", "$@16",
  "multiple_file_list", "multiple_file", "multiple_file_position",
  "data_division_header", "file_section_header",
  "file_description_sequence", "file_description",
  "file_description_entry", "$@17", "file_type",
  "file_description_clause_sequence", "file_description_clause",
  "block_contains_clause", "_records_or_characters", "record_clause",
  "record_depending", "opt_from_integer", "opt_to_integer",
  "label_records_clause", "value_of_clause", "file_id", "valueof_name",
  "data_records_clause", "linage_clause", "linage_sequence",
  "linage_lines", "linage_footing", "linage_top", "linage_bottom",
  "recording_mode_clause", "code_set_clause", "report_clause",
  "report_keyword", "rep_name_list", "working_storage_section", "$@18",
  "record_description_list", "$@19", "record_description_list_2",
  "data_description", "$@20", "level_number", "entry_name", "const_name",
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
  "based_clause", "value_clause", "$@21", "value_item_list", "value_item",
  "false_is", "renames_clause", "any_length_clause",
  "local_storage_section", "$@22", "linkage_section", "$@23",
  "report_section", "$@24", "report_description_sequence",
  "report_description", "$@25", "report_description_options",
  "report_description_option", "control_clause", "control_field_list",
  "identifier_list", "page_limit_clause", "page_line_column",
  "page_heading_list", "page_detail", "heading_clause", "first_detail",
  "last_heading", "last_detail", "footing_clause",
  "report_group_description_list", "report_group_description_entry",
  "$@26", "report_group_options", "report_group_option", "type_clause",
  "type_option", "control_final", "or_page", "next_group_clause",
  "sum_clause_list", "reset_clause", "data_or_final",
  "present_when_condition", "varying_clause", "line_clause",
  "line_keyword_clause", "column_clause", "col_keyword_clause",
  "report_line_integer_list", "line_or_plus", "report_col_integer_list",
  "col_or_plus", "source_clause", "group_indicate_clause",
  "report_usage_clause", "screen_section", "$@27",
  "opt_screen_description_list", "screen_description_list",
  "screen_description", "$@28", "screen_options", "screen_option",
  "plus_plus", "minus_minus", "screen_line_plus_minus",
  "screen_col_plus_minus", "screen_occurs_clause", "global_screen_opt",
  "procedure_division", "$@29", "$@30", "$@31", "procedure_using_chaining",
  "$@32", "$@33", "procedure_param_list", "procedure_param",
  "procedure_type", "size_optional", "procedure_optional",
  "procedure_returning", "procedure_declaratives", "$@34",
  "procedure_list", "procedure", "section_header", "$@35",
  "opt_use_statement", "paragraph_header", "invalid_statement",
  "opt_segment", "statement_list", "@36", "@37", "statements", "$@38",
  "statement", "accept_statement", "$@39", "accept_body",
  "accp_identifier", "lines_or_number", "opt_at_line_column",
  "at_line_column", "line_number", "column_number", "opt_at_from",
  "opt_at_block", "opt_accp_attr", "accp_attrs", "accp_attr", "end_accept",
  "add_statement", "$@40", "add_body", "add_to", "end_add",
  "allocate_statement", "$@41", "allocate_body", "allocate_returning",
  "alter_statement", "$@42", "alter_body", "alter_entry", "_proceed_to",
  "call_statement", "$@43", "call_body", "mnemonic_conv", "call_using",
  "$@44", "call_param_list", "call_param", "call_type", "call_returning",
  "return_give", "null_or_omitted", "call_on_exception",
  "call_not_on_exception", "end_call", "cancel_statement", "$@45",
  "cancel_body", "close_statement", "$@46", "close_body", "close_option",
  "compute_statement", "$@47", "compute_body", "end_compute",
  "commit_statement", "continue_statement", "delete_statement", "$@48",
  "delete_body", "delete_file_list", "end_delete", "display_statement",
  "$@49", "display_body", "display_list", "$@50", "display_atom",
  "display_upon", "display_upon_crt", "crt_under", "with_clause",
  "with_no_adv_clause", "disp_attrs", "disp_attr", "end_display",
  "divide_statement", "$@51", "divide_body", "end_divide",
  "entry_statement", "$@52", "entry_body", "evaluate_statement", "$@53",
  "evaluate_body", "evaluate_subject_list", "evaluate_subject",
  "evaluate_condition_list", "evaluate_case_list", "evaluate_case",
  "evaluate_other", "evaluate_when_list", "evaluate_object_list",
  "evaluate_object", "opt_evaluate_thru_expr", "end_evaluate",
  "exit_statement", "$@54", "exit_body", "exit_program_returning",
  "free_statement", "$@55", "free_body", "generate_statement", "$@56",
  "generate_body", "goto_statement", "$@57", "go_body", "goto_depending",
  "goback_statement", "if_statement", "$@58", "if_else_statements",
  "end_if", "initialize_statement", "$@59", "initialize_body",
  "initialize_filler", "initialize_value", "initialize_replacing",
  "initialize_replacing_list", "initialize_replacing_item",
  "initialize_category", "initialize_default", "initiate_statement",
  "$@60", "initiate_body", "inspect_statement", "$@61", "inspect_body",
  "send_identifier", "inspect_list", "inspect_tallying", "$@62",
  "inspect_replacing", "inspect_converting", "tallying_list",
  "tallying_item", "replacing_list", "replacing_item", "rep_keyword",
  "replacing_region", "inspect_region", "inspect_before_after",
  "merge_statement", "$@63", "move_statement", "$@64", "move_body",
  "multiply_statement", "$@65", "multiply_body", "end_multiply",
  "open_statement", "$@66", "open_body", "open_mode", "open_sharing",
  "open_sharing_option", "open_option", "perform_statement", "$@67",
  "perform_body", "$@68", "end_perform", "term_or_dot",
  "perform_procedure", "perform_option", "perform_test", "cond_or_exit",
  "perform_varying_list", "perform_varying", "read_statement", "$@69",
  "read_body", "read_into", "with_lock", "read_key", "read_handler",
  "end_read", "ready_statement", "release_statement", "$@70",
  "release_body", "reset_statement", "return_statement", "$@71",
  "return_body", "end_return", "rewrite_statement", "$@72", "rewrite_body",
  "write_lock", "end_rewrite", "rollback_statement", "search_statement",
  "$@73", "search_body", "search_varying", "search_at_end", "search_whens",
  "search_when", "end_search", "set_statement", "$@74", "set_body",
  "on_or_off", "up_or_down", "set_environment", "set_attr",
  "set_attr_clause", "set_attr_one", "set_to", "set_up_down",
  "set_to_on_off_sequence", "set_to_on_off", "set_to_true_false_sequence",
  "set_to_true_false", "sort_statement", "$@75", "sort_body", "@76",
  "sort_key_list", "opt_key_list", "sort_duplicates", "sort_collating",
  "sort_input", "sort_output", "start_statement", "$@77", "start_body",
  "sizelen_clause", "start_key", "start_op", "disallowed_op",
  "not_equal_op", "end_start", "stop_statement", "$@78", "stop_returning",
  "_opt_status", "stop_literal", "string_statement", "$@79", "string_body",
  "string_item_list", "string_item", "opt_with_pointer", "end_string",
  "subtract_statement", "$@80", "subtract_body", "end_subtract",
  "suppress_statement", "_printing", "terminate_statement", "$@81",
  "terminate_body", "transform_statement", "$@82", "transform_body",
  "unlock_statement", "$@83", "unlock_body", "opt_record",
  "unstring_statement", "$@84", "unstring_body", "unstring_delimited",
  "unstring_delimited_list", "unstring_delimited_item", "unstring_into",
  "unstring_into_item", "unstring_into_delimiter", "unstring_into_count",
  "unstring_tallying", "end_unstring", "use_statement", "$@85",
  "use_phrase", "use_file_exception", "use_global",
  "use_file_exception_target", "use_debugging", "debugging_list",
  "debugging_target", "all_refs", "use_start_end", "program_start_end",
  "use_reporting", "use_exception", "use_ex_keyw", "write_statement",
  "$@86", "write_body", "from_option", "write_option", "before_or_after",
  "write_handler", "end_write", "on_accp_exception",
  "opt_on_accp_exception", "opt_not_on_accp_exception",
  "on_disp_exception", "opt_on_disp_exception",
  "opt_not_on_disp_exception", "on_size_error", "opt_on_size_error",
  "opt_not_on_size_error", "on_overflow", "opt_on_overflow",
  "opt_not_on_overflow", "return_at_end", "at_end", "at_end_clause",
  "not_at_end_clause", "at_eop", "at_eop_clause", "not_at_eop_clause",
  "invalid_key", "opt_invalid_key_sentence",
  "opt_not_invalid_key_sentence", "_opt_scroll_lines", "condition", "expr",
  "partial_expr", "$@87", "expr_tokens", "expr_token", "eq", "gt", "lt",
  "ge", "le", "exp_list", "e_sep", "exp", "exp_term", "exp_factor",
  "exp_unary", "exp_atom", "line_linage_page_counter", "arithmetic_x_list",
  "arithmetic_x", "record_name", "table_name", "file_name_list",
  "file_name", "report_name", "mnemonic_name_list", "mnemonic_name",
  "procedure_name_list", "procedure_name", "label", "integer_label",
  "reference_list", "reference", "single_reference", "opt_reference_list",
  "opt_reference", "relative_key_reference", "reference_or_literal",
  "undefined_word", "unique_word", "target_x_list", "target_x", "x_list",
  "x", "report_x_list", "expr_x", "arith_x", "prog_or_entry",
  "alnum_or_id", "simple_value", "simple_all_value", "id_or_lit",
  "id_or_lit_or_func", "num_id_or_lit", "positive_id_or_lit",
  "pos_num_id_or_lit", "from_parameter", "sub_identifier",
  "sort_identifier", "sub_identifier_1", "identifier", "identifier_1",
  "target_identifier", "target_identifier_1", "qualified_word", "subref",
  "refmod", "integer", "symbolic_integer", "report_integer", "class_value",
  "literal", "basic_literal", "basic_value", "function", "func_no_parm",
  "func_one_parm", "func_multi_parm", "func_refmod", "func_args",
  "trim_args", "numvalc_args", "locale_dt_args", "not_const_word",
  "flag_all", "flag_duplicates", "flag_initialized", "flag_initialized_to",
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
     618,   618,   619,   619,   621,   620,   620,   622,   623,   623,
     624,   625,   626,   626,   626,   628,   627,   629,   629,   629,
     630,   630,   630,   630,   631,   631,   632,   632,   632,   632,
     633,   634,   635,   636,   637,   638,   638,   639,   640,   640,
     640,   641,   641,   641,   642,   642,   643,   643,   644,   645,
     645,   645,   645,   647,   646,   648,   648,   649,   650,   650,
     651,   651,   652,   652,   653,   653,   654,   656,   655,   655,
     657,   657,   658,   658,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   660,   661,   661,   661,   662,
     662,   662,   663,   663,   664,   664,   665,   665,   666,   667,
     667,   668,   668,   669,   669,   670,   671,   672,   672,   673,
     673,   673,   674,   675,   676,   677,   678,   679,   680,   680,
     681,   681,   682,   683,   682,   684,   685,   684,   686,   686,
     686,   687,   688,   687,   687,   689,   690,   690,   690,   691,
     692,   692,   693,   693,   693,   693,   694,   694,   694,   694,
     694,   694,   694,   694,   694,   694,   694,   694,   694,   695,
     695,   696,   696,   697,   697,   697,   698,   698,   699,   700,
     700,   701,   701,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   703,   704,   705,
     705,   706,   707,   708,   708,   709,   709,   709,   709,   709,
     709,   709,   709,   709,   709,   709,   709,   709,   709,   709,
     709,   709,   709,   709,   709,   709,   709,   709,   709,   709,
     709,   709,   709,   709,   709,   709,   709,   709,   709,   709,
     709,   710,   710,   711,   711,   712,   712,   713,   714,   714,
     715,   716,   716,   717,   717,   718,   719,   719,   720,   720,
     721,   721,   722,   722,   723,   724,   725,   726,   727,   729,
     728,   730,   730,   731,   731,   732,   732,   733,   733,   734,
     734,   735,   736,   735,   737,   738,   737,   739,   740,   739,
     741,   741,   743,   742,   744,   744,   744,   745,   745,   745,
     745,   746,   747,   748,   748,   749,   750,   750,   750,   751,
     751,   752,   752,   752,   752,   752,   753,   754,   755,   756,
     757,   758,   758,   760,   759,   761,   761,   762,   762,   762,
     762,   762,   762,   762,   762,   762,   762,   762,   762,   762,
     762,   762,   762,   763,   764,   764,   764,   764,   764,   764,
     764,   765,   765,   765,   766,   766,   767,   768,   769,   769,
     770,   770,   771,   772,   773,   774,   774,   775,   776,   776,
     777,   777,   778,   778,   778,   779,   779,   780,   780,   781,
     782,   783,   784,   785,   784,   786,   786,   787,   787,   788,
     789,   788,   788,   790,   790,   791,   791,   791,   791,   791,
     791,   791,   791,   791,   791,   791,   791,   791,   791,   791,
     791,   791,   791,   791,   791,   791,   791,   791,   791,   791,
     791,   791,   791,   791,   791,   791,   791,   791,   791,   792,
     792,   793,   793,   794,   794,   794,   795,   795,   795,   796,
     797,   798,   799,   800,   798,   801,   798,   802,   803,   802,
     804,   802,   805,   805,   806,   807,   807,   807,   808,   808,
     808,   808,   808,   808,   809,   809,   810,   810,   811,   812,
     811,   813,   813,   814,   814,   814,   814,   814,   816,   815,
     817,   817,   818,   819,   820,   820,   822,   823,   821,   825,
     824,   824,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   828,   827,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   830,   830,   831,   831,   832,   832,
     833,   833,   833,   833,   833,   834,   835,   835,   836,   836,
     837,   837,   838,   838,   839,   839,   840,   840,   840,   840,
     840,   840,   840,   840,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   840,   840,   840,   840,   840,   840,   840,
     841,   841,   843,   842,   844,   844,   844,   845,   845,   846,
     846,   848,   847,   849,   849,   850,   850,   852,   851,   853,
     853,   854,   855,   855,   857,   856,   858,   859,   859,   859,
     859,   860,   861,   860,   862,   862,   863,   863,   864,   864,
     864,   864,   865,   865,   865,   865,   866,   866,   867,   867,
     868,   868,   869,   869,   870,   870,   872,   871,   873,   873,
     875,   874,   876,   876,   877,   877,   877,   877,   877,   879,
     878,   880,   881,   881,   882,   883,   885,   884,   886,   886,
     887,   887,   888,   888,   890,   889,   891,   891,   891,   891,
     891,   891,   891,   892,   893,   892,   894,   895,   895,   895,
     895,   895,   896,   896,   897,   897,   898,   898,   899,   899,
     900,   900,   901,   901,   901,   901,   901,   901,   901,   901,
     901,   901,   901,   901,   901,   901,   901,   901,   902,   902,
     904,   903,   905,   905,   905,   905,   905,   906,   906,   908,
     907,   909,   911,   910,   912,   913,   913,   914,   914,   914,
     915,   915,   916,   916,   917,   918,   919,   919,   920,   920,
     921,   921,   921,   921,   922,   922,   923,   923,   925,   924,
     926,   926,   926,   926,   926,   926,   926,   927,   927,   929,
     928,   930,   932,   931,   933,   935,   934,   936,   937,   937,
     938,   940,   939,   941,   941,   941,   942,   942,   944,   943,
     945,   946,   946,   947,   947,   947,   948,   948,   949,   949,
     950,   951,   951,   951,   951,   951,   951,   951,   952,   952,
     954,   953,   955,   955,   957,   956,   958,   959,   959,   959,
     960,   960,   960,   960,   962,   961,   963,   964,   965,   965,
     966,   966,   966,   966,   966,   966,   967,   967,   968,   968,
     969,   969,   969,   969,   969,   970,   971,   971,   972,   972,
     974,   973,   976,   975,   977,   977,   979,   978,   980,   980,
     981,   981,   983,   982,   984,   984,   985,   985,   985,   985,
     986,   986,   987,   987,   987,   988,   988,   988,   988,   990,
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
    1068,  1068,  1069,  1069,  1070,  1070,  1070,  1070,  1072,  1071,
    1073,  1074,  1074,  1075,  1075,  1075,  1076,  1076,  1077,  1077,
    1079,  1078,  1080,  1080,  1080,  1081,  1081,  1082,  1083,  1083,
    1085,  1084,  1086,  1086,  1088,  1087,  1089,  1091,  1090,  1092,
    1093,  1093,  1093,  1095,  1094,  1096,  1097,  1097,  1098,  1098,
    1099,  1100,  1100,  1101,  1102,  1102,  1103,  1103,  1104,  1104,
    1105,  1105,  1107,  1106,  1108,  1108,  1108,  1108,  1108,  1109,
    1110,  1110,  1111,  1111,  1111,  1111,  1111,  1112,  1113,  1113,
    1114,  1114,  1114,  1115,  1115,  1115,  1115,  1116,  1117,  1117,
    1118,  1119,  1120,  1120,  1122,  1121,  1123,  1124,  1124,  1125,
    1125,  1125,  1125,  1126,  1126,  1127,  1127,  1128,  1128,  1129,
    1130,  1130,  1131,  1131,  1132,  1133,  1133,  1134,  1134,  1135,
    1136,  1136,  1137,  1137,  1138,  1139,  1139,  1140,  1140,  1141,
    1141,  1142,  1142,  1142,  1143,  1144,  1145,  1145,  1145,  1146,
    1147,  1148,  1149,  1149,  1150,  1150,  1151,  1151,  1152,  1153,
    1155,  1154,  1156,  1156,  1156,  1157,  1157,  1157,  1157,  1157,
    1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,
    1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1158,
    1158,  1159,  1159,  1160,  1160,  1161,  1162,  1163,  1163,  1164,
    1164,  1164,  1165,  1165,  1165,  1166,  1166,  1166,  1167,  1167,
    1168,  1168,  1168,  1169,  1169,  1170,  1170,  1170,  1170,  1170,
    1170,  1171,  1171,  1172,  1173,  1174,  1175,  1175,  1176,  1177,
    1178,  1178,  1179,  1180,  1180,  1181,  1182,  1182,  1182,  1183,
    1184,  1184,  1185,  1186,  1187,  1187,  1188,  1189,  1190,  1190,
    1191,  1192,  1193,  1193,  1194,  1194,  1194,  1195,  1195,  1196,
    1196,  1196,  1196,  1196,  1196,  1196,  1196,  1196,  1196,  1197,
    1197,  1198,  1198,  1198,  1199,  1199,  1199,  1199,  1199,  1199,
    1199,  1200,  1200,  1201,  1201,  1202,  1202,  1203,  1203,  1204,
    1204,  1205,  1205,  1205,  1206,  1206,  1206,  1207,  1207,  1208,
    1208,  1209,  1209,  1209,  1210,  1211,  1212,  1212,  1213,  1214,
    1214,  1214,  1214,  1215,  1216,  1216,  1216,  1216,  1217,  1217,
    1218,  1219,  1219,  1220,  1221,  1222,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1224,  1224,  1225,  1225,  1226,  1226,  1226,
    1226,  1226,  1226,  1226,  1227,  1227,  1227,  1227,  1227,  1227,
    1227,  1227,  1227,  1227,  1228,  1228,  1229,  1229,  1229,  1230,
    1230,  1230,  1231,  1231,  1231,  1232,  1232,  1232,  1233,  1233,
    1233,  1234,  1234,  1235,  1235,  1236,  1237,  1237,  1238,  1238,
    1239,  1239,  1240,  1240,  1241,  1241,  1242,  1242,  1242,  1243,
    1243,  1244,  1244,  1244,  1245,  1245,  1246,  1246,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1248,  1248,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1250,  1250,
    1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,
    1256,  1256,  1257,  1257,  1258,  1258,  1259,  1259,  1260,  1260,
    1261,  1261,  1262,  1262,  1263,  1263,  1264,  1264,  1265,  1265,
    1266,  1266,  1267,  1267,  1267,  1268,  1268,  1269,  1269,  1270,
    1270,  1271,  1271,  1272,  1272,  1272,  1273,  1273,  1274,  1274,
    1274,  1275,  1275,  1275,  1276,  1276,  1276,  1277,  1277,  1278,
    1278,  1279,  1279,  1280,  1280,  1280,  1281,  1281,  1282,  1282,
    1283,  1283,  1283,  1283,  1284,  1284,  1285,  1285,  1286,  1286,
    1287,  1287,  1288,  1288,  1289,  1289,  1290,  1290,  1291,  1291,
    1291,  1292,  1292,  1293,  1293,  1294,  1294,  1295,  1295,  1296,
    1296,  1297,  1297,  1298,  1298,  1299,  1299,  1299,  1300,  1300,
    1301,  1301,  1302,  1302,  1303,  1303,  1304,  1304,  1305,  1305,
    1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,  1310,  1310,
    1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,  1315,  1315,
    1316,  1316,  1317,  1317,  1318,  1318,  1319,  1319,  1319,  1320,
    1320,  1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324,  1325,
    1325,  1326,  1326,  1327,  1327
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
       1,     1,     7,     9,     0,     2,     2,     1,     0,     4,
       3,     4,     0,     1,     1,     0,     5,     2,     2,     1,
       0,     4,     5,     2,     3,     1,     1,     3,     1,     2,
       4,     4,     4,     4,     3,     1,     1,     3,     2,     2,
       2,     0,     2,     3,     1,     2,     1,     1,     5,     0,
       1,     1,     1,     0,     6,     1,     2,     2,     0,     2,
       0,     3,     0,     3,     0,     2,     2,     0,     5,     3,
       1,     1,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     0,     1,     1,     4,
       6,     9,     0,     3,     0,     2,     0,     2,     3,     5,
       5,     1,     1,     1,     1,     3,     5,     0,     2,     1,
       1,     1,     4,     2,     2,     4,     3,     2,     2,     2,
       1,     2,     0,     0,     5,     0,     0,     2,     2,     3,
       2,     1,     0,     4,     3,     2,     0,     1,     1,     1,
       0,     2,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     0,
       2,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     6,     0,     2,
       7,     0,     2,     0,     3,     1,     0,     5,     1,     1,
       0,     3,     1,     2,     1,     2,     2,     3,     1,     0,
       5,     1,     2,     1,     3,     0,     4,     2,     4,     2,
       2,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     2,     0,     6,     0,     2,     2,     2,     3,     1,
       1,     2,     2,     1,     2,     4,     1,     4,     2,     0,
       2,     1,     1,     1,     1,     1,     3,     4,     4,     4,
       3,     0,     2,     0,     5,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     1,     2,     1,
       1,     0,     2,     2,     0,     2,     4,     4,     0,     3,
       1,     1,     3,     6,     2,     3,     2,     2,     3,     2,
       1,     2,     2,     1,     1,     1,     2,     2,     1,     4,
       2,     3,     0,     0,     5,     0,     1,     2,     3,     1,
       0,     4,     3,     0,     2,     2,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     5,     5,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     0,     1,     1,     0,     1,     1,     3,
       2,     0,     0,     0,     9,     0,     4,     0,     0,     3,
       0,     3,     1,     2,     4,     0,     2,     2,     0,     3,
       3,     4,     4,     3,     0,     1,     0,     2,     0,     0,
       7,     0,     2,     1,     1,     2,     1,     1,     0,     6,
       0,     2,     2,     1,     0,     1,     0,     0,     3,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     4,     6,     3,     3,     4,     3,
       4,     3,     3,     4,     4,     3,     4,     3,     4,     5,
       3,     4,     3,     3,     1,     1,     1,     2,     0,     1,
       3,     3,     2,     2,     2,     3,     3,     3,     0,     1,
       0,     3,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       0,     1,     0,     4,     4,     5,     6,     0,     2,     0,
       1,     0,     3,     3,     4,     0,     2,     0,     3,     1,
       2,     4,     0,     2,     0,     4,     6,     0,     1,     1,
       1,     0,     0,     3,     1,     2,     2,     3,     0,     2,
       2,     2,     0,     3,     2,     4,     1,     1,     1,     1,
       0,     2,     0,     2,     0,     1,     0,     3,     1,     2,
       0,     3,     2,     3,     0,     1,     3,     3,     2,     0,
       4,     4,     0,     1,     1,     1,     0,     4,     3,     2,
       1,     2,     0,     1,     0,     4,     3,     3,     3,     3,
       4,     2,     4,     1,     0,     3,     5,     0,     2,     2,
       2,     2,     0,     2,     1,     1,     0,     2,     0,     1,
       1,     2,     1,     2,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     0,     1,
       0,     4,     4,     6,     6,     8,     8,     0,     1,     0,
       3,     2,     0,     4,     2,     1,     3,     1,     1,     1,
       2,     1,     1,     2,     2,     3,     2,     3,     1,     3,
       2,     1,     1,     1,     0,     2,     0,     1,     0,     3,
       0,     2,     1,     2,     1,     1,     1,     0,     2,     0,
       3,     1,     0,     3,     1,     0,     3,     3,     0,     3,
       2,     0,     6,     3,     2,     1,     0,     1,     0,     3,
       5,     0,     2,     0,     3,     3,     0,     2,     1,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     2,     0,     3,     2,     1,     1,     1,
       2,     1,     1,     1,     0,     3,     2,     5,     1,     2,
       2,     2,     1,     1,     1,     2,     1,     2,     4,     2,
       0,     1,     1,     1,     1,     4,     0,     2,     3,     3,
       0,     3,     0,     3,     3,     4,     0,     4,     4,     6,
       0,     1,     0,     3,     4,     5,     1,     1,     1,     1,
       0,     3,     2,     2,     2,     0,     3,     2,     1,     0,
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
       4,     4,     0,     1,     1,     1,     1,     1,     0,     4,
       5,     1,     2,     1,     3,     3,     0,     4,     0,     1,
       0,     4,     4,     6,     6,     0,     1,     2,     0,     1,
       0,     3,     1,     2,     0,     3,     5,     0,     3,     2,
       0,     1,     1,     0,     4,     6,     0,     3,     1,     3,
       2,     2,     2,     3,     0,     3,     0,     3,     0,     3,
       0,     1,     0,     3,     1,     1,     1,     1,     1,     7,
       0,     1,     1,     1,     1,     1,     1,     4,     1,     2,
       1,     2,     3,     0,     1,     2,     1,     3,     1,     1,
       4,     1,     1,     1,     0,     4,     5,     0,     2,     0,
       4,     3,     3,     1,     1,     1,     1,     0,     1,     2,
       0,     2,     0,     2,     2,     0,     2,     0,     2,     2,
       0,     2,     0,     2,     2,     0,     2,     0,     2,     2,
       1,     2,     1,     1,     2,     2,     2,     1,     1,     2,
       2,     2,     0,     2,     0,     2,     0,     2,     1,     1,
       0,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       2,     2,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     2,     2,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     3,     1,
       1,     2,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     2,     2,     2,     4,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       2,     2,     1,     1,     3,     2,     2,     1,     1,     3,
       3,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     5,     5,     4,     5,
       5,     5,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     5,     0,     3,     2,     1,     3,
       3,     1,     3,     1,     3,     0,     0,     1,     0,     1,
       0,     1,     0,     2,     0,     2,     0,     1,     1,     0,
       1,     0,     1,     2,     0,     2,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     2,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     1,     0,     1,     0,     1,
       1,     0,     1,     1,     0,     2,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     1,     0,     1,     0,     1,
       0,     2,     1,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     0,     1,
       0,     3,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     2,     1,     1,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     2
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
    1771,    46,     0,     0,     0,  1814,  1771,  1771,  1771,     0,
       0,     0,     0,     0,  1771,     0,     0,  1746,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1772,     0,     0,  1500,   125,  1771,
    1771,  1815,  1771,     0,     0,     0,     0,  1771,  1771,    60,
      82,     0,    54,    98,  1747,     0,  1771,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1808,    39,  1771,     0,     0,     0,  1568,   169,  1492,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1501,
     150,   151,  1773,   154,  1573,  1192,  1191,   116,   120,  1800,
    1771,     0,   100,   149,   176,   177,    38,  1809,    36,     0,
    1580,  1576,  1581,  1579,  1577,  1582,  1578,   158,   159,   161,
     170,   165,  1856,  1857,     0,   163,     0,  1745,     0,     0,
       0,  1771,  1878,    80,    61,  1744,    66,    68,    69,    70,
      71,  1744,     0,  1771,     0,    83,     0,    87,    55,    58,
     152,  1775,  1774,   155,     0,  1800,  1803,  1802,     0,     0,
     117,   121,     0,     0,   261,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1843,   164,     0,  1569,   168,  1877,  1771,
       0,     0,    65,    67,    63,    81,  1744,  1771,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1574,
     153,   156,     0,  1801,   123,   118,   119,   122,   178,     0,
       0,  1642,     0,   273,   269,    24,     0,   264,   266,   267,
     134,   137,     0,   162,     0,     0,  1876,    74,    64,     0,
    1493,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1643,   181,  1752,   270,   271,   272,  1734,
     280,     0,   262,   265,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1753,  1827,  1735,  1756,
       0,   282,   263,   138,   139,  1864,  1865,    72,  1810,  1828,
    1748,  1757,     0,     0,     0,   284,     0,  1789,     0,  1835,
       0,   246,     0,  1771,  1744,  1776,   248,     0,  1845,  1842,
     234,   182,   233,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   245,   193,   194,   195,   196,   197,   198,
    1740,  1771,  1749,     0,  1478,   268,  1476,   281,     0,    25,
     140,  1790,  1771,  1776,  1836,  1837,   210,  1844,   249,  1810,
    1771,  1771,  1777,  1771,  1771,   255,  1734,   256,     0,  1771,
    1789,  1741,     0,     0,   274,   275,   278,  1477,   283,   290,
     291,   342,   285,   345,     0,     0,  1771,   212,   211,   208,
    1811,   248,   244,     0,     0,     0,     0,   254,  1804,  1804,
       0,   257,     0,  1771,   247,   230,   276,     0,   277,     0,
     491,   286,  1625,     0,   287,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1499,  1498,   250,   251,   252,  1497,   253,  1805,   258,   259,
     260,   231,     0,   279,     0,     0,   494,   347,     0,     0,
     351,     0,   289,   292,  1628,   216,   201,   217,   202,  1752,
     203,   200,   213,   199,   214,   240,   239,   240,   236,   343,
       0,     0,   497,   350,     0,   348,     0,   357,   358,   352,
       0,   355,  1771,  1875,   224,     0,   228,  1629,   209,     0,
     238,   237,   345,   492,     0,     0,   592,   349,   354,   391,
     360,  1748,  1771,     0,     0,  1771,  1748,  1789,  1771,  1732,
     288,     0,   293,   296,   297,   298,   299,   300,   301,   302,
     303,   304,     0,     0,  1628,     0,  1874,     0,   222,     0,
     243,   344,   345,   495,     0,     0,    26,  1771,  1736,     0,
       0,     0,  1771,  1732,     0,     0,     0,     0,     0,  1771,
     338,  1733,   339,     0,   337,   340,   294,   295,   226,   227,
     228,   225,     0,     0,   493,   345,   498,     0,   655,     0,
     478,   415,  1816,  1816,  1816,  1816,  1816,  1838,   416,   451,
     453,   419,   420,   421,   422,   423,   424,   447,   445,   446,
     448,   449,   454,   452,   425,  1812,   450,     0,   426,   412,
     427,   428,     0,     0,  1819,   430,   431,   429,  1778,   433,
     434,   432,  1771,  1773,   392,   393,   394,   395,   396,   397,
     413,   417,   418,   398,   399,   400,   401,   402,   403,   404,
     405,   406,     0,     0,  1737,     0,   388,     0,   361,   316,
     336,  1866,  1867,  1496,   325,  1494,  1859,  1858,   318,  1787,
    1746,  1760,     0,  1771,   322,   321,  1771,   341,   223,     0,
       0,  1862,  1863,   241,   496,   500,   593,     0,    27,   699,
     489,   490,  1817,   444,   443,   436,   435,   442,   441,   440,
     439,   438,   437,  1839,     0,  1813,   475,   461,   407,  1562,
     487,  1820,  1779,  1780,   476,     0,     0,   409,   411,  1656,
    1656,   390,     0,  1796,  1591,     0,     0,  1587,  1592,  1590,
    1588,  1593,  1589,   389,   362,  1583,  1585,     0,   306,  1495,
    1788,   327,     0,   309,  1761,  1821,   335,     0,     0,   229,
    1535,  1558,  1536,   242,   499,   595,   657,     0,     0,   477,
       0,  1831,     0,  1560,  1561,     0,   414,   479,   481,   483,
       0,   408,  1744,   455,   456,  1584,  1797,     0,     0,   371,
     367,   370,   369,   368,   383,   379,   381,   382,   384,   380,
     385,   386,   387,   364,   375,   376,   377,   372,   373,   374,
     366,   363,     0,   317,   308,   307,   305,   326,  1746,  1822,
     314,   323,   320,   324,   319,     0,   501,     0,   599,   594,
     596,     0,   660,   658,   676,     0,   753,   822,   831,   837,
     844,   876,   880,   894,   889,   895,   896,   904,   950,   959,
     962,   988,   999,  1002,  1005,   997,  1011,  1018,  1040,  1044,
    1080,  1082,  1086,     0,  1092,  1109,  1133,  1151,  1152,  1155,
    1156,  1161,  1169,  1170,  1183,  1217,  1235,     0,  1268,  1280,
    1288,  1290,   681,  1294,  1297,  1303,  1354,   701,   702,   703,
     704,   705,   706,   707,   708,   710,   709,   711,   712,   713,
     714,   715,   716,   717,   718,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   700,   462,  1832,
     463,  1609,  1604,  1615,     0,  1465,  1467,     0,     0,     0,
    1607,     0,  1469,  1608,  1610,  1611,     0,     0,     0,     0,
    1606,  1615,  1605,  1449,  1447,  1454,  1457,  1459,  1462,  1527,
    1464,  1524,  1525,  1526,  1612,     0,     0,     0,  1559,   488,
     485,   482,     0,   410,  1657,   365,   378,  1586,     0,     0,
     328,   329,   330,   331,     0,   310,  1759,   316,     0,  1479,
     502,     0,   600,     0,   597,   665,   665,     0,     0,  1659,
    1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,
    1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1658,  1704,  1705,  1706,  1707,   752,
       0,     0,     0,     0,   847,     0,     0,     0,     0,     0,
       0,     0,  1410,   990,     0,     0,  1833,   867,   866,     0,
    1010,  1410,     0,     0,     0,     0,     0,     0,   751,     0,
    1121,     0,     0,     0,     0,     0,     0,     0,     0,  1264,
    1267,  1255,  1265,  1266,  1257,     0,     0,  1289,  1287,     0,
     699,     0,     0,     0,     0,  1798,   466,     0,  1602,  1528,
    1529,  1530,     0,     0,     0,     0,     0,     0,     0,  1461,
       0,  1460,     0,  1603,  1450,  1451,  1570,     0,     0,     0,
       0,     0,     0,     0,     0,  1594,     0,     0,     0,     0,
     480,     0,   484,   334,   333,  1738,  1746,   315,     0,   602,
     603,   598,  1743,   665,   662,   668,     0,   665,   677,   652,
     775,   820,   778,   774,  1796,     0,     0,  1518,   829,  1512,
     827,  1507,  1509,  1510,  1511,   832,     0,  1630,  1489,   838,
     839,     0,  1485,  1487,  1486,   850,   848,   849,   874,     0,
    1540,   877,   878,  1539,   881,   884,  1796,   892,     0,  1471,
    1644,  1504,  1563,  1567,  1505,     0,   902,  1810,  1587,   948,
    1375,   913,   917,  1507,     0,  1509,   957,     0,   851,   960,
     969,   968,   986,     0,   965,   967,  1409,     0,   992,   996,
     994,   997,   995,   989,  1000,  1001,  1502,  1003,  1004,  1834,
    1006,  1483,   998,  1829,  1408,  1019,  1021,  1041,  1042,  1045,
       0,  1047,  1048,  1049,  1081,  1221,  1555,  1556,     0,  1083,
       0,  1090,     0,  1099,  1096,  1098,  1097,  1093,  1100,  1123,
    1489,  1110,  1121,  1112,     0,  1119,     0,  1541,  1486,  1543,
       0,  1149,  1636,  1153,  1357,  1474,  1159,  1810,  1167,  1357,
       0,  1181,  1174,  1475,     0,  1482,  1184,  1185,  1186,  1187,
    1188,  1189,  1210,  1190,  1213,     0,  1480,     0,     0,  1554,
    1567,  1218,  1253,  1240,  1258,  1742,  1278,     0,  1271,  1273,
       0,  1285,     0,  1291,  1292,   687,   693,   682,   683,   684,
     686,     0,  1295,     0,  1298,  1300,  1320,  1306,  1367,  1357,
    1799,     0,   470,   465,  1617,  1449,  1447,  1466,  1468,  1449,
       0,     0,     0,  1449,  1521,  1522,  1523,     0,  1470,  1463,
    1449,     0,  1448,  1571,     0,  1453,  1452,  1456,  1455,  1458,
       0,     0,  1449,     0,  1771,  1739,     0,   312,     0,  1771,
    1818,   663,  1771,     0,   674,   666,   667,   678,   821,   754,
    1739,   788,   779,     0,     0,     0,     0,  1513,  1514,  1515,
     830,   823,     0,     0,  1508,  1632,  1631,   835,   840,   842,
       0,   875,   845,  1542,   851,   879,   884,  1868,  1869,   882,
       0,   885,     0,   893,   890,  1851,  1850,  1472,     0,  1646,
    1473,  1565,  1566,   899,   900,   903,   897,  1402,   949,   905,
     696,     0,   911,  1377,     0,   928,     0,   922,  1375,  1375,
    1375,  1375,   958,   951,     0,     0,   852,   961,   987,   963,
    1410,  1410,   964,   971,   972,   696,  1434,  1435,  1436,  1430,
    1833,  1422,  1442,  1445,  1444,  1446,  1438,  1429,  1428,  1433,
    1432,  1431,  1437,  1417,  1421,  1439,  1441,  1443,  1419,  1420,
    1416,  1418,  1411,  1412,  1423,  1424,  1425,  1426,  1427,  1415,
     993,   991,  1503,  1008,  1830,   696,  1023,     0,  1043,     0,
    1070,  1054,  1046,  1051,  1052,  1053,  1225,     0,  1557,     0,
       0,  1091,  1087,     0,  1100,  1842,     0,  1111,  1117,  1118,
     696,  1114,  1410,     0,     0,  1122,     0,  1150,  1134,  1637,
    1638,  1810,     0,  1154,  1160,  1157,  1136,  1168,  1162,  1164,
    1176,  1182,  1171,     0,  1176,     0,  1211,  1214,     0,     0,
    1481,  1194,     0,  1193,     0,     0,  1565,  1254,  1236,  1242,
    1771,  1243,  1238,     0,  1256,     0,     0,  1279,  1269,     0,
    1272,     0,  1286,  1281,     0,  1293,   694,   692,   685,     0,
    1301,  1302,  1299,  1321,  1304,  1742,     0,  1368,  1355,  1359,
     464,  1742,   460,   468,   469,  1776,  1616,     0,  1612,  1612,
    1612,     0,  1598,     0,  1612,  1572,     0,  1612,  1612,  1841,
       0,   332,  1798,   311,   506,  1771,  1771,  1732,  1784,   531,
     505,   509,   510,     0,  1754,   617,  1771,   607,  1838,   608,
    1847,  1846,     0,  1771,     0,   620,   611,   616,  1791,   612,
       0,   615,   622,   619,   613,   618,     0,   623,   614,     0,
     634,   628,   632,   631,   629,   633,   604,   635,   630,     0,
    1791,     0,  1771,   675,     0,     0,   653,   784,   789,   790,
    1791,  1791,   782,   783,  1791,   770,  1370,  1849,  1848,   767,
     759,   761,   762,     0,  1370,     0,     0,     0,   776,   765,
       0,   773,   756,   772,   757,  1532,  1531,     0,  1517,     0,
    1796,  1380,   828,  1567,  1505,     0,  1634,   835,     0,   833,
       0,     0,  1488,   862,   883,   888,     0,     0,  1506,  1380,
    1771,  1645,  1564,   901,   696,   898,  1404,  1376,   697,   915,
    1738,   696,  1374,   921,   920,   919,   918,   929,  1375,  1771,
     932,     0,   935,   936,     0,  1771,   939,   940,   941,   942,
       0,   943,  1375,   930,     0,   790,   908,   909,   906,   907,
       0,  1380,     0,   858,   966,   981,   983,   982,   976,   978,
     984,  1410,   973,   970,  1410,   974,  1440,  1413,  1414,  1798,
    1007,  1484,   696,  1015,  1016,  1833,  1031,  1032,  1034,  1036,
    1037,  1033,  1035,  1026,  1833,  1022,     0,  1071,     0,  1073,
    1072,  1074,  1056,  1066,     0,     0,  1050,  1227,     0,  1762,
       0,  1084,  1380,     0,     0,     0,  1105,  1115,  1128,  1124,
    1129,  1125,  1130,     0,  1120,  1364,  1363,  1127,  1136,  1358,
    1551,  1552,  1553,     0,     0,  1402,     0,   696,     0,  1175,
       0,     0,     0,  1212,     0,  1216,  1215,  1208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1196,  1197,  1639,
    1402,     0,  1259,  1825,  1825,  1274,  1275,  1276,     0,  1380,
       0,     0,   695,     0,  1626,     0,  1276,  1164,  1728,     0,
    1771,  1624,  1599,  1600,  1601,  1622,  1619,  1620,  1597,  1613,
       0,  1595,  1596,   486,     0,     0,  1893,  1894,  1771,  1732,
       0,   503,   507,  1755,   511,     0,     0,   605,   606,   609,
     610,     0,   637,  1792,  1771,  1831,  1771,   638,   636,   650,
    1771,   669,   670,   673,     0,   664,   679,   681,  1771,   792,
       0,     0,   780,   781,     0,   696,   771,  1372,   758,   760,
    1370,   768,   763,   764,   777,   766,  1534,  1516,  1533,  1644,
       0,   696,   824,  1382,  1565,  1566,  1380,     0,  1633,   834,
     836,   843,   841,   870,  1769,   887,   886,   891,     0,  1403,
     696,  1401,   699,  1378,   910,     0,   933,   934,   937,   938,
       0,  1406,  1406,   931,   912,   924,   925,   923,   926,     0,
     952,     0,   853,   854,   668,     0,  1410,  1410,   980,   696,
     977,     0,  1014,   696,  1017,  1012,     0,     0,  1038,     0,
       0,     0,  1067,  1069,     0,  1062,  1076,  1063,  1064,  1055,
    1058,  1076,  1219,  1771,  1776,     0,  1763,  1226,  1085,  1088,
       0,  1105,  1804,  1804,     0,  1101,  1108,  1094,     0,  1116,
    1113,     0,     0,  1138,  1137,   696,  1158,  1390,  1163,  1165,
       0,  1177,  1410,  1410,  1172,  1178,  1195,  1207,  1209,  1199,
    1200,  1201,  1205,  1202,  1206,  1203,  1204,  1198,  1640,  1252,
       0,  1249,  1250,  1244,     0,  1237,  1873,  1872,     0,  1826,
    1262,  1262,  1385,     0,  1644,  1282,     0,   688,     0,  1627,
    1307,  1308,     0,  1311,  1314,  1318,  1312,  1402,  1729,     0,
     474,   471,   472,     0,  1614,   313,   508,  1785,  1786,  1575,
     519,   516,   356,   532,   512,   513,  1546,   627,  1544,  1545,
     626,   643,   649,     0,   646,   671,   672,   681,   699,     0,
       0,  1370,   785,   787,   786,  1371,   696,  1369,   769,  1380,
    1506,  1381,   696,  1379,  1564,   825,  1635,  1537,  1538,  1854,
    1855,   872,   696,  1796,  1770,   869,   868,   864,     0,  1648,
    1649,  1650,  1651,  1652,  1653,  1654,  1655,  1647,  1405,     0,
     945,   944,   947,     0,  1549,  1550,   946,     0,   916,  1380,
    1471,  1380,  1471,   855,   856,     0,   860,   859,   861,   979,
     985,   975,  1009,  1013,  1024,  1027,  1028,  1750,  1020,  1833,
    1025,  1076,  1076,     0,  1061,  1059,  1060,  1065,  1229,     0,
    1223,  1764,  1380,  1095,  1102,  1103,  1104,  1107,     0,  1131,
       0,     0,  1145,     0,  1394,   696,  1389,  1166,   696,   696,
    1179,  1251,  1241,  1245,  1246,  1247,  1248,  1239,  1260,  1263,
    1261,   696,  1270,  1387,  1771,  1380,  1380,   690,  1296,  1626,
    1310,  1760,  1316,  1760,  1385,   696,   696,  1356,  1366,  1397,
    1398,  1365,  1362,  1361,  1781,   473,   467,  1490,   515,  1860,
    1861,   518,   358,   533,   514,   641,   639,   642,   640,   644,
     645,     0,   621,   647,   648,     0,   699,   791,   796,  1771,
     797,   798,   799,  1771,   800,   801,   802,   803,   804,   805,
     806,   808,   809,   810,     0,   811,  1730,   812,   813,   814,
     793,   794,   755,  1373,   826,  1383,   696,   846,   871,     0,
     863,  1870,  1871,  1407,   927,   954,     0,   953,     0,   857,
    1029,  1751,     0,     0,  1057,  1068,  1076,  1767,  1767,  1077,
       0,     0,  1232,  1228,  1222,  1089,  1106,     0,  1139,  1771,
    1402,     0,     0,  1140,     0,  1144,  1395,  1173,  1180,  1386,
     696,  1384,     0,  1284,  1283,  1322,   689,     0,  1309,     0,
    1760,  1313,     0,  1305,  1399,  1400,  1396,  1782,  1783,  1360,
    1491,     0,  1771,  1771,     0,   520,   521,   522,   523,   524,
     525,     0,   535,   624,   625,     0,     0,     0,  1771,  1406,
    1406,  1731,     0,   795,   873,   865,  1380,  1380,     0,  1039,
    1075,  1768,     0,     0,  1771,  1230,     0,     0,  1220,  1224,
       0,     0,  1135,  1148,  1392,  1393,  1147,  1143,  1141,  1142,
    1388,  1277,  1330,   691,  1315,     0,  1319,  1880,  1879,  1771,
       0,     0,  1882,     0,  1771,  1771,   517,  1818,     0,   816,
     815,     0,   818,   817,   819,  1547,  1548,   956,   955,  1030,
    1079,  1078,     0,  1233,  1771,  1410,  1146,  1391,  1353,  1352,
    1331,  1323,  1324,  1730,  1325,  1326,  1327,  1328,  1351,     0,
       0,  1317,     0,   530,   526,  1881,     0,     0,  1765,  1793,
    1732,     0,     0,     0,  1771,  1796,   534,  1771,  1771,     0,
     540,   542,   551,   543,   545,   548,   536,   537,   538,   547,
     549,   552,   539,     0,   544,     0,   546,   550,   541,  1793,
    1732,   680,   807,  1231,     0,  1132,     0,  1823,     0,  1798,
     527,   529,   528,  1766,   590,  1794,  1795,  1773,   576,  1771,
     461,  1410,     0,     0,     0,     0,     0,   584,     0,   574,
     580,   583,     0,   577,   585,   588,  1773,   579,  1234,     0,
    1824,     0,  1349,  1348,  1347,     0,   575,     0,  1831,   572,
    1644,   568,  1519,  1884,     0,     0,  1886,  1888,     0,  1892,
    1890,   553,   557,   561,   561,   555,   559,   554,   560,   591,
       0,   582,   581,   587,   586,   578,  1350,  1853,  1852,  1806,
    1343,  1337,  1338,  1340,   566,   463,   589,  1798,   567,  1520,
    1883,  1887,  1885,  1891,  1889,   564,   556,   564,   558,     0,
    1807,  1798,  1346,  1341,  1344,     0,  1339,   458,     0,     0,
     563,   562,     0,     0,  1345,  1342,     0,   457,   571,   569,
     570,   565,   573,  1336,  1333,  1335,  1334,  1329,  1332,   459
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    30,
      12,    31,    44,    45,    34,    35,    19,   320,   431,   618,
      32,    50,    14,    25,    37,    95,   131,   132,    20,    29,
      41,    69,    70,   148,   208,   267,    71,   145,   194,   195,
     196,   197,   198,   199,   200,   331,   201,    72,   146,   205,
     206,   207,   262,   304,   263,    73,    74,    75,    76,    77,
     116,   157,   276,   158,    78,   133,   237,   238,   239,   324,
     343,   240,    79,   121,    80,   150,   151,   152,   270,    81,
     177,   178,    82,    83,   244,    84,    85,    86,    87,    88,
      89,    90,   123,   224,   165,   225,   335,   348,   373,   374,
     478,   479,   439,   513,   506,   375,   468,   376,   574,   575,
     608,   578,   377,   378,   379,   380,   381,   518,   540,   382,
     383,   384,   385,   386,   387,   388,   416,   389,   451,   285,
     286,   287,   288,   319,   289,   315,   424,   425,   458,   341,
     355,   399,   432,   433,   503,   434,   532,   562,   563,   836,
     564,  1673,  1017,   768,   565,   566,   706,   842,   567,   568,
     837,  1010,  1011,  1012,  1013,   569,   570,   571,   572,   604,
     460,   542,   461,   462,   497,   498,   549,   499,   529,   530,
     588,   763,   823,   824,   825,   826,   827,   500,   686,   587,
     664,   665,   666,   801,   667,   668,   669,   670,   671,   672,
     673,  2562,  2697,   674,   791,  1156,  1392,  1393,  1655,  1652,
    2161,  2162,   675,   676,   677,   678,   679,  1000,   797,   798,
    1190,   680,   681,   496,   582,   522,   615,   546,   715,   784,
     846,  1198,  1429,  1680,  1681,  1964,  2174,  1682,  2170,  2328,
    2445,  2446,  2447,  2448,  2449,  2450,  1961,  2173,  2452,  2507,
    2566,  2567,  2641,  2676,  2690,  2568,  2569,  2668,  2699,  2570,
    2571,  2572,  2573,  2574,  2575,  2609,  2610,  2613,  2614,  2576,
    2577,  2578,   586,   785,   849,   850,   851,  1200,  1430,  1716,
    2339,  2340,  2341,  2345,  1717,  1718,   718,  1437,  1987,   719,
     854,  1026,  1025,  1203,  1204,  1205,  1434,  1724,  1028,  1726,
    2187,  1150,  1377,  1378,  2307,  2426,  1379,  1380,  1931,  1787,
    1788,  2032,  1381,   788,   907,   908,  1100,  1211,  1212,  1752,
    1441,  1497,  1732,  1733,  1729,  1989,  2191,  2370,  2371,  1439,
     909,  1101,  1218,  1453,  1451,   910,  1102,  1225,  1769,   911,
    1103,  1229,  1230,  1771,   912,  1104,  1238,  1239,  1507,  1823,
    2052,  2053,  2054,  2023,  1119,  2217,  2211,  2377,  1462,   913,
    1105,  1241,   914,  1106,  1244,  1469,   915,  1107,  1247,  1474,
     916,   917,   918,  1108,  1256,  1483,  1486,   919,  1109,  1259,
    1260,  1491,  1261,  1495,  1815,  2047,  2238,  1798,  1812,  1813,
    1489,   920,  1110,  1266,  1503,   921,  1111,  1269,   922,  1112,
    1272,  1273,  1274,  1512,  1513,  1514,  1833,  1515,  1828,  1829,
    2058,  1509,   923,  1113,  1283,  1120,   924,  1114,  1284,   925,
    1115,  1287,   926,  1116,  1290,  1840,   927,   928,  1121,  1844,
    2065,   929,  1122,  1295,  1556,  1853,  2068,  2255,  2256,  2257,
    2258,   930,  1123,  1297,   931,  1124,  1299,  1300,  1562,  1563,
    1865,  1564,  1565,  2079,  2080,  1862,  1863,  1864,  2073,  2264,
    2399,   932,  1125,   933,  1126,  1309,   934,  1127,  1311,  1572,
     935,  1129,  1317,  1318,  1576,  2095,  2097,   936,  1130,  1321,
    1580,  2100,  1581,  1322,  1323,  1324,  1879,  1881,  1882,   937,
    1131,  1331,  1894,  2282,  2410,  2482,  1588,   938,   939,  1132,
    1333,   940,   941,  1133,  1336,  1595,   942,  1134,  1338,  1895,
    1598,   943,   944,  1135,  1341,  1604,  1898,  2114,  2115,  1602,
     945,  1136,  1346,   159,  1614,  1347,  1348,  1917,  1918,  1349,
    1350,  1351,  1352,  1353,  1354,   946,  1137,  1304,  2268,  1566,
    2404,  1867,  2082,  2402,  2478,   947,  1138,  1362,  1920,  1622,
    2130,  2131,  2132,  1618,   948,  1364,  1624,  2298,  1144,   949,
    1145,  1366,  1367,  1368,  2142,  1628,   950,  1146,  1371,  1633,
     951,  1148,   952,  1149,  1373,   953,  1151,  1382,   954,  1152,
    1384,  1642,   955,  1153,  1386,  1646,  2150,  2151,  1936,  2153,
    2312,  2431,  2314,  1644,  2427,  2492,  2531,  2532,  2533,  2707,
    2534,  2661,  2662,  2685,  2535,  2624,  2536,  2537,  2538,   956,
    1154,  1388,  1593,  1937,  1887,  2317,  1648,  1996,  1997,  2197,
    1492,  1493,  1792,  2012,  2013,  2203,  2302,  2303,  2421,  2106,
    2483,  2107,  2286,  2318,  2319,  2320,  1785,  1786,  2031,  2232,
    1293,  1294,  1276,  1277,  1542,  1543,  1544,  1545,  1546,  1547,
    1548,   983,  1177,  1396,   985,   986,   987,   988,  1219,  1248,
    1477,  1334,  1342,   395,   396,  1020,  1355,  1356,  1553,  1325,
    1232,  1233,  2326,   481,   301,   694,   695,   486,   482,    98,
     153,  1285,  1250,  1220,  1454,  2631,  1403,   990,  1757,  2007,
    2081,  2206,  1242,  1326,  2177,  2514,  2233,  1889,  2178,  1305,
    1359,  1222,   781,  1251,  1252,   739,   793,   794,  2179,   271,
    2611,   179,  1223,   765,   766,  1224,   994,   995,   996,  1185,
    1158,  1411,  1407,  1400,   501,  2152,   536,  1457,  1767,  2018,
    1591,  2134,   282,  1480,  1781,  2227,   803,  1099,  2159,  2462,
     602,   339,   687,  1443,   422,  1206,   202,   115,   393,  2392,
     337,  1965,   352,  1018,   775,  2087,  2594,  2472,  2218,    96,
     214,   413,   744,  2439,  1960,   771,   402,  1974,  2597,   807,
    1391,   218,   488,  2681,   168,   390,   736,   102,   724,   683,
     840,  2621,  2140,   350,  1555,   960,  1291,   406,   734,  1191,
    1330,   391,  1734,  1754,  1478,  2659,  2212,   184,   698,  2331,
     713,   347,   594,  1471,  2383,  2138,   537,   203,  2499,  2505,
    2644,  2645,  2646,  2647,  2648,  1684
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2171
static const yytype_int16 yypact[] =
{
   -2171,   266,   472, -2171,  -166,   277, -2171,   472, -2171, -2171,
     657, -2171, -2171,   657,   657,   566,   566, -2171,   837, -2171,
     946,   789,   995, -2171, -2171,  1110,  1110,   706,   835, -2171,
   -2171,   498,   657,   566, -2171, -2171,  1050,   819, -2171, -2171,
     868,  1410,   566, -2171, -2171, -2171,   789,   876, -2171, -2171,
     -70, -2171,   829,   829,   924,   956,  1121,  1121,  1121,   975,
     829,   970,   928,   966,  1121,   977,   998,  1403, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,  1276, -2171, -2171, -2171, -2171,
    1282, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
    1331,  1065,   498, -2171, -2171,  1078,    98, -2171, -2171,  1121,
    1121, -2171,  1121,  1028,  1469,  1028,  1105,  1121,  1121, -2171,
   -2171,  1028, -2171, -2171, -2171,  1055,  1049,  1119, -2171, -2171,
    1067, -2171,  1122, -2171, -2171, -2171, -2171,  -134, -2171, -2171,
   -2171,  1229, -2171,  1121,   913,  1028,  1319,     3, -2171, -2171,
   -2171, -2171, -2171,  1327,  1116,   884,  1387, -2171,  1096, -2171,
    1055, -2171,    75, -2171, -2171, -2171, -2171, -2171,   642,   -67,
    1121,     9, -2171, -2171, -2171,   -49, -2171, -2171, -2171,   943,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,   913, -2171,  1167,
   -2171,   341, -2171, -2171,  1028, -2171,  1211, -2171,  1215,  1207,
    1555,  1121, -2171, -2171, -2171,   864, -2171, -2171, -2171, -2171,
   -2171,   391,  1561,  1121,    56, -2171,    76, -2171, -2171,    18,
   -2171, -2171, -2171, -2171,  1366,   -67, -2171,  1389,   829,   829,
   -2171,   642,  1174,    94,   -86, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,   572, -2171,
      90, -2171,   913, -2171, -2171,  1299, -2171, -2171, -2171,  1121,
    1225,  1372, -2171, -2171, -2171, -2171,   929,  1121,  1125,  1404,
     449, -2171,  1609,   453,  1186, -2171, -2171,  1187,  1532, -2171,
    1366, -2171,   829, -2171, -2171, -2171, -2171,   642, -2171,  1189,
    1329, -2171,   829, -2171,   826, -2171,    73, -2171, -2171, -2171,
   -2171, -2171,   572, -2171,  1386,  1372, -2171, -2171, -2171,   625,
   -2171, -2171, -2171,  1388, -2171, -2171, -2171, -2171, -2171,  1371,
   -2171, -2171, -2171, -2171, -2171,  1191, -2171, -2171, -2171,  1624,
    1546,  1198, -2171, -2171,   572, -2171, -2171,    28, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1216, -2171,  1464,
    1533,  1203, -2171,  1642, -2171, -2171, -2171, -2171,  1666, -2171,
    1574, -2171,  1157,  1212,  1277, -2171,   572,  1401,  1323,   599,
    1275, -2171,  1280,  1121,  1622,   117,   -83,     4, -2171,  1180,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1256,
   -2171,  1422, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
    1647,  1121, -2171,  1157, -2171,  1157, -2171, -2171,  1236,   -53,
   -2171, -2171,  1121,  1451, -2171, -2171,   127, -2171, -2171,   885,
    1121,  1121, -2171,  1121,  1121, -2171,  1624, -2171,   316,  1121,
    1401, -2171,  1289,  1188,  1157, -2171,  1367, -2171, -2171, -2171,
   -2171,  1193, -2171,  1197,    57,   371,  1121, -2171, -2171,   863,
   -2171, -2171, -2171,  -106,  1278,  1028,  1199, -2171,  1390,  1390,
    1392, -2171,  1028,  1121, -2171, -2171, -2171,  1372, -2171,  1310,
    1444, -2171, -2171,  1259, -2171, -2171, -2171, -2171, -2171,  1028,
   -2171, -2171,   -66,   -66,  1705,   -66, -2171, -2171,   -66,   -40,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,   662, -2171,  1262,  1321,  1461,   395,  1271,  6323,
   -2171,  1219, -2171, -2171,   -20, -2171, -2171, -2171, -2171,  1191,
   -2171, -2171, -2171, -2171, -2171,  1221, -2171,  1221, -2171, -2171,
    1274,  1332,  1362, -2171,  1279, -2171,  1283, -2171,  1646, -2171,
    1648, -2171,  1195, -2171, -2171,  1608,  1303, -2171, -2171,   405,
   -2171, -2171,  1197, -2171,  1287,  1345,  1351, -2171, -2171, -2171,
    1031,  1574,  1121,   841,   841,  1121,    13,  1401,  1121,  1719,
   -2171,  1436, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,   829,   888,   112,  1028, -2171,  1244, -2171,  1437,
   -2171, -2171,  1197, -2171,  1297,  1355, -2171,  6631,   125,  1547,
    1372,  1246,  1121,  1719,  1248,   -99,  -106,  1372,  1261,  1121,
   -2171, -2171, -2171,   -15,   829, -2171, -2171, -2171, -2171, -2171,
    1303, -2171,  1744,   440, -2171,  1197, -2171,  1304,   673,    11,
   -2171, -2171,   300,   421,   428,   560,   607,  1253, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,  1374, -2171,  1372, -2171, -2171,
   -2171, -2171,  1028,  1028,  1530, -2171, -2171, -2171,   -43, -2171,
   -2171, -2171,  1121,   286, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,   964,   -78, -2171,  1266, -2171,   906, -2171,  1317,
   -2171, -2171, -2171, -2171,  1248, -2171, -2171, -2171, -2171,  1511,
      45,  1548,  1284,  1121, -2171, -2171,  1121, -2171, -2171,   743,
    1014, -2171, -2171, -2171, -2171, -2171, -2171,  1659, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171,  1272, -2171, -2171,  1337, -2171,  1324,
    1342, -2171, -2171, -2171, -2171,  6798,   637,  1761, -2171,  1391,
    1391, -2171,  1043,  1483, -2171,  1034,  1034, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,  1343, -2171,  1372,    66, -2171,
   -2171, -2171,  1372, -2171, -2171,  1382, -2171,   -22,   -22, -2171,
   -2171, -2171,  1343, -2171,  1445,  1291,    31,  2640,  3648, -2171,
    1372,  1352,  7313,  1334, -2171,  1028, -2171,   637, -2171,  1356,
    1543, -2171,  1622, -2171, -2171, -2171, -2171,  1034,  1350, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  1043, -2171, -2171, -2171, -2171,    36,  1403, -2171,
      26, -2171, -2171, -2171, -2171,  1301, -2171,  6141, -2171, -2171,
    1291,  1357, -2171, -2171,  1427,  4045, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,   423, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  1407, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,   -52, -2171, -2171,
    1466, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
    1693, -2171, -2171,  1347,  3011,     3,     3,  1348,  1349,  1353,
   -2171,  1354,     3, -2171, -2171, -2171,  7329,  7313,  7329,  1358,
   -2171,  1347, -2171,   140,  1006,   817, -2171,  1643, -2171, -2171,
   -2171, -2171,  1343, -2171,  1359,  1360,  1361,  7313, -2171, -2171,
     188, -2171,   637, -2171, -2171, -2171, -2171, -2171,  -106,  -106,
   -2171, -2171, -2171, -2171,  1627, -2171, -2171,  1317,  1372, -2171,
   -2171,  1373, -2171,  1377, -2171,    85,    85,  1313,  1378, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
    -188,  4620,  7313,    -9,   456,    -2,  1157,   679,   583,  5535,
    5644,  1562,   597,   539,   679,  1028,  1384, -2171, -2171,  5644,
   -2171, -2171,   679,  1301,  1827,  1028,  4717,  5644, -2171,   751,
    4040,  1157,  1028,  1157,  1028,    71,   361,  1028,  1157, -2171,
   -2171, -2171, -2171, -2171, -2171,  4825,  4922, -2171, -2171,  1301,
      93,  1028,  1157,  1028,  1028,  1522, -2171,  6936, -2171, -2171,
    1343, -2171,  1335,  1336,  7313,  7313,  7313,  3011,  1340, -2171,
     952, -2171,  3011, -2171, -2171, -2171, -2171,  7313,  7058,  7313,
    7313,  7313,  7313,  7313,  7313, -2171,  3011,  7313,  1006,  1431,
   -2171,  1385, -2171, -2171, -2171,  1805,  1403, -2171,   154, -2171,
   -2171, -2171, -2171,   130, -2171,  -196,   354,   133, -2171, -2171,
   -2171,  1711,   717,  1649,  1483,  1028,  3011, -2171,  1715, -2171,
    5022, -2171, -2171, -2171, -2171, -2171,   129,   192, -2171,    -9,
   -2171,  1402, -2171,     3, -2171, -2171, -2171, -2171,  1717,  1958,
   -2171,    -2, -2171, -2171,  1157,   792,  1483,  1714,   486, -2171,
    1467, -2171, -2171,  1324,  1343,  1157,  1716,  1501,   999,  1721,
    5038, -2171,  5294,    37,  1026,  1118,  1722,   124,  1363, -2171,
   -2171, -2171,  1720,    44, -2171, -2171, -2171,  4398, -2171, -2171,
    1758,   423, -2171, -2171, -2171,   679, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  1421, -2171, -2171,   814,  1301, -2171, -2171,
     182, -2171, -2171, -2171, -2171, -2171, -2171,  1405,  5644, -2171,
    1419,  1729,  1821, -2171, -2171, -2171, -2171,   751,  1468, -2171,
    1429, -2171,  6366,   -29,   747,  1433,  1432, -2171,  -181, -2171,
    1439,  1728,   806, -2171,  1680, -2171,  1735,  1501,  1736,  1680,
    1028,  1737,  1383, -2171,   743, -2171, -2171, -2171, -2171, -2171,
   -2171,  1613, -2171,   679, -2171,   441, -2171,   468,  1854, -2171,
      63, -2171,  1742,    64,   134,  1841,  1746,  4497, -2171, -2171,
    1028,  1743,  5322,  1301, -2171, -2171,  -133, -2171, -2171, -2171,
   -2171,  3550, -2171,  1699, -2171,  1048,  1747,  1784,  1748,  1680,
   -2171,  1028,  1678,   905, -2171,   195,   948, -2171, -2171,   427,
    1452,  1453,  1454,   235, -2171,  1343, -2171,  1455, -2171, -2171,
     236,  1456,   948, -2171,   972,   817,   817, -2171, -2171, -2171,
    1016,  1457,   256,  1460,  1121, -2171,  -106,  1793,  1459,   302,
    6848, -2171,  1121,  1498,  1600, -2171, -2171,  1806, -2171, -2171,
     743,  1723, -2171,   834,  1423,   -23,  1471, -2171,  1343, -2171,
   -2171, -2171,  5743,  1718, -2171,  1696, -2171,  1549, -2171,  1585,
    1673, -2171, -2171, -2171,  1363, -2171,   792, -2171, -2171, -2171,
     509,   402,  1028, -2171, -2171, -2171, -2171, -2171,  7313,  1661,
   -2171,  1334, -2171,  1157, -2171, -2171, -2171,  1703, -2171, -2171,
   -2171,  5644, -2171,  1641,    -4,  1638,  2073,  1458,  1776,  1776,
    1776,  1776, -2171, -2171,  5644,  5743, -2171, -2171, -2171, -2171,
     597,   155, -2171,  1443, -2171,  1446, -2171, -2171, -2171, -2171,
    1384, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  4132, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,    -6, -2171,  1815,  1330,  1770, -2171,   743,
      74, -2171, -2171,  1584, -2171, -2171,    79,  7313, -2171,  1504,
     679, -2171, -2171,  5743,  1468,  1180,  1157, -2171, -2171, -2171,
   -2171, -2171,  1783,  1028,    -9, -2171,  1165, -2171, -2171, -2171,
   -2171,  1501,  1827, -2171, -2171, -2171,  1724, -2171, -2171,   -30,
    1824, -2171, -2171,  1028,  1824,  1509, -2171, -2171,   514,   642,
   -2171, -2171,  2676, -2171,  1908,  1085,    87, -2171, -2171, -2171,
    1121, -2171,   -57,  5644, -2171,    39,  5431, -2171, -2171,  1028,
   -2171,  1762, -2171, -2171,  5743, -2171,  1372, -2171, -2171,   743,
   -2171, -2171, -2171, -2171, -2171,  1841,  1732, -2171, -2171,  1165,
   -2171,  1841, -2171, -2171, -2171,  1451, -2171,  1028,  1359,  1359,
    1359,  3011, -2171,    43,  1359, -2171,  7209,  1359,  1359, -2171,
     637, -2171,  1522, -2171, -2171,  1121,  1121,  1719,  1176, -2171,
   -2171, -2171, -2171,  1759,  1786, -2171,  1121, -2171,   -24, -2171,
   -2171, -2171,  1281,  1121,  1958, -2171, -2171, -2171,  1665, -2171,
    1372, -2171,  1909, -2171, -2171, -2171,  1028, -2171, -2171,  1028,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1764,
    1665,   526,  1121, -2171,  1462,  1518, -2171, -2171, -2171,  1698,
    1665,  1665,   131,  1725,  1665, -2171,  1808, -2171, -2171, -2171,
    1470,  1463, -2171,   743,  1808,  1738,  1553,  1679, -2171, -2171,
    1704, -2171, -2171, -2171, -2171, -2171, -2171,   144, -2171,  1028,
    1483,   542, -2171,   -42,   -46,   679,  1537,  1549,   679, -2171,
    1538,    -9, -2171,   423, -2171, -2171,  1612,  1631, -2171,   727,
    1121, -2171, -2171, -2171, -2171, -2171,  1694, -2171, -2171, -2171,
    1965, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1776,  1121,
   -2171,   -56, -2171, -2171,  1333,  1121, -2171, -2171, -2171, -2171,
     -14, -2171,  2482, -2171,  1426,  1698, -2171, -2171, -2171, -2171,
    1794,   542,  1796,    88, -2171, -2171, -2171, -2171,  1979, -2171,
    1559,   147, -2171, -2171,   155, -2171, -2171, -2171, -2171,  1522,
   -2171, -2171, -2171,  1875,  1865,  1384, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  1640,  1384, -2171,  1563, -2171,  1961, -2171,
   -2171, -2171,   922, -2171,   743,   373, -2171,   106,   905,   -17,
     679,   679,   542,  1809,  1157,   348,   779,  1879, -2171, -2171,
   -2171,  2008, -2171,  1826, -2171, -2171, -2171, -2171,  1724, -2171,
   -2171, -2171, -2171,  1028,  1894,  1703,  1017, -2171,  1523, -2171,
    1526,   743,   930, -2171,   144, -2171, -2171, -2171,  5644,   642,
     642,   642,   642,   642,   642,   642,   642,  1085, -2171,   378,
    1703,    -7, -2171,  1606,  1606, -2171, -2171,   366,  1028,   542,
    1828,  1579, -2171,  1586,  2024,  1028,   363,   -30,  2027,  1531,
    1121, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
    1003, -2171, -2171, -2171,  1028,    -2, -2171, -2171,  1121,  1719,
    1780,  1291, -2171, -2171, -2171,  1028,   444, -2171, -2171, -2171,
   -2171,   444, -2171, -2171,  1121,  1352,  1121, -2171, -2171, -2171,
    1121, -2171, -2171, -2171,   638, -2171, -2171, -2171,  1121,  1534,
     444,   444, -2171, -2171,   444, -2171, -2171,  1751, -2171, -2171,
    1808, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1467,
     -23, -2171, -2171,  1745,     8,  1838,   542,   701, -2171, -2171,
   -2171, -2171, -2171,   -32,   152, -2171, -2171, -2171,   573, -2171,
   -2171, -2171, -2171, -2171, -2171,   444, -2171, -2171, -2171, -2171,
     444,   209,   209, -2171, -2171, -2171, -2171, -2171,  1544,   679,
   -2171,   679,  1755, -2171,  -131,    96,   155, -2171, -2171, -2171,
    1979,  1028, -2171, -2171, -2171, -2171,  1550,  1442,   217,  1551,
     701,   743, -2171, -2171,  1997, -2171, -2171, -2171, -2171,   373,
   -2171,  1862, -2171,  1121,  1451,  1739, -2171, -2171,   679, -2171,
     679,   779,  1390,  1390,  1741, -2171, -2171, -2171,  1045, -2171,
   -2171,  1028,  5644,  1169, -2171, -2171, -2171,  1768, -2171, -2171,
    1790, -2171, -2171, -2171, -2171,  1526, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,     7, -2171,
    1028, -2171, -2171, -2171,   856, -2171, -2171, -2171,  7313, -2171,
    5644,  5644,  1594,  1731,  1467, -2171,   679, -2171,   701, -2171,
    1749, -2171,   743, -2171,  1951,  1629, -2171,   578, -2171,   670,
   -2171,  1531, -2171,  1028, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171,  1255,   -60, -2171,  1028, -2171, -2171, -2171, -2171, -2171,
   -2171,   785, -2171,    -2,   785, -2171, -2171, -2171,   100,  2019,
    2392,  1808, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1657,
    1866, -2171, -2171, -2171,  1868, -2171, -2171, -2171, -2171, -2171,
   -2171,  1778, -2171,  1483, -2171, -2171, -2171, -2171,  1028, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  3188,
   -2171, -2171, -2171,  1267, -2171, -2171, -2171,  2073, -2171,   542,
    1713,   542,  1727, -2171, -2171,  5644, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,  1442, -2171,  1973, -2171,  1384,
   -2171, -2171, -2171,   701,  1214, -2171, -2171,  1214,  -108,  1028,
   -2171, -2171,   542, -2171, -2171, -2171, -2171, -2171,  1700, -2171,
    2030,  1820,  1847,   708, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,   948, -2171, -2171,
   -2171, -2171, -2171,  1798,  1121,  1657,   542,  1598, -2171,  2024,
   -2171,  1548,  2000,  1548,  1594, -2171, -2171, -2171, -2171,  1804,
   -2171, -2171, -2171, -2171,  1296, -2171,  1028, -2171,  1054, -2171,
   -2171,  1780, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171,   444, -2171, -2171, -2171,   444,   158, -2171, -2171,  1121,
   -2171, -2171, -2171,  1121, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171,  2042, -2171, -2171,   -13, -2171,  2091, -2171, -2171, -2171,
    2392, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1028,
   -2171, -2171, -2171, -2171,  2073, -2171,   679, -2171,   679, -2171,
   -2171, -2171,  2051,  1992,  1214,  1214, -2171,  1651,  1651, -2171,
    1766,  1157,   689, -2171,  1028, -2171, -2171,  5644, -2171,  1121,
      52,  1842,  1843, -2171,  1848, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  1028, -2171, -2171, -2171, -2171,  1662, -2171,  1028,
    1548, -2171,  1028, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171,   156,  1121,  1121,  1204, -2171, -2171, -2171, -2171, -2171,
   -2171,  1490, -2171, -2171, -2171,  2005,   444,   444,  1121,   209,
     209, -2171,   408, -2171, -2171, -2171,  1657,  1657,  5644, -2171,
    1214, -2171,  5644,  5644,  1121,  1157,  1157,  1779, -2171, -2171,
    1634,  1028, -2171, -2171,  1768, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  1068, -2171, -2171,  1028, -2171, -2171, -2171,  1121,
    1780,  1780, -2171,  1912,  1121,  1121, -2171,  2061,  1672, -2171,
   -2171,    -2, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,    -9,  1157,  1121, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  1254, -2171, -2171, -2171, -2171, -2171,  1789,
    2026, -2171,  1780, -2171, -2171, -2171,  1780,  1780,  1910,  1242,
    1719,  1925,  1372,  1636,  1121,  1483, -2171,  1121,  1121,  1028,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,   752, -2171,   443, -2171, -2171, -2171,  1242,
    1719, -2171, -2171, -2171,    -9, -2171,  1772,  1726,    -3,  1522,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,   286, -2171,  1121,
    1337, -2171,  7584,  7584,  1298,  2016,  1945, -2171,  1372,   752,
   -2171, -2171,  1372,   443, -2171, -2171,   286, -2171, -2171,  1028,
   -2171,   988, -2171, -2171, -2171,    55, -2171,   752,  1352, -2171,
    1467,  7351, -2171, -2171,  1111,  1150, -2171, -2171,  1168, -2171,
   -2171, -2171, -2171,   -38,   -38, -2171, -2171, -2171, -2171, -2171,
    7584, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1810,
     838,    55, -2171, -2171, -2171,  1693, -2171,  1522, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,  1829, -2171,  1829, -2171,  2094,
   -2171,  1522, -2171, -2171,  1839,  1028, -2171,  1730,   -28,  1825,
   -2171, -2171,  7584,   126, -2171, -2171,  1372, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1157, -2171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2171, -2171, -2171, -2171, -2171,  2141, -2171, -2171, -2171,   911,
   -2171,  2104, -2171,  2059, -2171, -2171,  1322, -2171, -2171, -2171,
    1434, -2171, -2171,  1365,  2126, -2171, -2171,  2029, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,  1952,
     828, -2171, -2171, -2171, -2171, -2171,  2006, -2171, -2171, -2171,
   -2171,  1954, -2171, -2171, -2171, -2171, -2171, -2171,  2082, -2171,
   -2171, -2171, -2171,  1940, -2171, -2171, -2171, -2171,  1924, -2171,
   -2171,   830, -2171, -2171, -2171, -2171,  2013, -2171, -2171, -2171,
   -2171,  1990, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171,  1005, -2171, -2171, -2171, -2171, -2171,
    1593,  1560, -2171, -2171, -2171, -2171, -2171, -2171,  1655, -2171,
    1767, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171,  1889, -2171, -2171, -2171, -2171, -2171,  1753, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  1161, -2171, -2171, -2171,  1408, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  -323, -2171, -2171,  1683, -2171,  -761,  -824, -2171,
   -2171, -2171,   414, -2171, -2171, -2171, -2171,   -64, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -1403,   755,  1447,   471,   477,
   -1400, -2171, -2171, -2171,  -413,  -477, -2171, -2171,   321, -2171,
   -2171,    29, -1399, -2171, -1396, -2171, -1395, -2171, -2171,  1394,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  -451,  -483, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -1301, -2171,  -418, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171,  1346, -2171, -2171, -2171,
      15,    16, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,  1171,  -136, -2171,   148, -2171, -2171, -2171,
   -2171, -1748, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -1195,
   -2171, -2171,  -701, -2171,  1413, -2171, -2171, -2171, -2171, -2171,
   -2171,   986,   473,   475, -2171,   390, -2171, -2171,  -162, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,   442, -2171,
   -2171, -2171,   982, -2171, -2171, -2171, -2171, -2171,   748, -2171,
   -2171,   161, -2171, -2171, -1268, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171,   753, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,   729, -2171, -2171, -2171, -2171, -2171,   -16, -1759,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,   714, -2171, -2171,   713, -2171, -2171,   393,   172,
   -2171, -2171, -2171, -2171, -2171,   949, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,   -21,   681,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171,   672, -2171, -2171,   160, -2171,   379, -2171, -2171, -1460,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171,   923,   674, -2171,   153, -2171, -2171, -2171,
   -2171, -2171, -2171, -1528,   925, -2171, -2171, -2171,   145, -2171,
   -2171, -2171,   364, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,   312,
   -2171, -2171, -2171, -2171, -2171, -2171,   647,   139, -2171, -2171,
   -2171, -2171, -2171,  -138, -2171, -2171, -2171, -2171,   343, -2171,
   -2171, -2171,   907, -2171,   910, -2171, -2171,  1127, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,   128, -2171, -2171,
   -2171, -2171, -2171,   899,   331, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171,   -41, -2171,   336,
   -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  -388, -2171, -2171, -2171, -2171, -2171, -2171, -2171,
   -2171, -2171,  -183, -2171,   626, -2171, -2171, -1662, -2171, -2171,
    -537, -2171, -2171, -1619, -2171, -2171,   -37, -2171, -2171, -2171,
   -2171,  -132, -2170, -2171, -2171,   -45, -1833, -2171, -2171, -1944,
   -1539, -1070, -1432, -2171, -2171,   734, -1575,   157,   159,   164,
     165,  -911,    19,  -729,   372,   314, -2171,   584,  -770, -1361,
   -1074,  -161,   941, -1551,  -383,  -408, -2171, -1316, -2171, -1049,
   -1709,   822, -2171,   -90,  1987, -2171,  1595, -2171,  -552,     6,
    2136, -1076, -1067,  -379,  -974, -2171, -1096, -1101, -2171,   386,
    -700, -1295, -1098, -1171, -1154, -2171, -2171, -2171, -1119, -2171,
    -867,   415,  -614, -2171, -2171,  -103, -1196,  -765,  -111,  2022,
   -1768,  2052,  -673,  1440,  -519,  -421, -2171, -2171, -2171,  -124,
    1314, -2171, -2171,   399, -2171, -2171,  1733, -2171, -2171, -2171,
   -2171, -2171, -2171, -1953, -2171, -2171,  1552, -2171, -2171,  -233,
    -589,  1887, -2171, -1176, -2171, -1315,  -276,  -625,   926, -2171,
    1795, -2171, -1434, -2171, -1402, -2171, -2171,   -93, -2171,    14,
    -657,  -363, -2171, -2171, -2171, -2171,   319,  -258,  -273, -1198,
   -1540,  2095,  -442, -2171, -2171, -1111, -2171, -2171,   989, -2171,
   -2171, -2171,   385, -2171,   243, -1923, -1471, -2171, -2171, -2171,
    -180,   445, -1394, -1683, -2171, -2171, -2171,  -160, -2171, -2171,
    1604, -2171,  1765, -2171, -2171, -2171,   754, -2171, -1778,  -283,
   -2171, -2171, -2171, -2171, -2171, -2171
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1843
static const yytype_int16 yytable[] =
{
     139,   245,   139,   414,   692,   160,   746,   489,   139,   779,
     426,  1264,   427,   138,   764,   141,  1445,  1358,   787,  1426,
     215,   147,   989,  1022,   847,  1876,  1868,  1710,   998,   268,
    1712,  1713,   139,  1249,  1714,  1715,  1720,  1777,   738,  1610,
     436,   426,  1275,  1880,   699,   180,  1296,  1286,  1472,  1836,
    1626,   464,  2182,  2043,  1231,  1286,  2199,  1481,   463,    99,
    1357,  1510,  2108,   984,  2660,   259,   107,  1440,  1464,  1286,
     103,   104,   105,   799,   321,   773,  1410,   264,   111,  1830,
    1340,   246,  2001,  1857,  1008,   345,   852,  2135,   410,   847,
    1421,  1761,  1793,  -656, -1556,   279,  1623,   211,  2236,   392,
    -654, -1738,   114, -1738,   533,   220, -1798,   291,  1839,  2041,
    2459,  1568,  1578,   134,   135,   527,   136,  2400, -1557,   429,
    1210,   143,   144,   834,   799, -1842,  2622,  1221,  1753,  1755,
     161,  1858,  1954,  2209,  1202,  1263,  1267,  1202,  2675,   215,
     297,   830,   830,  1465,  1821,  1292,  1487,   169,  2698, -1776,
     480,   684,  1310,  1312,   412,  1428, -1811, -1583,  2213,   703,
    2027, -1562,    94,   749,  1616,   216,  1520,   221,  1825,   360,
     127,  1369,  1221,  1504,   219, -1742,  1825,  2244,  1796,  1202,
    1231,  2105,  1202,  2246,   327,   222,  1455, -1842,   283,   418,
     505,  2305,  2171,   830, -1798,  1690,  2036,  1691,   704,   742,
    1923,  2085,  2050,   533,  1139,   251,   989,   989,   989,   696,
    1174, -1560,  1872,  1015,  1432,  -504,   512,   258,  1552,   581,
     129,   182,  1016, -1842,   274,   275,  1596,   989,  1967,  1552,
     411,  -656, -1842,   805,   841,  -656,   533,  2136,  -654,  2188,
    2485,  1619,  -654,  -504,  -504,    94,  1395,  1228,  1170, -1524,
    1228,  1859,   437,  2089,  1240,   720,   417, -1842,  1306,   614,
     154,  1636,  2497,   295, -1562,  1174,     3,  1345,  1188,   128,
    1306,   299,  2498,  1929,  1559,   204,  1422,  1608,   311,  1432,
    1433,   792, -1758,  1784,  1946,    15,  1286,  2455,   314, -1738,
    1552,   415,   714,  -656,  1140, -1842,  2703,  2086,   438,  2061,
    -654,  1620,   284,  1549,  1621,  1174,  1174,   212,   211,   183,
    2145,  1228,   721,  1007,  2527,  1860,   137,  1756,  1637,   697,
    1835,   685,   130,  2091,  2321,   448,  1174, -1829,  1924,  1192,
    1934,  1794,   989,  2037,  1569,  1141,  1939,  1117,  2198,   430,
     139,   743,   139,  2285,  2133,  1433,   493,   283,   223,   139,
    1159,  2704,  1505, -1842,   412,   484,   217,  2092,  -504,  2705,
    1843, -1524,   491,  1675,  1142,  1968,   139,  1246, -1738,   507,
     507,   993,   507,  1226,  2066,   507,   514,   409,  1249,   504,
    2214,   -35,  2075,  2069,   280,  1877,  -504,   989,  1390,  2401,
     750,  1676,  1677,  1369,   989,   989,   989,  2205,   137,  1830,
    2006,   832,  1830,  2137,  2016,   423,   281,   989,   989,   989,
     989,   989,   989,   989,   989,  1456,   435,   989,  2623,   835,
     792, -1776,  1579, -1842,   443,   444,   260,   445,   446,  2210,
    2076,  1249,   534,   452,  -656,  1399,  1399,  1399,   137,  2346,
    1275,  -654, -1742,  2706,  2332, -1742,   243,   187,  1412,  1414,
     469,  1302,   129,  2247,   188,  1420,  1193,  1194,  1143,  1535,
    2215,   284,  1731,  2059,   137,   154,   137,   492,  2042,  2460,
     997,   139,   139,   243,  1246,  -504,   137,   733,  1762,   689,
    1888,   137,   137,   535,   609,   609,   700, -1742,  1482,   705,
   -1742,   772,  1246,   139,  1871,   137,   465,  1174,   137,  1249,
    1795,  1009,   137,  1286,  1841,  2024,  -661,   368,  2055,  -659,
    1118,  1947, -1771,    97,  1344,  2512,  2513,  1790,   212, -1811,
    1246,   243,   255,  1972,   322,   792,  1004,   265,   853,  2372,
    1820,  1822,   292,   346,    94,  1884,   737,  1520,  1175,   243,
    1496,  1552,  1861,  1161,  1375,  1511,   573,  1560,  1246,   997,
     740,  1375,   261,  2291,   130,   993,   993,   993,  1981,   137,
    1249,   394,  2010,  2451,   589,  1945,   591,  2014,  1549,   596,
     598,  1427,   600,   754,  2289,   137,   993,  2486,   605,   149,
    2374,  -661,   535, -1742,  -659,   754, -1742,  1179,  1176,  2029,
     351,  1611,  1180,  1175,  2248,  1482,  2033,  1376, -1641,  1873,
    1826,   682,  1447,   449,  1376,  -504,   691,  2219,  1826,  1375,
     707,  1827,  2216,   702,  2077,   535,   137,   757,  1561,  1827,
    2385,  2267,  2387,  1678,  1830,  2043,  1117,   758, -1742,   757,
     394, -1742,  1345,  1175,  1175,  2093,  1982,   243,  1907,   758,
      42, -1840, -1524,  1656,  1605,  1475,   752,  2062,   137,  1922,
   -1524, -1524,  1926,  2405,  1175, -1524,   833,  1014,  1554,   189,
    1930,   838,  1376, -1829,  2169,   450,  2504,   579,  2128, -1842,
    2185,  2129,     4,  -651,   843,   843,   745,  2666,   -96,   958,
     754,   993,   305, -1621, -1618,  1246,  2423,  2424,  2239,  1189,
    2241,  1249,   999, -1842,  2516,   515, -1842,  2094,   754,  2169,
     154,  2020,  2111,  1303,  1668,  2665,   722,   759,   989,  1329,
     752,  1435,  1345,   137,   710,  1298,  1782,   777,   466,   759,
     778,   848,  2022,  1245,   757,  1257,   754,  1235,    16,  2272,
    1262,   190,  2543,  2544,   758,  2315,   993,  2055,  1278,   453,
    1727,  1374,   757,   993,   993,   993,  1406,  1440,  1332,  1779,
    1337,  1406,   758,  1679,   754,  1363,   993,   993,   993,   993,
     993,   993,   993,   993, -1756,  1406,   993,  1372,  2506,  1385,
     757,  1775,  2612,   467,  2590,  2261,   723,   760,  2591,  2592,
     758, -1738,   154, -1738,   228,  2306,   848,   191,  2393,   760,
     580,   711,   192,   712,  2088,  1449,  1776,   989,   757,  1118,
    2195,  2394,  2395,  1286,  1552,  1162,  1163,  2615,   758,  1784,
      18,  -651,  1168,     5,   759,  -651,  2201,  2180,  1329,   -96,
    1246,   761,    23,   306,  2580,  1175,  2642,   722,   229,   516,
    1535,  1758,   759,   761,   722,  2228,  2192,  2193,   230,     5,
    2194,  2078,   254,  2323,   243,  2615,   523,  2517,  2518,   754,
    2475,  1782,  1436,  2308,  2220,  2221,  2222,  2166,  1778,  1856,
     759,  1466,  1279,  1280,  2251,   137,   243,   137,  2253,   243,
    2316,   762,  1484,  -651,  1671, -1623,   599,   137,  1236,  1281,
    1237,  2230,   328,   762,   760,  1179,  2231,  1609,   759,  1558,
    1180,   754,  2476,   757,   154,   255,   989,   725,  1690, -1625,
    1691,  1329,   760,   758,   727,   139,   139,  1197,    24,  2429,
    2284,  2432,   137,   754,  1612,   752,  2663,  2223,   232,  1891,
     187,  1313,  2234,  2234,  2411,  2523,   154,   188,   761,   517,
     760,  1857,  1653,  1282,  2118,   757,  2470,  1950,  1476,  1933,
     187,  1345,    43, -1744,  2412,   758,   761,   188,   137,   155,
    1613,   156,  2663,  2011,  2176,   754,   753,   757,   760,    27,
    1902,  1816,  1817,  1818,  1819,  1635,   722,   758,  2396, -1738,
    2413,   226,   137,  1339,   761,  2240,  1314,  2242,   762,  1858,
     470,   471,   472,   759,  1315,   187,  2585,  2250,   233, -1842,
     137,  2322,   188,  1389,  2583,  2414,   762,  1953,  2015,   757,
    1234,  2373,   761,    43,  1253,  2324,  2477,  2375,  2169,   758,
     717,  1253,  1288,   722,  -651,  2379,  1249,  2378,   137,  1253,
    1654,  1552,  1307,   253,   762,   759,   754,  1328,  2495,  1335,
      28,  1335,  1343,  1360,  1307,   808,   729,  1255,  2607,  2224,
    2225, -1842,  2288,  2000,  2226,   404,   137,   759, -1738,  2625,
    1270,  1335,   762,   760, -1842,  2335,  2618,   993,  2540,   606,
     329,  1271,  2629,  1522,  1523,  1470, -1842,  1431,  1316,   227,
     757,  1431,  1249,  1460,   809,   810,   811,   812,   813, -1842,
     758,  2608,   236,   731,   253,  2342,  1730,   394,  1957,   759,
    2416,  1589,   607,  2417,  2418,   760,   405,   761,  1425,  1859,
    1783,   473,  1524,  1525,  2560,   361,  2419,  2561,  2563,   629,
     630,  2564,  2565,  2579,  2336,   474,  1557,   760,   754,   330,
    2434,  2435,   325,  1909,   780,   170,  1234,  2688,  2280,   300,
       5,  1910,   189,    33, -1070,   747,    36,   362,  2011,   761,
    1590,  2693,  2708,  2008,  2682,  1253,   993,   762,  1467,  2657,
     755,   756,   189,  2658,   344,   228,  1599,    39,  2096,   760,
     759,   761,   757,  1860,  2074,  1731,  2299,  2299,   748,   171,
     831,  1892,   758,  1885,   137, -1756,  2683,   316, -1070,   172,
    2176,  2464,  1253,   137,  1625,  1179,   400,  2453, -1070,   762,
    1180,  2454,   592,  1253,   593,  2528,  2684,   189,   475,   229,
    2172,  2116,  1886,   761,   190,   137,  1649,   991,  2415,   230,
     476,   762,   814,   815,   816,   817,   818,   819,   820,   642,
     643,  1005,  2397,   231,   190,  2490,   828,   828,  1582,    40,
     760,  2441,   829,   829,  2529, -1771,   440,  1343,   317,   318,
    1406,  2442,   551,  2337,   441,   993,  1583,   137,  2338,  2204,
    1253,  2398,   759,   762,  1253,   754,   351,   552,  2502,   173,
     191,  2034,  2461,    94,  2443,   192,  1468,  1181, -1070,   190,
      49,  2389,  2530,  1329,   761,  2044,  1182,   117,   828,  2109,
     191,    94,   243,   394,   829,   192,  1470,    52,   139,   232,
    2008,  2586,  1940,  2503,  2444,   243,  1911,   553,  2670,   757,
     477,  1650,  2509,  2510,  2110,   154,    48,  2277,  2652,   758,
    2497,  1536,  2466,  1537,  2467,   252,  2539,   243,   137,    51,
    2498,  2545,   760,   139,   762,   191,  2664,    93,  1912,   174,
     192,  2229,  2278,    97,    53,    21,    22,  2671, -1070,  1845,
    2234,  2234,  1846,  2515,  2208,  1847,  1848,   100,  2333,  1763,
    1913,  2633,  2502,    94,    46,  2673,   155,  2603,   156,   233,
    2672,   101,   234,   235,   821,   711,   761,   712,   989,   106,
    2168,  2262,    54,   175,    55,   108,    56,   822,  2674,   109,
     298,    26, -1070,  1905,    57, -1842,  2281,  2634,   193,   759,
    1861,   991,   991,   991,  1906,  1875,  2200,  2208,    47,  1640,
    1409,  1641,  1763,  1914,  2497, -1842,  1179,    91, -1738,  2297,
    1179,  1180,   991,  2582,  2498,  1180,   762,   110,  1657,  1896,
    1665,    52,  1661,   176,  1958,  1959, -1070,    94,   112,  1663,
    1179, -1842, -1070,  2480,   554,  1180,    13,  1969,  1670,  1970,
      58,    13,  1921,  1683,  1719,   555,  1721,  1735,  1736,   113,
    1234,  2164,  2310,   236,  1846,  1178, -1842,  1847,  1848,   760,
     114,  1179,  1980,  1915,  1179,  1666,  1180,  1253,    53,  1180,
    1763,  1903,  1990,  1991,  1179,  2208,  1994,   590,   508,  1180,
     510,  1234,   597,   511, -1540, -1540, -1540, -1540,  1737,  2038,
    1738,  2039,  1739,   427,  2519,  1417,  1418,  1419,  2520,  2521,
     120,  2630,  2632,   761,   122,  1253,    54,  2329,    55,  2330,
      56,  1498,  1499,  1500,  1501,  1213,   124,  1227,    57,  2381,
    1243,  2382,  2045,  2046,  1265,  1932,  1740,  1741,  1742,   126,
    2669,  1763,   137,    60,  1942,  1943,  1944,   140,   137,  1301,
    1948,  2595,  2596,  1951,  1952,  1327,   556,   557,  2437,  2679,
    2438,  1415,  1416,   762,   139,  1737,   142,  1738,  1916,   149,
    1169,   558,  1171,   559,  1401,  1402,  1383,  1941,  1387,   167,
     162,   163,   991,   164,    58,   181,  1743,    61,  1744,   991,
     991,   991,  1404,   185,   186,  1745,   204,  1404,  1746,  1975,
    2208,  2702,   991,   991,   991,   991,   991,   991,   991,   991,
     193,  1404,   991, -1539, -1539, -1539, -1539,  1849,  1850,   242,
    1983,   247,   726,   728,   730,   732,   248,   249,   250,  2635,
     257,   273,   269,  2636,  2637,   278,   296,   294,   154,   300,
    1446,  1851,  1852,   302,  1919,   303,    59,   307,   308,   309,
     312,   313,   326,   334,   333,   336,   560,   338,   340,   342,
    2274,  2275,   351,   349,  1327,   353,  1243,   354,  1253,   356,
     392,   394,  1253,   397,  2638,  1253,    64,    60,  1234, -1842,
     357,   398,   243,   401,   403,  1747,   407,  1748,   187,   419,
    2639,  2640,   408,   243,   420,   358,   421,   428,   412,  1955,
    1956,   454,   455,   561,  1345,   359,  2098,   483,   457,   459,
    1966,  -346,   490,   485,   494,   495,   487,  1971,   427,    67,
     502,    61,   509,   519,    62,   520,   521,   993,  1253,  1849,
    1850,  2270,   525,   531,   539,   543,   544,   118,   545,   360,
     547,  -359,   576,   550,   548,   577,  1984,  1327,   583,   584,
     585,   601,   603,  1851,  1852,   612,   613,  2143,   616,   617,
     690,   688,   693,   709,   733,   716,  2143,  1896,   735,   780,
     701,  -858,   741,   767,  -858,   770,   774,  1253,  1253,  1253,
     751,  2119,  2120,  2121,  2122,  2123,  2124,  2125,  2126,    63,
      68,   786,   789,   790,   795,  1631,   792,   800,   776,   806,
     832,   802,   839,   845,  2028, -1625,   997,   959,  1002,  1003,
      64,  1006,  1147,  1027,  1202,  1019,  1128,  1155,  1024,  1157,
    1164,  1165,  1183,  2035,  1195,  1166,  1167,  1208,  1268,  2040,
    1172,  1184,  1186,  1187,  1199,    65,  1253,    66,  1201,  1209,
    1289,  1390,   989,   989,  1423,  1425,   752,  -858,  1424,  1397,
    1398,  1438, -1742,    67,  1408,  1444,  1450,  1473,  1459,  1461,
    1485,   139,   440,  1479,  -858,   780,  1488,  1508,  1502,  1550,
    1506,   989,  1554,  1307,  2165,  1570,  1749,  1567,  1307,  1571,
    1573,  1587,  1575,  2186, -1542,  1584,  1592,  1585,  1586,  1594,
     989,  1597,  1603,  1601,  1345,  1615,   361,  1307,  1307,  1617,
    1202,  1307,  1632,   991,  1627,  1639,  1645,  1643,  1651,  1647,
    1658,  1659,  1660,  1662,  1664,  1667,  1669,  1672,  1722,   961,
    1674,  2098,  1723,  1253,    68,  1725,  1750,  1759,   362,  1766,
    1728,  1765,   989,  2283,  1770,  1768,   962,  1751,  -235,  1228,
    2235,  2235,  1307,  1780,  1784,  1791,  1797,  1307,  1307,  1307,
    2626,  1490,  1814,  1842,  1831,  1855,  1253,  1834,  1253,  1560,
    1870,  1878,  1893,  1897,  2163,  1901,  -858,  1908,  1928,  2655,
    1935,  2598,  1963,  1962,  1973,  1976,  1985,  -858,  1979,  1986,
    1988,  1999,  2167,  1995,   780,  2002,  2003,  1730,  2004,  1998,
    2005,   363,   991,  2017,  2021,  1253,   364,  1253,  2181,  2030,
    2183,  2617,  2025,  2026,  2184,  1440,  2056,  2049,  1883,  2051,
    -858,  2057,  2189,  2063,  2064,  2067,  -858,  1890,  -858,  2070,
    2071,  -858,  2090,  -858,  -858,  -858,  2101,   365,  1899,  -858,
    2099,  -858,  2102,  2105,  2112,   366,  -858,  2113,   963,  2139,
    2147,  2146,  2148,  2149,  2158,  2160,  2169,  2190,   367,   754,
     961, -1561,  2202,  1253,  1927,  2196,  2263,  2237,  2254,  2260,
    2266,  2276,  2287,  2271,   780,  2301,  1307,   962,  -858,  2285,
     139,  2304,  2309,  -858,  2311,  2313,  2347,   368,  2011, -1517,
     369, -1559,  2376,  2327,  2386,  2391,  1404,  -858,   370,  2407,
    2406,   991,  2408,   757,  2409,   967,   968,   969,  2388,  -232,
    2425,   970,   427,   758,  2420,  2430,  2316,  2269,  2458,  2461,
    2468,  -858,  2469,  2474,  2487,  2488,   627,  2471,  1799,  1327,
    2489,  1800, -1742,  2493,  2508,  2525,  2524,   371,  1801,  1802,
     372,  1977,  2545,  2581,  1978,  1690,  1737,  1691,  1738,  2588,
     971,  2593,  -858,  2589,  2599,  2649,  1253,  2601,  1253,  2619,
     427,  2650,  2689,  2692,  2620,  2694,  2701,  2680,    17,   782,
      92,   125,    38,   256,   209,  2696,   166,   119,   780,   963,
     266,   277,   290,   210,  1803,  -858,   139,   241,   611,  1253,
     708,  -858,   541,   759,  2009,   323,   442,   456,  1196,  2403,
     524,   993,   993,  -858,  -858,  1711,   844,  2628,  2687,  2084,
    2325,  1001,   796,  2678,  2691,  2654,  1023,  1207,  1442,  2343,
    2344,   957,  2245,  1253,   973,  2048,  1993,  1992,  2463,  2019,
     993,  1458,  1773,  2243,  1463,  -858,   967,   968,   969,  1774,
    1789,  2384,   970,   139,  1824,  -858,  1832,  2060,  2249,   993,
    1551,  -858,   992,  1804,  2390,  1866,  2440,  1854,  1307,  2265,
    1574,  2072,  1307,   760,  2273,  -858,  2279,  1577,  1874,  2157,
    -858,  1900,  2103, -1742,  2290,   974,   975,  -858,  1606,  -858,
    2127,   971,  1805,  1607,  1361,  -858,  1630,  2155,  2428,  2300,
    2548,   993,  2156,  2686,  2436,  1938,  1838,  2433,  2484,   780,
     780,  1600,  1772,  1253,  1806,  1253,   332,   761,   213,   769,
    2117,  2293,   310,  2294,   293,  1173,   645,   979,  2295,  2296,
    2587,  2479,   804,   447,   538,  2473,  2616,   610,  2104,  2141,
     272,  2259,  2083,  2549,   783,  2550,   780,   980,  2422,   595,
    1869,  2643,   981,     0,     0,   427,     0,     0,     0,   982,
       0,   137,     0,     0,     0,   973,     0,   762,  1807,     0,
       0,     0,     0,  2144,     0,     0,  2551,     0,  2235,  2235,
    2154,  2154,     0,  1307,  1307,     0,  1307,  1307,     0,  1307,
       0,     0,     0,  2456,     0,     0,  2552,  2457,     0,     0,
    1243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2175,     0,     0,     0,     0,     0,   974,   975,   649,     0,
       0,  1808,     0,     0,  2553,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,   992,   992,  1234,
       0,     0,     0,  2481,  2348,     0,     0,  2349,   979,     0,
    2350,     0,  2207,     0,     0,     0,     0,   992,  2351,     0,
       0,  2600,     0,     0,     0,     0,     0,     0,   980,     0,
       0,  1809,     0,   981,     0,     0,  2500,  2501,     0,     0,
     982,     0,   137,     0,  1810,     0,   654,     0,     0,     0,
       0,     0,  2511,     0,     0,  2554,  2252,     0,     0,     0,
       0,  1234,     0,  2352,     0,  2207,   780,     0,  2522,     0,
       0,     0,  2555,     0,   780,     0,     0,  2651,     0,     0,
       0,  2653,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2556,  2542,     0,     0,  1883,  1799,  2546,  2547,
    1800,     0,  1234,     0,     0,     0,     0,  1801,  1802,     0,
       0,     0,     0,  2557,     0,     0,     0,     0,  2584,     0,
       0,     0,   992,     0,     0,  2292,  1811,  1254,     0,     0,
       0,     0,  2558,   991,  1254,     0,     0,     0,  1234,   663,
    2559,     0,  1254,  2207,     0,     0,     0,   780,  2602,     0,
       0,  2604,  2605,  1803,     0,     0,  1254,     0,     0,     0,
       0,  2353,  2695,     0,     0,  2709,     0,     0,     0,  2334,
    2354,     0,     0,     0,     0,     0,     0,   992,  1243,     0,
       0,     0,     0,  2355,   992,   992,   992,  1405,     0,     0,
       0,     0,  1405,  2627,     0,     0,     0,   992,   992,   992,
     992,   992,   992,   992,   992,     0,  1405,   992,     0,     0,
       0,     0,     0,  2380,     0,  2356,     0,     0,     0,     0,
       0,   855,  1804,   856,     0,   857,     0,  1490,     0,     0,
     858,     0,     0,     0,     0,  2357,  1448,  2358,   859,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1805,     0,     0,     0,     0,     0,     0,  2207,     0,
    2359,     0,  1214,     0,     0,   752,     0,     0,  1254,     0,
       0,   860,   861,  1806,     0,     0,     0,     0,     0,     0,
     862,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2360,   863,     0,     0,   864,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1254,     0,     0,   865,     0,
       0,     0,     0,     0,     0,     0,  1254,  2361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1807,     0,     0,
       0,   866,     0,     0,     0,     0,     0,     0,   961,   867,
       0,   868,     0,  2362,     0,     0,     0,     0,     0,     0,
    2363,     0,     0,     0,     0,   962,     0,     0,     0,     0,
       0,     0,     0,  2364,   782,     0,     0,  2365,     0,     0,
       0,     0,   869,  1254,  2465,     0,     0,  1254,     0,     0,
    1808,     0,     0,   870,     0,     0,     0,     0,   871,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1904,     0,
       0,     0,     0,     0,     0,   872,  2366,  2491,     0,     0,
       0,     0,   873,     0,  2494,   874,   875,  2496,     0,     0,
       0,     0,     0,     0,     0,   876,     0,     0,     0,     0,
    1809,     0,   877,     0,   878,  2367,     0,   879,     0,     0,
       0,     0,     0,  1810,     0,  2368,     0,   963,     0,     0,
     782,  2369,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,  1764,     0,     0,     0,  2526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   880,
    2541,     0,     0,   881,     0,   882,     0,     0,   992,     0,
       0,  1216,     0,     0,     0,   883,  1243,   965,     0,   966,
       0,     0,   757,     0,   967,   968,   969,     0,     0,     0,
     970,     0,   758,     0,     0,  1764,     0,  1217,     0,     0,
       0,   884,     0,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,   885,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2606,     0,     0,     0,     0,   971,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   886,
     887,     0,     0,     0,     0,     0,     0,     0,   972,   782,
     888,     0,     0,     0,     0,     0,     0,   992,     0,     0,
    1254,     0,     0,  1764,   889,   890,     0,   991,   991,     0,
       0,   891,   759,     0,     0,   892,     0,     0,     0,     0,
       0,     0,     0,   893,  2656,     0,     0,     0,     0,     0,
       0,     0,     0,   894,     0,     0,   991,     0,  1254,     0,
       0,     0,   895,   973,     0,     0,     0,     0,  2677,  2677,
       0,   896,     0,     0,     0,   991,   897,   898,     0,     0,
     899,     0,   900,     0,  1764,     0,     0,     0,   901,   782,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   902,   760,   961,     0,     0,     0,     0,     0,     0,
       0,  1405,     0,  2700,   974,   975,   992,   991,     0,   903,
     962,     0,     0,     0,     0,   904,     0,     0,     0,     0,
     905,     0,     0,     0,     0,     0,     0,     0,     0,  1905,
       0,     0,     0,     0,     0,     0,   761,     0,     0,     0,
    1906,     0,     0,     0,     0,     0,   979,   906,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   980,     0,     0,     0,
       0,   981,     0,     0,     0,     0,     0,     0,   982,     0,
     137,     0,     0,   782,     0,     0,   762,     0,     0,   855,
       0,   856,     0,   857,     0,     0,     0,     0,   858,     0,
       0,  1254,     0,     0,     0,  1254,   859,     0,  1254,     0,
       0,     0,   963,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   860,
     861,     0,     0,     0,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   863,
       0,  1254,   864,     0,     0,     0,     0,   757,     0,   967,
     968,   969,     0,     0,     0,   970,   865,   758,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   866,
       0,     0,     0,     0,   782,   782,     0,   867,     0,   868,
    1254,  1254,  1254,     0,   971,     0,  -698,     0,  -698,  -698,
    -698,  -698,  -698,  -698,  -698,  -698,     0,  -698,  -698,  -698,
       0,  -698,  -698,  -698,  -698,  -698,  -698,  -698,  -698,  -698,
     869,   782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   870,     0,     0,     0,     0,   871,   759,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   872,     0,     0,     0,     0,   973,     0,
     873,     0,     0,   874,   875,     0,     0,     0,     0,     0,
       0,     0,     0,   876,     0,     0,     0,     0,     0,     0,
     877,     0,   878,     0,     0,   879,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   974,
     975,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1254,   880,     0,     0,
       0,   881,     0,   882,     0,     0,     0,     0,     0,     0,
       0,   761,     0,   883,     0,     0,     0,     0,     0,  -698,
    -698,   979,  -698,  -698,  -698,  -698,     0,     0,     0,  1254,
       0,  1254,     0,     0,     0,     0,     0,     0,     0,   884,
       0,   980,     0,     0,     0,     0,   981,     0,     0,     0,
       0,   782,   885,   982,     0,   137,     0,     0,     0,   782,
       0,   762,     0,     0,     0,     0,     0,     0,  1254,     0,
    1254,     0,     0,     0,     0,     0,     0,   886,   887,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   888,     0,
       0,   855,     0,   856,     0,   857,     0,     0,     0,     0,
     858,     0,   889,   890,     0,     0,     0,     0,   859,   891,
       0,     0,     0,   892,     0,     0,     0,     0,   992,     0,
       0,   893,     0,     0,     0,     0,  1254,     0,     0,     0,
       0,   894,   782,     0,     0,     0,     0,     0,     0,     0,
     895,   860,   861,     0,     0,     0,     0,     0,     0,   896,
     862,     0,     0,     0,   897,   898,     0,     0,   899,     0,
     900,   863,     0,     0,   864,     0,   901,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   865,  -698,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   855,
       0,   856,     0,   857,     0,     0,     0,   903,   858,     0,
       0,   866,     0,   904,     0,     0,   859,     0,   905,   867,
       0,   868,     0,     0,     0,     0,     0,     0,     0,  1254,
       0,  1254,     0,     0,     0,     0,     0,     0,     0,  -698,
       0,     0,     0,     0,     0,   906,     0,     0,     0,   860,
     861,     0,   869,     0,     0,     0,     0,     0,   862,     0,
       0,     0,  1254,   870,     0,     0,     0,     0,   871,   863,
       0,     0,   864,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   865,     0,     0,     0,
       0,     0,     0,     0,     0,   872,  1254,     0,     0,     0,
       0,     0,   873,     0,     0,   874,   875,     0,     0,   866,
       0,     0,     0,     0,     0,   876,     0,   867,     0,   868,
       0,     0,   877,     0,   878,     0,     0,   879,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     869,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   870,     0,     0,     0,     0,   871,     0,     0,   880,
       0,     0,     0,   881,     0,   882,  1254,     0,  1254,     0,
       0,     0,     0,     0,     0,   883,     0,     0,     0,     0,
       0,     0,     0,   872,     0,     0,     0,     0,     0,     0,
     873,     0,     0,   874,   875,     0,     0,     0,     0,     0,
       0,   884,     0,   876,     0,     0,     0,     0,     0,     0,
     877,     0,   878,     0,   885,   879,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   886,
     887,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     888,     0,     0,     0,     0,     0,     0,   880,     0,     0,
       0,   881,     0,   882,   889,   890,     0,     0,     0,     0,
       0,   891,     0,   883,     0,   892,     0,     0,     0,     0,
       0,     0,     0,   893,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   894,     0,     0,     0,     0,     0,   884,
       0,     0,   895,     0,     0,     0,     0,     0,     0,     0,
       0,   896,   885,     0,     0,     0,   897,   898,     0,     0,
     899,     0,   900,     0,     0,     0,     0,     0,   901,     0,
       0,     0,     0,     0,     0,     0,     0,   886,   887,     0,
       0,  1638,     0,     0,     0,     0,     0,     0,   888,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   903,
       0,     0,   889,   890,     0,   904,     0,     0,     0,   891,
     905,     0,     0,   892,     0,     0,     0,     0,     0,     0,
       0,   893,   992,   992,     0,     0,     0,     0,  1029,     0,
    1030,   894,     0,     0,     0,  1031,     0,   906,     0,     0,
     895,     0,     0,  1032,     0,     0,     0,     0,     0,   896,
       0,   992,     0,     0,   897,   898,     0,     0,   899,     0,
     900,     0,     0,     0,     0,     0,   901,     0,     0,     0,
     992,     0,     0,     0,     0,     0,  1033,  1034,     0,     0,
       0,     0,     0,     0,     0,  1035,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1036,   903,     0,  1037,
       0,     0,   961,   904,     0,     0,     0,     0,   905,     0,
       0,     0,   992,  1038,     0,     0,     0,     0,  1214,   962,
       0,   752,     0,     0,  1516,  1517,  1518,     0,     0,     0,
       0,     0,  1519,     0,     0,   906,  1039,     0,     0,     0,
       0,     0,     0,     0,  1040,     0,  1041,     0,     0,     0,
       0,     0,     0,  1042,     0,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,     0,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1064,     0,
       0,     0,     0,  1065,   961,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1319,   962,     0,     0,     0,     0,     0,     0,     0,     0,
    1066,   963,     0,     0,     0,     0,     0,  1067,     0,     0,
    1068,  1069,     0,     0,     0,     0,     0,     0,     0,     0,
    1070,     0,     0,     0,     0,     0,     0,  1071,     0,  1072,
       0,     0,  1073,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1520,     0,     0,     0,     0,  1320,     0,   967,   968,
     969,  1521,     0,     0,   970,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1074,     0,     0,     0,  1075,     0,
    1076,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1077,     0,     0,   963,     0,     0,     0,     0,     0,  1522,
    1523,     0,     0,   971,   754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1078,     0,     0,     0,
       0,     0,     0,     0,  1837,     0,     0,     0,     0,  1079,
       0,     0,     0,     0,     0,     0,     0,  1216,  1524,  1525,
       0,     0,     0,   965,     0,   966,     0,     0,   757,     0,
     967,   968,   969,     0,  1080,     0,   970,     0,   758,     0,
       0,     0,     0,  1217,  1214,  1081,     0,   752,     0,     0,
    1516,  1517,  1518,     0,     0,     0,  1526,   973,  1519,     0,
    1082,     0,  1527,     0,     0,  1528,  1083,     0,     0,     0,
    1084,     0,     0,  1529,     0,   971,     0,     0,  1085,     0,
    1530,     0,     0,     0,     0,  1531,     0,     0,  1086,     0,
       0,     0,     0,     0,   972,     0,     0,  1087,     0,     0,
       0,     0,     0,     0,  1532,     0,  1088,     0,   974,   975,
       0,  1089,  1090,     0,     0,  1091,     0,  1092,   759, -1842,
     961,     0,     0,  1093,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1094,   962,     0,     0,
       0,     0,     0,  1214,     0,     0,   752,     0,     0,   973,
     979,     0,     0,     0,  1095,     0,     0,     0,     0,     0,
    1096, -1126,     0,     0,     0,  1097,     0,     0,     0,     0,
     980,     0,     0,     0,     0,   981,     0,     0,     0, -1126,
       0,     0,   982,   243,   137,     0,     0,     0,   760,     0,
       0,     0,  1098,     0,     0,     0,     0,  1520,     0,     0,
     974,   975,     0,     0,     0,     0,     0,  1521,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   961,
    1533,     0,  1534,     0,  1535,     0,     0,  1536,     0,  1537,
    1538,  1539,   761,     0,  1540,  1541,   962,     0,     0,   963,
       0,     0,   979,     0,     0,  1522,  1523,     0,     0,  1365,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   980,     0,     0,     0,  1214,   981,     0,   752,
       0,     0,     0,     0,   982,     0,   137,     0,     0,     0,
       0,     0,   762,  1216,  1524,  1525,     0,     0,     0,   965,
       0,   966,     0,     0,   757,     0,   967,   968,   969,     0,
       0,     0,   970,     0,   758,     0,     0,     0,     0,  1217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1526,     0,     0,     0,     0,     0,  1527,     0,
       0,  1528,     0,     0,     0,     0,     0,     0,   963,  1529,
       0,   971,   961,     0,     0,     0,  1530,     0,     0,   754,
       0,  1531,     0,     0,  1215,     0,     0,     0,     0,   962,
     972,     0,     0,  1214,     0,  1629,   752,     0,     0,     0,
    1532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1216,     0,   759,     0,     0,     0,   965,     0,
     966,     0,     0,   757,     0,   967,   968,   969,     0,     0,
       0,   970,     0,   758,     0,     0,     0,     0,  1217,     0,
       0,     0,     0,     0,     0,   973,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   961,
     971,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1308,     0,     0,   760,     0,   962,     0,     0,   972,
       0,   963,     0,     0,     0,     0,   974,   975,     0,     0,
       0,  1214,   754,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,   759,     0,     0,  1533,     0,  1534,     0,
    1535,     0,     0,  1536,     0,  1537,  1538,  1539,   761,     0,
    1540,  1541,     0,     0,     0,  1216,     0,     0,   979,     0,
       0,   965,     0,   966,   973,     0,   757,     0,   967,   968,
     969,     0,     0,     0,   970,     0,   758,     0,   980,     0,
       0,  1217,     0,   981,     0,     0,     0,     0,     0,     0,
     982,     0,   137,     0,     0,     0,     0,   961,   762,     0,
       0,     0,     0,   760,     0,     0,     0,     0,   963,     0,
       0,     0,     0,   971,   962,   974,   975,     0,  1214,   754,
       0,   752,     0,     0,     0,     0,     0,  1365,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   761,     0,     0,
       0,     0,  1216,     0,     0,     0,   759,   979,   965,     0,
     966,     0,     0,   757,     0,   967,   968,   969,     0,     0,
       0,   970,     0,   758,     0,     0,     0,   980,  1217,     0,
       0,     0,   981,     0,     0,     0,     0,   973,     0,   982,
       0,   137,     0,     0,   961,     0,     0,   762,     0,     0,
       0,     0,     0,     0,     0,     0,  1370,     0,     0,     0,
     971,   962,     0,     0,     0,     0,   963,     0,  1214,     0,
       0,   752,     0,     0,     0,     0,   760,   754,     0,   972,
       0,     0,     0,     0,  -914,     0,     0,  -914,   974,   975,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   759,     0,     0,     0,     0,     0,     0,
    1216,     0,     0,     0,     0,     0,   965,     0,   966,     0,
     761,   757,     0,   967,   968,   969,     0,     0,     0,   970,
     979,   758,     0,     0,   973,     0,  1217,     0,     0,     0,
       0,     0,     0,     0,   961,     0,     0,     0,     0,     0,
     980,     0,     0,     0,     0,   981,     0,     0,     0,     0,
    -914,   962,   982,   963,   137,     0,     0,     0,   971,     0,
     762,     0,     0,   760,   754,     0,     0,  -914,     0,     0,
       0,     0,     0,     0,     0,   974,   975,   972,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1216,     0,     0,
       0,   759,     0,   965,     0,   966,     0,   761,   757,     0,
     967,   968,   969,     0,     0,     0,   970,   979,   758,     0,
       0,     0,     0,  1217,     0,     0,     0,     0,     0,     0,
       0,     0,   973,  1490,     0,     0,     0,   980,     0,     0,
       0,     0,   981,     0,     0,     0,     0,     0,     0,   982,
       0,   137,     0,   963,     0,   971,     0,   762,     0,     0,
       0,     0,     0,     0,   754,     0,     0,     0,     0,  -914,
       0,   760,     0,     0,   972,     0,     0,     0,     0,     0,
    -914,     0,     0,   974,   975,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1216,   759,     0,
       0,     0,     0,   965,     0,   966,     0,     0,   757,     0,
     967,   968,   969,  -914,     0,   761,   970,     0,   758,  -914,
       0,  -914,     0,  1217,  -914,   979,  -914,  -914,  -914,   973,
    1214,     0,  -914,   752,  -914,     0,     0,     0,     0,  -914,
       0,     0,     0,     0,     0,   980,     0,     0,     0,     0,
     981,     0,     0,     0,     0,   971,     0,   982,  1214,   137,
       0,   752,     0,     0,     0,   762,     0,     0,   760,     0,
       0,  -914,     0,     0,   972,     0,     0,     0,     0,     0,
     974,   975,     0,     0,     0,     0,     0,     0,     0,     0,
    -914,     0,     0,     0,     0,     0,     0,     0,   759,     0,
       0,     0,     0,     0,     0,     0,   961,     0,     0,     0,
       0,     0,   761,     0,  -914,     0,     0,     0,     0,     0,
       0,     0,   979,   962,     0,     0,     0,     0,     0,   973,
       0,     0,     0,     0,   961,     0,     0,     0,     0,     0,
       0,     0,   980,     0,     0,  -914,     0,   981,     0,     0,
       0,   962,     0,     0,   982,     0,   137,     0,     0,     0,
       0,     0,   762,     0,     0,     0,     0,  1214,   760,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     974,   975,     0,     0,  -914,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -914,  -914,  1452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   761,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   979,     0,     0,   963,     0,     0,  -914,     0,
       0,     0,     0,     0,     0,     0,   754,     0,  -914,     0,
       0,     0,   980,   961,     0,     0,     0,   981,  1634,     0,
       0,     0,     0,   963,   982,     0,   137,     0,  -914,     0,
     962,     0,   762,  -914,   754,     0,     0,     0,     0,  1216,
    -914,  1214,  -914,     0,   752,   965,     0,   966,  -914,     0,
     757,     0,   967,   968,   969,     0,     0,     0,   970,     0,
     758,     0,     0,     0,     0,  1217,     0,  1216,     0,     0,
       0,     0,     0,   965,     0,   966,     0,     0,   757,     0,
     967,   968,   969,     0,     0,     0,   970,     0,   758,     0,
       0,     0,     0,  1217,     0,     0,     0,   971,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   972,   961,     0,     0,
       0,     0,     0,     0,     0,   971,     0,     0,     0,     0,
       0,     0,   963,     0,   962,     0,     0,     0,     0,     0,
     759,     0,     0,   754,   972,     0,     0,     0,     0,     0,
    1214,     0,     0,   752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   759,     0,
       0,   973,     0,     0,     0,     0,  1216,     0,     0,     0,
       0,     0,   965,     0,   966,     0,     0,   757,     0,   967,
     968,   969,     0,     0,     0,   970,     0,   758,     0,   973,
       0,     0,  1217,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   974,   975,     0,     0,   961,     0,     0,     0,
       0,     0,     0,     0,   971,     0,   963,     0,   760,     0,
       0,     0,     0,   962,     0,     0,     0,   754,     0,  1760,
     974,   975,   752,   972,   761,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   979,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   759,  1494,     0,
    1216,     0,   761,     0,   980,     0,   965,     0,   966,   981,
       0,  1258,   979,   967,   968,   969,   982,     0,   137,   970,
       0,   758,     0,     0,   762,     0,  1217,     0,   973,     0,
       0,     0,   980,     0,     0,     0,     0,   981,     0,     0,
       0,     0,     0,     0,   982,   961,   137,     0,     0,     0,
       0,     0,   762,     0,     0,     0,     0,     0,   971,     0,
       0,  1925,   962,     0,     0,   963,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,   754,   972,     0,   974,
     975,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   759,     0,     0,     0,     0,     0,     0,     0,  1216,
       0,   761,     0,     0,     0,   965,     0,   966,     0,     0,
     757,   979,   967,   968,   969,     0,     0,     0,   970,     0,
     758,     0,   973,     0,     0,  1217,     0,     0,     0,     0,
       0,   980,     0,     0,     0,     0,   981,     0,     0,     0,
       0,     0,     0,   982,     0,   137,     0,     0,     0,     0,
       0,   762,     0,     0,   963,     0,     0,   971,     0,     0,
       0,   760,     0,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,   974,   975,     0,   972,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1216,     0,
     759,     0,     0,     0,   965,   761,   966,     0,     0,   757,
       0,   967,   968,   969,     0,   979,     0,   970,     0,   758,
       0,     0,     0,     0,  1217,     0,     0,     0,     0,     0,
       0,   973,     0,     0,     0,   980,     0,     0,     0,     0,
     981,     0,     0,     0,     0,     0,     0,   982,     0,   137,
       0,     0,     0,     0,     0,   762,   971,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   974,   975,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   759,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   761,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   979,     0,     0,     0,     0,     0,
     973,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   980,     0,     0,     0,     0,   981,
       0,     0,  1021,     0,     0,     0,   982,     0,   137,     0,
       0,     0,     0,     0,   762,     0,     0,     0,     0,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   974,   975,  -356,     0,     0,  -356,     0,     0,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   761,     0,  -356,     0,  -356,     0,     0,
       0,     0,     0,   979,  -356,     0,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   980,     0,     0,     0,     0,   981,     0,
       0,     0,     0,     0,     0,   982,     0,   137,     0,     0,
       0,     0,     0,   762,     0,     0,     0,     0,     0,     0,
    -356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,  -356,
    -356,  -356,  -356,  -356,   526,     0,  -356,  -356,     0,     0,
    -356,     0,     0,     0,     0,     0,     0,  -356,     0,  -356,
       0,     0,     0,     0,  -356,  -356,     0,     0,     0,     0,
       0,     0,  -356,     0,     0,     0,     0,     0,     0,  -356,
    -356,     0,  -356,  -356,  -356,  -356,  -356,  -356,  -356,     0,
       0,     0,     0,  -356,     0,     0,  -356,     0,     0,     0,
       0,     0,  -356,     0,  -356,     0,     0,     0,     0,     0,
       0,     0,     0,  -356,     0,     0,  -356,     0,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,     0,  -356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -356,     0,     0,     0,  -356,     0,   961,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -356,
    -356,     0,     0,     0,     0,   962,     0,     0,  -356,     0,
       0,  -356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -356,     0,  -356,     0,     0,     0,
       0,     0,     0,     0,  -356,     0,     0,     0,   527,     0,
       0,  -356,  -356,  -356,  -356,  -356,     0,     0,  -356,  -356,
       0,     0,  -356,     0,     0,     0,     0,     0,     0,  -356,
       0,     0,     0,     0,     0,     0,     0,  -356,     0,     0,
       0,     0,     0,     0,     0,     0,  -356,     0,     0,     0,
       0,     0,  -356,     0,     0,     0,  -356,     0,  -356,  -356,
    -356,     0,     0,     0,     0,  -356,  1319,     0,  -356,     0,
       0,     0,     0,     0,  -356,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -356,     0,     0,
       0,     0,  -356,     0,     0,     0,     0,  -356,     0,     0,
    -356,     0,     0,     0,     0,     0,     0,     0,     0,  -356,
       0,     0,     0,     0,  -356,     0,     0,     0,  -356,  -356,
    -356,     0,  1463,     0,   967,   968,   969,     0,  -356,     0,
     970,     0,  -356,     0,     0,     0,     0,     0,  -356,  -356,
       0,     0,  -356,     0,     0,   528,     0,     0,     0,     0,
    -356,     0,   619,  -356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -356,   620,     0,   971,
     621,   622,   623,   624,   625,   626,   627,     0,  -356,     0,
       0,     0,     0,     0,     0,     0,  -356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   628,     0,   629,   630,   631,   632,
     633,   634,   635,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -356,     0,
    -356,  -356,  -356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   973,     0,     0,     0,     0,     0,     0,
     636,     0,     0,     0,     0,     0,     0,  -356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -356,     0,     0,   974,   975,     0,     0,     0,     0,
    -356,  -356,  -356,     0,     0, -1842,     0,     0,     0,   637,
     638,   639,   640,   641,  -356,     0,   642,   643,     0,     0,
       0,  -356,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,   979,   621,   622,   623,
     624,   625,   626,     0,     0,     0,     0, -1126,     0,     0,
     644,     0,     0,     0,     0,     0,   980,     0,     0,     0,
       0,   981,     0,    94,     0, -1126,   645,     0,   982,   243,
     137,   628, -1818,   629,   630,   631,   632,   633,   634,   635,
    1685,     0,     0,  1686,     0,     0,  1687,   621,   622,   623,
     624,   625,   626,  1688,  1689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   646,     0,
       0,     0,  1690,     0,  1691,     0,     0,   636,     0,     0,
       0,   628,     0,   629,   630,   631,   632,   633,   634,   635,
       0,     0,     0,     0,     0,     0,   647,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     648,     0,     0,     0,     0,     0,     0,     0,   649,     0,
       0,   650,     0,     0,     0,     0,     0,   636,     0,     0,
       0,     0,     0,     0,   651,     0,   637,   638,   639,   640,
     641,     0,     0,   642,   643,     0,   652,     0,     0,     0,
       0,     0,     0,     0,   653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1692,     0,
       0,     0,     0,     0,     0,     0,     0,   644,   961,     0,
       0,     0,     0,     0,     0,     0,   637,   638,   639,   640,
     641,     0,     0,   642,   643,   962,   654,  1693,   655,   656,
     657,     0,     0,     0,  1694,     0,  1695,     0,     0,     0,
       0,     0, -1771,     0,     0,     0,     0,     0,     0,  1696,
       0,     0,     0,     0,     0,   658,     0,   644,     0,     0,
       0,     0,     0,     0,     0,   646,     0,     0,     0,     0,
      94,     0,  -353,   645,     0,     0,     0,     0,     0,     0,
       0,  1697,     0,     0,     0,     0,     0,     0,     0, -1818,
    1698,     0,     0,     0,     0,     0,     0,     0,   659,   660,
     661,     0,     0,  1699,     0,     0,     0,   648,     0,     0,
       0,     0,   662,     0,     0,   646,     0,     0,   650,   663,
       0,     0,     0,     0,     0,     0,     0,   963,     0,     0,
     961,   651,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,     0,  1700,     0,     0,     0,   962,     0,     0,
       0,     0,     0,     0,     0,     0,  1701,   648,     0,     0,
       0,     0,     0,     0,     0,   649,     0,     0,   650,     0,
       0,   964,     0,     0,     0,     0,     0,   965,     0,   966,
       0,   651,   757,  1702,   967,   968,   969,     0,     0,     0,
     970,     0,   758,     0,     0,   655,   656,   657,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1703,
       0,     0,     0,     0,     0,     0,  1704,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   971,
       0,     0,     0,  1705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   654,     0,   655,   656,   657,   972,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,   659,   660,   661,     0,     0,
       0,     0,   759,     0,     0,     0,     0,     0,     0,     0,
       0,   961,     0,     0,  1706,     0,     0,     0,     0,  -601,
       0,     0,     0,   964,  1707,     0,     0,     0,   962,   965,
       0,   966,     0,   973,   757,     0,   967,   968,   969,     0,
       0,  1708,   970,     0,   758,   659,   660,   661,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   662,
       0,     0,     0,     0,     0,  1709,   663,     0,     0,     0,
       0,     0,   760,     0,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,   974,   975,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     972,     0,     0,     0,  1394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   976,   961,   761,     0,   977,   978,
       0,     0,     0,     0,   759,     0,   979,     0,     0,     0,
     963,   961,   962,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,   980,     0,   962,     0,
       0,   981,     0,   961,     0,   973,     0,     0,   982,     0,
     137,     0,     0,     0,     0,     0,   762,     0,     0,     0,
     962,     0,     0,     0,   964,     0,     0,     0,     0,     0,
     965,     0,   966,     0,     0,   757,     0,   967,   968,   969,
       0,     0,     0,   970,   760,   758,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   974,   975,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1413,     0,     0,     0,
       0,     0,   971,     0,   963,     0,   976,     0,   761,     0,
     977,   978,     0,     0,     0,   754,     0,     0,   979,     0,
     963,   972,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,   980,     0,
       0,     0,   963,   981,     0,   759,     0,     0,   964,     0,
     982,     0,   137,   754,   965,     0,   966,     0,   762,   757,
       0,   967,   968,   969,   964,     0,     0,   970,     0,   758,
     965,     0,   966,     0,     0,   757,   973,   967,   968,   969,
       0,     0,     0,   970,     0,   758,   964,     0,     0,     0,
       0,     0,   965,     0,   966,     0,     0,   757,     0,   967,
     968,   969,     0,     0,     0,   970,   971,   758,     0,     0,
       0,     0,     0,     0,     0,   760,     0,     0,     0,     0,
       0,     0,   971,     0,     0,   972,     0,   974,   975,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   972,     0,     0,   971,     0,     0,  1949,     0,   759,
       0,     0,     0,     0,     0,     0,   961,   976,     0,   761,
       0,   977,   978,   972,     0,   759,     0,     0,     0,   979,
       0,     0,     0,   962,     0,     0,     0,     0,     0,     0,
     973,     0,     0,     0,     0,     0,     0,   759,     0,   980,
       0,     0,     0,     0,   981,     0,   973,     0,     0,     0,
       0,   982,     0,   137,     0,     0,     0,     0,     0,   762,
       0,     0,     0,     0,  2667,     0,     0,     0,   973,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   974,   975,     0,     0,   760,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   974,   975,     0,
       0,     0,     0,     0,     0,     0,     0,   760,     0,     0,
       0,   976,     0,   761,     0,   977,   978,     0,     0,   974,
     975,     0,     0,   979,     0,   963,     0,     0,     0,   761,
       0,   977,     0,     0,     0,     0,   754,     0,     0,   979,
       0,     0,     0,   980,     0,     0,     0,     0,   981,     0,
       0,   761,     0,     0,     0,   982,     0,   137,     0,   980,
       0,   979,     0,   762,   981,     0,     0,     0,     0,   964,
       0,   982,     0,   137,     0,   965,     0,   966,     0,   762,
     757,   980,   967,   968,   969,     0,   981,     0,   970,     0,
     758,     0,     0,   982,     0,   137,     0,     0,     0,     0,
       0,   762,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     759,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   973,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   974,   975,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   761,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   979,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   980,     0,     0,     0,     0,   981,
       0,     0,     0,     0,     0,     0,   982,     0,   137,     0,
       0,     0,     0,     0,   762
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-2171))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   181,   105,   366,   593,   116,   663,   449,   111,   709,
     393,  1109,   395,   103,   687,   105,  1214,  1136,   719,  1195,
     158,   111,   792,   847,   785,  1576,  1566,  1430,   793,   209,
    1430,  1430,   135,  1107,  1430,  1430,  1430,  1471,   652,  1355,
     403,   424,  1112,  1582,   596,   135,  1122,  1114,  1246,  1520,
    1365,   434,  1975,  1812,  1103,  1122,  2009,  1253,     1,    53,
    1136,    17,  1895,   792,     9,     9,    60,    30,  1239,  1136,
      56,    57,    58,   746,     1,   700,  1172,     1,    64,  1511,
       9,   184,  1744,     9,    48,    57,    55,  1920,   364,   850,
    1186,  1452,    96,     0,    31,     1,  1364,    22,  2042,    86,
       0,    64,    57,    66,   124,    96,    27,    17,   114,   123,
     123,  1307,   141,    99,   100,   175,   102,   225,    31,   172,
     308,   107,   108,    57,   797,   107,   129,  1101,  1444,   152,
     116,    57,  1672,   165,    49,  1109,  1110,    49,   176,   277,
     251,   755,   756,  1241,  1505,  1119,  1257,   133,   176,   232,
     256,    26,  1126,  1127,   237,     1,    39,   203,     6,   174,
    1779,   203,   232,   241,  1360,   232,   159,   161,    21,    63,
      72,  1145,  1146,    49,   160,    87,    21,   308,  1494,    49,
    1229,   129,    49,    87,   295,   234,    57,   244,   274,   369,
     256,  2144,  1960,   807,   115,    64,   252,    66,   213,   242,
     161,   218,  1821,   124,   256,   191,   976,   977,   978,   308,
      70,   203,  1573,   838,   410,    61,   256,   203,  1285,   542,
     354,   218,   196,   187,   218,   219,  1337,   997,   252,  1296,
     113,   138,   262,   752,   256,   142,   124,   244,   138,  1987,
    2410,   177,   142,    89,    90,   232,  1157,   256,   977,    57,
     256,   177,   125,  1872,   256,   244,   367,   287,  1125,   582,
     256,   394,   106,   249,   445,    70,     0,   271,   997,   171,
    1137,   257,   116,  1634,    92,   199,  1187,  1353,   272,   410,
     476,   462,   256,   231,   241,   451,  1353,   129,   282,   252,
    1357,   287,   615,   200,   346,   161,   170,   314,   171,  1839,
     200,   237,   388,  1277,   240,    70,    70,   232,    22,   306,
    1929,   256,   301,   832,  2484,   241,   504,   340,   451,   418,
    1515,   196,   456,  1874,  2157,     9,    70,   110,   289,  1002,
    1645,   335,  1102,   389,  1308,   387,  1651,   203,  2000,   392,
     443,   384,   445,   291,  1919,   476,   457,   274,   397,   452,
     964,   225,   228,   410,   237,   445,   423,     9,   204,   233,
    1555,   169,   452,    61,   416,   389,   469,     6,   331,   472,
     473,   792,   475,  1102,  1845,   478,   479,   363,  1452,   469,
     228,   451,     9,  1854,   290,  1580,   232,  1157,   309,   497,
     468,    89,    90,  1367,  1164,  1165,  1166,  2016,   504,  1831,
     256,   447,  1834,   410,  1765,   391,   312,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,   223,   402,  1187,   421,   353,
     462,   504,   451,   289,   410,   411,   370,   413,   414,   461,
      57,  1505,   452,   419,   341,  1164,  1165,  1166,   504,  2187,
    1510,   341,   357,   317,   504,   357,   503,    56,  1177,  1178,
     436,  1124,   354,   357,    63,  1184,  1008,  1009,   510,   452,
     308,   388,   331,   316,   504,   256,   504,   453,   482,   482,
     462,   574,   575,   503,     6,   321,   504,   501,  1452,   590,
    1591,   504,   504,   503,   574,   575,   597,   357,  1253,   504,
     357,   446,     6,   596,  1570,   504,   125,    70,   504,  1573,
     504,   465,   504,  1570,  1553,  1773,   376,   401,  1823,   376,
     376,   468,   499,   504,   153,  2459,  2460,  1491,   232,   402,
       6,   503,   504,  1694,   451,   462,   802,   451,   497,  2191,
    1504,  1505,   442,   505,   232,  1584,   647,   159,   398,   503,
     503,  1608,   468,   964,   451,   501,   532,   365,     6,   462,
     653,   451,   496,  2128,   456,   976,   977,   978,    32,   504,
    1634,   504,  1760,  2331,   550,  1661,   552,  1763,  1542,   555,
     556,  1196,   558,   212,  2113,   504,   997,  2410,   572,   504,
    2199,   451,   503,   498,   451,   212,   498,   458,   448,  1784,
     188,   123,   463,   398,   498,  1360,  1791,   504,   504,  1573,
     453,   587,  1216,   287,   504,   451,   592,    34,   453,   451,
     604,   464,   460,   599,   241,   503,   504,   256,   436,   464,
    2239,  2081,  2241,   321,  2056,  2384,   203,   266,   498,   256,
     504,   498,   271,   398,   398,   287,   110,   503,  1612,   266,
     142,   453,   450,   448,  1344,   159,     9,  1842,   504,  1623,
     458,   459,  1626,  2272,   398,   463,   767,   837,   441,   268,
    1634,   772,   504,   446,   256,   349,  2444,   262,   290,   328,
      32,   293,   200,     0,   777,   778,   662,  2630,   229,   790,
     212,  1102,   229,   448,   448,     6,  2305,  2306,  2049,   501,
    2051,  1765,   795,   330,  2462,    33,   330,   349,   212,   256,
     256,  1768,  1897,  1124,   448,  2628,   406,   346,  1478,  1130,
       9,   357,   271,   504,   274,  1123,  1481,   703,   347,   346,
     706,   785,  1771,  1106,   256,  1108,   212,   271,   451,  2090,
    1109,   340,  2500,  2501,   266,   157,  1157,  2052,   199,   420,
    1440,  1149,   256,  1164,  1165,  1166,  1167,    30,  1131,  1478,
    1133,  1172,   266,   451,   212,  1138,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,   362,  1186,  1187,  1146,  2451,  1152,
     256,   262,   329,   402,  2542,  2070,   476,   416,  2546,  2547,
     266,    64,   256,    66,   212,  2146,   850,   396,  2259,   416,
     385,   351,   401,   353,  1870,  1216,   287,  1567,   256,   376,
    1995,  2261,  2262,  1870,  1871,   965,   966,  2575,   266,   231,
     153,   138,   972,   341,   346,   142,  2011,  1971,  1239,   370,
       6,   460,   256,   370,  2507,   398,  2604,   406,   256,   167,
     452,  1445,   346,   460,   406,  2030,  1990,  1991,   266,   341,
    1994,   468,   451,  2159,   503,  2613,   451,  2466,  2467,   212,
    2401,  1616,   498,  2148,   281,   282,   283,  1955,  1472,  1559,
     346,  1244,   323,   324,  2059,   504,   503,   504,  2063,   503,
     292,   510,  1255,   200,  1426,   448,   557,   504,   422,   340,
     424,  2035,   257,   510,   416,   458,  2040,   446,   346,  1297,
     463,   212,   203,   256,   256,   504,  1666,   476,    64,   504,
      66,  1322,   416,   266,   476,  1008,  1009,  1018,   342,  2311,
    2105,  2313,   504,   212,   446,     9,  2625,   344,   346,  1592,
      56,   170,  2041,  2042,   216,  2476,   256,    63,   460,   267,
     416,     9,    27,   394,  1908,   256,  2396,  1666,   452,  1639,
      56,   271,    31,    59,   236,   266,   460,    63,   504,   307,
     482,   309,  2661,   411,   510,   212,    50,   256,   416,   122,
     446,  1498,  1499,  1500,  1501,  1373,   406,   266,  2263,   252,
     262,    28,   504,  1134,   460,  2049,   225,  2051,   510,    57,
     117,   118,   119,   346,   233,    56,  2525,  2057,   416,   175,
     504,   321,    63,  1154,  2522,   287,   510,  1670,  1763,   256,
    1103,  2196,   460,    92,  1107,  2159,   317,  2202,   256,   266,
     337,  1114,  1115,   406,   341,  2213,  2090,  2212,   504,  1122,
     115,  2088,  1125,   195,   510,   346,   212,  1130,  2430,  1132,
      84,  1134,  1135,  1136,  1137,     1,   476,   454,   286,   466,
     467,   262,  2112,  1743,   471,   446,   504,   346,   331,  2589,
     453,  1154,   510,   416,   262,   270,  2584,  1478,  2492,   171,
     435,   464,  2601,   207,   208,  1245,   287,  1203,   317,   126,
     256,  1207,  2146,  1233,    40,    41,    42,    43,    44,   287,
     266,   329,   510,   476,   256,  2183,   252,   504,  1677,   346,
    2285,   285,   204,  2288,  2289,   416,   497,   460,    30,   177,
    1483,   238,   246,   247,  2507,   220,  2301,  2507,  2507,    75,
      76,  2507,  2507,  2507,   329,   252,  1296,   416,   212,   494,
    2315,  2316,   292,    38,   709,   212,  1229,  2667,  2102,   504,
     341,    46,   268,   138,   212,   171,    26,   252,   411,   460,
     334,  2681,  2693,  1757,   306,  1248,  1567,   510,   356,   161,
     244,   245,   268,   165,   324,   212,  1339,   451,   379,   416,
     346,   460,   256,   241,  1864,   331,  2140,  2141,   204,   256,
     756,  1592,   266,     8,   504,   107,   338,   351,   256,   266,
     510,  2376,  1285,   504,  1364,   458,   356,  2341,   266,   510,
     463,  2345,   351,  1296,   353,   127,   358,   268,   335,   256,
    1961,  1901,    37,   460,   340,   504,  1389,   792,   500,   266,
     347,   510,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   807,     8,   280,   340,  2420,   755,   756,   481,   394,
     416,   177,   755,   756,   166,   204,   351,  1340,   412,   413,
    1661,   187,    47,   458,   359,  1666,   499,   504,   463,  2014,
    1353,    37,   346,   510,  1357,   212,   188,    62,    54,   346,
     396,  1798,     8,   232,   210,   401,   474,   450,   346,   340,
     451,  2245,   204,  1694,   460,  1812,   459,     1,   807,   262,
     396,   232,   503,   504,   807,   401,  1466,    11,  1391,   346,
    1904,    37,  1655,    89,   240,   503,   211,   102,   187,   256,
     437,  1391,  2456,  2457,   287,   256,   256,   262,  2609,   266,
     106,   455,  2386,   457,  2388,   451,  2492,   503,   504,   451,
     116,   210,   416,  1426,   510,   396,  2627,   451,   243,   416,
     401,  2032,   287,   504,    58,    13,    14,   187,   416,     9,
    2459,  2460,    12,  2462,  2017,    15,    16,   423,  2172,  1452,
     265,    53,    54,   232,    32,   187,   307,  2555,   309,   416,
     210,   405,   419,   420,   330,   351,   460,   353,  2138,   394,
    1959,  2071,    96,   460,    98,   405,   100,   343,   210,   451,
     451,    16,   460,   453,   108,   216,   217,    89,   504,   346,
     468,   976,   977,   978,   464,  1575,  2010,  2070,    33,   351,
     448,   353,  1505,   318,   106,   236,   458,    42,   340,  2138,
     458,   463,   997,  2511,   116,   463,   510,   451,  1399,  1599,
     448,    11,  1403,   510,   248,   249,   504,   232,   451,  1410,
     458,   262,   510,  2407,   239,   463,     2,   156,  1424,   158,
     164,     7,  1622,  1429,  1430,   250,  1432,    24,    25,   451,
    1553,   448,  2152,   510,    12,   449,   287,    15,    16,   416,
      57,   458,  1720,   378,   458,   449,   463,  1570,    58,   463,
    1573,  1609,  1730,  1731,   458,  2148,  1734,   551,   473,   463,
     475,  1584,   556,   478,   485,   486,   487,   488,    65,   156,
      67,   158,    69,  1876,  2468,  1181,  1182,  1183,  2472,  2473,
     218,  2602,  2603,   460,   173,  1608,    96,   252,    98,   254,
     100,   485,   486,   487,   488,  1100,   451,  1102,   108,   252,
    1105,   254,    96,    97,  1109,  1636,   103,   104,   105,   451,
    2631,  1634,   504,   257,  1658,  1659,  1660,    68,   504,  1124,
    1664,   299,   300,  1667,  1668,  1130,   351,   352,   252,  2650,
     254,  1179,  1180,   510,  1657,    65,   451,    67,   473,   504,
     976,   366,   978,   368,  1165,  1166,  1151,  1657,  1153,   340,
     451,   504,  1157,   451,   164,   256,   153,   301,   155,  1164,
    1165,  1166,  1167,   256,   468,   162,   199,  1172,   165,  1700,
    2263,  2692,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
     504,  1186,  1187,   485,   486,   487,   488,   277,   278,   442,
    1721,   400,   623,   624,   625,   626,   401,   410,    63,   321,
      59,   232,   256,   325,   326,   451,   401,   328,   256,   504,
    1215,   301,   302,   229,  1620,    26,   226,   451,   451,   107,
     451,   312,   256,   272,   256,   454,   451,    23,   102,   451,
    2092,  2093,   188,   437,  1239,   122,  1241,   454,  1761,    17,
      86,   504,  1765,   451,   366,  1768,   390,   257,  1771,   500,
       4,   394,   503,   272,   351,   252,   401,   254,    56,   423,
     382,   383,   402,   503,   262,    19,    39,   451,   237,  1675,
    1676,   402,   504,   498,   271,    29,  1876,   419,   331,   506,
    1686,   504,   310,   504,   394,   261,   316,  1693,  2091,   433,
     451,   301,     7,   451,   304,   394,   255,  2138,  1821,   277,
     278,  2084,   451,   504,   503,   451,   394,   451,   366,    63,
     451,    85,   124,    85,   451,   432,  1722,  1322,   451,   394,
     389,    22,   306,   301,   302,   501,   309,  1927,   451,   394,
     504,   204,   504,     9,   501,   451,  1936,  1937,   384,  1344,
     499,     6,   232,   446,     9,   254,   218,  1870,  1871,  1872,
     504,  1909,  1910,  1911,  1912,  1913,  1914,  1915,  1916,   369,
     504,   122,   510,   446,   442,  1370,   462,    26,   504,   306,
     447,   400,   410,   348,  1780,   504,   462,   445,   442,   256,
     390,   451,   336,   376,    49,   504,   399,   114,   451,   462,
     462,   462,   169,  1799,   187,   462,   462,   504,   256,  1805,
     462,   462,   462,   462,   451,   415,  1929,   417,   451,   451,
     446,   309,  2602,  2603,   403,    30,     9,    82,   453,   504,
     504,   130,    87,   433,   504,   196,   131,   133,   446,   132,
     134,  1954,   351,   386,    99,  1440,   135,   137,   136,   101,
     497,  2631,   441,  1966,  1954,   446,   443,   462,  1971,   140,
      49,   143,   404,  1984,   445,   442,   196,   445,   439,   144,
    2650,   145,   499,   146,   271,    31,   220,  1990,  1991,   147,
      49,  1994,   149,  1478,   148,   196,   112,   150,   220,   151,
     448,   448,   448,   448,   448,   448,   446,   114,   410,    82,
     451,  2091,   312,  2016,   504,   109,   493,   446,   252,   223,
     197,   203,  2692,  2103,   339,   376,    99,   504,   262,   256,
    2041,  2042,  2035,   272,   231,   294,   298,  2040,  2041,  2042,
    2597,   165,   484,   128,   501,   175,  2049,   501,  2051,   365,
     446,   168,   228,   129,  1940,   446,   201,    49,   196,  2616,
     228,  2550,   176,   204,   299,    56,   504,   212,   204,   451,
     272,   508,  1958,   165,  1559,   237,   423,   252,   299,   509,
     276,   315,  1567,   446,   446,  2088,   320,  2090,  1974,   295,
    1976,  2580,   380,   362,  1980,    30,    17,   203,  1583,   203,
     245,   442,  1988,   128,   139,   365,   251,  1592,   253,   446,
      49,   256,   203,   258,   259,   260,     8,   351,  1603,   264,
     141,   266,   196,   129,   501,   359,   271,   501,   201,   423,
     451,   203,   446,     9,     7,   504,   256,   503,   372,   212,
      82,   203,   297,  2146,  1629,   294,    49,   503,   498,   498,
     188,   310,   262,   314,  1639,   461,  2159,    99,   303,   291,
    2163,   330,   313,   308,   113,   436,    47,   401,   411,   203,
     404,   203,   294,  2163,   361,   102,  1661,   322,   412,    49,
     380,  1666,   262,   256,   237,   258,   259,   260,   361,   423,
     492,   264,  2475,   266,   296,    95,   292,  2083,    56,     8,
      49,   346,   110,   337,   262,   262,    45,   456,    35,  1694,
     262,    38,   357,   451,   109,   481,   337,   451,    45,    46,
     454,  1706,   210,   451,  1709,    64,    65,    66,    67,   340,
     303,   221,   377,   107,   209,   119,  2239,   501,  2241,   367,
    2523,   196,   313,    49,   418,   306,   321,   337,     7,   709,
      46,    92,    26,   201,   148,   425,   127,    75,  1743,   201,
     206,   221,   238,   150,    91,   410,  2269,   177,   575,  2272,
     610,   416,   517,   346,  1759,   286,   409,   424,  1017,  2269,
     497,  2602,  2603,   428,   429,  1430,   778,  2600,  2665,  1868,
    2161,   797,   745,  2644,  2677,  2613,   850,  1026,  1212,  2184,
    2184,   788,  2054,  2306,   377,  1815,  1733,  1732,  2370,  1767,
    2631,  1229,  1464,  2052,   256,   460,   258,   259,   260,  1466,
    1491,  2237,   264,  2326,  1510,   470,  1513,  1834,  2056,  2650,
    1281,   476,   792,   160,  2255,  1563,  2326,  1556,  2341,  2079,
    1317,  1862,  2345,   416,  2091,   490,  2101,  1322,  1574,  1937,
     495,  1604,  1888,   498,  2115,   428,   429,   502,  1351,   504,
    1917,   303,   189,  1353,  1137,   510,  1367,  1936,  2309,  2141,
     209,  2692,  1936,  2661,  2319,  1649,  1542,  2314,  2410,  1864,
    1865,  1340,  1460,  2386,   211,  2388,   299,   460,   152,   694,
    1904,  2134,   270,  2134,   242,   981,   235,   470,  2134,  2134,
    2533,  2404,   750,   416,   509,  2398,  2579,   574,  1893,  1924,
     215,  2068,  1867,   252,   710,   254,  1901,   490,  2304,   554,
    1566,  2604,   495,    -1,    -1,  2708,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,   377,    -1,   510,   265,    -1,
      -1,    -1,    -1,  1928,    -1,    -1,   285,    -1,  2459,  2460,
    1935,  1936,    -1,  2456,  2457,    -1,  2459,  2460,    -1,  2462,
      -1,    -1,    -1,  2349,    -1,    -1,   305,  2353,    -1,    -1,
    1955,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1965,    -1,    -1,    -1,    -1,    -1,   428,   429,   327,    -1,
      -1,   318,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   964,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   976,   977,   978,  2522,
      -1,    -1,    -1,  2409,    32,    -1,    -1,    35,   470,    -1,
      38,    -1,  2017,    -1,    -1,    -1,    -1,   997,    46,    -1,
      -1,  2552,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,   378,    -1,   495,    -1,    -1,  2442,  2443,    -1,    -1,
     502,    -1,   504,    -1,   391,    -1,   405,    -1,    -1,    -1,
      -1,    -1,  2458,    -1,    -1,   414,  2061,    -1,    -1,    -1,
      -1,  2584,    -1,    91,    -1,  2070,  2071,    -1,  2474,    -1,
      -1,    -1,   431,    -1,  2079,    -1,    -1,  2608,    -1,    -1,
      -1,  2612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,  2499,    -1,    -1,  2101,    35,  2504,  2505,
      38,    -1,  2625,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,  2524,    -1,
      -1,    -1,  1102,    -1,    -1,  2130,   473,  1107,    -1,    -1,
      -1,    -1,   491,  2138,  1114,    -1,    -1,    -1,  2661,   498,
     499,    -1,  1122,  2148,    -1,    -1,    -1,  2152,  2554,    -1,
      -1,  2557,  2558,    91,    -1,    -1,  1136,    -1,    -1,    -1,
      -1,   189,  2685,    -1,    -1,  2696,    -1,    -1,    -1,  2174,
     198,    -1,    -1,    -1,    -1,    -1,    -1,  1157,  2183,    -1,
      -1,    -1,    -1,   211,  1164,  1165,  1166,  1167,    -1,    -1,
      -1,    -1,  1172,  2599,    -1,    -1,    -1,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,    -1,  1186,  1187,    -1,    -1,
      -1,    -1,    -1,  2218,    -1,   243,    -1,    -1,    -1,    -1,
      -1,     1,   160,     3,    -1,     5,    -1,   165,    -1,    -1,
      10,    -1,    -1,    -1,    -1,   263,  1216,   265,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,  2263,    -1,
     288,    -1,     6,    -1,    -1,     9,    -1,    -1,  1248,    -1,
      -1,    51,    52,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     318,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1285,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1296,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    82,   119,
      -1,   121,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,
     378,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   391,  1344,    -1,    -1,   395,    -1,    -1,
      -1,    -1,   152,  1353,  2379,    -1,    -1,  1357,    -1,    -1,
     318,    -1,    -1,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   444,  2422,    -1,    -1,
      -1,    -1,   202,    -1,  2429,   205,   206,  2432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
     378,    -1,   222,    -1,   224,   473,    -1,   227,    -1,    -1,
      -1,    -1,    -1,   391,    -1,   483,    -1,   201,    -1,    -1,
    1440,   489,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,  1452,    -1,    -1,    -1,  2481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
    2495,    -1,    -1,   273,    -1,   275,    -1,    -1,  1478,    -1,
      -1,   245,    -1,    -1,    -1,   285,  2511,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,  1505,    -1,   271,    -1,    -1,
      -1,   311,    -1,    -1,    -1,   473,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2559,    -1,    -1,    -1,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,  1559,
     360,    -1,    -1,    -1,    -1,    -1,    -1,  1567,    -1,    -1,
    1570,    -1,    -1,  1573,   374,   375,    -1,  2602,  2603,    -1,
      -1,   381,   346,    -1,    -1,   385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   393,  2619,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   403,    -1,    -1,  2631,    -1,  1608,    -1,
      -1,    -1,   412,   377,    -1,    -1,    -1,    -1,  2643,  2644,
      -1,   421,    -1,    -1,    -1,  2650,   426,   427,    -1,    -1,
     430,    -1,   432,    -1,  1634,    -1,    -1,    -1,   438,  1639,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,   416,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1661,    -1,  2688,   428,   429,  1666,  2692,    -1,   469,
      99,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,
      -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,
     464,    -1,    -1,    -1,    -1,    -1,   470,   507,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,  1743,    -1,    -1,   510,    -1,    -1,     1,
      -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,  1761,    -1,    -1,    -1,  1765,    18,    -1,  1768,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,  1821,    74,    -1,    -1,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    88,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,  1864,  1865,    -1,   119,    -1,   121,
    1870,  1871,  1872,    -1,   303,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,  1901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,   168,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1929,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,   377,    -1,
     202,    -1,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,    -1,   224,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2016,   269,    -1,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,   285,    -1,    -1,    -1,    -1,    -1,   291,
     292,   470,   294,   295,   296,   297,    -1,    -1,    -1,  2049,
      -1,  2051,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,  2071,   324,   502,    -1,   504,    -1,    -1,    -1,  2079,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,  2088,    -1,
    2090,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,
      -1,     1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,   374,   375,    -1,    -1,    -1,    -1,    18,   381,
      -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,  2138,    -1,
      -1,   393,    -1,    -1,    -1,    -1,  2146,    -1,    -1,    -1,
      -1,   403,  2152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     412,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      60,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    71,    -1,    -1,    74,    -1,   438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,    -1,    -1,    -1,   469,    10,    -1,
      -1,   111,    -1,   475,    -1,    -1,    18,    -1,   480,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2239,
      -1,  2241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    51,
      52,    -1,   152,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,  2272,   163,    -1,    -1,    -1,    -1,   168,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,  2306,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,   205,   206,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   215,    -1,   119,    -1,   121,
      -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,   269,
      -1,    -1,    -1,   273,    -1,   275,  2386,    -1,  2388,    -1,
      -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,    -1,   224,    -1,   324,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,   273,    -1,   275,   374,   375,    -1,    -1,    -1,    -1,
      -1,   381,    -1,   285,    -1,   385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,   311,
      -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   324,    -1,    -1,    -1,   426,   427,    -1,    -1,
     430,    -1,   432,    -1,    -1,    -1,    -1,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,
      -1,    -1,   374,   375,    -1,   475,    -1,    -1,    -1,   381,
     480,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   393,  2602,  2603,    -1,    -1,    -1,    -1,     3,    -1,
       5,   403,    -1,    -1,    -1,    10,    -1,   507,    -1,    -1,
     412,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,   421,
      -1,  2631,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,
    2650,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,   469,    -1,    74,
      -1,    -1,    82,   475,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,  2692,    88,    -1,    -1,    -1,    -1,     6,    99,
      -1,     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,   507,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,   168,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   201,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
     205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,   224,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   256,    -1,   258,   259,
     260,   169,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     285,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,   207,
     208,    -1,    -1,   303,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
      -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,   349,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,     6,   360,    -1,     9,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,   284,   377,    20,    -1,
     375,    -1,   290,    -1,    -1,   293,   381,    -1,    -1,    -1,
     385,    -1,    -1,   301,    -1,   303,    -1,    -1,   393,    -1,
     308,    -1,    -1,    -1,    -1,   313,    -1,    -1,   403,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,   332,    -1,   421,    -1,   428,   429,
      -1,   426,   427,    -1,    -1,   430,    -1,   432,   346,   439,
      82,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   451,    99,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,     9,    -1,    -1,   377,
     470,    -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,
     475,   481,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,   499,
      -1,    -1,   502,   503,   504,    -1,    -1,    -1,   416,    -1,
      -1,    -1,   507,    -1,    -1,    -1,    -1,   159,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
     448,    -1,   450,    -1,   452,    -1,    -1,   455,    -1,   457,
     458,   459,   460,    -1,   462,   463,    99,    -1,    -1,   201,
      -1,    -1,   470,    -1,    -1,   207,   208,    -1,    -1,   112,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,     6,   495,    -1,     9,
      -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,   245,   246,   247,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   284,    -1,    -1,    -1,    -1,    -1,   290,    -1,
      -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,   201,   301,
      -1,   303,    82,    -1,    -1,    -1,   308,    -1,    -1,   212,
      -1,   313,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,
     322,    -1,    -1,     6,    -1,   228,     9,    -1,    -1,    -1,
     332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,   346,    -1,    -1,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,   416,    -1,    99,    -1,    -1,   322,
      -1,   201,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,     6,   212,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,   448,    -1,   450,    -1,
     452,    -1,    -1,   455,    -1,   457,   458,   459,   460,    -1,
     462,   463,    -1,    -1,    -1,   245,    -1,    -1,   470,    -1,
      -1,   251,    -1,   253,   377,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,   490,    -1,
      -1,   271,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    82,   510,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,   303,    99,   428,   429,    -1,     6,   212,
      -1,     9,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,   346,   470,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,   490,   271,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,   377,    -1,   502,
      -1,   504,    -1,    -1,    82,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
     303,    99,    -1,    -1,    -1,    -1,   201,    -1,     6,    -1,
      -1,     9,    -1,    -1,    -1,    -1,   416,   212,    -1,   322,
      -1,    -1,    -1,    -1,     6,    -1,    -1,     9,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,
     460,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
     470,   266,    -1,    -1,   377,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      82,    99,   502,   201,   504,    -1,    -1,    -1,   303,    -1,
     510,    -1,    -1,   416,   212,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   346,    -1,   251,    -1,   253,    -1,   460,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,   470,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,   165,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,   201,    -1,   303,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   201,
      -1,   416,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   346,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,   245,    -1,   460,   264,    -1,   266,   251,
      -1,   253,    -1,   271,   256,   470,   258,   259,   260,   377,
       6,    -1,   264,     9,   266,    -1,    -1,    -1,    -1,   271,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,   303,    -1,   502,     6,   504,
      -1,     9,    -1,    -1,    -1,   510,    -1,    -1,   416,    -1,
      -1,   303,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,   460,    -1,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    99,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,   377,    -1,   495,    -1,    -1,
      -1,    99,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,     6,   416,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,   446,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,   201,    -1,    -1,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,   470,    -1,
      -1,    -1,   490,    82,    -1,    -1,    -1,   495,   196,    -1,
      -1,    -1,    -1,   201,   502,    -1,   504,    -1,   490,    -1,
      99,    -1,   510,   495,   212,    -1,    -1,    -1,    -1,   245,
     502,     6,   504,    -1,     9,   251,    -1,   253,   510,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,    -1,    -1,    -1,   271,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,   212,   322,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,
      -1,   377,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,   377,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,   201,    -1,   416,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,   212,    -1,     6,
     428,   429,     9,   322,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,   484,    -1,
     245,    -1,   460,    -1,   490,    -1,   251,    -1,   253,   495,
      -1,   256,   470,   258,   259,   260,   502,    -1,   504,   264,
      -1,   266,    -1,    -1,   510,    -1,   271,    -1,   377,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    -1,   502,    82,   504,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,   410,    99,    -1,    -1,   201,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   322,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,   460,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,
     256,   470,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,   377,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,   201,    -1,    -1,   303,    -1,    -1,
      -1,   416,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
     346,    -1,    -1,    -1,   251,   460,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,   470,    -1,   264,    -1,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,    -1,   510,   303,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,     1,    -1,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    32,    -1,    -1,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,    64,    -1,    66,    -1,    -1,
      -1,    -1,    -1,   470,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   119,    -1,    -1,    -1,   305,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,
     319,    -1,    -1,    -1,    -1,    99,    -1,    -1,   327,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,   345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,    -1,
      -1,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,   405,    -1,   407,   408,
     409,    -1,    -1,    -1,    -1,   232,   190,    -1,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,   477,   478,
     479,    -1,   256,    -1,   258,   259,   260,    -1,   305,    -1,
     264,    -1,   491,    -1,    -1,    -1,    -1,    -1,   497,   498,
      -1,    -1,   319,    -1,    -1,   504,    -1,    -1,    -1,    -1,
     327,    -1,    21,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    36,    -1,   303,
      39,    40,    41,    42,    43,    44,    45,    -1,   355,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,
     407,   408,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   468,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
     477,   478,   479,    -1,    -1,   439,    -1,    -1,    -1,   178,
     179,   180,   181,   182,   491,    -1,   185,   186,    -1,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,   481,    -1,    -1,
     219,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,   232,    -1,   499,   235,    -1,   502,   503,
     504,    73,   241,    75,    76,    77,    78,    79,    80,    81,
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
      -1,   322,    -1,    -1,   303,    -1,    -1,   448,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    82,   458,    -1,   460,
      -1,   462,   463,   322,    -1,   346,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,   377,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,   377,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,   458,    -1,   460,    -1,   462,   463,    -1,    -1,   428,
     429,    -1,    -1,   470,    -1,   201,    -1,    -1,    -1,   460,
      -1,   462,    -1,    -1,    -1,    -1,   212,    -1,    -1,   470,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,   460,    -1,    -1,    -1,   502,    -1,   504,    -1,   490,
      -1,   470,    -1,   510,   495,    -1,    -1,    -1,    -1,   245,
      -1,   502,    -1,   504,    -1,   251,    -1,   253,    -1,   510,
     256,   490,   258,   259,   260,    -1,   495,    -1,   264,    -1,
     266,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
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
     603,   535,   523,   451,   232,   537,  1271,   504,  1191,  1191,
     423,   405,  1289,  1271,  1271,  1271,   394,  1191,   405,   451,
     451,  1271,   451,   451,    57,  1259,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1271,  1271,  1271,   504,  1185,  1217,
      68,  1185,   451,  1271,  1271,   549,   560,  1185,   545,   504,
     587,   588,   589,  1192,   256,   307,   309,   573,   575,  1035,
    1220,  1271,   451,   504,   451,   606,   539,   340,  1286,  1271,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1223,
    1185,   256,   218,   306,  1309,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1258,  1319,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1192,  1272,  1035,   232,   423,  1283,  1271,
      96,  1191,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1302,  1217,   400,   401,   410,
      63,  1271,   451,   552,   451,   504,   551,    59,  1271,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1302,   256,
     590,  1221,  1283,   232,  1191,  1191,   574,   575,   451,     1,
     290,   312,  1244,   274,   388,   641,   642,   643,   644,   646,
     580,    17,   442,  1223,   328,  1271,   401,  1220,   451,  1271,
     504,  1186,   229,    26,   565,   229,   370,   451,   451,   107,
    1221,  1191,   451,   312,  1191,   647,   351,   412,   413,   645,
     529,     1,   451,   643,   581,   583,   256,  1220,   257,   435,
     494,   557,  1186,   256,   272,   608,   454,  1262,    23,  1253,
     102,   651,   451,   582,   583,    57,   505,  1313,   609,   437,
    1295,   188,  1264,   122,   454,   652,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   624,   625,   626,
     627,   628,   631,   632,   633,   634,   635,   636,   637,   639,
    1287,  1303,    86,  1260,   504,  1175,  1176,   451,   394,   653,
     583,   272,  1278,   351,   446,   497,  1299,   401,   402,  1271,
    1258,   113,   237,  1273,  1273,   287,   638,  1220,  1302,   423,
     262,    39,  1256,  1271,   648,   649,  1176,  1176,   451,   172,
     392,   530,   654,   655,   657,  1271,  1273,   125,   171,   614,
     351,   359,   632,  1271,  1271,  1271,  1271,  1253,     9,   287,
     349,   640,  1271,  1278,   402,   504,   649,   331,   650,   506,
     682,   684,   685,     1,  1176,   125,   347,   402,   618,  1271,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1185,  1190,   419,  1185,   504,  1189,   316,  1284,  1284,
     310,  1185,  1271,  1220,   394,   261,   735,   686,   687,   689,
     699,  1236,   451,   656,  1185,   256,   616,  1217,   616,     7,
     616,   616,   256,   615,  1217,    33,   167,   267,   629,   451,
     394,   255,   737,   451,   687,   451,     1,   175,   504,   690,
     691,   504,   658,   124,   452,   503,  1238,  1318,  1262,   503,
     630,   630,   683,   451,   394,   366,   739,   451,   451,   688,
      85,    47,    62,   102,   239,   250,   351,   352,   366,   368,
     451,   498,   659,   660,   662,   666,   667,   670,   671,   677,
     678,   679,   680,  1271,   620,   621,   124,   432,   623,   262,
     385,   684,   736,   451,   394,   389,   784,   701,   692,  1271,
    1260,  1271,   351,   353,  1314,  1314,  1271,  1260,  1271,  1278,
    1271,    22,  1252,   306,   681,  1191,   171,   204,   622,  1185,
    1238,   622,   501,   309,   684,   738,   451,   394,   531,    21,
      36,    39,    40,    41,    42,    43,    44,    45,    73,    75,
      76,    77,    78,    79,    80,    81,   119,   178,   179,   180,
     181,   182,   185,   186,   219,   235,   277,   305,   319,   327,
     330,   343,   355,   363,   405,   407,   408,   409,   434,   477,
     478,   479,   491,   498,   702,   703,   704,   706,   707,   708,
     709,   710,   711,   712,   715,   724,   725,   726,   727,   728,
     733,   734,  1271,  1291,    26,   196,   700,  1254,   204,  1220,
     504,  1271,  1252,   504,  1187,  1188,   308,   418,  1310,  1190,
    1220,   499,  1271,   174,   213,   504,   668,  1191,   623,     9,
     274,   351,   353,  1312,   684,   740,   451,   337,   798,   801,
     244,   301,   406,   476,  1290,   476,  1290,   476,  1290,   476,
    1290,   476,  1290,   501,  1300,   384,  1288,  1220,  1214,  1217,
    1217,   232,   242,   384,  1274,  1271,  1272,   171,   204,   241,
     468,   504,     9,    50,   212,   244,   245,   256,   266,   346,
     416,   460,   510,   693,  1224,  1225,  1226,   446,   665,  1188,
     254,  1277,   446,  1259,   218,  1266,   504,  1271,  1271,  1202,
    1213,  1214,  1225,  1312,   741,   785,   122,   824,   825,   510,
     446,   716,   462,  1218,  1219,   442,   709,   730,   731,  1224,
      26,   705,   400,  1248,  1248,  1226,   306,  1281,     1,    40,
      41,    42,    43,    44,   178,   179,   180,   181,   182,   183,
     184,   330,   343,   694,   695,   696,   697,   698,   710,   711,
    1214,   694,   447,  1220,    57,   353,   661,   672,  1220,   410,
    1292,   256,   669,  1217,   669,   348,   742,   689,   699,   786,
     787,   788,    55,   497,   802,     1,     3,     5,    10,    18,
      51,    52,    60,    71,    74,    88,   111,   119,   121,   152,
     163,   168,   195,   202,   205,   206,   215,   222,   224,   227,
     269,   273,   275,   285,   311,   324,   349,   350,   360,   374,
     375,   381,   385,   393,   403,   412,   421,   426,   427,   430,
     432,   438,   451,   469,   475,   480,   507,   826,   827,   842,
     847,   851,   856,   871,   874,   878,   882,   883,   884,   889,
     903,   907,   910,   924,   928,   931,   934,   938,   939,   943,
     953,   956,   973,   975,   978,   982,   989,  1001,  1009,  1010,
    1013,  1014,  1018,  1023,  1024,  1032,  1047,  1057,  1066,  1071,
    1078,  1082,  1084,  1087,  1090,  1094,  1121,   826,  1220,   445,
    1297,    82,    99,   201,   245,   251,   253,   258,   259,   260,
     264,   303,   322,   377,   428,   429,   458,   462,   463,   470,
     490,   495,   502,  1163,  1165,  1166,  1167,  1168,  1169,  1170,
    1199,  1213,  1225,  1227,  1228,  1229,  1230,   462,  1219,  1217,
     729,   731,   442,   256,  1258,   694,   451,  1226,    48,   465,
     673,   674,   675,   676,  1302,  1259,   196,   664,  1265,   504,
    1177,     1,   690,   788,   451,   804,   803,   376,   810,     3,
       5,    10,    18,    51,    52,    60,    71,    74,    88,   111,
     119,   121,   128,   130,   131,   132,   133,   134,   135,   136,
     137,   139,   140,   141,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   163,   168,   195,   202,   205,   206,
     215,   222,   224,   227,   269,   273,   275,   285,   311,   324,
     349,   360,   375,   381,   385,   393,   403,   412,   421,   426,
     427,   430,   432,   438,   451,   469,   475,   480,   507,  1249,
     828,   843,   848,   852,   857,   872,   875,   879,   885,   890,
     904,   908,   911,   925,   929,   932,   935,   203,   376,   866,
     927,   940,   944,   954,   957,   974,   976,   979,   399,   983,
     990,  1002,  1011,  1015,  1019,  1025,  1033,  1048,  1058,   256,
     346,   387,   416,   510,  1070,  1072,  1079,   336,  1083,  1085,
     813,  1088,  1091,  1095,  1122,   114,   717,   462,  1232,  1214,
    1225,  1227,  1309,  1309,   462,   462,   462,   462,  1309,  1169,
    1165,  1169,   462,  1232,    70,   398,   448,  1164,   449,   458,
     463,   450,   459,   169,   462,  1231,   462,   462,  1165,   501,
     732,  1301,  1224,  1190,  1190,   187,   665,  1220,   743,   451,
     789,   451,    49,   805,   806,   807,  1257,   805,   504,   451,
     308,   829,   830,  1213,     6,    94,   245,   271,   844,  1170,
    1195,  1196,  1213,  1224,  1227,   849,  1165,  1213,   256,   853,
     854,  1181,  1182,  1183,  1217,   271,   422,   424,   858,   859,
     256,   873,  1204,  1213,   876,  1176,     6,   880,  1171,  1172,
    1194,  1215,  1216,  1217,  1225,   454,   886,  1176,   256,   891,
     892,   894,  1195,  1196,  1204,  1213,   905,  1196,   256,   909,
     453,   464,   912,   913,   914,  1153,  1154,  1155,   199,   323,
     324,   340,   394,   926,   930,  1193,  1194,   933,  1217,   446,
     936,  1298,  1196,  1152,  1153,   945,  1193,   955,  1177,   958,
     959,  1213,  1224,  1227,  1049,  1211,  1212,  1217,    94,   977,
    1196,   980,  1196,   170,   225,   233,   317,   984,   985,   190,
     256,   991,   995,   996,   997,  1181,  1205,  1213,  1217,  1227,
    1302,  1003,  1176,  1012,  1173,  1217,  1016,  1176,  1020,  1173,
       9,  1026,  1174,  1217,   153,   271,  1034,  1037,  1038,  1041,
    1042,  1043,  1044,  1045,  1046,  1178,  1179,  1193,  1210,  1212,
    1217,  1049,  1059,  1176,  1067,   112,  1073,  1074,  1075,  1196,
      94,  1080,  1195,  1086,  1177,   451,   504,   814,   815,   818,
     819,   824,  1089,  1213,  1092,  1176,  1096,  1213,  1123,  1173,
     309,  1282,   718,   719,   448,  1163,  1165,   504,   504,  1165,
    1235,  1235,  1235,  1198,  1213,  1225,  1227,  1234,   504,   448,
    1198,  1233,  1165,   448,  1165,  1166,  1166,  1167,  1167,  1167,
    1165,  1198,  1163,   403,   453,    30,  1255,  1259,     1,   744,
     790,   806,   410,   476,   808,   357,   498,   799,   130,   841,
      30,   832,   833,  1255,   196,  1281,  1213,  1214,  1225,  1227,
     131,   846,   446,   845,  1196,    57,   223,  1239,   854,   446,
    1309,   132,   870,   256,  1205,  1204,  1176,   356,   474,   877,
    1302,  1315,  1281,   133,   881,   159,   452,  1172,  1306,   386,
    1245,  1218,  1219,   887,  1176,   134,   888,  1287,   135,   902,
     165,   893,  1132,  1133,   484,   895,   503,   833,   485,   486,
     487,   488,   136,   906,    49,   228,   497,   860,   137,   923,
      17,   501,   915,   916,   917,   919,    12,    13,    14,    20,
     159,   169,   207,   208,   246,   247,   284,   290,   293,   301,
     308,   313,   332,   448,   450,   452,   455,   457,   458,   459,
     462,   463,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1196,
     101,   927,  1194,  1180,   441,  1296,   946,  1302,  1177,    92,
     365,   436,   960,   961,   963,   964,  1051,   462,  1218,  1196,
     446,   140,   981,    49,   985,   404,   986,   996,   141,   451,
     992,   994,   481,   499,   442,   445,   439,   143,  1008,   285,
     334,  1242,   196,  1124,   144,  1017,  1287,   145,  1022,  1124,
    1174,   146,  1031,   499,  1027,  1202,  1044,  1046,  1193,   446,
    1179,   123,   446,   482,  1036,    31,  1218,   147,  1065,   177,
     237,   240,  1061,   866,  1068,  1302,  1257,   148,  1077,   228,
    1075,  1213,   149,  1081,   196,  1177,   394,   451,   451,   196,
     351,   353,  1093,   150,  1105,   112,  1097,   151,  1128,  1124,
    1185,   220,   721,    27,   115,   720,   448,  1164,   448,   448,
     448,  1164,   448,  1164,   448,   448,   449,   448,   448,   446,
    1271,  1190,   114,   663,   451,    61,    89,    90,   321,   451,
     745,   746,   749,  1271,  1327,    32,    35,    38,    45,    46,
      64,    66,   160,   189,   196,   198,   211,   243,   252,   265,
     305,   318,   345,   371,   378,   395,   446,   456,   473,   497,
     707,   708,   712,   724,   726,   728,   791,   796,   797,  1271,
    1304,  1271,   410,   312,   809,   109,   811,  1202,   197,   836,
     252,   331,   834,   835,  1304,    24,    25,    65,    67,    69,
     103,   104,   105,   153,   155,   162,   165,   252,   254,   443,
     493,   504,   831,  1179,  1305,   152,   340,  1200,  1214,   446,
       6,  1171,  1196,  1217,  1225,   203,   223,  1240,   376,   850,
     339,   855,  1183,   860,   877,   262,   287,  1264,  1214,  1165,
     272,  1246,  1219,  1176,   231,  1148,  1149,   821,   822,   894,
    1196,   294,  1134,    96,   335,   504,  1179,   298,   899,    35,
      38,    45,    46,    91,   160,   189,   211,   265,   318,   378,
     391,   473,   900,   901,   484,   896,  1132,  1132,  1132,  1132,
    1196,  1171,  1196,   861,   914,    21,   453,   464,   920,   921,
    1154,   501,   917,   918,   501,   821,  1298,   232,  1157,   114,
     937,  1181,   128,   821,   941,     9,    12,    15,    16,   277,
     278,   301,   302,   947,   951,   175,  1202,     9,    57,   177,
     241,   468,   967,   968,   969,   962,   963,  1053,  1282,  1318,
     446,  1193,  1171,  1196,   986,  1302,  1175,   821,   168,   998,
    1152,   999,  1000,  1213,  1181,     8,    37,  1126,  1287,  1209,
    1213,  1224,  1227,   228,  1004,  1021,  1302,   129,  1028,  1213,
    1028,   446,   446,  1035,   152,   453,   464,  1196,    49,    38,
      46,   211,   243,   265,   318,   378,   473,  1039,  1040,  1271,
    1060,  1302,  1196,   161,   289,   410,  1196,  1213,   196,  1171,
    1196,   820,  1220,  1202,  1257,   228,  1100,  1125,  1126,  1257,
    1273,  1185,  1231,  1231,  1231,  1198,   241,   468,  1231,   448,
    1165,  1231,  1231,  1224,  1282,  1271,  1271,  1252,   248,   249,
    1276,   758,   204,   176,   747,  1263,  1271,   252,   389,   156,
     158,  1271,  1205,   299,  1279,  1220,    56,  1213,  1213,   204,
    1279,    32,   110,  1220,  1271,   504,   451,   800,   272,   837,
    1279,  1279,   835,   834,  1279,   165,  1129,  1130,   509,   508,
    1202,  1129,   237,   423,   299,   276,   256,  1201,  1214,  1213,
    1281,   411,  1135,  1136,  1218,  1219,  1171,   446,  1241,   850,
    1194,   446,  1181,   865,   866,   380,   362,  1135,  1271,   821,
     295,  1150,   823,   821,  1132,  1271,   252,   389,   156,   158,
    1271,   123,   482,   901,  1132,    96,    97,   897,   837,   203,
    1135,   203,   862,   863,   864,  1257,    17,   442,   922,   316,
     920,  1282,   821,   128,   139,   942,  1298,   365,   948,  1298,
     446,    49,   968,   970,  1202,     9,    57,   241,   468,   965,
     966,  1202,  1054,  1303,   720,   218,   314,  1267,  1193,  1135,
     203,  1175,     9,   287,   349,   987,   379,   988,  1302,   141,
     993,     8,   196,  1004,  1213,   129,  1141,  1143,  1148,   262,
     287,   821,   501,   501,  1029,  1030,  1202,  1201,  1196,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1040,   290,   293,
    1062,  1063,  1064,  1158,  1243,  1148,   244,   410,  1317,   423,
    1294,  1294,  1076,  1302,  1213,  1135,   203,   451,   446,     9,
    1098,  1099,  1237,  1101,  1213,  1076,  1101,  1021,     7,  1250,
     504,   722,   723,  1271,   448,  1185,  1204,  1271,  1252,   256,
     750,  1222,   689,   759,   748,  1213,   510,  1206,  1210,  1220,
    1206,  1271,  1297,  1271,  1271,    32,  1220,   812,   813,  1271,
     503,   838,  1206,  1206,  1206,   821,   294,  1131,  1129,  1245,
    1214,   821,   297,  1137,  1219,  1135,  1203,  1213,  1224,   165,
     461,   868,  1308,     6,   228,   308,   460,   867,  1270,    34,
     281,   282,   283,   344,   466,   467,   471,  1247,   821,   824,
    1206,  1206,  1151,  1208,  1210,  1220,  1151,   503,   898,  1171,
    1172,  1171,  1172,   863,   308,   808,    87,   357,   498,   921,
    1153,   821,  1213,   821,   498,   949,   950,   951,   952,  1296,
     498,  1203,  1202,    49,   971,   966,   188,   971,  1050,  1271,
    1273,   314,  1171,   988,  1284,  1284,   310,   262,   287,  1000,
    1196,   217,  1005,  1302,   821,   291,  1144,   262,  1153,  1152,
    1029,  1158,  1213,  1159,  1160,  1161,  1162,  1165,  1069,  1196,
    1069,   461,  1138,  1139,   330,  1245,  1171,   816,  1203,   313,
    1202,   113,  1102,   436,  1104,   157,   292,  1127,  1145,  1146,
    1147,  1148,   321,  1179,  1206,   723,  1184,  1185,   751,   252,
     254,  1311,   504,   690,  1213,   270,   329,   458,   463,   792,
     793,   794,  1204,   792,   793,   795,   813,    47,    32,    35,
      38,    46,    91,   189,   198,   211,   243,   263,   265,   288,
     318,   345,   371,   378,   391,   395,   444,   473,   483,   489,
     839,   840,  1129,   821,  1135,   821,   294,   869,   821,  1281,
    1213,   252,   254,  1316,   900,  1135,   361,  1135,   361,  1196,
     950,   102,  1261,  1298,   971,   971,  1203,     8,    37,   972,
     225,   497,  1055,  1185,  1052,  1135,   380,    49,   262,   237,
    1006,   216,   236,   262,   287,   500,   821,   821,   821,   821,
     296,  1140,  1271,  1135,  1135,   492,   817,  1106,  1099,  1266,
      95,  1103,  1266,  1138,   821,   821,  1147,   252,   254,  1275,
    1185,   177,   187,   210,   240,   752,   753,   754,   755,   756,
     757,  1222,   760,  1206,  1206,   129,  1271,  1271,    56,   123,
     482,     8,  1251,   840,   821,  1213,  1172,  1172,    49,   110,
     971,   456,  1269,  1269,   337,  1175,   203,   317,  1056,  1217,
    1196,  1271,  1007,  1142,  1143,  1144,  1148,   262,   262,   262,
     821,  1213,  1107,   451,  1213,  1266,  1213,   106,   116,  1320,
    1271,  1271,    54,    89,  1320,  1321,  1305,   761,   109,  1206,
    1206,  1271,  1151,  1151,  1207,  1210,  1222,  1135,  1135,  1196,
    1196,  1196,  1271,  1175,   337,   481,  1213,  1144,   127,   166,
     204,  1108,  1109,  1110,  1112,  1116,  1118,  1119,  1120,  1255,
    1264,  1213,  1271,  1222,  1222,   210,  1271,  1271,   209,   252,
     254,   285,   305,   333,   414,   431,   451,   472,   491,   499,
     707,   712,   713,   724,   726,   728,   762,   763,   767,   768,
     771,   772,   773,   774,   775,   776,   781,   782,   783,  1304,
    1305,   451,  1204,   995,  1271,  1152,    37,  1251,   340,   107,
    1222,  1222,  1222,   221,  1268,   299,   300,  1280,  1252,   209,
    1220,   501,  1271,  1281,  1271,  1271,  1213,   286,   329,   777,
     778,  1222,   329,   779,   780,  1222,  1280,  1252,   995,   367,
     418,  1293,   129,   421,  1117,  1282,  1272,  1271,   716,  1152,
    1199,  1197,  1199,    53,    89,   321,   325,   326,   366,   382,
     383,   764,  1320,  1321,  1322,  1323,  1324,  1325,  1326,   119,
     196,  1220,   778,  1220,   780,  1272,  1213,   161,   165,  1307,
       9,  1113,  1114,  1182,   778,  1297,  1245,   373,   769,  1199,
     187,   187,   210,   187,   210,   176,   765,  1213,   765,  1199,
     337,  1285,   306,   338,   358,  1115,  1114,   717,  1282,   313,
     766,   766,    49,  1282,   306,  1217,   425,   714,   176,   770,
    1213,   321,  1199,   170,   225,   233,   317,  1111,  1175,  1220
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
#line 1341 "parser.y"
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
#line 1352 "parser.y"
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
#line 1388 "parser.y"
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
#line 1443 "parser.y"
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
#line 1472 "parser.y"
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
#line 1505 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1511 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1523 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 1533 "parser.y"
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
#line 1564 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1571 "parser.y"
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
#line 1610 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1611 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1620 "parser.y"
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
#line 1629 "parser.y"
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
#line 1643 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1647 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1657 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1666 "parser.y"
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
#line 1691 "parser.y"
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
#line 1709 "parser.y"
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
#line 1722 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1751 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1758 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1765 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1772 "parser.y"
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
#line 1783 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1787 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1791 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1795 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1809 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1814 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1822 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1834 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1838 "parser.y"
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
#line 1859 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1863 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1870 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1875 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1886 "parser.y"
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
#line 1900 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1931 "parser.y"
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
#line 1950 "parser.y"
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
#line 1960 "parser.y"
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
#line 1973 "parser.y"
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
#line 1989 "parser.y"
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
#line 1999 "parser.y"
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
#line 2014 "parser.y"
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
#line 2027 "parser.y"
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
#line 2038 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2044 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2050 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2056 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2062 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2068 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2078 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2082 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2089 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2093 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2097 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2101 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2108 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 2112 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2118 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2119 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2120 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2121 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2122 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2123 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2131 "parser.y"
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
#line 2145 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 2149 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 2157 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 2164 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 2168 "parser.y"
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
#line 2179 "parser.y"
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
#line 2199 "parser.y"
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
#line 2207 "parser.y"
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
#line 2217 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2218 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 2225 "parser.y"
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
#line 2245 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2246 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2251 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2255 "parser.y"
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
#line 2276 "parser.y"
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
#line 2299 "parser.y"
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
#line 2380 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2384 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2393 "parser.y"
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
#line 2412 "parser.y"
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
#line 2428 "parser.y"
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
#line 2446 "parser.y"
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
#line 2464 "parser.y"
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
#line 2481 "parser.y"
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
#line 2498 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2506 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2515 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2530 "parser.y"
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
#line 2547 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2551 "parser.y"
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
#line 2585 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2591 "parser.y"
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
#line 2601 "parser.y"
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
#line 2614 "parser.y"
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
#line 2627 "parser.y"
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
#line 2650 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2657 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2670 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2682 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2689 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2690 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2691 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2699 "parser.y"
    {
	struct cb_alt_key *p;
	struct cb_alt_key *l;

	p = cobc_parse_malloc (sizeof (struct cb_alt_key));
	p->key = (yyvsp[(5) - (7)]);
	p->component_list = NULL;
	p->duplicates = CB_INTEGER ((yyvsp[(6) - (7)]))->val;
	if (CB_INTEGER ((yyvsp[(7) - (7)]))->val == -1) {
		p->tf_suppress = 0;
	} else {
		p->tf_suppress = 1;
		p->char_suppress = CB_INTEGER ((yyvsp[(7) - (7)]))->val;
	}
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
#line 2728 "parser.y"
    {
	struct cb_alt_key *p;
	struct cb_alt_key *l;
	cb_tree composite_key;

	p = cobc_parse_malloc (sizeof (struct cb_alt_key));
	// generate field (in w-s) for composite-key
	composite_key = cb_build_field((yyvsp[(5) - (9)]));
	if (composite_key == cb_error_node) {
		YYERROR;
	} else {
		composite_key->category = CB_CATEGORY_ALPHANUMERIC; 
		((struct cb_field *)composite_key)->count = 1;
		p->key = cb_build_field_reference((struct cb_field *)composite_key, NULL);
		p->component_list = key_component_list;
		p->duplicates = CB_INTEGER ((yyvsp[(8) - (9)]))->val;
		if (CB_INTEGER ((yyvsp[(9) - (9)]))->val == -1) {
			p->tf_suppress = 0;
		} else {
			p->tf_suppress = 1;
			p->char_suppress = CB_INTEGER ((yyvsp[(9) - (9)]))->val;
 		}
		p->next = NULL;

		/* add to the end of list */
		if (current_file->alt_key_list == NULL) {
			current_file->alt_key_list = p;
		} else {
			l = current_file->alt_key_list;
			for (; l->next; l = l->next);
			l->next = p;
		}
	}
  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2767 "parser.y"
    {
    key_component_list = NULL;
  }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2778 "parser.y"
    {
    struct cb_key_component *c;
    struct cb_key_component *comp = cobc_malloc(sizeof(struct cb_key_component));
    comp->next = NULL;
    comp->component = (yyvsp[(1) - (1)]);
    if (key_component_list == NULL) {
       key_component_list = comp;
    } else {
       for (c = key_component_list; c->next != NULL; c = c->next);
       c->next = comp;
    }
  }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2793 "parser.y"
    { (yyval) = cb_int (-1); }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2796 "parser.y"
    {
     if (cb_verify (cb_use_sparse_indexed_keys, "SUPPRESS WHEN")) {
        (yyval) = cb_int (literal_value ((yyvsp[(4) - (4)])));
     } else {
        (yyval) = cb_int (-1);
     }
  }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2811 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2822 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2837 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 2845 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2850 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2855 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2864 "parser.y"
    {
	current_file->flag_lock_many = 1;
  }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2868 "parser.y"
    {
	current_file->flag_lock_many = 1;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2884 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2889 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2894 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2899 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2910 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2921 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2931 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2942 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2953 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2967 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
  }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2973 "parser.y"
    { current_file->share_mode = COB_SHARE_ALL; }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2974 "parser.y"
    { current_file->share_mode = COB_SHARE_EXCLUSIVE; }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2975 "parser.y"
    { current_file->share_mode = COB_SHARE_READ_ONLY; }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 2984 "parser.y"
    {
	yyerrok;
  }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 3003 "parser.y"
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

  case 269:

/* Line 1806 of yacc.c  */
#line 3030 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 3031 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 3032 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 3033 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 3040 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 3045 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 3072 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 3081 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3095 "parser.y"
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

  case 287:

/* Line 1806 of yacc.c  */
#line 3114 "parser.y"
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

  case 289:

/* Line 1806 of yacc.c  */
#line 3131 "parser.y"
    {
	yyerrok;
  }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3138 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 3142 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 3153 "parser.y"
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

  case 295:

/* Line 1806 of yacc.c  */
#line 3163 "parser.y"
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

  case 305:

/* Line 1806 of yacc.c  */
#line 3193 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 3206 "parser.y"
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

  case 310:

/* Line 1806 of yacc.c  */
#line 3226 "parser.y"
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

  case 311:

/* Line 1806 of yacc.c  */
#line 3261 "parser.y"
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

  case 313:

/* Line 1806 of yacc.c  */
#line 3292 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3298 "parser.y"
    { (yyval) = NULL; }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3299 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3303 "parser.y"
    { (yyval) = NULL; }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 3304 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 3312 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 3323 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 3328 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 3351 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 3363 "parser.y"
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

  case 332:

/* Line 1806 of yacc.c  */
#line 3391 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 3398 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 3405 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 3414 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 3426 "parser.y"
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

  case 337:

/* Line 1806 of yacc.c  */
#line 3478 "parser.y"
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

  case 340:

/* Line 1806 of yacc.c  */
#line 3498 "parser.y"
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

  case 341:

/* Line 1806 of yacc.c  */
#line 3508 "parser.y"
    {
	current_report = build_report ((yyvsp[(2) - (2)]));
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 3548 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 3554 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 3563 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 3566 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 3572 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3592 "parser.y"
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

  case 353:

/* Line 1806 of yacc.c  */
#line 3607 "parser.y"
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

  case 354:

/* Line 1806 of yacc.c  */
#line 3627 "parser.y"
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

  case 355:

/* Line 1806 of yacc.c  */
#line 3640 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 3647 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 3653 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 3659 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 3668 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 3677 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 3681 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3692 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3693 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3694 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3695 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3700 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 3704 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 3708 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 3712 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 3716 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 3720 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 3724 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 3728 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 3732 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 3736 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 3740 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 3744 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 3748 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3780 "parser.y"
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

  case 389:

/* Line 1806 of yacc.c  */
#line 3806 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 3810 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 3818 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 3824 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 3852 "parser.y"
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

  case 408:

/* Line 1806 of yacc.c  */
#line 3876 "parser.y"
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

  case 409:

/* Line 1806 of yacc.c  */
#line 3903 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 3907 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 3916 "parser.y"
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

  case 412:

/* Line 1806 of yacc.c  */
#line 3941 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 3957 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3961 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 3965 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 3969 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 3973 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 3977 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 3981 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 3985 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 3989 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 3993 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 3997 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 4001 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 4005 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 4010 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 4015 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 4019 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 4023 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 4031 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 4035 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 4039 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 4047 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 4051 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 4055 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 4059 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 4063 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 4067 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 4071 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 4075 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 4079 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 4087 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 4095 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 4099 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 4103 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 4107 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 4111 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 4115 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 4135 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 4141 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 4154 "parser.y"
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

  case 459:

/* Line 1806 of yacc.c  */
#line 4172 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 4182 "parser.y"
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

  case 461:

/* Line 1806 of yacc.c  */
#line 4204 "parser.y"
    { (yyval) = NULL; }
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 4205 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 4210 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 4217 "parser.y"
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

  case 466:

/* Line 1806 of yacc.c  */
#line 4240 "parser.y"
    { (yyval) = NULL; }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 4243 "parser.y"
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

  case 468:

/* Line 1806 of yacc.c  */
#line 4258 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 4259 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 4264 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 4270 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 4272 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 4277 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 4288 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 4299 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 4310 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 4321 "parser.y"
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

  case 479:

/* Line 1806 of yacc.c  */
#line 4349 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 4357 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 4358 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 4362 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 4363 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 4368 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 4381 "parser.y"
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

  case 488:

/* Line 1806 of yacc.c  */
#line 4394 "parser.y"
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

  case 489:

/* Line 1806 of yacc.c  */
#line 4415 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 4424 "parser.y"
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

  case 492:

/* Line 1806 of yacc.c  */
#line 4439 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 4448 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 4460 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 4466 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 4477 "parser.y"
    {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 4493 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  }
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 4508 "parser.y"
    {
	yyerrok;
  }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 4515 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 4520 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 4531 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 4550 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4586 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 4590 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  }
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 4595 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 4615 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 4622 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 4629 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 4636 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 4643 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 4654 "parser.y"
    {
	check_pic_duplicate = 0;
  }
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 4685 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 4711 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 4718 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  }
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 4734 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 4745 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  }
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 4757 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 4790 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  }
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 4797 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  }
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 4804 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 4813 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 4820 "parser.y"
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

  case 600:

/* Line 1806 of yacc.c  */
#line 4846 "parser.y"
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

  case 601:

/* Line 1806 of yacc.c  */
#line 4877 "parser.y"
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

  case 602:

/* Line 1806 of yacc.c  */
#line 4903 "parser.y"
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

  case 605:

/* Line 1806 of yacc.c  */
#line 4926 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 4930 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 4934 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 4938 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 4942 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 4946 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 4950 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 4954 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 4958 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 4962 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 4966 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 4970 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 4974 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 4978 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 619:

/* Line 1806 of yacc.c  */
#line 4982 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 4986 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 4990 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 4995 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 4999 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 5003 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 5008 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 5013 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 5018 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 5031 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 5038 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 5043 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 5062 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 5066 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 5070 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 5077 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 5081 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 5085 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 5093 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 5104 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 5113 "parser.y"
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

  case 653:

/* Line 1806 of yacc.c  */
#line 5123 "parser.y"
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

  case 654:

/* Line 1806 of yacc.c  */
#line 5135 "parser.y"
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

  case 655:

/* Line 1806 of yacc.c  */
#line 5150 "parser.y"
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

  case 657:

/* Line 1806 of yacc.c  */
#line 5183 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 5187 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 5192 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 5200 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 5209 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 5219 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 5221 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 5226 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 5235 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 5239 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 5251 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 5259 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 671:

/* Line 1806 of yacc.c  */
#line 5267 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 5275 "parser.y"
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

  case 673:

/* Line 1806 of yacc.c  */
#line 5304 "parser.y"
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

  case 675:

/* Line 1806 of yacc.c  */
#line 5337 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 5346 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 677:

/* Line 1806 of yacc.c  */
#line 5352 "parser.y"
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

  case 679:

/* Line 1806 of yacc.c  */
#line 5380 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 680:

/* Line 1806 of yacc.c  */
#line 5386 "parser.y"
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

  case 685:

/* Line 1806 of yacc.c  */
#line 5423 "parser.y"
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

  case 687:

/* Line 1806 of yacc.c  */
#line 5441 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 5451 "parser.y"
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

  case 689:

/* Line 1806 of yacc.c  */
#line 5495 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 692:

/* Line 1806 of yacc.c  */
#line 5506 "parser.y"
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

  case 693:

/* Line 1806 of yacc.c  */
#line 5554 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 694:

/* Line 1806 of yacc.c  */
#line 5566 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 695:

/* Line 1806 of yacc.c  */
#line 5570 "parser.y"
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

  case 696:

/* Line 1806 of yacc.c  */
#line 5588 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 697:

/* Line 1806 of yacc.c  */
#line 5593 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 698:

/* Line 1806 of yacc.c  */
#line 5598 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 699:

/* Line 1806 of yacc.c  */
#line 5606 "parser.y"
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

  case 700:

/* Line 1806 of yacc.c  */
#line 5633 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 701:

/* Line 1806 of yacc.c  */
#line 5637 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 751:

/* Line 1806 of yacc.c  */
#line 5693 "parser.y"
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

  case 752:

/* Line 1806 of yacc.c  */
#line 5707 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 753:

/* Line 1806 of yacc.c  */
#line 5718 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 755:

/* Line 1806 of yacc.c  */
#line 5728 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 756:

/* Line 1806 of yacc.c  */
#line 5733 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 757:

/* Line 1806 of yacc.c  */
#line 5737 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 758:

/* Line 1806 of yacc.c  */
#line 5741 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 759:

/* Line 1806 of yacc.c  */
#line 5746 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 760:

/* Line 1806 of yacc.c  */
#line 5751 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 761:

/* Line 1806 of yacc.c  */
#line 5756 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 762:

/* Line 1806 of yacc.c  */
#line 5761 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 763:

/* Line 1806 of yacc.c  */
#line 5765 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 764:

/* Line 1806 of yacc.c  */
#line 5769 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 765:

/* Line 1806 of yacc.c  */
#line 5773 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 766:

/* Line 1806 of yacc.c  */
#line 5777 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 767:

/* Line 1806 of yacc.c  */
#line 5782 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 768:

/* Line 1806 of yacc.c  */
#line 5786 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 769:

/* Line 1806 of yacc.c  */
#line 5790 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 770:

/* Line 1806 of yacc.c  */
#line 5794 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 771:

/* Line 1806 of yacc.c  */
#line 5798 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 772:

/* Line 1806 of yacc.c  */
#line 5802 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 773:

/* Line 1806 of yacc.c  */
#line 5806 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 775:

/* Line 1806 of yacc.c  */
#line 5814 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 778:

/* Line 1806 of yacc.c  */
#line 5825 "parser.y"
    { (yyval) = NULL; }
    break;

  case 779:

/* Line 1806 of yacc.c  */
#line 5826 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 780:

/* Line 1806 of yacc.c  */
#line 5830 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 781:

/* Line 1806 of yacc.c  */
#line 5831 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 782:

/* Line 1806 of yacc.c  */
#line 5832 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 783:

/* Line 1806 of yacc.c  */
#line 5833 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 784:

/* Line 1806 of yacc.c  */
#line 5834 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 785:

/* Line 1806 of yacc.c  */
#line 5838 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 786:

/* Line 1806 of yacc.c  */
#line 5842 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 787:

/* Line 1806 of yacc.c  */
#line 5843 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 791:

/* Line 1806 of yacc.c  */
#line 5852 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 796:

/* Line 1806 of yacc.c  */
#line 5868 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 797:

/* Line 1806 of yacc.c  */
#line 5872 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 798:

/* Line 1806 of yacc.c  */
#line 5876 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 799:

/* Line 1806 of yacc.c  */
#line 5880 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 800:

/* Line 1806 of yacc.c  */
#line 5884 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 801:

/* Line 1806 of yacc.c  */
#line 5888 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 802:

/* Line 1806 of yacc.c  */
#line 5892 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 803:

/* Line 1806 of yacc.c  */
#line 5896 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 804:

/* Line 1806 of yacc.c  */
#line 5900 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 805:

/* Line 1806 of yacc.c  */
#line 5904 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 806:

/* Line 1806 of yacc.c  */
#line 5908 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 807:

/* Line 1806 of yacc.c  */
#line 5912 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 808:

/* Line 1806 of yacc.c  */
#line 5916 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 809:

/* Line 1806 of yacc.c  */
#line 5920 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 810:

/* Line 1806 of yacc.c  */
#line 5924 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 811:

/* Line 1806 of yacc.c  */
#line 5928 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 812:

/* Line 1806 of yacc.c  */
#line 5932 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 813:

/* Line 1806 of yacc.c  */
#line 5936 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 814:

/* Line 1806 of yacc.c  */
#line 5940 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 815:

/* Line 1806 of yacc.c  */
#line 5944 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 816:

/* Line 1806 of yacc.c  */
#line 5948 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 817:

/* Line 1806 of yacc.c  */
#line 5952 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 818:

/* Line 1806 of yacc.c  */
#line 5956 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 819:

/* Line 1806 of yacc.c  */
#line 5960 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 820:

/* Line 1806 of yacc.c  */
#line 5967 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 821:

/* Line 1806 of yacc.c  */
#line 5971 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 822:

/* Line 1806 of yacc.c  */
#line 5981 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 824:

/* Line 1806 of yacc.c  */
#line 5990 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 825:

/* Line 1806 of yacc.c  */
#line 5994 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 826:

/* Line 1806 of yacc.c  */
#line 5998 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 828:

/* Line 1806 of yacc.c  */
#line 6005 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 829:

/* Line 1806 of yacc.c  */
#line 6012 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 830:

/* Line 1806 of yacc.c  */
#line 6016 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 831:

/* Line 1806 of yacc.c  */
#line 6026 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 833:

/* Line 1806 of yacc.c  */
#line 6035 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 834:

/* Line 1806 of yacc.c  */
#line 6039 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 835:

/* Line 1806 of yacc.c  */
#line 6050 "parser.y"
    { (yyval) = NULL; }
    break;

  case 836:

/* Line 1806 of yacc.c  */
#line 6051 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 837:

/* Line 1806 of yacc.c  */
#line 6059 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 841:

/* Line 1806 of yacc.c  */
#line 6073 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 844:

/* Line 1806 of yacc.c  */
#line 6085 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 846:

/* Line 1806 of yacc.c  */
#line 6100 "parser.y"
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

  case 847:

/* Line 1806 of yacc.c  */
#line 6114 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 848:

/* Line 1806 of yacc.c  */
#line 6119 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 849:

/* Line 1806 of yacc.c  */
#line 6124 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 850:

/* Line 1806 of yacc.c  */
#line 6129 "parser.y"
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

  case 851:

/* Line 1806 of yacc.c  */
#line 6149 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 852:

/* Line 1806 of yacc.c  */
#line 6153 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 853:

/* Line 1806 of yacc.c  */
#line 6158 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 854:

/* Line 1806 of yacc.c  */
#line 6169 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 855:

/* Line 1806 of yacc.c  */
#line 6171 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 856:

/* Line 1806 of yacc.c  */
#line 6176 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 857:

/* Line 1806 of yacc.c  */
#line 6184 "parser.y"
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

  case 859:

/* Line 1806 of yacc.c  */
#line 6210 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 860:

/* Line 1806 of yacc.c  */
#line 6214 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 861:

/* Line 1806 of yacc.c  */
#line 6223 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 862:

/* Line 1806 of yacc.c  */
#line 6235 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 863:

/* Line 1806 of yacc.c  */
#line 6239 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 864:

/* Line 1806 of yacc.c  */
#line 6243 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 865:

/* Line 1806 of yacc.c  */
#line 6247 "parser.y"
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

  case 870:

/* Line 1806 of yacc.c  */
#line 6280 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 871:

/* Line 1806 of yacc.c  */
#line 6285 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 872:

/* Line 1806 of yacc.c  */
#line 6292 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 873:

/* Line 1806 of yacc.c  */
#line 6297 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 874:

/* Line 1806 of yacc.c  */
#line 6304 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 875:

/* Line 1806 of yacc.c  */
#line 6308 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 876:

/* Line 1806 of yacc.c  */
#line 6318 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 878:

/* Line 1806 of yacc.c  */
#line 6326 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 879:

/* Line 1806 of yacc.c  */
#line 6330 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 880:

/* Line 1806 of yacc.c  */
#line 6340 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 882:

/* Line 1806 of yacc.c  */
#line 6348 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 883:

/* Line 1806 of yacc.c  */
#line 6353 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 884:

/* Line 1806 of yacc.c  */
#line 6360 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 885:

/* Line 1806 of yacc.c  */
#line 6361 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 886:

/* Line 1806 of yacc.c  */
#line 6362 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 887:

/* Line 1806 of yacc.c  */
#line 6363 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 888:

/* Line 1806 of yacc.c  */
#line 6364 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 889:

/* Line 1806 of yacc.c  */
#line 6372 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 891:

/* Line 1806 of yacc.c  */
#line 6381 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 892:

/* Line 1806 of yacc.c  */
#line 6388 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 893:

/* Line 1806 of yacc.c  */
#line 6392 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 894:

/* Line 1806 of yacc.c  */
#line 6402 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 895:

/* Line 1806 of yacc.c  */
#line 6413 "parser.y"
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

  case 896:

/* Line 1806 of yacc.c  */
#line 6430 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 898:

/* Line 1806 of yacc.c  */
#line 6439 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 900:

/* Line 1806 of yacc.c  */
#line 6447 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 901:

/* Line 1806 of yacc.c  */
#line 6452 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 902:

/* Line 1806 of yacc.c  */
#line 6460 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 903:

/* Line 1806 of yacc.c  */
#line 6464 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 904:

/* Line 1806 of yacc.c  */
#line 6474 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 906:

/* Line 1806 of yacc.c  */
#line 6484 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 907:

/* Line 1806 of yacc.c  */
#line 6488 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 908:

/* Line 1806 of yacc.c  */
#line 6492 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 909:

/* Line 1806 of yacc.c  */
#line 6496 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 910:

/* Line 1806 of yacc.c  */
#line 6500 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 912:

/* Line 1806 of yacc.c  */
#line 6505 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 914:

/* Line 1806 of yacc.c  */
#line 6515 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 916:

/* Line 1806 of yacc.c  */
#line 6523 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 917:

/* Line 1806 of yacc.c  */
#line 6531 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 918:

/* Line 1806 of yacc.c  */
#line 6539 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 919:

/* Line 1806 of yacc.c  */
#line 6543 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 920:

/* Line 1806 of yacc.c  */
#line 6547 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 921:

/* Line 1806 of yacc.c  */
#line 6551 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 927:

/* Line 1806 of yacc.c  */
#line 6573 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 928:

/* Line 1806 of yacc.c  */
#line 6579 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 929:

/* Line 1806 of yacc.c  */
#line 6580 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 932:

/* Line 1806 of yacc.c  */
#line 6591 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 933:

/* Line 1806 of yacc.c  */
#line 6595 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 934:

/* Line 1806 of yacc.c  */
#line 6599 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 935:

/* Line 1806 of yacc.c  */
#line 6603 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 936:

/* Line 1806 of yacc.c  */
#line 6607 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 937:

/* Line 1806 of yacc.c  */
#line 6611 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 938:

/* Line 1806 of yacc.c  */
#line 6615 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 939:

/* Line 1806 of yacc.c  */
#line 6619 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 940:

/* Line 1806 of yacc.c  */
#line 6623 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 941:

/* Line 1806 of yacc.c  */
#line 6627 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 942:

/* Line 1806 of yacc.c  */
#line 6631 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 943:

/* Line 1806 of yacc.c  */
#line 6635 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 944:

/* Line 1806 of yacc.c  */
#line 6639 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 945:

/* Line 1806 of yacc.c  */
#line 6643 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 946:

/* Line 1806 of yacc.c  */
#line 6647 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 947:

/* Line 1806 of yacc.c  */
#line 6651 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 948:

/* Line 1806 of yacc.c  */
#line 6658 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 949:

/* Line 1806 of yacc.c  */
#line 6662 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 950:

/* Line 1806 of yacc.c  */
#line 6672 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 952:

/* Line 1806 of yacc.c  */
#line 6681 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 953:

/* Line 1806 of yacc.c  */
#line 6685 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 954:

/* Line 1806 of yacc.c  */
#line 6689 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 955:

/* Line 1806 of yacc.c  */
#line 6693 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 956:

/* Line 1806 of yacc.c  */
#line 6697 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 957:

/* Line 1806 of yacc.c  */
#line 6704 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 958:

/* Line 1806 of yacc.c  */
#line 6708 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 959:

/* Line 1806 of yacc.c  */
#line 6718 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 961:

/* Line 1806 of yacc.c  */
#line 6726 "parser.y"
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

  case 962:

/* Line 1806 of yacc.c  */
#line 6745 "parser.y"
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

  case 964:

/* Line 1806 of yacc.c  */
#line 6769 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 965:

/* Line 1806 of yacc.c  */
#line 6776 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 966:

/* Line 1806 of yacc.c  */
#line 6778 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 967:

/* Line 1806 of yacc.c  */
#line 6783 "parser.y"
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

  case 968:

/* Line 1806 of yacc.c  */
#line 6794 "parser.y"
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

  case 969:

/* Line 1806 of yacc.c  */
#line 6805 "parser.y"
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

  case 970:

/* Line 1806 of yacc.c  */
#line 6819 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 971:

/* Line 1806 of yacc.c  */
#line 6823 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 972:

/* Line 1806 of yacc.c  */
#line 6829 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 973:

/* Line 1806 of yacc.c  */
#line 6831 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 974:

/* Line 1806 of yacc.c  */
#line 6837 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 975:

/* Line 1806 of yacc.c  */
#line 6846 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 976:

/* Line 1806 of yacc.c  */
#line 6854 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 977:

/* Line 1806 of yacc.c  */
#line 6860 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 978:

/* Line 1806 of yacc.c  */
#line 6867 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 979:

/* Line 1806 of yacc.c  */
#line 6869 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 980:

/* Line 1806 of yacc.c  */
#line 6874 "parser.y"
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

  case 981:

/* Line 1806 of yacc.c  */
#line 6935 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 982:

/* Line 1806 of yacc.c  */
#line 6936 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 983:

/* Line 1806 of yacc.c  */
#line 6937 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 984:

/* Line 1806 of yacc.c  */
#line 6941 "parser.y"
    { (yyval) = NULL; }
    break;

  case 985:

/* Line 1806 of yacc.c  */
#line 6942 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 986:

/* Line 1806 of yacc.c  */
#line 6947 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 987:

/* Line 1806 of yacc.c  */
#line 6951 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 988:

/* Line 1806 of yacc.c  */
#line 6961 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 989:

/* Line 1806 of yacc.c  */
#line 6966 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 991:

/* Line 1806 of yacc.c  */
#line 6974 "parser.y"
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

  case 992:

/* Line 1806 of yacc.c  */
#line 6995 "parser.y"
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

  case 993:

/* Line 1806 of yacc.c  */
#line 7009 "parser.y"
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

  case 994:

/* Line 1806 of yacc.c  */
#line 7031 "parser.y"
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

  case 995:

/* Line 1806 of yacc.c  */
#line 7053 "parser.y"
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

  case 996:

/* Line 1806 of yacc.c  */
#line 7073 "parser.y"
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

  case 997:

/* Line 1806 of yacc.c  */
#line 7095 "parser.y"
    { (yyval) = NULL; }
    break;

  case 998:

/* Line 1806 of yacc.c  */
#line 7096 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 999:

/* Line 1806 of yacc.c  */
#line 7104 "parser.y"
    {
	begin_statement ("FREE", 0);
  }
    break;

  case 1001:

/* Line 1806 of yacc.c  */
#line 7112 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 1002:

/* Line 1806 of yacc.c  */
#line 7122 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  }
    break;

  case 1005:

/* Line 1806 of yacc.c  */
#line 7138 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1007:

/* Line 1806 of yacc.c  */
#line 7151 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1008:

/* Line 1806 of yacc.c  */
#line 7159 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1009:

/* Line 1806 of yacc.c  */
#line 7164 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1010:

/* Line 1806 of yacc.c  */
#line 7175 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  }
    break;

  case 1011:

/* Line 1806 of yacc.c  */
#line 7190 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1013:

/* Line 1806 of yacc.c  */
#line 7199 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7203 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1015:

/* Line 1806 of yacc.c  */
#line 7207 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1016:

/* Line 1806 of yacc.c  */
#line 7214 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7218 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1018:

/* Line 1806 of yacc.c  */
#line 7228 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7237 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7243 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7244 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7248 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7249 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1025:

/* Line 1806 of yacc.c  */
#line 7250 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7255 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7259 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7266 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7271 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7278 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7284 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1032:

/* Line 1806 of yacc.c  */
#line 7285 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7286 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7287 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1035:

/* Line 1806 of yacc.c  */
#line 7288 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7289 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1037:

/* Line 1806 of yacc.c  */
#line 7290 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7295 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1039:

/* Line 1806 of yacc.c  */
#line 7299 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1040:

/* Line 1806 of yacc.c  */
#line 7308 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1042:

/* Line 1806 of yacc.c  */
#line 7317 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7323 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1044:

/* Line 1806 of yacc.c  */
#line 7334 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1047:

/* Line 1806 of yacc.c  */
#line 7347 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1048:

/* Line 1806 of yacc.c  */
#line 7351 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1049:

/* Line 1806 of yacc.c  */
#line 7355 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1054:

/* Line 1806 of yacc.c  */
#line 7371 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7375 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1056:

/* Line 1806 of yacc.c  */
#line 7385 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1057:

/* Line 1806 of yacc.c  */
#line 7395 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1058:

/* Line 1806 of yacc.c  */
#line 7403 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1059:

/* Line 1806 of yacc.c  */
#line 7404 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7408 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7409 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7410 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1063:

/* Line 1806 of yacc.c  */
#line 7411 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1064:

/* Line 1806 of yacc.c  */
#line 7412 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1065:

/* Line 1806 of yacc.c  */
#line 7413 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1066:

/* Line 1806 of yacc.c  */
#line 7417 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7418 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7423 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7428 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7434 "parser.y"
    { /* Nothing */ }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
#line 7435 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1072:

/* Line 1806 of yacc.c  */
#line 7436 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7437 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7438 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1075:

/* Line 1806 of yacc.c  */
#line 7443 "parser.y"
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

  case 1076:

/* Line 1806 of yacc.c  */
#line 7470 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1077:

/* Line 1806 of yacc.c  */
#line 7474 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7481 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1079:

/* Line 1806 of yacc.c  */
#line 7485 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1080:

/* Line 1806 of yacc.c  */
#line 7494 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1082:

/* Line 1806 of yacc.c  */
#line 7506 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7514 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7518 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1086:

/* Line 1806 of yacc.c  */
#line 7528 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7537 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1089:

/* Line 1806 of yacc.c  */
#line 7541 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7548 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1091:

/* Line 1806 of yacc.c  */
#line 7552 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1092:

/* Line 1806 of yacc.c  */
#line 7562 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1094:

/* Line 1806 of yacc.c  */
#line 7570 "parser.y"
    {
	cb_tree l;

	if ((yyvsp[(2) - (4)]) && (yyvsp[(4) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	for (l = (yyvsp[(3) - (4)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		}
	}
  }
    break;

  case 1095:

/* Line 1806 of yacc.c  */
#line 7585 "parser.y"
    {
	cb_tree l;

	if ((yyvsp[(3) - (5)]) && (yyvsp[(5) - (5)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	for (l = (yyvsp[(4) - (5)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
		}
	}
  }
    break;

  case 1096:

/* Line 1806 of yacc.c  */
#line 7602 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7603 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7604 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1099:

/* Line 1806 of yacc.c  */
#line 7605 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1100:

/* Line 1806 of yacc.c  */
#line 7609 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1101:

/* Line 1806 of yacc.c  */
#line 7610 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1102:

/* Line 1806 of yacc.c  */
#line 7615 "parser.y"
    { (yyval) = cb_int (COB_SHARE_ALL); }
    break;

  case 1103:

/* Line 1806 of yacc.c  */
#line 7616 "parser.y"
    { (yyval) = cb_int (COB_SHARE_EXCLUSIVE); }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7617 "parser.y"
    { (yyval) = cb_int (COB_SHARE_READ_ONLY); }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7623 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1106:

/* Line 1806 of yacc.c  */
#line 7624 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7625 "parser.y"
    { (yyval) = cb_int (COB_LOCK_EXCLUSIVE); }
    break;

  case 1108:

/* Line 1806 of yacc.c  */
#line 7627 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1109:

/* Line 1806 of yacc.c  */
#line 7638 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
#line 7649 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1112:

/* Line 1806 of yacc.c  */
#line 7654 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
#line 7660 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1114:

/* Line 1806 of yacc.c  */
#line 7665 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1115:

/* Line 1806 of yacc.c  */
#line 7673 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1116:

/* Line 1806 of yacc.c  */
#line 7681 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
#line 7688 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1118:

/* Line 1806 of yacc.c  */
#line 7692 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 7705 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1120:

/* Line 1806 of yacc.c  */
#line 7712 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1121:

/* Line 1806 of yacc.c  */
#line 7723 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7727 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7732 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7736 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 7747 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7753 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1127:

/* Line 1806 of yacc.c  */
#line 7754 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
#line 7758 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1129:

/* Line 1806 of yacc.c  */
#line 7759 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1130:

/* Line 1806 of yacc.c  */
#line 7762 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1131:

/* Line 1806 of yacc.c  */
#line 7764 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1132:

/* Line 1806 of yacc.c  */
#line 7769 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7779 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1135:

/* Line 1806 of yacc.c  */
#line 7788 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 7814 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7815 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1138:

/* Line 1806 of yacc.c  */
#line 7820 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1139:

/* Line 1806 of yacc.c  */
#line 7824 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1140:

/* Line 1806 of yacc.c  */
#line 7828 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1141:

/* Line 1806 of yacc.c  */
#line 7832 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1142:

/* Line 1806 of yacc.c  */
#line 7836 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1143:

/* Line 1806 of yacc.c  */
#line 7840 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1144:

/* Line 1806 of yacc.c  */
#line 7844 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7850 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1146:

/* Line 1806 of yacc.c  */
#line 7851 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1149:

/* Line 1806 of yacc.c  */
#line 7861 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1150:

/* Line 1806 of yacc.c  */
#line 7865 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 7875 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 7885 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1154:

/* Line 1806 of yacc.c  */
#line 7893 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1155:

/* Line 1806 of yacc.c  */
#line 7903 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 7913 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1158:

/* Line 1806 of yacc.c  */
#line 7922 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1159:

/* Line 1806 of yacc.c  */
#line 7929 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 7933 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 7943 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1163:

/* Line 1806 of yacc.c  */
#line 7955 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1164:

/* Line 1806 of yacc.c  */
#line 7963 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 7967 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 7971 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1167:

/* Line 1806 of yacc.c  */
#line 7978 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1168:

/* Line 1806 of yacc.c  */
#line 7982 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 7992 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 8003 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1172:

/* Line 1806 of yacc.c  */
#line 8012 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 8017 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 8024 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 8025 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1176:

/* Line 1806 of yacc.c  */
#line 8030 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1177:

/* Line 1806 of yacc.c  */
#line 8035 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1178:

/* Line 1806 of yacc.c  */
#line 8042 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1179:

/* Line 1806 of yacc.c  */
#line 8046 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1180:

/* Line 1806 of yacc.c  */
#line 8054 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1181:

/* Line 1806 of yacc.c  */
#line 8061 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1182:

/* Line 1806 of yacc.c  */
#line 8065 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1183:

/* Line 1806 of yacc.c  */
#line 8075 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1184:

/* Line 1806 of yacc.c  */
#line 8082 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1191:

/* Line 1806 of yacc.c  */
#line 8097 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1192:

/* Line 1806 of yacc.c  */
#line 8098 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1193:

/* Line 1806 of yacc.c  */
#line 8102 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1194:

/* Line 1806 of yacc.c  */
#line 8103 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1195:

/* Line 1806 of yacc.c  */
#line 8110 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1196:

/* Line 1806 of yacc.c  */
#line 8119 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1199:

/* Line 1806 of yacc.c  */
#line 8131 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1200:

/* Line 1806 of yacc.c  */
#line 8135 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1201:

/* Line 1806 of yacc.c  */
#line 8139 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1202:

/* Line 1806 of yacc.c  */
#line 8143 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1203:

/* Line 1806 of yacc.c  */
#line 8147 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1204:

/* Line 1806 of yacc.c  */
#line 8151 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1205:

/* Line 1806 of yacc.c  */
#line 8155 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1206:

/* Line 1806 of yacc.c  */
#line 8159 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1207:

/* Line 1806 of yacc.c  */
#line 8168 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1208:

/* Line 1806 of yacc.c  */
#line 8172 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1209:

/* Line 1806 of yacc.c  */
#line 8181 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
#line 8195 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
#line 8209 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1216:

/* Line 1806 of yacc.c  */
#line 8213 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1217:

/* Line 1806 of yacc.c  */
#line 8223 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1219:

/* Line 1806 of yacc.c  */
#line 8231 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8252 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1221:

/* Line 1806 of yacc.c  */
#line 8261 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8266 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8284 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1224:

/* Line 1806 of yacc.c  */
#line 8285 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1226:

/* Line 1806 of yacc.c  */
#line 8290 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1227:

/* Line 1806 of yacc.c  */
#line 8297 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1228:

/* Line 1806 of yacc.c  */
#line 8298 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1229:

/* Line 1806 of yacc.c  */
#line 8303 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1230:

/* Line 1806 of yacc.c  */
#line 8309 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8319 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8334 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1233:

/* Line 1806 of yacc.c  */
#line 8340 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8350 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8366 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1237:

/* Line 1806 of yacc.c  */
#line 8376 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8388 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8392 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1240:

/* Line 1806 of yacc.c  */
#line 8399 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1241:

/* Line 1806 of yacc.c  */
#line 8403 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1242:

/* Line 1806 of yacc.c  */
#line 8408 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1243:

/* Line 1806 of yacc.c  */
#line 8413 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1244:

/* Line 1806 of yacc.c  */
#line 8420 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1245:

/* Line 1806 of yacc.c  */
#line 8421 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1246:

/* Line 1806 of yacc.c  */
#line 8422 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1247:

/* Line 1806 of yacc.c  */
#line 8423 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1248:

/* Line 1806 of yacc.c  */
#line 8424 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8425 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
#line 8430 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
#line 8443 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1254:

/* Line 1806 of yacc.c  */
#line 8447 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1255:

/* Line 1806 of yacc.c  */
#line 8457 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8461 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1257:

/* Line 1806 of yacc.c  */
#line 8467 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8479 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8483 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8487 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1261:

/* Line 1806 of yacc.c  */
#line 8495 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1262:

/* Line 1806 of yacc.c  */
#line 8506 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8510 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8516 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1265:

/* Line 1806 of yacc.c  */
#line 8517 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8518 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8519 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8526 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8535 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8541 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8542 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1273:

/* Line 1806 of yacc.c  */
#line 8546 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1274:

/* Line 1806 of yacc.c  */
#line 8547 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1275:

/* Line 1806 of yacc.c  */
#line 8548 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8552 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1277:

/* Line 1806 of yacc.c  */
#line 8553 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8558 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8562 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1280:

/* Line 1806 of yacc.c  */
#line 8572 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1282:

/* Line 1806 of yacc.c  */
#line 8581 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1283:

/* Line 1806 of yacc.c  */
#line 8585 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1284:

/* Line 1806 of yacc.c  */
#line 8589 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1285:

/* Line 1806 of yacc.c  */
#line 8596 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8600 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1287:

/* Line 1806 of yacc.c  */
#line 8610 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  }
    break;

  case 1290:

/* Line 1806 of yacc.c  */
#line 8628 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1292:

/* Line 1806 of yacc.c  */
#line 8637 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1293:

/* Line 1806 of yacc.c  */
#line 8643 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1294:

/* Line 1806 of yacc.c  */
#line 8654 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1296:

/* Line 1806 of yacc.c  */
#line 8662 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1297:

/* Line 1806 of yacc.c  */
#line 8675 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1299:

/* Line 1806 of yacc.c  */
#line 8683 "parser.y"
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

  case 1303:

/* Line 1806 of yacc.c  */
#line 8706 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8716 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1306:

/* Line 1806 of yacc.c  */
#line 8722 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1307:

/* Line 1806 of yacc.c  */
#line 8724 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1308:

/* Line 1806 of yacc.c  */
#line 8728 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1309:

/* Line 1806 of yacc.c  */
#line 8730 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1310:

/* Line 1806 of yacc.c  */
#line 8735 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1311:

/* Line 1806 of yacc.c  */
#line 8741 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1312:

/* Line 1806 of yacc.c  */
#line 8743 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1313:

/* Line 1806 of yacc.c  */
#line 8748 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1314:

/* Line 1806 of yacc.c  */
#line 8754 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1315:

/* Line 1806 of yacc.c  */
#line 8755 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1316:

/* Line 1806 of yacc.c  */
#line 8759 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1317:

/* Line 1806 of yacc.c  */
#line 8760 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1318:

/* Line 1806 of yacc.c  */
#line 8764 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1319:

/* Line 1806 of yacc.c  */
#line 8765 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1320:

/* Line 1806 of yacc.c  */
#line 8770 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1321:

/* Line 1806 of yacc.c  */
#line 8774 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1322:

/* Line 1806 of yacc.c  */
#line 8784 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1329:

/* Line 1806 of yacc.c  */
#line 8802 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8827 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1331:

/* Line 1806 of yacc.c  */
#line 8831 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8843 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8853 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1334:

/* Line 1806 of yacc.c  */
#line 8858 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1335:

/* Line 1806 of yacc.c  */
#line 8863 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1336:

/* Line 1806 of yacc.c  */
#line 8868 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1337:

/* Line 1806 of yacc.c  */
#line 8876 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8919 "parser.y"
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

  case 1341:

/* Line 1806 of yacc.c  */
#line 8959 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8969 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 8999 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("USE AT is invalid in nested program"));
	}
  }
    break;

  case 1348:

/* Line 1806 of yacc.c  */
#line 9008 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM START"));
	/* emit_entry ("_START", 0, NULL); */
	PENDING ("USE AT PROGRAM START");
  }
    break;

  case 1349:

/* Line 1806 of yacc.c  */
#line 9014 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM END"));
	/* emit_entry ("_END", 0, NULL); */
	PENDING ("USE AT PROGRAM END");
  }
    break;

  case 1350:

/* Line 1806 of yacc.c  */
#line 9024 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1351:

/* Line 1806 of yacc.c  */
#line 9033 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1354:

/* Line 1806 of yacc.c  */
#line 9049 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1356:

/* Line 1806 of yacc.c  */
#line 9061 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1357:

/* Line 1806 of yacc.c  */
#line 9070 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1358:

/* Line 1806 of yacc.c  */
#line 9071 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1359:

/* Line 1806 of yacc.c  */
#line 9076 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1360:

/* Line 1806 of yacc.c  */
#line 9080 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1361:

/* Line 1806 of yacc.c  */
#line 9084 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1362:

/* Line 1806 of yacc.c  */
#line 9088 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1363:

/* Line 1806 of yacc.c  */
#line 9094 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1364:

/* Line 1806 of yacc.c  */
#line 9095 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1367:

/* Line 1806 of yacc.c  */
#line 9105 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1368:

/* Line 1806 of yacc.c  */
#line 9109 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1371:

/* Line 1806 of yacc.c  */
#line 9126 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1373:

/* Line 1806 of yacc.c  */
#line 9136 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1376:

/* Line 1806 of yacc.c  */
#line 9149 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1378:

/* Line 1806 of yacc.c  */
#line 9159 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1381:

/* Line 1806 of yacc.c  */
#line 9174 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1383:

/* Line 1806 of yacc.c  */
#line 9184 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1386:

/* Line 1806 of yacc.c  */
#line 9201 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1388:

/* Line 1806 of yacc.c  */
#line 9212 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1394:

/* Line 1806 of yacc.c  */
#line 9235 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1395:

/* Line 1806 of yacc.c  */
#line 9244 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1399:

/* Line 1806 of yacc.c  */
#line 9261 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1400:

/* Line 1806 of yacc.c  */
#line 9270 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1403:

/* Line 1806 of yacc.c  */
#line 9287 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1405:

/* Line 1806 of yacc.c  */
#line 9297 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9307 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1407:

/* Line 1806 of yacc.c  */
#line 9311 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1408:

/* Line 1806 of yacc.c  */
#line 9321 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1409:

/* Line 1806 of yacc.c  */
#line 9328 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1410:

/* Line 1806 of yacc.c  */
#line 9334 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1411:

/* Line 1806 of yacc.c  */
#line 9338 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9351 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9359 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9360 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1418:

/* Line 1806 of yacc.c  */
#line 9362 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1419:

/* Line 1806 of yacc.c  */
#line 9363 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1420:

/* Line 1806 of yacc.c  */
#line 9364 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1421:

/* Line 1806 of yacc.c  */
#line 9365 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9366 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9368 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9369 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9370 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9371 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1427:

/* Line 1806 of yacc.c  */
#line 9372 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1428:

/* Line 1806 of yacc.c  */
#line 9373 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1429:

/* Line 1806 of yacc.c  */
#line 9375 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1430:

/* Line 1806 of yacc.c  */
#line 9376 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1431:

/* Line 1806 of yacc.c  */
#line 9377 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1432:

/* Line 1806 of yacc.c  */
#line 9379 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1433:

/* Line 1806 of yacc.c  */
#line 9380 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1434:

/* Line 1806 of yacc.c  */
#line 9381 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1435:

/* Line 1806 of yacc.c  */
#line 9382 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1436:

/* Line 1806 of yacc.c  */
#line 9383 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1437:

/* Line 1806 of yacc.c  */
#line 9386 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1438:

/* Line 1806 of yacc.c  */
#line 9387 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1447:

/* Line 1806 of yacc.c  */
#line 9417 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1448:

/* Line 1806 of yacc.c  */
#line 9421 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1452:

/* Line 1806 of yacc.c  */
#line 9432 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1453:

/* Line 1806 of yacc.c  */
#line 9433 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9434 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1455:

/* Line 1806 of yacc.c  */
#line 9438 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1456:

/* Line 1806 of yacc.c  */
#line 9439 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1457:

/* Line 1806 of yacc.c  */
#line 9440 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1458:

/* Line 1806 of yacc.c  */
#line 9445 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1459:

/* Line 1806 of yacc.c  */
#line 9448 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1460:

/* Line 1806 of yacc.c  */
#line 9452 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9453 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1462:

/* Line 1806 of yacc.c  */
#line 9454 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9457 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1464:

/* Line 1806 of yacc.c  */
#line 9458 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1465:

/* Line 1806 of yacc.c  */
#line 9469 "parser.y"
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

  case 1466:

/* Line 1806 of yacc.c  */
#line 9481 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1467:

/* Line 1806 of yacc.c  */
#line 9490 "parser.y"
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

  case 1468:

/* Line 1806 of yacc.c  */
#line 9502 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1469:

/* Line 1806 of yacc.c  */
#line 9511 "parser.y"
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

  case 1470:

/* Line 1806 of yacc.c  */
#line 9523 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9537 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1472:

/* Line 1806 of yacc.c  */
#line 9539 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1473:

/* Line 1806 of yacc.c  */
#line 9544 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1474:

/* Line 1806 of yacc.c  */
#line 9552 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1475:

/* Line 1806 of yacc.c  */
#line 9559 "parser.y"
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

  case 1476:

/* Line 1806 of yacc.c  */
#line 9579 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1477:

/* Line 1806 of yacc.c  */
#line 9583 "parser.y"
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

  case 1478:

/* Line 1806 of yacc.c  */
#line 9604 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9645 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9658 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9660 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1482:

/* Line 1806 of yacc.c  */
#line 9664 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1483:

/* Line 1806 of yacc.c  */
#line 9670 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1484:

/* Line 1806 of yacc.c  */
#line 9672 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1485:

/* Line 1806 of yacc.c  */
#line 9677 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9691 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1489:

/* Line 1806 of yacc.c  */
#line 9698 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1490:

/* Line 1806 of yacc.c  */
#line 9708 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1491:

/* Line 1806 of yacc.c  */
#line 9709 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1492:

/* Line 1806 of yacc.c  */
#line 9714 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1493:

/* Line 1806 of yacc.c  */
#line 9722 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1494:

/* Line 1806 of yacc.c  */
#line 9730 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9734 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1496:

/* Line 1806 of yacc.c  */
#line 9741 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1497:

/* Line 1806 of yacc.c  */
#line 9751 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_is_key = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1500:

/* Line 1806 of yacc.c  */
#line 9767 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9781 "parser.y"
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

  case 1502:

/* Line 1806 of yacc.c  */
#line 9798 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9802 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1506:

/* Line 1806 of yacc.c  */
#line 9811 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1507:

/* Line 1806 of yacc.c  */
#line 9818 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1508:

/* Line 1806 of yacc.c  */
#line 9822 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1513:

/* Line 1806 of yacc.c  */
#line 9833 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1514:

/* Line 1806 of yacc.c  */
#line 9837 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1515:

/* Line 1806 of yacc.c  */
#line 9841 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1516:

/* Line 1806 of yacc.c  */
#line 9845 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1517:

/* Line 1806 of yacc.c  */
#line 9849 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1518:

/* Line 1806 of yacc.c  */
#line 9853 "parser.y"
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

  case 1519:

/* Line 1806 of yacc.c  */
#line 9874 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1520:

/* Line 1806 of yacc.c  */
#line 9878 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1528:

/* Line 1806 of yacc.c  */
#line 9895 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1529:

/* Line 1806 of yacc.c  */
#line 9899 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1530:

/* Line 1806 of yacc.c  */
#line 9903 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1546:

/* Line 1806 of yacc.c  */
#line 9950 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1554:

/* Line 1806 of yacc.c  */
#line 9974 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1555:

/* Line 1806 of yacc.c  */
#line 9978 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1556:

/* Line 1806 of yacc.c  */
#line 9982 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1557:

/* Line 1806 of yacc.c  */
#line 9983 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1558:

/* Line 1806 of yacc.c  */
#line 9987 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1559:

/* Line 1806 of yacc.c  */
#line 9992 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1560:

/* Line 1806 of yacc.c  */
#line 9999 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1561:

/* Line 1806 of yacc.c  */
#line 10006 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1562:

/* Line 1806 of yacc.c  */
#line 10013 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1563:

/* Line 1806 of yacc.c  */
#line 10023 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1564:

/* Line 1806 of yacc.c  */
#line 10030 "parser.y"
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

  case 1565:

/* Line 1806 of yacc.c  */
#line 10040 "parser.y"
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

  case 1566:

/* Line 1806 of yacc.c  */
#line 10050 "parser.y"
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

  case 1567:

/* Line 1806 of yacc.c  */
#line 10060 "parser.y"
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

  case 1568:

/* Line 1806 of yacc.c  */
#line 10073 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1569:

/* Line 1806 of yacc.c  */
#line 10077 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1570:

/* Line 1806 of yacc.c  */
#line 10085 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1571:

/* Line 1806 of yacc.c  */
#line 10093 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1572:

/* Line 1806 of yacc.c  */
#line 10097 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1573:

/* Line 1806 of yacc.c  */
#line 10107 "parser.y"
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

  case 1574:

/* Line 1806 of yacc.c  */
#line 10122 "parser.y"
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

  case 1575:

/* Line 1806 of yacc.c  */
#line 10145 "parser.y"
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

  case 1576:

/* Line 1806 of yacc.c  */
#line 10168 "parser.y"
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

  case 1577:

/* Line 1806 of yacc.c  */
#line 10183 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 10184 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 10185 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1580:

/* Line 1806 of yacc.c  */
#line 10186 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1581:

/* Line 1806 of yacc.c  */
#line 10187 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1582:

/* Line 1806 of yacc.c  */
#line 10188 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1583:

/* Line 1806 of yacc.c  */
#line 10193 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1584:

/* Line 1806 of yacc.c  */
#line 10197 "parser.y"
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

  case 1585:

/* Line 1806 of yacc.c  */
#line 10214 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 10218 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 10224 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 10225 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10226 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10227 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1591:

/* Line 1806 of yacc.c  */
#line 10228 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1592:

/* Line 1806 of yacc.c  */
#line 10229 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1593:

/* Line 1806 of yacc.c  */
#line 10230 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1594:

/* Line 1806 of yacc.c  */
#line 10237 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1595:

/* Line 1806 of yacc.c  */
#line 10241 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1596:

/* Line 1806 of yacc.c  */
#line 10245 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1597:

/* Line 1806 of yacc.c  */
#line 10249 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1598:

/* Line 1806 of yacc.c  */
#line 10253 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1599:

/* Line 1806 of yacc.c  */
#line 10257 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1600:

/* Line 1806 of yacc.c  */
#line 10261 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1601:

/* Line 1806 of yacc.c  */
#line 10265 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1602:

/* Line 1806 of yacc.c  */
#line 10269 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1603:

/* Line 1806 of yacc.c  */
#line 10273 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1612:

/* Line 1806 of yacc.c  */
#line 10297 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1613:

/* Line 1806 of yacc.c  */
#line 10301 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1614:

/* Line 1806 of yacc.c  */
#line 10305 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1615:

/* Line 1806 of yacc.c  */
#line 10312 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1616:

/* Line 1806 of yacc.c  */
#line 10316 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1617:

/* Line 1806 of yacc.c  */
#line 10320 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1618:

/* Line 1806 of yacc.c  */
#line 10327 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10334 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10341 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10351 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10358 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10368 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10375 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10386 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10394 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10395 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10399 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10400 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10404 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10405 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10410 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10414 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1634:

/* Line 1806 of yacc.c  */
#line 10421 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10425 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10432 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10433 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10434 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10438 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10439 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10443 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10444 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10445 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10450 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1645:

/* Line 1806 of yacc.c  */
#line 10454 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1646:

/* Line 1806 of yacc.c  */
#line 10466 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1647:

/* Line 1806 of yacc.c  */
#line 10471 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1648:

/* Line 1806 of yacc.c  */
#line 10479 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1649:

/* Line 1806 of yacc.c  */
#line 10483 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1650:

/* Line 1806 of yacc.c  */
#line 10487 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1651:

/* Line 1806 of yacc.c  */
#line 10491 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1652:

/* Line 1806 of yacc.c  */
#line 10495 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1653:

/* Line 1806 of yacc.c  */
#line 10499 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1654:

/* Line 1806 of yacc.c  */
#line 10503 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1655:

/* Line 1806 of yacc.c  */
#line 10507 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1656:

/* Line 1806 of yacc.c  */
#line 10513 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1657:

/* Line 1806 of yacc.c  */
#line 10514 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1806 of yacc.c  */
#line 18693 "parser.c"
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
#line 10685 "parser.y"


