/*
  Conversion of Fahrenheit to Celcius
  C = (F - 32) / 1.8
  Dalton Hall
  July 8th, 2021
*/

#include <stdio.h>

int main(void)
{
    int fahrenheit, celcius;

    printf("Please enter fahrenheit as an integer: ");
    scanf("%d", &fahrenheit);
    celcius = (fahrenheit - 32) / 1.8;
    printf("\n%d fahrenheit is %d celcius.\n\n", fahrenheit, celcius);
    return 0;
}