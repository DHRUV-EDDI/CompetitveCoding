#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c, x, y, z, noOfRibbonPieces = 0, i, j, k, m;
    cin >> n >> a >> b >> c;
    m = min(min(a, b), c);
    // cout << "a = " << a << " b = " << b << " c = " << c;
    if (n % m == 0)
    {
        noOfRibbonPieces = n / m;
    }
    else
    {
        x = n / a;
        y = n / b;
        for (i = 0; i <= x; i++)
        {
            for (j = 0; j <= y; j++)
            {
                k = (n - i * a - j * b) / c;
                if (k >= 0)
                {
                    if (a * i + b * j + c * k == n)
                    {
                        noOfRibbonPieces = max(noOfRibbonPieces, i + j + k);
                    }
                }
            }
        }
    }
    cout << noOfRibbonPieces;
}

