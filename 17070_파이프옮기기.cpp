#include <iostream>
using namespace std;

pair<int, int> dir[4] = {{0, 1}, {1, 0}, {1, 1}};

int n;
int arr[16][16];
int ans = 0;

void bfs(int x, int y, int pipe)
{
    if (x == n - 1 && y == n - 1)
    {
        ans++;
        return;
    }

    // i : 파이프의 상태
    for (int i = 0; i < 3; i++)
    {
        if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0))
            continue;

        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx >= n || ny >= n || arr[nx][ny] == 1)
            continue;

        if ((i == 2 && arr[x][y + 1] == 1) || (i == 2 && arr[x + 1][y] == 1))
            continue;

        bfs(nx, ny, i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    bfs(0, 1, 0);

    cout << ans << endl;

    return 0;
}