#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int cnt[27];                   // cnt[i] = n : 길이가 i인 조합중 최대 주문 횟수는 n
unordered_map<string, int> um; //um[str] = n : 조합 str의 주문 횟수
vector<string> menu[27][21];   //길이가 i고 j번 주문된 orders의 목록

void comb(string s, int idx, string made)
{
    // 두개이상 주문한것만
    if (made.size() > 1)
    {
        um[made]++;                                         // 해당 조합 주문횟수 +1
        cnt[made.size()] = max(cnt[made.size()], um[made]); // n길이의 코스중 최대 주문횟수
        menu[made.size()][um[made]].push_back(made);        // 분류별 조합 목록 추가
    }

    for (int i = idx + 1; i < s.size(); i++)
    {
        made.push_back(s[i]);
        comb(s, i, made);
        made.pop_back();
    }
}

// ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
// [2,3,4]
vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (string &s : orders)
    {
        sort(s.begin(), s.end());
        comb(s, -1, "");
    }
    cout << answer.size() << endl;

    for (int i : course)
        if (cnt[i] > 1) // 길이가 i인 조합의 최대 주문 횟수가 1 이상인 경우만
            for (string s : menu[i][cnt[i]])
                answer.push_back(s);

    sort(answer.begin(), answer.end());

    return answer;
}