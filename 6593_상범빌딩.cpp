#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct area
{
    int x, y, z, cnt = 0;

    area(int a, int b, int c, int d)
    {
        z = a, x = b, y = c, cnt = d;
    }
};

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int l, r, c;
int map[30][30][30];
bool visit[30][30][30];
int sx, sy, sz, ex, ey, ez;
bool canExit = false;

void bfs(int z, int x, int y)
{
    visit[z][x][y] = true;
    queue<area> q;
    q.push({z, x, y, 0});

    while (!q.empty())
    {
        int tz = q.front().z;
        int tx = q.front().x;
        int ty = q.front().y;
        int tc = q.front().cnt;

        visit[tz][tx][ty] = true;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = tz + dz[i];
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (nz < 0 || nx >= r || ny >= c || nx < 0 || ny < 0 || nz >= l)
                continue;
            if (visit[nz][nx][ny])
                continue;
            if (map[nz][nx][ny] == -1)
                continue;
            if (nz == ez && nx == ex && ny == ey)
                canExit = true;
            q.push({nz, nx, ny, tc + 1});
            map[nz][nx][ny] = tc + 1;
            visit[nz][nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        canExit = false;
        memset(map, -1, sizeof(map));
        memset(visit, false, sizeof(visit));

        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    char c;
                    cin >> c;
                    if (c == 'S')
                    {
                        sx = j, sy = k, sz = i;
                        map[i][j][k] = 0;
                    }
                    else if (c == 'E')
                    {
                        ex = j, ey = k, ez = i;
                        map[i][j][k] = 0;
                    }
                    else if (c == '.')
                    {
                        map[i][j][k] = 0;
                    }
                }
            }
        }

        bfs(sz, sx, sy);

        if (canExit)
        {
            cout << "Escaped in " << map[ez][ex][ey] << " minute(s).\n";
        }
        else
        {
            cout << "Trapped!\n";
        }
    }
}
