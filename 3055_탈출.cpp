#include <iostream>
#include <queue>
using namespace std;

char arr[50][50];
bool visit[50][50];
int r, c, cnt = 0;
int sx, sy, ex, ey;
bool canExit = false;
queue<pair<int, int>> waterQueue;
queue<pair<int, int>> moveQueue;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y)
{
    moveQueue.push({x, y});
    visit[x][y] = true;

    while (!moveQueue.empty())
    {
        int wqSize = waterQueue.size();
        int mqSize = moveQueue.size();
        int x, y;
        cnt++;

        while (wqSize--)
        {
            x = waterQueue.front().first;
            y = waterQueue.front().second;
            waterQueue.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                    continue;
                if (visit[nx][ny] || arr[nx][ny] == 'X' || arr[nx][ny] == 'D')
                    continue;
                waterQueue.push({nx, ny});
                arr[nx][ny] = '*';
                visit[nx][ny] = true;
            }
        }

        while (mqSize--)
        {
            x = moveQueue.front().first;
            y = moveQueue.front().second;
            moveQueue.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (arr[nx][ny] == 'D')
                {
                    canExit = true;
                    return;
                }
                if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                    continue;
                if (visit[nx][ny] || arr[nx][ny] == 'X' || arr[nx][ny] == '*')
                    continue;
                moveQueue.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                sx = i, sy = j;
                arr[i][j] = '.';
            }
            else if (arr[i][j] == '*')
            {
                waterQueue.push({i, j});
            }
            else if (arr[i][j] == 'X')
            {
                visit[i][j] = true;
            }
        }
    }

    bfs(sx, sy);

    if (canExit)
        cout << cnt;
    else
        cout << "KAKTUS";

    return 0;
}