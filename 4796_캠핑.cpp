#include <algorithm>
#include <iostream>
using namespace std;

struct camp
{
    int l, p, v;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 1;
    while (true)
    {

        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;

        int remain = v % p;
        if (remain < l)
        {
            cout << "Case " << cnt << ": " << (v / p) * l + remain << endl;
        }
        else
        {
            cout << "Case " << cnt << ": " << (v / p) * l + l << endl;
        }
        cnt++;
    }

    return 0;
}