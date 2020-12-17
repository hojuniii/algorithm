#include <iostream>
#include <string>
using namespace std;

int arr[5][8];
int k;

void rotate(int idx)
{
    int last = arr[idx][7];
    for (int i = 7; i > 0; i--)
    {
        arr[idx][i] = arr[idx][i - 1];
    }
    arr[idx][0] = last;
}
void inverse(int idx)
{
    int first = arr[idx][0];
    for (int i = 0; i < 7; i++)
    {
        arr[idx][i] = arr[idx][i + 1];
    }
    arr[idx][7] = first;
}

void execute(int a, int b)
{
    //1번 톱니바퀴
    if (a == 1)
    {
        if (arr[1][2] == arr[2][6])
        {
            b == 1 ? rotate(1) : inverse(1);
        }
        //1 과 2 가 다름
        else
        {
            // 2와 3이 다름
            if (arr[2][2] != arr[3][6])
            {
                // 3과 4가 다름
                if (arr[3][2] != arr[4][6])
                {

                    if (b == 1)
                    {
                        rotate(1), inverse(2), rotate(3), inverse(4);
                    }
                    else
                    {
                        inverse(1), rotate(2), inverse(3), rotate(4);
                    }
                }
                else
                {
                    if (b == 1)
                    {
                        rotate(1), inverse(2), rotate(3);
                    }
                    else
                    {
                        inverse(1), rotate(2), inverse(3);
                    }
                }
            }
            else
            {
                if (b == 1)
                    rotate(1), inverse(2);
                else
                    inverse(1), rotate(2);
            }
        }
    }
    else if (a == 2)
    {
        if (arr[2][6] != arr[1][2])
        {
            b == 1 ? inverse(1) : rotate(1);
        }

        if (arr[2][2] != arr[3][6])
        {
            if (arr[3][2] != arr[4][6])
            {
                if (b == 1)
                {
                    rotate(2), inverse(3), rotate(4);
                }
                else
                {
                    inverse(2), rotate(3), inverse(4);
                }
            }
            else
            {
                if (b == 1)
                {
                    rotate(2), inverse(3);
                }
                else
                {
                    inverse(2), rotate(3);
                }
            }
        }
        else
        {
            b == 1 ? rotate(2) : inverse(2);
        }
    }
    else if (a == 3)
    {
        if (arr[3][2] != arr[4][6])
        {
            b == 1 ? inverse(4) : rotate(4);
        }

        if (arr[3][6] != arr[2][2])
        {
            if (arr[2][6] != arr[1][2])
            {
                if (b == 1)
                {
                    rotate(3);
                    inverse(2);
                    rotate(1);
                }
                else
                {
                    inverse(3);
                    rotate(2);
                    inverse(1);
                }
            }
            else
            {
                if (b == 1)
                {
                    rotate(3);
                    inverse(2);
                }
                else
                {
                    inverse(3);
                    rotate(2);
                }
            }
        }
        else
        {
            b == 1 ? rotate(3) : inverse(3);
        }
    }
    else if (a == 4)
    {
        if (arr[4][6] == arr[3][2])
        {
            b == 1 ? rotate(4) : inverse(4);
        }
        else
        {
            if (arr[3][6] != arr[2][2])
            {
                if (arr[2][6] != arr[1][2])
                {

                    if (b == 1)
                        rotate(4), inverse(3), rotate(2), inverse(1);
                    else
                    {
                        inverse(4),
                            rotate(3), inverse(2), rotate(1);
                    }
                }
                else
                {
                    if (b == 1)
                    {
                        rotate(4), inverse(3), rotate(2);
                    }
                    else
                    {
                        inverse(4), rotate(3), inverse(2);
                    }
                }
            }
            else
            {
                if (b == 1)
                {
                    rotate(4), inverse(3);
                }
                else
                    inverse(4), rotate(3);
            }
        }
    }
}

int getScore()
{
    int sum = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (arr[i][0] == 0)
            continue;
        else
        {
            if (i == 1)
                sum += 1;
            else if (i == 2)
                sum += 2;
            else if (i == 3)
                sum += 4;
            else if (i == 4)
                sum += 8;
        }
    }

    return sum;
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    scanf("%d", &k);

    while (k--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        execute(a, b);
    }

    printf("%d", getScore());

    return 0;
}