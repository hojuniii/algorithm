#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[500][500];
int h, w;

int main()
{
    vector<int> v;
    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }
    int answer = 0;

    for (int i = 1; i < w - 1; i++)
    {
        int left = 0, right = 0;

        //자신의 왼쪽중에 제일 큰애
        for (int j = 0; j < i; j++)
            left = max(left, v[j]);

        //자신의 오른쪽중에 제일 큰애
        for (int j = w - 1; j > i; j--)
            right = max(right, v[j]);
        
        // 차이를 구해서 더함. 
        // min(left, right) - v[i] < 0 : 채울게 없다
        answer += max(0, min(left, right) - v[i]);
    }
    cout << answer << endl;
}