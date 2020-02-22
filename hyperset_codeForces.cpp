#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, m, p, c = 0, sum = 'S' + 'E' + 'T', answer = 0;
    cin >> n >> k;
    vector<string> v(n);
    map<string, int> noOfRepeatedSets;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        noOfRepeatedSets[v[i]]++;
    }
    for (j = 0; j < n - 1; j++)
    {
        for (m = j + 1; m < n; m++)
        {
            string third = "";
            for (p = 0; p < k; p++)
            {
                if (v[j][p] == v[m][p])
                {
                    third += v[j][p];
                }
                else
                {
                    third += (sum - v[j][p] - v[m][p]);
                }
            }
            if (noOfRepeatedSets.count(third) > 0)
            {
                answer++;
            }
        }
    }
    cout << answer / 3;
}

