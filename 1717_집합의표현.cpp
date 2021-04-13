#include <cstring>
#include <iostream>
using namespace std;

int p[1000001];
int find(int num)
{
    // num이 루트일때
    if (p[num] < 0)
        return num;
    //num의 부모를 재귀적으로 찾아서 리턴
    p[num] = find(p[num]);
    return p[num];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    p[b] = a;
}

int n, m;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(p, -1, sizeof(p));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op)
        {
            if (find(a) == find(b))
            {
                cout << "YES" << '\n';
            }
            else
                cout << "NO" << '\n';
        }
        else
        {
            merge(a, b);
        }
    }
}