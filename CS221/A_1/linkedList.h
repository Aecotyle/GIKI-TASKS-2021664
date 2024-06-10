#ifndef HEADER_H
#define HEADER_H
#include "header.h"
#endif

class linkedList
{
    Node *head;
    Node *tail;
    Node *insertingTail;
    int col;
    int row;
    int counter;

public:
    linkedList(int _row = 0, int _col = 0)
    {
        tail = NULL;
        head = NULL;
        insertingTail = NULL;
        col = _col;
        row = _row;
        counter = 0;
    }

    void createList()
    {
        int _row, _col;
        cout << "Please enter the maximum no. of rows: \n";
        validIntInput(_row);
        cout << "Please enter the maximum no. of columns: \n";
        validIntInput(_col);
        // setting the maximum size of linked list
        this->row = _row;
        this->col = _col;
    }

    void insertNode(Node *node)
    {
        if (counter >= (this->row * this->col))
        {
            cout << "Your record could not be ADDED!\n";
            cout << "The maximum capactiy is " << (this->row * this->col) << endl;
            return;
        }
        if (tail == NULL)
        {
            tail = node;
            insertingTail = node;
        }

        if (counter < col)
        {
            if (head)
                head->prev = node;
            node->next = head;
            head = node;
        }
        else
        {
            node->down = insertingTail;
            insertingTail->up = node;
            if (counter % col != 0)
            {
                node->next = head;
                head->prev = node;
            }
            head = node;
            if ((counter + 1) % col == 0 && counter > col+1)
            {

                insertingTail = tail;
                while (insertingTail->up != NULL)
                    insertingTail = insertingTail->up;
            }
            else
                insertingTail = insertingTail->prev;
        }

        counter++;
    }

    void swapHead(Node *nodeToBeSwapped)
    {
        // swap fucntion simply swap the data/info of two node
        nodeToBeSwapped->phone_num = this->head->phone_num;
        nodeToBeSwapped->owners_name = this->head->owners_name;
        nodeToBeSwapped->email = this->head->email;
        nodeToBeSwapped->address = this->head->address;
    }

