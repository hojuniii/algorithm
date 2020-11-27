#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#define ll long long
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> prime;
    int k, n;
    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        prime.push_back(tmp);
    }

    int a = 0;
    ll b = 0;
    while (a < n - 1)
    {
        a++;
        b = pq.top();
        for (int i = 0; i < k; i++)
        {
            if (b * prime[i] < pow(2, 31))
                pq.push(b * prime[i]);
        }
        while (b == pq.top())
        {
            pq.pop();
        }
    }
    cout << pq.top();

    return 0;
}