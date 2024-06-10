#include <iostream>
#include <string>
using namespace std;
int main()
{
    string posArr[10] = {"happy", "good", "sweet", "love", "hope", "positivity", "truth", "calm", "beautiful", "patience"};
    string negArr[10] = {"sad", "evil", "harsh", "hate", "hopeless", "negativity", "lie", "upset", "ugly", "impatient"};
    string input;
    int posCount = 0;
    int negCount = 0;

    cout << "Enter your tweet" << endl;
    getline(cin, input);
    string tempStr;
    for (int i = 0; i <= input.length(); i++)
    {
        cout << " i: " << i << "  tempStr : " << tempStr << endl;

        if (input[i] == ' ' || i == input.length())
        {
            for (int j = 0; j < 10; j++)
            {
                if (tempStr == posArr[j])
                    posCount++;
                if (tempStr == negArr[j])
                    negCount++;
            }
            tempStr.clear();
        }

        else
            tempStr = tempStr + input[i];
    }

    cout << "positivity : " << posCount << endl;
    cout << "negativity : " << negCount << endl;
    return 0;
}