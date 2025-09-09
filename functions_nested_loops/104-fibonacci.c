/* 104-fibonacci.c */

#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers, starting with 1 and 2.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long a1 = 1, a2 = 0, b1 = 2, b2 = 0;
	unsigned long next1, next2;
	unsigned long limit = 10000000000;
	int i;

	printf("%lu, %lu", a1, b1);

	for (i = 2; i < 98; i++)
	{
		next1 = a1 + b1;
		next2 = a2 + b2;

		if (next1 >= limit)
		{
			next1 -= limit;
			next2++;
		}

		if (next2 > 0)
			printf(", %lu%010lu", next2, next1);
		else
			printf(", %lu", next1);

		a1 = b1;
		a2 = b2;
		b1 = next1;
		b2 = next2;
	}
	printf("\n");
	return (0);
}
