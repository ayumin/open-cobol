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

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

#ifdef	_WIN32
/* Later pdcurses versions require define before the include for DLL build */
#define	PDC_DLL_BUILD	1
#include <io.h>
#endif

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

#if defined(HAVE_NCURSESW_NCURSES_H)
#include <ncursesw/ncurses.h>
#define COB_GEN_SCREENIO
#elif defined(HAVE_NCURSESW_CURSES_H)
#include <ncursesw/curses.h>
#define COB_GEN_SCREENIO
#elif defined(HAVE_NCURSES_H)
#include <ncurses.h>
#define COB_GEN_SCREENIO
#elif defined(HAVE_NCURSES_NCURSES_H)
#include <ncurses/ncurses.h>
#define COB_GEN_SCREENIO
#elif defined(HAVE_PDCURSES_H)
#include <pdcurses.h>
#define COB_GEN_SCREENIO
#elif defined(HAVE_CURSES_H)
#include <curses.h>
#define COB_GEN_SCREENIO
#endif

#ifdef	HAVE_CURSES_FREEALL
extern "C" void	_nc_freeall(void);
#endif

struct cob_inp_struct {
	cob_screen *	scr;
	size_t			up_index;
	size_t			down_index;
	int				this_y;
	int				this_x;
};

#define	COB_INP_FLD_MAX		512

#define	COB_CH_UL		((const chtype)'_')
#define	COB_CH_SP		((const chtype)' ')
#define	COB_CH_AS		((const chtype)'*')

/* Local variables */

static cob_global *	cobglobptr;


/* Local variables when screenio activated */

#ifdef	COB_GEN_SCREENIO
static const cob_field_attr	const_alpha_attr(COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL);
static cob_inp_struct *	cob_base_inp;
static size_t			totl_index;
static size_t			cob_has_color;
static int				global_return;
static int				cob_current_y;
static int				cob_current_x;
static cob_u32_t		cob_legacy;
static short			fore_color;
static short			back_color;
#endif

/* Local functions */

static void
cob_speaker_beep(void)
{
	int fd = fileno(stdout);
	if(fd >= 0) {
		(void)write(fd, "\a",(size_t)1);
	}
}

#ifdef	COB_GEN_SCREENIO

static void
cob_beep(void)
{
	switch(COB_BEEP_VALUE) {
	case 1:
		(void)flash();
		return;
	case 2:
		cob_speaker_beep();
		return;
	case 9:
		return;
	default:
		(void)beep();
		return;
	}
}

static void
cob_convert_key(int * keyp, const cob_u32_t field_accept)
{
	/* Map key to KEY_xxx value */
	switch(*keyp) {
	case '\n':
	case '\r':
	case '\004':
	case '\032':
		*keyp = KEY_ENTER;
		break;
	case '\t':
		*keyp = KEY_STAB;
		break;
	case '\b':
	case 0177:
		*keyp = KEY_BACKSPACE;
		break;

#ifdef	KEY_A1
		/* A1, A3, C1, C3 must be present */
	case KEY_A1:
		*keyp = KEY_HOME;
		break;
	case KEY_A3:
		*keyp = KEY_PPAGE;
		break;
	case KEY_C1:
		*keyp = KEY_END;
		break;
	case KEY_C3:
		*keyp = KEY_NPAGE;
		break;
		/* Any or all of A2, B1-3, C2 MAY be present */
		/* Note B2 ignored */
#ifdef	KEY_A2
	case KEY_A2:
		*keyp = KEY_UP;
		break;
#endif
#ifdef	KEY_B1
	case KEY_B1:
		*keyp = KEY_LEFT;
		break;
#endif
#ifdef	KEY_B3
	case KEY_B3:
		*keyp = KEY_RIGHT;
		break;
#endif
#ifdef	KEY_C2
	case KEY_C2:
		*keyp = KEY_DOWN;
		break;
#endif

#if	defined(__PDCURSES__) && defined(PADSLASH)
	case PADSLASH:
		*keyp = '/';
		break;
	case PADSTAR:
		*keyp = '*';
		break;
	case PADMINUS:
		*keyp = '-';
		break;
	case PADPLUS:
		*keyp = '+';
		break;
	case PADENTER:
		*keyp = KEY_ENTER;
		break;
#ifdef	PAD0
	case PAD0:
		*keyp = KEY_IC;
		break;
	case PADSTOP:
		*keyp = KEY_DC;
		break;
#endif	/* PAD0 */
#endif	/* __PDCURSES__ */
#endif	/* KEY_A1 */
	default:
		break;
	}

	/* Check if key should be ignored */
	switch(*keyp) {
	case KEY_STAB:
		if(field_accept) {
			*keyp = 0;
		}
		break;
	case '\033':
		if(!COB_EXTENDED_STATUS || !COB_USE_ESC) {
			*keyp = 0;
		}
		break;
	case KEY_PPAGE:
	case KEY_NPAGE:
	case KEY_PRINT:
		if(!COB_EXTENDED_STATUS) {
			*keyp = 0;
		}
		break;
	case KEY_UP:
	case KEY_DOWN:
		if(field_accept && !COB_EXTENDED_STATUS) {
			*keyp = 0;
		}
		break;
	default:
		break;
	}
}

static void
get_line_column(cob_field * fline, cob_field * fcol, int * line, int * col)
{
	getyx(stdscr, *line, *col);
	if(fline == NULL) {
		if(fcol == NULL) {
			*line = 0;
			*col = 0;
			return;
		}
		int c = cob_get_int(fcol);
		if(c > 0) {
			*col = c - 1;
		} else if(c < 0) {
			*col = 0;
		}
		return;
	}

	int p = cob_get_int(fline);
	int l, c;
	if(fcol == NULL) {
		if(fline->size == 4) {
			l = p / 100;
			c = p % 100;
		} else {
			l = p / 1000;
			c = p % 1000;
		}
	} else {
		l = p;
		c = cob_get_int(fcol);
	}
	if(l > 0) {
		*line = --l;
	} else if(l < 0) {
		*line = 0;
	}
	if(c > 0) {
		*col = --c;
	} else if(c < 0) {
		*col = 0;
	}
}

