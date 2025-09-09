#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number of the times table to print (0 <= n <= 15).
 *
 * Return: Nothing.
 */
void print_times_table(int n)
{
	int i = 0, j, p;

	if (n < 0 || n > 15)
		return;

	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			p = i * j;
			if (j == 0)
			{
				_putchar('0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (p < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(p + '0');
				}
				else if (p < 100)
				{
					_putchar(' ');
					_putchar((p / 10) + '0');
					_putchar((p % 10) + '0');
				}
				else
				{
					_putchar((p / 100) + '0');
					_putchar(((p / 10) % 10) + '0');
					_putchar((p % 10) + '0');
				}
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}
