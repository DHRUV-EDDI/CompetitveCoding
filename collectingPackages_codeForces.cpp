#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, x, y, right, up, n;
    vector<pair<int, int>> xy;
    string route;
    cin >> t;
    while (t--)
    {
        xy.clear();
        route.erase();
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x >> y;
            xy.emplace_back(x, y);
        }
        sort(xy.begin(), xy.end());
        right = xy[0].first;
        up = xy[0].second;
        for (i = 0; i < right; i++)
        {
            route.push_back('R');
        }
        for (i = 0; i < up; i++)
        {
            route.push_back('U');
        }
        for (i = 1; i < xy.size(); i++)
        {
            right = xy[i].first - xy[i - 1].first;
            up = xy[i].second - xy[i - 1].second;
            if (right < 0 || up < 0)
            {
                route = "NO";
                break;
            }
            else
            {
                for (j = 0; j < right; j++)
                {
                    route.push_back('R');
                }
                for (j = 0; j < up; j++)
                {
                    route.push_back('U');
                }
            }
        }
        if (route == "NO")
        {
            cout << "NO";
        }
        else
        {
            cout << "YES\n";
            cout << route;
        }
        cout << "\n";
    }
}

