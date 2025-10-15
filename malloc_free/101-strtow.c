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
 * _count_words - Counts words in a string separated by spaces
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
		/* Skip spaces */
		while (str[i] != '\0' && _isspace(str[i]))
			i++;

		/* If at start of a word, count it */
		if (str[i] != '\0' && !_isspace(str[i]))
		{
			words++;
			/* Move to end of word */
			while (str[i] != '\0' && !_isspace(str[i]))
				i++;
		}
	}
	return (words);
}

/**
 * _word_len - Measures length of a word starting at str[pos]
 * @str: input string
 * @pos: start index
 *
 * Return: length of the word
 */
static int _word_len(char *str, int pos)
{
	int len = 0;

	while (str[pos] != '\0' && !_isspace(str[pos]))
	{
		len++;
		pos++;
	}
	return (len);
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
 * Return: array of strings, each one word; last element is NULL.
 *         NULL if str is NULL/empty or on allocation failure.
 */
char **strtow(char *str)
{
	char **tab;
	int i = 0, w = 0, start, len, words;

	words = _count_words(str);
	if (words == 0)
		return (NULL);

	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);

	while (str[i] != '\0' && w < words)
	{
		/* Skip spaces */
		while (str[i] != '\0' && _isspace(str[i]))
			i++;

		if (str[i] == '\0')
			break;

		/* Mark start of word and find its length */
		start = i;
		len = _word_len(str, start);

		/* Allocate and copy the word */
		tab[w] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[w] == NULL)
		{
			_free_words(tab, w);
			return (NULL);
		}

		/* Copy characters */
		for (i = start; i < start + len; i++)
			tab[w][i - start] = str[i];
		tab[w][len] = '\0';
		w++;

		/* Continue from end of the word */
		/* i is already at start + len */
	}

	tab[w] = NULL;
	return (tab);
}
