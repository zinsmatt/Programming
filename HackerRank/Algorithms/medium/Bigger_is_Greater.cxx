#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    if (w.size() == 1)
        return "no answer";

    int i = w.size() - 2;
    std::vector<char> temp = { w[i+1] };
    while (i >= 0 && w[i] >= w[i+1])
    {
        temp.push_back(w[i]);
        --i;
    }
    if (i == -1)
    {
        return "no answer";
    }

    int smallest_greater = 0;
    while (temp[smallest_greater] <= w[i]) {
        ++smallest_greater;
    }

    std::swap(w[i], temp[smallest_greater]);
    ++i;
    for (int j = 0; j < temp.size(); ++j)
    {
        w[i+j] = temp[j];
    }
    return w;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
