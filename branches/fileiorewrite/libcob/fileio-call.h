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





/*
 *	The header file for OpenCOBOL fileio :: interface to functions supporting COBOL CALL
 *
*/



#ifndef FILEIO_CALL_H
#define FILEIO_CALL_H




extern int cob_sys_create_file(
	  unsigned char *file_name
	, unsigned char *file_access
	, unsigned char *file_lock
	, unsigned char *file_dev
	, unsigned char *file_handle);

extern int cob_sys_open_file(
	  unsigned char *file_name
	, unsigned char *file_access
	, unsigned char *file_lock
	, unsigned char *file_dev
	, unsigned char *file_handle);

extern int cob_sys_read_file(
	  unsigned char *file_handle
	, unsigned char *file_offset
	, unsigned char *file_len
	, unsigned char *flags
	, unsigned char *buf);

extern int cob_sys_write_file(
	  unsigned char *file_handle
	, unsigned char *file_offset
	, unsigned char *file_len
	, unsigned char *flags
	, unsigned char *buf);

extern int cob_sys_close_file(
	  unsigned char *file_handle);

extern int cob_sys_flush_file(
	  unsigned char *file_handle);






extern int cob_sys_change_dir(
	  unsigned char *dir);

extern int cob_sys_check_file_exist(
	  unsigned char *file_name
	, unsigned char *file_info);

extern int cob_sys_copy_file(
	  unsigned char *fname1
	, unsigned char *fname2);

extern int cob_sys_create_dir(unsigned char *dir);

extern int cob_sys_delete_dir(unsigned char *dir);

extern int cob_sys_delete_file(unsigned char *file_name);


extern int cob_sys_expand_filename(
	  unsigned char *filename_ip
	, unsigned char *cb_filename_max
	, unsigned char *filename_op);

extern int cob_sys_get_current_dir(
	  unsigned char *flags
	, unsigned char *dir_length
	, unsigned char *dir);

extern int cob_sys_get_envvar(
	  unsigned char *var_name 
	, unsigned char *cb_value_max
	, unsigned char *var_value);

extern int cob_sys_purge_dir(unsigned char *dir);

extern int cob_sys_rename_file(
	  unsigned char *fname1
	, unsigned char *fname2);

extern int cob_sys_report_io_exception(void);


extern int cob_sys_trace_fileio(
	  unsigned char *new_trace_level); 



extern int cob_sys_mkdir(
	  unsigned char *dir);

extern int cob_sys_chdir(
	  unsigned char *dir
	, unsigned char *status);

extern int cob_sys_copyfile(
	  unsigned char *fname1
	, unsigned char *fname2
	, unsigned char *file_type);

extern int cob_sys_file_info(
	  unsigned char *file_name
	, unsigned char *file_info);

extern int cob_sys_file_delete(
	  unsigned char *file_name
	, unsigned char *file_type);





#endif   // FILEIO_CALL_H


