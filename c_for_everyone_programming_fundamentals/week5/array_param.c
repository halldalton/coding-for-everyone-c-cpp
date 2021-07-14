/*
  Use of Simple Arrays as Parameters
  Dalton Hall
  July 14th, 2021
*/

#include <stdio.h>

double average_grades(int how_many, int grades[])
{
    int i;
    double sum = 0.0;

    for (i = 0; i < how_many; i++)
    {
        sum += grades[i];
    }

    return(sum / how_many);
}

void print_grades(int how_many, int grades[])
{
    int i;

    printf("\nI have %d grades\n", how_many);

    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", grades[i]);
    }
}

int main(void)
{
    const int SIZE = 5;
    int grades[] = {78, 67, 92, 83, 88};

    print_grades(SIZE, grades);
    printf("\n\nMy average is %.2f\n\n", average_grades(SIZE, grades));

    return 0;
}