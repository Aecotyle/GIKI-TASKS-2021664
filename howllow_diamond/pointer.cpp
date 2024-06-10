#include <iostream>
using namespace std;

void jb(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + 4) << endl;
    }
}

int main()
{
    int *ptr;
    int aerr[2][3];
    int arr[5] = {1, 2, 3, 4, 5};

    ptr = &arr[0];

    jb(ptr);

    return 0;
}