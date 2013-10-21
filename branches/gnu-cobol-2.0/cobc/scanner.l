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


%option 8bit
%option case-insensitive
%option never-interactive

%option noyy_scan_buffer
%option noyy_scan_bytes
%option noyy_scan_string

%option noyyget_extra
%option noyyset_extra
%option noyyget_leng
%option noyyget_text
%option noyyget_lineno
%option noyyset_lineno
%option noyyget_in
%option noyyset_in
%option noyyget_out
%option noyyset_out
%option noyyget_lval
%option noyyset_lval
%option noyyget_lloc
%option noyyset_lloc
%option noyyget_debug
%option noyyset_debug
%{

#undef	YY_READ_BUF_SIZE
#define	YY_READ_BUF_SIZE	32768
#undef	YY_BUF_SIZE
#define	YY_BUF_SIZE		32768

#define	YY_SKIP_YYWRAP
#define	yywrap()		1

#define YY_INPUT(buf,result,max_size)	\
	{	\
		if (fgets (buf, (int)max_size, yyin) == NULL) { \
			result = YY_NULL; \
		} else { \
			result = strlen (buf); \
		} \
	}

#define	YY_USER_INIT	\
	if (!plexbuff) {					\
		plexbuff = cobc_malloc ((size_t)COB_MINI_BUFF);	\
		plexsize = COB_MINI_BUFF;			\
	}							\
	if (!picbuff1) {					\
		picbuff1 = cobc_malloc ((size_t)COB_MINI_BUFF);	\
		pic1size = COB_MINI_BUFF;			\
	}							\
	if (!picbuff2) {					\
		picbuff2 = cobc_malloc ((size_t)COB_MINI_BUFF);	\
		pic2size = COB_MINI_BUFF;			\
	}

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#else
#define	YY_NO_UNISTD_H	1
#endif

#define	COB_IN_SCANNER	1
#include "cobc.h"
#include "tree.h"

#define YYSTYPE			cb_tree
#include "parser.h"

#define SET_LOCATION(x)				\
	do {						\
		(x)->source_file = cb_source_file;	\
		(x)->source_line = cb_source_line;	\
	} while (0)

/* CONSTANT (78 level) structure */
struct cb_level_78 {
	struct cb_level_78	*next;		/* Next in chain */
	struct cb_level_78	*globnext;	/* Continued next in chain */
	struct cb_level_78	*last;		/* Last in chain */
	struct cb_field		*fld78;		/* Pointer to field */
	struct cb_program	*prog;		/* Program where defined */
	const char		*pic_replace;	/* Can replace in PICTURE */
	cob_u32_t		name_len;	/* Length of name */
	cob_u32_t		pic_len;	/* Length of pic_replace */
	cob_u32_t		not_const;	/* Invalid usage check */
	cob_u32_t		chk_const;	/* Check global level use */
};

struct cb_top_level_78 {
	struct cb_top_level_78	*next;
	struct cb_level_78	*lev78ptr;
};

/* Local variables */
static struct cb_level_78	*top78ptr = NULL;
static struct cb_level_78	*const78ptr = NULL;
static struct cb_level_78	*lev78ptr = NULL;
static struct cb_level_78	*globlev78ptr = NULL;
static unsigned char		*plexbuff = NULL;
static char			*picbuff1 = NULL;
static char			*picbuff2 = NULL;
static size_t			plexsize;
static size_t			pic1size;
static size_t			pic2size;
static unsigned int		last_token_is_dot = 0;
static unsigned int		integer_is_label = 0;
static unsigned int		inside_bracket = 0;

#ifdef	HAVE_DESIGNATED_INITS
static const unsigned char	valid_char[256] = {
	['-'] = 1,
	['0'] = 1,
	['1'] = 1,
	['2'] = 1,
	['3'] = 1,
	['4'] = 1,
	['5'] = 1,
	['6'] = 1,
	['7'] = 1,
	['8'] = 1,
	['9'] = 1,
	['A'] = 1,
	['B'] = 1,
	['C'] = 1,
	['D'] = 1,
	['E'] = 1,
	['F'] = 1,
	['G'] = 1,
	['H'] = 1,
	['I'] = 1,
	['J'] = 1,
	['K'] = 1,
	['L'] = 1,
	['M'] = 1,
	['N'] = 1,
	['O'] = 1,
	['P'] = 1,
	['Q'] = 1,
	['R'] = 1,
	['S'] = 1,
	['T'] = 1,
	['U'] = 1,
	['V'] = 1,
	['W'] = 1,
	['X'] = 1,
	['Y'] = 1,
	['Z'] = 1,
	['_'] = 1,
	['a'] = 1,
	['b'] = 1,
	['c'] = 1,
	['d'] = 1,
	['e'] = 1,
	['f'] = 1,
	['g'] = 1,
	['h'] = 1,
	['i'] = 1,
	['j'] = 1,
	['k'] = 1,
	['l'] = 1,
	['m'] = 1,
	['n'] = 1,
	['o'] = 1,
	['p'] = 1,
	['q'] = 1,
	['r'] = 1,
	['s'] = 1,
	['t'] = 1,
	['u'] = 1,
	['v'] = 1,
	['w'] = 1,
	['x'] = 1,
	['y'] = 1,
	['z'] = 1
};
#else
static unsigned char		valid_char[256];
static const unsigned char	pvalid_char[] =
	"-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
#endif

/* Function declarations */
static void	read_literal (const int);
static int	scan_x (char *, const int);
static int	scan_z (char *, const int, const cob_u32_t);
static int	scan_h (char *, const int);
static int	scan_numeric (char *);
static int	scan_floating_numeric (const char *);
static void	scan_picture (char *);
static void	count_lines (const char *);
static void	scan_define_options (const char *);
static void	scan_options (const char *, const unsigned int);

%}

%s DECIMAL_IS_PERIOD DECIMAL_IS_COMMA
%x PICTURE_STATE FUNCTION_STATE

%%

%{
	if (likely(current_program)) {
		if (current_program->decimal_point == '.') {
			BEGIN DECIMAL_IS_PERIOD;
		} else {
			BEGIN DECIMAL_IS_COMMA;
		}
	}

	/* We treat integer literals immediately after '.' as labels;
	   that is, they must be level numbers or section names. */
	if (last_token_is_dot) {
		integer_is_label = 1;
		last_token_is_dot = 0;
	} else {
		integer_is_label = 0;
	}
%}


<*>^[ ]?"#DEFLIT".*\n {
	scan_define_options (yytext);
}

<*>^[ ]?"#OPTION".*\n {
	scan_options (yytext, 1);
}

<*>^[ ]?"#DEFOFF".*\n {
	scan_options (yytext, 2);
}

<*>^[ ]?"#DEFENV".*\n {
	scan_options (yytext, 3);
}

<*>\n {
	cb_source_line++;
}

^"#LINE"[ ]?[0-9]+" ".* {
	/* Line directive */
	char		*p1;
	char		*p2;

	p1 = strchr (yytext, '"');
	if (p1) {
		p2 = cobc_strdup (p1 + 1);
		p1 = strrchr (p2, '"');
		if (p1) {
			*p1 = 0;
			cb_source_file = cobc_parse_strdup (p2);
			cb_source_line = (int)strtol (yytext + 5, NULL, 10) - 1;
		}
		free (p2);
	}
}

^"#".* {
	/* Ignore */
}

"PIC" |
"PICTURE" {
	BEGIN PICTURE_STATE;
}

"FUNCTION" {
	if (cobc_in_repository || cobc_cs_check == CB_CS_EXIT) {
		yylval = NULL;
		return FUNCTION;
	}
	BEGIN FUNCTION_STATE;
}

[\'\"] {
	/* String literal */
	cobc_force_literal = 0;
	read_literal (yytext[0]);
	return LITERAL;
}

X\'[^\'\n]*\' |
X\"[^\"\n]*\" {
	/* X string literal */
	cobc_force_literal = 0;
	return scan_x (yytext + 2, yytext[1]);
}

Z\'[^\'\n]*\' |
Z\"[^\"\n]*\" {
	/* Z string literal */
	cobc_force_literal = 0;
	return scan_z (yytext + 2, yytext[1], 0);
}

L\'[^\'\n]*\' |
L\"[^\"\n]*\" {
	/* L string literal */
	cobc_force_literal = 0;
	return scan_z (yytext + 2, yytext[1], 1);
}

H\'[^\'\n]*\' |
H\"[^\"\n]*\" {
	/* H numeric literal */
	cobc_force_literal = 0;
	return scan_h (yytext + 2, yytext[1]);
}

\( {
	inside_bracket++;
	return TOK_OPEN_PAREN;
}

\) {
	if (inside_bracket > 0) {
		inside_bracket--;
	}
	return TOK_CLOSE_PAREN;
}

[0-9]+ {
	cobc_force_literal = 0;
	if (integer_is_label) {
		/* Integer label or level number */
		yylval = cb_build_reference (yytext);
		SET_LOCATION (yylval);
		return WORD;
	}
	/* Numeric literal */
	return scan_numeric (yytext);
}

<*>[ ]+ {
	/* Ignore */
}

<*>;+ {
	if (inside_bracket) {
		return SEMI_COLON;
	}
	/* Ignore */
}

<DECIMAL_IS_PERIOD>[+-]?[0-9]+\.[0-9]*E[+-]?[0-9]+ {
	/* Numeric floating point literal */
	return scan_floating_numeric (yytext);
}

<DECIMAL_IS_PERIOD>[+-]?[0-9\.]*[0-9]+ {
	/* Numeric literal */
	return scan_numeric (yytext);
}

<DECIMAL_IS_PERIOD>,+ {
	if (inside_bracket) {
		return COMMA_DELIM;
	}
	/* Ignore */
}

<DECIMAL_IS_COMMA>[+-]?[0-9]+,[0-9]*E[+-]?[0-9]+ {
	/* Numeric floating point literal */
	return scan_floating_numeric (yytext);
}

<DECIMAL_IS_COMMA>[+-]?[0-9]+[,]?[0-9]+ {
	/* Numeric literal */
	return scan_numeric (yytext);
}

<DECIMAL_IS_COMMA>[+-]?,[0-9]+ {
	/* Numeric literal */
	return scan_numeric (yytext);
}

<DECIMAL_IS_COMMA>[+-]?[0-9]+ {
	/* Numeric literal */
	return scan_numeric (yytext);
}

<DECIMAL_IS_COMMA>,{2,} {
	unput (',');
}

<DECIMAL_IS_COMMA>, {
	if (inside_bracket) {
		return COMMA_DELIM;
	}
	/* Ignore */
}

"END"[ ,;\n]+"PROGRAM" {
	cobc_force_literal = 1;
	count_lines (yytext);
	return END_PROGRAM;
}

"END"[ ,;\n]+"FUNCTION" {
	cobc_force_literal = 1;
	count_lines (yytext);
	return END_FUNCTION;
}

"PICTURE"[ ,;\n]+"SYMBOL" {
	count_lines (yytext);
	return PICTURE_SYMBOL;
}

"FROM"[ ,;\n]+"CRT" {
	count_lines (yytext);
	return FROM_CRT;
}

"SCREEN"[ ,;\n]+"CONTROL" {
	count_lines (yytext);
	return SCREEN_CONTROL;
}

"EVENT"[ ,;\n]+"STATUS" {
	count_lines (yytext);
	return EVENT_STATUS;
}

"READY"[ ,;\n]+"TRACE" {
	count_lines (yytext);
	return READY_TRACE;
}

