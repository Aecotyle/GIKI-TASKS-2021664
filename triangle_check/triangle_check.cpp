#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "please enter sides a " << endl;
    cin >> a;
    cout << "please enter sides b " << endl;

    cin >> b;
    cout << "please enter sides c" << endl;

    cin >> c;

    cout << "it is a/an ";
    if (a == b && b == c && c == a)
    {
        cout << "Equilateral triangle";
    }

    else
    {
        if (a == b || b == c || c == a)
        {
            cout << "isoceles triangle";

            /* code */
        }
        else
        {
            cout << "scalene triangle"; /* code */
        }
    }
    return 0;
}