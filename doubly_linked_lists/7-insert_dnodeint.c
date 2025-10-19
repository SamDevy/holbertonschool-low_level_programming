/* 7-insert_dnodeint.c */
#include <stdlib.h>
#include "lists.h"

/**
 * _insert_before - Inserts new node with n before target cur
 * @cur: node to insert before (must be non-NULL)
 * @n: value for new node
 *
 * Return: pointer to new node or NULL
 */
static dlistint_t *_insert_before(dlistint_t *cur, int n)
{
	dlistint_t *node;

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

/**
 * _node_at_index_or_end - Returns node at idx or NULL; sets reached_len
 * @h: head pointer
 * @idx: target index
 * @reached_len: out flag set to 1 if traversal reached list end with i == idx
 *
 * Return: node at idx if exists; NULL otherwise
 */
static dlistint_t *_node_at_index_or_end(dlistint_t *h, unsigned int idx,
					 int *reached_len)
{
	unsigned int i = 0;

	*reached_len = 0;
	while (h != NULL && i < idx)
	{
		h = h->next;
		i++;
	}

	if (h != NULL && i == idx)
		return (h);

	/* if h == NULL and i == idx, caller may append at end */
	if (h == NULL && i == idx)
		*reached_len = 1;

	return (NULL);
}

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: address of head pointer
 * @idx: index where the new node should be added (0-based)
 * @n: integer value for the new node
 *
 * Return: address of the new node, or NULL if it failed/out of range
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *cur;
	int can_append;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	cur = _node_at_index_or_end(*h, idx, &can_append);
	if (cur != NULL)
		return (_insert_before(cur, n));

	if (can_append)
		return (add_dnodeint_end(h, n));

	return (NULL);
}
