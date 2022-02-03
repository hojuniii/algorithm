#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v[26];
        string w;
        cin >> w;

        int k;
        cin >> k;

        for (int i = 0; i < w.length(); i++)
        {
            v[w[i] - 'a'].push_back(i); // v[a][0] = a의 첫번째 인덱스
        }

        /*
        2
        superaquatornado
        2
        abcdefghijklmnopqrstuvwxyz
        5
        */

        int answer1 = 99999;
        int answer2 = -1;
        bool flag = false;
        for (int alpahbet = 0; alpahbet < 26; alpahbet++)
        {
            int count = v[alpahbet].size();
            if (count >= k)
            {
                flag = true;
                for (int i = 0; i <= count - k; i++)
                {
                    answer1 = min(answer1, v[alpahbet][i + k - 1] - v[alpahbet][i] + 1);
                    answer2 = max(answer2, v[alpahbet][i + k - 1] - v[alpahbet][i] + 1);
                }
            }
        }
        if (flag)
        {
            cout << answer1  << ' ' << answer2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}