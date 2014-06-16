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


#ifndef CB_TREE_H
#define CB_TREE_H

#define CB_BEFORE		cb_int0
#define CB_AFTER		cb_int1

#define COB_MAX_SUBSCRIPTS	16

#define CB_PREFIX_ATTR		"a_"	/* Field attribute (cob_field_attr) */
#define CB_PREFIX_BASE		"b_"	/* Base address (unsigned char *) */
#define CB_PREFIX_CONST		"c_"	/* Constant or literal (cob_field) */
#define CB_PREFIX_DECIMAL	"d_"	/* Decimal number (cob_decimal) */
#define CB_PREFIX_FIELD		"f_"	/* Field (cob_field) */
#define CB_PREFIX_FILE		"h_"	/* File (cob_file) */
#define CB_PREFIX_KEYS		"k_"	/* File keys (cob_file_key []) */
#define CB_PREFIX_LABEL		"l_"	/* Label */
#define CB_PREFIX_SEQUENCE	"s_"	/* Collating sequence */
#define CB_PREFIX_STRING	"st_"	/* String */

#define CB_PROGRAM_TYPE		0
#define CB_FUNCTION_TYPE	1

#define CB_CALL_BY_REFERENCE	1
#define CB_CALL_BY_CONTENT	2
#define CB_CALL_BY_VALUE	3

#define CB_SIZE_AUTO		0
#define CB_SIZE_1		1
#define CB_SIZE_2		2
#define CB_SIZE_4		3
#define CB_SIZE_8		4
#define CB_SIZE_UNSIGNED	8

/* Hash values */
/* Power of 2 - see hash function in tree.c */
#define CB_WORD_HASH_SIZE	(1U << 11)
#define CB_WORD_HASH_MASK	(CB_WORD_HASH_SIZE - 1U)

/* Basic tree tag */
enum cb_tag {
	/* Primitives */
	CB_TAG_CONST = 0,	/* 0 Constant value */
	CB_TAG_INTEGER,		/* 1 Integer constant */
	CB_TAG_STRING,		/* 2 String constant */
	CB_TAG_ALPHABET_NAME,	/* 3 Alphabet-name */
	CB_TAG_CLASS_NAME,	/* 4 Class-name */
	CB_TAG_LOCALE_NAME,	/* 5 Locale-name */
	CB_TAG_SYSTEM_NAME,	/* 6 System-name */
	CB_TAG_LITERAL,		/* 7 Numeric/alphanumeric literal */
	CB_TAG_DECIMAL,		/* 8 Decimal number */
	CB_TAG_FIELD,		/* 9 User-defined variable */
	CB_TAG_FILE,		/* 10 File description */
	CB_TAG_REPORT,		/* 11 Report description */
	/* Expressions */
	CB_TAG_REFERENCE,	/* 12 Reference to a field, file, or label */
	CB_TAG_BINARY_OP,	/* 13 Binary operation */
	CB_TAG_FUNCALL,		/* 14 Run-time function call */
	CB_TAG_CAST,		/* 15 Type cast */
	CB_TAG_INTRINSIC,	/* 16 Intrinsic function */
	/* Statements */
	CB_TAG_LABEL,		/* 17 Label statement */
	CB_TAG_ASSIGN,		/* 18 Assignment statement */
	CB_TAG_INITIALIZE,	/* 19 INITIALIZE statement */
	CB_TAG_SEARCH,		/* 20 SEARCH statement */
	CB_TAG_CALL,		/* 21 CALL statement */
	CB_TAG_GOTO,		/* 22 GO TO statement */
	CB_TAG_IF,		/* 23 IF statement */
	CB_TAG_PERFORM,		/* 24 PERFORM statement */
	CB_TAG_STATEMENT,	/* 25 General statement */
	CB_TAG_CONTINUE,	/* 26 CONTINUE statement */
	CB_TAG_CANCEL,		/* 27 CANCEL statement */
	CB_TAG_ALTER,		/* 28 ALTER statement */
	CB_TAG_SET_ATTR,	/* 29 SET ATTRIBUTE statement */
	/* Miscellaneous */
	CB_TAG_PERFORM_VARYING,	/* 30 PERFORM VARYING parameter */
	CB_TAG_PICTURE,		/* 31 PICTURE clause */
	CB_TAG_LIST,		/* 32 List */
	CB_TAG_DIRECT,		/* 33 Code output or comment */
	CB_TAG_DEBUG,		/* 34 Debug item set */
	CB_TAG_DEBUG_CALL	/* 35 Debug callback */
};

/* Alphabet type */
#define CB_ALPHABET_NATIVE	0
#define CB_ALPHABET_ASCII	1
#define CB_ALPHABET_EBCDIC	2
#define CB_ALPHABET_CUSTOM	3

/* Call convention bits */
/* Bit number	Meaning			Value */
/*	0	Parameter order		0 - Right to left		*/
/*					1 - Left to right		*/
/*	1	Stack manipulation	0 - Caller removes params	*/
/*					1 - Callee removes params	*/
/*	2	RETURN-CODE update	0 - Updated			*/
/*					1 - Not updated			*/
/*	3	Linking behaviour	0 - Normal linking		*/
/*					1 - Static CALL linking		*/
/*	4	OS/2 Optlink		0 - ??				*/
/*					1 - ??				*/
/*	5	Thunked to 16 bit	0 - No thunk			*/
/*					1 - Thunk			*/
/*	6	STDCALL convention	0 - CDECL			*/
/*					1 - STDCALL			*/

#define CB_CONV_L_TO_R		(1 << 0)
#define CB_CONV_CALLEE_STACK	(1 << 1)
#define CB_CONV_NO_RET_UPD	(1 << 2)
#define CB_CONV_STATIC_LINK	(1 << 3)
#define CB_CONV_OPT_LINK	(1 << 4)
#define CB_CONV_THUNK_16	(1 << 5)
#define CB_CONV_STDCALL		(1 << 6)

/* System category */
enum cb_system_name_category {
	CB_DEVICE_NAME = 0,
	CB_SWITCH_NAME,
	CB_FEATURE_NAME,
	CB_CALL_CONVENTION_NAME,
	CB_CODE_NAME,
	CB_COMPUTER_NAME,
	CB_ENTRY_CONVENTION_NAME,
	CB_EXTERNAL_LOCALE_NAME,
	CB_LIBRARY_NAME,
	CB_TEXT_NAME
};

/* Mnemonic defines */
/* Devices */
#define CB_DEVICE_SYSIN		0
#define CB_DEVICE_SYSOUT	1
#define CB_DEVICE_SYSERR	2
#define CB_DEVICE_CONSOLE	3
/* Switches */
#define CB_SWITCH_0		0
#define CB_SWITCH_1		1
#define CB_SWITCH_2		2
#define CB_SWITCH_3		3
#define CB_SWITCH_4		4
#define CB_SWITCH_5		5
#define CB_SWITCH_6		6
#define CB_SWITCH_7		7
#define CB_SWITCH_8		8
#define CB_SWITCH_9		9
#define CB_SWITCH_10		10
#define CB_SWITCH_11		11
#define CB_SWITCH_12		12
#define CB_SWITCH_13		13
#define CB_SWITCH_14		14
#define CB_SWITCH_15		15
/* Features */
#define CB_FEATURE_FORMFEED	0
#define CB_FEATURE_CONVENTION	1
#define CB_FEATURE_C01		2
#define CB_FEATURE_C02		3
#define CB_FEATURE_C03		4
#define CB_FEATURE_C04		5
#define CB_FEATURE_C05		6
#define CB_FEATURE_C06		7
#define CB_FEATURE_C07		8
#define CB_FEATURE_C08		9
#define CB_FEATURE_C09		10
#define CB_FEATURE_C10		11
#define CB_FEATURE_C11		12
#define CB_FEATURE_C12		13


/* Class category */
enum cb_class {
	CB_CLASS_UNKNOWN = 0,		/* 0 */
	CB_CLASS_ALPHABETIC,		/* 1 */
	CB_CLASS_ALPHANUMERIC,		/* 2 */
	CB_CLASS_BOOLEAN,		/* 3 */
	CB_CLASS_INDEX,			/* 4 */
	CB_CLASS_NATIONAL,		/* 5 */
	CB_CLASS_NUMERIC,		/* 6 */
	CB_CLASS_OBJECT,		/* 7 */
	CB_CLASS_POINTER		/* 8 */
};

/* Category */
enum cb_category {
	CB_CATEGORY_UNKNOWN = 0,		/* 0 */
	CB_CATEGORY_ALPHABETIC,			/* 1 */
	CB_CATEGORY_ALPHANUMERIC,		/* 2 */
	CB_CATEGORY_ALPHANUMERIC_EDITED,	/* 3 */
	CB_CATEGORY_BOOLEAN,			/* 4 */
	CB_CATEGORY_INDEX,			/* 5 */
	CB_CATEGORY_NATIONAL,			/* 6 */
	CB_CATEGORY_NATIONAL_EDITED,		/* 7 */
	CB_CATEGORY_NUMERIC,			/* 8 */
	CB_CATEGORY_NUMERIC_EDITED,		/* 9 */
	CB_CATEGORY_OBJECT_REFERENCE,		/* 10 */
	CB_CATEGORY_DATA_POINTER,		/* 11 */
	CB_CATEGORY_PROGRAM_POINTER		/* 12 */
};

/* Storage sections */
enum cb_storage {
	CB_STORAGE_CONSTANT = 0,	/* Constants */
	CB_STORAGE_FILE,		/* FILE SECTION */
	CB_STORAGE_WORKING,		/* WORKING-STORAGE SECTION */
	CB_STORAGE_LOCAL,		/* LOCAL-STORAGE SECTION */
	CB_STORAGE_LINKAGE,		/* LINKAGE SECTION */
	CB_STORAGE_SCREEN,		/* SCREEN SECTION */
	CB_STORAGE_REPORT,		/* REPORT SECTION */
	CB_STORAGE_COMMUNICATION	/* COMMUNICATION SECTION */
};

