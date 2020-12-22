#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'clique' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */


 int t(int n, int k)
 {
    double nn = n;
    double kk = k;
    return nn*(nn-1)/2 - (double)(n % k) * (std::ceil(nn/kk)* (std::ceil(nn/kk)-1.0)) * 0.5 - (double)(k - (n % k)) * (std::floor(nn/kk) * (std::floor(nn/kk)-1.0)) * 0.5;
 }
 
 int solve(int l, int r, int m, int n)
 {
    if (l == r) return l;
    if (l + 1 == r) {
        if (t(n, l) < m) return r;
        else return l;
    }
    int mid = (l+r)/2;
    auto tt = t(n, mid);
    if (tt < m) return solve(mid+1, r, m, n);
    else return solve(l, mid, m, n);
 }
 

int clique(int n, int m) {
  return solve(1, n+1, m, n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = clique(n, m);

        fout << result << std::endl;
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

