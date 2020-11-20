#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    int idx = 0;
    int sum = 0;
    bool flag = false;
    while (true)
    {
        if (sum == k)
        {
            cout << cnt << endl;
            break;
        }

        if (v[idx] + sum <= k)
        {
            sum += v[idx];
            cnt++;
            if (sum + v[idx] > k)
            {
                idx++;
            }
            else
                continue;
        }
        else
            idx++;
    }
    return 0;
}