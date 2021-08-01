// Swap in C++
// Dalton Hall
// August 1st, 2021

#include <iostream>

using namespace std;

namespace my_swap { // use namespace to avoid conflicts with std's swap function
  template <class T>
  inline void swap(T& i, T& j) // T& is a call by reference to a generic type
  {
    T temp = i;
    i = j;
    j = temp;
  }
}


int main()
{
  int m = 5, n = 10;
  double x = 5.3, y = 10.6;

  cout << "\ninputs: " << m << ", " << n << endl;
  my_swap::swap(m, n);
  cout << "outputs: " << m << ", " << n << endl;

  cout << "double inputs: " << x << ", " << y << endl;
  my_swap::swap(x, y);
  cout << "double outputs: " << x << ", " << y << endl << endl;

  return 0;
}