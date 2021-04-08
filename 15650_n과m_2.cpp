#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visit[10];

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= n; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            arr[cnt] = i;
            dfs(i, cnt + 1);
            visit[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);

    return 0;
}