#include <iostream>
using namespace std;
int main()
{
    int number, factorial = 1;
    cout << "enter your number :" << endl;
    cin >> number;

    for (int i = 1; i <= number; i++)
    {
        factorial = factorial * i;
        //cout << factorial;
    }

    cout << factorial;

    return 0;
}