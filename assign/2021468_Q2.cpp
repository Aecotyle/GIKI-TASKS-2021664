#include <iostream>
using namespace std;
int main()
{
    int n, space;
    cout << "Please enter a number: ";
    cin >> n;
    space = n - 1;
    int z = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j;
            z = j - 1;
        }
        for (int j = 0; j < i - 1; j++)
        {
            cout << z;
            z--;
        }
        space--;
        cout << endl;
    }
    space = 1;
    n = n - 1;
    int k = n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - (i - 1); j++)
        {
            cout << j;
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << k - j;
        }
        k--;
        space++;
        cout << endl;
    }
    return 0;
}
