#include "main.h"

/**
 * skip_stars - skips consecutive '*' characters in s2
 * @s2: string pointer
 *
 * Return: pointer to first non-'*' character
 */
char *skip_stars(char *s2)
{
	if (*s2 == '*' && *(s2 + 1) == '*')
		return (skip_stars(s2 + 1));
	return (s2);
}

/**
 * wildcmp - compares two strings and returns 1 if identical
 * @s1: first string
 * @s2: second string (may contain *)
 *
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	s2 = skip_stars(s2);

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
		return (
			wildcmp(s1, s2 + 1) || /* '*' matches empty */
			(*s1 != '\0' && wildcmp(s1 + 1, s2)) /* '*' matches one char */
		);

	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
