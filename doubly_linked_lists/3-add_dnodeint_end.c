/* 3-add_dnodeint_end.c */
/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: address of the head pointer
 * @n: integer value for the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
#include <stdlib.h>
#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *tail;

	if (head == NULL)
		return (NULL);

	node = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}

	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;

	tail->next = node;
	node->prev = tail;

	return (node);
}
