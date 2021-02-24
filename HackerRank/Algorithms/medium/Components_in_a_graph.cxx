#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */



vector<int> componentsInGraph(vector<vector<int>> gb) {
    vector<vector<int>> edges(60000, std::vector<int>());
    for (auto& p : gb)
    {
        edges[p[0]].push_back(p[1]);
        edges[p[1]].push_back(p[0]);
    }
    

    vector<int> done(60000, -1);
      
    int t = 0;
    int mini = std::numeric_limits<int>::max();
    int maxi = 0;
    for (int t = 0; t < done.size(); ++t)
    {   
        if (done[t] != -1 || edges[t].size() == 0) continue;
        std::queue<int> q;
        q.push(t);
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            done[x] = t;
            for (auto& e : edges[x])
            {
                if (done[e] == -1)
                {
                    q.push(e);
                }
            }
        }
        
        auto r = std::count(done.begin(), done.end(), t);
        if (r > 1 && r < mini) mini = r;
        if (r > 1 && r > maxi) maxi = r;
    }
    return {mini, maxi};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

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

