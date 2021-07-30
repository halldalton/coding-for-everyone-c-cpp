/*
  Lists
  Dalton Hall
  July 28th, 2021
  Updated July 30th to improve delete function
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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


void delete(list *p, list **prev, list **hd)
{
  if (*hd == *prev)
  {
    *hd = p -> next;
  }
  else
  {
    (*prev) -> next = p -> next;
  }
  free(p);
}


void delete_list(list *h)
{
  list *temp;
  if (h != NULL)
  {
    temp = h;
    delete_list(h = h -> next);
    free(temp);
  }
}


void print_list(list *h, char *title)
{
  printf("%s\n", title);
  while (h != NULL)
  {
    printf("%d : ", h -> data);
    h = h -> next;
  }
}


int main()
{
  list *list1 = NULL;
  list *list2 = NULL;
  int data1[3] = {1, 2, 3};
  int data2[3] = {4, 6};
  list1 = array_to_list(data1, 3);
  list2 = array_to_list(data2, 2);

  printf("\nList1 is of length %d\n\n", count(list1));
  print_list(list1, "List1");

  printf("\n\nList2 is of length %d\n\n", count(list2));
  print_list(list2, "List2");

  insert(list2, list2->next, create_list(5));

  printf("\n\nList2 after inserting 5\n\n");
  print_list(list2, "List2");

  concat(list1, list2);

  printf("\n\nList1 after concatenation:\n\n");
  print_list(list1, "List1");

  delete(list1 -> next -> next, &list1 -> next, &list1);

  printf("\n\nList1 after deleting 3rd element:\n\n");
  print_list(list1, "List1");

  printf("\n\n");
  return 0;
}