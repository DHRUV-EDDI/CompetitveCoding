#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void change(char a , char &b)
{
    if(b == 'R')
    {
        b = 'G';
    }
    else if(b == 'G')
    {
        b = 'B';
    }
    else
    {
        b = 'R';
    }
}
void change(char a, char &b, char c)
{
    if (b == c)
    {
        if (b == 'R')
        {
            b = 'G';
        }
        else if (b == 'G')
        {
            b = 'B';
        }
        else
        {
            b = 'R';
        }
    }
    else
    {
        if (b == 'R' && c == 'G')
        {
            b = 'B';
        }
        else if (b == 'R' && c == 'B')
        {
            b = 'G';
        }
        else if (b == 'G' && c == 'B')
        {
            b = 'R';
        }
        else if (b == 'G' && c == 'R')
        {
            b = 'B';
        }
        else if (b == 'B' && c == 'G')
        {
            b = 'R';
        }
        else if (b == 'B' && c == 'R')
        {
            b = 'G';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, n, c = 0;
    string s;
    char a[] = "RGB";
    cin >> n;
    cin >> s;
    // cout << s << endl;
    for (i = 0; i < n - 1;)
    {
        // cout << "i = " << i << endl;
        if (s[i] == s[i + 1])
        {
            c++;
            if(i == n-2)
            {
                change(s[i], s[i + 1]);
            }
            else 
            {
                change(s[i], s[i + 1], s[i + 2]);
            }
            i += 2;
        }
        else
        {
            i++;
        }
    }
    cout << c << endl
         << s;
}

