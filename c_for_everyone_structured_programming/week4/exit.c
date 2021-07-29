/*
  File I/O
  Dalton Hall
  July 29th, 2021
*/

#include <stdio.h>
#include <stdlib.h>

void print_file(FILE *fptr)
{
  int c;
  rewind(fptr);
  while ((c = getc(fptr)) != EOF)
  {
      putc(c, stdout);
  }
}

void double_space(FILE *ifp, FILE *ofp)
{
  int c;
  rewind(ifp);
  while((c = getc(ifp)) != EOF)
  {
    putc(c, ofp);
    if (c == '\n')
    {
      putc('\n', ofp);
    }
  }
}

int main(int argc, char *argv[])
{
  FILE *ifp, *ofp;

  if (argc != 3)
  {
    printf("Need executable input file and output file\n");
    exit(1);
  }

  ifp = fopen(argv[1], "r+");
  ofp = fopen(argv[2], "w+");

  printf("my %s file as read in is\n\n", argv[1]);
  print_file(ifp);
  printf("\n\n");

  double_space(ifp, ofp);

  printf("my %s file double space is \n\n", argv[2]);
  print_file(ofp);
  printf("\n\n");
  
  return 0;
}