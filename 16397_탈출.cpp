#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, t, g;
int minTime = 100000;
bool check[100000];
queue<pair<int, int>> q;

int aButton(int num)
{
    return ++num;
}

int bButton(int num)
{
    int doubleNum = num * 2;
    if (doubleNum > 99999)
        return doubleNum;
    string s = to_string(doubleNum);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - '0' != 0)
        {
            s[i] -= (char)1;
            break;
        }
    }

    return stoi(s);
}

int bfs(int num)
{
    q.push({num, 0});
    check[num] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt > t)
        {
            break;
        }
        if (cur == g)
        {
            return cnt;
        }

        int tmpA = aButton(cur);

        if (tmpA <= 99999 && !check[tmpA])
        {
            q.push({tmpA, cnt + 1});
            check[tmpA] = true;
        }

        if (cur != 0)
        {
            int tmpB = bButton(cur);
            //N이 0 이면 버튼을 눌러도 그대로
            if (tmpB <= 99999 && !check[tmpB])
            {
                check[tmpB] = true;
                q.push({tmpB, cnt + 1});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> t >> g;
    int res = bfs(n);
    if (res == -1)
    {
        cout << "ANG" << endl;
    }
    else
    {
        cout << res << endl;
    }
}