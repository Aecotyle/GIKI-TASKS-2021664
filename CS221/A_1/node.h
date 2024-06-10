#ifndef HEADER_H
#define HEADER_H
#include "header.h"
#endif

struct Node
{

    int phone_num;
    string owners_name;
    string address;
    string email;

    Node *next;
    Node *prev;
    Node *up;
    Node *down;

    Node(int p = 0, string o = " ", string a = " ", string e = " ")
    {
        phone_num = p;
        owners_name = o;
        address = a;
        email = e;
        this->next = NULL;
        this->prev = NULL;
        this->up = NULL;
        this->down = NULL;
    }
    //copy constructor 
    Node(Node *toBeCopied)
    {
       owners_name = toBeCopied->owners_name;
         phone_num = toBeCopied->phone_num;
           address = toBeCopied->address;
             email = toBeCopied->email;
        this->next = toBeCopied->next;
        this->prev = toBeCopied->prev;
          this->up = toBeCopied->up;
        this->down = toBeCopied->down;
    }
};