static void
cob_screen_attr(cob_field * fgc, cob_field * bgc, const int attr)
{
	int styles = 0;
	int line, column;
	attrset(A_NORMAL);
	if(attr & COB_SCREEN_BLANK_SCREEN) {
		getyx(stdscr, line, column);
		clear();
		move(line, column);
	}
	if(attr & COB_SCREEN_BLANK_LINE) {
		getyx(stdscr, line, column);
		move(line, 0);
		clrtoeol();
		move(line, column);
	}
	if(attr & COB_SCREEN_BELL) {
		cob_beep();
	}
	if(attr & COB_SCREEN_REVERSE) {
		styles |= A_REVERSE;
	}
	if(attr & COB_SCREEN_HIGHLIGHT) {
		styles |= A_BOLD;
	}
	if(attr & COB_SCREEN_BLINK) {
		styles |= A_BLINK;
	}
	if(attr & COB_SCREEN_UNDERLINE) {
		styles |= A_UNDERLINE;
	}
	if(styles) {
		attron(styles);
	}
	if(cob_has_color) {
		short fgcolor = fore_color;
		short bgcolor = back_color;
		if(fgc) {
			switch(cob_get_int(fgc)) {
			case COB_SCREEN_BLACK:
				fgcolor = COLOR_BLACK;
				break;
			case COB_SCREEN_BLUE:
				fgcolor = COLOR_BLUE;
				break;
			case COB_SCREEN_GREEN:
				fgcolor = COLOR_GREEN;
				break;
			case COB_SCREEN_CYAN:
				fgcolor = COLOR_CYAN;
				break;
			case COB_SCREEN_RED:
				fgcolor = COLOR_RED;
				break;
			case COB_SCREEN_MAGENTA:
				fgcolor = COLOR_MAGENTA;
				break;
			case COB_SCREEN_YELLOW:
				fgcolor = COLOR_YELLOW;
				break;
			case COB_SCREEN_WHITE:
				fgcolor = COLOR_WHITE;
				break;
			default:
				break;
			}
		}
		if(bgc) {
			switch(cob_get_int(bgc)) {
			case COB_SCREEN_BLACK:
				bgcolor = COLOR_BLACK;
				break;
			case COB_SCREEN_BLUE:
				bgcolor = COLOR_BLUE;
				break;
			case COB_SCREEN_GREEN:
				bgcolor = COLOR_GREEN;
				break;
			case COB_SCREEN_CYAN:
				bgcolor = COLOR_CYAN;
				break;
			case COB_SCREEN_RED:
				bgcolor = COLOR_RED;
				break;
			case COB_SCREEN_MAGENTA:
				bgcolor = COLOR_MAGENTA;
				break;
			case COB_SCREEN_YELLOW:
				bgcolor = COLOR_YELLOW;
				break;
			case COB_SCREEN_WHITE:
				bgcolor = COLOR_WHITE;
				break;
			default:
				break;
			}
		}
		int i;
		for(i = 0; i < (int)COLOR_PAIRS; i++) {
			short fgdef, bgdef;
			pair_content((short)i, &fgdef, &bgdef);
			if(fgdef == fgcolor && bgdef == bgcolor) {
				break;
			}
			if(fgdef == 0 && bgdef == 0) {
				init_pair((short)i, fgcolor, bgcolor);
				break;
			}
		}
		if(i != (int)COLOR_PAIRS) {
#ifdef	HAVE_COLOR_SET
			color_set((short)COLOR_PAIR(i), NULL);
#else
			attrset(COLOR_PAIR(i));
#endif
			bkgdset(COLOR_PAIR(i));
		} else {
			if(!styles) {
				attrset(A_NORMAL);
			}
		}
	}
	if(attr & COB_SCREEN_ERASE_EOL) {
		clrtoeol();
	}
	if(attr & COB_SCREEN_ERASE_EOS) {
		clrtobot();
	}
}

static void
cob_screen_init(void)
{
	if(cobglobptr->cob_screen_initialized) {
		return;
	}

	cob_base_inp = NULL;
	totl_index = 0;
	cob_has_color = 0;
	global_return = 0;
	cob_current_y = 0;
	cob_current_x = 0;
	cob_legacy = 0;
	fore_color = 0;
	back_color = 0;

	fflush(stdout);
	fflush(stderr);

	char * s;
	if((s = getenv("COB_LEGACY")) != NULL) {
		if(*s == 'Y' || *s == 'y' || *s == '1') {
			cob_legacy = 1U;
		}
	}

#if	0	/* RXWRXW sigtin */
#ifndef _WIN32
	/* If the process is backgrounded(running non interactively), */
	/* SIGTTIN or SIGTOU is emitted. If not caught, turns into a SIGSTP */
#ifdef	SIGTTIN
	signal(SIGTTIN, SIG_IGN);
#endif
#ifdef	SIGTTOU
	signal(SIGTTOU, SIG_IGN);
#endif
#endif
#endif

#if	0	/* RXWRXW - setlocale */
#ifdef	HAVE_SETLOCALE
	if(cobglobptr->cob_locale_orig) {
		setlocale(LC_ALL, cobglobptr->cob_locale_orig);
	}
	if(cobglobptr->cob_locale_ctype) {
		setlocale(LC_CTYPE, cobglobptr->cob_locale_ctype);
	}
#endif
#endif

	if(!initscr()) {
		cob_runtime_error(_("Failed to initialize curses"));
		cob_stop_run(1);
	}
	cobglobptr->cob_screen_initialized = 1;
#ifdef	HAVE_USE_LEGACY_CODING
	use_legacy_coding(2);
#endif

#if	0	/* RXWRXW - setlocale */
#ifdef	HAVE_SETLOCALE
	if(cobglobptr->cob_locale) {
		setlocale(LC_ALL, cobglobptr->cob_locale);
		setlocale(LC_CTYPE, "C");
	}
#endif
#endif

	cbreak();
	keypad(stdscr, 1);
	nonl();
	noecho();
	if(has_colors()) {
		start_color();
		pair_content((short)0, &fore_color, &back_color);
		if(COLOR_PAIRS) {
#ifdef	HAVE_LIBPDCURSES
			/* pdcurses sets ALL pairs to default fg/bg */
			/* IMHO a bug. */
			for(int i = 1; i < COLOR_PAIRS; ++i) {
				init_pair((short)i, 0, 0);
			}
#endif
			cob_has_color = 1;
		}
	}
	attrset(A_NORMAL);
	getmaxyx(stdscr, COB_MAX_Y_COORD, COB_MAX_X_COORD);
}

