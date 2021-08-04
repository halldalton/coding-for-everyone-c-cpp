// Cartesian Graph Point Class
// Dalton Hall
// August 4th, 2021

#include <iostream>

using namespace std;

class Point
{
  private:

    double x, y;

  public:

    Point(double a, double b)
    {
      x = a;
      y = b;
    }

    double get_x()
    {
      return x;
    }

    void set_x(double v)
    {
      x = v;
    }

    double get_y()
    {
      return y;
    }

    void set_y(double v)
    {
      y = v;
    }

    friend Point operator+(const Point &p1, const Point &p2);

    friend ostream& operator<<(ostream &out, const Point &p);
};


Point operator+(const Point &p1, const Point &p2)
{
  const Point &sum = Point(p1.x + p2.x, p1.y + p2.y);
  return sum;
}


ostream& operator<<(ostream &out, const Point &p)
{
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}


int main()
{
  Point p1(3.5, 2.5), p2(2.5, 4.5);
  cout << "\n" << p1 << " + " << p2 << " = " << p1 + p2 << endl << endl;;
  return 0;
}