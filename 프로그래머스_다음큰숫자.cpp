#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int cnt1 = 0;

    int answer = 0;
    int nextNum = n;
    while (n > 0)
    {
        int remain = 0;
        remain = n % 2;
        if (remain)
            cnt1++;
        n /= 2;
    }
    int cnt2 = 0;
    while (true)
    {

        nextNum++;
        int temp = nextNum;
        while (temp > 0)
        {
            int remain = 0;
            remain = temp % 2;
            if (remain)
                cnt2++;
            temp /= 2;
        }
        if (cnt1 == cnt2)
            return nextNum;
        else
            cnt2 = 0;
    }
}