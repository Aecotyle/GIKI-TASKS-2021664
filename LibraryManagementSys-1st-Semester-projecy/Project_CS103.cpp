#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
//#include <cstring>
using namespace std;

// Prototypes of all functions used throught the programme
vector<string> stringStreamFunction(string line);
bool checkRecordLength(string, int);
int searchFromData(vector<string>, string, int searchlimit = 2);
void deleteStudent(vector<string> &, vector<string> &);
void loadData(vector<string> &, string);
void addNewUser(vector<string> &);
void fileUpdate(vector<string> &);
void DisplayData(vector<string>);
void displaySearchResult(vector<string>);
void loanBook(vector<string> &, vector<string> &);
void bookUpdate(vector<string> &);
void recordUpdate(vector<string> &, int, string, char c = '+');
void bookReturn(vector<string> &, vector<string> &, string, string);
bool bookInOutCheck(vector<string>, int);
void dataSort(vector<string> &);
string lowerCase(string);
void bookReturnFromDeleted(vector<string> &libraryData, vector<string> &bookData, string userRecord);
void Menu();
void regExceptions(string &);

int main()
{

    vector<string> libraryData;
    vector<string> bookData;

    loadData(libraryData, "libraryDatabase.csv");
    loadData(bookData, "bookDatabase.csv");
    dataSort(libraryData);

    int foundIndex;
    char choice = '0';
    string pressAnyKey;

    while (true)
    {
        Menu();
        cout << "Please select your option" << endl
             << endl;
        cin.get(choice);
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice)
        {
        case '1':

            DisplayData(libraryData);
            break;
        case '2':

            DisplayData(bookData);
            break;
        case '3':

            loanBook(bookData, libraryData);
            break;
        case '4':

            bookReturn(libraryData, bookData, "#", "#");
            break;
        case '5':

            displaySearchResult(libraryData);
            break;
        case '6':

            addNewUser(libraryData);
            break;
        case '7':

            deleteStudent(libraryData, bookData);
            break;
        case '0':
            break;

        default:
            cout << "Please select valid option from range 0-7" << endl;
            cout << "Thank You!" << endl;
            break;
        }
        if (choice == '0')
            break;
        cout << "Press any key to Continue..." << endl
             << endl;
        cin.ignore();
        cin >> pressAnyKey;
        cin.ignore();
    }

    return 0;
}

void loadData(vector<string> &dataVector, string fileName)
{
    // function to load all the contents of file in the provided vector
    ifstream myfile;
    myfile.open(fileName);
    if (myfile.is_open())
    {
        cout << "open" << endl;
        string s;
        while (getline(myfile, s) && s.length() != 0)
        {
            dataVector.push_back(s);
        }

        myfile.close();
    }
}

void addNewUser(vector<string> &libraryData)
{

    if (libraryData.size() <= 10)
    {
        string userString, tempStr, temp;
        cin.ignore();
        regExceptions(tempStr);
        while (1)
        {
            if (searchFromData(libraryData, tempStr) != -1)
            {
                cout << "User is already registered" << endl;
                regExceptions(tempStr);
            }
            else
                break;
        }

        userString = tempStr;

        cout << "Enter your Name : ";
        getline(cin, tempStr);
        // concatenating the Reg no. and student name
        userString = userString + ',' + tempStr;

        // updating library vector and then libraryDatabase file
        libraryData.push_back(userString);
        fileUpdate(libraryData);
    }

    else
        cout << "Only 10 Students at a time in Library are allowed" << endl;
}

void DisplayData(vector<string> libraryData)
{
    // fucntion to display all the contents of library Database
    cout << " Reg.no "
         << "    Name "
         << "    Outstanding Books" << endl;
    for (int i = 0; i < libraryData.size(); i++)
    {
        vector<string> word;
        string line, temp;
        line = libraryData[i];
        stringstream s_stream(line);
        while (getline(s_stream, temp, ','))
        {
            word.push_back(temp);
        }
        cout << "_____________________________________" << endl;
        cout << endl;
        for (int i = 0; i < word.size(); i++)
        {
            cout << "| " << word[i];
        }
        cout << endl;
    }
}
void deleteStudent(vector<string> &libraryData, vector<string> &bookData)
{
    string identifier;
    cout << "Please enter the Name or Reg no. \nyou want to delete form library Database\n"
         << endl;
    cin.ignore();
    getline(cin, identifier);
    int deletingIndex = searchFromData(libraryData, identifier);
    // if search result found then excute the code below
    if (deletingIndex != -1)
    {
        // deleting the record from vector at a particular index found above
        bookReturnFromDeleted(libraryData, bookData, libraryData[deletingIndex]);
        libraryData.erase(libraryData.begin() + (deletingIndex));
        fileUpdate(libraryData);
        cout << "User " << identifier << " data deleted successfully" << endl;
    }
    else
        cout << "not found" << endl;
}
void fileUpdate(vector<string> &libraryData)
{

    // creating a new file to store updated data present in vector
    fstream myfile;
    myfile.open("libraryDatabaseUpdated.csv", ios::out);
    if (myfile.is_open())
    {
        for (int i = 0; i < libraryData.size(); i++)
        {
            myfile << libraryData[i] << endl;
        }
        myfile.close();
    }
    // Removing the old/outdated file and renaming new file with old file name
    remove("libraryDatabase.csv");
    rename("libraryDatabaseUpdated.csv", "libraryDatabase.csv");
}

int searchFromData(vector<string> searchVector, string identifier, int searchLimit)
{
    identifier = lowerCase(identifier);
    int foundIndex = 0;
    bool found = false;
    for (int i = 0; i < searchVector.size(); i++)
    {
        // passing searched record(string) to stringStreamFunction
        vector<string> word = stringStreamFunction(searchVector[i]);

        // Loop to match the search input and output the index at which record is found
        for (int j = 0; j < searchLimit && j < word.size(); j++)
        {
            string s = lowerCase(word[j]);
            if (identifier == s)
            {
                foundIndex = i;
                found = true;
                break;
            }
        }
    }
    if (found)
    {
        // cout << "Result Found!" << endl;
        return foundIndex;
    }
    else
    {
        return -1;
    }
}

void displaySearchResult(vector<string> dataVect)
{
    string search;
    cout << "Please enter the Name or Regn no. of User" << endl;
    cin.ignore();
    getline(cin, search);

    // fucntion to display search result if found
    int searchIndex = searchFromData(dataVect, search);
    if (searchIndex >= 0)
    {

        vector<string> studentData;
        string line = dataVect[searchIndex];
        studentData = stringStreamFunction(line);
        cout << "Reg No"
             << "   "
             << "Name"
             << "  "
             << " "
             << "Books" << endl;
        cout << "________________________" << endl;
        for (int i = 0; i < studentData.size(); i++)
        {
            cout << "| " << studentData[i];
        }
        cout << endl
             << "________________________" << endl;
    }
    else
        cout << "No matching results found!" << endl;
}
vector<string> stringStreamFunction(string line)
{
    // fucntion to breaking the string separated by comma(,)and passing value to a vector
    // string: value1,value2,value3 into a vector<string> v={value1,value2,value3}
    string temp;
    stringstream s_stream(line);
    vector<string> word;
    while (getline(s_stream, temp, ','))
    {
        word.push_back(temp);
    }
    return word;
}

