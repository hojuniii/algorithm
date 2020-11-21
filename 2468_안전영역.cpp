#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int arr[100][100];
bool visit[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n;
int maxHeight = -1, minHeight = 987654321;

void dfs(int x, int y, int k)
{
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (visit[nx][ny] || arr[nx][ny] <= k)
            continue;
        visit[nx][ny] = true;
        dfs(nx, ny, k);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            maxHeight = max(maxHeight, arr[i][j]);
            minHeight = min(minHeight, arr[i][j]);
        }
    }

    int maxCnt = 1;
    for (int k = minHeight; k < maxHeight; k++)
    {
        int cnt = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > k && !visit[i][j])
                {
                    visit[i][j] = true;
                    cnt++;
                    dfs(i, j, k);
                }
            }
        }
        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt << endl;
}