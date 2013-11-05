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


%option 8bit
%option case-insensitive
%option never-interactive
%option prefix="pp"

%option stack

%option noyy_top_state
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
#define	ppwrap()		1

#define	PPLEX_BUFF_LEN		512
#define YY_INPUT(buf,result,max_size)	result = ppinput(buf, max_size);
#define	ECHO				fputs(yytext, yyout)

#define	YY_USER_INIT							\
	if(!plexbuff1) {						\
		plexbuff1 = new char[COB_SMALL_BUFF];	\
	}								\
	if(!plexbuff2) {						\
		plexbuff2 = new char[COB_SMALL_BUFF];	\
	}								\
	requires_listing_line = 1;					\
	comment_allowed = 1;

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#else
#define	YY_NO_UNISTD_H	1
#endif
#include <ctype.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define	COB_IN_PPLEX	1
#include "cobc.h"
#include "ppparse.hpp"

#define PLEX_COND_DEPTH		16

struct copy_info {
	copy_info		*next;
	const char		*file;
	char			*dname;
	cb_replace_list	*replacing;
	YY_BUFFER_STATE	buffer;
	int				line;
	int				quotation_mark;
	int				source_format;
	copy_info() {
		memset(this, 0, sizeof(copy_info));
	}
};

struct plex_stack {
	unsigned int	cmd;
	unsigned int	skip;
	unsigned int	cond;
	int				line;
};

/* Global variables */


/* Local variables */
static char *		plexbuff1 = NULL;
static char *		plexbuff2 = NULL;
static size_t		newline_count = 0;
static size_t		within_comment = 0;
static size_t		inside_bracket = 0;
static size_t		consecutive_quotation = 0;
static size_t		need_continuation = 0;
static size_t		buffer_overflow = 0;
static size_t		comment_allowed;
static unsigned int	plex_skip_input = 0;
static unsigned int	plex_nest_depth = 0;
static int			quotation_mark = 0;
static int			listing_line = 0;
static int			requires_listing_line;
static int			requires_new_line = 0;

static cb_replace_list * current_replace_list = NULL;
static cb_replace_list * save_current_replace = NULL;
static cb_replace_list * base_replace_list = NULL;

static cb_text_list * text_queue = NULL;

static copy_info * copy_stack = NULL;

static plex_stack plex_cond_stack[PLEX_COND_DEPTH];

/* Function declarations */
static int	ppinput				(char *, const size_t);
static void	ppecho				(const char *, const cob_u32_t, const size_t);
static void	switch_to_buffer	(const int, const char *, const YY_BUFFER_STATE);
static void	check_listing		(const char *, const unsigned int);
static void	skip_to_eol			(void);
static void	display_to_eol		(void);
static void	check_comments		(const char *, const char *);

%}

WORD		[_0-9A-Z\x80-\xFF-]+
NUMRIC_LITERAL	[+-]?[0-9,.]*[0-9]
ALNUM_LITERAL	\"[^\"\n]*\"|\'[^\'\n]*\'
SET_PAREN_LIT	\([^()\n]*\)
DEFNUM_LITERAL	[+-]?[0-9]*[\.]*[0-9]+

%x COPY_STATE
%x PSEUDO_STATE
%x SOURCE_DIRECTIVE_STATE
%x DEFINE_DIRECTIVE_STATE
%x SET_DIRECTIVE_STATE
%x TURN_DIRECTIVE_STATE
%x IF_DIRECTIVE_STATE
%x ELSE_DIRECTIVE_STATE
%x ENDIF_DIRECTIVE_STATE

%%

%{
%}

<*>"*>".*		{
	#if	0	/* RXWRXW - Directive state */
	if(YY_START != DIRECTIVE_STATE && YY_START != SET_DIRECTIVE_STATE) {
		ppecho(" ", 0, 1);
	}
	#endif
}

^[ ]*">>"[ ]?"DEFINE "	{
	/* Define here to preempt next debug rule below */
	BEGIN DEFINE_DIRECTIVE_STATE;
	return DEFINE_DIRECTIVE;
}

^[ ]*">>"[ ]?"DISPLAY "	{
	/* Define here to preempt next debug rule below */
	display_to_eol();
}

^[ ]*">>D"		{
	/* OC extension for floating debug line */
	/* Remove line if debugging lines not activated */
	/* Otherwise ignore the directive part of the line */
	if(!cb_flag_debugging_line) {
		skip_to_eol();
	}
}

^[ ]*">>"[ ]?"SOURCE "	{
	BEGIN SOURCE_DIRECTIVE_STATE;
	return SOURCE_DIRECTIVE;
}

^[ ]*">>"[ ]?"SET "	{
	/* OC extension */
	BEGIN SET_DIRECTIVE_STATE;
	return SET_DIRECTIVE;
}

^[ ]*">>"[ ]?"TURN "	{
	BEGIN TURN_DIRECTIVE_STATE;
	return TURN_DIRECTIVE;
}

^[ ]*">>"[ ]?"IF "	{
	BEGIN IF_DIRECTIVE_STATE;
	return IF_DIRECTIVE;
}

^[ ]*">>"[ ]?"ELIF " |
^[ ]*">>"[ ]?"ELSE-IF "	{
	BEGIN IF_DIRECTIVE_STATE;
	return ELIF_DIRECTIVE;
}

