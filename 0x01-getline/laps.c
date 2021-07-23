#include "laps.h"

/**
 * race_state - Check the state of race.
 * @id: list of integer, id of cars.
 * @size: size of id.
 */

void race_state(int *id, size_t size)
{
	static car_t *head;
	car_t *node;
	size_t i = 0;

	if (size == 0)
	{
		free_list(head);
		return;
	}

	for (; i < size; i++)
	{
		node = search_node(head, id[i]);
		if (!node)
		{
			node = new_node(&head, id[i]);
			printf("Car %d joined the race\n", node->id);
		}
		else
			node->laps++;
	}
	print_race_state(head);
}

/**
 * search_node - search a node in the linked list.
 * @head: pointer to first node.
 * @id: id to search of node.
 * Return: the node found.
 */

car_t *search_node(car_t *head, int id)
{
	while (head && head->id != id)
		head = head->next;
	return (head);
}

/**
 * new_node - Adds a new node to the linked list.
 * @head: pointer to first node.
 * @id: id of the new node.
 * Return: the new node.
 */

car_t *new_node(car_t **head, int id)
{
	car_t *node;
	car_t *tmp;

	node = malloc(sizeof(*node));

	if (!node)
		return (NULL);

	node->id = id;
	node->laps = 0;

	if (!*head || id < (*head)->id)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	for (tmp = *head; tmp; tmp = tmp->next)
		if (tmp->id < id)
			if (tmp->next == NULL || tmp->next->id > id)
			{
				node->next = tmp->next;
				tmp->next = node;
				break;
			}
	return (node);
}

/**
 * free_list - free the linked list
 * @head: pointer to the first node.
*/

void free_list(car_t *head)
{
	car_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * print_race_state - prints each car and lap.
 * @head: pointer to the first node.
*/

void print_race_state(car_t *head)
{
	printf("Race state:\n");
	while (head)
	{
		printf("Car %d [%d laps]\n", head->id, head->laps);
		head = head->next;
	}
}
