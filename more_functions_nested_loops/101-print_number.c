#include "main.h"

/**
 * print_number - Prints an integer using only _putchar.
 * @n: The integer to print.
 *
 * Return: Nothing.
 */
void print_number(int n)
{
	unsigned int num;

	/* Handle negative numbers */
	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	/* Print digits recursively */
	if (num / 10)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}
