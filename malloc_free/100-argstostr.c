/* 100-argstostr.c */
/**
 * argstostr - Concatenates all program arguments into a single string
 * @ac: argument count
 * @av: argument vector (array of strings)
 *
 * Return: Pointer to newly allocated string containing all args,
 *         each followed by '\n'; NULL if ac == 0, av == NULL, or on failure
 *
 * Description:
 * - Computes total length needed: sum of arg lengths + one '\n' per arg + 1 for '\0'.
 * - Allocates buffer, copies args sequentially, inserts '\n' after each.
 */
#include <stdlib.h>

char *argstostr(int ac, char **av)
{
	int i, j;
	int total = 0;
	char *buf, *p;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* First pass: compute total bytes needed */
	for (i = 0; i < ac; i++)
	{
		if (av[i] != NULL)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				total++;
				j++;
			}
		}
		/* one newline per argument */
		total++;
	}

	/* +1 for final null terminator */
	buf = (char *)malloc((total + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);

	/* Second pass: copy content and insert '\n' after each argument */
	p = buf;
	for (i = 0; i < ac; i++)
	{
		if (av[i] != NULL)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				*p++ = av[i][j];
				j++;
			}
		}
		*p++ = '\n';
	}
	*p = '\0';

	return (buf);
}
