#include<iostream>
using namespace std;

double largerNumber(const double a, const double b);

int main() {
  double a, b, m;
  cout << "Specify two numbers: " << endl;
  cin >> a >> b;
  m = largerNumber(a, b);
  cout << "The largest number between " << a << " and " << b << " is " << m << endl;

  return 0;
}

double largerNumber(const double a, const double b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}