
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int nowNum, areaSum, M, N;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visit[101][101] = {
    false,
};
vector<vector<int>> gPicture;

void dfs(int sx, int sy)
{
    for (int d = 0; d < 4; d++)
    {
        int nx = sx + dx[d];
        int ny = sy + dy[d];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N || visit[nx][ny] || nowNum != gPicture[nx][ny])
        {
            continue;
        }
        areaSum++;
        visit[nx][ny] = true;
        dfs(nx, ny);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    memset(visit, false, sizeof(visit));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    gPicture = picture;
    

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j] && picture[i][j])
            {
                nowNum = picture[i][j];
                areaSum = 1;
                number_of_area++;
                visit[i][j] = true;
                dfs(i, j);
                max_size_of_one_area = max(max_size_of_one_area, areaSum);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = {
        {1, 1, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1}};

    vector<int> answer = solution(m, n, picture);
}