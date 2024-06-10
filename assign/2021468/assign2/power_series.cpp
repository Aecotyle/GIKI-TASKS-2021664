#include <iostream>
using namespace std;
int main()
{

    float temp_x,
        n, sum = 0, i = 1, factorial = 1, power = 1, x = 1;
    cout << "enter x" << endl;
    cin >> temp_x;
    cout << "enter no. terms" << endl;
    cin >> n;

    while (i <= n)
    {
        x = x * temp_x;

        for (int j = 1; j <= i; j++)
        {
            factorial = factorial * j;
        }
        cout << "x :" << x << endl;

        sum = sum + (x / factorial);
        i++;
        power++;
    }
    cout << "sum is : " << sum;

    return 0;
}