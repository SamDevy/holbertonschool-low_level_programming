/* 1-string_nconcat.c */
/**
 * _len - Returns the length of a C-string
 * @s: input string (may be NULL)
 *
 * Return: number of characters before '\0' (0 if s is NULL)
 */
static unsigned int _len(char *s)
{
	unsigned int n = 0;

	if (s == NULL)
		return (0);

	while (s[n] != '\0')
		n++;
	return (n);
}

/**
 * string_nconcat - Concatenates s1 with first n bytes of s2
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 * @n: number of bytes to take from s2
 *
 * Return: Pointer to newly allocated "s1 + s2[0..n-1]" null-terminated,
 *         or NULL on failure.
 *
 * Why: Computes exact sizes, clips n to s2 length, allocates once,
 *      copies by index, and appends '\0'.
 */
#include <stdlib.h>

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, take, total, i, j;
	char *buf;

	len1 = _len(s1);
	len2 = _len(s2);

	/* Clip n to s2 length */
	take = (n >= len2) ? len2 : n;

	/* Total bytes = len1 + take + 1 for '\0' */
	total = len1 + take + 1;

	buf = (char *)malloc(sizeof(char) * total);
	if (buf == NULL)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		buf[i] = s1[i];

	/* Copy first `take` bytes of s2 */
	for (j = 0; j < take; j++)
		buf[i + j] = s2[j];

	/* Null-terminate */
	buf[len1 + take] = '\0';

	return (buf);
}
