#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int map[301][301];
bool visit[301][301];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
queue<pair<int, int>> q;
int t, l;
int sx, sy, ex, ey;

void bfs(int sx, int sy)
{

    q.push({sx, sy});
    visit[sx][sy] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                continue;
            if (visit[nx][ny])
                continue;
            visit[nx][ny] = true;
            q.push({nx, ny});
            map[nx][ny] = map[x][y] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

        cin >> l;

        cin >> sx >> sy;
        cin >> ex >> ey;

        bfs(sx, sy);
        cout << map[ex][ey] << endl;
    }

    return 0;
}