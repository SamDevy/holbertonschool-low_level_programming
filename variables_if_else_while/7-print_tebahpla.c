#include <stdio.h>

/**
 * main - Prints the lowercase alphabet in reverse
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lasty = 'z';

	while (lasty >= 'a')
	{
		putchar(lasty);
		lasty--;
	}
	putchar('\n');

	return (0);
}
