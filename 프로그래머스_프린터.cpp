#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }

    while (!q.empty())
    {
        int curOrder = pq.top();
        pair<int, int> cur = q.front();
        q.pop();

        if (curOrder == cur.first)
        {
            answer++;
            pq.pop();
            if (cur.second == location)
                break;
        }
        else
        {
            q.push(cur);
        }
    }

    return answer;
}