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
#define CB_BYTEORDER_BIG_ENDIAN		0
#define CB_BYTEORDER_NATIVE		1U

/* Binary field sizes */
#define CB_BINARY_SIZE_1_2_4_8		0	/* 1,2,4,8 bytes */
#define CB_BINARY_SIZE_1__8		1U	/* 1,2,3,4,5,6,7,8 bytes */
#define CB_BINARY_SIZE_2_4_8		2U	/* 2,4,8 bytes */

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

/* Context sensitive keyword defines (trigger words) */
#define	CB_CS_ACCEPT			(1U << 0)
#define	CB_CS_ALPHABET			(1U << 1)
#define	CB_CS_ASSIGN			(1U << 2)
#define	CB_CS_CALL			(1U << 3)
#define	CB_CS_CONSTANT			(1U << 4)
#define	CB_CS_DATE			(1U << 5)
#define	CB_CS_DAY			(1U << 6)
#define	CB_CS_DISPLAY			(1U << 7)
#define	CB_CS_ERASE			(1U << 8)
#define	CB_CS_EXIT			(1U << 9)
#define	CB_CS_FROM			(1U << 10)
#define	CB_CS_PROGRAM_ID		(1U << 11)
#define	CB_CS_ROUNDED			(1U << 12)
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
	struct cb_text_list	*next;			/* next pointer */
	struct cb_text_list	*last;
	const char		*text;
};

/* Generic replace list structure */
struct cb_replace_list {
	struct cb_replace_list		*next;			/* next pointer */
	struct cb_replace_list		*last;
	struct cb_replace_list		*prev;
	const struct cb_text_list	*old_text;
	const struct cb_text_list	*new_text;
	unsigned int			lead_trail;
};

/* Generic define list structure */
struct cb_define_struct {
	struct cb_define_struct	*next;			/* next pointer */
	struct cb_define_struct	*last;
	char			*name;
	char			*value;
	unsigned int		deftype;
	int			sign;
	int			int_part;
	int			dec_part;
};

/* Structure for extended filenames */
struct local_filename {
	struct local_filename	*next;			/* next pointer */
	char			*local_name;
	FILE			*local_fp;
};

/* Structure for filename */
struct filename {
	struct filename		*next;
	const char		*source;		/* foo.cob (path from command line) */
	const char		*preprocess;		/* foo.i (full path) */
	const char		*translate;		/* foo.c (full path) */
	const char		*trstorage;		/* foo.c.h (full path) */
	const char		*object;		/* foo.o (full path) */
	const char		*demangle_source;	/* foo */
	const char		*listing_file;		/* foo.lst */
	struct local_filename	*localfile;		/* foo.c.l[n].h */
	size_t			translate_len;		/* strlen translate */
	size_t			object_len;		/* strlen object */
	unsigned int		need_preprocess;	/* Needs preprocess */
	unsigned int		need_translate;		/* Needs parse */
	unsigned int		need_assemble;		/* Needs C compile */
	int			has_error;		/* Error detected */
};

/* Exception structure */
struct cb_exception {
	const char	*name;			/* Exception name */
	const int	code;			/* Exception code */
	int		enable;			/* If turned on */
};

/* Structure for reserved words that have been reverted */
struct noreserve {
	struct	noreserve	*next;			/* next pointer */
	char			*noresword;
};

/* Basic memory structure */
struct cobc_mem_struct {
	struct	cobc_mem_struct	*next;			/* next pointer */
	void			*memptr;
	size_t			memlen;
};


extern int			cb_source_format;

extern struct cb_exception	cb_exception_table[];

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

extern char			*cb_oc_build_stamp;
extern const char		*cb_source_file;
extern int			cb_source_line;

extern const char		*cob_config_dir;

extern unsigned int		cobc_gen_listing;

extern const char		*demangle_name;
extern FILE			*cb_storage_file;
extern const char		*cb_storage_file_name;

extern char			**cb_saveargv;
extern int			cb_saveargc;

extern FILE			*cb_listing_file;
extern struct cb_text_list	*cb_include_list;
extern struct cb_text_list	*cb_intrinsic_list;
extern struct cb_text_list	*cb_extension_list;
extern struct cb_text_list	*cb_static_call_list;
extern struct cb_text_list	*cb_early_exit_list;

