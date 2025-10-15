/* 2-str_concat.c */
/**
 * str_concat - Concatenates two strings into a newly allocated buffer
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 *
 * Return: Pointer to new "s1+s2" null-terminated string, or NULL on failure
 */
#include <stdlib.h>

char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0, len2 = 0, i = 0, j = 0;
	char *buf;

	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;

	buf = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);

	while (i < len1)
	{
		buf[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		buf[i + j] = s2[j];
		j++;
	}
	buf[len1 + len2] = '\0';

	return (buf);
}
