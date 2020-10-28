#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[8][8];
int tempMap[8][8];
vector<pair<int, int>> virus;
vector<pair<int, int>> emptySpcae;
bool flag[64];
bool visit[8][8];
int n, m, zeroCount= 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;

    q.push({x, y});
    visit[x][y] = true;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (!visit[nx][ny] && tempMap[nx][ny] == 0)
            {
                tempMap[nx][ny] = 2;
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

void spread_virus()
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tempMap[i][j] = map[i][j];
        }
    }

    memset(visit, false, sizeof(visit));

    for (int i = 0; i < emptySpcae.size(); i++)
    {
        if (cnt == 3)
            break;
        if (flag[i] == true)
        {
            int x = emptySpcae[i].first;
            int y = emptySpcae[i].second;
            tempMap[x][y] = 1;
            cnt++;
        }
    }

    for (int i = 0; i < virus.size(); i++)
    {
        int x = virus[i].first;
        int y = virus[i].second;
        bfs(x, y);
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tempMap[i][j] == 0)
                temp++;
        }
    }
    if (zeroCount < temp)
        zeroCount = temp;
}

void makeWall(int index, int count)
{
    if (count == 3)
    {
        spread_virus();
        return;
    }
    for (int i = index; i < emptySpcae.size(); i++)
    {
        if (flag[i])
            continue;
        flag[i] = true;
        makeWall(i, count + 1);
        flag[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            map[i][j] = x;
            if (x == 2)
                virus.push_back({i, j});
            if (x == 0)
                emptySpcae.push_back({i, j});
        }
    }

    makeWall(0, 0);

    cout << zeroCount << endl;
}