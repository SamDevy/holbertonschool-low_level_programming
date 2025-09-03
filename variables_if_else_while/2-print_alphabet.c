#include <stdio.h> 

/*
 * Prints lowercase letters 'a' to 'z' to standard output.
 * Starts from character 'a' and increments until 'z'.
 * Uses a while loop and putchar for output.
 * Outputs letters consecutively without spaces.
 * Exits with status code 0.
 */
int main (void) {

    char a = 'a';
    while (a <= 'z') {
    putchar(a);
    putchar('\n')    
    a++;
}
return 0;
}
