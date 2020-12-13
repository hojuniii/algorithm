#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 9
#define INF 987654321
using namespace std;

typedef pair<int, int> node;

int n, m, ans, cctvCnt;
int arr[MAX][MAX];
int tmp[MAX][MAX];
int cctvDirection[MAX];
//  동 서 남 북
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
vector<node> cctv;

void copyMap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }
}

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
        if (tmp[nx][ny] == 0)
        {
            tmp[nx][ny] = 7;
        }
        else if (tmp[nx][ny] == 6)
            break;
    }
}

void setCCTV()
{
    for (int i = 0; i < cctv.size(); i++)
    {
        int x = cctv[i].first;
        int y = cctv[i].second;

        switch (tmp[x][y])
        {
        case 1:
        {
            int dir = cctvDirection[i];
            detect(x, y, dir);
            break;
        }
        case 2:
        {
            if (cctvDirection[i] == 1)
            {
                detect(x, y, 1);
                detect(x, y, 2);
            }
            else
            {
                detect(x, y, 3);
                detect(x, y, 4);
            }
            break;
        }
        case 3:
        {
            if (cctvDirection[i] == 1)
            {
                detect(x, y, 1);
                detect(x, y, 3);
            }
            else if (cctvDirection[i] == 2)
            {
                detect(x, y, 1);
                detect(x, y, 4);
            }
            else if (cctvDirection[i] == 3)
            {
                detect(x, y, 2);
                detect(x, y, 3);
            }
            else if (cctvDirection[i] == 4)
            {
                detect(x, y, 2);
                detect(x, y, 4);
            }
            break;
        }
        case 4:
        {
            if (cctvDirection[i] == 1)
            {
                detect(x, y, 1);
                detect(x, y, 3);
                detect(x, y, 4);
            }
            else if (cctvDirection[i] == 2)
            {
                detect(x, y, 1);
                detect(x, y, 2);
                detect(x, y, 4);
            }
            else if (cctvDirection[i] == 3)
            {
                detect(x, y, 1);
                detect(x, y, 2);
                detect(x, y, 3);
            }
            else if (cctvDirection[i] == 4)
            {
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

int getBlind()
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

// 모든 cctv에 대한 방향을 설정하는 재귀함수
void dfs(int idx, int cnt)
{
    if (cnt == cctv.size())
    {
        copyMap();

        setCCTV();

        ans = min(ans, getBlind());
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;

    for (int k = 1; k <= 4; k++)
    {
        //5번 cctv는 한방향만 탐색
        if (arr[x][y] == 5 && k > 1)
            continue;
        //2번 cctv는 두방향만 탐색
        if (arr[x][y] == 2 && k > 2)
            continue;

        cctvDirection[idx] = k;
        dfs(idx + 1, cnt + 1);
        cctvDirection[idx] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            // cctv 의 좌표를 벡터에 넣는다
            if (arr[i][j] >= 1 && arr[i][j] <= 5)
                cctv.push_back({i, j});
        }
    }
    ans = INF;
    dfs(0, 0);
    cout << ans << '\n';
}