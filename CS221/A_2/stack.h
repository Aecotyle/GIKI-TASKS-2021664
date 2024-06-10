#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif
template <class T>
class stack
{
    T *st;
    int st_top;
    int size;

public:
    stack(int sz = 0)
    {
        this->size = sz;
        this->st_top = -1;
        this->st = new T[size];
    }

    int getSize(){
        return size;
    }

    void push(T _val)
    {
        if (st_top >= size - 1)
            cout << "Stack Overflow\n";
        else
            st[++st_top] = _val;
    }
    void pop()
    {
        if (st_top <= -1)
            cout << "Stack Underflow\n";
        else
            st_top--;
    }

    T top()
    {
        return st[st_top];
    }

    bool empty()
    {
        if (st_top <= -1)
            return true;
        else
            return false;
    }
    string getStackString()
    {
        // function to get string from stack in reverse order with delimiter added
        string str;
        int t_top = st_top;
        while (t_top > -1)
        {
            
            if(str[0]!=',' && str.length())
           {str=','+str; 
            str = st[t_top]+str;}
            else
            str =st[t_top]+str;
            t_top--;
        }
        return str;
    }
    ~stack(){
        delete [] st;
        st=NULL;
    }
};
