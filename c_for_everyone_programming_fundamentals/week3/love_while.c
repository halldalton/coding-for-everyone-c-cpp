/*
  While loops
  Dalton Hall
  July 13th, 2021
*/

#include <stdio.h>

int main(void)
{
    int repeat = 0;

    printf("How strong is your love 1-10?: ");
    scanf("%d", &repeat);

    printf("I love you very");

    while (repeat > 0)
    {
        printf("\nvery");
        repeat--;
    };
    
    printf(" much <3\n\n");
    return 0;
}