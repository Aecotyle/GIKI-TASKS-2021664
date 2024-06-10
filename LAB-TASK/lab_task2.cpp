#include<iostream>
#include <string>
using namespace std;
void copy_str(string str1,string &str2,int len){
    if(len>0)
    {
        char temp;
        temp= str1.front();
        str1.erase(0,1);
        str2.push_back(temp);
        copy_str(str1,str2,len-1);
    }
    else
        return ;
  
}
int main()
{   string str,str2;
    cout<<"ENTER YOUR STRING"<<endl;
    getline(cin,str);

    int len=str.length();

    copy_str(str,str2,len);
    cout<<"COPIED STRING: "<<str2<<endl;
    return 0;
}