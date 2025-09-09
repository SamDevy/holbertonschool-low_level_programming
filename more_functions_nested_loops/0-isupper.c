/* 0-isupper.c */

/**
 * _isupper - Checks for uppercase character.
 * @c: The character to check.
 *
 * Return: 1 if c is uppercase, 0 otherwise.
 */
int _isupper(int c)
{
    /* Return 1 if c is between 'A' and 'Z', else 0 */
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}
