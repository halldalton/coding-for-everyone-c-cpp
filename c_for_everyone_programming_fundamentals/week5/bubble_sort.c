/*
  Bubble Sort
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int how_many, int data[], char *str)
{
    int i;
    printf("%s", str);

    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", data[i]);
    }
}

int main(void)
{
    int a = 5, b = 2;

    printf("\nInitially, a = %d, b = %d", a, b);

    swap(&a, &b);

    printf("\nAfter swapping values, a = %d, b = %d\n\n", a, b);

    return 0;
}