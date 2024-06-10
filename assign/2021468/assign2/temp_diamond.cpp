#include <iostream>
using namespace std;

int main()
{
    int num, i;
    int even = 0;
    int odd = 0;
    int prime = 0;
    int current = -4;
    int previous = -2;
    int discard = -6;
    do
    {
        cout << "Please enter a positive number:";
        cin >> num;
        discard = previous;
        previous = current;
        for (i = 2; i <= num; i++)
        {
            if (num % i != 0)
            {
                cout << "Number is prime.\n";
                prime = prime + 1;
            }
            break;
        }
        if (num % 2 == 0 && num != 2)
        {
            cout << "Number is even.\n";
            even = even + 1;
        }
        else if (num == 2)
        {
            cout << "Number is even and prime.\n";
            prime = prime + 1;
            odd = odd + 1;
        }
        else if (num % 3 == 0)
        {
            odd = odd + 1;
            cout << "Number is odd.\n";
        }
        current = num;
    } while (num != previous && num != discard);
    cout << "Even=" << even << endl
         << "Odd=" << odd << endl

         << "Prime=" << prime;
    return 0;
}