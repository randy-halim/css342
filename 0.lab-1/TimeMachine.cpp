#pragma once
#include "TimeSpan.h"
using namespace std;

int main()
{
  cout << "Any bools that are 1 are true, 0 are false" << endl;

  TimeSpan ts1 = TimeSpan(1, 2, 3);
  TimeSpan ts2 = TimeSpan(4, 5, 6);
  TimeSpan ts3 = TimeSpan(4, 5, 6);

  cout << "ts1: " << ts1 << endl;
  cout << "ts2: " << ts2 << endl;
  cout << "ts3: " << ts3 << endl;

  cout << endl;

  if (ts1 == ts2)
  {
    cout << "ts1 is equal to ts2 (this should not run)";
  }
  else
  {
    cout << "ts1 is not equal to ts2 (this should run)";
  }
  cout << endl;

  if (ts2 == ts3)
  {
    cout << "ts2 is equal to ts3 (this should run)";
  }
  else
  {
    cout << "ts2 is not equal to ts3 (this should not run)";
  }
  cout << endl
       << endl;

  TimeSpan ts4 = TimeSpan(5, 7, 9);
  TimeSpan ts5 = ts1 + ts2;

  cout << "ts4: " << ts4 << endl;
  cout << "ts5: " << ts5 << endl;
  cout << "These should be equal: " << (ts4 == ts5) << endl;

  cout << endl;

  TimeSpan ts6 = ts5 - ts1;

  cout << "ts6: " << ts6 << endl;
  cout << "ts2: " << ts2 << endl;
  cout << "These should be equal: " << (ts6 == ts2) << endl;

  cout << endl;

  TimeSpan ts7 = ts6 - ts2;

  cout << "ts7: " << ts7 << endl;
  cout << "ts1: " << ts1 << endl;
  cout << "These should be equal: " << (ts7 == ts1) << endl;

  cout << endl;

  TimeSpan ts8 = -ts1;
  TimeSpan ts9 = TimeSpan(0, 0, 0) - ts1;

  cout << "ts8: " << ts8 << endl;
  cout << "ts9: " << ts9 << endl;
  cout << "These should be equal: " << (ts8 == ts9) << endl;

  cout << endl;

  TimeSpan ts10;
  cout << "Enter a time span (hours, minutes, seconds): ";
  cin >> ts10;
  cout << "ts10: " << ts10 << endl;

  TimeSpan ts11 = TimeSpan(1.5, 4, -10);
  cout << "ts11: " << ts11 << endl;

  return 0;
}