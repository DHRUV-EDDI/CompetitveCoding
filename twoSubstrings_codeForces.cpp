#include <bits/stdc++.h>
using namespace std;

bool baFirst(string s, int len)
{
    int i, flag = 1;
    set<int> storage;
    bool baNotInserted = true;
    for (i = 0; i < len; i++)
    {
        if (s[i] == 'B' && baNotInserted)
        {
            if (s[i + 1] == 'A')
            {
                baNotInserted = false;
                storage.insert(i);
                storage.insert(i + 1);
                i++;
            }
        }
        else if (s[i] == 'A' && baNotInserted == false)
        {
            if (s[i + 1] == 'B')
            {
                storage.insert(i);
                storage.insert(i + 1);
                i++;
            }
        }
        if (storage.size() == 4)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        return true;
    }
    return false;
}
bool abFirst(string s, int len)
{
    int i, flag = 1;
    set<int> storage;
    bool abNotInserted = true;
    for (i = 0; i < len; i++)
    {
        if (s[i] == 'A' && abNotInserted)
        {
            if (s[i + 1] == 'B')
            {
                abNotInserted = false;
                storage.insert(i);
                storage.insert(i + 1);
                i++;
            }
        }
        else if (s[i] == 'B' && abNotInserted == false)
        {
            if (s[i + 1] == 'A')
            {
                storage.insert(i);
                storage.insert(i + 1);
                i++;
            }
        }
        if (storage.size() == 4)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    bool ans = abFirst(s, len) || baFirst(s, len);
    if (ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

