#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * sum_them_all - calculates the sum of all its parameters.
 * @n: The number of parameters passed to the function.
 * @...: A variable number of parameters to calculate the sum of.
 *
 * Return: If n == 0, return 0. Otherwise, return the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...);

/**
 * print_numbers - prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: A variable number of numbers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...);

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: The string to be printed between the strings.
 * @n: The number of strings passed to the function.
 * @...: A variable number of strings to be printed.
 */
void print_strings(const char *separator, const unsigned int n, ...);

#endif /* VARIADIC_FUNCTIONS_H */
