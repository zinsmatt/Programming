#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    bool ok = true;
    int n = 0;
    vector<int> count(26, 0);
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] == '_')
        {
            n++;
            continue;
        }
        count[b[i]-'A']++;
        if (i == 0)
        {
            ok = ok && (b[0] == b[1]);
        } else if (i == b.size() - 1)
        {
            ok = ok && (b[b.size()-1] == b[b.size()-2]);
        } else
        {
            ok = ok && (b[i] == b[i-1] || b[i] == b[i+1]);
        }
    }
    if (ok) return "YES";
    else
    {
        for (auto c : count)
        {
            if (c == 1)
                return "NO";
        }

        if (n > 0)
            return "YES";
        else
            return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
