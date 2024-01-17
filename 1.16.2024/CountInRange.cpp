#include <iostream>
#include <vector>
using namespace std;

int CountInRange(vector<int> &v, int min, int max)
{
  int count = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] >= min && v[i] <= max)
    {
      count++;
    }
  }
  return count;
}

int main()
{
  vector<int> v = {3, 5, 7};

  cout << "CountInRange(v, 1, 9) = " << CountInRange(v, 1, 9) << endl;
  cout << "CountInRange(v, 4, 6) = " << CountInRange(v, 4, 6) << endl;
}