#include <iostream>
#include <string>
using namespace std;
int main()
{
    int input, n, temp_input;
    int prime = 0, even = 0, odd = 0;
    int loop_check = 1;

    while (loop_check < 3)
    {

        cout << "Please enter a number: ";
        cin >> input;
        if (temp_input == input)
            loop_check++;
        else
            loop_check = 1;

        switch (input)
        {

        case (1):
            cout << "1 is an odd number." << endl;
            odd++;
            break;
        default:
        {

            if (input % 2 == 0 || input == 0)
            {
                cout << input << " is an even number." << endl;

                even++;
                prime++;
            }
            else
            {
                for (int i = 2; i <= input; i++)
                {

                    if (input % i == 0 && i != input)
                    {
                        cout << input << " is an odd number ." << endl;
                        odd++;

                        break;
                    }
                    else if (input % i == 0 && i == input)
                    {
                        cout << input << " is a prime a number." << endl;
                        prime++;

                        break;
                    } //it obvious that every prime is odd also ,if we want to add
                    //prime to odd counter also, we will simply add odd++ right after prime++.
                }
            }
        }
        }
        temp_input = input;
    }
    cout << endl;
    cout << "Prime numbers: " << prime << endl;
    cout << "Odd numbers: " << odd << endl;
    cout << "Even numbers: " << even << endl;

    return 0;
}