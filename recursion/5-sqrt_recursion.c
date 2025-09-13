#include "main.h"

/**
 * find_sqrt - helper function to find natural square root
 * @n: number to find the square root of
 * @i: current guess
 *
 * Return: natural square root, or -1 if not found
 */
int find_sqrt(int n, int i)
{
	if (i * i > n)   /* passed possible root */
		return (-1);
	if (i * i == n)  /* found exact square root */
		return (i);
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate square root of
 *
 * Return: natural square root, or -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}
