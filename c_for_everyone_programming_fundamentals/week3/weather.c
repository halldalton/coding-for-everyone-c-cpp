/*
  Logical operators and short circuit evaluation
  Dalton Hall
  July 13th, 2021
*/

#include <stdio.h>

int main(void)
{
    int outside, weather;

    printf("\nEnter if outside 1 true 0 false: ");
    scanf("%d", &outside);
    
    printf("Enter if rain 1 true 0 false: ");
    scanf("%d", &weather);

    if (outside && weather)
        printf("\nPlease use an umbrella\n");
        
    else
        printf("\nDress normally\n");

    return 0;
}