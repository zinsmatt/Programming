#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    std::vector<int> m(9);
    std::iota(m.begin(), m.end(), 1);
    int cost = std::numeric_limits<int>::max();
    //auto best = m;
    while(std::next_permutation(m.begin(), m.end())) {
        int c = 0;
        bool ok = true;
        for (int i = 0; i < 3; ++i) {
            int t = 0, r = 0, d1 = 0, d2 = 0;
            for (int j = 0; j < 3; ++j) {
                c += std::abs(m[i*3+j]-s[i][j]);
                t += m[i*3+j];
                r += m[j*3+i];
                d1 += m[j*3+j];
                d2 += m[j*3+2-j];
            }
            if (t != 15 || r != 15 || d1 != 15 || d2 != 15) {
                ok = false;
                break;
            }
        }
        if (ok && c < cost) {
            cost = c;
            //best = m;
        }
    }
    /*for (int i = 0; i <3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << best[i*3+j] << " ";
        }
        cout << "\n";
    }*/
    
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

