#include<iostream>
using namespace std;
void insert_sort(int arr[],int n,int step){
    if(step==n)
    return;
    
    int key=arr[step];
    int j=step-1;
    while(key<arr[j]&& j>=0){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    insert_sort(arr,n,step-1);


}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{ int size=5;

   int arr[5]={11,9,10,7,6} ;

insert_sort(arr,size,1);
print_array(arr,size);
for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}
 return 0;
}