/* 3-add_node_end.c */
/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: address of the head pointer
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
#include <stdlib.h>
#include <string.h>
#include "lists.h"

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *tail;
	char *dup;
	unsigned int len;

	if (head == NULL || str == NULL)
		return (NULL);

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);

	len = 0;
	while (dup[len] != '\0')
		len++;

	node = (list_t *)malloc(sizeof(list_t));
	if (node == NULL)
	{
		free(dup);
		return (NULL);
	}
	node->str = dup;
	node->len = len;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;

	tail->next = node;
	return (node);
}
