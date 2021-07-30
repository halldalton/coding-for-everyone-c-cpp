/*
  Binary Trees
  July 30th, 2021
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 32 // 2^4

typedef int DATA;

struct node 
{
  DATA d;
  struct node *left;
  struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

// Binary Tree Logic

void inorder(BTREE root)
{
  if (root != NULL)
  {
    inorder(root -> left);
    printf("%d ", root -> d);
    inorder(root -> right);
  }
}


BTREE new_node(void)
{
  return (malloc(sizeof(NODE)));
}


BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
  BTREE t;
  t = new_node();
  t -> d = d1;
  t -> left = p1;
  t -> right = p2;
  return t;
}


BTREE create_tree(DATA a[],  int i, int size)
{
  if (i >= size)
  {
    return NULL;
  }
  else
  {
    return (init_node(a[i], create_tree(a, 2 * i + 1, size), create_tree(a, 2 * i + 2, size)));
  }
}

// IO logic

void read_data(FILE *ptr, int d[], int *size)
{
  int i = 0;
  fscanf(ptr, "%d", size); // first value is the size, then iterate over file to add to data array
  while (fscanf(ptr, "%d", &d[i]) == 1)
  {
    i++;
    if (i >= *size) // break while loop if i >= size specified by file
    {
      break;
    }
  }
}


int main()
{
  int i, size = MAX_DATA;
  FILE *ifp;
  BTREE b;
  int d[MAX_DATA] = {};

  ifp = fopen("tree.txt", "r");
  read_data(ifp, d, &size);
  fclose(ifp);
  
  b = create_tree(d, 0, size);

  printf("\n");
  inorder(b);
  printf("\n\n");
  return 0;
}