/* Field types */
enum cb_usage {
	CB_USAGE_BINARY = 0,		/* 0 */
	CB_USAGE_BIT,			/* 1 */
	CB_USAGE_COMP_5,		/* 2 */
	CB_USAGE_COMP_X,		/* 3 */
	CB_USAGE_DISPLAY,		/* 4 */
	CB_USAGE_FLOAT,			/* 5 */
	CB_USAGE_DOUBLE,		/* 6 */
	CB_USAGE_INDEX,			/* 7 */
	CB_USAGE_NATIONAL,		/* 8 */
	CB_USAGE_OBJECT,		/* 9 */
	CB_USAGE_PACKED,		/* 10 */
	CB_USAGE_POINTER,		/* 11 */
	CB_USAGE_PROGRAM,		/* 12 */
	CB_USAGE_LENGTH,		/* 13 */
	CB_USAGE_PROGRAM_POINTER,	/* 14 */
	CB_USAGE_UNSIGNED_CHAR,		/* 15 */
	CB_USAGE_SIGNED_CHAR,		/* 16 */
	CB_USAGE_UNSIGNED_SHORT,	/* 17 */
	CB_USAGE_SIGNED_SHORT,		/* 18 */
	CB_USAGE_UNSIGNED_INT,		/* 19 */
	CB_USAGE_SIGNED_INT,		/* 20 */
	CB_USAGE_UNSIGNED_LONG,		/* 21 */
	CB_USAGE_SIGNED_LONG,		/* 22 */
	CB_USAGE_COMP_6,		/* 23 */
	CB_USAGE_FP_DEC64,		/* 24 */
	CB_USAGE_FP_DEC128,		/* 25 */
	CB_USAGE_FP_BIN32,		/* 26 */
	CB_USAGE_FP_BIN64,		/* 27 */
	CB_USAGE_FP_BIN128,		/* 28 */
	CB_USAGE_LONG_DOUBLE		/* 29 */
};


/* Cast type */
enum cb_cast_type {
	CB_CAST_INTEGER = 0,		/* 0 */
	CB_CAST_LONG_INT,		/* 1 */
	CB_CAST_ADDRESS,		/* 2 */
	CB_CAST_ADDR_OF_ADDR,		/* 3 */
	CB_CAST_LENGTH,			/* 4 */
	CB_CAST_PROGRAM_POINTER		/* 5 */
};

/* Intrinsic functions */
enum cb_intr_enum {
	CB_INTR_ABS = 1,
	CB_INTR_ACOS,
	CB_INTR_ANNUITY,
	CB_INTR_ASIN,
	CB_INTR_ATAN,
	CB_INTR_BOOLEAN_OF_INTEGER,
	CB_INTR_BYTE_LENGTH,
	CB_INTR_CHAR,
	CB_INTR_CHAR_NATIONAL,
	CB_INTR_COMBINED_DATETIME,
	CB_INTR_CONCATENATE,
	CB_INTR_COS,
	CB_INTR_CURRENCY_SYMBOL,
	CB_INTR_CURRENT_DATE,
	CB_INTR_DATE_OF_INTEGER,
	CB_INTR_DATE_TO_YYYYMMDD,
	CB_INTR_DAY_OF_INTEGER,
	CB_INTR_DAY_TO_YYYYDDD,
	CB_INTR_DISPLAY_OF,
	CB_INTR_E,
	CB_INTR_EXCEPTION_FILE,
	CB_INTR_EXCEPTION_FILE_N,
	CB_INTR_EXCEPTION_LOCATION,
	CB_INTR_EXCEPTION_LOCATION_N,
	CB_INTR_EXCEPTION_STATEMENT,
	CB_INTR_EXCEPTION_STATUS,
	CB_INTR_EXP,
	CB_INTR_EXP10,
	CB_INTR_FACTORIAL,
	CB_INTR_FORMATTED_CURRENT_DATE,
	CB_INTR_FORMATTED_DATE,
	CB_INTR_FORMATTED_DATETIME,
	CB_INTR_FORMATTED_TIME,
	CB_INTR_FRACTION_PART,
	CB_INTR_HIGHEST_ALGEBRAIC,
	CB_INTR_INTEGER,
	CB_INTR_INTEGER_OF_BOOLEAN,
	CB_INTR_INTEGER_OF_DATE,
	CB_INTR_INTEGER_OF_DAY,
	CB_INTR_INTEGER_OF_FORMATTED_DATE,
	CB_INTR_INTEGER_PART,
	CB_INTR_LENGTH,
	CB_INTR_LOCALE_COMPARE,
	CB_INTR_LOCALE_DATE,
	CB_INTR_LOCALE_TIME,
	CB_INTR_LOCALE_TIME_FROM_SECS,
	CB_INTR_LOG,
	CB_INTR_LOG10,
	CB_INTR_LOWER_CASE,
	CB_INTR_LOWEST_ALGEBRAIC,
	CB_INTR_MAX,
	CB_INTR_MEAN,
	CB_INTR_MEDIAN,
	CB_INTR_MIDRANGE,
	CB_INTR_MIN,
	CB_INTR_MOD,
	CB_INTR_MODULE_CALLER_ID,
	CB_INTR_MODULE_DATE,
	CB_INTR_MODULE_FORMATTED_DATE,
	CB_INTR_MODULE_ID,
	CB_INTR_MODULE_PATH,
	CB_INTR_MODULE_SOURCE,
	CB_INTR_MODULE_TIME,
	CB_INTR_MON_DECIMAL_POINT,
	CB_INTR_MON_THOUSANDS_SEP,
	CB_INTR_NATIONAL_OF,
	CB_INTR_NUM_DECIMAL_POINT,
	CB_INTR_NUM_THOUSANDS_SEP,
	CB_INTR_NUMVAL,
	CB_INTR_NUMVAL_C,
	CB_INTR_NUMVAL_F,
	CB_INTR_ORD,
	CB_INTR_ORD_MAX,
	CB_INTR_ORD_MIN,
	CB_INTR_PI,
	CB_INTR_PRESENT_VALUE,
	CB_INTR_RANDOM,
	CB_INTR_RANGE,
	CB_INTR_REM,
	CB_INTR_REVERSE,
	CB_INTR_SECONDS_FROM_FORMATTED_TIME,
	CB_INTR_SECONDS_PAST_MIDNIGHT,
	CB_INTR_SIGN,
	CB_INTR_SIN,
	CB_INTR_SQRT,
	CB_INTR_STANDARD_COMPARE,
	CB_INTR_STANDARD_DEVIATION,
	CB_INTR_STORED_CHAR_LENGTH,
	CB_INTR_SUBSTITUTE,
	CB_INTR_SUBSTITUTE_CASE,
	CB_INTR_SUM,
	CB_INTR_TAN,
	CB_INTR_TEST_DATE_YYYYMMDD,
	CB_INTR_TEST_DAY_YYYYDDD,
	CB_INTR_TEST_FORMATTED_DATETIME,
	CB_INTR_TEST_NUMVAL,
	CB_INTR_TEST_NUMVAL_C,
	CB_INTR_TEST_NUMVAL_F,
	CB_INTR_TRIM,
	CB_INTR_UPPER_CASE,
	CB_INTR_USER_FUNCTION,
	CB_INTR_VARIANCE,
	CB_INTR_WHEN_COMPILED,
	CB_INTR_YEAR_TO_YYYY
};

/* Perform type */
enum cb_perform_type {
	CB_PERFORM_EXIT = 0,
	CB_PERFORM_ONCE,
	CB_PERFORM_TIMES,
	CB_PERFORM_UNTIL,
	CB_PERFORM_FOREVER
};

/* Reserved word list structure */
struct cobc_reserved {
	const char		*name;		/* Word */
	const unsigned short	nodegen;	/* Statement with END-xxx */
	const unsigned short	context_sens;	/* Context sensitive */
	const int		token;		/* Token */
	const unsigned int	context_set;	/* Set context sensitive */
	const unsigned int	context_test;	/* Test context sensitive */
};

/* Basic common tree structure */

struct cb_tree_common {
	enum cb_tag		tag;		/* TAG - see below */
	enum cb_category	category;	/* Category */
	const char		*source_file;	/* Source file */
	int			source_line;	/* Line */
	int			source_column;	/* Column */
};

/* Define common cb_tree/CB_TREE for following defines */

typedef struct cb_tree_common	*cb_tree;

#define CB_TREE(x)		((struct cb_tree_common *) (x))
#define CB_TREE_TAG(x)		(CB_TREE (x)->tag)
#define CB_TREE_CLASS(x)	cb_tree_class (CB_TREE (x))
#define CB_TREE_CATEGORY(x)	cb_tree_category (CB_TREE (x))

#define	CB_VALID_TREE(x)	(x && CB_TREE (x) != cb_error_node)
#define	CB_INVALID_TREE(x)	(!(x) || CB_TREE (x) == cb_error_node)

#ifdef	COB_TREE_DEBUG

#ifdef	COB_HAVE_STEXPR
#define CB_TREE_CAST(tg,ty,x)						\
({									\
	cb_tree _x = (x);						\
	if (unlikely(!_x || CB_TREE_TAG (_x) != tg)) {			\
		cobc_tree_cast_error (_x, __FILE__, __LINE__, tg);	\
	}								\
	((ty *) (_x));							\
})
#else
#define CB_TREE_CAST(tg,ty,x)	\
	((ty *)cobc_tree_cast_check (x, __FILE__, __LINE__, tg))
#endif

#else
#define CB_TREE_CAST(tg,ty,x)	((ty *) (x))
#endif


/* Constant */

struct cb_const {
	struct cb_tree_common	common;		/* Common values */
	const char		*val;		/* Constant value */
};

#define CB_CONST(x)	(CB_TREE_CAST (CB_TAG_CONST, struct cb_const, x))
#define CB_CONST_P(x)	(CB_TREE_TAG (x) == CB_TAG_CONST)

