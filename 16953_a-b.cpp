#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

ll oper1(ll num)
{
    return num * 2;
}
ll oper2(ll num)
{
    return num * 10 + 1;
}

int main()
{
    queue<pair<ll, ll>> q;
    int ans = -1;
    int a, b;
    cin >> a >> b;

    q.push({a, 1});
    while (!q.empty())
    {
        ll x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x == b)
        {
            ans = cnt;
            break;
        }

        if (oper1(x) <= b)
        {
            q.push({oper1(x), cnt + 1});
        }

        if (oper2(x) <= b)
        {
            q.push({oper2(x), cnt + 1});
        }
    }

    cout << ans << endl;
}
