#include <cstring>
#include <iostream>
using namespace std;

int arr[1001];
bool visit[1001];

void dfs(int v)
{
    visit[v] = true;

    if (!visit[arr[v]])
        dfs(arr[v]);
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));

        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                dfs(i);
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}