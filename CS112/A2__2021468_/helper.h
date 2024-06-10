#include <iostream>
#include <string>
using namespace std;
// this is a change in file to check on git hub
size_t Mystrlen(const char *s)
{
    size_t len = 0;
    // iterating and incrementing{len} through s until '\0' occurs
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        len++;
    }
    return len;
}

char *Mystrcpy(char *s1, const char *s2)
{
    // calling Mystrlen to find length of s2
    int size = Mystrlen(s2);
    // creating new arr of size{size} copying all chars of s2 into arr
    char *arr = new char[size];
    for (int i = 0; i < size; i++)
        arr[i] = *(s2 + i);
    s1 = arr;
    delete[] arr;

    return s1;
}

char *Mystrncpy(char *s1, const char *s2, size_t n)
{
    // creating new arr of size n and copying chars of s2 into arr
    char *arr = new char[n];
    for (int i = 0; i < n; i++)
        arr[i] = *(s2 + i);
    s1 = arr;
    delete[] arr;

    return s1;
}

char *Mystrcat(char *s1, const char *s2)
{
    // calling Mystrlen to find lenght of s1 and s2
    int s1_size = Mystrlen(s1);
    int s2_size = Mystrlen(s2);
    // creating a new arr of s1(size)+s2(size)
    char *arr = new char[s1_size + s2_size];
    // loop to copy char of s1 and s2 in arr respectively
    for (int j = 0; j < s1_size + s2_size; j++)
    {
        if (j < s1_size)
            arr[j] = *(s1 + j);
        else
            arr[j] = *(s2 + j - 1);
    }
    s1 = arr;
    delete[] arr;
    return s1;
}

char *Mystrncat(char *s1, const char *s2, size_t n)
{
    // caliing Mystrlen to find the current length of string
    int s1_size = Mystrlen(s1);
    // creating a new arry of current size + n{the the given size}
    char *arr = new char[s1_size + n];
    // loop to copy{concatenate} s2 into s1
    for (int j = 0; j < s1_size + n; j++)
    {
        if (j < s1_size)
            arr[j] = *(s1 + j);
        else
            arr[j] = *(s2 + j - 1);
    }
    s1 = arr;
    delete[] arr;
    return s1;
}

int Mystrcmp(const char *s1, const char *s2)
{
    int count = 0;
    bool check = false;
    // loop to compare ascii value of chars ,if greater then count is incremented
    // else it incremented and multiplied by -1 to make it negative
    for (int i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
    {
        if (int(*(s1 + i)) < int(*(s2 + i)))
            count += (int(*(s1 + i))) * -1;
        else if (int(*(s1 + i)) > int(*(s2 + i)))
            count += int(*(s1 + i));
    }
    // loop to iterate char by char and check for equality
    // Anywhere inequality occurs. loop breaks and equalityCheck is set to false
    for (int i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
    {
        if (int(*(s1 + i)) == int(*(s2 + i)))
            check = true;
        else
        {
            check = false;
            break;
        }
    }
    // returns zero if equal else return count value
    if (check)
        return 0;
    else
        return count;
}

int Mystrncmp(const char *s1, const char *s2, size_t n)
{
    int count = 0;
    bool equalityCheck = false;
    // loop to compare ascii value of chars upto n,if greater then count is incremented
    // else it incremented and multiplied by -1 to make it negative
    for (int i = 0; i < n && *(s2 + i) != '\0'; i++)
    {
        if (int(*(s1 + i)) < int(*(s2 + i)))
            count += (int(*(s1 + i))) * -1;
        else if (int(*(s1 + i)) > int(*(s2 + i)))
            count += int(*(s1 + i));
    }
    // loop to iterate char by char upto n and check for equality
    // Anywhere inequality occurs. loop breaks and equalityCheck is set to false
    for (int i = 0; i < n && *(s2 + i) != '\0'; i++)
    {
        if (*(s1 + i) == *(s2 + i))
            equalityCheck = true;
        else
        {
            equalityCheck = false;
            break;
        }
    }
    // returns zero if equal else return count value
    if (equalityCheck)
        return 0;
    else
        return count;
}
char *Mystrtok(char *s1, const char *s2)
{ // Previous variable stores the index of string when last time funtion was called
    static int previous = 0;
    // counter variable counts the length of string until the delimiter is reached
    int counter = 0;
    for (int i = 0; *(s1 + i + previous) != *(s2) && *(s1 + i + previous) != '\0'; i++)
        counter++;

    // creating a new arr of counter size and coping chars of s1 into it
    char *arr = new char[counter];
    for (int i = 0; i < counter; i++)
        arr[i] = *(s1 + i + previous);

    s1 = arr;
    delete[] arr;
    // Incrementing counter to remove the delimiter from string
    previous += (++counter);

    return s1;
}
