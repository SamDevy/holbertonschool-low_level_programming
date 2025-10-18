/* 4-free_list.c */
/**
 * free_list - Frees all nodes of a list_t linked list
 * @head: head pointer to the list
 *
 * Return: Nothing.
 *
 * Behavior:
 * - Iterates through the list, freeing node->str (duplicated via strdup),
 *   then frees the node itself.
 * - Stops at NULL; safe on empty lists.
 */
#include <stdlib.h>
#include "lists.h"

void free_list(list_t *head)
{
	list_t *next_node;

	while (head != NULL)
	{
		next_node = head->next;
		free(head->str);
		free(head);
		head = next_node;
	}
}
