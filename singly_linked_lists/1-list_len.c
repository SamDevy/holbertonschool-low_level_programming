/* 1-list_len.c */
/**
 * list_len - Returns the number of elements in a list_t linked list
 * @h: head pointer to the list
 *
 * Return: number of nodes
 */
#include "lists.h"

size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