^[ ]*">>"[ ]?"ELSE"	{
	BEGIN ELSE_DIRECTIVE_STATE;
	return ELSE_DIRECTIVE;
}

^[ ]*">>"[ ]?"END-IF"	{
	BEGIN ENDIF_DIRECTIVE_STATE;
	return ENDIF_DIRECTIVE;
}

^[ ]*">>"[ ]?"LEAP-SECOND"	{
	if(warningopt) {
		cb_plex_warning(newline_count, _("Ignoring LEAP-SECOND directive"));
	}
	skip_to_eol();
}

^[ ]*">>"[ ]*\n		{
	cb_plex_warning(newline_count, _("Ignoring empty directive"));
	unput('\n');
}

^[ ]*">>"[ ]*[_0-9A-Z-]+	{
	char	*s;

	s = strchr(yytext, '>');
	cb_plex_warning(newline_count, _("Ignoring invalid directive - '%s'"), s);
	skip_to_eol();
}

^[ ]*">>"		{
	cb_plex_warning(newline_count, _("Ignoring invalid directive"));
	skip_to_eol();
}

^[ ]*"$DISPLAY "		{
	display_to_eol();
}

^[ ]*"$SET "		{
	BEGIN SET_DIRECTIVE_STATE;
	return SET_DIRECTIVE;
}

^[ ]*"$IF "		{
	BEGIN IF_DIRECTIVE_STATE;
	return IF_DIRECTIVE;
}

^[ ]*"$ELIF " |
^[ ]*"$ELSE-IF "		{
	BEGIN IF_DIRECTIVE_STATE;
	return ELIF_DIRECTIVE;
}

^[ ]*"$ELSE"		{
	BEGIN ELSE_DIRECTIVE_STATE;
	return ELSE_DIRECTIVE;
}

^[ ]*"$END"		{
	BEGIN ENDIF_DIRECTIVE_STATE;
	return ENDIF_DIRECTIVE;
}

^[ ]*"$"[_0-9A-Z-]+	{
	char	*s;

	s = strchr(yytext, '$');
	cb_plex_warning(newline_count, _("Ignoring invalid directive - '%s'"), s);
	skip_to_eol();
}

^[ ]*"$"		{
	cb_plex_warning(newline_count, _("Spurious '$' detected - ignoring"));
	skip_to_eol();
}

"PROCESS"		{
	cb_plex_warning(newline_count, _("PROCESS statement ignored"));
	skip_to_eol();
}

"COPY"			{
	yy_push_state(COPY_STATE);
	return COPY;
}

"INCLUDE"		{
	yy_push_state(COPY_STATE);
	return COPY;
}

"REPLACE"		{
	yy_push_state(COPY_STATE);
	return REPLACE;
}

"ID"[ ,;]+"DIVISION" |
"IDENTIFICATION"[ ,;]+"DIVISION" {
	/* Allow comment sentences/paragraphs */
	comment_allowed = 1;
	ppecho(yytext, 0, yyleng);
}

"PROGRAM-ID"	{
	/* Allow comment sentences/paragraphs */
	comment_allowed = 1;
	ppecho(yytext, 0, yyleng);
}

"DIVISION"	{
	/* Disallow comment sentences/paragraphs */
	comment_allowed = 0;
	ppecho(yytext, 0, yyleng);
}

"SECTION"	{
	/* Disallow comment sentences/paragraphs */
	comment_allowed = 0;
	ppecho(yytext, 0, yyleng);
}

"AUTHOR"		{ check_comments("AUTHOR", yytext); }
"DATE-WRITTEN"		{ check_comments("DATE-WRITTEN", yytext); }
"DATE-MODIFIED"		{ check_comments("DATE-MODIFIED", yytext); }
"DATE-COMPILED"		{ check_comments("DATE-COMPILED", yytext); }
"INSTALLATION"		{ check_comments("INSTALLATION", yytext); }
"REMARKS"		{ check_comments("REMARKS", yytext); }
"SECURITY"		{ check_comments("SECURITY", yytext); }

"EJECT"\.? |
"SKIP1"\.? |
"SKIP2"\.? |
"SKIP3"\.?	{
	/* These words are comments in various COBOL dialects */
	if(cb_verify(cb_eject_statement, yytext)) {
		/* Ignore */
	} else {
		ECHO;
		check_listing(yytext, 0);
	}
}

"WITH"[ ,;]+"DEBUGGING"[ ,;]+"MODE" |
"DEBUGGING"[ ,;]+"MODE"	{
	/* Pick up early - Also activates debugging lines */
	cb_flag_debugging_line = 1;
	ppecho(yytext, 0, yyleng);
}

[,;]?\n		{
	ppecho("\n", 0, 1);
	cb_source_line++;
}

[;]?[ ]+	{
	ppecho(" ", 1U, 1);
}

[,]?[ ]+	{
	if(inside_bracket) {
		ppecho(", ", 0, 2);
	} else {
		ppecho(" ", 1U, 1);
	}
}

"("		{
	inside_bracket++;
	ppecho("(", 0, 1);
}

")"		{
	if(inside_bracket) {
		inside_bracket--;
	}
	ppecho(")", 0, 1);
}

