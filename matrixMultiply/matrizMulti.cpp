#include <iostream>
using namespace std;
void arrMulti(int arr1[][5], int arr2[][5],int row1,int col1,int row2,int col2);

int main()
{
    const int matrix1Row=5,matrix1Col=5,matrix2Row=5,matrix2Col=5;
    int arr1[matrix1Row][matrix1Col] = {{1, 2, 3,4,5},{1, 2, 3,4,5},{1, 2, 3,4,5},{1, 2, 3,4,5},{1, 2, 3,4,5}};
    int arr2[matrix2Row][matrix2Col] = {{1, 2, 3,4,5},{1, 2, 3,4,5},{1, 2, 3,4,5},{1, 2, 3,4,5},{1, 2, 3,4,5}};

    arrMulti(arr1, arr2,matrix1Row,matrix1Col,matrix2Row,matrix2Col);

    return 0;
}

void arrMulti(int arr1[5][5], int arr2[5][5],int row1,int col1,int row2,int col2)
{
    int tempArr[row1][col2];
    // making temparr all elements zero
    int tempProduct = 1;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            tempArr[i][j] = 0;
        }
    }
    // arr multi
    for (int z = 0; z < row1; z++)
    {
        for (int j = 0; j < col2; j++)
        {
            int tempSum = 0;

            for (int i = 0; i < col1; i++)
            {
                tempSum += arr1[z][i] * arr2[i][j];
            }
            tempArr[z][j] = tempSum;
        }
    }
    for (int i = 0; i < row1; i++)
    {
        cout << "| ";
        for (int j = 0; j < col2; j++)
        {
            cout << tempArr[i][j] << " ";
        }
        cout << "|" << endl;
    }
}