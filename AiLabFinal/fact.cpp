#include <iostream>
using namespace std;
int main()
{
    bool dia;
    int arr[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for (int i = 0; i < 2; i++)
    {
        if (arr[i][i] == arr[i + 1][i + 1])
        {
            dia = true;
        }
        else
            dia = false;
    }
    bool s;
    if (dia)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 0 && i != j)
                {
                    cout << "in loo" << endl;
                    s = true;
                    break;
                }
                else

                    s = false;
            }
        }
    }
    if (s)
    {
        cout << "scalar" << endl;
    }
    else
        cout << "not scan" << endl;

    return 0;
}