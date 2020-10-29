#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
char arr[101][101];
bool visit[101][101];
int cnt = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs(int x, int y, char c)
{
    char area = arr[x][y];
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny])
            continue;
        if (arr[nx][ny] != area)
            continue;
        dfs(nx, ny, arr[nx][ny]);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j])
                continue;
            dfs(i, j, arr[i][j]);
            cnt++;
        }
    }

    cout << cnt << ' ';

    memset(visit, false, sizeof(visit));
    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'R')
                arr[i][j] = 'G';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j])
                continue;
            dfs(i, j, arr[i][j]);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}