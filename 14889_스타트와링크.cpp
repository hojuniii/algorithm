#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int minDif = 987654321;
int arr[21][21];
bool check[21];
int n;

void combi(int cnt, int cur)
{
    if (cnt == n / 2)
    {
        int a = 0;
        int b = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (check[i] && check[j])
                {
                    a += arr[i][j];
                    a += arr[j][i];
                }
                else if (!check[i] && !check[j])
                {
                    b += arr[i][j];
                    b += arr[j][i];
                }
            }
        }
        int tmp = abs(a - b);
        if (tmp < minDif)
            minDif = tmp;
        return;
    }

    for (int i = cur; i < n; i++)
    {
        check[i] = true;
        combi(cnt + 1, i + 1);
        check[i] = false;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    combi(0, 1);
    cout << minDif << endl;

    return 0;
}