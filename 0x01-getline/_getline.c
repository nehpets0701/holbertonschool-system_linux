#include "_getline.h"

/**
* _getline - reads line
* @fd: file descriptor
* Return: null-terminated string without newline, else NULL
*/
char *_getline(const int fd)
{
	static fd_t *holder_head;
	fd_t *current, *temp;

	if (fd == -1)
	{
		current = holder_head;
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			if (temp->buffer != NULL)
				free(temp->buffer);
			free(temp);
		}
		holder_head = NULL;
		return (NULL);
	}

	current = fd_insert(&holder_head, fd);
	if (current == NULL)
		return (NULL);

	return (extract_line(current));
}

/**
* fd_insert - insert new
* @head: head
* @fd: file descriptor
* Return: new node or null
*/
fd_t *fd_insert(fd_t **head, int fd)
{
	fd_t *out, *current = *head, *prev = NULL;

	if (*head == NULL)
	{
		out = malloc(sizeof(fd_t));
		if (out == NULL)
			return (NULL);
		out->buffer = NULL;
		out->fd = fd;
		out->next = NULL;
		*head = out;
		return (out);
	}
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		if (current->fd > fd)
		{
			out = malloc(sizeof(fd_t));
			if (out == NULL)
				return (NULL);
			out->buffer = NULL;
			out->fd = fd;
			out->next = current;
			if (prev != NULL)
				prev->next = out;
			return (out);
		}
		prev = current;
		current = current->next;
	}
	out = malloc(sizeof(fd_t));
	if (out == NULL)
		return (NULL);
	out->buffer = NULL;
	out->fd = fd;
	out->next = NULL;
	prev->next = out;
	return (out);
}

/**
* extract_line - gets next line
* @holder: struct
* Return: new or null
*/
char *extract_line(fd_t *holder)
{
	int start;
	char *out = NULL;

	if (holder->buffer == NULL)
	{
		holder->idx = 0;
		holder->buffer = malloc(sizeof(char) * (READ_SIZE + 1));
		if (holder->buffer == NULL)
			return (NULL);
		memset(holder->buffer, 0, READ_SIZE + 1);
		if (read(holder->fd, holder->buffer, READ_SIZE) == -1)
			return (NULL);
	}

	start = holder->idx;
	while (holder->idx < READ_SIZE)
	{
		if (holder->buffer[holder->idx] == '\n')
			break;
		else if (holder->buffer[holder->idx] == '\0')
			break;
		holder->idx++;
	}

	if (holder->idx == READ_SIZE)
		return (end_of_buffer(holder, start));

	if (holder->buffer[holder->idx] != '\0' || holder->idx != start)
		out = _strndup(holder->buffer + start, holder->idx - start);
	if (holder->buffer[holder->idx] == '\0')
	{
		free(holder->buffer);
		holder->buffer = NULL;
	}
	if (holder->idx < READ_SIZE)
		holder->idx++;

	return (out);
}

/**
* end_of_buffer - multiple reads
* @holder: struct with data
* @start: start
* Return: full line string, else NULL
*/
char *end_of_buffer(fd_t *holder, int start)
{
	char *out = NULL, *temp = NULL;
	int i = 0, j = 0;

	if (start != holder->idx)
		out = strdup(holder->buffer + start);
	else
		out = NULL;
	free(holder->buffer);
	holder->buffer = NULL;
	temp = extract_line(holder);
	if (temp == NULL)
	{
		if (out != NULL)
			free(out);
		if (holder->buffer != NULL)
			free(holder->buffer);
		return (NULL);
	}
	if (out != NULL)
	{
		while (out[i])
			i++;
		while (temp[j])
			j++;
		out = realloc(out, 1 + i + j);
		strcat(out, temp);
		free(temp);
	}
	else
		out = temp;
	return (out);
}

/**
* _strndup - strndup
* @src: src
* @n: n
* Return: new or null
*/
char *_strndup(char *src, int n)
{
	int i = 0;
	char *out;

	out = malloc(sizeof(char) * (n + 1));
	if (out == NULL)
		return (NULL);

	while (i < n)
	{
		out[i] = src[i];
		i++;
	}

	out[n] = '\0';
	return (out);
}
