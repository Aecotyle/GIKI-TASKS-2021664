#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n, guess, tries = 3;
    // guess = rand() % 100 + 1;
    guess = 40;
    do
    {
        cout << "Guess a number between 1 to 100:" << endl;
        cin >> n;
        if (n == guess)
        {
            cout << "You won";
        }
        else if (n > (guess / 2))
        {
            cout << " Too high" << endl;
            tries--;
            cout << "Tries left:" << tries << endl;
        }

        else if (n < guess / 2)
        {
            cout << "Too low" << endl;
            tries--;
            cout << "Tries left:" << tries << endl;
        }
    } while (n != guess && tries > 0);
    return 0;
}