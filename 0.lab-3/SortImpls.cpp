#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int swapCount = 0;
void swap(vector<int> *arr, int i, int j)
{
  int temp = arr->at(i);
  arr->at(i) = arr->at(j);
  ;
  arr->at(j) = temp;
  swapCount += 3; // 3 assignment operations
}

void BubbleSort(vector<int> *arr, int startIndex, int endIndex)
{
  // "borrowed" from Active Intro to Discrete Math & Algorithms
  // Example. 7.132.
  for (int i = endIndex; i > startIndex; i--)
  {
    for (int j = startIndex; j < i; j++)
    {
      if (arr->at(j) > arr->at(j + 1))
      {
        swap(arr, j, j + 1);
      }
    }
  }
}

void InsertionSort(vector<int> *arr, int startIndex, int endIndex)
{
  int j, key;

  for (int i = startIndex + 1; i < endIndex + 1; i++)
  {
    j = i - 1;
    key = arr->at(i);

    while (j >= startIndex && arr->at(j) > key)
    {
      arr->at(j + 1) = arr->at(j);
      j--;
    }

    arr->at(j + 1) = key;
  }
}

// from Carrano's textbook, p. 314-316
void merge(vector<int> *arr, int startIndex, int midpoint, int endIndex)
{
  int leftSize = midpoint - startIndex + 1;
  int rightSize = endIndex - midpoint;

  vector<int> left(leftSize);   // left vector with size `leftSize`
  vector<int> right(rightSize); // right vector with size `rightSize`

  for (int i = 0; i < leftSize; i++)
  {
    left.at(i) = arr->at(startIndex + i);
  }
  for (int i = 0; i < rightSize; i++)
  {
    right.at(i) = arr->at(midpoint + 1 + i);
  }

  int i = 0, j = 0, k = startIndex;
  while (i < leftSize && j < rightSize)
  {
    if (left.at(i) <= right.at(j))
    {
      arr->at(k) = left.at(i);
      i++;
    }
    else
    {
      arr->at(k) = right.at(j);
      j++;
    }
    k++;
  }

  while (i < leftSize)
  {
    arr->at(k) = left.at(i);
    i++;
    k++;
  }

  while (j < rightSize)
  {
    arr->at(k) = right.at(j);
    j++;
    k++;
  }
}

void MergeSort(vector<int> *arr, int startIndex, int endIndex)
{
  // from Carrano's textbook, p. 314-316
  // done recursively
  if (startIndex < endIndex)
  {
    int midpoint = (startIndex + endIndex) / 2;

    // vector for [startIndex ... midpoint]
    MergeSort(arr, startIndex, midpoint);

    // vector for [midpoint+1 ... endIndex]
    MergeSort(arr, midpoint + 1, endIndex);

    // merge the two vectors
    merge(arr, startIndex, midpoint, endIndex);
  }
}

// satisfies the median-of-three pivot selection requirement
const int QUICKSORT_MIN_SIZE = 4;

int quickSortMedianOfThree(vector<int> *arr, int i, int j, int k)
{
  int medianIndex;
  int a = arr->at(i);
  int b = arr->at(j);
  int c = arr->at(k);

  if ((a <= b && b <= c) || (c <= b && b <= a))
  {
    medianIndex = j;
  }
  else if ((b <= a && a <= c) || (c <= a && a <= b))
  {
    medianIndex = i;
  }
  else
  {
    medianIndex = k;
  }

  return medianIndex;
}

int quickSortPartition(vector<int> *arr, int startIndex, int endIndex)
{
  // this assumes there are at least 4 elements in the vector
  // according to our Median-of-Three pivot selection
  int midIndex = (startIndex + endIndex) / 2;

  int pivotIndex = quickSortMedianOfThree(arr, startIndex, midIndex, endIndex);
  int pivotValue = arr->at(pivotIndex);

  swap(arr, pivotIndex, endIndex); // this was important apparently

  int i = startIndex;

  for (int j = startIndex; j < endIndex; j++)
  {
    if (arr->at(j) < pivotValue)
    {
      swap(arr, i, j);
      i++;
    }
  }

  swap(arr, i, endIndex);

  return i;
}

void QuickSort(vector<int> *arr, int startIndex, int endIndex)
{
  // from Carrano's textbook, p. 324
  // uses our InsertionSort when the size of the vector is less than QUICKSORT_MIN_SIZE
  // (in accordance with the algorithm implementation provided by Carrano)

  if (endIndex - startIndex + 1 < QUICKSORT_MIN_SIZE)
  {
    InsertionSort(arr, startIndex, endIndex);
  }
  else
  {
    int pivotIndex = quickSortPartition(arr, startIndex, endIndex);
    QuickSort(arr, startIndex, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, endIndex);
  }
}

void ShellSort(vector<int> *arr, int startIndex, int endIndex)
{
  // from Wikipedia: https://en.wikipedia.org/wiki/Shellsort

  // utilizes repeated insertion sorts using a decreasing gap sequence
  // determined by the OEIS A036562 sequence (https://oeis.org/A036562) (Sedgewick, 1982)

  // determine the gap sequence to use dynamically, based on the size of the vector
  vector<int> *gaps = new vector<int>();
  int currentGap = 1;
  int k = 1;
  while (currentGap < endIndex - startIndex + 1)
  {
    gaps->push_back(currentGap);
    currentGap = pow(4, k) + 3 * pow(2, k - 1) + 1;
    k++;
  }

  // repeated insertion sorts
  while (!gaps->empty())
  {
    int gap = gaps->back();
    gaps->pop_back();

    for (int i = startIndex + gap; i <= endIndex; i++)
    {
      int temp = arr->at(i);

      int j = i;
      while ((j >= gap) && (arr->at(j - gap) > temp))
      {
        arr->at(j) = arr->at(j - gap);
        j -= gap;
      }

      arr->at(j) = temp;
    }
  }

  delete gaps;
}