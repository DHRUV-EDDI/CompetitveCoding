#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, j, d, n, sum, min;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n >> d;
        if (d <= n)
        {
            cout << "YES\n";
        }
        else
        {
            for (j = 1; true; j++)
            {
                sum = j + ceil(d / ((double)j + 1));
                // cout << "sum = " << sum << "\n";
                if (j == 1)
                {
                    min = sum;
                    // cout << "min = " << min << "\n";
                }
                else
                {
                    if (sum < min)
                    {
                        min = sum;
                        // cout << "min = " << min << "\n";
                    }
                    else if (sum > min)
                    {
                        break;
                    }
                }
            }
            if (min <= n)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}

