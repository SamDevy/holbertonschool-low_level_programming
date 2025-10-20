/* 2-print_dog.c */
/**
 * print_dog - Prints a struct dog (Name/Age/Owner)
 * @d: pointer to struct dog
 *
 * Return: Nothing. If d is NULL, prints nothing.
 *         If name/owner is NULL, prints "(nil)" for that field.
 */
#include <stdio.h>
#include "dog.h"

void print_dog(struct dog *d)
{
	if (d == (struct dog *)0)
		return;

	printf("Name: %s\n", (d->name == (char *)0) ? "(nil)" : d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", (d->owner == (char *)0) ? "(nil)" : d->owner);
}
