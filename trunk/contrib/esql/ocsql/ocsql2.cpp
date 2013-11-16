/*
 * Copyright (C) 2006 Sergey Kashyrin <ska@kiska.net>
 *               2012 enhanced by Doug Vogel <dv11674@gmail.com>
 *               2013 fixes and enhancements by Atilla Akarsular <030ati@gmail.com>
 *
 * This runtime library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Unfortunately we need to support several database-specific calls,
 *	and the only way to do that is to rely on defines.
 * Currently for MS SQL you have to define MSSQL, and if compiler
 *	is not MSVC we are assuming DB2 on Mainframe or something compatible.
 */

#ifdef _MSC_VER

#include <windows.h>
#include <sqlext.h>
#ifdef MSSQL
#include <sqlncli.h>
#endif
#include <stdio.h>
#pragma warning(disable: 4996)

#else	// not _MSC_VER - probably __370__

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>
#include <time.h>
#include <sqlcli1.h>
#ifndef _LP64
typedef SQLINTEGER SQLLEN;
#endif

#endif	// _MSC_VER

/////////////////////////////////////////////////////////////////////////
// This is how runtime will behave in the case of switching the databases
// It is very important to remember that if those definitions are not
//  used properly, runtime might fail in a situation when the same statement
//  has been prepared for MAX_DB databases and we are trying to use more.
// At least function to set the number of reserved databases has been
//  provided to correct this situation at runtime moment before bad things happened:
//  CALL 'OCSQLMAX' USING BY VALUE "S9(7) COMP-5".
#define MAX_DB_COUNT -1
// That can be used as a shortcut if we know for sure that we will not switch
//  to another database or if we know exactly what we are doing when using "USE".
// For z/OS DB2 we manipulate SCHEMAs so instead of USE, we are checking "SET CURRENT SCHEMA".
//#define USE_NOT_USED
/////////////////////////////////////////////////////////////////////////
#define OC_DBNAME_LENGTH 64

/////////////////////////////////////////////////////////////////////////
// Logging. Define EXTERNAL_LOG if log functions are implemented somewhere
#ifdef EXTERNAL_LOG
void log(const char *format_str, ...);
void logd(int level, const char *format_str, ...);
#else // not an EXTERNAL_LOG
#ifdef _DEBUG
void log(const char *format_str, ...)
{
	va_list ap;
#ifdef _MSC_VER
	fprintf(stderr, "%d ", GetTickCount());
#else
	fprintf(stderr, "%d ", time(NULL));
#endif
	va_start(ap, format_str);
	vfprintf(stderr, format_str, ap);
	fputc('\n', stderr);
	fflush(stderr);
	va_end(ap);
}
#ifndef LOGLEVEL
#define LOGLEVEL 999
#endif
void logd(int level, const char *format_str, ...)
{
	va_list ap;
	if(level > LOGLEVEL) return;
#ifdef _MSC_VER
	fprintf(stderr, "%d ", GetTickCount());
#else
	fprintf(stderr, "%d ", time(NULL));
#endif
	va_start(ap, format_str);
	vfprintf(stderr, format_str, ap);
	fputc('\n', stderr);
	fflush(stderr);
	va_end(ap);
}
#else	// not a _DEBUG
#define log(...)
#define logd(...)
#endif	// _DEBUG
#endif	// EXTERNAL_LOG

static bool closed = true;
static bool bNTS = false;
static char dbname[OC_DBNAME_LENGTH];
static SQLHANDLE	hEnv;		// Env Handle from SQLAllocEnv
static SQLHANDLE	hDBC;		// Connection handle
static SQLHANDLE	hStmt;		// just a statement to use

extern "C" __declspec(dllexport) SQLHANDLE getOCDBCHandle() { return hDBC;}		// Hook to my system to use the same connection
extern "C" __declspec(dllexport) const char * getOCCurDBName() { return dbname;}	// Another hook to my system

struct OC_SQLCA {
	char  OC_SQLSTATE[6];
	char  OC_SQLVERSION[2];
	int   OC_SQLCODE;
	short OC_SQLERRML;
	char  OC_SQLERRMC[486];
	int   OC_SQLERRD[6];
};

////////////////////////////////////////////////////////////////////
//
struct OC_SQLV {
	int OC_SQL_ARRSZ;
	int OC_SQL_COUNT;
	void * OC_SQL_ADDR[1];	// OC_SQL_ADDR[OC_SQL_ARRSZ]
	// int OC_SQL_LEN[OC_SQL_ARRSZ]
	// char OC_SQL_TYPE[OC_SQL_ARRSZ]
	// char OC_SQL_PREC[OC_SQL_ARRSZ]
};
/*
 * And here are the possible variations of the paremeters/binded columns
 *
 * SQL-TYPE  explanation
 * ---------------------
 * 'F' - DOUBLE FLOAT.  Cobol COMP-2 == C/C++ double
 * 'I' - INTEGER.
 *       SQL-LEN == 2  Cobol S9(4)  COMP-5 == C/C++ short int (16-bit)
 *       SQL-LEN == 4  Cobol S9(8)  COMP-5 == C/C++ int (32-bit)
 *       SQL-LEN == 8  Cobol S9(18) COMP-5 == C/C++ long long (64-bit)
 * 'X' - CHAR. Cobol PIC X(SQL-LEN) followed by PIC X VALUE LOW-VALUE == C/C++ char[] (0-terminated)
 * 'V' - VARCHAR. Cobol structure. C/C++ struct { short len; char val[SQL_LEN+1];} 0-terminated.
 *         01 X.
 *           02 LEN PIC S9(4) COMP-5.
 *           02 VAL PIC X(SQL-LEN).
 *           02 FILLER PIC X VALUE LOW-VALUE.
 * 'L' - LONG VARCHAR. Cobol structure. C/C++ struct { int len; char val[SQL_LEN+1];} 0-terminated.
 *         01 X.
 *           02 LEN PIC S9(8) COMP-5.
 *           02 VAL PIC X(SQL-LEN).
 *           02 FILLER PIC X VALUE LOW-VALUE.
 * 'B' - The same as 'X' but SQL type is BINARY
 * 'v' - The same as 'V' but SQL type is BINARY
 * 'l' - The same as 'L' but SQL type is BINARY
 * '3' - DECIMAL. Cobol Packed-Decimal PIC S9(n)V9(SQL-PREC) COMP-3
 *         with "n" calculated according SQL-LEN total length in bytes.
 * 'i' - Indicator variable - always "short".
 */
//
////////////////////////////////////////////////////////////////////

#ifdef USE_NOT_USED
// doing a fake DBS which will always tell that statement is prepared for all databases
class DBS {
public:
	DBS(int maxdbnum) {}
	~DBS() {}
	int getCurrentDB() { return 0;}
	int getCount() { return 1;}
	int getMaxDBCount() { return 1;}
	void setMaxDBCount(int ct) {}
	void setCurrentDB(char * name) {}
};
#else	// USE_NOT_USED
class DBS {
private:
	int maxdb;
	int dbct;
	int dbcurr;
	int cap;
	char ** db;
public:
	DBS(int maxdbnum) {
		maxdb = maxdbnum;
		db = new char *[100];
		dbct = 0;
		cap = 100;
	}
	~DBS() {
		for(int i = 0; i < dbct; ++i) {
			delete db[i];
		}
		delete db;
	}
	int getCurrentDB() {
		return dbcurr;
	}
	int getCount() {
		return dbct;
	}
	int getMaxDBCount() {
		return maxdb;
	}
	void setMaxDBCount(int ct) {
		maxdb = ct;
	}
	void setCurrentDB(char * name) {
		for(int i = 0; i < dbct; ++i) {
			if(0 == strcmp(name, db[i])) {
				dbcurr = i;
				return;
			}
		}
		if(dbct == cap) {
			char ** db1 = new char *[cap+cap];
			memcpy(db1, db, cap * (sizeof(char *)));
			delete db;
			db = db1;
			cap += cap;
		}
		db[dbct] = new char[strlen(name)+1];
		strcpy(db[dbct], name);
		dbcurr = dbct;
		++dbct;
	}
};
#endif	// USE_NOT_USED

