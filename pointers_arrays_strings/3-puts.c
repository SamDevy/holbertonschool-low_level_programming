#include "main.h"
#include <unistd.h>

/**
 * _puts - Prints a string, followed by a new line, to stdout
 * @str: The string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	/* Print each character using write() */
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}

	/* Print newline */
	write(1, "\n", 1);
}
