#include <iostream>
using namespace std;

int nChooseK(int n, int k)
{
  if (k == 0 || k == n)
  {
    return 1;
  }
  else
  {
    return nChooseK(n - 1, k - 1) + nChooseK(n - 1, k);
  }
}

int main()
{
  int n, k;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter k: ";
  cin >> k;
  cout << "n choose k is " << nChooseK(n, k) << endl;
  return 0;
}