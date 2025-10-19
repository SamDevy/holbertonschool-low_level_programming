/* 4-free_dlistint.c */
/**
 * free_dlistint - Frees a dlistint_t list
 * @head: head pointer to the list
 *
 * Return: Nothing.
 */
#include <stdlib.h>
#include "lists.h"

void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
