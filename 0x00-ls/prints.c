#include "hls.h"

/**
*printa-prints results
*@file_count: number of files
*@dr:dr
*@de:de
*@f:flag
*/
void printa(int count, DIR *dr, struct dirent *de, int ac, char **av)
{
	int printed = 0;
	int i;
	int flag = 0;

	if (av[2] == NULL)
	{
		printf(". ");
		while ((de = readdir(dr)) != NULL)
		{
			if (printed + 3 <= count)
				printf("%s ", de->d_name);
			else
				printf("%s\n", de->d_name);
			printed++;
		}
	}
	else
	{
		for (i = 1; i < ac; i++)
		{
			DIR *check = opendir(av[i]);

			if (!check && av[i][0] != '-')
			{
				fprintf(stderr, "%s: cannot access '%s': No such file or directory\n",
					av[0], av[i]);
				flag = 1;
			}

			if (flag == 1 && i == ac - 1)
			{
				closedir(check);
				exit (2);
			}
			closedir(check);
		}
		for (i = 1; i < ac; i++)
		{
			if (av[i][0] != '-')
				printf("%s\n", av[i]);
		}
		exit(0);
	}
}


/**
*print-prints results
*@file_count: number of files
*@dr:dr
*@de:de
*/
void print(int file_count, DIR *dr, struct dirent *de)
{
	int printed = 0;

	while ((de = readdir(dr)) != NULL)
	{
		if (de->d_name[0] != '.')
		{
			if (printed + 4 < file_count)
				printf("%s ", de->d_name);
			else
				printf("%s\n", de->d_name);
			printed++;
		}
	}
}


/**
*printA-prints results
*@file_count: number of files
*@dr:dr
*@de:de
*/
void printA(int file_count, DIR *dr, struct dirent *de)
{
	int printed = 0;

	while ((de = readdir(dr)) != NULL)
	{
		if (_strcmp(de->d_name, "..") != 0 && _strcmp(de->d_name, ".") != 0)
		{
			if (printed + 3 < file_count)
				printf("%s ", de->d_name);
			else
				printf("%s\n", de->d_name);
			printed++;
		}
	}
}


/**
*print1-prints results
*@dr:dr
*@de:de
*@argv:argv
*/
void print1(DIR *dr, struct dirent *de, char **argv)
{
	while ((de = readdir(dr)) != NULL)
	{
		if (argv[2] != NULL)
		{
			dr = opendir(argv[2]);
			if (dr != NULL)
			{
				printf("%s\n", argv[2]);
				exit(0);
			}
		}
		if (de->d_name[0] != '.')
			printf("%s\n", de->d_name);
	}
}


/**
*printl-prints results
*@file_count: number of files
*@dr:dr
*@de:de
*/
void printl(int file_count, DIR *dr, struct dirent *de)
{
	int printed = 0;

	while ((de = readdir(dr)) != NULL)
	{
		if (de->d_name[0] != '.')
		{
			if (printed + 4 < file_count)
				printf("%s ", de->d_name);
			else
				printf("%s\n", de->d_name);
			printed++;
		}
	}
}
