/* 0-print_dlistint.c */
/**
 * print_dlistint - Prints all elements of a dlistint_t list
 * @h: head pointer to the doubly linked list
 *
 * Return: number of nodes
 */
#include <stdio.h>
#include "lists.h"

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
