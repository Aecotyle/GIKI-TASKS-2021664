#include <iostream>
using namespace std;
char error = '\0';
class CMystring
{
    int size;
    char *myString;

public:
    CMystring();
    CMystring(const char *);
    CMystring(int);
    CMystring(const CMystring &);

    friend ostream &operator<<(ostream &, const CMystring &);
    friend istream &operator>>(istream &, CMystring &);

    int getSize() { return this->size; }
    int length();
    CMystring operator+(CMystring);
    bool operator==(CMystring);
    CMystring &operator+=(CMystring);
    bool operator!=(CMystring);
    CMystring operator=(const CMystring &);
    char &operator[](int);
    CMystring operator()(int, int);

    bool operator>(const CMystring &);
    bool operator<(const CMystring &);
    CMystring operator<<(int);
    CMystring operator>>(int);

    ~CMystring();
};
// Copy constructor
CMystring::CMystring(const CMystring &obj)
{
    this->size = obj.size;
    myString = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        myString[i] = obj.myString[i];
    }
    myString[size] = '\0';
}
// Construct accepting size of string as parameter
CMystring::CMystring(int sz) : size(sz)
{
    if (sz > 0)
    {
        myString = new char[sz + 1];
        for (int i = 0; i < sz; i++)
            myString[i] = ' ';
        myString[sz] = '\0';
    }
    else
        cout << "Invalid size\nPlease enter size in positive integer" << endl;
}
// Default constructor(with not parameters)
// size is set to 50bytes by default as per written in task
CMystring::CMystring() : size(50)
{
    myString = new char[size + 1];
    for (int i = 0; i < 50; i++)
        myString[i] = ' ';
    myString[size] = '\0';
}
// Constructor accepting char pointer as parameter
// and copying char of paramerer into mystring
CMystring::CMystring(const char *_str)
{
    if (!_str)
    {
        myString = new char[1];
        myString[0] = '\0';
        size = 0;
    }
    else
    {
        int i = 0;
        while (_str[i])
        {
            i++;
        }
        size = i;
        myString = new char[i + 1];
        for (i = 0; _str[i]; i++)
            myString[i] = _str[i];
        myString[i] = '\0';
    }
}
// Destructor
CMystring::~CMystring()
{
    delete[] myString;
    myString = NULL;
}
// Fucntion to determince the lenght of string
int CMystring::length()
{
    int i = 0;
    while (this->myString[i] != '\0')
    {
        i++;
    }
    return i;
}
// overlaoded stream insertion operator (cout)
ostream &operator<<(ostream &out, const CMystring &obj)
{
    out << obj.myString;
    return out;
}
// overlaoded stream extraction operator(cin)
istream &operator>>(istream &in, CMystring &obj)
{
    in >> obj.myString;
    return in;
}
// overloaded operator to get/set character at particular operator
char &CMystring::operator[](int index)
{
    int sz = this->length();
    if (index >= sz || index < 0)
    {
        cout << "ERROR! you cannot access " << index << " index out of string length" << endl;
        // returning char '\0' declared in global scope
        // upon inpu tof invalid index
        return ::error;
    }
    else
        return this->myString[index];
}
// overloaded less than operator(<) that compares
// sum of acii value of each character
bool CMystring::operator<(const CMystring &obj)
{
    int count1 = 0, count2 = 0, i = 0;
    for (i = 0; this->myString[i]; i++)
    {
        count1 += int(myString[i]);
    }
    for (i = 0; obj.myString[i]; i++)
    {
        count2 += int(obj.myString[i]);
    }
    if (count1 < count2)
        return true;
    else
        return false;
}
// overloaded greater than operator(>) that compares
// sum of acii value of each character
bool CMystring::operator>(const CMystring &obj)
{
    int count1 = 0, count2 = 0, i = 0;
    for (i = 0; this->myString[i]; i++)
    {
        count1 += int(this->myString[i]);
    }
    for (i = 0; obj.myString[i]; i++)
    {
        count2 += int(obj.myString[i]);
    }
    if (count1 > count2)
        return true;
    else
        return false;
}
// oveloaded left shift operator
CMystring CMystring::operator<<(int shift)
{
    CMystring temp(shift);
    int newSz = this->length() - shift;
    char *newStr = new char[newSz + 1];
    int i;
    for (i = 0; i < shift; i++)
        temp.myString[i] = this->myString[i];
    for (i = 0; i < newSz; i++)
        newStr[i] = this->myString[shift + i];
    newStr[newSz] = '\0';

    delete[] myString;
    myString = newStr;
    newStr = NULL;

    return temp;
}
// oveloaded right shift operator
CMystring CMystring::operator>>(int shift)
{
    CMystring temp(shift);
    int len = this->length();
    char *newStr = new char[len - shift + 1];
    int i;
    for (i = 0; i < shift; i++)
        temp.myString[i] = this->myString[len - 1 - i];
    for (i = 0; i < len - shift; i++)
        newStr[i] = this->myString[i];
    newStr[len - shift] = '\0';

    delete[] myString;
    myString = newStr;
    newStr = NULL;

    return temp;
}
// Overloaded addition operator(+)
CMystring CMystring::operator+(CMystring obj)
{
    int i = this->length() + obj.length();
    CMystring temp(i);
    for (i = 0; this->myString[i] != '\0'; i++)
        temp.myString[i] = this->myString[i];
    for (int j = 0; obj.myString[j] != '\0'; j++)
        temp.myString[i++] = obj.myString[j];
    return temp;
}
// Overlaoded equality operator(==)
bool CMystring::operator==(CMystring obj)
{

    if (this->length() != obj.length())
        return false;
    for (int i = 0; myString[i]; i++)
    {
        if (myString[i] != obj.myString[i])
            return false;
    }
    return true;
}
// Overloaded not-equal-to operator
bool CMystring::operator!=(CMystring obj)
{

    if (this->length() != obj.length())
        return true;
    for (int i = 0; myString[i]; i++)
    {
        if (myString[i] != obj.myString[i])
            return true;
    }
    return false;
}
// Overloaded assignment operator
CMystring CMystring::operator=(const CMystring &obj)
{

    CMystring copyOfObj(obj);
    delete[] myString;
    this->myString = copyOfObj.myString;
    this->size = copyOfObj.size;
    copyOfObj.myString = NULL;

    return *this;
}
// Overloaded concatenation operator(+=)
CMystring &CMystring::operator+=(CMystring obj)
{
    int thisLen = this->length();
    int objLen = obj.length();
    this->size = thisLen + objLen;
    char *newStr = new char[thisLen + objLen + 1];
    for (int i = 0; i < thisLen; i++)
        newStr[i] = this->myString[i];

    for (int i = 0; i < objLen; i++)
        newStr[thisLen + i] = obj.myString[i];

    newStr[thisLen + objLen] = '\0';
    delete[] myString;
    myString = newStr;
    newStr = NULL;

    return *this;
}
// Overloaded substring operator that return CMystring
// of characters in between startingIndex and endingIndex
CMystring CMystring::operator()(int startingIndex, int endingIndex)
{
    if (startingIndex > endingIndex || startingIndex < 0 || endingIndex < 0)
    {
        CMystring err(0);
        cout << "Invalid indexing!\nIndex should be positive" << endl;
        return err;
    }
    else
    {
        CMystring temp(endingIndex - startingIndex + 1);

        for (int i = 0; i <= (endingIndex - startingIndex); i++)
        {
            temp.myString[i] = myString[startingIndex + i];
        }
        return temp;
    }
}