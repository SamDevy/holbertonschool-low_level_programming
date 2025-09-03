#include <stdio.h>

/**
 * main - Prints all lowercase and uppercase English letters, then a newline.
 *
 * The program first creates arrays for lowercase and uppercase letters.
 * It uses while loops to fill each array with the correct letters.
 * Then, it prints all lowercase letters, followed by all uppercase letters.
 * Finally, it prints a newline character at the end.
 * Only the putchar function is used for output.
 */
int main(void)
{
	char small_letters[27];
	char capital_letters[27];
	int i = 0;
	char letter = 'a';

	while (letter <= 'z')
	{
		small_letters[i] = letter;
		i++;
		letter++;
	}
	small_letters[i] = '\0';

	i = 0;
	letter = 'A';

	while (letter <= 'Z')
	{
		capital_letters[i] = letter;
		i++;
		letter++;
	}
	capital_letters[i] = '\0';

	i = 0;
	while (small_letters[i] != '\0')
	{
		putchar(small_letters[i]);
		i++;
	}

	i = 0;
	while (capital_letters[i] != '\0')
	{
		putchar(capital_letters[i]);
		i++;
	}

	putchar('\n');
	return (0);
}
