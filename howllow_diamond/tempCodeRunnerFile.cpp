#include <iostream>
using namespace std;
void func(int n, int i,int space)
{
    if( i < n)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        cout << "*";

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << " ";
        }
        if (i > 0)
            cout << "*";

        space--;
        cout << endl;
        func(n,i+1,space);
    }
    else 
    return;
}
void func2(int n,int i,int space){
   if ( i < n)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        if (i < n - 1)
            cout << "*";
        space = space - 2;
        cout << endl;
    func2(n,i+1,space);
    }
    else 
    return;
}
int main()
{
    int n, space;
    cout << "enter a number: ";
    cin >> n;
    space = n - 1;

    func(n,0,space);
    //n = n - 1;
    space = 2 * n - 5;
    func2(n, 1,space);
    return 0;
}