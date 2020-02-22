#include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int t,a,b,c,maxi,mini,midd,i,n;
        cin>>t;
        for(i=0;i<t;i++)
        {
            cin>>a>>b>>c>>n;
            maxi = max(a,max(b,c));
            mini= min(a,min(b,c));
            if((a<=b) && (b<=c) || (c<=b) && (b<=a))
            {
                // cout << "b is midd\n";
                midd = b;
            }
            else if((b<=c) && (c<=a) || (a<=c) && (c<=b))
            {
                // cout << "c is midd\n";
                midd = c;
            }
            else if((c<=a) && (a<=b) || (b<=a) && (a<=c))
            {
                // cout << "a is midd\n";
                midd = a;
            }
            // cout << a << " " << b << " " << c << "\n";
            // cout << maxi << " " << mini << " " << midd << "\n";
            n -= (maxi-midd);
            // cout << "n = " << n << "\n";
            n -= (maxi-mini);
            // cout << "n = " << n << "\n";
            if(n>=0 && n%3 == 0)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }

