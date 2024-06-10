#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

void postfixClass::setInfix(string s)
{
    infixExp = s;
}

string postfixClass::getInfix()
{
    return infixExp;
}

void postfixClass::convertPosfix()
{
    int pres, assoc, paranthesisCount = 0, b_open = false;
    try
    {
        for (int i = 0; infixExp[i]; i++)
        {
            // if infixExp[i] is not a digit and decimal dot (.)
            if ((infixExp[i] < '0' || infixExp[i] > '9') && infixExp[i] != '.')
            {
                // push previously collected char array(string) of digits
                if (temp.length() != 0)
                {
                    postfixStack->push(temp);
                    temp.clear();
                }

                if (infixExp[i] == '(')
                {
                    b_open = true;
                    paranthesisCount++;
                    opStack->push(infixExp[i]);
                }
                else if (infixExp[i] == ')')
                {
                    if (!b_open)
                        throw -1;
                    if (paranthesisCount == 1)
                        b_open = false;
                    paranthesisCount--;
                    while (opStack->top() != '(')
                    {
                        postfixStack->push(getString(opStack->top()));
                        opStack->pop();
                    }
                    opStack->pop();
                }

                else
                {

                    bool loop = true;
                    do
                    {
                        if (opStack->empty() || opStack->top() == '(')
                        {
                            opStack->push(infixExp[i]);
                            loop = false;
                        }
                        else
                        {
                            // operands along with operators are passed to function to check their precedence and associativity
                            precedenceCheck(opStack->top(), infixExp[i], pres, assoc);
                            if (pres == 1)
                            {
                                opStack->push(infixExp[i]);
                                loop = false;
                            }
                            else if (pres == -1)
                            {

                                postfixStack->push(getString(opStack->top()));
                                opStack->pop();
                                loop = true;
                            }
                            else if (pres == 0)
                            {
                                if (assoc == -1)
                                {
                                    postfixStack->push(getString(opStack->top()));
                                    opStack->pop();
                                    loop = true;
                                }

                                if (assoc == 1)
                                {
                                    opStack->push(infixExp[i]);
                                    loop = false;
                                }
                            }
                        }
                    } while (loop);
                }
            }
            else
                temp += infixExp[i];
        }

        if (paranthesisCount)
            throw 0;
    }
    catch (int exp)
    {
        // if brackets are invalid in infix expression
        // for example a closing bracket is present without opening bracket
        if (exp == -1)
            cout << "Invalid Infix Expression --Conversion not possible\n";
        // if no of brackets are not balanced
        // for example there are three opening bracket and two closing brackets
        else if (exp == 0)
            cout << "Invalid Infix Expression --Brackets not balanced\n";
        // program will be terminated as we don't want futher calculations on invalid expression
        exit(0);
    }
    // storing last integer values
    postfixStack->push(temp);
    temp.clear();

    // pushing operators left in stack to postfix expression
    while (!opStack->empty())
    {
        postfixStack->push(getString(opStack->top()));
        opStack->pop();
    }
}

void postfixClass::displayPostfix()
{
    string str = postfixStack->getStackString();
    cout << "Postfix expression: ";
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ',')
            cout << str[i];
}

float postfixClass::evaluate()
{
    string str = postfixStack->getStackString();
    stringstream ss(str);
    stack<float> values(postfixStack->getSize());
    string temp;
    while (getline(ss, temp, ','))
    {
        if (temp == "*" || temp == "/" || temp == "+" || temp == "-" || temp == "^")
        {
            float op1 = values.top();
            values.pop();
            float op2 = values.top();
            values.pop();
            float res = calculate(op1, op2, temp);
            values.push(res);
        }
        else
            values.push(std::stof(temp));
    }
    return values.top();
}

void postfixClass ::precedenceCheck(char onStack, char newOp, int &pres, int &assoc)
{
    // -1 for less precedence
    // 0 for equal precedence
    // +1 for high precedence
    // ----------------------
    // +1 for Right to left associativity
    // -1 for left to Right associativity
    if (newOp == '^')
    {
        if (onStack == '^')
            pres = 0;
        else
            pres = 1;
        assoc = 1;
    }
    else if (newOp == '/' || newOp == '*')
    {
        if (onStack == '^')
            pres = -1;
        else if (onStack == '*' || onStack == '/')
            pres = 0;
        else
            pres = 1;

        assoc = -1;
    }
    else if (newOp == '+' || newOp == '-')
    {
        if (onStack == '+' || onStack == '-')
            pres = 0;
        else
            pres = -1;

        assoc = -1;
    }
}

float postfixClass::calculate(float op1, float op2, string opt)
{

    if (opt == "+")
        return add(op1, op2);
    else if (opt == "-")
        return subtract(op1, op2);
    else if (opt == "/")
        return divide(op1, op2);
    else if (opt == "*")
        return mutiply(op1, op2);
    else if (opt == "^")
        return power(op1, op2);
    else
        return 0;
}

float postfixClass::add(float op1, float op2)
{
    return op1 + op2;
}

float postfixClass::subtract(float op1, float op2)
{
    return op2 - op1;
}
float postfixClass::divide(float op1, float op2)
{
    // zero in denominator exception
    try
    {
        if (op1 == 0)
            throw 0;
    }
    catch (int exp)
    {
        cout << "\n --Math Error-- \n";
        cout << "Division by zero not possible!\n";
        exit(0);
    }
    return op2 / op1;
}
float postfixClass::power(float op1, float op2)
{
    return pow(op2, op1);
}
float postfixClass::mutiply(float op1, float op2)
{
    return op2 * op1;
}