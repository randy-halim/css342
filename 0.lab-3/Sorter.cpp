#pragma once
#include "SortImpls.cpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;

void printVector(vector<int> *arr)
{
  for (int i = 0; i < arr->size(); i++)
  {
    cout << "items[" << i << "] = " << arr->at(i) << endl;
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    cout << "Usage: " << argv[0] << " BubbleSort|InsertionSort|MergeSort|QuickSort|ShellSort <num-elements> [print: YES|NO] [generateType: random|ordered|partial|reversed|input]" << endl;
    return 1;
  }
  else
  {
    string sortType = argv[1];
    int numElements = atoi(argv[2]);
    bool print = argc > 3 && string(argv[3]) == "NO" ? false : true;
    string generateType = argc > 4 ? argv[4] : "random";

    vector<int> *arr = new vector<int>(); // YOU HAVE TO `new` THIS RAHHHHHHHH

    if (numElements < 1)
    {
      cout << "Number of elements must be greater than 0." << endl;
      return 1;
    }
    else if (numElements <= 10 || generateType == "input") // ask user for input
    {
      for (int i = 0; i < numElements; i++)
      {
        int value;
        cout << "items[" << i << "] = ";
        cin >> value;
        arr->push_back(value);
      }
    }
    else if (generateType == "random") // generate random numbers
    {
      for (int i = 0; i < numElements; i++)
      {
        arr->push_back(i + 1);
      }
      shuffle(arr->begin(), arr->end(), default_random_engine());
    }
    else if (generateType == "ordered") // generate ordered numbers
    {
      for (int i = 0; i < numElements; i++)
      {
        arr->push_back(i + 1);
      }
    }
    else if (generateType == "partial") // generate partially ordered numbers
    {
      // fill full array with ordered numbers
      for (int i = 0; i < numElements; i++)
      {
        arr->push_back(i + 1);
      }
      // get random index range of array
      int startIndex = rand() % numElements;
      int endIndex = rand() % numElements;
      if (startIndex > endIndex)
      {
        int temp = startIndex;
        startIndex = endIndex;
        endIndex = temp;
      }
      // shuffle the subset of the array
      shuffle(arr->begin() + startIndex, arr->begin() + endIndex, default_random_engine());
    }
    else if (generateType == "reversed") // generate reversed numbers
    {
      for (int i = 0; i < numElements; i++)
      {
        arr->push_back(numElements - i);
      }
    }
    else
    {
      cout << "Invalid generate type: " << generateType << endl;
      return 1;
    }

    if (print)
    {
      cout << "Inital:" << endl;
      printVector(arr);
    }

    auto start = high_resolution_clock::now();

    if (sortType == "BubbleSort")
    {
      BubbleSort(arr, 0, arr->size() - 1);
    }
    else if (sortType == "InsertionSort")
    {
      InsertionSort(arr, 0, arr->size() - 1);
    }
    else if (sortType == "MergeSort")
    {
      MergeSort(arr, 0, arr->size() - 1);
    }
    else if (sortType == "QuickSort")
    {
      QuickSort(arr, 0, arr->size() - 1);
    }
    else if (sortType == "ShellSort")
    {
      ShellSort(arr, 0, arr->size() - 1);
    }
    else
    {
      cout << "Invalid sort type: " << sortType << endl;
      return 1;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    // check the result, should be sequentially ordered
    for (int i = 1; i < arr->size(); i++)
    {
      if (arr->at(i) < arr->at(i - 1))
      {
        cout << "Error: items[" << i << "] = " << arr->at(i) << " is less than items[" << i - 1 << "] = " << arr->at(i - 1) << endl;
        return 125;
      }
    }

    if (print)
    {
      cout << "Sorted:" << endl;
      printVector(arr);
    }

    cout << "Time (ms): " << duration.count() << endl;

    delete arr;
    return 0;
  }
}