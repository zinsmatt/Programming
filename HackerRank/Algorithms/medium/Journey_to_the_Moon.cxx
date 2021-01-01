#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int find(const std::vector<int>& arr, int x)
{
    if (arr[x] == -1) return x;
    else return find(arr, arr[x]);
}

void union_(vector<int>& arr, int x, int y, vector<int>& count)
{
    auto rx = find(arr, x);
    auto ry = find(arr, y);
    if (rx != ry)
    {
        arr[rx] = ry;
        count[ry] += count[rx];
    }
}

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> arr(n, -1), count(n, 1);
    for (auto& p : astronaut) {
        union_(arr, p[0], p[1], count);
    }
    
    std::vector<long> p;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == -1)
        {
            p.push_back(count[i]);
        }
    }
    std::vector<long> s = p;
    for (int i = 1; i < s.size(); ++i)
    {
        s[i] += s[i-1];
    }
    
    long res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        res += p[i] * (s.back()-s[i]);
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

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

