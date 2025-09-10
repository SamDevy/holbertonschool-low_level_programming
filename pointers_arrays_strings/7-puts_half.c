#include <unistd.h>

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

	/* Calculate the length of the string */
	while (str[len] != '\0')
		len++;

	/* Determine the starting index of the second half */
	if (len % 2 == 0)
		i = len / 2;
	else
		i = (len - 1) / 2 + 1;

	/* Write each character to stdout */
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}

	/* Write newline */
	write(1, "\n", 1);
}
