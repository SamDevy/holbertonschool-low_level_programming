/* 3-array_range.c */
/**
 * array_range - Creates an array of ints from min to max inclusive
 * @min: starting value (included)
 * @max: ending value (included)
 *
 * Return: Pointer to newly allocated array ordered from min to max,
 *         or NULL if min > max or if malloc fails.
 *
 * Why: Simple index-based loop; clear and easy to verify boundaries.
 */
#include <stdlib.h>

int *array_range(int min, int max)
{
	int *arr;
	int len;
	int i;

	if (min > max)
		return (NULL);

	len = (max - min) + 1;

	arr = (int *)malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		arr[i] = min + i;

	return (arr);
}
