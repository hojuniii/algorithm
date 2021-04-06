#include <iostream>
using namespace std;

int arr[1000000];
int main()
{
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lo = 0, hi = 1000000000;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] > mid)
                sum += arr[i] - mid;

        if (sum >= m)
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;

    return 0;
}