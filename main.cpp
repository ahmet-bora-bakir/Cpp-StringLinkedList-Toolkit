//
//  main.cpp
//  LinkedList_string
//
//  Created by Ahmet Bora Bakır on 3/15/26.
//
#include "Node.h"
#include "LinkedList_string.h"

using namespace std;

int main()
{
    cout << "\nWelcome to the Linked List Program!" << endl;
    LinkedList list;
    string val;
    int idx;
    
    string input;
    do
    {
        cout << "Menu:" << endl
        << "1. Add an element" << endl
        << "2. Remove an element by value" << endl
        << "3. Access an element at index" << endl
        << "4. Insert an element at index" << endl
        << "5. Insert an element after index" << endl
        << "6. Remove an element at index" << endl
        << "7. Print the linked list" << endl
        << "8. Print the size of the linked list" << endl
        << "9. Check if the linked list is empty" << endl
        << "10. Clear the linked list" << endl
        << "11. Find middle node" << endl
        << "12. Find smallest node" << endl
        << "13. Move smallest to front" << endl
        << "x. Exit" << endl
        << "Selection: ";
        cin >> input;
        
        if (input == "x" || input == "X")
            break;
        int choice;
                try {
                    choice = stoi(input);
                } catch (...) {
                    cout << "Invalid input! Please enter a number or 'x'." << endl;
                    continue;
                }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.push_back(val);
                break;
            case 2:
                cout << "Enter value to remove: ";
                cin >> val;
                list.erase(val);
                break;
            case 3:
                cout << "Enter index: ";
                cin >> idx;
                
                try { cout << "Value: " << list.at(idx) << endl; }
                catch (...) { cout << "Invalid index!" << endl; }
                
                break;
            case 4:
                cout << "Enter index: ";
                cin >> idx;
                cout << "Enter value: ";
                cin >> val;
                list.insert_at(idx, val);
                break;
            case 5:
                cout << "Enter index: ";
                cin >> idx;
                cout << "Enter value: ";
                cin >> val;
                list.insert_after(idx, val);
                break;
            case 6:
                cout << "Enter index: ";
                cin >> idx;
                list.erase_at(idx);
                break;
            case 7:
                cout << list << endl;
                break;
            case 8:
                cout << "Size: " << list.size() << endl;
                break;
            case 9:
                cout << (list.empty() ? "List is empty." : "List is not empty.") << endl;
                break;
            case 10:
                list.clear();
                break;
            case 11:
                cout << "Middle one: " << list.findMiddleNode() -> data << endl;
                break;
            case 12:
                cout << "Smallest one: " << list.getSmallestNode() -> data << endl;
                break;
            case 13:
                list.moveSmallestToFront();
                cout << "Smallest one moved to front." << endl;
                break;
        }
    }while(true);
        
        
}
