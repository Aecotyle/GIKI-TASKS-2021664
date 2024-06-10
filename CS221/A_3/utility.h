#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

void displayMenu()
{
    cout << "\n----------------------\n";
    cout << "Please select your option: \n";
    cout << "1. Insert Node to tree\n";
    cout << "2. Search Node to tree\n";
    cout << "3. Delete Node to tree\n";
    cout << "4. Pre Order traversal\n";
    cout << "5. In Order traversal\n";
    cout << "6. Post Order traversal\n";
    cout << "7. Exit\n";
    cout << "----------------------\n";
}

void screenClear()
{
    for (int i = 0; i < 100; i++)
        cout << "\n";
}

node *createNode(int _val = 0)
{
    node *_node = new node(_val);
    return _node;
}

node *nodeInput()
{
    int x = 0;
    cout << "Please enter the value of node: ";
    cin >> x;
    return createNode(x);
}