"RESET"[ ,;\n]+"TRACE" {
	count_lines (yytext);
	return RESET_TRACE;
}

"GREATER"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n]+"TO"[ ,;\n] |
"GREATER"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n] |
"GREATER"[ ,;\n]+"THAN"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n]+"TO"[ ,;\n] |
"GREATER"[ ,;\n]+"THAN"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n] {
	count_lines (yytext);
	return GREATER_OR_EQUAL;
}

"GREATER"[ ,;\n]+"THAN"[ ,;\n] {
	count_lines (yytext);
	return GREATER;
}

"LESS"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n]+"TO"[ ,;\n] |
"LESS"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n] |
"LESS"[ ,;\n]+"THAN"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n]+"TO"[ ,;\n] |
"LESS"[ ,;\n]+"THAN"[ ,;\n]+"OR"[ ,;\n]+"EQUAL"[ ,;\n] {
	count_lines (yytext);
	return LESS_OR_EQUAL;
}

"LESS"[ ,;\n]+"THAN"[ ,;\n] {
	count_lines (yytext);
	return LESS;
}

"EQUAL"[ ,;\n]+"TO"[ ,;\n] {
	count_lines (yytext);
	return EQUAL;
}

"THEN"[ ,;\n]+"REPLACING"[ ,;\n] {
	count_lines (yytext);
	return REPLACING;
}

"LINES"[ ,;\n]+"AT"[ ,;\n]+"TOP"[ ,;\n] |
"LINES"[ ,;\n]+"TOP"[ ,;\n] |
"AT"[ ,;\n]+"TOP"[ ,;\n] {
	count_lines (yytext);
	return TOP;
}

"LINES"[ ,;\n]+"AT"[ ,;\n]+"BOTTOM"[ ,;\n] |
"LINES"[ ,;\n]+"BOTTOM"[ ,;\n] |
"AT"[ ,;\n]+"BOTTOM"[ ,;\n] {
	count_lines (yytext);
	return BOTTOM;
}

"WITH"[ ,;\n]+"NO"[ ,;\n]+"ADVANCING" |
"NO"[ ,;\n]+"ADVANCING" {
	count_lines (yytext);
	return NO_ADVANCING;
}

"ON"[ ,;\n]+"NEXT"[ ,;\n]+"PAGE"[ ,;\n] |
"NEXT"[ ,;\n]+"PAGE"[ ,;\n] {
	count_lines (yytext);
	return NEXT_PAGE;
}

"NOT"[ ,;\n]+"ON"[ ,;\n]+"SIZE"[ ,;\n]+"ERROR"[ ,;\n] |
"NOT"[ ,;\n]+"SIZE"[ ,;\n]+"ERROR"[ ,;\n] {
	count_lines (yytext);
	return NOT_SIZE_ERROR;
}

"ON"[ ,;\n]+"SIZE"[ ,;\n]+"ERROR"[ ,;\n] |
"SIZE"[ ,;\n]+"ERROR"[ ,;\n] {
	count_lines (yytext);
	return SIZE_ERROR;
}

"NOT"[ ,;\n]+"ON"[ ,;\n]+"EXCEPTION"[ ,;\n] |
"NOT"[ ,;\n]+"EXCEPTION"[ ,;\n] {
	count_lines (yytext);
	return NOT_EXCEPTION;
}

"ON"[ ,;\n]+"EXCEPTION"[ ,;\n] {
	count_lines (yytext);
	return EXCEPTION;
}

"NOT"[ ,;\n]+"ON"[ ,;\n]+"OVERFLOW"[ ,;\n] |
"NOT"[ ,;\n]+"OVERFLOW"[ ,;\n] {
	count_lines (yytext);
	return NOT_OVERFLOW;
}

"NOT"[ ,;\n]+"AT"[ ,;\n]+"END"[ ,;\n] |
"NOT"[ ,;\n]+"END"[ ,;\n] {
	count_lines (yytext);
	return NOT_END;
}

"AT"[ ,;\n]+"END"[ ,;\n] {
	count_lines (yytext);
	return END;
}

"ON"[ ,;\n]+"OVERFLOW"[ ,;\n] |
"OVERFLOW"[ ,;\n] {
	count_lines (yytext);
	return TOK_OVERFLOW;
}

"NOT"[ ,;\n]+"AT"[ ,;\n]+"END-OF-PAGE"[ ,;\n] |
"NOT"[ ,;\n]+"AT"[ ,;\n]+"EOP"[ ,;\n] |
"NOT"[ ,;\n]+"END-OF-PAGE"[ ,;\n] |
"NOT"[ ,;\n]+"EOP"[ ,;\n] {
	count_lines (yytext);
	return NOT_EOP;
}

"AT"[ ,;\n]+"END-OF-PAGE"[ ,;\n] |
"AT"[ ,;\n]+"EOP"[ ,;\n] |
"END-OF-PAGE"[ ,;\n] |
"EOP"[ ,;\n] {
	count_lines (yytext);
	return EOP;
}

"NOT"[ ,;\n]+"INVALID"[ ,;\n]+"KEY"[ ,;\n] {
	count_lines (yytext);
	return NOT_INVALID_KEY;
}

"NOT"[ ,;\n]+"INVALID"[ ,;\n] {
	count_lines (yytext);
	return NOT_INVALID_KEY;
}

"INVALID"[ ,;\n]+"KEY"[ ,;\n] {
	count_lines (yytext);
	return INVALID_KEY;
}

"INVALID"[ ,;\n] {
	count_lines (yytext);
	return INVALID_KEY;
}

"UPON"[ ,;\n]+"ENVIRONMENT-NAME" {
	count_lines (yytext);
	return UPON_ENVIRONMENT_NAME;
}

"UPON"[ ,;\n]+"ENVIRONMENT-VALUE" {
	count_lines (yytext);
	return UPON_ENVIRONMENT_VALUE;
}

