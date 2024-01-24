#include <iostream>
using namespace std;

void PrintBinary(int n)
{
  if (n < 2)
  {
    cout << n;
  }
  else
  {
    PrintBinary(n / 2);
    cout << n % 2;
  }
}

int main()
{
  int n;
  cout << "Enter a number: ";
  cin >> n;
  PrintBinary(n);
  cout << endl;
  return 0;
}