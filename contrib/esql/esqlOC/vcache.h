/*
 * Copyright (C) 2006 Sergey Kashyrin <ska@kiska.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 */

#if !defined(_INC_VCACHE)
#define _INC_VCACHE

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __370__
#include <ctype.h>

static inline char * strupr (char * p) {
	char * s = p;
	while(*s != 0) {
		if(islower(*s & 0xFF)) *s = toupper(*s & 0xFF);
		++s;
	}
	return p;
}

#endif

class string;

////////////////////////////////////////////////////////////////////
// garbage collection

class GC {
private:
	friend class string;
	struct gclist {
		gclist *	next;
		string *	value;
	} **			data;
	int				SZ;			// size of cache tables
	bool			dontremove;

protected:
	GC(int sz = 1009) {
		SZ = sz;
		data = new gclist *[SZ];
		for(int i = 0; i < SZ; ++i) data[i] = NULL;
		dontremove = false;
	}
	~GC() {
		clear();
		delete data;
		dontremove = true;
	}
	void clear();
	void add(string * s) {
		int i = ((unsigned int)(unsigned long long) s) % SZ;
		gclist * h = data[i];
		if(h == NULL) {
			data[i] = new gclist();
			data[i]->next = NULL;
			data[i]->value = s;
			return;
		}
		while(h->next != NULL) {
			if(h->value == s) return;
			h = h->next;
		}
		if(h->value == s) return;
		h->next = new gclist();
		h->next->next = NULL;
		h->next->value = s;
	}
	void remove(string * s) {
		if(dontremove) return;
		int i = ((unsigned int)(unsigned long long) s) % SZ;
		gclist * h = data[i];
		if(h == NULL) return;
		if(h->value == s) {
			data[i] = h->next;
			delete h;
			return;
		}
		while(h->next != NULL) {
			if(h->next->value == s) {
				gclist * h2 = h->next;
				h->next = h2->next;
				delete h2;
				return;
			}
			h = h->next;
		}
	}
};


////////////////////////////////////////////////////////////////////
// string class
class string {
private:
	char * v;
	int Length;
	static GC gc;

public:
	string() {
		v = NULL;
		Length = 0;
	}
	string(const char * s) {
		if(s == NULL) {
			Length = 0;
			v = NULL;
			return;
		}
		Length = (int) strlen(s);
		v = new char[Length+1];
		memcpy(v, s, Length+1);
	}
	string(string & s) {
		if(s.Length == 0) {
			Length = 0;
			v = NULL;
			return;
		}
		Length = s.Length;
		v = new char[Length+1];
		memcpy(v, s.v, Length+1);
	}
	~string() {
		gc.remove(this);
		if(v != NULL) delete v;
	}

	int length() { return Length;}
	void addgc() {
		gc.add(this);
	}
	static void cleargc() {
		gc.clear();
	}

	char & operator[](int i) { return v[i];}
	operator const char *() { return v; }

	string & operator +=(string & s) {
		if(s.Length == 0) return *this;
		if(Length == 0) {
			if(v != NULL) delete v;
			v = new char[s.Length + 1];
			memcpy(v, s.v, s.Length+1);
			Length = s.Length;
			return *this;
		}
		char * ss = v;
		v = new char[Length + s.Length + 1];
		memcpy(v, ss, Length);
		memcpy(v+Length, s.v, s.Length + 1);
		Length += s.Length;
		delete ss;
		return *this;
	}

	string & operator +=(int n) {
		char buf[30];
		sprintf(buf, "%d", n);
		int l = (int) strlen(buf);
		if(Length == 0) {
			if(v != NULL) delete v;
			v = new char[l + 1];
			memcpy(v, buf, l+1);
			Length = l;
			return *this;
		}
		char * ss = v;
		v = new char[Length + l + 1];
		memcpy(v, ss, Length);
		memcpy(v+Length, buf, l + 1);
		Length += l;
		delete ss;
		return *this;
	}

	string & operator +=(char c) {
		if(Length == 0) {
			if(v != NULL) delete v;
			v = new char[2];
			v[0] = c;
			v[1] = 0;
			Length = 1;
			return *this;
		}
		char * ss = v;
		v = new char[Length + 2];
		memcpy(v, ss, Length);
		v[Length++] = c;
		v[Length] = 0;
		delete ss;
		return *this;
	}

	string & operator +=(const char * s) {
		int l = (int) strlen(s);
		if(l == 0) return *this;
		if(Length == 0) {
			if(v != NULL) delete v;
			v = new char[l + 1];
			memcpy(v, s, l+1);
			Length = l;
			return *this;
		}
		char * ss = v;
		v = new char[Length + l + 1];
		memcpy(v, ss, Length);
		memcpy(v+Length, s, l + 1);
		Length += l;
		delete ss;
		return *this;
	}

	string & operator =(string & s) {
		if(v != NULL) delete v;
		Length = s.Length;
		if(Length == 0) {
			v = NULL;
			return *this;
		}
		v = new char[Length + 1];
		memcpy(v, s.v, Length+1);
		return *this;
	}

