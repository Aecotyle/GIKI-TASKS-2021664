#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool status;
//system("clear");
int counter = 0;
string new_passcode = "0", confirm_passcode = "0", em, pw, temp2;
char acc_check;
string email, passcode;
string temp;

string temp_email;
//int index = 1;ss
bool login()
{

    //string email, passcode, em, pw;
    ifstream read;
    read.open("credentials.txt", ios::in);
    if (read.is_open())
    {
        while (!read.eof())
        {
            getline(read, temp_email);
            //getline(read, pw);
            cout << temp_email << endl;
            //cout << pw << endl;
        }
        do
        {
            cout << "Please enter your email id" << endl;
            cin >> email;
            cout << "please enter your passcode" << endl;
            cin >> passcode;
            temp = email + passcode;

            if (temp_email == temp && /*pw == passcode &&*/ counter < 3)
            {
                cout << "login successful";
                return true;
            }
            else
            {
                counter++;
                cout << "Trials left :" << 3 - counter << endl;
            }

        } while (temp_email != temp /*&& pw != passcode)*/ && counter < 3);

        cout << "blocked";
        //return false;
    }
    else
        cout << "unable to open file";
    read.close();
}

int main()
{

    cout << "Login syetem" << endl;
    cout << "Do you already have acc ,press Y/N" << endl;
    cin >> acc_check;
    if (acc_check == 'N' || acc_check == 'n')
    {
        int passcode_loop = 0;
        do
        {

            cout << "Sign Up!" << endl;
            cout << "Enter your email" << endl;
            getline(cin >> ws, email);
            cin.ignore(1000, '\n');
            cout << "Enter your passcode" << endl;
            cin >> new_passcode;

            cout << "confirm your passcode" << endl;
            cin >> confirm_passcode;
            if (new_passcode == confirm_passcode)
            {
                passcode_loop = 1;

                ofstream file_2("credentials.txt", ios::out | ios::app);
                file_2 << email << new_passcode << "\n";
                file_2.close();
            }
            else
            {
                cout << "Passcode didn't match ,enter password again";
                system("clear");
            }

        } while (passcode_loop == 0);
    }
    else if (acc_check == 'Y' || acc_check == 'y')
    {
        login();
    }
    else
        cout << "invalid answer";

    return 0;
}
