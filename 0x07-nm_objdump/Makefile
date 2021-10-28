#Makefile

SHELL = /bin/bash
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -ggdb3
NM_SOURCE = $(patsubst %.c,%.o, $(wildcard nm/*.c))
OBJDUMP_SOURCE = $(patsubst %.c,%.o, $(wildcard objdump/*.c))

.PHONY: clean, check

hnm: $(NM_SOURCE)
	$(CC) -o $@ $^

hobjdump: $(OBJDUMP_SOURCE)
	$(CC) -o $@ $^

clean:
	rm nm/*.o objdump/*.o hnm hobjdump

all: clean hnm

check:
	betty nm/*.[ch] objdump/*.[ch]
