#include <iostream>
using namespace std;

int parent[201];
int n, m;

int find(int x)
{
    if (x == parent[x])
        return x;
    return find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    parent[b] = a;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int connected;
            cin >> connected;
            if (connected)
            {
                merge(i, j);
            }
        }
    }

    int first;
    cin >> first;
    first = find(first);
    for (int i = 1; i < m; i++)
    {
        int next;
        cin >> next;
        if (first != find(next))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}