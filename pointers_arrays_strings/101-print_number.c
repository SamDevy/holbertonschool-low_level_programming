#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: nothing
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		/* Handle edge case for INT_MIN */
		if (n / 10 != 0)
			print_number(-(n / 10));
		_putchar(-(n % 10) + '0');
	}
	else
	{
		if (n / 10 != 0)
			print_number(n / 10);
		_putchar((n % 10) + '0');
	}
}
