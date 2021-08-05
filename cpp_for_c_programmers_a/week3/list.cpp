// Singly Linked List in C++
// Dalton Hall
// August 4th, 2021

#include <iostream>

using namespace std;

class Node
{
  public:

    Node(int n = 0, Node *ptr = nullptr): d(n), next(ptr) {} // default constructor

    int d;
    Node *next;
};

class List
{
  public:

    List(): head(nullptr), cursor(nullptr) {} // default constructor

    List(const int *arr, int size) // array constructor
    {
      cursor = head = new Node(arr[0], nullptr);
      for (int i = 1; i < size; ++i)
      {
        prepend(arr[i]);
      }
    } 

    List(const List &list) // copy constructor
    {
      if (list.head == nullptr)
      {
        head = nullptr;
        cursor = nullptr;
      }
      else
      {
        Node *h = new Node();
        Node *previous;
        head = h;
        head -> d = list.head -> d;
        previous = h;
        for (cursor = list.head -> next; cursor != nullptr;)
        {
          h = new Node();
          h -> d = cursor -> d;
          previous -> next = h;
          cursor = cursor -> next;
          previous = h;
        }
        cursor = head;
      }
    }

    void prepend(int n) // adds element to the front of the list
    {
      if (head == nullptr)
      {
        cursor = head = new Node(n, head);
      }
      else
      {
        head = new Node(n, head);
      }
    }

    int get_element()
    {
      return cursor -> d;
    }

    void advance()
    {
      cursor = cursor -> next;
    }

    void print()
    {
      Node *h = head;
      while (h != nullptr)
      {
        cout << h -> d << ", ";
        h = h -> next;
      }
      cout << "nullptr" << endl;
    }

    ~List() 
    {
      for (cursor = head; cursor != nullptr;)
      {
        cursor = head -> next;
        delete head;
        head = cursor;
      }
    }

  private:

    Node *head;
    Node *cursor;
};


int main()
{
  List a;
  int c[10];

  a.prepend(9);
  a.prepend(8);

  cout << "\nList a" << endl;
  a.print();

  for (int i = 0; i < 10; ++i)
  {
    c[i] = (i * i);
  }

  List b(c, 10); // create from array c

  cout << "\nList b, created from array c" << endl;
  b.print();

  List d(a); // create from deep copy of a

  d.prepend(7);

  cout << "\nList d, created from deep copy of a" << endl;
  d.print();

  cout << "\nList a remains unchanged" << endl;
  a.print();
  cout << endl;

  return 0;
}