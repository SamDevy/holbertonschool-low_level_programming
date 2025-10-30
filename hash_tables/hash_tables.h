/* hash_tables.h */
#ifndef HOLBERTON_HASH_TABLES_H
#define HOLBERTON_HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: Key string (unique in the table)
 * @value: Value for the key
 * @next: Next node in the chain
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: Size of the array
 * @array: Array of bucket head pointers
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);

#endif /* HOLBERTON_HASH_TABLES_H */
