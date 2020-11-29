#include <iostream>
using namespace std;

int numbers[11];
int oper[4];
int add, di, sub, mul;
int minNum = 1000000001;
int maxNum = -1000000001;
int n;

void calculate(int result, int idx)
{
    if (idx == n)
    {
        if (result > maxNum)
            maxNum = result;
        if (result < minNum)
            minNum = result;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (oper[i] > 0)
        {
            oper[i]--;
            if (i == 0)
                calculate(result + numbers[idx], idx + 1);
            else if (i == 1)
                calculate(result - numbers[idx], idx + 1);
            else if (i == 2)
                calculate(result * numbers[idx], idx + 1);
            else if (i == 3)
                calculate(result / numbers[idx], idx + 1);
            oper[i]++;
        }
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }
    calculate(numbers[0], 1);
    cout << maxNum << '\n'
         << minNum;
}