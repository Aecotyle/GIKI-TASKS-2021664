#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter number: " << endl;
    cin >> n;
    int diff = 0;
    int value = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            value += diff;
            cout << value << " ";
            diff++;
        }
        cout << endl;
    }
    return 0;
}