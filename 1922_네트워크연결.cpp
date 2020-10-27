#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int a, b, c;
};

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int computers[1001];
int parents[1001];
vector<Edge> v;
int n, m;
int cost = 0;

// 간선의 두 노드의 부모 비교를 위한 find 함수
int find(int x)
{
    //자신이 부모이면
    if (parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
        // 자신이 부모가 아니면 재귀적으로 부모를 찾아나감
}


void unionEdge(int x, int y)
{
    x = find(x);
    y = find(y);
    parents[x] = y;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a + 1, b + 1, c});
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    for (auto edge : v)
    {
        //부모가 같으면 연결하지 않는다
        if (find(edge.a) == find(edge.b))
            continue;
        else{
            unionEdge(edge.a, edge.b);
            cost+=edge.c;
        }
    }

    cout<<cost<<endl;
}