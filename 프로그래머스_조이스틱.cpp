#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string name)
{
    int answer = 0;
    for (auto c : name)
        answer += min(c - 'A', 'Z' - c + 1);

    int len = name.length();
    int move = len - 1;
    int next;
    for (int i = 0; i < len; i++)
    {
        next = i + 1;
        while (next < len && name[next] == 'A')
            next++;
        // min(i, len - next) : 처음에 왼쪽으로 갈지 오른쪽으로 갈지 더 적은쪽으로
        move = min(move, i + (len - next) + min(i, len - next));
        move = move;
    }
    answer += move;

    return answer;
}

int main()
{
    cout << solution("ABBBAAABA");
}