#include <iostream>
#include <string>
#include <time.h>
using namespace std;
int main()
{   
char arr[9];
    int turn=0,index;
    char temp,a, b, c, d, e, f, g, h, i,symbol1,symbol2;
    int random;
    int player1,player2;
    cout<<"Player one select his symbol:  ";
    cin>>symbol1;
    cout<<"Player two select his symbol:  ";
    cin>>symbol2;
    srand(time(0));
    random=rand()%2+1;
    if(random==1){
         cout<<"Player one turn"<<endl;
         turn=1;

    }
    else{
         cout<<"Player two turn"<<endl;
         turn=2;
    }
    while(true){
    cout << "  " << arr[1] << " "
         << "|"
         << "  " << arr[2] << " "
         << "|"
         << "  " << arr[3] << " " << endl;
    cout << "------------" << endl;
    cout << "  " << arr[4]<< " "
         << "|"
         << "  " << arr[5]<< " "
         << "|"
         << "  " << arr[6] << " " << endl;
    cout << "------------" << endl;
    cout << "  " << arr[7]<< " "
         << "|"
         << "  " << arr[8]<< " "
         << "|"
         << "  " << arr[9] << " " << endl;
    cout<<""
    cout<<"Enter your index:  ";
    cin>>index;
    arr[index]=symbol1;}


    return 0;
}