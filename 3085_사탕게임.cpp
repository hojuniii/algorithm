#include <iostream>
#include <math.h>
using namespace std;

int maxCount = -1;
char arr[51][51];
char tempArr[51][51];
int n;

void checkRow()
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (tempArr[i][j] == tempArr[i][j + 1])
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                count = 0;
            }
        }
    }
}

void checkCol()
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (tempArr[j][i] == tempArr[j + 1][i])
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                count = 0;
            }
        }
    }
}

void setArray()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tempArr[i][j] = arr[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char a;
            cin >> a;
            arr[i][j] = a;
            tempArr[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tempArr[i][j] != tempArr[i][j + 1])
            {
                char temp = tempArr[i][j];
                tempArr[i][j] = tempArr[i][j + 1];
                tempArr[i][j + 1] = temp;
            }
            checkRow();
            checkCol();
            setArray();
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tempArr[j][i] != tempArr[j + 1][i])
            {
                char temp = tempArr[i][j];
                tempArr[i][j] = tempArr[i + 1][j];
                tempArr[i + 1][j] = temp;
            }
            checkRow();
            checkCol();
            setArray();
        }
    }

    cout << maxCount + 1 << endl;

    return 0;
}