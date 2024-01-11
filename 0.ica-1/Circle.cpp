#pragma once
#include "Circle.h"
#include <iostream>
#include <cmath>
using namespace std;

Circle::Circle(int x, int y, int radius)
{
  this->x = x;
  this->y = y;
  this->setRadius(radius);
}
Circle::Circle()
{
  *this = Circle(0, 0, 1);
}

int Circle::getRadius() const
{
  return this->radius;
}
int Circle::getX() const
{
  return this->x;
}
int Circle::getY() const
{
  return this->y;
}

void Circle::setRadius(const int radius)
{
  if (radius < 0)
  {
    throw runtime_error("Radius must be non-negative \n");
  }
  this->radius = radius;
}
void Circle::setX(const int x)
{
  this->x = x;
}
void Circle::setY(const int y)
{
  this->y = y;
}

double Circle::calcArea() const
{
  return M_PI * pow(this->radius, 2.0f);
}
double Circle::calcPerimeter() const
{
  return M_PI * 2 * this->radius;
}

bool Circle::isPointWithinCircle(const double x, const double y) const
{
  // distance formula
  // sqrt((point_x - circle_x)^2 + (point_y - circle_y)^2)

  const float distance = sqrt(pow((x - this->x), 2.0f) + pow((y - this->y), 2.0f));
  return distance <= this->radius;
}

Circle Circle::operator+(const Circle &circle)
{
  Circle result;
  result.x = this->x + circle.x;
  result.y = this->y + circle.y;
  result.radius = this->radius + circle.radius;

  return result;
}
Circle &Circle::operator+=(const Circle &circle)
{
  *this = *this + circle;
  return *this;
}

bool Circle::operator==(const Circle &circle) const
{
  return this->x == circle.x && this->y == circle.y && this->radius == circle.radius;
}
bool Circle::operator!=(const Circle &circle) const
{
  return !(*this == circle);
}

ostream &operator<<(ostream &os, const Circle &circle)
{
  os << "(" << circle.getX() << ", " << circle.getY() << ", " << circle.getRadius() << ")";
  return os;
}