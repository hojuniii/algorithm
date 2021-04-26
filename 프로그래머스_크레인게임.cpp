#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    vector<int> v;
    stack<int> st;
    int answer = 0;
    for (int k = 0; k < moves.size(); k++)
    {
        int col = moves[k] - 1;
        for (int row = 0; row < board.size(); row++)
        {
            if (board[row][col] != 0)
            {
                if (!st.empty() && st.top() == board[row][col])
                {
                    st.pop();
                    answer += 2;
                }
                else
                {
                    st.push(board[row][col]);
                }

                board[row][col] = 0;
                break;
            }
        }
    }

    return answer;
}