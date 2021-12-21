#include "multithreading.h"

/**
*thread_entry-entry point for new thread
*@arg:address of string to be printed
*/
void *thread_entry(void *arg)
{
	if (arg == NULL)
		return (NULL);
	printf("%s\n", (char *)arg);
	pthread_exit(0);
}
