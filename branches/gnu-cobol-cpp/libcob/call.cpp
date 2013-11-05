/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While
   Copyright (C) 2013 Sergey Kashyrin

   This file is part of GNU Cobol C++.

   The GNU Cobol C++ runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol C++ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "config.h"
#include "defaults.h"

#ifndef	_GNU_SOURCE
#define _GNU_SOURCE	1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#endif

/*	NOTE - The following variable should be uncommented when
	it is known that dlopen(NULL) is borked.
	This is known to be true for some PA-RISC HP-UX 11.11 systems.
	This is fixed with HP patch PHSS_28871.(There are newer but this
	fixes dlopen/dlsym problems)
*/
/* #define COB_BORKED_DLOPEN */

#ifdef	_WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static HMODULE
lt_dlopen(const char * x)
{
	if(x == NULL) {
		return GetModuleHandle(NULL);
	}
	return LoadLibrary(x);
}

static void *
lt_dlsym(HMODULE hmod, const char * p)
{
	union {
		FARPROC	modaddr;
		void *	voidptr;
	} modun;

	modun.modaddr = GetProcAddress(hmod, p);
	return modun.voidptr;
}

#if	0	/* RXWRXW - Win dlsym */
#define lt_dlsym(x,y)	GetProcAddress(x, y)
#endif

#define lt_dlclose(x)	FreeLibrary(x)
#define	lt_dlinit()
#define	lt_dlexit()
#define lt_dlhandle	HMODULE

#if	0	/* RXWRXW - dlerror */
static char	errbuf[64];
static char *
lt_dlerror(void)
{
	sprintf(errbuf, _("LoadLibrary/GetProcAddress error %d"), (int)GetLastError());
	return errbuf;
}
#endif

#elif	defined(USE_LIBDL)

#include <dlfcn.h>

#define lt_dlopen(x)	dlopen(x, RTLD_LAZY | RTLD_GLOBAL)
#define lt_dlsym(x,y)	dlsym(x, y)
#define lt_dlclose(x)	dlclose(x)
#define lt_dlerror()	dlerror()
#define	lt_dlinit()
#define	lt_dlexit()
#define lt_dlhandle	void *

#else

#include <ltdl.h>

#endif

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

#ifdef	_MSC_VER
#define PATHSEPC ';'
#define PATHSEPS ";"
#else
#define PATHSEPC ':'
#define PATHSEPS ":"
#endif

#ifndef	_WIN32
#define SLASH_INT	'/'
#define SLASH_STR	"/"
#else
#define SLASH_INT	'\\'
#define SLASH_STR	"\\"
#endif

#define	COB_MAX_COBCALL_PARMS	16
#define	CALL_BUFF_SIZE		256U
#define	CALL_BUFF_MAX		(CALL_BUFF_SIZE - 1U)

#define HASH_SIZE		131

/* Call table */
#if	0	/* Alternative hash structure */
#define	COB_ALT_HASH
#endif

struct call_hash {
	call_hash *		next;			/* Linked list next pointer */
	const char *	name;			/* Original called name */
	void *			func;			/* Function address */
	cob_module *	module;			/* Program module structure */
	lt_dlhandle		handle;			/* Handle to loaded module */
	const char *	path;			/* Full path of module */
	unsigned int	no_phys_cancel;	/* No physical cancel */
};

struct struct_handle {
	struct_handle *	next;		/* Linked list next pointer */
	const char *	path;		/* Path of module */
	lt_dlhandle		handle;		/* Handle to loaded module */
};

struct system_table {
	const char *	syst_name;
	cob_call_union	syst_call;
};

/* Local variables */

#ifdef	COB_ALT_HASH
static call_hash * call_table;
#else
static call_hash ** call_table;
#endif

static struct_handle * base_preload_ptr;
static struct_handle * base_dynload_ptr;

static cob_global * cobglobptr;

static char **	resolve_path;
static char *	resolve_error;
static char *	resolve_alloc;
static char *	resolve_error_buff;
static char *	call_buffer;
static char *	call_filename_buff;
static char *	call_entry_buff;
static unsigned char *	call_entry2_buff;

