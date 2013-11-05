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
#line 28 "parser.y"

#include "config.h"

#include <stdlib.h>
#include <string.h>

#define	COB_IN_PARSER	1
#include "cobc.h"
#include "tree.h"

#ifndef	_STDLIB_H
#define	_STDLIB_H 1
#endif

#define YYINCLUDED_STDLIB_H 1

#define YYSTYPE			cb_tree
#define yyerror			cb_error

#define	yyoverflow	pp_overflow

static void pp_overflow(const char * msg, short ** ptr1, size_t sz1, YYSTYPE ** ptr2, size_t sz2, size_t * newsz) {
	static short * aptr1 = NULL;
	static YYSTYPE * aptr2 = NULL;
	*newsz *= 5;
	short * nptr1 = new short[*newsz];
	YYSTYPE * nptr2 = new YYSTYPE[*newsz];
	memcpy(nptr1, *ptr1, sz1);
	memcpy(nptr2, *ptr2, sz2);
	if(aptr1 != NULL) {
		delete aptr1;
		delete aptr2;
	}
	*ptr1 = aptr1 = nptr1;
	*ptr2 = aptr2 = nptr2;
}

#define PENDING(x)		cb_warning(_("'%s' not implemented"), x)

#define emit_statement(x) \
do { \
  if(!skip_statements) { \
	CB_ADD_TO_CHAIN(x, current_program->exec_list); \
  } \
} while(0)

#define push_expr(type, node) \
  current_expr = cb_build_list(cb_int(type), node, current_expr)

/* Statement terminator definitions */
#define TERM_NONE		0
#define TERM_ACCEPT		1U
#define TERM_ADD		2U
#define TERM_CALL		3U
#define TERM_COMPUTE	4U
#define TERM_DELETE		5U
#define TERM_DISPLAY	6U
#define TERM_DIVIDE		7U
#define TERM_EVALUATE	8U
#define TERM_IF			9U
#define TERM_MULTIPLY	10U
#define TERM_PERFORM	11U
#define TERM_READ		12U
#define TERM_RECEIVE	13U
#define TERM_RETURN		14U
#define TERM_REWRITE	15U
#define TERM_SEARCH		16U
#define TERM_START		17U
#define TERM_STRING		18U
#define TERM_SUBTRACT	19U
#define TERM_UNSTRING	20U
#define TERM_WRITE		21U
#define TERM_MAX		22U

#define	TERMINATOR_WARNING(x,z)	terminator_warning(x, TERM_##z, #z)
#define	TERMINATOR_ERROR(x,z)	terminator_error(x, TERM_##z, #z)
#define	TERMINATOR_CLEAR(x,z)	terminator_clear(x, TERM_##z)

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

cb_program *	current_program = NULL;
cb_statement *	current_statement = NULL;
cb_label *		current_section = NULL;
cb_label *		current_paragraph = NULL;
char *			cobc_glob_line = NULL;	// Seems unused

cb_tree			cobc_printer_node = NULL;
int				functions_are_all = 0;
int				non_const_word = 0;
unsigned int	cobc_in_procedure = 0;
unsigned int	cobc_in_repository = 0;
unsigned int	cobc_force_literal = 0;
unsigned int	cobc_cs_check = 0;

/* Local variables */

static cb_statement * main_statement;

static cb_tree		current_expr;
static cb_field *	current_field;
static cb_field *	description_field;
static cb_file *	current_file;
static cb_report *	current_report;
static cb_report *	report_instance;

static cb_file *	linage_file;
static cb_tree		next_label_list;

static char *		stack_progid[PROG_DEPTH];

static enum cb_storage	current_storage;

static cb_tree		perform_stack;
static cb_tree		qualifier;

static cb_tree		save_tree;
static cb_tree		start_tree;

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
static int				next_label_id;
static int				eval_level;
static int				eval_inc;
static int				eval_inc2;
static int				depth;
static int				call_mode;
static int				size_mode;
static int				setattr_val_on;
static int				setattr_val_off;
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

static int				term_array[TERM_MAX];
static cb_tree			eval_check[EVAL_DEPTH][EVAL_DEPTH];

/* Defines for header presence */

#define	COBC_HD_ENVIRONMENT_DIVISION	(1U << 0)
#define	COBC_HD_CONFIGURATION_SECTION	(1U << 1)
#define	COBC_HD_SPECIAL_NAMES			(1U << 2)
#define	COBC_HD_INPUT_OUTPUT_SECTION	(1U << 3)
#define	COBC_HD_FILE_CONTROL			(1U << 4)
#define	COBC_HD_I_O_CONTROL				(1U << 5)
#define	COBC_HD_DATA_DIVISION			(1U << 6)
#define	COBC_HD_FILE_SECTION			(1U << 7)
#define	COBC_HD_WORKING_STORAGE_SECTION	(1U << 8)
#define	COBC_HD_LOCAL_STORAGE_SECTION	(1U << 9)
#define	COBC_HD_LINKAGE_SECTION			(1U << 10)
#define	COBC_HD_COMMUNICATIONS_SECTION	(1U << 11)
#define	COBC_HD_REPORT_SECTION			(1U << 12)
#define	COBC_HD_SCREEN_SECTION			(1U << 13)
#define	COBC_HD_PROCEDURE_DIVISION		(1U << 14)
#define	COBC_HD_PROGRAM_ID				(1U << 15)

/* Static functions */

static void
begin_statement(const char * name, const unsigned int term)
{
	if(cb_warn_unreachable && check_unreached) {
		cb_warning(_("Unreachable statement '%s'"), name);
	}
	current_paragraph->flag_statement = 1;
	current_statement = cb_build_statement(name);
	current_statement->source_file = cb_source_file;
	current_statement->source_line = cb_source_line;
	current_statement->statement = cobc_glob_line;
	current_statement->flag_in_debug = in_debugging;
	emit_statement(current_statement);
	if(term) {
		term_array[term]++;
	}
	main_statement = current_statement;
}

static void
begin_implicit_statement(void)
{
	current_statement = cb_build_statement(NULL);
	current_statement->flag_in_debug = !!in_debugging;
	main_statement->body = cb_list_add(main_statement->body,
					    current_statement);
}

static void
emit_entry(const char * name, const int encode, cb_tree using_list)
{
	char buff[COB_MINI_BUFF];
	snprintf(buff, (size_t)COB_MINI_MAX, "E$%s", name);
	cb_tree label = cb_build_label(cb_build_reference(buff), NULL);
	if(encode) {
		CB_LABEL(label)->name = cb_encode_program_id(name);
		CB_LABEL(label)->orig_name = name;
	} else {
		CB_LABEL(label)->name = name;
		CB_LABEL(label)->orig_name = current_program->orig_program_id;
	}
	CB_LABEL(label)->flag_begin = 1;
	CB_LABEL(label)->flag_entry = 1;
	label->source_file = cb_source_file;
	label->source_line = cb_source_line;
	emit_statement(label);

	if(current_program->flag_debugging) {
		emit_statement(cb_build_debug(cb_debug_contents,
						"START PROGRAM", NULL));
	}

	int parmnum = 1;
	for(cb_tree l = using_list; l; l = CB_CHAIN(l)) {
		cb_tree x = CB_VALUE(l);
		if(CB_VALID_TREE(x) && cb_ref(x) != cb_error_node) {
			cb_field * f = CB_FIELD(cb_ref(x));
			if(f->level != 01 && f->level != 77) {
				cb_error_x(x, _("'%s' not level 01 or 77"), cb_name(x));
			}
			if(!current_program->flag_chained) {
				if(f->storage != CB_STORAGE_LINKAGE) {
					cb_error_x(x, _("'%s' is not in LINKAGE SECTION"), cb_name(x));
				}
				if(f->flag_item_based || f->flag_external) {
					cb_error_x(x, _("'%s' can not be BASED/EXTERNAL"), cb_name(x));
				}
				f->flag_is_pdiv_parm = 1;
			} else {
				if(f->storage != CB_STORAGE_WORKING) {
					cb_error_x(x, _("'%s' is not in WORKING-STORAGE SECTION"), cb_name(x));
				}
				f->flag_chained = 1;
				f->param_num = parmnum;
				parmnum++;
			}
			if(f->redefines) {
				cb_error_x(x, _("'%s' REDEFINES field not allowed here"), cb_name(x));
			}
		}
	}

	/* Check dangling LINKAGE items */
	if(cb_warn_linkage) {
		for(cb_field * f = current_program->linkage_storage; f; f = f->sister) {
			if(current_program->returning) {
				if(cb_ref(current_program->returning) != cb_error_node) {
					if(f == CB_FIELD(cb_ref(current_program->returning))) {
						continue;
					}
				}
			}
			cb_tree l;
			for(l = using_list; l; l = CB_CHAIN(l)) {
				cb_tree x = CB_VALUE(l);
				if(CB_VALID_TREE(x) && cb_ref(x) != cb_error_node) {
					if(f == CB_FIELD(cb_ref(x))) {
						break;
					}
				}
			}
			if(!l && !f->redefines) {
				cb_warning(_("LINKAGE item '%s' is not a PROCEDURE USING parameter"), f->name);
			}
		}
	}

	/* Check returning item against using items when FUNCTION */
	if(current_program->prog_type == CB_FUNCTION_TYPE) {
		for(cb_tree l = using_list; l; l = CB_CHAIN(l)) {
			cb_tree x = CB_VALUE(l);
			if(CB_VALID_TREE(x) && current_program->returning && cb_ref(x) == cb_ref(current_program->returning)) {
				cb_error_x(x, _("'%s' USING item duplicates RETURNING item"), cb_name(x));
			}
		}
	}

	for(cb_tree l = current_program->entry_list; l; l = CB_CHAIN(l)) {
		if(strcmp((const char *)name, (const char *)(CB_LABEL(CB_PURPOSE(l))->name)) == 0) {
			cb_error_x(current_statement, _("ENTRY '%s' duplicated"), name);
		}
	}

	current_program->entry_list =
		cb_list_append(current_program->entry_list, CB_BUILD_PAIR(label, using_list));
}

static size_t
increment_depth(void)
{
	if(++depth >= PROG_DEPTH) {
		cb_error(_("Maximum nested program depth exceeded(%d)"),
			  PROG_DEPTH);
		return 1;
	}
	return 0;
}

static void
terminator_warning(cb_tree stmt, const unsigned int termid, const char * name)
{
	check_unreached = 0;
	if(term_array[termid]) {
		term_array[termid]--;
		if(cb_warn_terminator) {
			cb_warning_x(stmt,
				_("%s statement not terminated by END-%s"),
				name, name);
		}
	}
	/* Free tree assocated with terminator */
	cobc_parse_free(stmt);
}

static void
terminator_error(cb_tree stmt, const unsigned int termid, const char * name)
{
	check_unreached = 0;
	cb_error_x(current_statement,
			_("%s statement not terminated by END-%s"),
			name, name);
	if(term_array[termid]) {
		term_array[termid]--;
	}
	/* Free tree assocated with terminator */
	cobc_parse_free(stmt);
}

static void
terminator_clear(cb_tree stmt, const unsigned int termid)
{
	check_unreached = 0;
	if(term_array[termid]) {
		term_array[termid]--;
	}
	/* Free tree assocated with terminator */
	cobc_parse_free(stmt);
}

static int
literal_value(cb_tree x)
{
	if(x == cb_space) {
		return ' ';
	} else if(x == cb_zero) {
		return '0';
	} else if(x == cb_quote) {
		return cb_flag_apostrophe ? '\'' : '"';
	} else if(x == cb_null) {
		return 0;
	} else if(x == cb_low) {
		return 0;
	} else if(x == cb_high) {
		return 255;
	} else if(CB_TREE_CLASS(x) == CB_CLASS_NUMERIC) {
		return cb_get_int(x);
	} else {
		return CB_LITERAL(x)->data[0];
	}
}

static void
setup_use_file(cb_file * fileptr)
{
	if(fileptr->organization == COB_ORG_SORT) {
		cb_error(_("USE statement invalid for SORT file"));
	}
	if(fileptr->flag_global) {
		cb_file * newptr = (cb_file *) cobc_parse_malloc(sizeof(cb_file));
		*newptr = *fileptr;
		newptr->handler = current_section;
		newptr->handler_prog = current_program;
		if(!use_global_ind) {
			current_program->local_file_list =
				cb_list_add(current_program->local_file_list,
					     newptr);
		} else {
			current_program->global_file_list =
				cb_list_add(current_program->global_file_list,
					     newptr);
		}
	} else {
		fileptr->handler = current_section;
	}
}

static void
build_nested_special(const int ndepth)
{
	if(!ndepth) {
		return;
	}

	/* Inherit special name mnemonics from parent */
	for(cb_tree x = current_program->mnemonic_spec_list; x; x = CB_CHAIN(x)) {
		cb_tree y = cb_build_reference(cb_name(CB_PURPOSE(x)));
		if(CB_SYSTEM_NAME_P(CB_VALUE(x))) {
			cb_define(y, CB_VALUE(x));
		} else {
			cb_build_constant(y, CB_VALUE(x));
		}
	}
}

static void
clear_initial_values(void)
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
	memset((void *)eval_check, 0, sizeof(eval_check));
	memset((void *)term_array, 0, sizeof(term_array));
	linage_file = NULL;
	current_file = NULL;
	current_report = NULL;
	report_instance = NULL;
	next_label_list = NULL;
	if(cobc_glob_line) {
		delete [] cobc_glob_line;
		cobc_glob_line = NULL;
	}
}

static void
check_repeated(const char * clause, const unsigned int bitval)
{
	if(check_duplicate & bitval) {
		if(cb_relaxed_syntax_check) {
			cb_warning(_("Duplicate %s clause"), clause);
		} else {
			cb_error(_("Duplicate %s clause"), clause);
		}
	} else {
		check_duplicate |= bitval;
	}
}

static void
check_pic_repeated(const char * clause, const unsigned int bitval)
{
	if(check_pic_duplicate & bitval) {
		if(cb_relaxed_syntax_check) {
			cb_warning(_("Duplicate %s clause"), clause);
		} else {
			cb_error(_("Duplicate %s clause"), clause);
		}
	} else {
		check_pic_duplicate |= bitval;
	}
}

static void
check_comp_repeated(const char * clause, const unsigned int bitval)
{
	if(check_comp_duplicate & bitval) {
		if(cb_relaxed_syntax_check) {
			cb_warning(_("Duplicate %s clause"), clause);
		} else {
			cb_error(_("Duplicate %s clause"), clause);
		}
	} else {
		check_comp_duplicate |= bitval;
	}
}

static void
check_screen_attr(const char * clause, const int bitval)
{
	if(current_field->screen_flag & bitval) {
		if(cb_relaxed_syntax_check) {
			cb_warning(_("Duplicate %s clause"), clause);
		} else {
			cb_error(_("Duplicate %s clause"), clause);
		}
	} else {
		current_field->screen_flag |= bitval;
	}
}

static void
bit_set_attr(const cb_tree onoff, const int attrval)
{
	if(onoff == cb_int1) {
		setattr_val_on |= attrval;
	} else {
		setattr_val_off |= attrval;
	}
}

static void
check_attribs(cb_tree fgc, cb_tree bgc, cb_tree scroll,
			  cb_tree timeout, cb_tree prompt, int attribs)
{
	/* Attach attributes to current_statement */
	if(!current_statement->attr_ptr) {
		current_statement->attr_ptr =
			(cb_attr_struct *) cobc_parse_malloc(sizeof(cb_attr_struct));
	}
	if(fgc) {
		current_statement->attr_ptr->fgc = fgc;
	}
	if(bgc) {
		current_statement->attr_ptr->bgc = bgc;
	}
	if(scroll) {
		current_statement->attr_ptr->scroll = scroll;
	}
	if(timeout) {
		current_statement->attr_ptr->timeout = timeout;
	}
	if(prompt) {
		current_statement->attr_ptr->prompt = prompt;
	}
	current_statement->attr_ptr->dispattrs |= attribs;
}

static void
check_set_usage(const enum cb_usage usage)
{
	check_pic_repeated("USAGE", SYN_CLAUSE_5);
	current_field->usage = usage;
}

static void
check_relaxed_syntax(const unsigned int lev)
{
	const char * s;

	switch(lev) {
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
	if(cb_relaxed_syntax_check) {
		cb_warning(_("%s header missing - assumed"), s);
	} else {
		cb_error(_("%s header missing"), s);
	}
}

static void
check_headers_present(const unsigned int lev1, const unsigned int lev2,
		       const unsigned int lev3, const unsigned int lev4)
{
	/* Lev1 is always present and checked */
	/* Lev2/3/4, if non-zero(forced) may be present */
	if(!(header_check & lev1)) {
		header_check |= lev1;
		check_relaxed_syntax(lev1);
	}
	if(lev2) {
		if(!(header_check & lev2)) {
			header_check |= lev2;
			check_relaxed_syntax(lev2);
		}
	}
	if(lev3) {
		if(!(header_check & lev3)) {
			header_check |= lev3;
			check_relaxed_syntax(lev3);
		}
	}
	if(lev4) {
		if(!(header_check & lev4)) {
			header_check |= lev4;
			check_relaxed_syntax(lev4);
		}
	}
}



/* Line 268 of yacc.c  */
#line 773 "parser.cpp"

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
#line 1327 "parser.cpp"

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
#define YYLAST   7821

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  808
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1881
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2688

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
    2683,  2684,  2687,  2688,  2690,  2691,  2695,  2696,  2698,  2700,
    2703,  2705,  2707,  2709,  2710,  2714,  2716,  2717,  2721,  2723,
    2724,  2728,  2732,  2733,  2737,  2739,  2740,  2747,  2751,  2754,
    2756,  2757,  2759,  2760,  2764,  2770,  2771,  2774,  2775,  2779,
    2783,  2784,  2787,  2789,  2792,  2797,  2799,  2801,  2803,  2805,
    2807,  2809,  2811,  2812,  2816,  2817,  2821,  2823,  2826,  2827,
    2831,  2834,  2836,  2838,  2840,  2843,  2845,  2847,  2849,  2850,
    2854,  2857,  2863,  2865,  2868,  2871,  2874,  2876,  2878,  2880,
    2883,  2885,  2888,  2893,  2896,  2897,  2899,  2901,  2903,  2905,
    2910,  2911,  2914,  2918,  2922,  2923,  2927,  2928,  2932,  2936,
    2941,  2942,  2947,  2952,  2959,  2960,  2962,  2963,  2967,  2972,
    2978,  2980,  2982,  2984,  2986,  2987,  2991,  2992,  2996,  2999,
    3001,  3002,  3006,  3009,  3010,  3015,  3018,  3019,  3021,  3023,
    3025,  3027,  3031,  3032,  3035,  3037,  3041,  3045,  3046,  3050,
    3052,  3054,  3056,  3060,  3068,  3069,  3074,  3082,  3083,  3086,
    3087,  3090,  3093,  3097,  3101,  3105,  3108,  3109,  3113,  3115,
    3117,  3118,  3120,  3122,  3123,  3127,  3130,  3132,  3133,  3138,
    3143,  3144,  3146,  3147,  3152,  3157,  3158,  3161,  3165,  3166,
    3168,  3170,  3171,  3176,  3181,  3188,  3189,  3192,  3193,  3196,
    3198,  3201,  3205,  3206,  3208,  3209,  3213,  3215,  3217,  3219,
    3221,  3223,  3225,  3227,  3229,  3231,  3233,  3238,  3242,  3244,
    3247,  3250,  3253,  3256,  3259,  3262,  3265,  3268,  3271,  3276,
    3280,  3285,  3287,  3290,  3294,  3296,  3299,  3303,  3307,  3308,
    3312,  3313,  3321,  3322,  3328,  3329,  3332,  3333,  3336,  3337,
    3341,  3342,  3345,  3350,  3351,  3354,  3359,  3360,  3365,  3370,
    3371,  3375,  3376,  3381,  3383,  3385,  3387,  3390,  3393,  3396,
    3399,  3401,  3403,  3406,  3408,  3409,  3411,  3412,  3417,  3420,
    3421,  3424,  3427,  3432,  3437,  3438,  3440,  3442,  3444,  3446,
    3448,  3449,  3454,  3460,  3462,  3465,  3467,  3471,  3475,  3476,
    3481,  3482,  3484,  3485,  3490,  3495,  3502,  3509,  3510,  3512,
    3515,  3516,  3518,  3519,  3523,  3525,  3528,  3529,  3533,  3539,
    3540,  3544,  3547,  3548,  3550,  3552,  3553,  3558,  3565,  3566,
    3570,  3572,  3576,  3579,  3582,  3585,  3589,  3590,  3594,  3595,
    3599,  3600,  3604,  3605,  3607,  3608,  3612,  3614,  3616,  3618,
    3620,  3628,  3629,  3631,  3633,  3635,  3637,  3639,  3641,  3646,
    3648,  3651,  3653,  3656,  3660,  3661,  3663,  3666,  3668,  3673,
    3675,  3677,  3679,  3680,  3685,  3691,  3692,  3695,  3696,  3701,
    3705,  3709,  3711,  3713,  3715,  3717,  3718,  3720,  3723,  3724,
    3727,  3728,  3731,  3734,  3735,  3738,  3739,  3742,  3745,  3746,
    3749,  3750,  3753,  3756,  3757,  3760,  3761,  3764,  3767,  3769,
    3772,  3774,  3776,  3779,  3782,  3785,  3787,  3789,  3792,  3795,
    3798,  3799,  3802,  3803,  3806,  3807,  3810,  3812,  3814,  3815,
    3818,  3820,  3823,  3826,  3828,  3830,  3832,  3834,  3836,  3838,
    3840,  3842,  3844,  3846,  3848,  3850,  3852,  3854,  3856,  3858,
    3860,  3862,  3864,  3866,  3868,  3870,  3872,  3874,  3876,  3879,
    3881,  3883,  3885,  3887,  3889,  3891,  3893,  3897,  3898,  3900,
    3902,  3906,  3910,  3912,  3916,  3920,  3922,  3926,  3928,  3931,
    3934,  3936,  3940,  3942,  3944,  3948,  3950,  3954,  3956,  3960,
    3962,  3965,  3968,  3970,  3972,  3974,  3977,  3979,  3981,  3983,
    3986,  3988,  3989,  3992,  3994,  3996,  3998,  4002,  4004,  4006,
    4009,  4011,  4013,  4015,  4018,  4020,  4022,  4024,  4026,  4028,
    4030,  4033,  4035,  4037,  4041,  4043,  4046,  4048,  4050,  4052,
    4054,  4057,  4060,  4063,  4068,  4072,  4074,  4076,  4079,  4081,
    4083,  4085,  4087,  4089,  4091,  4093,  4096,  4099,  4102,  4104,
    4106,  4108,  4110,  4112,  4114,  4116,  4118,  4120,  4122,  4124,
    4126,  4128,  4130,  4132,  4134,  4136,  4138,  4140,  4142,  4144,
    4146,  4148,  4150,  4152,  4154,  4157,  4159,  4163,  4166,  4169,
    4171,  4173,  4177,  4180,  4183,  4185,  4187,  4191,  4195,  4200,
    4206,  4208,  4210,  4212,  4214,  4216,  4218,  4220,  4222,  4224,
    4226,  4228,  4231,  4233,  4237,  4239,  4241,  4243,  4245,  4247,
    4249,  4251,  4254,  4260,  4266,  4272,  4277,  4283,  4289,  4295,
    4298,  4301,  4303,  4305,  4307,  4309,  4311,  4313,  4315,  4317,
    4318,  4323,  4329,  4330,  4334,  4337,  4339,  4343,  4347,  4349,
    4353,  4355,  4359,  4360,  4361,  4363,  4364,  4366,  4367,  4369,
    4370,  4373,  4374,  4377,  4378,  4380,  4382,  4383,  4385,  4386,
    4388,  4391,  4392,  4395,  4396,  4400,  4402,  4404,  4406,  4408,
    4410,  4412,  4414,  4416,  4417,  4420,  4422,  4424,  4426,  4428,
    4430,  4432,  4434,  4436,  4438,  4440,  4442,  4444,  4446,  4448,
    4450,  4452,  4454,  4456,  4458,  4460,  4462,  4464,  4466,  4468,
    4470,  4472,  4474,  4476,  4478,  4480,  4482,  4484,  4486,  4488,
    4490,  4492,  4494,  4496,  4498,  4500,  4502,  4504,  4506,  4508,
    4510,  4512,  4514,  4516,  4518,  4520,  4522,  4524,  4526,  4528,
    4530,  4532,  4534,  4536,  4538,  4540,  4542,  4544,  4546,  4548,
    4550,  4552,  4554,  4556,  4558,  4560,  4561,  4563,  4564,  4566,
    4567,  4569,  4570,  4572,  4573,  4575,  4576,  4578,  4579,  4581,
    4582,  4584,  4585,  4587,  4588,  4590,  4591,  4593,  4594,  4596,
    4597,  4599,  4600,  4602,  4603,  4605,  4606,  4608,  4609,  4611,
    4612,  4614,  4617,  4618,  4620,  4621,  4623,  4624,  4626,  4627,
    4629,  4630,  4632,  4634,  4635,  4637,  4638,  4640,  4642,  4643,
    4645,  4647,  4648,  4651,  4654,  4655,  4657,  4658,  4660,  4661,
    4663,  4664,  4666,  4668,  4669,  4671,  4672,  4674,  4675,  4678,
    4680,  4682,  4683,  4685,  4686,  4688,  4689,  4691,  4692,  4694,
    4695,  4697,  4698,  4700,  4701,  4703,  4704,  4706,  4709,  4710,
    4712,  4713,  4715,  4716,  4718,  4719,  4721,  4722,  4724,  4725,
    4727,  4728,  4730,  4731,  4733,  4735,  4736,  4738,  4739,  4743,
    4744,  4746,  4749,  4751,  4753,  4755,  4757,  4759,  4761,  4763,
    4765,  4767,  4769,  4771,  4773,  4775,  4777,  4779,  4781,  4783,
    4785,  4787,  4789,  4791,  4794,  4797,  4799,  4801,  4803,  4805,
    4807,  4809,  4812,  4814,  4818,  4821,  4823,  4825,  4827,  4830,
    4832,  4835,  4837,  4840,  4842,  4845,  4847,  4850,  4852,  4855,
    4857,  4860
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
      -1,    -1,    26,   256,    -1,    -1,  1263,   538,  1278,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1294,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1263,  1212,  1305,    -1,  1311,
    1263,  1179,    -1,   396,  1263,  1212,    -1,  1250,    59,  1263,
     557,    -1,  1179,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1263,    96,    -1,  1212,  1263,  1183,    -1,
    1263,  1183,   574,    -1,   575,    -1,    -1,   575,    -1,  1030,
    1275,  1183,    -1,   575,  1030,  1275,  1183,    -1,    -1,    11,
    1183,   577,  1263,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1251,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1264,
     590,    -1,  1184,    -1,   589,  1184,    -1,  1213,    -1,   590,
    1213,    -1,    58,  1183,  1263,   592,    -1,   593,    -1,   592,
     593,    -1,  1215,    -1,  1215,   442,  1215,    -1,   257,  1183,
    1263,   256,    -1,    98,  1281,  1263,   256,   596,    -1,    -1,
    1294,   328,   256,    -1,   108,  1263,    68,    -1,   301,   405,
    1263,   468,   400,    -1,   100,  1263,  1178,    -1,    96,   423,
    1263,  1178,    -1,   390,  1263,  1178,    -1,   164,  1263,  1178,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1236,  1183,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1291,   614,   613,   615,    -1,    29,  1291,   614,   612,
     616,    -1,    29,  1291,   614,   119,   616,    -1,    29,  1291,
     614,   238,   616,    -1,    29,  1291,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1254,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1209,    -1,    -1,   256,    -1,  1209,    -1,     4,  1270,  1263,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1279,
    1265,  1263,   632,  1230,    -1,  1295,  1263,   504,    -1,   622,
     423,  1263,  1178,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1270,  1263,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1304,    -1,
     503,   262,   309,   274,  1304,    -1,   503,   385,    -1,   315,
    1263,   628,    -1,   628,    -1,   220,    -1,  1279,  1248,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1250,  1263,  1182,
      -1,   351,   113,  1263,   419,    -1,   351,  1265,  1263,   632,
      -1,  1178,    -1,  1178,   452,  1177,    -1,  1178,   414,  1263,
    1177,    -1,   359,  1265,  1263,  1178,    -1,   372,   635,  1245,
      -1,   287,    -1,  1212,    -1,   404,  1294,   637,    -1,     9,
    1276,    -1,   287,  1276,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1245,  1256,  1168,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1254,  1287,  1252,   645,    -1,   646,    -1,   645,   646,
      -1,  1169,   647,    -1,    -1,   331,  1212,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1169,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1263,   171,    -1,  1263,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1252,
    1212,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1252,  1212,  1251,    -1,   351,  1252,  1212,   446,  1212,  1251,
      -1,   351,  1263,   499,  1258,  1284,   661,   662,  1251,   660,
      -1,    -1,   114,  1274,  1178,    -1,    -1,  1257,  1212,    -1,
      -1,   446,  1212,    -1,   239,  1306,  1302,    -1,   498,   306,
     665,  1263,   666,    -1,   498,   306,   174,  1263,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1209,    -1,   102,  1306,
    1180,    -1,   250,  1263,  1182,  1269,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1294,   187,
    1247,  1182,    -1,   465,  1182,    -1,    48,  1182,    -1,   352,
    1270,  1263,   504,    -1,    62,  1263,   504,    -1,   677,   678,
      -1,   366,  1263,    -1,   368,  1244,    -1,  1183,    -1,   678,
    1183,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1228,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1263,   204,
      -1,  1216,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1273,   691,    -1,  1206,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1246,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1206,    -1,  1263,   171,   702,    -1,    -1,
      26,   256,    -1,  1263,   204,    -1,   327,    -1,   706,    -1,
     491,  1263,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1282,    -1,    41,   476,    -1,
      44,  1282,    -1,    44,   476,    -1,    43,  1282,    -1,    43,
     476,    -1,    42,  1282,    -1,    42,   476,    -1,    40,  1282,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1283,   241,  1240,    -1,  1283,   468,
    1240,    -1,   305,  1212,   713,  1289,   714,   711,    -1,    -1,
     425,  1212,    -1,   305,  1212,   713,  1289,   714,   715,   718,
      -1,    -1,   446,  1212,    -1,    -1,   114,  1274,  1178,    -1,
     716,    -1,    -1,   716,   717,  1265,  1263,  1177,    -1,    27,
      -1,   115,    -1,    -1,   220,  1249,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1280,    -1,   434,  1266,
      -1,    45,  1292,   510,    -1,    36,    -1,    -1,   498,  1264,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1216,
      -1,  1216,   442,  1216,    -1,    -1,  1293,   453,  1263,  1216,
      -1,   363,  1209,    -1,   363,  1209,   442,  1209,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1170,   740,   741,   451,   755,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1263,   204,
      -1,    61,  1263,  1196,    -1,   743,    -1,   746,    -1,  1319,
     744,    -1,  1255,   745,    -1,  1205,    -1,   745,  1205,    -1,
     321,  1268,   747,   748,    -1,  1214,    -1,  1214,  1303,  1214,
    1297,    -1,  1214,  1303,    -1,    -1,   748,   749,    -1,   750,
      -1,   751,    -1,   752,    -1,   753,    -1,   754,    -1,   210,
    1263,  1214,    -1,   177,  1312,  1263,  1214,    -1,   240,  1313,
    1263,  1214,    -1,   240,  1312,  1263,  1214,    -1,   187,  1263,
    1214,    -1,    -1,   755,   756,    -1,    -1,   686,   687,   757,
     758,   451,    -1,    -1,   758,   759,    -1,   760,    -1,   764,
      -1,   770,    -1,   704,    -1,   780,    -1,   709,    -1,   721,
      -1,   772,    -1,   723,    -1,   778,    -1,   765,    -1,   725,
      -1,   768,    -1,   779,    -1,   710,    -1,   769,    -1,   472,
    1263,   761,    -1,  1317,    -1,  1315,    -1,  1313,   762,    -1,
    1312,    -1,  1314,   762,    -1,  1316,    -1,  1318,    -1,    -1,
    1205,   763,    -1,   176,   763,    -1,    -1,   313,   321,    -1,
     285,   209,  1263,   775,    -1,   431,  1273,  1189,   766,    -1,
      -1,   373,  1274,   767,    -1,  1205,    -1,   176,    -1,   333,
     501,  1145,    -1,   499,  1205,   196,  1191,    49,  1191,    -1,
     771,   774,    -1,   252,  1272,  1264,    -1,   254,  1244,    -1,
     773,   776,    -1,  1296,  1272,  1264,    -1,  1297,  1244,    -1,
     775,    -1,   774,   775,    -1,   329,  1212,    -1,  1214,    -1,
     286,    -1,   777,    -1,   776,   777,    -1,   329,  1212,    -1,
    1214,    -1,   414,  1263,  1191,  1237,    -1,   209,  1260,    -1,
     491,  1263,   119,    -1,    -1,    -1,   389,   394,   451,   782,
     783,    -1,    -1,   784,    -1,   785,   451,    -1,   784,   785,
     451,    -1,   696,    -1,    -1,   686,   687,   786,   787,    -1,
     686,     1,   451,    -1,    -1,   787,   788,    -1,    45,   252,
      -1,    45,   389,    -1,    38,    -1,    46,    -1,   160,   156,
      -1,   160,   158,    -1,   211,    -1,   265,    -1,   378,    -1,
     473,    -1,   318,    -1,   243,    -1,    32,    -1,   395,    -1,
     371,    -1,   198,    -1,   345,    56,  1263,  1196,    -1,   345,
      -1,   456,    -1,   252,  1271,  1263,   791,  1198,    -1,  1296,
    1271,  1263,   792,  1198,    -1,   189,  1263,  1198,    -1,    35,
    1263,  1198,    -1,   705,    -1,   723,    -1,   794,    -1,   721,
      -1,   709,    -1,   725,    -1,   704,    -1,   793,    -1,   497,
    1205,    -1,   196,  1197,    -1,   446,  1205,    -1,   329,    -1,
     463,    -1,   270,    -1,   458,    -1,    -1,   789,    -1,   790,
      -1,    -1,   789,    -1,   790,    -1,   305,  1212,  1289,    -1,
    1263,   204,    -1,    -1,    -1,    -1,   337,   122,   799,   807,
     451,   796,   808,   797,   810,    -1,    -1,   798,   821,   451,
     810,    -1,    -1,    -1,   497,   800,   802,    -1,    -1,    55,
     801,   802,    -1,   803,    -1,   802,   803,    -1,   804,   805,
     806,   504,    -1,    -1,  1249,   357,    -1,  1249,   498,    -1,
      -1,   410,  1263,    32,    -1,   410,  1263,   110,    -1,   476,
     410,  1263,    32,    -1,   476,   410,  1263,  1212,    -1,   410,
    1263,  1212,    -1,    -1,   312,    -1,    -1,   376,   504,    -1,
      -1,    -1,   109,   451,   809,   810,   129,   109,   451,    -1,
      -1,   810,   811,    -1,   812,    -1,   815,    -1,   821,   451,
      -1,   816,    -1,   451,    -1,    -1,   504,   394,   817,   451,
     813,   814,    -1,    -1,  1101,   451,    -1,   504,   451,    -1,
     504,    -1,    -1,  1212,    -1,    -1,    -1,   819,   820,   821,
      -1,    -1,   822,   823,    -1,   821,   823,    -1,   824,    -1,
     839,    -1,   844,    -1,   848,    -1,   853,    -1,   868,    -1,
     871,    -1,   879,    -1,   875,    -1,   880,    -1,   881,    -1,
     886,    -1,   900,    -1,   904,    -1,   907,    -1,   921,    -1,
     924,    -1,   927,    -1,   930,    -1,   934,    -1,   935,    -1,
     939,    -1,   949,    -1,   952,    -1,   969,    -1,   971,    -1,
     974,    -1,   978,    -1,   984,    -1,   996,    -1,  1004,    -1,
    1005,    -1,  1008,    -1,  1009,    -1,  1013,    -1,  1018,    -1,
    1019,    -1,  1027,    -1,  1042,    -1,  1052,    -1,  1061,    -1,
    1066,    -1,  1073,    -1,  1077,    -1,  1079,    -1,  1082,    -1,
    1085,    -1,  1089,    -1,  1114,    -1,   285,   399,    -1,     1,
    1241,    -1,    -1,     3,   825,   826,   838,    -1,   827,   829,
     833,   834,   835,  1122,    -1,  1205,   196,   828,    -1,  1205,
     196,  1297,    -1,  1205,   196,   103,   509,    -1,  1205,   196,
     103,    -1,  1205,   196,   104,   508,    -1,  1205,   196,   104,
      -1,  1205,   196,   105,    -1,  1205,   196,   162,   237,    -1,
    1205,   196,   165,   423,    -1,  1205,   196,   443,    -1,  1205,
     196,   493,   276,    -1,  1205,   196,    69,    -1,  1205,   196,
     155,  1122,    -1,  1205,   196,   153,  1194,  1122,    -1,  1205,
     196,    24,    -1,  1205,   196,    25,  1122,    -1,  1205,   196,
    1172,    -1,  1205,   196,   504,    -1,  1205,    -1,   308,    -1,
     254,    -1,   252,   299,    -1,    -1,   830,    -1,  1247,   831,
     832,    -1,  1247,   832,   831,    -1,  1247,   831,    -1,  1247,
     832,    -1,    30,  1194,    -1,   252,  1271,  1198,    -1,  1296,
    1271,  1198,    -1,   331,  1271,  1198,    -1,    -1,   197,    -1,
      -1,   272,  1263,    47,    -1,    -1,   503,   836,    -1,   837,
      -1,   836,   837,    -1,    32,    -1,    38,    -1,    46,    -1,
      91,    -1,   198,    -1,   211,    -1,   243,    -1,   263,    -1,
     265,    -1,   288,    -1,   318,    -1,   345,    56,  1263,  1196,
      -1,   345,    -1,   371,    -1,   378,    -1,   395,    -1,   473,
      -1,   483,    -1,   489,    -1,   189,  1263,  1198,    -1,    35,
    1263,  1198,    -1,   391,   482,  1144,    -1,   391,   123,  1144,
      -1,   444,  1243,  1199,    -1,    -1,   130,    -1,    -1,     5,
     840,   841,   843,    -1,  1187,   446,  1164,  1128,    -1,  1187,
     842,   203,  1164,  1128,    -1,    94,  1205,   446,  1205,  1237,
    1128,    -1,    -1,   446,  1188,    -1,    -1,   131,    -1,    -1,
      10,   845,   846,    -1,  1205,  1231,   847,    -1,  1158,    57,
    1232,   847,    -1,    -1,   376,  1186,    -1,    -1,    18,   849,
     850,    -1,   851,    -1,   850,   851,    -1,  1174,   446,   852,
    1174,    -1,    -1,   339,   446,    -1,    -1,    51,   854,   855,
     867,    -1,   856,  1197,   857,   862,   865,   866,    -1,    -1,
     422,    -1,   424,    -1,   271,    -1,    -1,    -1,   497,   858,
     859,    -1,   860,    -1,   859,   860,    -1,   861,   308,    -1,
     861,   805,  1188,    -1,    -1,  1249,   357,    -1,  1249,    87,
      -1,  1249,   498,    -1,    -1,   863,  1262,  1205,    -1,   863,
     864,    -1,   863,     6,  1273,  1205,    -1,   376,    -1,   203,
      -1,   460,    -1,   308,    -1,    -1,  1300,   818,    -1,    -1,
     294,   818,    -1,    -1,   132,    -1,    -1,    52,   869,   870,
      -1,  1196,    -1,   870,  1196,    -1,    -1,    60,   872,   873,
      -1,  1169,   874,    -1,   873,  1169,   874,    -1,    -1,  1307,
      -1,  1307,  1256,   362,    -1,  1294,   287,   380,    -1,  1294,
     262,    -1,    -1,    74,   876,   877,   878,    -1,  1164,  1298,
    1158,  1128,    -1,    -1,   133,    -1,    71,    -1,    88,    -1,
      -1,   111,   882,   883,   885,    -1,  1169,  1279,  1141,    -1,
     454,   884,    -1,  1169,    -1,   884,  1169,    -1,    -1,   134,
      -1,    -1,   119,   887,   888,   899,    -1,  1196,   487,  1125,
      -1,  1196,   488,  1125,    -1,  1196,   485,  1125,    -1,  1196,
     486,  1125,    -1,  1187,   892,   896,  1125,    -1,   889,  1125,
      -1,  1188,   503,   897,  1125,    -1,   891,    -1,    -1,   889,
     890,   891,    -1,  1188,   830,   893,   834,   895,    -1,    -1,
     484,  1172,    -1,   484,   504,    -1,   484,   335,    -1,   484,
      96,    -1,    -1,   484,   894,    -1,    96,    -1,    97,    -1,
      -1,   503,   897,    -1,    -1,   298,    -1,   898,    -1,   897,
     898,    -1,    38,    -1,    45,   252,    -1,    45,   389,    -1,
      46,    -1,    91,    -1,   160,   156,    -1,   160,   158,    -1,
     211,    -1,   265,    -1,   318,    -1,   378,    -1,   473,    -1,
     189,  1263,  1198,    -1,    35,  1263,  1198,    -1,   391,   482,
    1144,    -1,   391,   123,  1144,    -1,    -1,   135,    -1,    -1,
     121,   901,   902,   903,    -1,  1188,   228,  1164,  1128,    -1,
    1188,   228,  1188,   203,  1164,  1128,    -1,  1188,    49,  1188,
     203,  1164,  1128,    -1,  1188,   228,  1188,   203,  1165,   361,
    1165,  1128,    -1,  1188,    49,  1188,   203,  1165,   361,  1165,
    1128,    -1,    -1,   136,    -1,    -1,   152,   905,   906,    -1,
     256,   857,    -1,    -1,   163,   908,   909,   920,    -1,   910,
     912,    -1,   911,    -1,   910,    17,   911,    -1,  1146,    -1,
     464,    -1,   453,    -1,   913,   915,    -1,   913,    -1,   914,
      -1,   913,   914,    -1,   916,   818,    -1,   501,   316,   818,
      -1,   501,   917,    -1,   916,   501,   917,    -1,   918,    -1,
     917,    17,   918,    -1,  1147,   919,    -1,    21,    -1,   464,
      -1,   453,    -1,    -1,   442,  1146,    -1,    -1,   137,    -1,
      -1,   168,   922,   923,    -1,    -1,   340,    -1,   199,    -1,
     324,   101,    -1,   324,    -1,   394,    -1,   323,    -1,    -1,
     195,   925,   926,    -1,  1185,    -1,    -1,   202,   928,   929,
      -1,  1209,    -1,    -1,   205,   931,   932,    -1,  1290,  1173,
     933,    -1,    -1,   114,  1274,  1205,    -1,   206,    -1,    -1,
     215,   936,  1145,  1288,   937,   938,    -1,   818,   128,   818,
      -1,   128,   818,    -1,   818,    -1,    -1,   139,    -1,    -1,
     222,   940,   941,    -1,  1185,   942,   943,   944,   948,    -1,
      -1,  1294,   175,    -1,    -1,     9,  1290,   498,    -1,   947,
    1290,   498,    -1,    -1,   365,   945,    -1,   946,    -1,   945,
     946,    -1,   947,  1253,    49,  1188,    -1,    12,    -1,    15,
      -1,   301,    -1,    16,    -1,   302,    -1,   277,    -1,   278,
      -1,    -1,  1288,  1290,   110,    -1,    -1,   224,   950,   951,
      -1,  1170,    -1,   951,  1170,    -1,    -1,   227,   953,   954,
      -1,   955,   956,    -1,  1205,    -1,  1216,    -1,  1219,    -1,
     957,   959,    -1,   957,    -1,   959,    -1,   960,    -1,    -1,
     436,   958,   961,    -1,   365,   963,    -1,    92,  1194,   446,
    1195,   967,    -1,   962,    -1,   961,   962,    -1,  1194,   188,
      -1,    57,   967,    -1,     9,    -1,   241,    -1,   468,    -1,
    1194,   967,    -1,   964,    -1,   963,   964,    -1,    57,    49,
    1194,   967,    -1,   965,   966,    -1,    -1,     9,    -1,   241,
      -1,   177,    -1,   468,    -1,  1194,    49,  1195,   967,    -1,
      -1,   967,   968,    -1,    37,  1261,  1188,    -1,     8,  1261,
    1188,    -1,    -1,   269,   970,  1044,    -1,    -1,   273,   972,
     973,    -1,  1188,   446,  1185,    -1,    94,  1188,   446,  1185,
      -1,    -1,   275,   975,   976,   977,    -1,  1188,    49,  1164,
    1128,    -1,  1188,    49,  1188,   203,  1164,  1128,    -1,    -1,
     140,    -1,    -1,   311,   979,   980,    -1,   981,   982,  1168,
     983,    -1,   980,   981,   982,  1168,   983,    -1,   225,    -1,
     317,    -1,   233,    -1,   170,    -1,    -1,   404,  1294,   637,
      -1,    -1,  1294,   287,   380,    -1,  1294,   262,    -1,   379,
      -1,    -1,   324,   985,   986,    -1,   990,   991,    -1,    -1,
     991,   987,   818,   988,    -1,   991,   989,    -1,    -1,   141,
      -1,   141,    -1,   451,    -1,  1174,    -1,  1174,   442,  1174,
      -1,    -1,  1197,   445,    -1,   190,    -1,   992,   481,   993,
      -1,   992,   499,   994,    -1,    -1,  1294,   439,  1119,    -1,
     168,    -1,  1145,    -1,   995,    -1,   994,     8,   995,    -1,
    1205,   196,  1188,    49,  1188,   481,  1145,    -1,    -1,   349,
     997,   998,  1003,    -1,  1169,  1234,  1279,   999,  1000,  1001,
    1002,    -1,    -1,   228,  1205,    -1,    -1,   217,   262,    -1,
    1294,   262,    -1,  1294,   236,   262,    -1,  1294,   287,   262,
      -1,  1294,   216,   262,    -1,  1294,   500,    -1,    -1,   237,
    1263,  1205,    -1,  1141,    -1,  1135,    -1,    -1,   143,    -1,
     350,    -1,    -1,   360,  1006,  1007,    -1,  1166,  1117,    -1,
     374,    -1,    -1,   375,  1010,  1011,  1012,    -1,  1169,  1279,
     999,  1134,    -1,    -1,   144,    -1,    -1,   381,  1014,  1015,
    1017,    -1,  1166,  1117,  1016,  1141,    -1,    -1,  1294,   262,
      -1,  1294,   287,   262,    -1,    -1,   145,    -1,   385,    -1,
      -1,   393,  1020,  1021,  1026,    -1,  1167,  1022,  1023,  1024,
      -1,     9,  1167,  1023,   501,  1146,   818,    -1,    -1,   499,
    1205,    -1,    -1,   129,   818,    -1,  1025,    -1,  1025,  1024,
      -1,   501,  1145,   818,    -1,    -1,   146,    -1,    -1,   403,
    1028,  1029,    -1,  1032,    -1,  1033,    -1,  1036,    -1,  1037,
      -1,  1038,    -1,  1040,    -1,   309,    -1,   307,    -1,   482,
      -1,   123,    -1,   153,  1194,   446,  1194,    -1,  1202,    31,
    1034,    -1,  1035,    -1,  1034,  1035,    -1,    38,  1030,    -1,
      46,  1030,    -1,   211,  1030,    -1,   265,  1030,    -1,   378,
    1030,    -1,   473,  1030,    -1,   243,  1030,    -1,   318,  1030,
      -1,  1185,   446,   152,  1193,    -1,  1185,   446,  1188,    -1,
    1185,  1031,    49,  1188,    -1,  1039,    -1,  1038,  1039,    -1,
    1171,   446,  1030,    -1,  1041,    -1,  1040,  1041,    -1,  1185,
     446,   464,    -1,  1185,   446,   453,    -1,    -1,   412,  1043,
    1044,    -1,    -1,  1203,  1046,  1048,  1049,  1045,  1050,  1051,
      -1,    -1,  1046,  1274,   717,  1265,  1047,    -1,    -1,  1047,
    1209,    -1,    -1,  1310,  1259,    -1,    -1,  1295,  1263,  1178,
      -1,    -1,   497,  1168,    -1,   225,   337,  1263,   990,    -1,
      -1,   203,  1168,    -1,   317,   337,  1263,   990,    -1,    -1,
     421,  1053,  1054,  1060,    -1,  1169,  1056,  1055,  1141,    -1,
      -1,  1294,  1309,  1158,    -1,    -1,   237,  1263,  1057,  1205,
      -1,   177,    -1,   240,    -1,  1151,    -1,  1235,  1152,    -1,
    1235,  1153,    -1,  1235,  1154,    -1,  1235,  1155,    -1,  1058,
      -1,  1059,    -1,   290,  1151,    -1,   293,    -1,    -1,   147,
      -1,    -1,   426,   387,  1062,  1063,    -1,   426,  1065,    -1,
      -1,   376,  1188,    -1,   203,  1188,    -1,  1294,   161,  1286,
    1064,    -1,  1294,   289,  1286,  1064,    -1,    -1,  1188,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,    -1,   427,
    1067,  1068,  1072,    -1,  1069,   228,  1205,  1071,  1131,    -1,
    1070,    -1,  1069,  1070,    -1,  1188,    -1,   112,  1249,   410,
      -1,   112,  1249,  1188,    -1,    -1,  1294,   330,  1263,  1205,
      -1,    -1,   148,    -1,    -1,   430,  1074,  1075,  1076,    -1,
    1187,   196,  1164,  1128,    -1,  1187,   196,  1188,   203,  1164,
    1128,    -1,    94,  1205,   196,  1205,  1237,  1128,    -1,    -1,
     149,    -1,   432,  1078,    -1,    -1,   336,    -1,    -1,   438,
    1080,  1081,    -1,  1170,    -1,  1081,  1170,    -1,    -1,   469,
    1083,  1084,    -1,  1205,   196,  1194,   446,  1195,    -1,    -1,
     475,  1086,  1087,    -1,  1169,  1088,    -1,    -1,   351,    -1,
     353,    -1,    -1,   480,  1090,  1091,  1100,    -1,  1205,  1092,
    1095,  1071,  1099,  1131,    -1,    -1,   112,  1249,  1093,    -1,
    1094,    -1,  1093,   313,  1094,    -1,  1229,  1194,    -1,   228,
    1096,    -1,  1095,  1096,    -1,  1205,  1097,  1098,    -1,    -1,
     113,  1258,  1205,    -1,    -1,    95,  1258,  1205,    -1,    -1,
     436,  1258,  1205,    -1,    -1,   150,    -1,    -1,   492,  1102,
    1103,    -1,  1104,    -1,  1107,    -1,  1111,    -1,  1112,    -1,
    1105,  1243,  1285,  1299,  1277,  1274,  1106,    -1,    -1,   204,
      -1,  1168,    -1,   225,    -1,   317,    -1,   233,    -1,   170,
      -1,  1256,   107,  1274,  1108,    -1,  1109,    -1,  1108,  1109,
      -1,  1175,    -1,     9,   338,    -1,     9,  1110,  1209,    -1,
      -1,   358,    -1,   358,   306,    -1,   306,    -1,  1105,    37,
     367,  1205,    -1,  1113,    -1,   166,    -1,   127,    -1,    -1,
     507,  1115,  1116,  1121,    -1,  1166,  1117,  1118,  1016,  1120,
      -1,    -1,   196,  1201,    -1,    -1,  1119,  1242,  1198,  1267,
      -1,  1119,  1242,  1172,    -1,  1119,  1242,   321,    -1,    37,
      -1,     8,    -1,  1141,    -1,  1138,    -1,    -1,   151,    -1,
    1123,  1124,    -1,    -1,   165,   818,    -1,    -1,   294,   818,
      -1,  1126,  1127,    -1,    -1,   165,   818,    -1,    -1,   294,
     818,    -1,  1129,  1130,    -1,    -1,   411,   818,    -1,    -1,
     297,   818,    -1,  1132,  1133,    -1,    -1,   461,   818,    -1,
      -1,   296,   818,    -1,  1136,  1137,    -1,  1136,    -1,  1136,
    1137,    -1,  1136,    -1,  1137,    -1,   129,   818,    -1,   291,
     818,    -1,  1139,  1140,    -1,  1139,    -1,  1140,    -1,   157,
     818,    -1,   292,   818,    -1,  1142,  1143,    -1,    -1,   231,
     818,    -1,    -1,   295,   818,    -1,    -1,  1200,  1308,    -1,
    1146,    -1,  1147,    -1,    -1,  1148,  1149,    -1,  1150,    -1,
    1149,   232,    -1,  1149,  1150,    -1,  1188,    -1,   462,    -1,
     448,    -1,   463,    -1,   458,    -1,   459,    -1,   450,    -1,
     169,    -1,  1151,    -1,  1152,    -1,  1153,    -1,  1154,    -1,
    1155,    -1,   293,    -1,   290,    -1,    20,    -1,   313,    -1,
     308,    -1,   301,    -1,    12,    -1,    13,    -1,    14,    -1,
     332,    -1,   284,    -1,   452,    -1,   159,  1290,    -1,   455,
      -1,   207,    -1,   457,    -1,   246,    -1,   208,    -1,   247,
      -1,  1158,    -1,  1156,  1157,  1158,    -1,    -1,    70,    -1,
     398,    -1,  1158,   463,  1159,    -1,  1158,   458,  1159,    -1,
    1159,    -1,  1159,   459,  1160,    -1,  1159,   450,  1160,    -1,
    1160,    -1,  1161,   169,  1160,    -1,  1161,    -1,   463,  1162,
      -1,   458,  1162,    -1,  1162,    -1,   462,  1158,   448,    -1,
    1191,    -1,   251,    -1,   251,  1301,   504,    -1,   253,    -1,
     253,  1301,   504,    -1,   322,    -1,   322,  1301,   504,    -1,
    1165,    -1,  1164,  1165,    -1,  1186,  1237,    -1,  1209,    -1,
    1209,    -1,  1169,    -1,  1168,  1169,    -1,   504,    -1,   504,
      -1,  1172,    -1,  1171,  1172,    -1,   271,    -1,    -1,  1173,
    1174,    -1,  1175,    -1,  1209,    -1,  1176,    -1,  1176,  1301,
    1176,    -1,   256,    -1,  1178,    -1,  1177,  1178,    -1,  1209,
      -1,   504,    -1,  1181,    -1,  1180,  1181,    -1,   504,    -1,
    1178,    -1,   256,    -1,   504,    -1,   504,    -1,  1186,    -1,
    1185,  1186,    -1,  1207,    -1,  1217,    -1,     6,  1273,  1206,
      -1,  1188,    -1,  1187,  1188,    -1,  1205,    -1,  1216,    -1,
    1219,    -1,  1163,    -1,   245,  1206,    -1,   245,  1217,    -1,
     245,  1219,    -1,     6,  1273,  1192,  1193,    -1,     6,  1273,
    1206,    -1,   271,    -1,  1191,    -1,  1189,  1191,    -1,  1205,
      -1,  1217,    -1,  1219,    -1,  1205,    -1,  1217,    -1,  1219,
      -1,  1163,    -1,   245,  1206,    -1,   245,  1217,    -1,   245,
    1219,    -1,   340,    -1,   152,    -1,  1206,    -1,   256,    -1,
    1205,    -1,  1217,    -1,  1205,    -1,  1216,    -1,  1205,    -1,
     256,    -1,  1205,    -1,   256,    -1,  1219,    -1,  1202,    -1,
    1212,    -1,   510,    -1,  1202,    -1,  1214,    -1,  1202,    -1,
    1212,    -1,  1205,    -1,  1216,    -1,  1219,    -1,  1204,    -1,
    1204,    -1,  1209,    -1,  1209,  1210,    -1,  1206,    -1,  1209,
    1210,  1211,    -1,  1209,  1210,    -1,  1209,  1211,    -1,  1209,
      -1,  1208,    -1,  1209,  1210,  1211,    -1,  1209,  1210,    -1,
    1209,  1211,    -1,  1209,    -1,   504,    -1,   504,  1301,  1209,
      -1,   462,  1156,   448,    -1,   462,  1158,   449,   448,    -1,
     462,  1158,   449,  1158,   448,    -1,   256,    -1,   256,    -1,
     256,    -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,
     212,    -1,   266,    -1,   460,    -1,  1217,    -1,     9,  1218,
      -1,  1218,    -1,  1217,   447,  1218,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,
      -1,  1220,  1223,    -1,  1221,   462,  1190,   448,  1223,    -1,
    1222,   462,  1156,   448,  1223,    -1,   470,   462,  1225,   448,
    1223,    -1,   303,   462,  1226,   448,    -1,   258,   462,  1227,
     448,  1223,    -1,   259,   462,  1227,   448,  1223,    -1,   260,
     462,  1227,   448,  1223,    -1,   201,  1224,    -1,   495,  1224,
      -1,    99,    -1,   502,    -1,   490,    -1,   264,    -1,   377,
      -1,    82,    -1,   428,    -1,   429,    -1,    -1,   462,  1158,
     449,   448,    -1,   462,  1158,   449,  1158,   448,    -1,    -1,
     462,  1156,   448,    -1,   462,   448,    -1,  1190,    -1,  1190,
    1157,   241,    -1,  1190,  1157,   468,    -1,  1190,    -1,  1190,
    1157,  1190,    -1,  1158,    -1,  1158,  1157,  1178,    -1,    -1,
      -1,     9,    -1,    -1,  1310,    -1,    -1,   223,    -1,    -1,
     223,  1233,    -1,    -1,   446,  1195,    -1,    -1,   285,    -1,
     334,    -1,    -1,   290,    -1,    -1,   312,    -1,   290,   312,
      -1,    -1,   386,  1238,    -1,    -1,   272,  1263,  1239,    -1,
      34,    -1,   281,    -1,   282,    -1,   283,    -1,   344,    -1,
     466,    -1,   467,    -1,   471,    -1,    -1,   400,  1250,    -1,
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
     384,    -1,    -1,   252,    -1,   254,    -1,    -1,   248,  1263,
      -1,   249,  1244,    -1,    -1,   254,    -1,    -1,   272,    -1,
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
      -1,   351,  1263,    -1,   353,  1244,    -1,   356,    -1,   474,
      -1,   252,    -1,   254,    -1,   410,    -1,   244,    -1,   503,
     124,    -1,   124,    -1,   340,    63,   401,    -1,    63,   401,
      -1,   401,    -1,   116,    -1,   106,    -1,    89,   210,    -1,
      54,    -1,    89,   187,    -1,    53,    -1,   321,   210,    -1,
     325,    -1,   321,   187,    -1,   326,    -1,   366,   210,    -1,
     383,    -1,   366,   187,    -1,   382,    -1,    89,  1263,    -1,
      90,  1244,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1346,  1346,  1346,  1378,  1379,  1383,  1384,  1388,  1389,
    1393,  1393,  1413,  1420,  1427,  1433,  1434,  1435,  1439,  1440,
    1444,  1468,  1469,  1473,  1507,  1513,  1525,  1499,  1535,  1534,
    1572,  1607,  1608,  1612,  1613,  1616,  1617,  1621,  1630,  1639,
    1640,  1644,  1648,  1657,  1658,  1666,  1667,  1677,  1678,  1682,
    1683,  1684,  1685,  1686,  1693,  1692,  1704,  1705,  1708,  1709,
    1723,  1722,  1731,  1732,  1733,  1734,  1738,  1739,  1743,  1744,
    1745,  1746,  1750,  1757,  1764,  1771,  1782,  1786,  1790,  1794,
    1801,  1802,  1809,  1808,  1818,  1819,  1820,  1827,  1828,  1832,
    1836,  1848,  1852,  1853,  1858,  1861,  1868,  1873,  1884,  1896,
    1897,  1905,  1906,  1910,  1911,  1912,  1913,  1914,  1915,  1916,
    1917,  1918,  1919,  1920,  1921,  1929,  1928,  1945,  1955,  1968,
    1976,  1979,  1980,  1984,  1992,  2006,  2005,  2027,  2033,  2039,
    2045,  2051,  2057,  2067,  2071,  2078,  2082,  2087,  2086,  2097,
    2101,  2108,  2109,  2110,  2111,  2112,  2113,  2120,  2133,  2136,
    2143,  2151,  2155,  2166,  2186,  2194,  2205,  2206,  2212,  2229,
    2230,  2234,  2238,  2259,  2278,  2358,  2361,  2370,  2387,  2401,
    2417,  2433,  2448,  2462,  2463,  2470,  2471,  2478,  2479,  2488,
    2489,  2494,  2493,  2512,  2522,  2523,  2527,  2528,  2529,  2530,
    2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,  2546,
    2552,  2562,  2575,  2588,  2604,  2605,  2606,  2607,  2610,  2611,
    2617,  2618,  2622,  2626,  2627,  2632,  2635,  2636,  2643,  2651,
    2652,  2653,  2660,  2684,  2695,  2702,  2704,  2705,  2711,  2711,
    2718,  2723,  2728,  2735,  2736,  2737,  2741,  2752,  2753,  2757,
    2762,  2767,  2772,  2783,  2794,  2804,  2812,  2813,  2814,  2820,
    2831,  2838,  2839,  2845,  2853,  2854,  2855,  2861,  2862,  2863,
    2870,  2871,  2875,  2876,  2882,  2906,  2907,  2908,  2909,  2916,
    2915,  2929,  2930,  2934,  2937,  2938,  2944,  2945,  2953,  2954,
    2962,  2963,  2967,  2988,  2987,  3003,  3010,  3014,  3020,  3021,
    3025,  3035,  3050,  3051,  3052,  3053,  3054,  3055,  3056,  3057,
    3058,  3065,  3072,  3072,  3072,  3078,  3098,  3132,  3163,  3164,
    3171,  3172,  3176,  3177,  3184,  3195,  3200,  3211,  3212,  3216,
    3217,  3223,  3234,  3252,  3253,  3257,  3258,  3259,  3263,  3270,
    3277,  3286,  3298,  3347,  3362,  3363,  3367,  3377,  3416,  3418,
    3417,  3433,  3436,  3436,  3451,  3452,  3454,  3458,  3460,  3459,
    3491,  3504,  3512,  3517,  3523,  3532,  3542,  3545,  3557,  3558,
    3559,  3560,  3564,  3568,  3572,  3576,  3580,  3584,  3588,  3592,
    3596,  3600,  3604,  3608,  3612,  3623,  3624,  3628,  3629,  3633,
    3634,  3635,  3639,  3640,  3644,  3667,  3671,  3680,  3684,  3693,
    3694,  3695,  3696,  3697,  3698,  3699,  3700,  3701,  3702,  3703,
    3704,  3705,  3706,  3713,  3737,  3765,  3768,  3777,  3802,  3813,
    3814,  3818,  3822,  3826,  3830,  3834,  3838,  3842,  3846,  3850,
    3854,  3858,  3862,  3866,  3871,  3876,  3880,  3884,  3892,  3896,
    3900,  3908,  3912,  3916,  3920,  3924,  3928,  3932,  3936,  3940,
    3948,  3956,  3960,  3964,  3968,  3972,  3976,  3984,  3985,  3989,
    3990,  3996,  4002,  4014,  4032,  4033,  4042,  4066,  4067,  4070,
    4071,  4078,  4097,  4098,  4113,  4114,  4117,  4118,  4125,  4126,
    4131,  4142,  4153,  4164,  4175,  4204,  4203,  4212,  4213,  4217,
    4218,  4221,  4222,  4235,  4248,  4269,  4278,  4292,  4294,  4293,
    4313,  4315,  4314,  4330,  4332,  4331,  4340,  4341,  4348,  4347,
    4360,  4361,  4362,  4369,  4374,  4378,  4379,  4385,  4392,  4396,
    4397,  4403,  4440,  4444,  4449,  4455,  4456,  4461,  4462,  4463,
    4464,  4465,  4469,  4476,  4483,  4490,  4497,  4503,  4504,  4509,
    4508,  4515,  4516,  4520,  4521,  4522,  4523,  4524,  4525,  4526,
    4527,  4528,  4529,  4530,  4531,  4532,  4533,  4534,  4535,  4539,
    4546,  4547,  4548,  4549,  4550,  4551,  4552,  4555,  4556,  4557,
    4560,  4561,  4565,  4572,  4578,  4579,  4583,  4584,  4588,  4595,
    4599,  4606,  4607,  4611,  4618,  4619,  4623,  4624,  4628,  4629,
    4630,  4634,  4635,  4639,  4640,  4644,  4651,  4658,  4666,  4668,
    4667,  4686,  4687,  4691,  4692,  4697,  4699,  4698,  4751,  4769,
    4770,  4774,  4778,  4782,  4786,  4790,  4794,  4798,  4802,  4806,
    4810,  4814,  4818,  4822,  4826,  4830,  4834,  4838,  4843,  4847,
    4851,  4856,  4861,  4866,  4871,  4872,  4873,  4874,  4875,  4876,
    4877,  4878,  4879,  4886,  4891,  4900,  4901,  4905,  4906,  4911,
    4914,  4918,  4926,  4929,  4933,  4941,  4952,  4960,  4962,  4972,
    4961,  4999,  4999,  5030,  5034,  5033,  5048,  5047,  5067,  5068,
    5073,  5080,  5082,  5086,  5096,  5098,  5106,  5114,  5122,  5151,
    5182,  5184,  5194,  5199,  5217,  5219,  5218,  5254,  5255,  5259,
    5260,  5261,  5276,  5277,  5288,  5287,  5337,  5338,  5342,  5388,
    5401,  5404,  5423,  5428,  5422,  5441,  5441,  5469,  5476,  5477,
    5478,  5479,  5480,  5481,  5482,  5483,  5484,  5485,  5486,  5487,
    5488,  5489,  5490,  5491,  5492,  5493,  5494,  5495,  5496,  5497,
    5498,  5499,  5500,  5501,  5502,  5503,  5504,  5505,  5506,  5507,
    5508,  5509,  5510,  5511,  5512,  5513,  5514,  5515,  5516,  5517,
    5518,  5519,  5520,  5521,  5522,  5523,  5524,  5525,  5537,  5549,
    5548,  5557,  5563,  5567,  5571,  5576,  5581,  5586,  5591,  5595,
    5599,  5603,  5607,  5612,  5616,  5620,  5624,  5628,  5632,  5636,
    5643,  5644,  5651,  5652,  5656,  5657,  5661,  5662,  5663,  5664,
    5665,  5669,  5673,  5674,  5677,  5678,  5681,  5682,  5688,  5689,
    5693,  5694,  5698,  5702,  5706,  5710,  5714,  5718,  5722,  5726,
    5730,  5734,  5738,  5742,  5746,  5750,  5754,  5758,  5762,  5766,
    5770,  5774,  5778,  5782,  5786,  5790,  5797,  5801,  5812,  5811,
    5820,  5824,  5828,  5834,  5835,  5842,  5846,  5857,  5856,  5865,
    5869,  5881,  5882,  5890,  5889,  5898,  5899,  5903,  5909,  5909,
    5916,  5915,  5925,  5946,  5950,  5955,  5960,  5979,  5983,  5982,
    6000,  6001,  6006,  6014,  6036,  6038,  6042,  6051,  6064,  6067,
    6071,  6075,  6096,  6097,  6101,  6102,  6107,  6110,  6118,  6122,
    6130,  6134,  6145,  6144,  6152,  6156,  6167,  6166,  6174,  6179,
    6187,  6188,  6189,  6190,  6191,  6199,  6198,  6207,  6214,  6218,
    6228,  6239,  6257,  6256,  6265,  6269,  6273,  6278,  6286,  6290,
    6301,  6300,  6310,  6314,  6318,  6322,  6326,  6330,  6331,  6340,
    6342,  6341,  6349,  6358,  6365,  6369,  6373,  6377,  6387,  6389,
    6393,  6394,  6397,  6399,  6406,  6407,  6411,  6412,  6417,  6421,
    6425,  6429,  6433,  6437,  6441,  6445,  6449,  6453,  6457,  6461,
    6465,  6469,  6473,  6477,  6484,  6488,  6499,  6498,  6507,  6511,
    6515,  6519,  6523,  6530,  6534,  6545,  6544,  6552,  6572,  6571,
    6595,  6603,  6604,  6609,  6620,  6631,  6645,  6649,  6656,  6657,
    6662,  6671,  6680,  6685,  6694,  6695,  6700,  6756,  6757,  6758,
    6762,  6763,  6767,  6771,  6782,  6781,  6793,  6794,  6812,  6826,
    6845,  6864,  6882,  6906,  6905,  6913,  6924,  6923,  6933,  6940,
    6939,  6952,  6961,  6965,  6976,  6989,  6988,  6997,  7001,  7005,
    7012,  7016,  7027,  7026,  7034,  7042,  7043,  7047,  7048,  7049,
    7054,  7057,  7064,  7068,  7076,  7083,  7084,  7085,  7086,  7087,
    7088,  7089,  7094,  7097,  7107,  7106,  7115,  7121,  7133,  7132,
    7141,  7145,  7149,  7153,  7160,  7161,  7162,  7163,  7170,  7169,
    7183,  7193,  7201,  7202,  7206,  7207,  7208,  7209,  7210,  7211,
    7215,  7216,  7220,  7225,  7232,  7233,  7234,  7235,  7236,  7240,
    7268,  7271,  7278,  7282,  7292,  7291,  7304,  7303,  7311,  7315,
    7326,  7325,  7334,  7338,  7345,  7349,  7360,  7359,  7367,  7386,
    7408,  7409,  7410,  7411,  7415,  7416,  7420,  7421,  7422,  7423,
    7435,  7434,  7445,  7451,  7450,  7461,  7469,  7477,  7484,  7488,
    7501,  7508,  7520,  7523,  7528,  7532,  7543,  7550,  7551,  7555,
    7556,  7559,  7560,  7565,  7576,  7575,  7584,  7609,  7610,  7615,
    7618,  7622,  7626,  7630,  7634,  7638,  7645,  7646,  7650,  7651,
    7655,  7659,  7669,  7680,  7679,  7687,  7697,  7708,  7707,  7716,
    7723,  7727,  7738,  7737,  7749,  7758,  7761,  7765,  7772,  7776,
    7786,  7798,  7797,  7806,  7810,  7819,  7820,  7825,  7828,  7836,
    7840,  7847,  7855,  7859,  7870,  7869,  7883,  7884,  7885,  7886,
    7887,  7888,  7892,  7893,  7897,  7898,  7904,  7913,  7920,  7921,
    7925,  7929,  7933,  7937,  7941,  7945,  7949,  7953,  7962,  7966,
    7975,  7984,  7985,  7989,  7998,  7999,  8003,  8007,  8018,  8017,
    8026,  8025,  8054,  8057,  8075,  8076,  8079,  8080,  8088,  8089,
    8094,  8099,  8109,  8125,  8130,  8140,  8157,  8156,  8166,  8179,
    8182,  8190,  8193,  8198,  8203,  8211,  8212,  8213,  8214,  8215,
    8216,  8220,  8228,  8229,  8233,  8237,  8248,  8247,  8257,  8270,
    8273,  8277,  8281,  8289,  8301,  8304,  8311,  8312,  8313,  8314,
    8321,  8320,  8329,  8336,  8337,  8341,  8342,  8343,  8347,  8348,
    8352,  8356,  8367,  8366,  8375,  8379,  8383,  8390,  8394,  8404,
    8415,  8416,  8423,  8422,  8431,  8437,  8449,  8448,  8456,  8468,
    8467,  8475,  8488,  8490,  8491,  8499,  8498,  8507,  8515,  8516,
    8521,  8522,  8527,  8534,  8535,  8540,  8547,  8548,  8552,  8553,
    8557,  8558,  8562,  8566,  8577,  8576,  8585,  8586,  8587,  8588,
    8592,  8619,  8622,  8634,  8642,  8647,  8652,  8657,  8665,  8701,
    8702,  8706,  8742,  8752,  8773,  8774,  8775,  8776,  8780,  8789,
    8798,  8799,  8806,  8805,  8817,  8827,  8828,  8833,  8836,  8840,
    8844,  8851,  8852,  8856,  8857,  8861,  8865,  8877,  8880,  8881,
    8890,  8891,  8900,  8903,  8904,  8913,  8914,  8925,  8928,  8929,
    8938,  8939,  8951,  8954,  8956,  8966,  8967,  8979,  8980,  8984,
    8985,  8986,  8990,  8999,  9010,  9011,  9012,  9016,  9025,  9036,
    9041,  9042,  9051,  9052,  9063,  9067,  9077,  9084,  9091,  9091,
    9101,  9102,  9103,  9107,  9116,  9117,  9119,  9120,  9121,  9122,
    9123,  9125,  9126,  9127,  9128,  9129,  9130,  9132,  9133,  9134,
    9136,  9137,  9138,  9139,  9140,  9143,  9144,  9148,  9149,  9153,
    9154,  9158,  9159,  9163,  9167,  9173,  9177,  9183,  9184,  9185,
    9189,  9190,  9191,  9195,  9196,  9197,  9201,  9205,  9209,  9210,
    9211,  9214,  9215,  9225,  9237,  9246,  9258,  9267,  9279,  9294,
    9295,  9300,  9309,  9315,  9333,  9337,  9357,  9397,  9411,  9412,
    9417,  9423,  9424,  9429,  9441,  9442,  9443,  9450,  9461,  9462,
    9466,  9474,  9482,  9486,  9493,  9502,  9503,  9509,  9523,  9540,
    9544,  9551,  9552,  9553,  9560,  9564,  9571,  9572,  9573,  9574,
    9575,  9579,  9583,  9587,  9591,  9595,  9613,  9617,  9624,  9625,
    9626,  9630,  9631,  9632,  9633,  9634,  9638,  9642,  9649,  9650,
    9654,  9655,  9659,  9660,  9664,  9665,  9676,  9677,  9681,  9682,
    9683,  9687,  9688,  9689,  9696,  9697,  9701,  9702,  9706,  9707,
    9708,  9714,  9718,  9722,  9723,  9727,  9731,  9738,  9745,  9752,
    9762,  9769,  9779,  9789,  9799,  9812,  9816,  9824,  9832,  9836,
    9846,  9861,  9882,  9903,  9917,  9918,  9919,  9920,  9921,  9922,
    9926,  9930,  9945,  9949,  9956,  9957,  9958,  9959,  9960,  9961,
    9962,  9968,  9972,  9976,  9980,  9984,  9988,  9992,  9996, 10000,
   10004, 10011, 10012, 10016, 10017, 10018, 10022, 10023, 10024, 10028,
   10032, 10036, 10043, 10047, 10051, 10058, 10063, 10068, 10076, 10081,
   10089, 10094, 10104, 10112, 10113, 10117, 10118, 10122, 10123, 10128,
   10131, 10139, 10142, 10149, 10151, 10152, 10156, 10157, 10161, 10162,
   10163, 10168, 10171, 10184, 10188, 10196, 10200, 10204, 10208, 10212,
   10216, 10220, 10224, 10231, 10232, 10238, 10239, 10240, 10241, 10242,
   10243, 10244, 10245, 10246, 10247, 10248, 10249, 10250, 10251, 10252,
   10253, 10254, 10255, 10256, 10257, 10258, 10259, 10260, 10261, 10262,
   10263, 10264, 10265, 10266, 10267, 10268, 10269, 10270, 10271, 10272,
   10273, 10274, 10275, 10276, 10277, 10278, 10279, 10280, 10281, 10282,
   10283, 10284, 10285, 10286, 10287, 10288, 10289, 10290, 10291, 10292,
   10293, 10294, 10295, 10296, 10297, 10298, 10299, 10300, 10301, 10302,
   10303, 10304, 10305, 10306, 10307, 10314, 10314, 10315, 10315, 10316,
   10316, 10317, 10317, 10318, 10318, 10319, 10319, 10320, 10320, 10321,
   10321, 10322, 10322, 10323, 10323, 10324, 10324, 10325, 10325, 10326,
   10326, 10327, 10327, 10328, 10328, 10329, 10329, 10330, 10330, 10331,
   10331, 10331, 10332, 10332, 10333, 10333, 10334, 10334, 10335, 10335,
   10336, 10336, 10336, 10337, 10337, 10338, 10338, 10338, 10339, 10339,
   10339, 10340, 10340, 10340, 10341, 10341, 10342, 10342, 10343, 10343,
   10344, 10344, 10344, 10345, 10345, 10346, 10346, 10347, 10347, 10347,
   10347, 10348, 10348, 10349, 10349, 10350, 10350, 10351, 10351, 10352,
   10352, 10353, 10353, 10354, 10354, 10355, 10355, 10355, 10356, 10356,
   10357, 10357, 10358, 10358, 10359, 10359, 10360, 10360, 10361, 10361,
   10362, 10362, 10363, 10363, 10363, 10364, 10364, 10365, 10365, 10366,
   10366, 10370, 10370, 10371, 10371, 10372, 10372, 10373, 10373, 10374,
   10374, 10375, 10375, 10376, 10376, 10377, 10377, 10378, 10378, 10379,
   10379, 10380, 10380, 10381, 10381, 10382, 10382, 10383, 10383, 10384,
   10384, 10385, 10385, 10388, 10389, 10390, 10394, 10394, 10395, 10395,
   10396, 10396, 10397, 10397, 10398, 10398, 10399, 10399, 10400, 10400,
   10401, 10401
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
     923,   923,   923,   925,   924,   926,   928,   927,   929,   931,
     930,   932,   933,   933,   934,   936,   935,   937,   937,   937,
     938,   938,   940,   939,   941,   942,   942,   943,   943,   943,
     944,   944,   945,   945,   946,   947,   947,   947,   947,   947,
     947,   947,   948,   948,   950,   949,   951,   951,   953,   952,
     954,   955,   955,   955,   956,   956,   956,   956,   958,   957,
     959,   960,   961,   961,   962,   962,   962,   962,   962,   962,
     963,   963,   964,   964,   965,   965,   965,   965,   965,   966,
     967,   967,   968,   968,   970,   969,   972,   971,   973,   973,
     975,   974,   976,   976,   977,   977,   979,   978,   980,   980,
     981,   981,   981,   981,   982,   982,   983,   983,   983,   983,
     985,   984,   986,   987,   986,   986,   988,   988,   989,   989,
     990,   990,   991,   991,   991,   991,   991,   992,   992,   993,
     993,   994,   994,   995,   997,   996,   998,   999,   999,  1000,
    1000,  1000,  1000,  1000,  1000,  1000,  1001,  1001,  1002,  1002,
    1003,  1003,  1004,  1006,  1005,  1007,  1008,  1010,  1009,  1011,
    1012,  1012,  1014,  1013,  1015,  1016,  1016,  1016,  1017,  1017,
    1018,  1020,  1019,  1021,  1021,  1022,  1022,  1023,  1023,  1024,
    1024,  1025,  1026,  1026,  1028,  1027,  1029,  1029,  1029,  1029,
    1029,  1029,  1030,  1030,  1031,  1031,  1032,  1033,  1034,  1034,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1036,  1036,
    1037,  1038,  1038,  1039,  1040,  1040,  1041,  1041,  1043,  1042,
    1045,  1044,  1046,  1046,  1047,  1047,  1048,  1048,  1049,  1049,
    1050,  1050,  1050,  1051,  1051,  1051,  1053,  1052,  1054,  1055,
    1055,  1056,  1056,  1056,  1056,  1057,  1057,  1057,  1057,  1057,
    1057,  1058,  1059,  1059,  1060,  1060,  1062,  1061,  1061,  1063,
    1063,  1063,  1063,  1063,  1064,  1064,  1065,  1065,  1065,  1065,
    1067,  1066,  1068,  1069,  1069,  1070,  1070,  1070,  1071,  1071,
    1072,  1072,  1074,  1073,  1075,  1075,  1075,  1076,  1076,  1077,
    1078,  1078,  1080,  1079,  1081,  1081,  1083,  1082,  1084,  1086,
    1085,  1087,  1088,  1088,  1088,  1090,  1089,  1091,  1092,  1092,
    1093,  1093,  1094,  1095,  1095,  1096,  1097,  1097,  1098,  1098,
    1099,  1099,  1100,  1100,  1102,  1101,  1103,  1103,  1103,  1103,
    1104,  1105,  1105,  1106,  1106,  1106,  1106,  1106,  1107,  1108,
    1108,  1109,  1109,  1109,  1110,  1110,  1110,  1110,  1111,  1112,
    1113,  1113,  1115,  1114,  1116,  1117,  1117,  1118,  1118,  1118,
    1118,  1119,  1119,  1120,  1120,  1121,  1121,  1122,  1123,  1123,
    1124,  1124,  1125,  1126,  1126,  1127,  1127,  1128,  1129,  1129,
    1130,  1130,  1131,  1132,  1132,  1133,  1133,  1134,  1134,  1135,
    1135,  1135,  1136,  1137,  1138,  1138,  1138,  1139,  1140,  1141,
    1142,  1142,  1143,  1143,  1144,  1144,  1145,  1146,  1148,  1147,
    1149,  1149,  1149,  1150,  1150,  1150,  1150,  1150,  1150,  1150,
    1150,  1150,  1150,  1150,  1150,  1150,  1150,  1150,  1150,  1150,
    1150,  1150,  1150,  1150,  1150,  1150,  1150,  1151,  1151,  1152,
    1152,  1153,  1153,  1154,  1155,  1156,  1156,  1157,  1157,  1157,
    1158,  1158,  1158,  1159,  1159,  1159,  1160,  1160,  1161,  1161,
    1161,  1162,  1162,  1163,  1163,  1163,  1163,  1163,  1163,  1164,
    1164,  1165,  1166,  1167,  1168,  1168,  1169,  1170,  1171,  1171,
    1172,  1173,  1173,  1174,  1175,  1175,  1175,  1176,  1177,  1177,
    1178,  1179,  1180,  1180,  1181,  1182,  1182,  1183,  1184,  1185,
    1185,  1186,  1186,  1186,  1187,  1187,  1188,  1188,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1189,  1189,  1190,  1190,
    1190,  1191,  1191,  1191,  1191,  1191,  1191,  1191,  1192,  1192,
    1193,  1193,  1194,  1194,  1195,  1195,  1196,  1196,  1197,  1197,
    1197,  1198,  1198,  1198,  1199,  1199,  1200,  1200,  1201,  1201,
    1201,  1202,  1203,  1204,  1204,  1205,  1206,  1206,  1206,  1206,
    1207,  1208,  1208,  1208,  1208,  1209,  1209,  1210,  1211,  1211,
    1212,  1213,  1214,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1216,  1216,  1217,  1217,  1218,  1218,  1218,  1218,  1218,  1218,
    1218,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,
    1219,  1220,  1220,  1221,  1221,  1221,  1222,  1222,  1222,  1223,
    1223,  1223,  1224,  1224,  1224,  1225,  1225,  1225,  1226,  1226,
    1227,  1227,  1228,  1229,  1229,  1230,  1230,  1231,  1231,  1232,
    1232,  1233,  1233,  1234,  1234,  1234,  1235,  1235,  1236,  1236,
    1236,  1237,  1237,  1238,  1238,  1239,  1239,  1239,  1239,  1239,
    1239,  1239,  1239,  1240,  1240,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,  1241,
    1241,  1241,  1241,  1241,  1241,  1242,  1242,  1243,  1243,  1244,
    1244,  1245,  1245,  1246,  1246,  1247,  1247,  1248,  1248,  1249,
    1249,  1250,  1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,
    1254,  1255,  1255,  1256,  1256,  1257,  1257,  1258,  1258,  1259,
    1259,  1259,  1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,
    1264,  1264,  1264,  1265,  1265,  1266,  1266,  1266,  1267,  1267,
    1267,  1268,  1268,  1268,  1269,  1269,  1270,  1270,  1271,  1271,
    1272,  1272,  1272,  1273,  1273,  1274,  1274,  1275,  1275,  1275,
    1275,  1276,  1276,  1277,  1277,  1278,  1278,  1279,  1279,  1280,
    1280,  1281,  1281,  1282,  1282,  1283,  1283,  1283,  1284,  1284,
    1285,  1285,  1286,  1286,  1287,  1287,  1288,  1288,  1289,  1289,
    1290,  1290,  1291,  1291,  1291,  1292,  1292,  1293,  1293,  1294,
    1294,  1295,  1295,  1296,  1296,  1297,  1297,  1298,  1298,  1299,
    1299,  1300,  1300,  1301,  1301,  1302,  1302,  1303,  1303,  1304,
    1304,  1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,
    1309,  1310,  1310,  1311,  1311,  1311,  1312,  1312,  1313,  1313,
    1314,  1314,  1315,  1315,  1316,  1316,  1317,  1317,  1318,  1318,
    1319,  1319
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
       0,     2,     0,     1,     0,     3,     0,     1,     1,     2,
       1,     1,     1,     0,     3,     1,     0,     3,     1,     0,
       3,     3,     0,     3,     1,     0,     6,     3,     2,     1,
       0,     1,     0,     3,     5,     0,     2,     0,     3,     3,
       0,     2,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     0,     3,     1,     2,     0,     3,
       2,     1,     1,     1,     2,     1,     1,     1,     0,     3,
       2,     5,     1,     2,     2,     2,     1,     1,     1,     2,
       1,     2,     4,     2,     0,     1,     1,     1,     1,     4,
       0,     2,     3,     3,     0,     3,     0,     3,     3,     4,
       0,     4,     4,     6,     0,     1,     0,     3,     4,     5,
       1,     1,     1,     1,     0,     3,     0,     3,     2,     1,
       0,     3,     2,     0,     4,     2,     0,     1,     1,     1,
       1,     3,     0,     2,     1,     3,     3,     0,     3,     1,
       1,     1,     3,     7,     0,     4,     7,     0,     2,     0,
       2,     2,     3,     3,     3,     2,     0,     3,     1,     1,
       0,     1,     1,     0,     3,     2,     1,     0,     4,     4,
       0,     1,     0,     4,     4,     0,     2,     3,     0,     1,
       1,     0,     4,     4,     6,     0,     2,     0,     2,     1,
       2,     3,     0,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     3,
       4,     1,     2,     3,     1,     2,     3,     3,     0,     3,
       0,     7,     0,     5,     0,     2,     0,     2,     0,     3,
       0,     2,     4,     0,     2,     4,     0,     4,     4,     0,
       3,     0,     4,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     1,     0,     1,     0,     4,     2,     0,
       2,     2,     4,     4,     0,     1,     1,     1,     1,     1,
       0,     4,     5,     1,     2,     1,     3,     3,     0,     4,
       0,     1,     0,     4,     4,     6,     6,     0,     1,     2,
       0,     1,     0,     3,     1,     2,     0,     3,     5,     0,
       3,     2,     0,     1,     1,     0,     4,     6,     0,     3,
       1,     3,     2,     2,     2,     3,     0,     3,     0,     3,
       0,     3,     0,     1,     0,     3,     1,     1,     1,     1,
       7,     0,     1,     1,     1,     1,     1,     1,     4,     1,
       2,     1,     2,     3,     0,     1,     2,     1,     4,     1,
       1,     1,     0,     4,     5,     0,     2,     0,     4,     3,
       3,     1,     1,     1,     1,     0,     1,     2,     0,     2,
       0,     2,     2,     0,     2,     0,     2,     2,     0,     2,
       0,     2,     2,     0,     2,     0,     2,     2,     1,     2,
       1,     1,     2,     2,     2,     1,     1,     2,     2,     2,
       0,     2,     0,     2,     0,     2,     1,     1,     0,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     2,     2,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       2,     2,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     3,     1,     1,     2,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       2,     2,     2,     4,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     2,     2,     1,
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
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     2,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     0,     1,     0,     1,     1,     0,     1,
       1,     0,     2,     2,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     0,     1,     0,     1,     0,     2,     1,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     2,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     1,     0,     1,     0,     3,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     2,     1,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     2
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
    1758,    46,     0,     0,     0,  1801,  1758,  1758,  1758,     0,
       0,     0,     0,     0,  1758,     0,     0,  1733,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1759,     0,     0,  1487,   125,  1758,
    1758,  1802,  1758,     0,     0,     0,     0,  1758,  1758,    60,
      82,     0,    54,    98,  1734,     0,  1758,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1795,    39,  1758,     0,     0,     0,  1555,   169,  1480,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1488,
     150,   151,  1760,   154,  1560,  1183,  1182,   116,   120,  1787,
    1758,     0,   100,   149,   176,   177,    38,  1796,    36,     0,
    1567,  1563,  1568,  1566,  1564,  1569,  1565,   158,   159,   161,
     170,   165,  1843,  1844,     0,   163,     0,  1732,     0,     0,
       0,  1758,  1865,    80,    61,  1731,    66,    68,    69,    70,
      71,  1731,     0,  1758,     0,    83,     0,    87,    55,    58,
     152,  1762,  1761,   155,     0,  1787,  1790,  1789,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1830,   164,     0,  1556,   168,  1864,  1758,
       0,     0,    65,    67,    63,    81,  1731,  1758,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1561,
     153,   156,     0,  1788,   123,   118,   119,   122,   178,     0,
       0,  1629,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1863,    74,    64,     0,
    1481,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1630,   181,  1739,   266,   267,   268,  1721,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1740,  1814,  1722,  1743,
       0,   278,   259,   138,   139,  1851,  1852,    72,  1797,  1815,
    1735,  1744,     0,     0,     0,   280,     0,  1776,  1797,  1822,
       0,   239,     0,  1758,  1731,  1763,   241,     0,  1832,  1829,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1727,  1758,  1736,     0,  1466,   264,  1464,   277,     0,    25,
     140,  1777,  1758,  1798,  1763,  1823,  1824,   210,  1831,   242,
    1797,  1758,  1758,  1764,  1758,  1758,   251,  1721,   252,     0,
    1758,  1776,  1728,     0,     0,   270,   271,   274,  1465,   279,
     286,   287,   338,   281,   341,     0,     0,  1758,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1791,  1791,
       0,   253,     0,  1758,   240,   223,   272,     0,   273,     0,
     487,   282,  1612,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1486,  1485,   243,   244,   245,   246,   249,  1792,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1615,   216,   201,   217,   202,  1739,
     203,   200,   213,   199,   214,  1758,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1758,  1862,     0,   222,  1616,   209,
       0,   247,  1478,     0,   231,   230,   341,   488,     0,     0,
     588,   345,   350,   387,   356,  1735,  1758,     0,     0,  1758,
    1735,  1776,  1758,  1719,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1861,   248,
    1479,     0,   236,   340,   341,   491,     0,     0,    26,  1758,
    1723,     0,     0,     0,  1758,  1719,     0,     0,     0,     0,
       0,  1758,   334,  1720,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   651,     0,   474,   411,  1803,
    1803,  1803,  1803,  1803,  1825,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1799,   446,     0,   422,   408,   423,   424,     0,
       0,  1806,   426,   427,   425,  1765,   429,   430,   428,  1758,
    1760,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1724,     0,   384,     0,   357,   312,   332,  1853,  1854,
    1484,   321,  1482,  1846,  1845,   314,  1774,  1733,  1747,     0,
    1758,   318,   317,  1758,   337,     0,  1849,  1850,   234,   492,
     496,   589,     0,    27,   695,   485,   486,  1804,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1826,     0,
    1800,   471,   457,   403,  1549,   483,  1807,  1766,  1767,   472,
       0,     0,   405,   407,  1643,  1643,   386,     0,  1783,  1578,
       0,     0,  1574,  1579,  1577,  1575,  1580,  1576,   385,   358,
    1570,  1572,     0,   302,  1483,  1775,   323,     0,   305,  1748,
    1808,   331,     0,     0,   235,   495,   591,   653,     0,     0,
     473,     0,  1818,     0,  1547,  1548,     0,   410,   475,   477,
     479,     0,   404,  1731,   451,   452,  1571,  1784,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1733,
    1809,   310,   319,   316,   320,   315,     0,   497,     0,   595,
     590,   592,     0,   656,   654,   672,     0,   749,   818,   827,
     833,   840,   872,   876,   890,   885,   891,   892,   900,   946,
     955,   958,   984,   993,   996,   999,  1004,  1005,  1012,  1034,
    1038,  1074,  1076,  1080,     0,  1086,  1100,  1124,  1142,  1143,
    1146,  1147,  1152,  1160,  1161,  1174,  1208,  1226,     0,  1260,
    1272,  1280,  1282,   677,  1286,  1289,  1295,  1342,   697,   698,
     699,   700,   701,   702,   703,   704,   706,   705,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   696,   458,
    1819,   459,  1596,  1591,  1602,     0,  1453,  1455,     0,     0,
       0,  1594,     0,  1457,  1595,  1597,  1598,     0,     0,     0,
       0,  1593,  1602,  1592,  1437,  1435,  1442,  1445,  1447,  1450,
    1514,  1452,  1511,  1545,  1512,  1513,  1599,     0,     0,     0,
    1546,   484,   481,   478,     0,   406,  1644,   361,   374,  1573,
       0,     0,   324,   325,   326,   327,     0,   306,  1746,   312,
       0,  1467,   498,     0,   596,     0,   593,   661,   661,     0,
       0,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1645,  1691,  1692,  1693,
    1694,   748,     0,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,  1398,   986,     0,     0,  1820,  1398,
       0,     0,     0,     0,     0,     0,   747,     0,  1112,     0,
       0,     0,     0,     0,     0,     0,     0,  1256,  1259,  1246,
    1257,  1258,  1248,     0,     0,  1281,  1279,     0,   695,     0,
       0,     0,     0,  1785,   462,     0,  1589,  1515,  1516,  1517,
       0,     0,     0,     0,     0,     0,     0,  1449,     0,  1448,
       0,  1590,  1438,  1439,  1557,     0,     0,     0,     0,     0,
       0,     0,     0,  1581,     0,     0,     0,     0,   476,     0,
     480,   330,   329,  1725,  1733,   311,     0,   598,   599,   594,
    1730,   661,   658,   664,     0,   661,   673,   648,   771,   816,
     774,   770,  1783,     0,     0,  1505,   825,  1499,   823,  1494,
    1496,  1497,  1498,   828,     0,  1617,  1477,   834,   835,     0,
    1473,  1475,  1474,   846,   844,   845,   870,     0,  1527,   873,
     874,  1526,   877,   880,  1783,   888,     0,  1459,  1631,  1491,
    1550,  1554,  1492,     0,   898,  1797,  1574,   944,  1363,   909,
     913,  1494,     0,  1496,   953,     0,   847,   956,   965,   964,
     982,     0,   961,   963,  1397,     0,   988,   992,   990,   987,
     991,   985,   994,   995,  1489,   997,   998,  1821,  1000,  1471,
    1816,  1396,  1013,  1015,  1035,  1036,  1039,     0,  1041,  1042,
    1043,  1075,  1212,  1542,  1543,     0,  1077,     0,  1084,     0,
    1093,  1090,  1092,  1091,  1087,  1094,  1114,  1477,  1101,  1112,
    1103,     0,  1110,     0,  1528,  1474,  1530,     0,  1140,  1623,
    1144,  1345,  1462,  1150,  1797,  1158,  1345,     0,  1172,  1165,
    1463,     0,  1470,  1175,  1176,  1177,  1178,  1179,  1180,  1201,
    1181,  1204,     0,  1468,     0,     0,  1541,  1554,  1209,  1244,
    1231,  1249,  1729,  1270,     0,  1263,  1265,     0,  1277,     0,
    1283,  1284,   683,   689,   678,   679,   680,   682,     0,  1287,
       0,  1290,  1292,  1312,  1298,  1355,  1345,  1786,     0,   466,
     461,  1604,  1437,  1435,  1454,  1456,  1437,     0,     0,     0,
    1437,  1508,  1509,  1510,     0,  1458,  1451,  1437,     0,  1436,
    1558,     0,  1441,  1440,  1444,  1443,  1446,     0,     0,  1437,
       0,  1758,  1726,     0,   308,     0,  1758,  1805,   659,  1758,
       0,   670,   662,   663,   674,   817,   750,  1726,   784,   775,
       0,     0,     0,     0,  1500,  1501,  1502,   826,   819,     0,
       0,  1495,  1619,  1618,   831,   836,   838,     0,   871,   841,
    1529,   847,   875,   880,  1855,  1856,   878,     0,   881,     0,
     889,   886,  1838,  1837,  1460,     0,  1633,  1461,  1552,  1553,
     895,   896,   899,   893,  1390,   945,   901,   692,     0,   907,
    1365,     0,   924,     0,   918,  1363,  1363,  1363,  1363,   954,
     947,     0,     0,   848,   957,   983,   959,  1398,  1398,   960,
     967,   968,   692,  1422,  1423,  1424,  1418,  1820,  1410,  1430,
    1433,  1432,  1434,  1426,  1417,  1416,  1421,  1420,  1419,  1425,
    1405,  1409,  1427,  1429,  1431,  1407,  1408,  1404,  1406,  1399,
    1400,  1411,  1412,  1413,  1414,  1415,  1403,   989,  1490,  1002,
    1817,   692,  1017,     0,  1037,     0,  1064,  1048,  1040,  1045,
    1046,  1047,  1216,     0,  1544,     0,     0,  1085,  1081,     0,
    1094,  1829,     0,  1102,  1108,  1109,   692,  1105,  1398,     0,
       0,  1113,     0,  1141,  1125,  1624,  1625,  1797,     0,  1145,
    1151,  1148,  1127,  1159,  1153,  1155,  1167,  1173,  1162,     0,
    1167,     0,  1522,  1523,  1202,  1205,     0,     0,  1469,  1185,
       0,  1184,     0,     0,  1552,  1245,  1227,  1233,  1758,  1234,
    1229,     0,     0,  1247,     0,     0,  1271,  1261,     0,  1264,
       0,  1278,  1273,     0,  1285,   690,   688,   681,     0,  1293,
    1294,  1291,  1313,  1296,  1729,     0,  1356,  1343,  1347,   460,
    1729,   456,   464,   465,  1763,  1603,     0,  1599,  1599,  1599,
       0,  1585,     0,  1599,  1559,     0,  1599,  1599,  1828,     0,
     328,  1785,   307,   502,  1758,  1758,  1719,  1771,   527,   501,
     505,   506,     0,  1741,   613,  1758,   603,  1825,   604,  1834,
    1833,     0,  1758,     0,   616,   607,   612,  1778,   608,     0,
     611,   618,   615,   609,   614,     0,   619,   610,     0,   630,
     624,   628,   627,   625,   629,   600,   631,   626,     0,  1778,
       0,  1758,   671,     0,     0,   649,   780,   785,   786,  1778,
    1778,   778,   779,  1778,   766,  1358,  1836,  1835,   763,   755,
     757,   758,     0,  1358,     0,     0,     0,   772,   761,     0,
     769,   752,   768,   753,  1519,  1518,     0,  1504,     0,  1783,
    1368,   824,  1554,  1492,     0,  1621,   831,     0,   829,     0,
       0,  1476,   858,   879,   884,     0,     0,  1493,  1368,  1758,
    1632,  1551,   897,   692,   894,  1392,  1364,   693,   911,  1725,
     692,  1362,   917,   916,   915,   914,   925,  1363,  1758,   928,
       0,   931,   932,     0,  1758,   935,   936,   937,   938,     0,
     939,  1363,   926,     0,   786,   904,   905,   902,   903,     0,
    1368,     0,   854,   962,   977,   979,   978,   972,   974,   980,
    1398,   969,   966,  1398,   970,  1428,  1401,  1402,  1785,  1001,
    1472,   692,  1009,  1010,  1820,  1025,  1026,  1028,  1030,  1031,
    1027,  1029,  1020,  1820,  1016,     0,  1065,     0,  1067,  1066,
    1068,  1050,  1060,     0,     0,  1044,  1218,     0,  1749,     0,
    1078,  1368,     0,     0,     0,  1096,  1106,  1119,  1115,  1120,
    1116,  1121,     0,  1111,  1352,  1351,  1118,  1127,  1346,  1538,
    1539,  1540,     0,     0,  1390,     0,   692,     0,  1166,     0,
       0,     0,  1203,     0,  1207,  1206,  1199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1187,  1188,  1626,  1390,
       0,  1251,  1250,  1812,  1812,  1266,  1267,  1268,     0,  1368,
       0,     0,   691,     0,  1613,     0,  1268,  1155,  1715,     0,
    1758,  1611,  1586,  1587,  1588,  1609,  1606,  1607,  1584,  1600,
       0,  1582,  1583,   482,     0,     0,  1880,  1881,  1758,  1719,
       0,   499,   503,  1742,   507,     0,     0,   601,   602,   605,
     606,     0,   633,  1779,  1758,  1818,  1758,   634,   632,   646,
    1758,   665,   666,   669,     0,   660,   675,   677,  1758,   788,
       0,     0,   776,   777,     0,   692,   767,  1360,   754,   756,
    1358,   764,   759,   760,   773,   762,  1521,  1503,  1520,  1631,
       0,   692,   820,  1370,  1552,  1553,  1368,     0,  1620,   830,
     832,   839,   837,   863,   862,   866,  1756,   883,   882,   887,
       0,  1391,   692,  1389,   695,  1366,   906,     0,   929,   930,
     933,   934,     0,  1394,  1394,   927,   908,   920,   921,   919,
     922,     0,   948,     0,   849,   850,   664,     0,  1398,  1398,
     976,   692,   973,     0,  1008,   692,  1011,  1006,     0,     0,
    1032,     0,     0,     0,  1061,  1063,     0,  1056,  1070,  1057,
    1058,  1049,  1052,  1070,  1210,  1758,  1763,     0,  1750,  1217,
    1079,  1082,     0,  1096,  1095,  1099,  1088,     0,  1107,  1104,
       0,     0,  1129,  1128,   692,  1149,  1378,  1154,  1156,     0,
    1168,  1398,  1398,  1163,  1169,  1186,  1198,  1200,  1190,  1191,
    1192,  1196,  1193,  1197,  1194,  1195,  1189,  1627,  1243,     0,
    1240,  1241,  1235,     0,  1228,  1860,  1859,     0,  1813,  1254,
    1254,  1373,     0,  1631,  1274,     0,   684,     0,  1614,  1299,
    1300,     0,  1303,  1306,  1310,  1304,  1390,  1716,     0,   470,
     467,   468,     0,  1601,   309,   504,  1772,  1773,  1562,   515,
     512,   352,   528,   508,   509,  1533,   623,  1531,  1532,   622,
     639,   645,     0,   642,   667,   668,   677,   695,     0,     0,
    1358,   781,   783,   782,  1359,   692,  1357,   765,  1368,  1493,
    1369,   692,  1367,  1551,   821,  1622,  1524,  1525,  1841,  1842,
     868,   692,  1783,  1757,   865,   864,   860,     0,  1635,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1634,  1393,     0,   941,
     940,   943,     0,  1536,  1537,   942,     0,   912,  1368,  1459,
    1368,  1459,   851,   852,     0,   856,   855,   857,   975,   981,
     971,  1003,  1007,  1018,  1021,  1022,  1737,  1014,  1820,  1019,
    1070,  1070,     0,  1055,  1053,  1054,  1059,  1220,     0,  1214,
    1751,  1368,  1089,  1098,     0,  1122,     0,     0,  1136,     0,
    1382,   692,  1377,  1157,   692,   692,  1170,  1242,  1232,  1236,
    1237,  1238,  1239,  1230,  1252,  1255,  1253,   692,  1262,  1375,
    1758,  1368,  1368,   686,  1288,  1613,  1302,  1747,  1308,  1747,
    1373,   692,   692,  1344,  1354,  1385,  1386,  1353,  1350,  1349,
    1768,   469,   463,   511,  1847,  1848,   514,   354,   529,   510,
     637,   635,   638,   636,   640,   641,     0,   617,   643,   644,
       0,   695,   787,   792,  1758,   793,   794,   795,  1758,   796,
     797,   798,   799,   800,   801,   802,   804,   805,   806,     0,
     807,  1717,   808,   809,   810,   789,   790,   751,  1361,   822,
    1371,   692,   842,   867,     0,   859,  1857,  1858,  1395,   923,
     950,     0,   949,     0,   853,  1023,  1738,     0,     0,  1051,
    1062,  1070,  1754,  1754,  1071,     0,     0,  1223,  1219,  1213,
    1083,  1097,     0,  1130,  1758,  1390,     0,     0,  1131,     0,
    1135,  1383,  1164,  1171,  1374,   692,  1372,     0,  1276,  1275,
    1314,   685,     0,  1301,     0,  1747,  1305,     0,  1297,  1387,
    1388,  1384,  1769,  1770,  1348,     0,  1758,  1758,     0,   516,
     517,   518,   519,   520,   521,     0,   531,   620,   621,     0,
       0,     0,  1758,  1394,  1394,  1718,     0,   791,   869,   861,
    1368,  1368,     0,  1033,  1069,  1755,     0,     0,  1758,  1221,
       0,     0,  1211,  1215,     0,     0,  1126,  1139,  1380,  1381,
    1138,  1134,  1132,  1133,  1376,  1269,  1321,   687,  1307,     0,
    1311,  1867,  1866,  1758,     0,     0,  1869,     0,  1758,  1758,
     513,  1805,     0,   812,   811,     0,   814,   813,   815,  1534,
    1535,   952,   951,  1024,  1073,  1072,     0,  1224,  1758,  1398,
    1137,  1379,  1341,  1340,  1322,  1315,  1316,  1717,  1317,  1318,
    1319,  1339,     0,  1309,     0,   526,   522,  1868,     0,     0,
    1752,  1780,  1719,     0,     0,     0,  1758,  1783,   530,  1758,
    1758,     0,   536,   538,   547,   539,   541,   544,   532,   533,
     534,   543,   545,   548,   535,     0,   540,     0,   542,   546,
     537,  1780,  1719,   676,   803,  1222,     0,  1123,     0,  1810,
    1785,   523,   525,   524,  1753,   586,  1781,  1782,  1760,   572,
    1758,   457,  1398,     0,     0,     0,     0,     0,   580,     0,
     570,   576,   579,     0,   573,   581,   584,  1760,   575,  1225,
       0,  1811,     0,     0,   571,     0,  1818,   568,  1631,   564,
    1506,  1871,     0,     0,  1873,  1875,     0,  1879,  1877,   549,
     553,   557,   557,   551,   555,   550,   556,   587,     0,   578,
     577,   583,   582,   574,  1338,  1840,  1839,  1793,  1334,  1328,
    1329,  1331,   562,   459,   585,  1785,   563,  1507,  1870,  1874,
    1872,  1878,  1876,   560,   552,   560,   554,     0,  1794,  1785,
    1337,  1332,  1335,     0,  1330,   454,     0,     0,   559,   558,
       0,     0,  1336,  1333,     0,   453,   567,   565,   566,   561,
     569,  1327,  1324,  1326,  1325,  1320,  1323,   455
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
     434,   503,   435,   534,   566,   567,   827,   568,  1662,  1009,
     763,   569,   570,   703,   833,   571,   572,   828,  1002,  1003,
    1004,  1005,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   758,   814,
     815,   816,   817,   818,   500,   683,   589,   661,   662,   663,
     792,   664,   665,   666,   667,   668,   669,   670,  2544,  2675,
     671,   782,  1144,  1379,  1380,  1644,  1641,  2150,  2151,   672,
     673,   674,   675,   676,   992,   788,   789,  1178,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1186,  1416,
    1669,  1670,  1954,  2163,  1671,  2159,  2313,  2429,  2430,  2431,
    2432,  2433,  2434,  1951,  2162,  2436,  2491,  2548,  2549,  2619,
    2654,  2668,  2550,  2551,  2646,  2677,  2552,  2553,  2554,  2555,
    2556,  2557,  2590,  2591,  2594,  2595,  2558,  2559,  2560,   588,
     776,   840,   841,   842,  1188,  1417,  1705,  2324,  2325,  2326,
    2330,  1706,  1707,   713,  1424,  1977,   714,   845,  1018,  1017,
    1191,  1192,  1193,  1421,  1713,  1020,  1715,  2176,  1138,  1364,
    1365,  2293,  2411,  1366,  1367,  1921,  1776,  1777,  2024,  1368,
     779,   898,   899,  1092,  1199,  1200,  1741,  1428,  1484,  1721,
    1722,  1718,  1979,  2180,  2355,  2356,  1426,   900,  1093,  1206,
    1440,  1438,   901,  1094,  1213,  1758,   902,  1095,  1217,  1218,
    1760,   903,  1096,  1226,  1227,  1494,  1812,  2044,  2045,  2046,
    2015,  2016,  2206,  2200,  2362,  1449,   904,  1097,  1229,   905,
    1098,  1232,  1456,   906,  1099,  1235,  1461,   907,   908,   909,
    1100,  1244,  1470,  1473,   910,  1101,  1247,  1248,  1478,  1249,
    1482,  1804,  2039,  2227,  1787,  1801,  1802,  1476,   911,  1102,
    1254,  1490,   912,  1103,  1257,   913,  1104,  1260,  1261,  1262,
    1499,  1500,  1501,  1822,  1502,  1817,  1818,  2050,  1496,   914,
    1105,  1271,   915,  1106,  1272,   916,  1107,  1275,   917,  1108,
    1278,  1829,   918,   919,  1109,  1833,  2057,   920,  1110,  1282,
    1542,  1842,  2060,  2244,  2245,  2246,  2247,   921,  1111,  1284,
     922,  1112,  1286,  1287,  1548,  1549,  1854,  1550,  1551,  2071,
    2072,  1851,  1852,  1853,  2065,  2253,  2384,   923,  1113,   924,
    1114,  1296,   925,  1115,  1298,  1558,   926,  1117,  1304,  1305,
    1562,  2086,   927,  1118,  1308,  1566,  2089,  1567,  1309,  1310,
    1311,  1868,  1870,  1871,   928,  1119,  1318,  1883,  2268,  2395,
    2466,  1574,   929,   930,  1120,  1320,   931,   932,  1121,  1323,
    1581,   933,  1122,  1325,  1884,  1584,   934,   935,  1123,  1328,
    1590,  1887,  2103,  2104,  1588,   936,  1124,  1333,   159,  1602,
    1334,  1335,  1906,  1907,  1336,  1337,  1338,  1339,  1340,  1341,
     937,  1125,  1291,  2257,  1552,  2389,  1856,  2074,  2387,  2462,
     938,  1126,  1349,  1909,  1610,  2119,  2120,  2121,  1606,   939,
    1351,  1613,  2284,  1132,   940,  1133,  1353,  1354,  1355,  2131,
    1617,   941,  1134,  1358,  1622,   942,  1136,   943,  1137,  1360,
     944,  1139,  1369,   945,  1140,  1371,  1631,   946,  1141,  1373,
    1635,  2139,  2140,  1926,  2142,  2298,  2416,  2300,  1633,  2412,
    2476,  2515,  2516,  2517,  2685,  2518,  2639,  2640,  2663,  2519,
    2520,  2521,   947,  1142,  1375,  1579,  1927,  1876,  2303,  1637,
    1986,  1987,  2186,  1479,  1480,  1781,  2002,  2003,  2192,  2288,
    2289,  2406,  2095,  2467,  2096,  2272,  2304,  2305,  2306,  1774,
    1775,  2023,  2221,  1280,  1281,  1264,  1265,  1529,  1530,  1531,
    1532,  1533,  1534,  1535,   974,  1165,  1383,   976,   977,   978,
     979,  1207,  1236,  1464,  1321,  1329,   395,   396,  1012,  1342,
    1343,  1539,  1312,  1220,  1221,   541,   481,   301,   691,   692,
     482,    98,   153,  1273,  1238,  1208,  1441,  2609,  1390,   981,
    1746,  1997,  2073,  2195,  1230,  1313,  2166,  2498,  2222,  1878,
    2167,  1292,  1346,  1210,   983,  1239,  1240,   734,   784,   785,
    2168,   271,  2592,   179,  1211,   760,   761,  1212,   986,   987,
     988,  1173,  1146,  1398,  1394,  1387,   501,  2141,   537,  1444,
    1756,  2008,  1577,  2123,   282,  1467,  1770,  2216,   794,  1091,
    2148,  2446,   604,   339,   684,  1430,   423,  1194,   202,   115,
     393,  2377,   337,  1955,   352,  1010,   770,  2079,  2575,  2456,
    2207,    96,   214,   414,   739,  2424,  1950,   766,   402,  1964,
    2578,   798,  1378,   218,   488,  2659,   168,   390,   731,   102,
     719,   680,   831,  2602,  2129,   350,  1541,   951,  1279,   407,
     729,  1179,  1317,   391,  1723,  1743,  1465,  2637,  2201,   184,
     695,  2316,   708,   347,   596,  1458,  2368,  2127,   538,   203,
    2483,  2489,  2622,  2623,  2624,  2625,  2626,  1673
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2286
static const yytype_int16 yypact[] =
{
   -2286,   251,   -31, -2286,  -197,  -194, -2286,   -31, -2286, -2286,
     513, -2286, -2286,   513,   513,   -69,   -69, -2286,   790, -2286,
     894,   721,   951, -2286, -2286,  1089,  1089,   710,   780, -2286,
   -2286,   604,   513,   -69, -2286, -2286,  1025,   839, -2286, -2286,
     870,  1695,   -69, -2286, -2286, -2286,   721,   876, -2286, -2286,
     174, -2286,   830,   830,   926,   955,  1155,  1155,  1155,   999,
     830,   995,   952,   960,  1155,   972,   998,  1408, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286,  1191, -2286, -2286, -2286, -2286,
    1250, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1337,  1030,   604, -2286, -2286,  1070,   157, -2286, -2286,  1155,
    1155, -2286,  1155,  1024,  1470,  1024,  1099,  1155,  1155, -2286,
   -2286,  1024, -2286, -2286, -2286,  1038,   988,  1106, -2286, -2286,
    1054, -2286,  1114, -2286, -2286, -2286, -2286,   590, -2286, -2286,
   -2286,  1226, -2286,  1155,  1267,  1024,  1306,   -12, -2286, -2286,
   -2286, -2286, -2286,  1312,  1101,   123,  1381, -2286,  1079, -2286,
    1038, -2286,    46, -2286, -2286, -2286, -2286, -2286,   489,    -9,
    1155,     2, -2286, -2286, -2286,   533, -2286, -2286, -2286,  1266,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1267, -2286,  1143,
   -2286,  -158, -2286, -2286,  1024, -2286,  1186, -2286,  1190,  1189,
    1533,  1155, -2286, -2286, -2286,   858, -2286, -2286, -2286, -2286,
   -2286,   758,  1541,  1155,    65, -2286,    83, -2286, -2286,    81,
   -2286, -2286, -2286, -2286,  1347,    -9, -2286,  1382,   830,   830,
   -2286,   489,  1164,    62,   -71, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   573, -2286,
      86, -2286,  1267, -2286, -2286,  1288, -2286, -2286, -2286,  1155,
    1217,  1363, -2286, -2286, -2286, -2286,   910,  1155,  1116,  1392,
     -36, -2286,  1601,   559,  1180, -2286, -2286,  1184,  1530, -2286,
    1347, -2286,   830, -2286, -2286, -2286, -2286,   489, -2286,  1187,
    1327, -2286,   830, -2286,   644, -2286,   165, -2286, -2286, -2286,
   -2286, -2286,   573, -2286,  1384,  1363, -2286, -2286, -2286,   -96,
   -2286, -2286, -2286,  1385, -2286, -2286, -2286, -2286, -2286,  1371,
   -2286, -2286, -2286, -2286, -2286,  1195, -2286, -2286, -2286,  1622,
    1548,  1204, -2286, -2286,   573, -2286, -2286,    28, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1219, -2286,  1472,
    1536,  1207, -2286,  1646, -2286, -2286, -2286, -2286,  1820, -2286,
    1581, -2286,  1165,  1220,  1276, -2286,   573,  1396,  1321,   329,
    1273, -2286,  1275,  1155,  1619,   222,   152,   -11, -2286,  1177,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1253,
   -2286,  1419, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1645,  1155, -2286,  1165, -2286,  1165, -2286, -2286,  1237,    48,
   -2286, -2286,  1155, -2286,  1455, -2286, -2286,   923, -2286, -2286,
     981,  1155,  1155, -2286,  1155,  1155, -2286,  1622, -2286,   313,
    1155,  1396, -2286,  1292,  1193,  1165, -2286,  1362, -2286, -2286,
   -2286, -2286,  1194, -2286,  1197,    59,    18,  1155, -2286, -2286,
    1034, -2286, -2286,  -111,  1279,  1024,  1024, -2286,  1386,  1386,
    1393, -2286,  1024,  1155, -2286, -2286, -2286,  1363, -2286,  1310,
    1444, -2286, -2286,  1257, -2286, -2286, -2286, -2286, -2286,  1024,
   -2286, -2286,   -85,   -85,  1702,   -85, -2286, -2286,   -85,   -80,
   -2286, -2286, -2286, -2286, -2286,   576, -2286, -2286, -2286, -2286,
   -2286, -2286,   586, -2286,  1260,  1319,  1457,   496,  1264,  6231,
   -2286,  1215, -2286, -2286,     7, -2286, -2286, -2286, -2286,  1195,
   -2286, -2286, -2286, -2286, -2286,  1155,  1024,  1218, -2286,  1218,
   -2286, -2286,  1272,  1324,  1351, -2286,  1277, -2286,  1278, -2286,
    1637, -2286,  1639, -2286,  1597, -2286,  1602, -2286, -2286, -2286,
    1024,  1024, -2286,   495, -2286, -2286,  1197, -2286,  1281,  1336,
    1344, -2286, -2286, -2286,   898,  1581,  1155,   712,   712,  1155,
       8,  1396,  1155,  1712, -2286,  1430, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,   830,   784, -2286,  1024,
   -2286,  1426, -2286, -2286,  1197, -2286,  1287,  1343, -2286,  6539,
     675,  1535,  1363,  1236,  1155,  1712,  1239,  -104,  -111,  1363,
    1242,  1155, -2286, -2286, -2286,   -56,   830, -2286, -2286, -2286,
     691, -2286,  1197, -2286,  1294,   638,   553, -2286, -2286,   336,
     357,   381,   486,   537,  1245, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286,  1366, -2286,  1363, -2286, -2286, -2286, -2286,  1024,
    1024,  1522, -2286, -2286, -2286,   510, -2286, -2286, -2286,  1155,
     146, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   915,
    -108, -2286,  1251, -2286,   899, -2286,  1313, -2286, -2286, -2286,
   -2286,  1239, -2286, -2286, -2286, -2286,  1517,    51,  1555,  1280,
    1155, -2286, -2286,  1155, -2286,   865, -2286, -2286, -2286, -2286,
   -2286, -2286,  1653, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1269,
   -2286, -2286,  1334, -2286,  1325,  1346, -2286, -2286, -2286, -2286,
    5920,   746,  1759, -2286,  1390,  1390, -2286,  1271,  1486, -2286,
    1323,  1323, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1349, -2286,  1363,   103, -2286, -2286, -2286,  1363, -2286, -2286,
    1391, -2286,   130,   130, -2286,  1446,  1296,    38,  2890,  3350,
   -2286,  1363,  1359,  7025,  1345, -2286,  1024, -2286,   746, -2286,
    1367,  1554, -2286,  1619, -2286, -2286, -2286, -2286,  1323,  1361,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286,  1271, -2286, -2286, -2286, -2286,    43,  1408,
   -2286,   737, -2286, -2286, -2286, -2286,  1309, -2286,  6049, -2286,
   -2286,  1296,  1364, -2286, -2286,  1438,  3734, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,  1418, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   690, -2286,
   -2286,  1482, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286,  1705, -2286, -2286,  1358,  6549,   -12,   -12,  1360,  1369,
    1373, -2286,  1376,   -12, -2286, -2286, -2286,  7114,  7025,  7114,
    1380, -2286,  1358, -2286,   209,   854,   678, -2286,  1652, -2286,
   -2286, -2286, -2286, -2286,  1349, -2286,  1383,  1388,  1389,  7025,
   -2286, -2286,  -189, -2286,   746, -2286, -2286, -2286, -2286, -2286,
    -111,  -111, -2286, -2286, -2286, -2286,  1636, -2286, -2286,  1313,
    1363, -2286, -2286,  1374, -2286,  1377, -2286,    53,    53,  1328,
    1401, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286,   431,  4521,  7025,   424,   501,   428,  1165,   467,
     266,  5425,  5576,  1577,   588,   867,   467,  1024,  1397, -2286,
     467,  1309,  1370,  1024,  4617,  5576, -2286,   799,  3650,  1165,
    1024,  1165,  1024,    55,   256,  1024,  1165, -2286, -2286, -2286,
   -2286, -2286, -2286,  4796,  4825, -2286, -2286,  1309,    89,  1024,
    1165,  1024,  1024,  1545, -2286,  6648, -2286, -2286,  1349, -2286,
    1352,  1353,  7025,  7025,  7025,  6549,  1357, -2286,   943, -2286,
    6549, -2286, -2286, -2286, -2286,  7025,  6921,  7025,  7025,  7025,
    7025,  7025,  7025, -2286,  6549,  7025,   854,  1452, -2286,  1409,
   -2286, -2286, -2286,  1833,  1408, -2286,   153, -2286, -2286, -2286,
   -2286,   161, -2286,  -145,   454,   452, -2286, -2286, -2286,  1734,
     838,  1670,  1486,  1024,  6549, -2286,  1738, -2286,  4893, -2286,
   -2286, -2286, -2286, -2286,    40,   954, -2286,   424, -2286,  1425,
   -2286,   -12, -2286, -2286, -2286, -2286,  1741,  3462, -2286,   428,
   -2286, -2286,  1165,  1308,  1486,  1743,   704, -2286,  1496, -2286,
   -2286,  1325,  1349,  1165,  1750,  1321,  1087,  1751,  5111, -2286,
    5149,   147,  1091,  1122,  1749,   550,  1395, -2286, -2286, -2286,
    1752,    82, -2286, -2286, -2286,  4233, -2286, -2286,  1787, -2286,
   -2286, -2286, -2286,   467, -2286, -2286, -2286, -2286, -2286, -2286,
    1449, -2286, -2286,   635,  1309, -2286, -2286,    25, -2286, -2286,
   -2286, -2286, -2286, -2286,  1431,  5576, -2286,  1445,  1754,  1846,
   -2286, -2286, -2286, -2286,   799,  1492, -2286,  1454, -2286,  5165,
     -34,  -229,  1460,  1459, -2286,   338, -2286,  1458,  1762,   769,
   -2286,  1710, -2286,  1763,  1321,  1764,  1710,  1024,  1765,  1411,
   -2286,   841, -2286, -2286, -2286, -2286, -2286, -2286,  1641, -2286,
     467, -2286,   440, -2286,   449,  1882, -2286,    52, -2286,  1768,
     986,   542,  1867,  1770,  4399, -2286, -2286,  1024,  1771,  5234,
    1309, -2286, -2286,   546, -2286, -2286, -2286, -2286,  3079, -2286,
    1723, -2286,   963,  1772,  1811,  1774,  1710, -2286,  1024,  1716,
     185, -2286,   238,  -205, -2286, -2286,   280,  1489,  1491,  1494,
     241, -2286,  1349, -2286,  1495, -2286, -2286,   289,  1499,  -205,
   -2286,   974,   678,   678, -2286, -2286, -2286,  1037,  1502,   342,
    1505,  1155, -2286,  -111,  1839,  1504,    75,  6756, -2286,  1155,
    1546,  1649, -2286, -2286,  1849, -2286, -2286,   841,  1767, -2286,
      73,  1394,   -47,  1520, -2286,  1349, -2286, -2286, -2286,  5681,
    1766, -2286,  1744, -2286,  1594, -2286,  1633,  1717, -2286, -2286,
   -2286,  1395, -2286,  1308, -2286, -2286, -2286,   519,   430,  1024,
   -2286, -2286, -2286, -2286, -2286,  7025,  1703, -2286,  1345, -2286,
    1165, -2286, -2286, -2286,  1745, -2286, -2286, -2286,  5576, -2286,
    1680,   129,  1683,  1992,  1498,  1818,  1818,  1818,  1818, -2286,
   -2286,  5576,  5681, -2286, -2286, -2286, -2286,   588,    56, -2286,
    1484, -2286,  1485, -2286, -2286, -2286, -2286,  1397, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  3966,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   -10,
   -2286,  1860,  1213,  1814, -2286,   841,    92, -2286, -2286,  1625,
   -2286, -2286,    35,  7025, -2286,  1547,   467, -2286, -2286,  5681,
    1492,  1177,  1165, -2286, -2286, -2286, -2286, -2286,  1823,  1024,
     424, -2286,  1076, -2286, -2286, -2286, -2286,  1321,  1370, -2286,
   -2286, -2286,  1769, -2286, -2286,   -28,  1865, -2286, -2286,  1024,
    1865,  1549, -2286,  1349, -2286, -2286,   331,   489, -2286, -2286,
    4331, -2286,  1949,  1111,    61, -2286, -2286, -2286,  1155, -2286,
     414,  5576,  5576, -2286,    24,  5302, -2286, -2286,  1024, -2286,
    1804, -2286, -2286,  5681, -2286,  1363, -2286, -2286,   841, -2286,
   -2286, -2286, -2286, -2286,  1867,  1773, -2286, -2286,  1076, -2286,
    1867, -2286, -2286, -2286,  1455, -2286,  1024,  1383,  1383,  1383,
    6549, -2286,   -95,  1383, -2286,  6999,  1383,  1383, -2286,   746,
   -2286,  1545, -2286, -2286,  1155,  1155,  1712,  1192, -2286, -2286,
   -2286, -2286,  1798,  1827, -2286,  1155, -2286,   447, -2286, -2286,
   -2286,  1181,  1155,  3462, -2286, -2286, -2286,  1706, -2286,  1363,
   -2286,  1948, -2286, -2286, -2286,  1024, -2286, -2286,  1024, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1802,  1706,
     131,  1155, -2286,  1503,  1557, -2286, -2286, -2286,  1737,  1706,
    1706,   297,  1758,  1706, -2286,  1851, -2286, -2286, -2286,  1508,
    1506, -2286,   841,  1851,  1781,  1588,  1720, -2286, -2286,  1748,
   -2286, -2286, -2286, -2286, -2286, -2286,   453, -2286,  1024,  1486,
     345, -2286,   -13,   -45,   467,  1574,  1594,   467, -2286,  1575,
     424, -2286,   -52, -2286, -2286,  1648,  1663, -2286,   736,  1155,
   -2286, -2286, -2286, -2286, -2286,  1731, -2286, -2286, -2286,  1999,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1818,  1155, -2286,
     -68, -2286, -2286,  1222,  1155, -2286, -2286, -2286, -2286,    -3,
   -2286,  1977, -2286,  1274,  1737, -2286, -2286, -2286, -2286,  1828,
     345,  1830,    66, -2286, -2286, -2286, -2286,  2017, -2286,  1593,
     298, -2286, -2286,    56, -2286, -2286, -2286, -2286,  1545, -2286,
   -2286, -2286,  1908,  1902,  1397, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286,  1677,  1397, -2286,  1598, -2286,  1994, -2286, -2286,
   -2286,   884, -2286,   841,   917, -2286,    64,   185,     1,   467,
     467,   345,  1843,  1165,   313,   879,  1906, -2286, -2286, -2286,
    2042, -2286,  1859, -2286, -2286, -2286, -2286,  1769, -2286, -2286,
   -2286, -2286,  1024,  1927,  1745,   722, -2286,  1556, -2286,  1558,
     841,   820, -2286,   453, -2286, -2286, -2286,  5576,   489,   489,
     489,   489,   489,   489,   489,   489,  1111, -2286,   741,  1745,
     475, -2286, -2286,  1635,  1635, -2286, -2286,  -150,  1024,   345,
    1862,  1611, -2286,  1617,  2057,  1024,   569,   -28,  2062,  1566,
    1155, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1082, -2286, -2286, -2286,  1024,   428, -2286, -2286,  1155,  1712,
    1819,  1296, -2286, -2286, -2286,  1024,   -89, -2286, -2286, -2286,
   -2286,   -89, -2286, -2286,  1155,  1359,  1155, -2286, -2286, -2286,
    1155, -2286, -2286, -2286,   566, -2286, -2286, -2286,  1155,  1571,
     -89,   -89, -2286, -2286,   -89, -2286, -2286,  1782, -2286, -2286,
    1851, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1496,
     -47, -2286, -2286,  1780,    -4,  1875,   345,   523, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286,   101,   128, -2286, -2286, -2286,
     798, -2286, -2286, -2286, -2286, -2286, -2286,   -89, -2286, -2286,
   -2286, -2286,   -89,   457,   457, -2286, -2286, -2286, -2286, -2286,
    1576,   467, -2286,   467,  3331, -2286,   446,    23,    56, -2286,
   -2286, -2286,  2017,  1024, -2286, -2286, -2286, -2286,  1582,  1173,
     194,  1583,   523,   841, -2286, -2286,  2035, -2286, -2286, -2286,
   -2286,   917, -2286,  1899, -2286,  1155,  1455,  1776, -2286, -2286,
     467, -2286,   467,   879, -2286, -2286, -2286,   948, -2286, -2286,
    1024,  5576,  1031, -2286, -2286, -2286,  1797, -2286, -2286,  1829,
   -2286, -2286, -2286, -2286,  1558, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,   -30, -2286,  1024,
   -2286, -2286, -2286,  1317, -2286, -2286, -2286,  7025, -2286,  5576,
    5576,  1631,  1777,  1496, -2286,   467, -2286,   523, -2286,  1783,
   -2286,   841, -2286,  1980,  1658, -2286,   733, -2286,   803, -2286,
    1566, -2286,  1024, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1174,   -63, -2286,  1024, -2286, -2286, -2286, -2286, -2286, -2286,
    -122, -2286,   428,  -122, -2286, -2286, -2286,    90,  2050,  1922,
    1851, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1687,  1896,
   -2286, -2286, -2286,  1897, -2286, -2286, -2286, -2286, -2286, -2286,
    1807, -2286,  1486, -2286, -2286, -2286, -2286,  1024, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  2554, -2286,
   -2286, -2286,  1212, -2286, -2286, -2286,  1992, -2286,   345,  1742,
     345,  1747, -2286, -2286,  5576, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,  1173, -2286,  2000, -2286,  1397, -2286,
   -2286, -2286,   523,  1138, -2286, -2286,  1138,   -90,  1024, -2286,
   -2286,   345, -2286, -2286,  1724, -2286,  2060,  1844,  1876,   482,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286,  -205, -2286, -2286, -2286, -2286, -2286,  1821,
    1155,  1687,   345,  1624, -2286,  2057, -2286,  1555,  2023,  1555,
    1631, -2286, -2286, -2286, -2286,  1831, -2286, -2286, -2286, -2286,
    1228, -2286,  1024,  1026, -2286, -2286,  1819, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,   -89, -2286, -2286, -2286,
     -89,    26, -2286, -2286,  1155, -2286, -2286, -2286,  1155, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,  2063, -2286, -2286,    72,
   -2286,  2114, -2286, -2286, -2286,  1922, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,  1024, -2286, -2286, -2286, -2286,  1992,
   -2286,   467, -2286,   467, -2286, -2286, -2286,  2077,  2019,  1138,
    1138, -2286,  1674,  1674, -2286,  1794,  1165,   571, -2286,  1024,
   -2286, -2286,  5576, -2286,  1155,   777,  1870,  1872, -2286,  1874,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1024, -2286, -2286,
   -2286, -2286,  1688, -2286,  1024,  1555, -2286,  1024, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286,  1214,  1155,  1155,  1318, -2286,
   -2286, -2286, -2286, -2286, -2286,  1429, -2286, -2286, -2286,  2029,
     -89,   -89,  1155,   457,   457, -2286,   476, -2286, -2286, -2286,
    1687,  1687,  5576, -2286,  1138, -2286,  5576,  5576,  1155,  1165,
    1165,  1806, -2286, -2286,  1660,  1024, -2286, -2286,  1797, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,  1104, -2286, -2286,  1024,
   -2286, -2286, -2286,  1155,  1819,  1819, -2286,  1934,  1155,  1155,
   -2286,  2326,  1694, -2286, -2286,   428, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,   424,  1165,  1155, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1178, -2286, -2286,
   -2286, -2286,  2039, -2286,  1819, -2286, -2286, -2286,  1819,  1819,
    1928,  1188,  1712,  1939,  1363,  1650,  1155,  1486, -2286,  1155,
    1155,  1024, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286,   720, -2286,   567, -2286, -2286,
   -2286,  1188,  1712, -2286, -2286, -2286,   424, -2286,  1786,  1732,
    1545, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   146, -2286,
    1155,  1334, -2286,  7311,  7311,  1423,  2037,  1958, -2286,  1363,
     720, -2286, -2286,  1363,   567, -2286, -2286,   146, -2286, -2286,
    1024, -2286,  1255,    45, -2286,   720,  1359, -2286,  1496,  7295,
   -2286, -2286,   961,  1017, -2286, -2286,  1045, -2286, -2286, -2286,
   -2286,   -44,   -44, -2286, -2286, -2286, -2286, -2286,  7311, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1822,   913,    45,
   -2286, -2286, -2286,  1705, -2286,  1545, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286,  1848, -2286,  1848, -2286,  2108, -2286,  1545,
   -2286, -2286,  1856,  1024, -2286,  1739,   -32,  1842, -2286, -2286,
    7311,   525, -2286, -2286,  1363, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,  1165, -2286
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2286, -2286, -2286, -2286, -2286,  2160, -2286, -2286, -2286,   206,
   -2286,  2122, -2286,  2078, -2286, -2286,  1291, -2286, -2286, -2286,
    1210, -2286, -2286,  1286,  2143, -2286, -2286,  2046, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  1973,
     564, -2286, -2286, -2286, -2286, -2286,  2027, -2286, -2286, -2286,
   -2286,  1970, -2286, -2286, -2286, -2286, -2286, -2286,  2102, -2286,
   -2286, -2286, -2286,  1959, -2286, -2286, -2286, -2286,  1944, -2286,
   -2286,   -57, -2286, -2286, -2286, -2286,  2034, -2286, -2286, -2286,
   -2286,  2014, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,   868, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,  1676, -2286,  1788, -2286, -2286, -2286,
    1727, -2286, -2286, -2286, -2286,   333, -2286, -2286,  1907, -2286,
   -2286, -2286, -2286, -2286,  1775, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1196, -2286, -2286, -2286,  1428, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,  -296,
   -2286, -2286,  1707, -2286,  -754,  -823, -2286, -2286, -2286,   200,
   -2286, -2286, -2286, -2286,  -567, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -1390,   789,  1467,   645,   664, -1387, -2286, -2286,
   -2286,  -370,  -431, -2286, -2286,   356, -2286, -2286,    67, -1386,
   -2286, -1382, -2286, -1381, -2286, -2286,  1427, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    -406,  -437, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -1307, -2286,  -375, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286,  1379, -2286, -2286, -2286,    49,    57, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
    1208,   247, -2286,   179, -2286, -2286, -2286, -2286, -1821, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286,  -817, -2286, -2286,  -698,
   -2286,  1456, -2286, -2286, -2286, -2286, -2286, -2286,  1028,   509,
     512, -2286,   437, -2286, -2286,  -121, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286,   490, -2286, -2286, -2286,  1043,
   -2286, -2286, -2286, -2286, -2286,   794, -2286, -2286,   203, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286,   808, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   785,
   -2286, -2286, -2286, -2286, -2286,    36, -1746, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   767,
   -2286, -2286,   765, -2286, -2286,   443,   221, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,    29,   730, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,   726, -2286, -2286,
     205, -2286,   426, -2286, -2286, -1954, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,   975,
     718,   197, -2286, -2286, -2286, -2286, -2286, -2286, -2285,   973,
   -2286, -2286, -2286,   191, -2286, -2286, -2286,   406, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286,   358, -2286, -2286, -2286, -2286, -2286,
   -2286,   694,   183, -2286, -2286, -2286, -2286, -2286,  -137, -2286,
   -2286, -2286, -2286,   383, -2286, -2286, -2286,   958, -2286,   957,
   -2286, -2286,  1167, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286,   168, -2286, -2286, -2286, -2286, -2286,   945,   375,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286,    10, -2286,   376, -2286, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -2286, -2286,  -336, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286,  -489, -2286,   668, -2286, -2286,
   -1622, -2286, -2286,  -670, -2286, -2286, -1686, -2286, -2286,     9,
   -2286, -2286, -2286, -2286,   -87, -2173, -2286, -2286,     6, -1843,
   -2286, -2286, -1928, -1522, -1064, -1456, -2286, -2286,   783, -1253,
     192,   195,   196,   198,   -75,  -144,  -771,   368,   276, -2286,
     544,  -683, -1351, -1042,  -886,   987, -1536,  -392,  -440, -2286,
   -1303, -2286, -1034, -1521,   875,  -529,   -98,  2024, -2286,  1634,
    -547,    20,  2172, -1065, -1057,  -857,  -524, -2286, -1095, -1388,
   -2286,   433, -1236, -1890, -1087, -1152, -1259, -2286, -2286, -2286,
   -1096, -2286,    54,  -293,  -625, -2286, -2286,  -103, -1185,  -761,
     -99,  2061, -1864,  2085,  -665,  1084,  -532,  -523, -2286, -2286,
   -2286,   -55,  1375, -2286, -2286,   400, -2286, -2286, -2286, -2286,
   -2286, -2286, -2286, -2286, -2286, -1941, -2286, -2286,  1585, -2286,
   -2286,  -185,  -591,  1916, -2286,  1151, -2286, -1308,  -268,  -628,
     719, -2286,  1837, -2286, -1433, -2286, -2097, -2286, -2286,   -41,
   -2286,    14,  -651,  -356, -2286, -2286, -2286, -2286,  -223,  -168,
    -225, -1184, -1523,  2124,  1900, -2286, -2286,  -338, -2286, -2286,
     896, -2286, -2286, -2286,   436, -2286,   291, -1918, -1455, -2286,
   -2286, -2286,  -175,   497, -1379, -2211, -2286, -2286, -2286,  -708,
   -2286, -2286,  1651, -2286,  1796, -2286, -2286, -2286,   806, -2286,
   -2239,  -226, -2286, -2286, -2286, -2286, -2286, -2286
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1830
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   689,   138,   245,   141,   139,   741,
     415,   579,   975,   147,  1252,  1014,   778,   160,  1432,   759,
     404,   215,   838,   990,   733,  1766,  1865,  1699,  1345,  1857,
    1701,  1702,   139,   427,   268,  1703,  1704,   180,  1709,  1598,
    1263,  2097,  1819,   464,  1615,  1283,  1869,  2171,   437,  1274,
    1459,   696,  1825,  1274,  2638,  2035,  1468,  1237,  2188,  1344,
     463,  1219, -1785,   279,  1327,  1397,  2124,  1274,   211,   768,
     103,   104,   105,    99,   259,  1451,   790,  1814,   111,  1408,
     107,   246,  2019, -1543,   264,   345,  2160,   838,  1750,  -652,
    -650,  1000, -1544,   843,   392,  1591,   411,  1442,   220,  1497,
     980,  1846,  1190,   291,  1828,  1744,  2225,  1564,   114,  1554,
    2235,  1991,   529,   134,   135,  1190,   136,  1545,   700,  2256,
    2033,   143,   144,   790,  2042,   821,   821,   360,  1742,  1507,
     161,   535,  2653,   744,  2202,  2385,  1664,  1679,  1944,  1680,
     215,  1810,  1452,   465,  2676,   480,  1936,   169,  2320,  1847,
   -1785,  2013,   297, -1729,  1415,  2439,  2177,   701, -1570,   535,
     825,   328,  1604,  1971,  1665,  1666,   321,   154,   211,     4,
   -1829,   505,  2250,   821,   219,  2081,   512,  1427,  1785,   187,
   -1829,   221, -1731,  1219,  2028,  1913,   188,    23, -1829,  2488,
   -1549,  1716,  2291,   -96,   419,  2443,   327,  1158,   453, -1547,
    2414,  1007,  2417,   283,   693,   251,   182,  2321,  1861,   839,
    1190, -1725,  1642, -1725,  -500,   796,  1538,   258,  1176,  2077,
     430,  2565,  2469,   216,  2490,  1782,  1538,  -652,  -650,   127,
   -1829,  -652,  -650,  2134, -1829,   325,  1326,    43,   274,   275,
      94,  1972,  -500,  -500,  1250,   154,  1216,  2294,  1150,  1151,
     583,     3,  1568,  1167,    15,  1156,  1376,    16,  1168, -1829,
     985, -1798,  1234,   295, -1827,  1419,  2198,   344,   418,  1848,
    1569,   299,  1919,    24,   839,  1596,   416,  1359,   212,  1162,
    2562,  2599,   204,  1274,   980,   980,   980,  1538,   611,  -652,
    -650,   999,   311,  1745,   183,  2511,  2379,  2380,    43,   400,
    1643,  1216,   314,  2307, -1816,  2053,   980,    94,  1162,  1845,
       5,  1162,  1177,  1914,   694,  2078,   709,   284,  2479,  1814,
    2194,  2029,   448,  1214,  2014,  1719,  1924,  2083,   128,  1180,
    1147,  1420,  1929,  1849,   -96,   412,  2322,  1234,   601,   329,
     139,  2323,   139,   139,  1377,   243,  2620,   485,   486,   139,
    1162,  1234,   280,   243,   491,  2331,  2203,  -500,   493,  1162,
     745,  1679,  2381,  1680,  1819,   466,   139,  1819,  2187,   507,
     507,   485,   507,  1937,   281,   507,   514,   410,   212,  2058,
    2236,  1386,  1386,  1386, -1763,  -500,   832,   154,  2061,   413,
    1546,   189,  1923,   137,  1399,  1401,  1667,  1237,   330, -1725,
    1332,  1407,   823,  2006,  1720,   424,    94,  2386,   300,  1331,
   -1729,   980,  1162,   139,   217,   137,   436,  1565,   542,   137,
     467,  2165,  1522, -1729,   137,   443,   444,  2454,   445,   446,
    -652,  -650,  1149,  1263,   452,   260,  2204,   139,   139,   283,
     431,  2317,   542,   580,   985,   985,   985,  1289,   702,   783,
    1237,   469,  2435,  1181,  1182,  1234,   826,   137,   989,   413,
     137,  1547,   980,   190,  1783,   368,   985,   492,   749,   980,
     980,   980,   137,  1234,  -500,   243,   139,  1362, -1725,  2034,
    1469,   580,   980,   980,   980,   980,   980,   980,   980,   980,
     982,  1860,   980,   686,   137,   139,  1990,   767,  1167,  1274,
     697,  1190,  2359,  1168,  2047,  1830,    97, -1758,  1001,  1815,
     536,   129,   752,  1447,   783,  2496,  2497,  1237, -1729,   191,
    1816,  2237,   753,   989,   192,   996,  1668,  1332,   292,   540,
    1363,  1962,   747,   346,   265,   844,  1873,  -657,   536,  1538,
    1362,  1362,  2370,   749,  2372,   732,   243,   735,   577,   137,
     149, -1729,  2470,   284,  2444,  1935,  1414,   749,  2357,   137,
    1850,   261,  2199,   394, -1729,  2000, -1628,  2004,   591,  1209,
     593,   985,  1599,   598,   600,  2390,   602,  1251,  1255,  1434,
    2275,  1237,  2500,  1498,   243,   255,  1469,   752,  2205,  1290,
    1297,  1299,  1819,  1363,  1363,  1316,   607,   753,  2174,  1491,
     449,   752,   754,   679,  -500,  2408,  2409,  1163,   688,  1356,
    1209,   753,  -657,   130,  2051,   699,   322,  2066,   351,   517,
    2525,  2526,   985,  2035, -1798,   -35,   704,   193,  1720,   985,
     985,   985,  1393,  1784,   137,  1540,  1163,  1393,  -647,  1163,
   -1816,  1234,   985,   985,   985,   985,   985,   985,   985,   985,
    1483,  1393,   985,  1006,  2105,  2122, -1763,  1164, -1829, -1729,
    2571,   749,   450,   824,  2572,  2573,    18,  2644,   829,   834,
     834,  1285,   755,   740,   982,   982,   982,   754,  1163,   749,
    1216,  1436,   949,   991,  1228,  1824,  1645,  1163,  2643, -1608,
    2228,   754,  2230,  2596,  1768,  2681,   982,  1361,  2396,  1957,
    2010,   681,  2169, -1829,  1316,   752,  1233,  1771,  1245,  1996,
    1234,  1332,  1237,   154,   772,   753,   756,   773,  2397,  2125,
    1243,  2181,  2182,   752,  1832,  2183,  2012,  1319, -1610,  1324,
    2596,  2261,  2158,   753,  1350,   749,  2047, -1605,  1167,  1198,
    1163,  1536,   717,  1168,  2398,  1611,    42,   755,  1372,  1866,
    2682,  1815,   737,   518,  2233,   747,  2001,   581,  2683,   253,
     137,   755,  1816,   717,  2501,  2502,   757,   222,  2219,  2399,
     394,  1555,  1223,  2220,  2460,   405,  -647,  1891,  1492,   752,
    -647,  1764,   980, -1549,  2292,   228,  1316,   717,   305,   753,
    1657,   756, -1743,  2378,  2080,   754,   155,   715,   156,  1201,
     783,  1215,  1274,  1538,  1231,   756,  1765,  1747,  1253, -1729,
   -1829,  1422,   718,   754,   187,  1805,  1806,  1807,  1808,  1288,
     253,   188,   154,  2158, -1829,  1314,   406,  2251,  -655,   229,
    1356, -1829,  2208,   720,  1767,   137,  1958,  1585,  -647,   230,
    1453,   757,  2684,  1771,  1544,  2309,  1370,   749,  1374,   137,
    2459,  1471,   982,   519,   716,   757,  1419,   722,  2155,   982,
     982,   982,  1391,  1462,  2277,   755,  1660,  1391,  1427,   754,
     980,   682,   982,   982,   982,   982,   982,   982,   982,   982,
     582,  1391,   982,   755,  1940,  2126,  1597,  1638,  2461,  2310,
    2301,   752,   717,  1846,   738,  1600,  2593,   139,   139, -1829,
    1507,   753, -1725,  -655, -1725,  2296,  2094,  1474,   747,   756,
    1433,  1185,    27,  1880,   187,  1751,   749,   243,  1612,   232,
    1624,   188,  1420,  1224,  2507,  1225,  2067,   756,   137,   306,
     223,  1601,   137,  1008,  1314,   137,  1231,  2223,  2223,   755,
    1625,  1847,   985,   717,   129,     5,  1127,   525,   728,   748,
   -1729,   822,  1423,   137,  1779,   608,  2021,   137,   749,   757,
     752,   137,   724,  2025,  1773,   705,   187,  1809,  1811,  1300,
     753,   137,   980,   188,  2068,   712,  2158,   757,    28,  -647,
     137,   754,  2400,   756,  2098,  2239,  1582,  2567,   609,   233,
     515,  2005,  1222, -1745,  1943,   316,  1241,  1626,   997,  2229,
   -1612,  2231,   752,  1241,  1276,  1536,  2588,  1241,  1773,  2099,
    1294, -1511,   753,   726,  2054,  1315,  1314,  1322,  2364,  1322,
    1330,  1347,  1294,  1538,  1301,  2302,   189,   137,   516,   394,
     985,  2117,  1302,   757,  2118,  1862,  1128,  2274,  1592,  1322,
    1237,  1258,   706,  2522,   707,   243,   130,  2603,   438,  2589,
     754,   755,  1259,   749,  1575,  1881,   317,   318,  1457,   154,
    2607,  1848,     5,   594,  1620,   595,  1266,  2437,  2271,  2100,
    1382,  2438,   243,   137,  1332,  1947,  1896,  1129,  1772,  2209,
    2210,  2211,  2641,   236,  1874,  2327,   742,  1911,  1912,    33,
   -1725,  1916,   754,  1237,   439,   756, -1064,   752,   190,  1920,
    1409,  2542, -1758,  1576,  2543,  2545,  1130,   753,  1543,  2546,
    2547,   749,  2561,  1875,  1222,    36,  1303,  2026,  2641,   743,
     755,  1998,  2666, -1511,  2308,  1849,   189,  1393,  1169,   749,
      94,  2036,   985,  1241,  1592,  2686,  2671,  1170,   243,   137,
   -1064, -1829,  2212,   750,   751,   757,  2382,  2001,  2648,  1898,
   -1064,   470,   471,   472,   191,   752,  1463,  1899,  2069,   192,
    1316,    39,   755,  1607,   756,   753, -1829,  1293,  2184, -1725,
    1241,  2527,   982,   752,    40,  2383,  1614,  1443,   189,  1293,
    1241,  2493,  2494,   753,  2190,  1835,  2445,   754,  1836,  1837,
    1267,  1268,   117,  1522,  1167,  2608,  2610,  2161,   190,  1168,
    1131,   361,    52,  2425,  2649,  2217,   756,  1269,   137,   254,
    2263, -1743,    13,  2426,   757,  2568,   706,    13,   707,  2660,
      94,  2647,  1834,  1608,  1330,  1835,  1609,  2650,  1836,  1837,
   -1064,  2512,  2651,   362,  2240,  2264,  2427,  1241,  2242,  1877,
    2657,  1241,  1646,  2193,   154,   754,  1650, -1829,  2267,    53,
     190,  2661,  1592,  1652,   191,  2652,   757,   755,  2085,   192,
     982,  1270,   255,   754,  2213,  2214,  2428, -1829,  1998,  2215,
    2513,  2662,   473,  1894,   592,   139,  1872,  2270,  1457,   599,
    1639,    48,  2680,  2630,  1895,  1879,   474,    54,  1930,    55,
      49,    56,   351, -1829,   226,   155,  1888,   156,  2642,    57,
   -1064,   756,    26,  1166,    21,    22,   191,   137,  2514,   252,
     139,   192,  1167,  2165,  1629,   755,  1630,  1168, -1829,    47,
    2481,    51,  1900,    46,   799,  1917,  2218,    93,    91,  2450,
    2482,  2451,   403,   755,    97,  1592,  1752,  1959,  2318,  1960,
     441,   508,  2197,   510, -1064,   137,   511,  2223,  2223,   100,
    2499,   757,  1850,  2584,  1901,    58,  2283,  1391,  2157,   756,
     101,   298,   982,   800,   801,   802,   803,   804,  2358,   475,
    2037,  2038,  2486,  2107,  2360,  2189,  1902,   756,  2030,   747,
    2031,   476,   243,   394,  2363,  2070,  1864,    94, -1064,  1752,
    1314,  1396,   227,   106, -1064,   819,   819,  2197,   626,   627,
     108,  1167,  1967,   109, -1511,  1968,  1168,  2487,  2564,   757,
    1885,   110, -1511, -1511,   820,   820,  2635, -1511,  1724,  1725,
    2636,   137,  1654,   112,  2481,  1659,  2314,   757,  2315,  1903,
    1672,  1708,  1167,  1710,  2482,  1910,  1222,  1168,  1418,  1592,
    1948,  1949,  1418,   819,   980,  1404,  1405,  1406,    60,   113,
    1838,  1839,   952,  1241,  2401,  1999,  1752,  2402,  2403,  1726,
    1892,  1727,   820,  1728,  2366,   114,  2367,  1222,   120,   953,
    2404,   477,  2197,   428,  1840,  1841,  2611,  2486,   228,   170,
    2422,   124,  2423,   749,  2419,  2420,  1655,  2576,  2577,  1904,
    1838,  1839,    61,  1241,  1726,  1167,  1727,  1729,  1730,  1731,
    1168,   805,   806,   807,   808,   809,   810,   811,   639,   640,
     122,  1157,  2612,  1159,  1840,  1841,   721,   723,   725,   727,
    1752,   126,   229,   171,  1509,  1510,  1922,   752,   137,  2481,
    2153, -1829,   230,   172,   243,  1402,  1403,   753,   140,  2482,
    1167,  1970,   149,   139,  2448,  1168,   231,  1732,  1931,  1733,
     142,  1980,  1981,  1388,  1389,  1984,  1734,   162,   163,  1735,
    1592,  1592,   181,  1511,  1512,   164,   167,  2266,   185,   186,
   -1829,   954, -1527, -1527, -1527, -1527,  1485,  1486,  1487,  1488,
     204,    64,   749,   193,  1905,   242,   247,  2197,  2474,  2093,
    1965,   248,  1932,  1933,  1934, -1829,   250,  1592,  1938,   249,
     257,  1941,  1942,   269,   985,  2285,  2285, -1526, -1526, -1526,
   -1526,  1973,   232,   173,   273,   278,   294,   754,   296,   154,
     300,   302,  1908,  2312,    67,  2133,   752,   303,   958,   959,
     960,   307,  2143,  2143,   961,   308,   753,   309,   312,   313,
     326,   333,   118,   334,   555,   338,  1736,  1241,  1737,   336,
     340,  1241,  1231,   812,  1241,   342,   349,  1222,   353,   556,
     351,   354,  2164,   356,  1454,  1332,   813,   392,   401,   394,
     398,   397,   403,   962,   408,   187,   420,   409,  1945,  1946,
     243,   421,   233,   174,   422,   234,   235,   755,   429,  1956,
    2087,   428,   413,   457,   454,    68,  1961,   455,   483,   557,
     459,  -342,   487,   490,   494,   495,    52,  1241,   502,   509,
    2374,   521,   523,   522,  2196,   527,   754,   549,   548,   533,
    2259,   543,  -355,   547,   554,  1974,   578,   175,   551,   552,
     586,   756,   585,   587,   603,   610,   605,   614,   613,   685,
     687,   698,  2132,   690,  2613,   711,   728,   964,  2614,  2615,
     730,  2132,  1885,    53,   736,   746,  1241,  1241,  1241,   762,
    2241,  2108,  2109,  2110,  2111,  2112,  2113,  2114,  2115,  2196,
    1592,   765,  1523,   769,  1524,   777,   236,   176,  1592,   780,
     781,   757,  1455,  2020,   771,   791,   755,   783,   786,  2616,
     793,    54,   797,    55,   836,    56,   823,  1872,   965,   966,
   -1612,   830,  2027,    57,   950,  2617,  2618,   989,  2032,   994,
     995,   243,   998,  1011,  1019,  1016,  1241,  1116,  1135,  1143,
    1145,  1171,  1152,  1183,   357,  1187,  2278,   137,  1189,    94,
     756,  1153,  1196,  1256,   982,  1154,   558,  1738,  1155,   358,
     970,   139,  1160,  1277,  2196,  1172,  2154,   559,  1592,   359,
    1174,  1175,  1197,  1294,  1377,  1410,  1384,  1385,  1294,    58,
     971,  1395,  1411,  1412,  1425,   972,  1431,   984,  2464,  1437,
    2319,  1446,   973,  1448,   137,  2175,  1460,  1294,  1294,  1231,
     757,  1294,  1466,   360,  1472,  1489,  1475,  1739,  1537,  1495,
    1540,  1556,  1493,  1553,  1557,  1559,  1561,  1572,  1740, -1529,
     980,   980,  1570,  1241,  1571,  1573,  1578,  1580,  2087,  1583,
    1589,  1587,  1332,  1603,  2365,  1605,  1190,  2269,  1616,  1628,
    1621,    59,  1632,  1634,  1294,  1636,   980,  2604,  2503,  1294,
    1294,  1294,  2504,  2505,  2224,  2224,  1640,  1647,  1241,  1648,
    1241,  2579,  1649,  1651,  2152,   980,  2633,  1653,   560,   561,
    1656,  1658,    60,  1661,  2333,  1663,  1711,  2334,  1714,  2196,
    2335,  1712,  2156,   562,  1717,   563,  1748,  1755,  2336,  1754,
    1757,  2598,  1759,  1216,  1780,  1769,  1773,  1241,  2170,  1241,
    2172,  1786,  1803,  1477,  2173,  1820,  1823,   980,  1831,  1844,
    1546,  1867,  2178,  1859,  1886,  1890,    61,  1882,  1897,    62,
    1918,  1925,  1952,  1953,  1966,  1963,  1969,  1975,  1976,  1978,
    1719,  1993,  1788,  2337,  1989,  1789,  1985,  1988,  1992,  1994,
    2007,  2011,  1790,  1791,  1995,  2018,  2022,  1788,  2017,  1427,
    1789,  2041,  1241,  2043,  2048,  2049,  2055,  1790,  1791,  1148,
     361,  2056,  2059,  2063,  2062,  1294,  2082,  2088,   564,   139,
    2090,   984,   984,   984,   542,  2091,  2094,  2101,  2128,  2102,
     985,   985,  2136,  2137,    63,  2135,  2138,   428,  1792,  2147,
    2149,  2449,   362,   984,  2179,  2158,  2185,  2191, -1548,  2226,
    2243,  2249,  -228,  1792,  2252,    64,   985,  2255,  2271,  2258,
    2260,  2273,  2287,  2297,  2299,   565,  2295,  2332,  2001, -1504,
   -1546,  2361,  2376,  2371,  2391,   985,  2393,  2290,  2373,  2392,
      65,  2338,    66,  2394,  2475,   428,  2410,  2405,  2415,  2442,
    2339,  2478,  2445,  2302,  2480,  1241,  2452,  1241,    67,  2453,
    2455,  2458,  2471,  2340,  2472,   363,  2473,  1793,  2492,  2477,
     364,  2509,  1477,  2508,  2527,  2563,  2570,   985,  2580,  2574,
    2601,  2582,  1793,  2600,  2628,   139,  2627,  2670,  1241,  2658,
    2388,  2667,  2672,  2679,  2674,  2341,  1794,    17,    92,    38,
     125,   365,  2510,   166,   256,   209,   266,   119,   984,   366,
     277,  1794,   290,  1242,   210,  2342,  2523,  2343,  1795,  1241,
    1242,   241,   367,   323,  1242,   545,   504,  2084,   442,    68,
     456,   835,  1231,  1795,   526,  1184,  1700,   787,  1242,   139,
    2344,  2606,  2665,  2076,   580,   993,  2656,  2311,  2669,  2632,
    1015,   368,  2328,  1294,   369,  2234,  1195,  1294,  1429,   984,
    2329,  1983,   370,  1982,  2447,   948,   984,   984,   984,  1392,
    2345,  2040,  1796,  -225,  1392,  1762,  2009,  2232,  2587,   984,
     984,   984,   984,   984,   984,   984,   984,  1796,  1392,   984,
    1445,  1763,  2369,  1778,  1813,  1821,  2052,  2346,  1241,  2238,
    1241,   371,  1843,  2375,   372,  1855,  2254,  2064,  1863,  1560,
    2262,  2265,  1563,  2092,  1889,  2146,  2463,  2276,  1435,  2116,
     982,   982,  1348,  2347,   428,  1797,  1594,  1595,  2286,  1619,
    2348,  2144,  2145,  2664,  2407,  2413,  1928,  2634,  2468,  2418,
    1797,  2421,  1827,  2349,  1586,  2279,   982,  2350,  2280,  2281,
    1242,  2282,  1761,   332,   213,   764,  2106,   293,  2655,  2655,
     795,   310,  2569,   447,  1413,   982,  2597,  1294,  1294,   272,
    1294,  1294,  2457,  1294,  2224,  2224,   539,  1161,  2440,   489,
    2130,  2248,  2441,  2075,   597,  1798,   774,  1242,  1858,  2621,
       0,     0,     0,     0,     0,     0,  2351,  1242,  1799,     0,
    1798,   624,     0,  2678,     0,     0,     0,   982,     0,     0,
       0,     0,     0,  1799,     0,     0,     0,     0,     0,     0,
    1679,  1726,  1680,  1727,     0,  2352,     0,     0,     0,     0,
       0,     0,     0,  1222,     0,  2353,     0,     0,  2465,     0,
       0,  2354,     0,     0,     0,  1593,     0,     0,     0,     0,
       0,     0,     0,     0,  1242,     0,     0,     0,  1242,     0,
       0,     0,     0,     0,     0,  2581,     0,     0,     0,     0,
    2484,  2485,     0,     0,     0,     0,     0,     0,     0,     0,
    1800,     0,     0,     0,     0,     0,  2495,     0,     0,     0,
       0,     0,     0,  1222,     0,  1800,     0,     0,     0,     0,
       0,     0,  2506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2629,     0,     0,     0,  2631,     0,     0,  2524,     0,     0,
    1222,     0,  2528,  2529,     0,     0,     0,     0,     0,     0,
       0,  1593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2566,  1753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2530,  1222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   984,
    2583,     0,     0,  2585,  2586,   846,     0,   847,     0,   848,
    2673,   642,     0,     0,   849,     0,     0,     0,     0,     0,
       0,     0,   850,     0,     0,  2687,  1753,     0,  2531,     0,
    2532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   851,   852,     0,     0,     0,
       0,  2533,     0,     0,   853,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   854,     0,     0,   855,  1593,
       0,  2534,     0,     0,     0,     0,     0,   984,     0,     0,
    1242,     0,   856,  1753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   646,     0,     0,     0,     0,     0,  2535,
       0,     0,     0,     0,     0,   857,     0,     0,     0,     0,
       0,     0,     0,   858,     0,   859,     0,     0,     0,     0,
    1242,     0,  -694,     0,  -694,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,     0,  -694,  -694,  -694,     0,  -694,  -694,  -694,
    -694,  -694,  -694,  -694,  -694,  -694,   860,  1753,     0,     0,
       0,     0,  1593,     0,     0,     0,     0,   861,     0,     0,
       0,     0,   862,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,     0,  1392,     0,     0,     0,     0,   984,
    2536,     0,     0,     0,     0,     0,     0,     0,     0,   863,
       0,     0,     0,     0,     0,     0,   864,  2537,     0,   865,
     866,     0,     0,     0,     0,     0,     0,     0,     0,   867,
       0,     0,     0,     0,     0,     0,   868,  2538,   869,     0,
       0,   870,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1593,  2540,     0,     0,
       0,     0,     0,   871,   660,  2541,     0,   872,     0,   873,
       0,     0,     0,     0,  1242,     0,     0,     0,  1242,   874,
       0,  1242,     0,     0,     0,  -694,  -694,     0,  -694,  -694,
    -694,  -694,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   875,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   876,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   846,     0,   847,  1242,   848,     0,     0,     0,     0,
     849,     0,     0,   877,   878,     0,     0,     0,   850,     0,
       0,     0,     0,     0,   879,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   880,   881,
       0,     0,     0,     0,     0,   882,     0,  1593,  1593,   883,
       0,   851,   852,  1242,  1242,  1242,     0,   884,     0,     0,
     853,     0,     0,     0,     0,     0,     0,   885,     0,     0,
       0,   854,     0,     0,   855,     0,   886,     0,     0,     0,
       0,     0,     0,     0,  1593,   887,     0,     0,   856,     0,
     888,   889,     0,     0,   890,     0,   891,     0,     0,     0,
       0,     0,   892,     0,     0,     0,     0,     0,     0,     0,
       0,   857,     0,  1242,     0,  -694,     0,     0,     0,   858,
       0,   859,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   894,     0,     0,     0,     0,     0,   895,
       0,     0,     0,     0,   896,     0,     0,     0,     0,     0,
       0,     0,   860,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   861,     0,  -694,     0,     0,   862,     0,
       0,   897,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     846,     0,   847,     0,   848,   863,     0,     0,     0,   849,
    1242,     0,   864,     0,     0,   865,   866,   850,     0,     0,
       0,     0,     0,     0,     0,   867,     0,     0,     0,     0,
       0,     0,   868,     0,   869,     0,     0,   870,     0,     0,
       0,     0,     0,     0,     0,  1242,     0,  1242,     0,     0,
     851,   852,     0,     0,     0,     0,     0,     0,     0,   853,
       0,     0,     0,     0,     0,     0,     0,  1593,     0,     0,
     854,     0,     0,   855,     0,  1593,     0,     0,     0,   871,
       0,     0,     0,   872,  1242,   873,  1242,   856,     0,     0,
       0,     0,     0,     0,     0,   874,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     857,     0,     0,     0,     0,     0,     0,     0,   858,     0,
     859,   875,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   984,     0,     0,   876,     0,     0,     0,     0,  1242,
       0,     0,     0,     0,     0,  1593,     0,     0,     0,     0,
       0,   860,     0,     0,     0,     0,     0,     0,     0,   877,
     878,     0,   861,     0,     0,     0,     0,   862,     0,     0,
     879,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   880,   881,     0,     0,     0,     0,
       0,   882,     0,     0,   863,   883,     0,     0,     0,     0,
       0,   864,     0,   884,   865,   866,     0,     0,     0,     0,
       0,     0,     0,   885,   867,     0,     0,     0,     0,     0,
       0,   868,   886,   869,     0,     0,   870,     0,     0,     0,
       0,   887,  1242,     0,  1242,     0,   888,   889,     0,     0,
     890,     0,   891,     0,     0,     0,     0,     0,   892,     0,
       0,     0,     0,     0,     0,     0,     0,  -854,     0,     0,
    -854,   893,     0,     0,     0,  1242,     0,     0,   871,     0,
       0,   846,   872,   847,   873,   848,     0,     0,     0,   894,
     849,     0,     0,     0,   874,   895,     0,     0,   850,     0,
     896,     0,     0,     0,     0,     0,  1242,     0,     0,     0,
    1190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     875,     0,     0,     0,     0,     0,     0,   897,     0,     0,
       0,   851,   852,   876,     0,     0,     0,     0,     0,     0,
     853,     0,     0,  -854,     0,     0,     0,     0, -1729,     0,
       0,   854,     0,     0,   855,     0,     0,     0,   877,   878,
    -854,     0,     0,     0,     0,     0,     0,     0,   856,   879,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   880,   881,  1242,     0,  1242,     0,     0,
     882,   857,     0,     0,   883,     0,     0,     0,     0,   858,
       0,   859,   884,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   885,     0,     0,     0,     0,     0,     0,     0,
       0,   886,     0,     0,     0,     0,     0,     0,     0,     0,
     887,     0,   860,     0,     0,   888,   889,     0,     0,   890,
       0,   891,     0,   861,     0,     0,     0,   892,   862,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1627,     0,  -854,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -854,   952,   863,     0,     0,   894,     0,
       0,     0,   864,     0,   895,   865,   866,     0,     0,   896,
       0,   953,     0,     0,     0,   867,     0,     0,     0,     0,
       0,     0,   868,     0,   869,     0,  -854,   870,     0,     0,
       0,     0,  -854,     0,  -854,     0,   897,  -854,     0,  -854,
    -854,  -854,     0,     0,     0,  -854,     0,  -854,     0,     0,
       0,     0,  -854,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   871,
       0,     0,     0,   872,     0,   873,     0,     0,     0,     0,
       0,     0,     0,     0,  -854,   874,     0,     0,     0,  -854,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -854,     0,     0,     0,     0,     0,     0,
       0,   875,     0,   954,     0,     0,     0,   984,   984,     0,
       0,     0,     0,     0,   876,     0,     0,  -854,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1729,     0,
       0,     0,     0,   984,     0,     0,     0,     0,     0,   877,
     878,     0,     0,     0,     0,     0,     0,     0,  -854,     0,
     879,     0,   984,     0,     0,     0,     0,     0,  1450,     0,
     958,   959,   960,     0,   880,   881,   961,     0,     0,     0,
       0,   882,   952,     0,     0,   883,     0,  1021,     0,  1022,
       0,  -854,     0,   884,  1023,     0,     0,  -854,     0,   953,
       0,     0,  1024,   885,   984,     0,     0,     0,     0,  -854,
    -854,     0,   886,     0,     0,   962,     0,     0,     0,     0,
       0,   887,     0,     0,     0,     0,   888,   889,     0,     0,
     890,     0,   891,     0,     0,  1025,  1026,     0,   892,     0,
       0,  -854,     0,     0,  1027,     0,     0,     0,     0,     0,
       0,  -854,     0,     0,     0,  1028,     0,  -854,  1029,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   894,
       0,  -854,  1030,     0,     0,   895,  -854,     0,     0, -1729,
     896,     0,     0,  -854,     0,  -854,     0,     0,     0,   964,
    1306,  -854,     0,     0,     0,  1031,     0,     0,     0,     0,
       0,   954,     0,  1032,     0,  1033,     0,   897,     0,     0,
       0,     0,  1034,     0,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,  1042,     0,  1043,  1044,  1045,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,     0,     0,     0,
     965,   966,     0,     0,     0,     0,     0,  1056,     0,     0,
       0,     0,  1057,     0,     0,     0,  1307,     0,   958,   959,
     960,     0,     0,     0,   961,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1058,
       0,     0,   970,     0,     0,     0,  1059,     0,     0,  1060,
    1061,     0,     0,     0,     0,     0,     0,     0,     0,  1062,
       0,     0,   971,   962,     0,     0,  1063,   972,  1064,     0,
       0,  1065,     0,     0,   973,     0,   137,     0,     0,     0,
       0,     0,  1202,     0,     0,   747,     0,     0,  1503,  1504,
    1505,     0,     0,     0,     0,     0,  1506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,     0,     0,     0,  1067,     0,  1068,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1069,
       0,     0,     0,     0,     0,     0,     0,   964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1070,     0,     0,   952,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1071,     0,
       0,     0,     0,     0,     0,   953,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   965,   966,
       0,     0,     0,  1072,     0,     0,     0,     0,     0, -1829,
       0,     0,     0,     0,  1073,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1074,
       0,     0,     0,     0,     0,  1075,     0,     0,     0,  1076,
     970,     0,     0,     0,     0,  1507,     0,  1077,     0,     0,
       0, -1117,     0,     0,     0,  1508,     0,  1078,     0,     0,
     971,     0,     0,     0,     0,   972,  1079,     0,     0, -1117,
       0,     0,   973,   243,   137,  1080,     0,     0,     0,     0,
    1081,  1082,     0,     0,  1083,     0,  1084,   954,     0,     0,
       0,     0,  1085,  1509,  1510,     0,     0,     0,   749,     0,
       0,     0,     0,     0,     0,  1086,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1826,     0,
       0,     0,     0,  1087,     0,     0,     0,     0,     0,  1088,
       0,  1204,  1511,  1512,  1089,     0,     0,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,  1205,     0,  1202,
       0,  1090,   747,     0,     0,  1503,  1504,  1505,     0,     0,
    1513,     0,     0,  1506,     0,     0,  1514,     0,     0,  1515,
       0,     0,     0,     0,     0,     0,     0,  1516,     0,   962,
       0,     0,     0,     0,  1517,     0,     0,     0,     0,  1518,
       0,     0,     0,     0,     0,     0,     0,     0,   963,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   754,     0,     0,   952,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   953,     0,     0,     0,     0,  1202,     0,     0,
     747,     0,     0,   964,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1507,     0,   965,   966,     0,     0,     0,     0,
       0,     0,  1508,     0,     0,  1202,     0,     0,   747,     0,
       0,     0,     0,   952,  1520,     0,  1521,     0,  1522,     0,
       0,  1523,     0,  1524,  1525,  1526,   756,     0,  1527,  1528,
     953,     0,     0,     0,   954,     0,   970,     0,     0,     0,
    1509,  1510,     0,     0,     0,   749,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,     0,     0,     0,     0,   973,     0,
     137,     0,     0,     0,     0,     0,   757,     0,  1204,  1511,
    1512,   952,     0,  1893,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,     0,     0,   961,   953,   753,
       0,     0,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,  1352,     0,     0,     0,     0,     0,  1513,     0,     0,
       0,     0,     0,  1514,     0,     0,  1515,  1202,     0,     0,
     747,     0,   954,     0,  1516,     0,   962,     0,     0,     0,
       0,  1517,     0,   749,     0,     0,  1518,     0,     0,     0,
       0,     0,     0,     0,     0,   963,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1204,     0,     0,   754,
       0,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
     954,     0,  1205,   952,     0,     0,     0,     0,     0,     0,
     964,   749,     0,     0,     0,  1203,     0,     0,     0,     0,
     953,     0,     0,  1202,     0,     0,   747,  1618,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1204,     0,     0,     0,     0,   755,
     956,     0,   957,   963,     0,   752,     0,   958,   959,   960,
       0,   965,   966,   961,     0,   753,     0,     0,     0,     0,
    1205,     0,     0,     0,     0,     0,     0,   754,     0,     0,
       0,  1520,     0,  1521,     0,  1522,     0,     0,  1523,     0,
    1524,  1525,  1526,   756,     0,  1527,  1528,     0,     0,   952,
       0,     0,   962,   970,     0,     0,     0,     0,   964,     0,
       0,  1295,     0,     0,     0,     0,   953,     0,     0,     0,
       0,   963,   954,   971,     0,     0,     0,     0,   972,     0,
       0,     0,     0,   749,     0,   973,     0,   137,     0,     0,
       0,     0,     0,   757,     0,   754,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,  1204,     0,     0,     0,
       0,     0,   956,     0,   957,     0,   964,   752,     0,   958,
     959,   960,     0,     0,  1894,   961,     0,   753,     0,     0,
       0,   756,  1205,     0,     0,  1895,     0,     0,     0,     0,
       0,   970,  1202,     0,     0,   747,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   755,     0,     0,   954,     0,
       0,   971,     0,     0,   962,     0,   972,   965,   966,   749,
       0,  1202,     0,   973,   747,   137,     0,     0,     0,     0,
       0,   757,     0,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   756,
       0,     0,  1204,     0,     0,     0,     0,   754,   956,   970,
     957,     0,     0,   752,     0,   958,   959,   960,   952,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1205,   971,
       0,     0,     0,     0,   972,   953,     0,     0,   964,  1202,
       0,   973,   747,   137,     0,     0,     0,   952,  1352,   757,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1357,
     962,     0,     0,     0,   953,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   952,     0,     0,     0,     0,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,   953,     0,   964,     0,     0,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   749,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,   954,     0,     0,     0,
       0,   757,     0,   755,     0,     0,     0,   749,     0,     0,
       0,  1204,     0,     0,     0,   965,   966,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,  1205,     0,     0,
    1204,     0,     0,     0,     0,     0,   956,   756,   957,     0,
       0,   752,     0,   958,   959,   960,     0,   970,     0,   961,
       0,   753,     0,     0,   954,     0,  1205,     0,     0,   962,
       0,     0,     0,     0,     0,   749,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,  -910,   963,   973,
    -910,   137,     0,     0,     0,     0,     0,   757,   962,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1204,     0,
       0,     0,   754,     0,   956,     0,   957,   963,     0,   752,
       0,   958,   959,   960,     0,  1202,     0,   961,   747,   753,
       0,     0,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,   754,     0,   964,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -910,     0,     0,   962,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
    -910,     0,   755,     0,     0,   963,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,     0,
       0,   952,     0,     0,     0,     0,     0,     0,     0,   754,
    1202,   755,     0,   747,     0,     0,     0,   952,   953,     0,
       0,     0,     0,   965,   966,     0,   756,     0,     0,     0,
       0,     0,     0,     0,   953,     0,   970,     0,     0,     0,
     964,     0,     0,     0,     0,     0,  1477,     0,     0,     0,
       0,     0,     0,     0,     0,   756,   971,     0,     0,     0,
       0,   972,     0,     0,     0,   970,     0,     0,   973,     0,
     137,     0,     0,     0,     0,     0,   757,     0,  1202,   755,
       0,   747,  -910,     0,     0,   971,   952,     0,     0,     0,
     972,   965,   966,  -910,     0,     0,     0,   973,     0,   137,
       0,     0,     0,   953,     0,   757,     0,     0,     0,  1439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     954,     0,     0,   756,     0,  1306,  -910,     0,     0,     0,
       0,   749,  -910,   970,  -910,     0,   954,  -910,     0,  -910,
    -910,  -910,     0,     0,     0,  -910,     0,  -910,     0,     0,
       0,     0,  -910,   971,   952,     0,     0,     0,   972,     0,
       0,     0,     0,     0,  1204,   973,     0,   137,     0,     0,
     956,   953,   957,   757,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,  -910,   753,     0,     0,     0,     0,
    1205,  1450,     0,   958,   959,   960,     0,     0,     0,   961,
    1623,  1202,     0,  -910,   747,   954,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   749,     0,     0,     0,
       0,     0,   962,     0,     0,     0,     0,  -910,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   962,     0,
       0,   963,     0,     0,     0,     0,     0,     0,     0,  1204,
       0,     0,     0,     0,     0,   956,     0,   957,  -910,     0,
     752,     0,   958,   959,   960,   754,     0,     0,   961,     0,
     753,     0,     0,   954,     0,  1205,     0,   952,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,   964,  -910,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   962,     0,  -910,
    -910,     0,   964,     0,     0,     0,     0,  1204,     0,     0,
       0,     0,     0,   956,     0,   957,   963,     0,   752,     0,
     958,   959,   960,     0,     0,   755,   961,     0,   753,     0,
       0,  -910,     0,  1205,     0,     0,     0,   965,   966,     0,
     754,  -910,  1202,     0,     0,   747,     0,     0,     0,     0,
       0,     0,     0,   965,   966,     0,     0,     0,     0,     0,
       0,  -910,     0,     0, -1829,   962,  -910,     0,     0,   756,
       0,   964,     0,  -910,     0,  -910,     0,     0,     0,   970,
       0,  -910,     0,     0,   963,     0,   954,     0,     0,     0,
       0,     0,     0,  1481,     0,   970,     0,   749,     0,   971,
       0,     0,     0,     0,   972,     0, -1117,     0,   754,     0,
     755,   973,     0,   137,     0,   971,     0,     0,   952,   757,
     972,     0,   965,   966, -1117,     0,     0,   973,   243,   137,
    1204,     0,     0,     0,     0,   953,   956,     0,   957,   964,
       0,  1246,     0,   958,   959,   960,     0,  1749,     0,   961,
     747,   753,     0,     0,   756,     0,  1205,     0,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,     0,     0,
       0,     0,  1915,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,   971,     0,     0,     0,   962,   972,
     965,   966,     0,     0,     0,     0,   973,     0,   137,     0,
       0,     0,     0,     0,   757,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,   952,     0,     0,     0,     0,     0,     0,
       0,   754,   970,     0,     0,     0,     0,   954,     0,     0,
     953,     0,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,   971,     0,     0,     0,     0,   972,     0,     0,
       0,     0,   964,     0,   973,     0,   137,     0,     0,     0,
       0,     0,   757,     0,     0,     0,     0,     0,     0,     0,
       0,  1204,     0,     0,     0,     0,     0,   956,     0,   957,
       0,     0,   752,     0,   958,   959,   960,     0,     0,     0,
     961,   755,   753,     0,     0,     0,     0,  1205,     0,     0,
       0,     0,     0,   965,   966,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   962,
       0,     0,   954,     0,     0,   756,     0,     0,     0,     0,
       0,     0,     0,   749,     0,   970,     0,     0,   963,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,   754,     0,     0,     0,  1204,   973,     0,   137,
       0,     0,   956,     0,   957,   757,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
       0,     0,  1205,   964,     0,     0,     0,     0,     0,   618,
     619,   620,   621,   622,   623,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,     0,     0,     0,     0,
       0,     0,   755,   625,     0,   626,   627,   628,   629,   630,
     631,   632,     0,   963,   965,   966,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   754,     0,     0,
       0,     0,     0,     0,     0,     0,   756,     0,     0,   633,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
    1013,     0,     0,     0,     0,     0,     0,     0,   964,     0,
       0,     0,     0,     0,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,     0,     0,     0,     0,   973,     0,
     137,  -352,     0,     0,  -352,     0,   757,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,   755,   634,   635,
     636,   637,   638,     0,     0,   639,   640,     0,     0,   965,
     966,     0,     0,  -352,     0,  -352,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,   641,
       0,   756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   970,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,   973,     0,   137,     0,     0,     0,     0,
       0,   757,     0,     0,     0,     0,     0,   643,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   529,     0,     0,  -352,  -352,  -352,
    -352,  -352,   528,     0,  -352,  -352,     0,     0,  -352,   645,
       0,     0,     0,     0,     0,  -352,     0,  -352,     0,     0,
     647,     0,  -352,  -352,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,   648,     0,     0,     0,  -352,  -352,     0,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
    -352,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,   652,   653,   654,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,  -352,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,     0,     0,   656,   657,   658,
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
       0,   952,     0,     0,     0,     0,  -352,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,   953,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,   634,   635,   636,
     637,   638,  -352,     0,   639,   640,     0,     0,     0,  -352,
     952,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   953,     0,     0,
     954,     0,     0,     0,     0,     0,     0,     0,   641,     0,
       0,   749,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,   642,     0,     0,     0,     0,     0,
   -1805,     0,     0,     0,     0,     0,     0,     0,  1674,     0,
       0,  1675,     0,     0,  1676,   618,   619,   620,   621,   622,
     623,  1677,  1678,     0,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,     0,   753,   643,     0,     0,     0,
    1679,     0,  1680,     0,     0,     0,     0,     0,     0,   625,
       0,   626,   627,   628,   629,   630,   631,   632,     0,     0,
       0,     0,     0,     0,   644,     0,     0,     0,     0,   954,
       0,     0,   962,     0,     0,     0,     0,     0,   645,     0,
     749,     0,     0,     0,     0,     0,   646,     0,     0,   647,
       0,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,   648,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   955,   649,   754,     0,     0,     0,   956,
       0,   957,   650,     0,   752,     0,   958,   959,   960,     0,
       0,     0,   961,     0,   753,     0,  1681,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   964,     0,     0,     0,
       0,     0,     0,     0,   634,   635,   636,   637,   638,     0,
       0,   639,   640,     0,   651,  1682,   652,   653,   654,     0,
       0,   962,  1683,     0,  1684,     0,     0,     0,     0,     0,
   -1758,     0,     0,     0,     0,   755,     0,  1685,     0,     0,
     963,     0,     0,   655,     0,   641,     0,   965,   966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
    -349,   642,     0,     0,   754,     0,     0,     0,     0,  1686,
       0,     0,     0,   952,     0,     0,     0, -1805,  1687,   756,
       0,     0,     0,     0,     0,     0,   656,   657,   658,   970,
     953,  1688,     0,     0,     0,   964,     0,     0,     0,     0,
     659,     0,     0,   643,     0,     0,     0,   660,     0,   971,
       0,     0,     0,     0,   972,     0,     0,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757,
       0,  1689,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1690,   645,   965,   966,     0,     0,
       0,   952,     0,   646,     0,     0,   647,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1381,     0,   953,   648,
       0,  1691,     0,     0,     0,     0,   967,   952,   756,     0,
     968,   969,     0,     0,     0,     0,     0,     0,   970,     0,
       0,     0,   954,     0,   953,     0,     0,  1692,     0,     0,
       0,     0,     0,   749,  1693,     0,     0,     0,   971,     0,
       0,     0,     0,   972,     0,     0,     0,     0,     0,     0,
     973,  1694,   137,     0,     0,     0,     0,     0,   757,     0,
       0,   651,     0,   652,   653,   654,   955,     0,     0,     0,
       0,     0,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,     0,   961,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,   952,     0,     0,     0,
     954,     0,  1695,     0,     0,     0,     0,  -597,     0,     0,
       0,   749,  1696,   953,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   962,     0,   954,     0,     0,  1697,
       0,     0,     0,   656,   657,   658,     0,   749,     0,     0,
       0,     0,     0,   963,   955,     0,     0,   659,     0,     0,
     956,     0,   957,  1698,   660,   752,     0,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,   754,     0,     0,
     955,     0,     0,     0,     0,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,     0,     0,     0,   961,
       0,   753,     0,     0,     0,     0,     0,     0,   964,     0,
       0,     0,   962,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   954,     0,     0,     0,     0,
       0,   963,     0,     0,     0,     0,   749,     0,   962,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,   754,     0,   963,     0,   965,
     966,     0,     0,     0,     0,     0,     0,     0,     0,   955,
       0,     0,     0,     0,     0,   956,     0,   957,     0,  1400,
     752,   754,   958,   959,   960,     0,   964,   952,   961,   967,
     753,   756,     0,   968,   969,     0,     0,     0,     0,     0,
       0,   970,     0,   952,   953,     0,     0,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
     953,   971,     0,     0,     0,   755,   972,   962,     0,     0,
       0,     0,     0,   973,     0,   137,     0,   965,   966,     0,
       0,   757,     0,     0,     0,     0,   963,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,  1939,     0,     0,
       0,     0,     0,   965,   966,     0,     0,   967,     0,   756,
     754,   968,   969,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   967,     0,   756,     0,   968,   969,   971,
       0,   964,     0,     0,   972,   970,   954,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,   749,     0,   757,
       0,     0,   954,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,   749,     0,     0,     0,   973,     0,   137,
     755,     0,     0,     0,     0,   757,     0,     0,     0,     0,
     955,     0,   965,   966,     0,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,   955,     0,     0,   961,
       0,   753,   956,     0,   957,     0,     0,   752,     0,   958,
     959,   960,     0,     0,   756,   961,   968,   753,     0,     0,
       0,     0,     0,     0,   970,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   962,     0,
       0,     0,     0,     0,   971,     0,     0,     0,     0,   972,
       0,     0,     0,     0,   962,     0,   973,   963,   137,     0,
       0,     0,     0,     0,   757,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2645,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   964,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
  ((yystate) == (-2286))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   595,   103,   181,   105,   111,   660,
     366,   540,   783,   111,  1101,   838,   714,   116,  1202,   684,
     358,   158,   776,   784,   649,  1458,  1562,  1417,  1124,  1552,
    1417,  1417,   135,   425,   209,  1417,  1417,   135,  1417,  1342,
    1104,  1884,  1498,   435,  1352,  1110,  1568,  1965,   404,  1106,
    1234,   598,  1507,  1110,     9,  1801,  1241,  1099,  1999,  1124,
       1,  1095,    27,     1,     9,  1160,  1909,  1124,    22,   697,
      56,    57,    58,    53,     9,  1227,   741,    21,    64,  1174,
      60,   184,  1768,    31,     1,    57,  1950,   841,  1439,     0,
       0,    48,    31,    55,    86,  1331,   364,    57,    96,    17,
     783,     9,    49,    17,   114,   152,  2034,   141,    57,  1294,
      87,  1733,   175,    99,   100,    49,   102,    92,   174,  2073,
     123,   107,   108,   788,  1810,   750,   751,    63,  1431,   159,
     116,   124,   176,   241,     6,   225,    61,    64,  1661,    66,
     277,  1492,  1229,   125,   176,   256,   241,   133,   270,    57,
     115,   203,   251,    87,     1,   129,  1977,   213,   203,   124,
      57,   257,  1347,    32,    89,    90,     1,   256,    22,   200,
     328,   256,  2062,   798,   160,  1861,   256,    30,  1481,    56,
     330,   161,    59,  1217,   252,   161,    63,   256,   107,  2428,
     203,  1427,  2133,   229,   369,   123,   295,   968,   421,   203,
    2297,   829,  2299,   274,   308,   191,   218,   329,  1559,   776,
      49,    64,    27,    66,    61,   747,  1273,   203,   989,   218,
     172,  2506,  2395,   232,  2435,    96,  1283,   138,   138,    72,
     187,   142,   142,  1919,   262,   292,  1122,    31,   218,   219,
     232,   110,    89,    90,  1101,   256,   256,  2137,   956,   957,
     546,     0,   481,   458,   451,   963,  1142,   451,   463,   287,
     783,    39,     6,   249,   453,   410,   165,   324,   367,   177,
     499,   257,  1623,   342,   841,  1340,   287,  1134,   232,    70,
    2491,  2566,   199,  1340,   967,   968,   969,  1344,   584,   200,
     200,   823,   272,   340,   306,  2468,  2250,  2251,    92,   356,
     115,   256,   282,  2146,   110,  1828,   989,   232,    70,  1545,
     341,    70,   501,   289,   418,   314,   612,   388,  2415,    21,
    2006,   389,     9,  1094,   376,   252,  1634,  1863,   171,   994,
     955,   476,  1640,   241,   370,   113,   458,     6,   561,   435,
     443,   463,   445,   446,   309,   503,  2585,   445,   446,   452,
      70,     6,   290,   503,   452,  2176,   228,   204,   457,    70,
     468,    64,  2252,    66,  1820,   347,   469,  1823,  1990,   472,
     473,   469,   475,   468,   312,   478,   479,   363,   232,  1834,
     357,  1152,  1153,  1154,   232,   232,   256,   256,  1843,   237,
     365,   268,  1628,   504,  1165,  1166,   321,  1439,   494,   252,
     271,  1172,   447,  1754,   331,   391,   232,   497,   504,   153,
     357,  1094,    70,   516,   423,   504,   402,   451,   516,   504,
     402,   510,   452,   357,   504,   411,   412,  2381,   414,   415,
     341,   341,   955,  1497,   420,   370,   308,   540,   541,   274,
     392,   504,   540,   541,   967,   968,   969,  1112,   504,   462,
    1492,   437,  2316,  1000,  1001,     6,   353,   504,   462,   237,
     504,   436,  1145,   340,   335,   401,   989,   453,   212,  1152,
    1153,  1154,   504,     6,   321,   503,   579,   451,   331,   482,
    1241,   579,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
     783,  1556,  1175,   592,   504,   598,  1732,   446,   458,  1556,
     599,    49,  2188,   463,  1812,  1539,   504,   499,   465,   453,
     503,   354,   256,  1221,   462,  2443,  2444,  1559,   357,   396,
     464,   498,   266,   462,   401,   793,   451,   271,   442,   515,
     504,  1683,     9,   505,   451,   497,  1570,   376,   503,  1596,
     451,   451,  2228,   212,  2230,   644,   503,   650,   534,   504,
     504,   498,  2395,   388,   482,  1650,  1184,   212,  2180,   504,
     468,   496,   461,   504,   498,  1749,   504,  1752,   554,  1093,
     556,  1094,   123,   559,   560,  2261,   562,  1101,  1102,  1204,
    2102,  1623,  2446,   501,   503,   504,  1347,   256,   460,  1112,
    1114,  1115,  2048,   504,   504,  1118,   576,   266,    32,    49,
     287,   256,   346,   589,   451,  2291,  2292,   398,   594,  1133,
    1134,   266,   451,   456,   316,   601,   451,  1853,   188,    33,
    2484,  2485,  1145,  2369,   402,   451,   606,   504,   331,  1152,
    1153,  1154,  1155,   504,   504,   441,   398,  1160,     0,   398,
     446,     6,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
     503,  1174,  1175,   828,  1890,  1908,   504,   448,   244,   498,
    2524,   212,   349,   762,  2528,  2529,   153,  2608,   767,   772,
     773,  1111,   416,   659,   967,   968,   969,   346,   398,   212,
     256,  1204,   781,   786,   256,  1502,   448,   398,  2606,   448,
    2041,   346,  2043,  2557,  1465,   170,   989,  1137,   216,   252,
    1757,    26,  1961,   161,  1227,   256,  1098,  1468,  1100,   256,
       6,   271,  1754,   256,   700,   266,   460,   703,   236,   244,
     454,  1980,  1981,   256,  1541,  1984,  1760,  1119,   448,  1121,
    2594,  2082,   256,   266,  1126,   212,  2044,   448,   458,   308,
     398,  1265,   406,   463,   262,   203,   142,   416,  1140,  1566,
     225,   453,   242,   167,   308,     9,   411,   262,   233,   195,
     504,   416,   464,   406,  2450,  2451,   510,   234,  2027,   287,
     504,  1295,   271,  2032,   203,   446,   138,   446,   228,   256,
     142,   262,  1465,   445,  2135,   212,  1309,   406,   229,   266,
     448,   460,   362,  2248,  1859,   346,   307,   244,   309,  1092,
     462,  1094,  1859,  1860,  1097,   460,   287,  1432,  1101,   357,
     175,   357,   476,   346,    56,  1485,  1486,  1487,  1488,  1112,
     256,    63,   256,   256,   410,  1118,   497,  2063,   376,   256,
    1354,   289,    34,   476,  1459,   504,   389,  1326,   200,   266,
    1232,   510,   317,  1604,  1284,  2148,  1139,   212,  1141,   504,
    2386,  1243,  1145,   267,   301,   510,   410,   476,  1945,  1152,
    1153,  1154,  1155,   159,  2117,   416,  1413,  1160,    30,   346,
    1553,   196,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
     385,  1174,  1175,   416,  1655,   410,   446,  1376,   317,  2148,
     157,   256,   406,     9,   384,   446,   329,  1000,  1001,   330,
     159,   266,    64,   451,    66,  2141,   129,  1245,     9,   460,
    1203,  1010,   122,  1578,    56,  1439,   212,   503,   376,   346,
    1360,    63,   476,   422,  2460,   424,     9,   460,   504,   370,
     397,   482,   504,   196,  1227,   504,  1229,  2033,  2034,   416,
     394,    57,  1465,   406,   354,   341,   256,   451,   501,    50,
     498,   751,   498,   504,  1478,   171,  1773,   504,   212,   510,
     256,   504,   476,  1780,   231,   274,    56,  1491,  1492,   170,
     266,   504,  1655,    63,    57,   337,   256,   510,    84,   341,
     504,   346,   500,   460,   262,  2049,  1324,  2509,   204,   416,
     414,  1752,  1095,   256,  1659,   351,  1099,   451,   798,  2041,
     504,  2043,   256,  1106,  1107,  1529,   286,  1110,   231,   287,
    1113,    57,   266,   476,  1831,  1118,  1309,  1120,  2202,  1122,
    1123,  1124,  1125,  2080,   225,   292,   268,   504,   452,   504,
    1553,   290,   233,   510,   293,  1559,   346,  2101,  1331,  1142,
    2082,   453,   351,  2476,   353,   503,   456,  2570,   125,   329,
     346,   416,   464,   212,   285,  1578,   412,   413,  1233,   256,
    2582,   177,   341,   351,  1357,   353,   199,  2326,   291,  1886,
    1145,  2330,   503,   504,   271,  1666,  1600,   387,  1470,   281,
     282,   283,  2603,   510,     8,  2172,   171,  1611,  1612,   138,
     252,  1615,   346,  2135,   171,   460,   212,   256,   340,  1623,
    1175,  2491,   204,   334,  2491,  2491,   416,   266,  1283,  2491,
    2491,   212,  2491,    37,  1217,    26,   317,  1787,  2639,   204,
     416,  1746,  2645,   169,   321,   241,   268,  1650,   450,   212,
     232,  1801,  1655,  1236,  1427,  2671,  2659,   459,   503,   504,
     256,   262,   344,   244,   245,   510,     8,   411,   187,    38,
     266,   117,   118,   119,   396,   256,   452,    46,   241,   401,
    1683,   451,   416,   177,   460,   266,   287,  1113,  1985,   331,
    1273,   210,  1465,   256,   394,    37,  1351,   223,   268,  1125,
    1283,  2440,  2441,   266,  2001,    12,     8,   346,    15,    16,
     323,   324,     1,   452,   458,  2583,  2584,  1951,   340,   463,
     510,   220,    11,   177,   187,  2022,   460,   340,   504,   451,
     262,   107,     2,   187,   510,    37,   351,     7,   353,   306,
     232,  2609,     9,   237,  1327,    12,   240,   210,    15,    16,
     346,   127,   187,   252,  2051,   287,   210,  1340,  2055,  1577,
    2628,  1344,  1386,  2004,   256,   346,  1390,   216,   217,    58,
     340,   338,  1545,  1397,   396,   210,   510,   416,   379,   401,
    1553,   394,   504,   346,   466,   467,   240,   236,  1893,   471,
     166,   358,   238,   453,   555,  1378,  1569,  2094,  1453,   560,
    1378,   256,  2670,  2590,   464,  1578,   252,    96,  1644,    98,
     451,   100,   188,   262,    28,   307,  1589,   309,  2605,   108,
     416,   460,    16,   449,    13,    14,   396,   504,   204,   451,
    1413,   401,   458,   510,   351,   416,   353,   463,   287,    33,
     106,   451,   211,    32,     1,  1618,  2024,   451,    42,  2371,
     116,  2373,   351,   416,   504,  1628,  1439,   156,  2161,   158,
     359,   473,  2007,   475,   460,   504,   478,  2443,  2444,   423,
    2446,   510,   468,  2537,   243,   164,  2127,  1650,  1949,   460,
     405,   451,  1655,    40,    41,    42,    43,    44,  2185,   335,
      96,    97,    54,  1897,  2191,  2000,   265,   460,   156,     9,
     158,   347,   503,   504,  2201,   468,  1561,   232,   504,  1492,
    1683,   448,   126,   394,   510,   750,   751,  2062,    75,    76,
     405,   458,  1695,   451,   450,  1698,   463,    89,  2495,   510,
    1585,   451,   458,   459,   750,   751,   161,   463,    24,    25,
     165,   504,   448,   451,   106,  1411,   252,   510,   254,   318,
    1416,  1417,   458,  1419,   116,  1610,  1539,   463,  1191,  1732,
     248,   249,  1195,   798,  2127,  1169,  1170,  1171,   257,   451,
     277,   278,    82,  1556,  2271,  1748,  1559,  2274,  2275,    65,
    1597,    67,   798,    69,   252,    57,   254,  1570,   218,    99,
    2287,   437,  2137,  1865,   301,   302,    53,    54,   212,   212,
     252,   451,   254,   212,  2301,  2302,   449,   299,   300,   378,
     277,   278,   301,  1596,    65,   458,    67,   103,   104,   105,
     463,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     173,   967,    89,   969,   301,   302,   620,   621,   622,   623,
    1623,   451,   256,   256,   207,   208,  1625,   256,   504,   106,
     448,   500,   266,   266,   503,  1167,  1168,   266,    68,   116,
     458,  1709,   504,  1646,  2361,   463,   280,   153,  1646,   155,
     451,  1719,  1720,  1153,  1154,  1723,   162,   451,   504,   165,
    1853,  1854,   256,   246,   247,   451,   340,  2091,   256,   468,
     262,   201,   485,   486,   487,   488,   485,   486,   487,   488,
     199,   390,   212,   504,   473,   442,   400,  2252,  2405,  1882,
    1689,   401,  1647,  1648,  1649,   287,    63,  1890,  1653,   410,
      59,  1656,  1657,   256,  2127,  2129,  2130,   485,   486,   487,
     488,  1710,   346,   346,   232,   451,   328,   346,   401,   256,
     504,   229,  1608,  2152,   433,  1918,   256,    26,   258,   259,
     260,   451,  1925,  1926,   264,   451,   266,   107,   451,   312,
     256,   256,   451,   272,    47,    23,   252,  1750,   254,   454,
     102,  1754,  1945,   330,  1757,   451,   437,  1760,   122,    62,
     188,   454,  1955,    17,   356,   271,   343,    86,   272,   504,
     394,   451,   351,   303,   401,    56,   423,   402,  1664,  1665,
     503,   262,   416,   416,    39,   419,   420,   416,   451,  1675,
    1865,  2083,   237,   331,   402,   504,  1682,   504,   419,   102,
     506,   504,   316,   310,   394,   261,    11,  1810,   451,     7,
    2234,   451,   255,   394,  2007,   451,   346,   366,   394,   504,
    2076,   503,    85,   451,    85,  1711,   124,   460,   451,   451,
     394,   460,   451,   389,    22,   309,   306,   394,   451,   204,
     504,   499,  1917,   504,   321,   451,   501,   377,   325,   326,
     384,  1926,  1927,    58,   232,   504,  1859,  1860,  1861,   446,
    2053,  1898,  1899,  1900,  1901,  1902,  1903,  1904,  1905,  2062,
    2063,   254,   455,   218,   457,   122,   510,   510,  2071,   510,
     446,   510,   474,  1769,   504,    26,   416,   462,   442,   366,
     400,    96,   306,    98,   348,   100,   447,  2090,   428,   429,
     504,   410,  1788,   108,   445,   382,   383,   462,  1794,   442,
     256,   503,   451,   504,   376,   451,  1919,   399,   336,   114,
     462,   169,   462,   187,     4,   451,  2119,   504,   451,   232,
     460,   462,   504,   256,  2127,   462,   239,   443,   462,    19,
     470,  1944,   462,   446,  2137,   462,  1944,   250,  2141,    29,
     462,   462,   451,  1956,   309,   403,   504,   504,  1961,   164,
     490,   504,   453,    30,   130,   495,   196,   783,  2392,   131,
    2163,   446,   502,   132,   504,  1974,   133,  1980,  1981,  2172,
     510,  1984,   386,    63,   134,   136,   135,   493,   101,   137,
     441,   446,   497,   462,   140,    49,   404,   439,   504,   445,
    2583,  2584,   442,  2006,   445,   143,   196,   144,  2083,   145,
     499,   146,   271,    31,  2207,   147,    49,  2092,   148,   196,
     149,   226,   150,   112,  2027,   151,  2609,  2578,  2452,  2032,
    2033,  2034,  2456,  2457,  2033,  2034,   220,   448,  2041,   448,
    2043,  2532,   448,   448,  1930,  2628,  2597,   448,   351,   352,
     448,   446,   257,   114,    32,   451,   410,    35,   109,  2252,
      38,   312,  1948,   366,   197,   368,   446,   223,    46,   203,
     376,  2562,   339,   256,   294,   272,   231,  2080,  1964,  2082,
    1966,   298,   484,   165,  1970,   501,   501,  2670,   128,   175,
     365,   168,  1978,   446,   129,   446,   301,   228,    49,   304,
     196,   228,   204,   176,    56,   299,   204,   504,   451,   272,
     252,   423,    35,    91,   508,    38,   165,   509,   237,   299,
     446,   446,    45,    46,   276,   362,   295,    35,   380,    30,
      38,   203,  2135,   203,    17,   442,   128,    45,    46,   955,
     220,   139,   365,    49,   446,  2148,   203,   141,   451,  2152,
       8,   967,   968,   969,  2152,   196,   129,   501,   423,   501,
    2583,  2584,   451,   446,   369,   203,     9,  2459,    91,     7,
     504,  2364,   252,   989,   503,   256,   294,   297,   203,   503,
     498,   498,   262,    91,    49,   390,  2609,   188,   291,  2075,
     314,   262,   461,   113,   436,   498,   313,    47,   411,   203,
     203,   294,   102,   361,   380,  2628,   262,   330,   361,    49,
     415,   189,   417,   237,  2407,  2507,   492,   296,    95,    56,
     198,  2414,     8,   292,  2417,  2228,    49,  2230,   433,   110,
     456,   337,   262,   211,   262,   315,   262,   160,   109,   451,
     320,   481,   165,   337,   210,   451,   107,  2670,   209,   221,
     418,   501,   160,   367,   196,  2258,   119,    49,  2261,   337,
    2258,   313,   306,   321,   425,   243,   189,     7,    46,    26,
      92,   351,  2465,   127,   201,   148,   206,    75,  1094,   359,
     221,   189,   238,  1099,   150,   263,  2479,   265,   211,  2292,
    1106,   177,   372,   286,  1110,   519,   469,  1864,   410,   504,
     425,   773,  2495,   211,   497,  1009,  1417,   740,  1124,  2312,
     288,  2581,  2643,  1857,  2312,   788,  2622,  2150,  2655,  2594,
     841,   401,  2173,  2326,   404,  2046,  1018,  2330,  1200,  1145,
    2173,  1722,   412,  1721,  2355,   779,  1152,  1153,  1154,  1155,
     318,  1804,   265,   423,  1160,  1451,  1756,  2044,  2541,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,   265,  1174,  1175,
    1217,  1453,  2226,  1478,  1497,  1500,  1823,   345,  2371,  2048,
    2373,   451,  1542,  2244,   454,  1549,  2071,  1851,  1560,  1304,
    2083,  2090,  1309,  1877,  1590,  1927,  2389,  2104,  1204,  1906,
    2583,  2584,  1125,   371,  2686,   318,  1338,  1340,  2130,  1354,
     378,  1926,  1926,  2639,  2290,  2295,  1638,  2600,  2395,  2300,
     318,  2305,  1529,   391,  1327,  2123,  2609,   395,  2123,  2123,
    1236,  2123,  1447,   299,   152,   691,  1893,   242,  2621,  2622,
     745,   270,  2517,   417,  1183,  2628,  2561,  2440,  2441,   215,
    2443,  2444,  2383,  2446,  2443,  2444,   509,   972,  2334,   449,
    1914,  2060,  2338,  1856,   558,   378,   705,  1273,  1552,  2585,
      -1,    -1,    -1,    -1,    -1,    -1,   444,  1283,   391,    -1,
     378,    45,    -1,  2666,    -1,    -1,    -1,  2670,    -1,    -1,
      -1,    -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,   473,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2506,    -1,   483,    -1,    -1,  2394,    -1,
      -1,   489,    -1,    -1,    -1,  1331,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1340,    -1,    -1,    -1,  1344,    -1,
      -1,    -1,    -1,    -1,    -1,  2534,    -1,    -1,    -1,    -1,
    2426,  2427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     473,    -1,    -1,    -1,    -1,    -1,  2442,    -1,    -1,    -1,
      -1,    -1,    -1,  2566,    -1,   473,    -1,    -1,    -1,    -1,
      -1,    -1,  2458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2589,    -1,    -1,    -1,  2593,    -1,    -1,  2483,    -1,    -1,
    2603,    -1,  2488,  2489,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2508,  1439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,  2639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,
    2536,    -1,    -1,  2539,  2540,     1,    -1,     3,    -1,     5,
    2663,   235,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,  2674,  1492,    -1,   252,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2580,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,   285,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,  1545,
      -1,   305,    -1,    -1,    -1,    -1,    -1,  1553,    -1,    -1,
    1556,    -1,    88,  1559,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,   333,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,    -1,
    1596,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,  1623,    -1,    -1,
      -1,    -1,  1628,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,    -1,  1650,    -1,    -1,    -1,    -1,  1655,
     414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   431,    -1,   205,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   451,   224,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1732,   491,    -1,    -1,
      -1,    -1,    -1,   269,   498,   499,    -1,   273,    -1,   275,
      -1,    -1,    -1,    -1,  1750,    -1,    -1,    -1,  1754,   285,
      -1,  1757,    -1,    -1,    -1,   291,   292,    -1,   294,   295,
     296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,  1810,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,   349,   350,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,   375,
      -1,    -1,    -1,    -1,    -1,   381,    -1,  1853,  1854,   385,
      -1,    51,    52,  1859,  1860,  1861,    -1,   393,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1890,   421,    -1,    -1,    88,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,    -1,    -1,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,  1919,    -1,   451,    -1,    -1,    -1,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,   475,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,   501,    -1,    -1,   168,    -1,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    -1,     5,   195,    -1,    -1,    -1,    10,
    2006,    -1,   202,    -1,    -1,   205,   206,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2041,    -1,  2043,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2063,    -1,    -1,
      71,    -1,    -1,    74,    -1,  2071,    -1,    -1,    -1,   269,
      -1,    -1,    -1,   273,  2080,   275,  2082,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2127,    -1,    -1,   324,    -1,    -1,    -1,    -1,  2135,
      -1,    -1,    -1,    -1,    -1,  2141,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,
     350,    -1,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
     360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,    -1,
      -1,   381,    -1,    -1,   195,   385,    -1,    -1,    -1,    -1,
      -1,   202,    -1,   393,   205,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   403,   215,    -1,    -1,    -1,    -1,    -1,
      -1,   222,   412,   224,    -1,    -1,   227,    -1,    -1,    -1,
      -1,   421,  2228,    -1,  2230,    -1,   426,   427,    -1,    -1,
     430,    -1,   432,    -1,    -1,    -1,    -1,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,   451,    -1,    -1,    -1,  2261,    -1,    -1,   269,    -1,
      -1,     1,   273,     3,   275,     5,    -1,    -1,    -1,   469,
      10,    -1,    -1,    -1,   285,   475,    -1,    -1,    18,    -1,
     480,    -1,    -1,    -1,    -1,    -1,  2292,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,
      -1,    51,    52,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,   349,   350,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,   375,  2371,    -1,  2373,    -1,    -1,
     381,   111,    -1,    -1,   385,    -1,    -1,    -1,    -1,   119,
      -1,   121,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,   152,    -1,    -1,   426,   427,    -1,    -1,   430,
      -1,   432,    -1,   163,    -1,    -1,    -1,   438,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     451,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    82,   195,    -1,    -1,   469,    -1,
      -1,    -1,   202,    -1,   475,   205,   206,    -1,    -1,   480,
      -1,    99,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,    -1,   224,    -1,   245,   227,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,   507,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,   285,    -1,    -1,    -1,   308,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    -1,   201,    -1,    -1,    -1,  2583,  2584,    -1,
      -1,    -1,    -1,    -1,   324,    -1,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,    -1,  2609,    -1,    -1,    -1,    -1,    -1,   349,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
     360,    -1,  2628,    -1,    -1,    -1,    -1,    -1,   256,    -1,
     258,   259,   260,    -1,   374,   375,   264,    -1,    -1,    -1,
      -1,   381,    82,    -1,    -1,   385,    -1,     3,    -1,     5,
      -1,   410,    -1,   393,    10,    -1,    -1,   416,    -1,    99,
      -1,    -1,    18,   403,  2670,    -1,    -1,    -1,    -1,   428,
     429,    -1,   412,    -1,    -1,   303,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,
     430,    -1,   432,    -1,    -1,    51,    52,    -1,   438,    -1,
      -1,   460,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    71,    -1,   476,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,
      -1,   490,    88,    -1,    -1,   475,   495,    -1,    -1,   498,
     480,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,   377,
     190,   510,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   201,    -1,   119,    -1,   121,    -1,   507,    -1,    -1,
      -1,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    -1,   470,    -1,    -1,    -1,   202,    -1,    -1,   205,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,   490,   303,    -1,    -1,   222,   495,   224,    -1,
      -1,   227,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
      -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,   439,
      -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,
      -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,   385,
     470,    -1,    -1,    -1,    -1,   159,    -1,   393,    -1,    -1,
      -1,   481,    -1,    -1,    -1,   169,    -1,   403,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,   412,    -1,    -1,   499,
      -1,    -1,   502,   503,   504,   421,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,   430,    -1,   432,   201,    -1,    -1,
      -1,    -1,   438,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,   475,
      -1,   245,   246,   247,   480,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,     6,
      -1,   507,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
     284,    -1,    -1,    20,    -1,    -1,   290,    -1,    -1,   293,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,   303,
      -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,   313,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   346,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,   169,    -1,    -1,     6,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    82,   448,    -1,   450,    -1,   452,    -1,
      -1,   455,    -1,   457,   458,   459,   460,    -1,   462,   463,
      99,    -1,    -1,    -1,   201,    -1,   470,    -1,    -1,    -1,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,   245,   246,
     247,    82,    -1,   152,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,    -1,   264,    99,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,   284,    -1,    -1,
      -1,    -1,    -1,   290,    -1,    -1,   293,     6,    -1,    -1,
       9,    -1,   201,    -1,   301,    -1,   303,    -1,    -1,    -1,
      -1,   308,    -1,   212,    -1,    -1,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,   346,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
     201,    -1,   271,    82,    -1,    -1,    -1,    -1,    -1,    -1,
     377,   212,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,     6,    -1,    -1,     9,   228,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   416,
     251,    -1,   253,   322,    -1,   256,    -1,   258,   259,   260,
      -1,   428,   429,   264,    -1,   266,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,   448,    -1,   450,    -1,   452,    -1,    -1,   455,    -1,
     457,   458,   459,   460,    -1,   462,   463,    -1,    -1,    82,
      -1,    -1,   303,   470,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   322,   201,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,   212,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510,    -1,   346,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,   377,   256,    -1,   258,
     259,   260,    -1,    -1,   453,   264,    -1,   266,    -1,    -1,
      -1,   460,   271,    -1,    -1,   464,    -1,    -1,    -1,    -1,
      -1,   470,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,   201,    -1,
      -1,   490,    -1,    -1,   303,    -1,   495,   428,   429,   212,
      -1,     6,    -1,   502,     9,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,   245,    -1,    -1,    -1,    -1,   346,   251,   470,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    82,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,   490,
      -1,    -1,    -1,    -1,   495,    99,    -1,    -1,   377,     6,
      -1,   502,     9,   504,    -1,    -1,    -1,    82,   112,   510,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
     303,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    99,    -1,   377,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,   201,    -1,    -1,    -1,
      -1,   510,    -1,   416,    -1,    -1,    -1,   212,    -1,    -1,
      -1,   245,    -1,    -1,    -1,   428,   429,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,   460,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,   470,    -1,   264,
      -1,   266,    -1,    -1,   201,    -1,   271,    -1,    -1,   303,
      -1,    -1,    -1,    -1,    -1,   212,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,     6,   322,   502,
       9,   504,    -1,    -1,    -1,    -1,    -1,   510,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,   346,    -1,   251,    -1,   253,   322,    -1,   256,
      -1,   258,   259,   260,    -1,     6,    -1,   264,     9,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,   303,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   416,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
       6,   416,    -1,     9,    -1,    -1,    -1,    82,    99,    -1,
      -1,    -1,    -1,   428,   429,    -1,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   470,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   460,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,   470,    -1,    -1,   502,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   510,    -1,     6,   416,
      -1,     9,   201,    -1,    -1,   490,    82,    -1,    -1,    -1,
     495,   428,   429,   212,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    99,    -1,   510,    -1,    -1,    -1,   446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,   460,    -1,   190,   245,    -1,    -1,    -1,
      -1,   212,   251,   470,   253,    -1,   201,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,   490,    82,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,   245,   502,    -1,   504,    -1,    -1,
     251,    99,   253,   510,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,   303,   266,    -1,    -1,    -1,    -1,
     271,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
     196,     6,    -1,   322,     9,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,   377,    -1,
     256,    -1,   258,   259,   260,   346,    -1,    -1,   264,    -1,
     266,    -1,    -1,   201,    -1,   271,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   377,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,   428,
     429,    -1,   377,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,   322,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,   416,   264,    -1,   266,    -1,
      -1,   460,    -1,   271,    -1,    -1,    -1,   428,   429,    -1,
     346,   470,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,   490,    -1,    -1,   439,   303,   495,    -1,    -1,   460,
      -1,   377,    -1,   502,    -1,   504,    -1,    -1,    -1,   470,
      -1,   510,    -1,    -1,   322,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   484,    -1,   470,    -1,   212,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,   481,    -1,   346,    -1,
     416,   502,    -1,   504,    -1,   490,    -1,    -1,    82,   510,
     495,    -1,   428,   429,   499,    -1,    -1,   502,   503,   504,
     245,    -1,    -1,    -1,    -1,    99,   251,    -1,   253,   377,
      -1,   256,    -1,   258,   259,   260,    -1,     6,    -1,   264,
       9,   266,    -1,    -1,   460,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,   303,   495,
     428,   429,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,    -1,    -1,   510,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,   470,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,   377,    -1,   502,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,   416,   266,    -1,    -1,    -1,    -1,   271,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   201,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,   470,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,   346,    -1,    -1,    -1,   245,   502,    -1,   504,
      -1,    -1,   251,    -1,   253,   510,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,   271,   377,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   416,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    -1,   322,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,
     504,    32,    -1,    -1,    35,    -1,   510,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,   416,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,   428,
     429,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,    -1,   178,   179,   180,
     181,   182,     1,    -1,   185,   186,    -1,    -1,   189,   319,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,
     330,    -1,    21,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,   343,    -1,    -1,    -1,    36,   219,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,   407,   408,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,   345,    -1,    -1,   477,   478,   479,
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
      -1,    82,    -1,    -1,    -1,    -1,   405,    -1,   407,   408,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
     181,   182,   491,    -1,   185,   186,    -1,    -1,    -1,   498,
      82,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,   277,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,   201,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,   319,    -1,
     212,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   355,   346,    -1,    -1,    -1,   251,
      -1,   253,   363,    -1,   256,    -1,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,   405,   189,   407,   408,   409,    -1,
      -1,   303,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,   416,    -1,   211,    -1,    -1,
     322,    -1,    -1,   434,    -1,   219,    -1,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,
     451,   235,    -1,    -1,   346,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    82,    -1,    -1,    -1,   468,   252,   460,
      -1,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,   470,
      99,   265,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,
     491,    -1,    -1,   277,    -1,    -1,    -1,   498,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,   305,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   318,   319,   428,   429,    -1,    -1,
      -1,    82,    -1,   327,    -1,    -1,   330,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    99,   343,
      -1,   345,    -1,    -1,    -1,    -1,   458,    82,   460,    -1,
     462,   463,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,   201,    -1,    99,    -1,    -1,   371,    -1,    -1,
      -1,    -1,    -1,   212,   378,    -1,    -1,    -1,   490,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     502,   395,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
      -1,   405,    -1,   407,   408,   409,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
     201,    -1,   446,    -1,    -1,    -1,    -1,   451,    -1,    -1,
      -1,   212,   456,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,   201,    -1,    -1,   473,
      -1,    -1,    -1,   477,   478,   479,    -1,   212,    -1,    -1,
      -1,    -1,    -1,   322,   245,    -1,    -1,   491,    -1,    -1,
     251,    -1,   253,   497,   498,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,   346,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    -1,   212,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   346,    -1,   322,    -1,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,   448,
     256,   346,   258,   259,   260,    -1,   377,    82,   264,   458,
     266,   460,    -1,   462,   463,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    82,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   490,    -1,    -1,    -1,   416,   495,   303,    -1,    -1,
      -1,    -1,    -1,   502,    -1,   504,    -1,   428,   429,    -1,
      -1,   510,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,
      -1,    -1,    -1,   428,   429,    -1,    -1,   458,    -1,   460,
     346,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,   460,    -1,   462,   463,   490,
      -1,   377,    -1,    -1,   495,   470,   201,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,   212,    -1,   510,
      -1,    -1,   201,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,   212,    -1,    -1,    -1,   502,    -1,   504,
     416,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
     245,    -1,   428,   429,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,   245,    -1,    -1,   264,
      -1,   266,   251,    -1,   253,    -1,    -1,   256,    -1,   258,
     259,   260,    -1,    -1,   460,   264,   462,   266,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,   303,    -1,   502,   322,   504,    -1,
      -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     603,   535,   523,   451,   232,   537,  1263,   504,  1183,  1183,
     423,   405,  1281,  1263,  1263,  1263,   394,  1183,   405,   451,
     451,  1263,   451,   451,    57,  1251,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1263,  1263,  1263,   504,  1178,  1209,
      68,  1178,   451,  1263,  1263,   549,   560,  1178,   545,   504,
     587,   588,   589,  1184,   256,   307,   309,   573,   575,  1030,
    1212,  1263,   451,   504,   451,   606,   539,   340,  1278,  1263,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1215,
    1178,   256,   218,   306,  1301,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1250,  1311,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1184,  1264,  1030,   232,   423,  1275,  1263,
      96,  1183,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1294,  1209,   400,   401,   410,
      63,  1263,   451,   552,   451,   504,   551,    59,  1263,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1294,   256,
     590,  1213,  1275,   232,  1183,  1183,   574,   575,   451,     1,
     290,   312,  1236,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1215,   328,  1263,   401,  1212,   451,  1263,
     504,  1179,   229,    26,   565,   229,   370,   451,   451,   107,
    1213,  1183,   451,   312,  1183,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1212,   257,   435,
     494,   557,  1179,   256,   272,   608,   454,  1254,    23,  1245,
     102,   648,   451,   582,   583,    57,   505,  1305,   609,   437,
    1287,   188,  1256,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1279,  1295,    86,  1252,   504,  1168,  1169,   451,   394,   650,
     583,   272,  1270,   351,  1279,   446,   497,  1291,   401,   402,
    1263,  1250,   113,   237,  1265,  1265,   287,   635,  1212,  1294,
     423,   262,    39,  1248,  1263,   645,   646,  1169,  1169,   451,
     172,   392,   530,   651,   652,   654,  1263,  1265,   125,   171,
     614,   359,   628,  1263,  1263,  1263,  1263,  1245,     9,   287,
     349,   637,  1263,  1270,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1169,   125,   347,   402,   618,  1263,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1178,  1182,   419,   632,  1178,  1178,   316,  1276,  1276,
     310,  1178,  1263,  1212,   394,   261,   732,   683,   684,   686,
     696,  1228,   451,   653,   632,   256,   616,  1209,   616,     7,
     616,   616,   256,   615,  1209,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1230,  1310,  1254,
    1263,  1177,  1178,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1263,   124,  1177,
    1178,   262,   385,   681,   733,   451,   394,   389,   781,   698,
     689,  1263,  1252,  1263,   351,   353,  1306,  1306,  1263,  1252,
    1263,  1270,  1263,    22,  1244,   306,   678,  1183,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1263,
    1283,    26,   196,   697,  1246,   204,  1212,   504,  1263,  1244,
     504,  1180,  1181,   308,   418,  1302,  1182,  1212,   499,  1263,
     174,   213,   504,   665,  1183,   274,   351,   353,  1304,   681,
     737,   451,   337,   795,   798,   244,   301,   406,   476,  1282,
     476,  1282,   476,  1282,   476,  1282,   476,  1282,   501,  1292,
     384,  1280,  1212,  1206,  1209,  1209,   232,   242,   384,  1266,
    1263,  1264,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1216,
    1217,  1218,   446,   662,  1181,   254,  1269,   446,  1251,   218,
    1258,   504,  1263,  1263,  1304,   738,   782,   122,   821,   822,
     510,   446,   713,   462,  1210,  1211,   442,   706,   727,   728,
    1216,    26,   702,   400,  1240,  1240,  1218,   306,  1273,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1206,   691,   447,  1212,    57,   353,   658,   669,  1212,
     410,  1284,   256,   666,  1209,   666,   348,   739,   686,   696,
     783,   784,   785,    55,   497,   799,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   823,   824,
     839,   844,   848,   853,   868,   871,   875,   879,   880,   881,
     886,   900,   904,   907,   921,   924,   927,   930,   934,   935,
     939,   949,   952,   969,   971,   974,   978,   984,   996,  1004,
    1005,  1008,  1009,  1013,  1018,  1019,  1027,  1042,  1052,  1061,
    1066,  1073,  1077,  1079,  1082,  1085,  1089,  1114,   823,  1212,
     445,  1289,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1156,  1158,  1159,  1160,  1161,  1162,
    1163,  1191,  1205,  1206,  1217,  1219,  1220,  1221,  1222,   462,
    1211,  1209,   726,   728,   442,   256,  1250,   691,   451,  1218,
      48,   465,   670,   671,   672,   673,  1294,  1251,   196,   661,
    1257,   504,  1170,     1,   687,   785,   451,   801,   800,   376,
     807,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1241,   825,   840,   845,   849,   854,   869,   872,   876,
     882,   887,   901,   905,   908,   922,   925,   928,   931,   936,
     940,   950,   953,   970,   972,   975,   399,   979,   985,   997,
    1006,  1010,  1014,  1020,  1028,  1043,  1053,   256,   346,   387,
     416,   510,  1065,  1067,  1074,   336,  1078,  1080,   810,  1083,
    1086,  1090,  1115,   114,   714,   462,  1224,  1206,  1217,  1219,
    1301,  1301,   462,   462,   462,   462,  1301,  1162,  1158,  1162,
     462,  1224,    70,   398,   448,  1157,   449,   458,   463,   450,
     459,   169,   462,  1223,   462,   462,  1158,   501,   729,  1293,
    1216,  1182,  1182,   187,   662,  1212,   740,   451,   786,   451,
      49,   802,   803,   804,  1249,   802,   504,   451,   308,   826,
     827,  1205,     6,    94,   245,   271,   841,  1163,  1187,  1188,
    1205,  1216,  1219,   846,  1158,  1205,   256,   850,   851,  1174,
    1175,  1176,  1209,   271,   422,   424,   855,   856,   256,   870,
    1196,  1205,   873,  1169,     6,   877,  1164,  1165,  1186,  1207,
    1208,  1209,  1217,   454,   883,  1169,   256,   888,   889,   891,
    1187,  1188,  1196,  1205,   902,  1188,   256,   906,   453,   464,
     909,   910,   911,  1146,  1147,  1148,   199,   323,   324,   340,
     394,   923,   926,  1185,  1186,   929,  1209,   446,   932,  1290,
    1145,  1146,   941,  1185,   951,  1170,   954,   955,  1205,  1216,
    1219,  1044,  1203,  1204,  1209,    94,   973,  1188,   976,  1188,
     170,   225,   233,   317,   980,   981,   190,   256,   986,   990,
     991,   992,  1174,  1197,  1205,  1209,  1219,  1294,   998,  1169,
    1007,  1166,  1209,  1011,  1169,  1015,  1166,     9,  1021,  1167,
    1209,   153,   271,  1029,  1032,  1033,  1036,  1037,  1038,  1039,
    1040,  1041,  1171,  1172,  1185,  1202,  1204,  1209,  1044,  1054,
    1169,  1062,   112,  1068,  1069,  1070,  1188,    94,  1075,  1187,
    1081,  1170,   451,   504,   811,   812,   815,   816,   821,  1084,
    1205,  1087,  1169,  1091,  1205,  1116,  1166,   309,  1274,   715,
     716,   448,  1156,  1158,   504,   504,  1158,  1227,  1227,  1227,
    1190,  1205,  1217,  1219,  1226,   504,   448,  1190,  1225,  1158,
     448,  1158,  1159,  1159,  1160,  1160,  1160,  1158,  1190,  1156,
     403,   453,    30,  1247,  1251,     1,   741,   787,   803,   410,
     476,   805,   357,   498,   796,   130,   838,    30,   829,   830,
    1247,   196,  1273,  1205,  1206,  1217,  1219,   131,   843,   446,
     842,  1188,    57,   223,  1231,   851,   446,  1301,   132,   867,
     256,  1197,  1196,  1169,   356,   474,   874,  1294,  1307,  1273,
     133,   878,   159,   452,  1165,  1298,   386,  1237,  1210,  1211,
     884,  1169,   134,   885,  1279,   135,   899,   165,   890,  1125,
    1126,   484,   892,   503,   830,   485,   486,   487,   488,   136,
     903,    49,   228,   497,   857,   137,   920,    17,   501,   912,
     913,   914,   916,    12,    13,    14,    20,   159,   169,   207,
     208,   246,   247,   284,   290,   293,   301,   308,   313,   332,
     448,   450,   452,   455,   457,   458,   459,   462,   463,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1188,   101,  1186,  1173,
     441,  1288,   942,  1294,  1170,    92,   365,   436,   956,   957,
     959,   960,  1046,   462,  1210,  1188,   446,   140,   977,    49,
     981,   404,   982,   991,   141,   451,   987,   989,   481,   499,
     442,   445,   439,   143,  1003,   285,   334,  1234,   196,  1117,
     144,  1012,  1279,   145,  1017,  1117,  1167,   146,  1026,   499,
    1022,  1194,  1205,  1217,  1039,  1041,  1185,   446,  1172,   123,
     446,   482,  1031,    31,  1210,   147,  1060,   177,   237,   240,
    1056,   203,   376,  1063,  1294,  1249,   148,  1072,   228,  1070,
    1205,   149,  1076,   196,  1170,   394,   451,   451,   196,   351,
     353,  1088,   150,  1100,   112,  1092,   151,  1121,  1117,  1178,
     220,   718,    27,   115,   717,   448,  1157,   448,   448,   448,
    1157,   448,  1157,   448,   448,   449,   448,   448,   446,  1263,
    1182,   114,   660,   451,    61,    89,    90,   321,   451,   742,
     743,   746,  1263,  1319,    32,    35,    38,    45,    46,    64,
      66,   160,   189,   196,   198,   211,   243,   252,   265,   305,
     318,   345,   371,   378,   395,   446,   456,   473,   497,   704,
     705,   709,   721,   723,   725,   788,   793,   794,  1263,  1296,
    1263,   410,   312,   806,   109,   808,  1194,   197,   833,   252,
     331,   831,   832,  1296,    24,    25,    65,    67,    69,   103,
     104,   105,   153,   155,   162,   165,   252,   254,   443,   493,
     504,   828,  1172,  1297,   152,   340,  1192,  1206,   446,     6,
    1164,  1188,  1209,  1217,   203,   223,  1232,   376,   847,   339,
     852,  1176,   857,   874,   262,   287,  1256,  1206,  1158,   272,
    1238,  1211,  1169,   231,  1141,  1142,   818,   819,   891,  1188,
     294,  1127,    96,   335,   504,  1172,   298,   896,    35,    38,
      45,    46,    91,   160,   189,   211,   265,   318,   378,   391,
     473,   897,   898,   484,   893,  1125,  1125,  1125,  1125,  1188,
    1164,  1188,   858,   911,    21,   453,   464,   917,   918,  1147,
     501,   914,   915,   501,   818,  1290,   232,  1150,   114,   933,
    1174,   128,   818,   937,     9,    12,    15,    16,   277,   278,
     301,   302,   943,   947,   175,  1194,     9,    57,   177,   241,
     468,   963,   964,   965,   958,   959,  1048,  1274,  1310,   446,
    1185,  1164,  1188,   982,  1294,  1168,   818,   168,   993,  1145,
     994,   995,  1205,  1174,     8,    37,  1119,  1279,  1201,  1205,
    1216,  1219,   228,   999,  1016,  1294,   129,  1023,  1205,  1023,
     446,   446,  1030,   152,   453,   464,  1188,    49,    38,    46,
     211,   243,   265,   318,   378,   473,  1034,  1035,  1263,  1055,
    1294,  1188,  1188,   161,   289,   410,  1188,  1205,   196,  1164,
    1188,   817,  1212,  1194,  1249,   228,  1095,  1118,  1119,  1249,
    1265,  1178,  1223,  1223,  1223,  1190,   241,   468,  1223,   448,
    1158,  1223,  1223,  1216,  1274,  1263,  1263,  1244,   248,   249,
    1268,   755,   204,   176,   744,  1255,  1263,   252,   389,   156,
     158,  1263,  1197,   299,  1271,  1212,    56,  1205,  1205,   204,
    1271,    32,   110,  1212,  1263,   504,   451,   797,   272,   834,
    1271,  1271,   832,   831,  1271,   165,  1122,  1123,   509,   508,
    1194,  1122,   237,   423,   299,   276,   256,  1193,  1206,  1205,
    1273,   411,  1128,  1129,  1210,  1211,  1164,   446,  1233,   847,
    1186,   446,  1174,   203,   376,   862,   863,   380,   362,  1128,
    1263,   818,   295,  1143,   820,   818,  1125,  1263,   252,   389,
     156,   158,  1263,   123,   482,   898,  1125,    96,    97,   894,
     834,   203,  1128,   203,   859,   860,   861,  1249,    17,   442,
     919,   316,   917,  1274,   818,   128,   139,   938,  1290,   365,
     944,  1290,   446,    49,   964,   966,  1194,     9,    57,   241,
     468,   961,   962,  1194,  1049,  1295,   717,   218,   314,  1259,
    1185,  1128,   203,  1168,   637,   379,   983,  1294,   141,   988,
       8,   196,   999,  1205,   129,  1134,  1136,  1141,   262,   287,
     818,   501,   501,  1024,  1025,  1194,  1193,  1188,  1030,  1030,
    1030,  1030,  1030,  1030,  1030,  1030,  1035,   290,   293,  1057,
    1058,  1059,  1151,  1235,  1141,   244,   410,  1309,   423,  1286,
    1286,  1071,  1294,  1205,  1128,   203,   451,   446,     9,  1093,
    1094,  1229,  1096,  1205,  1071,  1096,  1016,     7,  1242,   504,
     719,   720,  1263,   448,  1178,  1196,  1263,  1244,   256,   747,
    1214,   686,   756,   745,  1205,   510,  1198,  1202,  1212,  1198,
    1263,  1289,  1263,  1263,    32,  1212,   809,   810,  1263,   503,
     835,  1198,  1198,  1198,   818,   294,  1124,  1122,  1237,  1206,
     818,   297,  1130,  1211,  1128,  1195,  1205,  1216,   165,   461,
     865,  1300,     6,   228,   308,   460,   864,  1262,    34,   281,
     282,   283,   344,   466,   467,   471,  1239,   818,   821,  1198,
    1198,  1144,  1200,  1202,  1212,  1144,   503,   895,  1164,  1165,
    1164,  1165,   860,   308,   805,    87,   357,   498,   918,  1146,
     818,  1205,   818,   498,   945,   946,   947,   948,  1288,   498,
    1195,  1194,    49,   967,   962,   188,   967,  1045,  1263,  1265,
     314,  1164,   983,   262,   287,   995,  1188,   217,  1000,  1294,
     818,   291,  1137,   262,  1146,  1145,  1024,  1151,  1205,  1152,
    1153,  1154,  1155,  1158,  1064,  1188,  1064,   461,  1131,  1132,
     330,  1237,  1164,   813,  1195,   313,  1194,   113,  1097,   436,
    1099,   157,   292,  1120,  1138,  1139,  1140,  1141,   321,  1172,
    1198,   720,  1177,   748,   252,   254,  1303,   504,   687,  1205,
     270,   329,   458,   463,   789,   790,   791,  1196,   789,   790,
     792,   810,    47,    32,    35,    38,    46,    91,   189,   198,
     211,   243,   263,   265,   288,   318,   345,   371,   378,   391,
     395,   444,   473,   483,   489,   836,   837,  1122,   818,  1128,
     818,   294,   866,   818,  1273,  1205,   252,   254,  1308,   897,
    1128,   361,  1128,   361,  1188,   946,   102,  1253,  1290,   967,
     967,  1195,     8,    37,   968,   225,   497,  1050,  1178,  1047,
    1128,   380,    49,   262,   237,  1001,   216,   236,   262,   287,
     500,   818,   818,   818,   818,   296,  1133,  1263,  1128,  1128,
     492,   814,  1101,  1094,  1258,    95,  1098,  1258,  1131,   818,
     818,  1140,   252,   254,  1267,   177,   187,   210,   240,   749,
     750,   751,   752,   753,   754,  1214,   757,  1198,  1198,   129,
    1263,  1263,    56,   123,   482,     8,  1243,   837,   818,  1205,
    1165,  1165,    49,   110,   967,   456,  1261,  1261,   337,  1168,
     203,   317,  1051,  1209,  1188,  1263,  1002,  1135,  1136,  1137,
    1141,   262,   262,   262,   818,  1205,  1102,   451,  1205,  1258,
    1205,   106,   116,  1312,  1263,  1263,    54,    89,  1312,  1313,
    1297,   758,   109,  1198,  1198,  1263,  1144,  1144,  1199,  1202,
    1214,  1128,  1128,  1188,  1188,  1188,  1263,  1168,   337,   481,
    1205,  1137,   127,   166,   204,  1103,  1104,  1105,  1107,  1111,
    1112,  1113,  1256,  1205,  1263,  1214,  1214,   210,  1263,  1263,
     209,   252,   254,   285,   305,   333,   414,   431,   451,   472,
     491,   499,   704,   709,   710,   721,   723,   725,   759,   760,
     764,   765,   768,   769,   770,   771,   772,   773,   778,   779,
     780,  1296,  1297,   451,  1196,   990,  1263,  1145,    37,  1243,
     107,  1214,  1214,  1214,   221,  1260,   299,   300,  1272,  1244,
     209,  1212,   501,  1263,  1273,  1263,  1263,  1205,   286,   329,
     774,   775,  1214,   329,   776,   777,  1214,  1272,  1244,   990,
     367,   418,  1285,  1274,  1264,  1263,   713,  1145,  1191,  1189,
    1191,    53,    89,   321,   325,   326,   366,   382,   383,   761,
    1312,  1313,  1314,  1315,  1316,  1317,  1318,   119,   196,  1212,
     775,  1212,   777,  1264,  1205,   161,   165,  1299,     9,  1108,
    1109,  1175,   775,  1289,  1237,   373,   766,  1191,   187,   187,
     210,   187,   210,   176,   762,  1205,   762,  1191,   337,  1277,
     306,   338,   358,  1110,  1109,   714,  1274,   313,   763,   763,
      49,  1274,   306,  1209,   425,   711,   176,   767,  1205,   321,
    1191,   170,   225,   233,   317,  1106,  1168,  1212
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
#line 1346 "parser.y"
    {
	clear_initial_values();
	current_program = NULL;
	cobc_cs_check = 0;
	prog_end = 0;
	depth = 0;
	main_flag_set = 0;
	current_program = cb_build_program(NULL, 0);
	cb_build_registers();
  }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 1357 "parser.y"
    {
	if(!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body(current_program);
	}
	if(depth > 1) {
		cb_error(_("Multiple PROGRAM-ID's without matching END PROGRAM"));
	}
	if(cobc_flag_main && !main_flag_set) {
		cb_error(_("Executable requested but no program found"));
	}
	if(errorcount > 0) {
		YYABORT;
	}
	if(!current_program->entry_list) {
		emit_entry(current_program->program_id, 0, NULL);
	}
  }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 1393 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	prog_end = 1;
	if(increment_depth()) {
		YYABORT;
	}
	cb_tree l = cb_build_alphanumeric_literal(demangle_name, strlen(demangle_name));
	current_program->program_id = cb_build_program_id(l, NULL, 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if(!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = cobc_flag_main;
	}
	check_relaxed_syntax(COBC_HD_PROGRAM_ID);
  }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 1445 "parser.y"
    {
	char * s;

	if(CB_LITERAL_P((yyvsp[(2) - (3)]))) {
		s = (char *)(CB_LITERAL((yyvsp[(2) - (3)]))->data);
	} else {
		s = (char *)(CB_NAME((yyvsp[(2) - (3)])));
	}
	if(depth) {
		depth--;
	}
	if(strcmp(stack_progid[depth], s)) {
		cb_error(_("END PROGRAM '%s' is different to PROGRAM-ID '%s'"),
			s, stack_progid[depth]);
	}
	if(!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body(current_program);
	}
  }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 1474 "parser.y"
    {
	char * s;

	if(CB_LITERAL_P((yyvsp[(2) - (3)]))) {
		s = (char *)(CB_LITERAL((yyvsp[(2) - (3)]))->data);
	} else {
		s = (char *)(CB_NAME((yyvsp[(2) - (3)])));
	}
	if(depth) {
		depth--;
	}
	if(strcmp(stack_progid[depth], s)) {
		cb_error(_("END FUNCTION '%s' is different to FUNCTION-ID '%s'"),
			s, stack_progid[depth]);
	}
	if(!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body(current_program);
	}
  }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 1507 "parser.y"
    {
	cb_validate_program_environment(current_program);
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1513 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1525 "parser.y"
    {
	cb_validate_program_data(current_program);
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 1535 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	if(CB_LITERAL_P((yyvsp[(3) - (4)]))) {
		stack_progid[depth] = (char *)(CB_LITERAL((yyvsp[(3) - (4)]))->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME((yyvsp[(3) - (4)])));
	}
	if(prog_end) {
		if(!current_program->flag_validated) {
			current_program->flag_validated = 1;
			cb_validate_program_body(current_program);
		}
		clear_initial_values();
		current_program = cb_build_program(current_program, depth);
		build_nested_special(depth);
		cb_build_registers();
	} else {
		prog_end = 1;
	}
	if(increment_depth()) {
		YYABORT;
	}
	current_program->program_id = cb_build_program_id((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]), 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if(!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = !!cobc_flag_main;
	}
  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 1566 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1573 "parser.y"
    {
#if	0	/* RXWRXW - FUNCTION-ID */
	cb_error(_("FUNCTION-ID is not yet implemented"));
#endif
	current_section = NULL;
	current_paragraph = NULL;
	if(CB_LITERAL_P((yyvsp[(3) - (5)]))) {
		stack_progid[depth] = (char *)(CB_LITERAL((yyvsp[(3) - (5)]))->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME((yyvsp[(3) - (5)])));
	}
	if(prog_end) {
		if(!current_program->flag_validated) {
			current_program->flag_validated = 1;
			cb_validate_program_body(current_program);
		}
		clear_initial_values();
		current_program = cb_build_program(current_program, depth);
		build_nested_special(depth);
		cb_build_registers();
	} else {
		prog_end = 1;
	}
	if(increment_depth()) {
		YYABORT;
	}
	current_program->program_id = cb_build_program_id((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), 1);
	current_program->prog_type = CB_FUNCTION_TYPE;
	current_program->flag_recursive = 1;
	cobc_cs_check = 0;
  }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 1612 "parser.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1613 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1622 "parser.y"
    {
	if(!current_program->nested_level) {
		cb_error(_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog(current_program);
	}
  }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 1631 "parser.y"
    {
	if(!current_program->nested_level) {
		cb_error(_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog(current_program);
	}
  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 1645 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1649 "parser.y"
    {
	current_program->flag_recursive = 1;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1659 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1668 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if(current_program->nested_level) {
		cb_error(_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1693 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated("SOURCE-COMPUTER", SYN_CLAUSE_1);
	if(warningopt &&(check_comp_duplicate & SYN_CLAUSE_2)) {
		cb_warning(_("Phrases in non-standard order"));
	}
  }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 1710 "parser.y"
    {
	cb_verify(cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item();
  }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 1723 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated("OBJECT-COMPUTER", SYN_CLAUSE_2);
  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1751 "parser.y"
    {
	cb_verify(cb_memory_size_clause, "MEMORY SIZE");
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
	if(current_program->classification) {
		cb_error(_("Duplicate CLASSIFICATION clause"));
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
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, 0, 0);
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
	cb_tree x;

	if((yyvsp[(3) - (3)])) {
		x = (yyvsp[(3) - (3)]);
	} else {
		x = (yyvsp[(2) - (3)]);
	}
	current_program->user_spec_list =
		cb_list_add(current_program->user_spec_list, x);
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
		cb_list_add(current_program->function_spec_list, (yyvsp[(1) - (1)]));
  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1874 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add(current_program->function_spec_list, (yyvsp[(2) - (2)]));
  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1885 "parser.y"
    {
	check_duplicate = 0;
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, 0, 0);
	header_check |= COBC_HD_SPECIAL_NAMES;
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	}
  }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1898 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1929 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
		save_tree = NULL;
	} else {
		save_tree = lookup_system_name(CB_NAME((yyvsp[(1) - (1)])));
		if(!save_tree) {
			cb_error_x((yyvsp[(1) - (1)]), _("Invalid system-name '%s'"), CB_NAME((yyvsp[(1) - (1)])));
		}
	}
  }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1946 "parser.y"
    {
	if(save_tree) {
		if(CB_SYSTEM_NAME(save_tree)->token != CB_DEVICE_CONSOLE) {
			cb_error_x(save_tree, _("Invalid CRT clause"));
		} else {
			current_program->flag_console_is_crt = 1;
		}
	}
  }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1956 "parser.y"
    {
	if(save_tree) {
		if(CB_SYSTEM_NAME(save_tree)->token != CB_FEATURE_CONVENTION) {
			cb_error_x(save_tree, _("Invalid special names clause"));
		} else if(CB_VALID_TREE((yyvsp[(3) - (3)]))) {
			CB_SYSTEM_NAME(save_tree)->value = (yyvsp[(1) - (3)]);
			cb_define((yyvsp[(3) - (3)]), save_tree);
			CB_CHAIN_PAIR(current_program->mnemonic_spec_list,
					(yyvsp[(3) - (3)]), save_tree);
		}
	}
  }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1969 "parser.y"
    {
	if(save_tree && CB_VALID_TREE((yyvsp[(2) - (3)]))) {
		cb_define((yyvsp[(2) - (3)]), save_tree);
		CB_CHAIN_PAIR(current_program->mnemonic_spec_list,
				(yyvsp[(2) - (3)]), save_tree);
	}
  }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1985 "parser.y"
    {
	/* cb_define_switch_name checks param validity */
	cb_tree x = cb_define_switch_name((yyvsp[(3) - (3)]), save_tree, (yyvsp[(1) - (3)]) == cb_int1);
	if(x) {
		CB_CHAIN_PAIR(current_program->mnemonic_spec_list, (yyvsp[(3) - (3)]), x);
	}
  }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1993 "parser.y"
    {
	/* cb_define_switch_name checks param validity */
	cb_tree x = cb_define_switch_name((yyvsp[(4) - (4)]), save_tree, (yyvsp[(2) - (4)]) == cb_int1);
	if(x) {
		CB_CHAIN_PAIR(current_program->mnemonic_spec_list, (yyvsp[(4) - (4)]), x);
	}
  }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 2006 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
		(yyval) = NULL;
	} else {
		/* Returns null on error */
		(yyval) = cb_build_alphabet_name((yyvsp[(2) - (2)]));
	}
  }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 2017 "parser.y"
    {
	if((yyvsp[(3) - (5)])) {
		current_program->alphabet_name_list =
			cb_list_add(current_program->alphabet_name_list, (yyvsp[(3) - (5)]));
	}
	cobc_cs_check = 0;
  }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 2028 "parser.y"
    {
	if((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2034 "parser.y"
    {
	if((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2040 "parser.y"
    {
	if((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2046 "parser.y"
    {
	if((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2052 "parser.y"
    {
	if((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2058 "parser.y"
    {
	if((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2068 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2072 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2079 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2083 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2087 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (2)]));
  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2091 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2098 "parser.y"
    {
	cb_list_add((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 2102 "parser.y"
    {
	cb_list_add((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2108 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2109 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2110 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2111 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2112 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2113 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2121 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else if((yyvsp[(1) - (2)])) {
		CB_CHAIN_PAIR(current_program->symbolic_char_list, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 2133 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 2137 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 2145 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 2152 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 2156 "parser.y"
    {
	if((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 2167 "parser.y"
    {
	cb_tree		l1;
	cb_tree		l2;

	if(cb_list_length((yyvsp[(1) - (3)])) != cb_list_length((yyvsp[(3) - (3)]))) {
		cb_error(_("Invalid SYMBOLIC clause"));
		(yyval) = NULL;
	} else {
		l1 = (yyvsp[(1) - (3)]);
		l2 = (yyvsp[(3) - (3)]);
		for(; l1; l1 = CB_CHAIN(l1), l2 = CB_CHAIN(l2)) {
			CB_PURPOSE(l1) = CB_VALUE(l2);
		}
		(yyval) = (yyvsp[(1) - (3)]);
	}
  }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 2187 "parser.y"
    {
	if((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 2195 "parser.y"
    {
	if((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 2205 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2206 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 2213 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		cb_tree x = cb_build_class_name((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		if(x) {
			current_program->class_name_list =
				cb_list_add(current_program->class_name_list, x);
		}
	}
  }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 2229 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2230 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2235 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2239 "parser.y"
    {
	if(CB_TREE_CLASS((yyvsp[(1) - (3)])) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P((yyvsp[(1) - (3)])) && CB_LITERAL((yyvsp[(1) - (3)]))->size != 1) {
		cb_error(_("CLASS literal with THRU must have size 1"));
	}
	if(CB_TREE_CLASS((yyvsp[(3) - (3)])) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P((yyvsp[(3) - (3)])) && CB_LITERAL((yyvsp[(3) - (3)]))->size != 1) {
		cb_error(_("CLASS literal with THRU must have size 1"));
	}
	if(literal_value((yyvsp[(1) - (3)])) <= literal_value((yyvsp[(3) - (3)]))) {
		(yyval) = CB_BUILD_PAIR((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	} else {
		(yyval) = CB_BUILD_PAIR((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
	}
  }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 2260 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		cb_tree l = cb_build_locale_name((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		if(l) {
			current_program->locale_list =
				cb_list_add(current_program->locale_list, l);
		}
	}
  }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 2279 "parser.y"
    {
	unsigned char * s = CB_LITERAL((yyvsp[(4) - (5)]))->data;
	unsigned int error_ind = 0;

	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
		error_ind = 1;
	}
	check_repeated("CURRENCY", SYN_CLAUSE_1);
	if((yyvsp[(5) - (5)])) {
		PENDING("PICTURE SYMBOL");
	}
	if(CB_LITERAL((yyvsp[(4) - (5)]))->size != 1) {
		cb_error_x((yyvsp[(4) - (5)]), _("Invalid currency sign '%s'"), (char *)s);
		error_ind = 1;
	}
	switch(*s) {
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
		cb_error_x((yyvsp[(4) - (5)]), _("Invalid currency sign '%s'"), (char *)s);
		break;
	default:
		if(!error_ind) {
			current_program->currency_symbol = s[0];
		}
		break;
	}
  }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 2358 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2362 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2371 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated("DECIMAL-POINT", SYN_CLAUSE_2);
		current_program->decimal_point = ',';
		current_program->numeric_separator = '.';
	}
  }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 2388 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		current_program->flag_trailing_separate = 1;
	}
  }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 2402 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated("CURSOR", SYN_CLAUSE_3);
		current_program->cursor_pos = (yyvsp[(3) - (3)]);
	}
  }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 2418 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated("CRT STATUS", SYN_CLAUSE_4);
		current_program->crt_status = (yyvsp[(4) - (4)]);
	}
  }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2434 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated("SCREEN CONTROL", SYN_CLAUSE_5);
		PENDING("SCREEN CONTROL");
	}
  }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2449 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_SPECIAL_NAMES, 0);
	if(current_program->nested_level) {
		cb_error(_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated("EVENT STATUS", SYN_CLAUSE_6);
		PENDING("EVENT STATUS");
	}
  }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2464 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2472 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2480 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_INPUT_OUTPUT_SECTION, 0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2494 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_INPUT_OUTPUT_SECTION, COBC_HD_FILE_CONTROL, 0);
	check_duplicate = 0;
	if(CB_INVALID_TREE((yyvsp[(3) - (3)]))) {
		YYERROR;
	}

	/* Build new file */
	current_file = build_file((yyvsp[(3) - (3)]));
	current_file->optional = CB_INTEGER((yyvsp[(2) - (3)]))->val;

	/* Add file to current program list */
	CB_ADD_TO_CHAIN(current_file, current_program->file_list);
  }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 2509 "parser.y"
    {
	validate_file(current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2513 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if(current_program->file_list) {
		current_program->file_list = CB_CHAIN(current_program->file_list);
	}
  }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2547 "parser.y"
    {
	check_repeated("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name(current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2553 "parser.y"
    {
	check_repeated("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name(current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_fileid = 1;
	}
  }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 2563 "parser.y"
    {
	check_repeated("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name(current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal("stdout", (size_t)6);
		current_file->special = COB_SELECT_STDOUT;
	}
  }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 2576 "parser.y"
    {
	check_repeated("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name(current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal("stdin", (size_t)5);
		current_file->special = COB_SELECT_STDIN;
	}
  }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 2589 "parser.y"
    {
	check_repeated("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	if((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name(current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal("LPT1", (size_t)4);
	}
  }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 2612 "parser.y"
    {
	current_file->flag_line_adv = 1;
  }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2619 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2632 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2644 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated("ACCESS", SYN_CLAUSE_2);
  }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2651 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2652 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2653 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2661 "parser.y"
    {
	cb_alt_key * p = (cb_alt_key *) cobc_parse_malloc(sizeof(cb_alt_key));
	p->key = (yyvsp[(5) - (6)]);
	p->duplicates = CB_INTEGER((yyvsp[(6) - (6)]))->val;
	p->next = NULL;

	/* Add to the end of list */
	if(current_file->alt_key_list == NULL) {
		current_file->alt_key_list = p;
	} else {
		cb_alt_key * l = current_file->alt_key_list;
		for(; l->next; l = l->next) {
			;
		}
		l->next = p;
	}
  }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 2685 "parser.y"
    {
	check_repeated("COLLATING", SYN_CLAUSE_3);
	PENDING("COLLATING SEQUENCE");
  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2696 "parser.y"
    {
	check_repeated("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2711 "parser.y"
    {
	check_repeated("LOCK", SYN_CLAUSE_5);
  }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2719 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2724 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2729 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 2738 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2742 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING("WITH ROLLBACK");
  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2758 "parser.y"
    {
	check_repeated("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2763 "parser.y"
    {
	check_repeated("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2768 "parser.y"
    {
	check_repeated("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2773 "parser.y"
    {
	check_repeated("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2784 "parser.y"
    {
	check_repeated("PADDING", SYN_CLAUSE_7);
	cb_verify(cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2795 "parser.y"
    {
	check_repeated("RECORD DELIMITER", SYN_CLAUSE_8);
  }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2805 "parser.y"
    {
	check_repeated("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2812 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2813 "parser.y"
    { PENDING("SPLIT KEYS"); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2814 "parser.y"
    { PENDING("SPLIT KEYS"); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2821 "parser.y"
    {
	check_repeated("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2832 "parser.y"
    {
	check_repeated("RESERVE", SYN_CLAUSE_11);
  }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2846 "parser.y"
    {
	check_repeated("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2853 "parser.y"
    { (yyval) = NULL; }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2854 "parser.y"
    { (yyval) = cb_int(COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2855 "parser.y"
    { (yyval) = NULL; }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2864 "parser.y"
    {
	yyerrok;
  }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2883 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_I_O_CONTROL, 0);
	switch(CB_INTEGER((yyvsp[(2) - (5)]))->val) {
	case 0:
		/* SAME AREA */
		break;
	case 1:
		/* SAME RECORD */
		for(cb_tree l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN(l)) {
			if(CB_VALID_TREE(CB_VALUE(l))) {
				CB_FILE(cb_ref(CB_VALUE(l)))->same_clause = samearea;
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
#line 2906 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2907 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2908 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2909 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 2916 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2921 "parser.y"
    {
	check_headers_present(COBC_HD_ENVIRONMENT_DIVISION, COBC_HD_CONFIGURATION_SECTION, COBC_HD_I_O_CONTROL, 0);
	cb_verify(cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 2946 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 2955 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present(COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 2969 "parser.y"
    {
	if(CB_VALID_TREE(current_file)) {
		if(CB_VALID_TREE((yyvsp[(2) - (2)]))) {
			if(current_file->reports) {
				cb_error(_("RECORD description invalid with REPORT"));
			} else {
				finalize_file(current_file, CB_FIELD((yyvsp[(2) - (2)])));
			}
		} else if(!current_file->reports) {
			cb_error(_("RECORD description missing or invalid"));
		}
	}
  }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 2988 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present(COBC_HD_DATA_DIVISION, COBC_HD_FILE_SECTION, 0, 0);
	check_duplicate = 0;
	if(CB_INVALID_TREE((yyvsp[(2) - (2)])) || cb_ref((yyvsp[(2) - (2)])) == cb_error_node) {
		YYERROR;
	}
	current_file = CB_FILE(cb_ref((yyvsp[(2) - (2)])));
	if(CB_VALID_TREE(current_file)) {
		if((yyvsp[(1) - (2)])) {
			current_file->organization = COB_ORG_SORT;
		}
	}
  }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 3004 "parser.y"
    {
	yyerrok;
  }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3011 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3015 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3026 "parser.y"
    {
	check_repeated("EXTERNAL", SYN_CLAUSE_1);
#if	0	/* RXWRXW - Global/External */
	if(current_file->flag_global) {
		cb_error(_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	current_file->flag_external = 1;
  }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 3036 "parser.y"
    {
	check_repeated("GLOBAL", SYN_CLAUSE_2);
#if	0	/* RXWRXW - Global/External */
	if(current_file->flag_external) {
		cb_error(_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		current_file->flag_global = 1;
		current_program->flag_file_global = 1;
	}
  }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 3066 "parser.y"
    {
	check_repeated("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 3079 "parser.y"
    {
	check_repeated("RECORD", SYN_CLAUSE_4);
	if(current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if(warningopt) {
			cb_warning(_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_max = cb_get_int((yyvsp[(3) - (4)]));
		if(current_file->record_max < 1)  {
			current_file->record_max = 1;
			cb_error(_("RECORD clause invalid"));
		}
		if(current_file->record_max > MAX_FD_RECORD)  {
			current_file->record_max = MAX_FD_RECORD;
			cb_error(_("RECORD size exceeds maximum allowed(%d)"),
				  MAX_FD_RECORD);
		}
	}
  }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 3099 "parser.y"
    {
	int	error_ind = 0;

	check_repeated("RECORD", SYN_CLAUSE_4);
	if(current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if(warningopt) {
			cb_warning(_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_min = cb_get_int((yyvsp[(3) - (6)]));
		current_file->record_max = cb_get_int((yyvsp[(5) - (6)]));
		if(current_file->record_min < 0)  {
			current_file->record_min = 0;
			error_ind = 1;
		}
		if(current_file->record_max < 1)  {
			current_file->record_max = 1;
			error_ind = 1;
		}
		if(current_file->record_max > MAX_FD_RECORD)  {
			current_file->record_max = MAX_FD_RECORD;
			cb_error(_("RECORD size exceeds maximum allowed(%d)"),
				  MAX_FD_RECORD);
			error_ind = 1;
		}
		if(current_file->record_max <= current_file->record_min)  {
			error_ind = 1;
		}
		if(error_ind) {
			cb_error(_("RECORD clause invalid"));
		}
	}
  }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 3134 "parser.y"
    {
	bool error_ind = false;

	check_repeated("RECORD", SYN_CLAUSE_4);
	current_file->record_min = (yyvsp[(6) - (9)]) ? cb_get_int((yyvsp[(6) - (9)])) : 0;
	current_file->record_max = (yyvsp[(7) - (9)]) ? cb_get_int((yyvsp[(7) - (9)])) : 0;
	if((yyvsp[(6) - (9)]) && current_file->record_min < 0)  {
		current_file->record_min = 0;
		error_ind = true;
	}
	if((yyvsp[(7) - (9)]) && current_file->record_max < 1)  {
		current_file->record_max = 1;
		error_ind = true;
	}
	if((yyvsp[(7) - (9)]) && current_file->record_max > MAX_FD_RECORD)  {
		current_file->record_max = MAX_FD_RECORD;
		cb_error(_("RECORD size exceeds maximum allowed(%d)"),
			  MAX_FD_RECORD);
		error_ind = true;
	}
	if(((yyvsp[(6) - (9)]) || (yyvsp[(7) - (9)])) && current_file->record_max <= current_file->record_min)  {
		error_ind = true;
	}
	if(error_ind) {
		cb_error(_("RECORD clause invalid"));
	}
  }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 3165 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 3171 "parser.y"
    { (yyval) = NULL; }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 3172 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 3176 "parser.y"
    { (yyval) = NULL; }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 3177 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3185 "parser.y"
    {
	check_repeated("LABEL", SYN_CLAUSE_5);
	cb_verify(cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3196 "parser.y"
    {
	check_repeated("VALUE OF", SYN_CLAUSE_6);
	cb_verify(cb_value_of_clause, "VALUE OF");
  }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3201 "parser.y"
    {
	check_repeated("VALUE OF", SYN_CLAUSE_6);
	cb_verify(cb_value_of_clause, "VALUE OF");
	if(!current_file->assign) {
		current_file->assign = cb_build_assignment_name(current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 3224 "parser.y"
    {
	check_repeated("DATA", SYN_CLAUSE_7);
	cb_verify(cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3236 "parser.y"
    {
	check_repeated("LINAGE", SYN_CLAUSE_8);
	if(current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error(_("LINAGE clause with wrong file type"));
	} else {
		current_file->linage = (yyvsp[(3) - (5)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		if(current_linage == 0) {
			linage_file = current_file;
		}
		current_linage++;
	}
  }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 3264 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 3271 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 3278 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3287 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3299 "parser.y"
    {
	check_repeated("CODE SET", SYN_CLAUSE_10);
	if(CB_VALID_TREE((yyvsp[(3) - (3)]))) {
		cb_tree x = cb_ref((yyvsp[(3) - (3)]));
		if(current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
		    current_file->organization != COB_ORG_SEQUENTIAL) {
			cb_error(_("CODE-SET clause invalid for file type"));
		}
		if(!CB_ALPHABET_NAME_P(x)) {
			cb_error_x((yyvsp[(3) - (3)]), _("Alphabet-name is expected '%s'"), cb_name((yyvsp[(3) - (3)])));
		} else {
			cb_alphabet_name * al = CB_ALPHABET_NAME(x);
			switch(al->alphabet_type) {
#ifdef	COB_EBCDIC_MACHINE
			case CB_ALPHABET_ASCII:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if(warningopt) {
					cb_warning_x((yyvsp[(3) - (3)]), _("Ignoring CODE-SET '%s'"),
						      cb_name((yyvsp[(3) - (3)])));
				}
				break;
#else
			case CB_ALPHABET_EBCDIC:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if(warningopt) {
					cb_warning_x((yyvsp[(3) - (3)]), _("Ignoring CODE-SET '%s'"),
						      cb_name((yyvsp[(3) - (3)])));
				}
				break;
#endif
			}
			if(warningopt) {
				PENDING("CODE-SET");
			}
		}
	}
  }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 3348 "parser.y"
    {
	check_repeated("REPORT", SYN_CLAUSE_11);
	cb_warning(_("REPORT WRITER not implemented"));
	if(current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error(_("REPORT clause with wrong file type"));
	} else {
		current_file->reports = (yyvsp[(2) - (2)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	}
  }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 3368 "parser.y"
    {
	current_report = build_report((yyvsp[(1) - (1)]));
	current_report->file = current_file;
	CB_ADD_TO_CHAIN(current_report, current_program->report_list);
	if(report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 3378 "parser.y"
    {
	current_report = build_report((yyvsp[(2) - (2)]));
	CB_ADD_TO_CHAIN(current_report, current_program->report_list);
	if(report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 3418 "parser.y"
    {
	check_headers_present(COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 3424 "parser.y"
    {
	if((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD(current_program->working_storage, CB_FIELD((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 3433 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 3436 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field();
  }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 3442 "parser.y"
    {
	for(cb_field * p = description_field; p; p = p->sister) {
		cb_validate_field(p);
	}
	(yyval) = description_field;
  }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 3460 "parser.y"
    {
	cb_tree x = cb_build_field_tree((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage, current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free((yyvsp[(1) - (2)]));
	if(CB_INVALID_TREE(x)) {
		YYERROR;
	} else {
		current_field = CB_FIELD(x);
		check_pic_duplicate = 0;
	}
  }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 3472 "parser.y"
    {
	if(!qualifier &&(current_field->level == 88 ||
	    current_field->level == 66 || current_field->flag_item_78)) {
		cb_error(_("Item requires a data name"));
	}
	if(!qualifier) {
		current_field->flag_filler = 1;
	}
	if(current_field->level == 88) {
		cb_validate_88_item(current_field);
	}
	if(current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item(current_field, 0);
	}
	if(!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 3492 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field();
  }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 3505 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3512 "parser.y"
    {
	(yyval) = cb_build_filler();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 3518 "parser.y"
    {
	(yyval) = cb_build_filler();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 3524 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 3533 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 3542 "parser.y"
    {
	(yyval)= NULL;
  }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 3546 "parser.y"
    {
	if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("GLOBAL is invalid in a user FUNCTION"));
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 3557 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 3558 "parser.y"
    { (yyval) = cb_build_const_length((yyvsp[(2) - (2)])); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 3559 "parser.y"
    { (yyval) = cb_build_const_length((yyvsp[(2) - (2)])); }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 3560 "parser.y"
    { (yyval) = cb_build_const_length((yyvsp[(3) - (3)])); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 3565 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 3569 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 3573 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 3577 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 3581 "parser.y"
    {
	(yyval) = cb_int(8);
  }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 3585 "parser.y"
    {
	(yyval) = cb_int((int)sizeof(long));
  }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 3589 "parser.y"
    {
	(yyval) = cb_int((int)sizeof(void *));
  }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 3593 "parser.y"
    {
	(yyval) = cb_int((int)sizeof(float));
  }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 3597 "parser.y"
    {
	(yyval) = cb_int((int)sizeof(double));
  }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 3601 "parser.y"
    {
	(yyval) = cb_int(4);
  }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 3605 "parser.y"
    {
	(yyval) = cb_int(8);
  }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 3609 "parser.y"
    {
	(yyval) = cb_int(16);
  }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 3613 "parser.y"
    {
	yyerrok;
	cb_unput_dot();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field();
  }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 3645 "parser.y"
    {
	cobc_cs_check = 0;
	int level = cb_get_level((yyvsp[(1) - (5)]));
	/* Free tree assocated with level number */
	cobc_parse_free((yyvsp[(1) - (5)]));
	if(level != 1) {
		cb_error(_("CONSTANT item not at 01 level"));
	} else if((yyvsp[(5) - (5)])) {
		cb_tree x = cb_build_constant((yyvsp[(2) - (5)]), (yyvsp[(5) - (5)]));
		CB_FIELD(x)->flag_item_78 = 1;
		CB_FIELD(x)->level = 1;
		cb_needs_01 = 1;
		if((yyvsp[(4) - (5)])) {
			CB_FIELD(x)->flag_is_global = 1;
		}
		/* Ignore return value */
		(void)cb_validate_78_item(CB_FIELD(x), 0);
	}
  }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 3668 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 3672 "parser.y"
    {
	PENDING("CONSTANT FROM clause");
	(yyval) = NULL;
  }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 3680 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3686 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 3714 "parser.y"
    {
	check_pic_repeated("REDEFINES", SYN_CLAUSE_1);
	if((yyvsp[(0) - (2)]) != NULL) {
		if(cb_relaxed_syntax_check) {
			cb_warning_x((yyvsp[(2) - (2)]), _("REDEFINES clause should follow entry-name"));
		} else {
			cb_error_x((yyvsp[(2) - (2)]), _("REDEFINES clause must follow entry-name"));
		}
	}

	current_field->redefines = cb_resolve_redefines(current_field, (yyvsp[(2) - (2)]));
	if(current_field->redefines == NULL) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
		YYERROR;
	}
  }
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 3738 "parser.y"
    {
	check_pic_repeated("EXTERNAL", SYN_CLAUSE_2);
	if(current_storage != CB_STORAGE_WORKING) {
		cb_error(_("EXTERNAL not allowed here"));
	} else if(current_field->level != 1 && current_field->level != 77) {
		cb_error(_("EXTERNAL only allowed at 01/77 level"));
	} else if(!qualifier) {
		cb_error(_("EXTERNAL requires a data name"));
#if	0	/* RXWRXW - Global/External */
	} else if(current_field->flag_is_global) {
		cb_error(_("GLOBAL and EXTERNAL are mutually exclusive"));
#endif
	} else if(current_field->flag_item_based) {
		cb_error(_("BASED and EXTERNAL are mutually exclusive"));
	} else if(current_field->redefines) {
		cb_error(_("EXTERNAL and REDEFINES are mutually exclusive"));
	} else if(current_field->flag_occurs) {
		cb_error(_("EXTERNAL and OCCURS are mutually exclusive"));
	} else {
		current_field->flag_external = 1;
		current_program->flag_has_external = 1;
	}
  }
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 3765 "parser.y"
    {
	current_field->ename = cb_to_cname(current_field->name);
  }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 3769 "parser.y"
    {
	current_field->ename = cb_to_cname((const char *)CB_LITERAL((yyvsp[(2) - (2)]))->data);
  }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 3778 "parser.y"
    {
	check_pic_repeated("GLOBAL", SYN_CLAUSE_3);
	if(current_field->level != 1 && current_field->level != 77) {
		cb_error(_("GLOBAL only allowed at 01/77 level"));
	} else if(!qualifier) {
		cb_error(_("GLOBAL requires a data name"));
#if	0	/* RXWRXW - Global/External */
	} else if(current_field->flag_external) {
		cb_error(_("GLOBAL and EXTERNAL are mutually exclusive"));
#endif
	} else if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("GLOBAL is invalid in a user FUNCTION"));
	} else if(current_storage == CB_STORAGE_LOCAL) {
		cb_error(_("GLOBAL not allowed here"));
	} else {
		current_field->flag_is_global = 1;
	}
  }
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 3803 "parser.y"
    {
	check_pic_repeated("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE((yyvsp[(1) - (1)]));
  }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 3819 "parser.y"
    {
	check_set_usage(CB_USAGE_BINARY);
  }
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 3823 "parser.y"
    {
	check_set_usage(CB_USAGE_BINARY);
  }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 3827 "parser.y"
    {
	check_set_usage(CB_USAGE_FLOAT);
  }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 3831 "parser.y"
    {
	check_set_usage(CB_USAGE_DOUBLE);
  }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 3835 "parser.y"
    {
	check_set_usage(CB_USAGE_PACKED);
  }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 3839 "parser.y"
    {
	check_set_usage(CB_USAGE_BINARY);
  }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 3843 "parser.y"
    {
	check_set_usage(CB_USAGE_COMP_5);
  }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 3847 "parser.y"
    {
	check_set_usage(CB_USAGE_COMP_6);
  }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 3851 "parser.y"
    {
	check_set_usage(CB_USAGE_COMP_X);
  }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 3855 "parser.y"
    {
	check_set_usage(CB_USAGE_DISPLAY);
  }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 3859 "parser.y"
    {
	check_set_usage(CB_USAGE_INDEX);
  }
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 3863 "parser.y"
    {
	check_set_usage(CB_USAGE_PACKED);
  }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 3867 "parser.y"
    {
	check_set_usage(CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 3872 "parser.y"
    {
	check_set_usage(CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 3877 "parser.y"
    {
	check_set_usage(CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 3881 "parser.y"
    {
	check_set_usage(CB_USAGE_SIGNED_INT);
  }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 3885 "parser.y"
    {
	if(sizeof(long) == 4) {
		check_set_usage(CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage(CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 3893 "parser.y"
    {
	check_set_usage(CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 3897 "parser.y"
    {
	check_set_usage(CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 3901 "parser.y"
    {
	if(sizeof(long) == 4) {
		check_set_usage(CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage(CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 3909 "parser.y"
    {
	check_set_usage(CB_USAGE_SIGNED_CHAR);
  }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 3913 "parser.y"
    {
	check_set_usage(CB_USAGE_UNSIGNED_CHAR);
  }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 3917 "parser.y"
    {
	check_set_usage(CB_USAGE_SIGNED_SHORT);
  }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 3921 "parser.y"
    {
	check_set_usage(CB_USAGE_UNSIGNED_SHORT);
  }
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 3925 "parser.y"
    {
	check_set_usage(CB_USAGE_SIGNED_INT);
  }
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 3929 "parser.y"
    {
	check_set_usage(CB_USAGE_UNSIGNED_INT);
  }
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 3933 "parser.y"
    {
	check_set_usage(CB_USAGE_SIGNED_LONG);
  }
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 3937 "parser.y"
    {
	check_set_usage(CB_USAGE_UNSIGNED_LONG);
  }
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 3941 "parser.y"
    {
	if(sizeof(long) == 4) {
		check_set_usage(CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage(CB_USAGE_SIGNED_LONG);
	}
  }
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 3949 "parser.y"
    {
	if(sizeof(long) == 4) {
		check_set_usage(CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage(CB_USAGE_UNSIGNED_LONG);
	}
  }
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 3957 "parser.y"
    {
	check_set_usage(CB_USAGE_FP_BIN32);
  }
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 3961 "parser.y"
    {
	check_set_usage(CB_USAGE_FP_BIN64);
  }
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 3965 "parser.y"
    {
	check_set_usage(CB_USAGE_FP_BIN128);
  }
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 3969 "parser.y"
    {
	check_set_usage(CB_USAGE_FP_DEC64);
  }
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 3973 "parser.y"
    {
	check_set_usage(CB_USAGE_FP_DEC128);
  }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 3977 "parser.y"
    {
	check_pic_repeated("USAGE", SYN_CLAUSE_5);
	PENDING("USAGE NATIONAL");
  }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 3997 "parser.y"
    {
	check_pic_repeated("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 4003 "parser.y"
    {
	check_pic_repeated("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 4016 "parser.y"
    {
	check_pic_repeated("OCCURS", SYN_CLAUSE_7);
	if(current_field->depending && !((yyvsp[(3) - (6)]))) {
		cb_verify(cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (6)]) ? cb_get_int((yyvsp[(2) - (6)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (6)]) ? cb_get_int((yyvsp[(3) - (6)])) : cb_get_int((yyvsp[(2) - (6)]));
	current_field->indexes++;
	if(current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error(_("Maximum OCCURS depth exceeded(%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	current_field->flag_occurs = 1;
  }
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 4034 "parser.y"
    {
	current_field->step_count = cb_get_int((yyvsp[(2) - (2)]));
  }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 4044 "parser.y"
    {
	check_pic_repeated("OCCURS", SYN_CLAUSE_7);
	if(current_field->depending && !((yyvsp[(3) - (7)]))) {
		cb_verify(cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (7)]) ? cb_get_int((yyvsp[(2) - (7)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (7)]) ? cb_get_int((yyvsp[(3) - (7)])) : cb_get_int((yyvsp[(2) - (7)]));
	current_field->indexes++;
	if(current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error(_("Maximum OCCURS depth exceeded(%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	if(current_field->flag_item_based) {
		cb_error(_("BASED and OCCURS are mutually exclusive"));
	} else if(current_field->flag_external) {
		cb_error(_("EXTERNAL and OCCURS are mutually exclusive"));
	}
	current_field->flag_occurs = 1;
  }
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 4066 "parser.y"
    { (yyval) = NULL; }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 4067 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 4072 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 4079 "parser.y"
    {
	if((yyvsp[(1) - (1)])) {
		cb_tree l = (yyvsp[(1) - (1)]);
		int nkeys = cb_list_length((yyvsp[(1) - (1)]));
		cb_key * keys = (cb_key *) cobc_parse_malloc(sizeof(cb_key) * nkeys);

		for(int i = 0; i < nkeys; i++) {
			keys[i].dir = CB_PURPOSE_INT(l);
			keys[i].key = CB_VALUE(l);
			l = CB_CHAIN(l);
		}
		current_field->keys = keys;
		current_field->nkeys = nkeys;
	}
  }
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 4097 "parser.y"
    { (yyval) = NULL; }
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 4100 "parser.y"
    {
	for(cb_tree l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN(l)) {
		CB_PURPOSE(l) = (yyvsp[(2) - (5)]);
		if(qualifier && !CB_REFERENCE(CB_VALUE(l))->chain &&
		    strcasecmp(CB_NAME(CB_VALUE(l)), CB_NAME(qualifier))) {
			CB_REFERENCE(CB_VALUE(l))->chain = qualifier;
		}
	}
	(yyval) = cb_list_append((yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 4113 "parser.y"
    { (yyval) = cb_int(COB_ASCENDING); }
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 4114 "parser.y"
    { (yyval) = cb_int(COB_DESCENDING); }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 4119 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 4125 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 4127 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 4132 "parser.y"
    {
	(yyval) = cb_build_index((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR((yyval))->special_index = 1;
  }
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 4143 "parser.y"
    {
	check_pic_repeated("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 4154 "parser.y"
    {
	check_pic_repeated("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 4165 "parser.y"
    {
	check_pic_repeated("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 4176 "parser.y"
    {
	check_pic_repeated("BASED", SYN_CLAUSE_11);
	if(current_storage != CB_STORAGE_WORKING &&
	    current_storage != CB_STORAGE_LINKAGE &&
	    current_storage != CB_STORAGE_LOCAL) {
		cb_error(_("BASED not allowed here"));
	} else if(current_field->level != 1 && current_field->level != 77) {
		cb_error(_("BASED only allowed at 01/77 level"));
	} else if(!qualifier) {
		cb_error(_("BASED requires a data name"));
	} else if(current_field->flag_external) {
		cb_error(_("BASED and EXTERNAL are mutually exclusive"));
	} else if(current_field->redefines) {
		cb_error(_("BASED and REDEFINES are mutually exclusive"));
	} else if(current_field->flag_any_length) {
		cb_error(_("BASED and ANY LENGTH are mutually exclusive"));
	} else if(current_field->flag_occurs) {
		cb_error(_("BASED and OCCURS are mutually exclusive"));
	} else {
		current_field->flag_item_based = 1;
	}
  }
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 4204 "parser.y"
    {
	check_pic_repeated("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  }
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 4212 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 4213 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 4217 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 4218 "parser.y"
    { (yyval) = CB_BUILD_PAIR((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 4223 "parser.y"
    {
	if(current_field->level != 88) {
		cb_error(_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT((yyvsp[(4) - (4)]));
  }
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 4236 "parser.y"
    {
	check_pic_repeated("RENAMES", SYN_CLAUSE_13);
	if(cb_ref((yyvsp[(2) - (2)])) != cb_error_node) {
		if(CB_FIELD(cb_ref((yyvsp[(2) - (2)])))->level == 01 ||
		    CB_FIELD(cb_ref((yyvsp[(2) - (2)])))->level > 50) {
			cb_error(_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD(cb_ref((yyvsp[(2) - (2)])));
			current_field->pic = current_field->redefines->pic;
		}
	}
  }
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 4249 "parser.y"
    {
	check_pic_repeated("RENAMES", SYN_CLAUSE_13);
	if(cb_ref((yyvsp[(2) - (4)])) != cb_error_node && cb_ref((yyvsp[(4) - (4)])) != cb_error_node) {
		if(CB_FIELD(cb_ref((yyvsp[(2) - (4)])))->level == 01 ||
		    CB_FIELD(cb_ref((yyvsp[(2) - (4)])))->level > 50) {
			cb_error(_("RENAMES may not reference a level 01 or > 50"));
		} else if(CB_FIELD(cb_ref((yyvsp[(4) - (4)])))->level == 01 ||
		    CB_FIELD(cb_ref((yyvsp[(4) - (4)])))->level > 50) {
			cb_error(_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD(cb_ref((yyvsp[(2) - (4)])));
			current_field->rename_thru = CB_FIELD(cb_ref((yyvsp[(4) - (4)])));
		}
	}
  }
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 4270 "parser.y"
    {
	check_pic_repeated("ANY", SYN_CLAUSE_14);
	if(current_field->flag_item_based) {
		cb_error(_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  }
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 4279 "parser.y"
    {
	check_pic_repeated("ANY", SYN_CLAUSE_14);
	if(current_field->flag_item_based) {
		cb_error(_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
		current_field->flag_any_numeric = 1;
	}
  }
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 4294 "parser.y"
    {
	check_headers_present(COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if(current_program->nested_level) {
		cb_error(_("LOCAL-STORAGE not allowed in nested programs"));
	}
  }
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 4303 "parser.y"
    {
	if((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 4315 "parser.y"
    {
	check_headers_present(COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  }
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 4321 "parser.y"
    {
	if((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 4332 "parser.y"
    {
	cb_warning(_("REPORT SECTION not implemented"));
	current_storage = CB_STORAGE_REPORT;
	cb_clear_real_field();
  }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 4348 "parser.y"
    {
	if(CB_INVALID_TREE((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_report = CB_REPORT(cb_ref((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 4363 "parser.y"
    {
	yyerrok;
  }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 4370 "parser.y"
    {
	check_repeated("GLOBAL", SYN_CLAUSE_1);
	cb_error(_("GLOBAL is not allowed with RD"));
  }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 4375 "parser.y"
    {
	check_repeated("CODE", SYN_CLAUSE_2);
  }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 4386 "parser.y"
    {
	check_repeated("CONTROL", SYN_CLAUSE_3);
  }
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 4405 "parser.y"
    {
	check_repeated("PAGE", SYN_CLAUSE_4);
	if(!current_report->heading) {
		current_report->heading = 1;
	}
	if(!current_report->first_detail) {
		current_report->first_detail = current_report->heading;
	}
	if(!current_report->last_control) {
		if(current_report->last_detail) {
			current_report->last_control = current_report->last_detail;
		} else if(current_report->footing) {
			current_report->last_control = current_report->footing;
		} else {
			current_report->last_control = current_report->lines;
		}
	}
	if(!current_report->last_detail && !current_report->footing) {
		current_report->last_detail = current_report->lines;
		current_report->footing = current_report->lines;
	} else if(!current_report->last_detail) {
		current_report->last_detail = current_report->footing;
	} else if(!current_report->footing) {
		current_report->footing = current_report->last_detail;
	}
	if(current_report->heading > current_report->first_detail ||
	    current_report->first_detail > current_report->last_control ||
	    current_report->last_control > current_report->last_detail ||
	    current_report->last_detail > current_report->footing) {
		cb_error(_("Invalid PAGE clause"));
	}
  }
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 4441 "parser.y"
    {
	current_report->lines = cb_get_int((yyvsp[(1) - (1)]));
  }
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 4445 "parser.y"
    {
	current_report->lines = cb_get_int((yyvsp[(1) - (4)]));
	current_report->columns = cb_get_int((yyvsp[(3) - (4)]));
  }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 4450 "parser.y"
    {
	current_report->lines = cb_get_int((yyvsp[(1) - (2)]));
  }
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 4470 "parser.y"
    {
	current_report->heading = cb_get_int((yyvsp[(3) - (3)]));
  }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 4477 "parser.y"
    {
	current_report->first_detail = cb_get_int((yyvsp[(4) - (4)]));
  }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 4484 "parser.y"
    {
	current_report->last_control = cb_get_int((yyvsp[(4) - (4)]));
  }
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 4491 "parser.y"
    {
	current_report->last_detail = cb_get_int((yyvsp[(4) - (4)]));
  }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 4498 "parser.y"
    {
	current_report->footing = cb_get_int((yyvsp[(3) - (3)]));
  }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 4509 "parser.y"
    {
	check_pic_duplicate = 0;
  }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 4540 "parser.y"
    {
	check_pic_repeated("TYPE", SYN_CLAUSE_16);
  }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 4566 "parser.y"
    {
	check_pic_repeated("NEXT GROUP", SYN_CLAUSE_17);
  }
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 4573 "parser.y"
    {
	check_pic_repeated("SUM", SYN_CLAUSE_19);
  }
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 4589 "parser.y"
    {
	check_pic_repeated("PRESENT", SYN_CLAUSE_20);
  }
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 4600 "parser.y"
    {
	check_pic_repeated("LINE", SYN_CLAUSE_21);
  }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 4612 "parser.y"
    {
	check_pic_repeated("COLUMN", SYN_CLAUSE_18);
  }
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 4645 "parser.y"
    {
	check_pic_repeated("SOURCE", SYN_CLAUSE_22);
  }
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 4652 "parser.y"
    {
	check_pic_repeated("GROUP", SYN_CLAUSE_23);
  }
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 4659 "parser.y"
    {
	check_pic_repeated("USAGE", SYN_CLAUSE_24);
  }
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 4668 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field();
  }
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 4675 "parser.y"
    {
	if(description_field) {
		for(cb_field * p = description_field; p; p = p->sister) {
			cb_validate_field(p);
		}
		current_program->screen_storage = description_field;
		current_program->flag_screen = 1;
	}
  }
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 4699 "parser.y"
    {
	cb_tree x = cb_build_field_tree((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage, current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free((yyvsp[(1) - (2)]));
	check_pic_duplicate = 0;
	if(CB_INVALID_TREE(x)) {
		YYERROR;
	}

	current_field = CB_FIELD(x);
	if(current_field->parent) {
		int flags = current_field->parent->screen_flag;
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
#line 4726 "parser.y"
    {
	if(!qualifier &&(current_field->level == 88 ||
	    current_field->level == 66 ||
	    current_field->flag_item_78)) {
		cb_error(_("Item requires a data name"));
	}
	if(current_field->screen_flag & COB_SCREEN_INITIAL) {
		if(!(current_field->screen_flag & COB_SCREEN_INPUT)) {
			cb_error(_("INITIAL specified on non-input field"));
		}
	}
	if(!qualifier) {
		current_field->flag_filler = 1;
	}
	if(current_field->level == 88) {
		cb_validate_88_item(current_field);
	}
	if(current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item(current_field, 0);
	}
	if(!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 4752 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot();
	check_pic_duplicate = 0;
	check_duplicate = 0;
#if	1	/* RXWRXW Screen field */
	if(current_field) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
	}
#endif
	current_field = cb_get_real_field();
  }
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 4775 "parser.y"
    {
	check_screen_attr("BLANK LINE", COB_SCREEN_BLANK_LINE);
  }
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 4779 "parser.y"
    {
	check_screen_attr("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 4783 "parser.y"
    {
	check_screen_attr("BELL", COB_SCREEN_BELL);
  }
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 4787 "parser.y"
    {
	check_screen_attr("BLINK", COB_SCREEN_BLINK);
  }
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 4791 "parser.y"
    {
	check_screen_attr("ERASE EOL", COB_SCREEN_ERASE_EOL);
  }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 4795 "parser.y"
    {
	check_screen_attr("ERASE EOS", COB_SCREEN_ERASE_EOS);
  }
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 4799 "parser.y"
    {
	check_screen_attr("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 4803 "parser.y"
    {
	check_screen_attr("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  }
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 4807 "parser.y"
    {
	check_screen_attr("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  }
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 4811 "parser.y"
    {
	check_screen_attr("UNDERLINE", COB_SCREEN_UNDERLINE);
  }
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 4815 "parser.y"
    {
	check_screen_attr("OVERLINE", COB_SCREEN_OVERLINE);
  }
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 4819 "parser.y"
    {
	check_screen_attr("LEFTLINE", COB_SCREEN_LEFTLINE);
  }
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 4823 "parser.y"
    {
	check_screen_attr("AUTO", COB_SCREEN_AUTO);
  }
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 4827 "parser.y"
    {
	check_screen_attr("SECURE", COB_SCREEN_SECURE);
  }
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 4831 "parser.y"
    {
	check_screen_attr("REQUIRED", COB_SCREEN_REQUIRED);
  }
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 4835 "parser.y"
    {
	check_screen_attr("FULL", COB_SCREEN_FULL);
  }
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 4839 "parser.y"
    {
	check_screen_attr("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  }
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 4844 "parser.y"
    {
	check_screen_attr("PROMPT", COB_SCREEN_PROMPT);
  }
    break;

  case 619:

/* Line 1806 of yacc.c  */
#line 4848 "parser.y"
    {
	check_screen_attr("INITIAL", COB_SCREEN_INITIAL);
  }
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 4852 "parser.y"
    {
	check_pic_repeated("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 4857 "parser.y"
    {
	check_pic_repeated("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 4862 "parser.y"
    {
	check_pic_repeated("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 4867 "parser.y"
    {
	check_pic_repeated("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 4880 "parser.y"
    {
	check_pic_repeated("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 4887 "parser.y"
    {
	check_pic_repeated("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 4892 "parser.y"
    {
	check_pic_repeated("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 4911 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 4915 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 4919 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 4926 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 4930 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 4934 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 4942 "parser.y"
    {
	check_pic_repeated("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 4953 "parser.y"
    {
	cb_error(_("GLOBAL is not allowed with screen items"));
  }
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 4962 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	cb_set_system_names();
	header_check |= COBC_HD_PROCEDURE_DIVISION;
  }
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 4972 "parser.y"
    {
	if(current_program->flag_main && !current_program->flag_chained && (yyvsp[(3) - (7)])) {
		cb_error(_("Executable program requested but PROCEDURE/ENTRY has USING clause"));
	}
	/* Main entry point */
	emit_entry(current_program->program_id, 0, (yyvsp[(3) - (7)]));
	current_program->num_proc_params = cb_list_length((yyvsp[(3) - (7)]));
	if(current_program->source_name) {
		emit_entry(current_program->source_name, 1, (yyvsp[(3) - (7)]));
	}
  }
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 4984 "parser.y"
    {
	if(current_paragraph) {
		if(current_paragraph->exit_label) {
			emit_statement(current_paragraph->exit_label);
		}
		emit_statement(cb_build_perform_exit(current_paragraph));
	}
	if(current_section) {
		if(current_section->exit_label) {
			emit_statement(current_section->exit_label);
		}
		emit_statement(cb_build_perform_exit(current_section));
	}
  }
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 4999 "parser.y"
    {
	/* No PROCEDURE DIVISION header ! */
	/* Only a statement is allowed as first element */
	/* Thereafter, sections/paragraphs may be used */
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	cb_tree label = cb_build_reference("MAIN SECTION");
	current_section = CB_LABEL(cb_build_label(label, NULL));
	current_section->flag_section = 1;
	current_section->flag_dummy_section = 1;
	current_section->flag_skip_label = !!skip_statements;
	current_section->flag_declaratives = !!in_declaratives;
	current_section->source_file = cb_source_file;
	current_section->source_line = cb_source_line;
	emit_statement(current_section);
	label = cb_build_reference("MAIN PARAGRAPH");
	current_paragraph = CB_LABEL(cb_build_label(label, NULL));
	current_paragraph->flag_declaratives = !!in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_dummy_paragraph = 1;
	current_paragraph->source_file = cb_source_file;
	current_paragraph->source_line = cb_source_line;
	emit_statement(current_paragraph);
	cb_set_system_names();
  }
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 5030 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 5034 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_AUTO;
	//size_mode = (sizeof(void *) == 4) ? CB_SIZE_4 : CB_SIZE_8;
  }
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 5040 "parser.y"
    {
	if(cb_list_length((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error(_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 5048 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  }
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 5057 "parser.y"
    {
	if(cb_list_length((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error(_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 5067 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 5069 "parser.y"
    { (yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 5074 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR(cb_int(call_mode), cb_build_identifier((yyvsp[(4) - (4)]), 0));
	CB_SIZES((yyval)) = size_mode;
  }
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 5083 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 5087 "parser.y"
    {
	if(current_program->flag_chained) {
		cb_error(_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 5099 "parser.y"
    {
	if(call_mode != CB_CALL_BY_VALUE) {
		cb_error(_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 5107 "parser.y"
    {
	if(call_mode != CB_CALL_BY_VALUE) {
		cb_error(_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = (sizeof(void *) == 4) ? CB_SIZE_4 : CB_SIZE_8;
	}
  }
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 5115 "parser.y"
    {
	if(call_mode != CB_CALL_BY_VALUE) {
		cb_error(_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  }
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 5123 "parser.y"
    {
	unsigned char * s = CB_LITERAL((yyvsp[(4) - (4)]))->data;

	if(call_mode != CB_CALL_BY_VALUE) {
		cb_error(_("SIZE only allowed for BY VALUE items"));
	} else if(CB_LITERAL((yyvsp[(4) - (4)]))->size != 1) {
		cb_error_x((yyvsp[(4) - (4)]), _("Invalid value for SIZE"));
	} else {
		size_mode = CB_SIZE_UNSIGNED;
		switch(*s) {
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
			cb_error_x((yyvsp[(4) - (4)]), _("Invalid value for SIZE"));
			break;
		}
	}
  }
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 5152 "parser.y"
    {
	unsigned char * s = CB_LITERAL((yyvsp[(3) - (3)]))->data;

	if(call_mode != CB_CALL_BY_VALUE) {
		cb_error(_("SIZE only allowed for BY VALUE items"));
	} else if(CB_LITERAL((yyvsp[(3) - (3)]))->size != 1) {
		cb_error_x((yyvsp[(3) - (3)]), _("Invalid value for SIZE"));
	} else {
		size_mode = 0;
		switch(*s) {
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
			cb_error_x((yyvsp[(3) - (3)]), _("Invalid value for SIZE"));
			break;
		}
	}
  }
    break;

  case 671:

/* Line 1806 of yacc.c  */
#line 5185 "parser.y"
    {
	if(call_mode != CB_CALL_BY_REFERENCE) {
		cb_error(_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 5194 "parser.y"
    {
	if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 5200 "parser.y"
    {
	if(cb_ref((yyvsp[(2) - (2)])) != cb_error_node) {
		cb_field * f = CB_FIELD_PTR((yyvsp[(2) - (2)]));
		if(f->level != 1 && f->level != 77) {
			cb_error(_("RETURNING item must have level 01"));
		} else if(f->occurs_max > 1) {
			cb_error(_("RETURNING item should not have OCCURS"));
		} else if(f->storage == CB_STORAGE_LOCAL) {
			cb_error (_("RETURNING item should not be in LOCAL-STORAGE"));
		} else {
			f->flag_is_returning = 1;
			current_program->returning = (yyvsp[(2) - (2)]);
		}
	}
  }
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 5219 "parser.y"
    {
	in_declaratives = 1;
	emit_statement(cb_build_comment("DECLARATIVES"));
  }
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 5225 "parser.y"
    {
	if(needs_field_debug) {
		start_debug = 1;
	}
	in_declaratives = 0;
	in_debugging = 0;
	if(current_paragraph) {
		if(current_paragraph->exit_label) {
			emit_statement(current_paragraph->exit_label);
		}
		emit_statement(cb_build_perform_exit(current_paragraph));
		current_paragraph = NULL;
	}
	if(current_section) {
		if(current_section->exit_label) {
			emit_statement(current_section->exit_label);
		}
		current_section->flag_fatal_check = 1;
		emit_statement(cb_build_perform_exit(current_section));
		current_section = NULL;
	}
	skip_statements = 0;
	emit_statement(cb_build_comment("END DECLARATIVES"));
  }
    break;

  case 681:

/* Line 1806 of yacc.c  */
#line 5262 "parser.y"
    {
	if(next_label_list) {
		char	name[32];
		snprintf(name, sizeof(name), "L$%d", next_label_id);
		cb_tree plabel = cb_build_label(cb_build_reference(name), NULL);
		CB_LABEL(plabel)->flag_next_sentence = 1;
		emit_statement(plabel);
		current_program->label_list =
			cb_list_append(current_program->label_list, next_label_list);
		next_label_list = NULL;
		next_label_id++;
	}
	/* check_unreached = 0; */
  }
    break;

  case 683:

/* Line 1806 of yacc.c  */
#line 5278 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 684:

/* Line 1806 of yacc.c  */
#line 5288 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if(cb_build_section_name((yyvsp[(1) - (4)]), 0) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph/section */
	if(current_paragraph) {
		if(current_paragraph->exit_label) {
			emit_statement(current_paragraph->exit_label);
		}
		emit_statement(cb_build_perform_exit(current_paragraph));
	}
	if(current_section) {
		if(current_section->exit_label) {
			emit_statement(current_section->exit_label);
		}
		emit_statement(cb_build_perform_exit(current_section));
	}
	if(current_program->flag_debugging && !in_debugging) {
		if(current_paragraph || current_section) {
			emit_statement(cb_build_comment(
					"DEBUGGING - Fall through"));
			emit_statement(cb_build_debug(cb_debug_contents,
					"FALL THROUGH", NULL));
		}
	}

	/* Begin a new section */
	current_section = CB_LABEL(cb_build_label((yyvsp[(1) - (4)]), NULL));
	if((yyvsp[(3) - (4)])) {
		current_section->segment = cb_get_int((yyvsp[(3) - (4)]));
	}
	current_section->flag_section = 1;
	/* Careful here, one negation */
	current_section->flag_real_label = !in_debugging;
	current_section->flag_declaratives = !!in_declaratives;
	current_section->flag_skip_label = !!skip_statements;
	current_section->source_file = cb_source_file;
	current_section->source_line = cb_source_line;
	current_paragraph = NULL;
  }
    break;

  case 685:

/* Line 1806 of yacc.c  */
#line 5332 "parser.y"
    {
	emit_statement(current_section);
  }
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 5343 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if(cb_build_section_name((yyvsp[(1) - (2)]), 1) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph */
	if(current_paragraph) {
		if(current_paragraph->exit_label) {
			emit_statement(current_paragraph->exit_label);
		}
		emit_statement(cb_build_perform_exit(current_paragraph));
		if(current_program->flag_debugging && !in_debugging) {
			emit_statement(cb_build_comment(
					"DEBUGGING - Fall through"));
			emit_statement(cb_build_debug(cb_debug_contents,
					"FALL THROUGH", NULL));
		}
	}

	/* Begin a new paragraph */
	if(!current_section) {
		cb_tree label = cb_build_reference("MAIN SECTION");
		current_section = CB_LABEL(cb_build_label(label, NULL));
		current_section->flag_section = 1;
		current_section->flag_dummy_section = 1;
		current_section->flag_declaratives = !!in_declaratives;
		current_section->flag_skip_label = !!skip_statements;
		current_section->source_file = cb_source_file;
		current_section->source_line = cb_source_line;
		emit_statement(current_section);
	}
	current_paragraph = CB_LABEL(cb_build_label((yyvsp[(1) - (2)]), current_section));
	current_paragraph->flag_declaratives =!! in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_real_label = !in_debugging;
	current_paragraph->segment = current_section->segment;
	current_paragraph->source_file = cb_source_file;
	current_paragraph->source_line = cb_source_line;
	emit_statement(current_paragraph);
  }
    break;

  case 689:

/* Line 1806 of yacc.c  */
#line 5389 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if(cb_build_section_name((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 690:

/* Line 1806 of yacc.c  */
#line 5401 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 691:

/* Line 1806 of yacc.c  */
#line 5405 "parser.y"
    {
	if(in_declaratives) {
		cb_error(_("SECTION segment invalid within DECLARATIVE"));
	}
	if(cb_verify(cb_section_segments, "SECTION segment")) {
		current_program->flag_segments = 1;
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 692:

/* Line 1806 of yacc.c  */
#line 5423 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  }
    break;

  case 693:

/* Line 1806 of yacc.c  */
#line 5428 "parser.y"
    {
	(yyval) = current_statement;
	current_statement = NULL;
  }
    break;

  case 694:

/* Line 1806 of yacc.c  */
#line 5433 "parser.y"
    {
	(yyval) = cb_list_reverse(current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT((yyvsp[(2) - (3)]));
  }
    break;

  case 695:

/* Line 1806 of yacc.c  */
#line 5441 "parser.y"
    {
	if(!current_section) {
		cb_tree label = cb_build_reference("MAIN SECTION");
		current_section = CB_LABEL(cb_build_label(label, NULL));
		current_section->flag_section = 1;
		current_section->flag_dummy_section = 1;
		current_section->flag_skip_label = !!skip_statements;
		current_section->flag_declaratives = !!in_declaratives;
		current_section->source_file = cb_source_file;
		current_section->source_line = cb_source_line;
		emit_statement(current_section);
	}
	if(!current_paragraph) {
		cb_tree label = cb_build_reference("MAIN PARAGRAPH");
		current_paragraph = CB_LABEL(cb_build_label(label, NULL));
		current_paragraph->flag_declaratives = !!in_declaratives;
		current_paragraph->flag_skip_label = !!skip_statements;
		current_paragraph->flag_dummy_paragraph = 1;
		current_paragraph->source_file = cb_source_file;
		current_paragraph->source_line = cb_source_line;
		emit_statement(current_paragraph);
	}
	check_headers_present(COBC_HD_PROCEDURE_DIVISION, 0, 0, 0);
  }
    break;

  case 696:

/* Line 1806 of yacc.c  */
#line 5466 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 697:

/* Line 1806 of yacc.c  */
#line 5470 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 747:

/* Line 1806 of yacc.c  */
#line 5526 "parser.y"
    {
	if(cb_verify(cb_next_sentence_phrase, "NEXT SENTENCE")) {
		begin_statement("NEXT SENTENCE", 0);
		char name[32];
		sprintf(name, "L$%d", next_label_id);
		cb_tree label = cb_build_reference(name);
		next_label_list = cb_list_add(next_label_list, label);
		emit_statement(cb_build_goto(label, NULL));
	}
	check_unreached = 0;
  }
    break;

  case 748:

/* Line 1806 of yacc.c  */
#line 5538 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  }
    break;

  case 749:

/* Line 1806 of yacc.c  */
#line 5549 "parser.y"
    {
	begin_statement("ACCEPT", TERM_ACCEPT);
  }
    break;

  case 751:

/* Line 1806 of yacc.c  */
#line 5559 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  }
    break;

  case 752:

/* Line 1806 of yacc.c  */
#line 5564 "parser.y"
    {
	cb_emit_accept_line_or_col((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 753:

/* Line 1806 of yacc.c  */
#line 5568 "parser.y"
    {
	cb_emit_accept_line_or_col((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 754:

/* Line 1806 of yacc.c  */
#line 5572 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd((yyvsp[(1) - (4)]));
  }
    break;

  case 755:

/* Line 1806 of yacc.c  */
#line 5577 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date((yyvsp[(1) - (3)]));
  }
    break;

  case 756:

/* Line 1806 of yacc.c  */
#line 5582 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd((yyvsp[(1) - (4)]));
  }
    break;

  case 757:

/* Line 1806 of yacc.c  */
#line 5587 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day((yyvsp[(1) - (3)]));
  }
    break;

  case 758:

/* Line 1806 of yacc.c  */
#line 5592 "parser.y"
    {
	cb_emit_accept_day_of_week((yyvsp[(1) - (3)]));
  }
    break;

  case 759:

/* Line 1806 of yacc.c  */
#line 5596 "parser.y"
    {
	cb_emit_accept_escape_key((yyvsp[(1) - (4)]));
  }
    break;

  case 760:

/* Line 1806 of yacc.c  */
#line 5600 "parser.y"
    {
	cb_emit_accept_exception_status((yyvsp[(1) - (4)]));
  }
    break;

  case 761:

/* Line 1806 of yacc.c  */
#line 5604 "parser.y"
    {
	cb_emit_accept_time((yyvsp[(1) - (3)]));
  }
    break;

  case 762:

/* Line 1806 of yacc.c  */
#line 5608 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name((yyvsp[(1) - (4)]));
  }
    break;

  case 763:

/* Line 1806 of yacc.c  */
#line 5613 "parser.y"
    {
	cb_emit_accept_command_line((yyvsp[(1) - (3)]));
  }
    break;

  case 764:

/* Line 1806 of yacc.c  */
#line 5617 "parser.y"
    {
	cb_emit_accept_environment((yyvsp[(1) - (4)]));
  }
    break;

  case 765:

/* Line 1806 of yacc.c  */
#line 5621 "parser.y"
    {
	cb_emit_get_environment((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 766:

/* Line 1806 of yacc.c  */
#line 5625 "parser.y"
    {
	cb_emit_accept_arg_number((yyvsp[(1) - (3)]));
  }
    break;

  case 767:

/* Line 1806 of yacc.c  */
#line 5629 "parser.y"
    {
	cb_emit_accept_arg_value((yyvsp[(1) - (4)]));
  }
    break;

  case 768:

/* Line 1806 of yacc.c  */
#line 5633 "parser.y"
    {
	cb_emit_accept_mnemonic((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 769:

/* Line 1806 of yacc.c  */
#line 5637 "parser.y"
    {
	cb_emit_accept_name((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 771:

/* Line 1806 of yacc.c  */
#line 5645 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 774:

/* Line 1806 of yacc.c  */
#line 5656 "parser.y"
    { (yyval) = NULL; }
    break;

  case 775:

/* Line 1806 of yacc.c  */
#line 5657 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 776:

/* Line 1806 of yacc.c  */
#line 5661 "parser.y"
    { (yyval) = CB_BUILD_PAIR((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 777:

/* Line 1806 of yacc.c  */
#line 5662 "parser.y"
    { (yyval) = CB_BUILD_PAIR((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 778:

/* Line 1806 of yacc.c  */
#line 5663 "parser.y"
    { (yyval) = CB_BUILD_PAIR((yyvsp[(2) - (2)]), cb_int0); }
    break;

  case 779:

/* Line 1806 of yacc.c  */
#line 5664 "parser.y"
    { (yyval) = CB_BUILD_PAIR(cb_int0, (yyvsp[(2) - (2)])); }
    break;

  case 780:

/* Line 1806 of yacc.c  */
#line 5665 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 781:

/* Line 1806 of yacc.c  */
#line 5669 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 782:

/* Line 1806 of yacc.c  */
#line 5673 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 783:

/* Line 1806 of yacc.c  */
#line 5674 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 787:

/* Line 1806 of yacc.c  */
#line 5683 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 792:

/* Line 1806 of yacc.c  */
#line 5699 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  }
    break;

  case 793:

/* Line 1806 of yacc.c  */
#line 5703 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 794:

/* Line 1806 of yacc.c  */
#line 5707 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 795:

/* Line 1806 of yacc.c  */
#line 5711 "parser.y"
    {
	cb_warning(_("Ignoring CONVERSION"));
  }
    break;

  case 796:

/* Line 1806 of yacc.c  */
#line 5715 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  }
    break;

  case 797:

/* Line 1806 of yacc.c  */
#line 5719 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 798:

/* Line 1806 of yacc.c  */
#line 5723 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  }
    break;

  case 799:

/* Line 1806 of yacc.c  */
#line 5727 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  }
    break;

  case 800:

/* Line 1806 of yacc.c  */
#line 5731 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 801:

/* Line 1806 of yacc.c  */
#line 5735 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  }
    break;

  case 802:

/* Line 1806 of yacc.c  */
#line 5739 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 803:

/* Line 1806 of yacc.c  */
#line 5743 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  }
    break;

  case 804:

/* Line 1806 of yacc.c  */
#line 5747 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  }
    break;

  case 805:

/* Line 1806 of yacc.c  */
#line 5751 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  }
    break;

  case 806:

/* Line 1806 of yacc.c  */
#line 5755 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 807:

/* Line 1806 of yacc.c  */
#line 5759 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  }
    break;

  case 808:

/* Line 1806 of yacc.c  */
#line 5763 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 809:

/* Line 1806 of yacc.c  */
#line 5767 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  }
    break;

  case 810:

/* Line 1806 of yacc.c  */
#line 5771 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  }
    break;

  case 811:

/* Line 1806 of yacc.c  */
#line 5775 "parser.y"
    {
	check_attribs((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 812:

/* Line 1806 of yacc.c  */
#line 5779 "parser.y"
    {
	check_attribs(NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 813:

/* Line 1806 of yacc.c  */
#line 5783 "parser.y"
    {
	check_attribs(NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 814:

/* Line 1806 of yacc.c  */
#line 5787 "parser.y"
    {
	check_attribs(NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 815:

/* Line 1806 of yacc.c  */
#line 5791 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  }
    break;

  case 816:

/* Line 1806 of yacc.c  */
#line 5798 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), ACCEPT);
  }
    break;

  case 817:

/* Line 1806 of yacc.c  */
#line 5802 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), ACCEPT);
  }
    break;

  case 818:

/* Line 1806 of yacc.c  */
#line 5812 "parser.y"
    {
	begin_statement("ADD", TERM_ADD);
  }
    break;

  case 820:

/* Line 1806 of yacc.c  */
#line 5821 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(3) - (4)]), '+', cb_build_binary_list((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 821:

/* Line 1806 of yacc.c  */
#line 5825 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(4) - (5)]), 0, cb_build_binary_list((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 822:

/* Line 1806 of yacc.c  */
#line 5829 "parser.y"
    {
	cb_emit_corresponding(cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 824:

/* Line 1806 of yacc.c  */
#line 5836 "parser.y"
    {
	cb_list_add((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 825:

/* Line 1806 of yacc.c  */
#line 5843 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), ADD);
  }
    break;

  case 826:

/* Line 1806 of yacc.c  */
#line 5847 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), ADD);
  }
    break;

  case 827:

/* Line 1806 of yacc.c  */
#line 5857 "parser.y"
    {
	begin_statement("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  }
    break;

  case 829:

/* Line 1806 of yacc.c  */
#line 5866 "parser.y"
    {
	cb_emit_allocate((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 830:

/* Line 1806 of yacc.c  */
#line 5870 "parser.y"
    {
	if((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x(current_statement,
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate(NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 831:

/* Line 1806 of yacc.c  */
#line 5881 "parser.y"
    { (yyval) = NULL; }
    break;

  case 832:

/* Line 1806 of yacc.c  */
#line 5882 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 833:

/* Line 1806 of yacc.c  */
#line 5890 "parser.y"
    {
	begin_statement("ALTER", 0);
	cb_verify(cb_alter_statement, "ALTER statement");
  }
    break;

  case 837:

/* Line 1806 of yacc.c  */
#line 5904 "parser.y"
    {
	cb_emit_alter((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 840:

/* Line 1806 of yacc.c  */
#line 5916 "parser.y"
    {
	begin_statement("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  }
    break;

  case 842:

/* Line 1806 of yacc.c  */
#line 5931 "parser.y"
    {
	if(CB_LITERAL_P((yyvsp[(2) - (6)])) &&
	    current_program->prog_type == CB_PROGRAM_TYPE &&
	    !current_program->flag_recursive &&
	    !strcmp((const char *)(CB_LITERAL((yyvsp[(2) - (6)]))->data), current_program->orig_program_id))
	{
		cb_warning_x((yyvsp[(2) - (6)]), _("Recursive program call - assuming RECURSIVE attribute"));
		current_program->flag_recursive = 1;
	}
	cb_emit_call((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]), (yyvsp[(1) - (6)]));
  }
    break;

  case 843:

/* Line 1806 of yacc.c  */
#line 5946 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 844:

/* Line 1806 of yacc.c  */
#line 5951 "parser.y"
    {
	(yyval) = cb_int(CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  }
    break;

  case 845:

/* Line 1806 of yacc.c  */
#line 5956 "parser.y"
    {
	(yyval) = cb_int(CB_CONV_STDCALL);
	cobc_cs_check = 0;
  }
    break;

  case 846:

/* Line 1806 of yacc.c  */
#line 5961 "parser.y"
    {
	cb_tree x = cb_ref((yyvsp[(1) - (1)]));
	if(CB_VALID_TREE(x)) {
		if(CB_SYSTEM_NAME(x)->token != CB_FEATURE_CONVENTION) {
			cb_error_x((yyvsp[(1) - (1)]), _("Invalid mnemonic name"));
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
#line 5979 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 848:

/* Line 1806 of yacc.c  */
#line 5983 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_AUTO;
	//size_mode = (sizeof(void *) == 4) ? CB_SIZE_4 : CB_SIZE_8;
  }
    break;

  case 849:

/* Line 1806 of yacc.c  */
#line 5989 "parser.y"
    {
	if(cb_list_length((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x(current_statement,
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 850:

/* Line 1806 of yacc.c  */
#line 6000 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 851:

/* Line 1806 of yacc.c  */
#line 6002 "parser.y"
    { (yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 852:

/* Line 1806 of yacc.c  */
#line 6007 "parser.y"
    {
	if(call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x(current_statement,
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR(cb_int(call_mode), cb_null);
  }
    break;

  case 853:

/* Line 1806 of yacc.c  */
#line 6015 "parser.y"
    {
	int	save_mode = call_mode;
	if(call_mode != CB_CALL_BY_REFERENCE) {
		if(CB_FILE_P((yyvsp[(3) - (3)])) ||(CB_REFERENCE_P((yyvsp[(3) - (3)])) &&
		    CB_FILE_P(CB_REFERENCE((yyvsp[(3) - (3)]))->value))) {
			cb_error_x(current_statement,
				    _("Invalid file name reference"));
		} else if(call_mode == CB_CALL_BY_VALUE) {
			if(cb_category_is_alpha((yyvsp[(3) - (3)]))) {
				cb_warning_x((yyvsp[(3) - (3)]),
					      _("BY CONTENT assumed for alphanumeric item"));
				save_mode = CB_CALL_BY_CONTENT;
			}
		}
	}
	(yyval) = CB_BUILD_PAIR(cb_int(save_mode), (yyvsp[(3) - (3)]));
	CB_SIZES((yyval)) = size_mode;
	call_mode = save_mode;
  }
    break;

  case 855:

/* Line 1806 of yacc.c  */
#line 6039 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 856:

/* Line 1806 of yacc.c  */
#line 6043 "parser.y"
    {
	if(current_program->flag_chained) {
		cb_error_x(current_statement,
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 857:

/* Line 1806 of yacc.c  */
#line 6052 "parser.y"
    {
	if(current_program->flag_chained) {
		cb_error_x(current_statement,
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 858:

/* Line 1806 of yacc.c  */
#line 6064 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 859:

/* Line 1806 of yacc.c  */
#line 6068 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 860:

/* Line 1806 of yacc.c  */
#line 6072 "parser.y"
    {
	(yyval) = cb_null;
  }
    break;

  case 861:

/* Line 1806 of yacc.c  */
#line 6076 "parser.y"
    {
	if(cb_ref((yyvsp[(4) - (4)])) != cb_error_node) {
		cb_field * f = CB_FIELD_PTR((yyvsp[(4) - (4)]));
		if(f->level != 1 && f->level != 77) {
			cb_error(_("RETURNING item must have level 01 or 77"));
			(yyval) = NULL;
		} else if(f->storage != CB_STORAGE_LINKAGE &&
			   !f->flag_item_based) {
			cb_error(_("RETURNING item is neither in LINKAGE SECTION nor is it BASED"));
			(yyval) = NULL;
		} else {
			(yyval) = cb_build_address((yyvsp[(4) - (4)]));
		}
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 866:

/* Line 1806 of yacc.c  */
#line 6107 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 867:

/* Line 1806 of yacc.c  */
#line 6112 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 868:

/* Line 1806 of yacc.c  */
#line 6119 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 869:

/* Line 1806 of yacc.c  */
#line 6124 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 870:

/* Line 1806 of yacc.c  */
#line 6131 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), CALL);
  }
    break;

  case 871:

/* Line 1806 of yacc.c  */
#line 6135 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), CALL);
  }
    break;

  case 872:

/* Line 1806 of yacc.c  */
#line 6145 "parser.y"
    {
	begin_statement("CANCEL", 0);
  }
    break;

  case 874:

/* Line 1806 of yacc.c  */
#line 6153 "parser.y"
    {
	cb_emit_cancel((yyvsp[(1) - (1)]));
  }
    break;

  case 875:

/* Line 1806 of yacc.c  */
#line 6157 "parser.y"
    {
	cb_emit_cancel((yyvsp[(2) - (2)]));
  }
    break;

  case 876:

/* Line 1806 of yacc.c  */
#line 6167 "parser.y"
    {
	begin_statement("CLOSE", 0);
  }
    break;

  case 878:

/* Line 1806 of yacc.c  */
#line 6175 "parser.y"
    {
	begin_implicit_statement();
	cb_emit_close((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 879:

/* Line 1806 of yacc.c  */
#line 6180 "parser.y"
    {
	begin_implicit_statement();
	cb_emit_close((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 880:

/* Line 1806 of yacc.c  */
#line 6187 "parser.y"
    { (yyval) = cb_int(COB_CLOSE_NORMAL); }
    break;

  case 881:

/* Line 1806 of yacc.c  */
#line 6188 "parser.y"
    { (yyval) = cb_int(COB_CLOSE_UNIT); }
    break;

  case 882:

/* Line 1806 of yacc.c  */
#line 6189 "parser.y"
    { (yyval) = cb_int(COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 883:

/* Line 1806 of yacc.c  */
#line 6190 "parser.y"
    { (yyval) = cb_int(COB_CLOSE_NO_REWIND); }
    break;

  case 884:

/* Line 1806 of yacc.c  */
#line 6191 "parser.y"
    { (yyval) = cb_int(COB_CLOSE_LOCK); }
    break;

  case 885:

/* Line 1806 of yacc.c  */
#line 6199 "parser.y"
    {
	begin_statement("COMPUTE", TERM_COMPUTE);
  }
    break;

  case 887:

/* Line 1806 of yacc.c  */
#line 6208 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 888:

/* Line 1806 of yacc.c  */
#line 6215 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), COMPUTE);
  }
    break;

  case 889:

/* Line 1806 of yacc.c  */
#line 6219 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), COMPUTE);
  }
    break;

  case 890:

/* Line 1806 of yacc.c  */
#line 6229 "parser.y"
    {
	begin_statement("COMMIT", 0);
	cb_emit_commit();
  }
    break;

  case 891:

/* Line 1806 of yacc.c  */
#line 6240 "parser.y"
    {
	size_t	save_unreached;

	/* Do not check unreached for CONTINUE */
	save_unreached = check_unreached;
	check_unreached = 0;
	begin_statement("CONTINUE", 0);
	cb_emit_continue();
	check_unreached = (unsigned int) save_unreached;
  }
    break;

  case 892:

/* Line 1806 of yacc.c  */
#line 6257 "parser.y"
    {
	begin_statement("DELETE", TERM_DELETE);
  }
    break;

  case 894:

/* Line 1806 of yacc.c  */
#line 6266 "parser.y"
    {
	cb_emit_delete((yyvsp[(1) - (3)]));
  }
    break;

  case 896:

/* Line 1806 of yacc.c  */
#line 6274 "parser.y"
    {
	begin_implicit_statement();
	cb_emit_delete_file((yyvsp[(1) - (1)]));
  }
    break;

  case 897:

/* Line 1806 of yacc.c  */
#line 6279 "parser.y"
    {
	begin_implicit_statement();
	cb_emit_delete_file((yyvsp[(2) - (2)]));
  }
    break;

  case 898:

/* Line 1806 of yacc.c  */
#line 6287 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), DELETE);
  }
    break;

  case 899:

/* Line 1806 of yacc.c  */
#line 6291 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), DELETE);
  }
    break;

  case 900:

/* Line 1806 of yacc.c  */
#line 6301 "parser.y"
    {
	begin_statement("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  }
    break;

  case 902:

/* Line 1806 of yacc.c  */
#line 6311 "parser.y"
    {
	cb_emit_env_name((yyvsp[(1) - (3)]));
  }
    break;

  case 903:

/* Line 1806 of yacc.c  */
#line 6315 "parser.y"
    {
	cb_emit_env_value((yyvsp[(1) - (3)]));
  }
    break;

  case 904:

/* Line 1806 of yacc.c  */
#line 6319 "parser.y"
    {
	cb_emit_arg_number((yyvsp[(1) - (3)]));
  }
    break;

  case 905:

/* Line 1806 of yacc.c  */
#line 6323 "parser.y"
    {
	cb_emit_command_line((yyvsp[(1) - (3)]));
  }
    break;

  case 906:

/* Line 1806 of yacc.c  */
#line 6327 "parser.y"
    {
	cb_emit_display((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  }
    break;

  case 908:

/* Line 1806 of yacc.c  */
#line 6332 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display(CB_LIST_INIT((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  }
    break;

  case 910:

/* Line 1806 of yacc.c  */
#line 6342 "parser.y"
    {
	begin_implicit_statement();
  }
    break;

  case 912:

/* Line 1806 of yacc.c  */
#line 6350 "parser.y"
    {
	cb_emit_display(CB_LIST_INIT((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  }
    break;

  case 913:

/* Line 1806 of yacc.c  */
#line 6358 "parser.y"
    {
	if(current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 914:

/* Line 1806 of yacc.c  */
#line 6366 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic((yyvsp[(2) - (2)]));
  }
    break;

  case 915:

/* Line 1806 of yacc.c  */
#line 6370 "parser.y"
    {
	(yyval) = cb_build_display_name((yyvsp[(2) - (2)]));
  }
    break;

  case 916:

/* Line 1806 of yacc.c  */
#line 6374 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 917:

/* Line 1806 of yacc.c  */
#line 6378 "parser.y"
    {
	if(current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 923:

/* Line 1806 of yacc.c  */
#line 6400 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 924:

/* Line 1806 of yacc.c  */
#line 6406 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 925:

/* Line 1806 of yacc.c  */
#line 6407 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 928:

/* Line 1806 of yacc.c  */
#line 6418 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  }
    break;

  case 929:

/* Line 1806 of yacc.c  */
#line 6422 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  }
    break;

  case 930:

/* Line 1806 of yacc.c  */
#line 6426 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  }
    break;

  case 931:

/* Line 1806 of yacc.c  */
#line 6430 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  }
    break;

  case 932:

/* Line 1806 of yacc.c  */
#line 6434 "parser.y"
    {
	cb_warning(_("Ignoring CONVERSION"));
  }
    break;

  case 933:

/* Line 1806 of yacc.c  */
#line 6438 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  }
    break;

  case 934:

/* Line 1806 of yacc.c  */
#line 6442 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  }
    break;

  case 935:

/* Line 1806 of yacc.c  */
#line 6446 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 936:

/* Line 1806 of yacc.c  */
#line 6450 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  }
    break;

  case 937:

/* Line 1806 of yacc.c  */
#line 6454 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  }
    break;

  case 938:

/* Line 1806 of yacc.c  */
#line 6458 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  }
    break;

  case 939:

/* Line 1806 of yacc.c  */
#line 6462 "parser.y"
    {
	check_attribs(NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  }
    break;

  case 940:

/* Line 1806 of yacc.c  */
#line 6466 "parser.y"
    {
	check_attribs((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  }
    break;

  case 941:

/* Line 1806 of yacc.c  */
#line 6470 "parser.y"
    {
	check_attribs(NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  }
    break;

  case 942:

/* Line 1806 of yacc.c  */
#line 6474 "parser.y"
    {
	check_attribs(NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  }
    break;

  case 943:

/* Line 1806 of yacc.c  */
#line 6478 "parser.y"
    {
	check_attribs(NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  }
    break;

  case 944:

/* Line 1806 of yacc.c  */
#line 6485 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), DISPLAY);
  }
    break;

  case 945:

/* Line 1806 of yacc.c  */
#line 6489 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), DISPLAY);
  }
    break;

  case 946:

/* Line 1806 of yacc.c  */
#line 6499 "parser.y"
    {
	begin_statement("DIVIDE", TERM_DIVIDE);
  }
    break;

  case 948:

/* Line 1806 of yacc.c  */
#line 6508 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 949:

/* Line 1806 of yacc.c  */
#line 6512 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(5) - (6)]), 0, cb_build_binary_op((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 950:

/* Line 1806 of yacc.c  */
#line 6516 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(5) - (6)]), 0, cb_build_binary_op((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 951:

/* Line 1806 of yacc.c  */
#line 6520 "parser.y"
    {
	cb_emit_divide((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 952:

/* Line 1806 of yacc.c  */
#line 6524 "parser.y"
    {
	cb_emit_divide((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 953:

/* Line 1806 of yacc.c  */
#line 6531 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), DIVIDE);
  }
    break;

  case 954:

/* Line 1806 of yacc.c  */
#line 6535 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), DIVIDE);
  }
    break;

  case 955:

/* Line 1806 of yacc.c  */
#line 6545 "parser.y"
    {
	begin_statement("ENTRY", 0);
  }
    break;

  case 957:

/* Line 1806 of yacc.c  */
#line 6553 "parser.y"
    {
	if(current_program->nested_level) {
		cb_error(_("ENTRY is invalid in nested program"));
	} else if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("ENTRY is invalid in a user FUNCTION"));
	} else if(cb_verify(cb_entry_statement, "ENTRY")) {
		if(!cobc_check_valid_name((char *)(CB_LITERAL((yyvsp[(1) - (2)]))->data), 1U)) {
			emit_entry((char *)(CB_LITERAL((yyvsp[(1) - (2)]))->data), 1, (yyvsp[(2) - (2)]));
		}
	}
	check_unreached = 0;
  }
    break;

  case 958:

/* Line 1806 of yacc.c  */
#line 6572 "parser.y"
    {
	begin_statement("EVALUATE", TERM_EVALUATE);
	eval_level++;
	if(eval_level >= EVAL_DEPTH) {
		cb_error(_("Maximum evaluate depth exceeded(%d)"),
			  EVAL_DEPTH);
		eval_level = 0;
		eval_inc = 0;
		eval_inc2 = 0;
		YYERROR;
	} else {
		for(eval_inc = 0; eval_inc < EVAL_DEPTH; ++eval_inc) {
			eval_check[eval_level][eval_inc] = NULL;
		}
		eval_inc = 0;
		eval_inc2 = 0;
	}
  }
    break;

  case 960:

/* Line 1806 of yacc.c  */
#line 6596 "parser.y"
    {
	cb_emit_evaluate((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  }
    break;

  case 961:

/* Line 1806 of yacc.c  */
#line 6603 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 962:

/* Line 1806 of yacc.c  */
#line 6605 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 963:

/* Line 1806 of yacc.c  */
#line 6610 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	eval_check[eval_level][eval_inc++] = (yyvsp[(1) - (1)]);
	if(eval_inc >= EVAL_DEPTH) {
		cb_error(_("Maximum evaluate depth exceeded(%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
    break;

  case 964:

/* Line 1806 of yacc.c  */
#line 6621 "parser.y"
    {
	(yyval) = cb_true;
	eval_check[eval_level][eval_inc++] = NULL;
	if(eval_inc >= EVAL_DEPTH) {
		cb_error(_("Maximum evaluate depth exceeded(%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
    break;

  case 965:

/* Line 1806 of yacc.c  */
#line 6632 "parser.y"
    {
	(yyval) = cb_false;
	eval_check[eval_level][eval_inc++] = NULL;
	if(eval_inc >= EVAL_DEPTH) {
		cb_error(_("Maximum evaluate depth exceeded(%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  }
    break;

  case 966:

/* Line 1806 of yacc.c  */
#line 6646 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 967:

/* Line 1806 of yacc.c  */
#line 6650 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 968:

/* Line 1806 of yacc.c  */
#line 6656 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 969:

/* Line 1806 of yacc.c  */
#line 6658 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 970:

/* Line 1806 of yacc.c  */
#line 6664 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 971:

/* Line 1806 of yacc.c  */
#line 6673 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 972:

/* Line 1806 of yacc.c  */
#line 6681 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  }
    break;

  case 973:

/* Line 1806 of yacc.c  */
#line 6687 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 974:

/* Line 1806 of yacc.c  */
#line 6694 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 975:

/* Line 1806 of yacc.c  */
#line 6696 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 976:

/* Line 1806 of yacc.c  */
#line 6701 "parser.y"
    {
	cb_tree not0 = cb_int0;
	cb_tree e2 = (yyvsp[(2) - (2)]);
	cb_tree x = NULL;
	cb_tree parm1 = (yyvsp[(1) - (2)]);
	if(eval_check[eval_level][eval_inc2]) {
		/* Check if the first token is NOT */
		/* It may belong to the EVALUATE, however see */
		/* below when it may be part of a partial expression */
		if(CB_PURPOSE_INT(parm1) == '!') {
			/* Pop stack if subject not TRUE / FALSE */
			not0 = cb_int1;
			x = parm1;
			parm1 = CB_CHAIN(parm1);
		}
		/* Partial expression handling */
		switch(CB_PURPOSE_INT(parm1)) {
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
			if(e2) {
				cb_error_x(e2, _("Invalid THROUGH usage"));
				e2 = NULL;
			}
			not0 = CB_PURPOSE(parm1);
			if(x) {
				/* Rebind the NOT to the partial expression */
				parm1 = cb_build_list(cb_int('!'), NULL, parm1);
			}
			/* Insert subject at head of list */
			parm1 = cb_build_list(cb_int('x'),
					    eval_check[eval_level][eval_inc2], parm1);
			break;
		}
	}

	/* Build expr now */
	cb_tree e1 = cb_build_expr(parm1);

	eval_inc2++;
	(yyval) = CB_BUILD_PAIR(not0, CB_BUILD_PAIR(e1, e2));
  }
    break;

  case 977:

/* Line 1806 of yacc.c  */
#line 6756 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 978:

/* Line 1806 of yacc.c  */
#line 6757 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 979:

/* Line 1806 of yacc.c  */
#line 6758 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 980:

/* Line 1806 of yacc.c  */
#line 6762 "parser.y"
    { (yyval) = NULL; }
    break;

  case 981:

/* Line 1806 of yacc.c  */
#line 6763 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 982:

/* Line 1806 of yacc.c  */
#line 6768 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), EVALUATE);
  }
    break;

  case 983:

/* Line 1806 of yacc.c  */
#line 6772 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), EVALUATE);
  }
    break;

  case 984:

/* Line 1806 of yacc.c  */
#line 6782 "parser.y"
    {
	begin_statement("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  }
    break;

  case 985:

/* Line 1806 of yacc.c  */
#line 6787 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 987:

/* Line 1806 of yacc.c  */
#line 6795 "parser.y"
    {
	if(in_declaratives && use_global_ind) {
		cb_error_x(current_statement,
			    _("EXIT PROGRAM is not allowed within a USE GLOBAL procedure"));
	}
	if(current_program->prog_type != CB_PROGRAM_TYPE) {
		cb_error_x(current_statement,
			    _("EXIT PROGRAM only allowed within a PROGRAM type"));
	}
	if(current_program->flag_main) {
		check_unreached = 0;
	} else {
		check_unreached = 1;
	}
	current_statement->name = (const char *)"EXIT PROGRAM";
	cb_emit_exit(0);
  }
    break;

  case 988:

/* Line 1806 of yacc.c  */
#line 6813 "parser.y"
    {
	if(in_declaratives && use_global_ind) {
		cb_error_x(current_statement,
			    _("EXIT FUNCTION is not allowed within a USE GLOBAL procedure"));
	}
	if(current_program->prog_type != CB_FUNCTION_TYPE) {
		cb_error_x(current_statement,
			    _("EXIT FUNCTION only allowed within a FUNCTION type"));
	}
	check_unreached = 1;
	current_statement->name = (const char *)"EXIT FUNCTION";
	cb_emit_exit(0);
  }
    break;

  case 989:

/* Line 1806 of yacc.c  */
#line 6827 "parser.y"
    {
	if(!perform_stack) {
		cb_error_x(current_statement,
			    _("EXIT PERFORM is only valid with inline PERFORM"));
	} else if(CB_VALUE(perform_stack) != cb_error_node) {
		cb_perform * p = CB_PERFORM(CB_VALUE(perform_stack));
		if(!p->cycle_label) {
			char name[64];
			sprintf(name, "EXIT PERFORM CYCLE %d", cb_id);
			p->cycle_label = cb_build_reference(name);
			cb_tree plabel = cb_build_label(p->cycle_label, NULL);
			CB_LABEL(plabel)->flag_begin = 1;
			CB_LABEL(plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PERFORM CYCLE";
		cb_emit_goto(CB_LIST_INIT(p->cycle_label), NULL);
	}
  }
    break;

  case 990:

/* Line 1806 of yacc.c  */
#line 6846 "parser.y"
    {
	if(!perform_stack) {
		cb_error_x(current_statement,
			    _("EXIT PERFORM is only valid with inline PERFORM"));
	} else if(CB_VALUE(perform_stack) != cb_error_node) {
		cb_perform * p = CB_PERFORM(CB_VALUE(perform_stack));
		if(!p->exit_label) {
			char name[64];
			sprintf(name, "EXIT PERFORM %d", cb_id);
			p->exit_label = cb_build_reference(name);
			cb_tree plabel = cb_build_label(p->exit_label, NULL);
			CB_LABEL(plabel)->flag_begin = 1;
			CB_LABEL(plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PERFORM";
		cb_emit_goto(CB_LIST_INIT(p->exit_label), NULL);
	}
  }
    break;

  case 991:

/* Line 1806 of yacc.c  */
#line 6865 "parser.y"
    {
	if(!current_section) {
		cb_error_x(current_statement,
			    _("EXIT SECTION is only valid with an active SECTION"));
	} else {
		if(!current_section->exit_label) {
			char name[64];
			sprintf(name, "EXIT SECTION %d", cb_id);
			current_section->exit_label = cb_build_reference(name);
			cb_tree plabel = cb_build_label(current_section->exit_label, NULL);
			CB_LABEL(plabel)->flag_begin = 1;
			CB_LABEL(plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT SECTION";
		cb_emit_goto(CB_LIST_INIT(current_section->exit_label), NULL);
	}
  }
    break;

  case 992:

/* Line 1806 of yacc.c  */
#line 6883 "parser.y"
    {
	if(!current_paragraph) {
		cb_error_x(current_statement,
			    _("EXIT PARAGRAPH is only valid with an active PARAGRAPH"));
	} else {
		if(!current_paragraph->exit_label) {
			char name[64];
			sprintf(name, "EXIT PARAGRAPH %d", cb_id);
			current_paragraph->exit_label = cb_build_reference(name);
			cb_tree plabel = cb_build_label(current_paragraph->exit_label, NULL);
			CB_LABEL(plabel)->flag_begin = 1;
			CB_LABEL(plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PARAGRAPH";
		cb_emit_goto(CB_LIST_INIT(current_paragraph->exit_label), NULL);
	}
  }
    break;

  case 993:

/* Line 1806 of yacc.c  */
#line 6906 "parser.y"
    {
	begin_statement("FREE", 0);
  }
    break;

  case 995:

/* Line 1806 of yacc.c  */
#line 6914 "parser.y"
    {
	cb_emit_free((yyvsp[(1) - (1)]));
  }
    break;

  case 996:

/* Line 1806 of yacc.c  */
#line 6924 "parser.y"
    {
	begin_statement("GENERATE", 0);
	PENDING("GENERATE");
  }
    break;

  case 999:

/* Line 1806 of yacc.c  */
#line 6940 "parser.y"
    {
	if(!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1001:

/* Line 1806 of yacc.c  */
#line 6953 "parser.y"
    {
	cb_emit_goto((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  }
    break;

  case 1002:

/* Line 1806 of yacc.c  */
#line 6961 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 1003:

/* Line 1806 of yacc.c  */
#line 6966 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1004:

/* Line 1806 of yacc.c  */
#line 6977 "parser.y"
    {
	begin_statement("GOBACK", 0);
	check_unreached = 1;
	cb_emit_exit(1U);
  }
    break;

  case 1005:

/* Line 1806 of yacc.c  */
#line 6989 "parser.y"
    {
	begin_statement("IF", TERM_IF);
  }
    break;

  case 1007:

/* Line 1806 of yacc.c  */
#line 6998 "parser.y"
    {
	cb_emit_if((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1008:

/* Line 1806 of yacc.c  */
#line 7002 "parser.y"
    {
	cb_emit_if((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1009:

/* Line 1806 of yacc.c  */
#line 7006 "parser.y"
    {
	cb_emit_if((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  }
    break;

  case 1010:

/* Line 1806 of yacc.c  */
#line 7013 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-4) - (0)]), IF);
  }
    break;

  case 1011:

/* Line 1806 of yacc.c  */
#line 7017 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-4) - (1)]), IF);
  }
    break;

  case 1012:

/* Line 1806 of yacc.c  */
#line 7027 "parser.y"
    {
	begin_statement("INITIALIZE", 0);
  }
    break;

  case 1014:

/* Line 1806 of yacc.c  */
#line 7036 "parser.y"
    {
	cb_emit_initialize((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1015:

/* Line 1806 of yacc.c  */
#line 7042 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1016:

/* Line 1806 of yacc.c  */
#line 7043 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1017:

/* Line 1806 of yacc.c  */
#line 7047 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1018:

/* Line 1806 of yacc.c  */
#line 7048 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1019:

/* Line 1806 of yacc.c  */
#line 7049 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1020:

/* Line 1806 of yacc.c  */
#line 7054 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1021:

/* Line 1806 of yacc.c  */
#line 7058 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1022:

/* Line 1806 of yacc.c  */
#line 7065 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1023:

/* Line 1806 of yacc.c  */
#line 7070 "parser.y"
    {
	(yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1024:

/* Line 1806 of yacc.c  */
#line 7077 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1025:

/* Line 1806 of yacc.c  */
#line 7083 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_ALPHABETIC); }
    break;

  case 1026:

/* Line 1806 of yacc.c  */
#line 7084 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 1027:

/* Line 1806 of yacc.c  */
#line 7085 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_NUMERIC); }
    break;

  case 1028:

/* Line 1806 of yacc.c  */
#line 7086 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 1029:

/* Line 1806 of yacc.c  */
#line 7087 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 1030:

/* Line 1806 of yacc.c  */
#line 7088 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_NATIONAL); }
    break;

  case 1031:

/* Line 1806 of yacc.c  */
#line 7089 "parser.y"
    { (yyval) = cb_int(CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 1032:

/* Line 1806 of yacc.c  */
#line 7094 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1033:

/* Line 1806 of yacc.c  */
#line 7098 "parser.y"
    {
	(yyval) = cb_true;
  }
    break;

  case 1034:

/* Line 1806 of yacc.c  */
#line 7107 "parser.y"
    {
	begin_statement("INITIATE", 0);
	PENDING("INITIATE");
  }
    break;

  case 1036:

/* Line 1806 of yacc.c  */
#line 7116 "parser.y"
    {
	begin_implicit_statement();
	if((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1037:

/* Line 1806 of yacc.c  */
#line 7122 "parser.y"
    {
	begin_implicit_statement();
	if((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1038:

/* Line 1806 of yacc.c  */
#line 7133 "parser.y"
    {
	begin_statement("INSPECT", 0);
	inspect_keyword = 0;
  }
    break;

  case 1041:

/* Line 1806 of yacc.c  */
#line 7146 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1042:

/* Line 1806 of yacc.c  */
#line 7150 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1043:

/* Line 1806 of yacc.c  */
#line 7154 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1048:

/* Line 1806 of yacc.c  */
#line 7170 "parser.y"
    {
	cb_init_tallying();
  }
    break;

  case 1049:

/* Line 1806 of yacc.c  */
#line 7174 "parser.y"
    {
	cb_emit_inspect((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  }
    break;

  case 1050:

/* Line 1806 of yacc.c  */
#line 7184 "parser.y"
    {
	cb_emit_inspect((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  }
    break;

  case 1051:

/* Line 1806 of yacc.c  */
#line 7194 "parser.y"
    {
	cb_tree x = cb_build_converting((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect((yyvsp[(0) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1052:

/* Line 1806 of yacc.c  */
#line 7201 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1053:

/* Line 1806 of yacc.c  */
#line 7202 "parser.y"
    { (yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1054:

/* Line 1806 of yacc.c  */
#line 7206 "parser.y"
    { (yyval) = cb_build_tallying_data((yyvsp[(1) - (2)])); }
    break;

  case 1055:

/* Line 1806 of yacc.c  */
#line 7207 "parser.y"
    { (yyval) = cb_build_tallying_characters((yyvsp[(2) - (2)])); }
    break;

  case 1056:

/* Line 1806 of yacc.c  */
#line 7208 "parser.y"
    { (yyval) = cb_build_tallying_all(); }
    break;

  case 1057:

/* Line 1806 of yacc.c  */
#line 7209 "parser.y"
    { (yyval) = cb_build_tallying_leading(); }
    break;

  case 1058:

/* Line 1806 of yacc.c  */
#line 7210 "parser.y"
    { (yyval) = cb_build_tallying_trailing(); }
    break;

  case 1059:

/* Line 1806 of yacc.c  */
#line 7211 "parser.y"
    { (yyval) = cb_build_tallying_value((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1060:

/* Line 1806 of yacc.c  */
#line 7215 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1061:

/* Line 1806 of yacc.c  */
#line 7216 "parser.y"
    { (yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1062:

/* Line 1806 of yacc.c  */
#line 7221 "parser.y"
    {
	(yyval) = cb_build_replacing_characters((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 1063:

/* Line 1806 of yacc.c  */
#line 7226 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1064:

/* Line 1806 of yacc.c  */
#line 7232 "parser.y"
    { /* Nothing */ }
    break;

  case 1065:

/* Line 1806 of yacc.c  */
#line 7233 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 1066:

/* Line 1806 of yacc.c  */
#line 7234 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 1067:

/* Line 1806 of yacc.c  */
#line 7235 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 1068:

/* Line 1806 of yacc.c  */
#line 7236 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 1069:

/* Line 1806 of yacc.c  */
#line 7241 "parser.y"
    {
	switch(inspect_keyword) {
		case 1:
			(yyval) = cb_build_replacing_all((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 2:
			(yyval) = cb_build_replacing_leading((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 3:
			(yyval) = cb_build_replacing_first((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 4:
			(yyval) = cb_build_replacing_trailing((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		default:
			cb_error_x(current_statement,
				    _("INSPECT missing a keyword"));
			(yyval) = cb_build_replacing_all((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
	}
  }
    break;

  case 1070:

/* Line 1806 of yacc.c  */
#line 7268 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start();
  }
    break;

  case 1071:

/* Line 1806 of yacc.c  */
#line 7272 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1072:

/* Line 1806 of yacc.c  */
#line 7279 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1("cob_inspect_before", (yyvsp[(3) - (3)])));
  }
    break;

  case 1073:

/* Line 1806 of yacc.c  */
#line 7283 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1("cob_inspect_after", (yyvsp[(3) - (3)])));
  }
    break;

  case 1074:

/* Line 1806 of yacc.c  */
#line 7292 "parser.y"
    {
	begin_statement("MERGE", 0);
	current_statement->flag_merge = 1;
  }
    break;

  case 1076:

/* Line 1806 of yacc.c  */
#line 7304 "parser.y"
    {
	begin_statement("MOVE", 0);
  }
    break;

  case 1078:

/* Line 1806 of yacc.c  */
#line 7312 "parser.y"
    {
	cb_emit_move((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1079:

/* Line 1806 of yacc.c  */
#line 7316 "parser.y"
    {
	cb_emit_move_corresponding((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1080:

/* Line 1806 of yacc.c  */
#line 7326 "parser.y"
    {
	begin_statement("MULTIPLY", TERM_MULTIPLY);
  }
    break;

  case 1082:

/* Line 1806 of yacc.c  */
#line 7335 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 1083:

/* Line 1806 of yacc.c  */
#line 7339 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(5) - (6)]), 0, cb_build_binary_op((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 1084:

/* Line 1806 of yacc.c  */
#line 7346 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), MULTIPLY);
  }
    break;

  case 1085:

/* Line 1806 of yacc.c  */
#line 7350 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), MULTIPLY);
  }
    break;

  case 1086:

/* Line 1806 of yacc.c  */
#line 7360 "parser.y"
    {
	begin_statement("OPEN", 0);
  }
    break;

  case 1088:

/* Line 1806 of yacc.c  */
#line 7368 "parser.y"
    {
	if((yyvsp[(2) - (4)]) && (yyvsp[(4) - (4)])) {
		cb_error_x(current_statement,
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	cb_tree x;
	if((yyvsp[(4) - (4)])) {
		x = (yyvsp[(4) - (4)]);
	} else {
		x = (yyvsp[(2) - (4)]);
	}
	for(cb_tree l = (yyvsp[(3) - (4)]); l; l = CB_CHAIN(l)) {
		if(CB_VALID_TREE(CB_VALUE(l))) {
			begin_implicit_statement();
			cb_emit_open(CB_VALUE(l), (yyvsp[(1) - (4)]), x);
		}
	}
  }
    break;

  case 1089:

/* Line 1806 of yacc.c  */
#line 7387 "parser.y"
    {
	if((yyvsp[(3) - (5)]) && (yyvsp[(5) - (5)])) {
		cb_error_x(current_statement,
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	cb_tree x;
	if((yyvsp[(5) - (5)])) {
		x = (yyvsp[(5) - (5)]);
	} else {
		x = (yyvsp[(3) - (5)]);
	}
	for(cb_tree l = (yyvsp[(4) - (5)]); l; l = CB_CHAIN(l)) {
		if(CB_VALID_TREE(CB_VALUE(l))) {
			begin_implicit_statement();
			cb_emit_open(CB_VALUE(l), (yyvsp[(2) - (5)]), x);
		}
	}
  }
    break;

  case 1090:

/* Line 1806 of yacc.c  */
#line 7408 "parser.y"
    { (yyval) = cb_int(COB_OPEN_INPUT); }
    break;

  case 1091:

/* Line 1806 of yacc.c  */
#line 7409 "parser.y"
    { (yyval) = cb_int(COB_OPEN_OUTPUT); }
    break;

  case 1092:

/* Line 1806 of yacc.c  */
#line 7410 "parser.y"
    { (yyval) = cb_int(COB_OPEN_I_O); }
    break;

  case 1093:

/* Line 1806 of yacc.c  */
#line 7411 "parser.y"
    { (yyval) = cb_int(COB_OPEN_EXTEND); }
    break;

  case 1094:

/* Line 1806 of yacc.c  */
#line 7415 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1095:

/* Line 1806 of yacc.c  */
#line 7416 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1096:

/* Line 1806 of yacc.c  */
#line 7420 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1097:

/* Line 1806 of yacc.c  */
#line 7421 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1098:

/* Line 1806 of yacc.c  */
#line 7422 "parser.y"
    { (yyval) = cb_int(COB_LOCK_OPEN_EXCLUSIVE); }
    break;

  case 1099:

/* Line 1806 of yacc.c  */
#line 7424 "parser.y"
    {
	(void)cb_verify(CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  }
    break;

  case 1100:

/* Line 1806 of yacc.c  */
#line 7435 "parser.y"
    {
	begin_statement("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1102:

/* Line 1806 of yacc.c  */
#line 7446 "parser.y"
    {
	cb_emit_perform((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  }
    break;

  case 1103:

/* Line 1806 of yacc.c  */
#line 7451 "parser.y"
    {
	CB_ADD_TO_CHAIN((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  }
    break;

  case 1104:

/* Line 1806 of yacc.c  */
#line 7457 "parser.y"
    {
	perform_stack = CB_CHAIN(perform_stack);
	cb_emit_perform((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1105:

/* Line 1806 of yacc.c  */
#line 7462 "parser.y"
    {
	cb_emit_perform((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  }
    break;

  case 1106:

/* Line 1806 of yacc.c  */
#line 7470 "parser.y"
    {
	if(cb_relaxed_syntax_check) {
		TERMINATOR_WARNING((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR((yyvsp[(-4) - (0)]), PERFORM);
	}
  }
    break;

  case 1107:

/* Line 1806 of yacc.c  */
#line 7478 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-4) - (1)]), PERFORM);
  }
    break;

  case 1108:

/* Line 1806 of yacc.c  */
#line 7485 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), PERFORM);
  }
    break;

  case 1109:

/* Line 1806 of yacc.c  */
#line 7489 "parser.y"
    {
	if(cb_relaxed_syntax_check) {
		TERMINATOR_WARNING((yyvsp[(-2) - (1)]), PERFORM);
	} else {
		TERMINATOR_ERROR((yyvsp[(-2) - (1)]), PERFORM);
	}
	/* Put the dot token back into the stack for reparse */
	cb_unput_dot();
  }
    break;

  case 1110:

/* Line 1806 of yacc.c  */
#line 7502 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 1111:

/* Line 1806 of yacc.c  */
#line 7509 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1112:

/* Line 1806 of yacc.c  */
#line 7520 "parser.y"
    {
	(yyval) = cb_build_perform_once(NULL);
  }
    break;

  case 1113:

/* Line 1806 of yacc.c  */
#line 7524 "parser.y"
    {
	(yyval) = cb_build_perform_times((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 1114:

/* Line 1806 of yacc.c  */
#line 7529 "parser.y"
    {
	(yyval) = cb_build_perform_forever(NULL);
  }
    break;

  case 1115:

/* Line 1806 of yacc.c  */
#line 7533 "parser.y"
    {
	cb_tree varying;

	if(!(yyvsp[(3) - (3)])) {
		(yyval) = cb_build_perform_forever(NULL);
	} else {
		varying = CB_LIST_INIT(cb_build_perform_varying(NULL, NULL, NULL, (yyvsp[(3) - (3)])));
		(yyval) = cb_build_perform_until((yyvsp[(1) - (3)]), varying);
	}
  }
    break;

  case 1116:

/* Line 1806 of yacc.c  */
#line 7544 "parser.y"
    {
	(yyval) = cb_build_perform_until((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1117:

/* Line 1806 of yacc.c  */
#line 7550 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1118:

/* Line 1806 of yacc.c  */
#line 7551 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1119:

/* Line 1806 of yacc.c  */
#line 7555 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1120:

/* Line 1806 of yacc.c  */
#line 7556 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1121:

/* Line 1806 of yacc.c  */
#line 7559 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 1122:

/* Line 1806 of yacc.c  */
#line 7561 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1123:

/* Line 1806 of yacc.c  */
#line 7566 "parser.y"
    {
	(yyval) = cb_build_perform_varying((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1124:

/* Line 1806 of yacc.c  */
#line 7576 "parser.y"
    {
	begin_statement("READ", TERM_READ);
  }
    break;

  case 1126:

/* Line 1806 of yacc.c  */
#line 7585 "parser.y"
    {
	if(CB_VALID_TREE((yyvsp[(1) - (7)]))) {
		cb_file * cf = CB_FILE(cb_ref((yyvsp[(1) - (7)])));
		if((yyvsp[(5) - (7)]) &&(cf->lock_mode & COB_LOCK_AUTOMATIC)) {
			cb_error_x(current_statement,
				    _("LOCK clause invalid with file LOCK AUTOMATIC"));
		} else if((yyvsp[(6) - (7)]) &&
		    (cf->organization != COB_ORG_RELATIVE &&
		       cf->organization != COB_ORG_INDEXED)) {
			cb_error_x(current_statement,
				    _("KEY clause invalid with this file type"));
		} else if(current_statement->handler_id == COB_EC_I_O_INVALID_KEY &&
			 (cf->organization != COB_ORG_RELATIVE &&
			    cf->organization != COB_ORG_INDEXED)) {
			cb_error_x(current_statement,
				    _("INVALID KEY clause invalid with this file type"));
		} else {
			cb_emit_read((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(5) - (7)]));
		}
	}
  }
    break;

  case 1127:

/* Line 1806 of yacc.c  */
#line 7609 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1128:

/* Line 1806 of yacc.c  */
#line 7610 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1129:

/* Line 1806 of yacc.c  */
#line 7615 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1130:

/* Line 1806 of yacc.c  */
#line 7619 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1131:

/* Line 1806 of yacc.c  */
#line 7623 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1132:

/* Line 1806 of yacc.c  */
#line 7627 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1133:

/* Line 1806 of yacc.c  */
#line 7631 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1134:

/* Line 1806 of yacc.c  */
#line 7635 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1135:

/* Line 1806 of yacc.c  */
#line 7639 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1136:

/* Line 1806 of yacc.c  */
#line 7645 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1137:

/* Line 1806 of yacc.c  */
#line 7646 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1140:

/* Line 1806 of yacc.c  */
#line 7656 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), READ);
  }
    break;

  case 1141:

/* Line 1806 of yacc.c  */
#line 7660 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), READ);
  }
    break;

  case 1142:

/* Line 1806 of yacc.c  */
#line 7670 "parser.y"
    {
	begin_statement("READY TRACE", 0);
	cb_emit_ready_trace();
  }
    break;

  case 1143:

/* Line 1806 of yacc.c  */
#line 7680 "parser.y"
    {
	begin_statement("RELEASE", 0);
  }
    break;

  case 1145:

/* Line 1806 of yacc.c  */
#line 7688 "parser.y"
    {
	cb_emit_release((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1146:

/* Line 1806 of yacc.c  */
#line 7698 "parser.y"
    {
	begin_statement("RESET TRACE", 0);
	cb_emit_reset_trace();
  }
    break;

  case 1147:

/* Line 1806 of yacc.c  */
#line 7708 "parser.y"
    {
	begin_statement("RETURN", TERM_RETURN);
  }
    break;

  case 1149:

/* Line 1806 of yacc.c  */
#line 7717 "parser.y"
    {
	cb_emit_return((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1150:

/* Line 1806 of yacc.c  */
#line 7724 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), RETURN);
  }
    break;

  case 1151:

/* Line 1806 of yacc.c  */
#line 7728 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), RETURN);
  }
    break;

  case 1152:

/* Line 1806 of yacc.c  */
#line 7738 "parser.y"
    {
	begin_statement("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1154:

/* Line 1806 of yacc.c  */
#line 7750 "parser.y"
    {
	cb_emit_rewrite((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  }
    break;

  case 1155:

/* Line 1806 of yacc.c  */
#line 7758 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1156:

/* Line 1806 of yacc.c  */
#line 7762 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1157:

/* Line 1806 of yacc.c  */
#line 7766 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1158:

/* Line 1806 of yacc.c  */
#line 7773 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), REWRITE);
  }
    break;

  case 1159:

/* Line 1806 of yacc.c  */
#line 7777 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), REWRITE);
  }
    break;

  case 1160:

/* Line 1806 of yacc.c  */
#line 7787 "parser.y"
    {
	begin_statement("ROLLBACK", 0);
	cb_emit_rollback();
  }
    break;

  case 1161:

/* Line 1806 of yacc.c  */
#line 7798 "parser.y"
    {
	begin_statement("SEARCH", TERM_SEARCH);
  }
    break;

  case 1163:

/* Line 1806 of yacc.c  */
#line 7807 "parser.y"
    {
	cb_emit_search((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1164:

/* Line 1806 of yacc.c  */
#line 7812 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  }
    break;

  case 1165:

/* Line 1806 of yacc.c  */
#line 7819 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1166:

/* Line 1806 of yacc.c  */
#line 7820 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1167:

/* Line 1806 of yacc.c  */
#line 7825 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1168:

/* Line 1806 of yacc.c  */
#line 7830 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1169:

/* Line 1806 of yacc.c  */
#line 7837 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1170:

/* Line 1806 of yacc.c  */
#line 7841 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1171:

/* Line 1806 of yacc.c  */
#line 7849 "parser.y"
    {
	(yyval) = cb_build_if_check_break((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1172:

/* Line 1806 of yacc.c  */
#line 7856 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), SEARCH);
  }
    break;

  case 1173:

/* Line 1806 of yacc.c  */
#line 7860 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), SEARCH);
  }
    break;

  case 1174:

/* Line 1806 of yacc.c  */
#line 7870 "parser.y"
    {
	begin_statement("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  }
    break;

  case 1175:

/* Line 1806 of yacc.c  */
#line 7877 "parser.y"
    {
	cobc_cs_check = 0;
  }
    break;

  case 1182:

/* Line 1806 of yacc.c  */
#line 7892 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1183:

/* Line 1806 of yacc.c  */
#line 7893 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1184:

/* Line 1806 of yacc.c  */
#line 7897 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1185:

/* Line 1806 of yacc.c  */
#line 7898 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1186:

/* Line 1806 of yacc.c  */
#line 7905 "parser.y"
    {
	cb_emit_setenv((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1187:

/* Line 1806 of yacc.c  */
#line 7914 "parser.y"
    {
	cb_emit_set_attribute((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  }
    break;

  case 1190:

/* Line 1806 of yacc.c  */
#line 7926 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  }
    break;

  case 1191:

/* Line 1806 of yacc.c  */
#line 7930 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  }
    break;

  case 1192:

/* Line 1806 of yacc.c  */
#line 7934 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  }
    break;

  case 1193:

/* Line 1806 of yacc.c  */
#line 7938 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  }
    break;

  case 1194:

/* Line 1806 of yacc.c  */
#line 7942 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  }
    break;

  case 1195:

/* Line 1806 of yacc.c  */
#line 7946 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  }
    break;

  case 1196:

/* Line 1806 of yacc.c  */
#line 7950 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  }
    break;

  case 1197:

/* Line 1806 of yacc.c  */
#line 7954 "parser.y"
    {
	bit_set_attr((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  }
    break;

  case 1198:

/* Line 1806 of yacc.c  */
#line 7963 "parser.y"
    {
	cb_emit_set_to((yyvsp[(1) - (4)]), cb_build_ppointer((yyvsp[(4) - (4)])));
  }
    break;

  case 1199:

/* Line 1806 of yacc.c  */
#line 7967 "parser.y"
    {
	cb_emit_set_to((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1200:

/* Line 1806 of yacc.c  */
#line 7976 "parser.y"
    {
	cb_emit_set_up_down((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1203:

/* Line 1806 of yacc.c  */
#line 7990 "parser.y"
    {
	cb_emit_set_on_off((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1206:

/* Line 1806 of yacc.c  */
#line 8004 "parser.y"
    {
	cb_emit_set_true((yyvsp[(1) - (3)]));
  }
    break;

  case 1207:

/* Line 1806 of yacc.c  */
#line 8008 "parser.y"
    {
	cb_emit_set_false((yyvsp[(1) - (3)]));
  }
    break;

  case 1208:

/* Line 1806 of yacc.c  */
#line 8018 "parser.y"
    {
	begin_statement("SORT", 0);
  }
    break;

  case 1210:

/* Line 1806 of yacc.c  */
#line 8026 "parser.y"
    {
	cb_tree x = cb_ref((yyvsp[(1) - (4)]));
	if(CB_VALID_TREE(x)) {
		if(CB_INVALID_TREE((yyvsp[(2) - (4)]))) {
			if(CB_FILE_P(x)) {
				cb_error(_("File sort requires KEY phrase"));
			} else {
				cb_error(_("Table sort without keys not implemented yet"));
			}
			(yyval) = NULL;
		} else {
			cb_emit_sort_init((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			(yyval)= (yyvsp[(1) - (4)]);
		}
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 1211:

/* Line 1806 of yacc.c  */
#line 8045 "parser.y"
    {
	if((yyvsp[(5) - (7)]) && CB_VALID_TREE((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish((yyvsp[(1) - (7)]));
	}
  }
    break;

  case 1212:

/* Line 1806 of yacc.c  */
#line 8054 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1213:

/* Line 1806 of yacc.c  */
#line 8059 "parser.y"
    {
	cb_tree l;
	if((yyvsp[(5) - (5)]) == NULL) {
		l = CB_LIST_INIT(NULL);
	} else {
		l = (yyvsp[(5) - (5)]);
	}
	cb_tree lparm = l;
	for(; l; l = CB_CHAIN(l)) {
		CB_PURPOSE(l) = (yyvsp[(3) - (5)]);
	}
	(yyval) = cb_list_append((yyvsp[(1) - (5)]), lparm);
  }
    break;

  case 1214:

/* Line 1806 of yacc.c  */
#line 8075 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1215:

/* Line 1806 of yacc.c  */
#line 8076 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1217:

/* Line 1806 of yacc.c  */
#line 8081 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  }
    break;

  case 1218:

/* Line 1806 of yacc.c  */
#line 8088 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1219:

/* Line 1806 of yacc.c  */
#line 8089 "parser.y"
    { (yyval) = cb_ref((yyvsp[(3) - (3)])); }
    break;

  case 1220:

/* Line 1806 of yacc.c  */
#line 8094 "parser.y"
    {
	if((yyvsp[(0) - (0)]) && CB_FILE_P(cb_ref((yyvsp[(0) - (0)])))) {
		cb_error(_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1221:

/* Line 1806 of yacc.c  */
#line 8100 "parser.y"
    {
	if((yyvsp[(0) - (2)])) {
		if(!CB_FILE_P(cb_ref((yyvsp[(0) - (2)])))) {
			cb_error(_("USING invalid with table SORT"));
		} else {
			cb_emit_sort_using((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  }
    break;

  case 1222:

/* Line 1806 of yacc.c  */
#line 8110 "parser.y"
    {
	if((yyvsp[(0) - (4)])) {
		if(!CB_FILE_P(cb_ref((yyvsp[(0) - (4)])))) {
			cb_error(_("INPUT PROCEDURE invalid with table SORT"));
		} else if(current_statement->flag_merge) {
			cb_error(_("INPUT PROCEDURE invalid with MERGE"));
		} else {
			cb_emit_sort_input((yyvsp[(4) - (4)]));
		}
	}
  }
    break;

  case 1223:

/* Line 1806 of yacc.c  */
#line 8125 "parser.y"
    {
	if((yyvsp[(-1) - (0)]) && CB_FILE_P(cb_ref((yyvsp[(-1) - (0)])))) {
		cb_error(_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1224:

/* Line 1806 of yacc.c  */
#line 8131 "parser.y"
    {
	if((yyvsp[(-1) - (2)])) {
		if(!CB_FILE_P(cb_ref((yyvsp[(-1) - (2)])))) {
			cb_error(_("GIVING invalid with table SORT"));
		} else {
			cb_emit_sort_giving((yyvsp[(-1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  }
    break;

  case 1225:

/* Line 1806 of yacc.c  */
#line 8141 "parser.y"
    {
	if((yyvsp[(-1) - (4)])) {
		if(!CB_FILE_P(cb_ref((yyvsp[(-1) - (4)])))) {
			cb_error(_("OUTPUT PROCEDURE invalid with table SORT"));
		} else {
			cb_emit_sort_output((yyvsp[(4) - (4)]));
		}
	}
  }
    break;

  case 1226:

/* Line 1806 of yacc.c  */
#line 8157 "parser.y"
    {
	begin_statement("START", TERM_START);
	start_tree = cb_int(COB_EQ);
  }
    break;

  case 1228:

/* Line 1806 of yacc.c  */
#line 8167 "parser.y"
    {
	if((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x(current_statement,
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1229:

/* Line 1806 of yacc.c  */
#line 8179 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1230:

/* Line 1806 of yacc.c  */
#line 8183 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1231:

/* Line 1806 of yacc.c  */
#line 8190 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1232:

/* Line 1806 of yacc.c  */
#line 8194 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1233:

/* Line 1806 of yacc.c  */
#line 8199 "parser.y"
    {
	start_tree = cb_int(COB_FI);
	(yyval) = NULL;
  }
    break;

  case 1234:

/* Line 1806 of yacc.c  */
#line 8204 "parser.y"
    {
	start_tree = cb_int(COB_LA);
	(yyval) = NULL;
  }
    break;

  case 1235:

/* Line 1806 of yacc.c  */
#line 8211 "parser.y"
    { (yyval) = cb_int(COB_EQ); }
    break;

  case 1236:

/* Line 1806 of yacc.c  */
#line 8212 "parser.y"
    { (yyval) = cb_int((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); }
    break;

  case 1237:

/* Line 1806 of yacc.c  */
#line 8213 "parser.y"
    { (yyval) = cb_int((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); }
    break;

  case 1238:

/* Line 1806 of yacc.c  */
#line 8214 "parser.y"
    { (yyval) = cb_int((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); }
    break;

  case 1239:

/* Line 1806 of yacc.c  */
#line 8215 "parser.y"
    { (yyval) = cb_int((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); }
    break;

  case 1240:

/* Line 1806 of yacc.c  */
#line 8216 "parser.y"
    { (yyval) = cb_int(COB_NE); }
    break;

  case 1241:

/* Line 1806 of yacc.c  */
#line 8221 "parser.y"
    {
	cb_error_x(current_statement,
		    _("NOT EQUAL condition disallowed on START statement"));
  }
    break;

  case 1244:

/* Line 1806 of yacc.c  */
#line 8234 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), START);
  }
    break;

  case 1245:

/* Line 1806 of yacc.c  */
#line 8238 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), START);
  }
    break;

  case 1246:

/* Line 1806 of yacc.c  */
#line 8248 "parser.y"
    {
	begin_statement("STOP RUN", 0);
  }
    break;

  case 1247:

/* Line 1806 of yacc.c  */
#line 8252 "parser.y"
    {
	cb_emit_stop_run((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  }
    break;

  case 1248:

/* Line 1806 of yacc.c  */
#line 8258 "parser.y"
    {
	begin_statement("STOP", 0);
	cb_verify(cb_stop_literal_statement, "STOP literal");
	cb_emit_display(CB_LIST_INIT((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept(NULL, NULL, NULL);
	cobc_cs_check = 0;
  }
    break;

  case 1249:

/* Line 1806 of yacc.c  */
#line 8270 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  }
    break;

  case 1250:

/* Line 1806 of yacc.c  */
#line 8274 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1251:

/* Line 1806 of yacc.c  */
#line 8278 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1252:

/* Line 1806 of yacc.c  */
#line 8282 "parser.y"
    {
	if((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  }
    break;

  case 1253:

/* Line 1806 of yacc.c  */
#line 8290 "parser.y"
    {
	if((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  }
    break;

  case 1254:

/* Line 1806 of yacc.c  */
#line 8301 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1255:

/* Line 1806 of yacc.c  */
#line 8305 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1256:

/* Line 1806 of yacc.c  */
#line 8311 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1257:

/* Line 1806 of yacc.c  */
#line 8312 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1258:

/* Line 1806 of yacc.c  */
#line 8313 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1259:

/* Line 1806 of yacc.c  */
#line 8314 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1260:

/* Line 1806 of yacc.c  */
#line 8321 "parser.y"
    {
	begin_statement("STRING", TERM_STRING);
  }
    break;

  case 1262:

/* Line 1806 of yacc.c  */
#line 8330 "parser.y"
    {
	cb_emit_string((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1263:

/* Line 1806 of yacc.c  */
#line 8336 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 1264:

/* Line 1806 of yacc.c  */
#line 8337 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1265:

/* Line 1806 of yacc.c  */
#line 8341 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1266:

/* Line 1806 of yacc.c  */
#line 8342 "parser.y"
    { (yyval) = CB_BUILD_PAIR(cb_int0, NULL); }
    break;

  case 1267:

/* Line 1806 of yacc.c  */
#line 8343 "parser.y"
    { (yyval) = CB_BUILD_PAIR((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1268:

/* Line 1806 of yacc.c  */
#line 8347 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1269:

/* Line 1806 of yacc.c  */
#line 8348 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1270:

/* Line 1806 of yacc.c  */
#line 8353 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), STRING);
  }
    break;

  case 1271:

/* Line 1806 of yacc.c  */
#line 8357 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), STRING);
  }
    break;

  case 1272:

/* Line 1806 of yacc.c  */
#line 8367 "parser.y"
    {
	begin_statement("SUBTRACT", TERM_SUBTRACT);
  }
    break;

  case 1274:

/* Line 1806 of yacc.c  */
#line 8376 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(3) - (4)]), '-', cb_build_binary_list((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1275:

/* Line 1806 of yacc.c  */
#line 8380 "parser.y"
    {
	cb_emit_arithmetic((yyvsp[(5) - (6)]), 0, cb_build_binary_list(CB_BUILD_CHAIN((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1276:

/* Line 1806 of yacc.c  */
#line 8384 "parser.y"
    {
	cb_emit_corresponding(cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1277:

/* Line 1806 of yacc.c  */
#line 8391 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), SUBTRACT);
  }
    break;

  case 1278:

/* Line 1806 of yacc.c  */
#line 8395 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), SUBTRACT);
  }
    break;

  case 1279:

/* Line 1806 of yacc.c  */
#line 8405 "parser.y"
    {
	begin_statement("SUPPRESS", 0);
	if(!in_declaratives) {
		cb_error_x(current_statement,
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	PENDING("SUPPRESS");
  }
    break;

  case 1282:

/* Line 1806 of yacc.c  */
#line 8423 "parser.y"
    {
	begin_statement("TERMINATE", 0);
	PENDING("TERMINATE");
  }
    break;

  case 1284:

/* Line 1806 of yacc.c  */
#line 8432 "parser.y"
    {
	begin_implicit_statement();
	if((yyvsp[(1) - (1)]) != cb_error_node) {
	}
  }
    break;

  case 1285:

/* Line 1806 of yacc.c  */
#line 8438 "parser.y"
    {
	begin_implicit_statement();
	if((yyvsp[(2) - (2)]) != cb_error_node) {
	}
  }
    break;

  case 1286:

/* Line 1806 of yacc.c  */
#line 8449 "parser.y"
    {
	begin_statement("TRANSFORM", 0);
  }
    break;

  case 1288:

/* Line 1806 of yacc.c  */
#line 8457 "parser.y"
    {
	cb_tree x = cb_build_converting((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start());
	cb_emit_inspect((yyvsp[(1) - (5)]), x, cb_int0, 2);
  }
    break;

  case 1289:

/* Line 1806 of yacc.c  */
#line 8468 "parser.y"
    {
	begin_statement("UNLOCK", 0);
  }
    break;

  case 1291:

/* Line 1806 of yacc.c  */
#line 8476 "parser.y"
    {
	if(CB_VALID_TREE((yyvsp[(1) - (2)]))) {
		if(CB_FILE(cb_ref((yyvsp[(1) - (2)])))->organization == COB_ORG_SORT) {
			cb_error_x(current_statement,
				    _("UNLOCK invalid for SORT files"));
		} else {
			cb_emit_unlock((yyvsp[(1) - (2)]));
		}
	}
  }
    break;

  case 1295:

/* Line 1806 of yacc.c  */
#line 8499 "parser.y"
    {
	begin_statement("UNSTRING", TERM_UNSTRING);
  }
    break;

  case 1297:

/* Line 1806 of yacc.c  */
#line 8509 "parser.y"
    {
	cb_emit_unstring((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1298:

/* Line 1806 of yacc.c  */
#line 8515 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1299:

/* Line 1806 of yacc.c  */
#line 8517 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1300:

/* Line 1806 of yacc.c  */
#line 8521 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 1301:

/* Line 1806 of yacc.c  */
#line 8523 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1302:

/* Line 1806 of yacc.c  */
#line 8528 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1303:

/* Line 1806 of yacc.c  */
#line 8534 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(2) - (2)])); }
    break;

  case 1304:

/* Line 1806 of yacc.c  */
#line 8536 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1305:

/* Line 1806 of yacc.c  */
#line 8541 "parser.y"
    {
	(yyval) = cb_build_unstring_into((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1306:

/* Line 1806 of yacc.c  */
#line 8547 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1307:

/* Line 1806 of yacc.c  */
#line 8548 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1308:

/* Line 1806 of yacc.c  */
#line 8552 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1309:

/* Line 1806 of yacc.c  */
#line 8553 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1310:

/* Line 1806 of yacc.c  */
#line 8557 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1311:

/* Line 1806 of yacc.c  */
#line 8558 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1312:

/* Line 1806 of yacc.c  */
#line 8563 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), UNSTRING);
  }
    break;

  case 1313:

/* Line 1806 of yacc.c  */
#line 8567 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), UNSTRING);
  }
    break;

  case 1314:

/* Line 1806 of yacc.c  */
#line 8577 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  }
    break;

  case 1320:

/* Line 1806 of yacc.c  */
#line 8594 "parser.y"
    {
	if(!in_declaratives) {
		cb_error(_("USE statement must be within DECLARATIVES"));
	} else if(!current_section) {
		cb_error(_("SECTION header missing before USE statement"));
	} else {
		current_section->flag_begin = 1;
		current_section->flag_return = 1;
		current_section->flag_declarative_exit = 1;
		current_section->flag_real_label = 1;
		current_section->flag_skip_label = 0;
		CB_EXCEPTION_ENABLE(COB_EC_I_O) = 1;
		if(use_global_ind) {
			current_section->flag_global = 1;
			current_program->global_list =
				cb_list_add(current_program->global_list,
					     current_section);
		}
		emit_statement(cb_build_comment("USE AFTER ERROR"));
	}
  }
    break;

  case 1321:

/* Line 1806 of yacc.c  */
#line 8619 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1322:

/* Line 1806 of yacc.c  */
#line 8623 "parser.y"
    {
	if(current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error(_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  }
    break;

  case 1323:

/* Line 1806 of yacc.c  */
#line 8635 "parser.y"
    {
	for(cb_tree l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN(l)) {
		if(CB_VALID_TREE(CB_VALUE(l))) {
			setup_use_file(CB_FILE(cb_ref(CB_VALUE(l))));
		}
	}
  }
    break;

  case 1324:

/* Line 1806 of yacc.c  */
#line 8643 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1325:

/* Line 1806 of yacc.c  */
#line 8648 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1326:

/* Line 1806 of yacc.c  */
#line 8653 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1327:

/* Line 1806 of yacc.c  */
#line 8658 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1328:

/* Line 1806 of yacc.c  */
#line 8666 "parser.y"
    {
	if(!in_declaratives) {
		cb_error(_("USE statement must be within DECLARATIVES"));
	} else if(current_program->nested_level) {
		cb_error(_("USE DEBUGGING not supported in contained program"));
	} else {
		in_debugging = 1;
		current_section->flag_begin = 1;
		current_section->flag_return = 1;
		current_section->flag_declarative_exit = 1;
		current_section->flag_real_label = 0;
		current_section->flag_is_debug_sect = 1;
		if(!needs_debug_item) {
			needs_debug_item = 1;
			cb_build_debug_item();
		}
		if(!current_program->flag_debugging) {
			skip_statements = 1;
			current_section->flag_skip_label = 1;
		} else {
			current_program->flag_gen_debug = 1;
			char name[64];
			sprintf(name, "EXIT SECTION %d", cb_id);
			cb_tree plabel = cb_build_reference(name);
			plabel = cb_build_label(plabel, NULL);
			CB_LABEL(plabel)->flag_begin = 1;
			CB_LABEL(plabel)->flag_dummy_exit = 1;
			current_section->exit_label = plabel;
			emit_statement(cb_build_comment("USE FOR DEBUGGING"));
		}
	}
  }
    break;

  case 1331:

/* Line 1806 of yacc.c  */
#line 8707 "parser.y"
    {
	if(current_program->flag_debugging) {
		CB_REFERENCE((yyvsp[(1) - (1)]))->debug_section = current_section;
		CB_REFERENCE((yyvsp[(1) - (1)]))->flag_debug_code = 1;
		CB_REFERENCE((yyvsp[(1) - (1)]))->flag_all_debug = 0;
		cb_tree z = CB_LIST_INIT((yyvsp[(1) - (1)]));
		current_program->debug_list =
			cb_list_append(current_program->debug_list, z);
		/* Check backward refs to file/data names */
		/* Label refs will be checked later(forward/backward ref) */
		if(CB_WORD_COUNT((yyvsp[(1) - (1)])) > 0) {
			cb_tree l = CB_VALUE(CB_WORD_ITEMS((yyvsp[(1) - (1)])));
			switch(CB_TREE_TAG(l)) {
			case CB_TAG_FILE:
				CB_FILE(l)->debug_section = current_section;
				CB_FILE(l)->flag_fl_debug = 1;
				break;
			case CB_TAG_FIELD:
				{
					cb_tree x = cb_ref((yyvsp[(1) - (1)]));
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

  case 1332:

/* Line 1806 of yacc.c  */
#line 8743 "parser.y"
    {
	if(current_program->flag_debugging) {
		if(current_program->all_procedure) {
			cb_error(_("Duplicate USE DEBUGGING ON ALL PROCEDURES"));
		} else {
			current_program->all_procedure = current_section;
		}
	}
  }
    break;

  case 1333:

/* Line 1806 of yacc.c  */
#line 8753 "parser.y"
    {
	if(current_program->flag_debugging) {
		/* Reference must be a data item */
		cb_tree x = cb_ref((yyvsp[(3) - (3)]));
		if(CB_INVALID_TREE(x) || !CB_FIELD_P(x)) {
			cb_error(_("Invalid target for DEBUGGING ALL"));
		} else {
			needs_field_debug = 1;
			CB_FIELD(x)->debug_section = current_section;
			CB_FIELD(x)->flag_field_debug = 1;
			CB_FIELD(x)->flag_all_debug = 1;
			CB_REFERENCE((yyvsp[(3) - (3)]))->debug_section = current_section;
			CB_REFERENCE((yyvsp[(3) - (3)]))->flag_debug_code = 1;
			CB_REFERENCE((yyvsp[(3) - (3)]))->flag_all_debug = 1;
			CB_CHAIN_PAIR(current_program->debug_list, x, (yyvsp[(3) - (3)]));
		}
	}
  }
    break;

  case 1338:

/* Line 1806 of yacc.c  */
#line 8781 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement(cb_build_comment("USE BEFORE REPORTING"));
	PENDING("USE BEFORE REPORTING");
  }
    break;

  case 1339:

/* Line 1806 of yacc.c  */
#line 8790 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement(cb_build_comment("USE AFTER EXCEPTION CONDITION"));
	PENDING("USE AFTER EXCEPTION CONDITION");
  }
    break;

  case 1342:

/* Line 1806 of yacc.c  */
#line 8806 "parser.y"
    {
	begin_statement("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  }
    break;

  case 1344:

/* Line 1806 of yacc.c  */
#line 8818 "parser.y"
    {
	if(CB_VALID_TREE((yyvsp[(1) - (5)]))) {
		cb_emit_write((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  }
    break;

  case 1345:

/* Line 1806 of yacc.c  */
#line 8827 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1346:

/* Line 1806 of yacc.c  */
#line 8828 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1347:

/* Line 1806 of yacc.c  */
#line 8833 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1348:

/* Line 1806 of yacc.c  */
#line 8837 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1349:

/* Line 1806 of yacc.c  */
#line 8841 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1350:

/* Line 1806 of yacc.c  */
#line 8845 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page((yyvsp[(1) - (3)]));
  }
    break;

  case 1351:

/* Line 1806 of yacc.c  */
#line 8851 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1352:

/* Line 1806 of yacc.c  */
#line 8852 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1355:

/* Line 1806 of yacc.c  */
#line 8862 "parser.y"
    {
	TERMINATOR_WARNING((yyvsp[(-2) - (0)]), WRITE);
  }
    break;

  case 1356:

/* Line 1806 of yacc.c  */
#line 8866 "parser.y"
    {
	TERMINATOR_CLEAR((yyvsp[(-2) - (1)]), WRITE);
  }
    break;

  case 1359:

/* Line 1806 of yacc.c  */
#line 8883 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1361:

/* Line 1806 of yacc.c  */
#line 8893 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1364:

/* Line 1806 of yacc.c  */
#line 8906 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1366:

/* Line 1806 of yacc.c  */
#line 8916 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1369:

/* Line 1806 of yacc.c  */
#line 8931 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1371:

/* Line 1806 of yacc.c  */
#line 8941 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1374:

/* Line 1806 of yacc.c  */
#line 8958 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1376:

/* Line 1806 of yacc.c  */
#line 8969 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1382:

/* Line 1806 of yacc.c  */
#line 8992 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1383:

/* Line 1806 of yacc.c  */
#line 9001 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1387:

/* Line 1806 of yacc.c  */
#line 9018 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1388:

/* Line 1806 of yacc.c  */
#line 9027 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1391:

/* Line 1806 of yacc.c  */
#line 9044 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1393:

/* Line 1806 of yacc.c  */
#line 9054 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1394:

/* Line 1806 of yacc.c  */
#line 9064 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1395:

/* Line 1806 of yacc.c  */
#line 9068 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 1396:

/* Line 1806 of yacc.c  */
#line 9078 "parser.y"
    {
	(yyval) = cb_build_cond((yyvsp[(1) - (1)]));
  }
    break;

  case 1397:

/* Line 1806 of yacc.c  */
#line 9085 "parser.y"
    {
	(yyval) = cb_build_expr((yyvsp[(1) - (1)]));
  }
    break;

  case 1398:

/* Line 1806 of yacc.c  */
#line 9091 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1399:

/* Line 1806 of yacc.c  */
#line 9095 "parser.y"
    {
	(yyval) = cb_list_reverse(current_expr);
  }
    break;

  case 1403:

/* Line 1806 of yacc.c  */
#line 9108 "parser.y"
    {
	if(CB_REFERENCE_P((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P(cb_ref((yyvsp[(1) - (1)])))) {
		push_expr('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr('x', (yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1404:

/* Line 1806 of yacc.c  */
#line 9116 "parser.y"
    { push_expr('(', NULL); }
    break;

  case 1405:

/* Line 1806 of yacc.c  */
#line 9117 "parser.y"
    { push_expr(')', NULL); }
    break;

  case 1406:

/* Line 1806 of yacc.c  */
#line 9119 "parser.y"
    { push_expr('+', NULL); }
    break;

  case 1407:

/* Line 1806 of yacc.c  */
#line 9120 "parser.y"
    { push_expr('-', NULL); }
    break;

  case 1408:

/* Line 1806 of yacc.c  */
#line 9121 "parser.y"
    { push_expr('*', NULL); }
    break;

  case 1409:

/* Line 1806 of yacc.c  */
#line 9122 "parser.y"
    { push_expr('/', NULL); }
    break;

  case 1410:

/* Line 1806 of yacc.c  */
#line 9123 "parser.y"
    { push_expr('^', NULL); }
    break;

  case 1411:

/* Line 1806 of yacc.c  */
#line 9125 "parser.y"
    { push_expr('=', NULL); }
    break;

  case 1412:

/* Line 1806 of yacc.c  */
#line 9126 "parser.y"
    { push_expr('>', NULL); }
    break;

  case 1413:

/* Line 1806 of yacc.c  */
#line 9127 "parser.y"
    { push_expr('<', NULL); }
    break;

  case 1414:

/* Line 1806 of yacc.c  */
#line 9128 "parser.y"
    { push_expr(']', NULL); }
    break;

  case 1415:

/* Line 1806 of yacc.c  */
#line 9129 "parser.y"
    { push_expr('[', NULL); }
    break;

  case 1416:

/* Line 1806 of yacc.c  */
#line 9130 "parser.y"
    { push_expr('~', NULL); }
    break;

  case 1417:

/* Line 1806 of yacc.c  */
#line 9132 "parser.y"
    { push_expr('!', NULL); }
    break;

  case 1418:

/* Line 1806 of yacc.c  */
#line 9133 "parser.y"
    { push_expr('&', NULL); }
    break;

  case 1419:

/* Line 1806 of yacc.c  */
#line 9134 "parser.y"
    { push_expr('|', NULL); }
    break;

  case 1420:

/* Line 1806 of yacc.c  */
#line 9136 "parser.y"
    { push_expr('O', NULL); }
    break;

  case 1421:

/* Line 1806 of yacc.c  */
#line 9137 "parser.y"
    { push_expr('9', NULL); }
    break;

  case 1422:

/* Line 1806 of yacc.c  */
#line 9138 "parser.y"
    { push_expr('A', NULL); }
    break;

  case 1423:

/* Line 1806 of yacc.c  */
#line 9139 "parser.y"
    { push_expr('L', NULL); }
    break;

  case 1424:

/* Line 1806 of yacc.c  */
#line 9140 "parser.y"
    { push_expr('U', NULL); }
    break;

  case 1425:

/* Line 1806 of yacc.c  */
#line 9143 "parser.y"
    { push_expr('P', NULL); }
    break;

  case 1426:

/* Line 1806 of yacc.c  */
#line 9144 "parser.y"
    { push_expr('N', NULL); }
    break;

  case 1435:

/* Line 1806 of yacc.c  */
#line 9174 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1436:

/* Line 1806 of yacc.c  */
#line 9178 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1440:

/* Line 1806 of yacc.c  */
#line 9189 "parser.y"
    { (yyval) = cb_build_binary_op((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1441:

/* Line 1806 of yacc.c  */
#line 9190 "parser.y"
    { (yyval) = cb_build_binary_op((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1442:

/* Line 1806 of yacc.c  */
#line 9191 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1443:

/* Line 1806 of yacc.c  */
#line 9195 "parser.y"
    { (yyval) = cb_build_binary_op((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1444:

/* Line 1806 of yacc.c  */
#line 9196 "parser.y"
    { (yyval) = cb_build_binary_op((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1445:

/* Line 1806 of yacc.c  */
#line 9197 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1446:

/* Line 1806 of yacc.c  */
#line 9202 "parser.y"
    {
	(yyval) = cb_build_binary_op((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  }
    break;

  case 1447:

/* Line 1806 of yacc.c  */
#line 9205 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1448:

/* Line 1806 of yacc.c  */
#line 9209 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1449:

/* Line 1806 of yacc.c  */
#line 9210 "parser.y"
    { (yyval) = cb_build_binary_op(cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1450:

/* Line 1806 of yacc.c  */
#line 9211 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1451:

/* Line 1806 of yacc.c  */
#line 9214 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1452:

/* Line 1806 of yacc.c  */
#line 9215 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1453:

/* Line 1806 of yacc.c  */
#line 9226 "parser.y"
    {
	if(current_linage > 1) {
		cb_error(_("LINAGE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if(current_linage == 0) {
		cb_error(_("Invalid LINAGE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = linage_file->linage_ctr;
	}
  }
    break;

  case 1454:

/* Line 1806 of yacc.c  */
#line 9238 "parser.y"
    {
	if(CB_FILE_P(cb_ref((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE(cb_ref((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1455:

/* Line 1806 of yacc.c  */
#line 9247 "parser.y"
    {
	if(report_count > 1) {
		cb_error(_("LINE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if(report_count == 0) {
		cb_error(_("Invalid LINE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = report_instance->line_counter;
	}
  }
    break;

  case 1456:

/* Line 1806 of yacc.c  */
#line 9259 "parser.y"
    {
	if(CB_REPORT_P(cb_ref((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT(cb_ref((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1457:

/* Line 1806 of yacc.c  */
#line 9268 "parser.y"
    {
	if(report_count > 1) {
		cb_error(_("PAGE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if(report_count == 0) {
		cb_error(_("Invalid PAGE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = report_instance->page_counter;
	}
  }
    break;

  case 1458:

/* Line 1806 of yacc.c  */
#line 9280 "parser.y"
    {
	if(CB_REPORT_P(cb_ref((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT(cb_ref((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1459:

/* Line 1806 of yacc.c  */
#line 9294 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1460:

/* Line 1806 of yacc.c  */
#line 9296 "parser.y"
    { (yyval) = cb_list_append((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1461:

/* Line 1806 of yacc.c  */
#line 9301 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 1462:

/* Line 1806 of yacc.c  */
#line 9309 "parser.y"
    { cb_build_identifier((yyvsp[(1) - (1)]), 0); }
    break;

  case 1463:

/* Line 1806 of yacc.c  */
#line 9316 "parser.y"
    {
	cb_tree x = cb_ref((yyvsp[(1) - (1)]));
	if(!CB_FIELD_P(x)) {
		(yyval) = cb_error_node;
	} else if(!CB_FIELD(x)->index_list) {
		cb_error_x((yyvsp[(1) - (1)]), _("'%s' not indexed"), cb_name((yyvsp[(1) - (1)])));
		cb_error_x(x, _("'%s' defined here"), cb_name(x));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1464:

/* Line 1806 of yacc.c  */
#line 9334 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1465:

/* Line 1806 of yacc.c  */
#line 9338 "parser.y"
    {
	if(CB_VALID_TREE((yyvsp[(2) - (2)]))) {
		cb_tree l;
		for(l = (yyvsp[(1) - (2)]); l; l = CB_CHAIN(l)) {
			if(CB_VALID_TREE(CB_VALUE(l)) &&
			    !strcasecmp(CB_NAME((yyvsp[(2) - (2)])), CB_NAME(CB_VALUE(l)))) {
				cb_error_x((yyvsp[(2) - (2)]), _("Multiple reference to '%s' "),
					    CB_NAME((yyvsp[(2) - (2)])));
				break;
			}
		}
		if(!l) {
			(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  }
    break;

  case 1466:

/* Line 1806 of yacc.c  */
#line 9358 "parser.y"
    {
	if(CB_FILE_P(cb_ref((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1467:

/* Line 1806 of yacc.c  */
#line 9398 "parser.y"
    {
	if(CB_REPORT_P(cb_ref((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1468:

/* Line 1806 of yacc.c  */
#line 9411 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 1469:

/* Line 1806 of yacc.c  */
#line 9413 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1470:

/* Line 1806 of yacc.c  */
#line 9417 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1471:

/* Line 1806 of yacc.c  */
#line 9423 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1472:

/* Line 1806 of yacc.c  */
#line 9425 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1473:

/* Line 1806 of yacc.c  */
#line 9430 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->offset = current_section;
	CB_REFERENCE((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE((yyval))->section = current_section;
	CB_REFERENCE((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN((yyval), current_program->label_list);
  }
    break;

  case 1476:

/* Line 1806 of yacc.c  */
#line 9444 "parser.y"
    {
	CB_REFERENCE((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1477:

/* Line 1806 of yacc.c  */
#line 9451 "parser.y"
    {
	(yyval) = cb_build_reference((char *)(CB_LITERAL((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1478:

/* Line 1806 of yacc.c  */
#line 9461 "parser.y"
    { (yyval) = CB_LIST_INIT((yyvsp[(1) - (1)])); }
    break;

  case 1479:

/* Line 1806 of yacc.c  */
#line 9462 "parser.y"
    { (yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1480:

/* Line 1806 of yacc.c  */
#line 9467 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN((yyval), current_program->reference_list);
  }
    break;

  case 1481:

/* Line 1806 of yacc.c  */
#line 9475 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN((yyval), current_program->reference_list);
  }
    break;

  case 1482:

/* Line 1806 of yacc.c  */
#line 9483 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1483:

/* Line 1806 of yacc.c  */
#line 9487 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1484:

/* Line 1806 of yacc.c  */
#line 9494 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN((yyval), current_program->reference_list);
  }
    break;

  case 1487:

/* Line 1806 of yacc.c  */
#line 9510 "parser.y"
    {
	if(CB_WORD_COUNT((yyvsp[(1) - (1)])) > 0) {
		redefinition_error((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1488:

/* Line 1806 of yacc.c  */
#line 9524 "parser.y"
    {
	if(CB_REFERENCE((yyvsp[(1) - (1)]))->flag_duped || CB_WORD_COUNT((yyvsp[(1) - (1)])) > 0) {
		redefinition_error((yyvsp[(1) - (1)]));
		(yyval) = NULL;
	} else {
		CB_WORD_COUNT((yyvsp[(1) - (1)]))++;
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1489:

/* Line 1806 of yacc.c  */
#line 9541 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1490:

/* Line 1806 of yacc.c  */
#line 9545 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1493:

/* Line 1806 of yacc.c  */
#line 9554 "parser.y"
    {
	(yyval) = cb_build_address((yyvsp[(3) - (3)]));
  }
    break;

  case 1494:

/* Line 1806 of yacc.c  */
#line 9561 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1495:

/* Line 1806 of yacc.c  */
#line 9565 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1500:

/* Line 1806 of yacc.c  */
#line 9576 "parser.y"
    {
	(yyval) = cb_build_length((yyvsp[(2) - (2)]));
  }
    break;

  case 1501:

/* Line 1806 of yacc.c  */
#line 9580 "parser.y"
    {
	(yyval) = cb_build_length((yyvsp[(2) - (2)]));
  }
    break;

  case 1502:

/* Line 1806 of yacc.c  */
#line 9584 "parser.y"
    {
	(yyval) = cb_build_length((yyvsp[(2) - (2)]));
  }
    break;

  case 1503:

/* Line 1806 of yacc.c  */
#line 9588 "parser.y"
    {
	(yyval) = cb_build_ppointer((yyvsp[(4) - (4)]));
  }
    break;

  case 1504:

/* Line 1806 of yacc.c  */
#line 9592 "parser.y"
    {
	(yyval) = cb_build_address((yyvsp[(3) - (3)]));
  }
    break;

  case 1505:

/* Line 1806 of yacc.c  */
#line 9596 "parser.y"
    {
	cb_tree x = cb_ref((yyvsp[(1) - (1)]));
	if(CB_VALID_TREE(x)) {
		if(CB_SYSTEM_NAME(x)->category != CB_SWITCH_NAME) {
			cb_error_x(x, _("Invalid mnemonic identifier"));
			(yyval) = cb_error_node;
		} else {
			cb_tree switch_id = cb_int(CB_SYSTEM_NAME(x)->token);
			(yyval) = CB_BUILD_FUNCALL_1("cob_switch_value", switch_id);
		}
	} else {
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1506:

/* Line 1806 of yacc.c  */
#line 9614 "parser.y"
    {
	(yyval) = CB_LIST_INIT((yyvsp[(1) - (1)]));
  }
    break;

  case 1507:

/* Line 1806 of yacc.c  */
#line 9618 "parser.y"
    {
	(yyval) = cb_list_add((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1515:

/* Line 1806 of yacc.c  */
#line 9635 "parser.y"
    {
	(yyval) = cb_build_length((yyvsp[(2) - (2)]));
  }
    break;

  case 1516:

/* Line 1806 of yacc.c  */
#line 9639 "parser.y"
    {
	(yyval) = cb_build_length((yyvsp[(2) - (2)]));
  }
    break;

  case 1517:

/* Line 1806 of yacc.c  */
#line 9643 "parser.y"
    {
	(yyval) = cb_build_length((yyvsp[(2) - (2)]));
  }
    break;

  case 1533:

/* Line 1806 of yacc.c  */
#line 9690 "parser.y"
    {
	(yyval) = cb_zero;
  }
    break;

  case 1541:

/* Line 1806 of yacc.c  */
#line 9714 "parser.y"
    { (yyval) = cb_build_identifier((yyvsp[(1) - (1)]), 0); }
    break;

  case 1542:

/* Line 1806 of yacc.c  */
#line 9718 "parser.y"
    { (yyval) = cb_build_identifier((yyvsp[(1) - (1)]), 1); }
    break;

  case 1543:

/* Line 1806 of yacc.c  */
#line 9722 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1544:

/* Line 1806 of yacc.c  */
#line 9723 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1545:

/* Line 1806 of yacc.c  */
#line 9727 "parser.y"
    { (yyval) = cb_build_identifier((yyvsp[(1) - (1)]), 0); }
    break;

  case 1546:

/* Line 1806 of yacc.c  */
#line 9732 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1547:

/* Line 1806 of yacc.c  */
#line 9739 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1548:

/* Line 1806 of yacc.c  */
#line 9746 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1549:

/* Line 1806 of yacc.c  */
#line 9753 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1550:

/* Line 1806 of yacc.c  */
#line 9763 "parser.y"
    {
	(yyval) = cb_build_identifier((yyvsp[(1) - (1)]), 0);
  }
    break;

  case 1551:

/* Line 1806 of yacc.c  */
#line 9770 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if(CB_REFERENCE_P((yyvsp[(1) - (3)]))) {
		CB_REFERENCE((yyvsp[(1) - (3)]))->flag_target = 1;
	}
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (3)]));
	}
  }
    break;

  case 1552:

/* Line 1806 of yacc.c  */
#line 9780 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if(CB_REFERENCE_P((yyvsp[(1) - (2)]))) {
		CB_REFERENCE((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1553:

/* Line 1806 of yacc.c  */
#line 9790 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if(CB_REFERENCE_P((yyvsp[(1) - (2)]))) {
		CB_REFERENCE((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (2)]));
	}
  }
    break;

  case 1554:

/* Line 1806 of yacc.c  */
#line 9800 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if(CB_REFERENCE_P((yyvsp[(1) - (1)]))) {
		CB_REFERENCE((yyvsp[(1) - (1)]))->flag_target = 1;
	}
	if(start_debug) {
		cb_check_field_debug((yyvsp[(1) - (1)]));
	}
  }
    break;

  case 1555:

/* Line 1806 of yacc.c  */
#line 9813 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1556:

/* Line 1806 of yacc.c  */
#line 9817 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  }
    break;

  case 1557:

/* Line 1806 of yacc.c  */
#line 9825 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE((yyvsp[(0) - (3)]))->subs = cb_list_reverse((yyvsp[(2) - (3)]));
  }
    break;

  case 1558:

/* Line 1806 of yacc.c  */
#line 9833 "parser.y"
    {
	CB_REFERENCE((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1559:

/* Line 1806 of yacc.c  */
#line 9837 "parser.y"
    {
	CB_REFERENCE((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1560:

/* Line 1806 of yacc.c  */
#line 9847 "parser.y"
    {
	if(cb_tree_category((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error(_("Integer value expected"));
		(yyval) = cb_int1;
	} else if(CB_LITERAL((yyvsp[(1) - (1)]))->sign < 0 || CB_LITERAL((yyvsp[(1) - (1)]))->scale) {
		cb_error(_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  }
    break;

  case 1561:

/* Line 1806 of yacc.c  */
#line 9862 "parser.y"
    {
	if(cb_tree_category((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error(_("Integer value expected"));
		(yyval) = cb_int1;
	} else if(CB_LITERAL((yyvsp[(1) - (1)]))->sign || CB_LITERAL((yyvsp[(1) - (1)]))->scale) {
		cb_error(_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		int n = cb_get_int((yyvsp[(1) - (1)]));
		if(n < 1 || n > 256) {
			cb_error(_("Invalid SYMBOLIC integer"));
			(yyval) = cb_int1;
		} else {
			(yyval) = (yyvsp[(1) - (1)]);
		}
	}
  }
    break;

  case 1562:

/* Line 1806 of yacc.c  */
#line 9883 "parser.y"
    {
	if(cb_tree_category((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error(_("Integer value expected"));
		(yyval) = cb_int1;
	} else if(CB_LITERAL((yyvsp[(1) - (1)]))->sign || CB_LITERAL((yyvsp[(1) - (1)]))->scale) {
		cb_error(_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		int n = cb_get_int((yyvsp[(1) - (1)]));
		if(n < 1) {
			cb_error(_("Invalid integer"));
			(yyval) = cb_int1;
		} else {
			(yyval) = (yyvsp[(1) - (1)]);
		}
	}
  }
    break;

  case 1563:

/* Line 1806 of yacc.c  */
#line 9904 "parser.y"
    {
	if(cb_tree_category((yyvsp[(1) - (1)])) == CB_CATEGORY_NUMERIC) {
		if(CB_LITERAL((yyvsp[(1) - (1)]))->sign || CB_LITERAL((yyvsp[(1) - (1)]))->scale) {
			cb_error(_("Integer value expected"));
		} else {
			int n = cb_get_int((yyvsp[(1) - (1)]));
			if(n < 1 || n > 256) {
				cb_error(_("Invalid CLASS value"));
			}
		}
	}
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1564:

/* Line 1806 of yacc.c  */
#line 9917 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1565:

/* Line 1806 of yacc.c  */
#line 9918 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1566:

/* Line 1806 of yacc.c  */
#line 9919 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1567:

/* Line 1806 of yacc.c  */
#line 9920 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1568:

/* Line 1806 of yacc.c  */
#line 9921 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1569:

/* Line 1806 of yacc.c  */
#line 9922 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1570:

/* Line 1806 of yacc.c  */
#line 9927 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1571:

/* Line 1806 of yacc.c  */
#line 9931 "parser.y"
    {
	if(CB_LITERAL_P((yyvsp[(2) - (2)]))) {
		/* We must not alter the original definition */
		cb_literal * l = (cb_literal *) cobc_parse_malloc(sizeof(cb_literal));
		*l = *(CB_LITERAL((yyvsp[(2) - (2)])));
		l->all = 1;
		(yyval) = l;
	} else {
		(yyval) = (yyvsp[(2) - (2)]);
	}
  }
    break;

  case 1572:

/* Line 1806 of yacc.c  */
#line 9946 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1573:

/* Line 1806 of yacc.c  */
#line 9950 "parser.y"
    {
	(yyval) = cb_concat_literals((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1574:

/* Line 1806 of yacc.c  */
#line 9956 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1575:

/* Line 1806 of yacc.c  */
#line 9957 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1576:

/* Line 1806 of yacc.c  */
#line 9958 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1577:

/* Line 1806 of yacc.c  */
#line 9959 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1578:

/* Line 1806 of yacc.c  */
#line 9960 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1579:

/* Line 1806 of yacc.c  */
#line 9961 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1580:

/* Line 1806 of yacc.c  */
#line 9962 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1581:

/* Line 1806 of yacc.c  */
#line 9969 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  }
    break;

  case 1582:

/* Line 1806 of yacc.c  */
#line 9973 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (5)]), CB_LIST_INIT((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1583:

/* Line 1806 of yacc.c  */
#line 9977 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1584:

/* Line 1806 of yacc.c  */
#line 9981 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1585:

/* Line 1806 of yacc.c  */
#line 9985 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  }
    break;

  case 1586:

/* Line 1806 of yacc.c  */
#line 9989 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1587:

/* Line 1806 of yacc.c  */
#line 9993 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1588:

/* Line 1806 of yacc.c  */
#line 9997 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  }
    break;

  case 1589:

/* Line 1806 of yacc.c  */
#line 10001 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  }
    break;

  case 1590:

/* Line 1806 of yacc.c  */
#line 10005 "parser.y"
    {
	(yyval) = cb_build_intrinsic((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  }
    break;

  case 1599:

/* Line 1806 of yacc.c  */
#line 10029 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1600:

/* Line 1806 of yacc.c  */
#line 10033 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR((yyvsp[(2) - (4)]), NULL);
  }
    break;

  case 1601:

/* Line 1806 of yacc.c  */
#line 10037 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  }
    break;

  case 1602:

/* Line 1806 of yacc.c  */
#line 10044 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1603:

/* Line 1806 of yacc.c  */
#line 10048 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1604:

/* Line 1806 of yacc.c  */
#line 10052 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1605:

/* Line 1806 of yacc.c  */
#line 10059 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add(x, cb_int0);
  }
    break;

  case 1606:

/* Line 1806 of yacc.c  */
#line 10064 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add(x, cb_int1);
  }
    break;

  case 1607:

/* Line 1806 of yacc.c  */
#line 10069 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add(x, cb_int2);
  }
    break;

  case 1608:

/* Line 1806 of yacc.c  */
#line 10077 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add(x, cb_null);
  }
    break;

  case 1609:

/* Line 1806 of yacc.c  */
#line 10082 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add(x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1610:

/* Line 1806 of yacc.c  */
#line 10090 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add(x, cb_null);
  }
    break;

  case 1611:

/* Line 1806 of yacc.c  */
#line 10095 "parser.y"
    {
	cb_tree	x = CB_LIST_INIT((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add(x, cb_ref((yyvsp[(3) - (3)])));
  }
    break;

  case 1612:

/* Line 1806 of yacc.c  */
#line 10104 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1613:

/* Line 1806 of yacc.c  */
#line 10112 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1614:

/* Line 1806 of yacc.c  */
#line 10113 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1615:

/* Line 1806 of yacc.c  */
#line 10117 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1616:

/* Line 1806 of yacc.c  */
#line 10118 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1617:

/* Line 1806 of yacc.c  */
#line 10122 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1618:

/* Line 1806 of yacc.c  */
#line 10123 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1619:

/* Line 1806 of yacc.c  */
#line 10128 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1620:

/* Line 1806 of yacc.c  */
#line 10132 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1621:

/* Line 1806 of yacc.c  */
#line 10139 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1622:

/* Line 1806 of yacc.c  */
#line 10143 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 1623:

/* Line 1806 of yacc.c  */
#line 10150 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1624:

/* Line 1806 of yacc.c  */
#line 10151 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1625:

/* Line 1806 of yacc.c  */
#line 10152 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1626:

/* Line 1806 of yacc.c  */
#line 10156 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1627:

/* Line 1806 of yacc.c  */
#line 10157 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 1628:

/* Line 1806 of yacc.c  */
#line 10161 "parser.y"
    { (yyval) = cb_int(cb_flag_optional_file); }
    break;

  case 1629:

/* Line 1806 of yacc.c  */
#line 10162 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1630:

/* Line 1806 of yacc.c  */
#line 10163 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1631:

/* Line 1806 of yacc.c  */
#line 10168 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1632:

/* Line 1806 of yacc.c  */
#line 10172 "parser.y"
    {
	if((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int(COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  }
    break;

  case 1633:

/* Line 1806 of yacc.c  */
#line 10184 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  }
    break;

  case 1634:

/* Line 1806 of yacc.c  */
#line 10189 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  }
    break;

  case 1635:

/* Line 1806 of yacc.c  */
#line 10197 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  }
    break;

  case 1636:

/* Line 1806 of yacc.c  */
#line 10201 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  }
    break;

  case 1637:

/* Line 1806 of yacc.c  */
#line 10205 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  }
    break;

  case 1638:

/* Line 1806 of yacc.c  */
#line 10209 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  }
    break;

  case 1639:

/* Line 1806 of yacc.c  */
#line 10213 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_PROHIBITED);
  }
    break;

  case 1640:

/* Line 1806 of yacc.c  */
#line 10217 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  }
    break;

  case 1641:

/* Line 1806 of yacc.c  */
#line 10221 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  }
    break;

  case 1642:

/* Line 1806 of yacc.c  */
#line 10225 "parser.y"
    {
	(yyval) = cb_int(COB_STORE_ROUND | COB_STORE_TRUNCATION);
  }
    break;

  case 1643:

/* Line 1806 of yacc.c  */
#line 10231 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1644:

/* Line 1806 of yacc.c  */
#line 10232 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1806 of yacc.c  */
#line 18324 "parser.cpp"
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
#line 10403 "parser.y"


