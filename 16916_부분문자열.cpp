#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findFailure(string pattern)
{
    int m = pattern.length();
    vector<int> table(m);
    table[0] = 0;

    int i = 1;
    int j = 0;

    while (i < m)
    {

        if (pattern[i] == pattern[j])
        {
            table[i] = j + 1;
            i = j + 1;
            j += 1;
        }
        else if (j > 0)
        {
            j = table[j - 1];
        }
        else
        {
            table[i] = 0;
            i += 1;
        }
    }

    return table;
}

int main()
{
    bool ans = false;
    string s1, s2;
    cin >> s1 >> s2;

    if (strstr((char *)s1.c_str(), (char *)s2.c_str()) == NULL)
        cout << 0;
    else
        cout << 1;

    vector<int> failure_table = findFailure(s2);
    int n = s1.length();
    int m = s2.length();
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (s1[i] == s2[j])
        {
            if (j == m - 1)
            {
                ans = true;
                break;
            }
            j += 1;
            i += 1;
        }
        else if (j > 0)
        {
            j = failure_table[j - 1];
        }
        else if (j == 0)
            i += 1;
    }

    if (ans)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}