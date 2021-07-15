#include "hls.h"

/**
*main-ls main
*Return:idk yet
*@argc:count
*@argv:value
*/
int main(int argc, char **argv)
{
	int printed = 0;
	struct dirent *de;
	int file_count = 0;
	DIR *dr = opendir(".");
	(void) argc;

	if (argv[1] != NULL)
		dr = opendir(argv[1]);

	file_count = count();

	if (dr == NULL)
	{
		if (errno == 2)
			fprintf(stderr, "%s: cannot access '%s': No such file or directory\n",
					argv[0], argv[1]);
		else if (errno == 13)
			fprintf(stderr, "Permission error");
		exit(2);
	}

	while ((de = readdir(dr)) != NULL)
	{
		if (de->d_name[0] != '.')
		{
			if (printed <= file_count)
				printf("%s ", de->d_name);
			else
				printf("%s\n", de->d_name);
		}
		printed++;
	}
	printed = 0;

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
	{
		if (entry->d_type == DT_REG)
		{
			file_count++;
		}
	}
	return (file_count);
}
