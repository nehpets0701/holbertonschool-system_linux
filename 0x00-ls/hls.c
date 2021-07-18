#include "hls.h"

/**
*main-ls main
*Return:idk yet
*@argc:count
*@argv:value
*/
int main(int argc, char **argv)
{
	struct dirent *de;
	int file_count = 0;
	int flag = 0;
	DIR *dr;
	(void)argc;

	dr = opendir(".");
	de = readdir(dr);
	file_count = count();
	if (argv[1] != NULL)
	{
		flag = flags(flag, argv[1], file_count, dr, de, argv);
		if (flag != 1)
		{
			closedir(dr);
			dr = opendir(argv[1]);
			if (dr != NULL)
			{
				printf("%s\n", argv[1]);
				closedir(dr);
				exit(0);
			}
		}
	}

	if (dr == NULL)
		errorHandling(argv);

	print(file_count, dr, de);
	closedir(dr);
	exit(0);
}


/**
*count-counts number of files
*Return:number of files
*/
int count(void)
{
	DIR *dirp = opendir(".");
	struct dirent *entry;
	int file_count = 0;

	while ((entry = readdir(dirp)) != NULL)
		file_count++;

	closedir(dirp);
	return (file_count);
}


/**
*flags-handles options and flags
*Return:flag
*@f:flag in question
*@a:argv[1]
*@files:file count
*@dr:dr
*@de:de
*@argv:argv
*/
int flags(int f, char *a, int files, DIR *dr, struct dirent *de, char **argv)
{
	if (_strcmp(a, "-a") == 0)
	{
		printa(files, dr, de);
		f = 1;
	}
	else if (_strcmp(a, "-l") == 0)
	{
		printl(files, dr, de);
		f = 1;
	}
	else if (_strcmp(a, "-A") == 0)
	{
		printA(files, dr, de);
		f = 1;
	}
	else if (_strcmp(a, "-1") == 0)
	{
		print1(dr, de, argv);
		f = 1;
	}
	else
		f = 0;

	return (f);
}


/**
*errorHandling-handles errors
*@argv:argv
*/
void errorHandling(char **argv)
{
	if (errno == 2)
		fprintf(stderr, "%s: cannot access '%s': No such file or directory\n",
				argv[0], argv[1]);
	else if (errno == 13)
		fprintf(stderr, "%s: cannot open directory '%s': Permission denied\n",
				argv[0], argv[1]);
	else if (errno == 20)
	{
		printf("%s\n", argv[1]);
		exit(0);
	}
	exit(2);
}
