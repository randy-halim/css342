#include "LinkedList.h"
#include "Child.h"
#include <iostream>

using namespace std;

const string inFile = "input.txt";
const string inFile2 = "int_input.txt";

int main()
{
  // create a linked list of Child objects
  LinkedList<Child> class1;
  class1.BuildList(inFile);

  // print the list
  cout << class1 << endl;

  LinkedList<int> intList;
  intList.BuildList(inFile2);

  cout << intList << endl;

  return 0;
}