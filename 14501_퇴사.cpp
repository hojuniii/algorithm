#include <algorithm>
#include <iostream>
using namespace std;

int p[17] = { 0, };
int t[17] = { 0, };
int ans = 0;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--)
    {
        if (i + t[i] > n + 1)
            p[i] = p[i + 1];
        else
        {
            p[i] = max(p[i + 1], p[i] + p[i + t[i]]);
            ans = max(p[i], ans);
        }
    }

    cout << ans;

    return 0;
}