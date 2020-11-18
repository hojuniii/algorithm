#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Game
{
    int number;
    int strike;
    int ball;
};
bool canNumber[1000];
vector<Game> v;
int n;
int main()
{
    memset(canNumber, true, sizeof(canNumber));
    for (int i = 123; i <= 999; i++)
    {
        string temp = to_string(i);
        if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
            canNumber[i] = false;
        if (temp[0] - '0' == 0 || temp[1] - '0' == 0 || temp[2] - '0' == 0)
            canNumber[i] = false;
    }

    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Game g;
        g.number = a;
        g.strike = b;
        g.ball = c;
        v.push_back(g);
    }

    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].number;
        string num = to_string(a);
        int strike = v[i].strike;
        int ball = v[i].ball;

        for (int j = 123; j <= 999; j++)
        {
            int tempStrike = 0;
            int tempBall = 0;

            if (canNumber[j] == true)
            {
                string tempNum = to_string(j);
                for (int a = 0; a < 3; a++)
                {
                    for (int b = 0; b < 3; b++)
                    {
                        if (a == b && num[a] == tempNum[a])
                            tempStrike++;
                        if (a != b && num[a] == tempNum[b])
                            tempBall++;
                    }
                }
                if (strike != tempStrike || ball != tempBall)
                    canNumber[j] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 123; i <= 999; i++)
    {
        if (canNumber[i] == true)
            ans++;
    }
    cout << ans << endl;

    return 0;
}