static void
cob_check_pos_status(const int fret)
{
	if(fret) {
		cob_set_exception(COB_EC_IMP_ACCEPT);
	}
	COB_ACCEPT_STATUS = fret;
	if(COB_MODULE_PTR->crt_status) {
		if(COB_FIELD_IS_NUMERIC(COB_MODULE_PTR->crt_status)) {
			cob_set_int(COB_MODULE_PTR->crt_status, fret);
		} else {
			char datbuf[8];
			sprintf(datbuf, "%4.4d", fret);
			memcpy(COB_MODULE_PTR->crt_status->data, datbuf,
				   (size_t)4);
		}
	}
	if(COB_MODULE_PTR->cursor_pos) {
		int sline, scolumn;
		getyx(stdscr, sline, scolumn);
		cob_field * f = COB_MODULE_PTR->cursor_pos;
		if(COB_FIELD_IS_NUMERIC(f) && COB_FIELD_TYPE(f) != COB_TYPE_NUMERIC_DISPLAY) {
			sline *= 1000;
			sline += scolumn;
			cob_set_int(f, sline);
		} else {
			if(f->size < 6) {
				sline *= 100;
				sline += scolumn;
				char datbuf[8];
				sprintf(datbuf, "%4.4d", sline);
				memcpy(f->data, datbuf,(size_t)4);
			} else {
				sline *= 1000;
				sline += scolumn;
				char datbuf[8];
				sprintf(datbuf, "%6.6d", sline);
				memcpy(f->data, datbuf,(size_t)6);
			}
		}
	}
}

static void
cob_screen_puts(cob_screen * s, cob_field * f, const cob_u32_t is_input)
{
	int x, y;
	getyx(stdscr, y, x);
#if	1	/* RXWRXW - Column adjust */
	if(x > 0) {
		x--;
	}
#endif
	int line, column;
	if(!s->line) {
		line = y;
	} else {
		line = cob_get_int(s->line) - 1;
		if(line < 0) {
			line = y;
		}
	}
	if(!s->column) {
		column = x;
	} else {
		column = cob_get_int(s->column) - 1;
		if(column < 0) {
			column = x;
		}
	}
	if(s->attr & COB_SCREEN_LINE_PLUS) {
		line = y + line + 1;
	} else if(s->attr & COB_SCREEN_LINE_MINUS) {
		line = y - line + 1;
	}
	if(s->attr & COB_SCREEN_COLUMN_PLUS) {
		column = x + column + 1;
	} else if(s->attr & COB_SCREEN_COLUMN_MINUS) {
		column = x - column + 1;
	}
	move(line, column);
	cob_current_y = line;
	cob_current_x = column;
#if	0	/* RXWRXW - Attr */
	cob_screen_attr(s->foreg, s->backg, s->attr);
#endif
	if(s->attr & COB_SCREEN_INPUT) {
		cob_screen_attr(s->foreg, s->backg, s->attr);
		chtype promptchar;
		if(s->prompt) {
			promptchar = s->prompt->data[0];
		} else {
			promptchar = COB_CH_UL;
		}
		unsigned char * p = f->data;
		for(size_t size = 0; size < f->size; size++, p++) {
			if(s->attr & COB_SCREEN_SECURE) {
				addch(COB_CH_AS);
			} else if(*p <= ' ') {
				addch(promptchar);
			} else {
				addch((const chtype)*p);
			}
		}
	} else if(!is_input) {
		cob_screen_attr(s->foreg, s->backg, s->attr);
		addnstr((char *)f->data,(int)f->size);
	} else {
		column += (int)f->size;
		move(line, column);
	}
	refresh();
}

