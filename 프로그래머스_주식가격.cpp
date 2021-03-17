#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int len = prices.size();

    for (int i = 0; i < len; i++)
    {
        int cur = prices[i];
        int cnt = 0;
        for (int j = i + 1; j < len; j++)
        {
            cnt++;
            if (cur <= prices[j])
                continue;
            else
                break;
        }
        answer.push_back(cnt);
    }
    return answer;
}