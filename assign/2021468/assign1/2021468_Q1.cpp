#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    float a, b, c, x1, x2;
    cout << "Quadratic Formula Calculater\n ax^2 + bx + c" << endl;

    //user input
    cout << "Please enter value of 'a' : " << endl;
    cin >> a;
    cout << "Please enter value of 'b' : " << endl;
    cin >> b;
    cout << "Please enter value of 'c' : " << endl;
    cin >> c;

    //calculating values of x1 and x2
    x1 = (-b + sqrt(pow(b, 2) - 4 * (a * c))) / (2 * a);

    x2 = (-b - sqrt(pow(b, 2) - 4 * (a * c))) / (2 * a);

    //determining the nature of roots
    if (b * b == 4 * a * c)
    {
        cout << "The roots are real and both roots are the same." << endl;
        cout << "x1 :" << x1 << endl;
        cout << "x2 :" << x2 << "\n";
    }

    else if (b * b > 4 * a * c)
    {
        cout << "The roots are real and both roots are different" << endl;
        cout << "x1 :" << x1 << endl;
        cout << "x2 :" << x2 << "\n";
    }

    else
        cout << "The roots are not real i.e. they are complex " << endl;

    return 0;
    //reg 2021468
}