static void
cob_screen_get_all(const int initial_curs, const int gettimeout)
{
	size_t curr_index = (size_t)initial_curs;
	cob_inp_struct * sptr = cob_base_inp + curr_index;
	cob_screen * s = sptr->scr;
	int sline = sptr->this_y;
	int scolumn = sptr->this_x;
	move(sline, scolumn);
	cob_screen_attr(s->foreg, s->backg, s->attr);
	bool ateof = false;
	bool gotbacksp = false;
	bool ungetched = false;
	int rightpos = scolumn + (int)s->field->size - 1;
	unsigned char * p = s->field->data;

	for(; ;) {
		chtype promptchar;
		if(s->prompt) {
			promptchar = s->prompt->data[0];
		} else {
			promptchar = COB_CH_UL;
		}

		refresh();
		errno = 0;
		timeout(gettimeout);
		int keyp = getch();

		if(keyp == ERR) {
			global_return = 8001;
			goto screen_return;
		}
		if(keyp > KEY_F0 && keyp < KEY_F(65)) {
			global_return = 1000 + keyp - KEY_F0;
			goto screen_return;
		}

		cob_convert_key(&keyp, 0);
		if(keyp <= 0) {
			(void)flushinp();
			cob_beep();
			continue;
		}

		int cline, ccolumn;
		getyx(stdscr, cline, ccolumn);

		switch(keyp) {
		case KEY_ENTER:
			goto screen_return;
		case KEY_PPAGE:
			global_return = 2001;
			goto screen_return;
		case KEY_NPAGE:
			global_return = 2002;
			goto screen_return;
		case KEY_PRINT:
			global_return = 2006;
			goto screen_return;
		case '\033':
			global_return = 2005;
			goto screen_return;
		case KEY_STAB:
			if(curr_index < totl_index - 1) {
				curr_index++;
			} else {
				curr_index = 0;
			}
			sptr = cob_base_inp + curr_index;
			s = sptr->scr;
			sline = sptr->this_y;
			scolumn = sptr->this_x;
			ateof = false;
			gotbacksp = false;
			rightpos = scolumn +(int)s->field->size - 1;
			p = s->field->data;
			move(sline, scolumn);
			cob_screen_attr(s->foreg, s->backg, s->attr);
			continue;
		case KEY_BTAB:
			if(curr_index > 0) {
				curr_index--;
			} else {
				curr_index = totl_index - 1;
			}
			sptr = cob_base_inp + curr_index;
			s = sptr->scr;
			sline = sptr->this_y;
			scolumn = sptr->this_x;
			ateof = false;
			gotbacksp = false;
			rightpos = scolumn +(int)s->field->size - 1;
			if(ungetched) {
				ungetched = false;
				p = s->field->data + rightpos;
				move(sline, rightpos);
			} else {
				p = s->field->data;
				move(sline, scolumn);
			}
			cob_screen_attr(s->foreg, s->backg, s->attr);
			continue;
		case KEY_UP:
			curr_index = sptr->up_index;
			sptr = cob_base_inp + curr_index;
			s = sptr->scr;
			sline = sptr->this_y;
			scolumn = sptr->this_x;
			ateof = false;
			gotbacksp = false;
			rightpos = scolumn +(int)s->field->size - 1;
			p = s->field->data;
			move(sline, scolumn);
			cob_screen_attr(s->foreg, s->backg, s->attr);
			continue;
		case KEY_DOWN:
			curr_index = sptr->down_index;
			sptr = cob_base_inp + curr_index;
			s = sptr->scr;
			sline = sptr->this_y;
			scolumn = sptr->this_x;
			ateof = false;
			gotbacksp = false;
			rightpos = scolumn +(int)s->field->size - 1;
			p = s->field->data;
			move(sline, scolumn);
			cob_screen_attr(s->foreg, s->backg, s->attr);
			continue;
		case KEY_HOME:
			curr_index = 0;
			sptr = cob_base_inp;
			s = sptr->scr;
			sline = sptr->this_y;
			scolumn = sptr->this_x;
			ateof = false;
			gotbacksp = false;
			rightpos = scolumn +(int)s->field->size - 1;
			p = s->field->data;
			move(sline, scolumn);
			cob_screen_attr(s->foreg, s->backg, s->attr);
			continue;
		case KEY_END:
			curr_index = totl_index - 1;
			sptr = cob_base_inp + curr_index;
			s = sptr->scr;
			sline = sptr->this_y;
			scolumn = sptr->this_x;
			ateof = false;
			gotbacksp = false;
			rightpos = scolumn +(int)s->field->size - 1;
			p = s->field->data;
			move(sline, scolumn);
			cob_screen_attr(s->foreg, s->backg, s->attr);
			continue;
		case KEY_BACKSPACE:
			if(ccolumn > scolumn) {
				if(gotbacksp || ccolumn != rightpos) {
					ccolumn--;
				} else {
					ateof = false;
				}
				gotbacksp = true;
				move(cline, ccolumn);
				if(s->attr & COB_SCREEN_SECURE) {
					addch(COB_CH_AS);
				} else {
					addch(promptchar);
				}
				move(cline, ccolumn);
				p = s->field->data + ccolumn - scolumn;
				*p = ' ';
			} else {
				ungetched = true;
				gotbacksp = false;
				ungetch(KEY_BACKSPACE);
				ungetch(KEY_BTAB);
			}
			continue;
		case KEY_LEFT:
			gotbacksp = false;
			if(ccolumn > scolumn) {
				ccolumn--;
				move(cline, ccolumn);
				p = s->field->data + ccolumn - scolumn;
			} else {
				ungetched = true;
				ungetch(KEY_BTAB);
			}
			continue;
		case KEY_RIGHT:
			gotbacksp = false;
			if(ccolumn < rightpos) {
				ccolumn++;
				move(cline, ccolumn);
				p = s->field->data + ccolumn - scolumn;
			} else {
				ungetch('\t');
			}
			continue;
		default:
			break;
		}

		if(keyp > 037 && keyp <(int)A_CHARTEXT) {
			if(COB_FIELD_IS_NUMERIC(s->field) ||
					COB_FIELD_TYPE(s->field) == COB_TYPE_NUMERIC_EDITED) {
				if(keyp < '0' || keyp > '9') {
					cob_beep();
					continue;
				}
			}
			gotbacksp = false;
			if(s->attr & COB_SCREEN_UPPER) {
				if(islower(keyp)) {
					keyp = toupper(keyp);
				}
			} else if(s->attr & COB_SCREEN_LOWER) {
				if(isupper(keyp)) {
					keyp = tolower(keyp);
				}
			}
			*p = (unsigned char)keyp;
			if(s->attr & COB_SCREEN_SECURE) {
				addch(COB_CH_AS);
			} else if(s->attr & COB_SCREEN_NO_ECHO) {
				addch(COB_CH_SP);
			} else {
				addch((const chtype)keyp);
			}
			if(ccolumn == rightpos) {
				if(s->attr & COB_SCREEN_AUTO) {
					if(curr_index == totl_index - 1) {
						goto screen_return;
					} else {
						ungetch('\t');
					}
				}
				move(cline, ccolumn);
				if(ateof) {
					cob_beep();
				} else {
					ateof = true;
				}
			} else {
				p++;
			}
			continue;
		}
		gotbacksp = false;
		(void)flushinp();
		cob_beep();
	}
screen_return:
	refresh();
}

