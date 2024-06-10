#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif
// utility funciton to convert char to string
string getString(char a)
{
    string s(1, a);
    return s;
}
//prints 100 new lines to clear console previous output
void screenClear(){
    for(int i =0;i<100;i++){
       cout<<"\n"; 
    }
}