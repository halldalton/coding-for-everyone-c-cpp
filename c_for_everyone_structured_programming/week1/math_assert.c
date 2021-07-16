/*
  Assert 3
  Dalton Hall
  July 16th, 2021
*/

#include <assert.h>
#include <stdio.h>

int main(void)
{
    double x, y;
    while(1)
    {
        printf("Read in 2 floats:\n");
        scanf("%lf %lf", &x, &y);

        assert(y != 0); // avoid division by zero
        
        printf("x / y = %lf\n", x / y);
    }
    return 0;
}