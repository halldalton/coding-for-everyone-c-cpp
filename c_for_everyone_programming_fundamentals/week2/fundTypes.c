/*
  Fundamental Types Declaration and Assignment
  Dalton Hall
  July 12th, 2021
*/

#include <stdio.h>

int main(void)
{
    int a = 5, b = 7, c = 6;
    double average = 0.0;

    printf("a = %d, b = %d, c = %d\n", a, b, c);
    average = (a + b + c) / 3.0;
    printf("average = %lf\n", average);
    return 0;
}