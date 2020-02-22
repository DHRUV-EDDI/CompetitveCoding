#include <iostream>
#define ll long long int
#define ull unsigned long long int
using namespace std;

int main()
{
    int t, i, j, n;
    ll *a = new ll[100099], maxSum, untilNowSum, sum;
    cin >> t;

    for (i = 0; i < t; i++)
    {
        cin >> n;
        sum = 0;
        maxSum = 0;
        untilNowSum = 0;
        for (j = 0; j < n; j++)
        {
            cin >> a[j];
            sum += a[j];
        }
        for (j = 0; j < n - 1; j++)
        {
            if (untilNowSum < 0)
            {
                untilNowSum = a[j];
            }
            else
            {
                untilNowSum += a[j];
            }
            if (untilNowSum > maxSum)
            {
                maxSum = untilNowSum;
            }
        }
        untilNowSum = 0;
        for (j = n - 1; j > 0; j--)
        {
            if (untilNowSum < 0)
            {
                untilNowSum = a[j];
            }
            else
            {
                untilNowSum += a[j];
            }
            if (untilNowSum > maxSum)
            {
                maxSum = untilNowSum;
            }
        }
        if (sum > maxSum)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

