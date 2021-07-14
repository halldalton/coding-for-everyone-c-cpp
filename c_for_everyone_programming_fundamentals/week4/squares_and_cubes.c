/*
  Squares and Cubes Table
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

double square(double);
double cube(double);

int main(void)
{
    int how_many = 0, i, j;
    double interval;

    printf("I want to square and cube for 1 to n where n is: ");
    scanf("%d", &how_many);
    printf("\n   Square and Cubes by interval of .1\n");

    for (i = 1; i < how_many; i++)
    {
        for (j = 0; j <= 10; j++)
        {
            interval = i + (j / 10.0);
            printf("\n%lf\t%lf\t%lf", interval, square(interval), cube(interval));
        }
    }
    printf("\n\n");
    return 0;
}

double square(double x)
{
    return (x * x);
}

double cube(double x)
{
    return (x * x * x);
}