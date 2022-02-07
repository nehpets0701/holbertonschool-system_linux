#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>

/**
 * main-open a socket
 * Return: 0/1
 */
int main(void)
{
	int sock;
	struct sockaddr_in addr;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		return (EXIT_FAILURE);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(12345);

	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		return (EXIT_FAILURE);
	listen(sock, 3);
	printf("Listening on port 12345\n");
	while (1)
		;
	return (EXIT_SUCCESS);
}
