#include <stdio.h>

/**
 * puts2 - Prints every other character of a string, starting with the first
 * @str: The string to print
 *
 * Return: void
 */
void puts2(char *str)
{
	int i;

	/* Print every other character using printf */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
			printf("%c", str[i]);
	}
	printf("\n");
}
