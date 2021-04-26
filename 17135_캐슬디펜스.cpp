#include <algorithm>
#include <iostream>
#include <math.h>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = {0, -1, 0};
int dy[4] = {-1, 0, 1};
int n, m, d;
int arr[16][16];

int ans;
int tempArr[16][16];
bool check[16][16];
queue<pair<int, int>> q;
void copyArr()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tempArr[i][j] = arr[i][j];
            check[i][j] = false;
        }
    }
}
void simulation(int x, int y, int z)
{
    int pos = n;
    int kill = 0;
    bool visit[16][16];
    // 궁수의 가로 위치
    int archer[3] = {x, y, z};

    copyArr();

    
    while (pos > 0)
    {
        // i번째 궁수부터
        for (int i = 0; i < 3; i++)
        {
            memset(visit, false, sizeof(visit));

            q = queue<pair<int, int>>();
            int sx = pos - 1;
            int sy = archer[i];
            q.push({sx, sy});

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                visit[x][y] = true;
                if (tempArr[x][y])
                {
                    check[x][y] = true;
                    break;
                }
                for (int j = 0; j < 3; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (visit[nx][ny])
                        continue;
                    if ((abs(archer[i] - ny) + abs(pos - nx)) <= d)
                    {
                        q.push({nx, ny});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check[i][j])
                    tempArr[i][j] = 0;
            }
        }
        pos--;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (check[i][j])
                kill++;

    ans = max(ans, kill);
}
int main()
{
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                simulation(i, j, k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}