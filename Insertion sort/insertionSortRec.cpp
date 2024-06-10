#include <iostream>
using namespace std;
void arrInput(int arr[], int i, int starter)
{

    if (i > starter)
    {
        cout << "Enter a number : ";
        cin >> arr[starter];
        arrInput(arr, i, starter + 1);
    }
    else
        return;
}
void insertSort(int arr[], int size,int i){

    if(i<size)
    {
        int key = i;
        for (int k = key - 1; k >= 0; k--)
        {
            if (arr[k] > arr[key])
            {
                swap(arr[key], arr[k]);
                key = k;
            }
        }
        insertSort(arr,size,i+1);
    }
    else
    return;
}
void printArry(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int const size = 10;
    int arr[size];
     arrInput(arr,size,0);
    cout << "before: ";
    printArry(arr, size);

    insertSort(arr,size,0);


    printArry(arr, size);

    return 0;
}