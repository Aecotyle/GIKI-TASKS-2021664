#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{

    int inst[12] = {
        1000, 1001, 2000, 3001, 2102, 2000, 3101, 2103, 2000, 3301, 2104, 4300};
    int accumulator = 0, word;
    int memory[100] = {0};
    int instruction, op, address;
    for (int i = 0; i < 12; i++)
    { // inputing instruction form hard coded array, we can also take input of instrucitons;
        // as cin>>instruction
        instruction = inst[i];

        // formula to extract operation code out of instruction
        op = instruction / 100;

        // formula to extract address/memory location out of instruction
        address = instruction % 100;

        // switch case for dealing with operation code
        switch (op)
        {
        case (10):
            cout << "ENTER A WORD:  ";
            cin >> word;
            memory[address] = word;
            break;
        case (11):
            cout << memory[address] << endl;
            break;
        case (20):
            accumulator = memory[address];
            break;
        case (21):
            memory[address] = accumulator;
            accumulator = 0;
            break;
        case (30):
            accumulator += memory[address];
            break;
        case (31):
            accumulator -= memory[address];
            break;
        case (32):
            accumulator /= memory[address];
            break;
        case (33):
            accumulator *= memory[address];
            break;
        case (43):
            accumulator = 0;
            break;
        default:

            cout << "Invalid Opcode" << endl;
        }

        // if cases for proper display of data/result;
        if (i < 9)
            cout << i + 1 << setw(2);
        else
            cout << i + 1 << setw(1);
        cout << ")" << setw(10)
             << "op = " << op << setw(8)
             << "accumulator = ";
        if (accumulator == 0)
        {
            if (op != 43)
            {
                cout << "(empty)"
                     << setw(8)
                     << "data[" << address << "]=" << memory[address] << endl;
            }

            else
            {
                cout << "(empty)" << endl;
            }
        }

        else
        {
            if (op != 43)
            {
                cout << accumulator << setw(14)
                     << "data[" << address << "]=" << memory[address] << endl;
            }
            else
            {
                cout << accumulator << endl;
            }
        }
    }

    return 0;
}
/*
1000
1001
2000
3001
2102
2000
3101
2103
2000
3301
2104
4300


*/