static lt_dlhandle	mainhandle;

static size_t		call_lastsize;
static int			resolve_size;
static unsigned int	name_convert;
static unsigned int	cob_jmp_primed;
static unsigned int	physical_cancel;

#undef	COB_SYSTEM_GEN
#if 1
#define	COB_SYSTEM_GEN(x,y,z)		{ x, {(void *(*)(...))z} },
#else
#define	COB_SYSTEM_GEN(x,y,z)		{ x, {(void *(*)(void *))z} },
#endif

static const system_table system_tab[] = {
#include "system.def"
	{ NULL, {NULL} }
};
#undef	COB_SYSTEM_GEN

static const unsigned char	hexval[] = "0123456789ABCDEF";

static unsigned char		valid_char[256];
static const unsigned char	pvalid_char[] =
	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";

/* Local functions */

static void
set_resolve_error(const char * msg, const char * entry)
{
	resolve_error_buff[CALL_BUFF_MAX] = 0;
	snprintf(resolve_error_buff, (size_t)CALL_BUFF_MAX,
			 "%s '%s'", msg, entry);
	resolve_error = resolve_error_buff;
	cob_set_exception(COB_EC_PROGRAM_NOT_FOUND);
	cobglobptr->cob_first_init = 0;
}

static void
cob_set_library_path(const char * path)
{
	/* Clear the previous path */
	if(resolve_path) {
		delete [] resolve_path;
		delete [] resolve_alloc;
	}

	/* Count the number of separators */
	size_t i = 1;
	size_t size = 0;
	for(const char * p = path; *p; p++, size++) {
		if(*p == PATHSEPC) {
			i++;
		}
	}

	/* Build path array */
	size++;
	resolve_alloc = new char[size];
	char * pstr = resolve_alloc;
	for(const char * p = path; *p; p++, pstr++) {
#ifdef	_WIN32
		if(*p == (unsigned char)'/') {
			*pstr = (unsigned char)'\\';
			continue;
		}
#else
		if(*p == (unsigned char)'\\') {
			*pstr = (unsigned char)'/';
			continue;
		}
#endif
		*pstr = *p;
	}
	*pstr = 0;

	resolve_path = new char *[i];
	resolve_size = 0;
	pstr = resolve_alloc;
	for(; ;) {
		char * p = strtok(pstr, PATHSEPS);
		if(!p) {
			break;
		}
		pstr = NULL;
		struct stat st;
		if(stat(p, &st) || !(S_ISDIR(st.st_mode))) {
			continue;
		}
		resolve_path[resolve_size++] = p;
	}
}

static void
do_cancel_module(call_hash * p, call_hash ** base_hash, call_hash * prev)
{
	if(!p->module) {
		return;
	}
	if(!p->module->module_cancel.funcvoid) {
		return;
	}
	bool nocancel = false;
	if(p->module->flag_no_phys_canc) {
		nocancel = true;
	}
	/* This should be impossible */
	if(p->module->module_active) {
		nocancel = true;
	}
	if(p->module->module_ref_count && *(p->module->module_ref_count)) {
		nocancel = true;
	}
	int	(*cancel_func)(const int, void *, void *, void *, void *) =
		(int(*)(const int,void *,void *,void *,void *)) p->module->module_cancel.funcint;
	(void)cancel_func(-1, NULL, NULL, NULL, NULL);
	p->module = NULL;
	if(nocancel) {
		return;
	}
	if(!physical_cancel) {
		return;
	}
	if(p->no_phys_cancel) {
		return;
	}
	if(!p->handle) {
		return;
	}

	lt_dlclose(p->handle);

	struct_handle * dynptr = base_dynload_ptr;
	for(; dynptr; dynptr = dynptr->next) {
		if(dynptr->handle == p->handle) {
			dynptr->handle = NULL;
		}
	}

	if(!prev) {
		*base_hash = p->next;
	} else {
		prev->next = p->next;
	}
	if(p->name) {
		delete [] p->name;
	}
	if(p->path) {
		delete [] p->path;
	}
	delete p;
}

