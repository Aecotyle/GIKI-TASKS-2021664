#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int roll_dice();
int main()
{
    int sum, mypoint;
    enum status
    {
        WON,
        LOST,
        CONTINUE
    };
    status gamestatus;

    srand(time(0));
    sum = roll_dice();

    switch (sum)
    {
    case 7:
    case 11:
        gamestatus = WON;
        break;
    case 2:
    case 3:
    case 12:
        gamestatus = LOST;
        break;
    default:
        gamestatus = CONTINUE;
        mypoint = sum;
        cout << "Your points are : " << mypoint << endl;
        break;
    }
    while (gamestatus == CONTINUE)
    {
        sum = roll_dice();
        if (sum == mypoint)
        {
            gamestatus = WON;
            break;
        }
        else if (sum == 7)
        {
            gamestatus = LOST;
            break;
        }
    }

    if (gamestatus == WON)
        cout << "YOU WON" << endl;
    else
        cout << "******- YOU LOST -******" << endl;

    return 0;
}
int roll_dice()
{
    int die1, die2, worksum;
    die1 = (rand() % 6) + 1;
    die2 = (rand() % 6) + 1;
    worksum = die1 + die2;
    cout << "worksum = " << die1 << " + " << die2 << " = " << worksum << endl;
    return worksum;
}