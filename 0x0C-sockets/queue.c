#include "data_structures.h"

/**
 * create_queue - Creates an empty queue
 * Return: new queue
*/
queue_t *create_queue(void)
{
	queue_t *q = malloc(sizeof(queue_t));

	if (!q)
		exit(EXIT_FAILURE);

	q->first = q->last = NULL;
	q->size = 0;

	return (q);
}

/**
 * en_queue - en_queue
 * @queue: queue
 * @title: title field
 * @desc: description field
 */
void en_queue(queue_t *queue, char *title, char *desc)
{
	todo_list *temp = malloc(sizeof(todo_list));

	if (!temp)
		exit(EXIT_FAILURE);

	temp->title = strdup(title);
	temp->desc = strdup(desc);
	temp->next = NULL;
	queue->size++;
	if (queue->last == NULL)
	{
		queue->first = queue->last = temp;
		temp->id = 0;
	}
	else
	{
		temp->id = queue->last->id + 1;
		queue->last->next = temp;
		queue->last = temp;
	}
}


/**
* free_queue - frees a queue
* @q: pointer to head of queue
* Return: Nothing.
*/
void free_queue(queue_t **q)
{
	todo_list *prev;
	todo_list *head;

	head = (*q)->first;

	while (head)
	{
		prev = head->next;
		free(head->title);
		free(head->title);
		free(head);
		head = prev;
	}

	free(*q);
	*q = NULL;
}

/**
 * find_by_id - find a todo by id
 * @queue: queue of todos
 * @id: id of a todo
 * Return: todo with matching @id or NULL
 */
todo_list *find_by_id(queue_t *queue, size_t id)
{
	todo_list *node;

	if (!queue || !queue->size)
		return (NULL);
	node = queue->first;
	while (node && node->id != id)
		node = node->next;
	return (node);
}

/**
 * delete_by_id - delete a todo by id
 * @queue: queue of todos
 * @id: id of a todo to be deleted
 * Return: 0 on success, -1 on failure
 */
int delete_by_id(queue_t *queue, size_t id)
{
	todo_list *node, *prev;

	if (!queue || !queue->size)
		return (-1);
	prev = NULL;
	node = queue->first;
	while (node && node->id != id)
	{
		prev = node;
		node = node->next;
	}
	if (!node)
		return (-1);
	queue->size -= 1;
	if (prev)
		prev->next = node->next;
	if (!prev)
	{
		queue->first = node->next;
	}
	if (!node->next)
	{
		queue->last = prev;
	}
	free(node->title);
	free(node->desc);
	free(node);
	return (0);
}
