/*
   Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
   Copyright (C) 2007-2012 Roger While

   This file is part of GNU Cobol.

   The GNU Cobol runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GNU Cobol.  If not, see <http://www.gnu.org/licenses/>.




   OpenCOBOL fileio module. Re-engineered by BCS/JR. 2013
 */




#include "fileio-misc.h"
#include "fileio-stats.h"


/*
 *	This entire module is dummied unless configured WITH_FILEIO_STATS
 *	=================================================================
 *
 */

#ifndef WITH_FILEIO_STATS

int cob_fileio_stats_initialise(void)
{
	return(0);
}


int cob_fileio_stats_initialise_file(
	  cob_file_t *f)
{
	return(0);
}


int cob_fileio_stats_open_file(
	  cob_file_t *f
	, exception_t *exc
	, char *(*fn_file_xml) (cob_file_t *, const char *))
{
	return(0);
}

int cob_fileio_stats_close_file(
	  cob_file_t *f
	, int opt
	, exception_t *exc)
{
	return(0);
}

int cob_fileio_stats_terminate(void)
{
	return(0);
}
#endif



#ifdef WITH_FILEIO_STATS


/*
 *	fileio_stats generates a report in XML format describing
 *	a single execution of an OpenCOBOL program.
 *
 *	The stats report for this process is built in isolation.
 *	The report is optionally appended to a composite stats report at EOJ.
 *
 *	Environmental variables referenced [default]:
 *	COB_STATS :: produce stats report for this process [no]
 *	COB_STATS_REPORT :: name of consolidated stats report [no consolidation]
 *	                    setting COB_STATS_REPORT implicitly sets COB_STATS
 *	COB_STATS_DIR :: name of directory to hold stats reports [TMPDIR]
 *
 */

#include "fileio-misc.h"
#include "fileio-isam.h"
#include "fileio-sequential.h"


// casual ref to env-vars from fileio-module
extern int sort_memory;
extern int synchronise;






#define CB_XML_STATS 4096



#ifdef WITH_FILEIO_TRACE
static const char *me = "COB_fileio-stats";
#endif


static char *fid_stats_consolidated;
static char *dir_stats = NULL;
static char *fid_stats = NULL;
static FILE *f_stats = NULL;

static int tf_stats = 0;
static int tf_program_emitted = 0;
static int tf_process_started = 0;



static void	_stats_emit_compiler(void);

static void	_stats_emit_environment(void);

static void	_stats_emit_program(void);

static void _stats_emit_process_boj(void);

static void _stats_reset(cob_file_t *f);

static void _stats_emit_exception(exception_t *exc, const char *indent); 



int cob_fileio_stats_initialise(void)
{
	char *var, *pb_dir;

	var = getenv("COB_STATS"); 
	tf_stats = 0;
	if ((var != NULL) && ((*var == 'y') || (*var == 'Y') || (*var == '1')))
		tf_stats = 1;
	fid_stats_consolidated = getenv("COB_STATS_REPORT");
	if (fid_stats_consolidated != NULL)
		tf_stats = 1;
	if (tf_stats == 0)
		return(0);

	dir_stats = cob_malloc(FILENAME_MAX);
	fid_stats = cob_malloc(FILENAME_MAX);
	pb_dir = getenv("COB_STATS_DIR");
	if (pb_dir == NULL) {
		cob_fileio_get_dirtmp(dir_stats);
	} else {
		strcpy(dir_stats, pb_dir);
	}
	dir_stats = realloc(dir_stats, strlen(dir_stats)+1);

#ifdef _WIN32
	GetTempFileName (dir_stats, "cob_stat", 0, fid_stats);
#else
	sprintf(fid_stats, "%s/cob-stat-%d", dir_stats, getpid());
#endif
	fid_stats = realloc(fid_stats, strlen(fid_stats)+1);

	f_stats = fopen(fid_stats, "w+");
	if (f_stats == NULL) {
		fprintf(stderr, "libcob: fileio: !!! failed to open stats file [erc=%d]: \"%s\"\n", errno, fid_stats);
		return(-1);
	}

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1)
		fprintf(stderr, "%s: cob_fileio_stats_initialise() file-name=%s\n", me, fid_stats);
