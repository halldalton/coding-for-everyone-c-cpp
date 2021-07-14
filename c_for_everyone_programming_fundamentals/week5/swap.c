/*
  swap Function
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(void)
{
    int a = 5, b = 2;

    printf("\nInitially, a = %d, b = %d", a, b);

    swap(&a, &b);

    printf("\nAfter swapping values, a = %d, b = %d\n\n", a, b);

    return 0;
}