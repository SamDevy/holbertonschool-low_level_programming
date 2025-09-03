#include <stdio.h> 

/*
 * Program: Print lowercase letters a-z
 * Behavior: Skips 'e' and 'q' characters
 * Output: One line of letters without 'e' and 'q'
 * Usage: Compile and run to see the sequence
 * Note: Uses putchar in a simple while loop
 * Exits with status code 0.
 */
int main(void) 
{
char ch = 'a';

while (ch <= 'z') {
    if (ch != 'q' && ch != 'e')
        putchar(ch);
    ch++;
}
putchar('\n');
return 0; 

}

