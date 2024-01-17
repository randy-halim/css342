#include <iostream>
using namespace std;

template <class T>
T Lar2Inp(T &a, T &b)
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

int main()
{
  int a, b;
  cout << "Enter two numbers: ";
  cin >> a >> b;
  cout << "Larger number is: " << Lar2Inp(a, b) << endl;
  return 0;
}