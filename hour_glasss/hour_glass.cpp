#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "please enter your number: ";
    cin >> n;
    int k = 2 * n - 1;
    int space = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= k; j++)
        {
            cout << "*";
        }
        k--;
        k--;
        space++;

        cout << endl;
    }
    space = n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        space--;
        cout << endl;
    }

    return 0;
}