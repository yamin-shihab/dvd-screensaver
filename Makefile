CFLAGS = -Wall -Wextra -Wvla -Wpedantic -Wno-unused-result -std=c99 -Ofast
TARGET = dvd-screensaver
INSTALLDIR = /usr/local/bin
VPATH = src obj bin

$(TARGET): bin main.o
	cc obj/* -ltermbox -o bin/$(TARGET)
	strip bin/$(TARGET)

main.o: obj main.c main.h
	cc -c $(CFLAGS) src/main.c
	mv *.o obj

obj:
	mkdir obj

bin:
	mkdir bin

.PHONY: clean run install
clean:
	rm -r obj bin

run: $(TARGET)
	bin/$(TARGET)

install: $(TARGET)
	cp bin/$(TARGET) $(INSTALLDIR)
