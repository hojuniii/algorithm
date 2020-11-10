#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
int minPop = 987654321;
int maxPop = -1;

int res = 987654321;
int n, d1, d2, x, y;
int calc(int x, int y, int d1, int d2)
{
    int areas[5] = {
        0,
    };
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))
            {
                areas[0] += map[r][c];
            }
            else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x)))
            {
                areas[1] += map[r][c];
            }
            else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && r - c <= x - y + 2 * d1))
            {
                areas[2] += map[r][c];
            }
            else if (r > x + d2 && c >= y - d1 + d2 && !(r > x + d2 && r + c <= x + y + 2 * d2))
            {
                areas[3] += map[r][c];
            }
            else
            {
                areas[4] += map[r][c];
            }
        }
    }

    sort(areas, areas + 5);
    maxPop = areas[4];
    minPop = areas[0];

    if (res > maxPop - minPop)
    {
        res = maxPop - minPop;
    }

    return res;
}
int main()
{
    memset(map, 0, sizeof(map));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int pop;
            cin >> pop;
            map[i][j] = pop;
        }
    }

    for (int x = 1; x <= n - 2; x++)
    {
        for (int y = 2; y <= n - 1; y++)
        {
            for (int d1 = 1; x + d1 <= n - 1 && y - d1 >= 1; d1++)
            {
                for (int d2 = 1; x + d1 + d2 <= n && y + d2 <= n; d2++)
                {
                    res = min(res, calc(x, y, d1, d2));
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}