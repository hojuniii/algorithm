#include <algorithm>
#include <iostream>
using namespace std;

int map[401][401];
int INF = 987654321;
int v, e;

////플로이드와샬 -> 각 노드에서 노드로 가는 최단거리 저장
void floydWarshall()
{
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {

                //i -> j로 가는 길보다 i -> k -> j 의 경로가 짧을때
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j]; //i->j로 가는 최단경로 업데이트
                }
            }
        }
    }
}
int main()
{

    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            map[i][j] = INF;
        }
    }

    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    floydWarshall();

    int temp = INF;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (i == j)
                continue;
            //map[i][j]와 map[j][i] 둘다 길이 있으면 = 사이클이 있으면
            if (map[i][j] != INF && map[j][i] != INF)
            {
                // 사이클간의 최단 길이 저장
                temp = min(temp, map[i][j] + map[j][i]);
            }
        }
    }

    if (temp == INF)
        cout << -1 << endl;
    else
        cout << temp;

    return 0;
}