static int
compare_yx(const void * m1, const void * m2)
{
	const cob_inp_struct * s1 = (const cob_inp_struct *) m1;
	const cob_inp_struct * s2 = (const cob_inp_struct *) m2;
	if(s1->this_y < s2->this_y) {
		return -1;
	}
	if(s1->this_y > s2->this_y) {
		return 1;
	}
	if(s1->this_x < s2->this_x) {
		return -1;
	}
	if(s1->this_x > s2->this_x) {
		return 1;
	}
	return 0;
}

static void
cob_screen_moveyx(cob_screen * s)
{
	if(s->line || s->column ||
			s->attr &(COB_SCREEN_LINE_PLUS | COB_SCREEN_LINE_MINUS |
					  COB_SCREEN_COLUMN_PLUS |COB_SCREEN_COLUMN_MINUS))
	{
		int x, y;
		getyx(stdscr, y, x);
#if	1	/* RXWRXW - Column adjust */
		if(x > 0) {
			x--;
		}
#endif
		int line, column;
		if(!s->line) {
			line = y;
		} else {
			line = cob_get_int(s->line);
			if(line < 0) {
				line = y;
			}
		}
		if(!s->column) {
			column = x;
		} else {
			column = cob_get_int(s->column);
			if(column < 0) {
				column = x;
			}
		}
		if(s->attr & COB_SCREEN_LINE_PLUS) {
			line = y + line;
		} else if(s->attr & COB_SCREEN_LINE_MINUS) {
			line = y - line;
		}
		if(s->attr & COB_SCREEN_COLUMN_PLUS) {
			column = x + column;
		} else if(s->attr & COB_SCREEN_COLUMN_MINUS) {
			column = x - column;
		}
		move(line, column);
		refresh();
		cob_current_y = line;
		cob_current_x = column;
	}
}

static size_t
cob_prep_input(cob_screen * s)
{
	switch(s->type) {
	case COB_SCREEN_TYPE_GROUP:
		cob_screen_moveyx(s);
		for(s = s->child; s; s = s->next) {
			cob_prep_input(s);
		}
		break;
	case COB_SCREEN_TYPE_FIELD:
		cob_screen_puts(s, s->field, cob_legacy);
		if(s->attr & COB_SCREEN_INPUT) {
			if(totl_index >= COB_INP_FLD_MAX) {
				return 1;
			}
			cob_inp_struct * sptr = cob_base_inp + totl_index;
			sptr->scr = s;
			sptr->this_y = cob_current_y;
			sptr->this_x = cob_current_x;
			totl_index++;
		}
		break;
	case COB_SCREEN_TYPE_VALUE:
		cob_screen_puts(s, s->value, cob_legacy);
		if(s->occurs) {
			for(int n = 1; n < s->occurs; ++n) {
				cob_screen_puts(s, s->value, cob_legacy);
			}
		}
		break;
	case COB_SCREEN_TYPE_ATTRIBUTE:
#if	0	/* RXWRXW - Attr */
		cob_screen_attr(s->foreg, s->backg, s->attr);
#endif
		break;
	default:
		break;
	}
	return 0;
}

static void
cob_screen_iterate(cob_screen * s)
{
	switch(s->type) {
	case COB_SCREEN_TYPE_GROUP:
		cob_screen_moveyx(s);
		for(s = s->child; s; s = s->next) {
			cob_screen_iterate(s);
		}
		break;
	case COB_SCREEN_TYPE_FIELD:
		cob_screen_puts(s, s->field, 0);
		break;
	case COB_SCREEN_TYPE_VALUE:
		cob_screen_puts(s, s->value, 0);
		if(s->occurs) {
			for(int n = 1; n < s->occurs; ++n) {
				cob_screen_puts(s, s->value, 0);
			}
		}
		break;
	case COB_SCREEN_TYPE_ATTRIBUTE:
		cob_screen_attr(s->foreg, s->backg, s->attr);
		break;
	default:
		break;
	}
}

/* Global functions */

void
cob_screen_display(cob_screen * s, cob_field * line, cob_field * column)
{
	if(!cobglobptr->cob_screen_initialized) {
		cob_screen_init();
	}

	int sline, scolumn;
	if(line == NULL && column == NULL) {
		getyx(stdscr, sline, scolumn);
	} else {
		get_line_column(line, column, &sline, &scolumn);
	}
	move(sline, scolumn);
	cob_screen_iterate(s);
	refresh();
}