"UPON"[ ,;\n]+"ARGUMENT-NUMBER" {
	count_lines (yytext);
	return UPON_ARGUMENT_NUMBER;
}

"UPON"[ ,;\n]+"COMMAND-LINE" {
	count_lines (yytext);
	return UPON_COMMAND_LINE;
}

"AFTER"[ ,;\n]+"EXCEPTION"[ ,;\n]+"CONDITION"[ ,;\n] {
	count_lines (yytext);
	return EXCEPTION_CONDITION;
}

"EXCEPTION"[ ,;\n]+"CONDITION"[ ,;\n] {
	count_lines (yytext);
	return EXCEPTION_CONDITION;
}

"AFTER"[ ,;\n]+"EC"[ ,;\n] {
	count_lines (yytext);
	return EC;
}

"LENGTH"[ ,;\n]+"OF"[ ,;\n] {
	count_lines (yytext);
	return LENGTH_OF;
}

"ID"[ ,;]+"DIVISION"[ ,;]*"." |
"IDENTIFICATION"[ ,;]+"DIVISION"[ ,;]*"." {
	/* Ignore */
}

"SWITCH"[ ]+"0" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('0');
	} else {
		yylval = cb_build_reference ("SWITCH-0");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"1" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('1');
	} else {
		yylval = cb_build_reference ("SWITCH-1");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"2" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('2');
	} else {
		yylval = cb_build_reference ("SWITCH-2");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"3" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('3');
	} else {
		yylval = cb_build_reference ("SWITCH-3");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"4" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('4');
	} else {
		yylval = cb_build_reference ("SWITCH-4");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"5" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('5');
	} else {
		yylval = cb_build_reference ("SWITCH-5");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"6" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('6');
	} else {
		yylval = cb_build_reference ("SWITCH-6");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"7" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('7');
	} else {
		yylval = cb_build_reference ("SWITCH-7");
	}
	SET_LOCATION (yylval);
	return WORD;
}

"SWITCH"[ ]+"8" {
	if (cobc_in_procedure) {
		yylval = cb_build_reference ("SWITCH");
		unput ('8');
	} else {
		yylval = cb_build_reference ("SWITCH-8");
	}
	SET_LOCATION (yylval);
	return WORD;
}

[A-Z0-9\x80-\xFF]([_A-Z0-9\x80-\xFF-]*[A-Z0-9\x80-\xFF]+)? {
	struct cb_level_78		*p78;
	struct cb_intrinsic_table	*cbp;
	struct cobc_reserved		*resptr;
	struct cb_text_list		*tlp;
	cb_tree				x;
	cb_tree				l;

	/* Check word length */
	if (unlikely(yyleng > 31)) {
		if (!cb_relaxed_syntax_check) {
			cb_error (_("Word length exceeds 31 characters - '%s'"),
				  yytext);
		} else if (yyleng > 61) {
			/* Absolute limit */
			cb_error (_("Word length exceeds maximum allowed - '%s'"),
				  yytext);
		} else if (warningopt) {
			cb_warning (_("Word length exceeds 31 characters - '%s'"),
				  yytext);
		}
	}

	/* Check Intrinsic FUNCTION name without keyword */
	if ((cobc_in_procedure && (functions_are_all || cb_intrinsic_list ||
	     current_program->function_spec_list)) || cobc_in_repository) {
		cbp = lookup_intrinsic (yytext, 1, 0);
		if (cbp) {
			if (cobc_in_repository) {
				yylval = cb_build_alphanumeric_literal (yytext, (size_t)yyleng);
				SET_LOCATION (yylval);
				return REPO_FUNCTION;
			}
			if (functions_are_all) {
				yylval = cb_build_reference (yytext);
				SET_LOCATION (yylval);
				return (enum yytokentype)(cbp->token);
			}
			for (tlp = cb_intrinsic_list; tlp; tlp = tlp->next) {
				if (!strcasecmp (yytext, tlp->text)) {
					yylval = cb_build_reference (yytext);
					SET_LOCATION (yylval);
					return (enum yytokentype)(cbp->token);
				}
			}
			l = current_program->function_spec_list;
			for (; l; l = CB_CHAIN(l)) {
				x = CB_VALUE (l);
				if (!strcasecmp (yytext,
						 (char *)(CB_LITERAL(x)->data))) {
					yylval = cb_build_reference (yytext);
					SET_LOCATION (yylval);
					return (enum yytokentype)(cbp->token);
				}
			}
		}
	}

	/* Bail early for (END) PROGRAM-ID when not a literal */
	if (unlikely(cobc_force_literal)) {
		/* Force PROGRAM-ID / END PROGRAM */
		cobc_force_literal = 0;
		yylval = cb_build_alphanumeric_literal (yytext, (size_t)yyleng);
		SET_LOCATION (yylval);
		return PROGRAM_NAME;
	}

	/* Check reserved word */
	resptr = lookup_reserved_word (yytext);
	if (resptr != NULL) {
		if (resptr->nodegen) {
			/* Save location for terminator checking */
			/* Misuse comment tree to mark statement */
			yylval = cb_build_comment (NULL);
		} else {
			yylval = NULL;
		}
		return resptr->token;
	}

	/* Check user function */
	if (cobc_in_repository) {
		yylval = cb_build_alphanumeric_literal (yytext, (size_t)yyleng);
		SET_LOCATION (yylval);
		return USER_REPO_FUNCTION;
	} else if (cobc_in_procedure) {
		if (current_program->prog_type == CB_FUNCTION_TYPE &&
		    !functions_are_all &&
		    !strcasecmp (yytext, current_program->orig_program_id)) {
			/* Direct recursive reference */
			yylval = cb_build_reference (yytext);
			SET_LOCATION (yylval);
			return USER_FUNCTION_NAME;
		}
		for (l = current_program->user_spec_list; l; l = CB_CHAIN(l)) {
			x = CB_VALUE (l);
			if (!strcasecmp (yytext, (char *)(CB_LITERAL(x)->data))) {
				yylval = cb_build_reference (yytext);
				SET_LOCATION (yylval);
				return USER_FUNCTION_NAME;
			}
		}
	}

	/* User word */

	/* Check local, global and source global CONSTANT (78) items */

	for (p78 = top78ptr; p78; p78 = p78->globnext) {
		if (strcasecmp (yytext, p78->fld78->name) == 0) {
			if (unlikely(non_const_word)) {
				if (p78->prog == current_program) {
					cb_error (_("A constant may not be used here - '%s'"), yytext);
					yylval = cb_error_node;
					return WORD;
				}
				if (p78->chk_const) {
					p78->not_const = 1;
				}
				break;
			}
			if (p78->chk_const && p78->not_const) {
				break;
			}
			yylval = CB_VALUE (p78->fld78->values);
			return LITERAL;
		}
	}

	yylval = cb_build_reference (yytext);
	SET_LOCATION (yylval);

	/* Special name handling */
	if (CB_WORD_COUNT (yylval) > 0 && CB_WORD_ITEMS (yylval)) {
		x = CB_VALUE (CB_WORD_ITEMS (yylval));
		if (CB_SYSTEM_NAME_P (x)) {
			return MNEMONIC_NAME;
		}
	}

	return WORD;
}

