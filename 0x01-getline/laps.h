#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct car_n - singly linked list.
 * @id: id of the car.
 * @laps: laps of each car.
 * @next: points to the next node.
 */

typedef struct car_n
{
	int id;
	int laps;
	struct car_n *next;
} car_t;

void race_state(int *id, size_t size);
void free_list(car_t *head);
void print_race_state(car_t *head);
car_t *new_node(car_t **head, int id);
car_t *search_node(car_t *head, int id);

#endif /* LAPS_H */
