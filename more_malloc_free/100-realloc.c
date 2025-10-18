/* 100-realloc.c */
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated block (may be NULL)
 * @old_size: size of the current block in bytes
 * @new_size: requested new size in bytes
 *
 * Return: pointer to new block, or NULL when appropriate
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned char *newp, *oldp;
	unsigned int n, i;

	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	newp = (unsigned char *)malloc(new_size);
	if (newp == NULL)
		return (NULL);

	oldp = (unsigned char *)ptr;
	n = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < n; i++)
		newp[i] = oldp[i];

	free(ptr);
	return ((void *)newp);
}
