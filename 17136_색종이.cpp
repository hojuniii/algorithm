
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 987654321;

int arr[MAX][MAX];
int cnt, result;
int paper[6] = {0, 5, 5, 5, 5, 5};

void func(int x, int y)
{
    if (y == MAX)
    {
        func(x + 1, 0);
        return;
    }

    if (x == MAX)
    {
        result = min(result, cnt);
        return;
    }

    if (arr[x][y] == 0)
    {
        func(x, y + 1);
        return;
    }

    for (int size = 5; size >= 1; size--)
    {
        if (x + size > MAX || y + size > MAX || paper[size] == 0)
            continue;

        bool flag = true;

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (arr[x + j][y + k] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        if (!flag)
            continue;

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                arr[x + j][y + k] = 0;
            }
        }

        paper[size]--;
        cnt++;
        func(x, y + size);

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                arr[x + j][y + k] = 1;
            }
        }
        paper[size]++;
        cnt--;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> arr[i][j];
        }
    }
    result = INF;
    func(0, 0);
    if (result == INF)
        cout << -1 << "\n";
    else
        cout << result << "\n";
    return 0;
}
