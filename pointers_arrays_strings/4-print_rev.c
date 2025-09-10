#include "main.h"
#include <unistd.h>

/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: The string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	int len = 0;

	/* Find the length of the string */
	while (s[len] != '\0')
		len++;

	/* Print the string in reverse */
	while (len > 0)
	{
		len--;
		write(1, &s[len], 1);
	}

	/* Print the newline */
	write(1, "\n", 1);
}
