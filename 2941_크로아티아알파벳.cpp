#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> dictionary = {
        "c=",
        "c-",
        "dz=",
        "d-",
        "lj",
        "nj",
        "s=",
        "z="};
    string str;
    int ans = 0;

    cin >> str;

    for (int i = 0; i < dictionary.size(); i++)
    {
        while (1)
        {
            int idx = str.find(dictionary[i]);

            if (idx != string::npos)
            {
                str.replace(idx, dictionary[i].length(), "*");
            }
            else
            {
                break;
            }
        }
    }
    cout << str.length();
}