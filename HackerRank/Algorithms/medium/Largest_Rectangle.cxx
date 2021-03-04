#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void print(std::stack<long> s, std::stack<long> h)
{
    cout << "s = ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    cout << "h = ";
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << "\n\n";
}


// Complete the largestRectangle function below.
long largestRectangle(vector<int> arr) {
    arr.push_back(0);
    std::stack<long> s, h;
    long res = 0;
    for (long i = 0; i < arr.size(); ++i) {
        //print(s, h);
        
        long last_w = std::numeric_limits<long>::max();
        while (!s.empty() && h.top() > arr[i]) {
            last_w = s.top();
            auto a = (i-s.top()) * h.top();
            s.pop(); h.pop();
            res = std::max(res, a);            
        }
        
        if (s.empty() || h.top() < arr[i]) {
            s.push(std::min(last_w, i));
            h.push(arr[i]);
        }
    }
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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

