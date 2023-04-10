#include "dvd.h"
#define TB_IMPL
#include <termbox2.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int
main(void) {
    tb_init();
    if (check_terminal_size()) {
        return 1;
    }
    main_loop();
    tb_shutdown();
    return 0;
}

bool
check_terminal_size(void) {
    if (tb_height() < 10 || tb_width() < 10) {
        fprintf(stderr, "Terminal size too small. How do you think I can show anything?");
        return true;
    }
    return false;
}

void
main_loop(void) {
    srand(time(NULL));
    struct DVDLogo dvd = {
        .pos = { .x = rand() % tb_width(), .y = rand() % tb_height() },
        .dir = { .x = 1, .y = 1 },
        .color = 0
    };
    while (true) {
        move_dvd(&dvd);
        draw_screen(&dvd);
        if (check_quit()) {
            return;
        }
    }
}

void
move_dvd(struct DVDLogo *dvd) {
    dvd->pos.x += dvd->dir.x;
    dvd->pos.y += dvd->dir.y;
    if (dvd->pos.x == 0 || dvd->pos.x == tb_width() - 3) {
        dvd->dir.x *= -1;
        ++dvd->color;
    }
    if (dvd->pos.y == 0 || dvd->pos.y == tb_height()) {
        dvd->dir.y *= -1;
        ++dvd->color;
    }
}

void
draw_screen(struct DVDLogo *dvd) {
    const uintattr_t fg = TB_BLACK | TB_BOLD | TB_ITALIC;
    const uintattr_t bg = get_color(dvd);
    tb_set_clear_attrs(fg, fg);
    tb_clear();
    tb_set_cell(dvd->pos.x, dvd->pos.y, 'D', fg, bg);
    tb_set_cell(dvd->pos.x + 1, dvd->pos.y, 'V', fg, bg);
    tb_set_cell(dvd->pos.x + 2, dvd->pos.y, 'D', fg, bg);
    tb_present();
}

uintattr_t
get_color(struct DVDLogo *dvd) {
    const uintattr_t colors[] = {
        TB_RED,
        TB_GREEN,
        TB_YELLOW,
        TB_BLUE,
        TB_MAGENTA,
        TB_CYAN,
        TB_WHITE
    };
    dvd->color %= 7;
    return colors[dvd->color];
}

bool
check_quit() {
    struct tb_event event = { 0 };
    tb_peek_event(&event, MS_PER_FRAME);
    if (event.ch == 'q')
        return true;
    return false;
}