	string & operator =(const char * s) {
		if(v != NULL) delete v;
		Length = (int) strlen(s);
		if(Length == 0) {
			v = NULL;
			return *this;
		}
		v = new char[Length + 1];
		memcpy(v, s, Length+1);
		return *this;
	}

	string & operator =(char c) {
		if(v != NULL) delete v;
		v = new char[2];
		v[0] = c;
		v[1] = 0;
		Length = 1;
		return *this;
	}

	string & operator +(string & s2) {
		string * s = new string();
		s->addgc();
		s->v = new char[Length+s2.Length+1];
		if(Length > 0) memcpy(s->v, v, Length+1);
		if(s2.Length > 0) memcpy(s->v + Length, s2.v, s2.Length+1);
		s->Length = Length + s2.Length;
		return *s;
	}

	friend string & operator +(const char * s2, string & s);

	string & operator +(const char * s2) {
		int l = (int) strlen(s2);
		string * s = new string();
		s->addgc();
		s->v = new char[Length+l+1];
		if(Length > 0) memcpy(s->v, v, Length+1);
		if(l > 0) memcpy(s->v + Length, s2, l+1);
		s->Length = Length + l;
		return *s;
	}

	friend string & operator +(char c2, string & s);

	string & operator +(char c2) {
		string * s = new string();
		s->addgc();
		s->v = new char[Length+2];
		if(Length > 0) memcpy(s->v, v, Length);
		s->v[Length] = c2;
		s->v[Length+1] = 0;
		s->Length = Length + 1;
		return *s;
	}

	bool operator ==(const char * s) {
		int l = (int) strlen(s);
		if(Length != l) return false;
		if(l == 0) return true;
		if(0 == memcmp(v, s, l)) return true;
		return false;
	}

	void trim(int len) {
		if(Length > len) {
			Length = len;
			v[len] = 0;
		}
	}

	string & substr(int start, int len = -1) {
		string * s;
		if(Length > start && len != 0) {
			s = new string(v + start);
			if(len > 0) {
				s->trim(len);
			}
		} else {
			s = new string();
		}
		s->addgc();
		return *s;
	}

	void rtrim() {
		if(Length == 0) return;
		while(--Length >= 0) {
			if(v[Length] > ' ') {	// ASCII dependent !!!
				break;
			}
		}
		++Length;
		v[Length] = 0;
	}

	int indexof(char c, int start = 0) {
		if(start >= Length) return -1;
		char * p = strchr(v+start, c);
		if(p == NULL) return -1;
		return (int)(p - v);
	}

	int indexof(const char * s, int start = 0) {
		if(start >= Length) return -1;
		char * p = strstr(v+start, s);
		if(p == NULL) return -1;
		return (int)(p - v);
	}

	void trim() {
		if(v == NULL) return;
		while(Length > 0 && v[0] <= ' ') {
			strcpy(v, v+1);
			--Length;
		}
		rtrim();
	}

	void toupper() {
		if(v == NULL) return;
		strupr(v);
	}

	bool starts(const char * s) {
		if(v == NULL) return false;
		if(0 == strncmp(v, s, strlen(s))) return true;
		return false;
	}
	void deblank() {
		if(Length == 0) return;
		bool bQ = false;
		for(int i = 0; i < Length - 1; ++i) {
			if(v[i] == '\'') bQ = !bQ;
			if(bQ) continue;
			if(v[i] == ' ' && v[i + 1] == ' ') {
				strcpy(v+i, v+i+1);
				--i;
				--Length;
			}
		}
	}
};

string & operator +(const char * s2, string & s1);
string & operator +(char c2, string & s1);

////////////////////////////////////////////////////////////////////
// string array - sarray

class sarray {
private:
	int		asz;
	int		sz;
	char **	value;

	void increase() {
		char ** v = new char *[asz + asz];
		memcpy(v, value, asz * (sizeof(char *)));
		delete value;
		value = v;
		asz *= 2;
	}

	static int compare(const void * v1, const void * v2) {
		char * h1 = * (char **) v1;
		char * h2 = * (char **) v2;
		return strcmp(h1, h2);
	}

public:
	sarray(int szinit = 10) {
		if(szinit <= 0) szinit = 10;
		asz = szinit;
		sz = 0;
		value = new char *[szinit];
	}
	~sarray() {
		for(int i = 0; i < sz; ++i) delete value[i];
		delete value;
	}
	int add(const char * s) {
		if(sz == asz) increase();
		int ct = (int) strlen(s) + 1;
		value[sz] = new char[ct];
		memcpy(value[sz], s, ct);
		++sz;
		return sz - 1;
	}
	bool contains(const char * s) {
		for(int i = 0; i < sz; ++i) {
			if(0 == strcmp(s, value[i])) {
				return true;
			}
		}
		return false;
	}
	void sort() {
		qsort(value, sz, sizeof (char *), &compare);
	}
	void insert(int i, const char * s) {
		if(i < 0) i = 0;
		if(i >= sz) {
			add(s);
			return;
		}
		if(sz == asz) increase();
		memmove(value+i+1, value+i, (sz - i)*(sizeof(void *)));
		int ct = (int) strlen(s) + 1;
		value[i] = new char[ct];
		memcpy(value[i], s, ct);
		++sz;
	}
	int size() { return sz;}
	char * operator[](int i) { return value[i];}
};

