/* 1-isdigit.c */

/**
 * _isdigit - Checks if a character is a digit (0-9).
 * @c: The character to check.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	/* Check if c is between '0' and '9' in ASCII */
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