#endif

	fprintf(f_stats, "<openCOBOL_stats>\n");
	_stats_emit_compiler();
	_stats_emit_environment();
	return(0);
}





int cob_fileio_stats_initialise_file(
	  cob_file_t *f)
{
	const char *p_org, *p_acc;
	
	if (!tf_stats) return(0);

	if (!tf_program_emitted)
		_stats_emit_program();

	_stats_reset(f);
	switch(f->organization) {
		case COB_ORG_SEQUENTIAL:		p_org = "SEQUENTIAL";		break;
		case COB_ORG_LINE_SEQUENTIAL:	p_org = "LINE_SEQUENTIAL";	break;
		case COB_ORG_RELATIVE:			p_org = "RELATIVE";			break;
		case COB_ORG_INDEXED:			p_org = "INDEXED";			break;
		case COB_ORG_SORT:				p_org = "SORT";				break;
		default:						p_org = "ILLEGAL";
	}
	switch(f->access_mode) {
		case COB_ACCESS_SEQUENTIAL:		p_acc = "SEQUENTIAL";	break;
		case COB_ACCESS_DYNAMIC:		p_acc = "DYNAMIC";		break;
		case COB_ACCESS_RANDOM:			p_acc = "RANDOME";		break;
		default:						p_acc = "ILLEGAL";
	}

	fprintf(f_stats, "\t\t<file>\n");
	fprintf(f_stats, "\t\t\t<select_name> %s </select_name>\n", f->select_name);
	fprintf(f_stats, "\t\t\t<organisation> %s </organisation>\n", p_org);
	fprintf(f_stats, "\t\t\t<access_mode> %s </access_mode>\n", p_acc);
	fprintf(f_stats, "\t\t</file>\n");
	return(0);
}





int cob_fileio_stats_open_file(
	  cob_file_t *f
	, exception_t *exc
	, char *(*fn_file_xml) (cob_file_t *, const char *))
{
	const char *p_mode;
	char *bfr;
	if (!tf_stats) return(0);

	if (!tf_process_started)
		_stats_emit_process_boj();

	_stats_reset(f);
	switch(f->open_mode) {
		case COB_OPEN_INPUT:	p_mode = "INPUT";	break;
		case COB_OPEN_OUTPUT:	p_mode = "OUTPUT";	break;
		case COB_OPEN_I_O:		p_mode = "IO";		break;
		case COB_OPEN_EXTEND:	p_mode = "EXTEND";	break;
		default:				p_mode = "ILLEGAL";
	}
	fprintf(f_stats, "\t\t<file_open name=\"%s\" mode=\"%s\" >\n", f->select_name, p_mode);
	fprintf(f_stats, "\t\t\t<at> %s </at>\n", cob_fileio_get_now()); 
	fprintf(f_stats, "\t\t\t<assign_name> %s </assign_name>\n", f->assign_name);
	fprintf(f_stats, "\t\t\t<physical_name> %s </physical_name>\n", f->fid);
	bfr = fn_file_xml(f, "\t\t\t");
	if (bfr != NULL) {
		fprintf(f_stats, "%s", bfr);
		free(bfr);
	}
	fprintf(f_stats, "\t\t\t<status> %s </status>\n", cob_fileio_status_to_str(exc->status_key));
	if (exc->state != COB_IO_STATE_SUCCESS) 
		_stats_emit_exception(exc, "\t\t\t"); 
	fprintf(f_stats, "\t\t</file_open>\n");
	return(0);
}





