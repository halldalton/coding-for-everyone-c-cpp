// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function

#include <iostream>
#include <bits/stdc++.h> // library that has vectors

using namespace std;

const int n = 40;

inline int sum(vector<int> d)
{
  int acc = 0;
  for (int i = 0; i < n; ++i)
  {
    acc = acc + d[i];
  }
  return acc;
}

int main()
{
  vector<int> data(n, 0); // initialize vector to 40 items of 0

  for (int i = 0; i < n; ++i)
  {
    data[i] = i; // fill vector with values
  }

  int acc = sum(data);

  cout << "\nsum is " << acc << endl << endl; 

  return 0;
}