// Reg no. 2021468
#include "helper.h"
int main()
{
    char arr1[] = "hello", arr2[] = "worldTest";
    CMystring obj1(arr1), obj2(arr2);

    //-------------------------*****
    // Getting size of obj1 and 2 respectively
    //-------------------------*****
    cout << "=====Get Size============" << endl;
    cout << "-------------------------" << endl;
    cout << "Size of obj1: " << obj1.getSize() << endl;
    cout << "Size of obj2: " << obj2.getSize() << endl;
    cout << "-------------------------" << endl;
    cout << endl;

    //-------------------------*****
    // Cantenation: obj1+obj2
    //-------------------------*****
    cout << "=====Addition============" << endl;
    cout << "-------------------------" << endl;
    cout << obj1 + obj2 << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Contenation: obj1+=obj2
    //-------------------------*****
    cout << "=====Concatenation=======" << endl;
    cout << "-------------------------" << endl;
    cout << "before concatenation: += " << obj1 << endl;
    obj1 += obj2;
    cout << "After concatenation: += " << obj1 << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Get/set character using []
    //-------------------------*****
    cout << "=====Get/Set []==========" << endl;
    cout << "-------------------------" << endl;
    cout << "Getting character at index [3]: " << endl;
    cout << obj1[3] << endl;
    cout << "Setting character(X) at index [3]: " << endl;
    obj1[3] = 'X';
    cout << obj1 << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Testing equal and not-equal
    //-------------------------*****
    cout << "=====Operator == & != ===" << endl;
    cout << "-------------------------" << endl;
    if (obj1 == obj2)
        cout << "Obj1 and Obj2 are equal" << endl;
    else if (obj1 != obj2)
        cout << "Obj1 is not equal to obj1 2" << endl;
    else
        cout << "Niether of case is true" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Testing overloaded greater and less than operator
    //-------------------------*****
    cout << "=====Comparison(< & >)===" << endl;
    cout << "-------------------------" << endl;
    if (obj1 > obj2)
        cout << "obj1 is greater than obj2" << endl;
    else if (obj1 < obj2)
        cout << "obj2 is greater than obj1" << endl;
    else
        cout << "Obj1 is equal to Obj2" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Overloaded Substring (a,b) operator
    //-------------------------*****
    cout << "=====Substring(a,b)======" << endl;
    cout << "-------------------------" << endl;
    cout << "obj1     : " << obj1 << endl
         << "obj1(3,6): ";
    cout << obj1(3, 6) << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Overloading assignment operator
    //-------------------------*****
    cout << "=Assignment operator(=)==" << endl;
    cout << "-------------------------" << endl;
    cout << "obj1: " << obj1 << endl;
    cout << "obj2: " << obj2 << endl;
    obj1 = obj2;
    cout << "obj1 = obj2\nobj1: " << obj1 << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    //-------------------------*****
    // Right and left shift
    //-------------------------*****
    cout << "=====Left shift << ======" << endl;
    cout << "-------------------------" << endl;
    cout << "Left shifting obj1 << by 2 : " << (obj1 << 2) << endl;
    cout << "Obj1 after shifting : " << obj1 << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    cout << "=====Right shift >> =====" << endl;
    cout << "Right shifting obj2 >> by 2 : " << (obj2 >> 2) << endl;
    cout << "Obj2 after shifting : " << obj2 << endl;
    cout << "-------------------------" << endl;
    cout << endl;

    return 0;
}