    void print(Node *toBePrinted)
    {
        if (toBePrinted == NULL)
            cout << "Record Not found!\n";
        else
        {
            cout << "\n-------------------------------\n";
            cout << "Owner's Name  : " << toBePrinted->owners_name << endl;
            cout << "Phone Number  : " << toBePrinted->phone_num << endl;
            cout << "Email Address : " << toBePrinted->email << endl;
            cout << "Address       : " << toBePrinted->address << endl;
            cout << "\n-------------------------------\n";
        }
    }
    bool isEmpty()
    {
        if (!counter)
            return true;
        else
            return false;
    }
    void deleteNode(Node *toBedeleted)
    {
        if (isEmpty())
        {
            cout << "Deletion unsuccessful!\nPhone directory is Empty\n\n";
        }
        else if (!this->head->next)
        {
            // if only head is present in list
            counter--;
            delete this->head;
            this->head = NULL;
        }
        else
        {
            swapHead(toBedeleted);
            Node *temp = head;
            // if head has no node next to it then head will shift down
            // and traverse back until it reaches start of row
            if (head->next)
            {
                head = head->next;
                head->prev = NULL;
            }
            else
            {
                head = head->down;
                head->up = NULL;
                while (head->prev)
                {
                    head = head->prev;
                }
            }
            delete temp;
            counter--;
        }
        cout << "\nDeletion Successful!\n\n";
    }
    // search
    Node *search(Node *toBeSearched, bool uniqueEntry = false)
    {
        bool found = false;
        int searchMethodFlag;
        Node *temp = this->head;
        bool saveSearch = false;

        // Handling searhc if no user is register
        if (!counter)
            return NULL;

        // searching method
        if (!uniqueEntry)
        {
            cout << "Please select how do you want to search ?\n";
            cout << "1.Phone number\n2.Email address\n3.Name of person\n";
            do
            {
                validIntInput(searchMethodFlag);
            } while (searchMethodFlag > 3 || searchMethodFlag < 1);
        }
        else
            searchMethodFlag = 1;

        while (true)
        {

            while (!found)
            {
                // depending on the flag values it will search accroding to that parameter
                if (temp->phone_num == toBeSearched->phone_num && searchMethodFlag == 1)
                {
                    found = true;
                    break;
                }
                else if (temp->email == toBeSearched->email && searchMethodFlag == 2)
                {
                    found = true;
                    break;
                }
                else if (temp->owners_name == toBeSearched->owners_name && searchMethodFlag == 3)
                {
                    found = true;
                    break;
                }
                if (!temp->next)
                    break;
                else
                    temp = temp->next;
            }

            if (found)
            {
                if (!uniqueEntry)
                {
                    print(temp);
                    cout << "Is this you? \n";
                    if (validYesNoInput())
                        return temp;
                    else
                        found = false;
                }
                else
                    return temp;
            }
            if (temp->down == NULL)
                break;
            temp = temp->down;
            while (!found)
            {
                // depending on the flag values it will search accroding to that parameter
                if (temp->phone_num == toBeSearched->phone_num && searchMethodFlag == 1)
                {
                    found = true;
                    break;
                }
                else if (temp->email == toBeSearched->email && searchMethodFlag == 2)
                {
                    found = true;
                    break;
                }
                else if (temp->owners_name == toBeSearched->owners_name && searchMethodFlag == 3)
                {
                    found = true;
                    break;
                }
                if (!temp->prev)
                    break;
                else
                    temp = temp->prev;
            }

            if (found)
            {
                if (!uniqueEntry)
                {
                    print(temp);
                    cout << "Is this you? \n";
                    if (validYesNoInput())
                        return temp;
                    else
                        found = false;
                }
                else
                    return temp;
            }

            if (temp->down == NULL)
                break;
            temp = temp->down;
        }
        return NULL;
    }
    void printAll()
    {
        if (this->isEmpty())
        {
            cout << "No phone directory registered!\nPlease register your record in phone directory\n\n";
            return;
        }
        // print function travese whole linked list and print user details while traversing
        cout << "-------------------------\n";
        cout << "- - -PHONE NUMBERS- - - -\n";
        cout << "-------------------------\n";
        Node *printHead = head;

        while (true)
        {
            while (printHead->next != NULL)
            {
                cout << printHead->phone_num << endl;
                cout << "-------------------------\n";
                printHead = printHead->next;
            }
            cout << printHead->phone_num << endl;
            cout << "-------------------------\n";
            // checking if printHead->down is NULL or not?
            if (printHead->down == NULL)
                break;
            printHead = printHead->down;
            while (printHead->prev != NULL)
            {
                cout << printHead->phone_num << endl;
                cout << "-------------------------\n";
                printHead = printHead->prev;
            }
            cout << printHead->phone_num << endl;
            cout << "-------------------------\n";
            // checking if printHead->down is NULL or not?
            if (printHead->down == NULL)
                break;
            printHead = printHead->down;
        }
    }
    void userInput(Node *&_node)
    {
        cout << "Please enter your name      : ";
        getline(cin, _node->owners_name);
        cout << "Please enter your Phone no. : ";
        validIntInput(_node->phone_num);
        cout << "Do you have email ?\n";
        if (validYesNoInput())
            validEmailInput(_node);
        cin.ignore();
        cout << "Pleas enter your address    : ";
        getline(cin, _node->address);
    }

    void validEmailInput(Node *&_node)
    {
        // a funciton to only accept valid email like "example@email.com"
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        bool validEmail = false;
        cout << "Pleas enter your email      : ";
        getline(cin, _node->email);
        do
        {
            // count variable store the no. of @ in email
            int count = 0;
            string com = ".com";
            bool dotCom = true;
            int i;
            for (i = 0; i < _node->email.length(); i++)
            {
                if (_node->email[i] == '@')
                    count++;

                if (_node->email[_node->email.length() - i - 1] != com[com.length() - i - 1] && i < 4)
                {
                    // checking if the email ends with ".com" or not
                    dotCom = false;
                    break;
                }
            }

            // while loop terminates only when email has one and only one "@" symbol
            // and ".com" at end
            if (!dotCom)
                cout << "\nYour email should be like example @email.com\n";
            else if (count == 1)
            {
                validEmail = true;
                continue;
            }
            else if (count > 1)
                cout << "Your email must contain only one @ symbol\n";
            else
                cout << "Your email must contain one @ symbol\n";

            cout << "Pleas enter your email      : ";
            getline(cin, _node->email);

        } while (!validEmail);
    }
};
