#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int arr[100000];
bool visit[100000];
int minDist = 987654321;
queue<pair<int, int>> q;
int bfs(int s)
{
    q.push({s, 0});
    visit[s] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        visit[cur] = true;
        q.pop();

        if (cur == k)
        {
            minDist = min(minDist, cnt);
            return cnt;
        }

        if (cur * 2 <= 100000 && !visit[cur * 2])
        {
            q.push({cur * 2, cnt + 1});
            visit[cur * 2] = true;
        }
        if (cur + 1 <= 100000 && !visit[cur + 1])
        {
            q.push({cur + 1, cnt + 1});
            visit[cur + 1] = true;
        }
        if (cur - 1 >= 0 && !visit[cur - 1])
        {
            q.push({cur - 1, cnt + 1});
            visit[cur - 1] = true;
        }
    }

    return minDist;
}

int main()
{
    memset(visit, false, sizeof(visit));
    cin >> n >> k;

    cout << bfs(n);

    return 0;
}