// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// #define INF 987654321
// #define MAX 1000
// char arr[MAX][MAX];
// int fire[MAX][MAX];
// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};
// bool visit_jh[MAX][MAX];
// bool visit_fire[MAX][MAX];
// int R, C;
// int ans = INF;
// queue<pair<pair<int, int>, int>> move_q;
// queue<pair<int, int>> fire_q;

// void set_fire_time()
// {
//     while (!fire_q.empty())
//     {
//         for (int i = 0; i < fire_q.size(); i++)
//         {
//             int x = fire_q.front().first;
//             int y = fire_q.front().second;
//             int cur_time = fire[x][y];
//             visit_fire[x][y] = true;

//             fire_q.pop();

//             for (int i = 0; i < 4; i++)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if (visit_fire[nx][ny])
//                     continue;
//                 if (nx < 0 || ny < 0 || nx >= R || nx >= C)
//                     continue;
//                 if (arr[nx][ny] != '#' && fire[nx][ny] == -1)
//                 {
//                     fire_q.push({nx, ny});
//                     fire[nx][ny] = cur_time + 1;
//                     visit_fire[nx][ny] = true;
//                 }
//             }
//         }
//     }
// }

// void run_jh()
// {
//     while (!move_q.empty())
//     {
//         int x = move_q.front().first.first;
//         int y = move_q.front().first.second;
//         int cur_time = move_q.front().second;
//         visit_jh[x][y] = true;
//         move_q.pop();

//         if (x == 0 || y == 0 || x == R - 1 || y == C - 1)
//         {
//             cout<< cur_time+1;
//             ans = cur_time+1;
//             //ans = min(ans, cur_time + 1);
//             return;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (visit_jh[nx][ny])
//                 continue;
//             if (arr[nx][ny] == '#')
//                 continue;
//             if (nx >= 0 || ny >= 0 || nx < R || nx < C)
//             {
//                 if (cur_time + 1 < fire[nx][ny])
//                 {
//                     move_q.push({{nx, ny}, cur_time + 1});
//                     visit_jh[nx][ny] = true;
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     memset(fire, -1, sizeof(fire));
//     memset(visit_fire, false, sizeof(visit_fire));
//     memset(visit_jh, 0, sizeof(visit_jh));

//     cin >> R >> C;

//     for (int i = 0; i < R; i++)
//     {
//         for (int j = 0; j < C; j++)
//         {
//             cin >> arr[i][j];
//             if (arr[i][j] == 'J')
//                 move_q.push({{i, j}, 0}); //시작 위치
//             if (arr[i][j] == 'F')
//             {
//                 fire[i][j] = 0;
//                 fire_q.push({i, j}); // 불 위치
//             }
//         }
//     }
//     set_fire_time();

//     run_jh();

//     if (ans == INF)
//         cout << "IMPOSSIBLE";
// }