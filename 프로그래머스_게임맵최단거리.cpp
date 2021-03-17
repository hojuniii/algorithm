#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;
queue<pair<int, pair<int, int>>> q;
int solution(vector<vector<int>> maps)
{
    int answer = 987654321;
    int n = maps.size();
    int m = maps[0].size();

    q.push({1, {0, 0}});
    visit[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            answer = min(answer, cnt);
            return answer;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (maps[nx][ny] == 0 || visit[nx][ny])
                continue;

            q.push({cnt + 1, {nx, ny}});
            visit[nx][ny] = true;
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> v;
    v.push_back({1, 0, 1, 1, 1});
    v.push_back({1, 0, 1, 0, 1});
    v.push_back({1, 0, 1, 1, 1});
    v.push_back({1, 1, 1, 0, 1});
    v.push_back({0, 0, 0, 0, 1});
    cout << solution(v) << endl;
}