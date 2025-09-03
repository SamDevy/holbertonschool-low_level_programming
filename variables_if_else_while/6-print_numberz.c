#include <stdio.h>

/**
 * main - Prints numbers 0 to 9 using putchar and while loop
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i <= 9)
	{
		putchar(i + '0');
		i++;
	}
	putchar('\n');

	return (0);
}
