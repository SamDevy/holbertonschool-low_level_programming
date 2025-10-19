/* 1-dlistint_len.c */
/**
 * dlistint_len - Returns the number of elements in a dlistint_t list
 * @h: head pointer to the doubly linked list
 *
 * Return: number of nodes
 */
#include "lists.h"

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
