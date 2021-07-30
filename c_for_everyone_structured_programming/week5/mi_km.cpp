// Miles converted to kilometers in C++
// Dalton Hall
// July 30th, 2021

#include <iostream>
using namespace :: std;
const double m_to_km = 1.609;

inline double convert(int mi){ return (mi * m_to_km); }

int main(void)
{
    int miles = 1;

    while (miles != 0)
    {
        cout << "\nInput distance in miles or 0 to terminate: ";
        cin >> miles;
        cout << "\nDistace is " << convert(miles) << " km." << endl;
    }
    cout << endl;
}