#include <iostream>
using namespace std;

const string hexDigits = "0123456789ABCDEF";

void PrintHex(int n)
{
  if (n < 16)
  {
    cout << hexDigits[n];
  }
  else
  {
    PrintHex(n / 16);
    cout << hexDigits[n % 16];
  }
}

int main()
{
  int n;
  cout << "Enter a number: ";
  cin >> n;
  PrintHex(n);
  cout << endl;
  return 0;
}