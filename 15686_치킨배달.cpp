#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<int, int> pi;

int arr[51][51];
int minDist = 987654321;
int n, m;
bool check[13];
vector<pi> v;
vector<pi> home, chicken;

int getDistance()
{
    int sum = 0;
    for (int i = 0; i < home.size(); i++)
    {
        int x = home[i].first;
        int y = home[i].second;
        int d = 987654321;

        for (int j = 0; j < v.size(); j++)
        {
            int xx = v[j].first;
            int yy = v[j].second;
            int dist = abs(x - xx) + abs(y - yy);

            d = min(d, dist);
        }
        sum += d;
    }

    return sum;
}

void dfs(int idx, int cnt)
{
    //선택된 치킨집의 개수가 m일때
    if (cnt == m)
    {
        minDist = min(minDist, getDistance());
        return;
    }

    for (int i = idx; i < chicken.size(); i++)
    {
        if (check[i])
            continue;
        check[i] = true;
        v.push_back(chicken[i]);
        dfs(i, cnt + 1);
        check[i] = false;
        v.pop_back();
    }
}

int main()
{

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                home.push_back({i, j});
            if (arr[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    dfs(0, 0);

    cout << minDist;

    return 0;
}