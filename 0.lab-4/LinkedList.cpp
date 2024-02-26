#pragma once
#include "LinkedList.h"
#include <fstream>
#include <iostream>
using namespace std;

template <class ItemType>

// -----
// LinkedList class
// -----

// constructor
// -----
LinkedList<ItemType>::LinkedList()
{
    this->head = nullptr;
}

// copy constructor
// -----
template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &list)
{
    this->head = nullptr;
    *this = list;
}

// destructor
// -----
template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    DeleteList();
}

// bool BuildList(string fileName);
// -----
template <class ItemType>
bool LinkedList<ItemType>::BuildList(string fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile)
    {
        return false;
    }
    while (inFile)
    {
        ItemType *obj = new ItemType;
        if (inFile >> *obj)
        {
            Insert(obj);
            delete obj;
        }
        else
        {
            delete obj;
            break;
        }
    }
    inFile.close();
    return true;
}

// bool Insert(ItemType *obj);
// -----
// return false on duplicate found (failure)
// create copy of ItemType object and insert into list
// the inserted item should be in the correct order
template <class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
    Node<ItemType> *nextNode = new Node<ItemType>;
    nextNode->data = obj;
    nextNode->next = nullptr;
    Node<ItemType> *temp = head;

    if (this->isEmpty() || *(head->data) > *(obj))
    {
        nextNode->next = head;
        head = nextNode;
        return true;
    }
    if (*(head->data) == *(obj))
    {
        delete nextNode;
        return false;
    }

    while (temp->next != nullptr && *(obj) >= *(temp->next->data))
    {
        if (*(temp->next->data) == *(obj))
        {
            delete nextNode;
            return false;
        }
        temp = temp->next;
    }

    nextNode->next = temp->next;
    temp->next = nextNode;
    return true;
}
// template <class ItemType>
// bool LinkedList<ItemType>::Insert(ItemType *obj)
// {
//     if (isEmpty())
//     {
//         this->head = new Node<ItemType>;
//         this->head->data = new ItemType(*obj);
//         this->head->next = nullptr;
//         return true;
//     }
//     Node<ItemType> *current = this->head;
//     if (*(current->data) == *obj)
//     {
//         return false;
//     }
//     if (*(current->data) > *obj)
//     {
//         Node<ItemType> *temp = new Node<ItemType>;
//         temp->data = new ItemType(*obj);
//         temp->next = this->head;
//         this->head = temp;
//         return true;
//     }
//     while (current->next != nullptr)
//     {
//         if (*(current->next->data) == *obj)
//         {
//             return false;
//         }
//         if (*(current->next->data) > *obj)
//         {
//             Node<ItemType> *temp = new Node<ItemType>;
//             temp->data = new ItemType(*obj);
//             temp->next = current->next;
//             current->next = temp;
//             return true;
//         }
//         current = current->next;
//     }
//     Node<ItemType> *temp = new Node<ItemType>;
//     temp->data = new ItemType(*obj);
//     temp->next = nullptr;
//     current->next = temp;
//     return true;
// }

// bool Remove(ItemType target, ItemType &result);
// -----
// remove based on target, return the item by reference
// return false if not found
template <class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
    if (isEmpty())
    {
        return false;
    }
    Node<ItemType> *current = this->head;
    if (*(current->data) == target)
    {
        result = *(current->data);
        Node<ItemType> *temp = this->head;
        this->head = this->head->next;
        delete temp;
        return true;
    }
    while (current->next != nullptr)
    {
        if (*(current->next->data) == target)
        {
            result = *(current->next->data);
            Node<ItemType> *temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    return false;
}

// bool Peek(ItemType target, ItemType &result) const;
// -----
// same as delete, but do not remove from list
template <class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result) const
{
    if (isEmpty())
    {
        return false;
    }
    Node<ItemType> *current = this->head;
    while (current != nullptr)
    {
        if (*(current->data) == target)
        {
            result = *(current->data);
            return true;
        }
        current = current->next;
    }
    return false;
}

// bool isEmpty() const;
template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return this->head == nullptr;
}

