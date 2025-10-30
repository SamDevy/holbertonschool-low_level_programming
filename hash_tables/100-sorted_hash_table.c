#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/* ================== CREATE ================== */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return NULL;

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (!ht->array)
    {
        free(ht);
        return NULL;
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return ht;
}

/* ================== INSERT IN SORTED LIST ================== */
void shash_table_add_sorted(shash_table_t *ht, shash_node_t *node)
{
    shash_node_t *current;

    if (!ht->shead || strcmp(node->key, ht->shead->key) < 0)
    {
        /* Insert at head */
        node->snext = ht->shead;
        node->sprev = NULL;
        if (ht->shead)
            ht->shead->sprev = node;
        else
            ht->stail = node;
        ht->shead = node;
        return;
    }

    current = ht->shead;
    while (current->snext && strcmp(node->key, current->snext->key) > 0)
        current = current->snext;

    node->snext = current->snext;
    node->sprev = current;

    if (current->snext)
        current->snext->sprev = node;
    else
        ht->stail = node;

    current->snext = node;
}

/* ================== SET ================== */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *node, *current;
    char *val_copy;

    if (!ht || !key || !*key)
        return 0;

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current
