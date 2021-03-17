#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> days;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        int d = (100 - progresses[i]) / speeds[i];
        if (progresses[i] + d * speeds[i] != 100)
            d++;
        days.push_back(d);
    }
    // days - 5일, 10일, 1일, 1일, 20일, 1일

    //처음 작업은 앞을 고려하지 않아도 됨
    q.push(days[0]);
    for (int i = 1; i < days.size(); i++)
    {
        // 앞에 것이 더 오래걸리면 뒤의 작업도 같이배포해야됨
        if (q.front() >= days[i])
        {
            q.push(days[i]);
        }
        // 뒤에것이 더 오래걸리면 그전 작업은 배포가능
        else
        {
            answer.push_back(q.size());
            while (!q.empty())
                q.pop();
            q.push(days[i]);
        }
    }
    if (!q.empty())
        answer.push_back(q.size());

    return answer;
}

int main()
{

    vector<int> a;
    vector<int> b;
    a.push_back(95);
    a.push_back(90);
    a.push_back(99);
    a.push_back(99);
    a.push_back(80);
    a.push_back(99);

    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);

    cout << solution(a, b).size();

    return 0;
}