int cob_fileio_stats_close_file(
	  cob_file_t *f
	, int opt
	, exception_t *exc)
{
	cob_io_stats_t total, good;
	
	if (!tf_stats) return(0);

	if (!tf_process_started)
		_stats_emit_process_boj();

	total = f->io_stats[0];
	good = f->io_stats[1];

	fprintf(f_stats, "\t\t<file_close  name=\"%s\" options_hex=\"%x\" >\n", f->select_name, opt);
	fprintf(f_stats, "\t\t\t<at> %s </at>\n", cob_fileio_get_now());
	fprintf(f_stats, "\t\t\t<status> %s </status>\n", cob_fileio_status_to_str(exc->status_key));
	if (exc->state != COB_IO_STATE_SUCCESS) 
		_stats_emit_exception(exc, "\t\t\t");

	if (total.cnt_read > 0) {
		if (total.cnt_read == good.cnt_read) {
			fprintf(f_stats, "\t\t\t<reads> %d </reads>\n", total.cnt_read);
		} else {
			fprintf(f_stats
				, "\t\t\t<reads> <total> %d </total> <completed> %d </completed> <failed> %d </failed> </reads>\n"
				, total.cnt_read
				, good.cnt_read
				, total.cnt_read - good.cnt_read);
		}
	}
	if (total.cnt_start > 0) {
		if (total.cnt_start == good.cnt_start) {
			fprintf(f_stats, "\t\t\t<starts> %d </starts>\n", total.cnt_start);
		} else {
			fprintf(f_stats
				, "\t\t\t<starts> <total> %d </total> <completed> %d </completed> <failed> %d </failed> </starts>\n"
				, total.cnt_start
				, good.cnt_start
				, total.cnt_start - good.cnt_start);
		}
	}
	if (total.cnt_write > 0) {
		if (total.cnt_write == good.cnt_write) {
			fprintf(f_stats, "\t\t\t<writes> %d </writes>\n", total.cnt_write);
		} else {
			fprintf(f_stats
				, "\t\t\t<writes> <total> %d </total> <completed> %d </completed> <failed> %d </failed> </writes>\n"
				, total.cnt_write
				, good.cnt_write
				, total.cnt_write - good.cnt_write);
		}
	}
	if (total.cnt_rewrite > 0) {
		if (total.cnt_rewrite == good.cnt_rewrite) {
			fprintf(f_stats, "\t\t\t<rewrites> %d </rewrites>\n", total.cnt_rewrite);
		} else {
			fprintf(f_stats
				, "\t\t\t<rewrites> <total> %d </total> <completed> %d </completed> <failed> %d </failed> </rewrites>\n"
				, total.cnt_rewrite
				, good.cnt_rewrite
				, total.cnt_rewrite - good.cnt_rewrite);
		}
	}
	if (total.cnt_delete > 0) {
		if (total.cnt_delete == good.cnt_delete) {
			fprintf(f_stats, "\t\t\t<deletes> %d </deletes>\n", total.cnt_delete);
		} else {
			fprintf(f_stats
				, "\t\t\t<deletes> <total> %d </total> <completed> %d </completed> <failed> %d </failed> </deletes>\n"
				, total.cnt_delete
				, good.cnt_delete
				, total.cnt_delete - good.cnt_delete);
		}
	}
	fprintf(f_stats, "\t\t</file_close>\n");
	return(0);
}






int cob_fileio_stats_terminate(void)
{
	int c;
	FILE *f_consolidated;

	if (!tf_stats) return(0);

	if (!tf_process_started)
		_stats_emit_process_boj();
	fprintf(f_stats, "\t\t<eoj> <at> %s </at> </eoj>\n", cob_fileio_get_now());
	fprintf(f_stats, "\t</process>\n");
	fprintf(f_stats, "</openCOBOL_stats>");

	if (fid_stats_consolidated == NULL) {
		fclose(f_stats);

#ifdef  WITH_FILEIO_TRACE
		if (trace_level > 1)
			fprintf(stderr, "%s: cob_fileio_stats_terminate() %s\n", me, fid_stats);
#endif

		return(0);
	}

	f_consolidated = fopen(fid_stats_consolidated, "a");
	if (f_consolidated == NULL) 
		return(-1);
	rewind(f_stats);
	while (!feof(f_stats)) {
		c = fgetc(f_stats);
		if (c != EOF)
			fputc(c, f_consolidated);
	}
	fputs("\n\n\n", f_consolidated);
	fclose(f_consolidated);
	fclose(f_stats);

#ifdef  WITH_FILEIO_TRACE
	if (trace_level > 1) {
		fprintf(stderr, "%s: cob_fileio_stats_terminate() %s >> %s\n"
		      , me, fid_stats, fid_stats_consolidated);
	} else {
		unlink(fid_stats);
	}
#else
	unlink(fid_stats);
#endif

	return(0);
}




