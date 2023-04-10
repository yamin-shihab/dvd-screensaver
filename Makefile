# pls don't make fun of my pathetic makefile

CFLAGS := -std=c99 -pedantic -Wall -Wextra -Os -o build/dvd -ltermbox2

all: build

build:
	mkdir -p build && $(CC) src/dvd.c $(CFLAGS)

install: build
	cp build/dvd /usr/local/bin

clean:
	rm -rf build

.PHONY: clean build install
