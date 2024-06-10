#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter a number"<<endl;
cin>>n;
int space=1;
for(int i=0;i<=n;i++){
    for(int j=0; j<n-i;j++){
        cout<<"*";
    }
    for(int j=0;j<space;j++){
        cout<<" ";
    }
    for(int j=0;j<2*n-2*i;j++){
        cout<<"/";
    }
       for(int j=-2;j<2*i-2;j++){
        cout<<"\\";
    }
    for(int j=0;j<space;j++){
        cout<<" ";
    }
      for(int j=0; j<n-i;j++){
        cout<<"*";
    }

    cout<<endl;
    space++;

}



 return 0;   
}