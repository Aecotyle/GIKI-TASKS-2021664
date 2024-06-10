#include <iostream>
using namespace std;
int main(){
int n=0,n_temp,temp,order=1;


cout<<"HOW MANY NUMBER DO YOU WANT TO SORT: ";
cin>>n;
cout<<"HOW DO YOU WANT TO SORT INCREASING OR DECREASING?"<<endl;
cout<<"1.INCREASING\n2.DECREASING\n";
cin>>order;
int arr[n];
for(int i=0; i<n;i++){
    system("clear");
    cout<<"ENTER NO."<<i+1<<" OF LIST: ";
    cin>>n_temp;
    arr[i]=n_temp;
}
int smallest=arr[0];

 for(int i=0,z=0;i<n;i++){
smallest=arr[i];
        
     for(int j=z;j<n;j++){
        if(smallest<=arr[j]){
           if(j==n-1){
                temp=arr[z];
                arr[z]=arr[i];
                arr[i]=temp;
                z++;
                i=z-1;
                }
           continue;
           }
        else 
            break;
        }

}
cout<<"YOUR SORTED LIST OF NUMBERS"<<endl;

for(int i=0;i<n;i++){
    if(order==1)
    cout<<arr[i]<<" ";
    else
    cout<<arr[n-i-1]<<" ";
}
cout<<endl;
return 0;
}
