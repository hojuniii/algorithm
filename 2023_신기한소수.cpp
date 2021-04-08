#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool isPrime(int num)
{
    if (num == 0 || num == 1)
        return false;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void calc(int num, int len)
{
    if (len == n)
    {
        cout << num << "\n";
        return;
    }

    //홀수만
    for (int i = 1; i <= 9; i += 2)
    {
        if (isPrime(num * 10 + i))
            calc(num * 10 + i, len + 1);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;

    calc(2, 1);
    calc(3, 1);
    calc(5, 1);
    calc(7, 1);
}