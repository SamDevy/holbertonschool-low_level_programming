#include "main.h"

/**
 * check_prime - helper function to check divisibility
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int i)
{
	if (i * i > n)   /* If divisor squared > n, no need to check further */
		return (1);
	if (n % i == 0)  /* If divisible, not prime */
		return (0);
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, 2));
}
