#include <cstring>
#include <iostream>
using namespace std;

int k, s;
int arr[50];
int ans[50];
bool used[50];

void dfs(int num, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= k; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            ans[cnt] = arr[i];
            dfs(i, cnt + 1);
            used[i] = false;
        }
    }
}
int main()
{
    while (true)
    {
        memset(used, false, sizeof(used));
        memset(arr, 0, sizeof(arr));
        cin >> k;
        if (k == 0)
            break;

        for (int i = 1; i <= k; i++)
        {
            cin >> arr[i];
        }

        dfs(1, 0);
        cout << '\n';
    }
    return 0;
}