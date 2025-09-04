/* 100-print_comb3.c */
#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			/* Way 1: Add 48 to convert digit to ASCII */
			putchar(i + 48);
			putchar(j + 48);

			/* Way 2: Use '0' + digit to convert to ASCII */
			/* putchar('0' + i); */
			/* putchar('0' + j); */

			if (!(i == 8 && j == 9))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
