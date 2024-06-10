#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

void getSubtrings(string s, int row_pos, vector<string> &v)
{
    // fill the vector v (passed as argumnet) with all the possible vertical substrings
    string str;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= s.length() - i; j++)
        {
            str = s.substr(i, j);
            if (str.length() > 1)
            {
                char r_pos = row_pos + '0';
                char start_pos = i + '0';
                char end_pos = j + '0';
                str = str + '(' + r_pos + ',' + start_pos + ")(" + r_pos + ',' + end_pos + ')';
                v.push_back(str);
            }
        }
    }
}

void horizontalPermutation(char **arr, int row, int col, vector<string> &v)
{
    // genrate strings by combining horizontally placed characters from array
    //  and get substring of the strings generated
    string str;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            str += arr[i][j];

        getSubtrings(str, i, v);
        reverseString(str);
        getSubtrings(str, i, v);
        str.clear();
    }
}
void verticalPermutation(char **arr, int row, int col, vector<string> &v)
{
    // genrate strings by combining vertical placed characters from array
    // and get substring of the strings generated
    string str;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            str += arr[j][i];

        getSubtrings(str, i, v);
        reverseString(str);
        getSubtrings(str, i, v);
        str.clear();
    }
}

void diagonalPermutation(char **arr, int row, int col, vector<string> &v)
{
    // genrate strings by combining diagonally placed characters from array
    // and get substring of the strings generated
    string str;
    // left diagonal
    for (int i = 0; i < row - 1; i++)
    {
        str.clear();
        for (int j = 0; j < col - i; j++)
            str += arr[j][i + j];
        getSubtrings(str, i, v);
        reverseString(str);
        getSubtrings(str, i, v);
        str.clear();
        if (i)
        {
            for (int j = 0; j < col - i; j++)
                str += arr[i + j][j];
            getSubtrings(str, i, v);
            reverseString(str);
            getSubtrings(str, i, v);
        }
    }
    // right diagonal
    for (int i = 0; i < row - 1; i++)
    {
        str.clear();
        for (int j = 0; j < col - i; j++)
            str += arr[row - j - i - 1][j];
        getSubtrings(str, i, v);
        reverseString(str);
        getSubtrings(str, i, v);
        str.clear();
        if (i)
        {

            for (int j = 0; j < col - i; j++)
                str += arr[row - j - 1][i + j];
            getSubtrings(str, i, v);
            reverseString(str);
            getSubtrings(str, i, v);
        }
    }
}

void getAllpermutations(char **arr, int _row, int _col, vector<string> &_v)
{
    // gets all [horizontal, vertical, diagonal] permutations
    horizontalPermutation(arr, _row, _col, _v);
    verticalPermutation(arr, _row, _col, _v);
    diagonalPermutation(arr, _row, _col, _v);
}
