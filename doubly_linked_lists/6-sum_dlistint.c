/* 6-sum_dlistint.c */
/**
 * sum_dlistint - Returns the sum of all n values in a dlistint_t list
 * @head: head pointer to the doubly linked list
 *
 * Return: sum of node values (0 if list is empty)
 */
#include "lists.h"

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
