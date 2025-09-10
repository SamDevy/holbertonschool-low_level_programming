#include <stdio.h>

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: The string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	/* Find the length of the string */
	while (str[len] != '\0')
		len++;

	/* If odd, skip the middle character */
	if (len % 2 == 0)
		i = len / 2;
	else
		i = (len - 1) / 2 + 1;

	/* Print the second half */
	while (i < len)
	{
		putchar(str[i]);
		i++;
	}
	putchar('\n');
}
