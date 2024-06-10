#include<iostream>
using namespace std;
void func(int arr[],int a,int &min, int &max){

//for(int i=0;i<4;i++){
  if(a==0)
      return;
  

  else{
        if(arr[a-1]>max)
        max=arr[a-1];
        if(arr[a-1]<min)
        min=arr[a-1];
        func(arr,a-1,min,max);

    }
}


int main()
{   int min,max,arr[10];
    
    for(int i=0;i<10;i++){
        cout<<"enter no : ";
        cin>>arr[i];
    }
    max=arr[0],min=arr[0];
    
    func(arr,10,min,max);
    cout<<"max : "<<max<<endl;
    cout<<"min : "<<min<<endl;

 return 0;
}