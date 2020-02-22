#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, i, n, c = 0, sum, min, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long long *beforeData = new long long[n + 1];
        long long *afterData = new long long[n + 1];
        long long *a = new long long[n + 1];
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        beforeData[0] = 0;
        for (i = 1; i <= n; i++)
        {
            beforeData[i] = beforeData[i - 1] + (a[i] % k);
        }
        afterData[n] = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[i + 1] % k != 0)
            {
                afterData[i] = afterData[i + 1] + ((k * ((a[i + 1] / k) + 1)) - a[i + 1]);
            }
            else
            {
                afterData[i] = afterData[i + 1];
            }
        }
        // for (i = 0; i <= n; i++)
        // {
        //     cout << beforeData[i] << " ";
        // }
        // cout << endl;
        // for (i = 0; i <= n; i++)
        // {
        //     cout << afterData[i] << " ";
        // }
        // cout << endl
        //      << endl;
        if (afterData[0] == beforeData[0])
        {
            cout << 0 << endl;
        }
        else
        {
            min = beforeData[n];
            for (i = 1; i <= n; i++)
            {
                if (beforeData[i] - afterData[i] >= 0)
                {
                    if (beforeData[i] - afterData[i] < min)
                    {
                        min = beforeData[i] - afterData[i];
                    }
                }
            }
            cout << min << endl;
        }
    }
}

