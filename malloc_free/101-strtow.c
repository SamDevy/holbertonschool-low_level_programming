/* 101-strtow.c */
#include <stddef.h>
#include <stdlib.h>

/**
 * _isspace - Checks if a character is a space
 * @c: character to check
 *
 * Return: 1 if space, 0 otherwise
 */
static int _isspace(char c)
{
	return (c == ' ');
}

/**
 * _count_words - Counts words separated by spaces
 * @str: input string
 *
 * Return: number of words (0 if str is NULL or empty)
 */
static int _count_words(char *str)
{
	int i = 0, words = 0;

	if (str == NULL || str[0] == '\0')
		return (0);

	while (str[i] != '\0')
	{
		while (str[i] != '\0' && _isspace(str[i]))
			i++;
		if (str[i] != '\0' && !_isspace(str[i]))
		{
			words++;
			while (str[i] != '\0' && !_isspace(str[i]))
				i++;
		}
	}
	return (words);
}

/**
 * _word_bounds - Finds start and end indices of next word
 * @str: input string
 * @pos: current scan position (in/out)
 * @start: out param for word start index
 * @end: out param for word end index (exclusive)
 *
 * Return: 1 if a word found, 0 otherwise
 */
static int _word_bounds(char *str, int *pos, int *start, int *end)
{
	int i;

	i = *pos;
	while (str[i] != '\0' && _isspace(str[i]))
		i++;

	if (str[i] == '\0')
	{
		*pos = i;
		return (0);
	}

	*start = i;
	while (str[i] != '\0' && !_isspace(str[i]))
		i++;

	*end = i;
	*pos = i;
	return (1);
}

/**
 * _free_words - Frees allocated words when a failure occurs
 * @tab: array of strings
 * @count: number of words currently allocated
 *
 * Return: Nothing.
 */
static void _free_words(char **tab, int count)
{
	int i;

	if (tab == NULL)
		return;

	for (i = 0; i < count; i++)
		free(tab[i]);
	free(tab);
}

/**
 * strtow - Splits a string into words separated by spaces
 * @str: input string
 *
 * Return: array of strings; last element is NULL.
 *         NULL if str is NULL/empty or on allocation failure.
 */
char **strtow(char *str)
{
	char **tab;
	int words, w, pos, start, end, len, i;

	words = _count_words(str);
	if (words == 0)
		return (NULL);

	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);

	w = 0;
	pos = 0;
	while (_word_bounds(str, &pos, &start, &end) && w < words)
	{
		len = end - start;
		tab[w] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[w] == NULL)
		{
			_free_words(tab, w);
			return (NULL);
		}

		i = 0;
		while (i < len)
		{
			tab[w][i] = str[start + i];
			i++;
		}
		tab[w][len] = '\0';
		w++;
	}

	tab[w] = NULL;
	return (tab);
}
