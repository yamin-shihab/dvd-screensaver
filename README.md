# dvd-screensaver

A DVD screensaver animation program for the terminal using the awesome [termbox2](https://github.com/termbox/termbox2) library. I made this mainly as an activity to learn [termbox2](https://github.com/termbox/termbox2) (it's amazing!), so expect problems (I'd be surprised if anyone even sees, if not uses this).

## Build

To build this, you must have [termbox2](https://github.com/termbox/termbox2) installed (it'll be dynamically linked). You should also be sure to have a valid c compiler in `$PATH` called cc (I just symlinked `clang` to `/usr/local/bin/cc`, but you can use `gcc` or something else).
```bash
git clone https://github.com/yamin-shihab/dvd-screensaver.git # Clone the project onto your computer
cd dvd-screensaver # Move into the project directory
make # Build the program
```
The `dvd-screensaver` executable can then be found in the `bin/` directory. You can also install it with:
```bash
sudo make install # Install dvd-screensaver to: (default, edit in Makefile) /usr/local/bin/dvd-screensaver
```