static void	_stats_emit_compiler(void)
{
	const char *_ISAM_HANDLER = "unspecified";
	const char *_SEQUENTIAL_HANDLER = "unspecified";
	const char *_RELATIVE_HANDLER = "unspecified";
	const char *_COB_EXPERIMENTAL = "yes";

	const char *_HAVE_SYS_TYPES_H = "yes";
	const char *_HAVE_UNISTD_H = "yes";
	const char *_HAVE_FCNTL_H = "yes";

	const char *_WORDS_BIGENDIAN = "yes";
	const char *_HAVE_FCNTL = "yes";

	const char *_COB_PARAM_CHECK = "yes";
	const char *_COB_SHARED_OPT = "yes";
	const char *_WITH_FILEIO_SHARING = "yes";
	const char *_WITH_FILEIO_LOG = "yes";
	const char *_WITH_FILEIO_TRACE = "yes";
	const char *_RELATIVE_FIXED_RSZ = "yes";
	const char *_COB_TREAT_NULL_AS_ZERO = "yes";
	const char *_COB_IGNORE_NUMBER_ZONE = "yes";


#if defined(WITH_INDEXED_CISAM)
	_ISAM_HANDLER = "cisam";
#elif defined(WITH_INDEXED_DISAM)
	_ISAM_HANDLER = "disam";
#elif defined(WITH_INDEXED_VBISAM)
	_ISAM_HANDLER = "vbisam";
#elif defined(WITH_INDEXED_BDB)
	_ISAM_HANDLER = "bdb";
#elif defined(WITH_INDEXED_BDB_1)
	_ISAM_HANDLER = "bdb [pre 4.1]";
#elif defined(WITH_INDEXED_EXTERNAL)
	_ISAM_HANDLER = "external";
#elif defined(WITH_INDEXED_ODBC)
	_ISAM_HANDLER = "odbc";
#elif defined(WITH_INDEXED_NONE)
	_ISAM_HANDLER = "none";
#endif

#if defined(WITH_SEQUENTIAL)
	_SEQUENTIAL_HANDLER = "internal";
#elif defined(WITH_SEQUENTIAL_EXTERNAL)
	_SEQUENTIAL_HANDLER = "external";
#elif defined(WITH_INDEXED_NONE)
	_SEQUENTIAL_HANDLER = "none";
#endif

#if defined(WITH_RELATIVE)
	_RELATIVE_HANDLER = "internal";
#elif defined(WITH_RELATIVE_EXTERNAL)
	_RELATIVE_HANDLER = "external";
#elif defined(WITH_RELATIVE_NONE)
	_RELATIVE_HANDLER = "none";
#endif


#ifndef COB_EXPERIMENTAL
	_COB_EXPERIMENTAL = "no";
#endif

#ifndef HAVE_SYS_TYPES_H
	_HAVE_SYS_TYPES_H = "no";
#endif

#ifndef HAVE_UNISTD_H
	_HAVE_UNISTD_H = "no";
#endif

#ifndef HAVE_FCNTL_H
	_HAVE_FCNTL_H = "no";
#endif

#ifndef WORDS_BIGENDIAN
	_WORDS_BIGENDIAN = "no";
#endif

#ifndef HAVE_FCNTL
	_HAVE_FCNTL = "no";
#endif

#ifndef COB_PARAM_CHECK
	_COB_PARAM_CHECK = "no";
#endif

#ifndef COB_SHARED_OPT
	_COB_SHARED_OPT = "no";
#endif

#ifndef WITH_FILEIO_SHARING
	_WITH_FILEIO_SHARING = "no";
#endif

#ifndef WITH_FILEIO_LOG
	_WITH_FILEIO_LOG = "no";
#endif

#ifndef WITH_FILEIO_TRACE
	_WITH_FILEIO_TRACE = "no";
#endif

#ifndef WITH_RELATIVE_FIXED_RSZ
	_RELATIVE_FIXED_RSZ = "no";
#endif

#ifdef WITH_VARSEQ
	const int _VARSEQ = WITH_VARSEQ;
#else
	const int _VARSEQ = 0;
#endif

#ifndef COB_TREAT_NULL_AS_ZERO
	_COB_TREAT_NULL_AS_ZERO = "no";
#endif

#ifndef COB_IGNORE_NUMBER_ZONE
	_COB_IGNORE_NUMBER_ZONE = "no";
#endif

 	
	fprintf(f_stats, "\t<compiler>\n");

#ifdef _WIN32
	fprintf(f_stats, "\t\t<os> %s </os>\n", "Windows32");
#endif

	fprintf(f_stats, "\t\t<config>\n");
	fprintf(f_stats, "\t\t\t<PACKAGE> %s </PACKAGE>\n", PACKAGE_STRING);
	fprintf(f_stats, "\t\t\t<PATCH_LEVEL> %d </PATCH_LEVEL>\n", PATCH_LEVEL);
	fprintf(f_stats, "\t\t\t<COB_EXPERIMENTAL> %s </COB_EXPERIMENTAL>\n", _COB_EXPERIMENTAL);
	fprintf(f_stats, "\t\t\t<HAVE_SYS_TYPES_H> %s </HAVE_SYS_TYPES_H>\n", _HAVE_SYS_TYPES_H);
	fprintf(f_stats, "\t\t\t<HAVE_UNISTD_H> %s </HAVE_UNISTD_H>\n", _HAVE_UNISTD_H);
	fprintf(f_stats, "\t\t\t<HAVE_FCNTL_H> %s </HAVE_FCNTL_H>\n", _HAVE_FCNTL_H);

	fprintf(f_stats, "\t\t\t<WORDS_BIGENDIAN> %s </WORDS_BIGENDIAN>\n", _WORDS_BIGENDIAN);
	fprintf(f_stats, "\t\t\t<HAVE_FCNTL> %s </HAVE_FCNTL>\n", _HAVE_FCNTL);

	fprintf(f_stats, "\t\t\t<isam_handler> %s </isam_handler>\n", _ISAM_HANDLER);
	fprintf(f_stats, "\t\t\t<sequential_handler> %s </sequential_handler>\n", _SEQUENTIAL_HANDLER);
	fprintf(f_stats, "\t\t\t<SEQUENTIAL_VARIABLE_RSZ> %d </SEQUENTIAL_VARIABLE_RSZ>\n", _VARSEQ);
	fprintf(f_stats, "\t\t\t<relative_handler> %s </relative_handler>\n", _RELATIVE_HANDLER);
	fprintf(f_stats, "\t\t\t<RELATIVE_FIXED_RSZ> %s </RELATIVE_FIXED_RSZ>\n", _RELATIVE_FIXED_RSZ);
	fprintf(f_stats, "\t\t\t<COB_PARAM_CHECK> %s </COB_PARAM_CHECK>\n", _COB_PARAM_CHECK);
	fprintf(f_stats, "\t\t\t<COB_SHARED_OPT> %s </COB_SHARED_OPT>\n", _COB_SHARED_OPT);
	fprintf(f_stats, "\t\t\t<COB_TREAT_NULL_AS_ZERO> %s </COB_TREAT_NULL_AS_ZERO>\n", _COB_TREAT_NULL_AS_ZERO);
	fprintf(f_stats, "\t\t\t<COB_IGNORE_NUMBER_ZONE> %s </COB_IGNORE_NUMBER_ZONE>\n", _COB_IGNORE_NUMBER_ZONE);
	fprintf(f_stats, "\t\t\t<WITH_FILEIO_SHARING> %s </WITH_FILEIO_SHARING>\n", _WITH_FILEIO_SHARING);
	fprintf(f_stats, "\t\t\t<WITH_FILEIO_LOG> %s </WITH_FILEIO_LOG>\n", _WITH_FILEIO_LOG);
	fprintf(f_stats, "\t\t\t<WITH_FILEIO_TRACE> %s </WITH_FILEIO_TRACE>\n", _WITH_FILEIO_TRACE);
	fprintf(f_stats, "\t\t</config>\n");
	fprintf(f_stats, "\t</compiler>\n");
}






