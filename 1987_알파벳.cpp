#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int r, c;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char arr[20][20];
bool temp[26];
bool used[26];
bool visit[20][20];
int ans = 0;

void dfs(int x, int y, int length)
{
    ans = max(ans, length);
    visit[x][y] = true;
    used[arr[x][y] - 65] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (visit[nx][ny] || used[arr[nx][ny] - 65])
            continue;

        char next = arr[nx][ny];
        dfs(nx, ny, length + 1);
    }
    
    // 탐색이 끝나면 현재 알파벳 사용을 무른다
    visit[x][y] = false;
    used[arr[x][y] - 65] = false;
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
    cout << ans << endl;

    return 0;
}