/* Code output or comment */

struct cb_direct {
	struct cb_tree_common	common;		/* Common values */
	const char		*line;		/* Line redirect */
	cob_u32_t		flag_is_direct;	/* Is directed */
	cob_u32_t		flag_new_line;	/* Need new line */
};

#define CB_DIRECT(x)	(CB_TREE_CAST (CB_TAG_DIRECT, struct cb_direct, x))
#define CB_DIRECT_P(x)	(CB_TREE_TAG (x) == CB_TAG_DIRECT)

/* DEBUG */

struct cb_debug {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			target;		/* Target for debug */
	const char		*value;		/* Value for debug */
	cb_tree			fld;		/* Reference */
	size_t			size;		/* Size if relevant */
};

#define CB_DEBUG(x)	(CB_TREE_CAST (CB_TAG_DEBUG, struct cb_debug, x))
#define CB_DEBUG_P(x)	(CB_TREE_TAG (x) == CB_TAG_DEBUG)

/* DEBUG Callback */

struct cb_debug_call {
	struct cb_tree_common	common;		/* Common values */
	struct cb_label		*target;	/* Target label */
};

#define CB_DEBUG_CALL(x)	(CB_TREE_CAST (CB_TAG_DEBUG_CALL, struct cb_debug_call, x))
#define CB_DEBUG_CALL_P(x)	(CB_TREE_TAG (x) == CB_TAG_DEBUG_CALL)

/* Integer */

struct cb_integer {
	struct cb_tree_common	common;		/* Common values */
	int			val;		/* Integer value */
	unsigned int		hexval;		/* Output hex value */
};

#define CB_INTEGER(x)	(CB_TREE_CAST (CB_TAG_INTEGER, struct cb_integer, x))
#define CB_INTEGER_P(x)	(CB_TREE_TAG (x) == CB_TAG_INTEGER)

/* String */

struct cb_string {
	struct cb_tree_common	common;		/* Common values */
	const unsigned char	*data;		/* Data */
	size_t			size;		/* Data size */
};

#define CB_STRING(x)	(CB_TREE_CAST (CB_TAG_STRING, struct cb_string, x))
#define CB_STRING_P(x)	(CB_TREE_TAG (x) == CB_TAG_STRING)

/* Alphabet-name */

struct cb_alphabet_name {
	struct cb_tree_common	common;		/* Common values */
	const char		*name;		/* Original name */
	char			*cname;		/* Name used in C */
	cb_tree			custom_list;	/* Custom ALPHABET */
	unsigned int		alphabet_type;	/* ALPHABET type */
	int			low_val_char;	/* LOW-VALUE */
	int			high_val_char;	/* HIGH-VALUE */
	int			values[256];	/* Collating values */
	int			alphachr[256];	/* Actual values */
};

#define CB_ALPHABET_NAME(x)	(CB_TREE_CAST (CB_TAG_ALPHABET_NAME, struct cb_alphabet_name, x))
#define CB_ALPHABET_NAME_P(x)	(CB_TREE_TAG (x) == CB_TAG_ALPHABET_NAME)

/* Class-name */

struct cb_class_name {
	struct cb_tree_common	common;		/* Common values */
	const char		*name;		/* Original name */
	char			*cname;		/* Name used in C */
	cb_tree			list;		/* List of CLASS definitions */
};

#define CB_CLASS_NAME(x)	(CB_TREE_CAST (CB_TAG_CLASS_NAME, struct cb_class_name, x))
#define CB_CLASS_NAME_P(x)	(CB_TREE_TAG (x) == CB_TAG_CLASS_NAME)

/* Locale name */

struct cb_locale_name {
	struct cb_tree_common	common;		/* Common values */
	const char		*name;		/* Original name */
	char			*cname;		/* Name used in C */
	cb_tree			list;		/* List of locale definitions */
};

#define CB_LOCALE_NAME(x)	(CB_TREE_CAST (CB_TAG_LOCALE_NAME, struct cb_locale_name, x))
#define CB_LOCALE_NAME_P(x)	(CB_TREE_TAG (x) == CB_TAG_LOCALE_NAME)

/* System-name */

struct cb_system_name {
	struct cb_tree_common		common;		/* Common values */
	cb_tree				value;		/* System value */
	enum cb_system_name_category	category;	/* System category */
	int				token;		/* Device attributes */
};

#define CB_SYSTEM_NAME(x)	(CB_TREE_CAST (CB_TAG_SYSTEM_NAME, struct cb_system_name, x))
#define CB_SYSTEM_NAME_P(x)	(CB_TREE_TAG (x) == CB_TAG_SYSTEM_NAME)

/* Literal */

struct cb_literal {
	struct cb_tree_common	common;	/* Common values */
	unsigned char		*data;	/* Literal data */
	cob_u32_t		size;	/* Literal size */
	int			scale;	/* Numeric scale */
	cob_u32_t		llit;	/* 'L' literal */
	short			sign;	/* unsigned: 0 negative: -1 positive: 1 */
	short			all;	/* ALL */
};

#define CB_LITERAL(x)	(CB_TREE_CAST (CB_TAG_LITERAL, struct cb_literal, x))
#define CB_LITERAL_P(x)	(CB_TREE_TAG (x) == CB_TAG_LITERAL)
#define CB_NUMERIC_LITERAL_P(x) \
  (CB_LITERAL_P (x) && CB_TREE_CATEGORY (x) == CB_CATEGORY_NUMERIC)

/* Decimal */

struct cb_decimal {
	struct cb_tree_common	common;		/* Common values */
	int			id;		/* Id for this decimal */
};

#define CB_DECIMAL(x)	(CB_TREE_CAST (CB_TAG_DECIMAL, struct cb_decimal, x))
#define CB_DECIMAL_P(x)	(CB_TREE_TAG (x) == CB_TAG_DECIMAL)

/* Picture */

struct cb_picture {
	struct cb_tree_common	common;		/* Common values */
	char			*orig;		/* Original picture string */
	char			*str;		/* Packed picture string */
	int			size;		/* Byte size */
	int			lenstr;		/* Length of picture string */
	enum cb_category	category;	/* Field category */
	cob_u32_t		digits;		/* Number of digit places */
	int			scale;		/* 1/10^scale */
	cob_u32_t		have_sign;	/* Have 'S' */
	cob_u32_t		real_digits;	/* Real number of digits */
};

#define CB_PICTURE(x)	(CB_TREE_CAST (CB_TAG_PICTURE, struct cb_picture, x))
#define CB_PICTURE_P(x)	(CB_TREE_TAG (x) == CB_TAG_PICTURE)

/* Field */

struct cb_key {
	cb_tree	key;			/* KEY */
	cb_tree	ref;			/* Reference used in SEARCH ALL */
	cb_tree	val;			/* Value to be compared in SEARCH ALL */
	int	dir;			/* ASCENDING or DESCENDING */
};

struct cb_field {
	struct cb_tree_common	common;		/* Common values */
	const char		*name;		/* Original name */
	const char		*ename;		/* Externalized name */
	cb_tree			depending;	/* OCCURS ... DEPENDING ON */
	cb_tree			values;		/* VALUE */
	cb_tree			false_88;	/* 88 FALSE clause */
	cb_tree			index_list;	/* INDEXED BY */
	struct cb_field		*parent;	/* Upper level field (if any) */
	struct cb_field		*children;	/* Top of lower level fields */
	struct cb_field		*sister;	/* Fields at the same level */
	struct cb_field		*redefines;	/* REDEFINES */
	struct cb_field		*rename_thru;	/* RENAMES THRU */
	struct cb_field		*index_qual;	/* INDEXED BY qualifier */
	struct cb_file		*file;		/* FD section file name */
	struct cb_key 		*keys;		/* SEARCH key */
	struct cb_picture	*pic;		/* PICTURE */
	struct cb_field		*vsize;		/* Variable size cache */
	struct cb_label		*debug_section;	/* DEBUG section */

	cb_tree			screen_line;	/* LINE */
	cb_tree			screen_column;	/* COLUMN */
	cb_tree			screen_from;	/* TO and USING */
	cb_tree			screen_to;	/* FROM and USING */
	cb_tree			screen_foreg;	/* FOREGROUND */
	cb_tree			screen_backg;	/* BACKGROUND */
	cb_tree			screen_prompt;	/* PROMPT */

	int			id;		/* Field id */
	int			size;		/* Field size */
	int			level;		/* Level number */
	int			memory_size;	/* Memory size */
	int			offset;		/* Byte offset from 01 level */
	int			occurs_min;	/* OCCURS <max> */
	int			occurs_max;	/* or OCCURS <min> TO <max> */
	int			indexes;	/* Indices count (OCCURS) */

	int			count;		/* Reference count */
	int			mem_offset;	/* Memory offset */
	int			nkeys;		/* Number of keys */
	int			param_num;	/* CHAINING param number */
	int			screen_flag;	/* Flags used in SCREEN SECTION */
	int			step_count;	/* STEP in REPORT */
	unsigned int		vaddr;		/* Variable address cache */
	cob_u32_t		special_index;	/* Special field */

	enum cb_storage		storage;	/* Storage section */
	enum cb_usage		usage;		/* USAGE */

	/* Flags */
	unsigned char flag_base;		/* Has memory allocation */
	unsigned char flag_external;		/* EXTERNAL */
	unsigned char flag_local_storage;	/* LOCAL storage */
	unsigned char flag_is_global;		/* Is GLOBAL */

	unsigned int flag_local		: 1;	/* Has local scope */
	unsigned int flag_occurs	: 1;	/* OCCURS */
	unsigned int flag_sign_separate	: 1;	/* SIGN IS SEPARATE */
	unsigned int flag_sign_leading	: 1;	/* SIGN IS LEADING */
	unsigned int flag_blank_zero	: 1;	/* BLANK WHEN ZERO */
	unsigned int flag_justified	: 1;	/* JUSTIFIED RIGHT */
	unsigned int flag_binary_swap	: 1;	/* Binary byteswap */
	unsigned int flag_real_binary	: 1;	/* BINARY-CHAR/SHORT/LONG/DOUBLE */

