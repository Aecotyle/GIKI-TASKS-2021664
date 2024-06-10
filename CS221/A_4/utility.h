
#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

void input(char **arr, int row, int col)
{
    char x;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> x;
            arr[i][j] = tolower(x);
        }
    }
}
void reverseString(string &s)
{
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        temp = s[i] + temp;
    }
    s = temp;
}
void screenClear()
{
    for (int i = 0; i < 50; i++)
        cout << "\n";
}

void print(char **arr, int row, int col)
{
    screenClear();
    cout << "Your Input: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void loadWordsInDictionary(trie &_t)
{
    fstream file("wordlist.txt");
    if (file.is_open())
    {
        string str;
        while (getline(file, str))
        {
            string temp;
            for (int i = 0; i < str.length(); i++)
                temp += tolower(str[i]);
            if (temp.length() > 1)
                _t.insert(temp);
        }
    }
    else
    {
        cout << "Error in opening file\n";
    }
    file.close();
}

bool writeValidWordinFile(trie t, vector<string> permutations)
{
    fstream file("ValidWord.txt", ios::app);
    if (file.is_open())
    {
        cout << "\nList of valid words extracted from Array :\n";
        for (int i = 0; i < permutations.size(); i++)
        {
            string _s;
            // sperating position from string (tokenization)
            for (int j = 0; permutations[i][j] != '('; j++)
            {
                _s += permutations[i][j];
            }

            if (t.search(_s))
            {
                cout << permutations[i] << endl;
                file << permutations[i] << endl;
            }
        }
    }
    else
    {
        cout << "Error in opening ValidWord.txt";
        return false;
    }
    file.close();
    return true;
}