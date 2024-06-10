#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif
class postfixClass
{
    string infixExp;
    string postfixExp;
    stack<char> *opStack;
    stack<string> *postfixStack;
    string temp;

public:
    // constructor
    postfixClass(string _infixExp = "", int _opSize = 20, int _pfxSize = 50)
    {
        this->infixExp = _infixExp;
        opStack = new stack<char>(_opSize);
        postfixStack = new stack<string>(_pfxSize);
    }
    // fucntion prototypes
    string getInfix();
    void setInfix(string s);
    void convertPosfix();
    void displayPostfix();
    float subtract(float op1, float op2);
    float add(float op1, float op2);
    float divide(float op1, float op2);
    float power(float op1, float op2);
    float mutiply(float op1, float op2);
    float calculate(float op1, float op2, string opt);
    float evaluate();
    void precedenceCheck(char onStack, char newOp, int &pres, int &assoc);
};