	unsigned int flag_is_pointer	: 1;	/* Is POINTER */
	unsigned int flag_item_78	: 1;	/* Is 78 level */
	unsigned int flag_any_length	: 1;	/* Is ANY LENGTH */
	unsigned int flag_item_based	: 1;	/* Is BASED */
	unsigned int flag_filler	: 1;	/* Implicit/explicit filler */
	unsigned int flag_synchronized	: 1;	/* SYNCHRONIZED */
	unsigned int flag_invalid	: 1;	/* Is broken */
	unsigned int flag_field		: 1;	/* Has been internally cached */

	unsigned int flag_chained	: 1;	/* CHAINING item */
	unsigned int flag_anylen_done	: 1;	/* ANY LENGTH is set up */
	unsigned int flag_indexed_by	: 1;	/* INDEXED BY item */
	unsigned int flag_is_verified	: 1;	/* Has been verified */
	unsigned int flag_is_c_long	: 1;	/* Is BINARY-C-LONG */
	unsigned int flag_is_pdiv_parm	: 1;	/* Is PROC DIV USING */
	unsigned int flag_local_alloced	: 1;	/* LOCAL storage is allocated */
	unsigned int flag_no_init	: 1;	/* No initialize unless used */

	unsigned int flag_vsize_done	: 1;	/* Variable size cached */
	unsigned int flag_vaddr_done	: 1;	/* Variable address cached */
	unsigned int flag_odo_item	: 1;	/* ODO item */
	unsigned int flag_field_debug	: 1;	/* DEBUGGING */
	unsigned int flag_all_debug	: 1;	/* DEBUGGING */
	unsigned int flag_no_field	: 1;	/* SCREEN dummy field */
	unsigned int flag_any_numeric	: 1;	/* Is ANY NUMERIC */
	unsigned int flag_is_returning	: 1;	/* Is RETURNING item */
};

#define CB_FIELD(x)		(CB_TREE_CAST (CB_TAG_FIELD, struct cb_field, x))
#define CB_FIELD_P(x)		(CB_TREE_TAG (x) == CB_TAG_FIELD)

#define CB_REF_OR_FIELD_P(x)	(CB_REFERENCE_P (x) || CB_FIELD_P (x))

#define CB_FIELD_PTR(x)		\
	(CB_REFERENCE_P (x) ? CB_FIELD (cb_ref (x)) : CB_FIELD (x))

/* Index */

#define CB_INDEX_P(x)		cb_check_index_p (x)

/* Label */

struct cb_para_label {
	struct cb_para_label	*next;
	struct cb_label		*para;
};

struct cb_alter_id {
	struct cb_alter_id	*next;
	int			goto_id;
};

struct cb_label {
	struct cb_tree_common	common;			/* Common values */
	const char		*name;			/* Name */
	const char		*orig_name;		/* Original name */
	struct cb_label		*section;		/* Parent SECTION */
	struct cb_label		*debug_section;		/* DEBUG SECTION */
	struct cb_para_label	*para_label;		/* SECTION Paragraphs */
	cb_tree			exit_label;		/* EXIT label */
	struct cb_alter_id	*alter_gotos;		/* ALTER ids */
	int			id;			/* Unique id */
	int			section_id;		/* SECTION id */
	int			segment;		/* Segment number */

	unsigned int		flag_section		: 1;	/* Section */
	unsigned int		flag_entry		: 1;	/* Entry */
	unsigned int		flag_begin		: 1;	/* Begin label */
	unsigned int		flag_return		: 1;	/* End label */
	unsigned int		flag_real_label		: 1;	/* Is real label */
	unsigned int		flag_global		: 1;	/* GLOBAL */
	unsigned int		flag_declarative_exit	: 1;	/* Final EXIT */
	unsigned int		flag_declaratives	: 1;	/* DECLARATIVES */

	unsigned int		flag_fatal_check	: 1;	/* Fatal check */
	unsigned int		flag_dummy_section	: 1;	/* Dummy MAIN */
	unsigned int		flag_dummy_paragraph	: 1;	/* Dummy MAIN */
	unsigned int		flag_dummy_exit		: 1;	/* Dummy EXIT */
	unsigned int		flag_next_sentence	: 1;	/* NEXT SENTENCE */
	unsigned int		flag_default_handler	: 1;	/* Error handler */
	unsigned int		flag_statement		: 1;	/* Has statement */
	unsigned int		flag_first_is_goto	: 1;	/* 1st is GO TO */

	unsigned int		flag_alter		: 1;	/* ALTER code */
	unsigned int		flag_debugging_mode	: 1;	/* DEBUGGING MODE */
	unsigned int		flag_is_debug_sect	: 1;	/* DEBUGGING sect */
	unsigned int		flag_skip_label		: 1;	/* Skip label gen */
};

#define CB_LABEL(x)		(CB_TREE_CAST (CB_TAG_LABEL, struct cb_label, x))
#define CB_LABEL_P(x)		(CB_TREE_TAG (x) == CB_TAG_LABEL)

struct handler_struct {
	struct cb_label		*handler_label;		/* Handler label */
	struct cb_program	*handler_prog;		/* Handler program */
};

/* File */


struct cb_key_component {
   struct cb_key_component *next;
   cb_tree                  component;
};

struct cb_alt_key {
	struct cb_alt_key       *next;
	cb_tree                  key;
	int                      duplicates;
	int                      offset;
	int                      tf_suppress;
	int                      char_suppress;
	struct cb_key_component *component_list;
};

struct cb_file {
	struct cb_tree_common	common;			/* Common values */
	const char		*name;			/* Original name */
	char			*cname;			/* Name used in C */
	/* SELECT */
	cb_tree			assign;			/* ASSIGN */
	cb_tree			file_status;		/* FILE STATUS */
	cb_tree			sharing;		/* SHARING */
	cb_tree			key;			/* RECORD KEY */
	struct cb_alt_key	*alt_key_list;		/* ALTERNATE RECORD KEY */
	/* FD/SD */
	struct cb_field		*record;		/* Record descriptions */
	cb_tree			record_depending;	/* RECORD DEPENDING */
	cb_tree			reports;		/* REPORTS */
	cb_tree			linage;			/* LINAGE */
	cb_tree			linage_ctr;		/* LINAGE COUNTER */
	cb_tree			latfoot;		/* LINAGE FOOTING */
	cb_tree			lattop;			/* LINAGE TOP */
	cb_tree			latbot;			/* LINAGE BOTTOM */
	struct cb_label		*handler;		/* Error handler */
	struct cb_program	*handler_prog;		/* Prog where defined */
	struct cb_label		*debug_section;		/* DEBUG SECTION */
	struct cb_alphabet_name	*code_set;		/* CODE-SET */
	int			record_min;		/* RECORD CONTAINS */
	int			record_max;		/* RECORD CONTAINS */
	int			optional;		/* OPTIONAL */
	int			organization;		/* ORGANIZATION */
	int			access_mode;		/* ACCESS MODE */
	int			lock_mode;		/* LOCK MODE */
	int			special;		/* Special file */
	int			same_clause;		/* SAME clause */
	unsigned int		flag_finalized	: 1;	/* Is finalized */
	unsigned int		flag_external	: 1;	/* Is EXTERNAL */
	unsigned int		flag_ext_assign	: 1;	/* ASSIGN EXTERNAL */
	unsigned int		flag_fileid	: 1;	/* ASSIGN DISK */
	unsigned int		flag_global	: 1;	/* Is GLOBAL */
	unsigned int		flag_fl_debug	: 1;	/* DEBUGGING */
	unsigned int		flag_line_adv	: 1;	/* LINE ADVANCING */
};

#define CB_FILE(x)	(CB_TREE_CAST (CB_TAG_FILE, struct cb_file, x))
#define CB_FILE_P(x)	(CB_TREE_TAG (x) == CB_TAG_FILE)

/* Reference */

struct cb_word {
	struct cb_word	*next;		/* Next word with the same hash value */
	const char	*name;		/* Word name */
	cb_tree		items;		/* Objects associated with this word */
	int		count;		/* Number of words with the same name */
	int		error;		/* Set to 1 if error detected */
};

#define CB_WORD_TABLE_SIZE	(CB_WORD_HASH_SIZE * sizeof (struct cb_word))

struct cb_reference {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			chain;		/* Next qualified name */
	cb_tree			value;		/* Item referred to */
	cb_tree			subs;		/* List of subscripts */
	cb_tree			offset;		/* Reference mod offset */
	cb_tree			length;		/* Reference mod length */
	cb_tree			check;		/* Bounds check */
	struct cb_word		*word;		/* Pointer to word list */
	struct cb_label		*section;	/* Current section */
	struct cb_label		*paragraph;	/* Current paragraph */
	struct cb_label		*debug_section;	/* Debug section */
	size_t			hashval;	/* Hash value of name */

	unsigned int		flag_receiving	: 1;	/* Reference target */
	unsigned int		flag_all	: 1;	/* ALL */
	unsigned int		flag_in_decl	: 1;	/* In DECLARATIVE */
	unsigned int		flag_decl_ok	: 1;	/* DECLARATIVE ref OK  */
	unsigned int		flag_alter_code	: 1;	/* Needs ALTER code */
	unsigned int		flag_debug_code	: 1;	/* Needs DEBUG code */
	unsigned int		flag_all_debug	: 1;	/* Needs ALL DEBUG code */
	unsigned int		flag_target	: 1;	/* DEBUG item is target */

	unsigned int		flag_optional	: 1;	/* Definition optional */
	unsigned int		flag_filler_ref	: 1;	/* Ref to FILLER */
	unsigned int		flag_duped	: 1;	/* Duplicate name */
};

#define CB_REFERENCE(x)		(CB_TREE_CAST (CB_TAG_REFERENCE, struct cb_reference, x))
#define CB_REFERENCE_P(x)	(CB_TREE_TAG (x) == CB_TAG_REFERENCE)

