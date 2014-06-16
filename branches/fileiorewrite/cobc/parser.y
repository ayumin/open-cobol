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

%expect 0

%defines
%verbose
%error-verbose

%{
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

%}

%token TOKEN_EOF 0 "end of file"

%token ACCEPT
%token ACCESS
%token ADD
%token ADDRESS
%token ADVANCING
%token AFTER
%token ALL
%token ALLOCATE
%token ALPHABET
%token ALPHABETIC
%token ALPHABETIC_LOWER		"ALPHABETIC-LOWER"
%token ALPHABETIC_UPPER		"ALPHABETIC-UPPER"
%token ALPHANUMERIC
%token ALPHANUMERIC_EDITED	"ALPHANUMERIC-EDITED"
%token ALSO
%token ALTER
%token ALTERNATE
%token AND
%token ANY
%token ARE
%token AREA
%token ARGUMENT_NUMBER		"ARGUMENT-NUMBER"
%token ARGUMENT_VALUE		"ARGUMENT-VALUE"
%token AS
%token ASCENDING
%token ASCII
%token ASSIGN
%token AT
%token ATTRIBUTE
%token AUTO
%token AUTOMATIC
%token AWAY_FROM_ZERO		"AWAY-FROM-ZERO"
%token BACKGROUND_COLOR		"BACKGROUND-COLOR"
%token BASED
%token BEFORE
%token BELL
%token BINARY
%token BINARY_C_LONG		"BINARY-C-LONG"
%token BINARY_CHAR		"BINARY-CHAR"
%token BINARY_DOUBLE		"BINARY-DOUBLE"
%token BINARY_LONG		"BINARY-LONG"
%token BINARY_SHORT		"BINARY-SHORT"
%token BLANK
%token BLINK
%token BLOCK
%token BOTTOM
%token BY
%token BYTE_LENGTH		"BYTE-LENGTH"
%token CALL
%token CANCEL
%token CF
%token CH
%token CHAINING
%token CHARACTER
%token CHARACTERS
%token CLASS
%token CLASSIFICATION
%token CLOSE
%token CODE
%token CODE_SET			"CODE-SET"
%token COLLATING
%token COL
%token COLS
%token COLUMN
%token COLUMNS
%token COMMA
%token COMMAND_LINE		"COMMAND-LINE"
%token COMMA_DELIM		"comma delimiter"
%token COMMIT
%token COMMON
%token COMP
%token COMPUTE
%token COMP_1			"COMP-1"
%token COMP_2			"COMP-2"
%token COMP_3			"COMP-3"
%token COMP_4			"COMP-4"
%token COMP_5			"COMP-5"
%token COMP_6			"COMP-6"
%token COMP_X			"COMP-X"
%token CONCATENATE_FUNC		"FUNCTION CONCATENATE"
%token CONDITION
%token CONFIGURATION
%token CONSTANT
%token CONTAINS
%token CONTENT
%token CONTINUE
%token CONTROL
%token CONTROLS
%token CONVERSION
%token CONVERTING
%token COPY
%token CORRESPONDING
%token COUNT
%token CRT
%token CRT_UNDER		"CRT-UNDER"
%token CURRENCY
%token CURRENT_DATE_FUNC	"FUNCTION CURRENT-DATE"
%token CURSOR
%token CYCLE
%token DATA
%token DATE
%token DAY
%token DAY_OF_WEEK		"DAY-OF-WEEK"
%token DE
%token DEBUGGING
%token DECIMAL_POINT		"DECIMAL-POINT"
%token DECLARATIVES
%token DEFAULT
%token DELETE
%token DELIMITED
%token DELIMITER
%token DEPENDING
%token DESCENDING
%token DETAIL
%token DISC
%token DISK
%token DISPLAY
%token DISPLAY_OF_FUNC		"FUNCTION DISPLAY-OF"
%token DIVIDE
%token DIVISION
%token DOWN
%token DUPLICATES
%token DYNAMIC
%token EBCDIC
%token EC
%token ELSE
%token END
%token END_ACCEPT		"END-ACCEPT"
%token END_ADD			"END-ADD"
%token END_CALL			"END-CALL"
%token END_COMPUTE		"END-COMPUTE"
%token END_DELETE		"END-DELETE"
%token END_DISPLAY		"END-DISPLAY"
%token END_DIVIDE		"END-DIVIDE"
%token END_EVALUATE		"END-EVALUATE"
%token END_FUNCTION		"END FUNCTION"
%token END_IF			"END-IF"
%token END_MULTIPLY		"END-MULTIPLY"
%token END_PERFORM		"END-PERFORM"
%token END_PROGRAM		"END PROGRAM"
%token END_READ			"END-READ"
%token END_RETURN		"END-RETURN"
%token END_REWRITE		"END-REWRITE"
%token END_SEARCH		"END-SEARCH"
%token END_START		"END-START"
%token END_STRING		"END-STRING"
%token END_SUBTRACT		"END-SUBTRACT"
%token END_UNSTRING		"END-UNSTRING"
%token END_WRITE		"END-WRITE"
%token ENTRY
%token ENVIRONMENT
%token ENVIRONMENT_NAME		"ENVIRONMENT-NAME"
%token ENVIRONMENT_VALUE	"ENVIRONMENT-VALUE"
%token EOL
%token EOP
%token EOS
%token EQUAL
%token ERASE
%token ERROR
%token ESCAPE
%token EVALUATE
%token EVENT_STATUS		"EVENT STATUS"
%token EXCEPTION
%token EXCEPTION_CONDITION	"EXCEPTION CONDITION"
%token EXCLUSIVE
%token EXIT
%token EXPONENTIATION		"Exponentiation operator"
%token EXTEND
%token EXTERNAL
%token FD
%token FILE_CONTROL		"FILE-CONTROL"
%token FILE_ID			"FILE-ID"
%token FILLER
%token FINAL
%token FIRST
%token FLOAT_BINARY_128		"FLOAT-BINARY-128"
%token FLOAT_BINARY_32		"FLOAT-BINARY-32"
%token FLOAT_BINARY_64		"FLOAT-BINARY-64"
%token FLOAT_DECIMAL_16		"FLOAT-DECIMAL-16"
%token FLOAT_DECIMAL_34		"FLOAT-DECIMAL-34"
%token FLOAT_DECIMAL_7		"FLOAT-DECIMAL-7"
%token FLOAT_EXTENDED		"FLOAT-EXTENDED"
%token FLOAT_LONG		"FLOAT-LONG"
%token FLOAT_SHORT		"FLOAT-SHORT"
%token FOOTING
%token FOR
%token FOREGROUND_COLOR		"FOREGROUND-COLOR"
%token FOREVER
%token FORMATTED_CURRENT_FUNC	"FUNCTION FORMATTED-CURRENT-DATE"
%token FORMATTED_DATE_FUNC	"FUNCTION FORMATTED-DATE"
%token FORMATTED_DATETIME_FUNC	"FUNCTION FORMATTED-DATETIME"
%token FORMATTED_TIME_FUNC	"FUNCTION FORMATTED-TIME"
%token FREE
%token FROM
%token FROM_CRT			"FROM CRT"
%token FULL
%token FUNCTION
%token FUNCTION_ID		"FUNCTION-ID"
%token FUNCTION_NAME		"FUNCTION"
%token GENERATE
%token GIVING
%token GLOBAL
%token GO
%token GOBACK
%token GREATER
%token GREATER_OR_EQUAL		"GREATER OR EQUAL"
%token GROUP
%token HEADING
%token HIGHLIGHT
%token HIGH_VALUE		"HIGH-VALUE"
%token ID
%token IDENTIFICATION
%token IF
%token IGNORE
%token IGNORING
%token IN
%token INDEX
%token INDEXED
%token INDICATE
%token INITIALIZE
%token INITIALIZED
%token INITIATE
%token INPUT
%token INPUT_OUTPUT		"INPUT-OUTPUT"
%token INSPECT
%token INTO
%token INTRINSIC
%token INVALID
%token INVALID_KEY		"INVALID KEY"
%token IS
%token I_O			"I-O"
%token I_O_CONTROL		"I-O-CONTROL"
%token JUSTIFIED
%token KEPT
%token KEY
%token KEYBOARD
%token LABEL
%token LAST
%token LEADING
%token LEFT
%token LEFTLINE
%token LENGTH
%token LENGTH_OF		"LENGTH OF"
%token LESS
%token LESS_OR_EQUAL		"LESS OR EQUAL"
%token LIMIT
%token LIMITS
%token LINAGE
%token LINAGE_COUNTER		"LINAGE-COUNTER"
%token LINE
%token LINE_COUNTER		"LINE-COUNTER"
%token LINES
%token LINKAGE
%token LITERAL			"Literal"
%token LOCALE
%token LOCALE_DATE_FUNC		"FUNCTION LOCALE-DATE"
%token LOCALE_TIME_FUNC		"FUNCTION LOCALE-TIME"
%token LOCALE_TIME_FROM_FUNC	"FUNCTION LOCALE-TIME-FROM-SECONDS"
%token LOCAL_STORAGE		"LOCAL-STORAGE"
%token LOCK
%token LOWER
%token LOWER_CASE_FUNC		"FUNCTION LOWER-CASE"
%token LOWLIGHT
%token LOW_VALUE		"LOW-VALUE"
%token MANUAL
%token MEMORY
%token MERGE
%token MINUS
%token MNEMONIC_NAME		"MNEMONIC NAME"
%token MODE
%token MOVE
%token MULTIPLE
%token MULTIPLY
%token NAME
%token NATIONAL
%token NATIONAL_EDITED		"NATIONAL-EDITED"
%token NATIONAL_OF_FUNC		"FUNCTION NATIONAL-OF"
%token NATIVE
%token NEAREST_AWAY_FROM_ZERO	"NEAREST-AWAY-FROM-ZERO"
%token NEAREST_EVEN		"NEAREST-EVEN"
%token NEAREST_TOWARD_ZERO	"NEAREST-TOWARD-ZERO"
%token NEGATIVE
%token NEXT
%token NEXT_PAGE		"NEXT PAGE"
%token NO
%token NO_ECHO			"NO-ECHO"
%token NORMAL
%token NOT
%token NOT_END			"NOT END"
%token NOT_EOP			"NOT EOP"
%token NOT_EQUAL		"NOT EQUAL"
%token NOT_EXCEPTION		"NOT EXCEPTION"
%token NOT_INVALID_KEY		"NOT INVALID KEY"
%token NOT_OVERFLOW		"NOT OVERFLOW"
%token NOT_SIZE_ERROR		"NOT SIZE ERROR"
%token NO_ADVANCING		"NO ADVANCING"
%token NUMBER
%token NUMBERS
%token NUMERIC
%token NUMERIC_EDITED		"NUMERIC-EDITED"
%token NUMVALC_FUNC		"FUNCTION NUMVAL-C"
%token OBJECT_COMPUTER		"OBJECT-COMPUTER"
%token OCCURS
%token OF
%token OFF
%token OMITTED
%token ON
%token ONLY
%token OPEN
%token OPTIONAL
%token OR
%token ORDER
%token ORGANIZATION
%token OTHER
%token OUTPUT
%token OVERLINE
%token PACKED_DECIMAL		"PACKED-DECIMAL"
%token PADDING
%token PAGE
%token PAGE_COUNTER		"PAGE-COUNTER"
%token PARAGRAPH
%token PERFORM
%token PH
%token PF
%token PICTURE
%token PICTURE_SYMBOL		"PICTURE SYMBOL"
%token PLUS
%token POINTER
%token POSITION
%token POSITIVE
%token PRESENT
%token PREVIOUS
%token PRINTER
%token PRINTING
%token PROCEDURE
%token PROCEDURES
%token PROCEED
%token PROGRAM
%token PROGRAM_ID		"PROGRAM-ID"
%token PROGRAM_NAME		"Program name"
%token PROGRAM_POINTER		"PROGRAM-POINTER"
%token PROHIBITED
%token PROMPT
%token QUOTE
%token RANDOM
%token RD
%token READ
%token READY_TRACE		"READY TRACE"
%token RECORD
%token RECORDING
%token RECORDS
%token RECURSIVE
%token REDEFINES
%token REEL
%token REFERENCE
%token REFERENCES
%token RELATIVE
%token RELEASE
%token REMAINDER
%token REMOVAL
%token RENAMES
%token REPLACE
%token REPLACING
%token REPORT
%token REPORTING
%token REPORTS
%token REPOSITORY
%token REPO_FUNCTION		"Intrinsic function name"
%token REQUIRED
%token RESERVE
%token RESET
%token RESET_TRACE		"RESET TRACE"
%token RETURN
%token RETURNING
%token REVERSE_FUNC		"FUNCTION REVERSE"
%token REVERSE_VIDEO		"REVERSE-VIDEO"
%token REVERSED
%token REWIND
%token REWRITE
%token RF
%token RH
%token RIGHT
%token ROLLBACK
%token ROUNDED
%token RUN
%token SAME
%token SCREEN
%token SCREEN_CONTROL		"SCREEN-CONTROL"
%token SCROLL
%token SD
%token SEARCH
%token SECTION
%token SECURE
%token SEGMENT_LIMIT		"SEGMENT-LIMIT"
%token SELECT
%token SEMI_COLON		"semi-colon"
%token SENTENCE
%token SEPARATE
%token SEQUENCE
%token SEQUENTIAL
%token SET
%token SHARING
%token SIGN
%token SIGNED
%token SIGNED_INT		"SIGNED-INT"
%token SIGNED_LONG		"SIGNED-LONG"
%token SIGNED_SHORT		"SIGNED-SHORT"
%token SIZE
%token SIZE_ERROR		"SIZE ERROR"
%token SORT
%token SORT_MERGE		"SORT-MERGE"
%token SOURCE
%token SOURCE_COMPUTER		"SOURCE-COMPUTER"
%token SPACE
%token SPECIAL_NAMES		"SPECIAL-NAMES"
%token STANDARD
%token STANDARD_1		"STANDARD-1"
%token STANDARD_2		"STANDARD-2"
%token START
%token STATIC
%token STATUS
%token STDCALL
%token STEP
%token STOP
%token STRING
%token SUBSTITUTE_FUNC		"FUNCTION SUBSTITUTE"
%token SUBSTITUTE_CASE_FUNC	"FUNCTION SUBSTITUTE-CASE"
%token SUBTRACT
%token SUM
%token SUPPRESS
%token SYMBOLIC
%token SYNCHRONIZED
%token SYSTEM_DEFAULT		"SYSTEM-DEFAULT"
%token TALLYING
%token TAPE
%token TERMINATE
%token TEST
%token THAN
%token THEN
%token THRU
%token TIME
%token TIMEOUT
%token TIMES
%token TO
%token TOK_AMPER		"&"
%token TOK_CLOSE_PAREN		")"
%token TOK_COLON		":"
%token TOK_DIV			"/"
%token TOK_DOT			"."
%token TOK_EQUAL		"="
%token TOK_FALSE		"FALSE"
%token TOK_FILE			"FILE"
%token TOK_GREATER		">"
%token TOK_INITIAL		"INITIAL"
%token TOK_LESS			"<"
%token TOK_MINUS		"-"
%token TOK_MUL			"*"
%token TOK_NULL			"NULL"
%token TOK_OVERFLOW		"OVERFLOW"
%token TOK_OPEN_PAREN		"("
%token TOK_PLUS			"+"
%token TOK_TRUE			"TRUE"
%token TOP
%token TOWARD_GREATER		"TOWARD-GREATER"
%token TOWARD_LESSER		"TOWARD-LESSER"
%token TRAILING
%token TRANSFORM
%token TRIM_FUNC		"FUNCTION TRIM"
%token TRUNCATION
%token TYPE
%token UNDERLINE
%token UNIT
%token UNLOCK
%token UNSIGNED
%token UNSIGNED_INT		"UNSIGNED-INT"
%token UNSIGNED_LONG		"UNSIGNED-LONG"
%token UNSIGNED_SHORT		"UNSIGNED-SHORT"
%token UNSTRING
%token UNTIL
%token UP
%token UPDATE
%token UPON
%token UPON_ARGUMENT_NUMBER	"UPON ARGUMENT-NUMBER"
%token UPON_COMMAND_LINE	"UPON COMMAND-LINE"
%token UPON_ENVIRONMENT_NAME	"UPON ENVIRONMENT-NAME"
%token UPON_ENVIRONMENT_VALUE	"UPON ENVIRONMENT-VALUE"
%token UPPER
%token UPPER_CASE_FUNC		"FUNCTION UPPER-CASE"
%token USAGE
%token USE
%token USER
%token USER_DEFAULT		"USER-DEFAULT"
%token USER_FUNCTION_NAME	"User FUNCTION"
%token USER_REPO_FUNCTION	"User FUNCTION name"
%token USING
%token VALUE
%token VARYING
%token WAIT
%token WHEN
%token WHEN_COMPILED_FUNC	"FUNCTION WHEN-COMPILED"
%token WITH
%token WORD			"Identifier"
%token WORDS
%token WORKING_STORAGE		"WORKING-STORAGE"
%token WRITE
%token YYYYDDD
%token YYYYMMDD
%token ZERO

/* Set up precedence operators to force shift */

%nonassoc SHIFT_PREFER

%nonassoc ELSE

%nonassoc ACCEPT
%nonassoc ADD
%nonassoc ALLOCATE
%nonassoc ALTER
%nonassoc CALL
%nonassoc CANCEL
%nonassoc CLOSE
%nonassoc COMMIT
%nonassoc COMPUTE
%nonassoc CONTINUE
%nonassoc DELETE
%nonassoc DISPLAY
%nonassoc DIVIDE
%nonassoc ENTRY
%nonassoc EVALUATE
%nonassoc EXIT
%nonassoc FREE
%nonassoc GENERATE
%nonassoc GO
%nonassoc GOBACK
%nonassoc IF
%nonassoc INITIALIZE
%nonassoc INITIATE
%nonassoc INSPECT
%nonassoc MERGE
%nonassoc MOVE
%nonassoc MULTIPLY
%nonassoc NEXT
%nonassoc OPEN
%nonassoc PERFORM
%nonassoc READ
%nonassoc READY_TRACE
%nonassoc RELEASE
%nonassoc RESET_TRACE
%nonassoc RETURN
%nonassoc REWRITE
%nonassoc ROLLBACK
%nonassoc SEARCH
%nonassoc SET
%nonassoc SORT
%nonassoc START
%nonassoc STOP
%nonassoc STRING
%nonassoc SUBTRACT
%nonassoc SUPPRESS
%nonassoc TERMINATE
%nonassoc TRANSFORM
%nonassoc UNLOCK
%nonassoc UNSTRING
%nonassoc WRITE

%nonassoc NOT_END
%nonassoc NOT_EOP
%nonassoc NOT_INVALID_KEY
%nonassoc NOT_OVERFLOW
%nonassoc NOT_SIZE_ERROR
%nonassoc NOT_EXCEPTION

%nonassoc END_ACCEPT
%nonassoc END_ADD
%nonassoc END_CALL
%nonassoc END_COMPUTE
%nonassoc END_DELETE
%nonassoc END_DISPLAY
%nonassoc END_DIVIDE
%nonassoc END_EVALUATE
%nonassoc END_FUNCTION
%nonassoc END_IF
%nonassoc END_MULTIPLY
%nonassoc END_PERFORM
%nonassoc END_PROGRAM
%nonassoc END_READ
%nonassoc END_RETURN
%nonassoc END_REWRITE
%nonassoc END_SEARCH
%nonassoc END_START
%nonassoc END_STRING
%nonassoc END_SUBTRACT
%nonassoc END_UNSTRING
%nonassoc END_WRITE

%nonassoc PROGRAM_ID
%nonassoc WHEN
%nonassoc IN

%nonassoc WORD
%nonassoc LITERAL

%nonassoc TOK_OPEN_PAREN
%nonassoc TOK_PLUS
%nonassoc TOK_MINUS
%nonassoc TOK_DOT

%nonassoc error

%%

/* COBOL Compilation Unit */

start:
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
  nested_list
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
;

nested_list:
  simple_prog
| nested_progs
;

nested_progs:
  source_element
| nested_progs source_element
;

source_element:
  program_definition
| function_definition
;

simple_prog:
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
  program_body
;

program_definition:
  program_identification
  program_body
  nested_prog
  end_program
;

program_mandatory:
  program_identification
  program_body
  nested_prog
  end_mandatory
;

function_definition:
  function_identification
  program_body
  end_function
;

nested_prog:
  %prec SHIFT_PREFER
| program_mandatory
| nested_prog program_mandatory
;

end_program:
  %prec SHIFT_PREFER
| end_mandatory
;

