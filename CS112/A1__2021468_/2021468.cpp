#include <iostream>
#include <string>
#include <limits.h>
#include <iomanip>
#include <vector>
using namespace std;
void Menu();
int validInput();
// function to accept input of from zero to 4th index
int indexvalidInput()
{
    int x;
    x = validInput();
    while (x >= 5)
    {
        cout << "\nInvalid index. Please enter index between 0 to 4" << endl;
        x = validInput();
    }
    return x;
}
// fucntion to reject the zero input of ID
int zeroExp()
{
    int x;
    x = validInput();
    while (x == 0)
    {
        cout << "ID cannot be zero";
        x = validInput();
    }
    return x;
}

struct Student
{
    int ID;
    int rollNo;
    string stdName;

    void print()
    {
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "___________________________________\n";
        cout << "ID " << setw(15) << "Rollno " << setw(15) << "Name " << endl;
        cout << ID << setw(15) << rollNo << setw(15) << stdName << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    }
};
int searchStd(Student Arr[], int search);

struct studentList
{
    int count = 0;
    Student stdArr[5];

    void printAll()
    {
        if (count == 0)
            cout << "There is no student registered yet " << endl;
        else
        {

            for (int i = 0; i < 5; i++)
            {
                if (stdArr[i].ID != 0)
                    stdArr[i].print();
            }
        }
    }

    void deleteStd()
    {
        int id;
        cout << "Please enter the ID of stident you want to delete" << endl;
        cin >> id;
        int x = searchStd(stdArr, id);
        if (x == -1 || count == 0)
            cout << "No student is registered with " << id << " this ID" << endl;
        else
        {

            stdArr[x].ID = 0;
            cout << "Data of student deleted successfully" << endl;
            count--;
        }
    }

    void addStd()
    {
        if (count < 5)
        {

            int index, x;
            cout << "Please enter the index(0-4) you want to add student" << endl;
            index = indexvalidInput();
            count++;

            cout << "Student ID: ";
            x = zeroExp();
            if (searchStd(stdArr, x) == -1)
            {
                stdArr[index].ID = x;
                cout << "Please enter student Roll no. : ";
                stdArr[index].rollNo = validInput();
                cout << "Please enter student name: ";
                cin.ignore();
                getline(cin, stdArr[index].stdName);
            }
            else
                cout << "Student with ID: " << x << " is already registered" << endl;
        }
        else
            cout << "Only 5 students can be registered" << endl;
    }
} s;
struct Book
{
    string bookName;
    string author;
    int ID;
    string ISBN;
    int price;
    int pages;

    void print()
    {
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "___________________________________________\n";
        cout << "ID" << setw(15) << "Author" << setw(15) << "ISBN" << setw(15) << "Pages" << setw(15) << "Price" << setw(15) << "Book Name" << endl;
        cout << ID << setw(15) << author << setw(15) << ISBN << setw(15) << pages << setw(15) << price << setw(15) << bookName << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    }
};

int searchBook(Book Arr[], int search);
struct bookList
{
    int count = 0;
    Book bookArr[5];

    void printAll()
    {
        if (count == 0)
            cout << "There is no book registered yet " << endl;
        else
        {

            for (int i = 0; i < 5; i++)
            {
                if (bookArr[i].ID != 0)
                    bookArr[i].print();
            }
        }
    }

    void deleteAll()
    {
        for (int i = 0; i < 5; i++)
        {
            bookArr[i].ID = 0;
        }
        cout << "Data of all books deleted sucessfully" << endl;
        count = 0;
    }

    void addNewBook()

