#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<int> bins_sizes(container.size());
    vector<int> types_sizes(container[0].size(), 0);
    for (int i = 0; i < container.size(); ++i) {
        bins_sizes[i] = std::accumulate(container[i].begin(),
        container[i].end(), 0);
    }
    for (int i = 0; i < container.size(); ++i) {
        for (int j = 0; j < container[0].size(); ++j) {
            types_sizes[j] += container[i][j];
        }
    }
    sort(bins_sizes.begin(), bins_sizes.end()),
    sort(types_sizes.begin(), types_sizes.end());
    if (types_sizes == bins_sizes)
        return "Possible";
    else
        return "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