#define CB_NAME(x)		(CB_REFERENCE (x)->word->name)
#define CB_WORD_COUNT(x)	(CB_REFERENCE (x)->word->count)
#define CB_WORD_ITEMS(x)	(CB_REFERENCE (x)->word->items)

/* Binary operation */

/*
  '+'	x + y
  '-'	x - y
  '*'	x * y
  '/'	x / y
  '^'	x ** y
  '='	x = y
  '>'	x > y
  '<'	x < y
  '['	x <= y
  ']'	x >= y
  '~'	x != y
  '!'	not x
  '&'	x and y
  '|'	x or y
  '@'	( x )
*/

struct cb_binary_op {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			x;		/* LHS */
	cb_tree			y;		/* RHS */
	int			op;		/* Operation */
	unsigned int		flag;		/* Special usage */
};

#define CB_BINARY_OP(x)		(CB_TREE_CAST (CB_TAG_BINARY_OP, struct cb_binary_op, x))
#define CB_BINARY_OP_P(x)	(CB_TREE_TAG (x) == CB_TAG_BINARY_OP)

/* Function call */

struct cb_funcall {
	struct cb_tree_common	common;		/* Common values */
	const char		*name;		/* Function name */
	cb_tree			argv[10];	/* Function arguments */
	int			argc;		/* Number of arguments */
	int			varcnt;		/* Variable argument count */
	unsigned int		screenptr;	/* SCREEN usage */
	unsigned int		nolitcast;	/* No cast for literals */
};

#define CB_FUNCALL(x)		(CB_TREE_CAST (CB_TAG_FUNCALL, struct cb_funcall, x))
#define CB_FUNCALL_P(x)		(CB_TREE_TAG (x) == CB_TAG_FUNCALL)

/* Type cast */

struct cb_cast {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			val;
	enum cb_cast_type	cast_type;
};

#define CB_CAST(x)	(CB_TREE_CAST (CB_TAG_CAST, struct cb_cast, x))
#define CB_CAST_P(x)	(CB_TREE_TAG (x) == CB_TAG_CAST)

/* Assign */

struct cb_assign {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			var;
	cb_tree			val;
};

#define CB_ASSIGN(x)		(CB_TREE_CAST (CB_TAG_ASSIGN, struct cb_assign, x))
#define CB_ASSIGN_P(x)		(CB_TREE_TAG (x) == CB_TAG_ASSIGN)

/* Intrinsic FUNCTION */

struct cb_intrinsic_table {
	const char		*name;		/* FUNCTION NAME */
	const char		*intr_routine;	/* Routine name */
	const int		args;		/* 0-n, negative = variable */
	const int		implemented;	/* Have we implemented it? */
	const enum cb_intr_enum	intr_enum;	/* Enum intrinsic */
	const enum cb_category	category;	/* Category */
	const unsigned int	refmod;		/* Can be refmodded */
	const int		min_args;	/* Minimum number of args */
	const int		token;		/* Token value */
};

struct cb_intrinsic {
	struct cb_tree_common		common;		/* Common values */
	cb_tree				name;		/* INTRINSIC name */
	cb_tree				args;		/* Arguments */
	cb_tree				intr_field;	/* Field to use */
	struct cb_intrinsic_table	*intr_tab;	/* Table pointer */
	cb_tree				offset;		/* Reference mod */
	cb_tree				length;		/* Reference mod */
	int				isuser;		/* User function */
};

#define CB_INTRINSIC(x)		(CB_TREE_CAST (CB_TAG_INTRINSIC, struct cb_intrinsic, x))
#define CB_INTRINSIC_P(x)	(CB_TREE_TAG (x) == CB_TAG_INTRINSIC)

/* INITIALIZE */

struct cb_initialize {
	struct cb_tree_common	common;			/* Common values */
	cb_tree			var;			/* Field */
	cb_tree			val;			/* Value */
	cb_tree			rep;			/* Replacing */
	unsigned char		flag_default;		/* Default */
	unsigned char		flag_init_statement;	/* INITIALIZE statement */
	unsigned char		flag_no_filler_init;	/* No FILLER initialize */
	unsigned char		padding;		/* Padding */
};

#define CB_INITIALIZE(x)	(CB_TREE_CAST (CB_TAG_INITIALIZE, struct cb_initialize, x))
#define CB_INITIALIZE_P(x)	(CB_TREE_TAG (x) == CB_TAG_INITIALIZE)

/* SEARCH */

struct cb_search {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			table;		/* Table name */
	cb_tree			var;		/* Varying */
	cb_tree			end_stmt;	/* AT END */
	cb_tree			whens;		/* WHEN */
	int			flag_all;	/* SEARCH ALL */
};

#define CB_SEARCH(x)		(CB_TREE_CAST (CB_TAG_SEARCH, struct cb_search, x))
#define CB_SEARCH_P(x)		(CB_TREE_TAG (x) == CB_TAG_SEARCH)

/* CALL */

struct cb_call {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			name;		/* CALL name */
	cb_tree			args;		/* Arguments */
	cb_tree			stmt1;		/* ON EXCEPTION */
	cb_tree			stmt2;		/* NOT ON EXCEPTION */
	cb_tree			call_returning;	/* RETURNING */
	cob_u32_t		is_system;	/* System call */
	int			convention;	/* CALL convention */
};

#define CB_CALL(x)		(CB_TREE_CAST (CB_TAG_CALL, struct cb_call, x))
#define CB_CALL_P(x)		(CB_TREE_TAG (x) == CB_TAG_CALL)

/* CANCEL */

struct cb_cancel {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			target;		/* CANCEL target(s) */
};

#define CB_CANCEL(x)		(CB_TREE_CAST (CB_TAG_CANCEL, struct cb_cancel, x))
#define CB_CANCEL_P(x)		(CB_TREE_TAG (x) == CB_TAG_CANCEL)

/* ALTER */

struct cb_alter {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			source;		/* ALTER source paragraph */
	cb_tree			target;		/* ALTER target GO TO paragraph */
};

#define CB_ALTER(x)		(CB_TREE_CAST (CB_TAG_ALTER, struct cb_alter, x))
#define CB_ALTER_P(x)		(CB_TREE_TAG (x) == CB_TAG_ALTER)

/* GO TO */

struct cb_goto {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			target;		/* Procedure name(s) */
	cb_tree			depending;	/* DEPENDING */
};

#define CB_GOTO(x)		(CB_TREE_CAST (CB_TAG_GOTO, struct cb_goto, x))
#define CB_GOTO_P(x)		(CB_TREE_TAG (x) == CB_TAG_GOTO)

/* IF */

struct cb_if {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			test;		/* Condition */
	cb_tree			stmt1;		/* Statement list */
	cb_tree			stmt2;		/* ELSE/WHEN statement list */
	unsigned int		is_if;		/* From IF */
};

#define CB_IF(x)		(CB_TREE_CAST (CB_TAG_IF, struct cb_if, x))
#define CB_IF_P(x)		(CB_TREE_TAG (x) == CB_TAG_IF)

/* PERFORM */

struct cb_perform_varying {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			name;		/* VARYING item */
	cb_tree			from;		/* FROM */
	cb_tree			step;		/* Increment */
	cb_tree			until;		/* UNTIL */
};

struct cb_perform {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			test;		/* Condition */
	cb_tree			body;		/* Statements */
	cb_tree			data;		/* TIMES or procedure */
	cb_tree			varying;	/* VARYING */
	cb_tree			exit_label;	/* Implicit exit label */
	cb_tree			cycle_label;	/* EXIT PERFORM CYCLE */
	enum cb_perform_type	perform_type;	/* Perform type */
};

#define CB_PERFORM_VARYING(x)	(CB_TREE_CAST (CB_TAG_PERFORM_VARYING, struct cb_perform_varying, x))

#define CB_PERFORM(x)		(CB_TREE_CAST (CB_TAG_PERFORM, struct cb_perform, x))
#define CB_PERFORM_P(x)		(CB_TREE_TAG (x) == CB_TAG_PERFORM)

/* Struct for extended ACCEPT / DISPLAY */

struct cb_attr_struct {
	cb_tree			fgc;		/* FOREGROUND COLOR */
	cb_tree			bgc;		/* BACKGROUND COLOR */
	cb_tree			scroll;		/* SCROLL */
	cb_tree			timeout;	/* TIMEOUT */
	cb_tree			prompt;		/* PROMPT */
	int			dispattrs;	/* Attributes */
};

/* Statement */

struct cb_statement {
	struct cb_tree_common	common;			/* Common values */
	const char		*name;			/* Statement name */
	const char		*statement;		/* Statement line */
	cb_tree			body;			/* Statement body */
	cb_tree			file;			/* File reference */
	cb_tree			handler1;		/* Exception handler */
	cb_tree			handler2;		/* Exception handler */
	cb_tree			handler3;		/* INTO clause */
	cb_tree			null_check;		/* NULL check */
	cb_tree			debug_check;		/* Field DEBUG */
	cb_tree			debug_nodups;		/* Field DEBUG dups */
	struct cb_attr_struct	*attr_ptr;		/* Attributes */
	int			handler_id;		/* Handler id */
	unsigned int		flag_no_based	: 1;	/* Check BASED */
	unsigned int		flag_in_debug	: 1;	/* In DEBUGGING */
	unsigned int		flag_merge	: 1;	/* Is MERGE */
	unsigned int		flag_callback	: 1;	/* DEBUG Callback */
};

#define CB_STATEMENT(x)		(CB_TREE_CAST (CB_TAG_STATEMENT, struct cb_statement, x))
#define CB_STATEMENT_P(x)	(CB_TREE_TAG (x) == CB_TAG_STATEMENT)

/* CONTINUE */

struct cb_continue {
	struct cb_tree_common	common;		/* Common values */
};

#define CB_CONTINUE(x)		(CB_TREE_CAST (CB_TAG_CONTINUE, struct cb_continue, x))
#define CB_CONTINUE_P(x)	(CB_TREE_TAG (x) == CB_TAG_CONTINUE)

