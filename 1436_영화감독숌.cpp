#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    cin >> n;
    int cnt = 1;
    int num = 666;
    int flag = 0;

    while (1)
    {
        if (n == cnt)
            break;
        num++;

        int temp = num;
        int flag = 0;

        while (temp)
        {
            int t = temp % 10;
            if (t == 6)
                flag++;
            else if (flag < 3)
                flag = 0;
            temp /= 10;
        }

        if (flag >= 3)
        {
            cnt++;
        }
    }

    cout << num << endl;

    return 0;
}