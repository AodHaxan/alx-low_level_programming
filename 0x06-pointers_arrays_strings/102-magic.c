#include <stdio.h>

int main(void)
{
    int a[] = { 4, 8, 98, 7, 6, 5 };
    int *p = &a[1];

  /*
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   */
	*(p + 7) = 98;
  /* ...so that this prints 98\n */
	printf("a[2] = %d\n", *(p+1)); // added line
	return (0);
}
