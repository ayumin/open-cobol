/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While
   Copyright (C) 2013 Sergey Kashyrin

   This file is part of GNU Cobol C++.

   The GNU Cobol C++ compiler is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol C++ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#include "cobc.h"
#include "tree.h"
#include "parser.hpp"

struct system_struct {
	const char *			name;
	cb_system_name_category	category;
	int						token;
};

static const system_struct	system_table[] = {
	{"SYSIN",			CB_DEVICE_NAME,  CB_DEVICE_SYSIN},
	{"SYSIPT",			CB_DEVICE_NAME,  CB_DEVICE_SYSIN},
	{"STDIN",			CB_DEVICE_NAME,  CB_DEVICE_SYSIN},
	{"SYSOUT",			CB_DEVICE_NAME,  CB_DEVICE_SYSOUT},
	{"SYSLIST",			CB_DEVICE_NAME,  CB_DEVICE_SYSOUT},
	{"SYSLST",			CB_DEVICE_NAME,  CB_DEVICE_SYSOUT},
	{"STDOUT",			CB_DEVICE_NAME,  CB_DEVICE_SYSOUT},
	{"PRINTER",			CB_DEVICE_NAME,  CB_DEVICE_SYSOUT},
	{"SYSERR",			CB_DEVICE_NAME,  CB_DEVICE_SYSERR},
	{"STDERR",			CB_DEVICE_NAME,  CB_DEVICE_SYSERR},
	{"CONSOLE",			CB_DEVICE_NAME,  CB_DEVICE_CONSOLE},
	{"C01",				CB_FEATURE_NAME, CB_FEATURE_C01},
	{"C02",				CB_FEATURE_NAME, CB_FEATURE_C02},
	{"C03",				CB_FEATURE_NAME, CB_FEATURE_C03},
	{"C04",				CB_FEATURE_NAME, CB_FEATURE_C04},
	{"C05",				CB_FEATURE_NAME, CB_FEATURE_C05},
	{"C06",				CB_FEATURE_NAME, CB_FEATURE_C06},
	{"C07",				CB_FEATURE_NAME, CB_FEATURE_C07},
	{"C08",				CB_FEATURE_NAME, CB_FEATURE_C08},
	{"C09",				CB_FEATURE_NAME, CB_FEATURE_C09},
	{"C10",				CB_FEATURE_NAME, CB_FEATURE_C10},
	{"C11",				CB_FEATURE_NAME, CB_FEATURE_C11},
	{"C12",				CB_FEATURE_NAME, CB_FEATURE_C12},
	{"CSP",				CB_FEATURE_NAME, CB_FEATURE_FORMFEED},
	{"FORMFEED",		CB_FEATURE_NAME, CB_FEATURE_FORMFEED},
	{"CALL-CONVENTION",	CB_FEATURE_NAME, CB_FEATURE_CONVENTION},
	{"SWITCH-0",		CB_SWITCH_NAME,  CB_SWITCH_0},
	{"SWITCH-1",		CB_SWITCH_NAME,  CB_SWITCH_1},
	{"SWITCH-2",		CB_SWITCH_NAME,  CB_SWITCH_2},
	{"SWITCH-3",		CB_SWITCH_NAME,  CB_SWITCH_3},
	{"SWITCH-4",		CB_SWITCH_NAME,  CB_SWITCH_4},
	{"SWITCH-5",		CB_SWITCH_NAME,  CB_SWITCH_5},
	{"SWITCH-6",		CB_SWITCH_NAME,  CB_SWITCH_6},
	{"SWITCH-7",		CB_SWITCH_NAME,  CB_SWITCH_7},
	{"SWITCH-8",		CB_SWITCH_NAME,  CB_SWITCH_8},
	{"SWITCH-9",		CB_SWITCH_NAME,  CB_SWITCH_9},
	{"SWITCH-10",		CB_SWITCH_NAME,  CB_SWITCH_10},
	{"SWITCH-11",		CB_SWITCH_NAME,  CB_SWITCH_11},
	{"SWITCH-12",		CB_SWITCH_NAME,  CB_SWITCH_12},
	{"SWITCH-13",		CB_SWITCH_NAME,  CB_SWITCH_13},
	{"SWITCH-14",		CB_SWITCH_NAME,  CB_SWITCH_14},
	{"SWITCH-15",		CB_SWITCH_NAME,  CB_SWITCH_15}
};

#define	SYSTEM_TAB_SIZE	sizeof(system_table) / sizeof(system_struct)

static const system_struct	ext_system_table[] = {
	{"SW0",			CB_SWITCH_NAME,  CB_SWITCH_0},
	{"SW1",			CB_SWITCH_NAME,  CB_SWITCH_1},
	{"SW2",			CB_SWITCH_NAME,  CB_SWITCH_2},
	{"SW3",			CB_SWITCH_NAME,  CB_SWITCH_3},
	{"SW4",			CB_SWITCH_NAME,  CB_SWITCH_4},
	{"SW5",			CB_SWITCH_NAME,  CB_SWITCH_5},
	{"SW6",			CB_SWITCH_NAME,  CB_SWITCH_6},
	{"SW7",			CB_SWITCH_NAME,  CB_SWITCH_7},
	{"SW8",			CB_SWITCH_NAME,  CB_SWITCH_8},
	{"SW9",			CB_SWITCH_NAME,  CB_SWITCH_9},
	{"SW10",		CB_SWITCH_NAME,  CB_SWITCH_10},
	{"SW11",		CB_SWITCH_NAME,  CB_SWITCH_11},
	{"SW12",		CB_SWITCH_NAME,  CB_SWITCH_12},
	{"SW13",		CB_SWITCH_NAME,  CB_SWITCH_13},
	{"SW14",		CB_SWITCH_NAME,  CB_SWITCH_14},
	{"SW15",		CB_SWITCH_NAME,  CB_SWITCH_15}
};

#define	EXT_SYSTEM_TAB_SIZE	\
	sizeof(ext_system_table) / sizeof(system_struct)

/* Reserved word table */
/* Must be ordered on word for binary search */
/* Description */

/* Word # Statement has terminator # Is context sensitive # Token */
/* Special context set # Special context test */

