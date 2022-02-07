#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>

/**
 * main-opens and closes a socket after connection
 * Return: 0/1
 */
int main(void)
{
	int sock, newsSock, clientSize;
	struct sockaddr_in addr, client;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		return (EXIT_FAILURE);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(12345);

	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		return (EXIT_FAILURE);
	listen(sock, 3);
	clientSize = sizeof(client);
	newSock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&clientSize);
	if (newSock < 0)
		return (EXIT_FAILURE);

	printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
	close(sock);
	close(newSock);
	return (0);
}
