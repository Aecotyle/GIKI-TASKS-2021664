#include <iostream>
#include <string>
using namespace std;
int main()
{
    int input, n;
    int prime_list[100], even_list[100], odd_list[100];
    int prime_index = 0, even_index = 0, odd_index = 0;
    int check[] = {0, 0, 0};
    int check_index = 0;

    bool run = true;

    while (run)
    {

        cout
            << "Please enter a number: ";
        cin >> input;
        //system("clear");
        switch (input)
        {
            /*case (0):
            cout << "0 is an even number." << endl;
            even_list[even_index] = input;
        case (1):
            even_index++;
            odd_list[odd_index] = input;
            break;*/
            break;
            cout << "1 is an odd number." << endl;
            odd_index++;
        default:
        {

            if (input % 2 == 0 || input == 0)
            {
                cout << input << " is an even number." << endl;
                even_list[even_index] = input;
                even_index++;
            }
            else
            {
                for (int i = 2; i <= input; i++)
                {

                    if (input % i == 0 && i != input)
                    {
                        cout << input << " is an odd number ." << endl;
                        odd_list[odd_index] = input;
                        odd_index++;

                        break;
                    }
                    else if (input % i == 0 && i == input)
                    {
                        cout << input << " is a prime and number." << endl;
                        prime_list[prime_index] = input;
                        prime_index++;
                        odd_list[odd_index] = input;
                        odd_index++;
                        break;
                    }
                }
            }
        }
        }

        check[check_index] = input;
        if (check[0] == check[1] && check[1] == check[2] && check[0] == check[2])
            run = false;
        if (check_index < 3)
        {
            check_index++;
        }
        else
            check_index = 0;
    }

    cout << "Prime numbers: ";
    for (int x = 0; x < prime_index; x++)
    {
        if (prime_list[x] != prime_list[x + 1])
            cout << prime_list[x] << ",";
    }
    cout << endl
         << "Odd numbers: ";
    for (int x = 0; x < odd_index; x++)
    {
        if (odd_list[x] != odd_list[x + 1])
            cout << odd_list[x] << ",";
    }

    cout << endl
         << "Even numbers: ";
    for (int x = 0; x < even_index; x++)
    {
        if (even_list[x] != even_list[x + 1])
            cout << even_list[x] << ",";
    }

    return 0;
}