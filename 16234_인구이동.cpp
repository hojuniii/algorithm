#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, l, r;
int arr[100][100];
bool visited[100][100];
int cnt = 0;
vector<pair<int, int>> v[2000];
queue<pair<int, int>> q;

bool finish = false;

void bfs(int sx, int sy)
{
    q.push({sx, sy});
    v[cnt].push_back({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;
            int diff = abs(arr[x][y] - arr[nx][ny]);
            if (diff >= l && diff <= r)
            {
                q.push({nx, ny});
                v[cnt].push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    //인구 이동 시작
    int size = v[cnt].size();
    if (size > 1)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            int x = v[cnt][i].first;
            int y = v[cnt][i].second;
            sum += arr[x][y];
        }
        int avg = sum / size;
        for (int i = 0; i < size; i++)
        {
            int x = v[cnt][i].first;
            int y = v[cnt][i].second;
            arr[x][y] = avg;
        }
        finish = false;
    }
    v[cnt].clear();
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (true)
    {
        memset(visited, false, sizeof(visited));
        finish = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    bfs(i, j);
                }
            }
        }
        if (!finish)
            cnt++;
        else
            break;
    }

    cout << cnt << endl;

    return 0;
}