"<=" {
	yylval = NULL;
	return LESS_OR_EQUAL;
}

">=" {
	yylval = NULL;
	return GREATER_OR_EQUAL;
}

"<>" {
	yylval = NULL;
	return NOT_EQUAL;
}

"**" {
	yylval = NULL;
	return EXPONENTIATION;
}

"." {
	last_token_is_dot = 1;
	yylval = NULL;
	return TOK_DOT;
}

"&" {
	yylval = NULL;
	return TOK_AMPER;
}

":" {
	yylval = NULL;
	return TOK_COLON;
}

"=" {
	yylval = NULL;
	return TOK_EQUAL;
}

"/" {
	yylval = NULL;
	return TOK_DIV;
}

"*" {
	yylval = NULL;
	return TOK_MUL;
}

"+" {
	yylval = NULL;
	return TOK_PLUS;
}

"-" {
	yylval = NULL;
	return TOK_MINUS;
}

"<" {
	yylval = NULL;
	return TOK_LESS;
}

">" {
	yylval = NULL;
	return TOK_GREATER;
}

. {
	int	c;

	cb_error (_("Invalid symbol: %s - Skipping word"), yytext);
	while ((c = input ()) != EOF) {
		if (c == '\n' || c == ' ') {
			break;
		}
	}
	if (c != EOF) {
		unput (c);
	}
}


<PICTURE_STATE>{
  "IS" {
	/* Ignore */
  }
  [^ \n;]+ {
	BEGIN INITIAL;
	scan_picture (yytext);
	return PICTURE;
  }
}

<FUNCTION_STATE>{
  [A-Z0-9-]+ {
	struct cb_intrinsic_table	*cbp;
	cb_tree				l;
	cb_tree				x;

	BEGIN INITIAL;
	yylval = cb_build_reference (yytext);
	SET_LOCATION (yylval);
	for (l = current_program->user_spec_list; l; l = CB_CHAIN(l)) {
		x = CB_VALUE (l);
		if (!strcasecmp (yytext, (char *)(CB_LITERAL(x)->data))) {
			return USER_FUNCTION_NAME;
		}
	}
	cbp = lookup_intrinsic (yytext, 1, 0);
	if (cbp) {
		return (enum yytokentype)(cbp->token);
	}
	return FUNCTION_NAME;
  }
  . {
	yylval = NULL;
	return yytext[0];
  }
}

<<EOF>> {
	struct cb_level_78	*p78;
	struct cb_level_78	*p782;

	/* At EOF - Clear variables */
	for (p78 = lev78ptr; p78; ) {
		p782 = p78->next;
		free (p78);
		p78 = p782;
	}
	for (p78 = globlev78ptr; p78; ) {
		p782 = p78->next;
		free (p78);
		p78 = p782;
	}
	for (p78 = const78ptr; p78; ) {
		p782 = p78->next;
		free (p78);
		p78 = p782;
	}
	top78ptr = NULL;
	last_token_is_dot = 0;
	integer_is_label = 0;
	inside_bracket = 0;
	lev78ptr = NULL;
	globlev78ptr = NULL;
	cobc_force_literal = 0;
	yyterminate ();
}

%%

static void
read_literal (const int mark)
{
	size_t		i;
	int		c;

	i = 0;
	while ((c = input ()) != EOF) {
		plexbuff[i++] = (cob_u8_t)c;
		if (c == mark && (c = input ()) != mark) {
			i--;
			if (c == '-') {
				/* Free format continuation */
				/* Hack it as concatenation */
				unput ('&');
			} else {
				unput (c);
			}
			break;
		}
		if (i >= plexsize) {
			plexsize *= 2;
			plexbuff = cobc_realloc (plexbuff, plexsize);
		}
	}
	if (!i) {
		cb_warning (_("Alphanumeric literal has zero length"));
		cb_warning (_("A SPACE will be assumed"));
		i = 1;
		plexbuff[0] = ' ';
	}
	plexbuff[i] = 0;
	yylval = cb_build_alphanumeric_literal (plexbuff, i);
	SET_LOCATION (yylval);
}

