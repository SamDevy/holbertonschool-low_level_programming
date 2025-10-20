#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - Prints a name using a specific printing function.
 * @name: The name to be printed.
 * @f: A pointer to the function to be used for printing the name.
 *
 * Description: This function takes a name and a function pointer.
 * It calls the function pointed to by 'f', passing
 * the 'name' as an argument, provided neither 'name'
 * nor 'f' is NULL.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
