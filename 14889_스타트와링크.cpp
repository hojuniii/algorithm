#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int score[21][21];
bool team[21];
int minDiff = 987654321;
int n;
void comb(int cnt, int pos)
{
    if (cnt == n / 2)
    {
        int start = 0;
        int link = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (team[i] && team[j])
                {
                    start += score[i][j];
                    start += score[j][i];
                }
                else if (!team[i] && !team[j])
                {
                    link += score[i][j];
                    link += score[j][i];
                }
            }
        }
        int diff = abs(start - link);
        if (minDiff > diff)
            minDiff = min(minDiff, diff);
        return;
    }
    for (int i = pos; i < n; i++)
    {
        team[i] = true;
        comb(cnt + 1, i + 1);
        team[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> score[i][j];
        }
    }
    comb(0, 1);
    cout << minDiff << endl;

    return 0;
}