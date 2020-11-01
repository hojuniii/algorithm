#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[51][51];
int fx, fy;
int sx, sy;
int maxDistance = -1;
int n, m;
bool check[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;
    bool visit[51][51] = {
        false,
    };
    visit[x][y] = true;
    q.push({0, {x, y}});

    while (!q.empty())
    {

        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int dist = q.front().first;
        // visit[cx][cy] = true;
        q.pop();

        if (maxDistance < dist)
        {
            maxDistance = dist;
            fx = cx;
            fy = cy;
            sx = x;
            sy = y;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (map[nx][ny] == 'W' || visit[nx][ny])
                continue;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            q.push({dist + 1, {nx, ny}});
            visit[nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] || map[i][j] == 'W')
                continue;
            bfs(i, j);
            check[i][j] = true;
        }
    }

    cout << maxDistance << endl;
}