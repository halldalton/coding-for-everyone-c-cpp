// Sum array, with C++ features
// Dalton Hall
// August 3nd, 2021

#include <iostream>

using namespace std;


template <class T> // T is a generic type
T sum(const T data[], int size, T s=0)
{
  for (int i = 0; i < size; i++)
  {
    s += data[i]; // += must work for type T 
  }
  return s;
}


template <class T>
T substract(const T data[], int size, T s=0)
{
  for (int i = 0; i < size; i++)
  {
    s -= data[i]; // -= must work for type T 
  }
  return s;
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
  double b[] = {2.1, 2.2, 2.3};

  cout << "\nArray a is: ";
  print_array(a, 3);
  cout << "Sum of array a = " << sum(a, 3) << endl;

  cout << "\nArray b is: ";
  print_array(b, 3);
  cout << "10 minus the values of array b = " << substract(b, 3, 10.0) << endl << endl;
}