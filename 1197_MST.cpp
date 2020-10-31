#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int leader[10001];
vector<Edge> graph;
bool tree[10001];

int find(int vertex)
{
    if (vertex == leader[vertex])
        return vertex;
    else
        return leader[vertex] = find(leader[vertex]);
}

void unionVertex(int u, int v)
{
    int uLeader = find(u);
    int vLeader = find(v);
    leader[uLeader] = vLeader;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;

    int distance = 0;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a, b, c});
    }

    sort(graph.begin(), graph.end(), cmp);

    for (int i = 1; i <= v; i++)
    {
        leader[i] = i;
    }

    for (auto e : graph)
    {
        if (find(e.u) == find(e.v))
            continue;

        unionVertex(e.u, e.v);
        distance += e.w;
    }

    cout << distance << endl;

    return 0;
}