static int
scan_x (char *text, const int mark)
{
	unsigned char		*src;
	unsigned char		*dst;
	size_t			currlen;
	int			high;
	int			c;

	currlen = strlen (text);
	if (currlen > plexsize) {
		plexsize = currlen;
		plexbuff = cobc_realloc (plexbuff, plexsize);
	}
	src = (unsigned char *)text;
	dst = plexbuff;
	high = 1;
	for (; (int)*src != mark; src++) {
		c = (int)*src;
		if ('0' <= c && c <= '9') {
			c = c - '0';
		} else if ('A' <= c && c <= 'F') {
			c = c - 'A' + 10;
		} else if ('a' <= c && c <= 'f') {
			c = c - 'a' + 10;
		} else {
			goto error;
		}
		if (high) {
			*dst = (cob_u8_t)(c << 4);
		} else {
			*dst++ += (cob_u8_t)c;
		}
		high = 1 - high;
	}

	if (high) {
		yylval = cb_build_alphanumeric_literal (plexbuff, (size_t)(dst - plexbuff));
		SET_LOCATION (yylval);
		return LITERAL;
	}
	/* Fall through */
error:
	cb_error (_("Invalid X literal: %s"), text);
	yylval = cb_error_node;
	return LITERAL;
}

static int
scan_z (char *text, const int mark, const cob_u32_t llit)
{
	unsigned char		*src;
	unsigned char		*dst;
	size_t			currlen;

	/* currlen includes the terminating quote */
	currlen = strlen (text);
	if (currlen > plexsize) {
		plexsize = currlen;
		plexbuff = cobc_realloc (plexbuff, plexsize);
	}
	src = (unsigned char *)text;
	dst = plexbuff;
	for (; (int)*src != mark; ++src, ++dst) {
		*dst = *src;
	}
	*dst = 0;

	/* Count is correct here as the trailing quote is now a null */
	yylval = cb_build_alphanumeric_literal (plexbuff, currlen);
	CB_LITERAL(yylval)->llit = llit;
	SET_LOCATION (yylval);
	return LITERAL;
}

static int
scan_h (char *text, const int mark)
{
	unsigned char	*p;
	cob_u64_t	val;
	size_t		size;
	int		c;

	p = (unsigned char *)text;
	val = 0;
	size = 0;
	for (; (int)*p != mark; p++, size++) {
		if (size > 15) {
			goto error;
		}
		c = (int)*p;
		if ('0' <= c && c <= '9') {
			c = c - '0';
		} else if ('A' <= c && c <= 'F') {
			c = c - 'A' + 10;
		} else if ('a' <= c && c <= 'f') {
			c = c - 'a' + 10;
		} else {
			goto error;
		}
		val = (val << 4) + c;
	}

	sprintf ((char *)plexbuff, CB_FMT_LLU, val);
	yylval = cb_build_numeric_literal (0, (const void *)plexbuff, 0);
	SET_LOCATION (yylval);
	return LITERAL;

error:
	cb_error (_("Invalid H literal: %s"), text);
	yylval = cb_error_node;
	return LITERAL;
}

static int
scan_numeric (char *text)
{
	char		*s;
	int		sign;
	int		scale;

	/* Get sign */
	sign = (*text == '+') ? 1 : (*text == '-') ? -1 : 0;
	if (sign) {
		text++;
	}

	/* Get decimal point */
	scale = 0;
	s = strchr (text, current_program->decimal_point);
	if (s) {
		scale = (int)strlen (s) - 1;
		/* Remove decimal point */
		/* Moves trailing null */
		memmove (s, s + 1, (size_t)(scale + 1));
	}
	if (unlikely(strchr (text, '.'))) {
		cb_error (_("Invalid numeric literal"));
		goto num_zero;
	}
	if (unlikely(strchr (text, ','))) {
		cb_error (_("Invalid numeric literal"));
		goto num_zero;
	}
	if (unlikely(strlen (text) > COB_MAX_DIGITS)) {
		cb_error (_("Invalid numeric literal"));
		goto num_zero;
	}
	yylval = cb_build_numeric_literal (sign, text, scale);
	SET_LOCATION (yylval);
	return LITERAL;
num_zero:
	yylval = cb_build_numeric_literal (0, "0", 0);
	SET_LOCATION (yylval);
	return LITERAL;
}

static int
scan_floating_numeric (const char *text)
{
	size_t		size1;
	size_t		size2;
	int		sign;
	int		scale;
	int		exponent;
	int		n;
	char		significand_int[40];
	char		significand_dec[40];
	char		result[128];
	char		decpoint[4];
	char		junk[4];

	/* Get sign */
	sign = (*text == '+') ? 1 : (*text == '-') ? -1 : 0;
	if (sign) {
		text++;
	}

	exponent = 0;
	significand_dec[0] = '0';
	significand_dec[1] = 0;

	/* Separate components */
	n = sscanf (text, "%[^.,]%[,.]%[^Ee]%[Ee]%d", significand_int, decpoint,
		    significand_dec, junk, &exponent);
	if (n != 5) {
		/* No decimals in significand */
		n = sscanf (text, "%[^.,]%[,.]%[Ee]%d", significand_int,
			    decpoint, junk, &exponent);
	}

	/* Validation */
	size1 = strlen (significand_int);
	if (size1 > 17U) {
		size1 = 17;
		significand_int[17] = 0;
		cb_error (_("Invalid floating-point literal"));
	}
	size2 = strlen (significand_dec);
	if (size2 > 17U) {
		size2 = 17;
		significand_dec[17] = 0;
		cb_error (_("Invalid floating-point literal"));
	}
	if ((size1 + size2) > 18U) {
		cb_error (_("Invalid floating-point literal"));
	}
	if (exponent > 76) {
		exponent = 76;
		cb_error (_("Invalid floating-point literal"));
	}
	if (exponent < -78) {
		exponent = -78;
		cb_error (_("Invalid floating-point literal"));
	}

	/* Determine scale */
	/* Base scale is decimal part of the significand */
	scale = (int)size2;
	/* Adjust according to exponent */
	if (exponent < 0) {
		/* Decimals; power down by scale difference */
		exponent = -exponent;
		scale += exponent;
		result[0] = 0;
		if (exponent > (int)size1) {
			n = exponent - (int)size1;
			for (; n; --n) {
				strcat (result, "0");
			}
		}
		strcat (result, significand_int);
		strcat (result, significand_dec);
	} else if (exponent > 0) {
		/* No decimals; power up by scale difference */
		strcpy (result, significand_int);
		strcat (result, significand_dec);
		if (exponent >= scale) {
			n = exponent - scale;
			for (; n; --n) {
				strcat (result, "0");
			}
			scale = 0;
		} else {
			scale -= exponent;
		}
	} else {
		/* Exponent is 0; take as is */
		strcpy (result, significand_int);
		strcat (result, significand_dec);
	}

	yylval = cb_build_numeric_literal (sign, result,
					   scale);
	SET_LOCATION (yylval);
	return LITERAL;
}

