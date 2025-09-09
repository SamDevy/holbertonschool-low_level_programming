#include "main.h"

/**
 * print_num - Prints a number with proper spacing for times table.
 * @n: The number to print.
 *
 * Return: Nothing.
 */
void print_num(int n)
{
	if (n < 10)
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(n + '0');
	}
	else if (n < 100)
	{
		_putchar(' ');
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
}

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number of the times table to print (0 <= n <= 15).
 *
 * Return: Nothing.
 */
void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (j == 0)
				_putchar('0');
			else
			{
				_putchar(',');
				_putchar(' ');
				print_num(i * j);
			}
		}
		_putchar('\n');
	}
}
