#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sumA = 0, sumB = 0;
int arr[100][100];
bool visitA[100][100];
bool visitB[100][100];
queue<pair<int, pair<int, int>>> q;
int n, m;

int searchA(int x, int y)
{
    int cnt = 1;
    q.push({cnt, {x, y}});
    visitA[x][y] = true;

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 이미 방문했거나, B팀이면
            if (arr[nx][ny] != 0 || visitA[nx][ny])
                continue;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            cnt++;
            q.push({cnt, {nx, ny}});
            visitA[nx][ny] = true;
        }
    }

    return cnt;
}

int searchB(int x, int y)
{
    int cnt = 1;
    q.push({cnt, {x, y}});
    visitB[x][y] = true;

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 이미 방문했거나, B팀이면
            if (arr[nx][ny] != 1 || visitB[nx][ny])
                continue;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            cnt++;
            q.push({cnt, {nx, ny}});
            visitB[nx][ny] = true;
        }
    }

    return cnt;
}
int main()
{
    memset(visitA, false, sizeof(visitA));
    memset(visitB, false, sizeof(visitB));
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == 'W')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (!visitA[i][j] && arr[i][j] == 0)
            {
                int val = searchA(i, j);
                sumA += (val * val);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visitB[i][j] && arr[i][j] == 1)
            {
                int val = searchB(i, j);
                sumB += (val * val);
            }
        }
    }

    cout << sumA << ' ' << sumB;

    return 0;
}