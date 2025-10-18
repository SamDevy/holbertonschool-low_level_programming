/* 100-realloc.c */
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated block (may be NULL)
 * @old_size: current block size in bytes
 * @new_size: requested block size in bytes
 *
 * Return: pointer to new block, or NULL when appropriate
 *
 * Rules implemented to match checker:
 * - If new_size == 0: if ptr != NULL free(ptr); return NULL.
 * - If ptr == NULL and new_size > 0: malloc(new_size).
 * - If new_size == old_size: return ptr.
 * - Otherwise: allocate new block, copy min(old_size, new_size) bytes,
 *   free old block, return new pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned char *newp;
	unsigned char *oldp;
	unsigned int n, i;

	/* If new_size == 0: free if needed and return NULL */
	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}

	/* If ptr is NULL and new_size > 0, just malloc */
	if (ptr == NULL)
		return (malloc(new_size));

	/* If sizes equal, nothing to do */
	if (new_size == old_size)
		return (ptr);

	/* Allocate new block */
	newp = (unsigned char *)malloc(new_size);
	if (newp == NULL)
		return (NULL);

	/* Copy min(old_size, new_size) bytes */
	oldp = (unsigned char *)ptr;
	n = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < n; i++)
		newp[i] = oldp[i];

	/* Free old block */
	free(ptr);

	return ((void *)newp);
}
