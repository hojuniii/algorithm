#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX 32767

int t;
vector<pair<int, int>> v;
int sx, sy, ex, ey;
bool flag;
int visit[110];
void dfs(int sx, int sy)
{
    // 시작좌표와 도착 좌표와의 거리
    int num = abs(sx - ex) + abs(sy - ey);
    // 맥주가 모두 떨어지기 전에 도착 가능하면 true
    if (num <= 1000)
    {
        flag = true;
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        //이미 들른 편의점 패스
        if (visit[i])
            continue;

        //시작거리와 편의점 사이의 거리
        num = abs(v[i].first - sx) + abs(v[i].second - sy);

        //편의점까지 도착하기전에 맥주가 모두 떨어진다면 패스
        if (num > 1000)
            continue;
        else
        {
            // 해당 편의점 visit 처리, 편의점 좌표부터 다시 탐색
            visit[i] = true;
            dfs(v[i].first, v[i].second);
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        v.clear();
        memset(visit, false, sizeof(visit));

        int n;
        cin >> n;
        cin >> sx >> sy;

        for (int i = 0; i < n; i++)
        {
            int px, py;
            cin >> px >> py;
            v.push_back({px, py});
        }
        cin >> ex >> ey;
        flag = false;
        dfs(sx, sy);
        if (flag)
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
    }
}