#include <iostream>
#include <math.h>
#include <unistd.h>

using namespace std;

class Donut
{
private:
    const static int width = 50;
    const static int height = 22;
    float zbuff[height][width];
    char screen[height][width];
    float A, B;
    int R1, R2, k1, k2;
    string lightIntensity;

public:
    Donut() : A(0), B(0), R1(1), R2(2), k1(15), k2(5), lightIntensity(".,-~:;=!*#$@") {}

    void print(char[][width]);
    void reIntializer(char[][width]);
    void display();
};

void Donut::print(char screen[][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << screen[i][j];
            // A and B are incremented on each iteration with few decimals
            // to rotate donut around x and z axis
            A += 0.00005;
            B += 0.00003;
        }
        cout << endl;
    }
}
void Donut::reIntializer(char screen[][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screen[i][j] = ' ';
            zbuff[i][j] = 0;
        }
    }
}
void Donut::display()
{
    while (true)
    {
        /**
         * @brief
         * reintializer funciton fill the the whole screen array with space " "
         * and zbuff array with 0
         * The values of theta and phi are incremented by 0.08 and 0.0175 repectively
         * as 1 degree= 0.0175 radians . These values can be changed . More the angle increment
         * is, faster is rotation and lesser points will be calculate 
         */
        reIntializer(screen);

        for (float theta = 0; theta < 6.28; theta += 0.08)
        {

            for (float phi = 0; phi < 6.28; phi += 0.0175)
            { /**
           * @brief
           *  calulating (x,y,z) coordinates, surface Normal, (Xprime(xp),yprime(yp)) and luminanace index respectively.
              x : (R2+R1cosθ)(cosBcosϕ-cosAsinBsinϕ)+R1sinAsinBsinθ
              y : (R2+R1cosθ)(cosϕsinB+cosBcosAsinϕ)-R1sinAcosBsinθ
              z : sinA(R2+R1cosθ)sinϕ+R1cosAsinθ
              Surface normal : /z+k2 (surface normal)
              luminance index: 8*(cosϕcosθsinB−sinAcosθsinϕ−cosAsinθ+cosB(sinAsinθ−cosθcosAsinϕ))
           */

                float x = (R2 + (R1 * cos(theta))) * ((cos(B) * cos(phi)) - (cos(A) * sin(B) * sin(phi))) + R1 * sin(A) * sin(B) * sin(theta);
                float y = (R2 + (R1 * cos(theta))) * ((cos(phi) * sin(B)) + (cos(B) * cos(A) * sin(phi))) - R1 * sin(A) * cos(B) * sin(theta);
                float z = sin(A) * sin(phi) * (R2 + (R1 * cos(theta))) + R1 * cos(A) * sin(theta);
                float surfaceNormal = 1.0 / (k2 + z);
                // some constants are added to xp and yp to adjust the shape of donut and display it properly on console
                int xp = 24 + 2 * k1 * (1 / (z + k2)) * x;
                int yp = 12 + k1 * (1 / (z + k2)) * y;
                int luminanceIndex = 8 * ((cos(phi) * cos(theta) * sin(B)) - (sin(A) * cos(theta) * sin(phi)) - cos(A) * sin(theta) + cos(B) * sin(A) * sin(theta) - cos(B) * cos(theta) * cos(A) * sin(phi));

                /*
                we don't want to plot points that exceed sreen width and height
                checking if 1/z is greater than zbuff at that point(xprime,yprime)
                as we want only those point whose normal is toward screen so
                if it satistfies both conditions only then character is plotted at that point
                */
                if (height > yp && yp > 0 && xp > 0 && width > xp && surfaceNormal > zbuff[yp][xp])
                {
                    // zbuff value is updated to surfaceNormal(1/z+k2) at (zp,yp)
                    zbuff[yp][xp] = surfaceNormal;
                    screen[yp][xp] = (luminanceIndex > 0) ? lightIntensity[luminanceIndex] : lightIntensity[0];
                }
            }
        }
        /**
         * @brief 
         * using system("clear") to clear console each time after print(For Mac)
           system("cls") can be used on windows
           print function couts<< the whole 2d array (Screen)
           usleep is used to make programme little slow depending value to display a smooth animation
           basically it stop execution for few microseconds
         */
        system("clear");
        print(screen);
        usleep(25000);
    }
}

int main()
{
    Donut donutObj;
    donutObj.display();

    return 0;
}
// Reg 2021468
