#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <vector>
#define MAX 9
#define INF 987654321
using namespace std;

typedef pair<int, int> node;

int n, m, ans, cctv_cnt;
int map[MAX][MAX];
int tmp[MAX][MAX];
int cctv_dir[MAX];

// 동 서 남 북
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

vector<node> cctv;

// cctv 의 감시범위를 퍼뜨리기 위한 임시 map
void copyMap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = map[i][j];
        }
    }
}

// 해당 좌표부터 원하는 방향까지 감시범위를 구하는 함수
// 맵의 끝에 도달하거나 벽을 만나기 전까지 퍼짐
void detect(int x, int y, int d)
{
    int nx = x;
    int ny = y;

    while (true)
    {
        nx += dx[d];
        ny += dy[d];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            break;

        // 빈 칸이라면 cctv의 감시범위임
        if (tmp[nx][ny] == 0)
        {
            tmp[nx][ny] = 7;
        }
        // 벽이라면 감시 종료
        else if (tmp[nx][ny] == 6)
        {
            break;
        }
    }
}

// 모든 cctv를 설정한 방향대로 감시
// 1~5 종류에 따라 detect 함수를 다르게 사용함
void set_cctv()
{
    for (int i = 0; i < cctv.size(); i++)
    {
        int x = cctv[i].first;
        int y = cctv[i].second;

        switch (tmp[x][y])
        {
        case 1:
        {
            // 동 서 남 북 中 한방향
            int dir = cctv_dir[i];
            detect(x, y, dir);
            break;
        }

        case 2:
        {
            if (cctv_dir[i] == 1)
            {
                // 동 서
                detect(x, y, 1);
                detect(x, y, 2);
            }
            else
            {
                // 남 북
                detect(x, y, 3);
                detect(x, y, 4);
            }
            break;
        }
        case 3:
        {
            if (cctv_dir[i] == 1)
            {
                // 동 북
                detect(x, y, 1);
                detect(x, y, 4);
            }
            else if (cctv_dir[i] == 2)
            {
                // 동 남
                detect(x, y, 1);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 3)
            {
                // 서 남
                detect(x, y, 2);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 4)
            {
                // 서 북
                detect(x, y, 2);
                detect(x, y, 4);
            }
            break;
        }
        case 4:
        {
            if (cctv_dir[i] == 1)
            {
                // 동 서 북
                detect(x, y, 1);
                detect(x, y, 2);
                detect(x, y, 4);
            }
            else if (cctv_dir[i] == 2)
            {
                // 동 남 북
                detect(x, y, 1);
                detect(x, y, 3);
                detect(x, y, 4);
            }
            else if (cctv_dir[i] == 3)
            {
                // 동 서 남
                detect(x, y, 1);
                detect(x, y, 2);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 4)
            {
                // 서 남 북
                detect(x, y, 2);
                detect(x, y, 3);
                detect(x, y, 4);
            }
            break;
        }
        case 5:
        {
            // 동 서 남 북
            detect(x, y, 1);
            detect(x, y, 2);
            detect(x, y, 3);
            detect(x, y, 4);
            break;
        }

        default:
            break;
        }
    }
}

// 사각지대를 구하는 함수
int getBlindSpot()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 0)
                res++;
        }
    }
    return res;
}

// 모든 cctv에 대해 방향을 설정하도록 재귀함수 구현
// 만약 cctv 개수만큼 인덱스가 도달했다면 cctv 감시를 퍼뜨린 후
// 사각지대를 구해 최소값을 갱신함
void dfs(int ind, int cnt)
{
    // 모든 cctv의 방향을 설정했다면
    if (cnt == cctv.size())
    {
        // tmp 배열을 만듬
        copyMap();

        // cnt개의 cctv의 감시를 퍼뜨림
        set_cctv();

        // 최소값 찾기
        ans = min(ans, getBlindSpot());
        return;
    }

    int x = cctv[ind].first;
    int y = cctv[ind].second;

    // cctv 방향 설정
    for (int k = 1; k <= 4; k++)
    {
        // 2번과 5번은 각각 2개, 1개의 방향만 존재하므로 예외 처리
        if (map[x][y] == 5 && k > 1)
            continue;
        if (map[x][y] == 2 && k > 2)
            continue;

        cctv_dir[ind] = k;
        dfs(ind + 1, cnt + 1);
        cctv_dir[ind] = 0;
    }
}

int main(int argc, const char *argv[])
{
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            // cctv 의 좌표를 벡터에 넣는다
            if (map[i][j] >= 1 && map[i][j] <= 5)
                cctv.push_back(node(i, j));
        }
    }

    ans = INF;
    dfs(0, 0);
    cout << ans << "\n";

    return 0;
}