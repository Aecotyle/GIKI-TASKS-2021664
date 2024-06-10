#include <iostream>
#include <time.h>
using namespace std;
enum status
{
    WON,
    LOST,
    CONTINUE
};

int roll_func()
{
    int die_roll = rand() % 6 + 1;
    return die_roll;
}
int main()
{
    status p1_gamestatus, p2_gamestatus;
    int die_roll1 = 0, die_roll2 = 0, p1_score = 0, p2_score = 0, temp_sum1, temp_sum2;
    bool one_check;
    char YN_check, game_start;
    srand(time(0));
    cout << "\n----------GAME RULES----------" << endl;
    cout << "*IF ANY OF YOUR DIE ROLL IS 1 YOU LOOSE \n*PLAYER SCORING 50 FIRST WINS \n*YOU MAY PASS YOUR TURN TO OTHER PLAYER OR KEEP PLAYING\n*YOUR CURRENT SCORES ARE DISPLAYED ON EVERY TURN\n*TOTAL SCORE IS DISPLAYED AT THE END\n\n";
    cout << "PLAYER 1 TURN PRESS ANY KEY TO ROLL" << endl;
    cin >> game_start;
    while (p1_gamestatus != LOST && p2_gamestatus != LOST)
    {
        temp_sum1 = 0;
        if (p1_score >= 50 || p2_score >= 50)
        {
            p1_gamestatus = WON;
            p2_gamestatus = WON;
            break;
        }
        cout << "PRESS Y TO CONTINUE OR ANY KEY TO PASS TURN" << endl;
        die_roll1 = roll_func();
        die_roll2 = roll_func();
        temp_sum1 += die_roll1 + die_roll2;

        cout << "PLAYER 1 SCORE :" << temp_sum1 << endl;
        cin >> YN_check;
        system("clear");
        if (die_roll1 == 1 || die_roll2 == 1)
        {
            p1_score += temp_sum1;
            one_check = true;
            p1_gamestatus = LOST;

            break;
        }
        if (YN_check == 'Y' || YN_check == 'y')
        {
            p1_score += temp_sum1;
            continue;
        }
        else
        {
            cout << "Player 2 turn " << endl;
            cout << "Press any key to continue" << endl;
            cin >> game_start;
            while (p2_gamestatus != LOST)
            {
                temp_sum2 = 0;

                cout << "PRESS Y TO CONTINUE OR ANY KEY TO PASS TURN" << endl;
                die_roll1 = roll_func();
                die_roll2 = roll_func();
                temp_sum2 += die_roll2 + die_roll1;
                cout << " PLAYER 2 SCORE : " << temp_sum2 << endl;
                cin >> YN_check;
                system("clear");
                if (die_roll1 == 1 || die_roll2 == 1)
                {
                    one_check = true;
                    p2_score += temp_sum2;
                    p2_gamestatus = LOST;
                    break;
                }

                if (YN_check == 'Y' || YN_check == 'y')
                {
                    p2_score += temp_sum2;
                    continue;
                }
                else
                {
                    p2_score += temp_sum2;
                    break;
                }
            }
        }
    }
    if (p1_gamestatus == LOST && p2_gamestatus == LOST)
        cout << "MATCH DRAW" << endl;
    else if (p1_score >= 50 || p2_gamestatus == LOST)
    {
        cout << "PLAYER 1 WON" << endl;
    }
    else if (p2_score >= 50 || p1_gamestatus == LOST)
        cout << "PLAYERR 2 WON " << endl;
    (one_check == true) ? cout << "-----OTHER PLAYER LOST DUE TO 1-----" << endl : cout << "-----SCORE DEFEAT-----" << endl;
    cout << "PLAYER 1 TOTAL SCORE : " << p1_score << endl;
    cout << "PLAYER 2 TOTAL SCORE : " << p2_score << endl;

    return 0;
}