static char *
cob_get_buff(const size_t buffsize)
{
	if(buffsize > call_lastsize) {
		call_lastsize = buffsize;
		delete [] call_buffer;
		call_buffer = new char[buffsize];
	}
	return call_buffer;
}

static void
cache_dynload(const char * path, lt_dlhandle handle)
{
	for(struct_handle * dynptr = base_dynload_ptr; dynptr; dynptr = dynptr->next) {
		if(!strcmp(path, dynptr->path)) {
			if(!dynptr->handle) {
				dynptr->handle = handle;
				return;
			}
		}
	}
	struct_handle * dynptr = new struct_handle;
	dynptr->path = cob_strdup(path);
	dynptr->handle = handle;
	dynptr->next = base_dynload_ptr;
	base_dynload_ptr = dynptr;
}

static size_t
cache_preload(const char * path)
{
	/* Check for duplicate */
	for(struct_handle * preptr = base_preload_ptr; preptr; preptr = preptr->next) {
		if(!strcmp(path, preptr->path)) {
			return 1;
		}
	}

	if(access(path, R_OK) != 0) {
		return 0;
	}

	lt_dlhandle libhandle = lt_dlopen(path);
	if(!libhandle) {
		return 0;
	}

	struct_handle * preptr = new struct_handle;
	preptr->path = (char *) cob_strdup(path);
	preptr->handle = libhandle;
	preptr->next = base_preload_ptr;
	base_preload_ptr = preptr;
	return 1;
}

#ifndef	COB_ALT_HASH
static COB_INLINE unsigned int
hash(const unsigned char * s)
{
	unsigned int val = 0;
	while(*s) {
		val += *s++;
	}
	return val % HASH_SIZE;
}
#endif

static void
insert(const char * name, void * func, lt_dlhandle handle,
	   cob_module * module, const char * path,
	   const unsigned int nocanc)
{
	call_hash * p = new call_hash;
	p->name = (char *) cob_strdup(name);
	p->func = func;
	p->handle = handle;
	p->module = module;
	p->path = 0;
	if(path) {
#ifdef	_WIN32
		char * s = new char[COB_NORMAL_BUFF];
		/* path or NULL */
		p->path = _fullpath(s, path, COB_NORMAL_BUFF);
		if(p->path) {
			p->path = cob_strdup(s);
		}
		delete [] s;
#elif	defined(HAVE_CANONICALIZE_FILE_NAME)
		/* Malloced path or NULL */
		char * s = canonicalize_file_name(path);
		if(s) {
			p->path = cob_strdup(s);
			free(s); // allocated by canonicalize_file_name(path)
		}
#elif	defined(HAVE_REALPATH)
		char * s = new char[COB_NORMAL_BUFF];
		if(realpath(path, s) != NULL) {
			p->path = cob_strdup(s);
		}
		delete [] s;
#endif
		if(!p->path) {
			p->path = cob_strdup(path);
		}
	}
	p->no_phys_cancel = nocanc;
#ifdef	COB_ALT_HASH
	p->next = call_table;
	call_table = p;
#else
	unsigned int val = hash((const unsigned char *)name);
	p->next = call_table[val];
	call_table[val] = p;
#endif
}

static void *
lookup(const char * name)
{
	call_hash * p;

#ifdef	COB_ALT_HASH
	p = call_table;
#else
	p = call_table[hash((const unsigned char *)name)];
#endif
	for(; p; p = p->next) {
		if(strcmp(name, p->name) == 0) {
			return p->func;
		}
	}
	return NULL;
}

