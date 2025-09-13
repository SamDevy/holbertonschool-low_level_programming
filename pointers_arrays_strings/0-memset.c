/* 0-memset.c */

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area to fill
 * @b: the byte to fill the memory with
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 *
 * Way 1: Using a for loop with array indexing
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    /* Fill each byte of the memory area with the value of b */
    for (i = 0; i < n; i++)
    {
        s[i] = b;
    }

    return (s);
}
