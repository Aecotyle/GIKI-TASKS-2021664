#include <iostream>
using namespace std;
void func(int arr[], int size, int i)
{
    if (i < size - 1)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }

        func(arr, size, i + 1);
    }
}
void search(int arr[], int size, int x)
{
    int high = arr[size - 1];
    int low = arr[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x == mid)
            cout << "found at " << mid;
        if (x > mid)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
}

int main()
{
    int arr[5] = {4, 5, 7, 1, 3};
    func(arr, 5, 0);
    search(arr, 5, 7);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}