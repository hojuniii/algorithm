#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 987654321
using namespace std;

int s;
int current = 1;
int temp = 0;
int cnt = 0;
int ans = MAX;
queue<pair<int, int>> q;

void save()
{
    temp = current;
}
int paste(int n)
{
    return temp + current;
}
int del(int n)
{
    return n - 1;
}

void bfs()
{
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a == s)
        {
            ans = min(ans, b);
        }
        for (int i = 0; i < 3; i++)
        {
            switch (i)
            {
            case 0:
            {
                save();
                break;
            }
            case 1:
            {
                if (temp == 0)
                    continue;
                int c = paste(a);
                q.push({c, b + 1});
                break;
            }
            case 2:
            {
                q.push({del(a), b + 1});
                break;
            }
            }
        }
    }
}

int main()
{
    cin >> s;
    q.push({1, 0});
    bfs();
    cout << ans << endl;
}