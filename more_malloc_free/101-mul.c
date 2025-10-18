#include <stdlib.h>

/* Provided prototypes */
int _putchar(char c);
int is_digit(char *s);
int _strlen(char *s);
void errors(void);

/**
 * is_digit - Checks if a string contains only digits and is not empty
 * @s: String to check
 * Return: 1 if only digits and not empty, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * errors - Prints "Error" and exits with status 98
 */
void errors(void)
{
	char *msg = "Error\n";
	int i = 0;

	while (msg[i])
	{
		_putchar(msg[i]);
		i++;
	}
	exit(98);
}

/**
 * main - Multiplies two positive numbers passed as strings
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, exits with 98 on error
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, total_len;
	int i, j;
	int *result;
	int leading_zero = 1;

	if (argc != 3)
		errors();

	s1 = argv[1];
	s2 = argv[2];
	if (!is_digit(s1) || !is_digit(s2))
		errors();

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	total_len = len1 + len2;

	result = calloc(total_len, sizeof(int));
	if (result == NULL)
		errors();

	/* Multiply */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = s1[i] - '0';
			int digit2 = s2[j] - '0';
			result[i + j + 1] += digit1 * digit2;
		}
	}

	/* Handle carry */
	for (i = total_len - 1; i > 0; i--)
	{
		result[i - 1] += result[i] / 10;
		result[i] %= 10;
	}

	/* Print result, skipping leading zeros */
	for (i = 0; i < total_len; i++)
	{
		if (result[i] != 0)
			leading_zero = 0;
		if (!leading_zero)
			_putchar(result[i] + '0');
	}

	if (leading_zero) /* If result is zero */
		_putchar('0');

	_putchar('\n');
	free(result);
	return (0);
}