static void *
cob_resolve_internal(const char * name, const char * dirent,
					 const int fold_case)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	cob_set_exception(0);

	/* Search the cache */
	void * func = lookup(name);
	if(func) {
		return func;
	}

	/* Encode program name */
	unsigned char * p = (unsigned char *)call_entry_buff;
	const unsigned char	* s = (const unsigned char *)name;
	if(unlikely(*s <= (unsigned char)'9' && *s >= (unsigned char)'0')) {
		*p++ = (unsigned char)'_';
	}
	for(; *s; ++s) {
		if(likely(valid_char[*s])) {
			*p++ = *s;
		} else {
			*p++ = (unsigned char)'_';
			if(*s == (unsigned char)'-') {
				*p++ = (unsigned char)'_';
			} else {
				*p++ = hexval[*s / 16U];
				*p++ = hexval[*s % 16U];
			}
		}
	}
	*p = 0;

	/* Check case folding */
	switch(fold_case) {
	case COB_FOLD_UPPER:
		for(p = (unsigned char *)call_entry_buff; *p; p++) {
			if(islower(*p)) {
				*p = (cob_u8_t)toupper(*p);
			}
		}
		break;
	case COB_FOLD_LOWER:
		for(p = (unsigned char *)call_entry_buff; *p; p++) {
			if(isupper(*p)) {
				*p = (cob_u8_t)tolower(*p);
			}
		}
		break;
	default:
		break;
	}

	/* Search the main program */
	if(mainhandle != NULL) {
		func = lt_dlsym(mainhandle, call_entry_buff);
		if(func != NULL) {
			insert(name, func, mainhandle, NULL, NULL, 1);
			resolve_error = NULL;
			cobglobptr->cob_first_init = 0;
			return func;
		}
	}

	/* Search preloaded modules */
	for(struct_handle * preptr = base_preload_ptr; preptr; preptr = preptr->next) {
		func = lt_dlsym(preptr->handle, call_entry_buff);
		if(func != NULL) {
			insert(name, func, preptr->handle,
				   NULL, preptr->path, 1);
			resolve_error = NULL;
			return func;
		}
	}

	/* Search dynamic modules */
	for(struct_handle * preptr = base_dynload_ptr; preptr; preptr = preptr->next) {
		if(!preptr->handle) {
			continue;
		}
		func = lt_dlsym(preptr->handle, call_entry_buff);
		if(func != NULL) {
			insert(name, func, preptr->handle,
				   NULL, preptr->path, 1);
			resolve_error = NULL;
			return func;
		}
	}

#if	0	/* RXWRXW RTLD */
#if	defined(USE_LIBDL) && defined(RTLD_DEFAULT)
	func = lt_dlsym(RTLD_DEFAULT, call_entry_buff);
	if(func != NULL) {
		insert(name, func, NULL, NULL, NULL, 1);
		resolve_error = NULL;
		return func;
	}
#endif
#endif

	s = (const unsigned char *)name;

	/* Check if name needs conversion */
	if(unlikely(name_convert != 0)) {
		if(!call_entry2_buff) {
			call_entry2_buff = new unsigned char[COB_SMALL_BUFF];
		}
		p = call_entry2_buff;
		for(; *s; ++s, ++p) {
			if(name_convert == 1 && isupper(*s)) {
				*p = (cob_u8_t) tolower(*s);
			} else if(name_convert == 2 && islower(*s)) {
				*p = (cob_u8_t) toupper(*s);
			} else {
				*p = *s;
			}
		}
		*p = 0;
		s = (const unsigned char *)call_entry2_buff;
	}

	/* Search external modules */
#ifdef	__OS400__
	strcpy(call_filename_buff, s);
	for(p = call_filename_buff; *p; ++p) {
		*p = (cob_u8_t)toupper(*p);
	}
	lt_dlhandle handle = lt_dlopen(call_filename_buff);
	if(handle != NULL) {
		/* Candidate for future calls */
		cache_dynload(call_filename_buff, handle);
		func = lt_dlsym(handle, call_entry_buff);
		if(func != NULL) {
			insert(name, func, handle, NULL, call_filename_buff, 0);
			resolve_error = NULL;
			return func;
		}
	}
