#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0, start = 1;

    while (start <= n)
    {
        int sum = 0;

        for (int i = start; sum <= n; i++)
        {
            sum += i;
            if (sum == n)
            {
                answer++;
                break;
            }
        }
        start++;
    }

    return answer;
}

int main()
{

    cout << solution(15);
}

// 1 + 2 + 3 + 4 + 5 = 15
// 4 + 5 + 6 = 15
// 7 + 8 = 15
// 15 = 15
