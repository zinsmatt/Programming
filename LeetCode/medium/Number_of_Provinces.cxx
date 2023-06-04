class Solution {
    int res = 0;

    void solve(vector<vector<int>>& edges, int i, vector<int>& prov) {
        prov[i] = res;
        for (auto e : edges[i]) {
            if (prov[e] == -1) {
                solve(edges, e, prov);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> prov(n, -1);
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    edges[i].push_back(j);
                }
            }
        }


        for (int i = 0; i < n; ++i) {
            if (prov[i] == -1) {
                solve(edges, i, prov);
                ++res;
            }
        }
        return res;
    }
};
