/* 1-strdup.c */
/**
 * _strdup - Duplicates a string into a newly allocated buffer
 * @str: source string (must not be NULL)
 *
 * Return: Pointer to duplicated string, or NULL if str is NULL or malloc fails
 */
#include <stdlib.h>

char *_strdup(char *str)
{
	unsigned int len = 0, i = 0;
	char *dup;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';

	return (dup);
}
