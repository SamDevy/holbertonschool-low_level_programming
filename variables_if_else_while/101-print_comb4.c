/* 101-print_comb4.c */
#include <stdio.h>

/**
 * main - prints all possible different combinations of three digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j, k;

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			for (k = j + 1; k < 10; k++)
			{
				/* Way 1: Add 48 to convert digit to ASCII */
				putchar(i + 48);
				putchar(j + 48);
				putchar(k + 48);

				/* Way 2: Use '0' + digit to convert to ASCII */
				/* putchar('0' + i); */
				/* putchar('0' + j); */
				/* putchar('0' + k); */

				if (!(i == 7 && j == 8 && k == 9))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
