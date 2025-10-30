/* hash_tables.h */
#ifndef HOLBERTON_HASH_TABLES_H
#define HOLBERTON_HASH_TABLES_H

#include <stdlib.h>

/* Hash table node structure */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/* Hash table container structure */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* API */
hash_table_t *hash_table_create(unsigned long int size);

#endif /* HOLBERTON_HASH_TABLES_H */
