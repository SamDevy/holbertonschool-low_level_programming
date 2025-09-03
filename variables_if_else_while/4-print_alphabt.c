#include <stdio.h>

/**
 * main - Prints lowercase letters a-z except 'e' and 'q'
 *
 * Program prints all lowercase letters except 'e' and 'q' in one line.
 * Uses a while loop and putchar for output.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if (ch != 'q' && ch != 'e')
			putchar(ch);
		ch++;
	}
	putchar('\n');

	return (0);
}
