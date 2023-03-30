#include <stdio.h>

int main()
{
    int a[] = { 4, 8, 98, 7, 6, 5 };
    int *p = &a[1];

    printf("a[2] = %d\n", *(p+1)); // added line

    return 0;
}
