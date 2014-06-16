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



/* Line 268 of yacc.c  */
#line 770 "parser.c"

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
#line 1324 "parser.c"

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
#define YYLAST   7918

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  814
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1899
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2706

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
    1397,  1399,  1401,  1403,  1406,  1408,  1413,  1415,  1418,  1423,
    1425,  1427,  1428,  1431,  1433,  1435,  1437,  1439,  1441,  1445,
    1450,  1455,  1460,  1464,  1465,  1468,  1469,  1475,  1476,  1479,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,
    1501,  1503,  1505,  1507,  1509,  1511,  1513,  1517,  1519,  1521,
    1524,  1527,  1529,  1531,  1533,  1534,  1536,  1538,  1539,  1541,
    1543,  1548,  1550,  1553,  1556,  1558,  1561,  1563,  1565,  1567,
    1572,  1573,  1577,  1580,  1582,  1584,  1588,  1595,  1598,  1601,
    1603,  1606,  1608,  1610,  1611,  1614,  1616,  1618,  1621,  1625,
    1628,  1632,  1635,  1638,  1640,  1645,  1648,  1652,  1653,  1654,
    1660,  1661,  1663,  1666,  1670,  1672,  1673,  1678,  1682,  1683,
    1686,  1689,  1692,  1694,  1696,  1699,  1702,  1704,  1706,  1708,
    1710,  1712,  1714,  1716,  1718,  1720,  1722,  1727,  1729,  1731,
    1737,  1743,  1747,  1751,  1753,  1755,  1757,  1759,  1761,  1763,
    1765,  1767,  1770,  1773,  1776,  1778,  1780,  1782,  1784,  1785,
    1787,  1789,  1790,  1792,  1794,  1798,  1801,  1802,  1803,  1804,
    1814,  1815,  1820,  1821,  1822,  1826,  1827,  1831,  1833,  1836,
    1841,  1842,  1845,  1848,  1849,  1853,  1857,  1862,  1867,  1871,
    1872,  1874,  1875,  1878,  1879,  1880,  1888,  1889,  1892,  1894,
    1896,  1899,  1901,  1903,  1904,  1911,  1912,  1915,  1918,  1920,
    1921,  1923,  1924,  1925,  1929,  1930,  1933,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,  1960,
    1962,  1964,  1966,  1968,  1970,  1972,  1974,  1976,  1978,  1980,
    1982,  1984,  1986,  1988,  1990,  1992,  1994,  1996,  1998,  2000,
    2002,  2004,  2006,  2008,  2010,  2012,  2014,  2016,  2018,  2020,
    2022,  2024,  2026,  2028,  2030,  2032,  2034,  2037,  2040,  2041,
    2046,  2053,  2057,  2061,  2066,  2070,  2075,  2079,  2083,  2088,
    2093,  2097,  2102,  2106,  2111,  2117,  2121,  2126,  2130,  2134,
    2136,  2138,  2140,  2143,  2144,  2146,  2150,  2154,  2157,  2160,
    2163,  2167,  2171,  2175,  2176,  2178,  2179,  2183,  2184,  2187,
    2189,  2192,  2194,  2196,  2198,  2200,  2202,  2204,  2206,  2208,
    2210,  2212,  2214,  2219,  2221,  2223,  2225,  2227,  2229,  2231,
    2233,  2237,  2241,  2245,  2249,  2253,  2254,  2256,  2257,  2262,
    2267,  2273,  2280,  2281,  2284,  2285,  2287,  2288,  2292,  2296,
    2301,  2302,  2305,  2306,  2310,  2312,  2315,  2320,  2321,  2324,
    2325,  2330,  2337,  2338,  2340,  2342,  2344,  2345,  2346,  2350,
    2352,  2355,  2358,  2362,  2363,  2366,  2369,  2372,  2373,  2377,
    2380,  2385,  2387,  2389,  2391,  2393,  2394,  2397,  2398,  2401,
    2402,  2404,  2405,  2409,  2411,  2414,  2415,  2419,  2422,  2426,
    2427,  2429,  2433,  2437,  2440,  2441,  2446,  2451,  2452,  2454,
    2456,  2458,  2459,  2464,  2468,  2471,  2473,  2476,  2477,  2479,
    2480,  2485,  2489,  2493,  2497,  2501,  2506,  2509,  2514,  2516,
    2517,  2521,  2527,  2528,  2531,  2534,  2537,  2540,  2541,  2544,
    2546,  2548,  2549,  2552,  2553,  2555,  2557,  2560,  2562,  2565,
    2568,  2570,  2572,  2575,  2578,  2580,  2582,  2584,  2586,  2588,
    2592,  2596,  2600,  2604,  2605,  2607,  2608,  2613,  2618,  2625,
    2632,  2641,  2650,  2651,  2653,  2654,  2658,  2661,  2662,  2667,
    2670,  2672,  2676,  2678,  2680,  2682,  2685,  2687,  2689,  2692,
    2695,  2699,  2702,  2706,  2708,  2712,  2715,  2717,  2719,  2721,
    2722,  2725,  2726,  2728,  2729,  2733,  2734,  2736,  2738,  2741,
    2743,  2745,  2747,  2748,  2752,  2754,  2755,  2759,  2761,  2762,
    2766,  2770,  2771,  2775,  2777,  2778,  2785,  2789,  2792,  2794,
    2795,  2797,  2798,  2802,  2808,  2809,  2812,  2813,  2817,  2821,
    2822,  2825,  2827,  2830,  2835,  2837,  2839,  2841,  2843,  2845,
    2847,  2849,  2850,  2854,  2855,  2859,  2861,  2864,  2865,  2869,
    2872,  2874,  2876,  2878,  2881,  2883,  2885,  2887,  2888,  2892,
    2895,  2901,  2903,  2906,  2909,  2912,  2914,  2916,  2918,  2921,
    2923,  2926,  2931,  2934,  2935,  2937,  2939,  2941,  2943,  2948,
    2949,  2952,  2956,  2960,  2961,  2965,  2966,  2970,  2974,  2979,
    2980,  2985,  2990,  2997,  2998,  3000,  3001,  3005,  3010,  3016,
    3018,  3020,  3022,  3024,  3025,  3029,  3030,  3034,  3037,  3039,
    3040,  3044,  3047,  3048,  3053,  3056,  3057,  3059,  3061,  3063,
    3065,  3069,  3070,  3073,  3075,  3079,  3083,  3084,  3088,  3090,
    3092,  3094,  3098,  3106,  3107,  3112,  3120,  3121,  3124,  3125,
    3128,  3131,  3135,  3139,  3143,  3146,  3147,  3151,  3153,  3155,
    3156,  3158,  3160,  3161,  3165,  3168,  3170,  3171,  3176,  3181,
    3182,  3184,  3185,  3190,  3195,  3196,  3199,  3203,  3204,  3206,
    3208,  3209,  3214,  3219,  3226,  3227,  3230,  3231,  3234,  3236,
    3239,  3243,  3244,  3246,  3247,  3251,  3253,  3255,  3257,  3259,
    3261,  3263,  3265,  3267,  3269,  3271,  3276,  3280,  3282,  3285,
    3288,  3291,  3294,  3297,  3300,  3303,  3306,  3309,  3314,  3318,
    3323,  3325,  3328,  3332,  3334,  3337,  3341,  3345,  3346,  3350,
    3351,  3359,  3360,  3366,  3367,  3370,  3371,  3374,  3375,  3379,
    3380,  3383,  3388,  3389,  3392,  3397,  3398,  3403,  3408,  3409,
    3413,  3414,  3419,  3421,  3423,  3425,  3428,  3431,  3434,  3437,
    3439,  3441,  3444,  3446,  3447,  3449,  3450,  3455,  3458,  3459,
    3462,  3465,  3470,  3475,  3476,  3478,  3480,  3482,  3484,  3486,
    3487,  3492,  3498,  3500,  3503,  3505,  3509,  3513,  3514,  3519,
    3520,  3522,  3523,  3528,  3533,  3540,  3547,  3548,  3550,  3553,
    3554,  3556,  3557,  3561,  3563,  3566,  3567,  3571,  3577,  3578,
    3582,  3585,  3586,  3588,  3590,  3591,  3596,  3603,  3604,  3608,
    3610,  3614,  3617,  3620,  3623,  3627,  3628,  3632,  3633,  3637,
    3638,  3642,  3643,  3645,  3646,  3650,  3652,  3654,  3656,  3658,
    3666,  3667,  3669,  3671,  3673,  3675,  3677,  3679,  3684,  3686,
    3689,  3691,  3694,  3698,  3699,  3701,  3704,  3706,  3711,  3713,
    3715,  3717,  3718,  3723,  3729,  3730,  3733,  3734,  3739,  3743,
    3747,  3749,  3751,  3753,  3755,  3756,  3758,  3761,  3762,  3765,
    3766,  3769,  3772,  3773,  3776,  3777,  3780,  3783,  3784,  3787,
    3788,  3791,  3794,  3795,  3798,  3799,  3802,  3805,  3807,  3810,
    3812,  3814,  3817,  3820,  3823,  3825,  3827,  3830,  3833,  3836,
    3837,  3840,  3841,  3844,  3845,  3848,  3850,  3852,  3853,  3856,
    3858,  3861,  3864,  3866,  3868,  3870,  3872,  3874,  3876,  3878,
    3880,  3882,  3884,  3886,  3888,  3890,  3892,  3894,  3896,  3898,
    3900,  3902,  3904,  3906,  3908,  3910,  3912,  3914,  3917,  3919,
    3921,  3923,  3925,  3927,  3929,  3931,  3935,  3936,  3938,  3940,
    3944,  3948,  3950,  3954,  3958,  3960,  3964,  3966,  3969,  3972,
    3974,  3978,  3980,  3982,  3986,  3988,  3992,  3994,  3998,  4000,
    4003,  4006,  4008,  4010,  4012,  4015,  4017,  4019,  4021,  4024,
    4026,  4027,  4030,  4032,  4034,  4036,  4040,  4042,  4044,  4047,
    4049,  4051,  4053,  4056,  4058,  4060,  4062,  4064,  4066,  4068,
    4071,  4073,  4075,  4079,  4081,  4084,  4086,  4088,  4090,  4092,
    4095,  4098,  4101,  4106,  4110,  4112,  4114,  4117,  4119,  4121,
    4123,  4125,  4127,  4129,  4131,  4134,  4137,  4140,  4142,  4144,
    4146,  4148,  4150,  4152,  4154,  4156,  4158,  4160,  4162,  4164,
    4166,  4168,  4170,  4172,  4174,  4176,  4178,  4180,  4182,  4184,
    4186,  4188,  4190,  4192,  4195,  4197,  4201,  4204,  4207,  4209,
    4211,  4213,  4217,  4220,  4223,  4225,  4227,  4231,  4235,  4240,
    4246,  4248,  4250,  4252,  4254,  4256,  4258,  4260,  4262,  4264,
    4266,  4268,  4271,  4273,  4277,  4279,  4281,  4283,  4285,  4287,
    4289,  4291,  4294,  4300,  4306,  4312,  4317,  4323,  4329,  4335,
    4338,  4341,  4343,  4345,  4347,  4349,  4351,  4353,  4355,  4357,
    4358,  4363,  4369,  4370,  4374,  4377,  4379,  4383,  4387,  4389,
    4393,  4395,  4399,  4400,  4401,  4403,  4404,  4406,  4407,  4409,
    4410,  4413,  4414,  4417,  4418,  4420,  4422,  4423,  4425,  4426,
    4428,  4431,  4432,  4435,  4436,  4440,  4442,  4444,  4446,  4448,
    4450,  4452,  4454,  4456,  4457,  4460,  4462,  4464,  4466,  4468,
    4470,  4472,  4474,  4476,  4478,  4480,  4482,  4484,  4486,  4488,
    4490,  4492,  4494,  4496,  4498,  4500,  4502,  4504,  4506,  4508,
    4510,  4512,  4514,  4516,  4518,  4520,  4522,  4524,  4526,  4528,
    4530,  4532,  4534,  4536,  4538,  4540,  4542,  4544,  4546,  4548,
    4550,  4552,  4554,  4556,  4558,  4560,  4562,  4564,  4566,  4568,
    4570,  4572,  4574,  4576,  4578,  4580,  4582,  4584,  4586,  4588,
    4590,  4592,  4594,  4596,  4598,  4600,  4601,  4603,  4604,  4606,
    4607,  4609,  4610,  4612,  4613,  4615,  4616,  4618,  4619,  4621,
    4622,  4624,  4625,  4627,  4628,  4630,  4631,  4633,  4634,  4636,
    4637,  4639,  4640,  4642,  4643,  4645,  4646,  4648,  4649,  4651,
    4654,  4655,  4657,  4658,  4660,  4661,  4663,  4664,  4666,  4667,
    4669,  4671,  4672,  4674,  4675,  4677,  4679,  4680,  4682,  4684,
    4685,  4688,  4691,  4692,  4694,  4695,  4697,  4698,  4700,  4701,
    4703,  4705,  4706,  4708,  4709,  4711,  4712,  4715,  4717,  4719,
    4720,  4722,  4723,  4725,  4726,  4728,  4729,  4731,  4732,  4734,
    4735,  4737,  4738,  4740,  4741,  4743,  4746,  4747,  4749,  4750,
    4752,  4753,  4755,  4756,  4758,  4759,  4761,  4762,  4764,  4765,
    4767,  4768,  4770,  4772,  4773,  4775,  4776,  4780,  4781,  4783,
    4786,  4788,  4790,  4792,  4794,  4796,  4798,  4800,  4802,  4804,
    4806,  4808,  4810,  4812,  4814,  4816,  4818,  4820,  4822,  4824,
    4826,  4828,  4831,  4834,  4836,  4838,  4840,  4842,  4844,  4846,
    4849,  4851,  4855,  4858,  4860,  4862,  4864,  4867,  4869,  4872,
    4874,  4877,  4879,  4882,  4884,  4887,  4889,  4892,  4894,  4897
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
     648,   649,   650,   530,   679,   732,   734,   736,   788,   531,
     802,    -1,    -1,   341,   451,   535,   536,   533,   537,   451,
      -1,   200,   451,   535,   536,   451,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1269,   538,  1284,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1300,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1269,  1219,  1311,    -1,  1317,
    1269,  1186,    -1,   396,  1269,  1219,    -1,  1257,    59,  1269,
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
     572,   573,    -1,  1269,    96,    -1,  1219,  1269,  1190,    -1,
    1269,  1190,   574,    -1,   575,    -1,    -1,   575,    -1,  1037,
    1281,  1190,    -1,   575,  1037,  1281,  1190,    -1,    -1,    11,
    1190,   577,  1269,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1258,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1270,
     590,    -1,  1191,    -1,   589,  1191,    -1,  1220,    -1,   590,
    1220,    -1,    58,  1190,  1269,   592,    -1,   593,    -1,   592,
     593,    -1,  1222,    -1,  1222,   442,  1222,    -1,   257,  1190,
    1269,   256,    -1,    98,  1287,  1269,   256,   596,    -1,    -1,
    1300,   328,   256,    -1,   108,  1269,    68,    -1,   301,   405,
    1269,   468,   400,    -1,   100,  1269,  1185,    -1,    96,   423,
    1269,  1185,    -1,   390,  1269,  1185,    -1,   164,  1269,  1185,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1243,  1190,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1297,   614,   613,   615,    -1,    29,  1297,   614,   612,
     616,    -1,    29,  1297,   614,   119,   616,    -1,    29,  1297,
     614,   238,   616,    -1,    29,  1297,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1261,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1216,    -1,    -1,   256,    -1,  1216,    -1,     4,  1276,  1269,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1285,
    1271,  1269,   632,  1237,    -1,  1301,  1269,   504,    -1,   622,
     423,  1269,  1185,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1276,  1269,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1310,    -1,
     503,   262,   309,   274,  1310,    -1,   503,   385,    -1,   315,
    1269,   628,    -1,   628,    -1,   220,    -1,  1285,  1255,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1257,  1269,  1189,
      -1,   351,   113,  1269,   419,    -1,   351,  1271,  1269,   632,
      -1,  1185,    -1,  1185,   452,  1184,    -1,  1185,   414,  1269,
    1184,    -1,   359,  1271,  1269,  1185,    -1,   372,   635,  1252,
      -1,   287,    -1,  1219,    -1,   404,  1300,   637,    -1,     9,
    1282,    -1,   287,  1282,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1252,  1262,  1175,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1261,  1293,  1259,   645,    -1,   646,    -1,   645,   646,
      -1,  1176,   647,    -1,    -1,   331,  1219,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1176,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1269,   171,    -1,  1269,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1259,
    1219,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1259,  1219,  1258,    -1,   351,  1259,  1219,   446,  1219,  1258,
      -1,   351,  1269,   499,  1264,  1290,   661,   662,  1258,   660,
      -1,    -1,   114,  1280,  1185,    -1,    -1,  1263,  1219,    -1,
      -1,   446,  1219,    -1,   239,  1312,  1308,    -1,   498,   306,
     665,  1269,   666,    -1,   498,   306,   174,  1269,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1216,    -1,   102,  1312,
    1187,    -1,   250,  1269,  1189,  1275,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1300,   187,
    1254,  1189,    -1,   465,  1189,    -1,    48,  1189,    -1,   352,
    1276,  1269,   504,    -1,    62,  1269,   504,    -1,   677,   678,
      -1,   366,  1269,    -1,   368,  1251,    -1,  1190,    -1,   678,
    1190,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1235,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1269,   204,
      -1,  1223,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1279,   691,    -1,  1213,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1253,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1213,    -1,  1269,   171,   702,    -1,    -1,
      26,   256,    -1,  1269,   204,    -1,   327,    -1,   706,    -1,
     491,  1269,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1288,    -1,    41,   476,    -1,
      44,  1288,    -1,    44,   476,    -1,    43,  1288,    -1,    43,
     476,    -1,    42,  1288,    -1,    42,   476,    -1,    40,  1288,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1289,   241,  1247,    -1,  1289,   468,
    1247,    -1,   305,  1219,   713,  1295,   714,   711,    -1,    -1,
     425,  1219,    -1,   305,  1219,   713,  1295,   714,   715,   718,
      -1,    -1,   446,  1219,    -1,    -1,   114,  1280,  1185,    -1,
     716,    -1,    -1,   716,   717,  1271,  1269,  1184,    -1,    27,
      -1,   115,    -1,    -1,   220,  1256,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1286,    -1,   434,  1272,
      -1,    45,  1298,   510,    -1,    36,    -1,    -1,   498,  1270,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1223,
      -1,  1223,   442,  1223,    -1,    -1,  1299,   453,  1269,  1223,
      -1,   363,  1216,    -1,   363,  1216,   442,  1216,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1177,   740,   741,   451,   758,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1269,   204,
      -1,    61,  1269,  1203,    -1,   743,    -1,   748,    -1,  1325,
     744,    -1,   745,   746,    -1,   745,    -1,   746,    -1,   176,
      -1,   747,    -1,   746,   747,    -1,  1212,    -1,   321,  1274,
     749,   751,    -1,   750,    -1,   750,  1309,    -1,   750,  1309,
     750,  1303,    -1,  1221,    -1,  1212,    -1,    -1,   751,   752,
      -1,   753,    -1,   754,    -1,   755,    -1,   756,    -1,   757,
      -1,   210,  1269,   750,    -1,   177,  1318,  1269,   750,    -1,
     240,  1319,  1269,   750,    -1,   240,  1318,  1269,   750,    -1,
     187,  1269,   750,    -1,    -1,   758,   759,    -1,    -1,   686,
     687,   760,   761,   451,    -1,    -1,   761,   762,    -1,   763,
      -1,   767,    -1,   775,    -1,   781,    -1,   704,    -1,   787,
      -1,   709,    -1,   721,    -1,   782,    -1,   723,    -1,   785,
      -1,   770,    -1,   725,    -1,   773,    -1,   786,    -1,   710,
      -1,   774,    -1,   472,  1269,   764,    -1,  1323,    -1,  1321,
      -1,  1319,   765,    -1,  1320,   766,    -1,  1318,    -1,  1322,
      -1,  1324,    -1,    -1,  1212,    -1,   176,    -1,    -1,  1212,
      -1,   176,    -1,   285,   209,  1269,   768,    -1,  1219,    -1,
     329,  1219,    -1,   463,  1219,    -1,   769,    -1,   285,   321,
      -1,   286,    -1,   321,    -1,   285,    -1,   431,  1279,  1196,
     771,    -1,    -1,   373,  1280,   772,    -1,   484,  1212,    -1,
    1212,    -1,   176,    -1,   333,   501,  1152,    -1,   499,  1212,
     196,  1198,    49,  1198,    -1,   776,   777,    -1,   252,   779,
      -1,   780,    -1,   778,   780,    -1,   329,    -1,   463,    -1,
      -1,   299,   232,    -1,   299,    -1,  1221,    -1,   285,   321,
      -1,   309,   285,   321,    -1,   783,   784,    -1,  1302,  1278,
    1270,    -1,  1303,  1251,    -1,   778,  1221,    -1,  1221,    -1,
     414,  1269,  1198,  1244,    -1,   209,  1266,    -1,   491,  1269,
     119,    -1,    -1,    -1,   389,   394,   451,   789,   790,    -1,
      -1,   791,    -1,   792,   451,    -1,   791,   792,   451,    -1,
     696,    -1,    -1,   686,   687,   793,   794,    -1,   686,     1,
     451,    -1,    -1,   794,   795,    -1,    45,   252,    -1,    45,
     389,    -1,    38,    -1,    46,    -1,   160,   156,    -1,   160,
     158,    -1,   211,    -1,   265,    -1,   378,    -1,   473,    -1,
     318,    -1,   243,    -1,    32,    -1,   395,    -1,   371,    -1,
     198,    -1,   345,    56,  1269,  1203,    -1,   345,    -1,   456,
      -1,   252,  1277,  1269,   798,  1205,    -1,  1302,  1277,  1269,
     799,  1205,    -1,   189,  1269,  1205,    -1,    35,  1269,  1205,
      -1,   705,    -1,   723,    -1,   801,    -1,   721,    -1,   709,
      -1,   725,    -1,   704,    -1,   800,    -1,   497,  1212,    -1,
     196,  1204,    -1,   446,  1212,    -1,   329,    -1,   463,    -1,
     270,    -1,   458,    -1,    -1,   796,    -1,   797,    -1,    -1,
     796,    -1,   797,    -1,   305,  1219,  1295,    -1,  1269,   204,
      -1,    -1,    -1,    -1,   337,   122,   806,   814,   451,   803,
     815,   804,   817,    -1,    -1,   805,   828,   451,   817,    -1,
      -1,    -1,   497,   807,   809,    -1,    -1,    55,   808,   809,
      -1,   810,    -1,   809,   810,    -1,   811,   812,   813,   504,
      -1,    -1,  1256,   357,    -1,  1256,   498,    -1,    -1,   410,
    1269,    32,    -1,   410,  1269,   110,    -1,   476,   410,  1269,
      32,    -1,   476,   410,  1269,  1219,    -1,   410,  1269,  1219,
      -1,    -1,   312,    -1,    -1,   376,   504,    -1,    -1,    -1,
     109,   451,   816,   817,   129,   109,   451,    -1,    -1,   817,
     818,    -1,   819,    -1,   822,    -1,   828,   451,    -1,   823,
      -1,   451,    -1,    -1,   504,   394,   824,   451,   820,   821,
      -1,    -1,  1108,   451,    -1,   504,   451,    -1,   504,    -1,
      -1,  1219,    -1,    -1,    -1,   826,   827,   828,    -1,    -1,
     829,   830,    -1,   828,   830,    -1,   831,    -1,   846,    -1,
     851,    -1,   855,    -1,   860,    -1,   875,    -1,   878,    -1,
     886,    -1,   882,    -1,   887,    -1,   888,    -1,   893,    -1,
     907,    -1,   911,    -1,   914,    -1,   928,    -1,   931,    -1,
     934,    -1,   937,    -1,   941,    -1,   942,    -1,   946,    -1,
     956,    -1,   959,    -1,   976,    -1,   978,    -1,   981,    -1,
     985,    -1,   991,    -1,  1003,    -1,  1011,    -1,  1012,    -1,
    1015,    -1,  1016,    -1,  1020,    -1,  1025,    -1,  1026,    -1,
    1034,    -1,  1049,    -1,  1059,    -1,  1068,    -1,  1073,    -1,
    1080,    -1,  1084,    -1,  1086,    -1,  1089,    -1,  1092,    -1,
    1096,    -1,  1121,    -1,   285,   399,    -1,     1,  1248,    -1,
      -1,     3,   832,   833,   845,    -1,   834,   836,   840,   841,
     842,  1129,    -1,  1212,   196,   835,    -1,  1212,   196,  1303,
      -1,  1212,   196,   103,   509,    -1,  1212,   196,   103,    -1,
    1212,   196,   104,   508,    -1,  1212,   196,   104,    -1,  1212,
     196,   105,    -1,  1212,   196,   162,   237,    -1,  1212,   196,
     165,   423,    -1,  1212,   196,   443,    -1,  1212,   196,   493,
     276,    -1,  1212,   196,    69,    -1,  1212,   196,   155,  1129,
      -1,  1212,   196,   153,  1201,  1129,    -1,  1212,   196,    24,
      -1,  1212,   196,    25,  1129,    -1,  1212,   196,  1179,    -1,
    1212,   196,   504,    -1,  1212,    -1,   308,    -1,   254,    -1,
     252,   299,    -1,    -1,   837,    -1,  1254,   838,   839,    -1,
    1254,   839,   838,    -1,  1254,   838,    -1,  1254,   839,    -1,
      30,  1201,    -1,   252,  1277,  1205,    -1,  1302,  1277,  1205,
      -1,   331,  1277,  1205,    -1,    -1,   197,    -1,    -1,   272,
    1269,    47,    -1,    -1,   503,   843,    -1,   844,    -1,   843,
     844,    -1,    32,    -1,    38,    -1,    46,    -1,    91,    -1,
     198,    -1,   211,    -1,   243,    -1,   263,    -1,   265,    -1,
     288,    -1,   318,    -1,   345,    56,  1269,  1203,    -1,   345,
      -1,   371,    -1,   378,    -1,   395,    -1,   473,    -1,   483,
      -1,   489,    -1,   189,  1269,  1205,    -1,    35,  1269,  1205,
      -1,   391,   482,  1151,    -1,   391,   123,  1151,    -1,   444,
    1250,  1206,    -1,    -1,   130,    -1,    -1,     5,   847,   848,
     850,    -1,  1194,   446,  1171,  1135,    -1,  1194,   849,   203,
    1171,  1135,    -1,    94,  1212,   446,  1212,  1244,  1135,    -1,
      -1,   446,  1195,    -1,    -1,   131,    -1,    -1,    10,   852,
     853,    -1,  1212,  1238,   854,    -1,  1165,    57,  1239,   854,
      -1,    -1,   376,  1193,    -1,    -1,    18,   856,   857,    -1,
     858,    -1,   857,   858,    -1,  1181,   446,   859,  1181,    -1,
      -1,   339,   446,    -1,    -1,    51,   861,   862,   874,    -1,
     863,  1204,   864,   869,   872,   873,    -1,    -1,   422,    -1,
     424,    -1,   271,    -1,    -1,    -1,   497,   865,   866,    -1,
     867,    -1,   866,   867,    -1,   868,   308,    -1,   868,   812,
    1195,    -1,    -1,  1256,   357,    -1,  1256,    87,    -1,  1256,
     498,    -1,    -1,   870,  1268,  1212,    -1,   870,   871,    -1,
     870,     6,  1279,  1212,    -1,   376,    -1,   203,    -1,   460,
      -1,   308,    -1,    -1,  1306,   825,    -1,    -1,   294,   825,
      -1,    -1,   132,    -1,    -1,    52,   876,   877,    -1,  1203,
      -1,   877,  1203,    -1,    -1,    60,   879,   880,    -1,  1176,
     881,    -1,   880,  1176,   881,    -1,    -1,  1313,    -1,  1313,
    1262,   362,    -1,  1300,   287,   380,    -1,  1300,   262,    -1,
      -1,    74,   883,   884,   885,    -1,  1171,  1304,  1165,  1135,
      -1,    -1,   133,    -1,    71,    -1,    88,    -1,    -1,   111,
     889,   890,   892,    -1,  1176,  1285,  1148,    -1,   454,   891,
      -1,  1176,    -1,   891,  1176,    -1,    -1,   134,    -1,    -1,
     119,   894,   895,   906,    -1,  1203,   487,  1132,    -1,  1203,
     488,  1132,    -1,  1203,   485,  1132,    -1,  1203,   486,  1132,
      -1,  1194,   899,   903,  1132,    -1,   896,  1132,    -1,  1195,
     503,   904,  1132,    -1,   898,    -1,    -1,   896,   897,   898,
      -1,  1195,   837,   900,   841,   902,    -1,    -1,   484,  1179,
      -1,   484,   504,    -1,   484,   335,    -1,   484,    96,    -1,
      -1,   484,   901,    -1,    96,    -1,    97,    -1,    -1,   503,
     904,    -1,    -1,   298,    -1,   905,    -1,   904,   905,    -1,
      38,    -1,    45,   252,    -1,    45,   389,    -1,    46,    -1,
      91,    -1,   160,   156,    -1,   160,   158,    -1,   211,    -1,
     265,    -1,   318,    -1,   378,    -1,   473,    -1,   189,  1269,
    1205,    -1,    35,  1269,  1205,    -1,   391,   482,  1151,    -1,
     391,   123,  1151,    -1,    -1,   135,    -1,    -1,   121,   908,
     909,   910,    -1,  1195,   228,  1171,  1135,    -1,  1195,   228,
    1195,   203,  1171,  1135,    -1,  1195,    49,  1195,   203,  1171,
    1135,    -1,  1195,   228,  1195,   203,  1172,   361,  1172,  1135,
      -1,  1195,    49,  1195,   203,  1172,   361,  1172,  1135,    -1,
      -1,   136,    -1,    -1,   152,   912,   913,    -1,   256,   864,
      -1,    -1,   163,   915,   916,   927,    -1,   917,   919,    -1,
     918,    -1,   917,    17,   918,    -1,  1153,    -1,   464,    -1,
     453,    -1,   920,   922,    -1,   920,    -1,   921,    -1,   920,
     921,    -1,   923,   825,    -1,   501,   316,   825,    -1,   501,
     924,    -1,   923,   501,   924,    -1,   925,    -1,   924,    17,
     925,    -1,  1154,   926,    -1,    21,    -1,   464,    -1,   453,
      -1,    -1,   442,  1153,    -1,    -1,   137,    -1,    -1,   168,
     929,   930,    -1,    -1,   340,    -1,   199,    -1,   324,   101,
      -1,   324,    -1,   394,    -1,   323,    -1,    -1,   195,   932,
     933,    -1,  1192,    -1,    -1,   202,   935,   936,    -1,  1216,
      -1,    -1,   205,   938,   939,    -1,  1296,  1180,   940,    -1,
      -1,   114,  1280,  1212,    -1,   206,    -1,    -1,   215,   943,
    1152,  1294,   944,   945,    -1,   825,   128,   825,    -1,   128,
     825,    -1,   825,    -1,    -1,   139,    -1,    -1,   222,   947,
     948,    -1,  1192,   949,   950,   951,   955,    -1,    -1,  1300,
     175,    -1,    -1,     9,  1296,   498,    -1,   954,  1296,   498,
      -1,    -1,   365,   952,    -1,   953,    -1,   952,   953,    -1,
     954,  1260,    49,  1195,    -1,    12,    -1,    15,    -1,   301,
      -1,    16,    -1,   302,    -1,   277,    -1,   278,    -1,    -1,
    1294,  1296,   110,    -1,    -1,   224,   957,   958,    -1,  1177,
      -1,   958,  1177,    -1,    -1,   227,   960,   961,    -1,   962,
     963,    -1,  1212,    -1,  1223,    -1,  1226,    -1,   964,   966,
      -1,   964,    -1,   966,    -1,   967,    -1,    -1,   436,   965,
     968,    -1,   365,   970,    -1,    92,  1201,   446,  1202,   974,
      -1,   969,    -1,   968,   969,    -1,  1201,   188,    -1,    57,
     974,    -1,     9,    -1,   241,    -1,   468,    -1,  1201,   974,
      -1,   971,    -1,   970,   971,    -1,    57,    49,  1201,   974,
      -1,   972,   973,    -1,    -1,     9,    -1,   241,    -1,   177,
      -1,   468,    -1,  1201,    49,  1202,   974,    -1,    -1,   974,
     975,    -1,    37,  1267,  1195,    -1,     8,  1267,  1195,    -1,
      -1,   269,   977,  1051,    -1,    -1,   273,   979,   980,    -1,
    1195,   446,  1192,    -1,    94,  1195,   446,  1192,    -1,    -1,
     275,   982,   983,   984,    -1,  1195,    49,  1171,  1135,    -1,
    1195,    49,  1195,   203,  1171,  1135,    -1,    -1,   140,    -1,
      -1,   311,   986,   987,    -1,   988,   989,  1175,   990,    -1,
     987,   988,   989,  1175,   990,    -1,   225,    -1,   317,    -1,
     233,    -1,   170,    -1,    -1,   404,  1300,   637,    -1,    -1,
    1300,   287,   380,    -1,  1300,   262,    -1,   379,    -1,    -1,
     324,   992,   993,    -1,   997,   998,    -1,    -1,   998,   994,
     825,   995,    -1,   998,   996,    -1,    -1,   141,    -1,   141,
      -1,   451,    -1,  1181,    -1,  1181,   442,  1181,    -1,    -1,
    1204,   445,    -1,   190,    -1,   999,   481,  1000,    -1,   999,
     499,  1001,    -1,    -1,  1300,   439,  1126,    -1,   168,    -1,
    1152,    -1,  1002,    -1,  1001,     8,  1002,    -1,  1212,   196,
    1195,    49,  1195,   481,  1152,    -1,    -1,   349,  1004,  1005,
    1010,    -1,  1176,  1241,  1285,  1006,  1007,  1008,  1009,    -1,
      -1,   228,  1212,    -1,    -1,   217,   262,    -1,  1300,   262,
      -1,  1300,   236,   262,    -1,  1300,   287,   262,    -1,  1300,
     216,   262,    -1,  1300,   500,    -1,    -1,   237,  1269,  1212,
      -1,  1148,    -1,  1142,    -1,    -1,   143,    -1,   350,    -1,
      -1,   360,  1013,  1014,    -1,  1173,  1124,    -1,   374,    -1,
      -1,   375,  1017,  1018,  1019,    -1,  1176,  1285,  1006,  1141,
      -1,    -1,   144,    -1,    -1,   381,  1021,  1022,  1024,    -1,
    1173,  1124,  1023,  1148,    -1,    -1,  1300,   262,    -1,  1300,
     287,   262,    -1,    -1,   145,    -1,   385,    -1,    -1,   393,
    1027,  1028,  1033,    -1,  1174,  1029,  1030,  1031,    -1,     9,
    1174,  1030,   501,  1153,   825,    -1,    -1,   499,  1212,    -1,
      -1,   129,   825,    -1,  1032,    -1,  1032,  1031,    -1,   501,
    1152,   825,    -1,    -1,   146,    -1,    -1,   403,  1035,  1036,
      -1,  1039,    -1,  1040,    -1,  1043,    -1,  1044,    -1,  1045,
      -1,  1047,    -1,   309,    -1,   307,    -1,   482,    -1,   123,
      -1,   153,  1201,   446,  1201,    -1,  1209,    31,  1041,    -1,
    1042,    -1,  1041,  1042,    -1,    38,  1037,    -1,    46,  1037,
      -1,   211,  1037,    -1,   265,  1037,    -1,   378,  1037,    -1,
     473,  1037,    -1,   243,  1037,    -1,   318,  1037,    -1,  1192,
     446,   152,  1200,    -1,  1192,   446,  1195,    -1,  1192,  1038,
      49,  1195,    -1,  1046,    -1,  1045,  1046,    -1,  1178,   446,
    1037,    -1,  1048,    -1,  1047,  1048,    -1,  1192,   446,   464,
      -1,  1192,   446,   453,    -1,    -1,   412,  1050,  1051,    -1,
      -1,  1210,  1053,  1055,  1056,  1052,  1057,  1058,    -1,    -1,
    1053,  1280,   717,  1271,  1054,    -1,    -1,  1054,  1216,    -1,
      -1,  1316,  1265,    -1,    -1,  1301,  1269,  1185,    -1,    -1,
     497,  1175,    -1,   225,   337,  1269,   997,    -1,    -1,   203,
    1175,    -1,   317,   337,  1269,   997,    -1,    -1,   421,  1060,
    1061,  1067,    -1,  1176,  1063,  1062,  1148,    -1,    -1,  1300,
    1315,  1165,    -1,    -1,   237,  1269,  1064,  1212,    -1,   177,
      -1,   240,    -1,  1158,    -1,  1242,  1159,    -1,  1242,  1160,
      -1,  1242,  1161,    -1,  1242,  1162,    -1,  1065,    -1,  1066,
      -1,   290,  1158,    -1,   293,    -1,    -1,   147,    -1,    -1,
     426,   387,  1069,  1070,    -1,   426,  1072,    -1,    -1,   376,
    1195,    -1,   203,  1195,    -1,  1300,   161,  1292,  1071,    -1,
    1300,   289,  1292,  1071,    -1,    -1,  1195,    -1,   256,    -1,
     416,    -1,   510,    -1,   346,    -1,    -1,   427,  1074,  1075,
    1079,    -1,  1076,   228,  1212,  1078,  1138,    -1,  1077,    -1,
    1076,  1077,    -1,  1195,    -1,   112,  1256,   410,    -1,   112,
    1256,  1195,    -1,    -1,  1300,   330,  1269,  1212,    -1,    -1,
     148,    -1,    -1,   430,  1081,  1082,  1083,    -1,  1194,   196,
    1171,  1135,    -1,  1194,   196,  1195,   203,  1171,  1135,    -1,
      94,  1212,   196,  1212,  1244,  1135,    -1,    -1,   149,    -1,
     432,  1085,    -1,    -1,   336,    -1,    -1,   438,  1087,  1088,
      -1,  1177,    -1,  1088,  1177,    -1,    -1,   469,  1090,  1091,
      -1,  1212,   196,  1201,   446,  1202,    -1,    -1,   475,  1093,
    1094,    -1,  1176,  1095,    -1,    -1,   351,    -1,   353,    -1,
      -1,   480,  1097,  1098,  1107,    -1,  1212,  1099,  1102,  1078,
    1106,  1138,    -1,    -1,   112,  1256,  1100,    -1,  1101,    -1,
    1100,   313,  1101,    -1,  1236,  1201,    -1,   228,  1103,    -1,
    1102,  1103,    -1,  1212,  1104,  1105,    -1,    -1,   113,  1264,
    1212,    -1,    -1,    95,  1264,  1212,    -1,    -1,   436,  1264,
    1212,    -1,    -1,   150,    -1,    -1,   492,  1109,  1110,    -1,
    1111,    -1,  1114,    -1,  1118,    -1,  1119,    -1,  1112,  1250,
    1291,  1305,  1283,  1280,  1113,    -1,    -1,   204,    -1,  1175,
      -1,   225,    -1,   317,    -1,   233,    -1,   170,    -1,  1262,
     107,  1280,  1115,    -1,  1116,    -1,  1115,  1116,    -1,  1182,
      -1,     9,   338,    -1,     9,  1117,  1216,    -1,    -1,   358,
      -1,   358,   306,    -1,   306,    -1,  1112,    37,   367,  1212,
      -1,  1120,    -1,   166,    -1,   127,    -1,    -1,   507,  1122,
    1123,  1128,    -1,  1173,  1124,  1125,  1023,  1127,    -1,    -1,
     196,  1208,    -1,    -1,  1126,  1249,  1205,  1273,    -1,  1126,
    1249,  1179,    -1,  1126,  1249,   321,    -1,    37,    -1,     8,
      -1,  1148,    -1,  1145,    -1,    -1,   151,    -1,  1130,  1131,
      -1,    -1,   165,   825,    -1,    -1,   294,   825,    -1,  1133,
    1134,    -1,    -1,   165,   825,    -1,    -1,   294,   825,    -1,
    1136,  1137,    -1,    -1,   411,   825,    -1,    -1,   297,   825,
      -1,  1139,  1140,    -1,    -1,   461,   825,    -1,    -1,   296,
     825,    -1,  1143,  1144,    -1,  1143,    -1,  1143,  1144,    -1,
    1143,    -1,  1144,    -1,   129,   825,    -1,   291,   825,    -1,
    1146,  1147,    -1,  1146,    -1,  1147,    -1,   157,   825,    -1,
     292,   825,    -1,  1149,  1150,    -1,    -1,   231,   825,    -1,
      -1,   295,   825,    -1,    -1,  1207,  1314,    -1,  1153,    -1,
    1154,    -1,    -1,  1155,  1156,    -1,  1157,    -1,  1156,   232,
      -1,  1156,  1157,    -1,  1195,    -1,   462,    -1,   448,    -1,
     463,    -1,   458,    -1,   459,    -1,   450,    -1,   169,    -1,
    1158,    -1,  1159,    -1,  1160,    -1,  1161,    -1,  1162,    -1,
     293,    -1,   290,    -1,    20,    -1,   313,    -1,   308,    -1,
     301,    -1,    12,    -1,    13,    -1,    14,    -1,   332,    -1,
     284,    -1,   452,    -1,   159,  1296,    -1,   455,    -1,   207,
      -1,   457,    -1,   246,    -1,   208,    -1,   247,    -1,  1165,
      -1,  1163,  1164,  1165,    -1,    -1,    70,    -1,   398,    -1,
    1165,   463,  1166,    -1,  1165,   458,  1166,    -1,  1166,    -1,
    1166,   459,  1167,    -1,  1166,   450,  1167,    -1,  1167,    -1,
    1168,   169,  1167,    -1,  1168,    -1,   463,  1169,    -1,   458,
    1169,    -1,  1169,    -1,   462,  1165,   448,    -1,  1198,    -1,
     251,    -1,   251,  1307,   504,    -1,   253,    -1,   253,  1307,
     504,    -1,   322,    -1,   322,  1307,   504,    -1,  1172,    -1,
    1171,  1172,    -1,  1193,  1244,    -1,  1216,    -1,  1216,    -1,
    1176,    -1,  1175,  1176,    -1,   504,    -1,   504,    -1,  1179,
      -1,  1178,  1179,    -1,   271,    -1,    -1,  1180,  1181,    -1,
    1182,    -1,  1216,    -1,  1183,    -1,  1183,  1307,  1183,    -1,
     256,    -1,  1185,    -1,  1184,  1185,    -1,  1216,    -1,   504,
      -1,  1188,    -1,  1187,  1188,    -1,   504,    -1,  1185,    -1,
     256,    -1,   504,    -1,   504,    -1,  1193,    -1,  1192,  1193,
      -1,  1214,    -1,  1224,    -1,     6,  1279,  1213,    -1,  1195,
      -1,  1194,  1195,    -1,  1212,    -1,  1223,    -1,  1226,    -1,
    1170,    -1,   245,  1213,    -1,   245,  1224,    -1,   245,  1226,
      -1,     6,  1279,  1199,  1200,    -1,     6,  1279,  1213,    -1,
     271,    -1,  1198,    -1,  1196,  1198,    -1,  1212,    -1,  1224,
      -1,  1226,    -1,  1212,    -1,  1224,    -1,  1226,    -1,  1170,
      -1,   245,  1213,    -1,   245,  1224,    -1,   245,  1226,    -1,
     340,    -1,   152,    -1,  1213,    -1,   256,    -1,  1212,    -1,
    1224,    -1,  1212,    -1,  1223,    -1,  1212,    -1,   256,    -1,
    1212,    -1,   256,    -1,  1226,    -1,  1209,    -1,  1219,    -1,
     510,    -1,  1209,    -1,  1221,    -1,  1209,    -1,  1219,    -1,
    1212,    -1,  1223,    -1,  1226,    -1,  1211,    -1,  1211,    -1,
    1216,    -1,  1216,  1217,    -1,  1213,    -1,  1216,  1217,  1218,
      -1,  1216,  1217,    -1,  1216,  1218,    -1,  1216,    -1,  1215,
      -1,  1170,    -1,  1216,  1217,  1218,    -1,  1216,  1217,    -1,
    1216,  1218,    -1,  1216,    -1,   504,    -1,   504,  1307,  1216,
      -1,   462,  1163,   448,    -1,   462,  1165,   449,   448,    -1,
     462,  1165,   449,  1165,   448,    -1,   256,    -1,   256,    -1,
     256,    -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,
     212,    -1,   266,    -1,   460,    -1,  1224,    -1,     9,  1225,
      -1,  1225,    -1,  1224,   447,  1225,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,
      -1,  1227,  1230,    -1,  1228,   462,  1197,   448,  1230,    -1,
    1229,   462,  1163,   448,  1230,    -1,   470,   462,  1232,   448,
    1230,    -1,   303,   462,  1233,   448,    -1,   258,   462,  1234,
     448,  1230,    -1,   259,   462,  1234,   448,  1230,    -1,   260,
     462,  1234,   448,  1230,    -1,   201,  1231,    -1,   495,  1231,
      -1,    99,    -1,   502,    -1,   490,    -1,   264,    -1,   377,
      -1,    82,    -1,   428,    -1,   429,    -1,    -1,   462,  1165,
     449,   448,    -1,   462,  1165,   449,  1165,   448,    -1,    -1,
     462,  1163,   448,    -1,   462,   448,    -1,  1197,    -1,  1197,
    1164,   241,    -1,  1197,  1164,   468,    -1,  1197,    -1,  1197,
    1164,  1197,    -1,  1165,    -1,  1165,  1164,  1185,    -1,    -1,
      -1,     9,    -1,    -1,  1316,    -1,    -1,   223,    -1,    -1,
     223,  1240,    -1,    -1,   446,  1202,    -1,    -1,   285,    -1,
     334,    -1,    -1,   290,    -1,    -1,   312,    -1,   290,   312,
      -1,    -1,   386,  1245,    -1,    -1,   272,  1269,  1246,    -1,
      34,    -1,   281,    -1,   282,    -1,   283,    -1,   344,    -1,
     466,    -1,   467,    -1,   471,    -1,    -1,   400,  1257,    -1,
     451,    -1,     3,    -1,     5,    -1,    10,    -1,    18,    -1,
      51,    -1,    52,    -1,    60,    -1,    71,    -1,    74,    -1,
      88,    -1,   111,    -1,   119,    -1,   121,    -1,   128,    -1,
     152,    -1,   163,    -1,   168,    -1,   195,    -1,   202,    -1,
     205,    -1,   206,    -1,   215,    -1,   222,    -1,   224,    -1,
     227,    -1,   269,    -1,   273,    -1,   275,    -1,   285,    -1,
     311,    -1,   324,    -1,   349,    -1,   360,    -1,   375,    -1,
     381,    -1,   385,    -1,   393,    -1,   403,    -1,   412,    -1,
     421,    -1,   426,    -1,   427,    -1,   430,    -1,   432,    -1,
     438,    -1,   469,    -1,   475,    -1,   480,    -1,   507,    -1,
     130,    -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,
     135,    -1,   136,    -1,   137,    -1,   139,    -1,   140,    -1,
     141,    -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,   150,    -1,   151,    -1,
      -1,     7,    -1,    -1,     8,    -1,    -1,    22,    -1,    -1,
      23,    -1,    -1,    26,    -1,    -1,    30,    -1,    -1,    39,
      -1,    -1,    49,    -1,    -1,    56,    -1,    -1,    57,    -1,
      -1,    86,    -1,    -1,   102,    -1,    -1,   454,    -1,    -1,
     188,    -1,    -1,   196,    -1,    -1,   218,    -1,    -1,   314,
      -1,   218,   314,    -1,    -1,   221,    -1,    -1,   456,    -1,
      -1,   228,    -1,    -1,   232,    -1,    -1,   232,    -1,    22,
      -1,    -1,   237,    -1,    -1,   242,    -1,   384,    -1,    -1,
     252,    -1,   254,    -1,    -1,   248,  1269,    -1,   249,  1251,
      -1,    -1,   254,    -1,    -1,   272,    -1,    -1,   299,    -1,
      -1,   299,    -1,   300,    -1,    -1,   306,    -1,    -1,   309,
      -1,    -1,   423,   232,    -1,   423,    -1,   232,    -1,    -1,
     316,    -1,    -1,   337,    -1,    -1,   340,    -1,    -1,   351,
      -1,    -1,   384,    -1,    -1,   405,    -1,    -1,   406,    -1,
      -1,   405,    -1,   405,   232,    -1,    -1,   410,    -1,    -1,
     418,    -1,    -1,   423,    -1,    -1,   437,    -1,    -1,   441,
      -1,    -1,   445,    -1,    -1,   446,    -1,    -1,   446,    -1,
     497,    -1,    -1,   501,    -1,    -1,   501,   403,   446,    -1,
      -1,   503,    -1,    63,   401,    -1,   401,    -1,    66,    -1,
      64,    -1,    67,    -1,    65,    -1,   452,    -1,   159,    -1,
     165,    -1,   161,    -1,   165,    -1,   461,    -1,   218,    -1,
     306,    -1,   418,    -1,   308,    -1,   252,    -1,   254,    -1,
     351,    -1,   353,    -1,    57,    -1,   505,    -1,   351,  1269,
      -1,   353,  1251,    -1,   356,    -1,   474,    -1,   252,    -1,
     254,    -1,   410,    -1,   244,    -1,   503,   124,    -1,   124,
      -1,   340,    63,   401,    -1,    63,   401,    -1,   401,    -1,
     116,    -1,   106,    -1,    89,   210,    -1,    54,    -1,    89,
     187,    -1,    53,    -1,   321,   210,    -1,   325,    -1,   321,
     187,    -1,   326,    -1,   366,   210,    -1,   383,    -1,   366,
     187,    -1,   382,    -1,    89,  1269,    -1,    90,  1251,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1342,  1342,  1342,  1374,  1375,  1379,  1380,  1384,  1385,
    1389,  1389,  1412,  1419,  1426,  1432,  1433,  1434,  1438,  1439,
    1443,  1467,  1468,  1472,  1506,  1512,  1524,  1498,  1534,  1533,
    1571,  1606,  1607,  1611,  1612,  1615,  1616,  1620,  1629,  1638,
    1639,  1643,  1647,  1656,  1657,  1665,  1666,  1676,  1677,  1681,
    1682,  1683,  1684,  1685,  1692,  1691,  1704,  1705,  1708,  1709,
    1723,  1722,  1732,  1733,  1734,  1735,  1739,  1740,  1744,  1745,
    1746,  1747,  1751,  1758,  1765,  1772,  1783,  1787,  1791,  1795,
    1802,  1803,  1810,  1809,  1820,  1821,  1822,  1829,  1830,  1834,
    1838,  1850,  1854,  1855,  1860,  1863,  1870,  1875,  1886,  1899,
    1900,  1908,  1909,  1913,  1914,  1915,  1916,  1917,  1918,  1919,
    1920,  1921,  1922,  1923,  1924,  1932,  1931,  1950,  1960,  1973,
    1981,  1984,  1985,  1989,  1999,  2015,  2014,  2038,  2044,  2050,
    2056,  2062,  2068,  2078,  2082,  2089,  2093,  2098,  2097,  2108,
    2112,  2119,  2120,  2121,  2122,  2123,  2124,  2131,  2146,  2149,
    2156,  2164,  2168,  2179,  2199,  2207,  2218,  2219,  2225,  2246,
    2247,  2251,  2255,  2276,  2299,  2381,  2384,  2393,  2412,  2428,
    2446,  2464,  2481,  2497,  2498,  2505,  2506,  2514,  2515,  2525,
    2526,  2531,  2530,  2551,  2561,  2562,  2566,  2567,  2568,  2569,
    2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,  2578,  2585,
    2591,  2601,  2614,  2627,  2643,  2644,  2645,  2646,  2649,  2650,
    2656,  2657,  2661,  2665,  2666,  2671,  2674,  2675,  2682,  2690,
    2691,  2692,  2699,  2726,  2737,  2744,  2746,  2747,  2753,  2753,
    2760,  2765,  2770,  2777,  2778,  2779,  2783,  2794,  2795,  2799,
    2804,  2809,  2814,  2825,  2836,  2846,  2854,  2855,  2856,  2862,
    2873,  2880,  2881,  2887,  2895,  2896,  2897,  2903,  2904,  2905,
    2912,  2913,  2917,  2918,  2924,  2952,  2953,  2954,  2955,  2962,
    2961,  2977,  2978,  2982,  2985,  2986,  2992,  2993,  3001,  3002,
    3010,  3011,  3015,  3036,  3035,  3052,  3059,  3063,  3069,  3070,
    3074,  3084,  3099,  3100,  3101,  3102,  3103,  3104,  3105,  3106,
    3107,  3114,  3121,  3121,  3121,  3127,  3147,  3181,  3212,  3213,
    3220,  3221,  3225,  3226,  3233,  3244,  3249,  3260,  3261,  3265,
    3266,  3272,  3283,  3301,  3302,  3306,  3307,  3308,  3312,  3319,
    3326,  3335,  3347,  3399,  3414,  3415,  3419,  3431,  3473,  3475,
    3474,  3490,  3493,  3493,  3511,  3512,  3514,  3518,  3520,  3519,
    3554,  3567,  3575,  3580,  3586,  3595,  3605,  3608,  3620,  3621,
    3622,  3623,  3627,  3631,  3635,  3639,  3643,  3647,  3651,  3655,
    3659,  3663,  3667,  3671,  3675,  3686,  3687,  3691,  3692,  3696,
    3697,  3698,  3702,  3703,  3707,  3733,  3737,  3746,  3750,  3759,
    3760,  3761,  3762,  3763,  3764,  3765,  3766,  3767,  3768,  3769,
    3770,  3771,  3772,  3779,  3803,  3831,  3834,  3843,  3868,  3879,
    3880,  3884,  3888,  3892,  3896,  3900,  3904,  3908,  3912,  3916,
    3920,  3924,  3928,  3932,  3937,  3942,  3946,  3950,  3958,  3962,
    3966,  3974,  3978,  3982,  3986,  3990,  3994,  3998,  4002,  4006,
    4014,  4022,  4026,  4030,  4034,  4038,  4042,  4050,  4051,  4055,
    4056,  4062,  4068,  4080,  4098,  4099,  4108,  4132,  4133,  4136,
    4137,  4144,  4168,  4169,  4186,  4187,  4190,  4191,  4198,  4199,
    4204,  4215,  4226,  4237,  4248,  4277,  4276,  4285,  4286,  4290,
    4291,  4294,  4295,  4308,  4321,  4342,  4351,  4365,  4367,  4366,
    4386,  4388,  4387,  4403,  4405,  4404,  4415,  4416,  4423,  4422,
    4451,  4452,  4453,  4460,  4466,  4470,  4471,  4477,  4484,  4485,
    4486,  4490,  4497,  4498,  4502,  4512,  4563,  4571,  4579,  4595,
    4596,  4599,  4600,  4605,  4606,  4607,  4608,  4609,  4613,  4624,
    4635,  4646,  4657,  4667,  4668,  4673,  4672,  4693,  4694,  4698,
    4699,  4700,  4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,
    4709,  4710,  4711,  4712,  4713,  4714,  4718,  4725,  4729,  4733,
    4734,  4735,  4739,  4743,  4750,  4753,  4758,  4765,  4768,  4773,
    4780,  4787,  4796,  4801,  4806,  4813,  4814,  4815,  4816,  4820,
    4828,  4829,  4830,  4837,  4841,  4848,  4856,  4860,  4868,  4872,
    4873,  4880,  4881,  4884,  4885,  4886,  4890,  4900,  4904,  4911,
    4918,  4919,  4923,  4928,  4938,  4946,  4954,  4962,  4964,  4963,
    4984,  4985,  4989,  4990,  4994,  4996,  4995,  5052,  5070,  5071,
    5075,  5079,  5083,  5087,  5091,  5095,  5099,  5103,  5107,  5111,
    5115,  5119,  5123,  5127,  5131,  5135,  5139,  5144,  5148,  5152,
    5157,  5162,  5167,  5172,  5173,  5174,  5175,  5176,  5177,  5178,
    5179,  5180,  5187,  5192,  5201,  5202,  5206,  5207,  5212,  5215,
    5219,  5227,  5230,  5234,  5242,  5253,  5261,  5263,  5273,  5262,
    5300,  5300,  5333,  5337,  5336,  5350,  5349,  5369,  5370,  5375,
    5382,  5384,  5388,  5398,  5400,  5408,  5416,  5424,  5453,  5484,
    5486,  5496,  5501,  5528,  5530,  5529,  5565,  5566,  5570,  5571,
    5572,  5589,  5590,  5601,  5600,  5650,  5651,  5655,  5703,  5716,
    5719,  5738,  5743,  5737,  5756,  5756,  5786,  5793,  5794,  5795,
    5796,  5797,  5798,  5799,  5800,  5801,  5802,  5803,  5804,  5805,
    5806,  5807,  5808,  5809,  5810,  5811,  5812,  5813,  5814,  5815,
    5816,  5817,  5818,  5819,  5820,  5821,  5822,  5823,  5824,  5825,
    5826,  5827,  5828,  5829,  5830,  5831,  5832,  5833,  5834,  5835,
    5836,  5837,  5838,  5839,  5840,  5841,  5842,  5856,  5868,  5867,
    5876,  5882,  5886,  5890,  5895,  5900,  5905,  5910,  5914,  5918,
    5922,  5926,  5931,  5935,  5939,  5943,  5947,  5951,  5955,  5962,
    5963,  5970,  5971,  5975,  5976,  5980,  5981,  5982,  5983,  5984,
    5988,  5992,  5993,  5996,  5997,  6000,  6001,  6007,  6008,  6012,
    6013,  6017,  6021,  6025,  6029,  6033,  6037,  6041,  6045,  6049,
    6053,  6057,  6061,  6065,  6069,  6073,  6077,  6081,  6085,  6089,
    6093,  6097,  6101,  6105,  6109,  6116,  6120,  6131,  6130,  6139,
    6143,  6147,  6153,  6154,  6161,  6165,  6176,  6175,  6184,  6188,
    6200,  6201,  6209,  6208,  6217,  6218,  6222,  6228,  6228,  6235,
    6234,  6244,  6264,  6268,  6273,  6278,  6299,  6303,  6302,  6319,
    6320,  6325,  6333,  6357,  6359,  6363,  6372,  6385,  6388,  6392,
    6396,  6419,  6420,  6424,  6425,  6430,  6433,  6441,  6445,  6453,
    6457,  6468,  6467,  6475,  6479,  6490,  6489,  6497,  6502,  6510,
    6511,  6512,  6513,  6514,  6522,  6521,  6530,  6537,  6541,  6551,
    6562,  6580,  6579,  6588,  6592,  6596,  6601,  6609,  6613,  6624,
    6623,  6633,  6637,  6641,  6645,  6649,  6653,  6654,  6663,  6665,
    6664,  6672,  6681,  6688,  6692,  6696,  6700,  6710,  6712,  6716,
    6717,  6720,  6722,  6729,  6730,  6734,  6735,  6740,  6744,  6748,
    6752,  6756,  6760,  6764,  6768,  6772,  6776,  6780,  6784,  6788,
    6792,  6796,  6800,  6807,  6811,  6822,  6821,  6830,  6834,  6838,
    6842,  6846,  6853,  6857,  6868,  6867,  6875,  6895,  6894,  6918,
    6926,  6927,  6932,  6943,  6954,  6968,  6972,  6979,  6980,  6985,
    6994,  7003,  7008,  7017,  7018,  7023,  7085,  7086,  7087,  7091,
    7092,  7096,  7100,  7111,  7110,  7122,  7123,  7141,  7155,  7177,
    7199,  7219,  7245,  7244,  7252,  7263,  7262,  7271,  7284,  7283,
    7296,  7305,  7309,  7320,  7333,  7332,  7341,  7345,  7349,  7356,
    7360,  7371,  7370,  7378,  7386,  7387,  7391,  7392,  7393,  7398,
    7401,  7408,  7412,  7420,  7427,  7428,  7429,  7430,  7431,  7432,
    7433,  7438,  7441,  7451,  7450,  7458,  7465,  7478,  7477,  7486,
    7490,  7494,  7498,  7505,  7506,  7507,  7508,  7515,  7514,  7528,
    7538,  7547,  7548,  7552,  7553,  7554,  7555,  7556,  7557,  7561,
    7562,  7566,  7571,  7578,  7579,  7580,  7581,  7582,  7586,  7614,
    7617,  7624,  7628,  7638,  7637,  7650,  7649,  7657,  7661,  7672,
    7671,  7680,  7684,  7691,  7695,  7706,  7705,  7713,  7734,  7758,
    7759,  7760,  7761,  7765,  7766,  7770,  7771,  7772,  7773,  7785,
    7784,  7795,  7801,  7800,  7811,  7819,  7827,  7834,  7838,  7851,
    7858,  7870,  7873,  7878,  7882,  7893,  7900,  7901,  7905,  7906,
    7909,  7910,  7915,  7955,  7954,  7963,  7990,  7991,  7996,  7999,
    8003,  8007,  8011,  8015,  8019,  8026,  8027,  8031,  8032,  8036,
    8040,  8050,  8061,  8060,  8068,  8078,  8089,  8088,  8097,  8104,
    8108,  8119,  8118,  8130,  8139,  8142,  8146,  8153,  8157,  8167,
    8179,  8178,  8187,  8191,  8200,  8201,  8206,  8209,  8217,  8221,
    8228,  8236,  8240,  8251,  8250,  8264,  8265,  8266,  8267,  8268,
    8269,  8273,  8274,  8278,  8279,  8285,  8294,  8301,  8302,  8306,
    8310,  8314,  8318,  8322,  8326,  8330,  8334,  8343,  8347,  8356,
    8365,  8366,  8370,  8379,  8380,  8384,  8388,  8399,  8398,  8407,
    8406,  8437,  8440,  8460,  8461,  8464,  8465,  8473,  8474,  8479,
    8484,  8494,  8510,  8515,  8525,  8542,  8541,  8551,  8564,  8567,
    8575,  8578,  8583,  8588,  8596,  8597,  8598,  8599,  8600,  8601,
    8605,  8613,  8614,  8618,  8622,  8633,  8632,  8642,  8655,  8658,
    8662,  8666,  8674,  8686,  8689,  8696,  8697,  8698,  8699,  8706,
    8705,  8714,  8721,  8722,  8726,  8727,  8728,  8732,  8733,  8737,
    8741,  8752,  8751,  8760,  8764,  8768,  8775,  8779,  8789,  8800,
    8801,  8808,  8807,  8815,  8822,  8835,  8834,  8842,  8856,  8855,
    8863,  8876,  8878,  8879,  8887,  8886,  8895,  8903,  8904,  8909,
    8910,  8915,  8922,  8923,  8928,  8935,  8936,  8940,  8941,  8945,
    8946,  8950,  8954,  8965,  8964,  8973,  8974,  8975,  8976,  8980,
    9007,  9010,  9022,  9032,  9037,  9042,  9047,  9055,  9093,  9094,
    9098,  9138,  9148,  9171,  9172,  9173,  9174,  9178,  9209,  9218,
    9219,  9226,  9225,  9237,  9247,  9248,  9253,  9256,  9260,  9264,
    9271,  9272,  9276,  9277,  9281,  9285,  9297,  9300,  9301,  9310,
    9311,  9320,  9323,  9324,  9333,  9334,  9345,  9348,  9349,  9358,
    9359,  9371,  9374,  9376,  9386,  9387,  9399,  9400,  9404,  9405,
    9406,  9410,  9419,  9430,  9431,  9432,  9436,  9445,  9456,  9461,
    9462,  9471,  9472,  9483,  9487,  9497,  9504,  9511,  9511,  9521,
    9522,  9523,  9527,  9536,  9537,  9539,  9540,  9541,  9542,  9543,
    9545,  9546,  9547,  9548,  9549,  9550,  9552,  9553,  9554,  9556,
    9557,  9558,  9559,  9560,  9563,  9564,  9568,  9569,  9573,  9574,
    9578,  9579,  9583,  9587,  9593,  9597,  9603,  9604,  9605,  9609,
    9610,  9611,  9615,  9616,  9617,  9621,  9625,  9629,  9630,  9631,
    9634,  9635,  9645,  9657,  9666,  9682,  9691,  9707,  9722,  9723,
    9728,  9737,  9743,  9763,  9767,  9788,  9829,  9843,  9844,  9849,
    9855,  9856,  9861,  9873,  9874,  9875,  9882,  9893,  9894,  9898,
    9906,  9914,  9918,  9925,  9934,  9935,  9941,  9955,  9972,  9976,
    9983,  9984,  9985,  9992,  9996, 10003, 10004, 10005, 10006, 10007,
   10011, 10015, 10019, 10023, 10027, 10048, 10052, 10059, 10060, 10061,
   10065, 10066, 10067, 10068, 10069, 10073, 10077, 10084, 10085, 10089,
   10090, 10094, 10095, 10099, 10100, 10111, 10112, 10116, 10117, 10118,
   10122, 10123, 10124, 10131, 10132, 10136, 10137, 10141, 10142, 10143,
   10149, 10153, 10157, 10158, 10162, 10166, 10173, 10180, 10187, 10197,
   10201, 10208, 10218, 10228, 10238, 10251, 10255, 10263, 10271, 10275,
   10285, 10300, 10323, 10346, 10362, 10363, 10364, 10365, 10366, 10367,
   10371, 10375, 10392, 10396, 10403, 10404, 10405, 10406, 10407, 10408,
   10409, 10415, 10419, 10423, 10427, 10431, 10435, 10439, 10443, 10447,
   10451, 10458, 10459, 10463, 10464, 10465, 10469, 10470, 10471, 10475,
   10479, 10483, 10490, 10494, 10498, 10505, 10512, 10519, 10529, 10536,
   10546, 10553, 10565, 10573, 10574, 10578, 10579, 10583, 10584, 10589,
   10592, 10600, 10603, 10610, 10612, 10613, 10617, 10618, 10622, 10623,
   10624, 10629, 10632, 10645, 10649, 10657, 10661, 10665, 10669, 10673,
   10677, 10681, 10685, 10692, 10693, 10699, 10700, 10701, 10702, 10703,
   10704, 10705, 10706, 10707, 10708, 10709, 10710, 10711, 10712, 10713,
   10714, 10715, 10716, 10717, 10718, 10719, 10720, 10721, 10722, 10723,
   10724, 10725, 10726, 10727, 10728, 10729, 10730, 10731, 10732, 10733,
   10734, 10735, 10736, 10737, 10738, 10739, 10740, 10741, 10742, 10743,
   10744, 10745, 10746, 10747, 10748, 10749, 10750, 10751, 10752, 10753,
   10754, 10755, 10756, 10757, 10758, 10759, 10760, 10761, 10762, 10763,
   10764, 10765, 10766, 10767, 10768, 10775, 10775, 10776, 10776, 10777,
   10777, 10778, 10778, 10779, 10779, 10780, 10780, 10781, 10781, 10782,
   10782, 10783, 10783, 10784, 10784, 10785, 10785, 10786, 10786, 10787,
   10787, 10788, 10788, 10789, 10789, 10790, 10790, 10791, 10791, 10791,
   10792, 10792, 10793, 10793, 10794, 10794, 10795, 10795, 10796, 10796,
   10796, 10797, 10797, 10798, 10798, 10798, 10799, 10799, 10799, 10800,
   10800, 10800, 10801, 10801, 10802, 10802, 10803, 10803, 10804, 10804,
   10804, 10805, 10805, 10806, 10806, 10807, 10807, 10807, 10807, 10808,
   10808, 10809, 10809, 10810, 10810, 10811, 10811, 10812, 10812, 10813,
   10813, 10814, 10814, 10815, 10815, 10815, 10816, 10816, 10817, 10817,
   10818, 10818, 10819, 10819, 10820, 10820, 10821, 10821, 10822, 10822,
   10823, 10823, 10823, 10824, 10824, 10825, 10825, 10826, 10826, 10830,
   10830, 10831, 10831, 10832, 10832, 10833, 10833, 10834, 10834, 10835,
   10835, 10836, 10836, 10837, 10837, 10838, 10838, 10839, 10839, 10840,
   10840, 10841, 10841, 10842, 10842, 10843, 10843, 10844, 10844, 10845,
   10845, 10848, 10849, 10850, 10854, 10854, 10855, 10855, 10856, 10856,
   10857, 10857, 10858, 10858, 10859, 10859, 10860, 10860, 10861, 10861
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
  "control_final_tag", "identifier_list", "control_identifier",
  "page_limit_clause", "page_line_column", "report_int_ident",
  "page_heading_list", "page_detail", "heading_clause", "first_detail",
  "last_heading", "last_detail", "footing_clause",
  "report_group_description_list", "report_group_description_entry",
  "$@25", "report_group_options", "report_group_option", "type_clause",
  "type_option", "control_heading_final", "control_footing_final",
  "next_group_clause", "next_group_plus", "next_page", "sum_clause_list",
  "reset_clause", "data_or_final", "present_when_condition",
  "varying_clause", "line_clause", "line_keyword_clause",
  "line_clause_options", "PLUS_KEYWORD", "number_is",
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
     741,   741,   741,   742,   742,   742,   742,   743,   744,   744,
     744,   745,   746,   746,   747,   748,   749,   749,   749,   750,
     750,   751,   751,   752,   752,   752,   752,   752,   753,   754,
     755,   756,   757,   758,   758,   760,   759,   761,   761,   762,
     762,   762,   762,   762,   762,   762,   762,   762,   762,   762,
     762,   762,   762,   762,   762,   762,   763,   764,   764,   764,
     764,   764,   764,   764,   765,   765,   765,   766,   766,   766,
     767,   768,   768,   768,   768,   769,   769,   769,   769,   770,
     771,   771,   771,   772,   772,   773,   774,   775,   776,   777,
     777,   778,   778,   779,   779,   779,   780,   781,   781,   782,
     783,   783,   784,   784,   785,   786,   787,   788,   789,   788,
     790,   790,   791,   791,   792,   793,   792,   792,   794,   794,
     795,   795,   795,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   796,   796,   797,   797,   798,   798,
     798,   799,   799,   799,   800,   801,   802,   803,   804,   802,
     805,   802,   806,   807,   806,   808,   806,   809,   809,   810,
     811,   811,   811,   812,   812,   812,   812,   812,   812,   813,
     813,   814,   814,   815,   816,   815,   817,   817,   818,   818,
     818,   818,   818,   820,   819,   821,   821,   822,   823,   824,
     824,   826,   827,   825,   829,   828,   828,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   832,   831,
     833,   833,   833,   833,   833,   833,   833,   833,   833,   833,
     833,   833,   833,   833,   833,   833,   833,   833,   833,   834,
     834,   835,   835,   836,   836,   837,   837,   837,   837,   837,
     838,   839,   839,   840,   840,   841,   841,   842,   842,   843,
     843,   844,   844,   844,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   844,   845,   845,   847,   846,   848,
     848,   848,   849,   849,   850,   850,   852,   851,   853,   853,
     854,   854,   856,   855,   857,   857,   858,   859,   859,   861,
     860,   862,   863,   863,   863,   863,   864,   865,   864,   866,
     866,   867,   867,   868,   868,   868,   868,   869,   869,   869,
     869,   870,   870,   871,   871,   872,   872,   873,   873,   874,
     874,   876,   875,   877,   877,   879,   878,   880,   880,   881,
     881,   881,   881,   881,   883,   882,   884,   885,   885,   886,
     887,   889,   888,   890,   890,   891,   891,   892,   892,   894,
     893,   895,   895,   895,   895,   895,   895,   895,   896,   897,
     896,   898,   899,   899,   899,   899,   899,   900,   900,   901,
     901,   902,   902,   903,   903,   904,   904,   905,   905,   905,
     905,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     905,   905,   905,   906,   906,   908,   907,   909,   909,   909,
     909,   909,   910,   910,   912,   911,   913,   915,   914,   916,
     917,   917,   918,   918,   918,   919,   919,   920,   920,   921,
     922,   923,   923,   924,   924,   925,   925,   925,   925,   926,
     926,   927,   927,   929,   928,   930,   930,   930,   930,   930,
     930,   930,   932,   931,   933,   935,   934,   936,   938,   937,
     939,   940,   940,   941,   943,   942,   944,   944,   944,   945,
     945,   947,   946,   948,   949,   949,   950,   950,   950,   951,
     951,   952,   952,   953,   954,   954,   954,   954,   954,   954,
     954,   955,   955,   957,   956,   958,   958,   960,   959,   961,
     962,   962,   962,   963,   963,   963,   963,   965,   964,   966,
     967,   968,   968,   969,   969,   969,   969,   969,   969,   970,
     970,   971,   971,   972,   972,   972,   972,   972,   973,   974,
     974,   975,   975,   977,   976,   979,   978,   980,   980,   982,
     981,   983,   983,   984,   984,   986,   985,   987,   987,   988,
     988,   988,   988,   989,   989,   990,   990,   990,   990,   992,
     991,   993,   994,   993,   993,   995,   995,   996,   996,   997,
     997,   998,   998,   998,   998,   998,   999,   999,  1000,  1000,
    1001,  1001,  1002,  1004,  1003,  1005,  1006,  1006,  1007,  1007,
    1007,  1007,  1007,  1007,  1007,  1008,  1008,  1009,  1009,  1010,
    1010,  1011,  1013,  1012,  1014,  1015,  1017,  1016,  1018,  1019,
    1019,  1021,  1020,  1022,  1023,  1023,  1023,  1024,  1024,  1025,
    1027,  1026,  1028,  1028,  1029,  1029,  1030,  1030,  1031,  1031,
    1032,  1033,  1033,  1035,  1034,  1036,  1036,  1036,  1036,  1036,
    1036,  1037,  1037,  1038,  1038,  1039,  1040,  1041,  1041,  1042,
    1042,  1042,  1042,  1042,  1042,  1042,  1042,  1043,  1043,  1044,
    1045,  1045,  1046,  1047,  1047,  1048,  1048,  1050,  1049,  1052,
    1051,  1053,  1053,  1054,  1054,  1055,  1055,  1056,  1056,  1057,
    1057,  1057,  1058,  1058,  1058,  1060,  1059,  1061,  1062,  1062,
    1063,  1063,  1063,  1063,  1064,  1064,  1064,  1064,  1064,  1064,
    1065,  1066,  1066,  1067,  1067,  1069,  1068,  1068,  1070,  1070,
    1070,  1070,  1070,  1071,  1071,  1072,  1072,  1072,  1072,  1074,
    1073,  1075,  1076,  1076,  1077,  1077,  1077,  1078,  1078,  1079,
    1079,  1081,  1080,  1082,  1082,  1082,  1083,  1083,  1084,  1085,
    1085,  1087,  1086,  1088,  1088,  1090,  1089,  1091,  1093,  1092,
    1094,  1095,  1095,  1095,  1097,  1096,  1098,  1099,  1099,  1100,
    1100,  1101,  1102,  1102,  1103,  1104,  1104,  1105,  1105,  1106,
    1106,  1107,  1107,  1109,  1108,  1110,  1110,  1110,  1110,  1111,
    1112,  1112,  1113,  1113,  1113,  1113,  1113,  1114,  1115,  1115,
    1116,  1116,  1116,  1117,  1117,  1117,  1117,  1118,  1119,  1120,
    1120,  1122,  1121,  1123,  1124,  1124,  1125,  1125,  1125,  1125,
    1126,  1126,  1127,  1127,  1128,  1128,  1129,  1130,  1130,  1131,
    1131,  1132,  1133,  1133,  1134,  1134,  1135,  1136,  1136,  1137,
    1137,  1138,  1139,  1139,  1140,  1140,  1141,  1141,  1142,  1142,
    1142,  1143,  1144,  1145,  1145,  1145,  1146,  1147,  1148,  1149,
    1149,  1150,  1150,  1151,  1151,  1152,  1153,  1155,  1154,  1156,
    1156,  1156,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,
    1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,  1157,
    1157,  1157,  1157,  1157,  1157,  1157,  1158,  1158,  1159,  1159,
    1160,  1160,  1161,  1162,  1163,  1163,  1164,  1164,  1164,  1165,
    1165,  1165,  1166,  1166,  1166,  1167,  1167,  1168,  1168,  1168,
    1169,  1169,  1170,  1170,  1170,  1170,  1170,  1170,  1171,  1171,
    1172,  1173,  1174,  1175,  1175,  1176,  1177,  1178,  1178,  1179,
    1180,  1180,  1181,  1182,  1182,  1182,  1183,  1184,  1184,  1185,
    1186,  1187,  1187,  1188,  1189,  1189,  1190,  1191,  1192,  1192,
    1193,  1193,  1193,  1194,  1194,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1196,  1196,  1197,  1197,  1197,
    1198,  1198,  1198,  1198,  1198,  1198,  1198,  1199,  1199,  1200,
    1200,  1201,  1201,  1202,  1202,  1203,  1203,  1204,  1204,  1204,
    1205,  1205,  1205,  1206,  1206,  1207,  1207,  1208,  1208,  1208,
    1209,  1210,  1211,  1211,  1212,  1213,  1213,  1213,  1213,  1214,
    1214,  1215,  1215,  1215,  1215,  1216,  1216,  1217,  1218,  1218,
    1219,  1220,  1221,  1222,  1222,  1222,  1222,  1222,  1222,  1222,
    1223,  1223,  1224,  1224,  1225,  1225,  1225,  1225,  1225,  1225,
    1225,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1226,  1227,  1227,  1228,  1228,  1228,  1229,  1229,  1229,  1230,
    1230,  1230,  1231,  1231,  1231,  1232,  1232,  1232,  1233,  1233,
    1234,  1234,  1235,  1236,  1236,  1237,  1237,  1238,  1238,  1239,
    1239,  1240,  1240,  1241,  1241,  1241,  1242,  1242,  1243,  1243,
    1243,  1244,  1244,  1245,  1245,  1246,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1247,  1247,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1248,  1248,  1249,  1249,  1250,  1250,  1251,
    1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,  1256,
    1256,  1257,  1257,  1258,  1258,  1259,  1259,  1260,  1260,  1261,
    1261,  1262,  1262,  1263,  1263,  1264,  1264,  1265,  1265,  1265,
    1266,  1266,  1267,  1267,  1268,  1268,  1269,  1269,  1270,  1270,
    1270,  1271,  1271,  1272,  1272,  1272,  1273,  1273,  1273,  1274,
    1274,  1274,  1275,  1275,  1276,  1276,  1277,  1277,  1278,  1278,
    1278,  1279,  1279,  1280,  1280,  1281,  1281,  1281,  1281,  1282,
    1282,  1283,  1283,  1284,  1284,  1285,  1285,  1286,  1286,  1287,
    1287,  1288,  1288,  1289,  1289,  1289,  1290,  1290,  1291,  1291,
    1292,  1292,  1293,  1293,  1294,  1294,  1295,  1295,  1296,  1296,
    1297,  1297,  1297,  1298,  1298,  1299,  1299,  1300,  1300,  1301,
    1301,  1302,  1302,  1303,  1303,  1304,  1304,  1305,  1305,  1306,
    1306,  1307,  1307,  1308,  1308,  1309,  1309,  1310,  1310,  1311,
    1311,  1312,  1312,  1313,  1313,  1314,  1314,  1315,  1315,  1316,
    1316,  1317,  1317,  1317,  1318,  1318,  1319,  1319,  1320,  1320,
    1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324,  1325,  1325
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
       1,     1,     1,     2,     1,     4,     1,     2,     4,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     3,     4,
       4,     4,     3,     0,     2,     0,     5,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     1,     1,     0,     1,     1,     0,     1,     1,
       4,     1,     2,     2,     1,     2,     1,     1,     1,     4,
       0,     3,     2,     1,     1,     3,     6,     2,     2,     1,
       2,     1,     1,     0,     2,     1,     1,     2,     3,     2,
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
       1,     3,     2,     2,     1,     1,     3,     3,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     5,     5,     4,     5,     5,     5,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     5,     0,     3,     2,     1,     3,     3,     1,     3,
       1,     3,     0,     0,     1,     0,     1,     0,     1,     0,
       2,     0,     2,     0,     1,     1,     0,     1,     0,     1,
       2,     0,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     2,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       1,     0,     1,     0,     1,     1,     0,     1,     1,     0,
       2,     2,     0,     1,     0,     1,     0,     1,     0,     1,
       1,     0,     1,     0,     1,     0,     2,     1,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     2,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     0,     1,     0,     3,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     2,     1,     1,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     2
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
    1776,    46,     0,     0,     0,  1819,  1776,  1776,  1776,     0,
       0,     0,     0,     0,  1776,     0,     0,  1753,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1777,     0,     0,  1506,   125,  1776,
    1776,  1820,  1776,     0,     0,     0,     0,  1776,  1776,    60,
      82,     0,    54,    98,  1754,     0,  1776,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1813,    39,  1776,     0,     0,     0,  1575,   169,  1499,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1507,
     150,   151,  1778,   154,  1580,  1202,  1201,   116,   120,  1805,
    1776,     0,   100,   149,   176,   177,    38,  1814,    36,     0,
    1587,  1583,  1588,  1586,  1584,  1589,  1585,   158,   159,   161,
     170,   165,  1861,  1862,     0,   163,     0,  1752,     0,     0,
       0,  1776,  1883,    80,    61,  1751,    66,    68,    69,    70,
      71,  1751,     0,  1776,     0,    83,     0,    87,    55,    58,
     152,  1780,  1779,   155,     0,  1805,  1808,  1807,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1848,   164,     0,  1576,   168,  1882,  1776,
       0,     0,    65,    67,    63,    81,  1751,  1776,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1581,
     153,   156,     0,  1806,   123,   118,   119,   122,   178,     0,
       0,  1649,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1881,    74,    64,     0,
    1500,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1650,   181,  1759,   266,   267,   268,  1741,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1760,  1832,  1742,  1761,
       0,   278,   259,   138,   139,  1869,  1870,    72,  1815,  1833,
    1755,  1762,     0,     0,     0,   280,     0,  1794,  1815,  1840,
       0,   239,     0,  1776,  1751,  1781,   241,     0,  1850,  1847,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1747,  1776,  1756,     0,  1485,   264,  1483,   277,     0,    25,
     140,  1795,  1776,  1816,  1781,  1841,  1842,   210,  1849,   242,
    1815,  1776,  1776,  1782,  1776,  1776,   251,  1741,   252,     0,
    1776,  1794,  1748,     0,     0,   270,   271,   274,  1484,   279,
     286,   287,   338,   281,   341,     0,     0,  1776,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1809,  1809,
       0,   253,     0,  1776,   240,   223,   272,     0,   273,     0,
     487,   282,  1632,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1505,  1504,   243,   244,   245,   246,   249,  1810,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1635,   216,   201,   217,   202,  1759,
     203,   200,   213,   199,   214,  1776,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1776,  1880,     0,   222,  1636,   209,
       0,   247,  1497,     0,   231,   230,   341,   488,     0,     0,
     607,   345,   350,   387,   356,  1755,  1776,     0,     0,  1776,
    1755,  1794,  1776,  1739,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1879,   248,
    1498,     0,   236,   340,   341,   491,     0,     0,    26,  1776,
    1743,     0,     0,     0,  1776,  1739,     0,     0,     0,     0,
       0,  1776,   334,  1740,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   670,     0,   474,   411,  1821,
    1821,  1821,  1821,  1821,  1843,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1817,   446,     0,   422,   408,   423,   424,     0,
       0,  1824,   426,   427,   425,  1783,   429,   430,   428,  1776,
    1778,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1744,     0,   384,     0,   357,   312,   332,  1871,  1872,
    1503,   321,  1501,  1864,  1863,   314,  1792,  1753,  1765,     0,
    1776,   318,   317,  1776,   337,     0,  1867,  1868,   234,   492,
     496,   608,     0,    27,   714,   485,   486,  1822,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1844,     0,
    1818,   471,   457,   403,  1568,   483,  1825,  1784,  1785,   472,
       0,     0,   405,   407,  1663,  1663,   386,     0,  1801,  1598,
       0,     0,  1594,  1599,  1597,  1595,  1600,  1596,   385,   358,
    1590,  1592,     0,   302,  1502,  1793,   323,     0,   305,  1766,
    1826,   331,     0,     0,   235,   495,   610,   672,     0,     0,
     473,     0,  1836,     0,  1566,  1567,     0,   410,   475,   477,
     479,     0,   404,  1751,   451,   452,  1591,  1802,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1753,
    1827,   310,   319,   316,   320,   315,     0,   497,     0,   614,
     609,   611,     0,   675,   673,   691,     0,   768,   837,   846,
     852,   859,   891,   895,   909,   904,   910,   911,   919,   965,
     974,   977,  1003,  1012,  1015,  1018,  1023,  1024,  1031,  1053,
    1057,  1093,  1095,  1099,     0,  1105,  1119,  1143,  1161,  1162,
    1165,  1166,  1171,  1179,  1180,  1193,  1227,  1245,     0,  1279,
    1291,  1299,  1301,   696,  1305,  1308,  1314,  1361,   716,   717,
     718,   719,   720,   721,   722,   723,   725,   724,   726,   727,
     728,   729,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   715,   458,
    1837,   459,  1616,  1611,  1622,     0,  1472,  1474,     0,     0,
       0,  1614,     0,  1476,  1615,  1617,  1618,     0,     0,     0,
       0,  1613,  1622,  1612,  1456,  1454,  1461,  1464,  1466,  1469,
    1533,  1471,  1530,  1564,  1531,  1532,  1619,     0,     0,     0,
    1565,   484,   481,   478,     0,   406,  1664,   361,   374,  1593,
       0,     0,   324,   325,   326,   327,     0,   306,  1764,   312,
       0,  1486,   498,     0,   615,     0,   612,   680,   680,     0,
       0,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,  1733,  1734,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,
    1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1665,  1711,  1712,  1713,
    1714,   767,     0,     0,     0,     0,   862,     0,     0,     0,
       0,     0,     0,     0,  1417,  1005,     0,     0,  1838,  1417,
       0,     0,     0,     0,     0,     0,   766,     0,  1131,     0,
       0,     0,     0,     0,     0,     0,     0,  1275,  1278,  1265,
    1276,  1277,  1267,     0,     0,  1300,  1298,     0,   714,     0,
       0,     0,     0,  1803,   462,     0,  1609,  1534,  1535,  1536,
       0,     0,     0,     0,     0,     0,     0,  1468,     0,  1467,
       0,  1610,  1457,  1458,  1577,     0,     0,     0,     0,     0,
       0,     0,     0,  1601,     0,     0,     0,     0,   476,     0,
     480,   330,   329,  1745,  1753,   311,     0,   617,   618,   613,
    1750,   680,   677,   683,     0,   680,   692,   667,   790,   835,
     793,   789,  1801,     0,     0,  1524,   844,  1518,   842,  1513,
    1515,  1516,  1517,   847,     0,  1637,  1496,   853,   854,     0,
    1492,  1494,  1493,   865,   863,   864,   889,     0,  1546,   892,
     893,  1545,   896,   899,  1801,   907,  1570,     0,  1478,  1651,
    1510,  1569,  1574,  1511,     0,   917,  1815,  1594,   963,  1382,
     928,   932,  1513,     0,  1515,   972,     0,   866,   975,   984,
     983,  1001,     0,   980,   982,  1416,     0,  1007,  1011,  1009,
    1006,  1010,  1004,  1013,  1014,  1508,  1016,  1017,  1839,  1019,
    1490,  1834,  1415,  1032,  1034,  1054,  1055,  1058,     0,  1060,
    1061,  1062,  1094,  1231,  1561,  1562,     0,  1096,     0,  1103,
       0,  1112,  1109,  1111,  1110,  1106,  1113,  1133,  1496,  1120,
    1131,  1122,     0,  1129,     0,  1547,  1493,  1549,     0,  1159,
    1643,  1163,  1364,  1481,  1169,  1815,  1177,  1364,     0,  1191,
    1184,  1482,     0,  1489,  1194,  1195,  1196,  1197,  1198,  1199,
    1220,  1200,  1223,     0,  1487,     0,     0,  1560,  1574,  1228,
    1263,  1250,  1268,  1749,  1289,     0,  1282,  1284,     0,  1296,
       0,  1302,  1303,   702,   708,   697,   698,   699,   701,     0,
    1306,     0,  1309,  1311,  1331,  1317,  1374,  1364,  1804,     0,
     466,   461,  1624,  1456,  1454,  1473,  1475,  1456,     0,     0,
       0,  1456,  1527,  1528,  1529,     0,  1477,  1470,  1456,     0,
    1455,  1578,     0,  1460,  1459,  1463,  1462,  1465,     0,     0,
    1456,     0,  1776,  1746,     0,   308,     0,  1776,  1823,   678,
    1776,     0,   689,   681,   682,   693,   836,   769,  1746,   803,
     794,     0,     0,     0,     0,  1519,  1520,  1521,   845,   838,
       0,     0,  1514,  1639,  1638,   850,   855,   857,     0,   890,
     860,  1548,   866,   894,   899,  1873,  1874,   897,     0,   900,
       0,   908,   905,  1856,  1855,  1479,     0,  1653,  1480,  1572,
    1573,   914,   915,   918,   912,  1409,   964,   920,   711,     0,
     926,  1384,     0,   943,     0,   937,  1382,  1382,  1382,  1382,
     973,   966,     0,     0,   867,   976,  1002,   978,  1417,  1417,
     979,   986,   987,   711,  1441,  1442,  1443,  1437,  1838,  1429,
    1449,  1452,  1451,  1453,  1445,  1436,  1435,  1440,  1439,  1438,
    1444,  1424,  1428,  1446,  1448,  1450,  1426,  1427,  1423,  1425,
    1418,  1419,  1430,  1431,  1432,  1433,  1434,  1422,  1008,  1509,
    1021,  1835,   711,  1036,     0,  1056,     0,  1083,  1067,  1059,
    1064,  1065,  1066,  1235,     0,  1563,     0,     0,  1104,  1100,
       0,  1113,  1847,     0,  1121,  1127,  1128,   711,  1124,  1417,
       0,     0,  1132,     0,  1160,  1144,  1644,  1645,  1815,     0,
    1164,  1170,  1167,  1146,  1178,  1172,  1174,  1186,  1192,  1181,
       0,  1186,     0,  1541,  1542,  1221,  1224,     0,     0,  1488,
    1204,     0,  1203,     0,     0,  1572,  1264,  1246,  1252,  1776,
    1253,  1248,     0,     0,  1266,     0,     0,  1290,  1280,     0,
    1283,     0,  1297,  1292,     0,  1304,   709,   707,   700,     0,
    1312,  1313,  1310,  1332,  1315,  1749,     0,  1375,  1362,  1366,
     460,  1749,   456,   464,   465,  1781,  1623,     0,  1619,  1619,
    1619,     0,  1605,     0,  1619,  1579,     0,  1619,  1619,  1846,
       0,   328,  1803,   307,   502,  1776,  1776,  1739,  1789,   533,
     501,   505,   506,     0,     0,   632,  1776,   622,  1843,   623,
    1852,  1851,     0,  1776,     0,   635,   626,   631,  1796,   627,
       0,   630,   637,   634,   628,   633,     0,   638,   629,     0,
     649,   643,   647,   646,   644,   648,   619,   650,   645,     0,
    1796,     0,  1776,   690,     0,     0,   668,   799,   804,   805,
    1796,  1796,   797,   798,  1796,   785,  1377,  1854,  1853,   782,
     774,   776,   777,     0,  1377,     0,     0,     0,   791,   780,
       0,   788,   771,   787,   772,  1538,  1537,     0,  1523,     0,
    1801,  1570,  1387,   843,  1574,  1511,     0,  1641,   850,     0,
     848,     0,     0,  1495,   877,   898,   903,     0,     0,  1512,
    1387,  1776,  1652,  1571,   916,   711,   913,  1411,  1383,   712,
     930,  1745,   711,  1381,   936,   935,   934,   933,   944,  1382,
    1776,   947,     0,   950,   951,     0,  1776,   954,   955,   956,
     957,     0,   958,  1382,   945,     0,   805,   923,   924,   921,
     922,     0,  1387,     0,   873,   981,   996,   998,   997,   991,
     993,   999,  1417,   988,   985,  1417,   989,  1447,  1420,  1421,
    1803,  1020,  1491,   711,  1028,  1029,  1838,  1044,  1045,  1047,
    1049,  1050,  1046,  1048,  1039,  1838,  1035,     0,  1084,     0,
    1086,  1085,  1087,  1069,  1079,     0,     0,  1063,  1237,     0,
    1767,     0,  1097,  1387,     0,     0,     0,  1115,  1125,  1138,
    1134,  1139,  1135,  1140,     0,  1130,  1371,  1370,  1137,  1146,
    1365,  1557,  1558,  1559,     0,     0,  1409,     0,   711,     0,
    1185,     0,     0,     0,  1222,     0,  1226,  1225,  1218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1206,  1207,
    1646,  1409,     0,  1270,  1269,  1830,  1830,  1285,  1286,  1287,
       0,  1387,     0,     0,   710,     0,  1633,     0,  1287,  1174,
    1735,     0,  1776,  1631,  1606,  1607,  1608,  1629,  1626,  1627,
    1604,  1620,     0,  1602,  1603,   482,     0,     0,  1898,  1899,
    1776,  1739,     0,   499,   503,   511,   507,   509,   510,   512,
     514,     0,   620,   621,   624,   625,     0,   652,  1797,  1776,
    1836,  1776,   653,   651,   665,  1776,   684,   685,   688,     0,
     679,   694,   696,  1776,   807,     0,     0,   795,   796,     0,
     711,   786,  1379,   773,   775,  1377,   783,   778,   779,   792,
     781,  1540,  1522,  1539,  1651,     0,   711,   839,  1389,  1572,
    1573,  1387,     0,  1640,   849,   851,   858,   856,   882,   881,
     885,  1774,   902,   901,   906,     0,  1410,   711,  1408,   714,
    1385,   925,     0,   948,   949,   952,   953,     0,  1413,  1413,
     946,   927,   939,   940,   938,   941,     0,   967,     0,   868,
     869,   683,     0,  1417,  1417,   995,   711,   992,     0,  1027,
     711,  1030,  1025,     0,     0,  1051,     0,     0,     0,  1080,
    1082,     0,  1075,  1089,  1076,  1077,  1068,  1071,  1089,  1229,
    1776,  1781,     0,  1768,  1236,  1098,  1101,     0,  1115,  1114,
    1118,  1107,     0,  1126,  1123,     0,     0,  1148,  1147,   711,
    1168,  1397,  1173,  1175,     0,  1187,  1417,  1417,  1182,  1188,
    1205,  1217,  1219,  1209,  1210,  1211,  1215,  1212,  1216,  1213,
    1214,  1208,  1647,  1262,     0,  1259,  1260,  1254,     0,  1247,
    1878,  1877,     0,  1831,  1273,  1273,  1392,     0,  1651,  1293,
       0,   703,     0,  1634,  1318,  1319,     0,  1322,  1325,  1329,
    1323,  1409,  1736,     0,   470,   467,   468,     0,  1621,   309,
     504,  1790,  1791,  1582,   521,   516,   520,   519,   352,   534,
     508,   513,  1552,   642,  1550,  1551,   641,   658,   664,     0,
     661,   686,   687,   696,   714,     0,     0,  1377,   800,   802,
     801,  1378,   711,  1376,   784,  1387,  1512,  1388,   711,  1386,
    1571,   840,  1642,  1543,  1544,  1859,  1860,   887,   711,  1801,
    1775,   884,   883,   879,     0,  1655,  1656,  1657,  1658,  1659,
    1660,  1661,  1662,  1654,  1412,     0,   960,   959,   962,     0,
    1555,  1556,   961,     0,   931,  1387,  1478,  1387,  1478,   870,
     871,     0,   875,   874,   876,   994,  1000,   990,  1022,  1026,
    1037,  1040,  1041,  1757,  1033,  1838,  1038,  1089,  1089,     0,
    1074,  1072,  1073,  1078,  1239,     0,  1233,  1769,  1387,  1108,
    1117,     0,  1141,     0,     0,  1155,     0,  1401,   711,  1396,
    1176,   711,   711,  1189,  1261,  1251,  1255,  1256,  1257,  1258,
    1249,  1271,  1274,  1272,   711,  1281,  1394,  1776,  1387,  1387,
     705,  1307,  1633,  1321,  1765,  1327,  1765,  1392,   711,   711,
    1363,  1373,  1404,  1405,  1372,  1369,  1368,  1786,   469,   463,
     515,  1865,  1866,   517,   354,   535,   656,   654,   657,   655,
     659,   660,     0,   636,   662,   663,     0,   714,   806,   811,
    1776,   812,   813,   814,  1776,   815,   816,   817,   818,   819,
     820,   821,   823,   824,   825,     0,   826,  1737,   827,   828,
     829,   808,   809,   770,  1380,   841,  1390,   711,   861,   886,
       0,   878,  1875,  1876,  1414,   942,   969,     0,   968,     0,
     872,  1042,  1758,     0,     0,  1070,  1081,  1089,  1772,  1772,
    1090,     0,     0,  1242,  1238,  1232,  1102,  1116,     0,  1149,
    1776,  1409,     0,     0,  1150,     0,  1154,  1402,  1183,  1190,
    1393,   711,  1391,     0,  1295,  1294,  1333,   704,     0,  1320,
       0,  1765,  1324,     0,  1316,  1406,  1407,  1403,  1787,  1788,
    1367,     0,  1776,  1776,     0,   522,   523,   524,   525,   526,
     527,     0,   537,   639,   640,     0,     0,     0,  1776,  1413,
    1413,  1738,     0,   810,   888,   880,  1387,  1387,     0,  1052,
    1088,  1773,     0,     0,  1776,  1240,     0,     0,  1230,  1234,
       0,     0,  1145,  1158,  1399,  1400,  1157,  1153,  1151,  1152,
    1395,  1288,  1340,   706,  1326,     0,  1330,  1885,  1884,  1776,
       0,     0,  1887,     0,  1776,  1776,   518,  1823,     0,   831,
     830,     0,   833,   832,   834,  1553,  1554,   971,   970,  1043,
    1092,  1091,     0,  1243,  1776,  1417,  1156,  1398,  1360,  1359,
    1341,  1334,  1335,  1737,  1336,  1337,  1338,  1358,     0,  1328,
       0,   532,   528,  1886,     0,     0,  1770,   593,     0,     0,
       0,     0,  1776,  1801,   536,  1776,  1776,     0,   543,   545,
     554,   546,   548,   551,   538,   539,   540,   550,   552,   555,
     541,     0,   542,   547,     0,   549,   553,   544,  1798,  1739,
     695,   822,  1241,     0,  1142,     0,  1828,  1803,   529,   531,
     530,  1771,   605,   595,   588,  1776,   597,   457,     0,  1417,
       0,     0,     0,     0,     0,   591,   592,   587,     0,   589,
     596,     0,   599,   603,  1799,  1800,  1778,   601,  1244,     0,
    1829,     0,     0,   594,     0,  1836,   598,   585,  1651,   580,
    1525,  1889,     0,     0,  1891,  1893,     0,  1897,  1895,   556,
     561,   564,   567,   558,   562,   557,   563,   606,     0,   590,
     602,   600,  1357,  1858,  1857,  1811,  1353,  1347,  1348,  1350,
     578,   576,   577,     0,     0,   570,   574,   571,   459,   604,
    1803,     0,   579,  1526,  1888,  1892,  1890,  1896,  1894,   566,
     559,   565,   569,   560,   568,     0,  1812,  1803,  1356,  1351,
    1354,     0,  1349,   575,   572,   573,   454,     0,   582,     0,
       0,  1355,  1352,     0,   453,   584,   581,   583,   586,  1346,
    1343,  1345,  1344,  1339,  1342,   455
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
     434,   503,   435,   534,   566,   567,   827,   568,  1663,  1009,
     763,   569,   570,   703,   833,   571,   572,   828,  1002,  1003,
    1004,  1005,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   758,   814,
     815,   816,   817,   818,   500,   683,   589,   661,   662,   663,
     792,   664,   665,   666,   667,   668,   669,   670,  2550,  2694,
     671,   782,  1144,  1380,  1381,  1645,  1642,  2155,  2156,   672,
     673,   674,   675,   676,   992,   788,   789,  1178,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1186,  1417,
    1670,  1671,  1956,  1957,  1958,  1959,  1672,  2164,  2165,  2320,
    2435,  2436,  2437,  2438,  2439,  2440,  1953,  2169,  2442,  2497,
    2554,  2555,  2629,  2670,  2673,  2556,  2655,  2656,  2557,  2662,
    2696,  2558,  2559,  2560,  2561,  2597,  2598,  2584,  2599,  2562,
    2563,  2564,  2602,  2565,  2566,  2567,   588,   776,   840,   841,
     842,  1188,  1418,  1706,  2330,  2331,  2332,  2336,  1707,  1708,
     713,  1425,  1982,   714,   845,  1018,  1017,  1191,  1192,  1193,
    1422,  1714,  1020,  1716,  2183,  1138,  1365,  1366,  2300,  2417,
    1367,  1368,  1923,  1778,  1779,  2029,  1369,   779,   898,   899,
    1092,  1199,  1200,  1742,  1429,  1485,  1722,  1723,  1719,  1984,
    2187,  2361,  2362,  1427,   900,  1093,  1206,  1441,  1439,   901,
    1094,  1213,  1760,   902,  1095,  1217,  1218,  1762,   903,  1096,
    1226,  1227,  1495,  1814,  2049,  2050,  2051,  2020,  2021,  2213,
    2207,  2368,  1450,   904,  1097,  1229,   905,  1098,  1232,  1457,
     906,  1099,  1235,  1462,   907,   908,   909,  1100,  1245,  1471,
    1474,   910,  1101,  1248,  1249,  1479,  1250,  1483,  1806,  2044,
    2234,  1789,  1803,  1804,  1477,   911,  1102,  1255,  1491,   912,
    1103,  1258,   913,  1104,  1261,  1262,  1263,  1500,  1501,  1502,
    1824,  1503,  1819,  1820,  2055,  1497,   914,  1105,  1272,   915,
    1106,  1273,   916,  1107,  1276,   917,  1108,  1279,  1831,   918,
     919,  1109,  1835,  2062,   920,  1110,  1283,  1543,  1844,  2065,
    2251,  2252,  2253,  2254,   921,  1111,  1285,   922,  1112,  1287,
    1288,  1549,  1550,  1856,  1551,  1552,  2076,  2077,  1853,  1854,
    1855,  2070,  2260,  2390,   923,  1113,   924,  1114,  1297,   925,
    1115,  1299,  1559,   926,  1117,  1305,  1306,  1563,  2091,   927,
    1118,  1309,  1567,  2094,  1568,  1310,  1311,  1312,  1870,  1872,
    1873,   928,  1119,  1319,  1885,  2275,  2401,  2472,  1575,   929,
     930,  1120,  1321,   931,   932,  1121,  1324,  1582,   933,  1122,
    1326,  1886,  1585,   934,   935,  1123,  1329,  1591,  1889,  2108,
    2109,  1589,   936,  1124,  1334,   159,  1603,  1335,  1336,  1908,
    1909,  1337,  1338,  1339,  1340,  1341,  1342,   937,  1125,  1292,
    2264,  1553,  2395,  1858,  2079,  2393,  2468,   938,  1126,  1350,
    1911,  1611,  2124,  2125,  2126,  1607,   939,  1352,  1614,  2291,
    1132,   940,  1133,  1354,  1355,  1356,  2136,  1618,   941,  1134,
    1359,  1623,   942,  1136,   943,  1137,  1361,   944,  1139,  1370,
     945,  1140,  1372,  1632,   946,  1141,  1374,  1636,  2144,  2145,
    1928,  2147,  2305,  2422,  2307,  1634,  2418,  2482,  2521,  2522,
    2523,  2703,  2524,  2647,  2648,  2681,  2525,  2526,  2527,   947,
    1142,  1376,  1580,  1929,  1878,  2310,  1638,  1991,  1992,  2193,
    1480,  1481,  1783,  2007,  2008,  2199,  2295,  2296,  2412,  2100,
    2473,  2101,  2279,  2311,  2312,  2313,  1776,  1777,  2028,  2228,
    1281,  1282,  1265,  1266,  1530,  1531,  1532,  1533,  1534,  1535,
    1536,   974,  1165,  1384,   976,   977,   978,   979,  1236,  1237,
    1465,  1322,  1330,   395,   396,  1012,  1343,  1344,  1540,  1313,
    1220,  1221,   541,   481,   301,   691,   692,   482,    98,   153,
    1274,  1239,  1208,  1442,  2619,  1391,   981,  1747,  2002,  2078,
    2202,  1230,  1314,  2173,  2504,  2229,  1880,  2174,  1293,  1347,
    1210,   983,  1240,  1241,   734,   784,   785,  2175,   271,  2167,
     179,  1211,   760,   761,  1212,   986,   987,   988,  1173,  1146,
    1399,  1395,  1388,   501,  2146,   537,  1445,  1758,  2013,  1578,
    2128,   282,  1468,  1772,  2223,   794,  1091,  2153,  2452,   604,
     339,   684,  1431,   423,  1194,   202,   115,   393,  2383,   337,
     352,  1010,   770,  2084,  2582,  2462,  2214,    96,   214,   414,
     739,  2430,  1952,   766,   402,  1969,  2606,   798,  1379,   218,
     488,  2677,   168,   390,   731,   102,   719,   680,   831,  2611,
    2134,   350,  1542,   951,  1280,   407,   729,  1179,  1318,   391,
    1724,  1744,  1466,  2645,  2208,   184,   695,  2323,   708,   347,
     596,  1459,  2374,  2132,   538,   203,  2489,  2495,  2632,  2633,
    2634,  2635,  2636,  1674
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2370
static const yytype_int16 yypact[] =
{
   -2370,   254,   532, -2370,  -191,   137, -2370,   532, -2370, -2370,
     131, -2370, -2370,   131,   131,   -43,   -43, -2370,   545, -2370,
     679,   515,   786, -2370, -2370,   943,   943,   542,   583, -2370,
   -2370,    12,   131,   -43, -2370, -2370,   789,   585, -2370, -2370,
     685,  2130,   -43, -2370, -2370, -2370,   515,   771, -2370, -2370,
       5, -2370,   899,   899,   869,   921,  1189,  1189,  1189,  1034,
     899,  1078,  1071,  1114,  1189,  1129,  1136,  1461, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370,  1027, -2370, -2370, -2370, -2370,
    1344, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    1423,  1153,    12, -2370, -2370,  1162,   145, -2370, -2370,  1189,
    1189, -2370,  1189,  1121,  1561,  1121,  1180,  1189,  1189, -2370,
   -2370,  1121, -2370, -2370, -2370,  1130,    -9,  1191, -2370, -2370,
    1134, -2370,  1199, -2370, -2370, -2370, -2370,   496, -2370, -2370,
   -2370,  1300, -2370,  1189,  1223,  1121,  1395,   756, -2370, -2370,
   -2370, -2370, -2370,  1396,  1186,  1110,  1456, -2370,  1156, -2370,
    1130, -2370,    56, -2370, -2370, -2370, -2370, -2370,  1188,   507,
    1189,   -14, -2370, -2370, -2370,   477, -2370, -2370, -2370,  1154,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1223, -2370,  1221,
   -2370,  -173, -2370, -2370,  1121, -2370,  1258, -2370,  1265,  1259,
    1610,  1189, -2370, -2370, -2370,   799, -2370, -2370, -2370, -2370,
   -2370,   809,  1615,  1189,    66, -2370,    78, -2370, -2370,   107,
   -2370, -2370, -2370, -2370,  1422,   507, -2370,  1449,   899,   899,
   -2370,  1188,  1233,    70,   707, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,   815, -2370,
     149, -2370,  1223, -2370, -2370,  1358, -2370, -2370, -2370,  1189,
    1287,  1431, -2370, -2370, -2370, -2370,  1112,  1189,  1200,  1469,
     -64, -2370,  1664,   -41,  1250, -2370, -2370,  1254,  1596, -2370,
    1422, -2370,   899, -2370, -2370, -2370, -2370,  1188, -2370,  1255,
    1398, -2370,   899, -2370,  -126, -2370,   106, -2370, -2370, -2370,
   -2370, -2370,   815, -2370,  1451,  1431, -2370, -2370, -2370,   538,
   -2370, -2370, -2370,  1460, -2370, -2370, -2370, -2370, -2370,  1440,
   -2370, -2370, -2370, -2370, -2370,  1263, -2370, -2370, -2370,  1695,
    1617,  1269, -2370, -2370,   815, -2370, -2370,    26, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1285, -2370,  1539,
    1606,  1275, -2370,  1713, -2370, -2370, -2370, -2370,  2236, -2370,
    1645, -2370,  1231,  1288,  1346, -2370,   815,  1464,  1387,  -214,
    1340, -2370,  1341,  1189,  1686,   307,    -3,  1049, -2370,  1241,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1322,
   -2370,  1485, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    1714,  1189, -2370,  1231, -2370,  1231, -2370, -2370,  1304,   440,
   -2370, -2370,  1189, -2370,  1519, -2370, -2370,   831, -2370, -2370,
    1025,  1189,  1189, -2370,  1189,  1189, -2370,  1695, -2370,   113,
    1189,  1464, -2370,  1361,  1260,  1231, -2370,  1434, -2370, -2370,
   -2370, -2370,  1271, -2370,  1262,    60,    20,  1189, -2370, -2370,
     830, -2370, -2370,  -142,  1359,  1121,  1121, -2370,  1466,  1466,
    1478, -2370,  1121,  1189, -2370, -2370, -2370,  1431, -2370,  1400,
    1537, -2370, -2370,  1349, -2370, -2370, -2370, -2370, -2370,  1121,
   -2370, -2370,   -35,   -35,  1795,   -35, -2370, -2370,   -35,   143,
   -2370, -2370, -2370, -2370, -2370,  -172, -2370, -2370, -2370, -2370,
   -2370, -2370,   625, -2370,  1352,  1410,  1554,   262,  1362,  6147,
   -2370,  1306, -2370, -2370,   -23, -2370, -2370, -2370, -2370,  1263,
   -2370, -2370, -2370, -2370, -2370,  1189,  1121,  1309, -2370,  1309,
   -2370, -2370,  1363,  1426,  1450, -2370,  1366, -2370,  1370, -2370,
    1737, -2370,  1738, -2370,  1216, -2370,  1700, -2370, -2370, -2370,
    1121,  1121, -2370,   772, -2370, -2370,  1262, -2370,  1374,  1432,
    1441, -2370, -2370, -2370,    40,  1645,  1189,  1194,  1194,  1189,
      -1,  1464,  1189,  1805, -2370,  1527, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370,   899,  1100, -2370,  1121,
   -2370,  1522, -2370, -2370,  1262, -2370,  1384,  1442, -2370,  6455,
     623,  1634,  1431,  1335,  1189,  1805,  1345,  -113,  -142,  1431,
    1347,  1189, -2370, -2370, -2370,   -38,   899, -2370, -2370, -2370,
     -39, -2370,  1262, -2370,  1389,   737,    -5, -2370, -2370,  -182,
     608,   618,   770,   780,  1343, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,  1467, -2370,  1431, -2370, -2370, -2370, -2370,  1121,
    1121,  1613, -2370, -2370, -2370,   535, -2370, -2370, -2370,  1189,
     722, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1103,
     -80, -2370,  1350, -2370,   375, -2370,  1404, -2370, -2370, -2370,
   -2370,  1345, -2370, -2370, -2370, -2370,  1601,    51,  1638,  1353,
    1189, -2370, -2370,  1189, -2370,  1197, -2370, -2370, -2370, -2370,
   -2370, -2370,  1739, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1356,
   -2370, -2370,  1413, -2370,  1402,  1418, -2370, -2370, -2370, -2370,
    6622,   474,  1839, -2370,  1468,  1468, -2370,  1286,  1563, -2370,
    2024,  2024, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    1429, -2370,  1431,    52, -2370, -2370, -2370,  1431, -2370, -2370,
    1463, -2370,   404,   404, -2370,  1536,  1381,    31,  3468,  3951,
   -2370,  1431,  1425,  7137,  1416, -2370,  1121, -2370,   474, -2370,
    1446,  1633, -2370,  1686, -2370, -2370, -2370, -2370,  2024,  1439,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370,  1286, -2370, -2370, -2370, -2370,     7,  1461,
   -2370,   934, -2370, -2370, -2370, -2370,  1388, -2370,  5965, -2370,
   -2370,  1381,  1443, -2370, -2370,  1515,  4335, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  1497, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,   491, -2370,
   -2370,  1557, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370,  1783, -2370, -2370,  1437,  1525,   756,   756,  1444,  1445,
    1447, -2370,  1448,   756, -2370, -2370, -2370,  7288,  7137,  7288,
    1452, -2370,  1437, -2370,   247,  1007,   384, -2370,  1732, -2370,
   -2370, -2370, -2370, -2370,  1429, -2370,  1453,  1462,  1470,  7137,
   -2370, -2370,  -220, -2370,   474, -2370, -2370, -2370, -2370, -2370,
    -142,  -142, -2370, -2370, -2370, -2370,  1717, -2370, -2370,  1404,
    1431, -2370, -2370,  1454, -2370,  1471, -2370,    98,    98,  1408,
    1472, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,   427,  1910,  7137,   446,   729,   467,  1231,   593,
     317,  5491,  5596,  1657,   929,   864,   593,  1121,  1479, -2370,
     593,  1388,  1056,  1121,  2730,  5596, -2370,   931,  2748,  1231,
    1121,  1231,  1121,    65,   485,  1121,  1231, -2370, -2370, -2370,
   -2370, -2370, -2370,  4249,  4872, -2370, -2370,  1388,    73,  1121,
    1231,  1121,  1121,  1609, -2370,  6760, -2370, -2370,  1429, -2370,
    1427,  1433,  7137,  7137,  7137,  1525,  1455, -2370,   914, -2370,
    1525, -2370, -2370, -2370, -2370,  7137,  6882,  7137,  7137,  7137,
    7137,  7137,  7137, -2370,  1525,  7137,  1007,  1523, -2370,  1480,
   -2370, -2370, -2370,  1908,  1461, -2370,   202, -2370, -2370, -2370,
   -2370,   129, -2370,  -183,   621,   308, -2370, -2370, -2370,  1812,
     660,  1748,  1563,  1121,  1525, -2370,  1816, -2370,  4932, -2370,
   -2370, -2370, -2370, -2370,   163,   744, -2370,   446, -2370,  1503,
   -2370,   756, -2370, -2370, -2370, -2370,  1818,  1821, -2370,   467,
   -2370, -2370,  1231,   601,  1563,  1822, -2370,    99, -2370,  1565,
   -2370, -2370,  1402,  1429,  1231,  1826,  1387,  1068,  1827,  5000,
   -2370,  5140,   140,  1123,  1132,  1820,   697,  1473, -2370, -2370,
   -2370,  1824,    67, -2370, -2370, -2370,  4834, -2370, -2370,  1862,
   -2370, -2370, -2370, -2370,   593, -2370, -2370, -2370, -2370, -2370,
   -2370,  1528, -2370, -2370,   406,  1388, -2370, -2370,    39, -2370,
   -2370, -2370, -2370, -2370, -2370,  1502,  5596, -2370,  1520,  1828,
    1923, -2370, -2370, -2370, -2370,   931,  1569, -2370,  1529, -2370,
    2830,     8,   807,  1533,  1531, -2370,   944, -2370,  1538,  1837,
     913, -2370,  1785, -2370,  1843,  1387,  1838,  1785,  1121,  1842,
    1490, -2370,   875, -2370, -2370, -2370, -2370, -2370, -2370,  1719,
   -2370,   593, -2370,  -109, -2370,   423,  1960, -2370,   133, -2370,
    1846,   971,   472,  1945,  1848,  1187, -2370, -2370,  1121,  1849,
    5271,  1388, -2370, -2370,   822, -2370, -2370, -2370, -2370,  3762,
   -2370,  1801, -2370,  1208,  1850,  1887,  1851,  1785, -2370,  1121,
    1781,   189, -2370,   253,  -201, -2370, -2370,   316,  1555,  1558,
    1559,   256, -2370,  1429, -2370,  1562, -2370, -2370,   324,  1564,
    -201, -2370,  1054,   384,   384, -2370, -2370, -2370,  1074,  1566,
     327,  1567,  1189, -2370,  -142,  1897,  1568,   709,  6672, -2370,
    1189,  1607,  1704, -2370, -2370,  1909, -2370, -2370,   875,  1829,
   -2370,   716,  1646,   -15,  1577, -2370,  1429, -2370, -2370, -2370,
    5619,  1825, -2370,  1807, -2370,  1648, -2370,  1692,  1776, -2370,
   -2370, -2370,  1473, -2370,   601, -2370, -2370, -2370,  1023,   468,
    1121, -2370, -2370, -2370, -2370, -2370,  7137,  1764, -2370,  1416,
   -2370,  1231, -2370, -2370, -2370,  1808, -2370, -2370, -2370,  5596,
   -2370,  1744,    -2,  1742,  2537,  1560,  1876,  1876,  1876,  1876,
   -2370, -2370,  5596,  5619, -2370, -2370, -2370, -2370,   929,   152,
   -2370,  1541, -2370,  1542, -2370, -2370, -2370, -2370,  1479, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    4567, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
      10, -2370,  1917,  1090,  1871, -2370,   875,   132, -2370, -2370,
    1683, -2370, -2370,    86,  7137, -2370,  1603,   593, -2370, -2370,
    5619,  1569,  1241,  1231, -2370, -2370, -2370, -2370, -2370,  1885,
    1121,   446, -2370,   238, -2370, -2370, -2370, -2370,  1387,  1056,
   -2370, -2370, -2370,  1830, -2370, -2370,   554,  1926, -2370, -2370,
    1121,  1926,  1611, -2370,  1429, -2370, -2370,   454,  1188, -2370,
   -2370,  2632, -2370,  2011,   751,   146, -2370, -2370, -2370,  1189,
   -2370,   400,  5596,  5596, -2370,   653,  5406, -2370, -2370,  1121,
   -2370,  1865, -2370, -2370,  5619, -2370,  1431, -2370, -2370,   875,
   -2370, -2370, -2370, -2370, -2370,  1945,  1835, -2370, -2370,   238,
   -2370,  1945, -2370, -2370, -2370,  1519, -2370,  1121,  1453,  1453,
    1453,  1525, -2370,   -67,  1453, -2370,  7033,  1453,  1453, -2370,
     474, -2370,  1609, -2370, -2370,  1189,  1189,  1805,  1193, -2370,
   -2370, -2370, -2370,  1867,   -17, -2370,  1189, -2370,   551, -2370,
   -2370, -2370,  1383,  1189,  1821, -2370, -2370, -2370,  1770, -2370,
    1431, -2370,  2016, -2370, -2370, -2370,  1121, -2370, -2370,  1121,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1870,
    1770,   792,  1189, -2370,  1571,  1627, -2370, -2370, -2370,  1810,
    1770,  1770,   126,  1831,  1770, -2370,  1919, -2370, -2370, -2370,
    1578,  1580, -2370,   875,  1919,  1853,  1663,  1792, -2370, -2370,
    1817, -2370, -2370, -2370, -2370, -2370, -2370,   494, -2370,  1121,
    1563,  1891,   633, -2370,   -22,   -70,   593,  1650,  1648,   593,
   -2370,  1651,   446, -2370,   495, -2370, -2370,  1721,  1740, -2370,
     960,  1189, -2370, -2370, -2370, -2370, -2370,  1809, -2370, -2370,
   -2370,  2077, -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1876,
    1189, -2370,   -76, -2370, -2370,  1419,  1189, -2370, -2370, -2370,
   -2370,   -12, -2370,  1630, -2370,  1438,  1810, -2370, -2370, -2370,
   -2370,  1907,   633,  1911,    95, -2370, -2370, -2370, -2370,  2095,
   -2370,  1671,   151, -2370, -2370,   152, -2370, -2370, -2370, -2370,
    1609, -2370, -2370, -2370,  1987,  1977,  1479, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  1752,  1479, -2370,  1672, -2370,  2070,
   -2370, -2370, -2370,   710, -2370,   875,   724, -2370,    25,   189,
      -6,   593,   593,   633,  1920,  1231,   113,   676,  1979, -2370,
   -2370, -2370,  2118, -2370,  1931, -2370, -2370, -2370, -2370,  1830,
   -2370, -2370, -2370, -2370,  1121,  1999,  1808,  1111, -2370,  1628,
   -2370,  1632,   875,   972, -2370,   494, -2370, -2370, -2370,  5596,
    1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,   751, -2370,
     -11,  1808,   443, -2370, -2370,  1708,  1708, -2370, -2370,   388,
    1121,   633,  1934,  1687, -2370,  1694,  2133,  1121,   588,   554,
    2136,  1640,  1189, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,  1067, -2370, -2370, -2370,  1121,   467, -2370, -2370,
    1189,  1805,   501,  1381, -2370, -2370, -2370,  1121,  1121, -2370,
   -2370,   425, -2370, -2370, -2370, -2370,   425, -2370, -2370,  1189,
    1425,  1189, -2370, -2370, -2370,  1189, -2370, -2370, -2370,   159,
   -2370, -2370, -2370,  1189,  1642,   425,   425, -2370, -2370,   425,
   -2370, -2370,  1852, -2370, -2370,  1919, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  1565,   -15, -2370, -2370,  1854,    16,
    1944,   633,   422, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
     -33,   157, -2370, -2370, -2370,   410, -2370, -2370, -2370, -2370,
   -2370, -2370,   425, -2370, -2370, -2370, -2370,   425,   504,   504,
   -2370, -2370, -2370, -2370, -2370,  1649,   593, -2370,   593,  1377,
   -2370,   753,     6,   152, -2370, -2370, -2370,  2095,  1121, -2370,
   -2370, -2370, -2370,  1655,  1203,    17,  1656,   422,   875, -2370,
   -2370,  2099, -2370, -2370, -2370, -2370,   724, -2370,  1961, -2370,
    1189,  1519,  1844, -2370, -2370,   593, -2370,   593,   676, -2370,
   -2370, -2370,  1113, -2370, -2370,  1121,  5596,   526, -2370, -2370,
   -2370,  1866, -2370, -2370,  1894, -2370, -2370, -2370, -2370,  1632,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,   -25, -2370,  1121, -2370, -2370, -2370,  1036, -2370,
   -2370, -2370,  7137, -2370,  5596,  5596,  1698,  1834,  1565, -2370,
     593, -2370,   422, -2370,  1847, -2370,   875, -2370,  2058,  1736,
   -2370,   880, -2370,   502, -2370,  1640, -2370,  1121, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370,  1327, -2370, -2370,   -54, -2370,
    1121, -2370, -2370, -2370, -2370, -2370, -2370,   743, -2370,   467,
     743, -2370, -2370, -2370,   110,  2126,  2530,  1919, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370,  1766,  1972, -2370, -2370, -2370,
    1975, -2370, -2370, -2370, -2370, -2370, -2370,  1886, -2370,  1563,
   -2370, -2370, -2370, -2370,  1121, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370,  3275, -2370, -2370, -2370,  1331,
   -2370, -2370, -2370,  2537, -2370,   633,  1823,   633,  1832, -2370,
   -2370,  5596, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370,  1203, -2370,  2080, -2370,  1479, -2370, -2370, -2370,   422,
    1225, -2370, -2370,  1225,   153,  1121, -2370, -2370,   633, -2370,
   -2370,  1799, -2370,  2134,  1924,  1948,   -65, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    -201, -2370, -2370, -2370, -2370, -2370,  1893,  1189,  1766,   633,
    1699, -2370,  2133, -2370,  1638,  2092,  1638,  1698, -2370, -2370,
   -2370, -2370,  1900, -2370, -2370, -2370, -2370,  1336, -2370,  1121,
    1252, -2370, -2370,   501, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,   425, -2370, -2370, -2370,   425,   -27, -2370, -2370,
    1189, -2370, -2370, -2370,  1189, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,  2138, -2370, -2370,     0, -2370,  2187, -2370, -2370,
   -2370,  2530, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    1121, -2370, -2370, -2370, -2370,  2537, -2370,   593, -2370,   593,
   -2370, -2370, -2370,  2148,  2089,  1225,  1225, -2370,  1745,  1745,
   -2370,  1863,  1231,   779, -2370,  1121, -2370, -2370,  5596, -2370,
    1189,   626,  1949,  1950, -2370,  1952, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370,  1121, -2370, -2370, -2370, -2370,  1767, -2370,
    1121,  1638, -2370,  1121, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370,  1355,  1189,  1189,  1143, -2370, -2370, -2370, -2370, -2370,
   -2370,  1530, -2370, -2370, -2370,  2106,   425,   425,  1189,   504,
     504, -2370,   501, -2370, -2370, -2370,  1766,  1766,  5596, -2370,
    1225, -2370,  5596,  5596,  1189,  1231,  1231,  1880, -2370, -2370,
    1741,  1121, -2370, -2370,  1866, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,  1047, -2370, -2370,  1121, -2370, -2370, -2370,  1189,
     501,   501, -2370,  2009,  1189,  1189, -2370,  2814,  1769, -2370,
   -2370,   467, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,   446,  1231,  1189, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370,  1292, -2370, -2370, -2370, -2370,  2116, -2370,
     501, -2370, -2370, -2370,   501,   501,  2003,  1928,   -26,  1431,
    1940,  1730,  1189,  1563, -2370,  1189,  1189,  1121, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370,   591, -2370, -2370,   591, -2370, -2370, -2370,  1272,  1805,
   -2370, -2370, -2370,   446, -2370,  1868,  1819,  1609, -2370, -2370,
   -2370, -2370, -2370,  2002, -2370,  1189, -2370,  1413,  1918, -2370,
    7408,  7408,  1726,  2122,  2046, -2370, -2370, -2370,  1988, -2370,
   -2370,  1988, -2370, -2370, -2370, -2370,   722, -2370, -2370,  1121,
   -2370,  1342,    82, -2370,   803,  1425, -2370, -2370,  1565,  7153,
   -2370, -2370,   911,  1214, -2370, -2370,  1217, -2370, -2370, -2370,
   -2370,   -16,    -8, -2370, -2370, -2370, -2370, -2370,  7408, -2370,
   -2370, -2370, -2370, -2370, -2370,  1906,   903,    82, -2370, -2370,
    1927, -2370, -2370,  1431,  1431, -2370, -2370, -2370,  1783, -2370,
    1609,  1121, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370,  2198, -2370,  1609, -2370, -2370,
    1946,  1121, -2370, -2370, -2370, -2370,  1833,    62, -2370,  7408,
     579, -2370, -2370,  1431, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  1231, -2370
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2370, -2370, -2370, -2370, -2370,  2244, -2370, -2370, -2370,   197,
   -2370,  2207, -2370,  2165, -2370, -2370,  1417, -2370, -2370, -2370,
    1494, -2370, -2370,  1354,  2233, -2370, -2370,  2135, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,  2059,
     927, -2370, -2370, -2370, -2370, -2370,  2113, -2370, -2370, -2370,
   -2370,  2057, -2370, -2370, -2370, -2370, -2370, -2370,  2189, -2370,
   -2370, -2370, -2370,  2045, -2370, -2370, -2370, -2370,  2030, -2370,
   -2370,   788, -2370, -2370, -2370, -2370,  2119, -2370, -2370, -2370,
   -2370,  2093, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  1065, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  1753, -2370,  1861, -2370, -2370, -2370,
    1806, -2370, -2370, -2370, -2370,   411, -2370, -2370,  1992, -2370,
   -2370, -2370, -2370, -2370,  1857, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    1274, -2370, -2370, -2370,  1511, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,   643,
   -2370, -2370,  1788, -2370,  -754,  -817, -2370, -2370, -2370,   248,
   -2370, -2370, -2370, -2370,   267, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -1390,   868,  1548,   558,   613, -1388, -2370, -2370,
   -2370,  -298,  -368, -2370, -2370,   436, -2370, -2370,   141, -1387,
   -2370, -1384, -2370, -1382, -2370, -2370,  1509, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,   341, -1740, -2370, -2370, -1237, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370,  -264, -2370,  -295, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
    1465, -2370, -2370, -2370,   124,   125, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370,  1289,   329, -2370,
     257, -2370, -2370, -2370, -2370, -1715, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -1414, -2370, -2370,  -695, -2370,  1534, -2370,
   -2370, -2370, -2370, -2370, -2370,  1109,   592,   595, -2370,   508,
   -2370, -2370,   -42, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,   560, -2370, -2370, -2370,  1104, -2370, -2370, -2370,
   -2370, -2370,   870, -2370, -2370,   278, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,   874,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370,   850, -2370, -2370, -2370,
   -2370, -2370,    97, -1752, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370,   833, -2370, -2370,   832,
   -2370, -2370,   509,   279, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370,    84,   794, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,   791, -2370, -2370,   266, -2370,   499,
   -2370, -2370, -1804, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370,  1040,   797,   265, -2370,
   -2370, -2370, -2370, -2370, -2370, -1350,  1045, -2370, -2370, -2370,
     264, -2370, -2370, -2370,   481, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370,   433, -2370, -2370, -2370, -2370, -2370, -2370,   773,   252,
   -2370, -2370, -2370, -2370, -2370,  -131, -2370, -2370, -2370, -2370,
     455, -2370, -2370, -2370,  1026, -2370,  1028, -2370, -2370,  1243,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,   231,
   -2370, -2370, -2370, -2370, -2370,  1016,   444, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,    72,
   -2370,   447, -2370, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -2370, -2370,  -271, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370,   -75, -2370,   738, -2370, -2370, -1644, -2370, -2370,
    -661, -2370, -2370, -1670, -2370, -2370,    71, -2370, -2370, -2370,
   -2370,   -20, -1441, -2370, -2370,    74, -1819, -2370, -2370, -1942,
   -1529, -1066, -1429, -2370, -2370,   849, -1280,   255,   260,   261,
     263,  -904,  -161,  -763,   432,   171, -2370,   654,  1590, -1375,
   -1076,  -872,  1057, -1538,  -392,  -326, -2370, -1302, -2370, -1031,
   -2369,   936,  -531,   -98,  2083, -2370,  1702,  -554,    46,  2238,
   -1065, -1044,   193,  -976, -2370, -1102, -1062, -2370,   500, -1285,
   -1042, -1089, -1158, -1730, -2370, -2370, -2370, -1095, -2370,   284,
     178,  -631, -2370, -2370,  -103, -1179,  -769,   -99,  2124, -1240,
    2155,  -673,  1312,  -538,  -633, -2370, -2370, -2370,   -56,  1430,
   -2370, -2370,   492, -2370, -2370, -2370, -2370, -2370, -2370, -2370,
   -2370, -2370, -1954, -2370, -2370,  1653, -2370, -2370,  -124,  -591,
    1984, -2370,  1220, -2370, -1296,  -287,  -621,   959, -2370,  1895,
   -1424, -2370, -2106, -2370, -2370,    18, -2370,    -4,  -654,  -356,
   -2370, -2370, -2370, -2370,  -242,  -247, -2370, -1178, -1527,  2193,
    1964, -2370, -2370,  -342, -2370, -2370,  1072, -2370, -2370, -2370,
     503, -2370,   345, -1921, -1462, -2370, -2370, -2370,  -167,   557,
   -1379, -1202, -2370, -2370, -2370,  -148, -2370, -2370,  1711, -2370,
    1859, -2370, -2370, -2370,   871, -2370, -1802,  -171, -2370, -2370,
   -2370, -2370, -2370, -2370
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1848
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   689,   138,   741,   141,   139,   579,
     415,   759,  1253,   147,   245,   990,   404,   160,   733,   778,
     975,  1014,   838,  1238,  1433,  1867,  1859,   215,  1700,  1346,
    1702,  1703,   139,   427,  1704,  1768,  1705,   180,  1264,  1710,
    1871,  1599,   268,   464,   696,  1284,  1827,  1592,   437,  2178,
    2195,  2040,   103,   104,   105,  1000,  1460,  1616,  1398,  1345,
     111,   463,  1275,  1469,  1219,  1752,  1275,  2102,   790,  1452,
    1821,   279,  1409,  -671,  1328,   259,   768,   411,   211,   264,
    1275,   246,   220,   345,  1498,   392,   843,   838,   360,  1826,
    1996,  2646,  2129,  2242,  1784,   134,   135,  2232,   136,    99,
    2024,   535,  2445,   143,   144,  1234,   107,   321,   114,   825,
    -669,  2038,   161, -1803,   480,   790,  1555,  1209,  1812,   821,
     821,   529,   448,  2449,  1830,  1252,  1256, -1834,  1834,   169,
    1743,  1546,  2205, -1590,  1508,  1946,   700,  1745,  1298,  1300,
    1453,  1848,  2047,  1717,  1190,   465,   215,  1190,  1508,  1565,
     985,  2402,   297,  1868,    42, -1847,   219,  1357,  1209,  1955,
    2669,   744,  1333,  2209, -1562,   -96,   291,   821,  2672,  1605,
    1428,  2403,  1816,  1816,  1938,   701,  2033, -1563,  1190,   453,
    1787, -1568, -1749,  2585,  2298,  1863,  1219,   251,   305,  1849,
    1680,  2181,  1681,  2086, -1847,   693,   327,  2404,  2420,   258,
    2423, -1803,   419,  1416, -1745,  1158, -1745,   221,  1007,   796,
     535,  -671,  2082,    23, -1847,  -671,  1643,   127,  2171, -1566,
    1443,   505,  2405,    94,   717,   316,  1176,  1420,    43, -1781,
    1539,    94,   405, -1845,   413,   705,  2176,    94,  2695,   715,
    1539,  1383,   515,  2649, -1776,   295,  1876,   154,  -669,  1921,
    1327,  2139,  -669,   299,     3,  2188,  2189,  1167,  1463,  2190,
      15,  1847,  1168,  -500,   274,   275,  1216,  2184,   418,  1333,
    1377,  1410,    94,  -671,  2263,  1877,  1597,   204,  2649,  2122,
     516,  1177,  2123,   406,    18,   999,   317,   318,   212,    43,
    1537,  -500,  -500,  1421,   718,  2586,   716,  1275,   155,    24,
     156,  1539,  2226,  2058,  1644,   694,   -96,  2227,  2083,  1850,
    -669,   749,   706,  2034,   707,  2485,   128,  1162,   311,   601,
    1556,  1180,  1149,  1162,  1147,  1746,  1162,  2088,   314,   306,
     243,  1214,  2314,  1785,   985,   985,   985,  1598,  1216,  1926,
     139,  2201,   139,   139,  1925,  1931, -1816,   485,   486,   139,
     956,  2194,   957,     5,   491,   752,   985,  1190,   493,   410,
     280,  2026,   137,  2243,  1238,   753,   139,   466,  2030,   507,
     507,   485,   507,  1851,  2063,   507,   514,   823,  2391,  1357,
     283,  2011,   281,  2066,   747,  2210,  1162,   424,   745,  1387,
    1387,  1387, -1745,  1821,  1162,  1378,  1821,  1162,   436,   512,
     449,  1939,  1400,  1402,  1547,   826,  -500,   443,   444,  1408,
     445,   446,  1234,   139,  -671,   154,   452,  1238,   542,  2059,
     412,   963,   467,  2317,  1363,   748,   368,  1523,  2206,  1234,
    2171,   747,  1264,   469,  -500,  2406,   260,   139,   139,  1290,
     783,  1523,   542,   580,  2215,   754,  1181,  1182,  1995,   492,
    2324,  -669, -1749,  2385,  2386, -1749,   -35,  1721,  1541,  1566,
    1234,   985,   450, -1834,  1753,  2211,   702,  2056,  2337,   137,
    2039, -1745,  1001,  1470,  2105,  1548,   139,  1364,   989,  1291,
     536,   580,  2450,   747,  1238,  1317, -1749,   137,   137,   137,
      97,  1234,  1862,   686,   284,   139,   137,   767, -1776,   129,
     697, -1781,  1786,  1781,  2244,  -676,   996,  2502,  2503,  1832,
     243,   540,   985,  1275,   137,   755,  1811,  1813,  2052,   985,
     985,   985,  1394,  -500,  1363,  2365,  1967,  1394,   844,   265,
     577,   346,   985,   985,   985,   985,   985,   985,   985,   985,
    1875,  1394,   985,  2363,   413,   732,  1600,   735,  1238,  1937,
     591,  1464,   593,  1539,  1537,   598,   600,   322,   602,   756,
     149,  1363,   261,  1415,   394,  2376,   137,  2378,  1499,   137,
    2071,  1437,  2005,  1435, -1648,  2009,  2191,  1364,  2282,  1470,
    -676, -1847,  2476,  2460,  1864,   679,   137,   749,    16,   536,
     688,   292,  2197, -1749,  1317,   783, -1749,   699,  2396,  1234,
    1852,   130,  2443,   137,  1817,  1817,  2444,  2110,   989,   757,
     243,   255,   430,  2224,  1364,  1818,  1818,  2212,   749,   750,
     751,  1167,   607,  2040,  1821,  1898,  1168, -1749,  2414,  2415,
    2127,   752,  2494, -1847,   749,   749,  1913,  1914,  1332,  1234,
    1918,   753,  2247,  1484, -1847,  1163,  2249,   137,  1922,   681,
    2392,  1163,   704,  -500,  1163,   740,   351,   956,   517,   957,
     832,  1006,   752,   824,  2659, -1749,   749,    27,   829,   834,
     834,  2235,   753,  2237,   956,  1612,   957,  1317,   752,   752,
    1238,   154,   949,   991,  -674,  2277,   749,  2130,   753,   753,
    1428,  2216,  2217,  2218,  2658,  1164,   772,   749,  2018,   773,
    1773,  1646,  1216,  1770, -1628,   956,  1233,   957,  1246, -1816,
     752,   222,  2268,   525,  1163,  2015,  2499,  2500, -1847,  1848,
     753,   754,  1163,  1228, -1745,  1163, -1745,  1320,   963,  1325,
     752,  2017,     4,  2072,  1351,  1198,   956,  -666,   957,   216,
     753,   752, -1847,  2274,   211,   963,  1492,  1127,  1373,  2699,
    2001,   753,   754,  2052,  2219,  2099,  1333,  2163,   154,  -674,
     154, -1847, -1847,    28, -1630,  2299, -1632,  1849,   754,   754,
    1665,  1244, -1625,  1333,  1167,  1658,   963,   737,  2364,  1168,
    1680,  2073,  1681,  2258,  2366,  1286,  2507,  2508, -1847,  1900,
    2630,   755,   518,  2384,  2369,   328,  2085,  1901,  1666,  1667,
     754, -1530,  1748,  1962,  2700,   749, -1749,   963,  1150,  1151,
   -1847,  1362,  2701, -1847,  1915,  1156, -1847,  1275,  1539,   682,
     754,   394,   755,  2315,  1976,  1807,  1808,  1809,  1810,  1769,
   -1761,   754,   431,   985,  1169,   756,  1773,  1128,   755,   755,
    1454, -1847,  2284,  1170,   956,   749,   957,  2163,  1613,   752,
     129,  2316,  1472,  2131,  2465,   187,     5,  1775,  2160,   753,
    1661,  2303,   188, -1847,  2407,   187,   756,  2408,  2409,  1601,
     755,  2019,   188,     5,   223,  -666,  2220,  2221,  1129,  -666,
    2410,  2222,   756,   756,   956,   757,   957,  1850, -1847,   752,
     755,   243,   519,  1942,  2425,  2426,  2702,   139,   139,   753,
    1893,   755,  1977,   243,  1475,  1602,  1882,  1130,   137,   243,
     137,  1185, -1745, -1530,   756,   963,   757,  2278, -1847,   738,
    2595,   985, -1083,  2112,    33,  1493,   137,   137,  2513,   137,
     217,   137,   757,   757,   756,  2172,   749,  -666, -1847,   754,
    1963,    94,  1916,  2230,  2230,   756,  1883,   470,   471,   472,
     137,  1851,   130,  2454,   212,   963,   438,  1455,   137,  1545,
    2475,   982,  1902, -1847,   757,  2074, -1083,  1444,  1720,    36,
    2236,   137,  2238,   329,   182,   243, -1083,    40,  1423,   754,
     752,   283,  2466,  1583,   757,  2010,  2574,  1945,  2246,   137,
     753, -1745,  1222,    39,  1903,   757,  1242,  2480,   137,   822,
    1223,  1131,   439,  1242,  1277,   137,   137,  1242,   137,   755,
    1295,  1238,  2172,  2326,   717,  1316,  1904,  1323,  1394,  1323,
    1331,  1348,  1295,   985,   717,  2257, -1847,   228,   117,   243,
    1668,  2370,   330,  2517,   581,  1625,    49,  2308,    52,  1323,
    2281,  1539,   300,   839,  2006,    48,   997,  1721,   154,   755,
    2612,  1317,   728,   756,  2596,  2090, -1083,   243,  2528,   154,
    2617,  2240,   183,  1267,  1238,   747,  1458,   189,   473,  1905,
     754,   229,  2327,  1448,   712,  1456,  1949,   189,  -666,  1774,
     325,   230,   474,   394,   720,    53,  2441,   749,  2650,  2651,
    2333,   243,   137,   756,   722,   284,  2467,   137,  2664,  1836,
    2301,  1301,  1837,   757,   243,  1838,  1839,  2548,   839,  2549,
    2551,  1775,   344,  2552,  1222,  2553,  2003,  1544,  2568,  1424,
    2273,  2533,   253,    54,  2652,    55, -1083,    56,  2031,  1906,
    1008,   752,  2653,  2687,  1242,    57,    51,   137,   952,   190,
     755,   753,  2041,   757,   400,   982,   982,   982,  1608,   190,
    2690,  1224,  2704,  1225, -1761,   953,  1302,   582,  2292,  2292,
    1669,   232,  2572,  1420,  1303,   475,   187,   982,   187, -1751,
   -1083,  1242,  2309,   188,  2518,   188,   717,   476,  1852,   243,
     394,  1242,   226,   253,   756,  1615,   717,  1268,  1269,   583,
   -1763,    58,  2075,  1202, -1530,   191,   747,  2492,  1576,  2168,
     192,  2328, -1530, -1530,  1270,   191,  2329, -1530,  1609,  2678,
     192,  1610,  2506,  2519, -1083,  1837,  1626,  2387,  1838,  1839,
   -1083,   754,    93,  2608,  1907,  1331,  1647,   611,   137,  1421,
    1651,   233,  2493,  2388,   757,   351,  1879,  1653,  1242,  2496,
    2200,  2679,  1242,  1510,  1511,   361,   724,  1577,  1304,  2487,
     252,  2520,  1586,  2531,  2532,   709,   726,   954,  1271,  2488,
     254,  2680,  2389,   555,  2003,  2380,  2654,   477,   749,   952,
    1201,   608,  1215,  1627,   742,  1231,   139,   362,   556,  1254,
     227,  1640,  1512,  1513,    60,  1766,   953,  1458,  1569,  1932,
    1289,   755,   100,  2578,  1251,  2569,  1315,  2579,  2580,  1353,
    2451,  2456,  1639,  2457,   609,   154,  1570,   743,   819,   819,
    1767,   139,   752,   255,   958,   959,   960,  1371,   557,  1375,
     961,  2600,   753,   982,  2603,   236,   101,  1360,    61,  2575,
     982,   982,   982,  1392,  2225,   756,   416,  1754,  1392,  2204,
    1405,  1406,  1407,   982,   982,   982,   982,   982,   982,   982,
     982,  2325,  1392,   982,  2230,  2230,   819,  2505,  2600,   962,
    2162,  2640,  1397,   820,   820,  2591,   228,  1840,  1841,  2290,
      26,  2006,  1167,  2103,  2196,  2270,   403,  1168,   189,   137,
     189,  1434,  1259,  -873,   441,   757,  -873,    47,   954, -1568,
    1754,  1842,  1843,  1260,  2204,  1866,    91,  1294,  2104,   749,
    2271,  2665,   754,    97,  2667,  1315,   783,  1231,  1660,  1294,
     229,   820,  2571,  1673,  1709,  1619,  1711,    64,  1167,  1887,
     230,    94,  2470,  1168,  2666,  1896,  1190,  2668,   106,  2431,
      21,    22,  1204,   964,   231,   170,  1897,  1222,   956,  2432,
     957,  1950,  1951,   752,  1912,   958,   959,   960,    94,    46,
     190,   961,   190,   753,  1242,   558,  1166,  1754,  1205,  -873,
      67,  2487,  2433,  1975, -1749,  1167,   559,  1894,  1222,  2204,
    1168,  2488,   755,  1985,  1986,   428,  -873,  1989,   118,   171,
    1840,  1841,  2509,   108,   965,   966,  2510,  2511,  1315,   172,
     962,  1524,  2434,  1525,  1242,   155,    13,   156,   749,   985,
     232,    13,  1655,  2643,  1842,  1843,   191,  2644,   191,   963,
    1593,   192,  1167,   192,   592,  2158,   756,  1168,   114,   599,
    1419,  1754,   109,  1656,  1419,  1167,   970,  1924,  2618,  2620,
    1168,    68,  1167,   754,  2042,  2043,  1621,  1168,   508,  1964,
     510,  1965,   752,   511,   139,   594,   971,   595,   706,  1933,
     707,   972,   753, -1546, -1546, -1546, -1546,  2663,   973,  1630,
     137,  1631,   120,   298,   964,   110,   757,   560,   561,   173,
     233,  2604,  2605,   234,   235,  2035,  2675,  2036,  -873,  2321,
     112,  2322,   562,  2372,   563,  2373,  2204,   113,  2428,  -873,
    2429,  1970,  1934,  1935,  1936,  1727,   122,  1728,  1940,  1403,
    1404,  1943,  1944,   755,   124,  1910,  1593,   952,  1486,  1487,
    1488,  1489,  1978,   126,   193,   965,   966, -1545, -1545, -1545,
   -1545,  1157,  -873,  1159,   953,   137,  2319,  2698,  -873,   140,
    -873,   142,   754,  -873,   149,  -873,  -873,  -873,   163,   174,
     167,  -873,   162,  -873,   982,  1389,  1390,   756,  -873,  1242,
     164,   181,   185,  1242,   186,   204,  1242,   970,   247,  1222,
     193,  1947,  1948,   242,   236,  1790,   248,   564,  1791,   249,
    1725,  1726,  1961,   250,   257,  1792,  1793,   971,   269,  1966,
    -873,   273,   972,   175,   278,  -873,   294,   154,   296,   973,
     303,   137,   721,   723,   725,   727,   428,   757,   302,  -873,
    2092,   307,   755,   309,   300,   308,   312,   326,  1979,  1242,
     313,  1727,   334,  1728,   565,  1729,   333,   336,   338,   340,
     342,  1794,   349,  -873,  1593,  2266,   954,   351,   353,   354,
     356,   392,   982,   176, -1749,   394,   401,   749,   403,   397,
     398,   408,   187,   409,   243,   420,   756,   421,  1874,  1730,
    1731,  1732,  2137,   422,  -873,   429,   413,  1881,  1242,  1242,
    1242,  2137,  1887,   454,   455,   457,  -342,  2025,  1890,  2113,
    2114,  2115,  2116,  2117,  2118,  2119,  2120,   459,   483,  2621,
    2492,   752,   487,   958,   959,   960,  2032,  -873,   490,   961,
    1795,   753,  2037,  -873,   494,  1478,   757,  1919,   495,  1733,
     502,  1734,   509,   521,   522,  -873,  -873,  1593,  1735,   523,
     533,  1736,   543,   527,   547,  2622,   549,   551,  1242,  1796,
     548,   552,  -355,   554,   578,   585,   586,   603,   962,  1392,
     587,   610,  2487,   605,   982,   613,   614,  -873,   685,   687,
     711,  1797,  2488,   139,   728,   736,   698,  -873,  2159,   690,
     762,   730,  1960,  -873,   746,   765,   769,   771,  1295,   781,
     786,   777,  1315,  1295,   783,   791,   780,  -873,   793,   797,
     950,   754,  -873,   830,  1972, -1749,   823,  1973,   989,  -873,
    2182,  -873,  1295,  1295,   836, -1632,  1295,  -873,   994,   995,
     998,  1019,  1011,  1135,  1016,  1798,  1116,  1143,  1737,  1145,
    1738,  1171,   964,   952,  1183,  1187,  1152,  1153,  1242,  1154,
    1155,  1593,  1196,  1257,  1160,  1172,  1202,  1333,  1378,   747,
     953,  2092,  1189,  1197,  1174,  1278,  1411,  2004,  2157,  1295,
    2276,  1385,  1175,  1412,  1295,  1295,  1295,  1386,  1413,  2231,
    2231,   755,  1426,  1242,  1432,  1242,  2161,  1438,  1799,  1447,
    1449,  1467,  2641,   965,   966,  1461,  1490,   985,   985,  1396,
    1473,  1496,  1476,  1538,  1554,  2177,  1557,  2179,  1558,  1541,
    1494,  2180,  1560,  1562, -1548,  1571,  1572,  1573,  2607,  2185,
    1574,  1579,  1242,  1584,  1242,   756,   985,  1581,  1588,  1590,
    1333,  1604,   952,  1606,  1190,   970,  1617,  1629,  1622,  1635,
    1633,  1641,  1637,  1648,  1203,   985,  1649,  1650,  1800,   953,
    1652,  1662,  1654,  1659,  1657,   971,  1713,  1712,  1715,  1664,
     972,  1801,   954,  1749,  1759,   799,  1718,   973,  1756,   137,
    1757,  1761,  1216,  1593,  1593,   757,  1771,  1242,  1782,  1775,
    1788,  1478,  1822,  1825,  1805,  1833,  1846,  2623,  1547,  1861,
    1295,  2624,  2625,  1869,   139,  1888,   985,  1892,  1884,   542,
    1899,  1920,  2098,  1927,   800,   801,   802,   803,   804,  1968,
    1593,  1954,  1971,   428,  1974,  1980,  2265,  1451,  1981,   958,
     959,   960,  1983,  1720,  1990,   961,  1998,  1993,  1994,  1739,
    1997,  1999,  2626,  2000, -1518,   984,  2012,  2016,  2138,   626,
     627,  2022,  2023,  1802,  2027,  2148,  2148,  1428,  2627,  2628,
    2046,   954,  2053,  2054,  2048,  2060,  2061,  2064,  2067,  2068,
    2093,   428,   749,  2087,   962,  1231,  2095,  2096,  2099,  2106,
    2166,  2133,  1242,  2107,  1242,  1960,  1960,  2140,  2141,  1740,
    2142,    52,  2143,  2152,  2154,  2186,  2192, -1567,  2259,  2262,
    1741,  2198,  2233,  2250,  2256,  1204,  2280,  2278,  2267,  2294,
    2302,   956,   139,   957,  2297,  1242,   752,  2394,   958,   959,
     960,  2304,  2306,  2338,   961, -1523,   753,  2006, -1565,  2397,
    2367,  1205,  2382,  2398,  2377,  2400,  2399,  2421,    53,  2411,
    2203,  2416,  2309,  2379,  2448,  2451,  1242,  2458,   964,  2459,
    2464,  2461,   805,   806,   807,   808,   809,   810,   811,   639,
     640,  2477,  2478,   962,  2479,  2498,   139,  2514,  2483,  2533,
    2570,   580,  2515,  2577,  2581,  2588,    54,  2583,    55,  1295,
      56,  2589,   963,  1295,  2613,  2609,  2248,  2610,    57,  2616,
     357,  2637,  2638,  2676,  2163,  2203,  1593,  2689,  2683,   965,
     966,    17,  2691,    92,  1593,   358,   754,   125,  2693,    38,
     256,   209,   166,   266,   119,   359,   277,  1148,   290,   210,
     241,   442,   545,  1874,  1242,   504,  1242,  2089,   323,   984,
     984,   984,   456,  1184,   835,   526,  1701,   964,   787,  2615,
    2686,   970,  2469,  2413,    58,  2081,  2318,   993,  2170,   360,
    2601,   984,  2285,  2639,  2334,  2335,  1015,  1195,  2241,  1430,
     982,   971,   428,   948,  2045,  1988,   972,  1987,  2014,  2453,
    2203,  1446,  1764,   973,  1593,   137,   755,  2239,  1765,  1780,
    2375,  1815,  2245,  1823,  2057,  2381,  2446,  1845,   965,   966,
    2447,  1857,  2261,  1295,  1295,  1561,  1295,  1295,  1960,  1295,
    2231,  2231,  2069,  2269,   812,  1564,    59,  1231,  1865,  2272,
    2097,  2283,  2151,  2121,  1891,  1595,  2293,   813,  1349,  1596,
     756,  1620,  2149,   980,  2419,  2150,  2682,  1930,  2424,  1829,
     970,  2474,   332,  2286,  1763,  1587,  2427,    60,  2287,  2288,
     213,  2289,  2371,   764,   310,  2111,  2471,   293,   795,  2576,
     971,   447,  1161,  1414,   539,   972,   984,  2463,   272,  1222,
    2255,  1243,   973,   489,   137,  2080,   774,   597,  1243,  2135,
     757,  2631,  1243,     0,  1860,     0,     0,     0,  2490,  2491,
       0,    61,     0,     0,    62,     0,  1243,  2203,     0,     0,
    2587,     0,     0,     0,  2501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   361,   984,     0,     0,
    2512,     0,     0,     0,   984,   984,   984,  1393,     0,     0,
    1222,     0,  1393,     0,     0,     0,     0,   984,   984,   984,
     984,   984,   984,   984,   984,  2530,  1393,   984,   362,     0,
    2534,  2535,     0,     0,     0,     0,     0,     0,  -228,    63,
       0,  2166,     0,     0,     0,     0,     0,     0,     0,  1222,
    2573,     0,     0,     0,     0,  2657,  1436,     0,     0,     0,
      64,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2590,     0,
       0,  2592,  2593,     0,  1222,    65,     0,    66,  2455,  1243,
       0,   363,     0,     0,  2684,  2685,   364,   980,   980,   980,
       0,     0,  2339,    67,     0,  2340,     0,     0,  2341,     0,
       0,     0,  1790,     0,     0,  1791,  2342,     0,  2692,   980,
       0,  2614,  1792,  1793,     0,     0,  1243,   365,     0,     0,
       0,  2481,     0,     0,  2705,   366,  1243,     0,  2484,     0,
       0,  2486,     0,     0,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2343,     0,     0,     0,     0,     0,     0,  1794,     0,
       0,     0,     0,     0,    68,     0,     0,   368,  1202,     0,
     369,   747,     0,     0,  1594,     0,     0,     0,   370,  2516,
       0,     0,     0,  1243,     0,     0,     0,  1243,     0,  -225,
       0,     0,     0,  2529,     0,     0,     0,     0,  2166,  2166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1231,
       0,     0,     0,  1207,   980,     0,     0,   371,     0,     0,
     372,  1207,  1207,     0,     0,     0,     0,  1795,     0,     0,
       0,     0,     0,     0,  1207,  1207,     0,     0,  2166,     0,
       0,     0,  2166,  2166,   952,     0,     0,     0,     0,  2344,
       0,     0,     0,  1207,  1207,  2594,  1796,     0,  2345,     0,
       0,   953,     0,     0,     0,   980,  1202,     0,     0,   747,
    1594,  2346,   980,   980,   980,     0,     0,     0,  1797,     0,
       0,     0,  1755,     0,     0,   980,   980,   980,   980,   980,
     980,   980,   980,     0,     0,   980,     0,     0,   982,   982,
       0,     0,     0,  2347,     0,     0,     0,     0,   984,     0,
       0,     0,     0,     0,  1895,     0,     0,  2642,     0,     0,
       0,     0,     0,  2348,     0,  2349,     0,   982,  1207,     0,
       0,     0,  1798,     0,     0,  1755,     0,     0,     0,  2671,
    2674,     0,   952,     0,     0,     0,   982,     0,  2350,     0,
       0,     0,     0,     0,  1296,     0,     0,     0,     0,   953,
     952,     0,     0,   954,     0,     0,     0,     0,     0,  2688,
       0,  1207,     0,     0,   749,     0,     0,   953,  2351,     0,
       0,     0,     0,     0,     0,  1799,  1207,     0,  1594,   624,
       0,     0,     0,     0,     0,  2697,   984,   982,     0,  1243,
       0,     0,  1755,     0,     0,  2352,     0,  1204,  1680,  1727,
    1681,  1728,     0,   956,     0,   957,  1207,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
       0,  2353,     0,  1205,     0,     0,     0,     0,  2354,  1243,
       0,     0,   952,     0,     0,  1800,     0,     0,     0,     0,
       0,  2355,     0,     0,     0,  2356,     0,     0,  1801,   953,
       0,   954,     0,     0,     0,   962,  1755,     0,  1307,     0,
       0,  1594,   749,     0,     0,  1207,     0,     0,     0,   954,
    1207,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,  1393,     0,     0,     0,     0,   984,     0,
       0,     0,     0,     0,  2357,  1204,     0,     0,   754,     0,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1205,     0,  2358,  1308,     0,   958,   959,   960,   964,
    1802,     0,   961,  2359,     0,     0,     0,     0,     0,  2360,
    1307,     0,     0,  2536,     0,     0,     0,     0,     0,     0,
    1751,   954,     0,   962,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1594,     0,     0,   755,   642,
       0,   962,   963,     0,     0,     0,   980,     0,     0,     0,
     965,   966,     0,     0,  1243,     0,  2537,     0,  1243,  1207,
       0,  1243,     0,     0,     0,     0,   754,     0,     0,     0,
       0,     0,  1207,  1751,     0,  1896,  1451,     0,   958,   959,
     960,     0,   756,     0,   961,     0,  1897,     0,     0,  2538,
       0,     0,   970,     0,     0,     0,     0,   964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2539,
    1207,     0,   971,  2540,  1243,   964,     0,   972,     0,     0,
       0,     0,     0,   962,   973,     0,   137,     0,     0,     0,
       0,   646,   757,     0,   980,     0,   755,  2541,     0,     0,
    1751,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,  1594,  1594,     0,
       0,     0,     0,  1243,  1243,  1243,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1847,     0,     0,
     756,  1207,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,  1207,  1207,  1594,     0,  1207,   964,     0,     0,
       0,     0,     0,     0,  1751,     0,     0,     0,   970,   651,
     971,     0,     0,     0,     0,   972,     0,     0,  2542, -1136,
       0,     0,   973,  1243,   137,     0,     0,     0,   971,     0,
     757,     0,     0,   972,     0,  2543,   980, -1136,     0,     0,
     973,   243,   137,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,     0,     0,  2544,     0,     0,     0, -1847,
       0,     0,     0,     0,     0,     0,   846,     0,   847,     0,
     848,     0,     0,     0,     0,   849,  2545,     0,     0,     0,
       0,     0,     0,   850,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,     0,  2546,     0,     0,     0,     0,
       0, -1136,   660,  2547,     0,     0,     0,     0,     0,     0,
     971,     0,     0,  1243,     0,   972,   851,   852,     0, -1136,
       0,     0,   973,   243,   137,   853,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   854,     0,     0,   855,
       0,     0,     0,     0,     0,     0,     0,     0,  1243,     0,
    1243,     0,     0,   856,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1594,     0,     0,     0,     0,     0,   857,     0,  1594,     0,
       0,     0,     0,     0,   858,     0,   859,  1243,     0,  1243,
       0,     0,     0,  -713,     0,  -713,  -713,  -713,  -713,  -713,
    -713,  -713,  -713,     0,  -713,  -713,  -713,     0,  -713,  -713,
    -713,  -713,  -713,  -713,  -713,  -713,  -713,   860,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   861,     0,
       0,     0,     0,   862,   984,     0,     0,     0,     0,     0,
       0,     0,  1243,     0,     0,     0,     0,     0,  1594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   846,
     863,   847,     0,   848,     0,     0,     0,   864,   849,     0,
     865,   866,     0,     0,     0,     0,   850,     0,     0,  1207,
     867,     0,     0,     0,     0,     0,     0,   868,     0,   869,
       0,     0,   870,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   851,
     852,     0,     0,     0,     0,     0,     0,     0,   853,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   854,
       0,     0,   855,     0,   871,     0,     0,  1243,   872,  1243,
     873,     0,     0,     0,     0,     0,   856,     0,     0,     0,
     874,     0,     0,     0,     0,     0,  -713,  -713,     0,  -713,
    -713,  -713,  -713,     0,     0,     0,     0,     0,     0,   857,
    1243,     0,     0,     0,     0,     0,   875,   858,     0,   859,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   876,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1243,     0,     0,     0,     0,     0,     0,     0,     0,
     860,     0,     0,     0,   877,   878,     0,     0,     0,     0,
       0,   861,     0,     0,     0,   879,   862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   880,
     881,     0,     0,     0,     0,     0,   882,     0,     0,     0,
     883,     0,     0,   863,     0,     0,     0,     0,   884,     0,
     864,     0,     0,   865,   866,     0,     0,     0,   885,     0,
       0,     0,     0,   867,     0,     0,  1207,   886,     0,  1243,
     868,  1243,   869,     0,     0,   870,   887,     0,     0,     0,
       0,   888,   889,     0,     0,   890,     0,   891,     0,     0,
       0,     0,     0,   892,     0,     0,     0,     0,     0,     0,
       0,     0,   980,     0,  1207,  1207,  -713,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   871,     0,     0,
       0,   872,     0,   873,   894,     0,     0,     0,     0,     0,
     895,     0,     0,   874,     0,   896,     0,     0,     0,     0,
       0,     0,     0,   846,     0,   847,     0,   848,     0,     0,
       0,     0,   849,     0,     0,     0,  -713,     0,     0,   875,
     850,     0,   897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   876,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   851,   852,     0,     0,   877,   878,     0,
       0,     0,   853,     0,     0,     0,     0,     0,   879,     0,
       0,  1207,     0,   854,     0,     0,   855,     0,     0,     0,
       0,     0,   880,   881,     0,     0,     0,     0,     0,   882,
     856,     0,     0,   883,     0,     0,     0,     0,     0,     0,
       0,   884,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   885,     0,   857,     0,     0,     0,     0,     0,     0,
     886,   858,     0,   859,     0,     0,     0,     0,     0,   887,
       0,     0,     0,     0,   888,   889,     0,     0,   890,     0,
     891,     0,   984,   984,     0,     0,   892,     0,     0,     0,
       0,     0,     0,     0,   860,     0,     0,     0,     0,   893,
       0,     0,     0,     0,     0,   861,     0,     0,     0,     0,
     862,   984,     0,     0,     0,     0,     0,   894,     0,     0,
       0,     0,     0,   895,     0,     0,     0,     0,   896,     0,
     984,     0,   846,     0,   847,     0,   848,   863,     0,     0,
       0,   849,     0,     0,   864,     0,     0,   865,   866,   850,
       0,     0,     0,     0,     0,   897,     0,   867,     0,     0,
       0,     0,     0,     0,   868,     0,   869,     0,  1207,   870,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   984,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   854,     0,     0,   855,     0,     0,     0,     0,
       0,   871,     0,     0,     0,   872,     0,   873,     0,   856,
       0,     0,     0,     0,     0,     0,     0,   874,  1207,     0,
       0,     0,  1207,  1207,     0,     0,     0,     0,     0,     0,
       0,     0,   857,     0,     0,     0,     0,     0,     0,     0,
     858,     0,   859,   875,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   876,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   860,     0,     0,     0,     0,     0,     0,
       0,   877,   878,     0,   861,     0,     0,     0,     0,   862,
       0,     0,   879,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   880,   881,     0,     0,
       0,     0,     0,   882,     0,     0,   863,   883,     0,     0,
       0,     0,     0,   864,     0,   884,   865,   866,     0,     0,
       0,     0,     0,     0,     0,   885,   867,     0,     0,     0,
       0,     0,     0,   868,   886,   869,     0,     0,   870,     0,
     980,   980,     0,   887,     0,     0,     0,     0,   888,   889,
       0,     0,   890,     0,   891,     0,     0,     0,     0,     0,
     892,     0,     0,     0,     0,     0,     0,     0,     0,   980,
       0,     0,     0,  1628,     0,     0,     0,     0,     0,     0,
     871,     0,     0,     0,   872,     0,   873,     0,   980,     0,
       0,   894,     0,     0,     0,     0,   874,   895,     0,     0,
       0,     0,   896,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1202,     0,     0,   747,     0,
       0,     0,   875,     0,     0,     0,     0,     0,     0,   897,
       0,     0,     0,     0,     0,   876,     0,     0,     0,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     877,   878,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   880,   881,     0,     0,     0,
       0,   952,   882,     0,     0,     0,   883,     0,  1021,     0,
    1022,     0,     0,     0,   884,  1023,     0,     0,   953,     0,
       0,     0,     0,  1024,   885,     0,     0,     0,     0,     0,
       0,  1353,     0,   886,     0,     0,     0,     0,     0,     0,
       0,     0,   887,     0,     0,     0,     0,   888,   889,     0,
       0,   890,     0,   891,     0,     0,  1025,  1026,     0,   892,
       0,     0,     0,     0,     0,  1027,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1028,     0,     0,  1029,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     894,     0,     0,  1030,     0,     0,   895,     0,     0,     0,
       0,   896,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1031,     0,     0,     0,
     954,     0,     0,     0,  1032,     0,  1033,     0,   897,     0,
       0,   749,     0,  1034,     0,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,     0,  1043,  1044,  1045,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,     0,     0,
       0,     0,     0,     0,  1204,     0,     0,     0,  1056,     0,
     956,     0,   957,  1057,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,     0,     0,
    1205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1058,     0,     0,     0,     0,     0,     0,  1059,     0,     0,
    1060,  1061,     0,     0,     0,     0,     0,     0,     0,     0,
    1062,     0,   962,     0,     0,     0,     0,  1063,     0,  1064,
       0,     0,  1065,     0,     0,     0,     0,     0,     0,     0,
       0,   963,     0,  1202,     0,     0,   747,     0,     0,  1504,
    1505,  1506,     0,     0,     0,     0,     0,  1507,     0,     0,
       0,     0,     0,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,  1066,     0,     0,     0,  1067,     0,
    1068,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,     0,     0,     0,     0,   964,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1070,     0,     0,   952,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1071,
       0,     0,     0,     0,     0,   755,   953,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   965,   966,     0,
       0,     0,     0,     0,  1072,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1073,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   756,
    1074,     0,     0,     0,     0,     0,  1075,     0,     0,   970,
    1076,     0,     0,     0,     0,     0,  1508,     0,  1077,     0,
       0,     0,     0,     0,     0,     0,  1509,     0,  1078,   971,
       0,     0,     0,     0,   972,     0,     0,  1079,     0,     0,
       0,   973,     0,   137,     0,     0,  1080,     0,     0,   757,
       0,  1081,  1082,     0,     0,  1083,     0,  1084,   954,     0,
       0,     0,     0,  1085,  1510,  1511,     0,     0,     0,   749,
       0,     0,     0,     0,     0,     0,  1086,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1828,
       0,     0,     0,     0,  1087,     0,     0,     0,     0,     0,
    1088,     0,  1204,  1512,  1513,  1089,     0,     0,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1205,     0,
    1202,     0,  1090,   747,     0,     0,  1504,  1505,  1506,     0,
       0,  1514,     0,     0,  1507,     0,     0,  1515,     0,     0,
    1516,     0,     0,     0,     0,     0,     0,     0,  1517,     0,
     962,     0,     0,     0,     0,  1518,     0,     0,  1202,     0,
    1519,   747,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,   952,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   953,     0,     0,     0,     0,  1202,     0,
       0,   747,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1358,     0,     0,     0,
       0,   953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1508,     0,   965,   966,     0,     0,     0,
       0,     0,     0,  1509,     0,     0,  -929,     0,     0,  -929,
       0,     0,     0,     0,   952,  1521,     0,  1522,     0,  1523,
       0,     0,  1524,     0,  1525,  1526,  1527,   756,     0,  1528,
    1529,   953,     0,     0,     0,   954,     0,   970,     0,     0,
       0,  1510,  1511,     0,     0,     0,   749,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,   954,     0,     0,     0,   757,     0,  1204,
    1512,  1513,  -929,     0,   749,   956,     0,   957,     0,     0,
     752,     0,   958,   959,   960,     0,     0,     0,   961,  -929,
     753,     0,     0,     0,     0,  1205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1204,  1514,     0,
       0,     0,     0,   956,  1515,   957,     0,  1516,   752,     0,
     958,   959,   960,   954,     0,  1517,   961,   962,   753,     0,
       0,     0,  1518,  1205,   749,     0,  1202,  1519,     0,   747,
       0,     0,     0,     0,     0,     0,   963,     0,     0,     0,
       0,     0,     0,     0,     0,  1478,  1520,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,  1204,     0,     0,
     754,     0,     0,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,     0,   963,     0,   961,     0,   753,     0,
       0,  -929,     0,  1205,     0,     0,     0,     0,     0,     0,
       0,   964,  -929,     0,     0,     0,     0,     0,   754,     0,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,     0,     0,   953,
       0,     0,     0,     0,     0,  -929,     0,     0,     0,   964,
     755,  -929,     0,  -929,   963,     0,  -929,     0,  -929,  -929,
    -929,     0,   965,   966,  -929,     0,  -929,     0,     0,     0,
       0,  -929,     0,     0,     0,     0,     0,  1202,   754,     0,
     747,     0,  1521,     0,  1522,     0,  1523,     0,   755,  1524,
       0,  1525,  1526,  1527,   756,     0,  1528,  1529,     0,     0,
     965,   966,     0,  -929,   970,     0,     0,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -929,     0,   971,     0,     0,     0,     0,   972,
       0,     0,   756,     0,     0,     0,   973,     0,   137,     0,
       0,   954,   970,     0,   757,     0,  -929,     0,   755,     0,
       0,     0,   749,   952,     0,     0,     0,     0,     0,     0,
     965,   966,   971,     0,     0,     0,     0,   972,     0,     0,
     953,     0,     0,     0,   973,     0,   137,  -929,  1440,     0,
       0,     0,   757,     0,     0,  1204,     0,     0,     0,     0,
       0,   956,   756,   957,     0,     0,   752,     0,   958,   959,
     960,     0,   970,     0,   961,     0,   753,     0,     0,     0,
       0,  1205,  1202,     0,     0,   747,  -929,     0,     0,     0,
       0,     0,   971,     0,     0,     0,     0,   972,  -929,  -929,
       0,     0,     0,     0,   973,     0,   137,     0,     0,     0,
       0,     0,   757,   962,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -929,     0,   963,     0,     0,     0,     0,  1624,     0,     0,
    -929,     0,   954,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,   754,     0,   952,     0,
    -929,     0,     0,     0,     0,  -929,     0,  1202,     0,     0,
     747,     0,  -929,     0,  -929,   953,     0,     0,     0,     0,
    -929,     0,     0,     0,     0,     0,  1204,   964,     0,     0,
       0,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
       0,     0,  1205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,   952,   962,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     953,     0,     0,   963,     0,     0,     0,     0,     0,     0,
     756,     0,  1202,     0,     0,   747,     0,   954,     0,     0,
     970,     0,     0,     0,     0,     0,     0,   754,   749,     0,
       0,     0,     0,     0,  1482,  1750,     0,     0,   747,     0,
     971,     0,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,     0,     0,   964,     0,
     757,  1204,     0,     0,     0,     0,     0,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,  1205,   952,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,   954,     0,     0,   953,     0,     0,     0,   965,
     966,   952,     0,   749,     0,     0,     0,     0,     0,   962,
       0,     0,     0,     0,     0,     0,     0,     0,   953,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   963,     0,
       0,   756,     0,     0,     0,     0,  1204,     0,     0,     0,
       0,   970,   956,     0,   957,     0,     0,  1247,     0,   958,
     959,   960,   754,     0,     0,   961,     0,   753,     0,     0,
       0,   971,  1205,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,     0,   964,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,     0,   963,     0,     0,  1917,     0,     0,     0,
     954,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,   749,     0,     0,   965,   966,     0,   754,     0,     0,
       0,  1204,     0,     0,     0,     0,     0,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,  1204,     0,   756,  1205,   964,     0,
     956,     0,   957,     0,     0,   752,   970,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,     0,     0,
    1205,     0,     0,     0,     0,     0,   971,     0,     0,   962,
       0,   972,     0,     0,     0,     0,     0,   755,   973,     0,
     137,     0,     0,     0,     0,     0,   757,     0,   963,   965,
     966,     0,   962,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   963,   754,     0,     0,     0,     0,     0,     0,     0,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,   754,  1013,     0,     0,     0,
       0,     0,     0,   964,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,   964,  -352,     0,     0,
    -352,   757,     0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,  -352,
       0,  -352,     0,     0,     0,   755,     0,     0,  -352,     0,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,   965,   966,     0,
       0,     0,     0,     0,     0,     0,   756,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   756,
       0,     0,     0,     0,  -352,     0,   971,     0,     0,   970,
       0,   972,     0,     0,     0,     0,     0,     0,   973,     0,
     137,     0,     0,     0,     0,     0,   757,     0,     0,   971,
       0,     0,     0,     0,   972,     0,     0,     0,     0,     0,
       0,   973,     0,   137,     0,  -352,     0,     0,     0,   757,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     529,     0,     0,  -352,  -352,  -352,  -352,  -352,   528,     0,
    -352,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,  -352,     0,  -352,     0,     0,     0,     0,  -352,  -352,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,  -352,  -352,     0,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,  -352,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,  -352,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,   529,     0,     0,  -352,  -352,  -352,  -352,  -352,
       0,     0,  -352,  -352,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
    -352,     0,  -352,  -352,  -352,     0,     0,     0,     0,  -352,
       0,     0,  -352,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,     0,     0,  -352,     0,
       0,     0,  -352,  -352,  -352,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,  -352,  -352,     0,     0,  -352,     0,     0,   530,
       0,     0,     0,     0,  -352,     0,   616,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,   617,     0,     0,   618,   619,   620,   621,   622,   623,
     624,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   625,     0,
     626,   627,   628,   629,   630,   631,   632,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,  -352,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,  -352,  -352,     0,     0,     0,
       0,     0,     0,   634,   635,   636,   637,   638,  -352,     0,
     639,   640,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,   530,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   618,   619,   620,   621,   622,   623,     0,     0,     0,
       0,     0,     0,     0,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
     642,     0,     0,     0,     0,   625, -1823,   626,   627,   628,
     629,   630,   631,   632,  1675,     0,     0,  1676,     0,     0,
    1677,   618,   619,   620,   621,   622,   623,  1678,  1679,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,     0,     0,     0,  1680,     0,  1681,     0,
       0,   633,     0,     0,     0,   625,     0,   626,   627,   628,
     629,   630,   631,   632,     0,     0,     0,     0,     0,     0,
     644,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   645,     0,     0,     0,     0,     0,
       0,     0,   646,     0,     0,   647,     0,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,   648,     0,
     634,   635,   636,   637,   638,     0,     0,   639,   640,     0,
     649,     0,     0,     0,     0,     0,     0,     0,   650,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1682,     0,     0,     0,     0,     0,     0,     0,
       0,   641,   952,     0,     0,     0,     0,     0,     0,     0,
     634,   635,   636,   637,   638,     0,     0,   639,   640,   953,
     651,  1683,   652,   653,   654,     0,     0,     0,  1684,     0,
    1685,     0,     0,     0,     0,     0, -1776,     0,     0,     0,
       0,     0,     0,  1686,     0,     0,     0,     0,     0,   655,
       0,   641,     0,     0,     0,     0,     0,     0,     0,   643,
       0,     0,     0,     0,    94,     0,  -349,   642,     0,     0,
       0,     0,     0,     0,     0,  1687,     0,     0,     0,     0,
       0,     0,     0, -1823,  1688,     0,     0,     0,     0,     0,
       0,     0,   656,   657,   658,     0,     0,  1689,     0,     0,
       0,   645,     0,     0,     0,     0,   659,     0,     0,   643,
       0,     0,   647,   660,     0,     0,     0,     0,     0,     0,
       0,   954,     0,     0,   952,   648,     0,     0,     0,     0,
       0,     0,   749,     0,     0,     0,     0,  1690,     0,     0,
       0,   953,     0,     0,     0,     0,     0,     0,     0,     0,
    1691,   645,     0,     0,     0,     0,     0,     0,     0,   646,
       0,     0,   647,     0,     0,   955,     0,     0,     0,     0,
       0,   956,     0,   957,     0,   648,   752,  1692,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,   652,
     653,   654,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1693,     0,     0,     0,     0,     0,     0,
    1694,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   962,     0,     0,     0,  1695,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   651,     0,   652,
     653,   654,   963,   954,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,   656,
     657,   658,     0,     0,     0,     0,   754,     0,     0,     0,
       0,     0,     0,     0,     0,   952,     0,     0,  1696,     0,
       0,     0,     0,  -616,     0,     0,     0,   955,  1697,     0,
       0,     0,   953,   956,     0,   957,     0,   964,   752,     0,
     958,   959,   960,     0,     0,  1698,   961,     0,   753,   656,
     657,   658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659,     0,     0,     0,     0,     0,  1699,
     660,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,     0,     0,  1382,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   967,   952,
     756,     0,   968,   969,     0,     0,     0,     0,   754,     0,
     970,     0,     0,     0,   954,   952,   953,     0,     0,     0,
       0,     0,     0,     0,     0,   749,     0,     0,     0,     0,
     971,     0,   953,     0,     0,   972,     0,     0,     0,   964,
       0,     0,   973,     0,   137,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,     0,     0,     0,   955,     0,
       0,     0,     0,     0,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,     0,     0,   961,   755,   753,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1401,     0,     0,     0,     0,     0,   962,     0,   954,     0,
     967,     0,   756,     0,   968,   969,     0,     0,     0,   749,
       0,     0,   970,     0,   954,   963,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   749,     0,     0,     0,     0,
     952,     0,   971,     0,     0,     0,     0,   972,     0,   754,
       0,     0,   955,     0,   973,     0,   137,   953,   956,     0,
     957,     0,   757,   752,     0,   958,   959,   960,   955,     0,
       0,   961,     0,   753,   956,     0,   957,     0,     0,   752,
     964,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,     0,   962,     0,     0,   963,
       0,   965,   966,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   963,     0,     0,     0,     0,
       0,  1941,     0,   754,     0,     0,     0,     0,     0,   954,
     952,   967,     0,   756,     0,   968,   969,     0,     0,   754,
     749,     0,     0,   970,     0,     0,     0,   953,     0,     0,
       0,     0,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,   971,     0,     0,  2660,     0,   972,     0,
     964,     0,     0,   955,     0,   973,     0,   137,     0,   956,
       0,   957,     0,   757,   752,     0,   958,   959,   960,     0,
       0,     0,   961,   755,   753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   965,   966,     0,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   965,   966,     0,     0,     0,     0,     0,     0,     0,
       0,   962,     0,     0,     0,   967,     0,   756,     0,   968,
     969,     0,     0,     0,     0,     0,     0,   970,     0,   954,
     963,     0,     0,   756,     0,     0,     0,     0,     0,     0,
     749,     0,     0,   970,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,   754,     0,     0,  2661,     0,   973,
       0,   137,     0,   971,     0,     0,     0,   757,   972,     0,
       0,     0,     0,   955,     0,   973,     0,   137,     0,   956,
       0,   957,     0,   757,   752,   964,   958,   959,   960,     0,
       0,     0,   961,     0,   753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,   962,     0,     0,     0,     0,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     963,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   756,     0,
     968,     0,     0,     0,   754,     0,     0,     0,   970,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,   964,     0,     0,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-2370))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   595,   103,   660,   105,   111,   540,
     366,   684,  1101,   111,   181,   784,   358,   116,   649,   714,
     783,   838,   776,  1099,  1202,  1563,  1553,   158,  1418,  1124,
    1418,  1418,   135,   425,  1418,  1459,  1418,   135,  1104,  1418,
    1569,  1343,   209,   435,   598,  1110,  1508,  1332,   404,  1970,
    2004,  1803,    56,    57,    58,    48,  1234,  1353,  1160,  1124,
      64,     1,  1106,  1242,  1095,  1440,  1110,  1886,   741,  1227,
    1499,     1,  1174,     0,     9,     9,   697,   364,    22,     1,
    1124,   184,    96,    57,    17,    86,    55,   841,    63,  1503,
    1734,     9,  1911,    87,    96,    99,   100,  2039,   102,    53,
    1770,   124,   129,   107,   108,     6,    60,     1,    57,    57,
       0,   123,   116,    27,   256,   788,  1295,  1093,  1493,   750,
     751,   175,     9,   123,   114,  1101,  1102,   110,  1542,   133,
    1432,    92,   165,   203,   159,  1662,   174,   152,  1114,  1115,
    1229,     9,  1812,  1428,    49,   125,   277,    49,   159,   141,
     783,   216,   251,  1567,   142,   328,   160,  1133,  1134,   176,
     176,   241,   271,     6,    31,   229,    17,   798,   176,  1348,
      30,   236,    21,    21,   241,   213,   252,    31,    49,   421,
    1482,   203,    87,   209,  2138,  1560,  1217,   191,   229,    57,
      64,    32,    66,  1863,   187,   308,   295,   262,  2304,   203,
    2306,   115,   369,     1,    64,   968,    66,   161,   829,   747,
     124,   138,   218,   256,   107,   142,    27,    72,  1958,   203,
      57,   256,   287,   232,   406,   351,   989,   410,    31,   232,
    1274,   232,   446,   453,   237,   274,  1966,   232,   176,   244,
    1284,  1145,   414,  2612,   204,   249,     8,   256,   138,  1624,
    1122,  1921,   142,   257,     0,  1985,  1986,   458,   159,  1989,
     451,  1546,   463,    61,   218,   219,   256,  1982,   367,   271,
    1142,  1175,   232,   200,  2078,    37,  1341,   199,  2647,   290,
     452,   501,   293,   497,   153,   823,   412,   413,   232,    92,
    1266,    89,    90,   476,   476,   321,   301,  1341,   307,   342,
     309,  1345,  2032,  1830,   115,   418,   370,  2037,   314,   177,
     200,   212,   351,   389,   353,  2421,   171,    70,   272,   561,
    1296,   994,   955,    70,   955,   340,    70,  1865,   282,   370,
     503,  1094,  2151,   335,   967,   968,   969,   446,   256,  1635,
     443,  2011,   445,   446,  1629,  1641,    39,   445,   446,   452,
     251,  1995,   253,   341,   452,   256,   989,    49,   457,   363,
     290,  1775,   504,   357,  1440,   266,   469,   347,  1782,   472,
     473,   469,   475,   241,  1836,   478,   479,   447,   225,  1355,
     274,  1756,   312,  1845,     9,   228,    70,   391,   468,  1152,
    1153,  1154,   252,  1822,    70,   309,  1825,    70,   402,   256,
     287,   468,  1165,  1166,   365,   353,   204,   411,   412,  1172,
     414,   415,     6,   516,   341,   256,   420,  1493,   516,  1833,
     113,   322,   402,  2153,   451,    50,   401,   452,   461,     6,
    2170,     9,  1498,   437,   232,   500,   370,   540,   541,  1112,
     462,   452,   540,   541,    34,   346,  1000,  1001,  1733,   453,
     504,   341,   357,  2257,  2258,   357,   451,   331,   441,   451,
       6,  1094,   349,   446,  1440,   308,   504,   316,  2183,   504,
     482,   331,   465,  1242,  1888,   436,   579,   504,   462,  1112,
     503,   579,   482,     9,  1560,  1118,   357,   504,   504,   504,
     504,     6,  1557,   592,   388,   598,   504,   446,   499,   354,
     599,   504,   504,  1479,   498,   376,   793,  2449,  2450,  1540,
     503,   515,  1145,  1557,   504,   416,  1492,  1493,  1814,  1152,
    1153,  1154,  1155,   321,   451,  2195,  1684,  1160,   497,   451,
     534,   505,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1571,  1174,  1175,  2187,   237,   644,   123,   650,  1624,  1651,
     554,   452,   556,  1597,  1530,   559,   560,   451,   562,   460,
     504,   451,   496,  1184,   504,  2235,   504,  2237,   501,   504,
    1855,  1204,  1750,  1204,   504,  1754,  1990,   504,  2107,  1348,
     451,   175,  2401,  2387,  1560,   589,   504,   212,   451,   503,
     594,   442,  2006,   498,  1227,   462,   498,   601,  2268,     6,
     468,   456,  2332,   504,   453,   453,  2336,  1892,   462,   510,
     503,   504,   172,  2027,   504,   464,   464,   460,   212,   244,
     245,   458,   576,  2375,  2053,  1601,   463,   498,  2298,  2299,
    1910,   256,  2434,   161,   212,   212,  1612,  1613,   153,     6,
    1616,   266,  2056,   503,   244,   398,  2060,   504,  1624,    26,
     497,   398,   606,   451,   398,   659,   188,   251,    33,   253,
     256,   828,   256,   762,  2618,   357,   212,   122,   767,   772,
     773,  2046,   266,  2048,   251,   203,   253,  1310,   256,   256,
    1756,   256,   781,   786,   376,  2099,   212,   244,   266,   266,
      30,   281,   282,   283,  2615,   448,   700,   212,   203,   703,
    1469,   448,   256,  1466,   448,   251,  1098,   253,  1100,   402,
     256,   234,  2087,   451,   398,  1759,  2446,  2447,   330,     9,
     266,   346,   398,   256,    64,   398,    66,  1119,   322,  1121,
     256,  1762,   200,     9,  1126,   308,   251,     0,   253,   232,
     266,   256,   216,   217,    22,   322,    49,   256,  1140,   170,
     256,   266,   346,  2049,   344,   129,   271,   256,   256,   451,
     256,   289,   236,    84,   448,  2140,   504,    57,   346,   346,
      61,   454,   448,   271,   458,   448,   322,   242,  2192,   463,
      64,    57,    66,  2068,  2198,  1111,  2456,  2457,   262,    38,
    2592,   416,   167,  2255,  2208,   257,  1861,    46,    89,    90,
     346,    57,  1433,   252,   225,   212,   498,   322,   956,   957,
     410,  1137,   233,   287,   161,   963,   262,  1861,  1862,   196,
     346,   504,   416,   321,    32,  1486,  1487,  1488,  1489,  1460,
     362,   346,   392,  1466,   450,   460,  1605,   346,   416,   416,
    1232,   287,  2122,   459,   251,   212,   253,   256,   376,   256,
     354,  2153,  1244,   410,  2392,    56,   341,   231,  1947,   266,
    1414,  2146,    63,   262,  2278,    56,   460,  2281,  2282,   446,
     416,   376,    63,   341,   397,   138,   466,   467,   387,   142,
    2294,   471,   460,   460,   251,   510,   253,   177,   287,   256,
     416,   503,   267,  1656,  2308,  2309,   317,  1000,  1001,   266,
     446,   416,   110,   503,  1246,   482,  1579,   416,   504,   503,
     504,  1010,   252,   169,   460,   322,   510,   291,   330,   384,
     329,  1554,   212,  1899,   138,   228,   504,   504,  2466,   504,
     423,   504,   510,   510,   460,   510,   212,   200,   262,   346,
     389,   232,   289,  2038,  2039,   460,  1579,   117,   118,   119,
     504,   241,   456,  2367,   232,   322,   125,   356,   504,  1285,
    2401,   783,   211,   287,   510,   241,   256,   223,   252,    26,
    2046,   504,  2048,   435,   218,   503,   266,   394,   357,   346,
     256,   274,   203,  1325,   510,  1754,  2515,  1660,  2054,   504,
     266,   331,  1095,   451,   243,   510,  1099,  2411,   504,   751,
     271,   510,   171,  1106,  1107,   504,   504,  1110,   504,   416,
    1113,  2087,   510,   270,   406,  1118,   265,  1120,  1651,  1122,
    1123,  1124,  1125,  1656,   406,  2067,   500,   212,     1,   503,
     321,  2209,   494,  2474,   262,  1361,   451,   157,    11,  1142,
    2106,  2085,   504,   776,   411,   256,   798,   331,   256,   416,
    2577,  1684,   501,   460,   463,   379,   346,   503,  2482,   256,
    2589,   308,   306,   199,  2140,     9,  1233,   268,   238,   318,
     346,   256,   329,  1221,   337,   474,  1667,   268,   341,  1471,
     292,   266,   252,   504,   476,    58,  2323,   212,   285,   286,
    2179,   503,   504,   460,   476,   388,   317,   504,   187,     9,
    2142,   170,    12,   510,   503,    15,    16,  2497,   841,  2497,
    2497,   231,   324,  2497,  1217,  2497,  1747,  1284,  2497,   498,
    2096,   210,   195,    96,   321,    98,   416,   100,  1789,   378,
     196,   256,   329,  2660,  1237,   108,   451,   504,    82,   340,
     416,   266,  1803,   510,   356,   967,   968,   969,   177,   340,
    2677,   422,  2690,   424,   107,    99,   225,   385,  2134,  2135,
     451,   346,  2512,   410,   233,   335,    56,   989,    56,    59,
     460,  1274,   292,    63,   127,    63,   406,   347,   468,   503,
     504,  1284,    28,   256,   460,  1352,   406,   323,   324,   546,
     256,   164,   468,     6,   450,   396,     9,    54,   285,  1953,
     401,   458,   458,   459,   340,   396,   463,   463,   237,   306,
     401,   240,  2452,   166,   504,    12,   394,  2259,    15,    16,
     510,   346,   451,  2573,   473,  1328,  1387,   584,   504,   476,
    1391,   416,    89,     8,   510,   188,  1578,  1398,  1341,  2441,
    2009,   338,  1345,   207,   208,   220,   476,   334,   317,   106,
     451,   204,  1327,  2490,  2491,   612,   476,   201,   394,   116,
     451,   358,    37,    47,  1895,  2241,   463,   437,   212,    82,
    1092,   171,  1094,   451,   171,  1097,  1379,   252,    62,  1101,
     126,  1379,   246,   247,   257,   262,    99,  1454,   481,  1645,
    1112,   416,   423,  2530,  1101,  2497,  1118,  2534,  2535,   112,
       8,  2377,  1377,  2379,   204,   256,   499,   204,   750,   751,
     287,  1414,   256,   504,   258,   259,   260,  1139,   102,  1141,
     264,  2561,   266,  1145,  2564,   510,   405,  1134,   301,    37,
    1152,  1153,  1154,  1155,  2029,   460,   287,  1440,  1160,  2012,
    1169,  1170,  1171,  1165,  1166,  1167,  1168,  1169,  1170,  1171,
    1172,  2168,  1174,  1175,  2449,  2450,   798,  2452,  2598,   303,
    1951,  2601,   448,   750,   751,  2543,   212,   277,   278,  2132,
      16,   411,   458,   262,  2005,   262,   351,   463,   268,   504,
     268,  1203,   453,     6,   359,   510,     9,    33,   201,   445,
    1493,   301,   302,   464,  2067,  1562,    42,  1113,   287,   212,
     287,   187,   346,   504,   187,  1227,   462,  1229,  1412,  1125,
     256,   798,  2501,  1417,  1418,   228,  1420,   390,   458,  1586,
     266,   232,  2398,   463,   210,   453,    49,   210,   394,   177,
      13,    14,   245,   377,   280,   212,   464,  1540,   251,   187,
     253,   248,   249,   256,  1611,   258,   259,   260,   232,    32,
     340,   264,   340,   266,  1557,   239,   449,  1560,   271,    82,
     433,   106,   210,  1710,    87,   458,   250,  1598,  1571,  2142,
     463,   116,   416,  1720,  1721,  1867,    99,  1724,   451,   256,
     277,   278,  2458,   405,   428,   429,  2462,  2463,  1310,   266,
     303,   455,   240,   457,  1597,   307,     2,   309,   212,  2132,
     346,     7,   448,   161,   301,   302,   396,   165,   396,   322,
    1332,   401,   458,   401,   555,   448,   460,   463,    57,   560,
    1191,  1624,   451,   449,  1195,   458,   470,  1626,  2590,  2591,
     463,   504,   458,   346,    96,    97,  1358,   463,   473,   156,
     475,   158,   256,   478,  1647,   351,   490,   353,   351,  1647,
     353,   495,   266,   485,   486,   487,   488,  2619,   502,   351,
     504,   353,   218,   451,   377,   451,   510,   351,   352,   346,
     416,   299,   300,   419,   420,   156,  2638,   158,   201,   252,
     451,   254,   366,   252,   368,   254,  2259,   451,   252,   212,
     254,  1690,  1648,  1649,  1650,    65,   173,    67,  1654,  1167,
    1168,  1657,  1658,   416,   451,  1609,  1428,    82,   485,   486,
     487,   488,  1711,   451,   504,   428,   429,   485,   486,   487,
     488,   967,   245,   969,    99,   504,  2157,  2689,   251,    68,
     253,   451,   346,   256,   504,   258,   259,   260,   504,   416,
     340,   264,   451,   266,  1466,  1153,  1154,   460,   271,  1752,
     451,   256,   256,  1756,   468,   199,  1759,   470,   400,  1762,
     504,  1665,  1666,   442,   510,    35,   401,   451,    38,   410,
      24,    25,  1676,    63,    59,    45,    46,   490,   256,  1683,
     303,   232,   495,   460,   451,   308,   328,   256,   401,   502,
      26,   504,   620,   621,   622,   623,  2088,   510,   229,   322,
    1867,   451,   416,   107,   504,   451,   451,   256,  1712,  1812,
     312,    65,   272,    67,   498,    69,   256,   454,    23,   102,
     451,    91,   437,   346,  1546,  2081,   201,   188,   122,   454,
      17,    86,  1554,   510,   357,   504,   272,   212,   351,   451,
     394,   401,    56,   402,   503,   423,   460,   262,  1570,   103,
     104,   105,  1919,    39,   377,   451,   237,  1579,  1861,  1862,
    1863,  1928,  1929,   402,   504,   331,   504,  1771,  1590,  1900,
    1901,  1902,  1903,  1904,  1905,  1906,  1907,   506,   419,    53,
      54,   256,   316,   258,   259,   260,  1790,   410,   310,   264,
     160,   266,  1796,   416,   394,   165,   510,  1619,   261,   153,
     451,   155,     7,   451,   394,   428,   429,  1629,   162,   255,
     504,   165,   503,   451,   451,    89,   366,   451,  1921,   189,
     394,   451,    85,    85,   124,   451,   394,    22,   303,  1651,
     389,   309,   106,   306,  1656,   451,   394,   460,   204,   504,
     451,   211,   116,  1946,   501,   232,   499,   470,  1946,   504,
     446,   384,  1674,   476,   504,   254,   218,   504,  1961,   446,
     442,   122,  1684,  1966,   462,    26,   510,   490,   400,   306,
     445,   346,   495,   410,  1696,   498,   447,  1699,   462,   502,
    1979,   504,  1985,  1986,   348,   504,  1989,   510,   442,   256,
     451,   376,   504,   336,   451,   265,   399,   114,   252,   462,
     254,   169,   377,    82,   187,   451,   462,   462,  2011,   462,
     462,  1733,   504,   256,   462,   462,     6,   271,   309,     9,
      99,  2088,   451,   451,   462,   446,   403,  1749,  1932,  2032,
    2097,   504,   462,   453,  2037,  2038,  2039,   504,    30,  2038,
    2039,   416,   130,  2046,   196,  2048,  1950,   131,   318,   446,
     132,   386,  2606,   428,   429,   133,   136,  2590,  2591,   504,
     134,   137,   135,   101,   462,  1969,   446,  1971,   140,   441,
     497,  1975,    49,   404,   445,   442,   445,   439,  2569,  1983,
     143,   196,  2085,   145,  2087,   460,  2619,   144,   146,   499,
     271,    31,    82,   147,    49,   470,   148,   196,   149,   112,
     150,   220,   151,   448,    94,  2638,   448,   448,   378,    99,
     448,   114,   448,   446,   448,   490,   312,   410,   109,   451,
     495,   391,   201,   446,   376,     1,   197,   502,   203,   504,
     223,   339,   256,  1855,  1856,   510,   272,  2140,   294,   231,
     298,   165,   501,   501,   484,   128,   175,   321,   365,   446,
    2153,   325,   326,   168,  2157,   129,  2689,   446,   228,  2157,
      49,   196,  1884,   228,    40,    41,    42,    43,    44,   299,
    1892,   204,    56,  2465,   204,   504,  2080,   256,   451,   258,
     259,   260,   272,   252,   165,   264,   423,   509,   508,   443,
     237,   299,   366,   276,   203,   783,   446,   446,  1920,    75,
      76,   380,   362,   473,   295,  1927,  1928,    30,   382,   383,
     203,   201,    17,   442,   203,   128,   139,   365,   446,    49,
     141,  2513,   212,   203,   303,  1947,     8,   196,   129,   501,
    1952,   423,  2235,   501,  2237,  1957,  1958,   203,   451,   493,
     446,    11,     9,     7,   504,   503,   294,   203,    49,   188,
     504,   297,   503,   498,   498,   245,   262,   291,   314,   461,
     313,   251,  2265,   253,   330,  2268,   256,  2265,   258,   259,
     260,   113,   436,    47,   264,   203,   266,   411,   203,   380,
     294,   271,   102,    49,   361,   237,   262,    95,    58,   296,
    2012,   492,   292,   361,    56,     8,  2299,    49,   377,   110,
     337,   456,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   262,   262,   303,   262,   109,  2319,   337,   451,   210,
     451,  2319,   481,   107,   221,   285,    96,   299,    98,  2332,
     100,   501,   322,  2336,   232,   367,  2058,   418,   108,   321,
       4,   119,   196,   337,   256,  2067,  2068,    49,   321,   428,
     429,     7,   306,    46,  2076,    19,   346,    92,   425,    26,
     201,   148,   127,   206,    75,    29,   221,   955,   238,   150,
     177,   410,   519,  2095,  2377,   469,  2379,  1866,   286,   967,
     968,   969,   425,  1009,   773,   497,  1418,   377,   740,  2587,
    2658,   470,  2395,  2297,   164,  1859,  2155,   788,  1957,    63,
    2564,   989,  2124,  2598,  2180,  2180,   841,  1018,  2051,  1200,
    2132,   490,  2704,   779,  1806,  1723,   495,  1722,  1758,  2361,
    2142,  1217,  1452,   502,  2146,   504,   416,  2049,  1454,  1479,
    2233,  1498,  2053,  1501,  1825,  2251,  2340,  1543,   428,   429,
    2344,  1550,  2076,  2446,  2447,  1305,  2449,  2450,  2170,  2452,
    2449,  2450,  1853,  2088,   330,  1310,   226,  2179,  1561,  2095,
    1879,  2109,  1929,  1908,  1591,  1339,  2135,   343,  1125,  1341,
     460,  1355,  1928,   783,  2302,  1928,  2647,  1639,  2307,  1530,
     470,  2401,   299,  2128,  1448,  1328,  2312,   257,  2128,  2128,
     152,  2128,  2214,   691,   270,  1895,  2400,   242,   745,  2523,
     490,   417,   972,  1183,   509,   495,  1094,  2389,   215,  2512,
    2065,  1099,   502,   449,   504,  1858,   705,   558,  1106,  1916,
     510,  2592,  1110,    -1,  1553,    -1,    -1,    -1,  2432,  2433,
      -1,   301,    -1,    -1,   304,    -1,  1124,  2259,    -1,    -1,
    2539,    -1,    -1,    -1,  2448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,  1145,    -1,    -1,
    2464,    -1,    -1,    -1,  1152,  1153,  1154,  1155,    -1,    -1,
    2573,    -1,  1160,    -1,    -1,    -1,    -1,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  2489,  1174,  1175,   252,    -1,
    2494,  2495,    -1,    -1,    -1,    -1,    -1,    -1,   262,   369,
      -1,  2323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2612,
    2514,    -1,    -1,    -1,    -1,  2614,  1204,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2542,    -1,
      -1,  2545,  2546,    -1,  2647,   415,    -1,   417,  2370,  1237,
      -1,   315,    -1,    -1,  2653,  2654,   320,   967,   968,   969,
      -1,    -1,    32,   433,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    35,    -1,    -1,    38,    46,    -1,  2681,   989,
      -1,  2585,    45,    46,    -1,    -1,  1274,   351,    -1,    -1,
      -1,  2413,    -1,    -1,  2693,   359,  1284,    -1,  2420,    -1,
      -1,  2423,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,   504,    -1,    -1,   401,     6,    -1,
     404,     9,    -1,    -1,  1332,    -1,    -1,    -1,   412,  2471,
      -1,    -1,    -1,  1341,    -1,    -1,    -1,  1345,    -1,   423,
      -1,    -1,    -1,  2485,    -1,    -1,    -1,    -1,  2490,  2491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2501,
      -1,    -1,    -1,  1093,  1094,    -1,    -1,   451,    -1,    -1,
     454,  1101,  1102,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,  1114,  1115,    -1,    -1,  2530,    -1,
      -1,    -1,  2534,  2535,    82,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,  1133,  1134,  2547,   189,    -1,   198,    -1,
      -1,    99,    -1,    -1,    -1,  1145,     6,    -1,    -1,     9,
    1428,   211,  1152,  1153,  1154,    -1,    -1,    -1,   211,    -1,
      -1,    -1,  1440,    -1,    -1,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,    -1,    -1,  1175,    -1,    -1,  2590,  2591,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,  1466,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,  2609,    -1,    -1,
      -1,    -1,    -1,   263,    -1,   265,    -1,  2619,  1208,    -1,
      -1,    -1,   265,    -1,    -1,  1493,    -1,    -1,    -1,  2631,
    2632,    -1,    82,    -1,    -1,    -1,  2638,    -1,   288,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    99,
      82,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,  2661,
      -1,  1251,    -1,    -1,   212,    -1,    -1,    99,   318,    -1,
      -1,    -1,    -1,    -1,    -1,   318,  1266,    -1,  1546,    45,
      -1,    -1,    -1,    -1,    -1,  2687,  1554,  2689,    -1,  1557,
      -1,    -1,  1560,    -1,    -1,   345,    -1,   245,    64,    65,
      66,    67,    -1,   251,    -1,   253,  1296,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,   371,    -1,   271,    -1,    -1,    -1,    -1,   378,  1597,
      -1,    -1,    82,    -1,    -1,   378,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,   395,    -1,    -1,   391,    99,
      -1,   201,    -1,    -1,    -1,   303,  1624,    -1,   190,    -1,
      -1,  1629,   212,    -1,    -1,  1355,    -1,    -1,    -1,   201,
    1360,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1651,    -1,    -1,    -1,    -1,  1656,    -1,
      -1,    -1,    -1,    -1,   444,   245,    -1,    -1,   346,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,   473,   256,    -1,   258,   259,   260,   377,
     473,    -1,   264,   483,    -1,    -1,    -1,    -1,    -1,   489,
     190,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
    1440,   201,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,   416,   235,
      -1,   303,   322,    -1,    -1,    -1,  1466,    -1,    -1,    -1,
     428,   429,    -1,    -1,  1752,    -1,   252,    -1,  1756,  1479,
      -1,  1759,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,
      -1,    -1,  1492,  1493,    -1,   453,   256,    -1,   258,   259,
     260,    -1,   460,    -1,   264,    -1,   464,    -1,    -1,   285,
      -1,    -1,   470,    -1,    -1,    -1,    -1,   377,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,
    1530,    -1,   490,   309,  1812,   377,    -1,   495,    -1,    -1,
      -1,    -1,    -1,   303,   502,    -1,   504,    -1,    -1,    -1,
      -1,   327,   510,    -1,  1554,    -1,   416,   333,    -1,    -1,
    1560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1855,  1856,    -1,
      -1,    -1,    -1,  1861,  1862,  1863,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,    -1,
     460,  1601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,  1612,  1613,  1892,    -1,  1616,   377,    -1,    -1,
      -1,    -1,    -1,    -1,  1624,    -1,    -1,    -1,   470,   405,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,   414,   481,
      -1,    -1,   502,  1921,   504,    -1,    -1,    -1,   490,    -1,
     510,    -1,    -1,   495,    -1,   431,  1656,   499,    -1,    -1,
     502,   503,   504,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,   439,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,    10,   472,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,
      -1,   481,   498,   499,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,  2011,    -1,   495,    51,    52,    -1,   499,
      -1,    -1,   502,   503,   504,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2046,    -1,
    2048,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2068,    -1,    -1,    -1,    -1,    -1,   111,    -1,  2076,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,  2085,    -1,  2087,
      -1,    -1,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,   168,  2132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2140,    -1,    -1,    -1,    -1,    -1,  2146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
     195,     3,    -1,     5,    -1,    -1,    -1,   202,    10,    -1,
     205,   206,    -1,    -1,    -1,    -1,    18,    -1,    -1,  1899,
     215,    -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,   224,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,   269,    -1,    -1,  2235,   273,  2237,
     275,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
     285,    -1,    -1,    -1,    -1,    -1,   291,   292,    -1,   294,
     295,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,   111,
    2268,    -1,    -1,    -1,    -1,    -1,   311,   119,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,   349,   350,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   360,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,
     375,    -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,
     385,    -1,    -1,   195,    -1,    -1,    -1,    -1,   393,    -1,
     202,    -1,    -1,   205,   206,    -1,    -1,    -1,   403,    -1,
      -1,    -1,    -1,   215,    -1,    -1,  2096,   412,    -1,  2377,
     222,  2379,   224,    -1,    -1,   227,   421,    -1,    -1,    -1,
      -1,   426,   427,    -1,    -1,   430,    -1,   432,    -1,    -1,
      -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2132,    -1,  2134,  2135,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,   273,    -1,   275,   469,    -1,    -1,    -1,    -1,    -1,
     475,    -1,    -1,   285,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,    -1,     5,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,   501,    -1,    -1,   311,
      18,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,   349,   350,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,   360,    -1,
      -1,  2241,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    -1,   381,
      88,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   403,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     412,   119,    -1,   121,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    -1,  2590,  2591,    -1,    -1,   438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
     168,  2619,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,
      -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,   480,    -1,
    2638,    -1,     1,    -1,     3,    -1,     5,   195,    -1,    -1,
      -1,    10,    -1,    -1,   202,    -1,    -1,   205,   206,    18,
      -1,    -1,    -1,    -1,    -1,   507,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,    -1,   224,    -1,  2398,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2689,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,   269,    -1,    -1,    -1,   273,    -1,   275,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,  2458,    -1,
      -1,    -1,  2462,  2463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,   311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   349,   350,    -1,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,
      -1,    -1,    -1,   381,    -1,    -1,   195,   385,    -1,    -1,
      -1,    -1,    -1,   202,    -1,   393,   205,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   403,   215,    -1,    -1,    -1,
      -1,    -1,    -1,   222,   412,   224,    -1,    -1,   227,    -1,
    2590,  2591,    -1,   421,    -1,    -1,    -1,    -1,   426,   427,
      -1,    -1,   430,    -1,   432,    -1,    -1,    -1,    -1,    -1,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2619,
      -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   273,    -1,   275,    -1,  2638,    -1,
      -1,   469,    -1,    -1,    -1,    -1,   285,   475,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    -1,
      -1,    -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,   507,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,  2689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,
      -1,    82,   381,    -1,    -1,    -1,   385,    -1,     3,    -1,
       5,    -1,    -1,    -1,   393,    10,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    18,   403,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,   426,   427,    -1,
      -1,   430,    -1,   432,    -1,    -1,    51,    52,    -1,   438,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    88,    -1,    -1,   475,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   119,    -1,   121,    -1,   507,    -1,
      -1,   212,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   163,    -1,
     251,    -1,   253,   168,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
     205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    -1,   303,    -1,    -1,    -1,    -1,   222,    -1,   224,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,    -1,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     285,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,    -1,    -1,   416,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,
     375,    -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,   470,
     385,    -1,    -1,    -1,    -1,    -1,   159,    -1,   393,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,   403,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,   412,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,   421,    -1,    -1,   510,
      -1,   426,   427,    -1,    -1,   430,    -1,   432,   201,    -1,
      -1,    -1,    -1,   438,   207,   208,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,
     475,    -1,   245,   246,   247,   480,    -1,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
       6,    -1,   507,     9,    -1,    -1,    12,    13,    14,    -1,
      -1,   284,    -1,    -1,    20,    -1,    -1,   290,    -1,    -1,
     293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,
     303,    -1,    -1,    -1,    -1,   308,    -1,    -1,     6,    -1,
     313,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,     6,    -1,
      -1,     9,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    82,   448,    -1,   450,    -1,   452,
      -1,    -1,   455,    -1,   457,   458,   459,   460,    -1,   462,
     463,    99,    -1,    -1,    -1,   201,    -1,   470,    -1,    -1,
      -1,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,   201,    -1,    -1,    -1,   510,    -1,   245,
     246,   247,    82,    -1,   212,   251,    -1,   253,    -1,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    99,
     266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   284,    -1,
      -1,    -1,    -1,   251,   290,   253,    -1,   293,   256,    -1,
     258,   259,   260,   201,    -1,   301,   264,   303,   266,    -1,
      -1,    -1,   308,   271,   212,    -1,     6,   313,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   332,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,   245,    -1,    -1,
     346,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,   322,    -1,   264,    -1,   266,    -1,
      -1,   201,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,   212,    -1,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   377,
     416,   251,    -1,   253,   322,    -1,   256,    -1,   258,   259,
     260,    -1,   428,   429,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    -1,    -1,     6,   346,    -1,
       9,    -1,   448,    -1,   450,    -1,   452,    -1,   416,   455,
      -1,   457,   458,   459,   460,    -1,   462,   463,    -1,    -1,
     428,   429,    -1,   303,   470,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,   460,    -1,    -1,    -1,   502,    -1,   504,    -1,
      -1,   201,   470,    -1,   510,    -1,   346,    -1,   416,    -1,
      -1,    -1,   212,    82,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      99,    -1,    -1,    -1,   502,    -1,   504,   377,   446,    -1,
      -1,    -1,   510,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,   460,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,   470,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,     6,    -1,    -1,     9,   416,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,   428,   429,
      -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     460,    -1,   322,    -1,    -1,    -1,    -1,   196,    -1,    -1,
     470,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,   346,    -1,    82,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,     6,    -1,    -1,
       9,    -1,   502,    -1,   504,    99,    -1,    -1,    -1,    -1,
     510,    -1,    -1,    -1,    -1,    -1,   245,   377,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,    82,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
     460,    -1,     6,    -1,    -1,     9,    -1,   201,    -1,    -1,
     470,    -1,    -1,    -1,    -1,    -1,    -1,   346,   212,    -1,
      -1,    -1,    -1,    -1,   484,     6,    -1,    -1,     9,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,   377,    -1,
     510,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    99,    -1,    -1,    -1,   428,
     429,    82,    -1,   212,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,   460,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   470,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,   346,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,   490,   271,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,   322,    -1,    -1,   410,    -1,    -1,    -1,
     201,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,   428,   429,    -1,   346,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,   245,    -1,   460,   271,   377,    -1,
     251,    -1,   253,    -1,    -1,   256,   470,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,   303,
      -1,   495,    -1,    -1,    -1,    -1,    -1,   416,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,   322,   428,
     429,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,   346,     1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,   377,    32,    -1,    -1,
      35,   510,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    64,
      -1,    66,    -1,    -1,    -1,   416,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,   119,    -1,   490,    -1,    -1,   470,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,   160,    -1,    -1,    -1,   510,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,    -1,   178,   179,   180,   181,   182,     1,    -1,
     185,   186,    -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,    -1,    -1,    -1,    21,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    36,   219,    -1,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,   232,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,   241,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      73,    -1,    75,    76,    77,    78,    79,    80,    81,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,
     345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,   175,    -1,    -1,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    -1,    -1,   371,    -1,    -1,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     395,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
     405,    -1,   407,   408,   409,    -1,    -1,    -1,    -1,   232,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   446,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,   473,    -1,
      -1,    -1,   477,   478,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   305,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,   497,   498,    -1,    -1,   319,    -1,    -1,   504,
      -1,    -1,    -1,    -1,   327,    -1,    21,   330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     343,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   405,    -1,   407,   408,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   477,   478,   479,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,   491,    -1,
     185,   186,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,
      -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    73,   241,    75,    76,    77,
      78,    79,    80,    81,    32,    -1,    -1,    35,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,    -1,    -1,    -1,    64,    -1,    66,    -1,
      -1,   119,    -1,    -1,    -1,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,
     178,   179,   180,   181,   182,    -1,    -1,   185,   186,    -1,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,    -1,    -1,   185,   186,    99,
     405,   189,   407,   408,   409,    -1,    -1,    -1,   196,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   434,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,
      -1,    -1,    -1,    -1,   232,    -1,   451,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   468,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   477,   478,   479,    -1,    -1,   265,    -1,    -1,
      -1,   319,    -1,    -1,    -1,    -1,   491,    -1,    -1,   277,
      -1,    -1,   330,   498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    82,   343,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,   305,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,
      -1,    -1,   330,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,   253,    -1,   343,   256,   345,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,   407,
     408,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,
     378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,    -1,   395,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,   407,
     408,   409,   322,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   477,
     478,   479,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,   446,    -1,
      -1,    -1,    -1,   451,    -1,    -1,    -1,   245,   456,    -1,
      -1,    -1,    99,   251,    -1,   253,    -1,   377,   256,    -1,
     258,   259,   260,    -1,    -1,   473,   264,    -1,   266,   477,
     478,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,   497,
     498,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,   448,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    82,
     460,    -1,   462,   463,    -1,    -1,    -1,    -1,   346,    -1,
     470,    -1,    -1,    -1,   201,    82,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
     490,    -1,    99,    -1,    -1,   495,    -1,    -1,    -1,   377,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,
     510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,    -1,   264,   416,   266,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     448,    -1,    -1,    -1,    -1,    -1,   303,    -1,   201,    -1,
     458,    -1,   460,    -1,   462,   463,    -1,    -1,    -1,   212,
      -1,    -1,   470,    -1,   201,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      82,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,   346,
      -1,    -1,   245,    -1,   502,    -1,   504,    99,   251,    -1,
     253,    -1,   510,   256,    -1,   258,   259,   260,   245,    -1,
      -1,   264,    -1,   266,   251,    -1,   253,    -1,    -1,   256,
     377,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   322,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,   448,    -1,   346,    -1,    -1,    -1,    -1,    -1,   201,
      82,   458,    -1,   460,    -1,   462,   463,    -1,    -1,   346,
     212,    -1,    -1,   470,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,    -1,    -1,   373,    -1,   495,    -1,
     377,    -1,    -1,   245,    -1,   502,    -1,   504,    -1,   251,
      -1,   253,    -1,   510,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,   416,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,    -1,   458,    -1,   460,    -1,   462,
     463,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,   201,
     322,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,   470,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,   346,    -1,    -1,   484,    -1,   502,
      -1,   504,    -1,   490,    -1,    -1,    -1,   510,   495,    -1,
      -1,    -1,    -1,   245,    -1,   502,    -1,   504,    -1,   251,
      -1,   253,    -1,   510,   256,   377,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,
     462,    -1,    -1,    -1,   346,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,    -1,    -1,   495,    -1,   377,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510
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
     603,   535,   523,   451,   232,   537,  1269,   504,  1190,  1190,
     423,   405,  1287,  1269,  1269,  1269,   394,  1190,   405,   451,
     451,  1269,   451,   451,    57,  1258,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1269,  1269,  1269,   504,  1185,  1216,
      68,  1185,   451,  1269,  1269,   549,   560,  1185,   545,   504,
     587,   588,   589,  1191,   256,   307,   309,   573,   575,  1037,
    1219,  1269,   451,   504,   451,   606,   539,   340,  1284,  1269,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1222,
    1185,   256,   218,   306,  1307,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1257,  1317,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1191,  1270,  1037,   232,   423,  1281,  1269,
      96,  1190,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1300,  1216,   400,   401,   410,
      63,  1269,   451,   552,   451,   504,   551,    59,  1269,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1300,   256,
     590,  1220,  1281,   232,  1190,  1190,   574,   575,   451,     1,
     290,   312,  1243,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1222,   328,  1269,   401,  1219,   451,  1269,
     504,  1186,   229,    26,   565,   229,   370,   451,   451,   107,
    1220,  1190,   451,   312,  1190,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1219,   257,   435,
     494,   557,  1186,   256,   272,   608,   454,  1261,    23,  1252,
     102,   648,   451,   582,   583,    57,   505,  1311,   609,   437,
    1293,   188,  1262,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1285,  1301,    86,  1259,   504,  1175,  1176,   451,   394,   650,
     583,   272,  1276,   351,  1285,   446,   497,  1297,   401,   402,
    1269,  1257,   113,   237,  1271,  1271,   287,   635,  1219,  1300,
     423,   262,    39,  1255,  1269,   645,   646,  1176,  1176,   451,
     172,   392,   530,   651,   652,   654,  1269,  1271,   125,   171,
     614,   359,   628,  1269,  1269,  1269,  1269,  1252,     9,   287,
     349,   637,  1269,  1276,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1176,   125,   347,   402,   618,  1269,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1185,  1189,   419,   632,  1185,  1185,   316,  1282,  1282,
     310,  1185,  1269,  1219,   394,   261,   732,   683,   684,   686,
     696,  1235,   451,   653,   632,   256,   616,  1216,   616,     7,
     616,   616,   256,   615,  1216,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1237,  1316,  1261,
    1269,  1184,  1185,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1269,   124,  1184,
    1185,   262,   385,   681,   733,   451,   394,   389,   788,   698,
     689,  1269,  1259,  1269,   351,   353,  1312,  1312,  1269,  1259,
    1269,  1276,  1269,    22,  1251,   306,   678,  1190,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1269,
    1289,    26,   196,   697,  1253,   204,  1219,   504,  1269,  1251,
     504,  1187,  1188,   308,   418,  1308,  1189,  1219,   499,  1269,
     174,   213,   504,   665,  1190,   274,   351,   353,  1310,   681,
     737,   451,   337,   802,   805,   244,   301,   406,   476,  1288,
     476,  1288,   476,  1288,   476,  1288,   476,  1288,   501,  1298,
     384,  1286,  1219,  1213,  1216,  1216,   232,   242,   384,  1272,
    1269,  1270,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1223,
    1224,  1225,   446,   662,  1188,   254,  1275,   446,  1258,   218,
    1264,   504,  1269,  1269,  1310,   738,   789,   122,   828,   829,
     510,   446,   713,   462,  1217,  1218,   442,   706,   727,   728,
    1223,    26,   702,   400,  1247,  1247,  1225,   306,  1279,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1213,   691,   447,  1219,    57,   353,   658,   669,  1219,
     410,  1290,   256,   666,  1216,   666,   348,   739,   686,   696,
     790,   791,   792,    55,   497,   806,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   830,   831,
     846,   851,   855,   860,   875,   878,   882,   886,   887,   888,
     893,   907,   911,   914,   928,   931,   934,   937,   941,   942,
     946,   956,   959,   976,   978,   981,   985,   991,  1003,  1011,
    1012,  1015,  1016,  1020,  1025,  1026,  1034,  1049,  1059,  1068,
    1073,  1080,  1084,  1086,  1089,  1092,  1096,  1121,   830,  1219,
     445,  1295,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1163,  1165,  1166,  1167,  1168,  1169,
    1170,  1198,  1212,  1213,  1224,  1226,  1227,  1228,  1229,   462,
    1218,  1216,   726,   728,   442,   256,  1257,   691,   451,  1225,
      48,   465,   670,   671,   672,   673,  1300,  1258,   196,   661,
    1263,   504,  1177,     1,   687,   792,   451,   808,   807,   376,
     814,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1248,   832,   847,   852,   856,   861,   876,   879,   883,
     889,   894,   908,   912,   915,   929,   932,   935,   938,   943,
     947,   957,   960,   977,   979,   982,   399,   986,   992,  1004,
    1013,  1017,  1021,  1027,  1035,  1050,  1060,   256,   346,   387,
     416,   510,  1072,  1074,  1081,   336,  1085,  1087,   817,  1090,
    1093,  1097,  1122,   114,   714,   462,  1231,  1213,  1224,  1226,
    1307,  1307,   462,   462,   462,   462,  1307,  1169,  1165,  1169,
     462,  1231,    70,   398,   448,  1164,   449,   458,   463,   450,
     459,   169,   462,  1230,   462,   462,  1165,   501,   729,  1299,
    1223,  1189,  1189,   187,   662,  1219,   740,   451,   793,   451,
      49,   809,   810,   811,  1256,   809,   504,   451,   308,   833,
     834,  1212,     6,    94,   245,   271,   848,  1170,  1194,  1195,
    1212,  1223,  1226,   853,  1165,  1212,   256,   857,   858,  1181,
    1182,  1183,  1216,   271,   422,   424,   862,   863,   256,   877,
    1203,  1212,   880,  1176,     6,   884,  1170,  1171,  1172,  1193,
    1214,  1215,  1216,  1224,   454,   890,  1176,   256,   895,   896,
     898,  1194,  1195,  1203,  1212,   909,  1195,   256,   913,   453,
     464,   916,   917,   918,  1153,  1154,  1155,   199,   323,   324,
     340,   394,   930,   933,  1192,  1193,   936,  1216,   446,   939,
    1296,  1152,  1153,   948,  1192,   958,  1177,   961,   962,  1212,
    1223,  1226,  1051,  1210,  1211,  1216,    94,   980,  1195,   983,
    1195,   170,   225,   233,   317,   987,   988,   190,   256,   993,
     997,   998,   999,  1181,  1204,  1212,  1216,  1226,  1300,  1005,
    1176,  1014,  1173,  1216,  1018,  1176,  1022,  1173,     9,  1028,
    1174,  1216,   153,   271,  1036,  1039,  1040,  1043,  1044,  1045,
    1046,  1047,  1048,  1178,  1179,  1192,  1209,  1211,  1216,  1051,
    1061,  1176,  1069,   112,  1075,  1076,  1077,  1195,    94,  1082,
    1194,  1088,  1177,   451,   504,   818,   819,   822,   823,   828,
    1091,  1212,  1094,  1176,  1098,  1212,  1123,  1173,   309,  1280,
     715,   716,   448,  1163,  1165,   504,   504,  1165,  1234,  1234,
    1234,  1197,  1212,  1224,  1226,  1233,   504,   448,  1197,  1232,
    1165,   448,  1165,  1166,  1166,  1167,  1167,  1167,  1165,  1197,
    1163,   403,   453,    30,  1254,  1258,     1,   741,   794,   810,
     410,   476,   812,   357,   498,   803,   130,   845,    30,   836,
     837,  1254,   196,  1279,  1212,  1213,  1224,  1226,   131,   850,
     446,   849,  1195,    57,   223,  1238,   858,   446,  1307,   132,
     874,   256,  1204,  1203,  1176,   356,   474,   881,  1300,  1313,
    1279,   133,   885,   159,   452,  1172,  1304,   386,  1244,  1217,
    1218,   891,  1176,   134,   892,  1285,   135,   906,   165,   897,
    1132,  1133,   484,   899,   503,   837,   485,   486,   487,   488,
     136,   910,    49,   228,   497,   864,   137,   927,    17,   501,
     919,   920,   921,   923,    12,    13,    14,    20,   159,   169,
     207,   208,   246,   247,   284,   290,   293,   301,   308,   313,
     332,   448,   450,   452,   455,   457,   458,   459,   462,   463,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1195,   101,  1193,
    1180,   441,  1294,   949,  1300,  1177,    92,   365,   436,   963,
     964,   966,   967,  1053,   462,  1217,  1195,   446,   140,   984,
      49,   988,   404,   989,   998,   141,   451,   994,   996,   481,
     499,   442,   445,   439,   143,  1010,   285,   334,  1241,   196,
    1124,   144,  1019,  1285,   145,  1024,  1124,  1174,   146,  1033,
     499,  1029,  1201,  1212,  1224,  1046,  1048,  1192,   446,  1179,
     123,   446,   482,  1038,    31,  1217,   147,  1067,   177,   237,
     240,  1063,   203,   376,  1070,  1300,  1256,   148,  1079,   228,
    1077,  1212,   149,  1083,   196,  1177,   394,   451,   451,   196,
     351,   353,  1095,   150,  1107,   112,  1099,   151,  1128,  1124,
    1185,   220,   718,    27,   115,   717,   448,  1164,   448,   448,
     448,  1164,   448,  1164,   448,   448,   449,   448,   448,   446,
    1269,  1189,   114,   660,   451,    61,    89,    90,   321,   451,
     742,   743,   748,  1269,  1325,    32,    35,    38,    45,    46,
      64,    66,   160,   189,   196,   198,   211,   243,   252,   265,
     305,   318,   345,   371,   378,   395,   446,   456,   473,   497,
     704,   705,   709,   721,   723,   725,   795,   800,   801,  1269,
    1302,  1269,   410,   312,   813,   109,   815,  1201,   197,   840,
     252,   331,   838,   839,  1302,    24,    25,    65,    67,    69,
     103,   104,   105,   153,   155,   162,   165,   252,   254,   443,
     493,   504,   835,  1179,  1303,   152,   340,  1199,  1213,   446,
       6,  1170,  1171,  1195,  1216,  1224,   203,   223,  1239,   376,
     854,   339,   859,  1183,   864,   881,   262,   287,  1262,  1213,
    1165,   272,  1245,  1218,  1176,   231,  1148,  1149,   825,   826,
     898,  1195,   294,  1134,    96,   335,   504,  1179,   298,   903,
      35,    38,    45,    46,    91,   160,   189,   211,   265,   318,
     378,   391,   473,   904,   905,   484,   900,  1132,  1132,  1132,
    1132,  1195,  1171,  1195,   865,   918,    21,   453,   464,   924,
     925,  1154,   501,   921,   922,   501,   825,  1296,   232,  1157,
     114,   940,  1181,   128,   825,   944,     9,    12,    15,    16,
     277,   278,   301,   302,   950,   954,   175,  1201,     9,    57,
     177,   241,   468,   970,   971,   972,   965,   966,  1055,  1280,
    1316,   446,  1192,  1171,  1195,   989,  1300,  1175,   825,   168,
    1000,  1152,  1001,  1002,  1212,  1181,     8,    37,  1126,  1285,
    1208,  1212,  1223,  1226,   228,  1006,  1023,  1300,   129,  1030,
    1212,  1030,   446,   446,  1037,   152,   453,   464,  1195,    49,
      38,    46,   211,   243,   265,   318,   378,   473,  1041,  1042,
    1269,  1062,  1300,  1195,  1195,   161,   289,   410,  1195,  1212,
     196,  1171,  1195,   824,  1219,  1201,  1256,   228,  1102,  1125,
    1126,  1256,  1271,  1185,  1230,  1230,  1230,  1197,   241,   468,
    1230,   448,  1165,  1230,  1230,  1223,  1280,  1269,  1269,  1251,
     248,   249,  1274,   758,   204,   176,   744,   745,   746,   747,
    1212,  1269,   252,   389,   156,   158,  1269,  1204,   299,  1277,
    1219,    56,  1212,  1212,   204,  1277,    32,   110,  1219,  1269,
     504,   451,   804,   272,   841,  1277,  1277,   839,   838,  1277,
     165,  1129,  1130,   509,   508,  1201,  1129,   237,   423,   299,
     276,   256,  1200,  1213,  1212,  1279,   411,  1135,  1136,  1217,
    1218,  1171,   446,  1240,   854,  1193,   446,  1181,   203,   376,
     869,   870,   380,   362,  1135,  1269,   825,   295,  1150,   827,
     825,  1132,  1269,   252,   389,   156,   158,  1269,   123,   482,
     905,  1132,    96,    97,   901,   841,   203,  1135,   203,   866,
     867,   868,  1256,    17,   442,   926,   316,   924,  1280,   825,
     128,   139,   945,  1296,   365,   951,  1296,   446,    49,   971,
     973,  1201,     9,    57,   241,   468,   968,   969,  1201,  1056,
    1301,   717,   218,   314,  1265,  1192,  1135,   203,  1175,   637,
     379,   990,  1300,   141,   995,     8,   196,  1006,  1212,   129,
    1141,  1143,  1148,   262,   287,   825,   501,   501,  1031,  1032,
    1201,  1200,  1195,  1037,  1037,  1037,  1037,  1037,  1037,  1037,
    1037,  1042,   290,   293,  1064,  1065,  1066,  1158,  1242,  1148,
     244,   410,  1315,   423,  1292,  1292,  1078,  1300,  1212,  1135,
     203,   451,   446,     9,  1100,  1101,  1236,  1103,  1212,  1078,
    1103,  1023,     7,  1249,   504,   719,   720,  1269,   448,  1185,
    1203,  1269,  1251,   256,   749,   750,  1212,  1221,   686,   759,
     746,   747,   510,  1205,  1209,  1219,  1205,  1269,  1295,  1269,
    1269,    32,  1219,   816,   817,  1269,   503,   842,  1205,  1205,
    1205,   825,   294,  1131,  1129,  1244,  1213,   825,   297,  1137,
    1218,  1135,  1202,  1212,  1223,   165,   461,   872,  1306,     6,
     228,   308,   460,   871,  1268,    34,   281,   282,   283,   344,
     466,   467,   471,  1246,   825,   828,  1205,  1205,  1151,  1207,
    1209,  1219,  1151,   503,   902,  1171,  1172,  1171,  1172,   867,
     308,   812,    87,   357,   498,   925,  1153,   825,  1212,   825,
     498,   952,   953,   954,   955,  1294,   498,  1202,  1201,    49,
     974,   969,   188,   974,  1052,  1269,  1271,   314,  1171,   990,
     262,   287,  1002,  1195,   217,  1007,  1300,   825,   291,  1144,
     262,  1153,  1152,  1031,  1158,  1212,  1159,  1160,  1161,  1162,
    1165,  1071,  1195,  1071,   461,  1138,  1139,   330,  1244,  1171,
     820,  1202,   313,  1201,   113,  1104,   436,  1106,   157,   292,
    1127,  1145,  1146,  1147,  1148,   321,  1179,  1205,   720,  1184,
     751,   252,   254,  1309,   504,   687,   270,   329,   458,   463,
     796,   797,   798,  1203,   796,   797,   799,   817,    47,    32,
      35,    38,    46,    91,   189,   198,   211,   243,   263,   265,
     288,   318,   345,   371,   378,   391,   395,   444,   473,   483,
     489,   843,   844,  1129,   825,  1135,   825,   294,   873,   825,
    1279,  1212,   252,   254,  1314,   904,  1135,   361,  1135,   361,
    1195,   953,   102,  1260,  1296,   974,   974,  1202,     8,    37,
     975,   225,   497,  1057,  1185,  1054,  1135,   380,    49,   262,
     237,  1008,   216,   236,   262,   287,   500,   825,   825,   825,
     825,   296,  1140,  1269,  1135,  1135,   492,   821,  1108,  1101,
    1264,    95,  1105,  1264,  1138,   825,   825,  1147,   252,   254,
    1273,   177,   187,   210,   240,   752,   753,   754,   755,   756,
     757,   750,   760,  1205,  1205,   129,  1269,  1269,    56,   123,
     482,     8,  1250,   844,   825,  1212,  1172,  1172,    49,   110,
     974,   456,  1267,  1267,   337,  1175,   203,   317,  1058,  1216,
    1195,  1269,  1009,  1142,  1143,  1144,  1148,   262,   262,   262,
     825,  1212,  1109,   451,  1212,  1264,  1212,   106,   116,  1318,
    1269,  1269,    54,    89,  1318,  1319,  1303,   761,   109,  1205,
    1205,  1269,  1151,  1151,  1206,  1209,  1221,  1135,  1135,  1195,
    1195,  1195,  1269,  1175,   337,   481,  1212,  1144,   127,   166,
     204,  1110,  1111,  1112,  1114,  1118,  1119,  1120,  1262,  1212,
    1269,   750,   750,   210,  1269,  1269,   209,   252,   285,   305,
     309,   333,   414,   431,   451,   472,   491,   499,   704,   709,
     710,   721,   723,   725,   762,   763,   767,   770,   773,   774,
     775,   776,   781,   782,   783,   785,   786,   787,  1302,  1303,
     451,  1203,   997,  1269,  1152,    37,  1250,   107,   750,   750,
     750,   221,  1266,   299,   779,   209,   321,  1219,   285,   501,
    1269,  1279,  1269,  1269,  1212,   329,   463,   777,   778,   780,
    1221,   778,   784,  1221,   299,   300,  1278,  1251,   997,   367,
     418,  1291,  1280,   232,  1269,   713,   321,  1152,  1198,  1196,
    1198,    53,    89,   321,   325,   326,   366,   382,   383,   764,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,   119,   196,   780,
    1221,  1270,  1212,   161,   165,  1305,     9,  1115,  1116,  1182,
     285,   286,   321,   329,   463,   768,   769,  1219,  1295,  1244,
     373,   484,   771,  1198,   187,   187,   210,   187,   210,   176,
     765,  1212,   176,   766,  1212,  1198,   337,  1283,   306,   338,
     358,  1117,  1116,   321,  1219,  1219,   714,  1280,  1212,    49,
    1280,   306,  1216,   425,   711,   176,   772,  1212,  1198,   170,
     225,   233,   317,  1113,  1175,  1219
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
#line 1342 "parser.y"
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
#line 1353 "parser.y"
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
#line 1389 "parser.y"
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
#line 1444 "parser.y"
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
#line 1473 "parser.y"
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
#line 1506 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1512 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1524 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 1534 "parser.y"
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
#line 1565 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1572 "parser.y"
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
#line 1611 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1612 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1621 "parser.y"
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
#line 1630 "parser.y"
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
#line 1644 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1648 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1658 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1667 "parser.y"
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
#line 1692 "parser.y"
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
#line 1710 "parser.y"
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
#line 1723 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1752 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1759 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1766 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1773 "parser.y"
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
#line 1784 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1788 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1792 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1796 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1810 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1815 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1823 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1835 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1839 "parser.y"
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
#line 1860 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1864 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1871 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1876 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1887 "parser.y"
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
#line 1901 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1932 "parser.y"
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
#line 1951 "parser.y"
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
#line 1961 "parser.y"
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
#line 1974 "parser.y"
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
#line 1990 "parser.y"
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
#line 2000 "parser.y"
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
#line 2015 "parser.y"
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
#line 2028 "parser.y"
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
#line 2039 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2045 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2051 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2057 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2063 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2069 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2079 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2083 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2090 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2094 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2098 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2102 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2109 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 2113 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2119 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2120 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2121 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2122 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2123 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2124 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2132 "parser.y"
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
#line 2146 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 2150 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 2158 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 2165 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 2169 "parser.y"
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
#line 2180 "parser.y"
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
#line 2200 "parser.y"
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
#line 2208 "parser.y"
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
#line 2218 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2219 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 2226 "parser.y"
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
#line 2246 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2247 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2252 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2256 "parser.y"
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
#line 2277 "parser.y"
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
#line 2300 "parser.y"
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
#line 2381 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2385 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2394 "parser.y"
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
#line 2413 "parser.y"
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
#line 2429 "parser.y"
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
#line 2447 "parser.y"
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
#line 2465 "parser.y"
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
#line 2482 "parser.y"
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
#line 2499 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2507 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2516 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2531 "parser.y"
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
#line 2548 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2552 "parser.y"
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
#line 2586 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2592 "parser.y"
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
#line 2602 "parser.y"
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
#line 2615 "parser.y"
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
#line 2628 "parser.y"
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
#line 2651 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2658 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2671 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2683 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2690 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2691 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2692 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2700 "parser.y"
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
#line 2727 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2738 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2753 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2761 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2766 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2771 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2780 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2784 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2800 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2805 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2810 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2815 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2826 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2837 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2847 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2854 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2855 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2856 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2863 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2874 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2888 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2895 "parser.y"
    { (yyval) = NULL; }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2896 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2897 "parser.y"
    { (yyval) = NULL; }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2906 "parser.y"
    {
	yyerrok;
  }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2925 "parser.y"
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
#line 2952 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2953 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2954 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2955 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 2962 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2967 "parser.y"
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
#line 2994 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3003 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 3017 "parser.y"
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
#line 3036 "parser.y"
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
#line 3053 "parser.y"
    {
	yyerrok;
  }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3060 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3064 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3075 "parser.y"
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
#line 3085 "parser.y"
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
#line 3115 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 3128 "parser.y"
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
#line 3148 "parser.y"
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
#line 3183 "parser.y"
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
#line 3214 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 3220 "parser.y"
    { (yyval) = NULL; }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 3221 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 3225 "parser.y"
    { (yyval) = NULL; }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 3226 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3234 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3245 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3250 "parser.y"
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
#line 3273 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3285 "parser.y"
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
#line 3313 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 3320 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 3327 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3336 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3348 "parser.y"
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
#line 3400 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3420 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3432 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 3475 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 3481 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 3490 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 3493 "parser.y"
    {
	current_field = NULL;
	control_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 3500 "parser.y"
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
#line 3520 "parser.y"
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
#line 3535 "parser.y"
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
#line 3555 "parser.y"
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
#line 3568 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3575 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 3581 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 3587 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 3596 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 3605 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 3609 "parser.y"
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
#line 3620 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 3621 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 3622 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 3623 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3628 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3632 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3636 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3640 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3644 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 3648 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 3652 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 3656 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 3660 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 3664 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 3668 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 3672 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 3676 "parser.y"
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
#line 3708 "parser.y"
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
#line 3734 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 3738 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 3746 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3752 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 3780 "parser.y"
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
#line 3804 "parser.y"
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
#line 3831 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 3835 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 3844 "parser.y"
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
#line 3869 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 3885 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 3889 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 3893 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 3897 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 3901 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3905 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 3909 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 3913 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 3917 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 3921 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 3925 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 3929 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 3933 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 3938 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 3943 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 3947 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 3951 "parser.y"
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
#line 3959 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 3963 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 3967 "parser.y"
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
#line 3975 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 3979 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 3983 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 3987 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 3991 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 3995 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 3999 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 4003 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 4007 "parser.y"
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
#line 4015 "parser.y"
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
#line 4023 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 4027 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 4031 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 4035 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 4039 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 4043 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 4063 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 4069 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 4082 "parser.y"
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
#line 4100 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 4110 "parser.y"
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
#line 4132 "parser.y"
    { (yyval) = NULL; }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 4133 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 4138 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 4145 "parser.y"
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
#line 4168 "parser.y"
    { (yyval) = NULL; }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 4171 "parser.y"
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
#line 4186 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 4187 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 4192 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 4198 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 4200 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 4205 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 4216 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 4227 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 4238 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 4249 "parser.y"
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
#line 4277 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 4285 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 4286 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 4290 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 4291 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 4296 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 4309 "parser.y"
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
#line 4322 "parser.y"
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
#line 4343 "parser.y"
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
#line 4352 "parser.y"
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
#line 4367 "parser.y"
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
#line 4376 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 4388 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 4394 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 4405 "parser.y"
    {
	header_check |= COBC_HD_REPORT_SECTION;
	current_storage = CB_STORAGE_REPORT;
	description_field = NULL;
	current_program->flag_report = 1;
	cb_clear_real_field ();
  }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 4423 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_field = NULL;
		control_field = NULL;
		description_field = NULL;
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 4436 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 4454 "parser.y"
    {
	yyerrok;
  }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 4461 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	current_report->global = 1;
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 4467 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 4478 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 4491 "parser.y"
    {
      current_report->control_final = 1;
  }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 4503 "parser.y"
    {
	/* Add field to current control list */
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), current_report->controls);
  }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 4514 "parser.y"
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
		if (current_report->t_last_detail) {
			current_report->t_last_control = current_report->t_last_detail;
		} else if (current_report->t_footing) {
			current_report->t_last_control = current_report->t_footing;
		} else if(current_report->t_lines) {
			current_report->t_last_control = current_report->t_lines;
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
	if(current_report->heading > 0
	&& current_report->first_detail > 0
	&& current_report->last_control > 0
	&& current_report->last_detail > 0
	&& current_report->footing > 0) {
		if (current_report->heading > current_report->first_detail ||
		    current_report->first_detail > current_report->last_control ||
		    current_report->last_control > current_report->last_detail ||
		    current_report->last_detail > current_report->footing) {
			cb_error (_("Invalid PAGE clause"));
		}
	}
  }
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 4564 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(1) - (1)]))) {
		current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
	} else {
		current_report->t_lines = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 4572 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(1) - (2)]))) {
		current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
	} else {
		current_report->t_lines = (yyvsp[(1) - (2)]);
	}
  }
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 4580 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(1) - (4)]))) {
		current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	} else {
		current_report->t_lines = (yyvsp[(1) - (4)]);
	}
	if (CB_LITERAL_P ((yyvsp[(3) - (4)]))) {
		current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
	} else {
		current_report->t_columns = (yyvsp[(3) - (4)]);
	}
  }
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 4614 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(3) - (3)]))) {
		current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
	} else {
		current_report->t_heading = (yyvsp[(3) - (3)]);
	}
  }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 4625 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(4) - (4)]))) {
		current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
	} else {
		current_report->t_first_detail = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 4636 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(4) - (4)]))) {
		current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
	} else {
		current_report->t_last_control = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 4647 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(4) - (4)]))) {
		current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
	} else {
		current_report->t_last_detail = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 4658 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(3) - (3)]))) {
		current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
	} else {
		current_report->t_footing = (yyvsp[(3) - (3)]);
	}
  }
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 4673 "parser.y"
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

  case 556:

