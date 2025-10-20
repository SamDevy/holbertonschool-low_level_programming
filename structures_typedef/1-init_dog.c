/* 1-init_dog.c */
/**
 * init_dog - Initializes a struct dog with given values
 * @d: pointer to struct dog to initialize
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: Nothing.
 */
#include "dog.h"

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == (struct dog *)0)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
