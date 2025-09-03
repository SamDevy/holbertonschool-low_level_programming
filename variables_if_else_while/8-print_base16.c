#include <stdio.h>

/**
 * main - Prints all hexadecimal digits in lowercase, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char hex_digits[] = "0123456789abcdef";
	int i = 0;

	while (hex_digits[i] != '\0')
	{
		putchar(hex_digits[i]);
		i++;
	}
	putchar('\n');

	return (0);
}
