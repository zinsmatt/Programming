#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumDistances function below.
int minimumDistances(vector<int> a) {
    std::unordered_map<int, std::vector<int>> map;
    for (int i = 0; i < a.size(); ++i)
    {
        if (map.find(a[i]) != map.end())
        {
            map[a[i]].push_back(i);
        }
        else
        {
            map[a[i]] = std::vector<int>(1, i);
        }
    }

    int res = 999999;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        auto& vec = it->second;
        if (vec.size() < 2 )
            continue;
        std::sort(vec.begin(), vec.end());
        int min_diff = 99999999;
        for (int j = 0; j < vec.size() - 1; ++j)
        {
            min_diff = std::min(min_diff, vec[j+1] - vec[j]);
        }
        res = std::min(res, min_diff);
    }
    if (res == 999999)
    return -1;
    else
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

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
