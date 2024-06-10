#include <iostream>
using namespace std;
void detCalc(int arr[3][3], int, int);

int calc(int arr[2][2]);
int main()
{
    int arr[3][3] = {{3,5,7}, {5,6,7}, {5,8,9}};
    int tempArr[2][2] = {{1, 2}, {3, 4}};
     detCalc(arr,3,3);
    // cout<<calc(tempArr);
    return 0;
}
void detCalc(int arr[3][3], int row, int col)
{
    int tempArr[2][2];
    int det1=0,det2=0,det3=0,sum=0;
    // expanding by r1 c1
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 0)
                tempArr[i - 1][j - 1] = arr[i][j];
        }
    }
    det1=arr[0][0]*calc(tempArr);
    // expanding by r1 c2
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 1)
                tempArr[i - 1][j] = arr[i][j];
        }
    }
      det2=arr[0][1]*calc(tempArr); 
    // expanding by r1 c3
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
                tempArr[i - 1][j] = arr[i][j];
        }
    }
      det3=arr[0][2]*calc(tempArr);
        sum=det1+(-1*det2)+det3;
      for (int i=0;i<3;i++){
          cout<<"| ";
          for(int j=0;j<3;j++){
              cout<<arr[i][j]<<" ";
          }
       if(i==1)
       cout<<"|"<<" = "<<sum<<endl; 
          else
          cout<<"|"<<endl;
      }

}

int calc(int arr[2][2])
{
    int p1, p2, sum;

    p1 = arr[0][0] * arr[1][1];
    p2 = arr[1][0] * arr[0][1];
    sum = p1 - p2;
    return sum;
}