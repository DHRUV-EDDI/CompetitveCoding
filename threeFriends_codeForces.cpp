#include <bits/stdc++.h>
#define Int long long
using namespace std;

Int findPairwiseDistance(Int a, Int b, Int c, Int i, Int j, Int k , Int *move)
{
    a += move[i];
    b += move[j];
    c += move[k];
    return (abs(a - b) + abs(b - c) + abs(c - a));
}
int main()
{
    long long t, a, b, c, i, j, k,min,dis;
    Int move[3] = {1,0,-1};

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        min = abs(a - b) + abs(b - c) + abs(c - a);
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                for (k = 0; k < 3; k++)
                {
                    dis = findPairwiseDistance(a, b, c, i, j, k,move);
                    if (dis < min)
                    {
                        min = dis;
                    }
                }
            }
        }
        cout << min << endl;
    }
}

