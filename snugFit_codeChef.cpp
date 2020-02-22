#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t, i, n, c = 0,sum;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin >> n;
        int *a = new int[n];
        int *b = new int[n];
        for (i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n;i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for (i = 0; i < n;i++)
        {
            if(a[i] < b[i])
            {
                sum += a[i];
            }
            else
            {
                sum += b[i];
            }
        }
        cout << sum<<endl;
    }
}