static int
can_replace (const char *src1, const char *src2, const size_t size,
	     const size_t iteration)
{
	const unsigned char	*p;

	/* Check if we can do a replacement */
	if (strncasecmp (src1, src2, size)) {
		return 0;
	}
	p = (const unsigned char *)src1 + size;
	if (valid_char[*p]) {
		return 0;
	}
	if (iteration) {
		p = (const unsigned char *)src1 - 1;
		if (valid_char[*p]) {
			return 0;
		}
	}
	return 1;
}

static const char *
check_78_replace (const cb_tree p)
{
	/* Check if we can do a constant replacement within PICTURE */
	if (CB_LITERAL_P (p)) {
		if (CB_LITERAL(p)->size > 50) {
			return NULL;
		}
		return (const char *)(CB_LITERAL(p)->data);
	}
	if (p == cb_low) {
		return "LOW-VALUE";
	}
	if (p == cb_high) {
		return "HIGH-VALUE";
	}
	if (p == cb_space) {
		return "SPACE";
	}
	if (p == cb_zero) {
		return "ZERO";
	}
	if (p == cb_quote) {
		return "QUOTE";
	}
	if (p == cb_null) {
		return "NULL";
	}
	return NULL;
}

static void
scan_picture (char *text)
{
	unsigned char			*p;
	const struct cb_level_78	*p78;
	size_t				n;
	size_t				i;
	size_t				size;
	size_t				sizep;

	/* Scan a PICTURE clause */
	/* Normalize the input */
	for (p = (unsigned char *)text; *p; p++) {
		/* unput trailing '.' or ',' */
		if (p[1] == 0 && (*p == '.' || *p == ',')) {
			unput (*p);
			*p = 0;
			break;
		}
		*p = (unsigned char)toupper (*p);
	}

	if (!top78ptr) {
		yylval = cb_build_picture (text);
		return;
	}

	memset (picbuff1, 0, pic1size);
	memset (picbuff2, 0, pic2size);
	strcpy (picbuff1, text);
	for (p78 = top78ptr; p78; p78 = p78->globnext) {
		if (!p78->pic_replace) {
			strcpy (picbuff2, picbuff1);
			continue;
		}
		size = p78->name_len;
		sizep = p78->pic_len;
		i = 0;
		for (n = 0; n < strlen (picbuff1); n++) {
			if (can_replace (&picbuff1[n], p78->fld78->name, size, n)) {
				memcpy (&picbuff2[i], p78->pic_replace, sizep);
				n += size - 1;
				i += sizep;
			} else {
				picbuff2[i++] = picbuff1[n];
			}
		}
		picbuff2[i] = 0;
		strcpy (picbuff1, picbuff2);
	}
	yylval = cb_build_picture (picbuff2);
}

static void
count_lines (const char *text)
{
	const char	*p;

	/* Count newlines in text */
	for (p = text; *p; p++) {
		if (*p == '\n') {
			cb_source_line++;
		}
	}
}

static void
cb_add_const_var (const char *name, cb_tree value)
{
	cb_tree			x;
	struct cb_level_78	*p78;
	struct cb_field		*f;


	/* Add an inline constant */
	x = cb_build_constant (cb_build_reference (name), value);
	f = CB_FIELD (x);
	f->flag_item_78 = 1;
	f->flag_is_global = 1;
	f->level = 1;
	(void)cb_validate_78_item (f, 1);

	/* Add constant item */
	p78 = cobc_malloc (sizeof(struct cb_level_78));
	p78->fld78 = f;
	p78->prog = NULL;
	p78->pic_replace = check_78_replace (CB_VALUE(f->values));
	if (p78->pic_replace) {
		p78->pic_len = (cob_u32_t)strlen (p78->pic_replace);
	}
	p78->name_len = (cob_u32_t)strlen (f->name);
	/* RXWRXW - Check this */
	p78->chk_const = 0;
	if (!const78ptr) {
		p78->last = p78;
	} else {
		p78->last = const78ptr->last;
	}
	p78->next = const78ptr;
	p78->globnext = const78ptr;
	const78ptr = p78;
	if (globlev78ptr) {
		globlev78ptr->last->globnext = const78ptr;
	} else if (lev78ptr) {
		lev78ptr->last->globnext = const78ptr;
	} else {
		top78ptr = const78ptr;
	}
}

static void
scan_options (const char *text, const unsigned int optype)
{
	COB_UNUSED (text);
	COB_UNUSED (optype);
}

