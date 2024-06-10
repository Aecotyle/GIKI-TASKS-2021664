#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
int main()
{
    int counter = 0, length = 0;
    char arr[20];
    char *ptr;
    ptr = arr;
    cout << "Enter string: ";
    cin.get(arr, 20);
    
    while (*ptr != '\0')
    {

        switch (*ptr)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            counter++;
            break;

        }
        ptr++;
        length++;
    }
    cout << "length" <<"  "<<length << endl;
    cout << "vowels" <<"  "<<counter << endl;
    cout << "consonants" <<"  "<<length - counter << endl;

    return 0;
}