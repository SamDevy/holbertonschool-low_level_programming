/* 7-insert_dnodeint.c */
/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: address of the head pointer
 * @idx: index where the new node should be added (0-based)
 * @n: integer value for the new node
 *
 * Return: address of the new node, or NULL if it failed or idx is out of range
 */
#include <stdlib.h>
#include "lists.h"

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *cur;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	/* Insert at head position */
	if (idx == 0)
	{
		node = (dlistint_t *)malloc(sizeof(dlistint_t));
		if (node == NULL)
			return (NULL);
		node->n = n;
		node->prev = NULL;
		node->next = *h;
		if (*h != NULL)
			(*h)->prev = node;
		*h = node;
		return (node);
	}

	/* Walk to node currently at position idx */
	cur = *h;
	for (i = 0; cur != NULL && i < idx; i++)
		cur = cur->next;

	/* If cur is NULL, idx may be exactly at end => attach after tail */
	if (cur == NULL)
	{
		/* Find tail */
		dlistint_t *tail = *h;

		if (tail == NULL)
			return (NULL); /* idx > 0 with empty list */

		while (tail->next != NULL)
			tail = tail->next;

		/* Only valid if idx equals current length (append) */
		if (i == idx)
		{
			node = (dlistint_t *)malloc(sizeof(dlistint_t));
			if (node == NULL)
				return (NULL);
			node->n = n;
			node->next = NULL;
			node->prev = tail;
			tail->next = node;
			return (node);
		}
		return (NULL);
	}

	/* Insert before cur (at index idx), linking with its prev */
	node = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = cur->prev;
	node->next = cur;

	if (cur->prev != NULL)
		cur->prev->next = node;
	cur->prev = node;

	return (node);
}
