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
     CAPACITY = 308,
     CF = 309,
     CH = 310,
     CHAINING = 311,
     CHARACTER = 312,
     CHARACTERS = 313,
     CLASS = 314,
     CLASSIFICATION = 315,
     CLOSE = 316,
     CODE = 317,
     CODE_SET = 318,
     COLLATING = 319,
     COL = 320,
     COLS = 321,
     COLUMN = 322,
     COLUMNS = 323,
     COMMA = 324,
     COMMAND_LINE = 325,
     COMMA_DELIM = 326,
     COMMIT = 327,
     COMMON = 328,
     COMP = 329,
     COMPUTE = 330,
     COMP_1 = 331,
     COMP_2 = 332,
     COMP_3 = 333,
     COMP_4 = 334,
     COMP_5 = 335,
     COMP_6 = 336,
     COMP_X = 337,
     CONCATENATE_FUNC = 338,
     CONDITION = 339,
     CONFIGURATION = 340,
     CONSTANT = 341,
     CONTAINS = 342,
     CONTENT = 343,
     CONTINUE = 344,
     CONTROL = 345,
     CONTROLS = 346,
     CONVERSION = 347,
     CONVERTING = 348,
     COPY = 349,
     CORRESPONDING = 350,
     COUNT = 351,
     CRT = 352,
     CRT_UNDER = 353,
     CURRENCY = 354,
     CURRENT_DATE_FUNC = 355,
     CURSOR = 356,
     CYCLE = 357,
     DATA = 358,
     DATE = 359,
     DAY = 360,
     DAY_OF_WEEK = 361,
     DE = 362,
     DEBUGGING = 363,
     DECIMAL_POINT = 364,
     DECLARATIVES = 365,
     DEFAULT = 366,
     DELETE = 367,
     DELIMITED = 368,
     DELIMITER = 369,
     DEPENDING = 370,
     DESCENDING = 371,
     DETAIL = 372,
     DISC = 373,
     DISK = 374,
     DISPLAY = 375,
     DISPLAY_OF_FUNC = 376,
     DIVIDE = 377,
     DIVISION = 378,
     DOWN = 379,
     DUPLICATES = 380,
     DYNAMIC = 381,
     EBCDIC = 382,
     EC = 383,
     ELSE = 384,
     END = 385,
     END_ACCEPT = 386,
     END_ADD = 387,
     END_CALL = 388,
     END_COMPUTE = 389,
     END_DELETE = 390,
     END_DISPLAY = 391,
     END_DIVIDE = 392,
     END_EVALUATE = 393,
     END_FUNCTION = 394,
     END_IF = 395,
     END_MULTIPLY = 396,
     END_PERFORM = 397,
     END_PROGRAM = 398,
     END_READ = 399,
     END_RETURN = 400,
     END_REWRITE = 401,
     END_SEARCH = 402,
     END_START = 403,
     END_STRING = 404,
     END_SUBTRACT = 405,
     END_UNSTRING = 406,
     END_WRITE = 407,
     ENTRY = 408,
     ENVIRONMENT = 409,
     ENVIRONMENT_NAME = 410,
     ENVIRONMENT_VALUE = 411,
     EOL = 412,
     EOP = 413,
     EOS = 414,
     EQUAL = 415,
     ERASE = 416,
     ERROR = 417,
     ESCAPE = 418,
     EVALUATE = 419,
     EVENT_STATUS = 420,
     EXCEPTION = 421,
     EXCEPTION_CONDITION = 422,
     EXCLUSIVE = 423,
     EXIT = 424,
     EXPONENTIATION = 425,
     EXTEND = 426,
     EXTERNAL = 427,
     FD = 428,
     FILE_CONTROL = 429,
     FILE_ID = 430,
     FILLER = 431,
     FINAL = 432,
     FIRST = 433,
     FLOAT_BINARY_128 = 434,
     FLOAT_BINARY_32 = 435,
     FLOAT_BINARY_64 = 436,
     FLOAT_DECIMAL_16 = 437,
     FLOAT_DECIMAL_34 = 438,
     FLOAT_DECIMAL_7 = 439,
     FLOAT_EXTENDED = 440,
     FLOAT_LONG = 441,
     FLOAT_SHORT = 442,
     FOOTING = 443,
     FOR = 444,
     FOREGROUND_COLOR = 445,
     FOREVER = 446,
     FORMATTED_CURRENT_FUNC = 447,
     FORMATTED_DATE_FUNC = 448,
     FORMATTED_DATETIME_FUNC = 449,
     FORMATTED_TIME_FUNC = 450,
     FREE = 451,
     FROM = 452,
     FROM_CRT = 453,
     FULL = 454,
     FUNCTION = 455,
     FUNCTION_ID = 456,
     FUNCTION_NAME = 457,
     GENERATE = 458,
     GIVING = 459,
     GLOBAL = 460,
     GO = 461,
     GOBACK = 462,
     GREATER = 463,
     GREATER_OR_EQUAL = 464,
     GROUP = 465,
     HEADING = 466,
     HIGHLIGHT = 467,
     HIGH_VALUE = 468,
     ID = 469,
     IDENTIFICATION = 470,
     IF = 471,
     IGNORE = 472,
     IGNORING = 473,
     IN = 474,
     INDEX = 475,
     INDEXED = 476,
     INDICATE = 477,
     INITIALIZE = 478,
     INITIALIZED = 479,
     INITIATE = 480,
     INPUT = 481,
     INPUT_OUTPUT = 482,
     INSPECT = 483,
     INTO = 484,
     INTRINSIC = 485,
     INVALID = 486,
     INVALID_KEY = 487,
     IS = 488,
     I_O = 489,
     I_O_CONTROL = 490,
     JUSTIFIED = 491,
     KEPT = 492,
     KEY = 493,
     KEYBOARD = 494,
     LABEL = 495,
     LAST = 496,
     LEADING = 497,
     LEFT = 498,
     LEFTLINE = 499,
     LENGTH = 500,
     LENGTH_OF = 501,
     LESS = 502,
     LESS_OR_EQUAL = 503,
     LIMIT = 504,
     LIMITS = 505,
     LINAGE = 506,
     LINAGE_COUNTER = 507,
     LINE = 508,
     LINE_COUNTER = 509,
     LINES = 510,
     LINKAGE = 511,
     LITERAL = 512,
     LOCALE = 513,
     LOCALE_DATE_FUNC = 514,
     LOCALE_TIME_FUNC = 515,
     LOCALE_TIME_FROM_FUNC = 516,
     LOCAL_STORAGE = 517,
     LOCK = 518,
     LOWER = 519,
     LOWER_CASE_FUNC = 520,
     LOWLIGHT = 521,
     LOW_VALUE = 522,
     MANUAL = 523,
     MEMORY = 524,
     MERGE = 525,
     MINUS = 526,
     MNEMONIC_NAME = 527,
     MODE = 528,
     MOVE = 529,
     MULTIPLE = 530,
     MULTIPLY = 531,
     NAME = 532,
     NATIONAL = 533,
     NATIONAL_EDITED = 534,
     NATIONAL_OF_FUNC = 535,
     NATIVE = 536,
     NEAREST_AWAY_FROM_ZERO = 537,
     NEAREST_EVEN = 538,
     NEAREST_TOWARD_ZERO = 539,
     NEGATIVE = 540,
     NEXT = 541,
     NEXT_PAGE = 542,
     NO = 543,
     NO_ECHO = 544,
     NORMAL = 545,
     NOT = 546,
     NOT_END = 547,
     NOT_EOP = 548,
     NOT_EQUAL = 549,
     NOT_EXCEPTION = 550,
     NOT_INVALID_KEY = 551,
     NOT_OVERFLOW = 552,
     NOT_SIZE_ERROR = 553,
     NO_ADVANCING = 554,
     NUMBER = 555,
     NUMBERS = 556,
     NUMERIC = 557,
     NUMERIC_EDITED = 558,
     NUMVALC_FUNC = 559,
     OBJECT_COMPUTER = 560,
     OCCURS = 561,
     OF = 562,
     OFF = 563,
     OMITTED = 564,
     ON = 565,
     ONLY = 566,
     OPEN = 567,
     OPTIONAL = 568,
     OR = 569,
     ORDER = 570,
     ORGANIZATION = 571,
     OTHER = 572,
     OUTPUT = 573,
     OVERLINE = 574,
     PACKED_DECIMAL = 575,
     PADDING = 576,
     PAGE = 577,
     PAGE_COUNTER = 578,
     PARAGRAPH = 579,
     PERFORM = 580,
     PH = 581,
     PF = 582,
     PICTURE = 583,
     PICTURE_SYMBOL = 584,
     PLUS = 585,
     POINTER = 586,
     POSITION = 587,
     POSITIVE = 588,
     PRESENT = 589,
     PREVIOUS = 590,
     PRINTER = 591,
     PRINTING = 592,
     PROCEDURE = 593,
     PROCEDURES = 594,
     PROCEED = 595,
     PROGRAM = 596,
     PROGRAM_ID = 597,
     PROGRAM_NAME = 598,
     PROGRAM_POINTER = 599,
     PROHIBITED = 600,
     PROMPT = 601,
     QUOTE = 602,
     RANDOM = 603,
     RD = 604,
     READ = 605,
     READY_TRACE = 606,
     RECORD = 607,
     RECORDING = 608,
     RECORDS = 609,
     RECURSIVE = 610,
     REDEFINES = 611,
     REEL = 612,
     REFERENCE = 613,
     REFERENCES = 614,
     RELATIVE = 615,
     RELEASE = 616,
     REMAINDER = 617,
     REMOVAL = 618,
     RENAMES = 619,
     REPLACE = 620,
     REPLACING = 621,
     REPORT = 622,
     REPORTING = 623,
     REPORTS = 624,
     REPOSITORY = 625,
     REPO_FUNCTION = 626,
     REQUIRED = 627,
     RESERVE = 628,
     RESET = 629,
     RESET_TRACE = 630,
     RETURN = 631,
     RETURNING = 632,
     REVERSE_FUNC = 633,
     REVERSE_VIDEO = 634,
     REVERSED = 635,
     REWIND = 636,
     REWRITE = 637,
     RF = 638,
     RH = 639,
     RIGHT = 640,
     ROLLBACK = 641,
     ROUNDED = 642,
     RUN = 643,
     SAME = 644,
     SCREEN = 645,
     SCREEN_CONTROL = 646,
     SCROLL = 647,
     SD = 648,
     SEARCH = 649,
     SECTION = 650,
     SECURE = 651,
     SEGMENT_LIMIT = 652,
     SELECT = 653,
     SEMI_COLON = 654,
     SENTENCE = 655,
     SEPARATE = 656,
     SEQUENCE = 657,
     SEQUENTIAL = 658,
     SET = 659,
     SHARING = 660,
     SIGN = 661,
     SIGNED = 662,
     SIGNED_INT = 663,
     SIGNED_LONG = 664,
     SIGNED_SHORT = 665,
     SIZE = 666,
     SIZE_ERROR = 667,
     SORT = 668,
     SORT_MERGE = 669,
     SOURCE = 670,
     SOURCE_COMPUTER = 671,
     SPACE = 672,
     SPECIAL_NAMES = 673,
     STANDARD = 674,
     STANDARD_1 = 675,
     STANDARD_2 = 676,
     START = 677,
     STATIC = 678,
     STATUS = 679,
     STDCALL = 680,
     STEP = 681,
     STOP = 682,
     STRING = 683,
     SUBSTITUTE_FUNC = 684,
     SUBSTITUTE_CASE_FUNC = 685,
     SUBTRACT = 686,
     SUM = 687,
     SUPPRESS = 688,
     SYMBOLIC = 689,
     SYNCHRONIZED = 690,
     SYSTEM_DEFAULT = 691,
     TAB = 692,
     TALLYING = 693,
     TAPE = 694,
     TERMINATE = 695,
     TEST = 696,
     THAN = 697,
     THEN = 698,
     THRU = 699,
     TIME = 700,
     TIMEOUT = 701,
     TIMES = 702,
     TO = 703,
     TOK_AMPER = 704,
     TOK_CLOSE_PAREN = 705,
     TOK_COLON = 706,
     TOK_DIV = 707,
     TOK_DOT = 708,
     TOK_EQUAL = 709,
     TOK_FALSE = 710,
     TOK_FILE = 711,
     TOK_GREATER = 712,
     TOK_INITIAL = 713,
     TOK_LESS = 714,
     TOK_MINUS = 715,
     TOK_MUL = 716,
     TOK_NULL = 717,
     TOK_OVERFLOW = 718,
     TOK_OPEN_PAREN = 719,
     TOK_PLUS = 720,
     TOK_TRUE = 721,
     TOP = 722,
     TOWARD_GREATER = 723,
     TOWARD_LESSER = 724,
     TRAILING = 725,
     TRANSFORM = 726,
     TRIM_FUNC = 727,
     TRUNCATION = 728,
     TYPE = 729,
     UNDERLINE = 730,
     UNIT = 731,
     UNLOCK = 732,
     UNSIGNED = 733,
     UNSIGNED_INT = 734,
     UNSIGNED_LONG = 735,
     UNSIGNED_SHORT = 736,
     UNSTRING = 737,
     UNTIL = 738,
     UP = 739,
     UPDATE = 740,
     UPON = 741,
     UPON_ARGUMENT_NUMBER = 742,
     UPON_COMMAND_LINE = 743,
     UPON_ENVIRONMENT_NAME = 744,
     UPON_ENVIRONMENT_VALUE = 745,
     UPPER = 746,
     UPPER_CASE_FUNC = 747,
     USAGE = 748,
     USE = 749,
     USER = 750,
     USER_DEFAULT = 751,
     USER_FUNCTION_NAME = 752,
     USER_REPO_FUNCTION = 753,
     USING = 754,
     VALUE = 755,
     VARYING = 756,
     WAIT = 757,
     WHEN = 758,
     WHEN_COMPILED_FUNC = 759,
     WITH = 760,
     WORD = 761,
     WORDS = 762,
     WORKING_STORAGE = 763,
     WRITE = 764,
     YYYYDDD = 765,
     YYYYMMDD = 766,
     ZERO = 767,
     SHIFT_PREFER = 768
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
#define YYLAST   7584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  514
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1897
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2714

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   768

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
     505,   506,   507,   508,   509,   510,   511,   512,   513
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
    1222,  1224,  1228,  1232,  1239,  1240,  1243,  1251,  1260,  1261,
    1264,  1265,  1268,  1269,  1273,  1274,  1278,  1279,  1281,  1283,
    1284,  1290,  1292,  1294,  1295,  1299,  1301,  1304,  1306,  1309,
    1312,  1316,  1318,  1319,  1325,  1327,  1330,  1332,  1336,  1337,
    1342,  1345,  1350,  1353,  1356,  1357,  1358,  1364,  1365,  1366,
    1372,  1373,  1374,  1380,  1381,  1384,  1385,  1392,  1393,  1396,
    1399,  1402,  1406,  1408,  1410,  1413,  1416,  1418,  1421,  1426,
    1428,  1433,  1436,  1437,  1440,  1442,  1444,  1446,  1448,  1450,
    1454,  1459,  1464,  1469,  1473,  1474,  1477,  1478,  1484,  1485,
    1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1514,  1516,  1518,  1520,  1524,  1526,  1528,
    1531,  1533,  1536,  1538,  1540,  1541,  1544,  1547,  1548,  1551,
    1556,  1561,  1562,  1566,  1568,  1570,  1574,  1581,  1584,  1588,
    1591,  1594,  1598,  1601,  1603,  1606,  1609,  1611,  1613,  1615,
    1618,  1621,  1623,  1628,  1631,  1635,  1636,  1637,  1643,  1644,
    1646,  1649,  1653,  1655,  1656,  1661,  1665,  1666,  1669,  1672,
    1675,  1677,  1679,  1682,  1685,  1687,  1689,  1691,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1710,  1712,  1714,  1720,  1726,
    1730,  1734,  1736,  1738,  1740,  1742,  1744,  1746,  1748,  1750,
    1753,  1756,  1759,  1761,  1763,  1765,  1767,  1768,  1770,  1772,
    1773,  1775,  1777,  1781,  1784,  1785,  1786,  1787,  1797,  1798,
    1803,  1804,  1805,  1809,  1810,  1814,  1816,  1819,  1824,  1825,
    1828,  1831,  1832,  1836,  1840,  1845,  1850,  1854,  1855,  1857,
    1858,  1861,  1862,  1863,  1871,  1872,  1875,  1877,  1879,  1882,
    1884,  1886,  1887,  1894,  1895,  1898,  1901,  1903,  1904,  1906,
    1907,  1908,  1912,  1913,  1916,  1919,  1921,  1923,  1925,  1927,
    1929,  1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,
    1949,  1951,  1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,
    1969,  1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1987,
    1989,  1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2007,
    2009,  2011,  2013,  2015,  2017,  2020,  2023,  2024,  2029,  2036,
    2040,  2044,  2049,  2053,  2058,  2062,  2066,  2071,  2076,  2080,
    2085,  2089,  2094,  2100,  2104,  2109,  2113,  2117,  2119,  2121,
    2123,  2126,  2127,  2129,  2133,  2137,  2140,  2143,  2146,  2150,
    2154,  2158,  2159,  2161,  2162,  2166,  2167,  2170,  2172,  2175,
    2177,  2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,  2195,
    2197,  2199,  2204,  2206,  2208,  2210,  2212,  2214,  2217,  2219,
    2221,  2225,  2229,  2233,  2237,  2241,  2243,  2245,  2246,  2248,
    2249,  2254,  2259,  2265,  2272,  2273,  2276,  2277,  2279,  2280,
    2284,  2288,  2293,  2294,  2297,  2298,  2302,  2304,  2307,  2312,
    2313,  2316,  2317,  2322,  2329,  2330,  2332,  2334,  2336,  2337,
    2338,  2342,  2344,  2347,  2350,  2354,  2355,  2358,  2361,  2364,
    2365,  2369,  2372,  2377,  2379,  2381,  2383,  2385,  2386,  2389,
    2390,  2393,  2394,  2396,  2397,  2401,  2403,  2406,  2407,  2411,
    2414,  2418,  2419,  2421,  2425,  2429,  2432,  2433,  2438,  2443,
    2444,  2446,  2448,  2450,  2451,  2456,  2460,  2463,  2465,  2468,
    2469,  2471,  2472,  2477,  2481,  2485,  2489,  2493,  2498,  2501,
    2506,  2508,  2509,  2513,  2519,  2520,  2523,  2526,  2529,  2532,
    2533,  2536,  2538,  2540,  2541,  2544,  2545,  2547,  2549,  2552,
    2554,  2557,  2560,  2562,  2564,  2567,  2570,  2572,  2574,  2576,
    2578,  2580,  2584,  2588,  2592,  2596,  2597,  2599,  2600,  2605,
    2610,  2617,  2624,  2633,  2642,  2643,  2645,  2646,  2650,  2653,
    2654,  2659,  2662,  2664,  2668,  2670,  2672,  2674,  2677,  2679,
    2681,  2684,  2687,  2691,  2694,  2698,  2700,  2704,  2707,  2709,
    2711,  2713,  2714,  2717,  2718,  2720,  2721,  2725,  2726,  2729,
    2731,  2734,  2736,  2738,  2740,  2741,  2744,  2745,  2749,  2751,
    2752,  2756,  2758,  2759,  2763,  2767,  2768,  2772,  2775,  2776,
    2783,  2787,  2790,  2792,  2793,  2795,  2796,  2800,  2806,  2807,
    2810,  2811,  2815,  2819,  2820,  2823,  2825,  2828,  2833,  2835,
    2837,  2839,  2841,  2843,  2845,  2847,  2848,  2852,  2853,  2857,
    2859,  2862,  2863,  2867,  2870,  2872,  2874,  2876,  2879,  2881,
    2883,  2885,  2886,  2890,  2893,  2899,  2901,  2904,  2907,  2910,
    2912,  2914,  2916,  2919,  2921,  2924,  2929,  2932,  2933,  2935,
    2937,  2939,  2941,  2946,  2947,  2950,  2954,  2958,  2959,  2963,
    2964,  2968,  2972,  2977,  2978,  2983,  2988,  2995,  2996,  2998,
    2999,  3003,  3008,  3014,  3016,  3018,  3020,  3022,  3023,  3027,
    3028,  3032,  3035,  3037,  3038,  3042,  3045,  3046,  3051,  3054,
    3055,  3057,  3059,  3061,  3063,  3067,  3068,  3071,  3073,  3077,
    3081,  3082,  3086,  3088,  3090,  3092,  3096,  3104,  3105,  3110,
    3118,  3119,  3122,  3123,  3126,  3129,  3133,  3137,  3141,  3144,
    3145,  3149,  3151,  3153,  3154,  3156,  3158,  3159,  3163,  3166,
    3168,  3169,  3174,  3179,  3180,  3182,  3183,  3188,  3193,  3194,
    3197,  3201,  3202,  3204,  3206,  3207,  3212,  3217,  3224,  3225,
    3228,  3229,  3232,  3234,  3237,  3241,  3242,  3244,  3245,  3249,
    3251,  3253,  3255,  3257,  3259,  3261,  3263,  3265,  3267,  3269,
    3274,  3278,  3280,  3283,  3286,  3289,  3292,  3295,  3298,  3301,
    3304,  3307,  3312,  3316,  3321,  3323,  3326,  3330,  3332,  3335,
    3339,  3343,  3344,  3348,  3349,  3357,  3358,  3364,  3365,  3368,
    3369,  3372,  3373,  3377,  3378,  3381,  3386,  3387,  3390,  3395,
    3396,  3401,  3406,  3407,  3411,  3412,  3417,  3419,  3421,  3423,
    3426,  3429,  3432,  3435,  3437,  3439,  3442,  3444,  3445,  3447,
    3448,  3453,  3456,  3457,  3460,  3465,  3470,  3471,  3473,  3475,
    3477,  3479,  3481,  3482,  3487,  3493,  3495,  3498,  3500,  3504,
    3508,  3509,  3514,  3515,  3517,  3518,  3523,  3528,  3535,  3542,
    3543,  3545,  3548,  3549,  3551,  3552,  3556,  3558,  3561,  3562,
    3566,  3572,  3573,  3577,  3580,  3581,  3583,  3585,  3586,  3591,
    3598,  3599,  3603,  3605,  3609,  3612,  3615,  3618,  3622,  3623,
    3627,  3628,  3632,  3633,  3637,  3638,  3640,  3641,  3645,  3647,
    3649,  3651,  3653,  3655,  3663,  3664,  3666,  3668,  3670,  3672,
    3674,  3676,  3681,  3683,  3686,  3688,  3691,  3695,  3696,  3698,
    3701,  3703,  3707,  3709,  3711,  3716,  3718,  3720,  3722,  3723,
    3728,  3734,  3735,  3738,  3739,  3744,  3748,  3752,  3754,  3756,
    3758,  3760,  3761,  3763,  3766,  3767,  3770,  3771,  3774,  3777,
    3778,  3781,  3782,  3785,  3788,  3789,  3792,  3793,  3796,  3799,
    3800,  3803,  3804,  3807,  3810,  3812,  3815,  3817,  3819,  3822,
    3825,  3828,  3830,  3832,  3835,  3838,  3841,  3842,  3845,  3846,
    3849,  3850,  3853,  3855,  3857,  3858,  3861,  3863,  3866,  3869,
    3871,  3873,  3875,  3877,  3879,  3881,  3883,  3885,  3887,  3889,
    3891,  3893,  3895,  3897,  3899,  3901,  3903,  3905,  3907,  3909,
    3911,  3913,  3915,  3917,  3919,  3922,  3924,  3926,  3928,  3930,
    3932,  3934,  3936,  3940,  3941,  3943,  3945,  3949,  3953,  3955,
    3959,  3963,  3965,  3969,  3971,  3974,  3977,  3979,  3983,  3985,
    3987,  3991,  3993,  3997,  3999,  4003,  4005,  4008,  4011,  4013,
    4015,  4017,  4020,  4022,  4024,  4026,  4029,  4031,  4032,  4035,
    4037,  4039,  4041,  4045,  4047,  4049,  4052,  4054,  4056,  4058,
    4061,  4063,  4065,  4067,  4069,  4071,  4073,  4076,  4078,  4080,
    4084,  4086,  4089,  4091,  4093,  4095,  4097,  4100,  4103,  4106,
    4111,  4115,  4117,  4119,  4122,  4124,  4126,  4128,  4130,  4132,
    4134,  4136,  4139,  4142,  4145,  4147,  4149,  4151,  4153,  4155,
    4157,  4159,  4161,  4163,  4165,  4167,  4169,  4171,  4173,  4175,
    4177,  4179,  4181,  4183,  4185,  4187,  4189,  4191,  4193,  4195,
    4197,  4200,  4202,  4206,  4209,  4212,  4214,  4216,  4220,  4223,
    4226,  4228,  4230,  4234,  4238,  4243,  4249,  4251,  4253,  4255,
    4257,  4259,  4261,  4263,  4265,  4267,  4269,  4271,  4274,  4276,
    4280,  4282,  4284,  4286,  4288,  4290,  4292,  4294,  4297,  4303,
    4309,  4315,  4320,  4326,  4332,  4338,  4341,  4344,  4346,  4348,
    4350,  4352,  4354,  4356,  4358,  4360,  4361,  4366,  4372,  4373,
    4377,  4380,  4382,  4386,  4390,  4392,  4396,  4398,  4402,  4403,
    4404,  4406,  4407,  4409,  4410,  4412,  4413,  4416,  4417,  4420,
    4421,  4423,  4425,  4426,  4428,  4429,  4431,  4434,  4435,  4438,
    4439,  4443,  4445,  4447,  4449,  4451,  4453,  4455,  4457,  4459,
    4460,  4463,  4465,  4467,  4469,  4471,  4473,  4475,  4477,  4479,
    4481,  4483,  4485,  4487,  4489,  4491,  4493,  4495,  4497,  4499,
    4501,  4503,  4505,  4507,  4509,  4511,  4513,  4515,  4517,  4519,
    4521,  4523,  4525,  4527,  4529,  4531,  4533,  4535,  4537,  4539,
    4541,  4543,  4545,  4547,  4549,  4551,  4553,  4555,  4557,  4559,
    4561,  4563,  4565,  4567,  4569,  4571,  4573,  4575,  4577,  4579,
    4581,  4583,  4585,  4587,  4589,  4591,  4593,  4595,  4597,  4599,
    4601,  4603,  4604,  4606,  4607,  4609,  4610,  4612,  4613,  4615,
    4616,  4618,  4619,  4621,  4622,  4624,  4625,  4627,  4628,  4630,
    4631,  4633,  4634,  4636,  4637,  4639,  4640,  4642,  4643,  4645,
    4646,  4648,  4649,  4651,  4652,  4654,  4655,  4657,  4660,  4661,
    4663,  4664,  4666,  4667,  4669,  4670,  4672,  4673,  4675,  4677,
    4678,  4680,  4681,  4683,  4685,  4686,  4688,  4690,  4691,  4694,
    4697,  4698,  4700,  4701,  4703,  4704,  4706,  4707,  4709,  4711,
    4712,  4714,  4715,  4717,  4718,  4721,  4723,  4725,  4726,  4728,
    4729,  4731,  4732,  4734,  4735,  4737,  4738,  4740,  4741,  4743,
    4744,  4746,  4747,  4749,  4752,  4753,  4755,  4756,  4758,  4759,
    4761,  4762,  4764,  4765,  4767,  4768,  4770,  4771,  4773,  4774,
    4776,  4778,  4779,  4781,  4782,  4786,  4787,  4789,  4792,  4794,
    4796,  4798,  4800,  4802,  4804,  4806,  4808,  4810,  4812,  4814,
    4816,  4818,  4820,  4822,  4824,  4826,  4828,  4830,  4832,  4834,
    4837,  4840,  4842,  4844,  4846,  4848,  4850,  4852,  4855,  4857,
    4861,  4864,  4866,  4868,  4870,  4873,  4875,  4878,  4880,  4883,
    4885,  4888,  4890,  4893,  4895,  4898,  4900,  4903
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     515,     0,    -1,    -1,   516,   517,    -1,   520,    -1,   518,
      -1,   519,    -1,   518,   519,    -1,   522,    -1,   524,    -1,
      -1,   521,   530,    -1,   534,   530,   525,   526,    -1,   534,
     530,   525,   527,    -1,   536,   530,   528,    -1,    -1,   523,
      -1,   525,   523,    -1,    -1,   527,    -1,   143,   537,   453,
      -1,    -1,   529,    -1,   139,   537,   453,    -1,    -1,    -1,
      -1,   542,   543,   544,   605,   606,   608,   607,   640,   531,
     650,   651,   652,   532,   681,   737,   739,   741,   786,   533,
     800,    -1,    -1,   342,   453,   537,   538,   535,   539,   453,
      -1,   201,   453,   537,   538,   453,    -1,   343,    -1,   257,
      -1,    -1,    26,   257,    -1,    -1,  1272,   540,  1287,    -1,
      73,    -1,    73,   541,    -1,   541,    -1,   172,    -1,   458,
      -1,   355,    -1,    -1,   154,   123,   453,    -1,    -1,    85,
     395,   453,    -1,    -1,   544,   545,    -1,   546,    -1,   550,
      -1,   569,    -1,   570,    -1,   561,    -1,    -1,   416,   453,
     547,   548,    -1,    -1,   560,   549,   453,    -1,    -1,  1303,
     108,   273,    -1,    -1,   305,   453,   551,   552,    -1,    -1,
     560,   453,    -1,   560,   553,   453,    -1,   553,   453,    -1,
     554,    -1,   553,   554,    -1,   555,    -1,   556,    -1,   557,
      -1,   558,    -1,   269,   411,  1272,  1221,  1314,    -1,  1320,
    1272,  1188,    -1,   397,  1272,  1221,    -1,  1259,    60,  1272,
     559,    -1,  1188,    -1,   258,    -1,   496,    -1,   436,    -1,
     506,    -1,   560,   506,    -1,    -1,   370,   453,   562,   563,
      -1,    -1,   564,   453,    -1,   564,     1,   453,    -1,   565,
      -1,   564,   565,    -1,   200,     9,   230,    -1,   200,   566,
     567,    -1,   200,   568,   230,    -1,   371,    -1,   498,    -1,
      -1,    26,   257,    -1,   371,    -1,   568,   371,    -1,   418,
     453,    -1,   571,   453,    -1,   571,     1,   453,    -1,   572,
      -1,   571,   572,    -1,   573,    -1,   578,    -1,   586,    -1,
     596,    -1,   593,    -1,   597,    -1,   599,    -1,   600,    -1,
     601,    -1,   602,    -1,   603,    -1,   604,    -1,    -1,   506,
     574,   575,    -1,  1272,    97,    -1,  1221,  1272,  1192,    -1,
    1272,  1192,   576,    -1,   577,    -1,    -1,   577,    -1,  1037,
    1284,  1192,    -1,   577,  1037,  1284,  1192,    -1,    -1,    11,
    1192,   579,  1272,   580,    -1,   281,    -1,   420,    -1,   421,
      -1,   127,    -1,    28,    -1,   581,    -1,   582,    -1,   581,
     582,    -1,   585,    -1,   585,   444,   585,    -1,    -1,   585,
      17,   583,   584,    -1,   585,    -1,   584,    17,   585,    -1,
     257,    -1,   417,    -1,   512,    -1,   347,    -1,   213,    -1,
     267,    -1,   588,   587,    -1,    -1,   219,   506,    -1,   434,
    1260,   589,    -1,   590,    -1,   589,   590,    -1,   591,  1273,
     592,    -1,  1193,    -1,   591,  1193,    -1,  1222,    -1,   592,
    1222,    -1,    59,  1192,  1272,   594,    -1,   595,    -1,   594,
     595,    -1,  1224,    -1,  1224,   444,  1224,    -1,   258,  1192,
    1272,   257,    -1,    99,  1290,  1272,   257,   598,    -1,    -1,
    1303,   329,   257,    -1,   109,  1272,    69,    -1,   302,   406,
    1272,   470,   401,    -1,   101,  1272,  1187,    -1,    97,   424,
    1272,  1187,    -1,   391,  1272,  1187,    -1,   165,  1272,  1187,
      -1,    -1,   227,   395,   453,    -1,    -1,   174,   453,    -1,
      -1,   235,   453,    -1,    -1,   608,   609,    -1,    -1,   398,
    1245,  1192,   610,   611,   453,    -1,   398,     1,   453,    -1,
      -1,   611,   612,    -1,   613,    -1,   619,    -1,   621,    -1,
     622,    -1,   623,    -1,   625,    -1,   629,    -1,   631,    -1,
     632,    -1,   633,    -1,   635,    -1,   636,    -1,   638,    -1,
      29,  1300,   616,   615,   617,    -1,    29,  1300,   616,   614,
     618,    -1,    29,  1300,   616,   120,   618,    -1,    29,  1300,
     616,   239,   618,    -1,    29,  1300,   616,   336,   618,    -1,
     118,    -1,   119,    -1,   439,    -1,   348,    -1,    -1,   253,
       7,  1263,    -1,    -1,   172,    -1,   126,    -1,   257,    -1,
    1218,    -1,    -1,   257,    -1,  1218,    -1,     4,  1279,  1272,
     620,    -1,   403,    -1,   126,    -1,   348,    -1,    19,  1288,
    1274,  1272,   634,  1239,    -1,  1304,  1272,   506,    -1,   624,
     424,  1272,  1187,    -1,    -1,   456,    -1,   413,    -1,    -1,
     626,   263,  1279,  1272,   627,    -1,   268,   628,    -1,    33,
     628,    -1,   168,    -1,    -1,   505,   263,   310,  1313,    -1,
     505,   263,   310,   275,  1313,    -1,   505,   386,    -1,   316,
    1272,   630,    -1,   630,    -1,   221,    -1,  1288,  1257,   403,
      -1,   360,    -1,   253,   403,    -1,   321,  1259,  1272,  1191,
      -1,   352,   114,  1272,   420,    -1,   352,  1274,  1272,   634,
      -1,  1187,    -1,  1187,   454,  1186,    -1,  1187,   415,  1272,
    1186,    -1,   360,  1274,  1272,  1187,    -1,   373,   637,  1254,
      -1,   288,    -1,  1221,    -1,   405,  1303,   639,    -1,     9,
    1285,    -1,   288,  1285,    -1,   350,   311,    -1,    -1,   641,
     453,    -1,   641,     1,   453,    -1,   642,    -1,   641,   642,
      -1,   643,    -1,   645,    -1,   389,   644,  1254,  1265,  1177,
      -1,    -1,   352,    -1,   413,    -1,   414,    -1,    -1,   275,
     646,  1263,  1296,  1261,   647,    -1,   648,    -1,   647,   648,
      -1,  1178,   649,    -1,    -1,   332,  1221,    -1,    -1,   103,
     123,   453,    -1,    -1,   456,   395,   453,    -1,    -1,   652,
     653,    -1,   654,   683,    -1,    -1,   656,  1178,   655,   657,
     453,    -1,   656,     1,   453,    -1,   173,    -1,   393,    -1,
      -1,   657,   658,    -1,  1272,   172,    -1,  1272,   205,    -1,
     659,    -1,   661,    -1,   665,    -1,   666,    -1,   669,    -1,
     670,    -1,   676,    -1,   677,    -1,   678,    -1,    47,  1261,
    1221,   664,   660,    -1,    -1,   354,    -1,    58,    -1,   352,
    1261,  1221,  1260,    -1,   352,  1261,  1221,   448,  1221,  1260,
      -1,   352,  1272,   501,  1267,  1293,   663,   664,  1260,   662,
      -1,    -1,   115,  1283,  1187,    -1,    -1,  1266,  1221,    -1,
      -1,   448,  1221,    -1,   240,  1315,  1311,    -1,   500,   307,
     667,  1272,   668,    -1,   500,   307,   175,  1272,   668,    -1,
     506,    -1,   214,    -1,   257,    -1,  1218,    -1,   103,  1315,
    1189,    -1,   251,  1272,  1191,  1278,   671,    -1,    -1,   671,
     672,    -1,   673,    -1,   674,    -1,   675,    -1,  1303,   188,
    1256,  1191,    -1,   467,  1191,    -1,    48,  1191,    -1,   353,
    1279,  1272,   506,    -1,    63,  1272,   506,    -1,   679,   680,
      -1,   367,  1272,    -1,   369,  1253,    -1,  1192,    -1,   680,
    1192,    -1,    -1,    -1,   508,   395,   453,   682,   683,    -1,
      -1,    -1,   684,   685,    -1,   686,   453,    -1,   685,   686,
     453,    -1,   685,   453,    -1,   698,    -1,    -1,   688,   689,
     687,   700,    -1,   688,     1,   453,    -1,  1237,   506,    -1,
      -1,   176,    -1,   506,    -1,   506,    -1,    -1,  1272,   205,
      -1,  1225,    -1,   246,   693,    -1,   245,   693,    -1,    50,
    1282,   693,    -1,  1215,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   697,    -1,   709,    -1,   710,
      -1,   694,    -1,   695,    -1,   696,    -1,     1,   453,    -1,
     180,    -1,   184,    -1,   181,    -1,   182,    -1,   179,    -1,
     183,    -1,   185,    -1,   331,    -1,   344,    -1,   688,   690,
      86,   691,   699,    -1,  1255,   692,    -1,   197,   506,    -1,
      -1,   700,   701,    -1,   702,    -1,   703,    -1,   705,    -1,
     706,    -1,   707,    -1,   711,    -1,   714,    -1,   726,    -1,
     727,    -1,   728,    -1,   729,    -1,   730,    -1,   735,    -1,
     736,    -1,   356,  1215,    -1,  1272,   172,   704,    -1,    -1,
      26,   257,    -1,  1272,   205,    -1,   328,    -1,   708,    -1,
     493,  1272,   708,    -1,    39,    -1,    74,    -1,   709,    -1,
     710,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,   120,    -1,   220,    -1,   320,    -1,   331,    -1,
     344,    -1,   410,    -1,   408,    -1,   409,    -1,   481,    -1,
     479,    -1,   480,    -1,    41,  1291,    -1,    41,   478,    -1,
      44,  1291,    -1,    44,   478,    -1,    43,  1291,    -1,    43,
     478,    -1,    42,  1291,    -1,    42,   478,    -1,    40,  1291,
      -1,    40,   478,    -1,   180,    -1,   181,    -1,   179,    -1,
     182,    -1,   183,    -1,   278,    -1,    76,    -1,   187,    -1,
      77,    -1,   186,    -1,  1292,   242,  1249,    -1,  1292,   470,
    1249,    -1,   306,  1221,   715,  1298,   717,   713,    -1,    -1,
     426,  1221,    -1,   306,  1221,   715,  1298,   717,   720,   723,
      -1,   306,   126,   718,   716,   715,   719,   720,   723,    -1,
      -1,   448,  1221,    -1,    -1,   197,  1221,    -1,    -1,   115,
    1283,  1187,    -1,    -1,    53,  1267,   506,    -1,    -1,   224,
      -1,   721,    -1,    -1,   721,   722,  1274,  1272,  1186,    -1,
      27,    -1,   116,    -1,    -1,   221,  1258,   724,    -1,   725,
      -1,   724,   725,    -1,   506,    -1,   236,  1289,    -1,   435,
    1275,    -1,    45,  1301,   512,    -1,    36,    -1,    -1,   500,
    1273,   732,   731,   734,    -1,   733,    -1,   732,   733,    -1,
    1225,    -1,  1225,   444,  1225,    -1,    -1,  1302,   455,  1272,
    1225,    -1,   364,  1218,    -1,   364,  1218,   444,  1218,    -1,
      21,   245,    -1,    21,   302,    -1,    -1,    -1,   262,   395,
     453,   738,   683,    -1,    -1,    -1,   256,   395,   453,   740,
     683,    -1,    -1,    -1,   367,   395,   453,   742,   743,    -1,
      -1,   743,   744,    -1,    -1,   349,  1179,   745,   746,   453,
     760,    -1,    -1,   746,   747,    -1,     1,   453,    -1,  1272,
     205,    -1,    62,  1272,  1205,    -1,   748,    -1,   751,    -1,
    1328,   749,    -1,  1264,   750,    -1,  1214,    -1,   750,  1214,
      -1,   322,  1277,   752,   753,    -1,  1223,    -1,  1223,  1312,
    1223,  1306,    -1,  1223,  1312,    -1,    -1,   753,   754,    -1,
     755,    -1,   756,    -1,   757,    -1,   758,    -1,   759,    -1,
     211,  1272,  1223,    -1,   178,  1321,  1272,  1223,    -1,   241,
    1322,  1272,  1223,    -1,   241,  1321,  1272,  1223,    -1,   188,
    1272,  1223,    -1,    -1,   760,   761,    -1,    -1,   688,   689,
     762,   763,   453,    -1,    -1,   763,   764,    -1,   765,    -1,
     769,    -1,   775,    -1,   706,    -1,   785,    -1,   711,    -1,
     726,    -1,   777,    -1,   728,    -1,   783,    -1,   770,    -1,
     730,    -1,   773,    -1,   784,    -1,   712,    -1,   774,    -1,
     474,  1272,   766,    -1,  1326,    -1,  1324,    -1,  1322,   767,
      -1,  1321,    -1,  1323,   767,    -1,  1325,    -1,  1327,    -1,
      -1,  1214,   768,    -1,   177,   768,    -1,    -1,   314,   322,
      -1,   286,   210,  1272,   780,    -1,   432,  1282,  1198,   771,
      -1,    -1,   374,  1283,   772,    -1,  1214,    -1,   177,    -1,
     334,   503,  1154,    -1,   501,  1214,   197,  1200,    49,  1200,
      -1,   776,   779,    -1,   253,  1281,  1273,    -1,   255,  1253,
      -1,   778,   781,    -1,  1305,  1281,  1273,    -1,  1306,  1253,
      -1,   780,    -1,   779,   780,    -1,   330,  1221,    -1,  1223,
      -1,   287,    -1,   782,    -1,   781,   782,    -1,   330,  1221,
      -1,  1223,    -1,   415,  1272,  1200,  1246,    -1,   210,  1269,
      -1,   493,  1272,   120,    -1,    -1,    -1,   390,   395,   453,
     787,   788,    -1,    -1,   789,    -1,   790,   453,    -1,   789,
     790,   453,    -1,   698,    -1,    -1,   688,   689,   791,   792,
      -1,   688,     1,   453,    -1,    -1,   792,   793,    -1,    45,
     253,    -1,    45,   390,    -1,    38,    -1,    46,    -1,   161,
     157,    -1,   161,   159,    -1,   212,    -1,   266,    -1,   379,
      -1,   475,    -1,   319,    -1,   244,    -1,    32,    -1,   396,
      -1,   372,    -1,   199,    -1,   346,    57,  1272,  1205,    -1,
     346,    -1,   458,    -1,   253,  1280,  1272,   796,  1207,    -1,
    1305,  1280,  1272,   797,  1207,    -1,   190,  1272,  1207,    -1,
      35,  1272,  1207,    -1,   707,    -1,   728,    -1,   799,    -1,
     726,    -1,   711,    -1,   730,    -1,   706,    -1,   798,    -1,
     499,  1214,    -1,   197,  1206,    -1,   448,  1214,    -1,   330,
      -1,   465,    -1,   271,    -1,   460,    -1,    -1,   794,    -1,
     795,    -1,    -1,   794,    -1,   795,    -1,   306,  1221,  1298,
      -1,  1272,   205,    -1,    -1,    -1,    -1,   338,   123,   804,
     812,   453,   801,   813,   802,   815,    -1,    -1,   803,   826,
     453,   815,    -1,    -1,    -1,   499,   805,   807,    -1,    -1,
      56,   806,   807,    -1,   808,    -1,   807,   808,    -1,   809,
     810,   811,   506,    -1,    -1,  1258,   358,    -1,  1258,   500,
      -1,    -1,   411,  1272,    32,    -1,   411,  1272,   111,    -1,
     478,   411,  1272,    32,    -1,   478,   411,  1272,  1221,    -1,
     411,  1272,  1221,    -1,    -1,   313,    -1,    -1,   377,   506,
      -1,    -1,    -1,   110,   453,   814,   815,   130,   110,   453,
      -1,    -1,   815,   816,    -1,   817,    -1,   820,    -1,   826,
     453,    -1,   821,    -1,   453,    -1,    -1,   506,   395,   822,
     453,   818,   819,    -1,    -1,  1108,   453,    -1,   506,   453,
      -1,   506,    -1,    -1,  1221,    -1,    -1,    -1,   824,   825,
     826,    -1,    -1,   827,   828,    -1,   826,   828,    -1,   829,
      -1,   845,    -1,   850,    -1,   854,    -1,   859,    -1,   874,
      -1,   877,    -1,   885,    -1,   881,    -1,   886,    -1,   887,
      -1,   892,    -1,   906,    -1,   910,    -1,   913,    -1,   927,
      -1,   931,    -1,   934,    -1,   937,    -1,   941,    -1,   942,
      -1,   946,    -1,   956,    -1,   959,    -1,   976,    -1,   978,
      -1,   981,    -1,   985,    -1,   991,    -1,  1003,    -1,  1011,
      -1,  1012,    -1,  1015,    -1,  1016,    -1,  1020,    -1,  1025,
      -1,  1026,    -1,  1034,    -1,  1049,    -1,  1059,    -1,  1068,
      -1,  1073,    -1,  1080,    -1,  1084,    -1,  1086,    -1,  1089,
      -1,  1092,    -1,  1096,    -1,  1123,    -1,   286,   400,    -1,
       1,  1250,    -1,    -1,     3,   830,   831,   844,    -1,   832,
     834,   838,   839,   840,  1131,    -1,  1214,   197,   833,    -1,
    1214,   197,  1306,    -1,  1214,   197,   104,   511,    -1,  1214,
     197,   104,    -1,  1214,   197,   105,   510,    -1,  1214,   197,
     105,    -1,  1214,   197,   106,    -1,  1214,   197,   163,   238,
      -1,  1214,   197,   166,   424,    -1,  1214,   197,   445,    -1,
    1214,   197,   495,   277,    -1,  1214,   197,    70,    -1,  1214,
     197,   156,  1131,    -1,  1214,   197,   154,  1203,  1131,    -1,
    1214,   197,    24,    -1,  1214,   197,    25,  1131,    -1,  1214,
     197,  1181,    -1,  1214,   197,   506,    -1,  1214,    -1,   309,
      -1,   255,    -1,   253,   300,    -1,    -1,   835,    -1,  1256,
     836,   837,    -1,  1256,   837,   836,    -1,  1256,   836,    -1,
    1256,   837,    -1,    30,  1203,    -1,   253,  1280,  1207,    -1,
    1305,  1280,  1207,    -1,   332,  1280,  1207,    -1,    -1,   198,
      -1,    -1,   273,  1272,    47,    -1,    -1,   505,   841,    -1,
     842,    -1,   841,   842,    -1,    32,    -1,   437,    -1,    38,
      -1,    46,    -1,    92,    -1,   199,    -1,   212,    -1,   244,
      -1,   264,    -1,   266,    -1,   289,    -1,   319,    -1,   346,
      57,  1272,  1205,    -1,   346,    -1,   372,    -1,   379,    -1,
     396,    -1,   475,    -1,   288,   843,    -1,   843,    -1,   491,
      -1,   190,  1272,  1207,    -1,    35,  1272,  1207,    -1,   392,
     484,  1153,    -1,   392,   124,  1153,    -1,   446,  1252,  1208,
      -1,   485,    -1,   111,    -1,    -1,   131,    -1,    -1,     5,
     846,   847,   849,    -1,  1196,   448,  1173,  1137,    -1,  1196,
     848,   204,  1173,  1137,    -1,    95,  1214,   448,  1214,  1246,
    1137,    -1,    -1,   448,  1197,    -1,    -1,   132,    -1,    -1,
      10,   851,   852,    -1,  1214,  1240,   853,    -1,  1167,    58,
    1241,   853,    -1,    -1,   377,  1195,    -1,    -1,    18,   855,
     856,    -1,   857,    -1,   856,   857,    -1,  1183,   448,   858,
    1183,    -1,    -1,   340,   448,    -1,    -1,    51,   860,   861,
     873,    -1,   862,  1206,   863,   868,   871,   872,    -1,    -1,
     423,    -1,   425,    -1,   272,    -1,    -1,    -1,   499,   864,
     865,    -1,   866,    -1,   865,   866,    -1,   867,   309,    -1,
     867,   810,  1197,    -1,    -1,  1258,   358,    -1,  1258,    88,
      -1,  1258,   500,    -1,    -1,   869,  1271,  1214,    -1,   869,
     870,    -1,   869,     6,  1282,  1214,    -1,   377,    -1,   204,
      -1,   462,    -1,   309,    -1,    -1,  1309,   823,    -1,    -1,
     295,   823,    -1,    -1,   133,    -1,    -1,    52,   875,   876,
      -1,  1205,    -1,   876,  1205,    -1,    -1,    61,   878,   879,
      -1,  1178,   880,    -1,   879,  1178,   880,    -1,    -1,  1316,
      -1,  1316,  1265,   363,    -1,  1303,   288,   381,    -1,  1303,
     263,    -1,    -1,    75,   882,   883,   884,    -1,  1173,  1307,
    1167,  1137,    -1,    -1,   134,    -1,    72,    -1,    89,    -1,
      -1,   112,   888,   889,   891,    -1,  1178,  1288,  1150,    -1,
     456,   890,    -1,  1178,    -1,   890,  1178,    -1,    -1,   135,
      -1,    -1,   120,   893,   894,   905,    -1,  1205,   489,  1134,
      -1,  1205,   490,  1134,    -1,  1205,   487,  1134,    -1,  1205,
     488,  1134,    -1,  1196,   898,   902,  1134,    -1,   895,  1134,
      -1,  1197,   505,   903,  1134,    -1,   897,    -1,    -1,   895,
     896,   897,    -1,  1197,   835,   899,   839,   901,    -1,    -1,
     486,  1181,    -1,   486,   506,    -1,   486,   336,    -1,   486,
      97,    -1,    -1,   486,   900,    -1,    97,    -1,    98,    -1,
      -1,   505,   903,    -1,    -1,   299,    -1,   904,    -1,   903,
     904,    -1,    38,    -1,    45,   253,    -1,    45,   390,    -1,
      46,    -1,    92,    -1,   161,   157,    -1,   161,   159,    -1,
     212,    -1,   266,    -1,   319,    -1,   379,    -1,   475,    -1,
     190,  1272,  1207,    -1,    35,  1272,  1207,    -1,   392,   484,
    1153,    -1,   392,   124,  1153,    -1,    -1,   136,    -1,    -1,
     122,   907,   908,   909,    -1,  1197,   229,  1173,  1137,    -1,
    1197,   229,  1197,   204,  1173,  1137,    -1,  1197,    49,  1197,
     204,  1173,  1137,    -1,  1197,   229,  1197,   204,  1174,   362,
    1174,  1137,    -1,  1197,    49,  1197,   204,  1174,   362,  1174,
    1137,    -1,    -1,   137,    -1,    -1,   153,   911,   912,    -1,
     257,   863,    -1,    -1,   164,   914,   915,   926,    -1,   916,
     918,    -1,   917,    -1,   916,    17,   917,    -1,  1155,    -1,
     466,    -1,   455,    -1,   919,   921,    -1,   919,    -1,   920,
      -1,   919,   920,    -1,   922,   823,    -1,   503,   317,   823,
      -1,   503,   923,    -1,   922,   503,   923,    -1,   924,    -1,
     923,    17,   924,    -1,  1156,   925,    -1,    21,    -1,   466,
      -1,   455,    -1,    -1,   444,  1155,    -1,    -1,   138,    -1,
      -1,   169,   928,   929,    -1,    -1,   341,   930,    -1,   200,
      -1,   325,   102,    -1,   325,    -1,   395,    -1,   324,    -1,
      -1,   869,  1197,    -1,    -1,   196,   932,   933,    -1,  1194,
      -1,    -1,   203,   935,   936,    -1,  1218,    -1,    -1,   206,
     938,   939,    -1,  1299,  1182,   940,    -1,    -1,   115,  1283,
    1214,    -1,   207,   930,    -1,    -1,   216,   943,  1154,  1297,
     944,   945,    -1,   823,   129,   823,    -1,   129,   823,    -1,
     823,    -1,    -1,   140,    -1,    -1,   223,   947,   948,    -1,
    1194,   949,   950,   951,   955,    -1,    -1,  1303,   176,    -1,
      -1,     9,  1299,   500,    -1,   954,  1299,   500,    -1,    -1,
     366,   952,    -1,   953,    -1,   952,   953,    -1,   954,  1262,
      49,  1197,    -1,    12,    -1,    15,    -1,   302,    -1,    16,
      -1,   303,    -1,   278,    -1,   279,    -1,    -1,  1297,  1299,
     111,    -1,    -1,   225,   957,   958,    -1,  1179,    -1,   958,
    1179,    -1,    -1,   228,   960,   961,    -1,   962,   963,    -1,
    1214,    -1,  1225,    -1,  1228,    -1,   964,   966,    -1,   964,
      -1,   966,    -1,   967,    -1,    -1,   438,   965,   968,    -1,
     366,   970,    -1,    93,  1203,   448,  1204,   974,    -1,   969,
      -1,   968,   969,    -1,  1203,   189,    -1,    58,   974,    -1,
       9,    -1,   242,    -1,   470,    -1,  1203,   974,    -1,   971,
      -1,   970,   971,    -1,    58,    49,  1203,   974,    -1,   972,
     973,    -1,    -1,     9,    -1,   242,    -1,   178,    -1,   470,
      -1,  1203,    49,  1204,   974,    -1,    -1,   974,   975,    -1,
      37,  1270,  1197,    -1,     8,  1270,  1197,    -1,    -1,   270,
     977,  1051,    -1,    -1,   274,   979,   980,    -1,  1197,   448,
    1194,    -1,    95,  1197,   448,  1194,    -1,    -1,   276,   982,
     983,   984,    -1,  1197,    49,  1173,  1137,    -1,  1197,    49,
    1197,   204,  1173,  1137,    -1,    -1,   141,    -1,    -1,   312,
     986,   987,    -1,   988,   989,  1177,   990,    -1,   987,   988,
     989,  1177,   990,    -1,   226,    -1,   318,    -1,   234,    -1,
     171,    -1,    -1,   405,  1303,   639,    -1,    -1,  1303,   288,
     381,    -1,  1303,   263,    -1,   380,    -1,    -1,   325,   992,
     993,    -1,   997,   998,    -1,    -1,   998,   994,   823,   995,
      -1,   998,   996,    -1,    -1,   142,    -1,   142,    -1,   453,
      -1,  1183,    -1,  1183,   444,  1183,    -1,    -1,  1206,   447,
      -1,   191,    -1,   999,   483,  1000,    -1,   999,   501,  1001,
      -1,    -1,  1303,   441,  1128,    -1,   169,    -1,  1154,    -1,
    1002,    -1,  1001,     8,  1002,    -1,  1214,   197,  1197,    49,
    1197,   483,  1154,    -1,    -1,   350,  1004,  1005,  1010,    -1,
    1178,  1243,  1288,  1006,  1007,  1008,  1009,    -1,    -1,   229,
    1214,    -1,    -1,   218,   263,    -1,  1303,   263,    -1,  1303,
     237,   263,    -1,  1303,   288,   263,    -1,  1303,   217,   263,
      -1,  1303,   502,    -1,    -1,   238,  1272,  1214,    -1,  1150,
      -1,  1144,    -1,    -1,   144,    -1,   351,    -1,    -1,   361,
    1013,  1014,    -1,  1175,  1126,    -1,   375,    -1,    -1,   376,
    1017,  1018,  1019,    -1,  1178,  1288,  1006,  1143,    -1,    -1,
     145,    -1,    -1,   382,  1021,  1022,  1024,    -1,  1175,  1126,
    1023,  1150,    -1,    -1,  1303,   263,    -1,  1303,   288,   263,
      -1,    -1,   146,    -1,   386,    -1,    -1,   394,  1027,  1028,
    1033,    -1,  1176,  1029,  1030,  1031,    -1,     9,  1176,  1030,
     503,  1155,   823,    -1,    -1,   501,  1214,    -1,    -1,   130,
     823,    -1,  1032,    -1,  1032,  1031,    -1,   503,  1154,   823,
      -1,    -1,   147,    -1,    -1,   404,  1035,  1036,    -1,  1039,
      -1,  1040,    -1,  1043,    -1,  1044,    -1,  1045,    -1,  1047,
      -1,   310,    -1,   308,    -1,   484,    -1,   124,    -1,   154,
    1203,   448,  1203,    -1,  1211,    31,  1041,    -1,  1042,    -1,
    1041,  1042,    -1,    38,  1037,    -1,    46,  1037,    -1,   212,
    1037,    -1,   266,  1037,    -1,   379,  1037,    -1,   475,  1037,
      -1,   244,  1037,    -1,   319,  1037,    -1,  1194,   448,   153,
    1202,    -1,  1194,   448,  1197,    -1,  1194,  1038,    49,  1197,
      -1,  1046,    -1,  1045,  1046,    -1,  1180,   448,  1037,    -1,
    1048,    -1,  1047,  1048,    -1,  1194,   448,   466,    -1,  1194,
     448,   455,    -1,    -1,   413,  1050,  1051,    -1,    -1,  1212,
    1053,  1055,  1056,  1052,  1057,  1058,    -1,    -1,  1053,  1283,
     722,  1274,  1054,    -1,    -1,  1054,  1218,    -1,    -1,  1319,
    1268,    -1,    -1,  1304,  1272,  1187,    -1,    -1,   499,  1177,
      -1,   226,   338,  1272,   997,    -1,    -1,   204,  1177,    -1,
     318,   338,  1272,   997,    -1,    -1,   422,  1060,  1061,  1067,
      -1,  1178,  1063,  1062,  1150,    -1,    -1,  1303,  1318,  1167,
      -1,    -1,   238,  1272,  1064,  1214,    -1,   178,    -1,   241,
      -1,  1160,    -1,  1244,  1161,    -1,  1244,  1162,    -1,  1244,
    1163,    -1,  1244,  1164,    -1,  1065,    -1,  1066,    -1,   291,
    1160,    -1,   294,    -1,    -1,   148,    -1,    -1,   427,   388,
    1069,  1070,    -1,   427,  1072,    -1,    -1,   869,  1197,    -1,
    1303,   162,  1295,  1071,    -1,  1303,   290,  1295,  1071,    -1,
      -1,  1197,    -1,   257,    -1,   417,    -1,   512,    -1,   347,
      -1,    -1,   428,  1074,  1075,  1079,    -1,  1076,   229,  1214,
    1078,  1140,    -1,  1077,    -1,  1076,  1077,    -1,  1197,    -1,
     113,  1258,   411,    -1,   113,  1258,  1197,    -1,    -1,  1303,
     331,  1272,  1214,    -1,    -1,   149,    -1,    -1,   431,  1081,
    1082,  1083,    -1,  1196,   197,  1173,  1137,    -1,  1196,   197,
    1197,   204,  1173,  1137,    -1,    95,  1214,   197,  1214,  1246,
    1137,    -1,    -1,   150,    -1,   433,  1085,    -1,    -1,   337,
      -1,    -1,   440,  1087,  1088,    -1,  1179,    -1,  1088,  1179,
      -1,    -1,   471,  1090,  1091,    -1,  1214,   197,  1203,   448,
    1204,    -1,    -1,   477,  1093,  1094,    -1,  1178,  1095,    -1,
      -1,   352,    -1,   354,    -1,    -1,   482,  1097,  1098,  1107,
      -1,  1214,  1099,  1102,  1078,  1106,  1140,    -1,    -1,   113,
    1258,  1100,    -1,  1101,    -1,  1100,   314,  1101,    -1,  1238,
    1203,    -1,   229,  1103,    -1,  1102,  1103,    -1,  1214,  1104,
    1105,    -1,    -1,   114,  1267,  1214,    -1,    -1,    96,  1267,
    1214,    -1,    -1,   438,  1267,  1214,    -1,    -1,   151,    -1,
      -1,   494,  1109,  1110,    -1,  1111,    -1,  1114,    -1,  1118,
      -1,  1120,    -1,  1121,    -1,  1112,  1252,  1294,  1308,  1286,
    1283,  1113,    -1,    -1,   205,    -1,  1177,    -1,   226,    -1,
     318,    -1,   234,    -1,   171,    -1,  1265,   108,  1283,  1115,
      -1,  1116,    -1,  1115,  1116,    -1,  1184,    -1,     9,   339,
      -1,     9,  1117,  1218,    -1,    -1,   359,    -1,   359,   307,
      -1,   307,    -1,  1256,   341,  1119,    -1,   422,    -1,   130,
      -1,  1112,    37,   368,  1214,    -1,  1122,    -1,   167,    -1,
     128,    -1,    -1,   509,  1124,  1125,  1130,    -1,  1175,  1126,
    1127,  1023,  1129,    -1,    -1,   197,  1210,    -1,    -1,  1128,
    1251,  1207,  1276,    -1,  1128,  1251,  1181,    -1,  1128,  1251,
     322,    -1,    37,    -1,     8,    -1,  1150,    -1,  1147,    -1,
      -1,   152,    -1,  1132,  1133,    -1,    -1,   166,   823,    -1,
      -1,   295,   823,    -1,  1135,  1136,    -1,    -1,   166,   823,
      -1,    -1,   295,   823,    -1,  1138,  1139,    -1,    -1,   412,
     823,    -1,    -1,   298,   823,    -1,  1141,  1142,    -1,    -1,
     463,   823,    -1,    -1,   297,   823,    -1,  1145,  1146,    -1,
    1145,    -1,  1145,  1146,    -1,  1145,    -1,  1146,    -1,   130,
     823,    -1,   292,   823,    -1,  1148,  1149,    -1,  1148,    -1,
    1149,    -1,   158,   823,    -1,   293,   823,    -1,  1151,  1152,
      -1,    -1,   232,   823,    -1,    -1,   296,   823,    -1,    -1,
    1209,  1317,    -1,  1155,    -1,  1156,    -1,    -1,  1157,  1158,
      -1,  1159,    -1,  1158,   233,    -1,  1158,  1159,    -1,  1197,
      -1,   464,    -1,   450,    -1,   465,    -1,   460,    -1,   461,
      -1,   452,    -1,   170,    -1,  1160,    -1,  1161,    -1,  1162,
      -1,  1163,    -1,  1164,    -1,   294,    -1,   291,    -1,    20,
      -1,   314,    -1,   309,    -1,   302,    -1,    12,    -1,    13,
      -1,    14,    -1,   333,    -1,   285,    -1,   454,    -1,   160,
    1299,    -1,   457,    -1,   208,    -1,   459,    -1,   247,    -1,
     209,    -1,   248,    -1,  1167,    -1,  1165,  1166,  1167,    -1,
      -1,    71,    -1,   399,    -1,  1167,   465,  1168,    -1,  1167,
     460,  1168,    -1,  1168,    -1,  1168,   461,  1169,    -1,  1168,
     452,  1169,    -1,  1169,    -1,  1170,   170,  1169,    -1,  1170,
      -1,   465,  1171,    -1,   460,  1171,    -1,  1171,    -1,   464,
    1167,   450,    -1,  1200,    -1,   252,    -1,   252,  1310,   506,
      -1,   254,    -1,   254,  1310,   506,    -1,   323,    -1,   323,
    1310,   506,    -1,  1174,    -1,  1173,  1174,    -1,  1195,  1246,
      -1,  1218,    -1,  1218,    -1,  1178,    -1,  1177,  1178,    -1,
     506,    -1,   506,    -1,  1181,    -1,  1180,  1181,    -1,   272,
      -1,    -1,  1182,  1183,    -1,  1184,    -1,  1218,    -1,  1185,
      -1,  1185,  1310,  1185,    -1,   257,    -1,  1187,    -1,  1186,
    1187,    -1,  1218,    -1,   506,    -1,  1190,    -1,  1189,  1190,
      -1,   506,    -1,  1187,    -1,   257,    -1,   506,    -1,   506,
      -1,  1195,    -1,  1194,  1195,    -1,  1216,    -1,  1226,    -1,
       6,  1282,  1215,    -1,  1197,    -1,  1196,  1197,    -1,  1214,
      -1,  1225,    -1,  1228,    -1,  1172,    -1,   246,  1215,    -1,
     246,  1226,    -1,   246,  1228,    -1,     6,  1282,  1201,  1202,
      -1,     6,  1282,  1215,    -1,   272,    -1,  1200,    -1,  1198,
    1200,    -1,  1214,    -1,  1226,    -1,  1228,    -1,  1214,    -1,
    1226,    -1,  1228,    -1,  1172,    -1,   246,  1215,    -1,   246,
    1226,    -1,   246,  1228,    -1,   341,    -1,   153,    -1,  1215,
      -1,   257,    -1,  1214,    -1,  1226,    -1,  1214,    -1,  1225,
      -1,  1214,    -1,   257,    -1,  1214,    -1,   257,    -1,  1228,
      -1,  1211,    -1,  1221,    -1,   512,    -1,  1211,    -1,  1223,
      -1,  1211,    -1,  1221,    -1,  1214,    -1,  1225,    -1,  1228,
      -1,  1213,    -1,  1213,    -1,  1218,    -1,  1218,  1219,    -1,
    1215,    -1,  1218,  1219,  1220,    -1,  1218,  1219,    -1,  1218,
    1220,    -1,  1218,    -1,  1217,    -1,  1218,  1219,  1220,    -1,
    1218,  1219,    -1,  1218,  1220,    -1,  1218,    -1,   506,    -1,
     506,  1310,  1218,    -1,   464,  1165,   450,    -1,   464,  1167,
     451,   450,    -1,   464,  1167,   451,  1167,   450,    -1,   257,
      -1,   257,    -1,   257,    -1,   257,    -1,   417,    -1,   512,
      -1,   347,    -1,   213,    -1,   267,    -1,   462,    -1,  1226,
      -1,     9,  1227,    -1,  1227,    -1,  1226,   449,  1227,    -1,
     257,    -1,   417,    -1,   512,    -1,   347,    -1,   213,    -1,
     267,    -1,   462,    -1,  1229,  1232,    -1,  1230,   464,  1199,
     450,  1232,    -1,  1231,   464,  1165,   450,  1232,    -1,   472,
     464,  1234,   450,  1232,    -1,   304,   464,  1235,   450,    -1,
     259,   464,  1236,   450,  1232,    -1,   260,   464,  1236,   450,
    1232,    -1,   261,   464,  1236,   450,  1232,    -1,   202,  1233,
      -1,   497,  1233,    -1,   100,    -1,   504,    -1,   492,    -1,
     265,    -1,   378,    -1,    83,    -1,   429,    -1,   430,    -1,
      -1,   464,  1167,   451,   450,    -1,   464,  1167,   451,  1167,
     450,    -1,    -1,   464,  1165,   450,    -1,   464,   450,    -1,
    1199,    -1,  1199,  1166,   242,    -1,  1199,  1166,   470,    -1,
    1199,    -1,  1199,  1166,  1199,    -1,  1167,    -1,  1167,  1166,
    1187,    -1,    -1,    -1,     9,    -1,    -1,  1319,    -1,    -1,
     224,    -1,    -1,   224,  1242,    -1,    -1,   448,  1204,    -1,
      -1,   286,    -1,   335,    -1,    -1,   291,    -1,    -1,   313,
      -1,   291,   313,    -1,    -1,   387,  1247,    -1,    -1,   273,
    1272,  1248,    -1,    34,    -1,   282,    -1,   283,    -1,   284,
      -1,   345,    -1,   468,    -1,   469,    -1,   473,    -1,    -1,
     401,  1259,    -1,   453,    -1,     3,    -1,     5,    -1,    10,
      -1,    18,    -1,    51,    -1,    52,    -1,    61,    -1,    72,
      -1,    75,    -1,    89,    -1,   112,    -1,   120,    -1,   122,
      -1,   129,    -1,   153,    -1,   164,    -1,   169,    -1,   196,
      -1,   203,    -1,   206,    -1,   207,    -1,   216,    -1,   223,
      -1,   225,    -1,   228,    -1,   270,    -1,   274,    -1,   276,
      -1,   286,    -1,   312,    -1,   325,    -1,   350,    -1,   361,
      -1,   376,    -1,   382,    -1,   386,    -1,   394,    -1,   404,
      -1,   413,    -1,   422,    -1,   427,    -1,   428,    -1,   431,
      -1,   433,    -1,   440,    -1,   471,    -1,   477,    -1,   482,
      -1,   509,    -1,   131,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,   140,
      -1,   141,    -1,   142,    -1,   144,    -1,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,   151,
      -1,   152,    -1,    -1,     7,    -1,    -1,     8,    -1,    -1,
      22,    -1,    -1,    23,    -1,    -1,    26,    -1,    -1,    30,
      -1,    -1,    39,    -1,    -1,    49,    -1,    -1,    57,    -1,
      -1,    58,    -1,    -1,    87,    -1,    -1,   103,    -1,    -1,
     456,    -1,    -1,   177,    -1,    -1,   189,    -1,    -1,   197,
      -1,    -1,   219,    -1,    -1,   315,    -1,   219,   315,    -1,
      -1,   222,    -1,    -1,   458,    -1,    -1,   229,    -1,    -1,
     233,    -1,    -1,   233,    -1,    22,    -1,    -1,   238,    -1,
      -1,   243,    -1,   385,    -1,    -1,   253,    -1,   255,    -1,
      -1,   249,  1272,    -1,   250,  1253,    -1,    -1,   255,    -1,
      -1,   273,    -1,    -1,   300,    -1,    -1,   300,    -1,   301,
      -1,    -1,   307,    -1,    -1,   310,    -1,    -1,   424,   233,
      -1,   424,    -1,   233,    -1,    -1,   317,    -1,    -1,   338,
      -1,    -1,   341,    -1,    -1,   352,    -1,    -1,   385,    -1,
      -1,   406,    -1,    -1,   407,    -1,    -1,   406,    -1,   406,
     233,    -1,    -1,   411,    -1,    -1,   419,    -1,    -1,   424,
      -1,    -1,   439,    -1,    -1,   443,    -1,    -1,   447,    -1,
      -1,   448,    -1,    -1,   448,    -1,   499,    -1,    -1,   503,
      -1,    -1,   503,   404,   448,    -1,    -1,   505,    -1,    64,
     402,    -1,   402,    -1,    67,    -1,    65,    -1,    68,    -1,
      66,    -1,   454,    -1,   160,    -1,   166,    -1,   162,    -1,
     166,    -1,   463,    -1,   219,    -1,   307,    -1,   419,    -1,
     309,    -1,   253,    -1,   255,    -1,   352,    -1,   354,    -1,
      58,    -1,   507,    -1,   352,  1272,    -1,   354,  1253,    -1,
     357,    -1,   476,    -1,   253,    -1,   255,    -1,   411,    -1,
     245,    -1,   505,   125,    -1,   125,    -1,   341,    64,   402,
      -1,    64,   402,    -1,   402,    -1,   117,    -1,   107,    -1,
      90,   211,    -1,    55,    -1,    90,   188,    -1,    54,    -1,
     322,   211,    -1,   326,    -1,   322,   188,    -1,   327,    -1,
     367,   211,    -1,   384,    -1,   367,   188,    -1,   383,    -1,
      90,  1272,    -1,    91,  1253,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1368,  1368,  1368,  1400,  1401,  1405,  1406,  1410,  1411,
    1415,  1415,  1438,  1445,  1452,  1458,  1459,  1460,  1464,  1465,
    1469,  1493,  1494,  1498,  1532,  1538,  1550,  1524,  1560,  1559,
    1597,  1632,  1633,  1637,  1638,  1641,  1642,  1646,  1655,  1664,
    1665,  1669,  1673,  1682,  1683,  1691,  1692,  1702,  1703,  1707,
    1708,  1709,  1710,  1711,  1718,  1717,  1730,  1731,  1734,  1735,
    1749,  1748,  1758,  1759,  1760,  1761,  1765,  1766,  1770,  1771,
    1772,  1773,  1777,  1784,  1791,  1798,  1809,  1813,  1817,  1821,
    1828,  1829,  1836,  1835,  1846,  1847,  1848,  1855,  1856,  1860,
    1864,  1876,  1880,  1881,  1886,  1889,  1896,  1901,  1912,  1925,
    1926,  1934,  1935,  1939,  1940,  1941,  1942,  1943,  1944,  1945,
    1946,  1947,  1948,  1949,  1950,  1958,  1957,  1976,  1986,  1999,
    2007,  2010,  2011,  2015,  2025,  2041,  2040,  2064,  2070,  2076,
    2082,  2088,  2094,  2104,  2108,  2115,  2119,  2124,  2123,  2134,
    2138,  2145,  2146,  2147,  2148,  2149,  2150,  2157,  2172,  2175,
    2182,  2190,  2194,  2205,  2225,  2233,  2244,  2245,  2251,  2272,
    2273,  2277,  2281,  2302,  2325,  2407,  2410,  2419,  2438,  2454,
    2472,  2490,  2507,  2523,  2524,  2531,  2532,  2540,  2541,  2551,
    2552,  2557,  2556,  2577,  2587,  2588,  2592,  2593,  2594,  2595,
    2596,  2597,  2598,  2599,  2600,  2601,  2602,  2603,  2604,  2611,
    2617,  2627,  2640,  2653,  2669,  2670,  2671,  2672,  2675,  2676,
    2682,  2683,  2687,  2691,  2692,  2697,  2700,  2701,  2708,  2716,
    2717,  2718,  2725,  2752,  2763,  2770,  2772,  2773,  2779,  2779,
    2786,  2791,  2796,  2803,  2804,  2805,  2809,  2820,  2821,  2825,
    2830,  2835,  2840,  2851,  2862,  2872,  2880,  2881,  2882,  2888,
    2899,  2906,  2907,  2913,  2921,  2922,  2923,  2929,  2930,  2931,
    2938,  2939,  2943,  2944,  2950,  2978,  2979,  2980,  2981,  2988,
    2987,  3003,  3004,  3008,  3011,  3012,  3018,  3019,  3027,  3028,
    3036,  3037,  3041,  3062,  3061,  3078,  3085,  3089,  3095,  3096,
    3100,  3110,  3125,  3126,  3127,  3128,  3129,  3130,  3131,  3132,
    3133,  3140,  3147,  3147,  3147,  3153,  3173,  3207,  3238,  3239,
    3246,  3247,  3251,  3252,  3259,  3270,  3275,  3286,  3287,  3291,
    3292,  3298,  3309,  3327,  3328,  3332,  3333,  3334,  3338,  3345,
    3352,  3361,  3373,  3425,  3440,  3441,  3445,  3455,  3494,  3496,
    3495,  3511,  3514,  3514,  3531,  3532,  3534,  3538,  3540,  3539,
    3574,  3587,  3595,  3600,  3606,  3615,  3625,  3628,  3640,  3641,
    3642,  3643,  3647,  3651,  3655,  3659,  3663,  3667,  3671,  3675,
    3679,  3683,  3687,  3691,  3695,  3706,  3707,  3711,  3712,  3716,
    3717,  3718,  3722,  3723,  3727,  3753,  3757,  3766,  3770,  3779,
    3780,  3781,  3782,  3783,  3784,  3785,  3786,  3787,  3788,  3789,
    3790,  3791,  3792,  3799,  3823,  3851,  3854,  3863,  3888,  3899,
    3900,  3904,  3908,  3912,  3916,  3920,  3924,  3928,  3932,  3936,
    3940,  3944,  3948,  3952,  3957,  3962,  3966,  3970,  3978,  3982,
    3986,  3994,  3998,  4002,  4006,  4010,  4014,  4018,  4022,  4026,
    4034,  4042,  4046,  4050,  4054,  4058,  4062,  4070,  4071,  4075,
    4076,  4082,  4088,  4100,  4118,  4119,  4128,  4149,  4170,  4171,
    4175,  4176,  4179,  4180,  4186,  4187,  4194,  4195,  4202,  4226,
    4227,  4244,  4245,  4248,  4249,  4256,  4257,  4262,  4273,  4284,
    4295,  4306,  4335,  4334,  4343,  4344,  4348,  4349,  4352,  4353,
    4366,  4379,  4400,  4409,  4423,  4425,  4424,  4444,  4446,  4445,
    4461,  4463,  4462,  4471,  4472,  4479,  4478,  4491,  4492,  4493,
    4500,  4505,  4509,  4510,  4516,  4523,  4527,  4528,  4534,  4571,
    4575,  4580,  4586,  4587,  4592,  4593,  4594,  4595,  4596,  4600,
    4607,  4614,  4621,  4628,  4634,  4635,  4640,  4639,  4646,  4647,
    4651,  4652,  4653,  4654,  4655,  4656,  4657,  4658,  4659,  4660,
    4661,  4662,  4663,  4664,  4665,  4666,  4670,  4677,  4678,  4679,
    4680,  4681,  4682,  4683,  4686,  4687,  4688,  4691,  4692,  4696,
    4703,  4709,  4710,  4714,  4715,  4719,  4726,  4730,  4737,  4738,
    4742,  4749,  4750,  4754,  4755,  4759,  4760,  4761,  4765,  4766,
    4770,  4771,  4775,  4782,  4789,  4797,  4799,  4798,  4819,  4820,
    4824,  4825,  4830,  4832,  4831,  4888,  4906,  4907,  4911,  4915,
    4919,  4923,  4927,  4931,  4935,  4939,  4943,  4947,  4951,  4955,
    4959,  4963,  4967,  4971,  4975,  4980,  4984,  4988,  4993,  4998,
    5003,  5008,  5009,  5010,  5011,  5012,  5013,  5014,  5015,  5016,
    5023,  5028,  5037,  5038,  5042,  5043,  5048,  5051,  5055,  5063,
    5066,  5070,  5078,  5089,  5097,  5099,  5109,  5098,  5136,  5136,
    5169,  5173,  5172,  5186,  5185,  5205,  5206,  5211,  5218,  5220,
    5224,  5234,  5236,  5244,  5252,  5260,  5289,  5320,  5322,  5332,
    5337,  5364,  5366,  5365,  5402,  5403,  5407,  5408,  5409,  5426,
    5427,  5438,  5437,  5487,  5488,  5492,  5540,  5553,  5556,  5575,
    5580,  5574,  5593,  5593,  5623,  5630,  5631,  5632,  5633,  5634,
    5635,  5636,  5637,  5638,  5639,  5640,  5641,  5642,  5643,  5644,
    5645,  5646,  5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,
    5655,  5656,  5657,  5658,  5659,  5660,  5661,  5662,  5663,  5664,
    5665,  5666,  5667,  5668,  5669,  5670,  5671,  5672,  5673,  5674,
    5675,  5676,  5677,  5678,  5679,  5693,  5705,  5704,  5720,  5726,
    5730,  5734,  5739,  5744,  5749,  5754,  5758,  5762,  5766,  5770,
    5775,  5779,  5783,  5787,  5791,  5795,  5799,  5806,  5807,  5814,
    5815,  5819,  5820,  5824,  5825,  5826,  5827,  5828,  5832,  5836,
    5837,  5840,  5841,  5844,  5845,  5851,  5852,  5856,  5857,  5861,
    5865,  5871,  5875,  5879,  5883,  5887,  5891,  5895,  5899,  5903,
    5907,  5911,  5915,  5919,  5923,  5927,  5931,  5935,  5941,  5945,
    5949,  5953,  5957,  5961,  5965,  5972,  5973,  5977,  5981,  5999,
    5998,  6007,  6011,  6015,  6021,  6022,  6029,  6033,  6044,  6043,
    6052,  6056,  6068,  6069,  6077,  6076,  6085,  6086,  6090,  6096,
    6096,  6103,  6102,  6112,  6132,  6136,  6141,  6146,  6167,  6171,
    6170,  6187,  6188,  6193,  6201,  6225,  6227,  6231,  6240,  6253,
    6256,  6260,  6264,  6287,  6288,  6292,  6293,  6298,  6301,  6309,
    6313,  6321,  6325,  6336,  6335,  6343,  6347,  6358,  6357,  6365,
    6370,  6378,  6379,  6380,  6381,  6382,  6390,  6389,  6398,  6405,
    6409,  6419,  6430,  6448,  6447,  6456,  6460,  6464,  6469,  6477,
    6481,  6492,  6491,  6501,  6505,  6509,  6513,  6517,  6521,  6522,
    6531,  6533,  6532,  6540,  6549,  6556,  6560,  6564,  6568,  6578,
    6580,  6584,  6585,  6588,  6590,  6597,  6598,  6602,  6603,  6608,
    6612,  6616,  6620,  6624,  6628,  6632,  6636,  6640,  6644,  6648,
    6652,  6656,  6660,  6664,  6668,  6675,  6679,  6690,  6689,  6698,
    6702,  6706,  6710,  6714,  6721,  6725,  6736,  6735,  6744,  6763,
    6762,  6786,  6794,  6795,  6800,  6811,  6822,  6836,  6840,  6847,
    6848,  6853,  6862,  6871,  6876,  6885,  6886,  6891,  6953,  6954,
    6955,  6959,  6960,  6964,  6968,  6979,  6978,  6990,  6991,  7012,
    7026,  7048,  7070,  7090,  7113,  7114,  7122,  7121,  7130,  7141,
    7140,  7150,  7157,  7156,  7169,  7178,  7182,  7193,  7209,  7208,
    7217,  7221,  7225,  7232,  7236,  7247,  7246,  7254,  7262,  7263,
    7267,  7268,  7269,  7274,  7277,  7284,  7288,  7296,  7303,  7304,
    7305,  7306,  7307,  7308,  7309,  7314,  7317,  7327,  7326,  7335,
    7341,  7353,  7352,  7361,  7365,  7369,  7373,  7380,  7381,  7382,
    7383,  7390,  7389,  7403,  7413,  7422,  7423,  7427,  7428,  7429,
    7430,  7431,  7432,  7436,  7437,  7441,  7446,  7453,  7454,  7455,
    7456,  7457,  7461,  7489,  7492,  7499,  7503,  7513,  7512,  7525,
    7524,  7532,  7536,  7547,  7546,  7555,  7559,  7566,  7570,  7581,
    7580,  7588,  7609,  7633,  7634,  7635,  7636,  7640,  7641,  7645,
    7646,  7647,  7648,  7660,  7659,  7670,  7676,  7675,  7686,  7694,
    7702,  7709,  7713,  7726,  7733,  7745,  7748,  7753,  7757,  7768,
    7775,  7776,  7780,  7781,  7784,  7785,  7790,  7801,  7800,  7809,
    7836,  7837,  7842,  7845,  7849,  7853,  7857,  7861,  7865,  7872,
    7873,  7877,  7878,  7882,  7886,  7896,  7907,  7906,  7914,  7924,
    7935,  7934,  7943,  7950,  7954,  7965,  7964,  7976,  7985,  7988,
    7992,  7999,  8003,  8013,  8025,  8024,  8033,  8037,  8046,  8047,
    8052,  8055,  8063,  8067,  8074,  8082,  8086,  8097,  8096,  8110,
    8111,  8112,  8113,  8114,  8115,  8119,  8120,  8124,  8125,  8131,
    8140,  8147,  8148,  8152,  8156,  8160,  8164,  8168,  8172,  8176,
    8180,  8189,  8193,  8202,  8211,  8212,  8216,  8225,  8226,  8230,
    8234,  8245,  8244,  8253,  8252,  8283,  8286,  8306,  8307,  8310,
    8311,  8319,  8320,  8325,  8330,  8340,  8356,  8361,  8371,  8388,
    8387,  8397,  8410,  8413,  8421,  8424,  8429,  8434,  8442,  8443,
    8444,  8445,  8446,  8447,  8451,  8459,  8460,  8464,  8468,  8479,
    8478,  8488,  8501,  8504,  8508,  8516,  8528,  8531,  8538,  8539,
    8540,  8541,  8548,  8547,  8556,  8563,  8564,  8568,  8569,  8570,
    8574,  8575,  8579,  8583,  8594,  8593,  8602,  8606,  8610,  8617,
    8621,  8631,  8642,  8643,  8650,  8649,  8658,  8664,  8676,  8675,
    8683,  8697,  8696,  8704,  8717,  8719,  8720,  8728,  8727,  8736,
    8744,  8745,  8750,  8751,  8756,  8763,  8764,  8769,  8776,  8777,
    8781,  8782,  8786,  8787,  8791,  8795,  8806,  8805,  8814,  8815,
    8816,  8817,  8818,  8822,  8849,  8852,  8864,  8874,  8879,  8884,
    8889,  8897,  8935,  8936,  8940,  8980,  8990,  9013,  9014,  9015,
    9016,  9020,  9029,  9035,  9045,  9054,  9063,  9064,  9071,  9070,
    9082,  9092,  9093,  9098,  9101,  9105,  9109,  9116,  9117,  9121,
    9122,  9126,  9130,  9142,  9145,  9146,  9155,  9156,  9165,  9168,
    9169,  9178,  9179,  9190,  9193,  9194,  9203,  9204,  9216,  9219,
    9221,  9231,  9232,  9244,  9245,  9249,  9250,  9251,  9255,  9264,
    9275,  9276,  9277,  9281,  9290,  9301,  9306,  9307,  9316,  9317,
    9328,  9332,  9342,  9349,  9356,  9356,  9366,  9367,  9368,  9372,
    9381,  9382,  9384,  9385,  9386,  9387,  9388,  9390,  9391,  9392,
    9393,  9394,  9395,  9397,  9398,  9399,  9401,  9402,  9403,  9404,
    9405,  9408,  9409,  9413,  9414,  9418,  9419,  9423,  9424,  9428,
    9432,  9438,  9442,  9448,  9449,  9450,  9454,  9455,  9456,  9460,
    9461,  9462,  9466,  9470,  9474,  9475,  9476,  9479,  9480,  9490,
    9502,  9511,  9523,  9532,  9544,  9559,  9560,  9565,  9574,  9580,
    9600,  9604,  9625,  9666,  9680,  9681,  9686,  9692,  9693,  9698,
    9710,  9711,  9712,  9719,  9730,  9731,  9735,  9743,  9751,  9755,
    9762,  9771,  9772,  9778,  9792,  9809,  9813,  9820,  9821,  9822,
    9829,  9833,  9840,  9841,  9842,  9843,  9844,  9848,  9852,  9856,
    9860,  9864,  9885,  9889,  9896,  9897,  9898,  9902,  9903,  9904,
    9905,  9906,  9910,  9914,  9921,  9922,  9926,  9927,  9931,  9932,
    9936,  9937,  9948,  9949,  9953,  9954,  9955,  9959,  9960,  9961,
    9968,  9969,  9973,  9974,  9978,  9979,  9980,  9986,  9990,  9994,
    9995,  9999, 10003, 10010, 10017, 10024, 10034, 10041, 10051, 10061,
   10071, 10084, 10088, 10096, 10104, 10108, 10118, 10133, 10156, 10179,
   10195, 10196, 10197, 10198, 10199, 10200, 10204, 10208, 10225, 10229,
   10236, 10237, 10238, 10239, 10240, 10241, 10242, 10248, 10252, 10256,
   10260, 10264, 10268, 10272, 10276, 10280, 10284, 10291, 10292, 10296,
   10297, 10298, 10302, 10303, 10304, 10308, 10312, 10316, 10323, 10327,
   10331, 10338, 10345, 10352, 10362, 10369, 10379, 10386, 10398, 10406,
   10407, 10411, 10412, 10416, 10417, 10422, 10425, 10433, 10436, 10443,
   10445, 10446, 10450, 10451, 10455, 10456, 10457, 10462, 10465, 10478,
   10482, 10490, 10494, 10498, 10502, 10506, 10510, 10514, 10518, 10525,
   10526, 10532, 10533, 10534, 10535, 10536, 10537, 10538, 10539, 10540,
   10541, 10542, 10543, 10544, 10545, 10546, 10547, 10548, 10549, 10550,
   10551, 10552, 10553, 10554, 10555, 10556, 10557, 10558, 10559, 10560,
   10561, 10562, 10563, 10564, 10565, 10566, 10567, 10568, 10569, 10570,
   10571, 10572, 10573, 10574, 10575, 10576, 10577, 10578, 10579, 10580,
   10581, 10582, 10583, 10584, 10585, 10586, 10587, 10588, 10589, 10590,
   10591, 10592, 10593, 10594, 10595, 10596, 10597, 10598, 10599, 10600,
   10601, 10608, 10608, 10609, 10609, 10610, 10610, 10611, 10611, 10612,
   10612, 10613, 10613, 10614, 10614, 10615, 10615, 10616, 10616, 10617,
   10617, 10618, 10618, 10619, 10619, 10620, 10620, 10621, 10621, 10622,
   10622, 10623, 10623, 10624, 10624, 10625, 10625, 10625, 10626, 10626,
   10627, 10627, 10628, 10628, 10629, 10629, 10630, 10630, 10630, 10631,
   10631, 10632, 10632, 10632, 10633, 10633, 10633, 10634, 10634, 10634,
   10635, 10635, 10636, 10636, 10637, 10637, 10638, 10638, 10638, 10639,
   10639, 10640, 10640, 10641, 10641, 10641, 10641, 10642, 10642, 10643,
   10643, 10644, 10644, 10645, 10645, 10646, 10646, 10647, 10647, 10648,
   10648, 10649, 10649, 10649, 10650, 10650, 10651, 10651, 10652, 10652,
   10653, 10653, 10654, 10654, 10655, 10655, 10656, 10656, 10657, 10657,
   10657, 10658, 10658, 10659, 10659, 10660, 10660, 10664, 10664, 10665,
   10665, 10666, 10666, 10667, 10667, 10668, 10668, 10669, 10669, 10670,
   10670, 10671, 10671, 10672, 10672, 10673, 10673, 10674, 10674, 10675,
   10675, 10676, 10676, 10677, 10677, 10678, 10678, 10679, 10679, 10682,
   10683, 10684, 10688, 10688, 10689, 10689, 10690, 10690, 10691, 10691,
   10692, 10692, 10693, 10693, 10694, 10694, 10695, 10695
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
  "CAPACITY", "CF", "CH", "CHAINING", "CHARACTER", "CHARACTERS", "CLASS",
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
  "occurs_step", "occurs_clause", "occurs_to_integer",
  "occurs_from_integer", "occurs_depending", "capacity_in",
  "occurs_initialized", "occurs_keys", "occurs_key_list",
  "ascending_or_descending", "occurs_indexed", "occurs_index_list",
  "occurs_index", "justified_clause", "synchronized_clause",
  "blank_clause", "based_clause", "value_clause", "$@20",
  "value_item_list", "value_item", "false_is", "renames_clause",
  "any_length_clause", "local_storage_section", "$@21", "linkage_section",
  "$@22", "report_section", "$@23", "report_description_sequence",
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
     765,   766,   767,   768
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   514,   516,   515,   517,   517,   518,   518,   519,   519,
     521,   520,   522,   523,   524,   525,   525,   525,   526,   526,
     527,   528,   528,   529,   531,   532,   533,   530,   535,   534,
     536,   537,   537,   538,   538,   539,   539,   540,   540,   540,
     540,   541,   541,   542,   542,   543,   543,   544,   544,   545,
     545,   545,   545,   545,   547,   546,   548,   548,   549,   549,
     551,   550,   552,   552,   552,   552,   553,   553,   554,   554,
     554,   554,   555,   556,   557,   558,   559,   559,   559,   559,
     560,   560,   562,   561,   563,   563,   563,   564,   564,   565,
     565,   565,   566,   566,   567,   567,   568,   568,   569,   570,
     570,   571,   571,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   574,   573,   575,   575,   575,
     575,   576,   576,   577,   577,   579,   578,   580,   580,   580,
     580,   580,   580,   581,   581,   582,   582,   583,   582,   584,
     584,   585,   585,   585,   585,   585,   585,   586,   587,   587,
     588,   589,   589,   590,   591,   591,   592,   592,   593,   594,
     594,   595,   595,   596,   597,   598,   598,   599,   600,   601,
     602,   603,   604,   605,   605,   606,   606,   607,   607,   608,
     608,   610,   609,   609,   611,   611,   612,   612,   612,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   613,
     613,   613,   613,   613,   614,   614,   614,   614,   615,   615,
     616,   616,   616,   617,   617,   618,   618,   618,   619,   620,
     620,   620,   621,   622,   623,   624,   624,   624,   626,   625,
     627,   627,   627,   628,   628,   628,   628,   629,   629,   630,
     630,   630,   630,   631,   632,   633,   634,   634,   634,   635,
     636,   637,   637,   638,   639,   639,   639,   640,   640,   640,
     641,   641,   642,   642,   643,   644,   644,   644,   644,   646,
     645,   647,   647,   648,   649,   649,   650,   650,   651,   651,
     652,   652,   653,   655,   654,   654,   656,   656,   657,   657,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   659,   660,   660,   660,   661,   661,   661,   662,   662,
     663,   663,   664,   664,   665,   666,   666,   667,   667,   668,
     668,   669,   670,   671,   671,   672,   672,   672,   673,   674,
     675,   676,   677,   678,   679,   679,   680,   680,   681,   682,
     681,   683,   684,   683,   685,   685,   685,   686,   687,   686,
     686,   688,   689,   689,   689,   690,   691,   691,   692,   692,
     692,   692,   693,   693,   693,   693,   693,   693,   693,   693,
     693,   693,   693,   693,   693,   694,   694,   695,   695,   696,
     696,   696,   697,   697,   698,   699,   699,   700,   700,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   702,   703,   704,   704,   705,   706,   707,
     707,   708,   708,   708,   708,   708,   708,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   709,   709,   710,
     710,   711,   711,   712,   713,   713,   714,   714,   715,   715,
     716,   716,   717,   717,   718,   718,   719,   719,   720,   721,
     721,   722,   722,   723,   723,   724,   724,   725,   726,   727,
     728,   729,   731,   730,   732,   732,   733,   733,   734,   734,
     735,   735,   736,   736,   737,   738,   737,   739,   740,   739,
     741,   742,   741,   743,   743,   745,   744,   746,   746,   746,
     747,   747,   747,   747,   748,   749,   750,   750,   751,   752,
     752,   752,   753,   753,   754,   754,   754,   754,   754,   755,
     756,   757,   758,   759,   760,   760,   762,   761,   763,   763,
     764,   764,   764,   764,   764,   764,   764,   764,   764,   764,
     764,   764,   764,   764,   764,   764,   765,   766,   766,   766,
     766,   766,   766,   766,   767,   767,   767,   768,   768,   769,
     770,   771,   771,   772,   772,   773,   774,   775,   776,   776,
     777,   778,   778,   779,   779,   780,   780,   780,   781,   781,
     782,   782,   783,   784,   785,   786,   787,   786,   788,   788,
     789,   789,   790,   791,   790,   790,   792,   792,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   794,   794,   795,   795,   796,   796,   796,   797,
     797,   797,   798,   799,   800,   801,   802,   800,   803,   800,
     804,   805,   804,   806,   804,   807,   807,   808,   809,   809,
     809,   810,   810,   810,   810,   810,   810,   811,   811,   812,
     812,   813,   814,   813,   815,   815,   816,   816,   816,   816,
     816,   818,   817,   819,   819,   820,   821,   822,   822,   824,
     825,   823,   827,   826,   826,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   830,   829,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   832,   832,   833,
     833,   834,   834,   835,   835,   835,   835,   835,   836,   837,
     837,   838,   838,   839,   839,   840,   840,   841,   841,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   843,   843,   844,   844,   846,
     845,   847,   847,   847,   848,   848,   849,   849,   851,   850,
     852,   852,   853,   853,   855,   854,   856,   856,   857,   858,
     858,   860,   859,   861,   862,   862,   862,   862,   863,   864,
     863,   865,   865,   866,   866,   867,   867,   867,   867,   868,
     868,   868,   868,   869,   869,   870,   870,   871,   871,   872,
     872,   873,   873,   875,   874,   876,   876,   878,   877,   879,
     879,   880,   880,   880,   880,   880,   882,   881,   883,   884,
     884,   885,   886,   888,   887,   889,   889,   890,   890,   891,
     891,   893,   892,   894,   894,   894,   894,   894,   894,   894,
     895,   896,   895,   897,   898,   898,   898,   898,   898,   899,
     899,   900,   900,   901,   901,   902,   902,   903,   903,   904,
     904,   904,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,   904,   904,   905,   905,   907,   906,   908,
     908,   908,   908,   908,   909,   909,   911,   910,   912,   914,
     913,   915,   916,   916,   917,   917,   917,   918,   918,   919,
     919,   920,   921,   922,   922,   923,   923,   924,   924,   924,
     924,   925,   925,   926,   926,   928,   927,   929,   929,   929,
     929,   929,   929,   929,   930,   930,   932,   931,   933,   935,
     934,   936,   938,   937,   939,   940,   940,   941,   943,   942,
     944,   944,   944,   945,   945,   947,   946,   948,   949,   949,
     950,   950,   950,   951,   951,   952,   952,   953,   954,   954,
     954,   954,   954,   954,   954,   955,   955,   957,   956,   958,
     958,   960,   959,   961,   962,   962,   962,   963,   963,   963,
     963,   965,   964,   966,   967,   968,   968,   969,   969,   969,
     969,   969,   969,   970,   970,   971,   971,   972,   972,   972,
     972,   972,   973,   974,   974,   975,   975,   977,   976,   979,
     978,   980,   980,   982,   981,   983,   983,   984,   984,   986,
     985,   987,   987,   988,   988,   988,   988,   989,   989,   990,
     990,   990,   990,   992,   991,   993,   994,   993,   993,   995,
     995,   996,   996,   997,   997,   998,   998,   998,   998,   998,
     999,   999,  1000,  1000,  1001,  1001,  1002,  1004,  1003,  1005,
    1006,  1006,  1007,  1007,  1007,  1007,  1007,  1007,  1007,  1008,
    1008,  1009,  1009,  1010,  1010,  1011,  1013,  1012,  1014,  1015,
    1017,  1016,  1018,  1019,  1019,  1021,  1020,  1022,  1023,  1023,
    1023,  1024,  1024,  1025,  1027,  1026,  1028,  1028,  1029,  1029,
    1030,  1030,  1031,  1031,  1032,  1033,  1033,  1035,  1034,  1036,
    1036,  1036,  1036,  1036,  1036,  1037,  1037,  1038,  1038,  1039,
    1040,  1041,  1041,  1042,  1042,  1042,  1042,  1042,  1042,  1042,
    1042,  1043,  1043,  1044,  1045,  1045,  1046,  1047,  1047,  1048,
    1048,  1050,  1049,  1052,  1051,  1053,  1053,  1054,  1054,  1055,
    1055,  1056,  1056,  1057,  1057,  1057,  1058,  1058,  1058,  1060,
    1059,  1061,  1062,  1062,  1063,  1063,  1063,  1063,  1064,  1064,
    1064,  1064,  1064,  1064,  1065,  1066,  1066,  1067,  1067,  1069,
    1068,  1068,  1070,  1070,  1070,  1070,  1071,  1071,  1072,  1072,
    1072,  1072,  1074,  1073,  1075,  1076,  1076,  1077,  1077,  1077,
    1078,  1078,  1079,  1079,  1081,  1080,  1082,  1082,  1082,  1083,
    1083,  1084,  1085,  1085,  1087,  1086,  1088,  1088,  1090,  1089,
    1091,  1093,  1092,  1094,  1095,  1095,  1095,  1097,  1096,  1098,
    1099,  1099,  1100,  1100,  1101,  1102,  1102,  1103,  1104,  1104,
    1105,  1105,  1106,  1106,  1107,  1107,  1109,  1108,  1110,  1110,
    1110,  1110,  1110,  1111,  1112,  1112,  1113,  1113,  1113,  1113,
    1113,  1114,  1115,  1115,  1116,  1116,  1116,  1117,  1117,  1117,
    1117,  1118,  1119,  1119,  1120,  1121,  1122,  1122,  1124,  1123,
    1125,  1126,  1126,  1127,  1127,  1127,  1127,  1128,  1128,  1129,
    1129,  1130,  1130,  1131,  1132,  1132,  1133,  1133,  1134,  1135,
    1135,  1136,  1136,  1137,  1138,  1138,  1139,  1139,  1140,  1141,
    1141,  1142,  1142,  1143,  1143,  1144,  1144,  1144,  1145,  1146,
    1147,  1147,  1147,  1148,  1149,  1150,  1151,  1151,  1152,  1152,
    1153,  1153,  1154,  1155,  1157,  1156,  1158,  1158,  1158,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1160,  1160,  1161,  1161,  1162,  1162,  1163,
    1164,  1165,  1165,  1166,  1166,  1166,  1167,  1167,  1167,  1168,
    1168,  1168,  1169,  1169,  1170,  1170,  1170,  1171,  1171,  1172,
    1172,  1172,  1172,  1172,  1172,  1173,  1173,  1174,  1175,  1176,
    1177,  1177,  1178,  1179,  1180,  1180,  1181,  1182,  1182,  1183,
    1184,  1184,  1184,  1185,  1186,  1186,  1187,  1188,  1189,  1189,
    1190,  1191,  1191,  1192,  1193,  1194,  1194,  1195,  1195,  1195,
    1196,  1196,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,
    1197,  1197,  1198,  1198,  1199,  1199,  1199,  1200,  1200,  1200,
    1200,  1200,  1200,  1200,  1201,  1201,  1202,  1202,  1203,  1203,
    1204,  1204,  1205,  1205,  1206,  1206,  1206,  1207,  1207,  1207,
    1208,  1208,  1209,  1209,  1210,  1210,  1210,  1211,  1212,  1213,
    1213,  1214,  1215,  1215,  1215,  1215,  1216,  1217,  1217,  1217,
    1217,  1218,  1218,  1219,  1220,  1220,  1221,  1222,  1223,  1224,
    1224,  1224,  1224,  1224,  1224,  1224,  1225,  1225,  1226,  1226,
    1227,  1227,  1227,  1227,  1227,  1227,  1227,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1229,  1229,  1230,
    1230,  1230,  1231,  1231,  1231,  1232,  1232,  1232,  1233,  1233,
    1233,  1234,  1234,  1234,  1235,  1235,  1236,  1236,  1237,  1238,
    1238,  1239,  1239,  1240,  1240,  1241,  1241,  1242,  1242,  1243,
    1243,  1243,  1244,  1244,  1245,  1245,  1245,  1246,  1246,  1247,
    1247,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1249,
    1249,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1250,
    1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,
    1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,  1259,  1260,
    1260,  1261,  1261,  1262,  1262,  1263,  1263,  1264,  1264,  1265,
    1265,  1266,  1266,  1267,  1267,  1268,  1268,  1268,  1269,  1269,
    1270,  1270,  1271,  1271,  1272,  1272,  1273,  1273,  1273,  1274,
    1274,  1275,  1275,  1275,  1276,  1276,  1276,  1277,  1277,  1277,
    1278,  1278,  1279,  1279,  1280,  1280,  1281,  1281,  1281,  1282,
    1282,  1283,  1283,  1284,  1284,  1284,  1284,  1285,  1285,  1286,
    1286,  1287,  1287,  1288,  1288,  1289,  1289,  1290,  1290,  1291,
    1291,  1292,  1292,  1292,  1293,  1293,  1294,  1294,  1295,  1295,
    1296,  1296,  1297,  1297,  1298,  1298,  1299,  1299,  1300,  1300,
    1300,  1301,  1301,  1302,  1302,  1303,  1303,  1304,  1304,  1305,
    1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,  1310,
    1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,  1315,
    1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,  1319,  1320,
    1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324,
    1325,  1325,  1326,  1326,  1327,  1327,  1328,  1328
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
       1,     3,     3,     6,     0,     2,     7,     8,     0,     2,
       0,     2,     0,     3,     0,     3,     0,     1,     1,     0,
       5,     1,     1,     0,     3,     1,     2,     1,     2,     2,
       3,     1,     0,     5,     1,     2,     1,     3,     0,     4,
       2,     4,     2,     2,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     2,     0,     6,     0,     2,     2,
       2,     3,     1,     1,     2,     2,     1,     2,     4,     1,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     3,
       4,     4,     4,     3,     0,     2,     0,     5,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       1,     2,     1,     1,     0,     2,     2,     0,     2,     4,
       4,     0,     3,     1,     1,     3,     6,     2,     3,     2,
       2,     3,     2,     1,     2,     2,     1,     1,     1,     2,
       2,     1,     4,     2,     3,     0,     0,     5,     0,     1,
       2,     3,     1,     0,     4,     3,     0,     2,     2,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     5,     5,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     0,     1,     1,     0,
       1,     1,     3,     2,     0,     0,     0,     9,     0,     4,
       0,     0,     3,     0,     3,     1,     2,     4,     0,     2,
       2,     0,     3,     3,     4,     4,     3,     0,     1,     0,
       2,     0,     0,     7,     0,     2,     1,     1,     2,     1,
       1,     0,     6,     0,     2,     2,     1,     0,     1,     0,
       0,     3,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     4,     6,     3,
       3,     4,     3,     4,     3,     3,     4,     4,     3,     4,
       3,     4,     5,     3,     4,     3,     3,     1,     1,     1,
       2,     0,     1,     3,     3,     2,     2,     2,     3,     3,
       3,     0,     1,     0,     3,     0,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     3,     3,     3,     3,     1,     1,     0,     1,     0,
       4,     4,     5,     6,     0,     2,     0,     1,     0,     3,
       3,     4,     0,     2,     0,     3,     1,     2,     4,     0,
       2,     0,     4,     6,     0,     1,     1,     1,     0,     0,
       3,     1,     2,     2,     3,     0,     2,     2,     2,     0,
       3,     2,     4,     1,     1,     1,     1,     0,     2,     0,
       2,     0,     1,     0,     3,     1,     2,     0,     3,     2,
       3,     0,     1,     3,     3,     2,     0,     4,     4,     0,
       1,     1,     1,     0,     4,     3,     2,     1,     2,     0,
       1,     0,     4,     3,     3,     3,     3,     4,     2,     4,
       1,     0,     3,     5,     0,     2,     2,     2,     2,     0,
       2,     1,     1,     0,     2,     0,     1,     1,     2,     1,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     0,     1,     0,     4,     4,
       6,     6,     8,     8,     0,     1,     0,     3,     2,     0,
       4,     2,     1,     3,     1,     1,     1,     2,     1,     1,
       2,     2,     3,     2,     3,     1,     3,     2,     1,     1,
       1,     0,     2,     0,     1,     0,     3,     0,     2,     1,
       2,     1,     1,     1,     0,     2,     0,     3,     1,     0,
       3,     1,     0,     3,     3,     0,     3,     2,     0,     6,
       3,     2,     1,     0,     1,     0,     3,     5,     0,     2,
       0,     3,     3,     0,     2,     1,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     0,     3,     1,
       2,     0,     3,     2,     1,     1,     1,     2,     1,     1,
       1,     0,     3,     2,     5,     1,     2,     2,     2,     1,
       1,     1,     2,     1,     2,     4,     2,     0,     1,     1,
       1,     1,     4,     0,     2,     3,     3,     0,     3,     0,
       3,     3,     4,     0,     4,     4,     6,     0,     1,     0,
       3,     4,     5,     1,     1,     1,     1,     0,     3,     0,
       3,     2,     1,     0,     3,     2,     0,     4,     2,     0,
       1,     1,     1,     1,     3,     0,     2,     1,     3,     3,
       0,     3,     1,     1,     1,     3,     7,     0,     4,     7,
       0,     2,     0,     2,     2,     3,     3,     3,     2,     0,
       3,     1,     1,     0,     1,     1,     0,     3,     2,     1,
       0,     4,     4,     0,     1,     0,     4,     4,     0,     2,
       3,     0,     1,     1,     0,     4,     4,     6,     0,     2,
       0,     2,     1,     2,     3,     0,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     3,     4,     1,     2,     3,     1,     2,     3,
       3,     0,     3,     0,     7,     0,     5,     0,     2,     0,
       2,     0,     3,     0,     2,     4,     0,     2,     4,     0,
       4,     4,     0,     3,     0,     4,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     1,     0,     1,     0,
       4,     2,     0,     2,     4,     4,     0,     1,     1,     1,
       1,     1,     0,     4,     5,     1,     2,     1,     3,     3,
       0,     4,     0,     1,     0,     4,     4,     6,     6,     0,
       1,     2,     0,     1,     0,     3,     1,     2,     0,     3,
       5,     0,     3,     2,     0,     1,     1,     0,     4,     6,
       0,     3,     1,     3,     2,     2,     2,     3,     0,     3,
       0,     3,     0,     3,     0,     1,     0,     3,     1,     1,
       1,     1,     1,     7,     0,     1,     1,     1,     1,     1,
       1,     4,     1,     2,     1,     2,     3,     0,     1,     2,
       1,     3,     1,     1,     4,     1,     1,     1,     0,     4,
       5,     0,     2,     0,     4,     3,     3,     1,     1,     1,
       1,     0,     1,     2,     0,     2,     0,     2,     2,     0,
       2,     0,     2,     2,     0,     2,     0,     2,     2,     0,
       2,     0,     2,     2,     1,     2,     1,     1,     2,     2,
       2,     1,     1,     2,     2,     2,     0,     2,     0,     2,
       0,     2,     1,     1,     0,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     2,     2,     1,     3,     1,     1,
       3,     1,     3,     1,     3,     1,     2,     2,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     3,     1,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     2,     2,     2,     4,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     2,     1,     1,     3,     2,     2,
       1,     1,     3,     3,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       5,     4,     5,     5,     5,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     5,     0,     3,
       2,     1,     3,     3,     1,     3,     1,     3,     0,     0,
       1,     0,     1,     0,     1,     0,     2,     0,     2,     0,
       1,     1,     0,     1,     0,     1,     2,     0,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     2,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     1,     0,
       1,     0,     1,     1,     0,     1,     1,     0,     2,     2,
       0,     1,     0,     1,     0,     1,     0,     1,     1,     0,
       1,     0,     1,     0,     2,     1,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     2,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       1,     0,     1,     0,     3,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     2
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
    1774,    46,     0,     0,     0,  1817,  1774,  1774,  1774,     0,
       0,     0,     0,     0,  1774,     0,     0,  1749,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1775,     0,     0,  1503,   125,  1774,
    1774,  1818,  1774,     0,     0,     0,     0,  1774,  1774,    60,
      82,     0,    54,    98,  1750,     0,  1774,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1811,    39,  1774,     0,     0,     0,  1571,   169,  1496,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1504,
     150,   151,  1776,   154,  1576,  1196,  1195,   116,   120,  1803,
    1774,     0,   100,   149,   176,   177,    38,  1812,    36,     0,
    1583,  1579,  1584,  1582,  1580,  1585,  1581,   158,   159,   161,
     170,   165,  1859,  1860,     0,   163,     0,  1748,     0,     0,
       0,  1774,  1881,    80,    61,  1747,    66,    68,    69,    70,
      71,  1747,     0,  1774,     0,    83,     0,    87,    55,    58,
     152,  1778,  1777,   155,     0,  1803,  1806,  1805,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1846,   164,     0,  1572,   168,  1880,  1774,
       0,     0,    65,    67,    63,    81,  1747,  1774,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1577,
     153,   156,     0,  1804,   123,   118,   119,   122,   178,     0,
       0,  1645,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1879,    74,    64,     0,
    1497,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1646,   181,  1755,   266,   267,   268,  1737,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1756,  1830,  1738,  1759,
       0,   278,   259,   138,   139,  1867,  1868,    72,  1813,  1831,
    1751,  1760,     0,     0,     0,   280,     0,  1792,  1813,  1838,
       0,   239,     0,  1774,  1747,  1779,   241,     0,  1848,  1845,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1743,  1774,  1752,     0,  1482,   264,  1480,   277,     0,    25,
     140,  1793,  1774,  1814,  1779,  1839,  1840,   210,  1847,   242,
    1813,  1774,  1774,  1780,  1774,  1774,   251,  1737,   252,     0,
    1774,  1792,  1744,     0,     0,   270,   271,   274,  1481,   279,
     286,   287,   338,   281,   341,     0,     0,  1774,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1807,  1807,
       0,   253,     0,  1774,   240,   223,   272,     0,   273,     0,
     494,   282,  1628,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1502,  1501,   243,   244,   245,   246,   249,  1808,   254,   255,
     256,   224,     0,   275,     0,     0,   497,   343,     0,     0,
     347,     0,   285,   288,  1631,   216,   201,   217,   202,  1755,
     203,   200,   213,   199,   214,  1774,     0,   233,   232,   233,
     229,   339,     0,     0,   500,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1774,  1878,     0,   222,  1632,   209,
       0,   247,  1494,     0,   231,   230,   341,   495,     0,     0,
     595,   345,   350,   387,   356,  1751,  1774,     0,     0,  1774,
    1751,  1792,  1774,  1735,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1877,   248,
    1495,     0,   236,   340,   341,   498,     0,     0,    26,  1774,
    1739,     0,     0,     0,  1774,  1735,     0,     0,     0,     0,
       0,  1774,   334,  1736,   335,     0,   333,   336,   290,   291,
       0,   496,   341,   501,     0,   658,     0,   481,   411,  1819,
    1819,  1819,  1819,  1819,  1841,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1815,   446,     0,   422,   408,   423,   424,     0,
       0,  1822,   426,   427,   425,  1781,   429,   430,   428,  1774,
    1776,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1740,     0,   384,     0,   357,   312,   332,  1869,  1870,
    1500,   321,  1498,  1862,  1861,   314,  1790,  1749,  1763,     0,
    1774,   318,   317,  1774,   337,     0,  1865,  1866,   234,   499,
     503,   596,     0,    27,   702,   492,   493,  1820,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1842,     0,
    1816,   478,   464,   458,   403,  1565,   490,  1823,  1782,  1783,
     479,     0,     0,   405,   407,  1659,  1659,   386,     0,  1799,
    1594,     0,     0,  1590,  1595,  1593,  1591,  1596,  1592,   385,
     358,  1586,  1588,     0,   302,  1499,  1791,   323,     0,   305,
    1764,  1824,   331,     0,     0,   235,   502,   598,   660,     0,
       0,   480,  1763,   460,     0,  1834,     0,  1563,  1564,     0,
     410,   482,   484,   486,     0,   404,  1747,   451,   452,  1587,
    1800,     0,     0,   367,   363,   366,   365,   364,   379,   375,
     377,   378,   380,   376,   381,   382,   383,   360,   371,   372,
     373,   368,   369,   370,   362,   359,     0,   313,   304,   303,
     301,   322,  1749,  1825,   310,   319,   316,   320,   315,     0,
     504,     0,   602,   597,   599,     0,   663,   661,   679,     0,
     756,   829,   838,   844,   851,   883,   887,   901,   896,   902,
     903,   911,   957,   966,   969,   995,  1006,  1009,  1012,  1004,
    1018,  1025,  1047,  1051,  1087,  1089,  1093,     0,  1099,  1113,
    1137,  1155,  1156,  1159,  1160,  1165,  1173,  1174,  1187,  1221,
    1239,     0,  1272,  1284,  1292,  1294,   684,  1298,  1301,  1307,
    1358,   704,   705,   706,   707,   708,   709,   710,   711,   713,
     712,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   703,     0,     0,   458,   459,  1835,   462,  1612,  1607,
    1618,     0,  1469,  1471,     0,     0,     0,  1610,     0,  1473,
    1611,  1613,  1614,     0,     0,     0,     0,  1609,  1618,  1608,
    1453,  1451,  1458,  1461,  1463,  1466,  1530,  1468,  1527,  1561,
    1528,  1529,  1615,     0,     0,     0,  1562,   491,   488,   485,
       0,   406,  1660,   361,   374,  1589,     0,     0,   324,   325,
     326,   327,     0,   306,  1762,   312,     0,  1483,   505,     0,
     603,     0,   600,   668,   668,     0,     0,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,
    1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1661,  1707,  1708,  1709,  1710,   755,     0,     0,
       0,     0,   854,     0,     0,     0,     0,     0,     0,     0,
    1414,   997,     0,     0,  1836,   874,   873,     0,  1017,  1414,
       0,     0,     0,     0,     0,     0,   754,     0,  1125,     0,
       0,     0,     0,     0,     0,     0,     0,  1268,  1271,  1259,
    1269,  1270,  1261,     0,     0,  1293,  1291,     0,   702,     0,
       0,     0,     0,   465,   461,   466,  1801,   469,     0,  1605,
    1531,  1532,  1533,     0,     0,     0,     0,     0,     0,     0,
    1465,     0,  1464,     0,  1606,  1454,  1455,  1573,     0,     0,
       0,     0,     0,     0,     0,     0,  1597,     0,     0,     0,
       0,   483,     0,   487,   330,   329,  1741,  1749,   311,     0,
     605,   606,   601,  1746,   668,   665,   671,     0,   668,   680,
     655,   778,   827,   781,   777,  1799,     0,     0,  1521,   836,
    1515,   834,  1510,  1512,  1513,  1514,   839,     0,  1633,  1493,
     845,   846,     0,  1489,  1491,  1490,   857,   855,   856,   881,
       0,  1543,   884,   885,  1542,   888,   891,  1799,   899,     0,
    1475,  1647,  1507,  1566,  1570,  1508,     0,   909,  1813,  1590,
     955,  1379,   920,   924,  1510,     0,  1512,   964,     0,   858,
     967,   976,   975,   993,     0,   972,   974,  1413,     0,   999,
    1003,  1001,  1004,  1002,   996,  1007,  1008,  1505,  1010,  1011,
    1837,  1013,  1487,  1005,  1832,  1412,  1026,  1028,  1048,  1049,
    1052,     0,  1054,  1055,  1056,  1088,  1225,  1558,  1559,     0,
    1090,     0,  1097,     0,  1106,  1103,  1105,  1104,  1100,  1107,
    1127,  1493,  1114,  1125,  1116,     0,  1123,     0,  1544,  1490,
    1546,     0,  1153,  1639,  1157,  1361,  1478,  1163,  1813,  1171,
    1361,     0,  1185,  1178,  1479,     0,  1486,  1188,  1189,  1190,
    1191,  1192,  1193,  1214,  1194,  1217,     0,  1484,     0,     0,
    1557,  1570,  1222,  1257,  1244,  1262,  1745,  1282,     0,  1275,
    1277,     0,  1289,     0,  1295,  1296,   690,   696,   685,   686,
     687,   689,     0,  1299,     0,  1302,  1304,  1324,  1310,  1371,
    1361,   467,   469,  1802,     0,   473,   468,  1620,  1453,  1451,
    1470,  1472,  1453,     0,     0,     0,  1453,  1524,  1525,  1526,
       0,  1474,  1467,  1453,     0,  1452,  1574,     0,  1457,  1456,
    1460,  1459,  1462,     0,     0,  1453,     0,  1774,  1742,     0,
     308,     0,  1774,  1821,   666,  1774,     0,   677,   669,   670,
     681,   828,   757,  1742,   791,   782,     0,     0,     0,     0,
    1516,  1517,  1518,   837,   830,     0,     0,  1511,  1635,  1634,
     842,   847,   849,     0,   882,   852,  1545,   858,   886,   891,
    1871,  1872,   889,     0,   892,     0,   900,   897,  1854,  1853,
    1476,     0,  1649,  1477,  1568,  1569,   906,   907,   910,   904,
    1406,   956,   912,   699,     0,   918,  1381,     0,   935,     0,
     929,  1379,  1379,  1379,  1379,   965,   958,     0,     0,   859,
     968,   994,   970,  1414,  1414,   971,   978,   979,   699,  1438,
    1439,  1440,  1434,  1836,  1426,  1446,  1449,  1448,  1450,  1442,
    1433,  1432,  1437,  1436,  1435,  1441,  1421,  1425,  1443,  1445,
    1447,  1423,  1424,  1420,  1422,  1415,  1416,  1427,  1428,  1429,
    1430,  1431,  1419,  1000,   998,  1506,  1015,  1833,   699,  1030,
       0,  1050,     0,  1077,  1061,  1053,  1058,  1059,  1060,  1229,
       0,  1560,     0,     0,  1098,  1094,     0,  1107,  1845,     0,
    1115,  1121,  1122,   699,  1118,  1414,     0,     0,  1126,     0,
    1154,  1138,  1640,  1641,  1813,     0,  1158,  1164,  1161,  1140,
    1172,  1166,  1168,  1180,  1186,  1175,     0,  1180,     0,  1538,
    1539,  1215,  1218,     0,     0,  1485,  1198,     0,  1197,     0,
       0,  1568,  1258,  1240,  1246,  1774,  1247,  1242,     0,  1260,
       0,     0,  1283,  1273,     0,  1276,     0,  1290,  1285,     0,
    1297,   697,   695,   688,     0,  1305,  1306,  1303,  1325,  1308,
    1745,     0,  1372,  1359,  1363,   473,   463,  1745,   456,   471,
     472,  1779,  1619,     0,  1615,  1615,  1615,     0,  1601,     0,
    1615,  1575,     0,  1615,  1615,  1844,     0,   328,  1801,   307,
     509,  1774,  1774,  1735,  1787,   534,   508,   512,   513,     0,
    1757,   620,  1774,   610,  1841,   611,  1850,  1849,     0,  1774,
       0,   623,   614,   619,  1794,   615,     0,   618,   625,   622,
     616,   621,     0,   626,   617,     0,   637,   631,   635,   634,
     632,   636,   607,   638,   633,     0,  1794,     0,  1774,   678,
       0,     0,   656,   787,   792,   793,  1794,  1794,   785,   786,
    1794,   773,  1374,  1852,  1851,   770,   762,   764,   765,     0,
    1374,     0,     0,     0,   779,   768,     0,   776,   759,   775,
     760,  1535,  1534,     0,  1520,     0,  1799,  1384,   835,  1570,
    1508,     0,  1637,   842,     0,   840,     0,     0,  1492,   869,
     890,   895,     0,     0,  1509,  1384,  1774,  1648,  1567,   908,
     699,   905,  1408,  1380,   700,   922,  1741,   699,  1378,   928,
     927,   926,   925,   936,  1379,  1774,   939,     0,   942,   943,
       0,  1774,   946,   947,   948,   949,     0,   950,  1379,   937,
       0,   793,   915,   916,   913,   914,     0,  1384,     0,   865,
     973,   988,   990,   989,   983,   985,   991,  1414,   980,   977,
    1414,   981,  1444,  1417,  1418,  1801,  1014,  1488,   699,  1022,
    1023,  1836,  1038,  1039,  1041,  1043,  1044,  1040,  1042,  1033,
    1836,  1029,     0,  1078,     0,  1080,  1079,  1081,  1063,  1073,
       0,     0,  1057,  1231,     0,  1765,     0,  1091,  1384,     0,
       0,     0,  1109,  1119,  1132,  1128,  1133,  1129,  1134,     0,
    1124,  1368,  1367,  1131,  1140,  1362,  1554,  1555,  1556,     0,
       0,  1406,     0,   699,     0,  1179,     0,     0,     0,  1216,
       0,  1220,  1219,  1212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1200,  1201,  1642,  1406,     0,  1263,  1828,
    1828,  1278,  1279,  1280,     0,  1384,     0,     0,   698,     0,
    1629,     0,  1280,  1168,  1731,   457,     0,  1774,  1627,  1602,
    1603,  1604,  1625,  1622,  1623,  1600,  1616,     0,  1598,  1599,
     489,     0,     0,  1896,  1897,  1774,  1735,     0,   506,   510,
    1758,   514,     0,     0,   608,   609,   612,   613,     0,   640,
    1795,  1774,  1834,  1774,   641,   639,   653,  1774,   672,   673,
     676,     0,   667,   682,   684,  1774,   795,     0,     0,   783,
     784,     0,   699,   774,  1376,   761,   763,  1374,   771,   766,
     767,   780,   769,  1537,  1519,  1536,  1647,     0,   699,   831,
    1386,  1568,  1569,  1384,     0,  1636,   841,   843,   850,   848,
     877,  1772,   894,   893,   898,     0,  1407,   699,  1405,   702,
    1382,   917,     0,   940,   941,   944,   945,     0,  1410,  1410,
     938,   919,   931,   932,   930,   933,     0,   959,     0,   860,
     861,   671,     0,  1414,  1414,   987,   699,   984,     0,  1021,
     699,  1024,  1019,     0,     0,  1045,     0,     0,     0,  1074,
    1076,     0,  1069,  1083,  1070,  1071,  1062,  1065,  1083,  1223,
    1774,  1779,     0,  1766,  1230,  1092,  1095,     0,  1109,  1108,
    1112,  1101,     0,  1120,  1117,     0,     0,  1142,  1141,   699,
    1162,  1394,  1167,  1169,     0,  1181,  1414,  1414,  1176,  1182,
    1199,  1211,  1213,  1203,  1204,  1205,  1209,  1206,  1210,  1207,
    1208,  1202,  1643,  1256,     0,  1253,  1254,  1248,     0,  1241,
    1876,  1875,     0,  1829,  1266,  1266,  1389,     0,  1647,  1286,
       0,   691,     0,  1630,  1311,  1312,     0,  1315,  1318,  1322,
    1316,  1406,  1732,     0,   477,   474,   475,     0,  1617,   309,
     511,  1788,  1789,  1578,   522,   519,   352,   535,   515,   516,
    1549,   630,  1547,  1548,   629,   646,   652,     0,   649,   674,
     675,   684,   702,     0,     0,  1374,   788,   790,   789,  1375,
     699,  1373,   772,  1384,  1509,  1385,   699,  1383,  1567,   832,
    1638,  1540,  1541,  1857,  1858,   879,   699,  1799,  1773,   876,
     875,   871,     0,  1651,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,  1650,  1409,     0,   952,   951,   954,     0,  1552,  1553,
     953,     0,   923,  1384,  1475,  1384,  1475,   862,   863,     0,
     867,   866,   868,   986,   992,   982,  1016,  1020,  1031,  1034,
    1035,  1753,  1027,  1836,  1032,  1083,  1083,     0,  1068,  1066,
    1067,  1072,  1233,     0,  1227,  1767,  1384,  1102,  1111,     0,
    1135,     0,     0,  1149,     0,  1398,   699,  1393,  1170,   699,
     699,  1183,  1255,  1245,  1249,  1250,  1251,  1252,  1243,  1264,
    1267,  1265,   699,  1274,  1391,  1774,  1384,  1384,   693,  1300,
    1629,  1314,  1763,  1320,  1763,  1389,   699,   699,  1360,  1370,
    1401,  1402,  1369,  1366,  1365,  1784,   476,   470,   518,  1863,
    1864,   521,   354,   536,   517,   644,   642,   645,   643,   647,
     648,     0,   624,   650,   651,     0,   702,   794,   799,  1774,
     801,   802,   803,   826,  1774,   804,   805,   806,   807,   808,
       0,   809,   810,   812,   813,   814,     0,   815,   800,  1733,
     816,   825,   819,   796,   797,   818,   758,  1377,   833,  1387,
     699,   853,   878,     0,   870,  1873,  1874,  1411,   934,   961,
       0,   960,     0,   864,  1036,  1754,     0,     0,  1064,  1075,
    1083,  1770,  1770,  1084,     0,     0,  1236,  1232,  1226,  1096,
    1110,     0,  1143,  1774,  1406,     0,     0,  1144,     0,  1148,
    1399,  1177,  1184,  1390,   699,  1388,     0,  1288,  1287,  1326,
     692,     0,  1313,     0,  1763,  1317,     0,  1309,  1403,  1404,
    1400,  1785,  1786,  1364,     0,  1774,  1774,     0,   523,   524,
     525,   526,   527,   528,     0,   538,   627,   628,     0,     0,
       0,   817,  1774,  1410,  1410,  1734,     0,   798,   880,   872,
    1384,  1384,     0,  1046,  1082,  1771,     0,     0,  1774,  1234,
       0,     0,  1224,  1228,     0,     0,  1139,  1152,  1396,  1397,
    1151,  1147,  1145,  1146,  1392,  1281,  1334,   694,  1319,     0,
    1323,  1883,  1882,  1774,     0,     0,  1885,     0,  1774,  1774,
     520,  1821,     0,   821,   820,     0,   823,   822,   824,  1550,
    1551,   963,   962,  1037,  1086,  1085,     0,  1237,  1774,  1414,
    1150,  1395,  1357,  1356,  1335,  1327,  1328,  1733,  1329,  1330,
    1331,  1332,  1355,     0,     0,  1321,     0,   533,   529,  1884,
       0,     0,  1768,  1796,  1735,     0,     0,     0,  1774,  1799,
     537,  1774,  1774,     0,   543,   545,   554,   546,   548,   551,
     539,   540,   541,   550,   552,   555,   542,     0,   547,     0,
     549,   553,   544,  1796,  1735,   683,   811,  1235,     0,  1136,
       0,  1826,     0,  1801,   530,   532,   531,  1769,   593,  1797,
    1798,  1776,   579,  1774,   458,  1414,     0,     0,     0,     0,
       0,   587,     0,   577,   583,   586,     0,   580,   588,   591,
    1776,   582,  1238,     0,  1827,     0,  1353,  1352,  1351,     0,
     578,     0,  1834,   575,  1647,   571,  1522,  1887,     0,     0,
    1889,  1891,     0,  1895,  1893,   556,   560,   564,   564,   558,
     562,   557,   563,   594,     0,   585,   584,   590,   589,   581,
    1354,  1856,  1855,  1809,  1347,  1341,  1342,  1344,   569,   462,
     592,  1801,   570,  1523,  1886,  1890,  1888,  1894,  1892,   567,
     559,   567,   561,     0,  1810,  1801,  1350,  1345,  1348,     0,
    1343,   454,     0,     0,   566,   565,     0,     0,  1349,  1346,
       0,   453,   574,   572,   573,   568,   576,  1340,  1337,  1339,
    1338,  1333,  1336,   455
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
     434,   503,   435,   534,   566,   567,   830,   568,  1679,  1015,
     764,   569,   570,   703,   836,   571,   572,   831,  1008,  1009,
    1010,  1011,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   759,   817,
     818,   819,   820,   821,   500,   683,   589,   661,   662,   663,
     795,   664,   665,   666,   667,   668,   669,   670,  2566,  2701,
     671,   785,   954,  1157,   783,  1392,  1395,  1396,  1661,  1658,
    2165,  2166,   672,   673,   674,   675,   676,   998,   791,   792,
    1191,   677,   678,   496,   584,   524,   612,   550,   710,   776,
     840,  1199,  1432,  1686,  1687,  1971,  2178,  1688,  2174,  2328,
    2448,  2449,  2450,  2451,  2452,  2453,  1968,  2177,  2455,  2511,
    2570,  2571,  2645,  2680,  2694,  2572,  2573,  2672,  2703,  2574,
    2575,  2576,  2577,  2578,  2579,  2613,  2614,  2617,  2618,  2580,
    2581,  2582,   588,   777,   843,   844,   845,  1201,  1433,  1722,
    2339,  2340,  2341,  2345,  1723,  1724,   713,  1440,  1994,   714,
     848,  1024,  1023,  1204,  1205,  1206,  1437,  1730,  1026,  1732,
    2191,  1148,  1378,  1379,  2308,  2430,  1380,  1381,  1937,  1793,
    1794,  2039,  1382,   780,   901,   902,  1098,  1212,  1213,  1758,
    1444,  1500,  1738,  1739,  1735,  1996,  2195,  2373,  2374,  2375,
    1442,   903,  1099,  1219,  1456,  1454,   904,  1100,  1226,  1775,
     905,  1101,  1230,  1231,  1777,   906,  1102,  1239,  1240,  1510,
    1829,  2059,  2060,  2061,  2030,  1117,  2221,  2215,  2381,  1465,
     907,  1103,  1242,   908,  1104,  1245,  1472,   909,  1105,  1248,
    1477,   910,   911,   912,  1106,  1257,  1486,  1489,   913,  1107,
    1260,  1261,  1494,  1262,  1498,  1821,  2054,  2242,  1804,  1818,
    1819,  1492,   914,  1108,  1267,  1506,   915,  1109,  1270,   916,
    1110,  1273,  1274,  1275,  1515,  1516,  1517,  1839,  1518,  1834,
    1835,  2065,  1512,   917,  1111,  1284,  1118,   918,  1112,  1285,
     919,  1113,  1288,   920,  1114,  1291,  1846,   921,   922,  1119,
    1850,  2072,   923,  1120,  1296,  1559,  1859,  2075,  2259,  2260,
    2261,  2262,   924,  1121,  1298,   925,  1122,  1300,  1301,  1565,
    1566,  1871,  1567,  1568,  2086,  2087,  1868,  1869,  1870,  2080,
    2268,  2403,   926,  1123,   927,  1124,  1310,   928,  1125,  1312,
    1575,   929,  1127,  1318,  1319,  1579,  2101,   930,  1128,  1322,
    1583,  2104,  1584,  1323,  1324,  1325,  1885,  1887,  1888,   931,
    1129,  1332,  1900,  2283,  2414,  2486,  1591,   932,   933,  1130,
    1334,   934,   935,  1131,  1337,  1598,   936,  1132,  1339,  1901,
    1601,   937,   938,  1133,  1342,  1607,  1904,  2118,  2119,  1605,
     939,  1134,  1347,   159,  1619,  1348,  1349,  1923,  1924,  1350,
    1351,  1352,  1353,  1354,  1355,   940,  1135,  1305,  2272,  1569,
    2408,  1873,  2089,  2406,  2482,   941,  1136,  1363,  1926,  1627,
    2134,  2135,  2136,  1623,   942,  1365,  1629,  2299,  1142,   943,
    1143,  1367,  1368,  1369,  2146,  1633,   944,  1144,  1372,  1638,
     945,  1146,   946,  1147,  1374,   947,  1149,  1383,   948,  1150,
    1385,  1647,   949,  1151,  1387,  1651,  2154,  2155,  1942,  2157,
    2313,  2435,  2315,  1649,  2431,  2496,  2535,  2536,  2537,  2711,
    2538,  2665,  2666,  2689,  2539,  2628,  2540,  2541,  2542,   950,
    1152,  1389,  1596,  1943,  1893,  2318,  1653,  2003,  2004,  2201,
    1495,  1496,  1798,  2019,  2020,  2207,  2303,  2304,  2425,  2110,
    2487,  2111,  2287,  2319,  2320,  2321,  1791,  1792,  2038,  2236,
    1294,  1295,  1277,  1278,  1545,  1546,  1547,  1548,  1549,  1550,
    1551,   980,  1178,  1399,   982,   983,   984,   985,  1220,  1249,
    1480,  1335,  1343,   395,   396,  1018,  1356,  1357,  1556,  1326,
    1233,  1234,   541,   481,   301,   691,   692,   482,    98,   153,
    1286,  1251,  1221,  1457,  2635,  1406,   987,  1763,  2014,  2088,
    2210,  1243,  1327,  2181,  2518,  2237,  1895,  2182,  1306,  1360,
    1223,   989,  1252,  1253,   735,   787,   788,  2183,   271,  2615,
     179,  1224,   761,   762,  1225,   992,   993,   994,  1186,  1159,
    1414,  1410,  1403,   501,  2156,   537,  1460,  1773,  2025,  1594,
    2138,   282,  1483,  1787,  2231,   797,  1097,  2163,  2466,   604,
     339,   684,  1446,   423,  1207,   202,   115,   393,  2396,   337,
    1972,   352,  1016,   771,  2094,  2598,  2476,  2222,    96,   214,
     414,   740,  2443,  1967,   767,   402,  1981,  2601,   801,  1394,
     218,   488,  2685,   168,   390,   731,   102,   719,   680,   834,
    2625,  2144,   350,  1558,   957,  1292,   407,   729,  1192,  1331,
     391,  1740,  1760,  1481,  2663,  2216,   184,   695,  2331,   708,
     347,   596,  1474,  2387,  2142,   538,   203,  2503,  2509,  2648,
    2649,  2650,  2651,  2652,  1690
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2302
static const yytype_int16 yypact[] =
{
   -2302,   280,   684, -2302,   250,   276, -2302,   684, -2302, -2302,
     657, -2302, -2302,   657,   657,   -24,   -24, -2302,   675, -2302,
     732,   544,   771, -2302, -2302,   954,   954,   535,   606, -2302,
   -2302,    -9,   657,   -24, -2302, -2302,   785,   681, -2302, -2302,
     812,  2035,   -24, -2302, -2302, -2302,   544,   846, -2302, -2302,
    -118, -2302,   828,   828,   978,   972,  1173,  1173,  1173,  1046,
     828,  1044,  1023,  1036,  1173,  1065,  1096,  1410, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302,   782, -2302, -2302, -2302, -2302,
    1286, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
    1312,  1099,    -9, -2302, -2302,  1124,   226, -2302, -2302,  1173,
    1173, -2302,  1173,  1016,  1511,  1016,  1134,  1173,  1173, -2302,
   -2302,  1016, -2302, -2302, -2302,  1088,  1052,  1165, -2302, -2302,
    1119, -2302,  1176, -2302, -2302, -2302, -2302,  -155, -2302, -2302,
   -2302,  1287, -2302,  1173,  1146,  1016,  1379,    -2, -2302, -2302,
   -2302, -2302, -2302,  1382,  1170,  1017,  1448, -2302,  1148, -2302,
    1088, -2302,    84, -2302, -2302, -2302, -2302, -2302,  1090,   434,
    1173,   -10, -2302, -2302, -2302,   -30, -2302, -2302, -2302,   179,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1146, -2302,  1216,
   -2302,  -166, -2302, -2302,  1016, -2302,  1264, -2302,  1271,  1255,
    1613,  1173, -2302, -2302, -2302,   724, -2302, -2302, -2302, -2302,
   -2302,   423,  1624,  1173,    96, -2302,    66, -2302, -2302,   121,
   -2302, -2302, -2302, -2302,  1434,   434, -2302,  1459,   828,   828,
   -2302,  1090,  1242,   102,   -65, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,   428, -2302,
     162, -2302,  1146, -2302, -2302,  1370, -2302, -2302, -2302,  1173,
    1300,  1451, -2302, -2302, -2302, -2302,  1244,  1173,  1199,  1480,
     -40, -2302,  1688,   672,  1262, -2302, -2302,  1263,  1610, -2302,
    1434, -2302,   828, -2302, -2302, -2302, -2302,  1090, -2302,  1266,
    1412, -2302,   828, -2302,   880, -2302,    88, -2302, -2302, -2302,
   -2302, -2302,   428, -2302,  1470,  1451, -2302, -2302, -2302,   709,
   -2302, -2302, -2302,  1471, -2302, -2302, -2302, -2302, -2302,  1457,
   -2302, -2302, -2302, -2302, -2302,  1275, -2302, -2302, -2302,  1706,
    1631,  1284, -2302, -2302,   428, -2302, -2302,    25, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1297, -2302,  1549,
    1616,  1285, -2302,  1723, -2302, -2302, -2302, -2302,  2315, -2302,
    1655, -2302,  1237,  1291,  1351, -2302,   428,  1474,  1396,  -209,
    1347, -2302,  1348,  1173,  1693,   230,   -67,   -15, -2302,  1249,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1332,
   -2302,  1494, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
    1719,  1173, -2302,  1237, -2302,  1237, -2302, -2302,  1306,   -34,
   -2302, -2302,  1173, -2302,  1522, -2302, -2302,  1087, -2302, -2302,
     980,  1173,  1173, -2302,  1173,  1173, -2302,  1706, -2302,   416,
    1173,  1474, -2302,  1358,  1256,  1237, -2302,  1431, -2302, -2302,
   -2302, -2302,  1268, -2302,  1272,    63,    46,  1173, -2302, -2302,
    1072, -2302, -2302,   144,  1359,  1016,  1016, -2302,  1464,  1464,
    1473, -2302,  1016,  1173, -2302, -2302, -2302,  1451, -2302,  1390,
    1526, -2302, -2302,  1337, -2302, -2302, -2302, -2302, -2302,  1016,
   -2302, -2302,   390,   390,  1784,   390, -2302, -2302,   390,   401,
   -2302, -2302, -2302, -2302, -2302,   929, -2302, -2302, -2302, -2302,
   -2302, -2302,   601, -2302,  1339,  1398,  1538,   622,  1343,  6012,
   -2302,  1292, -2302, -2302,     7, -2302, -2302, -2302, -2302,  1275,
   -2302, -2302, -2302, -2302, -2302,  1173,  1016,  1295, -2302,  1295,
   -2302, -2302,  1344,  1406,  1436, -2302,  1353, -2302,  1354, -2302,
    1718, -2302,  1722, -2302,   994, -2302,  1685, -2302, -2302, -2302,
    1016,  1016, -2302,   502, -2302, -2302,  1272, -2302,  1360,  1416,
    1422, -2302, -2302, -2302,  1162,  1655,  1173,  1120,  1120,  1173,
      17,  1474,  1173,  1792, -2302,  1508, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,   828,   715, -2302,  1016,
   -2302,  1506, -2302, -2302,  1272, -2302,  1364,  1423, -2302,  6321,
     768,  1614,  1451,  1314,  1173,  1792,  1315,   566,   144,  1451,
    1321,  1173, -2302, -2302, -2302,     0,   828, -2302, -2302, -2302,
     811, -2302,  1272, -2302,  1371,   818,   -18, -2302, -2302,  -186,
    -185,   420,   696,   697,  1320, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,  1440, -2302,   665, -2302, -2302, -2302, -2302,  1016,
    1016,  1593, -2302, -2302, -2302,   533, -2302, -2302, -2302,  1173,
     170, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1082,
     -97, -2302,  1322, -2302,  1270, -2302,  1385, -2302, -2302, -2302,
   -2302,  1315, -2302, -2302, -2302, -2302,  1579,    51,  1617,  1334,
    1173, -2302, -2302,  1173, -2302,  1214, -2302, -2302, -2302, -2302,
   -2302, -2302,  1715, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1329,
   -2302, -2302,  1789,  1397, -2302,  1383,  1404, -2302, -2302, -2302,
   -2302,  6783,  1071,  1820, -2302,  1449,  1449, -2302,  1290,  1542,
   -2302,   789,   789, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302,  1403, -2302,  1451,   255, -2302, -2302, -2302,  1451, -2302,
   -2302,  1442, -2302,   406,   406, -2302,  1502,  1349,    24,  3289,
    3773, -2302,  1617,  1657,  1451,  1409,  6893,  1393, -2302,  1016,
   -2302,  1071, -2302,  1415,  1603, -2302,  1693, -2302, -2302, -2302,
   -2302,   789,  1408, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,  1290, -2302, -2302, -2302,
   -2302,   134,  1410, -2302,    28, -2302, -2302, -2302, -2302,  1357,
   -2302,  5829, -2302, -2302,  1349,  1411, -2302, -2302,  1488,  4127,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,   -66,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1466, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302,   590, -2302, -2302,  1530, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,  1362,  1451,  1397, -2302, -2302,  1754, -2302, -2302,
    1413,  4081,    -2,    -2,  1414,  1417,  1418, -2302,  1419,    -2,
   -2302, -2302, -2302,  3607,  6893,  3607,  1421, -2302,  1413, -2302,
      36,   979,   860, -2302,  1702, -2302, -2302, -2302, -2302, -2302,
    1403, -2302,  1424,  1426,  1427,  6893, -2302, -2302,  -201, -2302,
    1071, -2302, -2302, -2302, -2302, -2302,   144,   144, -2302, -2302,
   -2302, -2302,  1691, -2302, -2302,  1385,  1451, -2302, -2302,  1420,
   -2302,  1433, -2302,    98,    98,  1381,  1439, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  -139,  2451,
    6893,   430,   660,   481,  1237,   649,   713,  5347,  5425,  1619,
    -195,   855,   649,  1016,  1441, -2302, -2302,  5425, -2302, -2302,
     649,  1357,  1570,  1016,  4597,  5425, -2302,   896,  2661,  1237,
    1016,  1237,  1016,    68,   389,  1016,  1237, -2302, -2302, -2302,
   -2302, -2302, -2302,  4624,  4866, -2302, -2302,  1357,    85,  1016,
    1237,  1016,  1016, -2302, -2302,  1669,  1586, -2302,  5920, -2302,
   -2302,  1403, -2302,  1391,  1399,  6893,  6893,  6893,  4081,  1401,
   -2302,  1042, -2302,  4081, -2302, -2302, -2302, -2302,  6893,  6637,
    6893,  6893,  6893,  6893,  6893,  6893, -2302,  4081,  6893,   979,
    1495, -2302,  1447, -2302, -2302, -2302,  1873,  1410, -2302,   185,
   -2302, -2302, -2302, -2302,    22, -2302,  -191,   479,    30, -2302,
   -2302, -2302,  1773,   825,  1709,  1542,  1016,  4081, -2302,  1776,
   -2302,  4945, -2302, -2302, -2302, -2302, -2302,   160,   687, -2302,
     430, -2302,  1461, -2302,    -2, -2302, -2302, -2302, -2302,  1780,
    1175, -2302,   481, -2302, -2302,  1237,  1019,  1542,  1781,   583,
   -2302,  1527, -2302, -2302,  1383,  1403,  1237,  1783,  1396,  1103,
    1785,  4974, -2302,  5072,   111,  1122,  1133,  1779,   686,  1428,
   -2302, -2302, -2302,  1786,    48, -2302, -2302, -2302,  4481, -2302,
   -2302,  1817,   -66, -2302, -2302, -2302,   649, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302,  1482, -2302, -2302,   272,  1357, -2302,
   -2302,    31, -2302, -2302, -2302, -2302, -2302, -2302,  1462,  5425,
   -2302,  1475,  1787,  1880, -2302, -2302, -2302, -2302,   896,  1525,
   -2302,  1484, -2302,  3397,     6,  -237,  1489,  1487, -2302,  1013,
   -2302,  1499,  1799,   865, -2302,  1739, -2302,  1804,  1396,  1806,
    1739,  1016,  1803,  1455, -2302,  1144, -2302, -2302, -2302, -2302,
   -2302, -2302,  1682, -2302,   649, -2302,   424, -2302,   298,  1926,
   -2302,    53, -2302,  1810,  1033,   549,  1911,  1813,  1955, -2302,
   -2302,  1016,  1815,  5216,  1357, -2302, -2302,   618, -2302, -2302,
   -2302, -2302,  3531, -2302,  1770, -2302,  1232,  1818,  1855,  1819,
    1739, -2302, -2302, -2302,  1016,  1749,   175, -2302,    58,  1015,
   -2302, -2302,   363,  1523,  1524,  1528,   243, -2302,  1403, -2302,
    1529, -2302, -2302,   249,  1532,  1015, -2302,  1069,   860,   860,
   -2302, -2302, -2302,  1066,  1533,   266,  1536,  1173, -2302,   144,
    1857,  1535,   711,  6527, -2302,  1173,  1565,  1667, -2302, -2302,
    1881, -2302, -2302,  1144,  1797, -2302,   682,  2220,   -16,  1548,
   -2302,  1403, -2302, -2302, -2302,  5485,  1793, -2302,  1766, -2302,
    1621, -2302,  1661,  1745, -2302, -2302, -2302,  1428, -2302,  1019,
   -2302, -2302, -2302,   989,    41,  1016, -2302, -2302, -2302, -2302,
   -2302,  6893,  1730, -2302,  1393, -2302,  1237, -2302, -2302, -2302,
    1772, -2302, -2302, -2302,  5425, -2302,  1710,   148,  1707,  1543,
    1521,  1842,  1842,  1842,  1842, -2302, -2302,  5425,  5485, -2302,
   -2302, -2302, -2302,  -195,    61, -2302,  1507, -2302,  1509, -2302,
   -2302, -2302, -2302,  1441, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302,  4214, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,    -4, -2302,  1882,   944,
    1833, -2302,  1144,   116, -2302, -2302,  1647, -2302, -2302,    73,
    6893, -2302,  1567,   649, -2302, -2302,  5485,  1525,  1249,  1237,
   -2302, -2302, -2302, -2302, -2302,  1847,  1016,   430, -2302,  1151,
   -2302, -2302, -2302, -2302,  1396,  1570, -2302, -2302, -2302,  1788,
   -2302, -2302,   511,  1889, -2302, -2302,  1016,  1889,  1572, -2302,
    1403, -2302, -2302,   611,  1090, -2302, -2302,  1197, -2302,  1972,
     733,   113, -2302, -2302, -2302,  1173, -2302,   445,  5425, -2302,
      11,  5294, -2302, -2302,  1016, -2302,  1825, -2302, -2302,  5485,
   -2302,  1451, -2302, -2302,  1144, -2302, -2302, -2302, -2302, -2302,
    1911,  1794, -2302, -2302,  1151,  1749, -2302,  1911, -2302, -2302,
   -2302,  1522, -2302,  1016,  1424,  1424,  1424,  4081, -2302,   438,
    1424, -2302,  6784,  1424,  1424, -2302,  1071, -2302,  1586, -2302,
   -2302,  1173,  1173,  1792,   786, -2302, -2302, -2302, -2302,  1821,
    1848, -2302,  1173, -2302,   377, -2302, -2302, -2302,  1456,  1173,
    1175, -2302, -2302, -2302,  1724, -2302,  1451, -2302,  1970, -2302,
   -2302, -2302,  1016, -2302, -2302,  1016, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302,  1823,  1724,   172,  1173, -2302,
    1537,  1576, -2302, -2302, -2302,  1757,  1724,  1724,   317,  1778,
    1724, -2302,  1868, -2302, -2302, -2302,  1534,  1531, -2302,  1144,
    1868,  1798,  1615,  1748, -2302, -2302,  1774, -2302, -2302, -2302,
   -2302, -2302, -2302,   483, -2302,  1016,  1542,   725, -2302,   -43,
     -17,   649,  1601,  1621,   649, -2302,  1602,   430, -2302,   -66,
   -2302, -2302,  1671,  1690, -2302,   737,  1173, -2302, -2302, -2302,
   -2302, -2302,  1758, -2302, -2302, -2302,  2026, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302,  1842,  1173, -2302,   644, -2302, -2302,
    1492,  1173, -2302, -2302, -2302, -2302,   137, -2302,   977, -2302,
    1340,  1757, -2302, -2302, -2302, -2302,  1853,   725,  1854,   103,
   -2302, -2302, -2302, -2302,  2044, -2302,  1625,    70, -2302, -2302,
      61, -2302, -2302, -2302, -2302,  1586, -2302, -2302, -2302,  1934,
    1930,  1441, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1700,
    1441, -2302,  1623, -2302,  2023, -2302, -2302, -2302,  1283, -2302,
    1144,   953, -2302,    72,   175,    -7,   649,   649,   725,  1869,
    1237,   416,   720,  1936, -2302, -2302, -2302,  2071, -2302,  1883,
   -2302, -2302, -2302, -2302,  1788, -2302, -2302, -2302, -2302,  1016,
    1951,  1772,  1108, -2302,  1580, -2302,  1582,  1144,   727, -2302,
     483, -2302, -2302, -2302,  5425,  1090,  1090,  1090,  1090,  1090,
    1090,  1090,  1090,   733, -2302,    56,  1772,   570, -2302,  1665,
    1665, -2302, -2302,   441,  1016,   725,  1886,  1638, -2302,  1644,
    2084,  1016,   437,   511,  2089, -2302,  1591,  1173, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1078, -2302, -2302,
   -2302,  1016,   481, -2302, -2302,  1173,  1792,  1841,  1349, -2302,
   -2302, -2302,  1016,  -141, -2302, -2302, -2302, -2302,  -141, -2302,
   -2302,  1173,  1409,  1173, -2302, -2302, -2302,  1173, -2302, -2302,
   -2302,   632, -2302, -2302, -2302,  1173,  1594,  -141,  -141, -2302,
   -2302,  -141, -2302, -2302,  1805, -2302, -2302,  1868, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,  1527,   -16, -2302, -2302,
    1808,   -36,  1897,   725,   919, -2302, -2302, -2302, -2302, -2302,
      15,    80, -2302, -2302, -2302,   780, -2302, -2302, -2302, -2302,
   -2302, -2302,  -141, -2302, -2302, -2302, -2302,  -141,   497,   497,
   -2302, -2302, -2302, -2302, -2302,  1604,   649, -2302,   649,  1070,
   -2302,   512,   105,    61, -2302, -2302, -2302,  2044,  1016, -2302,
   -2302, -2302, -2302,  1607,   939,   240,  1608,   919,  1144, -2302,
   -2302,  2062, -2302, -2302, -2302, -2302,   953, -2302,  1923, -2302,
    1173,  1522,  1811, -2302, -2302,   649, -2302,   649,   720, -2302,
   -2302, -2302,  1121, -2302, -2302,  1016,  5425,   676, -2302, -2302,
   -2302,  1822, -2302, -2302,  1850, -2302, -2302, -2302, -2302,  1582,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,   -37, -2302,  1016, -2302, -2302, -2302,  1055, -2302,
   -2302, -2302,  6893, -2302,  5425,  5425,  1660,  1796,  1527, -2302,
     649, -2302,   919, -2302,  1814, -2302,  1144, -2302,  2015,  1692,
   -2302,   836, -2302,   587, -2302,  1591, -2302,  1016, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302,  1402,   -64, -2302,  1016, -2302,
   -2302, -2302, -2302, -2302, -2302,   779, -2302,   481,   779, -2302,
   -2302, -2302,   131,  2086,  3201,  1868, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,  1725,  1927, -2302, -2302, -2302,  1935, -2302,
   -2302, -2302, -2302, -2302, -2302,  1843, -2302,  1542, -2302, -2302,
   -2302, -2302,  1016, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,  2844, -2302, -2302, -2302,  1425, -2302, -2302,
   -2302,  1543, -2302,   725,  1790,   725,  1800, -2302, -2302,  5425,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,   939,
   -2302,  2038, -2302,  1441, -2302, -2302, -2302,   919,  1273, -2302,
   -2302,  1273,   -46,  1016, -2302, -2302,   725, -2302, -2302,  1762,
   -2302,  2096,  1885,  1912,   -11, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1015, -2302,
   -2302, -2302, -2302, -2302,  1852,  1173,  1725,   725,  1662, -2302,
    2084, -2302,  1617,  2055,  1617,  1660, -2302, -2302, -2302, -2302,
    1861, -2302, -2302, -2302, -2302,  1430, -2302,  1016,  1267, -2302,
   -2302,  1841, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302,  -141, -2302, -2302, -2302,  -141,   -12, -2302, -2302,  1173,
   -2302, -2302, -2302, -2302,  1173, -2302, -2302, -2302, -2302, -2302,
      -3, -2302, -2302,  2098, -2302, -2302,   139, -2302, -2302,  2150,
   -2302, -2302, -2302,  3201, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,  1016, -2302, -2302, -2302, -2302,  1543, -2302,
     649, -2302,   649, -2302, -2302, -2302,  2110,  2049,  1273,  1273,
   -2302,  1703,  1703, -2302,  1826,  1237,   596, -2302,  1016, -2302,
   -2302,  5425, -2302,  1173,   629,  1900,  1902, -2302,  1903, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,  1016, -2302, -2302, -2302,
   -2302,  1714, -2302,  1016,  1617, -2302,  1016, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302,  1007,  1173,  1173,  1001, -2302, -2302,
   -2302, -2302, -2302, -2302,  1622, -2302, -2302, -2302,  2059,  -141,
    -141, -2302,  1173,   497,   497, -2302,   499, -2302, -2302, -2302,
    1725,  1725,  5425, -2302,  1273, -2302,  5425,  5425,  1173,  1237,
    1237,  1834, -2302, -2302,  1695,  1016, -2302, -2302,  1822, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,   129, -2302, -2302,  1016,
   -2302, -2302, -2302,  1173,  1841,  1841, -2302,  1960,  1173,  1173,
   -2302,  2364,  1721, -2302, -2302,   481, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,   430,  1237,  1173, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1335, -2302, -2302,
   -2302, -2302, -2302,  1835,  2072, -2302,  1841, -2302, -2302, -2302,
    1841,  1841,  1959,  1298,  1792,  1975,  1451,  1679,  1173,  1542,
   -2302,  1173,  1173,  1016, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,     8, -2302,   740,
   -2302, -2302, -2302,  1298,  1792, -2302, -2302, -2302,   430, -2302,
    1824,  1767,   206,  1586, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302,   170, -2302,  1173,  1397, -2302,  7072,  7072,  1517,  2067,
    1991, -2302,  1451,     8, -2302, -2302,  1451,   740, -2302, -2302,
     170, -2302, -2302,  1016, -2302,  1226, -2302, -2302, -2302,    64,
   -2302,     8,  1409, -2302,  1527,  6993, -2302, -2302,   974,  1180,
   -2302, -2302,  1201, -2302, -2302, -2302, -2302,   -42,   -42, -2302,
   -2302, -2302, -2302, -2302,  7072, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,  1851,   897,    64, -2302, -2302, -2302,  1754,
   -2302,  1586, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  1876,
   -2302,  1876, -2302,  2142, -2302,  1586, -2302, -2302,  1888,  1016,
   -2302,  1771,   -35,  1871, -2302, -2302,  7072,   648, -2302, -2302,
    1451, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,  1237, -2302
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2302, -2302, -2302, -2302, -2302,  2189, -2302, -2302, -2302,   205,
   -2302,  2152, -2302,  2107, -2302, -2302,  1453, -2302, -2302, -2302,
    1544, -2302, -2302,  1400,  2176, -2302, -2302,  2076, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  2004,
     643, -2302, -2302, -2302, -2302, -2302,  2058, -2302, -2302, -2302,
   -2302,  2002, -2302, -2302, -2302, -2302, -2302, -2302,  2135, -2302,
   -2302, -2302, -2302,  1990, -2302, -2302, -2302, -2302,  1979, -2302,
   -2302,  1041, -2302, -2302, -2302, -2302,  2063, -2302, -2302, -2302,
   -2302,  2041, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302,  1031, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302,  1704, -2302,  1809, -2302, -2302, -2302,
    1752, -2302, -2302, -2302, -2302,   344, -2302, -2302,  1940, -2302,
   -2302, -2302, -2302, -2302,  1807, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
    1213, -2302, -2302, -2302,  1465, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,  -284,
   -2302, -2302,  1732, -2302,  -747,  -823, -2302, -2302, -2302,   472,
   -2302, -2302, -2302, -2302,    10, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -1406,   797,  1490,   538,   563, -1405, -2302, -2302,
   -2302,  -942, -2302,  -436, -2302, -2302,   842, -2302,   361,   585,
   -2302,    76, -1404, -2302, -1398, -2302, -1396, -2302, -2302,  1452,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,  -401,  -433, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -1227, -2302,  -368, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,  1407, -2302, -2302, -2302,
      62,    65, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,  1228,   186, -2302,   193, -2302, -2302, -2302,
   -2302, -1343, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -1118,
   -2302, -2302,  -694, -2302,  1476, -2302, -2302, -2302, -2302, -2302,
   -2302,  1045,   516,   519, -2302,   440, -2302, -2302,  -110,   -96,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,   492,
   -2302, -2302, -2302,  1037, -2302, -2302, -2302, -2302, -2302,   799,
   -2302, -2302,   209, -2302, -2302, -1164, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302,   800, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,   776, -2302, -2302, -2302, -2302, -2302,    32,
   -1774, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302,   758, -2302, -2302,   756, -2302, -2302,   435,
     211, -2302, -2302, -2302, -2302, -2302,   995, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,    20,
     717, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,   714, -2302, -2302,   195, -2302,   415, -2302, -2302,
   -1564, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302,   966,   708,   194, -2302, -2302, -2302,
   -2302, -2302, -2302, -1721,   968, -2302, -2302, -2302,   189, -2302,
   -2302, -2302,   402, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,   352,
   -2302, -2302, -2302, -2302, -2302, -2302,   690,   181, -2302, -2302,
   -2302, -2302, -2302,  -151, -2302, -2302, -2302, -2302,   375, -2302,
   -2302, -2302,   949, -2302,   950, -2302, -2302,  1168, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,   161, -2302, -2302,
   -2302, -2302, -2302,   941,   365, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302,     1, -2302,   368,
   -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,  -353, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302,   -73, -2302,   659, -2302, -2302, -1588, -2302, -2302,
   -1346, -2302, -2302, -1663, -2302, -2302,    -1, -2302, -2302, -2302,
   -2302,   -99, -2206, -2302, -2302,     2, -1838, -2302, -2302, -1959,
   -1545, -1069, -1459, -2302, -2302,   772, -1716,   178,   180,   183,
     190,  -366,   152,  -755,   422,   449, -2302,   723,  -621, -1380,
   -1010,  -894,   982, -1553,  -392,  -335, -2302, -1314, -2302, -1035,
   -1310,   864,  -529,   -90,  2030, -2302,  1639,  -552,    16,  2179,
   -1073, -1042,   154,  -876, -2302, -1074, -1378, -2302,   426, -1283,
   -1326, -1091, -1166, -1848, -2302, -2302, -2302, -1115, -2302,  -326,
     937,  -632, -2302, -2302,  -103, -1194,  -751,  -111,  2065, -1869,
    2090,  -670,  1460,  -537,  -460, -2302, -2302, -2302,    47,  1361,
   -2302, -2302,   331, -2302, -2302, -2302, -2302, -2302, -2302, -2302,
   -2302, -2302, -1960, -2302, -2302,  1592, -2302, -2302,  -196,  -591,
    1925, -2302, -1173, -2302, -1309,  -247,  -629,  1009, -2302,  1836,
   -2302, -1435, -2302,  -773, -2302, -2302,   -56, -2302,    -6,  -654,
    -356, -2302, -2302, -2302, -2302,   425,  -181,  -236, -1193, -1535,
    2134,  1901, -2302, -2302,  -334, -2302, -2302,  1022, -2302, -2302,
   -2302,   421, -2302,   279, -1923, -1474, -2302, -2302, -2302,  -156,
     482, -1395, -1410, -2302, -2302, -2302,  -303, -2302, -2302,  1653,
   -2302,  1801, -2302, -2302, -2302,   793, -2302, -2301,  -244, -2302,
   -2302, -2302, -2302, -2302, -2302
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1846
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   689,   160,   742,   215,   139,   952,
     415,   579,  1155,   138,   760,   141,  1265,   734,  1020,  1359,
     779,   147,  1448,  1429,   404,   245,  1882,  1716,  1718,  1719,
     841,   981,   139,   427,  1874,  1720,   996,  1721,  1726,  1783,
    1886,  1276,  1615,   464,  2050,   180,   696,  1297,   437,  1842,
     103,   104,   105,   268,  1475,  1836,  2203,  1631,   111,  2186,
    1484,  1358,  1608,  2112,   463,  1513,  1232,   264,   769,    99,
    1287,  1203,   793,  2664,  1467,  1767,   107,  1341,  1287,  1203,
     846,   246,  1831,   345, -1559,  -659,  2217,   220,  2139,   321,
    2240,  1831,  1287,   134,   135,  1250,   136,   841,  2175,  1413,
   -1801,   143,   144,   279,   392,   259,   211,  1175,  2353,   114,
     161,  1845,   529,  1424,  1571,    94,   154,   411,  2458,   824,
     824,   793,  2034,  1523,  1562,  1863,   215,   169,  1827,  1175,
    2184,  -657,   535,  1759,    42,  2679,   360,  1761,  1115,   430,
     297,  1443,  2702,  1961, -1560,   745,  2508,  1203,  1581,  2196,
    2197,  1468,  1203,  2198,   219,  1822,  1823,  1824,  1825,  1428,
    1733, -1565,  2008, -1845,  2057,   986, -1779,  1621, -1563,   824,
    1211,   413,   465,  1929,  1864,   700, -1741,   221, -1741,   291,
    2404,  2213,  1006,  1802,   327,   251,  1431, -1586,  2306, -1801,
     -96, -1745,   211,  2250,  2234,  1232,  1878,   258,   535,  2235,
     129,  1628,  1659,  1013,  1988,   222,  2415,   226,  2489,  2137,
     283,   799,  2092,   419,   701,  2096,  1523,   182,  1458,  1171,
    1435,   717,   717,  1222,  -659,  1014,  2416,   715,  -659, -1845,
     351,  1264,  1268,    23,   274,   275,    43, -1759,  1340,   405,
    1189,  1293,   154,   295,  1555,  1799,  1585,  -507,  1311,  1313,
      94,   299,  2417,  1229, -1843,  1555,   418,  2532,  1390,  1935,
    1271,  2048,   583,  2463,  1586,  2173,   204,  1370,  1222, -1814,
    -657,  1272,  2149,   416,  -657,  -507,  -507,  2418,  1247,  1862,
       3,  1613,  2531,  1989,   716, -1761,  -659,  1436,   311,  1005,
     406,  1660,   718,   720,  1865,  2611,  2533,    43,   314,   127,
     611,  1930,  1190,   130,  1247,   183,   227,  2646,  2093,  2218,
    2068,  1116,  1287,   828,  1175,  2325,  1555,   212,   351,    24,
    1175,  1229, -1845,  2322,   284,  1762,   991,  2098,   709,  1160,
    1193,   -96,  -657,     5,  2534,   -35,  2626,  1175,  2612,   243,
     139,  1940,   139,   139,   412,  1227,   493,  2132,  1946,   139,
    2133, -1832,   986,   986,   986,   485,   486,   410,  1866,   431,
    2209,  1939,   491,   283, -1741,   137,   139,   137,   223,   507,
     507,  2180,   507,   746,   986,   507,   514,  2073,  1836,   485,
   -1745,  1836,  1696,  1393,  1697,   424,  2076,  2066, -1745,  2219,
    -507,  2023,   228,   280,   466,  1247,   436,  1563,   128,  -664,
    1841,   480,  1552,   212, -1759,   443,   444,  -662,   445,   446,
    1402,  1402,  1402,   139,   452,   281,  2292,  1538,  -507,  2202,
    1346,   786,  1616,  1415,  1417,   448,   542,  -659,   995,   154,
    1423,   469,   826,  1572,  1175,  1176,   229,   139,   139, -1779,
    1849,  1376,  2332, -1741,  1276,  1250,   230,   492, -1845,   467,
     542,   580,  1303,  2405,  1194,  1195, -1745,  1176,  2041,  1582,
     231, -1745,  2454,  2251,   137,  1883,  2007,   260,   413,  1564,
   -1741,   137,  2051,  -657,   368,  -664,   139,   284,  2214,   986,
     187,   686,  2371,  -662,  1800,   750,  1177,   188,   697,   580,
     137,  2419,  1370,  2456,  1377,   139,    97,  2457,  1250,   768,
    1877,  1162,   137,  1485,  2516,  2517,   702,  -507,  1662,   540,
    1538,   750,   536,   991,   991,   991,  1832,   786, -1774,   265,
    2062,  1847, -1745,   847,  2271,  1832,   232,  1833,   577,   753,
   -1745,  1287,   346,   733,  1979,   991,  1833,   986,  1376,   754,
    2378,   322,  2220,  1345,   986,   986,   986,   736,   591,  1002,
     593,  1514,  1890,   598,   600,   753,   602,   986,   986,   986,
     986,   986,   986,   986,   986,   754,  1250,   986,  1430,   394,
     137,  1555,  2290,  2017,   137,  2021,  2490,   995,   536,  1768,
    2389,   129,  2391,   679,  1376,  1450,  1867,  2081,   688,  1247,
     149,  1377,   607,  1952,   261,   699,   233,  2520, -1745,   234,
     235,  1007,   750, -1745,  1836,  2252,   292,  2376, -1644,   829,
    1485,  2513,  2514,  2409,  2050,  2031,  1499,  1247,  1796,   755,
    1180,  2049,   704,  2464,  2120,  1181,   243,   255,  2627,  1250,
    1974,  1826,  1828, -1814,   517,  2547,  2548,  1377,  -507,   243,
     991,   228,  1176,  2427,  2428,   755,   753,   505,  1176,  1737,
     137,  2192,   827,   741,  1801,  1247,   754,   832,   512,  1163,
    1164,  1346,  1304,   835,  2189,  1176,  1169,   216,  1330,  1552,
     837,   837,  2036,   955,  2670,  1012,  2243,  2594,  2245,  2040,
    1953,  2595,  2596,  1557,   130,   229,   997,  1229, -1832,   756,
   -1845,   236,   189, -1624,   773,   230,  1346,   774,   991, -1621,
    1879,  2398,  2399,    15,   449,   991,   991,   991,  1409,  2669,
    2619, -1845,  1246,  1409,  1258,   756,  1674,  2276,   991,   991,
     991,   991,   991,   991,   991,   991,  1785,  1409,   991,    16,
    2069,  1247,  2027,  1788,   757,  1507,   755,  1333,  1241,  1338,
    2013,  1913,  2029,  1478,  1364, -1527,  1617,  1696,  2619,  1697,
    2062,  2265,  1928,  1115,   154,  1932,  2173,  1452,  1386,  2109,
     757,  1250,  1176,  1936,   190,   581,   450,  1975, -1845,   518,
    2307,  1915, -1845,  1681, -1845,   232,   738,   243,   137,  1916,
    1330,   187,  1618,   117,   758,  2115,  1299,   842,   188,  2397,
     802,   732,  1398,    52,   681,  2266,   750,  1307,    27, -1845,
    2480,  1682,  1683,  2095,   137,  2587,   756,  2521,  2522,  1307,
     758,    18,  1375, -1626,  2223,  2140,  1764,    28,  -654,  2707,
     191,  2248,  1425,  1180,   750,   192,  2309,   717,  1181,   803,
     804,   805,   806,   807,  1287,  1555,  2474,  1438,   253, -1845,
     753,    53,  1154,  1784,   154,   233,   453,  1137,  2346,  2324,
     754,   757,  2479,  1469,   842,  1443, -1845, -1527,   217,  1346,
     986,  1790,   750,  1330,  1487,   626,   627,  2622,   753,   519,
    1788,  2170,  1614,  2311,  2708,   693,   254,  1677,   754,    54,
     728,    55,  2709,    56,  2199,     4,     5,   608,   582,   154,
   -1741,    57, -1741, -1845,  2282,   137,   137,  2043,   722,   253,
    2205,   758,   305,   139,   139,  1198,   753,   137,  1954,  2323,
      33,  1459,   137, -1845,  2481,  1508,   754,  1957,   739,  2232,
     609,  2286,   154,  1435,  1490,  1897,  1116,  2527,   748,   255,
     755,  1463,  1236,  2238,  2238,  1736,   137,  1138,   750, -1845,
     236,  2400,   243,   137,    94,  1917,   243,    58,  2255,   986,
     243,  1852,  2257,  1851,  1853,  1854,  1852,  -654,   755,  1853,
    1854,  -654,  2082,  1561, -1845,   682,  2710,   328,   808,   809,
     810,   811,   812,   813,   814,   639,   640,  1918,  1139,  1439,
      36,  2141,   753, -1845,  2589,   694,   601,   137,    39,   137,
    1436,  2285,   754,   189,  2316,  2254,   755,  2173,  1235,  1919,
     756,    40,  1254,   137,  1599,   137,  1960,  1140, -1845,  1254,
    1289,  2083,  1805,  1641,  1737,  1806,   243,  1254,  2022,  -654,
    1308,   991,  1807,  1808,  2383,  1329,     5,  1336,   756,  1336,
    1344,  1361,  1308,  1684,  2044,  1965,  1966,  1479,  2122,  1640,
      60,   555,    48,   306,  2510,   757,  2244,  2289,  2246,  1336,
    2335,   986,  1920,  1555,   243,  1279,  2506,   556,  2629,  1908,
    2633,  2544,  2224,  2225,  2226,   190,   756,  1314,  1790,  1809,
    2616,  1642,   755,   757,   187,   525,  -865, -1747, -1741,  -865,
     748,   188,  2377,  1237,    61,  1238,   705,  1250,  2379,   137,
    1473,  2507,  1964,   137,  1789,   758,  2342,   557,  2382,  2180,
    2100,  2584,  1141,   717,   717,  2564,  2565,  2567,  2501,  2336,
     991,   757,  1921,  2568,  2501,  2569,  2583,   137,  2502,  1203,
     815,   191,  1315,   758,  2502,  2227,   192,  1235, -1628,  2317,
    1316,  2015,   750,   816,    49,  1898,  2692,  2018,  1810, -1527,
    1250,  1560,   756,  1493,  2712,   329,  1254, -1527, -1527,  2018,
    2697,  1592, -1527,  -865,   394,   137,   712, -1741, -1745,  1891,
    -654,   758,  2674,   706,  1685,   707,   750,  1811,  2420,  1256,
    -865,  2421,  2422,    64,   724,   726,   753,   252, -1845,  1280,
    1281,   243,  1911,  1254,  2423,  2549,   754,   757,  1892,  1812,
     470,   471,   472,  1912,  1254,  2084,  1282,  1180,  2438,  2439,
    1593,   361,  1181,  1215,  2686,   330,   748,  1409,  1922,  1630,
     753,  1624,   991,   438,  1317,   300,    67,  1855,  1856,   394,
     754,  2176,  1855,  1856,   825,   243,   394,    94,  2634,  2636,
    2281,   137,   316,   362,   558,   118,  2687,   758,  1344,  2337,
    1330,  1857,  1858,  1813,  2338,   559,  1857,  1858,  2228,  2229,
    1283,  1254,  1781,  2230,   743,  1254,  2688,  2673,   958,   439,
    1894,  1263,  2468,  1525,  1526,    51,   755,  1602,  2300,  2300,
    2208,  1625,  -865,  1003,  1626,   959,  2683,  1782,  2015,   748,
     958,  2401, -1845,  -865,   750,    94,   189,   744,    68,   822,
     822,   139,  1863,   317,   318,   137,  1814,   959,  1373,    93,
     755,   187,  1527,  1528,  1656,  1947,  2494, -1845,   188,   154,
    2402,   473,  1182,  1473,   823,   823,  -865,  1654,  2706,  2667,
     749,  1183,  -865,  2543,  -865,   474,   139,  -865,   753,  -865,
    -865,  -865,   403,   325,    97,  -865,   756,  -865,   754,   822,
     441,  1864,  -865,  2465,   515,  2233,   560,   561,  2238,  2238,
    1910,  2519,  1769,  2333,  2212,  2667,  1815,   750,   190,   170,
     155,   562,   156,   563,   823,   344,  2607, -1774,  2675,  1816,
     756,  2113,  2590,  2393,  -865,  2172,  1470,   960,   101,  -865,
    2470,   757,  2471,   516,  2278,  2204,  2656,  2298,  2661,  2677,
    1434,  2676,  2662,  -865,  1434,    94,  2114,   400,   155,   960,
     156,   753,   100,   171,  2668,  1769,    94,  2212,   475,  2279,
     750,   754,  2678,   172,   191,   757,    26,  -865,   755,   192,
     476,  1676,  1881,  2085,  2586,   137,  1689,  1725, -1745,  1727,
    1179,   758,  1466,    47,   964,   965,   966,  2052,  2053,  1180,
     967,   106,    91,  1217,  1181,  2444,  1902,   564,  -865,   962,
     108,   963,  1817,  1235,   753,  2445,   964,   965,   966,   137,
   -1565,  1865,   967,  1909,   754,   758,    21,    22,   114,  1218,
    1254,  1927,   594,  1769,   595,  1180,   109,   786,  2446,   968,
    1181,  -865,  2212,   750,  1235,    46,   122,  -865,   756,   110,
     428,   755,  1412,   173,   565,  1471, -1077,  1404,  1405,  -865,
    -865,   968,  1180,   750,   508,   120,   510,  1181,  2447,   511,
    1254,   477,  1539,   189,  1540,   751,   752,  1672,   112,  1671,
     969,   986,   137,   193,   243,  1866,  1180,   753,  2168,  1180,
    1938,  1181,  -865,   757,  1181,  2484,  1769,   754,  1180,  2433,
   -1077,  2436,  -865,  1181,   755,  1987,    13,   753,  -865,   113,
   -1077,    13,   124,   970,  1663,  1997,  1998,   754,  1667,  2001,
     139,   756,  -865,   174,   592,  1669,   706,  -865,   707,   599,
   -1745,  2637,  2506,  1948,  -865,   970,  -865,   126,  1805,   748,
     140,  1806,  -865,   758,  1645,   190,  1646,   142,  1807,  1808,
   -1543, -1543, -1543, -1543,   149,  1982,  2523,  2212,  2599,  2600,
    2524,  2525,  1418,  1419,   971,   972,   757,  2638,   175,  1501,
    1502,  1503,  1504,  1976,   756,  1977,  1990,   755,   162,  1925,
   -1542, -1542, -1542, -1542,  2501,   163,   971,   972,   167,   164,
   -1077,  1420,  1421,  1422,  2502,  1809,   181,   755,  2327,   185,
     186,   191,   721,   723,   725,   727,   192,   976,   204,  2045,
     137,  2046,  1911,   958,   193,  2329,   758,  2330,   176,   757,
     242,  2499,  2632,  1912,  1254,   247,   249,   977,  1254,   976,
     959,  1254,   978,   248,  1235,  1962,  1963,   250,  2385,   979,
    2386,   137,   991,  2441,   257,  2442,  1973,   756,  1743,   977,
    1744,   269,   273,  1978,   978,   278,  1170,   298,  1172,   294,
   -1077,   979,   296,   137,  1810,   300,   428,   756,   154,   758,
     302,  1949,  1950,  1951,   303,   307,   308,  1955,   309,   312,
    1958,  1959,  1991,   988,  1254,   313,  2102,   326,   333,   338,
     334,   336,   757,  1811,   340,  2274,   349,   342,   351,   353,
     356,   354,   392,   394,   397, -1077,   398,   401,   403,   408,
     187,   409,   757,  1867,   243,  1812,   420,   421,   422,   429,
     413,   454,   455,   457,  2123,  2124,  2125,  2126,  2127,  2128,
    2129,  2130,   960,  1254,  1254,  1254,   459,  2147,  -342,   483,
    2035,   487,   758,   750,   490,   494,  2147,  1902,   495, -1077,
     502,   509,   521,   522,   523, -1077,   527,   547,   533,  2042,
     543,   548,   758,   549,  -355,  2047,   551,   552,   554,  1813,
     578,   586,   587,   585,   603,   605,   610,   613,   614,   685,
     687,   690,   698,   728,   711,   730,   737,   753,   747,   964,
     965,   966,  1254,   763,   766,   967,   770,   754,   778,  2639,
     772,   781,   782,  2640,  2641,   784,   794,   786,   789,   800,
     796,   839,   826,   833,   953, -1628,   956,   995,   139,  1000,
    1001,  1004,  1814,  1017,  1022,  1025,  1126,  1145,  1153,  1156,
    1308,  2169,  1184,  1200,   968,  1308,  1269,  1158,  1165,  1196,
    2190,  1166,  1167,  1168,  2642,  1173,  1202,  1209,  1185,  1290,
    1187,  1188,  1210,  1391,  1308,  1308,  1393,  1400,  1308,  1426,
    2643,  2644,  1427,  1428,  1441,  1401,  1447,  1411,  1453,  1462,
     988,   988,   988,  1464,  1482,  1476,  1505,   755,  1488,  1553,
    1254,  1491,  1815,  1573,  1511,  1557,  1570,  1509,  1574,  1576,
    1578, -1545,   988,  1587,  1588,  1816,  1595,  2239,  2239,  1308,
    1589,  2167,  2102,  1590,  1308,  1308,  1308,  2630,   970,  1597,
    1604,  2284,  1600,  1254,  1346,  1254,  1606,  1620,  1622,  2171,
    1203,  1215,  1632,  2602,   748,  1637,  2659,  1644,  1650,  1648,
    1657,  1652,  1678,  1664,  1665,  2185,  1728,  2187,  1666,  1668,
    1729,  2188,  1670,  1673,  1675,   986,   986,   756,  1680,  2193,
    1772,  1731,  1254,  2621,  1254,  1734,  1765,  1771,  1774,   971,
     972,  1776,  1229,  1786,  1790,  1797,  1803,  1820,  1493,  1861,
    1837,  1848,  1840,  1563,   986,  1876,  1884,  1899,  1817,  1903,
    1907,  1914,  1934,  1941,  1980,  1970,  1969,  1983,  1986,  1993,
    1995,  1736,   757,   986,  2002,  1214,  2009,  1228,   958,  2010,
    1244,  2006,   976,  1992,  1266,  2005,    52,  1254,  2011,  2024,
    2028,  2012,  2032,  2033,  2037,   959,  1443,  2056,  2058,  1302,
    1308,  2063,   977,  2070,   139,  1328,  2074,   978,  1366,  2064,
    2071,  2077,  2078,  2097,   979,   986,   137,   542,  2103,  2105,
    2106,  2109,   758,  2116,  2273,  2117,  1384,   428,  1388,  2143,
    2150,  2151,  2152,  2153,    53,   988,  2162,  2164,  2173,  2194,
    2200, -1564,   988,   988,   988,  1407,  2206,  2258,  2264,  2241,
    1407,  2267,  2270,  2288,  2286,   988,   988,   988,   988,   988,
     988,   988,   988,  2302,  1407,   988,  2275,  2305,  2310,  2312,
    2314, -1520,    54,  2347,    55,   428,    56,  2018,  2380, -1562,
    1254,  2395,  1254,  2410,    57,  2411,   991,   991,  2412,  2424,
    2413,  2434,  2390,  1449,  2317,  2462,  2429,   960,  2465,  2472,
    2473,  2475,  2392,  2491,  2478,  2492,  2493,  2497,   750,  2512,
     139,  2549,  2528,  1254,  2585,   991,  2592,  1328,  2529,  1244,
    2593,  2597,  2605,  2407,  1634,  2603,  2624,  2653,  2654,  2684,
    2693,  2696,  2623,  2705,   991,  2698,    17,  2700,    92,   125,
      58,  1217,    38,   166,  1254,   256,   209,   962,   266,   963,
     119,   277,   753,   210,   964,   965,   966,   290,   241,   442,
     967,   504,   754,   545,   139,  2099,   323,  1218,  1197,   526,
    1717,   790,   456,  2691,  1655,  2091,   991,   580,  1308,   838,
    1945,  2326,  1308,   999,  1741,  1742,   990,  2682,  2695,  2658,
    2343,  1021,  1208,  2344,  2249,  2000,   951,  1999,  1445,   968,
    1328,  2055,    59,  2467,  2461,  2026,  1779,  1461,  2247,  1780,
    1795,  1830,  1838,  2388,  2253,  2067,  1860,  1554,   969,  2394,
    1872,  2269,  1609,  2079,  1577,  1880,  1743,  1254,  1744,  1254,
    1745,  1580,  2277,    60,  2280,  2161,  2107,  1906,  2131,  2426,
    2291,  1611,   755,  1362,  1612,  2483,  2301,  2159,  1636,  1635,
    2160,  2432,  2690,  1944,  2437,  2488,  2294,  1844,  2295,   357,
     428,  2296,  2440,  1603,  1746,  1747,  1748,  1778,  2297,   332,
     765,   213,   293,   970,   358,   310,  2121,    61,   798,  1174,
      62,  2591,   447,  2459,   359,   539,  2477,  2620,  2460,   272,
     489,  2145,  2239,  2239,  2263,  2090,  1308,  1308,   775,   597,
    1308,  1308,  1875,  1308,  2647,     0,     0,     0,     0,     0,
       0,     0,   756,     0,  1749,     0,  1750,     0,     0,   360,
    1609,     0,     0,  1751,   971,   972,  1752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,  2485,     0,   624,
       0,     0,     0,     0,     0,     0,     0,   757,   988,     0,
       0,  1161,     0,  1235,     0,     0,    64,   976,     0,  1696,
    1743,  1697,  1744,   990,   990,   990,     0,     0,     0,  2504,
    2505,     0,     0,     0,     0,  2604,     0,   977,     0,     0,
       0,    65,   978,    66,     0,   990,  2515,  1215,     0,   979,
     748,   137,     0,     0,     0,     0,     0,   758,     0,    67,
       0,     0,  2526,  1753,     0,  1754,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1235,     0,     0,     0,     0,
       0,     0,  1346,     0,     0,     0,     0,  2546,     0,  1609,
       0,  2655,  2550,  2551,     0,  2657,     0,   988,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2588,  1889,     0,     0,  1235,     0,     0,     0,
       0,     0,  1896,     0,   958,     0,   361,     0,     0,     0,
       0,    68,     0,  1905,     0,     0,  1216,     0,     0,     0,
       0,   959,  2606,     0,     0,  2608,  2609,     0,     0,     0,
     990,     0,  1235,     0,     0,  1255,     0,     0,   362,     0,
       0,  1933,  1255,     0,  2552,     0,     0,     0,  -228,     0,
    1255,  1609,     0,     0,     0,     0,  2699,     0,     0,  2713,
       0,     0,     0,     0,  1255,     0,     0,  2631,     0,     0,
     642,     0,     0,     0,  1407,     0,     0,     0,     0,   988,
       0,     0,     0,     0,     0,     0,     0,  2553,   990,  2554,
       0,     0,     0,     0,     0,   990,   990,   990,  1408,     0,
       0,   363,     0,  1408,     0,     0,   364,  1328,   990,   990,
     990,   990,   990,   990,   990,   990,     0,  1408,   990,  1984,
    2555,     0,  1985,   960,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   750,  1755,     0,   365,     0,     0,
    2556,     0,     0,     0,     0,   366,     0,  1451,     0,     0,
       0,     0,     0,     0,     0,     0,  1609,     0,   367,     0,
       0,     0,   646,     0,     0,     0,     0,  1217,  2557,     0,
       0,     0,  2016,   962,     0,   963,     0,     0,   753,  1255,
     964,   965,   966,     0,     0,  1756,   967,   368,   754,     0,
     369,     0,     0,  1218,     0,     0,  1757,     0,   370,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -225,
       0,     0,     0,     0,   958,     0,  1255,     0,     0,     0,
       0,     0,     0,     0,     0,   968,     0,  1255,     0,     0,
       0,   959,     0,     0,     0,     0,     0,     0,   371,     0,
     651,   372,     0,     0,   969,     0,     0,     0,     0,  2558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2559,     0,   755,     0,
       0,     0,     0,     0,     0,  1610,     0,  1609,  1609,     0,
       0,     0,     0,     0,  1255,     0,     0,  2560,  1255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,     0,     0,     0,  2108,     0,  2561,     0,
       0,     0,     0,     0,  1609,   849,     0,   850,     0,   851,
       0,     0,  1320,     0,   852,     0,     0,  2562,     0,     0,
       0,     0,   853,   960,   660,  2563,     0,     0,   756,     0,
       0,  2148,     0,     0,     0,     0,     0,     0,  2158,  2158,
     971,   972,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   854,   855,     0,     0,  1244,
       0,     0,     0,  1610,     0,   856,     0,     0,     0,  2179,
       0,     0,     0,   757,     0,  1770,   857,     0,  1321,   858,
     964,   965,   966,   976,     0,     0,   967,     0,     0,     0,
       0,     0,     0,   859,     0,     0,     0,     0,     0,     0,
       0,   990,     0,   977,     0,     0,     0,     0,   978,     0,
       0,     0,     0,     0,     0,   979,   860,   137,     0,     0,
       0,  2211,     0,   758,   861,   968,   862,     0,  1770,     0,
       0,     0,     0,  -701,     0,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,     0,  -701,  -701,  -701,     0,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,   863,     0,     0,
       0,     0,     0,     0,     0,  2256,     0,     0,   864,     0,
       0,     0,     0,   865,  2211,  1609,     0,     0,     0,     0,
       0,     0,  1610,  1609,     0,     0,     0,     0,     0,     0,
     990,     0,     0,  1255,     0,     0,  1770,     0,     0,   970,
     866,     0,  1889,     0,     0,     0,     0,   867,     0,     0,
     868,   869,     0,     0,     0,     0,     0,     0,     0,     0,
     870,     0,     0,     0,     0,     0,     0,   871,     0,   872,
       0,  2293,   873,  1255,     0,     0,     0,     0,     0,   988,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2211,
     971,   972,     0,  1609,     0,     0,     0,     0,     0,  1770,
       0,     0, -1845,     0,  1610,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   874,  2334,     0,     0,   875,     0,
     876,     0,     0,     0,  1244,     0,     0,  1408,     0,     0,
     877,     0,   990,   976,     0,     0,  -701,  -701,     0,  -701,
    -701,  -701,  -701,     0, -1130,     0,     0,     0,     0,     0,
       0,     0,     0,   977,     0,     0,   878,     0,   978,  2384,
       0,     0, -1130,     0,     0,   979,   243,   137,     0,   879,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   880,   881,     0,     0,     0,     0,
       0,     0,     0,     0,  2211,   882,     0,     0,     0,  1610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   883,
     884,     0,     0,     0,     0,     0,   885,  1255,     0,     0,
     886,  1255,     0,  2348,  1255,     0,  2349,     0,   887,  2350,
       0,     0,     0,     0,     0,     0,     0,  2351,   888,     0,
       0,     0,     0,     0,     0,     0,     0,   889,     0,     0,
       0,     0,     0,     0,     0,     0,   890,     0,     0,     0,
       0,   891,   892,     0,     0,   893,     0,   894,     0,     0,
       0,     0,     0,     0,   895,     0,     0,  1255,     0,     0,
     849,     0,   850,  2352,   851,     0,     0,  -701,     0,   852,
       0,     0,     0,     0,     0,     0,     0,   853,     0,     0,
       0,     0,  2353,     0,     0,   897,     0,     0,     0,     0,
    2469,   898,     0,     0,     0,     0,   899,     0,     0,     0,
    1610,  1610,     0,     0,     0,     0,  1255,  1255,  1255,     0,
     854,   855,     0,     0,     0,     0,     0,  -701,     0,     0,
     856,     0,     0,   900,     0,     0,     0,     0,     0,     0,
       0,   857,     0,  2495,   858,     0,     0,  1610,     0,     0,
    2498,     0,     0,  2500,     0,     0,     0,     0,   859,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2354,     0,     0,     0,  1255,     0,     0,     0,     0,
    2355,   860,     0,     0,     0,     0,     0,     0,     0,   861,
       0,   862,     0,  2356,     0,     0,     0,     0,     0,     0,
       0,     0,  2530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2545,     0,     0,     0,
       0,     0,   863,     0,     0,  2357,     0,     0,     0,     0,
       0,     0,  1244,   864,     0,     0,     0,     0,   865,     0,
       0,     0,     0,     0,     0,  2358,     0,  2359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     958,     0,     0,  1255,     0,   866,     0,     0,     0,  2360,
    2361,     0,   867,     0,     0,   868,   869,   959,     0,     0,
    2610,     0,     0,     0,     0,   870,     0,     0,     0,     0,
       0,     0,   871,     0,   872,     0,  1255,   873,  1255,     0,
    2362,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   849,     0,   850,     0,   851,     0,  1610,     0,
       0,   852,     0,   988,   988,     0,  1610,  2363,     0,   853,
       0,     0,     0,     0,     0,  1255,     0,  1255,     0,   874,
    2660,     0,     0,   875,     0,   876,     0,     0,     0,     0,
       0,     0,   988,  2364,     0,   877,     0,     0,     0,     0,
    2365,     0,   854,   855,  2681,  2681,     0,     0,  1320,     0,
       0,   988,   856,  2366,     0,     0,     0,  2367,     0,   960,
       0,   878,   990,   857,     0,     0,   858,     0,     0,     0,
    1255,     0,     0,     0,   879,     0,  1610,     0,     0,     0,
     859,     0,     0,     0,     0,     0,     0,     0,     0,  2704,
       0,     0,     0,   988,     0,     0,     0,     0,  2368,   880,
     881,     0,     0,   860,     0,     0,     0,  2369,     0,     0,
     882,   861,     0,   862,  1466,     0,   964,   965,   966,     0,
       0,     0,   967,     0,   883,   884,     0,     0,     0,     0,
       0,   885,     0,     0,     0,   886,  2370,     0,     0,     0,
       0,     0,     0,   887,   863,     0,  2371,     0,     0,     0,
     958,     0,  2372,   888,     0,   864,     0,     0,     0,     0,
     865,   968,   889,  1255,     0,  1255,     0,   959,     0,     0,
       0,   890,     0,     0,     0,     0,   891,   892,     0,     0,
     893,     0,   894,     0,     0,     0,     0,   866,     0,   895,
       0,     0,     0,     0,   867,     0,  1255,   868,   869,     0,
       0,     0,   896,     0,     0,     0,     0,   870,     0,     0,
       0,     0,     0,     0,   871,     0,   872,     0,     0,   873,
     897,     0,     0,     0,     0,     0,   898,  1255,     0,     0,
       0,   899,     0,     0,   849,   970,   850,     0,   851,     0,
       0,     0,     0,   852,     0,     0,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,     0,     0,   900,     0,
       0,   874,     0,     0,     0,   875,     0,   876,     0,   960,
       0,     0,     0,     0,     0,     0,     0,   877,     0,     0,
     750,     0,     0,     0,   854,   855,   971,   972,     0,     0,
       0,     0,     0,     0,   856,     0,     0,     0, -1845,     0,
       0,     0,     0,   878,     0,   857,     0,     0,   858,     0,
    1255,     0,  1255,   961,     0,     0,   879,     0,     0,   962,
       0,   963,   859,     0,   753,     0,   964,   965,   966,   976,
       0,     0,   967,     0,   754,     0,     0,     0,     0,     0,
   -1130,   880,   881,     0,     0,   860,     0,     0,     0,   977,
       0,     0,   882,   861,   978,   862,     0,     0, -1130,     0,
       0,   979,   243,   137,     0,     0,   883,   884,     0,     0,
       0,   968,     0,   885,     0,     0,     0,   886,     0,     0,
       0,     0,     0,     0,     0,   887,   863,     0,     0,     0,
     969,     0,     0,     0,     0,   888,     0,   864,     0,     0,
       0,     0,   865,     0,   889,     0,     0,     0,     0,     0,
       0,     0,     0,   890,   755,     0,     0,     0,   891,   892,
       0,     0,   893,     0,   894,     0,     0,     0,     0,   866,
       0,   895,     0,     0,     0,     0,   867,     0,     0,   868,
     869,     0,     0,     0,  1643,   970,     0,     0,     0,   870,
       0,     0,     0,     0,     0,     0,   871,     0,   872,     0,
       0,   873,   897,     0,     0,     0,     0,     0,   898,     0,
       0,     0,     0,   899,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   971,   972,     0,     0,
     900,     0,     0,   874,     0,     0,     0,   875,     0,   876,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   877,
       0,     0,     0,     0,     0,     0,   990,   990,     0,   757,
       0,   974,     0,     0,     0,     0,     0,     0,     0,   976,
       0,     0,     0,     0,     0,   878,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   990,     0,     0,   879,   977,
       0,     0,     0,     0,   978,     0,     0,     0,     0,     0,
       0,   979,     0,   137,   990,     0,     0,     0,     0,   758,
       0,     0,     0,   880,   881,     0,     0,     0,     0,     0,
    1027,     0,  1028,     0,   882,     0,     0,  1029,     0,     0,
       0,     0,     0,     0,     0,  1030,     0,     0,   883,   884,
       0,     0,     0,     0,     0,   885,   990,     0,     0,   886,
       0,     0,     0,     0,   958,     0,     0,   887,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   888,  1031,  1032,
       0,   959,     0,     0,     0,     0,   889,     0,  1033,     0,
       0,     0,     0,     0,     0,   890,     0,     0,     0,  1034,
     891,   892,  1035,     0,   893,     0,   894,     0,     0,     0,
       0,     0,     0,   895,     0,     0,  1036,     0,     0,     0,
    1215,     0,     0,   748,     0,     0,  1519,  1520,  1521,     0,
       0,     0,     0,     0,  1522,     0,     0,     0,     0,  1037,
       0,     0,     0,     0,   897,     0,     0,  1038,     0,  1039,
     898,     0,     0,     0,     0,   899,  1040,     0,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,     0,  1049,  1050,  1051,
       0,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,     0,   900,   960,     0,     0,     0,     0,     0,     0,
       0,  1062,     0,     0,   750,     0,  1063,   958,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   959,     0,     0,     0,     0,     0,
       0,     0,     0,  1064,     0,     0,     0,     0,     0,     0,
    1065,     0,     0,  1066,  1067,     0,     0,     0,   753,     0,
     964,   965,   966,  1068,     0,     0,   967,     0,   754,     0,
    1069,     0,  1070,     0,     0,  1071,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1523,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1524,   968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1072,     0,     0,
       0,  1073,     0,  1074,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1075,     0,     0,   960,     0,     0,     0,
       0,     0,  1525,  1526,     0,     0,     0,   750,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1076,
       0,     0,     0,     0,     0,     0,     0,  1843,     0,     0,
       0,     0,  1077,     0,     0,     0,     0,     0,     0,   970,
    1217,  1527,  1528,     0,     0,     0,   962,     0,   963,     0,
       0,   753,     0,   964,   965,   966,     0,  1078,     0,   967,
       0,   754,     0,     0,     0,     0,  1218,  1215,  1079,     0,
     748,     0,     0,  1519,  1520,  1521,     0,     0,   756,  1529,
       0,  1522,     0,  1080,     0,  1530,     0,     0,  1531,  1081,
     971,   972,     0,  1082,     0,     0,  1532,     0,   968,     0,
       0,  1083,     0,  1533,     0,     0,     0,     0,  1534,     0,
       0,  1084,     0,     0,     0,     0,     0,   969,     0,     0,
    1085,     0,     0,   757,     0,     0,     0,  1535,     0,  1086,
       0,     0,     0,   976,  1087,  1088,     0,     0,  1089,     0,
    1090,   755,     0,     0,   958,     0,     0,  1091,     0,     0,
       0,     0,     0,   977,     0,     0,     0,     0,   978,     0,
    1092,   959,     0,     0,     0,   979,     0,   137,     0,     0,
       0,     0,   970,   758,     0,     0,     0,     0,  1093,     0,
       0,     0,     0,  1215,  1094,     0,   748,     0,     0,  1095,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1215,   756,     0,   748,     0,     0,  1096,     0,     0,     0,
       0,  1523,     0,   971,   972,     0,     0,     0,     0,     0,
       0,  1524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1536,     0,  1537,     0,  1538,     0,
       0,  1539,     0,  1540,  1541,  1542,   757,     0,  1543,  1544,
     958,     0,     0,   960,     0,     0,   976,     0,     0,  1525,
    1526,     0,  1309,     0,   750,     0,     0,   959,     0,     0,
       0,     0,     0,     0,     0,     0,   977,   958,     0,     0,
       0,   978,     0,     0,     0,     0,     0,     0,   979,     0,
     137,     0,     0,     0,   959,     0,   758,  1217,  1527,  1528,
       0,     0,     0,   962,     0,   963,     0,  1366,   753,     0,
     964,   965,   966,     0,     0,     0,   967,     0,   754,     0,
       0,     0,     0,  1218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1529,     0,     0,     0,
       0,     0,  1530,     0,     0,  1531,     0,     0,     0,     0,
       0,     0,     0,  1532,     0,   968,     0,     0,     0,     0,
    1533,     0,     0,     0,     0,  1534,     0,     0,     0,   960,
       0,     0,     0,     0,   969,     0,     0,     0,     0,     0,
     750,     0,     0,     0,  1535,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   960,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,   750,     0,     0,
       0,     0,     0,  1217,     0,     0,     0,     0,     0,   962,
       0,   963,     0,     0,   753,     0,   964,   965,   966,   970,
       0,     0,   967,     0,   754,     0,     0,     0,     0,  1218,
    1217,     0,  1215,     0,     0,   748,   962,     0,   963,     0,
       0,   753,     0,   964,   965,   966,     0,     0,     0,   967,
       0,   754,     0,     0,     0,     0,  1218,     0,   756,     0,
       0,   968,     0,     0,     0,     0,     0,     0,     0,     0,
     971,   972,     0,     0,     0,     0,     0,     0,     0,     0,
     969,     0,     0,     0,     0,     0,     0,     0,   968,     0,
       0,  1536,     0,  1537,     0,  1538,     0,     0,  1539,     0,
    1540,  1541,  1542,   757,   755,  1543,  1544,   969,     0,   958,
       0,  1215,     0,   976,   748,     0,     0,     0,     0,     0,
       0,  1371,     0,     0,     0,     0,   959,     0,     0,     0,
       0,   755,     0,   977,     0,   970,     0,     0,   978,     0,
    -921,     0,     0,  -921,     0,   979,     0,   137,     0,     0,
       0,     0,     0,   758,     0,     0,     0,     0,     0,     0,
       0,     0,   970,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   971,   972,   958,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   756,     0,     0,     0,   959,     0,     0,     0,     0,
       0,     0,     0,   971,   972,     0,     0,  -921,     0,   757,
       0,     0,     0,     0,     0,     0,     0,     0,   960,   976,
       0,     0,     0,     0,  -921,     0,     0,     0,  1215,   750,
       0,   748,     0,     0,     0,     0,   757,     0,     0,   977,
       0,     0,     0,     0,   978,     0,   976,     0,     0,     0,
       0,   979,     0,   137,     0,     0,     0,     0,     0,   758,
       0,     0,  1217,     0,     0,     0,   977,     0,   962,     0,
     963,   978,     0,   753,     0,   964,   965,   966,   979,     0,
     137,   967,     0,   754,     0,     0,   758,     0,  1218,     0,
    1493,     0,     0,     0,     0,     0,     0,   960,     0,     0,
       0,     0,     0,     0,     0,   958,     0,     0,   750,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     968,     0,   959,     0,     0,     0,  -921,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -921,     0,   969,
       0,  1217,     0,     0,     0,     0,     0,   962,     0,   963,
       0,     0,   753,     0,   964,   965,   966,     0,     0,     0,
     967,     0,   754,   755,     0,     0,     0,  1218,     0,     0,
    -921,     0,  1215,     0,     0,   748,  -921,     0,  -921,     0,
       0,  -921,     0,  -921,  -921,  -921,     0,     0,     0,  -921,
       0,  -921,     0,     0,   970,     0,  -921,     0,     0,   968,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   969,     0,
       0,     0,     0,     0,   960,     0,     0,     0,  -921,     0,
       0,     0,     0,   756,     0,   750,     0,     0,     0,     0,
       0,     0,   755,     0,     0,   971,   972,  -921,     0,   958,
    1215,     0,     0,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   959,     0,  1217,     0,
       0,  -921,     0,   970,   962,     0,   963,     0,   757,   753,
       0,   964,   965,   966,     0,     0,     0,   967,   976,   754,
       0,     0,     0,     0,  1218,     0,     0,     0,     0,     0,
       0,     0,  -921,  1215,     0,     0,   748,     0,   977,     0,
       0,     0,   756,   978,     0,     0,     0,     0,     0,     0,
     979,     0,   137,     0,   971,   972,   968,   958,   758,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -921,     0,  1455,   959,   969,     0,     0,     0,     0,
       0,     0,     0,  -921,  -921,     0,     0,   757,     0,     0,
       0,     0,     0,  1639,     0,     0,     0,   976,   960,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   750,
     958,  1215,     0,     0,   748,     0,  -921,   977,     0,     0,
       0,     0,   978,     0,     0,     0,  -921,   959,     0,   979,
     970,   137,     0,     0,     0,     0,     0,   758,     0,     0,
       0,     0,  1217,     0,     0,     0,  -921,     0,   962,     0,
     963,  -921,     0,   753,     0,   964,   965,   966,  -921,     0,
    -921,   967,     0,   754,     0,     0,  -921,     0,  1218,   756,
       0,  1766,     0,     0,   748,     0,   960,     0,     0,     0,
       0,   971,   972,     0,     0,     0,     0,   750,   958,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     968,     0,     0,     0,     0,   959,     0,     0,     0,     0,
       0,     0,     0,     0,   757,     0,     0,     0,     0,   969,
    1217,     0,     0,     0,   976,     0,   962,     0,   963,   960,
       0,   753,     0,   964,   965,   966,     0,     0,  1497,   967,
     750,   754,     0,   755,   977,     0,  1218,     0,   958,   978,
       0,     0,     0,     0,     0,     0,   979,     0,   137,     0,
       0,     0,     0,     0,   758,   959,     0,     0,     0,     0,
       0,     0,     0,  1217,   970,     0,     0,     0,   968,   962,
       0,   963,     0,     0,  1259,     0,   964,   965,   966,     0,
       0,     0,   967,     0,   754,     0,     0,   969,     0,  1218,
       0,     0,     0,     0,     0,     0,     0,   960,     0,     0,
       0,     0,     0,   756,     0,     0,     0,     0,   750,     0,
       0,   755,     0,     0,     0,   971,   972,     0,     0,     0,
       0,   968,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     969,  1217,   970,     0,     0,     0,     0,   962,   757,   963,
       0,     0,   753,     0,   964,   965,   966,   960,   976,     0,
     967,     0,   754,     0,   755,     0,     0,  1218,   750,     0,
       0,     0,     0,     0,     0,  1931,     0,     0,   977,     0,
       0,   756,     0,   978,     0,     0,     0,     0,     0,     0,
     979,     0,   137,   971,   972,   970,     0,     0,   758,   968,
       0,  1217,     0,     0,     0,     0,     0,   962,     0,   963,
       0,     0,   753,     0,   964,   965,   966,     0,   969,     0,
     967,     0,   754,     0,     0,     0,   757,  1218,     0,     0,
       0,     0,     0,     0,   756,     0,   976,     0,     0,     0,
       0,     0,   755,     0,     0,     0,   971,   972,     0,     0,
       0,     0,     0,     0,     0,     0,   977,     0,     0,   968,
       0,   978,     0,     0,     0,     0,     0,     0,   979,     0,
     137,     0,     0,   970,     0,     0,   758,     0,   969,   757,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   976,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1019,     0,   755,     0,     0,     0,     0,     0,     0,   977,
       0,     0,   756,     0,   978,     0,     0,     0,     0,     0,
       0,   979,     0,   137,   971,   972,     0,     0,     0,   758,
       0,  -352,     0,   970,  -352,     0,     0,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,  -352,     0,  -352,   976,     0,     0,
       0,     0,   756,  -352,     0,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,     0,     0,   971,   972,     0,   977,     0,     0,
       0,     0,   978,     0,     0,     0,     0,     0,     0,   979,
       0,   137,     0,     0,     0,     0,     0,   758,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   757,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,   976,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   977,     0,     0,
       0,     0,   978,     0,     0,     0,     0,     0,     0,   979,
    -352,   137,     0,     0,     0,     0,     0,   758,     0,     0,
       0,     0,     0,   958,     0,   529,     0,     0,  -352,  -352,
    -352,  -352,  -352,   528,     0,  -352,  -352,     0,     0,  -352,
     959,     0,     0,     0,     0,     0,  -352,     0,  -352,     0,
       0,     0,     0,  -352,  -352,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,     0,     0,     0,     0,  -352,  -352,
       0,  -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,     0,
       0,     0,  -352,     0,     0,  -352,     0,     0,     0,     0,
       0,  -352,     0,  -352,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,  -352,     0,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   960,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,   750,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,  -352,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,   961,     0,     0,     0,
       0,     0,   962,  -352,   963,  -352,     0,   753,     0,   964,
     965,   966,     0,     0,  -352,   967,     0,   754,   529,     0,
       0,  -352,  -352,  -352,  -352,  -352,     0,     0,  -352,  -352,
       0,  -352,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,   968,  -352,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,  -352,     0,  -352,  -352,  -352,
       0,     0,     0,   969,     0,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,     0,   970,  -352,
       0,     0,     0,     0,  -352,     0,     0,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,  -352,  -352,
       0,     0,  -352,     0,     0,   530,     0,   756,     0,     0,
    -352,     0,   616,  -352,     0,     0,     0,     0,     0,   971,
     972,     0,     0,     0,     0,     0,  -352,   617,     0,     0,
     618,   619,   620,   621,   622,   623,   624,     0,  -352,     0,
    1397,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
     973,     0,   757,     0,   974,   975,     0,     0,     0,     0,
       0,     0,   976,     0,     0,   625,     0,   626,   627,   628,
     629,   630,   631,   632,     0,     0,     0,     0,     0,     0,
       0,     0,   977,     0,     0,     0,     0,   978,  -352,     0,
    -352,  -352,  -352,     0,   979,     0,   137,     0,     0,     0,
       0,     0,   758,     0,     0,     0,     0,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,  -352,  -352,     0,     0,     0,     0,     0,     0,
     634,   635,   636,   637,   638,  -352,     0,   639,   640,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,   642,     0,  1691,
       0,     0,  1692, -1821,     0,  1693,   618,   619,   620,   621,
     622,   623,  1694,  1695,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1696,     0,  1697,     0,     0,     0,     0,   643,
       0,   625,     0,   626,   627,   628,   629,   630,   631,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   645,     0,     0,     0,     0,     0,   633,     0,   646,
       0,     0,   647,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   648,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   649,     0,     0,
       0,     0,     0,     0,     0,   650,     0,     0,  1698,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   634,   635,   636,   637,
     638,     0,     0,   639,   640,     0,     0,  1699,     0,     0,
     958,     0,     0,     0,  1700,     0,  1701,   651,     0,   652,
     653,   654, -1774,     0,     0,     0,     0,   959,     0,  1702,
       0,     0,     0,     0,     0,     0,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,   655,     0,     0,     0,
      94,     0,     0,   642,     0,     0,     0,     0,     0,     0,
       0,  1703,     0,     0,  -349,     0,     0,     0,     0,     0,
    1704,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1821,     0,  1705,     0,     0,     0,     0,     0,     0,
     656,   657,   658,     0,     0,   643,     0,     0,     0,     0,
       0,     0,     0,     0,   659,     0,     0,     0,     0,     0,
       0,   660,   618,   619,   620,   621,   622,   623,     0,     0,
       0,     0,     0,  1706,     0,     0,     0,     0,     0,   960,
       0,     0,     0,     0,     0,     0,  1707,   645,     0,     0,
     750,     0,     0,     0,     0,   646,     0,   625,   647,   626,
     627,   628,   629,   630,   631,   632,     0,   958,     0,     0,
       0,   648,     0,  1708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   961,   959,     0,     0,     0,     0,   962,
       0,   963,     0,     0,   753,     0,   964,   965,   966,  1709,
       0,     0,   967,   633,   754,     0,  1710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1711,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   651,     0,   652,   653,   654,     0,     0,
       0,   968,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     969,     0,   634,   635,   636,   637,   638,     0,     0,   639,
     640,     0,     0,     0,     0,  1712,   958,     0,     0,     0,
    -604,     0,     0,     0,   755,  1713,   960,     0,     0,     0,
       0,     0,     0,   959,     0,     0,     0,   750,     0,     0,
       0,     0,  1714,   641,     0,     0,   656,   657,   658,     0,
       0,     0,     0,     0,     0,   970,     0,     0,     0,     0,
     659,     0,     0,     0,     0,     0,  1715,   660,     0,     0,
     961,     0,     0,     0,     0,     0,   962,     0,   963,     0,
       0,   753,     0,   964,   965,   966,     0,     0,     0,   967,
       0,   754,     0,     0,   756,     0,     0,     0,     0,     0,
       0,   643,     0,     0,     0,     0,   971,   972,     0,     0,
       0,     0,     0,     0,     0,     0,   958,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1416,   968,     0,
       0,     0,     0,   959,     0,   960,     0,   973,     0,   757,
       0,   974,   975,   645,     0,     0,   750,   969,     0,   976,
       0,     0,     0,     0,   647,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   648,     0,   977,
       0,   755,     0,     0,   978,     0,     0,     0,     0,   961,
       0,   979,     0,   137,     0,   962,     0,   963,     0,   758,
     753,     0,   964,   965,   966,   958,     0,     0,   967,     0,
     754,     0,   970,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   959,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   652,   653,   654,     0,   960,     0,   968,     0,     0,
       0,   756,     0,     0,     0,     0,   750,     0,     0,     0,
       0,     0,     0,   971,   972,     0,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1956,     0,     0,     0,     0,   961,
     755,     0,     0,     0,   973,   962,   757,   963,   974,   975,
     753,     0,   964,   965,   966,     0,   976,     0,   967,     0,
     754,     0,   656,   657,   658,     0,     0,     0,     0,     0,
       0,   970,     0,     0,   960,     0,   977,     0,     0,     0,
       0,   978,     0,     0,     0,   750,     0,     0,   979,     0,
     137,     0,     0,     0,     0,     0,   758,   968,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     756,     0,     0,     0,     0,     0,   969,     0,   961,     0,
       0,     0,   971,   972,   962,     0,   963,     0,     0,   753,
       0,   964,   965,   966,     0,     0,     0,   967,     0,   754,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   973,     0,   757,     0,   974,   975,     0,
       0,     0,     0,     0,     0,   976,     0,  2671,     0,     0,
       0,   970,     0,     0,     0,     0,   968,     0,     0,     0,
       0,     0,     0,     0,     0,   977,     0,     0,     0,     0,
     978,     0,     0,     0,     0,   969,     0,   979,     0,   137,
       0,     0,     0,     0,     0,   758,     0,     0,     0,     0,
     756,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,   971,   972,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,     0,   757,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   976,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   977,     0,     0,     0,   756,
     978,     0,     0,     0,     0,     0,     0,   979,     0,   137,
       0,   971,   972,     0,     0,   758,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   976,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   977,     0,     0,     0,     0,   978,
       0,     0,     0,     0,     0,     0,   979,     0,   137,     0,
       0,     0,     0,     0,   758
};

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   595,   116,   660,   158,   111,   782,
     366,   540,   954,   103,   684,   105,  1107,   649,   841,  1134,
     714,   111,  1215,  1196,   358,   181,  1579,  1433,  1433,  1433,
     777,   786,   135,   425,  1569,  1433,   787,  1433,  1433,  1474,
    1585,  1110,  1356,   435,  1818,   135,   598,  1120,   404,  1523,
      56,    57,    58,   209,  1247,  1514,  2016,  1366,    64,  1982,
    1254,  1134,  1345,  1901,     1,    17,  1101,     1,   697,    53,
    1112,    49,   742,     9,  1240,  1455,    60,     9,  1120,    49,
      56,   184,    21,    58,    31,     0,     6,    97,  1926,     1,
    2049,    21,  1134,    99,   100,  1105,   102,   844,  1967,  1173,
      27,   107,   108,     1,    87,     9,    22,    71,   111,    58,
     116,   115,   176,  1187,  1308,   233,   257,   364,   130,   751,
     752,   791,  1785,   160,    93,     9,   277,   133,  1508,    71,
    1978,     0,   125,  1447,   143,   177,    64,   153,   204,   173,
     251,    30,   177,  1678,    31,   242,  2447,    49,   142,  1997,
    1998,  1242,    49,  2001,   160,  1501,  1502,  1503,  1504,    30,
    1443,   204,  1750,   329,  1827,   786,   233,  1361,   204,   801,
     309,   238,   126,   162,    58,   175,    65,   161,    67,    17,
     226,   166,    48,  1497,   295,   191,     1,   204,  2148,   116,
     230,    88,    22,    88,  2042,  1230,  1576,   203,   125,  2047,
     355,  1365,    27,   832,    32,   235,   217,    28,  2414,  1925,
     275,   748,   219,   369,   214,  1878,   160,   219,    58,   974,
     411,   407,   407,  1099,   139,   197,   237,   245,   143,   108,
     189,  1107,  1108,   257,   218,   219,    31,   108,  1132,   448,
     995,  1117,   257,   249,  1286,    97,   483,    62,  1124,  1125,
     233,   257,   263,   257,   455,  1297,   367,   128,  1152,  1639,
     455,   124,   546,   124,   501,   257,   200,  1143,  1144,    39,
     139,   466,  1935,   288,   143,    90,    91,   288,     6,  1562,
       0,  1354,  2488,   111,   302,   257,   201,   478,   272,   826,
     499,   116,   478,   478,   178,   287,   167,    92,   282,    73,
     584,   290,   503,   458,     6,   307,   127,  2608,   315,   229,
    1845,   377,  1354,    58,    71,  2163,  1358,   233,   189,   343,
      71,   257,   188,  2161,   389,   341,   786,  1880,   612,   961,
    1000,   371,   201,   342,   205,   453,   130,    71,   330,   505,
     443,  1650,   445,   446,   114,  1100,   457,   291,  1657,   452,
     294,   111,   973,   974,   975,   445,   446,   363,   242,   393,
    2023,  1644,   452,   275,   253,   506,   469,   506,   398,   472,
     473,   512,   475,   470,   995,   478,   479,  1851,  1837,   469,
     358,  1840,    65,   310,    67,   391,  1860,   317,   358,   309,
     205,  1771,   213,   291,   348,     6,   402,   366,   172,   377,
    1518,   257,  1278,   233,   363,   411,   412,   377,   414,   415,
    1165,  1166,  1167,   516,   420,   313,  2132,   454,   233,  2007,
     272,   464,   124,  1178,  1179,     9,   516,   342,   464,   257,
    1185,   437,   449,  1309,    71,   399,   257,   540,   541,   506,
    1558,   453,   506,   332,  1513,  1455,   267,   453,   176,   403,
     540,   541,  1122,   499,  1006,  1007,   358,   399,  1804,   453,
     281,   358,  2331,   358,   506,  1583,  1749,   371,   238,   438,
     341,   506,  1818,   342,   402,   453,   579,   389,   463,  1100,
      57,   592,   485,   453,   336,   213,   450,    64,   599,   579,
     506,   502,  1368,  2341,   506,   598,   506,  2345,  1508,   448,
    1573,   961,   506,  1254,  2463,  2464,   506,   322,   450,   515,
     454,   213,   505,   973,   974,   975,   455,   464,   501,   453,
    1829,  1556,   500,   499,  2088,   455,   347,   466,   534,   257,
     500,  1573,   507,   644,  1700,   995,   466,  1158,   453,   267,
    2203,   453,   462,   154,  1165,  1166,  1167,   650,   554,   796,
     556,   503,  1587,   559,   560,   257,   562,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,   267,  1576,  1188,  1197,   506,
     506,  1613,  2117,  1766,   506,  1769,  2414,   464,   505,  1455,
    2243,   355,  2245,   589,   453,  1217,   470,  1870,   594,     6,
     506,   506,   576,  1667,   498,   601,   417,  2466,   500,   420,
     421,   467,   213,   500,  2063,   500,   444,  2195,   506,   354,
    1361,  2459,  2460,  2276,  2388,  1779,   505,     6,  1494,   347,
     460,   484,   606,   484,  1907,   465,   505,   506,   422,  1639,
     253,  1507,  1508,   403,    33,  2504,  2505,   506,   453,   505,
    1100,   213,   399,  2306,  2307,   347,   257,   257,   399,   332,
     506,  1994,   763,   659,   506,     6,   267,   768,   257,   962,
     963,   272,  1122,   257,    32,   399,   969,   233,  1128,  1545,
     773,   774,  1790,   784,  2634,   831,  2056,  2546,  2058,  1797,
     242,  2550,  2551,   443,   458,   257,   789,   257,   448,   417,
     245,   512,   269,   450,   700,   267,   272,   703,  1158,   450,
    1576,  2265,  2266,   453,   288,  1165,  1166,  1167,  1168,  2632,
    2579,   162,  1104,  1173,  1106,   417,   450,  2097,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1481,  1187,  1188,   453,
    1848,     6,  1774,  1484,   462,    49,   347,  1129,   257,  1131,
     257,  1617,  1777,   160,  1136,    58,   448,    65,  2617,    67,
    2059,  2077,  1628,   204,   257,  1631,   257,  1217,  1150,   130,
     462,  1771,   399,  1639,   341,   263,   350,   390,   331,   168,
    2150,    38,   331,    62,   263,   347,   243,   505,   506,    46,
    1240,    57,   484,     1,   512,  1903,  1121,   777,    64,  2263,
       1,   126,  1158,    11,    26,  2078,   213,  1123,   123,   288,
     204,    90,    91,  1876,   506,  2526,   417,  2470,  2471,  1135,
     512,   154,  1147,   450,    34,   245,  1448,    85,     0,   171,
     397,   309,  1188,   460,   213,   402,  2152,   407,   465,    40,
      41,    42,    43,    44,  1876,  1877,  2400,   358,   195,   290,
     257,    59,   953,  1475,   257,   417,   421,   257,  2191,  2163,
     267,   462,  2405,  1245,   844,    30,   411,   170,   424,   272,
    1481,   232,   213,  1323,  1256,    76,    77,  2588,   257,   268,
    1621,  1962,   448,  2156,   226,   309,   453,  1429,   267,    97,
     503,    99,   234,   101,  2002,   201,   342,   172,   386,   257,
      65,   109,    67,   217,   218,   506,   506,   253,   478,   256,
    2018,   512,   230,  1006,  1007,  1016,   257,   506,   470,   322,
     139,   224,   506,   237,   318,   229,   267,  1672,   385,  2037,
     205,   292,   257,   411,  1258,  1595,   377,  2480,     9,   506,
     347,  1234,   272,  2048,  2049,   253,   506,   347,   213,   263,
     512,  2267,   505,   506,   233,   212,   505,   165,  2066,  1570,
     505,    12,  2070,     9,    15,    16,    12,   139,   347,    15,
      16,   143,     9,  1298,   288,   197,   318,   258,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   244,   388,   500,
      26,   411,   257,   263,  2529,   419,   561,   506,   453,   506,
     478,  2109,   267,   269,   158,  2064,   347,   257,  1101,   266,
     417,   395,  1105,   506,  1338,   506,  1676,   417,   288,  1112,
    1113,    58,    35,   395,   332,    38,   505,  1120,  1769,   201,
    1123,  1481,    45,    46,  2217,  1128,   342,  1130,   417,  1132,
    1133,  1134,  1135,   322,   390,   249,   250,   454,  1914,  1374,
     258,    47,   257,   371,  2454,   462,  2056,  2116,  2058,  1152,
     271,  1672,   319,  2095,   505,   200,    55,    63,  2593,   448,
    2605,  2496,   282,   283,   284,   341,   417,   171,   232,    92,
     330,   453,   347,   462,    57,   453,     6,    60,   253,     9,
       9,    64,  2200,   423,   302,   425,   275,  2097,  2206,   506,
    1246,    90,  1683,   506,  1486,   512,  2187,   103,  2216,   512,
     380,  2511,   512,   407,   407,  2511,  2511,  2511,   107,   330,
    1570,   462,   379,  2511,   107,  2511,  2511,   506,   117,    49,
     331,   397,   226,   512,   117,   345,   402,  1230,   506,   293,
     234,  1763,   213,   344,   453,  1595,  2671,   412,   161,   452,
    2150,  1297,   417,   166,  2697,   436,  1249,   460,   461,   412,
    2685,   286,   465,    83,   506,   506,   338,   332,    88,     8,
     342,   512,   188,   352,   453,   354,   213,   190,  2286,   456,
     100,  2289,  2290,   391,   478,   478,   257,   453,   502,   324,
     325,   505,   455,  1286,  2302,   211,   267,   462,    37,   212,
     118,   119,   120,   466,  1297,   242,   341,   460,  2316,  2317,
     335,   221,   465,     6,   307,   496,     9,  1667,   475,  1365,
     257,   178,  1672,   126,   318,   506,   434,   278,   279,   506,
     267,  1968,   278,   279,   752,   505,   506,   233,  2606,  2607,
    2106,   506,   352,   253,   240,   453,   339,   512,  1341,   460,
    1700,   302,   303,   266,   465,   251,   302,   303,   468,   469,
     395,  1354,   263,   473,   172,  1358,   359,  2635,    83,   172,
    1594,  1107,  2380,   208,   209,   453,   347,  1340,  2144,  2145,
    2021,   238,   202,   801,   241,   100,  2654,   288,  1910,     9,
      83,     8,   263,   213,   213,   233,   269,   205,   506,   751,
     752,  1394,     9,   413,   414,   506,   319,   100,  1144,   453,
     347,    57,   247,   248,  1394,  1661,  2424,   288,    64,   257,
      37,   239,   452,  1469,   751,   752,   246,  1390,  2696,  2629,
      50,   461,   252,  2496,   254,   253,  1429,   257,   257,   259,
     260,   261,   352,   292,   506,   265,   417,   267,   267,   801,
     360,    58,   272,     8,   415,  2039,   352,   353,  2463,  2464,
     153,  2466,  1455,  2176,  2024,  2665,   379,   213,   341,   213,
     308,   367,   310,   369,   801,   324,  2559,   205,   188,   392,
     417,   263,    37,  2249,   304,  1966,   357,   202,   406,   309,
    2390,   462,  2392,   454,   263,  2017,  2613,  2142,   162,   188,
    1204,   211,   166,   323,  1208,   233,   288,   356,   308,   202,
     310,   257,   424,   257,  2631,  1508,   233,  2077,   336,   288,
     213,   267,   211,   267,   397,   462,    16,   347,   347,   402,
     348,  1427,  1578,   470,  2515,   506,  1432,  1433,   358,  1435,
     451,   512,   257,    33,   259,   260,   261,    97,    98,   460,
     265,   395,    42,   246,   465,   178,  1602,   453,   378,   252,
     406,   254,   475,  1556,   257,   188,   259,   260,   261,   506,
     447,   178,   265,  1614,   267,   512,    13,    14,    58,   272,
    1573,  1627,   352,  1576,   354,   460,   453,   464,   211,   304,
     465,   411,  2152,   213,  1587,    32,   174,   417,   417,   453,
    1882,   347,   450,   347,   500,   476,   213,  1166,  1167,   429,
     430,   304,   460,   213,   473,   219,   475,   465,   241,   478,
    1613,   439,   457,   269,   459,   245,   246,   451,   453,   450,
     323,  2142,   506,   506,   505,   242,   460,   257,   450,   460,
    1641,   465,   462,   462,   465,  2411,  1639,   267,   460,  2312,
     257,  2314,   472,   465,   347,  1726,     2,   257,   478,   453,
     267,     7,   453,   378,  1402,  1736,  1737,   267,  1406,  1740,
    1663,   417,   492,   417,   555,  1413,   352,   497,   354,   560,
     500,    54,    55,  1663,   504,   378,   506,   453,    35,     9,
      69,    38,   512,   512,   352,   341,   354,   453,    45,    46,
     487,   488,   489,   490,   506,  1706,  2472,  2267,   300,   301,
    2476,  2477,  1180,  1181,   429,   430,   462,    90,   462,   487,
     488,   489,   490,   157,   417,   159,  1727,   347,   453,  1625,
     487,   488,   489,   490,   107,   506,   429,   430,   341,   453,
     347,  1182,  1183,  1184,   117,    92,   257,   347,  2167,   257,
     470,   397,   620,   621,   622,   623,   402,   472,   200,   157,
     506,   159,   455,    83,   506,   253,   512,   255,   512,   462,
     444,  2434,  2604,   466,  1767,   401,   411,   492,  1771,   472,
     100,  1774,   497,   402,  1777,  1681,  1682,    64,   253,   504,
     255,   506,  2142,   253,    60,   255,  1692,   417,    66,   492,
      68,   257,   233,  1699,   497,   453,   973,   453,   975,   329,
     417,   504,   402,   506,   161,   506,  2098,   417,   257,   512,
     230,  1664,  1665,  1666,    26,   453,   453,  1670,   108,   453,
    1673,  1674,  1728,   786,  1827,   313,  1882,   257,   257,    23,
     273,   456,   462,   190,   103,  2091,   439,   453,   189,   123,
      17,   456,    87,   506,   453,   462,   395,   273,   352,   402,
      57,   403,   462,   470,   505,   212,   424,   263,    39,   453,
     238,   403,   506,   332,  1915,  1916,  1917,  1918,  1919,  1920,
    1921,  1922,   202,  1876,  1877,  1878,   508,  1933,   506,   420,
    1786,   317,   512,   213,   311,   395,  1942,  1943,   262,   506,
     453,     7,   453,   395,   256,   512,   453,   453,   506,  1805,
     505,   395,   512,   367,    86,  1811,   453,   453,    86,   266,
     125,   395,   390,   453,    22,   307,   310,   453,   395,   205,
     506,   506,   501,   503,   453,   385,   233,   257,   506,   259,
     260,   261,  1935,   448,   255,   265,   219,   267,   123,   322,
     506,   512,    53,   326,   327,   448,    26,   464,   444,   307,
     401,   349,   449,   411,   197,   506,   447,   464,  1961,   444,
     257,   453,   319,   506,   453,   377,   400,   337,   506,   115,
    1973,  1961,   170,   453,   304,  1978,   257,   464,   464,   188,
    1991,   464,   464,   464,   367,   464,   453,   506,   464,   448,
     464,   464,   453,   224,  1997,  1998,   310,   506,  2001,   404,
     383,   384,   455,    30,   131,   506,   197,   506,   132,   448,
     973,   974,   975,   133,   387,   134,   137,   347,   135,   102,
    2023,   136,   379,   448,   138,   443,   464,   499,   141,    49,
     405,   447,   995,   444,   447,   392,   197,  2048,  2049,  2042,
     441,  1947,  2098,   144,  2047,  2048,  2049,  2601,   378,   145,
     147,  2107,   146,  2056,   272,  2058,   501,    31,   148,  1965,
      49,     6,   149,  2554,     9,   150,  2620,   197,   113,   151,
     221,   152,   115,   450,   450,  1981,   411,  1983,   450,   450,
     313,  1987,   450,   450,   448,  2606,  2607,   417,   453,  1995,
     224,   110,  2095,  2584,  2097,   198,   448,   204,   377,   429,
     430,   340,   257,   273,   232,   295,   299,   486,   166,   176,
     503,   129,   503,   366,  2635,   448,   169,   229,   475,   130,
     448,    49,   197,   229,   300,   177,   205,    57,   205,   453,
     273,   253,   462,  2654,   166,  1098,   238,  1100,    83,   424,
    1103,   510,   472,   506,  1107,   511,    11,  2150,   300,   448,
     448,   277,   381,   363,   296,   100,    30,   204,   204,  1122,
    2163,    17,   492,   129,  2167,  1128,   366,   497,   113,   444,
     140,   448,    49,   204,   504,  2696,   506,  2167,   142,     8,
     197,   130,   512,   503,  2090,   503,  1149,  2479,  1151,   424,
     204,   453,   448,     9,    59,  1158,     7,   506,   257,   505,
     295,   204,  1165,  1166,  1167,  1168,   298,   500,   500,   505,
    1173,    49,   189,   263,   292,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,   463,  1187,  1188,   315,   331,   314,   114,
     438,   204,    97,    47,    99,  2527,   101,   412,   295,   204,
    2243,   103,  2245,   381,   109,    49,  2606,  2607,   263,   297,
     238,    96,   362,  1216,   293,    57,   494,   202,     8,    49,
     111,   458,   362,   263,   338,   263,   263,   453,   213,   110,
    2273,   211,   338,  2276,   453,  2635,   341,  1240,   483,  1242,
     108,   222,   503,  2273,   229,   210,   419,   120,   197,   338,
     314,    49,   368,   322,  2654,   307,     7,   426,    46,    92,
     165,   246,    26,   127,  2307,   201,   148,   252,   206,   254,
      75,   221,   257,   150,   259,   260,   261,   238,   177,   410,
     265,   469,   267,   519,  2327,  1881,   286,   272,  1015,   497,
    1433,   741,   425,  2669,  1392,  1874,  2696,  2327,  2341,   774,
    1655,  2165,  2345,   791,    24,    25,   786,  2648,  2681,  2617,
    2188,   844,  1024,  2188,  2061,  1739,   780,  1738,  1213,   304,
    1323,  1821,   227,  2373,  2360,  1773,  1467,  1230,  2059,  1469,
    1494,  1513,  1516,  2241,  2063,  1840,  1559,  1282,   323,  2259,
    1566,  2086,  1345,  1868,  1318,  1577,    66,  2390,    68,  2392,
      70,  1323,  2098,   258,  2105,  1943,  1894,  1607,  1923,  2305,
    2119,  1352,   347,  1135,  1354,  2408,  2145,  1942,  1371,  1368,
    1942,  2310,  2665,  1654,  2315,  2414,  2138,  1545,  2138,     4,
    2712,  2138,  2320,  1341,   104,   105,   106,  1463,  2138,   299,
     691,   152,   242,   378,    19,   270,  1910,   302,   746,   978,
     305,  2537,   417,  2349,    29,   509,  2402,  2583,  2354,   215,
     449,  1930,  2463,  2464,  2075,  1873,  2459,  2460,   705,   558,
    2463,  2464,  1569,  2466,  2608,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   417,    -1,   154,    -1,   156,    -1,    -1,    64,
    1443,    -1,    -1,   163,   429,   430,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   370,    -1,  2413,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,  1481,    -1,
      -1,   961,    -1,  2526,    -1,    -1,   391,   472,    -1,    65,
      66,    67,    68,   973,   974,   975,    -1,    -1,    -1,  2445,
    2446,    -1,    -1,    -1,    -1,  2556,    -1,   492,    -1,    -1,
      -1,   416,   497,   418,    -1,   995,  2462,     6,    -1,   504,
       9,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,   434,
      -1,    -1,  2478,   253,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2588,    -1,    -1,    -1,    -1,
      -1,    -1,   272,    -1,    -1,    -1,    -1,  2503,    -1,  1562,
      -1,  2612,  2508,  2509,    -1,  2616,    -1,  1570,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2528,  1586,    -1,    -1,  2629,    -1,    -1,    -1,
      -1,    -1,  1595,    -1,    83,    -1,   221,    -1,    -1,    -1,
      -1,   506,    -1,  1606,    -1,    -1,    95,    -1,    -1,    -1,
      -1,   100,  2558,    -1,    -1,  2561,  2562,    -1,    -1,    -1,
    1100,    -1,  2665,    -1,    -1,  1105,    -1,    -1,   253,    -1,
      -1,  1634,  1112,    -1,   210,    -1,    -1,    -1,   263,    -1,
    1120,  1644,    -1,    -1,    -1,    -1,  2689,    -1,    -1,  2700,
      -1,    -1,    -1,    -1,  1134,    -1,    -1,  2603,    -1,    -1,
     236,    -1,    -1,    -1,  1667,    -1,    -1,    -1,    -1,  1672,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,  1158,   255,
      -1,    -1,    -1,    -1,    -1,  1165,  1166,  1167,  1168,    -1,
      -1,   316,    -1,  1173,    -1,    -1,   321,  1700,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,    -1,  1187,  1188,  1712,
     286,    -1,  1715,   202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   445,    -1,   352,    -1,    -1,
     306,    -1,    -1,    -1,    -1,   360,    -1,  1217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1749,    -1,   373,    -1,
      -1,    -1,   328,    -1,    -1,    -1,    -1,   246,   334,    -1,
      -1,    -1,  1765,   252,    -1,   254,    -1,    -1,   257,  1249,
     259,   260,   261,    -1,    -1,   495,   265,   402,   267,    -1,
     405,    -1,    -1,   272,    -1,    -1,   506,    -1,   413,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    -1,    -1,    83,    -1,  1286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,    -1,  1297,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,
     406,   456,    -1,    -1,   323,    -1,    -1,    -1,    -1,   415,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,  1345,    -1,  1870,  1871,    -1,
      -1,    -1,    -1,    -1,  1354,    -1,    -1,   453,  1358,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,    -1,    -1,    -1,    -1,  1899,    -1,   474,    -1,
      -1,    -1,    -1,    -1,  1907,     1,    -1,     3,    -1,     5,
      -1,    -1,   191,    -1,    10,    -1,    -1,   493,    -1,    -1,
      -1,    -1,    18,   202,   500,   501,    -1,    -1,   417,    -1,
      -1,  1934,    -1,    -1,    -1,    -1,    -1,    -1,  1941,  1942,
     429,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,  1962,
      -1,    -1,    -1,  1443,    -1,    61,    -1,    -1,    -1,  1972,
      -1,    -1,    -1,   462,    -1,  1455,    72,    -1,   257,    75,
     259,   260,   261,   472,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1481,    -1,   492,    -1,    -1,    -1,    -1,   497,    -1,
      -1,    -1,    -1,    -1,    -1,   504,   112,   506,    -1,    -1,
      -1,  2024,    -1,   512,   120,   304,   122,    -1,  1508,    -1,
      -1,    -1,    -1,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2068,    -1,    -1,   164,    -1,
      -1,    -1,    -1,   169,  2077,  2078,    -1,    -1,    -1,    -1,
      -1,    -1,  1562,  2086,    -1,    -1,    -1,    -1,    -1,    -1,
    1570,    -1,    -1,  1573,    -1,    -1,  1576,    -1,    -1,   378,
     196,    -1,  2105,    -1,    -1,    -1,    -1,   203,    -1,    -1,
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,   225,
      -1,  2134,   228,  1613,    -1,    -1,    -1,    -1,    -1,  2142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2152,
     429,   430,    -1,  2156,    -1,    -1,    -1,    -1,    -1,  1639,
      -1,    -1,   441,    -1,  1644,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,  2178,    -1,    -1,   274,    -1,
     276,    -1,    -1,    -1,  2187,    -1,    -1,  1667,    -1,    -1,
     286,    -1,  1672,   472,    -1,    -1,   292,   293,    -1,   295,
     296,   297,   298,    -1,   483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,   312,    -1,   497,  2222,
      -1,    -1,   501,    -1,    -1,   504,   505,   506,    -1,   325,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2267,   361,    -1,    -1,    -1,  1749,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,
     376,    -1,    -1,    -1,    -1,    -1,   382,  1767,    -1,    -1,
     386,  1771,    -1,    32,  1774,    -1,    35,    -1,   394,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,   404,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,
      -1,   427,   428,    -1,    -1,   431,    -1,   433,    -1,    -1,
      -1,    -1,    -1,    -1,   440,    -1,    -1,  1827,    -1,    -1,
       1,    -1,     3,    92,     5,    -1,    -1,   453,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,   111,    -1,    -1,   471,    -1,    -1,    -1,    -1,
    2383,   477,    -1,    -1,    -1,    -1,   482,    -1,    -1,    -1,
    1870,  1871,    -1,    -1,    -1,    -1,  1876,  1877,  1878,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,
      61,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,  2426,    75,    -1,    -1,  1907,    -1,    -1,
    2433,    -1,    -1,  2436,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,  1935,    -1,    -1,    -1,    -1,
     199,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   122,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2499,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,  2515,   164,    -1,    -1,    -1,    -1,   169,    -1,
      -1,    -1,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,  2023,    -1,   196,    -1,    -1,    -1,   288,
     289,    -1,   203,    -1,    -1,   206,   207,   100,    -1,    -1,
    2563,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,
      -1,    -1,   223,    -1,   225,    -1,  2056,   228,  2058,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,    -1,     5,    -1,  2078,    -1,
      -1,    10,    -1,  2606,  2607,    -1,  2086,   346,    -1,    18,
      -1,    -1,    -1,    -1,    -1,  2095,    -1,  2097,    -1,   270,
    2623,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
      -1,    -1,  2635,   372,    -1,   286,    -1,    -1,    -1,    -1,
     379,    -1,    51,    52,  2647,  2648,    -1,    -1,   191,    -1,
      -1,  2654,    61,   392,    -1,    -1,    -1,   396,    -1,   202,
      -1,   312,  2142,    72,    -1,    -1,    75,    -1,    -1,    -1,
    2150,    -1,    -1,    -1,   325,    -1,  2156,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2692,
      -1,    -1,    -1,  2696,    -1,    -1,    -1,    -1,   437,   350,
     351,    -1,    -1,   112,    -1,    -1,    -1,   446,    -1,    -1,
     361,   120,    -1,   122,   257,    -1,   259,   260,   261,    -1,
      -1,    -1,   265,    -1,   375,   376,    -1,    -1,    -1,    -1,
      -1,   382,    -1,    -1,    -1,   386,   475,    -1,    -1,    -1,
      -1,    -1,    -1,   394,   153,    -1,   485,    -1,    -1,    -1,
      83,    -1,   491,   404,    -1,   164,    -1,    -1,    -1,    -1,
     169,   304,   413,  2243,    -1,  2245,    -1,   100,    -1,    -1,
      -1,   422,    -1,    -1,    -1,    -1,   427,   428,    -1,    -1,
     431,    -1,   433,    -1,    -1,    -1,    -1,   196,    -1,   440,
      -1,    -1,    -1,    -1,   203,    -1,  2276,   206,   207,    -1,
      -1,    -1,   453,    -1,    -1,    -1,    -1,   216,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,   225,    -1,    -1,   228,
     471,    -1,    -1,    -1,    -1,    -1,   477,  2307,    -1,    -1,
      -1,   482,    -1,    -1,     1,   378,     3,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,
      -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,
     213,    -1,    -1,    -1,    51,    52,   429,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,   441,    -1,
      -1,    -1,    -1,   312,    -1,    72,    -1,    -1,    75,    -1,
    2390,    -1,  2392,   246,    -1,    -1,   325,    -1,    -1,   252,
      -1,   254,    89,    -1,   257,    -1,   259,   260,   261,   472,
      -1,    -1,   265,    -1,   267,    -1,    -1,    -1,    -1,    -1,
     483,   350,   351,    -1,    -1,   112,    -1,    -1,    -1,   492,
      -1,    -1,   361,   120,   497,   122,    -1,    -1,   501,    -1,
      -1,   504,   505,   506,    -1,    -1,   375,   376,    -1,    -1,
      -1,   304,    -1,   382,    -1,    -1,    -1,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,   153,    -1,    -1,    -1,
     323,    -1,    -1,    -1,    -1,   404,    -1,   164,    -1,    -1,
      -1,    -1,   169,    -1,   413,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   422,   347,    -1,    -1,    -1,   427,   428,
      -1,    -1,   431,    -1,   433,    -1,    -1,    -1,    -1,   196,
      -1,   440,    -1,    -1,    -1,    -1,   203,    -1,    -1,   206,
     207,    -1,    -1,    -1,   453,   378,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,   225,    -1,
      -1,   228,   471,    -1,    -1,    -1,    -1,    -1,   477,    -1,
      -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,    -1,    -1,
     509,    -1,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,    -1,  2606,  2607,    -1,   462,
      -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,
      -1,    -1,    -1,    -1,    -1,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2635,    -1,    -1,   325,   492,
      -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,
      -1,   504,    -1,   506,  2654,    -1,    -1,    -1,    -1,   512,
      -1,    -1,    -1,   350,   351,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,   361,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,   375,   376,
      -1,    -1,    -1,    -1,    -1,   382,  2696,    -1,    -1,   386,
      -1,    -1,    -1,    -1,    83,    -1,    -1,   394,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,    51,    52,
      -1,   100,    -1,    -1,    -1,    -1,   413,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,    72,
     427,   428,    75,    -1,   431,    -1,   433,    -1,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,    89,    -1,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,   471,    -1,    -1,   120,    -1,   122,
     477,    -1,    -1,    -1,    -1,   482,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,   509,   202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,    -1,   213,    -1,   169,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,    -1,    -1,   206,   207,    -1,    -1,    -1,   257,    -1,
     259,   260,   261,   216,    -1,    -1,   265,    -1,   267,    -1,
     223,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   304,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,    -1,    -1,   202,    -1,    -1,    -1,
      -1,    -1,   208,   209,    -1,    -1,    -1,   213,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,    -1,   378,
     246,   247,   248,    -1,    -1,    -1,   252,    -1,   254,    -1,
      -1,   257,    -1,   259,   260,   261,    -1,   350,    -1,   265,
      -1,   267,    -1,    -1,    -1,    -1,   272,     6,   361,    -1,
       9,    -1,    -1,    12,    13,    14,    -1,    -1,   417,   285,
      -1,    20,    -1,   376,    -1,   291,    -1,    -1,   294,   382,
     429,   430,    -1,   386,    -1,    -1,   302,    -1,   304,    -1,
      -1,   394,    -1,   309,    -1,    -1,    -1,    -1,   314,    -1,
      -1,   404,    -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,
     413,    -1,    -1,   462,    -1,    -1,    -1,   333,    -1,   422,
      -1,    -1,    -1,   472,   427,   428,    -1,    -1,   431,    -1,
     433,   347,    -1,    -1,    83,    -1,    -1,   440,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,   497,    -1,
     453,   100,    -1,    -1,    -1,   504,    -1,   506,    -1,    -1,
      -1,    -1,   378,   512,    -1,    -1,    -1,    -1,   471,    -1,
      -1,    -1,    -1,     6,   477,    -1,     9,    -1,    -1,   482,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,   417,    -1,     9,    -1,    -1,   509,    -1,    -1,    -1,
      -1,   160,    -1,   429,   430,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,   452,    -1,   454,    -1,
      -1,   457,    -1,   459,   460,   461,   462,    -1,   464,   465,
      83,    -1,    -1,   202,    -1,    -1,   472,    -1,    -1,   208,
     209,    -1,    95,    -1,   213,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   492,    83,    -1,    -1,
      -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,
     506,    -1,    -1,    -1,   100,    -1,   512,   246,   247,   248,
      -1,    -1,    -1,   252,    -1,   254,    -1,   113,   257,    -1,
     259,   260,   261,    -1,    -1,    -1,   265,    -1,   267,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,   291,    -1,    -1,   294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   302,    -1,   304,    -1,    -1,    -1,    -1,
     309,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,   254,    -1,    -1,   257,    -1,   259,   260,   261,   378,
      -1,    -1,   265,    -1,   267,    -1,    -1,    -1,    -1,   272,
     246,    -1,     6,    -1,    -1,     9,   252,    -1,   254,    -1,
      -1,   257,    -1,   259,   260,   261,    -1,    -1,    -1,   265,
      -1,   267,    -1,    -1,    -1,    -1,   272,    -1,   417,    -1,
      -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,
      -1,   450,    -1,   452,    -1,   454,    -1,    -1,   457,    -1,
     459,   460,   461,   462,   347,   464,   465,   323,    -1,    83,
      -1,     6,    -1,   472,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,
      -1,   347,    -1,   492,    -1,   378,    -1,    -1,   497,    -1,
       6,    -1,    -1,     9,    -1,   504,    -1,   506,    -1,    -1,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   417,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,   430,    -1,    -1,    83,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   472,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,     6,   213,
      -1,     9,    -1,    -1,    -1,    -1,   462,    -1,    -1,   492,
      -1,    -1,    -1,    -1,   497,    -1,   472,    -1,    -1,    -1,
      -1,   504,    -1,   506,    -1,    -1,    -1,    -1,    -1,   512,
      -1,    -1,   246,    -1,    -1,    -1,   492,    -1,   252,    -1,
     254,   497,    -1,   257,    -1,   259,   260,   261,   504,    -1,
     506,   265,    -1,   267,    -1,    -1,   512,    -1,   272,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,   100,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,   323,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,    -1,   254,
      -1,    -1,   257,    -1,   259,   260,   261,    -1,    -1,    -1,
     265,    -1,   267,   347,    -1,    -1,    -1,   272,    -1,    -1,
     246,    -1,     6,    -1,    -1,     9,   252,    -1,   254,    -1,
      -1,   257,    -1,   259,   260,   261,    -1,    -1,    -1,   265,
      -1,   267,    -1,    -1,   378,    -1,   272,    -1,    -1,   304,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   304,    -1,
      -1,    -1,    -1,   417,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,   347,    -1,    -1,   429,   430,   323,    -1,    83,
       6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   246,    -1,
      -1,   347,    -1,   378,   252,    -1,   254,    -1,   462,   257,
      -1,   259,   260,   261,    -1,    -1,    -1,   265,   472,   267,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   378,     6,    -1,    -1,     9,    -1,   492,    -1,
      -1,    -1,   417,   497,    -1,    -1,    -1,    -1,    -1,    -1,
     504,    -1,   506,    -1,   429,   430,   304,    83,   512,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   417,    -1,   448,   100,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,   430,    -1,    -1,   462,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   472,   202,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      83,     6,    -1,    -1,     9,    -1,   462,   492,    -1,    -1,
      -1,    -1,   497,    -1,    -1,    -1,   472,   100,    -1,   504,
     378,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,   492,    -1,   252,    -1,
     254,   497,    -1,   257,    -1,   259,   260,   261,   504,    -1,
     506,   265,    -1,   267,    -1,    -1,   512,    -1,   272,   417,
      -1,     6,    -1,    -1,     9,    -1,   202,    -1,    -1,    -1,
      -1,   429,   430,    -1,    -1,    -1,    -1,   213,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,   323,
     246,    -1,    -1,    -1,   472,    -1,   252,    -1,   254,   202,
      -1,   257,    -1,   259,   260,   261,    -1,    -1,   486,   265,
     213,   267,    -1,   347,   492,    -1,   272,    -1,    83,   497,
      -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,   506,    -1,
      -1,    -1,    -1,    -1,   512,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   378,    -1,    -1,    -1,   304,   252,
      -1,   254,    -1,    -1,   257,    -1,   259,   260,   261,    -1,
      -1,    -1,   265,    -1,   267,    -1,    -1,   323,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,   213,    -1,
      -1,   347,    -1,    -1,    -1,   429,   430,    -1,    -1,    -1,
      -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     323,   246,   378,    -1,    -1,    -1,    -1,   252,   462,   254,
      -1,    -1,   257,    -1,   259,   260,   261,   202,   472,    -1,
     265,    -1,   267,    -1,   347,    -1,    -1,   272,   213,    -1,
      -1,    -1,    -1,    -1,    -1,   411,    -1,    -1,   492,    -1,
      -1,   417,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,
     504,    -1,   506,   429,   430,   378,    -1,    -1,   512,   304,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,    -1,   254,
      -1,    -1,   257,    -1,   259,   260,   261,    -1,   323,    -1,
     265,    -1,   267,    -1,    -1,    -1,   462,   272,    -1,    -1,
      -1,    -1,    -1,    -1,   417,    -1,   472,    -1,    -1,    -1,
      -1,    -1,   347,    -1,    -1,    -1,   429,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,   304,
      -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,
     506,    -1,    -1,   378,    -1,    -1,   512,    -1,   323,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,   492,
      -1,    -1,   417,    -1,   497,    -1,    -1,    -1,    -1,    -1,
      -1,   504,    -1,   506,   429,   430,    -1,    -1,    -1,   512,
      -1,    32,    -1,   378,    35,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    67,   472,    -1,    -1,
      -1,    -1,   417,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,   429,   430,    -1,   492,    -1,    -1,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,   504,
     161,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,
      -1,    -1,    -1,    83,    -1,   176,    -1,    -1,   179,   180,
     181,   182,   183,     1,    -1,   186,   187,    -1,    -1,   190,
     100,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
      -1,    -1,    -1,    21,   205,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    36,   220,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,   233,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   213,    -1,   306,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,
     331,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,   252,   344,   254,   346,    -1,   257,    -1,   259,
     260,   261,    -1,    -1,   172,   265,    -1,   267,   176,    -1,
      -1,   179,   180,   181,   182,   183,    -1,    -1,   186,   187,
      -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,   379,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   304,   396,    -1,    -1,    -1,    -1,
      -1,    -1,   220,    -1,    -1,   406,    -1,   408,   409,   410,
      -1,    -1,    -1,   323,    -1,   233,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,
      -1,    -1,   453,    -1,    -1,    -1,    -1,   458,    -1,    -1,
     278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   470,
      -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,   479,   480,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,
      -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,   499,   500,
      -1,    -1,   320,    -1,    -1,   506,    -1,   417,    -1,    -1,
     328,    -1,    21,   331,    -1,    -1,    -1,    -1,    -1,   429,
     430,    -1,    -1,    -1,    -1,    -1,   344,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,   356,    -1,
     450,    -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,
     460,    -1,   462,    -1,   464,   465,    -1,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   492,    -1,    -1,    -1,    -1,   497,   406,    -1,
     408,   409,   410,    -1,   504,    -1,   506,    -1,    -1,    -1,
      -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,   480,   481,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,   183,   493,    -1,   186,   187,    -1,
      -1,    -1,   500,    -1,    -1,    -1,    -1,    -1,   506,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,   236,    -1,    32,
      -1,    -1,    35,   242,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,   278,
      -1,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   320,    -1,    -1,    -1,    -1,    -1,   120,    -1,   328,
      -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
     183,    -1,    -1,   186,   187,    -1,    -1,   190,    -1,    -1,
      83,    -1,    -1,    -1,   197,    -1,   199,   406,    -1,   408,
     409,   410,   205,    -1,    -1,    -1,    -1,   100,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     233,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,
     479,   480,   481,    -1,    -1,   278,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,
      -1,   500,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,   319,   320,    -1,    -1,
     213,    -1,    -1,    -1,    -1,   328,    -1,    74,   331,    76,
      77,    78,    79,    80,    81,    82,    -1,    83,    -1,    -1,
      -1,   344,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   100,    -1,    -1,    -1,    -1,   252,
      -1,   254,    -1,    -1,   257,    -1,   259,   260,   261,   372,
      -1,    -1,   265,   120,   267,    -1,   379,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,   408,   409,   410,    -1,    -1,
      -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     323,    -1,   179,   180,   181,   182,   183,    -1,    -1,   186,
     187,    -1,    -1,    -1,    -1,   448,    83,    -1,    -1,    -1,
     453,    -1,    -1,    -1,   347,   458,   202,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,   475,   220,    -1,    -1,   479,   480,   481,    -1,
      -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,
     493,    -1,    -1,    -1,    -1,    -1,   499,   500,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,   252,    -1,   254,    -1,
      -1,   257,    -1,   259,   260,   261,    -1,    -1,    -1,   265,
      -1,   267,    -1,    -1,   417,    -1,    -1,    -1,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,   429,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,   304,    -1,
      -1,    -1,    -1,   100,    -1,   202,    -1,   460,    -1,   462,
      -1,   464,   465,   320,    -1,    -1,   213,   323,    -1,   472,
      -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,    -1,   492,
      -1,   347,    -1,    -1,   497,    -1,    -1,    -1,    -1,   246,
      -1,   504,    -1,   506,    -1,   252,    -1,   254,    -1,   512,
     257,    -1,   259,   260,   261,    83,    -1,    -1,   265,    -1,
     267,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,   409,   410,    -1,   202,    -1,   304,    -1,    -1,
      -1,   417,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,    -1,    -1,   429,   430,    -1,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,    -1,    -1,   246,
     347,    -1,    -1,    -1,   460,   252,   462,   254,   464,   465,
     257,    -1,   259,   260,   261,    -1,   472,    -1,   265,    -1,
     267,    -1,   479,   480,   481,    -1,    -1,    -1,    -1,    -1,
      -1,   378,    -1,    -1,   202,    -1,   492,    -1,    -1,    -1,
      -1,   497,    -1,    -1,    -1,   213,    -1,    -1,   504,    -1,
     506,    -1,    -1,    -1,    -1,    -1,   512,   304,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     417,    -1,    -1,    -1,    -1,    -1,   323,    -1,   246,    -1,
      -1,    -1,   429,   430,   252,    -1,   254,    -1,    -1,   257,
      -1,   259,   260,   261,    -1,    -1,    -1,   265,    -1,   267,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,   462,    -1,   464,   465,    -1,
      -1,    -1,    -1,    -1,    -1,   472,    -1,   374,    -1,    -1,
      -1,   378,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,
     497,    -1,    -1,    -1,    -1,   323,    -1,   504,    -1,   506,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
     417,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
      -1,    -1,   429,   430,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     378,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,   417,
     497,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,   506,
      -1,   429,   430,    -1,    -1,   512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,   497,
      -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,   506,    -1,
      -1,    -1,    -1,    -1,   512
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   515,   516,     0,   201,   342,   517,   518,   519,   520,
     521,   522,   524,   534,   536,   453,   453,   519,   154,   530,
     542,   530,   530,   257,   343,   537,   537,   123,    85,   543,
     523,   525,   534,   139,   528,   529,    26,   538,   538,   453,
     395,   544,   143,   523,   526,   527,   530,   537,   257,   453,
     535,   453,    11,    59,    97,    99,   101,   109,   165,   227,
     258,   302,   305,   370,   391,   416,   418,   434,   506,   545,
     546,   550,   561,   569,   570,   571,   572,   573,   578,   586,
     588,   593,   596,   597,   599,   600,   601,   602,   603,   604,
     605,   537,   525,   453,   233,   539,  1272,   506,  1192,  1192,
     424,   406,  1290,  1272,  1272,  1272,   395,  1192,   406,   453,
     453,  1272,   453,   453,    58,  1260,   574,     1,   453,   572,
     219,   587,   174,   606,   453,   527,   453,    73,   172,   355,
     458,   540,   541,   579,  1272,  1272,  1272,   506,  1187,  1218,
      69,  1187,   453,  1272,  1272,   551,   562,  1187,   547,   506,
     589,   590,   591,  1193,   257,   308,   310,   575,   577,  1037,
    1221,  1272,   453,   506,   453,   608,   541,   341,  1287,  1272,
     213,   257,   267,   347,   417,   462,   512,   594,   595,  1224,
    1187,   257,   219,   307,  1310,   257,   470,    57,    64,   269,
     341,   397,   402,   506,   552,   553,   554,   555,   556,   557,
     558,   560,  1259,  1320,   200,   563,   564,   565,   548,   560,
     590,    22,   233,  1193,  1273,  1037,   233,   424,  1284,  1272,
      97,  1192,   235,   398,   607,   609,    28,   127,   213,   257,
     267,   281,   347,   417,   420,   421,   512,   580,   581,   582,
     585,   595,   444,   505,   598,  1303,  1218,   401,   402,   411,
      64,  1272,   453,   554,   453,   506,   553,    60,  1272,     9,
     371,   498,   566,   568,     1,   453,   565,   549,  1303,   257,
     592,  1222,  1284,   233,  1192,  1192,   576,   577,   453,     1,
     291,   313,  1245,   275,   389,   640,   641,   642,   643,   645,
     582,    17,   444,  1224,   329,  1272,   402,  1221,   453,  1272,
     506,  1188,   230,    26,   567,   230,   371,   453,   453,   108,
    1222,  1192,   453,   313,  1192,   646,   352,   413,   414,   644,
     531,     1,   453,   642,   583,   585,   257,  1221,   258,   436,
     496,   559,  1188,   257,   273,   610,   456,  1263,    23,  1254,
     103,   650,   453,   584,   585,    58,   507,  1314,   611,   439,
    1296,   189,  1265,   123,   456,   651,    17,     4,    19,    29,
      64,   221,   253,   316,   321,   352,   360,   373,   402,   405,
     413,   453,   456,   612,   613,   619,   621,   622,   623,   624,
     625,   626,   629,   630,   631,   632,   633,   635,   636,   638,
    1288,  1304,    87,  1261,   506,  1177,  1178,   453,   395,   652,
     585,   273,  1279,   352,  1288,   448,   499,  1300,   402,   403,
    1272,  1259,   114,   238,  1274,  1274,   288,   637,  1221,  1303,
     424,   263,    39,  1257,  1272,   647,   648,  1178,  1178,   453,
     173,   393,   532,   653,   654,   656,  1272,  1274,   126,   172,
     616,   360,   630,  1272,  1272,  1272,  1272,  1254,     9,   288,
     350,   639,  1272,  1279,   403,   506,   648,   332,   649,   508,
     681,   683,   684,     1,  1178,   126,   348,   403,   620,  1272,
     118,   119,   120,   239,   253,   336,   348,   439,   614,   615,
     257,  1187,  1191,   420,   634,  1187,  1187,   317,  1285,  1285,
     311,  1187,  1272,  1221,   395,   262,   737,   685,   686,   688,
     698,  1237,   453,   655,   634,   257,   618,  1218,   618,     7,
     618,   618,   257,   617,  1218,   415,   454,    33,   168,   268,
     627,   453,   395,   256,   739,   453,   686,   453,     1,   176,
     506,   689,   690,   506,   657,   125,   505,  1239,  1319,  1263,
    1272,  1186,  1187,   505,   628,   628,   682,   453,   395,   367,
     741,   453,   453,   687,    86,    47,    63,   103,   240,   251,
     352,   353,   367,   369,   453,   500,   658,   659,   661,   665,
     666,   669,   670,   676,   677,   678,   679,  1272,   125,  1186,
    1187,   263,   386,   683,   738,   453,   395,   390,   786,   700,
     691,  1272,  1261,  1272,   352,   354,  1315,  1315,  1272,  1261,
    1272,  1279,  1272,    22,  1253,   307,   680,  1192,   172,   205,
     310,   683,   740,   453,   395,   533,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    74,    76,    77,    78,    79,
      80,    81,    82,   120,   179,   180,   181,   182,   183,   186,
     187,   220,   236,   278,   306,   320,   328,   331,   344,   356,
     364,   406,   408,   409,   410,   435,   479,   480,   481,   493,
     500,   701,   702,   703,   705,   706,   707,   708,   709,   710,
     711,   714,   726,   727,   728,   729,   730,   735,   736,  1272,
    1292,    26,   197,   699,  1255,   205,  1221,   506,  1272,  1253,
     506,  1189,  1190,   309,   419,  1311,  1191,  1221,   501,  1272,
     175,   214,   506,   667,  1192,   275,   352,   354,  1313,   683,
     742,   453,   338,   800,   803,   245,   302,   407,   478,  1291,
     478,  1291,   478,  1291,   478,  1291,   478,  1291,   503,  1301,
     385,  1289,   126,  1221,  1215,  1218,  1218,   233,   243,   385,
    1275,  1272,  1273,   172,   205,   242,   470,   506,     9,    50,
     213,   245,   246,   257,   267,   347,   417,   462,   512,   692,
    1225,  1226,  1227,   448,   664,  1190,   255,  1278,   448,  1260,
     219,  1267,   506,  1272,  1272,  1313,   743,   787,   123,   826,
     827,   512,    53,   718,   448,   715,   464,  1219,  1220,   444,
     708,   732,   733,  1225,    26,   704,   401,  1249,  1249,  1227,
     307,  1282,     1,    40,    41,    42,    43,    44,   179,   180,
     181,   182,   183,   184,   185,   331,   344,   693,   694,   695,
     696,   697,   709,   710,  1215,   693,   449,  1221,    58,   354,
     660,   671,  1221,   411,  1293,   257,   668,  1218,   668,   349,
     744,   688,   698,   788,   789,   790,    56,   499,   804,     1,
       3,     5,    10,    18,    51,    52,    61,    72,    75,    89,
     112,   120,   122,   153,   164,   169,   196,   203,   206,   207,
     216,   223,   225,   228,   270,   274,   276,   286,   312,   325,
     350,   351,   361,   375,   376,   382,   386,   394,   404,   413,
     422,   427,   428,   431,   433,   440,   453,   471,   477,   482,
     509,   828,   829,   845,   850,   854,   859,   874,   877,   881,
     885,   886,   887,   892,   906,   910,   913,   927,   931,   934,
     937,   941,   942,   946,   956,   959,   976,   978,   981,   985,
     991,  1003,  1011,  1012,  1015,  1016,  1020,  1025,  1026,  1034,
    1049,  1059,  1068,  1073,  1080,  1084,  1086,  1089,  1092,  1096,
    1123,   828,  1267,   197,   716,  1221,   447,  1298,    83,   100,
     202,   246,   252,   254,   259,   260,   261,   265,   304,   323,
     378,   429,   430,   460,   464,   465,   472,   492,   497,   504,
    1165,  1167,  1168,  1169,  1170,  1171,  1172,  1200,  1214,  1215,
    1226,  1228,  1229,  1230,  1231,   464,  1220,  1218,   731,   733,
     444,   257,  1259,   693,   453,  1227,    48,   467,   672,   673,
     674,   675,  1303,  1260,   197,   663,  1266,   506,  1179,     1,
     689,   790,   453,   806,   805,   377,   812,     3,     5,    10,
      18,    51,    52,    61,    72,    75,    89,   112,   120,   122,
     129,   131,   132,   133,   134,   135,   136,   137,   138,   140,
     141,   142,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   164,   169,   196,   203,   206,   207,   216,   223,
     225,   228,   270,   274,   276,   286,   312,   325,   350,   361,
     376,   382,   386,   394,   404,   413,   422,   427,   428,   431,
     433,   440,   453,   471,   477,   482,   509,  1250,   830,   846,
     851,   855,   860,   875,   878,   882,   888,   893,   907,   911,
     914,   928,   932,   935,   938,   204,   377,   869,   930,   943,
     947,   957,   960,   977,   979,   982,   400,   986,   992,  1004,
    1013,  1017,  1021,  1027,  1035,  1050,  1060,   257,   347,   388,
     417,   512,  1072,  1074,  1081,   337,  1085,  1087,   815,  1090,
    1093,  1097,  1124,   506,  1221,   715,   115,   717,   464,  1233,
    1215,  1226,  1228,  1310,  1310,   464,   464,   464,   464,  1310,
    1171,  1167,  1171,   464,  1233,    71,   399,   450,  1166,   451,
     460,   465,   452,   461,   170,   464,  1232,   464,   464,  1167,
     503,   734,  1302,  1225,  1191,  1191,   188,   664,  1221,   745,
     453,   791,   453,    49,   807,   808,   809,  1258,   807,   506,
     453,   309,   831,   832,  1214,     6,    95,   246,   272,   847,
    1172,  1196,  1197,  1214,  1225,  1228,   852,  1167,  1214,   257,
     856,   857,  1183,  1184,  1185,  1218,   272,   423,   425,   861,
     862,   257,   876,  1205,  1214,   879,  1178,     6,   883,  1173,
    1174,  1195,  1216,  1217,  1218,  1226,   456,   889,  1178,   257,
     894,   895,   897,  1196,  1197,  1205,  1214,   908,  1197,   257,
     912,   455,   466,   915,   916,   917,  1155,  1156,  1157,   200,
     324,   325,   341,   395,   929,   933,  1194,  1195,   936,  1218,
     448,   939,  1299,  1197,  1154,  1155,   948,  1194,   958,  1179,
     961,   962,  1214,  1225,  1228,  1051,  1212,  1213,  1218,    95,
     980,  1197,   983,  1197,   171,   226,   234,   318,   987,   988,
     191,   257,   993,   997,   998,   999,  1183,  1206,  1214,  1218,
    1228,  1303,  1005,  1178,  1014,  1175,  1218,  1018,  1178,  1022,
    1175,     9,  1028,  1176,  1218,   154,   272,  1036,  1039,  1040,
    1043,  1044,  1045,  1046,  1047,  1048,  1180,  1181,  1194,  1211,
    1213,  1218,  1051,  1061,  1178,  1069,   113,  1075,  1076,  1077,
    1197,    95,  1082,  1196,  1088,  1179,   453,   506,   816,   817,
     820,   821,   826,  1091,  1214,  1094,  1178,  1098,  1214,  1125,
    1175,   224,   719,   310,  1283,   720,   721,   450,  1165,  1167,
     506,   506,  1167,  1236,  1236,  1236,  1199,  1214,  1226,  1228,
    1235,   506,   450,  1199,  1234,  1167,   450,  1167,  1168,  1168,
    1169,  1169,  1169,  1167,  1199,  1165,   404,   455,    30,  1256,
    1260,     1,   746,   792,   808,   411,   478,   810,   358,   500,
     801,   131,   844,    30,   834,   835,  1256,   197,  1282,  1214,
    1215,  1226,  1228,   132,   849,   448,   848,  1197,    58,   224,
    1240,   857,   448,  1310,   133,   873,   257,  1206,  1205,  1178,
     357,   476,   880,  1303,  1316,  1282,   134,   884,   160,   454,
    1174,  1307,   387,  1246,  1219,  1220,   890,  1178,   135,   891,
    1288,   136,   905,   166,   896,  1134,  1135,   486,   898,   505,
     835,   487,   488,   489,   490,   137,   909,    49,   229,   499,
     863,   138,   926,    17,   503,   918,   919,   920,   922,    12,
      13,    14,    20,   160,   170,   208,   209,   247,   248,   285,
     291,   294,   302,   309,   314,   333,   450,   452,   454,   457,
     459,   460,   461,   464,   465,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1197,   102,   930,  1195,  1182,   443,  1297,   949,
    1303,  1179,    93,   366,   438,   963,   964,   966,   967,  1053,
     464,  1219,  1197,   448,   141,   984,    49,   988,   405,   989,
     998,   142,   453,   994,   996,   483,   501,   444,   447,   441,
     144,  1010,   286,   335,  1243,   197,  1126,   145,  1019,  1288,
     146,  1024,  1126,  1176,   147,  1033,   501,  1029,  1203,  1214,
    1226,  1046,  1048,  1194,   448,  1181,   124,   448,   484,  1038,
      31,  1219,   148,  1067,   178,   238,   241,  1063,   869,  1070,
    1303,  1258,   149,  1079,   229,  1077,  1214,   150,  1083,   197,
    1179,   395,   453,   453,   197,   352,   354,  1095,   151,  1107,
     113,  1099,   152,  1130,  1126,   720,  1187,   221,   723,    27,
     116,   722,   450,  1166,   450,   450,   450,  1166,   450,  1166,
     450,   450,   451,   450,   450,   448,  1272,  1191,   115,   662,
     453,    62,    90,    91,   322,   453,   747,   748,   751,  1272,
    1328,    32,    35,    38,    45,    46,    65,    67,   161,   190,
     197,   199,   212,   244,   253,   266,   306,   319,   346,   372,
     379,   396,   448,   458,   475,   499,   706,   707,   711,   726,
     728,   730,   793,   798,   799,  1272,  1305,  1272,   411,   313,
     811,   110,   813,  1203,   198,   838,   253,   332,   836,   837,
    1305,    24,    25,    66,    68,    70,   104,   105,   106,   154,
     156,   163,   166,   253,   255,   445,   495,   506,   833,  1181,
    1306,   153,   341,  1201,  1215,   448,     6,  1173,  1197,  1218,
    1226,   204,   224,  1241,   377,   853,   340,   858,  1185,   863,
     880,   263,   288,  1265,  1215,  1167,   273,  1247,  1220,  1178,
     232,  1150,  1151,   823,   824,   897,  1197,   295,  1136,    97,
     336,   506,  1181,   299,   902,    35,    38,    45,    46,    92,
     161,   190,   212,   266,   319,   379,   392,   475,   903,   904,
     486,   899,  1134,  1134,  1134,  1134,  1197,  1173,  1197,   864,
     917,    21,   455,   466,   923,   924,  1156,   503,   920,   921,
     503,   823,  1299,   233,  1159,   115,   940,  1183,   129,   823,
     944,     9,    12,    15,    16,   278,   279,   302,   303,   950,
     954,   176,  1203,     9,    58,   178,   242,   470,   970,   971,
     972,   965,   966,  1055,  1283,  1319,   448,  1194,  1173,  1197,
     989,  1303,  1177,   823,   169,  1000,  1154,  1001,  1002,  1214,
    1183,     8,    37,  1128,  1288,  1210,  1214,  1225,  1228,   229,
    1006,  1023,  1303,   130,  1030,  1214,  1030,   448,   448,  1037,
     153,   455,   466,  1197,    49,    38,    46,   212,   244,   266,
     319,   379,   475,  1041,  1042,  1272,  1062,  1303,  1197,   162,
     290,   411,  1197,  1214,   197,  1173,  1197,   822,  1221,  1203,
    1258,   229,  1102,  1127,  1128,   723,  1258,  1274,  1187,  1232,
    1232,  1232,  1199,   242,   470,  1232,   450,  1167,  1232,  1232,
    1225,  1283,  1272,  1272,  1253,   249,   250,  1277,   760,   205,
     177,   749,  1264,  1272,   253,   390,   157,   159,  1272,  1206,
     300,  1280,  1221,    57,  1214,  1214,   205,  1280,    32,   111,
    1221,  1272,   506,   453,   802,   273,   839,  1280,  1280,   837,
     836,  1280,   166,  1131,  1132,   511,   510,  1203,  1131,   238,
     424,   300,   277,   257,  1202,  1215,  1214,  1282,   412,  1137,
    1138,  1219,  1220,  1173,   448,  1242,   853,  1195,   448,  1183,
     868,   869,   381,   363,  1137,  1272,   823,   296,  1152,   825,
     823,  1134,  1272,   253,   390,   157,   159,  1272,   124,   484,
     904,  1134,    97,    98,   900,   839,   204,  1137,   204,   865,
     866,   867,  1258,    17,   444,   925,   317,   923,  1283,   823,
     129,   140,   945,  1299,   366,   951,  1299,   448,    49,   971,
     973,  1203,     9,    58,   242,   470,   968,   969,  1203,  1056,
    1304,   722,   219,   315,  1268,  1194,  1137,   204,  1177,   639,
     380,   990,  1303,   142,   995,     8,   197,  1006,  1214,   130,
    1143,  1145,  1150,   263,   288,   823,   503,   503,  1031,  1032,
    1203,  1202,  1197,  1037,  1037,  1037,  1037,  1037,  1037,  1037,
    1037,  1042,   291,   294,  1064,  1065,  1066,  1160,  1244,  1150,
     245,   411,  1318,   424,  1295,  1295,  1078,  1303,  1214,  1137,
     204,   453,   448,     9,  1100,  1101,  1238,  1103,  1214,  1078,
    1103,  1023,     7,  1251,   506,   724,   725,  1272,   450,  1187,
    1205,  1272,  1253,   257,   752,  1223,   688,   761,   750,  1214,
     512,  1207,  1211,  1221,  1207,  1272,  1298,  1272,  1272,    32,
    1221,   814,   815,  1272,   505,   840,  1207,  1207,  1207,   823,
     295,  1133,  1131,  1246,  1215,   823,   298,  1139,  1220,  1137,
    1204,  1214,  1225,   166,   463,   871,  1309,     6,   229,   309,
     462,   870,  1271,    34,   282,   283,   284,   345,   468,   469,
     473,  1248,   823,   826,  1207,  1207,  1153,  1209,  1211,  1221,
    1153,   505,   901,  1173,  1174,  1173,  1174,   866,   309,   810,
      88,   358,   500,   924,  1155,   823,  1214,   823,   500,   952,
     953,   954,   955,  1297,   500,  1204,  1203,    49,   974,   969,
     189,   974,  1052,  1272,  1274,   315,  1173,   990,   263,   288,
    1002,  1197,   218,  1007,  1303,   823,   292,  1146,   263,  1155,
    1154,  1031,  1160,  1214,  1161,  1162,  1163,  1164,  1167,  1071,
    1197,  1071,   463,  1140,  1141,   331,  1246,  1173,   818,  1204,
     314,  1203,   114,  1104,   438,  1106,   158,   293,  1129,  1147,
    1148,  1149,  1150,   322,  1181,  1207,   725,  1186,   753,   253,
     255,  1312,   506,   689,  1214,   271,   330,   460,   465,   794,
     795,   796,  1205,   794,   795,   797,   815,    47,    32,    35,
      38,    46,    92,   111,   190,   199,   212,   244,   264,   266,
     288,   289,   319,   346,   372,   379,   392,   396,   437,   446,
     475,   485,   491,   841,   842,   843,  1131,   823,  1137,   823,
     295,   872,   823,  1282,  1214,   253,   255,  1317,   903,  1137,
     362,  1137,   362,  1197,   953,   103,  1262,  1299,   974,   974,
    1204,     8,    37,   975,   226,   499,  1057,  1187,  1054,  1137,
     381,    49,   263,   238,  1008,   217,   237,   263,   288,   502,
     823,   823,   823,   823,   297,  1142,  1272,  1137,  1137,   494,
     819,  1108,  1101,  1267,    96,  1105,  1267,  1140,   823,   823,
    1149,   253,   255,  1276,   178,   188,   211,   241,   754,   755,
     756,   757,   758,   759,  1223,   762,  1207,  1207,   130,  1272,
    1272,   843,    57,   124,   484,     8,  1252,   842,   823,  1214,
    1174,  1174,    49,   111,   974,   458,  1270,  1270,   338,  1177,
     204,   318,  1058,  1218,  1197,  1272,  1009,  1144,  1145,  1146,
    1150,   263,   263,   263,   823,  1214,  1109,   453,  1214,  1267,
    1214,   107,   117,  1321,  1272,  1272,    55,    90,  1321,  1322,
    1306,   763,   110,  1207,  1207,  1272,  1153,  1153,  1208,  1211,
    1223,  1137,  1137,  1197,  1197,  1197,  1272,  1177,   338,   483,
    1214,  1146,   128,   167,   205,  1110,  1111,  1112,  1114,  1118,
    1120,  1121,  1122,  1256,  1265,  1214,  1272,  1223,  1223,   211,
    1272,  1272,   210,   253,   255,   286,   306,   334,   415,   432,
     453,   474,   493,   501,   706,   711,   712,   726,   728,   730,
     764,   765,   769,   770,   773,   774,   775,   776,   777,   778,
     783,   784,   785,  1305,  1306,   453,  1205,   997,  1272,  1154,
      37,  1252,   341,   108,  1223,  1223,  1223,   222,  1269,   300,
     301,  1281,  1253,   210,  1221,   503,  1272,  1282,  1272,  1272,
    1214,   287,   330,   779,   780,  1223,   330,   781,   782,  1223,
    1281,  1253,   997,   368,   419,  1294,   130,   422,  1119,  1283,
    1273,  1272,   715,  1154,  1200,  1198,  1200,    54,    90,   322,
     326,   327,   367,   383,   384,   766,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,   120,   197,  1221,   780,  1221,   782,  1273,
    1214,   162,   166,  1308,     9,  1115,  1116,  1184,   780,  1298,
    1246,   374,   771,  1200,   188,   188,   211,   188,   211,   177,
     767,  1214,   767,  1200,   338,  1286,   307,   339,   359,  1117,
    1116,   717,  1283,   314,   768,   768,    49,  1283,   307,  1218,
     426,   713,   177,   772,  1214,   322,  1200,   171,   226,   234,
     318,  1113,  1177,  1221
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
#line 1368 "parser.y"
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
#line 1379 "parser.y"
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
#line 1415 "parser.y"
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
#line 1470 "parser.y"
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
#line 1499 "parser.y"
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
#line 1532 "parser.y"
    {
	cb_validate_program_environment (current_program);
  ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 1538 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 1550 "parser.y"
    {
	cb_validate_program_data (current_program);
  ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 1560 "parser.y"
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
#line 1591 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 1598 "parser.y"
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
#line 1637 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 1638 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 1647 "parser.y"
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
#line 1656 "parser.y"
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
#line 1670 "parser.y"
    {
	current_program->flag_initial = 1;
  ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 1674 "parser.y"
    {
	current_program->flag_recursive = 1;
  ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 1684 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 1693 "parser.y"
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
#line 1718 "parser.y"
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
#line 1736 "parser.y"
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
#line 1749 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 1778 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1785 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 1792 "parser.y"
    {
	/* Ignore */
  ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1799 "parser.y"
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
#line 1810 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 1814 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 1818 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1822 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1836 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1841 "parser.y"
    {
	cobc_in_repository = 0;
  ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1849 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1861 "parser.y"
    {
	functions_are_all = 1;
  ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1865 "parser.y"
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
#line 1886 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1890 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1897 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1902 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1913 "parser.y"
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
#line 1927 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1958 "parser.y"
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
#line 1977 "parser.y"
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
#line 1987 "parser.y"
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
#line 2000 "parser.y"
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
#line 2016 "parser.y"
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
#line 2026 "parser.y"
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
#line 2041 "parser.y"
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
#line 2054 "parser.y"
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
#line 2065 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 2071 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 2077 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 2083 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 2089 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 2095 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 2105 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 2109 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 2116 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 2120 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 2124 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 2128 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 2135 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 2139 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 2145 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 2146 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 2147 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 2148 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 2149 "parser.y"
    { (yyval) = cb_norm_high; ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 2150 "parser.y"
    { (yyval) = cb_norm_low; ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 2158 "parser.y"
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
#line 2172 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 2176 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 2184 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 2191 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 2195 "parser.y"
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
#line 2206 "parser.y"
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
#line 2226 "parser.y"
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
#line 2234 "parser.y"
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
#line 2244 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 2245 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 2252 "parser.y"
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
#line 2272 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2273 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 2278 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 2282 "parser.y"
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
#line 2303 "parser.y"
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
#line 2326 "parser.y"
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
#line 2407 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2411 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 2420 "parser.y"
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
#line 2439 "parser.y"
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
#line 2455 "parser.y"
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
#line 2473 "parser.y"
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
#line 2491 "parser.y"
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
#line 2508 "parser.y"
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
#line 2525 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  ;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 2533 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  ;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 2542 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  ;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 2557 "parser.y"
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
#line 2574 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2578 "parser.y"
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
#line 2612 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2618 "parser.y"
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
#line 2628 "parser.y"
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
#line 2641 "parser.y"
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
#line 2654 "parser.y"
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
#line 2677 "parser.y"
    {
	current_file->flag_line_adv = 1;
  ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2684 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2697 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2709 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2716 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2717 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2718 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2726 "parser.y"
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
#line 2753 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2764 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2779 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 2787 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 2792 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 2797 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 2806 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 2810 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 2826 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 2831 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 2836 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 2841 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 2852 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 2863 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 2873 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 2880 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 2881 "parser.y"
    { PENDING ("SPLIT KEYS"); ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 2882 "parser.y"
    { PENDING ("SPLIT KEYS"); ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 2889 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 2900 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 2914 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 2921 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 2922 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 2923 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 2932 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 2951 "parser.y"
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
#line 2978 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 2979 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 2980 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 2981 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 2988 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 2993 "parser.y"
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
#line 3020 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3029 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3043 "parser.y"
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
#line 3062 "parser.y"
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
#line 3079 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3086 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3090 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3101 "parser.y"
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
#line 3111 "parser.y"
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
#line 3141 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3154 "parser.y"
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
#line 3174 "parser.y"
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
#line 3209 "parser.y"
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
#line 3240 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3246 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3247 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3251 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3252 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3260 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3271 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3276 "parser.y"
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
#line 3299 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3311 "parser.y"
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
#line 3339 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3346 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3353 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3362 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3374 "parser.y"
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
#line 3426 "parser.y"
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
#line 3446 "parser.y"
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
#line 3456 "parser.y"
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
#line 3496 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3502 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3511 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3514 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3520 "parser.y"
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
#line 3540 "parser.y"
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
#line 3555 "parser.y"
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
#line 3575 "parser.y"
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
#line 3588 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3595 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3601 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3607 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 3616 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 3625 "parser.y"
    {
	(yyval)= NULL;
  ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 3629 "parser.y"
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
#line 3640 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3641 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3642 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 3643 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 3648 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 3652 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 3656 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 3660 "parser.y"
    {
	(yyval) = cb_int4;
  ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 3664 "parser.y"
    {
	(yyval) = cb_int (8);
  ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 3668 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 3672 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 3676 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 3680 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 3684 "parser.y"
    {
	(yyval) = cb_int (4);
  ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 3688 "parser.y"
    {
	(yyval) = cb_int (8);
  ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 3692 "parser.y"
    {
	(yyval) = cb_int (16);
  ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 3696 "parser.y"
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
#line 3728 "parser.y"
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
#line 3754 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 3758 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 3766 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 3772 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 3800 "parser.y"
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
#line 3824 "parser.y"
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
#line 3851 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 3855 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 3864 "parser.y"
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
#line 3889 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 3905 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 3909 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 3913 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 3917 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 3921 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  ;}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 3925 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 3929 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 3933 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 3937 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 3941 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 3945 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 3949 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 3953 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 3958 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 3963 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 3967 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 3971 "parser.y"
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
#line 3979 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 3983 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 3987 "parser.y"
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
#line 3995 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 3999 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  ;}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 4003 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4007 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4011 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4015 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  ;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 4019 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4023 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  ;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 4027 "parser.y"
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
#line 4035 "parser.y"
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
#line 4043 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  ;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 4047 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  ;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 4051 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  ;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 4055 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  ;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 4059 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  ;}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 4063 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  ;}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 4083 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  ;}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 4089 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  ;}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 4102 "parser.y"
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
#line 4120 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 4130 "parser.y"
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
#line 4170 "parser.y"
    { (yyval) = NULL; }
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 4171 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 4175 "parser.y"
    { (yyval) = NULL; }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 4176 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 4181 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 4188 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(3) - (3)]), cb_zero, 0, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 4196 "parser.y"
    {
	/* current_field->initialized = 1; */
  }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 4203 "parser.y"
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

  case 469:

/* Line 1464 of yacc.c  */
#line 4226 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 4229 "parser.y"
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

  case 471:

/* Line 1464 of yacc.c  */
#line 4244 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); ;}
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 4245 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); ;}
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 4250 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 4256 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 4258 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 4263 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  ;}
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 4274 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  ;}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 4285 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  ;}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 4296 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  ;}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 4307 "parser.y"
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

  case 482:

/* Line 1464 of yacc.c  */
#line 4335 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 4343 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 4344 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 4348 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 4349 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 4354 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 4367 "parser.y"
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

  case 491:

/* Line 1464 of yacc.c  */
#line 4380 "parser.y"
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

  case 492:

/* Line 1464 of yacc.c  */
#line 4401 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  ;}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 4410 "parser.y"
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

  case 495:

/* Line 1464 of yacc.c  */
#line 4425 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  ;}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 4434 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 4446 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  ;}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 4452 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 4463 "parser.y"
    {
	cb_warning (_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field ();
  ;}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 4479 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  ;}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 4494 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 4501 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	cb_error (_("GLOBAL is not allowed with RD"));
  ;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 4506 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  ;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 4517 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  ;}
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 4536 "parser.y"
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

  case 519:

/* Line 1464 of yacc.c  */
#line 4572 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 4576 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
  ;}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 4581 "parser.y"
    {
	current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
  ;}
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 4601 "parser.y"
    {
	current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 4608 "parser.y"
    {
	current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 4615 "parser.y"
    {
	current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 4622 "parser.y"
    {
	current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 4629 "parser.y"
    {
	current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 4640 "parser.y"
    {
	check_pic_duplicate = 0;
  ;}
    break;

  case 556:

/* Line 1464 of yacc.c  */
#line 4671 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  ;}
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 4697 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  ;}
    break;

  case 570:

/* Line 1464 of yacc.c  */
#line 4704 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
  ;}
    break;

  case 575:

/* Line 1464 of yacc.c  */
#line 4720 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
  ;}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 4731 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
  ;}
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 4743 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  ;}
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 4776 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
  ;}
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 4783 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
  ;}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 4790 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  ;}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 4799 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  ;}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 4806 "parser.y"
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

  case 603:

/* Line 1464 of yacc.c  */
#line 4832 "parser.y"
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

  case 604:

/* Line 1464 of yacc.c  */
#line 4863 "parser.y"
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

  case 605:

/* Line 1464 of yacc.c  */
#line 4889 "parser.y"
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

  case 608:

/* Line 1464 of yacc.c  */
#line 4912 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  ;}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 4916 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  ;}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 4920 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  ;}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 4924 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  ;}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 4928 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  ;}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 4932 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  ;}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 4936 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 4940 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 4944 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  ;}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 4948 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 4952 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  ;}
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 4956 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 4960 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  ;}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 4964 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  ;}
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 4968 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  ;}
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 4972 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  ;}
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 4976 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 4981 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  ;}
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 4985 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  ;}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 4989 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  ;}
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 4994 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  ;}
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 4999 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 5004 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 639:

/* Line 1464 of yacc.c  */
#line 5017 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  ;}
    break;

  case 640:

/* Line 1464 of yacc.c  */
#line 5024 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 641:

/* Line 1464 of yacc.c  */
#line 5029 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  ;}
    break;

  case 646:

/* Line 1464 of yacc.c  */
#line 5048 "parser.y"
    {
	/* Nothing */
  ;}
    break;

  case 647:

/* Line 1464 of yacc.c  */
#line 5052 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  ;}
    break;

  case 648:

/* Line 1464 of yacc.c  */
#line 5056 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  ;}
    break;

  case 649:

/* Line 1464 of yacc.c  */
#line 5063 "parser.y"
    {
	/* Nothing */
  ;}
    break;

  case 650:

/* Line 1464 of yacc.c  */
#line 5067 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  ;}
    break;

  case 651:

/* Line 1464 of yacc.c  */
#line 5071 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  ;}
    break;

  case 652:

/* Line 1464 of yacc.c  */
#line 5079 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  ;}
    break;

  case 653:

/* Line 1464 of yacc.c  */
#line 5090 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  ;}
    break;

  case 655:

/* Line 1464 of yacc.c  */
#line 5099 "parser.y"
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

  case 656:

/* Line 1464 of yacc.c  */
#line 5109 "parser.y"
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

  case 657:

/* Line 1464 of yacc.c  */
#line 5121 "parser.y"
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

  case 658:

/* Line 1464 of yacc.c  */
#line 5136 "parser.y"
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

  case 660:

/* Line 1464 of yacc.c  */
#line 5169 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 661:

/* Line 1464 of yacc.c  */
#line 5173 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  ;}
    break;

  case 662:

/* Line 1464 of yacc.c  */
#line 5178 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 663:

/* Line 1464 of yacc.c  */
#line 5186 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  ;}
    break;

  case 664:

/* Line 1464 of yacc.c  */
#line 5195 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 665:

/* Line 1464 of yacc.c  */
#line 5205 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 666:

/* Line 1464 of yacc.c  */
#line 5207 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 667:

/* Line 1464 of yacc.c  */
#line 5212 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  ;}
    break;

  case 669:

/* Line 1464 of yacc.c  */
#line 5221 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  ;}
    break;

  case 670:

/* Line 1464 of yacc.c  */
#line 5225 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  ;}
    break;

  case 672:

/* Line 1464 of yacc.c  */
#line 5237 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  ;}
    break;

  case 673:

/* Line 1464 of yacc.c  */
#line 5245 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  ;}
    break;

  case 674:

/* Line 1464 of yacc.c  */
#line 5253 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  ;}
    break;

  case 675:

/* Line 1464 of yacc.c  */
#line 5261 "parser.y"
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

  case 676:

/* Line 1464 of yacc.c  */
#line 5290 "parser.y"
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

  case 678:

/* Line 1464 of yacc.c  */
#line 5323 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  ;}
    break;

  case 679:

/* Line 1464 of yacc.c  */
#line 5332 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  ;}
    break;

  case 680:

/* Line 1464 of yacc.c  */
#line 5338 "parser.y"
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

  case 682:

/* Line 1464 of yacc.c  */
#line 5366 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  ;}
    break;

  case 683:

/* Line 1464 of yacc.c  */
#line 5372 "parser.y"
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

  case 688:

/* Line 1464 of yacc.c  */
#line 5410 "parser.y"
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

  case 690:

/* Line 1464 of yacc.c  */
#line 5428 "parser.y"
    {
	/* check_unreached = 0; */
  ;}
    break;

  case 691:

/* Line 1464 of yacc.c  */
#line 5438 "parser.y"
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

  case 692:

/* Line 1464 of yacc.c  */
#line 5482 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  ;}
    break;

  case 695:

/* Line 1464 of yacc.c  */
#line 5493 "parser.y"
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

  case 696:

/* Line 1464 of yacc.c  */
#line 5541 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  ;}
    break;

  case 697:

/* Line 1464 of yacc.c  */
#line 5553 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 698:

/* Line 1464 of yacc.c  */
#line 5557 "parser.y"
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

  case 699:

/* Line 1464 of yacc.c  */
#line 5575 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  ;}
    break;

  case 700:

/* Line 1464 of yacc.c  */
#line 5580 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  ;}
    break;

  case 701:

/* Line 1464 of yacc.c  */
#line 5585 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  ;}
    break;

  case 702:

/* Line 1464 of yacc.c  */
#line 5593 "parser.y"
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

  case 703:

/* Line 1464 of yacc.c  */
#line 5620 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 704:

/* Line 1464 of yacc.c  */
#line 5624 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 754:

/* Line 1464 of yacc.c  */
#line 5680 "parser.y"
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

  case 755:

/* Line 1464 of yacc.c  */
#line 5694 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  ;}
    break;

  case 756:

/* Line 1464 of yacc.c  */
#line 5705 "parser.y"
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

  case 758:

/* Line 1464 of yacc.c  */
#line 5722 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  ;}
    break;

  case 759:

/* Line 1464 of yacc.c  */
#line 5727 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  ;}
    break;

  case 760:

/* Line 1464 of yacc.c  */
#line 5731 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  ;}
    break;

  case 761:

/* Line 1464 of yacc.c  */
#line 5735 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 762:

/* Line 1464 of yacc.c  */
#line 5740 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 763:

/* Line 1464 of yacc.c  */
#line 5745 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 764:

/* Line 1464 of yacc.c  */
#line 5750 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 765:

/* Line 1464 of yacc.c  */
#line 5755 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 766:

/* Line 1464 of yacc.c  */
#line 5759 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 767:

/* Line 1464 of yacc.c  */
#line 5763 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 768:

/* Line 1464 of yacc.c  */
#line 5767 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 769:

/* Line 1464 of yacc.c  */
#line 5771 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 770:

/* Line 1464 of yacc.c  */
#line 5776 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 771:

/* Line 1464 of yacc.c  */
#line 5780 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 772:

/* Line 1464 of yacc.c  */
#line 5784 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  ;}
    break;

  case 773:

/* Line 1464 of yacc.c  */
#line 5788 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 774:

/* Line 1464 of yacc.c  */
#line 5792 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 775:

/* Line 1464 of yacc.c  */
#line 5796 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 776:

/* Line 1464 of yacc.c  */
#line 5800 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 778:

/* Line 1464 of yacc.c  */
#line 5808 "parser.y"
    {
	(yyval) = cb_null;
  ;}
    break;

  case 781:

/* Line 1464 of yacc.c  */
#line 5819 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 782:

/* Line 1464 of yacc.c  */
#line 5820 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 783:

/* Line 1464 of yacc.c  */
#line 5824 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 784:

/* Line 1464 of yacc.c  */
#line 5825 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 785:

/* Line 1464 of yacc.c  */
#line 5826 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); ;}
    break;

  case 786:

/* Line 1464 of yacc.c  */
#line 5827 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); ;}
    break;

  case 787:

/* Line 1464 of yacc.c  */
#line 5828 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 788:

/* Line 1464 of yacc.c  */
#line 5832 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 789:

/* Line 1464 of yacc.c  */
#line 5836 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 790:

/* Line 1464 of yacc.c  */
#line 5837 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 794:

/* Line 1464 of yacc.c  */
#line 5846 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 799:

/* Line 1464 of yacc.c  */
#line 5862 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  ;}
    break;

  case 800:

/* Line 1464 of yacc.c  */
#line 5866 "parser.y"
    {
	if (cb_accept_auto) {
		remove_attrib (COB_SCREEN_AUTO);
	}
  ;}
    break;

  case 801:

/* Line 1464 of yacc.c  */
#line 5872 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  ;}
    break;

  case 802:

/* Line 1464 of yacc.c  */
#line 5876 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  ;}
    break;

  case 803:

/* Line 1464 of yacc.c  */
#line 5880 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  ;}
    break;

  case 804:

/* Line 1464 of yacc.c  */
#line 5884 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  ;}
    break;

  case 805:

/* Line 1464 of yacc.c  */
#line 5888 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 806:

/* Line 1464 of yacc.c  */
#line 5892 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 807:

/* Line 1464 of yacc.c  */
#line 5896 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  ;}
    break;

  case 808:

/* Line 1464 of yacc.c  */
#line 5900 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 809:

/* Line 1464 of yacc.c  */
#line 5904 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  ;}
    break;

  case 810:

/* Line 1464 of yacc.c  */
#line 5908 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  ;}
    break;

  case 811:

/* Line 1464 of yacc.c  */
#line 5912 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  ;}
    break;

  case 812:

/* Line 1464 of yacc.c  */
#line 5916 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  ;}
    break;

  case 813:

/* Line 1464 of yacc.c  */
#line 5920 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  ;}
    break;

  case 814:

/* Line 1464 of yacc.c  */
#line 5924 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  ;}
    break;

  case 815:

/* Line 1464 of yacc.c  */
#line 5928 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  ;}
    break;

  case 816:

/* Line 1464 of yacc.c  */
#line 5932 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 817:

/* Line 1464 of yacc.c  */
#line 5936 "parser.y"
    {
	if (cb_accept_update) {
		remove_attrib (COB_SCREEN_UPDATE);
	}
  ;}
    break;

  case 818:

/* Line 1464 of yacc.c  */
#line 5942 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  ;}
    break;

  case 819:

/* Line 1464 of yacc.c  */
#line 5946 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  ;}
    break;

  case 820:

/* Line 1464 of yacc.c  */
#line 5950 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  ;}
    break;

  case 821:

/* Line 1464 of yacc.c  */
#line 5954 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  ;}
    break;

  case 822:

/* Line 1464 of yacc.c  */
#line 5958 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  ;}
    break;

  case 823:

/* Line 1464 of yacc.c  */
#line 5962 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  ;}
    break;

  case 824:

/* Line 1464 of yacc.c  */
#line 5966 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  ;}
    break;

  case 827:

/* Line 1464 of yacc.c  */
#line 5978 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  ;}
    break;

  case 828:

/* Line 1464 of yacc.c  */
#line 5982 "parser.y"
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

  case 829:

/* Line 1464 of yacc.c  */
#line 5999 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  ;}
    break;

  case 831:

/* Line 1464 of yacc.c  */
#line 6008 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  ;}
    break;

  case 832:

/* Line 1464 of yacc.c  */
#line 6012 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  ;}
    break;

  case 833:

/* Line 1464 of yacc.c  */
#line 6016 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 835:

/* Line 1464 of yacc.c  */
#line 6023 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 836:

/* Line 1464 of yacc.c  */
#line 6030 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  ;}
    break;

  case 837:

/* Line 1464 of yacc.c  */
#line 6034 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  ;}
    break;

  case 838:

/* Line 1464 of yacc.c  */
#line 6044 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  ;}
    break;

  case 840:

/* Line 1464 of yacc.c  */
#line 6053 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  ;}
    break;

  case 841:

/* Line 1464 of yacc.c  */
#line 6057 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  ;}
    break;

  case 842:

/* Line 1464 of yacc.c  */
#line 6068 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 843:

/* Line 1464 of yacc.c  */
#line 6069 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 844:

/* Line 1464 of yacc.c  */
#line 6077 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  ;}
    break;

  case 848:

/* Line 1464 of yacc.c  */
#line 6091 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 851:

/* Line 1464 of yacc.c  */
#line 6103 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  ;}
    break;

  case 853:

/* Line 1464 of yacc.c  */
#line 6118 "parser.y"
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

  case 854:

/* Line 1464 of yacc.c  */
#line 6132 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  ;}
    break;

  case 855:

/* Line 1464 of yacc.c  */
#line 6137 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  ;}
    break;

  case 856:

/* Line 1464 of yacc.c  */
#line 6142 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  ;}
    break;

  case 857:

/* Line 1464 of yacc.c  */
#line 6147 "parser.y"
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

  case 858:

/* Line 1464 of yacc.c  */
#line 6167 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 859:

/* Line 1464 of yacc.c  */
#line 6171 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  ;}
    break;

  case 860:

/* Line 1464 of yacc.c  */
#line 6176 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 861:

/* Line 1464 of yacc.c  */
#line 6187 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 862:

/* Line 1464 of yacc.c  */
#line 6189 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 863:

/* Line 1464 of yacc.c  */
#line 6194 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  ;}
    break;

  case 864:

/* Line 1464 of yacc.c  */
#line 6202 "parser.y"
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

  case 866:

/* Line 1464 of yacc.c  */
#line 6228 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  ;}
    break;

  case 867:

/* Line 1464 of yacc.c  */
#line 6232 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  ;}
    break;

  case 868:

/* Line 1464 of yacc.c  */
#line 6241 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  ;}
    break;

  case 869:

/* Line 1464 of yacc.c  */
#line 6253 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 870:

/* Line 1464 of yacc.c  */
#line 6257 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 871:

/* Line 1464 of yacc.c  */
#line 6261 "parser.y"
    {
	(yyval) = cb_null;
  ;}
    break;

  case 872:

/* Line 1464 of yacc.c  */
#line 6265 "parser.y"
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

  case 877:

/* Line 1464 of yacc.c  */
#line 6298 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 878:

/* Line 1464 of yacc.c  */
#line 6303 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 879:

/* Line 1464 of yacc.c  */
#line 6310 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 880:

/* Line 1464 of yacc.c  */
#line 6315 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 881:

/* Line 1464 of yacc.c  */
#line 6322 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  ;}
    break;

  case 882:

/* Line 1464 of yacc.c  */
#line 6326 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  ;}
    break;

  case 883:

/* Line 1464 of yacc.c  */
#line 6336 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  ;}
    break;

  case 885:

/* Line 1464 of yacc.c  */
#line 6344 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 886:

/* Line 1464 of yacc.c  */
#line 6348 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 887:

/* Line 1464 of yacc.c  */
#line 6358 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  ;}
    break;

  case 889:

/* Line 1464 of yacc.c  */
#line 6366 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 890:

/* Line 1464 of yacc.c  */
#line 6371 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 891:

/* Line 1464 of yacc.c  */
#line 6378 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); ;}
    break;

  case 892:

/* Line 1464 of yacc.c  */
#line 6379 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); ;}
    break;

  case 893:

/* Line 1464 of yacc.c  */
#line 6380 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); ;}
    break;

  case 894:

/* Line 1464 of yacc.c  */
#line 6381 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); ;}
    break;

  case 895:

/* Line 1464 of yacc.c  */
#line 6382 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); ;}
    break;

  case 896:

/* Line 1464 of yacc.c  */
#line 6390 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  ;}
    break;

  case 898:

/* Line 1464 of yacc.c  */
#line 6399 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  ;}
    break;

  case 899:

/* Line 1464 of yacc.c  */
#line 6406 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  ;}
    break;

  case 900:

/* Line 1464 of yacc.c  */
#line 6410 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  ;}
    break;

  case 901:

/* Line 1464 of yacc.c  */
#line 6420 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  ;}
    break;

  case 902:

/* Line 1464 of yacc.c  */
#line 6431 "parser.y"
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

  case 903:

/* Line 1464 of yacc.c  */
#line 6448 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  ;}
    break;

  case 905:

/* Line 1464 of yacc.c  */
#line 6457 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 907:

/* Line 1464 of yacc.c  */
#line 6465 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 908:

/* Line 1464 of yacc.c  */
#line 6470 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 909:

/* Line 1464 of yacc.c  */
#line 6478 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  ;}
    break;

  case 910:

/* Line 1464 of yacc.c  */
#line 6482 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  ;}
    break;

  case 911:

/* Line 1464 of yacc.c  */
#line 6492 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  ;}
    break;

  case 913:

/* Line 1464 of yacc.c  */
#line 6502 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 914:

/* Line 1464 of yacc.c  */
#line 6506 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 915:

/* Line 1464 of yacc.c  */
#line 6510 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 916:

/* Line 1464 of yacc.c  */
#line 6514 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 917:

/* Line 1464 of yacc.c  */
#line 6518 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  ;}
    break;

  case 919:

/* Line 1464 of yacc.c  */
#line 6523 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  ;}
    break;

  case 921:

/* Line 1464 of yacc.c  */
#line 6533 "parser.y"
    {
	begin_implicit_statement ();
  ;}
    break;

  case 923:

/* Line 1464 of yacc.c  */
#line 6541 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  ;}
    break;

  case 924:

/* Line 1464 of yacc.c  */
#line 6549 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 925:

/* Line 1464 of yacc.c  */
#line 6557 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 926:

/* Line 1464 of yacc.c  */
#line 6561 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 927:

/* Line 1464 of yacc.c  */
#line 6565 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 928:

/* Line 1464 of yacc.c  */
#line 6569 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 934:

/* Line 1464 of yacc.c  */
#line 6591 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 935:

/* Line 1464 of yacc.c  */
#line 6597 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 936:

/* Line 1464 of yacc.c  */
#line 6598 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 939:

/* Line 1464 of yacc.c  */
#line 6609 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  ;}
    break;

  case 940:

/* Line 1464 of yacc.c  */
#line 6613 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  ;}
    break;

  case 941:

/* Line 1464 of yacc.c  */
#line 6617 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  ;}
    break;

  case 942:

/* Line 1464 of yacc.c  */
#line 6621 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  ;}
    break;

  case 943:

/* Line 1464 of yacc.c  */
#line 6625 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  ;}
    break;

  case 944:

/* Line 1464 of yacc.c  */
#line 6629 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  ;}
    break;

  case 945:

/* Line 1464 of yacc.c  */
#line 6633 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  ;}
    break;

  case 946:

/* Line 1464 of yacc.c  */
#line 6637 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 947:

/* Line 1464 of yacc.c  */
#line 6641 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 948:

/* Line 1464 of yacc.c  */
#line 6645 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  ;}
    break;

  case 949:

/* Line 1464 of yacc.c  */
#line 6649 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  ;}
    break;

  case 950:

/* Line 1464 of yacc.c  */
#line 6653 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 951:

/* Line 1464 of yacc.c  */
#line 6657 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  ;}
    break;

  case 952:

/* Line 1464 of yacc.c  */
#line 6661 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  ;}
    break;

  case 953:

/* Line 1464 of yacc.c  */
#line 6665 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  ;}
    break;

  case 954:

/* Line 1464 of yacc.c  */
#line 6669 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  ;}
    break;

  case 955:

/* Line 1464 of yacc.c  */
#line 6676 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  ;}
    break;

  case 956:

/* Line 1464 of yacc.c  */
#line 6680 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  ;}
    break;

  case 957:

/* Line 1464 of yacc.c  */
#line 6690 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  ;}
    break;

  case 959:

/* Line 1464 of yacc.c  */
#line 6699 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  ;}
    break;

  case 960:

/* Line 1464 of yacc.c  */
#line 6703 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  ;}
    break;

  case 961:

/* Line 1464 of yacc.c  */
#line 6707 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  ;}
    break;

  case 962:

/* Line 1464 of yacc.c  */
#line 6711 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  ;}
    break;

  case 963:

/* Line 1464 of yacc.c  */
#line 6715 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  ;}
    break;

  case 964:

/* Line 1464 of yacc.c  */
#line 6722 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  ;}
    break;

  case 965:

/* Line 1464 of yacc.c  */
#line 6726 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  ;}
    break;

  case 966:

/* Line 1464 of yacc.c  */
#line 6736 "parser.y"
    {
	check_unreached = 0;
	begin_statement ("ENTRY", 0);
  ;}
    break;

  case 968:

/* Line 1464 of yacc.c  */
#line 6745 "parser.y"
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
  ;}
    break;

  case 969:

/* Line 1464 of yacc.c  */
#line 6763 "parser.y"
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

  case 971:

/* Line 1464 of yacc.c  */
#line 6787 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  ;}
    break;

  case 972:

/* Line 1464 of yacc.c  */
#line 6794 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 973:

/* Line 1464 of yacc.c  */
#line 6796 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 974:

/* Line 1464 of yacc.c  */
#line 6801 "parser.y"
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

  case 975:

/* Line 1464 of yacc.c  */
#line 6812 "parser.y"
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

  case 976:

/* Line 1464 of yacc.c  */
#line 6823 "parser.y"
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

  case 977:

/* Line 1464 of yacc.c  */
#line 6837 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 978:

/* Line 1464 of yacc.c  */
#line 6841 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 979:

/* Line 1464 of yacc.c  */
#line 6847 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 980:

/* Line 1464 of yacc.c  */
#line 6849 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 981:

/* Line 1464 of yacc.c  */
#line 6855 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  ;}
    break;

  case 982:

/* Line 1464 of yacc.c  */
#line 6864 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  ;}
    break;

  case 983:

/* Line 1464 of yacc.c  */
#line 6872 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  ;}
    break;

  case 984:

/* Line 1464 of yacc.c  */
#line 6878 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  ;}
    break;

  case 985:

/* Line 1464 of yacc.c  */
#line 6885 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 986:

/* Line 1464 of yacc.c  */
#line 6887 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 987:

/* Line 1464 of yacc.c  */
#line 6892 "parser.y"
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

  case 988:

/* Line 1464 of yacc.c  */
#line 6953 "parser.y"
    { (yyval) = cb_any; eval_inc2++; ;}
    break;

  case 989:

/* Line 1464 of yacc.c  */
#line 6954 "parser.y"
    { (yyval) = cb_true; eval_inc2++; ;}
    break;

  case 990:

/* Line 1464 of yacc.c  */
#line 6955 "parser.y"
    { (yyval) = cb_false; eval_inc2++; ;}
    break;

  case 991:

/* Line 1464 of yacc.c  */
#line 6959 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 992:

/* Line 1464 of yacc.c  */
#line 6960 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 993:

/* Line 1464 of yacc.c  */
#line 6965 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  ;}
    break;

  case 994:

/* Line 1464 of yacc.c  */
#line 6969 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  ;}
    break;

  case 995:

/* Line 1464 of yacc.c  */
#line 6979 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  ;}
    break;

  case 996:

/* Line 1464 of yacc.c  */
#line 6984 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 998:

/* Line 1464 of yacc.c  */
#line 6992 "parser.y"
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

  case 999:

/* Line 1464 of yacc.c  */
#line 7013 "parser.y"
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

  case 1000:

/* Line 1464 of yacc.c  */
#line 7027 "parser.y"
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

  case 1001:

/* Line 1464 of yacc.c  */
#line 7049 "parser.y"
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

  case 1002:

/* Line 1464 of yacc.c  */
#line 7071 "parser.y"
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

  case 1003:

/* Line 1464 of yacc.c  */
#line 7091 "parser.y"
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

  case 1004:

/* Line 1464 of yacc.c  */
#line 7113 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1005:

/* Line 1464 of yacc.c  */
#line 7114 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1006:

/* Line 1464 of yacc.c  */
#line 7122 "parser.y"
    {
	begin_statement ("FREE", 0);
	current_statement->flag_no_based = 1;
  ;}
    break;

  case 1008:

/* Line 1464 of yacc.c  */
#line 7131 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1009:

/* Line 1464 of yacc.c  */
#line 7141 "parser.y"
    {
	begin_statement ("GENERATE", 0);
	PENDING("GENERATE");
  ;}
    break;

  case 1012:

/* Line 1464 of yacc.c  */
#line 7157 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1014:

/* Line 1464 of yacc.c  */
#line 7170 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  ;}
    break;

  case 1015:

/* Line 1464 of yacc.c  */
#line 7178 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  ;}
    break;

  case 1016:

/* Line 1464 of yacc.c  */
#line 7183 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1017:

/* Line 1464 of yacc.c  */
#line 7194 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	if ((yyvsp[(2) - (2)]) != NULL) {
		cb_emit_move ((yyvsp[(2) - (2)]), CB_LIST_INIT (current_program->cb_return_code));
	}
	cb_emit_exit (1U);
  ;}
    break;

  case 1018:

/* Line 1464 of yacc.c  */
#line 7209 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  ;}
    break;

  case 1020:

/* Line 1464 of yacc.c  */
#line 7218 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1021:

/* Line 1464 of yacc.c  */
#line 7222 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1022:

/* Line 1464 of yacc.c  */
#line 7226 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  ;}
    break;

  case 1023:

/* Line 1464 of yacc.c  */
#line 7233 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  ;}
    break;

  case 1024:

/* Line 1464 of yacc.c  */
#line 7237 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  ;}
    break;

  case 1025:

/* Line 1464 of yacc.c  */
#line 7247 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  ;}
    break;

  case 1027:

/* Line 1464 of yacc.c  */
#line 7256 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 1028:

/* Line 1464 of yacc.c  */
#line 7262 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1029:

/* Line 1464 of yacc.c  */
#line 7263 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1030:

/* Line 1464 of yacc.c  */
#line 7267 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1031:

/* Line 1464 of yacc.c  */
#line 7268 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1032:

/* Line 1464 of yacc.c  */
#line 7269 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 1033:

/* Line 1464 of yacc.c  */
#line 7274 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1034:

/* Line 1464 of yacc.c  */
#line 7278 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1035:

/* Line 1464 of yacc.c  */
#line 7285 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1036:

/* Line 1464 of yacc.c  */
#line 7290 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1037:

/* Line 1464 of yacc.c  */
#line 7297 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1038:

/* Line 1464 of yacc.c  */
#line 7303 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); ;}
    break;

  case 1039:

/* Line 1464 of yacc.c  */
#line 7304 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); ;}
    break;

  case 1040:

/* Line 1464 of yacc.c  */
#line 7305 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); ;}
    break;

  case 1041:

/* Line 1464 of yacc.c  */
#line 7306 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); ;}
    break;

  case 1042:

/* Line 1464 of yacc.c  */
#line 7307 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); ;}
    break;

  case 1043:

/* Line 1464 of yacc.c  */
#line 7308 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); ;}
    break;

  case 1044:

/* Line 1464 of yacc.c  */
#line 7309 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); ;}
    break;

  case 1045:

/* Line 1464 of yacc.c  */
#line 7314 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1046:

/* Line 1464 of yacc.c  */
#line 7318 "parser.y"
    {
	(yyval) = cb_true;
  ;}
    break;

  case 1047:

/* Line 1464 of yacc.c  */
#line 7327 "parser.y"
    {
	begin_statement ("INITIATE", 0);
	PENDING("INITIATE");
  ;}
    break;

  case 1049:

/* Line 1464 of yacc.c  */
#line 7336 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  ;}
    break;

  case 1050:

/* Line 1464 of yacc.c  */
#line 7342 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  ;}
    break;

  case 1051:

/* Line 1464 of yacc.c  */
#line 7353 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  ;}
    break;

  case 1054:

/* Line 1464 of yacc.c  */
#line 7366 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1055:

/* Line 1464 of yacc.c  */
#line 7370 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1056:

/* Line 1464 of yacc.c  */
#line 7374 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1061:

/* Line 1464 of yacc.c  */
#line 7390 "parser.y"
    {
	cb_init_tallying ();
  ;}
    break;

  case 1062:

/* Line 1464 of yacc.c  */
#line 7394 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  ;}
    break;

  case 1063:

/* Line 1464 of yacc.c  */
#line 7404 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  ;}
    break;

  case 1064:

/* Line 1464 of yacc.c  */
#line 7414 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  ;}
    break;

  case 1065:

/* Line 1464 of yacc.c  */
#line 7422 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1066:

/* Line 1464 of yacc.c  */
#line 7423 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1067:

/* Line 1464 of yacc.c  */
#line 7427 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); ;}
    break;

  case 1068:

/* Line 1464 of yacc.c  */
#line 7428 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); ;}
    break;

  case 1069:

/* Line 1464 of yacc.c  */
#line 7429 "parser.y"
    { (yyval) = cb_build_tallying_all (); ;}
    break;

  case 1070:

/* Line 1464 of yacc.c  */
#line 7430 "parser.y"
    { (yyval) = cb_build_tallying_leading (); ;}
    break;

  case 1071:

/* Line 1464 of yacc.c  */
#line 7431 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); ;}
    break;

  case 1072:

/* Line 1464 of yacc.c  */
#line 7432 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1073:

/* Line 1464 of yacc.c  */
#line 7436 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1074:

/* Line 1464 of yacc.c  */
#line 7437 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1075:

/* Line 1464 of yacc.c  */
#line 7442 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  ;}
    break;

  case 1076:

/* Line 1464 of yacc.c  */
#line 7447 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1077:

/* Line 1464 of yacc.c  */
#line 7453 "parser.y"
    { /* Nothing */ ;}
    break;

  case 1078:

/* Line 1464 of yacc.c  */
#line 7454 "parser.y"
    { inspect_keyword = 1; ;}
    break;

  case 1079:

/* Line 1464 of yacc.c  */
#line 7455 "parser.y"
    { inspect_keyword = 2; ;}
    break;

  case 1080:

/* Line 1464 of yacc.c  */
#line 7456 "parser.y"
    { inspect_keyword = 3; ;}
    break;

  case 1081:

/* Line 1464 of yacc.c  */
#line 7457 "parser.y"
    { inspect_keyword = 4; ;}
    break;

  case 1082:

/* Line 1464 of yacc.c  */
#line 7462 "parser.y"
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

  case 1083:

/* Line 1464 of yacc.c  */
#line 7489 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  ;}
    break;

  case 1084:

/* Line 1464 of yacc.c  */
#line 7493 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1085:

/* Line 1464 of yacc.c  */
#line 7500 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  ;}
    break;

  case 1086:

/* Line 1464 of yacc.c  */
#line 7504 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  ;}
    break;

  case 1087:

/* Line 1464 of yacc.c  */
#line 7513 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  ;}
    break;

  case 1089:

/* Line 1464 of yacc.c  */
#line 7525 "parser.y"
    {
	begin_statement ("MOVE", 0);
  ;}
    break;

  case 1091:

/* Line 1464 of yacc.c  */
#line 7533 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1092:

/* Line 1464 of yacc.c  */
#line 7537 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1093:

/* Line 1464 of yacc.c  */
#line 7547 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  ;}
    break;

  case 1095:

/* Line 1464 of yacc.c  */
#line 7556 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  ;}
    break;

  case 1096:

/* Line 1464 of yacc.c  */
#line 7560 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  ;}
    break;

  case 1097:

/* Line 1464 of yacc.c  */
#line 7567 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  ;}
    break;

  case 1098:

/* Line 1464 of yacc.c  */
#line 7571 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  ;}
    break;

  case 1099:

/* Line 1464 of yacc.c  */
#line 7581 "parser.y"
    {
	begin_statement ("OPEN", 0);
  ;}
    break;

  case 1101:

/* Line 1464 of yacc.c  */
#line 7589 "parser.y"
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

  case 1102:

/* Line 1464 of yacc.c  */
#line 7610 "parser.y"
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

  case 1103:

/* Line 1464 of yacc.c  */
#line 7633 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); ;}
    break;

  case 1104:

/* Line 1464 of yacc.c  */
#line 7634 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); ;}
    break;

  case 1105:

/* Line 1464 of yacc.c  */
#line 7635 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); ;}
    break;

  case 1106:

/* Line 1464 of yacc.c  */
#line 7636 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); ;}
    break;

  case 1107:

/* Line 1464 of yacc.c  */
#line 7640 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1108:

/* Line 1464 of yacc.c  */
#line 7641 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1109:

/* Line 1464 of yacc.c  */
#line 7645 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1110:

/* Line 1464 of yacc.c  */
#line 7646 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1111:

/* Line 1464 of yacc.c  */
#line 7647 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); ;}
    break;

  case 1112:

/* Line 1464 of yacc.c  */
#line 7649 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  ;}
    break;

  case 1113:

/* Line 1464 of yacc.c  */
#line 7660 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1115:

/* Line 1464 of yacc.c  */
#line 7671 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  ;}
    break;

  case 1116:

/* Line 1464 of yacc.c  */
#line 7676 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  ;}
    break;

  case 1117:

/* Line 1464 of yacc.c  */
#line 7682 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1118:

/* Line 1464 of yacc.c  */
#line 7687 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  ;}
    break;

  case 1119:

/* Line 1464 of yacc.c  */
#line 7695 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  ;}
    break;

  case 1120:

/* Line 1464 of yacc.c  */
#line 7703 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  ;}
    break;

  case 1121:

/* Line 1464 of yacc.c  */
#line 7710 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  ;}
    break;

  case 1122:

/* Line 1464 of yacc.c  */
#line 7714 "parser.y"
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

  case 1123:

/* Line 1464 of yacc.c  */
#line 7727 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 1124:

/* Line 1464 of yacc.c  */
#line 7734 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1125:

/* Line 1464 of yacc.c  */
#line 7745 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  ;}
    break;

  case 1126:

/* Line 1464 of yacc.c  */
#line 7749 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  ;}
    break;

  case 1127:

/* Line 1464 of yacc.c  */
#line 7754 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  ;}
    break;

  case 1128:

/* Line 1464 of yacc.c  */
#line 7758 "parser.y"
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

  case 1129:

/* Line 1464 of yacc.c  */
#line 7769 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1130:

/* Line 1464 of yacc.c  */
#line 7775 "parser.y"
    { (yyval) = CB_BEFORE; ;}
    break;

  case 1131:

/* Line 1464 of yacc.c  */
#line 7776 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1132:

/* Line 1464 of yacc.c  */
#line 7780 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1133:

/* Line 1464 of yacc.c  */
#line 7781 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1134:

/* Line 1464 of yacc.c  */
#line 7784 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1135:

/* Line 1464 of yacc.c  */
#line 7786 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 1136:

/* Line 1464 of yacc.c  */
#line 7791 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  ;}
    break;

  case 1137:

/* Line 1464 of yacc.c  */
#line 7801 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  ;}
    break;

  case 1139:

/* Line 1464 of yacc.c  */
#line 7810 "parser.y"
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

  case 1140:

/* Line 1464 of yacc.c  */
#line 7836 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1141:

/* Line 1464 of yacc.c  */
#line 7837 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1142:

/* Line 1464 of yacc.c  */
#line 7842 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1143:

/* Line 1464 of yacc.c  */
#line 7846 "parser.y"
    {
	(yyval) = cb_int3;
  ;}
    break;

  case 1144:

/* Line 1464 of yacc.c  */
#line 7850 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1145:

/* Line 1464 of yacc.c  */
#line 7854 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1146:

/* Line 1464 of yacc.c  */
#line 7858 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 1147:

/* Line 1464 of yacc.c  */
#line 7862 "parser.y"
    {
	(yyval) = cb_int3;
  ;}
    break;

  case 1148:

/* Line 1464 of yacc.c  */
#line 7866 "parser.y"
    {
	(yyval) = cb_int4;
  ;}
    break;

  case 1149:

/* Line 1464 of yacc.c  */
#line 7872 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1150:

/* Line 1464 of yacc.c  */
#line 7873 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1153:

/* Line 1464 of yacc.c  */
#line 7883 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  ;}
    break;

  case 1154:

/* Line 1464 of yacc.c  */
#line 7887 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  ;}
    break;

  case 1155:

/* Line 1464 of yacc.c  */
#line 7897 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  ;}
    break;

  case 1156:

/* Line 1464 of yacc.c  */
#line 7907 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  ;}
    break;

  case 1158:

/* Line 1464 of yacc.c  */
#line 7915 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1159:

/* Line 1464 of yacc.c  */
#line 7925 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  ;}
    break;

  case 1160:

/* Line 1464 of yacc.c  */
#line 7935 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  ;}
    break;

  case 1162:

/* Line 1464 of yacc.c  */
#line 7944 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1163:

/* Line 1464 of yacc.c  */
#line 7951 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  ;}
    break;

  case 1164:

/* Line 1464 of yacc.c  */
#line 7955 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  ;}
    break;

  case 1165:

/* Line 1464 of yacc.c  */
#line 7965 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1167:

/* Line 1464 of yacc.c  */
#line 7977 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  ;}
    break;

  case 1168:

/* Line 1464 of yacc.c  */
#line 7985 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1169:

/* Line 1464 of yacc.c  */
#line 7989 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1170:

/* Line 1464 of yacc.c  */
#line 7993 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 1171:

/* Line 1464 of yacc.c  */
#line 8000 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  ;}
    break;

  case 1172:

/* Line 1464 of yacc.c  */
#line 8004 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  ;}
    break;

  case 1173:

/* Line 1464 of yacc.c  */
#line 8014 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  ;}
    break;

  case 1174:

/* Line 1464 of yacc.c  */
#line 8025 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  ;}
    break;

  case 1176:

/* Line 1464 of yacc.c  */
#line 8034 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1177:

/* Line 1464 of yacc.c  */
#line 8039 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  ;}
    break;

  case 1178:

/* Line 1464 of yacc.c  */
#line 8046 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1179:

/* Line 1464 of yacc.c  */
#line 8047 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1180:

/* Line 1464 of yacc.c  */
#line 8052 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1181:

/* Line 1464 of yacc.c  */
#line 8057 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1182:

/* Line 1464 of yacc.c  */
#line 8064 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1183:

/* Line 1464 of yacc.c  */
#line 8068 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 1184:

/* Line 1464 of yacc.c  */
#line 8076 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1185:

/* Line 1464 of yacc.c  */
#line 8083 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  ;}
    break;

  case 1186:

/* Line 1464 of yacc.c  */
#line 8087 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  ;}
    break;

  case 1187:

/* Line 1464 of yacc.c  */
#line 8097 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  ;}
    break;

  case 1188:

/* Line 1464 of yacc.c  */
#line 8104 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 1195:

/* Line 1464 of yacc.c  */
#line 8119 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1196:

/* Line 1464 of yacc.c  */
#line 8120 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1197:

/* Line 1464 of yacc.c  */
#line 8124 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1198:

/* Line 1464 of yacc.c  */
#line 8125 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1199:

/* Line 1464 of yacc.c  */
#line 8132 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1200:

/* Line 1464 of yacc.c  */
#line 8141 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  ;}
    break;

  case 1203:

/* Line 1464 of yacc.c  */
#line 8153 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  ;}
    break;

  case 1204:

/* Line 1464 of yacc.c  */
#line 8157 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  ;}
    break;

  case 1205:

/* Line 1464 of yacc.c  */
#line 8161 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 1206:

/* Line 1464 of yacc.c  */
#line 8165 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 1207:

/* Line 1464 of yacc.c  */
#line 8169 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  ;}
    break;

  case 1208:

/* Line 1464 of yacc.c  */
#line 8173 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 1209:

/* Line 1464 of yacc.c  */
#line 8177 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 1210:

/* Line 1464 of yacc.c  */
#line 8181 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  ;}
    break;

  case 1211:

/* Line 1464 of yacc.c  */
#line 8190 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  ;}
    break;

  case 1212:

/* Line 1464 of yacc.c  */
#line 8194 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1213:

/* Line 1464 of yacc.c  */
#line 8203 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1216:

/* Line 1464 of yacc.c  */
#line 8217 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1219:

/* Line 1464 of yacc.c  */
#line 8231 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1220:

/* Line 1464 of yacc.c  */
#line 8235 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1221:

/* Line 1464 of yacc.c  */
#line 8245 "parser.y"
    {
	begin_statement ("SORT", 0);
  ;}
    break;

  case 1223:

/* Line 1464 of yacc.c  */
#line 8253 "parser.y"
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

  case 1224:

/* Line 1464 of yacc.c  */
#line 8274 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  ;}
    break;

  case 1225:

/* Line 1464 of yacc.c  */
#line 8283 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1226:

/* Line 1464 of yacc.c  */
#line 8288 "parser.y"
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

  case 1227:

/* Line 1464 of yacc.c  */
#line 8306 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1228:

/* Line 1464 of yacc.c  */
#line 8307 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1230:

/* Line 1464 of yacc.c  */
#line 8312 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  ;}
    break;

  case 1231:

/* Line 1464 of yacc.c  */
#line 8319 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1232:

/* Line 1464 of yacc.c  */
#line 8320 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); ;}
    break;

  case 1233:

/* Line 1464 of yacc.c  */
#line 8325 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  ;}
    break;

  case 1234:

/* Line 1464 of yacc.c  */
#line 8331 "parser.y"
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

  case 1235:

/* Line 1464 of yacc.c  */
#line 8341 "parser.y"
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

  case 1236:

/* Line 1464 of yacc.c  */
#line 8356 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  ;}
    break;

  case 1237:

/* Line 1464 of yacc.c  */
#line 8362 "parser.y"
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

  case 1238:

/* Line 1464 of yacc.c  */
#line 8372 "parser.y"
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

  case 1239:

/* Line 1464 of yacc.c  */
#line 8388 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  ;}
    break;

  case 1241:

/* Line 1464 of yacc.c  */
#line 8398 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  ;}
    break;

  case 1242:

/* Line 1464 of yacc.c  */
#line 8410 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1243:

/* Line 1464 of yacc.c  */
#line 8414 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1244:

/* Line 1464 of yacc.c  */
#line 8421 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1245:

/* Line 1464 of yacc.c  */
#line 8425 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 1246:

/* Line 1464 of yacc.c  */
#line 8430 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  ;}
    break;

  case 1247:

/* Line 1464 of yacc.c  */
#line 8435 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  ;}
    break;

  case 1248:

/* Line 1464 of yacc.c  */
#line 8442 "parser.y"
    { (yyval) = cb_int (COB_EQ); ;}
    break;

  case 1249:

/* Line 1464 of yacc.c  */
#line 8443 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); ;}
    break;

  case 1250:

/* Line 1464 of yacc.c  */
#line 8444 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); ;}
    break;

  case 1251:

/* Line 1464 of yacc.c  */
#line 8445 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); ;}
    break;

  case 1252:

/* Line 1464 of yacc.c  */
#line 8446 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); ;}
    break;

  case 1253:

/* Line 1464 of yacc.c  */
#line 8447 "parser.y"
    { (yyval) = cb_int (COB_NE); ;}
    break;

  case 1254:

/* Line 1464 of yacc.c  */
#line 8452 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  ;}
    break;

  case 1257:

/* Line 1464 of yacc.c  */
#line 8465 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  ;}
    break;

  case 1258:

/* Line 1464 of yacc.c  */
#line 8469 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  ;}
    break;

  case 1259:

/* Line 1464 of yacc.c  */
#line 8479 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  ;}
    break;

  case 1260:

/* Line 1464 of yacc.c  */
#line 8483 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  ;}
    break;

  case 1261:

/* Line 1464 of yacc.c  */
#line 8489 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  ;}
    break;

  case 1262:

/* Line 1464 of yacc.c  */
#line 8501 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  ;}
    break;

  case 1263:

/* Line 1464 of yacc.c  */
#line 8505 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1264:

/* Line 1464 of yacc.c  */
#line 8509 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  ;}
    break;

  case 1265:

/* Line 1464 of yacc.c  */
#line 8517 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 1266:

/* Line 1464 of yacc.c  */
#line 8528 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1267:

/* Line 1464 of yacc.c  */
#line 8532 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1268:

/* Line 1464 of yacc.c  */
#line 8538 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1269:

/* Line 1464 of yacc.c  */
#line 8539 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1270:

/* Line 1464 of yacc.c  */
#line 8540 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1271:

/* Line 1464 of yacc.c  */
#line 8541 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1272:

/* Line 1464 of yacc.c  */
#line 8548 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  ;}
    break;

  case 1274:

/* Line 1464 of yacc.c  */
#line 8557 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 1275:

/* Line 1464 of yacc.c  */
#line 8563 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1276:

/* Line 1464 of yacc.c  */
#line 8564 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1277:

/* Line 1464 of yacc.c  */
#line 8568 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1278:

/* Line 1464 of yacc.c  */
#line 8569 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); ;}
    break;

  case 1279:

/* Line 1464 of yacc.c  */
#line 8570 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); ;}
    break;

  case 1280:

/* Line 1464 of yacc.c  */
#line 8574 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1281:

/* Line 1464 of yacc.c  */
#line 8575 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); ;}
    break;

  case 1282:

/* Line 1464 of yacc.c  */
#line 8580 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  ;}
    break;

  case 1283:

/* Line 1464 of yacc.c  */
#line 8584 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  ;}
    break;

  case 1284:

/* Line 1464 of yacc.c  */
#line 8594 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  ;}
    break;

  case 1286:

/* Line 1464 of yacc.c  */
#line 8603 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  ;}
    break;

  case 1287:

/* Line 1464 of yacc.c  */
#line 8607 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  ;}
    break;

  case 1288:

/* Line 1464 of yacc.c  */
#line 8611 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 1289:

/* Line 1464 of yacc.c  */
#line 8618 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  ;}
    break;

  case 1290:

/* Line 1464 of yacc.c  */
#line 8622 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  ;}
    break;

  case 1291:

/* Line 1464 of yacc.c  */
#line 8632 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  ;}
    break;

  case 1294:

/* Line 1464 of yacc.c  */
#line 8650 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
	PENDING("TERMINATE");
  ;}
    break;

  case 1296:

/* Line 1464 of yacc.c  */
#line 8659 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  ;}
    break;

  case 1297:

/* Line 1464 of yacc.c  */
#line 8665 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  ;}
    break;

  case 1298:

/* Line 1464 of yacc.c  */
#line 8676 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  ;}
    break;

  case 1300:

/* Line 1464 of yacc.c  */
#line 8684 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  ;}
    break;

  case 1301:

/* Line 1464 of yacc.c  */
#line 8697 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  ;}
    break;

  case 1303:

/* Line 1464 of yacc.c  */
#line 8705 "parser.y"
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

  case 1307:

/* Line 1464 of yacc.c  */
#line 8728 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  ;}
    break;

  case 1309:

/* Line 1464 of yacc.c  */
#line 8738 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 1310:

/* Line 1464 of yacc.c  */
#line 8744 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1311:

/* Line 1464 of yacc.c  */
#line 8746 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1312:

/* Line 1464 of yacc.c  */
#line 8750 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1313:

/* Line 1464 of yacc.c  */
#line 8752 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 1314:

/* Line 1464 of yacc.c  */
#line 8757 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1315:

/* Line 1464 of yacc.c  */
#line 8763 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); ;}
    break;

  case 1316:

/* Line 1464 of yacc.c  */
#line 8765 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1317:

/* Line 1464 of yacc.c  */
#line 8770 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1318:

/* Line 1464 of yacc.c  */
#line 8776 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1319:

/* Line 1464 of yacc.c  */
#line 8777 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1320:

/* Line 1464 of yacc.c  */
#line 8781 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1321:

/* Line 1464 of yacc.c  */
#line 8782 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1322:

/* Line 1464 of yacc.c  */
#line 8786 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1323:

/* Line 1464 of yacc.c  */
#line 8787 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1324:

/* Line 1464 of yacc.c  */
#line 8792 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  ;}
    break;

  case 1325:

/* Line 1464 of yacc.c  */
#line 8796 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  ;}
    break;

  case 1326:

/* Line 1464 of yacc.c  */
#line 8806 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  ;}
    break;

  case 1333:

/* Line 1464 of yacc.c  */
#line 8824 "parser.y"
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

  case 1334:

/* Line 1464 of yacc.c  */
#line 8849 "parser.y"
    {
	use_global_ind = 0;
  ;}
    break;

  case 1335:

/* Line 1464 of yacc.c  */
#line 8853 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  ;}
    break;

  case 1336:

/* Line 1464 of yacc.c  */
#line 8865 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  ;}
    break;

  case 1337:

/* Line 1464 of yacc.c  */
#line 8875 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  ;}
    break;

  case 1338:

/* Line 1464 of yacc.c  */
#line 8880 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  ;}
    break;

  case 1339:

/* Line 1464 of yacc.c  */
#line 8885 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  ;}
    break;

  case 1340:

/* Line 1464 of yacc.c  */
#line 8890 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  ;}
    break;

  case 1341:

/* Line 1464 of yacc.c  */
#line 8898 "parser.y"
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

  case 1344:

/* Line 1464 of yacc.c  */
#line 8941 "parser.y"
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

  case 1345:

/* Line 1464 of yacc.c  */
#line 8981 "parser.y"
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

  case 1346:

/* Line 1464 of yacc.c  */
#line 8991 "parser.y"
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

  case 1351:

/* Line 1464 of yacc.c  */
#line 9021 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("USE AT is invalid in nested program"));
	}
  ;}
    break;

  case 1352:

/* Line 1464 of yacc.c  */
#line 9030 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM START"));
	/* emit_entry ("_START", 0, NULL); */
	PENDING ("USE AT PROGRAM START");
  ;}
    break;

  case 1353:

/* Line 1464 of yacc.c  */
#line 9036 "parser.y"
    {
	emit_statement (cb_build_comment ("USE AT PROGRAM END"));
	/* emit_entry ("_END", 0, NULL); */
	PENDING ("USE AT PROGRAM END");
  ;}
    break;

  case 1354:

/* Line 1464 of yacc.c  */
#line 9046 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE BEFORE REPORTING"));
	PENDING ("USE BEFORE REPORTING");
  ;}
    break;

  case 1355:

/* Line 1464 of yacc.c  */
#line 9055 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  ;}
    break;

  case 1358:

/* Line 1464 of yacc.c  */
#line 9071 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1360:

/* Line 1464 of yacc.c  */
#line 9083 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  ;}
    break;

  case 1361:

/* Line 1464 of yacc.c  */
#line 9092 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1362:

/* Line 1464 of yacc.c  */
#line 9093 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1363:

/* Line 1464 of yacc.c  */
#line 9098 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 1364:

/* Line 1464 of yacc.c  */
#line 9102 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1365:

/* Line 1464 of yacc.c  */
#line 9106 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1366:

/* Line 1464 of yacc.c  */
#line 9110 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1367:

/* Line 1464 of yacc.c  */
#line 9116 "parser.y"
    { (yyval) = CB_BEFORE; ;}
    break;

  case 1368:

/* Line 1464 of yacc.c  */
#line 9117 "parser.y"
    { (yyval) = CB_AFTER; ;}
    break;

  case 1371:

/* Line 1464 of yacc.c  */
#line 9127 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  ;}
    break;

  case 1372:

/* Line 1464 of yacc.c  */
#line 9131 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  ;}
    break;

  case 1375:

/* Line 1464 of yacc.c  */
#line 9148 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1377:

/* Line 1464 of yacc.c  */
#line 9158 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1380:

/* Line 1464 of yacc.c  */
#line 9171 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1382:

/* Line 1464 of yacc.c  */
#line 9181 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1385:

/* Line 1464 of yacc.c  */
#line 9196 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1387:

/* Line 1464 of yacc.c  */
#line 9206 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1390:

/* Line 1464 of yacc.c  */
#line 9223 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1392:

/* Line 1464 of yacc.c  */
#line 9234 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1398:

/* Line 1464 of yacc.c  */
#line 9257 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1399:

/* Line 1464 of yacc.c  */
#line 9266 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1403:

/* Line 1464 of yacc.c  */
#line 9283 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1404:

/* Line 1464 of yacc.c  */
#line 9292 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1407:

/* Line 1464 of yacc.c  */
#line 9309 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1409:

/* Line 1464 of yacc.c  */
#line 9319 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1410:

/* Line 1464 of yacc.c  */
#line 9329 "parser.y"
    {
	(yyval) = cb_one;
  ;}
    break;

  case 1411:

/* Line 1464 of yacc.c  */
#line 9333 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 1412:

/* Line 1464 of yacc.c  */
#line 9343 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1413:

/* Line 1464 of yacc.c  */
#line 9350 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1414:

/* Line 1464 of yacc.c  */
#line 9356 "parser.y"
    {
	current_expr = NULL;
  ;}
    break;

  case 1415:

/* Line 1464 of yacc.c  */
#line 9360 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  ;}
    break;

  case 1419:

/* Line 1464 of yacc.c  */
#line 9373 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1420:

/* Line 1464 of yacc.c  */
#line 9381 "parser.y"
    { push_expr ('(', NULL); ;}
    break;

  case 1421:

/* Line 1464 of yacc.c  */
#line 9382 "parser.y"
    { push_expr (')', NULL); ;}
    break;

  case 1422:

/* Line 1464 of yacc.c  */
#line 9384 "parser.y"
    { push_expr ('+', NULL); ;}
    break;

  case 1423:

/* Line 1464 of yacc.c  */
#line 9385 "parser.y"
    { push_expr ('-', NULL); ;}
    break;

  case 1424:

/* Line 1464 of yacc.c  */
#line 9386 "parser.y"
    { push_expr ('*', NULL); ;}
    break;

  case 1425:

/* Line 1464 of yacc.c  */
#line 9387 "parser.y"
    { push_expr ('/', NULL); ;}
    break;

  case 1426:

/* Line 1464 of yacc.c  */
#line 9388 "parser.y"
    { push_expr ('^', NULL); ;}
    break;

  case 1427:

/* Line 1464 of yacc.c  */
#line 9390 "parser.y"
    { push_expr ('=', NULL); ;}
    break;

  case 1428:

/* Line 1464 of yacc.c  */
#line 9391 "parser.y"
    { push_expr ('>', NULL); ;}
    break;

  case 1429:

/* Line 1464 of yacc.c  */
#line 9392 "parser.y"
    { push_expr ('<', NULL); ;}
    break;

  case 1430:

/* Line 1464 of yacc.c  */
#line 9393 "parser.y"
    { push_expr (']', NULL); ;}
    break;

  case 1431:

/* Line 1464 of yacc.c  */
#line 9394 "parser.y"
    { push_expr ('[', NULL); ;}
    break;

  case 1432:

/* Line 1464 of yacc.c  */
#line 9395 "parser.y"
    { push_expr ('~', NULL); ;}
    break;

  case 1433:

/* Line 1464 of yacc.c  */
#line 9397 "parser.y"
    { push_expr ('!', NULL); ;}
    break;

  case 1434:

/* Line 1464 of yacc.c  */
#line 9398 "parser.y"
    { push_expr ('&', NULL); ;}
    break;

  case 1435:

/* Line 1464 of yacc.c  */
#line 9399 "parser.y"
    { push_expr ('|', NULL); ;}
    break;

  case 1436:

/* Line 1464 of yacc.c  */
#line 9401 "parser.y"
    { push_expr ('O', NULL); ;}
    break;

  case 1437:

/* Line 1464 of yacc.c  */
#line 9402 "parser.y"
    { push_expr ('9', NULL); ;}
    break;

  case 1438:

/* Line 1464 of yacc.c  */
#line 9403 "parser.y"
    { push_expr ('A', NULL); ;}
    break;

  case 1439:

/* Line 1464 of yacc.c  */
#line 9404 "parser.y"
    { push_expr ('L', NULL); ;}
    break;

  case 1440:

/* Line 1464 of yacc.c  */
#line 9405 "parser.y"
    { push_expr ('U', NULL); ;}
    break;

  case 1441:

/* Line 1464 of yacc.c  */
#line 9408 "parser.y"
    { push_expr ('P', NULL); ;}
    break;

  case 1442:

/* Line 1464 of yacc.c  */
#line 9409 "parser.y"
    { push_expr ('N', NULL); ;}
    break;

  case 1451:

/* Line 1464 of yacc.c  */
#line 9439 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1452:

/* Line 1464 of yacc.c  */
#line 9443 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1456:

/* Line 1464 of yacc.c  */
#line 9454 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); ;}
    break;

  case 1457:

/* Line 1464 of yacc.c  */
#line 9455 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); ;}
    break;

  case 1458:

/* Line 1464 of yacc.c  */
#line 9456 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1459:

/* Line 1464 of yacc.c  */
#line 9460 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); ;}
    break;

  case 1460:

/* Line 1464 of yacc.c  */
#line 9461 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); ;}
    break;

  case 1461:

/* Line 1464 of yacc.c  */
#line 9462 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1462:

/* Line 1464 of yacc.c  */
#line 9467 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1463:

/* Line 1464 of yacc.c  */
#line 9470 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1464:

/* Line 1464 of yacc.c  */
#line 9474 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1465:

/* Line 1464 of yacc.c  */
#line 9475 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); ;}
    break;

  case 1466:

/* Line 1464 of yacc.c  */
#line 9476 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1467:

/* Line 1464 of yacc.c  */
#line 9479 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 1468:

/* Line 1464 of yacc.c  */
#line 9480 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1469:

/* Line 1464 of yacc.c  */
#line 9491 "parser.y"
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

  case 1470:

/* Line 1464 of yacc.c  */
#line 9503 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1471:

/* Line 1464 of yacc.c  */
#line 9512 "parser.y"
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

  case 1472:

/* Line 1464 of yacc.c  */
#line 9524 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1473:

/* Line 1464 of yacc.c  */
#line 9533 "parser.y"
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

  case 1474:

/* Line 1464 of yacc.c  */
#line 9545 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1475:

/* Line 1464 of yacc.c  */
#line 9559 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1476:

/* Line 1464 of yacc.c  */
#line 9561 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1477:

/* Line 1464 of yacc.c  */
#line 9566 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 1478:

/* Line 1464 of yacc.c  */
#line 9574 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1479:

/* Line 1464 of yacc.c  */
#line 9581 "parser.y"
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

  case 1480:

/* Line 1464 of yacc.c  */
#line 9601 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1481:

/* Line 1464 of yacc.c  */
#line 9605 "parser.y"
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

  case 1482:

/* Line 1464 of yacc.c  */
#line 9626 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1483:

/* Line 1464 of yacc.c  */
#line 9667 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1484:

/* Line 1464 of yacc.c  */
#line 9680 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1485:

/* Line 1464 of yacc.c  */
#line 9682 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1486:

/* Line 1464 of yacc.c  */
#line 9686 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1487:

/* Line 1464 of yacc.c  */
#line 9692 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1488:

/* Line 1464 of yacc.c  */
#line 9694 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1489:

/* Line 1464 of yacc.c  */
#line 9699 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  ;}
    break;

  case 1492:

/* Line 1464 of yacc.c  */
#line 9713 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1493:

/* Line 1464 of yacc.c  */
#line 9720 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  ;}
    break;

  case 1494:

/* Line 1464 of yacc.c  */
#line 9730 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1495:

/* Line 1464 of yacc.c  */
#line 9731 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1496:

/* Line 1464 of yacc.c  */
#line 9736 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1497:

/* Line 1464 of yacc.c  */
#line 9744 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1498:

/* Line 1464 of yacc.c  */
#line 9752 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1499:

/* Line 1464 of yacc.c  */
#line 9756 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1500:

/* Line 1464 of yacc.c  */
#line 9763 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1503:

/* Line 1464 of yacc.c  */
#line 9779 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1504:

/* Line 1464 of yacc.c  */
#line 9793 "parser.y"
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

  case 1505:

/* Line 1464 of yacc.c  */
#line 9810 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1506:

/* Line 1464 of yacc.c  */
#line 9814 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1509:

/* Line 1464 of yacc.c  */
#line 9823 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 1510:

/* Line 1464 of yacc.c  */
#line 9830 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1511:

/* Line 1464 of yacc.c  */
#line 9834 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1516:

/* Line 1464 of yacc.c  */
#line 9845 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1517:

/* Line 1464 of yacc.c  */
#line 9849 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1518:

/* Line 1464 of yacc.c  */
#line 9853 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1519:

/* Line 1464 of yacc.c  */
#line 9857 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 1520:

/* Line 1464 of yacc.c  */
#line 9861 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 1521:

/* Line 1464 of yacc.c  */
#line 9865 "parser.y"
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

  case 1522:

/* Line 1464 of yacc.c  */
#line 9886 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1523:

/* Line 1464 of yacc.c  */
#line 9890 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1531:

/* Line 1464 of yacc.c  */
#line 9907 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1532:

/* Line 1464 of yacc.c  */
#line 9911 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1533:

/* Line 1464 of yacc.c  */
#line 9915 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1549:

/* Line 1464 of yacc.c  */
#line 9962 "parser.y"
    {
	(yyval) = cb_zero;
  ;}
    break;

  case 1557:

/* Line 1464 of yacc.c  */
#line 9986 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1558:

/* Line 1464 of yacc.c  */
#line 9990 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); ;}
    break;

  case 1559:

/* Line 1464 of yacc.c  */
#line 9994 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1560:

/* Line 1464 of yacc.c  */
#line 9995 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 1561:

/* Line 1464 of yacc.c  */
#line 9999 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1562:

/* Line 1464 of yacc.c  */
#line 10004 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  ;}
    break;

  case 1563:

/* Line 1464 of yacc.c  */
#line 10011 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1564:

/* Line 1464 of yacc.c  */
#line 10018 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1565:

/* Line 1464 of yacc.c  */
#line 10025 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1566:

/* Line 1464 of yacc.c  */
#line 10035 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  ;}
    break;

  case 1567:

/* Line 1464 of yacc.c  */
#line 10042 "parser.y"
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

  case 1568:

/* Line 1464 of yacc.c  */
#line 10052 "parser.y"
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

  case 1569:

/* Line 1464 of yacc.c  */
#line 10062 "parser.y"
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

  case 1570:

/* Line 1464 of yacc.c  */
#line 10072 "parser.y"
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

  case 1571:

/* Line 1464 of yacc.c  */
#line 10085 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1572:

/* Line 1464 of yacc.c  */
#line 10089 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1573:

/* Line 1464 of yacc.c  */
#line 10097 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  ;}
    break;

  case 1574:

/* Line 1464 of yacc.c  */
#line 10105 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 1575:

/* Line 1464 of yacc.c  */
#line 10109 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  ;}
    break;

  case 1576:

/* Line 1464 of yacc.c  */
#line 10119 "parser.y"
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

  case 1577:

/* Line 1464 of yacc.c  */
#line 10134 "parser.y"
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

  case 1578:

/* Line 1464 of yacc.c  */
#line 10157 "parser.y"
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

  case 1579:

/* Line 1464 of yacc.c  */
#line 10180 "parser.y"
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

  case 1580:

/* Line 1464 of yacc.c  */
#line 10195 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1581:

/* Line 1464 of yacc.c  */
#line 10196 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1582:

/* Line 1464 of yacc.c  */
#line 10197 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1583:

/* Line 1464 of yacc.c  */
#line 10198 "parser.y"
    { (yyval) = cb_high; ;}
    break;

  case 1584:

/* Line 1464 of yacc.c  */
#line 10199 "parser.y"
    { (yyval) = cb_low; ;}
    break;

  case 1585:

/* Line 1464 of yacc.c  */
#line 10200 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1586:

/* Line 1464 of yacc.c  */
#line 10205 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1587:

/* Line 1464 of yacc.c  */
#line 10209 "parser.y"
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

  case 1588:

/* Line 1464 of yacc.c  */
#line 10226 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1589:

/* Line 1464 of yacc.c  */
#line 10230 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1590:

/* Line 1464 of yacc.c  */
#line 10236 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1591:

/* Line 1464 of yacc.c  */
#line 10237 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1592:

/* Line 1464 of yacc.c  */
#line 10238 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1593:

/* Line 1464 of yacc.c  */
#line 10239 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1594:

/* Line 1464 of yacc.c  */
#line 10240 "parser.y"
    { (yyval) = cb_high; ;}
    break;

  case 1595:

/* Line 1464 of yacc.c  */
#line 10241 "parser.y"
    { (yyval) = cb_low; ;}
    break;

  case 1596:

/* Line 1464 of yacc.c  */
#line 10242 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1597:

/* Line 1464 of yacc.c  */
#line 10249 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  ;}
    break;

  case 1598:

/* Line 1464 of yacc.c  */
#line 10253 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1599:

/* Line 1464 of yacc.c  */
#line 10257 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1600:

/* Line 1464 of yacc.c  */
#line 10261 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1601:

/* Line 1464 of yacc.c  */
#line 10265 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  ;}
    break;

  case 1602:

/* Line 1464 of yacc.c  */
#line 10269 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1603:

/* Line 1464 of yacc.c  */
#line 10273 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1604:

/* Line 1464 of yacc.c  */
#line 10277 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1605:

/* Line 1464 of yacc.c  */
#line 10281 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  ;}
    break;

  case 1606:

/* Line 1464 of yacc.c  */
#line 10285 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  ;}
    break;

  case 1615:

/* Line 1464 of yacc.c  */
#line 10309 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1616:

/* Line 1464 of yacc.c  */
#line 10313 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  ;}
    break;

  case 1617:

/* Line 1464 of yacc.c  */
#line 10317 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 1618:

/* Line 1464 of yacc.c  */
#line 10324 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1619:

/* Line 1464 of yacc.c  */
#line 10328 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 1620:

/* Line 1464 of yacc.c  */
#line 10332 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1621:

/* Line 1464 of yacc.c  */
#line 10339 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  ;}
    break;

  case 1622:

/* Line 1464 of yacc.c  */
#line 10346 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  ;}
    break;

  case 1623:

/* Line 1464 of yacc.c  */
#line 10353 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  ;}
    break;

  case 1624:

/* Line 1464 of yacc.c  */
#line 10363 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  ;}
    break;

  case 1625:

/* Line 1464 of yacc.c  */
#line 10370 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1626:

/* Line 1464 of yacc.c  */
#line 10380 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  ;}
    break;

  case 1627:

/* Line 1464 of yacc.c  */
#line 10387 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  ;}
    break;

  case 1628:

/* Line 1464 of yacc.c  */
#line 10398 "parser.y"
    {
	non_const_word = 1;
  ;}
    break;

  case 1629:

/* Line 1464 of yacc.c  */
#line 10406 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1630:

/* Line 1464 of yacc.c  */
#line 10407 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1631:

/* Line 1464 of yacc.c  */
#line 10411 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1632:

/* Line 1464 of yacc.c  */
#line 10412 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1633:

/* Line 1464 of yacc.c  */
#line 10416 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1634:

/* Line 1464 of yacc.c  */
#line 10417 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1635:

/* Line 1464 of yacc.c  */
#line 10422 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1636:

/* Line 1464 of yacc.c  */
#line 10426 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1637:

/* Line 1464 of yacc.c  */
#line 10433 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1638:

/* Line 1464 of yacc.c  */
#line 10437 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1639:

/* Line 1464 of yacc.c  */
#line 10444 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1640:

/* Line 1464 of yacc.c  */
#line 10445 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1641:

/* Line 1464 of yacc.c  */
#line 10446 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 1642:

/* Line 1464 of yacc.c  */
#line 10450 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1643:

/* Line 1464 of yacc.c  */
#line 10451 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1644:

/* Line 1464 of yacc.c  */
#line 10455 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); ;}
    break;

  case 1645:

/* Line 1464 of yacc.c  */
#line 10456 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1646:

/* Line 1464 of yacc.c  */
#line 10457 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1647:

/* Line 1464 of yacc.c  */
#line 10462 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 1648:

/* Line 1464 of yacc.c  */
#line 10466 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  ;}
    break;

  case 1649:

/* Line 1464 of yacc.c  */
#line 10478 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  ;}
    break;

  case 1650:

/* Line 1464 of yacc.c  */
#line 10483 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  ;}
    break;

  case 1651:

/* Line 1464 of yacc.c  */
#line 10491 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  ;}
    break;

  case 1652:

/* Line 1464 of yacc.c  */
#line 10495 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  ;}
    break;

  case 1653:

/* Line 1464 of yacc.c  */
#line 10499 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  ;}
    break;

  case 1654:

/* Line 1464 of yacc.c  */
#line 10503 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  ;}
    break;

  case 1655:

/* Line 1464 of yacc.c  */
#line 10507 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  ;}
    break;

  case 1656:

/* Line 1464 of yacc.c  */
#line 10511 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  ;}
    break;

  case 1657:

/* Line 1464 of yacc.c  */
#line 10515 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  ;}
    break;

  case 1658:

/* Line 1464 of yacc.c  */
#line 10519 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  ;}
    break;

  case 1659:

/* Line 1464 of yacc.c  */
#line 10525 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1660:

/* Line 1464 of yacc.c  */
#line 10526 "parser.y"
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
#line 10697 "parser.y"


