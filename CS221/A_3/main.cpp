#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

int main()
{
    BST tree;

    // Data Inseted to test code
    //  You can comment/delete it and insert your own data
    tree.insertNode(createNode(25));
    tree.insertNode(createNode(15));
    tree.insertNode(createNode(50));
    tree.insertNode(createNode(10));
    tree.insertNode(createNode(22));
    tree.insertNode(createNode(35));
    tree.insertNode(createNode(70));
    tree.insertNode(createNode(4));
    tree.insertNode(createNode(12));
    tree.insertNode(createNode(18));
    tree.insertNode(createNode(24));
    tree.insertNode(createNode(31));
    tree.insertNode(createNode(44));
    tree.insertNode(createNode(66));
    tree.insertNode(createNode(90));

    bool loop = true;
    int choice;
    while (loop)
    {
        int x = 0;
        screenClear();
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.insertNode(nodeInput());
            break;
        case 2:
            cout << "Please enter the value to be searched: ";
            cin >> x;
            tree.search(x);
            break;
        case 3:
            cout << "Please enter the value to be deleted: ";
            cin >> x;
            tree.deleteNode(x);

            break;
        case 4:
            cout << "\nPre order traversal: ";
            tree.preOrderTraversal(tree.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "\nIn order traversal: ";
            tree.inOrderTraversal(tree.getRoot());
            cout << endl;
            break;
        case 6:
            cout << "\nPost order traversal: ";
            tree.postOrderTraversal(tree.getRoot());
            cout << endl;
            break;
        case 7:
            loop = false;
            break;

        default:
            cout << "Please select option from 1~6\n";
            break;
        }
        cout << "Press any key to continue...\n";
        // cin.get works on MAC and Linux
        cin.ignore();
        cin.get();
        // Use getch() for Windows
    }
    return 0;
}