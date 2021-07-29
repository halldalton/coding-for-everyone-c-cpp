/*
  Sort List
  July 29th, 2021
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// List Functionality

typedef struct list
{
  int data;
  struct list *next;
} list;


int is_empty(const list *l)
{
  return (l == NULL);
}


list *create_list(int d)
{
  list *head = malloc(sizeof(list));
  head -> data = d;
  head -> next = NULL;
  return head;
}


list *add_to_front(int d, list *h)
{
  list *head = create_list(d);
  head -> next = h;
  return head;
}


list *array_to_list(int d[], int size)
{
  int i;
  list *head = create_list(d[0]);
  for (i = 1; i < size; i++)
  {
    head = add_to_front(d[i], head);
  }
  return head;
}


int count(list *h)
{
  if (h == NULL)
  {
    return 0;
  }
  else
  {
    return (1 + count(h -> next));
  }
}


void concat(list *h1, list *h2)
{
  assert(h1 != NULL);
  if (h1 -> next == NULL)
  {
    h1 -> next = h2;
  }
  else
  {
    concat(h1 -> next, h2);
  }
}


void insert(list *p1, list *p2, list *q)
{
  assert(p1 -> next == p2);
  p1 -> next = q;
  q -> next = p2;
}


void delete(list *p)
{
  list *temp;
  temp = p -> next;
  p -> next = temp -> next;
  free(temp);
}


void print_list(list *h, char *title)
{
  int i = 0;
  printf("%s\n", title);
  while (h != NULL)
  {
    if (i % 5 == 0)
    {
      printf("\n");
    }
    printf("%02d : ", h -> data); // keeps formatting even across lines
    h = h -> next;
    i++;
  }
}

// Sort Functionality

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


void bubble(list *h, int how_many)
{
  int i;
  list *head = h;
  for (i = how_many; i > 0; i--)
  {
    h = head; // reset pointer to head of list to iterate over the list again
    while (h -> next != NULL)
    {
      if (h -> data > h -> next -> data)
      {
        swap(&h -> data, &h -> next -> data);
      }
      h = h -> next;
    }
  }
}


int main()
{
  int i;
  const int SIZE = 100;
  int data[SIZE];
  list *l = NULL;

  for (i = 0; i < SIZE; i++)
  {
    data[i] = rand() % 100; // keep random ints < 100 to reduce clutter when printing
  }

  l = array_to_list(data, SIZE);

  printf("\n");
  print_list(l, "Unsorted List");
  printf("\n\n");

  bubble(l, SIZE);

  printf("\n");
  print_list(l, "Sorted List");
  printf("\n\n");

  return 0;
}