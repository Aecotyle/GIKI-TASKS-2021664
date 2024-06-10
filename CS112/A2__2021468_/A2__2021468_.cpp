#include "helper.h"

int main()
{
    string str1 = ",", str2 = "HEll,o wor,ld this is, a test case";
    char *ptr1 = &str1[0];
    char *ptr2 = &str2[0];

    //*******************************
    // Every funtion is working perfectly, you can de-comment the fucntions called below to check it
    //*******************************

    //*******************************
    cout << Mystrlen(ptr2);
    //*******************************

    //*******************************
    // Mystrtok fucntion is called 3 times to check if it remembers the previous index of delimiter or not
    // for (int i = 0; i < 3; i++)
    //     cout << Mystrtok(ptr2, ptr1) << endl;
    //*******************************

    //*******************************
    // cout << Mystrcpy(ptr1, ptr2) << endl;
    // cout << Mystrncpy(ptr1, ptr2, 8) << endl;
    //*******************************

    //*******************************
    // cout << Mystrcat(ptr1, ptr2);
    // cout << Mystrncat(ptr1, ptr2, 5);
    //*******************************

    //*******************************
    // cout << Mystrcmp(ptr2, ptr1);
    // cout << Mystrncmp(ptr1, ptr2, 6);
    //*******************************

    //*******************************
    // Reg: 2021468
    //*******************************

    return 0;
}
