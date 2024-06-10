#include <iostream>
using namespace std;

int power(int n, int p)
{
    if (p > 0)
    {
        return n * power(n, p - 1);
    }
    else
        return 1;
}

double fac(double n)
{
    if (n > 1)
    {
        return n * fac(n - 1);
    }
    else
        return 1;
}

double serCal(int n, int x)
{
    double sum = 0;
    for (double i = 2.0; i <= n; i += 2)
    {
        cout << i << endl;
        sum += (power((x + i), i) / fac(i));
    }
    return sum;
}

int main()
{
    int n, x;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of x: ";
    cin >> x;

    cout << serCal(n, x) << endl;

    return 0;
}