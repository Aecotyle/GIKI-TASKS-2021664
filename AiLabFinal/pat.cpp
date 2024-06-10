#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int start = 0;
    int value = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            value += i;
        }
        else
            value++;

        for (int j = 0; j < i; j++)
        {

            if (i % 2 == 0)
                cout << value - j << " ";
            else
            {
                cout << value + j << " ";
                if (j == i - 1)
                    value += j;
            }
        }
        cout << endl;
        // start++;
    }
    return 0;
}
// 1
// 3  2
// 4  5  6
// 10 9  8  7
// 11 12 13 14 15