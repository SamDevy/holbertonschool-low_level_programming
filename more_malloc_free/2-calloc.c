/* 2-calloc.c */
/**
 * _calloc - Allocates zero-initialized memory for an array
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: Pointer to newly allocated memory set to zero,
 *         or NULL if nmemb == 0, size == 0, or malloc fails.
 *
 * Why: Simple byte-by-byte zeroing; clear and portable (no libc memset).
 */
#include <stdlib.h>

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total;
	unsigned char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Compute total bytes; beware theoretical overflow on extreme inputs */
	total = nmemb * size;

	p = (unsigned char *)malloc(total);
	if (p == NULL)
		return (NULL);

	/* Zero-initialize the whole block */
	for (i = 0; i < total; i++)
		p[i] = 0;

	return ((void *)p);
}
