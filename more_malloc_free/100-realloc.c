/* 100-realloc.c */
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: pointer to the previously allocated block (may be NULL)
 * @old_size: current block size in bytes
 * @new_size: requested block size in bytes
 *
 * Return: pointer to new block (or NULL when appropriate)
 *
 * Rules:
 * - If ptr == NULL: behaves like malloc(new_size).
 * - If new_size == old_size: return ptr unchanged.
 * - If new_size == 0 and ptr != NULL: free(ptr) and return NULL.
 * - Copy the minimum of old_size and new_size bytes into the new block.
 * - If malloc fails: return NULL; old ptr remains untouched.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned char *newp;
	unsigned char *oldp;
	unsigned int i;

	/* Handle special cases first */
	if (ptr == NULL)
		return (new_size == 0 ? NULL : malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* Allocate new block */
	newp = (unsigned char *)malloc(new_size);
	if (newp == NULL)
		return (NULL);

	/* Copy min(old_size, new_size) bytes */
	oldp = (unsigned char *)ptr;
	i = 0;
	while (i < old_size && i < new_size)
	{
		newp[i] = oldp[i];
		i++;
	}

	/* Free old block and return new pointer */
	free(ptr);
	return ((void *)newp);
}