void loanBook(vector<string> &bookData, vector<string> &libraryData)
{
    string reg;
    int foundIndex;
    cout << "Your Reg no. in order to loan a book" << endl;
    cin.ignore();
    regExceptions(reg);

    // searching for reg no. in database the processing it futher if it exists
    foundIndex = searchFromData(libraryData, reg);
    if (foundIndex >= 0)
    {
        string bookName;
        // searching for book in bookDatabase whether it exist or not
        cout << "Enter the name of book you want" << endl;
        getline(cin, bookName);
        int bookFoundIndex = searchFromData(bookData, bookName);
        if (bookFoundIndex >= 0)
        {
            if (bookInOutCheck(bookData, bookFoundIndex))
            { // checking if user has used it limit to loan books or not
                if (checkRecordLength(libraryData[foundIndex], 4))
                {

                    recordUpdate(libraryData, foundIndex, bookName);
                    recordUpdate(bookData, bookFoundIndex, "Borrowed", '-');
                    fileUpdate(libraryData);
                    bookUpdate(bookData);
                    cout << "You have loaned a book successfully" << endl;
                }
                else
                    cout << "Student had already loaned 3 books" << endl;
            }

            else
                cout << "Book is already loaned by another student" << endl;
        }
        else
        {
            cout << "No Book with such name is in library!" << endl;
        }
    }
    else
        cout << "No User with such Reg no. is registered!" << endl;
}

void bookUpdate(vector<string> &bookData)
{
    // creating a new file to store updated data present in vector
    fstream myfile;
    myfile.open("bookDatabaseUpdated.csv", ios::out);
    if (myfile.is_open())
    {
        for (int i = 0; i < bookData.size(); i++)
        {
            myfile << bookData[i] << endl;
        }
        myfile.close();
    }
    // Removing the old/outdated file and renaming new file with old file name
    remove("bookDatabase.csv");
    rename("bookDatabaseUpdated.csv", "bookDatabase.csv");
}
void recordUpdate(vector<string> &recordVect, int index, string dataToAdd, char c)
{ // fucntion to that input a vector of database and separates the element of record(at particular index)
    // in new vetor and add or replace status/value at that particular index
    //  Example: bookname,in to bookname,out
    vector<string> userDataVect;
    string tempStr;
    userDataVect = stringStreamFunction(recordVect[index]);
    if (c == '+')
    {
        userDataVect.push_back(dataToAdd);
    }
    else
    {
        userDataVect[userDataVect.size() - 1] = dataToAdd;
    }
    for (int i = 0; i < userDataVect.size(); i++)
    {
        tempStr += userDataVect[i];
        if (i < userDataVect.size() - 1)
            tempStr += ',';
    }
    recordVect[index] = tempStr;
}

bool checkRecordLength(string record, int limit)
{ // function to check lenght of record in order to check whether
    // the student has used maximum no. of books that can be loaned or not.
    vector<string> recordVect;
    recordVect = stringStreamFunction(record);
    if (recordVect.size() <= limit)
        return true;
    else
        return false;
}

void bookReturn(vector<string> &libraryData, vector<string> &bookData, string bookName, string mode)
{
    vector<string> recordVect;
    int foundIndex;
    string tempStr;
    cin.ignore();
    if (mode != "already")
    {
        while (1)
        {
            cout << "Please enter the name of book you want to return" << endl;
            getline(cin, bookName);

            int bookFoundIndex = searchFromData(bookData, bookName);
            if (bookInOutCheck(bookData, bookFoundIndex))
            {
                cout << bookName << " is already in present in library" << endl;
            }
            else
                break;
        }
    }

    // passing libraryData to search fucntion in order to find the book registered against a student
    foundIndex = searchFromData(libraryData, bookName, 4);
    recordVect = stringStreamFunction(libraryData[foundIndex]);

    // running a for loop to find the exact location of book in record and deleting it from there
    for (int i = 0; i < recordVect.size(); i++)
    {
        if (bookName == recordVect[i])
        {
            recordVect.erase(recordVect.begin() + i);
            break;
        }
    }
    // running loop to concatinate the updated values of record into single string
    for (int i = 0; i < recordVect.size(); i++)
    {
        tempStr += recordVect[i];
        if (i < recordVect.size() - 1)
            tempStr += ',';
    }

    // To add the book back to library we search for location of book in library and making its status available
    int bookIndex = searchFromData(bookData, bookName);
    recordUpdate(bookData, bookIndex, "Available", '-');
    bookUpdate(bookData);

    // updating the database files of library and books
    libraryData[foundIndex] = tempStr;
    fileUpdate(libraryData);
}

