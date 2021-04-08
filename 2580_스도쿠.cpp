#include <iostream>
using namespace std;

bool row[9][9];
bool col[9][9];
bool square[9][9];
int arr[9][9];

void search(int cnt)
{
    if (cnt == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << arr[i][j]<<' ';
            cout << endl;
        }
        exit(0);
    }

    int x = cnt / 9;
    int y = cnt % 9;
    if (arr[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i])
            {
                row[x][i] = true;
                col[y][i] = true;
                arr[x][y] = i;
                square[(x / 3) * 3 + (y / 3)][i] = true;

                search(cnt + 1);

                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
                arr[x][y] = 0;
            }
        }
    }
    else
    {
        search(cnt + 1);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                row[i][arr[i][j]] = true;
                col[j][arr[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
            }
        }
    }
    search(0);
}