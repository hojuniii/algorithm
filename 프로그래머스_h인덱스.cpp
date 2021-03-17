#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    int index = 0;
    vector<int> temp;
    for (int i = 0; i < citations.size(); i++)
    {
        temp.push_back(citations[i]);
    }

    sort(temp.begin(), temp.end(), greater<int>());
    while (index < temp.size())
    {
        if (temp[index] <= index)
            break;
        index++;
    }

    return index;
}