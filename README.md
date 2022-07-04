# dvd-screensaver

A DVD screensaver animation program for the terminal using the awesome [termbox2](https://github.com/termbox/termbox2) library. I made this mainly as an activity to learn [termbox2](https://github.com/termbox/termbox2) (it's amazing!), so expect problems (I'd be surprised if anyone even sees, if not uses this). You just run it and watch, and you can quit by pressing `q`.

![demo of the program](demo.gif)

## Build/Install

To build this, you must have [termbox2](https://github.com/termbox/termbox2) installed and the ninja build system. You should also be sure to have a valid c compiler in `$PATH` called `cc` (I just used `ln -s /usr/local/bin/cc /usr/bin/clang`, but you can use `gcc` or something else).
```bash
git clone https://github.com/yamin-shihab/dvd-screensaver.git # Clone the project onto your computer
cd dvd-screensaver # Move into the project directory
ninja # Build the program
```
The `dvd-screensaver` executable can then be found in the `build/` directory. You can also install it with:
```bash
sudo cp build/dvd-screensaver /usr/local/bin # Install dvd-screensaver to /usr/local/bin/dvd-screensaver
```
