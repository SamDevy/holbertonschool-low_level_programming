/* hash_tables.h */
#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string (unique in the table)
 * @value: The value corresponding to a key
 * @next: Pointer to the next node (for chaining)
 *
 * Description:
 * Each node stores a key/value pair. Collisions are handled
 * by separate chaining, linking nodes in the same bucket.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: Array of pointers to bucket heads
 *
 * Description:
 * Each array cell points to the head of a linked list of
 * hash_node_t elements. Collisions are handled by chaining.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* Creates a new hash table with the given size. */
hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */
