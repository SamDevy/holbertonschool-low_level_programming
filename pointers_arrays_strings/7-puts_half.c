#include <stdio.h>

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: The string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0, i, start;

	/* Calculate the length of the string */
	while (str[len] != '\0')
		len++;

	/* Calculate the starting index for the second half */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* Print from start to end using printf */
	for (i = start; i < len; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
}
