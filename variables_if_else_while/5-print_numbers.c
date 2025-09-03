#include <stdio.h>

/*
 * Prints digits 0-9
 * Uses putchar in while loop
 * Outputs a newline at end
 * Returns from main
 * succed 0
 */

int main(void)
{

char to_9 = '0';

while(to_9 <= '9')
{
    putchar(to_9);
    to_9++;
}
putchar('\n');

return 0;
}

