#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isOdd(int num)
{
    return num % 2 == 1;
}

const int MIN_VAL = 1000000000;
const int MAX_VAL = -1;

int ans_max = MAX_VAL;
int ans_min = MIN_VAL;
int N;

void dfs(int num, int cnt)
{
    string str = to_string(num);
    int len = str.length();
    if (len == 1)
    {
        if (isOdd(num))
            cnt++;

        ans_max = max(ans_max, cnt);
        ans_min = min(ans_min, cnt);
        return;
    }
    else if (len == 2)
    {
        int x = str[0] - '0';
        int y = str[1] - '0';

        if (isOdd(x))
            cnt++;
        if (isOdd(y))
            cnt++;
        dfs(x + y, cnt);
    }
    else if (len > 2)
    {
        for (auto x : str)
        {
            if (isOdd(x - '0'))
                cnt++;
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                string a = str.substr(0, i);
                string b = str.substr(i, j - i);
                string c = str.substr(j, str.length());
                int num = stoi(a) + stoi(b) + stoi(c);

                dfs(num, cnt);
            }
        }
    }
}

int main()
{
    cin >> N;
    string str = to_string(N);

    dfs(N, 0);

    cout << ans_min << ' ' << ans_max;

    return 0;
}