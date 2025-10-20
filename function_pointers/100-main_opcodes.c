#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 if argument count is wrong,
 * 2 if number of bytes is negative.
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *main_address;

	/* Check for the correct number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* Convert the argument to an integer */
	num_bytes = atoi(argv[1]);

	/* Check if the number of bytes is negative */
	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/*
	 * Cast the address of the main function to an unsigned char pointer.
	 * This allows us to access the individual bytes (opcodes) of the function.
	 */
	main_address = (unsigned char *)main;

	/* Loop for the specified number of bytes */
	for (i = 0; i < num_bytes; i++)
	{
		/*
		 * Print the byte in lowercase hexadecimal format.
		 * The "%02x" format specifier ensures that each byte is printed
		 * as two characters, with a leading zero if necessary (e.g., "f" -> "0f").
		 */
		printf("%02x", main_address[i]);

		/* Print a space after each opcode, except for the very last one */
		if (i < num_bytes - 1)
		{
			printf(" ");
		}
	}

	/* Print the final newline character */
	printf("\n");

	return (0);
}
