#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    auto s = arr;
    sort(s.begin(), s.end());
    std::vector<int> diffs;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != s[i]) {
            diffs.push_back(i);
        }
    }
    
    if (diffs.size() == 0) {
        cout << "yes\n";
    } else if (diffs.size() == 2) {
        std::cout << "yes\n";
        std::cout << "swap " << diffs.front()+1 << " " << diffs.back()+1 << "\n";
    } else {
        bool ok = true;
        for (int i = 0; i < diffs.back() - diffs.front() + 1; ++i)
        {
            if (arr[diffs.front()+i] != s[diffs.back()-i]) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            std::cout << "yes\n";
            std::cout <<"reverse " << diffs.front()+1 << " " << diffs.back()+1 << "\n";
        } else {
            std::cout << "no\n";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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

