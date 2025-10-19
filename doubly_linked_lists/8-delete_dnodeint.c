/* 8-delete_dnodeint.c */
/**
 * delete_dnodeint_at_index - Deletes node at a given index in a doubly list
 * @head: address of pointer to head of the list
 * @index: zero-based index of the node to delete
 *
 * Return: 1 on success, -1 on failure (NULL head, out of range)
 *
 * Why this way:
 * - Handles deleting head (index 0) and middle/tail uniformly.
 * - Updates both prev and next links safely.
 * - Frees the target node and leaves list consistent.
 */
#include <stdlib.h>
#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	cur = *head;

	/* delete head case */
	if (index == 0)
	{
		*head = cur->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(cur);
		return (1);
	}

	/* walk to target index */
	for (i = 0; cur != NULL && i < index; i++)
		cur = cur->next;

	if (cur == NULL)
		return (-1);

	/* unlink cur from list */
	if (cur->prev != NULL)
		cur->prev->next = cur->next;
	if (cur->next != NULL)
		cur->next->prev = cur->prev;

	free(cur);
	return (1);
}
