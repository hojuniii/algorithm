#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dx[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};
int arr[50][50];
int ans = 0;
vector<pair<int, int>> v;

int n, m;
bool visit[50][50];

int bfs(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    visit[x][y] = true;
    while (!q.empty())
    {
        int dist = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (arr[x][y] == 1)
        {
            return dist;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visit[nx][ny])
                continue;

            q.push({dist + 1, {nx, ny}});
            visit[nx][ny] = true;
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                v.push_back({i, j});
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;

        memset(visit, false, sizeof(visit));
        int temp = bfs(x, y);
        ans = max(ans, temp);
    }

    cout << ans;
}