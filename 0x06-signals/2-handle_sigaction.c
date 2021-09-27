#include "signals.h"

/**
*handler-handles signal
*@signum:signum
*/
void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
*handle_sigaction-handles action
*Return: 0/-1
*/
int handle_sigaction(void)
{
	struct sigaction sig;

	sig.sa_handler = handler;
	return (sigaction(SIGINT, &sig, NULL));
}
