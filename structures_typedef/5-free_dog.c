/* 5-free_dog.c */
/**
 * free_dog - Frees a dog_t and its deep-copied fields (separate allocs)
 * @d: pointer to dog_t to free
 *
 * Return: Nothing.
 */
#include <stdlib.h>
#include "dog.h"

void free_dog(dog_t *d)
{
	if (d == (dog_t *)0)
		return;

	/* Free deep copies if they exist */
	if (d->name != (char *)0)
		free(d->name);
	if (d->owner != (char *)0)
		free(d->owner);

	free(d);
}
