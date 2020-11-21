#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int eureka[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= 45; i++)
    {
        eureka[i] = i * (i + 1) / 2;
    }

    while (n--)
    {
        int num, sum = 0;
        int cnt = 0;
        bool success = false;
        cin >> num;

        for (int i = 1; i <= 45; i++)
        {
            for (int j = 1; j <= 45; j++)
            {
                for (int k = 1; k <= 45; k++)
                {
                    sum = 0;
                    cnt = 0;
                    sum += eureka[i];
                    cnt++;

                    sum += eureka[j];
                    cnt++;

                    sum += eureka[k];
                    cnt++;
                    if (sum == num && cnt == 3)
                    {
                        success = true;
                        break;
                    }
                }
            }
        }

        if (success)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
}