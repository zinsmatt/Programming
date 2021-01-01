#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<vector<long>> m(n, vector<long>(n, -1));
    vector<unordered_map<int, int>> g(n);
    for (auto& e : edges)
    {
        int a = e[0]-1;
        int b = e[1]-1;
        if (g[a].find(b) != g[a].end()){
            g[a][b] = std::min(g[a][b], e[2]);
            g[b][a] = std::min(g[b][a], e[2]);
        }
        else {
            g[a][b] = e[2];
            g[b][a] = e[2];
        }
    }
    
    
    --s;
    vector<long> cost(n, numeric_limits<long>::max());
    vector<bool> done(n, false);
    cost[s] = 0;
    int cur = s;
    while (1)
    {
        long min_cost = numeric_limits<long>::max();
        int min_idx = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!done[i] && cost[i] < min_cost)
            {
                min_cost = cost[i];
                min_idx = i;
            }
        }
        if (min_idx == -1)
            break;
        done[min_idx] = true;
        
        for (auto e : g[min_idx])
        {
            auto new_cost = cost[min_idx] + e.second;
            cost[e.first] = std::min(cost[e.first], new_cost);
        }
        
        

    }
    
    vector<int> res(n-1);
    int a = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != s)
            res[a++] = cost[i];
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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

