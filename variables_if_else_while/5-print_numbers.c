#include <stdio.h>

/**
 * main - Prints digits 0 to 9
 *
 * Uses putchar in a while loop to print digits from 0 to 9,
 * then prints a newline at the end.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char to_9 = '0';

	while (to_9 <= '9')
	{
		putchar(to_9);
		to_9++;
	}
	putchar('\n');

	return (0);
}
