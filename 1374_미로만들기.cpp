#include <iostream>
#include <string>
using namespace std;

bool arr[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    string str;
    int len;

    cin >> len;
    cin >> str;

    int sx = 50, sy = 50;
    arr[sx][sy] = true;
    int dir = 0;

    int l = 50, r = 50, u = 50, d = 50;

    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        if (c == 'R')
        {
            dir = (dir + 1) % 4;
        }
        else if (c == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else
        {
            sx += dx[dir];
            sy += dy[dir];
            arr[sx][sy] = true;

            l = min(l, sy);
            u = min(u, sx);
            d = max(d, sx);
            r = max(r, sy);
        }
    }

    for (int i = u; i <= d; i++)
    {
        for (int j = l; j <= r; j++)
        {
            if (arr[i][j])
                cout << '.';
            else
                cout << '#';
        }
        cout << endl;
    }
}