#include <iostream>
using namespace std;
int main(){
    int n,space;
    cout<<"enter a number";
    cin>>n;
    space=n-1;
    for(int i=1;i<=n;i++){
         for(int j=0;j<space;j++){
             cout<<" ";
         }
        //ytn
         for(int j=1;j<=i;j++){
             cout<<j;
         }
         for(int j=1;j<=i-1;j++){
             cout<<i-j;
         }
        
        space--;
        cout<<endl;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=1;j<=n-i;j++){
            cout<<j;
        }
        

        cout<<endl;
    }
return 0;
}