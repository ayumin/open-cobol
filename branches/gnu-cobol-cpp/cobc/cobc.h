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


#ifndef CB_COBC_H
#define CB_COBC_H

#include <stdio.h>
#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef	HAVE_STRINGS_H
#include <strings.h>
#endif

#include "libcob.h"

#ifdef	ENABLE_NLS
#include "lib/gettext.h"
#define _(s)		gettext(s)
#define N_(s)		gettext_noop(s)
#else
#define _(s)		s
#define N_(s)		s
#endif

/* Defines for access() */
#ifndef	F_OK
#define	F_OK		0
#endif

#ifndef	X_OK
#define	X_OK		1
#endif

#ifndef	W_OK
#define	W_OK		2
#endif

#ifndef	R_OK
#define	R_OK		4
#endif

#define COBC_ABORT()			cobc_abort(__FILE__, __LINE__)
#define COBC_DUMB_ABORT()		cobc_dumb_abort(__FILE__, __LINE__)

/* Source format defines */
#define CB_FORMAT_FIXED			0
#define CB_FORMAT_FREE			1

/* COPY extended syntax defines */
#define CB_REPLACE_LEADING		1U
#define CB_REPLACE_TRAILING		2U

/* Stringify macros */
#define CB_STRINGIFY(s)			#s
#define CB_XSTRINGIFY(s)		CB_STRINGIFY(s)

/* ASSIGN clause interpretation */
#define CB_ASSIGN_MF			0	/* Micro Focus compatibility */
#define CB_ASSIGN_IBM			1U	/* IBM compatibility */
#define CB_ASSIGN_COBOL2002		2U	/* COBOL 2002 standard */

/* COMP/BINARY byte order */
#define CB_BYTEORDER_BIG_ENDIAN	0
#define CB_BYTEORDER_NATIVE		1U

/* Binary field sizes */
#define CB_BINARY_SIZE_1_2_4_8	0	/* 1,2,4,8 bytes */
#define CB_BINARY_SIZE_1__8		1U	/* 1,2,3,4,5,6,7,8 bytes */
#define CB_BINARY_SIZE_2_4_8	2U	/* 2,4,8 bytes */

/* Flex directive actions */
#define PLEX_ACT_IF			0
#define PLEX_ACT_ELSE			1U
#define PLEX_ACT_END			2U
#define PLEX_ACT_ELIF			3U

/* Flex value types */
#define PLEX_DEF_NONE			0
#define PLEX_DEF_LIT			1U
#define PLEX_DEF_NUM			2U
#define PLEX_DEF_DEL			3U

/* Context sensitive keyword defines(trigger words) */
#define	CB_CS_ACCEPT		(1U << 0)
#define	CB_CS_ALPHABET		(1U << 1)
#define	CB_CS_ASSIGN		(1U << 2)
#define	CB_CS_CALL			(1U << 3)
#define	CB_CS_CONSTANT		(1U << 4)
#define	CB_CS_DATE			(1U << 5)
#define	CB_CS_DAY			(1U << 6)
#define	CB_CS_DISPLAY		(1U << 7)
#define	CB_CS_ERASE			(1U << 8)
#define	CB_CS_EXIT			(1U << 9)
#define	CB_CS_FROM			(1U << 10)
#define	CB_CS_PROGRAM_ID	(1U << 11)
#define	CB_CS_ROUNDED		(1U << 12)
#define	CB_CS_SET			(1U << 13)
#define	CB_CS_STOP			(1U << 14)
#define	CB_CS_WITH			(1U << 15)

/* Operand operation type */
enum cb_operation_type {
	CB_OPERATION_READ = 0,
	CB_OPERATION_WRITE,
	CB_OPERATION_ASSIGN
};

/* Config dialect support types */
enum cb_support {
	CB_OK = 0,
	CB_WARNING,
	CB_ARCHAIC,
	CB_OBSOLETE,
	CB_SKIP,
	CB_IGNORE,
	CB_ERROR,
	CB_UNCONFORMABLE
};

/* Config dialect support types */
enum cb_std_def {
	CB_STD_OC = 0,
	CB_STD_MF,
	CB_STD_IBM,
	CB_STD_MVS,
	CB_STD_BS2000,
	CB_STD_85,
	CB_STD_2002
};

/* Generic text list structure */
struct cb_text_list {
	cb_text_list *	next;			/* next pointer */
	cb_text_list *	last;
	const char *	text;
};

/* Generic replace list structure */
struct cb_replace_list {
	cb_replace_list *	next;			/* next pointer */
	cb_replace_list *	last;
	cb_replace_list *	prev;
	const cb_text_list * old_text;
	const cb_text_list * new_text;
	unsigned int		lead_trail;
};

/* Generic define list structure */
struct cb_define_struct {
	cb_define_struct *	next;			/* next pointer */
	cb_define_struct *	last;
	char *				name;
	char *				value;
	unsigned int		deftype;
	int					sign;
	int					int_part;
	int					dec_part;
};

/* Structure for extended filenames */
struct local_filename {
	local_filename *	next;			/* next pointer */
	char *				local_name;
	FILE *				local_fp;
};

/* Structure for filename */
struct filename {
	filename *		next;
	const char *	source;				/* foo.cob (path from command line) */
	const char *	preprocess;			/* foo.i (full path) */
	const char *	translate;			/* foo.cpp (full path) */
	const char *	trstorage;			/* foo.cpp.h (full path) */
	const char *	object;				/* foo.o */
	const char *	demangle_source;	/* foo */
	const char *	listing_file;		/* foo.lst */
	local_filename * localfile;			/* foo.cpp.l[n].h */
	size_t			translate_len;		/* strlen translate */
	size_t			object_len;			/* strlen object */
	unsigned int	need_preprocess;	/* Needs preprocess */
	unsigned int	need_translate;		/* Needs parse */
	unsigned int	need_assemble;		/* Needs C compile */
	int				has_error;			/* Error detected */
};

/* Exception structure */
struct cb_exception {
	const char *	name;			/* Exception name */
	int				code;			/* Exception code */
	int				enable;			/* If turned on */
};

/* Structure for reserved words that have been reverted */
struct noreserve {
	noreserve *	next;			/* next pointer */
	char *		noresword;
};

/* Basic memory structure */
struct cobc_mem_struct {
	cobc_mem_struct *	next;			/* next pointer */
	void *				memptr;
	size_t				memlen;
};


extern int			cb_source_format;

extern cb_exception	cb_exception_table[];

#define CB_EXCEPTION_NAME(id)	cb_exception_table[id].name
#define CB_EXCEPTION_CODE(id)	cb_exception_table[id].code
#define CB_EXCEPTION_ENABLE(id)	cb_exception_table[id].enable

#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_NQ
#define	CB_FLAG(var,pdok,name,doc)		extern int var;
#define CB_FLAG_RQ(var,pdok,name,def,opt,doc)	extern int var;
#define CB_FLAG_NQ(pdok,name,opt,doc)
#include "flag.def"
#undef	CB_FLAG
#undef	CB_FLAG_RQ
#undef	CB_FLAG_nQ

#undef	CB_WARNDEF
#undef	CB_NOWARNDEF
#define	CB_WARNDEF(var,name,doc)	extern int var;
#define	CB_NOWARNDEF(var,name,doc)	extern int var;
#include "warning.def"
#undef	CB_WARNDEF
#undef	CB_NOWARNDEF

#undef	CB_OPTIM_DEF
#define	CB_OPTIM_DEF(x)			x,
enum cb_optim {
	COB_OPTIM_MIN = 0,
#include "codeoptim.def"
	COB_OPTIM_MAX
};
#undef	CB_OPTIM_DEF

extern int			cb_id;
extern int			cb_attr_id;
extern int			cb_literal_id;
extern int			cb_field_id;
extern int			cobc_flag_main;
extern int			cb_flag_functions_all;
extern int			cb_flag_main;
extern int			cobc_wants_debug;

extern int			errorcount;
extern int			warningcount;
extern int			warningopt;
extern int			no_physical_cancel;
extern cob_u32_t		optimize_defs[];

extern char *		cb_oc_build_stamp;
extern const char *	cb_source_file;
extern int			cb_source_line;

extern const char *	cob_config_dir;

extern unsigned int	cobc_gen_listing;

extern const char *	demangle_name;
extern FILE *		cb_storage_file;
extern const char *	cb_storage_file_name;

extern char **		cb_saveargv;
extern int			cb_saveargc;

extern FILE *		cb_listing_file;
extern cb_text_list * cb_include_list;
extern cb_text_list * cb_intrinsic_list;
extern cb_text_list * cb_extension_list;
extern cb_text_list * cb_static_call_list;
extern cb_text_list * cb_early_exit_list;

