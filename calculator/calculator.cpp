#include <iostream>
using namespace std;
int main()
{

    int num1, num2;
    char operation;
    int loop;
    loop = 1;
    while (loop == 1)
    {
        /* code */

        cout << "enter num1" << endl;
        cin >> num1;
        cout << "enter num2" << endl;
        cin >> num2;
        cout << "enter operation:" << endl;
        cin >> operation;
        if (operation == '+')
        {
            cout << num1 + num2;
        }
        else if (operation == '-')
        {
            cout << num1 - num2;
        }
        else if (operation == '*')
        {
            cout << num1 * num2;
        }
        else if (operation == '/')
        {
            cout << num1 / num2;
        }
        else if (operation == '%')
        {
            cout << num1 % num2;
        }
        else
        {
            cout << "not valid";
        }
        cout << endl
             << "Do you want to exist or continue?" << endl;
        cout << "1.continue" << endl
             << "2. exit" << endl;
        cin >> loop;
    }
}