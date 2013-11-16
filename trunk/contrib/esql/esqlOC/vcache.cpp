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

#ifdef _MSC_VER
	#pragma warning(disable: 4996)
#endif

#include "vcache.h"

GC string::gc;

string & operator +(const char * s2, string & s1) {
	int l = (int) strlen(s2);
	string * s = new string();
	s->addgc();
	s->v = new char[s1.Length+l+1];
	if(l > 0) memcpy(s->v, s2, l+1);
	if(s1.Length > 0) memcpy(s->v + l, s1.v, s1.Length+1);
	s->Length = s1.Length + l;
	return *s;
}

string & operator +(char c2, string & s1) {
	string * s = new string();
	s->addgc();
	s->v = new char[s1.Length+2];
	s->v[0] = c2;
	s->v[1] = 0;
	if(s1.Length > 0) memcpy(s->v + 1, s1.v, s1.Length+1);
	s->Length = s1.Length + 1;
	return *s;
}

void GC::clear() {
	dontremove = true;
	for(int i = 0; i < SZ; ++i) {
		for(gclist * h = data[i]; h != NULL;) {
			gclist * h2 = h;
			h = h->next;
			string * s = h2->value;
			delete s;
			delete h2;
		}
		data[i] = NULL;
	}
	dontremove = false;
}
