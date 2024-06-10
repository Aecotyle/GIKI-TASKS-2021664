#include <iostream>
using namespace std;
void func(int *ptr, int arr[])
{
    for (int i = 0; i < 5; i++)
    {

        cout << "Position: " << i + 1 << " #Actual : value " << arr[i] << " ,Address = " << &arr[i] << endl;
        cout << "Position: " << i + 1 << " #Actual : value " << *ptr << " ,Address = " << ptr << endl;
        cout << endl;
        ptr++;
    }
}

int main()
{
    int arr[5];
    int *ptr;
    ptr = &arr[0];
    for (int i = 0; i < 5; i++)
    {
        cout << "enter arr element " << i << " ";
        cin >> arr[i];
    }
    func(ptr, arr);

    return 0;
}