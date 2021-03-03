#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void debug(vector<string>& g)
{
    cout << "\n";
    for (auto x : g)
    cout << x << "\n";
    cout << "\n";
}

vector<vector<int>> move_next(vector<string>& g, int x, int y)
{
    vector<vector<int>> res;
    int i = x, j = y;
    vector<int> last = {-1, -1};
    while (i < g.size() && (g[i][j] == '.' || i == x))
    {
        if (i != x)
        {
            if ((j > 0 && g[i][j-1] == '.') || (j < g[0].size()-1 && g[i][j+1] == '.'))
               res.push_back({i, j});
            else
               last = {i, j};
        }
        ++i;
    }
    if (last[0] != -1) res.push_back(last);
    last = {-1, -1};
    
    i = x; j = y;
    while (i >= 0 && (g[i][j] == '.' || i == x))
    {
        if (i != x)
        {
            if ((j > 0 && g[i][j-1] == '.') || (j < g[0].size()-1 && g[i][j+1] == '.'))
               res.push_back({i, j});
            else
               last = {i, j};
        }
        --i;
    }
    if (last[0] != -1) res.push_back(last);
    last = {-1, -1};

    i = x; j = y;
    while (j < g[0].size() && (g[i][j] == '.' || j == y))
    {
        if (j != y)
        {
            if ((i > 0 && g[i-1][j] == '.') || (i < g.size()-1 && g[i+1][j] == '.'))
                res.push_back({i, j});
            else
               last = {i, j};
        }
        ++j;
    }
    if (last[0] != -1) res.push_back(last);
    last = {-1, -1};
    
    i = x; j = y;
    while (j >= 0 && (g[i][j] == '.' || j == y))
    {
        if (j != y)
        {
            if ((i > 0 && g[i-1][j] == '.') || (i < g.size()-1 && g[i+1][j] == '.'))
                res.push_back({i, j});
            else
               last = {i, j};
        }
        --j;
    }
    if (last[0] != -1) res.push_back(last);
    last = {-1, -1};
    
    return res;
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    std::queue<std::vector<int>> q;
    q.push({startX, startY});
    std::queue<int> d;
    d.push(0);
    while (!q.empty())
    {
        //debug(grid);
        auto X = q.front();
        q.pop();
        auto dist = d.front();
        d.pop();
        if (X[0] == goalX && X[1] == goalY) {
            return dist;
        }
        grid[X[0]][X[1]] = '#';
        auto next = move_next(grid, X[0], X[1]);
        for (auto& b : next) {
            std::cout <<"  next " << b[0] << " " << b[1] << "\n";
            q.push(b);
            d.push(dist+1);
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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

