#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1001];
int l = 1001, r = 0;
vector<pair<int, int>> v;
pair<int, int> maxVal = {0, 0};
int maxCnt = 0;
stack<int> st;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
        if (l > a)
            l = min(a, l);
        if (r < a)
            r = max(r, a);

        if (maxVal.second <= b)
        {
            maxVal.first = a;
            maxVal.second = b;
        }
    }

    int ans = 0;

    for (int i = l; i <= maxVal.first; i++)
    {
        if (arr[i])
        {
            if (st.empty())
                st.push(arr[i]);
            else if (arr[i] > st.top())
                st.push(arr[i]);
        }
        ans += st.top();
    }

    while (!st.empty())
        st.pop();

    for (int i = r; i > maxVal.first; i--)
    {
        if (arr[i])
        {
            if (st.empty())
                st.push(arr[i]);
            else if (st.top() < arr[i])
                st.push(arr[i]);
        }
        ans += st.top();
    }

    cout << ans << endl;
}
