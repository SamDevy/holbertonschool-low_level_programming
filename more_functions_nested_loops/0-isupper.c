/* 0-isupper.c */

/**
 * _isupper - Checks if a character is uppercase.
 * @c: The character to check.
 *
 * Return: 1 if c is uppercase, 0 otherwise.
 */
int _isupper(int c)
{
	/* Check if c is between 'A' and 'Z' in ASCII */
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
