#include <iostream>
using namespace std;

int arr[5][5];
int visit[5][5];
int r, c, k;
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt)
{
    if (cnt > k)
        return;
    if (x == 0 && y == c - 1)
    {
        if (cnt == k)
            ans++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (visit[nx][ny] || arr[x][y] == -1)
            continue;
        visit[x][y] = true;
        dfs(nx, ny, cnt + 1);
        visit[x][y] = false;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            cin >> c;
            if (c == 'T')
                arr[i][j] = -1;
        }
    }

    dfs(r - 1, 0, 1);
    cout << ans << endl;

    return 0;
}