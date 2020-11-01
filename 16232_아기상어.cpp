#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Fish
{
    int dist, x, y;
    Fish(int a, int b, int c)
    {
        dist = a;
        x = b;
        y = c;
    }
};

int n, currentX, currentY;
int sharkSize = 2;
int curExp = 0;
int map[21][21];
bool check[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int seconds = 0;

vector<Fish> fish;

bool cmp(Fish a, Fish b)
{
    if (a.dist == b.dist)
    {
        if (a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    }
    return a.dist < b.dist;
}

void bfs(int x, int y)
{
    queue<pair<pair<int, int>, int>> q;
    fish.clear();
    memset(check, false, sizeof(check));
    q.push({{x, y}, 0});
    check[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (map[nx][ny] > sharkSize)
                continue;
            if (check[nx][ny])
                continue;

            if (map[nx][ny] < sharkSize && map[nx][ny] > 0)
            {
                fish.push_back(Fish(dist + 1, nx, ny));
            }

            q.push({{nx, ny}, dist + 1});
            check[nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            map[i][j] = val;

            if (val == 9)
            {
                currentX = i, currentY = j;
                map[i][j] = 0;
            }
        }
    }

    while (true)
    {
        bfs(currentX, currentY);
        if (fish.size() == 0)
            break;

        sort(fish.begin(), fish.end(), cmp);

        curExp++;

        seconds += fish[0].dist;

        currentX = fish[0].x;
        currentY = fish[0].y;
        map[currentX][currentY] = 0;

        if (curExp == sharkSize)
        {
            curExp = 0;
            sharkSize++;
        }
    }

    cout << seconds << endl;
}