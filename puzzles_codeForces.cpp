#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , m , i,j,min,diff;
    cin>>n>>m;
    int *a = new int[m];
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a , a+m);
    for(i=0;i<=m-n ; i++)
    {
        diff = a[i+n-1] - a[i];
        if(i==0)
        {
            min = a[i+n-1] - a[i];
        }
        else if(diff < min)
        {
            min = diff;
        }
    }
    cout<<min;
}