#else
	if(dirent) {
		call_filename_buff[COB_NORMAL_MAX] = 0;
		snprintf(call_filename_buff, (size_t)COB_NORMAL_MAX,
				 "%s%s.%s", dirent, (char *)s, COB_MODULE_EXT);
		if(access(call_filename_buff, R_OK) != 0) {
			set_resolve_error(_("Cannot find module"), name);
			return NULL;
		}
		lt_dlhandle handle = lt_dlopen(call_filename_buff);
		if(handle != NULL) {
			/* Candidate for future calls */
			cache_dynload(call_filename_buff, handle);
			func = lt_dlsym(handle, call_entry_buff);
			if(func != NULL) {
				insert(name, func, handle, NULL,
					   call_filename_buff, 0);
				resolve_error = NULL;
				return func;
			}
		}
		set_resolve_error(_("Cannot find entry point"),
						  (const char *)s);
		return NULL;
	}
	for(int i = 0; i < resolve_size; ++i) {
		call_filename_buff[COB_NORMAL_MAX] = 0;
		if(resolve_path[i] == NULL) {
			snprintf(call_filename_buff, (size_t)COB_NORMAL_MAX,
					 "%s.%s", (char *)s, COB_MODULE_EXT);
		} else {
			snprintf(call_filename_buff, (size_t)COB_NORMAL_MAX,
					 "%s%s%s.%s", resolve_path[i],
					 SLASH_STR,
					 (char *)s,
					 COB_MODULE_EXT);
		}
		if(access(call_filename_buff, R_OK) == 0) {
			lt_dlhandle handle = lt_dlopen(call_filename_buff);
			if(handle != NULL) {
				/* Candidate for future calls */
				cache_dynload(call_filename_buff, handle);
				func = lt_dlsym(handle, call_entry_buff);
				if(func != NULL) {
					insert(name, func, handle, NULL,
						   call_filename_buff, 0);
					resolve_error = NULL;
					return func;
				}
			}
			set_resolve_error(_("Cannot find entry point"),
							  (const char *)s);
			return NULL;
		}
	}
#endif

	set_resolve_error(_("Cannot find module"), name);
	return NULL;
}

static const char *
cob_chk_dirp(const char * name)
{
	const char	* p;
	const char	* q;

	q = NULL;
	for(p = name; *p; p++) {
		if(*p == '/' || *p == '\\') {
			q = p + 1;
		}
	}
	if(q) {
		return q;
	}
	return name;
}

static const char *
cob_chk_call_path(const char * name, char ** dirent)
{
	*dirent = NULL;
	const char * q = NULL;
	size_t size1 = 0;
	size_t size2 = 0;
	for(const char * p = name; *p; p++, size1++) {
		if(*p == '/' || *p == '\\') {
			q = p + 1;
			size2 = size1 + 1;
		}
	}
	if(q) {
		char * p = cob_strdup(name);
		p[size2] = 0;
		*dirent = p;
		for(; *p; p++) {
#ifdef	_WIN32
			if(*p == '/') {
				*p = '\\';
			}
#else
			if(*p == '\\') {
				*p = '/';
			}
#endif
		}
		return q;
	}
	return name;
}

/* Global functions */

const char *
cob_resolve_error(void)
{
	const char * p;

	if(!resolve_error) {
		p = _("Indeterminable error");
	} else {
		p = resolve_error;
		resolve_error = NULL;
	}
	return p;
}

void
cob_call_error(void)
{
	cob_runtime_error("%s", cob_resolve_error());
	cob_stop_run(1);
}

void
cob_set_cancel(cob_module * m)
{
	call_hash * p;

#ifdef	COB_ALT_HASH
	p = call_table;
#else
	p = call_table[hash((const unsigned char *)(m->module_name))];
#endif
	for(; p; p = p->next) {
		if(strcmp(m->module_name, p->name) == 0) {
			p->module = m;
			/* Set path in program module structure */
			if(p->path && m->module_path && !*(m->module_path)) {
				*(m->module_path) = p->path;
			}
			return;
		}
	}
	insert(m->module_name, m->module_entry.funcvoid, NULL, m, NULL, 1);
}

void *
cob_resolve(const char * name)
{
	char * dirent;
	const char * entry = cob_chk_call_path(name, &dirent);
	void * p = cob_resolve_internal(entry, dirent, 0);
	if(dirent) {
		delete [] dirent;
	}
	return p;
}

void *
cob_resolve_cobol(const char * name, const int fold_case, const int errind)
{
	char * dirent;
	const char * entry = cob_chk_call_path(name, &dirent);
	void * p = cob_resolve_internal(entry, dirent, fold_case);
	if(dirent) {
		delete [] dirent;
	}
	if(unlikely(!p)) {
		if(errind) {
			cob_call_error();
		}
		cob_set_exception(COB_EC_PROGRAM_NOT_FOUND);
	}
	return p;
}

