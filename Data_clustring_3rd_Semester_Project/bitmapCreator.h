#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

struct color
{
    float r, g, b;
    color(float _r = 0.0, float _g = 0.0, float _b = 0.0)
    {
        r = _r;
        g = _g;
        b = _b;
    }
};
class Image
{
private:
    int width;
    int height;
    vector<color> v_colors;

public:
    Image(int _width, int _height)
    {
        width = _width;
        height = _height;
        v_colors.resize(width * height);
    }
    color getColor(int x, int y)
    {
        return v_colors[y * width + x];
    }
    void setColor(color _color, int x, int y)
    {
        v_colors[y * width + x].r = _color.r;
        v_colors[y * width + x].g = _color.g;
        v_colors[y * width + x].b = _color.b;
    }
    void Export(string path)
    {
        // opening file to export on given path;
        ofstream f;
        f.open(path, ios::out | ios::binary);
        if (!f.is_open())
        {
            cout << "Error in opening file\n";
            return;
        }

        unsigned char bmpPad[3] = {0, 0, 0};
        // calculating padding amount using the formula
        const int paddingAmount = ((4 - (width * 3) % 4) % 4);

        const int fileHeaderSize = 14;
        const int informationHeaderSize = 40;
        const int fileSize = fileHeaderSize + informationHeaderSize + width * height * 3 + paddingAmount * height;

        unsigned char fileHeader[fileHeaderSize];

        // saving header info
        // File type
        fileHeader[0] = 'B';
        fileHeader[1] = 'M';
        // File size
        fileHeader[2] = fileSize;
        fileHeader[3] = fileSize >> 8;
        fileHeader[4] = fileSize >> 16;
        fileHeader[5] = fileSize >> 24;

        // Reserved 1 (Not used)
        fileHeader[6] = 0;
        fileHeader[7] = 0;
        // Reserved 2 (Not used)
        fileHeader[8] = 0;
        fileHeader[9] = 0;

        // Pixel data offset
        fileHeader[10] = fileHeaderSize + informationHeaderSize;
        fileHeader[11] = 0;
        fileHeader[12] = 0;
        fileHeader[13] = 0;

        unsigned char informationHeader[informationHeaderSize];

        // Header Size
        informationHeader[0] = informationHeaderSize;
        informationHeader[1] = 0;
        informationHeader[2] = 0;
        informationHeader[3] = 0;

        // Image width
        informationHeader[4] = width;
        informationHeader[5] = width >> 8;
        informationHeader[6] = width >> 16;
        informationHeader[7] = width >> 24;

        // Image height
        informationHeader[8] = height;
        informationHeader[9] = height >> 8;
        informationHeader[10] = height >> 16;
        informationHeader[11] = height >> 24;

        // Planes
        informationHeader[12] = 1;
        informationHeader[13] = 0;

        // Bits per pixel (RGB)
        informationHeader[14] = 24;
        informationHeader[15] = 0;

        // Compression (no compression)
        informationHeader[16] = 0;
        informationHeader[17] = 0;
        informationHeader[18] = 0;
        informationHeader[19] = 0;
        // Image Size (no compression)
        informationHeader[20] = 0;
        informationHeader[21] = 0;
        informationHeader[22] = 0;
        informationHeader[23] = 0;

        // X pixel per meter (Not specified)
        informationHeader[24] = 0;
        informationHeader[25] = 0;
        informationHeader[26] = 0;
        informationHeader[27] = 0;
        // Y pixel per meter (Not specified)
        informationHeader[28] = 0;
        informationHeader[29] = 0;
        informationHeader[30] = 0;
        informationHeader[31] = 0;

        // Total colors (color palette not used)
        informationHeader[32] = 0;
        informationHeader[33] = 0;
        informationHeader[34] = 0;
        informationHeader[35] = 0;

        // Important colors (generally ignored)
        informationHeader[36] = 0;
        informationHeader[37] = 0;
        informationHeader[38] = 0;
        informationHeader[39] = 0;

        f.write(reinterpret_cast<char *>(fileHeader), fileHeaderSize);
        f.write(reinterpret_cast<char *>(informationHeader), informationHeaderSize);

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char r = static_cast<unsigned char>(getColor(x, y).r * 255.0f);
                unsigned char g = static_cast<unsigned char>(getColor(x, y).g * 255.0f);
                unsigned char b = static_cast<unsigned char>(getColor(x, y).b * 255.0f);

                unsigned char _colors[] = {b, g, r};
                f.write(reinterpret_cast<char *>(_colors), 3);
            }
            f.write(reinterpret_cast<char *>(bmpPad), paddingAmount);
        }

        f.close();

        cout << "Bitmap File created\n";
    }
};

