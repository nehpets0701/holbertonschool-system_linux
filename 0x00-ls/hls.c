#include "hls.h"

/**
*main-ls main
*Return:idk yet
*@argc:count
*@argv:value
*/
int main(int argc, char **argv)
{
	(void) argc;
	struct dirent *de;
	DIR *dr = opendir(".");

	if (argv[1] != NULL)
		dr = opendir(argv[1]);

	if (dr == NULL)
	{
		printf("%d\n", errno);
		if (errno == 2)
			fprintf(stderr, "%s: cannot access '%s': No such file or directory\n", argv[0], argv[1]);
		else if (errno == 13)
			fprintf(stderr, "Permission error");
		exit (2);
	}

	while ((de = readdir(dr)) != NULL)
	{
		if (de->d_name[0] != '.')
			printf("%s\n", de->d_name);
	}
	closedir(dr);
	return (0);
}
