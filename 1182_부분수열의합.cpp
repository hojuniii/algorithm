#include <cstring>
#include <iostream>
using namespace std;

int numbers[20];
int n, s, cnt = 0;

void dfs(int sum, int input)
{
    if (sum == s && input != 0)
    {
        cnt++;
    }
    if (input == n)
        return;
    for (int i = input; i < n; i++)
    {
        dfs(sum + numbers[i], i + 1);
    }
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers[i] = num;
    }
    dfs(0, 0);
    cout << cnt << endl;

    return 0;
}