static DBS DBN(MAX_DB_COUNT);

extern "C" int __declspec(dllexport) OCSQLMAX(int ct) {
	DBN.setMaxDBCount(ct);
	return 0;
}

class DBL {
private:
	int ct;
	SQLHANDLE * stmt;
public:
	DBL() {
		ct = DBN.getCount();
		if(DBN.getMaxDBCount() > ct) ct = DBN.getMaxDBCount();
		stmt = new SQLHANDLE[ct];
		memset(stmt, 0, ct * sizeof(SQLHANDLE));
	}
	~DBL() {
		for(int i = 0; i < ct; ++i) {
			if(stmt[i] != 0) {
				SQLFreeStmt(stmt[i], SQL_CLOSE);
				SQLFreeHandle(SQL_HANDLE_STMT, stmt[i]);
			}
		}
		delete stmt;
	}
	bool checkall() {
		if(ct != DBN.getMaxDBCount()) return false;
		for(int i = 0; i < ct; ++i) {
			if(stmt[i] == 0) return false;
		}
		return true;
	}
	DBL & operator=(SQLHANDLE h) {
		int nc = DBN.getCurrentDB();
		if(nc >= ct) {
			SQLHANDLE * stmt1 = new SQLHANDLE[DBN.getCount()];
			memcpy(stmt1, stmt, ct * (sizeof(SQLHANDLE)));
			for(int i = ct; i < DBN.getCount(); ++i) stmt1[i] = 0;
			delete stmt;
			stmt = stmt1;
			ct = DBN.getCount();
		}
		stmt[nc] = h;
		return *this;
	}
	operator SQLHANDLE() {
		int nc = DBN.getCurrentDB();
		if(nc >= ct) {
			SQLHANDLE * stmt1 = new SQLHANDLE[DBN.getCount()];
			memcpy(stmt1, stmt, ct * (sizeof(SQLHANDLE)));
			for(int i = ct; i < DBN.getCount(); ++i) stmt1[i] = 0;
			delete stmt;
			stmt = stmt1;
			ct = DBN.getCount();
		}
		return stmt[nc];
	}
};

struct mov {
	short movenumber;
	short movetype;
	int   movelen;
	void * moveto;
};

struct mydec {
	short bytelen;
	short precision;
	char num[22];
};

class mysql {
public:
	short parmct;
	short columnct;
	short movect;
	short bufct;
	DBL * ST;
	SQLLEN * parmlen;
	SQLLEN * hostlen;
	char **  hostaddr;
	char *   hosttype;
	char **  pbuf;
	struct mov * moves;

	mysql(int pct, int cct, int mct, int bct) {
		parmct = pct;
		columnct = cct;
		movect = mct;
		bufct = bct;
		ST = NULL;
		if(parmct == 0) {
			parmlen = NULL;
		} else {
			parmlen = new SQLLEN[parmct];
		}
		if(columnct == 0) {
			hostlen = NULL;
			hostaddr = NULL;
			hosttype = NULL;
		} else {
			hostlen = new SQLLEN[columnct];
			hostaddr = new char *[columnct];
			hosttype = new char[columnct];
		}
		if(movect == 0) {
			moves = NULL;
		} else {
			moves = new struct mov[movect];
		}
		if(bufct == 0) {
			pbuf = NULL;
		} else {
			pbuf = new char *[bufct];
			for(int i = 0; i < bufct; ++i) pbuf[i] = NULL;
		}
	}
	~mysql() {
		if(parmct != 0) {
			delete parmlen;
		}
		if(columnct != 0) {
			delete hostlen;
			delete hostaddr;
			delete hosttype;
		}
		if(movect != 0) {
			delete moves;
		}
		if(bufct != 0) {
			for(int i = 0; i < bufct; ++i) {
				if(pbuf[i] != NULL) delete pbuf[i];
			}
			delete pbuf;
		}
		if(ST != 0) {
			delete ST;
		}
	}
};

struct STMT {
	mysql * SQL_IPTR;
	char    SQL_PREP;
	char    SQL_OPT;
	short   SQL_PARMS;
	short   SQL_STMLEN;
	char    SQL_STMT[1];	// actually char[SQL_STMLEN]
};

static int strim(char * buf);
static void prnerr(SQLSMALLINT ht, SQLHANDLE h, OC_SQLCA * E = NULL);
static bool getcurrdb(char * db, OC_SQLCA & E);
static bool movecomp3(char * comp3, int bytelen, int precision, char * unpacked);

static void notconn(OC_SQLCA & E)
{
	strcpy(E.OC_SQLSTATE, "08003");
	E.OC_SQLCODE = -8003;
	strcpy(E.OC_SQLERRMC, "The connection does not exist.");
	E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
}

#ifdef MSSQL
static const int nDrivers = 3;
static const char * Drivers [] = {
	"SQL Server Native Client 11.0",
	"Server=%s;UID=%s;PWD=%s;AnsiNPW=yes;APP=OpenCobol;AutoTranslate=no;Driver={SQL Server Native Client 11.0};QuotedId=yes;MARS_Connection=yes;",
	"Server=%s;Trusted_Connection=yes;AnsiNPW=yes;APP=OpenCobol;AutoTranslate=no;Driver={SQL Server Native Client 11.0};QuotedId=yes;MARS_Connection=yes;",
	"SQL Server Native Client 10.0",
	"Server=%s;UID=%s;PWD=%s;AnsiNPW=yes;APP=OpenCobol;AutoTranslate=no;Driver={SQL Server Native Client 10.0};QuotedId=yes;MARS_Connection=yes;",
	"Server=%s;Trusted_Connection=yes;AnsiNPW=yes;APP=OpenCobol;AutoTranslate=no;Driver={SQL Server Native Client 10.0};QuotedId=yes;MARS_Connection=yes;",
	"SQL Server Native Client",
	"Server=%s;UID=%s;PWD=%s;AnsiNPW=yes;APP=OpenCobol;AutoTranslate=no;Driver={SQL Native Client};QuotedId=yes;MARS_Connection=yes;",
	"Server=%s;Trusted_Connection=yes;AnsiNPW=yes;APP=OpenCobol;AutoTranslate=no;Driver={SQL Native Client};QuotedId=yes;MARS_Connection=yes;"
};
#endif

extern "C" __declspec(dllexport) int OCSQL(SQLCHAR * S, int & slen, OC_SQLCA & E)
{
	if(!closed) {
		log("OCSQL: DB Already Connected");
		strcpy(E.OC_SQLSTATE, "08002");
		E.OC_SQLCODE = 8002;
		strcpy(E.OC_SQLERRMC, "The connection already exists.");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
	}
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;

	// Allocate ODBC Environment handle
	SQLRETURN rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	if(rc != SQL_SUCCESS) {
		log("OCSQL: Can't allocate SQL Handle");
		strcpy(E.OC_SQLSTATE, "08001");
		E.OC_SQLCODE = -8001;
		strcpy(E.OC_SQLERRMC, "Can't allocate SQL Handle.");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		return E.OC_SQLCODE;
	}

	// set ODBC3 version but ignore the error
	rc = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_ENV, hEnv);
	}

	// set NTS if possible to avoid extra moves
	rc = SQLSetEnvAttr(hEnv, SQL_ATTR_OUTPUT_NTS , (SQLPOINTER) SQL_FALSE, 0);
	if(rc == SQL_SUCCESS) {
		bNTS = true;
	}

	// Allocate connection handle
	rc = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDBC);
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_ENV, hEnv, &E);
		return E.OC_SQLCODE;
	}

#ifdef _MSC_VER
	// disable connection timeout but ignore the error
	rc = SQLSetConnectAttr(hDBC, SQL_ATTR_CONNECTION_TIMEOUT, 0, 0);
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_DBC, hDBC);
	}