static void _stats_emit_environment(void) 
{
	int ix_sw;
	char sw_name[13], sw_settings[10];
	const char *var, *val;
	char cwd[FILENAME_MAX];
	char dirtmp[FILENAME_MAX];
	
	getcwd(cwd, FILENAME_MAX);

	fprintf(f_stats, "\t<environment>\n");
	fprintf(f_stats, "\t\t<cwd> %s </cwd>\n", cwd);

	var = getenv("COB_LINE_TRACE");
    if ((var != NULL) && (*var == 'Y' || *var == 'y')) 
		val = "yes";
	else
		val = "no";
	fprintf(f_stats, "\t\t<line_trace var=\"COB_LINE_TRACE\" value=\"%s\" >\n", var);
	fprintf(f_stats, "\t\t\t%s\n", val);
	fprintf(f_stats, "\t\t</line_trace>\n");



	memset(sw_settings, '-', 9);
	sw_settings[9] = '\0'; 
	for (ix_sw = 0; ix_sw < 9; ++ix_sw) {
		sprintf(sw_name, "COB_SWITCH_%.1d", ix_sw);
		var = getenv(sw_name);
		if ((var != NULL) && strcasecmp(var, "ON") == 0) {
			sw_settings[ix_sw] = '|';
		}
	}
	fprintf(f_stats, "\t\t<switches> var=\"COB_SWITCH_n\" >\n");
	fprintf(f_stats, "\t\t\t%s\n", sw_settings);
	fprintf(f_stats, "\t\t</switches>\n");

	fprintf(f_stats, "\t\t<fileio>\n");
	var = getenv("COB_FILE_PATH");
	val = (var == NULL) ? "cwd" : var;
	fprintf(f_stats, "\t\t\t<files_root_directory var=\"COB_FILE_PATH\" value=\"%s\" >\n", var);
	fprintf(f_stats, "\t\t\t\t%s\n", val);
	fprintf(f_stats, "\t\t\t</files_root_directory>\n");

	cob_fileio_get_dirtmp(dirtmp);
	fprintf(f_stats, "\t\t\t<temp_directory var=\"TMPDIR | TMP | TEMP\" >\n");
	fprintf(f_stats, "\t\t\t\t%s\n", dirtmp);
	fprintf(f_stats, "\t\t\t</temp_directory>\n");


	fprintf(f_stats, "\t\t\t<synchronise_io var=\"COB_SYNC\" value=\"%s\" >\n"
	      , getenv("COB_SYNC"));
	fprintf(f_stats, "\t\t\t\t%d\n", synchronise);
	fprintf(f_stats, "\t\t\t</synchronise_io>\n");

	fprintf(f_stats, "\t\t\t<sort_max_memory var=\"COB_SORT_MEMORY\" value=\"%s\" >\n"
	      , getenv("COB_SORT_MEMORY"));
	fprintf(f_stats, "\t\t\t\t%d Mb\n", sort_memory);
	fprintf(f_stats, "\t\t\t</sort_max_memory>\n");

#ifdef  WITH_FILEIO_TRACE
	fprintf(f_stats, "\t\t\t<fileio_trace var=\"COB_FILEIO_TRACE\" value=\"%s\" >\n"
	      , getenv("COB_FILEIO_TRACE"));
	fprintf(f_stats, "\t\t\t\t%d\n", trace_level);
	fprintf(f_stats, "\t\t\t</fileio_trace>\n");
#endif


	fprintf(f_stats, "\t\t\t<org_sequential>\n");
	val = cob_fileio_sequential_stats_env("\t\t\t\t");
	fprintf(f_stats, val);
	free((char *)val);
	fprintf(f_stats, "\t\t\t</org_sequential>\n");

	fprintf(f_stats, "\t\t\t<org_indexed>\n");
	val = cob_fileio_isam_stats_env("\t\t\t\t");
	fprintf(f_stats, val);
	free((char *)val);
	fprintf(f_stats, "\t\t\t</org_indexed>\n");
	fprintf(f_stats, "\t\t</fileio>\n");

	fprintf(f_stats, "\t</environment>\n");
}



