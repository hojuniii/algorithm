// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// struct Mal
// {
//     int x, y, dir;
// };

// int dx[5] = {0, 0, 0, -1, 1};
// int dy[5] = {0, 1, -1, 0, 0};
// int arr[13][13];
// vector<int> map_state[13][13];
// int turn = 0;
// int n, k;
// vector<Mal> v[11];

// int main()
// {
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     //행 열 방향(동서북남)
//     for (int i = 1; i <= k; i++)
//     {
//         int x, y, dir;
//         cin >> x >> y >> dir;
//         v[i].push_back({x, y, dir});
//         map_state[x][y].push_back(i);
//     }

//     bool finish = false;

//     while (true)
//     {
//         if (turn > 1000)
//         {
//             cout << -1;
//             return 0;
//         }

//         for (int i = 1; i <= k; i++)
//         {
//             int cx = v[i].front().x;
//             int cy = v[i].front().y;
//             int dir = v[i].front().dir;
//             int size = map_state[cx][cy].size();

//             vector<int> vv;
//             if (size > 0)
//             {
//                 bool found = false;
//                 for (int j = 0; j < size; j++)
//                 {
//                     if (!found)
//                     {
//                         if (map_state[cx][cy][j] == i)
//                         {
//                             found = true;
//                             vv.push_back(map_state[cx][cy][j]);
//                         }
//                     }
//                     else
//                     {
//                         vv.push_back(map_state[cx][cy][j]);
//                     }
//                 }
//             }
//             int nx = cx + dx[dir];
//             int ny = cy + dy[dir];
//             int val = arr[nx][ny];
//             if (val == 2)
//             {
//                 int rd;
//                 if (dir == 1)
//                     rd = 2;
//                 else if (dir == 2)
//                     rd = 1;
//                 else if (dir == 3)
//                     rd = 4;
//                 else if (dir == 4)
//                     rd = 3;
//                 nx = cx + dx[rd];
//                 ny = cy + dy[rd];
//                 v[i][0].dir = rd;
//                 if (arr[nx][ny] == 2)
//                     continue;
//                 else
//                     val = arr[nx][ny];
//             }
//             for (int k = 0; k < vv.size(); k++)
//                 map_state[cx][cy].pop_back();
//             if (val == 1)
//                 reverse(vv.begin(), vv.end());

//             for (int k = 0; k < vv.size(); k++)
//             { 
//                 int cIdx = vv[k];
//                 map_state[nx][ny].push_back(cIdx);
//                 v[cIdx][0].x = nx;
//                 v[cIdx][0].y = ny;
//             }
//             if (map_state[nx][ny].size() > 3)
//             {
//                 finish = true;
//                 break;
//             }
//             if (finish)
//                 break;
//         }
//         turn++;
//     }
//     if (finish)
//         cout << turn;

//     return 0;
// }