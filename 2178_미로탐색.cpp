#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
bool visit[101][101];
int dist[101][101];
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void bfs()
{
    int nextX;
    int nextY;

    visit[1][1] = true;
    dist[1][1] = 1;
    q.push({1, 1});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (y == m && x == n)
        {
            printf("%d", dist[x][y]);
            return;
        }

        visit[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            nextX = x + dx[i];
            nextY = y + dy[i];
            dist[nextX][nextY] = dist[x][y] + 1;

            if (nextX < 0 || nextY < 0 || nextX > n || nextY > m)
                continue;
            if (!visit[nextX][nextY] && arr[nextX][nextY] == 1)
            {
                q.push({nextX, nextY});
                visit[nextX][nextY] = true;
            }
        }
    }
}

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    bfs();

    return 0;
}