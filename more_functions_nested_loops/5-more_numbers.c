#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers from 0 to 14,
 * followed by a new line.
 *
 * Return: Nothing.
 */

void more_numbers(void)
{
	int line, num;

	for (line = 0; line < 10; line++)
	{
		for (num = 0; num <= 14; num++)
		{
			/* Print tens digit if number >= 10 */
			if (num >= 10)
				_putchar((num / 10) + '0');
			/* Print units digit */
			_putchar((num % 10) + '0');
		}
		_putchar('\n');
	}
}
