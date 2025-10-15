/* 100-argstostr.c */
#include <stddef.h>
#include <stdlib.h>

/**
 * _arg_len - Returns length of a C-string
 * @s: string pointer (may be NULL)
 *
 * Return: length (0 if s is NULL)
 */
static int _arg_len(char *s)
{
	int n = 0;

	if (s == NULL)
		return (0);

	while (s[n] != '\0')
		n++;
	return (n);
}

/**
 * _total_len - Computes total bytes needed for argstostr
 * @ac: argument count
 * @av: argument vector
 *
 * Return: total = sum(len(av[i])) + ac newlines + 1 for '\0'
 */
static int _total_len(int ac, char **av)
{
	int i, total = 0;

	for (i = 0; i < ac; i++)
		total += _arg_len(av[i]) + 1;
	return (total + 1);
}

/**
 * argstostr - Concatenates all program arguments into one string
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Newly allocated "args\n..." string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, total;
	char *buf;

	if (ac == 0 || av == NULL)
		return (NULL);

	total = _total_len(ac, av);
	buf = (char *)malloc(sizeof(char) * total);
	if (buf == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		if (av[i] != NULL)
		{
			while (av[i][j] != '\0')
			{
				buf[k++] = av[i][j];
				j++;
			}
		}
		buf[k++] = '\n';
	}
	buf[k] = '\0';
	return (buf);
}
