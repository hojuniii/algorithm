#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 1000000000
using namespace std;

vector<int> solution(vector<vector<int>> v)
{
    vector<int> ans;
    ans.push_back(0);
    ans.push_back(0);
    // XOR - 다른 값 반환
    ans[0] = v[0][0] ^ v[1][0] ^ v[2][0];
    ans[1] = v[0][1] ^ v[1][1] ^ v[2][1];

    return ans;
}