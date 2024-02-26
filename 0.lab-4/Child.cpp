// #pragma once
#include "Child.h"
#include <iostream>
#include <string>
using namespace std;

// Child(string firstName = "", string lastName = "", int age = 0);
// -----
Child::Child(string firstName, string lastName, int age)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = age;
}

// Child();
// -----
Child::Child()
{
  this->firstName = "";
  this->lastName = "";
  this->age = 0;
}

// ~Child();
// -----
Child::~Child() {}

// friend ostream &operator<<(ostream &out, const Child &c);
// -----
// prints firstName, lastName, and age with no spaces
ostream &operator<<(ostream &out, const Child &c)
{
  out << c.firstName << c.lastName << c.age;
  return out;
}

// friend istream &operator>>(istream &in, Child &c);
// -----
// input form: "firstName lastName age"
istream &operator>>(istream &in, Child &c)
{
  in >> c.firstName >> c.lastName >> c.age;
  return in;
}

// bool operator>(const Child &c) const;
// -----
// alphabetical order by last name, then first name, then age
bool Child::operator>(const Child &c) const
{
  if (this->lastName > c.lastName)
  {
    return true;
  }
  else if (this->lastName == c.lastName)
  {
    if (this->firstName > c.firstName)
    {
      return true;
    }
    else if (this->firstName == c.firstName)
    {
      if (this->age > c.age)
      {
        return true;
      }
    }
  }
  return false;
}

// bool operator==(const Child &c) const;
// -----
bool Child::operator==(const Child &c) const
{
  return this->firstName == c.firstName && this->lastName == c.lastName && this->age == c.age;
}

// bool operator!=(const Child &c) const;
// -----
bool Child::operator!=(const Child &c) const
{
  return !(*this == c);
}

// bool operator<(const Child &c) const;
// -----
bool Child::operator<(const Child &c) const
{
  return !(*this > c) && !(*this == c);
}