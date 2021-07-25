/*
  Iterative vs Recursive Factorial
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

long int factorial(int n)
{
    long f = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

long int recursive_factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return(recursive_factorial(n - 1) * n);
    }
}

int main(void)
{
    int how_many, i;

    printf("I want table of factorial up to n: ");
    scanf("%d", &how_many);
    printf("\nFactorials\n");
    
    for (i = 1; i <= how_many; i++)
    {
        printf("\n%d\t %ld\n", i, factorial(i));
    }

    printf("\n\nRecursive Factorials\n");

    for (i = 1; i <= how_many; i++)
    {
        printf("\n%d\t %ld\n", i, recursive_factorial(i));
    }

    printf("\n\n");
    return 0;
}