static void	_stats_emit_program(void)
{
	progid_t progid;
    progid = cob_get_progid();
	fprintf(f_stats, "\t<program>\n");
	fprintf(f_stats, "\t\t<program_id> %s </program_id>\n", progid.program_name);
	fprintf(f_stats, "\t\t<source> %s </source>\n", progid.source_file_name);
	fprintf(f_stats, "\t\t<version> %s </version>\n", progid.version);
	fprintf(f_stats, "\t\t<patch_level> %d </patch_level>\n", progid.patch);
	fprintf(f_stats, "\t\t<compilation_host> %s </compilation_host>\n", progid.compile_host);
	fprintf(f_stats, "\t\t<compilation_date> %s </compilation_date>\n", progid.compile_date);
	tf_program_emitted = 1;
}



static void _stats_emit_process_boj(void)
{
	if (!tf_program_emitted)
		_stats_emit_program();
	fprintf(f_stats, "\t</program>\n");

	fprintf(f_stats, "\t<process>\n");
	fprintf(f_stats, "\t\t<boj> <at> %s </at> </boj>\n", cob_fileio_get_now());
	fprintf(f_stats, "\t\t<pid> %d </pid>\n", getpid());
	tf_process_started = 1;
}


static void _stats_reset(cob_file_t *f)
{
	int i;
	for (i = 0; i < 2; ++i) {
		f->io_stats[i].cnt_read = 0;
		f->io_stats[i].cnt_write = 0;
		f->io_stats[i].cnt_rewrite = 0;
		f->io_stats[i].cnt_delete = 0;
		f->io_stats[i].cnt_start = 0;
	}
}


