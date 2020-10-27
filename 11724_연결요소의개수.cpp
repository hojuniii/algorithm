#include <iostream>
using namespace std;

int graph[1001][1001];
bool visit[1001];

int n, m;
int cnt;
void dfs(int node)
{
    visit[node] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i] && graph[node][i] == 1)
        {
            visit[i] = true;
            dfs(i);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
