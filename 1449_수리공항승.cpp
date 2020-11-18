#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool pipe[1000];
vector<int> v;
int n, l;
int main()
{

    cin >> n;
    cin >> l;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        pipe[num] = true;
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i];
        if (pipe[x] == true)
        {
            for (int j = 0; j < l; j++)
            {
                pipe[x + j] = false;
            }
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}