/* SET ATTRIBUTE */

struct cb_set_attr {
	struct cb_tree_common	common;		/* Common values */
	struct cb_field		*fld;
	int			val_on;
	int			val_off;
};

#define CB_SET_ATTR(x)		(CB_TREE_CAST (CB_TAG_SET_ATTR, struct cb_set_attr, x))
#define CB_SET_ATTR_P(x)	(CB_TREE_TAG (x) == CB_TAG_SET_ATTR)

/* List */

struct cb_list {
	struct cb_tree_common	common;		/* Common values */
	cb_tree			chain;		/* Next in list */
	cb_tree			value;		/* Reference to item(s) */
	cb_tree			purpose;	/* Purpose */
	int			sizes;		/* BY VALUE SIZE */
};

#define CB_LIST(x)	(CB_TREE_CAST (CB_TAG_LIST, struct cb_list, x))
#define CB_LIST_P(x)	(CB_TREE_TAG (x) == CB_TAG_LIST)

#define CB_PURPOSE(x)			(CB_LIST (x)->purpose)
#define CB_VALUE(x)			(CB_LIST (x)->value)
#define CB_CHAIN(x)			(CB_LIST (x)->chain)
#define CB_SIZES(x)			(CB_LIST (x)->sizes)

#define CB_PURPOSE_INT(x)		(CB_INTEGER (CB_PURPOSE (x))->val)

#define CB_SIZES_INT(x)			((CB_LIST (x)->sizes) & 0x07)
#define CB_SIZES_INT_UNSIGNED(x)	((CB_LIST (x)->sizes) & CB_SIZE_UNSIGNED)

/* Pair */

#define CB_PAIR_P(x)		(CB_LIST_P (x) && CB_PAIR_X (x))
#define CB_PAIR_X(x)		CB_PURPOSE (x)
#define CB_PAIR_Y(x)		CB_VALUE (x)

/* Report */

struct cb_report {
	struct cb_tree_common	common;		/* Common values */
	const char		*name;		/* Original name */
	char			*cname;		/* Name used in C */
	struct cb_file		*file;		/* File */
	cb_tree			line_counter;	/* LINE-COUNTER */
	cb_tree			page_counter;	/* PAGE-COUNTER */
	cb_tree			code_clause;	/* CODE */
	cb_tree			controls;	/* CONTROLS */
	int			lines;		/* PAGE LIMIT LINES */
	int			columns;	/* PAGE LIMIT COLUMNS */
	int			heading;	/* HEADING */
	int			first_detail;	/* FIRST DE */
	int			last_control;	/* LAST CH */
	int			last_detail;	/* LAST DE */
	int			footing;	/* FOOTING */
};

#define CB_REPORT(x)	(CB_TREE_CAST (CB_TAG_REPORT, struct cb_report, x))
#define CB_REPORT_P(x)	(CB_TREE_TAG (x) == CB_TAG_REPORT)

/* Program */

struct nested_list {
	struct nested_list	*next;
	struct cb_program	*nested_prog;
};

struct cb_program {
	/* Program variables */
	struct cb_program	*next_program;		/* Nested/contained */
	const char		*program_id;		/* Demangled PROGRAM-ID */
	char			*source_name;		/* Source name */
	char			*orig_program_id;	/* Original PROGRAM-ID */
	struct cb_word		**word_table;		/* Name hash table */
	struct local_filename	*local_include;		/* Local include info */
	struct nested_list	*nested_prog_list;	/* Callable contained */
	struct nested_list	*common_prog_list;	/* COMMON contained */
	cb_tree			entry_list;		/* Entry point list */
	cb_tree			file_list;		/* File list */
	cb_tree			exec_list;		/* Executable statements */
	cb_tree			label_list;		/* Label list */
	cb_tree			reference_list;		/* Reference list */
	cb_tree			alphabet_name_list;	/* ALPHABET list */
	cb_tree			symbolic_char_list;	/* SYMBOLIC list */
	cb_tree			class_name_list;	/* CLASS list */
	cb_tree			parameter_list;		/* USING parameters */
	cb_tree			locale_list;		/* LOCALE list */
	cb_tree			global_list;		/* GLOBAL list */
	cb_tree			report_list;		/* REPORT list */
	cb_tree			alter_list;		/* ALTER list */
	cb_tree			debug_list;		/* DEBUG ref list */
	cb_tree			cb_return_code;		/* RETURN-CODE */
	cb_tree			cb_sort_return;		/* SORT-RETURN */
	cb_tree			cb_call_params;		/* Number of CALL params */
	cb_tree			mnemonic_spec_list;	/* MNEMONIC spec */
	cb_tree			class_spec_list;	/* CLASS spec */
	cb_tree			interface_spec_list;	/* INTERFACE spec */
	cb_tree			function_spec_list;	/* FUNCTION spec */
	cb_tree			user_spec_list;		/* User FUNCTION spec */
	cb_tree			program_spec_list;	/* PROGRAM spec */
	cb_tree			property_spec_list;	/* PROPERTY spec */
	struct cb_alter_id	*alter_gotos;		/* ALTER ids */
	struct cb_field		*working_storage;	/* WORKING-STORAGE */
	struct cb_field		*local_storage;		/* LOCAL-STORAGE */
	struct cb_field		*linkage_storage;	/* LINKAGE */
	struct cb_field		*screen_storage;	/* SCREEN */
	struct cb_field		*report_storage;	/* REPORT */
	cb_tree			local_file_list;	/* Local files */
	cb_tree			global_file_list;	/* Global files */
	struct handler_struct	global_handler[5];	/* Global handlers */
	cb_tree			collating_sequence;	/* COLLATING */
	cb_tree			classification;		/* CLASSIFICATION */
	cb_tree			cursor_pos;		/* CURSOR */
	cb_tree			crt_status;		/* CRT STATUS */
	cb_tree			returning;		/* RETURNING */
	struct cb_label		*all_procedure;		/* DEBUGGING */

	/* Internal variables */
	int		loop_counter;			/* Loop counters */
	int		decimal_index;			/* cob_decimal count */
	int		decimal_index_max;		/* cob_decimal max */
	int		nested_level;			/* Nested program level */
	int		num_proc_params;		/* PROC DIV params */
	int		toplev_count;			/* Top level source count */
	int		max_call_param;			/* Max params */

	unsigned char	decimal_point;			/* '.' or ',' */
	unsigned char	currency_symbol;		/* '$' or user-specified */
	unsigned char	numeric_separator;		/* ',' or '.' */
	unsigned char	prog_type;			/* Program type */

	unsigned int	flag_main		: 1;	/* Gen main function */
	unsigned int	flag_common		: 1;	/* COMMON PROGRAM */
	unsigned int	flag_initial		: 1;	/* INITIAL PROGRAM */
	unsigned int	flag_recursive		: 1;	/* RECURSIVE PROGRAM */
	unsigned int	flag_screen		: 1;	/* Have SCREEN SECTION */
	unsigned int	flag_validated		: 1;	/* End program validate */
	unsigned int	flag_chained		: 1;	/* PROCEDURE CHAINING */
	unsigned int	flag_global_use		: 1;	/* USE GLOBAL */

	unsigned int	flag_gen_error		: 1;	/* Gen error routine */
	unsigned int	flag_file_global	: 1;	/* Global FD */
	unsigned int	flag_has_external	: 1;	/* Has EXTERNAL */
	unsigned int	flag_segments		: 1;	/* Has segments */
	unsigned int	flag_trailing_separate	: 1;	/* TRAILING SEPARATE */
	unsigned int	flag_console_is_crt	: 1;	/* CONSOLE IS CRT */
	unsigned int	flag_debugging		: 1;	/* DEBUGGING MODE */
	unsigned int	flag_gen_debug		: 1;	/* DEBUGGING MODE */

	unsigned int	flag_save_exception	: 1;	/* Save execption code */
};


/* Functions/variables */

/* tree.c */

extern cb_tree			cb_any;
extern cb_tree			cb_true;
extern cb_tree			cb_false;
extern cb_tree			cb_null;
extern cb_tree			cb_zero;
extern cb_tree			cb_one;
extern cb_tree			cb_space;
extern cb_tree			cb_low;
extern cb_tree			cb_high;
extern cb_tree			cb_norm_low;
extern cb_tree			cb_norm_high;
extern cb_tree			cb_quote;
extern cb_tree			cb_int0;
extern cb_tree			cb_int1;
extern cb_tree			cb_int2;
extern cb_tree			cb_int3;
extern cb_tree			cb_int4;
extern cb_tree			cb_int5;
extern cb_tree			cb_i[COB_MAX_SUBSCRIPTS];
extern cb_tree			cb_error_node;

extern cb_tree			cb_intr_whencomp;

extern cb_tree			cb_standard_error_handler;
extern cb_tree			cb_depend_check;

extern unsigned int		gen_screen_ptr;

extern char			*cb_name (cb_tree);
extern enum cb_class		cb_tree_class (cb_tree);
extern enum cb_category		cb_tree_category (cb_tree);
extern int			cb_tree_type (const cb_tree,
					      const struct cb_field *);
extern int			cb_category_is_alpha (cb_tree);
extern int			cb_fits_int (const cb_tree);
extern int			cb_fits_long_long (const cb_tree);
extern int			cb_get_int (const cb_tree);
extern cob_s64_t		cb_get_long_long (const cb_tree);
extern cob_u64_t		cb_get_u_long_long (const cb_tree);

extern void			cb_init_constants (void);

extern cb_tree			cb_int (const int);
extern cb_tree			cb_int_hex (const int);

extern cb_tree			cb_build_string (const void *, const size_t);

extern cb_tree			cb_build_class_name (cb_tree, cb_tree);

extern cb_tree			cb_build_locale_name (cb_tree, cb_tree);

extern cb_tree			cb_build_numeric_literal (const int,
							  const void *,
							  const int);
