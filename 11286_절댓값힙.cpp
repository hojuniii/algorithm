#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x != 0)
        {
            pq.push({abs(x), x});
        }
        else
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}