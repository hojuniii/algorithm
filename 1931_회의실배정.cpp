#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct meeting
{
    int start;
    int end;
};
int n;
int cnt = 0;
vector<meeting> v;

bool cmp(meeting a, meeting b)
{
    if (a.end == b.end)
        return a.start < b.start;
    else
    {
        return a.end < b.end;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    int time = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        if (time <= v[i].start)
        {
            time = v[i].end;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}