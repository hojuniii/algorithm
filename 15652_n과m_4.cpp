#include <iostream>
using namespace std;

int arr[8];
bool used[8];
int n, m;
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
        used[i] = true;
        arr[cnt] = i;
        dfs(i, cnt + 1);
        used[i] = false;
    }
}
int main()
{
    cin >> n >> m;
    dfs(1, 0);
}