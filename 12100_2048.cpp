#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int board[20][20];
bool isEmpty[20][20];
int n;
int ans = 1;

void move(int direction)
{
    queue<int> q;
    if (direction == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 0)
                    q.push(board[i][j]);
                board[i][j] = 0;
            }

            int idx = 0;

            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (board[i][idx] == 0)
                    board[i][idx] = val;
                else if (board[i][idx] == val)
                {
                    board[i][idx] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    board[i][idx] = val;
                }
            }
        }
    }
    else if (direction == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (board[i][j] != 0)
                    q.push(board[i][j]);
                board[i][j] = 0;
            }

            int idx = n - 1;

            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (board[i][idx] == 0)
                    board[i][idx] = val;
                else if (board[i][idx] == val)
                {
                    board[i][idx] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    board[i][idx] = val;
                }
            }
        }
    }
    else if (direction == 2)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i][j] != 0)
                    q.push(board[i][j]);
                board[i][j] = 0;
            }

            int idx = 0;

            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (board[idx][j] == 0)
                    board[idx][j] = val;
                else if (board[idx][j] == val)
                {
                    board[idx][j] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    board[idx][j] = val;
                }
            }
        }
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (board[i][j] != 0)
                    q.push(board[i][j]);
                board[i][j] = 0;
            }

            int idx = n - 1;

            while (!q.empty())
            {
                int val = q.front();
                q.pop();

                if (board[idx][j] == 0)
                    board[idx][j] = val;
                else if (board[idx][j] == val)
                {
                    board[idx][j] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    board[idx][j] = val;
                }
            }
        }
    }
}

void dfs(int cnt)
{
    if (cnt == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }

    int temp[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = board[i][j];

    for (int i = 0; i < 4; i++)
    {
        move(i);
        dfs(cnt + 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = temp[i][j];
    }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
}