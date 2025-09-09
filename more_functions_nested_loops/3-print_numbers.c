/* 3-print_numbers.c */
#include "main.h"
/**
 * print_numbers - Prints the numbers from 0 to 9, followed by a new line.
 *
 * Return: Nothing.
 */

void print_numbers(void)
{
	int i;

	/* Print numbers from 0 to 9 */
	for (i = 0; i <= 9; i++)
		_putchar(i + '0');
	/* Print new line */
	_putchar('\n');
}