{WORD} |
{NUMRIC_LITERAL} |
{ALNUM_LITERAL} |
.		{
	ppecho(yytext, 0, yyleng);
}

<SOURCE_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  "FORMAT"		{ return FORMAT; }
  "IS"			{ return IS; }
  "FIXED"		{ return FIXED; }
  "FREE"		{ return FREE; }
  [ ,;]+		{ /* ignore */ }
  .			{ }
}

<DEFINE_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  "CONSTANT"		{
	return CONSTANT;
  }
  "AS"			{
	return AS;
  }
  "OFF"			{
	return OFF;
  }
  "OVERRIDE"		{
	return OVERRIDE;
  }
  "PARAMETER"		{
	return PARAMETER;
  }
  {NUMRIC_LITERAL} |
  {ALNUM_LITERAL}	{
	pplval.s = cobc_plex_strdup(yytext);
	return LITERAL;
  }
  {WORD}		{
	pplval.s = cobc_plex_strdup(yytext);
	return VARIABLE;
  }
  [ ,;]+		{ /* ignore */ }
  .			{ }
}

<SET_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  "CONSTANT"		{
	return CONSTANT;
  }
  "SOURCEFORMAT"	{
	return SOURCEFORMAT;
  }
  "FOLDCOPYNAME" |
  "FOLD-COPY-NAME"	{
	return FOLDCOPYNAME;
  }
  "NOFOLDCOPYNAME" |
  "NOFOLD-COPY-NAME"	{
	return NOFOLDCOPYNAME;
  }
  "AS"			{
	return AS;
  }
  {DEFNUM_LITERAL} |
  {ALNUM_LITERAL}	{
	pplval.s = cobc_plex_strdup(yytext);
	return LITERAL;
  }
  {SET_PAREN_LIT}	{
	yytext[strlen(yytext) - 1] = 0;
	pplval.s = cobc_plex_strdup(yytext + 1);
	return LITERAL;
  }
  {WORD}		{
	pplval.s = cobc_plex_strdup(yytext);
	return VARIABLE;
  }
  [ ,;]+		{ /* ignore */ }
  .			{ }
}

<TURN_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  "ON"			{
	return ON;
  }
  "OFF"			{
	return OFF;
  }
  "WITH"		{
	return WITH;
  }
  "LOCATION"		{
	return LOCATION;
  }
  "CHECKING"		{
	return CHECKING;
  }
  {DEFNUM_LITERAL} |
  {ALNUM_LITERAL}	{
	pplval.s = cobc_plex_strdup(yytext);
	return LITERAL;
  }
  {SET_PAREN_LIT}	{
	yytext[strlen(yytext) - 1] = 0;
	pplval.s = cobc_plex_strdup(yytext + 1);
	return LITERAL;
  }
  {WORD}		{
	pplval.s = cobc_plex_strdup(yytext);
	return VARIABLE;
  }
  [ ,;]+		{ /* ignore */ }
  .			{ }
}

<IF_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  [ ,;]+		{ /* ignore */ }
  "IS"			{ return IS; }
  "NOT"			{ return NOT; }
  "EQUAL"		{ return EQUAL; }
  "TO"			{ return TO; }
  "OR"			{ return OR; }
  "GREATER"		{ return GREATER; }
  "LESS"		{ return LESS; }
  "THAN"		{ return THAN; }
  "DEFINED"		{ return DEFINED; }
  "SET"			{ return SET; }
  ">="			{ return GE; }
  ">"			{ return GT; }
  "<="			{ return LE; }
  "<>"			{ return NE; }
  "<"			{ return LT; }
  "="			{ return EQ; }
  {NUMRIC_LITERAL} |
  {ALNUM_LITERAL}	{
	pplval.s = cobc_plex_strdup(yytext);
	return LITERAL;
  }
  {WORD}		{
	pplval.s = cobc_plex_strdup(yytext);
	return VARIABLE;
  }
  .			{ }
}

<ELSE_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  .+			{ /* ignore */ }
}

<ENDIF_DIRECTIVE_STATE>{
  \n			{
	BEGIN INITIAL;
	unput('\n');
	return TERMINATOR;
  }
  .+			{ /* ignore */ }
}

<COPY_STATE>{
  [,;]?\n		{
	ECHO;
	check_listing(yytext, 0);
	cb_source_line++;
  }
  [,;]?[ ]+		{ /* ignore */ }
  "."			{ yy_pop_state(); return DOT; }
  "=="			{ yy_push_state(PSEUDO_STATE); return EQEQ; }
  "("			{ return '('; }
  ")"			{ return ')'; }
  "BY"			{ return BY; }
  "IN"			{ return IN; }
  "OF"			{ return OF; }
  "OFF"			{ return OFF; }
  "SUPPRESS"		{ return SUPPRESS; }
  "PRINTING"		{ return PRINTING; }
  "REPLACING"		{ return REPLACING; }
  "LEADING"		{ return LEADING; }
  "TRAILING"		{ return TRAILING; }
  "ALSO"		{ return ALSO; }
  "LAST"		{ return LAST; }
  {WORD} |
  {NUMRIC_LITERAL} |
  {ALNUM_LITERAL} |
  .			{ pplval.s = cobc_plex_strdup(yytext); return TOKEN; }
}

