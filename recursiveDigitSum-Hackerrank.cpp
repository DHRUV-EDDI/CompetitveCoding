#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//MY CODE STARTS HERE
int finalSum(unsigned long long int a)
{
    int sum=0 , rem;
    if(a/10 == 0)
    {
        return a;
    }
    while(a!=0)
    {
        rem = a%10;
        sum+=rem;
        a=a/10;
    }
    return finalSum(sum);
}
// Complete the superDigit function below.
int superDigit(string n, int k) {
    int len = n.length(),i;
    unsigned long long sum=0;
    for(i=0;i<len;i++)
    {
        sum += (unsigned long long)n[i]-48;
    }
    sum *= k;
    return finalSum(sum);
}
//MY CODE ENDS HERE

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
