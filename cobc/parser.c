/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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

/* Line 189 of yacc.c  */
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
		cobc_free (cobc_glob_line);
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



/* Line 189 of yacc.c  */
#line 795 "parser.c"

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
     TAB = 691,
     TALLYING = 692,
     TAPE = 693,
     TERMINATE = 694,
     TEST = 695,
     THAN = 696,
     THEN = 697,
     THRU = 698,
     TIME = 699,
     TIMEOUT = 700,
     TIMES = 701,
     TO = 702,
     TOK_AMPER = 703,
     TOK_CLOSE_PAREN = 704,
     TOK_COLON = 705,
     TOK_DIV = 706,
     TOK_DOT = 707,
     TOK_EQUAL = 708,
     TOK_FALSE = 709,
     TOK_FILE = 710,
     TOK_GREATER = 711,
     TOK_INITIAL = 712,
     TOK_LESS = 713,
     TOK_MINUS = 714,
     TOK_MUL = 715,
     TOK_NULL = 716,
     TOK_OVERFLOW = 717,
     TOK_OPEN_PAREN = 718,
     TOK_PLUS = 719,
     TOK_TRUE = 720,
     TOP = 721,
     TOWARD_GREATER = 722,
     TOWARD_LESSER = 723,
     TRAILING = 724,
     TRANSFORM = 725,
     TRIM_FUNC = 726,
     TRUNCATION = 727,
     TYPE = 728,
     UNDERLINE = 729,
     UNIT = 730,
     UNLOCK = 731,
     UNSIGNED = 732,
     UNSIGNED_INT = 733,
     UNSIGNED_LONG = 734,
     UNSIGNED_SHORT = 735,
     UNSTRING = 736,
     UNTIL = 737,
     UP = 738,
     UPDATE = 739,
     UPON = 740,
     UPON_ARGUMENT_NUMBER = 741,
     UPON_COMMAND_LINE = 742,
     UPON_ENVIRONMENT_NAME = 743,
     UPON_ENVIRONMENT_VALUE = 744,
     UPPER = 745,
     UPPER_CASE_FUNC = 746,
     USAGE = 747,
     USE = 748,
     USER = 749,
     USER_DEFAULT = 750,
     USER_FUNCTION_NAME = 751,
     USER_REPO_FUNCTION = 752,
     USING = 753,
     VALUE = 754,
     VARYING = 755,
     WAIT = 756,
     WHEN = 757,
     WHEN_COMPILED_FUNC = 758,
     WITH = 759,
     WORD = 760,
     WORDS = 761,
     WORKING_STORAGE = 762,
     WRITE = 763,
     YYYYDDD = 764,
     YYYYMMDD = 765,
     ZERO = 766,
     SHIFT_PREFER = 767
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 1350 "parser.c"

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7607

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  513
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  812
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1890
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2701

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   767

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
     505,   506,   507,   508,   509,   510,   511,   512
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
    2170,  2172,  2174,  2176,  2178,  2183,  2185,  2187,  2189,  2191,
    2193,  2196,  2198,  2200,  2204,  2208,  2212,  2216,  2220,  2222,
    2224,  2225,  2227,  2228,  2233,  2238,  2244,  2251,  2252,  2255,
    2256,  2258,  2259,  2263,  2267,  2272,  2273,  2276,  2277,  2281,
    2283,  2286,  2291,  2292,  2295,  2296,  2301,  2308,  2309,  2311,
    2313,  2315,  2316,  2317,  2321,  2323,  2326,  2329,  2333,  2334,
    2337,  2340,  2343,  2344,  2348,  2351,  2356,  2358,  2360,  2362,
    2364,  2365,  2368,  2369,  2372,  2373,  2375,  2376,  2380,  2382,
    2385,  2386,  2390,  2393,  2397,  2398,  2400,  2404,  2408,  2411,
    2412,  2417,  2422,  2423,  2425,  2427,  2429,  2430,  2435,  2439,
    2442,  2444,  2447,  2448,  2450,  2451,  2456,  2460,  2464,  2468,
    2472,  2477,  2480,  2485,  2487,  2488,  2492,  2498,  2499,  2502,
    2505,  2508,  2511,  2512,  2515,  2517,  2519,  2520,  2523,  2524,
    2526,  2528,  2531,  2533,  2536,  2539,  2541,  2543,  2546,  2549,
    2551,  2553,  2555,  2557,  2559,  2563,  2567,  2571,  2575,  2576,
    2578,  2579,  2584,  2589,  2596,  2603,  2612,  2621,  2622,  2624,
    2625,  2629,  2632,  2633,  2638,  2641,  2643,  2647,  2649,  2651,
    2653,  2656,  2658,  2660,  2663,  2666,  2670,  2673,  2677,  2679,
    2683,  2686,  2688,  2690,  2692,  2693,  2696,  2697,  2699,  2700,
    2704,  2705,  2708,  2710,  2713,  2715,  2717,  2719,  2720,  2723,
    2724,  2728,  2730,  2731,  2735,  2737,  2738,  2742,  2746,  2747,
    2751,  2754,  2755,  2762,  2766,  2769,  2771,  2772,  2774,  2775,
    2779,  2785,  2786,  2789,  2790,  2794,  2798,  2799,  2802,  2804,
    2807,  2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,  2827,
    2831,  2832,  2836,  2838,  2841,  2842,  2846,  2849,  2851,  2853,
    2855,  2858,  2860,  2862,  2864,  2865,  2869,  2872,  2878,  2880,
    2883,  2886,  2889,  2891,  2893,  2895,  2898,  2900,  2903,  2908,
    2911,  2912,  2914,  2916,  2918,  2920,  2925,  2926,  2929,  2933,
    2937,  2938,  2942,  2943,  2947,  2951,  2956,  2957,  2962,  2967,
    2974,  2975,  2977,  2978,  2982,  2987,  2993,  2995,  2997,  2999,
    3001,  3002,  3006,  3007,  3011,  3014,  3016,  3017,  3021,  3024,
    3025,  3030,  3033,  3034,  3036,  3038,  3040,  3042,  3046,  3047,
    3050,  3052,  3056,  3060,  3061,  3065,  3067,  3069,  3071,  3075,
    3083,  3084,  3089,  3097,  3098,  3101,  3102,  3105,  3108,  3112,
    3116,  3120,  3123,  3124,  3128,  3130,  3132,  3133,  3135,  3137,
    3138,  3142,  3145,  3147,  3148,  3153,  3158,  3159,  3161,  3162,
    3167,  3172,  3173,  3176,  3180,  3181,  3183,  3185,  3186,  3191,
    3196,  3203,  3204,  3207,  3208,  3211,  3213,  3216,  3220,  3221,
    3223,  3224,  3228,  3230,  3232,  3234,  3236,  3238,  3240,  3242,
    3244,  3246,  3248,  3253,  3257,  3259,  3262,  3265,  3268,  3271,
    3274,  3277,  3280,  3283,  3286,  3291,  3295,  3300,  3302,  3305,
    3309,  3311,  3314,  3318,  3322,  3323,  3327,  3328,  3336,  3337,
    3343,  3344,  3347,  3348,  3351,  3352,  3356,  3357,  3360,  3365,
    3366,  3369,  3374,  3375,  3380,  3385,  3386,  3390,  3391,  3396,
    3398,  3400,  3402,  3405,  3408,  3411,  3414,  3416,  3418,  3421,
    3423,  3424,  3426,  3427,  3432,  3435,  3436,  3439,  3444,  3449,
    3450,  3452,  3454,  3456,  3458,  3460,  3461,  3466,  3472,  3474,
    3477,  3479,  3483,  3487,  3488,  3493,  3494,  3496,  3497,  3502,
    3507,  3514,  3521,  3522,  3524,  3527,  3528,  3530,  3531,  3535,
    3537,  3540,  3541,  3545,  3551,  3552,  3556,  3559,  3560,  3562,
    3564,  3565,  3570,  3577,  3578,  3582,  3584,  3588,  3591,  3594,
    3597,  3601,  3602,  3606,  3607,  3611,  3612,  3616,  3617,  3619,
    3620,  3624,  3626,  3628,  3630,  3632,  3634,  3642,  3643,  3645,
    3647,  3649,  3651,  3653,  3655,  3660,  3662,  3665,  3667,  3670,
    3674,  3675,  3677,  3680,  3682,  3686,  3688,  3690,  3695,  3697,
    3699,  3701,  3702,  3707,  3713,  3714,  3717,  3718,  3723,  3727,
    3731,  3733,  3735,  3737,  3739,  3740,  3742,  3745,  3746,  3749,
    3750,  3753,  3756,  3757,  3760,  3761,  3764,  3767,  3768,  3771,
    3772,  3775,  3778,  3779,  3782,  3783,  3786,  3789,  3791,  3794,
    3796,  3798,  3801,  3804,  3807,  3809,  3811,  3814,  3817,  3820,
    3821,  3824,  3825,  3828,  3829,  3832,  3834,  3836,  3837,  3840,
    3842,  3845,  3848,  3850,  3852,  3854,  3856,  3858,  3860,  3862,
    3864,  3866,  3868,  3870,  3872,  3874,  3876,  3878,  3880,  3882,
    3884,  3886,  3888,  3890,  3892,  3894,  3896,  3898,  3901,  3903,
    3905,  3907,  3909,  3911,  3913,  3915,  3919,  3920,  3922,  3924,
    3928,  3932,  3934,  3938,  3942,  3944,  3948,  3950,  3953,  3956,
    3958,  3962,  3964,  3966,  3970,  3972,  3976,  3978,  3982,  3984,
    3987,  3990,  3992,  3994,  3996,  3999,  4001,  4003,  4005,  4008,
    4010,  4011,  4014,  4016,  4018,  4020,  4024,  4026,  4028,  4031,
    4033,  4035,  4037,  4040,  4042,  4044,  4046,  4048,  4050,  4052,
    4055,  4057,  4059,  4063,  4065,  4068,  4070,  4072,  4074,  4076,
    4079,  4082,  4085,  4090,  4094,  4096,  4098,  4101,  4103,  4105,
    4107,  4109,  4111,  4113,  4115,  4118,  4121,  4124,  4126,  4128,
    4130,  4132,  4134,  4136,  4138,  4140,  4142,  4144,  4146,  4148,
    4150,  4152,  4154,  4156,  4158,  4160,  4162,  4164,  4166,  4168,
    4170,  4172,  4174,  4176,  4179,  4181,  4185,  4188,  4191,  4193,
    4195,  4199,  4202,  4205,  4207,  4209,  4213,  4217,  4222,  4228,
    4230,  4232,  4234,  4236,  4238,  4240,  4242,  4244,  4246,  4248,
    4250,  4253,  4255,  4259,  4261,  4263,  4265,  4267,  4269,  4271,
    4273,  4276,  4282,  4288,  4294,  4299,  4305,  4311,  4317,  4320,
    4323,  4325,  4327,  4329,  4331,  4333,  4335,  4337,  4339,  4340,
    4345,  4351,  4352,  4356,  4359,  4361,  4365,  4369,  4371,  4375,
    4377,  4381,  4382,  4383,  4385,  4386,  4388,  4389,  4391,  4392,
    4395,  4396,  4399,  4400,  4402,  4404,  4405,  4407,  4408,  4410,
    4413,  4414,  4417,  4418,  4422,  4424,  4426,  4428,  4430,  4432,
    4434,  4436,  4438,  4439,  4442,  4444,  4446,  4448,  4450,  4452,
    4454,  4456,  4458,  4460,  4462,  4464,  4466,  4468,  4470,  4472,
    4474,  4476,  4478,  4480,  4482,  4484,  4486,  4488,  4490,  4492,
    4494,  4496,  4498,  4500,  4502,  4504,  4506,  4508,  4510,  4512,
    4514,  4516,  4518,  4520,  4522,  4524,  4526,  4528,  4530,  4532,
    4534,  4536,  4538,  4540,  4542,  4544,  4546,  4548,  4550,  4552,
    4554,  4556,  4558,  4560,  4562,  4564,  4566,  4568,  4570,  4572,
    4574,  4576,  4578,  4580,  4582,  4583,  4585,  4586,  4588,  4589,
    4591,  4592,  4594,  4595,  4597,  4598,  4600,  4601,  4603,  4604,
    4606,  4607,  4609,  4610,  4612,  4613,  4615,  4616,  4618,  4619,
    4621,  4622,  4624,  4625,  4627,  4628,  4630,  4631,  4633,  4634,
    4636,  4639,  4640,  4642,  4643,  4645,  4646,  4648,  4649,  4651,
    4652,  4654,  4656,  4657,  4659,  4660,  4662,  4664,  4665,  4667,
    4669,  4670,  4673,  4676,  4677,  4679,  4680,  4682,  4683,  4685,
    4686,  4688,  4690,  4691,  4693,  4694,  4696,  4697,  4700,  4702,
    4704,  4705,  4707,  4708,  4710,  4711,  4713,  4714,  4716,  4717,
    4719,  4720,  4722,  4723,  4725,  4726,  4728,  4731,  4732,  4734,
    4735,  4737,  4738,  4740,  4741,  4743,  4744,  4746,  4747,  4749,
    4750,  4752,  4753,  4755,  4757,  4758,  4760,  4761,  4765,  4766,
    4768,  4771,  4773,  4775,  4777,  4779,  4781,  4783,  4785,  4787,
    4789,  4791,  4793,  4795,  4797,  4799,  4801,  4803,  4805,  4807,
    4809,  4811,  4813,  4816,  4819,  4821,  4823,  4825,  4827,  4829,
    4831,  4834,  4836,  4840,  4843,  4845,  4847,  4849,  4852,  4854,
    4857,  4859,  4862,  4864,  4867,  4869,  4872,  4874,  4877,  4879,
    4882
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     514,     0,    -1,    -1,   515,   516,    -1,   519,    -1,   517,
      -1,   518,    -1,   517,   518,    -1,   521,    -1,   523,    -1,
      -1,   520,   529,    -1,   533,   529,   524,   525,    -1,   533,
     529,   524,   526,    -1,   535,   529,   527,    -1,    -1,   522,
      -1,   524,   522,    -1,    -1,   526,    -1,   142,   536,   452,
      -1,    -1,   528,    -1,   138,   536,   452,    -1,    -1,    -1,
      -1,   541,   542,   543,   604,   605,   607,   606,   639,   530,
     649,   650,   651,   531,   680,   733,   735,   737,   782,   532,
     796,    -1,    -1,   341,   452,   536,   537,   534,   538,   452,
      -1,   200,   452,   536,   537,   452,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1268,   539,  1283,    -1,
      72,    -1,    72,   540,    -1,   540,    -1,   171,    -1,   457,
      -1,   354,    -1,    -1,   153,   122,   452,    -1,    -1,    84,
     394,   452,    -1,    -1,   543,   544,    -1,   545,    -1,   549,
      -1,   568,    -1,   569,    -1,   560,    -1,    -1,   415,   452,
     546,   547,    -1,    -1,   559,   548,   452,    -1,    -1,  1299,
     107,   272,    -1,    -1,   304,   452,   550,   551,    -1,    -1,
     559,   452,    -1,   559,   552,   452,    -1,   552,   452,    -1,
     553,    -1,   552,   553,    -1,   554,    -1,   555,    -1,   556,
      -1,   557,    -1,   268,   410,  1268,  1217,  1310,    -1,  1316,
    1268,  1184,    -1,   396,  1268,  1217,    -1,  1255,    59,  1268,
     558,    -1,  1184,    -1,   257,    -1,   495,    -1,   435,    -1,
     505,    -1,   559,   505,    -1,    -1,   369,   452,   561,   562,
      -1,    -1,   563,   452,    -1,   563,     1,   452,    -1,   564,
      -1,   563,   564,    -1,   199,     9,   229,    -1,   199,   565,
     566,    -1,   199,   567,   229,    -1,   370,    -1,   497,    -1,
      -1,    26,   256,    -1,   370,    -1,   567,   370,    -1,   417,
     452,    -1,   570,   452,    -1,   570,     1,   452,    -1,   571,
      -1,   570,   571,    -1,   572,    -1,   577,    -1,   585,    -1,
     595,    -1,   592,    -1,   596,    -1,   598,    -1,   599,    -1,
     600,    -1,   601,    -1,   602,    -1,   603,    -1,    -1,   505,
     573,   574,    -1,  1268,    96,    -1,  1217,  1268,  1188,    -1,
    1268,  1188,   575,    -1,   576,    -1,    -1,   576,    -1,  1033,
    1280,  1188,    -1,   576,  1033,  1280,  1188,    -1,    -1,    11,
    1188,   578,  1268,   579,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   580,    -1,   581,    -1,   580,
     581,    -1,   584,    -1,   584,   443,   584,    -1,    -1,   584,
      17,   582,   583,    -1,   584,    -1,   583,    17,   584,    -1,
     256,    -1,   416,    -1,   511,    -1,   346,    -1,   212,    -1,
     266,    -1,   587,   586,    -1,    -1,   218,   505,    -1,   433,
    1256,   588,    -1,   589,    -1,   588,   589,    -1,   590,  1269,
     591,    -1,  1189,    -1,   590,  1189,    -1,  1218,    -1,   591,
    1218,    -1,    58,  1188,  1268,   593,    -1,   594,    -1,   593,
     594,    -1,  1220,    -1,  1220,   443,  1220,    -1,   257,  1188,
    1268,   256,    -1,    98,  1286,  1268,   256,   597,    -1,    -1,
    1299,   328,   256,    -1,   108,  1268,    68,    -1,   301,   405,
    1268,   469,   400,    -1,   100,  1268,  1183,    -1,    96,   423,
    1268,  1183,    -1,   390,  1268,  1183,    -1,   164,  1268,  1183,
      -1,    -1,   226,   394,   452,    -1,    -1,   173,   452,    -1,
      -1,   234,   452,    -1,    -1,   607,   608,    -1,    -1,   397,
    1241,  1188,   609,   610,   452,    -1,   397,     1,   452,    -1,
      -1,   610,   611,    -1,   612,    -1,   618,    -1,   620,    -1,
     621,    -1,   622,    -1,   624,    -1,   628,    -1,   630,    -1,
     631,    -1,   632,    -1,   634,    -1,   635,    -1,   637,    -1,
      29,  1296,   615,   614,   616,    -1,    29,  1296,   615,   613,
     617,    -1,    29,  1296,   615,   119,   617,    -1,    29,  1296,
     615,   238,   617,    -1,    29,  1296,   615,   335,   617,    -1,
     117,    -1,   118,    -1,   438,    -1,   347,    -1,    -1,   252,
       7,  1259,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1214,    -1,    -1,   256,    -1,  1214,    -1,     4,  1275,  1268,
     619,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1284,
    1270,  1268,   633,  1235,    -1,  1300,  1268,   505,    -1,   623,
     423,  1268,  1183,    -1,    -1,   455,    -1,   412,    -1,    -1,
     625,   262,  1275,  1268,   626,    -1,   267,   627,    -1,    33,
     627,    -1,   167,    -1,    -1,   504,   262,   309,  1309,    -1,
     504,   262,   309,   274,  1309,    -1,   504,   385,    -1,   315,
    1268,   629,    -1,   629,    -1,   220,    -1,  1284,  1253,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1255,  1268,  1187,
      -1,   351,   113,  1268,   419,    -1,   351,  1270,  1268,   633,
      -1,  1183,    -1,  1183,   453,  1182,    -1,  1183,   414,  1268,
    1182,    -1,   359,  1270,  1268,  1183,    -1,   372,   636,  1250,
      -1,   287,    -1,  1217,    -1,   404,  1299,   638,    -1,     9,
    1281,    -1,   287,  1281,    -1,   349,   310,    -1,    -1,   640,
     452,    -1,   640,     1,   452,    -1,   641,    -1,   640,   641,
      -1,   642,    -1,   644,    -1,   388,   643,  1250,  1261,  1173,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     645,  1259,  1292,  1257,   646,    -1,   647,    -1,   646,   647,
      -1,  1174,   648,    -1,    -1,   331,  1217,    -1,    -1,   102,
     122,   452,    -1,    -1,   455,   394,   452,    -1,    -1,   651,
     652,    -1,   653,   682,    -1,    -1,   655,  1174,   654,   656,
     452,    -1,   655,     1,   452,    -1,   172,    -1,   392,    -1,
      -1,   656,   657,    -1,  1268,   171,    -1,  1268,   204,    -1,
     658,    -1,   660,    -1,   664,    -1,   665,    -1,   668,    -1,
     669,    -1,   675,    -1,   676,    -1,   677,    -1,    47,  1257,
    1217,   663,   659,    -1,    -1,   353,    -1,    57,    -1,   351,
    1257,  1217,  1256,    -1,   351,  1257,  1217,   447,  1217,  1256,
      -1,   351,  1268,   500,  1263,  1289,   662,   663,  1256,   661,
      -1,    -1,   114,  1279,  1183,    -1,    -1,  1262,  1217,    -1,
      -1,   447,  1217,    -1,   239,  1311,  1307,    -1,   499,   306,
     666,  1268,   667,    -1,   499,   306,   174,  1268,   667,    -1,
     505,    -1,   213,    -1,   256,    -1,  1214,    -1,   102,  1311,
    1185,    -1,   250,  1268,  1187,  1274,   670,    -1,    -1,   670,
     671,    -1,   672,    -1,   673,    -1,   674,    -1,  1299,   187,
    1252,  1187,    -1,   466,  1187,    -1,    48,  1187,    -1,   352,
    1275,  1268,   505,    -1,    62,  1268,   505,    -1,   678,   679,
      -1,   366,  1268,    -1,   368,  1249,    -1,  1188,    -1,   679,
    1188,    -1,    -1,    -1,   507,   394,   452,   681,   682,    -1,
      -1,    -1,   683,   684,    -1,   685,   452,    -1,   684,   685,
     452,    -1,   684,   452,    -1,   697,    -1,    -1,   687,   688,
     686,   699,    -1,   687,     1,   452,    -1,  1233,   505,    -1,
      -1,   175,    -1,   505,    -1,   505,    -1,    -1,  1268,   204,
      -1,  1221,    -1,   245,   692,    -1,   244,   692,    -1,    50,
    1278,   692,    -1,  1211,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   696,    -1,   708,    -1,   709,
      -1,   693,    -1,   694,    -1,   695,    -1,     1,   452,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   687,   689,
      85,   690,   698,    -1,  1251,   691,    -1,   196,   505,    -1,
      -1,   699,   700,    -1,   701,    -1,   702,    -1,   704,    -1,
     705,    -1,   706,    -1,   710,    -1,   713,    -1,   722,    -1,
     723,    -1,   724,    -1,   725,    -1,   726,    -1,   731,    -1,
     732,    -1,   355,  1211,    -1,  1268,   171,   703,    -1,    -1,
      26,   256,    -1,  1268,   204,    -1,   327,    -1,   707,    -1,
     492,  1268,   707,    -1,    39,    -1,    73,    -1,   708,    -1,
     709,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   480,    -1,
     478,    -1,   479,    -1,    41,  1287,    -1,    41,   477,    -1,
      44,  1287,    -1,    44,   477,    -1,    43,  1287,    -1,    43,
     477,    -1,    42,  1287,    -1,    42,   477,    -1,    40,  1287,
      -1,    40,   477,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1288,   241,  1245,    -1,  1288,   469,
    1245,    -1,   305,  1217,   714,  1294,   715,   712,    -1,    -1,
     425,  1217,    -1,   305,  1217,   714,  1294,   715,   716,   719,
      -1,    -1,   447,  1217,    -1,    -1,   114,  1279,  1183,    -1,
     717,    -1,    -1,   717,   718,  1270,  1268,  1182,    -1,    27,
      -1,   115,    -1,    -1,   220,  1254,   720,    -1,   721,    -1,
     720,   721,    -1,   505,    -1,   235,  1285,    -1,   434,  1271,
      -1,    45,  1297,   511,    -1,    36,    -1,    -1,   499,  1269,
     728,   727,   730,    -1,   729,    -1,   728,   729,    -1,  1221,
      -1,  1221,   443,  1221,    -1,    -1,  1298,   454,  1268,  1221,
      -1,   363,  1214,    -1,   363,  1214,   443,  1214,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   452,
     734,   682,    -1,    -1,    -1,   255,   394,   452,   736,   682,
      -1,    -1,    -1,   366,   394,   452,   738,   739,    -1,    -1,
     739,   740,    -1,    -1,   348,  1175,   741,   742,   452,   756,
      -1,    -1,   742,   743,    -1,     1,   452,    -1,  1268,   204,
      -1,    61,  1268,  1201,    -1,   744,    -1,   747,    -1,  1324,
     745,    -1,  1260,   746,    -1,  1210,    -1,   746,  1210,    -1,
     321,  1273,   748,   749,    -1,  1219,    -1,  1219,  1308,  1219,
    1302,    -1,  1219,  1308,    -1,    -1,   749,   750,    -1,   751,
      -1,   752,    -1,   753,    -1,   754,    -1,   755,    -1,   210,
    1268,  1219,    -1,   177,  1317,  1268,  1219,    -1,   240,  1318,
    1268,  1219,    -1,   240,  1317,  1268,  1219,    -1,   187,  1268,
    1219,    -1,    -1,   756,   757,    -1,    -1,   687,   688,   758,
     759,   452,    -1,    -1,   759,   760,    -1,   761,    -1,   765,
      -1,   771,    -1,   705,    -1,   781,    -1,   710,    -1,   722,
      -1,   773,    -1,   724,    -1,   779,    -1,   766,    -1,   726,
      -1,   769,    -1,   780,    -1,   711,    -1,   770,    -1,   473,
    1268,   762,    -1,  1322,    -1,  1320,    -1,  1318,   763,    -1,
    1317,    -1,  1319,   763,    -1,  1321,    -1,  1323,    -1,    -1,
    1210,   764,    -1,   176,   764,    -1,    -1,   313,   321,    -1,
     285,   209,  1268,   776,    -1,   431,  1278,  1194,   767,    -1,
      -1,   373,  1279,   768,    -1,  1210,    -1,   176,    -1,   333,
     502,  1150,    -1,   500,  1210,   196,  1196,    49,  1196,    -1,
     772,   775,    -1,   252,  1277,  1269,    -1,   254,  1249,    -1,
     774,   777,    -1,  1301,  1277,  1269,    -1,  1302,  1249,    -1,
     776,    -1,   775,   776,    -1,   329,  1217,    -1,  1219,    -1,
     286,    -1,   778,    -1,   777,   778,    -1,   329,  1217,    -1,
    1219,    -1,   414,  1268,  1196,  1242,    -1,   209,  1265,    -1,
     492,  1268,   119,    -1,    -1,    -1,   389,   394,   452,   783,
     784,    -1,    -1,   785,    -1,   786,   452,    -1,   785,   786,
     452,    -1,   697,    -1,    -1,   687,   688,   787,   788,    -1,
     687,     1,   452,    -1,    -1,   788,   789,    -1,    45,   252,
      -1,    45,   389,    -1,    38,    -1,    46,    -1,   160,   156,
      -1,   160,   158,    -1,   211,    -1,   265,    -1,   378,    -1,
     474,    -1,   318,    -1,   243,    -1,    32,    -1,   395,    -1,
     371,    -1,   198,    -1,   345,    56,  1268,  1201,    -1,   345,
      -1,   457,    -1,   252,  1276,  1268,   792,  1203,    -1,  1301,
    1276,  1268,   793,  1203,    -1,   189,  1268,  1203,    -1,    35,
    1268,  1203,    -1,   706,    -1,   724,    -1,   795,    -1,   722,
      -1,   710,    -1,   726,    -1,   705,    -1,   794,    -1,   498,
    1210,    -1,   196,  1202,    -1,   447,  1210,    -1,   329,    -1,
     464,    -1,   270,    -1,   459,    -1,    -1,   790,    -1,   791,
      -1,    -1,   790,    -1,   791,    -1,   305,  1217,  1294,    -1,
    1268,   204,    -1,    -1,    -1,    -1,   337,   122,   800,   808,
     452,   797,   809,   798,   811,    -1,    -1,   799,   822,   452,
     811,    -1,    -1,    -1,   498,   801,   803,    -1,    -1,    55,
     802,   803,    -1,   804,    -1,   803,   804,    -1,   805,   806,
     807,   505,    -1,    -1,  1254,   357,    -1,  1254,   499,    -1,
      -1,   410,  1268,    32,    -1,   410,  1268,   110,    -1,   477,
     410,  1268,    32,    -1,   477,   410,  1268,  1217,    -1,   410,
    1268,  1217,    -1,    -1,   312,    -1,    -1,   376,   505,    -1,
      -1,    -1,   109,   452,   810,   811,   129,   109,   452,    -1,
      -1,   811,   812,    -1,   813,    -1,   816,    -1,   822,   452,
      -1,   817,    -1,   452,    -1,    -1,   505,   394,   818,   452,
     814,   815,    -1,    -1,  1104,   452,    -1,   505,   452,    -1,
     505,    -1,    -1,  1217,    -1,    -1,    -1,   820,   821,   822,
      -1,    -1,   823,   824,    -1,   822,   824,    -1,   825,    -1,
     841,    -1,   846,    -1,   850,    -1,   855,    -1,   870,    -1,
     873,    -1,   881,    -1,   877,    -1,   882,    -1,   883,    -1,
     888,    -1,   902,    -1,   906,    -1,   909,    -1,   923,    -1,
     927,    -1,   930,    -1,   933,    -1,   937,    -1,   938,    -1,
     942,    -1,   952,    -1,   955,    -1,   972,    -1,   974,    -1,
     977,    -1,   981,    -1,   987,    -1,   999,    -1,  1007,    -1,
    1008,    -1,  1011,    -1,  1012,    -1,  1016,    -1,  1021,    -1,
    1022,    -1,  1030,    -1,  1045,    -1,  1055,    -1,  1064,    -1,
    1069,    -1,  1076,    -1,  1080,    -1,  1082,    -1,  1085,    -1,
    1088,    -1,  1092,    -1,  1119,    -1,   285,   399,    -1,     1,
    1246,    -1,    -1,     3,   826,   827,   840,    -1,   828,   830,
     834,   835,   836,  1127,    -1,  1210,   196,   829,    -1,  1210,
     196,  1302,    -1,  1210,   196,   103,   510,    -1,  1210,   196,
     103,    -1,  1210,   196,   104,   509,    -1,  1210,   196,   104,
      -1,  1210,   196,   105,    -1,  1210,   196,   162,   237,    -1,
    1210,   196,   165,   423,    -1,  1210,   196,   444,    -1,  1210,
     196,   494,   276,    -1,  1210,   196,    69,    -1,  1210,   196,
     155,  1127,    -1,  1210,   196,   153,  1199,  1127,    -1,  1210,
     196,    24,    -1,  1210,   196,    25,  1127,    -1,  1210,   196,
    1177,    -1,  1210,   196,   505,    -1,  1210,    -1,   308,    -1,
     254,    -1,   252,   299,    -1,    -1,   831,    -1,  1252,   832,
     833,    -1,  1252,   833,   832,    -1,  1252,   832,    -1,  1252,
     833,    -1,    30,  1199,    -1,   252,  1276,  1203,    -1,  1301,
    1276,  1203,    -1,   331,  1276,  1203,    -1,    -1,   197,    -1,
      -1,   272,  1268,    47,    -1,    -1,   504,   837,    -1,   838,
      -1,   837,   838,    -1,    32,    -1,   436,    -1,    38,    -1,
      46,    -1,    91,    -1,   198,    -1,   211,    -1,   243,    -1,
     263,    -1,   265,    -1,   288,    -1,   318,    -1,   345,    56,
    1268,  1201,    -1,   345,    -1,   371,    -1,   378,    -1,   395,
      -1,   474,    -1,   287,   839,    -1,   839,    -1,   490,    -1,
     189,  1268,  1203,    -1,    35,  1268,  1203,    -1,   391,   483,
    1149,    -1,   391,   123,  1149,    -1,   445,  1248,  1204,    -1,
     484,    -1,   110,    -1,    -1,   130,    -1,    -1,     5,   842,
     843,   845,    -1,  1192,   447,  1169,  1133,    -1,  1192,   844,
     203,  1169,  1133,    -1,    94,  1210,   447,  1210,  1242,  1133,
      -1,    -1,   447,  1193,    -1,    -1,   131,    -1,    -1,    10,
     847,   848,    -1,  1210,  1236,   849,    -1,  1163,    57,  1237,
     849,    -1,    -1,   376,  1191,    -1,    -1,    18,   851,   852,
      -1,   853,    -1,   852,   853,    -1,  1179,   447,   854,  1179,
      -1,    -1,   339,   447,    -1,    -1,    51,   856,   857,   869,
      -1,   858,  1202,   859,   864,   867,   868,    -1,    -1,   422,
      -1,   424,    -1,   271,    -1,    -1,    -1,   498,   860,   861,
      -1,   862,    -1,   861,   862,    -1,   863,   308,    -1,   863,
     806,  1193,    -1,    -1,  1254,   357,    -1,  1254,    87,    -1,
    1254,   499,    -1,    -1,   865,  1267,  1210,    -1,   865,   866,
      -1,   865,     6,  1278,  1210,    -1,   376,    -1,   203,    -1,
     461,    -1,   308,    -1,    -1,  1305,   819,    -1,    -1,   294,
     819,    -1,    -1,   132,    -1,    -1,    52,   871,   872,    -1,
    1201,    -1,   872,  1201,    -1,    -1,    60,   874,   875,    -1,
    1174,   876,    -1,   875,  1174,   876,    -1,    -1,  1312,    -1,
    1312,  1261,   362,    -1,  1299,   287,   380,    -1,  1299,   262,
      -1,    -1,    74,   878,   879,   880,    -1,  1169,  1303,  1163,
    1133,    -1,    -1,   133,    -1,    71,    -1,    88,    -1,    -1,
     111,   884,   885,   887,    -1,  1174,  1284,  1146,    -1,   455,
     886,    -1,  1174,    -1,   886,  1174,    -1,    -1,   134,    -1,
      -1,   119,   889,   890,   901,    -1,  1201,   488,  1130,    -1,
    1201,   489,  1130,    -1,  1201,   486,  1130,    -1,  1201,   487,
    1130,    -1,  1192,   894,   898,  1130,    -1,   891,  1130,    -1,
    1193,   504,   899,  1130,    -1,   893,    -1,    -1,   891,   892,
     893,    -1,  1193,   831,   895,   835,   897,    -1,    -1,   485,
    1177,    -1,   485,   505,    -1,   485,   335,    -1,   485,    96,
      -1,    -1,   485,   896,    -1,    96,    -1,    97,    -1,    -1,
     504,   899,    -1,    -1,   298,    -1,   900,    -1,   899,   900,
      -1,    38,    -1,    45,   252,    -1,    45,   389,    -1,    46,
      -1,    91,    -1,   160,   156,    -1,   160,   158,    -1,   211,
      -1,   265,    -1,   318,    -1,   378,    -1,   474,    -1,   189,
    1268,  1203,    -1,    35,  1268,  1203,    -1,   391,   483,  1149,
      -1,   391,   123,  1149,    -1,    -1,   135,    -1,    -1,   121,
     903,   904,   905,    -1,  1193,   228,  1169,  1133,    -1,  1193,
     228,  1193,   203,  1169,  1133,    -1,  1193,    49,  1193,   203,
    1169,  1133,    -1,  1193,   228,  1193,   203,  1170,   361,  1170,
    1133,    -1,  1193,    49,  1193,   203,  1170,   361,  1170,  1133,
      -1,    -1,   136,    -1,    -1,   152,   907,   908,    -1,   256,
     859,    -1,    -1,   163,   910,   911,   922,    -1,   912,   914,
      -1,   913,    -1,   912,    17,   913,    -1,  1151,    -1,   465,
      -1,   454,    -1,   915,   917,    -1,   915,    -1,   916,    -1,
     915,   916,    -1,   918,   819,    -1,   502,   316,   819,    -1,
     502,   919,    -1,   918,   502,   919,    -1,   920,    -1,   919,
      17,   920,    -1,  1152,   921,    -1,    21,    -1,   465,    -1,
     454,    -1,    -1,   443,  1151,    -1,    -1,   137,    -1,    -1,
     168,   924,   925,    -1,    -1,   340,   926,    -1,   199,    -1,
     324,   101,    -1,   324,    -1,   394,    -1,   323,    -1,    -1,
     865,  1193,    -1,    -1,   195,   928,   929,    -1,  1190,    -1,
      -1,   202,   931,   932,    -1,  1214,    -1,    -1,   205,   934,
     935,    -1,  1295,  1178,   936,    -1,    -1,   114,  1279,  1210,
      -1,   206,   926,    -1,    -1,   215,   939,  1150,  1293,   940,
     941,    -1,   819,   128,   819,    -1,   128,   819,    -1,   819,
      -1,    -1,   139,    -1,    -1,   222,   943,   944,    -1,  1190,
     945,   946,   947,   951,    -1,    -1,  1299,   175,    -1,    -1,
       9,  1295,   499,    -1,   950,  1295,   499,    -1,    -1,   365,
     948,    -1,   949,    -1,   948,   949,    -1,   950,  1258,    49,
    1193,    -1,    12,    -1,    15,    -1,   301,    -1,    16,    -1,
     302,    -1,   277,    -1,   278,    -1,    -1,  1293,  1295,   110,
      -1,    -1,   224,   953,   954,    -1,  1175,    -1,   954,  1175,
      -1,    -1,   227,   956,   957,    -1,   958,   959,    -1,  1210,
      -1,  1221,    -1,  1224,    -1,   960,   962,    -1,   960,    -1,
     962,    -1,   963,    -1,    -1,   437,   961,   964,    -1,   365,
     966,    -1,    92,  1199,   447,  1200,   970,    -1,   965,    -1,
     964,   965,    -1,  1199,   188,    -1,    57,   970,    -1,     9,
      -1,   241,    -1,   469,    -1,  1199,   970,    -1,   967,    -1,
     966,   967,    -1,    57,    49,  1199,   970,    -1,   968,   969,
      -1,    -1,     9,    -1,   241,    -1,   177,    -1,   469,    -1,
    1199,    49,  1200,   970,    -1,    -1,   970,   971,    -1,    37,
    1266,  1193,    -1,     8,  1266,  1193,    -1,    -1,   269,   973,
    1047,    -1,    -1,   273,   975,   976,    -1,  1193,   447,  1190,
      -1,    94,  1193,   447,  1190,    -1,    -1,   275,   978,   979,
     980,    -1,  1193,    49,  1169,  1133,    -1,  1193,    49,  1193,
     203,  1169,  1133,    -1,    -1,   140,    -1,    -1,   311,   982,
     983,    -1,   984,   985,  1173,   986,    -1,   983,   984,   985,
    1173,   986,    -1,   225,    -1,   317,    -1,   233,    -1,   170,
      -1,    -1,   404,  1299,   638,    -1,    -1,  1299,   287,   380,
      -1,  1299,   262,    -1,   379,    -1,    -1,   324,   988,   989,
      -1,   993,   994,    -1,    -1,   994,   990,   819,   991,    -1,
     994,   992,    -1,    -1,   141,    -1,   141,    -1,   452,    -1,
    1179,    -1,  1179,   443,  1179,    -1,    -1,  1202,   446,    -1,
     190,    -1,   995,   482,   996,    -1,   995,   500,   997,    -1,
      -1,  1299,   440,  1124,    -1,   168,    -1,  1150,    -1,   998,
      -1,   997,     8,   998,    -1,  1210,   196,  1193,    49,  1193,
     482,  1150,    -1,    -1,   349,  1000,  1001,  1006,    -1,  1174,
    1239,  1284,  1002,  1003,  1004,  1005,    -1,    -1,   228,  1210,
      -1,    -1,   217,   262,    -1,  1299,   262,    -1,  1299,   236,
     262,    -1,  1299,   287,   262,    -1,  1299,   216,   262,    -1,
    1299,   501,    -1,    -1,   237,  1268,  1210,    -1,  1146,    -1,
    1140,    -1,    -1,   143,    -1,   350,    -1,    -1,   360,  1009,
    1010,    -1,  1171,  1122,    -1,   374,    -1,    -1,   375,  1013,
    1014,  1015,    -1,  1174,  1284,  1002,  1139,    -1,    -1,   144,
      -1,    -1,   381,  1017,  1018,  1020,    -1,  1171,  1122,  1019,
    1146,    -1,    -1,  1299,   262,    -1,  1299,   287,   262,    -1,
      -1,   145,    -1,   385,    -1,    -1,   393,  1023,  1024,  1029,
      -1,  1172,  1025,  1026,  1027,    -1,     9,  1172,  1026,   502,
    1151,   819,    -1,    -1,   500,  1210,    -1,    -1,   129,   819,
      -1,  1028,    -1,  1028,  1027,    -1,   502,  1150,   819,    -1,
      -1,   146,    -1,    -1,   403,  1031,  1032,    -1,  1035,    -1,
    1036,    -1,  1039,    -1,  1040,    -1,  1041,    -1,  1043,    -1,
     309,    -1,   307,    -1,   483,    -1,   123,    -1,   153,  1199,
     447,  1199,    -1,  1207,    31,  1037,    -1,  1038,    -1,  1037,
    1038,    -1,    38,  1033,    -1,    46,  1033,    -1,   211,  1033,
      -1,   265,  1033,    -1,   378,  1033,    -1,   474,  1033,    -1,
     243,  1033,    -1,   318,  1033,    -1,  1190,   447,   152,  1198,
      -1,  1190,   447,  1193,    -1,  1190,  1034,    49,  1193,    -1,
    1042,    -1,  1041,  1042,    -1,  1176,   447,  1033,    -1,  1044,
      -1,  1043,  1044,    -1,  1190,   447,   465,    -1,  1190,   447,
     454,    -1,    -1,   412,  1046,  1047,    -1,    -1,  1208,  1049,
    1051,  1052,  1048,  1053,  1054,    -1,    -1,  1049,  1279,   718,
    1270,  1050,    -1,    -1,  1050,  1214,    -1,    -1,  1315,  1264,
      -1,    -1,  1300,  1268,  1183,    -1,    -1,   498,  1173,    -1,
     225,   337,  1268,   993,    -1,    -1,   203,  1173,    -1,   317,
     337,  1268,   993,    -1,    -1,   421,  1056,  1057,  1063,    -1,
    1174,  1059,  1058,  1146,    -1,    -1,  1299,  1314,  1163,    -1,
      -1,   237,  1268,  1060,  1210,    -1,   177,    -1,   240,    -1,
    1156,    -1,  1240,  1157,    -1,  1240,  1158,    -1,  1240,  1159,
      -1,  1240,  1160,    -1,  1061,    -1,  1062,    -1,   290,  1156,
      -1,   293,    -1,    -1,   147,    -1,    -1,   426,   387,  1065,
    1066,    -1,   426,  1068,    -1,    -1,   865,  1193,    -1,  1299,
     161,  1291,  1067,    -1,  1299,   289,  1291,  1067,    -1,    -1,
    1193,    -1,   256,    -1,   416,    -1,   511,    -1,   346,    -1,
      -1,   427,  1070,  1071,  1075,    -1,  1072,   228,  1210,  1074,
    1136,    -1,  1073,    -1,  1072,  1073,    -1,  1193,    -1,   112,
    1254,   410,    -1,   112,  1254,  1193,    -1,    -1,  1299,   330,
    1268,  1210,    -1,    -1,   148,    -1,    -1,   430,  1077,  1078,
    1079,    -1,  1192,   196,  1169,  1133,    -1,  1192,   196,  1193,
     203,  1169,  1133,    -1,    94,  1210,   196,  1210,  1242,  1133,
      -1,    -1,   149,    -1,   432,  1081,    -1,    -1,   336,    -1,
      -1,   439,  1083,  1084,    -1,  1175,    -1,  1084,  1175,    -1,
      -1,   470,  1086,  1087,    -1,  1210,   196,  1199,   447,  1200,
      -1,    -1,   476,  1089,  1090,    -1,  1174,  1091,    -1,    -1,
     351,    -1,   353,    -1,    -1,   481,  1093,  1094,  1103,    -1,
    1210,  1095,  1098,  1074,  1102,  1136,    -1,    -1,   112,  1254,
    1096,    -1,  1097,    -1,  1096,   313,  1097,    -1,  1234,  1199,
      -1,   228,  1099,    -1,  1098,  1099,    -1,  1210,  1100,  1101,
      -1,    -1,   113,  1263,  1210,    -1,    -1,    95,  1263,  1210,
      -1,    -1,   437,  1263,  1210,    -1,    -1,   150,    -1,    -1,
     493,  1105,  1106,    -1,  1107,    -1,  1110,    -1,  1114,    -1,
    1116,    -1,  1117,    -1,  1108,  1248,  1290,  1304,  1282,  1279,
    1109,    -1,    -1,   204,    -1,  1173,    -1,   225,    -1,   317,
      -1,   233,    -1,   170,    -1,  1261,   107,  1279,  1111,    -1,
    1112,    -1,  1111,  1112,    -1,  1180,    -1,     9,   338,    -1,
       9,  1113,  1214,    -1,    -1,   358,    -1,   358,   306,    -1,
     306,    -1,  1252,   340,  1115,    -1,   421,    -1,   129,    -1,
    1108,    37,   367,  1210,    -1,  1118,    -1,   166,    -1,   127,
      -1,    -1,   508,  1120,  1121,  1126,    -1,  1171,  1122,  1123,
    1019,  1125,    -1,    -1,   196,  1206,    -1,    -1,  1124,  1247,
    1203,  1272,    -1,  1124,  1247,  1177,    -1,  1124,  1247,   321,
      -1,    37,    -1,     8,    -1,  1146,    -1,  1143,    -1,    -1,
     151,    -1,  1128,  1129,    -1,    -1,   165,   819,    -1,    -1,
     294,   819,    -1,  1131,  1132,    -1,    -1,   165,   819,    -1,
      -1,   294,   819,    -1,  1134,  1135,    -1,    -1,   411,   819,
      -1,    -1,   297,   819,    -1,  1137,  1138,    -1,    -1,   462,
     819,    -1,    -1,   296,   819,    -1,  1141,  1142,    -1,  1141,
      -1,  1141,  1142,    -1,  1141,    -1,  1142,    -1,   129,   819,
      -1,   291,   819,    -1,  1144,  1145,    -1,  1144,    -1,  1145,
      -1,   157,   819,    -1,   292,   819,    -1,  1147,  1148,    -1,
      -1,   231,   819,    -1,    -1,   295,   819,    -1,    -1,  1205,
    1313,    -1,  1151,    -1,  1152,    -1,    -1,  1153,  1154,    -1,
    1155,    -1,  1154,   232,    -1,  1154,  1155,    -1,  1193,    -1,
     463,    -1,   449,    -1,   464,    -1,   459,    -1,   460,    -1,
     451,    -1,   169,    -1,  1156,    -1,  1157,    -1,  1158,    -1,
    1159,    -1,  1160,    -1,   293,    -1,   290,    -1,    20,    -1,
     313,    -1,   308,    -1,   301,    -1,    12,    -1,    13,    -1,
      14,    -1,   332,    -1,   284,    -1,   453,    -1,   159,  1295,
      -1,   456,    -1,   207,    -1,   458,    -1,   246,    -1,   208,
      -1,   247,    -1,  1163,    -1,  1161,  1162,  1163,    -1,    -1,
      70,    -1,   398,    -1,  1163,   464,  1164,    -1,  1163,   459,
    1164,    -1,  1164,    -1,  1164,   460,  1165,    -1,  1164,   451,
    1165,    -1,  1165,    -1,  1166,   169,  1165,    -1,  1166,    -1,
     464,  1167,    -1,   459,  1167,    -1,  1167,    -1,   463,  1163,
     449,    -1,  1196,    -1,   251,    -1,   251,  1306,   505,    -1,
     253,    -1,   253,  1306,   505,    -1,   322,    -1,   322,  1306,
     505,    -1,  1170,    -1,  1169,  1170,    -1,  1191,  1242,    -1,
    1214,    -1,  1214,    -1,  1174,    -1,  1173,  1174,    -1,   505,
      -1,   505,    -1,  1177,    -1,  1176,  1177,    -1,   271,    -1,
      -1,  1178,  1179,    -1,  1180,    -1,  1214,    -1,  1181,    -1,
    1181,  1306,  1181,    -1,   256,    -1,  1183,    -1,  1182,  1183,
      -1,  1214,    -1,   505,    -1,  1186,    -1,  1185,  1186,    -1,
     505,    -1,  1183,    -1,   256,    -1,   505,    -1,   505,    -1,
    1191,    -1,  1190,  1191,    -1,  1212,    -1,  1222,    -1,     6,
    1278,  1211,    -1,  1193,    -1,  1192,  1193,    -1,  1210,    -1,
    1221,    -1,  1224,    -1,  1168,    -1,   245,  1211,    -1,   245,
    1222,    -1,   245,  1224,    -1,     6,  1278,  1197,  1198,    -1,
       6,  1278,  1211,    -1,   271,    -1,  1196,    -1,  1194,  1196,
      -1,  1210,    -1,  1222,    -1,  1224,    -1,  1210,    -1,  1222,
      -1,  1224,    -1,  1168,    -1,   245,  1211,    -1,   245,  1222,
      -1,   245,  1224,    -1,   340,    -1,   152,    -1,  1211,    -1,
     256,    -1,  1210,    -1,  1222,    -1,  1210,    -1,  1221,    -1,
    1210,    -1,   256,    -1,  1210,    -1,   256,    -1,  1224,    -1,
    1207,    -1,  1217,    -1,   511,    -1,  1207,    -1,  1219,    -1,
    1207,    -1,  1217,    -1,  1210,    -1,  1221,    -1,  1224,    -1,
    1209,    -1,  1209,    -1,  1214,    -1,  1214,  1215,    -1,  1211,
      -1,  1214,  1215,  1216,    -1,  1214,  1215,    -1,  1214,  1216,
      -1,  1214,    -1,  1213,    -1,  1214,  1215,  1216,    -1,  1214,
    1215,    -1,  1214,  1216,    -1,  1214,    -1,   505,    -1,   505,
    1306,  1214,    -1,   463,  1161,   449,    -1,   463,  1163,   450,
     449,    -1,   463,  1163,   450,  1163,   449,    -1,   256,    -1,
     256,    -1,   256,    -1,   256,    -1,   416,    -1,   511,    -1,
     346,    -1,   212,    -1,   266,    -1,   461,    -1,  1222,    -1,
       9,  1223,    -1,  1223,    -1,  1222,   448,  1223,    -1,   256,
      -1,   416,    -1,   511,    -1,   346,    -1,   212,    -1,   266,
      -1,   461,    -1,  1225,  1228,    -1,  1226,   463,  1195,   449,
    1228,    -1,  1227,   463,  1161,   449,  1228,    -1,   471,   463,
    1230,   449,  1228,    -1,   303,   463,  1231,   449,    -1,   258,
     463,  1232,   449,  1228,    -1,   259,   463,  1232,   449,  1228,
      -1,   260,   463,  1232,   449,  1228,    -1,   201,  1229,    -1,
     496,  1229,    -1,    99,    -1,   503,    -1,   491,    -1,   264,
      -1,   377,    -1,    82,    -1,   428,    -1,   429,    -1,    -1,
     463,  1163,   450,   449,    -1,   463,  1163,   450,  1163,   449,
      -1,    -1,   463,  1161,   449,    -1,   463,   449,    -1,  1195,
      -1,  1195,  1162,   241,    -1,  1195,  1162,   469,    -1,  1195,
      -1,  1195,  1162,  1195,    -1,  1163,    -1,  1163,  1162,  1183,
      -1,    -1,    -1,     9,    -1,    -1,  1315,    -1,    -1,   223,
      -1,    -1,   223,  1238,    -1,    -1,   447,  1200,    -1,    -1,
     285,    -1,   334,    -1,    -1,   290,    -1,    -1,   312,    -1,
     290,   312,    -1,    -1,   386,  1243,    -1,    -1,   272,  1268,
    1244,    -1,    34,    -1,   281,    -1,   282,    -1,   283,    -1,
     344,    -1,   467,    -1,   468,    -1,   472,    -1,    -1,   400,
    1255,    -1,   452,    -1,     3,    -1,     5,    -1,    10,    -1,
      18,    -1,    51,    -1,    52,    -1,    60,    -1,    71,    -1,
      74,    -1,    88,    -1,   111,    -1,   119,    -1,   121,    -1,
     128,    -1,   152,    -1,   163,    -1,   168,    -1,   195,    -1,
     202,    -1,   205,    -1,   206,    -1,   215,    -1,   222,    -1,
     224,    -1,   227,    -1,   269,    -1,   273,    -1,   275,    -1,
     285,    -1,   311,    -1,   324,    -1,   349,    -1,   360,    -1,
     375,    -1,   381,    -1,   385,    -1,   393,    -1,   403,    -1,
     412,    -1,   421,    -1,   426,    -1,   427,    -1,   430,    -1,
     432,    -1,   439,    -1,   470,    -1,   476,    -1,   481,    -1,
     508,    -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,
     134,    -1,   135,    -1,   136,    -1,   137,    -1,   139,    -1,
     140,    -1,   141,    -1,   143,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,    -1,     7,    -1,    -1,     8,    -1,    -1,    22,
      -1,    -1,    23,    -1,    -1,    26,    -1,    -1,    30,    -1,
      -1,    39,    -1,    -1,    49,    -1,    -1,    56,    -1,    -1,
      57,    -1,    -1,    86,    -1,    -1,   102,    -1,    -1,   455,
      -1,    -1,   176,    -1,    -1,   188,    -1,    -1,   196,    -1,
      -1,   218,    -1,    -1,   314,    -1,   218,   314,    -1,    -1,
     221,    -1,    -1,   457,    -1,    -1,   228,    -1,    -1,   232,
      -1,    -1,   232,    -1,    22,    -1,    -1,   237,    -1,    -1,
     242,    -1,   384,    -1,    -1,   252,    -1,   254,    -1,    -1,
     248,  1268,    -1,   249,  1249,    -1,    -1,   254,    -1,    -1,
     272,    -1,    -1,   299,    -1,    -1,   299,    -1,   300,    -1,
      -1,   306,    -1,    -1,   309,    -1,    -1,   423,   232,    -1,
     423,    -1,   232,    -1,    -1,   316,    -1,    -1,   337,    -1,
      -1,   340,    -1,    -1,   351,    -1,    -1,   384,    -1,    -1,
     405,    -1,    -1,   406,    -1,    -1,   405,    -1,   405,   232,
      -1,    -1,   410,    -1,    -1,   418,    -1,    -1,   423,    -1,
      -1,   438,    -1,    -1,   442,    -1,    -1,   446,    -1,    -1,
     447,    -1,    -1,   447,    -1,   498,    -1,    -1,   502,    -1,
      -1,   502,   403,   447,    -1,    -1,   504,    -1,    63,   401,
      -1,   401,    -1,    66,    -1,    64,    -1,    67,    -1,    65,
      -1,   453,    -1,   159,    -1,   165,    -1,   161,    -1,   165,
      -1,   462,    -1,   218,    -1,   306,    -1,   418,    -1,   308,
      -1,   252,    -1,   254,    -1,   351,    -1,   353,    -1,    57,
      -1,   506,    -1,   351,  1268,    -1,   353,  1249,    -1,   356,
      -1,   475,    -1,   252,    -1,   254,    -1,   410,    -1,   244,
      -1,   504,   124,    -1,   124,    -1,   340,    63,   401,    -1,
      63,   401,    -1,   401,    -1,   116,    -1,   106,    -1,    89,
     210,    -1,    54,    -1,    89,   187,    -1,    53,    -1,   321,
     210,    -1,   325,    -1,   321,   187,    -1,   326,    -1,   366,
     210,    -1,   383,    -1,   366,   187,    -1,   382,    -1,    89,
    1268,    -1,    90,  1249,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1367,  1367,  1367,  1399,  1400,  1404,  1405,  1409,  1410,
    1414,  1414,  1437,  1444,  1451,  1457,  1458,  1459,  1463,  1464,
    1468,  1492,  1493,  1497,  1531,  1537,  1549,  1523,  1559,  1558,
    1596,  1631,  1632,  1636,  1637,  1640,  1641,  1645,  1654,  1663,
    1664,  1668,  1672,  1681,  1682,  1690,  1691,  1701,  1702,  1706,
    1707,  1708,  1709,  1710,  1717,  1716,  1729,  1730,  1733,  1734,
    1748,  1747,  1757,  1758,  1759,  1760,  1764,  1765,  1769,  1770,
    1771,  1772,  1776,  1783,  1790,  1797,  1808,  1812,  1816,  1820,
    1827,  1828,  1835,  1834,  1845,  1846,  1847,  1854,  1855,  1859,
    1863,  1875,  1879,  1880,  1885,  1888,  1895,  1900,  1911,  1924,
    1925,  1933,  1934,  1938,  1939,  1940,  1941,  1942,  1943,  1944,
    1945,  1946,  1947,  1948,  1949,  1957,  1956,  1975,  1985,  1998,
    2006,  2009,  2010,  2014,  2024,  2040,  2039,  2063,  2069,  2075,
    2081,  2087,  2093,  2103,  2107,  2114,  2118,  2123,  2122,  2133,
    2137,  2144,  2145,  2146,  2147,  2148,  2149,  2156,  2171,  2174,
    2181,  2189,  2193,  2204,  2224,  2232,  2243,  2244,  2250,  2271,
    2272,  2276,  2280,  2301,  2324,  2406,  2409,  2418,  2437,  2453,
    2471,  2489,  2506,  2522,  2523,  2530,  2531,  2539,  2540,  2550,
    2551,  2556,  2555,  2576,  2586,  2587,  2591,  2592,  2593,  2594,
    2595,  2596,  2597,  2598,  2599,  2600,  2601,  2602,  2603,  2610,
    2616,  2626,  2639,  2652,  2668,  2669,  2670,  2671,  2674,  2675,
    2681,  2682,  2686,  2690,  2691,  2696,  2699,  2700,  2707,  2715,
    2716,  2717,  2724,  2751,  2762,  2769,  2771,  2772,  2778,  2778,
    2785,  2790,  2795,  2802,  2803,  2804,  2808,  2819,  2820,  2824,
    2829,  2834,  2839,  2850,  2861,  2871,  2879,  2880,  2881,  2887,
    2898,  2905,  2906,  2912,  2920,  2921,  2922,  2928,  2929,  2930,
    2937,  2938,  2942,  2943,  2949,  2977,  2978,  2979,  2980,  2987,
    2986,  3002,  3003,  3007,  3010,  3011,  3017,  3018,  3026,  3027,
    3035,  3036,  3040,  3061,  3060,  3077,  3084,  3088,  3094,  3095,
    3099,  3109,  3124,  3125,  3126,  3127,  3128,  3129,  3130,  3131,
    3132,  3139,  3146,  3146,  3146,  3152,  3172,  3206,  3237,  3238,
    3245,  3246,  3250,  3251,  3258,  3269,  3274,  3285,  3286,  3290,
    3291,  3297,  3308,  3326,  3327,  3331,  3332,  3333,  3337,  3344,
    3351,  3360,  3372,  3424,  3439,  3440,  3444,  3454,  3493,  3495,
    3494,  3510,  3513,  3513,  3530,  3531,  3533,  3537,  3539,  3538,
    3573,  3586,  3594,  3599,  3605,  3614,  3624,  3627,  3639,  3640,
    3641,  3642,  3646,  3650,  3654,  3658,  3662,  3666,  3670,  3674,
    3678,  3682,  3686,  3690,  3694,  3705,  3706,  3710,  3711,  3715,
    3716,  3717,  3721,  3722,  3726,  3752,  3756,  3765,  3769,  3778,
    3779,  3780,  3781,  3782,  3783,  3784,  3785,  3786,  3787,  3788,
    3789,  3790,  3791,  3798,  3822,  3850,  3853,  3862,  3887,  3898,
    3899,  3903,  3907,  3911,  3915,  3919,  3923,  3927,  3931,  3935,
    3939,  3943,  3947,  3951,  3956,  3961,  3965,  3969,  3977,  3981,
    3985,  3993,  3997,  4001,  4005,  4009,  4013,  4017,  4021,  4025,
    4033,  4041,  4045,  4049,  4053,  4057,  4061,  4069,  4070,  4074,
    4075,  4081,  4087,  4099,  4117,  4118,  4127,  4151,  4152,  4155,
    4156,  4163,  4187,  4188,  4205,  4206,  4209,  4210,  4217,  4218,
    4223,  4234,  4245,  4256,  4267,  4296,  4295,  4304,  4305,  4309,
    4310,  4313,  4314,  4327,  4340,  4361,  4370,  4384,  4386,  4385,
    4405,  4407,  4406,  4422,  4424,  4423,  4432,  4433,  4440,  4439,
    4452,  4453,  4454,  4461,  4466,  4470,  4471,  4477,  4484,  4488,
    4489,  4495,  4532,  4536,  4541,  4547,  4548,  4553,  4554,  4555,
    4556,  4557,  4561,  4568,  4575,  4582,  4589,  4595,  4596,  4601,
    4600,  4607,  4608,  4612,  4613,  4614,  4615,  4616,  4617,  4618,
    4619,  4620,  4621,  4622,  4623,  4624,  4625,  4626,  4627,  4631,
    4638,  4639,  4640,  4641,  4642,  4643,  4644,  4647,  4648,  4649,
    4652,  4653,  4657,  4664,  4670,  4671,  4675,  4676,  4680,  4687,
    4691,  4698,  4699,  4703,  4710,  4711,  4715,  4716,  4720,  4721,
    4722,  4726,  4727,  4731,  4732,  4736,  4743,  4750,  4758,  4760,
    4759,  4780,  4781,  4785,  4786,  4791,  4793,  4792,  4849,  4867,
    4868,  4872,  4876,  4880,  4884,  4888,  4892,  4896,  4900,  4904,
    4908,  4912,  4916,  4920,  4924,  4928,  4932,  4936,  4941,  4945,
    4949,  4954,  4959,  4964,  4969,  4970,  4971,  4972,  4973,  4974,
    4975,  4976,  4977,  4984,  4989,  4998,  4999,  5003,  5004,  5009,
    5012,  5016,  5024,  5027,  5031,  5039,  5050,  5058,  5060,  5070,
    5059,  5097,  5097,  5130,  5134,  5133,  5147,  5146,  5166,  5167,
    5172,  5179,  5181,  5185,  5195,  5197,  5205,  5213,  5221,  5250,
    5281,  5283,  5293,  5298,  5325,  5327,  5326,  5363,  5364,  5368,
    5369,  5370,  5387,  5388,  5399,  5398,  5448,  5449,  5453,  5501,
    5514,  5517,  5536,  5541,  5535,  5554,  5554,  5584,  5591,  5592,
    5593,  5594,  5595,  5596,  5597,  5598,  5599,  5600,  5601,  5602,
    5603,  5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,
    5613,  5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,
    5623,  5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,  5632,
    5633,  5634,  5635,  5636,  5637,  5638,  5639,  5640,  5654,  5666,
    5665,  5681,  5687,  5691,  5695,  5700,  5705,  5710,  5715,  5719,
    5723,  5727,  5731,  5736,  5740,  5744,  5748,  5752,  5756,  5760,
    5767,  5768,  5775,  5776,  5780,  5781,  5785,  5786,  5787,  5788,
    5789,  5793,  5797,  5798,  5801,  5802,  5805,  5806,  5812,  5813,
    5817,  5818,  5822,  5826,  5832,  5836,  5840,  5844,  5848,  5852,
    5856,  5860,  5864,  5868,  5872,  5876,  5880,  5884,  5888,  5892,
    5896,  5902,  5906,  5910,  5914,  5918,  5922,  5926,  5933,  5934,
    5938,  5942,  5960,  5959,  5968,  5972,  5976,  5982,  5983,  5990,
    5994,  6005,  6004,  6013,  6017,  6029,  6030,  6038,  6037,  6046,
    6047,  6051,  6057,  6057,  6064,  6063,  6073,  6093,  6097,  6102,
    6107,  6128,  6132,  6131,  6148,  6149,  6154,  6162,  6186,  6188,
    6192,  6201,  6214,  6217,  6221,  6225,  6248,  6249,  6253,  6254,
    6259,  6262,  6270,  6274,  6282,  6286,  6297,  6296,  6304,  6308,
    6319,  6318,  6326,  6331,  6339,  6340,  6341,  6342,  6343,  6351,
    6350,  6359,  6366,  6370,  6380,  6391,  6409,  6408,  6417,  6421,
    6425,  6430,  6438,  6442,  6453,  6452,  6462,  6466,  6470,  6474,
    6478,  6482,  6483,  6492,  6494,  6493,  6501,  6510,  6517,  6521,
    6525,  6529,  6539,  6541,  6545,  6546,  6549,  6551,  6558,  6559,
    6563,  6564,  6569,  6573,  6577,  6581,  6585,  6589,  6593,  6597,
    6601,  6605,  6609,  6613,  6617,  6621,  6625,  6629,  6636,  6640,
    6651,  6650,  6659,  6663,  6667,  6671,  6675,  6682,  6686,  6697,
    6696,  6704,  6724,  6723,  6747,  6755,  6756,  6761,  6772,  6783,
    6797,  6801,  6808,  6809,  6814,  6823,  6832,  6837,  6846,  6847,
    6852,  6914,  6915,  6916,  6920,  6921,  6925,  6929,  6940,  6939,
    6951,  6952,  6973,  6987,  7009,  7031,  7051,  7074,  7075,  7083,
    7082,  7091,  7102,  7101,  7111,  7118,  7117,  7130,  7139,  7143,
    7154,  7170,  7169,  7178,  7182,  7186,  7193,  7197,  7208,  7207,
    7215,  7223,  7224,  7228,  7229,  7230,  7235,  7238,  7245,  7249,
    7257,  7264,  7265,  7266,  7267,  7268,  7269,  7270,  7275,  7278,
    7288,  7287,  7296,  7302,  7314,  7313,  7322,  7326,  7330,  7334,
    7341,  7342,  7343,  7344,  7351,  7350,  7364,  7374,  7383,  7384,
    7388,  7389,  7390,  7391,  7392,  7393,  7397,  7398,  7402,  7407,
    7414,  7415,  7416,  7417,  7418,  7422,  7450,  7453,  7460,  7464,
    7474,  7473,  7486,  7485,  7493,  7497,  7508,  7507,  7516,  7520,
    7527,  7531,  7542,  7541,  7549,  7570,  7594,  7595,  7596,  7597,
    7601,  7602,  7606,  7607,  7608,  7609,  7621,  7620,  7631,  7637,
    7636,  7647,  7655,  7663,  7670,  7674,  7687,  7694,  7706,  7709,
    7714,  7718,  7729,  7736,  7737,  7741,  7742,  7745,  7746,  7751,
    7762,  7761,  7770,  7797,  7798,  7803,  7806,  7810,  7814,  7818,
    7822,  7826,  7833,  7834,  7838,  7839,  7843,  7847,  7857,  7868,
    7867,  7875,  7885,  7896,  7895,  7904,  7911,  7915,  7926,  7925,
    7937,  7946,  7949,  7953,  7960,  7964,  7974,  7986,  7985,  7994,
    7998,  8007,  8008,  8013,  8016,  8024,  8028,  8035,  8043,  8047,
    8058,  8057,  8071,  8072,  8073,  8074,  8075,  8076,  8080,  8081,
    8085,  8086,  8092,  8101,  8108,  8109,  8113,  8117,  8121,  8125,
    8129,  8133,  8137,  8141,  8150,  8154,  8163,  8172,  8173,  8177,
    8186,  8187,  8191,  8195,  8206,  8205,  8214,  8213,  8244,  8247,
    8267,  8268,  8271,  8272,  8280,  8281,  8286,  8291,  8301,  8317,
    8322,  8332,  8349,  8348,  8358,  8371,  8374,  8382,  8385,  8390,
    8395,  8403,  8404,  8405,  8406,  8407,  8408,  8412,  8420,  8421,
    8425,  8429,  8440,  8439,  8449,  8462,  8465,  8469,  8477,  8489,
    8492,  8499,  8500,  8501,  8502,  8509,  8508,  8517,  8524,  8525,
    8529,  8530,  8531,  8535,  8536,  8540,  8544,  8555,  8554,  8563,
    8567,  8571,  8578,  8582,  8592,  8603,  8604,  8611,  8610,  8619,
    8625,  8637,  8636,  8644,  8658,  8657,  8665,  8678,  8680,  8681,
    8689,  8688,  8697,  8705,  8706,  8711,  8712,  8717,  8724,  8725,
    8730,  8737,  8738,  8742,  8743,  8747,  8748,  8752,  8756,  8767,
    8766,  8775,  8776,  8777,  8778,  8779,  8783,  8810,  8813,  8825,
    8835,  8840,  8845,  8850,  8858,  8896,  8897,  8901,  8941,  8951,
    8974,  8975,  8976,  8977,  8981,  8990,  8996,  9006,  9015,  9024,
    9025,  9032,  9031,  9043,  9053,  9054,  9059,  9062,  9066,  9070,
    9077,  9078,  9082,  9083,  9087,  9091,  9103,  9106,  9107,  9116,
    9117,  9126,  9129,  9130,  9139,  9140,  9151,  9154,  9155,  9164,
    9165,  9177,  9180,  9182,  9192,  9193,  9205,  9206,  9210,  9211,
    9212,  9216,  9225,  9236,  9237,  9238,  9242,  9251,  9262,  9267,
    9268,  9277,  9278,  9289,  9293,  9303,  9310,  9317,  9317,  9327,
    9328,  9329,  9333,  9342,  9343,  9345,  9346,  9347,  9348,  9349,
    9351,  9352,  9353,  9354,  9355,  9356,  9358,  9359,  9360,  9362,
    9363,  9364,  9365,  9366,  9369,  9370,  9374,  9375,  9379,  9380,
    9384,  9385,  9389,  9393,  9399,  9403,  9409,  9410,  9411,  9415,
    9416,  9417,  9421,  9422,  9423,  9427,  9431,  9435,  9436,  9437,
    9440,  9441,  9451,  9463,  9472,  9484,  9493,  9505,  9520,  9521,
    9526,  9535,  9541,  9561,  9565,  9586,  9627,  9641,  9642,  9647,
    9653,  9654,  9659,  9671,  9672,  9673,  9680,  9691,  9692,  9696,
    9704,  9712,  9716,  9723,  9732,  9733,  9739,  9753,  9770,  9774,
    9781,  9782,  9783,  9790,  9794,  9801,  9802,  9803,  9804,  9805,
    9809,  9813,  9817,  9821,  9825,  9846,  9850,  9857,  9858,  9859,
    9863,  9864,  9865,  9866,  9867,  9871,  9875,  9882,  9883,  9887,
    9888,  9892,  9893,  9897,  9898,  9909,  9910,  9914,  9915,  9916,
    9920,  9921,  9922,  9929,  9930,  9934,  9935,  9939,  9940,  9941,
    9947,  9951,  9955,  9956,  9960,  9964,  9971,  9978,  9985,  9995,
   10002, 10012, 10022, 10032, 10045, 10049, 10057, 10065, 10069, 10079,
   10094, 10117, 10140, 10156, 10157, 10158, 10159, 10160, 10161, 10165,
   10169, 10186, 10190, 10197, 10198, 10199, 10200, 10201, 10202, 10203,
   10209, 10213, 10217, 10221, 10225, 10229, 10233, 10237, 10241, 10245,
   10252, 10253, 10257, 10258, 10259, 10263, 10264, 10265, 10269, 10273,
   10277, 10284, 10288, 10292, 10299, 10306, 10313, 10323, 10330, 10340,
   10347, 10359, 10367, 10368, 10372, 10373, 10377, 10378, 10383, 10386,
   10394, 10397, 10404, 10406, 10407, 10411, 10412, 10416, 10417, 10418,
   10423, 10426, 10439, 10443, 10451, 10455, 10459, 10463, 10467, 10471,
   10475, 10479, 10486, 10487, 10493, 10494, 10495, 10496, 10497, 10498,
   10499, 10500, 10501, 10502, 10503, 10504, 10505, 10506, 10507, 10508,
   10509, 10510, 10511, 10512, 10513, 10514, 10515, 10516, 10517, 10518,
   10519, 10520, 10521, 10522, 10523, 10524, 10525, 10526, 10527, 10528,
   10529, 10530, 10531, 10532, 10533, 10534, 10535, 10536, 10537, 10538,
   10539, 10540, 10541, 10542, 10543, 10544, 10545, 10546, 10547, 10548,
   10549, 10550, 10551, 10552, 10553, 10554, 10555, 10556, 10557, 10558,
   10559, 10560, 10561, 10562, 10569, 10569, 10570, 10570, 10571, 10571,
   10572, 10572, 10573, 10573, 10574, 10574, 10575, 10575, 10576, 10576,
   10577, 10577, 10578, 10578, 10579, 10579, 10580, 10580, 10581, 10581,
   10582, 10582, 10583, 10583, 10584, 10584, 10585, 10585, 10586, 10586,
   10586, 10587, 10587, 10588, 10588, 10589, 10589, 10590, 10590, 10591,
   10591, 10591, 10592, 10592, 10593, 10593, 10593, 10594, 10594, 10594,
   10595, 10595, 10595, 10596, 10596, 10597, 10597, 10598, 10598, 10599,
   10599, 10599, 10600, 10600, 10601, 10601, 10602, 10602, 10602, 10602,
   10603, 10603, 10604, 10604, 10605, 10605, 10606, 10606, 10607, 10607,
   10608, 10608, 10609, 10609, 10610, 10610, 10610, 10611, 10611, 10612,
   10612, 10613, 10613, 10614, 10614, 10615, 10615, 10616, 10616, 10617,
   10617, 10618, 10618, 10618, 10619, 10619, 10620, 10620, 10621, 10621,
   10625, 10625, 10626, 10626, 10627, 10627, 10628, 10628, 10629, 10629,
   10630, 10630, 10631, 10631, 10632, 10632, 10633, 10633, 10634, 10634,
   10635, 10635, 10636, 10636, 10637, 10637, 10638, 10638, 10639, 10639,
   10640, 10640, 10643, 10644, 10645, 10649, 10649, 10650, 10650, 10651,
   10651, 10652, 10652, 10653, 10653, 10654, 10654, 10655, 10655, 10656,
   10656
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
  "SYMBOLIC", "SYNCHRONIZED", "\"SYSTEM-DEFAULT\"", "TAB", "TALLYING",
  "TAPE", "TERMINATE", "TEST", "THAN", "THEN", "THRU", "TIME", "TIMEOUT",
  "TIMES", "TO", "\"&\"", "\")\"", "\":\"", "\"/\"", "\".\"", "\"=\"",
  "\"FALSE\"", "\"FILE\"", "\">\"", "\"INITIAL\"", "\"<\"", "\"-\"",
  "\"*\"", "\"NULL\"", "\"OVERFLOW\"", "\"(\"", "\"+\"", "\"TRUE\"", "TOP",
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
     765,   766,   767
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   513,   515,   514,   516,   516,   517,   517,   518,   518,
     520,   519,   521,   522,   523,   524,   524,   524,   525,   525,
     526,   527,   527,   528,   530,   531,   532,   529,   534,   533,
     535,   536,   536,   537,   537,   538,   538,   539,   539,   539,
     539,   540,   540,   541,   541,   542,   542,   543,   543,   544,
     544,   544,   544,   544,   546,   545,   547,   547,   548,   548,
     550,   549,   551,   551,   551,   551,   552,   552,   553,   553,
     553,   553,   554,   555,   556,   557,   558,   558,   558,   558,
     559,   559,   561,   560,   562,   562,   562,   563,   563,   564,
     564,   564,   565,   565,   566,   566,   567,   567,   568,   569,
     569,   570,   570,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   573,   572,   574,   574,   574,
     574,   575,   575,   576,   576,   578,   577,   579,   579,   579,
     579,   579,   579,   580,   580,   581,   581,   582,   581,   583,
     583,   584,   584,   584,   584,   584,   584,   585,   586,   586,
     587,   588,   588,   589,   590,   590,   591,   591,   592,   593,
     593,   594,   594,   595,   596,   597,   597,   598,   599,   600,
     601,   602,   603,   604,   604,   605,   605,   606,   606,   607,
     607,   609,   608,   608,   610,   610,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   612,
     612,   612,   612,   612,   613,   613,   613,   613,   614,   614,
     615,   615,   615,   616,   616,   617,   617,   617,   618,   619,
     619,   619,   620,   621,   622,   623,   623,   623,   625,   624,
     626,   626,   626,   627,   627,   627,   627,   628,   628,   629,
     629,   629,   629,   630,   631,   632,   633,   633,   633,   634,
     635,   636,   636,   637,   638,   638,   638,   639,   639,   639,
     640,   640,   641,   641,   642,   643,   643,   643,   643,   645,
     644,   646,   646,   647,   648,   648,   649,   649,   650,   650,
     651,   651,   652,   654,   653,   653,   655,   655,   656,   656,
     657,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   658,   659,   659,   659,   660,   660,   660,   661,   661,
     662,   662,   663,   663,   664,   665,   665,   666,   666,   667,
     667,   668,   669,   670,   670,   671,   671,   671,   672,   673,
     674,   675,   676,   677,   678,   678,   679,   679,   680,   681,
     680,   682,   683,   682,   684,   684,   684,   685,   686,   685,
     685,   687,   688,   688,   688,   689,   690,   690,   691,   691,
     691,   691,   692,   692,   692,   692,   692,   692,   692,   692,
     692,   692,   692,   692,   692,   693,   693,   694,   694,   695,
     695,   695,   696,   696,   697,   698,   698,   699,   699,   700,
     700,   700,   700,   700,   700,   700,   700,   700,   700,   700,
     700,   700,   700,   701,   702,   703,   703,   704,   705,   706,
     706,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,   707,   707,   707,   707,   708,   708,   709,
     709,   710,   710,   711,   712,   712,   713,   714,   714,   715,
     715,   716,   717,   717,   718,   718,   719,   719,   720,   720,
     721,   722,   723,   724,   725,   727,   726,   728,   728,   729,
     729,   730,   730,   731,   731,   732,   732,   733,   734,   733,
     735,   736,   735,   737,   738,   737,   739,   739,   741,   740,
     742,   742,   742,   743,   743,   743,   743,   744,   745,   746,
     746,   747,   748,   748,   748,   749,   749,   750,   750,   750,
     750,   750,   751,   752,   753,   754,   755,   756,   756,   758,
     757,   759,   759,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   761,
     762,   762,   762,   762,   762,   762,   762,   763,   763,   763,
     764,   764,   765,   766,   767,   767,   768,   768,   769,   770,
     771,   772,   772,   773,   774,   774,   775,   775,   776,   776,
     776,   777,   777,   778,   778,   779,   780,   781,   782,   783,
     782,   784,   784,   785,   785,   786,   787,   786,   786,   788,
     788,   789,   789,   789,   789,   789,   789,   789,   789,   789,
     789,   789,   789,   789,   789,   789,   789,   789,   789,   789,
     789,   789,   789,   789,   789,   789,   789,   789,   789,   789,
     789,   789,   789,   789,   789,   790,   790,   791,   791,   792,
     792,   792,   793,   793,   793,   794,   795,   796,   797,   798,
     796,   799,   796,   800,   801,   800,   802,   800,   803,   803,
     804,   805,   805,   805,   806,   806,   806,   806,   806,   806,
     807,   807,   808,   808,   809,   810,   809,   811,   811,   812,
     812,   812,   812,   812,   814,   813,   815,   815,   816,   817,
     818,   818,   820,   821,   819,   823,   822,   822,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   826,
     825,   827,   827,   827,   827,   827,   827,   827,   827,   827,
     827,   827,   827,   827,   827,   827,   827,   827,   827,   827,
     828,   828,   829,   829,   830,   830,   831,   831,   831,   831,
     831,   832,   833,   833,   834,   834,   835,   835,   836,   836,
     837,   837,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   838,   838,   838,   838,   838,   838,   839,   839,
     840,   840,   842,   841,   843,   843,   843,   844,   844,   845,
     845,   847,   846,   848,   848,   849,   849,   851,   850,   852,
     852,   853,   854,   854,   856,   855,   857,   858,   858,   858,
     858,   859,   860,   859,   861,   861,   862,   862,   863,   863,
     863,   863,   864,   864,   864,   864,   865,   865,   866,   866,
     867,   867,   868,   868,   869,   869,   871,   870,   872,   872,
     874,   873,   875,   875,   876,   876,   876,   876,   876,   878,
     877,   879,   880,   880,   881,   882,   884,   883,   885,   885,
     886,   886,   887,   887,   889,   888,   890,   890,   890,   890,
     890,   890,   890,   891,   892,   891,   893,   894,   894,   894,
     894,   894,   895,   895,   896,   896,   897,   897,   898,   898,
     899,   899,   900,   900,   900,   900,   900,   900,   900,   900,
     900,   900,   900,   900,   900,   900,   900,   900,   901,   901,
     903,   902,   904,   904,   904,   904,   904,   905,   905,   907,
     906,   908,   910,   909,   911,   912,   912,   913,   913,   913,
     914,   914,   915,   915,   916,   917,   918,   918,   919,   919,
     920,   920,   920,   920,   921,   921,   922,   922,   924,   923,
     925,   925,   925,   925,   925,   925,   925,   926,   926,   928,
     927,   929,   931,   930,   932,   934,   933,   935,   936,   936,
     937,   939,   938,   940,   940,   940,   941,   941,   943,   942,
     944,   945,   945,   946,   946,   946,   947,   947,   948,   948,
     949,   950,   950,   950,   950,   950,   950,   950,   951,   951,
     953,   952,   954,   954,   956,   955,   957,   958,   958,   958,
     959,   959,   959,   959,   961,   960,   962,   963,   964,   964,
     965,   965,   965,   965,   965,   965,   966,   966,   967,   967,
     968,   968,   968,   968,   968,   969,   970,   970,   971,   971,
     973,   972,   975,   974,   976,   976,   978,   977,   979,   979,
     980,   980,   982,   981,   983,   983,   984,   984,   984,   984,
     985,   985,   986,   986,   986,   986,   988,   987,   989,   990,
     989,   989,   991,   991,   992,   992,   993,   993,   994,   994,
     994,   994,   994,   995,   995,   996,   996,   997,   997,   998,
    1000,   999,  1001,  1002,  1002,  1003,  1003,  1003,  1003,  1003,
    1003,  1003,  1004,  1004,  1005,  1005,  1006,  1006,  1007,  1009,
    1008,  1010,  1011,  1013,  1012,  1014,  1015,  1015,  1017,  1016,
    1018,  1019,  1019,  1019,  1020,  1020,  1021,  1023,  1022,  1024,
    1024,  1025,  1025,  1026,  1026,  1027,  1027,  1028,  1029,  1029,
    1031,  1030,  1032,  1032,  1032,  1032,  1032,  1032,  1033,  1033,
    1034,  1034,  1035,  1036,  1037,  1037,  1038,  1038,  1038,  1038,
    1038,  1038,  1038,  1038,  1039,  1039,  1040,  1041,  1041,  1042,
    1043,  1043,  1044,  1044,  1046,  1045,  1048,  1047,  1049,  1049,
    1050,  1050,  1051,  1051,  1052,  1052,  1053,  1053,  1053,  1054,
    1054,  1054,  1056,  1055,  1057,  1058,  1058,  1059,  1059,  1059,
    1059,  1060,  1060,  1060,  1060,  1060,  1060,  1061,  1062,  1062,
    1063,  1063,  1065,  1064,  1064,  1066,  1066,  1066,  1066,  1067,
    1067,  1068,  1068,  1068,  1068,  1070,  1069,  1071,  1072,  1072,
    1073,  1073,  1073,  1074,  1074,  1075,  1075,  1077,  1076,  1078,
    1078,  1078,  1079,  1079,  1080,  1081,  1081,  1083,  1082,  1084,
    1084,  1086,  1085,  1087,  1089,  1088,  1090,  1091,  1091,  1091,
    1093,  1092,  1094,  1095,  1095,  1096,  1096,  1097,  1098,  1098,
    1099,  1100,  1100,  1101,  1101,  1102,  1102,  1103,  1103,  1105,
    1104,  1106,  1106,  1106,  1106,  1106,  1107,  1108,  1108,  1109,
    1109,  1109,  1109,  1109,  1110,  1111,  1111,  1112,  1112,  1112,
    1113,  1113,  1113,  1113,  1114,  1115,  1115,  1116,  1117,  1118,
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
    1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1264,  1264,
    1264,  1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,  1269,
    1269,  1269,  1270,  1270,  1271,  1271,  1271,  1272,  1272,  1272,
    1273,  1273,  1273,  1274,  1274,  1275,  1275,  1276,  1276,  1277,
    1277,  1277,  1278,  1278,  1279,  1279,  1280,  1280,  1280,  1280,
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
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     1,     1,
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
       0,     3,     0,     3,     2,     1,     0,     3,     2,     0,
       4,     2,     0,     1,     1,     1,     1,     3,     0,     2,
       1,     3,     3,     0,     3,     1,     1,     1,     3,     7,
       0,     4,     7,     0,     2,     0,     2,     2,     3,     3,
       3,     2,     0,     3,     1,     1,     0,     1,     1,     0,
       3,     2,     1,     0,     4,     4,     0,     1,     0,     4,
       4,     0,     2,     3,     0,     1,     1,     0,     4,     4,
       6,     0,     2,     0,     2,     1,     2,     3,     0,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     3,     4,     1,     2,     3,
       1,     2,     3,     3,     0,     3,     0,     7,     0,     5,
       0,     2,     0,     2,     0,     3,     0,     2,     4,     0,
       2,     4,     0,     4,     4,     0,     3,     0,     4,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     1,
       0,     1,     0,     4,     2,     0,     2,     4,     4,     0,
       1,     1,     1,     1,     1,     0,     4,     5,     1,     2,
       1,     3,     3,     0,     4,     0,     1,     0,     4,     4,
       6,     6,     0,     1,     2,     0,     1,     0,     3,     1,
       2,     0,     3,     5,     0,     3,     2,     0,     1,     1,
       0,     4,     6,     0,     3,     1,     3,     2,     2,     2,
       3,     0,     3,     0,     3,     0,     3,     0,     1,     0,
       3,     1,     1,     1,     1,     1,     7,     0,     1,     1,
       1,     1,     1,     1,     4,     1,     2,     1,     2,     3,
       0,     1,     2,     1,     3,     1,     1,     4,     1,     1,
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
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     1,     0,     1,     0,     1,     1,     0,     1,     1,
       0,     2,     2,     0,     1,     0,     1,     0,     1,     0,
       1,     1,     0,     1,     0,     1,     0,     2,     1,     1,
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,    10,     1,     0,     0,     3,     5,     6,     4,
      43,     8,     9,    43,    43,     0,     0,     7,     0,    11,
      45,    15,    21,    32,    31,    33,    33,     0,     0,    47,
      16,    18,    43,     0,    14,    22,     0,     0,    28,    44,
       0,   173,     0,    17,    12,    19,    15,     0,    34,    30,
    1767,    46,     0,     0,     0,  1810,  1767,  1767,  1767,     0,
       0,     0,     0,     0,  1767,     0,     0,  1742,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1768,     0,     0,  1496,   125,  1767,
    1767,  1811,  1767,     0,     0,     0,     0,  1767,  1767,    60,
      82,     0,    54,    98,  1743,     0,  1767,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1804,    39,  1767,     0,     0,     0,  1564,   169,  1489,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1497,
     150,   151,  1769,   154,  1569,  1189,  1188,   116,   120,  1796,
    1767,     0,   100,   149,   176,   177,    38,  1805,    36,     0,
    1576,  1572,  1577,  1575,  1573,  1578,  1574,   158,   159,   161,
     170,   165,  1852,  1853,     0,   163,     0,  1741,     0,     0,
       0,  1767,  1874,    80,    61,  1740,    66,    68,    69,    70,
      71,  1740,     0,  1767,     0,    83,     0,    87,    55,    58,
     152,  1771,  1770,   155,     0,  1796,  1799,  1798,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1839,   164,     0,  1565,   168,  1873,  1767,
       0,     0,    65,    67,    63,    81,  1740,  1767,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1570,
     153,   156,     0,  1797,   123,   118,   119,   122,   178,     0,
       0,  1638,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1872,    74,    64,     0,
    1490,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1639,   181,  1748,   266,   267,   268,  1730,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1749,  1823,  1731,  1752,
       0,   278,   259,   138,   139,  1860,  1861,    72,  1806,  1824,
    1744,  1753,     0,     0,     0,   280,     0,  1785,  1806,  1831,
       0,   239,     0,  1767,  1740,  1772,   241,     0,  1841,  1838,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1736,  1767,  1745,     0,  1475,   264,  1473,   277,     0,    25,
     140,  1786,  1767,  1807,  1772,  1832,  1833,   210,  1840,   242,
    1806,  1767,  1767,  1773,  1767,  1767,   251,  1730,   252,     0,
    1767,  1785,  1737,     0,     0,   270,   271,   274,  1474,   279,
     286,   287,   338,   281,   341,     0,     0,  1767,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1800,  1800,
       0,   253,     0,  1767,   240,   223,   272,     0,   273,     0,
     487,   282,  1621,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1495,  1494,   243,   244,   245,   246,   249,  1801,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1624,   216,   201,   217,   202,  1748,
     203,   200,   213,   199,   214,  1767,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1767,  1871,     0,   222,  1625,   209,
       0,   247,  1487,     0,   231,   230,   341,   488,     0,     0,
     588,   345,   350,   387,   356,  1744,  1767,     0,     0,  1767,
    1744,  1785,  1767,  1728,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1870,   248,
    1488,     0,   236,   340,   341,   491,     0,     0,    26,  1767,
    1732,     0,     0,     0,  1767,  1728,     0,     0,     0,     0,
       0,  1767,   334,  1729,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   651,     0,   474,   411,  1812,
    1812,  1812,  1812,  1812,  1834,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1808,   446,     0,   422,   408,   423,   424,     0,
       0,  1815,   426,   427,   425,  1774,   429,   430,   428,  1767,
    1769,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1733,     0,   384,     0,   357,   312,   332,  1862,  1863,
    1493,   321,  1491,  1855,  1854,   314,  1783,  1742,  1756,     0,
    1767,   318,   317,  1767,   337,     0,  1858,  1859,   234,   492,
     496,   589,     0,    27,   695,   485,   486,  1813,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1835,     0,
    1809,   471,   457,   403,  1558,   483,  1816,  1775,  1776,   472,
       0,     0,   405,   407,  1652,  1652,   386,     0,  1792,  1587,
       0,     0,  1583,  1588,  1586,  1584,  1589,  1585,   385,   358,
    1579,  1581,     0,   302,  1492,  1784,   323,     0,   305,  1757,
    1817,   331,     0,     0,   235,   495,   591,   653,     0,     0,
     473,     0,  1827,     0,  1556,  1557,     0,   410,   475,   477,
     479,     0,   404,  1740,   451,   452,  1580,  1793,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1742,
    1818,   310,   319,   316,   320,   315,     0,   497,     0,   595,
     590,   592,     0,   656,   654,   672,     0,   749,   822,   831,
     837,   844,   876,   880,   894,   889,   895,   896,   904,   950,
     959,   962,   988,   999,  1002,  1005,   997,  1011,  1018,  1040,
    1044,  1080,  1082,  1086,     0,  1092,  1106,  1130,  1148,  1149,
    1152,  1153,  1158,  1166,  1167,  1180,  1214,  1232,     0,  1265,
    1277,  1285,  1287,   677,  1291,  1294,  1300,  1351,   697,   698,
     699,   700,   701,   702,   703,   704,   706,   705,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   696,   458,
    1828,   459,  1605,  1600,  1611,     0,  1462,  1464,     0,     0,
       0,  1603,     0,  1466,  1604,  1606,  1607,     0,     0,     0,
       0,  1602,  1611,  1601,  1446,  1444,  1451,  1454,  1456,  1459,
    1523,  1461,  1520,  1554,  1521,  1522,  1608,     0,     0,     0,
    1555,   484,   481,   478,     0,   406,  1653,   361,   374,  1582,
       0,     0,   324,   325,   326,   327,     0,   306,  1755,   312,
       0,  1476,   498,     0,   596,     0,   593,   661,   661,     0,
       0,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1704,  1705,  1706,  1707,  1708,
    1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,  1722,  1723,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1654,  1700,  1701,  1702,
    1703,   748,     0,     0,     0,     0,   847,     0,     0,     0,
       0,     0,     0,     0,  1407,   990,     0,     0,  1829,   867,
     866,     0,  1010,  1407,     0,     0,     0,     0,     0,     0,
     747,     0,  1118,     0,     0,     0,     0,     0,     0,     0,
       0,  1261,  1264,  1252,  1262,  1263,  1254,     0,     0,  1286,
    1284,     0,   695,     0,     0,     0,     0,  1794,   462,     0,
    1598,  1524,  1525,  1526,     0,     0,     0,     0,     0,     0,
       0,  1458,     0,  1457,     0,  1599,  1447,  1448,  1566,     0,
       0,     0,     0,     0,     0,     0,     0,  1590,     0,     0,
       0,     0,   476,     0,   480,   330,   329,  1734,  1742,   311,
       0,   598,   599,   594,  1739,   661,   658,   664,     0,   661,
     673,   648,   771,   820,   774,   770,  1792,     0,     0,  1514,
     829,  1508,   827,  1503,  1505,  1506,  1507,   832,     0,  1626,
    1486,   838,   839,     0,  1482,  1484,  1483,   850,   848,   849,
     874,     0,  1536,   877,   878,  1535,   881,   884,  1792,   892,
       0,  1468,  1640,  1500,  1559,  1563,  1501,     0,   902,  1806,
    1583,   948,  1372,   913,   917,  1503,     0,  1505,   957,     0,
     851,   960,   969,   968,   986,     0,   965,   967,  1406,     0,
     992,   996,   994,   997,   995,   989,  1000,  1001,  1498,  1003,
    1004,  1830,  1006,  1480,   998,  1825,  1405,  1019,  1021,  1041,
    1042,  1045,     0,  1047,  1048,  1049,  1081,  1218,  1551,  1552,
       0,  1083,     0,  1090,     0,  1099,  1096,  1098,  1097,  1093,
    1100,  1120,  1486,  1107,  1118,  1109,     0,  1116,     0,  1537,
    1483,  1539,     0,  1146,  1632,  1150,  1354,  1471,  1156,  1806,
    1164,  1354,     0,  1178,  1171,  1472,     0,  1479,  1181,  1182,
    1183,  1184,  1185,  1186,  1207,  1187,  1210,     0,  1477,     0,
       0,  1550,  1563,  1215,  1250,  1237,  1255,  1738,  1275,     0,
    1268,  1270,     0,  1282,     0,  1288,  1289,   683,   689,   678,
     679,   680,   682,     0,  1292,     0,  1295,  1297,  1317,  1303,
    1364,  1354,  1795,     0,   466,   461,  1613,  1446,  1444,  1463,
    1465,  1446,     0,     0,     0,  1446,  1517,  1518,  1519,     0,
    1467,  1460,  1446,     0,  1445,  1567,     0,  1450,  1449,  1453,
    1452,  1455,     0,     0,  1446,     0,  1767,  1735,     0,   308,
       0,  1767,  1814,   659,  1767,     0,   670,   662,   663,   674,
     821,   750,  1735,   784,   775,     0,     0,     0,     0,  1509,
    1510,  1511,   830,   823,     0,     0,  1504,  1628,  1627,   835,
     840,   842,     0,   875,   845,  1538,   851,   879,   884,  1864,
    1865,   882,     0,   885,     0,   893,   890,  1847,  1846,  1469,
       0,  1642,  1470,  1561,  1562,   899,   900,   903,   897,  1399,
     949,   905,   692,     0,   911,  1374,     0,   928,     0,   922,
    1372,  1372,  1372,  1372,   958,   951,     0,     0,   852,   961,
     987,   963,  1407,  1407,   964,   971,   972,   692,  1431,  1432,
    1433,  1427,  1829,  1419,  1439,  1442,  1441,  1443,  1435,  1426,
    1425,  1430,  1429,  1428,  1434,  1414,  1418,  1436,  1438,  1440,
    1416,  1417,  1413,  1415,  1408,  1409,  1420,  1421,  1422,  1423,
    1424,  1412,   993,   991,  1499,  1008,  1826,   692,  1023,     0,
    1043,     0,  1070,  1054,  1046,  1051,  1052,  1053,  1222,     0,
    1553,     0,     0,  1091,  1087,     0,  1100,  1838,     0,  1108,
    1114,  1115,   692,  1111,  1407,     0,     0,  1119,     0,  1147,
    1131,  1633,  1634,  1806,     0,  1151,  1157,  1154,  1133,  1165,
    1159,  1161,  1173,  1179,  1168,     0,  1173,     0,  1531,  1532,
    1208,  1211,     0,     0,  1478,  1191,     0,  1190,     0,     0,
    1561,  1251,  1233,  1239,  1767,  1240,  1235,     0,  1253,     0,
       0,  1276,  1266,     0,  1269,     0,  1283,  1278,     0,  1290,
     690,   688,   681,     0,  1298,  1299,  1296,  1318,  1301,  1738,
       0,  1365,  1352,  1356,   460,  1738,   456,   464,   465,  1772,
    1612,     0,  1608,  1608,  1608,     0,  1594,     0,  1608,  1568,
       0,  1608,  1608,  1837,     0,   328,  1794,   307,   502,  1767,
    1767,  1728,  1780,   527,   501,   505,   506,     0,  1750,   613,
    1767,   603,  1834,   604,  1843,  1842,     0,  1767,     0,   616,
     607,   612,  1787,   608,     0,   611,   618,   615,   609,   614,
       0,   619,   610,     0,   630,   624,   628,   627,   625,   629,
     600,   631,   626,     0,  1787,     0,  1767,   671,     0,     0,
     649,   780,   785,   786,  1787,  1787,   778,   779,  1787,   766,
    1367,  1845,  1844,   763,   755,   757,   758,     0,  1367,     0,
       0,     0,   772,   761,     0,   769,   752,   768,   753,  1528,
    1527,     0,  1513,     0,  1792,  1377,   828,  1563,  1501,     0,
    1630,   835,     0,   833,     0,     0,  1485,   862,   883,   888,
       0,     0,  1502,  1377,  1767,  1641,  1560,   901,   692,   898,
    1401,  1373,   693,   915,  1734,   692,  1371,   921,   920,   919,
     918,   929,  1372,  1767,   932,     0,   935,   936,     0,  1767,
     939,   940,   941,   942,     0,   943,  1372,   930,     0,   786,
     908,   909,   906,   907,     0,  1377,     0,   858,   966,   981,
     983,   982,   976,   978,   984,  1407,   973,   970,  1407,   974,
    1437,  1410,  1411,  1794,  1007,  1481,   692,  1015,  1016,  1829,
    1031,  1032,  1034,  1036,  1037,  1033,  1035,  1026,  1829,  1022,
       0,  1071,     0,  1073,  1072,  1074,  1056,  1066,     0,     0,
    1050,  1224,     0,  1758,     0,  1084,  1377,     0,     0,     0,
    1102,  1112,  1125,  1121,  1126,  1122,  1127,     0,  1117,  1361,
    1360,  1124,  1133,  1355,  1547,  1548,  1549,     0,     0,  1399,
       0,   692,     0,  1172,     0,     0,     0,  1209,     0,  1213,
    1212,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1193,  1194,  1635,  1399,     0,  1256,  1821,  1821,  1271,
    1272,  1273,     0,  1377,     0,     0,   691,     0,  1622,     0,
    1273,  1161,  1724,     0,  1767,  1620,  1595,  1596,  1597,  1618,
    1615,  1616,  1593,  1609,     0,  1591,  1592,   482,     0,     0,
    1889,  1890,  1767,  1728,     0,   499,   503,  1751,   507,     0,
       0,   601,   602,   605,   606,     0,   633,  1788,  1767,  1827,
    1767,   634,   632,   646,  1767,   665,   666,   669,     0,   660,
     675,   677,  1767,   788,     0,     0,   776,   777,     0,   692,
     767,  1369,   754,   756,  1367,   764,   759,   760,   773,   762,
    1530,  1512,  1529,  1640,     0,   692,   824,  1379,  1561,  1562,
    1377,     0,  1629,   834,   836,   843,   841,   870,  1765,   887,
     886,   891,     0,  1400,   692,  1398,   695,  1375,   910,     0,
     933,   934,   937,   938,     0,  1403,  1403,   931,   912,   924,
     925,   923,   926,     0,   952,     0,   853,   854,   664,     0,
    1407,  1407,   980,   692,   977,     0,  1014,   692,  1017,  1012,
       0,     0,  1038,     0,     0,     0,  1067,  1069,     0,  1062,
    1076,  1063,  1064,  1055,  1058,  1076,  1216,  1767,  1772,     0,
    1759,  1223,  1085,  1088,     0,  1102,  1101,  1105,  1094,     0,
    1113,  1110,     0,     0,  1135,  1134,   692,  1155,  1387,  1160,
    1162,     0,  1174,  1407,  1407,  1169,  1175,  1192,  1204,  1206,
    1196,  1197,  1198,  1202,  1199,  1203,  1200,  1201,  1195,  1636,
    1249,     0,  1246,  1247,  1241,     0,  1234,  1869,  1868,     0,
    1822,  1259,  1259,  1382,     0,  1640,  1279,     0,   684,     0,
    1623,  1304,  1305,     0,  1308,  1311,  1315,  1309,  1399,  1725,
       0,   470,   467,   468,     0,  1610,   309,   504,  1781,  1782,
    1571,   515,   512,   352,   528,   508,   509,  1542,   623,  1540,
    1541,   622,   639,   645,     0,   642,   667,   668,   677,   695,
       0,     0,  1367,   781,   783,   782,  1368,   692,  1366,   765,
    1377,  1502,  1378,   692,  1376,  1560,   825,  1631,  1533,  1534,
    1850,  1851,   872,   692,  1792,  1766,   869,   868,   864,     0,
    1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1643,  1402,
       0,   945,   944,   947,     0,  1545,  1546,   946,     0,   916,
    1377,  1468,  1377,  1468,   855,   856,     0,   860,   859,   861,
     979,   985,   975,  1009,  1013,  1024,  1027,  1028,  1746,  1020,
    1829,  1025,  1076,  1076,     0,  1061,  1059,  1060,  1065,  1226,
       0,  1220,  1760,  1377,  1095,  1104,     0,  1128,     0,     0,
    1142,     0,  1391,   692,  1386,  1163,   692,   692,  1176,  1248,
    1238,  1242,  1243,  1244,  1245,  1236,  1257,  1260,  1258,   692,
    1267,  1384,  1767,  1377,  1377,   686,  1293,  1622,  1307,  1756,
    1313,  1756,  1382,   692,   692,  1353,  1363,  1394,  1395,  1362,
    1359,  1358,  1777,   469,   463,   511,  1856,  1857,   514,   354,
     529,   510,   637,   635,   638,   636,   640,   641,     0,   617,
     643,   644,     0,   695,   787,   792,  1767,   794,   795,   796,
     819,  1767,   797,   798,   799,   800,   801,     0,   802,   803,
     805,   806,   807,     0,   808,   793,  1726,   809,   818,   812,
     789,   790,   811,   751,  1370,   826,  1380,   692,   846,   871,
       0,   863,  1866,  1867,  1404,   927,   954,     0,   953,     0,
     857,  1029,  1747,     0,     0,  1057,  1068,  1076,  1763,  1763,
    1077,     0,     0,  1229,  1225,  1219,  1089,  1103,     0,  1136,
    1767,  1399,     0,     0,  1137,     0,  1141,  1392,  1170,  1177,
    1383,   692,  1381,     0,  1281,  1280,  1319,   685,     0,  1306,
       0,  1756,  1310,     0,  1302,  1396,  1397,  1393,  1778,  1779,
    1357,     0,  1767,  1767,     0,   516,   517,   518,   519,   520,
     521,     0,   531,   620,   621,     0,     0,     0,   810,  1767,
    1403,  1403,  1727,     0,   791,   873,   865,  1377,  1377,     0,
    1039,  1075,  1764,     0,     0,  1767,  1227,     0,     0,  1217,
    1221,     0,     0,  1132,  1145,  1389,  1390,  1144,  1140,  1138,
    1139,  1385,  1274,  1327,   687,  1312,     0,  1316,  1876,  1875,
    1767,     0,     0,  1878,     0,  1767,  1767,   513,  1814,     0,
     814,   813,     0,   816,   815,   817,  1543,  1544,   956,   955,
    1030,  1079,  1078,     0,  1230,  1767,  1407,  1143,  1388,  1350,
    1349,  1328,  1320,  1321,  1726,  1322,  1323,  1324,  1325,  1348,
       0,     0,  1314,     0,   526,   522,  1877,     0,     0,  1761,
    1789,  1728,     0,     0,     0,  1767,  1792,   530,  1767,  1767,
       0,   536,   538,   547,   539,   541,   544,   532,   533,   534,
     543,   545,   548,   535,     0,   540,     0,   542,   546,   537,
    1789,  1728,   676,   804,  1228,     0,  1129,     0,  1819,     0,
    1794,   523,   525,   524,  1762,   586,  1790,  1791,  1769,   572,
    1767,   457,  1407,     0,     0,     0,     0,     0,   580,     0,
     570,   576,   579,     0,   573,   581,   584,  1769,   575,  1231,
       0,  1820,     0,  1346,  1345,  1344,     0,   571,     0,  1827,
     568,  1640,   564,  1515,  1880,     0,     0,  1882,  1884,     0,
    1888,  1886,   549,   553,   557,   557,   551,   555,   550,   556,
     587,     0,   578,   577,   583,   582,   574,  1347,  1849,  1848,
    1802,  1340,  1334,  1335,  1337,   562,   459,   585,  1794,   563,
    1516,  1879,  1883,  1881,  1887,  1885,   560,   552,   560,   554,
       0,  1803,  1794,  1343,  1338,  1341,     0,  1336,   454,     0,
       0,   559,   558,     0,     0,  1342,  1339,     0,   453,   567,
     565,   566,   561,   569,  1333,  1330,  1332,  1331,  1326,  1329,
     455
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
     792,   664,   665,   666,   667,   668,   669,   670,  2553,  2688,
     671,   782,  1148,  1384,  1385,  1649,  1646,  2152,  2153,   672,
     673,   674,   675,   676,   992,   788,   789,  1182,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1190,  1421,
    1674,  1675,  1958,  2165,  1676,  2161,  2315,  2435,  2436,  2437,
    2438,  2439,  2440,  1955,  2164,  2442,  2498,  2557,  2558,  2632,
    2667,  2681,  2559,  2560,  2659,  2690,  2561,  2562,  2563,  2564,
    2565,  2566,  2600,  2601,  2604,  2605,  2567,  2568,  2569,   588,
     776,   840,   841,   842,  1192,  1422,  1710,  2326,  2327,  2328,
    2332,  1711,  1712,   713,  1429,  1981,   714,   845,  1018,  1017,
    1195,  1196,  1197,  1426,  1718,  1020,  1720,  2178,  1142,  1369,
    1370,  2295,  2417,  1371,  1372,  1925,  1781,  1782,  2026,  1373,
     779,   898,   899,  1092,  1203,  1204,  1746,  1433,  1489,  1726,
    1727,  1723,  1983,  2182,  2360,  2361,  2362,  1431,   900,  1093,
    1210,  1445,  1443,   901,  1094,  1217,  1763,   902,  1095,  1221,
    1222,  1765,   903,  1096,  1230,  1231,  1499,  1817,  2046,  2047,
    2048,  2017,  1111,  2208,  2202,  2368,  1454,   904,  1097,  1233,
     905,  1098,  1236,  1461,   906,  1099,  1239,  1466,   907,   908,
     909,  1100,  1248,  1475,  1478,   910,  1101,  1251,  1252,  1483,
    1253,  1487,  1809,  2041,  2229,  1792,  1806,  1807,  1481,   911,
    1102,  1258,  1495,   912,  1103,  1261,   913,  1104,  1264,  1265,
    1266,  1504,  1505,  1506,  1827,  1507,  1822,  1823,  2052,  1501,
     914,  1105,  1275,  1112,   915,  1106,  1276,   916,  1107,  1279,
     917,  1108,  1282,  1834,   918,   919,  1113,  1838,  2059,   920,
    1114,  1287,  1548,  1847,  2062,  2246,  2247,  2248,  2249,   921,
    1115,  1289,   922,  1116,  1291,  1292,  1554,  1555,  1859,  1556,
    1557,  2073,  2074,  1856,  1857,  1858,  2067,  2255,  2390,   923,
    1117,   924,  1118,  1301,   925,  1119,  1303,  1564,   926,  1121,
    1309,  1310,  1568,  2088,   927,  1122,  1313,  1572,  2091,  1573,
    1314,  1315,  1316,  1873,  1875,  1876,   928,  1123,  1323,  1888,
    2270,  2401,  2473,  1580,   929,   930,  1124,  1325,   931,   932,
    1125,  1328,  1587,   933,  1126,  1330,  1889,  1590,   934,   935,
    1127,  1333,  1596,  1892,  2105,  2106,  1594,   936,  1128,  1338,
     159,  1608,  1339,  1340,  1911,  1912,  1341,  1342,  1343,  1344,
    1345,  1346,   937,  1129,  1296,  2259,  1558,  2395,  1861,  2076,
    2393,  2469,   938,  1130,  1354,  1914,  1616,  2121,  2122,  2123,
    1612,   939,  1356,  1618,  2286,  1136,   940,  1137,  1358,  1359,
    1360,  2133,  1622,   941,  1138,  1363,  1627,   942,  1140,   943,
    1141,  1365,   944,  1143,  1374,   945,  1144,  1376,  1636,   946,
    1145,  1378,  1640,  2141,  2142,  1930,  2144,  2300,  2422,  2302,
    1638,  2418,  2483,  2522,  2523,  2524,  2698,  2525,  2652,  2653,
    2676,  2526,  2615,  2527,  2528,  2529,   947,  1146,  1380,  1585,
    1931,  1881,  2305,  1642,  1990,  1991,  2188,  1484,  1485,  1786,
    2006,  2007,  2194,  2290,  2291,  2412,  2097,  2474,  2098,  2274,
    2306,  2307,  2308,  1779,  1780,  2025,  2223,  1285,  1286,  1268,
    1269,  1534,  1535,  1536,  1537,  1538,  1539,  1540,   974,  1169,
    1388,   976,   977,   978,   979,  1211,  1240,  1469,  1326,  1334,
     395,   396,  1012,  1347,  1348,  1545,  1317,  1224,  1225,   541,
     481,   301,   691,   692,   482,    98,   153,  1277,  1242,  1212,
    1446,  2622,  1395,   981,  1751,  2001,  2075,  2197,  1234,  1318,
    2168,  2505,  2224,  1883,  2169,  1297,  1351,  1214,   983,  1243,
    1244,   734,   784,   785,  2170,   271,  2602,   179,  1215,   760,
     761,  1216,   986,   987,   988,  1177,  1150,  1403,  1399,  1392,
     501,  2143,   537,  1449,  1761,  2012,  1583,  2125,   282,  1472,
    1775,  2218,   794,  1091,  2150,  2453,   604,   339,   684,  1435,
     423,  1198,   202,   115,   393,  2383,   337,  1959,   352,  1010,
     770,  2081,  2585,  2463,  2209,    96,   214,   414,   739,  2430,
    1954,   766,   402,  1968,  2588,   798,  1383,   218,   488,  2672,
     168,   390,   731,   102,   719,   680,   831,  2612,  2131,   350,
    1547,   951,  1283,   407,   729,  1183,  1322,   391,  1728,  1748,
    1470,  2650,  2203,   184,   695,  2318,   708,   347,   596,  1463,
    2374,  2129,   538,   203,  2490,  2496,  2635,  2636,  2637,  2638,
    2639,  1678
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2263
static const yytype_int16 yypact[] =
{
   -2263,   258,   -10, -2263,  -187,   302, -2263,   -10, -2263, -2263,
     614, -2263, -2263,   614,   614,   -64,   -64, -2263,   684, -2263,
     855,   568,   840, -2263, -2263,  1006,  1006,   587,   756, -2263,
   -2263,    36,   614,   -64, -2263, -2263,   952,   759, -2263, -2263,
     806,  1308,   -64, -2263, -2263, -2263,   568,   839, -2263, -2263,
     -27, -2263,   772,   772,   880,   930,  1118,  1118,  1118,   986,
     772,   981,   958,   998,  1118,  1005,  1012,  1350, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   982, -2263, -2263, -2263, -2263,
    1249, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1319,  1062,    36, -2263, -2263,  1072,   287, -2263, -2263,  1118,
    1118, -2263,  1118,  1028,  1443,  1028,  1112,  1118,  1118, -2263,
   -2263,  1028, -2263, -2263, -2263,  1078,  1149,  1135, -2263, -2263,
    1089, -2263,  1159, -2263, -2263, -2263, -2263,  -133, -2263, -2263,
   -2263,  1227, -2263,  1118,   761,  1028,  1358,    12, -2263, -2263,
   -2263, -2263, -2263,  1367,  1148,   421,  1428, -2263,  1124, -2263,
    1078, -2263,    72, -2263, -2263, -2263, -2263, -2263,   854,   -66,
    1118,    18, -2263, -2263, -2263,   480, -2263, -2263, -2263,    47,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,   761, -2263,  1191,
   -2263,   319, -2263, -2263,  1028, -2263,  1239, -2263,  1244,  1237,
    1586,  1118, -2263, -2263, -2263,   886, -2263, -2263, -2263, -2263,
   -2263,   811,  1594,  1118,    59, -2263,    90, -2263, -2263,   149,
   -2263, -2263, -2263, -2263,  1398,   -66, -2263,  1425,   772,   772,
   -2263,   854,  1209,    62,   -90, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   638, -2263,
     110, -2263,   761, -2263, -2263,  1335, -2263, -2263, -2263,  1118,
    1263,  1413, -2263, -2263, -2263, -2263,   911,  1118,  1166,  1444,
     576, -2263,  1648,   640,  1230, -2263, -2263,  1231,  1572, -2263,
    1398, -2263,   772, -2263, -2263, -2263, -2263,   854, -2263,  1233,
    1374, -2263,   772, -2263,   699, -2263,   146, -2263, -2263, -2263,
   -2263, -2263,   638, -2263,  1437,  1413, -2263, -2263, -2263,   695,
   -2263, -2263, -2263,  1439, -2263, -2263, -2263, -2263, -2263,  1431,
   -2263, -2263, -2263, -2263, -2263,  1242, -2263, -2263, -2263,  1681,
    1603,  1255, -2263, -2263,   638, -2263, -2263,    44, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1271, -2263,  1522,
    1589,  1258, -2263,  1697, -2263, -2263, -2263, -2263,  1631, -2263,
    1629, -2263,  1212,  1266,  1322, -2263,   638,  1452,  1377,   726,
    1328, -2263,  1331,  1118,  1674,    69,   -78,   946, -2263,  1232,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1311,
   -2263,  1473, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1698,  1118, -2263,  1212, -2263,  1212, -2263, -2263,  1288,   288,
   -2263, -2263,  1118, -2263,  1506, -2263, -2263,   882, -2263, -2263,
     837,  1118,  1118, -2263,  1118,  1118, -2263,  1681, -2263,   119,
    1118,  1452, -2263,  1342,  1241,  1212, -2263,  1416, -2263, -2263,
   -2263, -2263,  1252, -2263,  1251,    65,    92,  1118, -2263, -2263,
     817, -2263, -2263,   -53,  1347,  1028,  1028, -2263,  1449,  1449,
    1450, -2263,  1028,  1118, -2263, -2263, -2263,  1413, -2263,  1375,
    1507, -2263, -2263,  1321, -2263, -2263, -2263, -2263, -2263,  1028,
   -2263, -2263,   205,   205,  1767,   205, -2263, -2263,   205,   332,
   -2263, -2263, -2263, -2263, -2263,  -171, -2263, -2263, -2263, -2263,
   -2263, -2263,   713, -2263,  1323,  1382,  1527,   268,  1325,  6200,
   -2263,  1281, -2263, -2263,   -22, -2263, -2263, -2263, -2263,  1242,
   -2263, -2263, -2263, -2263, -2263,  1118,  1028,  1283, -2263,  1283,
   -2263, -2263,  1333,  1394,  1423, -2263,  1340, -2263,  1343, -2263,
    1708, -2263,  1709, -2263,  1280, -2263,  1672, -2263, -2263, -2263,
    1028,  1028, -2263,   -63, -2263, -2263,  1251, -2263,  1345,  1405,
    1414, -2263, -2263, -2263,   951,  1629,  1118,  1014,  1014,  1118,
      20,  1452,  1118,  1779, -2263,  1498, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   772,    75, -2263,  1028,
   -2263,  1496, -2263, -2263,  1251, -2263,  1354,  1415, -2263,  6371,
     749,  1606,  1413,  1302,  1118,  1779,  1306,   488,   -53,  1413,
    1312,  1118, -2263, -2263, -2263,   -32,   772, -2263, -2263, -2263,
     791, -2263,  1251, -2263,  1363,   723,   584, -2263, -2263,   585,
     629,   650,   682,   698,  1314, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  1430, -2263,  1413, -2263, -2263, -2263, -2263,  1028,
    1028,  1585, -2263, -2263, -2263,   -47, -2263, -2263, -2263,  1118,
     133, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1082,
     464, -2263,  1313, -2263,   879, -2263,  1372, -2263, -2263, -2263,
   -2263,  1306, -2263, -2263, -2263, -2263,  1567,    96,  1604,  1320,
    1118, -2263, -2263,  1118, -2263,  1196, -2263, -2263, -2263, -2263,
   -2263, -2263,  1702, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1315,
   -2263, -2263,  1380, -2263,  1365,  1386, -2263, -2263, -2263, -2263,
    6217,   487,  1804, -2263,  1432,  1432, -2263,  1220,  1525, -2263,
     914,   914, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1387, -2263,  1413,    94, -2263, -2263, -2263,  1413, -2263, -2263,
    1424, -2263,   337,   337, -2263,  1492,  1336,    48,  2484,  3701,
   -2263,  1413,  1396,  6998,  1381, -2263,  1028, -2263,   487, -2263,
    1400,  1590, -2263,  1674, -2263, -2263, -2263, -2263,   914,  1395,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1220, -2263, -2263, -2263, -2263,    40,  1350,
   -2263,   877, -2263, -2263, -2263, -2263,  1344, -2263,  5860, -2263,
   -2263,  1336,  1402, -2263, -2263,  1472,  4013, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   -65, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1453, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   853, -2263,
   -2263,  1519, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263,  1742, -2263, -2263,  1397,  5711,    12,    12,  1403,  1406,
    1407, -2263,  1408,    12, -2263, -2263, -2263,  5237,  6998,  5237,
    1409, -2263,  1397, -2263,   253,   988,  1053, -2263,  1690, -2263,
   -2263, -2263, -2263, -2263,  1387, -2263,  1411,  1421,  1426,  6998,
   -2263, -2263,   566, -2263,   487, -2263, -2263, -2263, -2263, -2263,
     -53,   -53, -2263, -2263, -2263, -2263,  1676, -2263, -2263,  1372,
    1413, -2263, -2263,  1435, -2263,  1442, -2263,    58,    58,  1359,
    1445, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  -173,  4284,  6998,   347,   477,   365,  1212,   420,
     688,  5309,  5417,  1612,  -204,  1033,   420,  1028,  1433, -2263,
   -2263,  5417, -2263, -2263,   420,  1344,  1066,  1028,  4362,  5417,
   -2263,   896,  2782,  1212,  1028,  1212,  1028,    56,   123,  1028,
    1212, -2263, -2263, -2263, -2263, -2263, -2263,  4629,  4737, -2263,
   -2263,  1344,    80,  1028,  1212,  1028,  1028,  1566, -2263,  6222,
   -2263, -2263,  1387, -2263,  1371,  1373,  6998,  6998,  6998,  5711,
    1391, -2263,  1029, -2263,  5711, -2263, -2263, -2263, -2263,  6998,
    6712,  6998,  6998,  6998,  6998,  6998,  6998, -2263,  5711,  6998,
     988,  1474, -2263,  1446, -2263, -2263, -2263,  1869,  1350, -2263,
     196, -2263, -2263, -2263, -2263,   145, -2263,   624,  -169,   266,
   -2263, -2263, -2263,  1771,   181,  1706,  1525,  1028,  5711, -2263,
    1772, -2263,  4809, -2263, -2263, -2263, -2263, -2263,    54,   578,
   -2263,   347, -2263,  1457, -2263,    12, -2263, -2263, -2263, -2263,
    1774,  1887, -2263,   365, -2263, -2263,  1212,  1115,  1525,  1775,
     263, -2263,  1523, -2263, -2263,  1365,  1387,  1212,  1776,  1377,
    1110,  1778,  4951, -2263,  5023,   103,  1114,  1203,  1780,   588,
    1419, -2263, -2263, -2263,  1777,    52, -2263, -2263, -2263,  4513,
   -2263, -2263,  1810,   -65, -2263, -2263, -2263,   420, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,  1476, -2263, -2263,   303,  1344,
   -2263, -2263,   218, -2263, -2263, -2263, -2263, -2263, -2263,  1456,
    5417, -2263,  1468,  1781,  1871, -2263, -2263, -2263, -2263,   896,
    1518, -2263,  1478, -2263,  3697,    -4,   745,  1482,  1481, -2263,
     825, -2263,  1488,  1786,   945, -2263,  1734, -2263,  1790,  1377,
    1798,  1734,  1028,  1802,  1454, -2263,   793, -2263, -2263, -2263,
   -2263, -2263, -2263,  1678, -2263,   420, -2263,   394, -2263,   245,
    1919, -2263,    51, -2263,  1805,   979,   554,  1906,  1808,  3796,
   -2263, -2263,  1028,  1809,  5095,  1344, -2263, -2263,   740, -2263,
   -2263, -2263, -2263,  3418, -2263,  1763, -2263,  1225,  1811,  1848,
    1812,  1734, -2263,  1028,  1744,   961, -2263,   283,   870, -2263,
   -2263,   213,  1513,  1516,  1517,   290, -2263,  1387, -2263,  1521,
   -2263, -2263,   314,  1524,   870, -2263,  1042,  1053,  1053, -2263,
   -2263, -2263,  1086,  1526,   360,  1520,  1118, -2263,   -53,  1854,
    1531,    35,  6708, -2263,  1118,  1561,  1660, -2263, -2263,  1865,
   -2263, -2263,   793,  1787, -2263,   874,  1733,   -26,  1529, -2263,
    1387, -2263, -2263, -2263,  5572,  1785, -2263,  1755, -2263,  1613,
   -2263,  1652,  1739, -2263, -2263, -2263,  1419, -2263,  1115, -2263,
   -2263, -2263,  1027,   639,  1028, -2263, -2263, -2263, -2263, -2263,
    6998,  1724, -2263,  1381, -2263,  1212, -2263, -2263, -2263,  1766,
   -2263, -2263, -2263,  5417, -2263,  1704,   220,  1701,  1264,  1515,
    1836,  1836,  1836,  1836, -2263, -2263,  5417,  5572, -2263, -2263,
   -2263, -2263,  -204,   192, -2263,  1500, -2263,  1503, -2263, -2263,
   -2263, -2263,  1433, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  4246, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   179, -2263,  1878,  1219,  1832,
   -2263,   793,   151, -2263, -2263,  1643, -2263, -2263,    86,  6998,
   -2263,  1562,   420, -2263, -2263,  5572,  1518,  1232,  1212, -2263,
   -2263, -2263, -2263, -2263,  1842,  1028,   347, -2263,  1228, -2263,
   -2263, -2263, -2263,  1377,  1066, -2263, -2263, -2263,  1783, -2263,
   -2263,   371,  1883, -2263, -2263,  1028,  1883,  1569, -2263,  1387,
   -2263, -2263,   384,   854, -2263, -2263,  2470, -2263,  1964,   802,
      88, -2263, -2263, -2263,  1118, -2263,   456,  5417, -2263,    28,
    5286, -2263, -2263,  1028, -2263,  1822, -2263, -2263,  5572, -2263,
    1413, -2263, -2263,   793, -2263, -2263, -2263, -2263, -2263,  1906,
    1791, -2263, -2263,  1228, -2263,  1906, -2263, -2263, -2263,  1506,
   -2263,  1028,  1411,  1411,  1411,  5711, -2263,   492,  1411, -2263,
    6730,  1411,  1411, -2263,   487, -2263,  1566, -2263, -2263,  1118,
    1118,  1779,  1236, -2263, -2263, -2263, -2263,  1817,  1846, -2263,
    1118, -2263,   391, -2263, -2263, -2263,  1412,  1118,  1887, -2263,
   -2263, -2263,  1726, -2263,  1413, -2263,  1967, -2263, -2263, -2263,
    1028, -2263, -2263,  1028, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1823,  1726,   708,  1118, -2263,  1528,  1574,
   -2263, -2263, -2263,  1756,  1726,  1726,   134,  1788,  1726, -2263,
    1864, -2263, -2263, -2263,  1532,  1535, -2263,   793,  1864,  1793,
    1608,  1747, -2263, -2263,  1762, -2263, -2263, -2263, -2263, -2263,
   -2263,   481, -2263,  1028,  1525,   620, -2263,   -54,   147,   420,
    1602,  1613,   420, -2263,  1605,   347, -2263,   -65, -2263, -2263,
    1661,  1688, -2263,   889,  1118, -2263, -2263, -2263, -2263, -2263,
    1758, -2263, -2263, -2263,  2025, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  1836,  1118, -2263,   -84, -2263, -2263,  1417,  1118,
   -2263, -2263, -2263, -2263,   -13, -2263,  1214, -2263,  1455,  1756,
   -2263, -2263, -2263, -2263,  1855,   620,  1856,   153, -2263, -2263,
   -2263, -2263,  2040, -2263,  1617,   210, -2263, -2263,   192, -2263,
   -2263, -2263, -2263,  1566, -2263, -2263, -2263,  1933,  1923,  1433,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1699,  1433, -2263,
    1616, -2263,  2018, -2263, -2263, -2263,   928, -2263,   793,  1119,
   -2263,    73,   961,   407,   420,   420,   620,  1866,  1212,   119,
    1056,  1929, -2263, -2263, -2263,  2063, -2263,  1877, -2263, -2263,
   -2263, -2263,  1783, -2263, -2263, -2263, -2263,  1028,  1945,  1766,
    1139, -2263,  1573, -2263,  1576,   793,  -199, -2263,   481, -2263,
   -2263, -2263,  5417,   854,   854,   854,   854,   854,   854,   854,
     854,   802, -2263,     6,  1766,   -59, -2263,  1653,  1653, -2263,
   -2263,   -42,  1028,   620,  1882,  1637, -2263,  1644,  2081,  1028,
     446,   371,  2093,  1598,  1118, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1059, -2263, -2263, -2263,  1028,   365,
   -2263, -2263,  1118,  1779,  1849,  1336, -2263, -2263, -2263,  1028,
     448, -2263, -2263, -2263, -2263,   448, -2263, -2263,  1118,  1396,
    1118, -2263, -2263, -2263,  1118, -2263, -2263, -2263,   634, -2263,
   -2263, -2263,  1118,  1600,   448,   448, -2263, -2263,   448, -2263,
   -2263,  1813, -2263, -2263,  1864, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1523,   -26, -2263, -2263,  1814,   -23,  1903,
     620,   935, -2263, -2263, -2263, -2263, -2263,   -17,    79, -2263,
   -2263, -2263,   415, -2263, -2263, -2263, -2263, -2263, -2263,   448,
   -2263, -2263, -2263, -2263,   448,   504,   504, -2263, -2263, -2263,
   -2263, -2263,  1609,   420, -2263,   420,  1362, -2263,   414,    10,
     192, -2263, -2263, -2263,  2040,  1028, -2263, -2263, -2263, -2263,
    1610,   960,   378,  1611,   935,   793, -2263, -2263,  2059, -2263,
   -2263, -2263, -2263,  1119, -2263,  1924, -2263,  1118,  1506,  1800,
   -2263, -2263,   420, -2263,   420,  1056, -2263, -2263, -2263,  1158,
   -2263, -2263,  1028,  5417,   656, -2263, -2263, -2263,  1824, -2263,
   -2263,  1858, -2263, -2263, -2263, -2263,  1576, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   -39,
   -2263,  1028, -2263, -2263, -2263,  1222, -2263, -2263, -2263,  6998,
   -2263,  5417,  5417,  1654,  1792,  1523, -2263,   420, -2263,   935,
   -2263,  1815, -2263,   793, -2263,  2004,  1684, -2263,   689, -2263,
     676, -2263,  1598, -2263,  1028, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263,  1327,   -41, -2263,  1028, -2263, -2263, -2263, -2263,
   -2263, -2263,   888, -2263,   365,   888, -2263, -2263, -2263,   100,
    2071,  2739,  1864, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1712,  1930, -2263, -2263, -2263,  1931, -2263, -2263, -2263, -2263,
   -2263, -2263,  1838, -2263,  1525, -2263, -2263, -2263, -2263,  1028,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    3229, -2263, -2263, -2263,  1332, -2263, -2263, -2263,  1264, -2263,
     620,  1789,   620,  1794, -2263, -2263,  5417, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   960, -2263,  2033, -2263,
    1433, -2263, -2263, -2263,   935,  1341, -2263, -2263,  1341,   -79,
    1028, -2263, -2263,   620, -2263, -2263,  1757, -2263,  2087,  1876,
    1904,   746, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   870, -2263, -2263, -2263, -2263,
   -2263,  1844,  1118,  1712,   620,  1649, -2263,  2081, -2263,  1604,
    2049,  1604,  1654, -2263, -2263, -2263, -2263,  1857, -2263, -2263,
   -2263, -2263,  1339, -2263,  1028,  1211, -2263, -2263,  1849, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   448, -2263,
   -2263, -2263,   448,    -8, -2263, -2263,  1118, -2263, -2263, -2263,
   -2263,  1118, -2263, -2263, -2263, -2263, -2263,     5, -2263, -2263,
    2092, -2263, -2263,   -11, -2263, -2263,  2144, -2263, -2263, -2263,
    2739, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1028, -2263, -2263, -2263, -2263,  1264, -2263,   420, -2263,   420,
   -2263, -2263, -2263,  2109,  2051,  1341,  1341, -2263,  1707,  1707,
   -2263,  1826,  1212,   648, -2263,  1028, -2263, -2263,  5417, -2263,
    1118,   781,  1897,  1905, -2263,  1907, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1028, -2263, -2263, -2263, -2263,  1713, -2263,
    1028,  1604, -2263,  1028, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263,  1217,  1118,  1118,   171, -2263, -2263, -2263, -2263, -2263,
   -2263,  1539, -2263, -2263, -2263,  2057,   448,   448, -2263,  1118,
     504,   504, -2263,   525, -2263, -2263, -2263,  1712,  1712,  5417,
   -2263,  1341, -2263,  5417,  5417,  1118,  1212,  1212,  1831, -2263,
   -2263,  1689,  1028, -2263, -2263,  1824, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,   712, -2263, -2263,  1028, -2263, -2263, -2263,
    1118,  1849,  1849, -2263,  1960,  1118,  1118, -2263,  2760,  1720,
   -2263, -2263,   365, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,   347,  1212,  1118, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1346, -2263, -2263, -2263, -2263, -2263,
    1833,  2068, -2263,  1849, -2263, -2263, -2263,  1849,  1849,  1955,
    1259,  1779,  1969,  1413,  1677,  1118,  1525, -2263,  1118,  1118,
    1028, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,   573, -2263,   534, -2263, -2263, -2263,
    1259,  1779, -2263, -2263, -2263,   347, -2263,  1818,  1768,    34,
    1566, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   133, -2263,
    1118,  1380, -2263,  7096,  7096,  1401,  2061,  1991, -2263,  1413,
     573, -2263, -2263,  1413,   534, -2263, -2263,   133, -2263, -2263,
    1028, -2263,  1361, -2263, -2263, -2263,    89, -2263,   573,  1396,
   -2263,  1523,  7024, -2263, -2263,  1204,  1273, -2263, -2263,  1290,
   -2263, -2263, -2263, -2263,   -20,   -20, -2263, -2263, -2263, -2263,
   -2263,  7096, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1851,   883,    89, -2263, -2263, -2263,  1742, -2263,  1566, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,  1879, -2263,  1879, -2263,
    2153, -2263,  1566, -2263, -2263,  1899,  1028, -2263,  1784,   -15,
    1872, -2263, -2263,  7096,   579, -2263, -2263,  1413, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  1212,
   -2263
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2263, -2263, -2263, -2263, -2263,  2201, -2263, -2263, -2263,   198,
   -2263,  2164, -2263,  2120, -2263, -2263,   240, -2263, -2263, -2263,
    1429, -2263, -2263,  1447,  2187, -2263, -2263,  2088, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  2013,
      38, -2263, -2263, -2263, -2263, -2263,  2069, -2263, -2263, -2263,
   -2263,  2012, -2263, -2263, -2263, -2263, -2263, -2263,  2145, -2263,
   -2263, -2263, -2263,  1998, -2263, -2263, -2263, -2263,  1983, -2263,
   -2263,   894, -2263, -2263, -2263, -2263,  2072, -2263, -2263, -2263,
   -2263,  2046, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1068, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,  1705, -2263,  1816, -2263, -2263, -2263,
    1759, -2263, -2263, -2263, -2263,   361, -2263, -2263,  1946, -2263,
   -2263, -2263, -2263, -2263,  1806, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1234, -2263, -2263, -2263,  1461, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  -311,
   -2263, -2263,  1743, -2263,  -752,  -818, -2263, -2263, -2263,  -514,
   -2263, -2263, -2263, -2263,  -567, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -1396,   814,  1499,   611,   672, -1388, -2263, -2263,
   -2263,  -350,  -414, -2263, -2263,   382, -2263, -2263,    93, -1384,
   -2263, -1383, -2263, -1382, -2263, -2263,  1458, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    -388,  -420, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -1200, -2263,  -355, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,  1410, -2263, -2263, -2263,    77,    78, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
    1238,   345, -2263,   202, -2263, -2263, -2263, -2263, -1742, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,  -983, -2263, -2263,  -698,
   -2263,  1479, -2263, -2263, -2263, -2263, -2263, -2263,  1051,   530,
     535, -2263,   451, -2263, -2263,   -94,   -85, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   506, -2263, -2263, -2263,
    1047, -2263, -2263, -2263, -2263, -2263,   813, -2263, -2263,   224,
   -2263, -2263, -1263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263,   815, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
     788, -2263, -2263, -2263, -2263, -2263,    49, -1744, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
     770, -2263, -2263,   773, -2263, -2263,   447,   229, -2263, -2263,
   -2263, -2263, -2263,  1007, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,    37,   733, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,   727,
   -2263, -2263,   211, -2263,   430, -2263, -2263, -1889, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263,   978,   722,   204, -2263, -2263, -2263, -2263, -2263, -2263,
   -1360,   976, -2263, -2263, -2263,   199, -2263, -2263, -2263,   411,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263,   363, -2263, -2263, -2263,
   -2263, -2263, -2263,   701,   189, -2263, -2263, -2263, -2263, -2263,
    -155, -2263, -2263, -2263, -2263,   387, -2263, -2263, -2263,   956,
   -2263,   959, -2263, -2263,  1171, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,   169, -2263, -2263, -2263, -2263, -2263,
     944,   375, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,     9, -2263,   379, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  -344,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263,  -469,
   -2263,   668, -2263, -2263, -1633, -2263, -2263,  -522, -2263, -2263,
   -1603, -2263, -2263,    15, -2263, -2263, -2263, -2263,   -87, -2139,
   -2263, -2263,    11, -1822, -2263, -2263, -1812, -1529, -1056, -1426,
   -2263, -2263,   785, -1738,   195,   197,   200,   201,  -908,   114,
    -753,   466,   381, -2263,   641,  -557, -1358, -1066,    97,   989,
   -1543,  -389,  -909, -2263, -1293, -2263, -1038, -1454,   871,  -529,
     -98,  2028, -2263,  1633,  -547,    30,  2176, -1070, -1054,  -857,
    -961, -2263, -1069, -1427, -2263,   431, -1287, -1326, -1089, -1147,
   -1150, -2263, -2263, -2263, -1114, -2263,  -212,   923,  -634, -2263,
   -2263,  -103, -1181,  -742,   -99,  2060, -1740,  2089,  -665,  1025,
    -531,  -387, -2263, -2263, -2263,    14,  1360, -2263, -2263,   486,
   -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -2263, -1948,
   -2263, -2263,  1588, -2263, -2263,  -190,  -594,  1918, -2263, -1166,
   -2263, -1301,  -265,  -625,   955, -2263,  1827, -2263, -1422, -2263,
   -1253, -2263, -2263,   -52, -2263,   -29,  -650,  -357, -2263, -2263,
   -2263, -2263,  -242,  -186,  -232, -1188, -1536,  2124,  1891, -2263,
   -2263,  -335, -2263, -2263,  1079, -2263, -2263, -2263,   423, -2263,
     280, -1916, -1451, -2263, -2263, -2263,  -150,   484, -1379, -1390,
   -2263, -2263, -2263,  -262, -2263, -2263,  1641, -2263,  1795, -2263,
   -2263, -2263,   796, -2263, -2262,  -246, -2263, -2263, -2263, -2263,
   -2263, -2263
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1839
static const yytype_int16 yytable[] =
{
     139,   689,   139,   215,   427,   138,   428,   141,   139,   415,
     741,   579,  1256,   147,  1350,   733,   778,   160,  1437,   759,
    1014,  1418,  1862,   404,   838,  1870,  1704,   103,   104,   105,
     975,   245,   139,  1241,  1706,   111,   427,   180,  1707,  1708,
    1709,  1771,   990,  1714,  1288,  1874,   464,   437,  1267,  1597,
    1464,   696,  1278,  2173,  1604,  2190,  1620,  1223,  1349,   268,
    1278,  1830,  2037,   279,  1473,  1332,   463,  2099,   259,  1502,
     134,   135,   768,   136,  1278,   226,   790,  1824,   143,   144,
    -652,   246, -1552,    99,  1456,  2204,  1755,   161,  1000,   838,
     107,   264,  2126,  1617,   211,  1402,  1669,  2237,  2651,   411,
    -650,   345,   535,   843,   169,  1995,   392,  1194, -1807,  1413,
    2035,  1447,  2450, -1794,   220,  2340,   821,   821,  1560, -1553,
    1512,  2445,   215,   790,  1670,  1671,  1749,   291,   448,  1238,
    1948,   219,  1213,  1432,   529,  1202,   360,  1570,  1109,  1815,
    1255,  1259,   700,  1747,  1457,  1721,  2391,   321,  2200, -1558,
    1284,   825,   297,   114, -1772,   211,  2666,  1302,  1304,   413,
    1851,  2689,   251,  2613,   821,  1512,   216, -1734,  2030, -1734,
    2021,  1610,  2495,   227,   258,  2124,  1361,  1213,    42,   453,
   -1556,   701,   412,  1223,   283,  2127,  2258,  2293,  1427,  1917,
       4,   221,    23,  1790,  1194,   737,   327,  1420,  1684,   581,
    1685, -1794,  1194,   480,  1007,    94,  1290,  1866,  1852,   839,
     535,  1432,  2044,  1819,  2162,  1162,   796,   465,  -652,   419,
     295,   129,  -652,  1544,  2227,  2493,   980, -1838,   299,    43,
     182,  1819,  1366,   253,  1544,   583,  1180,   822,  -650,  2179,
   -1738,  1387,  -650,   515,  1254, -1734,   608, -1734,   274,   275,
    1262,  1238,    94,    21,    22,  1899, -1838,  -500,     3,   228,
    2494,  1263,  2476,  2083,  1850,    15,  1900,    94,   418,  1238,
    1923,  1414,    46,   611,   839,  1602,  1336,  2488,    24,   609,
    -652,  1364,   516,  1166,   997,  -500,  -500,  2489, -1838,   204,
      43,  1278,   999,  1833,   253,  1544,  2119,  2055,   284,  2120,
    -650,   709,   311,   229,   212,  2031,   413,  2205,  1541,  1238,
    1551,  1110,   314,   230,  1750,  1194,  1787,  1918,   183,   601,
    2136,  1151,   582,  1166,   130,  2085,  2309,   231,  1853,  1184,
    1428,     5,   137,  2633,   410,   749,  2518,   738,  1928,  1561,
     139,  1218,   139,   139,  1933,  1220,  1927,   485,   486,   139,
   -1579,  2128,   280,  1166,   491, -1734,  1672,   217,   493,   127,
    1166,  2189,   424,  2385,  2386,   212,   139,  2238,  1605,   507,
     507,   485,   507,   436,   281,   507,   514,     5,  1241,   752,
    1550,  2279,   443,   444,  1166,   445,   446,  2206,  2060,   753,
    1238,   452,  1854,   232,  1337,  1382,   985,  2063,  1361,  1824,
    -500,  2010,  1824,  1391,  1391,  1391,   449,  2196,   469,   783,
     980,   980,   980,   139,  1527, -1738,  1404,  1406,   542,  2392,
     283,  -652,  1467,  1412,   492,   -35,  1238, -1772,  -500,   260,
    1166,  1241,   980, -1734, -1734,  1220,  2333,   139,   139,   466,
     989,  -650,   542,   580,  1367,  2201,  1267,   826,  1571,  2210,
    1994,  1294,   137,  1185,  1186,  2614,  1629,   749,   128,  1527,
     430,   505,   243,   233,  2319,  1725,   234,   235,   450,   754,
    2036, -1807,  2451,   702,   368,   749,   139,   187, -1838,   137,
   -1740,   580,   536,  1756,   188,   137,   540,  1673, -1825,  2358,
     137,  1337,  1865,   686,   467,   139,   747,  1368,  2461,  1241,
     697,   752, -1738,  1474,  2018,   577,  1001,  1835,  1278,  2239,
   -1738,   753, -1734,  1171,   783,   749,  2049,  -500,  1172,   752,
   -1767,  -657,  1784,    97,  1829,   591,  2053,   593,   996,   753,
     598,   600,  1367,   602,   284,  1814,  1816,   980,  1878,   755,
    2207,  1966,   265,   767,   243,   732,   844,   735,  1544,  2363,
     346,   989,  1367,   292,  1503,  1788,   261, -1738,   236,   752,
     679,   137,  1241,  1419,  1837,   688,  2004, -1637,  1153,   753,
     394,  2068,   699,  1541,  1439,  2277,  2008,   149,  2441,  2477,
     985,   985,   985,  1552,   756,  1368,  1939,  2365,   512,  1871,
     536,   754,   980,   832,   137,   823,   749,  -657,   322,   980,
     980,   980,   985,  1220,  1867,  1368,   607,  1488,  2107,   754,
    1474,  1167,   980,   980,   980,   980,   980,   980,   980,   980,
    1855,  1232,   980, -1738,  1824,  2079,  1238,  2376,   137,  2378,
     740,  2037,   749, -1838,   757, -1520,   704,  1496,  2503,  2504,
     752,   129,  -655,  1961, -1738,  1901,  1820, -1838,  -500,   754,
     753,  1167, -1738,   243,   255,  1553,  1916,  1821, -1838,  1920,
    2396,   755, -1619,   824,  1820,  1337,  2176,  1924,   829,   834,
     834,   772,  1171,  2657,   773,  1821,   752,  1172,  1006,   755,
     431,  1167,   949,   991,   137,  2230,   753,  2232,  1167,   189,
    2414,  2415,  1606,  1241,  1154,  1155,  2211,  2212,  2213,   749,
   -1838,  1160,  1168,  2656,   154,   744,   756,   985,  2014,  1237,
     137,  1249,  1167,  2507,   222, -1838,  1468,  1773,  -655,   755,
     525,  2080,  2235,  -647,   756,  1789,  2263,  2016,  1607,  1295,
     754,  1776,  1650,  1940,  1324,  1321,  1329,  2000,  2252, -1617,
    1975,  1355,  1417,   752,   130,  2049,   517, -1520,  1227,  2694,
     137,  2534,  2535,   753,    16,  1377,   757,  1109,  1167,  2214,
     154,   190,   985, -1614,   756, -1738,   754,    18,   137,   985,
     985,   985,  1398, -1621,   757,   681, -1838,  1398,  2253,  2294,
    1962,  2160,   985,   985,   985,   985,   985,   985,   985,   985,
    2160,  1398,   985,  2581,  2082,  2023,   693,  2582,  2583,  2384,
     755,  1448,  2027,  1752,  2695,   -96,    27,   243,   137,  1662,
    1278,  1544,  2696,  2296,   757,  2171,  1497,   191,  1976, -1752,
    1546,  1441,   192,   243,  1424, -1825,  2606,   351,   715,  2160,
    1772,  1896,   749,   754,  2183,  2184,   755,   137,  2185,  2519,
    1903,  1603,   137, -1838,  1321,   756,  2303,  1458,  1904,  2466,
     228,  2467,   137,  2056,  2508,  2509,  2298,  2311,  1476,  2598,
    2157,  -647,  1591,  2603,  2606,  -647, -1838,   187,  1776,   305,
     137,  1665, -1838,  2269,   188,   243,   752,   223,  2520,  2221,
     518,   756,  2215,  2216,  2222,   716,   753,  2217,   747,   137,
     154,  1425, -1838,   728,   229,   757,  2697,   139,   139,  1228,
     351,  1229,  2599,   755,   230,  1298,   694,  1944,  2102,     5,
    2096,  1189,  1643,   980,  1479,   799,  2521,  1298, -1838,  1885,
    1778,  2225,  2225,  -647,  2514,   137,   193,  1321,  2387,   748,
    1110,   757,   154,   745,   470,   471,   472,  1851,  1684,    28,
    1685,  2109,   187, -1838,   747,   682,   -96,  1337,   756,   188,
     243,   137,   328,   137,   800,   801,   802,   803,   804,  2167,
     243,  1941,  2402,  1452,   154,  2468,   754,   187,  1810,  1811,
    1812,  1813,  1840,   170,   188,  1841,  1842,  2231,    33,  2233,
     519,  2304,  2403,   117,   232,  1852,   137,  2576,  1647,   626,
     627,   717,  1226,    52,  1588,  2241,  1245,  2310,   757,  1947,
    2312, -1752,   980,  1245,  1280,   749,  2186,   438,  2404,   137,
     306,  1245,  1778,  1905,  1299,  2009,  2370,   171,  1241,  1320,
   -1836,  1327,  2192,  1327,  1335,  1352,  1299,   172,  1544, -1520,
     137,  2005,    36,  2405,  1424,   717,   755, -1520, -1520,    39,
      53,  2219, -1520,  1327,  2616,  1906,  2420,  2276,  2423,   752,
     316,  2497, -1734,   439,   233,   473,   717,   361,   243,   753,
     712,  2531,   718,  2620,  -647,   705,  1305,  1907,  1181,   474,
    2242,  1241,  2273,  1008,  2244,   747,  1648,  1951,    54,   189,
      55,   756,    56,   985,   394,  2329,  1777,  1462,   717,   362,
      57,   749,   805,   806,   807,   808,   809,   810,   811,   639,
     640,  1425,  2551,   980,   717,  1853,   720,   173,  2571,  1131,
    2552,   317,   318,  2272,  2554,  2555,  2556,  2002,  1226,  2570,
    1908,  1306,  2679,   750,   751,   137,  1724,   722,  2069,  1307,
     329,   757,  2268, -1754,  1630,   752,  2684,  1245,  1549,   754,
   -1070,  2699,   706,  1247,   707,   753,    58,   749,   952,   236,
      40,   190,   475,  2574,   189, -1767,  1613, -1838,  2322,   724,
     243,   155,  2654,   156,   476,   953,  2621,  2623,  2486,  1854,
    2287,  2287,   985,   405,  1245,   726,  2070,   174,  2443,   189,
    1909,   137,  2444,    94, -1070,  1245,   325,  2167,   403,  2673,
     330,   752,  1631,   394, -1070,  2660,   441,  1886,  2654,  1132,
     300,   753,   154,  2163,  2364,  1725,  1619,   191,    48,   755,
    2366,    49,   192,  1308,  2670,  2609,  1614,  2323,   344,  1615,
    2369,  2674,   175,  1331,   406,   754,   190,  1574,  1839,  1335,
    1581,  1840,  1270,   416,  1841,  1842,  1879,  1843,  1844,    60,
    1133,  2675,  1245,  1381,   812,  1575,  1245,  2406,  1882,  1793,
     400,   190,  1794,   742,   756,   477,  2693,   813,    51,  1795,
    1796,  1845,  1846,   254,  2002,  1880,  2195,   954,  1398,  1134,
    2028, -1558,   176,   985, -1070,  2380,  1910,    97,   749,  1582,
     139,   754,   191,    61,  2038,  1644,   743,   192,   783,  1769,
    2407,    93,  1934,  2408,  2409,   755,  2500,  2501,   137,  1793,
    2005,  1321,  1794,   100,   757,  1797,  2410,   191,  1462,  1795,
    1796,  2457,   192,  2458,  1770,   139,   255,  2530, -1838,    52,
    2425,  2426,   752,  2488,   958,   959,   960,   555,  2220,  1171,
     961,   749,   753,  2489,  1172,   101,  2225,  2225,   252,  2506,
     756,  1757,   556, -1838, -1070,  2320,  2199,  2324,  1171,  2388,
      94,   755,  2325,  1172,  2452,  1797,  1271,  1272,  2594,  2159,
    2071,   819,   819,   298,  1135,   594,    53,   595,  -858,   962,
    2191,  -858,    64,  1273,  1798,   752,  2285, -1838,  2389,  1482,
     106,    94,   557,  2577,  2455,   753,   108,  1664,  2431, -1070,
     757,  2661,  1677,  1713,  1757,  1715,   756,  1855,  2432,  2199,
    2643,  2100, -1838,  1799,    54,   154,    55,   114,    56,   819,
     109,  1194,   754,  2573,  2536,    67,    57,  1869,  2655,   137,
    2265,  2433,   820,   820,  1798,  1800,  2101,  1274,  2481,  1514,
    1515,    13,   749, -1070,   118,  2087,    13,  2471,  1170, -1070,
     137,  1890,  1226,   964,  -858,  2266,   757,  1171,  1897, -1738,
     110,  2434,  1172,  1799,  2624,  2493,   155,   112,   156,  1245,
    2662,  -858,  1757,    26,   113,   754,  1915,   120,  1516,  1517,
     820,  1459,    58,  1226,  2199,  1800,   752,  2664,  1401,  1801,
      47,   428,   755,  2663,  1952,  1953,   753,    68,  1171,    91,
    2625,  1659,   122,  1172,   965,   966,  1843,  1844,  2510,  1245,
    2665,  1171,  2511,  2512,  1173,  1651,  1172,  2488,  2155,  1655,
     592,   140,    94,  1174,   124,   599,  1657,  2489,  1171,   558,
    1845,  1846,  2648,  1172,   126,  1757,  2649,   756,  1974,  1801,
     559,  1926,  1802,   137,    59,   755,  1660,   970,  1984,  1985,
    1423,   508,  1988,   510,  1423,  1171,   511,   706,   139,   707,
    1172,  2039,  2040,  1935,  1409,  1410,  1411,   971,  2586,  2587,
     243,   394,   972,  -858,   142,    60,   754,   167,  1963,   973,
    1964,   137,   980,  2032,  -858,  2033,  1634,   757,  1635,  2316,
     756,  2317,  1802,   149,  2372,  1913,  2373,   162,  2072,  2199,
    1460,  2428,  1803,  2429,   163,  1969, -1536, -1536, -1536, -1536,
    1490,  1491,  1492,  1493,  1731,  1804,  1732,  -858,  1161,    61,
    1163,   164,    62,  -858,   181,  -858,  1977,   186,  -858,   243,
    -858,  -858,  -858,   185,   137,  2314,  -858,   204,  -858,   193,
     757,   560,   561,  -858,   242,   357,   755,  1407,  1408,   247,
    1949,  1950,  1803,  1393,  1394,   248,   562,   249,   563,   250,
     358,  1960,  1245,   257,   269,  1804,  1245,   273,  1965,  1245,
     359,   278,  1226,   294,   296,  -858,  1936,  1937,  1938,   154,
    -858,   300,  1942,   302,   303,  1945,  1946,    63,  1528,   309,
    1529,   756,   307,   308,  -858,   312,   313,  1978,  1805, -1535,
   -1535, -1535, -1535,   326,   360,   333,   428,   336,    64,   721,
     723,   725,   727,   334,   338,   340,   982,   342,  -858,   349,
     351,   353,  1245,   354,   356,   392,   398,   394,   397, -1738,
    2089,  2261,  2626,    65,   401,    66,  2627,  2628,   403,   408,
     187,   757,   564,   409,   420,   421,   243,   422,  1805,  -858,
     429,    67,   985,   413,   454,  2022,   455,   457,  2110,  2111,
    2112,  2113,  2114,  2115,  2116,  2117,  -342,  1729,  1730,   459,
     490,  1245,  1245,  1245,  2029,   487,   483,  2629,   495,   494,
    2034,  2134,  -858,   502,   509,   521,   522,   527,  -858,   565,
    2134,  1890,   523,  2630,  2631,   547,   533,   543,   548,   549,
    -858,  -858,   551,  -355,   554,   552,   578,   585,  1731,   586,
    1732,   603,  1733,   587,   605,   610,   613,   687,   984,   614,
     685,   690,   698,    68,   730,   711,   728,   736,   746,   762,
    1245,   765,   769,  -858,   777,   771,   780,   781,   783,   786,
     791,   797,   793,  -858,   830,   823,  1734,  1735,  1736,  -858,
     836, -1621,   950,   994,   989,   139,   995,   998,  1019,  1011,
    2156,   361,  1120,  -858,  1016,  1139,  1147,  1299,  -858,  1175,
    1149, -1738,  1299,  1187,  1200,  -858,  1156,  -858,  1260,  1157,
    1158,  1159,  1164,  -858,  1176,  1382,  1389,  1415,  1390,  2177,
    1281,  1299,  1299,   362,  1178,  1299,  1737,  1191,  1738,  1179,
     982,   982,   982,  -228,  1193,  1739,  1400,  1201,  1740,  1417,
    1416,  1430,  1436,  1442,  1451,  2154,  1453,  1245,  1465,  1471,
    1477,  1542,   982,  1480,  1500,  1562,  1494,  1498,  1546,  1559,
    1565,  1563,  1567,  2158, -1538,  1576,  1299,  1577,  1578,  1579,
    1584,  1299,  1299,  1299,  1586,  2089,  2226,  2226,  2617,  2172,
    1245,  2174,  1245,  1589,  2271,  2175,   363,  2589,  1593,  1337,
    1609,   364,  1611,  2180,  1595,  1194,  1621,  2646,  1626,  1633,
    1639,  1637,  1652,  1641,  1645,  1653,  1654,  1663,  1666,   952,
    1656,  1716,  1717,  1658,  1719,  1661,  1753,  2608,  1760,  1245,
    1152,  1245,   365,  1668,  1722,  1741,   953,  1742,  1759,  1762,
     366,  1764,   984,   984,   984,  1220,  1774,  1778,  1785,  1791,
    1808,  1482,  1825,   367,  1337,  1828,  1836,  1849,  1552,  1864,
    1872,  1887,  1891,  1902,   984,  1205,  1895,  1219,  1922,  1929,
    1235,  1956,  1957,  1970,  1257,  1967,  1980,  1973,  1982,  1989,
    1996,  1997,   368,  1979,  1245,   369,   980,   980,  1999,  1293,
    1724,  2019,  1992,   370,  1993,  1319,  1998,  1299,  2260,  2011,
    2020,   139,  2015,  2024,  -225,  1432,   542,  2050,  2043,  2045,
    2051,  2057,  2058,  2064,  2061,   980,  1375,  2065,  1379,  2084,
    2090,  2092,   982,  2093,  2096,  2103,  2130,   428,  2104,   982,
     982,   982,  1396,   371,   980,  2137,   372,  1396,   954,  2138,
    2140,  2139,   982,   982,   982,   982,   982,   982,   982,   982,
    2149,  1396,   982,  2151,  2181,  2160, -1557,  2187,  2254,  2245,
    2251,  2193,  2257,  2228,  2262,  2273,  2289,  2299,  2334,   984,
    2275,  2301,  2292,  2005,  1246,   428,   980,  1245,  2297,  1245,
    1438,  1246,  2367, -1513, -1555,  2382,  2398,  2397,  2399,  1246,
    2411,  2400,  2416,  1455,  2421,   958,   959,   960,  2449,  2304,
    2377,   961,  2452,  1246,  1319,  2379,  1235,   139,  2459,  2478,
    1245,  2460,  2394,  2465,  2462,  2484,  2499,  2479,  2515,  2480,
    2536,  2516,  2572,  2579,   984,  2580,  2584,  1743,  2590,  2592,
    2640,   984,   984,   984,  1397,  2610,  2611,  2641,  2671,  1397,
     962,  1245,  2680,  2692,   984,   984,   984,   984,   984,   984,
     984,   984,  2683,  1397,   984,  2685,   985,   985,    17,  2687,
      92,   139,   125,    38,   256,   166,   580,   209,   266,   277,
     119,   290,   210,   241,   545,  1299,   442,  1744,   504,  1299,
    2086,   456,   323,  1440,   835,   985,  1705,  1319,  1745,   787,
     526,  2619,  2678,  1188,  2078,  2313,   993,  2669,  2682,  2645,
    2236,  1015,  2330,  2331,   985,  1434,  1199,  1987,   948,  1598,
    2042,  1986,  2448,  2413,   964,  1246,  2454,  2013,  1450,  1767,
    2234,  1783,  1818,  1768,  1245,  2054,  1245,  2375,  1826,  2240,
    1543,  1848,  1860,  2381,  2256,  1625,  2066,  1566,  1868,  2264,
    1569,  2267,  2470,  2094,  2148,  2278,   985,  1894,  2118,  1600,
    1353,  2288,  1246,  1624,  1601,  2146,  2419,  2446,  2677,  2147,
     428,  1932,  2447,  1246,  2475,   965,   966,  2424,  2427,  1832,
    2281,  1592,  2282,  1766,   764,  2283,  2284,   332,   213,  2108,
     310,   293,  1165,   795,  2578,   447,   539,  2464,  2607,   272,
     489,  2132,  2250,  1299,  1299,  2077,   774,  1299,  1299,  2634,
    1299,  2226,  2226,   597,  1863,  1598,     0,     0,   970,     0,
       0,  1599,     0,     0,     0,     0,     0,     0,     0,     0,
    1246,  2472,     0,     0,  1246,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,     0,   137,   982,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2491,  2492,     0,     0,     0,     0,     0,
    1226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2513,     0,     0,     0,
       0,     0,     0,     0,  2591,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1599,     0,     0,
       0,  2533,     0,     0,     0,     0,  2537,  2538,     0,  1758,
       0,     0,  1226,     0,  1598,     0,  1206,     0,     0,   747,
       0,     0,   982,     0,     0,   846,  2575,   847,     0,   848,
       0,     0,     0,     0,   849,   984,     0,     0,  1877,     0,
    2642,     0,   850,     0,  2644,     0,     0,  1884,     0,     0,
       0,     0,     0,  1226,     0,     0,  2593,     0,  1893,  2595,
    2596,     0,  1758,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   851,   852,     0,     0,     0,
       0,     0,     0,     0,   853,     0,  1921,     0,     0,  1226,
       0,     0,   952,     0,     0,   854,  1598,     0,   855,     0,
       0,  2618,     0,     0,     0,     0,     0,     0,     0,   953,
       0,     0,   856,  2686,     0,     0,  1599,     0,  1396,     0,
       0,     0,     0,   982,   984,     0,     0,  1246,  2700,     0,
    1758,     0,     0,     0,     0,   857,     0,     0,     0,     0,
       0,     0,     0,   858,     0,   859,     0,     0,     0,     0,
       0,  1319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1898,  1971,     0,     0,  1972,  1246,     0,     0,
       0,     0,     0,     0,     0,     0,   860,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   861,     0,     0,
       0,     0,   862,  1758,     0,     0,     0,     0,  1599,     0,
    1598,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   954,     0,     0,     0,     0,  2003,     0,     0,   863,
    1397,     0,   749,     0,     0,   984,   864,     0,     0,   865,
     866,     0,     0,     0,     0,     0,     0,     0,     0,   867,
       0,     0,     0,     0,     0,     0,   868,     0,   869,     0,
       0,   870,     0,     0,     0,  1208,     0,     0,     0,     0,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   871,     0,     0,     0,   872,     0,   873,
       0,     0,  1599,     0,     0,     0,     0,     0,     0,   874,
       0,  2335,     0,   962,  2336,     0,     0,  2337,     0,     0,
    1246,  1598,  1598,     0,  1246,  2338,     0,  1246,     0,     0,
       0,     0,   963,     0,     0,   875,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   624,     0,     0,   876,     0,
    2095,     0,     0,     0,     0,     0,   754,     0,  1598,     0,
       0,     0,     0,     0,  1684,  1731,  1685,  1732,     0,     0,
    2339,     0,     0,   877,   878,     0,     0,     0,     0,     0,
    1246,     0,     0,     0,   879,  2135,     0,   964,     0,  2340,
       0,     0,  2145,  2145,     0,     0,     0,     0,   880,   881,
       0,     0,     0,     0,   952,   882,     0,     0,     0,   883,
       0,     0,  1235,     0,     0,     0,     0,   884,     0,     0,
       0,   953,  2166,  1599,  1599,     0,   755,   885,     0,  1246,
    1246,  1246,     0,     0,     0,     0,   886,     0,   965,   966,
       0,     0,     0,     0,     0,   887,     0,     0,     0,     0,
     888,   889,     0,     0,   890,     0,   891,     0,     0,     0,
    1599,     0,     0,   892,  1899,     0,     0,     0,  2341,     0,
       0,   756,     0,     0,  2198,  1900,   893,  2342,     0,     0,
       0,   970,     0,     0,     0,     0,     0,     0,  1246,     0,
    2343,     0,     0,     0,   894,     0,     0,     0,     0,     0,
     895,   971,     0,     0,     0,   896,   972,     0,     0,  2539,
       0,     0,  1311,   973,     0,   137,     0,     0,  2243,     0,
       0,   757,  2344,   954,     0,     0,     0,  2198,  1598,     0,
       0,     0,   897,     0,     0,   642,  1598,     0,     0,     0,
       0,     0,  2345,     0,  2346,     0,     0,     0,     0,     0,
       0,     0,  2540,     0,  2541,  1877,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2347,  2348,     0,     0,
       0,     0,     0,     0,     0,  1246,     0,     0,  1312,     0,
     958,   959,   960,     0,  2280,  2542,   961,     0,     0,     0,
       0,     0,   982,     0,     0,     0,     0,  2349,     0,     0,
       0,     0,  2198,     0,     0,  2543,  1598,     0,  1246,     0,
    1246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2350,   962,     0,   646,  2321,     0,
    1599,     0,     0,  2544,     0,     0,     0,  1235,  1599,     0,
       0,     0,     0,     0,     0,     0,     0,  1246,     0,  1246,
    2351,     0,     0,     0,     0,     0,     0,  2352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2353,     0,  2371,     0,  2354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   984,     0,     0,     0,     0,   964,
       0,     0,  1246,     0,     0,   651,     0,     0,  1599,     0,
       0,     0,     0,     0,  2545,  2355,     0,  2198,     0,     0,
       0,     0,     0,     0,  2356,     0,     0,     0,     0,     0,
       0,  2546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,  2547,  2357,     0,     0,     0,     0,     0,     0,
       0,     0, -1838,  2358,     0,     0,     0,     0,     0,  2359,
     846,     0,   847,  2548,   848,     0,     0,     0,     0,   849,
       0,     0,     0,     0,     0,     0,     0,   850,     0,     0,
       0,     0,  2549,   970,     0,  1246,     0,  1246,     0,   660,
    2550,     0,     0,     0, -1123,     0,     0,     0,     0,     0,
       0,     0,     0,   971,     0,     0,     0,     0,   972,     0,
     851,   852, -1123,     0,     0,   973,   243,   137,  1246,   853,
       0,     0,     0,  2456,     0,     0,     0,     0,     0,     0,
     854,     0,     0,   855,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   856,     0,  1246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2482,     0,     0,     0,
     857,     0,     0,  2485,     0,     0,  2487,     0,   858,     0,
     859,     0,     0,     0,     0,     0,     0,  -694,     0,  -694,
    -694,  -694,  -694,  -694,  -694,  -694,  -694,     0,  -694,  -694,
    -694,     0,  -694,  -694,  -694,  -694,  -694,  -694,  -694,  -694,
    -694,   860,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   861,     0,     0,  2517,     0,   862,     0,     0,
       0,     0,  1246,     0,  1246,     0,     0,     0,     0,  2532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   846,
       0,   847,     0,   848,   863,  1235,     0,     0,   849,     0,
       0,   864,     0,     0,   865,   866,   850,     0,     0,     0,
       0,     0,     0,     0,   867,     0,     0,     0,     0,     0,
       0,   868,     0,   869,     0,     0,   870,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   851,
     852,     0,     0,  2597,     0,     0,     0,     0,   853,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   854,
       0,     0,   855,     0,     0,     0,     0,     0,   871,     0,
       0,     0,   872,     0,   873,     0,   856,     0,     0,     0,
       0,     0,     0,     0,   874,     0,   982,   982,     0,     0,
    -694,  -694,     0,  -694,  -694,  -694,  -694,     0,     0,   857,
       0,     0,     0,  2647,     0,     0,     0,   858,     0,   859,
     875,     0,     0,     0,     0,   982,     0,     0,     0,     0,
       0,     0,     0,   876,     0,     0,     0,  2668,  2668,     0,
       0,     0,     0,     0,   982,     0,     0,     0,     0,     0,
     860,     0,     0,     0,     0,     0,     0,     0,   877,   878,
       0,   861,     0,     0,     0,     0,   862,     0,     0,   879,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2691,   880,   881,     0,   982,     0,     0,     0,
     882,     0,     0,   863,   883,     0,     0,     0,   984,   984,
     864,     0,   884,   865,   866,     0,     0,     0,     0,     0,
       0,     0,   885,   867,     0,     0,     0,     0,     0,     0,
     868,   886,   869,     0,     0,   870,     0,   984,     0,     0,
     887,     0,     0,     0,     0,   888,   889,     0,     0,   890,
       0,   891,     0,     0,     0,     0,   984,     0,   892,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -694,     0,     0,     0,     0,     0,   871,     0,     0,
       0,   872,     0,   873,     0,     0,     0,     0,     0,   894,
       0,     0,   846,   874,   847,   895,   848,     0,   984,     0,
     896,   849,     0,     0,     0,     0,     0,     0,     0,   850,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   875,
       0,  -694,     0,     0,     0,     0,     0,   897,     0,     0,
       0,     0,   876,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,     0,   877,   878,     0,
       0,     0,   854,     0,     0,   855,     0,     0,   879,   952,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   856,
       0,     0,   880,   881,     0,     0,   953,     0,     0,   882,
       0,     0,  1206,   883,     0,   747,     0,     0,     0,     0,
       0,   884,   857,     0,     0,     0,     0,     0,     0,     0,
     858,   885,   859,     0,     0,     0,     0,     0,     0,     0,
     886,     0,     0,     0,     0,     0,     0,     0,     0,   887,
       0,     0,     0,     0,   888,   889,     0,     0,   890,     0,
     891,     0,     0,   860,     0,     0,     0,   892,     0,     0,
       0,     0,     0,     0,   861,     0,     0,     0,     0,   862,
    1632,     0,     0,     0,     0,     0,     0,     0,   952,     0,
       0,     0,     0,     0,     0,     0,     0,  1311,   894,     0,
       0,     0,     0,     0,   895,   953,   863,     0,   954,   896,
       0,     0,     0,   864,     0,     0,   865,   866,  1357,     0,
       0,     0,     0,     0,     0,     0,   867,     0,     0,     0,
       0,     0,     0,   868,     0,   869,   897,     0,   870,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1455,     0,   958,   959,   960,     0,     0,
       0,   961,     0,     0,     0,     0,     0,     0,     0,     0,
     871,     0,     0,     0,   872,     0,   873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   874,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   954,     0,     0,
     962,     0,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,   875,     0,     0,     0,  1021,     0,  1022,     0,
       0,     0,     0,  1023,  1623,   876,     0,     0,     0,     0,
       0,  1024,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1208,     0,     0,     0,     0,     0,   956,     0,   957,
     877,   878,   752,     0,   958,   959,   960,     0,     0,     0,
     961,   879,   753,     0,  1025,  1026,     0,  1209,     0,     0,
       0,     0,     0,  1027,   964,   880,   881,     0,     0,     0,
       0,     0,   882,     0,  1028,     0,   883,  1029,     0,     0,
       0,     0,     0,     0,   884,     0,     0,     0,     0,   962,
       0,  1030,     0,     0,   885,     0,     0,     0,     0,     0,
       0,     0,     0,   886,     0,     0,     0,     0,   963,     0,
       0,     0,   887,     0,  1031,   965,   966,   888,   889,     0,
       0,   890,  1032,   891,  1033,     0,     0, -1838,     0,     0,
     892,  1034,   754,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1042,     0,  1043,  1044,  1045,     0,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,     0,     0,   970,     0,
       0,   894,     0,   964,     0,     0,  1056,   895,     0, -1123,
       0,  1057,   896,     0,     0,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,     0, -1123,     0,     0,
     973,   243,   137,     0,     0,     0,     0,     0,  1058,   897,
       0,     0,   755,     0,     0,  1059,     0,     0,  1060,  1061,
       0,     0,     0,     0,   965,   966,     0,     0,  1062,     0,
       0,     0,     0,     0,     0,  1063,     0,  1064,     0,     0,
    1065,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1206,     0,     0,   747,     0,   756,  1508,  1509,
    1510,     0,     0,     0,     0,     0,  1511,   970,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1066,     0,     0,     0,  1067,   971,  1068,     0,
    1206,     0,   972,   747,     0,     0,     0,     0,  1069,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1070,     0,     0,     0,   952,     0,
       0,     0,     0,     0,     0,     0,     0,  1071,     0,     0,
       0,     0,     0,     0,     0,   953,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1072,     0,     0,     0,   952,     0,  1206,     0,
       0,   747,     0,  1073,     0,     0,     0,     0,  1207,     0,
       0,     0,     0,   953,     0,     0,     0,     0,  1074,     0,
       0,     0,     0,     0,  1075,     0,     0,     0,  1076,     0,
       0,     0,     0,     0,     0,  1512,  1077,     0,     0,     0,
       0,     0,     0,     0,     0,  1513,  1078,     0,     0,     0,
       0,     0,     0,     0,     0,  1079,     0,     0,     0,     0,
       0,     0,     0,     0,  1080,     0,     0,     0,     0,  1081,
    1082,     0,     0,  1083,   952,  1084,     0,   954,     0,     0,
       0,     0,  1085,  1514,  1515,     0,  1300,     0,   749,     0,
       0,   953,     0,     0,     0,  1086,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1831,     0,
       0,     0,     0,  1087,     0,   954,     0,     0,     0,  1088,
       0,  1208,  1516,  1517,  1089,     0,   749,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,  1209,     0,  1206,
       0,  1090,   747,     0,     0,  1508,  1509,  1510,     0,  1208,
    1518,     0,     0,  1511,     0,   956,  1519,   957,     0,  1520,
     752,     0,   958,   959,   960,     0,     0,  1521,   961,   962,
     753,     0,     0,     0,  1522,  1209,     0,     0,     0,  1523,
       0,     0,     0,   954,     0,     0,     0,     0,   963,     0,
       0,     0,     0,     0,   749,     0,     0,     0,  1524,     0,
       0,     0,     0,     0,     0,     0,     0,   962,     0,     0,
       0,     0,   754,     0,     0,   952,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   963,  1208,     0,     0,
       0,     0,   953,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,   964,     0,     0,   961,     0,   753,     0,
     754,     0,     0,  1209,     0,  1206,     0,     0,   747,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   964,   755,     0,     0,   962,     0,     0,     0,     0,
       0,     0,  1512,     0,   965,   966,     0,     0,     0,     0,
       0,     0,  1513,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1525,     0,  1526,     0,  1527,
     755,     0,  1528,     0,  1529,  1530,  1531,   756,   754,  1532,
    1533,   952,   965,   966,   954,     0,     0,   970,     0,     0,
    1514,  1515,     0,     0,     0,   749,     0,     0,   953,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,   964,
       0,  1357,   972,  1206,     0,   756,   747,     0,     0,   973,
       0,   137,     0,     0,     0,   970,     0,   757,  1208,  1516,
    1517,     0,     0,     0,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,   971,     0,   961,   755,   753,
     972,     0,     0,     0,  1209,     0,     0,   973,     0,   137,
     965,   966,     0,     0,     0,   757,     0,  1518,     0,     0,
       0,     0,     0,  1519,     0,     0,  1520,     0,     0,     0,
       0,     0,     0,     0,  1521,  1206,   962,     0,   747,   952,
       0,  1522,     0,   756,     0,     0,  1523,     0,     0,     0,
     954,  1362,     0,   970,     0,   963,   953,     0,     0,     0,
       0,   749,     0,     0,     0,  1524,     0,     0,     0,     0,
       0,     0,     0,   971,     0,     0,     0,     0,   972,   754,
       0,     0,     0,     0,     0,   973,     0,   137,     0,     0,
       0,     0,     0,   757,  1208,     0,     0,     0,     0,     0,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
     964,   952,     0,   961,     0,   753,     0,     0,     0,     0,
    1209,     0,     0,     0,     0,     0,     0,     0,   953,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,   962,     0,     0,     0,     0,     0,   954,     0,
       0,   965,   966,     0,     0,     0,     0,     0,     0,   749,
       0,   963,     0,     0,     0,     0,     0,  -914,     0,     0,
    -914,     0,  1525,     0,  1526,     0,  1527,     0,     0,  1528,
       0,  1529,  1530,  1531,   756,   754,  1532,  1533,     0,     0,
       0,     0,  1208,     0,   970,     0,     0,     0,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,   971,     0,   964,     0,  1209,   972,
     954,     0,     0,     0,     0,     0,   973,     0,   137,     0,
       0,   749,     0,     0,   757,     0,     0,     0,     0,  1206,
       0,     0,   747,  -914,     0,     0,     0,     0,     0,     0,
     962,     0,     0,     0,     0,   755,     0,     0,     0,     0,
    -914,     0,     0,     0,  1208,     0,     0,   965,   966,   963,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,     0,     0,
    1209,     0,     0,   754,     0,     0,     0,     0,     0,     0,
     756,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,  1206,     0,     0,   747,   952,     0,     0,     0,     0,
       0,     0,   962,     0,   964,     0,  1482,     0,     0,     0,
     971,     0,   953,     0,     0,   972,     0,     0,     0,     0,
       0,   963,   973,     0,   137,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -914,   755,     0,   754,     0,     0,     0,     0,
       0,     0,     0,  -914,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   952,     0,     0,
       0,     0,     0,     0,     0,     0,   964,     0,     0,     0,
       0,     0,     0,     0,   953,     0,  -914,     0,   756,     0,
       0,     0,  -914,     0,  -914,     0,     0,  -914,   970,  -914,
    -914,  -914,     0,     0,     0,  -914,     0,  -914,     0,     0,
       0,     0,  -914,     0,   954,   755,     0,     0,   971,     0,
       0,     0,     0,   972,     0,   749,     0,   965,   966,     0,
     973,     0,   137,     0,     0,     0,     0,     0,   757,     0,
       0,     0,     0,     0,  -914,     0,  1444,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1208,     0,
     756,     0,     0,  -914,   956,     0,   957,     0,     0,   752,
     970,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,  1628,  1206,     0,  1209,   747,   954,  -914,     0,     0,
     971,     0,     0,     0,     0,   972,     0,   749,     0,     0,
       0,     0,   973,     0,   137,  1206,     0,     0,   747,   952,
     757,     0,     0,     0,     0,     0,   962,     0,  -914,     0,
       0,     0,     0,     0,     0,     0,   953,     0,     0,     0,
    1208,     0,     0,     0,     0,   963,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,     0,     0,  1209,  -914,   952,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -914,
    -914,     0,     0,     0,     0,   953,     0,     0,     0,     0,
       0,   952,     0,     0,     0,     0,     0,     0,   962,     0,
     964,     0,     0,     0,     0,     0,     0,     0,   953,     0,
       0,     0,  -914,     0,     0,     0,     0,   963,     0,     0,
       0,     0,  -914,  1206,     0,     0,   747,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   954,   755,
       0,   754,  -914,     0,     0,     0,     0,  -914,     0,   749,
       0,   965,   966,     0,  -914,     0,  -914,     0,     0,     0,
       0,     0,  -914,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   955,     0,   756,     0,     0,   954,   956,     0,
     957,     0,     0,   752,   970,   958,   959,   960,   749,   952,
       0,   961,     0,   753,     0,     0,     0,     0,  1486,     0,
     954,   755,     0,     0,   971,     0,   953,     0,     0,   972,
       0,   749,     0,   965,   966,     0,   973,     0,   137,     0,
       0,  1208,     0,     0,   757,     0,     0,   956,     0,   957,
     962,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,  1208,     0,   756,  1209,     0,   963,
     956,     0,   957,     0,     0,  1250,   970,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,  1754,     0,
    1209,   747,     0,   754,     0,     0,   971,     0,     0,   962,
       0,   972,     0,     0,     0,     0,     0,     0,   973,     0,
     137,     0,     0,     0,     0,     0,   757,     0,   963,     0,
       0,     0,   962,     0,   964,     0,     0,     0,   954,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   749,
       0,   963,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,   952,   754,     0,     0,     0,     0,
       0,     0,  1208,   964,     0,   965,   966,     0,   956,     0,
     957,   953,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,   964,     0,  1209,     0,
       0,     0,     0,     0,     0,     0,  1919,     0,   756,     0,
     968,     0,   755,     0,     0,     0,     0,     0,   970,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,     0,
     962,     0,     0,     0,     0,   755,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,     0,   965,   966,   963,
     973,     0,   137,     0,     0,     0,     0,   756,   757,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
     756,     0,     0,   954,     0,     0,     0,   971,     0,     0,
     970,     0,   972,     0,   749,     0,     0,     0,     0,   973,
       0,   137,     0,   952,   964,     0,     0,   757,     0,     0,
     971,     0,     0,     0,     0,   972,     0,     0,     0,     0,
     953,     0,   973,     0,   137,     0,     0,  1208,     0,     0,
     757,     0,     0,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,   755,     0,     0,   961,     0,   753,     0,
       0,     0,     0,  1209,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1013,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,     0,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,  -352,     0,   963,  -352,     0,     0,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,   971,     0,
       0,     0,   954,   972,     0,     0,     0,     0,   754,     0,
     973,     0,   137,   749,  -352,     0,  -352,     0,   757,     0,
       0,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,     0,     0,     0,     0,     0,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   756,     0,   529,     0,     0,  -352,  -352,
    -352,  -352,  -352,   970,     0,  -352,  -352,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,  -352,   754,  -352,     0,
       0,     0,     0,   971,  -352,     0,     0,     0,   972,     0,
       0,  -352,     0,     0,     0,   973,     0,   137,     0,  -352,
       0,     0,     0,   757,     0,     0,     0,     0,   964,     0,
       0,     0,  -352,     0,     0,  -352,     0,     0,     0,     0,
       0,  -352,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,   756,     0,     0,     0,     0,     0,  -352,  -352,
       0,     0,   970,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,   971,  -352,     0,  -352,     0,   972,     0,     0,
       0,     0,     0,     0,   973,     0,   137,     0,     0,     0,
       0,  -352,   757,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,  -352,     0,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,   618,   619,   620,   621,
     622,   623,     0,     0,     0,  -352,     0,  -352,  -352,  -352,
       0,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
     625,     0,   626,   627,   628,   629,   630,   631,   632,     0,
       0,     0,     0,     0,   952,     0,     0,  -352,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,  -352,     0,  -352,
       0,   953,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,  -352,     0,   633,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,  -352,  -352,
       0,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,   529,     0,     0,  -352,  -352,
    -352,  -352,  -352,     0,     0,  -352,  -352,     0,     0,     0,
       0,     0,   616,     0,     0,   634,   635,   636,   637,   638,
       0,     0,   639,   640,  -352,     0,     0,   617,     0,     0,
     618,   619,   620,   621,   622,   623,   624,     0,     0,  -352,
       0,     0,     0,   954,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,   749,  -352,   641,     0,     0,     0,
       0,  -352,     0,     0,   625,     0,   626,   627,   628,   629,
     630,   631,   632,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   955,     0,     0,
       0,     0,     0,   956,     0,   957,     0,  -352,   752,     0,
     958,   959,   960,     0,     0,     0,   961,     0,   753,     0,
     633,     0,     0,     0,   643,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,   962,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,   645,     0,     0,     0,
       0,     0,     0,  -352,   963,     0,     0,   647,     0,   634,
     635,   636,   637,   638,     0,  -352,   639,   640,     0,     0,
     648,     0,     0,  -352,     0,     0,     0,     0,   754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,     0,     0,     0,     0,     0,     0,     0,     0,   964,
       0,     0,     0,    94,     0,  -352,   642,  -352,  -352,  -352,
       0,     0, -1814,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   652,   653,   654,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,     0,
     965,   966,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,  1386,     0,     0,     0,     0,   644,     0,  -352,  -352,
    -352,   967,     0,   756,     0,   968,   969,     0,     0,     0,
     645,     0,  -352,   970,     0,   656,   657,   658,   646,  -352,
       0,   647,     0,     0,     0,   530,     0,     0,     0,     0,
       0,     0,     0,   971,   648,     0,     0,     0,   972,     0,
       0,     0,     0,     0,     0,   973,   649,   137,     0,     0,
       0,     0,     0,   757,   650,     0,     0,     0,     0,     0,
    1679,     0,     0,  1680,     0,     0,  1681,   618,   619,   620,
     621,   622,   623,  1682,  1683,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1684,     0,  1685,     0,   651,     0,   652,   653,
     654,   625,     0,   626,   627,   628,   629,   630,   631,   632,
       0,     0,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   655,     0,     0,     0,     0,
       0,   953,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -349,     0,     0,     0,   633,     0,   953,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1814,     0,     0,     0,     0,     0,     0,     0,     0,   656,
     657,   658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659,     0,     0,     0,     0,  1686,     0,
     660,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   634,   635,   636,   637,
     638,     0,     0,   639,   640,     0,     0,  1687,     0,     0,
       0,     0,     0,     0,  1688,     0,  1689,     0,     0,     0,
       0,     0, -1767,   954,     0,     0,     0,     0,     0,  1690,
       0,     0,     0,     0,   749,     0,     0,   641,     0,     0,
       0,   954,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,   749,   642,     0,     0,     0,     0,     0,     0,
       0,  1691,     0,     0,     0,     0,     0,   955,     0,     0,
    1692,     0,     0,   956,     0,   957,     0,     0,   752,     0,
     958,   959,   960,  1693,     0,   955,   961,     0,   753,     0,
       0,   956,     0,   957,     0,   643,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1694,     0,   962,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1695,   645,     0,     0,
       0,     0,     0,   962,   963,   646,     0,     0,   647,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   648,   963,  1696,     0,     0,     0,     0,   754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,     0,     0,  1697,
     952,     0,     0,     0,     0,     0,  1698,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,   953,     0,     0,
       0,     0,     0,  1699,     0,     0,   952,   964,     0,     0,
       0,     0,     0,   651,     0,   652,   653,   654,     0,     0,
       0,     0,     0,   953,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     965,   966,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,  1700,     0,     0,   965,   966,
    -597,  1405,     0,     0,     0,  1701,     0,     0,     0,     0,
       0,   967,     0,   756,     0,   968,   969,     0,   952,  1943,
       0,     0,  1702,   970,     0,     0,   656,   657,   658,   967,
       0,   756,     0,   968,   969,   953,     0,     0,     0,   954,
     659,   970,     0,   971,     0,     0,  1703,   660,   972,     0,
     749,     0,     0,     0,     0,   973,     0,   137,     0,     0,
       0,   971,     0,   757,     0,   954,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,   749,     0,     0,     0,
       0,   757,     0,   955,     0,     0,     0,     0,     0,   956,
       0,   957,     0,     0,   752,     0,   958,   959,   960,     0,
       0,     0,   961,     0,   753,     0,     0,     0,     0,   955,
       0,     0,     0,     0,     0,   956,     0,   957,     0,     0,
     752,     0,   958,   959,   960,     0,     0,     0,   961,     0,
     753,     0,     0,     0,     0,     0,     0,   954,     0,     0,
       0,   962,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     963,     0,     0,     0,     0,     0,     0,   962,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   955,     0,     0,   754,     0,   963,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,   964,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2658,     0,   962,
       0,   964,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,     0,   963,     0,
       0,     0,     0,     0,     0,     0,   965,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     755,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   965,   966,     0,     0,     0,   967,     0,   756,
       0,   968,   969,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,   964,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   756,     0,     0,     0,   971,
       0,     0,     0,     0,   972,   970,     0,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
       0,     0,   755,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,   965,   966,     0,   973,     0,   137,
       0,     0,     0,     0,     0,   757,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757
};

static const yytype_int16 yycheck[] =
{
     103,   595,   105,   158,   393,   103,   395,   105,   111,   366,
     660,   540,  1101,   111,  1128,   649,   714,   116,  1206,   684,
     838,  1187,  1558,   358,   776,  1568,  1422,    56,    57,    58,
     783,   181,   135,  1099,  1422,    64,   425,   135,  1422,  1422,
    1422,  1463,   784,  1422,  1114,  1574,   435,   404,  1104,  1336,
    1238,   598,  1106,  1969,  1347,  2003,  1357,  1095,  1128,   209,
    1114,  1512,  1806,     1,  1245,     9,     1,  1889,     9,    17,
      99,   100,   697,   102,  1128,    28,   741,  1503,   107,   108,
       0,   184,    31,    53,  1231,     6,  1444,   116,    48,   841,
      60,     1,  1914,  1356,    22,  1164,    61,    87,     9,   364,
       0,    57,   124,    55,   133,  1738,    86,    49,    39,  1178,
     123,    57,   123,    27,    96,   110,   750,   751,  1299,    31,
     159,   129,   277,   788,    89,    90,   152,    17,     9,     6,
    1666,   160,  1093,    30,   175,   308,    63,   141,   203,  1497,
    1101,  1102,   174,  1436,  1233,  1432,   225,     1,   165,   203,
    1111,    57,   251,    57,   232,    22,   176,  1118,  1119,   237,
       9,   176,   191,   129,   798,   159,   232,    64,   252,    66,
    1773,  1352,  2434,   126,   203,  1913,  1137,  1138,   142,   421,
     203,   213,   113,  1221,   274,   244,  2075,  2135,   357,   161,
     200,   161,   256,  1486,    49,   242,   295,     1,    64,   262,
      66,   115,    49,   256,   829,   232,  1115,  1565,    57,   776,
     124,    30,  1815,    21,  1954,   968,   747,   125,   138,   369,
     249,   354,   142,  1277,  2036,    54,   783,   187,   257,    31,
     218,    21,  1141,   195,  1288,   546,   989,   751,   138,  1981,
      87,  1149,   142,   414,  1101,    64,   171,    66,   218,   219,
     454,     6,   232,    13,    14,   454,   107,    61,     0,   212,
      89,   465,  2401,  1866,  1551,   452,   465,   232,   367,     6,
    1628,  1179,    32,   584,   841,  1345,   153,   106,   342,   204,
     200,  1138,   453,    70,   798,    89,    90,   116,   330,   199,
      92,  1345,   823,   114,   256,  1349,   290,  1833,   388,   293,
     200,   612,   272,   256,   232,   389,   237,   228,  1269,     6,
      92,   376,   282,   266,   340,    49,    96,   289,   306,   561,
    1923,   955,   385,    70,   457,  1868,  2148,   280,   177,   994,
     499,   341,   505,  2595,   363,   212,  2475,   384,  1639,  1300,
     443,  1094,   445,   446,  1645,   256,  1633,   445,   446,   452,
     203,   410,   290,    70,   452,   252,   321,   423,   457,    72,
      70,  1994,   391,  2252,  2253,   232,   469,   357,   123,   472,
     473,   469,   475,   402,   312,   478,   479,   341,  1444,   256,
    1289,  2119,   411,   412,    70,   414,   415,   308,  1839,   266,
       6,   420,   241,   346,   271,   309,   783,  1848,  1359,  1825,
     204,  1759,  1828,  1156,  1157,  1158,   287,  2010,   437,   463,
     967,   968,   969,   516,   453,   357,  1169,  1170,   516,   498,
     274,   341,   159,  1176,   453,   452,     6,   505,   232,   370,
      70,  1497,   989,   252,   331,   256,  2178,   540,   541,   347,
     463,   341,   540,   541,   452,   462,  1502,   353,   452,    34,
    1737,  1116,   505,  1000,  1001,   421,  1365,   212,   171,   453,
     172,   256,   504,   416,   505,   331,   419,   420,   349,   346,
     483,   402,   483,   505,   401,   212,   579,    56,   175,   505,
      59,   579,   504,  1444,    63,   505,   515,   452,   110,   484,
     505,   271,  1562,   592,   402,   598,     9,   505,  2387,  1565,
     599,   256,   357,  1245,  1767,   534,   466,  1545,  1562,   499,
     357,   266,   331,   459,   463,   212,  1817,   321,   464,   256,
     500,   376,  1483,   505,  1507,   554,   316,   556,   793,   266,
     559,   560,   452,   562,   388,  1496,  1497,  1094,  1576,   416,
     461,  1688,   452,   447,   504,   644,   498,   650,  1602,  2182,
     506,   463,   452,   443,   502,   335,   497,   499,   511,   256,
     589,   505,  1628,  1188,  1547,   594,  1754,   505,   955,   266,
     505,  1858,   601,  1534,  1208,  2104,  1757,   505,  2318,  2401,
     967,   968,   969,   365,   461,   505,  1655,  2190,   256,  1572,
     504,   346,  1149,   256,   505,   448,   212,   452,   452,  1156,
    1157,  1158,   989,   256,  1565,   505,   576,   504,  1895,   346,
    1352,   398,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
     469,   256,  1179,   357,  2050,   218,     6,  2230,   505,  2232,
     659,  2375,   212,   262,   511,    57,   606,    49,  2450,  2451,
     256,   354,   376,   252,   499,  1606,   454,   328,   452,   346,
     266,   398,   499,   504,   505,   437,  1617,   465,   287,  1620,
    2263,   416,   449,   762,   454,   271,    32,  1628,   767,   772,
     773,   700,   459,  2621,   703,   465,   256,   464,   828,   416,
     392,   398,   781,   786,   505,  2043,   266,  2045,   398,   268,
    2293,  2294,   447,  1759,   956,   957,   281,   282,   283,   212,
     244,   963,   449,  2619,   256,   241,   461,  1094,  1762,  1098,
     505,  1100,   398,  2453,   234,   161,   453,  1470,   452,   416,
     452,   314,   308,     0,   461,   505,  2084,  1765,   483,  1116,
     346,  1473,   449,   241,  1123,  1122,  1125,   256,  2064,   449,
      32,  1130,    30,   256,   457,  2046,    33,   169,   271,   170,
     505,  2491,  2492,   266,   452,  1144,   511,   203,   398,   344,
     256,   340,  1149,   449,   461,   499,   346,   153,   505,  1156,
    1157,  1158,  1159,   505,   511,    26,   330,  1164,  2065,  2137,
     389,   256,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
     256,  1178,  1179,  2533,  1864,  1778,   308,  2537,  2538,  2250,
     416,   223,  1785,  1437,   225,   229,   122,   504,   505,   449,
    1864,  1865,   233,  2139,   511,  1965,   228,   396,   110,   107,
     442,  1208,   401,   504,   410,   447,  2566,   188,   244,   256,
    1464,   447,   212,   346,  1984,  1985,   416,   505,  1988,   127,
      38,   447,   505,   289,  1231,   461,   157,  1236,    46,  2392,
     212,   203,   505,  1836,  2457,  2458,  2143,  2150,  1247,   286,
    1949,   138,  1331,   329,  2604,   142,   410,    56,  1610,   229,
     505,  1418,   216,   217,    63,   504,   256,   397,   166,  2029,
     167,   461,   467,   468,  2034,   301,   266,   472,     9,   505,
     256,   477,   236,   502,   256,   511,   317,  1000,  1001,   422,
     188,   424,   329,   416,   266,  1117,   418,  1660,  1891,   341,
     129,  1010,  1381,  1470,  1249,     1,   204,  1129,   262,  1584,
     231,  2035,  2036,   200,  2467,   505,   505,  1314,  2254,    50,
     376,   511,   256,   469,   117,   118,   119,     9,    64,    84,
      66,  1902,    56,   287,     9,   196,   370,   271,   461,    63,
     504,   505,   257,   505,    40,    41,    42,    43,    44,   511,
     504,   469,   216,  1225,   256,   317,   346,    56,  1490,  1491,
    1492,  1493,    12,   212,    63,    15,    16,  2043,   138,  2045,
     267,   292,   236,     1,   346,    57,   505,  2516,    27,    75,
      76,   406,  1095,    11,  1329,  2051,  1099,   321,   511,  1664,
    2150,   362,  1559,  1106,  1107,   212,  1989,   125,   262,   505,
     370,  1114,   231,   211,  1117,  1757,  2204,   256,  2084,  1122,
     454,  1124,  2005,  1126,  1127,  1128,  1129,   266,  2082,   451,
     505,   411,    26,   287,   410,   406,   416,   459,   460,   452,
      58,  2024,   464,  1146,  2580,   243,  2299,  2103,  2301,   256,
     351,  2441,   340,   171,   416,   238,   406,   220,   504,   266,
     337,  2483,   477,  2592,   341,   274,   170,   265,   502,   252,
    2053,  2137,   291,   196,  2057,     9,   115,  1671,    96,   268,
      98,   461,   100,  1470,   505,  2174,  1475,  1237,   406,   252,
     108,   212,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   477,  2498,  1660,   406,   177,   477,   346,  2498,   256,
    2498,   412,   413,  2096,  2498,  2498,  2498,  1751,  1221,  2498,
     318,   225,  2658,   244,   245,   505,   252,   477,     9,   233,
     435,   511,  2093,   256,   394,   256,  2672,  1240,  1288,   346,
     212,  2684,   351,   455,   353,   266,   164,   212,    82,   511,
     394,   340,   335,  2513,   268,   204,   177,   501,   270,   477,
     504,   307,  2616,   309,   347,    99,  2593,  2594,  2421,   241,
    2131,  2132,  1559,   447,  1277,   477,    57,   416,  2328,   268,
     378,   505,  2332,   232,   256,  1288,   292,   511,   351,   306,
     495,   256,   452,   505,   266,  2622,   359,  1584,  2652,   346,
     505,   266,   256,  1955,  2187,   331,  1356,   396,   256,   416,
    2193,   452,   401,   317,  2641,  2575,   237,   329,   324,   240,
    2203,   338,   461,  1126,   498,   346,   340,   482,     9,  1332,
     285,    12,   199,   287,    15,    16,     8,   277,   278,   257,
     387,   358,  1345,  1146,   330,   500,  1349,   501,  1583,    35,
     356,   340,    38,   171,   461,   438,  2683,   343,   452,    45,
      46,   301,   302,   452,  1898,    37,  2008,   201,  1655,   416,
    1792,   446,   511,  1660,   346,  2236,   474,   505,   212,   334,
    1383,   346,   396,   301,  1806,  1383,   204,   401,   463,   262,
    2273,   452,  1649,  2276,  2277,   416,  2446,  2447,   505,    35,
     411,  1688,    38,   423,   511,    91,  2289,   396,  1458,    45,
      46,  2377,   401,  2379,   287,  1418,   505,  2483,   262,    11,
    2303,  2304,   256,   106,   258,   259,   260,    47,  2026,   459,
     264,   212,   266,   116,   464,   405,  2450,  2451,   452,  2453,
     461,  1444,    62,   287,   416,  2163,  2011,   459,   459,     8,
     232,   416,   464,   464,     8,    91,   323,   324,  2546,  1953,
     241,   750,   751,   452,   511,   351,    58,   353,     6,   303,
    2004,     9,   390,   340,   160,   256,  2129,   262,    37,   165,
     394,   232,   102,    37,  2367,   266,   405,  1416,   177,   461,
     511,   187,  1421,  1422,  1497,  1424,   461,   469,   187,  2064,
    2600,   262,   287,   189,    96,   256,    98,    57,   100,   798,
     452,    49,   346,  2502,   210,   433,   108,  1567,  2618,   505,
     262,   210,   750,   751,   160,   211,   287,   394,  2411,   207,
     208,     2,   212,   505,   452,   379,     7,  2398,   450,   511,
     505,  1591,  1545,   377,    82,   287,   511,   459,  1603,    87,
     452,   240,   464,   189,    53,    54,   307,   452,   309,  1562,
     187,    99,  1565,    16,   452,   346,  1616,   218,   246,   247,
     798,   356,   164,  1576,  2139,   211,   256,   187,   449,   265,
      33,  1870,   416,   210,   248,   249,   266,   505,   459,    42,
      89,   449,   173,   464,   428,   429,   277,   278,  2459,  1602,
     210,   459,  2463,  2464,   451,  1391,   464,   106,   449,  1395,
     555,    68,   232,   460,   452,   560,  1402,   116,   459,   239,
     301,   302,   161,   464,   452,  1628,   165,   461,  1714,   265,
     250,  1630,   318,   505,   226,   416,   450,   471,  1724,  1725,
    1195,   473,  1728,   475,  1199,   459,   478,   351,  1651,   353,
     464,    96,    97,  1651,  1173,  1174,  1175,   491,   299,   300,
     504,   505,   496,   201,   452,   257,   346,   340,   156,   503,
     158,   505,  2129,   156,   212,   158,   351,   511,   353,   252,
     461,   254,   318,   505,   252,  1614,   254,   452,   469,  2254,
     475,   252,   378,   254,   505,  1694,   486,   487,   488,   489,
     486,   487,   488,   489,    65,   391,    67,   245,   967,   301,
     969,   452,   304,   251,   256,   253,  1715,   469,   256,   504,
     258,   259,   260,   256,   505,  2154,   264,   199,   266,   505,
     511,   351,   352,   271,   443,     4,   416,  1171,  1172,   400,
    1669,  1670,   378,  1157,  1158,   401,   366,   410,   368,    63,
      19,  1680,  1755,    59,   256,   391,  1759,   232,  1687,  1762,
      29,   452,  1765,   328,   401,   303,  1652,  1653,  1654,   256,
     308,   505,  1658,   229,    26,  1661,  1662,   369,   456,   107,
     458,   461,   452,   452,   322,   452,   312,  1716,   474,   486,
     487,   488,   489,   256,    63,   256,  2085,   455,   390,   620,
     621,   622,   623,   272,    23,   102,   783,   452,   346,   438,
     188,   122,  1815,   455,    17,    86,   394,   505,   452,   357,
    1870,  2078,   321,   415,   272,   417,   325,   326,   351,   401,
      56,   511,   452,   402,   423,   262,   504,    39,   474,   377,
     452,   433,  2129,   237,   402,  1774,   505,   331,  1903,  1904,
    1905,  1906,  1907,  1908,  1909,  1910,   505,    24,    25,   507,
     310,  1864,  1865,  1866,  1793,   316,   419,   366,   261,   394,
    1799,  1921,   410,   452,     7,   452,   394,   452,   416,   499,
    1930,  1931,   255,   382,   383,   452,   505,   504,   394,   366,
     428,   429,   452,    85,    85,   452,   124,   452,    65,   394,
      67,    22,    69,   389,   306,   309,   452,   505,   783,   394,
     204,   505,   500,   505,   384,   452,   502,   232,   505,   447,
    1923,   254,   218,   461,   122,   505,   511,   447,   463,   443,
      26,   306,   400,   471,   410,   448,   103,   104,   105,   477,
     348,   505,   446,   443,   463,  1948,   256,   452,   376,   505,
    1948,   220,   399,   491,   452,   336,   114,  1960,   496,   169,
     463,   499,  1965,   187,   505,   503,   463,   505,   256,   463,
     463,   463,   463,   511,   463,   309,   505,   403,   505,  1978,
     447,  1984,  1985,   252,   463,  1988,   153,   452,   155,   463,
     967,   968,   969,   262,   452,   162,   505,   452,   165,    30,
     454,   130,   196,   131,   447,  1934,   132,  2010,   133,   386,
     134,   101,   989,   135,   137,   447,   136,   498,   442,   463,
      49,   140,   404,  1952,   446,   443,  2029,   446,   440,   143,
     196,  2034,  2035,  2036,   144,  2085,  2035,  2036,  2588,  1968,
    2043,  1970,  2045,   145,  2094,  1974,   315,  2541,   146,   271,
      31,   320,   147,  1982,   500,    49,   148,  2607,   149,   196,
     112,   150,   449,   151,   220,   449,   449,   447,   114,    82,
     449,   410,   312,   449,   109,   449,   447,  2571,   223,  2082,
     955,  2084,   351,   452,   197,   252,    99,   254,   203,   376,
     359,   339,   967,   968,   969,   256,   272,   231,   294,   298,
     485,   165,   502,   372,   271,   502,   128,   175,   365,   447,
     168,   228,   129,    49,   989,  1092,   447,  1094,   196,   228,
    1097,   204,   176,    56,  1101,   299,   452,   204,   272,   165,
     237,   423,   401,   505,  2137,   404,  2593,  2594,   276,  1116,
     252,   380,   510,   412,   509,  1122,   299,  2150,  2077,   447,
     362,  2154,   447,   295,   423,    30,  2154,    17,   203,   203,
     443,   128,   139,   447,   365,  2622,  1143,    49,  1145,   203,
     141,     8,  1149,   196,   129,   502,   423,  2466,   502,  1156,
    1157,  1158,  1159,   452,  2641,   203,   455,  1164,   201,   452,
       9,   447,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
       7,  1178,  1179,   505,   504,   256,   203,   294,    49,   499,
     499,   297,   188,   504,   314,   291,   462,   113,    47,  1094,
     262,   437,   330,   411,  1099,  2514,  2683,  2230,   313,  2232,
    1207,  1106,   294,   203,   203,   102,    49,   380,   262,  1114,
     296,   237,   493,   256,    95,   258,   259,   260,    56,   292,
     361,   264,     8,  1128,  1231,   361,  1233,  2260,    49,   262,
    2263,   110,  2260,   337,   457,   452,   109,   262,   337,   262,
     210,   482,   452,   340,  1149,   107,   221,   444,   209,   502,
     119,  1156,  1157,  1158,  1159,   367,   418,   196,   337,  1164,
     303,  2294,   313,   321,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,    49,  1178,  1179,   306,  2593,  2594,     7,   425,
      46,  2314,    92,    26,   201,   127,  2314,   148,   206,   221,
      75,   238,   150,   177,   519,  2328,   410,   494,   469,  2332,
    1869,   425,   286,  1208,   773,  2622,  1422,  1314,   505,   740,
     497,  2591,  2656,  1009,  1862,  2152,   788,  2635,  2668,  2604,
    2048,   841,  2175,  2175,  2641,  1204,  1018,  1727,   779,  1336,
    1809,  1726,  2347,  2292,   377,  1240,  2360,  1761,  1221,  1456,
    2046,  1483,  1502,  1458,  2377,  1828,  2379,  2228,  1505,  2050,
    1273,  1548,  1555,  2246,  2073,  1362,  1856,  1309,  1566,  2085,
    1314,  2092,  2395,  1882,  1931,  2106,  2683,  1596,  1911,  1343,
    1129,  2132,  1277,  1359,  1345,  1930,  2297,  2336,  2652,  1930,
    2699,  1643,  2341,  1288,  2401,   428,   429,  2302,  2307,  1534,
    2125,  1332,  2125,  1452,   691,  2125,  2125,   299,   152,  1898,
     270,   242,   972,   745,  2524,   417,   509,  2389,  2570,   215,
     449,  1918,  2062,  2446,  2447,  1861,   705,  2450,  2451,  2595,
    2453,  2450,  2451,   558,  1558,  1432,    -1,    -1,   471,    -1,
      -1,  1336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1345,  2400,    -1,    -1,  1349,    -1,    -1,    -1,   491,    -1,
      -1,    -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,
     503,    -1,   505,  1470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2432,  2433,    -1,    -1,    -1,    -1,    -1,
    2513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2465,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2543,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1432,    -1,    -1,
      -1,  2490,    -1,    -1,    -1,    -1,  2495,  2496,    -1,  1444,
      -1,    -1,  2575,    -1,  1551,    -1,     6,    -1,    -1,     9,
      -1,    -1,  1559,    -1,    -1,     1,  2515,     3,    -1,     5,
      -1,    -1,    -1,    -1,    10,  1470,    -1,    -1,  1575,    -1,
    2599,    -1,    18,    -1,  2603,    -1,    -1,  1584,    -1,    -1,
      -1,    -1,    -1,  2616,    -1,    -1,  2545,    -1,  1595,  2548,
    2549,    -1,  1497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,  1623,    -1,    -1,  2652,
      -1,    -1,    82,    -1,    -1,    71,  1633,    -1,    74,    -1,
      -1,  2590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    88,  2676,    -1,    -1,  1551,    -1,  1655,    -1,
      -1,    -1,    -1,  1660,  1559,    -1,    -1,  1562,  2687,    -1,
    1565,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,    -1,
      -1,  1688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,  1700,    -1,    -1,  1703,  1602,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,   168,  1628,    -1,    -1,    -1,    -1,  1633,    -1,
    1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,  1753,    -1,    -1,   195,
    1655,    -1,   212,    -1,    -1,  1660,   202,    -1,    -1,   205,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,   224,    -1,
      -1,   227,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,   275,
      -1,    -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,   285,
      -1,    32,    -1,   303,    35,    -1,    -1,    38,    -1,    -1,
    1755,  1858,  1859,    -1,  1759,    46,    -1,  1762,    -1,    -1,
      -1,    -1,   322,    -1,    -1,   311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,   324,    -1,
    1887,    -1,    -1,    -1,    -1,    -1,   346,    -1,  1895,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    -1,    -1,
      91,    -1,    -1,   349,   350,    -1,    -1,    -1,    -1,    -1,
    1815,    -1,    -1,    -1,   360,  1922,    -1,   377,    -1,   110,
      -1,    -1,  1929,  1930,    -1,    -1,    -1,    -1,   374,   375,
      -1,    -1,    -1,    -1,    82,   381,    -1,    -1,    -1,   385,
      -1,    -1,  1949,    -1,    -1,    -1,    -1,   393,    -1,    -1,
      -1,    99,  1959,  1858,  1859,    -1,   416,   403,    -1,  1864,
    1865,  1866,    -1,    -1,    -1,    -1,   412,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,    -1,    -1,    -1,
    1895,    -1,    -1,   439,   454,    -1,    -1,    -1,   189,    -1,
      -1,   461,    -1,    -1,  2011,   465,   452,   198,    -1,    -1,
      -1,   471,    -1,    -1,    -1,    -1,    -1,    -1,  1923,    -1,
     211,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
     476,   491,    -1,    -1,    -1,   481,   496,    -1,    -1,   209,
      -1,    -1,   190,   503,    -1,   505,    -1,    -1,  2055,    -1,
      -1,   511,   243,   201,    -1,    -1,    -1,  2064,  2065,    -1,
      -1,    -1,   508,    -1,    -1,   235,  2073,    -1,    -1,    -1,
      -1,    -1,   263,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,    -1,   254,  2092,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,   288,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2010,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,  2121,   285,   264,    -1,    -1,    -1,
      -1,    -1,  2129,    -1,    -1,    -1,    -1,   318,    -1,    -1,
      -1,    -1,  2139,    -1,    -1,   305,  2143,    -1,  2043,    -1,
    2045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   345,   303,    -1,   327,  2165,    -1,
    2065,    -1,    -1,   333,    -1,    -1,    -1,  2174,  2073,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2082,    -1,  2084,
     371,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     391,    -1,  2209,    -1,   395,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2129,    -1,    -1,    -1,    -1,   377,
      -1,    -1,  2137,    -1,    -1,   405,    -1,    -1,  2143,    -1,
      -1,    -1,    -1,    -1,   414,   436,    -1,  2254,    -1,    -1,
      -1,    -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,
      -1,   431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,   452,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   440,   484,    -1,    -1,    -1,    -1,    -1,   490,
       1,    -1,     3,   473,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,   492,   471,    -1,  2230,    -1,  2232,    -1,   499,
     500,    -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,   496,    -1,
      51,    52,   500,    -1,    -1,   503,   504,   505,  2263,    60,
      -1,    -1,    -1,  2370,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,  2294,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2413,    -1,    -1,    -1,
     111,    -1,    -1,  2420,    -1,    -1,  2423,    -1,   119,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,  2472,    -1,   168,    -1,    -1,
      -1,    -1,  2377,    -1,  2379,    -1,    -1,    -1,    -1,  2486,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,   195,  2502,    -1,    -1,    10,    -1,
      -1,   202,    -1,    -1,   205,   206,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,   224,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,  2550,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,   273,    -1,   275,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   285,    -1,  2593,  2594,    -1,    -1,
     291,   292,    -1,   294,   295,   296,   297,    -1,    -1,   111,
      -1,    -1,    -1,  2610,    -1,    -1,    -1,   119,    -1,   121,
     311,    -1,    -1,    -1,    -1,  2622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   324,    -1,    -1,    -1,  2634,  2635,    -1,
      -1,    -1,    -1,    -1,  2641,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,
      -1,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2679,   374,   375,    -1,  2683,    -1,    -1,    -1,
     381,    -1,    -1,   195,   385,    -1,    -1,    -1,  2593,  2594,
     202,    -1,   393,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   403,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   412,   224,    -1,    -1,   227,    -1,  2622,    -1,    -1,
     421,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,
      -1,   432,    -1,    -1,    -1,    -1,  2641,    -1,   439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   452,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,     1,   285,     3,   476,     5,    -1,  2683,    -1,
     481,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
      -1,   502,    -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,   349,   350,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,   360,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,   374,   375,    -1,    -1,    99,    -1,    -1,   381,
      -1,    -1,     6,   385,    -1,     9,    -1,    -1,    -1,    -1,
      -1,   393,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   403,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,    -1,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,    -1,    -1,   152,    -1,    -1,    -1,   439,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,   168,
     452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   470,    -1,
      -1,    -1,    -1,    -1,   476,    99,   195,    -1,   201,   481,
      -1,    -1,    -1,   202,    -1,    -1,   205,   206,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,   222,    -1,   224,   508,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,   311,    -1,    -1,    -1,     3,    -1,     5,    -1,
      -1,    -1,    -1,    10,   228,   324,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
     349,   350,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,   360,   266,    -1,    51,    52,    -1,   271,    -1,    -1,
      -1,    -1,    -1,    60,   377,   374,   375,    -1,    -1,    -1,
      -1,    -1,   381,    -1,    71,    -1,   385,    74,    -1,    -1,
      -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,   303,
      -1,    88,    -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,   421,    -1,   111,   428,   429,   426,   427,    -1,
      -1,   430,   119,   432,   121,    -1,    -1,   440,    -1,    -1,
     439,   128,   346,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,   471,    -1,
      -1,   470,    -1,   377,    -1,    -1,   163,   476,    -1,   482,
      -1,   168,   481,    -1,    -1,    -1,    -1,    -1,   491,    -1,
      -1,    -1,    -1,   496,    -1,    -1,    -1,   500,    -1,    -1,
     503,   504,   505,    -1,    -1,    -1,    -1,    -1,   195,   508,
      -1,    -1,   416,    -1,    -1,   202,    -1,    -1,   205,   206,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,   215,    -1,
      -1,    -1,    -1,    -1,    -1,   222,    -1,   224,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    -1,   461,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,   471,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,   273,   491,   275,    -1,
       6,    -1,   496,     9,    -1,    -1,    -1,    -1,   285,   503,
      -1,   505,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   349,    -1,    -1,    -1,    82,    -1,     6,    -1,
      -1,     9,    -1,   360,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   375,    -1,
      -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   403,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,   426,
     427,    -1,    -1,   430,    82,   432,    -1,   201,    -1,    -1,
      -1,    -1,   439,   207,   208,    -1,    94,    -1,   212,    -1,
      -1,    99,    -1,    -1,    -1,   452,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,   470,    -1,   201,    -1,    -1,    -1,   476,
      -1,   245,   246,   247,   481,    -1,   212,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,     6,
      -1,   508,     9,    -1,    -1,    12,    13,    14,    -1,   245,
     284,    -1,    -1,    20,    -1,   251,   290,   253,    -1,   293,
     256,    -1,   258,   259,   260,    -1,    -1,   301,   264,   303,
     266,    -1,    -1,    -1,   308,   271,    -1,    -1,    -1,   313,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   332,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,   346,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   245,    -1,    -1,
      -1,    -1,    99,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,   377,    -1,    -1,   264,    -1,   266,    -1,
     346,    -1,    -1,   271,    -1,     6,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,   416,    -1,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,   169,    -1,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   449,    -1,   451,    -1,   453,
     416,    -1,   456,    -1,   458,   459,   460,   461,   346,   463,
     464,    82,   428,   429,   201,    -1,    -1,   471,    -1,    -1,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,   377,
      -1,   112,   496,     6,    -1,   461,     9,    -1,    -1,   503,
      -1,   505,    -1,    -1,    -1,   471,    -1,   511,   245,   246,
     247,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,   491,    -1,   264,   416,   266,
     496,    -1,    -1,    -1,   271,    -1,    -1,   503,    -1,   505,
     428,   429,    -1,    -1,    -1,   511,    -1,   284,    -1,    -1,
      -1,    -1,    -1,   290,    -1,    -1,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   301,     6,   303,    -1,     9,    82,
      -1,   308,    -1,   461,    -1,    -1,   313,    -1,    -1,    -1,
     201,    94,    -1,   471,    -1,   322,    99,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,   496,   346,
      -1,    -1,    -1,    -1,    -1,   503,    -1,   505,    -1,    -1,
      -1,    -1,    -1,   511,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
     377,    82,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,   322,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    -1,   449,    -1,   451,    -1,   453,    -1,    -1,   456,
      -1,   458,   459,   460,   461,   346,   463,   464,    -1,    -1,
      -1,    -1,   245,    -1,   471,    -1,    -1,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,   491,    -1,   377,    -1,   271,   496,
     201,    -1,    -1,    -1,    -1,    -1,   503,    -1,   505,    -1,
      -1,   212,    -1,    -1,   511,    -1,    -1,    -1,    -1,     6,
      -1,    -1,     9,    82,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,   245,    -1,    -1,   428,   429,   322,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
     461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     471,     6,    -1,    -1,     9,    82,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,   377,    -1,   165,    -1,    -1,    -1,
     491,    -1,    99,    -1,    -1,   496,    -1,    -1,    -1,    -1,
      -1,   322,   503,    -1,   505,    -1,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   416,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   245,    -1,   461,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,   471,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,    -1,   201,   416,    -1,    -1,   491,    -1,
      -1,    -1,    -1,   496,    -1,   212,    -1,   428,   429,    -1,
     503,    -1,   505,    -1,    -1,    -1,    -1,    -1,   511,    -1,
      -1,    -1,    -1,    -1,   303,    -1,   447,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
     461,    -1,    -1,   322,   251,    -1,   253,    -1,    -1,   256,
     471,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,   196,     6,    -1,   271,     9,   201,   346,    -1,    -1,
     491,    -1,    -1,    -1,    -1,   496,    -1,   212,    -1,    -1,
      -1,    -1,   503,    -1,   505,     6,    -1,    -1,     9,    82,
     511,    -1,    -1,    -1,    -1,    -1,   303,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,   322,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,   271,   416,    82,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,   461,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,   471,     6,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   416,
      -1,   346,   491,    -1,    -1,    -1,    -1,   496,    -1,   212,
      -1,   428,   429,    -1,   503,    -1,   505,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,   461,    -1,    -1,   201,   251,    -1,
     253,    -1,    -1,   256,   471,   258,   259,   260,   212,    82,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   485,    -1,
     201,   416,    -1,    -1,   491,    -1,    99,    -1,    -1,   496,
      -1,   212,    -1,   428,   429,    -1,   503,    -1,   505,    -1,
      -1,   245,    -1,    -1,   511,    -1,    -1,   251,    -1,   253,
     303,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,   245,    -1,   461,   271,    -1,   322,
     251,    -1,   253,    -1,    -1,   256,   471,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,     6,    -1,
     271,     9,    -1,   346,    -1,    -1,   491,    -1,    -1,   303,
      -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,   503,    -1,
     505,    -1,    -1,    -1,    -1,    -1,   511,    -1,   322,    -1,
      -1,    -1,   303,    -1,   377,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,   322,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    82,   346,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   377,    -1,   428,   429,    -1,   251,    -1,
     253,    99,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,   377,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,   461,    -1,
     463,    -1,   416,    -1,    -1,    -1,    -1,    -1,   471,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,   416,    -1,    -1,   491,    -1,
      -1,    -1,    -1,   496,    -1,    -1,    -1,   428,   429,   322,
     503,    -1,   505,    -1,    -1,    -1,    -1,   461,   511,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
     461,    -1,    -1,   201,    -1,    -1,    -1,   491,    -1,    -1,
     471,    -1,   496,    -1,   212,    -1,    -1,    -1,    -1,   503,
      -1,   505,    -1,    82,   377,    -1,    -1,   511,    -1,    -1,
     491,    -1,    -1,    -1,    -1,   496,    -1,    -1,    -1,    -1,
      99,    -1,   503,    -1,   505,    -1,    -1,   245,    -1,    -1,
     511,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,   416,    -1,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   461,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,
      -1,    -1,    32,    -1,   322,    35,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,   491,    -1,
      -1,    -1,   201,   496,    -1,    -1,    -1,    -1,   346,    -1,
     503,    -1,   505,   212,    64,    -1,    66,    -1,   511,    -1,
      -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   461,    -1,   175,    -1,    -1,   178,   179,
     180,   181,   182,   471,    -1,   185,   186,    -1,    -1,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   346,   198,    -1,
      -1,    -1,    -1,   491,   204,    -1,    -1,    -1,   496,    -1,
      -1,   211,    -1,    -1,    -1,   503,    -1,   505,    -1,   219,
      -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,
      -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,   318,   319,
      -1,    -1,   471,    -1,    -1,    -1,    -1,   327,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,   491,   343,    -1,   345,    -1,   496,    -1,    -1,
      -1,    -1,    -1,    -1,   503,    -1,   505,    -1,    -1,    -1,
      -1,    21,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    36,    -1,   378,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   395,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,   405,    -1,   407,   408,   409,
      -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,   447,    -1,    -1,
      -1,    -1,   452,    -1,    -1,    -1,    -1,   457,    -1,   119,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,
      -1,    -1,    -1,    -1,   474,    -1,   119,    -1,   478,   479,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   492,    -1,    -1,    -1,    -1,    -1,   498,   499,
      -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,   204,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,   219,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,   212,   235,   219,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,   277,   256,    -1,
     258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,
     119,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,
      -1,    -1,    -1,    -1,    -1,   303,    -1,   327,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
      -1,    -1,    -1,   343,   322,    -1,    -1,   330,    -1,   178,
     179,   180,   181,   182,    -1,   355,   185,   186,    -1,    -1,
     343,    -1,    -1,   363,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,   232,    -1,   405,   235,   407,   408,   409,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,   408,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,
     428,   429,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,
      -1,   449,    -1,    -1,    -1,    -1,   305,    -1,   478,   479,
     480,   459,    -1,   461,    -1,   463,   464,    -1,    -1,    -1,
     319,    -1,   492,   471,    -1,   478,   479,   480,   327,   499,
      -1,   330,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,   343,    -1,    -1,    -1,   496,    -1,
      -1,    -1,    -1,    -1,    -1,   503,   355,   505,    -1,    -1,
      -1,    -1,    -1,   511,   363,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,   405,    -1,   407,   408,
     409,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    99,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   452,    -1,    -1,    -1,   119,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,
     479,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,   160,    -1,
     499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,    -1,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,    -1,
      -1,    -1,   204,   201,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,   212,    -1,    -1,   219,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,   212,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
     252,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     258,   259,   260,   265,    -1,   245,   264,    -1,   266,    -1,
      -1,   251,    -1,   253,    -1,   277,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   305,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,    -1,
      -1,    -1,    -1,   303,   322,   327,    -1,    -1,   330,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   343,   322,   345,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,   371,
      82,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   395,    -1,    -1,    82,   377,    -1,    -1,
      -1,    -1,    -1,   405,    -1,   407,   408,   409,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,   428,   429,
     452,   449,    -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,
      -1,   459,    -1,   461,    -1,   463,   464,    -1,    82,   449,
      -1,    -1,   474,   471,    -1,    -1,   478,   479,   480,   459,
      -1,   461,    -1,   463,   464,    99,    -1,    -1,    -1,   201,
     492,   471,    -1,   491,    -1,    -1,   498,   499,   496,    -1,
     212,    -1,    -1,    -1,    -1,   503,    -1,   505,    -1,    -1,
      -1,   491,    -1,   511,    -1,   201,   496,    -1,    -1,    -1,
      -1,    -1,    -1,   503,    -1,   505,   212,    -1,    -1,    -1,
      -1,   511,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,
     256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,   346,    -1,   322,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,   303,
      -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,   459,    -1,   461,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,   471,
      -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   461,    -1,    -1,    -1,   491,
      -1,    -1,    -1,    -1,   496,   471,    -1,    -1,    -1,    -1,
      -1,   503,    -1,   505,    -1,    -1,    -1,    -1,    -1,   511,
      -1,    -1,   416,    -1,    -1,   491,    -1,    -1,    -1,    -1,
     496,    -1,    -1,    -1,   428,   429,    -1,   503,    -1,   505,
      -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,
      -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,   503,
      -1,   505,    -1,    -1,    -1,    -1,    -1,   511
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   514,   515,     0,   200,   341,   516,   517,   518,   519,
     520,   521,   523,   533,   535,   452,   452,   518,   153,   529,
     541,   529,   529,   256,   342,   536,   536,   122,    84,   542,
     522,   524,   533,   138,   527,   528,    26,   537,   537,   452,
     394,   543,   142,   522,   525,   526,   529,   536,   256,   452,
     534,   452,    11,    58,    96,    98,   100,   108,   164,   226,
     257,   301,   304,   369,   390,   415,   417,   433,   505,   544,
     545,   549,   560,   568,   569,   570,   571,   572,   577,   585,
     587,   592,   595,   596,   598,   599,   600,   601,   602,   603,
     604,   536,   524,   452,   232,   538,  1268,   505,  1188,  1188,
     423,   405,  1286,  1268,  1268,  1268,   394,  1188,   405,   452,
     452,  1268,   452,   452,    57,  1256,   573,     1,   452,   571,
     218,   586,   173,   605,   452,   526,   452,    72,   171,   354,
     457,   539,   540,   578,  1268,  1268,  1268,   505,  1183,  1214,
      68,  1183,   452,  1268,  1268,   550,   561,  1183,   546,   505,
     588,   589,   590,  1189,   256,   307,   309,   574,   576,  1033,
    1217,  1268,   452,   505,   452,   607,   540,   340,  1283,  1268,
     212,   256,   266,   346,   416,   461,   511,   593,   594,  1220,
    1183,   256,   218,   306,  1306,   256,   469,    56,    63,   268,
     340,   396,   401,   505,   551,   552,   553,   554,   555,   556,
     557,   559,  1255,  1316,   199,   562,   563,   564,   547,   559,
     589,    22,   232,  1189,  1269,  1033,   232,   423,  1280,  1268,
      96,  1188,   234,   397,   606,   608,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   511,   579,   580,   581,
     584,   594,   443,   504,   597,  1299,  1214,   400,   401,   410,
      63,  1268,   452,   553,   452,   505,   552,    59,  1268,     9,
     370,   497,   565,   567,     1,   452,   564,   548,  1299,   256,
     591,  1218,  1280,   232,  1188,  1188,   575,   576,   452,     1,
     290,   312,  1241,   274,   388,   639,   640,   641,   642,   644,
     581,    17,   443,  1220,   328,  1268,   401,  1217,   452,  1268,
     505,  1184,   229,    26,   566,   229,   370,   452,   452,   107,
    1218,  1188,   452,   312,  1188,   645,   351,   412,   413,   643,
     530,     1,   452,   641,   582,   584,   256,  1217,   257,   435,
     495,   558,  1184,   256,   272,   609,   455,  1259,    23,  1250,
     102,   649,   452,   583,   584,    57,   506,  1310,   610,   438,
    1292,   188,  1261,   122,   455,   650,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   452,   455,   611,   612,   618,   620,   621,   622,   623,
     624,   625,   628,   629,   630,   631,   632,   634,   635,   637,
    1284,  1300,    86,  1257,   505,  1173,  1174,   452,   394,   651,
     584,   272,  1275,   351,  1284,   447,   498,  1296,   401,   402,
    1268,  1255,   113,   237,  1270,  1270,   287,   636,  1217,  1299,
     423,   262,    39,  1253,  1268,   646,   647,  1174,  1174,   452,
     172,   392,   531,   652,   653,   655,  1268,  1270,   125,   171,
     615,   359,   629,  1268,  1268,  1268,  1268,  1250,     9,   287,
     349,   638,  1268,  1275,   402,   505,   647,   331,   648,   507,
     680,   682,   683,     1,  1174,   125,   347,   402,   619,  1268,
     117,   118,   119,   238,   252,   335,   347,   438,   613,   614,
     256,  1183,  1187,   419,   633,  1183,  1183,   316,  1281,  1281,
     310,  1183,  1268,  1217,   394,   261,   733,   684,   685,   687,
     697,  1233,   452,   654,   633,   256,   617,  1214,   617,     7,
     617,   617,   256,   616,  1214,   414,   453,    33,   167,   267,
     626,   452,   394,   255,   735,   452,   685,   452,     1,   175,
     505,   688,   689,   505,   656,   124,   504,  1235,  1315,  1259,
    1268,  1182,  1183,   504,   627,   627,   681,   452,   394,   366,
     737,   452,   452,   686,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   452,   499,   657,   658,   660,   664,
     665,   668,   669,   675,   676,   677,   678,  1268,   124,  1182,
    1183,   262,   385,   682,   734,   452,   394,   389,   782,   699,
     690,  1268,  1257,  1268,   351,   353,  1311,  1311,  1268,  1257,
    1268,  1275,  1268,    22,  1249,   306,   679,  1188,   171,   204,
     309,   682,   736,   452,   394,   532,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   478,   479,   480,   492,
     499,   700,   701,   702,   704,   705,   706,   707,   708,   709,
     710,   713,   722,   723,   724,   725,   726,   731,   732,  1268,
    1288,    26,   196,   698,  1251,   204,  1217,   505,  1268,  1249,
     505,  1185,  1186,   308,   418,  1307,  1187,  1217,   500,  1268,
     174,   213,   505,   666,  1188,   274,   351,   353,  1309,   682,
     738,   452,   337,   796,   799,   244,   301,   406,   477,  1287,
     477,  1287,   477,  1287,   477,  1287,   477,  1287,   502,  1297,
     384,  1285,  1217,  1211,  1214,  1214,   232,   242,   384,  1271,
    1268,  1269,   171,   204,   241,   469,   505,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   461,   511,   691,  1221,
    1222,  1223,   447,   663,  1186,   254,  1274,   447,  1256,   218,
    1263,   505,  1268,  1268,  1309,   739,   783,   122,   822,   823,
     511,   447,   714,   463,  1215,  1216,   443,   707,   728,   729,
    1221,    26,   703,   400,  1245,  1245,  1223,   306,  1278,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   692,   693,   694,   695,   696,   708,
     709,  1211,   692,   448,  1217,    57,   353,   659,   670,  1217,
     410,  1289,   256,   667,  1214,   667,   348,   740,   687,   697,
     784,   785,   786,    55,   498,   800,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   439,   452,   470,   476,   481,   508,   824,   825,
     841,   846,   850,   855,   870,   873,   877,   881,   882,   883,
     888,   902,   906,   909,   923,   927,   930,   933,   937,   938,
     942,   952,   955,   972,   974,   977,   981,   987,   999,  1007,
    1008,  1011,  1012,  1016,  1021,  1022,  1030,  1045,  1055,  1064,
    1069,  1076,  1080,  1082,  1085,  1088,  1092,  1119,   824,  1217,
     446,  1294,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   459,   463,   464,
     471,   491,   496,   503,  1161,  1163,  1164,  1165,  1166,  1167,
    1168,  1196,  1210,  1211,  1222,  1224,  1225,  1226,  1227,   463,
    1216,  1214,   727,   729,   443,   256,  1255,   692,   452,  1223,
      48,   466,   671,   672,   673,   674,  1299,  1256,   196,   662,
    1262,   505,  1175,     1,   688,   786,   452,   802,   801,   376,
     808,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   439,   452,   470,   476,   481,
     508,  1246,   826,   842,   847,   851,   856,   871,   874,   878,
     884,   889,   903,   907,   910,   924,   928,   931,   934,   203,
     376,   865,   926,   939,   943,   953,   956,   973,   975,   978,
     399,   982,   988,  1000,  1009,  1013,  1017,  1023,  1031,  1046,
    1056,   256,   346,   387,   416,   511,  1068,  1070,  1077,   336,
    1081,  1083,   811,  1086,  1089,  1093,  1120,   114,   715,   463,
    1229,  1211,  1222,  1224,  1306,  1306,   463,   463,   463,   463,
    1306,  1167,  1163,  1167,   463,  1229,    70,   398,   449,  1162,
     450,   459,   464,   451,   460,   169,   463,  1228,   463,   463,
    1163,   502,   730,  1298,  1221,  1187,  1187,   187,   663,  1217,
     741,   452,   787,   452,    49,   803,   804,   805,  1254,   803,
     505,   452,   308,   827,   828,  1210,     6,    94,   245,   271,
     843,  1168,  1192,  1193,  1210,  1221,  1224,   848,  1163,  1210,
     256,   852,   853,  1179,  1180,  1181,  1214,   271,   422,   424,
     857,   858,   256,   872,  1201,  1210,   875,  1174,     6,   879,
    1169,  1170,  1191,  1212,  1213,  1214,  1222,   455,   885,  1174,
     256,   890,   891,   893,  1192,  1193,  1201,  1210,   904,  1193,
     256,   908,   454,   465,   911,   912,   913,  1151,  1152,  1153,
     199,   323,   324,   340,   394,   925,   929,  1190,  1191,   932,
    1214,   447,   935,  1295,  1193,  1150,  1151,   944,  1190,   954,
    1175,   957,   958,  1210,  1221,  1224,  1047,  1208,  1209,  1214,
      94,   976,  1193,   979,  1193,   170,   225,   233,   317,   983,
     984,   190,   256,   989,   993,   994,   995,  1179,  1202,  1210,
    1214,  1224,  1299,  1001,  1174,  1010,  1171,  1214,  1014,  1174,
    1018,  1171,     9,  1024,  1172,  1214,   153,   271,  1032,  1035,
    1036,  1039,  1040,  1041,  1042,  1043,  1044,  1176,  1177,  1190,
    1207,  1209,  1214,  1047,  1057,  1174,  1065,   112,  1071,  1072,
    1073,  1193,    94,  1078,  1192,  1084,  1175,   452,   505,   812,
     813,   816,   817,   822,  1087,  1210,  1090,  1174,  1094,  1210,
    1121,  1171,   309,  1279,   716,   717,   449,  1161,  1163,   505,
     505,  1163,  1232,  1232,  1232,  1195,  1210,  1222,  1224,  1231,
     505,   449,  1195,  1230,  1163,   449,  1163,  1164,  1164,  1165,
    1165,  1165,  1163,  1195,  1161,   403,   454,    30,  1252,  1256,
       1,   742,   788,   804,   410,   477,   806,   357,   499,   797,
     130,   840,    30,   830,   831,  1252,   196,  1278,  1210,  1211,
    1222,  1224,   131,   845,   447,   844,  1193,    57,   223,  1236,
     853,   447,  1306,   132,   869,   256,  1202,  1201,  1174,   356,
     475,   876,  1299,  1312,  1278,   133,   880,   159,   453,  1170,
    1303,   386,  1242,  1215,  1216,   886,  1174,   134,   887,  1284,
     135,   901,   165,   892,  1130,  1131,   485,   894,   504,   831,
     486,   487,   488,   489,   136,   905,    49,   228,   498,   859,
     137,   922,    17,   502,   914,   915,   916,   918,    12,    13,
      14,    20,   159,   169,   207,   208,   246,   247,   284,   290,
     293,   301,   308,   313,   332,   449,   451,   453,   456,   458,
     459,   460,   463,   464,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1193,   101,   926,  1191,  1178,   442,  1293,   945,  1299,
    1175,    92,   365,   437,   959,   960,   962,   963,  1049,   463,
    1215,  1193,   447,   140,   980,    49,   984,   404,   985,   994,
     141,   452,   990,   992,   482,   500,   443,   446,   440,   143,
    1006,   285,   334,  1239,   196,  1122,   144,  1015,  1284,   145,
    1020,  1122,  1172,   146,  1029,   500,  1025,  1199,  1210,  1222,
    1042,  1044,  1190,   447,  1177,   123,   447,   483,  1034,    31,
    1215,   147,  1063,   177,   237,   240,  1059,   865,  1066,  1299,
    1254,   148,  1075,   228,  1073,  1210,   149,  1079,   196,  1175,
     394,   452,   452,   196,   351,   353,  1091,   150,  1103,   112,
    1095,   151,  1126,  1122,  1183,   220,   719,    27,   115,   718,
     449,  1162,   449,   449,   449,  1162,   449,  1162,   449,   449,
     450,   449,   449,   447,  1268,  1187,   114,   661,   452,    61,
      89,    90,   321,   452,   743,   744,   747,  1268,  1324,    32,
      35,    38,    45,    46,    64,    66,   160,   189,   196,   198,
     211,   243,   252,   265,   305,   318,   345,   371,   378,   395,
     447,   457,   474,   498,   705,   706,   710,   722,   724,   726,
     789,   794,   795,  1268,  1301,  1268,   410,   312,   807,   109,
     809,  1199,   197,   834,   252,   331,   832,   833,  1301,    24,
      25,    65,    67,    69,   103,   104,   105,   153,   155,   162,
     165,   252,   254,   444,   494,   505,   829,  1177,  1302,   152,
     340,  1197,  1211,   447,     6,  1169,  1193,  1214,  1222,   203,
     223,  1237,   376,   849,   339,   854,  1181,   859,   876,   262,
     287,  1261,  1211,  1163,   272,  1243,  1216,  1174,   231,  1146,
    1147,   819,   820,   893,  1193,   294,  1132,    96,   335,   505,
    1177,   298,   898,    35,    38,    45,    46,    91,   160,   189,
     211,   265,   318,   378,   391,   474,   899,   900,   485,   895,
    1130,  1130,  1130,  1130,  1193,  1169,  1193,   860,   913,    21,
     454,   465,   919,   920,  1152,   502,   916,   917,   502,   819,
    1295,   232,  1155,   114,   936,  1179,   128,   819,   940,     9,
      12,    15,    16,   277,   278,   301,   302,   946,   950,   175,
    1199,     9,    57,   177,   241,   469,   966,   967,   968,   961,
     962,  1051,  1279,  1315,   447,  1190,  1169,  1193,   985,  1299,
    1173,   819,   168,   996,  1150,   997,   998,  1210,  1179,     8,
      37,  1124,  1284,  1206,  1210,  1221,  1224,   228,  1002,  1019,
    1299,   129,  1026,  1210,  1026,   447,   447,  1033,   152,   454,
     465,  1193,    49,    38,    46,   211,   243,   265,   318,   378,
     474,  1037,  1038,  1268,  1058,  1299,  1193,   161,   289,   410,
    1193,  1210,   196,  1169,  1193,   818,  1217,  1199,  1254,   228,
    1098,  1123,  1124,  1254,  1270,  1183,  1228,  1228,  1228,  1195,
     241,   469,  1228,   449,  1163,  1228,  1228,  1221,  1279,  1268,
    1268,  1249,   248,   249,  1273,   756,   204,   176,   745,  1260,
    1268,   252,   389,   156,   158,  1268,  1202,   299,  1276,  1217,
      56,  1210,  1210,   204,  1276,    32,   110,  1217,  1268,   505,
     452,   798,   272,   835,  1276,  1276,   833,   832,  1276,   165,
    1127,  1128,   510,   509,  1199,  1127,   237,   423,   299,   276,
     256,  1198,  1211,  1210,  1278,   411,  1133,  1134,  1215,  1216,
    1169,   447,  1238,   849,  1191,   447,  1179,   864,   865,   380,
     362,  1133,  1268,   819,   295,  1148,   821,   819,  1130,  1268,
     252,   389,   156,   158,  1268,   123,   483,   900,  1130,    96,
      97,   896,   835,   203,  1133,   203,   861,   862,   863,  1254,
      17,   443,   921,   316,   919,  1279,   819,   128,   139,   941,
    1295,   365,   947,  1295,   447,    49,   967,   969,  1199,     9,
      57,   241,   469,   964,   965,  1199,  1052,  1300,   718,   218,
     314,  1264,  1190,  1133,   203,  1173,   638,   379,   986,  1299,
     141,   991,     8,   196,  1002,  1210,   129,  1139,  1141,  1146,
     262,   287,   819,   502,   502,  1027,  1028,  1199,  1198,  1193,
    1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1038,   290,
     293,  1060,  1061,  1062,  1156,  1240,  1146,   244,   410,  1314,
     423,  1291,  1291,  1074,  1299,  1210,  1133,   203,   452,   447,
       9,  1096,  1097,  1234,  1099,  1210,  1074,  1099,  1019,     7,
    1247,   505,   720,   721,  1268,   449,  1183,  1201,  1268,  1249,
     256,   748,  1219,   687,   757,   746,  1210,   511,  1203,  1207,
    1217,  1203,  1268,  1294,  1268,  1268,    32,  1217,   810,   811,
    1268,   504,   836,  1203,  1203,  1203,   819,   294,  1129,  1127,
    1242,  1211,   819,   297,  1135,  1216,  1133,  1200,  1210,  1221,
     165,   462,   867,  1305,     6,   228,   308,   461,   866,  1267,
      34,   281,   282,   283,   344,   467,   468,   472,  1244,   819,
     822,  1203,  1203,  1149,  1205,  1207,  1217,  1149,   504,   897,
    1169,  1170,  1169,  1170,   862,   308,   806,    87,   357,   499,
     920,  1151,   819,  1210,   819,   499,   948,   949,   950,   951,
    1293,   499,  1200,  1199,    49,   970,   965,   188,   970,  1048,
    1268,  1270,   314,  1169,   986,   262,   287,   998,  1193,   217,
    1003,  1299,   819,   291,  1142,   262,  1151,  1150,  1027,  1156,
    1210,  1157,  1158,  1159,  1160,  1163,  1067,  1193,  1067,   462,
    1136,  1137,   330,  1242,  1169,   814,  1200,   313,  1199,   113,
    1100,   437,  1102,   157,   292,  1125,  1143,  1144,  1145,  1146,
     321,  1177,  1203,   721,  1182,   749,   252,   254,  1308,   505,
     688,  1210,   270,   329,   459,   464,   790,   791,   792,  1201,
     790,   791,   793,   811,    47,    32,    35,    38,    46,    91,
     110,   189,   198,   211,   243,   263,   265,   287,   288,   318,
     345,   371,   378,   391,   395,   436,   445,   474,   484,   490,
     837,   838,   839,  1127,   819,  1133,   819,   294,   868,   819,
    1278,  1210,   252,   254,  1313,   899,  1133,   361,  1133,   361,
    1193,   949,   102,  1258,  1295,   970,   970,  1200,     8,    37,
     971,   225,   498,  1053,  1183,  1050,  1133,   380,    49,   262,
     237,  1004,   216,   236,   262,   287,   501,   819,   819,   819,
     819,   296,  1138,  1268,  1133,  1133,   493,   815,  1104,  1097,
    1263,    95,  1101,  1263,  1136,   819,   819,  1145,   252,   254,
    1272,   177,   187,   210,   240,   750,   751,   752,   753,   754,
     755,  1219,   758,  1203,  1203,   129,  1268,  1268,   839,    56,
     123,   483,     8,  1248,   838,   819,  1210,  1170,  1170,    49,
     110,   970,   457,  1266,  1266,   337,  1173,   203,   317,  1054,
    1214,  1193,  1268,  1005,  1140,  1141,  1142,  1146,   262,   262,
     262,   819,  1210,  1105,   452,  1210,  1263,  1210,   106,   116,
    1317,  1268,  1268,    54,    89,  1317,  1318,  1302,   759,   109,
    1203,  1203,  1268,  1149,  1149,  1204,  1207,  1219,  1133,  1133,
    1193,  1193,  1193,  1268,  1173,   337,   482,  1210,  1142,   127,
     166,   204,  1106,  1107,  1108,  1110,  1114,  1116,  1117,  1118,
    1252,  1261,  1210,  1268,  1219,  1219,   210,  1268,  1268,   209,
     252,   254,   285,   305,   333,   414,   431,   452,   473,   492,
     500,   705,   710,   711,   722,   724,   726,   760,   761,   765,
     766,   769,   770,   771,   772,   773,   774,   779,   780,   781,
    1301,  1302,   452,  1201,   993,  1268,  1150,    37,  1248,   340,
     107,  1219,  1219,  1219,   221,  1265,   299,   300,  1277,  1249,
     209,  1217,   502,  1268,  1278,  1268,  1268,  1210,   286,   329,
     775,   776,  1219,   329,   777,   778,  1219,  1277,  1249,   993,
     367,   418,  1290,   129,   421,  1115,  1279,  1269,  1268,   714,
    1150,  1196,  1194,  1196,    53,    89,   321,   325,   326,   366,
     382,   383,   762,  1317,  1318,  1319,  1320,  1321,  1322,  1323,
     119,   196,  1217,   776,  1217,   778,  1269,  1210,   161,   165,
    1304,     9,  1111,  1112,  1180,   776,  1294,  1242,   373,   767,
    1196,   187,   187,   210,   187,   210,   176,   763,  1210,   763,
    1196,   337,  1282,   306,   338,   358,  1113,  1112,   715,  1279,
     313,   764,   764,    49,  1279,   306,  1214,   425,   712,   176,
     768,  1210,   321,  1196,   170,   225,   233,   317,  1109,  1173,
    1217
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
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1464 of yacc.c  */
#line 1367 "parser.y"
    {
	clear_initial_values ();
	current_program = NULL;
	cobc_cs_check = 0;
	prog_end = 0;
	depth = 0;
	main_flag_set = 0;
	current_program = cb_build_program (NULL, 0);
	cb_build_registers ();
  ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 1378 "parser.y"
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
  ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 1414 "parser.y"
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
  ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 1469 "parser.y"
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
  ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 1498 "parser.y"
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
  ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 1531 "parser.y"
    {
	cb_validate_program_environment (current_program);
  ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 1537 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 1549 "parser.y"
    {
	cb_validate_program_data (current_program);
  ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 1559 "parser.y"
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
  ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 1590 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 1597 "parser.y"
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
  ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 1636 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 1637 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 1646 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 1655 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 1669 "parser.y"
    {
	current_program->flag_initial = 1;
  ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 1673 "parser.y"
    {
	current_program->flag_recursive = 1;
  ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 1683 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 1692 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if (current_program->nested_level) {
		cb_error (_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 1717 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("SOURCE-COMPUTER", SYN_CLAUSE_1);
	if (warningopt && (check_comp_duplicate & SYN_CLAUSE_2)) {
		cb_warning (_("Phrases in non-standard order"));
	}
  ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 1735 "parser.y"
    {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item ();
  ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 1748 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 1777 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1784 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 1791 "parser.y"
    {
	/* Ignore */
  ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1798 "parser.y"
    {
	if (current_program->classification) {
		cb_error (_("Duplicate CLASSIFICATION clause"));
	} else {
		current_program->classification = (yyvsp[(4) - (4)]);
	}
  ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1809 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 1813 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 1817 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1821 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1835 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1840 "parser.y"
    {
	cobc_in_repository = 0;
  ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1848 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1860 "parser.y"
    {
	functions_are_all = 1;
  ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1864 "parser.y"
    {
	cb_tree		x;

	if ((yyvsp[(3) - (3)])) {
		x = (yyvsp[(3) - (3)]);
	} else {
		x = (yyvsp[(2) - (3)]);
	}
	current_program->user_spec_list =
		cb_list_add (current_program->user_spec_list, x);
  ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1885 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1889 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1896 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1901 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1912 "parser.y"
    {
	check_duplicate = 0;
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	header_check |= COBC_HD_SPECIAL_NAMES;
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	}
  ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1926 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1957 "parser.y"
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
  ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1976 "parser.y"
    {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_DEVICE_CONSOLE) {
			cb_error_x (save_tree, _("Invalid CRT clause"));
		} else {
			current_program->flag_console_is_crt = 1;
		}
	}
  ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1986 "parser.y"
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
  ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1999 "parser.y"
    {
	if (save_tree && CB_VALID_TREE ((yyvsp[(2) - (3)]))) {
		cb_define ((yyvsp[(2) - (3)]), save_tree);
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
				(yyvsp[(2) - (3)]), save_tree);
	}
  ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 2015 "parser.y"
    {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ((yyvsp[(3) - (3)]), save_tree, (yyvsp[(1) - (3)]) == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, (yyvsp[(3) - (3)]), x);
	}
  ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 2025 "parser.y"
    {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ((yyvsp[(4) - (4)]), save_tree, (yyvsp[(2) - (4)]) == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, (yyvsp[(4) - (4)]), x);
	}
  ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 2040 "parser.y"
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
  ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 2053 "parser.y"
    {
	if ((yyvsp[(3) - (5)])) {
		current_program->alphabet_name_list =
			cb_list_add (current_program->alphabet_name_list, (yyvsp[(3) - (5)]));
	}
	cobc_cs_check = 0;
  ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 2064 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 2070 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 2076 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 2082 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 2088 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 2094 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 2104 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 2108 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 2115 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 2119 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 2123 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 2127 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 2134 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 2138 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 2144 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 2145 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 2146 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 2147 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 2148 "parser.y"
    { (yyval) = cb_norm_high; ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 2149 "parser.y"
    { (yyval) = cb_norm_low; ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 2157 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else if ((yyvsp[(1) - (2)])) {
		CB_CHAIN_PAIR (current_program->symbolic_char_list, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 2171 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 2175 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 2183 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 2190 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 2194 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  ;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 2205 "parser.y"
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
  ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 2225 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 2233 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 2243 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 2244 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 2251 "parser.y"
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
  ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 2271 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2272 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 2277 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 2281 "parser.y"
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
  ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 2302 "parser.y"
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
  ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 2325 "parser.y"
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
  ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2406 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2410 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 2419 "parser.y"
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
  ;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 2438 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		current_program->flag_trailing_separate = 1;
	}
  ;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 2454 "parser.y"
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
  ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 2472 "parser.y"
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
  ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 2490 "parser.y"
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
  ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 2507 "parser.y"
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
  ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 2524 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  ;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 2532 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  ;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 2541 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  ;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 2556 "parser.y"
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
  ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2573 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2577 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2611 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2617 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_fileid = 1;
	}
  ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2627 "parser.y"
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
  ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2640 "parser.y"
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
  ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2653 "parser.y"
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
  ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2676 "parser.y"
    {
	current_file->flag_line_adv = 1;
  ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2683 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2696 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2708 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2715 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2716 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2717 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2725 "parser.y"
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
  ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2752 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2763 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2778 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 2786 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 2791 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 2796 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 2805 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 2809 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 2825 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 2830 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 2835 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 2840 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 2851 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 2862 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 2872 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 2879 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 2880 "parser.y"
    { PENDING ("SPLIT KEYS"); ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 2881 "parser.y"
    { PENDING ("SPLIT KEYS"); ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 2888 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 2899 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 2913 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 2920 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 2921 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 2922 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 2931 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 2950 "parser.y"
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
  ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 2977 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 2978 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 2979 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 2980 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 2987 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 2992 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3019 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3028 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3042 "parser.y"
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
  ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 3061 "parser.y"
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
  ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3078 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3085 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3089 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3100 "parser.y"
    {
	check_repeated ("EXTERNAL", SYN_CLAUSE_1);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_global) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	current_file->flag_external = 1;
  ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3110 "parser.y"
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
  ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3140 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3153 "parser.y"
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
  ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3173 "parser.y"
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
  ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3208 "parser.y"
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
  ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3239 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3245 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3246 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3250 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3251 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3259 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3270 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3275 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3298 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3310 "parser.y"
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
  ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3338 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3345 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3352 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3361 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3373 "parser.y"
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
  ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3425 "parser.y"
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
  ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3445 "parser.y"
    {
	current_report = build_report ((yyvsp[(1) - (1)]));
	current_report->file = current_file;
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3455 "parser.y"
    {
	current_report = build_report ((yyvsp[(2) - (2)]));
	CB_ADD_TO_CHAIN (CB_TREE (current_report), current_program->report_list);
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3495 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3501 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3510 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3513 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3519 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 3539 "parser.y"
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
  ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 3554 "parser.y"
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
  ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 3574 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 3587 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3594 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3600 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3606 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 3615 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 3624 "parser.y"
    {
	(yyval)= NULL;
  ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 3628 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 3639 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3640 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3641 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 3642 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 3647 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 3651 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 3655 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 3659 "parser.y"
    {
	(yyval) = cb_int4;
  ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 3663 "parser.y"
    {
	(yyval) = cb_int (8);
  ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 3667 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 3671 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 3675 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 3679 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 3683 "parser.y"
    {
	(yyval) = cb_int (4);
  ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 3687 "parser.y"
    {
	(yyval) = cb_int (8);
  ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 3691 "parser.y"
    {
	(yyval) = cb_int (16);
  ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 3695 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 3727 "parser.y"
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
  ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 3753 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 3757 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 3765 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 3771 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 3799 "parser.y"
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
  ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 3823 "parser.y"
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
  ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 3850 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 3854 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 3863 "parser.y"
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
  ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 3888 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 3904 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 3908 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 3912 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 3916 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 3920 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  ;}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 3924 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 3928 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 3932 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 3936 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 3940 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 3944 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 3948 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 3952 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 3957 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 3962 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 3966 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 3970 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  ;}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 3978 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 3982 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 3986 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 3994 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 3998 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  ;}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 4002 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4006 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4010 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4014 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  ;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 4018 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4022 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  ;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 4026 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  ;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 4034 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  ;}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 4042 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  ;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 4046 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  ;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 4050 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  ;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 4054 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  ;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 4058 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  ;}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 4062 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  ;}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 4082 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  ;}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 4088 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  ;}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 4101 "parser.y"
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
  ;}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 4119 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 4129 "parser.y"
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
  ;}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 4151 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 4152 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 4157 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 4164 "parser.y"
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
  ;}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 4187 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 4190 "parser.y"
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
  ;}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 4205 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); ;}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 4206 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); ;}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 4211 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 4217 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 4219 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 4224 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  ;}
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 4235 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  ;}
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 4246 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  ;}
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 4257 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  ;}
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 4268 "parser.y"
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
  ;}
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 4296 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 4304 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 4305 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 4309 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 4310 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 4315 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 4328 "parser.y"
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
  ;}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 4341 "parser.y"
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
  ;}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 4362 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  ;}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 4371 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
		current_field->flag_any_numeric = 1;
	}
  ;}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 4386 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  ;}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 4395 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 4407 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  ;}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 4413 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 4424 "parser.y"
    {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  ;}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 4440 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  ;}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 4455 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 4462 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  ;}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 4467 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  ;}
    break;

  case 507:

/* Line 1464 of yacc.c  */
#line 4478 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  ;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 4497 "parser.y"
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
  ;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 4533 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 4537 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  ;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 4542 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  ;}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 4562 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 4569 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 4576 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 4583 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 4590 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 4601 "parser.y"
    {
	check_pic_duplicate = 0;
  ;}
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 4632 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  ;}
    break;

  case 562:

/* Line 1464 of yacc.c  */
#line 4658 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  ;}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 4665 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  ;}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 4681 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  ;}
    break;

  case 570:

/* Line 1464 of yacc.c  */
#line 4692 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  ;}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 4704 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  ;}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 4737 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  ;}
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 4744 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  ;}
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 4751 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  ;}
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 4760 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  ;}
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 4767 "parser.y"
    {
	struct cb_field *p;

	if (description_field) {
		for (p = description_field; p; p = p->sister) {
			cb_validate_field (p);
		}
		current_program->screen_storage = description_field;
		current_program->flag_screen = 1;
	}
  ;}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 4793 "parser.y"
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
  ;}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 4824 "parser.y"
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
  ;}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 4850 "parser.y"
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
  ;}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 4873 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  ;}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 4877 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  ;}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 4881 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  ;}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 4885 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  ;}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 4889 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  ;}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 4893 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  ;}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 4897 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 4901 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 4905 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  ;}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 4909 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 4913 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  ;}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 4917 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 4921 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  ;}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 4925 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  ;}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 4929 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  ;}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 4933 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  ;}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 4937 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 4942 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  ;}
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 4946 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  ;}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 4950 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  ;}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 4955 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  ;}
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 4960 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 4965 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 632:

/* Line 1464 of yacc.c  */
#line 4978 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  ;}
    break;

  case 633:

/* Line 1464 of yacc.c  */
#line 4985 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 634:

/* Line 1464 of yacc.c  */
#line 4990 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  ;}
    break;

  case 639:

/* Line 1464 of yacc.c  */
#line 5009 "parser.y"
    {
	/* Nothing */
  ;}
    break;

  case 640:

/* Line 1464 of yacc.c  */
#line 5013 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  ;}
    break;

  case 641:

/* Line 1464 of yacc.c  */
#line 5017 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  ;}
    break;

  case 642:

/* Line 1464 of yacc.c  */
#line 5024 "parser.y"
    {
	/* Nothing */
  ;}
    break;

  case 643:

/* Line 1464 of yacc.c  */
#line 5028 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  ;}
    break;

  case 644:

/* Line 1464 of yacc.c  */
#line 5032 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  ;}
    break;

  case 645:

/* Line 1464 of yacc.c  */
#line 5040 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  ;}
    break;

  case 646:

/* Line 1464 of yacc.c  */
#line 5051 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  ;}
    break;

  case 648:

/* Line 1464 of yacc.c  */
#line 5060 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	cb_set_system_names ();
	header_check |= COBC_HD_PROCEDURE_DIVISION;
  ;}
    break;

  case 649:

/* Line 1464 of yacc.c  */
#line 5070 "parser.y"
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
  ;}
    break;

  case 650:

/* Line 1464 of yacc.c  */
#line 5082 "parser.y"
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
  ;}
    break;

  case 651:

/* Line 1464 of yacc.c  */
#line 5097 "parser.y"
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
  ;}
    break;

  case 653:

/* Line 1464 of yacc.c  */
#line 5130 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 654:

/* Line 1464 of yacc.c  */
#line 5134 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  ;}
    break;

  case 655:

/* Line 1464 of yacc.c  */
#line 5139 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 656:

/* Line 1464 of yacc.c  */
#line 5147 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  ;}
    break;

  case 657:

/* Line 1464 of yacc.c  */
#line 5156 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 658:

/* Line 1464 of yacc.c  */
#line 5166 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 659:

/* Line 1464 of yacc.c  */
#line 5168 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 660:

/* Line 1464 of yacc.c  */
#line 5173 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  ;}
    break;

  case 662:

/* Line 1464 of yacc.c  */
#line 5182 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  ;}
    break;

  case 663:

/* Line 1464 of yacc.c  */
#line 5186 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  ;}
    break;

  case 665:

/* Line 1464 of yacc.c  */
#line 5198 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  ;}
    break;

  case 666:

/* Line 1464 of yacc.c  */
#line 5206 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  ;}
    break;

  case 667:

/* Line 1464 of yacc.c  */
#line 5214 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  ;}
    break;

  case 668:

/* Line 1464 of yacc.c  */
#line 5222 "parser.y"
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
  ;}
    break;

  case 669:

/* Line 1464 of yacc.c  */
#line 5251 "parser.y"
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
  ;}
    break;

  case 671:

/* Line 1464 of yacc.c  */
#line 5284 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  ;}
    break;

  case 672:

/* Line 1464 of yacc.c  */
#line 5293 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  ;}
    break;

  case 673:

/* Line 1464 of yacc.c  */
#line 5299 "parser.y"
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
  ;}
    break;

  case 675:

/* Line 1464 of yacc.c  */
#line 5327 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  ;}
    break;

  case 676:

/* Line 1464 of yacc.c  */
#line 5333 "parser.y"
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
  ;}
    break;

  case 681:

/* Line 1464 of yacc.c  */
#line 5371 "parser.y"
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
  ;}
    break;

  case 683:

/* Line 1464 of yacc.c  */
#line 5389 "parser.y"
    {
	/* check_unreached = 0; */
  ;}
    break;

  case 684:

/* Line 1464 of yacc.c  */
#line 5399 "parser.y"
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
  ;}
    break;

  case 685:

/* Line 1464 of yacc.c  */
#line 5443 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  ;}
    break;

  case 688:

/* Line 1464 of yacc.c  */
#line 5454 "parser.y"
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
  ;}
    break;

  case 689:

/* Line 1464 of yacc.c  */
#line 5502 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  ;}
    break;

  case 690:

/* Line 1464 of yacc.c  */
#line 5514 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 691:

/* Line 1464 of yacc.c  */
#line 5518 "parser.y"
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
  ;}
    break;

  case 692:

/* Line 1464 of yacc.c  */
#line 5536 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  ;}
    break;

  case 693:

/* Line 1464 of yacc.c  */
#line 5541 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  ;}
    break;

  case 694:

/* Line 1464 of yacc.c  */
#line 5546 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  ;}
    break;

  case 695:

/* Line 1464 of yacc.c  */
#line 5554 "parser.y"
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
  ;}
    break;

  case 696:

/* Line 1464 of yacc.c  */
#line 5581 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 697:

/* Line 1464 of yacc.c  */
#line 5585 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 747:

/* Line 1464 of yacc.c  */
#line 5641 "parser.y"
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
  ;}
    break;

  case 748:

/* Line 1464 of yacc.c  */
#line 5655 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  ;}
    break;

  case 749:

/* Line 1464 of yacc.c  */
#line 5666 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
	if (cb_accept_update) {
		check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
	}
	if (cb_accept_auto) {
		check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
	}

  ;}
    break;

  case 751:

/* Line 1464 of yacc.c  */
#line 5683 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  ;}
    break;

  case 752:

/* Line 1464 of yacc.c  */
#line 5688 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  ;}
    break;

  case 753:

/* Line 1464 of yacc.c  */
#line 5692 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  ;}
    break;

  case 754:

/* Line 1464 of yacc.c  */
#line 5696 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 755:

/* Line 1464 of yacc.c  */
#line 5701 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 756:

/* Line 1464 of yacc.c  */
#line 5706 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 757:

/* Line 1464 of yacc.c  */
#line 5711 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 758:

/* Line 1464 of yacc.c  */
#line 5716 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 759:

/* Line 1464 of yacc.c  */
#line 5720 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 760:

/* Line 1464 of yacc.c  */
#line 5724 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 761:

/* Line 1464 of yacc.c  */
#line 5728 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 762:

/* Line 1464 of yacc.c  */
#line 5732 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 763:

/* Line 1464 of yacc.c  */
#line 5737 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 764:

/* Line 1464 of yacc.c  */
#line 5741 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 765:

/* Line 1464 of yacc.c  */
#line 5745 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  ;}
    break;

  case 766:

/* Line 1464 of yacc.c  */
#line 5749 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 767:

/* Line 1464 of yacc.c  */
#line 5753 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 768:

/* Line 1464 of yacc.c  */
#line 5757 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 769:

/* Line 1464 of yacc.c  */
#line 5761 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 771:

/* Line 1464 of yacc.c  */
#line 5769 "parser.y"
    {
	(yyval) = cb_null;
  ;}
    break;

  case 774:

/* Line 1464 of yacc.c  */
#line 5780 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 775:

/* Line 1464 of yacc.c  */
#line 5781 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 776:

/* Line 1464 of yacc.c  */
#line 5785 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 777:

/* Line 1464 of yacc.c  */
#line 5786 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 778:

/* Line 1464 of yacc.c  */
#line 5787 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); ;}
    break;

  case 779:

/* Line 1464 of yacc.c  */
#line 5788 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); ;}
    break;

  case 780:

/* Line 1464 of yacc.c  */
#line 5789 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 781:

/* Line 1464 of yacc.c  */
#line 5793 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 782:

/* Line 1464 of yacc.c  */
#line 5797 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 783:

/* Line 1464 of yacc.c  */
#line 5798 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 787:

/* Line 1464 of yacc.c  */
#line 5807 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 792:

/* Line 1464 of yacc.c  */
#line 5823 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  ;}
    break;

  case 793:

/* Line 1464 of yacc.c  */
#line 5827 "parser.y"
    {
	if (cb_accept_auto) {
		remove_attrib (COB_SCREEN_AUTO);
	}
  ;}
    break;

  case 794:

/* Line 1464 of yacc.c  */
#line 5833 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  ;}
    break;

  case 795:

/* Line 1464 of yacc.c  */
#line 5837 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  ;}
    break;

  case 796:

/* Line 1464 of yacc.c  */
#line 5841 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  ;}
    break;

  case 797:

/* Line 1464 of yacc.c  */
#line 5845 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  ;}
    break;

  case 798:

/* Line 1464 of yacc.c  */
#line 5849 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 799:

/* Line 1464 of yacc.c  */
#line 5853 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 800:

/* Line 1464 of yacc.c  */
#line 5857 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  ;}
    break;

  case 801:

/* Line 1464 of yacc.c  */
#line 5861 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 802:

/* Line 1464 of yacc.c  */
#line 5865 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  ;}
    break;

  case 803:

/* Line 1464 of yacc.c  */
#line 5869 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  ;}
    break;

  case 804:

/* Line 1464 of yacc.c  */
#line 5873 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  ;}
    break;

  case 805:

/* Line 1464 of yacc.c  */
#line 5877 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  ;}
    break;

  case 806:

/* Line 1464 of yacc.c  */
#line 5881 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  ;}
    break;

  case 807:

/* Line 1464 of yacc.c  */
#line 5885 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  ;}
    break;

  case 808:

/* Line 1464 of yacc.c  */
#line 5889 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  ;}
    break;

  case 809:

/* Line 1464 of yacc.c  */
#line 5893 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 810:

/* Line 1464 of yacc.c  */
#line 5897 "parser.y"
    {
	if (cb_accept_update) {
		remove_attrib (COB_SCREEN_UPDATE);
	}
  ;}
    break;

  case 811:

/* Line 1464 of yacc.c  */
#line 5903 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  ;}
    break;

  case 812:

/* Line 1464 of yacc.c  */
#line 5907 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  ;}
    break;

  case 813:

/* Line 1464 of yacc.c  */
#line 5911 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  ;}
    break;

  case 814:

/* Line 1464 of yacc.c  */
#line 5915 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  ;}
    break;

  case 815:

/* Line 1464 of yacc.c  */
#line 5919 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  ;}
    break;

  case 816:

/* Line 1464 of yacc.c  */
#line 5923 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  ;}
    break;

  case 817:

/* Line 1464 of yacc.c  */
#line 5927 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  ;}
    break;

  case 820:

/* Line 1464 of yacc.c  */
#line 5939 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  ;}
    break;

  case 821:

/* Line 1464 of yacc.c  */
#line 5943 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
# if 0 /* activate only for debugging purposes for attribs */
	if (current_statement->attr_ptr) {
		printBits (current_statement->attr_ptr->dispattrs);
	} else {
		fprintf(stderr, "No Attribs\n");
	}
#endif
  ;}
    break;

  case 822:

/* Line 1464 of yacc.c  */
#line 5960 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  ;}
    break;

  case 824:

/* Line 1464 of yacc.c  */
#line 5969 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  ;}
    break;

  case 825:

/* Line 1464 of yacc.c  */
#line 5973 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  ;}
    break;

  case 826:

/* Line 1464 of yacc.c  */
#line 5977 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 828:

/* Line 1464 of yacc.c  */
#line 5984 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 829:

/* Line 1464 of yacc.c  */
#line 5991 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  ;}
    break;

  case 830:

/* Line 1464 of yacc.c  */
#line 5995 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  ;}
    break;

  case 831:

/* Line 1464 of yacc.c  */
#line 6005 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  ;}
    break;

  case 833:

/* Line 1464 of yacc.c  */
#line 6014 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  ;}
    break;

  case 834:

/* Line 1464 of yacc.c  */
#line 6018 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  ;}
    break;

  case 835:

/* Line 1464 of yacc.c  */
#line 6029 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 836:

/* Line 1464 of yacc.c  */
#line 6030 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 837:

/* Line 1464 of yacc.c  */
#line 6038 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  ;}
    break;

  case 841:

/* Line 1464 of yacc.c  */
#line 6052 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 844:

/* Line 1464 of yacc.c  */
#line 6064 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  ;}
    break;

  case 846:

/* Line 1464 of yacc.c  */
#line 6079 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(2) - (6)])) &&
	    current_program->prog_type == CB_PROGRAM_TYPE &&
	    !current_program->flag_recursive &&
	    !strcmp ((const char *)(CB_LITERAL((yyvsp[(2) - (6)]))->data), current_program->orig_program_id)) {
		cb_warning_x ((yyvsp[(2) - (6)]), _("Recursive program call - assuming RECURSIVE attribute"));
		current_program->flag_recursive = 1;
	}
	cb_emit_call ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]), (yyvsp[(1) - (6)]));
  ;}
    break;

  case 847:

/* Line 1464 of yacc.c  */
#line 6093 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  ;}
    break;

  case 848:

/* Line 1464 of yacc.c  */
#line 6098 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  ;}
    break;

  case 849:

/* Line 1464 of yacc.c  */
#line 6103 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  ;}
    break;

  case 850:

/* Line 1464 of yacc.c  */
#line 6108 "parser.y"
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
  ;}
    break;

  case 851:

/* Line 1464 of yacc.c  */
#line 6128 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 852:

/* Line 1464 of yacc.c  */
#line 6132 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  ;}
    break;

  case 853:

/* Line 1464 of yacc.c  */
#line 6137 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 854:

/* Line 1464 of yacc.c  */
#line 6148 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 855:

/* Line 1464 of yacc.c  */
#line 6150 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 856:

/* Line 1464 of yacc.c  */
#line 6155 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  ;}
    break;

  case 857:

/* Line 1464 of yacc.c  */
#line 6163 "parser.y"
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
  ;}
    break;

  case 859:

/* Line 1464 of yacc.c  */
#line 6189 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  ;}
    break;

  case 860:

/* Line 1464 of yacc.c  */
#line 6193 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  ;}
    break;

  case 861:

/* Line 1464 of yacc.c  */
#line 6202 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  ;}
    break;

  case 862:

/* Line 1464 of yacc.c  */
#line 6214 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 863:

/* Line 1464 of yacc.c  */
#line 6218 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 864:

/* Line 1464 of yacc.c  */
#line 6222 "parser.y"
    {
	(yyval) = cb_null;
  ;}
    break;

  case 865:

/* Line 1464 of yacc.c  */
#line 6226 "parser.y"
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
  ;}
    break;

  case 870:

/* Line 1464 of yacc.c  */
#line 6259 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 871:

/* Line 1464 of yacc.c  */
#line 6264 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 872:

/* Line 1464 of yacc.c  */
#line 6271 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 873:

/* Line 1464 of yacc.c  */
#line 6276 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 874:

/* Line 1464 of yacc.c  */
#line 6283 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  ;}
    break;

  case 875:

/* Line 1464 of yacc.c  */
#line 6287 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  ;}
    break;

  case 876:

/* Line 1464 of yacc.c  */
#line 6297 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  ;}
    break;

  case 878:

/* Line 1464 of yacc.c  */
#line 6305 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 879:

/* Line 1464 of yacc.c  */
#line 6309 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 880:

/* Line 1464 of yacc.c  */
#line 6319 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  ;}
    break;

  case 882:

/* Line 1464 of yacc.c  */
#line 6327 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 883:

/* Line 1464 of yacc.c  */
#line 6332 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 884:

/* Line 1464 of yacc.c  */
#line 6339 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); ;}
    break;

  case 885:

/* Line 1464 of yacc.c  */
#line 6340 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); ;}
    break;

  case 886:

/* Line 1464 of yacc.c  */
#line 6341 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); ;}
    break;

  case 887:

/* Line 1464 of yacc.c  */
#line 6342 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); ;}
    break;

  case 888:

/* Line 1464 of yacc.c  */
#line 6343 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); ;}
    break;

  case 889:

/* Line 1464 of yacc.c  */
#line 6351 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  ;}
    break;

  case 891:

/* Line 1464 of yacc.c  */
#line 6360 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  ;}
    break;

  case 892:

/* Line 1464 of yacc.c  */
#line 6367 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  ;}
    break;

  case 893:

/* Line 1464 of yacc.c  */
#line 6371 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  ;}
    break;

  case 894:

/* Line 1464 of yacc.c  */
#line 6381 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  ;}
    break;

  case 895:

/* Line 1464 of yacc.c  */
#line 6392 "parser.y"
    {
	size_t	save_unreached;

	/* Do not check unreached for CONTINUE */
	save_unreached = check_unreached;
	check_unreached = 0;
	begin_statement ("CONTINUE", 0);
	cb_emit_continue ();
	check_unreached = (unsigned int) save_unreached;
  ;}
    break;

  case 896:

/* Line 1464 of yacc.c  */
#line 6409 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  ;}
    break;

  case 898:

/* Line 1464 of yacc.c  */
#line 6418 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 900:

/* Line 1464 of yacc.c  */
#line 6426 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 901:

/* Line 1464 of yacc.c  */
#line 6431 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 902:

/* Line 1464 of yacc.c  */
#line 6439 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  ;}
    break;

  case 903:

/* Line 1464 of yacc.c  */
#line 6443 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  ;}
    break;

  case 904:

/* Line 1464 of yacc.c  */
#line 6453 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  ;}
    break;

  case 906:

/* Line 1464 of yacc.c  */
#line 6463 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 907:

/* Line 1464 of yacc.c  */
#line 6467 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 908:

/* Line 1464 of yacc.c  */
#line 6471 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 909:

/* Line 1464 of yacc.c  */
#line 6475 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 910:

/* Line 1464 of yacc.c  */
#line 6479 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  ;}
    break;

  case 912:

/* Line 1464 of yacc.c  */
#line 6484 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  ;}
    break;

  case 914:

/* Line 1464 of yacc.c  */
#line 6494 "parser.y"
    {
	begin_implicit_statement ();
  ;}
    break;

  case 916:

/* Line 1464 of yacc.c  */
#line 6502 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  ;}
    break;

  case 917:

/* Line 1464 of yacc.c  */
#line 6510 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 918:

/* Line 1464 of yacc.c  */
#line 6518 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 919:

/* Line 1464 of yacc.c  */
#line 6522 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 920:

/* Line 1464 of yacc.c  */
#line 6526 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 921:

/* Line 1464 of yacc.c  */
#line 6530 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 927:

/* Line 1464 of yacc.c  */
#line 6552 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 928:

/* Line 1464 of yacc.c  */
#line 6558 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 929:

/* Line 1464 of yacc.c  */
#line 6559 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 932:

/* Line 1464 of yacc.c  */
#line 6570 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  ;}
    break;

  case 933:

/* Line 1464 of yacc.c  */
#line 6574 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  ;}
    break;

  case 934:

/* Line 1464 of yacc.c  */
#line 6578 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  ;}
    break;

  case 935:

/* Line 1464 of yacc.c  */
#line 6582 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  ;}
    break;

  case 936:

/* Line 1464 of yacc.c  */
#line 6586 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  ;}
    break;

  case 937:

/* Line 1464 of yacc.c  */
#line 6590 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  ;}
    break;

  case 938:

/* Line 1464 of yacc.c  */
#line 6594 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  ;}
    break;

  case 939:

/* Line 1464 of yacc.c  */
#line 6598 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 940:

/* Line 1464 of yacc.c  */
#line 6602 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 941:

/* Line 1464 of yacc.c  */
#line 6606 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  ;}
    break;

  case 942:

/* Line 1464 of yacc.c  */
#line 6610 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  ;}
    break;

  case 943:

/* Line 1464 of yacc.c  */
#line 6614 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 944:

/* Line 1464 of yacc.c  */
#line 6618 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  ;}
    break;

  case 945:

/* Line 1464 of yacc.c  */
#line 6622 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  ;}
    break;

  case 946:

/* Line 1464 of yacc.c  */
#line 6626 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  ;}
    break;

  case 947:

/* Line 1464 of yacc.c  */
#line 6630 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  ;}
    break;

  case 948:

/* Line 1464 of yacc.c  */
#line 6637 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  ;}
    break;

  case 949:

/* Line 1464 of yacc.c  */
#line 6641 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  ;}
    break;

  case 950:

/* Line 1464 of yacc.c  */
#line 6651 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  ;}
    break;

  case 952:

/* Line 1464 of yacc.c  */
#line 6660 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  ;}
    break;

  case 953:

/* Line 1464 of yacc.c  */
#line 6664 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  ;}
    break;

  case 954:

/* Line 1464 of yacc.c  */
#line 6668 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  ;}
    break;

  case 955:

/* Line 1464 of yacc.c  */
#line 6672 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  ;}
    break;

  case 956:

/* Line 1464 of yacc.c  */
#line 6676 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  ;}
    break;

  case 957:

/* Line 1464 of yacc.c  */
#line 6683 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  ;}
    break;

  case 958:

/* Line 1464 of yacc.c  */
#line 6687 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  ;}
    break;

  case 959:

/* Line 1464 of yacc.c  */
#line 6697 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  ;}
    break;

  case 961:

/* Line 1464 of yacc.c  */
#line 6705 "parser.y"
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
  ;}
    break;

  case 962:

/* Line 1464 of yacc.c  */
#line 6724 "parser.y"
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
  ;}
    break;

  case 964:

/* Line 1464 of yacc.c  */
#line 6748 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  ;}
    break;

  case 965:

/* Line 1464 of yacc.c  */
#line 6755 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 966:

/* Line 1464 of yacc.c  */
#line 6757 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 967:

/* Line 1464 of yacc.c  */
#line 6762 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	eval_check[eval_level][eval_inc++] = (yyvsp[(1) - (1)]);
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  ;}
    break;

  case 968:

/* Line 1464 of yacc.c  */
#line 6773 "parser.y"
    {
	(yyval) = cb_true;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  ;}
    break;

  case 969:

/* Line 1464 of yacc.c  */
#line 6784 "parser.y"
    {
	(yyval) = cb_false;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  ;}
    break;

  case 970:

/* Line 1464 of yacc.c  */
#line 6798 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 971:

/* Line 1464 of yacc.c  */
#line 6802 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 972:

/* Line 1464 of yacc.c  */
#line 6808 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 973:

/* Line 1464 of yacc.c  */
#line 6810 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 974:

/* Line 1464 of yacc.c  */
#line 6816 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  ;}
    break;

  case 975:

/* Line 1464 of yacc.c  */
#line 6825 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  ;}
    break;

  case 976:

/* Line 1464 of yacc.c  */
#line 6833 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  ;}
    break;

  case 977:

/* Line 1464 of yacc.c  */
#line 6839 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  ;}
    break;

  case 978:

/* Line 1464 of yacc.c  */
#line 6846 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 979:

/* Line 1464 of yacc.c  */
#line 6848 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 980:

/* Line 1464 of yacc.c  */
#line 6853 "parser.y"
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
  ;}
    break;

  case 981:

/* Line 1464 of yacc.c  */
#line 6914 "parser.y"
    { (yyval) = cb_any; eval_inc2++; ;}
    break;

  case 982:

/* Line 1464 of yacc.c  */
#line 6915 "parser.y"
    { (yyval) = cb_true; eval_inc2++; ;}
    break;

  case 983:

/* Line 1464 of yacc.c  */
#line 6916 "parser.y"
    { (yyval) = cb_false; eval_inc2++; ;}
    break;

  case 984:

/* Line 1464 of yacc.c  */
#line 6920 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 985:

/* Line 1464 of yacc.c  */
#line 6921 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 986:

/* Line 1464 of yacc.c  */
#line 6926 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  ;}
    break;

  case 987:

/* Line 1464 of yacc.c  */
#line 6930 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  ;}
    break;

  case 988:

/* Line 1464 of yacc.c  */
#line 6940 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  ;}
    break;

  case 989:

/* Line 1464 of yacc.c  */
#line 6945 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 991:

/* Line 1464 of yacc.c  */
#line 6953 "parser.y"
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
  ;}
    break;

  case 992:

/* Line 1464 of yacc.c  */
#line 6974 "parser.y"
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
  ;}
    break;

  case 993:

/* Line 1464 of yacc.c  */
#line 6988 "parser.y"
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
  ;}
    break;

  case 994:

/* Line 1464 of yacc.c  */
#line 7010 "parser.y"
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
  ;}
    break;

  case 995:

/* Line 1464 of yacc.c  */
#line 7032 "parser.y"
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
  ;}
    break;

  case 996:

/* Line 1464 of yacc.c  */
#line 7052 "parser.y"
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
  ;}
    break;

  case 997:

/* Line 1464 of yacc.c  */
#line 7074 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 998:

/* Line 1464 of yacc.c  */
#line 7075 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 999:

/* Line 1464 of yacc.c  */
#line 7083 "parser.y"
    {
	begin_statement ("FREE", 0);
	current_statement->flag_no_based = 1;
  ;}
    break;

  case 1001:

/* Line 1464 of yacc.c  */
#line 7092 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1002:

/* Line 1464 of yacc.c  */
#line 7102 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  ;}
    break;

  case 1005:

/* Line 1464 of yacc.c  */
#line 7118 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1007:

/* Line 1464 of yacc.c  */
#line 7131 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  ;}
    break;

  case 1008:

/* Line 1464 of yacc.c  */
#line 7139 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  ;}
    break;

  case 1009:

/* Line 1464 of yacc.c  */
#line 7144 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1010:

/* Line 1464 of yacc.c  */
#line 7155 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  ;}
    break;

  case 1011:

/* Line 1464 of yacc.c  */
#line 7170 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  ;}
    break;

  case 1013:

/* Line 1464 of yacc.c  */
#line 7179 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1014:

/* Line 1464 of yacc.c  */
#line 7183 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1015:

/* Line 1464 of yacc.c  */
#line 7187 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  ;}
    break;

  case 1016:

/* Line 1464 of yacc.c  */
#line 7194 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  ;}
    break;

  case 1017:

/* Line 1464 of yacc.c  */
#line 7198 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  ;}
    break;

  case 1018:

/* Line 1464 of yacc.c  */
#line 7208 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  ;}
    break;

  case 1020:

/* Line 1464 of yacc.c  */
#line 7217 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 1021:

/* Line 1464 of yacc.c  */
#line 7223 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1022:

/* Line 1464 of yacc.c  */
#line 7224 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1023:

/* Line 1464 of yacc.c  */
#line 7228 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1024:

/* Line 1464 of yacc.c  */
#line 7229 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1025:

/* Line 1464 of yacc.c  */
#line 7230 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 1026:

/* Line 1464 of yacc.c  */
#line 7235 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1027:

/* Line 1464 of yacc.c  */
#line 7239 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1028:

/* Line 1464 of yacc.c  */
#line 7246 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1029:

/* Line 1464 of yacc.c  */
#line 7251 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1030:

/* Line 1464 of yacc.c  */
#line 7258 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1031:

/* Line 1464 of yacc.c  */
#line 7264 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); ;}
    break;

  case 1032:

/* Line 1464 of yacc.c  */
#line 7265 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); ;}
    break;

  case 1033:

/* Line 1464 of yacc.c  */
#line 7266 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); ;}
    break;

  case 1034:

/* Line 1464 of yacc.c  */
#line 7267 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); ;}
    break;

  case 1035:

/* Line 1464 of yacc.c  */
#line 7268 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); ;}
    break;

  case 1036:

/* Line 1464 of yacc.c  */
#line 7269 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); ;}
    break;

  case 1037:

/* Line 1464 of yacc.c  */
#line 7270 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); ;}
    break;

  case 1038:

/* Line 1464 of yacc.c  */
#line 7275 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1039:

/* Line 1464 of yacc.c  */
#line 7279 "parser.y"
    {
	(yyval) = cb_true;
  ;}
    break;

  case 1040:

/* Line 1464 of yacc.c  */
#line 7288 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  ;}
    break;

  case 1042:

/* Line 1464 of yacc.c  */
#line 7297 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  ;}
    break;

  case 1043:

/* Line 1464 of yacc.c  */
#line 7303 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  ;}
    break;

  case 1044:

/* Line 1464 of yacc.c  */
#line 7314 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  ;}
    break;

  case 1047:

/* Line 1464 of yacc.c  */
#line 7327 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1048:

/* Line 1464 of yacc.c  */
#line 7331 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1049:

/* Line 1464 of yacc.c  */
#line 7335 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1054:

/* Line 1464 of yacc.c  */
#line 7351 "parser.y"
    {
	cb_init_tallying ();
  ;}
    break;

  case 1055:

/* Line 1464 of yacc.c  */
#line 7355 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  ;}
    break;

  case 1056:

/* Line 1464 of yacc.c  */
#line 7365 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  ;}
    break;

  case 1057:

/* Line 1464 of yacc.c  */
#line 7375 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  ;}
    break;

  case 1058:

/* Line 1464 of yacc.c  */
#line 7383 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1059:

/* Line 1464 of yacc.c  */
#line 7384 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1060:

/* Line 1464 of yacc.c  */
#line 7388 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); ;}
    break;

  case 1061:

/* Line 1464 of yacc.c  */
#line 7389 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); ;}
    break;

  case 1062:

/* Line 1464 of yacc.c  */
#line 7390 "parser.y"
    { (yyval) = cb_build_tallying_all (); ;}
    break;

  case 1063:

/* Line 1464 of yacc.c  */
#line 7391 "parser.y"
    { (yyval) = cb_build_tallying_leading (); ;}
    break;

  case 1064:

/* Line 1464 of yacc.c  */
#line 7392 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); ;}
    break;

  case 1065:

/* Line 1464 of yacc.c  */
#line 7393 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1066:

/* Line 1464 of yacc.c  */
#line 7397 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1067:

/* Line 1464 of yacc.c  */
#line 7398 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1068:

/* Line 1464 of yacc.c  */
#line 7403 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  ;}
    break;

  case 1069:

/* Line 1464 of yacc.c  */
#line 7408 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1070:

/* Line 1464 of yacc.c  */
#line 7414 "parser.y"
    { /* Nothing */ ;}
    break;

  case 1071:

/* Line 1464 of yacc.c  */
#line 7415 "parser.y"
    { inspect_keyword = 1; ;}
    break;

  case 1072:

/* Line 1464 of yacc.c  */
#line 7416 "parser.y"
    { inspect_keyword = 2; ;}
    break;

  case 1073:

/* Line 1464 of yacc.c  */
#line 7417 "parser.y"
    { inspect_keyword = 3; ;}
    break;

  case 1074:

/* Line 1464 of yacc.c  */
#line 7418 "parser.y"
    { inspect_keyword = 4; ;}
    break;

  case 1075:

/* Line 1464 of yacc.c  */
#line 7423 "parser.y"
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
  ;}
    break;

  case 1076:

/* Line 1464 of yacc.c  */
#line 7450 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  ;}
    break;

  case 1077:

/* Line 1464 of yacc.c  */
#line 7454 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1078:

/* Line 1464 of yacc.c  */
#line 7461 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  ;}
    break;

  case 1079:

/* Line 1464 of yacc.c  */
#line 7465 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  ;}
    break;

  case 1080:

/* Line 1464 of yacc.c  */
#line 7474 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  ;}
    break;

  case 1082:

/* Line 1464 of yacc.c  */
#line 7486 "parser.y"
    {
	begin_statement ("MOVE", 0);
  ;}
    break;

  case 1084:

/* Line 1464 of yacc.c  */
#line 7494 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1085:

/* Line 1464 of yacc.c  */
#line 7498 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1086:

/* Line 1464 of yacc.c  */
#line 7508 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  ;}
    break;

  case 1088:

/* Line 1464 of yacc.c  */
#line 7517 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  ;}
    break;

  case 1089:

/* Line 1464 of yacc.c  */
#line 7521 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  ;}
    break;

  case 1090:

/* Line 1464 of yacc.c  */
#line 7528 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  ;}
    break;

  case 1091:

/* Line 1464 of yacc.c  */
#line 7532 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  ;}
    break;

  case 1092:

/* Line 1464 of yacc.c  */
#line 7542 "parser.y"
    {
	begin_statement ("OPEN", 0);
  ;}
    break;

  case 1094:

/* Line 1464 of yacc.c  */
#line 7550 "parser.y"
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
  ;}
    break;

  case 1095:

/* Line 1464 of yacc.c  */
#line 7571 "parser.y"
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
  ;}
    break;

  case 1096:

/* Line 1464 of yacc.c  */
#line 7594 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); ;}
    break;

  case 1097:

/* Line 1464 of yacc.c  */
#line 7595 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); ;}
    break;

  case 1098:

/* Line 1464 of yacc.c  */
#line 7596 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); ;}
    break;

  case 1099:

/* Line 1464 of yacc.c  */
#line 7597 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); ;}
    break;

  case 1100:

/* Line 1464 of yacc.c  */
#line 7601 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1101:

/* Line 1464 of yacc.c  */
#line 7602 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1102:

/* Line 1464 of yacc.c  */
#line 7606 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1103:

/* Line 1464 of yacc.c  */
#line 7607 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1104:

/* Line 1464 of yacc.c  */
#line 7608 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); ;}
    break;

  case 1105:

/* Line 1464 of yacc.c  */
#line 7610 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  ;}
    break;

  case 1106:

/* Line 1464 of yacc.c  */
#line 7621 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1108:

/* Line 1464 of yacc.c  */
#line 7632 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  ;}
    break;

  case 1109:

/* Line 1464 of yacc.c  */
#line 7637 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  ;}
    break;

  case 1110:

/* Line 1464 of yacc.c  */
#line 7643 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1111:

/* Line 1464 of yacc.c  */
#line 7648 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  ;}
    break;

  case 1112:

/* Line 1464 of yacc.c  */
#line 7656 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  ;}
    break;

  case 1113:

/* Line 1464 of yacc.c  */
#line 7664 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  ;}
    break;

  case 1114:

/* Line 1464 of yacc.c  */
#line 7671 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  ;}
    break;

  case 1115:

/* Line 1464 of yacc.c  */
#line 7675 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-2) - (1)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-2) - (1)]), PERFORM);
	}
	/* Put the dot token back into the stack for reparse */
	cb_unput_dot ();
  ;}
    break;

  case 1116:

/* Line 1464 of yacc.c  */
#line 7688 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 1117:

/* Line 1464 of yacc.c  */
#line 7695 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1118:

/* Line 1464 of yacc.c  */
#line 7706 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  ;}
    break;

  case 1119:

/* Line 1464 of yacc.c  */
#line 7710 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  ;}
    break;

  case 1120:

/* Line 1464 of yacc.c  */
#line 7715 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  ;}
    break;

  case 1121:

/* Line 1464 of yacc.c  */
#line 7719 "parser.y"
    {
	cb_tree varying;

	if (!(yyvsp[(3) - (3)])) {
		(yyval) = cb_build_perform_forever (NULL);
	} else {
		varying = CB_LIST_INIT (cb_build_perform_varying (NULL, NULL, NULL, (yyvsp[(3) - (3)])));
		(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), varying);
	}
  ;}
    break;

  case 1122:

/* Line 1464 of yacc.c  */
#line 7730 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1123:

/* Line 1464 of yacc.c  */
#line 7736 "parser.y"
    { (yyval) = CB_BEFORE; ;}
    break;

  case 1124:

/* Line 1464 of yacc.c  */
#line 7737 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1125:

/* Line 1464 of yacc.c  */
#line 7741 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1126:

/* Line 1464 of yacc.c  */
#line 7742 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1127:

/* Line 1464 of yacc.c  */
#line 7745 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1128:

/* Line 1464 of yacc.c  */
#line 7747 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 1129:

/* Line 1464 of yacc.c  */
#line 7752 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  ;}
    break;

  case 1130:

/* Line 1464 of yacc.c  */
#line 7762 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  ;}
    break;

  case 1132:

/* Line 1464 of yacc.c  */
#line 7771 "parser.y"
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
  ;}
    break;

  case 1133:

/* Line 1464 of yacc.c  */
#line 7797 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1134:

/* Line 1464 of yacc.c  */
#line 7798 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1135:

/* Line 1464 of yacc.c  */
#line 7803 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1136:

/* Line 1464 of yacc.c  */
#line 7807 "parser.y"
    {
	(yyval) = cb_int3;
  ;}
    break;

  case 1137:

/* Line 1464 of yacc.c  */
#line 7811 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1138:

/* Line 1464 of yacc.c  */
#line 7815 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1139:

/* Line 1464 of yacc.c  */
#line 7819 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 1140:

/* Line 1464 of yacc.c  */
#line 7823 "parser.y"
    {
	(yyval) = cb_int3;
  ;}
    break;

  case 1141:

/* Line 1464 of yacc.c  */
#line 7827 "parser.y"
    {
	(yyval) = cb_int4;
  ;}
    break;

  case 1142:

/* Line 1464 of yacc.c  */
#line 7833 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1143:

/* Line 1464 of yacc.c  */
#line 7834 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1146:

/* Line 1464 of yacc.c  */
#line 7844 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  ;}
    break;

  case 1147:

/* Line 1464 of yacc.c  */
#line 7848 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  ;}
    break;

  case 1148:

/* Line 1464 of yacc.c  */
#line 7858 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  ;}
    break;

  case 1149:

/* Line 1464 of yacc.c  */
#line 7868 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  ;}
    break;

  case 1151:

/* Line 1464 of yacc.c  */
#line 7876 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1152:

/* Line 1464 of yacc.c  */
#line 7886 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  ;}
    break;

  case 1153:

/* Line 1464 of yacc.c  */
#line 7896 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  ;}
    break;

  case 1155:

/* Line 1464 of yacc.c  */
#line 7905 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1156:

/* Line 1464 of yacc.c  */
#line 7912 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  ;}
    break;

  case 1157:

/* Line 1464 of yacc.c  */
#line 7916 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  ;}
    break;

  case 1158:

/* Line 1464 of yacc.c  */
#line 7926 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1160:

/* Line 1464 of yacc.c  */
#line 7938 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  ;}
    break;

  case 1161:

/* Line 1464 of yacc.c  */
#line 7946 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1162:

/* Line 1464 of yacc.c  */
#line 7950 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1163:

/* Line 1464 of yacc.c  */
#line 7954 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 1164:

/* Line 1464 of yacc.c  */
#line 7961 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  ;}
    break;

  case 1165:

/* Line 1464 of yacc.c  */
#line 7965 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  ;}
    break;

  case 1166:

/* Line 1464 of yacc.c  */
#line 7975 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  ;}
    break;

  case 1167:

/* Line 1464 of yacc.c  */
#line 7986 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  ;}
    break;

  case 1169:

/* Line 1464 of yacc.c  */
#line 7995 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1170:

/* Line 1464 of yacc.c  */
#line 8000 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  ;}
    break;

  case 1171:

/* Line 1464 of yacc.c  */
#line 8007 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1172:

/* Line 1464 of yacc.c  */
#line 8008 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1173:

/* Line 1464 of yacc.c  */
#line 8013 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1174:

/* Line 1464 of yacc.c  */
#line 8018 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1175:

/* Line 1464 of yacc.c  */
#line 8025 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1176:

/* Line 1464 of yacc.c  */
#line 8029 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 1177:

/* Line 1464 of yacc.c  */
#line 8037 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1178:

/* Line 1464 of yacc.c  */
#line 8044 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  ;}
    break;

  case 1179:

/* Line 1464 of yacc.c  */
#line 8048 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  ;}
    break;

  case 1180:

/* Line 1464 of yacc.c  */
#line 8058 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  ;}
    break;

  case 1181:

/* Line 1464 of yacc.c  */
#line 8065 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 1188:

/* Line 1464 of yacc.c  */
#line 8080 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1189:

/* Line 1464 of yacc.c  */
#line 8081 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1190:

/* Line 1464 of yacc.c  */
#line 8085 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1191:

/* Line 1464 of yacc.c  */
#line 8086 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1192:

/* Line 1464 of yacc.c  */
#line 8093 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1193:

/* Line 1464 of yacc.c  */
#line 8102 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  ;}
    break;

  case 1196:

/* Line 1464 of yacc.c  */
#line 8114 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  ;}
    break;

  case 1197:

/* Line 1464 of yacc.c  */
#line 8118 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  ;}
    break;

  case 1198:

/* Line 1464 of yacc.c  */
#line 8122 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 1199:

/* Line 1464 of yacc.c  */
#line 8126 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 1200:

/* Line 1464 of yacc.c  */
#line 8130 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  ;}
    break;

  case 1201:

/* Line 1464 of yacc.c  */
#line 8134 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 1202:

/* Line 1464 of yacc.c  */
#line 8138 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 1203:

/* Line 1464 of yacc.c  */
#line 8142 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  ;}
    break;

  case 1204:

/* Line 1464 of yacc.c  */
#line 8151 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  ;}
    break;

  case 1205:

/* Line 1464 of yacc.c  */
#line 8155 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1206:

/* Line 1464 of yacc.c  */
#line 8164 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1209:

/* Line 1464 of yacc.c  */
#line 8178 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1212:

/* Line 1464 of yacc.c  */
#line 8192 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1213:

/* Line 1464 of yacc.c  */
#line 8196 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1214:

/* Line 1464 of yacc.c  */
#line 8206 "parser.y"
    {
	begin_statement ("SORT", 0);
  ;}
    break;

  case 1216:

/* Line 1464 of yacc.c  */
#line 8214 "parser.y"
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
  ;}
    break;

  case 1217:

/* Line 1464 of yacc.c  */
#line 8235 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  ;}
    break;

  case 1218:

/* Line 1464 of yacc.c  */
#line 8244 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1219:

/* Line 1464 of yacc.c  */
#line 8249 "parser.y"
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
  ;}
    break;

  case 1220:

/* Line 1464 of yacc.c  */
#line 8267 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1221:

/* Line 1464 of yacc.c  */
#line 8268 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1223:

/* Line 1464 of yacc.c  */
#line 8273 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  ;}
    break;

  case 1224:

/* Line 1464 of yacc.c  */
#line 8280 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1225:

/* Line 1464 of yacc.c  */
#line 8281 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); ;}
    break;

  case 1226:

/* Line 1464 of yacc.c  */
#line 8286 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  ;}
    break;

  case 1227:

/* Line 1464 of yacc.c  */
#line 8292 "parser.y"
    {
	if ((yyvsp[(0) - (2)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(0) - (2)])))) {
			cb_error (_("USING invalid with table SORT"));
		} else {
			cb_emit_sort_using ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  ;}
    break;

  case 1228:

/* Line 1464 of yacc.c  */
#line 8302 "parser.y"
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
  ;}
    break;

  case 1229:

/* Line 1464 of yacc.c  */
#line 8317 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  ;}
    break;

  case 1230:

/* Line 1464 of yacc.c  */
#line 8323 "parser.y"
    {
	if ((yyvsp[(-1) - (2)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(-1) - (2)])))) {
			cb_error (_("GIVING invalid with table SORT"));
		} else {
			cb_emit_sort_giving ((yyvsp[(-1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  ;}
    break;

  case 1231:

/* Line 1464 of yacc.c  */
#line 8333 "parser.y"
    {
	if ((yyvsp[(-1) - (4)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(-1) - (4)])))) {
			cb_error (_("OUTPUT PROCEDURE invalid with table SORT"));
		} else {
			cb_emit_sort_output ((yyvsp[(4) - (4)]));
		}
	}
  ;}
    break;

  case 1232:

/* Line 1464 of yacc.c  */
#line 8349 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  ;}
    break;

  case 1234:

/* Line 1464 of yacc.c  */
#line 8359 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  ;}
    break;

  case 1235:

/* Line 1464 of yacc.c  */
#line 8371 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1236:

/* Line 1464 of yacc.c  */
#line 8375 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1237:

/* Line 1464 of yacc.c  */
#line 8382 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1238:

/* Line 1464 of yacc.c  */
#line 8386 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 1239:

/* Line 1464 of yacc.c  */
#line 8391 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  ;}
    break;

  case 1240:

/* Line 1464 of yacc.c  */
#line 8396 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  ;}
    break;

  case 1241:

/* Line 1464 of yacc.c  */
#line 8403 "parser.y"
    { (yyval) = cb_int (COB_EQ); ;}
    break;

  case 1242:

/* Line 1464 of yacc.c  */
#line 8404 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); ;}
    break;

  case 1243:

/* Line 1464 of yacc.c  */
#line 8405 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); ;}
    break;

  case 1244:

/* Line 1464 of yacc.c  */
#line 8406 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); ;}
    break;

  case 1245:

/* Line 1464 of yacc.c  */
#line 8407 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); ;}
    break;

  case 1246:

/* Line 1464 of yacc.c  */
#line 8408 "parser.y"
    { (yyval) = cb_int (COB_NE); ;}
    break;

  case 1247:

/* Line 1464 of yacc.c  */
#line 8413 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  ;}
    break;

  case 1250:

/* Line 1464 of yacc.c  */
#line 8426 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  ;}
    break;

  case 1251:

/* Line 1464 of yacc.c  */
#line 8430 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  ;}
    break;

  case 1252:

/* Line 1464 of yacc.c  */
#line 8440 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  ;}
    break;

  case 1253:

/* Line 1464 of yacc.c  */
#line 8444 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  ;}
    break;

  case 1254:

/* Line 1464 of yacc.c  */
#line 8450 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  ;}
    break;

  case 1255:

/* Line 1464 of yacc.c  */
#line 8462 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  ;}
    break;

  case 1256:

/* Line 1464 of yacc.c  */
#line 8466 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1257:

/* Line 1464 of yacc.c  */
#line 8470 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  ;}
    break;

  case 1258:

/* Line 1464 of yacc.c  */
#line 8478 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 1259:

/* Line 1464 of yacc.c  */
#line 8489 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1260:

/* Line 1464 of yacc.c  */
#line 8493 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1261:

/* Line 1464 of yacc.c  */
#line 8499 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1262:

/* Line 1464 of yacc.c  */
#line 8500 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1263:

/* Line 1464 of yacc.c  */
#line 8501 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1264:

/* Line 1464 of yacc.c  */
#line 8502 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1265:

/* Line 1464 of yacc.c  */
#line 8509 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  ;}
    break;

  case 1267:

/* Line 1464 of yacc.c  */
#line 8518 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 1268:

/* Line 1464 of yacc.c  */
#line 8524 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1269:

/* Line 1464 of yacc.c  */
#line 8525 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1270:

/* Line 1464 of yacc.c  */
#line 8529 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1271:

/* Line 1464 of yacc.c  */
#line 8530 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); ;}
    break;

  case 1272:

/* Line 1464 of yacc.c  */
#line 8531 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); ;}
    break;

  case 1273:

/* Line 1464 of yacc.c  */
#line 8535 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1274:

/* Line 1464 of yacc.c  */
#line 8536 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); ;}
    break;

  case 1275:

/* Line 1464 of yacc.c  */
#line 8541 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  ;}
    break;

  case 1276:

/* Line 1464 of yacc.c  */
#line 8545 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  ;}
    break;

  case 1277:

/* Line 1464 of yacc.c  */
#line 8555 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  ;}
    break;

  case 1279:

/* Line 1464 of yacc.c  */
#line 8564 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  ;}
    break;

  case 1280:

/* Line 1464 of yacc.c  */
#line 8568 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  ;}
    break;

  case 1281:

/* Line 1464 of yacc.c  */
#line 8572 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 1282:

/* Line 1464 of yacc.c  */
#line 8579 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  ;}
    break;

  case 1283:

/* Line 1464 of yacc.c  */
#line 8583 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  ;}
    break;

  case 1284:

/* Line 1464 of yacc.c  */
#line 8593 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  ;}
    break;

  case 1287:

/* Line 1464 of yacc.c  */
#line 8611 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  ;}
    break;

  case 1289:

/* Line 1464 of yacc.c  */
#line 8620 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  ;}
    break;

  case 1290:

/* Line 1464 of yacc.c  */
#line 8626 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  ;}
    break;

  case 1291:

/* Line 1464 of yacc.c  */
#line 8637 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  ;}
    break;

  case 1293:

/* Line 1464 of yacc.c  */
#line 8645 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  ;}
    break;

  case 1294:

/* Line 1464 of yacc.c  */
#line 8658 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  ;}
    break;

  case 1296:

/* Line 1464 of yacc.c  */
#line 8666 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (2)]))) {
		if (CB_FILE (cb_ref ((yyvsp[(1) - (2)])))->organization == COB_ORG_SORT) {
			cb_error_x (CB_TREE (current_statement),
				    _("UNLOCK invalid for SORT files"));
		} else {
			cb_emit_unlock ((yyvsp[(1) - (2)]));
		}
	}
  ;}
    break;

  case 1300:

/* Line 1464 of yacc.c  */
#line 8689 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  ;}
    break;

  case 1302:

/* Line 1464 of yacc.c  */
#line 8699 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 1303:

/* Line 1464 of yacc.c  */
#line 8705 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1304:

/* Line 1464 of yacc.c  */
#line 8707 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1305:

/* Line 1464 of yacc.c  */
#line 8711 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1306:

/* Line 1464 of yacc.c  */
#line 8713 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 1307:

/* Line 1464 of yacc.c  */
#line 8718 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1308:

/* Line 1464 of yacc.c  */
#line 8724 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); ;}
    break;

  case 1309:

/* Line 1464 of yacc.c  */
#line 8726 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1310:

/* Line 1464 of yacc.c  */
#line 8731 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1311:

/* Line 1464 of yacc.c  */
#line 8737 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1312:

/* Line 1464 of yacc.c  */
#line 8738 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1313:

/* Line 1464 of yacc.c  */
#line 8742 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1314:

/* Line 1464 of yacc.c  */
#line 8743 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1315:

/* Line 1464 of yacc.c  */
#line 8747 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1316:

/* Line 1464 of yacc.c  */
#line 8748 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1317:

/* Line 1464 of yacc.c  */
#line 8753 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  ;}
    break;

  case 1318:

/* Line 1464 of yacc.c  */
#line 8757 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  ;}
    break;

  case 1319:

/* Line 1464 of yacc.c  */
#line 8767 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  ;}
    break;

  case 1326:

/* Line 1464 of yacc.c  */
#line 8785 "parser.y"
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
  ;}
    break;

  case 1327:

/* Line 1464 of yacc.c  */
#line 8810 "parser.y"
    {
	use_global_ind = 0;
  ;}
    break;

  case 1328:

/* Line 1464 of yacc.c  */
#line 8814 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  ;}
    break;

  case 1329:

/* Line 1464 of yacc.c  */
#line 8826 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  ;}
    break;

  case 1330:

/* Line 1464 of yacc.c  */
#line 8836 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  ;}
    break;

  case 1331:

/* Line 1464 of yacc.c  */
#line 8841 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  ;}
    break;

  case 1332:

/* Line 1464 of yacc.c  */
#line 8846 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  ;}
    break;

  case 1333:

/* Line 1464 of yacc.c  */
#line 8851 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  ;}
    break;

  case 1334:

/* Line 1464 of yacc.c  */
#line 8859 "parser.y"
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
  ;}
    break;

  case 1337:

/* Line 1464 of yacc.c  */
#line 8902 "parser.y"
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
  ;}
    break;

  case 1338:

/* Line 1464 of yacc.c  */
#line 8942 "parser.y"
    {
	if (current_program->flag_debugging) {
		if (current_program->all_procedure) {
			cb_error (_("Duplicate USE DEBUGGING ON ALL PROCEDURES"));
		} else {
			current_program->all_procedure = current_section;
		}
	}
  ;}
    break;

  case 1339:

/* Line 1464 of yacc.c  */
#line 8952 "parser.y"
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
  ;}
    break;

  case 1344:

/* Line 1464 of yacc.c  */
#line 8982 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("USE AT is invalid in nested program"));
	}
  ;}
    break;

  case 1345:

/* Line 1464 of yacc.c  */
#line 8991 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM START"));
	/* emit_entry ("_START", 0, NULL); */
	PENDING ("USE AT PROGRAM START");
  ;}
    break;

  case 1346:

/* Line 1464 of yacc.c  */
#line 8997 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM END"));
	/* emit_entry ("_END", 0, NULL); */
	PENDING ("USE AT PROGRAM END");
  ;}
    break;

  case 1347:

/* Line 1464 of yacc.c  */
#line 9007 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  ;}
    break;

  case 1348:

/* Line 1464 of yacc.c  */
#line 9016 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  ;}
    break;

  case 1351:

/* Line 1464 of yacc.c  */
#line 9032 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1353:

/* Line 1464 of yacc.c  */
#line 9044 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  ;}
    break;

  case 1354:

/* Line 1464 of yacc.c  */
#line 9053 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1355:

/* Line 1464 of yacc.c  */
#line 9054 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1356:

/* Line 1464 of yacc.c  */
#line 9059 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 1357:

/* Line 1464 of yacc.c  */
#line 9063 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1358:

/* Line 1464 of yacc.c  */
#line 9067 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1359:

/* Line 1464 of yacc.c  */
#line 9071 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1360:

/* Line 1464 of yacc.c  */
#line 9077 "parser.y"
    { (yyval) = CB_BEFORE; ;}
    break;

  case 1361:

/* Line 1464 of yacc.c  */
#line 9078 "parser.y"
    { (yyval) = CB_AFTER; ;}
    break;

  case 1364:

/* Line 1464 of yacc.c  */
#line 9088 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  ;}
    break;

  case 1365:

/* Line 1464 of yacc.c  */
#line 9092 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  ;}
    break;

  case 1368:

/* Line 1464 of yacc.c  */
#line 9109 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1370:

/* Line 1464 of yacc.c  */
#line 9119 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1373:

/* Line 1464 of yacc.c  */
#line 9132 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1375:

/* Line 1464 of yacc.c  */
#line 9142 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1378:

/* Line 1464 of yacc.c  */
#line 9157 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1380:

/* Line 1464 of yacc.c  */
#line 9167 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1383:

/* Line 1464 of yacc.c  */
#line 9184 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1385:

/* Line 1464 of yacc.c  */
#line 9195 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1391:

/* Line 1464 of yacc.c  */
#line 9218 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1392:

/* Line 1464 of yacc.c  */
#line 9227 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1396:

/* Line 1464 of yacc.c  */
#line 9244 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1397:

/* Line 1464 of yacc.c  */
#line 9253 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1400:

/* Line 1464 of yacc.c  */
#line 9270 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1402:

/* Line 1464 of yacc.c  */
#line 9280 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1403:

/* Line 1464 of yacc.c  */
#line 9290 "parser.y"
    {
	(yyval) = cb_one;
  ;}
    break;

  case 1404:

/* Line 1464 of yacc.c  */
#line 9294 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 1405:

/* Line 1464 of yacc.c  */
#line 9304 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1406:

/* Line 1464 of yacc.c  */
#line 9311 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1407:

/* Line 1464 of yacc.c  */
#line 9317 "parser.y"
    {
	current_expr = NULL;
  ;}
    break;

  case 1408:

/* Line 1464 of yacc.c  */
#line 9321 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  ;}
    break;

  case 1412:

/* Line 1464 of yacc.c  */
#line 9334 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1413:

/* Line 1464 of yacc.c  */
#line 9342 "parser.y"
    { push_expr ('(', NULL); ;}
    break;

  case 1414:

/* Line 1464 of yacc.c  */
#line 9343 "parser.y"
    { push_expr (')', NULL); ;}
    break;

  case 1415:

/* Line 1464 of yacc.c  */
#line 9345 "parser.y"
    { push_expr ('+', NULL); ;}
    break;

  case 1416:

/* Line 1464 of yacc.c  */
#line 9346 "parser.y"
    { push_expr ('-', NULL); ;}
    break;

  case 1417:

/* Line 1464 of yacc.c  */
#line 9347 "parser.y"
    { push_expr ('*', NULL); ;}
    break;

  case 1418:

/* Line 1464 of yacc.c  */
#line 9348 "parser.y"
    { push_expr ('/', NULL); ;}
    break;

  case 1419:

/* Line 1464 of yacc.c  */
#line 9349 "parser.y"
    { push_expr ('^', NULL); ;}
    break;

  case 1420:

/* Line 1464 of yacc.c  */
#line 9351 "parser.y"
    { push_expr ('=', NULL); ;}
    break;

  case 1421:

/* Line 1464 of yacc.c  */
#line 9352 "parser.y"
    { push_expr ('>', NULL); ;}
    break;

  case 1422:

/* Line 1464 of yacc.c  */
#line 9353 "parser.y"
    { push_expr ('<', NULL); ;}
    break;

  case 1423:

/* Line 1464 of yacc.c  */
#line 9354 "parser.y"
    { push_expr (']', NULL); ;}
    break;

  case 1424:

/* Line 1464 of yacc.c  */
#line 9355 "parser.y"
    { push_expr ('[', NULL); ;}
    break;

  case 1425:

/* Line 1464 of yacc.c  */
#line 9356 "parser.y"
    { push_expr ('~', NULL); ;}
    break;

  case 1426:

/* Line 1464 of yacc.c  */
#line 9358 "parser.y"
    { push_expr ('!', NULL); ;}
    break;

  case 1427:

/* Line 1464 of yacc.c  */
#line 9359 "parser.y"
    { push_expr ('&', NULL); ;}
    break;

  case 1428:

/* Line 1464 of yacc.c  */
#line 9360 "parser.y"
    { push_expr ('|', NULL); ;}
    break;

  case 1429:

/* Line 1464 of yacc.c  */
#line 9362 "parser.y"
    { push_expr ('O', NULL); ;}
    break;

  case 1430:

/* Line 1464 of yacc.c  */
#line 9363 "parser.y"
    { push_expr ('9', NULL); ;}
    break;

  case 1431:

/* Line 1464 of yacc.c  */
#line 9364 "parser.y"
    { push_expr ('A', NULL); ;}
    break;

  case 1432:

/* Line 1464 of yacc.c  */
#line 9365 "parser.y"
    { push_expr ('L', NULL); ;}
    break;

  case 1433:

/* Line 1464 of yacc.c  */
#line 9366 "parser.y"
    { push_expr ('U', NULL); ;}
    break;

  case 1434:

/* Line 1464 of yacc.c  */
#line 9369 "parser.y"
    { push_expr ('P', NULL); ;}
    break;

  case 1435:

/* Line 1464 of yacc.c  */
#line 9370 "parser.y"
    { push_expr ('N', NULL); ;}
    break;

  case 1444:

/* Line 1464 of yacc.c  */
#line 9400 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1445:

/* Line 1464 of yacc.c  */
#line 9404 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1449:

/* Line 1464 of yacc.c  */
#line 9415 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); ;}
    break;

  case 1450:

/* Line 1464 of yacc.c  */
#line 9416 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); ;}
    break;

  case 1451:

/* Line 1464 of yacc.c  */
#line 9417 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1452:

/* Line 1464 of yacc.c  */
#line 9421 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); ;}
    break;

  case 1453:

/* Line 1464 of yacc.c  */
#line 9422 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); ;}
    break;

  case 1454:

/* Line 1464 of yacc.c  */
#line 9423 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1455:

/* Line 1464 of yacc.c  */
#line 9428 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1456:

/* Line 1464 of yacc.c  */
#line 9431 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1457:

/* Line 1464 of yacc.c  */
#line 9435 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1458:

/* Line 1464 of yacc.c  */
#line 9436 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); ;}
    break;

  case 1459:

/* Line 1464 of yacc.c  */
#line 9437 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1460:

/* Line 1464 of yacc.c  */
#line 9440 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 1461:

/* Line 1464 of yacc.c  */
#line 9441 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1462:

/* Line 1464 of yacc.c  */
#line 9452 "parser.y"
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
  ;}
    break;

  case 1463:

/* Line 1464 of yacc.c  */
#line 9464 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1464:

/* Line 1464 of yacc.c  */
#line 9473 "parser.y"
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
  ;}
    break;

  case 1465:

/* Line 1464 of yacc.c  */
#line 9485 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1466:

/* Line 1464 of yacc.c  */
#line 9494 "parser.y"
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
  ;}
    break;

  case 1467:

/* Line 1464 of yacc.c  */
#line 9506 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1468:

/* Line 1464 of yacc.c  */
#line 9520 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1469:

/* Line 1464 of yacc.c  */
#line 9522 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1470:

/* Line 1464 of yacc.c  */
#line 9527 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 1471:

/* Line 1464 of yacc.c  */
#line 9535 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1472:

/* Line 1464 of yacc.c  */
#line 9542 "parser.y"
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
  ;}
    break;

  case 1473:

/* Line 1464 of yacc.c  */
#line 9562 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1474:

/* Line 1464 of yacc.c  */
#line 9566 "parser.y"
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
  ;}
    break;

  case 1475:

/* Line 1464 of yacc.c  */
#line 9587 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1476:

/* Line 1464 of yacc.c  */
#line 9628 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1477:

/* Line 1464 of yacc.c  */
#line 9641 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1478:

/* Line 1464 of yacc.c  */
#line 9643 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1479:

/* Line 1464 of yacc.c  */
#line 9647 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1480:

/* Line 1464 of yacc.c  */
#line 9653 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1481:

/* Line 1464 of yacc.c  */
#line 9655 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1482:

/* Line 1464 of yacc.c  */
#line 9660 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  ;}
    break;

  case 1485:

/* Line 1464 of yacc.c  */
#line 9674 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1486:

/* Line 1464 of yacc.c  */
#line 9681 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  ;}
    break;

  case 1487:

/* Line 1464 of yacc.c  */
#line 9691 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1488:

/* Line 1464 of yacc.c  */
#line 9692 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1489:

/* Line 1464 of yacc.c  */
#line 9697 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1490:

/* Line 1464 of yacc.c  */
#line 9705 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1491:

/* Line 1464 of yacc.c  */
#line 9713 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1492:

/* Line 1464 of yacc.c  */
#line 9717 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1493:

/* Line 1464 of yacc.c  */
#line 9724 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1496:

/* Line 1464 of yacc.c  */
#line 9740 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1497:

/* Line 1464 of yacc.c  */
#line 9754 "parser.y"
    {
	if (CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_duped || CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = NULL;
	} else {
		CB_WORD_COUNT ((yyvsp[(1) - (1)]))++;
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1498:

/* Line 1464 of yacc.c  */
#line 9771 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1499:

/* Line 1464 of yacc.c  */
#line 9775 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1502:

/* Line 1464 of yacc.c  */
#line 9784 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 1503:

/* Line 1464 of yacc.c  */
#line 9791 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1504:

/* Line 1464 of yacc.c  */
#line 9795 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1509:

/* Line 1464 of yacc.c  */
#line 9806 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1510:

/* Line 1464 of yacc.c  */
#line 9810 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1511:

/* Line 1464 of yacc.c  */
#line 9814 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1512:

/* Line 1464 of yacc.c  */
#line 9818 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 1513:

/* Line 1464 of yacc.c  */
#line 9822 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 1514:

/* Line 1464 of yacc.c  */
#line 9826 "parser.y"
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
  ;}
    break;

  case 1515:

/* Line 1464 of yacc.c  */
#line 9847 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1516:

/* Line 1464 of yacc.c  */
#line 9851 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1524:

/* Line 1464 of yacc.c  */
#line 9868 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1525:

/* Line 1464 of yacc.c  */
#line 9872 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1526:

/* Line 1464 of yacc.c  */
#line 9876 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1542:

/* Line 1464 of yacc.c  */
#line 9923 "parser.y"
    {
	(yyval) = cb_zero;
  ;}
    break;

  case 1550:

/* Line 1464 of yacc.c  */
#line 9947 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1551:

/* Line 1464 of yacc.c  */
#line 9951 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); ;}
    break;

  case 1552:

/* Line 1464 of yacc.c  */
#line 9955 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1553:

/* Line 1464 of yacc.c  */
#line 9956 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 1554:

/* Line 1464 of yacc.c  */
#line 9960 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1555:

/* Line 1464 of yacc.c  */
#line 9965 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  ;}
    break;

  case 1556:

/* Line 1464 of yacc.c  */
#line 9972 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1557:

/* Line 1464 of yacc.c  */
#line 9979 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1558:

/* Line 1464 of yacc.c  */
#line 9986 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1559:

/* Line 1464 of yacc.c  */
#line 9996 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  ;}
    break;

  case 1560:

/* Line 1464 of yacc.c  */
#line 10003 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (3)]))) {
		CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  ;}
    break;

  case 1561:

/* Line 1464 of yacc.c  */
#line 10013 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (2)]))) {
		CB_REFERENCE ((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1562:

/* Line 1464 of yacc.c  */
#line 10023 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (2)]))) {
		CB_REFERENCE ((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1563:

/* Line 1464 of yacc.c  */
#line 10033 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)]))) {
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1564:

/* Line 1464 of yacc.c  */
#line 10046 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1565:

/* Line 1464 of yacc.c  */
#line 10050 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1566:

/* Line 1464 of yacc.c  */
#line 10058 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  ;}
    break;

  case 1567:

/* Line 1464 of yacc.c  */
#line 10066 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 1568:

/* Line 1464 of yacc.c  */
#line 10070 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  ;}
    break;

  case 1569:

/* Line 1464 of yacc.c  */
#line 10080 "parser.y"
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
  ;}
    break;

  case 1570:

/* Line 1464 of yacc.c  */
#line 10095 "parser.y"
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
  ;}
    break;

  case 1571:

/* Line 1464 of yacc.c  */
#line 10118 "parser.y"
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
  ;}
    break;

  case 1572:

/* Line 1464 of yacc.c  */
#line 10141 "parser.y"
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
  ;}
    break;

  case 1573:

/* Line 1464 of yacc.c  */
#line 10156 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1574:

/* Line 1464 of yacc.c  */
#line 10157 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1575:

/* Line 1464 of yacc.c  */
#line 10158 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1576:

/* Line 1464 of yacc.c  */
#line 10159 "parser.y"
    { (yyval) = cb_high; ;}
    break;

  case 1577:

/* Line 1464 of yacc.c  */
#line 10160 "parser.y"
    { (yyval) = cb_low; ;}
    break;

  case 1578:

/* Line 1464 of yacc.c  */
#line 10161 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1579:

/* Line 1464 of yacc.c  */
#line 10166 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1580:

/* Line 1464 of yacc.c  */
#line 10170 "parser.y"
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
  ;}
    break;

  case 1581:

/* Line 1464 of yacc.c  */
#line 10187 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1582:

/* Line 1464 of yacc.c  */
#line 10191 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1583:

/* Line 1464 of yacc.c  */
#line 10197 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1584:

/* Line 1464 of yacc.c  */
#line 10198 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1585:

/* Line 1464 of yacc.c  */
#line 10199 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1586:

/* Line 1464 of yacc.c  */
#line 10200 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1587:

/* Line 1464 of yacc.c  */
#line 10201 "parser.y"
    { (yyval) = cb_high; ;}
    break;

  case 1588:

/* Line 1464 of yacc.c  */
#line 10202 "parser.y"
    { (yyval) = cb_low; ;}
    break;

  case 1589:

/* Line 1464 of yacc.c  */
#line 10203 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1590:

/* Line 1464 of yacc.c  */
#line 10210 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  ;}
    break;

  case 1591:

/* Line 1464 of yacc.c  */
#line 10214 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1592:

/* Line 1464 of yacc.c  */
#line 10218 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1593:

/* Line 1464 of yacc.c  */
#line 10222 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1594:

/* Line 1464 of yacc.c  */
#line 10226 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  ;}
    break;

  case 1595:

/* Line 1464 of yacc.c  */
#line 10230 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1596:

/* Line 1464 of yacc.c  */
#line 10234 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1597:

/* Line 1464 of yacc.c  */
#line 10238 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1598:

/* Line 1464 of yacc.c  */
#line 10242 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  ;}
    break;

  case 1599:

/* Line 1464 of yacc.c  */
#line 10246 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  ;}
    break;

  case 1608:

/* Line 1464 of yacc.c  */
#line 10270 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1609:

/* Line 1464 of yacc.c  */
#line 10274 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  ;}
    break;

  case 1610:

/* Line 1464 of yacc.c  */
#line 10278 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 1611:

/* Line 1464 of yacc.c  */
#line 10285 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1612:

/* Line 1464 of yacc.c  */
#line 10289 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 1613:

/* Line 1464 of yacc.c  */
#line 10293 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1614:

/* Line 1464 of yacc.c  */
#line 10300 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  ;}
    break;

  case 1615:

/* Line 1464 of yacc.c  */
#line 10307 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  ;}
    break;

  case 1616:

/* Line 1464 of yacc.c  */
#line 10314 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  ;}
    break;

  case 1617:

/* Line 1464 of yacc.c  */
#line 10324 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  ;}
    break;

  case 1618:

/* Line 1464 of yacc.c  */
#line 10331 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1619:

/* Line 1464 of yacc.c  */
#line 10341 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  ;}
    break;

  case 1620:

/* Line 1464 of yacc.c  */
#line 10348 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  ;}
    break;

  case 1621:

/* Line 1464 of yacc.c  */
#line 10359 "parser.y"
    {
	non_const_word = 1;
  ;}
    break;

  case 1622:

/* Line 1464 of yacc.c  */
#line 10367 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1623:

/* Line 1464 of yacc.c  */
#line 10368 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1624:

/* Line 1464 of yacc.c  */
#line 10372 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1625:

/* Line 1464 of yacc.c  */
#line 10373 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1626:

/* Line 1464 of yacc.c  */
#line 10377 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1627:

/* Line 1464 of yacc.c  */
#line 10378 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1628:

/* Line 1464 of yacc.c  */
#line 10383 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1629:

/* Line 1464 of yacc.c  */
#line 10387 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1630:

/* Line 1464 of yacc.c  */
#line 10394 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1631:

/* Line 1464 of yacc.c  */
#line 10398 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1632:

/* Line 1464 of yacc.c  */
#line 10405 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1633:

/* Line 1464 of yacc.c  */
#line 10406 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1634:

/* Line 1464 of yacc.c  */
#line 10407 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 1635:

/* Line 1464 of yacc.c  */
#line 10411 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1636:

/* Line 1464 of yacc.c  */
#line 10412 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1637:

/* Line 1464 of yacc.c  */
#line 10416 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); ;}
    break;

  case 1638:

/* Line 1464 of yacc.c  */
#line 10417 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1639:

/* Line 1464 of yacc.c  */
#line 10418 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1640:

/* Line 1464 of yacc.c  */
#line 10423 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 1641:

/* Line 1464 of yacc.c  */
#line 10427 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  ;}
    break;

  case 1642:

/* Line 1464 of yacc.c  */
#line 10439 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  ;}
    break;

  case 1643:

/* Line 1464 of yacc.c  */
#line 10444 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  ;}
    break;

  case 1644:

/* Line 1464 of yacc.c  */
#line 10452 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  ;}
    break;

  case 1645:

/* Line 1464 of yacc.c  */
#line 10456 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  ;}
    break;

  case 1646:

/* Line 1464 of yacc.c  */
#line 10460 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  ;}
    break;

  case 1647:

/* Line 1464 of yacc.c  */
#line 10464 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  ;}
    break;

  case 1648:

/* Line 1464 of yacc.c  */
#line 10468 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  ;}
    break;

  case 1649:

/* Line 1464 of yacc.c  */
#line 10472 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  ;}
    break;

  case 1650:

/* Line 1464 of yacc.c  */
#line 10476 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  ;}
    break;

  case 1651:

/* Line 1464 of yacc.c  */
#line 10480 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  ;}
    break;

  case 1652:

/* Line 1464 of yacc.c  */
#line 10486 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1653:

/* Line 1464 of yacc.c  */
#line 10487 "parser.y"
    { (yyval) = cb_int1; ;}
    break;



/* Line 1464 of yacc.c  */
#line 18543 "parser.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1684 of yacc.c  */
#line 10658 "parser.y"