<PSEUDO_STATE>{
  [,;]?\n		{
	ECHO;
	check_listing(yytext, 0);
	cb_source_line++;
  }

  [,;]?[ ]+		{
	pplval.s = cobc_plex_strdup(" ");
	return TOKEN;
  }

  "=="			{
	yy_pop_state();
	return EQEQ;
  }

  {WORD} |
  {NUMRIC_LITERAL} |
  {ALNUM_LITERAL} |
  .			{
	pplval.s = cobc_plex_strdup(yytext);
	return TOKEN;
  }
}


<<EOF>> {
	copy_info * p = copy_stack;

	yy_delete_buffer(YY_CURRENT_BUFFER);

	/* Terminate at the end of all input */
	if(p->next == NULL) {
		/* Check dangling IF/ELSE */
		for(; plex_nest_depth > 0; --plex_nest_depth) {
			cb_source_line = plex_cond_stack[plex_nest_depth].line;
			cb_error(_("Dangling IF/ELSE directive"));
		}
		plex_nest_depth = 0;
		delete [] p->dname;
		delete p;
		listing_line = 0;
		requires_listing_line = 1;
		requires_new_line = 0;
		need_continuation = 0;
		buffer_overflow = 0;
		within_comment = 0;
		newline_count = 0;
		inside_bracket = 0;
		comment_allowed = 1;
		current_replace_list = NULL;
		base_replace_list = NULL;
		save_current_replace = NULL;
		text_queue = NULL;
		copy_stack = NULL;
		quotation_mark = 0;
		consecutive_quotation = 0;
		yyterminate();
	}

	/* Close the current file */
	fclose(ppin);

	/* Switch to previous buffer */
	switch_to_buffer(p->line, p->file, p->buffer);

	/* Restore variables */
	current_replace_list = p->replacing;
	quotation_mark = p->quotation_mark;
	cb_source_format = p->source_format;

	copy_stack = p->next;
	delete [] p->dname;
	delete p;
}

%%

/* Global functions */

void
pp_set_replace_list(cb_replace_list * list, const cob_u32_t is_pushpop)
{
	/* Handle REPLACE verb */
	if(!list) {
		/* REPLACE [LAST] OFF */
		if(!is_pushpop) {
			base_replace_list = NULL;
			return;
		}
		if(!base_replace_list) {
			return;
		}
		base_replace_list = base_replace_list->prev;
		return;
	}
	/* REPLACE [ALSO] ... */
	if(base_replace_list && is_pushpop) {
		list->last->next = base_replace_list;
		list->prev = base_replace_list;
	} else {
		list->prev = NULL;
	}
	base_replace_list = list;
}

int
ppopen(const char * name, cb_replace_list * replacing_list)
{
	if(ppin) {
		for(; newline_count > 0; newline_count--) {
			ungetc('\n', ppin);
		}
	}

	/* Open copy/source file */
#ifdef	__OS400__
	ppin = fopen(name, "r");
#else
	ppin = fopen(name, "rb");
#endif
	if(!ppin) {
		if(cb_source_file) {
			cb_error("%s: %s", name,
				  _("No such file or directory"));
		} else {
			fflush(stderr);
			fprintf(stderr, "%s: %s", name,
				 _("No such file or directory"));
			fflush(stderr);
			errorcount++;
		}
		return -1;
	}
#ifdef	_WIN32
	/* Check for BOM */
	unsigned char bom[4];
	if(fread(bom, 3, 1, ppin) == 1) {
		if(bom[0] != 0xEF || bom[1] != 0xBB || bom[2] != 0xBF) {
			rewind(ppin);
		}
	} else {
		rewind(ppin);
	}
#endif

	/* Preserve the current buffer */
	copy_info * p = new copy_info;
	p->file = cb_source_file;
	p->buffer = YY_CURRENT_BUFFER;

	/* Save variables */
	p->replacing = current_replace_list;
	p->line = cb_source_line;
	p->quotation_mark = quotation_mark;
	p->source_format = cb_source_format;

	p->next = copy_stack;
	copy_stack = p;

	/* Set replacing list */
	if(replacing_list) {
		if(current_replace_list) {
			replacing_list->last->next = current_replace_list;
			replacing_list->last = current_replace_list->last;
		}
		current_replace_list = replacing_list;
	}

	p->dname = cobc_strdup(name);
	for(char * s = p->dname; *s; ++s) {
		if(*s == '\\') {
			*s = '/';
		}
	}

	/* Switch to new buffer */
	switch_to_buffer(1, p->dname, yy_create_buffer(ppin, YY_BUF_SIZE));
	return 0;
}

int
ppcopy(const char * name, const char * lib, cb_replace_list * replace_list)
{
	const char		*s;
	/* Locate and open COPY file */
	if(lib) {
		snprintf(plexbuff1, (size_t)COB_SMALL_MAX, "%s/%s", lib, name);
		s = plexbuff1;
	} else {
		s = name;
	}

	/* Find the file */
	if(access(s, R_OK) == 0) {
		return ppopen(s, replace_list);
	}

	for(cb_text_list * el = cb_extension_list; el; el = el->next) {
		snprintf(plexbuff2, (size_t)COB_SMALL_MAX, "%s%s", s, el->text);
		if(access(plexbuff2, R_OK) == 0) {
			return ppopen(plexbuff2, replace_list);
		}
	}

	if(*s != '/') {
		for(cb_text_list * il = cb_include_list; il; il = il->next) {
			for(cb_text_list * el = cb_extension_list; el; el = el->next) {
				snprintf(plexbuff2, (size_t)COB_SMALL_MAX,
					  "%s/%s%s", il->text, name, el->text);
				if(access(plexbuff2, R_OK) == 0) {
					return ppopen(plexbuff2, replace_list);
				}
			}
		}
	}
	cb_error("%s: %s", name, _("No such file or directory"));
	return -1;
}

