/* hash_tables.h */
#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string (unique in the table)
 * @value: The value corresponding to a key
 * @next: Pointer to the next node (for chaining)
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
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* Create a hash table with a given size */
hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */
