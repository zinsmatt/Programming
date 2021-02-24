#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<string> finalize(vector<string> grid) {
    for (auto& s : grid)
        for (auto& c : s)
            if (c == 'i')
                c = 'O';
    return grid;
}

vector<string> fill(vector<string> grid) {
    // fill
    for (auto& s : grid)
        for (auto& c : s)
            if (c == '.')
                c = 'i';
    return grid;
}

vector<string> explose(vector<string> grid) {
    // explose
    auto grid2 = grid;
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            if (grid2[r][c] == 'O') {
                grid[r][c] = '.';
                if (r > 0) grid[r-1][c] = '.';
                if (c > 0) grid[r][c-1] = '.';
                if (r < grid.size()-1) grid[r+1][c] = '.';
                if (c < grid[0].size()-1) grid[r][c+1] = '.';
            }
        }
    }
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            if (grid[r][c] == 'i')
                grid[r][c] = 'O';
        }
    }
    return grid;
}



// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    if (n <= 1) return grid;
    
    n -= 2;
    auto k = n % 4;   
    
    int t = 0;
    for (int t = 0; t <= k ; ++t)
    {
        if (t % 2 == 0)
            grid = fill(grid);
        else
            grid = explose(grid);
    }
    return finalize(grid);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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

