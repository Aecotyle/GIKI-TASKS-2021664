#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number";
    cin>>n;

    /* top portion //xx\\ 
                 ////xx\\\\ 
               //////xx\\\\\\ 
    *///
    for(int i=1;i<=n; i++){

       for(int j=0; j<=n-i;j++){
           cout<<" ";
       } 
       for(int j=0; j<i;j++){
           cout<<"/";
       }
       cout<<"*"<<"*";
       for(int j=0;j<i;j++){
           cout<<"\\";
       }
        cout<<endl;
    }
                

    for(int i=0;i<=n;i++){
        cout<<"*_";
    }
    cout<<"*"<<endl;
    
    /* upper mid portion{upper half}
    |--/\------/\--|
    |-/\/\----/\/\-|
    |/\/\/\--/\/\/\|
    */

    for(int i=1;i<=n-2;i++){
        cout<<"|";
        for(int j=0;j<n-i-2;j++){
            cout<<"-";
        }
        for(int j=0;j<i;j++){
        cout<<"/"<<"\\";}
        for(int j=0;j<2*(n-2)-2*i;j++){
            cout<<"-";
        }
        for(int j=0;j<i;j++){
        cout<<"/"<<"\\";}
         for(int j=0;j<n-i-2;j++){
            cout<<"-";
        }
        cout<<"|";
        
        
        cout<<endl;
    }

    /*upper mid {lower half}
    |\/\/\/\/\/\/|
    |-\/\/--\/\/-|
    |--\/----\/--|
*/
    for(int i=0;i<n-2;i++){
        
        cout<<"|";
        for(int j=0;j<i;j++){
            cout<<"-";
        }
        for(int j=0; j<n-2-i;j++ ){
            cout<<"\\"<<"/";
        }
        for(int j=0;j<2*i;j++){
            cout<<"-";
        }
        for(int j=0; j<n-2-i;j++ ){
            cout<<"\\"<<"/";
        }
        for(int j=0;j<i;j++){
            cout<<"-";
        }
        cout<<"|";
        cout<<endl;
    }
     for(int i=0;i<=n;i++){
        cout<<"*_";
    }
    cout<<"*"<<endl;

    /*lower mid{ upper half}
    |\/\/\/\/\/\/|
    |-\/\/--\/\/-|
    |--\/----\/--|
*/

     for(int i=0;i<n-2;i++){
        
        cout<<"|";
        for(int j=0;j<i;j++){
            cout<<"-";
        }
        for(int j=0; j<n-2-i;j++ ){
            cout<<"\\"<<"/";
        }
        for(int j=0;j<2*i;j++){
            cout<<"-";
        }
        for(int j=0; j<n-2-i;j++ ){
            cout<<"\\"<<"/";
        }
        for(int j=0;j<i;j++){
            cout<<"-";
        }
        cout<<"|";
        cout<<endl;
    }
    /*lower mid {lower half}
    |--/\----/\--|
    |-/\/\--/\/\-|
    |/\/\/\/\/\/\|
*/

    for(int i=1;i<=n-2;i++){
        cout<<"|";
        for(int j=0;j<n-i-2;j++){
            cout<<"-";
        }
        for(int j=0;j<i;j++){
        cout<<"/"<<"\\";}
        for(int j=0;j<2*(n-2)-2*i;j++){
            cout<<"-";
        }
        for(int j=0;j<i;j++){
        cout<<"/"<<"\\";}
         for(int j=0;j<n-i-2;j++){
            cout<<"-";
        }
        cout<<"|";
        
        
        cout<<endl;
    }

     for(int i=0;i<=n;i++){
        cout<<"*_";
    }
    cout<<"*"<<endl;

       /* bottom portion //xx\\ 
                       ////xx\\\\ 
                     //////xx\\\\\\ 
        */
      for(int i=1;i<=n; i++){

       for(int j=0; j<n-i;j++){
           cout<<" ";
       } 
       for(int j=0; j<i;j++){
           cout<<"/";
       }
       cout<<"*"<<"*";
       for(int j=0;j<i;j++){
           cout<<"\\";
       }
        cout<<endl;
    }

}