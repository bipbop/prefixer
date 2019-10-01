CFLAGS := -static -O3
CC := gcc
DESTDIR := .

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

build:
	$(CC) prefixer.c -o prefixer $(CFLAGS)

install: build
	cp prefixer $(PREFIX)/bin/

clean:
	rm -rf prefixer