/* Line 1806 of yacc.c  */
#line 4719 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 4726 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_HEADING;
  }
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 4730 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_PAGE_HEADING;
  }
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 4736 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_DETAIL;
  }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 4740 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_PAGE_FOOTING;
  }
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 4744 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_FOOTING;
  }
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 4750 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING;
  }
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 4754 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING;
      current_field->report_control = (yyvsp[(1) - (1)]);
  }
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 4759 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING_FINAL;
  }
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 4765 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING;
  }
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 4769 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING;
      current_field->report_control = (yyvsp[(1) - (1)]);
  }
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 4774 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING_FINAL;
  }
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 4781 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 4788 "parser.y"
    {
	if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign > 0) {
		current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
	} else {
		current_field->report_flag |= COB_REPORT_NEXT_GROUP_LINE;
	}
	current_field->next_group_line = cb_get_int((yyvsp[(1) - (1)]));
  }
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 4797 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
      current_field->next_group_line = cb_get_int((yyvsp[(2) - (2)]));
  }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 4802 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
      current_field->next_group_line = cb_get_int((yyvsp[(2) - (2)]));
  }
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 4807 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PAGE;
  }
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 4821 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
	current_field->report_sum_list = (yyvsp[(3) - (4)]);
	build_sum_counter( current_report, current_field);
  }
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 4831 "parser.y"
    {
      current_field->report_sum_upon = (yyvsp[(2) - (2)]);
  }
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 4838 "parser.y"
    {
      current_field->report_reset = (yyvsp[(1) - (1)]);
  }
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 4842 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_RESET_FINAL;
  }
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 4849 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
	current_field->report_when = (yyvsp[(3) - (3)]);
  }
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 4861 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
	current_field->report_flag |= COB_REPORT_LINE;
  }
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 4874 "parser.y"
    {
	current_field->report_flag |= COB_REPORT_LINE_PLUS;
  }
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 4891 "parser.y"
    {
	current_field->report_line = cb_get_int((yyvsp[(1) - (1)]));
	if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign > 0) {
		current_field->report_flag |= COB_REPORT_LINE_PLUS;
	}
  }
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 4901 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_LINE_NEXT_PAGE;
  }
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 4905 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_LINE_NEXT_PAGE;
  }
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 4912 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 4924 "parser.y"
    {
	current_field->report_column = cb_get_int ((yyvsp[(2) - (2)]));
	current_field->report_flag |= COB_REPORT_COLUMN_PLUS;
  }
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 4929 "parser.y"
    {
	current_field->report_column = cb_get_int ((yyvsp[(1) - (1)]));
	if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign > 0) {
		current_field->report_flag |= COB_REPORT_COLUMN_PLUS;
	}
  }
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 4939 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
	current_field->report_source = (yyvsp[(3) - (4)]);
  }
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 4947 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
	current_field->report_flag |= COB_REPORT_GROUP_INDICATE;
  }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 4955 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 4964 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 4971 "parser.y"
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

  case 615:

