/* 4-print_most_numbers.c */

/**
 * print_most_numbers - Prints numbers from 0 to 9 except 2 and 4, followed by a new line.
 *
 * Return: Nothing.
 */
void print_most_numbers(void)
{
	int i;

	/* Print numbers from 0 to 9 except 2 and 4 */
	for (i = 0; i <= 9; i++)
	{
		if (i != 2 && i != 4)
			_putchar(i + '0');
	}
	/* Print new line */
	_putchar('\n');
}