void
ppparse_error(const char * msg)
{
	cb_plex_error(newline_count, msg);
}

void
plex_clear_vars(void)
{
	/* Reset variables */
	plex_skip_input = 0;
	plex_nest_depth = 0;
	memset(plex_cond_stack, 0, sizeof(plex_cond_stack));
	requires_listing_line = 1;
	comment_allowed = 1;
}

void
plex_clear_all(void)
{
	if(plexbuff1) {
		delete [] plexbuff1;
		plexbuff1 = NULL;
	}
	if(plexbuff2) {
		delete [] plexbuff2;
		plexbuff2 = NULL;
	}
}

void
plex_call_destroy(void)
{
	(void)pplex_destroy();
}

void
plex_action_directive(const unsigned int cmdtype, const unsigned int is_true)
{
	unsigned int	n;

	/* Action IF/ELSE/END-IF/ELIF */
	switch(cmdtype) {
	case PLEX_ACT_IF:
		/* Push stack - First occurrence is dummy */
		if(++plex_nest_depth >= PLEX_COND_DEPTH) {
			cobc_abort_pr(_("Directive nest depth exceeded - %d"),
					PLEX_COND_DEPTH);
			COBC_ABORT();
		}
		plex_cond_stack[plex_nest_depth].cmd = 1U;
		/* Intersection with previous - first is always 0 */
		n = plex_cond_stack[plex_nest_depth - 1].skip | !is_true;
		plex_cond_stack[plex_nest_depth].skip = n;
		plex_cond_stack[plex_nest_depth].cond = is_true;
		plex_cond_stack[plex_nest_depth].line = cb_source_line;
		plex_skip_input = n;
		return;
	case PLEX_ACT_ELSE:
		/* Must have an associated IF/ELIF */
		if(!plex_nest_depth ||
		    plex_cond_stack[plex_nest_depth].cmd != 1) {
			cb_plex_error(newline_count,
				_("ELSE directive without matching IF/ELIF"));
			return;
		}
		plex_cond_stack[plex_nest_depth].cmd = 2U;
		/* Reverse any IF/ELIF condition */
		n = plex_cond_stack[plex_nest_depth].cond;
		plex_cond_stack[plex_nest_depth].skip = n;
		plex_cond_stack[plex_nest_depth].line = cb_source_line;
		/* Intersection with previous */
		plex_skip_input = plex_cond_stack[plex_nest_depth - 1].skip | n;
		return;
	case PLEX_ACT_END:
		/* Must have an associated IF/ELIF/ELSE */
		if(!plex_nest_depth ||
		    !plex_cond_stack[plex_nest_depth].cmd) {
			cb_plex_error(newline_count,
				_("END-IF directive without matching IF/ELIF/ELSE"));
			return;
		}
		plex_cond_stack[plex_nest_depth].cmd = 0;
		plex_cond_stack[plex_nest_depth].skip = 0;
		plex_cond_stack[plex_nest_depth].cond = 0;
		plex_cond_stack[plex_nest_depth].line = 0;
		/* Pop stack - set skip to previous */
		plex_nest_depth--;
		plex_skip_input = plex_cond_stack[plex_nest_depth].skip;
		return;
	case PLEX_ACT_ELIF:
		/* Must have an associated IF/ELIF */
		if(!plex_nest_depth ||
		    plex_cond_stack[plex_nest_depth].cmd != 1) {
			cb_plex_error(newline_count,
				_("ELIF directive without matching IF/ELIF"));
			return;
		}
		plex_cond_stack[plex_nest_depth].line = cb_source_line;
		if(plex_cond_stack[plex_nest_depth].cond) {
			/* Previous IF or one of previous ELIF was true */
			/* Set to skip */
			n = 1U;
		} else if(is_true) {
			/* Condition is true */
			plex_cond_stack[plex_nest_depth].cond = 1U;
			n = 0;
		} else {
			/* Set to skip */
			n = 1U;
		}
		plex_cond_stack[plex_nest_depth].skip = n;
		/* Intersection with previous */
		plex_skip_input = plex_cond_stack[plex_nest_depth - 1].skip | n;
		return;
	default:
		cobc_abort_pr(_("Invalid internal case - %u"),
				cmdtype);
		COBC_ABORT();
	}
}

/* Local functions */

static void
switch_to_buffer(const int line, const char * file, const YY_BUFFER_STATE buffer)
{
	/* Reset file/line */
	cb_source_line = line;
	cb_source_file = cobc_plex_strdup(file);
	fprintf(yyout, "#line %d \"%s\"\n", line, file);
	/* Switch buffer */
	yy_switch_to_buffer(buffer);
}

