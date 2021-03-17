#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    queue<int> q;
    int sum_weight = 0;

    int idx = 0;
    while (1)
    {
        answer++;
        if (q.size() == bridge_length)
        { //트럭이 도착하면 무게 빼주고 제거
            sum_weight -= q.front();
            q.pop();
        }
        if (sum_weight + truck_weights[idx] <= weight)
        { //트럭 추가할 수 있으면 추가
            if (idx == truck_weights.size() - 1)
            { //마지막 트럭인 경우
                answer += bridge_length;
                break;
            }
            q.push(truck_weights[idx]);
            sum_weight += truck_weights[idx];
            idx++;
        }
        else
        {
            q.push(0); //트럭을 더 못 올리면 0으로 트럭 밀어주기
        }
    }

    return answer;
}

int main()
{
    vector<int> temp;

    temp.push_back(10);
    // temp.push_back(4);
    // temp.push_back(5);
    // temp.push_back(6);
    cout << solution(2, 10, {7,4,5,6}) << endl;
}