extern cb_tree			cb_build_alphanumeric_literal (const void *,
							       const size_t);
extern cb_tree			cb_build_numsize_literal (const void *,
							  const size_t,
							  const int);
extern cb_tree			cb_concat_literals (const cb_tree,
						    const cb_tree);

extern cb_tree			cb_build_decimal (const int);

extern cb_tree			cb_build_picture (const char *);
extern cb_tree			cb_build_comment (const char *);
extern cb_tree			cb_build_direct (const char *,
						 const unsigned int);
extern cb_tree			cb_build_debug (const cb_tree, const char *,
						const cb_tree);
extern cb_tree			cb_build_debug_call (struct cb_label *);

extern struct cb_picture	*cb_build_binary_picture (const char *,
							  const cob_u32_t,
							  const cob_u32_t);

extern cb_tree			cb_build_field (cb_tree);
extern cb_tree			cb_build_implicit_field (cb_tree, const int);
extern cb_tree			cb_build_constant (cb_tree, cb_tree);

extern void			cb_build_symbolic_chars (const cb_tree,
							 const cb_tree);

extern struct cb_field		*cb_field_add (struct cb_field *,
					       struct cb_field *);
extern int		             cb_field_size (cb_tree x);
extern struct cb_field		*cb_field_founder (const struct cb_field *);
extern struct cb_field		*cb_field_variable_size (const struct cb_field *);
extern unsigned int		cb_field_variable_address (const struct cb_field *);
extern int			cb_field_subordinate (const struct cb_field *,
						      const struct cb_field *);

extern cb_tree			cb_build_label (cb_tree, struct cb_label *);

extern struct cb_file		*build_file (cb_tree);
extern void			validate_file (struct cb_file *, cb_tree);
extern void			finalize_file (struct cb_file *,
					       struct cb_field *);

extern cb_tree			cb_build_filler (void);
extern cb_tree			cb_build_reference (const char *);
extern cb_tree			cb_build_field_reference (struct cb_field *,
							  cb_tree);
extern const char		*cb_define (cb_tree, cb_tree);
extern char			*cb_to_cname (const char *);
extern void			cb_set_system_names (void);
extern cb_tree			cb_ref (cb_tree);

extern cb_tree			cb_build_binary_op (cb_tree, const int,
						    cb_tree);
extern cb_tree			cb_build_binary_list (cb_tree, const int);

extern cb_tree			cb_build_funcall (const char *, const int,
						  const cb_tree, const cb_tree,
						  const cb_tree, const cb_tree,
						  const cb_tree, const cb_tree,
						  const cb_tree, const cb_tree,
						  const cb_tree, const cb_tree);

extern cb_tree			cb_build_cast (const enum cb_cast_type,
					       const cb_tree);
extern cb_tree			cb_build_cast_int (const cb_tree);
extern cb_tree			cb_build_cast_llint (const cb_tree);

extern cb_tree			cb_build_assign (const cb_tree, const cb_tree);

extern cb_tree			cb_build_intrinsic (cb_tree, cb_tree,
						    cb_tree, const int);
extern cb_tree			cb_build_any_intrinsic (cb_tree);

extern cb_tree			cb_build_search (const int,
						 const cb_tree, const cb_tree,
						 const cb_tree, const cb_tree);

extern cb_tree			cb_build_call (const cb_tree, const cb_tree,
					       const cb_tree, const cb_tree,
					       const cb_tree, const cob_u32_t,
					       const int);

extern cb_tree			cb_build_alter (const cb_tree, const cb_tree);

extern cb_tree			cb_build_cancel (const cb_tree);

extern cb_tree			cb_build_goto (const cb_tree, const cb_tree);

extern cb_tree			cb_build_if (const cb_tree, const cb_tree,
					     const cb_tree, const unsigned int);

extern cb_tree			cb_build_perform (const enum cb_perform_type);
extern cb_tree			cb_build_perform_varying (cb_tree, cb_tree,
							  cb_tree, cb_tree);

extern struct cb_statement	*cb_build_statement (const char *);

extern cb_tree			cb_build_continue (void);

extern cb_tree			cb_build_list (cb_tree, cb_tree, cb_tree);
extern cb_tree			cb_list_add (cb_tree, cb_tree);
extern cb_tree			cb_pair_add (cb_tree, cb_tree, cb_tree);
extern cb_tree			cb_list_append (cb_tree, cb_tree);
extern cb_tree			cb_list_reverse (cb_tree);
extern int			cb_list_length (cb_tree);

extern struct cb_report		*build_report (cb_tree);

extern void			cb_add_common_prog (struct cb_program *);
extern void			cb_insert_common_prog (struct cb_program *,
						       struct cb_program *);


extern struct cb_intrinsic_table	*lookup_intrinsic (const char *,
							   const int,
							   const int);

extern cb_tree		cb_build_alphabet_name (cb_tree);

extern cb_tree		cb_build_initialize (const cb_tree, const cb_tree,
					     const cb_tree,
					     const unsigned int,
					     const unsigned int,
					     const unsigned int);

struct cb_literal	*build_literal (enum cb_category,
					const void *,
					const size_t);

extern cb_tree	cb_build_system_name (const enum cb_system_name_category,
				      const int);

/* parser.y */
extern cb_tree		cobc_printer_node;
extern int		non_const_word;
extern unsigned int	cobc_in_procedure;
extern unsigned int	cobc_in_repository;
extern unsigned int	cobc_force_literal;
extern unsigned int	cobc_cs_check;

/* reserved.c */
extern struct cobc_reserved	*lookup_reserved_word (const char *);
extern cb_tree			lookup_system_name (const char *);
extern void			cb_list_reserved (void);
extern void			cb_list_intrinsics (void);
extern void			cb_list_mnemonics (void);
extern void			cb_list_system (void);
extern void			cb_list_map (cb_tree (*) (cb_tree), cb_tree);

/* error.c */
extern void	cb_warning_x (cb_tree, const char *, ...) COB_A_FORMAT23;
extern void	cb_error_x (cb_tree, const char *, ...) COB_A_FORMAT23;

extern void		redefinition_error (cb_tree);
extern void		redefinition_warning (cb_tree, cb_tree);
extern void		undefined_error (cb_tree);
extern void		ambiguous_error (cb_tree);
extern void		group_error (cb_tree, const char *);
extern void		level_redundant_error (cb_tree, const char *);
extern void		level_require_error (cb_tree, const char *);
extern void		level_except_error (cb_tree, const char *);

/* field.c */
extern size_t		cb_needs_01;
extern int		cb_get_level (cb_tree);
extern cb_tree		cb_build_field_tree (cb_tree, cb_tree, struct cb_field *,
					     enum cb_storage, struct cb_file *,
					     const int);
extern struct cb_field	*cb_resolve_redefines (struct cb_field *, cb_tree);
extern void		cb_validate_field (struct cb_field *);
extern void		cb_validate_88_item (struct cb_field *);
extern struct cb_field	*cb_validate_78_item (struct cb_field *, const cob_u32_t);
extern struct cb_field	*cb_get_real_field (void);
extern void		cb_clear_real_field (void);

/* typeck.c */
extern cb_tree		cb_debug_item;
extern cb_tree		cb_debug_line;
extern cb_tree		cb_debug_name;
extern cb_tree		cb_debug_sub_1;
extern cb_tree		cb_debug_sub_2;
extern cb_tree		cb_debug_sub_3;
extern cb_tree		cb_debug_contents;

extern struct cb_program	*cb_build_program (struct cb_program *,
						   const int);

extern cb_tree		cb_check_numeric_value (cb_tree);
extern size_t		cb_check_index_p (cb_tree x);

extern void		cb_build_registers (void);
extern void		cb_build_debug_item (void);
extern void		cb_check_field_debug (cb_tree);
extern char		*cb_encode_program_id (const char *);
extern char		*cb_build_program_id (cb_tree, cb_tree, const cob_u32_t);
extern cb_tree		cb_define_switch_name (cb_tree, cb_tree, const int);
extern cb_tree		cb_build_section_name (cb_tree, const int);
extern cb_tree		cb_build_assignment_name (struct cb_file *, cb_tree);
extern cb_tree		cb_build_index (cb_tree, cb_tree,
					const unsigned int, struct cb_field *);
extern cb_tree		cb_build_identifier (cb_tree, const int);
extern cb_tree		cb_build_length (cb_tree);
extern cb_tree		cb_build_const_length (cb_tree);
extern cb_tree		cb_build_address (cb_tree);
extern cb_tree		cb_build_ppointer (cb_tree);

extern void		cb_validate_program_environment (struct cb_program *);
extern void		cb_validate_program_data (struct cb_program *);
extern void		cb_validate_program_body (struct cb_program *);

extern cb_tree		cb_build_expr (cb_tree);
extern cb_tree		cb_build_cond (cb_tree);

