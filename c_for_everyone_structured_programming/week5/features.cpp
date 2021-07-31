// Some C++ easy to use features
// Dalton Hall
// July 31st, 2021

#include <iostream>
using namespace :: std;

long long fact(int n)
{
  long long f = 1;
  for (int i = 1; i <= n; i++)
  {
    f *= i;
  }
  return f;
}

int main(void)
{
  cout << "\nThis program uses some features not in C89" << endl;

  for (auto i = 0; i < 16; i++)
  {
    cout << "Factorial of " << i << " is " << fact(i) << endl;
  }
  cout << endl;
  
  return 0;
}