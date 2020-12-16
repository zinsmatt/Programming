#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
    int r = A.size()-1;
    while (r > 1)
    {
        int i_max = 0;
        int max = -1;
        
        for (int i = 0; i <= r; ++i) 
        {
            if (A[i] > max) {
                max=  A[i];
                i_max = i;
            }
        }
        
        if (i_max % 2 == r % 2) {
            for (int j = i_max; j < r; ++j) {
                A[j] = A[j+1];                
            }
            A[r] = max;
        } else {
            
            for (int j = i_max; j < r-1; ++j) {
                A[j] = A[j+1];                
            }
            A[r-1] = max;
            A[r-1] = A[r-2];
            A[r-2] = A[r];
            A[r] = max;
        }
        --r;        
    }
    
    if (A[0] < A[1])
        return "YES";
    else
        return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
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

