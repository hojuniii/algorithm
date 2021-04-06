#include <algorithm>
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
bool finish[1000];

int main()
{
    int lastDay = -1;
    int n;
    cin >> n;
    while (n--)
    {
        int d, w;
        cin >> d >> w;
        v.push_back(assignment({d, w}));
        lastDay = max(lastDay, d);
    }

    sort(v.begin(), v.end(), cmp);
    int day = 0;
    int score = 0;
    for (int i = lastDay; i >= 1; i--)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!finish[j] && v[j].d >= i)
            {
                score += v[j].w;
                finish[j] = true;
                break;
            }
        }
    }

    cout << score << endl;
}