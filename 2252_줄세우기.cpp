#include <iostream>
#include <queue>
#include <stack>

#define MAX 100001
using namespace std;

int inDegree[MAX];
vector<int> edge[MAX];
int main()
{
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
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        cout << val << " ";

        for (int i = 0; i < edge[val].size(); i++)
        {
            int next = edge[val][i];
            inDegree[next]--;
            if (inDegree[next] == 0)
                q.push(next);
        }
    }
}