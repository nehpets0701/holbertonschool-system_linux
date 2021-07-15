#ifndef HLS_H
#define HLS_H

/*includes*/
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
/*includes*/

/*prototypes*/
int count(void);
int handleFlags(int flag, char *a, int file_count, DIR *dr, struct dirent *de);
void print(int file_count, DIR *dr, struct dirent *de);
void printa(int file_count, DIR *dr, struct dirent *de);
void print1(DIR *dr, struct dirent *de);
void printA(int file_count, DIR *dr, struct dirent *de);
void printl(int file_count, DIR *dr, struct dirent *de);
int _strcmp(char *s1, char *s2);
/*prototypes*/
#endif
