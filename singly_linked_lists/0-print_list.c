/* 0-print_list.c */
/**
 * print_list - Prints all elements of a list_t linked list
 * @h: head pointer to the list
 *
 * Return: number of nodes
 */
#include <stdio.h>
#include "lists.h"

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		count++;
	}
	return (count);
}
