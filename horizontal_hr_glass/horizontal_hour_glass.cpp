#include <iostream>
using namespace std;
int main()

{
    int n, space;
    cout << "enter your number: ";
    cin >> n;

    space = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        space = space - 2;
        cout << endl;
    }
    int k = n - 1;
    space = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= k; j++)
        {
            cout << "*";
        }

        space = space + 2;
        k--;
        cout << endl;
    }
    return 0;
}