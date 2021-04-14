#include <cstring>
#include <iostream>
using namespace std;

int ice[301][301];
int info[301][301];
bool visit[301][301];

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool isEmptyIce()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] > 0)
                return false;
        }
    }
    return true;
}

void setInfo()
{
    memset(info, 0, sizeof(info));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] <= 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (ice[nx][ny] == 0)
                    info[i][j]++;
            }
        }
    }
}

void dfs(int x, int y)
{
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visit[nx][ny] || ice[nx][ny] == 0)
            continue;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        dfs(nx, ny);
    }
}
int getArea()
{
    memset(visit, false, sizeof(visit));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] <= 0)
                continue;
            if (visit[i][j])
                continue;
            dfs(i, j);
            cnt++;
        }
    }
    return cnt;
}

void melt()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] <= 0)
                continue;
            ice[i][j] -= info[i][j];
            if (ice[i][j] < 0)
                ice[i][j] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
        }
    }
    int year = 0;
    bool flag = false;
    while (!isEmptyIce())
    {
        // 주변 바닷물의 개수구함
        setInfo();
        melt();
        year++;

        int area = getArea();
        if (area >= 2)
        {
            cout << year;
            exit(0);
        }
    }
    cout << 0;

    return 0;
}