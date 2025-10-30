#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_node - Updates the value of an existing hash node
 * @node: Pointer to the node to update
 * @value: New value to set
 *
 * Return: 1 on success, 0 on failure
 */
static int update_node(hash_node_t *node, const char *value)
{
	char *new_value;

	new_value = strdup(value);
	if (!new_value)
		return (0);

	free(node->value);
	node->value = new_value;
	return (1);
}

/**
 * create_node - Creates a new hash node with a key and value
 * @key: The key string
 * @value: The value string
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: Pointer to the hash table
 * @key: The key (cannot be an empty string)
 * @value: The value associated with the key
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *temp, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (update_node(temp, value));
		temp = temp->next;
	}

	new_node = create_node(key, value);
	if (!new_node)
		return (0);

	new_node->n_
