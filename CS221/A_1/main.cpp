#ifndef HEADER_H
#define HEADER_H
#include "header.h"
#endif

int main()
{
    int option;
    bool loop = true;
    linkedList List;
    List.createList();

    while (loop)
    {
        cout << "Press any key to continue...\n";
        //cin.get() for Mac & Linux
        cin.get();
        //getch() for Windows
        // getch();
        //clearing screen
        for (int i = 0; i < 99; i++)
            cout << '\n';
        printMenu();
        validIntInput(option);
        while (option < 1 || option > 5)
        {
            cout << "Please enter valid option between 1 to 5 \n";
            validIntInput(option);
        }
        Node *tempNode = new Node();
    
        switch (option)
        {
        case 1:
            List.userInput(tempNode);
            if (List.search(tempNode, true))
            {
                cout << "User already exist with that phone number\n";
                cout << "Your phone number must be unique\n";
            }
            else
                List.insertNode(tempNode);
            break;
        case 2:
            cout << "Enter the detail you know about user and leave other blank\n";
            List.userInput(tempNode);
            tempNode = List.search(tempNode);
            if (tempNode)
                List.deleteNode(tempNode);
            else
                List.print(tempNode);
            break;
        case 3:
            cout << "Enter the detail you know about user and leave other blank\n";
            List.userInput(tempNode);
            List.print(List.search(tempNode));
            break;
        case 4:
            List.printAll();
            break;
        case 5:
            loop = false;
            break;
        }
    }

    return 0;
}