#ifdef MSSQL
	// enable multiple cursors
	rc = SQLSetConnectAttr(hDBC, SQL_COPT_SS_MARS_ENABLED, (SQLPOINTER)SQL_MARS_ENABLED_YES, SQL_IS_UINTEGER);
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_DBC, hDBC);
	}

	// enable ANSI NULLs
	rc = SQLSetConnectAttr(hDBC, SQL_COPT_SS_ANSI_NPW, (SQLPOINTER)SQL_AD_ON, SQL_IS_INTEGER); 
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_DBC, hDBC);
	}

	// disable cursor close on commit
	rc = SQLSetConnectAttr(hDBC, SQL_COPT_SS_PRESERVE_CURSORS, (SQLPOINTER)SQL_PC_ON, SQL_IS_INTEGER); 
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_DBC, hDBC);
	}
#endif
	// it looks we can't set isolation level as a connection attribute
	//rc = SQLSetConnectAttr(hDBC, SQL_ATTR_TXN_ISOLATION, (SQLPOINTER)ISOLATIONLEVEL_SNAPSHOT, 0);
#else
	// z/OS DB2 ODBC does not have control over timeout
#endif

	char * conn = new char[slen+1];
	memcpy(conn, S, slen);
	conn[slen] = 0;
	strim(conn);

	char * connUPR = new char[slen+1];
#if defined(_MSC_VER)
	// add another "defined" for systems with strupr
	strcpy(connUPR, conn);
	strupr(connUPR);
#else
	// Damn Mainframe does not have strupr
	char * p = connUPR;
	char * q = conn;
	do {
		*p = toupper((*q++) & 0xFF);
	} while(0 != *p++);
#endif
	bool bDriverSet = (strstr(connUPR, "DRIVER=") != NULL);
	delete connUPR;

	if(!bDriverSet) { // connection string NOT with "Driver="
		char * user = NULL;
		char * alias = strrchr(conn, '@');
		if(alias != NULL) {
			*alias++ = 0;
		}
		char * pass = strchr(conn, '/');
		if(pass != NULL) {
			*pass++ = 0;
			user = conn;
		}
		logd(9, "OCSQL: DB connect to DSN '%s' user = '%s'", alias, user);
		// Connect
		if(user != NULL) {
			rc = SQLConnect (hDBC, (SQLCHAR *)alias, SQL_NTS, (SQLCHAR *)user, SQL_NTS, (SQLCHAR *)pass, SQL_NTS);
		} else {
			rc = SQLConnect (hDBC, (SQLCHAR *)alias, SQL_NTS, 0, 0, 0, 0);
		}
		if(rc != SQL_SUCCESS) {
			prnerr(SQL_HANDLE_DBC, hDBC);	// ignore the error so far
			if(rc != SQL_SUCCESS_WITH_INFO) {
				bool bConnected = false;
#ifdef MSSQL
				for(int id = 0; id < nDrivers; ++id) {
					logd(9, "OCSQL: DB connect using %s to SERVER '%s' user = '%s'", Drivers[id*3], alias, user);
					SQLCHAR ConnStr[256];
					if(user != NULL) {
						sprintf((char *)ConnStr, Drivers[id*3+1], alias, user, pass);
					} else {
						sprintf((char *)ConnStr, Drivers[id*3+2], alias);
					}
					SQLSMALLINT sz = 0;
					rc = SQLDriverConnect(hDBC, NULL, ConnStr, SQL_NTS, NULL, 0, &sz, SQL_DRIVER_NOPROMPT);
					if(rc == SQL_SUCCESS) {
						bConnected = true;
						break;
					}
					prnerr(SQL_HANDLE_DBC, hDBC);	// print the error
					if(rc == SQL_SUCCESS_WITH_INFO) {
						bConnected = true;
						break;
					}
				}
#endif
				if(!bConnected) {
					prnerr(SQL_HANDLE_DBC, hDBC, &E);
					if(E.OC_SQLCODE == 0) E.OC_SQLCODE = -9999;
					SQLFreeConnect(hDBC);
					SQLFreeEnv(hEnv);
					delete conn;
					return E.OC_SQLCODE;
				}
			}
		}
	} else { // long connection string contains "Driver="
		SQLSMALLINT sz = 0;
		rc = SQLDriverConnect(hDBC, NULL, (SQLCHAR *)conn, SQL_NTS, NULL, 0, &sz, SQL_DRIVER_NOPROMPT);
		if(rc != SQL_SUCCESS) {
			prnerr(SQL_HANDLE_DBC, hDBC, &E);
			if(E.OC_SQLCODE == 0) E.OC_SQLCODE = -9999;
			SQLFreeConnect(hDBC);
			SQLFreeEnv(hEnv);
			delete conn;
			return E.OC_SQLCODE;
		} else {
			logd(9, "OCSQL: DB connect using SQLDriverConnect");
		}
	}
	delete conn;

	// Allocate memory for the statement handle
	rc = SQLAllocHandle(SQL_HANDLE_STMT , hDBC, &hStmt);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_DBC, hDBC, &E);
		SQLDisconnect(hDBC);
		SQLFreeConnect(hDBC);
		SQLFreeEnv(hEnv);
		log("OCSQL: DB Get Statement Handle error");
		return E.OC_SQLCODE;
	}
#if defined(SNAPSHOT)
	// force SNAPSHOT isolation
	rc = SQLExecDirect(hStmt, (SQLCHAR *) "SET TRANSACTION ISOLATION LEVEL SNAPSHOT", SQL_NTS);
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_STMT, hStmt);
	}
	SQLFreeStmt(hStmt, SQL_CLOSE);
#endif

	// try to set AUTOCOMMIT OFF
	rc = SQLSetConnectAttr(hDBC, SQL_ATTR_AUTOCOMMIT, SQL_AUTOCOMMIT_OFF, 0);
	if(rc != SQL_SUCCESS) {
		log("OCSQL: SEVERE ERROR: Can't turn autocommit OFF. Error = %d", rc);
		prnerr(SQL_HANDLE_DBC, hDBC);
	}

	if(!getcurrdb(dbname, E)) {
		SQLDisconnect(hDBC);
		SQLFreeConnect(hDBC);
		SQLFreeEnv(hEnv);
#ifdef _MSC_VER
		log("OCSQL: DB Can't get current Database name");
#else
		log("OCSQL: DB Can't get current Schema");
#endif
		return E.OC_SQLCODE;
	}
	DBN.setCurrentDB(dbname);
#ifdef _MSC_VER
	logd(1, "OCSQL: DB Connected, Database is '%s'", dbname);
#else
	logd(1, "OCSQL: DB Connected, Schema is '%s'", dbname);
#endif
	closed = false;
	return 0;
}

