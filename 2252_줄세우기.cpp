/*
위상정렬
방향 그래프에 존재하는 각 정점들의
선행 순서를 위배하지 않으면서
모든 정점을 나열하는 것
*/

#include <iostream>
#include <queue>

#define MAX 100001
using namespace std;

int main()
{
    int inDegree[MAX];
    vector<int> edge[MAX];
    queue<int> q;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        inDegree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout << val << ' ';

        for (int i = 0; i < edge[val].size(); i++)
        {
            int next = edge[val][i];
            inDegree[next]--;
            if (inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}