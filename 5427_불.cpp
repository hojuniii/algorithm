#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int w, h, sx, sy, n, cnt;
char building[1000][1000];
bool visit[1000][1000];
bool canExit = false;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> fq;
queue<pair<int, int>> sq;

void bfs(int sx, int sy)
{
    cnt = 0;
    visit[sx][sy] = true;
    sq.push({sx, sy});

    while (!sq.empty())
    {
        int sqSize = sq.size();
        int fqSize = fq.size();
        int x, y, nx, ny;

        cnt++;

        while (fqSize--)
        {
            x = fq.front().first;
            y = fq.front().second;
            fq.pop();
            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                    continue;
                if (building[nx][ny] == '#' || visit[nx][ny])
                    continue;
                fq.push({nx, ny});
                visit[nx][ny] = true;
            }
        }

        while (sqSize--)
        {
            x = sq.front().first;
            y = sq.front().second;
            sq.pop();
            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    canExit = true;
                    return;
                }
                if (building[nx][ny] == '#' || building[nx][ny] == '*' || visit[nx][ny])
                    continue;

                sq.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n--)
    {
        canExit = false;
        cnt = 0;
        memset(building, 0, sizeof(building));
        memset(visit, false, sizeof(visit));
        while (!fq.empty())
            fq.pop();
        while (!sq.empty())
            sq.pop();

        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> building[i][j];
                if (building[i][j] == '@')
                {
                    sx = i, sy = j;
                    building[i][j] = '.';
                }
                else if (building[i][j] == '*')
                {
                    fq.push({i, j});
                    visit[i][j] = true;
                }
            }
        }

        bfs(sx, sy);

        if (!canExit)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            cout << cnt << endl;
        }
    }
}