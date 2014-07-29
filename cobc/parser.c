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

# if 0 /* activate only for debugging purposes for attribs */
static
void printBits(unsigned int num){
	unsigned int size = sizeof(unsigned int);
	unsigned int maxPow = 1<<(size*8-1);
	int i=0;

	for(;i<size*8;++i){
		// print last bit and shift left.
		fprintf(stderr, "%u ",num&maxPow ? 1 : 0);
		num = num<<1;
	}
	fprintf(stderr, "\n");
}
#endif

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
	       cb_tree timeout, cb_tree prompt, int attrib)
{
	/* Attach attribute to current_statement */
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
	current_statement->attr_ptr->dispattrs |= attrib;
}

static void
remove_attrib (int attrib)
{
	/* Remove attribute from current_statement */
	if (!current_statement->attr_ptr) {
		return;
	}
	current_statement->attr_ptr->dispattrs ^= attrib;
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
#line 794 "parser.c"

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
#line 1348 "parser.c"

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
#define YYLAST   7983

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  812
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1889
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2700

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
    2194,  2196,  2198,  2202,  2206,  2210,  2214,  2218,  2220,  2222,
    2223,  2225,  2226,  2231,  2236,  2242,  2249,  2250,  2253,  2254,
    2256,  2257,  2261,  2265,  2270,  2271,  2274,  2275,  2279,  2281,
    2284,  2289,  2290,  2293,  2294,  2299,  2306,  2307,  2309,  2311,
    2313,  2314,  2315,  2319,  2321,  2324,  2327,  2331,  2332,  2335,
    2338,  2341,  2342,  2346,  2349,  2354,  2356,  2358,  2360,  2362,
    2363,  2366,  2367,  2370,  2371,  2373,  2374,  2378,  2380,  2383,
    2384,  2388,  2391,  2395,  2396,  2398,  2402,  2406,  2409,  2410,
    2415,  2420,  2421,  2423,  2425,  2427,  2428,  2433,  2437,  2440,
    2442,  2445,  2446,  2448,  2449,  2454,  2458,  2462,  2466,  2470,
    2475,  2478,  2483,  2485,  2486,  2490,  2496,  2497,  2500,  2503,
    2506,  2509,  2510,  2513,  2515,  2517,  2518,  2521,  2522,  2524,
    2526,  2529,  2531,  2534,  2537,  2539,  2541,  2544,  2547,  2549,
    2551,  2553,  2555,  2557,  2561,  2565,  2569,  2573,  2574,  2576,
    2577,  2582,  2587,  2594,  2601,  2610,  2619,  2620,  2622,  2623,
    2627,  2630,  2631,  2636,  2639,  2641,  2645,  2647,  2649,  2651,
    2654,  2656,  2658,  2661,  2664,  2668,  2671,  2675,  2677,  2681,
    2684,  2686,  2688,  2690,  2691,  2694,  2695,  2697,  2698,  2702,
    2703,  2706,  2708,  2711,  2713,  2715,  2717,  2718,  2721,  2722,
    2726,  2728,  2729,  2733,  2735,  2736,  2740,  2744,  2745,  2749,
    2752,  2753,  2760,  2764,  2767,  2769,  2770,  2772,  2773,  2777,
    2783,  2784,  2787,  2788,  2792,  2796,  2797,  2800,  2802,  2805,
    2810,  2812,  2814,  2816,  2818,  2820,  2822,  2824,  2825,  2829,
    2830,  2834,  2836,  2839,  2840,  2844,  2847,  2849,  2851,  2853,
    2856,  2858,  2860,  2862,  2863,  2867,  2870,  2876,  2878,  2881,
    2884,  2887,  2889,  2891,  2893,  2896,  2898,  2901,  2906,  2909,
    2910,  2912,  2914,  2916,  2918,  2923,  2924,  2927,  2931,  2935,
    2936,  2940,  2941,  2945,  2949,  2954,  2955,  2960,  2965,  2972,
    2973,  2975,  2976,  2980,  2985,  2991,  2993,  2995,  2997,  2999,
    3000,  3004,  3005,  3009,  3012,  3014,  3015,  3019,  3022,  3023,
    3028,  3031,  3032,  3034,  3036,  3038,  3040,  3044,  3045,  3048,
    3050,  3054,  3058,  3059,  3063,  3065,  3067,  3069,  3073,  3081,
    3082,  3087,  3095,  3096,  3099,  3100,  3103,  3106,  3110,  3114,
    3118,  3121,  3122,  3126,  3128,  3130,  3131,  3133,  3135,  3136,
    3140,  3143,  3145,  3146,  3151,  3156,  3157,  3159,  3160,  3165,
    3170,  3171,  3174,  3178,  3179,  3181,  3183,  3184,  3189,  3194,
    3201,  3202,  3205,  3206,  3209,  3211,  3214,  3218,  3219,  3221,
    3222,  3226,  3228,  3230,  3232,  3234,  3236,  3238,  3240,  3242,
    3244,  3246,  3251,  3255,  3257,  3260,  3263,  3266,  3269,  3272,
    3275,  3278,  3281,  3284,  3289,  3293,  3298,  3300,  3303,  3307,
    3309,  3312,  3316,  3320,  3321,  3325,  3326,  3334,  3335,  3341,
    3342,  3345,  3346,  3349,  3350,  3354,  3355,  3358,  3363,  3364,
    3367,  3372,  3373,  3378,  3383,  3384,  3388,  3389,  3394,  3396,
    3398,  3400,  3403,  3406,  3409,  3412,  3414,  3416,  3419,  3421,
    3422,  3424,  3425,  3430,  3433,  3434,  3437,  3442,  3447,  3448,
    3450,  3452,  3454,  3456,  3458,  3459,  3464,  3470,  3472,  3475,
    3477,  3481,  3485,  3486,  3491,  3492,  3494,  3495,  3500,  3505,
    3512,  3519,  3520,  3522,  3525,  3526,  3528,  3529,  3533,  3535,
    3538,  3539,  3543,  3549,  3550,  3554,  3557,  3558,  3560,  3562,
    3563,  3568,  3575,  3576,  3580,  3582,  3586,  3589,  3592,  3595,
    3599,  3600,  3604,  3605,  3609,  3610,  3614,  3615,  3617,  3618,
    3622,  3624,  3626,  3628,  3630,  3632,  3640,  3641,  3643,  3645,
    3647,  3649,  3651,  3653,  3658,  3660,  3663,  3665,  3668,  3672,
    3673,  3675,  3678,  3680,  3684,  3686,  3688,  3693,  3695,  3697,
    3699,  3700,  3705,  3711,  3712,  3715,  3716,  3721,  3725,  3729,
    3731,  3733,  3735,  3737,  3738,  3740,  3743,  3744,  3747,  3748,
    3751,  3754,  3755,  3758,  3759,  3762,  3765,  3766,  3769,  3770,
    3773,  3776,  3777,  3780,  3781,  3784,  3787,  3789,  3792,  3794,
    3796,  3799,  3802,  3805,  3807,  3809,  3812,  3815,  3818,  3819,
    3822,  3823,  3826,  3827,  3830,  3832,  3834,  3835,  3838,  3840,
    3843,  3846,  3848,  3850,  3852,  3854,  3856,  3858,  3860,  3862,
    3864,  3866,  3868,  3870,  3872,  3874,  3876,  3878,  3880,  3882,
    3884,  3886,  3888,  3890,  3892,  3894,  3896,  3899,  3901,  3903,
    3905,  3907,  3909,  3911,  3913,  3917,  3918,  3920,  3922,  3926,
    3930,  3932,  3936,  3940,  3942,  3946,  3948,  3951,  3954,  3956,
    3960,  3962,  3964,  3968,  3970,  3974,  3976,  3980,  3982,  3985,
    3988,  3990,  3992,  3994,  3997,  3999,  4001,  4003,  4006,  4008,
    4009,  4012,  4014,  4016,  4018,  4022,  4024,  4026,  4029,  4031,
    4033,  4035,  4038,  4040,  4042,  4044,  4046,  4048,  4050,  4053,
    4055,  4057,  4061,  4063,  4066,  4068,  4070,  4072,  4074,  4077,
    4080,  4083,  4088,  4092,  4094,  4096,  4099,  4101,  4103,  4105,
    4107,  4109,  4111,  4113,  4116,  4119,  4122,  4124,  4126,  4128,
    4130,  4132,  4134,  4136,  4138,  4140,  4142,  4144,  4146,  4148,
    4150,  4152,  4154,  4156,  4158,  4160,  4162,  4164,  4166,  4168,
    4170,  4172,  4174,  4177,  4179,  4183,  4186,  4189,  4191,  4193,
    4197,  4200,  4203,  4205,  4207,  4211,  4215,  4220,  4226,  4228,
    4230,  4232,  4234,  4236,  4238,  4240,  4242,  4244,  4246,  4248,
    4251,  4253,  4257,  4259,  4261,  4263,  4265,  4267,  4269,  4271,
    4274,  4280,  4286,  4292,  4297,  4303,  4309,  4315,  4318,  4321,
    4323,  4325,  4327,  4329,  4331,  4333,  4335,  4337,  4338,  4343,
    4349,  4350,  4354,  4357,  4359,  4363,  4367,  4369,  4373,  4375,
    4379,  4380,  4381,  4383,  4384,  4386,  4387,  4389,  4390,  4393,
    4394,  4397,  4398,  4400,  4402,  4403,  4405,  4406,  4408,  4411,
    4412,  4415,  4416,  4420,  4422,  4424,  4426,  4428,  4430,  4432,
    4434,  4436,  4437,  4440,  4442,  4444,  4446,  4448,  4450,  4452,
    4454,  4456,  4458,  4460,  4462,  4464,  4466,  4468,  4470,  4472,
    4474,  4476,  4478,  4480,  4482,  4484,  4486,  4488,  4490,  4492,
    4494,  4496,  4498,  4500,  4502,  4504,  4506,  4508,  4510,  4512,
    4514,  4516,  4518,  4520,  4522,  4524,  4526,  4528,  4530,  4532,
    4534,  4536,  4538,  4540,  4542,  4544,  4546,  4548,  4550,  4552,
    4554,  4556,  4558,  4560,  4562,  4564,  4566,  4568,  4570,  4572,
    4574,  4576,  4578,  4580,  4581,  4583,  4584,  4586,  4587,  4589,
    4590,  4592,  4593,  4595,  4596,  4598,  4599,  4601,  4602,  4604,
    4605,  4607,  4608,  4610,  4611,  4613,  4614,  4616,  4617,  4619,
    4620,  4622,  4623,  4625,  4626,  4628,  4629,  4631,  4632,  4634,
    4637,  4638,  4640,  4641,  4643,  4644,  4646,  4647,  4649,  4650,
    4652,  4654,  4655,  4657,  4658,  4660,  4662,  4663,  4665,  4667,
    4668,  4671,  4674,  4675,  4677,  4678,  4680,  4681,  4683,  4684,
    4686,  4688,  4689,  4691,  4692,  4694,  4695,  4698,  4700,  4702,
    4703,  4705,  4706,  4708,  4709,  4711,  4712,  4714,  4715,  4717,
    4718,  4720,  4721,  4723,  4724,  4726,  4729,  4730,  4732,  4733,
    4735,  4736,  4738,  4739,  4741,  4742,  4744,  4745,  4747,  4748,
    4750,  4751,  4753,  4755,  4756,  4758,  4759,  4763,  4764,  4766,
    4769,  4771,  4773,  4775,  4777,  4779,  4781,  4783,  4785,  4787,
    4789,  4791,  4793,  4795,  4797,  4799,  4801,  4803,  4805,  4807,
    4809,  4811,  4814,  4817,  4819,  4821,  4823,  4825,  4827,  4829,
    4832,  4834,  4838,  4841,  4843,  4845,  4847,  4850,  4852,  4855,
    4857,  4860,  4862,  4865,  4867,  4870,  4872,  4875,  4877,  4880
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
      -1,    -1,    26,   256,    -1,    -1,  1267,   538,  1282,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1298,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1267,  1216,  1309,    -1,  1315,
    1267,  1183,    -1,   396,  1267,  1216,    -1,  1254,    59,  1267,
     557,    -1,  1183,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1267,    96,    -1,  1216,  1267,  1187,    -1,
    1267,  1187,   574,    -1,   575,    -1,    -1,   575,    -1,  1032,
    1279,  1187,    -1,   575,  1032,  1279,  1187,    -1,    -1,    11,
    1187,   577,  1267,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1255,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1268,
     590,    -1,  1188,    -1,   589,  1188,    -1,  1217,    -1,   590,
    1217,    -1,    58,  1187,  1267,   592,    -1,   593,    -1,   592,
     593,    -1,  1219,    -1,  1219,   442,  1219,    -1,   257,  1187,
    1267,   256,    -1,    98,  1285,  1267,   256,   596,    -1,    -1,
    1298,   328,   256,    -1,   108,  1267,    68,    -1,   301,   405,
    1267,   468,   400,    -1,   100,  1267,  1182,    -1,    96,   423,
    1267,  1182,    -1,   390,  1267,  1182,    -1,   164,  1267,  1182,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1240,  1187,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1295,   614,   613,   615,    -1,    29,  1295,   614,   612,
     616,    -1,    29,  1295,   614,   119,   616,    -1,    29,  1295,
     614,   238,   616,    -1,    29,  1295,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1258,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1213,    -1,    -1,   256,    -1,  1213,    -1,     4,  1274,  1267,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1283,
    1269,  1267,   632,  1234,    -1,  1299,  1267,   504,    -1,   622,
     423,  1267,  1182,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1274,  1267,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1308,    -1,
     503,   262,   309,   274,  1308,    -1,   503,   385,    -1,   315,
    1267,   628,    -1,   628,    -1,   220,    -1,  1283,  1252,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1254,  1267,  1186,
      -1,   351,   113,  1267,   419,    -1,   351,  1269,  1267,   632,
      -1,  1182,    -1,  1182,   452,  1181,    -1,  1182,   414,  1267,
    1181,    -1,   359,  1269,  1267,  1182,    -1,   372,   635,  1249,
      -1,   287,    -1,  1216,    -1,   404,  1298,   637,    -1,     9,
    1280,    -1,   287,  1280,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1249,  1260,  1172,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1258,  1291,  1256,   645,    -1,   646,    -1,   645,   646,
      -1,  1173,   647,    -1,    -1,   331,  1216,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1173,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1267,   171,    -1,  1267,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1256,
    1216,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1256,  1216,  1255,    -1,   351,  1256,  1216,   446,  1216,  1255,
      -1,   351,  1267,   499,  1262,  1288,   661,   662,  1255,   660,
      -1,    -1,   114,  1278,  1182,    -1,    -1,  1261,  1216,    -1,
      -1,   446,  1216,    -1,   239,  1310,  1306,    -1,   498,   306,
     665,  1267,   666,    -1,   498,   306,   174,  1267,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1213,    -1,   102,  1310,
    1184,    -1,   250,  1267,  1186,  1273,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1298,   187,
    1251,  1186,    -1,   465,  1186,    -1,    48,  1186,    -1,   352,
    1274,  1267,   504,    -1,    62,  1267,   504,    -1,   677,   678,
      -1,   366,  1267,    -1,   368,  1248,    -1,  1187,    -1,   678,
    1187,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1232,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1267,   204,
      -1,  1220,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1277,   691,    -1,  1210,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1250,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1210,    -1,  1267,   171,   702,    -1,    -1,
      26,   256,    -1,  1267,   204,    -1,   327,    -1,   706,    -1,
     491,  1267,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1286,    -1,    41,   476,    -1,
      44,  1286,    -1,    44,   476,    -1,    43,  1286,    -1,    43,
     476,    -1,    42,  1286,    -1,    42,   476,    -1,    40,  1286,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1287,   241,  1244,    -1,  1287,   468,
    1244,    -1,   305,  1216,   713,  1293,   714,   711,    -1,    -1,
     425,  1216,    -1,   305,  1216,   713,  1293,   714,   715,   718,
      -1,    -1,   446,  1216,    -1,    -1,   114,  1278,  1182,    -1,
     716,    -1,    -1,   716,   717,  1269,  1267,  1181,    -1,    27,
      -1,   115,    -1,    -1,   220,  1253,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1284,    -1,   434,  1270,
      -1,    45,  1296,   510,    -1,    36,    -1,    -1,   498,  1268,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1220,
      -1,  1220,   442,  1220,    -1,    -1,  1297,   453,  1267,  1220,
      -1,   363,  1213,    -1,   363,  1213,   442,  1213,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1174,   740,   741,   451,   755,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1267,   204,
      -1,    61,  1267,  1200,    -1,   743,    -1,   746,    -1,  1323,
     744,    -1,  1259,   745,    -1,  1209,    -1,   745,  1209,    -1,
     321,  1272,   747,   748,    -1,  1218,    -1,  1218,  1307,  1218,
    1301,    -1,  1218,  1307,    -1,    -1,   748,   749,    -1,   750,
      -1,   751,    -1,   752,    -1,   753,    -1,   754,    -1,   210,
    1267,  1218,    -1,   177,  1316,  1267,  1218,    -1,   240,  1317,
    1267,  1218,    -1,   240,  1316,  1267,  1218,    -1,   187,  1267,
    1218,    -1,    -1,   755,   756,    -1,    -1,   686,   687,   757,
     758,   451,    -1,    -1,   758,   759,    -1,   760,    -1,   764,
      -1,   770,    -1,   704,    -1,   780,    -1,   709,    -1,   721,
      -1,   772,    -1,   723,    -1,   778,    -1,   765,    -1,   725,
      -1,   768,    -1,   779,    -1,   710,    -1,   769,    -1,   472,
    1267,   761,    -1,  1321,    -1,  1319,    -1,  1317,   762,    -1,
    1316,    -1,  1318,   762,    -1,  1320,    -1,  1322,    -1,    -1,
    1209,   763,    -1,   176,   763,    -1,    -1,   313,   321,    -1,
     285,   209,  1267,   775,    -1,   431,  1277,  1193,   766,    -1,
      -1,   373,  1278,   767,    -1,  1209,    -1,   176,    -1,   333,
     501,  1149,    -1,   499,  1209,   196,  1195,    49,  1195,    -1,
     771,   774,    -1,   252,  1276,  1268,    -1,   254,  1248,    -1,
     773,   776,    -1,  1300,  1276,  1268,    -1,  1301,  1248,    -1,
     775,    -1,   774,   775,    -1,   329,  1216,    -1,  1218,    -1,
     286,    -1,   777,    -1,   776,   777,    -1,   329,  1216,    -1,
    1218,    -1,   414,  1267,  1195,  1241,    -1,   209,  1264,    -1,
     491,  1267,   119,    -1,    -1,    -1,   389,   394,   451,   782,
     783,    -1,    -1,   784,    -1,   785,   451,    -1,   784,   785,
     451,    -1,   696,    -1,    -1,   686,   687,   786,   787,    -1,
     686,     1,   451,    -1,    -1,   787,   788,    -1,    45,   252,
      -1,    45,   389,    -1,    38,    -1,    46,    -1,   160,   156,
      -1,   160,   158,    -1,   211,    -1,   265,    -1,   378,    -1,
     473,    -1,   318,    -1,   243,    -1,    32,    -1,   395,    -1,
     371,    -1,   198,    -1,   345,    56,  1267,  1200,    -1,   345,
      -1,   456,    -1,   252,  1275,  1267,   791,  1202,    -1,  1300,
    1275,  1267,   792,  1202,    -1,   189,  1267,  1202,    -1,    35,
    1267,  1202,    -1,   705,    -1,   723,    -1,   794,    -1,   721,
      -1,   709,    -1,   725,    -1,   704,    -1,   793,    -1,   497,
    1209,    -1,   196,  1201,    -1,   446,  1209,    -1,   329,    -1,
     463,    -1,   270,    -1,   458,    -1,    -1,   789,    -1,   790,
      -1,    -1,   789,    -1,   790,    -1,   305,  1216,  1293,    -1,
    1267,   204,    -1,    -1,    -1,    -1,   337,   122,   799,   807,
     451,   796,   808,   797,   810,    -1,    -1,   798,   821,   451,
     810,    -1,    -1,    -1,   497,   800,   802,    -1,    -1,    55,
     801,   802,    -1,   803,    -1,   802,   803,    -1,   804,   805,
     806,   504,    -1,    -1,  1253,   357,    -1,  1253,   498,    -1,
      -1,   410,  1267,    32,    -1,   410,  1267,   110,    -1,   476,
     410,  1267,    32,    -1,   476,   410,  1267,  1216,    -1,   410,
    1267,  1216,    -1,    -1,   312,    -1,    -1,   376,   504,    -1,
      -1,    -1,   109,   451,   809,   810,   129,   109,   451,    -1,
      -1,   810,   811,    -1,   812,    -1,   815,    -1,   821,   451,
      -1,   816,    -1,   451,    -1,    -1,   504,   394,   817,   451,
     813,   814,    -1,    -1,  1103,   451,    -1,   504,   451,    -1,
     504,    -1,    -1,  1216,    -1,    -1,    -1,   819,   820,   821,
      -1,    -1,   822,   823,    -1,   821,   823,    -1,   824,    -1,
     840,    -1,   845,    -1,   849,    -1,   854,    -1,   869,    -1,
     872,    -1,   880,    -1,   876,    -1,   881,    -1,   882,    -1,
     887,    -1,   901,    -1,   905,    -1,   908,    -1,   922,    -1,
     926,    -1,   929,    -1,   932,    -1,   936,    -1,   937,    -1,
     941,    -1,   951,    -1,   954,    -1,   971,    -1,   973,    -1,
     976,    -1,   980,    -1,   986,    -1,   998,    -1,  1006,    -1,
    1007,    -1,  1010,    -1,  1011,    -1,  1015,    -1,  1020,    -1,
    1021,    -1,  1029,    -1,  1044,    -1,  1054,    -1,  1063,    -1,
    1068,    -1,  1075,    -1,  1079,    -1,  1081,    -1,  1084,    -1,
    1087,    -1,  1091,    -1,  1118,    -1,   285,   399,    -1,     1,
    1245,    -1,    -1,     3,   825,   826,   839,    -1,   827,   829,
     833,   834,   835,  1126,    -1,  1209,   196,   828,    -1,  1209,
     196,  1301,    -1,  1209,   196,   103,   509,    -1,  1209,   196,
     103,    -1,  1209,   196,   104,   508,    -1,  1209,   196,   104,
      -1,  1209,   196,   105,    -1,  1209,   196,   162,   237,    -1,
    1209,   196,   165,   423,    -1,  1209,   196,   443,    -1,  1209,
     196,   493,   276,    -1,  1209,   196,    69,    -1,  1209,   196,
     155,  1126,    -1,  1209,   196,   153,  1198,  1126,    -1,  1209,
     196,    24,    -1,  1209,   196,    25,  1126,    -1,  1209,   196,
    1176,    -1,  1209,   196,   504,    -1,  1209,    -1,   308,    -1,
     254,    -1,   252,   299,    -1,    -1,   830,    -1,  1251,   831,
     832,    -1,  1251,   832,   831,    -1,  1251,   831,    -1,  1251,
     832,    -1,    30,  1198,    -1,   252,  1275,  1202,    -1,  1300,
    1275,  1202,    -1,   331,  1275,  1202,    -1,    -1,   197,    -1,
      -1,   272,  1267,    47,    -1,    -1,   503,   836,    -1,   837,
      -1,   836,   837,    -1,    32,    -1,    38,    -1,    46,    -1,
      91,    -1,   198,    -1,   211,    -1,   243,    -1,   263,    -1,
     265,    -1,   288,    -1,   318,    -1,   345,    56,  1267,  1200,
      -1,   345,    -1,   371,    -1,   378,    -1,   395,    -1,   473,
      -1,   287,   838,    -1,   838,    -1,   489,    -1,   189,  1267,
    1202,    -1,    35,  1267,  1202,    -1,   391,   482,  1148,    -1,
     391,   123,  1148,    -1,   444,  1247,  1203,    -1,   483,    -1,
     110,    -1,    -1,   130,    -1,    -1,     5,   841,   842,   844,
      -1,  1191,   446,  1168,  1132,    -1,  1191,   843,   203,  1168,
    1132,    -1,    94,  1209,   446,  1209,  1241,  1132,    -1,    -1,
     446,  1192,    -1,    -1,   131,    -1,    -1,    10,   846,   847,
      -1,  1209,  1235,   848,    -1,  1162,    57,  1236,   848,    -1,
      -1,   376,  1190,    -1,    -1,    18,   850,   851,    -1,   852,
      -1,   851,   852,    -1,  1178,   446,   853,  1178,    -1,    -1,
     339,   446,    -1,    -1,    51,   855,   856,   868,    -1,   857,
    1201,   858,   863,   866,   867,    -1,    -1,   422,    -1,   424,
      -1,   271,    -1,    -1,    -1,   497,   859,   860,    -1,   861,
      -1,   860,   861,    -1,   862,   308,    -1,   862,   805,  1192,
      -1,    -1,  1253,   357,    -1,  1253,    87,    -1,  1253,   498,
      -1,    -1,   864,  1266,  1209,    -1,   864,   865,    -1,   864,
       6,  1277,  1209,    -1,   376,    -1,   203,    -1,   460,    -1,
     308,    -1,    -1,  1304,   818,    -1,    -1,   294,   818,    -1,
      -1,   132,    -1,    -1,    52,   870,   871,    -1,  1200,    -1,
     871,  1200,    -1,    -1,    60,   873,   874,    -1,  1173,   875,
      -1,   874,  1173,   875,    -1,    -1,  1311,    -1,  1311,  1260,
     362,    -1,  1298,   287,   380,    -1,  1298,   262,    -1,    -1,
      74,   877,   878,   879,    -1,  1168,  1302,  1162,  1132,    -1,
      -1,   133,    -1,    71,    -1,    88,    -1,    -1,   111,   883,
     884,   886,    -1,  1173,  1283,  1145,    -1,   454,   885,    -1,
    1173,    -1,   885,  1173,    -1,    -1,   134,    -1,    -1,   119,
     888,   889,   900,    -1,  1200,   487,  1129,    -1,  1200,   488,
    1129,    -1,  1200,   485,  1129,    -1,  1200,   486,  1129,    -1,
    1191,   893,   897,  1129,    -1,   890,  1129,    -1,  1192,   503,
     898,  1129,    -1,   892,    -1,    -1,   890,   891,   892,    -1,
    1192,   830,   894,   834,   896,    -1,    -1,   484,  1176,    -1,
     484,   504,    -1,   484,   335,    -1,   484,    96,    -1,    -1,
     484,   895,    -1,    96,    -1,    97,    -1,    -1,   503,   898,
      -1,    -1,   298,    -1,   899,    -1,   898,   899,    -1,    38,
      -1,    45,   252,    -1,    45,   389,    -1,    46,    -1,    91,
      -1,   160,   156,    -1,   160,   158,    -1,   211,    -1,   265,
      -1,   318,    -1,   378,    -1,   473,    -1,   189,  1267,  1202,
      -1,    35,  1267,  1202,    -1,   391,   482,  1148,    -1,   391,
     123,  1148,    -1,    -1,   135,    -1,    -1,   121,   902,   903,
     904,    -1,  1192,   228,  1168,  1132,    -1,  1192,   228,  1192,
     203,  1168,  1132,    -1,  1192,    49,  1192,   203,  1168,  1132,
      -1,  1192,   228,  1192,   203,  1169,   361,  1169,  1132,    -1,
    1192,    49,  1192,   203,  1169,   361,  1169,  1132,    -1,    -1,
     136,    -1,    -1,   152,   906,   907,    -1,   256,   858,    -1,
      -1,   163,   909,   910,   921,    -1,   911,   913,    -1,   912,
      -1,   911,    17,   912,    -1,  1150,    -1,   464,    -1,   453,
      -1,   914,   916,    -1,   914,    -1,   915,    -1,   914,   915,
      -1,   917,   818,    -1,   501,   316,   818,    -1,   501,   918,
      -1,   917,   501,   918,    -1,   919,    -1,   918,    17,   919,
      -1,  1151,   920,    -1,    21,    -1,   464,    -1,   453,    -1,
      -1,   442,  1150,    -1,    -1,   137,    -1,    -1,   168,   923,
     924,    -1,    -1,   340,   925,    -1,   199,    -1,   324,   101,
      -1,   324,    -1,   394,    -1,   323,    -1,    -1,   864,  1192,
      -1,    -1,   195,   927,   928,    -1,  1189,    -1,    -1,   202,
     930,   931,    -1,  1213,    -1,    -1,   205,   933,   934,    -1,
    1294,  1177,   935,    -1,    -1,   114,  1278,  1209,    -1,   206,
     925,    -1,    -1,   215,   938,  1149,  1292,   939,   940,    -1,
     818,   128,   818,    -1,   128,   818,    -1,   818,    -1,    -1,
     139,    -1,    -1,   222,   942,   943,    -1,  1189,   944,   945,
     946,   950,    -1,    -1,  1298,   175,    -1,    -1,     9,  1294,
     498,    -1,   949,  1294,   498,    -1,    -1,   365,   947,    -1,
     948,    -1,   947,   948,    -1,   949,  1257,    49,  1192,    -1,
      12,    -1,    15,    -1,   301,    -1,    16,    -1,   302,    -1,
     277,    -1,   278,    -1,    -1,  1292,  1294,   110,    -1,    -1,
     224,   952,   953,    -1,  1174,    -1,   953,  1174,    -1,    -1,
     227,   955,   956,    -1,   957,   958,    -1,  1209,    -1,  1220,
      -1,  1223,    -1,   959,   961,    -1,   959,    -1,   961,    -1,
     962,    -1,    -1,   436,   960,   963,    -1,   365,   965,    -1,
      92,  1198,   446,  1199,   969,    -1,   964,    -1,   963,   964,
      -1,  1198,   188,    -1,    57,   969,    -1,     9,    -1,   241,
      -1,   468,    -1,  1198,   969,    -1,   966,    -1,   965,   966,
      -1,    57,    49,  1198,   969,    -1,   967,   968,    -1,    -1,
       9,    -1,   241,    -1,   177,    -1,   468,    -1,  1198,    49,
    1199,   969,    -1,    -1,   969,   970,    -1,    37,  1265,  1192,
      -1,     8,  1265,  1192,    -1,    -1,   269,   972,  1046,    -1,
      -1,   273,   974,   975,    -1,  1192,   446,  1189,    -1,    94,
    1192,   446,  1189,    -1,    -1,   275,   977,   978,   979,    -1,
    1192,    49,  1168,  1132,    -1,  1192,    49,  1192,   203,  1168,
    1132,    -1,    -1,   140,    -1,    -1,   311,   981,   982,    -1,
     983,   984,  1172,   985,    -1,   982,   983,   984,  1172,   985,
      -1,   225,    -1,   317,    -1,   233,    -1,   170,    -1,    -1,
     404,  1298,   637,    -1,    -1,  1298,   287,   380,    -1,  1298,
     262,    -1,   379,    -1,    -1,   324,   987,   988,    -1,   992,
     993,    -1,    -1,   993,   989,   818,   990,    -1,   993,   991,
      -1,    -1,   141,    -1,   141,    -1,   451,    -1,  1178,    -1,
    1178,   442,  1178,    -1,    -1,  1201,   445,    -1,   190,    -1,
     994,   481,   995,    -1,   994,   499,   996,    -1,    -1,  1298,
     439,  1123,    -1,   168,    -1,  1149,    -1,   997,    -1,   996,
       8,   997,    -1,  1209,   196,  1192,    49,  1192,   481,  1149,
      -1,    -1,   349,   999,  1000,  1005,    -1,  1173,  1238,  1283,
    1001,  1002,  1003,  1004,    -1,    -1,   228,  1209,    -1,    -1,
     217,   262,    -1,  1298,   262,    -1,  1298,   236,   262,    -1,
    1298,   287,   262,    -1,  1298,   216,   262,    -1,  1298,   500,
      -1,    -1,   237,  1267,  1209,    -1,  1145,    -1,  1139,    -1,
      -1,   143,    -1,   350,    -1,    -1,   360,  1008,  1009,    -1,
    1170,  1121,    -1,   374,    -1,    -1,   375,  1012,  1013,  1014,
      -1,  1173,  1283,  1001,  1138,    -1,    -1,   144,    -1,    -1,
     381,  1016,  1017,  1019,    -1,  1170,  1121,  1018,  1145,    -1,
      -1,  1298,   262,    -1,  1298,   287,   262,    -1,    -1,   145,
      -1,   385,    -1,    -1,   393,  1022,  1023,  1028,    -1,  1171,
    1024,  1025,  1026,    -1,     9,  1171,  1025,   501,  1150,   818,
      -1,    -1,   499,  1209,    -1,    -1,   129,   818,    -1,  1027,
      -1,  1027,  1026,    -1,   501,  1149,   818,    -1,    -1,   146,
      -1,    -1,   403,  1030,  1031,    -1,  1034,    -1,  1035,    -1,
    1038,    -1,  1039,    -1,  1040,    -1,  1042,    -1,   309,    -1,
     307,    -1,   482,    -1,   123,    -1,   153,  1198,   446,  1198,
      -1,  1206,    31,  1036,    -1,  1037,    -1,  1036,  1037,    -1,
      38,  1032,    -1,    46,  1032,    -1,   211,  1032,    -1,   265,
    1032,    -1,   378,  1032,    -1,   473,  1032,    -1,   243,  1032,
      -1,   318,  1032,    -1,  1189,   446,   152,  1197,    -1,  1189,
     446,  1192,    -1,  1189,  1033,    49,  1192,    -1,  1041,    -1,
    1040,  1041,    -1,  1175,   446,  1032,    -1,  1043,    -1,  1042,
    1043,    -1,  1189,   446,   464,    -1,  1189,   446,   453,    -1,
      -1,   412,  1045,  1046,    -1,    -1,  1207,  1048,  1050,  1051,
    1047,  1052,  1053,    -1,    -1,  1048,  1278,   717,  1269,  1049,
      -1,    -1,  1049,  1213,    -1,    -1,  1314,  1263,    -1,    -1,
    1299,  1267,  1182,    -1,    -1,   497,  1172,    -1,   225,   337,
    1267,   992,    -1,    -1,   203,  1172,    -1,   317,   337,  1267,
     992,    -1,    -1,   421,  1055,  1056,  1062,    -1,  1173,  1058,
    1057,  1145,    -1,    -1,  1298,  1313,  1162,    -1,    -1,   237,
    1267,  1059,  1209,    -1,   177,    -1,   240,    -1,  1155,    -1,
    1239,  1156,    -1,  1239,  1157,    -1,  1239,  1158,    -1,  1239,
    1159,    -1,  1060,    -1,  1061,    -1,   290,  1155,    -1,   293,
      -1,    -1,   147,    -1,    -1,   426,   387,  1064,  1065,    -1,
     426,  1067,    -1,    -1,   864,  1192,    -1,  1298,   161,  1290,
    1066,    -1,  1298,   289,  1290,  1066,    -1,    -1,  1192,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,    -1,   427,
    1069,  1070,  1074,    -1,  1071,   228,  1209,  1073,  1135,    -1,
    1072,    -1,  1071,  1072,    -1,  1192,    -1,   112,  1253,   410,
      -1,   112,  1253,  1192,    -1,    -1,  1298,   330,  1267,  1209,
      -1,    -1,   148,    -1,    -1,   430,  1076,  1077,  1078,    -1,
    1191,   196,  1168,  1132,    -1,  1191,   196,  1192,   203,  1168,
    1132,    -1,    94,  1209,   196,  1209,  1241,  1132,    -1,    -1,
     149,    -1,   432,  1080,    -1,    -1,   336,    -1,    -1,   438,
    1082,  1083,    -1,  1174,    -1,  1083,  1174,    -1,    -1,   469,
    1085,  1086,    -1,  1209,   196,  1198,   446,  1199,    -1,    -1,
     475,  1088,  1089,    -1,  1173,  1090,    -1,    -1,   351,    -1,
     353,    -1,    -1,   480,  1092,  1093,  1102,    -1,  1209,  1094,
    1097,  1073,  1101,  1135,    -1,    -1,   112,  1253,  1095,    -1,
    1096,    -1,  1095,   313,  1096,    -1,  1233,  1198,    -1,   228,
    1098,    -1,  1097,  1098,    -1,  1209,  1099,  1100,    -1,    -1,
     113,  1262,  1209,    -1,    -1,    95,  1262,  1209,    -1,    -1,
     436,  1262,  1209,    -1,    -1,   150,    -1,    -1,   492,  1104,
    1105,    -1,  1106,    -1,  1109,    -1,  1113,    -1,  1115,    -1,
    1116,    -1,  1107,  1247,  1289,  1303,  1281,  1278,  1108,    -1,
      -1,   204,    -1,  1172,    -1,   225,    -1,   317,    -1,   233,
      -1,   170,    -1,  1260,   107,  1278,  1110,    -1,  1111,    -1,
    1110,  1111,    -1,  1179,    -1,     9,   338,    -1,     9,  1112,
    1213,    -1,    -1,   358,    -1,   358,   306,    -1,   306,    -1,
    1251,   340,  1114,    -1,   421,    -1,   129,    -1,  1107,    37,
     367,  1209,    -1,  1117,    -1,   166,    -1,   127,    -1,    -1,
     507,  1119,  1120,  1125,    -1,  1170,  1121,  1122,  1018,  1124,
      -1,    -1,   196,  1205,    -1,    -1,  1123,  1246,  1202,  1271,
      -1,  1123,  1246,  1176,    -1,  1123,  1246,   321,    -1,    37,
      -1,     8,    -1,  1145,    -1,  1142,    -1,    -1,   151,    -1,
    1127,  1128,    -1,    -1,   165,   818,    -1,    -1,   294,   818,
      -1,  1130,  1131,    -1,    -1,   165,   818,    -1,    -1,   294,
     818,    -1,  1133,  1134,    -1,    -1,   411,   818,    -1,    -1,
     297,   818,    -1,  1136,  1137,    -1,    -1,   461,   818,    -1,
      -1,   296,   818,    -1,  1140,  1141,    -1,  1140,    -1,  1140,
    1141,    -1,  1140,    -1,  1141,    -1,   129,   818,    -1,   291,
     818,    -1,  1143,  1144,    -1,  1143,    -1,  1144,    -1,   157,
     818,    -1,   292,   818,    -1,  1146,  1147,    -1,    -1,   231,
     818,    -1,    -1,   295,   818,    -1,    -1,  1204,  1312,    -1,
    1150,    -1,  1151,    -1,    -1,  1152,  1153,    -1,  1154,    -1,
    1153,   232,    -1,  1153,  1154,    -1,  1192,    -1,   462,    -1,
     448,    -1,   463,    -1,   458,    -1,   459,    -1,   450,    -1,
     169,    -1,  1155,    -1,  1156,    -1,  1157,    -1,  1158,    -1,
    1159,    -1,   293,    -1,   290,    -1,    20,    -1,   313,    -1,
     308,    -1,   301,    -1,    12,    -1,    13,    -1,    14,    -1,
     332,    -1,   284,    -1,   452,    -1,   159,  1294,    -1,   455,
      -1,   207,    -1,   457,    -1,   246,    -1,   208,    -1,   247,
      -1,  1162,    -1,  1160,  1161,  1162,    -1,    -1,    70,    -1,
     398,    -1,  1162,   463,  1163,    -1,  1162,   458,  1163,    -1,
    1163,    -1,  1163,   459,  1164,    -1,  1163,   450,  1164,    -1,
    1164,    -1,  1165,   169,  1164,    -1,  1165,    -1,   463,  1166,
      -1,   458,  1166,    -1,  1166,    -1,   462,  1162,   448,    -1,
    1195,    -1,   251,    -1,   251,  1305,   504,    -1,   253,    -1,
     253,  1305,   504,    -1,   322,    -1,   322,  1305,   504,    -1,
    1169,    -1,  1168,  1169,    -1,  1190,  1241,    -1,  1213,    -1,
    1213,    -1,  1173,    -1,  1172,  1173,    -1,   504,    -1,   504,
      -1,  1176,    -1,  1175,  1176,    -1,   271,    -1,    -1,  1177,
    1178,    -1,  1179,    -1,  1213,    -1,  1180,    -1,  1180,  1305,
    1180,    -1,   256,    -1,  1182,    -1,  1181,  1182,    -1,  1213,
      -1,   504,    -1,  1185,    -1,  1184,  1185,    -1,   504,    -1,
    1182,    -1,   256,    -1,   504,    -1,   504,    -1,  1190,    -1,
    1189,  1190,    -1,  1211,    -1,  1221,    -1,     6,  1277,  1210,
      -1,  1192,    -1,  1191,  1192,    -1,  1209,    -1,  1220,    -1,
    1223,    -1,  1167,    -1,   245,  1210,    -1,   245,  1221,    -1,
     245,  1223,    -1,     6,  1277,  1196,  1197,    -1,     6,  1277,
    1210,    -1,   271,    -1,  1195,    -1,  1193,  1195,    -1,  1209,
      -1,  1221,    -1,  1223,    -1,  1209,    -1,  1221,    -1,  1223,
      -1,  1167,    -1,   245,  1210,    -1,   245,  1221,    -1,   245,
    1223,    -1,   340,    -1,   152,    -1,  1210,    -1,   256,    -1,
    1209,    -1,  1221,    -1,  1209,    -1,  1220,    -1,  1209,    -1,
     256,    -1,  1209,    -1,   256,    -1,  1223,    -1,  1206,    -1,
    1216,    -1,   510,    -1,  1206,    -1,  1218,    -1,  1206,    -1,
    1216,    -1,  1209,    -1,  1220,    -1,  1223,    -1,  1208,    -1,
    1208,    -1,  1213,    -1,  1213,  1214,    -1,  1210,    -1,  1213,
    1214,  1215,    -1,  1213,  1214,    -1,  1213,  1215,    -1,  1213,
      -1,  1212,    -1,  1213,  1214,  1215,    -1,  1213,  1214,    -1,
    1213,  1215,    -1,  1213,    -1,   504,    -1,   504,  1305,  1213,
      -1,   462,  1160,   448,    -1,   462,  1162,   449,   448,    -1,
     462,  1162,   449,  1162,   448,    -1,   256,    -1,   256,    -1,
     256,    -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,
     212,    -1,   266,    -1,   460,    -1,  1221,    -1,     9,  1222,
      -1,  1222,    -1,  1221,   447,  1222,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,
      -1,  1224,  1227,    -1,  1225,   462,  1194,   448,  1227,    -1,
    1226,   462,  1160,   448,  1227,    -1,   470,   462,  1229,   448,
    1227,    -1,   303,   462,  1230,   448,    -1,   258,   462,  1231,
     448,  1227,    -1,   259,   462,  1231,   448,  1227,    -1,   260,
     462,  1231,   448,  1227,    -1,   201,  1228,    -1,   495,  1228,
      -1,    99,    -1,   502,    -1,   490,    -1,   264,    -1,   377,
      -1,    82,    -1,   428,    -1,   429,    -1,    -1,   462,  1162,
     449,   448,    -1,   462,  1162,   449,  1162,   448,    -1,    -1,
     462,  1160,   448,    -1,   462,   448,    -1,  1194,    -1,  1194,
    1161,   241,    -1,  1194,  1161,   468,    -1,  1194,    -1,  1194,
    1161,  1194,    -1,  1162,    -1,  1162,  1161,  1182,    -1,    -1,
      -1,     9,    -1,    -1,  1314,    -1,    -1,   223,    -1,    -1,
     223,  1237,    -1,    -1,   446,  1199,    -1,    -1,   285,    -1,
     334,    -1,    -1,   290,    -1,    -1,   312,    -1,   290,   312,
      -1,    -1,   386,  1242,    -1,    -1,   272,  1267,  1243,    -1,
      34,    -1,   281,    -1,   282,    -1,   283,    -1,   344,    -1,
     466,    -1,   467,    -1,   471,    -1,    -1,   400,  1254,    -1,
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
     176,    -1,    -1,   188,    -1,    -1,   196,    -1,    -1,   218,
      -1,    -1,   314,    -1,   218,   314,    -1,    -1,   221,    -1,
      -1,   456,    -1,    -1,   228,    -1,    -1,   232,    -1,    -1,
     232,    -1,    22,    -1,    -1,   237,    -1,    -1,   242,    -1,
     384,    -1,    -1,   252,    -1,   254,    -1,    -1,   248,  1267,
      -1,   249,  1248,    -1,    -1,   254,    -1,    -1,   272,    -1,
      -1,   299,    -1,    -1,   299,    -1,   300,    -1,    -1,   306,
      -1,    -1,   309,    -1,    -1,   423,   232,    -1,   423,    -1,
     232,    -1,    -1,   316,    -1,    -1,   337,    -1,    -1,   340,
      -1,    -1,   351,    -1,    -1,   384,    -1,    -1,   405,    -1,
      -1,   406,    -1,    -1,   405,    -1,   405,   232,    -1,    -1,
     410,    -1,    -1,   418,    -1,    -1,   423,    -1,    -1,   437,
      -1,    -1,   441,    -1,    -1,   445,    -1,    -1,   446,    -1,
      -1,   446,    -1,   497,    -1,    -1,   501,    -1,    -1,   501,
     403,   446,    -1,    -1,   503,    -1,    63,   401,    -1,   401,
      -1,    66,    -1,    64,    -1,    67,    -1,    65,    -1,   452,
      -1,   159,    -1,   165,    -1,   161,    -1,   165,    -1,   461,
      -1,   218,    -1,   306,    -1,   418,    -1,   308,    -1,   252,
      -1,   254,    -1,   351,    -1,   353,    -1,    57,    -1,   505,
      -1,   351,  1267,    -1,   353,  1248,    -1,   356,    -1,   474,
      -1,   252,    -1,   254,    -1,   410,    -1,   244,    -1,   503,
     124,    -1,   124,    -1,   340,    63,   401,    -1,    63,   401,
      -1,   401,    -1,   116,    -1,   106,    -1,    89,   210,    -1,
      54,    -1,    89,   187,    -1,    53,    -1,   321,   210,    -1,
     325,    -1,   321,   187,    -1,   326,    -1,   366,   210,    -1,
     383,    -1,   366,   187,    -1,   382,    -1,    89,  1267,    -1,
      90,  1248,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1366,  1366,  1366,  1398,  1399,  1403,  1404,  1408,  1409,
    1413,  1413,  1436,  1443,  1450,  1456,  1457,  1458,  1462,  1463,
    1467,  1491,  1492,  1496,  1530,  1536,  1548,  1522,  1558,  1557,
    1595,  1630,  1631,  1635,  1636,  1639,  1640,  1644,  1653,  1662,
    1663,  1667,  1671,  1680,  1681,  1689,  1690,  1700,  1701,  1705,
    1706,  1707,  1708,  1709,  1716,  1715,  1728,  1729,  1732,  1733,
    1747,  1746,  1756,  1757,  1758,  1759,  1763,  1764,  1768,  1769,
    1770,  1771,  1775,  1782,  1789,  1796,  1807,  1811,  1815,  1819,
    1826,  1827,  1834,  1833,  1844,  1845,  1846,  1853,  1854,  1858,
    1862,  1874,  1878,  1879,  1884,  1887,  1894,  1899,  1910,  1923,
    1924,  1932,  1933,  1937,  1938,  1939,  1940,  1941,  1942,  1943,
    1944,  1945,  1946,  1947,  1948,  1956,  1955,  1974,  1984,  1997,
    2005,  2008,  2009,  2013,  2023,  2039,  2038,  2062,  2068,  2074,
    2080,  2086,  2092,  2102,  2106,  2113,  2117,  2122,  2121,  2132,
    2136,  2143,  2144,  2145,  2146,  2147,  2148,  2155,  2170,  2173,
    2180,  2188,  2192,  2203,  2223,  2231,  2242,  2243,  2249,  2270,
    2271,  2275,  2279,  2300,  2323,  2405,  2408,  2417,  2436,  2452,
    2470,  2488,  2505,  2521,  2522,  2529,  2530,  2538,  2539,  2549,
    2550,  2555,  2554,  2575,  2585,  2586,  2590,  2591,  2592,  2593,
    2594,  2595,  2596,  2597,  2598,  2599,  2600,  2601,  2602,  2609,
    2615,  2625,  2638,  2651,  2667,  2668,  2669,  2670,  2673,  2674,
    2680,  2681,  2685,  2689,  2690,  2695,  2698,  2699,  2706,  2714,
    2715,  2716,  2723,  2750,  2761,  2768,  2770,  2771,  2777,  2777,
    2784,  2789,  2794,  2801,  2802,  2803,  2807,  2818,  2819,  2823,
    2828,  2833,  2838,  2849,  2860,  2870,  2878,  2879,  2880,  2886,
    2897,  2904,  2905,  2911,  2919,  2920,  2921,  2927,  2928,  2929,
    2936,  2937,  2941,  2942,  2948,  2976,  2977,  2978,  2979,  2986,
    2985,  3001,  3002,  3006,  3009,  3010,  3016,  3017,  3025,  3026,
    3034,  3035,  3039,  3060,  3059,  3076,  3083,  3087,  3093,  3094,
    3098,  3108,  3123,  3124,  3125,  3126,  3127,  3128,  3129,  3130,
    3131,  3138,  3145,  3145,  3145,  3151,  3171,  3205,  3236,  3237,
    3244,  3245,  3249,  3250,  3257,  3268,  3273,  3284,  3285,  3289,
    3290,  3296,  3307,  3325,  3326,  3330,  3331,  3332,  3336,  3343,
    3350,  3359,  3371,  3423,  3438,  3439,  3443,  3453,  3492,  3494,
    3493,  3509,  3512,  3512,  3529,  3530,  3532,  3536,  3538,  3537,
    3572,  3585,  3593,  3598,  3604,  3613,  3623,  3626,  3638,  3639,
    3640,  3641,  3645,  3649,  3653,  3657,  3661,  3665,  3669,  3673,
    3677,  3681,  3685,  3689,  3693,  3704,  3705,  3709,  3710,  3714,
    3715,  3716,  3720,  3721,  3725,  3751,  3755,  3764,  3768,  3777,
    3778,  3779,  3780,  3781,  3782,  3783,  3784,  3785,  3786,  3787,
    3788,  3789,  3790,  3797,  3821,  3849,  3852,  3861,  3886,  3897,
    3898,  3902,  3906,  3910,  3914,  3918,  3922,  3926,  3930,  3934,
    3938,  3942,  3946,  3950,  3955,  3960,  3964,  3968,  3976,  3980,
    3984,  3992,  3996,  4000,  4004,  4008,  4012,  4016,  4020,  4024,
    4032,  4040,  4044,  4048,  4052,  4056,  4060,  4068,  4069,  4073,
    4074,  4080,  4086,  4098,  4116,  4117,  4126,  4150,  4151,  4154,
    4155,  4162,  4186,  4187,  4204,  4205,  4208,  4209,  4216,  4217,
    4222,  4233,  4244,  4255,  4266,  4295,  4294,  4303,  4304,  4308,
    4309,  4312,  4313,  4326,  4339,  4360,  4369,  4383,  4385,  4384,
    4404,  4406,  4405,  4421,  4423,  4422,  4431,  4432,  4439,  4438,
    4451,  4452,  4453,  4460,  4465,  4469,  4470,  4476,  4483,  4487,
    4488,  4494,  4531,  4535,  4540,  4546,  4547,  4552,  4553,  4554,
    4555,  4556,  4560,  4567,  4574,  4581,  4588,  4594,  4595,  4600,
    4599,  4606,  4607,  4611,  4612,  4613,  4614,  4615,  4616,  4617,
    4618,  4619,  4620,  4621,  4622,  4623,  4624,  4625,  4626,  4630,
    4637,  4638,  4639,  4640,  4641,  4642,  4643,  4646,  4647,  4648,
    4651,  4652,  4656,  4663,  4669,  4670,  4674,  4675,  4679,  4686,
    4690,  4697,  4698,  4702,  4709,  4710,  4714,  4715,  4719,  4720,
    4721,  4725,  4726,  4730,  4731,  4735,  4742,  4749,  4757,  4759,
    4758,  4779,  4780,  4784,  4785,  4790,  4792,  4791,  4848,  4866,
    4867,  4871,  4875,  4879,  4883,  4887,  4891,  4895,  4899,  4903,
    4907,  4911,  4915,  4919,  4923,  4927,  4931,  4935,  4940,  4944,
    4948,  4953,  4958,  4963,  4968,  4969,  4970,  4971,  4972,  4973,
    4974,  4975,  4976,  4983,  4988,  4997,  4998,  5002,  5003,  5008,
    5011,  5015,  5023,  5026,  5030,  5038,  5049,  5057,  5059,  5069,
    5058,  5096,  5096,  5129,  5133,  5132,  5146,  5145,  5165,  5166,
    5171,  5178,  5180,  5184,  5194,  5196,  5204,  5212,  5220,  5249,
    5280,  5282,  5292,  5297,  5324,  5326,  5325,  5362,  5363,  5367,
    5368,  5369,  5386,  5387,  5398,  5397,  5447,  5448,  5452,  5500,
    5513,  5516,  5535,  5540,  5534,  5553,  5553,  5583,  5590,  5591,
    5592,  5593,  5594,  5595,  5596,  5597,  5598,  5599,  5600,  5601,
    5602,  5603,  5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,
    5612,  5613,  5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,
    5622,  5623,  5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,
    5632,  5633,  5634,  5635,  5636,  5637,  5638,  5639,  5653,  5665,
    5664,  5677,  5683,  5687,  5691,  5696,  5701,  5706,  5711,  5715,
    5719,  5723,  5727,  5732,  5736,  5740,  5744,  5748,  5752,  5756,
    5763,  5764,  5771,  5772,  5776,  5777,  5781,  5782,  5783,  5784,
    5785,  5789,  5793,  5794,  5797,  5798,  5801,  5802,  5808,  5809,
    5813,  5814,  5818,  5822,  5826,  5830,  5834,  5838,  5842,  5846,
    5850,  5854,  5858,  5862,  5866,  5870,  5874,  5878,  5882,  5886,
    5894,  5898,  5902,  5906,  5910,  5914,  5918,  5925,  5926,  5930,
    5934,  5952,  5951,  5960,  5964,  5968,  5974,  5975,  5982,  5986,
    5997,  5996,  6005,  6009,  6021,  6022,  6030,  6029,  6038,  6039,
    6043,  6049,  6049,  6056,  6055,  6065,  6085,  6089,  6094,  6099,
    6120,  6124,  6123,  6140,  6141,  6146,  6154,  6178,  6180,  6184,
    6193,  6206,  6209,  6213,  6217,  6240,  6241,  6245,  6246,  6251,
    6254,  6262,  6266,  6274,  6278,  6289,  6288,  6296,  6300,  6311,
    6310,  6318,  6323,  6331,  6332,  6333,  6334,  6335,  6343,  6342,
    6351,  6358,  6362,  6372,  6383,  6401,  6400,  6409,  6413,  6417,
    6422,  6430,  6434,  6445,  6444,  6454,  6458,  6462,  6466,  6470,
    6474,  6475,  6484,  6486,  6485,  6493,  6502,  6509,  6513,  6517,
    6521,  6531,  6533,  6537,  6538,  6541,  6543,  6550,  6551,  6555,
    6556,  6561,  6565,  6569,  6573,  6577,  6581,  6585,  6589,  6593,
    6597,  6601,  6605,  6609,  6613,  6617,  6621,  6628,  6632,  6643,
    6642,  6651,  6655,  6659,  6663,  6667,  6674,  6678,  6689,  6688,
    6696,  6716,  6715,  6739,  6747,  6748,  6753,  6764,  6775,  6789,
    6793,  6800,  6801,  6806,  6815,  6824,  6829,  6838,  6839,  6844,
    6906,  6907,  6908,  6912,  6913,  6917,  6921,  6932,  6931,  6943,
    6944,  6965,  6979,  7001,  7023,  7043,  7066,  7067,  7075,  7074,
    7083,  7094,  7093,  7103,  7110,  7109,  7122,  7131,  7135,  7146,
    7162,  7161,  7170,  7174,  7178,  7185,  7189,  7200,  7199,  7207,
    7215,  7216,  7220,  7221,  7222,  7227,  7230,  7237,  7241,  7249,
    7256,  7257,  7258,  7259,  7260,  7261,  7262,  7267,  7270,  7280,
    7279,  7288,  7294,  7306,  7305,  7314,  7318,  7322,  7326,  7333,
    7334,  7335,  7336,  7343,  7342,  7356,  7366,  7375,  7376,  7380,
    7381,  7382,  7383,  7384,  7385,  7389,  7390,  7394,  7399,  7406,
    7407,  7408,  7409,  7410,  7414,  7442,  7445,  7452,  7456,  7466,
    7465,  7478,  7477,  7485,  7489,  7500,  7499,  7508,  7512,  7519,
    7523,  7534,  7533,  7541,  7562,  7586,  7587,  7588,  7589,  7593,
    7594,  7598,  7599,  7600,  7601,  7613,  7612,  7623,  7629,  7628,
    7639,  7647,  7655,  7662,  7666,  7679,  7686,  7698,  7701,  7706,
    7710,  7721,  7728,  7729,  7733,  7734,  7737,  7738,  7743,  7754,
    7753,  7762,  7789,  7790,  7795,  7798,  7802,  7806,  7810,  7814,
    7818,  7825,  7826,  7830,  7831,  7835,  7839,  7849,  7860,  7859,
    7867,  7877,  7888,  7887,  7896,  7903,  7907,  7918,  7917,  7929,
    7938,  7941,  7945,  7952,  7956,  7966,  7978,  7977,  7986,  7990,
    7999,  8000,  8005,  8008,  8016,  8020,  8027,  8035,  8039,  8050,
    8049,  8063,  8064,  8065,  8066,  8067,  8068,  8072,  8073,  8077,
    8078,  8084,  8093,  8100,  8101,  8105,  8109,  8113,  8117,  8121,
    8125,  8129,  8133,  8142,  8146,  8155,  8164,  8165,  8169,  8178,
    8179,  8183,  8187,  8198,  8197,  8206,  8205,  8236,  8239,  8259,
    8260,  8263,  8264,  8272,  8273,  8278,  8283,  8293,  8309,  8314,
    8324,  8341,  8340,  8350,  8363,  8366,  8374,  8377,  8382,  8387,
    8395,  8396,  8397,  8398,  8399,  8400,  8404,  8412,  8413,  8417,
    8421,  8432,  8431,  8441,  8454,  8457,  8461,  8469,  8481,  8484,
    8491,  8492,  8493,  8494,  8501,  8500,  8509,  8516,  8517,  8521,
    8522,  8523,  8527,  8528,  8532,  8536,  8547,  8546,  8555,  8559,
    8563,  8570,  8574,  8584,  8595,  8596,  8603,  8602,  8611,  8617,
    8629,  8628,  8636,  8650,  8649,  8657,  8670,  8672,  8673,  8681,
    8680,  8689,  8697,  8698,  8703,  8704,  8709,  8716,  8717,  8722,
    8729,  8730,  8734,  8735,  8739,  8740,  8744,  8748,  8759,  8758,
    8767,  8768,  8769,  8770,  8771,  8775,  8802,  8805,  8817,  8827,
    8832,  8837,  8842,  8850,  8888,  8889,  8893,  8933,  8943,  8966,
    8967,  8968,  8969,  8973,  8982,  8988,  8998,  9007,  9016,  9017,
    9024,  9023,  9035,  9045,  9046,  9051,  9054,  9058,  9062,  9069,
    9070,  9074,  9075,  9079,  9083,  9095,  9098,  9099,  9108,  9109,
    9118,  9121,  9122,  9131,  9132,  9143,  9146,  9147,  9156,  9157,
    9169,  9172,  9174,  9184,  9185,  9197,  9198,  9202,  9203,  9204,
    9208,  9217,  9228,  9229,  9230,  9234,  9243,  9254,  9259,  9260,
    9269,  9270,  9281,  9285,  9295,  9302,  9309,  9309,  9319,  9320,
    9321,  9325,  9334,  9335,  9337,  9338,  9339,  9340,  9341,  9343,
    9344,  9345,  9346,  9347,  9348,  9350,  9351,  9352,  9354,  9355,
    9356,  9357,  9358,  9361,  9362,  9366,  9367,  9371,  9372,  9376,
    9377,  9381,  9385,  9391,  9395,  9401,  9402,  9403,  9407,  9408,
    9409,  9413,  9414,  9415,  9419,  9423,  9427,  9428,  9429,  9432,
    9433,  9443,  9455,  9464,  9476,  9485,  9497,  9512,  9513,  9518,
    9527,  9533,  9553,  9557,  9578,  9619,  9633,  9634,  9639,  9645,
    9646,  9651,  9663,  9664,  9665,  9672,  9683,  9684,  9688,  9696,
    9704,  9708,  9715,  9724,  9725,  9731,  9745,  9762,  9766,  9773,
    9774,  9775,  9782,  9786,  9793,  9794,  9795,  9796,  9797,  9801,
    9805,  9809,  9813,  9817,  9838,  9842,  9849,  9850,  9851,  9855,
    9856,  9857,  9858,  9859,  9863,  9867,  9874,  9875,  9879,  9880,
    9884,  9885,  9889,  9890,  9901,  9902,  9906,  9907,  9908,  9912,
    9913,  9914,  9921,  9922,  9926,  9927,  9931,  9932,  9933,  9939,
    9943,  9947,  9948,  9952,  9956,  9963,  9970,  9977,  9987,  9994,
   10004, 10014, 10024, 10037, 10041, 10049, 10057, 10061, 10071, 10086,
   10109, 10132, 10148, 10149, 10150, 10151, 10152, 10153, 10157, 10161,
   10178, 10182, 10189, 10190, 10191, 10192, 10193, 10194, 10195, 10201,
   10205, 10209, 10213, 10217, 10221, 10225, 10229, 10233, 10237, 10244,
   10245, 10249, 10250, 10251, 10255, 10256, 10257, 10261, 10265, 10269,
   10276, 10280, 10284, 10291, 10298, 10305, 10315, 10322, 10332, 10339,
   10351, 10359, 10360, 10364, 10365, 10369, 10370, 10375, 10378, 10386,
   10389, 10396, 10398, 10399, 10403, 10404, 10408, 10409, 10410, 10415,
   10418, 10431, 10435, 10443, 10447, 10451, 10455, 10459, 10463, 10467,
   10471, 10478, 10479, 10485, 10486, 10487, 10488, 10489, 10490, 10491,
   10492, 10493, 10494, 10495, 10496, 10497, 10498, 10499, 10500, 10501,
   10502, 10503, 10504, 10505, 10506, 10507, 10508, 10509, 10510, 10511,
   10512, 10513, 10514, 10515, 10516, 10517, 10518, 10519, 10520, 10521,
   10522, 10523, 10524, 10525, 10526, 10527, 10528, 10529, 10530, 10531,
   10532, 10533, 10534, 10535, 10536, 10537, 10538, 10539, 10540, 10541,
   10542, 10543, 10544, 10545, 10546, 10547, 10548, 10549, 10550, 10551,
   10552, 10553, 10554, 10561, 10561, 10562, 10562, 10563, 10563, 10564,
   10564, 10565, 10565, 10566, 10566, 10567, 10567, 10568, 10568, 10569,
   10569, 10570, 10570, 10571, 10571, 10572, 10572, 10573, 10573, 10574,
   10574, 10575, 10575, 10576, 10576, 10577, 10577, 10578, 10578, 10578,
   10579, 10579, 10580, 10580, 10581, 10581, 10582, 10582, 10583, 10583,
   10583, 10584, 10584, 10585, 10585, 10585, 10586, 10586, 10586, 10587,
   10587, 10587, 10588, 10588, 10589, 10589, 10590, 10590, 10591, 10591,
   10591, 10592, 10592, 10593, 10593, 10594, 10594, 10594, 10594, 10595,
   10595, 10596, 10596, 10597, 10597, 10598, 10598, 10599, 10599, 10600,
   10600, 10601, 10601, 10602, 10602, 10602, 10603, 10603, 10604, 10604,
   10605, 10605, 10606, 10606, 10607, 10607, 10608, 10608, 10609, 10609,
   10610, 10610, 10610, 10611, 10611, 10612, 10612, 10613, 10613, 10617,
   10617, 10618, 10618, 10619, 10619, 10620, 10620, 10621, 10621, 10622,
   10622, 10623, 10623, 10624, 10624, 10625, 10625, 10626, 10626, 10627,
   10627, 10628, 10628, 10629, 10629, 10630, 10630, 10631, 10631, 10632,
   10632, 10635, 10636, 10637, 10641, 10641, 10642, 10642, 10643, 10643,
   10644, 10644, 10645, 10645, 10646, 10646, 10647, 10647, 10648, 10648
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
  "opt_at_block", "opt_accp_attr", "accp_attrs", "accp_attr",
  "update_default", "end_accept", "add_statement", "$@39", "add_body",
  "add_to", "end_add", "allocate_statement", "$@40", "allocate_body",
  "allocate_returning", "alter_statement", "$@41", "alter_body",
  "alter_entry", "_proceed_to", "call_statement", "$@42", "call_body",
  "mnemonic_conv", "call_using", "$@43", "call_param_list", "call_param",
  "call_type", "call_returning", "return_give", "null_or_omitted",
  "call_on_exception", "call_not_on_exception", "end_call",
  "cancel_statement", "$@44", "cancel_body", "close_statement", "$@45",
  "close_body", "close_option", "compute_statement", "$@46",
  "compute_body", "end_compute", "commit_statement", "continue_statement",
  "delete_statement", "$@47", "delete_body", "delete_file_list",
  "end_delete", "display_statement", "$@48", "display_body",
  "display_list", "$@49", "display_atom", "display_upon",
  "display_upon_crt", "crt_under", "with_clause", "with_no_adv_clause",
  "disp_attrs", "disp_attr", "end_display", "divide_statement", "$@50",
  "divide_body", "end_divide", "entry_statement", "$@51", "entry_body",
  "evaluate_statement", "$@52", "evaluate_body", "evaluate_subject_list",
  "evaluate_subject", "evaluate_condition_list", "evaluate_case_list",
  "evaluate_case", "evaluate_other", "evaluate_when_list",
  "evaluate_object_list", "evaluate_object", "opt_evaluate_thru_expr",
  "end_evaluate", "exit_statement", "$@53", "exit_body",
  "exit_program_returning", "free_statement", "$@54", "free_body",
  "generate_statement", "$@55", "generate_body", "goto_statement", "$@56",
  "go_body", "goto_depending", "goback_statement", "if_statement", "$@57",
  "if_else_statements", "end_if", "initialize_statement", "$@58",
  "initialize_body", "initialize_filler", "initialize_value",
  "initialize_replacing", "initialize_replacing_list",
  "initialize_replacing_item", "initialize_category", "initialize_default",
  "initiate_statement", "$@59", "initiate_body", "inspect_statement",
  "$@60", "inspect_body", "send_identifier", "inspect_list",
  "inspect_tallying", "$@61", "inspect_replacing", "inspect_converting",
  "tallying_list", "tallying_item", "replacing_list", "replacing_item",
  "rep_keyword", "replacing_region", "inspect_region",
  "inspect_before_after", "merge_statement", "$@62", "move_statement",
  "$@63", "move_body", "multiply_statement", "$@64", "multiply_body",
  "end_multiply", "open_statement", "$@65", "open_body", "open_mode",
  "open_sharing", "open_option", "perform_statement", "$@66",
  "perform_body", "$@67", "end_perform", "term_or_dot",
  "perform_procedure", "perform_option", "perform_test", "cond_or_exit",
  "perform_varying_list", "perform_varying", "read_statement", "$@68",
  "read_body", "read_into", "with_lock", "read_key", "read_handler",
  "end_read", "ready_statement", "release_statement", "$@69",
  "release_body", "reset_statement", "return_statement", "$@70",
  "return_body", "end_return", "rewrite_statement", "$@71", "rewrite_body",
  "write_lock", "end_rewrite", "rollback_statement", "search_statement",
  "$@72", "search_body", "search_varying", "search_at_end", "search_whens",
  "search_when", "end_search", "set_statement", "$@73", "set_body",
  "on_or_off", "up_or_down", "set_environment", "set_attr",
  "set_attr_clause", "set_attr_one", "set_to", "set_up_down",
  "set_to_on_off_sequence", "set_to_on_off", "set_to_true_false_sequence",
  "set_to_true_false", "sort_statement", "$@74", "sort_body", "@75",
  "sort_key_list", "opt_key_list", "sort_duplicates", "sort_collating",
  "sort_input", "sort_output", "start_statement", "$@76", "start_body",
  "sizelen_clause", "start_key", "start_op", "disallowed_op",
  "not_equal_op", "end_start", "stop_statement", "$@77", "stop_returning",
  "_opt_status", "stop_literal", "string_statement", "$@78", "string_body",
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
     837,   837,   837,   837,   837,   837,   837,   838,   838,   839,
     839,   841,   840,   842,   842,   842,   843,   843,   844,   844,
     846,   845,   847,   847,   848,   848,   850,   849,   851,   851,
     852,   853,   853,   855,   854,   856,   857,   857,   857,   857,
     858,   859,   858,   860,   860,   861,   861,   862,   862,   862,
     862,   863,   863,   863,   863,   864,   864,   865,   865,   866,
     866,   867,   867,   868,   868,   870,   869,   871,   871,   873,
     872,   874,   874,   875,   875,   875,   875,   875,   877,   876,
     878,   879,   879,   880,   881,   883,   882,   884,   884,   885,
     885,   886,   886,   888,   887,   889,   889,   889,   889,   889,
     889,   889,   890,   891,   890,   892,   893,   893,   893,   893,
     893,   894,   894,   895,   895,   896,   896,   897,   897,   898,
     898,   899,   899,   899,   899,   899,   899,   899,   899,   899,
     899,   899,   899,   899,   899,   899,   899,   900,   900,   902,
     901,   903,   903,   903,   903,   903,   904,   904,   906,   905,
     907,   909,   908,   910,   911,   911,   912,   912,   912,   913,
     913,   914,   914,   915,   916,   917,   917,   918,   918,   919,
     919,   919,   919,   920,   920,   921,   921,   923,   922,   924,
     924,   924,   924,   924,   924,   924,   925,   925,   927,   926,
     928,   930,   929,   931,   933,   932,   934,   935,   935,   936,
     938,   937,   939,   939,   939,   940,   940,   942,   941,   943,
     944,   944,   945,   945,   945,   946,   946,   947,   947,   948,
     949,   949,   949,   949,   949,   949,   949,   950,   950,   952,
     951,   953,   953,   955,   954,   956,   957,   957,   957,   958,
     958,   958,   958,   960,   959,   961,   962,   963,   963,   964,
     964,   964,   964,   964,   964,   965,   965,   966,   966,   967,
     967,   967,   967,   967,   968,   969,   969,   970,   970,   972,
     971,   974,   973,   975,   975,   977,   976,   978,   978,   979,
     979,   981,   980,   982,   982,   983,   983,   983,   983,   984,
     984,   985,   985,   985,   985,   987,   986,   988,   989,   988,
     988,   990,   990,   991,   991,   992,   992,   993,   993,   993,
     993,   993,   994,   994,   995,   995,   996,   996,   997,   999,
     998,  1000,  1001,  1001,  1002,  1002,  1002,  1002,  1002,  1002,
    1002,  1003,  1003,  1004,  1004,  1005,  1005,  1006,  1008,  1007,
    1009,  1010,  1012,  1011,  1013,  1014,  1014,  1016,  1015,  1017,
    1018,  1018,  1018,  1019,  1019,  1020,  1022,  1021,  1023,  1023,
    1024,  1024,  1025,  1025,  1026,  1026,  1027,  1028,  1028,  1030,
    1029,  1031,  1031,  1031,  1031,  1031,  1031,  1032,  1032,  1033,
    1033,  1034,  1035,  1036,  1036,  1037,  1037,  1037,  1037,  1037,
    1037,  1037,  1037,  1038,  1038,  1039,  1040,  1040,  1041,  1042,
    1042,  1043,  1043,  1045,  1044,  1047,  1046,  1048,  1048,  1049,
    1049,  1050,  1050,  1051,  1051,  1052,  1052,  1052,  1053,  1053,
    1053,  1055,  1054,  1056,  1057,  1057,  1058,  1058,  1058,  1058,
    1059,  1059,  1059,  1059,  1059,  1059,  1060,  1061,  1061,  1062,
    1062,  1064,  1063,  1063,  1065,  1065,  1065,  1065,  1066,  1066,
    1067,  1067,  1067,  1067,  1069,  1068,  1070,  1071,  1071,  1072,
    1072,  1072,  1073,  1073,  1074,  1074,  1076,  1075,  1077,  1077,
    1077,  1078,  1078,  1079,  1080,  1080,  1082,  1081,  1083,  1083,
    1085,  1084,  1086,  1088,  1087,  1089,  1090,  1090,  1090,  1092,
    1091,  1093,  1094,  1094,  1095,  1095,  1096,  1097,  1097,  1098,
    1099,  1099,  1100,  1100,  1101,  1101,  1102,  1102,  1104,  1103,
    1105,  1105,  1105,  1105,  1105,  1106,  1107,  1107,  1108,  1108,
    1108,  1108,  1108,  1109,  1110,  1110,  1111,  1111,  1111,  1112,
    1112,  1112,  1112,  1113,  1114,  1114,  1115,  1116,  1117,  1117,
    1119,  1118,  1120,  1121,  1121,  1122,  1122,  1122,  1122,  1123,
    1123,  1124,  1124,  1125,  1125,  1126,  1127,  1127,  1128,  1128,
    1129,  1130,  1130,  1131,  1131,  1132,  1133,  1133,  1134,  1134,
    1135,  1136,  1136,  1137,  1137,  1138,  1138,  1139,  1139,  1139,
    1140,  1141,  1142,  1142,  1142,  1143,  1144,  1145,  1146,  1146,
    1147,  1147,  1148,  1148,  1149,  1150,  1152,  1151,  1153,  1153,
    1153,  1154,  1154,  1154,  1154,  1154,  1154,  1154,  1154,  1154,
    1154,  1154,  1154,  1154,  1154,  1154,  1154,  1154,  1154,  1154,
    1154,  1154,  1154,  1154,  1154,  1155,  1155,  1156,  1156,  1157,
    1157,  1158,  1159,  1160,  1160,  1161,  1161,  1161,  1162,  1162,
    1162,  1163,  1163,  1163,  1164,  1164,  1165,  1165,  1165,  1166,
    1166,  1167,  1167,  1167,  1167,  1167,  1167,  1168,  1168,  1169,
    1170,  1171,  1172,  1172,  1173,  1174,  1175,  1175,  1176,  1177,
    1177,  1178,  1179,  1179,  1179,  1180,  1181,  1181,  1182,  1183,
    1184,  1184,  1185,  1186,  1186,  1187,  1188,  1189,  1189,  1190,
    1190,  1190,  1191,  1191,  1192,  1192,  1192,  1192,  1192,  1192,
    1192,  1192,  1192,  1192,  1193,  1193,  1194,  1194,  1194,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1196,  1196,  1197,  1197,
    1198,  1198,  1199,  1199,  1200,  1200,  1201,  1201,  1201,  1202,
    1202,  1202,  1203,  1203,  1204,  1204,  1205,  1205,  1205,  1206,
    1207,  1208,  1208,  1209,  1210,  1210,  1210,  1210,  1211,  1212,
    1212,  1212,  1212,  1213,  1213,  1214,  1215,  1215,  1216,  1217,
    1218,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1220,  1220,
    1221,  1221,  1222,  1222,  1222,  1222,  1222,  1222,  1222,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1224,
    1224,  1225,  1225,  1225,  1226,  1226,  1226,  1227,  1227,  1227,
    1228,  1228,  1228,  1229,  1229,  1229,  1230,  1230,  1231,  1231,
    1232,  1233,  1233,  1234,  1234,  1235,  1235,  1236,  1236,  1237,
    1237,  1238,  1238,  1238,  1239,  1239,  1240,  1240,  1240,  1241,
    1241,  1242,  1242,  1243,  1243,  1243,  1243,  1243,  1243,  1243,
    1243,  1244,  1244,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1245,  1246,  1246,  1247,  1247,  1248,  1248,  1249,
    1249,  1250,  1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,
    1254,  1255,  1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,
    1259,  1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1263,
    1264,  1264,  1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,
    1268,  1269,  1269,  1270,  1270,  1270,  1271,  1271,  1271,  1272,
    1272,  1272,  1273,  1273,  1274,  1274,  1275,  1275,  1276,  1276,
    1276,  1277,  1277,  1278,  1278,  1279,  1279,  1279,  1279,  1280,
    1280,  1281,  1281,  1282,  1282,  1283,  1283,  1284,  1284,  1285,
    1285,  1286,  1286,  1287,  1287,  1287,  1288,  1288,  1289,  1289,
    1290,  1290,  1291,  1291,  1292,  1292,  1293,  1293,  1294,  1294,
    1295,  1295,  1295,  1296,  1296,  1297,  1297,  1298,  1298,  1299,
    1299,  1300,  1300,  1301,  1301,  1302,  1302,  1303,  1303,  1304,
    1304,  1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,
    1309,  1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,
    1314,  1315,  1315,  1315,  1316,  1316,  1317,  1317,  1318,  1318,
    1319,  1319,  1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323
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
       1,     1,     1,     4,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     0,
       1,     0,     4,     4,     5,     6,     0,     2,     0,     1,
       0,     3,     3,     4,     0,     2,     0,     3,     1,     2,
       4,     0,     2,     0,     4,     6,     0,     1,     1,     1,
       0,     0,     3,     1,     2,     2,     3,     0,     2,     2,
       2,     0,     3,     2,     4,     1,     1,     1,     1,     0,
       2,     0,     2,     0,     1,     0,     3,     1,     2,     0,
       3,     2,     3,     0,     1,     3,     3,     2,     0,     4,
       4,     0,     1,     1,     1,     0,     4,     3,     2,     1,
       2,     0,     1,     0,     4,     3,     3,     3,     3,     4,
       2,     4,     1,     0,     3,     5,     0,     2,     2,     2,
       2,     0,     2,     1,     1,     0,     2,     0,     1,     1,
       2,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     0,     1,     0,
       4,     4,     6,     6,     8,     8,     0,     1,     0,     3,
       2,     0,     4,     2,     1,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     3,     2,     3,     1,     3,     2,
       1,     1,     1,     0,     2,     0,     1,     0,     3,     0,
       2,     1,     2,     1,     1,     1,     0,     2,     0,     3,
       1,     0,     3,     1,     0,     3,     3,     0,     3,     2,
       0,     6,     3,     2,     1,     0,     1,     0,     3,     5,
       0,     2,     0,     3,     3,     0,     2,     1,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       3,     1,     2,     0,     3,     2,     1,     1,     1,     2,
       1,     1,     1,     0,     3,     2,     5,     1,     2,     2,
       2,     1,     1,     1,     2,     1,     2,     4,     2,     0,
       1,     1,     1,     1,     4,     0,     2,     3,     3,     0,
       3,     0,     3,     3,     4,     0,     4,     4,     6,     0,
       1,     0,     3,     4,     5,     1,     1,     1,     1,     0,
       3,     0,     3,     2,     1,     0,     3,     2,     0,     4,
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
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     4,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     2,     1,     1,     3,
       2,     2,     1,     1,     3,     3,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     5,     5,     4,     5,     5,     5,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     5,
       0,     3,     2,     1,     3,     3,     1,     3,     1,     3,
       0,     0,     1,     0,     1,     0,     1,     0,     2,     0,
       2,     0,     1,     1,     0,     1,     0,     1,     2,     0,
       2,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     1,     0,     1,     0,
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
    1766,    46,     0,     0,     0,  1809,  1766,  1766,  1766,     0,
       0,     0,     0,     0,  1766,     0,     0,  1741,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1767,     0,     0,  1495,   125,  1766,
    1766,  1810,  1766,     0,     0,     0,     0,  1766,  1766,    60,
      82,     0,    54,    98,  1742,     0,  1766,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1803,    39,  1766,     0,     0,     0,  1563,   169,  1488,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1496,
     150,   151,  1768,   154,  1568,  1188,  1187,   116,   120,  1795,
    1766,     0,   100,   149,   176,   177,    38,  1804,    36,     0,
    1575,  1571,  1576,  1574,  1572,  1577,  1573,   158,   159,   161,
     170,   165,  1851,  1852,     0,   163,     0,  1740,     0,     0,
       0,  1766,  1873,    80,    61,  1739,    66,    68,    69,    70,
      71,  1739,     0,  1766,     0,    83,     0,    87,    55,    58,
     152,  1770,  1769,   155,     0,  1795,  1798,  1797,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1838,   164,     0,  1564,   168,  1872,  1766,
       0,     0,    65,    67,    63,    81,  1739,  1766,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1569,
     153,   156,     0,  1796,   123,   118,   119,   122,   178,     0,
       0,  1637,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1871,    74,    64,     0,
    1489,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1638,   181,  1747,   266,   267,   268,  1729,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1748,  1822,  1730,  1751,
       0,   278,   259,   138,   139,  1859,  1860,    72,  1805,  1823,
    1743,  1752,     0,     0,     0,   280,     0,  1784,  1805,  1830,
       0,   239,     0,  1766,  1739,  1771,   241,     0,  1840,  1837,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1735,  1766,  1744,     0,  1474,   264,  1472,   277,     0,    25,
     140,  1785,  1766,  1806,  1771,  1831,  1832,   210,  1839,   242,
    1805,  1766,  1766,  1772,  1766,  1766,   251,  1729,   252,     0,
    1766,  1784,  1736,     0,     0,   270,   271,   274,  1473,   279,
     286,   287,   338,   281,   341,     0,     0,  1766,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1799,  1799,
       0,   253,     0,  1766,   240,   223,   272,     0,   273,     0,
     487,   282,  1620,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1494,  1493,   243,   244,   245,   246,   249,  1800,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1623,   216,   201,   217,   202,  1747,
     203,   200,   213,   199,   214,  1766,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1766,  1870,     0,   222,  1624,   209,
       0,   247,  1486,     0,   231,   230,   341,   488,     0,     0,
     588,   345,   350,   387,   356,  1743,  1766,     0,     0,  1766,
    1743,  1784,  1766,  1727,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1869,   248,
    1487,     0,   236,   340,   341,   491,     0,     0,    26,  1766,
    1731,     0,     0,     0,  1766,  1727,     0,     0,     0,     0,
       0,  1766,   334,  1728,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   651,     0,   474,   411,  1811,
    1811,  1811,  1811,  1811,  1833,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1807,   446,     0,   422,   408,   423,   424,     0,
       0,  1814,   426,   427,   425,  1773,   429,   430,   428,  1766,
    1768,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1732,     0,   384,     0,   357,   312,   332,  1861,  1862,
    1492,   321,  1490,  1854,  1853,   314,  1782,  1741,  1755,     0,
    1766,   318,   317,  1766,   337,     0,  1857,  1858,   234,   492,
     496,   589,     0,    27,   695,   485,   486,  1812,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1834,     0,
    1808,   471,   457,   403,  1557,   483,  1815,  1774,  1775,   472,
       0,     0,   405,   407,  1651,  1651,   386,     0,  1791,  1586,
       0,     0,  1582,  1587,  1585,  1583,  1588,  1584,   385,   358,
    1578,  1580,     0,   302,  1491,  1783,   323,     0,   305,  1756,
    1816,   331,     0,     0,   235,   495,   591,   653,     0,     0,
     473,     0,  1826,     0,  1555,  1556,     0,   410,   475,   477,
     479,     0,   404,  1739,   451,   452,  1579,  1792,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1741,
    1817,   310,   319,   316,   320,   315,     0,   497,     0,   595,
     590,   592,     0,   656,   654,   672,     0,   749,   821,   830,
     836,   843,   875,   879,   893,   888,   894,   895,   903,   949,
     958,   961,   987,   998,  1001,  1004,   996,  1010,  1017,  1039,
    1043,  1079,  1081,  1085,     0,  1091,  1105,  1129,  1147,  1148,
    1151,  1152,  1157,  1165,  1166,  1179,  1213,  1231,     0,  1264,
    1276,  1284,  1286,   677,  1290,  1293,  1299,  1350,   697,   698,
     699,   700,   701,   702,   703,   704,   706,   705,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   696,   458,
    1827,   459,  1604,  1599,  1610,     0,  1461,  1463,     0,     0,
       0,  1602,     0,  1465,  1603,  1605,  1606,     0,     0,     0,
       0,  1601,  1610,  1600,  1445,  1443,  1450,  1453,  1455,  1458,
    1522,  1460,  1519,  1553,  1520,  1521,  1607,     0,     0,     0,
    1554,   484,   481,   478,     0,   406,  1652,   361,   374,  1581,
       0,     0,   324,   325,   326,   327,     0,   306,  1754,   312,
       0,  1475,   498,     0,   596,     0,   593,   661,   661,     0,
       0,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1703,  1704,  1705,  1706,  1707,
    1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,
    1718,  1719,  1720,  1721,  1722,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1653,  1699,  1700,  1701,
    1702,   748,     0,     0,     0,     0,   846,     0,     0,     0,
       0,     0,     0,     0,  1406,   989,     0,     0,  1828,   866,
     865,     0,  1009,  1406,     0,     0,     0,     0,     0,     0,
     747,     0,  1117,     0,     0,     0,     0,     0,     0,     0,
       0,  1260,  1263,  1251,  1261,  1262,  1253,     0,     0,  1285,
    1283,     0,   695,     0,     0,     0,     0,  1793,   462,     0,
    1597,  1523,  1524,  1525,     0,     0,     0,     0,     0,     0,
       0,  1457,     0,  1456,     0,  1598,  1446,  1447,  1565,     0,
       0,     0,     0,     0,     0,     0,     0,  1589,     0,     0,
       0,     0,   476,     0,   480,   330,   329,  1733,  1741,   311,
       0,   598,   599,   594,  1738,   661,   658,   664,     0,   661,
     673,   648,   771,   819,   774,   770,  1791,     0,     0,  1513,
     828,  1507,   826,  1502,  1504,  1505,  1506,   831,     0,  1625,
    1485,   837,   838,     0,  1481,  1483,  1482,   849,   847,   848,
     873,     0,  1535,   876,   877,  1534,   880,   883,  1791,   891,
       0,  1467,  1639,  1499,  1558,  1562,  1500,     0,   901,  1805,
    1582,   947,  1371,   912,   916,  1502,     0,  1504,   956,     0,
     850,   959,   968,   967,   985,     0,   964,   966,  1405,     0,
     991,   995,   993,   996,   994,   988,   999,  1000,  1497,  1002,
    1003,  1829,  1005,  1479,   997,  1824,  1404,  1018,  1020,  1040,
    1041,  1044,     0,  1046,  1047,  1048,  1080,  1217,  1550,  1551,
       0,  1082,     0,  1089,     0,  1098,  1095,  1097,  1096,  1092,
    1099,  1119,  1485,  1106,  1117,  1108,     0,  1115,     0,  1536,
    1482,  1538,     0,  1145,  1631,  1149,  1353,  1470,  1155,  1805,
    1163,  1353,     0,  1177,  1170,  1471,     0,  1478,  1180,  1181,
    1182,  1183,  1184,  1185,  1206,  1186,  1209,     0,  1476,     0,
       0,  1549,  1562,  1214,  1249,  1236,  1254,  1737,  1274,     0,
    1267,  1269,     0,  1281,     0,  1287,  1288,   683,   689,   678,
     679,   680,   682,     0,  1291,     0,  1294,  1296,  1316,  1302,
    1363,  1353,  1794,     0,   466,   461,  1612,  1445,  1443,  1462,
    1464,  1445,     0,     0,     0,  1445,  1516,  1517,  1518,     0,
    1466,  1459,  1445,     0,  1444,  1566,     0,  1449,  1448,  1452,
    1451,  1454,     0,     0,  1445,     0,  1766,  1734,     0,   308,
       0,  1766,  1813,   659,  1766,     0,   670,   662,   663,   674,
     820,   750,  1734,   784,   775,     0,     0,     0,     0,  1508,
    1509,  1510,   829,   822,     0,     0,  1503,  1627,  1626,   834,
     839,   841,     0,   874,   844,  1537,   850,   878,   883,  1863,
    1864,   881,     0,   884,     0,   892,   889,  1846,  1845,  1468,
       0,  1641,  1469,  1560,  1561,   898,   899,   902,   896,  1398,
     948,   904,   692,     0,   910,  1373,     0,   927,     0,   921,
    1371,  1371,  1371,  1371,   957,   950,     0,     0,   851,   960,
     986,   962,  1406,  1406,   963,   970,   971,   692,  1430,  1431,
    1432,  1426,  1828,  1418,  1438,  1441,  1440,  1442,  1434,  1425,
    1424,  1429,  1428,  1427,  1433,  1413,  1417,  1435,  1437,  1439,
    1415,  1416,  1412,  1414,  1407,  1408,  1419,  1420,  1421,  1422,
    1423,  1411,   992,   990,  1498,  1007,  1825,   692,  1022,     0,
    1042,     0,  1069,  1053,  1045,  1050,  1051,  1052,  1221,     0,
    1552,     0,     0,  1090,  1086,     0,  1099,  1837,     0,  1107,
    1113,  1114,   692,  1110,  1406,     0,     0,  1118,     0,  1146,
    1130,  1632,  1633,  1805,     0,  1150,  1156,  1153,  1132,  1164,
    1158,  1160,  1172,  1178,  1167,     0,  1172,     0,  1530,  1531,
    1207,  1210,     0,     0,  1477,  1190,     0,  1189,     0,     0,
    1560,  1250,  1232,  1238,  1766,  1239,  1234,     0,  1252,     0,
       0,  1275,  1265,     0,  1268,     0,  1282,  1277,     0,  1289,
     690,   688,   681,     0,  1297,  1298,  1295,  1317,  1300,  1737,
       0,  1364,  1351,  1355,   460,  1737,   456,   464,   465,  1771,
    1611,     0,  1607,  1607,  1607,     0,  1593,     0,  1607,  1567,
       0,  1607,  1607,  1836,     0,   328,  1793,   307,   502,  1766,
    1766,  1727,  1779,   527,   501,   505,   506,     0,  1749,   613,
    1766,   603,  1833,   604,  1842,  1841,     0,  1766,     0,   616,
     607,   612,  1786,   608,     0,   611,   618,   615,   609,   614,
       0,   619,   610,     0,   630,   624,   628,   627,   625,   629,
     600,   631,   626,     0,  1786,     0,  1766,   671,     0,     0,
     649,   780,   785,   786,  1786,  1786,   778,   779,  1786,   766,
    1366,  1844,  1843,   763,   755,   757,   758,     0,  1366,     0,
       0,     0,   772,   761,     0,   769,   752,   768,   753,  1527,
    1526,     0,  1512,     0,  1791,  1376,   827,  1562,  1500,     0,
    1629,   834,     0,   832,     0,     0,  1484,   861,   882,   887,
       0,     0,  1501,  1376,  1766,  1640,  1559,   900,   692,   897,
    1400,  1372,   693,   914,  1733,   692,  1370,   920,   919,   918,
     917,   928,  1371,  1766,   931,     0,   934,   935,     0,  1766,
     938,   939,   940,   941,     0,   942,  1371,   929,     0,   786,
     907,   908,   905,   906,     0,  1376,     0,   857,   965,   980,
     982,   981,   975,   977,   983,  1406,   972,   969,  1406,   973,
    1436,  1409,  1410,  1793,  1006,  1480,   692,  1014,  1015,  1828,
    1030,  1031,  1033,  1035,  1036,  1032,  1034,  1025,  1828,  1021,
       0,  1070,     0,  1072,  1071,  1073,  1055,  1065,     0,     0,
    1049,  1223,     0,  1757,     0,  1083,  1376,     0,     0,     0,
    1101,  1111,  1124,  1120,  1125,  1121,  1126,     0,  1116,  1360,
    1359,  1123,  1132,  1354,  1546,  1547,  1548,     0,     0,  1398,
       0,   692,     0,  1171,     0,     0,     0,  1208,     0,  1212,
    1211,  1204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1192,  1193,  1634,  1398,     0,  1255,  1820,  1820,  1270,
    1271,  1272,     0,  1376,     0,     0,   691,     0,  1621,     0,
    1272,  1160,  1723,     0,  1766,  1619,  1594,  1595,  1596,  1617,
    1614,  1615,  1592,  1608,     0,  1590,  1591,   482,     0,     0,
    1888,  1889,  1766,  1727,     0,   499,   503,  1750,   507,     0,
       0,   601,   602,   605,   606,     0,   633,  1787,  1766,  1826,
    1766,   634,   632,   646,  1766,   665,   666,   669,     0,   660,
     675,   677,  1766,   788,     0,     0,   776,   777,     0,   692,
     767,  1368,   754,   756,  1366,   764,   759,   760,   773,   762,
    1529,  1511,  1528,  1639,     0,   692,   823,  1378,  1560,  1561,
    1376,     0,  1628,   833,   835,   842,   840,   869,  1764,   886,
     885,   890,     0,  1399,   692,  1397,   695,  1374,   909,     0,
     932,   933,   936,   937,     0,  1402,  1402,   930,   911,   923,
     924,   922,   925,     0,   951,     0,   852,   853,   664,     0,
    1406,  1406,   979,   692,   976,     0,  1013,   692,  1016,  1011,
       0,     0,  1037,     0,     0,     0,  1066,  1068,     0,  1061,
    1075,  1062,  1063,  1054,  1057,  1075,  1215,  1766,  1771,     0,
    1758,  1222,  1084,  1087,     0,  1101,  1100,  1104,  1093,     0,
    1112,  1109,     0,     0,  1134,  1133,   692,  1154,  1386,  1159,
    1161,     0,  1173,  1406,  1406,  1168,  1174,  1191,  1203,  1205,
    1195,  1196,  1197,  1201,  1198,  1202,  1199,  1200,  1194,  1635,
    1248,     0,  1245,  1246,  1240,     0,  1233,  1868,  1867,     0,
    1821,  1258,  1258,  1381,     0,  1639,  1278,     0,   684,     0,
    1622,  1303,  1304,     0,  1307,  1310,  1314,  1308,  1398,  1724,
       0,   470,   467,   468,     0,  1609,   309,   504,  1780,  1781,
    1570,   515,   512,   352,   528,   508,   509,  1541,   623,  1539,
    1540,   622,   639,   645,     0,   642,   667,   668,   677,   695,
       0,     0,  1366,   781,   783,   782,  1367,   692,  1365,   765,
    1376,  1501,  1377,   692,  1375,  1559,   824,  1630,  1532,  1533,
    1849,  1850,   871,   692,  1791,  1765,   868,   867,   863,     0,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1642,  1401,
       0,   944,   943,   946,     0,  1544,  1545,   945,     0,   915,
    1376,  1467,  1376,  1467,   854,   855,     0,   859,   858,   860,
     978,   984,   974,  1008,  1012,  1023,  1026,  1027,  1745,  1019,
    1828,  1024,  1075,  1075,     0,  1060,  1058,  1059,  1064,  1225,
       0,  1219,  1759,  1376,  1094,  1103,     0,  1127,     0,     0,
    1141,     0,  1390,   692,  1385,  1162,   692,   692,  1175,  1247,
    1237,  1241,  1242,  1243,  1244,  1235,  1256,  1259,  1257,   692,
    1266,  1383,  1766,  1376,  1376,   686,  1292,  1621,  1306,  1755,
    1312,  1755,  1381,   692,   692,  1352,  1362,  1393,  1394,  1361,
    1358,  1357,  1776,   469,   463,   511,  1855,  1856,   514,   354,
     529,   510,   637,   635,   638,   636,   640,   641,     0,   617,
     643,   644,     0,   695,   787,   792,  1766,   793,   794,   795,
     818,  1766,   796,   797,   798,   799,   800,     0,   801,   802,
     804,   805,   806,     0,   807,  1725,   808,   817,   811,   789,
     790,   810,   751,  1369,   825,  1379,   692,   845,   870,     0,
     862,  1865,  1866,  1403,   926,   953,     0,   952,     0,   856,
    1028,  1746,     0,     0,  1056,  1067,  1075,  1762,  1762,  1076,
       0,     0,  1228,  1224,  1218,  1088,  1102,     0,  1135,  1766,
    1398,     0,     0,  1136,     0,  1140,  1391,  1169,  1176,  1382,
     692,  1380,     0,  1280,  1279,  1318,   685,     0,  1305,     0,
    1755,  1309,     0,  1301,  1395,  1396,  1392,  1777,  1778,  1356,
       0,  1766,  1766,     0,   516,   517,   518,   519,   520,   521,
       0,   531,   620,   621,     0,     0,     0,   809,  1766,  1402,
    1402,  1726,     0,   791,   872,   864,  1376,  1376,     0,  1038,
    1074,  1763,     0,     0,  1766,  1226,     0,     0,  1216,  1220,
       0,     0,  1131,  1144,  1388,  1389,  1143,  1139,  1137,  1138,
    1384,  1273,  1326,   687,  1311,     0,  1315,  1875,  1874,  1766,
       0,     0,  1877,     0,  1766,  1766,   513,  1813,     0,   813,
     812,     0,   815,   814,   816,  1542,  1543,   955,   954,  1029,
    1078,  1077,     0,  1229,  1766,  1406,  1142,  1387,  1349,  1348,
    1327,  1319,  1320,  1725,  1321,  1322,  1323,  1324,  1347,     0,
       0,  1313,     0,   526,   522,  1876,     0,     0,  1760,  1788,
    1727,     0,     0,     0,  1766,  1791,   530,  1766,  1766,     0,
     536,   538,   547,   539,   541,   544,   532,   533,   534,   543,
     545,   548,   535,     0,   540,     0,   542,   546,   537,  1788,
    1727,   676,   803,  1227,     0,  1128,     0,  1818,     0,  1793,
     523,   525,   524,  1761,   586,  1789,  1790,  1768,   572,  1766,
     457,  1406,     0,     0,     0,     0,     0,   580,     0,   570,
     576,   579,     0,   573,   581,   584,  1768,   575,  1230,     0,
    1819,     0,  1345,  1344,  1343,     0,   571,     0,  1826,   568,
    1639,   564,  1514,  1879,     0,     0,  1881,  1883,     0,  1887,
    1885,   549,   553,   557,   557,   551,   555,   550,   556,   587,
       0,   578,   577,   583,   582,   574,  1346,  1848,  1847,  1801,
    1339,  1333,  1334,  1336,   562,   459,   585,  1793,   563,  1515,
    1878,  1882,  1880,  1886,  1884,   560,   552,   560,   554,     0,
    1802,  1793,  1342,  1337,  1340,     0,  1335,   454,     0,     0,
     559,   558,     0,     0,  1341,  1338,     0,   453,   567,   565,
     566,   561,   569,  1332,  1329,  1331,  1330,  1325,  1328,   455
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
     792,   664,   665,   666,   667,   668,   669,   670,  2552,  2687,
     671,   782,  1148,  1384,  1385,  1649,  1646,  2152,  2153,   672,
     673,   674,   675,   676,   992,   788,   789,  1182,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1190,  1421,
    1674,  1675,  1958,  2165,  1676,  2161,  2315,  2434,  2435,  2436,
    2437,  2438,  2439,  1955,  2164,  2441,  2497,  2556,  2557,  2631,
    2666,  2680,  2558,  2559,  2658,  2689,  2560,  2561,  2562,  2563,
    2564,  2565,  2599,  2600,  2603,  2604,  2566,  2567,  2568,   588,
     776,   840,   841,   842,  1192,  1422,  1710,  2326,  2327,  2328,
    2332,  1711,  1712,   713,  1429,  1981,   714,   845,  1018,  1017,
    1195,  1196,  1197,  1426,  1718,  1020,  1720,  2178,  1142,  1369,
    1370,  2295,  2416,  1371,  1372,  1925,  1781,  1782,  2026,  1373,
     779,   898,   899,  1092,  1203,  1204,  1746,  1433,  1489,  1726,
    1727,  1723,  1983,  2182,  2359,  2360,  2361,  1431,   900,  1093,
    1210,  1445,  1443,   901,  1094,  1217,  1763,   902,  1095,  1221,
    1222,  1765,   903,  1096,  1230,  1231,  1499,  1817,  2046,  2047,
    2048,  2017,  1111,  2208,  2202,  2367,  1454,   904,  1097,  1233,
     905,  1098,  1236,  1461,   906,  1099,  1239,  1466,   907,   908,
     909,  1100,  1248,  1475,  1478,   910,  1101,  1251,  1252,  1483,
    1253,  1487,  1809,  2041,  2229,  1792,  1806,  1807,  1481,   911,
    1102,  1258,  1495,   912,  1103,  1261,   913,  1104,  1264,  1265,
    1266,  1504,  1505,  1506,  1827,  1507,  1822,  1823,  2052,  1501,
     914,  1105,  1275,  1112,   915,  1106,  1276,   916,  1107,  1279,
     917,  1108,  1282,  1834,   918,   919,  1113,  1838,  2059,   920,
    1114,  1287,  1548,  1847,  2062,  2246,  2247,  2248,  2249,   921,
    1115,  1289,   922,  1116,  1291,  1292,  1554,  1555,  1859,  1556,
    1557,  2073,  2074,  1856,  1857,  1858,  2067,  2255,  2389,   923,
    1117,   924,  1118,  1301,   925,  1119,  1303,  1564,   926,  1121,
    1309,  1310,  1568,  2088,   927,  1122,  1313,  1572,  2091,  1573,
    1314,  1315,  1316,  1873,  1875,  1876,   928,  1123,  1323,  1888,
    2270,  2400,  2472,  1580,   929,   930,  1124,  1325,   931,   932,
    1125,  1328,  1587,   933,  1126,  1330,  1889,  1590,   934,   935,
    1127,  1333,  1596,  1892,  2105,  2106,  1594,   936,  1128,  1338,
     159,  1608,  1339,  1340,  1911,  1912,  1341,  1342,  1343,  1344,
    1345,  1346,   937,  1129,  1296,  2259,  1558,  2394,  1861,  2076,
    2392,  2468,   938,  1130,  1354,  1914,  1616,  2121,  2122,  2123,
    1612,   939,  1356,  1618,  2286,  1136,   940,  1137,  1358,  1359,
    1360,  2133,  1622,   941,  1138,  1363,  1627,   942,  1140,   943,
    1141,  1365,   944,  1143,  1374,   945,  1144,  1376,  1636,   946,
    1145,  1378,  1640,  2141,  2142,  1930,  2144,  2300,  2421,  2302,
    1638,  2417,  2482,  2521,  2522,  2523,  2697,  2524,  2651,  2652,
    2675,  2525,  2614,  2526,  2527,  2528,   947,  1146,  1380,  1585,
    1931,  1881,  2305,  1642,  1990,  1991,  2188,  1484,  1485,  1786,
    2006,  2007,  2194,  2290,  2291,  2411,  2097,  2473,  2098,  2274,
    2306,  2307,  2308,  1779,  1780,  2025,  2223,  1285,  1286,  1268,
    1269,  1534,  1535,  1536,  1537,  1538,  1539,  1540,   974,  1169,
    1388,   976,   977,   978,   979,  1211,  1240,  1469,  1326,  1334,
     395,   396,  1012,  1347,  1348,  1545,  1317,  1224,  1225,   541,
     481,   301,   691,   692,   482,    98,   153,  1277,  1242,  1212,
    1446,  2621,  1395,   981,  1751,  2001,  2075,  2197,  1234,  1318,
    2168,  2504,  2224,  1883,  2169,  1297,  1351,  1214,   983,  1243,
    1244,   734,   784,   785,  2170,   271,  2601,   179,  1215,   760,
     761,  1216,   986,   987,   988,  1177,  1150,  1403,  1399,  1392,
     501,  2143,   537,  1449,  1761,  2012,  1583,  2125,   282,  1472,
    1775,  2218,   794,  1091,  2150,  2452,   604,   339,   684,  1435,
     423,  1198,   202,   115,   393,  2382,   337,  1959,   352,  1010,
     770,  2081,  2584,  2462,  2209,    96,   214,   414,   739,  2429,
    1954,   766,   402,  1968,  2587,   798,  1383,   218,   488,  2671,
     168,   390,   731,   102,   719,   680,   831,  2611,  2131,   350,
    1547,   951,  1283,   407,   729,  1183,  1322,   391,  1728,  1748,
    1470,  2649,  2203,   184,   695,  2318,   708,   347,   596,  1463,
    2373,  2129,   538,   203,  2489,  2495,  2634,  2635,  2636,  2637,
    2638,  1678
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2254
static const yytype_int16 yypact[] =
{
   -2254,   274,   -24, -2254,  -174,   290, -2254,   -24, -2254, -2254,
     127, -2254, -2254,   127,   127,   610,   610, -2254,   682, -2254,
     800,   571,  1016, -2254, -2254,  1080,  1080,   612,   809, -2254,
   -2254,    55,   127,   610, -2254, -2254,   989,   802, -2254, -2254,
     835,  1410,   610, -2254, -2254, -2254,   571,   867, -2254, -2254,
    -105, -2254,   820,   820,   916,   942,  1118,  1118,  1118,   977,
     820,   970,   932,   937,  1118,   945,   962,  1352, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254,   931, -2254, -2254, -2254, -2254,
    1208, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1258,   983,    55, -2254, -2254,   987,   549, -2254, -2254,  1118,
    1118, -2254,  1118,   963,  1408,   963,  1043,  1118,  1118, -2254,
   -2254,   963, -2254, -2254, -2254,  1005,  1173,  1083, -2254, -2254,
    1010, -2254,  1100, -2254, -2254, -2254, -2254,  -156, -2254, -2254,
   -2254,  1157, -2254,  1118,   913,   963,  1282,   -17, -2254, -2254,
   -2254, -2254, -2254,  1305,  1096,   431,  1368, -2254,  1067, -2254,
    1005, -2254,    70, -2254, -2254, -2254, -2254, -2254,  1130,   477,
    1118,    95, -2254, -2254, -2254,   463, -2254, -2254, -2254,  1045,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254,   913, -2254,  1134,
   -2254,  -171, -2254, -2254,   963, -2254,  1177, -2254,  1187,  1188,
    1538,  1118, -2254, -2254, -2254,   730, -2254, -2254, -2254, -2254,
   -2254,   796,  1548,  1118,    65, -2254,   106, -2254, -2254,     6,
   -2254, -2254, -2254, -2254,  1355,   477, -2254,  1376,   820,   820,
   -2254,  1130,  1164,    97,   -80, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1309, -2254,
     183, -2254,   913, -2254, -2254,  1290, -2254, -2254, -2254,  1118,
    1222,  1378, -2254, -2254, -2254, -2254,  1078,  1118,  1145,  1409,
     -44, -2254,  1624,   505,  1202, -2254, -2254,  1203,  1550, -2254,
    1355, -2254,   820, -2254, -2254, -2254, -2254,  1130, -2254,  1212,
    1357, -2254,   820, -2254,   812, -2254,   131, -2254, -2254, -2254,
   -2254, -2254,  1309, -2254,  1416,  1378, -2254, -2254, -2254,   692,
   -2254, -2254, -2254,  1423, -2254, -2254, -2254, -2254, -2254,  1412,
   -2254, -2254, -2254, -2254, -2254,  1231, -2254, -2254, -2254,  1663,
    1592,  1244, -2254, -2254,  1309, -2254, -2254,   115, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1259, -2254,  1509,
    1579,  1249, -2254,  1688, -2254, -2254, -2254, -2254,  2163, -2254,
    1620, -2254,  1206,  1262,  1321, -2254,  1309,  1444,  1366,   551,
    1318, -2254,  1319,  1118,  1667,   102,   -71,     7, -2254,  1221,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1306,
   -2254,  1466, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1693,  1118, -2254,  1206, -2254,  1206, -2254, -2254,  1284,   -37,
   -2254, -2254,  1118, -2254,  1500, -2254, -2254,   971, -2254, -2254,
     839,  1118,  1118, -2254,  1118,  1118, -2254,  1663, -2254,   438,
    1118,  1444, -2254,  1337,  1243,  1206, -2254,  1417, -2254, -2254,
   -2254, -2254,  1251, -2254,  1254,    85,    43,  1118, -2254, -2254,
     703, -2254, -2254,   -92,  1340,   963,   963, -2254,  1449,  1449,
    1450, -2254,   963,  1118, -2254, -2254, -2254,  1378, -2254,  1372,
    1507, -2254, -2254,  1322, -2254, -2254, -2254, -2254, -2254,   963,
   -2254, -2254,    34,    34,  1762,    34, -2254, -2254,    34,   419,
   -2254, -2254, -2254, -2254, -2254,  -161, -2254, -2254, -2254, -2254,
   -2254, -2254,   578, -2254,  1323,  1382,  1517,   398,  1324,  6445,
   -2254,  1274, -2254, -2254,    -4, -2254, -2254, -2254, -2254,  1231,
   -2254, -2254, -2254, -2254, -2254,  1118,   963,  1279, -2254,  1279,
   -2254, -2254,  1332,  1390,  1421, -2254,  1341, -2254,  1344, -2254,
    1703, -2254,  1706, -2254,  1175, -2254,  1672, -2254, -2254, -2254,
     963,   963, -2254,   566, -2254, -2254,  1254, -2254,  1346,  1404,
    1413, -2254, -2254, -2254,   837,  1620,  1118,  1166,  1166,  1118,
      33,  1444,  1118,  1777, -2254,  1495, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254,   820,   915, -2254,   963,
   -2254,  1494, -2254, -2254,  1254, -2254,  1353,  1411, -2254,  6753,
     768,  1602,  1378,  1303,  1118,  1777,  1307,   469,   -92,  1378,
    1310,  1118, -2254, -2254, -2254,   185,   820, -2254, -2254, -2254,
     698, -2254,  1254, -2254,  1359,   129,    12, -2254, -2254,   400,
     403,   418,   429,   676,  1311, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,  1424, -2254,  1378, -2254, -2254, -2254, -2254,   963,
     963,  1583, -2254, -2254, -2254,   -61, -2254, -2254, -2254,  1118,
     189, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,   980,
     439, -2254,  1312, -2254,   912, -2254,  1371, -2254, -2254, -2254,
   -2254,  1307, -2254, -2254, -2254, -2254,  1568,    57,  1605,  1320,
    1118, -2254, -2254,  1118, -2254,  1219, -2254, -2254, -2254, -2254,
   -2254, -2254,  1704, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1326,
   -2254, -2254,  1387, -2254,  1375,  1396, -2254, -2254, -2254, -2254,
    6920,   217,  1802, -2254,  1434,  1434, -2254,   938,  1533, -2254,
    1035,  1035, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1393, -2254,  1378,   112, -2254, -2254, -2254,  1378, -2254, -2254,
    1431, -2254,   430,   430, -2254,  1496,  1342,    45,  2696,  3761,
   -2254,  1378,  1402,  7435,  1391, -2254,   963, -2254,   217, -2254,
    1406,  1596, -2254,  1667, -2254, -2254, -2254, -2254,  1035,  1403,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,   938, -2254, -2254, -2254, -2254,    46,  1352,
   -2254,   582, -2254, -2254, -2254, -2254,  1351, -2254,  6263, -2254,
   -2254,  1342,  1407, -2254, -2254,  1483,  4145, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254,   -32, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,  1461, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,   592, -2254,
   -2254,  1525, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254,  1752, -2254, -2254,  1414,  2879,   -17,   -17,  1415,  1418,
    1422, -2254,  1425,   -17, -2254, -2254, -2254,  2228,  7435,  2228,
    1429, -2254,  1414, -2254,   246,  1026,   810, -2254,  1698, -2254,
   -2254, -2254, -2254, -2254,  1393, -2254,  1430,  1432,  1433,  7435,
   -2254, -2254,   384, -2254,   217, -2254, -2254, -2254, -2254, -2254,
     -92,   -92, -2254, -2254, -2254, -2254,  1681, -2254, -2254,  1371,
    1378, -2254, -2254,  1419, -2254,  1427, -2254,    60,    60,  1365,
    1435, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,  -143,  4682,  7435,   462,   611,   481,  1206,   570,
    -212,  5607,  5656,  1616,  -181,   904,   570,   963,  1428, -2254,
   -2254,  5656, -2254, -2254,   570,  1351,  1361,   963,  4766,  5656,
   -2254,   939,  2502,  1206,   963,  1206,   963,    90,   473,   963,
    1206, -2254, -2254, -2254, -2254, -2254, -2254,  4952,  4988, -2254,
   -2254,  1351,    93,   963,  1206,   963,   963,  1564, -2254,  7058,
   -2254, -2254,  1393, -2254,  1379,  1389,  7435,  7435,  7435,  2879,
    1394, -2254,   953, -2254,  2879, -2254, -2254, -2254, -2254,  7435,
    7180,  7435,  7435,  7435,  7435,  7435,  7435, -2254,  2879,  7435,
    1026,  1472, -2254,  1443, -2254, -2254, -2254,  1867,  1352, -2254,
     750, -2254, -2254, -2254, -2254,   163, -2254,   420,   335,   195,
   -2254, -2254, -2254,  1769,   801,  1705,  1533,   963,  2879, -2254,
    1771, -2254,  5041, -2254, -2254, -2254, -2254, -2254,   173,   717,
   -2254,   462, -2254,  1454, -2254,   -17, -2254, -2254, -2254, -2254,
    1772,  2779, -2254,   481, -2254, -2254,  1206,  1076,  1533,  1770,
     303, -2254,  1520, -2254, -2254,  1375,  1393,  1206,  1774,  1366,
     968,  1776,  5254, -2254,  5307,   140,  1071,  1144,  1773,   239,
    1420, -2254, -2254, -2254,  1775,    94, -2254, -2254, -2254,  4644,
   -2254, -2254,  1812,   -32, -2254, -2254, -2254,   570, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254,  1474, -2254, -2254,   256,  1351,
   -2254, -2254,   286, -2254, -2254, -2254, -2254, -2254, -2254,  1457,
    5656, -2254,  1470,  1780,  1872, -2254, -2254, -2254, -2254,   939,
    1518, -2254,  1479, -2254,  3054,   -19,   807,  1485,  1480, -2254,
    -175, -2254,  1489,  1786,   859, -2254,  1734, -2254,  1790,  1366,
    1798,  1734,   963,  1800,  1448, -2254,  1325, -2254, -2254, -2254,
   -2254, -2254, -2254,  1677, -2254,   570, -2254,   446, -2254,   455,
    1918, -2254,    72, -2254,  1803,   993,   680,  1902,  1804,  4059,
   -2254, -2254,   963,  1806,  5385,  1351, -2254, -2254,  -155, -2254,
   -2254, -2254, -2254,  3568, -2254,  1760, -2254,  1241,  1808,  1847,
    1809,  1734, -2254,   963,  1741,   197, -2254,   252,   342, -2254,
   -2254,   240,  1514,  1515,  1516,   275, -2254,  1393, -2254,  1519,
   -2254, -2254,   309,  1521,   342, -2254,  1057,   810,   810, -2254,
   -2254, -2254,  1037,  1522,   337,  1526,  1118, -2254,   -92,  1851,
    1523,    47,  6970, -2254,  1118,  1556,  1656, -2254, -2254,  1864,
   -2254, -2254,  1325,  1778, -2254,   814,  1578,   123,  1530, -2254,
    1393, -2254, -2254, -2254,  5917,  1784, -2254,  1754, -2254,  1604,
   -2254,  1639,  1727, -2254, -2254, -2254,  1420, -2254,  1076, -2254,
   -2254, -2254,   925,    26,   963, -2254, -2254, -2254, -2254, -2254,
    7435,  1717, -2254,  1391, -2254,  1206, -2254, -2254, -2254,  1759,
   -2254, -2254, -2254,  5656, -2254,  1697,   352,  1694,  2067,  1510,
    1828,  1828,  1828,  1828, -2254, -2254,  5656,  5917, -2254, -2254,
   -2254, -2254,  -181,   226, -2254,  1501, -2254,  1502, -2254, -2254,
   -2254, -2254,  1428, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,  4377, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254,    -2, -2254,  1869,  1388,  1820,
   -2254,  1325,    96, -2254, -2254,  1636, -2254, -2254,   121,  7435,
   -2254,  1558,   570, -2254, -2254,  5917,  1518,  1221,  1206, -2254,
   -2254, -2254, -2254, -2254,  1837,   963,   462, -2254,   244, -2254,
   -2254, -2254, -2254,  1366,  1361, -2254, -2254, -2254,  1779, -2254,
   -2254,  -104,  1877, -2254, -2254,   963,  1877,  1562, -2254,  1393,
   -2254, -2254,   542,  1130, -2254, -2254,  2763, -2254,  1960,   666,
     108, -2254, -2254, -2254,  1118, -2254,   458,  5656, -2254,   601,
    5578, -2254, -2254,   963, -2254,  1814, -2254, -2254,  5917, -2254,
    1378, -2254, -2254,  1325, -2254, -2254, -2254, -2254, -2254,  1902,
    1783, -2254, -2254,   244, -2254,  1902, -2254, -2254, -2254,  1500,
   -2254,   963,  1430,  1430,  1430,  2879, -2254,   502,  1430, -2254,
    7331,  1430,  1430, -2254,   217, -2254,  1564, -2254, -2254,  1118,
    1118,  1777,  1046, -2254, -2254, -2254, -2254,  1810,  1836, -2254,
    1118, -2254,   480, -2254, -2254, -2254,  1386,  1118,  2779, -2254,
   -2254, -2254,  1718, -2254,  1378, -2254,  1963, -2254, -2254, -2254,
     963, -2254, -2254,   963, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,  1819,  1718,   724,  1118, -2254,  1512,  1573,
   -2254, -2254, -2254,  1753,  1718,  1718,   143,  1781,  1718, -2254,
    1863, -2254, -2254, -2254,  1527,  1524, -2254,  1325,  1863,  1792,
    1607,  1736, -2254, -2254,  1763, -2254, -2254, -2254, -2254, -2254,
   -2254,   486, -2254,   963,  1533,   435, -2254,   -58,   -36,   570,
    1594,  1604,   570, -2254,  1599,   462, -2254,   -32, -2254, -2254,
    1658,  1680, -2254,   744,  1118, -2254, -2254, -2254, -2254, -2254,
    1751, -2254, -2254, -2254,  2019, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,  1828,  1118, -2254,   -64, -2254, -2254,  1441,  1118,
   -2254, -2254, -2254, -2254,     3, -2254,  1653, -2254,  1405,  1753,
   -2254, -2254, -2254, -2254,  1849,   435,  1850,    68, -2254, -2254,
   -2254, -2254,  2033, -2254,  1612,   181, -2254, -2254,   226, -2254,
   -2254, -2254, -2254,  1564, -2254, -2254, -2254,  1929,  1919,  1428,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1696,  1428, -2254,
    1613, -2254,  2013, -2254, -2254, -2254,   766, -2254,  1325,  1056,
   -2254,    58,   197,   -10,   570,   570,   435,  1860,  1206,   438,
     886,  1924, -2254, -2254, -2254,  2059, -2254,  1873, -2254, -2254,
   -2254, -2254,  1779, -2254, -2254, -2254, -2254,   963,  1939,  1759,
     948, -2254,  1571, -2254,  1580,  1325,   880, -2254,   486, -2254,
   -2254, -2254,  5656,  1130,  1130,  1130,  1130,  1130,  1130,  1130,
    1130,   666, -2254,    28,  1759,   517, -2254,  1660,  1660, -2254,
   -2254,   417,   963,   435,  1881,  1635, -2254,  1641,  2079,   963,
    -176,  -104,  2082,  1597,  1118, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,  1065, -2254, -2254, -2254,   963,   481,
   -2254, -2254,  1118,  1777,  1842,  1342, -2254, -2254, -2254,   963,
     125, -2254, -2254, -2254, -2254,   125, -2254, -2254,  1118,  1402,
    1118, -2254, -2254, -2254,  1118, -2254, -2254, -2254,   158, -2254,
   -2254, -2254,  1118,  1600,   125,   125, -2254, -2254,   125, -2254,
   -2254,  1813, -2254, -2254,  1863, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,  1520,   123, -2254, -2254,  1811,   -47,  1903,
     435,   701, -2254, -2254, -2254, -2254, -2254,    14,   128, -2254,
   -2254, -2254,   816, -2254, -2254, -2254, -2254, -2254, -2254,   125,
   -2254, -2254, -2254, -2254,   125,   509,   509, -2254, -2254, -2254,
   -2254, -2254,  1606,   570, -2254,   570,  1232, -2254,  -124,    38,
     226, -2254, -2254, -2254,  2033,   963, -2254, -2254, -2254, -2254,
    1617,  1150,    50,  1619,   701,  1325, -2254, -2254,  2061, -2254,
   -2254, -2254, -2254,  1056, -2254,  1923, -2254,  1118,  1500,  1805,
   -2254, -2254,   570, -2254,   570,   886, -2254, -2254, -2254,   974,
   -2254, -2254,   963,  5656,  1087, -2254, -2254, -2254,  1823, -2254,
   -2254,  1856, -2254, -2254, -2254, -2254,  1580, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,    -8,
   -2254,   963, -2254, -2254, -2254,   900, -2254, -2254, -2254,  7435,
   -2254,  5656,  5656,  1659,  1794,  1520, -2254,   570, -2254,   701,
   -2254,  1818, -2254,  1325, -2254,  2009,  1699, -2254,   616, -2254,
     739, -2254,  1597, -2254,   963, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,  1381,   -35, -2254,   963, -2254, -2254, -2254, -2254,
   -2254, -2254,   513, -2254,   481,   513, -2254, -2254, -2254,   177,
    2085,  1950,  1863, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1722,  1931, -2254, -2254, -2254,  1933, -2254, -2254, -2254, -2254,
   -2254, -2254,  1844, -2254,  1533, -2254, -2254, -2254, -2254,   963,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    3316, -2254, -2254, -2254,  1385, -2254, -2254, -2254,  2067, -2254,
     435,  1782,   435,  1785, -2254, -2254,  5656, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254,  1150, -2254,  2038, -2254,
    1428, -2254, -2254, -2254,   701,   247, -2254, -2254,   247,   -15,
     963, -2254, -2254,   435, -2254, -2254,  1761, -2254,  2093,  1882,
    1910,   -11, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254,   342, -2254, -2254, -2254, -2254,
   -2254,  1853,  1118,  1722,   435,  1661, -2254,  2079, -2254,  1605,
    2055,  1605,  1659, -2254, -2254, -2254, -2254,  1859, -2254, -2254,
   -2254, -2254,  1392, -2254,   963,  1253, -2254, -2254,  1842, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,   125, -2254,
   -2254, -2254,   125,   245, -2254, -2254,  1118, -2254, -2254, -2254,
   -2254,  1118, -2254, -2254, -2254, -2254, -2254,    18, -2254, -2254,
    2099, -2254, -2254,    10, -2254,  2148, -2254, -2254, -2254,  1950,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,   963,
   -2254, -2254, -2254, -2254,  2067, -2254,   570, -2254,   570, -2254,
   -2254, -2254,  2114,  2054,   247,   247, -2254,  1710,  1710, -2254,
    1831,  1206,   600, -2254,   963, -2254, -2254,  5656, -2254,  1118,
     781,  1907,  1908, -2254,  1909, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,   963, -2254, -2254, -2254, -2254,  1721, -2254,   963,
    1605, -2254,   963, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1304,  1118,  1118,  1330, -2254, -2254, -2254, -2254, -2254, -2254,
    1603, -2254, -2254, -2254,  2064,   125,   125, -2254,  1118,   509,
     509, -2254,   541, -2254, -2254, -2254,  1722,  1722,  5656, -2254,
     247, -2254,  5656,  5656,  1118,  1206,  1206,  1838, -2254, -2254,
    1695,   963, -2254, -2254,  1823, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,  1147, -2254, -2254,   963, -2254, -2254, -2254,  1118,
    1842,  1842, -2254,  1964,  1118,  1118, -2254,  1295,  1726, -2254,
   -2254,   481, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254,   462,  1206,  1118, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,  1121, -2254, -2254, -2254, -2254, -2254,  1839,
    2071, -2254,  1842, -2254, -2254, -2254,  1842,  1842,  1962,  1158,
    1777,  1972,  1378,  1683,  1118,  1533, -2254,  1118,  1118,   963,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,   772, -2254,   -22, -2254, -2254, -2254,  1158,
    1777, -2254, -2254, -2254,   462, -2254,  1827,  1767,    -5,  1564,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254,   189, -2254,  1118,
    1387, -2254,  7473,  7473,  1186,  2077,  1990, -2254,  1378,   772,
   -2254, -2254,  1378,   -22, -2254, -2254,   189, -2254, -2254,   963,
   -2254,  1191, -2254, -2254, -2254,    75, -2254,   772,  1402, -2254,
    1520,  7451, -2254, -2254,   763,  1021, -2254, -2254,  1063, -2254,
   -2254, -2254, -2254,   -27,   -27, -2254, -2254, -2254, -2254, -2254,
    7473, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1861,
     958,    75, -2254, -2254, -2254,  1752, -2254,  1564, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254,  1884, -2254,  1884, -2254,  2150,
   -2254,  1564, -2254, -2254,  1906,   963, -2254,  1789,   -26,  1887,
   -2254, -2254,  7473,   629, -2254, -2254,  1378, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  1206, -2254
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2254, -2254, -2254, -2254, -2254,  2210, -2254, -2254, -2254,   206,
   -2254,  2172, -2254,  2127, -2254, -2254,  1277, -2254, -2254, -2254,
    1193, -2254, -2254,  1294,  2194, -2254, -2254,  2094, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  2021,
      74, -2254, -2254, -2254, -2254, -2254,  2075, -2254, -2254, -2254,
   -2254,  2018, -2254, -2254, -2254, -2254, -2254, -2254,  2153, -2254,
   -2254, -2254, -2254,  2010, -2254, -2254, -2254, -2254,  1992, -2254,
   -2254,   899, -2254, -2254, -2254, -2254,  2083, -2254, -2254, -2254,
   -2254,  2057, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,   972, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,  1713, -2254,  1826, -2254, -2254, -2254,
    1791, -2254, -2254, -2254, -2254,   371, -2254, -2254,  1955, -2254,
   -2254, -2254, -2254, -2254,  1817, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1234, -2254, -2254, -2254,  1471, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,   200,
   -2254, -2254,  1748, -2254,  -756,  -826, -2254, -2254, -2254,   264,
   -2254, -2254, -2254, -2254,  -535, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -1392,   824,  1508,   501,   626, -1383, -2254, -2254,
   -2254,  -343,  -406, -2254, -2254,   388, -2254, -2254,    99, -1382,
   -2254, -1377, -2254, -1376, -2254, -2254,  1464, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    -381,  -413, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -1251, -2254,  -348, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,  1426, -2254, -2254, -2254,    83,    84, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
    1246,   213, -2254,   214, -2254, -2254, -2254, -2254, -1768, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -1329, -2254, -2254,  -696,
   -2254,  1482, -2254, -2254, -2254, -2254, -2254, -2254,  1061,   539,
     543, -2254,   461, -2254, -2254,   -87,   -73, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254,   515, -2254, -2254, -2254,
    1058, -2254, -2254, -2254, -2254, -2254,   821, -2254, -2254,   234,
   -2254, -2254, -1250, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254,   823, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
     799, -2254, -2254, -2254, -2254, -2254,    56, -1737, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
     783, -2254, -2254,   782, -2254, -2254,   460,   236, -2254, -2254,
   -2254, -2254, -2254,  1017, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254,    48,   741, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,   737,
   -2254, -2254,   220, -2254,   440, -2254, -2254, -1902, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254,   988,   732,   215, -2254, -2254, -2254, -2254, -2254, -2254,
   -1587,   985, -2254, -2254, -2254,   209, -2254, -2254, -2254,   421,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254,   373, -2254, -2254, -2254,
   -2254, -2254, -2254,   706,   199, -2254, -2254, -2254, -2254, -2254,
    -154, -2254, -2254, -2254, -2254,   402, -2254, -2254, -2254,   966,
   -2254,   969, -2254, -2254,  1182, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,   184, -2254, -2254, -2254, -2254, -2254,
     956,   387, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254,    21, -2254,   390, -2254, -2254, -2254,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  -329,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254,  -425,
   -2254,   681, -2254, -2254, -1641, -2254, -2254,  -702, -2254, -2254,
   -1677, -2254, -2254,    23, -2254, -2254, -2254, -2254,   -77, -2179,
   -2254, -2254,    19, -1813, -2254, -2254, -1926, -1524, -1042, -1431,
   -2254, -2254,   795, -1697,   205,   208,   210,   211,   -49,   191,
    -730,   374,   296, -2254,   711,  -517, -1379, -1044,    63,   999,
   -1530,  -392,  -365, -2254, -1293, -2254, -1039, -1523,   882,  -530,
     -98,  2039, -2254,  1646,  -546,    42,  2187, -1046, -1048,  -853,
   -1077, -2254, -1087, -1314, -2254,   442, -1273, -1889, -1086, -1142,
   -1066, -2254, -2254, -2254, -1107, -2254,   176,   921,  -635, -2254,
   -2254,  -103, -1157,  -737,   -99,  2074, -1722,  2106,  -658,  1031,
    -520,  -566, -2254, -2254, -2254,   -48,  1380, -2254, -2254,   426,
   -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -2254, -1936,
   -2254, -2254,  1609, -2254, -2254,  -168,  -586,  1940, -2254, -1165,
   -2254, -1282,  -218,  -607,   712, -2254,  1852, -2254, -1414, -2254,
   -1529, -2254, -2254,   -30, -2254,   -29,  -649,  -360, -2254, -2254,
   -2254, -2254,   332,  -192,  -213, -1187, -1522,  2144,  1911, -2254,
   -2254,  -335, -2254, -2254,  1054, -2254, -2254, -2254,   444, -2254,
     301, -1905, -1455, -2254, -2254, -2254,  -150,   503, -1374, -1644,
   -2254, -2254, -2254,  -699, -2254, -2254,  1664, -2254,  1807, -2254,
   -2254, -2254,   808, -2254, -2253,  -226, -2254, -2254, -2254, -2254,
   -2254, -2254
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1838
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   215,   138,   415,   141,   139,   689,
     579,   741,  1014,   147,   733,  1256,  1213,   160,   778,  1437,
     838,  1350,  1418,   404,  1255,  1259,   759,   103,   104,   105,
    1704,   245,   139,   427,  1284,   111,  1862,   180,  1870,  1706,
    1707,  1302,  1304,   464,   437,  1708,  1709,   990,  1714,  1771,
    1874,  1464,   696,   975,  1604,  1241,  1223,  1830,  1278,   268,
    1361,  1213,  1267,  1597,  2173,  1755,  1278,  2190,  1288,  2037,
     134,   135,  1824,   136,   259,  1620,  2099,  1402,   143,   144,
    1278,   246,  1349,   790,  2650,   838,   463,   161,  1473,  1456,
     768,  1413,   211,  -652,  1000,    99,  2021,  1995,   279,  1332,
     843,  2126,   107, -1551,   169,  1851,  1617,   264,  1669,  1194,
    2227,  1502,  1833, -1837,   114,   821,   821,  1194,  1815,   392,
     535,   360,  1570,   215,  2612,  2237,  2035,    94,  2340,  -647,
     790,   219,   321,  2449,  2204,   430,  1670,  1671,  2044, -1552,
     529, -1806,  1560,  1747,  1948, -1557,   411,  1457, -1793,  2665,
    2688,  1512,   297,  1852, -1837, -1737, -1555, -1837, -1837,  1721,
   -1824, -1771,   251,   821,   480,  1202,   413, -1578,   465,   825,
    1432,  1109,   345,  2258,   258,  2252,     4,  -650,  1829,  2200,
    2494,   737,  1223, -1837,  2235,   -96,  1866,  1512,  2030,  2083,
    2176,   220,  1541,  1790,   283,  1610,   327,    42,   129,  2293,
     291,   182,  1819,   221, -1733,  2401, -1733,  1684,  2079,  1685,
    2390,   211,  1194,  2179,   351,   412,  2124,   985,  1837,   419,
     295,  2475,  1007,  1561,  1647,  2402,   747,   796,   299,  1544,
    1447,  -652,  2162, -1837,  2160,  -652, -1793,    43,  1162,  1630,
    1544,   839,  1247,  1871,  1194,   535,  2136,  1819,  1254,  1923,
    2296,  2403,  1879,   515,  1220,  2387,   715,  1154,  1155,  1180,
     274,   275,  1238,   154,  1160,    94,   980,  -647,   418,   253,
   -1557,  -647,  1262,  1853,     3,  1749,  2404,    15,  1850,    94,
      18,  1880,  1361,  1263,  2388,  1364,  1424,   783,  1496,   183,
     505,   516,   394,  -652,   416,  2517,  1631,  1278,    43,  1602,
     130,  1544,   212,   999,  2080,   204,   839,  2602,   284,  1238,
    1166,  2055,  1648,   716,   311,  -650,  1166,     5,  2119,  -650,
    1151,  2120,  1166,   738,   314,  2031,   -96,   243,   137,  -647,
     253,  1220,   243,  2196,   410,  2309,  1184,  1854,  2085,   413,
     139,  2632,   139,   139,  1110,  1166,   -35,   485,   486,   139,
    2384,  2385,  1425,  2189,   491,   431,  2205,  1928,   493,   700,
    1927,   137,   424,  1933,  1218,  2386,   139,  1756,  1672,   507,
     507,   485,   507,   436,  2444,   507,   514,  -650,  1551,  1166,
    2010,   154,   443,   444,  2060,   445,   446,   280, -1751,  1153,
     466,   452, -1733,  2063,  1824,  2238,     5,  1824,   701,   243,
    1241,   985,   985,   985,   783,   283,  1784,  1166,   469,   281,
    2333,   823,   137,   139,   154,   989,  2613, -1737,   542,  1814,
    1816,   212,  2279,   985,   492, -1737,  1391,  1391,  1391,   749,
    1382, -1837,  1571, -1771,  -652,   260,  2206,   139,   139,  1404,
    1406,  1238,   542,   580,  1527,   467,  1412,   448,  1787,  2023,
     980,   980,   980,  1241,  1185,  1186,  2027,  1541,  1294,   368,
    1267,  1238,  1467,  1750,  1994,   826,   712,  1497,   749,  2319,
    -647, -1733,   980,   752,  1725,  2201,   139,   137,   137,  1238,
    1527,   580,  2391,   753,  2460,  2036,   540,   187,  1867,  2405,
   -1739,  1546,  2450,   686,   188,   139, -1824,  2053,  1673,   536,
     697,  2357,   137,   767, -1806,   577,  1835,  2056,  1474,   243,
     255,  1001,   752,  2364,  1278,   749,  1865,  2018,  -650,   284,
   -1737,  1241,   753,  2502,  2503,   591,  1452,   593,   985,  1901,
     598,   600, -1766,   602,   783,  2049,  2239,  1878,   137,  -657,
    1916,  2362,   844,  1920,  1367,   732,  1966,   735,  1238,   243,
    1295,  1924, -1737,  2375,  1544,  2377,  1321,   265, -1737,   752,
     679,   261,  2102,   754,  1855,   688, -1737,  2004,  1939,   753,
     989,  -655,   699,  1439,   149,   996,  1238,   980,  1605,   137,
    2277,  1419,   322,   985,  1241,  2068,  2395,  2476,  2207,   394,
     985,   985,   985,  1398,   137,  1503,  2440,  1368,  1398,    97,
    2008, -1636,   754,   985,   985,   985,   985,   985,   985,   985,
     985,   517,  1398,   985,  -657,  1474,  2413,  2414,   607,  1824,
     346,   127,  2107,  1337,   536,   292,  1336,   137,  1367,   137,
     740,  1171,   980,   755,  1820,  2167,  1172,  2037,  1167,   980,
     980,   980,  1441,  1488,  1167,  1821,  -655,   749,   704,   754,
    1167,  1552,   980,   980,   980,   980,   980,   980,   980,   980,
    2186, -1737,   980,   824,  2230,  1321,  2232,   749,   829,   834,
     834,   772,   755,  1167,   773,   512,  2192,   756,  1006,  1820,
     744,  1368,   949,   991,  2656,   749,   832,  1788, -1618,   702,
    1821,   752,  1427, -1737,  1168,  2219,  1367,   222,  1171,   189,
    1650,   753, -1837,  1172,  1903,  2263,  1237,  1167,  1249,   216,
     747,   752,  1904,  2655,  2014,  1241,   756,  1337,  1220,   755,
     128,   753,  1553, -1616,  2242,   449,  2016,   757,  2244,   752,
    2506,  1324,  1961,  1329,   305,  1167,  1776,  1232,  1355,   753,
    1773,    16,  2000,  1940,  1337,   518,   583, -1837,  1321,  1368,
    1290,  1420,  1377,   453,   749,  1468,  1975, -1613,  2294,   243,
     137,  2127,  1917,   756,  2049,   154,   757,  2272,  2533,  2534,
    2419,   190,  2422,  2303, -1519,  1851,  1366,   693,  1008,  2507,
    2508,   754,   749,  2322,   611,  1662,   187,   450,  1810,  1811,
    1812,  1813,  2253,   188,   681,  2383,  2496,  2160,   752,  2693,
    1171,   754,  1752,  2466,    27,  1172,   717,   137,   753,   717,
    2580,  -500,   709,   757,  2581,  2582,  1278,  1544,  2082,   754,
     470,   471,   472,  1852,   717,  2109,   752,   191,   581,  1772,
    1424,  1432,   192,  1428,  1976,   717,   753, -1835, -1753,  -500,
    -500, -1837,  2323,  2605,  1458,   519,  2005,  1778,  1131,   525,
    2210,   755,   187,  2570,  2694,  1476,  1789,  2311,  2363,   188,
     223,  2465,  2695,  2157,  2365, -1733,    23, -1733, -1837,  1962,
    2298,   755,  1665,  1776,  2368,   306,   718,  1905,  1684,   720,
    1685,  2605,  1227,  1109,    28,  1181, -1519,   694,   754,   755,
    1918,  2485,  1603,   601,   722,   756,  1425,   139,   139,  2171,
     217,  1606, -1620,   129,   985,   724,  1591,   745,  2304,  1906,
    2096,  1189,     5,   749,  1479,   756,   754,  2467,  2183,  2184,
     243,   747,  2185,   137,  1550,  2573,  1885,  2128,  2225,  2225,
    1944,  1907,   117,   756,   137,   193,  2513,  1607,  1132,   137,
    1448,   473,    52,  1853,  2406,   757,  2696,  2407,  2408,   328,
    2660,   582,    24,   980,  -500,   474,  1643,   752,   755,   137,
    2409,   243,   748,  2221,   682,   757,   137,   753,  2222, -1837,
    1941,  2324,   705,  2535,  2424,  2425,  2325,   137, -1069,  1133,
     154,   728,  -500,   757,  1908,   137,   755,  2608,  1896,    53,
     137,  2575,  1226,   985,  1588,   154,  1245,   405,   189,  2231,
    1629,  2233,   756,  1245,  1280,   130,  1947,  1854,  1134,  2241,
    1337,  1245,  1778,   137,  1299,   822,  2268,  2369,  1886,  1320,
    2009,  1327, -1069,  1327,  1335,  1352,  1299,    54,  2160,    55,
     756,    56, -1069,  1228,  1544,  1229,   799,  2454,   475,    57,
    1241, -1766,   980,  1327,  1909,   137,   137,   754,   406,   706,
     476,   707,   757, -1733,  2287,  2287,  1110,  2615,  2597,   361,
    2310,  2276,   997,    39,   189,  2069,  1724,  2619,  2530,    94,
     190,  -500,  2273,   226,   137,   800,   801,   802,   803,   804,
     757,  2480,   717,  1777,  2312,  1951,   608,  1462,  2329,  1398,
    2028,   362,  2653,  1241,   985,    58,   438,  2211,  2212,  2213,
    1387,  2598,  1135,  1270,  2038,  2550,    36,  1514,  1515,  1305,
     626,   627, -1069,  2070,  2551,  2553,  2002,   755,  1226,   609,
    2554,  2555,  1321,  2569,   749,   170,   191,   329,  2653,  2451,
    1414,   192, -1733,   394,   187,  2678,   190,  1245,  1549,  1910,
     477,   188,   439,   980,  1581,  1725,  1516,  1517, -1837,  2683,
     749,   742,   726,  2698,    33,  2005,   750,   751,  2576,  2379,
    2214,   756,  1840,   316,  1306,  1841,  1842, -1519,   752,   171,
    1613,   227,  1307, -1837,  1245, -1519, -1519,  1417,   753,   172,
   -1519,   252, -1069,   243,   743,  1245,   330,  1769,    60,  1331,
     403,   325,   191,  1582,   752,    13,   300,   192,   441,  2163,
      13,  -500,  1171,    40,   753,   137,  1619,  1172,  2661,  1381,
    2100,   757,  1770,   805,   806,   807,   808,   809,   810,   811,
     639,   640,   555,   344,   317,   318, -1069,  1271,  1272,  1335,
    1614,  2662,    61,  1615,  1855,  2101,  2265,   556,  -857,  2623,
    2492,  -857,  1245,   137,  1273,    48,  1245,   254,  1882,  2167,
    2663,   819,   819,    49, -1751,   400,  1308,   228,   754,   173,
    1173,  2266,  2442,  2002,  2672,  2087,  2443,   592,   749,  1174,
   -1069,  2195,   599,  2664,  2518,  2624, -1069,   557,  2620,  2622,
     139,  1194,  2215,  2216,   754,  1644,    51,  2217,  1574,  1934,
      21,    22,  2487,  1298,  1952,  1953,  2673,  2071,  1274,   819,
     255,   229,  2488, -1837,  2269,  1298,  1575,  2659,  1462,    46,
      26,   230,   752,  2519,  -857,   139,  2674,  2529,    93, -1737,
    2470,    64,   753, -1837,    97,   231,  2669,    47,   755,   174,
    2220,  -857,  2456,  1899,  2457,   351,    91,  2320, -1837,   100,
     624,  1757,  2225,  2225,  1900,  2505,   189,   101,  2642, -1837,
      94,  2520,  2647,  2199,   755,  1528,  2648,  1529,  2593,  1684,
    1731,  1685,  1732, -1837,    67,   812,  2654,  2159,  2692,  2191,
     747,   106,   756,   175, -1837,   108,   820,   820,   813,  2499,
    2500,  2509,   118,   109,  2492,  2510,  2511,  1664,   110,   243,
     394,   232,  1677,  1713,  1757,  1715,   112,  1839,   756,  2285,
    1840,  1401,   754,  1841,  1842,    94,  2199,    94,  1423,   114,
    2487,  1171,  1423,   113,   558,  2572,  1172,  1869,   190,  2493,
    2488,    52,   757,   176,   820,   559,   120,  1843,  1844,   154,
    2430,   122,  1459,  -857,   124,    68,  2487,   155,   126,   156,
    2431,  1890,  1226,   952,  -857,   508,  2488,   510,   757,  1897,
     511,  1845,  1846, -1535, -1535, -1535, -1535,  2585,  2586,  1245,
     953,   233,  1757,  2432,   234,   235,  1915,   137,    53,  1409,
    1410,  1411,   755,  1226,   191,  1170,   140,  -857,   428,   192,
     155,  2199,   156,  -857,  1171,  -857,  1660, -1733,  -857,  1172,
    -857,  -857,  -857,  2433,   142,  1171,  -857,   167,  -857,  1245,
    1172,  2039,  2040,  -857,  2538,  1659,    54,  2625,    55,   149,
      56,  2626,  2627,  2155,   163,  1171,   756,   594,    57,   595,
    1172,   228,  1974,  1171,  2072,  1757,   560,   561,  1172,   298,
     642,  1926,  1984,  1985,   162,  -857,  1988,   749,   181,   137,
    -857,   562,  1963,   563,  1964,  1407,  1408,  2539,   139,  2540,
    1460,   164,  2628,  1935,  -857,   236,  1490,  1491,  1492,  1493,
     137,   185,   954,   985,   186,   229,   757,   204,  2629,  2630,
     706,   193,   707,   749,    58,   230,   242,   247,  -857,   243,
    2541,   752,  1651,  1393,  1394,  1913,  1655, -1837,   248, -1737,
     243,   753,  1634,  1657,  1635,  1969,  2199,  2032,   249,  2033,
    2542,   250,  1729,  1730,  1936,  1937,  1938,   257,   273,  -857,
    1942,   269,   980,  1945,  1946,   278,  1977,   752,   294,   958,
     959,   960,   646,   296,  2314,   961,   564,   753,  2543, -1534,
   -1534, -1534, -1534,  2316,   154,  2317,    59,  2371,   302,  2372,
    1949,  1950,  -857,  1731,  2427,  1732,  2428,  1733,  -857,   300,
     303,  1960,  1245,   307,   308,   232,  1245,   309,  1965,  1245,
    -857,  -857,  1226,   312,   962,  1843,  1844,    60,  1731,   313,
    1732,   754,   326,   565,   721,   723,   725,   727,  1161,   333,
    1163,  1734,  1735,  1736,   334,   336,   338,  1978,  1793,  1845,
    1846,  1794,  -857,   428,   340,   342,   349,   351,  1795,  1796,
     651,   353,  -857,   354,   982,   356,   392,   754,  -857,  2544,
     394,    61,  1245,   397,    62,   398,   401,   403,  2261,   408,
    2089,   409,  -857,   187,   243,   233,  2545,  -857,   421,   420,
   -1737,  1737,   422,  1738,  -857,   429,  -857,   413,   964,   454,
    1739,   755,  -857,  1740,  1797,  2022,  2546,   455,   457,  2110,
    2111,  2112,  2113,  2114,  2115,  2116,  2117,   459,  -342,   483,
     490,  1245,  1245,  1245,  2029,   487,   494,  2547,   495,   509,
    2034,  2134,   523,   502,   521,   527,   522,   755,   533,    63,
    2134,  1890,   543,   547,   548,   756,  2548,   549,  -355,   965,
     966,   554,   551,   660,  2549,   552,   578,   585,   586,   603,
      64,   605,   587,   610,   613,   614,   685,   687,   730,   698,
     711,   690,   728,  1798,   984,   736,   746,   762,  1482,   236,
    1245,   756,   765,   769,   771,    65,   777,    66,   791,   137,
    1741,   970,  1742,   781,   793,   757,   780,   783,   786,   797,
     823,   830,  1799,    67,   836,   139, -1620,   950,   994,  1337,
    2156,   971,   995,   989,   998,  1011,   972,  1299,  1016,  1019,
    1120,  1139,  1299,   973,  1800,   137,  1147,  1175,  1187,  1200,
    1191,   757,  1260,  1382,  1281,  1415,  1149,  1156,  1193,  2177,
    1157,  1299,  1299,  1389,  1158,  1299,  1201,  1159,   982,   982,
     982,  1164,  1176,  1390,  1178,  1179,  1416,  1417,  1400,  1430,
    1451,  1436,  1442,  1465,  1453,  2154,  1471,  1245,  1477,  1494,
     982,  1480,  1500,  1542,    68,  1546,  1562,  1498,  1801,  1559,
    1563,  1565,  1567,  2158, -1537,  1577,  1299,  1576,  1578,  1579,
    1584,  1299,  1299,  1299,  1586,  2089,  2226,  2226,  2616,  2172,
    1245,  2174,  1245,  1589,  2271,  2175,  1593,  1595,  1337,  1609,
    1611,  1194,  1621,  2180,  2588,  1626,  1633,  2645,  1637,  1639,
    1641,  1645,  1652,  1653,  1654,  1666,  1716,  1656,  1717,  1658,
    1661,  1802,  1663,  1719,  1668,  1722,  1753,  1760,  1764,  1245,
    1762,  1245,  2335,  1220,  2607,  2336,  1152,  1759,  2337,  1774,
    1778,  1785,  1791,  1482,  1808,  1849,  2338,  1836,   984,   984,
     984,  1552,  1825,  1828,  1864,  1872,  1891,  1887,  1895,  1902,
    1922,  1929,  1957,  1205,  1956,  1219,  1979,  1967,  1235,  1970,
     984,  1743,  1257,  1973,  1980,  1982,   985,   985,  1989,  1996,
    1997,  1803,  1993,  1724,  1245,  1998,  1992,  1293,  2019,  1999,
    2011,  2339,  2020,  1319,  1804,  2015,  2024,  1299,  2260,  1432,
    2050,   139,  2043,  2045,  2051,   985,   542,  2057,  2058,  2064,
    2340,  2061,  2065,  2084,  1375,  2090,  1379,  2092,  2096,  2093,
     982,  1744,  2103,   428,   985,   980,   980,   982,   982,   982,
    1396,  2104,  1745,  2130,  2137,  1396,  2138,  2139,  2140,  2149,
     982,   982,   982,   982,   982,   982,   982,   982,  2160,  1396,
     982,  2151,  1793,  2181,   980,  1794, -1556,  2187,  2193,  2228,
    2254,  2257,  1795,  1796,  2273,  2245,   985,  2251,  2275,  2262,
    2289,   428,  2299,   980,  2292,   984,  1805,  1245,  1438,  1245,
    1246,  2297,  2334,  2005, -1512,  2301, -1554,  1246,  2366,  2341,
    2381,  2396,  2397,  2376,  2398,  1246,  2378,  2399,  2342,  2410,
    2420,  2304,  1319,  2415,  1235,  2448,  2451,   139,  1797,  1246,
    1245,  2343,  2393,  2458,  2459,   980,  2461,   357,  2464,  2477,
    2478,  2479,  2483,  2498,  2535,  2514,  2515,  2571,  2579,  2578,
     984,  2589,   358,  2583,  2591,  2610,  2640,   984,   984,   984,
    1397,  1245,   359,  2344,  2609,  1397,  2639,  2679,  2670,  2682,
     984,   984,   984,   984,   984,   984,   984,   984,  2691,  1397,
     984,   139,  2684,  2345,  2686,  2346,   580,    17,    92,   125,
      38,   166,   256,   209,   266,  1299,   360,  1798,   119,  1299,
     290,   277,   545,   210,   241,  1319,   442,  2347,  2348,  1440,
    2086,   323,   456,  1188,   835,   526,  1705,  2618,   787,  2677,
    2078,  2313,   993,  2668,  2681,  2644,  1799,  1598,  2330,  2331,
     504,   948,  2236,  2412,  1199,  1434,  1987,  1015,  2349,  1986,
    2042,  1246,  2453,  1245,  2447,  1245,  2013,  1767,  1800,  1450,
    2234,  1768,  1783,  1625,  2374,  1818,  2240,  1826,  2054,  1848,
    1543,  2469,  1860,  2256,  2380,  2350,  2066,  1566,  1868,  1569,
    2264,  2267,  1894,  2094,  2148,  2278,   428,  2445,  1246,  1600,
     952,  1353,  2446,  2118,  1601,  1624,  2288,  2146,  2418,  1246,
    2147,  2351,  2676,  2474,  1932,  2423,  2426,   953,  2352,  1832,
    2281,  1592,  1801,  2282,  1766,  2283,  2284,   764,   332,   213,
    2108,  2353,  1299,  1299,   310,  2354,  1299,  1299,   293,  1299,
    2226,  2226,  1165,  1598,   795,  2577,  2606,   447,  2463,   272,
     489,   539,  2132,  2250,  2077,   597,  1863,  1599,  2633,   774,
    2471,     0,     0,     0,     0,     0,  1246,     0,     0,     0,
    1246,     0,     0,   361,     0,  1802,     0,     0,     0,     0,
       0,   982,     0,     0,  2355,     0,     0,     0,     0,     0,
       0,     0,  2490,  2491,     0,     0,     0,     0,     0,  1226,
       0,     0,     0,     0,     0,   362,     0,     0,     0,  2501,
       0,     0,     0,  2356,     0,  -228,     0,     0,     0,   954,
       0,     0,     0,  2357,     0,  2512,     0,     0,     0,  2358,
     749,     0,     0,  2590,     0,  1803,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1804,     0,
    2532,     0,     0,  1599,     0,  2536,  2537,     0,     0,     0,
       0,  1226,  1598,   955,     0,  1758,     0,     0,   363,   956,
     982,   957,     0,   364,   752,  2574,   958,   959,   960,     0,
       0,     0,   961,     0,   753,     0,  1877,     0,     0,  2641,
       0,   984,     0,  2643,     0,  1884,     0,     0,     0,     0,
       0,     0,  1226,     0,   365,  2592,  1893,     0,  2594,  2595,
       0,     0,   366,     0,     0,     0,     0,     0,  1758,     0,
       0,   962,     0,     0,     0,   367,     0,     0,     0,     0,
    1805,     0,     0,     0,  1921,     0,     0,     0,  1226,     0,
     963,     0,     0,     0,  1598,     0,     0,     0,     0,     0,
    2617,     0,     0,     0,   368,     0,     0,   369,     0,     0,
       0,     0,  2685,     0,   754,   370,  1396,     0,     0,     0,
       0,   982,  1599,     0,   952,     0,  -225,  2699,     0,     0,
     984,     0,     0,  1246,     0,     0,  1758,     0,     0,     0,
       0,   953,     0,     0,     0,   964,     0,     0,     0,  1319,
       0,     0,     0,     0,   371,     0,     0,   372,     0,     0,
       0,  1971,     0,     0,  1972,     0,     0,     0,     0,     0,
       0,     0,     0,  1246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,   966,  1598,  1758,
       0,     0,     0,     0,  1599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2003,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1397,     0,   756,     0,
     968,   984,  1311,     0,     0,     0,     0,   846,   970,   847,
       0,   848,     0,   954,     0,     0,   849,     0,     0,     0,
       0,     0,     0,     0,   850,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
       0,     0,     0,     0,     0,     0,     0,   851,   852,     0,
       0,     0,     0,     0,     0,     0,   853,     0,  1312,     0,
     958,   959,   960,     0,     0,     0,   961,   854,  1599,  1206,
     855,     0,   747,     0,     0,     0,     0,     0,     0,  1598,
    1598,     0,     0,     0,   856,     0,  1246,     0,     0,     0,
    1246,     0,     0,  1246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,   857,  2095,     0,
       0,     0,     0,     0,     0,   858,  1598,   859,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2135,     0,   952,  1246,     0,   860,     0,
    2145,  2145,     0,     0,     0,     0,     0,     0,     0,   861,
       0,   952,   953,     0,   862,     0,     0,     0,     0,     0,
    1235,     0,     0,     0,     0,     0,     0,     0,   953,   964,
    2166,     0,     0,     0,     0,     0,     0,     0,     0,  1599,
    1599,   863,     0,     0,     0,  1246,  1246,  1246,   864,     0,
       0,   865,   866,     0,     0,     0,     0,     0,     0,     0,
       0,   867,     0,     0,     0,  1898,     0,     0,   868,     0,
     869,     0,     0,   870,     0,     0,  1599,     0,     0,     0,
     965,   966,  2198,     0,     0,     0,     0,     0,     0,     0,
       0, -1837,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1246,     0,     0,     0,     0,     0,
       0,   952,     0,     0,   954,   871,     0,     0,     0,   872,
       0,   873,   970,     0,     0,   749,  2243,     0,   953,     0,
     954,   874,     0, -1122,     0,  2198,  1598,     0,     0,     0,
       0,     0,   971,     0,  1598,     0,     0,   972,     0,     0,
       0, -1122,     0,     0,   973,   243,   137,   875,  1208,     0,
       0,     0,     0,  1877,   956,     0,   957,     0,     0,   752,
     876,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,     0,     0,     0,  1209,  1455,     0,   958,   959,   960,
       0,  1246,  2280,   961,     0,   877,   878,     0,     0,     0,
     982,     0,     0,     0,     0,     0,   879,     0,     0,     0,
    2198,     0,     0,     0,  1598,     0,   962,     0,     0,     0,
     880,   881,     0,     0,  1246,     0,  1246,   882,     0,     0,
     954,   883,   962,     0,     0,   963,  2321,     0,     0,   884,
       0,   749,     0,     0,     0,  1235,  1599,     0,     0,   885,
       0,     0,     0,     0,  1599,     0,     0,     0,   886,   754,
       0,     0,     0,  1246,     0,  1246,     0,   887,     0,     0,
       0,     0,   888,   889,     0,     0,   890,     0,   891,     0,
    2370,     0,     0,     0,   892,   752,   952,   958,   959,   960,
     964,     0,     0,   961,     0,   753,     0,   893,     0,     0,
       0,     0,     0,   953,     0,     0,   964,     0,     0,     0,
     984,     0,     0,     0,     0,   894,     0,     0,  1246,     0,
       0,   895,     0,     0,  1599,  2198,   896,     0,     0,   755,
       0,     0,   962,     0,     0,     0,     0,     0,     0,     0,
       0,   965,   966,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   897,     0,     0,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,  1899,     0,     0,     0,
       0,     0,     0,   756,     0,   754,     0,  1900,     0,     0,
       0,     0,     0,   970,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1311,     0,     0,     0,     0,   970,
       0,     0,     0,   971,     0,   954,   964,     0,   972,     0,
       0,  1246,     0,  1246,     0,   973,     0,   137,     0,   971,
       0,     0,     0,   757,   972,     0,     0,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,     0,
    2455,     0,     0,     0,  1246,   755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   965,   966,     0,
    1455,     0,   958,   959,   960,     0,     0,   846,   961,   847,
       0,   848,     0,     0,     0,  1246,   849,     0,     0,     0,
       0,     0,     0,  2481,   850,     0,     0,     0,     0,   756,
    2484,     0,     0,  2486,     0,     0,     0,     0,     0,   970,
       0,     0,     0,     0,     0,     0,     0,   962,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   851,   852,   971,
       0,     0,     0,     0,   972,     0,   853,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,   854,     0,   757,
     855,     0,  2516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   856,     0,  2531,  1246,     0,  1246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,     0,   857,     0,     0,
       0,   964,     0,     0,     0,   858,     0,   859,     0,     0,
       0,     0,     0,     0,  -694,     0,  -694,  -694,  -694,  -694,
    -694,  -694,  -694,  -694,     0,  -694,  -694,  -694,     0,  -694,
    -694,  -694,  -694,  -694,  -694,  -694,  -694,  -694,   860,     0,
    2596,     0,     0,     0,     0,     0,     0,     0,     0,   861,
       0,     0,   965,   966,   862,     0,     0,     0,     0,     0,
       0,     0,     0, -1837,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   863,     0,   982,   982,     0,     0,     0,   864,     0,
       0,   865,   866,     0,   970,     0,     0,     0,     0,     0,
    2646,   867,     0,     0,     0, -1122,     0,     0,   868,     0,
     869,     0,   982,   870,   971,     0,     0,     0,     0,   972,
       0,     0,     0, -1122,  2667,  2667,   973,   243,   137,     0,
       0,   982,     0,     0,     0,     0,     0,     0,     0,   846,
       0,   847,     0,   848,     0,     0,     0,     0,   849,     0,
       0,     0,     0,     0,     0,   871,   850,     0,     0,   872,
       0,   873,     0,     0,     0,     0,     0,     0,     0,  2690,
       0,   874,     0,   982,     0,     0,     0,  -694,  -694,     0,
    -694,  -694,  -694,  -694,     0,     0,     0,     0,     0,   851,
     852,     0,     0,   984,   984,     0,     0,   875,   853,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   854,
     876,     0,   855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   984,     0,     0,     0,   856,     0,     0,     0,
       0,     0,     0,     0,     0,   877,   878,     0,     0,     0,
       0,   984,     0,     0,     0,     0,   879,     0,     0,   857,
       0,     0,     0,     0,     0,     0,     0,   858,     0,   859,
     880,   881,     0,     0,     0,     0,     0,   882,     0,     0,
       0,   883,     0,     0,     0,     0,     0,     0,     0,   884,
       0,     0,     0,   984,     0,     0,     0,     0,     0,   885,
     860,     0,     0,     0,     0,     0,     0,     0,   886,     0,
       0,   861,     0,     0,     0,     0,   862,   887,     0,     0,
       0,     0,   888,   889,     0,     0,   890,     0,   891,     0,
       0,     0,     0,     0,   892,     0,     0,     0,     0,     0,
       0,     0,   846,   863,   847,     0,   848,  -694,     0,     0,
     864,   849,     0,   865,   866,     0,     0,     0,     0,   850,
       0,     0,     0,   867,     0,   894,     0,     0,     0,     0,
     868,   895,   869,     0,     0,   870,   896,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   851,   852,     0,     0,     0,  -694,     0,     0,
       0,   853,     0,   897,     0,     0,     0,     0,     0,     0,
       0,     0,   854,     0,     0,   855,     0,   871,     0,     0,
       0,   872,     0,   873,     0,     0,     0,     0,     0,   856,
       0,     0,     0,   874,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   857,     0,     0,     0,     0,     0,     0,   875,
     858,     0,   859,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   876,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   860,     0,     0,     0,   877,   878,     0,
       0,     0,     0,     0,   861,     0,     0,     0,   879,   862,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   880,   881,     0,     0,     0,     0,     0,   882,
       0,     0,     0,   883,     0,     0,   863,     0,     0,     0,
       0,   884,     0,   864,     0,     0,   865,   866,     0,     0,
       0,   885,     0,     0,     0,     0,   867,     0,     0,     0,
     886,     0,     0,   868,     0,   869,     0,     0,   870,   887,
       0,     0,     0,     0,   888,   889,     0,     0,   890,     0,
     891,     0,     0,     0,     0,     0,   892,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     871,     0,     0,     0,   872,     0,   873,   894,     0,     0,
       0,     0,     0,   895,     0,     0,   874,     0,   896,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1206,     0,     0,   747,     0,
       0,     0,   875,     0,     0,   897,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   876,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     877,   878,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   880,   881,     0,     0,     0,
       0,   952,   882,     0,     0,     0,   883,     0,  1021,     0,
    1022,     0,     0,     0,   884,  1023,     0,     0,   953,     0,
       0,     0,     0,  1024,   885,     0,     0,     0,     0,     0,
       0,  1357,     0,   886,     0,     0,     0,     0,     0,     0,
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
    1040,  1041,  1042,     0,  1043,  1044,  1045,  1623,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,     0,     0,
       0,     0,     0,     0,  1208,     0,     0,     0,  1056,     0,
     956,     0,   957,  1057,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,     0,     0,
    1209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1058,     0,     0,     0,     0,     0,     0,  1059,     0,     0,
    1060,  1061,     0,     0,     0,     0,     0,     0,     0,     0,
    1062,     0,   962,     0,     0,     0,     0,  1063,     0,  1064,
       0,     0,  1065,     0,     0,     0,     0,     0,     0,     0,
       0,   963,     0,  1206,     0,     0,   747,     0,     0,  1508,
    1509,  1510,     0,     0,     0,     0,     0,  1511,     0,     0,
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
    1076,     0,     0,     0,     0,     0,  1512,     0,  1077,     0,
       0,     0,     0,     0,     0,     0,  1513,     0,  1078,   971,
       0,     0,     0,     0,   972,     0,     0,  1079,     0,     0,
       0,   973,     0,   137,     0,     0,  1080,     0,     0,   757,
       0,  1081,  1082,     0,     0,  1083,     0,  1084,   954,     0,
       0,     0,     0,  1085,  1514,  1515,     0,     0,     0,   749,
       0,     0,     0,     0,     0,     0,  1086,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1831,
       0,     0,     0,     0,  1087,     0,     0,     0,     0,     0,
    1088,     0,  1208,  1516,  1517,  1089,     0,     0,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1209,     0,
    1206,     0,  1090,   747,     0,     0,  1508,  1509,  1510,     0,
       0,  1518,     0,     0,  1511,     0,     0,  1519,     0,     0,
    1520,     0,     0,     0,     0,     0,     0,     0,  1521,     0,
     962,     0,     0,     0,     0,  1522,     0,     0,  1206,     0,
    1523,   747,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,   952,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   953,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,  1206,     0,     0,   747,  1207,     0,     0,     0,
       0,   953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1512,     0,   965,   966,     0,     0,     0,
       0,     0,     0,  1513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1525,     0,  1526,     0,  1527,
       0,     0,  1528,     0,  1529,  1530,  1531,   756,     0,  1532,
    1533,     0,     0,     0,     0,   954,     0,   970,   952,     0,
       0,  1514,  1515,     0,     0,     0,   749,     0,     0,     0,
    1300,     0,     0,     0,     0,   953,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,   954,     0,     0,     0,   757,     0,  1208,
    1516,  1517,     0,     0,   749,   956,     0,   957,     0,     0,
     752,     0,   958,   959,   960,     0,     0,     0,   961,     0,
     753,     0,     0,     0,     0,  1209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1208,  1518,     0,
       0,     0,     0,   956,  1519,   957,     0,  1520,   752,     0,
     958,   959,   960,     0,     0,  1521,   961,   962,   753,     0,
       0,     0,  1522,  1209,     0,     0,     0,  1523,  1206,     0,
       0,   747,     0,     0,     0,     0,   963,   954,     0,     0,
       0,     0,     0,     0,     0,     0,  1524,     0,   749,     0,
       0,     0,     0,     0,     0,   962,     0,     0,     0,     0,
     754,     0,     0,     0,  1206,     0,     0,   747,     0,     0,
       0,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,  1208,     0,     0,     0,     0,     0,   956,     0,   957,
       0,   964,   752,     0,   958,   959,   960,     0,   754,     0,
     961,     0,   753,     0,   952,     0,     0,  1209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1206,     0,     0,
     747,   953,     0,     0,     0,     0,     0,     0,     0,   964,
     755,     0,     0,     0,  1357,     0,     0,     0,     0,   962,
     952,     0,   965,   966,     0,     0,     0,     0,     0,     0,
       0,     0,  1362,     0,     0,     0,     0,   953,   963,     0,
       0,     0,  1525,     0,  1526,     0,  1527,     0,   755,  1528,
       0,  1529,  1530,  1531,   756,     0,  1532,  1533,     0,     0,
     965,   966,   754,     0,   970,     0,     0,     0,     0,     0,
       0,     0,     0,   952,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   971,     0,     0,     0,     0,   972,
     953,     0,   756,   964,     0,     0,   973,     0,   137,     0,
       0,     0,   970,   954,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,     0,
       0,     0,   971,     0,     0,     0,     0,   972,     0,     0,
       0,     0,   755,     0,   973,     0,   137,     0,     0,   954,
       0,     0,   757,     0,   965,   966,     0,  1208,     0,     0,
     749,     0,     0,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
       0,     0,     0,  1209,     0,     0,   756,     0,     0,     0,
       0,     0,     0,  1208,     0,     0,   970,     0,     0,   956,
       0,   957,   954,     0,   752,     0,   958,   959,   960,     0,
       0,     0,   961,   749,   753,   962,   971,     0,     0,  1209,
    -913,   972,     0,  -913,     0,     0,     0,     0,   973,     0,
     137,     0,     0,     0,   963,     0,   757,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1208,     0,     0,     0,
       0,   962,   956,     0,   957,     0,     0,   752,   754,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
     963,     0,  1209,  1206,     0,     0,   747,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   964,
       0,     0,     0,     0,   754,     0,  -913,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,     0,     0,
       0,     0,     0,  -913,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,   964,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,   754,     0,   952,
       0,  1206,     0,     0,   747,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   755,     0,   953,     0,     0,     0,
       0,     0,   756,     0,     0,     0,   965,   966,   964,  1482,
       0,     0,   970,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   971,     0,     0,     0,     0,   972,   756,     0,
       0,     0,     0,     0,   973,  -913,   137,   755,   970,     0,
       0,     0,   757,     0,     0,     0,  -913,   952,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,   971,     0,
       0,     0,     0,   972,   953,     0,     0,  1444,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,  -913,
       0,   756,     0,     0,     0,  -913,     0,  -913,   954,     0,
    -913,   970,  -913,  -913,  -913,     0,     0,     0,  -913,   749,
    -913,     0,     0,     0,     0,  -913,     0,     0,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,  1208,     0,     0,     0,     0,  -913,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,  -913,     0,  1209,     0,
       0,  1628,     0,     0,  1206,     0,   954,   747,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   749,     0,     0,
    -913,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,     0,     0,  1206,     0,     0,   747,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
    1208,  -913,     0,     0,     0,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,   754,     0,     0,  1209,     0,     0,     0,
     952,     0,  1206,     0,     0,   747,     0,     0,     0,     0,
    -913,     0,     0,     0,     0,     0,     0,   953,     0,     0,
       0,     0,  -913,  -913,   964,     0,     0,     0,   962,   952,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   953,   963,     0,     0,
       0,     0,     0,     0,  -913,     0,     0,     0,     0,     0,
       0,     0,     0,   755,  -913,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,   965,   966,     0,   952,     0,
       0,     0,     0,     0,  -913,     0,     0,     0,     0,  -913,
       0,     0,     0,     0,     0,   953,  -913,     0,  -913,     0,
       0,     0,   964,     0,  -913,     0,     0,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,   954,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     749,  1486,     0,     0,     0,     0,     0,   971,     0,     0,
       0,   755,   972,     0,     0,     0,     0,     0,   954,   973,
       0,   137,     0,   965,   966,     0,     0,   757,     0,   749,
       0,     0,     0,  1208,     0,     0,     0,     0,     0,   956,
       0,   957,     0,     0,   752,     0,   958,   959,   960,     0,
       0,     0,   961,     0,   753,   756,     0,     0,     0,  1209,
       0,     0,  1208,     0,     0,   970,     0,   954,   956,     0,
     957,     0,     0,  1250,     0,   958,   959,   960,   749,     0,
       0,   961,     0,   753,     0,   971,     0,     0,  1209,     0,
     972,   962,     0,     0,     0,     0,     0,   973,     0,   137,
       0,     0,     0,     0,     0,   757,     0,     0,     0,     0,
     963,  1208,     0,     0,     0,     0,     0,   956,     0,   957,
     962,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,  1754,   754,     0,   747,  1209,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,   964,     0,     0,     0,   962,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   963,     0,
       0,     0,     0,     0,   964,     0,     0,     0,  1919,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,   952,
       0,     0,   754,     0,     0,     0,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,   953,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   964,     0,   965,   966,     0,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,   971,     0,
       0,     0,   755,   972,     0,     0,     0,   970,     0,     0,
     973,     0,   137,     0,   965,   966,     0,     0,   757,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,   756,   757,   954,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,   749,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,     0,     0,     0,     0,   973,     0,
     137,     0,  1208,     0,     0,     0,   757,     0,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,  1013,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   964,  -352,     0,     0,  -352,     0,
       0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,  -352,
       0,     0,     0,   755,     0,     0,  -352,     0,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,   970,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,  -352,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,  -352,  -352,  -352,  -352,  -352,   528,     0,  -352,  -352,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,  -352,
       0,  -352,     0,     0,     0,     0,  -352,  -352,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,  -352,  -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,     0,     0,     0,     0,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,  -352,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,  -352,     0,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,  -352,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
     529,     0,     0,  -352,  -352,  -352,  -352,  -352,     0,     0,
    -352,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,  -352,     0,
    -352,  -352,  -352,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,  -352,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,  -352,     0,     0,     0,
    -352,  -352,  -352,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
    -352,  -352,     0,     0,  -352,     0,     0,   530,     0,     0,
       0,     0,  -352,     0,   616,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,   617,
       0,     0,   618,   619,   620,   621,   622,   623,   624,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   625,     0,   626,   627,
     628,   629,   630,   631,   632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,  -352,  -352,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,  -352,  -352,     0,     0,     0,     0,     0,
       0,   634,   635,   636,   637,   638,  -352,     0,   639,   640,
       0,     0,     0,  -352,     0,     0,     0,     0,     0,   530,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   618,
     619,   620,   621,   622,   623,     0,     0,     0,     0,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,   642,     0,
       0,     0,     0,   625, -1813,   626,   627,   628,   629,   630,
     631,   632,  1679,     0,     0,  1680,     0,     0,  1681,   618,
     619,   620,   621,   622,   623,  1682,  1683,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,     0,     0,     0,  1684,     0,  1685,     0,     0,   633,
       0,     0,     0,   625,     0,   626,   627,   628,   629,   630,
     631,   632,     0,     0,     0,     0,     0,     0,   644,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   645,     0,     0,     0,     0,     0,     0,     0,
     646,     0,     0,   647,     0,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,   648,     0,   634,   635,
     636,   637,   638,     0,     0,   639,   640,     0,   649,     0,
       0,     0,     0,     0,     0,     0,   650,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1686,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     952,     0,     0,     0,     0,     0,     0,     0,   634,   635,
     636,   637,   638,     0,     0,   639,   640,   953,   651,  1687,
     652,   653,   654,     0,     0,     0,  1688,     0,  1689,     0,
       0,     0,     0,     0, -1766,     0,     0,     0,     0,     0,
       0,  1690,     0,     0,     0,     0,     0,   655,     0,   641,
       0,     0,     0,     0,     0,     0,     0,   643,     0,     0,
       0,     0,    94,     0,  -349,   642,     0,     0,     0,     0,
       0,     0,     0,  1691,     0,     0,     0,     0,     0,     0,
       0, -1813,  1692,     0,     0,     0,     0,     0,     0,     0,
     656,   657,   658,     0,     0,  1693,     0,     0,     0,   645,
       0,     0,     0,     0,   659,     0,     0,   643,     0,     0,
     647,   660,     0,     0,     0,     0,     0,     0,     0,   954,
       0,     0,   952,   648,     0,     0,     0,     0,     0,     0,
     749,     0,     0,     0,     0,  1694,     0,     0,     0,   953,
       0,     0,     0,     0,     0,     0,     0,     0,  1695,   645,
       0,     0,     0,     0,     0,     0,     0,   646,     0,     0,
     647,     0,     0,   955,     0,     0,     0,     0,     0,   956,
       0,   957,     0,   648,   752,  1696,   958,   959,   960,     0,
       0,     0,   961,     0,   753,     0,     0,   652,   653,   654,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1697,     0,     0,     0,     0,     0,     0,  1698,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   962,     0,     0,     0,  1699,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   651,     0,   652,   653,   654,
     963,   954,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   749,     0,     0,     0,     0,   656,   657,   658,
       0,     0,     0,     0,   754,     0,     0,     0,     0,     0,
       0,     0,     0,   952,     0,     0,  1700,     0,     0,     0,
       0,  -597,     0,     0,     0,   955,  1701,     0,     0,     0,
     953,   956,     0,   957,     0,   964,   752,     0,   958,   959,
     960,     0,     0,  1702,   961,     0,   753,   656,   657,   658,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   659,     0,     0,     0,     0,     0,  1703,   660,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,   962,     0,     0,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   963,     0,     0,     0,  1386,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   967,   952,   756,     0,
     968,   969,     0,     0,     0,     0,   754,     0,   970,     0,
       0,     0,   954,   952,   953,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,     0,     0,   971,     0,
     953,     0,     0,   972,     0,   952,     0,   964,     0,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
       0,     0,   953,     0,     0,     0,   955,     0,     0,     0,
       0,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,   755,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1405,     0,
       0,     0,     0,     0,   962,     0,   954,     0,   967,     0,
     756,     0,   968,   969,     0,     0,     0,   749,     0,     0,
     970,     0,   954,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,     0,     0,     0,     0,
     971,     0,     0,     0,   954,   972,     0,   754,     0,     0,
     955,     0,   973,     0,   137,   749,   956,     0,   957,     0,
     757,   752,     0,   958,   959,   960,   955,     0,     0,   961,
       0,   753,   956,     0,   957,     0,     0,   752,   964,   958,
     959,   960,     0,     0,     0,   961,     0,   753,   955,     0,
       0,     0,     0,     0,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,     0,     0,   961,   962,   753,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,   962,     0,     0,   963,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,     0,   962,     0,     0,  1943,
       0,   754,     0,     0,     0,     0,     0,     0,     0,   967,
       0,   756,     0,   968,   969,   963,     0,   754,     0,     0,
       0,   970,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,   754,
       0,   971,     0,     0,  2657,     0,   972,     0,   964,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,     0,     0,     0,     0,     0,     0,     0,     0,
     964,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   965,   966,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,   967,     0,   756,     0,   968,   969,     0,
       0,   965,   966,     0,     0,   970,     0,     0,     0,     0,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,   756,     0,     0,     0,   973,     0,   137,
       0,   971,     0,   970,     0,   757,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,     0,   971,     0,     0,     0,     0,   972,     0,
       0,     0,     0,     0,     0,   973,     0,   137,     0,     0,
       0,     0,     0,   757
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-2254))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   158,   103,   366,   105,   111,   595,
     540,   660,   838,   111,   649,  1101,  1093,   116,   714,  1206,
     776,  1128,  1187,   358,  1101,  1102,   684,    56,    57,    58,
    1422,   181,   135,   425,  1111,    64,  1558,   135,  1568,  1422,
    1422,  1118,  1119,   435,   404,  1422,  1422,   784,  1422,  1463,
    1574,  1238,   598,   783,  1347,  1099,  1095,  1512,  1106,   209,
    1137,  1138,  1104,  1336,  1969,  1444,  1114,  2003,  1114,  1806,
      99,   100,  1503,   102,     9,  1357,  1889,  1164,   107,   108,
    1128,   184,  1128,   741,     9,   841,     1,   116,  1245,  1231,
     697,  1178,    22,     0,    48,    53,  1773,  1738,     1,     9,
      55,  1914,    60,    31,   133,     9,  1356,     1,    61,    49,
    2036,    17,   114,   107,    57,   750,   751,    49,  1497,    86,
     124,    63,   141,   277,   129,    87,   123,   232,   110,     0,
     788,   160,     1,   123,     6,   172,    89,    90,  1815,    31,
     175,    39,  1299,  1436,  1666,   203,   364,  1233,    27,   176,
     176,   159,   251,    57,   330,    87,   203,   328,   262,  1432,
     110,   232,   191,   798,   256,   308,   237,   203,   125,    57,
      30,   203,    57,  2075,   203,  2064,   200,     0,  1507,   165,
    2433,   242,  1221,   287,   308,   229,  1565,   159,   252,  1866,
      32,    96,  1269,  1486,   274,  1352,   295,   142,   354,  2135,
      17,   218,    21,   161,    64,   216,    66,    64,   218,    66,
     225,    22,    49,  1981,   188,   113,  1913,   783,  1547,   369,
     249,  2400,   829,  1300,    27,   236,     9,   747,   257,  1277,
      57,   138,  1954,   187,   256,   142,   115,    31,   968,   394,
    1288,   776,   454,  1572,    49,   124,  1923,    21,  1101,  1628,
    2139,   262,     8,   414,   256,     8,   244,   956,   957,   989,
     218,   219,     6,   256,   963,   232,   783,   138,   367,   195,
     445,   142,   453,   177,     0,   152,   287,   451,  1551,   232,
     153,    37,  1359,   464,    37,  1138,   410,   462,    49,   306,
     256,   452,   504,   200,   287,  2474,   451,  1345,    92,  1345,
     456,  1349,   232,   823,   314,   199,   841,   329,   388,     6,
      70,  1833,   115,   301,   272,   138,    70,   341,   290,   142,
     955,   293,    70,   384,   282,   389,   370,   503,   504,   200,
     256,   256,   503,  2010,   363,  2148,   994,   241,  1868,   237,
     443,  2594,   445,   446,   376,    70,   451,   445,   446,   452,
    2252,  2253,   476,  1994,   452,   392,   228,  1639,   457,   174,
    1633,   504,   391,  1645,  1094,  2254,   469,  1444,   321,   472,
     473,   469,   475,   402,   129,   478,   479,   200,    92,    70,
    1759,   256,   411,   412,  1839,   414,   415,   290,   362,   955,
     347,   420,   252,  1848,  1825,   357,   341,  1828,   213,   503,
    1444,   967,   968,   969,   462,   274,  1483,    70,   437,   312,
    2178,   447,   504,   516,   256,   462,   421,   357,   516,  1496,
    1497,   232,  2119,   989,   453,   357,  1156,  1157,  1158,   212,
     309,   175,   451,   504,   341,   370,   308,   540,   541,  1169,
    1170,     6,   540,   541,   452,   402,  1176,     9,    96,  1778,
     967,   968,   969,  1497,  1000,  1001,  1785,  1534,  1116,   401,
    1502,     6,   159,   340,  1737,   353,   337,   228,   212,   504,
     341,   331,   989,   256,   331,   461,   579,   504,   504,     6,
     452,   579,   497,   266,  2386,   482,   515,    56,  1565,   500,
      59,   441,   482,   592,    63,   598,   446,   316,   451,   503,
     599,   483,   504,   446,   402,   534,  1545,  1836,  1245,   503,
     504,   465,   256,  2190,  1562,   212,  1562,  1767,   341,   388,
     357,  1565,   266,  2449,  2450,   554,  1225,   556,  1094,  1606,
     559,   560,   499,   562,   462,  1817,   498,  1576,   504,   376,
    1617,  2182,   497,  1620,   451,   644,  1688,   650,     6,   503,
    1116,  1628,   357,  2230,  1602,  2232,  1122,   451,   498,   256,
     589,   496,  1891,   346,   468,   594,   498,  1754,  1655,   266,
     462,   376,   601,  1208,   504,   793,     6,  1094,   123,   504,
    2104,  1188,   451,  1149,  1628,  1858,  2263,  2400,   460,   504,
    1156,  1157,  1158,  1159,   504,   501,  2318,   504,  1164,   504,
    1757,   504,   346,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,    33,  1178,  1179,   451,  1352,  2293,  2294,   576,  2050,
     505,    72,  1895,   271,   503,   442,   153,   504,   451,   504,
     659,   458,  1149,   416,   453,   510,   463,  2374,   398,  1156,
    1157,  1158,  1208,   503,   398,   464,   451,   212,   606,   346,
     398,   365,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1989,   498,  1179,   762,  2043,  1231,  2045,   212,   767,   772,
     773,   700,   416,   398,   703,   256,  2005,   460,   828,   453,
     241,   504,   781,   786,  2620,   212,   256,   335,   448,   504,
     464,   256,   357,   498,   448,  2024,   451,   234,   458,   268,
     448,   266,   244,   463,    38,  2084,  1098,   398,  1100,   232,
       9,   256,    46,  2618,  1762,  1759,   460,   271,   256,   416,
     171,   266,   436,   448,  2053,   287,  1765,   510,  2057,   256,
    2452,  1123,   252,  1125,   229,   398,  1473,   256,  1130,   266,
    1470,   451,   256,   241,   271,   167,   546,   330,  1314,   504,
    1115,     1,  1144,   421,   212,   452,    32,   448,  2137,   503,
     504,   244,   161,   460,  2046,   256,   510,  2096,  2490,  2491,
    2299,   340,  2301,   157,    57,     9,  1141,   308,   196,  2456,
    2457,   346,   212,   270,   584,   448,    56,   349,  1490,  1491,
    1492,  1493,  2065,    63,    26,  2250,  2440,   256,   256,   170,
     458,   346,  1437,   203,   122,   463,   406,   504,   266,   406,
    2532,    61,   612,   510,  2536,  2537,  1864,  1865,  1864,   346,
     117,   118,   119,    57,   406,  1902,   256,   396,   262,  1464,
     410,    30,   401,   498,   110,   406,   266,   453,   256,    89,
      90,   161,   329,  2565,  1236,   267,   411,   231,   256,   451,
      34,   416,    56,  2497,   225,  1247,   504,  2150,  2187,    63,
     397,  2391,   233,  1949,  2193,    64,   256,    66,   410,   389,
    2143,   416,  1418,  1610,  2203,   370,   476,   211,    64,   476,
      66,  2603,   271,   203,    84,   501,   169,   418,   346,   416,
     289,  2420,   446,   561,   476,   460,   476,  1000,  1001,  1965,
     423,   446,   504,   354,  1470,   476,  1331,   468,   292,   243,
     129,  1010,   341,   212,  1249,   460,   346,   317,  1984,  1985,
     503,     9,  1988,   504,  1289,  2512,  1584,   410,  2035,  2036,
    1660,   265,     1,   460,   504,   504,  2466,   482,   346,   504,
     223,   238,    11,   177,  2273,   510,   317,  2276,  2277,   257,
     187,   385,   342,  1470,   204,   252,  1381,   256,   416,   504,
    2289,   503,    50,  2029,   196,   510,   504,   266,  2034,   289,
     468,   458,   274,   210,  2303,  2304,   463,   504,   212,   387,
     256,   501,   232,   510,   318,   504,   416,  2574,   446,    58,
     504,  2515,  1095,  1559,  1329,   256,  1099,   446,   268,  2043,
    1365,  2045,   460,  1106,  1107,   456,  1664,   241,   416,  2051,
     271,  1114,   231,   504,  1117,   751,  2093,  2204,  1584,  1122,
    1757,  1124,   256,  1126,  1127,  1128,  1129,    96,   256,    98,
     460,   100,   266,   422,  2082,   424,     1,  2366,   335,   108,
    2084,   204,  1559,  1146,   378,   504,   504,   346,   497,   351,
     347,   353,   510,   252,  2131,  2132,   376,  2579,   286,   220,
     321,  2103,   798,   451,   268,     9,   252,  2591,  2482,   232,
     340,   321,   291,    28,   504,    40,    41,    42,    43,    44,
     510,  2410,   406,  1475,  2150,  1671,   171,  1237,  2174,  1655,
    1792,   252,  2615,  2137,  1660,   164,   125,   281,   282,   283,
    1149,   329,   510,   199,  1806,  2497,    26,   207,   208,   170,
      75,    76,   346,    57,  2497,  2497,  1751,   416,  1221,   204,
    2497,  2497,  1688,  2497,   212,   212,   396,   435,  2651,     8,
    1179,   401,   331,   504,    56,  2657,   340,  1240,  1288,   473,
     437,    63,   171,  1660,   285,   331,   246,   247,   262,  2671,
     212,   171,   476,  2683,   138,   411,   244,   245,    37,  2236,
     344,   460,    12,   351,   225,    15,    16,   450,   256,   256,
     177,   126,   233,   287,  1277,   458,   459,    30,   266,   266,
     463,   451,   416,   503,   204,  1288,   494,   262,   257,  1126,
     351,   292,   396,   334,   256,     2,   504,   401,   359,  1955,
       7,   451,   458,   394,   266,   504,  1356,   463,   187,  1146,
     262,   510,   287,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    47,   324,   412,   413,   460,   323,   324,  1332,
     237,   210,   301,   240,   468,   287,   262,    62,     6,    53,
      54,     9,  1345,   504,   340,   256,  1349,   451,  1583,   510,
     187,   750,   751,   451,   107,   356,   317,   212,   346,   346,
     450,   287,  2328,  1898,   306,   379,  2332,   555,   212,   459,
     504,  2008,   560,   210,   127,    89,   510,   102,  2592,  2593,
    1383,    49,   466,   467,   346,  1383,   451,   471,   481,  1649,
      13,    14,   106,  1117,   248,   249,   338,   241,   394,   798,
     504,   256,   116,   216,   217,  1129,   499,  2621,  1458,    32,
      16,   266,   256,   166,    82,  1418,   358,  2482,   451,    87,
    2397,   390,   266,   236,   504,   280,  2640,    33,   416,   416,
    2026,    99,  2376,   453,  2378,   188,    42,  2163,   262,   423,
      45,  1444,  2449,  2450,   464,  2452,   268,   405,  2599,   262,
     232,   204,   161,  2011,   416,   455,   165,   457,  2545,    64,
      65,    66,    67,   287,   433,   330,  2617,  1953,  2682,  2004,
       9,   394,   460,   460,   287,   405,   750,   751,   343,  2445,
    2446,  2458,   451,   451,    54,  2462,  2463,  1416,   451,   503,
     504,   346,  1421,  1422,  1497,  1424,   451,     9,   460,  2129,
      12,   448,   346,    15,    16,   232,  2064,   232,  1195,    57,
     106,   458,  1199,   451,   239,  2501,   463,  1567,   340,    89,
     116,    11,   510,   510,   798,   250,   218,   277,   278,   256,
     177,   173,   356,   201,   451,   504,   106,   307,   451,   309,
     187,  1591,  1545,    82,   212,   473,   116,   475,   510,  1603,
     478,   301,   302,   485,   486,   487,   488,   299,   300,  1562,
      99,   416,  1565,   210,   419,   420,  1616,   504,    58,  1173,
    1174,  1175,   416,  1576,   396,   449,    68,   245,  1870,   401,
     307,  2139,   309,   251,   458,   253,   449,   340,   256,   463,
     258,   259,   260,   240,   451,   458,   264,   340,   266,  1602,
     463,    96,    97,   271,   209,   448,    96,   321,    98,   504,
     100,   325,   326,   448,   504,   458,   460,   351,   108,   353,
     463,   212,  1714,   458,   468,  1628,   351,   352,   463,   451,
     235,  1630,  1724,  1725,   451,   303,  1728,   212,   256,   504,
     308,   366,   156,   368,   158,  1171,  1172,   252,  1651,   254,
     474,   451,   366,  1651,   322,   510,   485,   486,   487,   488,
     504,   256,   201,  2129,   468,   256,   510,   199,   382,   383,
     351,   504,   353,   212,   164,   266,   442,   400,   346,   503,
     285,   256,  1391,  1157,  1158,  1614,  1395,   500,   401,   357,
     503,   266,   351,  1402,   353,  1694,  2254,   156,   410,   158,
     305,    63,    24,    25,  1652,  1653,  1654,    59,   232,   377,
    1658,   256,  2129,  1661,  1662,   451,  1715,   256,   328,   258,
     259,   260,   327,   401,  2154,   264,   451,   266,   333,   485,
     486,   487,   488,   252,   256,   254,   226,   252,   229,   254,
    1669,  1670,   410,    65,   252,    67,   254,    69,   416,   504,
      26,  1680,  1755,   451,   451,   346,  1759,   107,  1687,  1762,
     428,   429,  1765,   451,   303,   277,   278,   257,    65,   312,
      67,   346,   256,   498,   620,   621,   622,   623,   967,   256,
     969,   103,   104,   105,   272,   454,    23,  1716,    35,   301,
     302,    38,   460,  2085,   102,   451,   437,   188,    45,    46,
     405,   122,   470,   454,   783,    17,    86,   346,   476,   414,
     504,   301,  1815,   451,   304,   394,   272,   351,  2078,   401,
    1870,   402,   490,    56,   503,   416,   431,   495,   262,   423,
     498,   153,    39,   155,   502,   451,   504,   237,   377,   402,
     162,   416,   510,   165,    91,  1774,   451,   504,   331,  1903,
    1904,  1905,  1906,  1907,  1908,  1909,  1910,   506,   504,   419,
     310,  1864,  1865,  1866,  1793,   316,   394,   472,   261,     7,
    1799,  1921,   255,   451,   451,   451,   394,   416,   504,   369,
    1930,  1931,   503,   451,   394,   460,   491,   366,    85,   428,
     429,    85,   451,   498,   499,   451,   124,   451,   394,    22,
     390,   306,   389,   309,   451,   394,   204,   504,   384,   499,
     451,   504,   501,   160,   783,   232,   504,   446,   165,   510,
    1923,   460,   254,   218,   504,   415,   122,   417,    26,   504,
     252,   470,   254,   446,   400,   510,   510,   462,   442,   306,
     447,   410,   189,   433,   348,  1948,   504,   445,   442,   271,
    1948,   490,   256,   462,   451,   504,   495,  1960,   451,   376,
     399,   336,  1965,   502,   211,   504,   114,   169,   187,   504,
     451,   510,   256,   309,   446,   403,   462,   462,   451,  1978,
     462,  1984,  1985,   504,   462,  1988,   451,   462,   967,   968,
     969,   462,   462,   504,   462,   462,   453,    30,   504,   130,
     446,   196,   131,   133,   132,  1934,   386,  2010,   134,   136,
     989,   135,   137,   101,   504,   441,   446,   497,   265,   462,
     140,    49,   404,  1952,   445,   445,  2029,   442,   439,   143,
     196,  2034,  2035,  2036,   144,  2085,  2035,  2036,  2587,  1968,
    2043,  1970,  2045,   145,  2094,  1974,   146,   499,   271,    31,
     147,    49,   148,  1982,  2540,   149,   196,  2606,   150,   112,
     151,   220,   448,   448,   448,   114,   410,   448,   312,   448,
     448,   318,   446,   109,   451,   197,   446,   223,   339,  2082,
     376,  2084,    32,   256,  2570,    35,   955,   203,    38,   272,
     231,   294,   298,   165,   484,   175,    46,   128,   967,   968,
     969,   365,   501,   501,   446,   168,   129,   228,   446,    49,
     196,   228,   176,  1092,   204,  1094,   504,   299,  1097,    56,
     989,   443,  1101,   204,   451,   272,  2592,  2593,   165,   237,
     423,   378,   508,   252,  2137,   299,   509,  1116,   380,   276,
     446,    91,   362,  1122,   391,   446,   295,  2150,  2077,    30,
      17,  2154,   203,   203,   442,  2621,  2154,   128,   139,   446,
     110,   365,    49,   203,  1143,   141,  1145,     8,   129,   196,
    1149,   493,   501,  2465,  2640,  2592,  2593,  1156,  1157,  1158,
    1159,   501,   504,   423,   203,  1164,   451,   446,     9,     7,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,   256,  1178,
    1179,   504,    35,   503,  2621,    38,   203,   294,   297,   503,
      49,   188,    45,    46,   291,   498,  2682,   498,   262,   314,
     461,  2513,   113,  2640,   330,  1094,   473,  2230,  1207,  2232,
    1099,   313,    47,   411,   203,   436,   203,  1106,   294,   189,
     102,   380,    49,   361,   262,  1114,   361,   237,   198,   296,
      95,   292,  1231,   492,  1233,    56,     8,  2260,    91,  1128,
    2263,   211,  2260,    49,   110,  2682,   456,     4,   337,   262,
     262,   262,   451,   109,   210,   337,   481,   451,   107,   340,
    1149,   209,    19,   221,   501,   418,   196,  1156,  1157,  1158,
    1159,  2294,    29,   243,   367,  1164,   119,   313,   337,    49,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,   321,  1178,
    1179,  2314,   306,   263,   425,   265,  2314,     7,    46,    92,
      26,   127,   201,   148,   206,  2328,    63,   160,    75,  2332,
     238,   221,   519,   150,   177,  1314,   410,   287,   288,  1208,
    1869,   286,   425,  1009,   773,   497,  1422,  2590,   740,  2655,
    1862,  2152,   788,  2634,  2667,  2603,   189,  1336,  2175,  2175,
     469,   779,  2048,  2292,  1018,  1204,  1727,   841,   318,  1726,
    1809,  1240,  2359,  2376,  2347,  2378,  1761,  1456,   211,  1221,
    2046,  1458,  1483,  1362,  2228,  1502,  2050,  1505,  1828,  1548,
    1273,  2394,  1555,  2073,  2246,   345,  1856,  1309,  1566,  1314,
    2085,  2092,  1596,  1882,  1931,  2106,  2698,  2336,  1277,  1343,
      82,  1129,  2341,  1911,  1345,  1359,  2132,  1930,  2297,  1288,
    1930,   371,  2651,  2400,  1643,  2302,  2307,    99,   378,  1534,
    2125,  1332,   265,  2125,  1452,  2125,  2125,   691,   299,   152,
    1898,   391,  2445,  2446,   270,   395,  2449,  2450,   242,  2452,
    2449,  2450,   972,  1432,   745,  2523,  2569,   417,  2388,   215,
     449,   509,  1918,  2062,  1861,   558,  1558,  1336,  2594,   705,
    2399,    -1,    -1,    -1,    -1,    -1,  1345,    -1,    -1,    -1,
    1349,    -1,    -1,   220,    -1,   318,    -1,    -1,    -1,    -1,
      -1,  1470,    -1,    -1,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2431,  2432,    -1,    -1,    -1,    -1,    -1,  2512,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,  2448,
      -1,    -1,    -1,   473,    -1,   262,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   483,    -1,  2464,    -1,    -1,    -1,   489,
     212,    -1,    -1,  2542,    -1,   378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,
    2489,    -1,    -1,  1432,    -1,  2494,  2495,    -1,    -1,    -1,
      -1,  2574,  1551,   245,    -1,  1444,    -1,    -1,   315,   251,
    1559,   253,    -1,   320,   256,  2514,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,  1575,    -1,    -1,  2598,
      -1,  1470,    -1,  2602,    -1,  1584,    -1,    -1,    -1,    -1,
      -1,    -1,  2615,    -1,   351,  2544,  1595,    -1,  2547,  2548,
      -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,  1497,    -1,
      -1,   303,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
     473,    -1,    -1,    -1,  1623,    -1,    -1,    -1,  2651,    -1,
     322,    -1,    -1,    -1,  1633,    -1,    -1,    -1,    -1,    -1,
    2589,    -1,    -1,    -1,   401,    -1,    -1,   404,    -1,    -1,
      -1,    -1,  2675,    -1,   346,   412,  1655,    -1,    -1,    -1,
      -1,  1660,  1551,    -1,    82,    -1,   423,  2686,    -1,    -1,
    1559,    -1,    -1,  1562,    -1,    -1,  1565,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,   377,    -1,    -1,    -1,  1688,
      -1,    -1,    -1,    -1,   451,    -1,    -1,   454,    -1,    -1,
      -1,  1700,    -1,    -1,  1703,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1602,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,  1737,  1628,
      -1,    -1,    -1,    -1,  1633,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,   460,    -1,
     462,  1660,   190,    -1,    -1,    -1,    -1,     1,   470,     3,
      -1,     5,    -1,   201,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,   490,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    71,  1737,     6,
      74,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,  1858,
    1859,    -1,    -1,    -1,    88,    -1,  1755,    -1,    -1,    -1,
    1759,    -1,    -1,  1762,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,   111,  1887,    -1,
      -1,    -1,    -1,    -1,    -1,   119,  1895,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1922,    -1,    82,  1815,    -1,   152,    -1,
    1929,  1930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    82,    99,    -1,   168,    -1,    -1,    -1,    -1,    -1,
    1949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   377,
    1959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1858,
    1859,   195,    -1,    -1,    -1,  1864,  1865,  1866,   202,    -1,
      -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   152,    -1,    -1,   222,    -1,
     224,    -1,    -1,   227,    -1,    -1,  1895,    -1,    -1,    -1,
     428,   429,  2011,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1923,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,   201,   269,    -1,    -1,    -1,   273,
      -1,   275,   470,    -1,    -1,   212,  2055,    -1,    99,    -1,
     201,   285,    -1,   481,    -1,  2064,  2065,    -1,    -1,    -1,
      -1,    -1,   490,    -1,  2073,    -1,    -1,   495,    -1,    -1,
      -1,   499,    -1,    -1,   502,   503,   504,   311,   245,    -1,
      -1,    -1,    -1,  2092,   251,    -1,   253,    -1,    -1,   256,
     324,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,    -1,    -1,   271,   256,    -1,   258,   259,   260,
      -1,  2010,  2121,   264,    -1,   349,   350,    -1,    -1,    -1,
    2129,    -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,
    2139,    -1,    -1,    -1,  2143,    -1,   303,    -1,    -1,    -1,
     374,   375,    -1,    -1,  2043,    -1,  2045,   381,    -1,    -1,
     201,   385,   303,    -1,    -1,   322,  2165,    -1,    -1,   393,
      -1,   212,    -1,    -1,    -1,  2174,  2065,    -1,    -1,   403,
      -1,    -1,    -1,    -1,  2073,    -1,    -1,    -1,   412,   346,
      -1,    -1,    -1,  2082,    -1,  2084,    -1,   421,    -1,    -1,
      -1,    -1,   426,   427,    -1,    -1,   430,    -1,   432,    -1,
    2209,    -1,    -1,    -1,   438,   256,    82,   258,   259,   260,
     377,    -1,    -1,   264,    -1,   266,    -1,   451,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,   377,    -1,    -1,    -1,
    2129,    -1,    -1,    -1,    -1,   469,    -1,    -1,  2137,    -1,
      -1,   475,    -1,    -1,  2143,  2254,   480,    -1,    -1,   416,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   507,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,   346,    -1,   464,    -1,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,   490,    -1,   201,   377,    -1,   495,    -1,
      -1,  2230,    -1,  2232,    -1,   502,    -1,   504,    -1,   490,
      -1,    -1,    -1,   510,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,
    2369,    -1,    -1,    -1,  2263,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,     1,   264,     3,
      -1,     5,    -1,    -1,    -1,  2294,    10,    -1,    -1,    -1,
      -1,    -1,    -1,  2412,    18,    -1,    -1,    -1,    -1,   460,
    2419,    -1,    -1,  2422,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,   490,
      -1,    -1,    -1,    -1,   495,    -1,    60,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    71,    -1,   510,
      74,    -1,  2471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,  2485,  2376,    -1,  2378,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2501,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,   377,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
    2549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,   428,   429,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,  2592,  2593,    -1,    -1,    -1,   202,    -1,
      -1,   205,   206,    -1,   470,    -1,    -1,    -1,    -1,    -1,
    2609,   215,    -1,    -1,    -1,   481,    -1,    -1,   222,    -1,
     224,    -1,  2621,   227,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,   499,  2633,  2634,   502,   503,   504,    -1,
      -1,  2640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,   269,    18,    -1,    -1,   273,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2678,
      -1,   285,    -1,  2682,    -1,    -1,    -1,   291,   292,    -1,
     294,   295,   296,   297,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,  2592,  2593,    -1,    -1,   311,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
     324,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2621,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   349,   350,    -1,    -1,    -1,
      -1,  2640,    -1,    -1,    -1,    -1,   360,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
     374,   375,    -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,    -1,  2682,    -1,    -1,    -1,    -1,    -1,   403,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,
      -1,   163,    -1,    -1,    -1,    -1,   168,   421,    -1,    -1,
      -1,    -1,   426,   427,    -1,    -1,   430,    -1,   432,    -1,
      -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,   195,     3,    -1,     5,   451,    -1,    -1,
     202,    10,    -1,   205,   206,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,   215,    -1,   469,    -1,    -1,    -1,    -1,
     222,   475,   224,    -1,    -1,   227,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,   501,    -1,    -1,
      -1,    60,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,   269,    -1,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   311,
     119,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   349,   350,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   360,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    -1,   381,
      -1,    -1,    -1,   385,    -1,    -1,   195,    -1,    -1,    -1,
      -1,   393,    -1,   202,    -1,    -1,   205,   206,    -1,    -1,
      -1,   403,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
     412,    -1,    -1,   222,    -1,   224,    -1,    -1,   227,   421,
      -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   273,    -1,   275,   469,    -1,    -1,
      -1,    -1,    -1,   475,    -1,    -1,   285,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,    -1,
      -1,    -1,   311,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,
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
     135,   136,   137,    -1,   139,   140,   141,   228,   143,   144,
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
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   448,    -1,   450,    -1,   452,
      -1,    -1,   455,    -1,   457,   458,   459,   460,    -1,   462,
     463,    -1,    -1,    -1,    -1,   201,    -1,   470,    82,    -1,
      -1,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    99,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,   201,    -1,    -1,    -1,   510,    -1,   245,
     246,   247,    -1,    -1,   212,   251,    -1,   253,    -1,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   284,    -1,
      -1,    -1,    -1,   251,   290,   253,    -1,   293,   256,    -1,
     258,   259,   260,    -1,    -1,   301,   264,   303,   266,    -1,
      -1,    -1,   308,   271,    -1,    -1,    -1,   313,     6,    -1,
      -1,     9,    -1,    -1,    -1,    -1,   322,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,     6,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,   377,   256,    -1,   258,   259,   260,    -1,   346,    -1,
     264,    -1,   266,    -1,    82,    -1,    -1,   271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
     416,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,   303,
      82,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    99,   322,    -1,
      -1,    -1,   448,    -1,   450,    -1,   452,    -1,   416,   455,
      -1,   457,   458,   459,   460,    -1,   462,   463,    -1,    -1,
     428,   429,   346,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
      99,    -1,   460,   377,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,   470,   201,   510,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,   416,    -1,   502,    -1,   504,    -1,    -1,   201,
      -1,    -1,   510,    -1,   428,   429,    -1,   245,    -1,    -1,
     212,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,   460,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,   470,    -1,    -1,   251,
      -1,   253,   201,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,   212,   266,   303,   490,    -1,    -1,   271,
       6,   495,    -1,     9,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,   322,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   303,   251,    -1,   253,    -1,    -1,   256,   346,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
     322,    -1,   271,     6,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,   346,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,   377,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,   346,    -1,    82,
      -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    99,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,   428,   429,   377,   165,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,   460,    -1,
      -1,    -1,    -1,    -1,   502,   201,   504,   416,   470,    -1,
      -1,    -1,   510,    -1,    -1,    -1,   212,    82,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,
      -1,    -1,    -1,   495,    99,    -1,    -1,   446,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,   245,
      -1,   460,    -1,    -1,    -1,   251,    -1,   253,   201,    -1,
     256,   470,   258,   259,   260,    -1,    -1,    -1,   264,   212,
     266,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,   245,    -1,    -1,    -1,    -1,   303,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,   322,    -1,   271,    -1,
      -1,   196,    -1,    -1,     6,    -1,   201,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,     6,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     245,   377,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,   346,    -1,    -1,   271,    -1,    -1,    -1,
      82,    -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   428,   429,   377,    -1,    -1,    -1,   303,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   322,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,   470,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,   428,   429,    -1,    82,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,    -1,    99,   502,    -1,   504,    -1,
      -1,    -1,   377,    -1,   510,    -1,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   484,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,   416,   495,    -1,    -1,    -1,    -1,    -1,   201,   502,
      -1,   504,    -1,   428,   429,    -1,    -1,   510,    -1,   212,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,   460,    -1,    -1,    -1,   271,
      -1,    -1,   245,    -1,    -1,   470,    -1,   201,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,   212,    -1,
      -1,   264,    -1,   266,    -1,   490,    -1,    -1,   271,    -1,
     495,   303,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
     322,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
     303,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,     6,   346,    -1,     9,   271,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,   377,    -1,    -1,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,   410,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    82,
      -1,    -1,   346,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,    -1,   428,   429,    -1,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,   490,    -1,
      -1,    -1,   416,   495,    -1,    -1,    -1,   470,    -1,    -1,
     502,    -1,   504,    -1,   428,   429,    -1,    -1,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,   460,   510,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,   245,    -1,    -1,    -1,   510,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,    32,    -1,    -1,    35,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,   416,    -1,    -1,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,   160,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,
      -1,   178,   179,   180,   181,   182,     1,    -1,   185,   186,
      -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,    -1,    -1,    -1,    21,   204,    -1,    -1,
      -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    36,   219,    -1,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,   232,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    81,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     327,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,   345,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
     175,    -1,    -1,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,
      -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,
      -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,   405,    -1,
     407,   408,   409,    -1,    -1,    -1,    -1,   232,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,
      -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,   456,
      -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   468,    -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,
     477,   478,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     305,    -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,
     497,   498,    -1,    -1,   319,    -1,    -1,   504,    -1,    -1,
      -1,    -1,   327,    -1,    21,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    36,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     405,    -1,   407,   408,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   434,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   477,   478,   479,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,   181,   182,   491,    -1,   185,   186,
      -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    73,   241,    75,    76,    77,    78,    79,
      80,    81,    32,    -1,    -1,    35,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     277,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,   119,
      -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     327,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    -1,   355,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    99,   405,   189,
     407,   408,   409,    -1,    -1,    -1,   196,    -1,   198,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,   434,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,
      -1,    -1,   232,    -1,   451,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   468,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477,   478,   479,    -1,    -1,   265,    -1,    -1,    -1,   319,
      -1,    -1,    -1,    -1,   491,    -1,    -1,   277,    -1,    -1,
     330,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    82,   343,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,
     330,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,   343,   256,   345,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,   407,   408,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   405,    -1,   407,   408,   409,
     322,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,   477,   478,   479,
      -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,   446,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,   245,   456,    -1,    -1,    -1,
      99,   251,    -1,   253,    -1,   377,   256,    -1,   258,   259,
     260,    -1,    -1,   473,   264,    -1,   266,   477,   478,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   491,    -1,    -1,    -1,    -1,    -1,   497,   498,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,   448,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   458,    82,   460,    -1,
     462,   463,    -1,    -1,    -1,    -1,   346,    -1,   470,    -1,
      -1,    -1,   201,    82,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   490,    -1,
      99,    -1,    -1,   495,    -1,    82,    -1,   377,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,    -1,    99,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,   416,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,
      -1,    -1,    -1,    -1,   303,    -1,   201,    -1,   458,    -1,
     460,    -1,   462,   463,    -1,    -1,    -1,   212,    -1,    -1,
     470,    -1,   201,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,   201,   495,    -1,   346,    -1,    -1,
     245,    -1,   502,    -1,   504,   212,   251,    -1,   253,    -1,
     510,   256,    -1,   258,   259,   260,   245,    -1,    -1,   264,
      -1,   266,   251,    -1,   253,    -1,    -1,   256,   377,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,   245,    -1,
      -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,    -1,   264,   303,   266,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   322,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,   303,    -1,    -1,   448,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,
      -1,   460,    -1,   462,   463,   322,    -1,   346,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,   346,
      -1,   490,    -1,    -1,   373,    -1,   495,    -1,   377,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,   458,    -1,   460,    -1,   462,   463,    -1,
      -1,   428,   429,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,   460,    -1,    -1,    -1,   502,    -1,   504,
      -1,   490,    -1,   470,    -1,   510,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510
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
     603,   535,   523,   451,   232,   537,  1267,   504,  1187,  1187,
     423,   405,  1285,  1267,  1267,  1267,   394,  1187,   405,   451,
     451,  1267,   451,   451,    57,  1255,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1267,  1267,  1267,   504,  1182,  1213,
      68,  1182,   451,  1267,  1267,   549,   560,  1182,   545,   504,
     587,   588,   589,  1188,   256,   307,   309,   573,   575,  1032,
    1216,  1267,   451,   504,   451,   606,   539,   340,  1282,  1267,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1219,
    1182,   256,   218,   306,  1305,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1254,  1315,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1188,  1268,  1032,   232,   423,  1279,  1267,
      96,  1187,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1298,  1213,   400,   401,   410,
      63,  1267,   451,   552,   451,   504,   551,    59,  1267,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1298,   256,
     590,  1217,  1279,   232,  1187,  1187,   574,   575,   451,     1,
     290,   312,  1240,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1219,   328,  1267,   401,  1216,   451,  1267,
     504,  1183,   229,    26,   565,   229,   370,   451,   451,   107,
    1217,  1187,   451,   312,  1187,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1216,   257,   435,
     494,   557,  1183,   256,   272,   608,   454,  1258,    23,  1249,
     102,   648,   451,   582,   583,    57,   505,  1309,   609,   437,
    1291,   188,  1260,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1283,  1299,    86,  1256,   504,  1172,  1173,   451,   394,   650,
     583,   272,  1274,   351,  1283,   446,   497,  1295,   401,   402,
    1267,  1254,   113,   237,  1269,  1269,   287,   635,  1216,  1298,
     423,   262,    39,  1252,  1267,   645,   646,  1173,  1173,   451,
     172,   392,   530,   651,   652,   654,  1267,  1269,   125,   171,
     614,   359,   628,  1267,  1267,  1267,  1267,  1249,     9,   287,
     349,   637,  1267,  1274,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1173,   125,   347,   402,   618,  1267,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1182,  1186,   419,   632,  1182,  1182,   316,  1280,  1280,
     310,  1182,  1267,  1216,   394,   261,   732,   683,   684,   686,
     696,  1232,   451,   653,   632,   256,   616,  1213,   616,     7,
     616,   616,   256,   615,  1213,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1234,  1314,  1258,
    1267,  1181,  1182,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1267,   124,  1181,
    1182,   262,   385,   681,   733,   451,   394,   389,   781,   698,
     689,  1267,  1256,  1267,   351,   353,  1310,  1310,  1267,  1256,
    1267,  1274,  1267,    22,  1248,   306,   678,  1187,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1267,
    1287,    26,   196,   697,  1250,   204,  1216,   504,  1267,  1248,
     504,  1184,  1185,   308,   418,  1306,  1186,  1216,   499,  1267,
     174,   213,   504,   665,  1187,   274,   351,   353,  1308,   681,
     737,   451,   337,   795,   798,   244,   301,   406,   476,  1286,
     476,  1286,   476,  1286,   476,  1286,   476,  1286,   501,  1296,
     384,  1284,  1216,  1210,  1213,  1213,   232,   242,   384,  1270,
    1267,  1268,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1220,
    1221,  1222,   446,   662,  1185,   254,  1273,   446,  1255,   218,
    1262,   504,  1267,  1267,  1308,   738,   782,   122,   821,   822,
     510,   446,   713,   462,  1214,  1215,   442,   706,   727,   728,
    1220,    26,   702,   400,  1244,  1244,  1222,   306,  1277,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1210,   691,   447,  1216,    57,   353,   658,   669,  1216,
     410,  1288,   256,   666,  1213,   666,   348,   739,   686,   696,
     783,   784,   785,    55,   497,   799,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   823,   824,
     840,   845,   849,   854,   869,   872,   876,   880,   881,   882,
     887,   901,   905,   908,   922,   926,   929,   932,   936,   937,
     941,   951,   954,   971,   973,   976,   980,   986,   998,  1006,
    1007,  1010,  1011,  1015,  1020,  1021,  1029,  1044,  1054,  1063,
    1068,  1075,  1079,  1081,  1084,  1087,  1091,  1118,   823,  1216,
     445,  1293,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1160,  1162,  1163,  1164,  1165,  1166,
    1167,  1195,  1209,  1210,  1221,  1223,  1224,  1225,  1226,   462,
    1215,  1213,   726,   728,   442,   256,  1254,   691,   451,  1222,
      48,   465,   670,   671,   672,   673,  1298,  1255,   196,   661,
    1261,   504,  1174,     1,   687,   785,   451,   801,   800,   376,
     807,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1245,   825,   841,   846,   850,   855,   870,   873,   877,
     883,   888,   902,   906,   909,   923,   927,   930,   933,   203,
     376,   864,   925,   938,   942,   952,   955,   972,   974,   977,
     399,   981,   987,   999,  1008,  1012,  1016,  1022,  1030,  1045,
    1055,   256,   346,   387,   416,   510,  1067,  1069,  1076,   336,
    1080,  1082,   810,  1085,  1088,  1092,  1119,   114,   714,   462,
    1228,  1210,  1221,  1223,  1305,  1305,   462,   462,   462,   462,
    1305,  1166,  1162,  1166,   462,  1228,    70,   398,   448,  1161,
     449,   458,   463,   450,   459,   169,   462,  1227,   462,   462,
    1162,   501,   729,  1297,  1220,  1186,  1186,   187,   662,  1216,
     740,   451,   786,   451,    49,   802,   803,   804,  1253,   802,
     504,   451,   308,   826,   827,  1209,     6,    94,   245,   271,
     842,  1167,  1191,  1192,  1209,  1220,  1223,   847,  1162,  1209,
     256,   851,   852,  1178,  1179,  1180,  1213,   271,   422,   424,
     856,   857,   256,   871,  1200,  1209,   874,  1173,     6,   878,
    1168,  1169,  1190,  1211,  1212,  1213,  1221,   454,   884,  1173,
     256,   889,   890,   892,  1191,  1192,  1200,  1209,   903,  1192,
     256,   907,   453,   464,   910,   911,   912,  1150,  1151,  1152,
     199,   323,   324,   340,   394,   924,   928,  1189,  1190,   931,
    1213,   446,   934,  1294,  1192,  1149,  1150,   943,  1189,   953,
    1174,   956,   957,  1209,  1220,  1223,  1046,  1207,  1208,  1213,
      94,   975,  1192,   978,  1192,   170,   225,   233,   317,   982,
     983,   190,   256,   988,   992,   993,   994,  1178,  1201,  1209,
    1213,  1223,  1298,  1000,  1173,  1009,  1170,  1213,  1013,  1173,
    1017,  1170,     9,  1023,  1171,  1213,   153,   271,  1031,  1034,
    1035,  1038,  1039,  1040,  1041,  1042,  1043,  1175,  1176,  1189,
    1206,  1208,  1213,  1046,  1056,  1173,  1064,   112,  1070,  1071,
    1072,  1192,    94,  1077,  1191,  1083,  1174,   451,   504,   811,
     812,   815,   816,   821,  1086,  1209,  1089,  1173,  1093,  1209,
    1120,  1170,   309,  1278,   715,   716,   448,  1160,  1162,   504,
     504,  1162,  1231,  1231,  1231,  1194,  1209,  1221,  1223,  1230,
     504,   448,  1194,  1229,  1162,   448,  1162,  1163,  1163,  1164,
    1164,  1164,  1162,  1194,  1160,   403,   453,    30,  1251,  1255,
       1,   741,   787,   803,   410,   476,   805,   357,   498,   796,
     130,   839,    30,   829,   830,  1251,   196,  1277,  1209,  1210,
    1221,  1223,   131,   844,   446,   843,  1192,    57,   223,  1235,
     852,   446,  1305,   132,   868,   256,  1201,  1200,  1173,   356,
     474,   875,  1298,  1311,  1277,   133,   879,   159,   452,  1169,
    1302,   386,  1241,  1214,  1215,   885,  1173,   134,   886,  1283,
     135,   900,   165,   891,  1129,  1130,   484,   893,   503,   830,
     485,   486,   487,   488,   136,   904,    49,   228,   497,   858,
     137,   921,    17,   501,   913,   914,   915,   917,    12,    13,
      14,    20,   159,   169,   207,   208,   246,   247,   284,   290,
     293,   301,   308,   313,   332,   448,   450,   452,   455,   457,
     458,   459,   462,   463,  1153,  1154,  1155,  1156,  1157,  1158,
    1159,  1192,   101,   925,  1190,  1177,   441,  1292,   944,  1298,
    1174,    92,   365,   436,   958,   959,   961,   962,  1048,   462,
    1214,  1192,   446,   140,   979,    49,   983,   404,   984,   993,
     141,   451,   989,   991,   481,   499,   442,   445,   439,   143,
    1005,   285,   334,  1238,   196,  1121,   144,  1014,  1283,   145,
    1019,  1121,  1171,   146,  1028,   499,  1024,  1198,  1209,  1221,
    1041,  1043,  1189,   446,  1176,   123,   446,   482,  1033,    31,
    1214,   147,  1062,   177,   237,   240,  1058,   864,  1065,  1298,
    1253,   148,  1074,   228,  1072,  1209,   149,  1078,   196,  1174,
     394,   451,   451,   196,   351,   353,  1090,   150,  1102,   112,
    1094,   151,  1125,  1121,  1182,   220,   718,    27,   115,   717,
     448,  1161,   448,   448,   448,  1161,   448,  1161,   448,   448,
     449,   448,   448,   446,  1267,  1186,   114,   660,   451,    61,
      89,    90,   321,   451,   742,   743,   746,  1267,  1323,    32,
      35,    38,    45,    46,    64,    66,   160,   189,   196,   198,
     211,   243,   252,   265,   305,   318,   345,   371,   378,   395,
     446,   456,   473,   497,   704,   705,   709,   721,   723,   725,
     788,   793,   794,  1267,  1300,  1267,   410,   312,   806,   109,
     808,  1198,   197,   833,   252,   331,   831,   832,  1300,    24,
      25,    65,    67,    69,   103,   104,   105,   153,   155,   162,
     165,   252,   254,   443,   493,   504,   828,  1176,  1301,   152,
     340,  1196,  1210,   446,     6,  1168,  1192,  1213,  1221,   203,
     223,  1236,   376,   848,   339,   853,  1180,   858,   875,   262,
     287,  1260,  1210,  1162,   272,  1242,  1215,  1173,   231,  1145,
    1146,   818,   819,   892,  1192,   294,  1131,    96,   335,   504,
    1176,   298,   897,    35,    38,    45,    46,    91,   160,   189,
     211,   265,   318,   378,   391,   473,   898,   899,   484,   894,
    1129,  1129,  1129,  1129,  1192,  1168,  1192,   859,   912,    21,
     453,   464,   918,   919,  1151,   501,   915,   916,   501,   818,
    1294,   232,  1154,   114,   935,  1178,   128,   818,   939,     9,
      12,    15,    16,   277,   278,   301,   302,   945,   949,   175,
    1198,     9,    57,   177,   241,   468,   965,   966,   967,   960,
     961,  1050,  1278,  1314,   446,  1189,  1168,  1192,   984,  1298,
    1172,   818,   168,   995,  1149,   996,   997,  1209,  1178,     8,
      37,  1123,  1283,  1205,  1209,  1220,  1223,   228,  1001,  1018,
    1298,   129,  1025,  1209,  1025,   446,   446,  1032,   152,   453,
     464,  1192,    49,    38,    46,   211,   243,   265,   318,   378,
     473,  1036,  1037,  1267,  1057,  1298,  1192,   161,   289,   410,
    1192,  1209,   196,  1168,  1192,   817,  1216,  1198,  1253,   228,
    1097,  1122,  1123,  1253,  1269,  1182,  1227,  1227,  1227,  1194,
     241,   468,  1227,   448,  1162,  1227,  1227,  1220,  1278,  1267,
    1267,  1248,   248,   249,  1272,   755,   204,   176,   744,  1259,
    1267,   252,   389,   156,   158,  1267,  1201,   299,  1275,  1216,
      56,  1209,  1209,   204,  1275,    32,   110,  1216,  1267,   504,
     451,   797,   272,   834,  1275,  1275,   832,   831,  1275,   165,
    1126,  1127,   509,   508,  1198,  1126,   237,   423,   299,   276,
     256,  1197,  1210,  1209,  1277,   411,  1132,  1133,  1214,  1215,
    1168,   446,  1237,   848,  1190,   446,  1178,   863,   864,   380,
     362,  1132,  1267,   818,   295,  1147,   820,   818,  1129,  1267,
     252,   389,   156,   158,  1267,   123,   482,   899,  1129,    96,
      97,   895,   834,   203,  1132,   203,   860,   861,   862,  1253,
      17,   442,   920,   316,   918,  1278,   818,   128,   139,   940,
    1294,   365,   946,  1294,   446,    49,   966,   968,  1198,     9,
      57,   241,   468,   963,   964,  1198,  1051,  1299,   717,   218,
     314,  1263,  1189,  1132,   203,  1172,   637,   379,   985,  1298,
     141,   990,     8,   196,  1001,  1209,   129,  1138,  1140,  1145,
     262,   287,   818,   501,   501,  1026,  1027,  1198,  1197,  1192,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1037,   290,
     293,  1059,  1060,  1061,  1155,  1239,  1145,   244,   410,  1313,
     423,  1290,  1290,  1073,  1298,  1209,  1132,   203,   451,   446,
       9,  1095,  1096,  1233,  1098,  1209,  1073,  1098,  1018,     7,
    1246,   504,   719,   720,  1267,   448,  1182,  1200,  1267,  1248,
     256,   747,  1218,   686,   756,   745,  1209,   510,  1202,  1206,
    1216,  1202,  1267,  1293,  1267,  1267,    32,  1216,   809,   810,
    1267,   503,   835,  1202,  1202,  1202,   818,   294,  1128,  1126,
    1241,  1210,   818,   297,  1134,  1215,  1132,  1199,  1209,  1220,
     165,   461,   866,  1304,     6,   228,   308,   460,   865,  1266,
      34,   281,   282,   283,   344,   466,   467,   471,  1243,   818,
     821,  1202,  1202,  1148,  1204,  1206,  1216,  1148,   503,   896,
    1168,  1169,  1168,  1169,   861,   308,   805,    87,   357,   498,
     919,  1150,   818,  1209,   818,   498,   947,   948,   949,   950,
    1292,   498,  1199,  1198,    49,   969,   964,   188,   969,  1047,
    1267,  1269,   314,  1168,   985,   262,   287,   997,  1192,   217,
    1002,  1298,   818,   291,  1141,   262,  1150,  1149,  1026,  1155,
    1209,  1156,  1157,  1158,  1159,  1162,  1066,  1192,  1066,   461,
    1135,  1136,   330,  1241,  1168,   813,  1199,   313,  1198,   113,
    1099,   436,  1101,   157,   292,  1124,  1142,  1143,  1144,  1145,
     321,  1176,  1202,   720,  1181,   748,   252,   254,  1307,   504,
     687,  1209,   270,   329,   458,   463,   789,   790,   791,  1200,
     789,   790,   792,   810,    47,    32,    35,    38,    46,    91,
     110,   189,   198,   211,   243,   263,   265,   287,   288,   318,
     345,   371,   378,   391,   395,   444,   473,   483,   489,   836,
     837,   838,  1126,   818,  1132,   818,   294,   867,   818,  1277,
    1209,   252,   254,  1312,   898,  1132,   361,  1132,   361,  1192,
     948,   102,  1257,  1294,   969,   969,  1199,     8,    37,   970,
     225,   497,  1052,  1182,  1049,  1132,   380,    49,   262,   237,
    1003,   216,   236,   262,   287,   500,   818,   818,   818,   818,
     296,  1137,  1267,  1132,  1132,   492,   814,  1103,  1096,  1262,
      95,  1100,  1262,  1135,   818,   818,  1144,   252,   254,  1271,
     177,   187,   210,   240,   749,   750,   751,   752,   753,   754,
    1218,   757,  1202,  1202,   129,  1267,  1267,   838,    56,   123,
     482,     8,  1247,   837,   818,  1209,  1169,  1169,    49,   110,
     969,   456,  1265,  1265,   337,  1172,   203,   317,  1053,  1213,
    1192,  1267,  1004,  1139,  1140,  1141,  1145,   262,   262,   262,
     818,  1209,  1104,   451,  1209,  1262,  1209,   106,   116,  1316,
    1267,  1267,    54,    89,  1316,  1317,  1301,   758,   109,  1202,
    1202,  1267,  1148,  1148,  1203,  1206,  1218,  1132,  1132,  1192,
    1192,  1192,  1267,  1172,   337,   481,  1209,  1141,   127,   166,
     204,  1105,  1106,  1107,  1109,  1113,  1115,  1116,  1117,  1251,
    1260,  1209,  1267,  1218,  1218,   210,  1267,  1267,   209,   252,
     254,   285,   305,   333,   414,   431,   451,   472,   491,   499,
     704,   709,   710,   721,   723,   725,   759,   760,   764,   765,
     768,   769,   770,   771,   772,   773,   778,   779,   780,  1300,
    1301,   451,  1200,   992,  1267,  1149,    37,  1247,   340,   107,
    1218,  1218,  1218,   221,  1264,   299,   300,  1276,  1248,   209,
    1216,   501,  1267,  1277,  1267,  1267,  1209,   286,   329,   774,
     775,  1218,   329,   776,   777,  1218,  1276,  1248,   992,   367,
     418,  1289,   129,   421,  1114,  1278,  1268,  1267,   713,  1149,
    1195,  1193,  1195,    53,    89,   321,   325,   326,   366,   382,
     383,   761,  1316,  1317,  1318,  1319,  1320,  1321,  1322,   119,
     196,  1216,   775,  1216,   777,  1268,  1209,   161,   165,  1303,
       9,  1110,  1111,  1179,   775,  1293,  1241,   373,   766,  1195,
     187,   187,   210,   187,   210,   176,   762,  1209,   762,  1195,
     337,  1281,   306,   338,   358,  1112,  1111,   714,  1278,   313,
     763,   763,    49,  1278,   306,  1213,   425,   711,   176,   767,
    1209,   321,  1195,   170,   225,   233,   317,  1108,  1172,  1216
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
#line 1366 "parser.y"
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
#line 1377 "parser.y"
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
#line 1413 "parser.y"
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
#line 1468 "parser.y"
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
#line 1497 "parser.y"
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
#line 1530 "parser.y"
    {
	cb_validate_program_environment (current_program);
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1536 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1548 "parser.y"
    {
	cb_validate_program_data (current_program);
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 1558 "parser.y"
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
#line 1589 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1596 "parser.y"
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
#line 1635 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1636 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1645 "parser.y"
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
#line 1654 "parser.y"
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
#line 1668 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1672 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1682 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1691 "parser.y"
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
#line 1716 "parser.y"
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
#line 1734 "parser.y"
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
#line 1747 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1776 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1783 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1790 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1797 "parser.y"
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
#line 1808 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1812 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1816 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1820 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1834 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1839 "parser.y"
    {
	cobc_in_repository = 0;
  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1847 "parser.y"
    {
	yyerrok;
  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1859 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1863 "parser.y"
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
#line 1884 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1888 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1895 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1900 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1911 "parser.y"
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
#line 1925 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1956 "parser.y"
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
#line 1975 "parser.y"
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
#line 1985 "parser.y"
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
#line 1998 "parser.y"
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
#line 2014 "parser.y"
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
#line 2024 "parser.y"
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
#line 2039 "parser.y"
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
#line 2052 "parser.y"
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
#line 2063 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2069 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2075 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2081 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2087 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2093 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2103 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2107 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2114 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2118 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2122 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2126 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2133 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 2137 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2143 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2144 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2145 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2146 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2147 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2148 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2156 "parser.y"
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
#line 2170 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 2174 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 2182 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 2189 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 2193 "parser.y"
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
#line 2204 "parser.y"
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
#line 2224 "parser.y"
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
#line 2232 "parser.y"
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
#line 2242 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2243 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 2250 "parser.y"
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
#line 2270 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2271 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2276 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2280 "parser.y"
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
#line 2301 "parser.y"
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
#line 2324 "parser.y"
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
#line 2405 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2409 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2418 "parser.y"
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
#line 2437 "parser.y"
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
#line 2453 "parser.y"
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
#line 2471 "parser.y"
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
#line 2489 "parser.y"
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
#line 2506 "parser.y"
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
#line 2523 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2531 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2540 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2555 "parser.y"
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
#line 2572 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2576 "parser.y"
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
#line 2610 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2616 "parser.y"
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
#line 2626 "parser.y"
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
#line 2639 "parser.y"
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
#line 2652 "parser.y"
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
#line 2675 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2682 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2695 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2707 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2714 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2715 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2716 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2724 "parser.y"
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
#line 2751 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2762 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2777 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2785 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2790 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2795 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2804 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2808 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2824 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2829 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2834 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2839 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2850 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2861 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2871 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2878 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2879 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2880 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2887 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2898 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2912 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2919 "parser.y"
    { (yyval) = NULL; }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2920 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2921 "parser.y"
    { (yyval) = NULL; }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2930 "parser.y"
    {
	yyerrok;
  }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2949 "parser.y"
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
#line 2976 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2977 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2978 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2979 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 2986 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2991 "parser.y"
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
#line 3018 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3027 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 3041 "parser.y"
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
#line 3060 "parser.y"
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
#line 3077 "parser.y"
    {
	yyerrok;
  }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3084 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3088 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3099 "parser.y"
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
#line 3109 "parser.y"
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
#line 3139 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 3152 "parser.y"
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
#line 3172 "parser.y"
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
#line 3207 "parser.y"
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
#line 3238 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 3244 "parser.y"
    { (yyval) = NULL; }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 3245 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 3249 "parser.y"
    { (yyval) = NULL; }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 3250 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3258 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3269 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3274 "parser.y"
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
#line 3297 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3309 "parser.y"
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
#line 3337 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 3344 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 3351 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3360 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3372 "parser.y"
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
#line 3424 "parser.y"
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
#line 3444 "parser.y"
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
#line 3454 "parser.y"
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
#line 3494 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 3500 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 3509 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 3512 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 3518 "parser.y"
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
#line 3538 "parser.y"
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
#line 3553 "parser.y"
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
#line 3573 "parser.y"
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
#line 3586 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3593 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 3599 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 3605 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 3614 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 3623 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 3627 "parser.y"
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
#line 3638 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 3639 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 3640 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 3641 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3646 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3650 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3654 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3658 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3662 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 3666 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 3670 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 3674 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 3678 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 3682 "parser.y"
    {
	(yyval) = cb_int (4);
  }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 3686 "parser.y"
    {
	(yyval) = cb_int (8);
  }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 3690 "parser.y"
    {
	(yyval) = cb_int (16);
  }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 3694 "parser.y"
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
#line 3726 "parser.y"
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
#line 3752 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 3756 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 3764 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3770 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 3798 "parser.y"
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
#line 3822 "parser.y"
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
#line 3849 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 3853 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 3862 "parser.y"
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
#line 3887 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 3903 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 3907 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 3911 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 3915 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 3919 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3923 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 3927 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 3931 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 3935 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 3939 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 3943 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 3947 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 3951 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 3956 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 3961 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 3965 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 3969 "parser.y"
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
#line 3977 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 3981 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 3985 "parser.y"
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
#line 3993 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 3997 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 4001 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 4005 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 4009 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 4013 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 4017 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 4021 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 4025 "parser.y"
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
#line 4033 "parser.y"
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
#line 4041 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 4045 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 4049 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 4053 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 4057 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 4061 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 4081 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 4087 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 4100 "parser.y"
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
#line 4118 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 4128 "parser.y"
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
#line 4150 "parser.y"
    { (yyval) = NULL; }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 4151 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 4156 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 4163 "parser.y"
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
#line 4186 "parser.y"
    { (yyval) = NULL; }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 4189 "parser.y"
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
#line 4204 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 4205 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 4210 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 4216 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 4218 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 4223 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 4234 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 4245 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 4256 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 4267 "parser.y"
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
#line 4295 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 4303 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 4304 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 4308 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 4309 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 4314 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 4327 "parser.y"
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
#line 4340 "parser.y"
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
#line 4361 "parser.y"
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
#line 4370 "parser.y"
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
#line 4385 "parser.y"
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
#line 4394 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 4406 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 4412 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 4423 "parser.y"
    {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 4439 "parser.y"
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
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 4466 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 4477 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 4496 "parser.y"
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
#line 4532 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  }
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 4536 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 4541 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  }
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 4561 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 4568 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 4575 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 4582 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 4589 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 4600 "parser.y"
    {
	check_pic_duplicate = 0;
  }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 4631 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 4657 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 4664 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  }
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 4680 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 4691 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 4703 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 4736 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  }
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 4743 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  }
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 4750 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 4759 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 4766 "parser.y"
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
#line 4792 "parser.y"
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
#line 4823 "parser.y"
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
#line 4849 "parser.y"
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
#line 4872 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 4876 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 4880 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  }
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 4884 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 4888 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 4892 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 4896 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 4900 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 4904 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 4908 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 4912 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 4916 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 4920 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 4924 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 4928 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 4932 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  }
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 4936 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 4941 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 619:

/* Line 1806 of yacc.c  */
#line 4945 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 4949 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 4954 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 4959 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 4964 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 4977 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 4984 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 4989 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 5008 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 5012 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 5016 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 5023 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 5027 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 5031 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 5039 "parser.y"
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
#line 5050 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 5059 "parser.y"
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
#line 5069 "parser.y"
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
#line 5081 "parser.y"
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
#line 5096 "parser.y"
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
#line 5129 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 5133 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 5138 "parser.y"
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
#line 5146 "parser.y"
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
#line 5155 "parser.y"
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
#line 5165 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 5167 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 5172 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 5181 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 5185 "parser.y"
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
#line 5197 "parser.y"
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
#line 5205 "parser.y"
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
#line 5213 "parser.y"
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
#line 5221 "parser.y"
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
#line 5250 "parser.y"
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
#line 5283 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 5292 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 5298 "parser.y"
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
#line 5326 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  }
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 5332 "parser.y"
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
	check_unreached = 0;
  }
    break;

  case 681:

/* Line 1806 of yacc.c  */
#line 5370 "parser.y"
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
#line 5388 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 684:

/* Line 1806 of yacc.c  */
#line 5398 "parser.y"
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
#line 5442 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 5453 "parser.y"
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
#line 5501 "parser.y"
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
#line 5513 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 691:

/* Line 1806 of yacc.c  */
#line 5517 "parser.y"
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
#line 5535 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 693:

/* Line 1806 of yacc.c  */
#line 5540 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 694:

/* Line 1806 of yacc.c  */
#line 5545 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 695:

/* Line 1806 of yacc.c  */
#line 5553 "parser.y"
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
#line 5580 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 697:

/* Line 1806 of yacc.c  */
#line 5584 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 747:

/* Line 1806 of yacc.c  */
#line 5640 "parser.y"
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
#line 5654 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 749:

/* Line 1806 of yacc.c  */
#line 5665 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
	if (cb_accept_update) {
		check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
	}

  }
    break;

  case 751:

/* Line 1806 of yacc.c  */
#line 5679 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 752:

/* Line 1806 of yacc.c  */
#line 5684 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 753:

/* Line 1806 of yacc.c  */
#line 5688 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 754:

/* Line 1806 of yacc.c  */
#line 5692 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 755:

/* Line 1806 of yacc.c  */
#line 5697 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 756:

/* Line 1806 of yacc.c  */
#line 5702 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 757:

/* Line 1806 of yacc.c  */
#line 5707 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 758:

/* Line 1806 of yacc.c  */
#line 5712 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 759:

/* Line 1806 of yacc.c  */
#line 5716 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  }
    break;

  case 760:

/* Line 1806 of yacc.c  */
#line 5720 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  }
    break;

  case 761:

/* Line 1806 of yacc.c  */
#line 5724 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 762:

/* Line 1806 of yacc.c  */
#line 5728 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  }
    break;

  case 763:

/* Line 1806 of yacc.c  */
#line 5733 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 764:

/* Line 1806 of yacc.c  */
#line 5737 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 765:

/* Line 1806 of yacc.c  */
#line 5741 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 766:

/* Line 1806 of yacc.c  */
#line 5745 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 767:

/* Line 1806 of yacc.c  */
#line 5749 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 768:

/* Line 1806 of yacc.c  */
#line 5753 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 769:

/* Line 1806 of yacc.c  */
#line 5757 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 771:

/* Line 1806 of yacc.c  */
#line 5765 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 774:

/* Line 1806 of yacc.c  */
#line 5776 "parser.y"
    { (yyval) = NULL; }
    break;

  case 775:

/* Line 1806 of yacc.c  */
#line 5777 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 776:

/* Line 1806 of yacc.c  */
#line 5781 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 777:

/* Line 1806 of yacc.c  */
#line 5782 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 778:

/* Line 1806 of yacc.c  */
#line 5783 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 779:

/* Line 1806 of yacc.c  */
#line 5784 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 780:

/* Line 1806 of yacc.c  */
#line 5785 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 781:

/* Line 1806 of yacc.c  */
#line 5789 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 782:

/* Line 1806 of yacc.c  */
#line 5793 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 783:

/* Line 1806 of yacc.c  */
#line 5794 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 787:

/* Line 1806 of yacc.c  */
#line 5803 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 792:

/* Line 1806 of yacc.c  */
#line 5819 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 793:

/* Line 1806 of yacc.c  */
#line 5823 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 794:

/* Line 1806 of yacc.c  */
#line 5827 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 795:

/* Line 1806 of yacc.c  */
#line 5831 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 796:

/* Line 1806 of yacc.c  */
#line 5835 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 797:

/* Line 1806 of yacc.c  */
#line 5839 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 798:

/* Line 1806 of yacc.c  */
#line 5843 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 799:

/* Line 1806 of yacc.c  */
#line 5847 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 800:

/* Line 1806 of yacc.c  */
#line 5851 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 801:

/* Line 1806 of yacc.c  */
#line 5855 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 802:

/* Line 1806 of yacc.c  */
#line 5859 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 803:

/* Line 1806 of yacc.c  */
#line 5863 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 804:

/* Line 1806 of yacc.c  */
#line 5867 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 805:

/* Line 1806 of yacc.c  */
#line 5871 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 806:

/* Line 1806 of yacc.c  */
#line 5875 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 807:

/* Line 1806 of yacc.c  */
#line 5879 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 808:

/* Line 1806 of yacc.c  */
#line 5883 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 809:

/* Line 1806 of yacc.c  */
#line 5887 "parser.y"
    {
	if (!cb_accept_update) {
		cb_warning ("WITH NO UPDATE/DEFAULT is non-standard");
	} else {
		remove_attrib (COB_SCREEN_UPDATE);
	}
  }
    break;

  case 810:

/* Line 1806 of yacc.c  */
#line 5895 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 811:

/* Line 1806 of yacc.c  */
#line 5899 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 812:

/* Line 1806 of yacc.c  */
#line 5903 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 813:

/* Line 1806 of yacc.c  */
#line 5907 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 814:

/* Line 1806 of yacc.c  */
#line 5911 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 815:

/* Line 1806 of yacc.c  */
#line 5915 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 816:

/* Line 1806 of yacc.c  */
#line 5919 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 819:

/* Line 1806 of yacc.c  */
#line 5931 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 820:

/* Line 1806 of yacc.c  */
#line 5935 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
# if 0 /* activate only for debugging purposes for attribs */
	if (current_statement->attr_ptr) {
		printBits (current_statement->attr_ptr->dispattrs);
	} else {
		fprintf(stderr, "No Attribs\n");
	}
