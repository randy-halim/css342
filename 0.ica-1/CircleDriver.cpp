#pragma once
#include "Circle.h"
#include <iostream>
using namespace std;

int main()
{
  Circle circle1 = Circle();
  Circle circle2 = Circle(4, 5, 6);

  cout << "Circle 1: " << circle1 << endl;
  cout << "Circle 2: " << circle2 << endl;

  Circle addedCircles = circle1 + circle2;

  cout << "Circle 1 + Circle 2 = " << addedCircles << endl;

  circle2 += addedCircles;

  cout << "Circle2 += addedCircles: " << circle2 << endl;

  cout << "Area of Circle2: " << circle2.calcArea() << endl;
  cout << "Perimeter of Circle2: " << circle2.calcPerimeter() << endl;

  cout << "Point (10, 11) in Circle2: (1 is true) " << circle2.isPointWithinCircle(10, 11) << endl;
  cout << "Point (99, 99) in Circle3: (1 is true) " << circle2.isPointWithinCircle(99, 99) << endl;

  cout << "Circle2 == Circle2: (1 is true) " << (circle2 == circle2) << endl;
  cout << "Circle2 != Circle1: (1 is true) " << (circle2 != circle1) << endl;
  cout << "Circle2 == Circle1: (should be false) " << (circle2 == circle1) << endl;
}