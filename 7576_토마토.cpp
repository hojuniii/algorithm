#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Tomato
{
    int x, y;
};

int m, n, ans = 0;
int arr[1001][1001];
queue<Tomato> tomato;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs()
{
    while (!tomato.empty())
    {
        int x = tomato.front().x;
        int y = tomato.front().y;
        tomato.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (arr[nx][ny])
                continue;
            arr[nx][ny] = arr[x][y] + 1;
            tomato.push({nx, ny});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            arr[i][j] = val;
            if (val == 1)
            {
                tomato.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
            if (ans < arr[i][j])
                ans = arr[i][j];
        }
    }
    cout << ans - 1 << endl;

    return 0;
}