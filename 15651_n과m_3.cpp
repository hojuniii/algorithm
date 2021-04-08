#include <iostream>
using namespace std;

int arr[7];
bool used[7];
int n, m;
void dfs(int cnt)
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

    for (int i = 1; i <= n; i++)
    {
        used[i] = true;
        arr[cnt] = i;
        dfs(cnt + 1);
        used[i] = false;
    }
}
int main()
{
    cin >> n >> m;
    dfs(0);
}