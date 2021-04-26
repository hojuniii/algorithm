#include <iostream>
#include <vector>
using namespace std;
struct edge
{
    int a, b, c;
};
int n, k;
int city[51][51];
bool visit[51][51];
vector<edge> v;
int ans = 0;
void dfs(int s, int cost)
{

    if (cost > k)
        return;
    ans++;

    for (int i = s; i <= n; i++)
    {
        if (s == i)
            continue;
        if (city[s][i] != 0 && !visit[s][i])
        {
            visit[s][i] = true;
            dfs(i, cost + city[s][i]);
        }
    }
}
int solution(int N, vector<vector<int>> road, int K)
{
    n = N, k = K;
    int answer = 0;
    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        v.push_back({a, b, c});
    }

    for (int i = 0; i < v.size(); i++)
    {
        city[v[i].a][v[i].b] = v[i].c;
    }

    dfs(1, 0);

    return ans;
}
int main()
{
    solution(5, {
                    {1, 2, 1},
                    {2, 3, 3},
                    {5, 2, 2},
                    {1, 4, 2},
                    {5, 3, 1},
                },
             3);
}