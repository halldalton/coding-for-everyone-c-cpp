/*
  Use of Pointers
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

int main(void)
{
    const int SIZE = 5;
    int grades[] = {78, 67, 92, 83, 88};
    double sum = 0.0;
    double *ptr_to_sum = &sum;
    int i;

    printf("\nMy grades are:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", grades[i]);
        sum = sum + grades[i];
    }

    printf("\nsum is at %p, or %lu and is %lf\n", ptr_to_sum, (unsigned long)ptr_to_sum, *ptr_to_sum);
    printf("grades are at %lu to %lu\n\n", (unsigned long)grades, (unsigned long)(grades + SIZE));

    return 0;
}