/* Line 1806 of yacc.c  */
#line 4996 "parser.y"
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

  case 616:

/* Line 1806 of yacc.c  */
#line 5027 "parser.y"
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

  case 617:

/* Line 1806 of yacc.c  */
#line 5053 "parser.y"
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

  case 620:

/* Line 1806 of yacc.c  */
#line 5076 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 5080 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 5084 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 5088 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 5092 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 5096 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 5100 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 5104 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 628:

/* Line 1806 of yacc.c  */
#line 5108 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 5112 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 5116 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 5120 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 5124 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 5128 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 5132 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 5136 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 5140 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 5145 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 5149 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 5153 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 5158 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 5163 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 5168 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 5181 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 5188 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 5193 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 5212 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 5216 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 5220 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 5227 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 5231 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 5235 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 5243 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 5254 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 5263 "parser.y"
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

  case 668:

/* Line 1806 of yacc.c  */
#line 5273 "parser.y"
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

  case 669:

/* Line 1806 of yacc.c  */
#line 5285 "parser.y"
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

  case 670:

/* Line 1806 of yacc.c  */
#line 5300 "parser.y"
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

  case 672:

/* Line 1806 of yacc.c  */
#line 5333 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 5337 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 674:

/* Line 1806 of yacc.c  */
#line 5342 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 5350 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 5359 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 677:

/* Line 1806 of yacc.c  */
#line 5369 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 678:

/* Line 1806 of yacc.c  */
#line 5371 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 679:

/* Line 1806 of yacc.c  */
#line 5376 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 681:

/* Line 1806 of yacc.c  */
#line 5385 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 682:

/* Line 1806 of yacc.c  */
#line 5389 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 684:

/* Line 1806 of yacc.c  */
#line 5401 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 685:

/* Line 1806 of yacc.c  */
#line 5409 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 686:

/* Line 1806 of yacc.c  */
#line 5417 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 687:

/* Line 1806 of yacc.c  */
#line 5425 "parser.y"
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

  case 688:

/* Line 1806 of yacc.c  */
#line 5454 "parser.y"
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

  case 690:

/* Line 1806 of yacc.c  */
#line 5487 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 691:

/* Line 1806 of yacc.c  */
#line 5496 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 692:

/* Line 1806 of yacc.c  */
#line 5502 "parser.y"
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

  case 694:

/* Line 1806 of yacc.c  */
#line 5530 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 695:

/* Line 1806 of yacc.c  */
#line 5536 "parser.y"
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

  case 700:

/* Line 1806 of yacc.c  */
#line 5573 "parser.y"
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

  case 702:

/* Line 1806 of yacc.c  */
#line 5591 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 703:

/* Line 1806 of yacc.c  */
#line 5601 "parser.y"
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

  case 704:

/* Line 1806 of yacc.c  */
#line 5645 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 707:

/* Line 1806 of yacc.c  */
#line 5656 "parser.y"
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

  case 708:

/* Line 1806 of yacc.c  */
#line 5704 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 709:

/* Line 1806 of yacc.c  */
#line 5716 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 710:

/* Line 1806 of yacc.c  */
#line 5720 "parser.y"
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

  case 711:

/* Line 1806 of yacc.c  */
#line 5738 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 712:

/* Line 1806 of yacc.c  */
#line 5743 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 713:

/* Line 1806 of yacc.c  */
#line 5748 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 714:

/* Line 1806 of yacc.c  */
#line 5756 "parser.y"
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

  case 715:

/* Line 1806 of yacc.c  */
#line 5783 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 716:

/* Line 1806 of yacc.c  */
#line 5787 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 766:

/* Line 1806 of yacc.c  */
#line 5843 "parser.y"
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

  case 767:

/* Line 1806 of yacc.c  */
#line 5857 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 768:

/* Line 1806 of yacc.c  */
#line 5868 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 770:

/* Line 1806 of yacc.c  */
#line 5878 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 771:

/* Line 1806 of yacc.c  */
#line 5883 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 772:

/* Line 1806 of yacc.c  */
#line 5887 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 773:

/* Line 1806 of yacc.c  */
#line 5891 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 774:

/* Line 1806 of yacc.c  */
#line 5896 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 775:

/* Line 1806 of yacc.c  */
#line 5901 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 776:

/* Line 1806 of yacc.c  */
#line 5906 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 777:

/* Line 1806 of yacc.c  */
#line 5911 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 778:

/* Line 1806 of yacc.c  */
#line 5915 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 779:

/* Line 1806 of yacc.c  */
#line 5919 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 780:

/* Line 1806 of yacc.c  */
#line 5923 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 781:

/* Line 1806 of yacc.c  */
#line 5927 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 782:

/* Line 1806 of yacc.c  */
#line 5932 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 783:

/* Line 1806 of yacc.c  */
#line 5936 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 784:

/* Line 1806 of yacc.c  */
#line 5940 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 785:

/* Line 1806 of yacc.c  */
#line 5944 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 786:

/* Line 1806 of yacc.c  */
#line 5948 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 787:

/* Line 1806 of yacc.c  */
#line 5952 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 788:

/* Line 1806 of yacc.c  */
#line 5956 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 790:

/* Line 1806 of yacc.c  */
#line 5964 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 793:

/* Line 1806 of yacc.c  */
#line 5975 "parser.y"
    { (yyval) = NULL; }
    break;

  case 794:

/* Line 1806 of yacc.c  */
#line 5976 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 795:

/* Line 1806 of yacc.c  */
#line 5980 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 796:

/* Line 1806 of yacc.c  */
#line 5981 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 797:

/* Line 1806 of yacc.c  */
#line 5982 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 798:

/* Line 1806 of yacc.c  */
#line 5983 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 799:

/* Line 1806 of yacc.c  */
#line 5984 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 800:

/* Line 1806 of yacc.c  */
#line 5988 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 801:

/* Line 1806 of yacc.c  */
#line 5992 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 802:

/* Line 1806 of yacc.c  */
#line 5993 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 806:

/* Line 1806 of yacc.c  */
#line 6002 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 811:

/* Line 1806 of yacc.c  */
#line 6018 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 812:

/* Line 1806 of yacc.c  */
#line 6022 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 813:

/* Line 1806 of yacc.c  */
#line 6026 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 814:

/* Line 1806 of yacc.c  */
#line 6030 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 815:

/* Line 1806 of yacc.c  */
#line 6034 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 816:

/* Line 1806 of yacc.c  */
#line 6038 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 817:

/* Line 1806 of yacc.c  */
#line 6042 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 818:

/* Line 1806 of yacc.c  */
#line 6046 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 819:

/* Line 1806 of yacc.c  */
#line 6050 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 820:

/* Line 1806 of yacc.c  */
#line 6054 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 821:

/* Line 1806 of yacc.c  */
#line 6058 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 822:

/* Line 1806 of yacc.c  */
#line 6062 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 823:

/* Line 1806 of yacc.c  */
#line 6066 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 824:

/* Line 1806 of yacc.c  */
#line 6070 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 825:

/* Line 1806 of yacc.c  */
#line 6074 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 826:

/* Line 1806 of yacc.c  */
#line 6078 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 827:

/* Line 1806 of yacc.c  */
#line 6082 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 828:

/* Line 1806 of yacc.c  */
#line 6086 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 829:

/* Line 1806 of yacc.c  */
#line 6090 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 830:

/* Line 1806 of yacc.c  */
#line 6094 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 831:

/* Line 1806 of yacc.c  */
#line 6098 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 832:

/* Line 1806 of yacc.c  */
#line 6102 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 833:

/* Line 1806 of yacc.c  */
#line 6106 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 834:

/* Line 1806 of yacc.c  */
#line 6110 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 835:

/* Line 1806 of yacc.c  */
#line 6117 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 836:

/* Line 1806 of yacc.c  */
#line 6121 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 837:

/* Line 1806 of yacc.c  */
#line 6131 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 839:

/* Line 1806 of yacc.c  */
#line 6140 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 840:

/* Line 1806 of yacc.c  */
#line 6144 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 841:

/* Line 1806 of yacc.c  */
#line 6148 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 843:

/* Line 1806 of yacc.c  */
#line 6155 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 844:

/* Line 1806 of yacc.c  */
#line 6162 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 845:

/* Line 1806 of yacc.c  */
#line 6166 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 846:

/* Line 1806 of yacc.c  */
#line 6176 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 848:

/* Line 1806 of yacc.c  */
#line 6185 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 849:

/* Line 1806 of yacc.c  */
#line 6189 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 850:

/* Line 1806 of yacc.c  */
#line 6200 "parser.y"
    { (yyval) = NULL; }
    break;

  case 851:

/* Line 1806 of yacc.c  */
#line 6201 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 852:

/* Line 1806 of yacc.c  */
#line 6209 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 856:

/* Line 1806 of yacc.c  */
#line 6223 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 859:

/* Line 1806 of yacc.c  */
#line 6235 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 861:

/* Line 1806 of yacc.c  */
#line 6250 "parser.y"
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

  case 862:

/* Line 1806 of yacc.c  */
#line 6264 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 863:

/* Line 1806 of yacc.c  */
#line 6269 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 864:

/* Line 1806 of yacc.c  */
#line 6274 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 865:

/* Line 1806 of yacc.c  */
#line 6279 "parser.y"
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

  case 866:

/* Line 1806 of yacc.c  */
#line 6299 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 867:

/* Line 1806 of yacc.c  */
#line 6303 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 868:

/* Line 1806 of yacc.c  */
#line 6308 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 869:

/* Line 1806 of yacc.c  */
#line 6319 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 870:

/* Line 1806 of yacc.c  */
#line 6321 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 871:

/* Line 1806 of yacc.c  */
#line 6326 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 872:

/* Line 1806 of yacc.c  */
#line 6334 "parser.y"
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

  case 874:

/* Line 1806 of yacc.c  */
#line 6360 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 875:

/* Line 1806 of yacc.c  */
#line 6364 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 876:

/* Line 1806 of yacc.c  */
#line 6373 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 877:

/* Line 1806 of yacc.c  */
#line 6385 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 878:

/* Line 1806 of yacc.c  */
#line 6389 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 879:

/* Line 1806 of yacc.c  */
#line 6393 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 880:

/* Line 1806 of yacc.c  */
#line 6397 "parser.y"
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

  case 885:

/* Line 1806 of yacc.c  */
#line 6430 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 886:

/* Line 1806 of yacc.c  */
#line 6435 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 887:

/* Line 1806 of yacc.c  */
#line 6442 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 888:

/* Line 1806 of yacc.c  */
#line 6447 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 889:

/* Line 1806 of yacc.c  */
#line 6454 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 890:

/* Line 1806 of yacc.c  */
#line 6458 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 891:

/* Line 1806 of yacc.c  */
#line 6468 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 893:

/* Line 1806 of yacc.c  */
#line 6476 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 894:

/* Line 1806 of yacc.c  */
#line 6480 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 895:

/* Line 1806 of yacc.c  */
#line 6490 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 897:

/* Line 1806 of yacc.c  */
#line 6498 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 898:

/* Line 1806 of yacc.c  */
#line 6503 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 899:

/* Line 1806 of yacc.c  */
#line 6510 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 900:

/* Line 1806 of yacc.c  */
#line 6511 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 901:

/* Line 1806 of yacc.c  */
#line 6512 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 902:

/* Line 1806 of yacc.c  */
#line 6513 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 903:

/* Line 1806 of yacc.c  */
#line 6514 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 904:

/* Line 1806 of yacc.c  */
#line 6522 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 906:

/* Line 1806 of yacc.c  */
#line 6531 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 907:

/* Line 1806 of yacc.c  */
#line 6538 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 908:

/* Line 1806 of yacc.c  */
#line 6542 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 909:

/* Line 1806 of yacc.c  */
#line 6552 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 910:

/* Line 1806 of yacc.c  */
#line 6563 "parser.y"
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

  case 911:

/* Line 1806 of yacc.c  */
#line 6580 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 913:

/* Line 1806 of yacc.c  */
#line 6589 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 915:

/* Line 1806 of yacc.c  */
#line 6597 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 916:

/* Line 1806 of yacc.c  */
#line 6602 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 917:

/* Line 1806 of yacc.c  */
#line 6610 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 918:

/* Line 1806 of yacc.c  */
#line 6614 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 919:

/* Line 1806 of yacc.c  */
#line 6624 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 921:

/* Line 1806 of yacc.c  */
#line 6634 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 922:

/* Line 1806 of yacc.c  */
#line 6638 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 923:

/* Line 1806 of yacc.c  */
#line 6642 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 924:

/* Line 1806 of yacc.c  */
#line 6646 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 925:

/* Line 1806 of yacc.c  */
#line 6650 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 927:

/* Line 1806 of yacc.c  */
#line 6655 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 929:

/* Line 1806 of yacc.c  */
#line 6665 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 931:

/* Line 1806 of yacc.c  */
#line 6673 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 932:

/* Line 1806 of yacc.c  */
#line 6681 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 933:

/* Line 1806 of yacc.c  */
#line 6689 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 934:

/* Line 1806 of yacc.c  */
#line 6693 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 935:

/* Line 1806 of yacc.c  */
#line 6697 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 936:

/* Line 1806 of yacc.c  */
#line 6701 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 942:

/* Line 1806 of yacc.c  */
#line 6723 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 943:

/* Line 1806 of yacc.c  */
#line 6729 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 944:

/* Line 1806 of yacc.c  */
#line 6730 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 947:

/* Line 1806 of yacc.c  */
#line 6741 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 948:

/* Line 1806 of yacc.c  */
#line 6745 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 949:

/* Line 1806 of yacc.c  */
#line 6749 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 950:

/* Line 1806 of yacc.c  */
#line 6753 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 951:

/* Line 1806 of yacc.c  */
#line 6757 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 952:

/* Line 1806 of yacc.c  */
#line 6761 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 953:

/* Line 1806 of yacc.c  */
#line 6765 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 954:

/* Line 1806 of yacc.c  */
#line 6769 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 955:

/* Line 1806 of yacc.c  */
#line 6773 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 956:

/* Line 1806 of yacc.c  */
#line 6777 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 957:

/* Line 1806 of yacc.c  */
#line 6781 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 958:

/* Line 1806 of yacc.c  */
#line 6785 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 959:

/* Line 1806 of yacc.c  */
#line 6789 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 960:

/* Line 1806 of yacc.c  */
#line 6793 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 961:

/* Line 1806 of yacc.c  */
#line 6797 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 962:

/* Line 1806 of yacc.c  */
#line 6801 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 963:

/* Line 1806 of yacc.c  */
#line 6808 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 964:

/* Line 1806 of yacc.c  */
#line 6812 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 965:

/* Line 1806 of yacc.c  */
#line 6822 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 967:

/* Line 1806 of yacc.c  */
#line 6831 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 968:

/* Line 1806 of yacc.c  */
#line 6835 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 969:

/* Line 1806 of yacc.c  */
#line 6839 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 970:

/* Line 1806 of yacc.c  */
#line 6843 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 971:

/* Line 1806 of yacc.c  */
#line 6847 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 972:

/* Line 1806 of yacc.c  */
#line 6854 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 973:

/* Line 1806 of yacc.c  */
#line 6858 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 974:

/* Line 1806 of yacc.c  */
#line 6868 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 976:

/* Line 1806 of yacc.c  */
#line 6876 "parser.y"
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

  case 977:

/* Line 1806 of yacc.c  */
#line 6895 "parser.y"
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

  case 979:

/* Line 1806 of yacc.c  */
#line 6919 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 980:

/* Line 1806 of yacc.c  */
#line 6926 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 981:

/* Line 1806 of yacc.c  */
#line 6928 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 982:

/* Line 1806 of yacc.c  */
#line 6933 "parser.y"
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

  case 983:

/* Line 1806 of yacc.c  */
#line 6944 "parser.y"
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

  case 984:

/* Line 1806 of yacc.c  */
#line 6955 "parser.y"
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

  case 985:

/* Line 1806 of yacc.c  */
#line 6969 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 986:

/* Line 1806 of yacc.c  */
#line 6973 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 987:

/* Line 1806 of yacc.c  */
#line 6979 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 988:

/* Line 1806 of yacc.c  */
#line 6981 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 989:

/* Line 1806 of yacc.c  */
#line 6987 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 990:

/* Line 1806 of yacc.c  */
#line 6996 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 991:

/* Line 1806 of yacc.c  */
#line 7004 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 992:

/* Line 1806 of yacc.c  */
#line 7010 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 993:

/* Line 1806 of yacc.c  */
#line 7017 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 994:

/* Line 1806 of yacc.c  */
#line 7019 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 995:

/* Line 1806 of yacc.c  */
#line 7024 "parser.y"
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

  case 996:

/* Line 1806 of yacc.c  */
#line 7085 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 997:

/* Line 1806 of yacc.c  */
#line 7086 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 998:

/* Line 1806 of yacc.c  */
#line 7087 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 999:

/* Line 1806 of yacc.c  */
#line 7091 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1000:

/* Line 1806 of yacc.c  */
#line 7092 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1001:

/* Line 1806 of yacc.c  */
#line 7097 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 1002:

/* Line 1806 of yacc.c  */
#line 7101 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 1003:

/* Line 1806 of yacc.c  */
#line 7111 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 1004:

/* Line 1806 of yacc.c  */
#line 7116 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1006:

/* Line 1806 of yacc.c  */
#line 7124 "parser.y"
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

  case 1007:

/* Line 1806 of yacc.c  */
#line 7142 "parser.y"
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

  case 1008:

/* Line 1806 of yacc.c  */
#line 7156 "parser.y"
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

  case 1009:

/* Line 1806 of yacc.c  */
#line 7178 "parser.y"
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

  case 1010:

/* Line 1806 of yacc.c  */
#line 7200 "parser.y"
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

  case 1011:

/* Line 1806 of yacc.c  */
#line 7220 "parser.y"
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

  case 1012:

/* Line 1806 of yacc.c  */
#line 7245 "parser.y"
    {
	begin_statement ("FREE", 0);
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7253 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 1015:

/* Line 1806 of yacc.c  */
#line 7263 "parser.y"
    {
	begin_statement ("GENERATE", 0);
  }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7272 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
		cb_emit_generate((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1018:

/* Line 1806 of yacc.c  */
#line 7284 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7297 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7305 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7310 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7321 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	cb_emit_exit (1U);
  }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7333 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7342 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7346 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7350 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7357 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7361 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7371 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7380 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7386 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1035:

/* Line 1806 of yacc.c  */
#line 7387 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7391 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1037:

/* Line 1806 of yacc.c  */
#line 7392 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7393 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1039:

/* Line 1806 of yacc.c  */
#line 7398 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1040:

/* Line 1806 of yacc.c  */
#line 7402 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1041:

/* Line 1806 of yacc.c  */
#line 7409 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1042:

/* Line 1806 of yacc.c  */
#line 7414 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7421 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1044:

/* Line 1806 of yacc.c  */
#line 7427 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1045:

/* Line 1806 of yacc.c  */
#line 7428 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1046:

/* Line 1806 of yacc.c  */
#line 7429 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1047:

/* Line 1806 of yacc.c  */
#line 7430 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1048:

/* Line 1806 of yacc.c  */
#line 7431 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1049:

/* Line 1806 of yacc.c  */
#line 7432 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1050:

/* Line 1806 of yacc.c  */
#line 7433 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1051:

/* Line 1806 of yacc.c  */
#line 7438 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1052:

/* Line 1806 of yacc.c  */
#line 7442 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1053:

/* Line 1806 of yacc.c  */
#line 7451 "parser.y"
    {
	begin_statement ("INITIATE", 0);
  }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7459 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	    cb_emit_initiate((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1056:

/* Line 1806 of yacc.c  */
#line 7466 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	    cb_emit_initiate((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1057:

/* Line 1806 of yacc.c  */
#line 7478 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7491 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7495 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7499 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7515 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7519 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7529 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7539 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
#line 7547 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1072:

/* Line 1806 of yacc.c  */
#line 7548 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7552 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7553 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1075:

/* Line 1806 of yacc.c  */
#line 7554 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1076:

/* Line 1806 of yacc.c  */
#line 7555 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1077:

/* Line 1806 of yacc.c  */
#line 7556 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7557 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1079:

/* Line 1806 of yacc.c  */
#line 7561 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1080:

/* Line 1806 of yacc.c  */
#line 7562 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1081:

/* Line 1806 of yacc.c  */
#line 7567 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1082:

/* Line 1806 of yacc.c  */
#line 7572 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1083:

/* Line 1806 of yacc.c  */
#line 7578 "parser.y"
    { /* Nothing */ }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7579 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7580 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1086:

/* Line 1806 of yacc.c  */
#line 7581 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1087:

/* Line 1806 of yacc.c  */
#line 7582 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7587 "parser.y"
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

  case 1089:

/* Line 1806 of yacc.c  */
#line 7614 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7618 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1091:

/* Line 1806 of yacc.c  */
#line 7625 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1092:

/* Line 1806 of yacc.c  */
#line 7629 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1093:

/* Line 1806 of yacc.c  */
#line 7638 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1095:

/* Line 1806 of yacc.c  */
#line 7650 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7658 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7662 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1099:

/* Line 1806 of yacc.c  */
#line 7672 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1101:

/* Line 1806 of yacc.c  */
#line 7681 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1102:

/* Line 1806 of yacc.c  */
#line 7685 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1103:

/* Line 1806 of yacc.c  */
#line 7692 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7696 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7706 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7714 "parser.y"
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

  case 1108:

/* Line 1806 of yacc.c  */
#line 7735 "parser.y"
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

  case 1109:

/* Line 1806 of yacc.c  */
#line 7758 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1110:

/* Line 1806 of yacc.c  */
#line 7759 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
#line 7760 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1112:

/* Line 1806 of yacc.c  */
#line 7761 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
#line 7765 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1114:

/* Line 1806 of yacc.c  */
#line 7766 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1115:

/* Line 1806 of yacc.c  */
#line 7770 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1116:

/* Line 1806 of yacc.c  */
#line 7771 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
#line 7772 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1118:

/* Line 1806 of yacc.c  */
#line 7774 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1119:

/* Line 1806 of yacc.c  */
#line 7785 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1121:

/* Line 1806 of yacc.c  */
#line 7796 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7801 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7807 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7812 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1125:

/* Line 1806 of yacc.c  */
#line 7820 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7828 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1127:

/* Line 1806 of yacc.c  */
#line 7835 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
#line 7839 "parser.y"
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

  case 1129:

/* Line 1806 of yacc.c  */
#line 7852 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1130:

/* Line 1806 of yacc.c  */
#line 7859 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1131:

/* Line 1806 of yacc.c  */
#line 7870 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1132:

/* Line 1806 of yacc.c  */
#line 7874 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7879 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1134:

/* Line 1806 of yacc.c  */
#line 7883 "parser.y"
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

  case 1135:

/* Line 1806 of yacc.c  */
#line 7894 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1136:

/* Line 1806 of yacc.c  */
#line 7900 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7901 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1138:

/* Line 1806 of yacc.c  */
#line 7905 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1139:

/* Line 1806 of yacc.c  */
#line 7906 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1140:

/* Line 1806 of yacc.c  */
#line 7909 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1141:

/* Line 1806 of yacc.c  */
#line 7911 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1142:

/* Line 1806 of yacc.c  */
#line 7916 "parser.y"
    {
	cb_tree		x;
	int		dataTypeOk = 1;

	if (cb_tree_category ((yyvsp[(1) - (7)])) != CB_CATEGORY_NUMERIC) {
		x = cb_ref ((yyvsp[(1) - (7)]));
		cb_error_x (CB_TREE (current_statement),
			_("PERFORM VARYING '%s' (Line %d of %s) is not a numeric field"), 
					cb_name (x),x->source_line, x->source_file);
		(yyval) = cb_int1;
		dataTypeOk = 0;
	} 
	if (cb_tree_category ((yyvsp[(3) - (7)])) != CB_CATEGORY_NUMERIC) {
		x = cb_ref ((yyvsp[(3) - (7)]));
		cb_error_x (CB_TREE (current_statement),
			_("PERFORM VARYING '%s' (Line %d of %s) is not a numeric field"), 
					cb_name (x),x->source_line, x->source_file);
		(yyval) = cb_int1;
		dataTypeOk = 0;
	} 
	if (cb_tree_category ((yyvsp[(5) - (7)])) != CB_CATEGORY_NUMERIC) {
		x = cb_ref ((yyvsp[(5) - (7)]));
		cb_error_x (CB_TREE (current_statement),
			_("PERFORM VARYING '%s' (Line %d of %s) is not a numeric field"), 
					cb_name (x),x->source_line, x->source_file);
		(yyval) = cb_int1;
		dataTypeOk = 0;
	} 
	if(dataTypeOk) {
		(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
	}
  }
    break;

  case 1143:

/* Line 1806 of yacc.c  */
#line 7955 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7964 "parser.y"
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

  case 1146:

/* Line 1806 of yacc.c  */
#line 7990 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1147:

/* Line 1806 of yacc.c  */
#line 7991 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1148:

/* Line 1806 of yacc.c  */
#line 7996 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1149:

/* Line 1806 of yacc.c  */
#line 8000 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1150:

/* Line 1806 of yacc.c  */
#line 8004 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 8008 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 8012 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1153:

/* Line 1806 of yacc.c  */
#line 8016 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1154:

/* Line 1806 of yacc.c  */
#line 8020 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1155:

/* Line 1806 of yacc.c  */
#line 8026 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 8027 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1159:

/* Line 1806 of yacc.c  */
#line 8037 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 8041 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 8051 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1162:

/* Line 1806 of yacc.c  */
#line 8061 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1164:

/* Line 1806 of yacc.c  */
#line 8069 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 8079 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 8089 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1168:

/* Line 1806 of yacc.c  */
#line 8098 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 8105 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 8109 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1171:

/* Line 1806 of yacc.c  */
#line 8119 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 8131 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 8139 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 8143 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1176:

/* Line 1806 of yacc.c  */
#line 8147 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1177:

/* Line 1806 of yacc.c  */
#line 8154 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1178:

/* Line 1806 of yacc.c  */
#line 8158 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1179:

/* Line 1806 of yacc.c  */
#line 8168 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1180:

/* Line 1806 of yacc.c  */
#line 8179 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1182:

/* Line 1806 of yacc.c  */
#line 8188 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1183:

/* Line 1806 of yacc.c  */
#line 8193 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1184:

/* Line 1806 of yacc.c  */
#line 8200 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1185:

/* Line 1806 of yacc.c  */
#line 8201 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1186:

/* Line 1806 of yacc.c  */
#line 8206 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1187:

/* Line 1806 of yacc.c  */
#line 8211 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1188:

/* Line 1806 of yacc.c  */
#line 8218 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1189:

/* Line 1806 of yacc.c  */
#line 8222 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1190:

/* Line 1806 of yacc.c  */
#line 8230 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1191:

/* Line 1806 of yacc.c  */
#line 8237 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1192:

/* Line 1806 of yacc.c  */
#line 8241 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1193:

/* Line 1806 of yacc.c  */
#line 8251 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1194:

/* Line 1806 of yacc.c  */
#line 8258 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1201:

/* Line 1806 of yacc.c  */
#line 8273 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1202:

/* Line 1806 of yacc.c  */
#line 8274 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1203:

/* Line 1806 of yacc.c  */
#line 8278 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1204:

/* Line 1806 of yacc.c  */
#line 8279 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1205:

/* Line 1806 of yacc.c  */
#line 8286 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1206:

/* Line 1806 of yacc.c  */
#line 8295 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1209:

/* Line 1806 of yacc.c  */
#line 8307 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1210:

/* Line 1806 of yacc.c  */
#line 8311 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1211:

/* Line 1806 of yacc.c  */
#line 8315 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
#line 8319 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1213:

/* Line 1806 of yacc.c  */
#line 8323 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1214:

/* Line 1806 of yacc.c  */
#line 8327 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
#line 8331 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1216:

/* Line 1806 of yacc.c  */
#line 8335 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1217:

/* Line 1806 of yacc.c  */
#line 8344 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1218:

/* Line 1806 of yacc.c  */
#line 8348 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1219:

/* Line 1806 of yacc.c  */
#line 8357 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8371 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1225:

/* Line 1806 of yacc.c  */
#line 8385 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1226:

/* Line 1806 of yacc.c  */
#line 8389 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1227:

/* Line 1806 of yacc.c  */
#line 8399 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1229:

/* Line 1806 of yacc.c  */
#line 8407 "parser.y"
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

  case 1230:

/* Line 1806 of yacc.c  */
#line 8428 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1231:

/* Line 1806 of yacc.c  */
#line 8437 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1232:

/* Line 1806 of yacc.c  */
#line 8442 "parser.y"
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

  case 1233:

/* Line 1806 of yacc.c  */
#line 8460 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1234:

/* Line 1806 of yacc.c  */
#line 8461 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1236:

/* Line 1806 of yacc.c  */
#line 8466 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1237:

/* Line 1806 of yacc.c  */
#line 8473 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1238:

/* Line 1806 of yacc.c  */
#line 8474 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8479 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1240:

/* Line 1806 of yacc.c  */
#line 8485 "parser.y"
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

  case 1241:

/* Line 1806 of yacc.c  */
#line 8495 "parser.y"
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

  case 1242:

/* Line 1806 of yacc.c  */
#line 8510 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1243:

/* Line 1806 of yacc.c  */
#line 8516 "parser.y"
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

  case 1244:

/* Line 1806 of yacc.c  */
#line 8526 "parser.y"
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

  case 1245:

/* Line 1806 of yacc.c  */
#line 8542 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1247:

/* Line 1806 of yacc.c  */
#line 8552 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1248:

/* Line 1806 of yacc.c  */
#line 8564 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8568 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
#line 8575 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1251:

/* Line 1806 of yacc.c  */
#line 8579 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1252:

/* Line 1806 of yacc.c  */
#line 8584 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
#line 8589 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1254:

/* Line 1806 of yacc.c  */
#line 8596 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1255:

/* Line 1806 of yacc.c  */
#line 8597 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8598 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1257:

/* Line 1806 of yacc.c  */
#line 8599 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1258:

/* Line 1806 of yacc.c  */
#line 8600 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8601 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8606 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8619 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8623 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1265:

/* Line 1806 of yacc.c  */
#line 8633 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8637 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8643 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8655 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1269:

/* Line 1806 of yacc.c  */
#line 8659 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8663 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8667 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8675 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1273:

/* Line 1806 of yacc.c  */
#line 8686 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1274:

/* Line 1806 of yacc.c  */
#line 8690 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1275:

/* Line 1806 of yacc.c  */
#line 8696 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8697 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1277:

/* Line 1806 of yacc.c  */
#line 8698 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8699 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8706 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1281:

/* Line 1806 of yacc.c  */
#line 8715 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1282:

/* Line 1806 of yacc.c  */
#line 8721 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1283:

/* Line 1806 of yacc.c  */
#line 8722 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1284:

/* Line 1806 of yacc.c  */
#line 8726 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1285:

/* Line 1806 of yacc.c  */
#line 8727 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8728 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1287:

/* Line 1806 of yacc.c  */
#line 8732 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1288:

/* Line 1806 of yacc.c  */
#line 8733 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1289:

/* Line 1806 of yacc.c  */
#line 8738 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1290:

/* Line 1806 of yacc.c  */
#line 8742 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1291:

/* Line 1806 of yacc.c  */
#line 8752 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1293:

/* Line 1806 of yacc.c  */
#line 8761 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1294:

/* Line 1806 of yacc.c  */
#line 8765 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1295:

/* Line 1806 of yacc.c  */
#line 8769 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1296:

/* Line 1806 of yacc.c  */
#line 8776 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1297:

/* Line 1806 of yacc.c  */
#line 8780 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1298:

/* Line 1806 of yacc.c  */
#line 8790 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	cb_emit_suppress(control_field);
  }
    break;

  case 1301:

/* Line 1806 of yacc.c  */
#line 8808 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
  }
    break;

  case 1303:

/* Line 1806 of yacc.c  */
#line 8816 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	    cb_emit_terminate((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1304:

/* Line 1806 of yacc.c  */
#line 8823 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	    cb_emit_terminate((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8835 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1307:

/* Line 1806 of yacc.c  */
#line 8843 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1308:

/* Line 1806 of yacc.c  */
#line 8856 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1310:

/* Line 1806 of yacc.c  */
#line 8864 "parser.y"
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

  case 1314:

/* Line 1806 of yacc.c  */
#line 8887 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1316:

/* Line 1806 of yacc.c  */
#line 8897 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1317:

/* Line 1806 of yacc.c  */
#line 8903 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1318:

/* Line 1806 of yacc.c  */
#line 8905 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1319:

/* Line 1806 of yacc.c  */
#line 8909 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1320:

/* Line 1806 of yacc.c  */
#line 8911 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1321:

/* Line 1806 of yacc.c  */
#line 8916 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1322:

/* Line 1806 of yacc.c  */
#line 8922 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1323:

/* Line 1806 of yacc.c  */
#line 8924 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1324:

/* Line 1806 of yacc.c  */
#line 8929 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1325:

/* Line 1806 of yacc.c  */
#line 8935 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1326:

/* Line 1806 of yacc.c  */
#line 8936 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1327:

/* Line 1806 of yacc.c  */
#line 8940 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1328:

/* Line 1806 of yacc.c  */
#line 8941 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1329:

/* Line 1806 of yacc.c  */
#line 8945 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1330:

/* Line 1806 of yacc.c  */
#line 8946 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1331:

/* Line 1806 of yacc.c  */
#line 8951 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1332:

/* Line 1806 of yacc.c  */
#line 8955 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1333:

/* Line 1806 of yacc.c  */
#line 8965 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1339:

/* Line 1806 of yacc.c  */
#line 8982 "parser.y"
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

  case 1340:

/* Line 1806 of yacc.c  */
#line 9007 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1341:

/* Line 1806 of yacc.c  */
#line 9011 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1342:

/* Line 1806 of yacc.c  */
#line 9023 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1343:

/* Line 1806 of yacc.c  */
#line 9033 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1344:

/* Line 1806 of yacc.c  */
#line 9038 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1345:

/* Line 1806 of yacc.c  */
#line 9043 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1346:

/* Line 1806 of yacc.c  */
#line 9048 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1347:

/* Line 1806 of yacc.c  */
#line 9056 "parser.y"
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

  case 1350:

/* Line 1806 of yacc.c  */
#line 9099 "parser.y"
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

  case 1351:

/* Line 1806 of yacc.c  */
#line 9139 "parser.y"
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

  case 1352:

/* Line 1806 of yacc.c  */
#line 9149 "parser.y"
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

  case 1357:

/* Line 1806 of yacc.c  */
#line 9179 "parser.y"
    {
	char wrk[80];
	cb_tree x;
	struct cb_field		*f;
	struct cb_report	*r;

	x = cb_ref ((yyvsp[(4) - (4)]));
	if (!CB_FIELD_P (x)) {
		cb_error_x ((yyvsp[(4) - (4)]), _("'%s' is not a report group"), CB_NAME ((yyvsp[(4) - (4)])));
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

  case 1358:

/* Line 1806 of yacc.c  */
#line 9210 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1361:

/* Line 1806 of yacc.c  */
#line 9226 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1363:

/* Line 1806 of yacc.c  */
#line 9238 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1364:

/* Line 1806 of yacc.c  */
#line 9247 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1365:

/* Line 1806 of yacc.c  */
#line 9248 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1366:

/* Line 1806 of yacc.c  */
#line 9253 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1367:

/* Line 1806 of yacc.c  */
#line 9257 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1368:

/* Line 1806 of yacc.c  */
#line 9261 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1369:

/* Line 1806 of yacc.c  */
#line 9265 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1370:

/* Line 1806 of yacc.c  */
#line 9271 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1371:

/* Line 1806 of yacc.c  */
#line 9272 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1374:

/* Line 1806 of yacc.c  */
#line 9282 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1375:

/* Line 1806 of yacc.c  */
#line 9286 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1378:

/* Line 1806 of yacc.c  */
#line 9303 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1380:

/* Line 1806 of yacc.c  */
#line 9313 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1383:

/* Line 1806 of yacc.c  */
#line 9326 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1385:

/* Line 1806 of yacc.c  */
#line 9336 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1388:

/* Line 1806 of yacc.c  */
#line 9351 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1390:

/* Line 1806 of yacc.c  */
#line 9361 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1393:

/* Line 1806 of yacc.c  */
#line 9378 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1395:

/* Line 1806 of yacc.c  */
#line 9389 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1401:

/* Line 1806 of yacc.c  */
#line 9412 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1402:

/* Line 1806 of yacc.c  */
#line 9421 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9438 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1407:

/* Line 1806 of yacc.c  */
#line 9447 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1410:

/* Line 1806 of yacc.c  */
#line 9464 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1412:

/* Line 1806 of yacc.c  */
#line 9474 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1413:

/* Line 1806 of yacc.c  */
#line 9484 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1414:

/* Line 1806 of yacc.c  */
#line 9488 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9498 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9505 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9511 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1418:

/* Line 1806 of yacc.c  */
#line 9515 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9528 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9536 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9537 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9539 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9540 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1427:

/* Line 1806 of yacc.c  */
#line 9541 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1428:

/* Line 1806 of yacc.c  */
#line 9542 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1429:

/* Line 1806 of yacc.c  */
#line 9543 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1430:

/* Line 1806 of yacc.c  */
#line 9545 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1431:

/* Line 1806 of yacc.c  */
#line 9546 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1432:

/* Line 1806 of yacc.c  */
#line 9547 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1433:

/* Line 1806 of yacc.c  */
#line 9548 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1434:

/* Line 1806 of yacc.c  */
#line 9549 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1435:

/* Line 1806 of yacc.c  */
#line 9550 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1436:

/* Line 1806 of yacc.c  */
#line 9552 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1437:

/* Line 1806 of yacc.c  */
#line 9553 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1438:

/* Line 1806 of yacc.c  */
#line 9554 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1439:

/* Line 1806 of yacc.c  */
#line 9556 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1440:

/* Line 1806 of yacc.c  */
#line 9557 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1441:

/* Line 1806 of yacc.c  */
#line 9558 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1442:

/* Line 1806 of yacc.c  */
#line 9559 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1443:

/* Line 1806 of yacc.c  */
#line 9560 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1444:

/* Line 1806 of yacc.c  */
#line 9563 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1445:

/* Line 1806 of yacc.c  */
#line 9564 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9594 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1455:

/* Line 1806 of yacc.c  */
#line 9598 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1459:

/* Line 1806 of yacc.c  */
#line 9609 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1460:

/* Line 1806 of yacc.c  */
#line 9610 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9611 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1462:

/* Line 1806 of yacc.c  */
#line 9615 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9616 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1464:

/* Line 1806 of yacc.c  */
#line 9617 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1465:

/* Line 1806 of yacc.c  */
#line 9622 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1466:

/* Line 1806 of yacc.c  */
#line 9625 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1467:

/* Line 1806 of yacc.c  */
#line 9629 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1468:

/* Line 1806 of yacc.c  */
#line 9630 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1469:

/* Line 1806 of yacc.c  */
#line 9631 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1470:

/* Line 1806 of yacc.c  */
#line 9634 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9635 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1472:

/* Line 1806 of yacc.c  */
#line 9646 "parser.y"
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

  case 1473:

/* Line 1806 of yacc.c  */
#line 9658 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1474:

/* Line 1806 of yacc.c  */
#line 9667 "parser.y"
    {
	  if (report_count > 1
	  && current_report != NULL) {
		(yyval) = current_report->line_counter;
	  } else
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

  case 1475:

/* Line 1806 of yacc.c  */
#line 9683 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1476:

/* Line 1806 of yacc.c  */
#line 9692 "parser.y"
    {
	  if (report_count > 1
	  && current_report != NULL) {
		(yyval) = current_report->page_counter;
	  } else
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

  case 1477:

/* Line 1806 of yacc.c  */
#line 9708 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1478:

/* Line 1806 of yacc.c  */
#line 9722 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9724 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9729 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9737 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1482:

/* Line 1806 of yacc.c  */
#line 9744 "parser.y"
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

  case 1483:

/* Line 1806 of yacc.c  */
#line 9764 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1484:

/* Line 1806 of yacc.c  */
#line 9768 "parser.y"
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

  case 1485:

/* Line 1806 of yacc.c  */
#line 9789 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1486:

/* Line 1806 of yacc.c  */
#line 9830 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1487:

/* Line 1806 of yacc.c  */
#line 9843 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9845 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1489:

/* Line 1806 of yacc.c  */
#line 9849 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1490:

/* Line 1806 of yacc.c  */
#line 9855 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1491:

/* Line 1806 of yacc.c  */
#line 9857 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1492:

/* Line 1806 of yacc.c  */
#line 9862 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9876 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1496:

/* Line 1806 of yacc.c  */
#line 9883 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1497:

/* Line 1806 of yacc.c  */
#line 9893 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1498:

/* Line 1806 of yacc.c  */
#line 9894 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1499:

/* Line 1806 of yacc.c  */
#line 9899 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1500:

/* Line 1806 of yacc.c  */
#line 9907 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9915 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1502:

/* Line 1806 of yacc.c  */
#line 9919 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9926 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1506:

/* Line 1806 of yacc.c  */
#line 9942 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1507:

/* Line 1806 of yacc.c  */
#line 9956 "parser.y"
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

  case 1508:

/* Line 1806 of yacc.c  */
#line 9973 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1509:

/* Line 1806 of yacc.c  */
#line 9977 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1512:

/* Line 1806 of yacc.c  */
#line 9986 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1513:

/* Line 1806 of yacc.c  */
#line 9993 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1514:

/* Line 1806 of yacc.c  */
#line 9997 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1519:

/* Line 1806 of yacc.c  */
#line 10008 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1520:

/* Line 1806 of yacc.c  */
#line 10012 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1521:

/* Line 1806 of yacc.c  */
#line 10016 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1522:

/* Line 1806 of yacc.c  */
#line 10020 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1523:

/* Line 1806 of yacc.c  */
#line 10024 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1524:

/* Line 1806 of yacc.c  */
#line 10028 "parser.y"
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

  case 1525:

/* Line 1806 of yacc.c  */
#line 10049 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1526:

/* Line 1806 of yacc.c  */
#line 10053 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1534:

/* Line 1806 of yacc.c  */
#line 10070 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1535:

/* Line 1806 of yacc.c  */
#line 10074 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1536:

/* Line 1806 of yacc.c  */
#line 10078 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1552:

/* Line 1806 of yacc.c  */
#line 10125 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1560:

/* Line 1806 of yacc.c  */
#line 10149 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1561:

/* Line 1806 of yacc.c  */
#line 10153 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1562:

/* Line 1806 of yacc.c  */
#line 10157 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1563:

/* Line 1806 of yacc.c  */
#line 10158 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1564:

/* Line 1806 of yacc.c  */
#line 10162 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1565:

/* Line 1806 of yacc.c  */
#line 10167 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1566:

/* Line 1806 of yacc.c  */
#line 10174 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1567:

/* Line 1806 of yacc.c  */
#line 10181 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1568:

/* Line 1806 of yacc.c  */
#line 10188 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1569:

/* Line 1806 of yacc.c  */
#line 10198 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1570:

/* Line 1806 of yacc.c  */
#line 10202 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1571:

/* Line 1806 of yacc.c  */
#line 10209 "parser.y"
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

  case 1572:

/* Line 1806 of yacc.c  */
#line 10219 "parser.y"
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

  case 1573:

/* Line 1806 of yacc.c  */
#line 10229 "parser.y"
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

  case 1574:

/* Line 1806 of yacc.c  */
#line 10239 "parser.y"
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

  case 1575:

/* Line 1806 of yacc.c  */
#line 10252 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1576:

/* Line 1806 of yacc.c  */
#line 10256 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1577:

/* Line 1806 of yacc.c  */
#line 10264 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 10272 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 10276 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1580:

/* Line 1806 of yacc.c  */
#line 10286 "parser.y"
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

  case 1581:

/* Line 1806 of yacc.c  */
#line 10301 "parser.y"
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

  case 1582:

/* Line 1806 of yacc.c  */
#line 10324 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign < 0 || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Positive Integer value expected"));
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

  case 1583:

/* Line 1806 of yacc.c  */
#line 10347 "parser.y"
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

  case 1584:

/* Line 1806 of yacc.c  */
#line 10362 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1585:

/* Line 1806 of yacc.c  */
#line 10363 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 10364 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 10365 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 10366 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10367 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10372 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1591:

/* Line 1806 of yacc.c  */
#line 10376 "parser.y"
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

  case 1592:

/* Line 1806 of yacc.c  */
#line 10393 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1593:

/* Line 1806 of yacc.c  */
#line 10397 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1594:

/* Line 1806 of yacc.c  */
#line 10403 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1595:

/* Line 1806 of yacc.c  */
#line 10404 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1596:

/* Line 1806 of yacc.c  */
#line 10405 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1597:

/* Line 1806 of yacc.c  */
#line 10406 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1598:

/* Line 1806 of yacc.c  */
#line 10407 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1599:

/* Line 1806 of yacc.c  */
#line 10408 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1600:

/* Line 1806 of yacc.c  */
#line 10409 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1601:

/* Line 1806 of yacc.c  */
#line 10416 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1602:

/* Line 1806 of yacc.c  */
#line 10420 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1603:

/* Line 1806 of yacc.c  */
#line 10424 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1604:

/* Line 1806 of yacc.c  */
#line 10428 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1605:

/* Line 1806 of yacc.c  */
#line 10432 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1606:

/* Line 1806 of yacc.c  */
#line 10436 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1607:

/* Line 1806 of yacc.c  */
#line 10440 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1608:

/* Line 1806 of yacc.c  */
#line 10444 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1609:

/* Line 1806 of yacc.c  */
#line 10448 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1610:

/* Line 1806 of yacc.c  */
#line 10452 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10476 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10480 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10484 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10491 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10495 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10499 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10506 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10513 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10520 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10530 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10537 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10547 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10554 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10565 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10573 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1634:

/* Line 1806 of yacc.c  */
#line 10574 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10578 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10579 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10583 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10584 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10589 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10593 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10600 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10604 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10611 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10612 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1645:

/* Line 1806 of yacc.c  */
#line 10613 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1646:

/* Line 1806 of yacc.c  */
#line 10617 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1647:

/* Line 1806 of yacc.c  */
#line 10618 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1648:

/* Line 1806 of yacc.c  */
#line 10622 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1649:

/* Line 1806 of yacc.c  */
#line 10623 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1650:

/* Line 1806 of yacc.c  */
#line 10624 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1651:

/* Line 1806 of yacc.c  */
#line 10629 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1652:

/* Line 1806 of yacc.c  */
#line 10633 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1653:

/* Line 1806 of yacc.c  */
#line 10645 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1654:

/* Line 1806 of yacc.c  */
#line 10650 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1655:

/* Line 1806 of yacc.c  */
#line 10658 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1656:

/* Line 1806 of yacc.c  */
#line 10662 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1657:

/* Line 1806 of yacc.c  */
#line 10666 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1658:

/* Line 1806 of yacc.c  */
#line 10670 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1659:

/* Line 1806 of yacc.c  */
#line 10674 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1660:

/* Line 1806 of yacc.c  */
#line 10678 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1661:

/* Line 1806 of yacc.c  */
#line 10682 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1662:

/* Line 1806 of yacc.c  */
#line 10686 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1663:

/* Line 1806 of yacc.c  */
#line 10692 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1664:

/* Line 1806 of yacc.c  */
#line 10693 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1806 of yacc.c  */
#line 18955 "parser.c"
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
#line 10863 "parser.y"