extern "C" __declspec(dllexport) int OCSQLDIS(OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	SQLRETURN rc = SQLEndTran(SQL_HANDLE_DBC, hDBC, SQL_COMMIT);
	if(rc != SQL_SUCCESS) {
		prnerr(SQL_HANDLE_DBC, hDBC, &E);
	} else {
		strcpy(E.OC_SQLSTATE, "00000");
		E.OC_SQLCODE = 0;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	SQLDisconnect(hDBC);
	SQLFreeConnect(hDBC);
	SQLFreeEnv(hEnv);
	closed = true;
	logd(1, "OCSQL: DB Closed");
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLPRE(OC_SQLV & V, STMT & S, OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	if(S.SQL_PREP == 'A') {
		S.SQL_PREP = 'N';
		if(S.SQL_IPTR != NULL) {
			mysql * msql = (mysql *) S.SQL_IPTR;
			S.SQL_IPTR = NULL;
			delete msql;
		}
	}
	if(S.SQL_PREP != 'N') return 0;	// already prepared
	S.SQL_PREP = 'X';
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	mysql * msql = NULL;
	if(S.SQL_IPTR != NULL) {
		msql = (mysql *) S.SQL_IPTR;
		if(0 != (SQLHANDLE) *(msql->ST)) {
			S.SQL_PREP = 'P';
			return 0;
		}
	}
	logd(901, "OCSQL: PREPARE I/O %.*s", S.SQL_STMLEN, S.SQL_STMT);
	void ** PARMADDR = & V.OC_SQL_ADDR[0];
	int * PARMLEN  = (int *)(&PARMADDR[V.OC_SQL_ARRSZ]);
	char * PARMTYPE  = (char *)(&PARMLEN[V.OC_SQL_ARRSZ]);
	char * PARMPREC = (char *)(&PARMTYPE[V.OC_SQL_ARRSZ]);
	int ct = 0;
	int bufct = 0;
	for(int i = 0; i < V.OC_SQL_COUNT; ++i) {
		if(!bNTS && i < V.OC_SQL_COUNT - S.SQL_PARMS &&
			(PARMTYPE[i] == 'X' || PARMTYPE[i] == 'V' || PARMTYPE[i] == 'L'))
		{
			++ct;
			++bufct;
		}
		if(PARMTYPE[i] == 'V' || PARMTYPE[i] == 'v' ||
			PARMTYPE[i] == 'L' || PARMTYPE[i] == 'l' || PARMTYPE[i] == '3')
		{
			++ct;
			if(PARMTYPE[i] == '3') ++bufct;
		}
	}
	if(msql == NULL) {
		msql = new mysql(V.OC_SQL_COUNT, V.OC_SQL_COUNT - S.SQL_PARMS, ct, bufct);
		msql->ST = new DBL();
		S.SQL_IPTR = msql;
	}
	mov * smov = msql->moves;
	// Allocate memory for the statement handle
	SQLHANDLE stmt;
	SQLRETURN rc = SQLAllocHandle(SQL_HANDLE_STMT , hDBC, &stmt);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_DBC, hDBC, &E);
		return E.OC_SQLCODE;
	}
	// Options
	if(S.SQL_OPT == 'H') {
#ifdef _MSC_VER
		rc = SQLSetStmtAttr(stmt, SQL_ATTR_CONCURRENCY, (SQLPOINTER)SQL_CONCUR_VALUES, SQL_IS_INTEGER);
#else
		rc = SQLSetStmtAttr(stmt, SQL_ATTR_CURSOR_HOLD, (SQLPOINTER)SQL_CURSOR_HOLD_ON, SQL_IS_INTEGER);
#endif
		if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
			prnerr(SQL_HANDLE_STMT, stmt, &E);
		}
	}
	// Prepare SQL statement
	rc = SQLPrepare(stmt, (SQLCHAR *) S.SQL_STMT, S.SQL_STMLEN);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, stmt, &E);
		SQLFreeStmt(stmt, SQL_CLOSE);
		SQLFreeHandle(SQL_HANDLE_STMT, stmt);
		return E.OC_SQLCODE;
	}
	// Bind parameters first
	SQLUSMALLINT ParmNum = 0;
	for(int i = V.OC_SQL_COUNT - S.SQL_PARMS; i < V.OC_SQL_COUNT; ++i) {
		++ParmNum;
		SQLSMALLINT ValueType;
		SQLSMALLINT ParmType;
		SQLLEN ColumnSize = PARMLEN[i];
		SQLSMALLINT DecimalDigits = 0;
		SQLLEN BufferLength = PARMLEN[i];
		msql->parmlen[i] = PARMLEN[i];
		// Correct possible moving values
		if(PARMTYPE[i] == 'V' || PARMTYPE[i] == 'v') {
			--ct;
			smov[ct].movenumber = i;
			smov[ct].movetype = -2;	// moving short to SQLLEN.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			char * a = (char *) PARMADDR[i];
			PARMADDR[i] = a + 2;
		} else if(PARMTYPE[i] == 'L' || PARMTYPE[i] == 'l') {
			--ct;
			smov[ct].movenumber = i;
			smov[ct].movetype = -4;	// moving int to SQLLEN.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			char * a = (char *) PARMADDR[i];
			PARMADDR[i] = a + 4;
		} else if(PARMTYPE[i] == '3') {
			--ct;
			--bufct;
			mydec * md;
			if(msql->pbuf[bufct] == NULL) {
				md = new mydec;
				md->bytelen = (int) PARMLEN[i];
				md->precision = PARMPREC[i];
				msql->pbuf[bufct] = (char *) md;
			} else {
				md = (mydec *) msql->pbuf[bufct];
			}
			smov[ct].movenumber = i;
			smov[ct].movetype = -3;	// moving COMP-3 to DECIMAL.
			smov[ct].movelen = bufct;
			smov[ct].moveto = PARMADDR[i];
			PARMADDR[i] = md->num;
		}
		switch(PARMTYPE[i]) {
		case 'F':
			ValueType = SQL_C_DOUBLE;
			ParmType = SQL_DOUBLE;
			ColumnSize = 53;
			break;
		case '3':
			ValueType = SQL_C_CHAR;
			ParmType = SQL_VARCHAR;
			ColumnSize = BufferLength = 21;
			msql->parmlen[i] = 21;
			break;
		case 'I':
			switch(PARMLEN[i]) {
			case 2:
				ValueType = SQL_C_SSHORT;
				ParmType = SQL_SMALLINT;
				break;
			case 4:
				ValueType = SQL_C_SLONG;
				ParmType = SQL_INTEGER;
				break;
			case 8:
				ValueType = SQL_C_SBIGINT;
				ParmType = SQL_BIGINT;
				break;
			default:
				strcpy(E.OC_SQLSTATE, "07772");
				E.OC_SQLCODE = -7772;
				sprintf(E.OC_SQLERRMC, "Prepare Internal Error. Unsupported INTEGER length %d.", PARMLEN[i]);
				E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
				SQLFreeStmt(stmt, SQL_CLOSE);
				SQLFreeHandle(SQL_HANDLE_STMT, stmt);
				return E.OC_SQLCODE;
			}
			break;
		case 'X':
		case 'V':
		case 'L':
			ValueType = SQL_C_CHAR;
			if(PARMLEN[i] >= 8000) {
				ParmType = SQL_LONGVARCHAR;
			} else {
				ParmType = SQL_VARCHAR;
			}
			break;
		case 'B':
		case 'v':
		case 'l':
			ValueType = SQL_C_BINARY;
			if(PARMLEN[i] >= 8000) {
				ParmType = SQL_LONGVARBINARY;
			} else {
				ParmType = SQL_VARBINARY;
			}
			break;
		default:
			strcpy(E.OC_SQLSTATE, "07771");
			E.OC_SQLCODE = -7771;
			sprintf(E.OC_SQLERRMC, "Prepare Internal Error. Unsupported type '%c'.", PARMTYPE[i]);
			E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
			return E.OC_SQLCODE;
		}
		rc = SQLBindParameter(stmt, ParmNum, SQL_PARAM_INPUT,
			ValueType, ParmType, ColumnSize, DecimalDigits,
			PARMADDR[i], BufferLength, &msql->parmlen[i]);
		if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
			prnerr(SQL_HANDLE_STMT, stmt, &E);
			SQLFreeStmt(stmt, SQL_CLOSE);
			SQLFreeHandle(SQL_HANDLE_STMT, stmt);
			return E.OC_SQLCODE;
		}
		if(i + 1 < V.OC_SQL_COUNT && PARMTYPE[i+1] == 'i') {	// Indicator is present
			if(*((short *)PARMADDR[i+1]) < 0) {	// NULL
				msql->parmlen[i] = SQL_NULL_DATA;
			}
			++i;
		}
	}
	// Bind columns
	ParmNum = 0;
	for(int i = 0; i < V.OC_SQL_COUNT - S.SQL_PARMS; ++i) {
		msql->hosttype[i] = PARMTYPE[i];
		if(PARMTYPE[i] == 'i') {	// Ignore indicator
			msql->hostaddr[i] = (char *) PARMADDR[i];
			continue;
		}
		++ParmNum;
		SQLLEN BufferLength = PARMLEN[i];
		msql->hostlen[i] = PARMLEN[i];
		SQLSMALLINT ValueType;
		// Correct possible moving values
		if(PARMTYPE[i] == 'V' || PARMTYPE[i] == 'v') {
			--ct;
			smov[ct].movenumber = i;
			smov[ct].movetype = 2;	// moving SQLLEN to short.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			char * a = (char *) PARMADDR[i];
			PARMADDR[i] = a + 2;
		} else if(PARMTYPE[i] == 'L' || PARMTYPE[i] == 'l') {
			--ct;
			smov[ct].movenumber = i;
			smov[ct].movetype = 4;	// moving SQLLEN to int.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			char * a = (char *) PARMADDR[i];
			PARMADDR[i] = a + 4;
		} else if(PARMTYPE[i] == '3') {
			--ct;
			--bufct;
			mydec * md;
			if(msql->pbuf[bufct] == NULL) {
				md = new mydec;
				md->bytelen = (int) PARMLEN[i];
				md->precision = PARMPREC[i];
				msql->pbuf[bufct] = (char *) md;
			} else {
				md = (mydec *) msql->pbuf[bufct];
			}
			smov[ct].movenumber = i;
			smov[ct].movetype = 3;	// moving DECIMAL to COMP-3.
			smov[ct].movelen = bufct;
			smov[ct].moveto = PARMADDR[i];
			PARMADDR[i] = & md->num;
		}
		if(!bNTS && (PARMTYPE[i] == 'X' || PARMTYPE[i] == 'V' || PARMTYPE[i] == 'L')) {
			--ct;
			--bufct;
			if(msql->pbuf[bufct] == NULL) {
				msql->pbuf[bufct] = new char[PARMLEN[i] + 1];
			}
			smov[ct].movenumber = i;
			smov[ct].movetype = 1;	// moving bytes.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			PARMADDR[i] = msql->pbuf[bufct];
		}
		switch(PARMTYPE[i]) {
		case 'F':
			ValueType = SQL_C_DOUBLE;
			break;
		case '3':
			ValueType = SQL_C_CHAR;
			BufferLength = 22;
			break;
		case 'I':
			switch(PARMLEN[i]) {
			case 2:
				ValueType = SQL_C_SSHORT;
				break;
			case 4:
				ValueType = SQL_C_SLONG;
				break;
			case 8:
				ValueType = SQL_C_SBIGINT;
				break;
			default:
				strcpy(E.OC_SQLSTATE, "07772");
				E.OC_SQLCODE = -7772;
				sprintf(E.OC_SQLERRMC, "Prepare Internal Error. Unsupported INTEGER length %d.", PARMLEN[i]);
				E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
				SQLFreeStmt(stmt, SQL_CLOSE);
				SQLFreeHandle(SQL_HANDLE_STMT, stmt);
				return E.OC_SQLCODE;
			}
			break;
		case 'X':
		case 'V':
		case 'L':
			if(!bNTS) ++BufferLength;
			ValueType = SQL_C_CHAR;
			break;
		case 'B':
		case 'v':
		case 'l':
			ValueType = SQL_C_BINARY;
			break;
		default:
			strcpy(E.OC_SQLSTATE, "07771");
			E.OC_SQLCODE = -7771;
			sprintf(E.OC_SQLERRMC, "Prepare Internal Error. Unsupported type '%c'.", PARMTYPE[i]);
			E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
			return E.OC_SQLCODE;
		}
		msql->hostaddr[i] = (char *) PARMADDR[i];
		rc = SQLBindCol(stmt, ParmNum, ValueType, PARMADDR[i], BufferLength, &msql->parmlen[i]);
		if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
			prnerr(SQL_HANDLE_STMT, stmt, &E);
			SQLFreeStmt(stmt, SQL_CLOSE);
			SQLFreeHandle(SQL_HANDLE_STMT, stmt);
			return E.OC_SQLCODE;
		}
	}
	*(msql->ST) = stmt;
	S.SQL_PREP = 'P';
	return 0;
}

