#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    std::set<int> cur;
    cur.insert(0);
    for (int i = 1; i < n; ++i)
    {
        std::set<int> new_cur;
        for (auto v : cur)
        {
            new_cur.insert(v + a);
            new_cur.insert(v + b);
        }
        cur = std::move(new_cur);
        std::cerr << i << " -> " << cur.size() << "\n";
    }
    std::vector<int> res;
    std::cerr << "=> " << cur.size() << std::endl;
    for (auto v : cur)
        res.push_back(v);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
