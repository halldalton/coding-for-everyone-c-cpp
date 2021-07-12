/*
  A program that prints the sine function for an input x between 0 and 1
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, val; // initialization

    printf("Enter a value between 0 and 1: ");
    scanf("%lf", &x); // input value

    val = sin(x); // calculate sine of x
    printf("sine of %lf = %lf\n", x, val);

    return 0;
}