void
cob_screen_accept(cob_screen * s, cob_field * line,
				  cob_field * column, cob_field * ftimeout)
{
	if(!cobglobptr->cob_screen_initialized) {
		cob_screen_init();
	}
	if(!cob_base_inp) {
		cob_base_inp = new cob_inp_struct[COB_INP_FLD_MAX];
	} else {
		memset(cob_base_inp, 0, COB_INP_FLD_MAX * sizeof(cob_inp_struct));
	}
	cobglobptr->cob_exception_code = 0;
	cob_current_y = 0;
	cob_current_x = 0;
	totl_index = 0;
	if(line == NULL && column == NULL) {
		move(0, 0);
	} else {
		int sline, scolumn;
		get_line_column(line, column, &sline, &scolumn);
		move(sline, scolumn);
	}

	/* Prepare input fields */
	if(cob_prep_input(s)) {
		cob_check_pos_status(9001);
		return;
	}

	/* No input field is an error */
	if(!totl_index) {
		cob_check_pos_status(8000);
		return;
	}

	int gettimeout;
	if(ftimeout) {
		gettimeout = cob_get_int(ftimeout) * COB_TIMEOUT_SCALE;
		if(gettimeout >= 0 && gettimeout < 500) {
			gettimeout = 500;
		}
	} else {
		gettimeout = -1;
	}

	/* Sort input fields on line, column */
	qsort(cob_base_inp, totl_index, sizeof(cob_inp_struct), compare_yx);

	size_t posu = 0;
	size_t posd = 0;
	size_t prevy = 0;
	size_t firsty = 0;
	cob_inp_struct * sptr = cob_base_inp;
	int starty = sptr->this_y;
	int initial_curs = -1;
	/* Set up array for Cursor UP/DOWN */
	for(size_t n = 0; n < totl_index; n++) {
		sptr = cob_base_inp + n;
		if((sptr->scr->attr & COB_SCREEN_INITIAL) && initial_curs < 0) {
			initial_curs = (int)n;
		}
		if(sptr->this_y > starty) {
			if(!firsty) {
				firsty = n;
			}
			starty = sptr->this_y;
			cob_inp_struct * sptr2 = cob_base_inp + posd;
			for(size_t idx = posd; idx < n; idx++, sptr2++) {
				sptr2->down_index = n;
			}
			posu = prevy;
			prevy = n;
			posd = n;
		}
		sptr->up_index = posu;
	}
	sptr = cob_base_inp;
	for(size_t n = 0; n < firsty; n++, sptr++) {
		sptr->up_index = posd;
	}
	global_return = 0;
	if(initial_curs < 0) {
		initial_curs = 0;
	}
	cob_screen_get_all(initial_curs, gettimeout);
	cob_check_pos_status(global_return);
}

void
cob_field_display(cob_field * f, cob_field * line, cob_field * column,
				  cob_field * fgc, cob_field * bgc, cob_field * fscroll,
				  const int fattr)
{
	if(!cobglobptr->cob_screen_initialized) {
		cob_screen_init();
	}

	if(fscroll) {
		int sline = cob_get_int(fscroll);
		if(fattr & COB_SCREEN_SCROLL_DOWN) {
			sline = -sline;
		}
		scrollok(stdscr, 1);
		scrl(sline);
		scrollok(stdscr, 0);
		refresh();
	}

	int sline, scolumn;
	if(line == NULL && column == NULL) {
		getyx(stdscr, sline, scolumn);
	} else {
		get_line_column(line, column, &sline, &scolumn);
	}
	move(sline, scolumn);

	cob_screen_attr(fgc, bgc, fattr);
	if(!(fattr & COB_SCREEN_NO_DISP)) {
		addnstr((char *)f->data,(int)f->size);
	}
	if(fattr & COB_SCREEN_EMULATE_NL) {
		if(++sline >= LINES) {
			sline = 0;
		}
		move(sline, 0);
	}
	refresh();
}

