#include <iostream>
using namespace std;
int main()
{
    int num1, num2, b, carry = 0, temp1, temp2, temp_sum, j = 0, binary_sum = 0, m = 1;
    cout << "Enter num1:  ";
    cin >> num1;
    cout << "Enter num2:  ";
    cin >> num2;
    cout << "enter base:  ";
    cin >> b;

    if (b == 2)
    {
        while (j < 8)
        {
            if (carry == 2)
                carry = 1;
            temp1 = num1 % 10, temp2 = num2 % 10;
            num1 = num1 / 10;
            num2 = num2 / 10;
            if (temp1 + temp2 + carry == 3)
            {
                carry = 1;
                temp_sum = 1;
            }
            else if (carry + temp1 + temp2 == 2)
            {
                carry = 1;
                temp_sum = 0;
            }
            else
            {
                temp_sum = carry + temp1 + temp2;
                carry = 0;
            }

            binary_sum += temp_sum * m;
            m *= 10;
            j++;
        }

        cout << binary_sum;
    }

    return 0;
}