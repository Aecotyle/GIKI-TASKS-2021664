#ifndef HEADER_H
#define HEADER_H
#include "header.h"
#endif

// Utilily Functions
void validIntInput(int &input)
{
    // function to handle char input error to a int variable
    while (true)
    {
        try
        {
            cin >> input;
            // if the input stream is not good it throws exception
            if (!cin)
            {
                // clearing the bad input stream
                cin.clear();
                // ignore INT_MAX no. of characters upto \n
                cin.ignore(INT_MAX, '\n');
                throw 101;
            }
            // if the stream is good the loop simply breaks without any error
            else
                break;
        }
        catch (...)
        {
            cout << "Input must be of int type\n";
        }
    }
    cin.ignore();
}
bool validYesNoInput()
{
    // a fucntion to take yes or no input in form of y or n
    //  it keeps asking input until it Y or N is pressed
    char in;
    while (true)
    {

        cout << "If yes press [Y] else press [N]: ";
        cin >> in;
        if (in == 'Y' || in == 'y')
            return true;
        else if (in == 'N' || in == 'n')
            return false;
    }
}

void printMenu()
{
    cout << "\n------------------------------\n";
    cout << "Please select your option: \n";
    cout << "\n------------------------------\n";
    cout << "1.Add a record to directory\n";
    cout << "2.Delete a record from directory\n";
    cout << "3.Search a record from directory\n";
    cout << "4.Print all phone numbers in directory\n";
    cout << "5.Exit\n";
    cout << "------------------------------\n";
}