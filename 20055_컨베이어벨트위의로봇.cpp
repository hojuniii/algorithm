#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int arr[200];
bool robot[200];
int n, k;
int zeroCount = 0;

//한칸 회전
void firstStep()
{
    int temp = arr[2 * n - 1];
    for (int i = 2 * n - 1; i >= 1; i--)
    {
        robot[i] = robot[i - 1];
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    robot[0] = false;
}

void secondStep()
{
    if (robot[n - 1])
        robot[n - 1] = false;

    for (int i = n - 2; i >= 0; i--)
    {
        if (robot[i] && arr[i + 1] > 0 && !robot[i + 1])
        {
            robot[i] = false;
            robot[i + 1] = true;
            arr[i + 1] -= 1; //내구도 감소
            if (arr[i + 1] == 0)
                zeroCount++;
        }
    }

    if (robot[n - 1])
        robot[n - 1] = false;
}

void thirdStep()
{
    if (arr[0] > 0 && !robot[0])
    {
        robot[0] = true;
        arr[0]--;
        if (arr[0] == 0)
            zeroCount++;
    }
}

int main()
{
    memset(arr, 0, sizeof(arr));
    memset(robot, false, sizeof(robot));
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        robot[i] = 0;
    }
    int cnt = 0;
    while (zeroCount < k)
    {
        cnt++;
        firstStep();
        secondStep();
        thirdStep();
    }
    cout << cnt << endl;
}
