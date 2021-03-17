#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n)
{
    string answer = "";
    int remain = n;

    while (n > 0)
    {

        remain = n % 3; // 1
        n /= 3;         // 2

        if (remain == 0)
        {
            n -= 1;
            remain = 4;
        }

        answer = to_string(remain) + answer;
    }

    return answer;
}

int main()
{

    cout << solution(5) << endl;
}