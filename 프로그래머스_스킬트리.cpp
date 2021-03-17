#include <iostream>
#include <string>
#include <vector>

using namespace std;

//"CBD"	["BACDE", "CBADF", "AECB", "BDA"]
int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    for (auto str : skill_trees)
    {
        bool flag = true;
        string temp;

        for (auto c : str)
        {
            for (auto s : skill)
            {
                if (c == s)
                    temp += c;
            }
        }

        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] != skill[i])
                flag = false;
        }
        if (flag)
            answer++;
    }

    return answer;
}

int main()
{
    vector<string> test;
    test.push_back("BACDE");
    test.push_back("CBADF");
    test.push_back("AECB");
    test.push_back("BDA");

    cout << solution("CBD", test);
}