void *
cob_resolve_func(const char * name)
{
	void * p = cob_resolve_internal(name, NULL, 0);
	if(unlikely(!p)) {
		cob_runtime_error(_("User function '%s' not found"), name);
		cob_stop_run(1);
	}
	return p;
}

void *
cob_call_field(const cob_field * f, const cob_call_struct * cs,
			   const unsigned int errind, const int fold_case)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}

	char * buff = cob_get_buff(f->size + 1);
	cob_field_to_string(f, buff, f->size);

	char * dirent;
	const char * entry = cob_chk_call_path(buff, &dirent);

	/* Check if system routine */
	for(const system_table * psyst = system_tab; psyst->syst_name; ++psyst) {
		if(!strcmp(entry, psyst->syst_name)) {
			if(dirent) {
				delete [] dirent;
			}
			return psyst->syst_call.funcvoid;
		}
	}


	/* Check if contained program */
	for(const cob_call_struct * s = cs; s && s->cob_cstr_name; s++) {
		if(!strcmp(entry, s->cob_cstr_name)) {
			if(dirent) {
				delete [] dirent;
			}
			return s->cob_cstr_call.funcvoid;
		}
	}

	void * p = cob_resolve_internal(entry, dirent, fold_case);
	if(dirent) {
		delete [] dirent;
	}
	if(unlikely(!p)) {
		if(errind) {
			cob_call_error();
		} else {
			cob_set_exception(COB_EC_PROGRAM_NOT_FOUND);
			return NULL;
		}
	}
	return p;
}

void
cob_cancel(const char * name)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	if(unlikely(!name)) {
		cob_runtime_error(_("NULL parameter passed to 'cob_cancel'"));
		cob_stop_run(1);
	}
	const char * entry = cob_chk_dirp(name);

	call_hash ** q;
#ifdef	COB_ALT_HASH
	q = &call_table;
#else
	q = &call_table[hash((const unsigned char *)entry)];
#endif
	call_hash * r = NULL;
	for(call_hash * p = *q; p; p = p->next) {
		if(strcmp(entry, p->name) == 0) {
			do_cancel_module(p, q, r);
			return;
		}
		r = p;
	}
}

void
cob_cancel_field(const cob_field * f, const cob_call_struct * cs)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	if(!f || f->size == 0) {
		return;
	}
	char * name = cob_get_buff(f->size + 1);
	cob_field_to_string(f, name, f->size);
	const char * entry = cob_chk_dirp(name);

	/* Check if contained program */
	for(const cob_call_struct * s = cs; s && s->cob_cstr_name; s++) {
		if(!strcmp(entry, s->cob_cstr_name)) {
			if(s->cob_cstr_cancel.funcvoid) {
				int	(*cancel_func)(const int, void *, void *, void *, void *) =
					(int(*)(const int,void *,void *,void *,void *)) s->cob_cstr_cancel.funcint;
				(void)cancel_func(-1, NULL, NULL, NULL, NULL);
			}
			return;
		}
	}
	cob_cancel(entry);
}

int
cob_call(const char * name, const int argc, void ** argv)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	if(argc < 0 || argc > COB_MAX_FIELD_PARAMS) {
		cob_runtime_error(_("Invalid number of arguments to 'cob_call'"));
		cob_stop_run(1);
	}
	if(unlikely(!name)) {
		cob_runtime_error(_("NULL name parameter passed to 'cob_call'"));
		cob_stop_run(1);
	}
	cob_call_union unifunc;
	unifunc.funcvoid = cob_resolve_cobol(name, 0, 1);
	void ** pargv = new void *[COB_MAX_FIELD_PARAMS];
	/* Set number of parameters */
	cobglobptr->cob_call_params = argc;
	for(int i = 0; i < argc; ++i) {
		pargv[i] = argv[i];
	}
	int i = ((int( *)(...))unifunc.funcint)(pargv[0], pargv[1], pargv[2], pargv[3],
											pargv[4], pargv[5], pargv[6], pargv[7],
											pargv[8], pargv[9], pargv[10], pargv[11],
#if	COB_MAX_FIELD_PARAMS == 16
											pargv[12], pargv[13], pargv[14], pargv[15]);
