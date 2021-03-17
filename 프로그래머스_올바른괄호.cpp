#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    bool answer = true;
    int len = s.length();
    for (auto c : s)
    {
        if (c == '(')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            else
                st.pop();
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << solution("(())()");
}