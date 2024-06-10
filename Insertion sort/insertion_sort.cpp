#include <iostream>
using namespace std;
void func(int arr[], int size, int i)
{
    if (i < size)
    {
        int key = arr[i];
        int j = i - 1;
        while (key > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        func(arr, size, i + 1);
    }
}

int main()
{
    int arr[5] = {4, 5, 7, 1, 3};
    func(arr, 5, 1);

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}