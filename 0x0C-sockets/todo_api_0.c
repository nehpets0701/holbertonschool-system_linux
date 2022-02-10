#include "todo_api.h"

/**
 * connect - accept connection
 * @sock: socket
 * Return: 0/-1
*/
int connect(int sock)
{
	int newSock, clientSize;
	struct sockaddr_in client;
	char header[BUFSIZ] = {0};

	clientSize = sizeof(client);
	while (1)
	{
		newSock = accept(sck, (struct sockaddr *)&client, (socklen_t *)&clientSize);
		if (newSock < 0)
			return (-1);
		printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
		if (print_raw_req(header, newSock) == -1)
		{
			close(newSock);
			close(sock);
			return (-1);
		}
		printf("Method: %s\n", strtok(header, " "));
		printf("Path: %s\n", strtok(NULL, " "));
		printf("Version: %s\n", strtok(NULL, " \r"));
		dprintf(newSock, "HTTP/1.0 200 OK\r\n\r\n");
		close(newSock);
	}
	return (0);
}

/**
 * main-socket for todo api
 * Return: 0/1
 */
int main(void)
{
	int sock;

	setbuf(stdout, NULL);
	sock = init_inet_socket();
	if (sck == -1)
		return (EXIT_FAILURE);
	if (connect(sock) == -1)
		return (EXIT_FAILURE);
	close(sock);
	return (EXIT_SUCCESS);
}
