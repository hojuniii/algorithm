#include <iostream>
using namespace std;

typedef struct
{
    int x, y;
    int dir;
} Fish;

int ans;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

void solve(int board[4][4], Fish fish[], int sharkX, int sharkY, int sum)
{
    int tempBoard[4][4];
    Fish tempFish[16];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tempBoard[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < 16; i++)
    {
        tempFish[i] = fish[i];
    }

    //eat
    int fishNum = tempBoard[sharkX][sharkY];
    int sharkDir = tempFish[fishNum].dir;
    tempFish[fishNum].x = -1;
    tempFish[fishNum].y = -1;
    tempFish[fishNum].dir = -1;
    tempBoard[sharkX][sharkY] = -1;

    sum += (fishNum + 1);
    if (ans < sum)
    {
        ans = sum;
    }

    //move fish
    for (int f = 0; f < 16; f++)
    {
        if (tempFish[f].x == -1)
            continue;
        int x = tempFish[f].x;
        int y = tempFish[f].y;
        int dir = tempFish[f].dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int nd = dir;
        while (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (nx == sharkX && ny == sharkY))
        {
            nd += 1;
            nd %= 8;
            nx = x + dx[nd];
            ny = y + dy[nd];
        }

        //이동 가능
        if (tempBoard[nx][ny] != -1)
        {
            int nextFishNum = tempBoard[nx][ny];
            tempFish[nextFishNum].x = x;
            tempFish[nextFishNum].y = y;

            tempFish[f].x = nx;
            tempFish[f].y = ny;
            tempFish[f].dir = nd;

            tempBoard[x][y] = nextFishNum;
            tempBoard[nx][ny] = f;
        }
        else
        {
            tempBoard[nx][ny] = f;
            tempFish[f].x = nx;
            tempFish[f].y = ny;
            tempFish[f].dir = nd;
            tempBoard[x][y] = -1;
        }
    }

    for (int step = 1; step < 4; step++)
    {
        int nextSx = sharkX + dx[sharkDir] * step;
        int nextSy = sharkY + dy[sharkDir] * step;

        if (nextSx < 0 || nextSy < 0 || nextSx >= 4 || nextSy >= 4)
            continue;
        if (tempBoard[nextSx][nextSy] != -1)
            solve(tempBoard, tempFish, nextSx, nextSy, sum);
    }
}

int main()
{
    Fish fish[16];
    int board[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            fish[a].x = i;
            fish[a].y = j;
            fish[a].dir = b;
            board[i][j] = a;
        }
    }
    ans = 0;
    solve(board, fish, 0, 0, 0);

    cout << ans << endl;
}