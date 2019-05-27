#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int cur = 0;
    int nb = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'U')
        {
            if (cur == -1)
                nb++;
            cur++;
        }
        else{
            cur--;
        }
    }
    return nb;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
