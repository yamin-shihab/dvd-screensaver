#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <termbox.h>
#include "main.h"


bool
quit_check(const int ms)
{
	struct tb_event event = { 0 };
	tb_peek_event(&event, ms);
	if (event.ch == 'q')
		return true;
	return false;
}


uintattr_t
col_get(struct DVDLogo *dvd)
{
	const uintattr_t cols[] = {
		TB_RED,
		TB_GREEN,
		TB_YELLOW,
		TB_BLUE,
		TB_MAGENTA,
		TB_CYAN,
		TB_WHITE
	};
	dvd->col %= 7;
	return cols[dvd->col];
}


void
screen_draw(struct DVDLogo *dvd)
{
	const uintattr_t fg = TB_BLACK | TB_BOLD | TB_ITALIC;
	const uintattr_t bg = col_get(dvd);
	tb_set_clear_attrs(fg, fg);
	tb_clear();
	tb_set_cell(dvd->pos.x, dvd->pos.y, 'D', fg, bg);
	tb_set_cell(dvd->pos.x + 1, dvd->pos.y, 'V', fg, bg);
	tb_set_cell(dvd->pos.x + 2, dvd->pos.y, 'D', fg, bg);
	tb_present();
}


void
dvd_move(struct DVDLogo *dvd)
{
	dvd->pos.x += dvd->dir.x;
	dvd->pos.y += dvd->dir.y;
	if (dvd->pos.x == 0 || dvd->pos.x == tb_width() - 3) {
		dvd->dir.x *= -1;
		++dvd->col;
	}
	if (dvd->pos.y == 0 || dvd->pos.y == tb_height()) {
		dvd->dir.y *= -1;
		++dvd->col;
	}
}


void
main_loop(void)
{
	const int FPS = 16;
	const double MS_PER_FRAME = 1000 / FPS;
	srand(time(NULL));
	struct DVDLogo dvd = {
		.pos = { .x = rand() % tb_width(), .y = rand() % tb_height() },
		.dir = { .x = 1, .y = 1 },
		.col = 0
	};
	while (true) {
		dvd_move(&dvd);
		screen_draw(&dvd);
		if (quit_check(MS_PER_FRAME))
			return;
	}
}


int
terminal_size_check(void)
{
	if (tb_height() < 10 || tb_width() < 10) {
		printf("Terminal size too small. How do you think I can show anything?");
		return 1;
	}
	return 0;
}


int
main(void)
{
	tb_init();
	if (terminal_size_check())
		return 1;
	main_loop();
	tb_shutdown();
	return 0;
}
