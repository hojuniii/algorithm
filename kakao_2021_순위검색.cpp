#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split(string str, char delimeter)
{
    vector<string> result;
    string tmp = "";
    stringstream ss(str);

    while (getline(ss, tmp, delimeter))
    {
        if (tmp == "and")
            continue;
        result.push_back(tmp);
    }
    return result;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    vector<vector<string>> v;
    int len = info.size();

    for (int i = 0; i < len; i++)
    {
        v.push_back(split(info[i], ' '));
    }

    //쿼리 하나
    for (int i = 0; i < query.size(); i++)
    {
        int cnt = 0;
        string str = query[i];
        vector<string> condition = split(str, ' ');
        //사람 한명
        for (int j = 0; j < len; j++)
        {
            bool flag = false;
            vector<string> person = v[j];
            //조건 하나
            for (int k = 0; k < 5; k++)
            {
                if (condition[k] == "-")
                    continue;
                if (k == 4)
                {
                    int point = stoi(person[4]);
                    int conditionPoint = stoi(condition[4]);
                    if (point >= conditionPoint)
                        cnt++;
                    break;
                }
                if (person[k] != condition[k])
                {
                    break;
                }
            }
        }
        answer.push_back(cnt);
    }
    for (int i : answer)
    {
        cout << i << endl;
    }

    return answer;
}

int main()
{
    vector<string> info;
    vector<string> query;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");

    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");
    solution(info, query);
}