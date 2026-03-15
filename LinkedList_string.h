//
//  LinkedList_string.h
//  LinkedList_string
//
//  Created by Ahmet Bora Bakır on 3/15/26.
//

#ifndef LinkedList_string_h
#define LinkedList_string_h


#pragma once
#include"Node.h"
#include <string>
#include <iostream>
using namespace std;
class LinkedList {
private:
    Node* head;
public:
    // Constructors
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();

    // Element Access
    string& at(int index);
    string& front();
    string& back();
    Node* findMiddleNode();
    Node* getSmallestNode();
    

    // Modifiers
    void push_back(const string& value);
    void pop_back();
    void push_front(const string& value);
    void pop_front();
    void insert_at(int index, const string& value);
    void insert_after(int index, const string& val);
    void erase_at(int index);
    void erase(const string& e);
    void clear();
    void moveSmallestToFront();
    

    // Capacity
    int size() const;
    bool empty() const;
    

    LinkedList& operator=(const LinkedList& lhs);
    bool operator==(const LinkedList& lhs)const;

    friend ostream& operator<<(ostream& out, const LinkedList &list);

};


#endif /* LinkedList_string_h */
