#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char map[60][60];
char chese[8][8];
int n, m;

int solve()
{
    int bCnt = 0;
    int wCnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //w
            if ((i + j) % 2 == 0 && chese[i][j] == 'B')
            {
                wCnt++;
            }
            if ((i + j) % 2 == 1 && chese[i][j] == 'W')
            {
                wCnt++;
            }

            //b
            if ((i + j) % 2 == 0 && chese[i][j] == 'W')
            {
                bCnt++;
            }
            if((i + j) % 2 == 1 && chese[i][j] == 'B')
            {
                bCnt++;
            }
        }
    }

    return min(bCnt, wCnt);
}

void input(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chese[i][j] = map[x + i][y + j];
        }
    }
}
int main()
{
    int ans = 987654321;
    memset(map, 0, sizeof(map));
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            input(i, j);

            ans = min(ans, solve());
        }
    }

    cout << ans << endl;
}