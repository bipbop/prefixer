CFLAGS := -static -O3
CC := gcc
DESTDIR := .
DEBDIR = prefixer_1.1-1

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

build:
	$(CC) prefixer.c -o prefixer $(CFLAGS)

deb: build
	mkdir -p $(DEBDIR)/usr/bin/
	cp -R DEBIAN $(DEBDIR)
	cp prefixer $(DEBDIR)/usr/bin/
	dpkg-deb --build $(DEBDIR)

install: build
	mkdir $(DESTDIT)$(PREFIX)/bin/
	cp prefixer $(DESTDIT)$(PREFIX)/bin/

clean:
	rm -rf prefixer
