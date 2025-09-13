#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Sets the value of a[2] = 98 without
 *              directly using the array variable 'a'.
 *              Only one statement is allowed.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
  int n;
  int a[5];
  int *p;

  a[2] = 1024;
  p = &n;
  *(p + 5) = 98;
  printf("a[2] = %d\n", a[2]);
  return (0);
}

