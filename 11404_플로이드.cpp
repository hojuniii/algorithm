#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
    int i;
    int j;
    int cost;
};

#define INF 9999999
int n, m;
vector<edge> v;
int arr[102][102];
int main()
{
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
        }
    }
    for (int k = 0; k < m; k++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (arr[a][b] > c)
            arr[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}