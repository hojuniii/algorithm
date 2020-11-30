#include <iostream>
using namespace std;

int n, l, pass = 0;
int map[100][100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        bool canPass = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (map[i][j] == map[i][j + 1])
                cnt++;
            else if (map[i][j] - map[i][j + 1] == -1)
            {
                cnt >= l ? cnt = 1 : canPass = false;
            }
            else if (map[i][j] - map[i][j + 1] == 1)
            {
                cnt < 0 ? canPass = false : cnt = -(l - 1);
            }
            else
                canPass = false;
        }
        if (cnt >= 0 && canPass)
        {
            pass++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        bool canPass = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (map[j][i] == map[j + 1][i])
                cnt++;
            else if (map[j][i] - map[j + 1][i] == -1)
            {
                cnt >= l ? cnt = 1 : canPass = false;
            }
            else if (map[j][i] - map[j + 1][i] == 1)
            {
                cnt < 0 ? canPass = false : cnt = -(l - 1);
            }
            else
                canPass = false;
        }
        if (cnt >= 0 && canPass)
        {
            pass++;
        }
    }

    cout << pass << endl;

    return 0;
}