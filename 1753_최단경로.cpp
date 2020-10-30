#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20001
#define INF 987654321

vector<pair<int, int>> graph[MAX];
typedef pair<int, int> edge;
vector<int> dist;

struct cmp
{
    bool operator()(edge a, edge b)
    {
        return a.first > b.first;
    }
};

priority_queue<edge, vector<edge>, cmp> pq;

void dijkstra(int start, int size)
{
    // init
    dist.push_back(0);
    for (int i = 0; i < size; i++)
    {
        dist.push_back(INF);
    }

    dist[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < d)
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            //인접노드
            int v = graph[u][i].first;
            //인접노드 거리
            int w = graph[u][i].second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int v, e, start;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e >> start;

    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    //1, 5
    dijkstra(start, v);

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}