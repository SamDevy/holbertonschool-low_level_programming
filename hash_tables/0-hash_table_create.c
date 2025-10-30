/* 0-hash_table_create.c */
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table with given size
 * @size: Number of buckets in the hash table
 *
 * Return:
 * Pointer to a newly created hash_table_t on success,
 * NULL on error or if size is 0.
 *
 * Why:
 * - Allocate the table struct.
 * - Allocate the bucket array.
 * - Initialize all buckets to NULL (using calloc).
 * - Validate inputs and allocations.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	/* Size 0 is invalid; avoid creating unusable table */
	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;

	/* Use calloc to zero-initialize bucket pointers to NULL */
	ht->array = calloc(size, sizeof(hash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	return (ht);
}
