/* 5-get_dnodeint.c */
/**
 * get_dnodeint_at_index - Returns the node at a given index in a doubly list
 * @head: head pointer to the list
 * @index: zero-based index
 *
 * Return: pointer to the node at index, or NULL if it does not exist
 */
#include "lists.h"

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
