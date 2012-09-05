/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 336 of yacc.c  */
#line 26 "parser.y"

#include "config.h"

#include <stdlib.h>
#include <string.h>

#include "cobc.h"
#include "tree.h"

#define yyerror			cb_error
#define YYDEBUG			1
#define YYERROR_VERBOSE		1

#define PENDING(x)		cb_warning (_("'%s' not implemented"), x)

#define emit_statement(x) \
  current_program->exec_list = cb_cons (x, current_program->exec_list)

#define push_expr(type, node) \
  current_expr = cb_build_list (cb_int (type), node, current_expr)

#define TERM_NONE		0
#define TERM_ACCEPT		1
#define TERM_ADD		2
#define TERM_CALL		3
#define TERM_COMPUTE		4
#define TERM_DELETE		5
#define TERM_DISPLAY		6
#define TERM_DIVIDE		7
#define TERM_EVALUATE		8
#define TERM_IF			9
#define TERM_MULTIPLY		10
#define TERM_PERFORM		11
#define TERM_READ		12
#define TERM_RECEIVE		13
#define TERM_RETURN		14
#define TERM_REWRITE		15
#define TERM_SEARCH		16
#define TERM_START		17
#define TERM_STRING		18
#define TERM_SUBTRACT		19
#define TERM_UNSTRING		20
#define TERM_WRITE		21
#define TERM_MAX		22

/* Global variables */

struct cb_program		*current_program = NULL;
struct cb_statement		*current_statement = NULL;
struct cb_label			*current_section = NULL;
struct cb_label			*current_paragraph = NULL;
size_t				functions_are_all = 0;
int				non_const_word = 0;

/* Local variables */

static struct cb_statement	*main_statement;

static cb_tree			current_expr;
static struct cb_field		*current_field;
static struct cb_field		*description_field;
static struct cb_file		*current_file;

static enum cb_storage		current_storage;

static size_t			check_unreached = 0;
static int			call_mode;
static int			size_mode;

static cb_tree			perform_stack = NULL;
static cb_tree			qualifier = NULL;

static cb_tree			fgc;
static cb_tree			bgc;
static cb_tree			scroll;
static cb_tree			save_tree_1;
static cb_tree			save_tree_2;
static cb_tree			dummy_tree;
static size_t			in_declaratives = 0;
static size_t			current_linage = 0;
static size_t			prog_end = 0;
static size_t			use_global_ind = 0;
static size_t			samearea = 1;
static size_t			organized_seen = 0;
static size_t			inspect_keyword = 0;
static int			next_label_id = 0;
static int			eval_level = 0;
static int			eval_inc = 0;
static int			eval_inc2 = 0;
static int			depth = 0;
static int			dispattrs = 0;
static struct cb_file		*linage_file;
static cb_tree			next_label_list = NULL;
static char			*stack_progid[32];
static int			term_array[TERM_MAX];
static int			eval_check[64][64];

/* Static functions */

static void
BEGIN_STATEMENT (const char *name, const size_t term)
{
	if (cb_warn_unreachable && check_unreached) {
		cb_warning (_("Unreachable statement"));
	}
	current_statement = cb_build_statement ((char *)name);
	CB_TREE (current_statement)->source_file = (unsigned char *)cb_source_file;
	CB_TREE (current_statement)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_statement));
	if (term) {
		term_array[term]++;
	}
	main_statement = current_statement;
}

static void
BEGIN_IMPLICIT_STATEMENT (void)
{
	current_statement = cb_build_statement (NULL);
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
	char		buff[256];

	sprintf (buff, "E$%s", name);
	label = cb_build_label (cb_build_reference (buff), NULL);
	if (encode) {
		CB_LABEL (label)->name = (unsigned char *)(cb_encode_program_id (name));
		CB_LABEL (label)->orig_name = (unsigned char *)name;
	} else {
		CB_LABEL (label)->name = (unsigned char *)name;
		CB_LABEL (label)->orig_name = (unsigned char *)current_program->orig_source_name;
	}
	CB_LABEL (label)->need_begin = 1;
	CB_LABEL (label)->is_entry = 1;
	emit_statement (label);

	parmnum = 1;
	for (l = using_list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (x != cb_error_node && cb_ref (x) != cb_error_node) {
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
			for (l = using_list; l; l = CB_CHAIN (l)) {
				x = CB_VALUE (l);
				if (x != cb_error_node && cb_ref (x) != cb_error_node) {
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

	for (l = current_program->entry_list; l; l = CB_CHAIN (l)) {
		if (strcmp ((const char *)name, (const char *)(CB_LABEL(CB_PURPOSE(l))->name)) == 0) {
			cb_error_x (CB_TREE (current_statement), _("ENTRY '%s' duplicated"), name);
		}
	}

	current_program->entry_list = cb_list_append (current_program->entry_list,
							cb_build_pair (label, using_list));
}

static void
terminator_warning (const size_t termid)
{
	check_unreached = 0;
	if (cb_warn_terminator && term_array[termid]) {
		cb_warning_x (CB_TREE (current_statement),
			_("%s statement not terminated by END-%s"),
			current_statement->name, current_statement->name);
	}
	if (term_array[termid]) {
		term_array[termid]--;
	}
}

static void
terminator_error (void)
{
	check_unreached = 0;
	cb_error_x (CB_TREE (current_statement),
			_("%s statement not terminated by END-%s"),
			current_statement->name, current_statement->name);
}

static void
terminator_clear (const size_t termid)
{
	check_unreached = 0;
	if (term_array[termid]) {
		term_array[termid]--;
	}
}

static int
literal_value (cb_tree x)
{
	if (x == cb_space) {
		return ' ';
	} else if (x == cb_zero) {
		return '0';
	} else if (x == cb_quote) {
		return '"';
	} else if (x == cb_null) {
		return 0;
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
	if (fileptr->global) {
		newptr = cobc_malloc (sizeof(struct cb_file));
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



/* Line 336 of yacc.c  */
#line 352 "parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_PARSER_H
# define YY_PARSER_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
     ASSIGN = 283,
     AT = 284,
     AUTO = 285,
     AUTOMATIC = 286,
     BACKGROUND_COLOR = 287,
     BASED = 288,
     BEFORE = 289,
     BELL = 290,
     BINARY = 291,
     BINARY_C_LONG = 292,
     BINARY_CHAR = 293,
     BINARY_DOUBLE = 294,
     BINARY_LONG = 295,
     BINARY_SHORT = 296,
     BLANK = 297,
     BLANK_LINE = 298,
     BLANK_SCREEN = 299,
     BLINK = 300,
     BLOCK = 301,
     BOTTOM = 302,
     BY = 303,
     BYTE_LENGTH = 304,
     CALL = 305,
     CANCEL = 306,
     CH = 307,
     CHAINING = 308,
     CHARACTER = 309,
     CHARACTERS = 310,
     CLASS = 311,
     CLOSE = 312,
     CODE = 313,
     CODE_SET = 314,
     COLLATING = 315,
     COL = 316,
     COLS = 317,
     COLUMN = 318,
     COLUMNS = 319,
     COMMA = 320,
     COMMAND_LINE = 321,
     COMMA_DELIM = 322,
     COMMIT = 323,
     COMMON = 324,
     COMP = 325,
     COMPUTE = 326,
     COMP_1 = 327,
     COMP_2 = 328,
     COMP_3 = 329,
     COMP_4 = 330,
     COMP_5 = 331,
     COMP_X = 332,
     CONCATENATE_FUNC = 333,
     CONFIGURATION = 334,
     CONSTANT = 335,
     CONTAINS = 336,
     CONTENT = 337,
     CONTINUE = 338,
     CONTROL = 339,
     CONTROLS = 340,
     CONTROL_FOOTING = 341,
     CONTROL_HEADING = 342,
     CONVERTING = 343,
     CORRESPONDING = 344,
     COUNT = 345,
     CRT = 346,
     CURRENCY = 347,
     CURRENT_DATE_FUNC = 348,
     CURSOR = 349,
     CYCLE = 350,
     DATA = 351,
     DATE = 352,
     DAY = 353,
     DAY_OF_WEEK = 354,
     DE = 355,
     DEBUGGING = 356,
     DECIMAL_POINT = 357,
     DECLARATIVES = 358,
     DEFAULT = 359,
     DELETE = 360,
     DELIMITED = 361,
     DELIMITER = 362,
     DEPENDING = 363,
     DESCENDING = 364,
     DETAIL = 365,
     DISK = 366,
     DISPLAY = 367,
     DIVIDE = 368,
     DIVISION = 369,
     DOWN = 370,
     DUPLICATES = 371,
     DYNAMIC = 372,
     EBCDIC = 373,
     ELSE = 374,
     END = 375,
     END_ACCEPT = 376,
     END_ADD = 377,
     END_CALL = 378,
     END_COMPUTE = 379,
     END_DELETE = 380,
     END_DISPLAY = 381,
     END_DIVIDE = 382,
     END_EVALUATE = 383,
     END_FUNCTION = 384,
     END_IF = 385,
     END_MULTIPLY = 386,
     END_PERFORM = 387,
     END_PROGRAM = 388,
     END_READ = 389,
     END_RETURN = 390,
     END_REWRITE = 391,
     END_SEARCH = 392,
     END_START = 393,
     END_STRING = 394,
     END_SUBTRACT = 395,
     END_UNSTRING = 396,
     END_WRITE = 397,
     ENTRY = 398,
     ENVIRONMENT = 399,
     ENVIRONMENT_NAME = 400,
     ENVIRONMENT_VALUE = 401,
     EOL = 402,
     EOP = 403,
     EOS = 404,
     EQUAL = 405,
     EQUALS = 406,
     ERASE = 407,
     ERROR = 408,
     ESCAPE = 409,
     EVALUATE = 410,
     EVENT_STATUS = 411,
     EXCEPTION = 412,
     EXCLUSIVE = 413,
     EXIT = 414,
     EXTEND = 415,
     EXTERNAL = 416,
     FD = 417,
     FILE_CONTROL = 418,
     FILE_ID = 419,
     FILLER = 420,
     FINAL = 421,
     FIRST = 422,
     FOOTING = 423,
     FOR = 424,
     FOREGROUND_COLOR = 425,
     FOREVER = 426,
     FREE = 427,
     FROM = 428,
     FULL = 429,
     FUNCTION = 430,
     FUNCTION_ID = 431,
     FUNCTION_NAME = 432,
     GE = 433,
     GENERATE = 434,
     GIVING = 435,
     GLOBAL = 436,
     GO = 437,
     GOBACK = 438,
     GREATER = 439,
     GROUP = 440,
     HEADING = 441,
     HIGHLIGHT = 442,
     HIGH_VALUE = 443,
     IDENTIFICATION = 444,
     IF = 445,
     IGNORE = 446,
     IGNORING = 447,
     IN = 448,
     INDEX = 449,
     INDEXED = 450,
     INDICATE = 451,
     INITIALIZE = 452,
     INITIALIZED = 453,
     INITIATE = 454,
     INPUT = 455,
     INPUT_OUTPUT = 456,
     INSPECT = 457,
     INTO = 458,
     INTRINSIC = 459,
     INVALID = 460,
     INVALID_KEY = 461,
     IS = 462,
     I_O = 463,
     I_O_CONTROL = 464,
     JUSTIFIED = 465,
     KEY = 466,
     LABEL = 467,
     LAST = 468,
     LAST_DETAIL = 469,
     LE = 470,
     LEADING = 471,
     LEFT = 472,
     LENGTH = 473,
     LESS = 474,
     LIMIT = 475,
     LIMITS = 476,
     LINAGE = 477,
     LINAGE_COUNTER = 478,
     LINE = 479,
     LINES = 480,
     LINKAGE = 481,
     LITERAL = 482,
     LOCALE = 483,
     LOCALE_DT_FUNC = 484,
     LOCAL_STORAGE = 485,
     LOCK = 486,
     LOWER_CASE_FUNC = 487,
     LOWLIGHT = 488,
     LOW_VALUE = 489,
     MANUAL = 490,
     MEMORY = 491,
     MERGE = 492,
     MINUS = 493,
     MNEMONIC_NAME = 494,
     MODE = 495,
     MOVE = 496,
     MULTIPLE = 497,
     MULTIPLY = 498,
     NATIONAL = 499,
     NATIONAL_EDITED = 500,
     NATIVE = 501,
     NE = 502,
     NEGATIVE = 503,
     NEXT = 504,
     NEXT_SENTENCE = 505,
     NO = 506,
     NOT = 507,
     NOT_END = 508,
     NOT_EOP = 509,
     NOT_EXCEPTION = 510,
     NOT_INVALID_KEY = 511,
     NOT_OVERFLOW = 512,
     NOT_SIZE_ERROR = 513,
     NO_ADVANCING = 514,
     NUMBER = 515,
     NUMBERS = 516,
     NUMERIC = 517,
     NUMERIC_EDITED = 518,
     NUMVALC_FUNC = 519,
     OBJECT_COMPUTER = 520,
     OCCURS = 521,
     OF = 522,
     OFF = 523,
     OMITTED = 524,
     ON = 525,
     ONLY = 526,
     OPEN = 527,
     OPTIONAL = 528,
     OR = 529,
     ORDER = 530,
     ORGANIZATION = 531,
     OTHER = 532,
     OUTPUT = 533,
     OVERFLOW = 534,
     OVERLINE = 535,
     PACKED_DECIMAL = 536,
     PADDING = 537,
     PAGE = 538,
     PAGE_FOOTING = 539,
     PAGE_HEADING = 540,
     PARAGRAPH = 541,
     PERFORM = 542,
     PICTURE = 543,
     PLUS = 544,
     POINTER = 545,
     POSITION = 546,
     POSITIVE = 547,
     PRESENT = 548,
     PREVIOUS = 549,
     PRINTER = 550,
     PRINTING = 551,
     PROCEDURE = 552,
     PROCEDURES = 553,
     PROCEED = 554,
     PROGRAM = 555,
     PROGRAM_ID = 556,
     PROGRAM_NAME = 557,
     PROGRAM_POINTER = 558,
     PROMPT = 559,
     QUOTE = 560,
     RANDOM = 561,
     RD = 562,
     READ = 563,
     RECORD = 564,
     RECORDING = 565,
     RECORDS = 566,
     RECURSIVE = 567,
     REDEFINES = 568,
     REEL = 569,
     REFERENCE = 570,
     RELATIVE = 571,
     RELEASE = 572,
     REMAINDER = 573,
     REMOVAL = 574,
     RENAMES = 575,
     REPLACING = 576,
     REPORT = 577,
     REPORTING = 578,
     REPORTS = 579,
     REPORT_FOOTING = 580,
     REPORT_HEADING = 581,
     REPOSITORY = 582,
     REQUIRED = 583,
     RESERVE = 584,
     RETURN = 585,
     RETURNING = 586,
     REVERSE_FUNC = 587,
     REVERSE_VIDEO = 588,
     REWIND = 589,
     REWRITE = 590,
     RIGHT = 591,
     ROLLBACK = 592,
     ROUNDED = 593,
     RUN = 594,
     SAME = 595,
     SCREEN = 596,
     SCREEN_CONTROL = 597,
     SCROLL = 598,
     SD = 599,
     SEARCH = 600,
     SECTION = 601,
     SECURE = 602,
     SEGMENT_LIMIT = 603,
     SELECT = 604,
     SEMI_COLON = 605,
     SENTENCE = 606,
     SEPARATE = 607,
     SEQUENCE = 608,
     SEQUENTIAL = 609,
     SET = 610,
     SHARING = 611,
     SIGN = 612,
     SIGNED = 613,
     SIGNED_INT = 614,
     SIGNED_LONG = 615,
     SIGNED_SHORT = 616,
     SIZE = 617,
     SIZE_ERROR = 618,
     SORT = 619,
     SORT_MERGE = 620,
     SOURCE = 621,
     SOURCE_COMPUTER = 622,
     SPACE = 623,
     SPECIAL_NAMES = 624,
     STANDARD = 625,
     STANDARD_1 = 626,
     STANDARD_2 = 627,
     START = 628,
     STATUS = 629,
     STOP = 630,
     STRING = 631,
     SUBSTITUTE_FUNC = 632,
     SUBSTITUTE_CASE_FUNC = 633,
     SUBTRACT = 634,
     SUM = 635,
     SUPPRESS = 636,
     SYMBOLIC = 637,
     SYNCHRONIZED = 638,
     TALLYING = 639,
     TAPE = 640,
     TERMINATE = 641,
     TEST = 642,
     THAN = 643,
     THEN = 644,
     THRU = 645,
     TIME = 646,
     TIMES = 647,
     TO = 648,
     TOK_FALSE = 649,
     TOK_FILE = 650,
     TOK_INITIAL = 651,
     TOK_NULL = 652,
     TOK_TRUE = 653,
     TOP = 654,
     TRAILING = 655,
     TRANSFORM = 656,
     TRIM_FUNCTION = 657,
     TYPE = 658,
     UNDERLINE = 659,
     UNIT = 660,
     UNLOCK = 661,
     UNSIGNED = 662,
     UNSIGNED_INT = 663,
     UNSIGNED_LONG = 664,
     UNSIGNED_SHORT = 665,
     UNSTRING = 666,
     UNTIL = 667,
     UP = 668,
     UPDATE = 669,
     UPON = 670,
     UPON_ARGUMENT_NUMBER = 671,
     UPON_COMMAND_LINE = 672,
     UPON_ENVIRONMENT_NAME = 673,
     UPON_ENVIRONMENT_VALUE = 674,
     UPPER_CASE_FUNC = 675,
     USAGE = 676,
     USE = 677,
     USING = 678,
     VALUE = 679,
     VARYING = 680,
     WAIT = 681,
     WHEN = 682,
     WHEN_COMPILED_FUNC = 683,
     WITH = 684,
     WORD = 685,
     WORDS = 686,
     WORKING_STORAGE = 687,
     WRITE = 688,
     YYYYDDD = 689,
     YYYYMMDD = 690,
     ZERO = 691,
     UNARY_SIGN = 692
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_PARSER_H  */

/* Copy the second part of user declarations.  */


/* Line 353 of yacc.c  */
#line 857 "parser.c"

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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  451
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  690
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1519
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2241

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   692

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   450,     2,
     445,   446,   439,   437,     2,   438,   443,   440,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   449,     2,
     448,   444,   447,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   442,     2,     2,     2,     2,     2,
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
     435,   436,   441
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    17,
      18,    27,    28,    29,    38,    39,    40,    48,    49,    51,
      54,    55,    59,    63,    67,    68,    76,    82,    84,    86,
      87,    90,    91,    95,    97,   100,   102,   104,   106,   107,
     113,   114,   119,   120,   123,   125,   127,   129,   131,   135,
     136,   139,   143,   146,   150,   152,   156,   157,   160,   164,
     167,   169,   172,   174,   176,   178,   184,   186,   188,   193,
     197,   201,   202,   205,   207,   210,   214,   218,   220,   223,
     227,   228,   231,   233,   236,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   258,   262,   263,   269,   270,
     276,   278,   280,   281,   287,   289,   291,   293,   295,   297,
     299,   302,   304,   308,   309,   314,   316,   320,   322,   324,
     326,   328,   330,   332,   334,   336,   338,   340,   342,   344,
     348,   352,   354,   357,   359,   362,   367,   369,   372,   374,
     378,   383,   388,   392,   396,   401,   405,   409,   410,   416,
     417,   422,   423,   428,   429,   433,   434,   437,   438,   445,
     446,   449,   451,   453,   455,   457,   459,   461,   463,   465,
     467,   469,   471,   473,   475,   481,   486,   487,   489,   491,
     492,   494,   496,   498,   500,   502,   507,   509,   511,   513,
     520,   524,   530,   531,   533,   535,   540,   543,   546,   548,
     549,   554,   560,   563,   565,   567,   571,   573,   575,   579,
     581,   583,   586,   591,   596,   601,   603,   607,   612,   617,
     621,   625,   628,   631,   634,   635,   639,   640,   643,   645,
     648,   650,   652,   658,   659,   661,   663,   665,   671,   673,
     676,   679,   680,   683,   684,   694,   695,   696,   702,   703,
     707,   708,   711,   715,   718,   721,   723,   725,   726,   731,
     732,   735,   738,   741,   743,   745,   747,   749,   751,   753,
     755,   757,   759,   765,   766,   768,   770,   775,   782,   792,
     793,   797,   798,   801,   802,   805,   809,   811,   813,   819,
     825,   827,   829,   833,   839,   840,   843,   845,   847,   849,
     855,   860,   864,   869,   873,   877,   881,   882,   883,   889,
     890,   892,   893,   896,   900,   905,   908,   910,   911,   916,
     918,   919,   921,   923,   925,   926,   929,   931,   935,   939,
     946,   947,   950,   952,   954,   956,   958,   960,   962,   964,
     966,   968,   970,   972,   974,   976,   978,   981,   985,   986,
     989,   992,   994,   996,  1000,  1002,  1004,  1006,  1008,  1010,
    1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,  1028,  1030,
    1032,  1034,  1036,  1038,  1041,  1044,  1046,  1049,  1052,  1054,
    1057,  1060,  1062,  1065,  1068,  1070,  1073,  1076,  1078,  1080,
    1084,  1088,  1096,  1097,  1100,  1101,  1105,  1107,  1108,  1114,
    1116,  1118,  1119,  1123,  1125,  1128,  1130,  1133,  1136,  1137,
    1139,  1141,  1145,  1147,  1148,  1157,  1159,  1162,  1164,  1168,
    1169,  1173,  1176,  1181,  1184,  1185,  1186,  1192,  1193,  1194,
    1200,  1201,  1202,  1208,  1209,  1211,  1213,  1216,  1222,  1223,
    1226,  1229,  1233,  1235,  1237,  1240,  1243,  1246,  1247,  1249,
    1251,  1254,  1263,  1264,  1268,  1269,  1274,  1275,  1280,  1281,
    1285,  1286,  1290,  1292,  1297,  1300,  1302,  1304,  1305,  1308,
    1313,  1314,  1317,  1319,  1321,  1323,  1325,  1327,  1329,  1331,
    1333,  1335,  1337,  1339,  1341,  1343,  1345,  1347,  1349,  1353,
    1355,  1357,  1359,  1361,  1363,  1365,  1367,  1372,  1377,  1380,
    1382,  1384,  1387,  1391,  1393,  1397,  1404,  1407,  1411,  1414,
    1416,  1419,  1422,  1424,  1427,  1428,  1430,  1432,  1437,  1440,
    1441,  1443,  1445,  1446,  1447,  1448,  1455,  1456,  1458,  1460,
    1463,  1465,  1466,  1472,  1473,  1476,  1478,  1480,  1482,  1484,
    1487,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,
    1508,  1510,  1516,  1522,  1526,  1530,  1532,  1534,  1536,  1538,
    1540,  1542,  1544,  1547,  1550,  1553,  1554,  1556,  1558,  1560,
    1562,  1563,  1565,  1567,  1569,  1571,  1575,  1576,  1577,  1578,
    1588,  1589,  1590,  1594,  1595,  1599,  1601,  1604,  1609,  1610,
    1613,  1616,  1617,  1621,  1625,  1630,  1634,  1635,  1637,  1638,
    1641,  1642,  1643,  1651,  1652,  1655,  1657,  1659,  1661,  1664,
    1667,  1669,  1674,  1677,  1679,  1681,  1682,  1684,  1685,  1686,
    1690,  1691,  1694,  1697,  1699,  1701,  1703,  1705,  1707,  1709,
    1711,  1713,  1715,  1717,  1719,  1721,  1723,  1725,  1727,  1729,
    1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,  1749,
    1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1767,  1769,
    1771,  1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,  1789,
    1791,  1793,  1795,  1796,  1801,  1806,  1811,  1815,  1819,  1823,
    1828,  1832,  1837,  1841,  1845,  1849,  1854,  1860,  1864,  1869,
    1873,  1877,  1878,  1882,  1886,  1889,  1892,  1895,  1899,  1903,
    1907,  1908,  1911,  1913,  1916,  1918,  1920,  1922,  1924,  1926,
    1928,  1930,  1934,  1938,  1942,  1946,  1948,  1950,  1952,  1954,
    1956,  1958,  1959,  1961,  1962,  1967,  1972,  1978,  1985,  1986,
    1989,  1990,  1992,  1993,  1997,  2001,  2007,  2008,  2011,  2014,
    2015,  2021,  2022,  2025,  2026,  2035,  2036,  2037,  2041,  2043,
    2046,  2049,  2053,  2054,  2057,  2060,  2063,  2064,  2067,  2070,
    2071,  2072,  2076,  2077,  2078,  2082,  2083,  2085,  2086,  2090,
    2091,  2094,  2095,  2099,  2100,  2104,  2105,  2107,  2111,  2115,
    2118,  2120,  2122,  2123,  2128,  2133,  2134,  2136,  2138,  2140,
    2142,  2144,  2145,  2152,  2153,  2155,  2156,  2161,  2165,  2169,
    2173,  2177,  2183,  2184,  2187,  2190,  2193,  2196,  2197,  2200,
    2203,  2205,  2208,  2210,  2212,  2215,  2218,  2220,  2222,  2224,
    2226,  2228,  2232,  2236,  2240,  2244,  2246,  2248,  2249,  2251,
    2252,  2257,  2262,  2269,  2276,  2285,  2294,  2295,  2297,  2298,
    2303,  2304,  2310,  2312,  2316,  2318,  2320,  2322,  2325,  2327,
    2330,  2331,  2335,  2336,  2337,  2342,  2345,  2349,  2351,  2355,
    2358,  2360,  2362,  2364,  2365,  2368,  2369,  2371,  2372,  2376,
    2377,  2379,  2381,  2384,  2386,  2388,  2389,  2393,  2394,  2398,
    2399,  2405,  2406,  2410,  2411,  2414,  2415,  2416,  2425,  2429,
    2430,  2431,  2435,  2436,  2438,  2439,  2447,  2448,  2451,  2452,
    2456,  2460,  2461,  2464,  2466,  2469,  2474,  2476,  2478,  2480,
    2482,  2484,  2486,  2488,  2489,  2491,  2492,  2496,  2497,  2502,
    2504,  2506,  2508,  2510,  2513,  2515,  2517,  2519,  2520,  2524,
    2526,  2529,  2532,  2535,  2537,  2539,  2541,  2544,  2547,  2549,
    2552,  2557,  2560,  2561,  2563,  2565,  2567,  2569,  2574,  2580,
    2581,  2586,  2587,  2589,  2590,  2594,  2595,  2599,  2603,  2608,
    2609,  2614,  2619,  2626,  2627,  2629,  2630,  2634,  2635,  2641,
    2643,  2645,  2647,  2649,  2650,  2654,  2655,  2659,  2662,  2663,
    2667,  2670,  2671,  2676,  2679,  2680,  2682,  2684,  2688,  2689,
    2691,  2694,  2698,  2702,  2703,  2707,  2709,  2713,  2721,  2722,
    2733,  2734,  2737,  2738,  2741,  2744,  2748,  2752,  2755,  2756,
    2760,  2761,  2763,  2765,  2766,  2768,  2769,  2774,  2775,  2783,
    2784,  2786,  2787,  2795,  2796,  2799,  2803,  2804,  2806,  2808,
    2809,  2814,  2819,  2820,  2828,  2829,  2832,  2833,  2834,  2839,
    2841,  2844,  2845,  2850,  2851,  2853,  2854,  2858,  2860,  2862,
    2864,  2866,  2868,  2873,  2878,  2882,  2887,  2889,  2891,  2893,
    2896,  2900,  2902,  2905,  2909,  2913,  2914,  2918,  2919,  2927,
    2928,  2934,  2935,  2938,  2939,  2942,  2943,  2947,  2948,  2951,
    2956,  2957,  2960,  2965,  2966,  2967,  2975,  2976,  2981,  2984,
    2987,  2990,  2993,  2996,  2997,  2999,  3000,  3005,  3008,  3009,
    3012,  3015,  3016,  3025,  3027,  3030,  3032,  3036,  3040,  3041,
    3045,  3046,  3048,  3049,  3054,  3059,  3066,  3073,  3074,  3076,
    3079,  3080,  3082,  3083,  3087,  3088,  3096,  3097,  3102,  3103,
    3105,  3107,  3108,  3118,  3119,  3123,  3125,  3129,  3132,  3135,
    3138,  3142,  3143,  3147,  3148,  3152,  3153,  3157,  3158,  3160,
    3162,  3164,  3166,  3175,  3176,  3178,  3180,  3182,  3184,  3186,
    3188,  3189,  3191,  3192,  3194,  3196,  3198,  3200,  3202,  3204,
    3206,  3207,  3209,  3215,  3217,  3220,  3226,  3227,  3236,  3237,
    3240,  3241,  3246,  3250,  3254,  3256,  3258,  3259,  3261,  3263,
    3264,  3266,  3269,  3272,  3273,  3274,  3278,  3279,  3280,  3284,
    3287,  3288,  3289,  3293,  3294,  3295,  3299,  3302,  3303,  3304,
    3308,  3309,  3310,  3314,  3316,  3318,  3321,  3322,  3326,  3327,
    3331,  3333,  3335,  3338,  3339,  3343,  3344,  3348,  3349,  3351,
    3353,  3355,  3358,  3359,  3363,  3364,  3368,  3369,  3373,  3375,
    3377,  3378,  3381,  3383,  3386,  3389,  3391,  3393,  3395,  3397,
    3399,  3401,  3403,  3405,  3407,  3409,  3411,  3413,  3415,  3417,
    3419,  3421,  3423,  3425,  3427,  3429,  3431,  3433,  3435,  3437,
    3439,  3442,  3444,  3446,  3449,  3451,  3454,  3456,  3462,  3464,
    3470,  3472,  3476,  3477,  3479,  3481,  3483,  3487,  3491,  3495,
    3499,  3502,  3505,  3509,  3513,  3515,  3519,  3521,  3524,  3527,
    3529,  3531,  3533,  3536,  3538,  3540,  3543,  3545,  3546,  3549,
    3551,  3553,  3555,  3559,  3561,  3563,  3566,  3568,  3569,  3571,
    3573,  3575,  3577,  3579,  3582,  3584,  3588,  3590,  3593,  3595,
    3599,  3603,  3607,  3612,  3616,  3618,  3620,  3622,  3624,  3628,
    3632,  3636,  3638,  3640,  3642,  3644,  3646,  3648,  3650,  3652,
    3654,  3656,  3658,  3660,  3662,  3664,  3666,  3668,  3670,  3672,
    3674,  3676,  3678,  3681,  3684,  3688,  3690,  3694,  3698,  3703,
    3709,  3711,  3713,  3716,  3718,  3722,  3724,  3726,  3728,  3730,
    3732,  3734,  3736,  3739,  3742,  3748,  3754,  3760,  3766,  3772,
    3778,  3784,  3789,  3795,  3798,  3799,  3804,  3810,  3811,  3815,
    3816,  3818,  3820,  3824,  3828,  3830,  3834,  3836,  3840,  3841,
    3842,  3844,  3845,  3847,  3848,  3850,  3851,  3853,  3855,  3856,
    3858,  3859,  3861,  3862,  3864,  3865,  3868,  3870,  3872,  3875,
    3878,  3881,  3883,  3886,  3888,  3889,  3891,  3892,  3894,  3895,
    3897,  3898,  3900,  3901,  3903,  3904,  3906,  3907,  3909,  3910,
    3912,  3913,  3915,  3916,  3918,  3919,  3921,  3922,  3924,  3925,
    3927,  3928,  3930,  3931,  3933,  3934,  3936,  3937,  3939,  3941,
    3942,  3944,  3945,  3947,  3949,  3950,  3952,  3953,  3955,  3956,
    3958,  3959,  3961,  3962,  3964,  3965,  3967,  3970,  3971,  3973,
    3974,  3976,  3977,  3979,  3980,  3982,  3983,  3985,  3986,  3988,
    3989,  3991,  3994,  3995,  3997,  3998,  4000,  4001,  4003,  4004,
    4006,  4007,  4009,  4010,  4012,  4013,  4015,  4016,  4018,  4019
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     452,     0,    -1,    -1,   453,   454,    -1,   455,    -1,   454,
     455,    -1,   456,    -1,   462,    -1,    -1,    -1,   469,   477,
     457,   572,   458,   706,   465,   466,    -1,    -1,    -1,   469,
     477,   460,   572,   461,   706,   465,   467,    -1,    -1,    -1,
     471,   477,   463,   572,   464,   706,   468,    -1,    -1,   459,
      -1,   465,   459,    -1,    -1,   133,   472,   443,    -1,   133,
     472,   443,    -1,   129,   472,   443,    -1,    -1,   301,   443,
     472,   473,   470,   474,   443,    -1,   176,   443,   472,   473,
     443,    -1,   302,    -1,   227,    -1,    -1,    26,   227,    -1,
      -1,  1115,   475,  1126,    -1,    69,    -1,    69,   476,    -1,
     476,    -1,   396,    -1,   312,    -1,    -1,   144,   114,   443,
     478,   529,    -1,    -1,    79,   346,   443,   479,    -1,    -1,
     479,   480,    -1,   481,    -1,   485,    -1,   498,    -1,   493,
      -1,   367,   443,   482,    -1,    -1,   484,   443,    -1,   484,
     483,   443,    -1,   483,   443,    -1,  1140,   101,   240,    -1,
     430,    -1,   265,   443,   486,    -1,    -1,   484,   443,    -1,
     484,   487,   443,    -1,   487,   443,    -1,   488,    -1,   487,
     488,    -1,   489,    -1,   491,    -1,   492,    -1,   236,   362,
    1115,  1076,   490,    -1,    55,    -1,   431,    -1,  1126,  1099,
    1115,  1055,    -1,   348,  1115,  1076,    -1,   327,   443,   494,
      -1,    -1,   495,   443,    -1,   496,    -1,   495,   496,    -1,
     175,   497,   204,    -1,   175,     9,   204,    -1,   227,    -1,
     497,   227,    -1,   369,   443,   499,    -1,    -1,   500,   443,
      -1,   501,    -1,   500,   501,    -1,   502,    -1,   506,    -1,
     515,    -1,   522,    -1,   519,    -1,   523,    -1,   524,    -1,
     525,    -1,   526,    -1,   527,    -1,   528,    -1,   430,  1115,
      91,    -1,    -1,   430,  1115,  1058,   503,   504,    -1,    -1,
     504,   505,  1133,  1115,  1058,    -1,   270,    -1,   268,    -1,
      -1,    11,  1058,   507,  1115,   508,    -1,   246,    -1,   371,
      -1,   372,    -1,   118,    -1,   509,    -1,   510,    -1,   509,
     510,    -1,   513,    -1,   513,   390,   513,    -1,    -1,   513,
      17,   511,   512,    -1,   514,    -1,   512,    17,   514,    -1,
     227,    -1,   368,    -1,   436,    -1,   305,    -1,   188,    -1,
     234,    -1,   227,    -1,   368,    -1,   436,    -1,   305,    -1,
     188,    -1,   234,    -1,   382,  1108,   516,    -1,   517,  1116,
     518,    -1,  1058,    -1,   517,  1058,    -1,  1076,    -1,   518,
    1076,    -1,    56,  1058,  1115,   520,    -1,   521,    -1,   520,
     521,    -1,  1079,    -1,  1079,   390,  1079,    -1,   228,  1058,
    1115,  1055,    -1,    92,  1130,  1115,   227,    -1,   102,  1115,
      65,    -1,    94,  1115,  1055,    -1,    91,   374,  1115,  1055,
      -1,   342,  1115,  1055,    -1,   156,  1115,  1055,    -1,    -1,
     201,   346,   443,   532,   562,    -1,    -1,   163,   443,   530,
     533,    -1,    -1,   209,   443,   531,   563,    -1,    -1,   163,
     443,   533,    -1,    -1,   533,   534,    -1,    -1,   349,  1093,
    1058,   535,   536,   443,    -1,    -1,   536,   537,    -1,   538,
      -1,   542,    -1,   544,    -1,   545,    -1,   546,    -1,   548,
      -1,   552,    -1,   554,    -1,   555,    -1,   556,    -1,   558,
      -1,   559,    -1,   560,    -1,    28,  1138,   540,   539,   541,
      -1,    28,  1138,   540,   111,    -1,    -1,   111,    -1,   295,
      -1,    -1,   161,    -1,   117,    -1,   227,    -1,   112,    -1,
    1073,    -1,     4,  1120,  1115,   543,    -1,   354,    -1,   117,
      -1,   306,    -1,    19,   309,  1117,  1115,   557,  1089,    -1,
    1099,  1115,   430,    -1,   547,   374,  1115,  1055,  1056,    -1,
      -1,   395,    -1,   364,    -1,   231,  1120,  1115,   549,    -1,
     235,   550,    -1,    31,   550,    -1,   158,    -1,    -1,   429,
     231,   270,   551,    -1,   429,   231,   270,   242,   551,    -1,
     429,   337,    -1,   309,    -1,   311,    -1,   276,  1115,   553,
      -1,   553,    -1,   195,    -1,   309,  1105,   354,    -1,   354,
      -1,   316,    -1,   224,   354,    -1,   282,  1107,  1115,  1057,
      -1,   309,   107,  1115,   371,    -1,   309,  1117,  1115,   557,
      -1,  1055,    -1,  1055,   444,  1054,    -1,  1055,   366,  1115,
    1054,    -1,   316,  1117,  1115,  1055,    -1,   329,  1076,  1102,
      -1,   356,  1140,   561,    -1,     9,  1125,    -1,   251,  1125,
      -1,   308,   271,    -1,    -1,   209,   443,   563,    -1,    -1,
     564,   443,    -1,   565,    -1,   564,   565,    -1,   566,    -1,
     568,    -1,   340,   567,  1102,  1112,  1046,    -1,    -1,   309,
      -1,   364,    -1,   365,    -1,   242,  1111,  1134,  1109,   569,
      -1,   570,    -1,   569,   570,    -1,  1047,   571,    -1,    -1,
     291,  1076,    -1,    -1,    96,   114,   443,   573,   604,   649,
     651,   653,   694,    -1,    -1,    -1,   395,   346,   443,   574,
     576,    -1,    -1,   579,   575,   578,    -1,    -1,   576,   577,
      -1,   579,   580,   606,    -1,   580,   606,    -1,   578,   577,
      -1,   162,    -1,   344,    -1,    -1,  1047,   581,   582,   443,
      -1,    -1,   582,   583,    -1,  1115,   161,    -1,  1115,   181,
      -1,   584,    -1,   586,    -1,   590,    -1,   592,    -1,   594,
      -1,   595,    -1,   601,    -1,   602,    -1,   603,    -1,    46,
    1109,  1076,   589,   585,    -1,    -1,   311,    -1,    55,    -1,
     309,  1109,  1076,  1108,    -1,   309,  1109,  1076,   393,  1076,
    1108,    -1,   309,  1115,   425,  1114,  1132,   588,   589,  1108,
     587,    -1,    -1,   108,  1123,  1055,    -1,    -1,  1113,  1076,
      -1,    -1,   393,  1076,    -1,   212,  1097,   591,    -1,   370,
      -1,   269,    -1,   424,   267,   430,  1115,   593,    -1,   424,
     267,   164,  1115,   593,    -1,   227,    -1,  1073,    -1,    96,
    1097,  1054,    -1,   222,  1115,  1057,  1119,   596,    -1,    -1,
     596,   597,    -1,   598,    -1,   599,    -1,   600,    -1,  1140,
     168,  1104,  1057,  1119,    -1,  1104,   399,  1057,  1119,    -1,
    1104,    47,  1057,    -1,   310,  1120,  1115,   430,    -1,    59,
    1115,   430,    -1,   322,  1115,   693,    -1,   324,  1101,   693,
      -1,    -1,    -1,   432,   346,   443,   605,   606,    -1,    -1,
     607,    -1,    -1,   608,   609,    -1,  1087,   610,   443,    -1,
     609,  1087,   610,   443,    -1,   609,   443,    -1,   617,    -1,
      -1,   612,   613,   611,   618,    -1,   430,    -1,    -1,   165,
      -1,   430,    -1,   430,    -1,    -1,  1115,   181,    -1,  1077,
      -1,   218,  1122,  1072,    -1,    49,  1122,  1072,    -1,   612,
     614,    80,   615,  1103,   616,    -1,    -1,   618,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   624,    -1,   625,    -1,
     627,    -1,   628,    -1,   637,    -1,   638,    -1,   640,    -1,
     641,    -1,   642,    -1,   647,    -1,   648,    -1,   313,  1072,
      -1,  1115,   161,   622,    -1,    -1,    26,   227,    -1,  1115,
     181,    -1,   288,    -1,   626,    -1,   421,  1115,   626,    -1,
      36,    -1,    70,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,   112,    -1,   194,    -1,
     281,    -1,   290,    -1,   303,    -1,   361,    -1,   359,    -1,
     360,    -1,   410,    -1,   408,    -1,   409,    -1,    38,   358,
      -1,    38,   407,    -1,    38,    -1,    41,   358,    -1,    41,
     407,    -1,    41,    -1,    40,   358,    -1,    40,   407,    -1,
      40,    -1,    39,   358,    -1,    39,   407,    -1,    39,    -1,
      37,   358,    -1,    37,   407,    -1,    37,    -1,   244,    -1,
    1131,   216,  1095,    -1,  1131,   400,  1095,    -1,   266,  1076,
     629,  1137,   630,   631,   634,    -1,    -1,   393,  1076,    -1,
      -1,   108,  1123,  1055,    -1,   632,    -1,    -1,   632,   633,
    1117,  1115,  1054,    -1,    27,    -1,   109,    -1,    -1,   195,
    1106,   635,    -1,   636,    -1,   635,   636,    -1,   430,    -1,
     210,  1128,    -1,   383,   639,    -1,    -1,   217,    -1,   336,
      -1,    42,  1139,   436,    -1,    33,    -1,    -1,   424,  1116,
     644,   643,  1139,  1129,  1138,   646,    -1,   645,    -1,   644,
     645,    -1,  1077,    -1,  1077,   390,  1077,    -1,    -1,   394,
    1115,  1077,    -1,   320,  1073,    -1,   320,  1073,   390,  1073,
      -1,    21,   218,    -1,    -1,    -1,   230,   346,   443,   650,
     606,    -1,    -1,    -1,   226,   346,   443,   652,   606,    -1,
      -1,    -1,   322,   346,   443,   654,   655,    -1,    -1,   656,
      -1,   657,    -1,   656,   657,    -1,   307,   693,   658,   443,
     672,    -1,    -1,   658,   659,    -1,  1115,   181,    -1,    58,
    1115,  1068,    -1,   660,    -1,   664,    -1,    84,   661,    -1,
      85,   661,    -1,   662,   663,    -1,    -1,   166,    -1,  1071,
      -1,   663,  1071,    -1,   283,  1116,   670,   665,   666,   667,
     668,   669,    -1,    -1,   186,  1115,  1076,    -1,    -1,   167,
     110,  1115,  1076,    -1,    -1,   213,    87,  1115,  1076,    -1,
      -1,   214,  1115,  1076,    -1,    -1,   168,  1115,  1076,    -1,
    1076,    -1,  1076,   671,  1076,    64,    -1,  1076,   671,    -1,
     224,    -1,   225,    -1,    -1,   672,   673,    -1,   612,   613,
     674,   443,    -1,    -1,   674,   675,    -1,   676,    -1,   678,
      -1,   685,    -1,   624,    -1,   625,    -1,   627,    -1,   637,
      -1,   679,    -1,   640,    -1,   690,    -1,   680,    -1,   642,
      -1,   683,    -1,   691,    -1,   628,    -1,   684,    -1,   403,
    1115,   677,    -1,   326,    -1,   285,    -1,    87,    -1,   110,
      -1,    86,    -1,   284,    -1,   325,    -1,   249,   185,  1115,
    1076,    -1,    63,  1121,  1115,  1076,    -1,    63,   261,    -1,
      64,    -1,   681,    -1,   680,   681,    -1,   380,  1122,   682,
      -1,  1055,    -1,   293,   427,  1027,    -1,   425,  1071,   173,
    1062,    48,  1062,    -1,   686,   687,    -1,   224,   689,  1116,
      -1,   225,  1101,    -1,   688,    -1,   687,   688,    -1,   289,
    1076,    -1,  1076,    -1,   249,   283,    -1,    -1,   260,    -1,
     261,    -1,   366,  1115,  1071,  1094,    -1,   185,   692,    -1,
      -1,   196,    -1,   430,    -1,    -1,    -1,    -1,   341,   346,
     443,   695,   696,   697,    -1,    -1,   698,    -1,   699,    -1,
     698,   699,    -1,   617,    -1,    -1,   612,   613,   700,   701,
     443,    -1,    -1,   701,   702,    -1,    43,    -1,    44,    -1,
      35,    -1,    45,    -1,   152,   147,    -1,   152,   149,    -1,
     187,    -1,   233,    -1,   333,    -1,   404,    -1,   280,    -1,
      30,    -1,   347,    -1,   328,    -1,   174,    -1,   304,    -1,
     224,  1121,  1115,   703,  1070,    -1,    63,  1121,  1115,   704,
    1070,    -1,   170,  1115,  1070,    -1,    32,  1115,  1070,    -1,
     625,    -1,   640,    -1,   637,    -1,   627,    -1,   642,    -1,
     624,    -1,   705,    -1,   423,  1071,    -1,   173,  1069,    -1,
     393,  1071,    -1,    -1,   289,    -1,   437,    -1,   238,    -1,
     438,    -1,    -1,   289,    -1,   437,    -1,   238,    -1,   438,
      -1,   266,  1076,  1137,    -1,    -1,    -1,    -1,   297,   114,
     709,   717,   443,   707,   718,   708,   720,    -1,    -1,    -1,
     423,   710,   712,    -1,    -1,    53,   711,   712,    -1,   713,
      -1,   712,   713,    -1,   714,   715,   716,   430,    -1,    -1,
    1106,   315,    -1,  1106,   424,    -1,    -1,   362,  1115,    30,
      -1,   362,  1115,   104,    -1,   407,   362,  1115,  1076,    -1,
     362,  1115,  1076,    -1,    -1,   273,    -1,    -1,   331,   430,
      -1,    -1,    -1,   103,   443,   719,   720,   120,   103,   443,
      -1,    -1,   720,   721,    -1,   722,    -1,   723,    -1,   724,
      -1,   730,   443,    -1,     1,   443,    -1,   443,    -1,   725,
     346,   726,   443,    -1,   430,   443,    -1,   725,    -1,   430,
      -1,    -1,   227,    -1,    -1,    -1,   728,   729,   730,    -1,
      -1,   731,   732,    -1,   730,   732,    -1,   733,    -1,   743,
      -1,   748,    -1,   752,    -1,   755,    -1,   768,    -1,   771,
      -1,   781,    -1,   776,    -1,   782,    -1,   783,    -1,   786,
      -1,   794,    -1,   798,    -1,   800,    -1,   815,    -1,   818,
      -1,   820,    -1,   822,    -1,   825,    -1,   827,    -1,   833,
      -1,   842,    -1,   844,    -1,   861,    -1,   863,    -1,   866,
      -1,   870,    -1,   876,    -1,   886,    -1,   893,    -1,   895,
      -1,   898,    -1,   902,    -1,   903,    -1,   914,    -1,   925,
      -1,   935,    -1,   941,    -1,   944,    -1,   950,    -1,   954,
      -1,   956,    -1,   958,    -1,   960,    -1,   963,    -1,   974,
      -1,   987,    -1,   250,    -1,    -1,     3,   734,   735,   742,
      -1,  1071,   736,   739,   994,    -1,  1071,   173,   154,   211,
      -1,  1071,   173,   225,    -1,  1071,   173,    64,    -1,  1071,
     173,    97,    -1,  1071,   173,    97,   435,    -1,  1071,   173,
      98,    -1,  1071,   173,    98,   434,    -1,  1071,   173,    99,
      -1,  1071,   173,   391,    -1,  1071,   173,    66,    -1,  1071,
     173,   146,   994,    -1,  1071,   173,   144,  1066,   994,    -1,
    1071,   173,    24,    -1,  1071,   173,    25,   994,    -1,  1071,
     173,  1049,    -1,  1071,   173,   430,    -1,    -1,  1104,   737,
     738,    -1,  1104,   738,   737,    -1,  1104,   737,    -1,  1104,
     738,    -1,    29,  1066,    -1,   224,  1121,  1068,    -1,    63,
    1121,  1068,    -1,   291,  1121,  1068,    -1,    -1,   429,   740,
      -1,   741,    -1,   740,   741,    -1,    35,    -1,    45,    -1,
     187,    -1,   233,    -1,   333,    -1,   404,    -1,   280,    -1,
     170,  1115,  1070,    -1,    32,  1115,  1070,    -1,   343,   413,
    1026,    -1,   343,   115,  1026,    -1,    30,    -1,   174,    -1,
     328,    -1,   347,    -1,   414,    -1,   304,    -1,    -1,   121,
      -1,    -1,     5,   744,   745,   747,    -1,  1061,   393,  1042,
    1000,    -1,  1061,   746,   180,  1042,  1000,    -1,    89,  1071,
     393,  1071,  1094,  1000,    -1,    -1,   393,  1062,    -1,    -1,
     122,    -1,    -1,    10,   749,   750,    -1,   430,  1090,   751,
      -1,  1028,    55,  1090,   331,  1060,    -1,    -1,   331,  1060,
      -1,    18,   753,    -1,    -1,   753,  1051,   393,   754,  1051,
      -1,    -1,   299,   393,    -1,    -1,    50,   756,  1069,   757,
     762,   763,   765,   767,    -1,    -1,    -1,   423,   758,   759,
      -1,   760,    -1,   759,   760,    -1,   761,   269,    -1,   761,
     715,  1062,    -1,    -1,  1106,   315,    -1,  1106,    82,    -1,
    1106,   424,    -1,    -1,   331,  1071,    -1,   180,  1071,    -1,
      -1,    -1,   981,   764,   727,    -1,    -1,    -1,   982,   766,
     727,    -1,    -1,   123,    -1,    -1,    51,   769,   770,    -1,
      -1,   770,  1068,    -1,    -1,    57,   772,   773,    -1,    -1,
     773,  1047,   774,    -1,    -1,   775,    -1,   775,  1112,   319,
      -1,  1140,   251,   334,    -1,  1140,   231,    -1,   314,    -1,
     405,    -1,    -1,    71,   777,   778,   779,    -1,  1042,   780,
    1028,  1000,    -1,    -1,   124,    -1,   444,    -1,   150,    -1,
      68,    -1,    83,    -1,    -1,   105,   784,  1047,  1127,  1020,
     785,    -1,    -1,   125,    -1,    -1,   112,   787,   788,   793,
      -1,  1068,   418,   995,    -1,  1068,   419,   995,    -1,  1068,
     416,   995,    -1,  1068,   417,   995,    -1,  1061,   736,   789,
     790,   995,    -1,    -1,   415,  1049,    -1,   415,   430,    -1,
     415,   295,    -1,   415,    91,    -1,    -1,  1140,   259,    -1,
     429,   791,    -1,   792,    -1,   791,   792,    -1,    35,    -1,
      45,    -1,   152,   147,    -1,   152,   149,    -1,   187,    -1,
     233,    -1,   333,    -1,   404,    -1,   280,    -1,   170,  1115,
    1070,    -1,    32,  1115,  1070,    -1,   343,   413,  1026,    -1,
     343,   115,  1026,    -1,    43,    -1,    44,    -1,    -1,   126,
      -1,    -1,   113,   795,   796,   797,    -1,  1062,   203,  1042,
    1000,    -1,  1062,   203,  1062,   180,  1042,  1000,    -1,  1062,
      48,  1062,   180,  1042,  1000,    -1,  1062,   203,  1062,   180,
    1043,   318,  1043,  1000,    -1,  1062,    48,  1062,   180,  1043,
     318,  1043,  1000,    -1,    -1,   127,    -1,    -1,   143,   799,
     227,   757,    -1,    -1,   155,   801,   802,   804,   814,    -1,
     803,    -1,   802,    17,   803,    -1,  1028,    -1,   398,    -1,
     394,    -1,   805,   808,    -1,   806,    -1,   805,   806,    -1,
      -1,   810,   807,   727,    -1,    -1,    -1,   427,   277,   809,
     727,    -1,   427,   811,    -1,   810,   427,   811,    -1,   812,
      -1,   811,    17,   812,    -1,  1029,   813,    -1,    21,    -1,
     398,    -1,   394,    -1,    -1,   390,  1028,    -1,    -1,   128,
      -1,    -1,   159,   816,   817,    -1,    -1,   300,    -1,   287,
      -1,   287,    95,    -1,   346,    -1,   286,    -1,    -1,   172,
     819,  1059,    -1,    -1,   179,   821,  1071,    -1,    -1,   182,
    1138,   823,  1050,   824,    -1,    -1,   108,  1123,  1071,    -1,
      -1,   183,   826,    -1,    -1,    -1,   190,   828,  1027,  1136,
     829,   727,   830,   832,    -1,   190,     1,   130,    -1,    -1,
      -1,   119,   831,   727,    -1,    -1,   130,    -1,    -1,   197,
     834,  1059,   835,   836,   837,   841,    -1,    -1,  1140,   165,
      -1,    -1,     9,  1138,   424,    -1,   840,  1138,   424,    -1,
      -1,   321,   838,    -1,   839,    -1,   838,   839,    -1,   840,
    1110,    48,  1062,    -1,    12,    -1,    15,    -1,   262,    -1,
      16,    -1,   263,    -1,   244,    -1,   245,    -1,    -1,   104,
      -1,    -1,   199,   843,   663,    -1,    -1,   202,   845,   846,
     847,    -1,  1071,    -1,  1077,    -1,  1080,    -1,   848,    -1,
     847,   848,    -1,   849,    -1,   853,    -1,   858,    -1,    -1,
     384,   850,   851,    -1,   852,    -1,   851,   852,    -1,  1066,
     169,    -1,    55,   859,    -1,     9,    -1,   216,    -1,   400,
      -1,  1066,   859,    -1,   321,   854,    -1,   855,    -1,   854,
     855,    -1,    55,    48,  1066,   859,    -1,   856,   857,    -1,
      -1,     9,    -1,   216,    -1,   167,    -1,   400,    -1,  1066,
      48,  1067,   859,    -1,    88,  1066,   393,  1067,   859,    -1,
      -1,   859,   991,   860,  1062,    -1,    -1,   396,    -1,    -1,
     237,   862,   927,    -1,    -1,   241,   864,   865,    -1,  1062,
     393,  1059,    -1,    89,  1062,   393,  1059,    -1,    -1,   243,
     867,   868,   869,    -1,  1062,    48,  1042,  1000,    -1,  1062,
      48,  1062,   180,  1042,  1000,    -1,    -1,   131,    -1,    -1,
     272,   871,   872,    -1,    -1,   872,   873,   874,  1046,   875,
      -1,   200,    -1,   278,    -1,   208,    -1,   160,    -1,    -1,
     356,  1140,   561,    -1,    -1,  1140,   251,   334,    -1,  1140,
     231,    -1,    -1,   287,   877,   878,    -1,   881,   882,    -1,
      -1,   882,   879,   727,   880,    -1,   882,   132,    -1,    -1,
     132,    -1,  1051,    -1,  1051,   390,  1051,    -1,    -1,   171,
      -1,  1069,   392,    -1,   883,   412,  1027,    -1,   883,   425,
     884,    -1,    -1,  1140,   387,   991,    -1,   885,    -1,   884,
       8,   885,    -1,  1071,   173,  1062,    48,  1062,   412,  1027,
      -1,    -1,   308,   887,  1047,  1091,  1127,   888,   889,   890,
     891,   892,    -1,    -1,   203,  1071,    -1,    -1,   192,   231,
      -1,  1140,   231,    -1,  1140,   251,   231,    -1,  1140,   191,
     231,    -1,  1140,   426,    -1,    -1,   211,  1115,  1071,    -1,
      -1,  1010,    -1,  1021,    -1,    -1,   134,    -1,    -1,   317,
     894,  1044,   989,    -1,    -1,   330,   896,  1047,  1127,   888,
    1010,   897,    -1,    -1,   135,    -1,    -1,   335,   899,  1044,
     989,   900,  1020,   901,    -1,    -1,  1140,   231,    -1,  1140,
     251,   231,    -1,    -1,   136,    -1,   337,    -1,    -1,   345,
     904,   905,   913,    -1,  1045,   907,   908,   910,    -1,    -1,
       9,  1045,   908,   427,  1028,   906,   727,    -1,    -1,   425,
    1071,    -1,    -1,    -1,  1104,   120,   909,   727,    -1,   911,
      -1,   911,   910,    -1,    -1,   427,  1027,   912,   727,    -1,
      -1,   137,    -1,    -1,   355,   915,   916,    -1,   917,    -1,
     918,    -1,   919,    -1,   921,    -1,   923,    -1,   144,  1066,
     393,  1066,    -1,  1059,   393,   143,  1065,    -1,  1059,   393,
    1062,    -1,  1059,   920,    48,  1062,    -1,   413,    -1,   115,
      -1,   922,    -1,   921,   922,    -1,  1048,   393,   505,    -1,
     924,    -1,   923,   924,    -1,  1059,   393,   398,    -1,  1059,
     393,   394,    -1,    -1,   364,   926,   927,    -1,    -1,  1073,
     929,   931,   932,   928,   933,   934,    -1,    -1,   929,  1123,
     633,  1117,   930,    -1,    -1,   930,  1073,    -1,    -1,  1098,
    1124,    -1,    -1,  1099,  1115,  1055,    -1,    -1,   423,  1046,
      -1,   200,   297,  1115,   881,    -1,    -1,   180,  1046,    -1,
     278,   297,  1115,   881,    -1,    -1,    -1,   373,   936,  1047,
     937,   938,  1020,   940,    -1,    -1,   211,  1115,   939,  1062,
      -1,  1092,  1033,    -1,  1092,  1034,    -1,  1092,  1035,    -1,
    1092,  1036,    -1,  1092,  1037,    -1,    -1,   138,    -1,    -1,
     375,   339,   942,   943,    -1,   375,   227,    -1,    -1,   331,
    1062,    -1,   180,  1062,    -1,    -1,   376,   945,   946,   203,
    1071,   948,  1005,   949,    -1,   947,    -1,   946,   947,    -1,
    1062,    -1,   106,  1106,   362,    -1,   106,  1106,  1062,    -1,
      -1,  1140,   290,  1071,    -1,    -1,   139,    -1,    -1,   379,
     951,   952,   953,    -1,  1061,   173,  1042,  1000,    -1,  1061,
     173,  1062,   180,  1042,  1000,    -1,    89,  1071,   173,  1071,
    1094,  1000,    -1,    -1,   140,    -1,   381,   955,    -1,    -1,
     296,    -1,    -1,   386,   957,   663,    -1,    -1,   401,   959,
    1071,   173,  1066,   393,  1067,    -1,    -1,   406,   961,  1047,
     962,    -1,    -1,   309,    -1,   311,    -1,    -1,   411,   964,
    1071,   965,   968,   948,   972,  1005,   973,    -1,    -1,   106,
    1106,   966,    -1,   967,    -1,   966,   274,   967,    -1,  1088,
    1066,    -1,   203,   969,    -1,   968,   969,    -1,  1071,   970,
     971,    -1,    -1,   107,  1114,  1071,    -1,    -1,    90,  1114,
    1071,    -1,    -1,   384,  1114,  1071,    -1,    -1,   141,    -1,
     975,    -1,   984,    -1,   986,    -1,   422,   976,   978,   979,
     980,   983,  1123,   977,    -1,    -1,   181,    -1,  1046,    -1,
     200,    -1,   278,    -1,   208,    -1,   160,    -1,    -1,     8,
      -1,    -1,   370,    -1,   157,    -1,   153,    -1,   157,    -1,
     279,    -1,   255,    -1,   257,    -1,    -1,   297,    -1,   422,
    1112,   101,  1123,   985,    -1,  1051,    -1,     9,   298,    -1,
     422,   976,    34,   323,  1071,    -1,    -1,   433,   988,  1044,
     989,   900,   990,   992,   993,    -1,    -1,   173,  1068,    -1,
      -1,   991,  1100,  1070,  1118,    -1,   991,  1100,  1049,    -1,
     991,  1100,   283,    -1,    34,    -1,     8,    -1,    -1,  1015,
      -1,  1021,    -1,    -1,   142,    -1,   996,   998,    -1,   996,
     998,    -1,    -1,    -1,   157,   997,   727,    -1,    -1,    -1,
     255,   999,   727,    -1,  1001,  1003,    -1,    -1,    -1,   363,
    1002,   727,    -1,    -1,    -1,   258,  1004,   727,    -1,  1006,
    1008,    -1,    -1,    -1,   279,  1007,   727,    -1,    -1,    -1,
     257,  1009,   727,    -1,  1011,    -1,  1013,    -1,  1011,  1013,
      -1,    -1,   120,  1012,   727,    -1,    -1,   253,  1014,   727,
      -1,  1016,    -1,  1018,    -1,  1016,  1018,    -1,    -1,   148,
    1017,   727,    -1,    -1,   254,  1019,   727,    -1,    -1,  1021,
      -1,  1022,    -1,  1024,    -1,  1022,  1024,    -1,    -1,   206,
    1023,   727,    -1,    -1,   256,  1025,   727,    -1,    -1,  1106,
    1070,  1118,    -1,  1028,    -1,  1029,    -1,    -1,  1030,  1031,
      -1,  1032,    -1,  1031,   207,    -1,  1031,  1032,    -1,  1062,
      -1,   445,    -1,   446,    -1,   437,    -1,   438,    -1,   439,
      -1,   440,    -1,   442,    -1,  1033,    -1,  1034,    -1,  1035,
      -1,   178,    -1,   215,    -1,   247,    -1,   252,    -1,    20,
      -1,   274,    -1,   269,    -1,   262,    -1,    12,    -1,    13,
      -1,    14,    -1,   292,    -1,   248,    -1,   444,    -1,   150,
    1138,    -1,   151,    -1,   447,    -1,   184,  1135,    -1,   448,
      -1,   219,  1135,    -1,   178,    -1,   184,  1135,   274,   150,
    1138,    -1,   215,    -1,   219,  1135,   274,   150,  1138,    -1,
    1040,    -1,  1038,  1039,  1040,    -1,    -1,    67,    -1,   350,
      -1,  1063,    -1,  1040,   437,  1040,    -1,  1040,   438,  1040,
      -1,  1040,   439,  1040,    -1,  1040,   440,  1040,    -1,   437,
    1040,    -1,   438,  1040,    -1,  1040,   442,  1040,    -1,   445,
    1040,   446,    -1,   223,    -1,   223,  1096,   430,    -1,  1043,
      -1,  1042,  1043,    -1,  1062,  1094,    -1,  1073,    -1,  1073,
      -1,  1047,    -1,  1046,  1047,    -1,   430,    -1,  1049,    -1,
    1048,  1049,    -1,   239,    -1,    -1,  1050,  1051,    -1,  1052,
      -1,  1073,    -1,  1053,    -1,  1053,  1096,  1053,    -1,   227,
      -1,  1055,    -1,  1054,  1055,    -1,  1073,    -1,    -1,  1055,
      -1,  1055,    -1,   227,    -1,   430,    -1,  1060,    -1,  1059,
    1060,    -1,  1071,    -1,     6,  1122,  1072,    -1,  1062,    -1,
    1061,  1062,    -1,  1071,    -1,   218,  1122,  1072,    -1,   218,
    1122,  1078,    -1,   218,  1122,  1080,    -1,     6,  1122,  1064,
    1065,    -1,     6,  1122,  1072,    -1,  1077,    -1,  1080,    -1,
    1041,    -1,  1071,    -1,   218,  1122,  1072,    -1,   218,  1122,
    1078,    -1,   218,  1122,  1080,    -1,  1078,    -1,  1080,    -1,
    1041,    -1,   300,    -1,   143,    -1,  1072,    -1,   227,    -1,
    1071,    -1,  1078,    -1,  1071,    -1,  1077,    -1,  1071,    -1,
     227,    -1,  1071,    -1,   227,    -1,  1080,    -1,  1071,    -1,
    1076,    -1,   436,    -1,  1072,    -1,  1073,    -1,  1073,  1074,
      -1,  1073,  1075,    -1,  1073,  1074,  1075,    -1,   430,    -1,
     430,  1096,  1073,    -1,   445,  1038,   446,    -1,   445,  1040,
     449,   446,    -1,   445,  1040,   449,  1040,   446,    -1,   227,
      -1,  1078,    -1,     9,  1079,    -1,  1079,    -1,  1078,   450,
    1079,    -1,   227,    -1,   368,    -1,   436,    -1,   305,    -1,
     188,    -1,   234,    -1,   397,    -1,    93,  1081,    -1,   428,
    1081,    -1,   420,   445,  1040,   446,  1081,    -1,   232,   445,
    1040,   446,  1081,    -1,   332,   445,  1040,   446,  1081,    -1,
      78,   445,  1038,   446,  1081,    -1,   377,   445,  1038,   446,
    1081,    -1,   378,   445,  1038,   446,  1081,    -1,   402,   445,
    1084,   446,  1081,    -1,   264,   445,  1085,   446,    -1,   229,
     445,  1086,   446,  1081,    -1,   177,  1082,    -1,    -1,   445,
    1040,   449,   446,    -1,   445,  1040,   449,  1040,   446,    -1,
      -1,   445,  1083,   446,    -1,    -1,  1038,    -1,  1040,    -1,
    1040,  1039,   216,    -1,  1040,  1039,   400,    -1,  1040,    -1,
    1040,  1039,  1040,    -1,  1040,    -1,  1040,  1039,  1055,    -1,
      -1,    -1,     9,    -1,    -1,  1098,    -1,    -1,   198,    -1,
      -1,   249,    -1,   294,    -1,    -1,   252,    -1,    -1,   273,
      -1,    -1,   338,    -1,    -1,   352,  1107,    -1,   193,    -1,
     267,    -1,   309,  1115,    -1,   311,  1101,    -1,   429,   116,
      -1,   116,    -1,    60,   353,    -1,   353,    -1,    -1,     7,
      -1,    -1,    22,    -1,    -1,    23,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    36,    -1,    -1,    48,    -1,    -1,
      54,    -1,    -1,    55,    -1,    -1,    81,    -1,    -1,    96,
      -1,    -1,   395,    -1,    -1,   169,    -1,    -1,   173,    -1,
      -1,   193,    -1,    -1,   207,    -1,    -1,   207,    -1,    22,
      -1,    -1,   211,    -1,    -1,   224,    -1,   225,    -1,    -1,
     225,    -1,    -1,   240,    -1,    -1,   260,    -1,    -1,   267,
      -1,    -1,   270,    -1,    -1,   275,    -1,   193,   275,    -1,
      -1,   277,    -1,    -1,   300,    -1,    -1,   309,    -1,    -1,
     336,    -1,    -1,   355,    -1,    -1,   357,    -1,    -1,   357,
      -1,   357,   207,    -1,    -1,   362,    -1,    -1,   374,    -1,
      -1,   385,    -1,    -1,   388,    -1,    -1,   389,    -1,    -1,
     392,    -1,    -1,   393,    -1,    -1,   427,    -1,    -1,   429,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   757,   757,   757,   799,   800,   804,   805,   810,   811,
     809,   819,   820,   818,   828,   829,   827,   834,   835,   836,
     839,   840,   864,   888,   918,   917,   958,  1002,  1003,  1007,
    1008,  1011,  1012,  1016,  1023,  1030,  1034,  1038,  1050,  1051,
    1061,  1062,  1071,  1072,  1076,  1077,  1078,  1079,  1088,  1091,
    1092,  1093,  1094,  1098,  1105,  1114,  1117,  1118,  1119,  1120,
    1124,  1125,  1129,  1130,  1131,  1135,  1142,  1143,  1147,  1154,
    1166,  1169,  1170,  1174,  1175,  1179,  1183,  1190,  1191,  1201,
    1204,  1205,  1209,  1210,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1231,  1242,  1241,  1254,  1255,
    1263,  1264,  1272,  1271,  1283,  1284,  1285,  1286,  1287,  1295,
    1296,  1301,  1302,  1304,  1303,  1315,  1316,  1320,  1321,  1322,
    1323,  1324,  1325,  1329,  1330,  1331,  1332,  1333,  1334,  1341,
    1352,  1364,  1365,  1369,  1370,  1377,  1386,  1387,  1391,  1392,
    1406,  1421,  1488,  1499,  1506,  1513,  1519,  1526,  1527,  1531,
    1530,  1540,  1539,  1555,  1556,  1559,  1560,  1565,  1564,  1585,
    1586,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,
    1599,  1600,  1601,  1602,  1609,  1613,  1619,  1620,  1621,  1624,
    1625,  1629,  1633,  1634,  1641,  1648,  1652,  1653,  1654,  1661,
    1686,  1696,  1705,  1707,  1708,  1714,  1718,  1719,  1720,  1723,
    1724,  1725,  1729,  1733,  1734,  1740,  1741,  1745,  1754,  1763,
    1772,  1781,  1796,  1806,  1813,  1820,  1821,  1822,  1828,  1835,
    1842,  1846,  1847,  1848,  1856,  1857,  1860,  1861,  1865,  1866,
    1870,  1871,  1877,  1902,  1903,  1904,  1905,  1911,  1918,  1919,
    1923,  1926,  1927,  1935,  1936,  1950,  1951,  1951,  1954,  1953,
    1966,  1967,  1971,  1983,  1992,  1996,  1997,  2007,  2006,  2024,
    2025,  2029,  2036,  2043,  2044,  2045,  2046,  2047,  2048,  2049,
    2050,  2051,  2058,  2062,  2062,  2062,  2068,  2080,  2105,  2129,
    2130,  2137,  2138,  2142,  2143,  2150,  2157,  2158,  2165,  2169,
    2178,  2179,  2185,  2195,  2213,  2214,  2218,  2219,  2220,  2224,
    2231,  2238,  2248,  2255,  2273,  2277,  2288,  2289,  2289,  2300,
    2301,  2305,  2305,  2322,  2323,  2325,  2329,  2331,  2330,  2361,
    2366,  2371,  2377,  2386,  2394,  2395,  2403,  2404,  2405,  2409,
    2429,  2433,  2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,
    2450,  2451,  2452,  2453,  2454,  2455,  2462,  2484,  2506,  2507,
    2519,  2539,  2546,  2547,  2551,  2552,  2553,  2554,  2555,  2556,
    2557,  2558,  2559,  2560,  2561,  2562,  2567,  2572,  2573,  2574,
    2575,  2576,  2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,
    2585,  2586,  2587,  2588,  2589,  2590,  2598,  2606,  2614,  2621,
    2626,  2637,  2654,  2655,  2658,  2659,  2666,  2690,  2691,  2708,
    2709,  2712,  2713,  2720,  2721,  2726,  2736,  2743,  2746,  2747,
    2748,  2755,  2762,  2787,  2787,  2792,  2793,  2797,  2798,  2801,
    2802,  2815,  2827,  2847,  2861,  2863,  2862,  2882,  2883,  2883,
    2896,  2898,  2897,  2909,  2910,  2914,  2915,  2924,  2931,  2934,
    2938,  2942,  2943,  2944,  2951,  2952,  2956,  2959,  2959,  2962,
    2963,  2969,  2974,  2975,  2978,  2979,  2982,  2983,  2986,  2987,
    2990,  2991,  2995,  2996,  2997,  3001,  3002,  3005,  3006,  3010,
    3014,  3015,  3019,  3020,  3021,  3022,  3023,  3024,  3025,  3026,
    3027,  3028,  3029,  3030,  3031,  3032,  3033,  3034,  3038,  3042,
    3043,  3044,  3045,  3046,  3047,  3048,  3052,  3056,  3057,  3058,
    3062,  3063,  3067,  3071,  3076,  3080,  3084,  3088,  3089,  3093,
    3094,  3098,  3099,  3100,  3103,  3103,  3103,  3106,  3110,  3113,
    3113,  3116,  3123,  3124,  3125,  3124,  3142,  3143,  3147,  3148,
    3153,  3155,  3154,  3190,  3191,  3195,  3196,  3197,  3198,  3199,
    3200,  3201,  3202,  3203,  3204,  3205,  3206,  3207,  3208,  3209,
    3210,  3211,  3215,  3219,  3223,  3227,  3228,  3229,  3230,  3231,
    3232,  3233,  3234,  3241,  3245,  3255,  3258,  3262,  3266,  3270,
    3278,  3281,  3285,  3289,  3293,  3301,  3314,  3316,  3326,  3315,
    3353,  3355,  3354,  3361,  3360,  3369,  3370,  3375,  3382,  3384,
    3388,  3398,  3400,  3408,  3416,  3445,  3476,  3478,  3488,  3493,
    3504,  3505,  3505,  3532,  3533,  3537,  3538,  3539,  3540,  3556,
    3560,  3572,  3603,  3640,  3652,  3655,  3656,  3665,  3669,  3665,
    3682,  3682,  3700,  3704,  3705,  3706,  3707,  3708,  3709,  3710,
    3711,  3712,  3713,  3714,  3715,  3716,  3717,  3718,  3719,  3720,
    3721,  3722,  3723,  3724,  3725,  3726,  3727,  3728,  3729,  3730,
    3731,  3732,  3733,  3734,  3735,  3736,  3737,  3738,  3739,  3740,
    3741,  3742,  3743,  3744,  3745,  3746,  3747,  3748,  3749,  3750,
    3751,  3752,  3775,  3774,  3787,  3791,  3795,  3799,  3803,  3807,
    3811,  3815,  3819,  3823,  3827,  3831,  3835,  3839,  3843,  3847,
    3851,  3858,  3859,  3860,  3861,  3862,  3863,  3867,  3871,  3872,
    3875,  3876,  3880,  3881,  3885,  3886,  3887,  3888,  3889,  3890,
    3891,  3892,  3896,  3900,  3904,  3909,  3910,  3911,  3912,  3913,
    3914,  3918,  3919,  3928,  3928,  3934,  3938,  3942,  3948,  3949,
    3953,  3954,  3963,  3963,  3968,  3972,  3979,  3980,  3989,  3995,
    3996,  4000,  4000,  4008,  4008,  4018,  4020,  4019,  4028,  4029,
    4034,  4041,  4048,  4050,  4054,  4062,  4073,  4074,  4075,  4080,
    4084,  4083,  4095,  4099,  4098,  4109,  4110,  4119,  4119,  4123,
    4124,  4136,  4136,  4140,  4141,  4152,  4153,  4154,  4155,  4156,
    4159,  4159,  4167,  4167,  4173,  4180,  4181,  4184,  4184,  4191,
    4204,  4217,  4217,  4228,  4229,  4239,  4238,  4251,  4255,  4259,
    4263,  4267,  4274,  4275,  4276,  4277,  4278,  4282,  4283,  4284,
    4288,  4289,  4294,  4295,  4296,  4297,  4298,  4299,  4300,  4301,
    4302,  4303,  4307,  4311,  4315,  4320,  4321,  4325,  4326,  4335,
    4335,  4341,  4345,  4349,  4353,  4357,  4364,  4365,  4374,  4374,
    4396,  4395,  4414,  4415,  4420,  4429,  4434,  4442,  4452,  4453,
    4459,  4458,  4471,  4475,  4474,  4486,  4487,  4492,  4493,  4498,
    4527,  4528,  4529,  4532,  4533,  4537,  4538,  4547,  4547,  4552,
    4553,  4561,  4578,  4595,  4613,  4638,  4638,  4651,  4651,  4664,
    4664,  4673,  4677,  4690,  4690,  4703,  4705,  4703,  4713,  4718,
    4722,  4721,  4732,  4733,  4742,  4742,  4750,  4751,  4755,  4756,
    4757,  4761,  4762,  4767,  4768,  4773,  4777,  4778,  4779,  4780,
    4781,  4782,  4783,  4787,  4788,  4797,  4797,  4810,  4809,  4819,
    4820,  4821,  4825,  4826,  4830,  4831,  4832,  4838,  4838,  4843,
    4844,  4848,  4849,  4850,  4851,  4852,  4853,  4859,  4863,  4864,
    4868,  4873,  4877,  4878,  4879,  4880,  4881,  4885,  4911,  4920,
    4921,  4925,  4925,  4933,  4933,  4943,  4943,  4948,  4952,  4964,
    4964,  4970,  4974,  4981,  4982,  4991,  4991,  4995,  4996,  5010,
    5011,  5012,  5013,  5017,  5018,  5022,  5023,  5024,  5036,  5036,
    5041,  5046,  5045,  5055,  5062,  5063,  5067,  5072,  5081,  5084,
    5088,  5093,  5100,  5107,  5108,  5112,  5113,  5118,  5130,  5130,
    5153,  5154,  5158,  5159,  5163,  5167,  5171,  5175,  5182,  5183,
    5186,  5187,  5188,  5192,  5193,  5202,  5202,  5217,  5217,  5228,
    5229,  5238,  5238,  5249,  5250,  5254,  5261,  5262,  5271,  5284,
    5284,  5290,  5295,  5294,  5305,  5306,  5310,  5312,  5311,  5322,
    5323,  5328,  5327,  5338,  5339,  5348,  5348,  5353,  5354,  5355,
    5356,  5357,  5363,  5372,  5376,  5385,  5392,  5393,  5399,  5400,
    5404,  5413,  5414,  5418,  5422,  5434,  5434,  5440,  5439,  5456,
    5459,  5475,  5476,  5479,  5480,  5484,  5485,  5490,  5495,  5503,
    5515,  5520,  5528,  5544,  5545,  5544,  5565,  5566,  5570,  5571,
    5572,  5573,  5574,  5578,  5579,  5588,  5588,  5593,  5600,  5601,
    5602,  5611,  5611,  5620,  5621,  5625,  5626,  5627,  5631,  5632,
    5636,  5637,  5646,  5646,  5652,  5656,  5660,  5667,  5668,  5677,
    5684,  5685,  5693,  5693,  5706,  5706,  5722,  5722,  5731,  5733,
    5734,  5743,  5743,  5753,  5754,  5759,  5760,  5765,  5772,  5773,
    5778,  5785,  5786,  5790,  5791,  5795,  5796,  5800,  5801,  5810,
    5811,  5812,  5816,  5840,  5843,  5851,  5861,  5866,  5871,  5876,
    5883,  5884,  5887,  5888,  5892,  5892,  5896,  5896,  5900,  5900,
    5903,  5904,  5908,  5915,  5916,  5920,  5932,  5932,  5943,  5944,
    5949,  5952,  5956,  5960,  5967,  5968,  5971,  5972,  5973,  5977,
    5978,  5991,  5999,  6006,  6008,  6007,  6017,  6019,  6018,  6033,
    6040,  6042,  6041,  6051,  6053,  6052,  6068,  6074,  6076,  6075,
    6085,  6087,  6086,  6102,  6107,  6112,  6122,  6121,  6133,  6132,
    6148,  6153,  6158,  6168,  6167,  6179,  6178,  6193,  6194,  6198,
    6203,  6208,  6218,  6217,  6229,  6228,  6245,  6248,  6260,  6267,
    6274,  6274,  6284,  6285,  6286,  6290,  6292,  6293,  6295,  6296,
    6297,  6298,  6299,  6301,  6302,  6303,  6304,  6305,  6306,  6308,
    6309,  6310,  6312,  6313,  6314,  6315,  6316,  6319,  6320,  6323,
    6323,  6323,  6324,  6324,  6325,  6325,  6326,  6326,  6327,  6327,
    6332,  6333,  6336,  6337,  6338,  6342,  6343,  6344,  6345,  6346,
    6347,  6348,  6349,  6350,  6361,  6373,  6388,  6389,  6394,  6400,
    6406,  6426,  6430,  6446,  6460,  6461,  6466,  6472,  6473,  6478,
    6487,  6488,  6489,  6493,  6504,  6505,  6509,  6517,  6518,  6522,
    6523,  6529,  6549,  6550,  6554,  6555,  6559,  6560,  6564,  6565,
    6566,  6567,  6568,  6569,  6570,  6571,  6572,  6576,  6577,  6578,
    6579,  6580,  6581,  6582,  6586,  6587,  6591,  6592,  6596,  6597,
    6601,  6602,  6613,  6614,  6618,  6619,  6620,  6624,  6625,  6626,
    6634,  6638,  6639,  6640,  6641,  6645,  6646,  6650,  6658,  6662,
    6674,  6686,  6687,  6697,  6698,  6702,  6703,  6704,  6705,  6706,
    6707,  6708,  6716,  6720,  6724,  6728,  6732,  6736,  6740,  6744,
    6748,  6752,  6756,  6760,  6767,  6768,  6769,  6773,  6774,  6778,
    6779,  6784,  6791,  6798,  6808,  6815,  6825,  6832,  6846,  6856,
    6857,  6861,  6862,  6866,  6867,  6871,  6872,  6873,  6877,  6878,
    6882,  6883,  6887,  6888,  6892,  6893,  6900,  6900,  6901,  6901,
    6902,  6902,  6903,  6903,  6905,  6905,  6906,  6906,  6907,  6907,
    6908,  6908,  6909,  6909,  6910,  6910,  6911,  6911,  6912,  6912,
    6913,  6913,  6914,  6914,  6915,  6915,  6916,  6916,  6917,  6917,
    6918,  6918,  6919,  6919,  6920,  6920,  6921,  6921,  6921,  6922,
    6922,  6923,  6923,  6923,  6924,  6924,  6925,  6925,  6926,  6926,
    6927,  6927,  6928,  6928,  6929,  6929,  6929,  6930,  6930,  6931,
    6931,  6932,  6932,  6933,  6933,  6934,  6934,  6935,  6935,  6936,
    6936,  6936,  6937,  6937,  6938,  6938,  6939,  6939,  6940,  6940,
    6941,  6941,  6942,  6942,  6943,  6943,  6945,  6945,  6946,  6946
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "ACCEPT", "ACCESS", "ADD",
  "ADDRESS", "ADVANCING", "AFTER", "ALL", "ALLOCATE", "ALPHABET",
  "ALPHABETIC", "\"ALPHABETIC-LOWER\"", "\"ALPHABETIC-UPPER\"",
  "ALPHANUMERIC", "\"ALPHANUMERIC-EDITED\"", "ALSO", "ALTER", "ALTERNATE",
  "AND", "ANY", "ARE", "AREA", "\"ARGUMENT-NUMBER\"", "\"ARGUMENT-VALUE\"",
  "AS", "ASCENDING", "ASSIGN", "AT", "AUTO", "AUTOMATIC",
  "\"BACKGROUND-COLOR\"", "BASED", "BEFORE", "BELL", "BINARY",
  "\"BINARY-C-LONG\"", "\"BINARY-CHAR\"", "\"BINARY-DOUBLE\"",
  "\"BINARY-LONG\"", "\"BINARY-SHORT\"", "BLANK", "\"BLANK-LINE\"",
  "\"BLANK-SCREEN\"", "BLINK", "BLOCK", "BOTTOM", "BY", "\"BYTE-LENGTH\"",
  "CALL", "CANCEL", "CH", "CHAINING", "CHARACTER", "CHARACTERS", "CLASS",
  "CLOSE", "CODE", "\"CODE-SET\"", "COLLATING", "COL", "COLS", "COLUMN",
  "COLUMNS", "COMMA", "\"COMMAND-LINE\"", "\"comma delimiter\"", "COMMIT",
  "COMMON", "COMP", "COMPUTE", "\"COMP-1\"", "\"COMP-2\"", "\"COMP-3\"",
  "\"COMP-4\"", "\"COMP-5\"", "\"COMP-X\"", "\"FUNCTION CONCATENATE\"",
  "CONFIGURATION", "CONSTANT", "CONTAINS", "CONTENT", "CONTINUE",
  "CONTROL", "CONTROLS", "\"CONTROL FOOTING\"", "\"CONTROL HEADING\"",
  "CONVERTING", "CORRESPONDING", "COUNT", "CRT", "CURRENCY",
  "\"FUNCTION CURRENT-DATE\"", "CURSOR", "CYCLE", "DATA", "DATE", "DAY",
  "\"DAY-OF-WEEK\"", "DE", "DEBUGGING", "\"DECIMAL-POINT\"",
  "DECLARATIVES", "DEFAULT", "DELETE", "DELIMITED", "DELIMITER",
  "DEPENDING", "DESCENDING", "DETAIL", "DISK", "DISPLAY", "DIVIDE",
  "DIVISION", "DOWN", "DUPLICATES", "DYNAMIC", "EBCDIC", "ELSE", "END",
  "\"END-ACCEPT\"", "\"END-ADD\"", "\"END-CALL\"", "\"END-COMPUTE\"",
  "\"END-DELETE\"", "\"END-DISPLAY\"", "\"END-DIVIDE\"",
  "\"END-EVALUATE\"", "\"END FUNCTION\"", "\"END-IF\"", "\"END-MULTIPLY\"",
  "\"END-PERFORM\"", "\"END PROGRAM\"", "\"END-READ\"", "\"END-RETURN\"",
  "\"END-REWRITE\"", "\"END-SEARCH\"", "\"END-START\"", "\"END-STRING\"",
  "\"END-SUBTRACT\"", "\"END-UNSTRING\"", "\"END-WRITE\"", "ENTRY",
  "ENVIRONMENT", "\"ENVIRONMENT-NAME\"", "\"ENVIRONMENT-VALUE\"", "EOL",
  "EOP", "EOS", "EQUAL", "EQUALS", "ERASE", "ERROR", "ESCAPE", "EVALUATE",
  "\"EVENT-STATUS\"", "EXCEPTION", "EXCLUSIVE", "EXIT", "EXTEND",
  "EXTERNAL", "FD", "\"FILE-CONTROL\"", "\"FILE-ID\"", "FILLER", "FINAL",
  "FIRST", "FOOTING", "FOR", "\"FOREGROUND-COLOR\"", "FOREVER", "FREE",
  "FROM", "FULL", "FUNCTION", "\"FUNCTION-ID\"", "\"FUNCTION\"", "GE",
  "GENERATE", "GIVING", "GLOBAL", "GO", "GOBACK", "GREATER", "GROUP",
  "HEADING", "HIGHLIGHT", "\"HIGH-VALUE\"", "IDENTIFICATION", "IF",
  "IGNORE", "IGNORING", "IN", "INDEX", "INDEXED", "INDICATE", "INITIALIZE",
  "INITIALIZED", "INITIATE", "INPUT", "\"INPUT-OUTPUT\"", "INSPECT",
  "INTO", "INTRINSIC", "INVALID", "\"INVALID KEY\"", "IS", "\"I-O\"",
  "\"I-O-CONTROL\"", "JUSTIFIED", "KEY", "LABEL", "LAST",
  "\"LAST DETAIL\"", "LE", "LEADING", "LEFT", "LENGTH", "LESS", "LIMIT",
  "LIMITS", "LINAGE", "\"LINAGE-COUNTER\"", "LINE", "LINES", "LINKAGE",
  "\"Literal\"", "LOCALE", "\"FUNCTION LOCALE\"", "\"LOCAL-STORAGE\"",
  "LOCK", "\"FUNCTION LOWER-CASE\"", "LOWLIGHT", "\"LOW-VALUE\"", "MANUAL",
  "MEMORY", "MERGE", "MINUS", "\"MNEMONIC NAME\"", "MODE", "MOVE",
  "MULTIPLE", "MULTIPLY", "NATIONAL", "\"NATIONAL-EDITED\"", "NATIVE",
  "NE", "NEGATIVE", "NEXT", "\"NEXT SENTENCE\"", "NO", "NOT",
  "\"NOT END\"", "\"NOT EOP\"", "\"NOT EXCEPTION\"", "\"NOT INVALID KEY\"",
  "\"NOT OVERFLOW\"", "\"NOT SIZE ERROR\"", "\"NO ADVANCING\"", "NUMBER",
  "NUMBERS", "NUMERIC", "\"NUMERIC-EDITED\"", "\"FUNCTION NUMVALC\"",
  "\"OBJECT-COMPUTER\"", "OCCURS", "OF", "OFF", "OMITTED", "ON", "ONLY",
  "OPEN", "OPTIONAL", "OR", "ORDER", "ORGANIZATION", "OTHER", "OUTPUT",
  "OVERFLOW", "OVERLINE", "\"PACKED-DECIMAL\"", "PADDING", "PAGE",
  "\"PAGE FOOTING\"", "\"PAGE HEADING\"", "PARAGRAPH", "PERFORM",
  "PICTURE", "PLUS", "POINTER", "POSITION", "POSITIVE", "PRESENT",
  "PREVIOUS", "PRINTER", "PRINTING", "PROCEDURE", "PROCEDURES", "PROCEED",
  "PROGRAM", "\"PROGRAM-ID\"", "\"Program name\"", "\"PROGRAM-POINTER\"",
  "PROMPT", "QUOTE", "RANDOM", "RD", "READ", "RECORD", "RECORDING",
  "RECORDS", "RECURSIVE", "REDEFINES", "REEL", "REFERENCE", "RELATIVE",
  "RELEASE", "REMAINDER", "REMOVAL", "RENAMES", "REPLACING", "REPORT",
  "REPORTING", "REPORTS", "\"REPORT FOOTING\"", "\"REPORT HEADING\"",
  "REPOSITORY", "REQUIRED", "RESERVE", "RETURN", "RETURNING",
  "\"FUNCTION REVERSE\"", "\"REVERSE-VIDEO\"", "REWIND", "REWRITE",
  "RIGHT", "ROLLBACK", "ROUNDED", "RUN", "SAME", "SCREEN",
  "\"SCREEN-CONTROL\"", "SCROLL", "SD", "SEARCH", "SECTION", "SECURE",
  "\"SEGMENT-LIMIT\"", "SELECT", "\"semi-colon\"", "SENTENCE", "SEPARATE",
  "SEQUENCE", "SEQUENTIAL", "SET", "SHARING", "SIGN", "SIGNED",
  "\"SIGNED-INT\"", "\"SIGNED-LONG\"", "\"SIGNED-SHORT\"", "SIZE",
  "\"SIZE ERROR\"", "SORT", "\"SORT-MERGE\"", "SOURCE",
  "\"SOURCE-COMPUTER\"", "SPACE", "\"SPECIAL-NAMES\"", "STANDARD",
  "\"STANDARD-1\"", "\"STANDARD-2\"", "START", "STATUS", "STOP", "STRING",
  "\"FUNCTION SUBSTITUTE\"", "\"FUNCTION SUBSTITUTE-CASE\"", "SUBTRACT",
  "SUM", "SUPPRESS", "SYMBOLIC", "SYNCHRONIZED", "TALLYING", "TAPE",
  "TERMINATE", "TEST", "THAN", "THEN", "THRU", "TIME", "TIMES", "TO",
  "\"FALSE\"", "\"FILE\"", "\"INITIAL\"", "\"NULL\"", "\"TRUE\"", "TOP",
  "TRAILING", "TRANSFORM", "\"FUNCTION TRIM\"", "TYPE", "UNDERLINE",
  "UNIT", "UNLOCK", "UNSIGNED", "\"UNSIGNED-INT\"", "\"UNSIGNED-LONG\"",
  "\"UNSIGNED-SHORT\"", "UNSTRING", "UNTIL", "UP", "UPDATE", "UPON",
  "\"UPON ARGUMENT-NUMBER\"", "\"UPON COMMAND-LINE\"",
  "\"UPON ENVIRONMENT-NAME\"", "\"UPON ENVIRONMENT-VALUE\"",
  "\"FUNCTION UPPER-CASE\"", "USAGE", "USE", "USING", "VALUE", "VARYING",
  "WAIT", "WHEN", "\"FUNCTION WHEN-COMPILED\"", "WITH", "\"Identifier\"",
  "WORDS", "\"WORKING-STORAGE\"", "WRITE", "YYYYDDD", "YYYYMMDD", "ZERO",
  "'+'", "'-'", "'*'", "'/'", "UNARY_SIGN", "'^'", "'.'", "'='", "'('",
  "')'", "'>'", "'<'", "':'", "'&'", "$accept", "start", "$@1",
  "nested_list", "source_element", "program_definition", "$@2", "$@3",
  "program_mandatory", "$@4", "$@5", "function_definition", "$@6", "$@7",
  "nested_prog", "end_program", "end_mandatory", "end_function",
  "identification_division", "$@8", "function_division", "program_name",
  "as_literal", "program_type", "program_type_clause", "_init_or_recurs",
  "environment_division", "configuration_section", "configuration_list",
  "configuration_paragraph", "source_computer_paragraph",
  "source_computer_entry", "with_debugging_mode", "computer_name",
  "object_computer_paragraph", "object_computer_entry",
  "object_clauses_list", "object_clauses", "object_computer_memory",
  "object_char_or_word", "object_computer_sequence",
  "object_computer_segment", "repository_paragraph", "opt_repository",
  "repository_list", "repository_name", "repository_literal_list",
  "special_names_paragraph", "opt_special_names", "special_name_list",
  "special_name", "mnemonic_name_clause", "$@9",
  "special_name_mnemonic_on_off", "on_or_off", "alphabet_name_clause",
  "$@10", "alphabet_definition", "alphabet_literal_list",
  "alphabet_literal", "@11", "alphabet_also_sequence", "alphabet_lits",
  "alphabet_also_literal", "symbolic_characters_clause",
  "symbolic_characters_list", "char_list", "integer_list",
  "class_name_clause", "class_item_list", "class_item", "locale_clause",
  "currency_sign_clause", "decimal_point_clause", "cursor_clause",
  "crt_status_clause", "screen_control", "event_status",
  "input_output_section", "$@12", "$@13", "file_control_paragraph",
  "file_control_sequence", "file_control_entry", "$@14",
  "select_clause_sequence", "select_clause", "assign_clause", "_device",
  "_ext_clause", "assignment_name", "access_mode_clause", "access_mode",
  "alternative_record_key_clause", "collating_sequence_clause",
  "file_status_clause", "file_or_sort", "lock_mode_clause", "lock_mode",
  "lock_with", "lock_records", "organization_clause", "organization",
  "padding_character_clause", "record_delimiter_clause",
  "record_key_clause", "opt_splitk", "relative_key_clause",
  "reserve_clause", "sharing_clause", "sharing_option",
  "i_o_control_paragraph", "opt_i_o_control", "i_o_control_list",
  "i_o_control_clause", "same_clause", "same_option",
  "multiple_file_tape_clause", "multiple_file_list", "multiple_file",
  "multiple_file_position", "data_division", "file_section", "$@15",
  "$@16", "file_description_sequence", "file_description",
  "file_description_sequence_without_type", "file_type",
  "file_description_entry", "@17", "file_description_clause_sequence",
  "file_description_clause", "block_contains_clause",
  "_records_or_characters", "record_clause", "record_depending",
  "opt_from_integer", "opt_to_integer", "label_records_clause",
  "label_option", "value_of_clause", "valueof_name", "data_records_clause",
  "linage_clause", "linage_sequence", "linage_lines", "linage_footing",
  "linage_top", "linage_bottom", "recording_mode_clause",
  "code_set_clause", "report_clause", "working_storage_section", "$@18",
  "record_description_list", "record_description_list_1", "$@19",
  "record_description_list_2", "data_description", "$@20", "level_number",
  "entry_name", "const_name", "const_global", "lit_or_length",
  "constant_entry", "data_description_clause_sequence",
  "data_description_clause", "redefines_clause", "external_clause",
  "as_extname", "global_clause", "picture_clause", "usage_clause", "usage",
  "sign_clause", "occurs_clause", "occurs_to_integer", "occurs_depending",
  "occurs_keys", "occurs_key_list", "ascending_or_descending",
  "occurs_indexed", "occurs_index_list", "occurs_index",
  "justified_clause", "synchronized_clause", "left_or_right",
  "blank_clause", "based_clause", "value_clause", "$@21",
  "value_item_list", "value_item", "false_is", "renames_clause",
  "any_length_clause", "local_storage_section", "$@22", "linkage_section",
  "$@23", "report_section", "$@24", "opt_report_description_list",
  "report_description_list", "report_description_entry",
  "report_description_options", "report_description_option",
  "control_clause", "control_field_list", "_final", "identifier_list",
  "page_limit_clause", "heading_clause", "first_detail", "last_heading",
  "last_detail", "footing_clause", "page_line_column", "line_or_lines",
  "report_group_description_list", "report_group_description_entry",
  "report_group_options", "report_group_option", "type_clause",
  "type_option", "next_group_clause", "column_clause", "sum_clause_list",
  "sum_clause", "ref_id_exp", "present_when_condition", "varying_clause",
  "line_clause", "line_keyword_clause", "report_line_integer_list",
  "line_or_plus", "_numbers", "source_clause", "group_indicate_clause",
  "_indicate", "report_name", "screen_section", "$@25", "$@26",
  "opt_screen_description_list", "screen_description_list",
  "screen_description", "$@27", "screen_options", "screen_option",
  "screen_line_plus_minus", "screen_col_plus_minus",
  "screen_occurs_clause", "procedure_division", "$@28", "$@29",
  "procedure_using_chaining", "$@30", "$@31", "procedure_param_list",
  "procedure_param", "procedure_type", "size_optional",
  "procedure_optional", "procedure_returning", "procedure_declaratives",
  "$@32", "procedure_list", "procedure", "section_header",
  "paragraph_header", "invalid_statement", "section_name", "opt_segment",
  "statement_list", "@33", "@34", "statements", "$@35", "statement",
  "accept_statement", "$@36", "accept_body", "opt_at_line_column",
  "line_number", "column_number", "opt_accp_attr", "accp_attrs",
  "accp_attr", "end_accept", "add_statement", "$@37", "add_body", "add_to",
  "end_add", "allocate_statement", "$@38", "allocate_body",
  "allocate_returning", "alter_statement", "alter_options", "_proceed_to",
  "call_statement", "$@39", "call_using", "$@40", "call_param_list",
  "call_param", "call_type", "call_returning", "call_on_exception", "$@41",
  "call_not_on_exception", "$@42", "end_call", "cancel_statement", "$@43",
  "cancel_list", "close_statement", "$@44", "close_list", "close_option",
  "reel_or_unit", "compute_statement", "$@45", "compute_body",
  "end_compute", "comp_equal", "commit_statement", "continue_statement",
  "delete_statement", "$@46", "end_delete", "display_statement", "$@47",
  "display_body", "display_upon", "with_clause", "disp_attrs", "disp_attr",
  "end_display", "divide_statement", "$@48", "divide_body", "end_divide",
  "entry_statement", "$@49", "evaluate_statement", "$@50",
  "evaluate_subject_list", "evaluate_subject", "evaluate_condition_list",
  "evaluate_case_list", "evaluate_case", "$@51", "evaluate_other", "$@52",
  "evaluate_when_list", "evaluate_object_list", "evaluate_object",
  "opt_evaluate_thru_expr", "end_evaluate", "exit_statement", "$@53",
  "exit_body", "free_statement", "$@54", "generate_statement", "$@55",
  "goto_statement", "$@56", "goto_depending", "goback_statement", "$@57",
  "if_statement", "$@58", "$@59", "if_else_sentence", "$@60", "end_if",
  "initialize_statement", "$@61", "initialize_filler", "initialize_value",
  "initialize_replacing", "initialize_replacing_list",
  "initialize_replacing_item", "initialize_category", "initialize_default",
  "initiate_statement", "$@62", "inspect_statement", "$@63",
  "send_identifier", "inspect_list", "inspect_item", "inspect_tallying",
  "$@64", "tallying_list", "tallying_item", "inspect_replacing",
  "replacing_list", "replacing_item", "rep_keyword", "replacing_region",
  "inspect_converting", "inspect_region", "_initial", "merge_statement",
  "$@65", "move_statement", "$@66", "move_body", "multiply_statement",
  "$@67", "multiply_body", "end_multiply", "open_statement", "$@68",
  "open_list", "open_mode", "open_sharing", "open_option",
  "perform_statement", "$@69", "perform_body", "$@70", "end_perform",
  "perform_procedure", "perform_option", "perform_test",
  "perform_varying_list", "perform_varying", "read_statement", "$@71",
  "read_into", "with_lock", "read_key", "read_handler", "end_read",
  "release_statement", "$@72", "return_statement", "$@73", "end_return",
  "rewrite_statement", "$@74", "write_lock", "end_rewrite",
  "rollback_statement", "search_statement", "$@75", "search_body", "$@76",
  "search_varying", "search_at_end", "$@77", "search_whens", "search_when",
  "$@78", "end_search", "set_statement", "$@79", "set_body",
  "set_environment", "set_to", "set_up_down", "up_or_down",
  "set_to_on_off_sequence", "set_to_on_off", "set_to_true_false_sequence",
  "set_to_true_false", "sort_statement", "$@80", "sort_body", "$@81",
  "sort_key_list", "opt_key_list", "sort_duplicates", "sort_collating",
  "sort_input", "sort_output", "start_statement", "$@82", "@83",
  "start_key", "start_op", "end_start", "stop_statement", "$@84",
  "stop_returning", "string_statement", "$@85", "string_item_list",
  "string_item", "opt_with_pointer", "end_string", "subtract_statement",
  "$@86", "subtract_body", "end_subtract", "suppress_statement",
  "_printing", "terminate_statement", "$@87", "transform_statement",
  "$@88", "unlock_statement", "$@89", "opt_record", "unstring_statement",
  "$@90", "unstring_delimited", "unstring_delimited_list",
  "unstring_delimited_item", "unstring_into", "unstring_into_item",
  "unstring_into_delimiter", "unstring_into_count", "unstring_tallying",
  "end_unstring", "use_statement", "use_exception", "use_global",
  "use_exception_target", "_after", "_standard", "exception_or_error",
  "exception_or_overflow", "not_exception_or_overflow", "_procedure",
  "use_debugging", "use_debugging_target", "use_reporting",
  "write_statement", "$@91", "write_from", "write_option",
  "before_or_after", "write_handler", "end_write", "on_accp_exception",
  "on_disp_exception", "opt_on_exception", "$@92", "opt_not_on_exception",
  "$@93", "on_size_error", "opt_on_size_error", "$@94",
  "opt_not_on_size_error", "$@95", "on_overflow", "opt_on_overflow",
  "$@96", "opt_not_on_overflow", "$@97", "at_end", "at_end_sentence",
  "$@98", "not_at_end_sentence", "$@99", "at_eop", "at_eop_sentence",
  "$@100", "not_at_eop_sentence", "$@101", "opt_invalid_key",
  "invalid_key", "invalid_key_sentence", "$@102",
  "not_invalid_key_sentence", "$@103", "_opt_scroll_lines", "condition",
  "expr", "partial_expr", "$@104", "expr_tokens", "expr_token", "eq", "gt",
  "lt", "ge", "le", "exp_list", "e_sep", "exp", "linage_counter",
  "arithmetic_x_list", "arithmetic_x", "record_name", "table_name",
  "file_name_list", "file_name", "mnemonic_name_list", "mnemonic_name",
  "procedure_name_list", "procedure_name", "label", "integer_label",
  "reference_list", "reference", "opt_reference", "reference_or_literal",
  "undefined_word", "target_x_list", "target_x", "x_list", "x", "arith_x",
  "prog_or_entry", "alnum_or_id", "simple_value", "simple_all_value",
  "id_or_lit", "id_or_lit_or_func", "num_id_or_lit", "identifier",
  "identifier_1", "qualified_word", "subref", "refmod", "integer",
  "literal", "basic_literal", "basic_value", "function", "func_refmod",
  "func_args", "list_func_args", "trim_args", "numvalc_args",
  "locale_dt_args", "not_const_word", "flag_all", "flag_duplicates",
  "flag_initialized", "flag_next", "flag_not", "flag_optional",
  "flag_rounded", "flag_separate", "in_of", "records", "with_dups",
  "coll_sequence", "_advancing", "_are", "_area", "_as", "_at", "_binary",
  "_by", "_character", "_characters", "_contains", "_data", "_file",
  "_for", "_from", "_in", "_is", "_is_are", "_key", "_line_or_lines",
  "_lines", "_mode", "_number", "_of", "_on", "_in_order", "_other",
  "_program", "_record", "_right", "_set", "_sign", "_sign_is", "_size",
  "_status", "_tape", "_than", "_then", "_times", "_to", "_when", "_with", YY_NULL
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
     685,   686,   687,   688,   689,   690,   691,    43,    45,    42,
      47,   692,    94,    46,    61,    40,    41,    62,    60,    58,
      38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   451,   453,   452,   454,   454,   455,   455,   457,   458,
     456,   460,   461,   459,   463,   464,   462,   465,   465,   465,
     466,   466,   467,   468,   470,   469,   471,   472,   472,   473,
     473,   474,   474,   475,   475,   475,   476,   476,   477,   477,
     478,   478,   479,   479,   480,   480,   480,   480,   481,   482,
     482,   482,   482,   483,   484,   485,   486,   486,   486,   486,
     487,   487,   488,   488,   488,   489,   490,   490,   491,   492,
     493,   494,   494,   495,   495,   496,   496,   497,   497,   498,
     499,   499,   500,   500,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   502,   503,   502,   504,   504,
     505,   505,   507,   506,   508,   508,   508,   508,   508,   509,
     509,   510,   510,   511,   510,   512,   512,   513,   513,   513,
     513,   513,   513,   514,   514,   514,   514,   514,   514,   515,
     516,   517,   517,   518,   518,   519,   520,   520,   521,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   529,   530,
     529,   531,   529,   532,   532,   533,   533,   535,   534,   536,
     536,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   538,   538,   539,   539,   539,   540,
     540,   540,   541,   541,   541,   542,   543,   543,   543,   544,
     545,   546,   547,   547,   547,   548,   549,   549,   549,   550,
     550,   550,   550,   551,   551,   552,   552,   553,   553,   553,
     553,   553,   554,   555,   556,   557,   557,   557,   558,   559,
     560,   561,   561,   561,   562,   562,   563,   563,   564,   564,
     565,   565,   566,   567,   567,   567,   567,   568,   569,   569,
     570,   571,   571,   572,   572,   573,   574,   573,   575,   573,
     576,   576,   577,   578,   578,   579,   579,   581,   580,   582,
     582,   583,   583,   583,   583,   583,   583,   583,   583,   583,
     583,   583,   584,   585,   585,   585,   586,   586,   586,   587,
     587,   588,   588,   589,   589,   590,   591,   591,   592,   592,
     593,   593,   594,   595,   596,   596,   597,   597,   597,   598,
     599,   600,   601,   602,   603,   603,   604,   605,   604,   606,
     606,   608,   607,   609,   609,   609,   610,   611,   610,   612,
     613,   613,   613,   614,   615,   615,   616,   616,   616,   617,
     618,   618,   619,   619,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   619,   620,   621,   622,   622,
     623,   624,   625,   625,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   627,
     627,   628,   629,   629,   630,   630,   631,   632,   632,   633,
     633,   634,   634,   635,   635,   636,   637,   638,   639,   639,
     639,   640,   641,   643,   642,   644,   644,   645,   645,   646,
     646,   647,   647,   648,   649,   650,   649,   651,   652,   651,
     653,   654,   653,   655,   655,   656,   656,   657,   658,   658,
     659,   659,   659,   659,   660,   660,   661,   662,   662,   663,
     663,   664,   665,   665,   666,   666,   667,   667,   668,   668,
     669,   669,   670,   670,   670,   671,   671,   672,   672,   673,
     674,   674,   675,   675,   675,   675,   675,   675,   675,   675,
     675,   675,   675,   675,   675,   675,   675,   675,   676,   677,
     677,   677,   677,   677,   677,   677,   678,   679,   679,   679,
     680,   680,   681,   682,   683,   684,   685,   686,   686,   687,
     687,   688,   688,   688,   689,   689,   689,   690,   691,   692,
     692,   693,   694,   695,   696,   694,   697,   697,   698,   698,
     699,   700,   699,   701,   701,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   703,   703,   703,   703,   703,
     704,   704,   704,   704,   704,   705,   706,   707,   708,   706,
     709,   710,   709,   711,   709,   712,   712,   713,   714,   714,
     714,   715,   715,   715,   715,   715,   716,   716,   717,   717,
     718,   719,   718,   720,   720,   721,   721,   721,   721,   721,
     721,   722,   723,   724,   725,   726,   726,   728,   729,   727,
     731,   730,   730,   732,   732,   732,   732,   732,   732,   732,
     732,   732,   732,   732,   732,   732,   732,   732,   732,   732,
     732,   732,   732,   732,   732,   732,   732,   732,   732,   732,
     732,   732,   732,   732,   732,   732,   732,   732,   732,   732,
     732,   732,   732,   732,   732,   732,   732,   732,   732,   732,
     732,   732,   734,   733,   735,   735,   735,   735,   735,   735,
     735,   735,   735,   735,   735,   735,   735,   735,   735,   735,
     735,   736,   736,   736,   736,   736,   736,   737,   738,   738,
     739,   739,   740,   740,   741,   741,   741,   741,   741,   741,
     741,   741,   741,   741,   741,   741,   741,   741,   741,   741,
     741,   742,   742,   744,   743,   745,   745,   745,   746,   746,
     747,   747,   749,   748,   750,   750,   751,   751,   752,   753,
     753,   754,   754,   756,   755,   757,   758,   757,   759,   759,
     760,   760,   761,   761,   761,   761,   762,   762,   762,   763,
     764,   763,   765,   766,   765,   767,   767,   769,   768,   770,
     770,   772,   771,   773,   773,   774,   774,   774,   774,   774,
     775,   775,   777,   776,   778,   779,   779,   780,   780,   781,
     782,   784,   783,   785,   785,   787,   786,   788,   788,   788,
     788,   788,   789,   789,   789,   789,   789,   790,   790,   790,
     791,   791,   792,   792,   792,   792,   792,   792,   792,   792,
     792,   792,   792,   792,   792,   792,   792,   793,   793,   795,
     794,   796,   796,   796,   796,   796,   797,   797,   799,   798,
     801,   800,   802,   802,   803,   803,   803,   804,   805,   805,
     807,   806,   808,   809,   808,   810,   810,   811,   811,   812,
     812,   812,   812,   813,   813,   814,   814,   816,   815,   817,
     817,   817,   817,   817,   817,   819,   818,   821,   820,   823,
     822,   824,   824,   826,   825,   828,   829,   827,   827,   830,
     831,   830,   832,   832,   834,   833,   835,   835,   836,   836,
     836,   837,   837,   838,   838,   839,   840,   840,   840,   840,
     840,   840,   840,   841,   841,   843,   842,   845,   844,   846,
     846,   846,   847,   847,   848,   848,   848,   850,   849,   851,
     851,   852,   852,   852,   852,   852,   852,   853,   854,   854,
     855,   855,   856,   856,   856,   856,   856,   857,   858,   859,
     859,   860,   860,   862,   861,   864,   863,   865,   865,   867,
     866,   868,   868,   869,   869,   871,   870,   872,   872,   873,
     873,   873,   873,   874,   874,   875,   875,   875,   877,   876,
     878,   879,   878,   878,   880,   880,   881,   881,   882,   882,
     882,   882,   882,   883,   883,   884,   884,   885,   887,   886,
     888,   888,   889,   889,   889,   889,   889,   889,   890,   890,
     891,   891,   891,   892,   892,   894,   893,   896,   895,   897,
     897,   899,   898,   900,   900,   900,   901,   901,   902,   904,
     903,   905,   906,   905,   907,   907,   908,   909,   908,   910,
     910,   912,   911,   913,   913,   915,   914,   916,   916,   916,
     916,   916,   917,   918,   918,   919,   920,   920,   921,   921,
     922,   923,   923,   924,   924,   926,   925,   928,   927,   929,
     929,   930,   930,   931,   931,   932,   932,   933,   933,   933,
     934,   934,   934,   936,   937,   935,   938,   938,   939,   939,
     939,   939,   939,   940,   940,   942,   941,   941,   943,   943,
     943,   945,   944,   946,   946,   947,   947,   947,   948,   948,
     949,   949,   951,   950,   952,   952,   952,   953,   953,   954,
     955,   955,   957,   956,   959,   958,   961,   960,   962,   962,
     962,   964,   963,   965,   965,   966,   966,   967,   968,   968,
     969,   970,   970,   971,   971,   972,   972,   973,   973,   974,
     974,   974,   975,   976,   976,   977,   977,   977,   977,   977,
     978,   978,   979,   979,   980,   980,   981,   981,   982,   982,
     983,   983,   984,   985,   985,   986,   988,   987,   989,   989,
     990,   990,   990,   990,   991,   991,   992,   992,   992,   993,
     993,   994,   995,   996,   997,   996,   998,   999,   998,  1000,
    1001,  1002,  1001,  1003,  1004,  1003,  1005,  1006,  1007,  1006,
    1008,  1009,  1008,  1010,  1010,  1010,  1012,  1011,  1014,  1013,
    1015,  1015,  1015,  1017,  1016,  1019,  1018,  1020,  1020,  1021,
    1021,  1021,  1023,  1022,  1025,  1024,  1026,  1026,  1027,  1028,
    1030,  1029,  1031,  1031,  1031,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1033,
    1033,  1033,  1034,  1034,  1035,  1035,  1036,  1036,  1037,  1037,
    1038,  1038,  1039,  1039,  1039,  1040,  1040,  1040,  1040,  1040,
    1040,  1040,  1040,  1040,  1041,  1041,  1042,  1042,  1043,  1044,
    1045,  1046,  1046,  1047,  1048,  1048,  1049,  1050,  1050,  1051,
    1052,  1052,  1052,  1053,  1054,  1054,  1055,  1056,  1056,  1057,
    1057,  1058,  1059,  1059,  1060,  1060,  1061,  1061,  1062,  1062,
    1062,  1062,  1062,  1062,  1062,  1062,  1062,  1063,  1063,  1063,
    1063,  1063,  1063,  1063,  1064,  1064,  1065,  1065,  1066,  1066,
    1067,  1067,  1068,  1068,  1069,  1069,  1069,  1070,  1070,  1070,
    1071,  1072,  1072,  1072,  1072,  1073,  1073,  1074,  1075,  1075,
    1076,  1077,  1077,  1078,  1078,  1079,  1079,  1079,  1079,  1079,
    1079,  1079,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1081,  1081,  1081,  1082,  1082,  1083,
    1083,  1084,  1084,  1084,  1085,  1085,  1086,  1086,  1087,  1088,
    1088,  1089,  1089,  1090,  1090,  1091,  1091,  1091,  1092,  1092,
    1093,  1093,  1094,  1094,  1095,  1095,  1096,  1096,  1097,  1097,
    1098,  1098,  1099,  1099,  1100,  1100,  1101,  1101,  1102,  1102,
    1103,  1103,  1104,  1104,  1105,  1105,  1106,  1106,  1107,  1107,
    1108,  1108,  1109,  1109,  1110,  1110,  1111,  1111,  1112,  1112,
    1113,  1113,  1114,  1114,  1115,  1115,  1116,  1116,  1116,  1117,
    1117,  1118,  1118,  1118,  1119,  1119,  1120,  1120,  1121,  1121,
    1122,  1122,  1123,  1123,  1124,  1124,  1124,  1125,  1125,  1126,
    1126,  1127,  1127,  1128,  1128,  1129,  1129,  1130,  1130,  1131,
    1131,  1131,  1132,  1132,  1133,  1133,  1134,  1134,  1135,  1135,
    1136,  1136,  1137,  1137,  1138,  1138,  1139,  1139,  1140,  1140
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     0,     0,
       8,     0,     0,     8,     0,     0,     7,     0,     1,     2,
       0,     3,     3,     3,     0,     7,     5,     1,     1,     0,
       2,     0,     3,     1,     2,     1,     1,     1,     0,     5,
       0,     4,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     3,     2,     3,     1,     3,     0,     2,     3,     2,
       1,     2,     1,     1,     1,     5,     1,     1,     4,     3,
       3,     0,     2,     1,     2,     3,     3,     1,     2,     3,
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     5,     0,     5,
       1,     1,     0,     5,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     0,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     1,     2,     4,     1,     2,     1,     3,
       4,     4,     3,     3,     4,     3,     3,     0,     5,     0,
       4,     0,     4,     0,     3,     0,     2,     0,     6,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     0,     1,     1,     0,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     6,
       3,     5,     0,     1,     1,     4,     2,     2,     1,     0,
       4,     5,     2,     1,     1,     3,     1,     1,     3,     1,
       1,     2,     4,     4,     4,     1,     3,     4,     4,     3,
       3,     2,     2,     2,     0,     3,     0,     2,     1,     2,
       1,     1,     5,     0,     1,     1,     1,     5,     1,     2,
       2,     0,     2,     0,     9,     0,     0,     5,     0,     3,
       0,     2,     3,     2,     2,     1,     1,     0,     4,     0,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     0,     1,     1,     4,     6,     9,     0,
       3,     0,     2,     0,     2,     3,     1,     1,     5,     5,
       1,     1,     3,     5,     0,     2,     1,     1,     1,     5,
       4,     3,     4,     3,     3,     3,     0,     0,     5,     0,
       1,     0,     2,     3,     4,     2,     1,     0,     4,     1,
       0,     1,     1,     1,     0,     2,     1,     3,     3,     6,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     0,     2,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     1,     3,
       3,     7,     0,     2,     0,     3,     1,     0,     5,     1,
       1,     0,     3,     1,     2,     1,     2,     2,     0,     1,
       1,     3,     1,     0,     8,     1,     2,     1,     3,     0,
       3,     2,     4,     2,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     1,     1,     2,     5,     0,     2,
       2,     3,     1,     1,     2,     2,     2,     0,     1,     1,
       2,     8,     0,     3,     0,     4,     0,     4,     0,     3,
       0,     3,     1,     4,     2,     1,     1,     0,     2,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     1,
       1,     2,     3,     1,     3,     6,     2,     3,     2,     1,
       2,     2,     1,     2,     0,     1,     1,     4,     2,     0,
       1,     1,     0,     0,     0,     6,     0,     1,     1,     2,
       1,     0,     5,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     0,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     3,     0,     0,     0,     9,
       0,     0,     3,     0,     3,     1,     2,     4,     0,     2,
       2,     0,     3,     3,     4,     3,     0,     1,     0,     2,
       0,     0,     7,     0,     2,     1,     1,     1,     2,     2,
       1,     4,     2,     1,     1,     0,     1,     0,     0,     3,
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     4,     4,     3,     3,     3,     4,
       3,     4,     3,     3,     3,     4,     5,     3,     4,     3,
       3,     0,     3,     3,     2,     2,     2,     3,     3,     3,
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     4,     4,     5,     6,     0,     2,
       0,     1,     0,     3,     3,     5,     0,     2,     2,     0,
       5,     0,     2,     0,     8,     0,     0,     3,     1,     2,
       2,     3,     0,     2,     2,     2,     0,     2,     2,     0,
       0,     3,     0,     0,     3,     0,     1,     0,     3,     0,
       2,     0,     3,     0,     3,     0,     1,     3,     3,     2,
       1,     1,     0,     4,     4,     0,     1,     1,     1,     1,
       1,     0,     6,     0,     1,     0,     4,     3,     3,     3,
       3,     5,     0,     2,     2,     2,     2,     0,     2,     2,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1,     1,     0,     1,     0,
       4,     4,     6,     6,     8,     8,     0,     1,     0,     4,
       0,     5,     1,     3,     1,     1,     1,     2,     1,     2,
       0,     3,     0,     0,     4,     2,     3,     1,     3,     2,
       1,     1,     1,     0,     2,     0,     1,     0,     3,     0,
       1,     1,     2,     1,     1,     0,     3,     0,     3,     0,
       5,     0,     3,     0,     2,     0,     0,     8,     3,     0,
       0,     3,     0,     1,     0,     7,     0,     2,     0,     3,
       3,     0,     2,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     3,     0,     4,     1,
       1,     1,     1,     2,     1,     1,     1,     0,     3,     1,
       2,     2,     2,     1,     1,     1,     2,     2,     1,     2,
       4,     2,     0,     1,     1,     1,     1,     4,     5,     0,
       4,     0,     1,     0,     3,     0,     3,     3,     4,     0,
       4,     4,     6,     0,     1,     0,     3,     0,     5,     1,
       1,     1,     1,     0,     3,     0,     3,     2,     0,     3,
       2,     0,     4,     2,     0,     1,     1,     3,     0,     1,
       2,     3,     3,     0,     3,     1,     3,     7,     0,    10,
       0,     2,     0,     2,     2,     3,     3,     2,     0,     3,
       0,     1,     1,     0,     1,     0,     4,     0,     7,     0,
       1,     0,     7,     0,     2,     3,     0,     1,     1,     0,
       4,     4,     0,     7,     0,     2,     0,     0,     4,     1,
       2,     0,     4,     0,     1,     0,     3,     1,     1,     1,
       1,     1,     4,     4,     3,     4,     1,     1,     1,     2,
       3,     1,     2,     3,     3,     0,     3,     0,     7,     0,
       5,     0,     2,     0,     2,     0,     3,     0,     2,     4,
       0,     2,     4,     0,     0,     7,     0,     4,     2,     2,
       2,     2,     2,     0,     1,     0,     4,     2,     0,     2,
       2,     0,     8,     1,     2,     1,     3,     3,     0,     3,
       0,     1,     0,     4,     4,     6,     6,     0,     1,     2,
       0,     1,     0,     3,     0,     7,     0,     4,     0,     1,
       1,     0,     9,     0,     3,     1,     3,     2,     2,     2,
       3,     0,     3,     0,     3,     0,     3,     0,     1,     1,
       1,     1,     8,     0,     1,     1,     1,     1,     1,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     5,     1,     2,     5,     0,     8,     0,     2,
       0,     4,     3,     3,     1,     1,     0,     1,     1,     0,
       1,     2,     2,     0,     0,     3,     0,     0,     3,     2,
       0,     0,     3,     0,     0,     3,     2,     0,     0,     3,
       0,     0,     3,     1,     1,     2,     0,     3,     0,     3,
       1,     1,     2,     0,     3,     0,     3,     0,     1,     1,
       1,     2,     0,     3,     0,     3,     0,     3,     1,     1,
       0,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     1,     2,     1,     5,     1,     5,
       1,     3,     0,     1,     1,     1,     3,     3,     3,     3,
       2,     2,     3,     3,     1,     3,     1,     2,     2,     1,
       1,     1,     2,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     3,     1,     1,     2,     1,     0,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     3,
       3,     3,     4,     3,     1,     1,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     3,     3,     4,     5,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     5,     5,     5,     5,     5,     5,
       5,     4,     5,     2,     0,     4,     5,     0,     3,     0,
       1,     1,     3,     3,     1,     3,     1,     3,     0,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     0,     1,
       0,     1,     0,     1,     0,     2,     1,     1,     2,     2,
       2,     1,     2,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     1,     0,
       1,     0,     1,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     2,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     4,     6,     7,
      38,    38,     0,     0,     5,     0,     8,    14,    28,    27,
      29,    29,     0,   243,   243,     0,     0,    24,    40,     0,
       9,    15,    30,    26,  1464,     0,   147,     0,   576,   576,
    1465,     0,     0,     0,     0,     0,     0,    39,   245,     0,
      17,     0,    25,    33,    37,    36,  1489,    35,    42,   149,
       0,   151,   255,   256,     0,   306,   248,   580,    18,    20,
      38,     0,    16,    34,  1490,    32,    41,   155,   153,   226,
       0,     0,   424,     0,   583,   581,   598,     0,    19,    10,
      11,     0,     0,     0,     0,     0,    43,    44,    45,    47,
      46,   150,     0,   224,  1456,   233,   152,     0,   228,   230,
     231,   246,     0,     0,   427,  1303,   249,   309,   257,   588,
     588,     0,     0,     0,   243,    23,    56,    71,    49,    80,
    1420,   156,   155,     0,   148,  1457,  1506,   234,   235,   236,
    1438,   227,   229,   250,   307,     0,     0,   430,   254,     0,
     253,   310,  1408,   259,  1447,   588,   585,   591,     0,   588,
     599,   577,    21,    12,     0,  1464,    54,  1489,    55,  1489,
      60,    62,    63,    64,     0,     0,    70,     0,    73,  1519,
      48,     0,  1518,     0,     0,     0,     0,  1497,  1464,  1464,
    1464,     0,  1464,  1450,  1464,    79,     0,    82,    84,    85,
      86,    88,    87,    89,    90,    91,    92,    93,    94,  1421,
       0,   154,   226,  1507,  1452,  1439,  1458,   247,   309,   425,
       0,     0,   522,   309,   312,     0,  1464,   586,  1464,     0,
     596,   589,   590,   600,   576,  1464,     0,    57,  1489,    59,
      61,     0,  1433,  1464,     0,    77,     0,    72,    74,    52,
      50,     0,     0,  1321,   102,  1464,  1464,  1498,  1464,     0,
       0,     0,  1464,     0,  1451,     0,     0,    81,    83,   157,
     225,  1453,     0,  1459,     0,   251,   308,   309,   428,     0,
       0,   244,   252,   315,     0,   319,     0,   320,   316,  1452,
    1464,     0,     0,  1464,  1452,  1476,  1464,  1436,     0,   258,
     260,   263,   264,   265,   266,   267,   268,   269,   270,   271,
       0,     0,  1464,   597,     0,     0,   578,    17,     0,  1370,
      69,    58,  1432,     0,    76,    75,    78,    51,    53,  1464,
       0,     0,     0,  1365,   143,  1316,   142,   146,     0,   145,
     129,  1466,   131,    95,    96,   159,   237,   238,   241,   232,
    1301,   426,   309,   431,     0,     0,   313,   321,   322,   317,
       0,     0,     0,  1464,  1436,     0,     0,     0,     0,     0,
    1477,  1464,     0,  1437,     0,     0,   261,   262,   592,   593,
     595,     0,   587,   601,   603,     0,     0,    68,     0,  1379,
    1375,  1380,  1378,  1376,  1381,  1377,   135,   136,   138,   144,
     141,  1426,  1427,     0,   140,  1468,  1467,   132,     0,    98,
     192,   239,     0,   240,  1302,   429,   433,   523,   314,   330,
     324,   283,   303,  1428,  1429,   292,  1314,   287,   286,   285,
    1320,  1319,  1474,  1450,  1462,     0,   521,   304,   305,  1464,
    1464,   594,   603,     0,     0,    13,    66,    67,    65,   107,
     121,   117,   122,   104,   120,   118,   105,   106,   119,   103,
     108,   109,   111,   137,     0,  1366,   130,   133,    97,  1476,
       0,  1514,   207,     0,  1476,  1464,  1448,  1469,   210,     0,
     209,  1518,   194,   193,   158,   160,   161,   162,   163,   164,
     165,     0,   166,   167,   206,   168,   169,   170,   171,   172,
     173,  1464,   242,     0,   432,   434,   435,   524,  1464,  1440,
       0,     0,   273,  1315,  1475,   294,     0,   276,  1463,  1502,
     302,     0,     0,     0,     0,   614,   610,   604,   605,   606,
     607,   613,     0,     0,     0,   110,   113,     0,   139,   134,
     101,   100,  1504,  1464,  1469,  1515,   179,   211,  1464,     0,
    1449,  1464,  1445,  1464,  1470,     0,  1464,  1464,  1438,     0,
    1464,     0,   438,   436,   526,     0,   412,   354,   387,   375,
     384,   381,   378,  1516,   355,   356,   357,   358,   359,   360,
     361,   362,   363,  1493,   388,     0,   364,   351,   365,   366,
       0,     0,  1500,   368,   369,   367,   408,   371,   372,   370,
    1464,  1466,   331,   332,   333,   334,   335,   336,   352,   337,
     338,   339,   340,   341,   342,   343,   344,   345,     0,     0,
    1441,     0,   325,   284,   275,   274,   272,   293,  1450,  1503,
     281,   290,   289,   291,   288,     0,   609,   612,   615,   672,
     723,   732,   739,   743,   767,   771,   789,   782,   790,   791,
     795,   829,   838,   840,   867,   875,   877,  1514,   883,     0,
     894,   915,   917,   953,   955,   959,   671,   965,   978,   998,
    1015,  1017,  1021,  1028,  1029,  1045,  1065,  1083,     0,  1101,
    1112,  1120,  1122,  1124,  1126,  1131,  1153,  1176,   608,   622,
     623,   624,   625,   626,   627,   628,   629,   631,   630,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,  1149,  1150,  1151,
     670,   621,    22,     0,   112,  1505,  1464,     0,  1464,   181,
     180,   176,     0,  1444,   210,   205,     0,     0,   208,     0,
       0,   219,  1487,  1487,     0,   220,     0,   190,  1464,   320,
     530,   525,   527,   528,   423,   385,   386,   373,   374,   382,
     383,   379,   380,   376,   377,  1517,     0,  1494,   406,   392,
     346,  1361,   421,  1501,   409,   410,   407,     0,     0,   348,
     350,  1424,  1424,     0,  1480,  1480,   329,   326,  1371,  1373,
    1443,   295,   296,   297,   298,     0,     0,   277,  1461,   283,
       0,     0,   616,     0,     0,     0,  1240,   738,     0,   769,
     773,     0,     0,     0,     0,     0,  1240,   869,     0,     0,
     879,   884,     0,  1240,     0,     0,     0,     0,     0,     0,
     967,   988,     0,     0,     0,     0,     0,     0,     0,     0,
    1097,  1095,     0,     0,  1121,  1119,     0,     0,     0,     0,
    1154,  1160,     0,     0,   127,   123,   128,   126,   124,   125,
     114,   115,     0,   187,   188,   186,   185,     0,   175,   178,
       0,   199,   198,   199,   195,   212,   213,   214,   215,   218,
    1488,   221,   222,   223,  1317,  1464,   447,   447,  1466,   467,
     439,   442,   443,     0,   531,   529,   411,     0,  1512,     0,
    1362,  1363,     0,   353,   413,   415,   417,     0,   347,  1448,
     389,   390,  1372,  1481,     0,     0,     0,     0,     0,  1442,
    1450,   282,   602,   611,   721,   691,  1360,  1480,     0,     0,
    1394,  1397,  1480,  1294,     0,     0,     0,     0,     0,     0,
       0,     0,  1394,   730,  1336,   728,  1326,  1328,  1334,  1335,
    1413,   733,     0,  1239,     0,  1313,     0,  1309,  1311,  1310,
    1355,   745,  1354,  1356,   768,   772,   785,     0,  1296,  1422,
    1491,  1375,   827,   691,     0,  1328,   836,     0,   745,   846,
     845,     0,   842,   844,   874,   871,   870,   873,   868,  1480,
     876,  1322,  1324,   878,  1307,   888,  1510,  1238,   896,   916,
     449,     0,   919,   920,   921,   954,  1069,     0,   956,     0,
     963,     0,   966,   989,  1313,   979,   988,   981,     0,   986,
       0,  1310,     0,  1415,  1178,  1299,  1491,  1178,     0,  1043,
    1034,  1300,     0,  1306,  1046,  1047,  1048,  1049,  1050,  1058,
    1051,  1061,     0,  1304,     0,  1066,  1084,  1098,  1446,     0,
    1103,  1105,     0,  1117,     0,  1123,     0,  1128,  1133,  1161,
       0,  1162,  1482,  1178,     0,    99,  1411,   183,   182,   174,
     184,     0,   197,   196,  1464,     0,  1318,   191,     0,   448,
     444,     0,   445,     0,   437,   440,   533,   393,  1513,   394,
    1480,     0,     0,     0,  1282,  1280,  1343,  1285,  1337,  1341,
    1342,     0,  1364,   422,  1516,   416,     0,   349,  1425,   328,
     327,  1374,   301,  1474,     0,   279,   722,   673,  1443,     0,
     700,     0,     0,     0,     0,     0,  1382,  1399,  1393,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1383,
     731,   724,     0,     0,  1327,  1414,   736,  1413,  1264,  1265,
    1266,  1260,  1514,  1271,  1256,  1508,  1257,  1508,  1258,  1268,
    1259,  1263,  1262,  1261,  1267,  1248,  1249,  1250,  1251,  1252,
    1269,  1246,  1247,  1272,  1274,  1241,  1242,  1253,  1254,  1255,
    1245,   741,     0,   746,   756,  1353,   770,  1352,   775,   786,
     783,   788,   787,  1240,  1297,  1423,  1298,  1492,  1227,   828,
     796,   802,  1193,  1193,  1193,  1193,   837,   830,     0,     0,
     839,  1240,  1240,   865,   852,   848,   850,   872,     0,  1323,
     881,  1511,   886,   898,     0,   450,     0,   942,   927,   918,
     922,   924,   925,   926,  1073,     0,     0,   964,   960,     0,
     972,   969,   971,   970,   973,   980,   983,   617,  1240,     0,
       0,   990,     0,  1416,  1417,  1491,     0,  1016,  1000,  1023,
    1036,  1044,  1030,     0,  1036,     0,  1348,  1349,  1059,  1062,
       0,     0,  1305,  1057,     0,  1056,     0,  1086,     0,     0,
    1096,     0,     0,  1104,     0,  1118,  1113,     0,     0,  1129,
    1130,  1127,  1446,     0,     0,  1163,     0,  1483,     0,  1023,
     116,  1431,     0,   189,  1412,     0,   202,     0,   216,   441,
     446,   452,   462,   320,   468,  1499,  1482,   397,     0,  1290,
    1291,     0,  1283,  1284,  1367,     0,     0,     0,     0,     0,
       0,     0,     0,  1495,   418,   300,  1474,  1482,   278,   696,
     687,  1193,   677,   684,   678,   680,   682,     0,  1193,     0,
     676,   683,   690,   689,     0,  1193,  1478,  1478,  1478,   694,
     695,  1345,  1344,     0,  1333,  1282,  1280,     0,     0,  1282,
       0,  1329,  1330,  1331,  1295,  1282,     0,     0,  1282,     0,
       0,  1282,  1282,  1282,     0,     0,  1200,  1422,     0,     0,
     734,     0,  1270,  1509,  1273,  1275,  1243,  1244,     0,     0,
    1312,   752,     0,     0,   759,   780,   781,   774,   776,     0,
    1200,  1232,  1234,   793,  1228,  1229,  1230,     0,   807,  1194,
     799,  1196,   800,   797,   798,     0,  1200,  1422,   843,   860,
     862,   861,   855,   857,   863,   866,   841,  1240,   849,   847,
    1240,   617,  1325,  1482,   880,  1308,   617,  1514,   906,   907,
     909,   911,   912,   908,   910,   901,  1514,   897,     0,   943,
       0,   945,   944,   946,   937,   938,     0,     0,   923,  1075,
    1484,     0,     0,   957,  1200,  1422,  1518,     0,   984,   618,
     991,   992,   995,     0,   987,  1185,  1184,   994,  1000,  1179,
       0,     0,  1227,     0,     0,     0,  1035,     0,     0,     0,
    1060,     0,  1064,  1063,  1054,     0,  1464,  1227,  1100,  1099,
    1106,  1107,  1108,     0,  1200,  1422,     0,  1409,     0,  1108,
    1175,  1165,  1164,  1170,     0,  1172,  1173,  1180,  1430,     0,
     217,  1464,   454,   465,   466,   464,   322,   470,   546,  1464,
     537,   535,   536,   538,  1478,     0,  1464,     0,   549,   541,
    1478,   542,     0,   545,   550,   548,   543,   547,     0,   544,
       0,   532,   560,   555,   558,   557,   556,   559,   534,   561,
       0,   401,   396,  1338,  1339,  1340,  1293,  1281,  1286,  1287,
    1288,  1289,  1292,  1368,     0,  1496,  1514,   299,     0,   688,
    1196,   679,   681,  1193,   685,   675,   715,  1464,   704,   705,
    1464,   716,   706,   707,   710,   720,   717,   708,     0,   718,
     709,   719,   701,   702,   674,  1479,     0,     0,     0,   692,
     693,  1347,  1332,  1346,  1394,  1422,     0,  1398,     0,  1394,
    1394,     0,  1391,  1394,  1394,  1394,     0,  1394,  1394,  1201,
     725,  1203,  1200,   737,     0,   742,   740,   747,   748,   591,
       0,   758,   757,  1166,  1167,   762,   760,     0,   779,     0,
     784,   617,   617,   794,   792,  1231,   806,   805,   804,   803,
    1519,  1193,     0,   617,  1197,  1192,     0,   831,     0,  1240,
    1240,   859,   853,   856,   851,     0,   889,     0,     0,   913,
       0,     0,     0,   939,   941,     0,   933,   949,   934,   935,
     928,   929,   949,  1067,  1464,     0,  1485,  1074,   399,   400,
    1469,   958,   961,     0,     0,   975,   985,   982,   620,     0,
       0,  1002,  1001,  1216,  1218,  1019,  1213,  1214,  1026,  1024,
       0,  1240,  1037,  1240,  1031,  1039,  1052,  1053,  1055,  1418,
    1093,  1207,     0,  1422,  1114,     0,     0,  1410,  1134,  1135,
       0,  1138,  1141,  1145,  1139,  1171,  1482,  1174,  1186,  1434,
       0,   203,   204,   200,     0,     0,   456,     0,  1499,     0,
    1464,   539,   540,     0,   563,  1464,  1512,   564,   562,   395,
    1446,   391,  1469,  1369,   419,   280,  1191,   686,     0,     0,
    1236,  1236,   703,   698,   697,   699,  1387,  1200,  1395,     0,
    1407,  1392,  1385,  1405,  1386,  1388,  1389,  1402,  1403,  1390,
    1384,   617,  1204,  1199,   726,   735,   749,   750,     0,   754,
     753,   755,  1168,  1169,   765,   763,   617,   777,   778,  1233,
    1235,  1464,   812,   825,   826,   813,     0,  1464,   816,   817,
     820,   818,     0,   819,   809,   810,   801,   808,  1195,   617,
    1200,  1296,  1200,  1296,   858,   864,   617,   882,   890,   892,
     899,   902,   903,  1454,   914,   895,   900,   949,  1350,  1351,
     949,     0,   932,   930,   931,   936,  1077,     0,  1486,  1071,
    1200,   974,   968,     0,   619,   996,     0,     0,  1008,     0,
     617,   617,  1020,  1018,  1215,  1027,  1022,  1025,  1032,   617,
    1041,  1040,  1419,     0,     0,  1094,  1085,  1208,  1110,  1210,
       0,  1200,  1200,  1125,  1409,  1137,  1462,  1143,  1462,  1207,
       0,  1223,  1225,  1189,  1187,  1220,  1221,  1188,  1435,     0,
     201,   453,  1464,     0,   458,   463,  1478,   499,   519,   514,
    1436,     0,     0,  1464,  1480,  1464,     0,   469,   475,   476,
     477,   486,   478,   480,   483,   471,   472,   473,   479,   482,
     500,   484,   487,   474,     0,   481,   485,  1359,   554,  1357,
    1358,   570,   553,   565,   575,     0,  1464,  1464,   414,   712,
     711,   714,     0,   713,   727,  1396,  1202,   617,   751,   766,
     744,   617,   761,     0,   814,   815,     0,  1236,  1236,   811,
    1198,   833,     0,   832,     0,   854,   617,   893,   887,   904,
    1455,     0,   948,   940,   949,   951,     0,     0,  1080,  1076,
    1070,   962,   977,     0,     0,  1003,  1464,  1010,     0,  1004,
       0,  1007,  1217,  1219,   617,  1038,   617,  1087,  1276,  1508,
    1278,  1508,  1088,  1089,  1090,  1091,  1092,   617,  1111,  1102,
    1211,  1206,  1109,  1116,  1115,  1136,     0,  1462,  1140,     0,
    1147,  1159,  1156,  1158,  1157,  1152,  1155,   617,   617,  1190,
    1177,  1222,  1183,  1182,  1471,     0,  1464,  1464,   460,   498,
    1464,   520,   518,   515,   516,  1466,   508,  1464,  1240,     0,
       0,     0,     0,   501,     0,     0,   506,   509,   512,   573,
     571,   572,   574,     0,   568,   566,   567,   569,     0,   405,
     402,   403,     0,     0,  1471,  1205,   764,   822,   821,   824,
     823,  1200,  1200,   891,     0,   947,   952,     0,  1464,  1078,
       0,     0,  1068,  1072,   976,     0,     0,  1013,  1011,  1012,
    1006,  1005,  1033,  1042,  1273,  1275,  1209,   617,  1142,     0,
    1146,  1148,  1132,  1224,  1226,  1472,  1473,  1181,   455,     0,
       0,  1464,   451,     0,   507,     0,   504,  1422,   502,   503,
     493,   491,   492,   494,   490,   495,   489,   488,     0,   513,
     511,   510,   552,   551,   404,   398,   420,  1237,   835,   834,
     905,   950,     0,  1081,  1464,  1240,  1009,  1014,   999,     0,
       0,  1212,  1144,   457,   459,     0,   497,   496,   517,     0,
    1079,     0,   997,  1514,  1514,   461,     0,  1082,  1277,  1279,
     505
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    23,    38,    68,   124,
     234,     9,    24,    39,    69,    89,   445,    72,    70,    34,
      11,    20,    26,    41,    56,    57,    16,    36,    76,    96,
      97,   180,   181,   167,    98,   168,   169,   170,   171,   448,
     172,   173,    99,   176,   177,   178,   246,   100,   195,   196,
     197,   198,   409,   468,   542,   199,   329,   459,   460,   461,
     743,   880,   462,   881,   200,   340,   341,   466,   201,   396,
     397,   202,   203,   204,   205,   206,   207,   208,    47,    77,
      79,   103,   101,   131,   345,   410,   485,   486,   890,   751,
    1089,   487,   886,   488,   489,   490,   491,   492,   894,  1092,
    1783,   493,   494,   495,   496,   497,   897,   498,   499,   500,
     765,   134,   106,   107,   108,   109,   140,   110,   346,   347,
     413,    30,    65,   143,    83,   217,   148,   116,   149,   117,
     153,   226,   300,   301,   626,   302,  1358,   819,   512,   303,
     429,   304,   632,   305,   306,   627,   811,   812,   813,   814,
     307,   308,   309,    82,   218,   150,   151,   152,   224,   286,
     419,   287,   359,   360,   509,   806,   288,   508,   602,   603,
     604,   928,   605,   606,   607,   608,   609,   610,   918,  1337,
    1591,  1592,  1730,  1801,  2130,  2131,   611,   612,   796,   613,
     614,   615,  1124,   924,   925,  1998,   616,   617,   114,   277,
     147,   352,   222,   416,   504,   505,   506,   768,   910,   911,
    1100,  1101,  1019,   912,  1552,  1786,  1954,  2098,  2182,  1331,
    1555,  1104,  1334,  1788,  1975,  1976,  2197,  1977,  1978,  1979,
    1980,  2188,  1981,  1982,  1983,  1984,  2116,  2117,  2105,  1985,
    1986,  2102,   437,   281,   507,   564,   771,   772,   773,  1106,
    1335,  1588,  2128,  2123,  1589,    50,   233,   384,    86,   120,
     119,   155,   156,   157,   230,   314,   122,   316,   442,   443,
     527,   528,   529,   530,   531,   823,  1498,  1499,  1738,   532,
     533,   689,   690,   824,   944,  1140,  1379,  1380,  1375,  1632,
    1633,  1137,   691,   825,   963,  1163,  1161,   692,   826,   971,
    1410,   693,   827,  1419,   694,   828,  1204,  1421,  1667,  1668,
    1669,  1424,  1675,  1846,  1844,  2011,  2010,   695,   829,   984,
     696,   830,   985,  1427,  1428,   697,   831,   986,  1210,  1213,
     698,   699,   700,   832,  1684,   701,   833,   992,  1438,  1691,
    1864,  1865,  1220,   702,   834,   996,  1227,   703,   835,   704,
     836,  1001,  1002,  1233,  1234,  1235,  1461,  1459,  1876,  1236,
    1452,  1453,  1701,  1456,   705,   837,  1008,   706,   838,   707,
     839,   708,  1014,  1464,   709,   841,   710,   843,  1466,  1879,
    2026,  2028,   711,   844,  1243,  1475,  1709,  1881,  1882,  1883,
    1885,   712,   845,   713,   846,  1021,  1249,  1250,  1251,  1487,
    1720,  1721,  1252,  1484,  1485,  1486,  1714,  1253,  1892,  2147,
     714,   847,   715,   848,  1028,   716,   849,  1030,  1258,   717,
     850,  1032,  1264,  1497,  1902,   718,   851,  1035,  1267,  1737,
    1036,  1037,  1038,  1501,  1502,   719,   852,  1511,  1908,  2047,
    2157,  2218,   720,   853,   721,   854,  1913,   722,   855,  1512,
    1916,   723,   724,   856,  1049,  2054,  1284,  1514,  1919,  1754,
    1755,  2056,  1282,   725,   857,  1054,  1055,  1056,  1057,  1296,
    1058,  1059,  1060,  1061,   726,   858,  1025,  1896,  1254,  2040,
    1489,  1723,  2038,  2152,   727,   859,  1297,  1527,  1923,  1926,
     728,  1067,  1300,   729,   862,  1069,  1070,  1761,  2069,   730,
     863,  1073,  1306,   731,   865,   732,   866,   733,   867,   734,
     868,  1311,   735,   869,  1313,  1768,  1769,  1539,  1771,  1937,
    2078,  1939,  2172,   736,   737,   871,  2085,  1081,  1316,  1543,
    1676,  1845,  1776,   738,  1545,   739,   740,   873,  1277,  1778,
    2035,  1943,  2090,  1609,  1440,  1441,  1693,  1695,  1869,  1660,
    1661,  1831,  1833,  2007,  1928,  1929,  2067,  2071,  2167,  1745,
    1746,  1910,  1747,  1911,  1944,  1945,  2087,  1946,  2088,  1433,
    1434,  1435,  1681,  1436,  1682,  2001,  1016,  1017,   973,   974,
    1195,  1196,  1197,  1198,  1199,  2065,  2066,  1114,  1345,  1386,
     964,   987,  1214,  1044,  1050,   349,   350,  1062,  1063,  1240,
    1039,   977,   978,   425,   431,  1097,   432,   254,  1010,  1011,
     965,   989,  1117,  1383,  1642,  1722,  1887,   994,  1040,  1988,
     967,   946,   791,   920,   921,  1990,   968,   808,   809,   969,
    1146,  1148,  1390,  1404,  1399,  1396,   225,  1770,  1323,  1166,
    1275,  1924,   210,  1216,   930,   403,   365,  1324,   243,  1949,
     374,   216,   621,  1141,   555,   158,   551,   265,   272,  2031,
     136,   274,   820,   519,    42,   408,   556,  2177,   515,   371,
    1636,   934,  1318,  1727,   901,   174,  1218,   788,  1606,   258,
     619,   630,   746,   214,  1414,  1242,  1109,   546,   786,   183
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1940
static const yytype_int16 yypact[] =
{
   -1940,   278,   520, -1940,  -155,   144,   520, -1940, -1940, -1940,
     538,   538,   417,   417, -1940,   661, -1940, -1940, -1940, -1940,
     864,   864,   458,   896,   896,   794,   653, -1940,  1058,  1057,
   -1940, -1940, -1940, -1940,   -86,   813,   914,   738,   894,   894,
   -1940,   743,    39,   758,   770,   873,   780, -1940,   252,  1116,
     942,  1117, -1940,   546, -1940, -1940,   958, -1940, -1940, -1940,
     816, -1940, -1940, -1940,   924,   839, -1940,    21, -1940,   469,
     538,   417, -1940, -1940, -1940, -1940,   557, -1940,  1128,   -23,
     834,   933,  1066,   875, -1940, -1940,   963,   417, -1940, -1940,
   -1940,   855,   857,   871,   872,   874, -1940, -1940, -1940, -1940,
   -1940,   959,   877,  1098,   923,   709, -1940,   281, -1940, -1940,
   -1940, -1940,   878,   976,  1097, -1940,    25,   899, -1940,    66,
      66,   906,   884,   892,   896, -1940,   704,  1151,   -18,  1064,
    1074, -1940, -1940,   913, -1940, -1940,   952, -1940, -1940, -1940,
    1334, -1940, -1940, -1940, -1940,   915,  1014,  1039, -1940,   875,
   -1940, -1940, -1940, -1940, -1940,   110, -1940,   -94,   -77,   155,
   -1940, -1940, -1940, -1940,  1001,  1157, -1940,   -61, -1940,   523,
   -1940, -1940, -1940, -1940,    76,   177, -1940,   -26, -1940, -1940,
   -1940,   922,   656,  1268,   938,   938,   998,  1016,  1157,  1157,
    1157,   938,  1157,  1319,  1157, -1940,   911, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
     938,   959,   -23, -1940,  1298, -1940,  1212,    25,   899, -1940,
     939,  1037,  1043,   899,   453,   960,   965, -1940,  1157,  1048,
    1130, -1940, -1940,  1302,   894,  1157,  1184, -1940,   529, -1940,
   -1940,  1059, -1940,  1157,  1213, -1940,   897, -1940, -1940, -1940,
   -1940,   972,  1178, -1940, -1940,  1157,  1157, -1940,  1157,   990,
    1356,   990,  1157,   990, -1940,   938,     4, -1940, -1940, -1940,
   -1940, -1940,   875, -1940,   875, -1940, -1940,   899, -1940,   979,
    1078, -1940, -1940, -1940,   960, -1940,   984,    48, -1940,  1298,
    1157,   392,   392,  1157,    24,  1190,  1157,  1410,  1168, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
     505,   638,  1157, -1940,  1008,   997, -1940,   942,  1184, -1940,
   -1940, -1940, -1940,   990, -1940, -1940, -1940, -1940, -1940,  1157,
     883,   990,  1221,   437, -1940, -1940, -1940, -1940,   990, -1940,
   -1940,    62, -1940, -1940, -1940, -1940,   875, -1940,  1159,   875,
   -1940, -1940,   899, -1940,  1009,  1012, -1940, -1940,  1377, -1940,
    1379,  1184,  1044,  1157,  1410,   990,   -24,   -53,  1184,  1042,
   -1940,  1157,  1046, -1940,  1046,   -45, -1940, -1940, -1940, -1940,
   -1940,  1184, -1940, -1940, -1940,   472,   104, -1940,    37, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,   883, -1940,  1085, -1940,
   -1940, -1940, -1940,   990, -1940, -1940, -1940, -1940,  1184, -1940,
     888, -1940,  1184, -1940, -1940, -1940,  1175, -1940, -1940, -1940,
     772,  1091, -1940, -1940, -1940,   990, -1940, -1940, -1940, -1940,
   -1940, -1940,  1260,    82,  1293,  1062, -1940, -1940, -1940,  1157,
    1157, -1940, -1940,  2500,   417, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
     767, -1940,    68, -1940,   883, -1940,  1184, -1940,   746,  1190,
    1179,  1102, -1940,  1136,  1190,  1157,  1439,   134,   163,  1184,
   -1940,  1072, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940,  1124, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940,  1157, -1940,  1046, -1940,  1175, -1940, -1940,  4690,  1476,
    1322,  1184,    86, -1940, -1940, -1940,  1184, -1940, -1940,  1147,
   -1940,   -42,   -42,  2708,  1070,  1073, -1940, -1940, -1940, -1940,
   -1940,  1166,  3417,  3652,  1080, -1940, -1940,   767, -1940, -1940,
   -1940, -1940,  1143,  1157,  1315, -1940,   895, -1940,  1157,   786,
   -1940,  1157, -1940,  1157, -1940,  1173,  1157,  1157,  1334,   275,
    1157,  1099, -1940, -1940,   960,  1312, -1940, -1940,   325,   610,
     620,   640,   651,  1105, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940,  1198, -1940,  1184, -1940, -1940, -1940, -1940,
     990,   990,  1326, -1940, -1940, -1940,     0, -1940, -1940, -1940,
    1157,   142, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,   870,   402,
   -1940,   842, -1940, -1940, -1940, -1940, -1940,   132,  1319, -1940,
     500, -1940, -1940, -1940, -1940,  1433, -1940, -1940,  1314, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940,  1102, -1940,  2096,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,   450, -1940,
   -1940,  1247, -1940, -1940, -1940, -1940,   826, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940,   795, -1940, -1940,  1157,   266,  1157, -1940,
   -1940,   477,   141,  1512, -1940, -1940,   -53,  1180, -1940,   990,
     990, -1940,  1273,  1273,  1282, -1940,   990, -1940,   168,    48,
   -1940, -1940,   960, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,  1119, -1940, -1940,  1163,
   -1940,  1113,  1169, -1940, -1940, -1940, -1940,  2934,   133,  1535,
   -1940,  1210,  1210,   883,  1296,  1296, -1940, -1940,  1118, -1940,
   -1940, -1940, -1940, -1940, -1940,    28,  1399, -1940, -1940,  1091,
    1184,  1127, -1940,  1133,   990,  3495,  1141,   -29,  1348, -1940,
   -1940,  4262,   875,  4323,  4262,  1346,   360,   865,    74,   990,
   -1940, -1940,  1449, -1940,    74,   990,  4276,   990,  3678,  4262,
   -1940,  1904,   875,   990,   875,   990,    63,    46,   990,   875,
   -1940, -1940,  3732,  3744, -1940, -1940,   990,   990,   875,   990,
   -1940,  1054,  1483,   990, -1940, -1940, -1940, -1940, -1940, -1940,
    1568, -1940,   938, -1940, -1940, -1940, -1940,   990,    97, -1940,
     146,  1160, -1940,  1160, -1940, -1940, -1940, -1940,  -101, -1940,
   -1940, -1940, -1940, -1940,   990,  1157,  1420,  1420,   142, -1940,
   -1940, -1940, -1940,  1407, -1940, -1940, -1940,  1184,  1200,  5049,
    1145, -1940,   990, -1940,   133, -1940,  1203,  1367, -1940,  1439,
   -1940, -1940, -1940, -1940,   990,   990,   883,   -53,   -53,  1567,
    1319, -1940, -1940, -1940,  1480,   705, -1940,  1296,  1164,   990,
    1172,  1187,  1296,   437,  1188,  1189,  1193,  1194,  1195,  1196,
    1199,  1201,  1172,  1482, -1940,  3913, -1940, -1940, -1940, -1940,
    1422, -1940,  1547, -1940,  3185, -1940,  1215, -1940,   437, -1940,
   -1940,  1182, -1940, -1940,   -17,   875,  1494,   904, -1940,  1285,
    1316,  1045,  1498,  1543,  1197,  1211,  1508,   147,  1182, -1940,
   -1940,    44, -1940, -1940, -1940,  1548, -1940, -1940, -1940,  1296,
      74, -1940, -1940, -1940, -1940, -1940,  1253, -1940,    70,   990,
   -1940,    18, -1940, -1940, -1940, -1940, -1940,  4262, -1940,  1254,
    1518,  1602,   905, -1940,  1259, -1940,  2150,  1521,   742,  1264,
    1263,  -190,  1270,   663,  1488, -1940,  1316,  1488,   990,  1525,
    1238, -1940,  1061, -1940, -1940, -1940, -1940, -1940,  1425, -1940,
      74, -1940,   -39, -1940,    61, -1940, -1940,   -13,  1617,  2841,
   -1940, -1940,   990,  1526,  3993,   990,  1496,   833,  1561, -1940,
    1349,  1303,  1405,  1488,   795, -1940,    -9, -1940, -1940, -1940,
   -1940,   543, -1940, -1940,  1157,   990, -1940, -1940,   -17, -1940,
   -1940,   990, -1940,  1184,   960, -1940, -1940, -1940, -1940,  1566,
    1296,  5049,  5049,  5049,    60,   756, -1940, -1940, -1940,  1118,
   -1940,  5049, -1940, -1940,  1105, -1940,   133, -1940, -1940, -1940,
   -1940, -1940, -1940,  1260,   -53,  1570, -1940, -1940,  1061,  1279,
    1250,    99,   255,  5049,  1283,  5049, -1940,  5049, -1940,  1167,
    1251,  5049,  5049,  5049,  5049,  5049,  5049,  5049,  5049, -1940,
   -1940, -1940,  4262,  1502, -1940, -1940,  1352,  1422, -1940, -1940,
   -1940, -1940,  1102, -1940, -1940,  1300, -1940,  1300, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940,  2948, -1940, -1940, -1940, -1940,
   -1940,  1387,  1462, -1940,    17, -1940, -1940, -1940,   677, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,    26, -1940,
   -1940,  1276,  1538,  1538,  1538,  1538, -1940, -1940,  4262,  4262,
   -1940,   360,   173,  1569,  1269, -1940,  1280, -1940,   990, -1940,
     -12, -1940, -1940,   625,  1541, -1940,  1061,   137, -1940,    18,
   -1940, -1940, -1940, -1940,    95,  1317,    74, -1940, -1940,  4262,
   -1940, -1940, -1940, -1940,  1355, -1940, -1940, -1940, -1940,   990,
     -29, -1940,  1060, -1940, -1940,  1316,   -17, -1940,  1509,   358,
     232, -1940, -1940,   990,   232,  1320, -1940,  1118, -1940, -1940,
      67,   746, -1940, -1940,  1835, -1940,  1666,  1504,  4262,  4262,
   -1940,  4006,   990, -1940,  1544, -1940, -1940,  4262,  1061, -1940,
   -1940, -1940,  1617,  1513,   990, -1940,   927, -1940,    47,   358,
   -1940, -1940,  1603, -1940, -1940,  1448, -1940,   990,   990, -1940,
     990,  1536,   982,   114, -1940,  4775,  1405, -1940,  1167,  1281,
    1281,   787, -1940, -1940, -1940,  5049,  5049,  5049,  5049,  5049,
    5049,  4854,   756,  1366, -1940, -1940,  1260,  1405, -1940, -1940,
   -1940,  1538, -1940, -1940,  1289,  1294, -1940,  1061,  1538,  1516,
   -1940, -1940, -1940, -1940,  1404,  1538,  1469,  1469,  1469,   108,
    1506, -1940, -1940,   373, -1940,    96,  1005,   990,   827,   139,
    1287, -1940,  1118, -1940, -1940,   274,  1288,  1031,   372,  1290,
    1041,   145,   153,   602,  1292,  1068,  4201,    42,  4262,    74,
   -1940,  1408, -1940, -1940, -1940, -1940, -1940, -1940,  1342,   -29,
   -1940,   195,   990,   990,   482, -1940, -1940, -1940,   434,   667,
    1378, -1940, -1940,  1615, -1940,  1486, -1940,    -2,     1, -1940,
   -1940,  1489, -1940, -1940, -1940,  1563,  4201,   445, -1940, -1940,
   -1940, -1940,  1728, -1940,  1358, -1940, -1940,   170, -1940, -1940,
     173, -1940, -1940,  1405, -1940, -1940, -1940,  1102, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940,  1428,  1102, -1940,  1353, -1940,
    1704, -1940, -1940, -1940,   792, -1940,  1061,   916, -1940,    76,
      55,   840,    74,    74,  4201,   528,  1072,   875,  1621, -1940,
   -1940,  1747, -1940,  1583, -1940, -1940, -1940, -1940,  1509, -1940,
     990,   595,    26,   858,  1330,  1638, -1940,  1332,  1061,   814,
   -1940,   373, -1940, -1940, -1940,  4262,  1157,    26, -1940, -1940,
   -1940, -1940,   304,   990,  4201,   541,  1369,  1751,   990,   318,
   -1940, -1940, -1940,  1466,  1467, -1940, -1940,  1060, -1940,   630,
     990,  1157,  1597, -1940, -1940,  1184, -1940, -1940, -1940,  1157,
   -1940, -1940, -1940, -1940,  1469,  1069,  1157,  1348, -1940, -1940,
    1469, -1940,  1184, -1940, -1940, -1940, -1940, -1940,   990, -1940,
     990, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
     990,  1574,   840, -1940,  1118, -1940, -1940,  1005,   808,   808,
    1281,  1281,  1281, -1940,  1082, -1940,  1102, -1940,   990, -1940,
    1489, -1940, -1940,  1538, -1940, -1940, -1940,  1157, -1940, -1940,
    1157, -1940, -1940, -1940, -1940, -1940, -1940, -1940,    19, -1940,
   -1940, -1940,  1404, -1940, -1940, -1940,   -17,   -17,   -17, -1940,
   -1940, -1940, -1940, -1940,  1172,  1285,  4983, -1940,   990,  1172,
    1172,  5049, -1940,  1172,  1172,  1172,   435,  1172,  1172, -1940,
   -1940,  1515,  4201, -1940,    74, -1940, -1940,  2214, -1940,   374,
      -5, -1940, -1940, -1940, -1940,   983, -1940,  1452, -1940,  1440,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
    1267,  1538,  1520, -1940, -1940, -1940,  4262, -1940,  4262,   173,
   -1940, -1940, -1940,  1728, -1940,   990,  1661,  1357,   801,  1678,
    1359,   245,  1061, -1940, -1940,  1736, -1940, -1940, -1940, -1940,
     916, -1940,  1616, -1940,  1157,  1511, -1940, -1940, -1940, -1940,
    1315,    74, -1940,  4262,   275,   350, -1940, -1940, -1940,   990,
    4262,   423, -1940, -1940, -1940,  1652,  1537, -1940,  1653, -1940,
    1560, -1940, -1940, -1940, -1940,  1332, -1940, -1940, -1940,  1540,
    1656,  1517,  1505,  1285, -1940,  4262,   245, -1940,  1523, -1940,
    1061, -1940,  1691,  1416, -1940, -1940,  1405, -1940,    53,  1795,
     946, -1940, -1940, -1940,  1184,  1694,  1592,  1742,  4900,   390,
    1157, -1940, -1940,   390, -1940,  1157,  1200, -1940, -1940, -1940,
    1617, -1940,  1315, -1940,  1415, -1940, -1940, -1940,   390,   390,
     129,   129, -1940, -1940, -1940, -1940, -1940,  1378, -1940,  1100,
   -1940, -1940, -1940,  1005, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  4262, -1940,
   -1940, -1940, -1940, -1940,  1687, -1940, -1940, -1940, -1940, -1940,
   -1940,  1157, -1940, -1940, -1940, -1940,  1114,  1157, -1940, -1940,
   -1940, -1940,    81, -1940,  1267, -1940, -1940, -1940, -1940, -1940,
    4201,  1493,  4201,  1495, -1940, -1940, -1940, -1940, -1940,  1682,
   -1940,   801, -1940,  1718, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940,   245,  1060, -1940, -1940,  1060,    33,   990, -1940, -1940,
    4201, -1940, -1940,   890,  3652, -1940,  1767,  1586,  1608,   401,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940,  4262,   731, -1940, -1940, -1940,  1683,  1564,
     990,  1378,  4201, -1940,  1751, -1940,  1293,  1734,  1293,  1517,
     -27, -1940, -1940,  1684, -1940,  1571, -1940, -1940, -1940,   389,
   -1940, -1940,  1157,  1740,  1614, -1940,    34, -1940,  1633,   868,
    1410,  1646,  1409,  1157,  1296,  1157,   990, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  1455,
   -1940, -1940, -1940, -1940,   711, -1940, -1940, -1940, -1940, -1940,
   -1940,   457, -1940,   468, -1940,  1412,  1157,  1157, -1940, -1940,
   -1940, -1940,   390, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940,   390, -1940, -1940,   390,   129,   129, -1940,
   -1940, -1940,  4262, -1940,  4262, -1940, -1940, -1940, -1940, -1940,
   -1940,  1790,  1060,  1060, -1940,  1443,  1546,   875,   737, -1940,
     990, -1940, -1940,  1519,  4262, -1940,  1157,   717,  1609, -1940,
    1619, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  1300,
   -1940,  1300, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,   990,  1293, -1940,   990,
    1705, -1940, -1940, -1940, -1940, -1940,   875, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940,  1010,  1184,  1157,  1157,  1677, -1940,
    1157, -1940, -1940, -1940, -1940,   142, -1940,  1157, -1940,   990,
     990,   889,  1674, -1940,  1573,  1184,   711, -1940, -1940, -1940,
   -1940, -1940, -1940,   390, -1940, -1940, -1940, -1940,   390, -1940,
    1412, -1940,   990,   133,  1010, -1940, -1940, -1940, -1940, -1940,
   -1940,  1378,  1378, -1940,  4262,  1060, -1940,  4262,  1157,   875,
     875,  1554, -1940, -1940, -1940,  1442,   990,  1723, -1940, -1940,
   -1940, -1940, -1940, -1940,  1578,  1584, -1940, -1940, -1940,   990,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  1184,
    1184,  1157, -1940,  1184, -1940,  1184, -1940,  1285, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  4262, -1940,
   -1940, -1940, -1940, -1940, -1940,   990, -1940, -1940, -1940, -1940,
   -1940, -1940,   -29,   875,  1157, -1940, -1940, -1940, -1940,  1709,
    1710, -1940, -1940, -1940, -1940,  1184, -1940, -1940, -1940,  1814,
   -1940,   -29, -1940,  1102,  1102, -1940,  4262, -1940, -1940, -1940,
   -1940
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1940, -1940, -1940, -1940,  1857, -1940, -1940, -1940,    41, -1940,
   -1940, -1940, -1940, -1940,  1549, -1940, -1940, -1940,  1112, -1940,
   -1940,    52,  1843, -1940, -1940,  1815,   660, -1940, -1940, -1940,
   -1940, -1940,  1685,  1743, -1940, -1940,  1703,   720, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940,  1695, -1940, -1940, -1940, -1940,
    1680, -1940, -1940, -1940,   582, -1940, -1940, -1940, -1940,  1414,
   -1940, -1940,  1341,   796, -1940, -1940, -1940, -1940, -1940, -1940,
    1485, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940,  1752, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,   986,
     103, -1940,  1338, -1940, -1940, -1940,  1002, -1940, -1940, -1940,
     154, -1940,  1688, -1940,  1792, -1940, -1940, -1940, -1940,  1555,
   -1940,   192, -1940, -1940, -1940, -1940,  1686, -1940,  1854,  1755,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  1086, -1940,
   -1940, -1940,  1384, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940,   751, -1940, -1940, -1940,  1623,
   -1940,  -530,  -736, -1940, -1940, -1940,  -404, -1940, -1940, -1940,
   -1940, -1940, -1940, -1290, -1277,  1111, -1275,   121, -1940, -1940,
   -1940, -1940,   323, -1940, -1940,  -214, -1272, -1940, -1940, -1267,
   -1940, -1266, -1940, -1940,   993, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,  1413, -1940, -1940, -1940,
    1003, -1940,  -738, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
     -60, -1940, -1940, -1940, -1940, -1940, -1940,  -194, -1940, -1940,
   -1940, -1940,  -205, -1940, -1940, -1940, -1940, -1940,  1152, -1940,
   -1940, -1940, -1940, -1940, -1940,   127, -1940, -1940, -1940, -1940,
   -1940,  1803,  1025, -1940,   256, -1940, -1940, -1940, -1940,  1484,
   -1940, -1940, -1940, -1940, -1940, -1940, -1362, -1940, -1940,   189,
   -1940,  1396, -1940, -1940, -1940,   937,   551,   556, -1940, -1940,
     305, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,   940, -1940, -1940,   272,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940,    77, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940,   713, -1940, -1940,   708, -1940, -1940, -1940, -1940,
     486,   248, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,    71,   714,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940,   699, -1940, -1940,
   -1940,   231, -1940, -1940,   470, -1940, -1940, -1940, -1582, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1939,   925, -1940, -1940,   219, -1940, -1940,   451, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,   641,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940,   678, -1940,   210,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940,   908, -1940,   907, -1940, -1940,  1110, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,   903,   436, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940,    43, -1940,   441, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,    -4, -1940,
   -1152, -1940, -1940, -1043, -1174, -1072, -1940,   364, -1940, -1222,
   -1940, -1940, -1940, -1940,    49, -1940, -1940, -1940, -1940,   -71,
   -1940, -1940,   235, -1940, -1940, -1940, -1940,    38, -1940,  -457,
   -1661, -1940, -1940,   552, -1940, -1395, -1251,  -807, -1190, -1940,
   -1940,   791,    65,    69,    72, -1940, -1940,     6,  -213,  -414,
    -690,  -865,  -822,    31,   943, -1457,   -83, -1940, -1046, -1940,
    -790, -1940,   788, -1083,  -241, -1940,  -647,  -153,  -813,  -964,
      88,  -747, -1940, -1940,   473,  -908, -1038,  -948,  -801,  -663,
     547,  -576,  -220, -1940,  1079,  -230,  -618,  -361,  -271,  -313,
    -794, -1940, -1940, -1940, -1940, -1940,  1774, -1940, -1940,   835,
   -1940, -1940, -1940, -1610,  1202,   100,  1708,   747,  -399, -1940,
    -362,  1447, -1940,  -604, -1940, -1055,  1077,  -378,    40, -1940,
   -1940,  -665, -1940, -1715,  -164,  -594,  -474,  -127,  -800,   642,
   -1330,  -795, -1201, -1940,  1245,  1953,  -903, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1162, -1940,   214,  -652,   891,  -473
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1519
static const yytype_int16 yytable[] =
{
     118,   236,   424,   807,   557,   840,   320,   798,   559,   988,
     935,   501,  1328,  1301,   790,  1415,  1292,  1500,   334,   972,
     337,   872,   339,   815,   259,   260,   261,   981,   263,  1003,
     266,  1018,   255,   914,   769,  1817,  1206,   976,   262,   335,
    1735,   335,  1454,   335,  1064,  1582,  1239,  1637,  1638,  1442,
    1443,  1444,  1009,  1491,  1239,   517,  1544,   269,  1583,   398,
    1584,  1231,   310,  1585,   311,    21,   118,  1009,  1586,  1587,
     748,   318,  1048,  1009,    84,   937,  1009,  1839,   966,   323,
    1009,   380,   387, -1518,   405,   536,   966,   997,   386,  1686,
     399,   330,   331,  1373,   332,   343,  1463,   404,   338,  1704,
    1239,  1029,  1031,   335,  1706,   271,  1246,  1321,    53,   895,
      88,   335,   342,   344,   154,  1071,   966,  1947,   335,   439,
    1507,    40, -1482,    91,   426,   398,   362,  1342,  1075,   367,
     369,   421,   372,  2081,  1810,  1590,   241,   264,   433,   123,
    1895,   624,   803,  1278,  1285,   335,  1479,   335,   381,   175,
    1329,   441,  1142,  1931,   816,   449,  1608,  1149,   154,   446,
     770,   810,  1376,  1342,   405,   388,    51,  1298,  1159,   438,
     552,  1376,   891,  2082,   430,   164,  1293,   154,   467, -1442,
     926,  2083,   502,   465,   513,   631,   244,    62,   407,   348,
    1052,  1449,  1480,   538,  1449,  1228,  2017,  1422,   975,   423,
    1053,  1941, -1361,   154, -1482,   335,  1342,   435,  1680,  -177,
    1205,  1321,  1342,   357,  1238,   975,    31,   794,  1164,   104,
    1342,  2076,  -729,  2079,  1697,   450,   905,  1200,  1023,  1116,
    1359,    40,  1431,  2036,  1790, -1518,   539,  1053,   231,    74,
    1795,   553,   769,   154,  1550,   427,  1164,  1290,  1725,   558,
     817,  2084,   906,   907,   803,   919,   510,  1537,  1087,  1431,
   -1518,   810,  1705,   348,   451,  1094,   414,  1454,   228,   406,
    1454,   452,  1732,  2230,   975,   521,   522, -1446,     3,   357,
    1255,   623,  1432,   453,   762,  1053,   628,   165,    12,  1610,
    1132,  1133,  2237,  1687,  1635,  2099,  1610,  1406,   562,   892,
   -1518,   633,   633,  1610,  1481,  2032,   926,  1942,  2033,  1432,
    1840,   549,  1764,   229,  1103,  1338,   163,   105,  1299,  1849,
    1850,   389,  1071,  1377,  -177,  1614,  1239,  1164,  1509,   361,
    1726,  1868,  1634,  1355,   368,  1134,   795,   561,  1478,  1247,
     988,  1342,   454,  1095,   618,   554,   428,   232,  1423,   406,
    1229,    54, -1442,  1482,  1291,   789, -1446,   -31,  1129,  1130,
     390,   317,  2169,  1330,  1446,  1317,  1670,   391,   770,    63,
   -1469,   792,  1508,  1088,   554,    40,   893,   333,  1042,   747,
    1215, -1446,   237,   883,   752,   440,  2159,   756,   333,   757,
    1378,  1689,   759,   760,  1494,  1779,   766,   625,  1381,  1378,
    1536,   333,  1248,   115,   245,   455,  1430,   988,   456,   457,
    1343,   179,   166,   333,    62,  1407,  2003,   247,   333,  1841,
    1322,  1116,  1116,  1116,  1003, -1446,    88,   938,  1688,   242,
    1690,  1116,  1811,   389,   253,    55,   797,   988,   392,  1342,
    1834,  -584,  1534,  1493,    85,  1663,  1343,  1702,  1200, -1464,
    1465,   908,  2145,  1116,  1294,  1116,  2037,  1116,   537,  1613,
    1519,  1116,  1116,  1116,  1116,  1116,  1116,  1116,  1116,  2006,
   -1446,  1232,   390,   458,  1295,   516,   333,   333,   358,   391,
    1504,  1445,  1447,  2086,  2012,   988,  -582,  1356, -1444,  1343,
   -1446,   333,   253,   333,  2018,  1343,   534,   333,  1968,   179,
     333,   393,  1920,  1343,   333,  1115,  1344,  2020,  1354,  1454,
   -1446,  1969,  1495,  1970,  2025,   983,  1972,  1866,   898,   899,
    1412,  1973,  1974,   104,  1322,   904,   763,  -177,  1546,  1239,
     394, -1442,   932,  1024, -1446,   447,   335,  1483,   983,   335,
     335,  1610,  1644,  1662,  1556,  1244,   335,  1524,  2052,  2053,
     392,  1528,  1529,  -584,  1531,  1382,  1607,  2055,  1119, -1446,
    1535,   179,  1135,  1042,  1450, -1446,  1384,  1450,  1451,   395,
    1807,  1451,   884,  1391,  1333,  1940,   333,  2228,  1715, -1446,
    2149, -1518,   882,   764,   887, -1400,   988,    13,   888, -1518,
     941,  1654,  2048, -1469, -1518,  2004,    63,  1557,  -582,  1655,
    1641, -1518,    87,   273,   913,   444,  1120,   979, -1518, -1518,
    1756,   909,  1670,   393, -1518,  1907,   319,   319,   801, -1446,
     885,   105,  2139,  2140,  1343,  1698,  2100,  1026,  1053,  1666,
     401,  1041,  2049,  1045,  1467,  1045,  1051,  1468,  1026,  1673,
    1469,  1470,   394,  1837,    18,  2135,   898,    64,  2021,  2136,
    2023,  1827,  2050,  1045, -1518,  1116,  1116,  1116,  1116,  1116,
    1116,  1116,  1462,  1096,  2143,  1131,   376,   335,   378,  1342,
    1090,    17,  2092,   818, -1518,   333,  1515,   860,  2041,  1731,
    1515,   395,    15,   775,   335,   333,   377,  1107,  1813,  1814,
    1815,  1287,  2162,  2213,  2163,  2119,     4,  1339,  1340,  1341,
    1835,   363,  1123,   364,   402,  2166,  2124,  1352,  1733,  2073,
    2074,  1346,  1347,  1348,  1349,  1743,  1350,   335,   335,    19,
   -1406,  1765,  1343,   983,   141,  2173,  2174, -1460,  1933,  1085,
      90,  1388,   776,   179,  1138,  1429,   228,  1395,  1397,  1398,
    1400,  1098,   379,  1403,  1405,  1995,  2120,   179,   333,   990,
    1119,  1119,  1119, -1458,   999,  2002,  2002,  2125,  1000,   164,
    1119,  1674,  1593,  1677, -1489,   164,  1794,  1239, -1442,  1043,
       5,  1046,   889,     5,  1325,    22,  1066,  1287,  1758,   179,
     115,   229,  1119,  1215,  1119,  1077,  1119,   179,  1392,   861,
    1119,  1119,  1119,  1119,  1119,  1119,  1119,  1119,  1120,  1120,
    1120,  1479,   802,   333,  1890,  2221,  1513,  1643,  1120,  1346,
    1347,  1348,  1349,  1468,  1350,  1707,  1469,  1470, -1404,   333,
     333,     5,    92,    74,  1710,  1987,  1987,  2051,  1051,    74,
    1120,  1870,  1120,  1872,  1120,  1828,  1393,  1743,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1513,  1480,  1744, -1518,
    1816,   803,   179,  2034,   426,  1821,  1822,  2186,    54,  1824,
    1825,  1826,  1935,  1829,  1830,   319,  1215,  1728,  1900,  1471,
    1472,   165,  1780,  1332,  1871,   335,  1873,   165,  1139,  1215,
    1326,  1172,  1173, -1408,    93,  1287,  1047,  1473,  1474,   240,
      25,   804,   469,  1875,  2121,  2122,   283,  2164,  1678,  2165,
    1932,    28,  1208,  2093,  1083,  2126,  2127,   470, -1518,  2058,
     947,   988,  1273,   803,   335,  2059,   471,  2150,  1679,  2208,
    2209,   993,   184,  1431,    94,  1716,    95, -1458, -1518, -1442,
    1327,  1597,  1598,  1599,  1600,  1601,  1602,  1604,   319,  1781,
     164,  1782,    55,   988,  1918,  1643,  2060,  1287,   241,  1729,
    2061,  1074,  1343, -1464,  1804,   450,  1116,  1274,   240,  1481,
    2114,  1116,  2002,  2002,  2232,  1692,   239,   185,   777,   276,
    1744,  1717,   321,  1432,   282,  2190,  2191,  1594,   779,    40,
    -942,   472,   948,   874,  1119,  1119,  1119,  1119,  1119,  1119,
    1119,  1425,    29,  1906,   451,   273, -1442,   950,   781,  2192,
    2115,   452,   186,   187,    74,   188,  1287,   870,  1482,   783,
     473,   289,   749,   189,   540,  2151,   541,   778,   137,  -942,
     979,    32,   875,  1734,   290,  1595,  -942,   780,   351,   876,
     389,   799,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1346,
    1347,  1348,  1349,  1279,  1350,  1471,  1472,   782, -1401,  2205,
     979,   800,   165,  1150,  1211,  1748,   750, -1489,   784,  1762,
     805,   291,  1079,  1473,  1474,  1260,  1762,   190,  1505,   390,
    1760,   389,   454,   138,   139,   184,   391,    44,  1202,  1319,
    1541,   951,  1426,   472,  1542,   179,   426,   513,  1080,  1749,
    1724,  2008,   389,  1889,  1506,   753,    33,  -942,   979,   250,
     877,   325,   754,   415,   389,  1261,   179,   335,   335,  1750,
     390,   543,   473,  1262,    10,    45,   548,   391,    10,   474,
     185,  2042,   952,    46,   326,  1287,  1287,   953,  2103,  2104,
    1992,   390,  1718,   954,   166,   455,   955,    35,   391,   191,
     480,  2043,  1309,   390,  1310,  1999,  2000,   392,  1889,  1385,
     391,  1004,  1005,  1389,  1268,   186,   187,  1287,   188,    43,
    -942,  1401,  1402,   878,   475,  1006,   189,  1269,   956,  2110,
     476,    37,    40,  2193,  2194,  1190,  2057,   292,  1193,  1194,
     227,    48,  1648,  1263,   227,  1651,    52,   293,   392,  -942,
    1656,    49,  1483,  1346,  1347,  1348,  1349,   477,  1350,   979,
    2141,    58,  2142,   458,   478,  1351,  1553,  1554,  1522,   392,
     393,  1007,  1523,    59,  2195,  2196,  1791,   479,  1792,    60,
     190,   392,  -942,    61,  1346,  1347,  1348,  1349,  -942,  1350,
      67,   879,  1819,  1596,  2175,  2176,   957,  1823,  1842,   394,
    1843,   242,   480,     5,   481,   948,    71,  1348,  1349,   389,
    1350,   393,   482,   192,   983,  1781,  1899,  1782,    74,    78,
     950,  2014,  1903,  2015,  1346,  1347,  1348,  1349,  1909,  1350,
      80,    81,   393,  1889,   294,   295,  1646,   111,   395,   112,
     394,   958,   959,   483,   393,  1119,  2094,   296,   390,   297,
    1119,   102,   191,   193,   121,   391,   113,  2155,   125,  1851,
     126,   394,  1852,  1360,  1361,   115,   960,   133,   130,   513,
    1853,  1854,  1855,   394,   127,   128,  1719,   129,   135,   395,
     132,   144,   145,   146,   961,  1787,   175,   161,  1996,  -311,
     335,   484,   962,  1120,   333,   162,   160,   213,  1120,  2134,
     395,   194,  1796,  1362,   951,  1363,   333,   209,  1212,  1799,
    2137,  1287,   395,  2138,   267,   389,   212,   215,   219,  1287,
     220,   221,  1759,   235,    40,   249,   392,  1805,   253,   252,
     335,   945,   256,   257,   264,   982,  1364,  1365,  1366,   271,
     995,   273,   278,   279,   280,  1012,  1013,  1784,   335,   298,
     285,  1012,  1020,  1022,   390,  1789,   954,  2210,   982,   955,
    2211,   391,  1793,   313,  1012,   315,   192,  1820,   299,  1287,
     312,   319,   322,  1020,  1076,   327,  1078,   324,   328,  1856,
     333,   336,   353,  1367,   354,  1368,   948,   356,   335,   393,
     370,   956,   373,  1369,  1616,   375,  1617,  1857,   382,  1618,
     383,   950,  1346,  1347,  1348,  1349,   193,  1350,   400,  1619,
     412,  2229,   417,  1808,  1858,   418,  1809,  -323,   394,   420,
    2202, -1353, -1353, -1353, -1353,  2203,  1118,   434,  1346,  1347,
    1348,  1349,   392,  1350,   422,   464,   436,  1650,  1346,  1347,
    1348,  1349,   503,  1350,   511,   514,   518,  1653,   544,  2240,
     547,   333,   520,   550,   194,   545,  1144,   395,   560,   957,
    1859,   179,   620,   622,  1370,  1346,  1347,  1348,  1349,   629,
    1350,  2184,   638,   636,  1658,  2206,   637,   745,  1053,  1346,
    1347,  1348,  1349,   742,  1350,   951,   554,   758,  1803,   767,
     774,  1207,   785,   793,   787,   393,   821,  1346,  1347,  1348,
    1349,   822,  1350,   864,   958,   959,  2005,  1860,   552,   947,
     900,   896,   803,   903,  1951,   916,   917,  1012,   919,   922,
    1897,   927,   929,   933,   394,  1012,  1245,   939,   936,   960,
     942,   970,  1138,   998,  1620,   980,   943,   954,  1621,  1015,
     955,  2238,  2239,   982,  1082,  1084,  1099,   961,  1105,  1091,
    1121,  1622,  1108,  1126,  1127,   962,   810,   333,  2106,  1286,
    1861,  1136,  1167,   395,  1160,  1203, -1442,  1012,  1201,  1143,
    1862,  1012,   956,  1222,  1223,  1224,  1225,  1145,  1209,  1304,
    1165,   948,  1245,  1215,  1219,  1217,  1991, -1352, -1352, -1352,
   -1352,  1993,  1147,  1151,  1152,  1226,   950,  1623,  1153,  1154,
    1155,  1156,  1241,  1237,  1157,  1207,  1158,  1256,  1020,  1257,
    1259, -1355,   414,  1266,  1270,  1271,  2039,  1272,  1118,  1118,
    1118,  1276,  1281,  1283,  1053,   154,  1305,  1312,  1118,  1308,
    1371,  1863,  1314,  1315,  1336,  1317,  1387,   335,  1357,  1374,
     957,  1394,  1408,  1409,  1624,  1286,  1418,  2013,  1413,   975,
    1118,  1437,  1118,  2016,  1118,  1439,  1457,  1455,  1118,  1118,
    1118,  1118,  1118,  1118,  1118,  1118,  1477,  1460,  1625,  1372,
    1492,  1496,  1510,  1518,  1525,  1526,  1538,  1533,  1549,  1548,
     951,  1605,  1551,  1350,  1611,   958,   959,  1615,  1612,  1635,
    1377,   389,  1626,  1647,  1649,  1665,  1652,  1627,  1657,  1664,
    1683,  1659,  1432,  1696,  1694,  1699,  1711,  1628,  1700,  1708,
     960,  1629,  1712,  1736,  2118,  1739,  1740,  1751,  1752,  1753,
    1767,   952,  1766,  1775,  1785,  1777,   953, -1442,   961,  1800,
     390,  1847,   954,  1832,  1848,   955,   962,   391,   333,  1867,
    1878,  1880,  1884,  1886,  1891,  1894,  1898,  1912,  2095,  1915,
    1744,  1917,  1922,  1286,  1925,  1930,  1927,  1934,  1936,  2109,
    1938,  2111,  1948,  1012,  1952,  1953,  1955,   956,  1630,  1997,
    2009,  2022,  2027,  2024,  2030,  2044,  1503,  2045,  1631,  2046,
    2153,  2070,  2068,  1207,  2077,  1942,  2089,  2096,  2097,  2101,
    1516,  2107,  2132,  2133, -1442,  1964,  2108,  1012,  2144,  2146,
    2160,   947,  2129,  2148,   803,  2181,  2171,  2198,   392,  1532,
    2161,  2214,  2219,  2154,  2215,  1286,  2199,  2217,  2220,  2233,
    2234,  1540,  2236,    14,    27,  2178,   385,   251,    73,  2189,
     238,   182,   248,  1520,   535,   957,   268,  1245,   744,  1093,
    1320,   463,  2156,  1950,   211,  2200,  2118,   755,  1901,  1086,
     335,   426,  1118,  1118,  1118,  1118,  1118,  1118,  1118,   142,
     270,   411,    66,   275,   223,   940,   634,   355,   923,  1971,
    1102,   393,   335,   948,  1286,  1802,  2204,  1125,   563,  2113,
     958,   959,  2201,   159,   915,  1838,   523,  1904,   950,   741,
    1221,  1640,  2179,  2180,  1645,  1639,  2183,  1812,  1230,  1836,
     394,  2019,  1458,  2185,  1448,   960,  1703,  1874,  1488,  2223,
    2224,  1893,  2029,  2226,  1713,  2227,  1012,  1476,  1905,  1741,
    1547,  1265,  1517,   961,   513,  1921,  1288,  1289,  1065,  1671,
    1672,   962,  1303,   333,  1806,  1773,  2158,  2075,  1521,   395,
    1774,  1914,   948,  2091,  2212,   335,  1417,  1685,  2080,  2062,
    1420,  1280,   979,  2063,  1757,  2235,  2064,   950,   284,  1122,
     366,  1490,  1411,   414,   931,   761,  1128,  2207,   902,    75,
    1994,   979,   951,     0,     0,  1353,     0,  2225,     0,     0,
       0,     0,     0,   389,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1286,  1286,     0,     0,     0,     0,  1012,
    1012,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2231,     0,     0,   952,     0,     0,     0,  1742,   953,     0,
       0,     0,   390,     0,   954,  1286,   414,   955,     0,   391,
       0,     0,     0,     0,     0,  1033,     0,     0,     0,     0,
    1763,   951,     0,     0,     0,  1772,  1772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   842,     0,   956,
       0,     0,  -885,     0,     0,  -885,     0,     0,  -885,  -885,
    -885,     0,     0,     0,   982,     0,  -885,     0,     0,     0,
       0,     0,     0,     0,     0,  1797,     0,  1798,     0,     0,
     414,  1034,     0,   954,     0,     0,   955,     0,     0,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   957,   956,     0,
       0,     0,     0,     0,  -885,     0,     0,     0,     0,     0,
       0,     0,     0,  1207,  1207,  1207,     0,     0,     0,  -885,
       0,     0,     0,  1118,     0,     0,     0,     0,  1118,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,  1012,   958,   959,     0,     0,     0,     0,     0,     0,
    -752,     0,     0,  -752,     0,     0,     0,     0,   948,  1522,
       0,     0,   394,  1523,     0,     0,   957,   960,     0,     0,
       0,     0,     0,   950,     0,     0,  -885,  -885,     0,     0,
       0,     0,  1877,     0,     0,   961,     0,     0,  1888,  1286,
       0,     0,   154,   962,     0,   333,     0,  1286,     0,     0,
       0,   395,     0,  -885,  -885,     0,     0,     0,  1012,     0,
    -885,   958,   959,     0,  -885,     0,  1503,     0,     0,     0,
       0, -1518,  -752,     0,     0,     0, -1446,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   960,  -752,     0,     0,
       0,  -885,     0,  1888,  -885,  -885,  -993,  1286,     0,  -885,
       0,  1033,     0,  -885,   961,  -885,     0,   951,  -885,  -993,
    -885,     0,   962,   179,   333,     0,  1989,     0,     0,     0,
    1989,     0,     0,  -885,  -885,     0,     0,     0,  -885,     0,
       0,     0,     0,     0,     0,  1989,  1989,     0,  -885,     0,
    -885,     0,     0,     0,     0,  -885,     0,     0,     0,     0,
    -885,     0,     0,     0,     0,     0,     0,   980,     0,   954,
       0,     0,   955,     0,     0,     0,     0,     0,  -885,     0,
       0,  -752,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -885,  -752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   956,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -885,     0,
       0,     0,  -752,     0,     0,     0,     0,  -752,  1888,     0,
       0,  -752,     0,  -752,     0,     0,  -752,     0,  -752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -885,     0,     0,     0,     0,     0,
       0,     0,     0,  -885,  -885,     0,     0,  2072,  -752,     0,
       0,     0,   957,  -752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -885,     0,     0,  1989,     0,  -885,     0,
    -579,   524,     0,  -620,     0,  -620,     0,     0,     0,     0,
    -620,     0,     0,  2112,     0,     0,  -885,     0,  -620,  -752,
       0,     0,     0,     0,  -885,     0,  -885,   958,   959, -1446,
       0,     0,  -885,  -885,  -885,  -885,  -885, -1518,  -885,     0,
    -885,  -885,  -885,  -885,  -885,     0,  -752,     0,     0,  1989,
    -620,  -620,   960,     0,     0,     0,     0,  -620,     0,     0,
    1989,     0,  -993,  1989,     0,     0,     0,     0,  -620,     0,
     961,  -620,     0,     0,     0,  -993,  -752,     0,   962,   179,
     333,     0,  -752,  -620,     0,     0,     0,     0,     0,     0,
       0,  -752,  -752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -620,     0,     0,     0,     0,
       0,  -752,  -620,  -620,     0,     0,  -752,     0,     0,     0,
       0,  -752,     0,  2168,     0,     0,  2170,     0,     0,  -579,
       0,     0,     0,  -579,  -752,     0,     0,     0, -1446,     0,
       0,     0,  -752,  -620,  -752,     0,     0,     0,     0,     0,
    -752,     0,     0,     0,     0,  -620,  2187,     0,     0,  -620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1989,     0,  -620,     0,     0,  1989,  -579,     0,     0,  -620,
       0,     0,  -620,  -620,     0,     0,     0,     0,     0,     0,
    -620,     0,     0,     0,     0,     0,     0,  -620,     0,  -620,
       0,     0,  -620,  2216,     0,     0,     0,     0,     0,   524,
       0,  -620,     0,  -620,     0,     0,  2222,     0,  -620,     0,
       0,     0,     0,     0,     0,     0,  -620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -620,     0,     0,
       0,  -620,     0,  -620,     0,     0,     0,     0,     0,     0,
    -620,     0,     0,     0,     0,     0,     0,     0,  -620,  -620,
       0,     0,     0,     0,     0,  -620,     0,     0,     0,     0,
       0,     0,  -620,     0,     0,     0,  -620,     0,     0,  -620,
       0,     0,     0,     0,     0,     0,     0,  -620,     0,     0,
       0,  -620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -579,     0,     0,     0,     0,     0,     0,  -620,     0,
       0,     0,     0,  -620,     0,     0,     0,  -620,     0,     0,
    -620,  -620,     0,     0,     0,     0,     0,     0,   635,     0,
    -620,     0,     0,     0,     0,  -620,     0,  -620,     0,     0,
       0,     0,     0,     0,     0,  -620,     0,   947,     0,     0,
     803,  -620,     0,     0,     0,  -620,     0,     0,     0,     0,
       0,     0,     0,  -620,  -620,     0,     0,  -620,     0,     0,
       0,     0,     0,  -620,     0,  -620,  -620,     0,     0,  -620,
    -620,  -620,     0,     0,     0,     0,  -620,  -620,     0,     0,
    -620,  -620,     0,     0,     0,     0,     0,     0,  -620,     0,
       0,  -620,     0,     0,     0,  -620,  -620,  -620,     0,     0,
    -620,  -620,     0,     0,     0,     0,     0,     0,     0,   948,
       0,     0,  -620,     0,     0,     0,     0,     0,     0,     0,
     525,     0,     0,  -620,   950,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,  -620,     0,  1068,     0,  -620,
       0,  -620,     0,     0,   947,     0,     0,   803,  -620,     0,
    1168,  1169,  1170,     0,     0,     0,     0,     0,  1171,     0,
     567,   568,   569,   570,   571,   572,     0,     0,     0,     0,
    -620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -620,     0,     0,     0,     0,
       0,     0,     0,     0,   574,     0,   575,   576,   577,   578,
     579,   580,     0,     0,     0,     0,  -620,     0,   951,     0,
       0,     0,     0,     0,     0,  -620,   948,     0,     0,   389,
       0,     0,     0,     0,     0,     0,     0,     0,  -620,     0,
       0,   950,     0,  -620,  1302,  -620,   581,     0,     0,     0,
       0,     0,     0,  -620,     0,     0,     0,     0,     0,   952,
       0,     0,     0,  -620,   953,     0,     0,     0,   390,     0,
     954,     0,  -620,   955,     0,   391,     0,     0,     0,     0,
       0,  -620,     0,  -620,  -620,     0,     0,  -620,     0,  -620,
       0,     0,     0,     0,  -620,     0,     0,     0,  1172,  1173,
       0,     0,     0,     0,     0,   956,     0,     0,     0,  -620,
       0,     0,     0,     0,  -620,     0,     0,     0,     0,  -620,
       0,     0,     0,     0,     0,   951,  1174,     0,   582,     0,
    -620,     0,  1175,     0,     0,     0,   389,     0,   525,     0,
       0,  -620,     0,     0,     0,     0,   392,     0,     0,     0,
       0,   526,     0,     0,     0,  1416,     0,     0,     0,     0,
       0,     0,     0,  1176,     0,     0,   952,  1177,     0,     0,
       0,   953,     0,   957,     0,   390,     0,   954,   584,     0,
     955,     0,   391,     0,     0,     0,     0,     0,     0,     0,
       0,   947,     0,     0,   803,  1178,  1179,  1168,  1169,  1170,
    1180,     0,     0,     0,     0,  1171,     0,     0,     0,   393,
    1181,     0,   956,     0,     0,   586,     0,  1182,   958,   959,
       0,     0,  1183,     0,   588,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   589,   394,     0,
    1184,     0,     0,   960,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,   961,     0,   948,     0,     0,     0,     0,     0,   962,
       0,   333,     0,     0,     0,     0,     0,   395,   950,     0,
     957,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   593,   594,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,   958,   959,     0,     0,     0,
       0,     0,     0,     0,     0,  1172,  1173,     0,     0,     0,
       0,     0,   597,   598,   599,   394,     0,     0,     0,     0,
     960,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   951,  1174,     0,     0,     0,     0,   961,  1175,
       0,     0,     0,   389,     0,     0,   962,     0,   333,     0,
       0,     0,     0,     0,   395,  1185,  1186,  1187,  1188,     0,
    1189,     0,  1190,  1191,  1192,  1193,  1194,     0,     0,     0,
    1176,     0,     0,   952,  1177,     0,     0,     0,   953,     0,
       0,     0,   390,     0,   954,     0,     0,   955,     0,   391,
     639,     0,   640,     0,     0,     0,     0,   641,     0,     0,
       0,     0,  1178,  1179,     0,   642,     0,  1180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1181,     0,   956,
       0,     0,     0,     0,  1182,     0,     0,     0,     0,  1183,
       0,     0,     0,     0,     0,     0,     0,   643,   644,     0,
       0,     0,     0,     0,   645,     0,     0,  1184,     0,     0,
       0,     0,     0,     0,     0,   646,     0,     0,   647,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     648,   947,     0,     0,   803,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   957,     0,     0,
       0,     0,   649,     0,     0,     0,     0,     0,     0,   650,
     651,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
     652,     0,   958,   959,     0,     0,     0,     0,     0,     0,
       0,     0,   653,   948,     0,     0,   654,     0,     0,     0,
       0,     0,   394,     0,   949,     0,     0,   960,   950,   655,
       0,     0,     0,     0,     0,     0,   656,     0,     0,   657,
     658,     0,     0,     0,     0,   961,     0,   659,     0,     0,
       0,     0,     0,   962,   660,   333,   661,     0,     0,   662,
       0,   395,  1185,  1186,  1187,  1188,     0,  1189,     0,  1190,
    1191,  1192,  1193,  1194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   663,   639,     0,   640,   664,     0,
     665,     0,   641,     0,     0,     0,     0,   666,     0,     0,
     642,     0,   951,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,   947,     0,     0,   803,     0,   667,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,   644,   668,     0,     0,     0,     0,   645,
       0,     0,     0,   952,     0,     0,     0,     0,   953,     0,
     646,     0,   390,   647,   954,   669,     0,   955,     0,   391,
       0,     0,     0,     0,   670,   648,     0,     0,   947,     0,
       0,   803,     0,     0,     0,     0,     0,   671,     0,     0,
     947,     0,   672,   803,   673,     0,   948,   649,     0,   956,
       0,     0,   674,     0,   650,   651,     0,  1027,     0,     0,
       0,   950,   675,     0,     0,     0,     0,     0,     0,     0,
       0,   676,     0,     0,     0,     0,     0,     0,     0,     0,
     677,     0,   678,   679,     0,   652,   680,     0,   681,     0,
     392,     0,     0,   682,     0,     0,     0,   653,     0,     0,
     948,   654,     0,     0,     0,     0,     0,     0,   683,     0,
       0,     0,   948,   684,   655,   950,     0,   957,   685,     0,
       0,   656,     0,  1072,   657,   658,     0,   950,  1068,   686,
       0,     0,   659,     0,     0,     0,     0,     0,     0,   660,
     687,   661,     0,     0,   662,   951,     0,     0,     0,     0,
     688,     0,     0,   393,     0,     0,   389,     0,     0,     0,
       0,     0,   958,   959,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   663,
       0,     0,   394,   664,     0,   665,   952,   960,     0,     0,
       0,   953,   666,     0,     0,   390,     0,   954,     0,   951,
     955,     0,   391,     0,     0,   961,     0,     0,     0,   947,
     389,   951,   803,   962,   667,   333,     0,     0,     0,     0,
       0,   395,   389,     0,     0,     0,     0,     0,     0,   668,
       0,     0,   956,     0,     0,     0,     0,     0,     0,     0,
     952,     0,     0,     0,     0,   953,     0,     0,     0,   390,
     669,   954,   952,     0,   955,     0,   391,   953,     0,   670,
       0,   390,     0,   954,     0,     0,   955,     0,   391,     0,
       0,     0,   671,   392,     0,     0,     0,   672,     0,   673,
       0,   948,     0,     0,     0,     0,   956,   674,     0,   947,
       0,     0,   803,     0,     0,     0,   950,   675,   956,     0,
     957,     0,   947,     0,     0,   803,   676,     0,     0,     0,
       0,     0,     0,     0,     0,   677,     0,   678,   679,     0,
       0,   680,     0,   681,     0,     0,     0,   392,   682,     0,
       0,     0,     0,     0,     0,     0,   393,     0,     0,   392,
       0,     0,     0,   683,     0,   958,   959,     0,   684,     0,
       0,     0,     0,   685,   957,     0,     0,     0,     0,     0,
       0,   948,     0,     0,   686,   394,   957,     0,     0,     0,
     960,     0,     0,     0,   948,   687,   950,     0,     0,     0,
     951,     0,     0,     0,     0,     0,     0,     0,   961,   950,
     393,   389,     0,     0,     0,     0,   962,     0,   333,   958,
     959,     0,   393,     0,   395,     0,     0,     0,     0,     0,
       0,   958,   959,     0,     0,     0,     0,     0,     0,   394,
       0,   952,     0,     0,   960,     0,   953,     0,     0,     0,
     390,   394,   954,     0,     0,   955,   960,   391,     0,     0,
       0,     0,   961,     0,     0,     0,     0,     0,     0,     0,
     962,     0,   333,     0,   961,     0,  1307,     0,   395,     0,
     951,     0,   962,     0,   333,     0,     0,   956,     0,     0,
     395,   389,     0,   951,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   947,     0,     0,
     803,   952,     0,     0,     0,     0,   953,     0,   392,     0,
     390,     0,   954,     0,   952,   955,     0,   391,     0,   953,
       0,     0,     0,   390,     0,   954,     0,     0,   955,     0,
     391,     0,     0,     0,     0,   957,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   956,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   947,     0,
     956,   803,     0,     0,     0,     0,     0,     0,     0,   948,
       0,   393,     0,     0,     0,   803,     0,     0,     0,     0,
     958,   959,     0,     0,   950,     0,     0,     0,   392,     0,
       0,     0,     0,     0,     0,     0,  1162,     0,     0,     0,
     394,   392,     0,     0,     0,   960,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   957,     0,     0,     0,   947,
       0,     0,   803,   961,     0,     0,     0,     0,   957,     0,
     948,   962,     0,   333,     0,     0,     0,     0,     0,   395,
       0,     0,     0,     0,   948,   950,     0,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1530,   950,
     958,   959,     0,     0,   393,     0,     0,     0,   951,     0,
       0,     0,     0,   958,   959,     0,     0,     0,     0,   389,
     394,     0,     0,     0,     0,   960,     0,     0,     0,     0,
       0,   948,     0,   394,     0,     0,     0,     0,   960,     0,
       0,     0,     0,   961,     0,     0,   950,     0,     0,   952,
       0,   962,     0,   333,   953,     0,   961,     0,   390,   395,
     954,     0,     0,   955,   962,   391,   333,     0,     0,   951,
       0,     0,   395,     0,     0,     0,     0,     0,     0,     0,
     389,     0,     0,   951,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,   956,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     952,     0,     0,     0,     0,   953,     0,     0,     0,   390,
       0,   954,     0,     0,   955,     0,   391,     0,     0,     0,
     951,     0,     0,   390,     0,   954,   392,     0,   955,     0,
     391,   389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   956,     0,     0,     0,
       0,     0,     0,   957,     0,     0,     0,     0,     0,     0,
     956,   952,     0,     0,     0,     0,   953,     0,     0,     0,
     991,     0,   954,     0,     0,   955,     0,   391,     0,     0,
       0,     0,     0,     0,  1659,     0,     0,   392,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,   958,   959,
       0,   392,     0,     0,     0,     0,     0,   956,     0,     0,
       0,     0,     0,     0,   957,     0,     0,     0,   394,     0,
       0,     0,     0,   960,     0,     0,     0,     0,   957,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   961,     0,     0,     0,     0,     0,     0,   392,   962,
     393,   333,     0,     0,     0,     0,     0,   395,     0,   958,
     959,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,   958,   959,   957,     0,     0,     0,   394,
       0,     0,     0,     0,   960,     0,     0,     0,     0,     0,
       0,     0,     0,   394,     0,     0,     0,     0,   960,     0,
       0,     0,   961,     0,     0,     0,     0,     0,     0,     0,
     962,   393,   333,     0,     0,     0,   961,     0,   395,     0,
     958,   959,     0,     0,   962,     0,   333,     0,     0,     0,
       0,   565,   395,     0,     0,     0,     0,     0,     0,     0,
     394,     0,     0,   566,     0,   960,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   961,     0,     0,     0,     0,     0,     0,
       0,   962,     0,   333,     0,     0,     0,     0,     0,   395,
     574,     0,   575,   576,   577,   578,   579,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   581,     0,     0,  1558,     0,  1559,     0,     0,
    1560,   567,   568,   569,   570,   571,   572,   573,  1561,  1562,
    1563,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1564,     0,
       0,     0,     0,     0,     0,   574,     0,   575,   576,   577,
     578,   579,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   582,     0,     0,   581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
     583,     0,     0,     0,     0,     0, -1499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1565,     0,     0,
       0,     0,   948,     0,   584,     0,   567,   568,   569,   570,
     571,   572,   573,     0,     0,  1566,     0,   950,  1567,  1568,
       0,     0,     0,     0,     0,     0,   585,     0,     0,     0,
       0,     0,  1569,  1956,  1957,     0,     0,     0,     0,   582,
     574,   586,   575,   576,   577,   578,   579,   580,   587,     0,
     588,     0,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,   589,     0,     0,     0,     0,     0,  1570,
       0,     0,     0,   590,     0,     0,     0,     0,  1571,     0,
     591,     0,   581,     0,     0,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   951,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1572,   389,     0,     0,     0,     0,   592,     0,   593,
     594,   595,     0,     0,     0,  1573,   586,     0,     0,     0,
       0,   948,     0,   587,     0,   588,     0,     0,     0,     0,
       0,     0,  1110,   596,     0,     0,   950,   953,   589,  1574,
       0,   390,     0,   954,     0,  1958,   955,     0,   391,     0,
   -1499,     0,     0,     0,   582,     0,     0,     0,   597,   598,
     599,     0,     0,  1575,     0,     0,     0,     0,  1576,     0,
     583,   600,     0,     0,   601,     0,     0,     0,   956,     0,
       0,     0,  1577,     0,  1959,  1960,     0,   948,     0,     0,
       0,     0,   592,  -318,   593,   594,   595,     0,     0,     0,
       0,     0,   950,     0,   584,     0,     0,     0,     0,  1961,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
     951,     0,     0,     0,     0,     0,   585,     0,  1578,     0,
       0,   389,     0,     0,     0,     0,     0,     0,     0,  1579,
       0,   586,     0,   597,   598,   599,   957,     0,   587,     0,
     588,     0,     0,  1962,     0,     0,   600,     0,  1580,   601,
       0,  1110,     0,   589,     0,     0,   953,     0,     0,     0,
     390,     0,   954,     0,     0,   955,     0,   391,  1581,     0,
       0,     0,   393,     0,     0,     0,   951,     0,     0,     0,
       0,   958,   959,     0,     0,     0,     0,   389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   956,     0,     0,
       0,   394,     0,     0,     0,     0,   960,   592,     0,   593,
     594,   595,     0,     0,     0,     0,  1963,  1110,     0,     0,
       0,     0,   953,     0,   961,     0,   390,     0,   954,     0,
    1964,   955,   962,   391,   333,     0,     0,     0,   392,     0,
     395,  1111,  1112,     0,     0,     0,     0,     0,     0,  1113,
    1603,     0,     0,  1965,     0,     0,     0,     0,   597,   598,
     599,     0,     0,   956,     0,   957,     0,     0,     0,     0,
       0,   600,     0,     0,   601,  1966,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1967,     0,     0,     0,     0,     0,     0,
       0,   393,     0,     0,   392,     0,     0,     0,     0,     0,
     958,   959,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     394,   957,     0,     0,     0,   960,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   961,     0,     0,     0,     0,     0,     0,
       0,   962,     0,   333,     0,     0,     0,   393,     0,   395,
    1111,  1112,     0,     0,     0,     0,   958,   959,  1113,  1818,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,     0,     0,     0,
       0,   960,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   961,
       0,     0,     0,     0,     0,     0,     0,   962,     0,   333,
       0,     0,     0,     0,     0,   395,  1111,  1112,     0,     0,
       0,     0,     0,     0,  1113
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-1940))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      83,   165,   364,   621,   478,   657,   236,   601,   481,   831,
     805,   410,  1095,  1068,   590,  1177,  1062,  1268,   259,   826,
     261,   686,   263,   627,   188,   189,   190,   828,   192,   836,
     194,   844,   185,   769,   564,  1645,   984,   827,   191,   259,
    1497,   261,  1232,   263,   857,  1335,  1010,  1377,  1378,  1223,
    1224,  1225,     6,  1254,  1018,   433,     9,   210,  1335,   330,
    1335,    17,   226,  1335,   228,    13,   149,     6,  1335,  1335,
     544,   235,     9,     6,    53,    47,     6,    82,   825,   243,
       6,   311,   323,   101,    22,    17,   833,   834,   318,    91,
     331,   255,   256,  1139,   258,    91,   108,   338,   262,  1461,
    1064,   848,   849,   323,  1466,    81,    88,   116,    69,   756,
      69,   331,   265,   266,    48,   862,   863,  1778,   338,   164,
    1272,   207,    27,    71,   365,   396,   290,    67,   866,   293,
     294,   361,   296,   160,   115,  1336,    60,    55,   368,    87,
    1722,    55,     9,  1046,  1052,   365,     9,   367,   312,   175,
    1098,   381,   947,  1763,   627,   118,  1357,   952,    48,    55,
     564,    29,    63,    67,    22,   329,    39,   180,   962,   374,
      36,    63,    31,   200,   227,   236,   115,    48,   408,    47,
     798,   208,   412,   403,   425,   227,     9,   162,   341,   272,
     144,    21,    55,   464,    21,    48,   115,   180,   227,   363,
     239,   148,   392,    48,   109,   425,    67,   371,  1430,   112,
     227,   116,    67,   165,  1009,   227,    24,   217,   965,   242,
      67,  1936,   180,  1938,  1446,   188,    58,   974,   846,   919,
    1138,   207,   206,   200,  1564,   165,   466,   239,   315,   300,
    1570,   107,   772,    48,  1327,   269,   993,  1060,   193,   479,
     628,   278,    84,    85,     9,   445,   420,  1312,   112,   206,
     259,    29,  1463,   346,   227,   366,   349,  1457,   362,   207,
    1460,   234,  1494,  2212,   227,   439,   440,    82,     0,   165,
    1027,   511,   256,   246,     9,   239,   516,   348,   443,  1361,
     937,   938,  2231,   295,   260,   261,  1368,  1162,   503,   158,
     168,   521,   522,  1375,   167,  1887,   924,   254,  1890,   256,
     315,   475,  1534,   407,   908,  1110,   124,   340,   331,  1681,
    1682,   188,  1069,   224,   227,  1368,  1290,  1074,  1276,   289,
     275,  1693,  1375,  1133,   294,   939,   336,   501,  1246,   321,
    1162,    67,   305,   444,   508,   211,   370,   424,   331,   207,
     203,   312,   120,   216,   393,   585,   227,   443,   934,   935,
     227,   234,  2077,  1101,  1229,   270,  1421,   234,   772,   344,
     207,   591,  1275,   227,   211,   207,   235,   430,   851,   543,
     338,   315,   443,   117,   548,   430,  2047,   551,   430,   553,
     291,  1437,   556,   557,  1259,  1547,   560,   311,   143,   291,
    1308,   430,   384,   430,   227,   368,  1213,  1229,   371,   372,
     350,   429,   430,   430,   162,  1162,  1811,   443,   430,   424,
     429,  1111,  1112,  1113,  1231,   315,   385,   399,   430,   353,
     429,  1121,   413,   188,   430,   396,   600,  1259,   305,    67,
    1662,   331,  1307,  1256,   423,  1409,   350,   277,  1195,   425,
    1240,   283,  2034,  1143,   393,  1145,   423,  1147,   390,  1367,
     393,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1831,
     315,   427,   227,   436,   413,   393,   430,   430,   430,   234,
    1270,  1228,  1229,  1940,  1846,  1307,   331,  1134,   354,   350,
     424,   430,   430,   430,   413,   350,   444,   430,  1788,   429,
     430,   368,  1753,   350,   430,   919,   446,  1869,  1126,  1699,
     315,  1788,  1259,  1788,  1876,   828,  1788,  1691,   759,   760,
    1172,  1788,  1788,   242,   429,   766,   251,   430,  1318,  1493,
     397,   399,   803,   846,   424,   431,   756,   400,   851,   759,
     760,  1613,   446,  1408,   430,  1018,   766,  1294,  1910,  1911,
     305,  1298,  1299,   443,  1301,   300,  1356,  1919,   919,   430,
    1307,   429,   940,  1036,   394,   436,  1142,   394,   398,   436,
    1613,   398,   306,  1149,  1104,  1776,   430,  2187,  1486,   424,
    2037,   231,   746,   308,   748,   446,  1408,   443,   111,   231,
     820,   446,   191,   430,   290,  1817,   344,  1333,   443,   446,
     227,   251,   133,   169,   768,   133,   919,   827,   290,   251,
    1518,   443,  1667,   368,   191,   192,   227,   227,   216,   424,
     354,   340,  2017,  2018,   350,   180,  1956,   847,   239,  1419,
     193,   851,   231,   853,     9,   855,   856,    12,   858,   157,
      15,    16,   397,   269,   227,  2007,   887,   395,  1870,  2011,
    1872,   216,   251,   873,   231,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1238,   904,  2026,   936,   161,   887,    30,    67,
     890,    11,   283,   173,   251,   430,  1280,   227,  1900,  1492,
    1284,   436,   144,   358,   904,   430,   181,   917,  1636,  1637,
    1638,  1052,  2054,  2150,  2056,   238,   176,  1111,  1112,  1113,
    1664,   309,   922,   311,   267,  2067,   238,  1121,   180,  1931,
    1932,   437,   438,   439,   440,   120,   442,   937,   938,   302,
     446,   180,   350,  1036,   443,  2087,  2088,   227,  1766,   882,
      70,  1145,   407,   429,    29,  1208,   362,  1151,  1152,  1153,
    1154,   905,   104,  1157,  1158,  1800,   289,   429,   430,   832,
    1111,  1112,  1113,   319,   394,  1810,  1811,   289,   398,   236,
    1121,   279,  1338,  1428,    60,   236,  1567,  1731,    63,   852,
     301,   854,   295,   301,   231,   114,   859,  1138,  1525,   429,
     430,   407,  1143,   338,  1145,   868,  1147,   429,  1149,   339,
    1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1111,  1112,
    1113,     9,   400,   430,  1712,  2167,  1279,  1383,  1121,   437,
     438,   439,   440,    12,   442,  1467,    15,    16,   446,   430,
     430,   301,   265,   300,  1476,   436,   436,   426,  1048,   300,
    1143,  1696,  1145,  1698,  1147,   400,  1149,   120,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1319,    55,   253,   426,
    1644,     9,   429,  1891,  1095,  1649,  1650,  2108,   312,  1653,
    1654,  1655,  1770,  1657,  1658,   227,   338,    27,  1733,   244,
     245,   348,   242,  1103,  1696,  1095,  1698,   348,   173,   338,
     337,   150,   151,   430,   327,  1246,   855,   262,   263,   169,
      26,    49,     4,  1700,   437,   438,   443,  2059,   231,  2061,
    1765,   443,   985,  1949,   873,   437,   438,    19,   231,   178,
       6,  1733,   249,     9,  1134,   184,    28,   180,   251,  2141,
    2142,   833,    11,   206,   367,     9,   369,   101,   251,   224,
    1094,  1345,  1346,  1347,  1348,  1349,  1350,  1351,   227,   309,
     236,   311,   396,  1765,  1751,  1521,   215,  1308,    60,   109,
     219,   863,   350,   181,  1606,   188,  1646,   294,   238,   167,
     249,  1651,  2017,  2018,  2215,  1438,   443,    56,   358,   218,
     253,    55,   443,   256,   223,    86,    87,  1338,   358,   207,
     188,   195,    78,   188,  1345,  1346,  1347,  1348,  1349,  1350,
    1351,   314,    96,  1740,   227,   169,   291,    93,   358,   110,
     289,   234,    91,    92,   300,    94,  1367,   181,   216,   358,
     224,    46,   117,   102,   268,   278,   270,   407,   309,   227,
    1240,   227,   227,  1496,    59,  1338,   234,   407,   277,   234,
     188,   161,  1345,  1346,  1347,  1348,  1349,  1350,  1351,   437,
     438,   439,   440,  1047,   442,   244,   245,   407,   446,  2132,
    1270,   181,   348,   953,   150,  1512,   161,   353,   407,  1532,
     218,    96,     8,   262,   263,   160,  1539,   156,     8,   227,
    1527,   188,   305,   364,   365,    11,   234,   163,   978,  1083,
     153,   177,   405,   195,   157,   429,  1327,  1328,    34,   231,
    1489,  1838,   188,  1711,    34,   309,   443,   305,  1318,   443,
     305,   204,   316,   352,   188,   200,   429,  1327,  1328,   251,
     227,   469,   224,   208,     2,   201,   474,   234,     6,   231,
      56,   231,   218,   209,   227,  1486,  1487,   223,   260,   261,
    1793,   227,   216,   229,   430,   368,   232,    79,   234,   228,
     354,   251,   309,   227,   311,  1808,  1809,   305,  1766,  1143,
     234,   286,   287,  1147,   412,    91,    92,  1518,    94,   346,
     368,  1155,  1156,   368,   276,   300,   102,   425,   264,  1964,
     282,   114,   207,   284,   285,   444,  1923,   212,   447,   448,
     155,   443,  1395,   278,   159,  1398,   443,   222,   305,   397,
    1403,   297,   400,   437,   438,   439,   440,   309,   442,  1419,
    2022,   443,  2024,   436,   316,   449,   224,   225,   394,   305,
     368,   346,   398,   443,   325,   326,   147,   329,   149,   346,
     156,   305,   430,   443,   437,   438,   439,   440,   436,   442,
     114,   436,  1646,   446,   224,   225,   332,  1651,   255,   397,
     257,   353,   354,   301,   356,    78,   129,   439,   440,   188,
     442,   368,   364,   342,  1567,   309,  1730,   311,   300,   443,
      93,   147,  1735,   149,   437,   438,   439,   440,  1741,   442,
     346,   432,   368,  1891,   309,   310,   449,   443,   436,   346,
     397,   377,   378,   395,   368,  1646,  1949,   322,   227,   324,
    1651,   163,   228,   382,   331,   234,   230,  2044,   443,    32,
     443,   397,    35,    24,    25,   430,   402,   209,   349,  1550,
      43,    44,    45,   397,   443,   443,   400,   443,   395,   436,
     443,   443,   346,   226,   420,  1555,   175,   443,  1802,   430,
    1550,   443,   428,  1646,   430,   443,   430,   385,  1651,  2002,
     436,   430,  1572,    64,   177,    66,   430,   273,   444,  1590,
    2013,  1712,   436,  2016,   443,   188,   443,    23,   443,  1720,
     346,   322,  1526,   362,   207,   443,   305,  1608,   430,   101,
    1590,   824,   374,   357,    55,   828,    97,    98,    99,    81,
     833,   169,   443,   346,   341,   838,   839,  1551,  1608,   424,
     430,   844,   845,   846,   227,  1559,   229,  2144,   851,   232,
    2147,   234,  1566,   273,   857,   103,   342,  1648,   443,  1770,
     362,   227,   353,   866,   867,   443,   869,   204,   240,   152,
     430,    65,   443,   144,   346,   146,    78,   443,  1648,   368,
     240,   264,    22,   154,    30,   267,    32,   170,   430,    35,
     443,    93,   437,   438,   439,   440,   382,   442,   227,    45,
     291,  2198,   443,  1617,   187,   443,  1620,    80,   397,    80,
    2123,   416,   417,   418,   419,  2128,   919,   425,   437,   438,
     439,   440,   305,   442,   430,   390,   430,   446,   437,   438,
     439,   440,   307,   442,   393,   225,   193,   446,   309,  2236,
     354,   430,   430,    54,   430,   393,   949,   436,   374,   332,
     233,   429,    26,   181,   225,   437,   438,   439,   440,   362,
     442,  2105,   346,   443,   446,  2133,   443,   374,   239,   437,
     438,   439,   440,   443,   442,   177,   211,   354,   446,   430,
     218,   984,   427,   207,   336,   368,   103,   437,   438,   439,
     440,   227,   442,   296,   377,   378,   446,   280,    36,     6,
     277,   371,     9,   271,  1784,   436,   393,  1010,   445,   390,
    1724,    26,   352,   267,   397,  1018,  1019,   168,   450,   402,
     443,   430,    29,   227,   170,   227,   443,   229,   174,   130,
     232,  2233,  2234,  1036,   101,    17,   166,   420,   181,   429,
     445,   187,   392,   390,   227,   428,    29,   430,  1960,  1052,
     333,   121,    55,   436,   122,   423,    63,  1060,   393,   445,
     343,  1064,   264,   416,   417,   418,   419,   445,   124,  1072,
     198,    78,  1075,   338,   126,   309,  1790,   416,   417,   418,
     419,  1795,   445,   445,   445,   127,    93,   233,   445,   445,
     445,   445,   389,    95,   445,  1098,   445,   393,  1101,   131,
      48,   392,  1735,   132,   390,   392,  1897,   387,  1111,  1112,
    1113,   173,   137,   425,   239,    48,   140,   106,  1121,   173,
     391,   404,   323,   370,   108,   270,   393,  1897,   108,   429,
     332,   430,   180,   331,   280,  1138,   299,  1851,   388,   227,
    1143,   415,  1145,  1857,  1147,   157,   427,   128,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,   165,   427,   304,   430,
     393,   356,   203,   393,    48,   211,   203,   173,   270,   116,
     177,   355,   186,   442,   435,   377,   378,   211,   434,   260,
     224,   188,   328,   446,   446,   393,   446,   333,   446,   331,
     125,   363,   256,   180,   255,    17,   393,   343,   390,   321,
     402,   347,    48,   132,  1984,     8,   173,   427,   120,   427,
       9,   218,   393,   297,   167,   298,   223,   224,   420,   195,
     227,   319,   229,   258,   334,   232,   428,   234,   430,   259,
     119,   424,   104,   424,    48,   169,   275,   135,  1952,   136,
     253,   231,   252,  1246,   138,   290,   279,   274,   107,  1963,
     384,  1965,     7,  1256,   110,   213,    64,   264,   404,   394,
     123,   318,   130,   318,    96,    48,  1269,   231,   414,   211,
    2040,   257,   139,  1276,    90,   254,   142,    87,   214,   196,
    1283,   185,  1996,  1997,   291,   380,   427,  1290,    48,   396,
     231,     6,   430,   297,     9,   168,   141,   173,   305,  1302,
     231,   297,   274,   334,   412,  1308,   283,   134,   274,   150,
     150,  1314,    48,     6,    21,  2095,   317,   182,    53,  2110,
     167,   128,   177,  1291,   460,   332,   196,  1330,   537,   893,
    1084,   396,  2046,  1780,   132,  2115,  2116,   549,  1734,   887,
    2110,  2132,  1345,  1346,  1347,  1348,  1349,  1350,  1351,   107,
     212,   346,    48,   217,   149,   819,   522,   284,   797,  1788,
     907,   368,  2132,    78,  1367,  1592,  2130,   924,   505,  1979,
     377,   378,  2116,   120,   772,  1669,   442,  1738,    93,   533,
     993,  1380,  2096,  2097,  1387,  1379,  2100,  1632,   998,  1667,
     397,  1864,  1234,  2107,  1231,   402,  1460,  1699,  1249,  2179,
    2180,  1720,  1881,  2183,  1484,  2185,  1409,  1243,  1739,  1508,
    1319,  1036,  1284,   420,  2205,  1755,  1058,  1060,   858,  1422,
    1423,   428,  1069,   430,  1610,  1539,  2047,  1934,   143,   436,
    1539,  1746,    78,  1945,  2148,  2205,  1195,  1435,  1939,  1924,
    1202,  1048,  2212,  1924,  1521,  2225,  1924,    93,   224,   920,
     292,  1254,  1167,  2086,   802,   558,   929,  2134,   763,    56,
    1796,  2231,   177,    -1,    -1,  1124,    -1,  2181,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1486,  1487,    -1,    -1,    -1,    -1,  1492,
    1493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2214,    -1,    -1,   218,    -1,    -1,    -1,  1510,   223,    -1,
      -1,    -1,   227,    -1,   229,  1518,  2149,   232,    -1,   234,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,
    1533,   177,    -1,    -1,    -1,  1538,  1539,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,   264,
      -1,    -1,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,  1567,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1578,    -1,  1580,    -1,    -1,
    2213,   227,    -1,   229,    -1,    -1,   232,    -1,    -1,    -1,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,   264,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1636,  1637,  1638,    -1,    -1,    -1,    93,
      -1,    -1,    -1,  1646,    -1,    -1,    -1,    -1,  1651,    -1,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1664,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    78,   394,
      -1,    -1,   397,   398,    -1,    -1,   332,   402,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,   150,   151,    -1,    -1,
      -1,    -1,  1705,    -1,    -1,   420,    -1,    -1,  1711,  1712,
      -1,    -1,    48,   428,    -1,   430,    -1,  1720,    -1,    -1,
      -1,   436,    -1,   177,   178,    -1,    -1,    -1,  1731,    -1,
     184,   377,   378,    -1,   188,    -1,  1739,    -1,    -1,    -1,
      -1,   387,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   402,    93,    -1,    -1,
      -1,   215,    -1,  1766,   218,   219,   412,  1770,    -1,   223,
      -1,   171,    -1,   227,   420,   229,    -1,   177,   232,   425,
     234,    -1,   428,   429,   430,    -1,  1789,    -1,    -1,    -1,
    1793,    -1,    -1,   247,   248,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,  1808,  1809,    -1,   262,    -1,
     264,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,   229,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,   292,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   305,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,  1891,    -1,
      -1,   227,    -1,   229,    -1,    -1,   232,    -1,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,   378,    -1,    -1,  1930,   264,    -1,
      -1,    -1,   332,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,    -1,    -1,  1949,    -1,   402,    -1,
       0,     1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,  1966,    -1,    -1,   420,    -1,    18,   305,
      -1,    -1,    -1,    -1,   428,    -1,   430,   377,   378,   315,
      -1,    -1,   436,   437,   438,   439,   440,   387,   442,    -1,
     444,   445,   446,   447,   448,    -1,   332,    -1,    -1,  2002,
      50,    51,   402,    -1,    -1,    -1,    -1,    57,    -1,    -1,
    2013,    -1,   412,  2016,    -1,    -1,    -1,    -1,    68,    -1,
     420,    71,    -1,    -1,    -1,   425,   362,    -1,   428,   429,
     430,    -1,   368,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   397,   112,   113,    -1,    -1,   402,    -1,    -1,    -1,
      -1,   407,    -1,  2076,    -1,    -1,  2079,    -1,    -1,   129,
      -1,    -1,    -1,   133,   420,    -1,    -1,    -1,   424,    -1,
      -1,    -1,   428,   143,   430,    -1,    -1,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,   155,  2109,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2123,    -1,   172,    -1,    -1,  2128,   176,    -1,    -1,   179,
      -1,    -1,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
      -1,    -1,   202,  2156,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    -1,     5,    -1,    -1,  2169,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,   272,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   317,    -1,    -1,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
     330,    -1,    -1,    -1,    -1,   335,    -1,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,    -1,     6,    -1,    -1,
       9,   143,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   364,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,   373,    -1,   375,   376,    -1,    -1,   379,
     172,   381,    -1,    -1,    -1,    -1,   386,   179,    -1,    -1,
     182,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,   401,    -1,    -1,    -1,   197,   406,   199,    -1,    -1,
     202,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     430,    -1,    -1,   433,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,    -1,   237,    -1,   106,    -1,   241,
      -1,   243,    -1,    -1,     6,    -1,    -1,     9,   250,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
     272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,   308,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   317,    78,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,    -1,
      -1,    93,    -1,   335,   203,   337,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   355,   223,    -1,    -1,    -1,   227,    -1,
     229,    -1,   364,   232,    -1,   234,    -1,    -1,    -1,    -1,
      -1,   373,    -1,   375,   376,    -1,    -1,   379,    -1,   381,
      -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   150,   151,
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   401,
      -1,    -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,   411,
      -1,    -1,    -1,    -1,    -1,   177,   178,    -1,   194,    -1,
     422,    -1,   184,    -1,    -1,    -1,   188,    -1,   430,    -1,
      -1,   433,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,
      -1,   443,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,   218,   219,    -1,    -1,
      -1,   223,    -1,   332,    -1,   227,    -1,   229,   244,    -1,
     232,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,     9,   247,   248,    12,    13,    14,
     252,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,   368,
     262,    -1,   264,    -1,    -1,   281,    -1,   269,   377,   378,
      -1,    -1,   274,    -1,   290,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   397,    -1,
     292,    -1,    -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    78,    -1,    -1,    -1,    -1,    -1,   428,
      -1,   430,    -1,    -1,    -1,    -1,    -1,   436,    93,    -1,
     332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   359,   360,   361,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,    -1,   408,   409,   410,   397,    -1,    -1,    -1,    -1,
     402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,    -1,    -1,    -1,    -1,   420,   184,
      -1,    -1,    -1,   188,    -1,    -1,   428,    -1,   430,    -1,
      -1,    -1,    -1,    -1,   436,   437,   438,   439,   440,    -1,
     442,    -1,   444,   445,   446,   447,   448,    -1,    -1,    -1,
     215,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,   227,    -1,   229,    -1,    -1,   232,    -1,   234,
       3,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,   247,   248,    -1,    18,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,   264,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,   292,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    78,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,   397,    -1,    89,    -1,    -1,   402,    93,   172,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,   182,
     183,    -1,    -1,    -1,    -1,   420,    -1,   190,    -1,    -1,
      -1,    -1,    -1,   428,   197,   430,   199,    -1,    -1,   202,
      -1,   436,   437,   438,   439,   440,    -1,   442,    -1,   444,
     445,   446,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,     3,    -1,     5,   241,    -1,
     243,    -1,    10,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      18,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,     6,    -1,    -1,     9,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,   287,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,
      68,    -1,   227,    71,   229,   308,    -1,   232,    -1,   234,
      -1,    -1,    -1,    -1,   317,    83,    -1,    -1,     6,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,   330,    -1,    -1,
       6,    -1,   335,     9,   337,    -1,    78,   105,    -1,   264,
      -1,    -1,   345,    -1,   112,   113,    -1,    89,    -1,    -1,
      -1,    93,   355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   364,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     373,    -1,   375,   376,    -1,   143,   379,    -1,   381,    -1,
     305,    -1,    -1,   386,    -1,    -1,    -1,   155,    -1,    -1,
      78,   159,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,
      -1,    -1,    78,   406,   172,    93,    -1,   332,   411,    -1,
      -1,   179,    -1,    89,   182,   183,    -1,    93,   106,   422,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     433,   199,    -1,    -1,   202,   177,    -1,    -1,    -1,    -1,
     443,    -1,    -1,   368,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,    -1,   397,   241,    -1,   243,   218,   402,    -1,    -1,
      -1,   223,   250,    -1,    -1,   227,    -1,   229,    -1,   177,
     232,    -1,   234,    -1,    -1,   420,    -1,    -1,    -1,     6,
     188,   177,     9,   428,   272,   430,    -1,    -1,    -1,    -1,
      -1,   436,   188,    -1,    -1,    -1,    -1,    -1,    -1,   287,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,   227,
     308,   229,   218,    -1,   232,    -1,   234,   223,    -1,   317,
      -1,   227,    -1,   229,    -1,    -1,   232,    -1,   234,    -1,
      -1,    -1,   330,   305,    -1,    -1,    -1,   335,    -1,   337,
      -1,    78,    -1,    -1,    -1,    -1,   264,   345,    -1,     6,
      -1,    -1,     9,    -1,    -1,    -1,    93,   355,   264,    -1,
     332,    -1,     6,    -1,    -1,     9,   364,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,    -1,   375,   376,    -1,
      -1,   379,    -1,   381,    -1,    -1,    -1,   305,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,   305,
      -1,    -1,    -1,   401,    -1,   377,   378,    -1,   406,    -1,
      -1,    -1,    -1,   411,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,   422,   397,   332,    -1,    -1,    -1,
     402,    -1,    -1,    -1,    78,   433,    93,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,    93,
     368,   188,    -1,    -1,    -1,    -1,   428,    -1,   430,   377,
     378,    -1,   368,    -1,   436,    -1,    -1,    -1,    -1,    -1,
      -1,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,   397,
      -1,   218,    -1,    -1,   402,    -1,   223,    -1,    -1,    -1,
     227,   397,   229,    -1,    -1,   232,   402,   234,    -1,    -1,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,   430,    -1,   420,    -1,   173,    -1,   436,    -1,
     177,    -1,   428,    -1,   430,    -1,    -1,   264,    -1,    -1,
     436,   188,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,   218,    -1,    -1,    -1,    -1,   223,    -1,   305,    -1,
     227,    -1,   229,    -1,   218,   232,    -1,   234,    -1,   223,
      -1,    -1,    -1,   227,    -1,   229,    -1,    -1,   232,    -1,
     234,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
     264,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,   368,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
     377,   378,    -1,    -1,    93,    -1,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,
     397,   305,    -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,     6,
      -1,    -1,     9,   420,    -1,    -1,    -1,    -1,   332,    -1,
      78,   428,    -1,   430,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    78,    93,    -1,    -1,    -1,    -1,
      -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,   362,    93,
     377,   378,    -1,    -1,   368,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   377,   378,    -1,    -1,    -1,    -1,   188,
     397,    -1,    -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,
      -1,    78,    -1,   397,    -1,    -1,    -1,    -1,   402,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    93,    -1,    -1,   218,
      -1,   428,    -1,   430,   223,    -1,   420,    -1,   227,   436,
     229,    -1,    -1,   232,   428,   234,   430,    -1,    -1,   177,
      -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,   232,    -1,   234,    -1,    -1,    -1,
     177,    -1,    -1,   227,    -1,   229,   305,    -1,   232,    -1,
     234,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
     227,    -1,   229,    -1,    -1,   232,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,   305,    -1,   368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,   378,
      -1,   305,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,   397,    -1,
      -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,   332,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,   305,   428,
     368,   430,    -1,    -1,    -1,    -1,    -1,   436,    -1,   377,
     378,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,   378,   332,    -1,    -1,    -1,   397,
      -1,    -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,   402,    -1,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   368,   430,    -1,    -1,    -1,   420,    -1,   436,    -1,
     377,   378,    -1,    -1,   428,    -1,   430,    -1,    -1,    -1,
      -1,    21,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     397,    -1,    -1,    33,    -1,   402,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,    -1,   430,    -1,    -1,    -1,    -1,    -1,   436,
      70,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    30,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,    78,    -1,   244,    -1,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,   170,    -1,    93,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,   187,    63,    64,    -1,    -1,    -1,    -1,   194,
      70,   281,    72,    73,    74,    75,    76,    77,   288,    -1,
     290,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,   233,    -1,
     320,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   188,    -1,    -1,    -1,    -1,   357,    -1,   359,
     360,   361,    -1,    -1,    -1,   280,   281,    -1,    -1,    -1,
      -1,    78,    -1,   288,    -1,   290,    -1,    -1,    -1,    -1,
      -1,    -1,   218,   383,    -1,    -1,    93,   223,   303,   304,
      -1,   227,    -1,   229,    -1,   185,   232,    -1,   234,    -1,
     400,    -1,    -1,    -1,   194,    -1,    -1,    -1,   408,   409,
     410,    -1,    -1,   328,    -1,    -1,    -1,    -1,   333,    -1,
     210,   421,    -1,    -1,   424,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   347,    -1,   224,   225,    -1,    78,    -1,    -1,
      -1,    -1,   357,   443,   359,   360,   361,    -1,    -1,    -1,
      -1,    -1,    93,    -1,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,
     177,    -1,    -1,    -1,    -1,    -1,   266,    -1,   393,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,
      -1,   281,    -1,   408,   409,   410,   332,    -1,   288,    -1,
     290,    -1,    -1,   293,    -1,    -1,   421,    -1,   423,   424,
      -1,   218,    -1,   303,    -1,    -1,   223,    -1,    -1,    -1,
     227,    -1,   229,    -1,    -1,   232,    -1,   234,   443,    -1,
      -1,    -1,   368,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,   377,   378,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,   397,    -1,    -1,    -1,    -1,   402,   357,    -1,   359,
     360,   361,    -1,    -1,    -1,    -1,   366,   218,    -1,    -1,
      -1,    -1,   223,    -1,   420,    -1,   227,    -1,   229,    -1,
     380,   232,   428,   234,   430,    -1,    -1,    -1,   305,    -1,
     436,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,   445,
     446,    -1,    -1,   403,    -1,    -1,    -1,    -1,   408,   409,
     410,    -1,    -1,   264,    -1,   332,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,   424,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   368,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,
     377,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     397,   332,    -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,    -1,   430,    -1,    -1,    -1,   368,    -1,   436,
     437,   438,    -1,    -1,    -1,    -1,   377,   378,   445,   446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,
      -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,   430,
      -1,    -1,    -1,    -1,    -1,   436,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,   445
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   452,   453,     0,   176,   301,   454,   455,   456,   462,
     469,   471,   443,   443,   455,   144,   477,   477,   227,   302,
     472,   472,   114,   457,   463,    26,   473,   473,   443,    96,
     572,   572,   227,   443,   470,    79,   478,   114,   458,   464,
     207,   474,  1115,   346,   163,   201,   209,   529,   443,   297,
     706,   706,   443,    69,   312,   396,   475,   476,   443,   443,
     346,   443,   162,   344,   395,   573,   579,   114,   459,   465,
     469,   129,   468,   476,   300,  1126,   479,   530,   443,   531,
     346,   432,   604,   575,    53,   423,   709,   133,   459,   466,
     477,   472,   265,   327,   367,   369,   480,   481,   485,   493,
     498,   533,   163,   532,   242,   340,   563,   564,   565,   566,
     568,   443,   346,   230,   649,   430,   578,   580,  1047,   711,
     710,   331,   717,   472,   460,   443,   443,   443,   443,   443,
     349,   534,   443,   209,   562,   395,  1111,   309,   364,   365,
     567,   443,   565,   574,   443,   346,   226,   651,   577,   579,
     606,   607,   608,   581,    48,   712,   713,   714,  1106,   712,
     430,   443,   443,   572,   236,   348,   430,   484,   486,   487,
     488,   489,   491,   492,  1126,   175,   494,   495,   496,   429,
     482,   483,   484,  1140,    11,    56,    91,    92,    94,   102,
     156,   228,   342,   382,   430,   499,   500,   501,   502,   506,
     515,   519,   522,   523,   524,   525,   526,   527,   528,   273,
    1093,   533,   443,   385,  1134,    23,  1102,   576,   605,   443,
     346,   322,   653,   580,   609,  1087,   582,   713,   362,   407,
     715,   315,   424,   707,   461,   362,  1115,   443,   487,   443,
     488,    60,   353,  1099,     9,   227,   497,   443,   496,   443,
     443,   483,   101,   430,  1058,  1058,   374,   357,  1130,  1115,
    1115,  1115,  1058,  1115,    55,  1108,  1115,   443,   501,  1058,
     563,    81,  1109,   169,  1112,   577,   606,   650,   443,   346,
     341,   694,   606,   443,  1087,   430,   610,   612,   617,    46,
      59,    96,   212,   222,   309,   310,   322,   324,   424,   443,
     583,   584,   586,   590,   592,   594,   595,   601,   602,   603,
    1115,  1115,   362,   273,   716,   103,   718,   706,  1115,   227,
    1076,   443,   353,  1115,   204,   204,   227,   443,   240,   507,
    1115,  1115,  1115,   430,  1055,  1073,    65,  1055,  1115,  1055,
     516,   517,  1058,    91,  1058,   535,   569,   570,  1047,  1046,
    1047,   606,   652,   443,   346,   610,   443,   165,   430,   613,
     614,  1109,  1115,   309,   311,  1097,  1097,  1115,  1109,  1115,
     240,  1120,  1115,    22,  1101,   267,   161,   181,    30,   104,
    1076,  1115,   430,   443,   708,   465,  1076,  1055,  1115,   188,
     227,   234,   305,   368,   397,   436,   520,   521,  1079,  1055,
     227,   193,   267,  1096,  1055,    22,   207,  1058,  1116,   503,
     536,   570,   291,   571,  1047,   606,   654,   443,   443,   611,
      80,  1076,   430,  1115,  1101,  1054,  1055,   269,   370,   591,
     227,  1055,  1057,  1076,   425,  1115,   430,   693,   693,   164,
     430,  1076,   719,   720,   133,   467,    55,   431,   490,   118,
     188,   227,   234,   246,   305,   368,   371,   372,   436,   508,
     509,   510,   513,   521,   390,  1073,   518,  1076,   504,     4,
      19,    28,   195,   224,   231,   276,   282,   309,   316,   329,
     354,   356,   364,   395,   443,   537,   538,   542,   544,   545,
     546,   547,   548,   552,   553,   554,   555,   556,   558,   559,
     560,  1099,  1076,   307,   655,   656,   657,   695,   618,   615,
    1115,   393,   589,  1055,   225,  1119,   393,  1108,   193,  1114,
     430,  1115,  1115,   720,     1,   430,   443,   721,   722,   723,
     724,   725,   730,   731,   472,   510,    17,   390,  1079,  1076,
     268,   270,   505,  1120,   309,   393,  1138,   354,  1120,  1115,
      54,  1107,    36,   107,   211,  1105,  1117,  1117,  1076,  1140,
     374,  1115,   693,   657,   696,    21,    33,    36,    37,    38,
      39,    40,    41,    42,    70,    72,    73,    74,    75,    76,
      77,   112,   194,   210,   244,   266,   281,   288,   290,   303,
     313,   320,   357,   359,   360,   361,   383,   408,   409,   410,
     421,   424,   619,   620,   621,   623,   624,   625,   626,   627,
     628,   637,   638,   640,   641,   642,   647,   648,  1115,  1131,
      26,  1103,   181,  1076,    55,   311,   585,   596,  1076,   362,
    1132,   227,   593,  1073,   593,   120,   443,   443,   346,     3,
       5,    10,    18,    50,    51,    57,    68,    71,    83,   105,
     112,   113,   143,   155,   159,   172,   179,   182,   183,   190,
     197,   199,   202,   237,   241,   243,   250,   272,   287,   308,
     317,   330,   335,   337,   345,   355,   364,   373,   375,   376,
     379,   381,   386,   401,   406,   411,   422,   433,   443,   732,
     733,   743,   748,   752,   755,   768,   771,   776,   781,   782,
     783,   786,   794,   798,   800,   815,   818,   820,   822,   825,
     827,   833,   842,   844,   861,   863,   866,   870,   876,   886,
     893,   895,   898,   902,   903,   914,   925,   935,   941,   944,
     950,   954,   956,   958,   960,   963,   974,   975,   984,   986,
     987,   732,   443,   511,   513,   374,  1133,  1115,  1117,   117,
     161,   540,  1115,   309,   316,   553,  1115,  1115,   354,  1115,
    1115,  1102,     9,   251,   308,   561,  1115,   430,   658,   612,
     617,   697,   698,   699,   218,   358,   407,   358,   407,   358,
     407,   358,   407,   358,   407,   427,  1139,   336,  1128,  1076,
    1072,  1073,  1073,   207,   217,   336,   639,  1115,  1116,   161,
     181,   216,   400,     9,    49,   218,   616,  1077,  1078,  1079,
      29,   597,   598,   599,   600,  1104,  1140,  1108,   173,   588,
    1113,   103,   227,   726,   734,   744,   749,   753,   756,   769,
     772,   777,   784,   787,   795,   799,   801,   816,   819,   821,
    1138,   826,     1,   828,   834,   843,   845,   862,   864,   867,
     871,   877,   887,   894,   896,   899,   904,   915,   926,   936,
     227,   339,   945,   951,   296,   955,   957,   959,   961,   964,
     181,   976,  1112,   988,   188,   227,   234,   305,   368,   436,
     512,   514,  1115,   117,   306,   354,   543,  1115,   111,   295,
     539,    31,   158,   235,   549,  1057,   371,   557,  1055,  1055,
     277,  1125,  1125,   271,  1055,    58,    84,    85,   283,   443,
     659,   660,   664,  1115,   613,   699,   436,   393,   629,   445,
    1074,  1075,   390,   626,   644,   645,  1077,    26,   622,   352,
    1095,  1095,  1079,   267,  1122,  1122,   450,    47,   399,   168,
     589,  1076,   443,   443,   735,  1071,  1072,     6,    78,    89,
      93,   177,   218,   223,   229,   232,   264,   332,   377,   378,
     402,   420,   428,   745,  1041,  1061,  1062,  1071,  1077,  1080,
     430,   750,  1028,  1029,  1030,   227,  1051,  1052,  1053,  1073,
     227,  1069,  1071,  1080,   770,   773,   778,  1042,  1043,  1062,
    1047,   227,   788,  1061,  1068,  1071,   796,  1062,   227,   394,
     398,   802,   803,  1028,   286,   287,   300,   346,   817,     6,
    1059,  1060,  1071,  1071,   823,   130,  1027,  1028,  1059,   663,
    1071,   846,  1071,  1077,  1080,   927,  1073,    89,   865,  1062,
     868,  1062,   872,   171,   227,   878,   881,   882,   883,  1051,
    1069,  1073,  1140,  1047,  1044,  1073,  1047,  1044,     9,   905,
    1045,  1073,   144,   239,   916,   917,   918,   919,   921,   922,
     923,   924,  1048,  1049,  1059,   927,  1047,   942,   106,   946,
     947,  1062,    89,   952,  1061,   663,  1071,  1047,  1071,     8,
      34,   978,   101,  1044,    17,  1058,   557,   112,   227,   541,
    1073,   429,   550,   550,   366,   444,  1055,  1056,  1115,   166,
     661,   662,   661,  1116,   672,   181,   700,  1076,   392,  1137,
     218,   437,   438,   445,  1038,  1040,  1041,  1063,  1071,  1078,
    1080,   445,  1075,  1073,   643,   645,   390,   227,  1107,  1072,
    1072,  1079,  1057,  1057,  1104,  1108,   121,   742,    29,   173,
     736,  1104,  1122,   445,  1071,   445,  1081,   445,  1082,  1122,
    1096,   445,   445,   445,   445,   445,   445,   445,   445,  1081,
     122,   747,   393,   746,  1062,   198,  1090,    55,    12,    13,
      14,    20,   150,   151,   178,   184,   215,   219,   247,   248,
     252,   262,   269,   274,   292,   437,   438,   439,   440,   442,
     444,   445,   446,   447,   448,  1031,  1032,  1033,  1034,  1035,
    1062,   393,  1096,   423,   757,   227,  1068,  1071,  1047,   124,
     779,   150,   444,   780,  1043,   338,  1094,   309,  1127,   126,
     793,   736,   416,   417,   418,   419,   127,   797,    48,   203,
     757,    17,   427,   804,   805,   806,   810,    95,  1122,  1060,
    1050,   389,  1136,   835,  1140,  1071,    88,   321,   384,   847,
     848,   849,   853,   858,   929,  1062,   393,   131,   869,    48,
     160,   200,   208,   278,   873,   882,   132,   879,   412,   425,
     390,   392,   387,   249,   294,  1091,   173,   989,  1127,   989,
    1045,   137,   913,   425,   907,  1066,  1071,  1078,   922,   924,
    1059,   393,  1049,   115,   393,   413,   920,   937,   180,   331,
     943,  1106,   203,   947,  1071,   140,   953,   173,   173,   309,
     311,   962,   106,   965,   323,   370,   979,   270,  1123,   989,
     514,   116,   429,  1089,  1098,   231,   337,  1115,  1054,  1068,
     663,   670,  1076,   612,   673,   701,   108,   630,  1122,  1040,
    1040,  1040,    67,   350,   446,  1039,   437,   438,   439,   440,
     442,   449,  1040,  1139,  1077,  1119,  1057,   108,   587,  1066,
      24,    25,    64,    66,    97,    98,    99,   144,   146,   154,
     225,   391,   430,  1049,   429,   739,    63,   224,   291,   737,
     738,   143,   300,  1064,  1072,  1038,  1040,   393,  1040,  1038,
    1083,  1072,  1078,  1080,   430,  1040,  1086,  1040,  1040,  1085,
    1040,  1038,  1038,  1040,  1084,  1040,  1042,  1062,   180,   331,
     751,  1090,  1138,   388,  1135,  1135,   207,  1032,   299,   754,
    1053,   758,   180,   331,   762,   314,   405,   774,   775,  1140,
    1028,   206,   256,  1020,  1021,  1022,  1024,   415,   789,   157,
     995,   996,   995,   995,   995,  1062,  1042,  1062,   803,    21,
     394,   398,   811,   812,  1029,   128,   814,   427,   806,   808,
     427,   807,  1072,   108,   824,  1051,   829,     9,    12,    15,
      16,   244,   245,   262,   263,   836,   840,   165,  1066,     9,
      55,   167,   216,   400,   854,   855,   856,   850,   848,   931,
    1098,  1123,   393,  1059,  1042,  1062,   356,   874,   727,   728,
    1027,   884,   885,  1071,  1051,     8,    34,   991,  1127,  1068,
     203,   888,   900,  1140,   908,  1104,  1071,   908,   393,   393,
     505,   143,   394,   398,  1062,    48,   211,   938,  1062,  1062,
     362,  1062,  1071,   173,  1042,  1062,  1066,  1106,   203,   968,
    1071,   153,   157,   980,     9,   985,  1051,   900,   116,   270,
    1054,   186,   665,   224,   225,   671,   430,   613,    30,    32,
      35,    43,    44,    45,    63,   152,   170,   173,   174,   187,
     224,   233,   266,   280,   304,   328,   333,   347,   393,   404,
     423,   443,   624,   625,   627,   637,   640,   642,   702,   705,
    1123,   631,   632,  1072,  1078,  1080,   446,  1040,  1040,  1040,
    1040,  1040,  1040,   446,  1040,   355,  1129,  1119,  1123,   994,
     996,   435,   434,  1066,   994,   211,    30,    32,    35,    45,
     170,   174,   187,   233,   280,   304,   328,   333,   343,   347,
     404,   414,   740,   741,   994,   260,  1121,  1121,  1121,   738,
     737,   227,  1065,  1072,   446,  1071,   449,   446,  1039,   446,
     446,  1039,   446,   446,   446,   446,  1039,   446,   446,   363,
    1000,  1001,  1042,  1060,   331,   393,  1051,   759,   760,   761,
    1106,  1071,  1071,   157,   279,   763,   981,  1112,   231,   251,
    1000,  1023,  1025,   125,   785,  1024,    91,   295,   430,  1049,
     429,   790,  1140,   997,   255,   998,   180,  1000,   180,    17,
     390,   813,   277,   811,   727,  1123,   727,  1138,   321,   837,
    1138,   393,    48,   855,   857,  1066,     9,    55,   216,   400,
     851,   852,  1066,   932,  1099,   193,   275,  1124,    27,   109,
     633,  1059,  1000,   180,  1140,  1046,   132,   880,   729,     8,
     173,   888,  1071,   120,   253,  1010,  1011,  1013,  1020,   231,
     251,   427,   120,   427,   910,   911,  1066,  1065,  1062,  1115,
    1020,   948,  1140,  1071,  1000,   180,   393,     9,   966,   967,
    1088,   969,  1071,   948,   969,   297,   983,   298,   990,   991,
     242,   309,   311,   551,  1115,   167,   666,  1076,   674,  1115,
    1121,   147,   149,  1115,  1069,  1121,  1076,  1071,  1071,  1055,
     195,   634,   633,   446,  1138,  1055,   998,   994,  1115,  1115,
     115,   413,   741,  1068,  1068,  1068,  1081,  1094,   446,  1040,
    1055,  1081,  1081,  1040,  1081,  1081,  1081,   216,   400,  1081,
    1081,  1002,   258,  1003,  1000,  1060,   760,   269,   715,    82,
     315,   424,   255,   257,   765,   982,   764,   319,   334,   727,
     727,    32,    35,    43,    44,    45,   152,   170,   187,   233,
     280,   333,   343,   404,   791,   792,   995,   259,   727,   999,
    1042,  1043,  1042,  1043,   812,  1028,   809,  1071,   119,   830,
     424,   838,   839,   840,   104,   841,   424,  1067,  1071,  1077,
    1066,    48,   859,   852,   169,   859,   928,  1115,   275,  1117,
    1042,   561,   875,  1140,   730,   885,  1062,   192,   889,  1140,
    1012,  1014,   135,   897,  1013,   136,   901,   231,  1028,   909,
    1027,   910,   252,   939,  1092,   138,   940,   279,  1005,  1006,
     290,  1094,  1042,  1067,   274,  1066,   107,   970,   384,   972,
    1123,   148,   254,   992,  1015,  1016,  1018,  1021,     7,  1100,
     551,  1076,   110,   213,   667,    64,    63,    64,   185,   224,
     225,   249,   293,   366,   380,   403,   425,   443,   624,   625,
     627,   628,   637,   640,   642,   675,   676,   678,   679,   680,
     681,   683,   684,   685,   686,   690,   691,   436,  1070,  1071,
    1076,  1115,  1070,  1115,  1137,  1106,  1117,   394,   646,  1070,
    1070,  1026,  1106,  1026,  1000,   446,   727,  1004,  1062,   123,
     767,   766,   727,  1115,   147,   149,  1115,   115,   413,   792,
     727,  1000,   318,  1000,   318,   727,   831,   130,   832,   839,
      96,  1110,   859,   859,  1067,   991,   200,   423,   933,  1055,
     930,  1000,   231,   251,    48,   231,   211,   890,   191,   231,
     251,   426,   727,   727,   906,   727,   912,  1062,   178,   184,
     215,   219,  1033,  1034,  1035,  1036,  1037,  1007,   139,   949,
     257,  1008,  1071,  1000,  1000,   967,  1114,    90,   971,  1114,
    1005,   160,   200,   208,   278,   977,  1046,  1017,  1019,   142,
     993,  1018,   283,  1049,  1070,  1115,    87,   214,   668,   261,
    1121,   196,   692,   260,   261,   689,  1101,   185,   427,  1115,
    1122,  1115,  1071,   681,   249,   289,   687,   688,  1076,   238,
     289,   437,   438,   704,   238,   289,   437,   438,   703,   430,
     635,   636,  1115,  1115,  1070,   727,   727,  1070,  1070,  1026,
    1026,  1043,  1043,   727,    48,   859,   396,   860,   297,  1046,
     180,   278,   934,  1073,   334,  1062,  1115,   891,  1010,  1021,
     231,   231,   727,   727,  1135,  1135,   727,  1009,  1071,  1114,
    1071,   141,   973,   727,   727,   224,   225,  1118,  1076,  1115,
    1115,   168,   669,  1115,  1116,  1115,  1027,  1071,   682,  1055,
      86,    87,   110,   284,   285,   325,   326,   677,   173,   283,
    1076,   688,  1070,  1070,   636,  1054,  1077,  1118,  1000,  1000,
    1062,  1062,  1115,  1046,   297,   412,  1071,   134,   892,   274,
     274,   727,  1071,  1076,  1076,  1115,  1076,  1076,  1094,  1062,
     881,  1115,  1027,   150,   150,  1076,    48,   881,  1138,  1138,
    1062
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

       Refer to the stacks through separate pointers, to allow yyoverflow
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

/* Line 1788 of yacc.c  */
#line 757 "parser.y"
    {
	perform_stack = NULL;
	current_statement = NULL;
	next_label_id = 0;
	current_linage = 0;
	current_storage = 0;
	eval_level = 0;
	eval_inc = 0;
	eval_inc2 = 0;
	prog_end = 0;
	depth = 0;
	inspect_keyword = 0;
	check_unreached = 0;
	samearea = 1;
	memset ((char *)eval_check, 0, sizeof(eval_check));
	memset ((char *)term_array, 0, sizeof(term_array));
	linage_file = NULL;
	next_label_list = NULL;
	current_program = cb_build_program (NULL, 0);
	cb_build_registers ();
	current_program->flag_main = cb_flag_main;
  }
    break;

  case 3:

/* Line 1788 of yacc.c  */
#line 781 "parser.y"
    {
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
	if (depth > 1) {
		cb_error (_("Multiple PROGRAM-ID's without matching END PROGRAM"));
	}
	if (errorcount > 0) {
		YYABORT;
	}
	if (!current_program->entry_list) {
		emit_entry (current_program->program_id, 0, NULL);
	}
  }
    break;

  case 8:

/* Line 1788 of yacc.c  */
#line 810 "parser.y"
    { cb_validate_program_environment (current_program); }
    break;

  case 9:

/* Line 1788 of yacc.c  */
#line 811 "parser.y"
    { cb_validate_program_data (current_program); }
    break;

  case 11:

/* Line 1788 of yacc.c  */
#line 819 "parser.y"
    { cb_validate_program_environment (current_program); }
    break;

  case 12:

/* Line 1788 of yacc.c  */
#line 820 "parser.y"
    { cb_validate_program_data (current_program); }
    break;

  case 14:

/* Line 1788 of yacc.c  */
#line 828 "parser.y"
    { cb_validate_program_environment (current_program); }
    break;

  case 15:

/* Line 1788 of yacc.c  */
#line 829 "parser.y"
    { cb_validate_program_data (current_program); }
    break;

  case 21:

/* Line 1788 of yacc.c  */
#line 841 "parser.y"
    {
	char			*s;

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

  case 22:

/* Line 1788 of yacc.c  */
#line 865 "parser.y"
    {
	char			*s;

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

/* Line 1788 of yacc.c  */
#line 889 "parser.y"
    {
	char			*s;

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

/* Line 1788 of yacc.c  */
#line 918 "parser.y"
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
		perform_stack = NULL;
		current_statement = NULL;
		next_label_id = 0;
		current_linage = 0;
		current_storage = 0;
		eval_level = 0;
		inspect_keyword = 0;
		check_unreached = 0;
		eval_inc = 0;
		eval_inc2 = 0;
		samearea = 1;
		memset ((char *)eval_check, 0, sizeof(eval_check));
		memset ((char *)term_array, 0, sizeof(term_array));
		linage_file = NULL;
		next_label_list = NULL;
		current_program = cb_build_program (current_program, depth);
		cb_build_registers ();
	} else {
		prog_end = 1;
	}
	depth++;
	current_program->program_id = cb_build_program_id ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 26:

/* Line 1788 of yacc.c  */
#line 959 "parser.y"
    {
	cb_error (_("FUNCTION-ID is not yet implemented"));
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
		perform_stack = NULL;
		current_statement = NULL;
		next_label_id = 0;
		current_linage = 0;
		current_storage = 0;
		eval_level = 0;
		inspect_keyword = 0;
		check_unreached = 0;
		eval_inc = 0;
		eval_inc2 = 0;
		samearea = 1;
		memset ((char *)eval_check, 0, sizeof(eval_check));
		memset ((char *)term_array, 0, sizeof(term_array));
		linage_file = NULL;
		next_label_list = NULL;
		current_program = cb_build_program (current_program, depth);
		cb_build_registers ();
	} else {
		prog_end = 1;
	}
	depth++;
	current_program->program_id = cb_build_program_id ((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	current_program->prog_type = CB_FUNCTION_TYPE;
	current_program->flag_recursive = 1;
	current_program->flag_initial = 1;
  }
    break;

  case 29:

/* Line 1788 of yacc.c  */
#line 1007 "parser.y"
    { (yyval) = NULL; }
    break;

  case 30:

/* Line 1788 of yacc.c  */
#line 1008 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 33:

/* Line 1788 of yacc.c  */
#line 1017 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a nested program"));
	}
	current_program->flag_common = 1;
  }
    break;

  case 34:

/* Line 1788 of yacc.c  */
#line 1024 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a nested program"));
	}
	current_program->flag_common = 1;
  }
    break;

  case 36:

/* Line 1788 of yacc.c  */
#line 1035 "parser.y"
    {
	current_program->flag_initial = 1;
  }
    break;

  case 37:

/* Line 1788 of yacc.c  */
#line 1039 "parser.y"
    {
	current_program->flag_recursive = 1;
	current_program->flag_initial = 1;
  }
    break;

  case 41:

/* Line 1788 of yacc.c  */
#line 1064 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  }
    break;

  case 53:

/* Line 1788 of yacc.c  */
#line 1099 "parser.y"
    {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
  }
    break;

  case 54:

/* Line 1788 of yacc.c  */
#line 1105 "parser.y"
    { }
    break;

  case 65:

/* Line 1788 of yacc.c  */
#line 1136 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  }
    break;

  case 68:

/* Line 1788 of yacc.c  */
#line 1148 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(4) - (4)]);
  }
    break;

  case 69:

/* Line 1788 of yacc.c  */
#line 1155 "parser.y"
    {
	/* Ignore */
  }
    break;

  case 75:

/* Line 1788 of yacc.c  */
#line 1180 "parser.y"
    {
	current_program->function_spec_list = (yyvsp[(2) - (3)]);
  }
    break;

  case 76:

/* Line 1788 of yacc.c  */
#line 1184 "parser.y"
    {
	functions_are_all = 1;
  }
    break;

  case 77:

/* Line 1788 of yacc.c  */
#line 1190 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 78:

/* Line 1788 of yacc.c  */
#line 1192 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 95:

/* Line 1788 of yacc.c  */
#line 1232 "parser.y"
    {
	save_tree_1 = lookup_system_name (CB_NAME ((yyvsp[(1) - (3)])));
	if (save_tree_1 == cb_error_node) {
		cb_error_x ((yyvsp[(1) - (3)]), _("Unknown system-name '%s'"), CB_NAME ((yyvsp[(1) - (3)])));
	} else if (CB_SYSTEM_NAME(save_tree_1)->token != CB_DEVICE_CONSOLE) {
		cb_error_x (save_tree_1, _("Invalid CRT clause"));
	}
	/* current_program->flag_screen = 1; */
  }
    break;

  case 96:

/* Line 1788 of yacc.c  */
#line 1242 "parser.y"
    {
	save_tree_1 = lookup_system_name (CB_NAME ((yyvsp[(1) - (3)])));
	if (save_tree_1 == cb_error_node) {
		cb_error_x ((yyvsp[(1) - (3)]), _("Unknown system-name '%s'"), CB_NAME ((yyvsp[(1) - (3)])));
	} else {
		cb_define ((yyvsp[(3) - (3)]), save_tree_1);
	}
	save_tree_2 = (yyvsp[(3) - (3)]);
  }
    break;

  case 99:

/* Line 1788 of yacc.c  */
#line 1257 "parser.y"
    {
	cb_define_switch_name ((yyvsp[(5) - (5)]), save_tree_1, (yyvsp[(2) - (5)]), save_tree_2);
  }
    break;

  case 100:

/* Line 1788 of yacc.c  */
#line 1263 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 101:

/* Line 1788 of yacc.c  */
#line 1264 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 102:

/* Line 1788 of yacc.c  */
#line 1272 "parser.y"
    {
	save_tree_1 = (yyvsp[(2) - (2)]);
  }
    break;

  case 103:

/* Line 1788 of yacc.c  */
#line 1276 "parser.y"
    {
	current_program->alphabet_name_list =
		cb_list_add (current_program->alphabet_name_list, (yyvsp[(5) - (5)]));
  }
    break;

  case 104:

/* Line 1788 of yacc.c  */
#line 1283 "parser.y"
    { (yyval) = cb_build_alphabet_name (save_tree_1, CB_ALPHABET_NATIVE); }
    break;

  case 105:

/* Line 1788 of yacc.c  */
#line 1284 "parser.y"
    { (yyval) = cb_build_alphabet_name (save_tree_1, CB_ALPHABET_STANDARD_1); }
    break;

  case 106:

/* Line 1788 of yacc.c  */
#line 1285 "parser.y"
    { (yyval) = cb_build_alphabet_name (save_tree_1, CB_ALPHABET_STANDARD_2); }
    break;

  case 107:

/* Line 1788 of yacc.c  */
#line 1286 "parser.y"
    { (yyval) = cb_build_alphabet_name (save_tree_1, CB_ALPHABET_EBCDIC); }
    break;

  case 108:

/* Line 1788 of yacc.c  */
#line 1288 "parser.y"
    {
	(yyval) = cb_build_alphabet_name (save_tree_1, CB_ALPHABET_CUSTOM);
	CB_ALPHABET_NAME ((yyval))->custom_list = (yyvsp[(1) - (1)]);
  }
    break;

  case 109:

/* Line 1788 of yacc.c  */
#line 1295 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 110:

/* Line 1788 of yacc.c  */
#line 1297 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 111:

/* Line 1788 of yacc.c  */
#line 1301 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 112:

/* Line 1788 of yacc.c  */
#line 1302 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 113:

/* Line 1788 of yacc.c  */
#line 1304 "parser.y"
    {
	(yyval) = cb_list_init ((yyvsp[(1) - (2)]));
	save_tree_2 = (yyval);
  }
    break;

  case 114:

/* Line 1788 of yacc.c  */
#line 1309 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  }
    break;

  case 117:

/* Line 1788 of yacc.c  */
#line 1320 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 118:

/* Line 1788 of yacc.c  */
#line 1321 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 119:

/* Line 1788 of yacc.c  */
#line 1322 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 120:

/* Line 1788 of yacc.c  */
#line 1323 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 121:

/* Line 1788 of yacc.c  */
#line 1324 "parser.y"
    { (yyval) = cb_norm_high; }
    break;

  case 122:

/* Line 1788 of yacc.c  */
#line 1325 "parser.y"
    { (yyval) = cb_norm_low; }
    break;

  case 123:

/* Line 1788 of yacc.c  */
#line 1329 "parser.y"
    { cb_list_add (save_tree_2, (yyvsp[(1) - (1)])); }
    break;

  case 124:

/* Line 1788 of yacc.c  */
#line 1330 "parser.y"
    { cb_list_add (save_tree_2, cb_space); }
    break;

  case 125:

/* Line 1788 of yacc.c  */
#line 1331 "parser.y"
    { cb_list_add (save_tree_2, cb_zero); }
    break;

  case 126:

/* Line 1788 of yacc.c  */
#line 1332 "parser.y"
    { cb_list_add (save_tree_2, cb_quote); }
    break;

  case 127:

/* Line 1788 of yacc.c  */
#line 1333 "parser.y"
    { cb_list_add (save_tree_2, cb_norm_high); }
    break;

  case 128:

/* Line 1788 of yacc.c  */
#line 1334 "parser.y"
    { cb_list_add (save_tree_2, cb_norm_low); }
    break;

  case 129:

/* Line 1788 of yacc.c  */
#line 1342 "parser.y"
    {
	if ((yyvsp[(3) - (3)])) {
		current_program->symbolic_list =
			cb_list_add (current_program->symbolic_list, (yyvsp[(3) - (3)]));
	}
	PENDING ("SYMBOLIC CHARACTERS");
  }
    break;

  case 130:

/* Line 1788 of yacc.c  */
#line 1353 "parser.y"
    {
	if (cb_list_length ((yyvsp[(1) - (3)])) != cb_list_length ((yyvsp[(3) - (3)]))) {
		cb_error (_("Invalid SYMBOLIC clause"));
		(yyval) = NULL;
	} else {
		(yyval) = NULL;
	}
  }
    break;

  case 131:

/* Line 1788 of yacc.c  */
#line 1364 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 132:

/* Line 1788 of yacc.c  */
#line 1365 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 133:

/* Line 1788 of yacc.c  */
#line 1369 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 134:

/* Line 1788 of yacc.c  */
#line 1370 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 135:

/* Line 1788 of yacc.c  */
#line 1378 "parser.y"
    {
	current_program->class_name_list =
			cb_list_add (current_program->class_name_list,
			cb_build_class_name ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])));
  }
    break;

  case 136:

/* Line 1788 of yacc.c  */
#line 1386 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 137:

/* Line 1788 of yacc.c  */
#line 1387 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 138:

/* Line 1788 of yacc.c  */
#line 1391 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 139:

/* Line 1788 of yacc.c  */
#line 1393 "parser.y"
    {
	/* if (CB_LITERAL ($1)->data[0] < CB_LITERAL ($3)->data[0]) */
	if (literal_value ((yyvsp[(1) - (3)])) < literal_value ((yyvsp[(3) - (3)]))) {
		(yyval) = cb_build_pair ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	} else {
		(yyval) = cb_build_pair ((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
	}
  }
    break;

  case 140:

/* Line 1788 of yacc.c  */
#line 1407 "parser.y"
    {
	cb_tree	l;

	l = cb_build_locale_name ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
	if (l != cb_error_node) {
		current_program->locale_list =
			cb_list_add (current_program->locale_list, l);
	}
  }
    break;

  case 141:

/* Line 1788 of yacc.c  */
#line 1422 "parser.y"
    {
	unsigned char *s = CB_LITERAL ((yyvsp[(4) - (4)]))->data;

	if (CB_LITERAL ((yyvsp[(4) - (4)]))->size != 1) {
		cb_error_x ((yyvsp[(4) - (4)]), _("Invalid currency sign '%s'"), s);
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
	case 'a':
	case 'A':
	case 'b':
	case 'B':
	case 'c':
	case 'C':
	case 'd':
	case 'D':
	case 'e':
	case 'E':
	case 'n':
	case 'N':
	case 'p':
	case 'P':
	case 'r':
	case 'R':
	case 's':
	case 'S':
	case 'v':
	case 'V':
	case 'x':
	case 'X':
	case 'z':
	case 'Z':
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
	case '"':
	case ' ':
		cb_error_x ((yyvsp[(4) - (4)]), _("Invalid currency sign '%s'"), s);
		break;
	default:
		break;
	}
	current_program->currency_symbol = s[0];
  }
    break;

  case 142:

/* Line 1788 of yacc.c  */
#line 1489 "parser.y"
    {
	current_program->decimal_point = ',';
	current_program->numeric_separator = '.';
  }
    break;

  case 143:

/* Line 1788 of yacc.c  */
#line 1499 "parser.y"
    { current_program->cursor_pos = (yyvsp[(3) - (3)]); }
    break;

  case 144:

/* Line 1788 of yacc.c  */
#line 1506 "parser.y"
    { current_program->crt_status = (yyvsp[(4) - (4)]); }
    break;

  case 145:

/* Line 1788 of yacc.c  */
#line 1513 "parser.y"
    {  PENDING ("SCREEN CONTROL"); }
    break;

  case 146:

/* Line 1788 of yacc.c  */
#line 1519 "parser.y"
    {  PENDING ("EVENT STATUS"); }
    break;

  case 149:

/* Line 1788 of yacc.c  */
#line 1531 "parser.y"
    {
	/* hack for MF compatibility */
	if (cb_relaxed_syntax_check) {
		cb_warning (_("INPUT-OUTPUT SECTION header missing - assumed"));
	} else {
		cb_error (_("INPUT-OUTPUT SECTION header missing"));
	}
  }
    break;

  case 151:

/* Line 1788 of yacc.c  */
#line 1540 "parser.y"
    {
	/* hack for MF compatibility */
	if (cb_relaxed_syntax_check) {
		cb_warning (_("INPUT-OUTPUT SECTION header missing - assumed"));
	} else {
		cb_error (_("INPUT-OUTPUT SECTION header missing"));
	}
  }
    break;

  case 157:

/* Line 1788 of yacc.c  */
#line 1565 "parser.y"
    {
	organized_seen = 0;
	if ((yyvsp[(3) - (3)]) == cb_error_node) {
		YYERROR;
	}

	/* build new file */
	current_file = build_file ((yyvsp[(3) - (3)]));
	current_file->optional = CB_INTEGER ((yyvsp[(2) - (3)]))->val;

	/* register the file */
	current_program->file_list =
		cb_cons (CB_TREE (current_file), current_program->file_list);
  }
    break;

  case 158:

/* Line 1788 of yacc.c  */
#line 1580 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  }
    break;

  case 174:

/* Line 1788 of yacc.c  */
#line 1610 "parser.y"
    {
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  }
    break;

  case 175:

/* Line 1788 of yacc.c  */
#line 1614 "parser.y"
    {
	current_file->fileid_assign = 1;
  }
    break;

  case 178:

/* Line 1788 of yacc.c  */
#line 1621 "parser.y"
    { current_file->organization = COB_ORG_LINE_SEQUENTIAL; }
    break;

  case 180:

/* Line 1788 of yacc.c  */
#line 1626 "parser.y"
    {
	current_file->external_assign = 1;
  }
    break;

  case 183:

/* Line 1788 of yacc.c  */
#line 1635 "parser.y"
    {
	const char	*s;

	s = "$#@DUMMY@#$";
	(yyval) = cb_build_alphanumeric_literal ((unsigned char *)s, strlen (s));
  }
    break;

  case 186:

/* Line 1788 of yacc.c  */
#line 1652 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; }
    break;

  case 187:

/* Line 1788 of yacc.c  */
#line 1653 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; }
    break;

  case 188:

/* Line 1788 of yacc.c  */
#line 1654 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; }
    break;

  case 189:

/* Line 1788 of yacc.c  */
#line 1662 "parser.y"
    {
	struct cb_alt_key *p;
	struct cb_alt_key *l;

	p = cobc_malloc (sizeof (struct cb_alt_key));
	p->key = (yyvsp[(5) - (6)]);
	p->duplicates = CB_INTEGER ((yyvsp[(6) - (6)]))->val;
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
    break;

  case 190:

/* Line 1788 of yacc.c  */
#line 1687 "parser.y"
    {
	PENDING ("COLLATING SEQUENCE");
  }
    break;

  case 191:

/* Line 1788 of yacc.c  */
#line 1697 "parser.y"
    {
	current_file->file_status = (yyvsp[(4) - (5)]);
	if ((yyvsp[(5) - (5)])) {
		PENDING ("2nd FILE STATUS");
	}
  }
    break;

  case 196:

/* Line 1788 of yacc.c  */
#line 1718 "parser.y"
    { current_file->lock_mode = COB_LOCK_MANUAL; }
    break;

  case 197:

/* Line 1788 of yacc.c  */
#line 1719 "parser.y"
    { current_file->lock_mode = COB_LOCK_AUTOMATIC; }
    break;

  case 198:

/* Line 1788 of yacc.c  */
#line 1720 "parser.y"
    { current_file->lock_mode = COB_LOCK_EXCLUSIVE; }
    break;

  case 201:

/* Line 1788 of yacc.c  */
#line 1726 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  }
    break;

  case 202:

/* Line 1788 of yacc.c  */
#line 1729 "parser.y"
    { PENDING ("WITH ROLLBACK"); }
    break;

  case 207:

/* Line 1788 of yacc.c  */
#line 1746 "parser.y"
    {
	if (organized_seen) {
		cb_error (_("Invalid or duplicate ORGANIZED clause"));
	} else {
		current_file->organization = COB_ORG_INDEXED;
		organized_seen = 1;
	}
  }
    break;

  case 208:

/* Line 1788 of yacc.c  */
#line 1755 "parser.y"
    {
	if (organized_seen) {
		cb_error (_("Invalid or duplicate ORGANIZED clause"));
	} else {
		current_file->organization = COB_ORG_SEQUENTIAL;
		organized_seen = 1;
	}
  }
    break;

  case 209:

/* Line 1788 of yacc.c  */
#line 1764 "parser.y"
    {
	if (organized_seen) {
		cb_error (_("Invalid or duplicate ORGANIZED clause"));
	} else {
		current_file->organization = cb_default_organization;
		organized_seen = 1;
	}
  }
    break;

  case 210:

/* Line 1788 of yacc.c  */
#line 1773 "parser.y"
    {
	if (organized_seen) {
		cb_error (_("Invalid or duplicate ORGANIZED clause"));
	} else {
		current_file->organization = COB_ORG_RELATIVE;
		organized_seen = 1;
	}
  }
    break;

  case 211:

/* Line 1788 of yacc.c  */
#line 1782 "parser.y"
    {
	if (organized_seen) {
		cb_error (_("Invalid or duplicate ORGANIZED clause"));
	} else {
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		organized_seen = 1;
	}
  }
    break;

  case 212:

/* Line 1788 of yacc.c  */
#line 1797 "parser.y"
    {
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  }
    break;

  case 213:

/* Line 1788 of yacc.c  */
#line 1806 "parser.y"
    { /* ignored */ }
    break;

  case 214:

/* Line 1788 of yacc.c  */
#line 1814 "parser.y"
    {
	current_file->key = (yyvsp[(4) - (4)]);
  }
    break;

  case 215:

/* Line 1788 of yacc.c  */
#line 1820 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 216:

/* Line 1788 of yacc.c  */
#line 1821 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 217:

/* Line 1788 of yacc.c  */
#line 1822 "parser.y"
    { PENDING ("SPLIT KEYS"); }
    break;

  case 218:

/* Line 1788 of yacc.c  */
#line 1828 "parser.y"
    { current_file->key = (yyvsp[(4) - (4)]); }
    break;

  case 219:

/* Line 1788 of yacc.c  */
#line 1835 "parser.y"
    { /* ignored */ }
    break;

  case 220:

/* Line 1788 of yacc.c  */
#line 1842 "parser.y"
    { current_file->sharing = (yyvsp[(3) - (3)]); }
    break;

  case 221:

/* Line 1788 of yacc.c  */
#line 1846 "parser.y"
    { (yyval) = NULL; PENDING ("SHARING ALL OTHER"); }
    break;

  case 222:

/* Line 1788 of yacc.c  */
#line 1847 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 223:

/* Line 1788 of yacc.c  */
#line 1848 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 232:

/* Line 1788 of yacc.c  */
#line 1878 "parser.y"
    {
	cb_tree l;

	switch (CB_INTEGER ((yyvsp[(2) - (5)]))->val) {
	case 0:
		/* SAME AREA */
		break;
	case 1:
		/* SAME RECORD */
		for (l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN (l)) {
			if (CB_VALUE (l) != cb_error_node) {
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

  case 233:

/* Line 1788 of yacc.c  */
#line 1902 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 234:

/* Line 1788 of yacc.c  */
#line 1903 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 235:

/* Line 1788 of yacc.c  */
#line 1904 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 236:

/* Line 1788 of yacc.c  */
#line 1905 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 237:

/* Line 1788 of yacc.c  */
#line 1912 "parser.y"
    {
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
  }
    break;

  case 240:

/* Line 1788 of yacc.c  */
#line 1923 "parser.y"
    { }
    break;

  case 246:

/* Line 1788 of yacc.c  */
#line 1951 "parser.y"
    { current_storage = CB_STORAGE_FILE; }
    break;

  case 248:

/* Line 1788 of yacc.c  */
#line 1954 "parser.y"
    {
	/* hack for MF compatibility */
	if (cb_relaxed_syntax_check) {
		cb_warning (_("FILE SECTION header missing - assumed"));
	} else {
		cb_error (_("FILE SECTION header missing"));
	}
	current_storage = CB_STORAGE_FILE;
  }
    break;

  case 252:

/* Line 1788 of yacc.c  */
#line 1973 "parser.y"
    {
	if ((yyvsp[(3) - (3)]) && (yyvsp[(3) - (3)]) != cb_error_node) {
		finalize_file (current_file, CB_FIELD ((yyvsp[(3) - (3)])));
	} else {
		cb_error (_("RECORD description missing or invalid"));
	}
  }
    break;

  case 253:

/* Line 1788 of yacc.c  */
#line 1985 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) && (yyvsp[(2) - (2)]) != cb_error_node) {
		finalize_file (current_file, CB_FIELD ((yyvsp[(2) - (2)])));
	} else {
		cb_error (_("RECORD description missing or invalid"));
	}
  }
    break;

  case 255:

/* Line 1788 of yacc.c  */
#line 1996 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 256:

/* Line 1788 of yacc.c  */
#line 1997 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 257:

/* Line 1788 of yacc.c  */
#line 2007 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == cb_error_node) {
		YYERROR;
	}

	current_file = CB_FILE (cb_ref ((yyvsp[(1) - (1)])));
	if ((yyvsp[(0) - (1)]) == cb_int1) {
		current_file->organization = COB_ORG_SORT;
	}
  }
    break;

  case 258:

/* Line 1788 of yacc.c  */
#line 2018 "parser.y"
    {
	/* Shut up bison */
	dummy_tree = (yyvsp[(2) - (4)]);
  }
    break;

  case 261:

/* Line 1788 of yacc.c  */
#line 2030 "parser.y"
    {
	if (current_file->global) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
	current_file->external = 1;
  }
    break;

  case 262:

/* Line 1788 of yacc.c  */
#line 2037 "parser.y"
    {
	if (current_file->external) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
	current_file->global = 1;
  }
    break;

  case 272:

/* Line 1788 of yacc.c  */
#line 2059 "parser.y"
    { /* ignored */ }
    break;

  case 276:

/* Line 1788 of yacc.c  */
#line 2069 "parser.y"
    {
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
	} else {
		current_file->record_max = cb_get_int ((yyvsp[(3) - (4)]));
		if (current_file->record_max < 1)  {
			current_file->record_max = 1;
			cb_error (_("RECORD clause invalid"));
		}
	}
  }
    break;

  case 277:

/* Line 1788 of yacc.c  */
#line 2081 "parser.y"
    {
	int	error_ind = 0;

	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
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
		if (current_file->record_max <= current_file->record_min)  {
			error_ind = 1;
		}
		if (error_ind) {
			cb_error (_("RECORD clause invalid"));
		}
	}
  }
    break;

  case 278:

/* Line 1788 of yacc.c  */
#line 2107 "parser.y"
    {
	int	error_ind = 0;

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
	if (((yyvsp[(6) - (9)]) || (yyvsp[(7) - (9)])) && current_file->record_max <= current_file->record_min)  {
		error_ind = 1;
	}
	if (error_ind) {
		cb_error (_("RECORD clause invalid"));
	}
  }
    break;

  case 280:

/* Line 1788 of yacc.c  */
#line 2131 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 281:

/* Line 1788 of yacc.c  */
#line 2137 "parser.y"
    { (yyval) = NULL; }
    break;

  case 282:

/* Line 1788 of yacc.c  */
#line 2138 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 283:

/* Line 1788 of yacc.c  */
#line 2142 "parser.y"
    { (yyval) = NULL; }
    break;

  case 284:

/* Line 1788 of yacc.c  */
#line 2143 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 285:

/* Line 1788 of yacc.c  */
#line 2151 "parser.y"
    {
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  }
    break;

  case 288:

/* Line 1788 of yacc.c  */
#line 2166 "parser.y"
    {
	cb_verify (cb_value_of_clause, "VALUE OF");
  }
    break;

  case 289:

/* Line 1788 of yacc.c  */
#line 2170 "parser.y"
    {
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  }
    break;

  case 292:

/* Line 1788 of yacc.c  */
#line 2186 "parser.y"
    {
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  }
    break;

  case 293:

/* Line 1788 of yacc.c  */
#line 2197 "parser.y"
    {
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL
	    && current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("LINAGE clause with wrong file type"));
		(yyval) = cb_error_node;
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

  case 299:

/* Line 1788 of yacc.c  */
#line 2225 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (5)]);
  }
    break;

  case 300:

/* Line 1788 of yacc.c  */
#line 2232 "parser.y"
    {
	current_file->lattop = (yyvsp[(3) - (4)]);
  }
    break;

  case 301:

/* Line 1788 of yacc.c  */
#line 2239 "parser.y"
    {
	current_file->latbot = (yyvsp[(3) - (3)]);
  }
    break;

  case 302:

/* Line 1788 of yacc.c  */
#line 2248 "parser.y"
    { /* ignore */ }
    break;

  case 303:

/* Line 1788 of yacc.c  */
#line 2256 "parser.y"
    {
	if ((yyvsp[(3) - (3)]) != cb_error_node) {
		cb_tree x;

		x = cb_ref ((yyvsp[(3) - (3)]));
		if (!CB_ALPHABET_NAME_P (x)) {
			cb_error_x ((yyvsp[(3) - (3)]), _("Alphabet-name is expected '%s'"), cb_name ((yyvsp[(3) - (3)])));
		} else if (CB_ALPHABET_NAME (x)->custom_list) {
			PENDING ("CODE-SET");
		}
	}
  }
    break;

  case 304:

/* Line 1788 of yacc.c  */
#line 2274 "parser.y"
    {
	cb_warning (_("file descriptor REPORT IS"));
  }
    break;

  case 305:

/* Line 1788 of yacc.c  */
#line 2278 "parser.y"
    {
	cb_warning (_("file descriptor REPORTS ARE"));
  }
    break;

  case 307:

/* Line 1788 of yacc.c  */
#line 2289 "parser.y"
    { current_storage = CB_STORAGE_WORKING; }
    break;

  case 308:

/* Line 1788 of yacc.c  */
#line 2291 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->working_storage =
			cb_field_add (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  }
    break;

  case 309:

/* Line 1788 of yacc.c  */
#line 2300 "parser.y"
    { (yyval) = NULL; }
    break;

  case 310:

/* Line 1788 of yacc.c  */
#line 2301 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 311:

/* Line 1788 of yacc.c  */
#line 2305 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 312:

/* Line 1788 of yacc.c  */
#line 2311 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  }
    break;

  case 317:

/* Line 1788 of yacc.c  */
#line 2331 "parser.y"
    {
	cb_tree x;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage, current_file);
	if (x == cb_error_node) {
		YYERROR;
	} else {
		current_field = CB_FIELD (x);
	}
  }
    break;

  case 318:

/* Line 1788 of yacc.c  */
#line 2342 "parser.y"
    {
	if (!qualifier && (current_field->level == 88 ||
		current_field->level == 66 || current_field->flag_item_78)) {
		cb_error (_("Item requires a data name"));
	}
	if (current_field->level == 88) {
		cb_validate_88_item (current_field);
	}
	if (current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item (current_field);
	}
	if (!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 320:

/* Line 1788 of yacc.c  */
#line 2366 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 321:

/* Line 1788 of yacc.c  */
#line 2372 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  }
    break;

  case 322:

/* Line 1788 of yacc.c  */
#line 2378 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 323:

/* Line 1788 of yacc.c  */
#line 2387 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  }
    break;

  case 325:

/* Line 1788 of yacc.c  */
#line 2396 "parser.y"
    {
	current_field->flag_is_global = 1;
	cb_error (_("CONSTANT with GLOBAL clause is not yet supported"));
  }
    break;

  case 326:

/* Line 1788 of yacc.c  */
#line 2403 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 327:

/* Line 1788 of yacc.c  */
#line 2404 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 328:

/* Line 1788 of yacc.c  */
#line 2405 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); }
    break;

  case 329:

/* Line 1788 of yacc.c  */
#line 2410 "parser.y"
    {
	cb_tree x;
	int	level;

	level = cb_get_level ((yyvsp[(1) - (6)]));
	if (level && level != 1) {
		cb_error (_("CONSTANT item not at 01 level"));
	}
	x = cb_build_constant ((yyvsp[(2) - (6)]), (yyvsp[(6) - (6)]));
	CB_FIELD (x)->flag_item_78 = 1;
	CB_FIELD (x)->level = 1;
	cb_needs_01 = 1;
	/* Ignore return value */
	cb_validate_78_item (CB_FIELD (x));
  }
    break;

  case 330:

/* Line 1788 of yacc.c  */
#line 2429 "parser.y"
    {
	/* required to check redefines */
	(yyval) = NULL;
  }
    break;

  case 331:

/* Line 1788 of yacc.c  */
#line 2435 "parser.y"
    {
	/* required to check redefines */
	(yyval) = cb_true;
  }
    break;

  case 346:

/* Line 1788 of yacc.c  */
#line 2463 "parser.y"
    {
	if ((yyvsp[(0) - (2)]) != NULL) {
		/* hack for MF compatibility */
		if (cb_relaxed_syntax_check) {
			cb_warning_x ((yyvsp[(2) - (2)]), _("REDEFINES clause should follow entry-name"));
		} else {
			cb_error_x ((yyvsp[(2) - (2)]), _("REDEFINES clause must follow entry-name"));
		}
	}

	current_field->redefines = cb_resolve_redefines (current_field, (yyvsp[(2) - (2)]));
	if (current_field->redefines == NULL) {
		YYERROR;
	}
  }
    break;

  case 347:

/* Line 1788 of yacc.c  */
#line 2485 "parser.y"
    {
	if (current_storage != CB_STORAGE_WORKING) {
		cb_error (_("EXTERNAL not allowed here"));
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("EXTERNAL only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("EXTERNAL requires a data name"));
	} else if (current_field->flag_is_global) {
		cb_error (_("GLOBAL and EXTERNAL are mutually exclusive"));
	} else if (current_field->flag_item_based) {
		cb_error (_("BASED and EXTERNAL are mutually exclusive"));
	} else if (current_field->redefines) {
		cb_error (_("EXTERNAL and REDEFINES are mutually exclusive"));
	} else {
		current_field->flag_external = 1;
		has_external = 1;
	}
  }
    break;

  case 348:

/* Line 1788 of yacc.c  */
#line 2506 "parser.y"
    { current_field->ename = NULL; }
    break;

  case 349:

/* Line 1788 of yacc.c  */
#line 2508 "parser.y"
    {
	struct cb_field *x;

	x = CB_FIELD(cb_build_field (cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(2) - (2)]))->data))));
	current_field->ename = x->name;
 }
    break;

  case 350:

/* Line 1788 of yacc.c  */
#line 2520 "parser.y"
    {
	if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("GLOBAL only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("GLOBAL requires a data name"));
	} else if (current_field->flag_external) {
		cb_error (_("GLOBAL and EXTERNAL are mutually exclusive"));
	} else if (current_storage == CB_STORAGE_LOCAL) {
		cb_error (_("GLOBAL not allowed here"));
	} else {
		current_field->flag_is_global = 1;
	}
  }
    break;

  case 351:

/* Line 1788 of yacc.c  */
#line 2539 "parser.y"
    { current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)])); }
    break;

  case 354:

/* Line 1788 of yacc.c  */
#line 2551 "parser.y"
    { current_field->usage = CB_USAGE_BINARY; }
    break;

  case 355:

/* Line 1788 of yacc.c  */
#line 2552 "parser.y"
    { current_field->usage = CB_USAGE_BINARY; }
    break;

  case 356:

/* Line 1788 of yacc.c  */
#line 2553 "parser.y"
    { current_field->usage = CB_USAGE_FLOAT; }
    break;

  case 357:

/* Line 1788 of yacc.c  */
#line 2554 "parser.y"
    { current_field->usage = CB_USAGE_DOUBLE; }
    break;

  case 358:

/* Line 1788 of yacc.c  */
#line 2555 "parser.y"
    { current_field->usage = CB_USAGE_PACKED; }
    break;

  case 359:

/* Line 1788 of yacc.c  */
#line 2556 "parser.y"
    { current_field->usage = CB_USAGE_BINARY; }
    break;

  case 360:

/* Line 1788 of yacc.c  */
#line 2557 "parser.y"
    { current_field->usage = CB_USAGE_COMP_5; }
    break;

  case 361:

/* Line 1788 of yacc.c  */
#line 2558 "parser.y"
    { current_field->usage = CB_USAGE_COMP_X; }
    break;

  case 362:

/* Line 1788 of yacc.c  */
#line 2559 "parser.y"
    { current_field->usage = CB_USAGE_DISPLAY; }
    break;

  case 363:

/* Line 1788 of yacc.c  */
#line 2560 "parser.y"
    { current_field->usage = CB_USAGE_INDEX; }
    break;

  case 364:

/* Line 1788 of yacc.c  */
#line 2561 "parser.y"
    { current_field->usage = CB_USAGE_PACKED; }
    break;

  case 365:

/* Line 1788 of yacc.c  */
#line 2563 "parser.y"
    {
	current_field->usage = CB_USAGE_POINTER;
	current_field->flag_is_pointer = 1;
  }
    break;

  case 366:

/* Line 1788 of yacc.c  */
#line 2568 "parser.y"
    {
	current_field->usage = CB_USAGE_PROGRAM_POINTER;
	current_field->flag_is_pointer = 1;
  }
    break;

  case 367:

/* Line 1788 of yacc.c  */
#line 2572 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_SHORT; }
    break;

  case 368:

/* Line 1788 of yacc.c  */
#line 2573 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_INT; }
    break;

  case 369:

/* Line 1788 of yacc.c  */
#line 2574 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_LONG; }
    break;

  case 370:

/* Line 1788 of yacc.c  */
#line 2575 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_SHORT; }
    break;

  case 371:

/* Line 1788 of yacc.c  */
#line 2576 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_INT; }
    break;

  case 372:

/* Line 1788 of yacc.c  */
#line 2577 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_LONG; }
    break;

  case 373:

/* Line 1788 of yacc.c  */
#line 2578 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_CHAR; }
    break;

  case 374:

/* Line 1788 of yacc.c  */
#line 2579 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_CHAR; }
    break;

  case 375:

/* Line 1788 of yacc.c  */
#line 2580 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_CHAR; }
    break;

  case 376:

/* Line 1788 of yacc.c  */
#line 2581 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_SHORT; }
    break;

  case 377:

/* Line 1788 of yacc.c  */
#line 2582 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_SHORT; }
    break;

  case 378:

/* Line 1788 of yacc.c  */
#line 2583 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_SHORT; }
    break;

  case 379:

/* Line 1788 of yacc.c  */
#line 2584 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_INT; }
    break;

  case 380:

/* Line 1788 of yacc.c  */
#line 2585 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_INT; }
    break;

  case 381:

/* Line 1788 of yacc.c  */
#line 2586 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_INT; }
    break;

  case 382:

/* Line 1788 of yacc.c  */
#line 2587 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_LONG; }
    break;

  case 383:

/* Line 1788 of yacc.c  */
#line 2588 "parser.y"
    { current_field->usage = CB_USAGE_UNSIGNED_LONG; }
    break;

  case 384:

/* Line 1788 of yacc.c  */
#line 2589 "parser.y"
    { current_field->usage = CB_USAGE_SIGNED_LONG; }
    break;

  case 385:

/* Line 1788 of yacc.c  */
#line 2591 "parser.y"
    {
	if (sizeof(long) == 4) {
		current_field->usage = CB_USAGE_SIGNED_INT;
	} else {
		current_field->usage = CB_USAGE_SIGNED_LONG;
	}
  }
    break;

  case 386:

/* Line 1788 of yacc.c  */
#line 2599 "parser.y"
    {
	if (sizeof(long) == 4) {
		current_field->usage = CB_USAGE_UNSIGNED_INT;
	} else {
		current_field->usage = CB_USAGE_UNSIGNED_LONG;
	}
  }
    break;

  case 387:

/* Line 1788 of yacc.c  */
#line 2607 "parser.y"
    {
	if (sizeof(long) == 4) {
		current_field->usage = CB_USAGE_SIGNED_INT;
	} else {
		current_field->usage = CB_USAGE_SIGNED_LONG;
	}
  }
    break;

  case 388:

/* Line 1788 of yacc.c  */
#line 2614 "parser.y"
    { PENDING ("USAGE NATIONAL");}
    break;

  case 389:

/* Line 1788 of yacc.c  */
#line 2622 "parser.y"
    {
	current_field->flag_sign_separate = CB_INTEGER ((yyvsp[(3) - (3)]))->val;
	current_field->flag_sign_leading  = 1;
  }
    break;

  case 390:

/* Line 1788 of yacc.c  */
#line 2627 "parser.y"
    {
	current_field->flag_sign_separate = CB_INTEGER ((yyvsp[(3) - (3)]))->val;
	current_field->flag_sign_leading  = 0;
  }
    break;

  case 391:

/* Line 1788 of yacc.c  */
#line 2639 "parser.y"
    {
	if (current_field->occurs_depending && !((yyvsp[(3) - (7)]))) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (7)]) ? cb_get_int ((yyvsp[(2) - (7)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (7)]) ? cb_get_int ((yyvsp[(3) - (7)])) : cb_get_int ((yyvsp[(2) - (7)]));
	current_field->indexes++;
	if (current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error (_("Maximum OCCURS depth exceeded"));
	}
	current_field->flag_occurs = 1;
  }
    break;

  case 392:

/* Line 1788 of yacc.c  */
#line 2654 "parser.y"
    { (yyval) = NULL; }
    break;

  case 393:

/* Line 1788 of yacc.c  */
#line 2655 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 395:

/* Line 1788 of yacc.c  */
#line 2660 "parser.y"
    {
	current_field->occurs_depending = (yyvsp[(3) - (3)]);
  }
    break;

  case 396:

/* Line 1788 of yacc.c  */
#line 2667 "parser.y"
    {
	if ((yyvsp[(1) - (1)])) {
		cb_tree		l;
		struct cb_key	*keys;
		int		i;
		int		nkeys;

		l = (yyvsp[(1) - (1)]);
		nkeys = cb_list_length ((yyvsp[(1) - (1)]));
		keys = cobc_malloc (sizeof (struct cb_key) * nkeys);

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

  case 397:

/* Line 1788 of yacc.c  */
#line 2690 "parser.y"
    { (yyval) = NULL; }
    break;

  case 398:

/* Line 1788 of yacc.c  */
#line 2693 "parser.y"
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

  case 399:

/* Line 1788 of yacc.c  */
#line 2708 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); }
    break;

  case 400:

/* Line 1788 of yacc.c  */
#line 2709 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); }
    break;

  case 402:

/* Line 1788 of yacc.c  */
#line 2714 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  }
    break;

  case 403:

/* Line 1788 of yacc.c  */
#line 2720 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 404:

/* Line 1788 of yacc.c  */
#line 2722 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 405:

/* Line 1788 of yacc.c  */
#line 2727 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1, current_field);
  }
    break;

  case 406:

/* Line 1788 of yacc.c  */
#line 2736 "parser.y"
    { current_field->flag_justified = 1; }
    break;

  case 407:

/* Line 1788 of yacc.c  */
#line 2743 "parser.y"
    { current_field->flag_synchronized = 1; }
    break;

  case 411:

/* Line 1788 of yacc.c  */
#line 2755 "parser.y"
    { current_field->flag_blank_zero = 1; }
    break;

  case 412:

/* Line 1788 of yacc.c  */
#line 2763 "parser.y"
    {
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
	} else {
		current_field->flag_item_based = 1;
	}
  }
    break;

  case 413:

/* Line 1788 of yacc.c  */
#line 2787 "parser.y"
    { current_field->values = (yyvsp[(3) - (3)]); }
    break;

  case 415:

/* Line 1788 of yacc.c  */
#line 2792 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 416:

/* Line 1788 of yacc.c  */
#line 2793 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 417:

/* Line 1788 of yacc.c  */
#line 2797 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 418:

/* Line 1788 of yacc.c  */
#line 2798 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 420:

/* Line 1788 of yacc.c  */
#line 2803 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = cb_list_init ((yyvsp[(3) - (3)]));
  }
    break;

  case 421:

/* Line 1788 of yacc.c  */
#line 2816 "parser.y"
    {
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

  case 422:

/* Line 1788 of yacc.c  */
#line 2828 "parser.y"
    {
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

  case 423:

/* Line 1788 of yacc.c  */
#line 2848 "parser.y"
    {
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY LENGTH are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  }
    break;

  case 425:

/* Line 1788 of yacc.c  */
#line 2863 "parser.y"
    {
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  }
    break;

  case 426:

/* Line 1788 of yacc.c  */
#line 2870 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 428:

/* Line 1788 of yacc.c  */
#line 2883 "parser.y"
    { current_storage = CB_STORAGE_LINKAGE; }
    break;

  case 429:

/* Line 1788 of yacc.c  */
#line 2885 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  }
    break;

  case 431:

/* Line 1788 of yacc.c  */
#line 2898 "parser.y"
    {
	cb_error (_("REPORT SECTION not supported"));
	current_storage = CB_STORAGE_REPORT;
  }
    break;

  case 438:

/* Line 1788 of yacc.c  */
#line 2931 "parser.y"
    {
	cb_warning (_("Report description using defaults"));
  }
    break;

  case 440:

/* Line 1788 of yacc.c  */
#line 2939 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with RD"));
  }
    break;

  case 472:

/* Line 1788 of yacc.c  */
#line 3019 "parser.y"
    { cb_warning (_("looking for Report line TYPE")); }
    break;

  case 523:

/* Line 1788 of yacc.c  */
#line 3124 "parser.y"
    { current_storage = CB_STORAGE_SCREEN; }
    break;

  case 524:

/* Line 1788 of yacc.c  */
#line 3125 "parser.y"
    {
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  }
    break;

  case 525:

/* Line 1788 of yacc.c  */
#line 3131 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	current_program->screen_storage = description_field;
	current_program->flag_screen = 1;
  }
    break;

  case 531:

/* Line 1788 of yacc.c  */
#line 3155 "parser.y"
    {
	cb_tree x;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage, current_file);
	if (x == cb_error_node) {
		YYERROR;
	}

	current_field = CB_FIELD (x);
	if (current_field->parent) {
		current_field->screen_flag |= current_field->parent->screen_flag;
		current_field->screen_foreg = current_field->parent->screen_foreg;
		current_field->screen_backg = current_field->parent->screen_backg;
	}
  }
    break;

  case 532:

/* Line 1788 of yacc.c  */
#line 3171 "parser.y"
    {
	if (!qualifier && (current_field->level == 88 ||
	    current_field->level == 77 || current_field->level == 66 ||
	    current_field->flag_item_78)) {
		cb_error (_("Item requires a data name"));
	}
	if (current_field->level == 88) {
		cb_validate_88_item (current_field);
	}
	if (current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item (current_field);
	}
	if (!description_field) {
		description_field = current_field;
	}
  }
    break;

  case 535:

/* Line 1788 of yacc.c  */
#line 3195 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_BLANK_LINE; }
    break;

  case 536:

/* Line 1788 of yacc.c  */
#line 3196 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_BLANK_SCREEN; }
    break;

  case 537:

/* Line 1788 of yacc.c  */
#line 3197 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_BELL; }
    break;

  case 538:

/* Line 1788 of yacc.c  */
#line 3198 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_BLINK; }
    break;

  case 539:

/* Line 1788 of yacc.c  */
#line 3199 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_ERASE_EOL; }
    break;

  case 540:

/* Line 1788 of yacc.c  */
#line 3200 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_ERASE_EOS; }
    break;

  case 541:

/* Line 1788 of yacc.c  */
#line 3201 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_HIGHLIGHT; }
    break;

  case 542:

/* Line 1788 of yacc.c  */
#line 3202 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_LOWLIGHT; }
    break;

  case 543:

/* Line 1788 of yacc.c  */
#line 3203 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_REVERSE; }
    break;

  case 544:

/* Line 1788 of yacc.c  */
#line 3204 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_UNDERLINE; }
    break;

  case 545:

/* Line 1788 of yacc.c  */
#line 3205 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_OVERLINE; }
    break;

  case 546:

/* Line 1788 of yacc.c  */
#line 3206 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_AUTO; }
    break;

  case 547:

/* Line 1788 of yacc.c  */
#line 3207 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_SECURE; }
    break;

  case 548:

/* Line 1788 of yacc.c  */
#line 3208 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_REQUIRED; }
    break;

  case 549:

/* Line 1788 of yacc.c  */
#line 3209 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_FULL; }
    break;

  case 550:

/* Line 1788 of yacc.c  */
#line 3210 "parser.y"
    { current_field->screen_flag |= COB_SCREEN_PROMPT; }
    break;

  case 551:

/* Line 1788 of yacc.c  */
#line 3212 "parser.y"
    {
	current_field->screen_line = (yyvsp[(5) - (5)]);
  }
    break;

  case 552:

/* Line 1788 of yacc.c  */
#line 3216 "parser.y"
    {
	current_field->screen_column = (yyvsp[(5) - (5)]);
  }
    break;

  case 553:

/* Line 1788 of yacc.c  */
#line 3220 "parser.y"
    {
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  }
    break;

  case 554:

/* Line 1788 of yacc.c  */
#line 3224 "parser.y"
    {
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  }
    break;

  case 562:

/* Line 1788 of yacc.c  */
#line 3235 "parser.y"
    {
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_PROMPT;
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 563:

/* Line 1788 of yacc.c  */
#line 3242 "parser.y"
    {
	current_field->screen_from = (yyvsp[(2) - (2)]);
  }
    break;

  case 564:

/* Line 1788 of yacc.c  */
#line 3246 "parser.y"
    {
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_PROMPT;
	current_field->screen_flag |= COB_SCREEN_INPUT;
  }
    break;

  case 565:

/* Line 1788 of yacc.c  */
#line 3255 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 566:

/* Line 1788 of yacc.c  */
#line 3259 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 567:

/* Line 1788 of yacc.c  */
#line 3263 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  }
    break;

  case 568:

/* Line 1788 of yacc.c  */
#line 3267 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 569:

/* Line 1788 of yacc.c  */
#line 3271 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  }
    break;

  case 570:

/* Line 1788 of yacc.c  */
#line 3278 "parser.y"
    {
	/* Nothing */
  }
    break;

  case 571:

/* Line 1788 of yacc.c  */
#line 3282 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 572:

/* Line 1788 of yacc.c  */
#line 3286 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  }
    break;

  case 573:

/* Line 1788 of yacc.c  */
#line 3290 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 574:

/* Line 1788 of yacc.c  */
#line 3294 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  }
    break;

  case 575:

/* Line 1788 of yacc.c  */
#line 3302 "parser.y"
    {
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  }
    break;

  case 577:

/* Line 1788 of yacc.c  */
#line 3316 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	cb_define_system_name ("CONSOLE");
	cb_define_system_name ("SYSIN");
	cb_define_system_name ("SYSOUT");
	cb_define_system_name ("SYSERR");
	cb_set_in_procedure ();
  }
    break;

  case 578:

/* Line 1788 of yacc.c  */
#line 3326 "parser.y"
    {
	if (current_program->flag_main && !current_program->flag_chained && (yyvsp[(3) - (7)])) {
		cb_error (_("Executable program requested but PROCEDURE/ENTRY has USING clause"));
	}
	emit_entry (current_program->program_id, 0, (yyvsp[(3) - (7)])); /* main entry point */
	if (current_program->source_name) {
		emit_entry (current_program->source_name, 1, (yyvsp[(3) - (7)]));
	}
  }
    break;

  case 579:

/* Line 1788 of yacc.c  */
#line 3336 "parser.y"
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

  case 580:

/* Line 1788 of yacc.c  */
#line 3353 "parser.y"
    { (yyval) = NULL; }
    break;

  case 581:

/* Line 1788 of yacc.c  */
#line 3355 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 582:

/* Line 1788 of yacc.c  */
#line 3359 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 583:

/* Line 1788 of yacc.c  */
#line 3361 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	current_program->flag_chained = 1;
  }
    break;

  case 584:

/* Line 1788 of yacc.c  */
#line 3365 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 585:

/* Line 1788 of yacc.c  */
#line 3369 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 586:

/* Line 1788 of yacc.c  */
#line 3371 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 587:

/* Line 1788 of yacc.c  */
#line 3376 "parser.y"
    {
	(yyval) = cb_build_pair (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)])));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 589:

/* Line 1788 of yacc.c  */
#line 3385 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 590:

/* Line 1788 of yacc.c  */
#line 3389 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 592:

/* Line 1788 of yacc.c  */
#line 3401 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  }
    break;

  case 593:

/* Line 1788 of yacc.c  */
#line 3409 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  }
    break;

  case 594:

/* Line 1788 of yacc.c  */
#line 3417 "parser.y"
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

  case 595:

/* Line 1788 of yacc.c  */
#line 3446 "parser.y"
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

  case 597:

/* Line 1788 of yacc.c  */
#line 3479 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  }
    break;

  case 598:

/* Line 1788 of yacc.c  */
#line 3488 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  }
    break;

  case 599:

/* Line 1788 of yacc.c  */
#line 3494 "parser.y"
    {
	if (cb_ref ((yyvsp[(2) - (2)])) != cb_error_node) {
		current_program->returning = (yyvsp[(2) - (2)]);
		if (cb_field ((yyvsp[(2) - (2)]))->storage != CB_STORAGE_LINKAGE) {
			cb_error (_("RETURNING item is not defined in LINKAGE SECTION"));
		}
	}
  }
    break;

  case 601:

/* Line 1788 of yacc.c  */
#line 3505 "parser.y"
    { in_declaratives = 1; }
    break;

  case 602:

/* Line 1788 of yacc.c  */
#line 3508 "parser.y"
    {
	in_declaratives = 0;
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
		emit_statement (cb_build_perform_exit (current_section));
		current_section = NULL;
	}
  }
    break;

  case 608:

/* Line 1788 of yacc.c  */
#line 3541 "parser.y"
    {
	if (next_label_list) {
		cb_tree label;
		char name[16];

		sprintf (name, "L$%d", next_label_id);
		label = cb_build_reference (name);
		emit_statement (cb_build_label (label, NULL));
		current_program->label_list =
			cb_list_append (current_program->label_list, next_label_list);
		next_label_list = NULL;
		next_label_id++;
	}
	/* check_unreached = 0; */
  }
    break;

  case 609:

/* Line 1788 of yacc.c  */
#line 3557 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 610:

/* Line 1788 of yacc.c  */
#line 3561 "parser.y"
    {
	/* check_unreached = 0; */
  }
    break;

  case 611:

/* Line 1788 of yacc.c  */
#line 3573 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if ((yyvsp[(1) - (4)]) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last section */
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

	/* Begin a new section */
	current_section = CB_LABEL (cb_build_label ((yyvsp[(1) - (4)]), NULL));
	current_section->is_section = 1;
	current_paragraph = NULL;
	emit_statement (CB_TREE (current_section));
  }
    break;

  case 612:

/* Line 1788 of yacc.c  */
#line 3604 "parser.y"
    {
	cb_tree label;

	non_const_word = 0;
	check_unreached = 0;
	(yyval) = cb_build_section_name ((yyvsp[(1) - (2)]), 1);
	/* if ($1 == cb_error_node) */
	if ((yyval) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph */
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
	}

	/* Begin a new paragraph */
	if (!current_section) {
		label = cb_build_reference ("MAIN SECTION");
		current_section = CB_LABEL (cb_build_label (label, NULL));
		current_section->is_section = 1;
		emit_statement (CB_TREE (current_section));
	}
	current_paragraph = CB_LABEL (cb_build_label ((yyval), current_section));
	if (current_section) {
		current_section->children =
			cb_cons (CB_TREE (current_paragraph), current_section->children);
	}
	emit_statement (CB_TREE (current_paragraph));
  }
    break;

  case 613:

/* Line 1788 of yacc.c  */
#line 3641 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  }
    break;

  case 614:

/* Line 1788 of yacc.c  */
#line 3652 "parser.y"
    { (yyval) = cb_build_section_name ((yyvsp[(1) - (1)]), 0); }
    break;

  case 616:

/* Line 1788 of yacc.c  */
#line 3656 "parser.y"
    { /* ignore */ }
    break;

  case 617:

/* Line 1788 of yacc.c  */
#line 3665 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
  }
    break;

  case 618:

/* Line 1788 of yacc.c  */
#line 3669 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  }
    break;

  case 619:

/* Line 1788 of yacc.c  */
#line 3674 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  }
    break;

  case 620:

/* Line 1788 of yacc.c  */
#line 3682 "parser.y"
    {
	cb_tree label;

	if (!current_section) {
		label = cb_build_reference ("MAIN SECTION");
		current_section = CB_LABEL (cb_build_label (label, NULL));
		current_section->is_section = 1;
		emit_statement (CB_TREE (current_section));
	}
	if (!current_paragraph) {
		label = cb_build_reference ("MAIN PARAGRAPH");
		current_paragraph = CB_LABEL (cb_build_label (label, NULL));
		emit_statement (CB_TREE (current_paragraph));
		current_section->children =
			cb_cons (CB_TREE (current_paragraph), current_section->children);
	}
  }
    break;

  case 671:

/* Line 1788 of yacc.c  */
#line 3753 "parser.y"
    {
	if (cb_verify (cb_next_sentence_phrase, "NEXT SENTENCE")) {
		cb_tree label;
		char	name[16];

		BEGIN_STATEMENT ("NEXT SENTENCE", 0);
		sprintf (name, "L$%d", next_label_id);
		label = cb_build_reference (name);
		next_label_list = cb_list_add (next_label_list, label);
		emit_statement (cb_build_goto (label, NULL));
	}
	check_unreached = 0;
  }
    break;

  case 672:

/* Line 1788 of yacc.c  */
#line 3775 "parser.y"
    {
	BEGIN_STATEMENT ("ACCEPT", TERM_ACCEPT);
	dispattrs = 0;
	fgc = NULL;
	bgc = NULL;
	scroll = NULL;
  }
    break;

  case 674:

/* Line 1788 of yacc.c  */
#line 3788 "parser.y"
    {
	cb_emit_accept ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), fgc, bgc, scroll, dispattrs);
  }
    break;

  case 675:

/* Line 1788 of yacc.c  */
#line 3792 "parser.y"
    {
	PENDING ("ACCEPT .. FROM ESCAPE KEY");
  }
    break;

  case 676:

/* Line 1788 of yacc.c  */
#line 3796 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  }
    break;

  case 677:

/* Line 1788 of yacc.c  */
#line 3800 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  }
    break;

  case 678:

/* Line 1788 of yacc.c  */
#line 3804 "parser.y"
    {
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  }
    break;

  case 679:

/* Line 1788 of yacc.c  */
#line 3808 "parser.y"
    {
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  }
    break;

  case 680:

/* Line 1788 of yacc.c  */
#line 3812 "parser.y"
    {
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  }
    break;

  case 681:

/* Line 1788 of yacc.c  */
#line 3816 "parser.y"
    {
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  }
    break;

  case 682:

/* Line 1788 of yacc.c  */
#line 3820 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  }
    break;

  case 683:

/* Line 1788 of yacc.c  */
#line 3824 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  }
    break;

  case 684:

/* Line 1788 of yacc.c  */
#line 3828 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 685:

/* Line 1788 of yacc.c  */
#line 3832 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  }
    break;

  case 686:

/* Line 1788 of yacc.c  */
#line 3836 "parser.y"
    { 
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  }
    break;

  case 687:

/* Line 1788 of yacc.c  */
#line 3840 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 688:

/* Line 1788 of yacc.c  */
#line 3844 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  }
    break;

  case 689:

/* Line 1788 of yacc.c  */
#line 3848 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 690:

/* Line 1788 of yacc.c  */
#line 3852 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 691:

/* Line 1788 of yacc.c  */
#line 3858 "parser.y"
    { (yyval) = NULL; }
    break;

  case 692:

/* Line 1788 of yacc.c  */
#line 3859 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 693:

/* Line 1788 of yacc.c  */
#line 3860 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 694:

/* Line 1788 of yacc.c  */
#line 3861 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(2) - (2)]), NULL); }
    break;

  case 695:

/* Line 1788 of yacc.c  */
#line 3862 "parser.y"
    { (yyval) = cb_build_pair (NULL, (yyvsp[(2) - (2)])); }
    break;

  case 696:

/* Line 1788 of yacc.c  */
#line 3863 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 697:

/* Line 1788 of yacc.c  */
#line 3867 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 698:

/* Line 1788 of yacc.c  */
#line 3871 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 699:

/* Line 1788 of yacc.c  */
#line 3872 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 704:

/* Line 1788 of yacc.c  */
#line 3885 "parser.y"
    { dispattrs |= COB_SCREEN_BELL; }
    break;

  case 705:

/* Line 1788 of yacc.c  */
#line 3886 "parser.y"
    { dispattrs |= COB_SCREEN_BLINK; }
    break;

  case 706:

/* Line 1788 of yacc.c  */
#line 3887 "parser.y"
    { dispattrs |= COB_SCREEN_HIGHLIGHT; }
    break;

  case 707:

/* Line 1788 of yacc.c  */
#line 3888 "parser.y"
    { dispattrs |= COB_SCREEN_LOWLIGHT; }
    break;

  case 708:

/* Line 1788 of yacc.c  */
#line 3889 "parser.y"
    { dispattrs |= COB_SCREEN_REVERSE; }
    break;

  case 709:

/* Line 1788 of yacc.c  */
#line 3890 "parser.y"
    { dispattrs |= COB_SCREEN_UNDERLINE; }
    break;

  case 710:

/* Line 1788 of yacc.c  */
#line 3891 "parser.y"
    { dispattrs |= COB_SCREEN_OVERLINE; }
    break;

  case 711:

/* Line 1788 of yacc.c  */
#line 3893 "parser.y"
    {
	fgc = (yyvsp[(3) - (3)]);
  }
    break;

  case 712:

/* Line 1788 of yacc.c  */
#line 3897 "parser.y"
    {
	bgc = (yyvsp[(3) - (3)]);
  }
    break;

  case 713:

/* Line 1788 of yacc.c  */
#line 3901 "parser.y"
    {
	scroll = (yyvsp[(3) - (3)]);
  }
    break;

  case 714:

/* Line 1788 of yacc.c  */
#line 3905 "parser.y"
    {
	dispattrs |= COB_SCREEN_SCROLL_DOWN;
	scroll = (yyvsp[(3) - (3)]);
  }
    break;

  case 715:

/* Line 1788 of yacc.c  */
#line 3909 "parser.y"
    { dispattrs |= COB_SCREEN_AUTO; }
    break;

  case 716:

/* Line 1788 of yacc.c  */
#line 3910 "parser.y"
    { dispattrs |= COB_SCREEN_FULL; }
    break;

  case 717:

/* Line 1788 of yacc.c  */
#line 3911 "parser.y"
    { dispattrs |= COB_SCREEN_REQUIRED; }
    break;

  case 718:

/* Line 1788 of yacc.c  */
#line 3912 "parser.y"
    { dispattrs |= COB_SCREEN_SECURE; }
    break;

  case 719:

/* Line 1788 of yacc.c  */
#line 3913 "parser.y"
    { dispattrs |= COB_SCREEN_UPDATE; }
    break;

  case 720:

/* Line 1788 of yacc.c  */
#line 3914 "parser.y"
    { dispattrs |= COB_SCREEN_PROMPT; }
    break;

  case 721:

/* Line 1788 of yacc.c  */
#line 3918 "parser.y"
    { terminator_warning (TERM_ACCEPT); }
    break;

  case 722:

/* Line 1788 of yacc.c  */
#line 3919 "parser.y"
    { terminator_clear (TERM_ACCEPT); }
    break;

  case 723:

/* Line 1788 of yacc.c  */
#line 3928 "parser.y"
    { BEGIN_STATEMENT ("ADD", TERM_ADD); }
    break;

  case 725:

/* Line 1788 of yacc.c  */
#line 3935 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 726:

/* Line 1788 of yacc.c  */
#line 3939 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  }
    break;

  case 727:

/* Line 1788 of yacc.c  */
#line 3943 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 729:

/* Line 1788 of yacc.c  */
#line 3949 "parser.y"
    { cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 730:

/* Line 1788 of yacc.c  */
#line 3953 "parser.y"
    { terminator_warning (TERM_ADD); }
    break;

  case 731:

/* Line 1788 of yacc.c  */
#line 3954 "parser.y"
    { terminator_clear (TERM_ADD); }
    break;

  case 732:

/* Line 1788 of yacc.c  */
#line 3963 "parser.y"
    { BEGIN_STATEMENT ("ALLOCATE", 0); }
    break;

  case 734:

/* Line 1788 of yacc.c  */
#line 3969 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  }
    break;

  case 735:

/* Line 1788 of yacc.c  */
#line 3973 "parser.y"
    {
	cb_emit_allocate (NULL, (yyvsp[(5) - (5)]), (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]));
  }
    break;

  case 736:

/* Line 1788 of yacc.c  */
#line 3979 "parser.y"
    { (yyval) = NULL; }
    break;

  case 737:

/* Line 1788 of yacc.c  */
#line 3980 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 738:

/* Line 1788 of yacc.c  */
#line 3990 "parser.y"
    {
	cb_error (_("ALTER statement is obsolete and unsupported"));
  }
    break;

  case 743:

/* Line 1788 of yacc.c  */
#line 4008 "parser.y"
    { BEGIN_STATEMENT ("CALL", TERM_CALL); }
    break;

  case 744:

/* Line 1788 of yacc.c  */
#line 4012 "parser.y"
    {
	cb_emit_call ((yyvsp[(3) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 745:

/* Line 1788 of yacc.c  */
#line 4018 "parser.y"
    { (yyval) = NULL; }
    break;

  case 746:

/* Line 1788 of yacc.c  */
#line 4020 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  }
    break;

  case 747:

/* Line 1788 of yacc.c  */
#line 4024 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 748:

/* Line 1788 of yacc.c  */
#line 4028 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 749:

/* Line 1788 of yacc.c  */
#line 4030 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 750:

/* Line 1788 of yacc.c  */
#line 4035 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = cb_build_pair (cb_int (call_mode), cb_null);
  }
    break;

  case 751:

/* Line 1788 of yacc.c  */
#line 4042 "parser.y"
    {
	(yyval) = cb_build_pair (cb_int (call_mode), (yyvsp[(3) - (3)]));
	CB_SIZES ((yyval)) = size_mode;
  }
    break;

  case 753:

/* Line 1788 of yacc.c  */
#line 4051 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  }
    break;

  case 754:

/* Line 1788 of yacc.c  */
#line 4055 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  }
    break;

  case 755:

/* Line 1788 of yacc.c  */
#line 4063 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  }
    break;

  case 756:

/* Line 1788 of yacc.c  */
#line 4073 "parser.y"
    { (yyval) = NULL; }
    break;

  case 757:

/* Line 1788 of yacc.c  */
#line 4074 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 758:

/* Line 1788 of yacc.c  */
#line 4075 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 759:

/* Line 1788 of yacc.c  */
#line 4080 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 760:

/* Line 1788 of yacc.c  */
#line 4084 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 761:

/* Line 1788 of yacc.c  */
#line 4088 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 762:

/* Line 1788 of yacc.c  */
#line 4095 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 763:

/* Line 1788 of yacc.c  */
#line 4099 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 764:

/* Line 1788 of yacc.c  */
#line 4103 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 765:

/* Line 1788 of yacc.c  */
#line 4109 "parser.y"
    { terminator_warning (TERM_CALL); }
    break;

  case 766:

/* Line 1788 of yacc.c  */
#line 4110 "parser.y"
    { terminator_clear (TERM_CALL); }
    break;

  case 767:

/* Line 1788 of yacc.c  */
#line 4119 "parser.y"
    { BEGIN_STATEMENT ("CANCEL", 0); }
    break;

  case 770:

/* Line 1788 of yacc.c  */
#line 4125 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  }
    break;

  case 771:

/* Line 1788 of yacc.c  */
#line 4136 "parser.y"
    { BEGIN_STATEMENT ("CLOSE", 0); }
    break;

  case 774:

/* Line 1788 of yacc.c  */
#line 4143 "parser.y"
    {
	BEGIN_IMPLICIT_STATEMENT ();
	if ((yyvsp[(2) - (3)]) != cb_error_node) {
		cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	}
  }
    break;

  case 775:

/* Line 1788 of yacc.c  */
#line 4152 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); }
    break;

  case 776:

/* Line 1788 of yacc.c  */
#line 4153 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); }
    break;

  case 777:

/* Line 1788 of yacc.c  */
#line 4154 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); }
    break;

  case 778:

/* Line 1788 of yacc.c  */
#line 4155 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); }
    break;

  case 779:

/* Line 1788 of yacc.c  */
#line 4156 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); }
    break;

  case 782:

/* Line 1788 of yacc.c  */
#line 4167 "parser.y"
    { BEGIN_STATEMENT ("COMPUTE", TERM_COMPUTE); }
    break;

  case 784:

/* Line 1788 of yacc.c  */
#line 4174 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  }
    break;

  case 785:

/* Line 1788 of yacc.c  */
#line 4180 "parser.y"
    { terminator_warning (TERM_COMPUTE); }
    break;

  case 786:

/* Line 1788 of yacc.c  */
#line 4181 "parser.y"
    { terminator_clear (TERM_COMPUTE); }
    break;

  case 789:

/* Line 1788 of yacc.c  */
#line 4192 "parser.y"
    {
	BEGIN_STATEMENT ("COMMIT", 0);
	cb_emit_commit ();
  }
    break;

  case 790:

/* Line 1788 of yacc.c  */
#line 4205 "parser.y"
    {
	BEGIN_STATEMENT ("CONTINUE", 0);
	cb_emit_continue ();
  }
    break;

  case 791:

/* Line 1788 of yacc.c  */
#line 4217 "parser.y"
    { BEGIN_STATEMENT ("DELETE", TERM_DELETE); }
    break;

  case 792:

/* Line 1788 of yacc.c  */
#line 4220 "parser.y"
    {
	if ((yyvsp[(3) - (6)]) != cb_error_node) {
		cb_emit_delete ((yyvsp[(3) - (6)]));
	}
  }
    break;

  case 793:

/* Line 1788 of yacc.c  */
#line 4228 "parser.y"
    { terminator_warning (TERM_DELETE); }
    break;

  case 794:

/* Line 1788 of yacc.c  */
#line 4229 "parser.y"
    { terminator_clear (TERM_DELETE); }
    break;

  case 795:

/* Line 1788 of yacc.c  */
#line 4239 "parser.y"
    {
	BEGIN_STATEMENT ("DISPLAY", TERM_DISPLAY);
	dispattrs = 0;
	fgc = NULL;
	bgc = NULL;
	scroll = NULL;
  }
    break;

  case 797:

/* Line 1788 of yacc.c  */
#line 4252 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  }
    break;

  case 798:

/* Line 1788 of yacc.c  */
#line 4256 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  }
    break;

  case 799:

/* Line 1788 of yacc.c  */
#line 4260 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  }
    break;

  case 800:

/* Line 1788 of yacc.c  */
#line 4264 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  }
    break;

  case 801:

/* Line 1788 of yacc.c  */
#line 4268 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(2) - (5)]), fgc, bgc, scroll, dispattrs);
  }
    break;

  case 802:

/* Line 1788 of yacc.c  */
#line 4274 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 803:

/* Line 1788 of yacc.c  */
#line 4275 "parser.y"
    { (yyval) = cb_build_display_upon ((yyvsp[(2) - (2)])); }
    break;

  case 804:

/* Line 1788 of yacc.c  */
#line 4276 "parser.y"
    { (yyval) = cb_build_display_upon_direct ((yyvsp[(2) - (2)])); }
    break;

  case 805:

/* Line 1788 of yacc.c  */
#line 4277 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 806:

/* Line 1788 of yacc.c  */
#line 4278 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 807:

/* Line 1788 of yacc.c  */
#line 4282 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 808:

/* Line 1788 of yacc.c  */
#line 4283 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 809:

/* Line 1788 of yacc.c  */
#line 4284 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 812:

/* Line 1788 of yacc.c  */
#line 4294 "parser.y"
    { dispattrs |= COB_SCREEN_BELL; }
    break;

  case 813:

/* Line 1788 of yacc.c  */
#line 4295 "parser.y"
    { dispattrs |= COB_SCREEN_BLINK; }
    break;

  case 814:

/* Line 1788 of yacc.c  */
#line 4296 "parser.y"
    { dispattrs |= COB_SCREEN_ERASE_EOL; }
    break;

  case 815:

/* Line 1788 of yacc.c  */
#line 4297 "parser.y"
    { dispattrs |= COB_SCREEN_ERASE_EOS; }
    break;

  case 816:

/* Line 1788 of yacc.c  */
#line 4298 "parser.y"
    { dispattrs |= COB_SCREEN_HIGHLIGHT; }
    break;

  case 817:

/* Line 1788 of yacc.c  */
#line 4299 "parser.y"
    { dispattrs |= COB_SCREEN_LOWLIGHT; }
    break;

  case 818:

/* Line 1788 of yacc.c  */
#line 4300 "parser.y"
    { dispattrs |= COB_SCREEN_REVERSE; }
    break;

  case 819:

/* Line 1788 of yacc.c  */
#line 4301 "parser.y"
    { dispattrs |= COB_SCREEN_UNDERLINE; }
    break;

  case 820:

/* Line 1788 of yacc.c  */
#line 4302 "parser.y"
    { dispattrs |= COB_SCREEN_OVERLINE; }
    break;

  case 821:

/* Line 1788 of yacc.c  */
#line 4304 "parser.y"
    {
	fgc = (yyvsp[(3) - (3)]);
  }
    break;

  case 822:

/* Line 1788 of yacc.c  */
#line 4308 "parser.y"
    {
	bgc = (yyvsp[(3) - (3)]);
  }
    break;

  case 823:

/* Line 1788 of yacc.c  */
#line 4312 "parser.y"
    {
	scroll = (yyvsp[(3) - (3)]);
  }
    break;

  case 824:

/* Line 1788 of yacc.c  */
#line 4316 "parser.y"
    {
	dispattrs |= COB_SCREEN_SCROLL_DOWN;
	scroll = (yyvsp[(3) - (3)]);
  }
    break;

  case 825:

/* Line 1788 of yacc.c  */
#line 4320 "parser.y"
    { dispattrs |= COB_SCREEN_BLANK_LINE; }
    break;

  case 826:

/* Line 1788 of yacc.c  */
#line 4321 "parser.y"
    { dispattrs |= COB_SCREEN_BLANK_SCREEN; }
    break;

  case 827:

/* Line 1788 of yacc.c  */
#line 4325 "parser.y"
    { terminator_warning (TERM_DISPLAY); }
    break;

  case 828:

/* Line 1788 of yacc.c  */
#line 4326 "parser.y"
    { terminator_clear (TERM_DISPLAY); }
    break;

  case 829:

/* Line 1788 of yacc.c  */
#line 4335 "parser.y"
    { BEGIN_STATEMENT ("DIVIDE", TERM_DIVIDE); }
    break;

  case 831:

/* Line 1788 of yacc.c  */
#line 4342 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  }
    break;

  case 832:

/* Line 1788 of yacc.c  */
#line 4346 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  }
    break;

  case 833:

/* Line 1788 of yacc.c  */
#line 4350 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  }
    break;

  case 834:

/* Line 1788 of yacc.c  */
#line 4354 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 835:

/* Line 1788 of yacc.c  */
#line 4358 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 836:

/* Line 1788 of yacc.c  */
#line 4364 "parser.y"
    { terminator_warning (TERM_DIVIDE); }
    break;

  case 837:

/* Line 1788 of yacc.c  */
#line 4365 "parser.y"
    { terminator_clear (TERM_DIVIDE); }
    break;

  case 838:

/* Line 1788 of yacc.c  */
#line 4374 "parser.y"
    { BEGIN_STATEMENT ("ENTRY", 0); }
    break;

  case 839:

/* Line 1788 of yacc.c  */
#line 4376 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("ENTRY is invalid in nested program"));
	} else if (cb_verify (cb_entry_statement, "ENTRY")) {
		if (cobc_check_valid_name ((char *)(CB_LITERAL ((yyvsp[(3) - (4)]))->data))) {
			cb_error (_("ENTRY '%s' invalid"), (char *)(CB_LITERAL ((yyvsp[(3) - (4)]))->data));
		}
		emit_entry ((char *)(CB_LITERAL ((yyvsp[(3) - (4)]))->data), 1, (yyvsp[(4) - (4)]));
	}
	check_unreached = 0;
  }
    break;

  case 840:

/* Line 1788 of yacc.c  */
#line 4396 "parser.y"
    {
	BEGIN_STATEMENT ("EVALUATE", TERM_EVALUATE);
	eval_level++;
	for (eval_inc = 0; eval_inc < 64; eval_inc++) {
		eval_check[eval_level][eval_inc] = 0;
	}
	eval_inc = 0;
	eval_inc2 = 0;
  }
    break;

  case 841:

/* Line 1788 of yacc.c  */
#line 4407 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	eval_level--;
  }
    break;

  case 842:

/* Line 1788 of yacc.c  */
#line 4414 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 843:

/* Line 1788 of yacc.c  */
#line 4416 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 844:

/* Line 1788 of yacc.c  */
#line 4421 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)]))) {
		eval_check[eval_level][eval_inc++] = 0;
	} else {
		eval_check[eval_level][eval_inc++] = 1;
	}
  }
    break;

  case 845:

/* Line 1788 of yacc.c  */
#line 4430 "parser.y"
    {
	(yyval) = cb_true;
	eval_check[eval_level][eval_inc++] = 2;
  }
    break;

  case 846:

/* Line 1788 of yacc.c  */
#line 4435 "parser.y"
    {
	(yyval) = cb_false;
	eval_check[eval_level][eval_inc++] = 3;
  }
    break;

  case 847:

/* Line 1788 of yacc.c  */
#line 4443 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_add ((yyval), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 848:

/* Line 1788 of yacc.c  */
#line 4452 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 849:

/* Line 1788 of yacc.c  */
#line 4454 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 850:

/* Line 1788 of yacc.c  */
#line 4459 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 851:

/* Line 1788 of yacc.c  */
#line 4463 "parser.y"
    {
	(yyval) = cb_cons ((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
	eval_inc2 = 0;
  }
    break;

  case 852:

/* Line 1788 of yacc.c  */
#line 4471 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 853:

/* Line 1788 of yacc.c  */
#line 4475 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 854:

/* Line 1788 of yacc.c  */
#line 4479 "parser.y"
    {
	(yyval) = cb_cons ((yyvsp[(4) - (4)]), NULL);
	eval_inc2 = 0;
  }
    break;

  case 855:

/* Line 1788 of yacc.c  */
#line 4486 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(2) - (2)])); }
    break;

  case 856:

/* Line 1788 of yacc.c  */
#line 4488 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 857:

/* Line 1788 of yacc.c  */
#line 4492 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 858:

/* Line 1788 of yacc.c  */
#line 4494 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 859:

/* Line 1788 of yacc.c  */
#line 4499 "parser.y"
    {
	cb_tree not;
	cb_tree e1;
	cb_tree e2;

	not = cb_int0;
	e2 = (yyvsp[(2) - (2)]);
	/* in case the first token is NOT */
	if (CB_PURPOSE_INT ((yyvsp[(1) - (2)])) == '!') {
		if (eval_check[eval_level][eval_inc2] < 2) {
			not = cb_int1;
			(yyvsp[(1) - (2)]) = CB_CHAIN ((yyvsp[(1) - (2)]));
		}
	}

	/* build expr now */
	e1 = cb_build_expr ((yyvsp[(1) - (2)]));

	if (e2 == NULL) {
		/* WHEN expr */
		eval_inc2++;
		(yyval) = cb_build_pair (not, cb_build_pair (e1, NULL));
	} else {
		/* WHEN expr THRU expr */
		(yyval) = cb_build_pair (not, cb_build_pair (e1, e2));
		eval_inc2++;
	}
  }
    break;

  case 860:

/* Line 1788 of yacc.c  */
#line 4527 "parser.y"
    { (yyval) = cb_any; eval_inc2++; }
    break;

  case 861:

/* Line 1788 of yacc.c  */
#line 4528 "parser.y"
    { (yyval) = cb_true; eval_inc2++; }
    break;

  case 862:

/* Line 1788 of yacc.c  */
#line 4529 "parser.y"
    { (yyval) = cb_false; eval_inc2++; }
    break;

  case 863:

/* Line 1788 of yacc.c  */
#line 4532 "parser.y"
    { (yyval) = NULL; }
    break;

  case 864:

/* Line 1788 of yacc.c  */
#line 4533 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 865:

/* Line 1788 of yacc.c  */
#line 4537 "parser.y"
    { terminator_warning (TERM_EVALUATE); }
    break;

  case 866:

/* Line 1788 of yacc.c  */
#line 4538 "parser.y"
    { terminator_clear (TERM_EVALUATE); }
    break;

  case 867:

/* Line 1788 of yacc.c  */
#line 4547 "parser.y"
    { BEGIN_STATEMENT ("EXIT", 0); }
    break;

  case 869:

/* Line 1788 of yacc.c  */
#line 4552 "parser.y"
    { /* nothing */ }
    break;

  case 870:

/* Line 1788 of yacc.c  */
#line 4554 "parser.y"
    {
	if (in_declaratives && use_global_ind) {
		cb_error (_("EXIT PROGRAM is not allowed within a USE GLOBAL procedure"));
	}
	check_unreached = 1;
	cb_emit_exit (0);
  }
    break;

  case 871:

/* Line 1788 of yacc.c  */
#line 4562 "parser.y"
    {
	struct cb_perform	*p;
	char			name[64];

	if (!perform_stack) {
		cb_error (_("EXIT PERFORM is only valid with inline PERFORM"));
	} else {
		p = CB_PERFORM (CB_VALUE (perform_stack));
		if (!p->exit_label) {
			sprintf (name, "EXIT PERFORM %d", cb_id);
			p->exit_label = cb_build_reference (name);
			CB_LABEL (cb_build_label (p->exit_label, NULL))->need_begin = 1;
		}
		cb_emit_goto (cb_list_init (p->exit_label), NULL);
	}
  }
    break;

  case 872:

/* Line 1788 of yacc.c  */
#line 4579 "parser.y"
    {
	struct cb_perform	*p;
	char			name[64];

	if (!perform_stack) {
		cb_error (_("EXIT PERFORM is only valid with inline PERFORM"));
	} else {
		p = CB_PERFORM (CB_VALUE (perform_stack));
		if (!p->cycle_label) {
			sprintf (name, "EXIT PERFORM CYCLE %d", cb_id);
			p->cycle_label = cb_build_reference (name);
			CB_LABEL (cb_build_label (p->cycle_label, NULL))->need_begin = 1;
		}
		cb_emit_goto (cb_list_init (p->cycle_label), NULL);
	}
  }
    break;

  case 873:

/* Line 1788 of yacc.c  */
#line 4596 "parser.y"
    {
	cb_tree	plabel;
	char	name[64];

	if (!current_section) {
		cb_error (_("EXIT SECTION is only valid with an active SECTION"));
	} else {
		if (!current_section->exit_label) {
			sprintf (name, "EXIT SECTION %d", cb_id);
			plabel = cb_build_reference (name);
			current_section->exit_label = cb_build_label (plabel, NULL);
			current_section->exit_label_ref = plabel;
			CB_LABEL (current_section->exit_label)->need_begin = 1;
		}
		cb_emit_goto (cb_list_init (current_section->exit_label_ref), NULL);
	}
  }
    break;

  case 874:

/* Line 1788 of yacc.c  */
#line 4614 "parser.y"
    {
	cb_tree	plabel;
	char	name[64];

	if (!current_paragraph) {
		cb_error (_("EXIT PARAGRAPH is only valid with an active PARAGRAPH"));
	} else {
		if (!current_paragraph->exit_label) {
			sprintf (name, "EXIT PARAGRAPH %d", cb_id);
			plabel = cb_build_reference (name);
			current_paragraph->exit_label = cb_build_label (plabel, NULL);
			current_paragraph->exit_label_ref = plabel;
			CB_LABEL (current_paragraph->exit_label)->need_begin = 1;
		}
		cb_emit_goto (cb_list_init (current_paragraph->exit_label_ref), NULL);
	}
  }
    break;

  case 875:

/* Line 1788 of yacc.c  */
#line 4638 "parser.y"
    { BEGIN_STATEMENT ("FREE", 0); }
    break;

  case 876:

/* Line 1788 of yacc.c  */
#line 4640 "parser.y"
    {
	cb_emit_free ((yyvsp[(3) - (3)]));
  }
    break;

  case 877:

/* Line 1788 of yacc.c  */
#line 4651 "parser.y"
    { BEGIN_STATEMENT ("GENERATE", 0); }
    break;

  case 878:

/* Line 1788 of yacc.c  */
#line 4653 "parser.y"
    {
	PENDING("GENERATE");
  }
    break;

  case 879:

/* Line 1788 of yacc.c  */
#line 4664 "parser.y"
    { BEGIN_STATEMENT ("GO TO", 0); }
    break;

  case 880:

/* Line 1788 of yacc.c  */
#line 4666 "parser.y"
    {
	cb_emit_goto ((yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 881:

/* Line 1788 of yacc.c  */
#line 4673 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  }
    break;

  case 882:

/* Line 1788 of yacc.c  */
#line 4678 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 883:

/* Line 1788 of yacc.c  */
#line 4690 "parser.y"
    { BEGIN_STATEMENT ("GOBACK", 0); }
    break;

  case 884:

/* Line 1788 of yacc.c  */
#line 4691 "parser.y"
    {
	check_unreached = 1;
	cb_emit_exit (1);
  }
    break;

  case 885:

/* Line 1788 of yacc.c  */
#line 4703 "parser.y"
    { BEGIN_STATEMENT ("IF", TERM_IF); }
    break;

  case 886:

/* Line 1788 of yacc.c  */
#line 4705 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 887:

/* Line 1788 of yacc.c  */
#line 4710 "parser.y"
    {
	cb_emit_if ((yyvsp[(3) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]));
  }
    break;

  case 889:

/* Line 1788 of yacc.c  */
#line 4718 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 890:

/* Line 1788 of yacc.c  */
#line 4722 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 891:

/* Line 1788 of yacc.c  */
#line 4726 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 892:

/* Line 1788 of yacc.c  */
#line 4732 "parser.y"
    { terminator_warning (TERM_IF); }
    break;

  case 893:

/* Line 1788 of yacc.c  */
#line 4733 "parser.y"
    { terminator_clear (TERM_IF); }
    break;

  case 894:

/* Line 1788 of yacc.c  */
#line 4742 "parser.y"
    { BEGIN_STATEMENT ("INITIALIZE", 0); }
    break;

  case 895:

/* Line 1788 of yacc.c  */
#line 4744 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 896:

/* Line 1788 of yacc.c  */
#line 4750 "parser.y"
    { (yyval) = NULL; }
    break;

  case 897:

/* Line 1788 of yacc.c  */
#line 4751 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 898:

/* Line 1788 of yacc.c  */
#line 4755 "parser.y"
    { (yyval) = NULL; }
    break;

  case 899:

/* Line 1788 of yacc.c  */
#line 4756 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 900:

/* Line 1788 of yacc.c  */
#line 4757 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 901:

/* Line 1788 of yacc.c  */
#line 4761 "parser.y"
    { (yyval) = NULL; }
    break;

  case 902:

/* Line 1788 of yacc.c  */
#line 4763 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 903:

/* Line 1788 of yacc.c  */
#line 4767 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 904:

/* Line 1788 of yacc.c  */
#line 4769 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 905:

/* Line 1788 of yacc.c  */
#line 4773 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 906:

/* Line 1788 of yacc.c  */
#line 4777 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); }
    break;

  case 907:

/* Line 1788 of yacc.c  */
#line 4778 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); }
    break;

  case 908:

/* Line 1788 of yacc.c  */
#line 4779 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); }
    break;

  case 909:

/* Line 1788 of yacc.c  */
#line 4780 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); }
    break;

  case 910:

/* Line 1788 of yacc.c  */
#line 4781 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); }
    break;

  case 911:

/* Line 1788 of yacc.c  */
#line 4782 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); }
    break;

  case 912:

/* Line 1788 of yacc.c  */
#line 4783 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); }
    break;

  case 913:

/* Line 1788 of yacc.c  */
#line 4787 "parser.y"
    { (yyval) = NULL; }
    break;

  case 914:

/* Line 1788 of yacc.c  */
#line 4788 "parser.y"
    { (yyval) = cb_true; }
    break;

  case 915:

/* Line 1788 of yacc.c  */
#line 4797 "parser.y"
    { BEGIN_STATEMENT ("INITIATE", 0); }
    break;

  case 916:

/* Line 1788 of yacc.c  */
#line 4799 "parser.y"
    {
	PENDING("INITIATE");
  }
    break;

  case 917:

/* Line 1788 of yacc.c  */
#line 4810 "parser.y"
    {
	BEGIN_STATEMENT ("INSPECT", 0);
	sending_id = 0;
	inspect_keyword = 0;
  }
    break;

  case 919:

/* Line 1788 of yacc.c  */
#line 4819 "parser.y"
    { save_tree_1 = (yyvsp[(1) - (1)]); sending_id = 0; }
    break;

  case 920:

/* Line 1788 of yacc.c  */
#line 4820 "parser.y"
    { save_tree_1 = (yyvsp[(1) - (1)]); sending_id = 1; }
    break;

  case 921:

/* Line 1788 of yacc.c  */
#line 4821 "parser.y"
    { save_tree_1 = (yyvsp[(1) - (1)]); sending_id = 1; }
    break;

  case 924:

/* Line 1788 of yacc.c  */
#line 4830 "parser.y"
    { cb_emit_inspect (save_tree_1, (yyvsp[(1) - (1)]), cb_int0, 0); }
    break;

  case 925:

/* Line 1788 of yacc.c  */
#line 4831 "parser.y"
    { cb_emit_inspect (save_tree_1, (yyvsp[(1) - (1)]), cb_int1, 1); }
    break;

  case 926:

/* Line 1788 of yacc.c  */
#line 4832 "parser.y"
    { cb_emit_inspect (save_tree_1, (yyvsp[(1) - (1)]), cb_int0, 2); }
    break;

  case 927:

/* Line 1788 of yacc.c  */
#line 4838 "parser.y"
    { cb_init_tarrying (); }
    break;

  case 928:

/* Line 1788 of yacc.c  */
#line 4839 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 929:

/* Line 1788 of yacc.c  */
#line 4843 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 930:

/* Line 1788 of yacc.c  */
#line 4844 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 931:

/* Line 1788 of yacc.c  */
#line 4848 "parser.y"
    { (yyval) = cb_build_tarrying_data ((yyvsp[(1) - (2)])); }
    break;

  case 932:

/* Line 1788 of yacc.c  */
#line 4849 "parser.y"
    { (yyval) = cb_build_tarrying_characters ((yyvsp[(2) - (2)])); }
    break;

  case 933:

/* Line 1788 of yacc.c  */
#line 4850 "parser.y"
    { (yyval) = cb_build_tarrying_all (); }
    break;

  case 934:

/* Line 1788 of yacc.c  */
#line 4851 "parser.y"
    { (yyval) = cb_build_tarrying_leading (); }
    break;

  case 935:

/* Line 1788 of yacc.c  */
#line 4852 "parser.y"
    { (yyval) = cb_build_tarrying_trailing (); }
    break;

  case 936:

/* Line 1788 of yacc.c  */
#line 4853 "parser.y"
    { (yyval) = cb_build_tarrying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 937:

/* Line 1788 of yacc.c  */
#line 4859 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); inspect_keyword = 0; }
    break;

  case 938:

/* Line 1788 of yacc.c  */
#line 4863 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 939:

/* Line 1788 of yacc.c  */
#line 4864 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 940:

/* Line 1788 of yacc.c  */
#line 4869 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  }
    break;

  case 941:

/* Line 1788 of yacc.c  */
#line 4873 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 942:

/* Line 1788 of yacc.c  */
#line 4877 "parser.y"
    { /* Nothing */ }
    break;

  case 943:

/* Line 1788 of yacc.c  */
#line 4878 "parser.y"
    { inspect_keyword = 1; }
    break;

  case 944:

/* Line 1788 of yacc.c  */
#line 4879 "parser.y"
    { inspect_keyword = 2; }
    break;

  case 945:

/* Line 1788 of yacc.c  */
#line 4880 "parser.y"
    { inspect_keyword = 3; }
    break;

  case 946:

/* Line 1788 of yacc.c  */
#line 4881 "parser.y"
    { inspect_keyword = 4; }
    break;

  case 947:

/* Line 1788 of yacc.c  */
#line 4886 "parser.y"
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
			cb_error (_("INSPECT missing a keyword"));
			(yyval) = cb_error_node;
			break;
	}
  }
    break;

  case 948:

/* Line 1788 of yacc.c  */
#line 4912 "parser.y"
    {
	(yyval) = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 949:

/* Line 1788 of yacc.c  */
#line 4920 "parser.y"
    { (yyval) = cb_build_inspect_region_start (); }
    break;

  case 950:

/* Line 1788 of yacc.c  */
#line 4922 "parser.y"
    { (yyval) = cb_build_inspect_region ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 953:

/* Line 1788 of yacc.c  */
#line 4933 "parser.y"
    { BEGIN_STATEMENT ("MERGE", 0); }
    break;

  case 955:

/* Line 1788 of yacc.c  */
#line 4943 "parser.y"
    { BEGIN_STATEMENT ("MOVE", 0); }
    break;

  case 957:

/* Line 1788 of yacc.c  */
#line 4949 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 958:

/* Line 1788 of yacc.c  */
#line 4953 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 959:

/* Line 1788 of yacc.c  */
#line 4964 "parser.y"
    { BEGIN_STATEMENT ("MULTIPLY", TERM_MULTIPLY); }
    break;

  case 961:

/* Line 1788 of yacc.c  */
#line 4971 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  }
    break;

  case 962:

/* Line 1788 of yacc.c  */
#line 4975 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  }
    break;

  case 963:

/* Line 1788 of yacc.c  */
#line 4981 "parser.y"
    { terminator_warning (TERM_MULTIPLY); }
    break;

  case 964:

/* Line 1788 of yacc.c  */
#line 4982 "parser.y"
    { terminator_clear (TERM_MULTIPLY); }
    break;

  case 965:

/* Line 1788 of yacc.c  */
#line 4991 "parser.y"
    { BEGIN_STATEMENT ("OPEN", 0); }
    break;

  case 968:

/* Line 1788 of yacc.c  */
#line 4998 "parser.y"
    {
	cb_tree l;
	for (l = (yyvsp[(4) - (5)]); l; l = CB_CHAIN (l)) {
		if (CB_VALUE (l) != cb_error_node) {
			BEGIN_IMPLICIT_STATEMENT ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]));
		}
	}
  }
    break;

  case 969:

/* Line 1788 of yacc.c  */
#line 5010 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); }
    break;

  case 970:

/* Line 1788 of yacc.c  */
#line 5011 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); }
    break;

  case 971:

/* Line 1788 of yacc.c  */
#line 5012 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); }
    break;

  case 972:

/* Line 1788 of yacc.c  */
#line 5013 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); }
    break;

  case 973:

/* Line 1788 of yacc.c  */
#line 5017 "parser.y"
    { (yyval) = NULL; }
    break;

  case 974:

/* Line 1788 of yacc.c  */
#line 5018 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 975:

/* Line 1788 of yacc.c  */
#line 5022 "parser.y"
    { (yyval) = NULL; }
    break;

  case 976:

/* Line 1788 of yacc.c  */
#line 5023 "parser.y"
    { (yyval) = NULL; }
    break;

  case 977:

/* Line 1788 of yacc.c  */
#line 5024 "parser.y"
    { PENDING ("OPEN ... WITH LOCK"); }
    break;

  case 978:

/* Line 1788 of yacc.c  */
#line 5036 "parser.y"
    { BEGIN_STATEMENT ("PERFORM", TERM_PERFORM); }
    break;

  case 980:

/* Line 1788 of yacc.c  */
#line 5042 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 981:

/* Line 1788 of yacc.c  */
#line 5046 "parser.y"
    {
	perform_stack = cb_cons ((yyvsp[(1) - (1)]), perform_stack);
	check_unreached = 0;
  }
    break;

  case 982:

/* Line 1788 of yacc.c  */
#line 5051 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 983:

/* Line 1788 of yacc.c  */
#line 5056 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
  }
    break;

  case 984:

/* Line 1788 of yacc.c  */
#line 5062 "parser.y"
    { terminator_error (); }
    break;

  case 985:

/* Line 1788 of yacc.c  */
#line 5063 "parser.y"
    { terminator_clear (TERM_PERFORM); }
    break;

  case 986:

/* Line 1788 of yacc.c  */
#line 5068 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true; /* return from $1 */
	(yyval) = cb_build_pair ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  }
    break;

  case 987:

/* Line 1788 of yacc.c  */
#line 5073 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true; /* return from $3 */
	(yyval) = cb_build_pair ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 988:

/* Line 1788 of yacc.c  */
#line 5081 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  }
    break;

  case 989:

/* Line 1788 of yacc.c  */
#line 5085 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  }
    break;

  case 990:

/* Line 1788 of yacc.c  */
#line 5089 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  }
    break;

  case 991:

/* Line 1788 of yacc.c  */
#line 5094 "parser.y"
    {
	cb_tree varying;

	varying = cb_list_init (cb_build_perform_varying (NULL, NULL, NULL, (yyvsp[(3) - (3)])));
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), varying);
  }
    break;

  case 992:

/* Line 1788 of yacc.c  */
#line 5101 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 993:

/* Line 1788 of yacc.c  */
#line 5107 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 994:

/* Line 1788 of yacc.c  */
#line 5108 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 995:

/* Line 1788 of yacc.c  */
#line 5112 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 996:

/* Line 1788 of yacc.c  */
#line 5114 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 997:

/* Line 1788 of yacc.c  */
#line 5119 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 998:

/* Line 1788 of yacc.c  */
#line 5130 "parser.y"
    { BEGIN_STATEMENT ("READ", TERM_READ); }
    break;

  case 999:

/* Line 1788 of yacc.c  */
#line 5133 "parser.y"
    {
	if ((yyvsp[(3) - (10)]) != cb_error_node) {
		if ((yyvsp[(7) - (10)]) && (CB_FILE(cb_ref ((yyvsp[(3) - (10)])))->lock_mode & COB_LOCK_AUTOMATIC)) {
			cb_error (_("LOCK clause invalid with file LOCK AUTOMATIC"));
		} else if ((yyvsp[(8) - (10)]) &&
		      (CB_FILE(cb_ref ((yyvsp[(3) - (10)])))->organization != COB_ORG_RELATIVE &&
		       CB_FILE(cb_ref ((yyvsp[(3) - (10)])))->organization != COB_ORG_INDEXED)) {
			cb_error (_("KEY clause invalid with this file type"));
		} else if (current_statement->handler_id == COB_EC_I_O_INVALID_KEY &&
		      (CB_FILE(cb_ref ((yyvsp[(3) - (10)])))->organization != COB_ORG_RELATIVE &&
		       CB_FILE(cb_ref ((yyvsp[(3) - (10)])))->organization != COB_ORG_INDEXED)) {
			cb_error (_("INVALID KEY clause invalid with this file type"));
		} else {
			cb_emit_read ((yyvsp[(3) - (10)]), (yyvsp[(4) - (10)]), (yyvsp[(6) - (10)]), (yyvsp[(8) - (10)]), (yyvsp[(7) - (10)]));
		}
	}
  }
    break;

  case 1000:

/* Line 1788 of yacc.c  */
#line 5153 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1001:

/* Line 1788 of yacc.c  */
#line 5154 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1002:

/* Line 1788 of yacc.c  */
#line 5158 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1003:

/* Line 1788 of yacc.c  */
#line 5160 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1004:

/* Line 1788 of yacc.c  */
#line 5164 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1005:

/* Line 1788 of yacc.c  */
#line 5168 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1006:

/* Line 1788 of yacc.c  */
#line 5172 "parser.y"
    {
	(yyval) = cb_int3;
  }
    break;

  case 1007:

/* Line 1788 of yacc.c  */
#line 5176 "parser.y"
    {
	(yyval) = cb_int4;
  }
    break;

  case 1008:

/* Line 1788 of yacc.c  */
#line 5182 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1009:

/* Line 1788 of yacc.c  */
#line 5183 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1013:

/* Line 1788 of yacc.c  */
#line 5192 "parser.y"
    { terminator_warning (TERM_READ); }
    break;

  case 1014:

/* Line 1788 of yacc.c  */
#line 5193 "parser.y"
    { terminator_clear (TERM_READ); }
    break;

  case 1015:

/* Line 1788 of yacc.c  */
#line 5202 "parser.y"
    { BEGIN_STATEMENT ("RELEASE", 0); }
    break;

  case 1016:

/* Line 1788 of yacc.c  */
#line 5204 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) != cb_error_node) {
		cb_emit_release ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	}
  }
    break;

  case 1017:

/* Line 1788 of yacc.c  */
#line 5217 "parser.y"
    { BEGIN_STATEMENT ("RETURN", TERM_RETURN); }
    break;

  case 1018:

/* Line 1788 of yacc.c  */
#line 5220 "parser.y"
    {
	if ((yyvsp[(3) - (7)]) != cb_error_node) {
		cb_emit_return ((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]));
	}
  }
    break;

  case 1019:

/* Line 1788 of yacc.c  */
#line 5228 "parser.y"
    { terminator_warning (TERM_RETURN); }
    break;

  case 1020:

/* Line 1788 of yacc.c  */
#line 5229 "parser.y"
    { terminator_clear (TERM_RETURN); }
    break;

  case 1021:

/* Line 1788 of yacc.c  */
#line 5238 "parser.y"
    { BEGIN_STATEMENT ("REWRITE", TERM_REWRITE); }
    break;

  case 1022:

/* Line 1788 of yacc.c  */
#line 5241 "parser.y"
    {
	if ((yyvsp[(3) - (7)]) != cb_error_node) {
		cb_emit_rewrite ((yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]));
	}
  }
    break;

  case 1023:

/* Line 1788 of yacc.c  */
#line 5249 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1024:

/* Line 1788 of yacc.c  */
#line 5251 "parser.y"
    {
	(yyval) = cb_int1;
  }
    break;

  case 1025:

/* Line 1788 of yacc.c  */
#line 5255 "parser.y"
    {
	(yyval) = cb_int2;
  }
    break;

  case 1026:

/* Line 1788 of yacc.c  */
#line 5261 "parser.y"
    { terminator_warning (TERM_REWRITE); }
    break;

  case 1027:

/* Line 1788 of yacc.c  */
#line 5262 "parser.y"
    { terminator_clear (TERM_REWRITE); }
    break;

  case 1028:

/* Line 1788 of yacc.c  */
#line 5272 "parser.y"
    {
	BEGIN_STATEMENT ("ROLLBACK", 0);
	cb_emit_rollback ();
  }
    break;

  case 1029:

/* Line 1788 of yacc.c  */
#line 5284 "parser.y"
    { BEGIN_STATEMENT ("SEARCH", TERM_SEARCH); }
    break;

  case 1031:

/* Line 1788 of yacc.c  */
#line 5291 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1032:

/* Line 1788 of yacc.c  */
#line 5295 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1033:

/* Line 1788 of yacc.c  */
#line 5299 "parser.y"
    {
	cb_emit_search_all ((yyvsp[(2) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  }
    break;

  case 1034:

/* Line 1788 of yacc.c  */
#line 5305 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1035:

/* Line 1788 of yacc.c  */
#line 5306 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1036:

/* Line 1788 of yacc.c  */
#line 5310 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1037:

/* Line 1788 of yacc.c  */
#line 5312 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1038:

/* Line 1788 of yacc.c  */
#line 5316 "parser.y"
    {
	(yyval) = (yyvsp[(4) - (4)]);
  }
    break;

  case 1039:

/* Line 1788 of yacc.c  */
#line 5322 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1040:

/* Line 1788 of yacc.c  */
#line 5323 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); CB_IF ((yyvsp[(1) - (2)]))->stmt2 = (yyvsp[(2) - (2)]); }
    break;

  case 1041:

/* Line 1788 of yacc.c  */
#line 5328 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1042:

/* Line 1788 of yacc.c  */
#line 5332 "parser.y"
    {
	(yyval) = cb_build_if ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]), NULL);
  }
    break;

  case 1043:

/* Line 1788 of yacc.c  */
#line 5338 "parser.y"
    { terminator_warning (TERM_SEARCH); }
    break;

  case 1044:

/* Line 1788 of yacc.c  */
#line 5339 "parser.y"
    { terminator_clear (TERM_SEARCH); }
    break;

  case 1045:

/* Line 1788 of yacc.c  */
#line 5348 "parser.y"
    { BEGIN_STATEMENT ("SET", 0); }
    break;

  case 1052:

/* Line 1788 of yacc.c  */
#line 5364 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1053:

/* Line 1788 of yacc.c  */
#line 5373 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  }
    break;

  case 1054:

/* Line 1788 of yacc.c  */
#line 5377 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1055:

/* Line 1788 of yacc.c  */
#line 5386 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  }
    break;

  case 1056:

/* Line 1788 of yacc.c  */
#line 5392 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1057:

/* Line 1788 of yacc.c  */
#line 5393 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1060:

/* Line 1788 of yacc.c  */
#line 5405 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1063:

/* Line 1788 of yacc.c  */
#line 5419 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  }
    break;

  case 1064:

/* Line 1788 of yacc.c  */
#line 5423 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  }
    break;

  case 1065:

/* Line 1788 of yacc.c  */
#line 5434 "parser.y"
    { BEGIN_STATEMENT ("SORT", 0); }
    break;

  case 1067:

/* Line 1788 of yacc.c  */
#line 5440 "parser.y"
    {
	cb_emit_sort_init ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (4)]))) && (yyvsp[(2) - (4)]) == NULL) {
		cb_error (_("File sort requires KEY phrase"));
	}
	/* used in sort_input/sort_output */
	save_tree_1 = (yyvsp[(1) - (4)]);
  }
    break;

  case 1068:

/* Line 1788 of yacc.c  */
#line 5449 "parser.y"
    {
	cb_emit_sort_finish ((yyvsp[(1) - (7)]));
  }
    break;

  case 1069:

/* Line 1788 of yacc.c  */
#line 5456 "parser.y"
    {
	(yyval) = NULL;
  }
    break;

  case 1070:

/* Line 1788 of yacc.c  */
#line 5461 "parser.y"
    {
	cb_tree l;

	if ((yyvsp[(5) - (5)]) == NULL) {
		(yyvsp[(5) - (5)]) = cb_list_init (NULL);
	}
	for (l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = (yyvsp[(3) - (5)]);
	}
	(yyval) = cb_list_append ((yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1071:

/* Line 1788 of yacc.c  */
#line 5475 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1072:

/* Line 1788 of yacc.c  */
#line 5476 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1074:

/* Line 1788 of yacc.c  */
#line 5480 "parser.y"
    { /* nothing */ }
    break;

  case 1075:

/* Line 1788 of yacc.c  */
#line 5484 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1076:

/* Line 1788 of yacc.c  */
#line 5485 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); }
    break;

  case 1077:

/* Line 1788 of yacc.c  */
#line 5490 "parser.y"
    {
	if (CB_FILE_P (cb_ref (save_tree_1))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  }
    break;

  case 1078:

/* Line 1788 of yacc.c  */
#line 5496 "parser.y"
    {
	if (!CB_FILE_P (cb_ref (save_tree_1))) {
		cb_error (_("USING invalid with table SORT"));
	} else {
		cb_emit_sort_using (save_tree_1, (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1079:

/* Line 1788 of yacc.c  */
#line 5504 "parser.y"
    {
	if (!CB_FILE_P (cb_ref (save_tree_1))) {
		cb_error (_("INPUT PROCEDURE invalid with table SORT"));
	} else {
		cb_emit_sort_input ((yyvsp[(4) - (4)]));
	}
  }
    break;

  case 1080:

/* Line 1788 of yacc.c  */
#line 5515 "parser.y"
    {
	if (CB_FILE_P (cb_ref (save_tree_1))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  }
    break;

  case 1081:

/* Line 1788 of yacc.c  */
#line 5521 "parser.y"
    {
	if (!CB_FILE_P (cb_ref (save_tree_1))) {
		cb_error (_("GIVING invalid with table SORT"));
	} else {
		cb_emit_sort_giving (save_tree_1, (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1082:

/* Line 1788 of yacc.c  */
#line 5529 "parser.y"
    {
	if (!CB_FILE_P (cb_ref (save_tree_1))) {
		cb_error (_("OUTPUT PROCEDURE invalid with table SORT"));
	} else {
		cb_emit_sort_output ((yyvsp[(4) - (4)]));
	}
  }
    break;

  case 1083:

/* Line 1788 of yacc.c  */
#line 5544 "parser.y"
    { BEGIN_STATEMENT ("START", TERM_START); }
    break;

  case 1084:

/* Line 1788 of yacc.c  */
#line 5545 "parser.y"
    { (yyval) = cb_int (COB_EQ); }
    break;

  case 1085:

/* Line 1788 of yacc.c  */
#line 5548 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (7)])))) {
		if (CB_FILE (cb_ref ((yyvsp[(3) - (7)])))->organization != COB_ORG_INDEXED &&
		     CB_FILE (cb_ref ((yyvsp[(3) - (7)])))->organization != COB_ORG_RELATIVE) {
			cb_error (_("START not allowed on SEQUENTIAL files"));
			(yyval) = cb_error_node;
		} else {
			cb_emit_start ((yyvsp[(3) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]));
		}
	} else {
		cb_error_x ((yyvsp[(3) - (7)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (7)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1086:

/* Line 1788 of yacc.c  */
#line 5565 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1087:

/* Line 1788 of yacc.c  */
#line 5566 "parser.y"
    { (yyvsp[(0) - (4)]) = (yyvsp[(3) - (4)]); (yyval) = (yyvsp[(4) - (4)]); }
    break;

  case 1088:

/* Line 1788 of yacc.c  */
#line 5570 "parser.y"
    { (yyval) = cb_int (((yyvsp[(1) - (2)]) == cb_int1) ? COB_NE : COB_EQ); }
    break;

  case 1089:

/* Line 1788 of yacc.c  */
#line 5571 "parser.y"
    { (yyval) = cb_int (((yyvsp[(1) - (2)]) == cb_int1) ? COB_LE : COB_GT); }
    break;

  case 1090:

/* Line 1788 of yacc.c  */
#line 5572 "parser.y"
    { (yyval) = cb_int (((yyvsp[(1) - (2)]) == cb_int1) ? COB_GE : COB_LT); }
    break;

  case 1091:

/* Line 1788 of yacc.c  */
#line 5573 "parser.y"
    { (yyval) = cb_int (((yyvsp[(1) - (2)]) == cb_int1) ? COB_LT : COB_GE); }
    break;

  case 1092:

/* Line 1788 of yacc.c  */
#line 5574 "parser.y"
    { (yyval) = cb_int (((yyvsp[(1) - (2)]) == cb_int1) ? COB_GT : COB_LE); }
    break;

  case 1093:

/* Line 1788 of yacc.c  */
#line 5578 "parser.y"
    { terminator_warning (TERM_START); }
    break;

  case 1094:

/* Line 1788 of yacc.c  */
#line 5579 "parser.y"
    { terminator_clear (TERM_START); }
    break;

  case 1095:

/* Line 1788 of yacc.c  */
#line 5588 "parser.y"
    { BEGIN_STATEMENT ("STOP", 0); }
    break;

  case 1096:

/* Line 1788 of yacc.c  */
#line 5590 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
  }
    break;

  case 1097:

/* Line 1788 of yacc.c  */
#line 5594 "parser.y"
    {
	cb_verify (cb_stop_literal_statement, "STOP literal");
  }
    break;

  case 1098:

/* Line 1788 of yacc.c  */
#line 5600 "parser.y"
    { (yyval) = current_program->cb_return_code; }
    break;

  case 1099:

/* Line 1788 of yacc.c  */
#line 5601 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1100:

/* Line 1788 of yacc.c  */
#line 5602 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1101:

/* Line 1788 of yacc.c  */
#line 5611 "parser.y"
    { BEGIN_STATEMENT ("STRING", TERM_STRING); }
    break;

  case 1102:

/* Line 1788 of yacc.c  */
#line 5614 "parser.y"
    {
	cb_emit_string ((yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(6) - (8)]));
  }
    break;

  case 1103:

/* Line 1788 of yacc.c  */
#line 5620 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1104:

/* Line 1788 of yacc.c  */
#line 5621 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1105:

/* Line 1788 of yacc.c  */
#line 5625 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1106:

/* Line 1788 of yacc.c  */
#line 5626 "parser.y"
    { (yyval) = cb_build_pair (cb_int0, NULL); }
    break;

  case 1107:

/* Line 1788 of yacc.c  */
#line 5627 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(3) - (3)]), NULL); }
    break;

  case 1108:

/* Line 1788 of yacc.c  */
#line 5631 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1109:

/* Line 1788 of yacc.c  */
#line 5632 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1110:

/* Line 1788 of yacc.c  */
#line 5636 "parser.y"
    { terminator_warning (TERM_STRING); }
    break;

  case 1111:

/* Line 1788 of yacc.c  */
#line 5637 "parser.y"
    { terminator_clear (TERM_STRING); }
    break;

  case 1112:

/* Line 1788 of yacc.c  */
#line 5646 "parser.y"
    { BEGIN_STATEMENT ("SUBTRACT", TERM_SUBTRACT); }
    break;

  case 1114:

/* Line 1788 of yacc.c  */
#line 5653 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  }
    break;

  case 1115:

/* Line 1788 of yacc.c  */
#line 5657 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (cb_cons ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  }
    break;

  case 1116:

/* Line 1788 of yacc.c  */
#line 5661 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  }
    break;

  case 1117:

/* Line 1788 of yacc.c  */
#line 5667 "parser.y"
    { terminator_warning (TERM_SUBTRACT); }
    break;

  case 1118:

/* Line 1788 of yacc.c  */
#line 5668 "parser.y"
    { terminator_clear (TERM_SUBTRACT); }
    break;

  case 1119:

/* Line 1788 of yacc.c  */
#line 5678 "parser.y"
    {
	BEGIN_STATEMENT ("SUPPRESS", 0);
	PENDING("SUPPRESS");
  }
    break;

  case 1122:

/* Line 1788 of yacc.c  */
#line 5693 "parser.y"
    { BEGIN_STATEMENT ("TERMINATE", 0); }
    break;

  case 1123:

/* Line 1788 of yacc.c  */
#line 5695 "parser.y"
    {
	PENDING("TERMINATE");
  }
    break;

  case 1124:

/* Line 1788 of yacc.c  */
#line 5706 "parser.y"
    { BEGIN_STATEMENT ("TRANSFORM", 0); }
    break;

  case 1125:

/* Line 1788 of yacc.c  */
#line 5708 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(3) - (7)]), x, cb_int0, 2);
  }
    break;

  case 1126:

/* Line 1788 of yacc.c  */
#line 5722 "parser.y"
    { BEGIN_STATEMENT ("UNLOCK", 0); }
    break;

  case 1127:

/* Line 1788 of yacc.c  */
#line 5724 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) != cb_error_node) {
		cb_emit_unlock ((yyvsp[(3) - (4)]));
	}
  }
    break;

  case 1131:

/* Line 1788 of yacc.c  */
#line 5743 "parser.y"
    { BEGIN_STATEMENT ("UNSTRING", TERM_UNSTRING); }
    break;

  case 1132:

/* Line 1788 of yacc.c  */
#line 5747 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]));
  }
    break;

  case 1133:

/* Line 1788 of yacc.c  */
#line 5753 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1134:

/* Line 1788 of yacc.c  */
#line 5755 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1135:

/* Line 1788 of yacc.c  */
#line 5759 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1136:

/* Line 1788 of yacc.c  */
#line 5761 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1137:

/* Line 1788 of yacc.c  */
#line 5766 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 1138:

/* Line 1788 of yacc.c  */
#line 5772 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(2) - (2)])); }
    break;

  case 1139:

/* Line 1788 of yacc.c  */
#line 5774 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1140:

/* Line 1788 of yacc.c  */
#line 5779 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1141:

/* Line 1788 of yacc.c  */
#line 5785 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1142:

/* Line 1788 of yacc.c  */
#line 5786 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1143:

/* Line 1788 of yacc.c  */
#line 5790 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1144:

/* Line 1788 of yacc.c  */
#line 5791 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1145:

/* Line 1788 of yacc.c  */
#line 5795 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1146:

/* Line 1788 of yacc.c  */
#line 5796 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 1147:

/* Line 1788 of yacc.c  */
#line 5800 "parser.y"
    { terminator_warning (TERM_UNSTRING); }
    break;

  case 1148:

/* Line 1788 of yacc.c  */
#line 5801 "parser.y"
    { terminator_clear (TERM_UNSTRING); }
    break;

  case 1152:

/* Line 1788 of yacc.c  */
#line 5819 "parser.y"
    {
	if (!in_declaratives) {
		cb_error (_("USE statement must be within DECLARATIVES"));
	} else if (!current_section) {
		cb_error (_("SECTION header missing before USE statement"));
	} else {
		current_section->need_begin = 1;
		current_section->need_return = 1;
		CB_EXCEPTION_ENABLE (COB_EC_I_O) = 1;
		if (use_global_ind) {
			current_section->is_global = 1;
			current_program->global_list =
				cb_list_add (current_program->global_list,
					     CB_TREE (current_section));
		}
	}
  }
    break;

  case 1153:

/* Line 1788 of yacc.c  */
#line 5840 "parser.y"
    {
	use_global_ind = 0;
  }
    break;

  case 1154:

/* Line 1788 of yacc.c  */
#line 5844 "parser.y"
    {
	use_global_ind = 1;
	current_program->flag_global_use = 1;
  }
    break;

  case 1155:

/* Line 1788 of yacc.c  */
#line 5852 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALUE (l) != cb_error_node) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  }
    break;

  case 1156:

/* Line 1788 of yacc.c  */
#line 5862 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  }
    break;

  case 1157:

/* Line 1788 of yacc.c  */
#line 5867 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  }
    break;

  case 1158:

/* Line 1788 of yacc.c  */
#line 5872 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  }
    break;

  case 1159:

/* Line 1788 of yacc.c  */
#line 5877 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  }
    break;

  case 1172:

/* Line 1788 of yacc.c  */
#line 5909 "parser.y"
    {
	PENDING ("USE FOR DEBUGGING");
  }
    break;

  case 1175:

/* Line 1788 of yacc.c  */
#line 5921 "parser.y"
    {
	PENDING ("USE BEFORE REPORTING");
  }
    break;

  case 1176:

/* Line 1788 of yacc.c  */
#line 5932 "parser.y"
    { BEGIN_STATEMENT ("WRITE", TERM_WRITE); }
    break;

  case 1177:

/* Line 1788 of yacc.c  */
#line 5935 "parser.y"
    {
	if ((yyvsp[(3) - (8)]) != cb_error_node) {
		cb_emit_write ((yyvsp[(3) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(5) - (8)]));
	}
  }
    break;

  case 1178:

/* Line 1788 of yacc.c  */
#line 5943 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1179:

/* Line 1788 of yacc.c  */
#line 5944 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1180:

/* Line 1788 of yacc.c  */
#line 5949 "parser.y"
    {
	(yyval) = cb_int0;
  }
    break;

  case 1181:

/* Line 1788 of yacc.c  */
#line 5953 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  }
    break;

  case 1182:

/* Line 1788 of yacc.c  */
#line 5957 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 1183:

/* Line 1788 of yacc.c  */
#line 5961 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  }
    break;

  case 1184:

/* Line 1788 of yacc.c  */
#line 5967 "parser.y"
    { (yyval) = CB_BEFORE; }
    break;

  case 1185:

/* Line 1788 of yacc.c  */
#line 5968 "parser.y"
    { (yyval) = CB_AFTER; }
    break;

  case 1189:

/* Line 1788 of yacc.c  */
#line 5977 "parser.y"
    { terminator_warning (TERM_WRITE); }
    break;

  case 1190:

/* Line 1788 of yacc.c  */
#line 5978 "parser.y"
    { terminator_clear (TERM_WRITE); }
    break;

  case 1191:

/* Line 1788 of yacc.c  */
#line 5993 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
  }
    break;

  case 1192:

/* Line 1788 of yacc.c  */
#line 6001 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
  }
    break;

  case 1194:

/* Line 1788 of yacc.c  */
#line 6008 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1195:

/* Line 1788 of yacc.c  */
#line 6012 "parser.y"
    {
	current_statement->handler1 = (yyvsp[(3) - (3)]);
  }
    break;

  case 1197:

/* Line 1788 of yacc.c  */
#line 6019 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1198:

/* Line 1788 of yacc.c  */
#line 6023 "parser.y"
    {
	current_statement->handler2 = (yyvsp[(3) - (3)]);
  }
    break;

  case 1199:

/* Line 1788 of yacc.c  */
#line 6035 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
  }
    break;

  case 1201:

/* Line 1788 of yacc.c  */
#line 6042 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1202:

/* Line 1788 of yacc.c  */
#line 6046 "parser.y"
    {
	current_statement->handler1 = (yyvsp[(3) - (3)]);
  }
    break;

  case 1204:

/* Line 1788 of yacc.c  */
#line 6053 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1205:

/* Line 1788 of yacc.c  */
#line 6057 "parser.y"
    {
	current_statement->handler2 = (yyvsp[(3) - (3)]);
  }
    break;

  case 1206:

/* Line 1788 of yacc.c  */
#line 6069 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
  }
    break;

  case 1208:

/* Line 1788 of yacc.c  */
#line 6076 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1209:

/* Line 1788 of yacc.c  */
#line 6080 "parser.y"
    {
	current_statement->handler1 = (yyvsp[(3) - (3)]);
  }
    break;

  case 1211:

/* Line 1788 of yacc.c  */
#line 6087 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1212:

/* Line 1788 of yacc.c  */
#line 6091 "parser.y"
    {
	current_statement->handler2 = (yyvsp[(3) - (3)]);
  }
    break;

  case 1213:

/* Line 1788 of yacc.c  */
#line 6103 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(1) - (1)]);
  }
    break;

  case 1214:

/* Line 1788 of yacc.c  */
#line 6108 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(1) - (1)]);
  }
    break;

  case 1215:

/* Line 1788 of yacc.c  */
#line 6113 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(1) - (2)]);
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1216:

/* Line 1788 of yacc.c  */
#line 6122 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1217:

/* Line 1788 of yacc.c  */
#line 6126 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1218:

/* Line 1788 of yacc.c  */
#line 6133 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1219:

/* Line 1788 of yacc.c  */
#line 6137 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1220:

/* Line 1788 of yacc.c  */
#line 6149 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(1) - (1)]);
  }
    break;

  case 1221:

/* Line 1788 of yacc.c  */
#line 6154 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(1) - (1)]);
  }
    break;

  case 1222:

/* Line 1788 of yacc.c  */
#line 6159 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(1) - (2)]);
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1223:

/* Line 1788 of yacc.c  */
#line 6168 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1224:

/* Line 1788 of yacc.c  */
#line 6172 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1225:

/* Line 1788 of yacc.c  */
#line 6179 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1226:

/* Line 1788 of yacc.c  */
#line 6183 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1229:

/* Line 1788 of yacc.c  */
#line 6199 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(1) - (1)]);
  }
    break;

  case 1230:

/* Line 1788 of yacc.c  */
#line 6204 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(1) - (1)]);
  }
    break;

  case 1231:

/* Line 1788 of yacc.c  */
#line 6209 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(1) - (2)]);
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  }
    break;

  case 1232:

/* Line 1788 of yacc.c  */
#line 6218 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1233:

/* Line 1788 of yacc.c  */
#line 6222 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1234:

/* Line 1788 of yacc.c  */
#line 6229 "parser.y"
    {
	check_unreached = 0;
  }
    break;

  case 1235:

/* Line 1788 of yacc.c  */
#line 6233 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 1236:

/* Line 1788 of yacc.c  */
#line 6245 "parser.y"
    {
	(yyval) = cb_one;
  }
    break;

  case 1237:

/* Line 1788 of yacc.c  */
#line 6249 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 1238:

/* Line 1788 of yacc.c  */
#line 6261 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  }
    break;

  case 1239:

/* Line 1788 of yacc.c  */
#line 6268 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  }
    break;

  case 1240:

/* Line 1788 of yacc.c  */
#line 6274 "parser.y"
    {
	current_expr = NULL;
  }
    break;

  case 1241:

/* Line 1788 of yacc.c  */
#line 6278 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  }
    break;

  case 1245:

/* Line 1788 of yacc.c  */
#line 6290 "parser.y"
    { push_expr ('x', (yyvsp[(1) - (1)])); }
    break;

  case 1246:

/* Line 1788 of yacc.c  */
#line 6292 "parser.y"
    { push_expr ('(', NULL); }
    break;

  case 1247:

/* Line 1788 of yacc.c  */
#line 6293 "parser.y"
    { push_expr (')', NULL); }
    break;

  case 1248:

/* Line 1788 of yacc.c  */
#line 6295 "parser.y"
    { push_expr ('+', NULL); }
    break;

  case 1249:

/* Line 1788 of yacc.c  */
#line 6296 "parser.y"
    { push_expr ('-', NULL); }
    break;

  case 1250:

/* Line 1788 of yacc.c  */
#line 6297 "parser.y"
    { push_expr ('*', NULL); }
    break;

  case 1251:

/* Line 1788 of yacc.c  */
#line 6298 "parser.y"
    { push_expr ('/', NULL); }
    break;

  case 1252:

/* Line 1788 of yacc.c  */
#line 6299 "parser.y"
    { push_expr ('^', NULL); }
    break;

  case 1253:

/* Line 1788 of yacc.c  */
#line 6301 "parser.y"
    { push_expr ('=', NULL); }
    break;

  case 1254:

/* Line 1788 of yacc.c  */
#line 6302 "parser.y"
    { push_expr ('>', NULL); }
    break;

  case 1255:

/* Line 1788 of yacc.c  */
#line 6303 "parser.y"
    { push_expr ('<', NULL); }
    break;

  case 1256:

/* Line 1788 of yacc.c  */
#line 6304 "parser.y"
    { push_expr (']', NULL); }
    break;

  case 1257:

/* Line 1788 of yacc.c  */
#line 6305 "parser.y"
    { push_expr ('[', NULL); }
    break;

  case 1258:

/* Line 1788 of yacc.c  */
#line 6306 "parser.y"
    { push_expr ('~', NULL); }
    break;

  case 1259:

/* Line 1788 of yacc.c  */
#line 6308 "parser.y"
    { push_expr ('!', NULL); }
    break;

  case 1260:

/* Line 1788 of yacc.c  */
#line 6309 "parser.y"
    { push_expr ('&', NULL); }
    break;

  case 1261:

/* Line 1788 of yacc.c  */
#line 6310 "parser.y"
    { push_expr ('|', NULL); }
    break;

  case 1262:

/* Line 1788 of yacc.c  */
#line 6312 "parser.y"
    { push_expr ('O', NULL); }
    break;

  case 1263:

/* Line 1788 of yacc.c  */
#line 6313 "parser.y"
    { push_expr ('9', NULL); }
    break;

  case 1264:

/* Line 1788 of yacc.c  */
#line 6314 "parser.y"
    { push_expr ('A', NULL); }
    break;

  case 1265:

/* Line 1788 of yacc.c  */
#line 6315 "parser.y"
    { push_expr ('L', NULL); }
    break;

  case 1266:

/* Line 1788 of yacc.c  */
#line 6316 "parser.y"
    { push_expr ('U', NULL); }
    break;

  case 1267:

/* Line 1788 of yacc.c  */
#line 6319 "parser.y"
    { push_expr ('P', NULL); }
    break;

  case 1268:

/* Line 1788 of yacc.c  */
#line 6320 "parser.y"
    { push_expr ('N', NULL); }
    break;

  case 1280:

/* Line 1788 of yacc.c  */
#line 6332 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1281:

/* Line 1788 of yacc.c  */
#line 6333 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1285:

/* Line 1788 of yacc.c  */
#line 6342 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1286:

/* Line 1788 of yacc.c  */
#line 6343 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); }
    break;

  case 1287:

/* Line 1788 of yacc.c  */
#line 6344 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); }
    break;

  case 1288:

/* Line 1788 of yacc.c  */
#line 6345 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); }
    break;

  case 1289:

/* Line 1788 of yacc.c  */
#line 6346 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); }
    break;

  case 1290:

/* Line 1788 of yacc.c  */
#line 6347 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 1291:

/* Line 1788 of yacc.c  */
#line 6348 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); }
    break;

  case 1292:

/* Line 1788 of yacc.c  */
#line 6349 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)])); }
    break;

  case 1293:

/* Line 1788 of yacc.c  */
#line 6350 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1294:

/* Line 1788 of yacc.c  */
#line 6362 "parser.y"
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

  case 1295:

/* Line 1788 of yacc.c  */
#line 6374 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1296:

/* Line 1788 of yacc.c  */
#line 6388 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1297:

/* Line 1788 of yacc.c  */
#line 6390 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1298:

/* Line 1788 of yacc.c  */
#line 6394 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); }
    break;

  case 1299:

/* Line 1788 of yacc.c  */
#line 6400 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)])); }
    break;

  case 1300:

/* Line 1788 of yacc.c  */
#line 6407 "parser.y"
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

  case 1301:

/* Line 1788 of yacc.c  */
#line 6427 "parser.y"
    {
	(yyval) = cb_list_init ((yyvsp[(1) - (1)]));
  }
    break;

  case 1302:

/* Line 1788 of yacc.c  */
#line 6431 "parser.y"
    {
	cb_tree		l;

	if ((yyvsp[(2) - (2)]) != cb_error_node) {
		for (l = (yyvsp[(1) - (2)]); l; l = CB_CHAIN (l)) {
			if (!strcasecmp (CB_NAME ((yyvsp[(2) - (2)])), CB_NAME (CB_VALUE (l)))) {
				cb_error_x ((yyvsp[(2) - (2)]), _("Multiple reference to '%s' "), CB_NAME ((yyvsp[(2) - (2)])));
			}
		}
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  }
    break;

  case 1303:

/* Line 1788 of yacc.c  */
#line 6447 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1304:

/* Line 1788 of yacc.c  */
#line 6460 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1305:

/* Line 1788 of yacc.c  */
#line 6462 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1306:

/* Line 1788 of yacc.c  */
#line 6466 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1307:

/* Line 1788 of yacc.c  */
#line 6472 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1308:

/* Line 1788 of yacc.c  */
#line 6474 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1309:

/* Line 1788 of yacc.c  */
#line 6479 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	current_program->label_list = cb_cons ((yyval), current_program->label_list);
  }
    break;

  case 1313:

/* Line 1788 of yacc.c  */
#line 6494 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  }
    break;

  case 1314:

/* Line 1788 of yacc.c  */
#line 6504 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1315:

/* Line 1788 of yacc.c  */
#line 6505 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1316:

/* Line 1788 of yacc.c  */
#line 6510 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	current_program->reference_list = cb_cons ((yyval), current_program->reference_list);
  }
    break;

  case 1317:

/* Line 1788 of yacc.c  */
#line 6517 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1318:

/* Line 1788 of yacc.c  */
#line 6518 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1321:

/* Line 1788 of yacc.c  */
#line 6530 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (CB_REFERENCE ((yyval))->word->count > 0) {
		redefinition_error ((yyval));
		(yyval) = cb_error_node;
	}
  }
    break;

  case 1322:

/* Line 1788 of yacc.c  */
#line 6549 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1323:

/* Line 1788 of yacc.c  */
#line 6550 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1325:

/* Line 1788 of yacc.c  */
#line 6555 "parser.y"
    { (yyval) = cb_build_address ((yyvsp[(3) - (3)])); }
    break;

  case 1326:

/* Line 1788 of yacc.c  */
#line 6559 "parser.y"
    { (yyval) = cb_list_init ((yyvsp[(1) - (1)])); }
    break;

  case 1327:

/* Line 1788 of yacc.c  */
#line 6560 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 1329:

/* Line 1788 of yacc.c  */
#line 6565 "parser.y"
    { (yyval) = cb_build_length ((yyvsp[(3) - (3)])); }
    break;

  case 1330:

/* Line 1788 of yacc.c  */
#line 6566 "parser.y"
    { (yyval) = cb_build_length ((yyvsp[(3) - (3)])); }
    break;

  case 1331:

/* Line 1788 of yacc.c  */
#line 6567 "parser.y"
    { (yyval) = cb_build_length ((yyvsp[(3) - (3)])); }
    break;

  case 1332:

/* Line 1788 of yacc.c  */
#line 6568 "parser.y"
    { (yyval) = cb_build_ppointer ((yyvsp[(4) - (4)])); }
    break;

  case 1333:

/* Line 1788 of yacc.c  */
#line 6569 "parser.y"
    { (yyval) = cb_build_address ((yyvsp[(3) - (3)])); }
    break;

  case 1338:

/* Line 1788 of yacc.c  */
#line 6577 "parser.y"
    { (yyval) = cb_build_length ((yyvsp[(3) - (3)])); }
    break;

  case 1339:

/* Line 1788 of yacc.c  */
#line 6578 "parser.y"
    { (yyval) = cb_build_length ((yyvsp[(3) - (3)])); }
    break;

  case 1340:

/* Line 1788 of yacc.c  */
#line 6579 "parser.y"
    { (yyval) = cb_build_length ((yyvsp[(3) - (3)])); }
    break;

  case 1346:

/* Line 1788 of yacc.c  */
#line 6591 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1347:

/* Line 1788 of yacc.c  */
#line 6592 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1359:

/* Line 1788 of yacc.c  */
#line 6626 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1360:

/* Line 1788 of yacc.c  */
#line 6634 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)])); }
    break;

  case 1361:

/* Line 1788 of yacc.c  */
#line 6638 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1362:

/* Line 1788 of yacc.c  */
#line 6639 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1363:

/* Line 1788 of yacc.c  */
#line 6640 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 1364:

/* Line 1788 of yacc.c  */
#line 6641 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 1365:

/* Line 1788 of yacc.c  */
#line 6645 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1366:

/* Line 1788 of yacc.c  */
#line 6646 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]); }
    break;

  case 1367:

/* Line 1788 of yacc.c  */
#line 6651 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  }
    break;

  case 1368:

/* Line 1788 of yacc.c  */
#line 6659 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  }
    break;

  case 1369:

/* Line 1788 of yacc.c  */
#line 6663 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  }
    break;

  case 1370:

/* Line 1788 of yacc.c  */
#line 6675 "parser.y"
    {
	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign < 0 || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Integer value expected"));
	}
	(yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 1371:

/* Line 1788 of yacc.c  */
#line 6686 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1372:

/* Line 1788 of yacc.c  */
#line 6688 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
	if (CB_LITERAL_P ((yyvsp[(2) - (2)]))) {
		CB_LITERAL ((yyvsp[(2) - (2)]))->all = 1;
	}
  }
    break;

  case 1373:

/* Line 1788 of yacc.c  */
#line 6697 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1374:

/* Line 1788 of yacc.c  */
#line 6698 "parser.y"
    { (yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 1375:

/* Line 1788 of yacc.c  */
#line 6702 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1376:

/* Line 1788 of yacc.c  */
#line 6703 "parser.y"
    { (yyval) = cb_space; }
    break;

  case 1377:

/* Line 1788 of yacc.c  */
#line 6704 "parser.y"
    { (yyval) = cb_zero; }
    break;

  case 1378:

/* Line 1788 of yacc.c  */
#line 6705 "parser.y"
    { (yyval) = cb_quote; }
    break;

  case 1379:

/* Line 1788 of yacc.c  */
#line 6706 "parser.y"
    { (yyval) = cb_high; }
    break;

  case 1380:

/* Line 1788 of yacc.c  */
#line 6707 "parser.y"
    { (yyval) = cb_low; }
    break;

  case 1381:

/* Line 1788 of yacc.c  */
#line 6708 "parser.y"
    { (yyval) = cb_null; }
    break;

  case 1382:

/* Line 1788 of yacc.c  */
#line 6717 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1383:

/* Line 1788 of yacc.c  */
#line 6721 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  }
    break;

  case 1384:

/* Line 1788 of yacc.c  */
#line 6725 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), cb_list_init ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]));
  }
    break;

  case 1385:

/* Line 1788 of yacc.c  */
#line 6729 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), cb_list_init ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]));
  }
    break;

  case 1386:

/* Line 1788 of yacc.c  */
#line 6733 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), cb_list_init ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]));
  }
    break;

  case 1387:

/* Line 1788 of yacc.c  */
#line 6737 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1388:

/* Line 1788 of yacc.c  */
#line 6741 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1389:

/* Line 1788 of yacc.c  */
#line 6745 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1390:

/* Line 1788 of yacc.c  */
#line 6749 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1391:

/* Line 1788 of yacc.c  */
#line 6753 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL);
  }
    break;

  case 1392:

/* Line 1788 of yacc.c  */
#line 6757 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
  }
    break;

  case 1393:

/* Line 1788 of yacc.c  */
#line 6761 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL);
  }
    break;

  case 1394:

/* Line 1788 of yacc.c  */
#line 6767 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1395:

/* Line 1788 of yacc.c  */
#line 6768 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(2) - (4)]), NULL); }
    break;

  case 1396:

/* Line 1788 of yacc.c  */
#line 6769 "parser.y"
    { (yyval) = cb_build_pair ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); }
    break;

  case 1397:

/* Line 1788 of yacc.c  */
#line 6773 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1398:

/* Line 1788 of yacc.c  */
#line 6774 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 1399:

/* Line 1788 of yacc.c  */
#line 6778 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1400:

/* Line 1788 of yacc.c  */
#line 6779 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 1401:

/* Line 1788 of yacc.c  */
#line 6785 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  }
    break;

  case 1402:

/* Line 1788 of yacc.c  */
#line 6792 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  }
    break;

  case 1403:

/* Line 1788 of yacc.c  */
#line 6799 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  }
    break;

  case 1404:

/* Line 1788 of yacc.c  */
#line 6809 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1405:

/* Line 1788 of yacc.c  */
#line 6816 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  }
    break;

  case 1406:

/* Line 1788 of yacc.c  */
#line 6826 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  }
    break;

  case 1407:

/* Line 1788 of yacc.c  */
#line 6833 "parser.y"
    {
	cb_tree	x;

	x = cb_list_init ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  }
    break;

  case 1408:

/* Line 1788 of yacc.c  */
#line 6846 "parser.y"
    {
	non_const_word = 1;
  }
    break;

  case 1409:

/* Line 1788 of yacc.c  */
#line 6856 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1410:

/* Line 1788 of yacc.c  */
#line 6857 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1411:

/* Line 1788 of yacc.c  */
#line 6861 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1412:

/* Line 1788 of yacc.c  */
#line 6862 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1413:

/* Line 1788 of yacc.c  */
#line 6866 "parser.y"
    { (yyval) = NULL; }
    break;

  case 1414:

/* Line 1788 of yacc.c  */
#line 6867 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1415:

/* Line 1788 of yacc.c  */
#line 6871 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1416:

/* Line 1788 of yacc.c  */
#line 6872 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1417:

/* Line 1788 of yacc.c  */
#line 6873 "parser.y"
    { (yyval) = cb_int2; }
    break;

  case 1418:

/* Line 1788 of yacc.c  */
#line 6877 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1419:

/* Line 1788 of yacc.c  */
#line 6878 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1420:

/* Line 1788 of yacc.c  */
#line 6882 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1421:

/* Line 1788 of yacc.c  */
#line 6883 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1422:

/* Line 1788 of yacc.c  */
#line 6887 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1423:

/* Line 1788 of yacc.c  */
#line 6888 "parser.y"
    { (yyval) = cb_int1; }
    break;

  case 1424:

/* Line 1788 of yacc.c  */
#line 6892 "parser.y"
    { (yyval) = cb_int0; }
    break;

  case 1425:

/* Line 1788 of yacc.c  */
#line 6893 "parser.y"
    { (yyval) = cb_int1; }
    break;



/* Line 1788 of yacc.c  */
#line 14011 "parser.c"
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

#if !defined yyoverflow || YYERROR_VERBOSE
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



/* Line 2049 of yacc.c  */
#line 6949 "parser.y"


