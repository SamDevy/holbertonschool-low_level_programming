#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: The string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0;
	int i;
	char temp;

	/* Find the length of the string */
	while (s[len] != '\0')
		len++;

	/* Swap characters from both ends moving toward the center */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
