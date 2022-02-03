#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> v;

void print_stack(stack<char> &stack)
{
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}

int main()
{
    string str;
    getline(cin, str);
    int pos = 0;
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '<')
        {
            print_stack(st);
            while (true)
            {
                cout << str[i];
                if (str[i] == '>')
                    break;
                i++;
            }
        }
        else if (str[i] == ' ')
        {
            print_stack(st);
            cout << ' ';
        }
        else
        {
            st.push(str[i]);
        }
    }
    
    print_stack(st);
}