static void
scan_define_options (const char *text)
{
	char				*p;
	char				*s;
	char				*var;
	const struct cb_level_78	*p78;
	char				*q;
	unsigned char			*t;
	cb_tree				x;
	size_t				size;
	int				scale;
	int				sign;

	/* Scan a source inline define */
	p = cobc_strdup (text);

	/* Ignore first part */
	s = strtok (p, " ");

	/* Variable name */
	s = strtok (NULL, " \n");
	if (!s) {
		free (p);
		return;
	}

	/* Check for already defined constant */
	for (p78 = top78ptr; p78; p78 = p78->globnext) {
		if (strcasecmp (s, p78->fld78->name) == 0) {
			free (p);
			return;
		}
	}

	var = cobc_strdup (s);

	/* Value */
	s = strtok (NULL, "\n");
	if (!s) {
		cb_error (_("Invalid CONSTANT - %s"), var);
		goto freevar;
	}

	if (*s == '"' || *s == '\'') {
		/* Alphanumeric literal */
		sign = *s;
		size = strlen (s);
		q = s + size - 1;
		if (q == s || *q != sign) {
			cb_error (_("Invalid alphanumeric CONSTANT - %s"), s);
			goto freevar;
		}
		if (size < 3) {
			cb_error (_("Empty alphanumeric CONSTANT - %s"), s);
			goto freevar;
		}
		*q = 0;
		size -= 2;
		x = cb_build_alphanumeric_literal (s + 1, size);
	} else {
		/* Get sign */
		sign = (*s == '+') ? 1 : (*s == '-') ? -1 : 0;
		if (sign) {
			s++;
		}

		/* Get decimal point */
		scale = 0;
		q = strchr (s, '.');
		if (q) {
			scale = (int)strlen (q) - 1;
			if (scale < 1) {
				cb_error (_("Invalid numeric CONSTANT - %s"), s);
				goto freevar;
			}
			/* Remove decimal point */
			memmove (q, q + 1, (size_t)(scale + 1));
		}
		for (t = (unsigned char *)s; *t; ++t) {
			if (*t < '0' || *t  > '9') {
				cb_error (_("Invalid numeric CONSTANT - %s"), s);
				goto freevar;
			}
		}
		if (strlen (s) > COB_MAX_DIGITS) {
			cb_error (_("Invalid numeric CONSTANT - %s"), s);
			goto freevar;
		}

		x = cb_build_numeric_literal (sign, s, scale);
	}
	/* Add to constant list */
	cb_add_const_var (var, x);

freevar:
	free (p);
	free (var);
}

/* Global functions */

void
ylex_clear_all (void)
{
	/* Clear buffers after parsing all source elements */
	if (picbuff2) {
		free (picbuff2);
		picbuff2 = NULL;
	}
	if (picbuff1) {
		free (picbuff1);
		picbuff1 = NULL;
	}
	if (plexbuff) {
		free (plexbuff);
		plexbuff = NULL;
	}
	plexsize = 0;
	pic1size = 0;
	pic2size = 0;
}

void
ylex_call_destroy (void)
{
	/* Release flex buffers */
	(void)yylex_destroy ();
	const78ptr = NULL;
}

void
cb_unput_dot (void)
{
	unput ('.');
}

void
cb_reset_78 (void)
{
	struct cb_level_78	*p78;
	struct cb_level_78	*p782;

	/* Remove constant (78 level) items for current program */
	for (p78 = lev78ptr; p78; ) {
		p782 = p78->next;
		free (p78);
		p78 = p782;
	}
	lev78ptr = NULL;
	for (p78 = globlev78ptr; p78; p78 = p78->next) {
		p78->not_const = 0;
	}
	if (globlev78ptr) {
		top78ptr = globlev78ptr;
	} else {
		top78ptr = const78ptr;
	}
}

void
cb_reset_global_78 (void)
{
	struct cb_level_78	*p78;
	struct cb_level_78	*p782;

	/* Remove constant (78 level) items for top program */
	for (p78 = globlev78ptr; p78; ) {
		p782 = p78->next;
		free (p78);
		p78 = p782;
	}
	globlev78ptr = NULL;
	top78ptr = const78ptr;
}

void
cb_add_78 (struct cb_field *f)
{
	struct cb_level_78	*p78;

	/* Add a constant (78 level) item */
	p78 = cobc_malloc (sizeof(struct cb_level_78));
	p78->fld78 = f;
	p78->prog = current_program;
	p78->pic_replace = check_78_replace (CB_VALUE(f->values));
	if (p78->pic_replace) {
		p78->pic_len = (cob_u32_t)strlen (p78->pic_replace);
	}
	p78->name_len = (cob_u32_t)strlen (f->name);
	if (f->flag_is_global) {
		if (!globlev78ptr) {
			p78->last = p78;
		} else {
			p78->last = globlev78ptr->last;
		}
		p78->last->globnext = const78ptr;
		p78->next = globlev78ptr;
		p78->globnext = globlev78ptr;
		p78->chk_const = 1;
		globlev78ptr = p78;
		if (lev78ptr) {
			lev78ptr->last->globnext = globlev78ptr;
		} else {
			top78ptr = globlev78ptr;
		}
	} else {
		if (!lev78ptr) {
			p78->last = p78;
		} else {
			p78->last = lev78ptr->last;
		}
		if (globlev78ptr) {
			p78->last->globnext = globlev78ptr;
		} else {
			p78->last->globnext = const78ptr;
		}
		p78->next = lev78ptr;
		p78->globnext = lev78ptr;
		lev78ptr = p78;
		top78ptr = lev78ptr;
	}
}

struct cb_field *
check_level_78 (const char *name)
{
	const struct cb_level_78	*p78;

	/* Check against a current constant (78 level) */
	for (p78 = lev78ptr; p78; p78 = p78->next) {
		if (strcasecmp (name, p78->fld78->name) == 0) {
			return p78->fld78;
		}
	}
	return NULL;
}

#ifndef	HAVE_DESIGNATED_INITS
void
cobc_init_scanner (void)
{
	const unsigned char	*p;

	memset (valid_char, 0, sizeof(valid_char));
	for (p = pvalid_char; *p; ++p) {
		valid_char[*p] = 1;
	}
}
#endif
