#pragma once
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int moveCount = 0;

// represents the Tower of Hanoi with three rods
void hanoiMoves(int n, string from, string to, string extra, bool print = true)
{
  if (n == 0) // base case
  {
    return;
  }
  else
  {
    hanoiMoves(n - 1, from, extra, to, print); // recursively move top disk to extra rod
    moveCount++;                               // for analysis

    if (print)
    {
      cout << "Move disk " << n << " from " << from << " to " << to << endl;
    }

    hanoiMoves(n - 1, extra, to, from, print); // recursively move back to the final rod
  }
}

int main()
{
  cout << "hanoiMoves(3):" << endl;

  moveCount = 0;
  auto start = high_resolution_clock::now();
  hanoiMoves(3, "A", "C", "B");
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);

  cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
  cout << "Number of moves: " << moveCount << endl;

  cout << endl;

  for (int i = 1; i <= 15; i++)
  {
    moveCount = 0;
    start = high_resolution_clock::now();
    hanoiMoves(i, "A", "C", "B", false);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    cout << "hanoiMoves(" << i << "): " << duration.count() << " microseconds, " << moveCount << " moves" << endl;
    if (moveCount == pow(2, i) - 1)
    {
      cout << moveCount << " = (2^n - 1) for n = " << i;
    }
    else
    {
      cout << moveCount << " != (2^n - 1) for n = " << i;
    }
    cout << endl;
  }
}