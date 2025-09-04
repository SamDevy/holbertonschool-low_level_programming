/* 102-print_comb5.c */
#include <stdio.h>

/**
 * main - prints all possible combinations of two two-digit numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = i + 1; j < 100; j++)
		{
			/* Way 1: Add 48 to convert digit to ASCII */
			putchar((i / 10) + 48); /* tens digit of first number */
			putchar((i % 10) + 48); /* units digit of first number */
			putchar(' ');
			putchar((j / 10) + 48); /* tens digit of second number */
			putchar((j % 10) + 48); /* units digit of second number */

			/* Way 2: Use '0' + digit to convert to ASCII */
			/* putchar('0' + (i / 10)); */
			/* putchar('0' + (i % 10)); */
			/* putchar(' '); */
			/* putchar('0' + (j / 10)); */
			/* putchar('0' + (j % 10)); */

			if (!(i == 98 && j == 99))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
