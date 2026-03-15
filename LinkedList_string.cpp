//
//  LinkedList_string.cpp
//  LinkedList_string
//
//  Created by Ahmet Bora Bakır on 3/15/26.
//

#include "LinkedList_string.h"

LinkedList::LinkedList():head(nullptr)
{
}

LinkedList::LinkedList(const LinkedList& other)
{
    if(other.head == nullptr)
    {
        head = nullptr;
        return;
    }
    
    head  = new Node(other.head -> data);
    
    Node* currentNew = head;
    Node* currentOld = other.head -> next;
    
    while(currentOld != nullptr)
    {
        currentNew -> next = new Node(currentOld -> data);
        
        currentOld = currentOld -> next;
        currentNew = currentNew -> next;
    }
}

LinkedList::~LinkedList()
{
    Node* current = head;
    while(current != nullptr)
    {
        Node* nextNode = current -> next;
        delete current;
        current = nextNode;
    }
}

string& LinkedList::at(int index)
{
    Node* current;
    if(head != nullptr && index >= 0)
        current = head;
    else throw "Out of bounds!\n";
    
    for(int i = 0 ; i < index ; i++)
    {
        if(current -> next != nullptr)
            current = current -> next;
        else throw "Out of bounds!\n";
    }
    return current -> data;
}

string& LinkedList::front()
{
    if(head != nullptr)
        return head -> data;
    throw "Head is null!\n";
}

string& LinkedList::back()
{
    Node* current;
    
    if(head != nullptr)
        current = head;
    else throw "Head is null!\n";
    
    while(current -> next != nullptr)
        current = current -> next;
    return current -> data;
}

void LinkedList::push_back(const string& value)
{
    Node* current;
    
    if(head != nullptr)
    {
        current = head;
        while(current -> next != nullptr)
            current = current -> next;
        current -> next = new Node(value);
    }
    else head = new Node(value);
}

void LinkedList::pop_back()
{
    Node* current;
    if(head != nullptr)
        current = head;
    else throw "Head is null!\n";
    
    if(current -> next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    
    while(current -> next -> next != nullptr)
        current = current -> next;
    delete current -> next;
    current -> next = nullptr;
}

void LinkedList::push_front(const string& value)
{
    Node* newHead = new Node(value);
    newHead -> next = head;
    
    head = newHead;
}

void LinkedList::pop_front()
{
    Node* temp;
    if(head != nullptr)
        temp = head -> next;
    else throw "Head is null!\n";
    
    delete head;
    head = temp;
}

void LinkedList::insert_at(int index, const string& value)
{
    Node* current;
    if(head != nullptr && index >= 0)
        current = head;
    else throw "Out of bounds!\n";
    
    if (index == 0)
    {
        push_front(value);
        return;
    }
    for(int i = 0 ; i < index - 1 ; i++)
    {
        if(current -> next != nullptr)
            current = current -> next;
        else
            throw "Out of bounds!\n";
    }
    Node* newNode = new Node(value);
    newNode -> next = current -> next;
    current -> next = newNode;
    
}

void LinkedList::insert_after(int index, const string& val)
{
    Node* current;
    if(index >= 0 && head != nullptr)
        current = head;
    else throw "Out of bounds!\n";
    
    
    for(int i = 0 ; i < index ; i++)
    {
        if(current -> next != nullptr)
            current = current -> next;
        else throw "Out of bounds!\n";
    }
    Node* temp = new Node(val);
    temp -> next = current -> next;
    current -> next = temp;
}

void LinkedList::erase_at(int index)
{
    Node* current;
    if(head != nullptr && index >= 0)
        current = head;
    else throw "Head is null!\n";
    
    if(index == 0)
    {
        Node* temp = head -> next;
        delete head;
        head = temp;
        return;
    }
    
    for(int i = 0 ; i < index - 1 ; i++)
    {
        if(current -> next != nullptr)
            current = current -> next;
        else throw "Out of bounds!\n";
    }
    Node* temp;
    if(current -> next -> next != nullptr)
    {
        temp = current -> next -> next;
        delete current -> next;
        current -> next = temp;
        return;
    }
    
    delete current -> next;
    current -> next = nullptr;
}


void LinkedList::erase(const string& e)
{
    Node* current;
    if(head != nullptr)
        current = head;
    else throw "Head is null!\n";
    bool flag = false;
    if(head -> data == e)
    {
        current = head -> next;
        delete head;
        head = current;
        return;
    }
    while(current -> next != nullptr)
    {
        if(current -> next -> data != e)
            current = current -> next;
        else
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        Node* temp = current -> next;
        current -> next = current -> next -> next;
        delete temp;
    }
}

void LinkedList::clear()
{
    Node* current = head;
    while(current != nullptr)
    {
        Node* nextNode = current -> next;
        delete current;
        current = nextNode;
    }
}

int LinkedList::size() const
{
    Node* current = head;
    
    int counter = 0;
    
    while(current != nullptr)
    {
        current = current -> next;
        counter++;
    }
    return counter;
   
}

bool LinkedList::empty() const
{
    return head == nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& lhs)
{
    // TODO: insert return statement here
    if (this == &lhs) return *this;
    clear();
    if(lhs.head == nullptr)
    {
        head = nullptr;
        return *this;
    }
    
    head  = new Node(lhs.head -> data);
    
    Node* currentNew = head;
    Node* currentOld = lhs.head -> next;
    
    while(currentOld != nullptr)
    {
        currentNew -> next = new Node(currentOld -> data);
        
        currentOld = currentOld -> next;
        currentNew = currentNew -> next;
    }
    return *this;
    
}
Node* LinkedList::findMiddleNode()
{
    if(head == nullptr)
        return nullptr;
    int size = this -> size();
    Node* current = head;
    
    for(int i = 0 ; i < size / 2 ; i++)
    {
        current = current -> next;
    }
    return current;
}

Node* LinkedList::getSmallestNode()
{
    if(head == nullptr)
        return nullptr;
    Node* smallestNode= head;
    
    int size = this -> size();
    
    Node* current = head -> next;
    for(int i = 1 ; i < size ; i++)
    {
        if(current -> data < smallestNode -> data)
            smallestNode = current;
        current = current -> next;
    }
    return smallestNode;
}

void LinkedList::moveSmallestToFront()
{
    Node* smallest = getSmallestNode();
    
    
    if(smallest != nullptr && head -> next != nullptr && smallest != head)
    {
        int size = this -> size();
        Node* current = head;
        for(int i = 0 ; i < size ; i++)
        {
            if(current -> next == smallest)
                break;
            current = current -> next;
        }
        current -> next = current -> next -> next;
        
        Node* temp = head;
        head = smallest;
        smallest -> next = temp;
        
    }
    
}


bool LinkedList::operator==(const LinkedList& lhs) const
{
    if (this == &lhs) return true;
    
    Node* p1 = head;
    Node* p2 = lhs.head;
    
    
    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1 -> data != p2 -> data)
            return false;
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    return (p1 == nullptr && p2 == nullptr);
    
}

ostream& operator<<(ostream& out, const LinkedList& list)
{
    Node* current = list.head;
    while(current != nullptr)
    {
        out << *current;
        current = current -> next;
    }
    return out;
}
