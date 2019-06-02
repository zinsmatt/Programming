#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    if (k >= s.size() + t.size())
     return "Yes";
    int m = 0;
    while (m < s.size() && m < t.size() && s[m] == t[m])
        ++m;
    int r = s.size() - m + t.size() - m;
    if (r == k)
      return "Yes";
    else if (r > k)
      return "No";
    else
    {
        if (m == 0)
          return "Yes";
        else
        {
            if ((k - r) % 2 == 0)
              return "Yes";
            else
                return "No";
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
