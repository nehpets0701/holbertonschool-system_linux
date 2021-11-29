CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3 -std=gnu90
HEADERS = strace.h syscalls.h
TASK_0 = 0strace
TASK_1 = 1strace
TASK_2 = 2strace
TASK_3 = 3strace
HELPERS = helpers

.PHONY: clean, check

$(TASK_3): $(TASK_3).o $(HEADERS)
	$(CC) $(CFLAGS) -o $@  $^

$(TASK_2): $(TASK_2).o $(HEADERS)
	$(CC) $(CFLAGS) -o $@  $^

$(TASK_1): $(TASK_1).o $(HEADERS)
	$(CC) $(CFLAGS) -o $@  $^

$(TASK_0): $(TASK_0).o $(HEADERS)
	$(CC) $(CFLAGS) -o $@  $^

clean:
	rm *.o $(TASK_0) $(TASK_1) $(TASK_2) $(TASK_3)

check:
	betty *.c *.h
