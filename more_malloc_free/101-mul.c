#include <stdlib.h>
#include <stdio.h>

/* Function Prototypes */
int _putchar(char c);
int is_digit(char *s);
int _strlen(char *s);
void errors(void);

/**
 * is_digit - checks if a string contains only digit characters
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

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
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * errors - handles errors for main by printing "Error" and exiting
 */
void errors(void)
{
	char *error_msg = "Error";
	int i;

	for (i = 0; error_msg[i] != '\0'; i++)
		_putchar(error_msg[i]);
	_putchar('\n');
	exit(98);
}

/**
 * main - multiplies two positive numbers passed as arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, total_len, i, j, carry, digit1, digit2, *result;
	int leading_zeros = 1;

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
	if (!result)
		return (1); /* Malloc failure */

	/* Perform multiplication */
	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i] += carry;
	}

	/* Print the result, skipping leading zeros */
	for (i = 0; i < total_len; i++)
	{
		if (result[i] != 0)
			leading_zeros = 0;
		if (!leading_zeros)
			_putchar(result[i] + '0');
	}

	/* If result is 0, print a single '0' */
	if (leading_zeros)
		_putchar('0');

	_putchar('\n');
	free(result);
	return (0);
}