void
cob_field_accept(cob_field * f, cob_field * line, cob_field * column,
				 cob_field * fgc, cob_field * bgc, cob_field * fscroll,
				 cob_field * ftimeout, cob_field * prompt, const int fattr)
{
	memset(COB_TERM_BUFF, ' ',(size_t)COB_MEDIUM_MAX);
	cob_field temp(1, COB_TERM_BUFF, &const_alpha_attr);
#if	0	/* RXWRXW - Screen update */
	cob_field char_temp;
	unsigned char space_buff[4];
	char_temp.data = space_buff;
	char_temp.attr = &const_alpha_attr;
	char_temp.size = 1;
	space_buff[0] = ' ';
	space_buff[1] = 0;
#endif
	chtype promptchar = (prompt) ? prompt->data[0] : COB_CH_UL;

	if(!cobglobptr->cob_screen_initialized) {
		cob_screen_init();
	}

	int gettimeout;
	if(ftimeout) {
		gettimeout = cob_get_int(ftimeout) * COB_TIMEOUT_SCALE;
		if(gettimeout >= 0 && gettimeout < 500) {
			gettimeout = 500;
		}
	} else {
		gettimeout = -1;
	}

	if(fscroll) {
		int keyp = cob_get_int(fscroll);
		if(fattr & COB_SCREEN_SCROLL_DOWN) {
			keyp = -keyp;
		}
		scrollok(stdscr, 1);
		scrl(keyp);
		scrollok(stdscr, 0);
		refresh();
	}
	cobglobptr->cob_exception_code = 0;

	int sline, scolumn;
	if(line == NULL && column == NULL) {
		sline = 0;
		scolumn = 0;
#if	0	/* RXWRXW - Line / Col */
		getyx(stdscr, sline, scolumn);
#endif
	} else {
		get_line_column(line, column, &sline, &scolumn);
	}
	move(sline, scolumn);

	unsigned char * p;
	int rightpos;
	cob_screen_attr(fgc, bgc, fattr);
	if(f) {
		p = COB_TERM_BUFF;
		temp.size = f->size;
		if(fattr & COB_SCREEN_UPDATE) {
			cob_move(f, &temp);
		}
		for(size_t count = 0; count < f->size; count++) {
			if(fattr & COB_SCREEN_SECURE) {
				addch(COB_CH_AS);
			} else if(fattr & COB_SCREEN_NO_ECHO) {
				addch(COB_CH_SP);
			} else if(fattr & COB_SCREEN_UPDATE) {
				int fret = *p++;
				addch((const chtype)fret);
			} else if(fattr & COB_SCREEN_PROMPT) {
				addch(promptchar);
			} else {
				addch(COB_CH_SP);
			}
		}
		move(sline, scolumn);
#if	0	/* RXWRXW - Screen update */
		if(!(fattr & COB_SCREEN_UPDATE)) {
			if(COB_FIELD_IS_NUMERIC(f) ||
					COB_FIELD_TYPE(f) == COB_TYPE_NUMERIC_EDITED) {
				cob_set_int(f, 0);
			} else {
				cob_move(&char_temp, f);
			}
		}
#endif
		rightpos = scolumn +(int)f->size - 1;
		p = COB_TERM_BUFF;
	} else {
		rightpos = 0;
		p = NULL;
	}
	int fret = 0;
	bool ateof = false;
	bool gotbacksp = false;
	bool count = false;
	unsigned char * s;
	size_t size;

	for(; ;) {
		refresh();
		errno = 0;
		timeout(gettimeout);
		int keyp = getch();

		if(keyp == ERR) {
			fret = 8001;
			goto field_return;
		}
		if(keyp > KEY_F0 && keyp < KEY_F(65)) {
			fret = 1000 + keyp - KEY_F0;
			goto field_return;
		}

		cob_convert_key(&keyp, 1U);
		if(keyp <= 0) {
			(void)flushinp();
			cob_beep();
			continue;
		}

		int cline;
		int ccolumn;
		getyx(stdscr, cline, ccolumn);

		switch(keyp) {
		case KEY_ENTER:
			goto field_return;
		case KEY_PPAGE:
			fret = 2001;
			goto field_return;
		case KEY_NPAGE:
			fret = 2002;
			goto field_return;
		case KEY_UP:
			fret = 2003;
			goto field_return;
		case KEY_DOWN:
			fret = 2004;
			goto field_return;
		case KEY_PRINT:
			/* pdcurses not returning this ? */
			fret = 2006;
			goto field_return;
		case 033:
			fret = 2005;
			goto field_return;
		default:
			break;
		}

		if(!f) {
			(void)flushinp();
			cob_beep();
			continue;
		}

		switch(keyp) {
		case KEY_BACKSPACE:
			if(ccolumn <= scolumn) {
				gotbacksp = false;
				cob_beep();
				continue;
			}
			if(gotbacksp || ccolumn != rightpos) {
				ccolumn--;
			} else {
				ateof = false;
			}
			gotbacksp = true;
			move(cline, ccolumn);
			if(fattr & COB_SCREEN_SECURE) {
				addch(COB_CH_AS);
			} else if(fattr & COB_SCREEN_NO_ECHO) {
				addch(COB_CH_SP);
			} else if(fattr & COB_SCREEN_PROMPT) {
				addch(promptchar);
			} else {
				addch(COB_CH_SP);
			}
			move(cline, ccolumn);
			p = COB_TERM_BUFF + ccolumn - scolumn;
			*p = ' ';
			count = true;
			continue;
		case KEY_HOME:
			move(sline, scolumn);
			p = COB_TERM_BUFF;
			ateof = false;
			gotbacksp = false;
			continue;
		case KEY_END:
			move(sline, rightpos);
			p = COB_TERM_BUFF + f->size - 1;
			ateof = false;
			gotbacksp = false;
			continue;
		case KEY_LEFT:
			if(ccolumn > scolumn) {
				ccolumn--;
				move(cline, ccolumn);
				p = COB_TERM_BUFF + ccolumn - scolumn;
				continue;
			}
			gotbacksp = false;
			cob_beep();
			continue;
		case KEY_RIGHT:
			if(ccolumn < rightpos) {
				ccolumn++;
				move(cline, ccolumn);
				p = COB_TERM_BUFF + ccolumn - scolumn;
				continue;
			}
			gotbacksp = false;
			cob_beep();
			continue;
		case KEY_IC:
			s = COB_TERM_BUFF + ccolumn - scolumn;
			size = f->size -(ccolumn - scolumn);
			memmove(s + 1, s, size);
			*s = ' ';
			if(fattr & COB_SCREEN_SECURE) {
				addch(COB_CH_AS);
			} else if(fattr & COB_SCREEN_NO_ECHO) {
				addch(COB_CH_SP);
			} else if(fattr & COB_SCREEN_PROMPT) {
				addch(promptchar);
				s++;
				if(size > 0) {
					size--;
				}
				for(; size > 0; size--, s++) {
					if(*s == ' ') {
						addch(promptchar);
					} else {
						addch((const chtype)(*s));
					}
				}
			} else {
				addch(COB_CH_SP);
				if(size > 0) {
					addnstr((char *)s + 1,(int)size - 1);
				}
			}
			move(cline, ccolumn);
			gotbacksp = false;
			continue;
		case KEY_DC:
			s = COB_TERM_BUFF + ccolumn - scolumn;
			size = f->size -(ccolumn - scolumn);
			memmove(s, s + 1, size);
			*(s + size) = ' ';
			if(fattr & COB_SCREEN_SECURE) {
				/* RXWRXW */
			} else if(fattr & COB_SCREEN_NO_ECHO) {
				/* RXWRXW */
			} else if(fattr & COB_SCREEN_PROMPT) {
				for(; size > 0; size--, s++) {
					if(*s == ' ') {
						addch(promptchar);
					} else {
						addch((const chtype)(*s));
					}
				}
				addch(promptchar);
			} else {
				if(size > 0) {
					addnstr((char *)s + 1,(int)size - 1);
				}
			}
			move(cline, ccolumn);
			gotbacksp = false;
			continue;
		default:
			break;
		}

		if(keyp > '\037' && keyp <(int)A_CHARTEXT) {
			gotbacksp = false;
			if(COB_FIELD_IS_NUMERIC(f) ||
					COB_FIELD_TYPE(f) == COB_TYPE_NUMERIC_EDITED) {
				if(keyp < '0' || keyp > '9') {
					cob_beep();
					continue;
				}
			}
			if(fattr & COB_SCREEN_UPPER) {
				if(islower(keyp)) {
					keyp = toupper(keyp);
				}
			} else if(fattr & COB_SCREEN_LOWER) {
				if(isupper(keyp)) {
					keyp = tolower(keyp);
				}
			}
			*p = (unsigned char)keyp;
			count = true;
			if(fattr & COB_SCREEN_SECURE) {
				addch(COB_CH_AS);
			} else if(fattr & COB_SCREEN_NO_ECHO) {
				addch(COB_CH_SP);
			} else {
				addch((const chtype)keyp);
			}
			if(ccolumn == rightpos) {
				if(fattr & COB_SCREEN_AUTO) {
					break;
				}
				move(cline, ccolumn);
				if(ateof) {
					cob_beep();
				} else {
					ateof = true;
				}
			} else {
#if	0	/* RXWRXW - Column inc */
				ccolumn++;
#endif
				p++;
			}
			continue;
		}
		gotbacksp = false;
		(void)flushinp();
		cob_beep();
	}
field_return:
	if(f) {
		move(sline, rightpos + 1);
	}
	refresh();
	cob_check_pos_status(fret);
	if(!f) {
		return;
	}
	if(!count) {
		return;
	}
	cob_move(&temp, f);
}

