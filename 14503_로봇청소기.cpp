#include <iostream>
#include <queue>
using namespace std;

// 북 - 동 - 남 - 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bdx[] = {1, 0, -1, 0};
int bdy[] = {0, -1, 0, 1};

queue<pair<int, int>> q;
int n, m, r, c, d;
int visit[50][50];
int sx, sy, cnt = 0;
bool stop = false;

void dfs(int x, int y, int d)
{
    if (visit[x][y] == 1)
        return;

    if (visit[x][y] == 0)
    {
        visit[x][y] = 2;
        cnt++;
    }

    for (int i = 0; i < 4; i++)
    {
        int nd = d - 1 < 0 ? 3 : d - 1;
        int nx = x + dx[nd];
        int ny = y + dy[nd];

        if (visit[nx][ny] == 0)
        {
            dfs(nx, ny, nd);
            return;
        }
        else
        {
            d = nd;
        }
    }

    int bx = x + bdx[d];
    int by = y + bdy[d];
    if (visit[bx][by] == 1)
        return;
    dfs(bx, by, d);
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> visit[i][j];
        }
    }

    dfs(r, c, d);

    cout << cnt << endl;
    return 0;
}