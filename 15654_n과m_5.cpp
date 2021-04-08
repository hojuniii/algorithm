#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[8];
int ans[8];
bool used[8];
void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            ans[cnt] = arr[i];
            dfs(cnt + 1);
            used[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0);

    return 0;
}