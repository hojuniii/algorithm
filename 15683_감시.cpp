#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 8
#define INF 987654321;
using namespace std;

int n, m, ans;
int arr[MAX][MAX];
int tmp[MAX][MAX];

vector<pair<int, int>> cctv;
int cctvDirection[MAX];
// 동 서 남 북
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void copyArr()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }
}

void spread(int x, int y, int d)
{
    int nx = x;
    int ny = y;
    while (true)
    {
        nx += dx[d];
        ny += dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            break;
        if (tmp[nx][ny] == 0)
        {
            tmp[nx][ny] = 7;
        }
        else if (tmp[nx][ny] == 6)
            break;
    }
}

void setCCTV()
{
    for (int i = 0; i < cctv.size(); i++)
    {
        int x = cctv[i].first;
        int y = cctv[i].second;

        switch (tmp[x][y])
        {
        case 1:
        {
            int dir = cctvDirection[i];
            spread(x, y, dir);
            break;
        }
        case 2:
        {
            if (cctvDirection[i] == 0)
            {
                spread(x, y, 0);
                spread(x, y, 1);
            }
            else
            {
                spread(x, y, 2);
                spread(x, y, 3);
            }
            break;
        }
        case 3:
        {
            if (cctvDirection[i] == 0)
            {
                spread(x, y, 0);
                spread(x, y, 3);
            }
            else if (cctvDirection[i] == 1)
            {
                spread(x, y, 0);
                spread(x, y, 2);
            }
            else if (cctvDirection[i] == 2)
            {
                spread(x, y, 1);
                spread(x, y, 3);
            }
            else if (cctvDirection[i] == 3)
            {
                spread(x, y, 1);
                spread(x, y, 2);
            }
            break;
        }
        case 4:
        {
            if (cctvDirection[i] == 0)
            {
                //동 서 북
                spread(x, y, 0);
                spread(x, y, 1);
                spread(x, y, 3);
            }
            else if (cctvDirection[i] == 1)
            {
                // 동 남 북
                spread(x, y, 0);
                spread(x, y, 2);
                spread(x, y, 3);
            }
            else if (cctvDirection[i] == 2)
            {
                // 동 서 남
                spread(x, y, 0);
                spread(x, y, 1);
                spread(x, y, 2);
            }
            else if (cctvDirection[i] == 3)
            {
                // 서 남 북
                spread(x, y, 1);
                spread(x, y, 2);
                spread(x, y, 3);
            }
            break;
        }
        case 5:
        {
            spread(x, y, 0);
            spread(x, y, 1);
            spread(x, y, 2);
            spread(x, y, 3);
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

int getMin()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 0)
                res++;
        }
    }
    return res;
}

void dfs(int idx, int cnt)
{
    if (cnt == cctv.size())
    {
        copyArr();
        setCCTV();
        ans = min(ans, getMin());
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;

    for (int k = 0; k < 4; k++)
    {
        if (arr[x][y] == 2 && k >= 2)
            continue;
        if (arr[x][y] == 5 && k >= 1)
            continue;
        cctvDirection[idx] = k;
        dfs(idx + 1, cnt + 1);
        cctvDirection[idx] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5)
            {
                cctv.push_back({i, j});
            }
        }
    }

    ans = INF;
    dfs(0, 0);
    cout << ans << '\n';
}