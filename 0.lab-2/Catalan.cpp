#include <iostream>
using namespace std;

// Catalan:
//  C(0) = 1
//  C(n) = sum(C(i) * C(n - i - 1), i = 0..n - 1)

int Catalan(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    int accumulate = 0;

    for (int i = 0; i < n; i++)
    {
      accumulate += Catalan(i) * Catalan(n - i - 1);
    }

    return accumulate;
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "Enter one or more numbers, seperated by space." << endl;
    return 1;
  }
  else
  {
    for (int i = 1; i < argc; i++)
    {
      int n = atoi(argv[i]);
      cout << Catalan(n) << endl;
    }
  }
}