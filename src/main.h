#ifndef MAIN
#define MAIN

#include <stdbool.h>
#include <termbox.h>


struct Vec2 {
	int x, y;
};


struct DVDLogo {
	struct Vec2 pos;
	struct Vec2 dir;
	int col;
};


uint32_t
char_to_unicode(const char c);

bool
quit_check();

void
screen_draw(struct DVDLogo *dvd);

uintattr_t
col_get(struct DVDLogo *dvd);

void
dvd_move(struct DVDLogo *dvd);

void
main_loop();

int
terminal_size_check();

#endif
