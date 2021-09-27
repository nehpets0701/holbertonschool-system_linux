#include "signals.h"

/**
*event-catch signal
*@sig:sigint
*/
void event(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
*handle_signal-handles a signal
*Return:0/-1
*/
int handle_signal(void)
{
	if (signal(SIGINT, event) == SIG_ERR)
		return (-1);
	return (0);
}