static int
ppinput(char * buff, const size_t max_size)
{
	char * bp;
	int i;
	int n;

	/* Read line(s) */

	size_t continuation = 0;
start:
	if(unlikely(buffer_overflow ||
		(newline_count + PPLEX_BUFF_LEN) >= max_size)) {
		if(need_continuation || continuation) {
			cb_plex_error(newline_count,
					_("Buffer overrun - Literal too long - Aborting"));
			return YY_NULL;
		}
		if(newline_count < max_size) {
			memset(buff, '\n', newline_count);
			buff[newline_count] = 0;
			int ipchar = (int)newline_count;
			newline_count = 0;
			buffer_overflow = 0;
			return ipchar;
		}
		buffer_overflow = 1;
		int ipchar = (int)(max_size - 1);
		memset(buff, '\n', (size_t)ipchar);
		buff[ipchar] = 0;
		newline_count -= ipchar;
		return ipchar;
	}
	size_t gotcr = 0;
	int ipchar = 0;
	for(n = 0; n < PPLEX_BUFF_LEN && ipchar != '\n';) {
		ipchar = getc(ppin);
		if(unlikely(ipchar == EOF)) {
			if(n > 0) {
				/* No end of line at end of file */
				break;
			}
			if(newline_count == 0) {
				return YY_NULL;
			}
			memset(buff, '\n', newline_count);
			buff[newline_count] = 0;
			ipchar = (int)newline_count;
			newline_count = 0;
			return ipchar;
		}
#ifndef	COB_EBCDIC_MACHINE
		if(unlikely(ipchar == 0x1A && !n)) {
			continue;
		}
#endif
		if(unlikely(gotcr)) {
			gotcr = 0;
			if(ipchar != '\n') {
				buff[n++] = '\r';
			}
		}
		if(unlikely(ipchar == '\r')) {
			gotcr = 1;
			continue;
		}
		if(unlikely(ipchar == '\t')) {
			buff[n++] = ' ';
			while(n % cb_tab_width != 0) {
				buff[n++] = ' ';
			}
			/* Prevent heap smash */
			if(n > PPLEX_BUFF_LEN - 16) {
				break;
			}
			continue;
		}
		buff[n++] = (char)ipchar;
	}

	if(buff[n - 1] != '\n') {
		cb_plex_warning(newline_count,
				 _("Line not terminated by a newline"));
		buff[n++] = '\n';
	}
	buff[n] = 0;

	if(cb_source_format == CB_FORMAT_FIXED) {
		if(n < 8) {
			/* Line too short */
			newline_count++;
			goto start;
		}

		if(cb_flag_mfcomment) {
			if(buff[0] == '*' || buff[0] == '/') {
				newline_count++;
				goto start;
			}
		}

		/* Check if text is longer than cb_text_column */
		if(n > cb_text_column + 1) {
			/* Show warning if it is not whitespace */
			if(cb_warn_column_overflow) {
				for(int coln = cb_text_column; coln < n; ++coln) {
					if(buff[coln] != ' ' && buff[coln] != '\n') {
						cb_plex_warning(newline_count,
								 _("Source text after column %d"),
							    cb_text_column);
						break;
					}
				}
			}
			/* Remove it */
			buff[cb_text_column] = '\n';
			buff[cb_text_column + 1] = 0;
			n = cb_text_column + 1;
		}

		memset(buff, ' ', (size_t)6);
		/* Note we allow directive lines to start at column 7 */
		bp = &buff[6];
	} else {
		bp = buff;
	}

	/* Check for directives/floating comment */
	ipchar = 0;
	for(; *bp; bp++) {
		if(*bp != ' ') {
			if(*bp == '$' ||(*bp == '>' && bp[1] == '>')) {
				/* Directive */
				ipchar = 1;
#if	1 /* RXWRXW - Float comment */
			} else if(*bp == '*' && bp[1] == '>') {
				/* Floating comment line */
				newline_count++;
				goto start;
#endif
			}
			break;
		}
	}
	if(ipchar) {
		/* Directive - pass complete line with NL to ppparse */
		if(newline_count) {
			/* Move including NL and NULL byte */
			memmove(buff + newline_count, buff, (size_t)(n + 1));
			memset(buff, '\n', newline_count);
			n += (int) newline_count;
			newline_count = 0;
		}
		return n;
	}

	if(plex_skip_input) {
		/* Skipping input */
		newline_count++;
		goto start;
	}

	/* Return when free format */
	if(cb_source_format != CB_FORMAT_FIXED) {
		if(buff[0] == '*' || buff[0] == '/') {
			newline_count++;
			goto start;
		}
		within_comment = 0;
		if(newline_count) {
			memmove(buff + newline_count, buff, (size_t)(n + 1));
			memset(buff, '\n', newline_count);
			n += (int) newline_count;
			newline_count = 0;
		}
		return n;
	}

	/* Fixed format */

	/* Check the indicator(column 7) */
	switch(buff[6]) {
	case ' ':
		break;
	case '-':
		if(unlikely(within_comment)) {
			cb_plex_error(newline_count,
					_("Invalid continuation in comment entry"));
			newline_count++;
			goto start;
		}
		continuation = 1;
		break;
	case 'd':
	case 'D':
		/* Debugging line */
		if(cb_flag_debugging_line) {
			break;
		}
		newline_count++;
		goto start;
	case '*':
	case '/':
		/* Comment line */
		newline_count++;
		goto start;
	default:
		/* Invalid indicator */
		cb_plex_error(newline_count,
				_("Invalid indicator '%c' at column 7"), buff[6]);
		newline_count++;
		return YY_NULL;
	}

	/* Skip comments that follow after AUTHORS, etc. */
	if(unlikely(within_comment)) {
		/* Check all of "Area A" */
		for(ipchar = 7; ipchar <(n - 1) && ipchar < 11; ++ipchar) {
			if(buff[ipchar] != ' ') {
				ipchar = 0;
				break;
			}
		}
		if(ipchar) {
			newline_count++;
			goto start;
		}
		within_comment = 0;
	}

	/* Skip blank lines */
	for(i = 7; buff[i] == ' '; ++i) {
		;
	}

	if(buff[i] == '\n') {
		newline_count++;
		goto start;
	}

	buff[6] = ' ';
	bp = buff + 7;

	if(unlikely(continuation)) {
		/* Line continuation */
		need_continuation = 0;
		for(; *bp == ' '; ++bp) {
			;
		}
		/* Validate concatenation */
		if(consecutive_quotation) {
			if(bp[0] == quotation_mark && bp[1] == quotation_mark) {
				bp++;
			} else {
				cb_plex_error(newline_count,
						_("Invalid line continuation"));
				return YY_NULL;
			}
			quotation_mark = 0;
			consecutive_quotation = 0;
		} else if(quotation_mark) {
			/* Literal concatenation */
			if(*bp == quotation_mark) {
				bp++;
			} else {
				cb_plex_error(newline_count,
						_("Invalid line continuation"));
				return YY_NULL;
			}
		}
	} else {
		/* Normal line */
		if(need_continuation) {
			cb_plex_error(newline_count,
					_("Continuation character expected"));
			need_continuation = 0;
		}
		quotation_mark = 0;
		consecutive_quotation = 0;
	}

	/* Check if string literal is to be continued */
	for(i = (int)(bp - buff); buff[i] != '\n'; ++i) {
		/* Pick up floating comment and force loop exit */
		if(buff[i] == '*' && buff[i + 1] == '>' && !quotation_mark) {
			/* Set to null, 'i' is predecremented further below */
#if	1	/* RXWRXW - Float comment */
			buff[i] = 0;
			break;
#endif
		} else if(buff[i] == '\'' || buff[i] == '"') {
			if(quotation_mark == 0) {
				/* Literal start */
				quotation_mark = buff[i];
			} else if(quotation_mark == buff[i]) {
				if(i == cb_text_column - 1) {
					/* Consecutive quotation */
					consecutive_quotation = 1;
				} else {
					/* Literal end */
					quotation_mark = 0;
				}
			}
		}
	}

	if(unlikely(quotation_mark)) {
		/* Expecting continuation */
		if(!consecutive_quotation) {
			need_continuation = 1;
		}
		for(; i < cb_text_column;) {
			buff[i++] = ' ';
		}
		buff[i] = 0;
	} else {
		/* Truncate trailing spaces, including the newline */
		for(i--; i >= 0 && buff[i] == ' '; i--) {
			;
		}
		if(i < 0) {
			/* Empty line after removing floating comment */
			newline_count++;
			goto start;
		}
		if(buff[i] == '\'' || buff[i] == '\"') {
			buff[++i] = ' ';
		}
		buff[i + 1] = 0;
	}

	if(unlikely(continuation)) {
		gotcr = strlen(bp);
		memmove(buff, bp, gotcr + 1);
		newline_count++;
	} else {
		/* Insert newlines at the start of the buffer */
		gotcr = strlen(buff);
		if(newline_count) {
			memmove(buff + newline_count, buff, gotcr + 1);
			memset(buff, '\n', newline_count);
			gotcr += newline_count;
		}
		newline_count = 1;
	}
	return(int)gotcr;
}

