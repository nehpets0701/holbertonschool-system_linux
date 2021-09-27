#include "signals.h"

/**
*main-main
*Return: exit success or failure
*@argc:argc
*@argv:argv
*/
int main(int argc, char **argv)
{
	pid_t pid;

	if (argc < 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = strtol(argv[1], NULL, 10);

	if (kill(pid, SIGINT) == -1)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