void
cob_screen_line_col(cob_field * f, const int l_or_c)
{
	if(!cobglobptr->cob_screen_initialized) {
		cob_screen_init();
	}
	if(!l_or_c) {
		cob_set_int(f,(int)LINES);
	} else {
		cob_set_int(f,(int)COLS);
	}
}

int
cob_sys_clear_screen(void)
{
	if(!cobglobptr->cob_screen_initialized) {
		cob_screen_init();
	}
	clear();
	refresh();
	cob_current_y = 0;
	cob_current_x = 0;
	return 0;
}

void
cob_screen_set_mode(const cob_u32_t smode)
{
	if(!smode) {
		refresh();
		def_prog_mode();
		endwin();
	} else {
		reset_prog_mode();
		refresh();
	}
}

void
cob_exit_screen(void)
{
	if(cobglobptr->cob_screen_initialized) {
		cobglobptr->cob_screen_initialized = 0;
		clear();
		move(23, 0);
		delwin(stdscr);
		endwin();
#ifdef	HAVE_CURSES_FREEALL
		_nc_freeall();
#endif
		if(cob_base_inp) {
			delete [] cob_base_inp;
			cob_base_inp = NULL;
		}
	}
	COB_ACCEPT_STATUS = 0;
}

#else	/* COB_GEN_SCREENIO */

void
cob_exit_screen(void)
{
}

void
cob_field_display(cob_field * f, cob_field * line, cob_field * column,
				  cob_field * fgc, cob_field * bgc, cob_field * fscroll,
				  const int attr)
{
	COB_UNUSED(f);
	COB_UNUSED(line);
	COB_UNUSED(column);
	COB_UNUSED(fgc);
	COB_UNUSED(bgc);
	COB_UNUSED(fscroll);
	COB_UNUSED(attr);
}

void
cob_field_accept(cob_field * f, cob_field * line, cob_field * column,
				 cob_field * fgc, cob_field * bgc, cob_field * fscroll,
				 cob_field * ftimeout, cob_field * prompt, const int attr)
{
	COB_UNUSED(f);
	COB_UNUSED(line);
	COB_UNUSED(column);
	COB_UNUSED(fgc);
	COB_UNUSED(bgc);
	COB_UNUSED(fscroll);
	COB_UNUSED(ftimeout);
	COB_UNUSED(prompt);
	COB_UNUSED(attr);
}

void
cob_screen_display(cob_screen * s, cob_field * line, cob_field * column)
{
	COB_UNUSED(s);
	COB_UNUSED(line);
	COB_UNUSED(column);
}

void
cob_screen_accept(cob_screen * s, cob_field * line,
				  cob_field * column, cob_field * ftimeout)
{
	COB_UNUSED(s);
	COB_UNUSED(line);
	COB_UNUSED(column);
	COB_UNUSED(ftimeout);
}

void
cob_screen_line_col(cob_field * f, const int l_or_c)
{
	if(!l_or_c) {
		cob_set_int(f, 24);
	} else {
		cob_set_int(f, 80);
	}
}

void
cob_screen_set_mode(const cob_u32_t smode)
{
	COB_UNUSED(smode);
}

int
cob_sys_clear_screen(void)
{
	return 0;
}

#endif	/* COB_GEN_SCREENIO */

int
cob_sys_sound_bell(void)
{
	if(COB_BEEP_VALUE == 9) {
		return 0;
	}
#ifdef	COB_GEN_SCREENIO
	if(!cobglobptr->cob_screen_initialized &&
			COB_BEEP_VALUE != 2) {
		cob_screen_init();
	}
	cob_beep();
#else
	cob_speaker_beep();
#endif
	return 0;
}

void
cob_accept_escape_key(cob_field * f)
{
	cob_set_int(f, COB_ACCEPT_STATUS);
}

int
cob_sys_get_csr_pos(unsigned char * fld)
{
	COB_CHK_PARMS(CBL_GET_CSR_POS, 1);

#ifdef	COB_GEN_SCREENIO
	int cline, ccol;
	getyx(stdscr, cline, ccol);
	fld[0] = (unsigned char)cline;
	fld[1] = (unsigned char)ccol;
#else
	fld[0] = 1U;
	fld[1] = 1U;
#endif
	return 0;
}

int
cob_sys_get_scr_size(unsigned char * line, unsigned char * col)
{
	COB_CHK_PARMS(CBL_GET_SCR_SIZE, 2);

#ifdef	COB_GEN_SCREENIO
	*line = (unsigned char)LINES;
	*col = (unsigned char)COLS;
#else
	*line = 24U;
	*col = 80U;
#endif
	return 0;
}

void
cob_init_screenio(cob_global * lptr)
{
	cobglobptr = lptr;
}
