#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    int k = n;

    while (n--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < k - 1; i++)
    {
        int a = pq.top();
        cnt += a;
        pq.pop();
        int b = pq.top();
        pq.pop();
        cnt += b;
        int s = a + b;
        pq.push(s);
    }

    cout << cnt << endl;

    return 0;
}