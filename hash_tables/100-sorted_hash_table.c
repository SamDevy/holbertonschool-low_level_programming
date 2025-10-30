#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/* Create sorted hash table */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (!ht->array)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;
    return (ht);
}

/* Insert key/value into sorted hash table */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *node, *current, *tmp;

    if (!ht || !key || !*key || !value)
        return (0);

    index = djb2((const unsigned char *)key) % ht->size;
    current = ht->array[index];

    /* Update if key exists */
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return (1);
        }
        current = current->next;
    }

    /* Create new node */
    node = malloc(sizeof(shash_node_t));
    if (!node)
        return (0);
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = ht->array[index];
    ht->array[index] = node;

    /* Insert in sorted linked list */
    if (!ht->shead)
    {
        node->sprev = NULL;
        node->snext = NULL;
        ht->shead = node;
        ht->stail = node;
    }
    else
    {
        tmp = ht->shead;
        while (tmp && strcmp(node->key, tmp->key) > 0)
            tmp = tmp->snext;

        if (!tmp) /* Insert at end */
        {
            node->sprev = ht->stail;
            node->snext = NULL;
            ht->stail->snext = node;
            ht->stail = node;
        }
        else if (!tmp->sprev) /* Insert at beginning */
        {
            node->sprev = NULL;
            node->snext = tmp;
            tmp->sprev = node;
            ht->shead = node;
        }
        else /* Insert in middle */
        {
            node->snext = tmp;
            node->sprev = tmp->sprev;
            tmp->sprev->snext = node;
            tmp->sprev = node;
        }
    }

    return (1);
}

/* Print sorted hash table in order */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int first = 1;

    if (!ht)
        return;

    printf("{");
    node = ht->shead;
    while (node)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->snext;
    }
    printf("}\n");
}

/* Print sorted hash table in reverse order */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int first = 1;

    if (!ht)
        return;

    printf("{");
    node = ht->stail;
    while (node)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->sprev;
    }
    printf("}\n");
}

/* Delete sorted hash table */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *tmp;
    unsigned long int i;

    if (!ht)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            tmp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = tmp;
        }
    }

    free(ht->array);
    free(ht);
}