static const cobc_reserved reserved_words[] = {
  { "ACCEPT",			1, 0, ACCEPT,			/* 2002 */
						CB_CS_ACCEPT, 0
  },
  { "ACCESS",			0, 0, ACCESS,			/* 2002 */
						0, 0
  },
  { "ACTIVE-CLASS",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "ADD",				1, 0, ADD,				/* 2002 */
						0, 0
  },
  { "ADDRESS",			0, 0, ADDRESS,			/* 2002 */
						0, 0
  },
  { "ADVANCING",		0, 0, ADVANCING,		/* 2002 */
						0, 0
  },
  { "AFTER",			0, 0, AFTER,			/* 2002 */
						0, 0
  },
  { "ALIGNED",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "ALL",				0, 0, ALL,				/* 2002 */
						0, 0
  },
  { "ALLOCATE",			0, 0, ALLOCATE,			/* 2002 */
						0, 0
  },
  { "ALPHABET",			0, 0, ALPHABET,			/* 2002 */
						CB_CS_ALPHABET, 0
  },
  { "ALPHABETIC",		0, 0, ALPHABETIC,		/* 2002 */
						0, 0
  },
  { "ALPHABETIC-LOWER",	0, 0, ALPHABETIC_LOWER,	/* 2002 */
						0, 0
  },
  { "ALPHABETIC-UPPER",	0, 0, ALPHABETIC_UPPER,	/* 2002 */
						0, 0
  },
  { "ALPHANUMERIC",		0, 0, ALPHANUMERIC,		/* 2002 */
						0, 0
  },
  { "ALPHANUMERIC-EDITED",	0, 0, ALPHANUMERIC_EDITED,	/* 2002 */
						0, 0
  },
  { "ALSO",				0, 0, ALSO,				/* 2002 */
						0, 0
  },
  { "ALTER",			0, 0, ALTER,			/* 85 */
						0, 0
  },
  { "ALTERNATE",		0, 0, ALTERNATE,		/* 2002 */
						0, 0
  },
  { "AND",				0, 0, AND,				/* 2002 */
						0, 0
  },
  { "ANY",				0, 0, ANY,				/* 2002 */
						0, 0
  },
  { "ANYCASE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "ARE",				0, 0, ARE,				/* 2002 */
						0, 0
  },
  { "AREA",				0, 0, AREA,				/* 2002 */
						0, 0
  },
  { "AREAS",			0, 0, AREA,				/* 2002 */
						0, 0
  },
  { "ARGUMENT-NUMBER",	0, 0, ARGUMENT_NUMBER,	/* Extension */
						0, 0
  },
  { "ARGUMENT-VALUE",	0, 0, ARGUMENT_VALUE,	/* Extension */
						0, 0
  },
  { "ARITHMETIC",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "AS",				0, 0, AS,				/* 2002 */
						0, 0
  },
  { "ASCENDING",		0, 0, ASCENDING,		/* 2002 */
						0, 0
  },
  { "ASCII",			0, 1, ASCII,			/* Extension */
						0, CB_CS_ALPHABET
  },
  { "ASSIGN",			0, 0, ASSIGN,			/* 2002 */
						CB_CS_ASSIGN, 0
  },
  { "AT",				0, 0, AT,				/* 2002 */
						0, 0
  },
  { "ATTRIBUTE",		0, 1, ATTRIBUTE,		/* 2002(C/S) */
						0, CB_CS_SET
  },
  { "AUTO",				0, 0, AUTO,				/* 2002(C/S) */
						0, 0
  },
  { "AUTO-SKIP",		0, 0, AUTO,				/* Extension */
						0, 0
  },
  { "AUTOMATIC",		0, 0, AUTOMATIC,		/* 2002(C/S) */
						0, 0
  },
  { "AUTOTERMINATE",	0, 0, AUTO,				/* Extension */
						0, 0
  },
  { "AWAY-FROM-ZERO",	0, 1, AWAY_FROM_ZERO,	/* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "B-AND",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "B-NOT",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "B-OR",				0, 0, -1,				/* 2002 */
						0, 0
  },
  { "B-XOR",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "BACKGROUND-COLOR",	0, 0, BACKGROUND_COLOR,	/* 2002(C/S) */
						0, 0
  },
  { "BACKGROUND-COLOUR", 0, 0, BACKGROUND_COLOR, /* Extension */
						0, 0
  },
  { "BASED",			0, 0, BASED,			/* 2002 */
						0, 0
  },
  { "BEEP",				0, 0, BELL,				/* Extension */
						0, 0
  },
  { "BEFORE",			0, 0, BEFORE,			/* 2002 */
						0, 0
  },
  { "BELL",				0, 0, BELL,				/* 2002(C/S) */
						0, 0
  },
  { "BINARY",			0, 0, BINARY,			/* 2002 */
						0, 0
  },
  { "BINARY-C-LONG",	0, 0, BINARY_C_LONG,	/* Extension */
						0, 0
  },
  { "BINARY-CHAR",		0, 0, BINARY_CHAR,		/* 2002 */
						0, 0
  },
  { "BINARY-DOUBLE",	0, 0, BINARY_DOUBLE,	/* 2002 */
						0, 0
  },
  { "BINARY-INT",		0, 0, BINARY_LONG,		/* Extension */
						0, 0
  },
  { "BINARY-LONG",		0, 0, BINARY_LONG,		/* 2002 */
						0, 0
  },
  { "BINARY-LONG-LONG",	0, 0, BINARY_DOUBLE,	/* Extension */
						0, 0
  },
  { "BINARY-SHORT",		0, 0, BINARY_SHORT,		/* 2002 */
						0, 0
  },
  { "BIT",				0, 0, -1,				/* 2002 */
						0, 0
  },
  { "BLANK",			0, 0, BLANK,			/* 2002 */
						0, 0
  },
  { "BLINK",			0, 0, BLINK,			/* 2002(C/S) */
						0, 0
  },
  { "BLOCK",			0, 0, BLOCK,			/* 2002 */
						0, 0
  },
  { "BOOLEAN",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "BOTTOM",			0, 0, BOTTOM,			/* 2002 */
						0, 0
  },
  { "BY",				0, 0, BY,				/* 2002 */
						0, 0
  },
  { "BYTE-LENGTH",		0, 1, BYTE_LENGTH,		/* 2002(C/S) */
						0, CB_CS_CONSTANT
  },
  { "CALL",				1, 0, CALL,				/* 2002 */
						CB_CS_CALL, 0
  },
  { "CANCEL",			0, 0, CANCEL,			/* 2002 */
						0, 0
  },
  { "CAPACITY",			0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
  { "CD",				0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "CENTER",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "CF",				0, 0, CF,				/* 2002 */
						0, 0
  },
  { "CH",				0, 0, CH,				/* 2002 */
						0, 0
  },
  { "CHAIN",			0, 0, -1,				/* Extension */
						0, 0
  },
  { "CHAINING",			0, 0, CHAINING,			/* Extension */
						0, 0
  },
  { "CHARACTER",		0, 0, CHARACTER,		/* 2002 */
						0, 0
  },
  { "CHARACTERS",		0, 0, CHARACTERS,		/* 2002 */
						0, 0
  },
  { "CLASS",			0, 0, CLASS,			/* 2002 */
						0, 0
  },
  { "CLASS-ID",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "CLASSIFICATION",	0, 1, CLASSIFICATION,	/* 2002(C/S) */
						0, 0
  },
  { "CLOSE",			0, 0, CLOSE,			/* 2002 */
						0, 0
  },
  { "CODE",				0, 0, CODE,				/* 2002 */
						0, 0
  },
  { "CODE-SET",			0, 0, CODE_SET,			/* 2002 */
						0, 0
  },
  { "COL",				0, 0, COL,				/* 2002 */
						0, 0
  },
  { "COLLATING",		0, 0, COLLATING,		/* 2002 */
						0, 0
  },
  { "COLS",				0, 0, COLS,				/* 2002 */
						0, 0
  },
  { "COLUMN",			0, 0, COLUMN,			/* 2002 */
						0, 0
  },
  { "COLUMNS",			0, 0, COLUMNS,			/* 2002 */
						0, 0
  },
  { "COMMA",			0, 0, COMMA,			/* 2002 */
						0, 0
  },
  { "COMMAND-LINE",		0, 0, COMMAND_LINE,		/* Extension */
						0, 0
  },
  { "COMMIT",			0, 0, COMMIT,			/* Extension */
						0, 0
  },
  { "COMMON",			0, 0, COMMON,			/* 2002 */
						0, 0
  },
  { "COMMUNICATION",	0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "COMP",				0, 0, COMP,				/* 2002 */
						0, 0
  },
	/* Note EBCDIC! */
#ifdef	COB_EBCDIC_MACHINE
  { "COMP-X",			0, 0, COMP_X,			/* Extension */
						0, 0
  },
#endif
  { "COMP-1",			0, 0, COMP_1,			/* Extension */
						0, 0
  },
  { "COMP-2",			0, 0, COMP_2,			/* Extension */
						0, 0
  },
  { "COMP-3",			0, 0, COMP_3,			/* Extension */
						0, 0
  },
  { "COMP-4",			0, 0, COMP_4,			/* Extension */
						0, 0
  },
  { "COMP-5",			0, 0, COMP_5,			/* Extension */
						0, 0
  },
  { "COMP-6",			0, 0, COMP_6,			/* Extension */
						0, 0
  },
	/* Note EBCDIC! */
#ifndef	COB_EBCDIC_MACHINE
  { "COMP-X",			0, 0, COMP_X,			/* Extension */
						0, 0
  },
#endif
  { "COMPUTATIONAL",	0, 0, COMP,				/* 2002 */
						0, 0
  },
	/* Note EBCDIC! */
#ifdef	COB_EBCDIC_MACHINE
  { "COMPUTATIONAL-X",	0, 0, COMP_X,			/* Extension */
						0, 0
  },
#endif
  { "COMPUTATIONAL-1",	0, 0, COMP_1,			/* Extension */
						0, 0
  },
  { "COMPUTATIONAL-2",	0, 0, COMP_2,			/* Extension */
						0, 0
  },
  { "COMPUTATIONAL-3",	0, 0, COMP_3,			/* Extension */
						0, 0
  },
  { "COMPUTATIONAL-4",	0, 0, COMP_4,			/* Extension */
						0, 0
  },
  { "COMPUTATIONAL-5",	0, 0, COMP_5,			/* Extension */
						0, 0
  },
	/* Note EBCDIC! */
#ifndef	COB_EBCDIC_MACHINE
  { "COMPUTATIONAL-X",	0, 0, COMP_X,			/* Extension */
						0, 0
  },
#endif
  { "COMPUTE",			1, 0, COMPUTE,			/* 2002 */
						0, 0
  },
  { "CONDITION",		0, 0, CONDITION,		/* 2002 */
						0, 0
  },
  { "CONFIGURATION",	0, 0, CONFIGURATION,	/* 2002 */
						0, 0
  },
  { "CONSTANT",			0, 0, CONSTANT,			/* 2002 */
						CB_CS_CONSTANT, 0
  },
  { "CONTAINS",			0, 0, CONTAINS,			/* 2002 */
						0, 0
  },
  { "CONTENT",			0, 0, CONTENT,			/* 2002 */
						0, 0
  },
  { "CONTINUE",			0, 0, CONTINUE,			/* 2002 */
						0, 0
  },
  { "CONTROL",			0, 0, CONTROL,			/* 2002 */
						0, 0
  },
  { "CONTROLS",			0, 0, CONTROLS,			/* 2002 */
						0, 0
  },
  { "CONVERSION",		0, 1, CONVERSION,		/* Extension */
						0, CB_CS_WITH
  },
  { "CONVERTING",		0, 0, CONVERTING,		/* 2002 */
						0, 0
  },
  { "COPY",				0, 0, COPY,				/* 2002 */
						0, 0
  },
  { "CORR",				0, 0, CORRESPONDING,	/* 2002 */
						0, 0
  },
  { "CORRESPONDING",	0, 0, CORRESPONDING,	/* 2002 */
						0, 0
  },
  { "COUNT",			0, 0, COUNT,			/* 2002 */
						0, 0
  },
  { "CRT",				0, 0, CRT,				/* 2002 */
						0, 0
  },
  { "CRT-UNDER",		0, 0, CRT_UNDER,		/* Extension */
						0, 0
  },
  { "CURRENCY",			0, 0, CURRENCY,			/* 2002 */
						0, 0
  },
  { "CURSOR",			0, 0, CURSOR,			/* 2002 */
						0, 0
  },
  { "CYCLE",			0, 1, CYCLE,			/* 2002(C/S) */
						0, CB_CS_EXIT
  },
  { "DATA",				0, 0, DATA,				/* 2002 */
						0, 0
  },
  { "DATA-POINTER",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "DATE",				0, 0, DATE,				/* 2002 */
						CB_CS_DATE, 0
  },
  { "DAY",				0, 0, DAY,				/* 2002 */
						CB_CS_DAY, 0
  },
  { "DAY-OF-WEEK",		0, 0, DAY_OF_WEEK,		/* 2002 */
						0, 0
  },
  { "DE",				0, 0, DE,				/* 2002 */
						0, 0
  },
  { "DEBUGGING",		0, 0, DEBUGGING,		/* 2002 */
						0, 0
  },
  { "DECIMAL-POINT",	0, 0, DECIMAL_POINT,	/* 2002 */
						0, 0
  },
  { "DECLARATIVES",		0, 0, DECLARATIVES,		/* 2002 */
						0, 0
  },
  { "DEFAULT",			0, 0, DEFAULT,			/* 2002 */
						0, 0
  },
  { "DELETE",			1, 0, DELETE,			/* 2002 */
						0, 0
  },
  { "DELIMITED",		0, 0, DELIMITED,		/* 2002 */
						0, 0
  },
  { "DELIMITER",		0, 0, DELIMITER,		/* 2002 */
						0, 0
  },
  { "DEPENDING",		0, 0, DEPENDING,		/* 2002 */
						0, 0
  },
  { "DESCENDING",		0, 0, DESCENDING,		/* 2002 */
						0, 0
  },
  { "DESTINATION",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "DETAIL",			0, 0, DETAIL,			/* 2002 */
						0, 0
  },
  { "DISABLE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "DISC",				0, 1, DISC,				/* Extension */
						0, CB_CS_ASSIGN
  },
  { "DISK",				0, 1, DISK,				/* Extension */
						0, CB_CS_ASSIGN
  },
  { "DISPLAY",			1, 0, DISPLAY,			/* 2002 */
						0, 0
  },
  { "DIVIDE",			1, 0, DIVIDE,			/* 2002 */
						0, 0
  },
  { "DIVISION",			0, 0, DIVISION,			/* 2002 */
						0, 0
  },
  { "DOWN",				0, 0, DOWN,				/* 2002 */
						0, 0
  },
  { "DUPLICATES",		0, 0, DUPLICATES,		/* 2002 */
						0, 0
  },
  { "DYNAMIC",			0, 0, DYNAMIC,			/* 2002 */
						0, 0
  },
  { "EBCDIC",			0, 1, EBCDIC,			/* Extension */
						0, CB_CS_ALPHABET
  },
  { "EC",				0, 0, EC,				/* 2002 */
						0, 0
  },
  { "EGI",				0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "ELSE",				0, 0, ELSE,				/* 2002 */
						0, 0
  },
  { "EMI",				0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "EMPTY-CHECK",		0, 0, REQUIRED,			/* Extension */
						0, 0
  },
  { "ENABLE",			0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "END",				0, 0, END,				/* 2002 */
						0, 0
  },
  { "END-ACCEPT",		0, 0, END_ACCEPT,		/* 2002 */
						0, 0
  },
  { "END-ADD",			0, 0, END_ADD,			/* 2002 */
						0, 0
  },
  { "END-CALL",			0, 0, END_CALL,			/* 2002 */
						0, 0
  },
  { "END-CHAIN",		0, 0, -1,				/* Extension */
						0, 0
  },
  { "END-COMPUTE",		0, 0, END_COMPUTE,		/* 2002 */
						0, 0
  },
  { "END-DELETE",		0, 0, END_DELETE,		/* 2002 */
						0, 0
  },
  { "END-DISPLAY",		0, 0, END_DISPLAY,		/* 2002 */
						0, 0
  },
  { "END-DIVIDE",		0, 0, END_DIVIDE,		/* 2002 */
						0, 0
  },
  { "END-EVALUATE",		0, 0, END_EVALUATE,		/* 2002 */
						0, 0
  },
  { "END-IF",			0, 0, END_IF,			/* 2002 */
						0, 0
  },
  { "END-MULTIPLY",		0, 0, END_MULTIPLY,		/* 2002 */
						0, 0
  },
  { "END-OF-PAGE",		0, 0, EOP,				/* 2002 */
						0, 0
  },
  { "END-PERFORM",		0, 0, END_PERFORM,		/* 2002 */
						0, 0
  },
  { "END-READ",			0, 0, END_READ,			/* 2002 */
						0, 0
  },
  { "END-RECEIVE",		0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "END-RETURN",		0, 0, END_RETURN,		/* 2002 */
						0, 0
  },
  { "END-REWRITE",		0, 0, END_REWRITE,		/* 2002 */
						0, 0
  },
  { "END-SEARCH",		0, 0, END_SEARCH,		/* 2002 */
						0, 0
  },
  { "END-START",		0, 0, END_START,		/* 2002 */
						0, 0
  },
  { "END-STRING",		0, 0, END_STRING,		/* 2002 */
						0, 0
  },
  { "END-SUBTRACT",		0, 0, END_SUBTRACT,		/* 2002 */
						0, 0
  },
  { "END-UNSTRING",		0, 0, END_UNSTRING,		/* 2002 */
						0, 0
  },
  { "END-WRITE",		0, 0, END_WRITE,		/* 2002 */
						0, 0
  },
  { "ENTRY",			0, 0, ENTRY,			/* Extension */
						0, 0
  },
  { "ENTRY-CONVENTION",	0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "ENVIRONMENT",		0, 0, ENVIRONMENT,		/* 2002 */
						0, 0
  },
  { "ENVIRONMENT-NAME",	0, 0, ENVIRONMENT_NAME,	/* Extension */
						0, 0
  },
  { "ENVIRONMENT-VALUE", 0, 0, ENVIRONMENT_VALUE, /* Extension */
						0, 0
  },
  { "EO",				0, 0, -1,				/* 2002 */
						0, 0
  },
  { "EOL",				0, 1, EOL,				/* 2002(C/S) */
						0, CB_CS_ERASE
  },
  { "EOP",				0, 0, EOP,				/* 2002 */
						0, 0
  },
  { "EOS",				0, 1, EOS,				/* 2002(C/S) */
						0, CB_CS_ERASE
  },
  { "EQUAL",			0, 0, EQUAL,			/* 2002 */
						0, 0
  },
  { "EQUALS",			0, 0, EQUAL,			/* Extension */
						0, 0
  },
  { "ERASE",			0, 0, ERASE,			/* 2002(C/S) */
						CB_CS_ERASE, 0
  },
  { "ERROR",			0, 0, ERROR,			/* 2002 */
						0, 0
  },
  { "ESCAPE",			0, 0, ESCAPE,			/* Extension */
						0, 0
  },
  { "ESI",				0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "EVALUATE",			1, 0, EVALUATE,			/* 2002 */
						0, 0
  },
  { "EXCEPTION",		0, 0, EXCEPTION,		/* 2002 */
						0, 0
  },
  { "EXCEPTION-OBJECT",	0, 0, -1,				/* 2002 */
						0, 0
  },
  { "EXCLUSIVE",		0, 0, EXCLUSIVE,		/* Extension */
						0, 0
  },
  { "EXIT",				0, 0, EXIT,				/* 2002 */
				CB_CS_EXIT, 0
  },
  { "EXPANDS",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "EXTEND",			0, 0, EXTEND,			/* 2002 */
						0, 0
  },
  { "EXTERNAL",			0, 0, EXTERNAL,			/* 2002 */
						0, 0
  },
  { "FACTORY",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "FALSE",			0, 0, TOK_FALSE,		/* 2002 */
						0, 0
  },
  { "FD",				0, 0, FD,				/* 2002 */
						0, 0
  },
  { "FILE",				0, 0, TOK_FILE,			/* 2002 */
						0, 0
  },
  { "FILE-CONTROL",		0, 0, FILE_CONTROL,		/* 2002 */
						0, 0
  },
  { "FILE-ID",			0, 0, FILE_ID,			/* Extension */
						0, 0
  },
  { "FILLER",			0, 0, FILLER,			/* 2002 */
						0, 0
  },
  { "FINAL",			0, 0, FINAL,			/* 2002 */
						0, 0
  },
  { "FIRST",			0, 0, FIRST,			/* 2002 */
						0, 0
  },
  { "FLOAT-BINARY-128",	0, 0, -1,				/* 2011 */
						0, 0
  },
  { "FLOAT-BINARY-32",	0, 0, -1,				/* 2011 */
						0, 0
  },
  { "FLOAT-BINARY-64",	0, 0, -1,				/* 2011 */
						0, 0
  },
  { "FLOAT-DECIMAL-16",	0, 0, FLOAT_DECIMAL_16,	/* 2008 */
						0, 0
  },
  { "FLOAT-DECIMAL-34",	0, 0, FLOAT_DECIMAL_34,	/* 2008 */
						0, 0
  },
#if	0	/* RXWRXW - FP Decimal */
  { "FLOAT-DECIMAL-7",	0, 0, -1,				/* Extension */
						0, 0
  },
#endif
  { "FLOAT-EXTENDED",	0, 0, -1,				/* 2002 */
						0, 0
  },
  { "FLOAT-INFINITY",	0, 0, -1,				/* 2011 */
						0, 0
  },
  { "FLOAT-LONG",		0, 0, FLOAT_LONG,		/* 2002 */
						0, 0
  },
  { "FLOAT-NOT-A-NUMBER", 0, 1, -1,				/* 2011 */
						0, 0
  },
  { "FLOAT-SHORT",		0, 0, FLOAT_SHORT,		/* 2002 */
						0, 0
  },
  { "FOOTING",			0, 0, FOOTING,			/* 2002 */
						0, 0
  },
  { "FOR",				0, 0, FOR,				/* 2002 */
						0, 0
  },
  { "FOREGROUND-COLOR",	0, 0, FOREGROUND_COLOR,	/* 2002(C/S) */
						0, 0
  },
  { "FOREGROUND-COLOUR", 0, 0, FOREGROUND_COLOR, /* Extension */
						0, 0
  },
  { "FOREVER",			0, 0, FOREVER,			/* 2002(C/S) */
						0, 0
  },
  { "FORMAT",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "FREE",				0, 0, FREE,				/* 2002 */
						0, 0
  },
  { "FROM",				0, 0, FROM,				/* 2002 */
						CB_CS_FROM, CB_CS_ACCEPT
  },
  { "FULL",				0, 0, FULL,				/* 2002(C/S) */
						0, 0
  },
  { "FUNCTION",			0, 0, FUNCTION,			/* 2002 */
						0, 0
  },
  { "FUNCTION-ID",		0, 0, FUNCTION_ID,		/* 2002 */
						0, 0
  },
  { "FUNCTION-POINTER",	0, 0, -1,				/* 2008 */
						0, 0
  },
  { "GENERATE",			0, 0, GENERATE,			/* 2002 */
						0, 0
  },
  { "GET",				0, 0, -1,				/* 2002 */
						0, 0
  },
  { "GIVING",			0, 0, GIVING,			/* 2002 */
						0, 0
  },
  { "GLOBAL",			0, 0, GLOBAL,			/* 2002 */
						0, 0
  },
  { "GO",				0, 0, GO,				/* 2002 */
						0, 0
  },
  { "GOBACK",			0, 0, GOBACK,			/* 2002 */
						0, 0
  },
  { "GREATER",			0, 0, GREATER,			/* 2002 */
						0, 0
  },
  { "GROUP",			0, 0, GROUP,			/* 2002 */
						0, 0
  },
  { "GROUP-USAGE",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "HEADING",			0, 0, HEADING,			/* 2002 */
						0, 0
  },
  { "HIGH-VALUE",		0, 0, HIGH_VALUE,		/* 2002 */
						0, 0
  },
  { "HIGH-VALUES",		0, 0, HIGH_VALUE,		/* 2002 */
						0, 0
  },
  { "HIGHLIGHT",		0, 0, HIGHLIGHT,		/* 2002(C/S) */
						0, 0
  },
  { "I-O",				0, 0, I_O,				/* 2002 */
						0, 0
  },
  { "I-O-CONTROL",		0, 0, I_O_CONTROL,		/* 2002 */
						0, 0
  },
  { "ID",				0, 0, ID,				/* Extension */
						0, 0
  },
  { "IDENTIFICATION",	0, 0, IDENTIFICATION,	/* 2002 */
						0, 0
  },
  { "IF",				1, 0, IF,				/* 2002 */
						0, 0
  },
  { "IGNORE",			0, 0, IGNORE,			/* Extension */
						0, 0
  },
  { "IGNORING",			0, 0, IGNORING,			/* 2002(C/S) */
						0, 0
  },
  { "IMPLEMENTS",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "IN",				0, 0, IN,				/* 2002 */
						0, 0
  },
  { "INDEX",			0, 0, INDEX,			/* 2002 */
						0, 0
  },
  { "INDEXED",			0, 0, INDEXED,			/* 2002 */
						0, 0
  },
  { "INDICATE",			0, 0, INDICATE,			/* 2002 */
						0, 0
  },
  { "INDIRECT",			0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
  { "INHERITS",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "INITIAL",			0, 0, TOK_INITIAL,		/* 2002 */
						0, 0
  },
  { "INITIALISE",		0, 0, INITIALIZE,		/* Extension */
						0, 0
  },
  { "INITIALISED",		0, 0, INITIALIZED,		/* Extension */
						0, 0
  },
  { "INITIALIZE",		0, 0, INITIALIZE,		/* 2002 */
						0, 0
  },
  { "INITIALIZED",		0, 0, INITIALIZED,		/* 2002 */
						0, 0
  },
  { "INITIATE",			0, 0, INITIATE,			/* 2002 */
						0, 0
  },
  { "INPUT",			0, 0, INPUT,			/* 2002 */
						0, 0
  },
  { "INPUT-OUTPUT",		0, 0, INPUT_OUTPUT,		/* 2002 */
						0, 0
  },
  { "INSPECT",			0, 0, INSPECT,			/* 2002 */
						0, 0
  },
  { "INTERFACE",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "INTERFACE-ID",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "INTERMEDIATE",		0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
  { "INTO",				0, 0, INTO,				/* 2002 */
						0, 0
  },
  { "INTRINSIC",		0, 1, INTRINSIC,		/* 2002(C/S) */
						0, 0
  },
  { "INVALID",			0, 0, INVALID,			/* 2002 */
						0, 0
  },
  { "INVOKE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "IS",				0, 0, IS,				/* 2002 */
						0, 0
  },
  { "JUST",				0, 0, JUSTIFIED,		/* 2002 */
						0, 0
  },
  { "JUSTIFIED",		0, 0, JUSTIFIED,		/* 2002 */
						0, 0
  },
  { "KEPT",				0, 0, KEPT,				/* Extension */
						0, 0
  },
  { "KEY",				0, 0, KEY,				/* 2002 */
						0, 0
  },
  { "KEYBOARD",			0, 1, KEYBOARD,			/* Extension */
						0, CB_CS_ASSIGN
  },
  { "LABEL",			0, 0, LABEL,			/* 85 */
						0, 0
  },
  { "LAST",				0, 0, LAST,				/* 2002 */
						0, 0
  },
  { "LC_ALL",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LC_COLLATE",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LC_CTYPE",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LC_MESSAGES",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LC_MONETARY",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LC_NUMERIC",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LC_TIME",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "LEADING",			0, 0, LEADING,			/* 2002 */
						0, 0
  },
  { "LEFT",				0, 0, LEFT,				/* 2002 */
						0, 0
  },
  { "LEFT-JUSTIFY",		0, 0, -1,				/* Extension */
						0, 0
  },
  { "LEFTLINE",			0, 0, LEFTLINE,			/* Extension */
						0, 0
  },
  { "LENGTH",			0, 0, LENGTH,			/* 2002 */
						0, 0
  },
  { "LENGTH-CHECK",		0, 0, FULL,				/* Extension */
						0, 0
  },
  { "LESS",				0, 0, LESS,				/* 2002 */
						0, 0
  },
  { "LIMIT",			0, 0, LIMIT,			/* 2002 */
						0, 0
  },
  { "LIMITS",			0, 0, LIMITS,			/* 2002 */
						0, 0
  },
  { "LINAGE",			0, 0, LINAGE,			/* 2002 */
						0, 0
  },
  { "LINAGE-COUNTER",	0, 0, LINAGE_COUNTER,	/* 2002 */
						0, 0
  },
  { "LINE",				0, 0, LINE,				/* 2002 */
						0, 0
  },
  { "LINE-COUNTER",		0, 0, LINE_COUNTER,		/* 2002 */
						0, 0
  },
  { "LINES",			0, 0, LINES,			/* 2002 */
						0, 0
  },
  { "LINKAGE",			0, 0, LINKAGE,			/* 2002 */
						0, 0
  },
  { "LOCAL-STORAGE",	0, 0, LOCAL_STORAGE,	/* 2002 */
						0, 0
  },
  { "LOCALE",			0, 0, LOCALE,			/* 2002 */
						0, 0
  },
  { "LOCK",				0, 0, LOCK,				/* 2002 */
						0, 0
  },
  { "LOW-VALUE",		0, 0, LOW_VALUE,		/* 2002 */
						0, 0
  },
  { "LOW-VALUES",		0, 0, LOW_VALUE,		/* 2002 */
						0, 0
  },
  { "LOWER",			0, 1, LOWER,			/* Extension */
						0, CB_CS_WITH
  },
  { "LOWLIGHT",			0, 0, LOWLIGHT,			/* 2002(C/S) */
						0, 0
  },
  { "MANUAL",			0, 0, MANUAL,			/* 2002(C/S) */
						0, 0
  },
  { "MEMORY",			0, 0, MEMORY,			/* 85 */
						0, 0
  },
  { "MERGE",			0, 0, MERGE,			/* 2002 */
						0, 0
  },
  { "MESSAGE",			0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "METHOD",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "METHOD-ID",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "MINUS",			0, 0, MINUS,			/* 2002 */
						0, 0
  },
  { "MODE",				0, 0, MODE,				/* 2002 */
						0, 0
  },
  { "MOVE",				0, 0, MOVE,				/* 2002 */
						0, 0
  },
  { "MULTIPLE",			0, 0, MULTIPLE,			/* 2002(C/S) */
						0, 0
  },
  { "MULTIPLY",			1, 0, MULTIPLY,			/* 2002 */
						0, 0
  },
  { "NAME",				0, 1, NAME,				/* Extension */
						0, CB_CS_FROM
  },
  { "NATIONAL",			0, 0, NATIONAL,			/* 2002 */
						0, 0
  },
  { "NATIONAL-EDITED",	0, 0, NATIONAL_EDITED,	/* 2002 */
						0, 0
  },
  { "NATIVE",			0, 0, NATIVE,			/* 2002 */
						0, 0
  },
  { "NEAREST-AWAY-FROM-ZERO", 0, 1, NEAREST_AWAY_FROM_ZERO, /* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "NEAREST-EVEN",		0, 1, NEAREST_EVEN,		/* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "NEAREST-TOWARD-ZERO", 0, 1, NEAREST_TOWARD_ZERO, /* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "NEGATIVE",			0, 0, NEGATIVE,			/* 2002 */
						0, 0
  },
  { "NESTED",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "NEXT",				0, 0, NEXT,				/* 2002 */
						0, 0
  },
  { "NO",				0, 0, NO,				/* 2002 */
						0, 0
  },
  { "NO-ECHO",			0, 0, NO_ECHO,			/* Extension */
						0, 0
  },
  { "NONE",				0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "NORMAL",			0, 1, NORMAL,			/* 2002(C/S) */
						0, CB_CS_STOP
  },
  { "NOT",				0, 0, NOT,				/* 2002 */
						0, 0
  },
  { "NULL",				0, 0, TOK_NULL,			/* 2002 */
						0, 0
  },
  { "NULLS",			0, 0, TOK_NULL,			/* Extension */
						0, 0
  },
  { "NUMBER",			0, 0, NUMBER,			/* 2002 */
						0, 0
  },
  { "NUMBERS",			0, 0, NUMBERS,			/* 2002(C/S) */
						0, 0
  },
  { "NUMERIC",			0, 0, NUMERIC,			/* 2002 */
						0, 0
  },
  { "NUMERIC-EDITED",	0, 0, NUMERIC_EDITED,	/* 2002 */
						0, 0
  },
  { "OBJECT",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "OBJECT-COMPUTER",	0, 0, OBJECT_COMPUTER,	/* 2002 */
						0, 0
  },
  { "OBJECT-REFERENCE",	0, 0, -1,				/* 2002 */
						0, 0
  },
  { "OCCURS",			0, 0, OCCURS,			/* 2002 */
						0, 0
  },
  { "OF",				0, 0, OF,				/* 2002 */
						0, 0
  },
  { "OFF",				0, 0, OFF,				/* 2002 */
						0, 0
  },
  { "OMITTED",			0, 0, OMITTED,			/* 2002 */
						0, 0
  },
  { "ON",				0, 0, ON,				/* 2002 */
						0, 0
  },
  { "ONLY",				0, 0, ONLY,				/* 2002(C/S) */
						0, 0
  },
  { "OPEN",				0, 0, OPEN,				/* 2002 */
						0, 0
  },
  { "OPTIONAL",			0, 0, OPTIONAL,			/* 2002 */
						0, 0
  },
  { "OPTIONS",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "OR",				0, 0, OR,				/* 2002 */
						0, 0
  },
  { "ORDER",			0, 0, ORDER,			/* 2002 */
						0, 0
  },
  { "ORGANISATION",		0, 0, ORGANIZATION,		/* Extension */
						0, 0
  },
  { "ORGANIZATION",		0, 0, ORGANIZATION,		/* 2002 */
						0, 0
  },
  { "OTHER",			0, 0, OTHER,			/* 2002 */
						0, 0
  },
  { "OUTPUT",			0, 0, OUTPUT,			/* 2002 */
						0, 0
  },
  { "OVERFLOW",			0, 0, TOK_OVERFLOW,		/* 2002 */
						0, 0
  },
  { "OVERLINE",			0, 0, OVERLINE,			/* Extension */
						0, 0
  },
  { "OVERRIDE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "PACKED-DECIMAL",	0, 0, PACKED_DECIMAL,	/* 2002 */
						0, 0
  },
  { "PADDING",			0, 0, PADDING,			/* 2002 */
						0, 0
  },
  { "PAGE",				0, 0, PAGE,				/* 2002 */
						0, 0
  },
  { "PAGE-COUNTER",		0, 0, PAGE_COUNTER,		/* 2002 */
						0, 0
  },
  { "PARAGRAPH",		0, 1, PARAGRAPH,		/* 2002(C/S) */
						0, CB_CS_EXIT
  },
  { "PERFORM",			1, 0, PERFORM,			/* 2002 */
						0, 0
  },
  { "PF",				0, 0, PF,				/* 2002 */
						0, 0
  },
  { "PH",				0, 0, PH,				/* 2002 */
						0, 0
  },
  { "PIC",				0, 0, PICTURE,			/* 2002 */
						0, 0
  },
  { "PICTURE",			0, 0, PICTURE,			/* 2002 */
						0, 0
  },
  { "PLUS",				0, 0, PLUS,				/* 2002 */
						0, 0
  },
  { "POINTER",			0, 0, POINTER,			/* 2002 */
						0, 0
  },
  { "POSITION",			0, 0, POSITION,			/* 85 */
						0, 0
  },
  { "POSITIVE",			0, 0, POSITIVE,			/* 2002 */
						0, 0
  },
  { "PREFIXED",			0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
  { "PRESENT",			0, 0, PRESENT,			/* 2002 */
						0, 0
  },
  { "PREVIOUS",			0, 0, PREVIOUS,			/* 2002(C/S) */
						0, 0
  },
  { "PRINTER",			0, 1, PRINTER,			/* Extension */
						0, CB_CS_ASSIGN
  },
  { "PRINTING",			0, 0, PRINTING,			/* 2002 */
						0, 0
  },
  { "PROCEDURE",		0, 0, PROCEDURE,		/* 2002 */
						0, 0
  },
  { "PROCEDURE-POINTER", 0, 0, PROGRAM_POINTER,	/* Extension */
						0, 0
  },
  { "PROCEDURES",		0, 0, PROCEDURES,		/* Extension */
						0, 0
  },
  { "PROCEED",			0, 0, PROCEED,			/* 85 */
						0, 0
  },
  { "PROGRAM",			0, 0, PROGRAM,			/* 2002 */
						0, 0
  },
  { "PROGRAM-ID",		0, 0, PROGRAM_ID,		/* 2002 */
						0, 0
  },
  { "PROGRAM-POINTER",	0, 0, PROGRAM_POINTER,	/* 2002 */
						0, 0
  },
  { "PROHIBITED",		0, 1, PROHIBITED,		/* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "PROMPT",			0, 0, PROMPT,			/* Extension */
						0, 0
  },
  { "PROPERTY",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "PROTOTYPE",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "PURGE",			0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "QUEUE",			0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "QUOTE",			0, 0, QUOTE,			/* 2002 */
						0, 0
  },
  { "QUOTES",			0, 0, QUOTE,			/* 2002 */
						0, 0
  },
  { "RAISE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "RAISING",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "RANDOM",			0, 0, RANDOM,			/* 2002 */
						0, 0
  },
  { "RD",				0, 0, RD,				/* 2002 */
						0, 0
  },
  { "READ",				1, 0, READ,				/* 2002 */
						0, 0
  },
  { "RECEIVE",			1, 0, 0,				/* 85 CM */
						0, 0
  },
  { "RECORD",			0, 0, RECORD,			/* 2002 */
						0, 0
  },
  { "RECORDING",		0, 0, RECORDING,		/* Extension */
						0, 0
  },
  { "RECORDS",			0, 0, RECORDS,			/* 2002 */
						0, 0
  },
  { "RECURSIVE",		0, 1, RECURSIVE,		/* 2002(C/S) */
						0, CB_CS_PROGRAM_ID
  },
  { "REDEFINES",		0, 0, REDEFINES,		/* 2002 */
						0, 0
  },
  { "REEL",				0, 0, REEL,				/* 2002 */
						0, 0
  },
  { "REFERENCE",		0, 0, REFERENCE,		/* 2002 */
						0, 0
  },
  { "REFERENCES",		0, 0, REFERENCES,		/* Obsolete */
						0, 0
  },
  { "RELATION",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "RELATIVE",			0, 0, RELATIVE,			/* 2002 */
						0, 0
  },
  { "RELEASE",			0, 0, RELEASE,			/* 2002 */
						0, 0
  },
  { "REMAINDER",		0, 0, REMAINDER,		/* 2002 */
						0, 0
  },
  { "REMOVAL",			0, 0, REMOVAL,			/* 2002 */
						0, 0
  },
  { "RENAMES",			0, 0, RENAMES,			/* 2002 */
						0, 0
  },
  { "REPLACE",			0, 0, REPLACE,			/* 2002 */
						0, 0
  },
  { "REPLACING",		0, 0, REPLACING,		/* 2002 */
						0, 0
  },
  { "REPORT",			0, 0, REPORT,			/* 2002 */
						0, 0
  },
  { "REPORTING",		0, 0, REPORTING,		/* 2002 */
						0, 0
  },
  { "REPORTS",			0, 0, REPORTS,			/* 2002 */
						0, 0
  },
  { "REPOSITORY",		0, 0, REPOSITORY,		/* 2002 */
						0, 0
  },
  { "REQUIRED",			0, 0, REQUIRED,			/* 2002(C/S) */
						0, 0
  },
  { "RESERVE",			0, 0, RESERVE,			/* 2002 */
						0, 0
  },
  { "RESET",			0, 0, RESET,			/* 2002 */
						0, 0
  },
  { "RESUME",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "RETRY",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "RETURN",			1, 0, RETURN,			/* 2002 */
						0, 0
  },
  { "RETURNING",		0, 0, RETURNING,		/* 2002 */
						0, 0
  },
  { "REVERSE-VIDEO",	0, 0, REVERSE_VIDEO,	/* 2002(C/S) */
						0, 0
  },
  { "REVERSED",			0, 0, REVERSED,			/* Obsolete */
						0, 0
  },
  { "REWIND",			0, 0, REWIND,			/* 2002 */
						0, 0
  },
  { "REWRITE",			1, 0, REWRITE,			/* 2002 */
						0, 0
  },
  { "RF",				0, 0, RF,				/* 2002 */
						0, 0
  },
  { "RH",				0, 0, RH,				/* 2002 */
						0, 0
  },
  { "RIGHT",			0, 0, RIGHT,			/* 2002 */
						0, 0
  },
  { "RIGHT-JUSTIFY",	0, 0, -1,				/* Extension */
						0, 0
  },
  { "ROLLBACK",			0, 0, ROLLBACK,			/* Extension */
						0, 0
  },
  { "ROUNDED",			0, 0, ROUNDED,			/* 2002 */
						CB_CS_ROUNDED, 0
  },
  { "ROUNDING",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "RUN",				0, 0, RUN,				/* 2002 */
						0, 0
  },
  { "SAME",				0, 0, SAME,				/* 2002 */
						0, 0
  },
  { "SCREEN",			0, 0, SCREEN,			/* 2002 */
						0, 0
  },
  { "SCROLL",			0, 1, SCROLL,			/* Extension */
						0, CB_CS_WITH
  },
  { "SD",				0, 0, SD,				/* 2002 */
						0, 0
  },
  { "SEARCH",			1, 0, SEARCH,			/* 2002 */
						0, 0
  },
  { "SECONDS",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "SECTION",			0, 0, SECTION,			/* 2002 */
						0, 0
  },
  { "SECURE",			0, 0, SECURE,			/* 2002(C/S) */
						0, 0
  },
  { "SEGMENT",			0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "SEGMENT-LIMIT",	0, 0, SEGMENT_LIMIT,	/* 85 */
						0, 0
  },
  { "SELECT",			0, 0, SELECT,			/* 2002 */
						0, 0
  },
  { "SELF",				0, 0, -1,				/* 2002 */
						0, 0
  },
  { "SEND",				0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "SENTENCE",			0, 0, SENTENCE,			/* 2002 */
						0, 0
  },
  { "SEPARATE",			0, 0, SEPARATE,			/* 2002 */
						0, 0
  },
  { "SEQUENCE",			0, 0, SEQUENCE,			/* 2002 */
						0, 0
  },
  { "SEQUENTIAL",		0, 0, SEQUENTIAL,		/* 2002 */
						0, 0
  },
  { "SET",				0, 0, SET,				/* 2002 */
						0, 0
  },
  { "SHARING",			0, 0, SHARING,			/* 2002 */
						0, 0
  },
  { "SIGN",				0, 0, SIGN,				/* 2002 */
						0, 0
  },
  { "SIGNED",			0, 0, SIGNED,			/* 2002(C/S) */
						0, 0
  },
  { "SIGNED-INT",		0, 0, SIGNED_INT,		/* Extension */
						0, 0
  },
  { "SIGNED-LONG",		0, 0, SIGNED_LONG,		/* Extension */
						0, 0
  },
  { "SIGNED-SHORT",		0, 0, SIGNED_SHORT,		/* Extension */
						0, 0
  },
  { "SIZE",				0, 0, SIZE,				/* 2002 */
						0, 0
  },
  { "SORT",				0, 0, SORT,				/* 2002 */
						0, 0
  },
  { "SORT-MERGE",		0, 0, SORT_MERGE,		/* 2002 */
						0, 0
  },
  { "SOURCE",			0, 0, SOURCE,			/* 2002 */
						0, 0
  },
  { "SOURCE-COMPUTER",	0, 0, SOURCE_COMPUTER,	/* 2002 */
						0, 0
  },
  { "SOURCES",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "SPACE",			0, 0, SPACE,			/* 2002 */
						0, 0
  },
  { "SPACE-FILL",		0, 0, -1,				/* Extension */
						0, 0
  },
  { "SPACES",			0, 0, SPACE,			/* 2002 */
						0, 0
  },
  { "SPECIAL-NAMES",	0, 0, SPECIAL_NAMES,	/* 2002 */
						0, 0
  },
  { "STANDARD",			0, 0, STANDARD,			/* 2002 */
						0, 0
  },
	/* Note EBCDIC! */
#ifdef	COB_EBCDIC_MACHINE
  { "STANDARD-BINARY",	0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
  { "STANDARD-DECIMAL",	0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
#endif
  { "STANDARD-1",		0, 0, STANDARD_1,		/* 2002 */
						0, 0
  },
  { "STANDARD-2",		0, 0, STANDARD_2,		/* 2002 */
						0, 0
  },
	/* Note EBCDIC! */
#ifndef	COB_EBCDIC_MACHINE
  { "STANDARD-BINARY",	0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
  { "STANDARD-DECIMAL",	0, 1, -1,				/* 2008(C/S) */
						0, 0
  },
#endif
  { "START",			1, 0, START,			/* 2002 */
						0, 0
  },
  { "STATEMENT",		0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "STATIC",			0, 1, STATIC,			/* Extension */
						0, CB_CS_CALL
  },
  { "STATUS",			0, 0, STATUS,			/* 2002 */
						0, 0
  },
  { "STDCALL",			0, 1, STDCALL,			/* Extension */
						0, CB_CS_CALL
  },
  { "STEP",				0, 0, STEP,				/* 2002(C/S) */
						0, 0
  },
  { "STOP",				0, 0, STOP,				/* 2002 */
						CB_CS_STOP, 0
  },
  { "STRING",			1, 0, STRING,			/* 2002 */
						0, 0
  },
  { "STRONG",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "SUB-QUEUE-1",		0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "SUB-QUEUE-2",		0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "SUB-QUEUE-3",		0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "SUBTRACT",			1, 0, SUBTRACT,			/* 2002 */
						0, 0
  },
  { "SUM",				0, 0, SUM,				/* 2002 */
						0, 0
  },
  { "SUPER",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "SUPPRESS",			0, 0, SUPPRESS,			/* 2002 */
						0, 0
  },
  { "SYMBOL",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "SYMBOLIC",			0, 0, SYMBOLIC,			/* 2002 */
						0, 0
  },
  { "SYNC",				0, 0, SYNCHRONIZED,		/* 2002 */
						0, 0
  },
  { "SYNCHRONISED",		0, 0, SYNCHRONIZED,		/* Extension */
						0, 0
  },
  { "SYNCHRONIZED",		0, 0, SYNCHRONIZED,		/* 2002 */
						0, 0
  },
  { "SYSTEM-DEFAULT",	0, 0, SYSTEM_DEFAULT,	/* 2002 */
						0, 0
  },
  { "TABLE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "TALLYING",			0, 0, TALLYING,			/* 2002 */
						0, 0
  },
  { "TAPE",				0, 1, TAPE,				/* 85 */
						0, CB_CS_ASSIGN
  },
  { "TERMINAL",			0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "TERMINATE",		0, 0, TERMINATE,		/* 2002 */
						0, 0
  },
  { "TEST",				0, 0, TEST,				/* 2002 */
						0, 0
  },
  { "TEXT",				0, 0, 0,				/* 85 CM */
						0, 0
  },
  { "THAN",				0, 0, THAN,				/* 2002 */
						0, 0
  },
  { "THEN",				0, 0, THEN,				/* 2002 */
						0, 0
  },
  { "THROUGH",			0, 0, THRU,				/* 2002 */
						0, 0
  },
  { "THRU",				0, 0, THRU,				/* 2002 */
						0, 0
  },
  { "TIME",				0, 0, TIME,				/* 2002 */
						0, 0
  },
  { "TIME-OUT",			0, 1, TIMEOUT,			/* Ext(C/S) */
						0, CB_CS_WITH
  },
  { "TIMEOUT",			0, 1, TIMEOUT,			/* Ext(C/S) */
						0, CB_CS_WITH
  },
  { "TIMES",			0, 0, TIMES,			/* 2002 */
						0, 0
  },
  { "TO",				0, 0, TO,				/* 2002 */
						0, 0
  },
  { "TOP",				0, 0, TOP,				/* 2002 */
						0, 0
  },
  { "TOWARD-GREATER",	0, 1, TOWARD_GREATER,	/* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "TOWARD-LESSER",		0, 1, TOWARD_LESSER, /* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "TRAILING",			0, 0, TRAILING,			/* 2002 */
						0, 0
  },
  { "TRAILING-SIGN",	0, 0, -1,				/* Extension */
						0, 0
  },
  { "TRANSFORM",		0, 0, TRANSFORM,		/* OSVS */
						0, 0
  },
  { "TRUE",				0, 0, TOK_TRUE,			/* 2002 */
						0, 0
  },
  { "TRUNCATION",		0, 1, TRUNCATION,		/* 2008(C/S) */
						0, CB_CS_ROUNDED
  },
  { "TYPE",				0, 0, TYPE,				/* 2002 */
						0, 0
  },
  { "TYPEDEF",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "UCS-4",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "UNDERLINE",		0, 0, UNDERLINE,		/* 2002(C/S) */
						0, 0
  },
  { "UNIT",				0, 0, UNIT,				/* 2002 */
						0, 0
  },
  { "UNIVERSAL",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "UNLOCK",			0, 0, UNLOCK,			/* 2002 */
						0, 0
  },
  { "UNSIGNED",			0, 0, UNSIGNED,			/* 2002(C/S) */
						0, 0
  },
  { "UNSIGNED-INT",		0, 0, UNSIGNED_INT,		/* Extension */
						0, 0
  },
  { "UNSIGNED-LONG",	0, 0, UNSIGNED_LONG,	/* Extension */
						0, 0
  },
  { "UNSIGNED-SHORT",	0, 0, UNSIGNED_SHORT,	/* Extension */
						0, 0
  },
  { "UNSTRING",			1, 0, UNSTRING,			/* 2002 */
						0, 0
  },
  { "UNTIL",			0, 0, UNTIL,			/* 2002 */
						0, 0
  },
  { "UP",				0, 0, UP,				/* 2002 */
						0, 0
  },
  { "UPDATE",			0, 0, UPDATE,			/* Extension */
						0, 0
  },
  { "UPON",				0, 0, UPON,				/* 2002 */
						0, 0
  },
  { "UPPER",			0, 1, UPPER,			/* Extension */
						0, CB_CS_WITH
  },
  { "USAGE",			0, 0, USAGE,			/* 2002 */
						0, 0
  },
  { "USE",				0, 0, USE,				/* 2002 */
						0, 0
  },
  { "USER",				0, 1, USER,				/* Extension */
						0, CB_CS_FROM
  },
  { "USER-DEFAULT",		0, 0, USER_DEFAULT,		/* 2002 */
						0, 0
  },
  { "USING",			0, 0, USING,			/* 2002 */
						0, 0
  },
  { "UTF-16",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "UTF-8",			0, 1, -1,				/* 2002(C/S) */
						0, 0
  },
  { "VAL-STATUS",		0, 0, -1,				/* 2002 */
						0, 0
  },
  { "VALID",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "VALIDATE",			0, 0, -1,				/* 2002 */
						0, 0
  },
  { "VALIDATE-STATUS",	0, 0, -1,				/* 2002 */
						0, 0
  },
  { "VALUE",			0, 0, VALUE,			/* 2002 */
						0, 0
  },
  { "VALUES",			0, 0, VALUE,			/* 2002 */
						0, 0
  },
  { "VARYING",			0, 0, VARYING,			/* 2002 */
						0, 0
  },
  { "WAIT",				0, 0, WAIT,				/* Extension */
						0, 0
  },
  { "WHEN",				0, 0, WHEN,				/* 2002 */
						0, 0
  },
  { "WITH",				0, 0, WITH,				/* 2002 */
						CB_CS_WITH, CB_CS_ACCEPT | CB_CS_DISPLAY
  },
  { "WORDS",			0, 0, WORDS,			/* 85 */
						0, 0
  },
  { "WORKING-STORAGE",	0, 0, WORKING_STORAGE,	/* 2002 */
						0, 0
  },
  { "WRITE",			1, 0, WRITE,			/* 2002 */
						0, 0
  },
  { "YYYYDDD",			0, 1, YYYYDDD,			/* 2002(C/S) */
						0, CB_CS_DAY
  },
  { "YYYYMMDD",			0, 1, YYYYMMDD,			/* 2002(C/S) */
						0, CB_CS_DATE
  },
  { "ZERO",				0, 0, ZERO,				/* 2002 */
						0, 0
  },
  { "ZERO-FILL",		0, 0, -1,				/* Extension */
						0, 0
  },
  { "ZEROES",			0, 0, ZERO,				/* 2002 */
						0, 0
  },
  { "ZEROS",			0, 0, ZERO,				/* 2002 */
						0, 0
  }
};

#define NUM_RESERVED_WORDS	sizeof(reserved_words) / sizeof(cobc_reserved)

/* Intrinsic Function List */
/* Must be ordered on name for binary search */

/*		Name,		Routine,				*/
/*		Arguments,	Implemented,	Token,			*/
/*		Category,	Can refmod,	Minimum number of args	*/
/*		Parser token						*/

static const cb_intrinsic_table function_list[] = {
  { "ABS",				"cob_intr_abs",
						1, 1, CB_INTR_ABS,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "ACOS",				"cob_intr_acos",
						1, 1, CB_INTR_ACOS,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "ANNUITY",			"cob_intr_annuity",
						2, 1, CB_INTR_ANNUITY,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "ASIN",				"cob_intr_asin",
						1, 1, CB_INTR_ASIN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "ATAN",				"cob_intr_atan",
						1, 1, CB_INTR_ATAN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "BOOLEAN-OF-INTEGER",	"cob_intr_boolean_of_integer",
						2, 0, CB_INTR_BOOLEAN_OF_INTEGER,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "BYTE-LENGTH",		"cob_intr_byte_length",
						1, 1, CB_INTR_BYTE_LENGTH,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "CHAR",				"cob_intr_char",
						1, 1, CB_INTR_CHAR,
						CB_CATEGORY_ALPHANUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "CHAR-NATIONAL",	"cob_intr_char_national",
						1, 0, CB_INTR_CHAR_NATIONAL,
						CB_CATEGORY_ALPHANUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "COMBINED-DATETIME",	"cob_intr_combined_datetime",
						2, 1, CB_INTR_COMBINED_DATETIME,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "CONCATENATE",		"cob_intr_concatenate",
						-1, 1, CB_INTR_CONCATENATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						CONCATENATE_FUNC
  },
  { "COS",				"cob_intr_cos",
						1, 1, CB_INTR_COS,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "CURRENCY-SYMBOL",	"cob_intr_currency_symbol",
						0, 1, CB_INTR_CURRENCY_SYMBOL,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "CURRENT-DATE",		"cob_intr_current_date",
						0, 1, CB_INTR_CURRENT_DATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 0,
						CURRENT_DATE_FUNC
  },
  { "DATE-OF-INTEGER",	"cob_intr_date_of_integer",
						1, 1, CB_INTR_DATE_OF_INTEGER,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "DATE-TO-YYYYMMDD",	"cob_intr_date_to_yyyymmdd",
						-1, 1, CB_INTR_DATE_TO_YYYYMMDD,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "DAY-OF-INTEGER",	"cob_intr_day_of_integer",
						1, 1, CB_INTR_DAY_OF_INTEGER,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "DAY-TO-YYYYDDD",	"cob_intr_day_to_yyyyddd",
						-1, 1, CB_INTR_DAY_TO_YYYYDDD,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "DISPLAY-OF",		"cob_intr_display_of",
						-1, 0, CB_INTR_DISPLAY_OF,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						DISPLAY_OF_FUNC
  },
  { "E",				"cob_intr_e",
						0, 1, CB_INTR_E,
						CB_CATEGORY_NUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXCEPTION-FILE",	"cob_intr_exception_file",
						0, 1, CB_INTR_EXCEPTION_FILE,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXCEPTION-FILE-N",	"cob_intr_exception_file_n",
						0, 0, CB_INTR_EXCEPTION_FILE_N,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXCEPTION-LOCATION",	"cob_intr_exception_location",
						0, 1, CB_INTR_EXCEPTION_LOCATION,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXCEPTION-LOCATION-N",	"cob_intr_exception_location_n",
						0, 0, CB_INTR_EXCEPTION_LOCATION_N,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXCEPTION-STATEMENT",	"cob_intr_exception_statement",
						0, 1, CB_INTR_EXCEPTION_STATEMENT,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXCEPTION-STATUS",	"cob_intr_exception_status",
						0, 1, CB_INTR_EXCEPTION_STATUS,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "EXP",				"cob_intr_exp",
						1, 1, CB_INTR_EXP,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "EXP10",			"cob_intr_exp10",
						1, 1, CB_INTR_EXP10,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "FACTORIAL",		"cob_intr_factorial",
						1, 1, CB_INTR_FACTORIAL,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "FORMATTED-CURRENT-DATE",	"cob_intr_formatted_current_date",
						1, 0, CB_INTR_FORMATTED_CURRENT_DATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						FORMATTED_CURRENT_FUNC
  },
  { "FORMATTED-DATE",	"cob_intr_formatted_date",
						2, 0, CB_INTR_FORMATTED_DATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 2,
						FORMATTED_DATE_FUNC
  },
  { "FORMATTED-DATETIME",	"cob_intr_formatted_datetime",
						-1, 0, CB_INTR_FORMATTED_DATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 3,
						FORMATTED_DATETIME_FUNC
  },
  { "FORMATTED-TIME",	"cob_intr_formatted_time",
						-1, 0, CB_INTR_FORMATTED_DATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 2,
						FORMATTED_TIME_FUNC
  },
  { "FRACTION-PART",	"cob_intr_fraction_part",
						1, 1, CB_INTR_FRACTION_PART,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "HIGHEST-ALGEBRAIC",	"cob_intr_highest_algebraic",
						1, 1, CB_INTR_HIGHEST_ALGEBRAIC,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "INTEGER",			"cob_intr_integer",
						1, 1, CB_INTR_INTEGER,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "INTEGER-OF-BOOLEAN",	"cob_intr_integer_of_boolean",
						1, 0, CB_INTR_INTEGER_OF_BOOLEAN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "INTEGER-OF-DATE",	"cob_intr_integer_of_date",
						1, 1, CB_INTR_INTEGER_OF_DATE,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "INTEGER-OF-DAY",	"cob_intr_integer_of_day",
						1, 1, CB_INTR_INTEGER_OF_DAY,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "INTEGER-OF-FORMATTED-DATE",	"cob_intr_integer_of_formatted_date",
						2, 0, CB_INTR_INTEGER_OF_FORMATTED_DATE,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "INTEGER-PART",		"cob_intr_integer_part",
						1, 1, CB_INTR_INTEGER_PART,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "LENGTH",			"cob_intr_length",
						1, 1, CB_INTR_LENGTH,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "LENGTH-AN",		"cob_intr_byte_length",
						1, 1, CB_INTR_BYTE_LENGTH,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "LOCALE-COMPARE",	"cob_intr_locale_compare",
						-1, 1, CB_INTR_LOCALE_COMPARE,
						CB_CATEGORY_ALPHANUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "LOCALE-DATE",		"cob_intr_locale_date",
						2, 1, CB_INTR_LOCALE_DATE,
						CB_CATEGORY_ALPHANUMERIC, 1, 2,
						LOCALE_DATE_FUNC
  },
  { "LOCALE-TIME",		"cob_intr_locale_time",
						2, 1, CB_INTR_LOCALE_TIME,
						CB_CATEGORY_ALPHANUMERIC, 1, 2,
						LOCALE_TIME_FUNC
  },
  { "LOCALE-TIME-FROM-SECONDS",	"cob_intr_lcl_time_from_secs",
						2, 1, CB_INTR_LOCALE_TIME_FROM_SECS,
						CB_CATEGORY_ALPHANUMERIC, 1, 2,
						LOCALE_TIME_FROM_FUNC
  },
  { "LOG",				"cob_intr_log",
						1, 1, CB_INTR_LOG,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "LOG10",			"cob_intr_log10",
						1, 1, CB_INTR_LOG10,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "LOWER-CASE",		"cob_intr_lower_case",
						1, 1, CB_INTR_LOWER_CASE,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						LOWER_CASE_FUNC
  },
  { "LOWEST-ALGEBRAIC",	"cob_intr_lowest_algebraic",
						1, 1, CB_INTR_LOWEST_ALGEBRAIC,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "MAX",				"cob_intr_max",
						-1, 1, CB_INTR_MAX,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "MEAN",				"cob_intr_mean",
						-1, 1, CB_INTR_MEAN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "MEDIAN",			"cob_intr_median",
						-1, 1, CB_INTR_MEDIAN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "MIDRANGE",			"cob_intr_midrange",
						-1, 1, CB_INTR_MIDRANGE,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "MIN",				"cob_intr_min",
						-1, 1, CB_INTR_MIN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "MOD",				"cob_intr_mod",
						2, 1, CB_INTR_MOD,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "MODULE-CALLER-ID",	"cob_intr_module_caller_id",
						0, 1, CB_INTR_MODULE_CALLER_ID,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MODULE-DATE",		"cob_intr_module_date",
						0, 1, CB_INTR_MODULE_DATE,
						CB_CATEGORY_NUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MODULE-FORMATTED-DATE",	"cob_intr_module_formatted_date",
						0, 1, CB_INTR_MODULE_FORMATTED_DATE,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MODULE-ID",		"cob_intr_module_id",
						0, 1, CB_INTR_MODULE_ID,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MODULE-PATH",		"cob_intr_module_path",
						0, 1, CB_INTR_MODULE_PATH,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MODULE-SOURCE",	"cob_intr_module_source",
						0, 1, CB_INTR_MODULE_SOURCE,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MODULE-TIME",		"cob_intr_module_time",
						0, 1, CB_INTR_MODULE_TIME,
						CB_CATEGORY_NUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MONETARY-DECIMAL-POINT",	"cob_intr_mon_decimal_point",
						0, 1, CB_INTR_MON_DECIMAL_POINT,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "MONETARY-THOUSANDS-SEPARATOR",	"cob_intr_mon_thousands_sep",
						0, 1, CB_INTR_MON_THOUSANDS_SEP,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "NATIONAL-OF",		"cob_intr_national_of",
						-1, 0, CB_INTR_NATIONAL_OF,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						NATIONAL_OF_FUNC
  },
  { "NUMERIC-DECIMAL-POINT",	"cob_intr_num_decimal_point",
						0, 1, CB_INTR_NUM_DECIMAL_POINT,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "NUMERIC-THOUSANDS-SEPARATOR",	"cob_intr_num_thousands_sep",
						0, 1, CB_INTR_NUM_THOUSANDS_SEP,
						CB_CATEGORY_ALPHANUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "NUMVAL",			"cob_intr_numval",
						1, 1, CB_INTR_NUMVAL,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "NUMVAL-C",			"cob_intr_numval_c",
						2, 1, CB_INTR_NUMVAL_C,
						CB_CATEGORY_NUMERIC, 0, 2,
						NUMVALC_FUNC
  },
  { "NUMVAL-F",			"cob_intr_numval_f",
						1, 1, CB_INTR_NUMVAL_F,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "ORD",				"cob_intr_ord",
						1, 1, CB_INTR_ORD,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "ORD-MAX",			"cob_intr_ord_max",
						-1, 1, CB_INTR_ORD_MAX,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "ORD-MIN",			"cob_intr_ord_min",
						-1, 1, CB_INTR_ORD_MIN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "PI",				"cob_intr_pi",
						0, 1, CB_INTR_PI,
						CB_CATEGORY_NUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "PRESENT-VALUE",	"cob_intr_present_value",
						-1, 1, CB_INTR_PRESENT_VALUE,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "RANDOM",			"cob_intr_random",
						-1, 1, CB_INTR_RANDOM,
						CB_CATEGORY_NUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "RANGE",			"cob_intr_range",
						-1, 1, CB_INTR_RANGE,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "REM",				"cob_intr_rem",
						2, 1, CB_INTR_REM,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "REVERSE",			"cob_intr_reverse",
						1, 1, CB_INTR_REVERSE,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						REVERSE_FUNC
  },
  { "SECONDS-FROM-FORMATTED-TIME",	"cob_intr_seconds_from_formatted_time",
						2, 1, CB_INTR_SECONDS_PAST_MIDNIGHT,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "SECONDS-PAST-MIDNIGHT",	"cob_intr_seconds_past_midnight",
						0, 1, CB_INTR_SECONDS_PAST_MIDNIGHT,
						CB_CATEGORY_NUMERIC, 0, 0,
						FUNCTION_NAME
  },
  { "SIGN",				"cob_intr_sign",
						1, 1, CB_INTR_SIGN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "SIN",				"cob_intr_sin",
						1, 1, CB_INTR_SIN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "SQRT",				"cob_intr_sqrt",
						1, 1, CB_INTR_SQRT,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "STANDARD-COMPARE",	"cob_intr_standard_compare",
						-1, 0, CB_INTR_STANDARD_COMPARE,
						CB_CATEGORY_ALPHANUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "STANDARD-DEVIATION",	"cob_intr_standard_deviation",
						-1, 1, CB_INTR_STANDARD_DEVIATION,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "STORED-CHAR-LENGTH",	"cob_intr_stored_char_length",
						1, 1, CB_INTR_STORED_CHAR_LENGTH,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "SUBSTITUTE",		"cob_intr_substitute",
						-1, 1, CB_INTR_SUBSTITUTE,
						CB_CATEGORY_ALPHANUMERIC, 1, 3,
						SUBSTITUTE_FUNC
  },
  { "SUBSTITUTE-CASE",	"cob_intr_substitute_case",
						-1, 1, CB_INTR_SUBSTITUTE_CASE,
						CB_CATEGORY_ALPHANUMERIC, 1, 3,
						SUBSTITUTE_CASE_FUNC
  },
  { "SUM",				"cob_intr_sum",
						-1, 1, CB_INTR_SUM,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "TAN",				"cob_intr_tan",
						1, 1, CB_INTR_TAN,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "TEST-DATE-YYYYMMDD",	"cob_intr_test_date_yyyymmdd",
						1, 1, CB_INTR_TEST_DATE_YYYYMMDD,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "TEST-DAY-YYYYDDD",	"cob_intr_test_day_yyyyddd",
						1, 1, CB_INTR_TEST_DAY_YYYYDDD,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "TEST-FORMATTED-DATETIME",	"cob_intr_test_formatted_date",
						2, 0, CB_INTR_TEST_FORMATTED_DATETIME,
						CB_CATEGORY_NUMERIC, 0, 2,
						FUNCTION_NAME
  },
  { "TEST-NUMVAL",		"cob_intr_test_numval",
						1, 1, CB_INTR_TEST_NUMVAL,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "TEST-NUMVAL-C",	"cob_intr_test_numval_c",
						2, 1, CB_INTR_TEST_NUMVAL_C,
						CB_CATEGORY_NUMERIC, 0, 2,
						NUMVALC_FUNC
  },
  { "TEST-NUMVAL-F",	"cob_intr_test_numval_f",
						1, 1, CB_INTR_TEST_NUMVAL_F,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "TRIM",				"cob_intr_trim",
						2, 1, CB_INTR_TRIM,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						TRIM_FUNC
  },
  { "UPPER-CASE",		"cob_intr_upper_case",
						1, 1, CB_INTR_UPPER_CASE,
						CB_CATEGORY_ALPHANUMERIC, 1, 1,
						UPPER_CASE_FUNC
  },
  { "VARIANCE",			"cob_intr_variance",
						-1, 1, CB_INTR_VARIANCE,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  },
  { "WHEN-COMPILED",	"cob_intr_when_compiled",
						0, 1, CB_INTR_WHEN_COMPILED,
						CB_CATEGORY_ALPHANUMERIC, 1, 0,
						WHEN_COMPILED_FUNC
  },
  { "YEAR-TO-YYYY",		"cob_intr_year_to_yyyy",
						-1, 1, CB_INTR_YEAR_TO_YYYY,
						CB_CATEGORY_NUMERIC, 0, 1,
						FUNCTION_NAME
  }
};

#define	NUM_INTRINSICS	sizeof(function_list) / sizeof(cb_intrinsic_table)

static unsigned char		cob_lower_tab[256];
static const unsigned char	pcob_lower_tab[] = "abcdefghijklmnopqrstuvwxyz";
static const unsigned char	pcob_lower_val[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* Local functions */

static int
cob_strcasecmp(const void * s1, const void * s2)
{
	/* Note - second parameter is assumed already upper case */

	const unsigned char	* p1 = (const unsigned char *)s1;
	const unsigned char	* p2 = (const unsigned char *)s2;

	for(;;) {
		unsigned char c1;
		if(cob_lower_tab[*p1]) {
			c1 = cob_lower_tab[*p1++];
		} else {
			c1 = *p1++;
		}
		unsigned char c2 = *p2++;
		if(c1 != c2) {
			return c1 < c2 ? -1 : 1;
		}
		if(!c1) {
			break;
		}
	}
	return 0;
}

static int
reserve_comp(const void * p1, const void * p2)
{
	return cob_strcasecmp(p1, ((cobc_reserved *)p2)->name);
}

static int
intrinsic_comp(const void * p1, const void * p2)
{
	return cob_strcasecmp(p1, ((cb_intrinsic_table *)p2)->name);
}

static const char *
res_get_feature(const enum cb_system_name_category category)
{
	switch(category) {
	case CB_DEVICE_NAME:
		return _("Device name");
	case CB_SWITCH_NAME:
		return _("Switch name");
	case CB_FEATURE_NAME:
		return _("Feature name");
	default:
		break;
	}
	return _("Unknown");
}

/* Global functions */

cb_tree
lookup_system_name(const char * name)
{
	for(size_t i = 0; i < SYSTEM_TAB_SIZE; ++i) {
		if(cob_strcasecmp(name, system_table[i].name) == 0) {
			return cb_build_system_name(system_table[i].category,
						      system_table[i].token);
		}
	}
	if(cb_flag_syntax_extension) {
		for(size_t i = 0; i < EXT_SYSTEM_TAB_SIZE; ++i) {
			if(cob_strcasecmp(name, ext_system_table[i].name) == 0) {
				return cb_build_system_name(ext_system_table[i].category,
							      ext_system_table[i].token);
			}
		}
	}
	return NULL;
}

cobc_reserved *
lookup_reserved_word(const char * name)
{
	cobc_reserved * p = (cobc_reserved *) bsearch(name, reserved_words, NUM_RESERVED_WORDS,
												  sizeof(cobc_reserved), reserve_comp);
	if(!p) {
		return NULL;
	}

	/* Allow obsolete/unimplemented 85 keywords as user names */
	if(!p->token && !cb_cobol85_reserved) {
		return NULL;
	}

	/* Check if the configuration has unreserved the word */
	for(noreserve * nr = cobc_nores_base; nr; nr = nr->next) {
		if(strcasecmp(name, nr->noresword) == 0) {
			return NULL;
		}
	}

	/* Check word is implemented */
	if(unlikely(p->token <= 0)) {
		/* Not implemented - If context sensitive, no error */
		if(!p->context_sens) {
			cb_error(_("'%s' reserved word, but not supported"), name);
		}
		return NULL;
	}

	/* Special actions / Context sensitive */
	if(p->context_set) {
		if(unlikely(p->context_test)) {
			/* Dependent words */
			if(!(cobc_cs_check & p->context_test)) {
				return p;
			}
		}
		cobc_cs_check |= p->context_set;
		return p;
	}

	if(p->context_test) {
		if((cobc_cs_check & p->context_test) != p->context_test) {
			return NULL;
		}
		if(!cobc_in_procedure) {
			cobc_cs_check = 0;
		}
		return p;
	}

	if(p->token == FUNCTION_ID) {
		cobc_cs_check = 0;
		cobc_force_literal = 1;
	} else if(p->token == INTRINSIC) {
		if(!cobc_in_repository) {
			return NULL;
		}
	} else if(p->token == PROGRAM_ID) {
		cobc_cs_check = CB_CS_PROGRAM_ID;
		cobc_force_literal = 1;
	} else if(p->token == REPOSITORY) {
		cobc_in_repository = 1;
	} 

	return p;
}

cb_intrinsic_table *
lookup_intrinsic(const char * name, const int checkres, const int checkimpl)
{
	if(unlikely(cobc_nores_base && checkres)) {
		for(noreserve * nr = cobc_nores_base; nr; nr = nr->next) {
			if(strcasecmp(name, nr->noresword) == 0) {
				return NULL;
			}
		}
	}
	cb_intrinsic_table * cbp = (cb_intrinsic_table *) bsearch(name, function_list, NUM_INTRINSICS,
															  sizeof(cb_intrinsic_table), intrinsic_comp);
	if(cbp &&(checkimpl || cbp->implemented)) {
		return cbp;
	}
	return NULL;
}

void
cb_list_reserved(void)
{
	putchar('\n');
	printf(_("Reserved Words\t\t\tImplemented(Y/N)"));
	puts("\n");
	for(size_t i = 0; i < NUM_RESERVED_WORDS; ++i) {
		const char * s;
		size_t n = strlen(reserved_words[i].name);
		switch(n / 8) {
		case 0:
			s = "\t\t\t\t";
			break;
		case 1:
			s = "\t\t\t";
			break;
		case 2:
			s = "\t\t";
			break;
		default:
			s = "\t";
			break;
		}
		const char * p;
		if(reserved_words[i].token == 0) {
			p = _("N(85 obsolete)");
		} else if(reserved_words[i].token > 0) {
			if(reserved_words[i].context_sens) {
				p = _("Y(Context sensitive)");
			} else {
				p = _("Y");
			}
		} else {
			if(reserved_words[i].context_sens) {
				p = _("N(Context sensitive)");
			} else {
				p = _("N");
			}
		}
		printf("%s%s%s\n", reserved_words[i].name, s, p);
	}
	putchar('\n');
	puts(_("Extra(obsolete) context sensitive words"));
	puts("AUTHOR");
	puts("DATE-COMPILED");
	puts("DATE-MODIFIED");
	puts("DATE-WRITTEN");
	puts("INSTALLATION");
	puts("REMARKS");
	puts("SECURITY");
	putchar('\n');
	puts(_("Extra internal registers\tDefinition"));
	puts("RETURN-CODE\t\t\tUSAGE BINARY-LONG");
	puts("SORT-RETURN\t\t\tUSAGE BINARY-LONG");
	puts("NUMBER-OF-CALL-PARAMETERS\tUSAGE BINARY-LONG");
	puts("COB-CRT-STATUS\t\t\tPIC 9(4)");
	puts("'LENGTH OF' phrase\t\tUSAGE BINARY-LONG");
}

void
cb_list_intrinsics(void)
{
	putchar('\n');
	puts(_("Intrinsic Function\t\tImplemented\tParameters"));
	for(size_t i = 0; i < NUM_INTRINSICS; ++i) {
		const char * s;
		size_t n = strlen(function_list[i].name);
		switch(n / 8) {
		case 0:
			s = "\t\t\t\t";
			break;
		case 1:
			s = "\t\t\t";
			break;
		case 2:
			s = "\t\t";
			break;
		default:
			s = "\t";
			break;
		}
		const char * t;
		if(function_list[i].implemented) {
			t = _("Y");
		} else {
			t = _("N");
		}
		if(function_list[i].args < 0) {
			printf("%s%s%s\t\tVariable\n", function_list[i].name,
				s, t);
		} else {
			printf("%s%s%s\t\t%d\n", function_list[i].name,
				s, t, function_list[i].args);
		}
	}
}

void
cb_list_mnemonics(void)
{
	putchar('\n');
	puts(_("Mnemonic names"));
	for(size_t i = 0; i < SYSTEM_TAB_SIZE; ++i) {
		const char * tabs;
		if(strlen(system_table[i].name) < 8) {
			tabs = "\t\t";
		} else {
			tabs = "\t";
		}
		const char * feature = res_get_feature(system_table[i].category);
		printf("%s%s%s\n", system_table[i].name, tabs, feature);
	}
	putchar('\n');
	puts(_("Extended mnemonic names(with -fsyntax-extension)"));
	for(size_t i = 0; i < EXT_SYSTEM_TAB_SIZE; ++i) {
		const char * tabs;
		if(strlen(ext_system_table[i].name) < 8) {
			tabs = "\t\t";
		} else {
			tabs = "\t";
		}
		const char * feature = res_get_feature(ext_system_table[i].category);
		printf("%s%s%s\n", ext_system_table[i].name, tabs, feature);
	}
}

void
cobc_init_reserved(void)
{
	memset(cob_lower_tab, 0, sizeof(cob_lower_tab));
	const unsigned char * v = pcob_lower_val;
	for(const unsigned char * p = pcob_lower_tab; *p; ++p, ++v) {
		cob_lower_tab[*p] = *v;
	}
}
