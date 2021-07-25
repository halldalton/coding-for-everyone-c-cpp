/*
  Use of Simple Arrays
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

int main(void)
{
    const int SIZE = 5;

    int grades[] = {78, 67, 92, 83, 88};
    double sum = 0.0;
    int i;

    printf("\nmy grades are:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", grades[i]);
        sum = sum + grades[i];
    }

    printf("\n\nmy average = %.2f\n\n", sum / SIZE);

    return 0;
}