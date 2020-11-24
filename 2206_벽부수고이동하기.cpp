#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int arr[1001][1001];
int visit[2][1001][1001];
queue<pair<int, pair<int, int>>> q;

int bfs()
{
    q.push({1, {1, 1}});
    visit[1][1][1] = 1;

    while (!q.empty())
    {
        int crash = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == n && y == m)
        {
            return visit[crash][x][y];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || ny <= 0 || nx > n || ny > m)
                continue;

            //벽이 있고 아직 뚫을 수 있으면
            if (arr[nx][ny] == 1 && crash)
            {
                visit[0][nx][ny] = visit[crash][x][y] + 1;
                q.push({0, {nx, ny}});
            }
            //벽이 없고, 방문하지 않았으면
            else if (arr[nx][ny] == 0 && !visit[crash][nx][ny])
            {
                visit[crash][nx][ny] = visit[crash][x][y] + 1;
                q.push({crash, {nx, ny}});
            }
        }
    }

    return -1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    printf("%d", bfs());
    return 0;
}