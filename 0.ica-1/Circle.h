#pragma once
#include <iostream>
using namespace std;

class Circle
{
private:
  int x;
  int y;
  int radius;

public:
  Circle(int x, int y, int radius);
  Circle();

  // setters & getters
  int getRadius() const;
  int getX() const;
  int getY() const;
  void setRadius(const int radius);
  void setX(const int x);
  void setY(const int y);

  double calcArea() const;
  double calcPerimeter() const;
  bool isPointWithinCircle(const double x, const double y) const;

  Circle operator+(const Circle &circle);
  Circle &operator+=(const Circle &circle);
  bool operator==(const Circle &circle) const;
  bool operator!=(const Circle &circle) const;

  friend ostream &operator<<(ostream &ostream, const Circle &circle);
};