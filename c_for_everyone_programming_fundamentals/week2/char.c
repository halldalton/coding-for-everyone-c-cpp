/*
  Char in C
  Dalton Hall
  July 12th, 2021
*/

#include <stdio.h>

int main(void)
{
    char c = 'a';
    printf("a in ASCII is: %d\n", c);
    printf("a the character is: %c\n", c);
    printf("Three consecutive chars are: %c%c%c\n", c, c+1, c+2);
    printf("Three bell rings chars are: %c%c%c\n", '\a', '\a', '\a');
    return 0;
}