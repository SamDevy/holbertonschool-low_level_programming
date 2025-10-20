/* 4-new_dog.c */
/**
 * new_dog - Creates a new dog with deep-copied name and owner
 * @name: dog's name (source string)
 * @age: dog's age
 * @owner: owner's name (source string)
 *
 * Return: pointer to newly allocated dog_t, or NULL on failure
 */
#include <stdlib.h>
#include "dog.h"

/* local strlen (C90) */
static int _slen(const char *s)
{
	int n = 0;

	if (s == (const char *)0)
		return (0);
	while (s[n] != '\0')
		n++;
	return (n);
}

/* local strcpy */
static void _scpy(char *dst, const char *src)
{
	int i = 0;

	if (dst == (char *)0 || src == (const char *)0)
		return;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *ncopy, *ocopy;
	int ln, lo;

	d = (dog_t *)malloc(sizeof(dog_t));
	if (d == (dog_t *)0)
		return (0);

	ln = _slen(name);
	lo = _slen(owner);

	ncopy = (ln > 0) ? (char *)malloc((unsigned int)ln + 1U) : (char *)0;
	ocopy = (lo > 0) ? (char *)malloc((unsigned int)lo + 1U) : (char *)0;

	if ((ln > 0 && ncopy == (char *)0) || (lo > 0 && ocopy == (char *)0))
	{
		if (ncopy != (char *)0)
			free(ncopy);
		if (ocopy != (char *)0)
			free(ocopy);
		free(d);
		return (0);
	}

	if (ncopy != (char *)0)
		_scpy(ncopy, name);
	if (ocopy != (char *)0)
		_scpy(ocopy, owner);

	d->name = (ncopy != (char *)0) ? ncopy : (char *)name;
	d->age = age;
	d->owner = (ocopy != (char *)0) ? ocopy : (char *)owner;

	return (d);
}