extern "C" __declspec(dllexport) int OCSQLEXE(STMT & S, OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: EXECUTE %.*s", S.SQL_STMLEN, S.SQL_STMT);
	if(S.SQL_PREP != 'Y' && S.SQL_PREP != 'P') {
		if(S.SQL_PREP == 'X') {
			S.SQL_PREP = 'N';
			if(E.OC_SQLCODE != 0) return E.OC_SQLCODE;
		}
		// not prepared correctly
		strcpy(E.OC_SQLSTATE, "07777");
		E.OC_SQLCODE = -7777;
		strcpy(E.OC_SQLERRMC, "Executor Error. Statement was not Prepared Correctly");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		S.SQL_PREP = 'N';
		return E.OC_SQLCODE;
	}
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	E.OC_SQLERRD[2] = 0;
	mysql * msql = (mysql *) S.SQL_IPTR;
	mov * smov = msql->moves;
	SQLHANDLE stmt = *(msql->ST);
	if(stmt == 0) {
		// not initiated correctly
		strcpy(E.OC_SQLSTATE, "07707");
		E.OC_SQLCODE = -7707;
		strcpy(E.OC_SQLERRMC, "Executor Error. Optimization Internal error.");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		S.SQL_PREP = 'N';
		return E.OC_SQLCODE;
	}
	if(S.SQL_PREP == 'P') {
		if(msql->ST->checkall()) {
			S.SQL_PREP = 'Y';
		} else {
			S.SQL_PREP = 'N';
		}
	}
	for(int i = 0; i < msql->movect; ++i) {
		switch(smov[i].movetype) {
		case -4:
			msql->parmlen[smov[i].movenumber] = *((int *) smov[i].moveto);
			break;
		case -2:
			msql->parmlen[smov[i].movenumber] = *((short *) smov[i].moveto);
			break;
		case -3:
			{
				mydec * md = (mydec *) msql->pbuf[smov[i].movelen];
				char * c3 = (char *) smov[i].moveto;
				int iprec = md->precision;
				int ctf = 2 * md->bytelen - iprec - 1;
				int ctb = ctf/2;
				char * b = md->num;
				if((c3[md->bytelen-1] & 0x0F) == 0x0D) *b++ = '-';
				else *b++ = '+';
				while(ctb > 0) {
					*b++ = '0' + ((*c3 >> 4) & 0x0F);
					*b++ = '0' + (*c3 & 0x0F);
					++c3;
					--ctb;
				}
				if((ctf % 2) != 0) {
					*b++ = '0' + ((*c3 >> 4) & 0x0F);
					if(iprec != 0) {
						*b++ = '.';
						*b++ = '0' + (*c3 & 0x0F);
						--iprec;
					}
					++c3;
				} else {
					if(iprec != 0) *b++ = '.';
				}
				while(iprec > 0) {
					*b++ = '0' + ((*c3 >> 4) & 0x0F);
					--iprec;
					if(iprec == 0) break;
					*b++ = '0' + (*c3 & 0x0F);
					--iprec;
					++c3;
				}
				while(b < md->num + 21) *b++ = ' ';
				md->num[21] = 0;
			}
			break;
		default:
			msql->parmlen[smov[i].movenumber] = smov[i].movelen;
			break;
		}
	}

	SQLRETURN rc = SQLExecute(stmt);
	if(rc == SQL_NO_DATA) {
		strcpy(E.OC_SQLSTATE, "02000");
		E.OC_SQLCODE = 100;
		strcpy(E.OC_SQLERRMC, "NO DATA");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		SQLFreeStmt(stmt, SQL_CLOSE);
		return E.OC_SQLCODE;
	}
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, stmt, &E);
		SQLFreeStmt(stmt, SQL_CLOSE);
		return E.OC_SQLCODE;
	}
	SQLLEN rct = 0;
	SQLRowCount(stmt, &rct);
	E.OC_SQLERRD[2] = (int) rct;
	if(msql->columnct == 0) {
		SQLFreeStmt(stmt, SQL_CLOSE);
		return E.OC_SQLCODE;
	}
	rc = SQLFetch(stmt);
	if(rc == SQL_NO_DATA) {
		strcpy(E.OC_SQLSTATE, "02000");
		E.OC_SQLCODE = 100;
		strcpy(E.OC_SQLERRMC, "NO DATA");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		SQLFreeStmt(stmt, SQL_CLOSE);
		return E.OC_SQLCODE;
	}
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, stmt, &E);
		SQLFreeStmt(stmt, SQL_CLOSE);
		return E.OC_SQLCODE;
	}
	// Padding Cobol fields with a spaces, setting indicators
	for(int i = 0; i < msql->columnct; ++i) {
		int n = (int) msql->parmlen[i];
		if(n < 0) {
			if(n == SQL_NULL_DATA) {	// NULL !!!
				if(msql->hosttype[i] == '3') {
					strcpy(msql->hostaddr[i], "0");
				}
			}
			n = 0;
		}
		if(n < msql->hostlen[i] && (msql->hosttype[i] == 'B' || msql->hosttype[i] == 'X')) {
			while(n < msql->hostlen[i]) {
				msql->hostaddr[i][n] = ((msql->hosttype[i] == 'B') ? 0 : ' ');
				++n;
			}
		}
		if(i + 1 < msql->columnct && msql->hosttype[i+1] == 'i') {	// Indicator is present
			*((short *)msql->hostaddr[i+1]) = (msql->parmlen[i] == SQL_NULL_DATA) ? -1 : 0;
			++i;
		}
	}
	for(int i = 0; i < msql->movect; ++i) {
		switch(smov[i].movetype) {
		case 4:
			*((int *) smov[i].moveto) = (int) msql->parmlen[smov[i].movenumber];
			break;
		case 2:
			*((short *) smov[i].moveto) = (short) msql->parmlen[smov[i].movenumber];
			break;
		case 3:
			{
				mydec * md = (mydec *) msql->pbuf[smov[i].movelen];
				movecomp3((char *) smov[i].moveto, md->bytelen, md->precision, md->num);
			}
			break;
		case 1:
			memcpy(smov[i].moveto, msql->hostaddr[smov[i].movenumber], smov[i].movelen);
			break;
		}
	}
	SQLFreeStmt(stmt, SQL_CLOSE);
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLRBK(OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: ROLLBACK");
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	SQLRETURN rc = SQLEndTran(SQL_HANDLE_DBC, hDBC, SQL_ROLLBACK);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_DBC, hDBC, &E);
	}
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLCMT(OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: COMMIT");
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	SQLRETURN rc = SQLEndTran(SQL_HANDLE_DBC, hDBC, SQL_COMMIT);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_DBC, hDBC, &E);
	}
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLIMM(SQLCHAR * S, int & slen, OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: EXECUTE IMMEDIATE %.*s", slen, S);
	SQLHANDLE stmt;
	SQLRETURN rc = SQLAllocHandle(SQL_HANDLE_STMT , hDBC, &stmt);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_DBC, hDBC, &E);
		return E.OC_SQLCODE;
	}
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	E.OC_SQLERRD[2] = 0;
	rc = ::SQLExecDirect(stmt, S, slen);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, stmt, &E);
		SQLFreeStmt(stmt, SQL_CLOSE);
		SQLFreeHandle(SQL_HANDLE_STMT, stmt);
		return E.OC_SQLCODE;
	}
	SQLLEN rct = 0;
	SQLRowCount(stmt, &rct);
	E.OC_SQLERRD[2] = (int) rct;
	SQLFreeStmt(stmt, SQL_CLOSE);
	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
