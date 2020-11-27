#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    cin >> n;
    int cnt = (n * n) - n;
    int idx = 1;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        pq.push(x);
    }

    while (cnt--)
    {
        long long x;
        cin >> x;

        pq.push(x);
        pq.pop();
    }

    cout << pq.top();
}