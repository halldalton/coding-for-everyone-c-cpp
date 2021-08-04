// More Generics and Templates
// Dalton Hall
// August 3nd, 2021

#include <iostream>

using namespace std;


template<class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    destination[i] = static_cast<T2>(source[i]);
  }
}


template <class T>
void print_array(const T data[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << data[i] << " ";
  }
  cout << endl;
}


int main()
{
  int a[] = {1, 2, 3};
  double b[] = {2.1, 3.5, 10.3};

  cout << "\nArray a is: ";
  print_array(a, 3);

  cout << "\nArray b is: ";
  print_array(b, 3);
  
  copy(b, a, 3);

  cout << "\nArray a after copying from array b is: ";
  print_array(a, 3);
  cout << endl;
}