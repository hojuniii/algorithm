#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int height[301][301];
int decrease[301][301];
bool visit[301][301];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void calc(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (height[nx][ny] == 0)
        {
            decrease[x][y]++;
        }
    }
}

void melt()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (height[i][j] == 0)
                continue;
            height[i][j] -= decrease[i][j];
            if (height[i][j] < 0)
                height[i][j] = 0;
        }
    }
}

bool all_melted()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (height[i][j] > 0)
                return false;
        }
    }
    return true;
}

void dfs(int x, int y)
{
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (height[nx][ny] > 0 && !visit[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

// dfs 수행 횟수 -> 연결 개수
int numberOfAdj()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && height[i][j] > 0)
            {
                dfs(i, j);
                res++;
            }
        }
    }
    return res;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> height[i][j];
        }
    }

    int cnt = 0;
    while (!all_melted())
    {
        // 덩어리 계산
        if (numberOfAdj() >= 2)
        {
            cout << cnt << endl;
            exit(0);
        }

        for (int i = 0; i < 300; i++)
        {
            memset(decrease[i], 0, sizeof(decrease[i]));
            memset(visit[i], false, sizeof(visit[i]));
        }

        // 접해있는 바닷물 개수 계산
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (height[i][j] == 0)
                    continue;
                calc(i, j);
            }
        }
        // 진행
        melt();
        cnt++;
    }
    cout << 0 << endl;

    return 0;
}