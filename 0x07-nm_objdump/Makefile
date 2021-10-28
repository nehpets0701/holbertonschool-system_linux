#Makefile

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -ggdb3
NM_SOURCE = $(patsubst %.c,%.o, $(wildcard nm/*.c))
OBJDUMP_SOURCE = $(patsubst %.c,%.o, $(wildcard objdump/*.c))

hnm: $(NM_SOURCE)
	$(CC) -o $@ $^

hobjdump: $(OBJDUMP_SOURCE)
	$(CC) -o $@ $^
