#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[51][51];
bool visit[51][51];
int t, m, n, k;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void bfs(int x, int y)
{
    visit[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        visit[x][y] = true;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (visit[nx][ny] || arr[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        memset(visit, false, sizeof(visit));
        memset(arr, 0, sizeof(arr));
        v.clear();

        cin >> m >> n;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
            v.push_back({x, y});
        }

        int count = 0;

        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i].first;
            int y = v[i].second;
            if (visit[x][y] || arr[x][y] == 0)
                continue;
            bfs(x, y);
            count++;
        }

        cout << count << endl;
    }

    return 0;
}