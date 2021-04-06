#include <algorithm>
#include <iostream>
using namespace std;

char arr[20][20];
bool visited[20][20];
bool used[26];
int r, c;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

void dfs(int x, int y, int length)
{
    visited[x][y] = true;
    used[arr[x][y] - 'A'] = true;
    ans = max(ans, length);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny] || used[arr[nx][ny] - 'A'])
            continue;
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;

        dfs(nx, ny, length + 1);
    }

    visited[x][y] = false;
    used[arr[x][y] - 'A'] = false;
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0, 1);
    cout << ans;
}