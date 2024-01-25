#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

int moveCount = 0;

void PrintStringReversal(string str)
{
  if (str.length() == 0)
  {
    cout << endl;
    return;
  }

  moveCount++;
  cout << str[str.length() - 1];
  PrintStringReversal(str.substr(0, str.length() - 1));
}

bool isPal(string str)
{
  if (str.length() <= 1)
  {
    return true;
  }
  else
  {
    if (str[0] == str[str.length() - 1])
    {
      moveCount++;
      return isPal(str.substr(1, str.length() - 2));
    }
    else
    {
      return false;
    }
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "Enter a string: ";
  string str1;
  cin >> str1;

  moveCount = 0;
  start = high_resolution_clock::now();
  PrintStringReversal(str1);
  end = high_resolution_clock::now();
  duration = duration_cast<microseconds>(end - start);
  cout << "Time: " << duration.count() << " microseconds; Moves: " << moveCount << endl;

  cout << "Enter another string: ";
  string str2;
  cin >> str2;

  moveCount = 0;
  start = high_resolution_clock::now();
  bool pal = isPal(str2);
  end = high_resolution_clock::now();
  duration = duration_cast<microseconds>(end - start);

  if (pal)
  {
    cout << "String '" << str2 << "' is a palindrome" << endl;
  }
  else
  {
    cout << "String '" << str2 << "' is not a palindrome" << endl;
  }
  cout << "Time: " << duration.count() << " microseconds; Moves: " << moveCount << endl;

  return 0;
}