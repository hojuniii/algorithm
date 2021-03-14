#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m, ans = 987654321;
char board[10][10];
bool checkRed[10][10];
bool checkBlue[10][10];
int ex, ey;
bool flag = false;

// 하 상 좌 우
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int rx, int ry, int bx, int by, int cnt)
{
    if (rx == ex && ry == ey)
    {
        flag = true;
        return;
    }
    if (cnt > 10)
        return;
    if (checkRed[rx][ry] && checkRed[bx][by])
        return;
    int nrx = rx, nry = ry, nbx = bx, nby = by;
    for (int i = 0; i < 4; i++)
    {
        while (nrx < 0 || nry < 0 || nrx >= n || nry >= m)
        {
            nrx = rx + dx[i];
            nry = ry + dy[i];
        }
        while (nbx < 0 || nby < 0 || nbx >= n || nby >= m)
        {
            nbx = bx + dx[i];
            nby = by + dy[i];
        }
    }
}

int main()
{
    int rx, ry, bx, by;
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                rx = i, ry = j;
            if (board[i][j] == 'B')
                bx = i, by = j;
            if (board[i][j] == '0')
                ex = i, ey = j;
        }
    }
    bfs(rx, ry, bx, by, 0);
    if (flag)
    {
        cout << 10 - ans;
    }
    else
    {
        cout << -1;
    }
}