extern struct cb_program * current_program;
extern struct cb_statement * current_statement;
extern struct cb_label *	current_section;
extern struct cb_label *	current_paragraph;
extern int			functions_are_all;

/* Functions */

// cobc.cpp

extern noreserve *	cobc_nores_base;

char *			cobc_strdup(const char *);

void *			cobc_main_malloc(const size_t);
char *			cobc_main_strdup(const char *);
void *			cobc_main_realloc(void *, const size_t);
void			cobc_main_free(void *);

void *			cobc_parse_malloc(const size_t);
char *			cobc_parse_strdup(const char *);
void			cobc_parse_free(void *);

void *			cobc_plex_malloc(const size_t);
char *			cobc_plex_strdup(const char *);

void *			cobc_check_string(const char *);
void			cobc_abort_pr(const char *, ...) COB_A_FORMAT12;

DECLNORET void	cobc_abort(const char *, const int) COB_A_NORETURN;
DECLNORET void	cobc_too_many_errors(void) COB_A_NORETURN;
void			cobc_dumb_abort(const char *, const int);

size_t	cobc_check_valid_name(const char *, const unsigned int);

/* config.c */

#undef	CB_CONFIG_ANY
#undef	CB_CONFIG_INT
#undef	CB_CONFIG_STRING
#undef	CB_CONFIG_BOOLEAN
#undef	CB_CONFIG_SUPPORT

#define	CB_CONFIG_ANY(type,var,name)	extern type var;
#define	CB_CONFIG_INT(var,name)		extern int var;
#define	CB_CONFIG_STRING(var,name)	extern const char *var;
#define	CB_CONFIG_BOOLEAN(var,name)	extern int var;
#define	CB_CONFIG_SUPPORT(var,name)	extern enum cb_support var;

#include "config.def"

#undef	CB_CONFIG_ANY
#undef	CB_CONFIG_INT
#undef	CB_CONFIG_STRING
#undef	CB_CONFIG_BOOLEAN
#undef	CB_CONFIG_SUPPORT

int				cb_load_std(const char *);
int				cb_load_conf(const char *, const int, const int);

/* Initialization routines in scanner.l, typeck.c, reserved.c */
void			cobc_init_scanner(void);
void			cobc_init_typeck(void);
void			cobc_init_reserved(void);

/* preprocessor(in pplex.l, ppparse.y) */
#if	!defined(COB_IN_SCANNER ) && !defined(COB_IN_PPLEX)
extern FILE *	ppin;
extern FILE *	ppout;
int				pplex(void);
#endif

int				ppparse(void);
int				ppopen(const char *, cb_replace_list *);
int				ppcopy(const char *, const char *, cb_replace_list *);
void			pp_set_replace_list(cb_replace_list *, const cob_u32_t);
void			ppparse_error(const char *);
void			ppparse_clear_vars(const cb_define_struct *);
void			plex_clear_vars(void);
void			plex_clear_all(void);
void			plex_call_destroy(void);
void			plex_action_directive(const unsigned int, const unsigned int);

// parser(in scanner.l, parser.y)
extern char *	cobc_glob_line;

#if	!defined(COB_IN_SCANNER ) && !defined(COB_IN_PPLEX) && !defined(COB_IN_PPPARSE)
extern FILE *	yyin;
extern FILE *	yyout;
#endif

int				yylex(void);
int				yyparse(void);
extern void		ylex_clear_all(void);
extern void		ylex_call_destroy(void);

// typeck.cpp
extern size_t	suppress_warn;

// codeoptim.cpp
void			cob_gen_optim(const enum cb_optim);

// codegen.cpp
unsigned int	chk_field_variable_address(struct cb_field *);

// naming.cpp
void			externalize_tree(struct cb_field **);

// error.cpp
void			cb_warning(const char *, ...) COB_A_FORMAT12;
void			cb_error(const char *, ...) COB_A_FORMAT12;
void			cb_plex_warning(const size_t, const char *, ...) COB_A_FORMAT23;
void			cb_plex_error(const size_t, const char *, ...) COB_A_FORMAT23;
unsigned int	cb_verify(const enum cb_support, const char *);

/////////////////////////// SKA DEBUG //////////////////////
void skadbg(const char * fmt, ...);
/////////////////////////// SKA DEBUG //////////////////////
#endif /* CB_COBC_H */