#ifdef _MSC_VER
	if(0 == _strnicmp((char *)S, "USE ", 4)) {
		if(!getcurrdb(dbname, E)) {
			log("OCSQL: DB Can't get current Database name");
			return E.OC_SQLCODE;
		}
		DBN.setCurrentDB(dbname);
	}
#else
	if(0 == strncasecmp((char *)S, "SET ", 4)) {
		char * p = (char *)(S + 4);
		while(*p == ' ') ++p;
		if(0 == strncasecmp(p, "CURRENT ", 8)) {
			p += 8;
			while(*p == ' ') ++p;
			if(0 == strncasecmp(p, "SCHEMA", 6)) {
				if(!getcurrdb(dbname, E)) {
					log("OCSQL: DB Can't get current Schema");
					return E.OC_SQLCODE;
				}
				DBN.setCurrentDB(dbname);
			}
		}
	}
#endif
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLOCU(STMT & S, OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: OPEN CURSOR %.*s", S.SQL_STMLEN, S.SQL_STMT);
	if(S.SQL_PREP != 'Y' && S.SQL_PREP != 'P') {
		if(S.SQL_PREP == 'X') {
			S.SQL_PREP = 'N';
			if(E.OC_SQLCODE != 0) return E.OC_SQLCODE;
		}
		// not prepared correctly
		strcpy(E.OC_SQLSTATE, "07777");
		E.OC_SQLCODE = -7777;
		strcpy(E.OC_SQLERRMC, "Executor Error. Statement was not Prepared Correctly");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		S.SQL_PREP = 'N';
		return E.OC_SQLCODE;
	}
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	mysql * msql = (mysql *) S.SQL_IPTR;
	mov * smov = msql->moves;
	SQLHANDLE stmt = *(msql->ST);
	if(stmt == 0) {
		// not initiated correctly
		strcpy(E.OC_SQLSTATE, "07708");
		E.OC_SQLCODE = -7708;
		strcpy(E.OC_SQLERRMC, "Open Cursor Executor Error. BT Optimization Internal error.");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		S.SQL_PREP = 'N';
		return E.OC_SQLCODE;
	}
	if(S.SQL_PREP == 'P') {
		if(msql->ST->checkall()) {
			S.SQL_PREP = 'Y';
		} else {
			S.SQL_PREP = 'N';
		}
	}
	for(int i = 0; i < msql->movect; ++i) {
		switch(smov[i].movetype) {
		case -4:
			msql->parmlen[smov[i].movenumber] = *((int *) smov[i].moveto);
			break;
		case -2:
			msql->parmlen[smov[i].movenumber] = *((short *) smov[i].moveto);
			break;
		case -3:
			{
				mydec * md = (mydec *) msql->pbuf[smov[i].movelen];
				char * c3 = (char *) smov[i].moveto;
				int iprec = md->precision;
				int ctf = 2 * md->bytelen - iprec - 1;
				int ctb = ctf/2;
				char * b = md->num;
				if((c3[md->bytelen-1] & 0x0F) == 0x0D) *b++ = '-';
				else *b++ = '+';
				while(ctb > 0) {
					*b++ = '0' + ((*c3 >> 4) & 0x0F);
					*b++ = '0' + (*c3 & 0x0F);
					++c3;
					--ctb;
				}
				if((ctf % 2) != 0) {
					*b++ = '0' + ((*c3 >> 4) & 0x0F);
					if(iprec != 0) {
						*b++ = '.';
						*b++ = '0' + (*c3 & 0x0F);
						--iprec;
					}
					++c3;
				} else {
					if(iprec != 0) *b++ = '.';
				}
				while(iprec > 0) {
					*b++ = '0' + ((*c3 >> 4) & 0x0F);
					--iprec;
					if(iprec == 0) break;
					*b++ = '0' + (*c3 & 0x0F);
					--iprec;
					++c3;
				}
				while(b < md->num + 21) *b++ = ' ';
				md->num[21] = 0;
			}
			break;
		default:
			msql->parmlen[smov[i].movenumber] = smov[i].movelen;
			break;
		}
	}

	SQLRETURN rc = SQLExecute(stmt);
	if(rc == SQL_NO_DATA) {
		strcpy(E.OC_SQLSTATE, "02000");
		E.OC_SQLCODE = 100;
		strcpy(E.OC_SQLERRMC, "NO DATA");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		SQLFreeStmt(stmt, SQL_CLOSE);
		return E.OC_SQLCODE;
	}
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, stmt, &E);
		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLFTC(OC_SQLV & V, STMT & S, OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: FETCH %.*s", S.SQL_STMLEN, S.SQL_STMT);
	SQLRETURN rc;
	mysql * sql = (mysql *) S.SQL_IPTR;
	SQLHANDLE stmt = *(sql->ST);
	if(stmt == 0) {
		// cursor in invalid state
		strcpy(E.OC_SQLSTATE, "07705");
		E.OC_SQLCODE = -7705;
		strcpy(E.OC_SQLERRMC, "Executor Error. Cursor is not in a valid state.");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		return E.OC_SQLCODE;
	}
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	void ** PARMADDR = & V.OC_SQL_ADDR[0];
	int * PARMLEN  = (int *)(&PARMADDR[V.OC_SQL_ARRSZ]);
	char * PARMTYPE  = (char *)(&PARMLEN[V.OC_SQL_ARRSZ]);
	char * PARMPREC = (char *)(&PARMTYPE[V.OC_SQL_ARRSZ]);
	int ct = 0;
	int bufct = 0;
	for(int i = 0; i < V.OC_SQL_COUNT; ++i) {
		if(!bNTS && (PARMTYPE[i] == 'X' || PARMTYPE[i] == 'V' || PARMTYPE[i] == 'L'))
		{
			++ct;
			++bufct;
		}
		if(PARMTYPE[i] == 'V' || PARMTYPE[i] == 'v' ||
			PARMTYPE[i] == 'L' || PARMTYPE[i] == 'l' || PARMTYPE[i] == '3')
		{
			++ct;
			if(PARMTYPE[i] == '3') ++bufct;
		}
	}
	// allocate out internal handle
	mysql * msql = new mysql(V.OC_SQL_COUNT, V.OC_SQL_COUNT, ct, bufct);
	mov * smov = msql->moves;
	// Bind columns
	SQLUSMALLINT ParmNum = 0;
	for(int i = 0; i < V.OC_SQL_COUNT; ++i) {
		msql->hosttype[i] = PARMTYPE[i];
		if(PARMTYPE[i] == 'i') {	// Ignore indicator
			msql->hostaddr[i] = (char *) PARMADDR[i];
			continue;
		}
		++ParmNum;
		SQLLEN BufferLength = PARMLEN[i];
		msql->hostlen[i] = PARMLEN[i];
		SQLSMALLINT ValueType;
		// Correct possible moving values
		if(PARMTYPE[i] == 'V' || PARMTYPE[i] == 'v') {
			--ct;
			smov[ct].movenumber = i;
			smov[ct].movetype = 2;	// moving SQLLEN to short.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			char * a = (char *) PARMADDR[i];
			PARMADDR[i] = a + 2;
		} else if(PARMTYPE[i] == 'L' || PARMTYPE[i] == 'l') {
			--ct;
			smov[ct].movenumber = i;
			smov[ct].movetype = 4;	// moving SQLLEN to int.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			char * a = (char *) PARMADDR[i];
			PARMADDR[i] = a + 4;
		} else if(PARMTYPE[i] == '3') {
			--ct;
			--bufct;
			mydec * md;
			if(msql->pbuf[bufct] == NULL) {
				md = new mydec;
				msql->pbuf[bufct] = (char *) md;
			} else {
				md = (mydec *) msql->pbuf[bufct];
			}
			md->bytelen = PARMLEN[i];
			md->precision = PARMPREC[i];
			smov[ct].movenumber = i;
			smov[ct].movetype = 3;	// moving DECIMAL to COMP-3.
			smov[ct].movelen = bufct;
			smov[ct].moveto = PARMADDR[i];
			PARMADDR[i] = & md->num;
		}
		if(!bNTS && (PARMTYPE[i] == 'X' || PARMTYPE[i] == 'V' || PARMTYPE[i] == 'L')) {
			--ct;
			--bufct;
			if(msql->pbuf[bufct] == NULL) {
				msql->pbuf[bufct] = new char[PARMLEN[i] + 1];
			} else if(smov[ct].movelen < PARMLEN[i]) {
				delete msql->pbuf[bufct];
				msql->pbuf[bufct] = new char[PARMLEN[i] + 1];
			}
			smov[ct].movenumber = i;
			smov[ct].movetype = 1;	// moving bytes.
			smov[ct].movelen = (int) PARMLEN[i];
			smov[ct].moveto = PARMADDR[i];
			PARMADDR[i] = msql->pbuf[bufct];
		}
		switch(PARMTYPE[i]) {
		case 'F':
			ValueType = SQL_C_DOUBLE;
			break;
		case '3':
			ValueType = SQL_C_CHAR;
			BufferLength = 22;
			break;
		case 'I':
			switch(PARMLEN[i]) {
			case 2:
				ValueType = SQL_C_SSHORT;
				break;
			case 4:
				ValueType = SQL_C_SLONG;
				break;
			case 8:
				ValueType = SQL_C_SBIGINT;
				break;
			default:
				strcpy(E.OC_SQLSTATE, "07772");
				E.OC_SQLCODE = -7772;
				sprintf(E.OC_SQLERRMC, "Bind Internal Error. Unsupported INTEGER length %d.", PARMLEN[i]);
				E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
				SQLFreeStmt(stmt, SQL_CLOSE);
				delete msql;
				return E.OC_SQLCODE;
			}
			break;
		case 'X':
		case 'V':
		case 'L':
			if(!bNTS) ++BufferLength;
			ValueType = SQL_C_CHAR;
			break;
		case 'B':
		case 'v':
		case 'l':
			ValueType = SQL_C_BINARY;
			break;
		default:
			strcpy(E.OC_SQLSTATE, "07771");
			E.OC_SQLCODE = -7771;
			sprintf(E.OC_SQLERRMC, "Bind Internal Error. Unsupported type '%c'.", PARMTYPE[i]);
			E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
			delete msql;
			return E.OC_SQLCODE;
		}
		msql->hostaddr[i] = (char *) PARMADDR[i];
		rc = SQLBindCol(stmt, ParmNum, ValueType, PARMADDR[i], BufferLength, &msql->parmlen[i]);
		if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
			prnerr(SQL_HANDLE_STMT, stmt, &E);
			delete msql;
			return E.OC_SQLCODE;
		}
	}
	rc = SQLFetch(stmt);
	if(rc == SQL_NO_DATA) {
		strcpy(E.OC_SQLSTATE, "02000");
		E.OC_SQLCODE = 100;
		strcpy(E.OC_SQLERRMC, "NO DATA");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		delete msql;
		return E.OC_SQLCODE;
	}
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, stmt, &E);
		delete msql;
		return E.OC_SQLCODE;
	}
	// Padding Cobol fields with a spaces
	for(int i = 0; i < msql->columnct; ++i) {
		int n = (int) msql->parmlen[i];
		if(n < 0) {
			if(n == SQL_NULL_DATA) {	// NULL !!!
				if(msql->hosttype[i] == '3') {
					strcpy(msql->hostaddr[i], "0");
				}
			}
			n = 0;
		}
		if(n < msql->hostlen[i] && (msql->hosttype[i] == 'B' || msql->hosttype[i] == 'X')) {
			while(n < msql->hostlen[i]) {
				msql->hostaddr[i][n] = ((msql->hosttype[i] == 'B') ? 0 : ' ');
				++n;
			}
		}
		if(i + 1 < msql->columnct && msql->hosttype[i+1] == 'i') {	// Indicator is present
			*((short *)msql->hostaddr[i+1]) = (msql->parmlen[i] == SQL_NULL_DATA) ? -1 : 0;
			++i;
		}
	}
	for(int i = 0; i < msql->movect; ++i) {
		switch(smov[i].movetype) {
		case 4:
			*((int *) smov[i].moveto) = (int) msql->parmlen[smov[i].movenumber];
			break;
		case 2:
			*((short *) smov[i].moveto) = (short) msql->parmlen[smov[i].movenumber];
			break;
		case 3:
			{
				mydec * md = (mydec *) msql->pbuf[smov[i].movelen];
				movecomp3((char *) smov[i].moveto, md->bytelen, md->precision, md->num);
			}
			break;
		case 1:
			memcpy(smov[i].moveto, msql->hostaddr[smov[i].movenumber], smov[i].movelen);
			break;
		}
	}
	delete msql;
	return E.OC_SQLCODE;
}

