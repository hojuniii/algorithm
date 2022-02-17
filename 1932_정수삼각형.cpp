#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[501][501];
int ans = -1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][0];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i - 1][j - 1] + dp[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans;
}
