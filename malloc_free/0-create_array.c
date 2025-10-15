/* 0-create_array.c */
/**
 * create_array - Creates a char array and initializes it with a given char
 * @size: number of elements to allocate
 * @c: initialization character
 *
 * Return: Pointer to the newly allocated array,
 *         or NULL if size == 0 or if allocation fails
 */
#include <stdlib.h>

char *create_array(unsigned int size, char c)
{
	char *buf;
	unsigned int i;

	if (size == 0)
		return (NULL);

	buf = (char *)malloc(size * sizeof(char));
	if (buf == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		buf[i] = c;

	return (buf);
}
