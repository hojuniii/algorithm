#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool used[51];
vector<int> v;
string str;
int len, maxNum;
void dfs(int pos)
{
    if (pos == len)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        exit(0);
    }

    int num;
    string s = "";

    for (int i = pos; i <= pos + 1; i++)
    {
        s = s + str[i];
        num = stoi(s);
        if (used[num])
            continue;
        if (maxNum < num)
            continue;
        used[num] = true;
        v.push_back(num);
        dfs(i + 1);
        used[num] = false;
        v.pop_back();
    }
}
int main()
{
    cin >> str;
    len = str.length();
    if (len > 9)
    {
        maxNum = 9 + (len - 9) / 2;
    }
    else
    {
        maxNum = len;
    }

    dfs(0);
}