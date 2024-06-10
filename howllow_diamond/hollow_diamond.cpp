#include <iostream>
using namespace std;
int main()
{
    int n, space;
    cout << "enter a number: ";
    cin >> n;
    space = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        cout << "*";

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << " ";
        }
        if (i > 0)
            cout << "*";

        space--;
        cout << endl;
    }
    //n = n - 1;
    space = 2 * n - 5;
    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        if (i < n - 1)
            cout << "*";
        space = space - 2;
        cout << endl;
    }
    return 0;
}