#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

int main()
{
    screenClear();
    postfixClass exp;
    exp.setInfix("(23)+45.89*(56-77.7)/9*2+(55-22)+(6*77)-5^2+(99+100)^2.57");
    cout<<"Infix expression  : "<< exp.getInfix()<<endl;
    exp.convertPosfix();
    exp.displayPostfix();
    cout << "\nAnswer to verify  : "
         << "2345.895677.7-*9/2*+5522-+677*+52^-99100+2.57^+\n" << endl;
    cout<<"Results after evaluation: ";
    cout<<exp.evaluate()<<endl;
    return 0;
}

