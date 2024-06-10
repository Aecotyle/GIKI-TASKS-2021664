#include <iostream>
using namespace std;
void func(int *ptr, int arr[])
{ int sum=0;
    for (int i = 0; i < 5; i++)
    {

        cout << "Position: " << i << " #Actual : value " << arr[i] << " ,Address = " << &arr[i] << endl;
        cout << "Position: " << i << " #Pointer : value " << *ptr << " ,Address = " << ptr << endl;
        cout << endl;
        sum+=*ptr;
        ptr++;
    }
    cout<<" sum : "<<sum<<endl;
}

void inputArr(int arr[],int size){
     for (int i = 0; i < size; i++)
    {
        cout << "enter arr element " << i << " ";
        cin >> arr[i];
    }
}
int main()
{
    int arr[5];
    int *ptr;
    ptr = &arr[0];
    inputArr(arr,5);
    func(ptr, arr);

    return 0;
}