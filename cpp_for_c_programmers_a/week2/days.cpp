// Typedef, Enum, Operator Overloading, and Classes in C++
// Dalton Hall
// August 4th, 2021

#include <iostream>

using namespace std;

typedef enum day {SUN, MON, TUE, WED, THU, FRI, SAT} day;


inline day operator++(day &d)
{
  return d = static_cast<day>((static_cast<int>(d) + 1) % 7);
}


inline ostream& operator<<(ostream &out, const day &d)
{
  switch (d)
  {
    case SUN: out << "Sunday"; break;
    case MON: out << "Monday"; break;
    case TUE: out << "Tuesday"; break;
    case WED: out << "Wednesday"; break;
    case THU: out << "Thursday"; break;
    case FRI: out << "Friday"; break;
    case SAT: out << "Saturday"; break;
  }
  return out;
}


int main()
{
  day d = MON;
  cout << d << '\t' << ++d << endl;
  return 0;
}