#include <stdlib.h>

/* Prototypes */
int _putchar(char c);
int is_digit(char *s);
int _strlen(char *s);
void errors(void);

/**
 * is_digit - checks if a string contains only digits
 * @s: string to evaluate
 *
 * Return: 1 if only digits and not empty, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (s[i] == '\0')
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
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * errors - prints "Error" and exits with status 98
 */
void errors(void)
{
	char *msg = "Error";
	int i = 0;

	while (msg[i] != '\0')
	{
		_putchar(msg[i]);
		i++;
	}
	_putchar('\n');
	exit(98);
}

/**
 * main - multiplies two positive base-10 numbers
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, total_len, i, j, leading_zeros;
	int *result;

	if (argc != 3)
		errors();

	s1 = argv[1];
	s2 = argv[2];
	if (!is_digit(s1) || !is_digit(s2))
		errors();

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	total_len = len1 + len2;

	result = (int *)malloc(sizeof(int) * total_len);
	if (result == NULL)
		errors();

	/* zero-initialize result (calloc not allowed) */
	for (i = 0; i < total_len; i++)
		result[i] = 0;

	/* multiply digits (no carries yet) */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
			result[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
	}

	/* propagate carries */
	for (i = total_len - 1; i > 0; i--)
	{
		result[i - 1] += result[i] / 10;
		result[i] %= 10;
	}

	/* print skipping leading zeros */
	leading_zeros = 1;
	for (i = 0; i < total_len; i++)
	{
		if (result[i] != 0)
			leading_zeros = 0;
		if (!leading_zeros)
			_putchar(result[i] + '0');
	}
	if (leading_zeros)
		_putchar('0');

	_putchar('\n');
	free(result);
	return (0);
}
