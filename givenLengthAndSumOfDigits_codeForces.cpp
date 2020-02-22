#include <bits/stdc++.h>
using namespace std;


void display(char *s , int m)
{
    int i=0;
    for(;i<=m;i++)
    {
        cout<<s[i];
    }
    cout<<" ";
}
bool isSumEqual(char* str , int m , int n)
{
    int i,sum=0;
    for(i=0;i<m;i++)
    {
        sum += str[i]-48;
    }
    if(sum == n)
    {
        return true;
    }
    return false;
}
int main()
{
    int m , s,i,j,rem,flag=1;
    cin>>m>>s;
    char *str = new char[m];
    if(m == 1 && s == 0)
    {
        cout<<"0 0";
    }
    else if(s == 0 || 9*m < s)
    {
        cout<<"-1 -1";
    }
    else
    {
        i=0;
        while(true)
        {
            if(i>8)
            {
                flag =0;
                break;
            }
            str[0] = (char)(48+i+1);
            rem = s-(i+1);
            for(j=m-1;j>0;j--)
            {
                if(rem<=9)
                {
                    str[j] = (char)(rem+48);
                    rem =0;
                }
                else
                {
                    str[j] = (char)(9+48);
                    rem -= 9;
                }
            }
            if(isSumEqual(str , m , s))
            {
                display(str , m-1);
                break;
            }
            i++;
        }
        if(flag == 0)
        {
            cout<<"-1 -1";
        }
        else
        {
            i=0;
            while(true)
            {
                if(i>8)
                {
                    break;
                }
                str[0] = (char)(48+(9-i));
                rem=s-(9-i);
                if(rem < 0)
                {
                    i++;
                    continue;
                }
                for(j=1;j<m;j++)
                {
                    if(rem <= 9)
                    {
                        str[j] = (char)(rem+48);
                        rem=0;
                    }
                    else
                    {
                        str[j] = (char)(9+48);
                        rem -= 9;
                    }
                }
                if(isSumEqual(str , m , s))
                {
                    display(str , m-1);
                    break;
                }
                i++;
            }
        }
    }
}

