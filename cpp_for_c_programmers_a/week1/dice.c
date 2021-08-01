/* 
  Dice Probabilty in C
  Dalton Hall
  August 1st, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)

int main()
{
  const int n_dice = 2;
  int trials, j, d1, d2;
  int outcomes[13] = {0}; // 13 to populate outcomes 1-12
  clock_t clock(void);

  srand(clock());

  printf("\nEnter Number of Trials: ");
  scanf("%d", &trials);

  for (j = 0; j < trials; j++)
  {
    outcomes[(d1 = R_SIDE) + (d2 = R_SIDE)]++; // if d1 = 2 and d2 = 5, add to outcomes at 7 and increment count;
  }

  printf("\nProbability\n");

  for (j = 2; j < n_dice * SIDES + 1; ++j) // start at 2, since outcome of 0 or 1 is impossible
  {
    printf("j = %d, p = %lf\n", j, (double)(outcomes[j]) / trials);
  }

  return 0;
}