static void _stats_emit_exception(
	  exception_t *exc
	, const char *indent) 
{
	fprintf(f_stats, "%s<exception>\n", indent);
	fprintf(f_stats, "%s\t<context> %s </context>\n"
		, indent, cob_exception_context_cap[exc->context]);
	fprintf(f_stats, "%s\t<realm> %s </realm>\n"
		, indent, cob_exception_realm_cap[exc->realm]);
	fprintf(f_stats, "%s\t<verb> %s </verb>\n"
		, indent, cob_exception_verb_cap[exc->verb]);
	fprintf(f_stats, "%s\t<status>\n", indent);
	fprintf(f_stats, "%s\t\t<status_key> %s </status_key>\n"
		, indent, cob_fileio_status_to_str(exc->status_key));
	fprintf(f_stats, "%s\t\t<status_message> %s </status_message>\n"
		, indent, cob_fileio_status_msg(exc->status_key));
	fprintf(f_stats, "%s\t\t<state> %s </state>\n"
		, indent, cob_exception_state_cap[exc->state]);
	fprintf(f_stats, "%s\t</status>\n", indent);
	fprintf(f_stats, "%s\t<cobol_exc>\n", indent);
	fprintf(f_stats, "%s\t\t<exc_code> %d </exc_code>\n"
		, indent, exc->erc_cobol);
	fprintf(f_stats, "%s\t\t<exc_message> %s </exc_message>\n"
		, indent, exc->msg_cobol);
	fprintf(f_stats, "%s\t</cobol_exc>\n", indent);
	if (exc->erc_native != 0) {
		fprintf(f_stats, "%s\t<native_exc>\n", indent);
		fprintf(f_stats, "%s\t\t<exc_code> %d </exc_code>\n"
			, indent, exc->erc_native);
		fprintf(f_stats, "%s\t\t<exc_message> %s </exc_message>\n"
			, indent, exc->msg_native);
		fprintf(f_stats, "%s\t</native_exc>\n", indent);
	}
	fprintf(f_stats, "%s</exception>\n", indent);
}



#endif            // WITH_FILEIO_STATS
