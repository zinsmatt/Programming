#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {

    std::vector<std::vector<std::pair<int, int>>> g(n+1);
    vector<bool> done(n+1, false);
    vector<bool> used(edges.size(), false);
    done[start] = true;
    int res = 0;
    for (int i = 0; i < n-1; ++i) 
    {
        int idx = -1;
        int min_c = std::numeric_limits<int>::max();
        for (int j = 0; j < edges.size(); ++j)
        {
            if (!used[j] && (done[edges[j][0]] ^ done[edges[j][1]]) && edges[j][2] < min_c)
            {
                min_c = edges[j][2];
                idx = j;
            }
        }
        res += edges[idx][2];
        used[idx] = true;
        done[edges[idx][0]] = true;
        done[edges[idx][1]] = true;
    }
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

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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

