#pragma once
#include <string>
using namespace std;

class Child
{
private:
  string firstName;
  string lastName;
  int age;

public:
  // constructor
  Child(string firstName, string lastName, int age);
  // default constructor
  Child();
  // destructor
  ~Child();
  // << operator override
  friend ostream &operator<<(ostream &out, const Child &c);
  // >> operator override
  friend istream &operator>>(istream &in, Child &c);

  // >, ==, !=, < operator overrides
  bool operator>(const Child &c) const;
  bool operator==(const Child &c) const;
  bool operator!=(const Child &c) const;
  bool operator<(const Child &c) const;
  bool operator>=(const Child &c) const
  {
    return !(*this < c);
  }
};
