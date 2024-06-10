#include <iostream>
using namespace std;
int main(){
    int back_slash=0,exclamation_mark;
    int i=0,n,j,k;
    cout<<"enter a number";
    cin>>n;
    exclamation_mark=4*n-2;
    while(i<n){
        j=0;
        while(j<back_slash){
            cout<< "\\";
            j++;
        }
        j=0;
        while(j<exclamation_mark){
            cout<<"!";
             j++;
        }
        j=0;
        while(j<back_slash){
            cout<< "/";
            j++;
        }
        cout<<endl;
        i++;
        back_slash+=2;
        exclamation_mark-=4;

    }


    return 0;
}