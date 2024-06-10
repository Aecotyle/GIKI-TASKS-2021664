#include<iostream>
using namespace std;
int main()
{
    int n=10;
 int arr[10]={2,34,34,23,32,213,4,432,7,54};
 for(int i=0; i<n-1;i++){

     for(int j=0;j<n-i;j++){
         if(arr[j]>arr[j+1]){
             swap(arr[j],arr[j+1]);
         }
     }
 }

 for(int i=0;i<n;i++){
     cout<<arr[i]<<endl;
 }
 
 
 return 0;
}