/* 100-prime_factor.c */

#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of 612852475143.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long factor = 2;

	/* Divide n by smallest possible factor until n becomes the largest prime */
	while (n > 1)
	{
		if (n % factor == 0)
			n /= factor;
		else
			factor++;
	}
	printf("%lu\n", factor);
	return (0);
}
