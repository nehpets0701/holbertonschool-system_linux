#include "signals.h"

/**
*handler-handler
*@signum:signum
*/
void handler(int signum)
{
	printf("Caught %d\n", signum);
}

/**
*main-main
*Return:success
*/
int main(void)
{
	signal(SIGINT, handler);

	if (pause() == -1)
		printf("Signal received\n");
	return (EXIT_SUCCESS);
}
