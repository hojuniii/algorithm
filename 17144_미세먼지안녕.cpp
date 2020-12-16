#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

int r, c, t;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[51][51];
int tmp[51][51];
int total = 0;
bool visitied[51][51];
queue<pair<int, int>> cleanerQueue;
vector<pair<int, int>> v;

void getDust()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] >= 1)
                total += arr[i][j];
        }
    }
}

void copy()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
}

void init()
{
    memset(visitied, false, sizeof(visitied));
    memset(tmp, 0, sizeof(tmp));
}

void caculateDust(int sx, int sy)
{
    int x = sx;
    int y = sy;
    int cnt = 0;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (visitied[nx][ny] || arr[nx][ny] == -1)
            continue;
        cnt++;
        tmp[nx][ny] += arr[x][y] / 5;
    }
    tmp[x][y] += arr[x][y] - (arr[x][y] / 5) * cnt;
}

void spread()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 0 || visitied[i][j])
                continue;
            if (arr[i][j] == -1)
            {
                tmp[i][j] = -1;
                continue;
            }
            caculateDust(i, j);
        }
    }
    copy();
    init();
}

void clean()
{
    int fx = v[0].first;
    int fy = v[0].second;
    for (int i = fx; i > 0; i--)
    {
        if (i == fx)
            continue;
        arr[i][0] = arr[i - 1][0];
    }
    for (int i = 0; i < c - 1; i++)
    {
        arr[0][i] = arr[0][i + 1];
    }
    for (int i = 0; i < fx; i++)
    {
        arr[i][c - 1] = arr[i + 1][c - 1];
    }
    for (int i = c - 1; i > fy; i--)
    {
        if (i == 1)
            arr[fx][i] = 0;
        else
            arr[fx][i] = arr[fx][i - 1];
    }

    int sx = v[1].first;
    int sy = v[1].second;
    for (int i = sx; i < r - 1; i++)
    {
        if (i == sx)
            continue;
        arr[i][0] = arr[i + 1][0];
    }
    for (int i = 0; i < c - 1; i++)
    {
        arr[r - 1][i] = arr[r - 1][i + 1];
    }
    for (int i = r - 1; i > sx; i--)
    {
        arr[i][c - 1] = arr[i - 1][c - 1];
    }
    for (int i = c - 1; i > 0; i--)
    {
        if (i == 1)
        {
            arr[sx][i] = 0;
        }
        else
            arr[sx][i] = arr[sx][i - 1];
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
                v.push_back({i, j});
        }
    }

    while (t--)
    {
        init();
        spread();
        clean();
    }
    getDust();

    cout << total << endl;

    return 0;
}