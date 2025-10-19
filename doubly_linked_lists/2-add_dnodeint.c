/* 2-add_dnodeint.c */
/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 * @head: address of the head pointer
 * @n: integer value for the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
#include <stdlib.h>
#include "lists.h"

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	if (head == NULL)
		return (NULL);

	node = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = *head;

	if (*head != NULL)
		(*head)->prev = node;

	*head = node;
	return (node);
}
