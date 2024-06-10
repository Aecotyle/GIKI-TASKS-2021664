#ifndef HEADER_H
#define HEADER_H
#include "./header.h"
#endif

// ---------------------------
// Group
// ---------------------------
// Reg: 2021250 (Itba Malahat)
// Reg: 2021468 (Talha Imtiaz)
// ---------------------------

int main()
{
    trie t;
    int no_rows, no_cols;
    vector<string> permutations;
    // inerting wordlist to the tries data structure
    loadWordsInDictionary(t);
    cout << "Enter the no. of rows: ";
    cin >> no_rows;
    cout << "Enter the no. of columns: ";
    cin >> no_cols;

    // creating a dynamic array
    char **arr = new char *[no_rows];
    for (int i = 0; i < no_rows; i++)
    {
        arr[i] = new char[no_cols];
    }

    cout << "input: ";
    input(arr, no_rows, no_cols);
    print(arr, no_rows, no_cols);
    getAllpermutations(arr, no_rows, no_cols, permutations);
    if (writeValidWordinFile(t, permutations))
        cout << "\nWriting to file was successful\n";
    else
        cout << "\n--A technical Error occured\n";

    return 0;
}