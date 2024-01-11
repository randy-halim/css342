#include <iostream>

void swapInts(int &a, int &b)
{
  int c = a;

  a = b;
  b = c;
}

int main()
{
  int testA = 45;
  int testB = 88;

  swapInts(testA, testB);

  std::cout << "a = " << testA << std::endl;
  std::cout << "b = " << testB << std::endl;

  return 0;
}