// void DeleteList();
// -----
// delete all nodes
// also delete the data in each node (no memory leaks)
template <class ItemType>
void LinkedList<ItemType>::DeleteList()
{
    Node<ItemType> *current = this->head;
    while (current != nullptr)
    {
        Node<ItemType> *temp = current;
        current = current->next;
        delete temp;
    }
    this->head = nullptr;
}

// bool Merge(LinkedList<ItemType> &list1);
// -----
// given a sorted list (?) merge it into the current (sorted ?) list
// do not allow duplicates, do not allocate new memory
// list1 should be empty after the merge
// return false if list1 is not sorted or if there are duplicates
template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList<ItemType> &list1)
{
    if (list1.isEmpty())
    {
        return true;
    }
    if (this->head == list1.head)
    {
        return false;
    }

    Node<ItemType> *current = this->head;
    Node<ItemType> *current1 = list1.head;
    Node<ItemType> *prev = nullptr;
    while (current != nullptr && current1 != nullptr)
    {
        if (*(current->data) == *(current1->data))
        {
            Node<ItemType> *temp = current1;
            current1 = current1->next;
            delete temp;
        }
        else if (*(current->data) < *(current1->data))
        {
            prev = current;
            current = current->next;
        }
        else
        {
            Node<ItemType> *temp = current1;
            current1 = current1->next;

            if (prev == nullptr)
            {
                temp->next = this->head;
                this->head = temp;
            }
            else if (*(prev->data) < *(temp->data))
            {
                prev->next = temp;
                temp->next = current;
                prev = temp;
            }
            else
            {
                delete temp;
            }
        }
    }

    if (current1 != nullptr)
    {
        if (prev == nullptr)
        {
            head = current1;
        }
        else
        {
            prev->next = current1;
        }
        list1.head = nullptr;
    }
    return true;
}

// LinkedList<ItemType> operator+(const LinkedList<ItemType> &list);
// -----
// new list with items from both lists
// assumed to be sorted, return a sorted list
// no duplicates are allowed, throw an exception if found
// use an efficient sorting algorithm
template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList<ItemType> &list)
{
    LinkedList<ItemType> newList;
    Node<ItemType> *current = this->head;
    Node<ItemType> *current1 = list.head;
    while (current != nullptr)
    {
        newList.Insert(current->data);
        current = current->next;
    }
    while (current1 != nullptr)
    {
        newList.Insert(current1->data);
        current1 = current1->next;
    }
    return newList;
}

// LinkedList<ItemType> &operator+=(const LinkedList<ItemType> &list);
// -----
// same as +, but modify the current list
template <class ItemType>
LinkedList<ItemType> &LinkedList<ItemType>::operator+=(const LinkedList<ItemType> &list)
{
    Node<ItemType> *current = list.head;
    while (current != nullptr)
    {
        Insert(current->data);
        current = current->next;
    }
    return *this;
}

// ostream &operator<<(ostream &out, const LinkedList<ItemType> &list);
// -----
// print the list, no extra blanks/endlines/etc
// display the list in increasing order
template <typename ItemType>
ostream &operator<<(ostream &out, const LinkedList<ItemType> &list)
{
    Node<ItemType> *current = list.head;
    while (current != nullptr)
    {
        out << *(current->data);
        current = current->next;
    }
    return out;
}

// bool operator==(const LinkedList<ItemType> &list);
// -----
// compare two lists, return true if they are the same
template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType> &list)
{
    Node<ItemType> *current = this->head;
    Node<ItemType> *current1 = list.head;
    while (current != nullptr && current1 != nullptr)
    {
        if (*(current->data) != *(current1->data))
        {
            return false;
        }
        current = current->next;
        current1 = current1->next;
    }
    return current == nullptr && current1 == nullptr;
}

// bool operator!=(const LinkedList<ItemType> &list);
// -----
// compare two lists, return true if they are not the same
template <class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList<ItemType> &list)
{
    return !(*this == list);
}

// LinkedList<ItemType> &operator=(const LinkedList<ItemType> &list);
// -----
// deep copy of list
template <class ItemType>
LinkedList<ItemType> &LinkedList<ItemType>::operator=(const LinkedList<ItemType> &list)
{
    if (this == &list)
    {
        return *this;
    }
    DeleteList();
    Node<ItemType> *current = list.head;
    while (current != nullptr)
    {
        Insert(current->data);
        current = current->next;
    }
    return *this;
}