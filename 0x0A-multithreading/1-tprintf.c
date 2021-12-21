#include "multithreading.h"

/**
*tprintf-prints with thread ID
*@format:format string
*Return:number of chars printed
*/
int tprintf(char const *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	count += printf("[%lu] ", pthread_self());
	count += vprintf(format, args);
	va_end(args);
	return (count);
}
