<div align=center>

# dvd-screensaver

*A DVD screensaver animation program for the terminal using the awesome [termbox2](https://github.com/termbox/termbox2) library*

![Video demo of the program](demo.gif)

---

</div>

I made this mainly as an activity to learn [termbox2](https://github.com/termbox/termbox2) (it's amazing!), so expect problems (I'd be surprised if anyone uses this, if not sees this). You just run it and watch, and you can quit by pressing `q`.

---

<div align=center>

## Build/Install

</div>

To build this, you must have [termbox2](https://github.com/termbox/termbox2) installed and the `make` build system. You should also be sure to have a valid c compiler in `$PATH` called `cc` (I just used `ln -s /usr/local/bin/cc /usr/bin/clang`, but you can use `gcc`, `tcc`, or something else).
```bash
git clone https://github.com/yamin-shihab/dvd-screensaver # Clone the project onto your computer
cd dvd-screensaver # Move into the project directory
make # Build the program
```
The `dvd` executable can then be found in the `build/` directory. You can also install it with:
```bash
sudo make install # Install dvd to /usr/local/bin/dvd
```
