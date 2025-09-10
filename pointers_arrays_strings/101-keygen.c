#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
	int sum = 0;
	char c;

	srand(time(NULL));

	while (sum < 2772) /* 2772 is the target sum */
	{
		c = rand() % 94 + 33; /* printable ASCII characters: 33 to 126 */
		if (sum + c > 2772)
			break;
		sum += c;
		printf("%c", c);
	}
	/* Print the final character to make the total sum exactly 2772 */
	printf("%c", 2772 - sum);

	return (0);
}
