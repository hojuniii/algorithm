#include <iostream>
using namespace std;

int arr[500][500];
bool visit[500][500];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    return 0;
}