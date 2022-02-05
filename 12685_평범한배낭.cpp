#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, k;
int dp[101][100001];
int w[101];
int v[101];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            // w[i] - i번째 까지 담았을때 의 무게
            // j까지
            if (w[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][k];
}