static cb_text_list *
pp_text_list_add(cb_text_list * list, const char * text, const size_t size)
{
	cb_text_list * p = (cb_text_list *) cobc_plex_malloc(sizeof(cb_text_list));
	void * tp = cobc_plex_malloc(size + 1);
	memcpy(tp, text, size);
	p->text = (const char *) tp;
	if(!list) {
		p->last = p;
		return p;
	}
	list->last->next = p;
	list->last = p;
	return list;
}

static void
ppecho(const char * text, const cob_u32_t alt_space, const size_t textlen)
{
	cb_replace_list		*save_ptr;
	const char			*s;

	/* Check for replacement text before outputting */
	if(alt_space) {
		s = yytext;
	} else {
		s = text;
	}

	if(text_queue == NULL &&(text[0] == ' ' || text[0] == '\n')) {
		/* No replacement */
		fwrite(text, (size_t)textlen, (size_t)1, ppout);
		if(cb_listing_file) {
			check_listing(s, 0);
		}
		return;
	}
	if(!current_replace_list && !base_replace_list) {
		/* Ouput queue */
		for(; text_queue; text_queue = text_queue->next) {
			fputs(text_queue->text, ppout);
		}
		fwrite(text, (size_t)textlen, (size_t)1, ppout);
		if(cb_listing_file) {
			check_listing(s, 0);
		}
		return;
	}
	if(!current_replace_list) {
		current_replace_list = base_replace_list;
		save_ptr = NULL;
	} else {
		current_replace_list->last->next = base_replace_list;
		save_ptr = current_replace_list->last;
	}

	/* Do replacement */
	text_queue = pp_text_list_add(text_queue, text, (size_t)textlen);

	cb_text_list * save_queue = NULL;
	size_t size = 0;
	size_t size2 = 0;
	for(cb_replace_list * r = current_replace_list; r; r = r->next) {
		cb_text_list * queue = text_queue;
		const cb_text_list	*lno;
		/* The LEADING/TRAILING code looks peculiar as we use */
		/* variables after breaking out of the loop BUT */
		/* ppparse.y guarantees that we have only one token */
		/* and therefore only one iteration of this loop */
		for(lno = r->old_text; lno; lno = lno->next) {
			if(lno->text[0] == ' ' || lno->text[0] == '\n') {
				continue;
			}
			while(queue &&(queue->text[0] == ' ' ||
			       queue->text[0] == '\n')) {
				queue = queue->next;
			}
			if(queue == NULL) {
				/* Partial match */
				if(!save_ptr) {
					current_replace_list = NULL;
				} else {
					save_ptr->next = NULL;
				}
				return;
			}
			if(r->lead_trail == CB_REPLACE_LEADING) {
				/* Check leading text */
				size = strlen(lno->text);
				if(strncasecmp(lno->text, queue->text, size)) {
					/* No match */
					break;
				}
				save_queue = queue;
			} else if(r->lead_trail == CB_REPLACE_TRAILING) {
				/* Check trailing text */
				size = strlen(lno->text);
				size2 = strlen(queue->text);
				if(size2 < size) {
					/* No match */
					break;
				}
				size2 -= size;
				if(strncasecmp(lno->text, queue->text + size2, size)) {
					/* No match */
					break;
				}
				save_queue = queue;
			} else if(strcasecmp(lno->text, queue->text)) {
				/* No match */
				break;
			}
			queue = queue->next;
		}
		if(lno == NULL) {
			/* Match */
			if(r->lead_trail == CB_REPLACE_TRAILING) {
				/* Non-matched part of original text */
				fprintf(ppout, "%*.*s", (int)size2, (int)size2,
					 save_queue->text);
				if(cb_listing_file) {
					char * temp_ptr = cobc_strdup(save_queue->text);
					*(temp_ptr + size2) = 0;
					check_listing(temp_ptr, 0);
					delete [] temp_ptr;
				}
			}
			for(lno = r->new_text; lno; lno = lno->next) {
				fputs(lno->text, ppout);
				if(cb_listing_file) {
					check_listing(lno->text, 0);
				}
			}
			if(r->lead_trail == CB_REPLACE_LEADING) {
				/* Non-matched part of original text */
				fputs(save_queue->text + size, ppout);
				if(cb_listing_file) {
					check_listing(save_queue->text + size, 0);
				}
			}
			text_queue = queue;
			continue;
		}
	}

	/* No match */
	for(; text_queue; text_queue = text_queue->next) {
		fputs(text_queue->text, ppout);
		if(cb_listing_file) {
			check_listing(text_queue->text, 0);
		}
	}
	if(!save_ptr) {
		current_replace_list = NULL;
	} else {
		save_ptr->next = NULL;
	}
}

