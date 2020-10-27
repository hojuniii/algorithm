#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool visited[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> v;
int cnt;
int n;
int map[26][26];

void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (map[nx][ny] == true && !visited[nx][ny])
                dfs(nx, ny);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == true && !visited[i][j])
            {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d\n", v[i]);
    }

    return 0;
}