#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct elevator
{
    int cur, dist;
    elevator(int a, int b)
    {
        cur = a, dist = b;
    }
};
queue<elevator> q;
bool visit[1000001];
int f, s, g, u, d;
int minDist = 987654321;

void bfs(int cur)
{
    elevator e(cur, 0);
    q.push(e);
    visit[cur] = true;

    while (!q.empty())
    {
        elevator ne = q.front();
        int nu = ne.cur + u;
        int nd = ne.cur - d;

        q.pop();

        if (ne.cur == g)
        {
            minDist = min(minDist, ne.dist);
            return;
        }

        if (nu <= f && !visit[nu])
        {
            q.push({nu, ne.dist + 1});
            visit[nu] = true;
        }
        if (nd > 0 && !visit[nd])
        {
            q.push({nd, ne.dist + 1});
            visit[nd] = true;
        }
    }
}
int main()
{
    cin >> f >> s >> g >> u >> d;

    bfs(s);

    if (minDist == 987654321)
        cout << "use the stairs" << endl;
    else
        cout << minDist << endl;

    return 0;
}