end_mandatory:
  END_PROGRAM program_name TOK_DOT
  {
	char	*s;

	if (CB_LITERAL_P ($2)) {
		s = (char *)(CB_LITERAL ($2)->data);
	} else {
		s = (char *)(CB_NAME ($2));
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
;

end_function:
  %prec SHIFT_PREFER
| end_function_mandatory
;

end_function_mandatory:
  END_FUNCTION program_name TOK_DOT
  {
	char	*s;

	if (CB_LITERAL_P ($2)) {
		s = (char *)(CB_LITERAL ($2)->data);
	} else {
		s = (char *)(CB_NAME ($2));
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
;

/* PROGRAM body */

program_body:
  environment_header
  configuration_header
  configuration_list
  input_output_header
  file_control_header
  file_control_sequence
  i_o_control_header
  opt_i_o_control
  {
	cb_validate_program_environment (current_program);
  }
  data_division_header
  file_section_header
  file_description_sequence
  {
	current_storage = CB_STORAGE_WORKING;
  }
  working_storage_section
/* RXWRXW - W/S
  working_storage_header
  working_storage_records
*/
  local_storage_section
  linkage_section
  report_section
  screen_section
  {
	cb_validate_program_data (current_program);
  }
  procedure_division
;

/* IDENTIFICATION DIVISION */

program_identification:
  PROGRAM_ID TOK_DOT program_name as_literal
  {
	current_section = NULL;
	current_paragraph = NULL;
	if (CB_LITERAL_P ($3)) {
		stack_progid[depth] = (char *)(CB_LITERAL ($3)->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME ($3));
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
	current_program->program_id = cb_build_program_id ($3, $4, 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if (!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = !!cobc_flag_main;
	}
  }
  program_type TOK_DOT
  {
	cobc_cs_check = 0;
  }
;

function_identification:
  FUNCTION_ID TOK_DOT program_name as_literal TOK_DOT
  {
#if	0	/* RXWRXW - FUNCTION-ID */
	cb_error (_("FUNCTION-ID is not yet implemented"));
#endif
	current_section = NULL;
	current_paragraph = NULL;
	if (CB_LITERAL_P ($3)) {
		stack_progid[depth] = (char *)(CB_LITERAL ($3)->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME ($3));
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
	current_program->program_id = cb_build_program_id ($3, $4, 1);
	current_program->prog_type = CB_FUNCTION_TYPE;
	current_program->flag_recursive = 1;
	cobc_cs_check = 0;
  }
;

program_name:
  PROGRAM_NAME
| LITERAL
;

as_literal:
  /* empty */			{ $$ = NULL; }
| AS LITERAL			{ $$ = $2; }
;

program_type:
| _is program_type_clause _program
;

program_type_clause:
  COMMON
  {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  }
| COMMON _init_or_recurs
  {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  }
| _init_or_recurs
| EXTERNAL
;

_init_or_recurs:
  TOK_INITIAL
  {
	current_program->flag_initial = 1;
  }
| RECURSIVE
  {
	current_program->flag_recursive = 1;
  }
;


/* ENVIRONMENT DIVISION */

environment_header:
| ENVIRONMENT DIVISION TOK_DOT
  {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
;

/* CONFIGURATION SECTION */

configuration_header:
| CONFIGURATION SECTION TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if (current_program->nested_level) {
		cb_error (_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  }
;

configuration_list:
| configuration_list configuration_paragraph
;

configuration_paragraph:
  source_computer_paragraph
| object_computer_paragraph
| special_names_paragraph
| special_names_entry
| repository_paragraph
;

/* SOURCE-COMPUTER paragraph */

source_computer_paragraph:
  SOURCE_COMPUTER TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("SOURCE-COMPUTER", SYN_CLAUSE_1);
	if (warningopt && (check_comp_duplicate & SYN_CLAUSE_2)) {
		cb_warning (_("Phrases in non-standard order"));
	}
  }
  source_computer_entry
;

source_computer_entry:
  %prec SHIFT_PREFER
| computer_words with_debugging_mode TOK_DOT
;

with_debugging_mode:
| _with DEBUGGING MODE
  {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item ();
  }
;

/* OBJECT-COMPUTER paragraph */

object_computer_paragraph:
  OBJECT_COMPUTER TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
  object_computer_entry
;

object_computer_entry:
  %prec SHIFT_PREFER
| computer_words TOK_DOT
| computer_words object_clauses_list TOK_DOT
| object_clauses_list TOK_DOT
;

object_clauses_list:
  object_clauses
| object_clauses_list object_clauses
;

object_clauses:
  object_computer_memory
| object_computer_sequence
| object_computer_segment
| object_computer_class
;

object_computer_memory:
  MEMORY SIZE _is integer object_char_or_word
  {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
;

object_computer_sequence:
  prog_coll_sequence _is single_reference
  {
	current_program->collating_sequence = $3;
  }
;

object_computer_segment:
  SEGMENT_LIMIT _is integer
  {
	/* Ignore */
  }
;

object_computer_class:
  _character CLASSIFICATION _is locale_class
  {
	if (current_program->classification) {
		cb_error (_("Duplicate CLASSIFICATION clause"));
	} else {
		current_program->classification = $4;
	}
  }
;

locale_class:
  single_reference
  {
	$$ = $1;
  }
| LOCALE
  {
	$$ = NULL;
  }
| USER_DEFAULT
  {
	$$ = cb_int1;
  }
| SYSTEM_DEFAULT
  {
	$$ = cb_int1;
  }
;

computer_words:
  WORD
| computer_words WORD
;

/* REPOSITORY paragraph */

repository_paragraph:
  REPOSITORY TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
  repository_entry
  {
	cobc_in_repository = 0;
  }
;

repository_entry:
| repository_list TOK_DOT
| repository_list error TOK_DOT
  {
	yyerrok;
  }
;

repository_list:
  repository_name
| repository_list repository_name
;

repository_name:
  FUNCTION ALL INTRINSIC
  {
	functions_are_all = 1;
  }
| FUNCTION user_or_intrinsic _as_literal_intrinsic
  {
	cb_tree		x;

	if ($3) {
		x = $3;
	} else {
		x = $2;
	}
	current_program->user_spec_list =
		cb_list_add (current_program->user_spec_list, x);
  }
| FUNCTION repository_name_list INTRINSIC
;

user_or_intrinsic:
  REPO_FUNCTION
| USER_REPO_FUNCTION
;

_as_literal_intrinsic:
  /* empty */
  {
	$$ = NULL;
  }
| AS LITERAL
  {
	$$ = $2;
  }
;

repository_name_list:
  REPO_FUNCTION
  {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, $1);
  }
| repository_name_list REPO_FUNCTION
  {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, $2);
  }
;


/* SPECIAL-NAMES paragraph */

special_names_paragraph:
  SPECIAL_NAMES TOK_DOT
  {
	check_duplicate = 0;
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	header_check |= COBC_HD_SPECIAL_NAMES;
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	}
  }
;

special_names_entry:
  special_name_list TOK_DOT
| special_name_list error TOK_DOT
  {
	cobc_cs_check = 0;
	yyerrok;
  }
;

special_name_list:
  special_name
| special_name_list special_name
;

special_name:
  mnemonic_name_clause
| alphabet_name_clause
| symbolic_characters_clause
| locale_clause
| class_name_clause
| currency_sign_clause
| decimal_point_clause
| numeric_sign_clause
| cursor_clause
| crt_status_clause
| screen_control
| event_status
;


/* Mnemonic name clause */

mnemonic_name_clause:
  WORD
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		save_tree = NULL;
	} else {
		save_tree = lookup_system_name (CB_NAME ($1));
		if (!save_tree) {
			cb_error_x ($1, _("Invalid system-name '%s'"), CB_NAME ($1));
		}
	}
  }
  mnemonic_choices
;

mnemonic_choices:
  _is CRT
  {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_DEVICE_CONSOLE) {
			cb_error_x (save_tree, _("Invalid CRT clause"));
		} else {
			current_program->flag_console_is_crt = 1;
		}
	}
  }
| integer _is undefined_word
  {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_FEATURE_CONVENTION) {
			cb_error_x (save_tree, _("Invalid special names clause"));
		} else if (CB_VALID_TREE ($3)) {
			CB_SYSTEM_NAME(save_tree)->value = $1;
			cb_define ($3, save_tree);
			CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
					$3, save_tree);
		}
	}
  }
| _is undefined_word special_name_mnemonic_on_off
  {
	if (save_tree && CB_VALID_TREE ($2)) {
		cb_define ($2, save_tree);
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
				$2, save_tree);
	}
  }
| on_off_clauses
;

special_name_mnemonic_on_off:
| on_off_clauses
;

on_off_clauses:
  on_or_off _onoff_status undefined_word
  {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ($3, save_tree, $1 == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, $3, x);
	}
  }
| on_off_clauses on_or_off _onoff_status undefined_word
  {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ($4, save_tree, $2 == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, $4, x);
	}
  }
;

/* ALPHABET clause */

alphabet_name_clause:
  ALPHABET undefined_word
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		$$ = NULL;
	} else {
		/* Returns null on error */
		$$ = cb_build_alphabet_name ($2);
	}
  }
  _is alphabet_definition
  {
	if ($3) {
		current_program->alphabet_name_list =
			cb_list_add (current_program->alphabet_name_list, $3);
	}
	cobc_cs_check = 0;
  }
;

alphabet_definition:
  NATIVE
  {
	if ($-1) {
		CB_ALPHABET_NAME ($-1)->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
| STANDARD_1
  {
	if ($-1) {
		CB_ALPHABET_NAME ($-1)->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
| STANDARD_2
  {
	if ($-1) {
		CB_ALPHABET_NAME ($-1)->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
| EBCDIC
  {
	if ($-1) {
		CB_ALPHABET_NAME ($-1)->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
| ASCII
  {
	if ($-1) {
		CB_ALPHABET_NAME ($-1)->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
| alphabet_literal_list
  {
	if ($-1) {
		CB_ALPHABET_NAME ($-1)->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ($-1)->custom_list = $1;
	}
  }
;

alphabet_literal_list:
  alphabet_literal
  {
	$$ = CB_LIST_INIT ($1);
  }
| alphabet_literal_list alphabet_literal
  {
	$$ = cb_list_add ($1, $2);
  }
;

alphabet_literal:
  alphabet_lits
  {
	$$ = $1;
  }
| alphabet_lits THRU alphabet_lits
  {
	$$ = CB_BUILD_PAIR ($1, $3);
  }
| alphabet_lits ALSO
  {
	$$ = CB_LIST_INIT ($1);
  }
  alphabet_also_sequence
  {
	$$ = $3;
  }
;

alphabet_also_sequence:
  alphabet_lits
  {
	cb_list_add ($0, $1);
  }
| alphabet_also_sequence ALSO alphabet_lits
  {
	cb_list_add ($0, $3);
  }
;

alphabet_lits:
  LITERAL			{ $$ = $1; }
| SPACE				{ $$ = cb_space; }
| ZERO				{ $$ = cb_zero; }
| QUOTE				{ $$ = cb_quote; }
| HIGH_VALUE			{ $$ = cb_norm_high; }
| LOW_VALUE			{ $$ = cb_norm_low; }
;


/* SYMBOLIC characters clause */

symbolic_characters_clause:
  symbolic_collection sym_in_word
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else if ($1) {
		CB_CHAIN_PAIR (current_program->symbolic_char_list, $1, $2);
	}
  }
;

sym_in_word:
  /* empty */
  {
	$$ = NULL;
  }
| IN WORD
  {
	$$ = $2;
  }
;

symbolic_collection:
  %prec SHIFT_PREFER
  SYMBOLIC _characters symbolic_chars_list
  {
	$$ = $3;
  }
;

symbolic_chars_list:
  symbolic_chars_phrase
  {
	$$ = $1;
  }
| symbolic_chars_list symbolic_chars_phrase
  {
	if ($2) {
		$$ = cb_list_append ($1, $2);
	} else {
		$$ = $1;
	}
  }
;

symbolic_chars_phrase:
  char_list _is_are integer_list
  {
	cb_tree		l1;
	cb_tree		l2;

	if (cb_list_length ($1) != cb_list_length ($3)) {
		cb_error (_("Invalid SYMBOLIC clause"));
		$$ = NULL;
	} else {
		l1 = $1;
		l2 = $3;
		for (; l1; l1 = CB_CHAIN (l1), l2 = CB_CHAIN (l2)) {
			CB_PURPOSE (l1) = CB_VALUE (l2);
		}
		$$ = $1;
	}
  }
;

char_list:
  unique_word
  {
	if ($1 == NULL) {
		$$ = NULL;
	} else {
		$$ = CB_LIST_INIT ($1);
	}
  }
| char_list unique_word
  {
	if ($2 == NULL) {
		$$ = $1;
	} else {
		$$ = cb_list_add ($1, $2);
	}
  }
;

integer_list:
  symbolic_integer		{ $$ = CB_LIST_INIT ($1); }
| integer_list symbolic_integer	{ $$ = cb_list_add ($1, $2); }
;

/* CLASS clause */

class_name_clause:
  CLASS undefined_word _is class_item_list
  {
	cb_tree		x;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		x = cb_build_class_name ($2, $4);
		if (x) {
			current_program->class_name_list =
				cb_list_add (current_program->class_name_list, x);
		}
	}
  }
;

class_item_list:
  class_item			{ $$ = CB_LIST_INIT ($1); }
| class_item_list class_item	{ $$ = cb_list_add ($1, $2); }
;

class_item:
  class_value
  {
	$$ = $1;
  }
| class_value THRU class_value
  {
	if (CB_TREE_CLASS ($1) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P ($1) && CB_LITERAL ($1)->size != 1) {
		cb_error (_("CLASS literal with THRU must have size 1"));
	}
	if (CB_TREE_CLASS ($3) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P ($3) && CB_LITERAL ($3)->size != 1) {
		cb_error (_("CLASS literal with THRU must have size 1"));
	}
	if (literal_value ($1) <= literal_value ($3)) {
		$$ = CB_BUILD_PAIR ($1, $3);
	} else {
		$$ = CB_BUILD_PAIR ($3, $1);
	}
  }
;

/* LOCALE clause */

locale_clause:
  LOCALE undefined_word _is LITERAL
  {
	cb_tree	l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		l = cb_build_locale_name ($2, $4);
		if (l) {
			current_program->locale_list =
				cb_list_add (current_program->locale_list, l);
		}
	}
  }
;

/* CURRENCY SIGN clause */

currency_sign_clause:
  CURRENCY _sign _is LITERAL with_pic_symbol
  {
	unsigned char	*s = CB_LITERAL ($4)->data;
	unsigned int	error_ind = 0;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		error_ind = 1;
	}
	check_repeated ("CURRENCY", SYN_CLAUSE_1);
	if ($5) {
		PENDING ("PICTURE SYMBOL");
	}
	if (CB_LITERAL ($4)->size != 1) {
		cb_error_x ($4, _("Invalid currency sign '%s'"), (char *)s);
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
		cb_error_x ($4, _("Invalid currency sign '%s'"), (char *)s);
		break;
	default:
		if (!error_ind) {
			current_program->currency_symbol = s[0];
		}
		break;
	}
  }
;


with_pic_symbol:
  /* empty */
  {
	$$ = NULL;
  }
| _with PICTURE_SYMBOL LITERAL
  {
	$$ = $3;
  }
;

/* DECIMAL-POINT clause */

decimal_point_clause:
  DECIMAL_POINT _is COMMA
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
;


/* NUMERIC SIGN clause */

numeric_sign_clause:
  NUMERIC SIGN _is TRAILING SEPARATE
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
;

/* CURSOR clause */

cursor_clause:
  CURSOR _is reference
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("CURSOR", SYN_CLAUSE_3);
		current_program->cursor_pos = $3;
	}
  }
;


/* CRT STATUS clause */

crt_status_clause:
  CRT STATUS _is reference
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("CRT STATUS", SYN_CLAUSE_4);
		current_program->crt_status = $4;
	}
  }
;


/* SCREEN CONTROL */

screen_control:
  SCREEN_CONTROL _is reference
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
;

/* EVENT STATUS */

event_status:
  EVENT_STATUS _is reference
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
;

/* INPUT-OUTPUT SECTION */

input_output_header:
| INPUT_OUTPUT SECTION TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
;

file_control_header:
| FILE_CONTROL TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
;

i_o_control_header:
| I_O_CONTROL TOK_DOT
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
;

/* FILE-CONTROL paragraph */

file_control_sequence:
| file_control_sequence file_control_entry
;

file_control_entry:
  SELECT flag_optional undefined_word
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       COBC_HD_FILE_CONTROL, 0);
	check_duplicate = 0;
	if (CB_INVALID_TREE ($3)) {
		YYERROR;
	}

	/* Build new file */
	current_file = build_file ($3);
	current_file->optional = CB_INTEGER ($2)->val;

	/* Add file to current program list */
	CB_ADD_TO_CHAIN (CB_TREE (current_file), current_program->file_list);
  }
  select_clause_sequence TOK_DOT
  {
	validate_file (current_file, $3);
  }
| SELECT error TOK_DOT
  {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  }
;

select_clause_sequence:
| select_clause_sequence select_clause
;

select_clause:
  assign_clause
| access_mode_clause
| alternative_record_key_clause
| collating_sequence_clause
| file_status_clause
| lock_mode_clause
| organization_clause
| padding_character_clause
| record_delimiter_clause
| record_key_clause
| relative_key_clause
| reserve_clause
| sharing_clause
;


/* ASSIGN clause */

assign_clause:
  ASSIGN _to_using _ext_clause _line_adv_file assignment_name
  {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, $5);
  }
| ASSIGN _to_using _ext_clause device_name opt_assignment_name
  {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ($5) {
		current_file->assign = cb_build_assignment_name (current_file, $5);
	} else {
		current_file->flag_fileid = 1;
	}
  }
| ASSIGN _to_using _ext_clause DISPLAY opt_assignment_name
  {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ($5) {
		current_file->assign = cb_build_assignment_name (current_file, $5);
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("stdout", (size_t)6);
		current_file->special = COB_SELECT_STDOUT;
	}
  }
| ASSIGN _to_using _ext_clause KEYBOARD opt_assignment_name
  {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ($5) {
		current_file->assign = cb_build_assignment_name (current_file, $5);
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("stdin", (size_t)5);
		current_file->special = COB_SELECT_STDIN;
	}
  }
| ASSIGN _to_using _ext_clause PRINTER opt_assignment_name
  {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	if ($5) {
		current_file->assign = cb_build_assignment_name (current_file, $5);
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("LPT1", (size_t)4);
	}
  }
;

device_name:
  DISC
| DISK
| TAPE
| RANDOM
;

_line_adv_file:
| LINE ADVANCING _file
  {
	current_file->flag_line_adv = 1;
  }
;

_ext_clause:
| EXTERNAL
  {
	current_file->flag_ext_assign = 1;
  }
| DYNAMIC
;

assignment_name:
  LITERAL
| qualified_word
;

opt_assignment_name:
  /* empty */
  {
	$$ = NULL;
  }
| LITERAL
| qualified_word
;


/* ACCESS MODE clause */

