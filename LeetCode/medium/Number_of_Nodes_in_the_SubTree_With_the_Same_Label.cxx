class Solution {

    vector<int> counts;
    array<int, 26> solve(int x, const vector<vector<int>>& edges, const string& labels, int n, vector<bool>& done, vector<int>& counts) {
        done[x] = true;

        array<int, 26> nb;
        nb.fill(0);

        for (auto e : edges[x]) {
            if (!done[e]) {
                auto c = solve(e, edges, labels, n, done, counts);
                for (int i = 0; i <26; ++i) {
                    nb[i] += c[i];
                }
            }
        }
        ++nb[labels[x]-'a'];
        counts[x] = nb[labels[x]-'a'];
        return nb;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> e(labels.size(), vector<int>());
        for (auto &v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }

        counts.resize(labels.size(), 0);
        vector<bool> done(labels.size(), false);
        solve(0, e, labels, labels.size(), done, counts);
        return counts;        
    }
};
