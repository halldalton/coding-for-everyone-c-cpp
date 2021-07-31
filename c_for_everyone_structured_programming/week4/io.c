/*
  File I/O
  Dalton Hall
  July 29th, 2021
*/

#include <stdio.h>

#define MAX_HW 20

void read_data(FILE *ptr, int d[], int *size)
{
  *size = 0;
  while (fscanf(ptr, "%d", &d[*size]) == 1)
  {
    (*size)++;
  }
}


void print_data(int d[], int size)
{
  int i;
  printf("My homework scores are: ");
  for (i = 0; i < size; i++)
  {
    if (i % 10 == 0)
    {
      printf("\n");
    }
    printf("%d\t", d[i]);
  }
}


double average(int d[], int size)
{
  int i;
  double avg = 0.0;

  for (i = 0; i < size; i++)
  {
    avg += d[i];
  }

  return (avg / size);
}


int main()
{
  int i, size = MAX_HW;
  FILE *ifp;
  int data[MAX_HW] = {};

  ifp = fopen("myhw.tsv", "r");
  read_data(ifp, data, &size);

  printf("\n");
  print_data(data, size);
  printf("\nAverage score is: %.2f\n\n", average(data, size));

  fclose(ifp);
  return 0;
}