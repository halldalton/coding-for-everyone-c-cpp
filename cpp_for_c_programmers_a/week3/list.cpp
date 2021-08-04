// Singly Linked List in C++
// Dalton Hall
// August 4th, 2021

#include <iostream>

using namespace std;

class Node
{
  public:

    Node(int n = 0, Node *ptr = nullptr): d(n), next(ptr) {}

    int d;
    Node *next;
};

class List
{
  public:

    List(): head(nullptr), cursor(nullptr) {}

    ~List() 
    {
      cout << "Deconstructor called" << endl;
      // release();
    }

    void prepend(int n)
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

    void print();

  private:

    Node *head;
    Node *cursor;
};