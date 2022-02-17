#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visit[200];
int answer = 0;
int N;

void dfs(int start, int n, vector<vector<int>> &computers)
{
    visit[start] = true;

    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && computers[start][i] && start != i)
        {
            dfs(i, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers)
{
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i, n, computers);
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
}