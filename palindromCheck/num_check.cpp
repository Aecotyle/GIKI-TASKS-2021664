#include <iostream>
using namespace std;
int main()
{
    int num, tempNum, sum = 0, temp2,temp3;
    cout << "ENtER A NUMBER: ";
    cin >> num;
    tempNum = num;
    temp3=num;
    int z = 1;
    int len = 0;
    while (true)
    {
        if (tempNum == 0)
            break;
        tempNum /= 10;
        len++;
    }
    for (int j = 1; j < len; j++)
    {
        z *= 10;
    }
    for (int i = 0; i < len; i++, z /= 10)
    {
        if (num == 0)
            break;
        temp2 = num % 10;
        num /= 10;
        temp2 *= z;
        sum += temp2;
    }
    num=temp3;
    if (sum == num)
    
        cout << "The number " << num << " is a palindrome"<<endl;

    else
        cout << "The number " << num << " is not a palindrome"<<endl;
    return 0;
}
