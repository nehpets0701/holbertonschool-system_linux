#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

/**
*main-connects to a listening server
*Return: 0/1
*@argc:argc
*@argv:argv
*/
int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in addr;
	struct hostent *host;

	if (argc < 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	host = gethostbyname(argv[1]);
	if (!host)
		return (EXIT_FAILURE);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		return (EXIT_FAILURE);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr));
	addr.sin_port = htons(strtol(argv[2], NULL, 10));

	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		return (EXIT_FAILURE);
	}
	printf("Connected to %s:%s\n", argv[1], argv[2]);
	close(sock);
	return (0);
}
