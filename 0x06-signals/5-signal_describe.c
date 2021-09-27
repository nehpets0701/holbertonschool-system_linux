#include "signals.h"

/**
*main-describe a given signal
*Return: exit success or failure
*@argc:argc
*@argv:argv
*/
int main(int argc, char **argv)
{
	long int i;

	if (argc < 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	i = strtol(argv[1], NULL, 10);
	printf("%ld: %s\n", i, strsignal(i));
	return (EXIT_SUCCESS);
}