extern "C" __declspec(dllexport) int OCSQLCCU(STMT & S, OC_SQLCA & E)
{
	if(closed) {
		notconn(E);
		return E.OC_SQLCODE;
	}
	logd(901, "OCSQL: CLOSE CURSOR %.*s", S.SQL_STMLEN, S.SQL_STMT);
	mysql * msql = (mysql *) S.SQL_IPTR;
	SQLHANDLE stmt = *(msql->ST);
	if(stmt == 0) {
		// cursor in invalid state
		strcpy(E.OC_SQLSTATE, "07705");
		E.OC_SQLCODE = -7705;
		strcpy(E.OC_SQLERRMC, "Executor Error. Cursor is not in a valid state on Close.");
		E.OC_SQLERRML = (short) strlen(E.OC_SQLERRMC);
		return E.OC_SQLCODE;
	}
	strcpy(E.OC_SQLSTATE, "00000");
	E.OC_SQLCODE = 0;
	SQLFreeStmt(stmt, SQL_CLOSE);
	return E.OC_SQLCODE;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Internal static functions
static int strim(char * buf) {
	int len = (int) strlen(buf);
	if(len == 0) return 0;
	while(len > 0) {
		if(buf[len-1] != '\n' && buf[len-1] != '\r' &&
			buf[len-1] != ' ' && buf[len-1] != '\t')
		{
			break;
		}
		buf[--len] = 0;
	}
	if(len == 0) return 0;
	while(buf[0] == ' ') {
		strcpy(buf, buf+1);
		--len;
	}
	return len;
}

static void prnerr(SQLSMALLINT ht, SQLHANDLE h, OC_SQLCA * E)
{
	bool codewasset = false;
	for(SQLSMALLINT i = 1; ; ++i) {
		SQLSMALLINT	elen;
		SQLINTEGER err;
		SQLCHAR errs[486];
		SQLCHAR state[6];
		SQLRETURN rc = SQLGetDiagRec(ht, h, i, state, &err, errs, sizeof errs, &elen);
		if(rc == SQL_NO_DATA) return;
		if(E != NULL) {
			state[5] = 0;
			if(state[0] != '0' || (state[1] != '0' && state[1] != '1')) {
				if(i == 1 || E->OC_SQLCODE == 0 || !codewasset) {
					if(err == 0) {
						E->OC_SQLCODE = - atoi((char *)state);
					} else {
						E->OC_SQLCODE = - err;
						codewasset = true;
					}
					E->OC_SQLERRML = elen;
					errs[(sizeof errs)-1] = 0;
					strcpy(E->OC_SQLERRMC, (char *) errs);
					memcpy(E->OC_SQLSTATE, state, 6);
				}
				if(err != 2627) {
					log("OCSQL: SQL code %d : %s : %s", err, state, errs);
				} else {
					logd(190, "OCSQL: SQL code %d : %s : %s", err, state, errs);
				}
			} else {
				logd(190, "OCSQL: SQL code %d : %s : %s", err, state, errs);
			}
		} else {
			log("OCSQL: SQL code %d : %s : %s", err, state, errs);
		}
	}
}

static bool getcurrdb(char * db, OC_SQLCA & E)
{
#ifdef _MSC_VER
	SQLSMALLINT buflength = OC_DBNAME_LENGTH;
	// SQLGetInfo() (ODBC 1.0) we could also use SQLGetConnectAttr() with SQL_ATTR_CURRENT_CATALOG (ODBC 3.0)
	SQLRETURN rc = SQLGetInfo(hDBC, SQL_DATABASE_NAME, db, buflength, &buflength);
	if(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
		return true;
	}
#ifdef MSSQL
	rc = SQLPrepare (hStmt, (SQLCHAR *) "SELECT DB_NAME()", SQL_NTS);
#else
	rc = SQLPrepare (hStmt, (SQLCHAR *) "SELECT DATABASE()", SQL_NTS);
#endif
#else	// _MSC_VER
	SQLRETURN rc = SQLPrepare (hStmt, (SQLCHAR *) "SELECT CURRENT SCHEMA FROM SYSIBM.SYSDUMMY1", SQL_NTS);
#endif
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, hStmt, &E);
		SQLFreeStmt(hStmt, SQL_CLOSE);
		return false;
	}
	SQLLEN slen = OC_DBNAME_LENGTH;
	rc = SQLBindCol(hStmt, 1, SQL_C_CHAR, db, OC_DBNAME_LENGTH, &slen);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, hStmt, &E);
		SQLFreeStmt(hStmt, SQL_CLOSE);
		return false;
	}
	rc = SQLExecute(hStmt);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, hStmt, &E);
		SQLFreeStmt(hStmt, SQL_CLOSE);
		return false;
	}
	rc = SQLFetch(hStmt);
	if(rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, hStmt, &E);
		SQLFreeStmt(hStmt, SQL_CLOSE);
		return false;
	}
	if(rc == SQL_SUCCESS_WITH_INFO) {
		prnerr(SQL_HANDLE_STMT, hStmt);
	}
	SQLFreeStmt(hStmt, SQL_CLOSE);
	return true;
}

