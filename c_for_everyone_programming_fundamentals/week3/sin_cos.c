/*
  Prints values of sine and cosine
  July 13th, 2021
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    for (i = 0; i <= 10; i++)
    {
        double interval = i / 10.0;
        printf("sin(%lf) = %lf, ", interval, sin(interval));
        printf("cos(%lf) = %lf\n", interval, cos(interval));
    };
    return 0;
}