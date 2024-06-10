#include "bitmapCreator.h"

void create_bitmap(string txtfilename, float _color=0)
{
    //function to write txt file values to a bimap file u
    //first read the files
    //convert char to float
    //write the values using function

    ifstream f("txtFiles/"+txtfilename);
    if (!f.is_open())
        cout << "Err in opening " << txtfilename << endl;

    string str;

    vector<vector<double> > data;

    for (int i = 0; getline(f, str); i++)
    {

        stringstream ss(str);
        string str2;
        vector<double> temp;
        for (int j = 0; getline(ss, str2, ',') && j < 148; j++)
            temp.push_back(stod(str2));

        data.push_back(temp);
    }

    const int width = data[0].size();
    const int height = data.size();

    Image img(width, height);
    int r1=rand()%200;
    int r2=rand()%100;
    int r3=rand()%150;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
               if(_color ){
                    if(data[i][j]==1)
                    img.setColor(color(r1,120+_color,255), j, i);
                    else
                    img.setColor(color(r2,r3+_color,r1), j, i);
                 }
               else if(data[i][j]==1)
                {  

                    img.setColor(color(200,120,255), j, i);
                }
                else if(data[i][j]!=0) {
                 if(data[i][j]>1)
                img.setColor(color(150,data[i][j],255), j, i);
                else
                img.setColor(color(200,100+data[i][j],255), j, i);

                }
        }
    }
    int l=txtfilename.length();
    txtfilename[l-3]='b';
    txtfilename[l-2]='m';
    txtfilename[l-1]='p';
    img.Export("bitmaps/"+txtfilename);
}