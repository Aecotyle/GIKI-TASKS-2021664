#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"enter a number : ";
    cin>>n;
    for (int i =0; i<n; i++){
        //pritning spaces
        for(int j=0; j<n-i;j++){
            for(int k=0; k<n;k++){
                cout<<" ";
            }
        }
        //printing * for n number on horizontal line *****
        for(int j=0; j<=n;j++){
            cout<<"*";
        }

        /*
        //printing star after space horizontally
                                                                **********
                                                                * space  * these star 
                                                                *        * in last column
                                                        *********        *
                                                        *   <space>      *
                                                        *                *
                                                *********                *
                                                */
    
        for(int j=0;j<i;j++){
            for(int k=0;k<n;k++){
                cout<<" ";
            }
        }
        cout<<"*";
        cout<<endl;
        

    //printing step hieght 
    /*   ********
         *      hieght
         *      *
   *******      *

     */
        for(int x=0;x<2;x++){
            for(int j=0; j<n-i;j++){
                for(int k=0; k<n;k++){
                cout<<" ";
                }
            }
            cout<<"*";
            for(int j=0;j<i+1;j++){
                for(int k=0;k<n;k++){
                cout<<" ";
            }
        }
        cout<<"*"<<endl;}

        
    }
    //print last *********** line
    for(int i=0;i<=(n*n)+n+1;i++){
        cout<<"*";
    }
}