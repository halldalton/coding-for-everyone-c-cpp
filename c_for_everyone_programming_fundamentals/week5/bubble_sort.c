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

void bubble(int data[], int how_many)
{
    int i, j;
    int go_on;
    int is_sorted;

    for (i = 0; i < how_many; i++)
    {
        print_array(how_many, data, "\ninside bubble\n");
        printf("i = %d, input any int to continue: ", i);
        scanf("%d", &go_on);

        is_sorted = how_many;

        for (j = how_many - 1; j > i; j--)
        {
            if (data[j - 1] > data[j])
            {
                swap(&data[j - 1], &data[j]);
                is_sorted -= 1;
            }
        }
        
        if (is_sorted == how_many)
        {
            i = how_many; // break out of loop
            printf("\nArray is sorted, exiting loop\n");
        }
    }
}

int main(void)
{
    const int SIZE = 5;
    int grades[] = {78, 67, 92, 83, 88};

    print_array(SIZE, grades, "My grades\n");
    printf("\n\n");

    bubble(grades, SIZE); // sort the array

    print_array(SIZE, grades, "\nMy Sorted Grades\n");
    printf("\n\n");

    return 0;
}