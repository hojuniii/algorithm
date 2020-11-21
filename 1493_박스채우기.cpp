#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    vector<pair<int, int>> v;
    int l, w, h;
    cin >> l >> w >> h;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    ll ans = 0;
    ll before = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        before <<= 3;
        ll pc = (ll)(l >> i) * (w >> i) * (h >> i) - before;
        cout << "pc:" << pc << endl;
        ll nc = min((ll)v[i].second, pc);

        before += nc;
        ans += nc;
    }

    if (before == (ll)l * w * h)
        cout << ans;
    else
        cout << -1;
}