#elif	COB_MAX_FIELD_PARAMS == 36
											pargv[12], pargv[13], pargv[14], pargv[15],
											pargv[16], pargv[17], pargv[18], pargv[19],
											pargv[20], pargv[21], pargv[22], pargv[23],
											pargv[24], pargv[25], pargv[26], pargv[27],
											pargv[28], pargv[29], pargv[30], pargv[31],
											pargv[32], pargv[33], pargv[34], pargv[35]);
#else
#error	"Invalid COB_MAX_FIELD_PARAMS value"
#endif
	delete [] pargv;
	return i;
}

int
cob_func(const char * name, const int argc, void ** argv)
{
	int ret = cob_call(name, argc, argv);
	cob_cancel(name);
	return ret;
}

void *
cob_savenv(cobjmp_buf * jbuf)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	if(unlikely(!jbuf)) {
		cob_runtime_error(_("NULL parameter passed to 'cob_savenv'"));
		cob_stop_run(1);
	}
	if(cob_jmp_primed) {
		cob_runtime_error(_("Multiple call to 'cob_setjmp'"));
		cob_stop_run(1);
	}
	cob_jmp_primed = 1;
	return jbuf->cbj_jmp_buf;
}

void *
cob_savenv2(cobjmp_buf * jbuf, const int jsize)
{
	COB_UNUSED(jsize);

	return cob_savenv(jbuf);
}

void
cob_longjmp(cobjmp_buf * jbuf)
{
	if(unlikely(!cobglobptr)) {
		cob_fatal_error(COB_FERROR_INITIALIZED);
	}
	if(unlikely(!jbuf)) {
		cob_runtime_error(_("NULL parameter passed to 'cob_longjmp'"));
		cob_stop_run(1);
	}
	if(!cob_jmp_primed) {
		cob_runtime_error(_("Call to 'cob_longjmp' with no prior 'cob_setjmp'"));
		cob_stop_run(1);
	}
	cob_jmp_primed = 0;
	longjmp(jbuf->cbj_jmp_buf, 1);
}

void
cob_exit_call(void)
{
	if(call_filename_buff) {
		delete [] call_filename_buff;
		call_filename_buff = NULL;
	}
	if(call_entry_buff) {
		delete [] call_entry_buff;
		call_entry_buff = NULL;
	}
	if(call_entry2_buff) {
		delete [] call_entry2_buff;
		call_entry2_buff = NULL;
	}
	if(call_buffer) {
		delete [] call_buffer;
		call_buffer = NULL;
	}
	if(resolve_error_buff) {
		delete [] resolve_error_buff;
		resolve_error_buff = NULL;
	}
	if(resolve_alloc) {
		delete [] resolve_alloc;
		resolve_alloc = NULL;
	}
	if(resolve_path) {
		delete [] resolve_path;
		resolve_path = NULL;
	}

	call_hash * p;
#ifndef	COB_ALT_HASH
	for(int i = 0; i < HASH_SIZE; ++i) {
		p = call_table[i];
#else
	p = call_table;
#endif
		for(; p;) {
			call_hash * q = p;
			p = p->next;
			if(q->name) {
				delete [] q->name;
			}
			if(q->path) {
				delete [] q->path;
			}
			delete q;
		}
#ifndef	COB_ALT_HASH
	}
	if(call_table)
	{
		delete [] call_table;
	}
	call_table = NULL;
#endif

	for(struct_handle * h = base_preload_ptr; h;)
	{
		struct_handle * j = h;
		if(h->path) {
			delete [] h->path;
		}
		if(h->handle) {
			lt_dlclose(h->handle);
		}
		h = h->next;
		delete j;
	}
	base_preload_ptr = NULL;
	for(struct_handle * h = base_dynload_ptr; h;)
	{
		struct_handle * j = h;
		if(h->path) {
			delete [] h->path;
		}
		if(h->handle) {
			lt_dlclose(h->handle);
		}
		h = h->next;
		delete j;
	}
	base_dynload_ptr = NULL;

#if	!defined(_WIN32) && !defined(USE_LIBDL)
	lt_dlexit();
#if	0	/* RXWRXW - ltdl leak */
	/* Weird - ltdl leaks mainhandle - This appears to work but .. */
	free(mainhandle); // commented out by Roger
#endif
#endif

}

void
cob_init_call(cob_global * lptr)
{
	cobglobptr = lptr;

	base_preload_ptr = NULL;
	base_dynload_ptr = NULL;
	resolve_path = NULL;
	resolve_alloc = NULL;
	resolve_error = NULL;
	resolve_error_buff = NULL;
	mainhandle = NULL;
	call_buffer = NULL;
	call_filename_buff = NULL;
	call_entry_buff = NULL;
	call_entry2_buff = NULL;
	call_table = NULL;
	call_lastsize = 0;
	resolve_size = 0;
	name_convert = 0;
	cob_jmp_primed = 0;
	physical_cancel = 0;

	memset(valid_char, 0, sizeof(valid_char));
	for(const unsigned char * pv = pvalid_char; *pv; ++pv) {
		valid_char[*pv] = 1;
	}

	/* Big enough for anything from libdl/libltdl */
	resolve_error_buff = new char[CALL_BUFF_SIZE];

#ifndef	COB_ALT_HASH
	call_table = new call_hash *[HASH_SIZE];
	memset(call_table, 0, HASH_SIZE * sizeof(call_hash *));
#endif

	call_filename_buff = new char[COB_NORMAL_BUFF];
	call_entry_buff = new char[COB_SMALL_BUFF];

	char * s = getenv("COB_PHYSICAL_CANCEL");
	if(s) {
		if(*s == 'Y' || *s == 'y' || *s == '1') {
			physical_cancel = 1;
		}
	} else {
		s = getenv("default_cancel_mode");
		if(s) {
			if(*s == '0') {
				physical_cancel = 1;
			}
		}
	}

	s = getenv("COB_LOAD_CASE");
	if(s != NULL) {
		if(strcasecmp(s, "LOWER") == 0) {
			name_convert = 1;
		} else if(strcasecmp(s, "UPPER") == 0) {
			name_convert = 2;
		}
	}

	char * buff = new char[COB_MEDIUM_BUFF];
	s = getenv("COB_LIBRARY_PATH");
	if(s == NULL) {
		snprintf(buff, (size_t)COB_MEDIUM_MAX, ".%s%s",
				 PATHSEPS, COB_LIBRARY_PATH);
	} else {
		snprintf(buff, (size_t)COB_MEDIUM_MAX, "%s%s.%s%s",
				 s, PATHSEPS, PATHSEPS, COB_LIBRARY_PATH);
	}
	cob_set_library_path(buff);

	lt_dlinit();

#ifndef	COB_BORKED_DLOPEN
	mainhandle = lt_dlopen(NULL);
#endif

	s = getenv("COB_PRE_LOAD");
	if(s != NULL) {
		char * p = cob_strdup(s);
		s = strtok(p, PATHSEPS);
		for(; s; s = strtok(NULL, PATHSEPS)) {
#ifdef __OS400__
			for(char * t = s; *t; ++t) {
				*t = toupper(*t);
			}
			cache_preload(s);
#else
			int i;
			for(i = 0; i < resolve_size; ++i) {
				buff[COB_MEDIUM_MAX] = 0;
				snprintf(buff, (size_t)COB_MEDIUM_MAX,
						 "%s/%s.%s",
						 resolve_path[i], s, COB_MODULE_EXT);
				if(cache_preload(buff)) {
					break;
				}
			}
			/* If not found, try just using the name */
			if(i == resolve_size) {
				(void)cache_preload(s);
			}
#endif
		}
		delete [] p;
	}
	delete [] buff;
	call_buffer = new char[CALL_BUFF_SIZE];
	call_lastsize = CALL_BUFF_SIZE;
}