bool bookInOutCheck(vector<string> bookData, int bookFoundIndex)
{ // fucntion to check whether a book is in use of any student or not?
    vector<string> bookVect;
    // making a vector to store all the values of a recorc in ti.
    bookVect = stringStreamFunction(bookData[bookFoundIndex]);
    if (bookVect[1] == "Available")
        return true;
    else
        return false;
}

void Menu()
{
    system("clear");
    cout << "________________________________________________________________\n";
    cout << "\n             ---LIBRARY MANAGEMENT SYSTEM---\n\n\n";
    cout << "________________________________________________________________";
    cout << "\n\n1. Display list all existing user in library\n";
    cout << "________________________________________________________________";
    cout << "\n\n2. Display list all existing books and their status\n";
    cout << "________________________________________________________________";
    cout << "\n\n3. Loan a book\n";
    cout << "________________________________________________________________";
    cout << "\n\n4. Return book\n";
    cout << "________________________________________________________________";
    cout << "\n\n5. Search user and show books outstanding against him\n";
    cout << "________________________________________________________________";
    cout << "\n\n6. Add a user to library\n";
    cout << "________________________________________________________________";
    cout << "\n\n7. Delete student record from library database\n";
    cout << "________________________________________________________________";
    cout << "\n\n.. Press 0 to Exit\n";
    cout << "________________________________________________________________";
    cout << endl
         << endl;
}

void dataSort(vector<string> &libraryData)
{
    vector<string> list;
    vector<int> intList;
    for (int i = 0; i < libraryData.size(); i++)

    {
        string row = libraryData[i];
        string regNo;
        stringstream s_stream(row);
        getline(s_stream, regNo, ',');
        list.push_back(regNo);
    }

    for (int i = 0; i < list.size(); i++)
    {
        string temp_str = list[i];
        int temp_int = stoi(temp_str);
        intList.push_back(temp_int);
    }
    for (int i = 0; i < intList.size(); i++)
    {

        for (int j = 0; j < intList.size() - i - 1; j++)
        {
            if (intList[j] > intList[j + 1])
            {
                swap(libraryData[j], libraryData[j + 1]);
                swap(intList[j], intList[j + 1]);
            }
        }
    }
}

string lowerCase(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
void bookReturnFromDeleted(vector<string> &libraryData, vector<string> &bookData, string userRecord)
{
    vector<string> temp = stringStreamFunction(userRecord);
    for (int i = 2; i < temp.size(); i++)
    {
        int foundIndex = searchFromData(libraryData, temp[i], 4);
        if (foundIndex != -1)
        {
            bookReturn(libraryData, bookData, temp[i], "already");
        }
    }
}

void regExceptions(string &tempStr)
{
    bool loopRun = true;
    while (loopRun)
    { // Exception to check that user don't enter any invalid value
        cout << "Enter your reg no. : ";
        getline(cin, tempStr);
        // check whether the student is already registered or not

        if (tempStr.length() != 7 || tempStr == "0000000")
        { // check the valid lenght of reg and 0000000
            cout << "Registration number must be a 7-digit number" << endl;
            if (tempStr == "0000000")
                cout << "Registration number cannot be 000000" << endl;
        }
        else
        { // comparing ascii values character by character to only allow digit from 0-9
            for (int i = 0; i < tempStr.length(); i++)
            { // checking ascii value of digits of reg
                char c_test = tempStr[i];
                int in = int(c_test);

                if (in >= 48 && in <= 57)
                    if (i != tempStr.length() - 1)
                        continue;
                    else
                        loopRun = false;

                else if (in == 45)
                {
                    cout << "Registration number can only be non-negative digits" << endl;
                    break;
                }
                else
                {
                    cout << "Please enter valid reg no." << endl;
                    break;
                }
            }
        }
        ////chech achi value n len of reg by % func and -ve
    }
}
