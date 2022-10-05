#ifndef DVD_SCREENSAVER
#define DVD_SCREENSAVER

#include <stdbool.h>
#include <termbox.h>

// Frames per second and milliseconds per frame for program, and speed of DVD logo movement
#define FPS 24
#define MS_PER_FRAME 1000 / FPS

// The minimum width and height of the terminal
#define TERM_WIDTH 10
#define TERM_HEIGHT 10

// Used to represent a position or direction in the terminal
struct Vec2 {
	int x, y;
};

// Has the position, direction, and current color of the DVD logo
struct DVDLogo {
	struct Vec2 pos;
	struct Vec2 dir;
	int color;
};

// Returns true if terminal is too small, otherwise false
bool
check_terminal_size(void);

// The main forever loop of the animation
void
main_loop(void);

// Moves the DVD's position by its direction
void
move_dvd(struct DVDLogo *dvd);

// Draws the DVD onto the terminal, as well as color and background
void
draw_screen(struct DVDLogo *dvd);

// Returns the current color of the DVD, and change it too
uintattr_t
get_color(struct DVDLogo *dvd);

// Waits for the specific MS_PER_FRAME to receive input, return true if it is the "q" key
bool
check_quit(void);

#endif
