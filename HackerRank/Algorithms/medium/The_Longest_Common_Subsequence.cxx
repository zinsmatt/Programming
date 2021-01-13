#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> solve(std::vector<std::vector<vector<int>>>& C, const std::vector<int>& a, std::vector<int>& b, int ia, int ib)
{
    if (ia < 0 || ib < 0)
    {
        return {};
    }
    
    
    if (C[ib][ia].size())
    {
        return C[ib][ia];
    }
    

    if (a[ia] == b[ib])
    {
        auto res = solve(C, a, b, ia-1, ib-1);
        res.push_back(a[ia]);
        C[ib][ia] = res;
        return res;
    }
    else {
        auto res1 = solve(C, a, b, ia-1, ib);
        auto res2 = solve(C, a, b, ia, ib-1);
        if (res1.size() >= res2.size())
        {
            C[ib][ia] = res1;
            return  res1;
        } else {
            C[ib][ia] = res2;
            return res2;
        }

    }
}

// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    std::vector<std::vector<vector<int>>> C(b.size(), vector<vector<int>>(a.size()));
    auto res = solve(C, a, b, a.size()-1, b.size()-1);
    return res;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

