#include "signals.h"

/**
*current_handler_sigaction-finds sigint handler
*Return: pointer of handler
*/
void (*current_handler_sigaction(void))(int)
{
	struct sigaction oldact;

	if (sigaction(SIGINT, NULL, &oldact) == -1)
		return (NULL);
	return (oldact.sa_handler);
}
