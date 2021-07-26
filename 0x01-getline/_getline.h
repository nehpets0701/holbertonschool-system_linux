#ifndef _GETLINE_H
#define _GETLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

/**
* struct fd_holder - struct for handling file descriptors with _getline
* @buffer: char buffer holding output from read()
* @idx: current left index of next line
* @fd: file descriptor to be used with read()
* @next: pointer to next fd_holder in a linked list
*
* Description: all necessary info for _getline with multiple fds
*/
typedef struct fd_holder
{
	char *buffer;
	int idx;
	int fd;
	struct fd_holder *next;
} fd_t;

char *_getline(const int fd);
char *extract_line(fd_t *);
char *end_of_buffer(fd_t *, int);
fd_t *fd_insert(fd_t **head, int fd);
char *_strndup(char *, int);

#define READ_SIZE 1

#endif