access_mode_clause:
  ACCESS _mode _is access_mode
  {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
;

access_mode:
  SEQUENTIAL		{ current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
| DYNAMIC		{ current_file->access_mode = COB_ACCESS_DYNAMIC; }
| RANDOM		{ current_file->access_mode = COB_ACCESS_RANDOM; }
;


/* ALTERNATIVE RECORD KEY clause */

alternative_record_key_clause:
  ALTERNATE RECORD _key _is reference flag_duplicates suppress_clause
  {
	struct cb_alt_key *p;
	struct cb_alt_key *l;

	p = cobc_parse_malloc (sizeof (struct cb_alt_key));
	p->key = $5;
	p->component_list = NULL;
	p->duplicates = CB_INTEGER ($6)->val;
	if (CB_INTEGER ($7)->val == -1) {
		p->tf_suppress = 0;
	} else {
		p->tf_suppress = 1;
		p->char_suppress = CB_INTEGER ($7)->val;
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
|
  ALTERNATE RECORD _key _is reference '=' split_key_list flag_duplicates suppress_clause
  {
	struct cb_alt_key *p;
	struct cb_alt_key *l;
	cb_tree composite_key;

	p = cobc_malloc (sizeof (struct cb_alt_key));
	// generate field (in w-s) for composite-key
	composite_key = cb_build_field($5);
	if (composite_key == cb_error_node) {
		YYERROR;
	} else {
		composite_key->category = CB_CATEGORY_ALPHANUMERIC; 
		((struct cb_field *)composite_key)->count = 1;
		p->key = cb_build_field_reference((struct cb_field *)composite_key, NULL);
		p->component_list = key_component_list;
		p->duplicates = CB_INTEGER ($8)->val;
		if (CB_INTEGER ($9)->val == -1) {
			p->tf_suppress = 0;
		} else {
			p->tf_suppress = 1;
			p->char_suppress = CB_INTEGER ($9)->val;
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
;



split_key_list:
  {
    key_component_list = NULL;
  }
  split_key
| split_key_list split_key
;



split_key:
  reference
  {
    struct cb_key_component *c;
    struct cb_key_component *comp = cobc_malloc(sizeof(struct cb_key_component));
    comp->next = NULL;
    comp->component = $1;
    if (key_component_list == NULL) {
       key_component_list = comp;
    } else {
       for (c = key_component_list; c->next != NULL; c = c->next);
       c->next = comp;
    }
  }
;

suppress_clause:
  /* empty */                   { $$ = cb_int (-1); }
|
  SUPPRESS WHEN ALL simple_value
  {
     if (cb_verify (cb_use_sparse_indexed_keys, "SUPPRESS WHEN")) {
        $$ = cb_int (literal_value ($4));
     } else {
        $$ = cb_int (-1);
     }
  }
;



/* COLLATING SEQUENCE clause */

collating_sequence_clause:
  coll_sequence _is WORD
  {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
;


/* FILE STATUS clause */

file_status_clause:
  file_or_sort STATUS _is reference
  {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = $4;
  }
;

file_or_sort:
  /* empty */
| TOK_FILE
| SORT
;

/* LOCK MODE clause */

lock_mode_clause:
  {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
  LOCK _mode _is lock_mode
;

lock_mode:
  MANUAL lock_with
  {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
| AUTOMATIC lock_with
  {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
| EXCLUSIVE
  {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
;

lock_with:
| WITH LOCK ON lock_records
| WITH LOCK ON MULTIPLE lock_records
  {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
| WITH ROLLBACK
  {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  }
;


/* ORGANIZATION clause */

organization_clause:
  ORGANIZATION _is organization
| organization
;

organization:
  INDEXED
  {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
| _record _binary SEQUENTIAL
  {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
| RELATIVE
  {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
| LINE SEQUENTIAL
  {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
;


/* PADDING CHARACTER clause */

padding_character_clause:
  PADDING _character _is reference_or_literal
  {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
;


/* RECORD DELIMITER clause */

record_delimiter_clause:
  RECORD DELIMITER _is STANDARD_1
  {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
;


/* RECORD KEY clause */

record_key_clause:
  RECORD _key _is reference
  {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = $4;
  }
;


/* RELATIVE KEY clause */

relative_key_clause:
  RELATIVE _key _is reference
  {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = $4;
  }
;


/* RESERVE clause */

reserve_clause:
  RESERVE no_or_integer _area
  {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
;

no_or_integer:
  NO
| integer
;

/* SHARING clause */

sharing_clause:
  SHARING _with sharing_option
  {
	check_repeated ("SHARING", SYN_CLAUSE_12);
  }
;

sharing_option:
  ALL _other        { current_file->sharing = COB_SHARE_ALL; }
| NO _other         { current_file->sharing = COB_SHARE_EXCLUSIVE; }
| READ ONLY         { current_file->sharing = COB_SHARE_READ_ONLY; }
;


/* I-O-CONTROL paragraph */

opt_i_o_control:
| i_o_control_list TOK_DOT
| i_o_control_list error TOK_DOT
  {
	yyerrok;
  }
;

i_o_control_list:
  i_o_control_clause
| i_o_control_list i_o_control_clause
;

i_o_control_clause:
  same_clause
| multiple_file_tape_clause
;

/* SAME clause */

same_clause:
  SAME same_option _area _for file_name_list
  {
	cb_tree l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	switch (CB_INTEGER ($2)->val) {
	case 0:
		/* SAME AREA */
		break;
	case 1:
		/* SAME RECORD */
		for (l = $5; l; l = CB_CHAIN (l)) {
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
;

same_option:
  /* empty */			{ $$ = cb_int0; }
| RECORD			{ $$ = cb_int1; }
| SORT				{ $$ = cb_int2; }
| SORT_MERGE			{ $$ = cb_int2; }
;

/* MULTIPLE FILE TAPE clause */

multiple_file_tape_clause:
  MULTIPLE
  {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
  _file _tape _contains multiple_file_list
  {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
;

multiple_file_list:
  multiple_file
| multiple_file_list multiple_file
;

multiple_file:
  file_name multiple_file_position
;

multiple_file_position:
| POSITION integer
;


/* DATA DIVISION */

data_division_header:
| DATA DIVISION TOK_DOT
  {
	header_check |= COBC_HD_DATA_DIVISION;
  }
;

/* FILE SECTION */

file_section_header:
| TOK_FILE SECTION TOK_DOT
  {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
;

file_description_sequence:
| file_description_sequence file_description
;

file_description:
  file_description_entry
  record_description_list
  {
	if (CB_VALID_TREE (current_file)) {
		if (CB_VALID_TREE ($2)) {
			if (current_file->reports) {
				cb_error (_("RECORD description invalid with REPORT"));
			} else {
				finalize_file (current_file, CB_FIELD ($2));
			}
		} else if (!current_file->reports) {
			cb_error (_("RECORD description missing or invalid"));
		}
	}
  }
;

/* File description entry */

file_description_entry:
  file_type file_name
  {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION,
			       COBC_HD_FILE_SECTION, 0, 0);
	check_duplicate = 0;
	if (CB_INVALID_TREE ($2) || cb_ref ($2) == cb_error_node) {
		YYERROR;
	}
	current_file = CB_FILE (cb_ref ($2));
	if (CB_VALID_TREE (current_file)) {
		if ($1) {
			current_file->organization = COB_ORG_SORT;
		}
	}
  }
  file_description_clause_sequence TOK_DOT
| file_type error TOK_DOT
  {
	yyerrok;
  }
;

file_type:
  FD
  {
	$$ = NULL;
  }
| SD
  {
	$$ = cb_int1;
  }
;

file_description_clause_sequence:
| file_description_clause_sequence file_description_clause
;

file_description_clause:
  _is EXTERNAL
  {
	check_repeated ("EXTERNAL", SYN_CLAUSE_1);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_global) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	current_file->flag_external = 1;
  }
| _is GLOBAL
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
| block_contains_clause
| record_clause
| label_records_clause
| value_of_clause
| data_records_clause
| linage_clause
| recording_mode_clause
| code_set_clause
| report_clause
;


/* BLOCK CONTAINS clause */

block_contains_clause:
  BLOCK _contains integer opt_to_integer _records_or_characters
  {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
;

_records_or_characters:	| RECORDS | CHARACTERS ;


/* RECORD clause */

record_clause:
  RECORD _contains integer _characters
  {
	check_repeated ("RECORD", SYN_CLAUSE_4);
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if (warningopt) {
			cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_max = cb_get_int ($3);
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
| RECORD _contains integer TO integer _characters
  {
	int	error_ind = 0;

	check_repeated ("RECORD", SYN_CLAUSE_4);
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if (warningopt) {
			cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_min = cb_get_int ($3);
		current_file->record_max = cb_get_int ($5);
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
| RECORD _is VARYING _in _size opt_from_integer opt_to_integer _characters
  record_depending
  {
	int	error_ind = 0;

	check_repeated ("RECORD", SYN_CLAUSE_4);
	current_file->record_min = $6 ? cb_get_int ($6) : 0;
	current_file->record_max = $7 ? cb_get_int ($7) : 0;
	if ($6 && current_file->record_min < 0)  {
		current_file->record_min = 0;
		error_ind = 1;
	}
	if ($7 && current_file->record_max < 1)  {
		current_file->record_max = 1;
		error_ind = 1;
	}
	if ($7 && current_file->record_max > MAX_FD_RECORD)  {
		current_file->record_max = MAX_FD_RECORD;
		cb_error (_("RECORD size exceeds maximum allowed (%d)"),
			  MAX_FD_RECORD);
		error_ind = 1;
	}
	if (($6 || $7) && current_file->record_max <= current_file->record_min)  {
		error_ind = 1;
	}
	if (error_ind) {
		cb_error (_("RECORD clause invalid"));
	}
  }
;

record_depending:
| DEPENDING _on reference
  {
	current_file->record_depending = $3;
  }
;

opt_from_integer:
  /* empty */			{ $$ = NULL; }
| _from integer			{ $$ = $2; }
;

opt_to_integer:
  /* empty */			{ $$ = NULL; }
| TO integer			{ $$ = $2; }
;


/* LABEL RECORDS clause */

label_records_clause:
  LABEL records label_option
  {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
;


/* VALUE OF clause */

value_of_clause:
  VALUE OF file_id _is valueof_name
  {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
| VALUE OF FILE_ID _is valueof_name
  {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, $5);
	}
  }
;

file_id:
  WORD
| ID
;

valueof_name:
  LITERAL
| qualified_word
;

/* DATA RECORDS clause */

data_records_clause:
  DATA records opt_reference_list
  {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
;


/* LINAGE clause */

linage_clause:
  LINAGE _is reference_or_literal _lines
  linage_sequence
  {
	check_repeated ("LINAGE", SYN_CLAUSE_8);
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("LINAGE clause with wrong file type"));
	} else {
		current_file->linage = $3;
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		if (current_linage == 0) {
			linage_file = current_file;
		}
		current_linage++;
	}
  }
;

linage_sequence:
| linage_sequence linage_lines
;

linage_lines:
  linage_footing
| linage_top
| linage_bottom
;

linage_footing:
  _with FOOTING _at reference_or_literal
  {
	current_file->latfoot = $4;
  }
;

linage_top:
  TOP reference_or_literal
  {
	current_file->lattop = $2;
  }
;

linage_bottom:
  BOTTOM reference_or_literal
  {
	current_file->latbot = $2;
  }
;

/* RECORDING MODE clause */

recording_mode_clause:
  RECORDING _mode _is WORD
  {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
;


/* CODE-SET clause */

code_set_clause:
  CODE_SET _is WORD
  {
	check_repeated ("CODE SET", SYN_CLAUSE_10);
	if (CB_VALID_TREE ($3)) {
		cb_tree			x;
		struct cb_alphabet_name	*al;

		x = cb_ref ($3);
		if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
		    current_file->organization != COB_ORG_SEQUENTIAL) {
			cb_error (_("CODE-SET clause invalid for file type"));
		}
		if (!CB_ALPHABET_NAME_P (x)) {
			cb_error_x ($3, _("Alphabet-name is expected '%s'"), cb_name ($3));
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
					cb_warning_x ($3, _("Ignoring CODE-SET '%s'"),
						      cb_name ($3));
				}
				break;
#else
			case CB_ALPHABET_EBCDIC:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if (warningopt) {
					cb_warning_x ($3, _("Ignoring CODE-SET '%s'"),
						      cb_name ($3));
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
;

/* REPORT clause */

report_clause:
  report_keyword rep_name_list
  {
	check_repeated ("REPORT", SYN_CLAUSE_11);
	cb_warning (_("REPORT WRITER not implemented"));
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("REPORT clause with wrong file type"));
	} else {
		current_file->reports = $2;
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	}
  }
;

report_keyword:
  REPORT _is
| REPORTS _are
;

rep_name_list:
  undefined_word
  {
	current_report = build_report ($1);
	current_report->file = current_file;
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
| rep_name_list undefined_word
  {
	current_report = build_report ($2);
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
;


/* WORKING-STORAGE SECTION */

/* RXWRXW - W/S
working_storage_header:
| WORKING_STORAGE SECTION TOK_DOT
  {
	current_storage = CB_STORAGE_WORKING;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
  }
;

working_storage_records:
  {
	current_storage = CB_STORAGE_WORKING;
	check_headers_present (COBC_HD_DATA_DIVISION,
			       COBC_HD_WORKING_STORAGE_SECTION, 0, 0);
  }
  record_description_list
  {
	if ($2) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ($2));
	}
  }
;
*/

working_storage_section:
| WORKING_STORAGE SECTION TOK_DOT
  {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
  record_description_list
  {
	if ($5) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ($5));
	}
  }
;

record_description_list:
  /* empty */
  {
	$$ = NULL;
  }
| {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
  record_description_list_2
  {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	$$ = CB_TREE (description_field);
  }
;

record_description_list_2:
  data_description TOK_DOT
| record_description_list_2
  data_description TOK_DOT
| record_description_list_2 TOK_DOT
;

data_description:
  constant_entry
| level_number entry_name
  {
	cb_tree x;

	x = cb_build_field_tree ($1, $2, current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ($1);
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	} else {
		current_field = CB_FIELD (x);
		check_pic_duplicate = 0;
	}
  }
  data_description_clause_sequence
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
| level_number error TOK_DOT
  {
	/* Free tree assocated with level number */
	cobc_parse_free ($1);
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
;

level_number:
  not_const_word WORD
  {
	$$ = $2;
  }
;

entry_name:
  /* empty */
  {
	$$ = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
| FILLER
  {
	$$ = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
| WORD
  {
	$$ = $1;
	qualifier = $1;
	non_const_word = 0;
  }
;

const_name:
  WORD
  {
	$$ = $1;
	qualifier = $1;
	non_const_word = 0;
  }
;

const_global:
  /* Nothing */
  {
	$$= NULL;
  }
| _is GLOBAL
  {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
		$$= NULL;
	} else {
		$$ = cb_null;
	}
  }
;

lit_or_length:
  literal				{ $$ = $1; }
| LENGTH_OF con_identifier		{ $$ = cb_build_const_length ($2); }
| LENGTH con_identifier			{ $$ = cb_build_const_length ($2); }
| BYTE_LENGTH _of con_identifier	{ $$ = cb_build_const_length ($3); }
;

con_identifier:
  identifier_1
  {
	$$ = $1;
  }
| BINARY_CHAR
  {
	$$ = cb_int1;
  }
| BINARY_SHORT
  {
	$$ = cb_int2;
  }
| BINARY_LONG
  {
	$$ = cb_int4;
  }
| BINARY_DOUBLE
  {
	$$ = cb_int (8);
  }
| BINARY_C_LONG
  {
	$$ = cb_int ((int)sizeof(long));
  }
| pointer_len
  {
	$$ = cb_int ((int)sizeof(void *));
  }
| float_usage
  {
	$$ = cb_int ((int)sizeof(float));
  }
| double_usage
  {
	$$ = cb_int ((int)sizeof(double));
  }
| fp32_usage
  {
	$$ = cb_int (4);
  }
| fp64_usage
  {
	$$ = cb_int (8);
  }
| fp128_usage
  {
	$$ = cb_int (16);
  }
| error TOK_DOT
  {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  }
;

fp32_usage:
  FLOAT_BINARY_32
| FLOAT_DECIMAL_7
;

fp64_usage:
  FLOAT_BINARY_64
| FLOAT_DECIMAL_16
;

fp128_usage:
  FLOAT_BINARY_128
| FLOAT_DECIMAL_34
| FLOAT_EXTENDED
;

pointer_len:
  POINTER
| PROGRAM_POINTER
;

constant_entry:
  level_number const_name CONSTANT const_global constant_source
  {
	cb_tree x;
	int	level;

	cobc_cs_check = 0;
	level = cb_get_level ($1);
	/* Free tree assocated with level number */
	cobc_parse_free ($1);
	if (level != 1) {
		cb_error (_("CONSTANT item not at 01 level"));
	} else if ($5) {
		x = cb_build_constant ($2, $5);
		CB_FIELD (x)->flag_item_78 = 1;
		CB_FIELD (x)->level = 1;
		cb_needs_01 = 1;
		if ($4) {
			CB_FIELD (x)->flag_is_global = 1;
		}
		/* Ignore return value */
		(void)cb_validate_78_item (CB_FIELD (x), 0);
	}
  }
;

constant_source:
  _as lit_or_length
  {
	$$ = $2;
  }
| FROM WORD
  {
	PENDING ("CONSTANT FROM clause");
	$$ = NULL;
  }
;

data_description_clause_sequence:
  /* empty */
  {
	/* Required to check redefines */
	$$ = NULL;
  }
| data_description_clause_sequence
  data_description_clause
  {
	/* Required to check redefines */
	$$ = cb_true;
  }
;

data_description_clause:
  redefines_clause
| external_clause
| global_clause
| picture_clause
| usage_clause
| sign_clause
| occurs_clause
| justified_clause
| synchronized_clause
| blank_clause
| based_clause
| value_clause
| renames_clause
| any_length_clause
;


/* REDEFINES clause */

redefines_clause:
  REDEFINES identifier_1
  {
	check_pic_repeated ("REDEFINES", SYN_CLAUSE_1);
	if ($0 != NULL) {
		if (cb_relaxed_syntax_check) {
			cb_warning_x ($2, _("REDEFINES clause should follow entry-name"));
		} else {
			cb_error_x ($2, _("REDEFINES clause must follow entry-name"));
		}
	}

	current_field->redefines = cb_resolve_redefines (current_field, $2);
	if (current_field->redefines == NULL) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
		YYERROR;
	}
  }
;


/* EXTERNAL clause */

external_clause:
  _is EXTERNAL as_extname
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
;

as_extname:
  /* empty */
  {
	current_field->ename = cb_to_cname (current_field->name);
  }
| AS LITERAL
  {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ($2)->data);
  }
;

/* GLOBAL clause */

global_clause:
  _is GLOBAL
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
;


/* PICTURE clause */

picture_clause:
  PICTURE
  {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ($1);
  }
;


/* USAGE clause */

usage_clause:
  usage
| USAGE _is usage
;

usage:
  BINARY
  {
	check_set_usage (CB_USAGE_BINARY);
  }
| COMP
  {
	check_set_usage (CB_USAGE_BINARY);
  }
| float_usage
  {
	check_set_usage (CB_USAGE_FLOAT);
  }
| double_usage
  {
	check_set_usage (CB_USAGE_DOUBLE);
  }
| COMP_3
  {
	check_set_usage (CB_USAGE_PACKED);
  }
| COMP_4
  {
	check_set_usage (CB_USAGE_BINARY);
  }
| COMP_5
  {
	check_set_usage (CB_USAGE_COMP_5);
  }
| COMP_6
  {
	check_set_usage (CB_USAGE_COMP_6);
  }
| COMP_X
  {
	check_set_usage (CB_USAGE_COMP_X);
  }
| DISPLAY
  {
	check_set_usage (CB_USAGE_DISPLAY);
  }
| INDEX
  {
	check_set_usage (CB_USAGE_INDEX);
  }
| PACKED_DECIMAL
  {
	check_set_usage (CB_USAGE_PACKED);
  }
| POINTER
  {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
| PROGRAM_POINTER
  {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
| SIGNED_SHORT
  {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
| SIGNED_INT
  {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
| SIGNED_LONG
  {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
| UNSIGNED_SHORT
  {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
| UNSIGNED_INT
  {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
| UNSIGNED_LONG
  {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
| BINARY_CHAR _signed
  {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
| BINARY_CHAR UNSIGNED
  {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
| BINARY_SHORT _signed
  {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
| BINARY_SHORT UNSIGNED
  {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
| BINARY_LONG _signed
  {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
| BINARY_LONG UNSIGNED
  {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
| BINARY_DOUBLE _signed
  {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
| BINARY_DOUBLE UNSIGNED
  {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
| BINARY_C_LONG _signed
  {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  }
| BINARY_C_LONG UNSIGNED
  {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  }
| FLOAT_BINARY_32
  {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
| FLOAT_BINARY_64
  {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
| FLOAT_BINARY_128
  {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
| FLOAT_DECIMAL_16
  {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
| FLOAT_DECIMAL_34
  {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
| NATIONAL
  {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
;

float_usage:
  COMP_1
| FLOAT_SHORT
;

double_usage:
  COMP_2
| FLOAT_LONG
;

/* SIGN clause */

sign_clause:
  _sign_is LEADING flag_separate
  {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ($3 ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
| _sign_is TRAILING flag_separate
  {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ($3 ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
;


/* REPORT (RD) OCCURS clause */

report_occurs_clause:
  OCCURS integer occurs_to_integer _times
  occurs_depending occurs_step
  {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_7);
	if (current_field->depending && !($3)) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = $3 ? cb_get_int ($2) : 1;
	current_field->occurs_max = $3 ? cb_get_int ($3) : cb_get_int ($2);
	current_field->indexes++;
	if (current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error (_("Maximum OCCURS depth exceeded (%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	current_field->flag_occurs = 1;
  }
;

occurs_step:
| STEP integer
  {
	current_field->step_count = cb_get_int ($2);
  }
;

/* OCCURS clause */

occurs_clause:
  OCCURS integer occurs_to_integer _times
  occurs_depending occurs_keys occurs_indexed
  {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_7);
	if (current_field->depending && !($3)) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = $3 ? cb_get_int ($2) : 1;
	current_field->occurs_max = $3 ? cb_get_int ($3) : cb_get_int ($2);
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
;

occurs_to_integer:
  /* empty */			{ $$ = NULL; }
| TO integer			{ $$ = $2; }
;

occurs_depending:
| DEPENDING _on reference
  {
	current_field->depending = $3;
  }
;

occurs_keys:
  occurs_key_list
  {
	if ($1) {
		cb_tree		l;
		struct cb_key	*keys;
		int		i;
		int		nkeys;

		l = $1;
		nkeys = cb_list_length ($1);
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
;

occurs_key_list:
  /* empty */			{ $$ = NULL; }
| occurs_key_list
  ascending_or_descending _key _is reference_list
  {
	cb_tree l;

	for (l = $5; l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = $2;
		if (qualifier && !CB_REFERENCE(CB_VALUE(l))->chain &&
		    strcasecmp (CB_NAME(CB_VALUE(l)), CB_NAME(qualifier))) {
			CB_REFERENCE(CB_VALUE(l))->chain = qualifier;
		}
	}
	$$ = cb_list_append ($1, $5);
  }
;

ascending_or_descending:
  ASCENDING			{ $$ = cb_int (COB_ASCENDING); }
| DESCENDING			{ $$ = cb_int (COB_DESCENDING); }
;

occurs_indexed:
| INDEXED _by occurs_index_list
  {
	current_field->index_list = $3;
  }
;

occurs_index_list:
  occurs_index			{ $$ = CB_LIST_INIT ($1); }
| occurs_index_list
  occurs_index			{ $$ = cb_list_add ($1, $2); }
;

occurs_index:
  WORD
  {
	$$ = cb_build_index ($1, cb_int1, 1U, current_field);
	CB_FIELD_PTR ($$)->special_index = 1;
  }
;


/* JUSTIFIED clause */

justified_clause:
  JUSTIFIED _right
  {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
;


/* SYNCHRONIZED clause */

synchronized_clause:
  SYNCHRONIZED _left_or_right
  {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
;


/* BLANK clause */

blank_clause:
  BLANK _when ZERO
  {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
;


/* BASED clause */

based_clause:
  BASED
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
;

/* VALUE clause */

value_clause:
  VALUE _is_are value_item_list
  {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = $3;
  }
  false_is
;

value_item_list:
  value_item			{ $$ = CB_LIST_INIT ($1); }
| value_item_list value_item	{ $$ = cb_list_add ($1, $2); }
;

value_item:
  literal			{ $$ = $1; }
| literal THRU literal		{ $$ = CB_BUILD_PAIR ($1, $3); }
;

false_is:
| _when_set_to TOK_FALSE _is literal
  {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ($4);
  }
;


/* RENAMES clause */

renames_clause:
  RENAMES qualified_word
  {
	check_pic_repeated ("RENAMES", SYN_CLAUSE_13);
	if (cb_ref ($2) != cb_error_node) {
		if (CB_FIELD (cb_ref ($2))->level == 01 ||
		    CB_FIELD (cb_ref ($2))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD (cb_ref ($2));
			current_field->pic = current_field->redefines->pic;
		}
	}
  }
| RENAMES qualified_word THRU qualified_word
  {
	check_pic_repeated ("RENAMES", SYN_CLAUSE_13);
	if (cb_ref ($2) != cb_error_node && cb_ref ($4) != cb_error_node) {
		if (CB_FIELD (cb_ref ($2))->level == 01 ||
		    CB_FIELD (cb_ref ($2))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else if (CB_FIELD (cb_ref ($4))->level == 01 ||
		    CB_FIELD (cb_ref ($4))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD (cb_ref ($2));
			current_field->rename_thru = CB_FIELD (cb_ref ($4));
		}
	}
  }
;

/* ANY LENGTH clause */

any_length_clause:
  ANY LENGTH
  {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  }
| ANY NUMERIC
  {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
		current_field->flag_any_numeric = 1;
	}
  }
;

/* LOCAL-STORAGE SECTION */

local_storage_section:
| LOCAL_STORAGE SECTION TOK_DOT
  {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  }
  record_description_list
  {
	if ($5) {
		current_program->local_storage = CB_FIELD ($5);
	}
  }
;


/* LINKAGE SECTION */

linkage_section:
| LINKAGE SECTION TOK_DOT
  {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
  record_description_list
  {
	if ($5) {
		current_program->linkage_storage = CB_FIELD ($5);
	}
  }
;

/* REPORT SECTION */

report_section:
| REPORT SECTION TOK_DOT
  {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  }
  report_description_sequence
;

report_description_sequence:
| report_description_sequence report_description
;

/* RD report description */

report_description:
  RD report_name
  {
	if (CB_INVALID_TREE ($2)) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ($2));
	}
	check_duplicate = 0;
  }
  report_description_options TOK_DOT
  report_group_description_list
;

report_description_options:
| report_description_options report_description_option
| error TOK_DOT
  {
	yyerrok;
  }
;

report_description_option:
  _is GLOBAL
  {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  }
| CODE _is id_or_lit
  {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
| control_clause
| page_limit_clause
;

/* REPORT control breaks */

control_clause:
  control_keyword control_field_list
  {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
;

control_field_list:
  _final identifier_list
;

identifier_list:
  identifier
| identifier_list identifier
;

/* PAGE clause */

page_limit_clause:
  PAGE _limits page_line_column
  page_heading_list
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
;

page_line_column:
  report_integer
  {
	current_report->lines = cb_get_int ($1);
  }
| report_integer line_or_lines report_integer columns_or_cols
  {
	current_report->lines = cb_get_int ($1);
	current_report->columns = cb_get_int ($3);
  }
| report_integer line_or_lines
  {
	current_report->lines = cb_get_int ($1);
  }
;

page_heading_list:
| page_heading_list page_detail
;


page_detail:
  heading_clause
| first_detail
| last_heading
| last_detail
| footing_clause
;

heading_clause:
  HEADING _is report_integer
  {
	current_report->heading = cb_get_int ($3);
  }
;

first_detail:
  FIRST detail_keyword _is report_integer
  {
	current_report->first_detail = cb_get_int ($4);
  }
;

last_heading:
  LAST ch_keyword _is report_integer
  {
	current_report->last_control = cb_get_int ($4);
  }
;

last_detail:
  LAST detail_keyword _is report_integer
  {
	current_report->last_detail = cb_get_int ($4);
  }
;

footing_clause:
  FOOTING _is report_integer
  {
	current_report->footing = cb_get_int ($3);
  }
;

report_group_description_list:
| report_group_description_list report_group_description_entry
;

report_group_description_entry:
  level_number entry_name
  {
	check_pic_duplicate = 0;
  }
  report_group_options TOK_DOT
;

report_group_options:
| report_group_options report_group_option
;

report_group_option:
  type_clause
| next_group_clause
| line_clause
| picture_clause
| report_usage_clause
| sign_clause
| justified_clause
| column_clause
| blank_clause
| source_clause
| sum_clause_list
| value_clause
| present_when_condition
| group_indicate_clause
| report_occurs_clause
| varying_clause
;

type_clause:
  TYPE _is type_option
  {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
;

type_option:
  rh_keyword
| ph_keyword
| ch_keyword control_final
| detail_keyword
| cf_keyword control_final
| pf_keyword
| rf_keyword
;

control_final:
| identifier or_page
| FINAL or_page
;

or_page:
| OR PAGE
;

next_group_clause:
  NEXT GROUP _is line_or_plus
  {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
;

sum_clause_list:
  SUM _of report_x_list reset_clause
  {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  }
;

reset_clause:
| RESET _on data_or_final
;

data_or_final:
  identifier
| FINAL
;

present_when_condition:
  PRESENT WHEN condition
  {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
;

varying_clause:
  VARYING identifier FROM arith_x BY arith_x
;

line_clause:
  line_keyword_clause report_line_integer_list
  {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  }
;

line_keyword_clause:
  LINE _numbers _is_are
| LINES _are
;

column_clause:
  col_keyword_clause report_col_integer_list
  {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
;

col_keyword_clause:
  column_or_col _numbers _is_are
| columns_or_cols _are
;

report_line_integer_list:
  line_or_plus
| report_line_integer_list line_or_plus
;

line_or_plus:
  PLUS integer
| report_integer
| NEXT_PAGE
;

report_col_integer_list:
  col_or_plus
| report_col_integer_list col_or_plus
;

col_or_plus:
  PLUS integer
| report_integer
;

source_clause:
  SOURCE _is arith_x flag_rounded
  {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  }
;

group_indicate_clause:
  GROUP _indicate
  {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  }
;

report_usage_clause:
  USAGE _is DISPLAY
  {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
;

/* SCREEN SECTION */

screen_section:
| SCREEN SECTION TOK_DOT
  {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
  opt_screen_description_list
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
;

opt_screen_description_list:
| screen_description_list
;

screen_description_list:
  screen_description TOK_DOT
| screen_description_list
  screen_description TOK_DOT
;

screen_description:
  constant_entry
| level_number entry_name
  {
	cb_tree	x;
	int	flags;

	x = cb_build_field_tree ($1, $2, current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ($1);
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
  screen_options
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
| level_number error TOK_DOT
  {
	/* Free tree assocated with level number */
	cobc_parse_free ($1);
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
;

screen_options:
| screen_options screen_option
;

screen_option:
  BLANK LINE
  {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
| BLANK SCREEN
  {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
| BELL
  {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
| BLINK
  {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
| ERASE EOL
  {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
| ERASE EOS
  {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
| HIGHLIGHT
  {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
| LOWLIGHT
  {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
| REVERSE_VIDEO
  {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
| UNDERLINE
  {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
| OVERLINE
  {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
| LEFTLINE
  {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
| AUTO
  {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
| SECURE
  {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
| REQUIRED
  {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
| FULL
  {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
| PROMPT CHARACTER _is id_or_lit
  {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = $4;
  }
| PROMPT
  {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
| TOK_INITIAL
  {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
| LINE _number _is screen_line_plus_minus num_id_or_lit
  {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = $5;
  }
| column_or_col _number _is screen_col_plus_minus num_id_or_lit
  {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = $5;
  }
| FOREGROUND_COLOR _is num_id_or_lit
  {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = $3;
  }
| BACKGROUND_COLOR _is num_id_or_lit
  {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = $3;
  }
| usage_clause
| blank_clause
| global_screen_opt
| justified_clause
| sign_clause
| value_clause
| picture_clause
| screen_occurs_clause
| USING identifier
  {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = $2;
	current_field->screen_to = $2;
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
| FROM id_or_lit_or_func
  {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = $2;
  }
| TO identifier
  {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = $2;
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
;

plus_plus:
  PLUS
| TOK_PLUS
;

minus_minus:
  MINUS
| TOK_MINUS
;

screen_line_plus_minus:
  /* empty */
  {
	/* Nothing */
  }
| plus_plus
  {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
| minus_minus
  {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
;

screen_col_plus_minus:
  /* empty */
  {
	/* Nothing */
  }
| plus_plus
  {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
| minus_minus
  {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
;


screen_occurs_clause:
  OCCURS integer _times
  {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ($2);
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
;

global_screen_opt:
  _is GLOBAL
  {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
;

/* PROCEDURE DIVISION */

procedure_division:
| PROCEDURE DIVISION procedure_using_chaining procedure_returning TOK_DOT
  {
	current_section = NULL;
	current_paragraph = NULL;
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	cb_set_system_names ();
	header_check |= COBC_HD_PROCEDURE_DIVISION;
  }
  procedure_declaratives
  {
	if (current_program->flag_main && !current_program->flag_chained && $3) {
		cb_error (_("Executable program requested but PROCEDURE/ENTRY has USING clause"));
	}
	/* Main entry point */
	emit_entry (current_program->program_id, 0, $3);
	current_program->num_proc_params = cb_list_length ($3);
	if (current_program->source_name) {
		emit_entry (current_program->source_name, 1, $3);
	}
  }
  procedure_list
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
|
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
  statements TOK_DOT procedure_list
;

procedure_using_chaining:
  /* empty */
  {
	$$ = NULL;
  }
| USING
  {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
  procedure_param_list
  {
	if (cb_list_length ($3) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	$$ = $3;
  }
| CHAINING
  {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
  procedure_param_list
  {
	if (cb_list_length ($3) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	$$ = $3;
  }
;

procedure_param_list:
  procedure_param		{ $$ = $1; }
| procedure_param_list
  procedure_param		{ $$ = cb_list_append ($1, $2); }
;

procedure_param:
  procedure_type size_optional procedure_optional WORD
  {
	$$ = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ($4, 0));
	CB_SIZES ($$) = size_mode;
  }
;

procedure_type:
  /* empty */
| _by REFERENCE
  {
	call_mode = CB_CALL_BY_REFERENCE;
  }
| _by VALUE
  {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
;

size_optional:
  /* empty */
| SIZE _is AUTO
  {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
| SIZE _is DEFAULT
  {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
| UNSIGNED SIZE _is AUTO
  {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
| UNSIGNED SIZE _is integer
  {
	unsigned char *s = CB_LITERAL ($4)->data;

	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else if (CB_LITERAL ($4)->size != 1) {
		cb_error_x ($4, _("Invalid value for SIZE"));
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
			cb_error_x ($4, _("Invalid value for SIZE"));
			break;
		}
	}
  }
| SIZE _is integer
  {
	unsigned char *s = CB_LITERAL ($3)->data;

	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else if (CB_LITERAL ($3)->size != 1) {
		cb_error_x ($3, _("Invalid value for SIZE"));
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
			cb_error_x ($3, _("Invalid value for SIZE"));
			break;
		}
	}
  }
;

procedure_optional:
  /* empty */
| OPTIONAL
  {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
;

procedure_returning:
  /* empty */
  {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
| RETURNING WORD
  {
	struct cb_field	*f;

	if (cb_ref ($2) != cb_error_node) {
		f = CB_FIELD_PTR ($2);
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
			current_program->returning = $2;
		}
	}
  }
;

procedure_declaratives:
| DECLARATIVES TOK_DOT
  {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
  procedure_list
  END DECLARATIVES TOK_DOT
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
;


/* Procedure list */

procedure_list:
| procedure_list procedure
;

procedure:
  section_header
| paragraph_header
| statements TOK_DOT
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
| invalid_statement %prec SHIFT_PREFER
| TOK_DOT
  {
	/* check_unreached = 0; */
  }
;


/* Section/Paragraph */

section_header:
  WORD SECTION opt_segment TOK_DOT
  {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ($1, 0) == cb_error_node) {
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
	current_section = CB_LABEL (cb_build_label ($1, NULL));
	if ($3) {
		current_section->segment = cb_get_int ($3);
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
  opt_use_statement
  {
	emit_statement (CB_TREE (current_section));
  }
;

opt_use_statement:
| use_statement TOK_DOT
;

paragraph_header:
  WORD TOK_DOT
  {
	cb_tree label;

	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ($1, 1) == cb_error_node) {
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
	current_paragraph = CB_LABEL (cb_build_label ($1, current_section));
	current_paragraph->flag_declaratives =!! in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_real_label = !in_debugging;
	current_paragraph->segment = current_section->segment;
	CB_TREE (current_paragraph)->source_file = cb_source_file;
	CB_TREE (current_paragraph)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_paragraph));
  }
;

invalid_statement:
  WORD
  {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ($1, 0) != cb_error_node) {
		cb_error_x ($1, _("Unknown statement '%s'"), CB_NAME ($1));
	}
	YYERROR;
  }
;

opt_segment:
  /* empty */
  {
	$$ = NULL;
  }
| integer
  {
	if (in_declaratives) {
		cb_error (_("SECTION segment invalid within DECLARATIVE"));
	}
	if (cb_verify (cb_section_segments, "SECTION segment")) {
		current_program->flag_segments = 1;
		$$ = $1;
	} else {
		$$ = NULL;
	}
  }
;


/* Statements */

statement_list:
  %prec SHIFT_PREFER
  {
	$$ = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
  {
	$$ = CB_TREE (current_statement);
	current_statement = NULL;
  }
  statements
  {
	$$ = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = $1;
	current_statement = CB_STATEMENT ($2);
  }
;

statements:
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
  statement
  {
	cobc_cs_check = 0;
  }
| statements statement
  {
	cobc_cs_check = 0;
  }
;

statement:
  accept_statement
| add_statement
| allocate_statement
| alter_statement
| call_statement
| cancel_statement
| close_statement
| commit_statement
| compute_statement
| continue_statement
| delete_statement
| display_statement
| divide_statement
| entry_statement
| evaluate_statement
| exit_statement
| free_statement
| generate_statement
| goto_statement
| goback_statement
| if_statement
| initialize_statement
| initiate_statement
| inspect_statement
| merge_statement
| move_statement
| multiply_statement
| open_statement
| perform_statement
| read_statement
| ready_statement
| release_statement
| reset_statement
| return_statement
| rewrite_statement
| rollback_statement
| search_statement
| set_statement
| sort_statement
| start_statement
| stop_statement
| string_statement
| subtract_statement
| suppress_statement
| terminate_statement
| transform_statement
| unlock_statement
| unstring_statement
| write_statement
| %prec SHIFT_PREFER NEXT SENTENCE
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
| error error_stmt_recover
  {
	yyerrok;
	cobc_cs_check = 0;
  }
;


/* ACCEPT statement */

accept_statement:
  ACCEPT
  {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  }
  accept_body
  end_accept
;

accept_body:
  accp_identifier opt_at_line_column opt_at_from
  opt_at_block opt_accp_attr on_accp_exception
  {
	cobc_cs_check = 0;
	cb_emit_accept ($1, $2, current_statement->attr_ptr);
  }
| identifier FROM lines_or_number
  {
	cb_emit_accept_line_or_col ($1, 0);
  }
| identifier FROM columns_or_cols
  {
	cb_emit_accept_line_or_col ($1, 1);
  }
| identifier FROM DATE YYYYMMDD
  {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ($1);
  }
| identifier FROM DATE
  {
	cobc_cs_check = 0;
	cb_emit_accept_date ($1);
  }
| identifier FROM DAY YYYYDDD
  {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ($1);
  }
| identifier FROM DAY
  {
	cobc_cs_check = 0;
	cb_emit_accept_day ($1);
  }
| identifier FROM DAY_OF_WEEK
  {
	cb_emit_accept_day_of_week ($1);
  }
| identifier FROM ESCAPE KEY
  {
	cb_emit_accept_escape_key ($1);
  }
| identifier FROM EXCEPTION STATUS
  {
	cb_emit_accept_exception_status ($1);
  }
| identifier FROM TIME
  {
	cb_emit_accept_time ($1);
  }
| identifier FROM USER NAME
  {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ($1);
  }
| identifier FROM COMMAND_LINE
  {
	cb_emit_accept_command_line ($1);
  }
| identifier FROM ENVIRONMENT_VALUE on_accp_exception
  {
	cb_emit_accept_environment ($1);
  }
| identifier FROM ENVIRONMENT simple_value on_accp_exception
  {
	cb_emit_get_environment ($4, $1);
  }
| identifier FROM ARGUMENT_NUMBER
  {
	cb_emit_accept_arg_number ($1);
  }
| identifier FROM ARGUMENT_VALUE on_accp_exception
  {
	cb_emit_accept_arg_value ($1);
  }
| identifier FROM mnemonic_name
  {
	cb_emit_accept_mnemonic ($1, $3);
  }
| identifier FROM WORD
  {
	cb_emit_accept_name ($1, $3);
  }
;

accp_identifier:
  identifier
| OMITTED
  {
	$$ = cb_null;
  }
;

lines_or_number:
  LINES
| LINE NUMBER
;

opt_at_line_column:
  /* empty */			{ $$ = NULL; }
| at_line_column		{ $$ = $1; }
;

at_line_column:
  _at line_number column_number { $$ = CB_BUILD_PAIR ($2, $3); }
| _at column_number line_number { $$ = CB_BUILD_PAIR ($3, $2); }
| _at line_number		{ $$ = CB_BUILD_PAIR ($2, cb_int0); }
| _at column_number		{ $$ = CB_BUILD_PAIR (cb_int0, $2); }
| AT simple_value		{ $$ = $2; }
;

line_number:
  LINE _number num_id_or_lit		{ $$ = $3; }
;

column_number:
  column_or_col _number num_id_or_lit	{ $$ = $3; }
| POSITION _number num_id_or_lit	{ $$ = $3; }
;

opt_at_from:
| FROM_CRT
;

opt_at_block:
| MODE _is BLOCK
  {
	cobc_cs_check = 0;
  }
;

opt_accp_attr:
| WITH accp_attrs
;

accp_attrs:
  accp_attr
| accp_attrs accp_attr
;

accp_attr:
  AUTO
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
| BELL
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
| BLINK
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
| CONVERSION
  {
	cb_warning (_("Ignoring CONVERSION"));
  }
| FULL
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
| HIGHLIGHT
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
| LEFTLINE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
| LOWER
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
| LOWLIGHT
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
| NO_ECHO
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
| OVERLINE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
| PROMPT CHARACTER _is id_or_lit
  {
	check_attribs (NULL, NULL, NULL, NULL, $4, COB_SCREEN_PROMPT);
  }
| PROMPT
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
| REQUIRED
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
| REVERSE_VIDEO
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
| SECURE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
| UNDERLINE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
| UPDATE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
| UPPER
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
| FOREGROUND_COLOR _is num_id_or_lit
  {
	check_attribs ($3, NULL, NULL, NULL, NULL, 0);
  }
| BACKGROUND_COLOR _is num_id_or_lit
  {
	check_attribs (NULL, $3, NULL, NULL, NULL, 0);
  }
| SCROLL UP _opt_scroll_lines
  {
	check_attribs (NULL, NULL, $3, NULL, NULL, 0);
  }
| SCROLL DOWN _opt_scroll_lines
  {
	check_attribs (NULL, NULL, $3, NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
| TIMEOUT _after positive_id_or_lit
  {
	check_attribs (NULL, NULL, NULL, $3, NULL, 0);
  }
;

end_accept:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, ACCEPT);
  }
| END_ACCEPT
  {
	TERMINATOR_CLEAR ($-2, ACCEPT);
  }
;


/* ADD statement */

add_statement:
  ADD
  {
	begin_statement ("ADD", TERM_ADD);
  }
  add_body
  end_add
;

add_body:
  x_list TO arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($3, '+', cb_build_binary_list ($1, '+'));
  }
| x_list add_to GIVING arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($4, 0, cb_build_binary_list ($1, '+'));
  }
| CORRESPONDING identifier TO identifier flag_rounded on_size_error
  {
	cb_emit_corresponding (cb_build_add, $4, $2, $5);
  }
;

add_to:
| TO x
  {
	cb_list_add ($0, $2);
  }
;

end_add:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, ADD);
  }
| END_ADD
  {
	TERMINATOR_CLEAR ($-2, ADD);
  }
;


/* ALLOCATE statement */

allocate_statement:
  ALLOCATE
  {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
  allocate_body
;

allocate_body:
  identifier flag_initialized allocate_returning
  {
	cb_emit_allocate ($1, $3, NULL, $2);
  }
| exp CHARACTERS flag_initialized_to allocate_returning
  {
	if ($4 == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, $4, $1, $3);
	}
  }
;

allocate_returning:
  /* empty */			{ $$ = NULL; }
| RETURNING target_x		{ $$ = $2; }
;


/* ALTER statement */

alter_statement:
  ALTER
  {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
  alter_body
;

alter_body:
  alter_entry
| alter_body alter_entry
;

alter_entry:
  procedure_name TO _proceed_to procedure_name
  {
	cb_emit_alter ($1, $4);
  }
;

_proceed_to:	| PROCEED TO ;


/* CALL statement */

call_statement:
  CALL
  {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
  call_body
  end_call
;

call_body:
  mnemonic_conv
  id_or_lit_or_func
  call_using
  call_returning
  call_on_exception
  call_not_on_exception
  {
	if (CB_LITERAL_P ($2) &&
	    current_program->prog_type == CB_PROGRAM_TYPE &&
	    !current_program->flag_recursive &&
	    !strcmp ((const char *)(CB_LITERAL($2)->data), current_program->orig_program_id)) {
		cb_warning_x ($2, _("Recursive program call - assuming RECURSIVE attribute"));
		current_program->flag_recursive = 1;
	}
	cb_emit_call ($2, $3, $4, $5, $6, $1);
  }
;

mnemonic_conv:
  /* empty */
  {
	$$ = NULL;
	cobc_cs_check = 0;
  }
| STATIC
  {
	$$ = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
| STDCALL
  {
	$$ = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
| MNEMONIC_NAME
  {
	cb_tree		x;

	x = cb_ref ($1);
	if (CB_VALID_TREE (x)) {
		if (CB_SYSTEM_NAME(x)->token != CB_FEATURE_CONVENTION) {
			cb_error_x ($1, _("Invalid mnemonic name"));
			$$ = NULL;
		} else {
			$$ = CB_SYSTEM_NAME(x)->value;
		}
	} else {
		$$ = NULL;
	}
	cobc_cs_check = 0;
  }
;

call_using:
  /* empty */
  {
	$$ = NULL;
  }
| USING
  {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
  call_param_list
  {
	if (cb_list_length ($3) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	$$ = $3;
  }
;

call_param_list:
  call_param			{ $$ = $1; }
| call_param_list
  call_param			{ $$ = cb_list_append ($1, $2); }
;

call_param:
  call_type OMITTED
  {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	$$ = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
| call_type size_optional x
  {
	int	save_mode;

	save_mode = call_mode;
	if (call_mode != CB_CALL_BY_REFERENCE) {
		if (CB_FILE_P ($3) || (CB_REFERENCE_P ($3) &&
		    CB_FILE_P (CB_REFERENCE ($3)->value))) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid file name reference"));
		} else if (call_mode == CB_CALL_BY_VALUE) {
			if (cb_category_is_alpha ($3)) {
				cb_warning_x ($3,
					      _("BY CONTENT assumed for alphanumeric item"));
				save_mode = CB_CALL_BY_CONTENT;
			}
		}
	}
	$$ = CB_BUILD_PAIR (cb_int (save_mode), $3);
	CB_SIZES ($$) = size_mode;
	call_mode = save_mode;
  }
;

call_type:
  /* empty */
| _by REFERENCE
  {
	call_mode = CB_CALL_BY_REFERENCE;
  }
| _by CONTENT
  {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
| _by VALUE
  {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
;

call_returning:
  /* empty */
  {
	$$ = NULL;
  }
| return_give _into identifier
  {
	$$ = $3;
  }
| return_give null_or_omitted
  {
	$$ = cb_null;
  }
| return_give ADDRESS _of identifier
  {
	struct cb_field	*f;

	if (cb_ref ($4) != cb_error_node) {
		f = CB_FIELD_PTR ($4);
		if (f->level != 1 && f->level != 77) {
			cb_error (_("RETURNING item must have level 01 or 77"));
			$$ = NULL;
		} else if (f->storage != CB_STORAGE_LINKAGE &&
			   !f->flag_item_based) {
			cb_error (_("RETURNING item is neither in LINKAGE SECTION nor is it BASED"));
			$$ = NULL;
		} else {
			$$ = cb_build_address ($4);
		}
	} else {
		$$ = NULL;
	}
  }
;

return_give:
  RETURNING
| GIVING
;

null_or_omitted:
  TOK_NULL
| OMITTED
;

call_on_exception:
  /* empty */
  {
	$$ = NULL;
  }
| exception_or_overflow
  statement_list
  {
	$$ = $2;
  }
;

call_not_on_exception:
  /* empty */	%prec SHIFT_PREFER
  {
	$$ = NULL;
  }
| NOT_EXCEPTION
  statement_list
  {
	$$ = $2;
  }
;

end_call:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, CALL);
  }
| END_CALL
  {
	TERMINATOR_CLEAR ($-2, CALL);
  }
;


/* CANCEL statement */

cancel_statement:
  CANCEL
  {
	begin_statement ("CANCEL", 0);
  }
  cancel_body
;

cancel_body:
  id_or_lit
  {
	cb_emit_cancel ($1);
  }
| cancel_body id_or_lit
  {
	cb_emit_cancel ($2);
  }
;


/* CLOSE statement */

close_statement:
  CLOSE
  {
	begin_statement ("CLOSE", 0);
  }
  close_body
;

close_body:
  file_name close_option
  {
	begin_implicit_statement ();
	cb_emit_close ($1, $2);
  }
| close_body file_name close_option
  {
	begin_implicit_statement ();
	cb_emit_close ($2, $3);
  }
;

close_option:
  /* empty */			{ $$ = cb_int (COB_CLOSE_NORMAL); }
| reel_or_unit			{ $$ = cb_int (COB_CLOSE_UNIT); }
| reel_or_unit _for REMOVAL	{ $$ = cb_int (COB_CLOSE_UNIT_REMOVAL); }
| _with NO REWIND		{ $$ = cb_int (COB_CLOSE_NO_REWIND); }
| _with LOCK			{ $$ = cb_int (COB_CLOSE_LOCK); }
;


/* COMPUTE statement */

compute_statement:
  COMPUTE
  {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
  compute_body
  end_compute
;

compute_body:
  arithmetic_x_list comp_equal exp on_size_error
  {
	cb_emit_arithmetic ($1, 0, $3);
  }
;

end_compute:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, COMPUTE);
  }
| END_COMPUTE
  {
	TERMINATOR_CLEAR ($-2, COMPUTE);
  }
;


/* COMMIT statement */

commit_statement:
  COMMIT
  {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
;


/* CONTINUE statement */

continue_statement:
  CONTINUE
  {
	size_t	save_unreached;

	/* Do not check unreached for CONTINUE */
	save_unreached = check_unreached;
	check_unreached = 0;
	begin_statement ("CONTINUE", 0);
	cb_emit_continue ();
	check_unreached = (unsigned int) save_unreached;
  }
;


/* DELETE statement */

delete_statement:
  DELETE
  {
	begin_statement ("DELETE", TERM_DELETE);
  }
  delete_body
  end_delete
;

delete_body:
  file_name _record invalid_key
  {
	cb_emit_delete ($1);
  }
| TOK_FILE delete_file_list
;

delete_file_list:
  file_name
  {
	begin_implicit_statement ();
	cb_emit_delete_file ($1);
  }
| delete_file_list file_name
  {
	begin_implicit_statement ();
	cb_emit_delete_file ($2);
  }
;

end_delete:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, DELETE);
  }
| END_DELETE
  {
	TERMINATOR_CLEAR ($-2, DELETE);
  }
;


/* DISPLAY statement */

display_statement:
  DISPLAY
  {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
  display_body
  end_display
;

display_body:
  id_or_lit UPON_ENVIRONMENT_NAME on_disp_exception
  {
	cb_emit_env_name ($1);
  }
| id_or_lit UPON_ENVIRONMENT_VALUE on_disp_exception
  {
	cb_emit_env_value ($1);
  }
| id_or_lit UPON_ARGUMENT_NUMBER on_disp_exception
  {
	cb_emit_arg_number ($1);
  }
| id_or_lit UPON_COMMAND_LINE on_disp_exception
  {
	cb_emit_command_line ($1);
  }
| x_list display_upon with_no_adv_clause on_disp_exception
  {
	cb_emit_display ($1, $2, $3, NULL, NULL);
  }
| display_list on_disp_exception
| x WITH disp_attrs on_disp_exception
  {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ($1), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
;

display_list:
  display_atom
| display_list
  {
	begin_implicit_statement ();
  }
  display_atom
;

display_atom:
  x at_line_column display_upon_crt opt_at_block with_clause
  {
	cb_emit_display (CB_LIST_INIT ($1), cb_null, cb_int1,
			 $2, current_statement->attr_ptr);
  }
;

display_upon:
  /* empty */
  {
	if (current_program->flag_console_is_crt) {
		$$ = cb_null;
	} else {
		$$ = cb_int0;
	}
  }
| UPON mnemonic_name
  {
	$$ = cb_build_display_mnemonic ($2);
  }
| UPON WORD
  {
	$$ = cb_build_display_name ($2);
  }
| UPON PRINTER
  {
	$$ = cb_int0;
  }
| UPON CRT
  {
	if (current_program->flag_console_is_crt) {
		$$ = cb_null;
	} else {
		$$ = cb_int0;
	}
  }
;

display_upon_crt:
  /* empty */
| UPON crt_under
;

crt_under:
  CRT
| CRT_UNDER
;

with_clause:
  /* empty */
| WITH disp_attrs
  {
	cobc_cs_check = 0;
  }
;

with_no_adv_clause:
  /* empty */			{ $$ = cb_int1; }
| NO_ADVANCING			{ $$ = cb_int0; }
;

disp_attrs:
  disp_attr
| disp_attrs disp_attr
;


disp_attr:
  BELL
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
| BLANK LINE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
| BLANK SCREEN
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
| BLINK
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
| CONVERSION
  {
	cb_warning (_("Ignoring CONVERSION"));
  }
| ERASE EOL
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
| ERASE EOS
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
| HIGHLIGHT
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
| LOWLIGHT
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
| OVERLINE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
| REVERSE_VIDEO
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
| UNDERLINE
  {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
| FOREGROUND_COLOR _is num_id_or_lit
  {
	check_attribs ($3, NULL, NULL, NULL, NULL, 0);
  }
| BACKGROUND_COLOR _is num_id_or_lit
  {
	check_attribs (NULL, $3, NULL, NULL, NULL, 0);
  }
| SCROLL UP _opt_scroll_lines
  {
	check_attribs (NULL, NULL, $3, NULL, NULL, 0);
  }
| SCROLL DOWN _opt_scroll_lines
  {
	check_attribs (NULL, NULL, $3, NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
;

end_display:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, DISPLAY);
  }
| END_DISPLAY
  {
	TERMINATOR_CLEAR ($-2, DISPLAY);
  }
;


/* DIVIDE statement */

divide_statement:
  DIVIDE
  {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
  divide_body
  end_divide
;

divide_body:
  x INTO arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($3, '/', $1);
  }
| x INTO x GIVING arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($5, 0, cb_build_binary_op ($3, '/', $1));
  }
| x BY x GIVING arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($5, 0, cb_build_binary_op ($1, '/', $3));
  }
| x INTO x GIVING arithmetic_x REMAINDER arithmetic_x on_size_error
  {
	cb_emit_divide ($3, $1, $5, $7);
  }
| x BY x GIVING arithmetic_x REMAINDER arithmetic_x on_size_error
  {
	cb_emit_divide ($1, $3, $5, $7);
  }
;

end_divide:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, DIVIDE);
  }
| END_DIVIDE
  {
	TERMINATOR_CLEAR ($-2, DIVIDE);
  }
;


/* ENTRY statement */

entry_statement:
  ENTRY
  {
	begin_statement ("ENTRY", 0);
  }
  entry_body
;

entry_body:
  LITERAL call_using
  {
	if (current_program->nested_level) {
		cb_error (_("ENTRY is invalid in nested program"));
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("ENTRY is invalid in a user FUNCTION"));
	} else if (cb_verify (cb_entry_statement, "ENTRY")) {
		if (!cobc_check_valid_name ((char *)(CB_LITERAL ($1)->data), 1U)) {
			emit_entry ((char *)(CB_LITERAL ($1)->data), 1, $2);
		}
	}
	check_unreached = 0;
  }
;


/* EVALUATE statement */

evaluate_statement:
  EVALUATE
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
  evaluate_body
  end_evaluate
;

evaluate_body:
  evaluate_subject_list evaluate_condition_list
  {
	cb_emit_evaluate ($1, $2);
	eval_level--;
  }
;

evaluate_subject_list:
  evaluate_subject		{ $$ = CB_LIST_INIT ($1); }
| evaluate_subject_list ALSO
  evaluate_subject		{ $$ = cb_list_add ($1, $3); }
;

evaluate_subject:
  expr
  {
	$$ = $1;
	eval_check[eval_level][eval_inc++] = $1;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
| TOK_TRUE
  {
	$$ = cb_true;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
| TOK_FALSE
  {
	$$ = cb_false;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
;

evaluate_condition_list:
  evaluate_case_list evaluate_other
  {
	$$ = cb_list_add ($1, $2);
  }
| evaluate_case_list %prec SHIFT_PREFER
  {
	$$ = $1;
  }
;

evaluate_case_list:
  evaluate_case			{ $$ = CB_LIST_INIT ($1); }
| evaluate_case_list
  evaluate_case			{ $$ = cb_list_add ($1, $2); }
;

evaluate_case:
  evaluate_when_list
  statement_list
  {
	$$ = CB_BUILD_CHAIN ($2, $1);
	eval_inc2 = 0;
  }
;

evaluate_other:
  WHEN OTHER
  statement_list
  {
	$$ = CB_BUILD_CHAIN ($3, NULL);
	eval_inc2 = 0;
  }
;

evaluate_when_list:
  WHEN evaluate_object_list
  {
	$$ = CB_LIST_INIT ($2);
	eval_inc2 = 0;
  }
| evaluate_when_list
  WHEN evaluate_object_list
  {
	$$ = cb_list_add ($1, $3);
	eval_inc2 = 0;
  }
;

evaluate_object_list:
  evaluate_object		{ $$ = CB_LIST_INIT ($1); }
| evaluate_object_list ALSO
  evaluate_object		{ $$ = cb_list_add ($1, $3); }
;

evaluate_object:
  partial_expr opt_evaluate_thru_expr
  {
	cb_tree	not0;
	cb_tree	e1;
	cb_tree	e2;
	cb_tree	x;
	cb_tree	parm1;

	not0 = cb_int0;
	e2 = $2;
	x = NULL;
	parm1 = $1;
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
	$$ = CB_BUILD_PAIR (not0, CB_BUILD_PAIR (e1, e2));
  }
| ANY				{ $$ = cb_any; eval_inc2++; }
| TOK_TRUE			{ $$ = cb_true; eval_inc2++; }
| TOK_FALSE			{ $$ = cb_false; eval_inc2++; }
;

opt_evaluate_thru_expr:
  /* empty */			{ $$ = NULL; }
| THRU expr			{ $$ = $2; }
;

end_evaluate:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, EVALUATE);
  }
| END_EVALUATE
  {
	TERMINATOR_CLEAR ($-2, EVALUATE);
  }
;


/* EXIT statement */

exit_statement:
  EXIT
  {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
  exit_body
  {
	cobc_cs_check = 0;
  }
;

exit_body:
  /* empty */	%prec SHIFT_PREFER
| PROGRAM exit_program_returning
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
	if ($2 != NULL) {
		cb_emit_move ($2, CB_LIST_INIT (current_program->cb_return_code));
	}
	current_statement->name = (const char *)"EXIT PROGRAM";
	cb_emit_exit (0);
  }
| FUNCTION
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
| PERFORM CYCLE
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
| PERFORM
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
| SECTION
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
| PARAGRAPH
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
;

exit_program_returning:
  /* empty */			{ $$ = NULL; }
| return_give x		{ $$ = $2; }
;


/* FREE statement */

free_statement:
  FREE
  {
	begin_statement ("FREE", 0);
  }
  free_body
;

free_body:
  target_x_list
  {
	cb_emit_free ($1);
  }
;


/* GENERATE statement */

generate_statement:
  GENERATE
  {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  }
  generate_body
;


generate_body:
  qualified_word
;

/* GO TO statement */

goto_statement:
  GO
  {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
  go_body
;

go_body:
  _to procedure_name_list goto_depending
  {
	cb_emit_goto ($2, $3);
	start_debug = save_debug;
  }
;

goto_depending:
  /* empty */
  {
	check_unreached = 1;
	$$ = NULL;
  }
| DEPENDING _on identifier
  {
	check_unreached = 0;
	$$ = $3;
  }
;


/* GOBACK statement */

goback_statement:
  GOBACK exit_program_returning
  {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ($2 != NULL) {
		cb_emit_move ($2, CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  }
;


/* IF statement */

if_statement:
  IF
  {
	begin_statement ("IF", TERM_IF);
  }
  condition _then if_else_statements
  end_if
;

if_else_statements:
  statement_list ELSE statement_list
  {
	cb_emit_if ($-1, $1, $3);
  }
| ELSE statement_list
  {
	cb_emit_if ($-1, NULL, $2);
  }
| statement_list %prec SHIFT_PREFER
  {
	cb_emit_if ($-1, $1, NULL);
  }
;

end_if:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-4, IF);
  }
| END_IF
  {
	TERMINATOR_CLEAR ($-4, IF);
  }
;


/* INITIALIZE statement */

initialize_statement:
  INITIALIZE
  {
	begin_statement ("INITIALIZE", 0);
  }
  initialize_body
;

initialize_body:
  target_x_list initialize_filler initialize_value
  initialize_replacing initialize_default
  {
	cb_emit_initialize ($1, $2, $3, $4, $5);
  }
;

initialize_filler:
  /* empty */			{ $$ = NULL; }
| _with FILLER			{ $$ = cb_true; }
;

initialize_value:
  /* empty */			{ $$ = NULL; }
| ALL _to VALUE			{ $$ = cb_true; }
| initialize_category _to VALUE	{ $$ = $1; }
;

initialize_replacing:
  /* empty */
  {
	$$ = NULL;
  }
| REPLACING initialize_replacing_list
  {
	$$ = $2;
  }
;

initialize_replacing_list:
  initialize_replacing_item
  {
	$$ = $1;
  }
| initialize_replacing_list
  initialize_replacing_item
  {
	$$ = cb_list_append ($1, $2);
  }
;

initialize_replacing_item:
  initialize_category _data BY x
  {
	$$ = CB_BUILD_PAIR ($1, $4);
  }
;

initialize_category:
  ALPHABETIC		{ $$ = cb_int (CB_CATEGORY_ALPHABETIC); }
| ALPHANUMERIC		{ $$ = cb_int (CB_CATEGORY_ALPHANUMERIC); }
| NUMERIC		{ $$ = cb_int (CB_CATEGORY_NUMERIC); }
| ALPHANUMERIC_EDITED	{ $$ = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
| NUMERIC_EDITED	{ $$ = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
| NATIONAL		{ $$ = cb_int (CB_CATEGORY_NATIONAL); }
| NATIONAL_EDITED	{ $$ = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
;

initialize_default:
  /* empty */
  {
	$$ = NULL;
  }
| _then _to DEFAULT
  {
	$$ = cb_true;
  }
;

/* INITIATE statement */

initiate_statement:
  INITIATE
  {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
  initiate_body
;

initiate_body:
  report_name
  {
	begin_implicit_statement ();
	if ($1 != cb_error_node) {
	}
  }
| initiate_body report_name
  {
	begin_implicit_statement ();
	if ($2 != cb_error_node) {
	}
  }
;

/* INSPECT statement */

inspect_statement:
  INSPECT
  {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
  inspect_body
;

inspect_body:
  send_identifier inspect_list
;

send_identifier:
  identifier
  {
	$$ = $1;
  }
| literal
  {
	$$ = $1;
  }
| function
  {
	$$ = $1;
  }
;

inspect_list:
  inspect_tallying inspect_replacing
| inspect_tallying
| inspect_replacing
| inspect_converting
;

/* INSPECT TALLYING */

inspect_tallying:
  TALLYING
  {
	cb_init_tallying ();
  }
  tallying_list
  {
	cb_emit_inspect ($0, $3, cb_int0, 0);
	$$ = $0;
  }
;

/* INSPECT REPLACING */

inspect_replacing:
  REPLACING replacing_list
  {
	cb_emit_inspect ($0, $2, cb_int1, 1);
	inspect_keyword = 0;
  }
;

/* INSPECT CONVERTING */

inspect_converting:
  CONVERTING simple_value TO simple_all_value inspect_region
  {
	cb_tree		x;
	x = cb_build_converting ($2, $4, $5);
	cb_emit_inspect ($0, x, cb_int0, 2);
  }
;

tallying_list:
  tallying_item			{ $$ = $1; }
| tallying_list tallying_item	{ $$ = cb_list_append ($1, $2); }
;

tallying_item:
  simple_value FOR		{ $$ = cb_build_tallying_data ($1); }
| CHARACTERS inspect_region	{ $$ = cb_build_tallying_characters ($2); }
| ALL				{ $$ = cb_build_tallying_all (); }
| LEADING			{ $$ = cb_build_tallying_leading (); }
| TRAILING			{ $$ = cb_build_tallying_trailing (); }
| simple_value inspect_region	{ $$ = cb_build_tallying_value ($1, $2); }
;

replacing_list:
  replacing_item		{ $$ = $1; }
| replacing_list replacing_item	{ $$ = cb_list_append ($1, $2); }
;

replacing_item:
  CHARACTERS BY simple_value inspect_region
  {
	$$ = cb_build_replacing_characters ($3, $4);
	inspect_keyword = 0;
  }
| rep_keyword replacing_region
  {
	$$ = $2;
  }
;

rep_keyword:
  /* empty */			{ /* Nothing */ }
| ALL				{ inspect_keyword = 1; }
| LEADING			{ inspect_keyword = 2; }
| FIRST				{ inspect_keyword = 3; }
| TRAILING			{ inspect_keyword = 4; }
;

replacing_region:
  simple_value BY simple_all_value inspect_region
  {
	switch (inspect_keyword) {
		case 1:
			$$ = cb_build_replacing_all ($1, $3, $4);
			break;
		case 2:
			$$ = cb_build_replacing_leading ($1, $3, $4);
			break;
		case 3:
			$$ = cb_build_replacing_first ($1, $3, $4);
			break;
		case 4:
			$$ = cb_build_replacing_trailing ($1, $3, $4);
			break;
		default:
			cb_error_x (CB_TREE (current_statement),
				    _("INSPECT missing a keyword"));
			$$ = cb_build_replacing_all ($1, $3, $4);
			break;
	}
  }
;

/* INSPECT BEFORE/AFTER */

inspect_region:
  /* empty */
  {
	$$ = cb_build_inspect_region_start ();
  }
| inspect_region inspect_before_after
  {
	$$ = $2;
  }
;

inspect_before_after:
  BEFORE _initial x
  {
	$$ = cb_list_add ($0, CB_BUILD_FUNCALL_1 ("cob_inspect_before", $3));
  }
| AFTER _initial x
  {
	$$ = cb_list_add ($0, CB_BUILD_FUNCALL_1 ("cob_inspect_after", $3));
  }
;

/* MERGE statement */

merge_statement:
  MERGE
  {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
  sort_body
;


/* MOVE statement */

move_statement:
  MOVE
  {
	begin_statement ("MOVE", 0);
  }
  move_body
;

move_body:
  x TO target_x_list
  {
	cb_emit_move ($1, $3);
  }
| CORRESPONDING x TO target_x_list
  {
	cb_emit_move_corresponding ($2, $4);
  }
;


/* MULTIPLY statement */

multiply_statement:
  MULTIPLY
  {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
  multiply_body
  end_multiply
;

multiply_body:
  x BY arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($3, '*', $1);
  }
| x BY x GIVING arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($5, 0, cb_build_binary_op ($1, '*', $3));
  }
;

end_multiply:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, MULTIPLY);
  }
| END_MULTIPLY
  {
	TERMINATOR_CLEAR ($-2, MULTIPLY);
  }
;


/* OPEN statement */

open_statement:
  OPEN
  {
	begin_statement ("OPEN", 0);
  }
  open_body
;

open_body:
  open_mode open_sharing file_name_list open_option
  {
	cb_tree l;
	cb_tree x;

	if ($2 && $4) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	if ($4) {
		x = $4;
	} else {
		x = $2;
	}
	for (l = $3; l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), $1, x);
		}
	}
  }
| open_body open_mode open_sharing file_name_list open_option
  {
	cb_tree l;
	cb_tree x;

	if ($3 && $5) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	if ($5) {
		x = $5;
	} else {
		x = $3;
	}
	for (l = $4; l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), $2, x);
		}
	}
  }
;

open_mode:
  INPUT				{ $$ = cb_int (COB_OPEN_INPUT); }
| OUTPUT			{ $$ = cb_int (COB_OPEN_OUTPUT); }
| I_O				{ $$ = cb_int (COB_OPEN_I_O); }
| EXTEND			{ $$ = cb_int (COB_OPEN_EXTEND); }
;

open_sharing:
  /* empty */			{ $$ = NULL; }
| SHARING _with open_sharing_option	{ $$ = $3; }
;


open_sharing_option:
  ALL _other                    { $$ = cb_int (COB_SHARE_ALL); }
| NO _other                     { $$ = cb_int (COB_SHARE_EXCLUSIVE); }
| READ ONLY                     { $$ = cb_int (COB_SHARE_READ_ONLY); }
;



open_option:
  /* empty */			{ $$ = NULL; }
| _with NO REWIND		{ $$ = NULL; }
| _with LOCK			{ $$ = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
| REVERSED
  {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	$$ = NULL;
  }
;


/* PERFORM statement */

perform_statement:
  PERFORM
  {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
  perform_body
;

perform_body:
  perform_procedure perform_option
  {
	cb_emit_perform ($2, $1);
	start_debug = save_debug;
  }
| perform_option
  {
	CB_ADD_TO_CHAIN ($1, perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
  statement_list end_perform
  {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ($1, $3);
  }
| perform_option term_or_dot
  {
	cb_emit_perform ($1, NULL);
	start_debug = save_debug;
  }
;

end_perform:
  /* empty */	%prec SHIFT_PREFER
  {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ($-4, PERFORM);
	} else {
		TERMINATOR_ERROR ($-4, PERFORM);
	}
  }
| END_PERFORM
  {
	TERMINATOR_CLEAR ($-4, PERFORM);
  }
;

term_or_dot:
  END_PERFORM
  {
	TERMINATOR_CLEAR ($-2, PERFORM);
  }
| TOK_DOT
  {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ($-2, PERFORM);
	} else {
		TERMINATOR_ERROR ($-2, PERFORM);
	}
	/* Put the dot token back into the stack for reparse */
	cb_unput_dot ();
  }
;

perform_procedure:
  procedure_name
  {
	/* Return from $1 */
	CB_REFERENCE ($1)->length = cb_true;
	CB_REFERENCE ($1)->flag_decl_ok = 1;
	$$ = CB_BUILD_PAIR ($1, $1);
  }
| procedure_name THRU procedure_name
  {
	/* Return from $3 */
	CB_REFERENCE ($3)->length = cb_true;
	CB_REFERENCE ($1)->flag_decl_ok = 1;
	CB_REFERENCE ($3)->flag_decl_ok = 1;
	$$ = CB_BUILD_PAIR ($1, $3);
  }
;

perform_option:
  /* empty */
  {
	$$ = cb_build_perform_once (NULL);
  }
| id_or_lit_or_func TIMES
  {
	$$ = cb_build_perform_times ($1);
	current_program->loop_counter++;
  }
| FOREVER
  {
	$$ = cb_build_perform_forever (NULL);
  }
| perform_test UNTIL cond_or_exit
  {
	cb_tree varying;

	if (!$3) {
		$$ = cb_build_perform_forever (NULL);
	} else {
		varying = CB_LIST_INIT (cb_build_perform_varying (NULL, NULL, NULL, $3));
		$$ = cb_build_perform_until ($1, varying);
	}
  }
| perform_test VARYING perform_varying_list
  {
	$$ = cb_build_perform_until ($1, $3);
  }
;

perform_test:
  /* empty */			{ $$ = CB_BEFORE; }
| _with TEST before_or_after	{ $$ = $3; }
;

cond_or_exit:
  EXIT				{ $$ = NULL; }
| condition			{ $$ = $1; }

perform_varying_list:
  perform_varying		{ $$ = CB_LIST_INIT ($1); }
| perform_varying_list AFTER
  perform_varying		{ $$ = cb_list_add ($1, $3); }
;

perform_varying:
  identifier FROM x BY x UNTIL condition
  {
	$$ = cb_build_perform_varying ($1, $3, $5, $7);
  }
;


/* READ statement */

read_statement:
  READ
  {
	begin_statement ("READ", TERM_READ);
  }
  read_body
  end_read
;

read_body:
  file_name flag_next _record read_into with_lock read_key read_handler
  {
	if (CB_VALID_TREE ($1)) {
		struct cb_file	*cf;

		cf = CB_FILE(cb_ref ($1));
		if ($5 && (cf->lock_mode & COB_LOCK_AUTOMATIC)) {
			cb_error_x (CB_TREE (current_statement),
				    _("LOCK clause invalid with file LOCK AUTOMATIC"));
		} else if ($6 &&
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
			cb_emit_read ($1, $2, $4, $6, $5);
		}
	}
  }
;

read_into:
  /* empty */			{ $$ = NULL; }
| INTO identifier		{ $$ = $2; }
;

with_lock:
  /* empty */
  {
	$$ = NULL;
  }
| IGNORING LOCK
  {
	$$ = cb_int3;
  }
| _with LOCK
  {
	$$ = cb_int1;
  }
| _with KEPT LOCK
  {
	$$ = cb_int1;
  }
| _with NO LOCK
  {
	$$ = cb_int2;
  }
| _with IGNORE LOCK
  {
	$$ = cb_int3;
  }
| _with WAIT
  {
	$$ = cb_int4;
  }
;

read_key:
  /* empty */			{ $$ = NULL; }
| KEY _is identifier		{ $$ = $3; }
;

read_handler:
  invalid_key
| at_end
;

end_read:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, READ);
  }
| END_READ
  {
	TERMINATOR_CLEAR ($-2, READ);
  }
;


/* READY TRACE statement */

ready_statement:
  READY_TRACE
  {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
;

/* RELEASE statement */

release_statement:
  RELEASE
  {
	begin_statement ("RELEASE", 0);
  }
  release_body
;

release_body:
  record_name from_option
  {
	cb_emit_release ($1, $2);
  }
;


/* RESET TRACE statement */

reset_statement:
  RESET_TRACE
  {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
;

/* RETURN statement */

return_statement:
  RETURN
  {
	begin_statement ("RETURN", TERM_RETURN);
  }
  return_body
  end_return
;

return_body:
  file_name _record read_into return_at_end
  {
	cb_emit_return ($1, $3);
  }
;

end_return:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, RETURN);
  }
| END_RETURN
  {
	TERMINATOR_CLEAR ($-2, RETURN);
  }
;


/* REWRITE statement */

rewrite_statement:
  REWRITE
  {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
  rewrite_body
  end_rewrite
;

rewrite_body:
  record_name from_option write_lock invalid_key
  {
	cb_emit_rewrite ($1, $2, $3);
	start_debug = save_debug;
  }
;

write_lock:
  /* empty */
  {
	$$ = NULL;
  }
| _with LOCK
  {
	$$ = cb_int1;
  }
| _with NO LOCK
  {
	$$ = cb_int2;
  }
;

end_rewrite:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, REWRITE);
  }
| END_REWRITE
  {
	TERMINATOR_CLEAR ($-2, REWRITE);
  }
;


/* ROLLBACK statement */

rollback_statement:
  ROLLBACK
  {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
;


/* SEARCH statement */

search_statement:
  SEARCH
  {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
  search_body
  end_search
;

search_body:
  table_name search_varying search_at_end search_whens
  {
	cb_emit_search ($1, $2, $3, $4);
  }
| ALL table_name search_at_end WHEN expr
  statement_list
  {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ($2, $3, $5, $6);
  }
;

search_varying:
  /* empty */			{ $$ = NULL; }
| VARYING identifier		{ $$ = $2; }
;

search_at_end:
  /* empty */
  {
	$$ = NULL;
  }
| END
  statement_list
  {
	$$ = $2;
  }
;

search_whens:
  search_when	%prec SHIFT_PREFER
  {
	$$ = CB_LIST_INIT ($1);
  }
| search_when search_whens
  {
	$$ = cb_list_add ($2, $1);
  }
;

search_when:
  WHEN condition
  statement_list
  {
	$$ = cb_build_if_check_break ($2, $3);
  }
;

end_search:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, SEARCH);
  }
| END_SEARCH
  {
	TERMINATOR_CLEAR ($-2, SEARCH);
  }
;


/* SET statement */

set_statement:
  SET
  {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
  set_body
  {
	cobc_cs_check = 0;
  }
;

set_body:
  set_environment
| set_attr
| set_to
| set_up_down
| set_to_on_off_sequence
| set_to_true_false_sequence
;

on_or_off:
  ON				{ $$ = cb_int1; }
| OFF				{ $$ = cb_int0; }
;

up_or_down:
  UP				{ $$ = cb_int0; }
| DOWN				{ $$ = cb_int1; }
;

/* SET ENVIRONMENT ... TO ... */

set_environment:
  ENVIRONMENT simple_value TO simple_value
  {
	cb_emit_setenv ($2, $4);
  }
;

/* SET name ATTRIBUTE ... */

set_attr:
  sub_identifier ATTRIBUTE set_attr_clause
  {
	cb_emit_set_attribute ($1, setattr_val_on, setattr_val_off);
  }
;

set_attr_clause:
  set_attr_one
| set_attr_clause set_attr_one
;

set_attr_one:
  BELL on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_BELL);
  }
| BLINK on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_BLINK);
  }
| HIGHLIGHT on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_HIGHLIGHT);
  }
| LOWLIGHT on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_LOWLIGHT);
  }
| REVERSE_VIDEO on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_REVERSE);
  }
| UNDERLINE on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_UNDERLINE);
  }
| LEFTLINE on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_LEFTLINE);
  }
| OVERLINE on_or_off
  {
	bit_set_attr ($2, COB_SCREEN_OVERLINE);
  }
;

/* SET name ... TO expr */

set_to:
  target_x_list TO ENTRY alnum_or_id
  {
	cb_emit_set_to ($1, cb_build_ppointer ($4));
  }
| target_x_list TO x
  {
	cb_emit_set_to ($1, $3);
  }
;

/* SET name ... UP/DOWN BY expr */

set_up_down:
  target_x_list up_or_down BY x
  {
	cb_emit_set_up_down ($1, $2, $4);
  }
;

/* SET mnemonic-name-1 ... TO ON/OFF */

set_to_on_off_sequence:
  set_to_on_off
| set_to_on_off_sequence set_to_on_off
;

set_to_on_off:
  mnemonic_name_list TO on_or_off
  {
	cb_emit_set_on_off ($1, $3);
  }
;

/* SET condition-name-1 ... TO TRUE/FALSE */

set_to_true_false_sequence:
  set_to_true_false
| set_to_true_false_sequence set_to_true_false
;

set_to_true_false:
  target_x_list TO TOK_TRUE
  {
	cb_emit_set_true ($1);
  }
| target_x_list TO TOK_FALSE
  {
	cb_emit_set_false ($1);
  }
;


/* SORT statement */

sort_statement:
  SORT
  {
	begin_statement ("SORT", 0);
  }
  sort_body
;

sort_body:
  sort_identifier sort_key_list sort_duplicates sort_collating
  {
	cb_tree		x;

	x = cb_ref ($1);
	if (CB_VALID_TREE (x)) {
		if (CB_INVALID_TREE ($2)) {
			if (CB_FILE_P (x)) {
				cb_error (_("File sort requires KEY phrase"));
			} else {
				cb_error (_("Table sort without keys not implemented yet"));
			}
			$$ = NULL;
		} else {
			cb_emit_sort_init ($1, $2, $4);
			$$= $1;
		}
	} else {
		$$ = NULL;
	}
  }
  sort_input sort_output
  {
	if ($5 && CB_VALID_TREE ($1)) {
		cb_emit_sort_finish ($1);
	}
  }
;

sort_key_list:
  /* empty */
  {
	$$ = NULL;
  }
| sort_key_list
  _on ascending_or_descending _key opt_key_list
  {
	cb_tree l;
	cb_tree lparm;

	if ($5 == NULL) {
		l = CB_LIST_INIT (NULL);
	} else {
		l = $5;
	}
	lparm = l;
	for (; l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = $3;
	}
	$$ = cb_list_append ($1, lparm);
  }
;

opt_key_list:
  /* empty */			{ $$ = NULL; }
| opt_key_list qualified_word	{ $$ = cb_list_add ($1, $2); }
;

sort_duplicates:
| with_dups _in_order
  {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
;

sort_collating:
  /* empty */				{ $$ = cb_null; }
| coll_sequence _is reference		{ $$ = cb_ref ($3); }
;

sort_input:
  /* empty */
  {
	if ($0 && CB_FILE_P (cb_ref ($0))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
| USING file_name_list
  {
	if ($0) {
		if (!CB_FILE_P (cb_ref ($0))) {
			cb_error (_("USING invalid with table SORT"));
		} else {
			cb_emit_sort_using ($0, $2);
		}
	}
  }
| INPUT PROCEDURE _is perform_procedure
  {
	if ($0) {
		if (!CB_FILE_P (cb_ref ($0))) {
			cb_error (_("INPUT PROCEDURE invalid with table SORT"));
		} else if (current_statement->flag_merge) {
			cb_error (_("INPUT PROCEDURE invalid with MERGE"));
		} else {
			cb_emit_sort_input ($4);
		}
	}
  }
;

sort_output:
  /* empty */
  {
	if ($-1 && CB_FILE_P (cb_ref ($-1))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
| GIVING file_name_list
  {
	if ($-1) {
		if (!CB_FILE_P (cb_ref ($-1))) {
			cb_error (_("GIVING invalid with table SORT"));
		} else {
			cb_emit_sort_giving ($-1, $2);
		}
	}
  }
| OUTPUT PROCEDURE _is perform_procedure
  {
	if ($-1) {
		if (!CB_FILE_P (cb_ref ($-1))) {
			cb_error (_("OUTPUT PROCEDURE invalid with table SORT"));
		} else {
			cb_emit_sort_output ($4);
		}
	}
  }
;


/* START statement */

start_statement:
  START
  {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
  start_body
  end_start
;

start_body:
  file_name start_key sizelen_clause invalid_key
  {
	if ($3 && !$2) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ($1, start_tree, $2, $3);
	}
  }
;

sizelen_clause:
  /* empty */
  {
	$$ = NULL;
  }
| _with size_or_length exp
  {
	$$ = $3;
  }
;

start_key:
  /* empty */
  {
	$$ = NULL;
  }
| KEY _is start_op identifier
  {
	start_tree = $3;
	$$ = $4;
  }
| FIRST
  {
	start_tree = cb_int (COB_FI);
	$$ = NULL;
  }
| LAST
  {
	start_tree = cb_int (COB_LA);
	$$ = NULL;
  }
;

start_op:
  eq			{ $$ = cb_int (COB_EQ); }
| flag_not gt		{ $$ = cb_int ($1 ? COB_LE : COB_GT); }
| flag_not lt		{ $$ = cb_int ($1 ? COB_GE : COB_LT); }
| flag_not ge		{ $$ = cb_int ($1 ? COB_LT : COB_GE); }
| flag_not le		{ $$ = cb_int ($1 ? COB_GT : COB_LE); }
| disallowed_op		{ $$ = cb_int (COB_NE); }
;

disallowed_op:
  not_equal_op
  {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
;

not_equal_op:
  NOT eq
| NOT_EQUAL
;

end_start:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, START);
  }
| END_START
  {
	TERMINATOR_CLEAR ($-2, START);
  }
;


/* STOP statement */

stop_statement:
  STOP RUN
  {
	begin_statement ("STOP RUN", 0);
  }
  stop_returning
  {
	cb_emit_stop_run ($4);
	check_unreached = 1;
	cobc_cs_check = 0;
  }
| STOP stop_literal
  {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ($2), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
;

stop_returning:
  /* empty */
  {
	$$ = current_program->cb_return_code;
  }
| return_give x
  {
	$$ = $2;
  }
| _with ERROR _status _opt_status
  {
	if ($4) {
		$$ = $4;
	} else {
		$$ = cb_int1;
	}
  }
| _with NORMAL _status _opt_status
  {
	if ($4) {
		$$ = $4;
	} else {
		$$ = cb_int0;
	}
  }
;

_opt_status:
  /* empty */
  {
	$$ = NULL;
  }
| x
  {
	$$ = $1;
  }
;

stop_literal:
  LITERAL			{ $$ = $1; }
| SPACE				{ $$ = cb_space; }
| ZERO				{ $$ = cb_zero; }
| QUOTE				{ $$ = cb_quote; }
;

/* STRING statement */

string_statement:
  STRING
  {
	begin_statement ("STRING", TERM_STRING);
  }
  string_body
  end_string
;

string_body:
  string_item_list INTO identifier opt_with_pointer on_overflow
  {
	cb_emit_string ($1, $3, $4);
  }
;

string_item_list:
  string_item			{ $$ = CB_LIST_INIT ($1); }
| string_item_list string_item	{ $$ = cb_list_add ($1, $2); }
;

string_item:
  x				{ $$ = $1; }
| DELIMITED _by SIZE		{ $$ = CB_BUILD_PAIR (cb_int0, NULL); }
| DELIMITED _by x		{ $$ = CB_BUILD_PAIR ($3, NULL); }
;

opt_with_pointer:
  /* empty */			{ $$ = NULL; }
| _with POINTER _is identifier	{ $$ = $4; }
;

end_string:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, STRING);
  }
| END_STRING
  {
	TERMINATOR_CLEAR ($-2, STRING);
  }
;


/* SUBTRACT statement */

subtract_statement:
  SUBTRACT
  {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
  subtract_body
  end_subtract
;

subtract_body:
  x_list FROM arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($3, '-', cb_build_binary_list ($1, '+'));
  }
| x_list FROM x GIVING arithmetic_x_list on_size_error
  {
	cb_emit_arithmetic ($5, 0, cb_build_binary_list (CB_BUILD_CHAIN ($3, $1), '-'));
  }
| CORRESPONDING identifier FROM identifier flag_rounded on_size_error
  {
	cb_emit_corresponding (cb_build_sub, $4, $2, $5);
  }
;

end_subtract:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, SUBTRACT);
  }
| END_SUBTRACT
  {
	TERMINATOR_CLEAR ($-2, SUBTRACT);
  }
;


/* SUPPRESS statement */

suppress_statement:
  SUPPRESS _printing
  {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  }
;

_printing:
| PRINTING
;

/* TERMINATE statement */

terminate_statement:
  TERMINATE
  {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
  terminate_body
;

terminate_body:
  report_name
  {
	begin_implicit_statement ();
	if ($1 != cb_error_node) {
	}
  }
| terminate_body report_name
  {
	begin_implicit_statement ();
	if ($2 != cb_error_node) {
	}
  }
;

/* TRANSFORM statement */

transform_statement:
  TRANSFORM
  {
	begin_statement ("TRANSFORM", 0);
  }
  transform_body
;

transform_body:
  identifier FROM simple_value TO simple_all_value
  {
	cb_tree		x;

	x = cb_build_converting ($3, $5, cb_build_inspect_region_start ());
	cb_emit_inspect ($1, x, cb_int0, 2);
  }
;


/* UNLOCK statement */

unlock_statement:
  UNLOCK
  {
	begin_statement ("UNLOCK", 0);
  }
  unlock_body
;

unlock_body:
  file_name opt_record
  {
	if (CB_VALID_TREE ($1)) {
		if (CB_FILE (cb_ref ($1))->organization == COB_ORG_SORT) {
			cb_error_x (CB_TREE (current_statement),
				    _("UNLOCK invalid for SORT files"));
		} else {
			cb_emit_unlock ($1);
		}
	}
  }
;

opt_record:
  /* empty */
| RECORD
| RECORDS
;


/* UNSTRING statement */

unstring_statement:
  UNSTRING
  {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
  unstring_body
  end_unstring
;

unstring_body:
  identifier unstring_delimited unstring_into
  opt_with_pointer unstring_tallying on_overflow
  {
	cb_emit_unstring ($1, $2, $3, $4, $5);
  }
;

unstring_delimited:
  /* empty */			{ $$ = NULL; }
| DELIMITED _by
  unstring_delimited_list	{ $$ = $3; }
;

unstring_delimited_list:
  unstring_delimited_item	{ $$ = CB_LIST_INIT ($1); }
| unstring_delimited_list OR
  unstring_delimited_item	{ $$ = cb_list_add ($1, $3); }
;

unstring_delimited_item:
  flag_all simple_value
  {
	$$ = cb_build_unstring_delimited ($1, $2);
  }
;

unstring_into:
  INTO unstring_into_item	{ $$ = CB_LIST_INIT ($2); }
| unstring_into
  unstring_into_item		{ $$ = cb_list_add ($1, $2); }
;

unstring_into_item:
  identifier unstring_into_delimiter unstring_into_count
  {
	$$ = cb_build_unstring_into ($1, $2, $3);
  }
;

unstring_into_delimiter:
  /* empty */			{ $$ = NULL; }
| DELIMITER _in identifier	{ $$ = $3; }
;

unstring_into_count:
  /* empty */			{ $$ = NULL; }
| COUNT _in identifier		{ $$ = $3; }
;

unstring_tallying:
  /* empty */			{ $$ = NULL; }
| TALLYING _in identifier	{ $$ = $3; }
;

end_unstring:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, UNSTRING);
  }
| END_UNSTRING
  {
	TERMINATOR_CLEAR ($-2, UNSTRING);
  }
;


/* USE statement */

use_statement:
  USE
  {
	skip_statements = 0;
	in_debugging = 0;
  }
  use_phrase
;

use_phrase:
  use_file_exception
| use_debugging
| use_reporting
| use_exception
;

use_file_exception:
  use_global _after _standard exception_or_error _procedure
  _on use_file_exception_target
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
;

use_global:
  /* empty */
  {
	use_global_ind = 0;
  }
| GLOBAL
  {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
;

use_file_exception_target:
  file_name_list
  {
	cb_tree		l;

	for (l = $1; l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
| INPUT
  {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
| OUTPUT
  {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
| I_O
  {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
| EXTEND
  {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
;

use_debugging:
  _for DEBUGGING _on debugging_list
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
;

debugging_list:
  debugging_target
| debugging_list debugging_target
;

debugging_target:
  label
  {
	cb_tree		l;
	cb_tree		x;
	cb_tree		z;

	if (current_program->flag_debugging) {
		CB_REFERENCE ($1)->debug_section = current_section;
		CB_REFERENCE ($1)->flag_debug_code = 1;
		CB_REFERENCE ($1)->flag_all_debug = 0;
		z = CB_LIST_INIT ($1);
		current_program->debug_list =
			cb_list_append (current_program->debug_list, z);
		/* Check backward refs to file/data names */
		/* Label refs will be checked later (forward/backward ref) */
		if (CB_WORD_COUNT ($1) > 0) {
			l = CB_VALUE(CB_WORD_ITEMS ($1));
			switch (CB_TREE_TAG (l)) {
			case CB_TAG_FILE:
				CB_FILE (l)->debug_section = current_section;
				CB_FILE (l)->flag_fl_debug = 1;
				break;
			case CB_TAG_FIELD:
				{
					x = cb_ref($1);
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
| ALL PROCEDURES
  {
	if (current_program->flag_debugging) {
		if (current_program->all_procedure) {
			cb_error (_("Duplicate USE DEBUGGING ON ALL PROCEDURES"));
		} else {
			current_program->all_procedure = current_section;
		}
	}
  }
| ALL all_refs qualified_word
  {
	cb_tree		x;

	if (current_program->flag_debugging) {
		/* Reference must be a data item */
		x = cb_ref ($3);
		if (CB_INVALID_TREE (x) || !CB_FIELD_P (x)) {
			cb_error (_("Invalid target for DEBUGGING ALL"));
		} else {
			needs_field_debug = 1;
			CB_FIELD (x)->debug_section = current_section;
			CB_FIELD (x)->flag_field_debug = 1;
			CB_FIELD (x)->flag_all_debug = 1;
			CB_REFERENCE ($3)->debug_section = current_section;
			CB_REFERENCE ($3)->flag_debug_code = 1;
			CB_REFERENCE ($3)->flag_all_debug = 1;
			CB_CHAIN_PAIR (current_program->debug_list, x, $3);
		}
	}
  }
;

all_refs:
| REFERENCES
| REFERENCES OF
| OF
;

use_reporting:
  use_global BEFORE REPORTING identifier
  {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
;

use_exception:
  use_ex_keyw
  {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
;

use_ex_keyw:
  EXCEPTION_CONDITION
| EC
;

/* WRITE statement */

write_statement:
  WRITE
  {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
  write_body
  end_write
;

write_body:
  record_name from_option write_option write_lock write_handler
  {
	if (CB_VALID_TREE ($1)) {
		cb_emit_write ($1, $2, $3, $4);
	}
	start_debug = save_debug;
  }
;

from_option:
  /* empty */			{ $$ = NULL; }
| FROM from_parameter		{ $$ = $2; }
;

write_option:
  /* empty */
  {
	$$ = cb_int0;
  }
| before_or_after _advancing num_id_or_lit _line_or_lines
  {
	$$ = cb_build_write_advancing_lines ($1, $3);
  }
| before_or_after _advancing mnemonic_name
  {
	$$ = cb_build_write_advancing_mnemonic ($1, $3);
  }
| before_or_after _advancing PAGE
  {
	$$ = cb_build_write_advancing_page ($1);
  }
;

before_or_after:
  BEFORE			{ $$ = CB_BEFORE; }
| AFTER				{ $$ = CB_AFTER; }
;

write_handler:
  invalid_key
| at_eop
;

end_write:
  /* empty */	%prec SHIFT_PREFER
  {
	TERMINATOR_WARNING ($-2, WRITE);
  }
| END_WRITE
  {
	TERMINATOR_CLEAR ($-2, WRITE);
  }
;


/* Status handlers */

/* ON EXCEPTION */

on_accp_exception:
  opt_on_accp_exception opt_not_on_accp_exception
;

opt_on_accp_exception:
| EXCEPTION
  statement_list
  {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = $2;
  }
;

opt_not_on_accp_exception:
  %prec SHIFT_PREFER
| NOT_EXCEPTION
  statement_list
  {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = $2;
  }
;

on_disp_exception:
  opt_on_disp_exception opt_not_on_disp_exception
;

opt_on_disp_exception:
| EXCEPTION
  statement_list
  {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = $2;
  }
;

opt_not_on_disp_exception:
  %prec SHIFT_PREFER
| NOT_EXCEPTION
  statement_list
  {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = $2;
  }
;

/* ON SIZE ERROR */

on_size_error:
  opt_on_size_error opt_not_on_size_error
;

opt_on_size_error:
| SIZE_ERROR
  statement_list
  {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = $2;
  }
;

opt_not_on_size_error:
  %prec SHIFT_PREFER
| NOT_SIZE_ERROR
  statement_list
  {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = $2;
  }
;


/* ON OVERFLOW */

on_overflow:
  opt_on_overflow opt_not_on_overflow
;

opt_on_overflow:
  /* empty */
| TOK_OVERFLOW
  statement_list
  {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = $2;
  }
;

opt_not_on_overflow:
  /* empty */
  %prec SHIFT_PREFER
| NOT_OVERFLOW
  statement_list
  {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = $2;
  }
;


/* AT END */

return_at_end:
  at_end_clause not_at_end_clause
| at_end_clause %prec SHIFT_PREFER
;

at_end:
  at_end_clause not_at_end_clause
| at_end_clause %prec SHIFT_PREFER
| not_at_end_clause
;

at_end_clause:
  END
  statement_list
  {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = $2;
  }
;

not_at_end_clause:
  NOT_END
  statement_list
  {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = $2;
  }
;

/* AT EOP */

at_eop:
  at_eop_clause not_at_eop_clause
| at_eop_clause %prec SHIFT_PREFER
| not_at_eop_clause
;

at_eop_clause:
  EOP
  statement_list
  {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = $2;
  }
;

not_at_eop_clause:
  NOT_EOP
  statement_list
  {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = $2;
  }
;

/* INVALID KEY */

invalid_key:
  opt_invalid_key_sentence
  opt_not_invalid_key_sentence
;

opt_invalid_key_sentence:
  /* empty */	%prec SHIFT_PREFER
| INVALID_KEY
  statement_list
  {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = $2;
  }
;

opt_not_invalid_key_sentence:
  /* empty */	%prec SHIFT_PREFER
| NOT_INVALID_KEY
  statement_list
  {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = $2;
  }
;

/* Common Constructs */

_opt_scroll_lines:
  /* empty */	%prec SHIFT_PREFER
  {
	$$ = cb_one;
  }
| pos_num_id_or_lit scroll_line_or_lines
  {
	$$ = $1;
  }
;


/* Expressions */

condition:
  expr
  {
	$$ = cb_build_cond ($1);
  }
;

expr:
  partial_expr
  {
	$$ = cb_build_expr ($1);
  }
;

partial_expr:
  {
	current_expr = NULL;
  }
  expr_tokens
  {
	$$ = cb_list_reverse (current_expr);
  }
;

expr_tokens:
  expr_token
| expr_tokens IS
| expr_tokens expr_token
;

expr_token:
  x
  {
	if (CB_REFERENCE_P ($1) && CB_CLASS_NAME_P (cb_ref ($1))) {
		push_expr ('C', $1);
	} else {
		push_expr ('x', $1);
	}
  }
/* Parentheses */
| TOK_OPEN_PAREN		{ push_expr ('(', NULL); }
| TOK_CLOSE_PAREN		{ push_expr (')', NULL); }
/* Arithmetic operators */
| TOK_PLUS			{ push_expr ('+', NULL); }
| TOK_MINUS			{ push_expr ('-', NULL); }
| TOK_MUL			{ push_expr ('*', NULL); }
| TOK_DIV			{ push_expr ('/', NULL); }
| EXPONENTIATION		{ push_expr ('^', NULL); }
/* Conditional operators */
| eq				{ push_expr ('=', NULL); }
| gt				{ push_expr ('>', NULL); }
| lt				{ push_expr ('<', NULL); }
| ge				{ push_expr (']', NULL); }
| le				{ push_expr ('[', NULL); }
| NOT_EQUAL			{ push_expr ('~', NULL); }
/* Logical operators */
| NOT				{ push_expr ('!', NULL); }
| AND				{ push_expr ('&', NULL); }
| OR				{ push_expr ('|', NULL); }
/* Class condition */
| OMITTED			{ push_expr ('O', NULL); }
| NUMERIC			{ push_expr ('9', NULL); }
| ALPHABETIC			{ push_expr ('A', NULL); }
| ALPHABETIC_LOWER		{ push_expr ('L', NULL); }
| ALPHABETIC_UPPER		{ push_expr ('U', NULL); }
/* Sign condition */
/* ZERO is defined in 'x' */
| POSITIVE			{ push_expr ('P', NULL); }
| NEGATIVE			{ push_expr ('N', NULL); }
;

eq:
  TOK_EQUAL
| EQUAL _to
;

gt:
  TOK_GREATER
| GREATER
;

lt:
  TOK_LESS
| LESS
;

ge:
  GREATER_OR_EQUAL
;

le:
  LESS_OR_EQUAL
;

/* Arithmetic expression */

exp_list:
  exp %prec SHIFT_PREFER
  {
	$$ = CB_LIST_INIT ($1);
  }
| exp_list e_sep exp %prec SHIFT_PREFER
  {
	$$ = cb_list_add ($1, $3);
  }
;

e_sep:
| COMMA_DELIM
| SEMI_COLON
;

exp:
  exp TOK_PLUS exp_term		{ $$ = cb_build_binary_op ($1, '+', $3); }
| exp TOK_MINUS exp_term	{ $$ = cb_build_binary_op ($1, '-', $3); }
| exp_term			{ $$ = $1; }
;

exp_term:
  exp_term TOK_MUL exp_factor	{ $$ = cb_build_binary_op ($1, '*', $3); }
| exp_term TOK_DIV exp_factor	{ $$ = cb_build_binary_op ($1, '/', $3); }
| exp_factor			{ $$ = $1; }
;

exp_factor:
  exp_unary EXPONENTIATION exp_factor
  {
	$$ = cb_build_binary_op ($1, '^', $3);
  }
| exp_unary			{ $$ = $1; }
;

exp_unary:
  TOK_PLUS exp_atom		{ $$ = $2; }
| TOK_MINUS exp_atom		{ $$ = cb_build_binary_op (cb_zero, '-', $2); }
| exp_atom			{ $$ = $1; }

exp_atom:
  TOK_OPEN_PAREN exp TOK_CLOSE_PAREN	{ $$ = $2; }
| arith_x				{ $$ = $1; }
;



/* Names */

/* LINAGE-COUNTER LINE-COUNTER PAGE-COUNTER */

line_linage_page_counter:
  LINAGE_COUNTER
  {
	if (current_linage > 1) {
		cb_error (_("LINAGE-COUNTER must be qualified here"));
		$$ = cb_error_node;
	} else if (current_linage == 0) {
		cb_error (_("Invalid LINAGE-COUNTER usage"));
		$$ = cb_error_node;
	} else {
		$$ = linage_file->linage_ctr;
	}
  }
| LINAGE_COUNTER in_of WORD
  {
	if (CB_FILE_P (cb_ref ($3))) {
		$$ = CB_FILE (cb_ref ($3))->linage_ctr;
	} else {
		cb_error_x ($3, _("'%s' is not a file name"), CB_NAME ($3));
		$$ = cb_error_node;
	}
  }
| LINE_COUNTER
  {
	if (report_count > 1) {
		cb_error (_("LINE-COUNTER must be qualified here"));
		$$ = cb_error_node;
	} else if (report_count == 0) {
		cb_error (_("Invalid LINE-COUNTER usage"));
		$$ = cb_error_node;
	} else {
		$$ = report_instance->line_counter;
	}
  }
| LINE_COUNTER in_of WORD
  {
	if (CB_REPORT_P (cb_ref ($3))) {
		$$ = CB_REPORT (cb_ref ($3))->line_counter;
	} else {
		cb_error_x ($3, _("'%s' is not a report name"), CB_NAME ($3));
		$$ = cb_error_node;
	}
  }
| PAGE_COUNTER
  {
	if (report_count > 1) {
		cb_error (_("PAGE-COUNTER must be qualified here"));
		$$ = cb_error_node;
	} else if (report_count == 0) {
		cb_error (_("Invalid PAGE-COUNTER usage"));
		$$ = cb_error_node;
	} else {
		$$ = report_instance->page_counter;
	}
  }
| PAGE_COUNTER in_of WORD
  {
	if (CB_REPORT_P (cb_ref ($3))) {
		$$ = CB_REPORT (cb_ref ($3))->page_counter;
	} else {
		cb_error_x ($3, _("'%s' is not a report name"), CB_NAME ($3));
		$$ = cb_error_node;
	}
  }
;


/* Data name */

arithmetic_x_list:
  arithmetic_x			{ $$ = $1; }
| arithmetic_x_list
  arithmetic_x			{ $$ = cb_list_append ($1, $2); }
;

arithmetic_x:
  target_x flag_rounded
  {
	$$ = CB_BUILD_PAIR ($2, $1);
  }
;

/* Record name */

record_name:
  qualified_word		{ cb_build_identifier ($1, 0); }
;

/* Table name */

table_name:
  qualified_word
  {
	cb_tree x;

	x = cb_ref ($1);
	if (!CB_FIELD_P (x)) {
		$$ = cb_error_node;
	} else if (!CB_FIELD (x)->index_list) {
		cb_error_x ($1, _("'%s' not indexed"), cb_name ($1));
		cb_error_x (x, _("'%s' defined here"), cb_name (x));
		$$ = cb_error_node;
	} else {
		$$ = $1;
	}
  }
;

/* File name */

file_name_list:
  file_name
  {
	$$ = CB_LIST_INIT ($1);
  }
| file_name_list file_name
  {
	cb_tree		l;

	if (CB_VALID_TREE ($2)) {
		for (l = $1; l; l = CB_CHAIN (l)) {
			if (CB_VALID_TREE (CB_VALUE (l)) &&
			    !strcasecmp (CB_NAME ($2), CB_NAME (CB_VALUE (l)))) {
				cb_error_x ($2, _("Multiple reference to '%s' "),
					    CB_NAME ($2));
				break;
			}
		}
		if (!l) {
			$$ = cb_list_add ($1, $2);
		}
	}
  }
;

file_name:
  WORD
  {
	if (CB_FILE_P (cb_ref ($1))) {
		$$ = $1;
	} else {
		cb_error_x ($1, _("'%s' is not a file name"), CB_NAME ($1));
		$$ = cb_error_node;
	}
  }
;

/* Report name */

/* RXWRXW - Report list
report_name_list:
  report_name
  {
	$$ = CB_LIST_INIT ($1);
  }
| report_name_list report_name
  {
	cb_tree		l;

	if (CB_VALID_TREE ($2)) {
		for (l = $1; l; l = CB_CHAIN (l)) {
			if (CB_VALID_TREE (CB_VALUE (l)) &&
			    !strcasecmp (CB_NAME ($2), CB_NAME (CB_VALUE (l)))) {
				cb_error_x ($2, _("Multiple reference to '%s' "),
					    CB_NAME ($2));
				break;
			}
		}
		if (!l) {
			$$ = cb_list_add ($1, $2);
		}
	}
  }
;
*/

report_name:
  WORD
  {
	if (CB_REPORT_P (cb_ref ($1))) {
		$$ = $1;
	} else {
		cb_error_x ($1, _("'%s' is not a report name"), CB_NAME ($1));
		$$ = cb_error_node;
	}
  }
;

/* Mnemonic name */

mnemonic_name_list:
  mnemonic_name			{ $$ = CB_LIST_INIT ($1); }
| mnemonic_name_list
  mnemonic_name			{ $$ = cb_list_add ($1, $2); }
;

mnemonic_name:
  MNEMONIC_NAME			{ $$ = $1; }
;

/* Procedure name */

procedure_name_list:
  /* empty */			{ $$ = NULL; }
| procedure_name_list
  procedure_name		{ $$ = cb_list_add ($1, $2); }
;

procedure_name:
  label
  {
	$$ = $1;
	CB_REFERENCE ($$)->offset = CB_TREE (current_section);
	CB_REFERENCE ($$)->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ($$)->section = current_section;
	CB_REFERENCE ($$)->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ($$, current_program->label_list);
  }
;

label:
  qualified_word
| integer_label
| integer_label in_of integer_label
  {
	CB_REFERENCE ($1)->chain = $3;
  }
;

integer_label:
  LITERAL
  {
	$$ = cb_build_reference ((char *)(CB_LITERAL ($1)->data));
	$$->source_file = $1->source_file;
	$$->source_line = $1->source_line;
  }
;

/* Reference */

reference_list:
  reference			{ $$ = CB_LIST_INIT ($1); }
| reference_list reference	{ $$ = cb_list_add ($1, $2); }
;

reference:
  qualified_word
  {
	$$ = $1;
	CB_ADD_TO_CHAIN ($$, current_program->reference_list);
  }
;

single_reference:
  WORD
  {
	$$ = $1;
	CB_ADD_TO_CHAIN ($$, current_program->reference_list);
  }
;

opt_reference_list:
  opt_reference
  {
	$$ = CB_LIST_INIT ($1);
  }
| opt_reference_list opt_reference
  {
	$$ = cb_list_add ($1, $2);
  }
;

opt_reference:
  WORD
  {
	$$ = $1;
	CB_REFERENCE($$)->flag_optional = 1;
	CB_ADD_TO_CHAIN ($$, current_program->reference_list);
  }
;

reference_or_literal:
  reference
| LITERAL
;

/* Undefined word */

undefined_word:
  WORD
  {
	if (CB_WORD_COUNT ($1) > 0) {
		redefinition_error ($1);
		$$ = cb_error_node;
	} else {
		$$ = $1;
	}
  }
;

/* Unique word */

unique_word:
  WORD
  {
	if (CB_REFERENCE ($1)->flag_duped || CB_WORD_COUNT ($1) > 0) {
		redefinition_error ($1);
		$$ = NULL;
	} else {
		CB_WORD_COUNT ($1)++;
		$$ = $1;
	}
  }
;

/* Primitive elements */

/* Primitive value */

target_x_list:
  target_x
  {
	$$ = CB_LIST_INIT ($1);
  }
| target_x_list target_x
  {
	$$ = cb_list_add ($1, $2);
  }
;

target_x:
  target_identifier
| basic_literal
| ADDRESS _of identifier_1
  {
	$$ = cb_build_address ($3);
  }
;

x_list:
  x
  {
	$$ = CB_LIST_INIT ($1);
  }
| x_list x
  {
	$$ = cb_list_add ($1, $2);
  }
;

x:
  identifier
| literal
| function
| line_linage_page_counter
| LENGTH_OF identifier_1
  {
	$$ = cb_build_length ($2);
  }
| LENGTH_OF basic_literal
  {
	$$ = cb_build_length ($2);
  }
| LENGTH_OF function
  {
	$$ = cb_build_length ($2);
  }
| ADDRESS _of prog_or_entry alnum_or_id
  {
	$$ = cb_build_ppointer ($4);
  }
| ADDRESS _of identifier_1
  {
	$$ = cb_build_address ($3);
  }
| MNEMONIC_NAME
  {
	cb_tree		x;
	cb_tree		switch_id;

	x = cb_ref ($1);
	if (CB_VALID_TREE (x)) {
		if (CB_SYSTEM_NAME (x)->category != CB_SWITCH_NAME) {
			cb_error_x (x, _("Invalid mnemonic identifier"));
			$$ = cb_error_node;
		} else {
			switch_id = cb_int (CB_SYSTEM_NAME (x)->token);
			$$ = CB_BUILD_FUNCALL_1 ("cob_switch_value", switch_id);
		}
	} else {
		$$ = cb_error_node;
	}
  }
;

report_x_list:
  arith_x
  {
	$$ = CB_LIST_INIT ($1);
  }
| report_x_list arith_x
  {
	$$ = cb_list_add ($1, $2);
  }
;

expr_x:
  identifier
| basic_literal
| function
;

arith_x:
  identifier
| basic_literal
| function
| line_linage_page_counter
| LENGTH_OF identifier_1
  {
	$$ = cb_build_length ($2);
  }
| LENGTH_OF basic_literal
  {
	$$ = cb_build_length ($2);
  }
| LENGTH_OF function
  {
	$$ = cb_build_length ($2);
  }
;

prog_or_entry:
  PROGRAM
| ENTRY
;

alnum_or_id:
  identifier_1
| LITERAL
;

simple_value:
  identifier
| basic_literal
;

simple_all_value:
  identifier
| literal
;

/*
numeric_value:
  identifier
| integer
;
*/

id_or_lit:
  identifier
| LITERAL
;

id_or_lit_or_func:
  identifier
| LITERAL
| function
;

num_id_or_lit:
  sub_identifier
| integer
| ZERO
  {
	$$ = cb_zero;
  }
;

positive_id_or_lit:
  sub_identifier
| report_integer
;

pos_num_id_or_lit:
  sub_identifier
| integer
;

from_parameter:
  identifier
| literal
| function
;

/* Identifier */

sub_identifier:
  sub_identifier_1		{ $$ = cb_build_identifier ($1, 0); }
;

sort_identifier:
  sub_identifier_1		{ $$ = cb_build_identifier ($1, 1); }
;

sub_identifier_1:
  qualified_word		{ $$ = $1; }
| qualified_word subref		{ $$ = $1; }
;

identifier:
  identifier_1			{ $$ = cb_build_identifier ($1, 0); }
;

identifier_1:
  qualified_word subref refmod
  {
	$$ = $1;
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
| qualified_word subref %prec SHIFT_PREFER
  {
	$$ = $1;
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
| qualified_word refmod
  {
	$$ = $1;
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
| qualified_word %prec SHIFT_PREFER
  {
	$$ = $1;
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
;

target_identifier:
  target_identifier_1
  {
	$$ = cb_build_identifier ($1, 0);
  }
;

target_identifier_1:
  qualified_word subref refmod
  {
	$$ = $1;
	if (CB_REFERENCE_P ($1)) {
		CB_REFERENCE ($1)->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
| qualified_word subref %prec SHIFT_PREFER
  {
	$$ = $1;
	if (CB_REFERENCE_P ($1)) {
		CB_REFERENCE ($1)->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
| qualified_word refmod
  {
	$$ = $1;
	if (CB_REFERENCE_P ($1)) {
		CB_REFERENCE ($1)->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
| qualified_word %prec SHIFT_PREFER
  {
	$$ = $1;
	if (CB_REFERENCE_P ($1)) {
		CB_REFERENCE ($1)->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ($1);
	}
  }
;

qualified_word:
  WORD
  {
	$$ = $1;
  }
| WORD in_of qualified_word
  {
	$$ = $1;
	CB_REFERENCE ($1)->chain = $3;
  }
;

subref:
  TOK_OPEN_PAREN exp_list TOK_CLOSE_PAREN
  {
	$$ = $0;
	CB_REFERENCE ($0)->subs = cb_list_reverse ($2);
  }
;

refmod:
  TOK_OPEN_PAREN exp TOK_COLON TOK_CLOSE_PAREN
  {
	CB_REFERENCE ($0)->offset = $2;
  }
| TOK_OPEN_PAREN exp TOK_COLON exp TOK_CLOSE_PAREN
  {
	CB_REFERENCE ($0)->offset = $2;
	CB_REFERENCE ($0)->length = $4;
  }
;

/* Literal */

integer:
  LITERAL %prec SHIFT_PREFER
  {
	if (cb_tree_category ($1) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		$$ = cb_int1;
	} else if (CB_LITERAL ($1)->sign < 0 || CB_LITERAL ($1)->scale) {
		cb_error (_("Integer value expected"));
		$$ = cb_int1;
	} else {
		$$ = $1;
	}
  }
;

symbolic_integer:
  LITERAL
  {
	int	n;

	if (cb_tree_category ($1) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		$$ = cb_int1;
	} else if (CB_LITERAL ($1)->sign || CB_LITERAL ($1)->scale) {
		cb_error (_("Integer value expected"));
		$$ = cb_int1;
	} else {
		n = cb_get_int ($1);
		if (n < 1 || n > 256) {
			cb_error (_("Invalid SYMBOLIC integer"));
			$$ = cb_int1;
		} else {
			$$ = $1;
		}
	}
  }
;

report_integer:
  LITERAL
  {
	int	n;

	if (cb_tree_category ($1) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		$$ = cb_int1;
	} else if (CB_LITERAL ($1)->sign || CB_LITERAL ($1)->scale) {
		cb_error (_("Integer value expected"));
		$$ = cb_int1;
	} else {
		n = cb_get_int ($1);
		if (n < 1) {
			cb_error (_("Invalid integer"));
			$$ = cb_int1;
		} else {
			$$ = $1;
		}
	}
  }
;

class_value:
  LITERAL
  {
	int	n;

	if (cb_tree_category ($1) == CB_CATEGORY_NUMERIC) {
		if (CB_LITERAL ($1)->sign || CB_LITERAL ($1)->scale) {
			cb_error (_("Integer value expected"));
		} else {
			n = cb_get_int ($1);
			if (n < 1 || n > 256) {
				cb_error (_("Invalid CLASS value"));
			}
		}
	}
	$$ = $1;
  }
| SPACE				{ $$ = cb_space; }
| ZERO				{ $$ = cb_zero; }
| QUOTE				{ $$ = cb_quote; }
| HIGH_VALUE			{ $$ = cb_high; }
| LOW_VALUE			{ $$ = cb_low; }
| TOK_NULL			{ $$ = cb_null; }
;

literal:
  basic_literal
  {
	$$ = $1;
  }
| ALL basic_value
  {
	struct cb_literal	*l;

	if (CB_LITERAL_P ($2)) {
		/* We must not alter the original definition */
		l = cobc_parse_malloc (sizeof(struct cb_literal));
		*l = *(CB_LITERAL($2));
		l->all = 1;
		$$ = CB_TREE (l);
	} else {
		$$ = $2;
	}
  }
;

basic_literal:
  basic_value
  {
	$$ = $1;
  }
| basic_literal TOK_AMPER basic_value
  {
	$$ = cb_concat_literals ($1, $3);
  }
;

basic_value:
  LITERAL			{ $$ = $1; }
| SPACE				{ $$ = cb_space; }
| ZERO				{ $$ = cb_zero; }
| QUOTE				{ $$ = cb_quote; }
| HIGH_VALUE			{ $$ = cb_high; }
| LOW_VALUE			{ $$ = cb_low; }
| TOK_NULL			{ $$ = cb_null; }
;

/* Function */

function:
  func_no_parm func_refmod
  {
	$$ = cb_build_intrinsic ($1, NULL, $2, 0);
  }
| func_one_parm TOK_OPEN_PAREN expr_x TOK_CLOSE_PAREN func_refmod
  {
	$$ = cb_build_intrinsic ($1, CB_LIST_INIT ($3), $5, 0);
  }
| func_multi_parm TOK_OPEN_PAREN exp_list TOK_CLOSE_PAREN func_refmod
  {
	$$ = cb_build_intrinsic ($1, $3, $5, 0);
  }
| TRIM_FUNC TOK_OPEN_PAREN trim_args TOK_CLOSE_PAREN func_refmod
  {
	$$ = cb_build_intrinsic ($1, $3, $5, 0);
  }
| NUMVALC_FUNC TOK_OPEN_PAREN numvalc_args TOK_CLOSE_PAREN
  {
	$$ = cb_build_intrinsic ($1, $3, NULL, 0);
  }
| LOCALE_DATE_FUNC TOK_OPEN_PAREN locale_dt_args TOK_CLOSE_PAREN func_refmod
  {
	$$ = cb_build_intrinsic ($1, $3, $5, 0);
  }
| LOCALE_TIME_FUNC TOK_OPEN_PAREN locale_dt_args TOK_CLOSE_PAREN func_refmod
  {
	$$ = cb_build_intrinsic ($1, $3, $5, 0);
  }
| LOCALE_TIME_FROM_FUNC TOK_OPEN_PAREN locale_dt_args TOK_CLOSE_PAREN func_refmod
  {
	$$ = cb_build_intrinsic ($1, $3, $5, 0);
  }
| FUNCTION_NAME func_args
  {
	$$ = cb_build_intrinsic ($1, $2, NULL, 0);
  }
| USER_FUNCTION_NAME func_args
  {
	$$ = cb_build_intrinsic ($1, $2, NULL, 1);
  }
;

func_no_parm:
  CURRENT_DATE_FUNC
| WHEN_COMPILED_FUNC
;

func_one_parm:
  UPPER_CASE_FUNC
| LOWER_CASE_FUNC
| REVERSE_FUNC
;

func_multi_parm:
  CONCATENATE_FUNC
| SUBSTITUTE_FUNC
| SUBSTITUTE_CASE_FUNC
;

func_refmod:
  /* empty */	%prec SHIFT_PREFER
  {
	$$ = NULL;
  }
| TOK_OPEN_PAREN exp TOK_COLON TOK_CLOSE_PAREN
  {
	$$ = CB_BUILD_PAIR ($2, NULL);
  }
| TOK_OPEN_PAREN exp TOK_COLON exp TOK_CLOSE_PAREN
  {
	$$ = CB_BUILD_PAIR ($2, $4);
  }
;

func_args:
  /* empty */	%prec SHIFT_PREFER
  {
	$$ = NULL;
  }
| TOK_OPEN_PAREN exp_list TOK_CLOSE_PAREN
  {
	$$ = $2;
  }
| TOK_OPEN_PAREN TOK_CLOSE_PAREN
  {
	$$ = NULL;
  }
;

trim_args:
  expr_x
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, cb_int0);
  }
| expr_x e_sep LEADING
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, cb_int1);
  }
| expr_x e_sep TRAILING
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, cb_int2);
  }
;

numvalc_args:
  expr_x
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, cb_null);
  }
| expr_x e_sep expr_x
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, $3);
  }
;

locale_dt_args:
  exp
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, cb_null);
  }
| exp e_sep reference
  {
	cb_tree	x;

	x = CB_LIST_INIT ($1);
	$$ = cb_list_add (x, cb_ref ($3));
  }
;

/* Common rules */

not_const_word:
  {
	non_const_word = 1;
  }
;

/* Common flags */

flag_all:
  /* empty */			{ $$ = cb_int0; }
| ALL				{ $$ = cb_int1; }
;

flag_duplicates:
  /* empty */			{ $$ = cb_int0; }
| with_dups			{ $$ = cb_int1; }
;

flag_initialized:
  /* empty */			{ $$ = NULL; }
| INITIALIZED			{ $$ = cb_int1; }
;

flag_initialized_to:
  /* empty */
  {
	$$ = NULL;
  }
| INITIALIZED to_init_val
  {
	$$ = $2;
  }
;

to_init_val:
  /* empty */
  {
	$$ = NULL;
  }
| TO simple_all_value
  {
	$$ = $2;
  }
;

flag_next:
  %prec SHIFT_PREFER
  /* empty */			{ $$ = cb_int0; }
| NEXT				{ $$ = cb_int1; }
| PREVIOUS			{ $$ = cb_int2; }
;

flag_not:
  /* empty */			{ $$ = NULL; }
| NOT				{ $$ = cb_true; }
;

flag_optional:
  /* empty */			{ $$ = cb_int (cb_flag_optional_file); }
| OPTIONAL			{ $$ = cb_int1; }
| NOT OPTIONAL			{ $$ = cb_int0; }
;

flag_rounded:
  /* empty */
  {
	$$ = cb_int0;
  }
| ROUNDED round_mode
  {
	if ($2) {
		$$ = $2;
	} else {
		$$ = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
;

round_mode:
  /* empty */
  {
	$$ = NULL;
	cobc_cs_check = 0;
  }
| MODE _is round_choice
  {
	$$ = $3;
	cobc_cs_check = 0;
  }
;

round_choice:
  AWAY_FROM_ZERO
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
| NEAREST_AWAY_FROM_ZERO
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
| NEAREST_EVEN
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
| NEAREST_TOWARD_ZERO
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
| PROHIBITED
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
| TOWARD_GREATER
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
| TOWARD_LESSER
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
| TRUNCATION
  {
	$$ = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
;

flag_separate:
  /* empty */			{ $$ = NULL; }
| SEPARATE _character		{ $$ = cb_int1; }
;

/* Error recovery */

error_stmt_recover:
  TOK_DOT
| ACCEPT
| ADD
| ALLOCATE
| ALTER
| CALL
| CANCEL
| CLOSE
| COMMIT
| COMPUTE
| CONTINUE
| DELETE
| DISPLAY
| DIVIDE
| ELSE
| ENTRY
| EVALUATE
| EXIT
| FREE
| GENERATE
| GO
| GOBACK
| IF
| INITIALIZE
| INITIATE
| INSPECT
| MERGE
| MOVE
| MULTIPLY
| NEXT
| OPEN
| PERFORM
| READ
| RELEASE
| RETURN
| REWRITE
| ROLLBACK
| SEARCH
| SET
| SORT
| START
| STOP
| STRING
| SUBTRACT
| SUPPRESS
| TERMINATE
| TRANSFORM
| UNLOCK
| UNSTRING
| WRITE
| END_ACCEPT
| END_ADD
| END_CALL
| END_COMPUTE
| END_DELETE
| END_DISPLAY
| END_DIVIDE
| END_EVALUATE
| END_IF
| END_MULTIPLY
| END_PERFORM
| END_READ
| END_RETURN
| END_REWRITE
| END_SEARCH
| END_START
| END_STRING
| END_SUBTRACT
| END_UNSTRING
| END_WRITE
;

/* Mandatory/Optional keyword selection without actions */

/* Optional selection */

_advancing:	| ADVANCING ;
_after:		| AFTER ;
_are:		| ARE ;
_area:		| AREA ;
_as:		| AS ;
_at:		| AT ;
_binary:	| BINARY ;
_by:		| BY ;
_character:	| CHARACTER ;
_characters:	| CHARACTERS ;
_contains:	| CONTAINS ;
_data:		| DATA ;
_file:		| TOK_FILE ;
_final:		| FINAL ;
_for:		| FOR ;
_from:		| FROM ;
_in:		| IN ;
_in_order:	| ORDER | IN ORDER ;
_indicate:	| INDICATE ;
_initial:	| TOK_INITIAL ;
_into:		| INTO ;
_is:		| IS ;
_is_are:	| IS | ARE ;
_key:		| KEY ;
_left_or_right:	| LEFT | RIGHT ;
_line_or_lines:	| LINE | LINES ;
_limits:	| LIMIT _is | LIMITS _are ;
_lines:		| LINES ;
_mode:		| MODE ;
_number:	| NUMBER ;
_numbers:	| NUMBER | NUMBERS ;
_of:		| OF ;
_on:		| ON ;
_onoff_status:	| STATUS IS | STATUS | IS ;
_other:		| OTHER ;
_procedure:	| PROCEDURE ;
_program:	| PROGRAM ;
_record:	| RECORD ;
_right:		| RIGHT ;
_sign:		| SIGN ;
_signed:	| SIGNED ;
_sign_is:	| SIGN | SIGN IS ;
_size:		| SIZE ;
_standard:	| STANDARD ;
_status:	| STATUS ;
_tape:		| TAPE ;
_then:		| THEN ;
_times:		| TIMES ;
_to:		| TO ;
_to_using:	| TO | USING;
_when:		| WHEN ;
_when_set_to:	| WHEN SET TO ;
_with:		| WITH ;

/* Mandatory selection */

coll_sequence:		COLLATING SEQUENCE | SEQUENCE ;
column_or_col:		COLUMN | COL ;
columns_or_cols:	COLUMNS | COLS ;
comp_equal:		TOK_EQUAL | EQUAL ;
exception_or_error:	EXCEPTION | ERROR ;
exception_or_overflow:	EXCEPTION | TOK_OVERFLOW ;
in_of:			IN | OF ;
label_option:		STANDARD | OMITTED ;
line_or_lines:		LINE | LINES ;
lock_records:		RECORD | RECORDS ;
object_char_or_word:	CHARACTERS | WORDS ;
records:		RECORD _is | RECORDS _are ;
reel_or_unit:		REEL | UNIT ;
scroll_line_or_lines:	LINE | LINES ;
size_or_length:		SIZE | LENGTH ;
with_dups:		WITH DUPLICATES | DUPLICATES ;

prog_coll_sequence:
  PROGRAM COLLATING SEQUENCE
| COLLATING SEQUENCE
| SEQUENCE
;

/* Mandatory R/W keywords */
detail_keyword:		DETAIL | DE ;
ch_keyword:		CONTROL HEADING | CH ;
cf_keyword:		CONTROL FOOTING | CF ;
ph_keyword:		PAGE HEADING | PH ;
pf_keyword:		PAGE FOOTING | PF ;
rh_keyword:		REPORT HEADING | RH ;
rf_keyword:		REPORT FOOTING | RF ;
control_keyword:	CONTROL _is | CONTROLS _are ;

%%
