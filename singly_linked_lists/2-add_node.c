/* 2-add_node.c */
/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: address of the head pointer
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 *
 * Behavior:
 * - Duplicates str (using strdup), computes its length,
 *   allocates a new node, links it at the head, and returns it.
 * - On any allocation failure, frees what was allocated and returns NULL.
 */
#include <stdlib.h>
#include <string.h>
#include "lists.h"

list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
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
	node->next = *head;
	*head = node;

	return (node);
}
