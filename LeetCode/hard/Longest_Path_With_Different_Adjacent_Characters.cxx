class Solution {
    void solve(int x, vector<vector<int>>& edges, const std::string& labels, vector<int>& max1, vector<int>& max2) {
        for (auto e : edges[x]) {
            solve(e, edges, labels, max1, max2);
            if (labels[e] != labels[x]) {
                int l = max1[e];
                if (l+1 > max1[x]) {
                    max2[x] = max1[x];
                    max1[x] = l+1;
                } else if (l+1 > max2[x]) {
                        max2[x] = l+1;
                }
            }
        }
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> edges(parent.size(), vector<int>());
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] != -1) {
                edges[parent[i]].push_back(i);
            }
        }
        vector<int> max1(parent.size(), 1);
        vector<int> max2(parent.size(), 1);
        solve(0, edges, s, max1, max2);
        // cout << "max1: ";
        // for (auto x : max1)cout << x << " ";
        // cout << "\n";
        // cout << "max2: ";
        // for (auto x : max2)cout << x << " ";
        // cout << "\n";

        int res = 0;
        for (int i = 0; i < max1.size(); ++i) {
            res = max(res, max1[i] + max2[i] - 1);
        }
        return res;
                
    }
};
