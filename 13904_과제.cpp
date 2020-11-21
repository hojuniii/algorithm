#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct assignment
{
    int d, w;
};

bool cmp(assignment a, assignment b)
{
    return a.w > b.w;
}

vector<assignment> v;
bool check[1001];
int main()
{
    int n, score = 0;
    int lastDay = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        lastDay = max(lastDay, a);
    }

    sort(v.begin(), v.end(), cmp);
    memset(check, false, sizeof(check));

    int cnt = 0;

    //마감일부터 1일씩 줄어든다
    for (int i = lastDay; i >= 1; i--)
    {
        for (int j = 0; j < v.size(); j++)
        {
            //아직 수행하지 않은 과제이며, 현재 날짜가 과제 마감일 안에 속한다면
            if (!check[j] && v[j].d >= i)
            {
                score += v[j].w;
                check[j] = true;
                break;
            }
        }
    }

    cout << score << endl;

    return 0;
}