static bool movecomp3(char * comp3, int bytelen, int precision, char * unpacked)
{
	bool positive = true;
	char * p = unpacked;
	if(*p == '+') {
		++p;
	} else if(*p == '-') {
		++p;
		positive = false;
	}
	char * pt = strchr(p, '.');
	char * pw = pt;
	if(pw == NULL) {
		pw = p + strlen(p);
	} else {
		++pt;
	}
	memset(comp3, 0, bytelen);
	int ctf = 2 * bytelen - precision - 1;
	int ctb = ctf/2;
	char * px = comp3 + ctb;
	if((ctf % 2) != 0) {
		if(pw > p) {
			--pw;
			*px = ((*pw & 0x0F) << 4);
		}
	}
	--px;
	while(ctb > 0) {
		if(pw <= p) break;
		--pw;
		*px = (*pw & 0x0F);
		if(pw <= p) break;
		--pw;
		*px |= ((*pw & 0x0F) << 4);
		--px;
		--ctb;
	}
	pw = comp3 + bytelen;
	if(pt != NULL) {
		ctb = ctf/2;
		px = comp3 + ctb;
		if((ctf % 2) != 0) {
			if(*pt != 0) {
				*px |= (*pt & 0x0F);
				++pt;
			}
			++px;
		}
		while(px < pw) {
			if(*pt == 0) break;
			*px = ((*pt & 0x0F) << 4);
			++pt;
			if(*pt == 0) break;
			*px |= (*pt & 0x0F);
			++pt;
			++px;
		}
		if(px == pw) {	// rounding
			--px;
			if((*px & 0x0F) >= 5) {
				if(((*px >> 4) & 0x0F) == 9) {
					*px &= 0x0F;
					while(px > comp3) {
						--px;
						if((*px & 0x0F) == 9) {
							*px &= 0xF0;
							if(((*px >> 4) & 0x0F) == 9) {
								*px = 0;
								continue;
							}
							*px += 0x10;
							break;
						}
						*px += 0x01;
						break;
					}
				} else {
					*px += 0x10;
				}
			}
		}
	}
	--pw;
	*pw &= 0xF0;
	if(positive) {
		*pw |= 0x0C;
	} else {
		*pw |= 0x0D;
	}
	return true;
}
