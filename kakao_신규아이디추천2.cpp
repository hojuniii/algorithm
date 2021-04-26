#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)

{
    string answer = "";
    int len = new_id.length();

    // 1단계 대문자를 소문자로 치환
    for (int i = 0; i < len; i++)
    {
        if (new_id[i] >= 65 && new_id[i] <= 90)
        {
            new_id[i] = tolower(new_id[i]);
        }
    }

    for (char c : new_id)
    {
        if ((c == '_') || (c == '-') || (c == '.') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            answer.push_back(c);
    }

    // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    string tmp = "";
    for (int i = 0; i < answer.length(); i++)
    {
        int cnt = 0;
        int cur = i + 1;
        if (answer[i] == '.')
        {
            while (answer[cur] == '.')
            {
                cnt++;
                cur++;
            }
            if (cnt <= 0)
                tmp.push_back('.');
            else
            {
                tmp.push_back('.');
                i = cur - 1;
            }
        }
        else
            tmp.push_back(answer[i]);
    }
    answer = tmp;

    // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (answer[0] == '.')
    {
        answer = answer.substr(1, answer.length());
    }
    if (answer[answer.length() - 1] == '.')
    {
        answer = answer.substr(0, answer.length() - 1);
    }

    // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if (answer.length() == 0)
        answer = "a";

    // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if (answer.length() >= 16)
    {
        answer = answer.substr(0, 15);
        if (answer[answer.length() - 1] == '.')
        {
            answer = answer.substr(0, answer.length() - 1);
        }
    }

    // new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if (answer.length() <= 2)
    {
        char c = answer[answer.length() - 1];
        for (int i = answer.length(); i < 3; i++)
        {
            answer.push_back(c);
        }
    }

    return answer;
}

int main()
{
    cout << solution("=.=");
}