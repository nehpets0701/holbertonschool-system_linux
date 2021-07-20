#ifndef HLS_H
#define HLS_H

/*includes*/
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
/*includes*/

/*prototypes*/
int count(void);
int flags(int f, int files, DIR *dr, struct dirent *de, char **argv, int argc);
void print(int file_count, DIR *dr, struct dirent *de);
void printa(int count, DIR *dr, struct dirent *de, int ac, char **av);
void print1(DIR *dr, struct dirent *de, char **argv);
void printA(int file_count, DIR *dr, struct dirent *de);
void printl(int file_count, DIR *dr, struct dirent *de);
void errorHandling(char **argv);
int _strcmp(char *s1, char *s2);
/*prototypes*/
#endif