extern struct cb_program	*current_program;
extern struct cb_statement	*current_statement;
extern struct cb_label		*current_section;
extern struct cb_label		*current_paragraph;
extern int			functions_are_all;

/* Functions */

/* cobc.c */

extern struct noreserve		*cobc_nores_base;

extern void			*cobc_malloc (const size_t);
extern void			cobc_free (void *);
extern void			*cobc_strdup (const char *);
extern void			*cobc_realloc (void *, const size_t);

extern void			*cobc_main_malloc (const size_t);
extern void			*cobc_main_strdup (const char *);
extern void			*cobc_main_realloc (void *, const size_t);
extern void			cobc_main_free (void *);

extern void			*cobc_parse_malloc (const size_t);
extern void			*cobc_parse_strdup (const char *);
extern void			*cobc_parse_realloc (void *, const size_t);
extern void			cobc_parse_free (void *);

extern void			*cobc_plex_malloc (const size_t);
extern void			*cobc_plex_strdup (const char *);

extern void			*cobc_check_string (const char *);
extern void			cobc_abort_pr (const char *, ...) COB_A_FORMAT12;

DECLNORET extern void		cobc_abort (const char *,
					    const int) COB_A_NORETURN;
DECLNORET extern void		cobc_too_many_errors (void) COB_A_NORETURN;
DECLNORET extern void			cobc_dumb_abort (const char *, const int);

extern size_t			cobc_check_valid_name (const char *,
						       const unsigned int);

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

extern int		cb_load_std (const char *);
extern int		cb_config_entry (char *, const char *, const int);
extern int		cb_load_conf (const char *, const int, const int);

#ifndef	HAVE_DESIGNATED_INITS
/* Initialization routines in scanner.l, typeck.c, reserved.c */
extern void		cobc_init_scanner (void);
extern void		cobc_init_typeck (void);
extern void		cobc_init_reserved (void);
#endif

/* preprocessor (in pplex.l, ppparse.y) */
#if	!defined (COB_IN_SCANNER ) && !defined (COB_IN_PPLEX)
extern FILE		*ppin;
extern FILE		*ppout;
extern int		pplex (void);
#endif

#ifndef	COB_IN_PPPARSE
extern int		ppparse (void);
#endif

extern int		ppopen (const char *, struct cb_replace_list *);
extern int		ppcopy (const char *, const char *,
				struct cb_replace_list *);
extern void		pp_set_replace_list (struct cb_replace_list *,
					     const cob_u32_t);
extern void		ppparse_error (const char *);
extern void		ppparse_clear_vars (const struct cb_define_struct *);
extern void		plex_clear_vars (void);
extern void		plex_clear_all (void);
extern void		plex_call_destroy (void);
extern void		plex_action_directive (const unsigned int,
					       const unsigned int);

/* parser (in scanner.l, parser.y) */
extern char		*cobc_glob_line;

#if	!defined (COB_IN_SCANNER ) && !defined (COB_IN_PPLEX) && \
	!defined (COB_IN_PPPARSE)
extern FILE		*yyin;
extern FILE		*yyout;
extern int		yylex (void);
#endif

#if	!defined (COB_IN_PPPARSE) && !defined (COB_IN_PARSER)
extern int		yyparse (void);
#endif

extern void		ylex_clear_all (void);
extern void		ylex_call_destroy (void);

/* typeck.c */
extern size_t		suppress_warn;

/* codeoptim.c */
extern void		cob_gen_optim (const enum cb_optim);

/* error.c */
#define CB_MSG_STYLE_GCC	0
#define CB_MSG_STYLE_MSC	1U

extern size_t		cb_msg_style;

extern void		cb_warning (const char *, ...) COB_A_FORMAT12;
extern void		cb_error (const char *, ...) COB_A_FORMAT12;
extern void		cb_plex_warning (const size_t,
					 const char *, ...) COB_A_FORMAT23;
extern void		cb_plex_error (const size_t,
				       const char *, ...) COB_A_FORMAT23;
extern void		configuration_error (const char *,
					 const int, const char *, ...) COB_A_FORMAT34;

extern unsigned int	cb_verify (const enum cb_support, const char *);

#endif /* CB_COBC_H */