    {
        int x;
        int index;
        if (count < 5)
        {
            cout << "Enter the index(0-4) you want to save book" << endl;
            index = indexvalidInput();
            cout << endl
                 << "Please enter the following details" << endl;
            cout << "Book ID: ";
            x = zeroExp();
            if (searchBook(bookArr, x) == -1)
            {

                bookArr[index].ID = x;
                cout << "Price: ";
                bookArr[index].price = validInput();
                cout << "Pages: ";
                bookArr[index].pages = validInput();
                cin.ignore();
                cout << "Book Name: ";
                getline(cin, bookArr[index].bookName);
                cout << "Author: ";
                getline(cin, bookArr[index].author);
                cout << "ISBN: ";
                getline(cin, bookArr[index].ISBN);
                count++;
            }
            else
                cout << "Book with ID: " << x << " is already registered" << endl;

            cout << endl
                 << count << endl;
        }
        else
            cout << "You can register only 5 books at a time" << endl;
    }
    // funtion to (bubblesort) arary according to parameter order
    void sort(string order)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (order == "Ascending")
                {

                    if (bookArr[j].ID > bookArr[j + 1].ID)
                        swap(bookArr[j], bookArr[j + 1]);
                }
                else
                {

                    if (bookArr[j].ID < bookArr[j + 1].ID)
                        swap(bookArr[j], bookArr[j + 1]);
                }
            }
        }
    }
} b;

int main()

{

    int option;
    int bookID;
    bool loop = true;
    do
    {
        system("clear");

        Menu();
        cout << endl;

        cout << "Option: ";
        option = validInput();
        cout << endl
             << endl;

        switch (option)
        {
        case 1:
            s.addStd();
            break;

        case 2:
            s.deleteStd();
            break;
        case 3:
            s.printAll();
            break;
        case 4:

            b.addNewBook();
            break;
        case 5:
            b.deleteAll();
            break;
        case 6:
        {
            cout << "Please enter the name of book you want to search" << endl;

            cin >> bookID;
            int x = searchBook(b.bookArr, bookID);
            if (x == -1)
                cout << "No book with this ID exits.\nPlease enter correct book ID" << endl;
            else
                b.bookArr[x].print();

            break;
        }

        case 7:
            b.printAll();
            break;
        case 8:
            b.sort("Ascending");
            b.printAll();
            break;
        case 9:
            b.sort("Dscending");
            b.printAll();
            break;
        case 10:
            loop = false;
            break;
        default:
            cout << "Please enter a valid option" << endl;
        }
        if (option != 10)
        {

            char check;
            cout << "Press any key then enter to continue" << endl;
            cin >> check;
        }

    } while (loop);
    return 0;
}

// fucntion to search book from array
int searchBook(Book Arr[], int search)
{
    int found;
    for (int i = 0; i < 5; i++)
    {
        if (search == Arr[i].ID && Arr[i].ID != 0)
        {

            found = i;
            break;
        }
        else
            found = -1;
    }

    return found;
}

// fucniton to search student form array
int searchStd(Student Arr[], int search)
{
    int found;
    for (int i = 0; i < 5; i++)
    {
        if (search == Arr[i].ID && Arr[i].ID != 0)
        {

            found = i;
            break;
        }
        else
            found = -1;
    }
    return found;
}
void Menu()
{
    cout << "___________________________________________\n";
    cout << "1. Add New Student.\n";
    cout << "___________________________________________\n";
    cout << "2. Delete Existing Student.\n";
    cout << "___________________________________________\n";
    cout << "3. Show all Students.\n";
    cout << "___________________________________________\n";
    cout << "4. Add New Book.\n";
    cout << "___________________________________________\n";
    cout << "5. Delete Existing Book.\n";
    cout << "___________________________________________\n";
    cout << "6. Show particular Book.\n";
    cout << "___________________________________________\n";
    cout << "7. Show all Books.\n";
    cout << "___________________________________________\n";
    cout << "8. Sort Books in Ascending order.\n";
    cout << "___________________________________________\n";
    cout << "9. Sort Books in Descending order.\n";
    cout << "___________________________________________\n";
    cout << "15. Exit.\n";
    cout << "___________________________________________\n";
}

// Fucntion to handle exceptions if you input char/string in int type input
int validInput()
{

    int x;
    cin >> setw(1) >> x;
    while (!cin.good() || x < 0)
    {

        cout << "please enter +ve integer value" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cin >> setw(1) >> x;
    }

    return x;
}