////////////////////////////////////////////////////////////////////
// cobline - element of array of the lines of Cobol program
class cobline
{
public:
	string line;
	int lineno;
	bool bComment;
	bool bSQL;
	int sqlaction;
	int sqlnum;
	string * sql;
	char * fname;

	cobline(const char * s) : line(s)
	{
		lineno = 0;
		bComment = false;
		bSQL = false;
		sqlaction = 0;
		sqlnum = -1;
		sql = NULL;
		fname = NULL;
	}
	~cobline() {
		if(sql != NULL) delete sql;
	}
};

////////////////////////////////////////////////////////////////////
// clarray - array of cobline elements
class clarray {
private:
	int			asz;
	int			sz;
	cobline **	value;

	void increase() {
		cobline ** v = new cobline *[asz + asz];
		memcpy(v, value, asz * (sizeof(void *)));
		delete value;
		value = v;
		asz *= 2;
	}

public:
	clarray(int szinit = 10) {
		if(szinit <= 0) szinit = 10;
		asz = szinit;
		sz = 0;
		value = new cobline *[szinit];
	}
	~clarray() {
		for(int i = 0; i < sz; ++i) delete value[i];
		delete value;
	}
	int add(cobline * s) {
		if(sz == asz) increase();
		value[sz++] = s;
		return sz - 1;
	}
	void insert(int i, cobline * s) {
		if(i < 0) i = 0;
		if(i >= sz) {
			add(s);
			return;
		}
		if(sz == asz) increase();
		memmove(value+i+1, value+i, (sz - i)*(sizeof(void *)));
		value[i] = s;
		++sz;
	}
	int size() { return sz;}
	cobline * operator[](int i) { return value[i];}
};

////////////////////////////////////////////////////////////////////
// varholder - holder for SQL variables/names

class varholder {
	friend class varcache;
private:
	varholder *	next;
public:
	string name;
	char type;
	int size;
	int precision;
	bool inuse;
	varholder *	over;

	varholder(const char * s) : name(s) {
		name.toupper();
		next = NULL;
		over = NULL;
		inuse = false;
	}
};

class varcache {

private:
	varholder**	data;
	int			SZ;			// size of cache tables
	int			lastIx;
	varholder *	lastH;
	int			count;

public:
	varcache(int sz = 1009) {
		SZ = sz;
		data = new varholder *[SZ];
		for(int i = 0; i < SZ; ++i) data[i] = NULL;
		count = 0;
	}
	~varcache() {
		clear();
		delete data;
	}

private:
	int hash(const char * s)
	{
		int h = 0;
		for(int i = 0; i < 8 && *s != 0; ++i) {
			h <<= 3;
			h += (*s++ & 0x1F);
		}
		h &= 0x7FFFFFFF;
		h %= SZ;
		return h;
	}

public:
	int getCount() { return count;}

	void clear()
	{
		for(int i = 0; i < SZ; ++i) {
			for(varholder * h = data[i]; h != NULL;) {
				varholder * h2 = h;
				h = h->next;
				delete h2;
			}
			data[i] = NULL;
		}
		count = 0;
	}

	varholder * operator[](const char * s) {
		varholder v(s);
		int i = hash(v.name);
		for(varholder * h = data[i]; h != NULL; h = h->next) {
			if(h->name == v.name) return h;
		}
		return NULL;
	}

	void put(varholder * v)
	{
		int i = hash(v->name);
		if(data[i] == NULL) {
			data[i] = v;
			++count;
			return;
		}
		varholder ** h = &data[i];
		for(;;) {
			if((*h)->name == v->name) {
				v->next = (*h)->next;
				delete *h;
				*h = v;
				return;
			}
			if((*h)->next == NULL) {
				(*h)->next = v;
				++count;
				return;
			}
			h = &((*h)->next);
		}
	}

	varholder * getFirstHolder()
	{
		for(lastIx = 0; lastIx < SZ; ++lastIx) {
			if(data[lastIx] != NULL) break;
		}
		if(lastIx >= SZ) return NULL;
		lastH = data[lastIx];
		return lastH;
	}

	varholder * getNextHolder()
	{
		if(lastH == NULL) return NULL;
		lastH = lastH->next;
		if(lastH != NULL) return lastH;
		for(lastIx = lastIx+1; lastIx < SZ; ++lastIx) {
			if(data[lastIx] != NULL) break;
		}
		if(lastIx >= SZ) return NULL;
		lastH = data[lastIx];
		return lastH;
	}
};

#endif	// _INC_VCACHE
