/* 0-print_dlistint.c */
#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints all integers in a doubly linked list
 * @h: head pointer
 *
 * Return: number of nodes
 */
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
