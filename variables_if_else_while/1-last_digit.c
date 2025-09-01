#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/* 
using if else and genrateing numbers 
than we took the last digit and compare it to 5 
if its bigger it would says grater
if its smaller it would says less
if its = 0 it would says 0
*/
int main(void)
{
        int n;
        int a;
        srand(time(0));
        n = rand() - RAND_MAX / 2;
	a = n % 10;
        if (a > 5)
        {
                printf("Last digit of %d is %d and is greater than 5\n", n, a);
        }
        else if (a == 0)
        {
                printf("Last digit of %d is %d and is 0\n", n, a);
        }
        else
        {
                printf("Last digit of %d is %d and is less than 6 and not 0\n", n, a);
        }

        return (0);
}
