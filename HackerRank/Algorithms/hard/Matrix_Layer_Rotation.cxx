#include <bits/stdc++.h>
#include <numeric>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


void solve(vector<vector<int>>& out, vector<vector<int>> m, int r)
{
    
    for (int x = 0; x < std::min(m.size(), m[0].size())/2; ++x)
    {
        int s = (m.size()-2*x)*2 + (m[0].size()-2*x)*2 - 4;
        for (int rr = 0; rr < (r % s); ++rr)
        {
            for (int i = x; i < m[0].size()-x-1; ++i)
                out[x][i] = m[x][i+1];
            for (int i = x; i < m.size()-x-1; ++i)
                out[i][m[0].size()-x-1] = m[i+1][m[0].size()-x-1];
            for (int i = m[0].size()-1-x; i >= x+1; --i)
                out[m.size()-1-x][i] = m[m.size()-1-x][i-1];
            for (int i = m.size()-1-x; i >= x+1; --i)
                out[i][x] = m[i-1][x];
            m=out;
        }
        
    }
}
// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    auto out = matrix;

    solve(out, matrix, r);

    for (auto& l : out)
    {
        for (auto x : l)
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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

