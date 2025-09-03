#include <stdio.h>

/**
 * main - Prints all single-digit numbers separated by comma and space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i <= 9)
	{
		putchar(i + '0');
		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	putchar('\n');

	return (0);
}
