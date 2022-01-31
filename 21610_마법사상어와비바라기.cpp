#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int crossX[4] = {-1, -1, 1, 1};
int crossY[4] = {-1, 1, -1, 1};
int a[101][101];
bool visit[101][101];
int is_cloud[101][101]; // 0 - 구름이 아닌 칸 / 1 - 구름 /  3 - (2번에서)물이 증가한 칸, 사라진칸
int n, m;
vector<pair<int, int>> cloud;

void move_cloud(int d, int s)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (is_cloud[i][j] == 1)
            {

                // int x = i + (dx[d] * s) % n;
                // int y = j + (dy[d] * s) % n;
                int nx = i, ny = j;

                for (int k = 0; k < s; k++)
                {
                    nx += dx[d];
                    ny += dy[d];

                    if (nx == 0)
                    {
                        nx = n;
                    }
                    else if (nx > n)
                    {
                        nx = 1;
                    }

                    if (ny == 0)
                    {
                        ny = n;
                    }
                    else if (ny > n)
                    {
                        ny = 1;
                    }
                }

                cout << "이동후:" << nx << ',' << ny << endl;
                is_cloud[nx][ny] = 1;
                is_cloud[i][j] = 0;
            }
        }
    }
}

void rain()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (is_cloud[i][j] == 1)
            {
                a[i][j] += 1;
                is_cloud[i][j] = 3;
            }
        }
    }
}

// void delete_cloud()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (is_cloud[i][j] != 3)
//             {
//                 is_cloud[i][j] = 0; // 사라진 모든 구름
//             }
//         }
//     }
// }

void increase_water()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (is_cloud[i][j] == 3)
            {
                int count_water = 0;
                for (int k = 1; k <= 4; k++)
                {
                    int ni = i + crossX[k];
                    int nj = j + crossY[k];
                    if (ni < 1 || nj < 1 || ni > n || nj > n)
                        continue;
                    if (a[ni][nj] > 0)
                    {
                        count_water++;
                    }
                }
                a[i][j] += count_water;
            }
}

void go()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다
            //이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
            if (a[i][j] >= 2 && is_cloud[i][j] != 3)
            {
                is_cloud[i][j] = 1;
                a[i][j] -= 2;
            }
            else if (is_cloud[i][j] == 3)
            {
                is_cloud[i][j] = 0;
            }
        }
    }
}

int get_water()
{
    int temp = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            temp += a[i][j];
        }

    return temp;
}

int main()
{
    memset(is_cloud, 0, sizeof(is_cloud));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    //비구름 생성
    is_cloud[n][1] = is_cloud[n][2] = is_cloud[n - 1][1] = is_cloud[n - 1][2] = 1;

    for (int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;

        // 1. d 방향으로 s 만큼 이동
        move_cloud(d, s);

        // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
        rain();

        // 3.구름이 모두 사라진다.
        // delete_cloud();

        // 4. 2의 구름이 있었던 자리의 대각선의 개수만큼 물의 개수 증가
        increase_water();

        // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
        //이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
        go();
    }

    cout << get_water() << endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout<<a[i][j]<< ' ';
    //     }
    //     cout<<endl;
    // }
}