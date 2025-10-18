/* 0-malloc_checked.c */
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory and exits with 98 on failure
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory (never NULL; process exits if malloc fails)
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);
	return (p);
}
