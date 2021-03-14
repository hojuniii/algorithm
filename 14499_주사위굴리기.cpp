#include <iostream>
using namespace std;

int arr[20][20];
int r, c;
int n, m, x, y;
int k;
int dice[6] = {0, 0, 0, 0, 0, 0};
int top, bottom;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int dir;
        cin >> dir;

        if (dir == 1)
        {
            if (y + 1 >= m)
                continue;
            y += 1;

            int temp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[2];
            dice[2] = dice[5];
            dice[5] = temp;

            if (arr[x][y] == 0)
            {
                arr[x][y] = dice[2];
            }
            else
            {
                dice[2] = arr[x][y];
                arr[x][y] = 0;
            }
            cout << dice[0] << endl;
        }
        else if (dir == 2)
        {

            if (y - 1 < 0)
                continue;
            y -= 1;

            int temp = dice[0];
            dice[0] = dice[5];
            dice[5] = dice[2];
            dice[2] = dice[4];
            dice[4] = temp;

            if (arr[x][y] == 0)
            {
                arr[x][y] = dice[2];
            }
            else
            {
                dice[2] = arr[x][y];
                arr[x][y] = 0;
            }
            cout << dice[0] << endl;
        }
        else if (dir == 3)
        {

            if (x - 1 < 0)
                continue;
            x -= 1;

            int temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = temp;

            if (arr[x][y] == 0)
            {
                arr[x][y] = dice[2];
            }
            else
            {
                dice[2] = arr[x][y];
                arr[x][y] = 0;
            }
            cout << dice[0] << endl;
        }
        else if (dir == 4)
        {

            if (x + 1 >= n)
                continue;

            x += 1;

            int temp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[1];
            dice[1] = temp;

            if (arr[x][y] == 0)
            {
                arr[x][y] = dice[2];
            }
            else
            {
                dice[2] = arr[x][y];
                arr[x][y] = 0;
            }
            cout << dice[0] << endl;
        }
    }

    return 0;
}