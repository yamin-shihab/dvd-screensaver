#ifndef DVD_SCREENSAVER
#define DVD_SCREENSAVER

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


bool
quit_check(const int ms);

void
screen_draw(struct DVDLogo *dvd);

uintattr_t
col_get(struct DVDLogo *dvd);

void
dvd_move(struct DVDLogo *dvd);

void
main_loop(void);

int
terminal_size_check(void);

#endif
