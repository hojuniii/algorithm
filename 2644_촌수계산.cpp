#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
bool visit[101];
int n, m, a, b;
int depth[101];

queue<int> q;
void bfs(int i)
{
    visit[i] = true;
    q.push(i);
    int temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (arr[temp][j] && !visit[j])
            {
                q.push(j);
                visit[j] = true;
                depth[j] = depth[temp] + 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    bfs(a);

    if (depth[b] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << depth[b];
    }

    return 0;
}