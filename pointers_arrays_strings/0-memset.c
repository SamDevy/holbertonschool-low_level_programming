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
 * Way 2: Using a for loop with pointer arithmetic
 */

char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    /* Way 1: Using array indexing */
    for (i = 0; i < n; i++)
    {
        s[i] = b; /* Fill each byte with value b */
    }

    /* Way 2: Using pointer arithmetic */
    /*
    char *p = s;
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        *(p + i) = b; // Fill each byte with value b
    }
    */

    return s; /* Return pointer to the memory area */
}
