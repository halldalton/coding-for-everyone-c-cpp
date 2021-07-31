// C++ classes
// Dalton Hall
// July 31st, 2021

#include <iostream>
using namespace :: std;

class Rectangle
{
  public:
    Rectangle(double h, double w)
    {
      height = h;
      width = w;
    };

    double area()
    {
      return (height * width);
    };
  
  private:
    double height;
    double width;
};

int main(void)
{
  double height, width;
  cout << "\nEnter a height for your rectangle: ";
  cin >> height;
  cout << "Enter a width for your rectangle: ";
  cin >> width;

  Rectangle r = Rectangle(height, width);

  cout << "Area of your rectangle is: " << r.area() << endl << endl;

  return 0;
}