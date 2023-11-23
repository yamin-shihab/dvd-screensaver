# pls don't make fun of my pathetic makefile

CFLAGS := -std=c99 -pedantic -Wall -Wextra -Os -static -o build/dvd

all: build

build:
	mkdir -p build
	$(CC) src/dvd.c $(CFLAGS)
	strip build/dvd

install: build
	cp build/dvd /usr/local/bin

clean:
	rm -rf build

.PHONY: clean build install
