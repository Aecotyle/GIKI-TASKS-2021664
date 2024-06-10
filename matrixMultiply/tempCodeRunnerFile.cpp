#include <iostream>
using namespace std;
void arrMulti(int arr1[][3], int arr2[][2]);

int main()
{

    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    arrMulti(arr1, arr2);

    return 0;
}
void arrMulti(int arr1[2][3], int arr2[3][2])
{
    int tempArr[2][2];
    // making temparr all elements zero
    int tempProduct = 1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tempArr[i][j] = 0;
        }
    }
    // arr multi
    for (int z = 0; z < 2; z++)
    {
        for (int j = 0; j < 2; j++)
        {
            int tempSum = 0;

            for (int i = 0; i < 3; i++)
            {
                tempSum += arr1[1][i] * arr2[i][j];
            }
            tempArr[z][j] = tempSum;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "| ";
        for (int j = 0; j < 2; j++)
        {
            cout << tempArr[i][j] << " ";
        }
        cout << "|" << endl;
    }
}