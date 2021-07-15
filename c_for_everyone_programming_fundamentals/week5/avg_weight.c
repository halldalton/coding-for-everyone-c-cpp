/*
  Calculates average weight of seals from input array
*/

#include <stdio.h>

void sum_array(int a[], int how_many, double *sum) // adds sum to variable initialized in main
{
    int j;

    for (j = 0; j < how_many; j++)
    {
        *sum += a[j];
    }
}

int main(void)
{
    const int SIZE = 1000;
    int i;
    double sum = 0.0;
    int seals[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &seals[i]); // scan for ints and add them to array
    }

    sum_array(seals, SIZE, &sum);

    printf("\nAverage weight of elephant seals = %lf\n\n", sum / SIZE);

    return 0;
}