#endif
  }
    break;

  case 821:

/* Line 1806 of yacc.c  */
#line 5952 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  }
    break;

  case 823:

/* Line 1806 of yacc.c  */
#line 5961 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 824:

/* Line 1806 of yacc.c  */
#line 5965 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 825:

/* Line 1806 of yacc.c  */
#line 5969 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 827:

/* Line 1806 of yacc.c  */
#line 5976 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 828:

/* Line 1806 of yacc.c  */
#line 5983 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 829:

/* Line 1806 of yacc.c  */
#line 5987 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 830:

/* Line 1806 of yacc.c  */
#line 5997 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 832:

/* Line 1806 of yacc.c  */
#line 6006 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 833:

/* Line 1806 of yacc.c  */
#line 6010 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 834:

/* Line 1806 of yacc.c  */
#line 6021 "parser.y"
    { (yyval) = NULL; }
    break;

  case 835:

/* Line 1806 of yacc.c  */
#line 6022 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 836:

/* Line 1806 of yacc.c  */
#line 6030 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  }
    break;

  case 840:

/* Line 1806 of yacc.c  */
#line 6044 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 843:

/* Line 1806 of yacc.c  */
#line 6056 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 845:

/* Line 1806 of yacc.c  */
#line 6071 "parser.y"
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

  case 846:

/* Line 1806 of yacc.c  */
#line 6085 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 847:

/* Line 1806 of yacc.c  */
#line 6090 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 848:

/* Line 1806 of yacc.c  */
#line 6095 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 849:

/* Line 1806 of yacc.c  */
#line 6100 "parser.y"
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

  case 850:

/* Line 1806 of yacc.c  */
#line 6120 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 851:

/* Line 1806 of yacc.c  */
#line 6124 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 852:

/* Line 1806 of yacc.c  */
#line 6129 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 853:

/* Line 1806 of yacc.c  */
#line 6140 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 854:

/* Line 1806 of yacc.c  */
#line 6142 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 855:

/* Line 1806 of yacc.c  */
#line 6147 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  }
    break;

  case 856:

/* Line 1806 of yacc.c  */
#line 6155 "parser.y"
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

  case 858:

/* Line 1806 of yacc.c  */
#line 6181 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 859:

/* Line 1806 of yacc.c  */
#line 6185 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 860:

/* Line 1806 of yacc.c  */
#line 6194 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 861:

/* Line 1806 of yacc.c  */
#line 6206 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 862:

/* Line 1806 of yacc.c  */
#line 6210 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 863:

/* Line 1806 of yacc.c  */
#line 6214 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 864:

/* Line 1806 of yacc.c  */
#line 6218 "parser.y"
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

  case 869:

/* Line 1806 of yacc.c  */
#line 6251 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 870:

/* Line 1806 of yacc.c  */
#line 6256 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 871:

/* Line 1806 of yacc.c  */
#line 6263 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 872:

/* Line 1806 of yacc.c  */
#line 6268 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 873:

/* Line 1806 of yacc.c  */
#line 6275 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 874:

/* Line 1806 of yacc.c  */
#line 6279 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 875:

/* Line 1806 of yacc.c  */
#line 6289 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  }
    break;

  case 877:

/* Line 1806 of yacc.c  */
#line 6297 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  }
    break;

  case 878:

/* Line 1806 of yacc.c  */
#line 6301 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 879:

/* Line 1806 of yacc.c  */
#line 6311 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  }
    break;

  case 881:

/* Line 1806 of yacc.c  */
#line 6319 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 882:

/* Line 1806 of yacc.c  */
#line 6324 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 883:

/* Line 1806 of yacc.c  */
#line 6331 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 884:

/* Line 1806 of yacc.c  */
#line 6332 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 885:

/* Line 1806 of yacc.c  */
#line 6333 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 886:

/* Line 1806 of yacc.c  */
#line 6334 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 887:

/* Line 1806 of yacc.c  */
#line 6335 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 888:

/* Line 1806 of yacc.c  */
#line 6343 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 890:

/* Line 1806 of yacc.c  */
#line 6352 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 891:

/* Line 1806 of yacc.c  */
#line 6359 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 892:

/* Line 1806 of yacc.c  */
#line 6363 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 893:

/* Line 1806 of yacc.c  */
#line 6373 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 894:

/* Line 1806 of yacc.c  */
#line 6384 "parser.y"
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

  case 895:

/* Line 1806 of yacc.c  */
#line 6401 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  }
    break;

  case 897:

/* Line 1806 of yacc.c  */
#line 6410 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  }
    break;

  case 899:

/* Line 1806 of yacc.c  */
#line 6418 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  }
    break;

  case 900:

/* Line 1806 of yacc.c  */
#line 6423 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  }
    break;

  case 901:

/* Line 1806 of yacc.c  */
#line 6431 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 902:

/* Line 1806 of yacc.c  */
#line 6435 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 903:

/* Line 1806 of yacc.c  */
#line 6445 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 905:

/* Line 1806 of yacc.c  */
#line 6455 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 906:

/* Line 1806 of yacc.c  */
#line 6459 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 907:

/* Line 1806 of yacc.c  */
#line 6463 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 908:

/* Line 1806 of yacc.c  */
#line 6467 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 909:

/* Line 1806 of yacc.c  */
#line 6471 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 911:

/* Line 1806 of yacc.c  */
#line 6476 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 913:

/* Line 1806 of yacc.c  */
#line 6486 "parser.y"
    {
	begin_implicit_statement ();
  }
    break;

  case 915:

/* Line 1806 of yacc.c  */
#line 6494 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 916:

/* Line 1806 of yacc.c  */
#line 6502 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 917:

/* Line 1806 of yacc.c  */
#line 6510 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  }
    break;

  case 918:

/* Line 1806 of yacc.c  */
#line 6514 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  }
    break;

  case 919:

/* Line 1806 of yacc.c  */
#line 6518 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 920:

/* Line 1806 of yacc.c  */
#line 6522 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 926:

/* Line 1806 of yacc.c  */
#line 6544 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 927:

/* Line 1806 of yacc.c  */
#line 6550 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 928:

/* Line 1806 of yacc.c  */
#line 6551 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 931:

/* Line 1806 of yacc.c  */
#line 6562 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 932:

/* Line 1806 of yacc.c  */
#line 6566 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 933:

/* Line 1806 of yacc.c  */
#line 6570 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 934:

/* Line 1806 of yacc.c  */
#line 6574 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 935:

/* Line 1806 of yacc.c  */
#line 6578 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  }
    break;

  case 936:

/* Line 1806 of yacc.c  */
#line 6582 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 937:

/* Line 1806 of yacc.c  */
#line 6586 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 938:

/* Line 1806 of yacc.c  */
#line 6590 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 939:

/* Line 1806 of yacc.c  */
#line 6594 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 940:

/* Line 1806 of yacc.c  */
#line 6598 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 941:

/* Line 1806 of yacc.c  */
#line 6602 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 942:

/* Line 1806 of yacc.c  */
#line 6606 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 943:

/* Line 1806 of yacc.c  */
#line 6610 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 944:

/* Line 1806 of yacc.c  */
#line 6614 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 945:

/* Line 1806 of yacc.c  */
#line 6618 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 946:

/* Line 1806 of yacc.c  */
#line 6622 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 947:

/* Line 1806 of yacc.c  */
#line 6629 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 948:

/* Line 1806 of yacc.c  */
#line 6633 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 949:

/* Line 1806 of yacc.c  */
#line 6643 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 951:

/* Line 1806 of yacc.c  */
#line 6652 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 952:

/* Line 1806 of yacc.c  */
#line 6656 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 953:

/* Line 1806 of yacc.c  */
#line 6660 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 954:

/* Line 1806 of yacc.c  */
#line 6664 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 955:

/* Line 1806 of yacc.c  */
#line 6668 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 956:

/* Line 1806 of yacc.c  */
#line 6675 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 957:

/* Line 1806 of yacc.c  */
#line 6679 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 958:

/* Line 1806 of yacc.c  */
#line 6689 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  }
    break;

  case 960:

/* Line 1806 of yacc.c  */
#line 6697 "parser.y"
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

  case 961:

/* Line 1806 of yacc.c  */
#line 6716 "parser.y"
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

  case 963:

/* Line 1806 of yacc.c  */
#line 6740 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 964:

/* Line 1806 of yacc.c  */
#line 6747 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 965:

/* Line 1806 of yacc.c  */
#line 6749 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 966:

/* Line 1806 of yacc.c  */
#line 6754 "parser.y"
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

  case 967:

/* Line 1806 of yacc.c  */
#line 6765 "parser.y"
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

  case 968:

/* Line 1806 of yacc.c  */
#line 6776 "parser.y"
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

  case 969:

/* Line 1806 of yacc.c  */
#line 6790 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 970:

/* Line 1806 of yacc.c  */
#line 6794 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 971:

/* Line 1806 of yacc.c  */
#line 6800 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 972:

/* Line 1806 of yacc.c  */
#line 6802 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 973:

/* Line 1806 of yacc.c  */
#line 6808 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 974:

/* Line 1806 of yacc.c  */
#line 6817 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 975:

/* Line 1806 of yacc.c  */
#line 6825 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 976:

/* Line 1806 of yacc.c  */
#line 6831 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 977:

/* Line 1806 of yacc.c  */
#line 6838 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 978:

/* Line 1806 of yacc.c  */
#line 6840 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 979:

/* Line 1806 of yacc.c  */
#line 6845 "parser.y"
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

  case 980:

/* Line 1806 of yacc.c  */
#line 6906 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 981:

/* Line 1806 of yacc.c  */
#line 6907 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 982:

/* Line 1806 of yacc.c  */
#line 6908 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 983:

/* Line 1806 of yacc.c  */
#line 6912 "parser.y"
    { (yyval) = NULL; }
    break;

  case 984:

/* Line 1806 of yacc.c  */
#line 6913 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 985:

/* Line 1806 of yacc.c  */
#line 6918 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 986:

/* Line 1806 of yacc.c  */
#line 6922 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 987:

/* Line 1806 of yacc.c  */
#line 6932 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 988:

/* Line 1806 of yacc.c  */
#line 6937 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 990:

/* Line 1806 of yacc.c  */
#line 6945 "parser.y"
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

  case 991:

/* Line 1806 of yacc.c  */
#line 6966 "parser.y"
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

  case 992:

/* Line 1806 of yacc.c  */
#line 6980 "parser.y"
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

  case 993:

/* Line 1806 of yacc.c  */
#line 7002 "parser.y"
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

  case 994:

/* Line 1806 of yacc.c  */
#line 7024 "parser.y"
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

  case 995:

/* Line 1806 of yacc.c  */
#line 7044 "parser.y"
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

  case 996:

/* Line 1806 of yacc.c  */
#line 7066 "parser.y"
    { (yyval) = NULL; }
    break;

  case 997:

/* Line 1806 of yacc.c  */
#line 7067 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 998:

/* Line 1806 of yacc.c  */
#line 7075 "parser.y"
    {
	begin_statement ("FREE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 1000:

/* Line 1806 of yacc.c  */
#line 7084 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  }
    break;

  case 1001:

/* Line 1806 of yacc.c  */
#line 7094 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  }
    break;

  case 1004:

/* Line 1806 of yacc.c  */
#line 7110 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1006:

/* Line 1806 of yacc.c  */
#line 7123 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1007:

/* Line 1806 of yacc.c  */
#line 7131 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1008:

/* Line 1806 of yacc.c  */
#line 7136 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1009:

/* Line 1806 of yacc.c  */
#line 7147 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  }
    break;

  case 1010:

/* Line 1806 of yacc.c  */
#line 7162 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  }
    break;

  case 1012:

/* Line 1806 of yacc.c  */
#line 7171 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1013:

/* Line 1806 of yacc.c  */
#line 7175 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7179 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1015:

/* Line 1806 of yacc.c  */
#line 7186 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1016:

/* Line 1806 of yacc.c  */
#line 7190 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7200 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  }
    break;

  case 1019:

/* Line 1806 of yacc.c  */
#line 7209 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7215 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7216 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7220 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7221 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7222 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1025:

/* Line 1806 of yacc.c  */
#line 7227 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7231 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7238 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7243 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7250 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7256 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7257 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1032:

/* Line 1806 of yacc.c  */
#line 7258 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7259 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7260 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1035:

/* Line 1806 of yacc.c  */
#line 7261 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7262 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1037:

/* Line 1806 of yacc.c  */
#line 7267 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7271 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1039:

/* Line 1806 of yacc.c  */
#line 7280 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1041:

/* Line 1806 of yacc.c  */
#line 7289 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1042:

/* Line 1806 of yacc.c  */
#line 7295 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7306 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1046:

/* Line 1806 of yacc.c  */
#line 7319 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1047:

/* Line 1806 of yacc.c  */
#line 7323 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1048:

/* Line 1806 of yacc.c  */
#line 7327 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1053:

/* Line 1806 of yacc.c  */
#line 7343 "parser.y"
    {
	cb_init_tallying ();
  }
    break;

  case 1054:

/* Line 1806 of yacc.c  */
#line 7347 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7357 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1056:

/* Line 1806 of yacc.c  */
#line 7367 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1057:

/* Line 1806 of yacc.c  */
#line 7375 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1058:

/* Line 1806 of yacc.c  */
#line 7376 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1059:

/* Line 1806 of yacc.c  */
#line 7380 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7381 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7382 "parser.y"
    { (yyval) = cb_build_tallying_all (); }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7383 "parser.y"
    { (yyval) = cb_build_tallying_leading (); }
    break;

  case 1063:

/* Line 1806 of yacc.c  */
#line 7384 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); }
    break;

  case 1064:

/* Line 1806 of yacc.c  */
#line 7385 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1065:

/* Line 1806 of yacc.c  */
#line 7389 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1066:

/* Line 1806 of yacc.c  */
#line 7390 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7395 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7400 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7406 "parser.y"
    { /* Nothing */ }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7407 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
#line 7408 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1072:

/* Line 1806 of yacc.c  */
#line 7409 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7410 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7415 "parser.y"
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

  case 1075:

/* Line 1806 of yacc.c  */
#line 7442 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  }
    break;

  case 1076:

/* Line 1806 of yacc.c  */
#line 7446 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1077:

/* Line 1806 of yacc.c  */
#line 7453 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7457 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1079:

/* Line 1806 of yacc.c  */
#line 7466 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1081:

/* Line 1806 of yacc.c  */
#line 7478 "parser.y"
    {
	begin_statement ("MOVE", 0);
  }
    break;

  case 1083:

/* Line 1806 of yacc.c  */
#line 7486 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7490 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7500 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1087:

/* Line 1806 of yacc.c  */
#line 7509 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7513 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1089:

/* Line 1806 of yacc.c  */
#line 7520 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7524 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1091:

/* Line 1806 of yacc.c  */
#line 7534 "parser.y"
    {
	begin_statement ("OPEN", 0);
  }
    break;

  case 1093:

/* Line 1806 of yacc.c  */
#line 7542 "parser.y"
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

  case 1094:

/* Line 1806 of yacc.c  */
#line 7563 "parser.y"
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

  case 1095:

/* Line 1806 of yacc.c  */
#line 7586 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 1096:

/* Line 1806 of yacc.c  */
#line 7587 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7588 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7589 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 1099:

/* Line 1806 of yacc.c  */
#line 7593 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1100:

/* Line 1806 of yacc.c  */
#line 7594 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1101:

/* Line 1806 of yacc.c  */
#line 7598 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1102:

/* Line 1806 of yacc.c  */
#line 7599 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1103:

/* Line 1806 of yacc.c  */
#line 7600 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7602 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7613 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7624 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1108:

/* Line 1806 of yacc.c  */
#line 7629 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1109:

/* Line 1806 of yacc.c  */
#line 7635 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1110:

/* Line 1806 of yacc.c  */
#line 7640 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
#line 7648 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1112:

/* Line 1806 of yacc.c  */
#line 7656 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
#line 7663 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1114:

/* Line 1806 of yacc.c  */
#line 7667 "parser.y"
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

  case 1115:

/* Line 1806 of yacc.c  */
#line 7680 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1116:

/* Line 1806 of yacc.c  */
#line 7687 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
#line 7698 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 1118:

/* Line 1806 of yacc.c  */
#line 7702 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1119:

/* Line 1806 of yacc.c  */
#line 7707 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 1120:

/* Line 1806 of yacc.c  */
#line 7711 "parser.y"
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

  case 1121:

/* Line 1806 of yacc.c  */
#line 7722 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7728 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7729 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7733 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1125:

/* Line 1806 of yacc.c  */
#line 7734 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7737 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1127:

/* Line 1806 of yacc.c  */
#line 7739 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
#line 7744 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1129:

/* Line 1806 of yacc.c  */
#line 7754 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  }
    break;

  case 1131:

/* Line 1806 of yacc.c  */
#line 7763 "parser.y"
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

  case 1132:

/* Line 1806 of yacc.c  */
#line 7789 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7790 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1134:

/* Line 1806 of yacc.c  */
#line 7795 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1135:

/* Line 1806 of yacc.c  */
#line 7799 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1136:

/* Line 1806 of yacc.c  */
#line 7803 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7807 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1138:

/* Line 1806 of yacc.c  */
#line 7811 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1139:

/* Line 1806 of yacc.c  */
#line 7815 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1140:

/* Line 1806 of yacc.c  */
#line 7819 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1141:

/* Line 1806 of yacc.c  */
#line 7825 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1142:

/* Line 1806 of yacc.c  */
#line 7826 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7836 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1146:

/* Line 1806 of yacc.c  */
#line 7840 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1147:

/* Line 1806 of yacc.c  */
#line 7850 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  }
    break;

  case 1148:

/* Line 1806 of yacc.c  */
#line 7860 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  }
    break;

  case 1150:

/* Line 1806 of yacc.c  */
#line 7868 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 7878 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 7888 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  }
    break;

  case 1154:

/* Line 1806 of yacc.c  */
#line 7897 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1155:

/* Line 1806 of yacc.c  */
#line 7904 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 7908 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1157:

/* Line 1806 of yacc.c  */
#line 7918 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1159:

/* Line 1806 of yacc.c  */
#line 7930 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 7938 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 7942 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1162:

/* Line 1806 of yacc.c  */
#line 7946 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1163:

/* Line 1806 of yacc.c  */
#line 7953 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1164:

/* Line 1806 of yacc.c  */
#line 7957 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 7967 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 7978 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  }
    break;

  case 1168:

/* Line 1806 of yacc.c  */
#line 7987 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 7992 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 7999 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1171:

/* Line 1806 of yacc.c  */
#line 8000 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1172:

/* Line 1806 of yacc.c  */
#line 8005 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 8010 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 8017 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 8021 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1176:

/* Line 1806 of yacc.c  */
#line 8029 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1177:

/* Line 1806 of yacc.c  */
#line 8036 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1178:

/* Line 1806 of yacc.c  */
#line 8040 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1179:

/* Line 1806 of yacc.c  */
#line 8050 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1180:

/* Line 1806 of yacc.c  */
#line 8057 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1187:

/* Line 1806 of yacc.c  */
#line 8072 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1188:

/* Line 1806 of yacc.c  */
#line 8073 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1189:

/* Line 1806 of yacc.c  */
#line 8077 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1190:

/* Line 1806 of yacc.c  */
#line 8078 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1191:

/* Line 1806 of yacc.c  */
#line 8085 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1192:

/* Line 1806 of yacc.c  */
#line 8094 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1195:

/* Line 1806 of yacc.c  */
#line 8106 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1196:

/* Line 1806 of yacc.c  */
#line 8110 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1197:

/* Line 1806 of yacc.c  */
#line 8114 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1198:

/* Line 1806 of yacc.c  */
#line 8118 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1199:

/* Line 1806 of yacc.c  */
#line 8122 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1200:

/* Line 1806 of yacc.c  */
#line 8126 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1201:

/* Line 1806 of yacc.c  */
#line 8130 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1202:

/* Line 1806 of yacc.c  */
#line 8134 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1203:

/* Line 1806 of yacc.c  */
#line 8143 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1204:

/* Line 1806 of yacc.c  */
#line 8147 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1205:

/* Line 1806 of yacc.c  */
#line 8156 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1208:

/* Line 1806 of yacc.c  */
#line 8170 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1211:

/* Line 1806 of yacc.c  */
#line 8184 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
#line 8188 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1213:

/* Line 1806 of yacc.c  */
#line 8198 "parser.y"
    {
	begin_statement ("SORT", 0);
  }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
#line 8206 "parser.y"
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

  case 1216:

/* Line 1806 of yacc.c  */
#line 8227 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1217:

/* Line 1806 of yacc.c  */
#line 8236 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1218:

/* Line 1806 of yacc.c  */
#line 8241 "parser.y"
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

  case 1219:

/* Line 1806 of yacc.c  */
#line 8259 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1220:

/* Line 1806 of yacc.c  */
#line 8260 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8265 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1223:

/* Line 1806 of yacc.c  */
#line 8272 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1224:

/* Line 1806 of yacc.c  */
#line 8273 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1225:

/* Line 1806 of yacc.c  */
#line 8278 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1226:

/* Line 1806 of yacc.c  */
#line 8284 "parser.y"
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

  case 1227:

/* Line 1806 of yacc.c  */
#line 8294 "parser.y"
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

  case 1228:

/* Line 1806 of yacc.c  */
#line 8309 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1229:

/* Line 1806 of yacc.c  */
#line 8315 "parser.y"
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

  case 1230:

/* Line 1806 of yacc.c  */
#line 8325 "parser.y"
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

  case 1231:

/* Line 1806 of yacc.c  */
#line 8341 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  }
    break;

  case 1233:

/* Line 1806 of yacc.c  */
#line 8351 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1234:

/* Line 1806 of yacc.c  */
#line 8363 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1235:

/* Line 1806 of yacc.c  */
#line 8367 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1236:

/* Line 1806 of yacc.c  */
#line 8374 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1237:

/* Line 1806 of yacc.c  */
#line 8378 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1238:

/* Line 1806 of yacc.c  */
#line 8383 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8388 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1240:

/* Line 1806 of yacc.c  */
#line 8395 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1241:

/* Line 1806 of yacc.c  */
#line 8396 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1242:

/* Line 1806 of yacc.c  */
#line 8397 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1243:

/* Line 1806 of yacc.c  */
#line 8398 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1244:

/* Line 1806 of yacc.c  */
#line 8399 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1245:

/* Line 1806 of yacc.c  */
#line 8400 "parser.y"
    { (yyval) = cb_int (COB_NE); }
    break;

  case 1246:

/* Line 1806 of yacc.c  */
#line 8405 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8418 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
#line 8422 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1251:

/* Line 1806 of yacc.c  */
#line 8432 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  }
    break;

  case 1252:

/* Line 1806 of yacc.c  */
#line 8436 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
#line 8442 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
    break;

  case 1254:

/* Line 1806 of yacc.c  */
#line 8454 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1255:

/* Line 1806 of yacc.c  */
#line 8458 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8462 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1257:

/* Line 1806 of yacc.c  */
#line 8470 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1258:

/* Line 1806 of yacc.c  */
#line 8481 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8485 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8491 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1261:

/* Line 1806 of yacc.c  */
#line 8492 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1262:

/* Line 1806 of yacc.c  */
#line 8493 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8494 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8501 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8510 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8516 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8517 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1269:

/* Line 1806 of yacc.c  */
#line 8521 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8522 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8523 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8527 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1273:

/* Line 1806 of yacc.c  */
#line 8528 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1274:

/* Line 1806 of yacc.c  */
#line 8533 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1275:

/* Line 1806 of yacc.c  */
#line 8537 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8547 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8556 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8560 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1280:

/* Line 1806 of yacc.c  */
#line 8564 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1281:

/* Line 1806 of yacc.c  */
#line 8571 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1282:

/* Line 1806 of yacc.c  */
#line 8575 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1283:

/* Line 1806 of yacc.c  */
#line 8585 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8603 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1288:

/* Line 1806 of yacc.c  */
#line 8612 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1289:

/* Line 1806 of yacc.c  */
#line 8618 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1290:

/* Line 1806 of yacc.c  */
#line 8629 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  }
    break;

  case 1292:

/* Line 1806 of yacc.c  */
#line 8637 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1293:

/* Line 1806 of yacc.c  */
#line 8650 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  }
    break;

  case 1295:

/* Line 1806 of yacc.c  */
#line 8658 "parser.y"
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

  case 1299:

/* Line 1806 of yacc.c  */
#line 8681 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1301:

/* Line 1806 of yacc.c  */
#line 8691 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1302:

/* Line 1806 of yacc.c  */
#line 8697 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1303:

/* Line 1806 of yacc.c  */
#line 8699 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1304:

/* Line 1806 of yacc.c  */
#line 8703 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8705 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1306:

/* Line 1806 of yacc.c  */
#line 8710 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1307:

/* Line 1806 of yacc.c  */
#line 8716 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); }
    break;

  case 1308:

/* Line 1806 of yacc.c  */
#line 8718 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1309:

/* Line 1806 of yacc.c  */
#line 8723 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1310:

/* Line 1806 of yacc.c  */
#line 8729 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1311:

/* Line 1806 of yacc.c  */
#line 8730 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1312:

/* Line 1806 of yacc.c  */
#line 8734 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1313:

/* Line 1806 of yacc.c  */
#line 8735 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1314:

/* Line 1806 of yacc.c  */
#line 8739 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1315:

/* Line 1806 of yacc.c  */
#line 8740 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1316:

/* Line 1806 of yacc.c  */
#line 8745 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1317:

/* Line 1806 of yacc.c  */
#line 8749 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1318:

/* Line 1806 of yacc.c  */
#line 8759 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1325:

/* Line 1806 of yacc.c  */
#line 8777 "parser.y"
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

  case 1326:

/* Line 1806 of yacc.c  */
#line 8802 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1327:

/* Line 1806 of yacc.c  */
#line 8806 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1328:

/* Line 1806 of yacc.c  */
#line 8818 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1329:

/* Line 1806 of yacc.c  */
#line 8828 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1330:

/* Line 1806 of yacc.c  */
#line 8833 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1331:

/* Line 1806 of yacc.c  */
#line 8838 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1332:

/* Line 1806 of yacc.c  */
#line 8843 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1333:

/* Line 1806 of yacc.c  */
#line 8851 "parser.y"
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

  case 1336:

/* Line 1806 of yacc.c  */
#line 8894 "parser.y"
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

  case 1337:

/* Line 1806 of yacc.c  */
#line 8934 "parser.y"
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

  case 1338:

/* Line 1806 of yacc.c  */
#line 8944 "parser.y"
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

  case 1343:

/* Line 1806 of yacc.c  */
#line 8974 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("USE AT is invalid in nested program"));
	}
  }
    break;

  case 1344:

/* Line 1806 of yacc.c  */
#line 8983 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM START"));
	/* emit_entry ("_START", 0, NULL); */
	PENDING ("USE AT PROGRAM START");
  }
    break;

  case 1345:

/* Line 1806 of yacc.c  */
#line 8989 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM END"));
	/* emit_entry ("_END", 0, NULL); */
	PENDING ("USE AT PROGRAM END");
  }
    break;

  case 1346:

/* Line 1806 of yacc.c  */
#line 8999 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1347:

/* Line 1806 of yacc.c  */
#line 9008 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1350:

/* Line 1806 of yacc.c  */
#line 9024 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1352:

/* Line 1806 of yacc.c  */
#line 9036 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1353:

/* Line 1806 of yacc.c  */
#line 9045 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1354:

/* Line 1806 of yacc.c  */
#line 9046 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1355:

/* Line 1806 of yacc.c  */
#line 9051 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1356:

/* Line 1806 of yacc.c  */
#line 9055 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1357:

/* Line 1806 of yacc.c  */
#line 9059 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1358:

/* Line 1806 of yacc.c  */
#line 9063 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1359:

/* Line 1806 of yacc.c  */
#line 9069 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1360:

/* Line 1806 of yacc.c  */
#line 9070 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1363:

/* Line 1806 of yacc.c  */
#line 9080 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1364:

/* Line 1806 of yacc.c  */
#line 9084 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1367:

/* Line 1806 of yacc.c  */
#line 9101 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1369:

/* Line 1806 of yacc.c  */
#line 9111 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1372:

/* Line 1806 of yacc.c  */
#line 9124 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1374:

/* Line 1806 of yacc.c  */
#line 9134 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1377:

/* Line 1806 of yacc.c  */
#line 9149 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1379:

/* Line 1806 of yacc.c  */
#line 9159 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1382:

/* Line 1806 of yacc.c  */
#line 9176 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1384:

/* Line 1806 of yacc.c  */
#line 9187 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1390:

/* Line 1806 of yacc.c  */
#line 9210 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1391:

/* Line 1806 of yacc.c  */
#line 9219 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1395:

/* Line 1806 of yacc.c  */
#line 9236 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1396:

/* Line 1806 of yacc.c  */
#line 9245 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1399:

/* Line 1806 of yacc.c  */
#line 9262 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1401:

/* Line 1806 of yacc.c  */
#line 9272 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1402:

/* Line 1806 of yacc.c  */
#line 9282 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1403:

/* Line 1806 of yacc.c  */
#line 9286 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1404:

/* Line 1806 of yacc.c  */
#line 9296 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1405:

/* Line 1806 of yacc.c  */
#line 9303 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9309 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1407:

/* Line 1806 of yacc.c  */
#line 9313 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1411:

/* Line 1806 of yacc.c  */
#line 9326 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1412:

/* Line 1806 of yacc.c  */
#line 9334 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1413:

/* Line 1806 of yacc.c  */
#line 9335 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1414:

/* Line 1806 of yacc.c  */
#line 9337 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9338 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9339 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9340 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1418:

/* Line 1806 of yacc.c  */
#line 9341 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1419:

/* Line 1806 of yacc.c  */
#line 9343 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1420:

/* Line 1806 of yacc.c  */
#line 9344 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1421:

/* Line 1806 of yacc.c  */
#line 9345 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9346 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9347 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9348 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9350 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9351 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1427:

/* Line 1806 of yacc.c  */
#line 9352 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1428:

/* Line 1806 of yacc.c  */
#line 9354 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1429:

/* Line 1806 of yacc.c  */
#line 9355 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1430:

/* Line 1806 of yacc.c  */
#line 9356 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1431:

/* Line 1806 of yacc.c  */
#line 9357 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1432:

/* Line 1806 of yacc.c  */
#line 9358 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1433:

/* Line 1806 of yacc.c  */
#line 9361 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1434:

/* Line 1806 of yacc.c  */
#line 9362 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1443:

/* Line 1806 of yacc.c  */
#line 9392 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1444:

/* Line 1806 of yacc.c  */
#line 9396 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1448:

/* Line 1806 of yacc.c  */
#line 9407 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1449:

/* Line 1806 of yacc.c  */
#line 9408 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1450:

/* Line 1806 of yacc.c  */
#line 9409 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1451:

/* Line 1806 of yacc.c  */
#line 9413 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1452:

/* Line 1806 of yacc.c  */
#line 9414 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1453:

/* Line 1806 of yacc.c  */
#line 9415 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9420 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1455:

/* Line 1806 of yacc.c  */
#line 9423 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1456:

/* Line 1806 of yacc.c  */
#line 9427 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1457:

/* Line 1806 of yacc.c  */
#line 9428 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1458:

/* Line 1806 of yacc.c  */
#line 9429 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1459:

/* Line 1806 of yacc.c  */
#line 9432 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1460:

/* Line 1806 of yacc.c  */
#line 9433 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9444 "parser.y"
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

  case 1462:

/* Line 1806 of yacc.c  */
#line 9456 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9465 "parser.y"
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

  case 1464:

/* Line 1806 of yacc.c  */
#line 9477 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1465:

/* Line 1806 of yacc.c  */
#line 9486 "parser.y"
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

  case 1466:

/* Line 1806 of yacc.c  */
#line 9498 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1467:

/* Line 1806 of yacc.c  */
#line 9512 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1468:

/* Line 1806 of yacc.c  */
#line 9514 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1469:

/* Line 1806 of yacc.c  */
#line 9519 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1470:

/* Line 1806 of yacc.c  */
#line 9527 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9534 "parser.y"
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

  case 1472:

/* Line 1806 of yacc.c  */
#line 9554 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1473:

/* Line 1806 of yacc.c  */
#line 9558 "parser.y"
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

  case 1474:

/* Line 1806 of yacc.c  */
#line 9579 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1475:

/* Line 1806 of yacc.c  */
#line 9620 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1476:

/* Line 1806 of yacc.c  */
#line 9633 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1477:

/* Line 1806 of yacc.c  */
#line 9635 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1478:

/* Line 1806 of yacc.c  */
#line 9639 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9645 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9647 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9652 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  }
    break;

  case 1484:

/* Line 1806 of yacc.c  */
#line 9666 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1485:

/* Line 1806 of yacc.c  */
#line 9673 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1486:

/* Line 1806 of yacc.c  */
#line 9683 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); }
    break;

  case 1487:

/* Line 1806 of yacc.c  */
#line 9684 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9689 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1489:

/* Line 1806 of yacc.c  */
#line 9697 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1490:

/* Line 1806 of yacc.c  */
#line 9705 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1491:

/* Line 1806 of yacc.c  */
#line 9709 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1492:

/* Line 1806 of yacc.c  */
#line 9716 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9732 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1496:

/* Line 1806 of yacc.c  */
#line 9746 "parser.y"
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

  case 1497:

/* Line 1806 of yacc.c  */
#line 9763 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1498:

/* Line 1806 of yacc.c  */
#line 9767 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9776 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1502:

/* Line 1806 of yacc.c  */
#line 9783 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9787 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1508:

/* Line 1806 of yacc.c  */
#line 9798 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1509:

/* Line 1806 of yacc.c  */
#line 9802 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1510:

/* Line 1806 of yacc.c  */
#line 9806 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1511:

/* Line 1806 of yacc.c  */
#line 9810 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  }
    break;

  case 1512:

/* Line 1806 of yacc.c  */
#line 9814 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  }
    break;

  case 1513:

/* Line 1806 of yacc.c  */
#line 9818 "parser.y"
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

  case 1514:

/* Line 1806 of yacc.c  */
#line 9839 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  }
    break;

  case 1515:

/* Line 1806 of yacc.c  */
#line 9843 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1523:

/* Line 1806 of yacc.c  */
#line 9860 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1524:

/* Line 1806 of yacc.c  */
#line 9864 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1525:

/* Line 1806 of yacc.c  */
#line 9868 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  }
    break;

  case 1541:

/* Line 1806 of yacc.c  */
#line 9915 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1549:

/* Line 1806 of yacc.c  */
#line 9939 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1550:

/* Line 1806 of yacc.c  */
#line 9943 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); }
    break;

  case 1551:

/* Line 1806 of yacc.c  */
#line 9947 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1552:

/* Line 1806 of yacc.c  */
#line 9948 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1553:

/* Line 1806 of yacc.c  */
#line 9952 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); }
    break;

  case 1554:

/* Line 1806 of yacc.c  */
#line 9957 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1555:

/* Line 1806 of yacc.c  */
#line 9964 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1556:

/* Line 1806 of yacc.c  */
#line 9971 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1557:

/* Line 1806 of yacc.c  */
#line 9978 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1558:

/* Line 1806 of yacc.c  */
#line 9988 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1559:

/* Line 1806 of yacc.c  */
#line 9995 "parser.y"
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

  case 1560:

/* Line 1806 of yacc.c  */
#line 10005 "parser.y"
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

  case 1561:

/* Line 1806 of yacc.c  */
#line 10015 "parser.y"
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

/* Line 1806 of yacc.c  */
#line 10025 "parser.y"
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

  case 1563:

/* Line 1806 of yacc.c  */
#line 10038 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1564:

/* Line 1806 of yacc.c  */
#line 10042 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1565:

/* Line 1806 of yacc.c  */
#line 10050 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1566:

/* Line 1806 of yacc.c  */
#line 10058 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1567:

/* Line 1806 of yacc.c  */
#line 10062 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1568:

/* Line 1806 of yacc.c  */
#line 10072 "parser.y"
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

  case 1569:

/* Line 1806 of yacc.c  */
#line 10087 "parser.y"
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

  case 1570:

/* Line 1806 of yacc.c  */
#line 10110 "parser.y"
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

  case 1571:

/* Line 1806 of yacc.c  */
#line 10133 "parser.y"
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

  case 1572:

/* Line 1806 of yacc.c  */
#line 10148 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1573:

/* Line 1806 of yacc.c  */
#line 10149 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1574:

/* Line 1806 of yacc.c  */
#line 10150 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1575:

/* Line 1806 of yacc.c  */
#line 10151 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1576:

/* Line 1806 of yacc.c  */
#line 10152 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1577:

/* Line 1806 of yacc.c  */
#line 10153 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 10158 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 10162 "parser.y"
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

  case 1580:

/* Line 1806 of yacc.c  */
#line 10179 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1581:

/* Line 1806 of yacc.c  */
#line 10183 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1582:

/* Line 1806 of yacc.c  */
#line 10189 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1583:

/* Line 1806 of yacc.c  */
#line 10190 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1584:

/* Line 1806 of yacc.c  */
#line 10191 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1585:

/* Line 1806 of yacc.c  */
#line 10192 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 10193 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 10194 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 10195 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10202 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10206 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1591:

/* Line 1806 of yacc.c  */
#line 10210 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1592:

/* Line 1806 of yacc.c  */
#line 10214 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1593:

/* Line 1806 of yacc.c  */
#line 10218 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1594:

/* Line 1806 of yacc.c  */
#line 10222 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1595:

/* Line 1806 of yacc.c  */
#line 10226 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1596:

/* Line 1806 of yacc.c  */
#line 10230 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1597:

/* Line 1806 of yacc.c  */
#line 10234 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1598:

/* Line 1806 of yacc.c  */
#line 10238 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1607:

/* Line 1806 of yacc.c  */
#line 10262 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1608:

/* Line 1806 of yacc.c  */
#line 10266 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1609:

/* Line 1806 of yacc.c  */
#line 10270 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1610:

/* Line 1806 of yacc.c  */
#line 10277 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1611:

/* Line 1806 of yacc.c  */
#line 10281 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1612:

/* Line 1806 of yacc.c  */
#line 10285 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1613:

/* Line 1806 of yacc.c  */
#line 10292 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1614:

/* Line 1806 of yacc.c  */
#line 10299 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1615:

/* Line 1806 of yacc.c  */
#line 10306 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1616:

/* Line 1806 of yacc.c  */
#line 10316 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1617:

/* Line 1806 of yacc.c  */
#line 10323 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1618:

/* Line 1806 of yacc.c  */
#line 10333 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10340 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10351 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10359 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10360 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10364 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10365 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10369 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10370 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10375 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10379 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10386 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10390 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10397 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10398 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10399 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1634:

/* Line 1806 of yacc.c  */
#line 10403 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10404 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10408 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); }
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10409 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10410 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10415 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10419 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10431 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10436 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10444 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10448 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1645:

/* Line 1806 of yacc.c  */
#line 10452 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1646:

/* Line 1806 of yacc.c  */
#line 10456 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1647:

/* Line 1806 of yacc.c  */
#line 10460 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1648:

/* Line 1806 of yacc.c  */
#line 10464 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1649:

/* Line 1806 of yacc.c  */
#line 10468 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1650:

/* Line 1806 of yacc.c  */
#line 10472 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1651:

/* Line 1806 of yacc.c  */
#line 10478 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1652:

/* Line 1806 of yacc.c  */
#line 10479 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1806 of yacc.c  */
#line 18621 "parser.c"
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
#line 10650 "parser.y"


