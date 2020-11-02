#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int r, c, n;
int timer;
int arr[201][201];

void afterSecond()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j]++;
                if (arr[i][j] == 3)
                {
                    arr[i][j] = -1;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx >= 1 && ny >= 1 && nx <= r && ny <= c)
                        {
                            if (arr[nx][ny] == 2)
                            {

                                continue;
                            }
                            arr[nx][ny] = -1;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    memset(arr, -1, sizeof(arr));
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> n;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char val;
            cin >> val;
            if (val == '.')
                arr[i][j] = -1; // -1 : 빈땅
            if (val == 'O')
            {
                arr[i][j] = 0;
            }
        }
    }

    //초기상태
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == 0)
                arr[i][j]++;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        afterSecond();
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] != -1)
                cout << 0;
            else
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}