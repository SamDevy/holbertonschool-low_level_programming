/* 0-hash_table_create.c */
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table with given size
 * @size: number of buckets in the hash table
 *
 * Return: pointer to newly created hash_table_t, or NULL on error
 *
 * Why this approach:
 * - We allocate the table struct, then allocate the array of bucket pointers.
 * - We use calloc to zero-initialize the bucket array so all pointers start as NULL.
 * - We validate inputs and each allocation to avoid undefined behavior.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	/* Validate size; a table of size 0 is not useful */
	if (size == 0)
		return (NULL);

	/* Allocate the hash table struct */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;

	/* Allocate buckets array; each bucket is a pointer to hash_node_t */
	ht->array = calloc(size, sizeof(hash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	return (ht);
}
