#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX 100000 + 1
using namespace std;

int n, k;
int minSec = 0;
int cnt = 0;
bool visit[MAX];

int bfs(int n, int k)
{
    queue<pair<int, int>> q;

    q.push({n, 0});
    visit[n] = true;

    while (!q.empty())
    {
        int curLoc = q.front().first;
        int curSec = q.front().second;
        q.pop();
        visit[curLoc] = true;

        if (minSec && minSec == curSec && curLoc == k)
        {
            cnt++;
        }

        if (!minSec && curLoc == k)
        {
            minSec = curSec;
            cnt++;
        }

        int plus = curLoc + 1;
        int minus = curLoc - 1;
        int mul = curLoc * 2;

        if (plus < MAX && !visit[plus])
            q.push({plus, curSec + 1});
        if (minus >= 0 && !visit[minus])
            q.push({minus, curSec + 1});
        if (mul < MAX && !visit[mul])
            q.push({mul, curSec + 1});
    }

    return minSec;
}

int main()
{
    memset(visit, false, sizeof(visit));
    cin >> n >> k;

    cout << bfs(n, k) << endl;
    cout << cnt << endl;

    return 0;
}