static void
skip_to_eol(void)
{
	int	c;

	/* Skip bytes to end of line */
	while((c = yyinput()) != EOF) {
		if(c == '\n') {
			break;
		}
	}
	if(c != EOF) {
		unput(c);
	}
}

static void
display_to_eol(void)
{
	int	c;

	while((c = yyinput()) != EOF) {
		if(c == '\n') {
			break;
		}
		if(!plex_skip_input) {
			putchar(c);
		}
	}
	if(!plex_skip_input) {
		putchar('\n');
	}
	if(c != EOF) {
		unput(c);
	}
}

static void
check_comments(const char * keyword, const char * text)
{
	/* Treated as comments when in Identification Division */
	if(comment_allowed) {
		cb_verify(cb_author_paragraph, keyword);
		/* Skip comments until the end of line */
		within_comment = 1;
		skip_to_eol();
	} else {
		ppecho(text, 0, yyleng);
	}
}

static void
check_listing(const char * text, const unsigned int comment)
{
	const char	*s;
	char		c;

	/* Check for listing */
	if(!cb_listing_file) {
		/* Nothing to do */
		return;
	}
	if(!text) {
		return;
	}
	if(cobc_gen_listing > 1) {
		/* Passed to cobxref */
		fputs(text, cb_listing_file);
		return;
	}
	if(comment) {
		c = '*';
	} else {
		c = ' ';
	}

	if(requires_listing_line) {
		if(requires_new_line) {
			requires_new_line = 0;
			putc('\n', cb_listing_file);
		}
		fprintf(cb_listing_file, "%6d%c", ++listing_line, c);
	}

	if(requires_listing_line && cb_source_format == CB_FORMAT_FIXED &&
	    strlen(text) > 6) {
		s = &text[6];
	} else {
		s = text;
	}
	fputs(s, cb_listing_file);
	if(strchr(text, '\n')) {
		requires_listing_line = 1;
	} else {
		requires_listing_line = 0;
	}
}
