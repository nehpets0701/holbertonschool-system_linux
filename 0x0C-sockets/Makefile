##
#http server

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3

TASK0 = todo_api_0
TASK1 = todo_api_1
TASK2 = todo_api_2
TASK3 = todo_api_3
TASK4 = todo_api_4
TASK5 = todo_api_5

$(TASK5): $(TASK5).c todo_api.h helpers1.c helpers2.c rest_api_2.c queue.c
	$(CC) $(CFLAGS) -o $@  $^

$(TASK4): $(TASK4).c todo_api.h helpers1.c helpers2.c rest_api_2.c queue.c
	$(CC) $(CFLAGS) -o $@  $^

$(TASK3): $(TASK3).c todo_api.h helpers1.c helpers2.c
	$(CC) $(CFLAGS) -o $@  $^

$(TASK2): $(TASK2).c todo_api.h helpers1.c helpers2.c
	$(CC) $(CFLAGS) -o $@  $^

$(TASK1): $(TASK1).c todo_api.h helpers1.c helpers2.c
	$(CC) $(CFLAGS) -o $@  $^

$(TASK0): $(TASK0).c todo_api.h helpers1.c helpers2.c
	$(CC) $(CFLAGS) -o $@  $^

.PHONY: clean, check, run

clean:
	rm $(TASK0) $(TASK1) $(TASK2) $(TASK3) $(TASK4)

check:
	betty *.c *.h

# end
