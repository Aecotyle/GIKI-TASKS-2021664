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
        //system("clear");
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
                        cout << input << " is a prime and number." << endl;
                        prime++;
                        odd++;
                        break;
                    }
                }
            }
        }
        }
        temp_input = input;
    }

    cout << "Prime and odd numbers: " << prime << endl;
    cout << "Odd numbers: " << odd << endl;
    cout << "Even numbers: " << even << endl;

    return 0;
}