#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<long long> shortestReach(int n, vector<vector<long long>> edges, int s) {
    vector<unordered_map<int, long long>> g(n+1);
    for (auto& v : edges) {
        if (g[v[0]].find(v[1]) != g[v[0]].end()) {
            g[v[0]][v[1]] = std::min(g[v[0]][v[1]], v[2]);
            g[v[1]][v[0]] = std::min(g[v[1]][v[0]], v[2]);
        } else {
            g[v[0]][v[1]] = v[2];
            g[v[1]][v[0]] = v[2];
        }
    }
    
    const long long INF = std::numeric_limits<long long>::max();
    std::vector<long long> dists(n+1, INF);
    dists[s] = 0;

    auto cmp = [&dists](int a, int b) {
        if (dists[a] == dists[b]) return a > b;
        return dists[a] > dists[b];
    };

    std::priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.push(s);
    /*for (int i = 1; i <= n; ++i) {
        q.push(i);
    }    */
    vector<bool> done(n+1, false);
    while (!q.empty()) {
    //while (1) {
        
        /*int i_min=-1;
        long long d_min = INF;
        for (int a = 1; a <= n; ++a) {
            if (!done[a] && dists[a] < d_min) {
                d_min = dists[a];
                i_min = a;
            }
        }
        if (i_min == -1) break;
        int a = i_min;*/
        auto a = q.top();
        q.pop();
//        if (done[a]) continue;
        
        //done[a] = true;
        if (dists[a] != INF) {
            for (auto e : g[a]) {                
                if (dists[e.first] > dists[a] + e.second) {
                    dists[e.first] = dists[a] + e.second;
                    q.push(e.first);                    
                }
            }
        }
    }
    vector<long long> res(n-1);
    int r = 0;
    for (int i = 1; i <=n; ++i) {
        if (i != s) {
            res[r++] = dists[i] == INF ? -1 : dists[i];
        }
    }
    
    
    return res;
}

int main()
{    ios_base::sync_with_stdio(false);

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

        vector<vector<long long>> edges(m);
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

        vector<long long> result = shortestReach(n, edges, s);

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

