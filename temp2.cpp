#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[1000][1000];
int dp[1000][1000];
bool visit[1000][1000];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int answer = -1;
int xSize, ySize;
int xCost, yCost;
queue<pair<int, pair<int, int>>> q;

int n, m;

void bfs()
{
    q.push({map[0][0], {0, 0}});
    visit[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int curCost = q.front().first;
        visit[x][y] = true;
        q.pop();
        if (x == m - 1)
        {
            if (curCost < 0)
            {
                answer = max(answer, 0);
                return;
            }
            else
            {
                answer = max(answer, curCost);
                return ;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (visit[nx][ny])
                continue;

            //아래측
            if (i == 0)
            {
                int sumCost = curCost + map[nx][ny] - xCost;
                q.push({sumCost, {nx, ny}});
            }
            else
            {
                int sumCost = curCost + map[nx][ny] - yCost;
                q.push({sumCost, {nx, ny}});
            }
        }
    }
}

int main(void)
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = i + j;
        }
    }

    cin >> xCost >> yCost;

    bfs();

    cout << answer;

    return 0;
}
