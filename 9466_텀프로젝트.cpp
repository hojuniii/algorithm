#include <cstring>
#include <iostream>
using namespace std;

int arr[100001];
bool visit[100001];
bool finish[100001];
int n, t, cnt = 0;

void dfs(int node)
{
    visit[node] = true;
    int next = arr[node];

    if (!visit[next])
        dfs(next);
    else if (!finish[next])
    {
        while (next != node)
        {
            cnt++;
            next = arr[next];
        }
        cnt++;
    }
    finish[node] = true;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cnt = 0;
        memset(visit, false, sizeof(visit));
        memset(finish, false, sizeof(finish));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            dfs(i);
        }
        cout << n - cnt << endl;
    }

    return 0;
}