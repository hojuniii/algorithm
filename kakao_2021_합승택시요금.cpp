#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 99999999;

int n;
int cost[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = MAX;
            if (i == j)
                cost[i][j] = 0;
        }
    }

    for (auto v : fares)
    {
        cost[v[0]][v[1]] = v[2];
        cost[v[1]][v[0]] = v[2];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // i -> j로 가는경로보다 i->k->j로 가는길이 더짧을때
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, cost[s][i] + cost[i][a] + cost[i][b]);
    }

    return answer;
}