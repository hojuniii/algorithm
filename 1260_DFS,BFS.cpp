#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
bool check[1001];
int n, m, v;

void dfs(int v)
{
    check[v] = true;
    printf("%d ", v);
    for (int i = 1; i <= n; i++)
    {
        if (arr[v][i] == 1 && !check[i])
        {
            dfs(i);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    check[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for (int i = 1; i <= n; i++)
        {
            if (arr[x][i] == 1 && !check[i])
            {
                check[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &v);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x][y] = true;
    }

    dfs(v);
    printf("\n");
    memset(check, false, sizeof(check));

    bfs(v);

    return 0;
}