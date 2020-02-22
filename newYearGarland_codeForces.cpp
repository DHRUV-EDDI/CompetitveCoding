#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,i,a,b,c,R,G,B,max,min,mid;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        if(a>b)
        {
            if(c>a)
            {
                max=c;
                min=b;
                mid=a;
            }
            else
            {
                max = a;
                if(b<c)
                {
                    min=b;
                    mid=c;
                }
                else 
                {
                    mid=b;
                    min=c;
                }
            }
        }
        else
        {
            if(c>b)
            {
                max = c;
                if(b<a)
                {
                    min=b;
                    mid=a;
                }
                else
                {
                    min=a;
                    mid=b;
                }
            }
            else
            {
                max = b;
                if(a<c)
                {
                    min=a;
                    mid=c;
                }
                else 
                {
                    min=c;
                    mid=a;
                }
            }
        }
        B=max;
        R=min;
        G=mid;
        if(B > R+G+1)
        {
            cout<<"No\n";
        }
        else 
        {
            cout<<"Yes\n";
        }
    }
}

