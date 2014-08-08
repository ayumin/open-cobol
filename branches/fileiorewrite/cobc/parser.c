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
static struct cb_key_component	*key_component_list;

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
check_relaxed_syntax_opt (const char * optional, const unsigned int needed)
{
	if (!cb_relaxed_syntax_check) {
		if (needed) {
			cb_error (_("'%s' is mandatory here"), optional);
		} else {
			cb_error (_("non-standard '%s'"), optional);
		}
	}
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
#line 781 "parser.c"

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
#line 1335 "parser.c"

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
#define YYLAST   7766

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  820
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1905
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2725

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
     376,   380,   382,   384,   386,   388,   390,   392,   394,   396,
     399,   400,   403,   407,   409,   412,   416,   418,   421,   423,
     426,   431,   433,   436,   438,   442,   447,   453,   454,   458,
     462,   468,   472,   477,   481,   485,   486,   490,   491,   494,
     495,   498,   499,   502,   503,   510,   514,   515,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     542,   544,   550,   556,   562,   568,   574,   576,   578,   580,
     582,   583,   587,   588,   590,   592,   594,   596,   597,   599,
     601,   606,   608,   610,   612,   620,   630,   631,   636,   640,
     644,   649,   650,   652,   654,   655,   661,   664,   667,   669,
     670,   675,   681,   684,   688,   690,   692,   696,   698,   701,
     706,   711,   716,   723,   725,   728,   729,   732,   735,   737,
     742,   746,   748,   750,   754,   757,   760,   763,   764,   767,
     771,   773,   776,   778,   780,   786,   787,   789,   791,   793,
     794,   801,   803,   806,   809,   810,   813,   814,   818,   819,
     823,   824,   827,   830,   831,   837,   841,   843,   845,   846,
     849,   852,   855,   857,   859,   861,   863,   865,   867,   869,
     871,   873,   879,   880,   882,   884,   889,   896,   906,   907,
     911,   912,   915,   916,   919,   923,   929,   935,   937,   939,
     941,   943,   947,   953,   954,   957,   959,   961,   963,   968,
     971,   974,   979,   983,   986,   989,   992,   994,   997,   998,
     999,  1005,  1006,  1007,  1010,  1013,  1017,  1020,  1022,  1023,
    1028,  1032,  1035,  1036,  1038,  1040,  1042,  1043,  1046,  1048,
    1051,  1054,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,
    1074,  1076,  1078,  1080,  1082,  1085,  1087,  1089,  1091,  1093,
    1095,  1097,  1099,  1101,  1103,  1109,  1112,  1115,  1116,  1119,
    1121,  1123,  1125,  1127,  1129,  1131,  1133,  1135,  1137,  1139,
    1141,  1143,  1145,  1147,  1150,  1154,  1155,  1158,  1161,  1163,
    1165,  1169,  1171,  1173,  1175,  1177,  1179,  1181,  1183,  1185,
    1187,  1189,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1212,  1215,  1218,  1221,  1224,  1227,  1230,  1233,
    1236,  1239,  1241,  1243,  1245,  1247,  1249,  1251,  1253,  1255,
    1257,  1259,  1263,  1267,  1274,  1275,  1278,  1286,  1287,  1290,
    1291,  1295,  1297,  1298,  1304,  1306,  1308,  1309,  1313,  1315,
    1318,  1320,  1323,  1326,  1330,  1332,  1333,  1339,  1341,  1344,
    1346,  1350,  1351,  1356,  1359,  1364,  1367,  1370,  1371,  1372,
    1378,  1379,  1380,  1386,  1387,  1388,  1394,  1395,  1398,  1399,
    1406,  1407,  1410,  1413,  1416,  1420,  1422,  1424,  1427,  1430,
    1432,  1435,  1440,  1442,  1447,  1450,  1451,  1454,  1456,  1458,
    1460,  1462,  1464,  1468,  1473,  1478,  1483,  1487,  1488,  1491,
    1492,  1498,  1499,  1502,  1504,  1506,  1508,  1510,  1512,  1514,
    1516,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,  1534,
    1538,  1540,  1542,  1545,  1547,  1550,  1552,  1554,  1555,  1558,
    1561,  1562,  1565,  1570,  1575,  1576,  1580,  1582,  1584,  1588,
    1595,  1598,  1602,  1605,  1608,  1612,  1615,  1617,  1620,  1623,
    1625,  1627,  1629,  1632,  1635,  1637,  1642,  1645,  1649,  1650,
    1651,  1657,  1658,  1660,  1663,  1667,  1669,  1670,  1675,  1679,
    1680,  1683,  1686,  1689,  1691,  1693,  1696,  1699,  1701,  1703,
    1705,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1724,  1726,
    1728,  1734,  1740,  1744,  1748,  1750,  1752,  1754,  1756,  1758,
    1760,  1762,  1764,  1767,  1770,  1773,  1775,  1777,  1779,  1781,
    1782,  1784,  1786,  1787,  1789,  1791,  1795,  1798,  1799,  1800,
    1801,  1811,  1812,  1817,  1818,  1819,  1823,  1824,  1828,  1830,
    1833,  1838,  1839,  1842,  1845,  1846,  1850,  1854,  1859,  1864,
    1868,  1869,  1871,  1872,  1875,  1876,  1877,  1885,  1886,  1889,
    1891,  1893,  1896,  1898,  1900,  1901,  1908,  1909,  1912,  1915,
    1917,  1918,  1920,  1921,  1922,  1926,  1927,  1930,  1933,  1935,
    1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,
    1957,  1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,  1975,
    1977,  1979,  1981,  1983,  1985,  1987,  1989,  1991,  1993,  1995,
    1997,  1999,  2001,  2003,  2005,  2007,  2009,  2011,  2013,  2015,
    2017,  2019,  2021,  2023,  2025,  2027,  2029,  2031,  2034,  2037,
    2038,  2043,  2050,  2054,  2058,  2063,  2067,  2072,  2076,  2080,
    2085,  2090,  2094,  2099,  2103,  2108,  2114,  2118,  2123,  2127,
    2131,  2133,  2135,  2137,  2140,  2141,  2143,  2147,  2151,  2154,
    2157,  2160,  2164,  2168,  2172,  2173,  2175,  2176,  2180,  2181,
    2184,  2186,  2189,  2191,  2193,  2195,  2197,  2199,  2201,  2203,
    2205,  2207,  2209,  2211,  2216,  2218,  2220,  2222,  2224,  2226,
    2228,  2230,  2234,  2238,  2242,  2246,  2250,  2251,  2253,  2254,
    2259,  2264,  2270,  2277,  2278,  2281,  2282,  2284,  2285,  2289,
    2293,  2298,  2299,  2302,  2303,  2307,  2309,  2312,  2317,  2318,
    2321,  2322,  2327,  2334,  2335,  2337,  2339,  2341,  2342,  2343,
    2347,  2349,  2352,  2355,  2359,  2360,  2363,  2366,  2369,  2370,
    2374,  2377,  2382,  2384,  2386,  2388,  2390,  2391,  2394,  2395,
    2398,  2399,  2401,  2402,  2406,  2408,  2411,  2412,  2416,  2419,
    2423,  2424,  2426,  2430,  2434,  2437,  2438,  2443,  2448,  2449,
    2451,  2453,  2455,  2456,  2461,  2465,  2468,  2470,  2473,  2474,
    2476,  2477,  2482,  2486,  2490,  2494,  2498,  2503,  2506,  2511,
    2513,  2514,  2518,  2524,  2525,  2528,  2531,  2534,  2537,  2538,
    2541,  2543,  2545,  2546,  2549,  2550,  2552,  2554,  2557,  2559,
    2562,  2565,  2567,  2569,  2572,  2575,  2577,  2579,  2581,  2583,
    2585,  2589,  2593,  2597,  2601,  2602,  2604,  2605,  2610,  2615,
    2622,  2629,  2638,  2647,  2648,  2650,  2651,  2655,  2658,  2659,
    2664,  2667,  2669,  2673,  2675,  2677,  2679,  2682,  2684,  2686,
    2689,  2692,  2696,  2699,  2703,  2705,  2709,  2712,  2714,  2716,
    2718,  2719,  2722,  2723,  2725,  2726,  2730,  2731,  2734,  2736,
    2739,  2741,  2743,  2745,  2746,  2749,  2750,  2754,  2756,  2757,
    2761,  2763,  2764,  2768,  2772,  2773,  2777,  2780,  2781,  2788,
    2792,  2795,  2797,  2798,  2800,  2801,  2805,  2811,  2812,  2815,
    2816,  2820,  2824,  2825,  2828,  2830,  2833,  2838,  2840,  2842,
    2844,  2846,  2848,  2850,  2852,  2853,  2857,  2858,  2862,  2864,
    2867,  2868,  2872,  2875,  2877,  2879,  2881,  2884,  2886,  2888,
    2890,  2891,  2895,  2898,  2904,  2906,  2909,  2912,  2915,  2917,
    2919,  2921,  2924,  2926,  2929,  2934,  2937,  2938,  2940,  2942,
    2944,  2946,  2951,  2952,  2955,  2959,  2963,  2964,  2968,  2969,
    2973,  2977,  2982,  2983,  2988,  2993,  3000,  3001,  3003,  3004,
    3008,  3013,  3019,  3021,  3023,  3025,  3027,  3028,  3032,  3035,
    3038,  3041,  3042,  3046,  3049,  3051,  3052,  3056,  3059,  3060,
    3065,  3068,  3069,  3071,  3073,  3075,  3077,  3081,  3082,  3085,
    3087,  3091,  3095,  3096,  3100,  3102,  3104,  3106,  3110,  3118,
    3119,  3124,  3132,  3133,  3136,  3137,  3140,  3143,  3147,  3151,
    3155,  3158,  3159,  3163,  3165,  3167,  3168,  3170,  3172,  3173,
    3177,  3180,  3182,  3183,  3188,  3193,  3194,  3196,  3197,  3202,
    3207,  3208,  3211,  3215,  3216,  3218,  3220,  3221,  3226,  3231,
    3238,  3239,  3242,  3243,  3246,  3248,  3251,  3255,  3256,  3258,
    3259,  3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,  3279,
    3281,  3283,  3288,  3292,  3294,  3297,  3300,  3303,  3306,  3309,
    3312,  3315,  3318,  3321,  3326,  3330,  3335,  3337,  3340,  3344,
    3346,  3349,  3353,  3357,  3358,  3362,  3363,  3371,  3372,  3378,
    3379,  3382,  3383,  3386,  3387,  3391,  3392,  3395,  3400,  3401,
    3404,  3409,  3410,  3415,  3420,  3421,  3425,  3426,  3431,  3433,
    3435,  3437,  3440,  3443,  3446,  3449,  3451,  3453,  3456,  3458,
    3459,  3461,  3462,  3467,  3470,  3471,  3474,  3479,  3484,  3485,
    3487,  3489,  3491,  3493,  3495,  3496,  3501,  3507,  3509,  3512,
    3514,  3518,  3522,  3523,  3528,  3529,  3531,  3532,  3537,  3542,
    3549,  3556,  3557,  3559,  3562,  3563,  3565,  3566,  3570,  3572,
    3575,  3576,  3580,  3586,  3587,  3591,  3594,  3595,  3597,  3599,
    3600,  3605,  3612,  3613,  3617,  3619,  3623,  3626,  3629,  3632,
    3636,  3637,  3641,  3642,  3646,  3647,  3651,  3652,  3654,  3655,
    3659,  3661,  3663,  3665,  3667,  3669,  3677,  3678,  3680,  3682,
    3684,  3686,  3688,  3690,  3695,  3697,  3700,  3702,  3705,  3709,
    3710,  3712,  3715,  3717,  3721,  3723,  3725,  3730,  3732,  3734,
    3736,  3737,  3742,  3748,  3749,  3752,  3753,  3758,  3762,  3766,
    3768,  3770,  3772,  3774,  3775,  3777,  3780,  3781,  3784,  3785,
    3788,  3791,  3792,  3795,  3796,  3799,  3802,  3803,  3806,  3807,
    3810,  3813,  3814,  3817,  3818,  3821,  3824,  3826,  3829,  3831,
    3833,  3836,  3839,  3842,  3844,  3846,  3849,  3852,  3855,  3856,
    3859,  3860,  3863,  3864,  3867,  3869,  3871,  3872,  3875,  3877,
    3880,  3883,  3885,  3887,  3889,  3891,  3893,  3895,  3897,  3899,
    3901,  3903,  3905,  3907,  3909,  3911,  3913,  3915,  3917,  3919,
    3921,  3923,  3925,  3927,  3929,  3931,  3933,  3936,  3938,  3940,
    3942,  3944,  3946,  3948,  3950,  3954,  3955,  3957,  3959,  3963,
    3967,  3969,  3973,  3977,  3979,  3983,  3985,  3988,  3991,  3993,
    3997,  3999,  4001,  4005,  4007,  4011,  4013,  4017,  4019,  4022,
    4025,  4027,  4029,  4031,  4034,  4036,  4038,  4040,  4043,  4045,
    4046,  4049,  4051,  4053,  4055,  4059,  4061,  4063,  4066,  4068,
    4070,  4072,  4075,  4077,  4079,  4081,  4083,  4085,  4087,  4089,
    4092,  4094,  4096,  4100,  4102,  4105,  4107,  4109,  4111,  4113,
    4116,  4119,  4122,  4127,  4131,  4133,  4135,  4138,  4140,  4142,
    4144,  4146,  4148,  4150,  4152,  4155,  4158,  4161,  4163,  4165,
    4167,  4169,  4171,  4173,  4175,  4177,  4179,  4181,  4183,  4185,
    4187,  4189,  4191,  4193,  4195,  4197,  4199,  4201,  4203,  4205,
    4207,  4209,  4211,  4213,  4216,  4218,  4222,  4225,  4228,  4230,
    4232,  4236,  4239,  4242,  4244,  4246,  4250,  4254,  4259,  4265,
    4267,  4269,  4271,  4273,  4275,  4277,  4279,  4281,  4283,  4285,
    4287,  4290,  4292,  4296,  4298,  4300,  4302,  4304,  4306,  4308,
    4310,  4313,  4319,  4325,  4331,  4336,  4342,  4348,  4354,  4357,
    4360,  4362,  4364,  4366,  4368,  4370,  4372,  4374,  4376,  4377,
    4382,  4388,  4389,  4393,  4396,  4398,  4402,  4406,  4408,  4412,
    4414,  4418,  4419,  4420,  4422,  4423,  4425,  4427,  4428,  4430,
    4431,  4434,  4435,  4438,  4439,  4441,  4443,  4444,  4446,  4447,
    4449,  4452,  4453,  4456,  4457,  4461,  4463,  4465,  4467,  4469,
    4471,  4473,  4475,  4477,  4478,  4481,  4483,  4485,  4487,  4489,
    4491,  4493,  4495,  4497,  4499,  4501,  4503,  4505,  4507,  4509,
    4511,  4513,  4515,  4517,  4519,  4521,  4523,  4525,  4527,  4529,
    4531,  4533,  4535,  4537,  4539,  4541,  4543,  4545,  4547,  4549,
    4551,  4553,  4555,  4557,  4559,  4561,  4563,  4565,  4567,  4569,
    4571,  4573,  4575,  4577,  4579,  4581,  4583,  4585,  4587,  4589,
    4591,  4593,  4595,  4597,  4599,  4601,  4603,  4605,  4607,  4609,
    4611,  4613,  4615,  4617,  4619,  4621,  4622,  4624,  4625,  4627,
    4628,  4630,  4631,  4633,  4634,  4636,  4637,  4639,  4640,  4642,
    4643,  4645,  4646,  4648,  4649,  4651,  4652,  4654,  4655,  4657,
    4658,  4660,  4661,  4663,  4664,  4666,  4667,  4669,  4670,  4672,
    4673,  4675,  4678,  4679,  4681,  4682,  4684,  4685,  4687,  4688,
    4690,  4691,  4693,  4695,  4696,  4698,  4699,  4701,  4703,  4704,
    4706,  4708,  4709,  4712,  4715,  4716,  4718,  4719,  4721,  4722,
    4724,  4725,  4727,  4729,  4730,  4732,  4733,  4735,  4736,  4739,
    4741,  4743,  4744,  4746,  4747,  4749,  4750,  4752,  4753,  4755,
    4756,  4758,  4759,  4761,  4762,  4764,  4765,  4767,  4770,  4771,
    4773,  4774,  4776,  4777,  4779,  4780,  4782,  4783,  4785,  4786,
    4788,  4789,  4791,  4792,  4794,  4796,  4797,  4799,  4800,  4804,
    4805,  4807,  4808,  4810,  4813,  4815,  4817,  4819,  4821,  4823,
    4825,  4827,  4829,  4831,  4833,  4835,  4837,  4839,  4841,  4843,
    4845,  4847,  4849,  4851,  4853,  4855,  4858,  4861,  4863,  4865,
    4867,  4869,  4871,  4873,  4876,  4878,  4882,  4885,  4889,  4892,
    4894,  4896,  4898,  4901,  4903,  4906,  4908,  4911,  4913,  4916,
    4918,  4921,  4923,  4926,  4928,  4931
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
      -1,   540,   541,   542,   604,   605,   607,   606,   643,   529,
     653,   654,   655,   530,   684,   737,   739,   741,   786,   531,
     800,    -1,    -1,   341,   451,   535,   536,   533,   537,   451,
      -1,   200,   451,   535,   536,   451,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1273,   538,  1288,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1304,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1273,  1222,  1316,    -1,  1323,
    1273,  1188,    -1,   396,  1273,  1222,    -1,  1260,    59,  1273,
     557,    -1,  1188,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   585,    -1,
     595,    -1,   592,    -1,   596,    -1,   598,    -1,   599,    -1,
     600,    -1,   601,    -1,   602,    -1,   603,    -1,    -1,   504,
     572,   573,    -1,  1273,    96,    -1,  1222,  1273,  1193,    -1,
    1273,  1193,   574,    -1,   575,    -1,    -1,   575,    -1,  1037,
    1285,  1193,    -1,   575,  1037,  1285,  1193,    -1,    -1,    11,
    1193,   577,  1273,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   416,    -1,   510,    -1,   587,   586,    -1,    -1,
     218,   504,    -1,   433,  1261,   588,    -1,   589,    -1,   588,
     589,    -1,   590,  1274,   591,    -1,  1194,    -1,   590,  1194,
      -1,  1223,    -1,   591,  1223,    -1,    58,  1193,  1273,   593,
      -1,   594,    -1,   593,   594,    -1,  1225,    -1,  1225,   442,
    1225,    -1,   257,  1193,  1273,   256,    -1,    98,  1291,  1273,
     256,   597,    -1,    -1,  1304,   328,   256,    -1,   108,  1273,
      68,    -1,   301,   405,  1273,   468,   400,    -1,   100,  1273,
    1187,    -1,    96,   423,  1273,  1187,    -1,   390,  1273,  1187,
      -1,   164,  1273,  1187,    -1,    -1,   226,   394,   451,    -1,
      -1,   173,   451,    -1,    -1,   234,   451,    -1,    -1,   607,
     608,    -1,    -1,   397,  1246,  1193,   609,   610,   451,    -1,
     397,     1,   451,    -1,    -1,   610,   611,    -1,   612,    -1,
     618,    -1,   620,    -1,   622,    -1,   623,    -1,   625,    -1,
     629,    -1,   631,    -1,   632,    -1,   633,    -1,   638,    -1,
     639,    -1,   641,    -1,    29,  1301,   615,   614,   616,    -1,
      29,  1301,   615,   613,   617,    -1,    29,  1301,   615,   119,
     617,    -1,    29,  1301,   615,   238,   617,    -1,    29,  1301,
     615,   335,   617,    -1,   117,    -1,   118,    -1,   437,    -1,
     347,    -1,    -1,   252,     7,  1264,    -1,    -1,   171,    -1,
     125,    -1,   256,    -1,  1219,    -1,    -1,   256,    -1,  1219,
      -1,     4,  1280,  1273,   619,    -1,   402,    -1,   125,    -1,
     347,    -1,    19,  1305,  1275,  1273,  1187,  1240,   621,    -1,
      19,  1305,  1275,  1273,  1187,   634,   635,  1240,   621,    -1,
      -1,   432,   501,     9,  1226,    -1,   432,   501,   584,    -1,
    1306,  1273,   504,    -1,   624,   423,  1273,  1187,    -1,    -1,
     454,    -1,   412,    -1,    -1,   626,   262,  1280,  1273,   627,
      -1,   267,   628,    -1,    33,   628,    -1,   167,    -1,    -1,
     503,   262,   309,  1315,    -1,   503,   262,   309,   274,  1315,
      -1,   503,   385,    -1,   315,  1273,   630,    -1,   630,    -1,
     220,    -1,  1289,  1258,   402,    -1,   359,    -1,   252,   402,
      -1,   320,  1260,  1273,  1192,    -1,   351,   113,  1273,   419,
      -1,   351,  1275,  1273,  1187,    -1,   351,  1275,  1273,  1187,
     634,   635,    -1,   452,    -1,   414,  1273,    -1,    -1,   636,
     637,    -1,   635,   637,    -1,  1187,    -1,   359,  1275,  1273,
    1191,    -1,   372,   640,  1255,    -1,   287,    -1,  1222,    -1,
     404,  1304,   642,    -1,     9,  1286,    -1,   287,  1286,    -1,
     349,   310,    -1,    -1,   644,   451,    -1,   644,     1,   451,
      -1,   645,    -1,   644,   645,    -1,   646,    -1,   648,    -1,
     388,   647,  1255,  1266,  1177,    -1,    -1,   351,    -1,   412,
      -1,   413,    -1,    -1,   274,   649,  1264,  1297,  1262,   650,
      -1,   651,    -1,   650,   651,    -1,  1178,   652,    -1,    -1,
     331,  1222,    -1,    -1,   102,   122,   451,    -1,    -1,   454,
     394,   451,    -1,    -1,   655,   656,    -1,   657,   686,    -1,
      -1,   659,  1178,   658,   660,   451,    -1,   659,     1,   451,
      -1,   172,    -1,   392,    -1,    -1,   660,   661,    -1,  1273,
     171,    -1,  1273,   204,    -1,   662,    -1,   664,    -1,   668,
      -1,   669,    -1,   672,    -1,   673,    -1,   679,    -1,   680,
      -1,   681,    -1,    47,  1262,  1222,   667,   663,    -1,    -1,
     353,    -1,    57,    -1,   351,  1262,  1222,  1261,    -1,   351,
    1262,  1222,   446,  1222,  1261,    -1,   351,  1273,   499,  1268,
    1294,   666,   667,  1261,   665,    -1,    -1,   114,  1284,  1187,
      -1,    -1,  1267,  1222,    -1,    -1,   446,  1222,    -1,   239,
    1317,  1313,    -1,   498,   306,   670,  1273,   671,    -1,   498,
     306,   174,  1273,   671,    -1,   504,    -1,   213,    -1,   256,
      -1,  1219,    -1,   102,  1317,  1189,    -1,   250,  1273,  1192,
    1279,   674,    -1,    -1,   674,   675,    -1,   676,    -1,   677,
      -1,   678,    -1,  1304,   187,  1257,  1192,    -1,   465,  1192,
      -1,    48,  1192,    -1,   352,  1280,  1273,   504,    -1,    62,
    1273,   504,    -1,   682,   683,    -1,   366,  1273,    -1,   368,
    1254,    -1,  1193,    -1,   683,  1193,    -1,    -1,    -1,   506,
     394,   451,   685,   686,    -1,    -1,    -1,   687,   688,    -1,
     689,   451,    -1,   688,   689,   451,    -1,   688,   451,    -1,
     701,    -1,    -1,   691,   692,   690,   703,    -1,   691,     1,
     451,    -1,  1238,   504,    -1,    -1,   175,    -1,   504,    -1,
     504,    -1,    -1,  1273,   204,    -1,  1226,    -1,   245,   696,
      -1,   244,   696,    -1,    50,  1283,   696,    -1,  1216,    -1,
      41,    -1,    44,    -1,    43,    -1,    42,    -1,    40,    -1,
     700,    -1,   712,    -1,   713,    -1,   697,    -1,   698,    -1,
     699,    -1,     1,   451,    -1,   179,    -1,   183,    -1,   180,
      -1,   181,    -1,   178,    -1,   182,    -1,   184,    -1,   330,
      -1,   343,    -1,   691,   693,    85,   694,   702,    -1,  1256,
     695,    -1,   196,   504,    -1,    -1,   703,   704,    -1,   705,
      -1,   706,    -1,   708,    -1,   709,    -1,   710,    -1,   714,
      -1,   717,    -1,   726,    -1,   727,    -1,   728,    -1,   729,
      -1,   730,    -1,   735,    -1,   736,    -1,   355,  1216,    -1,
    1273,   171,   707,    -1,    -1,    26,   256,    -1,  1273,   204,
      -1,   327,    -1,   711,    -1,   491,  1273,   711,    -1,    39,
      -1,    73,    -1,   712,    -1,   713,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,   119,    -1,   219,
      -1,   319,    -1,   330,    -1,   343,    -1,   409,    -1,   407,
      -1,   408,    -1,   479,    -1,   477,    -1,   478,    -1,    41,
    1292,    -1,    41,   476,    -1,    44,  1292,    -1,    44,   476,
      -1,    43,  1292,    -1,    43,   476,    -1,    42,  1292,    -1,
      42,   476,    -1,    40,  1292,    -1,    40,   476,    -1,   179,
      -1,   180,    -1,   178,    -1,   181,    -1,   182,    -1,   277,
      -1,    75,    -1,   186,    -1,    76,    -1,   185,    -1,  1293,
     241,  1250,    -1,  1293,   468,  1250,    -1,   305,  1222,   718,
    1299,   719,   716,    -1,    -1,   425,  1222,    -1,   305,  1222,
     718,  1299,   719,   720,   723,    -1,    -1,   446,  1222,    -1,
      -1,   114,  1284,  1187,    -1,   721,    -1,    -1,   721,   722,
    1275,  1273,  1186,    -1,    27,    -1,   115,    -1,    -1,   220,
    1259,   724,    -1,   725,    -1,   724,   725,    -1,   504,    -1,
     235,  1290,    -1,   434,  1276,    -1,    45,  1302,   510,    -1,
      36,    -1,    -1,   498,  1274,   732,   731,   734,    -1,   733,
      -1,   732,   733,    -1,  1226,    -1,  1226,   442,  1226,    -1,
      -1,  1303,   453,  1273,  1226,    -1,   363,  1219,    -1,   363,
    1219,   442,  1219,    -1,    21,   244,    -1,    21,   301,    -1,
      -1,    -1,   261,   394,   451,   738,   686,    -1,    -1,    -1,
     255,   394,   451,   740,   686,    -1,    -1,    -1,   366,   394,
     451,   742,   743,    -1,    -1,   743,   744,    -1,    -1,   348,
    1179,   745,   746,   451,   760,    -1,    -1,   746,   747,    -1,
       1,   451,    -1,  1273,   204,    -1,    61,  1273,  1206,    -1,
     748,    -1,   751,    -1,  1331,   749,    -1,  1265,   750,    -1,
    1215,    -1,   750,  1215,    -1,   321,  1278,   752,   753,    -1,
    1224,    -1,  1224,  1314,  1224,  1308,    -1,  1224,  1314,    -1,
      -1,   753,   754,    -1,   755,    -1,   756,    -1,   757,    -1,
     758,    -1,   759,    -1,   210,  1273,  1224,    -1,   177,  1324,
    1273,  1224,    -1,   240,  1325,  1273,  1224,    -1,   240,  1324,
    1273,  1224,    -1,   187,  1273,  1224,    -1,    -1,   760,   761,
      -1,    -1,   691,   692,   762,   763,   451,    -1,    -1,   763,
     764,    -1,   765,    -1,   769,    -1,   775,    -1,   709,    -1,
     785,    -1,   714,    -1,   726,    -1,   777,    -1,   728,    -1,
     783,    -1,   770,    -1,   730,    -1,   773,    -1,   784,    -1,
     715,    -1,   774,    -1,   472,  1273,   766,    -1,  1329,    -1,
    1327,    -1,  1325,   767,    -1,  1324,    -1,  1326,   767,    -1,
    1328,    -1,  1330,    -1,    -1,  1215,   768,    -1,   176,   768,
      -1,    -1,   313,   321,    -1,   285,   209,  1273,   780,    -1,
     431,  1283,  1199,   771,    -1,    -1,   373,  1284,   772,    -1,
    1215,    -1,   176,    -1,   333,   501,  1154,    -1,   499,  1215,
     196,  1201,    49,  1201,    -1,   776,   779,    -1,   252,  1282,
    1274,    -1,   254,  1254,    -1,   778,   781,    -1,  1307,  1282,
    1274,    -1,  1308,  1254,    -1,   780,    -1,   779,   780,    -1,
     329,  1222,    -1,  1224,    -1,   286,    -1,   782,    -1,   781,
     782,    -1,   329,  1222,    -1,  1224,    -1,   414,  1273,  1201,
    1247,    -1,   209,  1270,    -1,   491,  1273,   119,    -1,    -1,
      -1,   389,   394,   451,   787,   788,    -1,    -1,   789,    -1,
     790,   451,    -1,   789,   790,   451,    -1,   701,    -1,    -1,
     691,   692,   791,   792,    -1,   691,     1,   451,    -1,    -1,
     792,   793,    -1,    45,   252,    -1,    45,   389,    -1,    38,
      -1,    46,    -1,   160,   156,    -1,   160,   158,    -1,   211,
      -1,   265,    -1,   378,    -1,   473,    -1,   318,    -1,   243,
      -1,    32,    -1,   395,    -1,   371,    -1,   198,    -1,   345,
      56,  1273,  1206,    -1,   345,    -1,   456,    -1,   252,  1281,
    1273,   796,  1208,    -1,  1307,  1281,  1273,   797,  1208,    -1,
     189,  1273,  1208,    -1,    35,  1273,  1208,    -1,   710,    -1,
     728,    -1,   799,    -1,   726,    -1,   714,    -1,   730,    -1,
     709,    -1,   798,    -1,   497,  1215,    -1,   196,  1207,    -1,
     446,  1215,    -1,   329,    -1,   463,    -1,   270,    -1,   458,
      -1,    -1,   794,    -1,   795,    -1,    -1,   794,    -1,   795,
      -1,   305,  1222,  1299,    -1,  1273,   204,    -1,    -1,    -1,
      -1,   337,   122,   804,   812,   451,   801,   813,   802,   815,
      -1,    -1,   803,   826,   451,   815,    -1,    -1,    -1,   497,
     805,   807,    -1,    -1,    55,   806,   807,    -1,   808,    -1,
     807,   808,    -1,   809,   810,   811,   504,    -1,    -1,  1259,
     357,    -1,  1259,   498,    -1,    -1,   410,  1273,    32,    -1,
     410,  1273,   110,    -1,   476,   410,  1273,    32,    -1,   476,
     410,  1273,  1222,    -1,   410,  1273,  1222,    -1,    -1,   312,
      -1,    -1,   376,   504,    -1,    -1,    -1,   109,   451,   814,
     815,   129,   109,   451,    -1,    -1,   815,   816,    -1,   817,
      -1,   820,    -1,   826,   451,    -1,   821,    -1,   451,    -1,
      -1,   504,   394,   822,   451,   818,   819,    -1,    -1,  1108,
     451,    -1,   504,   451,    -1,   504,    -1,    -1,  1222,    -1,
      -1,    -1,   824,   825,   826,    -1,    -1,   827,   828,    -1,
     826,   828,    -1,   829,    -1,   844,    -1,   849,    -1,   853,
      -1,   858,    -1,   873,    -1,   876,    -1,   884,    -1,   880,
      -1,   885,    -1,   886,    -1,   891,    -1,   905,    -1,   909,
      -1,   912,    -1,   926,    -1,   930,    -1,   933,    -1,   936,
      -1,   940,    -1,   941,    -1,   945,    -1,   955,    -1,   958,
      -1,   975,    -1,   977,    -1,   980,    -1,   984,    -1,   991,
      -1,  1003,    -1,  1011,    -1,  1012,    -1,  1015,    -1,  1016,
      -1,  1020,    -1,  1025,    -1,  1026,    -1,  1034,    -1,  1049,
      -1,  1059,    -1,  1068,    -1,  1073,    -1,  1080,    -1,  1084,
      -1,  1086,    -1,  1089,    -1,  1092,    -1,  1096,    -1,  1123,
      -1,   285,   399,    -1,     1,  1251,    -1,    -1,     3,   830,
     831,   843,    -1,   832,   834,   838,   839,   840,  1131,    -1,
    1215,   196,   833,    -1,  1215,   196,  1308,    -1,  1215,   196,
     103,   509,    -1,  1215,   196,   103,    -1,  1215,   196,   104,
     508,    -1,  1215,   196,   104,    -1,  1215,   196,   105,    -1,
    1215,   196,   162,   237,    -1,  1215,   196,   165,   423,    -1,
    1215,   196,   443,    -1,  1215,   196,   493,   276,    -1,  1215,
     196,    69,    -1,  1215,   196,   155,  1131,    -1,  1215,   196,
     153,  1204,  1131,    -1,  1215,   196,    24,    -1,  1215,   196,
      25,  1131,    -1,  1215,   196,  1181,    -1,  1215,   196,   504,
      -1,  1215,    -1,   308,    -1,   254,    -1,   252,   299,    -1,
      -1,   835,    -1,  1257,   836,   837,    -1,  1257,   837,   836,
      -1,  1257,   836,    -1,  1257,   837,    -1,    30,  1204,    -1,
     252,  1281,  1208,    -1,  1307,  1281,  1208,    -1,   331,  1281,
    1208,    -1,    -1,   197,    -1,    -1,   272,  1273,    47,    -1,
      -1,   503,   841,    -1,   842,    -1,   841,   842,    -1,    32,
      -1,    38,    -1,    46,    -1,    91,    -1,   198,    -1,   211,
      -1,   243,    -1,   263,    -1,   265,    -1,   288,    -1,   318,
      -1,   345,    56,  1273,  1206,    -1,   345,    -1,   371,    -1,
     378,    -1,   395,    -1,   473,    -1,   483,    -1,   489,    -1,
     189,  1273,  1208,    -1,    35,  1273,  1208,    -1,   391,   482,
    1153,    -1,   391,   123,  1153,    -1,   444,  1253,  1209,    -1,
      -1,   130,    -1,    -1,     5,   845,   846,   848,    -1,  1197,
     446,  1173,  1137,    -1,  1197,   847,   203,  1173,  1137,    -1,
      94,  1215,   446,  1215,  1247,  1137,    -1,    -1,   446,  1198,
      -1,    -1,   131,    -1,    -1,    10,   850,   851,    -1,  1215,
    1241,   852,    -1,  1167,    57,  1242,   852,    -1,    -1,   376,
    1196,    -1,    -1,    18,   854,   855,    -1,   856,    -1,   855,
     856,    -1,  1183,   446,   857,  1183,    -1,    -1,   339,   446,
      -1,    -1,    51,   859,   860,   872,    -1,   861,  1207,   862,
     867,   870,   871,    -1,    -1,   422,    -1,   424,    -1,   271,
      -1,    -1,    -1,   497,   863,   864,    -1,   865,    -1,   864,
     865,    -1,   866,   308,    -1,   866,   810,  1198,    -1,    -1,
    1259,   357,    -1,  1259,    87,    -1,  1259,   498,    -1,    -1,
     868,  1272,  1215,    -1,   868,   869,    -1,   868,     6,  1283,
    1215,    -1,   376,    -1,   203,    -1,   460,    -1,   308,    -1,
      -1,  1311,   823,    -1,    -1,   294,   823,    -1,    -1,   132,
      -1,    -1,    52,   874,   875,    -1,  1206,    -1,   875,  1206,
      -1,    -1,    60,   877,   878,    -1,  1178,   879,    -1,   878,
    1178,   879,    -1,    -1,  1318,    -1,  1318,  1266,   362,    -1,
    1304,   287,   380,    -1,  1304,   262,    -1,    -1,    74,   881,
     882,   883,    -1,  1173,  1309,  1167,  1137,    -1,    -1,   133,
      -1,    71,    -1,    88,    -1,    -1,   111,   887,   888,   890,
      -1,  1178,  1289,  1150,    -1,   454,   889,    -1,  1178,    -1,
     889,  1178,    -1,    -1,   134,    -1,    -1,   119,   892,   893,
     904,    -1,  1206,   487,  1134,    -1,  1206,   488,  1134,    -1,
    1206,   485,  1134,    -1,  1206,   486,  1134,    -1,  1197,   897,
     901,  1134,    -1,   894,  1134,    -1,  1198,   503,   902,  1134,
      -1,   896,    -1,    -1,   894,   895,   896,    -1,  1198,   835,
     898,   839,   900,    -1,    -1,   484,  1181,    -1,   484,   504,
      -1,   484,   335,    -1,   484,    96,    -1,    -1,   484,   899,
      -1,    96,    -1,    97,    -1,    -1,   503,   902,    -1,    -1,
     298,    -1,   903,    -1,   902,   903,    -1,    38,    -1,    45,
     252,    -1,    45,   389,    -1,    46,    -1,    91,    -1,   160,
     156,    -1,   160,   158,    -1,   211,    -1,   265,    -1,   318,
      -1,   378,    -1,   473,    -1,   189,  1273,  1208,    -1,    35,
    1273,  1208,    -1,   391,   482,  1153,    -1,   391,   123,  1153,
      -1,    -1,   135,    -1,    -1,   121,   906,   907,   908,    -1,
    1198,   228,  1173,  1137,    -1,  1198,   228,  1198,   203,  1173,
    1137,    -1,  1198,    49,  1198,   203,  1173,  1137,    -1,  1198,
     228,  1198,   203,  1174,   361,  1174,  1137,    -1,  1198,    49,
    1198,   203,  1174,   361,  1174,  1137,    -1,    -1,   136,    -1,
      -1,   152,   910,   911,    -1,   256,   862,    -1,    -1,   163,
     913,   914,   925,    -1,   915,   917,    -1,   916,    -1,   915,
      17,   916,    -1,  1155,    -1,   464,    -1,   453,    -1,   918,
     920,    -1,   918,    -1,   919,    -1,   918,   919,    -1,   921,
     823,    -1,   501,   316,   823,    -1,   501,   922,    -1,   921,
     501,   922,    -1,   923,    -1,   922,    17,   923,    -1,  1156,
     924,    -1,    21,    -1,   464,    -1,   453,    -1,    -1,   442,
    1155,    -1,    -1,   137,    -1,    -1,   168,   927,   928,    -1,
      -1,   340,   929,    -1,   199,    -1,   324,   101,    -1,   324,
      -1,   394,    -1,   323,    -1,    -1,   868,  1198,    -1,    -1,
     195,   931,   932,    -1,  1195,    -1,    -1,   202,   934,   935,
      -1,  1219,    -1,    -1,   205,   937,   938,    -1,  1300,  1182,
     939,    -1,    -1,   114,  1284,  1215,    -1,   206,   929,    -1,
      -1,   215,   942,  1154,  1298,   943,   944,    -1,   823,   128,
     823,    -1,   128,   823,    -1,   823,    -1,    -1,   139,    -1,
      -1,   222,   946,   947,    -1,  1195,   948,   949,   950,   954,
      -1,    -1,  1304,   175,    -1,    -1,     9,  1300,   498,    -1,
     953,  1300,   498,    -1,    -1,   365,   951,    -1,   952,    -1,
     951,   952,    -1,   953,  1263,    49,  1198,    -1,    12,    -1,
      15,    -1,   301,    -1,    16,    -1,   302,    -1,   277,    -1,
     278,    -1,    -1,  1298,  1300,   110,    -1,    -1,   224,   956,
     957,    -1,  1179,    -1,   957,  1179,    -1,    -1,   227,   959,
     960,    -1,   961,   962,    -1,  1215,    -1,  1226,    -1,  1229,
      -1,   963,   965,    -1,   963,    -1,   965,    -1,   966,    -1,
      -1,   436,   964,   967,    -1,   365,   969,    -1,    92,  1204,
     446,  1205,   973,    -1,   968,    -1,   967,   968,    -1,  1204,
     188,    -1,    57,   973,    -1,     9,    -1,   241,    -1,   468,
      -1,  1204,   973,    -1,   970,    -1,   969,   970,    -1,    57,
      49,  1204,   973,    -1,   971,   972,    -1,    -1,     9,    -1,
     241,    -1,   177,    -1,   468,    -1,  1204,    49,  1205,   973,
      -1,    -1,   973,   974,    -1,    37,  1271,  1198,    -1,     8,
    1271,  1198,    -1,    -1,   269,   976,  1051,    -1,    -1,   273,
     978,   979,    -1,  1198,   446,  1195,    -1,    94,  1198,   446,
    1195,    -1,    -1,   275,   981,   982,   983,    -1,  1198,    49,
    1173,  1137,    -1,  1198,    49,  1198,   203,  1173,  1137,    -1,
      -1,   140,    -1,    -1,   311,   985,   986,    -1,   987,   988,
    1177,   990,    -1,   986,   987,   988,  1177,   990,    -1,   225,
      -1,   317,    -1,   233,    -1,   170,    -1,    -1,   404,  1304,
     989,    -1,     9,  1286,    -1,   287,  1286,    -1,   349,   310,
      -1,    -1,  1304,   287,   380,    -1,  1304,   262,    -1,   379,
      -1,    -1,   324,   992,   993,    -1,   997,   998,    -1,    -1,
     998,   994,   823,   995,    -1,   998,   996,    -1,    -1,   141,
      -1,   141,    -1,   451,    -1,  1183,    -1,  1183,   442,  1183,
      -1,    -1,  1207,   445,    -1,   190,    -1,   999,   481,  1000,
      -1,   999,   499,  1001,    -1,    -1,  1304,   439,  1128,    -1,
     168,    -1,  1154,    -1,  1002,    -1,  1001,     8,  1002,    -1,
    1215,   196,  1198,    49,  1198,   481,  1154,    -1,    -1,   349,
    1004,  1005,  1010,    -1,  1178,  1244,  1289,  1006,  1007,  1008,
    1009,    -1,    -1,   228,  1215,    -1,    -1,   217,   262,    -1,
    1304,   262,    -1,  1304,   236,   262,    -1,  1304,   287,   262,
      -1,  1304,   216,   262,    -1,  1304,   500,    -1,    -1,   237,
    1273,  1215,    -1,  1150,    -1,  1144,    -1,    -1,   143,    -1,
     350,    -1,    -1,   360,  1013,  1014,    -1,  1175,  1126,    -1,
     374,    -1,    -1,   375,  1017,  1018,  1019,    -1,  1178,  1289,
    1006,  1143,    -1,    -1,   144,    -1,    -1,   381,  1021,  1022,
    1024,    -1,  1175,  1126,  1023,  1150,    -1,    -1,  1304,   262,
      -1,  1304,   287,   262,    -1,    -1,   145,    -1,   385,    -1,
      -1,   393,  1027,  1028,  1033,    -1,  1176,  1029,  1030,  1031,
      -1,     9,  1176,  1030,   501,  1155,   823,    -1,    -1,   499,
    1215,    -1,    -1,   129,   823,    -1,  1032,    -1,  1032,  1031,
      -1,   501,  1154,   823,    -1,    -1,   146,    -1,    -1,   403,
    1035,  1036,    -1,  1039,    -1,  1040,    -1,  1043,    -1,  1044,
      -1,  1045,    -1,  1047,    -1,   309,    -1,   307,    -1,   482,
      -1,   123,    -1,   153,  1204,   446,  1204,    -1,  1212,    31,
    1041,    -1,  1042,    -1,  1041,  1042,    -1,    38,  1037,    -1,
      46,  1037,    -1,   211,  1037,    -1,   265,  1037,    -1,   378,
    1037,    -1,   473,  1037,    -1,   243,  1037,    -1,   318,  1037,
      -1,  1195,   446,   152,  1203,    -1,  1195,   446,  1198,    -1,
    1195,  1038,    49,  1198,    -1,  1046,    -1,  1045,  1046,    -1,
    1180,   446,  1037,    -1,  1048,    -1,  1047,  1048,    -1,  1195,
     446,   464,    -1,  1195,   446,   453,    -1,    -1,   412,  1050,
    1051,    -1,    -1,  1213,  1053,  1055,  1056,  1052,  1057,  1058,
      -1,    -1,  1053,  1284,   722,  1275,  1054,    -1,    -1,  1054,
    1219,    -1,    -1,  1321,  1269,    -1,    -1,  1306,  1273,  1187,
      -1,    -1,   497,  1177,    -1,   225,   337,  1273,   997,    -1,
      -1,   203,  1177,    -1,   317,   337,  1273,   997,    -1,    -1,
     421,  1060,  1061,  1067,    -1,  1178,  1063,  1062,  1150,    -1,
      -1,  1304,  1320,  1167,    -1,    -1,   237,  1273,  1064,  1215,
      -1,   177,    -1,   240,    -1,  1160,    -1,  1245,  1161,    -1,
    1245,  1162,    -1,  1245,  1163,    -1,  1245,  1164,    -1,  1065,
      -1,  1066,    -1,   290,  1160,    -1,   293,    -1,    -1,   147,
      -1,    -1,   426,   387,  1069,  1070,    -1,   426,  1072,    -1,
      -1,   868,  1198,    -1,  1304,   161,  1296,  1071,    -1,  1304,
     289,  1296,  1071,    -1,    -1,  1198,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,    -1,   427,  1074,  1075,  1079,
      -1,  1076,   228,  1215,  1078,  1140,    -1,  1077,    -1,  1076,
    1077,    -1,  1198,    -1,   112,  1259,   410,    -1,   112,  1259,
    1198,    -1,    -1,  1304,   330,  1273,  1215,    -1,    -1,   148,
      -1,    -1,   430,  1081,  1082,  1083,    -1,  1197,   196,  1173,
    1137,    -1,  1197,   196,  1198,   203,  1173,  1137,    -1,    94,
    1215,   196,  1215,  1247,  1137,    -1,    -1,   149,    -1,   432,
    1085,    -1,    -1,   336,    -1,    -1,   438,  1087,  1088,    -1,
    1179,    -1,  1088,  1179,    -1,    -1,   469,  1090,  1091,    -1,
    1215,   196,  1204,   446,  1205,    -1,    -1,   475,  1093,  1094,
      -1,  1178,  1095,    -1,    -1,   351,    -1,   353,    -1,    -1,
     480,  1097,  1098,  1107,    -1,  1215,  1099,  1102,  1078,  1106,
    1140,    -1,    -1,   112,  1259,  1100,    -1,  1101,    -1,  1100,
     313,  1101,    -1,  1239,  1204,    -1,   228,  1103,    -1,  1102,
    1103,    -1,  1215,  1104,  1105,    -1,    -1,   113,  1268,  1215,
      -1,    -1,    95,  1268,  1215,    -1,    -1,   436,  1268,  1215,
      -1,    -1,   150,    -1,    -1,   492,  1109,  1110,    -1,  1111,
      -1,  1114,    -1,  1118,    -1,  1120,    -1,  1121,    -1,  1112,
    1253,  1295,  1310,  1287,  1284,  1113,    -1,    -1,   204,    -1,
    1177,    -1,   225,    -1,   317,    -1,   233,    -1,   170,    -1,
    1266,   107,  1284,  1115,    -1,  1116,    -1,  1115,  1116,    -1,
    1184,    -1,     9,   338,    -1,     9,  1117,  1219,    -1,    -1,
     358,    -1,   358,   306,    -1,   306,    -1,  1257,   340,  1119,
      -1,   421,    -1,   129,    -1,  1112,    37,   367,  1215,    -1,
    1122,    -1,   166,    -1,   127,    -1,    -1,   507,  1124,  1125,
    1130,    -1,  1175,  1126,  1127,  1023,  1129,    -1,    -1,   196,
    1211,    -1,    -1,  1128,  1252,  1208,  1277,    -1,  1128,  1252,
    1181,    -1,  1128,  1252,   321,    -1,    37,    -1,     8,    -1,
    1150,    -1,  1147,    -1,    -1,   151,    -1,  1132,  1133,    -1,
      -1,   165,   823,    -1,    -1,   294,   823,    -1,  1135,  1136,
      -1,    -1,   165,   823,    -1,    -1,   294,   823,    -1,  1138,
    1139,    -1,    -1,   411,   823,    -1,    -1,   297,   823,    -1,
    1141,  1142,    -1,    -1,   461,   823,    -1,    -1,   296,   823,
      -1,  1145,  1146,    -1,  1145,    -1,  1145,  1146,    -1,  1145,
      -1,  1146,    -1,   129,   823,    -1,   291,   823,    -1,  1148,
    1149,    -1,  1148,    -1,  1149,    -1,   157,   823,    -1,   292,
     823,    -1,  1151,  1152,    -1,    -1,   231,   823,    -1,    -1,
     295,   823,    -1,    -1,  1210,  1319,    -1,  1155,    -1,  1156,
      -1,    -1,  1157,  1158,    -1,  1159,    -1,  1158,   232,    -1,
    1158,  1159,    -1,  1198,    -1,   462,    -1,   448,    -1,   463,
      -1,   458,    -1,   459,    -1,   450,    -1,   169,    -1,  1160,
      -1,  1161,    -1,  1162,    -1,  1163,    -1,  1164,    -1,   293,
      -1,   290,    -1,    20,    -1,   313,    -1,   308,    -1,   301,
      -1,    12,    -1,    13,    -1,    14,    -1,   332,    -1,   284,
      -1,   452,    -1,   159,  1300,    -1,   455,    -1,   207,    -1,
     457,    -1,   246,    -1,   208,    -1,   247,    -1,  1167,    -1,
    1165,  1166,  1167,    -1,    -1,    70,    -1,   398,    -1,  1167,
     463,  1168,    -1,  1167,   458,  1168,    -1,  1168,    -1,  1168,
     459,  1169,    -1,  1168,   450,  1169,    -1,  1169,    -1,  1170,
     169,  1169,    -1,  1170,    -1,   463,  1171,    -1,   458,  1171,
      -1,  1171,    -1,   462,  1167,   448,    -1,  1201,    -1,   251,
      -1,   251,  1312,   504,    -1,   253,    -1,   253,  1312,   504,
      -1,   322,    -1,   322,  1312,   504,    -1,  1174,    -1,  1173,
    1174,    -1,  1196,  1247,    -1,  1219,    -1,  1219,    -1,  1178,
      -1,  1177,  1178,    -1,   504,    -1,   504,    -1,  1181,    -1,
    1180,  1181,    -1,   271,    -1,    -1,  1182,  1183,    -1,  1184,
      -1,  1219,    -1,  1185,    -1,  1185,  1312,  1185,    -1,   256,
      -1,  1187,    -1,  1186,  1187,    -1,  1219,    -1,   504,    -1,
    1190,    -1,  1189,  1190,    -1,   504,    -1,   504,    -1,  1187,
      -1,   256,    -1,   504,    -1,   504,    -1,  1196,    -1,  1195,
    1196,    -1,  1217,    -1,  1227,    -1,     6,  1283,  1216,    -1,
    1198,    -1,  1197,  1198,    -1,  1215,    -1,  1226,    -1,  1229,
      -1,  1172,    -1,   245,  1216,    -1,   245,  1227,    -1,   245,
    1229,    -1,     6,  1283,  1202,  1203,    -1,     6,  1283,  1216,
      -1,   271,    -1,  1201,    -1,  1199,  1201,    -1,  1215,    -1,
    1227,    -1,  1229,    -1,  1215,    -1,  1227,    -1,  1229,    -1,
    1172,    -1,   245,  1216,    -1,   245,  1227,    -1,   245,  1229,
      -1,   340,    -1,   152,    -1,  1216,    -1,   256,    -1,  1215,
      -1,  1227,    -1,  1215,    -1,  1226,    -1,  1215,    -1,   256,
      -1,  1215,    -1,   256,    -1,  1229,    -1,  1212,    -1,  1222,
      -1,   510,    -1,  1212,    -1,  1224,    -1,  1212,    -1,  1222,
      -1,  1215,    -1,  1226,    -1,  1229,    -1,  1214,    -1,  1214,
      -1,  1219,    -1,  1219,  1220,    -1,  1216,    -1,  1219,  1220,
    1221,    -1,  1219,  1220,    -1,  1219,  1221,    -1,  1219,    -1,
    1218,    -1,  1219,  1220,  1221,    -1,  1219,  1220,    -1,  1219,
    1221,    -1,  1219,    -1,   504,    -1,   504,  1312,  1219,    -1,
     462,  1165,   448,    -1,   462,  1167,   449,   448,    -1,   462,
    1167,   449,  1167,   448,    -1,   256,    -1,   256,    -1,   256,
      -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,
      -1,   266,    -1,   460,    -1,  1227,    -1,     9,  1228,    -1,
    1228,    -1,  1227,   447,  1228,    -1,   256,    -1,   416,    -1,
     510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,    -1,
    1230,  1233,    -1,  1231,   462,  1200,   448,  1233,    -1,  1232,
     462,  1165,   448,  1233,    -1,   470,   462,  1235,   448,  1233,
      -1,   303,   462,  1236,   448,    -1,   258,   462,  1237,   448,
    1233,    -1,   259,   462,  1237,   448,  1233,    -1,   260,   462,
    1237,   448,  1233,    -1,   201,  1234,    -1,   495,  1234,    -1,
      99,    -1,   502,    -1,   490,    -1,   264,    -1,   377,    -1,
      82,    -1,   428,    -1,   429,    -1,    -1,   462,  1167,   449,
     448,    -1,   462,  1167,   449,  1167,   448,    -1,    -1,   462,
    1165,   448,    -1,   462,   448,    -1,  1200,    -1,  1200,  1166,
     241,    -1,  1200,  1166,   468,    -1,  1200,    -1,  1200,  1166,
    1200,    -1,  1167,    -1,  1167,  1166,  1187,    -1,    -1,    -1,
       9,    -1,    -1,  1321,    -1,  1322,    -1,    -1,   223,    -1,
      -1,   223,  1243,    -1,    -1,   446,  1205,    -1,    -1,   285,
      -1,   334,    -1,    -1,   290,    -1,    -1,   312,    -1,   290,
     312,    -1,    -1,   386,  1248,    -1,    -1,   272,  1273,  1249,
      -1,    34,    -1,   281,    -1,   282,    -1,   283,    -1,   344,
      -1,   466,    -1,   467,    -1,   471,    -1,    -1,   400,  1260,
      -1,   451,    -1,     3,    -1,     5,    -1,    10,    -1,    18,
      -1,    51,    -1,    52,    -1,    60,    -1,    71,    -1,    74,
      -1,    88,    -1,   111,    -1,   119,    -1,   121,    -1,   128,
      -1,   152,    -1,   163,    -1,   168,    -1,   195,    -1,   202,
      -1,   205,    -1,   206,    -1,   215,    -1,   222,    -1,   224,
      -1,   227,    -1,   269,    -1,   273,    -1,   275,    -1,   285,
      -1,   311,    -1,   324,    -1,   349,    -1,   360,    -1,   375,
      -1,   381,    -1,   385,    -1,   393,    -1,   403,    -1,   412,
      -1,   421,    -1,   426,    -1,   427,    -1,   430,    -1,   432,
      -1,   438,    -1,   469,    -1,   475,    -1,   480,    -1,   507,
      -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   139,    -1,   140,
      -1,   141,    -1,   143,    -1,   144,    -1,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,   151,
      -1,    -1,     7,    -1,    -1,     8,    -1,    -1,    22,    -1,
      -1,    23,    -1,    -1,    26,    -1,    -1,    30,    -1,    -1,
      39,    -1,    -1,    49,    -1,    -1,    56,    -1,    -1,    57,
      -1,    -1,    86,    -1,    -1,   102,    -1,    -1,   454,    -1,
      -1,   176,    -1,    -1,   188,    -1,    -1,   196,    -1,    -1,
     218,    -1,    -1,   314,    -1,   218,   314,    -1,    -1,   221,
      -1,    -1,   456,    -1,    -1,   228,    -1,    -1,   232,    -1,
      -1,   232,    -1,    22,    -1,    -1,   237,    -1,    -1,   242,
      -1,   384,    -1,    -1,   252,    -1,   254,    -1,    -1,   248,
    1273,    -1,   249,  1254,    -1,    -1,   254,    -1,    -1,   272,
      -1,    -1,   299,    -1,    -1,   299,    -1,   300,    -1,    -1,
     306,    -1,    -1,   309,    -1,    -1,   423,   232,    -1,   423,
      -1,   232,    -1,    -1,   316,    -1,    -1,   337,    -1,    -1,
     340,    -1,    -1,   351,    -1,    -1,   384,    -1,    -1,   405,
      -1,    -1,   406,    -1,    -1,   405,    -1,   405,   232,    -1,
      -1,   410,    -1,    -1,   418,    -1,    -1,   423,    -1,    -1,
     437,    -1,    -1,   441,    -1,    -1,   445,    -1,    -1,   446,
      -1,    -1,   446,    -1,   497,    -1,    -1,   501,    -1,    -1,
     501,   403,   446,    -1,    -1,   503,    -1,    -1,   351,    -1,
      63,   401,    -1,   401,    -1,    66,    -1,    64,    -1,    67,
      -1,    65,    -1,   452,    -1,   159,    -1,   165,    -1,   161,
      -1,   165,    -1,   461,    -1,   218,    -1,   306,    -1,   418,
      -1,   308,    -1,   252,    -1,   254,    -1,   351,    -1,   353,
      -1,    57,    -1,   505,    -1,   351,  1273,    -1,   353,  1254,
      -1,   356,    -1,   474,    -1,   252,    -1,   254,    -1,   410,
      -1,   244,    -1,   503,   124,    -1,   124,    -1,   503,   287,
     124,    -1,   287,   124,    -1,   340,    63,   401,    -1,    63,
     401,    -1,   401,    -1,   116,    -1,   106,    -1,    89,   210,
      -1,    54,    -1,    89,   187,    -1,    53,    -1,   321,   210,
      -1,   325,    -1,   321,   187,    -1,   326,    -1,   366,   210,
      -1,   383,    -1,   366,   187,    -1,   382,    -1,    89,  1273,
      -1,    90,  1254,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1353,  1353,  1353,  1385,  1386,  1390,  1391,  1395,  1396,
    1400,  1400,  1423,  1430,  1437,  1443,  1444,  1445,  1449,  1450,
    1454,  1478,  1479,  1483,  1517,  1523,  1535,  1509,  1545,  1544,
    1582,  1617,  1618,  1622,  1623,  1626,  1627,  1631,  1640,  1649,
    1650,  1654,  1658,  1667,  1668,  1676,  1677,  1687,  1688,  1692,
    1693,  1694,  1695,  1696,  1703,  1702,  1715,  1716,  1719,  1720,
    1734,  1733,  1743,  1744,  1745,  1746,  1750,  1751,  1755,  1756,
    1757,  1758,  1762,  1769,  1776,  1783,  1794,  1798,  1802,  1806,
    1813,  1814,  1821,  1820,  1831,  1832,  1833,  1840,  1841,  1845,
    1849,  1861,  1865,  1866,  1871,  1874,  1881,  1886,  1897,  1910,
    1911,  1919,  1920,  1924,  1925,  1926,  1927,  1928,  1929,  1930,
    1931,  1932,  1933,  1934,  1935,  1943,  1942,  1961,  1971,  1984,
    1992,  1995,  1996,  2000,  2010,  2026,  2025,  2049,  2055,  2061,
    2067,  2073,  2079,  2089,  2093,  2100,  2104,  2109,  2108,  2119,
    2123,  2130,  2131,  2132,  2133,  2134,  2135,  2139,  2140,  2147,
    2162,  2165,  2172,  2180,  2184,  2195,  2215,  2223,  2234,  2235,
    2241,  2262,  2263,  2267,  2271,  2292,  2315,  2397,  2400,  2409,
    2428,  2444,  2462,  2480,  2497,  2513,  2514,  2521,  2522,  2530,
    2531,  2541,  2542,  2547,  2546,  2567,  2577,  2578,  2582,  2583,
    2584,  2585,  2586,  2587,  2588,  2589,  2590,  2591,  2592,  2593,
    2594,  2601,  2607,  2617,  2630,  2643,  2659,  2660,  2661,  2662,
    2665,  2666,  2672,  2673,  2677,  2681,  2682,  2687,  2690,  2691,
    2698,  2706,  2707,  2708,  2715,  2744,  2782,  2784,  2793,  2808,
    2819,  2826,  2828,  2829,  2835,  2835,  2842,  2847,  2852,  2859,
    2860,  2861,  2865,  2876,  2877,  2881,  2886,  2891,  2896,  2907,
    2918,  2928,  2933,  2955,  2956,  2960,  2960,  2964,  2969,  2988,
    2999,  3006,  3007,  3013,  3020,  3021,  3022,  3028,  3029,  3030,
    3037,  3038,  3042,  3043,  3049,  3077,  3078,  3079,  3080,  3087,
    3086,  3102,  3103,  3107,  3110,  3111,  3117,  3118,  3126,  3127,
    3135,  3136,  3140,  3161,  3160,  3177,  3184,  3188,  3194,  3195,
    3199,  3209,  3224,  3225,  3226,  3227,  3228,  3229,  3230,  3231,
    3232,  3239,  3246,  3246,  3246,  3252,  3272,  3306,  3337,  3338,
    3345,  3346,  3350,  3351,  3358,  3369,  3374,  3385,  3386,  3390,
    3391,  3397,  3408,  3426,  3427,  3431,  3432,  3433,  3437,  3444,
    3451,  3460,  3472,  3524,  3539,  3540,  3544,  3554,  3593,  3595,
    3594,  3610,  3613,  3613,  3630,  3631,  3633,  3637,  3639,  3638,
    3673,  3686,  3694,  3699,  3705,  3714,  3724,  3727,  3739,  3740,
    3741,  3742,  3746,  3750,  3754,  3758,  3762,  3766,  3770,  3774,
    3778,  3782,  3786,  3790,  3794,  3805,  3806,  3810,  3811,  3815,
    3816,  3817,  3821,  3822,  3826,  3852,  3856,  3865,  3869,  3878,
    3879,  3880,  3881,  3882,  3883,  3884,  3885,  3886,  3887,  3888,
    3889,  3890,  3891,  3898,  3922,  3950,  3953,  3962,  3987,  3998,
    3999,  4003,  4007,  4011,  4015,  4019,  4023,  4027,  4031,  4035,
    4039,  4043,  4047,  4051,  4056,  4061,  4065,  4069,  4077,  4081,
    4085,  4093,  4097,  4101,  4105,  4109,  4113,  4117,  4121,  4125,
    4133,  4141,  4145,  4149,  4153,  4157,  4161,  4169,  4170,  4174,
    4175,  4181,  4187,  4199,  4217,  4218,  4227,  4251,  4252,  4255,
    4256,  4263,  4287,  4288,  4305,  4306,  4309,  4310,  4317,  4318,
    4323,  4334,  4345,  4356,  4367,  4396,  4395,  4404,  4405,  4409,
    4410,  4413,  4414,  4427,  4440,  4461,  4470,  4484,  4486,  4485,
    4505,  4507,  4506,  4522,  4524,  4523,  4532,  4533,  4540,  4539,
    4552,  4553,  4554,  4561,  4566,  4570,  4571,  4577,  4584,  4588,
    4589,  4595,  4632,  4636,  4641,  4647,  4648,  4653,  4654,  4655,
    4656,  4657,  4661,  4668,  4675,  4682,  4689,  4695,  4696,  4701,
    4700,  4707,  4708,  4712,  4713,  4714,  4715,  4716,  4717,  4718,
    4719,  4720,  4721,  4722,  4723,  4724,  4725,  4726,  4727,  4731,
    4738,  4739,  4740,  4741,  4742,  4743,  4744,  4747,  4748,  4749,
    4752,  4753,  4757,  4764,  4770,  4771,  4775,  4776,  4780,  4787,
    4791,  4798,  4799,  4803,  4810,  4811,  4815,  4816,  4820,  4821,
    4822,  4826,  4827,  4831,  4832,  4836,  4843,  4850,  4858,  4860,
    4859,  4880,  4881,  4885,  4886,  4891,  4893,  4892,  4949,  4967,
    4968,  4972,  4976,  4980,  4984,  4988,  4992,  4996,  5000,  5004,
    5008,  5012,  5016,  5020,  5024,  5028,  5032,  5036,  5041,  5045,
    5049,  5054,  5059,  5064,  5069,  5070,  5071,  5072,  5073,  5074,
    5075,  5076,  5077,  5084,  5089,  5098,  5099,  5103,  5104,  5109,
    5112,  5116,  5124,  5127,  5131,  5139,  5150,  5158,  5160,  5170,
    5159,  5197,  5197,  5230,  5234,  5233,  5247,  5246,  5266,  5267,
    5272,  5279,  5281,  5285,  5295,  5297,  5305,  5313,  5321,  5350,
    5381,  5383,  5393,  5398,  5425,  5427,  5426,  5462,  5463,  5467,
    5468,  5469,  5486,  5487,  5498,  5497,  5547,  5548,  5552,  5600,
    5613,  5616,  5635,  5640,  5634,  5653,  5653,  5683,  5690,  5691,
    5692,  5693,  5694,  5695,  5696,  5697,  5698,  5699,  5700,  5701,
    5702,  5703,  5704,  5705,  5706,  5707,  5708,  5709,  5710,  5711,
    5712,  5713,  5714,  5715,  5716,  5717,  5718,  5719,  5720,  5721,
    5722,  5723,  5724,  5725,  5726,  5727,  5728,  5729,  5730,  5731,
    5732,  5733,  5734,  5735,  5736,  5737,  5738,  5739,  5753,  5765,
    5764,  5773,  5779,  5783,  5787,  5792,  5797,  5802,  5807,  5811,
    5815,  5819,  5823,  5828,  5832,  5836,  5840,  5844,  5848,  5852,
    5859,  5860,  5867,  5868,  5872,  5873,  5877,  5878,  5879,  5880,
    5881,  5885,  5889,  5890,  5893,  5894,  5897,  5898,  5904,  5905,
    5909,  5910,  5914,  5918,  5922,  5926,  5930,  5934,  5938,  5942,
    5946,  5950,  5954,  5958,  5962,  5966,  5970,  5974,  5978,  5982,
    5986,  5990,  5994,  5998,  6002,  6006,  6013,  6017,  6028,  6027,
    6036,  6040,  6044,  6050,  6051,  6058,  6062,  6073,  6072,  6081,
    6085,  6097,  6098,  6106,  6105,  6114,  6115,  6119,  6125,  6125,
    6132,  6131,  6141,  6161,  6165,  6170,  6175,  6196,  6200,  6199,
    6216,  6217,  6222,  6230,  6254,  6256,  6260,  6269,  6282,  6285,
    6289,  6293,  6316,  6317,  6321,  6322,  6327,  6330,  6338,  6342,
    6350,  6354,  6365,  6364,  6372,  6376,  6387,  6386,  6394,  6399,
    6407,  6408,  6409,  6410,  6411,  6419,  6418,  6427,  6434,  6438,
    6448,  6459,  6477,  6476,  6485,  6489,  6493,  6498,  6506,  6510,
    6521,  6520,  6530,  6534,  6538,  6542,  6546,  6550,  6551,  6560,
    6562,  6561,  6569,  6578,  6585,  6589,  6593,  6597,  6607,  6609,
    6613,  6614,  6617,  6619,  6626,  6627,  6631,  6632,  6637,  6641,
    6645,  6649,  6653,  6657,  6661,  6665,  6669,  6673,  6677,  6681,
    6685,  6689,  6693,  6697,  6704,  6708,  6719,  6718,  6727,  6731,
    6735,  6739,  6743,  6750,  6754,  6765,  6764,  6772,  6792,  6791,
    6815,  6823,  6824,  6829,  6840,  6851,  6865,  6869,  6876,  6877,
    6882,  6891,  6900,  6905,  6914,  6915,  6920,  6982,  6983,  6984,
    6988,  6989,  6993,  6997,  7008,  7007,  7019,  7020,  7041,  7055,
    7077,  7099,  7119,  7142,  7143,  7151,  7150,  7158,  7169,  7168,
    7178,  7185,  7184,  7197,  7206,  7210,  7221,  7237,  7236,  7245,
    7249,  7253,  7260,  7264,  7275,  7274,  7282,  7290,  7291,  7295,
    7296,  7297,  7302,  7305,  7312,  7316,  7324,  7331,  7332,  7333,
    7334,  7335,  7336,  7337,  7342,  7345,  7355,  7354,  7363,  7369,
    7381,  7380,  7389,  7393,  7397,  7401,  7408,  7409,  7410,  7411,
    7418,  7417,  7431,  7441,  7450,  7451,  7455,  7456,  7457,  7458,
    7459,  7460,  7464,  7465,  7469,  7474,  7481,  7482,  7483,  7484,
    7485,  7489,  7517,  7520,  7527,  7531,  7541,  7540,  7553,  7552,
    7560,  7564,  7575,  7574,  7583,  7587,  7594,  7598,  7609,  7608,
    7616,  7631,  7649,  7650,  7651,  7652,  7656,  7657,  7662,  7663,
    7664,  7670,  7671,  7672,  7673,  7685,  7684,  7695,  7701,  7700,
    7711,  7719,  7727,  7734,  7738,  7751,  7758,  7770,  7773,  7778,
    7782,  7793,  7800,  7801,  7805,  7806,  7809,  7810,  7815,  7826,
    7825,  7834,  7861,  7862,  7867,  7870,  7874,  7878,  7882,  7886,
    7890,  7897,  7898,  7902,  7903,  7907,  7911,  7921,  7932,  7931,
    7939,  7949,  7960,  7959,  7968,  7975,  7979,  7990,  7989,  8001,
    8010,  8013,  8017,  8024,  8028,  8038,  8050,  8049,  8058,  8062,
    8071,  8072,  8077,  8080,  8088,  8092,  8099,  8107,  8111,  8122,
    8121,  8135,  8136,  8137,  8138,  8139,  8140,  8144,  8145,  8149,
    8150,  8156,  8165,  8172,  8173,  8177,  8181,  8185,  8189,  8193,
    8197,  8201,  8205,  8214,  8218,  8227,  8236,  8237,  8241,  8250,
    8251,  8255,  8259,  8270,  8269,  8278,  8277,  8308,  8311,  8331,
    8332,  8335,  8336,  8344,  8345,  8350,  8355,  8365,  8381,  8386,
    8396,  8413,  8412,  8422,  8435,  8438,  8446,  8449,  8454,  8459,
    8467,  8468,  8469,  8470,  8471,  8472,  8476,  8484,  8485,  8489,
    8493,  8504,  8503,  8513,  8526,  8529,  8533,  8541,  8553,  8556,
    8563,  8564,  8565,  8566,  8573,  8572,  8581,  8588,  8589,  8593,
    8594,  8595,  8599,  8600,  8604,  8608,  8619,  8618,  8627,  8631,
    8635,  8642,  8646,  8656,  8667,  8668,  8675,  8674,  8683,  8689,
    8701,  8700,  8708,  8722,  8721,  8729,  8742,  8744,  8745,  8753,
    8752,  8761,  8769,  8770,  8775,  8776,  8781,  8788,  8789,  8794,
    8801,  8802,  8806,  8807,  8811,  8812,  8816,  8820,  8831,  8830,
    8839,  8840,  8841,  8842,  8843,  8847,  8874,  8877,  8889,  8899,
    8904,  8909,  8914,  8922,  8960,  8961,  8965,  9005,  9015,  9038,
    9039,  9040,  9041,  9045,  9054,  9060,  9070,  9079,  9088,  9089,
    9096,  9095,  9107,  9117,  9118,  9123,  9126,  9130,  9134,  9141,
    9142,  9146,  9147,  9151,  9155,  9167,  9170,  9171,  9180,  9181,
    9190,  9193,  9194,  9203,  9204,  9215,  9218,  9219,  9228,  9229,
    9241,  9244,  9246,  9256,  9257,  9269,  9270,  9274,  9275,  9276,
    9280,  9289,  9300,  9301,  9302,  9306,  9315,  9326,  9331,  9332,
    9341,  9342,  9353,  9357,  9367,  9374,  9381,  9381,  9391,  9392,
    9393,  9397,  9406,  9407,  9409,  9410,  9411,  9412,  9413,  9415,
    9416,  9417,  9418,  9419,  9420,  9422,  9423,  9424,  9426,  9427,
    9428,  9429,  9430,  9433,  9434,  9438,  9439,  9443,  9444,  9448,
    9449,  9453,  9457,  9463,  9467,  9473,  9474,  9475,  9479,  9480,
    9481,  9485,  9486,  9487,  9491,  9495,  9499,  9500,  9501,  9504,
    9505,  9515,  9527,  9536,  9548,  9557,  9569,  9584,  9585,  9590,
    9599,  9605,  9625,  9629,  9650,  9691,  9705,  9706,  9711,  9717,
    9718,  9723,  9735,  9736,  9737,  9744,  9755,  9756,  9760,  9768,
    9776,  9780,  9787,  9797,  9806,  9807,  9813,  9827,  9844,  9848,
    9855,  9856,  9857,  9864,  9868,  9875,  9876,  9877,  9878,  9879,
    9883,  9887,  9891,  9895,  9899,  9920,  9924,  9931,  9932,  9933,
    9937,  9938,  9939,  9940,  9941,  9945,  9949,  9956,  9957,  9961,
    9962,  9966,  9967,  9971,  9972,  9983,  9984,  9988,  9989,  9990,
    9994,  9995,  9996, 10003, 10004, 10008, 10009, 10013, 10014, 10015,
   10021, 10025, 10029, 10030, 10034, 10038, 10045, 10052, 10059, 10069,
   10076, 10086, 10096, 10106, 10119, 10123, 10131, 10139, 10143, 10153,
   10168, 10191, 10214, 10230, 10231, 10232, 10233, 10234, 10235, 10239,
   10243, 10260, 10264, 10271, 10272, 10273, 10274, 10275, 10276, 10277,
   10283, 10287, 10291, 10295, 10299, 10303, 10307, 10311, 10315, 10319,
   10326, 10327, 10331, 10332, 10333, 10337, 10338, 10339, 10343, 10347,
   10351, 10358, 10362, 10366, 10373, 10380, 10387, 10397, 10404, 10414,
   10421, 10433, 10441, 10442, 10446, 10447, 10448, 10456, 10457, 10462,
   10465, 10473, 10476, 10483, 10485, 10486, 10490, 10491, 10495, 10496,
   10497, 10502, 10505, 10518, 10522, 10530, 10534, 10538, 10542, 10546,
   10550, 10554, 10558, 10565, 10566, 10572, 10573, 10574, 10575, 10576,
   10577, 10578, 10579, 10580, 10581, 10582, 10583, 10584, 10585, 10586,
   10587, 10588, 10589, 10590, 10591, 10592, 10593, 10594, 10595, 10596,
   10597, 10598, 10599, 10600, 10601, 10602, 10603, 10604, 10605, 10606,
   10607, 10608, 10609, 10610, 10611, 10612, 10613, 10614, 10615, 10616,
   10617, 10618, 10619, 10620, 10621, 10622, 10623, 10624, 10625, 10626,
   10627, 10628, 10629, 10630, 10631, 10632, 10633, 10634, 10635, 10636,
   10637, 10638, 10639, 10640, 10641, 10648, 10648, 10649, 10649, 10650,
   10650, 10651, 10651, 10652, 10652, 10653, 10653, 10654, 10654, 10655,
   10655, 10656, 10656, 10657, 10657, 10658, 10658, 10659, 10659, 10660,
   10660, 10661, 10661, 10662, 10662, 10663, 10663, 10664, 10664, 10665,
   10665, 10665, 10666, 10666, 10667, 10667, 10668, 10668, 10669, 10669,
   10670, 10670, 10670, 10671, 10671, 10672, 10672, 10672, 10673, 10673,
   10673, 10674, 10674, 10674, 10675, 10675, 10676, 10676, 10677, 10677,
   10678, 10678, 10678, 10679, 10679, 10680, 10680, 10681, 10681, 10681,
   10681, 10682, 10682, 10683, 10683, 10684, 10684, 10685, 10685, 10686,
   10686, 10687, 10687, 10688, 10688, 10689, 10689, 10689, 10690, 10690,
   10691, 10691, 10692, 10692, 10693, 10693, 10694, 10694, 10695, 10695,
   10696, 10696, 10697, 10697, 10697, 10698, 10698, 10699, 10699, 10700,
   10700, 10706, 10709, 10714, 10714, 10715, 10715, 10716, 10716, 10717,
   10717, 10718, 10718, 10719, 10719, 10720, 10720, 10721, 10721, 10722,
   10722, 10723, 10723, 10724, 10724, 10725, 10725, 10726, 10726, 10727,
   10727, 10728, 10728, 10729, 10729, 10730, 10730, 10733, 10734, 10735,
   10739, 10739, 10740, 10740, 10741, 10741, 10742, 10742, 10743, 10743,
   10744, 10744, 10745, 10745, 10746, 10746
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
  "space_or_zero", "symbolic_characters_clause", "sym_in_word",
  "symbolic_collection", "symbolic_chars_list", "symbolic_chars_phrase",
  "char_list", "integer_list", "class_name_clause", "class_item_list",
  "class_item", "locale_clause", "currency_sign_clause", "with_pic_symbol",
  "decimal_point_clause", "numeric_sign_clause", "cursor_clause",
  "crt_status_clause", "screen_control", "event_status",
  "input_output_header", "file_control_header", "i_o_control_header",
  "file_control_sequence", "file_control_entry", "$@13",
  "select_clause_sequence", "select_clause", "assign_clause",
  "device_name", "_line_adv_file", "_ext_clause", "assignment_name",
  "opt_assignment_name", "access_mode_clause", "access_mode",
  "alternative_record_key_clause", "suppress_clause",
  "collating_sequence_clause", "file_status_clause", "file_or_sort",
  "lock_mode_clause", "$@14", "lock_mode", "lock_with",
  "organization_clause", "organization", "padding_character_clause",
  "record_delimiter_clause", "record_key_clause", "_source_is",
  "split_key_list", "$@15", "split_key", "relative_key_clause",
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
  "rel_record", "coll_sequence", "column_or_col", "columns_or_cols",
  "comp_equal", "exception_or_error", "exception_or_overflow", "in_of",
  "label_option", "line_or_lines", "lock_records", "object_char_or_word",
  "records", "reel_or_unit", "scroll_line_or_lines", "size_or_length",
  "with_dups", "with_no_dups", "prog_coll_sequence", "detail_keyword",
  "ch_keyword", "cf_keyword", "ph_keyword", "pf_keyword", "rh_keyword",
  "rf_keyword", "control_keyword", 0
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
     582,   583,   583,   583,   583,   583,   583,   584,   584,   585,
     586,   586,   587,   588,   588,   589,   590,   590,   591,   591,
     592,   593,   593,   594,   594,   595,   596,   597,   597,   598,
     599,   600,   601,   602,   603,   604,   604,   605,   605,   606,
     606,   607,   607,   609,   608,   608,   610,   610,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   612,   612,   612,   612,   612,   613,   613,   613,   613,
     614,   614,   615,   615,   615,   616,   616,   617,   617,   617,
     618,   619,   619,   619,   620,   620,   621,   621,   621,   622,
     623,   624,   624,   624,   626,   625,   627,   627,   627,   628,
     628,   628,   628,   629,   629,   630,   630,   630,   630,   631,
     632,   633,   633,   634,   634,   636,   635,   635,   637,   638,
     639,   640,   640,   641,   642,   642,   642,   643,   643,   643,
     644,   644,   645,   645,   646,   647,   647,   647,   647,   649,
     648,   650,   650,   651,   652,   652,   653,   653,   654,   654,
     655,   655,   656,   658,   657,   657,   659,   659,   660,   660,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   662,   663,   663,   663,   664,   664,   664,   665,   665,
     666,   666,   667,   667,   668,   669,   669,   670,   670,   671,
     671,   672,   673,   674,   674,   675,   675,   675,   676,   677,
     678,   679,   680,   681,   682,   682,   683,   683,   684,   685,
     684,   686,   687,   686,   688,   688,   688,   689,   690,   689,
     689,   691,   692,   692,   692,   693,   694,   694,   695,   695,
     695,   695,   696,   696,   696,   696,   696,   696,   696,   696,
     696,   696,   696,   696,   696,   697,   697,   698,   698,   699,
     699,   699,   700,   700,   701,   702,   702,   703,   703,   704,
     704,   704,   704,   704,   704,   704,   704,   704,   704,   704,
     704,   704,   704,   705,   706,   707,   707,   708,   709,   710,
     710,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   712,   712,   713,
     713,   714,   714,   715,   716,   716,   717,   718,   718,   719,
     719,   720,   721,   721,   722,   722,   723,   723,   724,   724,
     725,   726,   727,   728,   729,   731,   730,   732,   732,   733,
     733,   734,   734,   735,   735,   736,   736,   737,   738,   737,
     739,   740,   739,   741,   742,   741,   743,   743,   745,   744,
     746,   746,   746,   747,   747,   747,   747,   748,   749,   750,
     750,   751,   752,   752,   752,   753,   753,   754,   754,   754,
     754,   754,   755,   756,   757,   758,   759,   760,   760,   762,
     761,   763,   763,   764,   764,   764,   764,   764,   764,   764,
     764,   764,   764,   764,   764,   764,   764,   764,   764,   765,
     766,   766,   766,   766,   766,   766,   766,   767,   767,   767,
     768,   768,   769,   770,   771,   771,   772,   772,   773,   774,
     775,   776,   776,   777,   778,   778,   779,   779,   780,   780,
     780,   781,   781,   782,   782,   783,   784,   785,   786,   787,
     786,   788,   788,   789,   789,   790,   791,   790,   790,   792,
     792,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   794,   794,   795,   795,   796,
     796,   796,   797,   797,   797,   798,   799,   800,   801,   802,
     800,   803,   800,   804,   805,   804,   806,   804,   807,   807,
     808,   809,   809,   809,   810,   810,   810,   810,   810,   810,
     811,   811,   812,   812,   813,   814,   813,   815,   815,   816,
     816,   816,   816,   816,   818,   817,   819,   819,   820,   821,
     822,   822,   824,   825,   823,   827,   826,   826,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   830,
     829,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     832,   832,   833,   833,   834,   834,   835,   835,   835,   835,
     835,   836,   837,   837,   838,   838,   839,   839,   840,   840,
     841,   841,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   843,   843,   845,   844,
     846,   846,   846,   847,   847,   848,   848,   850,   849,   851,
     851,   852,   852,   854,   853,   855,   855,   856,   857,   857,
     859,   858,   860,   861,   861,   861,   861,   862,   863,   862,
     864,   864,   865,   865,   866,   866,   866,   866,   867,   867,
     867,   867,   868,   868,   869,   869,   870,   870,   871,   871,
     872,   872,   874,   873,   875,   875,   877,   876,   878,   878,
     879,   879,   879,   879,   879,   881,   880,   882,   883,   883,
     884,   885,   887,   886,   888,   888,   889,   889,   890,   890,
     892,   891,   893,   893,   893,   893,   893,   893,   893,   894,
     895,   894,   896,   897,   897,   897,   897,   897,   898,   898,
     899,   899,   900,   900,   901,   901,   902,   902,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   904,   904,   906,   905,   907,   907,
     907,   907,   907,   908,   908,   910,   909,   911,   913,   912,
     914,   915,   915,   916,   916,   916,   917,   917,   918,   918,
     919,   920,   921,   921,   922,   922,   923,   923,   923,   923,
     924,   924,   925,   925,   927,   926,   928,   928,   928,   928,
     928,   928,   928,   929,   929,   931,   930,   932,   934,   933,
     935,   937,   936,   938,   939,   939,   940,   942,   941,   943,
     943,   943,   944,   944,   946,   945,   947,   948,   948,   949,
     949,   949,   950,   950,   951,   951,   952,   953,   953,   953,
     953,   953,   953,   953,   954,   954,   956,   955,   957,   957,
     959,   958,   960,   961,   961,   961,   962,   962,   962,   962,
     964,   963,   965,   966,   967,   967,   968,   968,   968,   968,
     968,   968,   969,   969,   970,   970,   971,   971,   971,   971,
     971,   972,   973,   973,   974,   974,   976,   975,   978,   977,
     979,   979,   981,   980,   982,   982,   983,   983,   985,   984,
     986,   986,   987,   987,   987,   987,   988,   988,   989,   989,
     989,   990,   990,   990,   990,   992,   991,   993,   994,   993,
     993,   995,   995,   996,   996,   997,   997,   998,   998,   998,
     998,   998,   999,   999,  1000,  1000,  1001,  1001,  1002,  1004,
    1003,  1005,  1006,  1006,  1007,  1007,  1007,  1007,  1007,  1007,
    1007,  1008,  1008,  1009,  1009,  1010,  1010,  1011,  1013,  1012,
    1014,  1015,  1017,  1016,  1018,  1019,  1019,  1021,  1020,  1022,
    1023,  1023,  1023,  1024,  1024,  1025,  1027,  1026,  1028,  1028,
    1029,  1029,  1030,  1030,  1031,  1031,  1032,  1033,  1033,  1035,
    1034,  1036,  1036,  1036,  1036,  1036,  1036,  1037,  1037,  1038,
    1038,  1039,  1040,  1041,  1041,  1042,  1042,  1042,  1042,  1042,
    1042,  1042,  1042,  1043,  1043,  1044,  1045,  1045,  1046,  1047,
    1047,  1048,  1048,  1050,  1049,  1052,  1051,  1053,  1053,  1054,
    1054,  1055,  1055,  1056,  1056,  1057,  1057,  1057,  1058,  1058,
    1058,  1060,  1059,  1061,  1062,  1062,  1063,  1063,  1063,  1063,
    1064,  1064,  1064,  1064,  1064,  1064,  1065,  1066,  1066,  1067,
    1067,  1069,  1068,  1068,  1070,  1070,  1070,  1070,  1071,  1071,
    1072,  1072,  1072,  1072,  1074,  1073,  1075,  1076,  1076,  1077,
    1077,  1077,  1078,  1078,  1079,  1079,  1081,  1080,  1082,  1082,
    1082,  1083,  1083,  1084,  1085,  1085,  1087,  1086,  1088,  1088,
    1090,  1089,  1091,  1093,  1092,  1094,  1095,  1095,  1095,  1097,
    1096,  1098,  1099,  1099,  1100,  1100,  1101,  1102,  1102,  1103,
    1104,  1104,  1105,  1105,  1106,  1106,  1107,  1107,  1109,  1108,
    1110,  1110,  1110,  1110,  1110,  1111,  1112,  1112,  1113,  1113,
    1113,  1113,  1113,  1114,  1115,  1115,  1116,  1116,  1116,  1117,
    1117,  1117,  1117,  1118,  1119,  1119,  1120,  1121,  1122,  1122,
    1124,  1123,  1125,  1126,  1126,  1127,  1127,  1127,  1127,  1128,
    1128,  1129,  1129,  1130,  1130,  1131,  1132,  1132,  1133,  1133,
    1134,  1135,  1135,  1136,  1136,  1137,  1138,  1138,  1139,  1139,
    1140,  1141,  1141,  1142,  1142,  1143,  1143,  1144,  1144,  1144,
    1145,  1146,  1147,  1147,  1147,  1148,  1149,  1150,  1151,  1151,
    1152,  1152,  1153,  1153,  1154,  1155,  1157,  1156,  1158,  1158,
    1158,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,  1160,  1160,  1161,  1161,  1162,
    1162,  1163,  1164,  1165,  1165,  1166,  1166,  1166,  1167,  1167,
    1167,  1168,  1168,  1168,  1169,  1169,  1170,  1170,  1170,  1171,
    1171,  1172,  1172,  1172,  1172,  1172,  1172,  1173,  1173,  1174,
    1175,  1176,  1177,  1177,  1178,  1179,  1180,  1180,  1181,  1182,
    1182,  1183,  1184,  1184,  1184,  1185,  1186,  1186,  1187,  1188,
    1189,  1189,  1190,  1191,  1192,  1192,  1193,  1194,  1195,  1195,
    1196,  1196,  1196,  1197,  1197,  1198,  1198,  1198,  1198,  1198,
    1198,  1198,  1198,  1198,  1198,  1199,  1199,  1200,  1200,  1200,
    1201,  1201,  1201,  1201,  1201,  1201,  1201,  1202,  1202,  1203,
    1203,  1204,  1204,  1205,  1205,  1206,  1206,  1207,  1207,  1207,
    1208,  1208,  1208,  1209,  1209,  1210,  1210,  1211,  1211,  1211,
    1212,  1213,  1214,  1214,  1215,  1216,  1216,  1216,  1216,  1217,
    1218,  1218,  1218,  1218,  1219,  1219,  1220,  1221,  1221,  1222,
    1223,  1224,  1225,  1225,  1225,  1225,  1225,  1225,  1225,  1226,
    1226,  1227,  1227,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,
    1230,  1230,  1231,  1231,  1231,  1232,  1232,  1232,  1233,  1233,
    1233,  1234,  1234,  1234,  1235,  1235,  1235,  1236,  1236,  1237,
    1237,  1238,  1239,  1239,  1240,  1240,  1240,  1241,  1241,  1242,
    1242,  1243,  1243,  1244,  1244,  1244,  1245,  1245,  1246,  1246,
    1246,  1247,  1247,  1248,  1248,  1249,  1249,  1249,  1249,  1249,
    1249,  1249,  1249,  1250,  1250,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  1251,  1251,  1252,  1252,  1253,  1253,  1254,
    1254,  1255,  1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,
    1259,  1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1264,
    1264,  1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,  1269,
    1269,  1269,  1270,  1270,  1271,  1271,  1272,  1272,  1273,  1273,
    1274,  1274,  1274,  1275,  1275,  1276,  1276,  1276,  1277,  1277,
    1277,  1278,  1278,  1278,  1279,  1279,  1280,  1280,  1281,  1281,
    1282,  1282,  1282,  1283,  1283,  1284,  1284,  1285,  1285,  1285,
    1285,  1286,  1286,  1287,  1287,  1288,  1288,  1289,  1289,  1290,
    1290,  1291,  1291,  1292,  1292,  1293,  1293,  1293,  1294,  1294,
    1295,  1295,  1296,  1296,  1297,  1297,  1298,  1298,  1299,  1299,
    1300,  1300,  1301,  1301,  1301,  1302,  1302,  1303,  1303,  1304,
    1304,  1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,
    1309,  1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,
    1314,  1315,  1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,
    1319,  1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323,  1323,
    1324,  1324,  1325,  1325,  1326,  1326,  1327,  1327,  1328,  1328,
    1329,  1329,  1330,  1330,  1331,  1331
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
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     2,     3,     1,     2,     3,     1,     2,     1,     2,
       4,     1,     2,     1,     3,     4,     5,     0,     3,     3,
       5,     3,     4,     3,     3,     0,     3,     0,     2,     0,
       2,     0,     2,     0,     6,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     5,     5,     1,     1,     1,     1,
       0,     3,     0,     1,     1,     1,     1,     0,     1,     1,
       4,     1,     1,     1,     7,     9,     0,     4,     3,     3,
       4,     0,     1,     1,     0,     5,     2,     2,     1,     0,
       4,     5,     2,     3,     1,     1,     3,     1,     2,     4,
       4,     4,     6,     1,     2,     0,     2,     2,     1,     4,
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
       4,     5,     1,     1,     1,     1,     0,     3,     2,     2,
       2,     0,     3,     2,     1,     0,     3,     2,     0,     4,
       2,     0,     1,     1,     1,     1,     3,     0,     2,     1,
       3,     3,     0,     3,     1,     1,     1,     3,     7,     0,
       4,     7,     0,     2,     0,     2,     2,     3,     3,     3,
       2,     0,     3,     1,     1,     0,     1,     1,     0,     3,
       2,     1,     0,     4,     4,     0,     1,     0,     4,     4,
       0,     2,     3,     0,     1,     1,     0,     4,     4,     6,
       0,     2,     0,     2,     1,     2,     3,     0,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     3,     4,     1,     2,     3,     1,
       2,     3,     3,     0,     3,     0,     7,     0,     5,     0,
       2,     0,     2,     0,     3,     0,     2,     4,     0,     2,
       4,     0,     4,     4,     0,     3,     0,     4,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     1,     0,
       1,     0,     4,     2,     0,     2,     4,     4,     0,     1,
       1,     1,     1,     1,     0,     4,     5,     1,     2,     1,
       3,     3,     0,     4,     0,     1,     0,     4,     4,     6,
       6,     0,     1,     2,     0,     1,     0,     3,     1,     2,
       0,     3,     5,     0,     3,     2,     0,     1,     1,     0,
       4,     6,     0,     3,     1,     3,     2,     2,     2,     3,
       0,     3,     0,     3,     0,     3,     0,     1,     0,     3,
       1,     1,     1,     1,     1,     7,     0,     1,     1,     1,
       1,     1,     1,     4,     1,     2,     1,     2,     3,     0,
       1,     2,     1,     3,     1,     1,     4,     1,     1,     1,
       0,     4,     5,     0,     2,     0,     4,     3,     3,     1,
       1,     1,     1,     0,     1,     2,     0,     2,     0,     2,
       2,     0,     2,     0,     2,     2,     0,     2,     0,     2,
       2,     0,     2,     0,     2,     2,     1,     2,     1,     1,
       2,     2,     2,     1,     1,     2,     2,     2,     0,     2,
       0,     2,     0,     2,     1,     1,     0,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     2,     2,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     2,     2,
       1,     1,     1,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     3,     1,     1,     2,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
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
       3,     0,     0,     1,     0,     1,     1,     0,     1,     0,
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
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     2,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     0,     1,     0,     1,     1,     0,     1,
       1,     0,     2,     2,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     0,     1,     0,     1,     0,     2,     1,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     2,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     1,     0,     1,     0,     3,     0,
       1,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     2,     3,     2,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     2
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
       0,   175,     0,    17,    12,    19,    15,     0,    34,    30,
    1778,    46,     0,     0,     0,  1821,  1778,  1778,  1778,     0,
       0,     0,     0,     0,  1778,     0,     0,  1753,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     150,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     177,     0,     0,    23,  1779,     0,     0,  1506,   125,  1778,
    1778,  1822,  1778,     0,     0,     0,     0,  1778,  1778,    60,
      82,     0,    54,    98,  1754,     0,  1778,     0,    99,   102,
       0,   149,     0,   181,    20,    13,    29,    37,    40,    42,
      41,  1815,    39,  1778,     0,     0,     0,  1574,   171,  1498,
     169,   174,   176,     0,     0,    62,    84,   173,    56,  1507,
     152,   153,  1780,   156,  1579,  1198,  1197,   116,   120,  1807,
    1778,     0,   100,   151,   178,   179,    38,  1816,    36,     0,
    1586,  1582,  1587,  1585,  1583,  1588,  1584,   160,   161,   163,
     172,   167,  1865,  1866,     0,   165,     0,  1752,     0,     0,
       0,  1778,  1889,    80,    61,  1751,    66,    68,    69,    70,
      71,  1751,     0,  1778,     0,    83,     0,    87,    55,    58,
     154,  1782,  1781,   157,     0,  1807,  1810,  1809,     0,     0,
     117,   121,     0,     0,   267,   182,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   162,     0,  1850,   166,     0,  1575,   170,  1888,  1778,
       0,     0,    65,    67,    63,    81,  1751,  1778,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1580,
     155,   158,     0,  1808,   123,   118,   119,   122,   180,     0,
       0,  1649,     0,   279,   275,    24,     0,   270,   272,   273,
     134,   137,     0,   164,     0,     0,  1887,    74,    64,     0,
    1499,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     159,   124,   185,  1650,   183,  1759,   276,   277,   278,  1741,
     286,     0,   268,   271,     0,   136,   168,     0,    77,    79,
      78,    75,    76,    95,    59,   186,  1760,  1834,  1742,  1763,
       0,   288,   269,   138,   139,  1873,  1874,    72,  1817,  1835,
    1755,  1764,     0,     0,     0,   290,     0,  1796,  1851,  1842,
       0,   245,     0,  1778,  1751,  1783,   247,     0,  1854,  1849,
     233,   184,   232,   187,   188,   189,   190,   191,   192,     0,
     193,     0,   194,   244,   195,   196,   197,   198,   199,   200,
    1747,  1778,  1756,     0,  1484,   274,  1482,   287,     0,    25,
     140,  1797,  1778,  1852,  1783,  1843,  1844,   212,  1853,   248,
    1817,  1778,  1778,  1784,  1778,  1778,   261,  1741,   262,     0,
    1778,  1796,  1748,     0,     0,   280,   281,   284,  1483,   289,
     296,   297,   348,   291,   351,     0,     0,  1778,   214,   213,
     210,  1818,   247,   243,     0,     0,     0,     0,   260,  1811,
    1811,     0,   263,     0,  1778,   246,   229,   282,     0,   283,
       0,   497,   292,  1631,     0,   293,   222,   223,   221,   220,
       0,   206,   207,   217,   217,     0,   217,   209,   208,   217,
       0,  1505,  1504,   249,   250,   251,  1503,   259,  1812,   264,
     265,   266,   230,     0,   285,     0,     0,   500,   353,     0,
       0,   357,     0,   295,   298,  1634,   218,   203,   219,   204,
    1759,   205,   202,   215,   201,   216,  1778,   253,   255,   239,
     238,   239,   235,   349,     0,     0,   503,   356,     0,   354,
       0,   363,   364,   358,     0,   361,  1778,  1884,     0,     0,
     255,   226,  1635,  1636,   211,   254,   252,     0,     0,   237,
     236,   351,   498,     0,     0,   598,   355,   360,   397,   366,
    1755,  1778,     0,     0,  1778,  1755,  1796,  1778,  1739,   294,
       0,   299,   302,   303,   304,   305,   306,   307,   308,   309,
     310,     0,     0,  1886,  1883,     0,  1634,     0,   224,   257,
     258,   256,     0,   242,   350,   351,   501,     0,     0,    26,
    1778,  1743,     0,     0,     0,  1778,  1739,     0,     0,     0,
       0,     0,  1778,   344,  1740,   345,     0,   343,   346,   300,
     301,  1885,   226,     0,     0,   499,   351,   504,     0,   661,
       0,   484,   421,  1823,  1823,  1823,  1823,  1823,  1845,   422,
     457,   459,   425,   426,   427,   428,   429,   430,   453,   451,
     452,   454,   455,   460,   458,   431,  1819,   456,     0,   432,
     418,   433,   434,     0,     0,  1826,   436,   437,   435,  1785,
     439,   440,   438,  1778,  1780,   398,   399,   400,   401,   402,
     403,   419,   423,   424,   404,   405,   406,   407,   408,   409,
     410,   411,   412,     0,     0,  1744,     0,   394,     0,   367,
     322,   342,  1875,  1876,  1502,   331,  1500,  1868,  1867,   324,
    1794,  1753,  1767,     0,  1778,   328,   327,  1778,   347,   225,
       0,   147,   148,   228,     0,  1871,  1872,   240,   502,   506,
     599,     0,    27,   705,   495,   496,  1824,   450,   449,   442,
     441,   448,   447,   446,   445,   444,   443,  1846,     0,  1820,
     481,   467,   413,  1568,   493,  1827,  1786,  1787,   482,     0,
       0,   415,   417,  1663,  1663,   396,     0,  1803,  1597,     0,
       0,  1593,  1598,  1596,  1594,  1599,  1595,   395,   368,  1589,
    1591,     0,   312,  1501,  1795,   333,     0,   315,  1768,  1828,
     341,     0,     0,   227,   241,   505,   601,   663,     0,     0,
     483,     0,  1838,     0,  1566,  1567,     0,   420,   485,   487,
     489,     0,   414,  1751,   461,   462,  1590,  1804,     0,     0,
     377,   373,   376,   375,   374,   389,   385,   387,   388,   390,
     386,   391,   392,   393,   370,   381,   382,   383,   378,   379,
     380,   372,   369,     0,   323,   314,   313,   311,   332,  1753,
    1829,   320,   329,   326,   330,   325,     0,   507,     0,   605,
     600,   602,     0,   666,   664,   682,     0,   759,   828,   837,
     843,   850,   882,   886,   900,   895,   901,   902,   910,   956,
     965,   968,   994,  1005,  1008,  1011,  1003,  1017,  1024,  1046,
    1050,  1086,  1088,  1092,     0,  1098,  1115,  1139,  1157,  1158,
    1161,  1162,  1167,  1175,  1176,  1189,  1223,  1241,     0,  1274,
    1286,  1294,  1296,   687,  1300,  1303,  1309,  1360,   707,   708,
     709,   710,   711,   712,   713,   714,   716,   715,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,   706,   468,
    1839,   469,  1615,  1610,  1621,     0,  1471,  1473,     0,     0,
       0,  1613,     0,  1475,  1614,  1616,  1617,     0,     0,     0,
       0,  1612,  1621,  1611,  1455,  1453,  1460,  1463,  1465,  1468,
    1533,  1470,  1530,  1564,  1531,  1532,  1618,     0,     0,     0,
    1565,   494,   491,   488,     0,   416,  1664,   371,   384,  1592,
       0,     0,   334,   335,   336,   337,     0,   316,  1766,   322,
       0,  1485,   508,     0,   606,     0,   603,   671,   671,     0,
       0,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,  1733,  1734,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,
    1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1665,  1711,  1712,  1713,
    1714,   758,     0,     0,     0,     0,   853,     0,     0,     0,
       0,     0,     0,     0,  1416,   996,     0,     0,  1840,   873,
     872,     0,  1016,  1416,     0,     0,     0,     0,     0,     0,
     757,     0,  1127,     0,     0,     0,     0,     0,     0,     0,
       0,  1270,  1273,  1261,  1271,  1272,  1263,     0,     0,  1295,
    1293,     0,   705,     0,     0,     0,     0,  1805,   472,     0,
    1608,  1534,  1535,  1536,     0,     0,     0,     0,     0,     0,
       0,  1467,     0,  1466,     0,  1609,  1456,  1457,  1576,     0,
       0,     0,     0,     0,     0,     0,     0,  1600,     0,     0,
       0,     0,   486,     0,   490,   340,   339,  1745,  1753,   321,
       0,   608,   609,   604,  1750,   671,   668,   674,     0,   671,
     683,   658,   781,   826,   784,   780,  1803,     0,     0,  1524,
     835,  1518,   833,  1513,  1515,  1516,  1517,   838,     0,  1637,
    1495,   844,   845,     0,  1491,  1493,  1492,   856,   854,   855,
     880,     0,  1546,   883,   884,  1545,   887,   890,  1803,   898,
       0,  1477,  1651,  1510,  1569,  1573,  1511,     0,   908,  1817,
    1593,   954,  1381,   919,   923,  1513,     0,  1515,   963,     0,
     857,   966,   975,   974,   992,     0,   971,   973,  1415,     0,
     998,  1002,  1000,  1003,  1001,   995,  1006,  1007,  1508,  1009,
    1010,  1841,  1012,  1489,  1004,  1836,  1414,  1025,  1027,  1047,
    1048,  1051,     0,  1053,  1054,  1055,  1087,  1227,  1561,  1562,
       0,  1089,     0,  1096,     0,  1105,  1102,  1104,  1103,  1099,
    1106,  1129,  1495,  1116,  1127,  1118,     0,  1125,     0,  1547,
    1492,  1549,     0,  1155,  1643,  1159,  1363,  1480,  1165,  1817,
    1173,  1363,     0,  1187,  1180,  1481,     0,  1488,  1190,  1191,
    1192,  1193,  1194,  1195,  1216,  1196,  1219,     0,  1486,     0,
       0,  1560,  1573,  1224,  1259,  1246,  1264,  1749,  1284,     0,
    1277,  1279,     0,  1291,     0,  1297,  1298,   693,   699,   688,
     689,   690,   692,     0,  1301,     0,  1304,  1306,  1326,  1312,
    1373,  1363,  1806,     0,   476,   471,  1623,  1455,  1453,  1472,
    1474,  1455,     0,     0,     0,  1455,  1527,  1528,  1529,     0,
    1476,  1469,  1455,     0,  1454,  1577,     0,  1459,  1458,  1462,
    1461,  1464,     0,     0,  1455,     0,  1778,  1746,     0,   318,
       0,  1778,  1825,   669,  1778,     0,   680,   672,   673,   684,
     827,   760,  1746,   794,   785,     0,     0,     0,     0,  1519,
    1520,  1521,   836,   829,     0,     0,  1514,  1639,  1638,   841,
     846,   848,     0,   881,   851,  1548,   857,   885,   890,  1877,
    1878,   888,     0,   891,     0,   899,   896,  1860,  1859,  1478,
       0,  1653,  1479,  1571,  1572,   905,   906,   909,   903,  1408,
     955,   911,   702,     0,   917,  1383,     0,   934,     0,   928,
    1381,  1381,  1381,  1381,   964,   957,     0,     0,   858,   967,
     993,   969,  1416,  1416,   970,   977,   978,   702,  1440,  1441,
    1442,  1436,  1840,  1428,  1448,  1451,  1450,  1452,  1444,  1435,
    1434,  1439,  1438,  1437,  1443,  1423,  1427,  1445,  1447,  1449,
    1425,  1426,  1422,  1424,  1417,  1418,  1429,  1430,  1431,  1432,
    1433,  1421,   999,   997,  1509,  1014,  1837,   702,  1029,     0,
    1049,     0,  1076,  1060,  1052,  1057,  1058,  1059,  1231,     0,
    1563,     0,     0,  1097,  1093,     0,  1106,  1849,     0,  1117,
    1123,  1124,   702,  1120,  1416,     0,     0,  1128,     0,  1156,
    1140,  1644,  1645,  1817,     0,  1160,  1166,  1163,  1142,  1174,
    1168,  1170,  1182,  1188,  1177,     0,  1182,     0,  1541,  1542,
    1217,  1220,     0,     0,  1487,  1200,     0,  1199,     0,     0,
    1571,  1260,  1242,  1248,  1778,  1249,  1244,     0,  1262,     0,
       0,  1285,  1275,     0,  1278,     0,  1292,  1287,     0,  1299,
     700,   698,   691,     0,  1307,  1308,  1305,  1327,  1310,  1749,
       0,  1374,  1361,  1365,   470,  1749,   466,   474,   475,  1783,
    1622,     0,  1618,  1618,  1618,     0,  1604,     0,  1618,  1578,
       0,  1618,  1618,  1848,     0,   338,  1805,   317,   512,  1778,
    1778,  1739,  1791,   537,   511,   515,   516,     0,  1761,   623,
    1778,   613,  1845,   614,  1856,  1855,     0,  1778,     0,   626,
     617,   622,  1798,   618,     0,   621,   628,   625,   619,   624,
       0,   629,   620,     0,   640,   634,   638,   637,   635,   639,
     610,   641,   636,     0,  1798,     0,  1778,   681,     0,     0,
     659,   790,   795,   796,  1798,  1798,   788,   789,  1798,   776,
    1376,  1858,  1857,   773,   765,   767,   768,     0,  1376,     0,
       0,     0,   782,   771,     0,   779,   762,   778,   763,  1538,
    1537,     0,  1523,     0,  1803,  1386,   834,  1573,  1511,     0,
    1641,   841,     0,   839,     0,     0,  1494,   868,   889,   894,
       0,     0,  1512,  1386,  1778,  1652,  1570,   907,   702,   904,
    1410,  1382,   703,   921,  1745,   702,  1380,   927,   926,   925,
     924,   935,  1381,  1778,   938,     0,   941,   942,     0,  1778,
     945,   946,   947,   948,     0,   949,  1381,   936,     0,   796,
     914,   915,   912,   913,     0,  1386,     0,   864,   972,   987,
     989,   988,   982,   984,   990,  1416,   979,   976,  1416,   980,
    1446,  1419,  1420,  1805,  1013,  1490,   702,  1021,  1022,  1840,
    1037,  1038,  1040,  1042,  1043,  1039,  1041,  1032,  1840,  1028,
       0,  1077,     0,  1079,  1078,  1080,  1062,  1072,     0,     0,
    1056,     0,  1233,     0,  1769,     0,  1090,  1386,     0,     0,
       0,  1111,  1121,  1134,  1130,  1135,  1131,  1136,     0,  1126,
    1370,  1369,  1133,  1142,  1364,  1557,  1558,  1559,     0,     0,
    1408,     0,   702,     0,  1181,     0,     0,     0,  1218,     0,
    1222,  1221,  1214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1202,  1203,  1646,  1408,     0,  1265,  1832,  1832,
    1280,  1281,  1282,     0,  1386,     0,     0,   701,     0,  1632,
       0,  1282,  1170,  1735,     0,  1778,  1630,  1605,  1606,  1607,
    1628,  1625,  1626,  1603,  1619,     0,  1601,  1602,   492,     0,
       0,  1904,  1905,  1778,  1739,     0,   509,   513,  1762,   517,
       0,     0,   611,   612,   615,   616,     0,   643,  1799,  1778,
    1838,  1778,   644,   642,   656,  1778,   675,   676,   679,     0,
     670,   685,   687,  1778,   798,     0,     0,   786,   787,     0,
     702,   777,  1378,   764,   766,  1376,   774,   769,   770,   783,
     772,  1540,  1522,  1539,  1651,     0,   702,   830,  1388,  1571,
    1572,  1386,     0,  1640,   840,   842,   849,   847,   876,  1776,
     893,   892,   897,     0,  1409,   702,  1407,   705,  1384,   916,
       0,   939,   940,   943,   944,     0,  1412,  1412,   937,   918,
     930,   931,   929,   932,     0,   958,     0,   859,   860,   674,
       0,  1416,  1416,   986,   702,   983,     0,  1020,   702,  1023,
    1018,     0,     0,  1044,     0,     0,     0,  1073,  1075,     0,
    1068,  1082,  1069,  1070,  1061,  1064,  1082,  1225,  1778,  1783,
       0,  1770,  1232,  1091,  1094,     0,  1111,  1811,  1811,     0,
    1107,  1114,  1100,     0,  1122,  1119,     0,     0,  1144,  1143,
     702,  1164,  1396,  1169,  1171,     0,  1183,  1416,  1416,  1178,
    1184,  1201,  1213,  1215,  1205,  1206,  1207,  1211,  1208,  1212,
    1209,  1210,  1204,  1647,  1258,     0,  1255,  1256,  1250,     0,
    1243,  1882,  1881,     0,  1833,  1268,  1268,  1391,     0,  1651,
    1288,     0,   694,     0,  1633,  1313,  1314,     0,  1317,  1320,
    1324,  1318,  1408,  1736,     0,   480,   477,   478,     0,  1620,
     319,   514,  1792,  1793,  1581,   525,   522,   362,   538,   518,
     519,  1552,   633,  1550,  1551,   632,   649,   655,     0,   652,
     677,   678,   687,   705,     0,     0,  1376,   791,   793,   792,
    1377,   702,  1375,   775,  1386,  1512,  1387,   702,  1385,  1570,
     831,  1642,  1543,  1544,  1863,  1864,   878,   702,  1803,  1777,
     875,   874,   870,     0,  1655,  1656,  1657,  1658,  1659,  1660,
    1661,  1662,  1654,  1411,     0,   951,   950,   953,     0,  1555,
    1556,   952,     0,   922,  1386,  1477,  1386,  1477,   861,   862,
       0,   866,   865,   867,   985,   991,   981,  1015,  1019,  1030,
    1033,  1034,  1757,  1026,  1840,  1031,  1082,  1082,     0,  1067,
    1065,  1066,  1071,  1235,     0,  1229,  1771,  1386,  1101,  1108,
    1109,  1110,  1113,     0,  1137,     0,     0,  1151,     0,  1400,
     702,  1395,  1172,   702,   702,  1185,  1257,  1247,  1251,  1252,
    1253,  1254,  1245,  1266,  1269,  1267,   702,  1276,  1393,  1778,
    1386,  1386,   696,  1302,  1632,  1316,  1767,  1322,  1767,  1391,
     702,   702,  1362,  1372,  1403,  1404,  1371,  1368,  1367,  1788,
     479,   473,  1496,   521,  1869,  1870,   524,   364,   539,   520,
     647,   645,   648,   646,   650,   651,     0,   627,   653,   654,
       0,   705,   797,   802,  1778,   803,   804,   805,  1778,   806,
     807,   808,   809,   810,   811,   812,   814,   815,   816,     0,
     817,  1737,   818,   819,   820,   799,   800,   761,  1379,   832,
    1389,   702,   852,   877,     0,   869,  1879,  1880,  1413,   933,
     960,     0,   959,     0,   863,  1035,  1758,     0,     0,  1063,
    1074,  1082,  1774,  1774,  1083,     0,     0,  1238,  1234,  1228,
    1095,  1112,     0,  1145,  1778,  1408,     0,     0,  1146,     0,
    1150,  1401,  1179,  1186,  1392,   702,  1390,     0,  1290,  1289,
    1328,   695,     0,  1315,     0,  1767,  1319,     0,  1311,  1405,
    1406,  1402,  1789,  1790,  1366,  1497,     0,  1778,  1778,     0,
     526,   527,   528,   529,   530,   531,     0,   541,   630,   631,
       0,     0,     0,  1778,  1412,  1412,  1738,     0,   801,   879,
     871,  1386,  1386,     0,  1045,  1081,  1775,     0,     0,  1778,
    1236,     0,     0,  1226,  1230,     0,     0,  1141,  1154,  1398,
    1399,  1153,  1149,  1147,  1148,  1394,  1283,  1336,   697,  1321,
       0,  1325,  1891,  1890,  1778,     0,     0,  1893,     0,  1778,
    1778,   523,  1825,     0,   822,   821,     0,   824,   823,   825,
    1553,  1554,   962,   961,  1036,  1085,  1084,     0,  1239,  1778,
    1416,  1152,  1397,  1359,  1358,  1337,  1329,  1330,  1737,  1331,
    1332,  1333,  1334,  1357,     0,     0,  1323,     0,   536,   532,
    1892,     0,     0,  1772,  1800,  1739,     0,     0,     0,  1778,
    1803,   540,  1778,  1778,     0,   546,   548,   557,   549,   551,
     554,   542,   543,   544,   553,   555,   558,   545,     0,   550,
       0,   552,   556,   547,  1800,  1739,   686,   813,  1237,     0,
    1138,     0,  1830,     0,  1805,   533,   535,   534,  1773,   596,
    1801,  1802,  1780,   582,  1778,   467,  1416,     0,     0,     0,
       0,     0,   590,     0,   580,   586,   589,     0,   583,   591,
     594,  1780,   585,  1240,     0,  1831,     0,  1355,  1354,  1353,
       0,   581,     0,  1838,   578,  1651,   574,  1525,  1895,     0,
       0,  1897,  1899,     0,  1903,  1901,   559,   563,   567,   567,
     561,   565,   560,   566,   597,     0,   588,   587,   593,   592,
     584,  1356,  1862,  1861,  1813,  1349,  1343,  1344,  1346,   572,
     469,   595,  1805,   573,  1526,  1894,  1898,  1896,  1902,  1900,
     570,   562,   570,   564,     0,  1814,  1805,  1352,  1347,  1350,
       0,  1345,   464,     0,     0,   569,   568,     0,     0,  1351,
    1348,     0,   463,   577,   575,   576,   571,   579,  1342,  1339,
    1341,  1340,  1335,  1338,   465
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    30,
      12,    31,    44,    45,    34,    35,    19,   320,   432,   629,
      32,    50,    14,    25,    37,    95,   131,   132,    20,    29,
      41,    69,    70,   148,   208,   267,    71,   145,   194,   195,
     196,   197,   198,   199,   200,   331,   201,    72,   146,   205,
     206,   207,   262,   304,   263,    73,    74,    75,    76,    77,
     116,   157,   276,   158,    78,   133,   237,   238,   239,   324,
     343,   240,   723,    79,   121,    80,   150,   151,   152,   270,
      81,   177,   178,    82,    83,   244,    84,    85,    86,    87,
      88,    89,    90,   123,   224,   165,   225,   335,   348,   373,
     374,   479,   480,   440,   514,   507,   375,   469,   376,   588,
     377,   378,   379,   380,   381,   522,   549,   382,   383,   384,
     385,   386,   518,   546,   547,   589,   387,   388,   417,   389,
     452,   285,   286,   287,   288,   319,   289,   315,   425,   426,
     459,   341,   355,   399,   433,   434,   504,   435,   536,   571,
     572,   847,   573,  1687,  1029,   782,   574,   575,   717,   853,
     576,   577,   848,  1022,  1023,  1024,  1025,   578,   579,   580,
     581,   617,   461,   551,   462,   463,   498,   499,   558,   500,
     533,   534,   601,   777,   834,   835,   836,   837,   838,   501,
     697,   600,   675,   676,   677,   812,   678,   679,   680,   681,
     682,   683,   684,  2577,  2712,   685,   802,  1168,  1404,  1405,
    1669,  1666,  2176,  2177,   686,   687,   688,   689,   690,  1012,
     808,   809,  1202,   691,   692,   497,   595,   526,   626,   555,
     729,   795,   857,  1210,  1441,  1694,  1695,  1979,  2189,  1696,
    2185,  2343,  2460,  2461,  2462,  2463,  2464,  2465,  1976,  2188,
    2467,  2522,  2581,  2582,  2656,  2691,  2705,  2583,  2584,  2683,
    2714,  2585,  2586,  2587,  2588,  2589,  2590,  2624,  2625,  2628,
    2629,  2591,  2592,  2593,   599,   796,   860,   861,   862,  1212,
    1442,  1730,  2354,  2355,  2356,  2360,  1731,  1732,   732,  1449,
    2002,   733,   865,  1038,  1037,  1215,  1216,  1217,  1446,  1738,
    1040,  1740,  2202,  1162,  1389,  1390,  2322,  2441,  1391,  1392,
    1946,  1801,  1802,  2047,  1393,   799,   918,   919,  1112,  1223,
    1224,  1766,  1453,  1509,  1746,  1747,  1743,  2004,  2206,  2385,
    2386,  1451,   920,  1113,  1230,  1465,  1463,   921,  1114,  1237,
    1783,   922,  1115,  1241,  1242,  1785,   923,  1116,  1250,  1251,
    1519,  1837,  2067,  2068,  2069,  2038,  1131,  2232,  2226,  2392,
    1474,   924,  1117,  1253,   925,  1118,  1256,  1481,   926,  1119,
    1259,  1486,   927,   928,   929,  1120,  1268,  1495,  1498,   930,
    1121,  1271,  1272,  1503,  1273,  1507,  1829,  2062,  2253,  1812,
    1826,  1827,  1501,   931,  1122,  1278,  1515,   932,  1123,  1281,
     933,  1124,  1284,  1285,  1286,  1524,  1525,  1526,  1847,  1527,
    1842,  1843,  2073,  1521,   934,  1125,  1295,  1132,   935,  1126,
    1296,   936,  1127,  1299,   937,  1128,  1302,  1854,   938,   939,
    1133,  1858,  2080,   940,  1134,  1307,  1568,  1867,  2083,  2270,
    2271,  2272,  2273,   941,  1135,  1309,   942,  1136,  1311,  1312,
    1574,  1575,  1879,  1576,  1577,  2094,  2095,  1876,  1877,  1878,
    2088,  2279,  2414,   943,  1137,   944,  1138,  1321,   945,  1139,
    1323,  1584,   946,  1141,  1329,  1330,  1588,  2110,  2112,   947,
    1142,  1333,  1592,  2115,  1593,  1334,  1335,  1336,  1894,  1896,
    1897,   948,  1143,  1343,  1909,  2297,  2425,  2497,  1600,   949,
     950,  1144,  1345,   951,   952,  1145,  1348,  1607,   953,  1146,
    1350,  1910,  1610,   954,   955,  1147,  1353,  1616,  1913,  2129,
    2130,  1614,   956,  1148,  1358,   159,  1628,  1359,  1360,  1932,
    1933,  1361,  1362,  1363,  1364,  1365,  1366,   957,  1149,  1316,
    2283,  1578,  2419,  1882,  2097,  2417,  2493,   958,  1150,  1374,
    1935,  1636,  2145,  2146,  2147,  1632,   959,  1376,  1638,  2313,
    1156,   960,  1157,  1378,  1379,  1380,  2157,  1642,   961,  1158,
    1383,  1647,   962,  1160,   963,  1161,  1385,   964,  1163,  1394,
     965,  1164,  1396,  1656,   966,  1165,  1398,  1660,  2165,  2166,
    1951,  2168,  2327,  2446,  2329,  1658,  2442,  2507,  2546,  2547,
    2548,  2722,  2549,  2676,  2677,  2700,  2550,  2639,  2551,  2552,
    2553,   967,  1166,  1400,  1605,  1952,  1902,  2332,  1662,  2011,
    2012,  2212,  1504,  1505,  1806,  2027,  2028,  2218,  2317,  2318,
    2436,  2121,  2498,  2122,  2301,  2333,  2334,  2335,  1799,  1800,
    2046,  2247,  1305,  1306,  1288,  1289,  1554,  1555,  1556,  1557,
    1558,  1559,  1560,   994,  1189,  1408,   996,   997,   998,   999,
    1231,  1260,  1489,  1346,  1354,   395,   396,  1032,  1367,  1368,
    1565,  1337,  1244,  1245,  2341,   482,   301,   705,   706,   487,
     483,    98,   153,  1297,  1262,  1232,  1466,  2646,  1415,  1001,
    1771,  2022,  2096,  2221,  1254,  1338,  2192,  2529,  2248,  1904,
    2193,  1317,  1371,  1234,  1003,  1263,  1264,   753,   804,   805,
    2194,   271,  2626,   179,  1235,   779,   780,  1236,  1006,  1007,
    1008,  1197,  1170,  1423,  1419,  1412,   502,  2167,   541,  1469,
    1781,  2033,  1603,  2149,   282,  1492,  1795,  2242,   814,  1111,
    2174,  2477,   615,   339,   698,  1455,   423,  1218,   202,   115,
     393,  2407,   337,  1980,   352,  1030,   789,  2102,  2609,  2487,
    2233,    96,   214,   414,   758,  2454,  1975,   785,   402,  1989,
    2612,   818,  1403,   218,   489,  2696,   168,   390,   750,   102,
     738,   694,   851,  2636,  2155,   350,  1567,   971,  1303,   407,
     748,  1203,  1342,   404,   391,  1748,  1768,  1490,  2674,  2227,
     184,   709,  2346,   727,   347,   607,  1483,  2398,  2153,   542,
     543,   203,  2514,  2520,  2659,  2660,  2661,  2662,  2663,  1698
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2301
static const yytype_int16 yypact[] =
{
   -2301,   275,    31, -2301,  -200,   431, -2301,    31, -2301, -2301,
     735, -2301, -2301,   735,   735,   569,   569, -2301,   774, -2301,
     235,   586,   797, -2301, -2301,   967,   967,   622,   710, -2301,
   -2301,    10,   735,   569, -2301, -2301,   903,   746, -2301, -2301,
     752,  1752,   569, -2301, -2301, -2301,   586,   793, -2301, -2301,
     464, -2301,   792,   792,   830,   932,  1124,  1124,  1124,   965,
     792,   980,   921,   943,  1124,   959,   962,  1344, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,   972, -2301, -2301, -2301, -2301,
    1208, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
    1256,   984,    10, -2301, -2301,  1006,   297, -2301, -2301,  1124,
    1124, -2301,  1124,   971,  1399,   971,  1030,  1124,  1124, -2301,
   -2301,   971, -2301, -2301, -2301,   994,   -16,  1050, -2301, -2301,
    1000, -2301,  1063, -2301, -2301, -2301, -2301,  -161, -2301, -2301,
   -2301,  1144, -2301,  1124,   609,   971,  1264,   -17, -2301, -2301,
   -2301, -2301, -2301,  1268,  1062,   754,  1338, -2301,  1047, -2301,
     994, -2301,    68, -2301, -2301, -2301, -2301, -2301,  1136,   -78,
    1124,     8, -2301, -2301, -2301,   -67, -2301, -2301, -2301,   686,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,   609, -2301,  1113,
   -2301,  -169, -2301, -2301,   971, -2301,  1159, -2301,  1166,  1163,
    1517,  1124, -2301, -2301, -2301,   751, -2301, -2301, -2301, -2301,
   -2301,   455,  1527,  1124,    94, -2301,    93, -2301, -2301,    -8,
   -2301, -2301, -2301, -2301,  1348,   -78, -2301,  1362,   792,   792,
   -2301,  1136,  1156,    50,   -94, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,   591, -2301,
      79, -2301,   609, -2301, -2301,  1284, -2301, -2301, -2301,  1124,
    1218,  1367, -2301, -2301, -2301, -2301,   780,  1124,  1130,  1409,
     619, -2301,  1615,   657,  1193, -2301, -2301,  1196,  1543, -2301,
    1348, -2301,   792, -2301, -2301, -2301, -2301,  1136, -2301,  1202,
    1381, -2301,   792, -2301,   942, -2301,    92, -2301, -2301, -2301,
   -2301, -2301,   591, -2301,  1418,  1367, -2301, -2301, -2301,   603,
   -2301, -2301, -2301,  1438, -2301, -2301, -2301, -2301, -2301,  1427,
   -2301, -2301, -2301, -2301, -2301,  1249, -2301, -2301, -2301,  1681,
    1603,  1255, -2301, -2301,   591, -2301, -2301,    91, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1270, -2301,  1521,
    1588,  1257, -2301,  1696, -2301, -2301, -2301, -2301,  2135, -2301,
    1628, -2301,  1211,  1266,  1324, -2301,   591,  1449,  1371,   338,
    1322, -2301,  1326,  1124,  1668,   233,   -79,   511, -2301,  1223,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1306,
   -2301,  1468, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
    1692,  1124, -2301,  1211, -2301,  1211, -2301, -2301,  1283,   237,
   -2301, -2301,  1124, -2301,  1500, -2301, -2301,   107, -2301, -2301,
     940,  1124,  1124, -2301,  1124,  1124, -2301,  1681, -2301,   132,
    1124,  1449, -2301,  1336,  1238,  1211, -2301,  1412, -2301, -2301,
   -2301, -2301,  1240, -2301,  1245,    58,     2,  1124, -2301, -2301,
    1271, -2301, -2301, -2301,   -74,  1328,   971,  1246, -2301,  1435,
    1435,  1442, -2301,   971,  1124, -2301, -2301, -2301,  1367, -2301,
    1359,  1493, -2301, -2301,  1304, -2301, -2301, -2301, -2301, -2301,
     971, -2301, -2301,   364,   364,  1749,   364, -2301, -2301,   364,
     409, -2301, -2301, -2301, -2301,   800, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,   638, -2301,  1309,  1363,  1507,   279,  1313,
    6250, -2301,  1261, -2301, -2301,   739, -2301, -2301, -2301, -2301,
    1249, -2301, -2301, -2301, -2301, -2301,  1124, -2301, -2301,  1263,
   -2301,  1263, -2301, -2301,  1317,  1377,  1406, -2301,  1323, -2301,
    1327, -2301,  1688, -2301,  1694, -2301,  1393, -2301,  1657,   607,
   -2301,  1353, -2301, -2301, -2301, -2301,   971,   971,   -70, -2301,
   -2301,  1245, -2301,  1343,  1401,  1407, -2301, -2301, -2301,  1080,
    1628,  1124,  1120,  1120,  1124,    23,  1449,  1124,  1775, -2301,
    1492, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301,   792,    72, -2301, -2301,  1675,   400,  1300, -2301, -2301,
   -2301, -2301,  1491, -2301, -2301,  1245, -2301,  1351,  1410, -2301,
    6558,   161,  1599,  1367,  1303,  1124,  1775,  1305,  -100,   -74,
    1367,  1312,  1124, -2301, -2301, -2301,   -56,   792, -2301, -2301,
   -2301, -2301,  1353,    55,   869, -2301,  1245, -2301,  1357,   849,
      -5, -2301, -2301,  -179,  -178,  -132,   590,   665,  1315, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301,  1428, -2301,  1367, -2301,
   -2301, -2301, -2301,   971,   971,  1581, -2301, -2301, -2301,   -64,
   -2301, -2301, -2301,  1124,   133, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,    73,   -46, -2301,  1314, -2301,   264, -2301,
    1373, -2301, -2301, -2301, -2301,  1305, -2301, -2301, -2301, -2301,
    1563,    40,  1602,  1318,  1124, -2301, -2301,  1124, -2301, -2301,
     749, -2301, -2301, -2301,  1212, -2301, -2301, -2301, -2301, -2301,
   -2301,  1699, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1316, -2301,
   -2301,  1378, -2301,  1361,  1385, -2301, -2301, -2301, -2301,  6725,
     749,  1803, -2301,  1430,  1430, -2301,  1354,  1529, -2301,  1485,
    1485, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1390,
   -2301,  1367,    99, -2301, -2301, -2301,  1367, -2301, -2301,  1429,
   -2301,   490,   490, -2301, -2301,  1488,  1334,   116,  2689,  4016,
   -2301,  1367,  1397,  2398,  1383, -2301,   971, -2301,   749, -2301,
    1404,  1587, -2301,  1668, -2301, -2301, -2301, -2301,  1485,  1396,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,  1354, -2301, -2301, -2301, -2301,   166,  1344,
   -2301,   726, -2301, -2301, -2301, -2301,  1347, -2301,  6068, -2301,
   -2301,  1334,  1405, -2301, -2301,  1479,  4400, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301,   -12, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  1459, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,   492, -2301,
   -2301,  1523, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301,  1747, -2301, -2301,  1400,  1931,   -17,   -17,  1403,  1408,
    1411, -2301,  1413,   -17, -2301, -2301, -2301,  5137,  2398,  5137,
    1414, -2301,  1400, -2301,   105,   958,   342, -2301,  1698, -2301,
   -2301, -2301, -2301, -2301,  1390, -2301,  1417,  1419,  1420,  2398,
   -2301, -2301,   671, -2301,   749, -2301, -2301, -2301, -2301, -2301,
     -74,   -74, -2301, -2301, -2301, -2301,  1676, -2301, -2301,  1373,
    1367, -2301, -2301,  1421, -2301,  1433, -2301,   134,   134,  1364,
    1434, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301,   386,  3798,  2398,   507,   674,   516,  1211,   617,
     588,  5501,  5569,  1613,  -205,   876,   617,   971,  1425, -2301,
   -2301,  5569, -2301, -2301,   617,  1347,  1074,   971,  4495,  5569,
   -2301,  1036,  2847,  1211,   971,  1211,   971,    63,    56,   971,
    1211, -2301, -2301, -2301, -2301, -2301, -2301,  4761,  4904, -2301,
   -2301,  1347,    87,   971,  1211,   971,   971,  1565, -2301,  6863,
   -2301, -2301,  1390, -2301,  1376,  1382,  2398,  2398,  2398,  1931,
    1386, -2301,  -198, -2301,  1931, -2301, -2301, -2301, -2301,  2398,
    6985,  2398,  2398,  2398,  2398,  2398,  2398, -2301,  1931,  2398,
     958,  1484, -2301,  1439, -2301, -2301, -2301,  1859,  1344, -2301,
     351, -2301, -2301, -2301, -2301,   158, -2301,  -188,   397,   170,
   -2301, -2301, -2301,  1764,   745,  1700,  1529,   971,  1931, -2301,
    1766, -2301,  4940, -2301, -2301, -2301, -2301, -2301,   201,   720,
   -2301,   507, -2301,  1454, -2301,   -17, -2301, -2301, -2301, -2301,
    1763,  2717, -2301,   516, -2301, -2301,  1211,   798,  1529,  1768,
     496, -2301,  1518, -2301, -2301,  1361,  1390,  1211,  1771,  1556,
    1129,  1773,  5032, -2301,  5160,   183,  1141,  1172,  1774,   120,
    1415, -2301, -2301, -2301,  1772,    57, -2301, -2301, -2301,  4632,
   -2301, -2301,  1810,   -12, -2301, -2301, -2301,   617, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,  1472, -2301, -2301,   276,  1347,
   -2301, -2301,    14, -2301, -2301, -2301, -2301, -2301, -2301,  1452,
    5569, -2301,  1469,  1781,  1873, -2301, -2301, -2301, -2301,  1036,
    1519, -2301,  1480, -2301,  2919,   -20,   811,  1482,  1489, -2301,
     337, -2301,  1494,  1783,   -55, -2301,  1731, -2301,  1785,  1556,
    1787,  1731,   971,  1790,  1440, -2301,  1073, -2301, -2301, -2301,
   -2301, -2301, -2301,  1666, -2301,   617, -2301,   514, -2301,   251,
    1907, -2301,   118, -2301,  1793,  1086,   548,  1892,  1794,  4314,
   -2301, -2301,   971,  1795,  5288,  1347, -2301, -2301,  -123, -2301,
   -2301, -2301, -2301,  3721, -2301,  1753, -2301,  1219,  1798,  1839,
    1805,  1731, -2301,   971,  1744,   194, -2301,   293,   532, -2301,
   -2301,   259,  1520,  1522,  1524,   323, -2301,  1390, -2301,  1525,
   -2301, -2301,   340,  1526,   532, -2301,   976,   342,   342, -2301,
   -2301, -2301,  1025,  1528,   346,  1531,  1124, -2301,   -74,  1851,
    1532,   623,  6775, -2301,  1124,  1561,  1663, -2301, -2301,  1870,
   -2301, -2301,  1073,  1789, -2301,   887,  1487,   -19,  1536, -2301,
    1390, -2301, -2301, -2301,  5629,  1791, -2301,  1761, -2301,  1612,
   -2301,  1653,  1737, -2301, -2301, -2301,  1415, -2301,   798, -2301,
   -2301, -2301,   884,   690,   971, -2301, -2301, -2301, -2301, -2301,
    2398,  1723, -2301,  1383, -2301,  1211, -2301, -2301, -2301,  1765,
   -2301, -2301, -2301,  5569, -2301,  1703,   142,  1701,  1462,  1514,
    1840,  1840,  1840,  1840, -2301, -2301,  5569,  5629, -2301, -2301,
   -2301, -2301,  -205,    86, -2301,  1503, -2301,  1505, -2301, -2301,
   -2301, -2301,  1425, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  2997, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,   189, -2301,  1883,   963,  1837,
   -2301,  1073,    69, -2301, -2301,  1651, -2301, -2301,    46,  2398,
   -2301,  1571,   617, -2301, -2301,  5629,  1519,  1223,  1211, -2301,
   -2301, -2301, -2301, -2301,  1850,   971,   507, -2301,   973, -2301,
   -2301, -2301, -2301,  1556,  1074, -2301, -2301, -2301,  1792, -2301,
   -2301,   -98,  1890, -2301, -2301,   971,  1890,  1579, -2301,  1390,
   -2301, -2301,   494,  1136, -2301, -2301,  1949, -2301,  1979,   919,
     171, -2301, -2301, -2301,  1124, -2301,   -97,  5569, -2301,    27,
    5416, -2301, -2301,   971, -2301,  1836, -2301, -2301,  5629, -2301,
    1367, -2301, -2301,  1073, -2301, -2301, -2301, -2301, -2301,  1892,
    1814, -2301, -2301,   973, -2301,  1892, -2301, -2301, -2301,  1500,
   -2301,   971,  1417,  1417,  1417,  1931, -2301,   441,  1417, -2301,
    7136,  1417,  1417, -2301,   749, -2301,  1565, -2301, -2301,  1124,
    1124,  1775,  1243, -2301, -2301, -2301, -2301,  1829,  1869, -2301,
    1124, -2301,   475, -2301, -2301, -2301,  1475,  1124,  2717, -2301,
   -2301, -2301,  1748, -2301,  1367, -2301,  1990, -2301, -2301, -2301,
     971, -2301, -2301,   971, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,  1845,  1748,   837,  1124, -2301,  1546,  1600,
   -2301, -2301, -2301,  1780,  1748,  1748,   102,  1802,  1748, -2301,
    1894, -2301, -2301, -2301,  1548,  1552, -2301,  1073,  1894,  1824,
    1640,  1769, -2301, -2301,  1788, -2301, -2301, -2301, -2301, -2301,
   -2301,   517, -2301,   971,  1529,   525, -2301,     7,   -52,   617,
    1619,  1612,   617, -2301,  1623,   507, -2301,   -12, -2301, -2301,
    1690,  1711, -2301,   724,  1124, -2301, -2301, -2301, -2301, -2301,
    1782, -2301, -2301, -2301,  2046, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301,  1840,  1124, -2301,   513, -2301, -2301,  1481,  1124,
   -2301, -2301, -2301, -2301,   -23, -2301,  1222, -2301,  1446,  1780,
   -2301, -2301, -2301, -2301,  1875,   525,  1876,    42, -2301, -2301,
   -2301, -2301,  2063, -2301,  1639,   197, -2301, -2301,    86, -2301,
   -2301, -2301, -2301,  1565, -2301, -2301, -2301,  1954,  1944,  1425,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1719,  1425, -2301,
    1641, -2301,  2036, -2301, -2301, -2301,  1265, -2301,  1073,  1389,
   -2301,  1965,    81,   194,   -28,   617,   617,   525,  1887,  1211,
     349,   864,  1950, -2301, -2301, -2301,  2084, -2301,  1897, -2301,
   -2301, -2301, -2301,  1792, -2301, -2301, -2301, -2301,   971,  1968,
    1765,   902, -2301,  1593, -2301,  1598,  1073,   977, -2301,   517,
   -2301, -2301, -2301,  5569,  1136,  1136,  1136,  1136,  1136,  1136,
    1136,  1136,   919, -2301,   551,  1765,   -71, -2301,  1677,  1677,
   -2301, -2301,   328,   971,   525,  1899,  1652, -2301,  1660,  2099,
     971,   554,   -98,  2102,  1607,  1124, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,   989, -2301, -2301, -2301,   971,
     516, -2301, -2301,  1124,  1775,  1856,  1334, -2301, -2301, -2301,
     971,   410, -2301, -2301, -2301, -2301,   410, -2301, -2301,  1124,
    1397,  1124, -2301, -2301, -2301,  1124, -2301, -2301, -2301,   103,
   -2301, -2301, -2301,  1124,  1610,   410,   410, -2301, -2301,   410,
   -2301, -2301,  1821, -2301, -2301,  1894, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  1518,   -19, -2301, -2301,  1820,   212,
    1915,   525,   621, -2301, -2301, -2301, -2301, -2301,   -22,   109,
   -2301, -2301, -2301,   395, -2301, -2301, -2301, -2301, -2301, -2301,
     410, -2301, -2301, -2301, -2301,   410,   550,   550, -2301, -2301,
   -2301, -2301, -2301,  1616,   617, -2301,   617,   968, -2301,  -143,
     136,    86, -2301, -2301, -2301,  2063,   971, -2301, -2301, -2301,
   -2301,  1624,   934,   301,  1625,   621,  1073, -2301, -2301,  2071,
   -2301, -2301, -2301, -2301,  1389, -2301,  1936, -2301,  1124,  1500,
    1811, -2301, -2301,   617, -2301,   617,   864,  1435,  1435,  1816,
   -2301, -2301, -2301,  1033, -2301, -2301,   971,  5569,   906, -2301,
   -2301, -2301,  1838, -2301, -2301,  1865, -2301, -2301, -2301, -2301,
    1598, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,    15, -2301,   971, -2301, -2301, -2301,  1081,
   -2301, -2301, -2301,  2398, -2301,  5569,  5569,  1667,  1800,  1518,
   -2301,   617, -2301,   621, -2301,  1818, -2301,  1073, -2301,  2020,
    1704, -2301,  1017, -2301,  1031, -2301,  1607, -2301,   971, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301,  1402,   -58, -2301,   971,
   -2301, -2301, -2301, -2301, -2301, -2301,   820, -2301,   516,   820,
   -2301, -2301, -2301,   124,  2087,  2995,  1894, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  1724,  1933, -2301, -2301, -2301,  1934,
   -2301, -2301, -2301, -2301, -2301, -2301,  1847, -2301,  1529, -2301,
   -2301, -2301, -2301,   971, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  3528, -2301, -2301, -2301,  1423, -2301,
   -2301, -2301,  1462, -2301,   525,  1784,   525,  1786, -2301, -2301,
    5569, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
     934, -2301,  2042, -2301,  1425, -2301, -2301, -2301,   621,  1242,
   -2301, -2301,  1242,   -63,   971, -2301, -2301,   525, -2301, -2301,
   -2301, -2301, -2301,  1777, -2301,  2097,  1886,  1912,   614, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301,   532, -2301, -2301, -2301, -2301, -2301,  1863,  1124,
    1724,   525,  1670, -2301,  2099, -2301,  1602,  2060,  1602,  1667,
   -2301, -2301, -2301, -2301,  1868, -2301, -2301, -2301, -2301,  1426,
   -2301,   971, -2301,   998, -2301, -2301,  1856, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301,   410, -2301, -2301, -2301,
     410,   -31, -2301, -2301,  1124, -2301, -2301, -2301,  1124, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301,  2107, -2301, -2301,    -7,
   -2301,  2157, -2301, -2301, -2301,  2995, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,   971, -2301, -2301, -2301, -2301,  1462,
   -2301,   617, -2301,   617, -2301, -2301, -2301,  2117,  2058,  1242,
    1242, -2301,  1714,  1714, -2301,  1834,  1211,    -6, -2301,   971,
   -2301, -2301,  5569, -2301,  1124,   589,  1910,  1911, -2301,  1913,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,   971, -2301, -2301,
   -2301, -2301,  1725, -2301,   971,  1602, -2301,   971, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301,  1188,  1124,  1124,  1287,
   -2301, -2301, -2301, -2301, -2301, -2301,  1622, -2301, -2301, -2301,
    2065,   410,   410,  1124,   550,   550, -2301,   560, -2301, -2301,
   -2301,  1724,  1724,  5569, -2301,  1242, -2301,  5569,  5569,  1124,
    1211,  1211,  1841, -2301, -2301,  1702,   971, -2301, -2301,  1838,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,   719, -2301, -2301,
     971, -2301, -2301, -2301,  1124,  1856,  1856, -2301,  1967,  1124,
    1124, -2301,  1853,  1742, -2301, -2301,   516, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,   507,  1211,  1124,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1311, -2301,
   -2301, -2301, -2301, -2301,  1842,  2081, -2301,  1856, -2301, -2301,
   -2301,  1856,  1856,  1975,  1299,  1775,  1994,  1367,  1705,  1124,
    1529, -2301,  1124,  1124,   971, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,   881, -2301,
     -39, -2301, -2301, -2301,  1299,  1775, -2301, -2301, -2301,   507,
   -2301,  1832,  1796,    76,  1565, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301,   133, -2301,  1124,  1378, -2301,  7256,  7256,  1192,
    2085,  2014, -2301,  1367,   881, -2301, -2301,  1367,   -39, -2301,
   -2301,   133, -2301, -2301,   971, -2301,  1239, -2301, -2301, -2301,
      52, -2301,   881,  1397, -2301,  1518,  7240, -2301, -2301,  1067,
    1170, -2301, -2301,  1171, -2301, -2301, -2301, -2301,   -30,   -30,
   -2301, -2301, -2301, -2301, -2301,  7256, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  1874,   857,    52, -2301, -2301, -2301,
    1747, -2301,  1565, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
    1903, -2301,  1903, -2301,  2163, -2301,  1565, -2301, -2301,  1916,
     971, -2301,  1799,   -26,  1896, -2301, -2301,  7256,   575, -2301,
   -2301,  1367, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,  1211, -2301
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2301, -2301, -2301, -2301, -2301,  2212, -2301, -2301, -2301,   193,
   -2301,  2175, -2301,  2131, -2301, -2301,  1436, -2301, -2301, -2301,
    1457, -2301, -2301,  1375,  2199, -2301, -2301,  2101, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,  2025,
     602, -2301, -2301, -2301, -2301, -2301,  2082, -2301, -2301, -2301,
   -2301,  2023, -2301, -2301, -2301, -2301, -2301, -2301,  2156, -2301,
   -2301, -2301, -2301,  2011, -2301, -2301, -2301, -2301,  1995, -2301,
   -2301,   874, -2301, -2301, -2301, -2301, -2301,  2086, -2301, -2301,
   -2301, -2301,  2062, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,  1020, -2301, -2301, -2301,  1618,
   -2301, -2301, -2301, -2301, -2301, -2301,  1716, -2301,  1825, -2301,
   -2301, -2301,  1736,  1706, -2301,  1695, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,  1957, -2301, -2301, -2301, -2301, -2301,  1819,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,  1216, -2301, -2301, -2301,  1455,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  -325, -2301, -2301,  1750, -2301,  -769,
    -840, -2301, -2301, -2301,   407, -2301, -2301, -2301, -2301,   362,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -1414,   808,  1495,
     547,   604, -1411, -2301, -2301, -2301,  -364,  -425, -2301, -2301,
     376, -2301, -2301,    84, -1409, -2301, -1407, -2301, -1406, -2301,
   -2301,  1453, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,  -397,  -429, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -1300, -2301,
    -362, -2301, -2301, -2301, -2301, -2301, -2301, -2301,  1422, -2301,
   -2301, -2301,    65,    66, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,  1230,   250, -2301,   200, -2301,
   -2301, -2301, -2301, -1842, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301,  -695, -2301, -2301,  -711, -2301,  1471, -2301, -2301, -2301,
   -2301, -2301, -2301,  1048,   526,   528, -2301,   446, -2301, -2301,
    -109, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
     497, -2301, -2301, -2301,  1038, -2301, -2301, -2301, -2301, -2301,
     804, -2301, -2301,   215, -2301, -2301, -1254, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301,   803, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,   782, -2301, -2301, -2301, -2301, -2301,
      34, -1780, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,   765, -2301, -2301,   763, -2301, -2301,
     442,   218, -2301, -2301, -2301, -2301, -2301,   999, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
      21,   728, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301,   727, -2301, -2301,   205, -2301,   418, -2301,
   -2301, -1449, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301,   974,   715, -2301,   199, -2301,
   -2301, -2301, -2301, -2301, -2301, -2300,   975, -2301, -2301, -2301,
     190, -2301, -2301, -2301,   404, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301,   358, -2301, -2301, -2301, -2301, -2301, -2301,   695,   182,
   -2301, -2301, -2301, -2301, -2301,  -138, -2301, -2301, -2301, -2301,
     381, -2301, -2301, -2301,   951, -2301,   952, -2301, -2301,  1169,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,   159,
   -2301, -2301, -2301, -2301, -2301,   941,   368, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,    -3,
   -2301,   371, -2301, -2301, -2301, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  -353, -2301, -2301, -2301, -2301, -2301,
   -2301, -2301, -2301, -2301,  -273, -2301,   661, -2301, -2301, -1624,
   -2301, -2301,  -579, -2301, -2301, -1552, -2301, -2301,    -2, -2301,
   -2301, -2301, -2301,   -96, -2219, -2301, -2301,    -4, -1830, -2301,
   -2301, -1949, -1554, -1080, -1465, -2301, -2301,   778, -1758,   179,
     184,   185,   187,  -185,   135,  -789,   500,   354, -2301,   701,
    -551, -1385, -1096,   229,   986, -1563,  -386,  -197, -2301, -1320,
   -2301, -1060, -1358,   867, -2301,   -92,  2041, -2301,  1636, -2301,
    -564,    35,  2190, -1081, -1063,  -334, -1056, -2301, -1061, -1247,
   -2301,   424, -1267, -1270, -1111, -1167, -1216, -2301, -2301, -2301,
   -1131, -2301,   214,   845,  -639, -2301, -2301,  -103, -1209,  -778,
    -111,  2075, -1862,  2104,  -683,  1490,  -562,  -591, -2301, -2301,
   -2301,   -85,  1356, -2301, -2301,   520, -2301, -2301,  1767, -2301,
   -2301, -2301, -2301, -2301, -2301, -1982, -2301, -2301,  1585, -2301,
   -2301,  -194,  -605,  1939, -2301, -1186, -2301, -1327,  -278,  -651,
     950, -2301,  1848, -2301, -1454, -2301, -1357, -2301, -2301,   -51,
   -2301,    12,  -662,  -363, -2301, -2301, -2301, -2301,  -210,  -163,
    -244, -1210, -1548,  2142,  -446, -2301, -2301,  -887, -2301, -2301,
    1049, -2301, -2301, -2301,   422, -2301,   283, -1938, -1478, -2301,
   -2301, -2301,  -175, -2301,   485, -1404, -1486, -2301, -2301, -2301,
    -741, -2301, -2301,  1646, -2301,  1812, -2301, -2301, -2301,   795,
   -2301, -2301, -1703,  -240, -2301, -2301, -2301, -2301, -2301, -2301
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1850
static const yytype_int16 yytable[] =
{
     139,   703,   139,   415,   490,   160,   245,   427,   139,   428,
    1276,   138,   760,   141,   995,   778,  1457,  1370,  1034,   147,
     215,  1438,   798,  1261,   752,  1891,  1010,   858,  1724,  1791,
    1883,  1726,   139,  1727,   268,  1728,  1729,   793,  1734,   427,
    1895,   437,  2214,   180,  1287,   710,  2058,  1624,  1484,   465,
    1640,   279,  2197,  1308,  1850,  1243,  1493,  1233,  1844,   464,
     787,  2675,  1258,  1298,   720,  1275,  1279,  1369,   103,   104,
     105,  1298,  1352, -1805,  1522,  1304,   111,   810,  1871,  1775,
    2123,   246,  1322,  1324,  1476,  1298,   411,  -662,    99,  1617,
     211,  1214,   858,   321,   264,   107,   291,   114,  2470, -1849,
    2056,  1381,  1233,   259,   220,  2150,  1571,  1839,  2251,   392,
    1580,   134,   135,  2186,   136,  2228,  2474,   531,   714,   143,
     144,  1590,  1637,  1422,  -660,   810,  1872,   466,   161, -1749,
     841,   841,  1835,  1769,  2016,  2200,  1767,  1433,  1969,   215,
     297,   449,  1477,  2224,   360,   169,  2690, -1849,   345, -1562,
    2713, -1589,    42, -1783,   216,   211,   845,   715,   413, -1849,
    2203, -1805,  2415,  1630, -1849,  2259,  1704,   222,  1705,  1516,
     537,   863,   219,  2151,  1532,  1186,  2148,  2320,   756,   841,
     283,  1243,   481,  1214,   327,  1741,  1810,   695,  1938, -1849,
    2100,  1129,   592,   129,   419,   763,   221,  2491,  1027,  1182,
    1887,   182, -1563,   251,   816,  2637,  2500,  1214,   707,  1356,
   -1568,   454,  1005,  1452,  1020,   258,    94,  2184,  1839,  1214,
    1200,  1667,  1444,  2261,    43,  -662,   594,   736,   736,  -662,
    1601,     4,   438,  1561,  1564,  1174,  1175,  2598,  1807,   734,
     154,  2042,  1180,   619,   761,  1564,  1873, -1745,  1282, -1745,
    1421,    15,  1000,   274,   275,    94,   418,  1258,  1467,  1283,
    1191,   295,  -660,  1944,  1581,  1192,  -660,  1444,   768,   299,
     625,  1650, -1818,   766,   736,     3,   620,   762,   439,  1602,
    2542,  1019,  1258,  2065,  1622,    43,  2101,  -662,  1445,   183,
    2627,   155,   204,   156,   284,   130,   735,   737,   739,  2633,
     212,   728,  1298,  1853,  1870,  2076,  1564,   311,  1240,  1668,
    1874,  2492,   771, -1849,   767,   593,  1939,   314,   708,    28,
     757,  1770,   772,  1381,  -660,  1238,  2106,  1357,  1651,  1186,
     223,  1204,  1949,  1445,   243,  2104,  1171,  2229,  1954,  2152,
     280,   139,  2336,   139,   741,   217,   412,   494,  1517,   467,
     139,     5,  1440, -1849,   485,  1402,   612,   696,  2107,   154,
    2361,   492,   281,  1186,  1130,   212,   283,   139,  1261,   127,
     508,   508,     5,   508,  1625,   410,   508,   515,   505,  1572,
    1844,  2081,  1499,  1844,  1173,  2306,  1948,  1411,  1411,  1411,
    2084,  2213,  2160,  1186,  2031,   843,  1005,  1005,  1005, -1749,
    1424,  1426,   773,   424,   468,   243,   243,  1432,  1776,   430,
    1186, -1836,  -510,  1357,   436, -1566,  1186,  2230,  1005,   450,
    1387,  1261,   764,   444,   445, -1783,   446,   447,  -662,  2234,
     137,  1591,   453,  1745,  2416, -1745,  1000,  1000,  1000,  2225,
    -510,  -510,  1287,   139,   139,  1240,  2347,  1804,   716,   470,
    1573, -1849,   846,  1314,   590,   590,  1205,  1206,  1000,  2057,
    1834,  1836,  1608,   768,   260,  -660,   493,  1547,   128,   803,
     413,   721,   774,  1388,   137,  2475,   768,  1808,   137,  2220,
     284,   451,   368,   139,  2466,   137,   786,  1494,   768,  1261,
    2015, -1749,   700,  2262,   590,   243,   255,  2638,  1561,   711,
    1258,  1886,  1258,  1187,  1472,  1855,   139,   771,   769,   770,
    2070,   187,    97,  2074, -1745, -1749,   775,   772,   188,  1298,
     771,   292, -1778,  1005,   537,  2527,  2528, -1749,   545,  1888,
     772,  1258,   771,  2039,  -667,  1016,  1899,  1875,  1387,  1840,
   -1749,  1987,   772,   322,   265,  1315,  -665,   751,   582,  1881,
    1841,  1341,  1261,  1188, -1648,  -510,   137,  1439,  1523,  1564,
     137,   754,   394,  1000,  2025,   722,   776,   137,  2029,  2231,
    1922,   602,   149,   604,  2304,  1387,   609,   611,  1005,   613,
     803,  1937,  2387,  -510,  1941,  1005,  1005,  1005,  1418,  1459,
     261,  1388,  1945,  1418,  1494,  2501,   346,   773,  1005,  1005,
    1005,  1005,  1005,  1005,  1005,  1005,  1844,  1418,  1005,  -667,
     773,  2089,   693,   864,  1960,  2531,   618,   702,  1000,  2058,
     506,  -665,   773,  1258,   713,  1000,  1000,  1000,  1388,   431,
     766,  1021, -1749,  1009,  2263, -1818,  2108,  1461,  1000,  1000,
    1000,  1000,  1000,  1000,  1000,  1000,  1809,  2282,  1000,  2131,
    1840,   129,   718,  2558,  2559,  1487, -1749,  1187, -1849,  1191,
    1341,  1841,  2389,  2681,  1192,   513,   154,   774, -1749,   243,
     844,   519,  -510,  1026,  1009,   849,  2235,  2236,  2237,  2254,
     774,  2256,  1961,  1261,  1689,   759,  1508,   538,   854,   854,
     969,  1187,   774,   137,  1222,  2605,    94,  1626,  2109,  2606,
    2607,  1793,  2400,  1011,  2402,  2680,   768, -1629,   768, -1849,
    1532,   775,  1690,  1691,   226,  1796,  1903,  1191,  2120,  2035,
    2287,  1187,  1192,   189,   775,  2037,   791,  1982,  2630,   792,
     527,   584,  1257,  1627,  1269,  2420,   775,   768,  1187,  2238,
    2070,  1670,  1566,  1341,  1187,  2718,   852, -1836,  1151,  1437,
     771,  1129,   771,   130,  1447,   137,  2519,  1344,   766,  1349,
     772,   776,   772,  1240,  1375,  2051,  2630,   154,  2438,  2439,
    2195, -1627,  1252,  2021,   776,  1452,  2321, -1530,  1397,   243,
     137,   771, -1568, -1631,   405,  1357,   776,  1274, -1624,  2207,
    2208,   772,  1193,  2209,  1682,   190,  2408,   253,   416,   803,
    2719,  1194,  -510,   228,  2103,   520,   154,   187,  2720, -1745,
     187, -1745,   227, -1751,   188,  2276,  2184,   188,  1772,  2277,
    1798,   170,  1298,  1564,  1384,    23, -1763,  2409,  2410,   768,
    2426,   243,  1849,   768,  2245,   406,   187, -1849,  1152,  2246,
     773,  2143,   773,   188,  2144,  1792,  2543,   229,   -96,  -657,
    2427,   191,  1796,  2490,  2338,    94,   192,   230,   253,  2181,
     328,  2239,  2240,   537,  1983,   171,  2241,  2133,   137,  1996,
    1478,   773,  1857,   771,  1685,   172,  2428,   771,   351,  1153,
    2300,  1496,    16,   772, -1849,  2544,   305,   772,    18, -1530,
     137,  1965,  2721,  2323,   585,  1448,    27,  1892,   228,  1005,
    2325,  2429,  2052,   539,   137,   521,   254,   351,  1154,  1962,
     774,    24,   774,   137,   137,   -35,  2657,   139,   139,  1209,
    2191,  1906,  1028,  2545,  1130,  2249,  2249,     5,  2538,  2532,
    2533,  1830,  1831,  1832,  1833,    33,  2026,   232,  1310,  1000,
    1917,   774,   229,  1468,  1692,  1247,  1860,  1997,  1488,  1861,
    1862,  1704,   230,  1705,   775,   173,   775,  1924,  2339,   255,
    1623,   768,  2485,   773,  1386,  1925,   231,   773,  2255,  2444,
    2257,  2447,  1859,   117,  -864,  1860,   747,  -864,  1861,  1862,
    2521,  1900, -1765,    52,  1407,   775,  2600,  -657,  1005,   -96,
    1191,  -657,  2265,    36,   137,  1192,   736, -1745,   137,  2030,
     137,  1968,  1155,  1547,   776,   771,   776,   233,  2411,  1261,
    1901,   137,  1246,  1907,  1434,   772,  1265,  1214,  2394,   189,
     137,   137,   189,  1265,  1300,   174,   538,   306,  1000,   137,
      53,  1265,   232,   774,  1319,   776,  2595,   774,   329,  1340,
    1564,  1347,  1267,  1347,  1355,  1372,  1319,  2303,   189,  -657,
    -864,   243, -1763,  2555,   137, -1749,  2640,   243,   137, -1745,
   -1849,  2295,  2644,  1347,   137,  1261,   743,  -864,    54,   175,
      55,   736,    56,    39,  1693,  1290, -1745,   775,  1611,   394,
      57,   775,  1482,   766,  1418, -1849,  1972,  2357,  2510,  1005,
    2350,   190,   394,   154,   190,   773,  1248,   330,  1249,  2314,
    2314,   236,   233,  2044,    40,   234,   235,   300,  2575,  1797,
    2048,  2576,  1570,  2578,  2430,  2579,  2580,  1341,  2594,   176,
     190,   137, -1849,  2296, -1847,   137, -1849,   776,  1663,  1000,
    1926,   776,  2023,  1569,  2703,  2026,    58,  2184,  1246,  1744,
    2468,   745, -1849,   724,  2469,  2723,  1789,   191,  2708,  2351,
     191, -1849,   192,   516,  1479,   192,   972,  1265,   859,    48,
     361,  2077,  1927,  2697,  2124,   774,   325,  2622, -1849,  -864,
   -1530,  1790,  1201,   973,  2330,  2456,   191,   842, -1530, -1530,
    -864,   192,  1191, -1530,  1928,  2457,   731,  1192,  1649,  2125,
    -657,   517,   362, -1849,  1265,  2698,   236,    49,   344,  1291,
    1292,  1639,   252,    51,  2404,  1265,  1325,  2187,  2458,   775,
    2623,  1863,  1864,  -864,   516,  2699,  1293,  2126,  1745,  -864,
     725,  -864,   726,   859,  -864,  1017,  -864,  -864,  -864,    60,
     400,   298,  -864,  2049,  -864,  1865,  1866,  1929,  2459,  -864,
    1863,  1864,   539,  2111,    93,  2648,  2517,  2059,  1798,  1355,
    2412,  2219,   517,   100,  2685,  2524,  2525,  1813,   193,   776,
    1814,  1326,  1265,  1633,  1865,  1866,  1265,  1815,  1816,  1327,
    1294,  -864,  1480,    61,  1871,   974,  -864,  2560,  2352,  2413,
    2023,  2649,  2678,  2353, -1778,   768,   768,   154,  1534,  1535,
    -864,   441,  1594,   316,  2512,  2292,    97,  1930,  2512,   442,
     139,   243,  1357,  1482,  2513,  2481,  1955,  2482,  2513,  2331,
    1595,  1664,    94,  1817,  -864,  2210,   839,   839,  2678,  2476,
    2293,  2554,  1872,  1634,  2667, -1749,  1635,  1536,  1537,   771,
     771,  2216,   978,   979,   980,   139,  2244,   101,   981,   772,
     772,  2517,  2679,  2249,  2249,  -864,  2530,  2348,  2601,  2223,
    2243,  1318,  2337,  1328,   317,   318,    94,  2686,  2688,   106,
    2618,  1777,    64,  1318,  2312,   839,  2495,   243,   394,  2183,
    2645,  2647,   109,   840,   840,  1351,  2518,   982,  -864,  2266,
    2687,  2689,  1818,  2268,  -864,   108,  2215,  1502,   471,   472,
     473,    26,  1931,  2512,   110,  1401,  -864,  -864,  2090,  2684,
    2672,   114,  2223,  2513,  2673,    67, -1849,  1190,    47,   243,
     112,  1819,  1890,   113,  1777,  2597,  1191,    91,  2694,   773,
     773,  1192,   840,   118,  1679,  2299,   120,  2534,  -864,   122,
    1920,  2535,  2536,  1820,  1191,   124,  1911,  2179,  -864,  1192,
     560,  1921,  1873,   155,  -864,   156,  2091,  1191,  1684,    21,
      22,   984,  1192,  1697,  1733,   561,  1735,   126,  -864,    13,
    2717,  1936,  1246,  -864,    13,  1443, -1749,   140,    46,  1443,
    -864,   605,  -864,   606,  1680,   137,    68, -1076,  -864,  1265,
    2223,   142,  1777,  1191,   167,  1918,   819,  1821,  1192,   774,
     774,  1973,  1974,  1246,   509,   562,   511,  1813,   149,   512,
    1814,   162,   985,   986,   163,   428,  1874,  1815,  1816,   474,
     603,  1749,  1750,  2650,   164,   610,  2388,  2651,  2652,  1265,
     181, -1076,  2390,   475,   185,   820,   821,   822,   823,   824,
     186, -1076,  2393,   775,   775,   137,  1548,   204,  1549,  1947,
    1822,  2191,  2060,  2061,   990,  1777,  1671,  1429,  1430,  1431,
    1675,   193,  1751,  1817,  1752,   242,  1753,  1677,  2653,   247,
     640,   641,  1005,   725,   991,   726,   768,   248,   139,   992,
    1654,  1995,  1655,   249,  2654,  2655,   993,   137,   137,  1956,
     250,  2005,  2006,   776,   776,  2009,   257,  1957,  1958,  1959,
    1754,  1755,  1756,  1963,   273,  2223,  1966,  1967,  2610,  2611,
    1823,   768,  1000,  1990,   269,  2431,   476,   278,  2432,  2433,
     771, -1076,   294,  1824, -1546, -1546, -1546, -1546,   477,   296,
     772,  2434,  1818,   154,  1998,    94,  1510,  1511,  1512,  1513,
    2092,  1984,   563,  1985,   300,  2449,  2450,  2053,   302,  2054,
    1757,   303,  1758,   564,   307,   771,  1934,   308,  1002,  1759,
     309,  1819,  1760,   312,  2344,   772,  2345, -1545, -1545, -1545,
   -1545,  2289,  2290,   825,   826,   827,   828,   829,   830,   831,
     653,   654,  1265,  1820,   326,  2396,  1265,  2397,  2452,  1265,
    2453, -1076,  1246,   740,   742,   744,   746,  1751,  1181,  1752,
    1183,  1427,  1428,   313,   333,  1825,  2479,  1413,  1414,   334,
     773,  1970,  1971,   336,   338,   340,   342,   349,   478,   351,
     353,   354,  1981,   356,   392,   394,  2113,   397,   398,  1986,
     428,   401,   403,   408,   187, -1076,   243,  1821,   409,   420,
     421,   422,  1265,  1875,   429,   773,  2285,   413,   455,  1761,
    2505,  1762,   456,   458,   565,   566,   460,   484,  1999,  -352,
     486,   488,   491,   495,   496,   503,   510,   524,  1357,   567,
     523,   568,   525,    52,   529,   535,   548,  2158,   552, -1076,
     774,   553,   554,  -365,   556, -1076,  2158,  1911,   557,   559,
    1822,   583,  1265,  1265,  1265,   587,  2134,  2135,  2136,  2137,
    2138,  2139,  2140,  2141,   596,   597,   598,   614,   616,   621,
     624,   623,   627,   699,   628,   774,  2043,   701,   730,   704,
      53,   712,   749,   755,   775,   832,   747,   784,   765,   781,
     788,   797,   790,   803,   801,  2050,   800,   806,   833,   811,
     813,  2055,  1002,  1002,  1002,   817,   856,   843, -1631,   850,
    1823,  1265,   970,  1015,   569,  1009,  1014,  1018,    54,   775,
      55,  1031,    56,  1824,  1002,  1039,  1036,  2093,  1140,  1159,
      57,  1167,  1169,  1207,   776,  1176,   139,  1195,  1220,  1280,
    1177,  1301,  1211,  1178,  1402,  1179,  1184,  2180,  1319,  1196,
    1409,  1198,  1199,  1319,  1213,  1221,  1410,  1435,  2201,  1437,
    1420,   570,  1436,   137,  1450,  1473,  1456,  1462,   638,   776,
    1471,  1485,  1319,  1319,  1491,  1497,  1319,   441,  1500,  1520,
    1514,  1562,  1518,  1566,  1579,  1582,    58,  1704,  1751,  1705,
    1752,  1583,  1585,  1587,  1596, -1548,  1599,  1604,  1265,  1606,
    1763,  2113,  1609,  1598,  1597,  1825,  1613,  1357,  1629,  1615,
    1631,  1214,  1641,  2298,  1646,  2250,  2250,  1319,  1657,  1653,
    2641,  1659,  1319,  1319,  1319,  1226,  1661,  1225,   766,  1239,
    2613,  1265,  1255,  1265,  1665,  1686,  1277,  2178,  1672,  2670,
    1673,  1736,  1674,  1676,  1678,  1737,  1681,  1683,    59,  1739,
    1764,  1313,  1773,  1688,  1780,  2182,  1742,  1339,  1782,   137,
    2632,  1765,  1784,  1240,  1779,  1794,  1798,  1805,  1828,  1811,
    1265,  2196,  1265,  2198,  1845,  1502,  1848,  2199,  1395,    60,
    1399,  1856,  1869,   972,  1002,  2204,  1572,  1885,  1893,  1912,
    1908,  1002,  1002,  1002,  1416,  1916,  1005,  1005,  1923,  1416,
     973,   972,  1943,  1977,  1002,  1002,  1002,  1002,  1002,  1002,
    1002,  1002,  1950,  1416,  1002,  1978,  1991,  1988,   973,  1994,
    2000,  2001,  2003,    61,  1744,  1005,    62,  2013,  1265,  2010,
    2014,  2017,  2563,  2018,  2020,  2032,  1000,  1000,  2019,  2036,
    2040,  1319,  1458,  2041,  1005,   139,  1452,  2045,  2064,  2066,
    2071,  2072,  2078,  2079,  2082,  2086,  2342,  2085,   656,   584,
    2105,  2114,  2116,  2117,  2127,  1000,  1339,  2120,  1255,  2128,
    2154,  1919,  2161,  2162,   428,  2564,  2163,  2565,  2164,  2173,
    2284,  2175,  2184,  2205,  1000,  2211,  1005,  2217, -1567,  2252,
    2278,    63,  2269,  2275,  2281,  2286,  2291,  2302,  2316,  2300,
    2319,  2324,   974,  2326,  2362,  2026, -1523, -1565,  2566,   357,
    2328,  2391,    64,   768,  2406,  2401,  2422,  2403,  2423,  2424,
     974,  1265,   428,  1265,   358,  2445,  1000,  2421,  2567,  2435,
    2331,   768,  2440,  2473,   359,  2476,  2483,    65,  2484,    66,
    2486,  2489,  2502,  2503,  2523,  2504,  2508,  2560,  2539,  1339,
     660,   139,  2603,  2540,  1265,    67,  2568,   771,  2604,   978,
     979,   980,  2418,  2596,  1228,   981,  2608,   772,   360,  2634,
     976,  1618,   977,  2614,  2664,   771,  2616,   978,   979,   980,
    2665,  2695,  2707,   981,  2635,   772,  2704,  2716,  1265,    17,
    1229,    92,  2709,   125,  2711,    38,   256,  1645,   166,   266,
     209,   119,   277,   290,   982,   443,   210,   550,   139,   241,
     719,   540,   591,   323,   457,  1208,   586,   855,   528,  2455,
    1725,  2643,   982,  1319,   807,  2702,    68,  1319,   665,  2099,
    2340,  1013,  2693,  2706,  2358,  2359,  2669,  2569,  1219,  2260,
     968,   983,  1454,  2008,  2007,  2063,  2478,   773,  2034,  1470,
    1787,  1788,  2258,  1035,  2570,  1803,  2399,  1838,  1846,  2264,
    2075,  2405,  1563,  1004,  2087,   773,  1868,  1618,  1265,  2280,
    1265,  1889,  1880,  1586,  2571,  2288,  2294,  2118,   984,  1589,
    2172,  1915,  2305,  2142,  1620,  2315,  2494,  1621,  1373,  2170,
    1644,  2443,  2171,  2701,  1953,  2572,   984,  2448,  2308,  2499,
    2451,  2437,  1852,  2309,  2310,  1002,  2311,   428,  1612,  1786,
     332,   783,   213,  2132,  2573,   310,   293,   774,  1185,   815,
    2631,   674,  2574,   622,  2602,   361,   448,   272,   544,   985,
     986,  2156,  2488,  2250,  2250,   774,  2274,  2098,  1319,  1319,
     794,  1319,  1319,  1884,  1319,   608,  2471,   985,   986,  2658,
    2472,     0,     0,     0,     0,     0,     0,   362,     0,     0,
       0,   775,     0,     0,     0,     0,     0,  -234,     0,     0,
       0,   990,  1920,     0,     0,     0,     0,     0,     0,   775,
       0,     0,     0,  1921,     0,     0,  1618,     0,     0,   990,
       0,   991,     0,     0,  1002,     0,   992,     0,     0,     0,
       0,     0,     0,   993,  1246,   137,  2496,     0,     0,   991,
    1898,   776,     0,     0,   992,     0,     0,     0,     0,  1905,
     363,   993,     0,   137,     0,   364,  2615,     0,     0,   776,
    1914,     0,     0,     0,     0,  1172,     0,     0,     0,  2515,
    2516,     0,     0,     0,     0,     0,     0,  1004,  1004,  1004,
     972,     0,     0,     0,     0,  2526,   365,     0,  1942,     0,
       0,     0,     0,     0,   366,     0,  1246,   973,  1618,  1004,
       0,  2537,     0,     0,     0,     0,     0,   367,     0,     0,
       0,     0,  2666,     0,     0,     0,  2668,     0,     0,     0,
    1416,     0,     0,     0,     0,  1002,  2557,     0,     0,     0,
       0,  2561,  2562,     0,     0,     0,   368,  1246,     0,   369,
       0,     0,     0,     0,     0,     0,     0,   370,     0,     0,
       0,  2599,     0,  1339,     0,     0,     0,     0,  -231,     0,
       0,     0,     0,     0,     0,  1992,     0,     0,  1993,     0,
       0,     0,     0,  1246,     0,     0,     0,     0,     0,     0,
       0,  2617,     0,     0,  2619,  2620,   371,     0,     0,   372,
       0,     0,     0,     0,     0,     0,     0,  2710,     0,   974,
    2724,     0,  1618,     0,  1004,     0,     0,     0,     0,  1266,
     768,     0,     0,     0,     0,     0,  1266,     0,  2024,     0,
       0,     0,     0,     0,  1266,     0,  2642,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1266,     0,
       0,     0,     0,   975,     0,     0,     0,     0,     0,   976,
       0,   977,     0,     0,   771,     0,   978,   979,   980,  1004,
       0,     0,   981,     0,   772,     0,  1004,  1004,  1004,  1417,
       0,     0,     0,     0,  1417,     0,     0,     0,     0,  1004,
    1004,  1004,  1004,  1004,  1004,  1004,  1004,     0,  1417,  1004,
     866,     0,   867,     0,   868,     0,     0,     0,     0,   869,
       0,   982,     0,     0,     0,     0,     0,   870,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1460,     0,
     983,     0,     0,  1618,  1618,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     871,   872,     0,     0,   773,     0,     0,     0,     0,   873,
    1266,     0,     0,  2119,     0,     0,     0,     0,     0,     0,
     874,  1618,     0,   875,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   984,     0,   876,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1266,  2159,     0,
       0,     0,     0,     0,     0,  2169,  2169,     0,  1266,   972,
     877,     0,     0,     0,     0,     0,     0,     0,   878,     0,
     879,     0,     0,     0,   774,  1255,   973,     0,     0,     0,
       0,     0,     0,     0,     0,  2190,   985,   986,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   880,     0,     0,     0,     0,  1619,     0,     0,     0,
       0,     0,   881,     0,     0,  1266,   987,   882,   775,  1266,
     988,   989,     0,     0,     0,     0,     0,     0,   990,     0,
       0,     0,     0,     0,     0,     0,     0,  2222,     0,     0,
       0,     0,     0,     0,   883,     0,     0,     0,   991,     0,
       0,   884,     0,   992,   885,   886,     0,     0,     0,     0,
     993,     0,   137,     0,   887,     0,     0,     0,   776,     0,
       0,   888,     0,   889,     0,     0,   890,     0,   974,     0,
       0,  2267,     0,     0,     0,     0,     0,     0,     0,   972,
    2222,  1618,     0,     0,     0,     0,     0,     0,     0,  1618,
       0,     0,  1619,     0,     0,     0,   973,     0,     0,     0,
       0,     0,     0,     0,  1778,     0,     0,     0,   891,     0,
       0,  1898,   892,     0,   893,     0,     0,     0,     0,     0,
       0,     0,     0,  1475,   894,   978,   979,   980,     0,     0,
    1004,   981,     0,     0,     0,     0,     0,     0,     0,     0,
    2307,     0,     0,     0,     0,     0,     0,     0,  1002,     0,
     895,   972,     0,  1226,     0,     0,   766,  1778,  2222,  1528,
    1529,  1530,  1618,   896,     0,     0,     0,  1531,   973,     0,
     982,     0,     0,     0,     0,     0,     0,  2363,     0,     0,
    2364,     0,     0,  2365,  2349,     0,     0,  1331,   897,   898,
       0,  2366,     0,  1255,     0,     0,     0,     0,   974,   899,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1619,     0,   900,   901,     0,     0,     0,     0,  1004,
     902,     0,  1266,     0,   903,  1778,     0,     0,  2395,   972,
       0,     0,   904,     0,     0,     0,  2367,     0,     0,     0,
       0,     0,   905,     0,   984,     0,   973,     0,     0,     0,
       0,   906,     0,  1332,     0,   978,   979,   980,     0,  1331,
     907,   981,  1266,     0,     0,   908,   909,     0,     0,   910,
     974,   911,     0,  2222,     0,     0,     0,   912,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1778,     0,
     913,     0,     0,  1619,     0,   985,   986,     0,     0,     0,
     982,     0,     0,     0,     0,     0,  1532,     0,   914,     0,
       0,     0,     0,     0,   915,  1417,  1533,     0,     0,   916,
    1004,     0,     0,     0,     0,  1475,     0,   978,   979,   980,
       0,     0,     0,   981,  2368,     0,     0,   990,     0,     0,
       0,     0,     0,  2369,     0,     0,   917,     0,   974,     0,
       0,     0,     0,     0,  1534,  1535,  2370,   991,     0,   768,
       0,     0,   992,     0,     0,     0,     0,     0,     0,   993,
       0,   137,   982,     0,   984,     0,     0,     0,     0,  1851,
       0,     0,     0,     0,     0,     0,     0,     0,  2371,  2480,
       0,     0,  1228,  1536,  1537,     0,     0,  1619,   976,     0,
     977,     0,     0,   771,     0,   978,   979,   980,  2372,     0,
    2373,   981,     0,   772,     0,  1266,     0,     0,  1229,  1266,
       0,     0,  1266,     0,     0,   985,   986,     0,     0,     0,
       0,  1538,  2506,  2374,     0,     0, -1849,  1539,     0,  2509,
    1540,     0,  2511,     0,     0,     0,   984,     0,  1541,     0,
     982,     0,     0,     0,     0,  1542,     0,     0,     0,     0,
    1543,     0,     0,  2375,     0,     0,     0,   990,     0,   983,
       0,     0,     0,     0,     0,  1266,     0,     0, -1132,  1544,
       0,     0,     0,     0,     0,     0,     0,   991,     0,     0,
    2376,  2541,   992,   773,     0,     0, -1132,   985,   986,   993,
     243,   137,     0,     0,     0,  2556,     0,     0, -1849,     0,
       0,     0,     0,     0,     0,     0,  2377,     0,  1619,  1619,
       0,  1255,     0,  2378,   984,  1266,  1266,  1266,     0,     0,
       0,     0,     0,     0,     0,     0,  2379,     0,     0,   990,
    2380,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1132,     0,     0,     0,     0,     0,  1619,     0,     0,   991,
       0,     0,     0,   774,   992,     0,     0,     0, -1132,  2621,
       0,   993,   243,   137,     0,   985,   986,     0,     0,     0,
       0,     0,     0,     0,  1266,     0,     0,     0,     0,  2381,
       0,     0,     0,     0,     0,  1545,     0,  1546,     0,  1547,
       0,     0,  1548,     0,  1549,  1550,  1551,   775,     0,  1552,
    1553,     0,  1002,  1002,     0,     0,     0,   990,  2382,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2383,  2671,
       0,     0,     0,     0,  2384,     0,     0,   991,     0,     0,
       0,  1002,   992,     0,     0,     0,     0,     0,     0,   993,
       0,   137,     0,  2692,  2692,     0,     0,   776,     0,     0,
    1002,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1266,     0,     0,     0,     0,     0,     0,     0,   866,
       0,   867,     0,   868,     0,     0,     0,     0,   869,     0,
       0,     0,     0,     0,     0,     0,   870,     0,  2715,     0,
       0,     0,  1002,     0,  1266,     0,  1266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1619,     0,     0,   871,
     872,     0,     0,     0,  1619,     0,     0,     0,   873,     0,
       0,     0,     0,  1266,     0,  1266,     0,     0,     0,   874,
       0,     0,   875,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   876,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   877,
       0,     0,     0,  1004,     0,     0,     0,   878,     0,   879,
       0,  1266,     0,     0,     0,     0,  -704,  1619,  -704,  -704,
    -704,  -704,  -704,  -704,  -704,  -704,     0,  -704,  -704,  -704,
       0,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,  -704,
     880,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   881,     0,     0,     0,     0,   882,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   866,   883,   867,     0,   868,     0,     0,     0,
     884,   869,     0,   885,   886,     0,     0,     0,     0,   870,
       0,     0,     0,   887,  1266,     0,  1266,     0,     0,     0,
     888,     0,   889,     0,     0,   890,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   871,   872,     0,     0,     0,  1266,     0,     0,
       0,   873,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   874,     0,     0,   875,     0,   891,     0,     0,
       0,   892,     0,   893,  1226,     0,     0,   766,     0,   876,
       0,  1266,     0,   894,     0,     0,     0,     0,     0,  -704,
    -704,     0,  -704,  -704,  -704,  -704,     0,     0,     0,     0,
       0,     0,   877,     0,     0,     0,     0,     0,     0,   895,
     878,     0,   879,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   896,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   880,     0,     0,     0,   897,   898,     0,
     972,     0,     0,     0,   881,     0,     0,     0,   899,   882,
       0,  1266,  1227,  1266,     0,     0,     0,   973,     0,     0,
       0,     0,   900,   901,     0,     0,     0,     0,     0,   902,
       0,     0,     0,   903,     0,     0,   883,     0,     0,     0,
       0,   904,     0,   884,     0,     0,   885,   886,     0,     0,
       0,   905,     0,     0,     0,     0,   887,     0,     0,     0,
     906,     0,     0,   888,     0,   889,     0,     0,   890,   907,
       0,     0,     0,     0,   908,   909,     0,     0,   910,     0,
     911,     0,     0,     0,     0,     0,   912,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -704,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     891,     0,     0,     0,   892,     0,   893,   914,     0,   974,
       0,     0,     0,   915,     0,     0,   894,     0,   916,     0,
     768,     0,     0,     0,     0,     0,     0,   866,     0,   867,
       0,   868,     0,     0,     0,     0,   869,     0,     0,  -704,
       0,     0,   895,     0,   870,   917,     0,     0,     0,     0,
       0,     0,     0,  1228,     0,   896,     0,     0,     0,   976,
       0,   977,     0,     0,   771,     0,   978,   979,   980,     0,
       0,     0,   981,     0,   772,     0,     0,   871,   872,  1229,
     897,   898,     0,     0,     0,     0,   873,     0,     0,     0,
       0,   899,     0,     0,     0,     0,     0,   874,     0,     0,
     875,     0,     0,     0,     0,   900,   901,     0,     0,     0,
       0,   982,   902,     0,   876,     0,   903,  1004,  1004,     0,
       0,     0,     0,     0,   904,     0,     0,     0,     0,     0,
     983,     0,     0,     0,   905,     0,     0,   877,     0,     0,
       0,     0,     0,   906,     0,   878,  1004,   879,     0,     0,
       0,     0,   907,     0,   773,     0,     0,   908,   909,     0,
       0,   910,     0,   911,     0,  1004,     0,     0,     0,   912,
       0,     0,     0,     0,     0,     0,     0,     0,   880,     0,
       0,     0,  1652,     0,     0,   984,     0,     0,     0,   881,
       0,     0,     0,     0,   882,     0,     0,     0,     0,     0,
     914,     0,     0,     0,     0,     0,   915,  1004,     0,     0,
       0,   916,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   883,     0,     0,   774,     0,     0,     0,   884,     0,
       0,   885,   886,     0,     0,     0,   985,   986,   917,     0,
       0,   887,     0,     0,     0,     0,     0,     0,   888,     0,
     889,     0,     0,   890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   990,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   891,     0,     0,   991,   892,
       0,   893,     0,   992,     0,     0,     0,     0,     0,     0,
     993,   894,   137,     0,     0,     0,     0,     0,   776,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1226,     0,     0,   766,     0,     0,     0,   895,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     896,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   897,   898,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   899,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     900,   901,     0,     0,     0,     0,   972,   902,     0,     0,
       0,   903,     0,  1041,     0,  1042,     0,     0,     0,   904,
    1043,     0,     0,   973,     0,     0,     0,     0,  1044,   905,
       0,     0,     0,     0,     0,     0,  1377,     0,   906,     0,
       0,     0,     0,     0,     0,     0,     0,   907,     0,     0,
       0,     0,   908,   909,     0,     0,   910,     0,   911,     0,
       0,  1045,  1046,     0,   912,     0,     0,     0,     0,     0,
    1047,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1048,     0,     0,  1049,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   914,     0,     0,  1050,     0,
       0,   915,     0,     0,     0,     0,   916,     0,     0,     0,
       0,  1226,     0,     0,   766,     0,     0,     0,     0,     0,
       0,  1051,     0,     0,     0,   974,     0,     0,     0,  1052,
       0,  1053,     0,   917,     0,     0,   768,     0,  1054,     0,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,
    1064,  1065,  1643,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,     0,     0,     0,     0,     0,     0,  1228,
       0,     0,     0,  1076,     0,   976,     0,   977,  1077,     0,
     771,     0,   978,   979,   980,     0,     0,   972,   981,     0,
     772,     0,     0,     0,     0,  1229,     0,     0,     0,  1320,
       0,     0,     0,     0,   973,  1078,     0,     0,     0,     0,
       0,     0,  1079,     0,     0,  1080,  1081,     0,     0,     0,
       0,     0,     0,     0,     0,  1082,     0,   982,     0,     0,
       0,     0,  1083,     0,  1084,     0,     0,  1085,     0,     0,
       0,     0,     0,     0,     0,     0,   983,     0,  1226,     0,
       0,   766,     0,     0,  1528,  1529,  1530,     0,     0,     0,
       0,     0,  1531,     0,     0,     0,     0,     0,     0,     0,
     773,     0,     0,     0,     0,     0,     0,     0,     0,  1086,
       0,     0,     0,  1087,     0,  1088,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1089,     0,     0,     0,     0,
       0,   984,     0,     0,     0,     0,   974,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   768,     0,     0,
       0,  1090,     0,     0,   972,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1091,     0,     0,     0,     0,     0,
     774,   973,     0,     0,     0,     0,     0,     0,     0,     0,
    1228,     0,   985,   986,     0,     0,   976,     0,   977,  1092,
       0,   771,     0,   978,   979,   980,     0,     0,     0,   981,
    1093,   772,     0,     0,     0,     0,  1229,  1226,     0,     0,
     766,     0,     0,     0,   775,  1094,     0,     0,     0,     0,
       0,  1095,     0,     0,   990,  1096,     0,     0,     0,     0,
       0,  1532,     0,  1097,     0,     0,     0,     0,   982,     0,
       0,  1533,     0,  1098,   991,     0,     0,     0,     0,   992,
       0,     0,  1099,     0,     0,     0,   993,   983,   137,     0,
       0,  1100,     0,     0,   776,     0,  1101,  1102,     0,     0,
    1103,     0,  1104,   974,     0,     0,     0,     0,  1105,  1534,
    1535,   773,     0,   972,   768,     0,     0,     0,     0,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
     973,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,   984,  1377,     0,  1108,     0,  1228,  1536,  1537,
    1109,     0,     0,   976,     0,   977,     0,     0,   771,     0,
     978,   979,   980,     0,     0,     0,   981,     0,   772,     0,
       0,     0,     0,  1229,     0,     0,     0,  1110,     0,     0,
    1226,   774,     0,   766,     0,     0,  1538,     0,     0,     0,
       0,     0,  1539,   985,   986,  1540,     0,     0,     0,     0,
       0,     0,     0,  1541,     0,   982,     0,     0,     0,     0,
    1542,     0,     0,     0,     0,  1543,  1226,     0,     0,   766,
       0,     0,     0,     0,   983,   775,     0,     0,     0,     0,
       0,     0,   974,     0,  1544,   990,     0,     0,     0,     0,
       0,     0,     0,   768,     0,     0,     0,     0,   773,     0,
       0,     0,     0,     0,     0,   991,   972,     0,     0,     0,
     992,     0,     0,     0,     0,     0,     0,   993,  1382,   137,
       0,     0,     0,   973,     0,   776,  1228,     0,     0,   984,
       0,     0,   976,     0,   977,     0,     0,   771,     0,   978,
     979,   980,   972,     0,     0,   981,     0,   772,     0,     0,
       0,     0,  1229,     0,     0,     0,     0,     0,  -920,   973,
       0,  -920,     0,     0,     0,     0,     0,     0,   774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     985,   986,     0,     0,   982,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1545,     0,  1546,   983,  1547,     0,     0,  1548,     0,  1549,
    1550,  1551,   775,     0,  1552,  1553,     0,     0,     0,     0,
       0,     0,   990,     0,     0,   974,     0,   773,     0,     0,
       0,     0,     0,     0,  -920,     0,   768,     0,     0,     0,
       0,     0,   991,     0,     0,     0,     0,   992,     0,     0,
       0,  -920,     0,     0,   993,     0,   137,     0,   984,     0,
       0,   974,   776,     0,     0,     0,     0,     0,     0,  1228,
       0,     0,   768,     0,     0,   976,     0,   977,     0,     0,
     771,     0,   978,   979,   980,     0,  1226,     0,   981,   766,
     772,     0,     0,     0,     0,  1229,     0,   774,     0,     0,
       0,     0,     0,     0,     0,  1228,     0,     0,     0,   985,
     986,   976,     0,   977,     0,     0,   771,  1502,   978,   979,
     980,     0,     0,     0,   981,     0,   772,   982,     0,     0,
       0,  1229,     0,     0,     0,     0,     0,     0,     0,   972,
       0,   775,     0,     0,     0,     0,   983,     0,     0,     0,
       0,   990,     0,  -920,     0,     0,   973,     0,     0,     0,
       0,     0,   972,   982,  -920,     0,     0,     0,     0,     0,
     773,   991,     0,     0,     0,     0,   992,     0,     0,   973,
       0,     0,   983,   993,     0,   137,     0,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,  -920,     0,     0,
       0,   984,     0,  -920,     0,  -920,   773,     0,  -920,     0,
    -920,  -920,  -920,     0,  1226,     0,  -920,   766,  -920,     0,
       0,     0,     0,  -920,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   984,     0,     0,
     774,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   985,   986,     0,  -920,     0,     0,   974,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   768,
       0,     0,     0,     0,  -920,     0,   774,     0,     0,     0,
       0,   974,     0,     0,   775,     0,     0,     0,   985,   986,
     972,     0,   768,     0,   990,     0,     0,     0,  -920,     0,
       0,     0,   975,     0,     0,     0,  1464,   973,   976,     0,
     977,     0,     0,   771,   991,   978,   979,   980,     0,   992,
     775,   981,     0,   772,     0,  1228,   993,     0,   137,  -920,
     990,   976,     0,   977,   776,     0,   771,     0,   978,   979,
     980,     0,  1226,     0,   981,   766,   772,     0,     0,     0,
     991,  1229,     0,     0,     0,   992,     0,     0,     0,     0,
     982,     0,   993,     0,   137,     0,     0,     0,  -920,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,   983,
    -920,  -920,     0,   982,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   983,   773,  1648,     0,     0,     0,     0,   974,
       0,     0,  -920,     0,     0,     0,     0,     0,   972,     0,
     768,     0,  -920,     0,     0,     0,   773,  1226,     0,     0,
     766,     0,     0,     0,   984,   973,     0,     0,     0,     0,
       0,     0,  -920,     0,     0,     0,     0,  -920,     0,     0,
       0,     0,     0,  1228,  -920,     0,  -920,   984,     0,   976,
       0,   977,  -920,     0,   771,     0,   978,   979,   980,     0,
       0,     0,   981,   774,   772,     0,     0,     0,     0,  1229,
       0,     0,     0,     0,     0,   985,   986,     0,     0,     0,
       0,     0,     0,     0,     0,  1226,   774,     0,   766,     0,
       0,     0,     0,   972,     0,     0,     0,     0,   985,   986,
       0,   982,     0,     0,     0,     0,     0,   775,     0,   988,
     973,     0,     0,     0,     0,     0,     0,   990,     0,     0,
     983,     0,     0,     0,     0,     0,     0,   974,     0,     0,
     775,     0,     0,     0,     0,     0,     0,   991,   768,     0,
     990,     0,   992,     0,   773,  1774,     0,     0,   766,   993,
       0,   137,     0,     0,  1506,     0,     0,   776,     0,     0,
     991,   972,     0,     0,     0,   992,     0,     0,     0,     0,
       0,  1228,   993,     0,   137,   984,     0,   976,   973,   977,
     776,     0,   771,     0,   978,   979,   980,     0,     0,     0,
     981,     0,   772,     0,     0,     0,     0,  1229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   974,     0,   774,     0,     0,     0,     0,     0,
       0,   972,     0,   768,     0,     0,   985,   986,     0,   982,
       0,     0,     0,     0,     0,     0,     0,     0,   973,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   983,     0,
       0,     0,     0,     0,     0,     0,  1228,     0,   775,     0,
       0,     0,   976,     0,   977,     0,     0,  1270,   990,   978,
     979,   980,   773,     0,     0,   981,     0,   772,     0,     0,
     974,     0,  1229,     0,     0,     0,     0,     0,   991,     0,
       0,   768,     0,   992,     0,     0,     0,     0,     0,     0,
     993,     0,   137,   984,     0,     0,     0,     0,   776,     0,
       0,     0,     0,     0,   982,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1228,     0,     0,     0,     0,     0,
     976,     0,   977,   983,     0,   771,  1940,   978,   979,   980,
     974,     0,   774,   981,     0,   772,     0,     0,     0,     0,
    1229,   768,     0,     0,   985,   986,     0,   773,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   982,     0,  1228,     0,   775,     0,   984,     0,
     976,     0,   977,     0,     0,   771,   990,   978,   979,   980,
       0,   983,     0,   981,     0,   772,     0,     0,     0,     0,
    1229,     0,     0,     0,     0,     0,   991,     0,     0,     0,
       0,   992,     0,     0,     0,   773,     0,   774,   993,     0,
     137,     0,     0,     0,     0,     0,   776,     0,     0,   985,
     986,     0,   982,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   984,     0,     0,     0,
       0,   983,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   775,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   990,     0,     0,     0,   773,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   774,     0,     0,     0,     0,
       0,   991,     0,     0,     0,     0,   992,   985,   986,     0,
       0,     0,     0,   993,     0,   137,   984,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   775,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   990,
       0,     0,     0,     0,     0,   774,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   985,   986,   991,
       0,     0,     0,     0,   992,     0,     0,     0,     0,  1033,
       0,   993,     0,   137,     0,     0,     0,     0,     0,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   775,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   990,
    -362,     0,     0,  -362,     0,     0,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,     0,     0,     0,     0,   991,
       0,     0,     0,     0,   992,     0,     0,     0,     0,     0,
       0,   993,  -362,   137,  -362,     0,     0,     0,     0,   776,
       0,  -362,     0,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   531,     0,     0,  -362,  -362,  -362,  -362,
    -362,   530,     0,  -362,  -362,     0,     0,  -362,     0,     0,
       0,     0,     0,     0,  -362,     0,  -362,     0,     0,     0,
       0,  -362,  -362,     0,     0,     0,     0,     0,     0,  -362,
       0,     0,     0,     0,     0,     0,  -362,  -362,     0,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,     0,     0,     0,     0,
    -362,     0,     0,  -362,     0,     0,     0,     0,     0,  -362,
       0,  -362,     0,     0,     0,     0,     0,     0,     0,     0,
    -362,     0,     0,  -362,     0,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,     0,  -362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -362,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -362,
       0,     0,     0,  -362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -362,  -362,     0,     0,
       0,     0,     0,     0,     0,  -362,     0,     0,  -362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -362,     0,  -362,     0,     0,     0,     0,     0,     0,
       0,  -362,     0,     0,     0,   531,     0,     0,  -362,  -362,
    -362,  -362,  -362,     0,     0,  -362,  -362,     0,     0,  -362,
       0,     0,     0,     0,     0,     0,  -362,     0,     0,     0,
       0,     0,     0,     0,  -362,     0,     0,     0,     0,     0,
       0,     0,     0,  -362,     0,     0,     0,     0,     0,  -362,
       0,     0,     0,  -362,     0,  -362,  -362,  -362,     0,     0,
       0,     0,  -362,     0,     0,  -362,     0,     0,     0,     0,
       0,  -362,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -362,     0,     0,     0,     0,  -362,
       0,     0,     0,     0,  -362,     0,     0,  -362,     0,     0,
       0,     0,     0,     0,     0,     0,  -362,     0,     0,     0,
       0,  -362,     0,     0,     0,  -362,  -362,  -362,     0,     0,
       0,     0,     0,     0,     0,  -362,     0,     0,     0,  -362,
       0,     0,     0,     0,     0,  -362,  -362,     0,     0,  -362,
       0,     0,   532,     0,     0,     0,     0,  -362,     0,   630,
    -362,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -362,   631,     0,     0,   632,   633,   634,
     635,   636,   637,   638,     0,  -362,     0,     0,     0,     0,
       0,     0,     0,  -362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   639,     0,   640,   641,   642,   643,   644,   645,   646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -362,     0,  -362,  -362,  -362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   647,     0,     0,
       0,     0,     0,     0,  -362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -362,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -362,     0,
       0,     0,     0,     0,     0,     0,     0,  -362,  -362,  -362,
       0,     0,     0,     0,     0,     0,   648,   649,   650,   651,
     652,  -362,     0,   653,   654,     0,     0,     0,  -362,     0,
       0,     0,     0,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   632,   633,   634,   635,   636,   637,
       0,     0,     0,     0,     0,     0,     0,   655,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,   656,     0,     0,     0,     0,   639, -1825,
     640,   641,   642,   643,   644,   645,   646,  1699,     0,     0,
    1700,     0,     0,  1701,   632,   633,   634,   635,   636,   637,
    1702,  1703,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   657,     0,     0,     0,  1704,
       0,  1705,     0,     0,   647,     0,     0,     0,   639,     0,
     640,   641,   642,   643,   644,   645,   646,     0,     0,     0,
       0,     0,     0,   658,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   659,     0,     0,
       0,     0,     0,     0,     0,   660,     0,     0,   661,     0,
       0,     0,     0,     0,   647,     0,     0,     0,     0,     0,
       0,   662,     0,   648,   649,   650,   651,   652,     0,     0,
     653,   654,     0,   663,     0,     0,     0,     0,     0,     0,
       0,   664,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1706,     0,     0,     0,     0,
       0,     0,     0,     0,   655,   972,     0,     0,     0,     0,
       0,     0,     0,   648,   649,   650,   651,   652,     0,     0,
     653,   654,   973,   665,  1707,   666,   667,   668,     0,     0,
       0,  1708,     0,  1709,     0,     0,     0,     0,     0, -1778,
       0,     0,     0,     0,     0,     0,  1710,     0,     0,     0,
       0,     0,   669,     0,   655,     0,     0,     0,     0,     0,
       0,     0,   657,     0,     0,     0,     0,    94,     0,  -359,
     656,     0,     0,     0,     0,     0,     0,     0,  1711,     0,
       0,     0,     0,     0,     0,     0, -1825,  1712,     0,     0,
       0,     0,     0,     0,     0,   670,   671,   672,     0,     0,
    1713,     0,     0,     0,   659,     0,     0,     0,     0,   673,
       0,     0,   657,     0,     0,   661,   674,     0,     0,     0,
       0,     0,     0,     0,   974,     0,     0,   972,   662,     0,
       0,     0,     0,     0,     0,   768,     0,     0,     0,     0,
    1714,     0,     0,     0,   973,     0,     0,     0,     0,     0,
       0,     0,     0,  1715,   659,     0,     0,     0,     0,     0,
       0,     0,   660,     0,     0,   661,     0,     0,   975,     0,
       0,     0,     0,     0,   976,     0,   977,     0,   662,   771,
    1716,   978,   979,   980,     0,     0,     0,   981,     0,   772,
       0,     0,   666,   667,   668,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1717,     0,     0,     0,
       0,     0,     0,  1718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   982,     0,     0,     0,
    1719,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     665,     0,   666,   667,   668,   983,   974,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   768,     0,     0,
       0,     0,   670,   671,   672,     0,     0,     0,     0,   773,
       0,     0,     0,     0,     0,     0,     0,     0,   972,     0,
       0,  1720,     0,     0,     0,     0,  -607,     0,     0,     0,
     975,  1721,     0,     0,     0,   973,   976,     0,   977,     0,
     984,   771,     0,   978,   979,   980,     0,     0,  1722,   981,
       0,   772,   670,   671,   672,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   673,     0,     0,     0,
       0,     0,  1723,   674,     0,     0,     0,     0,     0,   774,
       0,     0,     0,     0,     0,     0,     0,     0,   982,     0,
       0,   985,   986,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   983,     0,     0,
       0,  1406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   987,   972,   775,     0,   988,   989,     0,     0,     0,
       0,   773,     0,   990,     0,     0,     0,   974,   972,   973,
       0,     0,     0,     0,     0,     0,     0,     0,   768,     0,
       0,     0,     0,   991,     0,   973,     0,     0,   992,     0,
       0,     0,   984,     0,     0,   993,     0,   137,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,     0,
       0,   975,     0,     0,     0,     0,     0,   976,     0,   977,
       0,     0,   771,     0,   978,   979,   980,     0,     0,     0,
     981,   774,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   985,   986,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1425,     0,     0,     0,     0,     0,   982,
       0,   974,     0,   987,     0,   775,     0,   988,   989,     0,
       0,     0,   768,     0,     0,   990,     0,   974,   983,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   768,     0,
       0,     0,     0,     0,     0,   991,     0,     0,     0,     0,
     992,     0,   773,     0,     0,   975,     0,   993,     0,   137,
       0,   976,     0,   977,     0,   776,   771,     0,   978,   979,
     980,   975,     0,     0,   981,     0,   772,   976,     0,   977,
       0,     0,   771,   984,   978,   979,   980,     0,     0,     0,
     981,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   982,     0,     0,     0,     0,     0,     0,
       0,     0,   774,     0,     0,     0,     0,     0,     0,   982,
       0,     0,   983,     0,   985,   986,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   983,     0,
       0,     0,     0,     0,  1964,     0,   773,     0,     0,     0,
       0,     0,     0,     0,   987,     0,   775,     0,   988,   989,
       0,     0,   773,     0,     0,     0,   990,     0,     0,     0,
       0,     0,     0,  2682,     0,     0,     0,   984,     0,     0,
       0,     0,     0,     0,     0,     0,   991,     0,     0,     0,
       0,   992,     0,   984,     0,     0,     0,     0,   993,     0,
     137,     0,     0,     0,     0,     0,   776,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   774,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   985,   986,
       0,     0,   774,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   985,   986,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     775,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     990,     0,     0,     0,     0,     0,   775,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   990,     0,     0,     0,
     991,     0,     0,     0,     0,   992,     0,     0,     0,     0,
       0,     0,   993,     0,   137,     0,   991,     0,     0,     0,
     776,   992,     0,     0,     0,     0,     0,     0,   993,     0,
     137,     0,     0,     0,     0,     0,   776
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-2301))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   606,   105,   366,   450,   116,   181,   393,   111,   395,
    1121,   103,   674,   105,   803,   698,  1226,  1148,   858,   111,
     158,  1207,   733,  1119,   663,  1588,   804,   796,  1442,  1483,
    1578,  1442,   135,  1442,   209,  1442,  1442,   720,  1442,   425,
    1594,   404,  2024,   135,  1124,   609,  1826,  1367,  1258,   435,
    1377,     1,  1990,  1134,  1532,  1115,  1265,  1113,  1523,     1,
     711,     9,     6,  1126,     9,  1121,  1122,  1148,    56,    57,
      58,  1134,     9,    27,    17,  1131,    64,   760,     9,  1464,
    1910,   184,  1138,  1139,  1251,  1148,   364,     0,    53,  1356,
      22,    49,   861,     1,     1,    60,    17,    57,   129,   107,
     123,  1157,  1158,     9,    96,  1935,    92,    21,  2057,    86,
    1319,    99,   100,  1975,   102,     6,   123,   175,   174,   107,
     108,   141,  1376,  1184,     0,   808,    57,   125,   116,    87,
     769,   770,  1517,   152,  1758,    32,  1456,  1198,  1686,   277,
     251,     9,  1253,   165,    63,   133,   176,   244,    57,    31,
     176,   203,   142,   232,   232,    22,    57,   213,   237,   328,
    2002,   115,   225,  1372,   262,   308,    64,   234,    66,    49,
     124,    55,   160,   244,   159,    70,  1934,  2159,   242,   818,
     274,  1241,   256,    49,   295,  1452,  1506,    26,   161,   287,
     218,   203,   262,   354,   369,   241,   161,   203,   849,   988,
    1585,   218,    31,   191,   766,   129,  2425,    49,   308,   153,
     203,   421,   803,    30,    48,   203,   232,   256,    21,    49,
    1009,    27,   410,    87,    31,   138,   551,   406,   406,   142,
     285,   200,   125,  1289,  1297,   976,   977,  2537,    96,   244,
     256,  1793,   983,   171,   171,  1308,   177,    64,   453,    66,
     448,   451,   803,   218,   219,   232,   367,     6,    57,   464,
     458,   249,   138,  1648,  1320,   463,   142,   410,   212,   257,
     595,   394,    39,     9,   406,     0,   204,   204,   171,   334,
    2499,   843,     6,  1835,  1365,    92,   314,   200,   476,   306,
     329,   307,   199,   309,   388,   456,   301,   476,   476,  2599,
     232,   626,  1365,   114,  1571,  1853,  1369,   272,   256,   115,
     241,   317,   256,   410,    50,   385,   289,   282,   418,    84,
     384,   340,   266,  1379,   200,  1114,  1889,   271,   451,    70,
     397,  1014,  1659,   476,   503,  1887,   975,   228,  1665,   410,
     290,   444,  2172,   446,   476,   423,   113,   458,   228,   347,
     453,   341,     1,   187,   446,   309,   566,   196,     9,   256,
    2202,   453,   312,    70,   376,   232,   274,   470,  1464,    72,
     473,   474,   341,   476,   123,   363,   479,   480,   470,   365,
    1845,  1859,  1269,  1848,   975,  2143,  1653,  1176,  1177,  1178,
    1868,  2015,  1944,    70,  1779,   447,   987,   988,   989,   357,
    1189,  1190,   346,   391,   402,   503,   503,  1196,  1464,   172,
      70,   110,    61,   271,   402,   203,    70,   308,  1009,   287,
     451,  1517,   468,   411,   412,   504,   414,   415,   341,    34,
     504,   451,   420,   331,   497,   252,   987,   988,   989,   461,
      89,    90,  1522,   546,   547,   256,   504,  1503,   504,   437,
     436,   175,   353,  1136,   546,   547,  1020,  1021,  1009,   482,
    1516,  1517,  1349,   212,   370,   341,   454,   452,   171,   462,
     237,   416,   416,   504,   504,   482,   212,   335,   504,  2031,
     388,   349,   401,   586,  2346,   504,   446,  1265,   212,  1585,
    1757,   357,   603,   357,   586,   503,   504,   421,  1554,   610,
       6,  1582,     6,   398,  1245,  1565,   609,   256,   244,   245,
    1837,    56,   504,   316,   331,   357,   460,   266,    63,  1582,
     256,   442,   499,  1114,   124,  2474,  2475,   357,   516,  1585,
     266,     6,   256,  1787,   376,   813,  1596,   468,   451,   453,
     498,  1708,   266,   451,   451,  1136,   376,   658,   536,   503,
     464,  1142,  1648,   448,   504,   204,   504,  1208,   501,  1622,
     504,   664,   504,  1114,  1774,   510,   510,   504,  1777,   460,
    1626,   559,   504,   561,  2128,   451,   564,   565,  1169,   567,
     462,  1637,  2206,   232,  1640,  1176,  1177,  1178,  1179,  1228,
     496,   504,  1648,  1184,  1372,  2425,   505,   346,  1189,  1190,
    1191,  1192,  1193,  1194,  1195,  1196,  2071,  1198,  1199,   451,
     346,  1878,   600,   497,  1675,  2477,   581,   605,  1169,  2399,
     256,   451,   346,     6,   612,  1176,  1177,  1178,   504,   392,
       9,   465,   498,   462,   498,   402,   287,  1228,  1189,  1190,
    1191,  1192,  1193,  1194,  1195,  1196,   504,  2096,  1199,  1916,
     453,   354,   617,  2515,  2516,   159,   498,   398,   330,   458,
    1251,   464,  2214,  2645,   463,   256,   256,   416,   498,   503,
     781,    33,   321,   848,   462,   786,   281,   282,   283,  2064,
     416,  2066,   241,  1779,    61,   673,   503,   287,   791,   792,
     801,   398,   416,   504,   308,  2557,   232,   446,   349,  2561,
    2562,  1490,  2254,   806,  2256,  2643,   212,   448,   212,   161,
     159,   460,    89,    90,    28,  1493,  1603,   458,   129,  1782,
    2105,   398,   463,   268,   460,  1785,   714,   252,  2590,   717,
     451,   124,  1118,   482,  1120,  2287,   460,   212,   398,   344,
    2067,   448,   441,  1334,   398,   170,   256,   446,   256,    30,
     256,   203,   256,   456,   357,   504,  2459,  1143,     9,  1145,
     266,   510,   266,   256,  1150,   252,  2628,   256,  2320,  2321,
    1986,   448,   256,   256,   510,    30,  2161,    57,  1164,   503,
     504,   256,   445,   504,   446,   271,   510,  1121,   448,  2005,
    2006,   266,   450,  2009,   448,   340,  2274,   195,   287,   462,
     225,   459,   451,   212,  1885,   167,   256,    56,   233,    64,
      56,    66,   126,    59,    63,  2085,   256,    63,  1457,  2086,
     231,   212,  1885,  1886,  1158,   256,   107,  2276,  2277,   212,
     216,   503,  1527,   212,  2050,   497,    56,   289,   346,  2055,
     346,   290,   346,    63,   293,  1484,   127,   256,   229,     0,
     236,   396,  1630,  2416,  2174,   232,   401,   266,   256,  1970,
     257,   466,   467,   124,   389,   256,   471,  1923,   504,    32,
    1256,   346,  1567,   256,  1438,   266,   262,   256,   188,   387,
     291,  1267,   451,   266,   330,   166,   229,   266,   153,   169,
     504,  1680,   317,  2163,   287,   498,   122,  1592,   212,  1490,
    2167,   287,   389,   503,   504,   267,   451,   188,   416,   468,
     416,   342,   416,   504,   504,   451,  2619,  1020,  1021,  1030,
     510,  1604,   196,   204,   376,  2056,  2057,   341,  2491,  2481,
    2482,  1510,  1511,  1512,  1513,   138,   411,   346,  1135,  1490,
     446,   416,   256,   223,   321,   271,    12,   110,   452,    15,
      16,    64,   266,    66,   460,   346,   460,    38,  2174,   504,
     446,   212,  2411,   346,  1161,    46,   280,   346,  2064,  2326,
    2066,  2328,     9,     1,     6,    12,   501,     9,    15,    16,
    2466,     8,   256,    11,  1169,   460,  2540,   138,  1579,   370,
     458,   142,  2072,    26,   504,   463,   406,   252,   504,  1777,
     504,  1684,   510,   452,   510,   256,   510,   416,  2278,  2105,
      37,   504,  1115,  1604,  1199,   266,  1119,    49,  2228,   268,
     504,   504,   268,  1126,  1127,   416,   287,   370,  1579,   504,
      58,  1134,   346,   416,  1137,   510,  2522,   416,   435,  1142,
    2103,  1144,   454,  1146,  1147,  1148,  1149,  2127,   268,   200,
      82,   503,   362,  2507,   504,    87,  2604,   503,   504,   340,
     262,  2117,  2616,  1166,   504,  2161,   476,    99,    96,   460,
      98,   406,   100,   451,   451,   199,   331,   460,  1351,   504,
     108,   460,  1257,     9,  1675,   287,  1691,  2198,  2445,  1680,
     270,   340,   504,   256,   340,   346,   422,   494,   424,  2155,
    2156,   510,   416,  1798,   394,   419,   420,   504,  2522,  1495,
    1805,  2522,  1309,  2522,   500,  2522,  2522,  1708,  2522,   510,
     340,   504,   216,   217,   453,   504,   262,   510,  1401,  1680,
     211,   510,  1771,  1308,  2682,   411,   164,   256,  1241,   252,
    2356,   476,   236,   274,  2360,  2708,   262,   396,  2696,   329,
     396,   287,   401,   414,   356,   401,    82,  1260,   796,   256,
     220,  1856,   243,   306,   262,   416,   292,   286,   262,   201,
     450,   287,   501,    99,   157,   177,   396,   770,   458,   459,
     212,   401,   458,   463,   265,   187,   337,   463,  1385,   287,
     341,   452,   252,   287,  1297,   338,   510,   451,   324,   323,
     324,  1376,   451,   451,  2260,  1308,   170,  1976,   210,   460,
     329,   277,   278,   245,   414,   358,   340,  1912,   331,   251,
     351,   253,   353,   861,   256,   818,   258,   259,   260,   257,
     356,   451,   264,  1812,   266,   301,   302,   318,   240,   271,
     277,   278,   503,   379,   451,    53,    54,  1826,   231,  1352,
       8,  2029,   452,   423,   187,  2471,  2472,    35,   504,   510,
      38,   225,  1365,   177,   301,   302,  1369,    45,    46,   233,
     394,   303,   474,   301,     9,   201,   308,   210,   458,    37,
    1919,    89,  2640,   463,   204,   212,   212,   256,   207,   208,
     322,   351,   481,   351,   106,   262,   504,   378,   106,   359,
    1403,   503,   271,  1478,   116,  2401,  1669,  2403,   116,   292,
     499,  1403,   232,    91,   346,  2010,   769,   770,  2676,     8,
     287,  2507,    57,   237,  2624,   357,   240,   246,   247,   256,
     256,  2026,   258,   259,   260,  1438,  2047,   405,   264,   266,
     266,    54,  2642,  2474,  2475,   377,  2477,  2187,    37,  2032,
    2045,  1137,   321,   317,   412,   413,   232,   187,   187,   394,
    2570,  1464,   390,  1149,  2153,   818,  2422,   503,   504,  1974,
    2617,  2618,   451,   769,   770,  1146,    89,   303,   410,  2074,
     210,   210,   160,  2078,   416,   405,  2025,   165,   117,   118,
     119,    16,   473,   106,   451,  1166,   428,   429,     9,  2646,
     161,    57,  2085,   116,   165,   433,   500,   449,    33,   503,
     451,   189,  1587,   451,  1517,  2526,   458,    42,  2665,   346,
     346,   463,   818,   451,   448,  2120,   218,  2483,   460,   173,
     453,  2487,  2488,   211,   458,   451,  1611,   448,   470,   463,
      47,   464,   177,   307,   476,   309,    57,   458,  1436,    13,
      14,   377,   463,  1441,  1442,    62,  1444,   451,   490,     2,
    2707,  1636,  1565,   495,     7,  1215,   498,    68,    32,  1219,
     502,   351,   504,   353,   449,   504,   504,   212,   510,  1582,
    2163,   451,  1585,   458,   340,  1623,     1,   265,   463,   416,
     416,   248,   249,  1596,   474,   102,   476,    35,   504,   479,
      38,   451,   428,   429,   504,  1891,   241,    45,    46,   238,
     560,    24,    25,   321,   451,   565,  2211,   325,   326,  1622,
     256,   256,  2217,   252,   256,    40,    41,    42,    43,    44,
     468,   266,  2227,   460,   460,   504,   455,   199,   457,  1650,
     318,   510,    96,    97,   470,  1648,  1411,  1193,  1194,  1195,
    1415,   504,    65,    91,    67,   442,    69,  1422,   366,   400,
      75,    76,  2153,   351,   490,   353,   212,   401,  1671,   495,
     351,  1734,   353,   410,   382,   383,   502,   504,   504,  1671,
      63,  1744,  1745,   510,   510,  1748,    59,  1672,  1673,  1674,
     103,   104,   105,  1678,   232,  2278,  1681,  1682,   299,   300,
     378,   212,  2153,  1714,   256,  2300,   335,   451,  2303,  2304,
     256,   346,   328,   391,   485,   486,   487,   488,   347,   401,
     266,  2316,   160,   256,  1735,   232,   485,   486,   487,   488,
     241,   156,   239,   158,   504,  2330,  2331,   156,   229,   158,
     153,    26,   155,   250,   451,   256,  1634,   451,   803,   162,
     107,   189,   165,   451,   252,   266,   254,   485,   486,   487,
     488,  2107,  2108,   178,   179,   180,   181,   182,   183,   184,
     185,   186,  1775,   211,   256,   252,  1779,   254,   252,  1782,
     254,   416,  1785,   634,   635,   636,   637,    65,   987,    67,
     989,  1191,  1192,   312,   256,   473,  2391,  1177,  1178,   272,
     346,  1689,  1690,   454,    23,   102,   451,   437,   437,   188,
     122,   454,  1700,    17,    86,   504,  1891,   451,   394,  1707,
    2106,   272,   351,   401,    56,   460,   503,   265,   402,   423,
     262,    39,  1835,   468,   451,   346,  2099,   237,   402,   252,
    2435,   254,   504,   331,   351,   352,   506,   419,  1736,   504,
     504,   316,   310,   394,   261,   451,     7,   394,   271,   366,
     451,   368,   255,    11,   451,   504,   503,  1942,   451,   504,
     416,   394,   366,    85,   451,   510,  1951,  1952,   451,    85,
     318,   124,  1885,  1886,  1887,   432,  1924,  1925,  1926,  1927,
    1928,  1929,  1930,  1931,   451,   394,   389,    22,   306,   124,
     309,   501,   451,   204,   394,   416,  1794,   504,   451,   504,
      58,   499,   384,   232,   460,   330,   501,   254,   504,   446,
     218,   122,   504,   462,   446,  1813,   510,   442,   343,    26,
     400,  1819,   987,   988,   989,   306,   348,   447,   504,   410,
     378,  1944,   445,   256,   451,   462,   442,   451,    96,   460,
      98,   504,   100,   391,  1009,   376,   451,   468,   399,   336,
     108,   114,   462,   187,   510,   462,  1969,   169,   504,   256,
     462,   446,   451,   462,   309,   462,   462,  1969,  1981,   462,
     504,   462,   462,  1986,   451,   451,   504,   403,  1999,    30,
     504,   498,   453,   504,   130,   132,   196,   131,    45,   510,
     446,   133,  2005,  2006,   386,   134,  2009,   351,   135,   137,
     136,   101,   497,   441,   462,   446,   164,    64,    65,    66,
      67,   140,    49,   404,   442,   445,   143,   196,  2031,   144,
     443,  2106,   145,   439,   445,   473,   146,   271,    31,   499,
     147,    49,   148,  2118,   149,  2056,  2057,  2050,   150,   196,
    2612,   112,  2055,  2056,  2057,     6,   151,  1112,     9,  1114,
    2565,  2064,  1117,  2066,   220,   114,  1121,  1955,   448,  2631,
     448,   410,   448,   448,   448,   312,   448,   446,   226,   109,
     493,  1136,   446,   451,   223,  1973,   197,  1142,   376,   504,
    2595,   504,   339,   256,   203,   272,   231,   294,   484,   298,
    2103,  1989,  2105,  1991,   501,   165,   501,  1995,  1163,   257,
    1165,   128,   175,    82,  1169,  2003,   365,   446,   168,   129,
     228,  1176,  1177,  1178,  1179,   446,  2617,  2618,    49,  1184,
      99,    82,   196,   204,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,   228,  1198,  1199,   176,    56,   299,    99,   204,
     504,   451,   272,   301,   252,  2646,   304,   509,  2161,   165,
     508,   237,   209,   423,   276,   446,  2617,  2618,   299,   446,
     380,  2174,  1227,   362,  2665,  2178,    30,   295,   203,   203,
      17,   442,   128,   139,   365,    49,  2178,   446,   235,   124,
     203,   141,     8,   196,   501,  2646,  1251,   129,  1253,   501,
     423,   152,   203,   451,  2490,   252,   446,   254,     9,     7,
    2098,   504,   256,   503,  2665,   294,  2707,   297,   203,   503,
      49,   369,   498,   498,   188,   314,   310,   262,   461,   291,
     330,   313,   201,   113,    47,   411,   203,   203,   285,     4,
     436,   294,   390,   212,   102,   361,    49,   361,   262,   237,
     201,  2254,  2538,  2256,    19,    95,  2707,   380,   305,   296,
     292,   212,   492,    56,    29,     8,    49,   415,   110,   417,
     456,   337,   262,   262,   109,   262,   451,   210,   337,  1334,
     327,  2284,   340,   481,  2287,   433,   333,   256,   107,   258,
     259,   260,  2284,   451,   245,   264,   221,   266,    63,   367,
     251,  1356,   253,   209,   119,   256,   501,   258,   259,   260,
     196,   337,    49,   264,   418,   266,   313,   321,  2321,     7,
     271,    46,   306,    92,   425,    26,   201,  1382,   127,   206,
     148,    75,   221,   238,   303,   410,   150,   521,  2341,   177,
     622,   505,   547,   286,   425,  1029,   540,   792,   498,  2341,
    1442,  2615,   303,  2356,   759,  2680,   504,  2360,   405,  1883,
    2176,   808,  2659,  2692,  2199,  2199,  2628,   414,  1038,  2069,
     799,   322,  1224,  1747,  1746,  1829,  2385,   346,  1781,  1241,
    1476,  1478,  2067,   861,   431,  1503,  2252,  1522,  1525,  2071,
    1848,  2270,  1293,   803,  1876,   346,  1568,  1452,  2401,  2094,
    2403,  1586,  1575,  1329,   451,  2106,  2116,  1903,   377,  1334,
    1952,  1616,  2130,  1932,  1363,  2156,  2419,  1365,  1149,  1951,
    1379,  2324,  1951,  2676,  1663,   472,   377,  2329,  2149,  2425,
    2334,  2319,  1554,  2149,  2149,  1490,  2149,  2723,  1352,  1472,
     299,   705,   152,  1919,   491,   270,   242,   416,   992,   764,
    2594,   498,   499,   586,  2548,   220,   417,   215,   510,   428,
     429,  1939,  2413,  2474,  2475,   416,  2083,  1882,  2471,  2472,
     724,  2474,  2475,  1578,  2477,   563,  2364,   428,   429,  2619,
    2368,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,   470,   453,    -1,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,   464,    -1,    -1,  1571,    -1,    -1,   470,
      -1,   490,    -1,    -1,  1579,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,  2537,   504,  2424,    -1,    -1,   490,
    1595,   510,    -1,    -1,   495,    -1,    -1,    -1,    -1,  1604,
     315,   502,    -1,   504,    -1,   320,  2567,    -1,    -1,   510,
    1615,    -1,    -1,    -1,    -1,   975,    -1,    -1,    -1,  2457,
    2458,    -1,    -1,    -1,    -1,    -1,    -1,   987,   988,   989,
      82,    -1,    -1,    -1,    -1,  2473,   351,    -1,  1643,    -1,
      -1,    -1,    -1,    -1,   359,    -1,  2599,    99,  1653,  1009,
      -1,  2489,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,  2623,    -1,    -1,    -1,  2627,    -1,    -1,    -1,
    1675,    -1,    -1,    -1,    -1,  1680,  2514,    -1,    -1,    -1,
      -1,  2519,  2520,    -1,    -1,    -1,   401,  2640,    -1,   404,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,
      -1,  2539,    -1,  1708,    -1,    -1,    -1,    -1,   423,    -1,
      -1,    -1,    -1,    -1,    -1,  1720,    -1,    -1,  1723,    -1,
      -1,    -1,    -1,  2676,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2569,    -1,    -1,  2572,  2573,   451,    -1,    -1,   454,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2700,    -1,   201,
    2711,    -1,  1757,    -1,  1114,    -1,    -1,    -1,    -1,  1119,
     212,    -1,    -1,    -1,    -1,    -1,  1126,    -1,  1773,    -1,
      -1,    -1,    -1,    -1,  1134,    -1,  2614,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1148,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,  1169,
      -1,    -1,   264,    -1,   266,    -1,  1176,  1177,  1178,  1179,
      -1,    -1,    -1,    -1,  1184,    -1,    -1,    -1,    -1,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,    -1,  1198,  1199,
       1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    10,
      -1,   303,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1228,    -1,
     322,    -1,    -1,  1878,  1879,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,   346,    -1,    -1,    -1,    -1,    60,
    1260,    -1,    -1,  1908,    -1,    -1,    -1,    -1,    -1,    -1,
      71,  1916,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1297,  1943,    -1,
      -1,    -1,    -1,    -1,    -1,  1950,  1951,    -1,  1308,    82,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,    -1,    -1,   416,  1970,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1980,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,  1356,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,  1365,   458,   168,   460,  1369,
     462,   463,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2032,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   490,    -1,
      -1,   202,    -1,   495,   205,   206,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,   215,    -1,    -1,    -1,   510,    -1,
      -1,   222,    -1,   224,    -1,    -1,   227,    -1,   201,    -1,
      -1,  2076,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
    2085,  2086,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2094,
      -1,    -1,  1452,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1464,    -1,    -1,    -1,   269,    -1,
      -1,  2116,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   285,   258,   259,   260,    -1,    -1,
    1490,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2153,    -1,
     311,    82,    -1,     6,    -1,    -1,     9,  1517,  2163,    12,
      13,    14,  2167,   324,    -1,    -1,    -1,    20,    99,    -1,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    -1,    -1,    38,  2189,    -1,    -1,   190,   349,   350,
      -1,    46,    -1,  2198,    -1,    -1,    -1,    -1,   201,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1571,    -1,   374,   375,    -1,    -1,    -1,    -1,  1579,
     381,    -1,  1582,    -1,   385,  1585,    -1,    -1,  2233,    82,
      -1,    -1,   393,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,   403,    -1,   377,    -1,    99,    -1,    -1,    -1,
      -1,   412,    -1,   256,    -1,   258,   259,   260,    -1,   190,
     421,   264,  1622,    -1,    -1,   426,   427,    -1,    -1,   430,
     201,   432,    -1,  2278,    -1,    -1,    -1,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1648,    -1,
     451,    -1,    -1,  1653,    -1,   428,   429,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,    -1,   159,    -1,   469,    -1,
      -1,    -1,    -1,    -1,   475,  1675,   169,    -1,    -1,   480,
    1680,    -1,    -1,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,   189,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,   198,    -1,    -1,   507,    -1,   201,    -1,
      -1,    -1,    -1,    -1,   207,   208,   211,   490,    -1,   212,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,   303,    -1,   377,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,  2394,
      -1,    -1,   245,   246,   247,    -1,    -1,  1757,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,   263,    -1,
     265,   264,    -1,   266,    -1,  1775,    -1,    -1,   271,  1779,
      -1,    -1,  1782,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,   284,  2437,   288,    -1,    -1,   439,   290,    -1,  2444,
     293,    -1,  2447,    -1,    -1,    -1,   377,    -1,   301,    -1,
     303,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,
     313,    -1,    -1,   318,    -1,    -1,    -1,   470,    -1,   322,
      -1,    -1,    -1,    -1,    -1,  1835,    -1,    -1,   481,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
     345,  2496,   495,   346,    -1,    -1,   499,   428,   429,   502,
     503,   504,    -1,    -1,    -1,  2510,    -1,    -1,   439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,  1878,  1879,
      -1,  2526,    -1,   378,   377,  1885,  1886,  1887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,   470,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     481,    -1,    -1,    -1,    -1,    -1,  1916,    -1,    -1,   490,
      -1,    -1,    -1,   416,   495,    -1,    -1,    -1,   499,  2574,
      -1,   502,   503,   504,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1944,    -1,    -1,    -1,    -1,   444,
      -1,    -1,    -1,    -1,    -1,   448,    -1,   450,    -1,   452,
      -1,    -1,   455,    -1,   457,   458,   459,   460,    -1,   462,
     463,    -1,  2617,  2618,    -1,    -1,    -1,   470,   473,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,  2634,
      -1,    -1,    -1,    -1,   489,    -1,    -1,   490,    -1,    -1,
      -1,  2646,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,  2658,  2659,    -1,    -1,   510,    -1,    -1,
    2665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2031,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,  2703,    -1,
      -1,    -1,  2707,    -1,  2064,    -1,  2066,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2086,    -1,    -1,    51,
      52,    -1,    -1,    -1,  2094,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,  2103,    -1,  2105,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,  2153,    -1,    -1,    -1,   119,    -1,   121,
      -1,  2161,    -1,    -1,    -1,    -1,   128,  2167,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,   195,     3,    -1,     5,    -1,    -1,    -1,
     202,    10,    -1,   205,   206,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,   215,  2254,    -1,  2256,    -1,    -1,    -1,
     222,    -1,   224,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,  2287,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,   269,    -1,    -1,
      -1,   273,    -1,   275,     6,    -1,    -1,     9,    -1,    88,
      -1,  2321,    -1,   285,    -1,    -1,    -1,    -1,    -1,   291,
     292,    -1,   294,   295,   296,   297,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   311,
     119,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   349,   350,    -1,
      82,    -1,    -1,    -1,   163,    -1,    -1,    -1,   360,   168,
      -1,  2401,    94,  2403,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    -1,   381,
      -1,    -1,    -1,   385,    -1,    -1,   195,    -1,    -1,    -1,
      -1,   393,    -1,   202,    -1,    -1,   205,   206,    -1,    -1,
      -1,   403,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
     412,    -1,    -1,   222,    -1,   224,    -1,    -1,   227,   421,
      -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   273,    -1,   275,   469,    -1,   201,
      -1,    -1,    -1,   475,    -1,    -1,   285,    -1,   480,    -1,
     212,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,   501,
      -1,    -1,   311,    -1,    18,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,   324,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,    51,    52,   271,
     349,   350,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,
      -1,   303,   381,    -1,    88,    -1,   385,  2617,  2618,    -1,
      -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,   403,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   412,    -1,   119,  2646,   121,    -1,    -1,
      -1,    -1,   421,    -1,   346,    -1,    -1,   426,   427,    -1,
      -1,   430,    -1,   432,    -1,  2665,    -1,    -1,    -1,   438,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   451,    -1,    -1,   377,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    -1,    -1,    -1,   475,  2707,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,    -1,   416,    -1,    -1,    -1,   202,    -1,
      -1,   205,   206,    -1,    -1,    -1,   428,   429,   507,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,
     224,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,   490,   273,
      -1,   275,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,   285,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    -1,   311,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   349,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     374,   375,    -1,    -1,    -1,    -1,    82,   381,    -1,    -1,
      -1,   385,    -1,     3,    -1,     5,    -1,    -1,    -1,   393,
      10,    -1,    -1,    99,    -1,    -1,    -1,    -1,    18,   403,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,    -1,   426,   427,    -1,    -1,   430,    -1,   432,    -1,
      -1,    51,    52,    -1,   438,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    88,    -1,
      -1,   475,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,   201,    -1,    -1,    -1,   119,
      -1,   121,    -1,   507,    -1,    -1,   212,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,   139,
     140,   141,   228,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,   163,    -1,   251,    -1,   253,   168,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    82,   264,    -1,
     266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    99,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,   303,    -1,    -1,
      -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
      -1,   311,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,
     416,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,   428,   429,    -1,    -1,   251,    -1,   253,   349,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
     360,   266,    -1,    -1,    -1,    -1,   271,     6,    -1,    -1,
       9,    -1,    -1,    -1,   460,   375,    -1,    -1,    -1,    -1,
      -1,   381,    -1,    -1,   470,   385,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   393,    -1,    -1,    -1,    -1,   303,    -1,
      -1,   169,    -1,   403,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,   412,    -1,    -1,    -1,   502,   322,   504,    -1,
      -1,   421,    -1,    -1,   510,    -1,   426,   427,    -1,    -1,
     430,    -1,   432,   201,    -1,    -1,    -1,    -1,   438,   207,
     208,   346,    -1,    82,   212,    -1,    -1,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,
      -1,    -1,   377,   112,    -1,   475,    -1,   245,   246,   247,
     480,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,   507,    -1,    -1,
       6,   416,    -1,     9,    -1,    -1,   284,    -1,    -1,    -1,
      -1,    -1,   290,   428,   429,   293,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,   303,    -1,    -1,    -1,    -1,
     308,    -1,    -1,    -1,    -1,   313,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,   322,   460,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,   332,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    82,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    94,   504,
      -1,    -1,    -1,    99,    -1,   510,   245,    -1,    -1,   377,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    82,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,     6,    99,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     448,    -1,   450,   322,   452,    -1,    -1,   455,    -1,   457,
     458,   459,   460,    -1,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,   201,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    99,    -1,    -1,   502,    -1,   504,    -1,   377,    -1,
      -1,   201,   510,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,   212,    -1,    -1,   251,    -1,   253,    -1,    -1,
     256,    -1,   258,   259,   260,    -1,     6,    -1,   264,     9,
     266,    -1,    -1,    -1,    -1,   271,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   428,
     429,   251,    -1,   253,    -1,    -1,   256,   165,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,   303,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,   460,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,   470,    -1,   201,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    82,   303,   212,    -1,    -1,    -1,    -1,    -1,
     346,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    99,
      -1,    -1,   322,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   377,    -1,   251,    -1,   253,   346,    -1,   256,    -1,
     258,   259,   260,    -1,     6,    -1,   264,     9,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,   303,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,   322,    -1,   416,    -1,    -1,    -1,
      -1,   201,    -1,    -1,   460,    -1,    -1,    -1,   428,   429,
      82,    -1,   212,    -1,   470,    -1,    -1,    -1,   346,    -1,
      -1,    -1,   245,    -1,    -1,    -1,   446,    99,   251,    -1,
     253,    -1,    -1,   256,   490,   258,   259,   260,    -1,   495,
     460,   264,    -1,   266,    -1,   245,   502,    -1,   504,   377,
     470,   251,    -1,   253,   510,    -1,   256,    -1,   258,   259,
     260,    -1,     6,    -1,   264,     9,   266,    -1,    -1,    -1,
     490,   271,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
     303,    -1,   502,    -1,   504,    -1,    -1,    -1,   416,    -1,
     510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     428,   429,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   346,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    82,    -1,
     212,    -1,   470,    -1,    -1,    -1,   346,     6,    -1,    -1,
       9,    -1,    -1,    -1,   377,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,   245,   502,    -1,   504,   377,    -1,   251,
      -1,   253,   510,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,   416,   266,    -1,    -1,    -1,    -1,   271,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   416,    -1,     9,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,   428,   429,
      -1,   303,    -1,    -1,    -1,    -1,    -1,   460,    -1,   462,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,   490,   212,    -1,
     470,    -1,   495,    -1,   346,     6,    -1,    -1,     9,   502,
      -1,   504,    -1,    -1,   484,    -1,    -1,   510,    -1,    -1,
     490,    82,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,   245,   502,    -1,   504,   377,    -1,   251,    99,   253,
     510,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,   212,    -1,    -1,   428,   429,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,   460,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,   470,   258,
     259,   260,   346,    -1,    -1,   264,    -1,   266,    -1,    -1,
     201,    -1,   271,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,   212,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,   377,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,   322,    -1,   256,   410,   258,   259,   260,
     201,    -1,   416,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,   212,    -1,    -1,   428,   429,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,   245,    -1,   460,    -1,   377,    -1,
     251,    -1,   253,    -1,    -1,   256,   470,   258,   259,   260,
      -1,   322,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,   346,    -1,   416,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,   428,
     429,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,   428,   429,    -1,
      -1,    -1,    -1,   502,    -1,   504,   377,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,     1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      32,    -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    64,   504,    66,    -1,    -1,    -1,    -1,   510,
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
     182,   491,    -1,   185,   186,    -1,    -1,    -1,   498,    -1,
      -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    73,   241,
      75,    76,    77,    78,    79,    80,    81,    32,    -1,    -1,
      35,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    64,
      -1,    66,    -1,    -1,   119,    -1,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   343,    -1,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    99,   405,   189,   407,   408,   409,    -1,    -1,
      -1,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,   434,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,    -1,    -1,    -1,    -1,   232,    -1,   451,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   468,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   477,   478,   479,    -1,    -1,
     265,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,   491,
      -1,    -1,   277,    -1,    -1,   330,   498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    82,   343,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
     305,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,   330,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,   251,    -1,   253,    -1,   343,   256,
     345,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,   407,   408,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     405,    -1,   407,   408,   409,   322,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
      -1,    -1,   477,   478,   479,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,   446,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
     245,   456,    -1,    -1,    -1,    99,   251,    -1,   253,    -1,
     377,   256,    -1,   258,   259,   260,    -1,    -1,   473,   264,
      -1,   266,   477,   478,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,   497,   498,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   458,    82,   460,    -1,   462,   463,    -1,    -1,    -1,
      -1,   346,    -1,   470,    -1,    -1,    -1,   201,    82,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,   490,    -1,    99,    -1,    -1,   495,    -1,
      -1,    -1,   377,    -1,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,   416,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,   303,
      -1,   201,    -1,   458,    -1,   460,    -1,   462,   463,    -1,
      -1,    -1,   212,    -1,    -1,   470,    -1,   201,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,   346,    -1,    -1,   245,    -1,   502,    -1,   504,
      -1,   251,    -1,   253,    -1,   510,   256,    -1,   258,   259,
     260,   245,    -1,    -1,   264,    -1,   266,   251,    -1,   253,
      -1,    -1,   256,   377,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   322,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,   448,    -1,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   458,    -1,   460,    -1,   462,   463,
      -1,    -1,   346,    -1,    -1,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,   377,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,   377,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,   490,    -1,    -1,    -1,
     510,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510
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
     544,   548,   559,   567,   568,   569,   570,   571,   576,   585,
     587,   592,   595,   596,   598,   599,   600,   601,   602,   603,
     604,   535,   523,   451,   232,   537,  1273,   504,  1193,  1193,
     423,   405,  1291,  1273,  1273,  1273,   394,  1193,   405,   451,
     451,  1273,   451,   451,    57,  1261,   572,     1,   451,   570,
     218,   586,   173,   605,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1273,  1273,  1273,   504,  1187,  1219,
      68,  1187,   451,  1273,  1273,   549,   560,  1187,   545,   504,
     588,   589,   590,  1194,   256,   307,   309,   573,   575,  1037,
    1222,  1273,   451,   504,   451,   607,   539,   340,  1288,  1273,
     212,   256,   266,   346,   416,   460,   510,   593,   594,  1225,
    1187,   256,   218,   306,  1312,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1260,  1323,   199,   561,   562,   563,   546,   558,
     589,    22,   232,  1194,  1274,  1037,   232,   423,  1285,  1273,
      96,  1193,   234,   397,   606,   608,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   594,   442,   503,   597,  1304,  1219,   400,   401,   410,
      63,  1273,   451,   552,   451,   504,   551,    59,  1273,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1304,   256,
     591,  1223,  1285,   232,  1193,  1193,   574,   575,   451,     1,
     290,   312,  1246,   274,   388,   643,   644,   645,   646,   648,
     580,    17,   442,  1225,   328,  1273,   401,  1222,   451,  1273,
     504,  1188,   229,    26,   565,   229,   370,   451,   451,   107,
    1223,  1193,   451,   312,  1193,   649,   351,   412,   413,   647,
     529,     1,   451,   645,   581,   583,   256,  1222,   257,   435,
     494,   557,  1188,   256,   272,   609,   454,  1264,    23,  1255,
     102,   653,   451,   582,   583,    57,   505,  1316,   610,   437,
    1297,   188,  1266,   122,   454,   654,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   611,   612,   618,   620,   622,   623,   624,
     625,   626,   629,   630,   631,   632,   633,   638,   639,   641,
    1289,  1306,    86,  1262,   504,  1177,  1178,   451,   394,   655,
     583,   272,  1280,   351,  1305,   446,   497,  1301,   401,   402,
    1273,  1260,   113,   237,  1275,  1275,   287,   640,  1222,  1304,
     423,   262,    39,  1258,  1273,   650,   651,  1178,  1178,   451,
     172,   392,   530,   656,   657,   659,  1273,  1275,   125,   171,
     615,   351,   359,   630,  1273,  1273,  1273,  1273,  1255,     9,
     287,   349,   642,  1273,  1280,   402,   504,   651,   331,   652,
     506,   684,   686,   687,     1,  1178,   125,   347,   402,   619,
    1273,   117,   118,   119,   238,   252,   335,   347,   437,   613,
     614,   256,  1187,  1192,   419,  1187,   504,  1191,   316,  1286,
    1286,   310,  1187,  1273,  1222,   394,   261,   737,   688,   689,
     691,   701,  1238,   451,   658,  1187,   256,   617,  1219,   617,
       7,   617,   617,   256,   616,  1219,   414,   452,   634,    33,
     167,   267,   627,   451,   394,   255,   739,   451,   689,   451,
       1,   175,   504,   692,   693,   504,   660,   124,   287,   503,
     634,  1240,  1321,  1322,  1264,  1273,   635,   636,   503,   628,
     628,   685,   451,   394,   366,   741,   451,   451,   690,    85,
      47,    62,   102,   239,   250,   351,   352,   366,   368,   451,
     498,   661,   662,   664,   668,   669,   672,   673,   679,   680,
     681,   682,  1273,   124,   124,   287,   635,   432,   621,   637,
    1187,   637,   262,   385,   686,   738,   451,   394,   389,   786,
     703,   694,  1273,  1262,  1273,   351,   353,  1317,  1317,  1273,
    1262,  1273,  1280,  1273,    22,  1254,   306,   683,  1193,   171,
     204,   124,  1240,   501,   309,   686,   740,   451,   394,   531,
      21,    36,    39,    40,    41,    42,    43,    44,    45,    73,
      75,    76,    77,    78,    79,    80,    81,   119,   178,   179,
     180,   181,   182,   185,   186,   219,   235,   277,   305,   319,
     327,   330,   343,   355,   363,   405,   407,   408,   409,   434,
     477,   478,   479,   491,   498,   704,   705,   706,   708,   709,
     710,   711,   712,   713,   714,   717,   726,   727,   728,   729,
     730,   735,   736,  1273,  1293,    26,   196,   702,  1256,   204,
    1222,   504,  1273,  1254,   504,  1189,  1190,   308,   418,  1313,
    1192,  1222,   499,  1273,   174,   213,   504,   670,  1193,   621,
       9,   416,   510,   584,   274,   351,   353,  1315,   686,   742,
     451,   337,   800,   803,   244,   301,   406,   476,  1292,   476,
    1292,   476,  1292,   476,  1292,   476,  1292,   501,  1302,   384,
    1290,  1222,  1216,  1219,  1219,   232,   242,   384,  1276,  1273,
    1274,   171,   204,   241,   468,   504,     9,    50,   212,   244,
     245,   256,   266,   346,   416,   460,   510,   695,  1226,  1227,
    1228,   446,   667,  1190,   254,  1279,   446,  1261,   218,  1268,
     504,  1273,  1273,  1226,  1315,   743,   787,   122,   826,   827,
     510,   446,   718,   462,  1220,  1221,   442,   711,   732,   733,
    1226,    26,   707,   400,  1250,  1250,  1228,   306,  1283,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   696,   697,   698,   699,   700,   712,
     713,  1216,   696,   447,  1222,    57,   353,   663,   674,  1222,
     410,  1294,   256,   671,  1219,   671,   348,   744,   691,   701,
     788,   789,   790,    55,   497,   804,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   828,   829,
     844,   849,   853,   858,   873,   876,   880,   884,   885,   886,
     891,   905,   909,   912,   926,   930,   933,   936,   940,   941,
     945,   955,   958,   975,   977,   980,   984,   991,  1003,  1011,
    1012,  1015,  1016,  1020,  1025,  1026,  1034,  1049,  1059,  1068,
    1073,  1080,  1084,  1086,  1089,  1092,  1096,  1123,   828,  1222,
     445,  1299,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1165,  1167,  1168,  1169,  1170,  1171,
    1172,  1201,  1215,  1216,  1227,  1229,  1230,  1231,  1232,   462,
    1221,  1219,   731,   733,   442,   256,  1260,   696,   451,  1228,
      48,   465,   675,   676,   677,   678,  1304,  1261,   196,   666,
    1267,   504,  1179,     1,   692,   790,   451,   806,   805,   376,
     812,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1251,   830,   845,   850,   854,   859,   874,   877,   881,
     887,   892,   906,   910,   913,   927,   931,   934,   937,   203,
     376,   868,   929,   942,   946,   956,   959,   976,   978,   981,
     399,   985,   992,  1004,  1013,  1017,  1021,  1027,  1035,  1050,
    1060,   256,   346,   387,   416,   510,  1072,  1074,  1081,   336,
    1085,  1087,   815,  1090,  1093,  1097,  1124,   114,   719,   462,
    1234,  1216,  1227,  1229,  1312,  1312,   462,   462,   462,   462,
    1312,  1171,  1167,  1171,   462,  1234,    70,   398,   448,  1166,
     449,   458,   463,   450,   459,   169,   462,  1233,   462,   462,
    1167,   501,   734,  1303,  1226,  1192,  1192,   187,   667,  1222,
     745,   451,   791,   451,    49,   807,   808,   809,  1259,   807,
     504,   451,   308,   831,   832,  1215,     6,    94,   245,   271,
     846,  1172,  1197,  1198,  1215,  1226,  1229,   851,  1167,  1215,
     256,   855,   856,  1183,  1184,  1185,  1219,   271,   422,   424,
     860,   861,   256,   875,  1206,  1215,   878,  1178,     6,   882,
    1173,  1174,  1196,  1217,  1218,  1219,  1227,   454,   888,  1178,
     256,   893,   894,   896,  1197,  1198,  1206,  1215,   907,  1198,
     256,   911,   453,   464,   914,   915,   916,  1155,  1156,  1157,
     199,   323,   324,   340,   394,   928,   932,  1195,  1196,   935,
    1219,   446,   938,  1300,  1198,  1154,  1155,   947,  1195,   957,
    1179,   960,   961,  1215,  1226,  1229,  1051,  1213,  1214,  1219,
      94,   979,  1198,   982,  1198,   170,   225,   233,   317,   986,
     987,   190,   256,   993,   997,   998,   999,  1183,  1207,  1215,
    1219,  1229,  1304,  1005,  1178,  1014,  1175,  1219,  1018,  1178,
    1022,  1175,     9,  1028,  1176,  1219,   153,   271,  1036,  1039,
    1040,  1043,  1044,  1045,  1046,  1047,  1048,  1180,  1181,  1195,
    1212,  1214,  1219,  1051,  1061,  1178,  1069,   112,  1075,  1076,
    1077,  1198,    94,  1082,  1197,  1088,  1179,   451,   504,   816,
     817,   820,   821,   826,  1091,  1215,  1094,  1178,  1098,  1215,
    1125,  1175,   309,  1284,   720,   721,   448,  1165,  1167,   504,
     504,  1167,  1237,  1237,  1237,  1200,  1215,  1227,  1229,  1236,
     504,   448,  1200,  1235,  1167,   448,  1167,  1168,  1168,  1169,
    1169,  1169,  1167,  1200,  1165,   403,   453,    30,  1257,  1261,
       1,   746,   792,   808,   410,   476,   810,   357,   498,   801,
     130,   843,    30,   834,   835,  1257,   196,  1283,  1215,  1216,
    1227,  1229,   131,   848,   446,   847,  1198,    57,   223,  1241,
     856,   446,  1312,   132,   872,   256,  1207,  1206,  1178,   356,
     474,   879,  1304,  1318,  1283,   133,   883,   159,   452,  1174,
    1309,   386,  1247,  1220,  1221,   889,  1178,   134,   890,  1289,
     135,   904,   165,   895,  1134,  1135,   484,   897,   503,   835,
     485,   486,   487,   488,   136,   908,    49,   228,   497,   862,
     137,   925,    17,   501,   917,   918,   919,   921,    12,    13,
      14,    20,   159,   169,   207,   208,   246,   247,   284,   290,
     293,   301,   308,   313,   332,   448,   450,   452,   455,   457,
     458,   459,   462,   463,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1198,   101,   929,  1196,  1182,   441,  1298,   948,  1304,
    1179,    92,   365,   436,   962,   963,   965,   966,  1053,   462,
    1220,  1198,   446,   140,   983,    49,   987,   404,   988,   998,
     141,   451,   994,   996,   481,   499,   442,   445,   439,   143,
    1010,   285,   334,  1244,   196,  1126,   144,  1019,  1289,   145,
    1024,  1126,  1176,   146,  1033,   499,  1029,  1204,  1215,  1227,
    1046,  1048,  1195,   446,  1181,   123,   446,   482,  1038,    31,
    1220,   147,  1067,   177,   237,   240,  1063,   868,  1070,  1304,
    1259,   148,  1079,   228,  1077,  1215,   149,  1083,   196,  1179,
     394,   451,   451,   196,   351,   353,  1095,   150,  1107,   112,
    1099,   151,  1130,  1126,  1187,   220,   723,    27,   115,   722,
     448,  1166,   448,   448,   448,  1166,   448,  1166,   448,   448,
     449,   448,   448,   446,  1273,  1192,   114,   665,   451,    61,
      89,    90,   321,   451,   747,   748,   751,  1273,  1331,    32,
      35,    38,    45,    46,    64,    66,   160,   189,   196,   198,
     211,   243,   252,   265,   305,   318,   345,   371,   378,   395,
     446,   456,   473,   497,   709,   710,   714,   726,   728,   730,
     793,   798,   799,  1273,  1307,  1273,   410,   312,   811,   109,
     813,  1204,   197,   838,   252,   331,   836,   837,  1307,    24,
      25,    65,    67,    69,   103,   104,   105,   153,   155,   162,
     165,   252,   254,   443,   493,   504,   833,  1181,  1308,   152,
     340,  1202,  1216,   446,     6,  1173,  1198,  1219,  1227,   203,
     223,  1242,   376,   852,   339,   857,  1185,   862,   879,   262,
     287,  1266,  1216,  1167,   272,  1248,  1221,  1178,   231,  1150,
    1151,   823,   824,   896,  1198,   294,  1136,    96,   335,   504,
    1181,   298,   901,    35,    38,    45,    46,    91,   160,   189,
     211,   265,   318,   378,   391,   473,   902,   903,   484,   898,
    1134,  1134,  1134,  1134,  1198,  1173,  1198,   863,   916,    21,
     453,   464,   922,   923,  1156,   501,   919,   920,   501,   823,
    1300,   232,  1159,   114,   939,  1183,   128,   823,   943,     9,
      12,    15,    16,   277,   278,   301,   302,   949,   953,   175,
    1204,     9,    57,   177,   241,   468,   969,   970,   971,   964,
     965,   503,  1055,  1284,  1321,   446,  1195,  1173,  1198,   988,
    1304,  1177,   823,   168,  1000,  1154,  1001,  1002,  1215,  1183,
       8,    37,  1128,  1289,  1211,  1215,  1226,  1229,   228,  1006,
    1023,  1304,   129,  1030,  1215,  1030,   446,   446,  1037,   152,
     453,   464,  1198,    49,    38,    46,   211,   243,   265,   318,
     378,   473,  1041,  1042,  1273,  1062,  1304,  1198,   161,   289,
     410,  1198,  1215,   196,  1173,  1198,   822,  1222,  1204,  1259,
     228,  1102,  1127,  1128,  1259,  1275,  1187,  1233,  1233,  1233,
    1200,   241,   468,  1233,   448,  1167,  1233,  1233,  1226,  1284,
    1273,  1273,  1254,   248,   249,  1278,   760,   204,   176,   749,
    1265,  1273,   252,   389,   156,   158,  1273,  1207,   299,  1281,
    1222,    56,  1215,  1215,   204,  1281,    32,   110,  1222,  1273,
     504,   451,   802,   272,   839,  1281,  1281,   837,   836,  1281,
     165,  1131,  1132,   509,   508,  1204,  1131,   237,   423,   299,
     276,   256,  1203,  1216,  1215,  1283,   411,  1137,  1138,  1220,
    1221,  1173,   446,  1243,   852,  1196,   446,  1183,   867,   868,
     380,   362,  1137,  1273,   823,   295,  1152,   825,   823,  1134,
    1273,   252,   389,   156,   158,  1273,   123,   482,   903,  1134,
      96,    97,   899,   839,   203,  1137,   203,   864,   865,   866,
    1259,    17,   442,   924,   316,   922,  1284,   823,   128,   139,
     944,  1300,   365,   950,  1300,   446,    49,   970,   972,  1204,
       9,    57,   241,   468,   967,   968,  1204,  1056,  1306,   722,
     218,   314,  1269,  1195,  1137,   203,  1177,     9,   287,   349,
     989,   379,   990,  1304,   141,   995,     8,   196,  1006,  1215,
     129,  1143,  1145,  1150,   262,   287,   823,   501,   501,  1031,
    1032,  1204,  1203,  1198,  1037,  1037,  1037,  1037,  1037,  1037,
    1037,  1037,  1042,   290,   293,  1064,  1065,  1066,  1160,  1245,
    1150,   244,   410,  1320,   423,  1296,  1296,  1078,  1304,  1215,
    1137,   203,   451,   446,     9,  1100,  1101,  1239,  1103,  1215,
    1078,  1103,  1023,     7,  1252,   504,   724,   725,  1273,   448,
    1187,  1206,  1273,  1254,   256,   752,  1224,   691,   761,   750,
    1215,   510,  1208,  1212,  1222,  1208,  1273,  1299,  1273,  1273,
      32,  1222,   814,   815,  1273,   503,   840,  1208,  1208,  1208,
     823,   294,  1133,  1131,  1247,  1216,   823,   297,  1139,  1221,
    1137,  1205,  1215,  1226,   165,   461,   870,  1311,     6,   228,
     308,   460,   869,  1272,    34,   281,   282,   283,   344,   466,
     467,   471,  1249,   823,   826,  1208,  1208,  1153,  1210,  1212,
    1222,  1153,   503,   900,  1173,  1174,  1173,  1174,   865,   308,
     810,    87,   357,   498,   923,  1155,   823,  1215,   823,   498,
     951,   952,   953,   954,  1298,   498,  1205,  1204,    49,   973,
     968,   188,   973,  1052,  1273,  1275,   314,  1173,   990,  1286,
    1286,   310,   262,   287,  1002,  1198,   217,  1007,  1304,   823,
     291,  1146,   262,  1155,  1154,  1031,  1160,  1215,  1161,  1162,
    1163,  1164,  1167,  1071,  1198,  1071,   461,  1140,  1141,   330,
    1247,  1173,   818,  1205,   313,  1204,   113,  1104,   436,  1106,
     157,   292,  1129,  1147,  1148,  1149,  1150,   321,  1181,  1208,
     725,  1186,  1187,   753,   252,   254,  1314,   504,   692,  1215,
     270,   329,   458,   463,   794,   795,   796,  1206,   794,   795,
     797,   815,    47,    32,    35,    38,    46,    91,   189,   198,
     211,   243,   263,   265,   288,   318,   345,   371,   378,   391,
     395,   444,   473,   483,   489,   841,   842,  1131,   823,  1137,
     823,   294,   871,   823,  1283,  1215,   252,   254,  1319,   902,
    1137,   361,  1137,   361,  1198,   952,   102,  1263,  1300,   973,
     973,  1205,     8,    37,   974,   225,   497,  1057,  1187,  1054,
    1137,   380,    49,   262,   237,  1008,   216,   236,   262,   287,
     500,   823,   823,   823,   823,   296,  1142,  1273,  1137,  1137,
     492,   819,  1108,  1101,  1268,    95,  1105,  1268,  1140,   823,
     823,  1149,   252,   254,  1277,  1187,   177,   187,   210,   240,
     754,   755,   756,   757,   758,   759,  1224,   762,  1208,  1208,
     129,  1273,  1273,    56,   123,   482,     8,  1253,   842,   823,
    1215,  1174,  1174,    49,   110,   973,   456,  1271,  1271,   337,
    1177,   203,   317,  1058,  1219,  1198,  1273,  1009,  1144,  1145,
    1146,  1150,   262,   262,   262,   823,  1215,  1109,   451,  1215,
    1268,  1215,   106,   116,  1324,  1273,  1273,    54,    89,  1324,
    1325,  1308,   763,   109,  1208,  1208,  1273,  1153,  1153,  1209,
    1212,  1224,  1137,  1137,  1198,  1198,  1198,  1273,  1177,   337,
     481,  1215,  1146,   127,   166,   204,  1110,  1111,  1112,  1114,
    1118,  1120,  1121,  1122,  1257,  1266,  1215,  1273,  1224,  1224,
     210,  1273,  1273,   209,   252,   254,   285,   305,   333,   414,
     431,   451,   472,   491,   499,   709,   714,   715,   726,   728,
     730,   764,   765,   769,   770,   773,   774,   775,   776,   777,
     778,   783,   784,   785,  1307,  1308,   451,  1206,   997,  1273,
    1154,    37,  1253,   340,   107,  1224,  1224,  1224,   221,  1270,
     299,   300,  1282,  1254,   209,  1222,   501,  1273,  1283,  1273,
    1273,  1215,   286,   329,   779,   780,  1224,   329,   781,   782,
    1224,  1282,  1254,   997,   367,   418,  1295,   129,   421,  1119,
    1284,  1274,  1273,   718,  1154,  1201,  1199,  1201,    53,    89,
     321,   325,   326,   366,   382,   383,   766,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,   119,   196,  1222,   780,  1222,   782,
    1274,  1215,   161,   165,  1310,     9,  1115,  1116,  1184,   780,
    1299,  1247,   373,   771,  1201,   187,   187,   210,   187,   210,
     176,   767,  1215,   767,  1201,   337,  1287,   306,   338,   358,
    1117,  1116,   719,  1284,   313,   768,   768,    49,  1284,   306,
    1219,   425,   716,   176,   772,  1215,   321,  1201,   170,   225,
     233,   317,  1113,  1177,  1222
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
#line 1353 "parser.y"
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
#line 1364 "parser.y"
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
#line 1400 "parser.y"
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
#line 1455 "parser.y"
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
#line 1484 "parser.y"
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
#line 1517 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1523 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1535 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 1545 "parser.y"
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
#line 1576 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1583 "parser.y"
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
#line 1622 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1623 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1632 "parser.y"
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
#line 1641 "parser.y"
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
#line 1655 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1659 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1669 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1678 "parser.y"
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
#line 1703 "parser.y"
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
#line 1721 "parser.y"
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
#line 1734 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1763 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1770 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1777 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1784 "parser.y"
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
#line 1795 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1799 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1803 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1807 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1821 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1826 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1834 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1846 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1850 "parser.y"
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
#line 1871 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1875 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1882 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1887 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1898 "parser.y"
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
#line 1912 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1943 "parser.y"
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
#line 1962 "parser.y"
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
#line 1972 "parser.y"
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
#line 1985 "parser.y"
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
#line 2001 "parser.y"
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
#line 2011 "parser.y"
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
#line 2026 "parser.y"
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
#line 2039 "parser.y"
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
#line 2050 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2056 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2062 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2068 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2074 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2080 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2090 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2094 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2101 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2105 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2109 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2113 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2120 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 2124 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2130 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2131 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2132 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2133 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2134 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2135 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2139 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 2140 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 2148 "parser.y"
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

  case 150:

/* Line 1806 of yacc.c  */
#line 2162 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 2166 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 2174 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 2181 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 2185 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 2196 "parser.y"
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

  case 156:

/* Line 1806 of yacc.c  */
#line 2216 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2224 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 2234 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 2235 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2242 "parser.y"
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

  case 161:

/* Line 1806 of yacc.c  */
#line 2262 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2263 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 2268 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 2272 "parser.y"
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

  case 165:

/* Line 1806 of yacc.c  */
#line 2293 "parser.y"
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

  case 166:

/* Line 1806 of yacc.c  */
#line 2316 "parser.y"
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

  case 167:

/* Line 1806 of yacc.c  */
#line 2397 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 2401 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 2410 "parser.y"
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

  case 170:

/* Line 1806 of yacc.c  */
#line 2429 "parser.y"
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

  case 171:

/* Line 1806 of yacc.c  */
#line 2445 "parser.y"
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

  case 172:

/* Line 1806 of yacc.c  */
#line 2463 "parser.y"
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

  case 173:

/* Line 1806 of yacc.c  */
#line 2481 "parser.y"
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

  case 174:

/* Line 1806 of yacc.c  */
#line 2498 "parser.y"
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

  case 176:

/* Line 1806 of yacc.c  */
#line 2515 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2523 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 2532 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2547 "parser.y"
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

  case 184:

/* Line 1806 of yacc.c  */
#line 2564 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 2568 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 2602 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 2608 "parser.y"
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

  case 203:

/* Line 1806 of yacc.c  */
#line 2618 "parser.y"
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

  case 204:

/* Line 1806 of yacc.c  */
#line 2631 "parser.y"
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

  case 205:

/* Line 1806 of yacc.c  */
#line 2644 "parser.y"
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

  case 211:

/* Line 1806 of yacc.c  */
#line 2667 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2674 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2687 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2699 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2706 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2707 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 2708 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2716 "parser.y"
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

  case 225:

/* Line 1806 of yacc.c  */
#line 2745 "parser.y"
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

  case 226:

/* Line 1806 of yacc.c  */
#line 2782 "parser.y"
    { (yyval) = cb_int (-1); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2785 "parser.y"
    {
     if (cb_verify (cb_use_sparse_indexed_keys, "SUPPRESS WHEN")) {
        (yyval) = cb_int (literal_value ((yyvsp[(4) - (4)])));
     } else {
        (yyval) = cb_int (-1);
     }
  }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2794 "parser.y"
    {
     if (cb_verify (cb_use_sparse_indexed_keys, "SUPPRESS WHEN")) {
        (yyval) = cb_int (literal_value ((yyvsp[(3) - (3)])));
     } else {
        (yyval) = cb_int (-1);
     }
  }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2809 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2820 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 2835 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2843 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 2848 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2853 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2862 "parser.y"
    {
	current_file->flag_lock_many = 1;
  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2866 "parser.y"
    {
	current_file->flag_lock_many = 1;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2882 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2887 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2892 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2897 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2908 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2919 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2929 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2934 "parser.y"
    {
	PENDING ("SPLIT KEYS for PRIMARY KEYS");
	#if 0 /* ToDo: implement */
	cb_tree composite_key;

	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	// generate field (in w-s) for composite-key
	composite_key = cb_build_field((yyvsp[(5) - (6)]));
	if (composite_key == cb_error_node) {
		YYERROR;
	} else {
		composite_key->category = CB_CATEGORY_ALPHANUMERIC; 
		((struct cb_field *)composite_key)->count = 1;
		current_file->key = cb_build_field_reference((struct cb_field *)composite_key, NULL);
		current_file->component_list = key_component_list;
	}
	#endif
  }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2960 "parser.y"
    {
    key_component_list = NULL;
  }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2970 "parser.y"
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

  case 259:

/* Line 1806 of yacc.c  */
#line 2989 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 3000 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 3014 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
  }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 3020 "parser.y"
    { current_file->share_mode = COB_SHARE_ALL; }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 3021 "parser.y"
    { current_file->share_mode = COB_SHARE_EXCLUSIVE; }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 3022 "parser.y"
    { current_file->share_mode = COB_SHARE_READ_ONLY; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 3031 "parser.y"
    {
	yyerrok;
  }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 3050 "parser.y"
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

  case 275:

/* Line 1806 of yacc.c  */
#line 3077 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 3078 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 3079 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 3080 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3087 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 3092 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3119 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 3128 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 3142 "parser.y"
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

  case 293:

/* Line 1806 of yacc.c  */
#line 3161 "parser.y"
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

  case 295:

/* Line 1806 of yacc.c  */
#line 3178 "parser.y"
    {
	yyerrok;
  }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 3185 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 3189 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 3200 "parser.y"
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

  case 301:

/* Line 1806 of yacc.c  */
#line 3210 "parser.y"
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

  case 311:

/* Line 1806 of yacc.c  */
#line 3240 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3253 "parser.y"
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

  case 316:

/* Line 1806 of yacc.c  */
#line 3273 "parser.y"
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

  case 317:

/* Line 1806 of yacc.c  */
#line 3308 "parser.y"
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

  case 319:

/* Line 1806 of yacc.c  */
#line 3339 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 3345 "parser.y"
    { (yyval) = NULL; }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 3346 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3350 "parser.y"
    { (yyval) = NULL; }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 3351 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 3359 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 3370 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 3375 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3398 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3410 "parser.y"
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

  case 338:

/* Line 1806 of yacc.c  */
#line 3438 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 3445 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 3452 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 3461 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 3473 "parser.y"
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

  case 343:

/* Line 1806 of yacc.c  */
#line 3525 "parser.y"
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

  case 346:

/* Line 1806 of yacc.c  */
#line 3545 "parser.y"
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

  case 347:

/* Line 1806 of yacc.c  */
#line 3555 "parser.y"
    {
	current_report = build_report ((yyvsp[(2) - (2)]));
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 3595 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 3601 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 3610 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3613 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 3619 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 3639 "parser.y"
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

  case 359:

/* Line 1806 of yacc.c  */
#line 3654 "parser.y"
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

  case 360:

/* Line 1806 of yacc.c  */
#line 3674 "parser.y"
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

  case 361:

/* Line 1806 of yacc.c  */
#line 3687 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3694 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3700 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3706 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3715 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3724 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 3728 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 3739 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 3740 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 3741 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 3742 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 3747 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 3751 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 3755 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 3759 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 3763 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 3767 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 3771 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 3775 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 3779 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 3783 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 3787 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 3791 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 3795 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 3827 "parser.y"
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

  case 395:

/* Line 1806 of yacc.c  */
#line 3853 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 3857 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 3865 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 3871 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 3899 "parser.y"
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

  case 414:

/* Line 1806 of yacc.c  */
#line 3923 "parser.y"
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

  case 415:

/* Line 1806 of yacc.c  */
#line 3950 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3954 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 3963 "parser.y"
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

  case 418:

/* Line 1806 of yacc.c  */
#line 3988 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 4004 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 4008 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 4012 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 4016 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 4020 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 4024 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 4028 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 4032 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 4036 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 4040 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 4044 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 4048 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 4052 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 4057 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 4062 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 4066 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 4070 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 4078 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 4082 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 4086 "parser.y"
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
#line 4094 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 4098 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 4102 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 4106 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 4110 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 4114 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 4118 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 4122 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 4126 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 4134 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 4142 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 4146 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 4150 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 4154 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 4158 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 4162 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 4182 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 4188 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 4201 "parser.y"
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

  case 465:

/* Line 1806 of yacc.c  */
#line 4219 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 4229 "parser.y"
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

  case 467:

/* Line 1806 of yacc.c  */
#line 4251 "parser.y"
    { (yyval) = NULL; }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 4252 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 4257 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 4264 "parser.y"
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

  case 472:

/* Line 1806 of yacc.c  */
#line 4287 "parser.y"
    { (yyval) = NULL; }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 4290 "parser.y"
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

  case 474:

/* Line 1806 of yacc.c  */
#line 4305 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 4306 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 4311 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 4317 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 4319 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 4324 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 4335 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 4346 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 4357 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 4368 "parser.y"
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

  case 485:

/* Line 1806 of yacc.c  */
#line 4396 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 4404 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 4405 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 4409 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 4410 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 4415 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 4428 "parser.y"
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

  case 494:

/* Line 1806 of yacc.c  */
#line 4441 "parser.y"
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

  case 495:

/* Line 1806 of yacc.c  */
#line 4462 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  }
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 4471 "parser.y"
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

  case 498:

/* Line 1806 of yacc.c  */
#line 4486 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 4495 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 4507 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 4513 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 4524 "parser.y"
    {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  }
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 4540 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  }
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 4555 "parser.y"
    {
	yyerrok;
  }
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 4562 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 4567 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 4578 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 4597 "parser.y"
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

  case 522:

/* Line 1806 of yacc.c  */
#line 4633 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 4637 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 4642 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  }
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 4662 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 4669 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 4676 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 4683 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 4690 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 4701 "parser.y"
    {
	check_pic_duplicate = 0;
  }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 4732 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 4758 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 4765 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  }
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 4781 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 4792 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  }
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 4804 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 4837 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  }
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 4844 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  }
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 4851 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 4860 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 4867 "parser.y"
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

  case 606:

/* Line 1806 of yacc.c  */
#line 4893 "parser.y"
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

  case 607:

/* Line 1806 of yacc.c  */
#line 4924 "parser.y"
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

  case 608:

/* Line 1806 of yacc.c  */
#line 4950 "parser.y"
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

  case 611:

/* Line 1806 of yacc.c  */
#line 4973 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 4977 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 4981 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 4985 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 4989 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 4993 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 4997 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 5001 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 619:

/* Line 1806 of yacc.c  */
#line 5005 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 5009 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 5013 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 5017 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 5021 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 5025 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 5029 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 5033 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 5037 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 628:

/* Line 1806 of yacc.c  */
#line 5042 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 5046 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 5050 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 5055 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 5060 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 5065 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 5078 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 5085 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 5090 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 5109 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 5113 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 5117 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 5124 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 5128 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 5132 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 5140 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 5151 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 5160 "parser.y"
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

  case 659:

/* Line 1806 of yacc.c  */
#line 5170 "parser.y"
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

  case 660:

/* Line 1806 of yacc.c  */
#line 5182 "parser.y"
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

  case 661:

/* Line 1806 of yacc.c  */
#line 5197 "parser.y"
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

  case 663:

/* Line 1806 of yacc.c  */
#line 5230 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 5234 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 5239 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 5247 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 5256 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 5266 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 5268 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 5273 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 5282 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 5286 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 5298 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 5306 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 677:

/* Line 1806 of yacc.c  */
#line 5314 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 678:

/* Line 1806 of yacc.c  */
#line 5322 "parser.y"
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

  case 679:

/* Line 1806 of yacc.c  */
#line 5351 "parser.y"
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

  case 681:

/* Line 1806 of yacc.c  */
#line 5384 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 682:

/* Line 1806 of yacc.c  */
#line 5393 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 683:

/* Line 1806 of yacc.c  */
#line 5399 "parser.y"
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

  case 685:

/* Line 1806 of yacc.c  */
#line 5427 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 686:

/* Line 1806 of yacc.c  */
#line 5433 "parser.y"
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

  case 691:

/* Line 1806 of yacc.c  */
#line 5470 "parser.y"
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

  case 693:

/* Line 1806 of yacc.c  */
#line 5488 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 694:

/* Line 1806 of yacc.c  */
#line 5498 "parser.y"
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

  case 695:

/* Line 1806 of yacc.c  */
#line 5542 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 698:

/* Line 1806 of yacc.c  */
#line 5553 "parser.y"
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

  case 699:

/* Line 1806 of yacc.c  */
#line 5601 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 700:

/* Line 1806 of yacc.c  */
#line 5613 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 701:

/* Line 1806 of yacc.c  */
#line 5617 "parser.y"
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

  case 702:

/* Line 1806 of yacc.c  */
#line 5635 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 703:

/* Line 1806 of yacc.c  */
#line 5640 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 704:

/* Line 1806 of yacc.c  */
#line 5645 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 705:

/* Line 1806 of yacc.c  */
#line 5653 "parser.y"
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

  case 706:

/* Line 1806 of yacc.c  */
#line 5680 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 707:

/* Line 1806 of yacc.c  */
#line 5684 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 757:

/* Line 1806 of yacc.c  */
#line 5740 "parser.y"
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

  case 758:

/* Line 1806 of yacc.c  */
#line 5754 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 759:

/* Line 1806 of yacc.c  */
#line 5765 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 761:

/* Line 1806 of yacc.c  */
#line 5775 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 762:

/* Line 1806 of yacc.c  */
#line 5780 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 763:

/* Line 1806 of yacc.c  */
#line 5784 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 764:

/* Line 1806 of yacc.c  */
#line 5788 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 765:

/* Line 1806 of yacc.c  */
#line 5793 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 766:

/* Line 1806 of yacc.c  */
#line 5798 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 767:

/* Line 1806 of yacc.c  */
#line 5803 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 768:

/* Line 1806 of yacc.c  */
#line 5808 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 769:

/* Line 1806 of yacc.c  */
#line 5812 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 770:

/* Line 1806 of yacc.c  */
#line 5816 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 771:

/* Line 1806 of yacc.c  */
#line 5820 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 772:

/* Line 1806 of yacc.c  */
#line 5824 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 773:

/* Line 1806 of yacc.c  */
#line 5829 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 774:

/* Line 1806 of yacc.c  */
#line 5833 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 775:

/* Line 1806 of yacc.c  */
#line 5837 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 776:

/* Line 1806 of yacc.c  */
#line 5841 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 777:

/* Line 1806 of yacc.c  */
#line 5845 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 778:

/* Line 1806 of yacc.c  */
#line 5849 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 779:

/* Line 1806 of yacc.c  */
#line 5853 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 781:

/* Line 1806 of yacc.c  */
#line 5861 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 784:

/* Line 1806 of yacc.c  */
#line 5872 "parser.y"
    { (yyval) = NULL; }
    break;

  case 785:

/* Line 1806 of yacc.c  */
#line 5873 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 786:

/* Line 1806 of yacc.c  */
#line 5877 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 787:

/* Line 1806 of yacc.c  */
#line 5878 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 788:

/* Line 1806 of yacc.c  */
#line 5879 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 789:

/* Line 1806 of yacc.c  */
#line 5880 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 790:

/* Line 1806 of yacc.c  */
#line 5881 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 791:

/* Line 1806 of yacc.c  */
#line 5885 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 792:

/* Line 1806 of yacc.c  */
#line 5889 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 793:

/* Line 1806 of yacc.c  */
#line 5890 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 797:

/* Line 1806 of yacc.c  */
#line 5899 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 802:

/* Line 1806 of yacc.c  */
#line 5915 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 803:

/* Line 1806 of yacc.c  */
#line 5919 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 804:

/* Line 1806 of yacc.c  */
#line 5923 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 805:

/* Line 1806 of yacc.c  */
#line 5927 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 806:

/* Line 1806 of yacc.c  */
#line 5931 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 807:

/* Line 1806 of yacc.c  */
#line 5935 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 808:

/* Line 1806 of yacc.c  */
#line 5939 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 809:

/* Line 1806 of yacc.c  */
#line 5943 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 810:

/* Line 1806 of yacc.c  */
#line 5947 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 811:

/* Line 1806 of yacc.c  */
#line 5951 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 812:

/* Line 1806 of yacc.c  */
#line 5955 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 813:

/* Line 1806 of yacc.c  */
#line 5959 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 814:

/* Line 1806 of yacc.c  */
#line 5963 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 815:

/* Line 1806 of yacc.c  */
#line 5967 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 816:

/* Line 1806 of yacc.c  */
#line 5971 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 817:

/* Line 1806 of yacc.c  */
#line 5975 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 818:

/* Line 1806 of yacc.c  */
#line 5979 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 819:

/* Line 1806 of yacc.c  */
#line 5983 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 820:

/* Line 1806 of yacc.c  */
#line 5987 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 821:

/* Line 1806 of yacc.c  */
#line 5991 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 822:

/* Line 1806 of yacc.c  */
#line 5995 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 823:

/* Line 1806 of yacc.c  */
#line 5999 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 824:

/* Line 1806 of yacc.c  */
#line 6003 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 825:

/* Line 1806 of yacc.c  */
#line 6007 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 826:

/* Line 1806 of yacc.c  */
#line 6014 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 827:

/* Line 1806 of yacc.c  */
#line 6018 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 828:

/* Line 1806 of yacc.c  */
#line 6028 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 830:

/* Line 1806 of yacc.c  */
#line 6037 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 831:

/* Line 1806 of yacc.c  */
#line 6041 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 832:

/* Line 1806 of yacc.c  */
#line 6045 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 834:

/* Line 1806 of yacc.c  */
#line 6052 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 835:

/* Line 1806 of yacc.c  */
#line 6059 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 836:

/* Line 1806 of yacc.c  */
#line 6063 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 837:

/* Line 1806 of yacc.c  */
#line 6073 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 839:

/* Line 1806 of yacc.c  */
#line 6082 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 840:

/* Line 1806 of yacc.c  */
#line 6086 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 841:

/* Line 1806 of yacc.c  */
#line 6097 "parser.y"
    { (yyval) = NULL; }
    break;

  case 842:

/* Line 1806 of yacc.c  */
#line 6098 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 843:

/* Line 1806 of yacc.c  */
#line 6106 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 847:

/* Line 1806 of yacc.c  */
#line 6120 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 850:

/* Line 1806 of yacc.c  */
#line 6132 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 852:

/* Line 1806 of yacc.c  */
#line 6147 "parser.y"
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

  case 853:

/* Line 1806 of yacc.c  */
#line 6161 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 854:

/* Line 1806 of yacc.c  */
#line 6166 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 855:

/* Line 1806 of yacc.c  */
#line 6171 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 856:

/* Line 1806 of yacc.c  */
#line 6176 "parser.y"
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

  case 857:

/* Line 1806 of yacc.c  */
#line 6196 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 858:

/* Line 1806 of yacc.c  */
#line 6200 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 859:

/* Line 1806 of yacc.c  */
#line 6205 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 860:

/* Line 1806 of yacc.c  */
#line 6216 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 861:

/* Line 1806 of yacc.c  */
#line 6218 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 862:

/* Line 1806 of yacc.c  */
#line 6223 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 863:

/* Line 1806 of yacc.c  */
#line 6231 "parser.y"
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

  case 865:

/* Line 1806 of yacc.c  */
#line 6257 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 866:

/* Line 1806 of yacc.c  */
#line 6261 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 867:

/* Line 1806 of yacc.c  */
#line 6270 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 868:

/* Line 1806 of yacc.c  */
#line 6282 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 869:

/* Line 1806 of yacc.c  */
#line 6286 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 870:

/* Line 1806 of yacc.c  */
#line 6290 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 871:

/* Line 1806 of yacc.c  */
#line 6294 "parser.y"
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

  case 876:

/* Line 1806 of yacc.c  */
#line 6327 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 877:

/* Line 1806 of yacc.c  */
#line 6332 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 878:

/* Line 1806 of yacc.c  */
#line 6339 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 879:

/* Line 1806 of yacc.c  */
#line 6344 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 880:

/* Line 1806 of yacc.c  */
#line 6351 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 881:

/* Line 1806 of yacc.c  */
#line 6355 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 882:

/* Line 1806 of yacc.c  */
#line 6365 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 884:

/* Line 1806 of yacc.c  */
#line 6373 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 885:

/* Line 1806 of yacc.c  */
#line 6377 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 886:

/* Line 1806 of yacc.c  */
#line 6387 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 888:

/* Line 1806 of yacc.c  */
#line 6395 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 889:

/* Line 1806 of yacc.c  */
#line 6400 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 890:

/* Line 1806 of yacc.c  */
#line 6407 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 891:

/* Line 1806 of yacc.c  */
#line 6408 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 892:

/* Line 1806 of yacc.c  */
#line 6409 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 893:

/* Line 1806 of yacc.c  */
#line 6410 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 894:

/* Line 1806 of yacc.c  */
#line 6411 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 895:

/* Line 1806 of yacc.c  */
#line 6419 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 897:

/* Line 1806 of yacc.c  */
#line 6428 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 898:

/* Line 1806 of yacc.c  */
#line 6435 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 899:

/* Line 1806 of yacc.c  */
#line 6439 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 900:

/* Line 1806 of yacc.c  */
#line 6449 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 901:

/* Line 1806 of yacc.c  */
#line 6460 "parser.y"
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

  case 902:

/* Line 1806 of yacc.c  */
#line 6477 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 904:

/* Line 1806 of yacc.c  */
#line 6486 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 906:

/* Line 1806 of yacc.c  */
#line 6494 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 907:

/* Line 1806 of yacc.c  */
#line 6499 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 908:

/* Line 1806 of yacc.c  */
#line 6507 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 909:

/* Line 1806 of yacc.c  */
#line 6511 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 910:

/* Line 1806 of yacc.c  */
#line 6521 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 912:

/* Line 1806 of yacc.c  */
#line 6531 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 913:

/* Line 1806 of yacc.c  */
#line 6535 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 914:

/* Line 1806 of yacc.c  */
#line 6539 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 915:

/* Line 1806 of yacc.c  */
#line 6543 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 916:

/* Line 1806 of yacc.c  */
#line 6547 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 918:

/* Line 1806 of yacc.c  */
#line 6552 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 920:

/* Line 1806 of yacc.c  */
#line 6562 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 922:

/* Line 1806 of yacc.c  */
#line 6570 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 923:

/* Line 1806 of yacc.c  */
#line 6578 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 924:

/* Line 1806 of yacc.c  */
#line 6586 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 925:

/* Line 1806 of yacc.c  */
#line 6590 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 926:

/* Line 1806 of yacc.c  */
#line 6594 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 927:

/* Line 1806 of yacc.c  */
#line 6598 "parser.y"
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
#line 6620 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 934:

/* Line 1806 of yacc.c  */
#line 6626 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 935:

/* Line 1806 of yacc.c  */
#line 6627 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 938:

/* Line 1806 of yacc.c  */
#line 6638 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 939:

/* Line 1806 of yacc.c  */
#line 6642 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 940:

/* Line 1806 of yacc.c  */
#line 6646 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 941:

/* Line 1806 of yacc.c  */
#line 6650 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 942:

/* Line 1806 of yacc.c  */
#line 6654 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 943:

/* Line 1806 of yacc.c  */
#line 6658 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 944:

/* Line 1806 of yacc.c  */
#line 6662 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 945:

/* Line 1806 of yacc.c  */
#line 6666 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 946:

/* Line 1806 of yacc.c  */
#line 6670 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 947:

/* Line 1806 of yacc.c  */
#line 6674 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 948:

/* Line 1806 of yacc.c  */
#line 6678 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 949:

/* Line 1806 of yacc.c  */
#line 6682 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 950:

/* Line 1806 of yacc.c  */
#line 6686 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 951:

/* Line 1806 of yacc.c  */
#line 6690 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 952:

/* Line 1806 of yacc.c  */
#line 6694 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 953:

/* Line 1806 of yacc.c  */
#line 6698 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 954:

/* Line 1806 of yacc.c  */
#line 6705 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 955:

/* Line 1806 of yacc.c  */
#line 6709 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 956:

/* Line 1806 of yacc.c  */
#line 6719 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 958:

/* Line 1806 of yacc.c  */
#line 6728 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 959:

/* Line 1806 of yacc.c  */
#line 6732 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 960:

/* Line 1806 of yacc.c  */
#line 6736 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 961:

/* Line 1806 of yacc.c  */
#line 6740 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 962:

/* Line 1806 of yacc.c  */
#line 6744 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 963:

/* Line 1806 of yacc.c  */
#line 6751 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 964:

/* Line 1806 of yacc.c  */
#line 6755 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 965:

/* Line 1806 of yacc.c  */
#line 6765 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 967:

/* Line 1806 of yacc.c  */
#line 6773 "parser.y"
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

  case 968:

/* Line 1806 of yacc.c  */
#line 6792 "parser.y"
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

  case 970:

/* Line 1806 of yacc.c  */
#line 6816 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 971:

/* Line 1806 of yacc.c  */
#line 6823 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 972:

/* Line 1806 of yacc.c  */
#line 6825 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 973:

/* Line 1806 of yacc.c  */
#line 6830 "parser.y"
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

  case 974:

/* Line 1806 of yacc.c  */
#line 6841 "parser.y"
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

  case 975:

/* Line 1806 of yacc.c  */
#line 6852 "parser.y"
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

  case 976:

/* Line 1806 of yacc.c  */
#line 6866 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 977:

/* Line 1806 of yacc.c  */
#line 6870 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 978:

/* Line 1806 of yacc.c  */
#line 6876 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 979:

/* Line 1806 of yacc.c  */
#line 6878 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 980:

/* Line 1806 of yacc.c  */
#line 6884 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 981:

/* Line 1806 of yacc.c  */
#line 6893 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 982:

/* Line 1806 of yacc.c  */
#line 6901 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 983:

/* Line 1806 of yacc.c  */
#line 6907 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 984:

/* Line 1806 of yacc.c  */
#line 6914 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 985:

/* Line 1806 of yacc.c  */
#line 6916 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 986:

/* Line 1806 of yacc.c  */
#line 6921 "parser.y"
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

  case 987:

/* Line 1806 of yacc.c  */
#line 6982 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 988:

/* Line 1806 of yacc.c  */
#line 6983 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 989:

/* Line 1806 of yacc.c  */
#line 6984 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 990:

/* Line 1806 of yacc.c  */
#line 6988 "parser.y"
    { (yyval) = NULL; }
    break;

  case 991:

/* Line 1806 of yacc.c  */
#line 6989 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 992:

/* Line 1806 of yacc.c  */
#line 6994 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 993:

/* Line 1806 of yacc.c  */
#line 6998 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 994:

/* Line 1806 of yacc.c  */
#line 7008 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 995:

/* Line 1806 of yacc.c  */
#line 7013 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 997:

/* Line 1806 of yacc.c  */
#line 7021 "parser.y"
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

  case 998:

/* Line 1806 of yacc.c  */
#line 7042 "parser.y"
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

  case 999:

/* Line 1806 of yacc.c  */
#line 7056 "parser.y"
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

  case 1000:

/* Line 1806 of yacc.c  */
#line 7078 "parser.y"
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

  case 1001:

/* Line 1806 of yacc.c  */
#line 7100 "parser.y"
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

  case 1002:

/* Line 1806 of yacc.c  */
#line 7120 "parser.y"
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

  case 1003:

/* Line 1806 of yacc.c  */
#line 7142 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1004:

/* Line 1806 of yacc.c  */
#line 7143 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1005:

/* Line 1806 of yacc.c  */
#line 7151 "parser.y"
    {
	begin_statement ("FREE", 0);
  }
    break;

  case 1007:

/* Line 1806 of yacc.c  */
#line 7159 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 1008:

/* Line 1806 of yacc.c  */
#line 7169 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  }
    break;

  case 1011:

/* Line 1806 of yacc.c  */
#line 7185 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1013:

/* Line 1806 of yacc.c  */
#line 7198 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7206 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1015:

/* Line 1806 of yacc.c  */
#line 7211 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1016:

/* Line 1806 of yacc.c  */
#line 7222 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7237 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1019:

/* Line 1806 of yacc.c  */
#line 7246 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7250 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7254 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7261 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7265 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7275 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7284 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7290 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7291 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7295 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7296 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7297 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1032:

/* Line 1806 of yacc.c  */
#line 7302 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7306 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7313 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1035:

/* Line 1806 of yacc.c  */
#line 7318 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7325 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1037:

/* Line 1806 of yacc.c  */
#line 7331 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7332 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1039:

/* Line 1806 of yacc.c  */
#line 7333 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1040:

/* Line 1806 of yacc.c  */
#line 7334 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1041:

/* Line 1806 of yacc.c  */
#line 7335 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1042:

/* Line 1806 of yacc.c  */
#line 7336 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7337 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1044:

/* Line 1806 of yacc.c  */
#line 7342 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1045:

/* Line 1806 of yacc.c  */
#line 7346 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1046:

/* Line 1806 of yacc.c  */
#line 7355 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1048:

/* Line 1806 of yacc.c  */
#line 7364 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1049:

/* Line 1806 of yacc.c  */
#line 7370 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1050:

/* Line 1806 of yacc.c  */
#line 7381 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1053:

/* Line 1806 of yacc.c  */
#line 7394 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1054:

/* Line 1806 of yacc.c  */
#line 7398 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7402 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7418 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7422 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7432 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1063:

/* Line 1806 of yacc.c  */
#line 7442 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1064:

/* Line 1806 of yacc.c  */
#line 7450 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1065:

/* Line 1806 of yacc.c  */
#line 7451 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1066:

/* Line 1806 of yacc.c  */
#line 7455 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7456 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7457 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7458 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7459 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
#line 7460 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1072:

/* Line 1806 of yacc.c  */
#line 7464 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7465 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7470 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1075:

/* Line 1806 of yacc.c  */
#line 7475 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1076:

/* Line 1806 of yacc.c  */
#line 7481 "parser.y"
    { /* Nothing */ }
    break;

  case 1077:

/* Line 1806 of yacc.c  */
#line 7482 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7483 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1079:

/* Line 1806 of yacc.c  */
#line 7484 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1080:

/* Line 1806 of yacc.c  */
#line 7485 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1081:

/* Line 1806 of yacc.c  */
#line 7490 "parser.y"
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

  case 1082:

/* Line 1806 of yacc.c  */
#line 7517 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1083:

/* Line 1806 of yacc.c  */
#line 7521 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7528 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7532 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1086:

/* Line 1806 of yacc.c  */
#line 7541 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7553 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7561 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1091:

/* Line 1806 of yacc.c  */
#line 7565 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1092:

/* Line 1806 of yacc.c  */
#line 7575 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1094:

/* Line 1806 of yacc.c  */
#line 7584 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1095:

/* Line 1806 of yacc.c  */
#line 7588 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1096:

/* Line 1806 of yacc.c  */
#line 7595 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7599 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7609 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1100:

/* Line 1806 of yacc.c  */
#line 7617 "parser.y"
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

  case 1101:

/* Line 1806 of yacc.c  */
#line 7632 "parser.y"
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

  case 1102:

/* Line 1806 of yacc.c  */
#line 7649 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1103:

/* Line 1806 of yacc.c  */
#line 7650 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7651 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7652 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1106:

/* Line 1806 of yacc.c  */
#line 7656 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7657 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1108:

/* Line 1806 of yacc.c  */
#line 7662 "parser.y"
    { (yyval) = cb_int (COB_SHARE_ALL); }
    break;

  case 1109:

/* Line 1806 of yacc.c  */
#line 7663 "parser.y"
    { (yyval) = cb_int (COB_SHARE_EXCLUSIVE); }
    break;

  case 1110:

/* Line 1806 of yacc.c  */
#line 7664 "parser.y"
    { (yyval) = cb_int (COB_SHARE_READ_ONLY); }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
#line 7670 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1112:

/* Line 1806 of yacc.c  */
#line 7671 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
#line 7672 "parser.y"
    { (yyval) = cb_int (COB_LOCK_EXCLUSIVE); }
    break;

  case 1114:

/* Line 1806 of yacc.c  */
#line 7674 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1115:

/* Line 1806 of yacc.c  */
#line 7685 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
#line 7696 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1118:

/* Line 1806 of yacc.c  */
#line 7701 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1119:

/* Line 1806 of yacc.c  */
#line 7707 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1120:

/* Line 1806 of yacc.c  */
#line 7712 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1121:

/* Line 1806 of yacc.c  */
#line 7720 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7728 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7735 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7739 "parser.y"
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

  case 1125:

/* Line 1806 of yacc.c  */
#line 7752 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7759 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1127:

/* Line 1806 of yacc.c  */
#line 7770 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
#line 7774 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1129:

/* Line 1806 of yacc.c  */
#line 7779 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1130:

/* Line 1806 of yacc.c  */
#line 7783 "parser.y"
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

  case 1131:

/* Line 1806 of yacc.c  */
#line 7794 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1132:

/* Line 1806 of yacc.c  */
#line 7800 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7801 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1134:

/* Line 1806 of yacc.c  */
#line 7805 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1135:

/* Line 1806 of yacc.c  */
#line 7806 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1136:

/* Line 1806 of yacc.c  */
#line 7809 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7811 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1138:

/* Line 1806 of yacc.c  */
#line 7816 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1139:

/* Line 1806 of yacc.c  */
#line 7826 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1141:

/* Line 1806 of yacc.c  */
#line 7835 "parser.y"
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

  case 1142:

/* Line 1806 of yacc.c  */
#line 7861 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1143:

/* Line 1806 of yacc.c  */
#line 7862 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1144:

/* Line 1806 of yacc.c  */
#line 7867 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7871 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1146:

/* Line 1806 of yacc.c  */
#line 7875 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1147:

/* Line 1806 of yacc.c  */
#line 7879 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1148:

/* Line 1806 of yacc.c  */
#line 7883 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1149:

/* Line 1806 of yacc.c  */
#line 7887 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1150:

/* Line 1806 of yacc.c  */
#line 7891 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 7897 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 7898 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1155:

/* Line 1806 of yacc.c  */
#line 7908 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 7912 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1157:

/* Line 1806 of yacc.c  */
#line 7922 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1158:

/* Line 1806 of yacc.c  */
#line 7932 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 7940 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 7950 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1162:

/* Line 1806 of yacc.c  */
#line 7960 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1164:

/* Line 1806 of yacc.c  */
#line 7969 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 7976 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 7980 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1167:

/* Line 1806 of yacc.c  */
#line 7990 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 8002 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 8010 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1171:

/* Line 1806 of yacc.c  */
#line 8014 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1172:

/* Line 1806 of yacc.c  */
#line 8018 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 8025 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 8029 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 8039 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1176:

/* Line 1806 of yacc.c  */
#line 8050 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1178:

/* Line 1806 of yacc.c  */
#line 8059 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1179:

/* Line 1806 of yacc.c  */
#line 8064 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1180:

/* Line 1806 of yacc.c  */
#line 8071 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1181:

/* Line 1806 of yacc.c  */
#line 8072 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1182:

/* Line 1806 of yacc.c  */
#line 8077 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1183:

/* Line 1806 of yacc.c  */
#line 8082 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1184:

/* Line 1806 of yacc.c  */
#line 8089 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1185:

/* Line 1806 of yacc.c  */
#line 8093 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1186:

/* Line 1806 of yacc.c  */
#line 8101 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1187:

/* Line 1806 of yacc.c  */
#line 8108 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1188:

/* Line 1806 of yacc.c  */
#line 8112 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1189:

/* Line 1806 of yacc.c  */
#line 8122 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1190:

/* Line 1806 of yacc.c  */
#line 8129 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1197:

/* Line 1806 of yacc.c  */
#line 8144 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1198:

/* Line 1806 of yacc.c  */
#line 8145 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1199:

/* Line 1806 of yacc.c  */
#line 8149 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1200:

/* Line 1806 of yacc.c  */
#line 8150 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1201:

/* Line 1806 of yacc.c  */
#line 8157 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1202:

/* Line 1806 of yacc.c  */
#line 8166 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1205:

/* Line 1806 of yacc.c  */
#line 8178 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1206:

/* Line 1806 of yacc.c  */
#line 8182 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1207:

/* Line 1806 of yacc.c  */
#line 8186 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1208:

/* Line 1806 of yacc.c  */
#line 8190 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1209:

/* Line 1806 of yacc.c  */
#line 8194 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1210:

/* Line 1806 of yacc.c  */
#line 8198 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1211:

/* Line 1806 of yacc.c  */
#line 8202 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
#line 8206 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1213:

/* Line 1806 of yacc.c  */
#line 8215 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1214:

/* Line 1806 of yacc.c  */
#line 8219 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
#line 8228 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1218:

/* Line 1806 of yacc.c  */
#line 8242 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1221:

/* Line 1806 of yacc.c  */
#line 8256 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8260 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1223:

/* Line 1806 of yacc.c  */
#line 8270 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1225:

/* Line 1806 of yacc.c  */
#line 8278 "parser.y"
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

  case 1226:

/* Line 1806 of yacc.c  */
#line 8299 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1227:

/* Line 1806 of yacc.c  */
#line 8308 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1228:

/* Line 1806 of yacc.c  */
#line 8313 "parser.y"
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

  case 1229:

/* Line 1806 of yacc.c  */
#line 8331 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1230:

/* Line 1806 of yacc.c  */
#line 8332 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1232:

/* Line 1806 of yacc.c  */
#line 8337 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1233:

/* Line 1806 of yacc.c  */
#line 8344 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1234:

/* Line 1806 of yacc.c  */
#line 8345 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1235:

/* Line 1806 of yacc.c  */
#line 8350 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1236:

/* Line 1806 of yacc.c  */
#line 8356 "parser.y"
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

  case 1237:

/* Line 1806 of yacc.c  */
#line 8366 "parser.y"
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

  case 1238:

/* Line 1806 of yacc.c  */
#line 8381 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8387 "parser.y"
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

  case 1240:

/* Line 1806 of yacc.c  */
#line 8397 "parser.y"
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

  case 1241:

/* Line 1806 of yacc.c  */
#line 8413 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1243:

/* Line 1806 of yacc.c  */
#line 8423 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1244:

/* Line 1806 of yacc.c  */
#line 8435 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1245:

/* Line 1806 of yacc.c  */
#line 8439 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1246:

/* Line 1806 of yacc.c  */
#line 8446 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1247:

/* Line 1806 of yacc.c  */
#line 8450 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1248:

/* Line 1806 of yacc.c  */
#line 8455 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8460 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
#line 8467 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1251:

/* Line 1806 of yacc.c  */
#line 8468 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1252:

/* Line 1806 of yacc.c  */
#line 8469 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
#line 8470 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1254:

/* Line 1806 of yacc.c  */
#line 8471 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1255:

/* Line 1806 of yacc.c  */
#line 8472 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8477 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8490 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8494 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1261:

/* Line 1806 of yacc.c  */
#line 8504 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1262:

/* Line 1806 of yacc.c  */
#line 8508 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8514 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8526 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1265:

/* Line 1806 of yacc.c  */
#line 8530 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8534 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8542 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8553 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1269:

/* Line 1806 of yacc.c  */
#line 8557 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8563 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8564 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8565 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1273:

/* Line 1806 of yacc.c  */
#line 8566 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1274:

/* Line 1806 of yacc.c  */
#line 8573 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8582 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1277:

/* Line 1806 of yacc.c  */
#line 8588 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8589 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8593 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1280:

/* Line 1806 of yacc.c  */
#line 8594 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1281:

/* Line 1806 of yacc.c  */
#line 8595 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1282:

/* Line 1806 of yacc.c  */
#line 8599 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1283:

/* Line 1806 of yacc.c  */
#line 8600 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1284:

/* Line 1806 of yacc.c  */
#line 8605 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1285:

/* Line 1806 of yacc.c  */
#line 8609 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8619 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1288:

/* Line 1806 of yacc.c  */
#line 8628 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1289:

/* Line 1806 of yacc.c  */
#line 8632 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1290:

/* Line 1806 of yacc.c  */
#line 8636 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1291:

/* Line 1806 of yacc.c  */
#line 8643 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1292:

/* Line 1806 of yacc.c  */
#line 8647 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1293:

/* Line 1806 of yacc.c  */
#line 8657 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  }
    break;

  case 1296:

/* Line 1806 of yacc.c  */
#line 8675 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1298:

/* Line 1806 of yacc.c  */
#line 8684 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1299:

/* Line 1806 of yacc.c  */
#line 8690 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1300:

/* Line 1806 of yacc.c  */
#line 8701 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1302:

/* Line 1806 of yacc.c  */
#line 8709 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1303:

/* Line 1806 of yacc.c  */
#line 8722 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8730 "parser.y"
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

  case 1309:

/* Line 1806 of yacc.c  */
#line 8753 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1311:

/* Line 1806 of yacc.c  */
#line 8763 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1312:

/* Line 1806 of yacc.c  */
#line 8769 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1313:

/* Line 1806 of yacc.c  */
#line 8771 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1314:

/* Line 1806 of yacc.c  */
#line 8775 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1315:

/* Line 1806 of yacc.c  */
#line 8777 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1316:

/* Line 1806 of yacc.c  */
#line 8782 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1317:

/* Line 1806 of yacc.c  */
#line 8788 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1318:

/* Line 1806 of yacc.c  */
#line 8790 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1319:

/* Line 1806 of yacc.c  */
#line 8795 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1320:

/* Line 1806 of yacc.c  */
#line 8801 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1321:

/* Line 1806 of yacc.c  */
#line 8802 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1322:

/* Line 1806 of yacc.c  */
#line 8806 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1323:

/* Line 1806 of yacc.c  */
#line 8807 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1324:

/* Line 1806 of yacc.c  */
#line 8811 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1325:

/* Line 1806 of yacc.c  */
#line 8812 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1326:

/* Line 1806 of yacc.c  */
#line 8817 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1327:

/* Line 1806 of yacc.c  */
#line 8821 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1328:

/* Line 1806 of yacc.c  */
#line 8831 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1335:

/* Line 1806 of yacc.c  */
#line 8849 "parser.y"
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

  case 1336:

/* Line 1806 of yacc.c  */
#line 8874 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1337:

/* Line 1806 of yacc.c  */
#line 8878 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1338:

/* Line 1806 of yacc.c  */
#line 8890 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1339:

/* Line 1806 of yacc.c  */
#line 8900 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1340:

/* Line 1806 of yacc.c  */
#line 8905 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1341:

/* Line 1806 of yacc.c  */
#line 8910 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1342:

/* Line 1806 of yacc.c  */
#line 8915 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1343:

/* Line 1806 of yacc.c  */
#line 8923 "parser.y"
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

  case 1346:

/* Line 1806 of yacc.c  */
#line 8966 "parser.y"
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

  case 1347:

/* Line 1806 of yacc.c  */
#line 9006 "parser.y"
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

  case 1348:

/* Line 1806 of yacc.c  */
#line 9016 "parser.y"
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

  case 1353:

/* Line 1806 of yacc.c  */
#line 9046 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("USE AT is invalid in nested program"));
	}
  }
    break;

  case 1354:

/* Line 1806 of yacc.c  */
#line 9055 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM START"));
	/* emit_entry ("_START", 0, NULL); */
	PENDING ("USE AT PROGRAM START");
  }
    break;

  case 1355:

/* Line 1806 of yacc.c  */
#line 9061 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM END"));
	/* emit_entry ("_END", 0, NULL); */
	PENDING ("USE AT PROGRAM END");
  }
    break;

  case 1356:

/* Line 1806 of yacc.c  */
#line 9071 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1357:

/* Line 1806 of yacc.c  */
#line 9080 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1360:

/* Line 1806 of yacc.c  */
#line 9096 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1362:

/* Line 1806 of yacc.c  */
#line 9108 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1363:

/* Line 1806 of yacc.c  */
#line 9117 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1364:

/* Line 1806 of yacc.c  */
#line 9118 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1365:

/* Line 1806 of yacc.c  */
#line 9123 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1366:

/* Line 1806 of yacc.c  */
#line 9127 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1367:

/* Line 1806 of yacc.c  */
#line 9131 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1368:

/* Line 1806 of yacc.c  */
#line 9135 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1369:

/* Line 1806 of yacc.c  */
#line 9141 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1370:

/* Line 1806 of yacc.c  */
#line 9142 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1373:

/* Line 1806 of yacc.c  */
#line 9152 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1374:

/* Line 1806 of yacc.c  */
#line 9156 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1377:

/* Line 1806 of yacc.c  */
#line 9173 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1379:

/* Line 1806 of yacc.c  */
#line 9183 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1382:

/* Line 1806 of yacc.c  */
#line 9196 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1384:

/* Line 1806 of yacc.c  */
#line 9206 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1387:

/* Line 1806 of yacc.c  */
#line 9221 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1389:

/* Line 1806 of yacc.c  */
#line 9231 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1392:

/* Line 1806 of yacc.c  */
#line 9248 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1394:

/* Line 1806 of yacc.c  */
#line 9259 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1400:

/* Line 1806 of yacc.c  */
#line 9282 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1401:

/* Line 1806 of yacc.c  */
#line 9291 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1405:

/* Line 1806 of yacc.c  */
#line 9308 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9317 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1409:

/* Line 1806 of yacc.c  */
#line 9334 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1411:

/* Line 1806 of yacc.c  */
#line 9344 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1412:

/* Line 1806 of yacc.c  */
#line 9354 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1413:

/* Line 1806 of yacc.c  */
#line 9358 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1414:

/* Line 1806 of yacc.c  */
#line 9368 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9375 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9381 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9385 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1421:

/* Line 1806 of yacc.c  */
#line 9398 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9406 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9407 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9409 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9410 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9411 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1427:

/* Line 1806 of yacc.c  */
#line 9412 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1428:

/* Line 1806 of yacc.c  */
#line 9413 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1429:

/* Line 1806 of yacc.c  */
#line 9415 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1430:

/* Line 1806 of yacc.c  */
#line 9416 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1431:

/* Line 1806 of yacc.c  */
#line 9417 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1432:

/* Line 1806 of yacc.c  */
#line 9418 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1433:

/* Line 1806 of yacc.c  */
#line 9419 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1434:

/* Line 1806 of yacc.c  */
#line 9420 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1435:

/* Line 1806 of yacc.c  */
#line 9422 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1436:

/* Line 1806 of yacc.c  */
#line 9423 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1437:

/* Line 1806 of yacc.c  */
#line 9424 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1438:

/* Line 1806 of yacc.c  */
#line 9426 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1439:

/* Line 1806 of yacc.c  */
#line 9427 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1440:

/* Line 1806 of yacc.c  */
#line 9428 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1441:

/* Line 1806 of yacc.c  */
#line 9429 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1442:

/* Line 1806 of yacc.c  */
#line 9430 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1443:

/* Line 1806 of yacc.c  */
#line 9433 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1444:

/* Line 1806 of yacc.c  */
#line 9434 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1453:

/* Line 1806 of yacc.c  */
#line 9464 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9468 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1458:

/* Line 1806 of yacc.c  */
#line 9479 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1459:

/* Line 1806 of yacc.c  */
#line 9480 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1460:

/* Line 1806 of yacc.c  */
#line 9481 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9485 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1462:

/* Line 1806 of yacc.c  */
#line 9486 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9487 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1464:

/* Line 1806 of yacc.c  */
#line 9492 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1465:

/* Line 1806 of yacc.c  */
#line 9495 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1466:

/* Line 1806 of yacc.c  */
#line 9499 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1467:

/* Line 1806 of yacc.c  */
#line 9500 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1468:

/* Line 1806 of yacc.c  */
#line 9501 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1469:

/* Line 1806 of yacc.c  */
#line 9504 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1470:

/* Line 1806 of yacc.c  */
#line 9505 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9516 "parser.y"
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

  case 1472:

/* Line 1806 of yacc.c  */
#line 9528 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1473:

/* Line 1806 of yacc.c  */
#line 9537 "parser.y"
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

  case 1474:

/* Line 1806 of yacc.c  */
#line 9549 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1475:

/* Line 1806 of yacc.c  */
#line 9558 "parser.y"
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

  case 1476:

/* Line 1806 of yacc.c  */
#line 9570 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1477:

/* Line 1806 of yacc.c  */
#line 9584 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1478:

/* Line 1806 of yacc.c  */
#line 9586 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9591 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9599 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9606 "parser.y"
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

  case 1482:

/* Line 1806 of yacc.c  */
#line 9626 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1483:

/* Line 1806 of yacc.c  */
#line 9630 "parser.y"
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

  case 1484:

/* Line 1806 of yacc.c  */
#line 9651 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1485:

/* Line 1806 of yacc.c  */
#line 9692 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1486:

/* Line 1806 of yacc.c  */
#line 9705 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1487:

/* Line 1806 of yacc.c  */
#line 9707 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9711 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1489:

/* Line 1806 of yacc.c  */
#line 9717 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1490:

/* Line 1806 of yacc.c  */
#line 9719 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1491:

/* Line 1806 of yacc.c  */
#line 9724 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1494:

/* Line 1806 of yacc.c  */
#line 9738 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9745 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1496:

/* Line 1806 of yacc.c  */
#line 9755 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1497:

/* Line 1806 of yacc.c  */
#line 9756 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1498:

/* Line 1806 of yacc.c  */
#line 9761 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1499:

/* Line 1806 of yacc.c  */
#line 9769 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1500:

/* Line 1806 of yacc.c  */
#line 9777 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9781 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1502:

/* Line 1806 of yacc.c  */
#line 9788 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9798 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_is_key = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1506:

/* Line 1806 of yacc.c  */
#line 9814 "parser.y"
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
#line 9828 "parser.y"
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
#line 9845 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1509:

/* Line 1806 of yacc.c  */
#line 9849 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1512:

/* Line 1806 of yacc.c  */
#line 9858 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1513:

/* Line 1806 of yacc.c  */
#line 9865 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1514:

/* Line 1806 of yacc.c  */
#line 9869 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1519:

/* Line 1806 of yacc.c  */
#line 9880 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1520:

/* Line 1806 of yacc.c  */
#line 9884 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1521:

/* Line 1806 of yacc.c  */
#line 9888 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1522:

/* Line 1806 of yacc.c  */
#line 9892 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1523:

/* Line 1806 of yacc.c  */
#line 9896 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1524:

/* Line 1806 of yacc.c  */
#line 9900 "parser.y"
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
#line 9921 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1526:

/* Line 1806 of yacc.c  */
#line 9925 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1534:

/* Line 1806 of yacc.c  */
#line 9942 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1535:

/* Line 1806 of yacc.c  */
#line 9946 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1536:

/* Line 1806 of yacc.c  */
#line 9950 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1552:

/* Line 1806 of yacc.c  */
#line 9997 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1560:

/* Line 1806 of yacc.c  */
#line 10021 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1561:

/* Line 1806 of yacc.c  */
#line 10025 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1562:

/* Line 1806 of yacc.c  */
#line 10029 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1563:

/* Line 1806 of yacc.c  */
#line 10030 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1564:

/* Line 1806 of yacc.c  */
#line 10034 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1565:

/* Line 1806 of yacc.c  */
#line 10039 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1566:

/* Line 1806 of yacc.c  */
#line 10046 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1567:

/* Line 1806 of yacc.c  */
#line 10053 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1568:

/* Line 1806 of yacc.c  */
#line 10060 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1569:

/* Line 1806 of yacc.c  */
#line 10070 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1570:

/* Line 1806 of yacc.c  */
#line 10077 "parser.y"
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

  case 1571:

/* Line 1806 of yacc.c  */
#line 10087 "parser.y"
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

  case 1572:

/* Line 1806 of yacc.c  */
#line 10097 "parser.y"
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
#line 10107 "parser.y"
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

  case 1574:

/* Line 1806 of yacc.c  */
#line 10120 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1575:

/* Line 1806 of yacc.c  */
#line 10124 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1576:

/* Line 1806 of yacc.c  */
#line 10132 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1577:

/* Line 1806 of yacc.c  */
#line 10140 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 10144 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 10154 "parser.y"
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

  case 1580:

/* Line 1806 of yacc.c  */
#line 10169 "parser.y"
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

  case 1581:

/* Line 1806 of yacc.c  */
#line 10192 "parser.y"
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

  case 1582:

/* Line 1806 of yacc.c  */
#line 10215 "parser.y"
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

  case 1583:

/* Line 1806 of yacc.c  */
#line 10230 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1584:

/* Line 1806 of yacc.c  */
#line 10231 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1585:

/* Line 1806 of yacc.c  */
#line 10232 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 10233 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 10234 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 10235 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10240 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10244 "parser.y"
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

  case 1591:

/* Line 1806 of yacc.c  */
#line 10261 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1592:

/* Line 1806 of yacc.c  */
#line 10265 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1593:

/* Line 1806 of yacc.c  */
#line 10271 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1594:

/* Line 1806 of yacc.c  */
#line 10272 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1595:

/* Line 1806 of yacc.c  */
#line 10273 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1596:

/* Line 1806 of yacc.c  */
#line 10274 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1597:

/* Line 1806 of yacc.c  */
#line 10275 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1598:

/* Line 1806 of yacc.c  */
#line 10276 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1599:

/* Line 1806 of yacc.c  */
#line 10277 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1600:

/* Line 1806 of yacc.c  */
#line 10284 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1601:

/* Line 1806 of yacc.c  */
#line 10288 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1602:

/* Line 1806 of yacc.c  */
#line 10292 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1603:

/* Line 1806 of yacc.c  */
#line 10296 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1604:

/* Line 1806 of yacc.c  */
#line 10300 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1605:

/* Line 1806 of yacc.c  */
#line 10304 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1606:

/* Line 1806 of yacc.c  */
#line 10308 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1607:

/* Line 1806 of yacc.c  */
#line 10312 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1608:

/* Line 1806 of yacc.c  */
#line 10316 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1609:

/* Line 1806 of yacc.c  */
#line 10320 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1618:

/* Line 1806 of yacc.c  */
#line 10344 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10348 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10352 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10359 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10363 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10367 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10374 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10381 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10388 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10398 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10405 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10415 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10422 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10433 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10441 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10442 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1634:

/* Line 1806 of yacc.c  */
#line 10446 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10447 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10449 "parser.y"
    {
	check_relaxed_syntax_opt ("NO DUPLICATES", 0);
	(yyval) = cb_int0;
}
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10456 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10457 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10462 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10466 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10473 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10477 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10484 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10485 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1645:

/* Line 1806 of yacc.c  */
#line 10486 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1646:

/* Line 1806 of yacc.c  */
#line 10490 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1647:

/* Line 1806 of yacc.c  */
#line 10491 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1648:

/* Line 1806 of yacc.c  */
#line 10495 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1649:

/* Line 1806 of yacc.c  */
#line 10496 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1650:

/* Line 1806 of yacc.c  */
#line 10497 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1651:

/* Line 1806 of yacc.c  */
#line 10502 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1652:

/* Line 1806 of yacc.c  */
#line 10506 "parser.y"
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
#line 10518 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1654:

/* Line 1806 of yacc.c  */
#line 10523 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1655:

/* Line 1806 of yacc.c  */
#line 10531 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1656:

/* Line 1806 of yacc.c  */
#line 10535 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1657:

/* Line 1806 of yacc.c  */
#line 10539 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1658:

/* Line 1806 of yacc.c  */
#line 10543 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1659:

/* Line 1806 of yacc.c  */
#line 10547 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1660:

/* Line 1806 of yacc.c  */
#line 10551 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1661:

/* Line 1806 of yacc.c  */
#line 10555 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1662:

/* Line 1806 of yacc.c  */
#line 10559 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1663:

/* Line 1806 of yacc.c  */
#line 10565 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1664:

/* Line 1806 of yacc.c  */
#line 10566 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1851:

/* Line 1806 of yacc.c  */
#line 10706 "parser.y"
    {
	check_relaxed_syntax_opt ("RECORD", 1);
  }
    break;



/* Line 1806 of yacc.c  */
#line 18723 "parser.c"
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
#line 10748 "parser.y"


