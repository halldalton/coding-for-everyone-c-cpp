/*
  File I/O
  July 29th, 2021
*/

#include <stdio.h>

#define MAX_HW 20

void read_data(FILE *ptr, int d[], int *size)
{
  int i = 0;
  fscanf(ptr, "%d", size); // first value is the size, then iterate over file to add to data array
  while (fscanf(ptr, "%d", &d[i]) == 1)
  {
    i++;
  }
}


void print_and_write_data(int d[], int size, FILE *ofp)
{
  int i;
  printf("My homework scores are: "); // print to std out
  fprintf(ofp, "My homework scores are: "); // write  to file
  for (i = 0; i < size; i++)
  {
    if (i % 10 == 0)
    {
      printf("\n");
      fprintf(ofp, "\n");
    }
    printf("%d\t", d[i]);
    fprintf(ofp, "%d\t", d[i]);
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


int max(int d[], int size)
{
  int i;
  int max = 0;

  for (i = 0; i < size; i++)
  {
    if (d[i] > max)
    {
      max = d[i];
    }
  }
  return max;
}


int main()
{
  int i, size, m;
  double avg;
  FILE *ifp, *ofp;
  int data[MAX_HW] = {};
  char output_str[] = {}; 

  ifp = fopen("in.txt", "r+");
  ofp = fopen("out.txt", "w+");
  read_data(ifp, data, &size);

  avg = average(data, size);
  m = max(data, size);

  printf("\n");
  print_and_write_data(data, size, ofp);
  printf("\nAverage score is: %.2f, max score is %d\n\n", avg, m); // print to stdout
  fprintf(ofp, "\nAverage score is: %.2f, max score is %d", avg, m); // write to file

  fclose(ifp);
  fclose(ofp);
  return 0;
}