#pragma once
#include <string>
using namespace std;

template <typename NodeItemType>
struct Node
{
    NodeItemType *data;
    Node *next;
};

template <typename ItemType>
class LinkedList
{
public:
    bool BuildList(string fileName);
    bool Insert(ItemType *obj);
    bool Remove(ItemType target, ItemType &result);
    bool Peek(ItemType target, ItemType &result) const;
    bool isEmpty() const;
    void DeleteList();
    bool Merge(LinkedList<ItemType> &list1);

    // operator overrides: +, +=, <<, ==, !=, = (deep copy)
    LinkedList<ItemType> operator+(const LinkedList<ItemType> &list);
    LinkedList<ItemType> &operator+=(const LinkedList<ItemType> &list);
    template <typename Output>
    friend ostream &operator<<(ostream &out, const LinkedList<Output> &list);
    bool operator==(const LinkedList<ItemType> &list);
    bool operator!=(const LinkedList<ItemType> &list);
    LinkedList<ItemType> &operator=(const LinkedList<ItemType> &list);

    // constructor, copy constructor, destructor
    LinkedList();
    LinkedList(const LinkedList<ItemType> &list);
    ~LinkedList();

private:
    Node<ItemType> *head;
};

template <typename ItemType>
ostream &operator<<(ostream &out, const LinkedList<ItemType> &list);

#include "LinkedList.cpp" // include the implementation file