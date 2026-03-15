//
//  Node.h
//  LinkedList_string
//
//  Created by Ahmet Bora Bakır on 3/15/26.
//

#ifndef Node_h
#define Node_h


#pragma once
#include <string>
#include <iostream>
#include<ostream>
using namespace std;
class Node
{
public:
    string data;
    Node* next;

    Node():next(nullptr){}
    Node(const string &na) :next(nullptr), data(na) {}

    void print()const {
        cout << data << " -> ";
    }
    friend ostream& operator<< (ostream& out, const Node & obj);
};

inline ostream& operator<<(ostream& out, const Node& obj)
{
    out << obj.data << string(" -> ");
    return out;
}


#endif /* Node_h */