extern void		cb_emit_arithmetic (cb_tree, const int, cb_tree);
extern cb_tree		cb_build_add (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_sub (cb_tree, cb_tree, cb_tree);
extern void		cb_emit_corresponding (
				cb_tree (*) (cb_tree, cb_tree, cb_tree),
				cb_tree, cb_tree, cb_tree);
extern void		cb_emit_move_corresponding (cb_tree, cb_tree);

extern void		cb_emit_accept (cb_tree, cb_tree,
					struct cb_attr_struct *);
extern void		cb_emit_accept_line_or_col (cb_tree, const int);
extern void		cb_emit_accept_escape_key (cb_tree);
extern void		cb_emit_accept_exception_status (cb_tree);
extern void		cb_emit_accept_user_name (cb_tree);
extern void		cb_emit_accept_date (cb_tree);
extern void		cb_emit_accept_date_yyyymmdd (cb_tree);
extern void		cb_emit_accept_day (cb_tree);
extern void		cb_emit_accept_day_yyyyddd (cb_tree);
extern void		cb_emit_accept_day_of_week (cb_tree);
extern void		cb_emit_accept_time (cb_tree);
extern void		cb_emit_accept_command_line (cb_tree);
extern void		cb_emit_accept_environment (cb_tree);
extern void		cb_emit_accept_mnemonic (cb_tree, cb_tree);
extern void		cb_emit_accept_name (cb_tree, cb_tree);
extern void		cb_emit_accept_arg_number (cb_tree);
extern void		cb_emit_accept_arg_value (cb_tree);
extern void		cb_emit_get_environment (cb_tree, cb_tree);

extern void		cb_emit_allocate (cb_tree, cb_tree,
					  cb_tree, cb_tree);
extern void		cb_emit_alter (cb_tree, cb_tree);
extern void		cb_emit_free (cb_tree);

extern void		cb_emit_call (cb_tree, cb_tree, cb_tree, cb_tree,
				      cb_tree, cb_tree);

extern void		cb_emit_cancel (cb_tree);
extern void		cb_emit_close (cb_tree, cb_tree);
extern void		cb_emit_commit (void);
extern void		cb_emit_continue (void);
extern void		cb_emit_delete (cb_tree);
extern void		cb_emit_delete_file (cb_tree);
extern void		cb_emit_display (cb_tree, cb_tree,
					 cb_tree, cb_tree,
					 struct cb_attr_struct *);
extern cb_tree		cb_build_display_mnemonic (cb_tree);
extern cb_tree		cb_build_display_name (cb_tree);
extern void		cb_emit_env_name (cb_tree);
extern void		cb_emit_env_value (cb_tree);
extern void		cb_emit_arg_number (cb_tree);
extern void		cb_emit_command_line (cb_tree);

extern void		cb_emit_divide (cb_tree, cb_tree,
					cb_tree, cb_tree);

extern void		cb_emit_evaluate (cb_tree, cb_tree);

extern void		cb_emit_goto (cb_tree, cb_tree);
extern void		cb_emit_exit (const unsigned int);

extern void		cb_emit_if (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_if_check_break (cb_tree, cb_tree);

extern void		cb_emit_initialize (cb_tree, cb_tree,
					    cb_tree, cb_tree,
					    cb_tree);

extern void		cb_emit_inspect (cb_tree, cb_tree,
					 cb_tree, const unsigned int);
extern void		cb_init_tallying (void);
extern cb_tree		cb_build_tallying_data (cb_tree);
extern cb_tree		cb_build_tallying_characters (cb_tree);
extern cb_tree		cb_build_tallying_all (void);
extern cb_tree		cb_build_tallying_leading (void);
extern cb_tree		cb_build_tallying_trailing (void);
extern cb_tree		cb_build_tallying_value (cb_tree, cb_tree);
extern cb_tree		cb_build_replacing_characters (cb_tree, cb_tree);
extern cb_tree		cb_build_replacing_all (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_replacing_leading (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_replacing_first (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_replacing_trailing (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_converting (cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_inspect_region_start (void);

extern int		validate_move (cb_tree, cb_tree, const unsigned int);
extern cb_tree		cb_build_move (cb_tree, cb_tree);
extern void		cb_emit_move (cb_tree, cb_tree);

extern void		cb_emit_open (cb_tree, cb_tree, cb_tree);

extern void		cb_emit_perform (cb_tree, cb_tree);
extern cb_tree		cb_build_perform_once (cb_tree);
extern cb_tree		cb_build_perform_times (cb_tree);
extern cb_tree		cb_build_perform_until (cb_tree, cb_tree);
extern cb_tree		cb_build_perform_forever (cb_tree);
extern cb_tree		cb_build_perform_exit (struct cb_label *);

extern void		cb_emit_read (cb_tree, cb_tree, cb_tree,
				      cb_tree, cb_tree);

extern void		cb_emit_ready_trace (void);
extern void		cb_emit_rewrite (cb_tree, cb_tree, cb_tree);

extern void		cb_emit_release (cb_tree, cb_tree);
extern void		cb_emit_reset_trace (void);
extern void		cb_emit_return (cb_tree, cb_tree);

extern void		cb_emit_rollback (void);

extern void		cb_emit_search (cb_tree, cb_tree,
					cb_tree, cb_tree);
extern void		cb_emit_search_all (cb_tree, cb_tree,
					    cb_tree, cb_tree);

extern void		cb_emit_setenv (cb_tree, cb_tree);
extern void		cb_emit_set_to (cb_tree, cb_tree);
extern void		cb_emit_set_up_down (cb_tree, cb_tree, cb_tree);
extern void		cb_emit_set_on_off (cb_tree, cb_tree);
extern void		cb_emit_set_true (cb_tree);
extern void		cb_emit_set_false (cb_tree);
extern void		cb_emit_set_attribute (cb_tree, const int, const int);
extern cb_tree		cb_build_set_attribute (const struct cb_field *,
						const int, const int);

extern void		cb_emit_sort_init (cb_tree, cb_tree, cb_tree);
extern void		cb_emit_sort_using (cb_tree, cb_tree);
extern void		cb_emit_sort_input (cb_tree);
extern void		cb_emit_sort_giving (cb_tree, cb_tree);
extern void		cb_emit_sort_output (cb_tree);
extern void		cb_emit_sort_finish (cb_tree);

extern void		cb_emit_start (cb_tree, cb_tree, cb_tree, cb_tree);

extern void		cb_emit_stop_run (cb_tree);

extern void		cb_emit_string (cb_tree, cb_tree, cb_tree);

extern void		cb_emit_unlock (cb_tree);

extern void		cb_emit_unstring (cb_tree, cb_tree, cb_tree, cb_tree,
					  cb_tree);
extern cb_tree		cb_build_unstring_delimited (cb_tree, cb_tree);
extern cb_tree		cb_build_unstring_into (cb_tree, cb_tree, cb_tree);

extern void		cb_emit_write (cb_tree, cb_tree, cb_tree, cb_tree);
extern cb_tree		cb_build_write_advancing_lines (cb_tree, cb_tree);
extern cb_tree		cb_build_write_advancing_mnemonic (cb_tree, cb_tree);
extern cb_tree		cb_build_write_advancing_page (cb_tree);

DECLNORET extern void	cobc_tree_cast_error (const cb_tree, const char *,
					      const int,
					      const enum cb_tag) COB_A_NORETURN;

#if	!defined(__GNUC__) && defined(COB_TREE_DEBUG)
extern cb_tree		cobc_tree_cast_check (const cb_tree, const char *,
					      const int, const enum cb_tag);
#endif


/* codegen.c */
extern void		codegen (struct cb_program *, const int);

/* scanner.l */
extern void		cb_unput_dot (void);
extern void		cb_add_78 (struct cb_field *);
extern void		cb_reset_78 (void);
extern void		cb_reset_global_78 (void);
extern struct cb_field	*check_level_78 (const char *);

/* Function defines */

#define CB_BUILD_FUNCALL_0(f)					\
	cb_build_funcall (f, 0, NULL, NULL, NULL, NULL, NULL,	\
			  NULL, NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_1(f,a1)				\
	cb_build_funcall (f, 1, a1, NULL, NULL, NULL, NULL,	\
			  NULL, NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_2(f,a1,a2)				\
	cb_build_funcall (f, 2, a1, a2, NULL, NULL, NULL,	\
			  NULL, NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_3(f,a1,a2,a3)				\
	cb_build_funcall (f, 3, a1, a2, a3, NULL, NULL,		\
			  NULL, NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_4(f,a1,a2,a3,a4)			\
	cb_build_funcall (f, 4, a1, a2, a3, a4, NULL,		\
			  NULL, NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_5(f,a1,a2,a3,a4,a5)			\
	cb_build_funcall (f, 5, a1, a2, a3, a4, a5,		\
			  NULL, NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_6(f,a1,a2,a3,a4,a5,a6)			\
	cb_build_funcall (f, 6, a1, a2, a3, a4, a5, a6,		\
			  NULL, NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_7(f,a1,a2,a3,a4,a5,a6,a7)		\
	cb_build_funcall (f, 7, a1, a2, a3, a4, a5, a6, a7,	\
			  NULL, NULL, NULL)

#define CB_BUILD_FUNCALL_8(f,a1,a2,a3,a4,a5,a6,a7,a8)		\
	cb_build_funcall (f, 8, a1, a2, a3, a4, a5, a6, a7, a8,	\
			  NULL, NULL)

#define CB_BUILD_FUNCALL_9(f,a1,a2,a3,a4,a5,a6,a7,a8,a9)	\
	cb_build_funcall (f, 9, a1, a2, a3, a4, a5, a6, a7, a8,	\
			  a9, NULL)

/* Miscellanous defines */

#define CB_BUILD_CAST_ADDRESS(x)	cb_build_cast (CB_CAST_ADDRESS, x)
#define CB_BUILD_CAST_ADDR_OF_ADDR(x)	cb_build_cast (CB_CAST_ADDR_OF_ADDR, x)
#define CB_BUILD_CAST_LENGTH(x)		cb_build_cast (CB_CAST_LENGTH, x)
#define CB_BUILD_CAST_PPOINTER(x)	cb_build_cast (CB_CAST_PROGRAM_POINTER, x)

#define CB_BUILD_PARENTHESIS(x)		cb_build_binary_op (x, '@', NULL)
#define CB_BUILD_NEGATION(x)		cb_build_binary_op (x, '!', NULL)

#define CB_BUILD_STRING0(str)		cb_build_string (str, strlen ((char *)(str)))

#define CB_LIST_INIT(x)			cb_build_list (NULL, x, NULL)
#define CB_BUILD_CHAIN(x,y)		cb_build_list (NULL, x, y)
#define CB_BUILD_PAIR(x,y)		cb_build_list (x, y, NULL)
#define CB_ADD_TO_CHAIN(x,y)		y = CB_BUILD_CHAIN (x, y)
#define CB_CHAIN_PAIR(x,y,z)		x = cb_pair_add (x, y, z)
#define CB_FIELD_ADD(x,y)		x = cb_field_add (x, y)


#endif /* CB_TREE_H */
