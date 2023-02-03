class Solution {
    vector<vector<int>> g;
    void solve(int i, int j, int l, const vector<vector<int>>& m) {
        int res = g[i][j];
        auto& v = m[i][j];
        if (i > 0 && m[i-1][j] > v) {
            if (g[i-1][j] == 0)
                solve(i-1, j, l, m);

            res = max(res, g[i-1][j]);
        }
        if (i < g.size()-1 && m[i+1][j] > v) {
            if (g[i+1][j] == 0)
                solve(i+1, j, l, m);
            res = max(res, g[i+1][j]);
        }
        if (j > 0 && m[i][j-1] > v) {
            if (g[i][j-1] == 0)
                solve(i, j-1, l, m);
            res = max(res, g[i][j-1]);
        }
        if (j < g[0].size()-1 && m[i][j+1] > v) {
            if (g[i][j+1] == 0)
                solve(i, j+1, l, m);
            res = max(res, g[i][j+1]);
        }
   
        g[i][j] = res+1;
    }

    void print() {
        for (auto &v : g) {
            for (auto c : v) {
                cout << c << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        g.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (g[i][j] == 0)
                    solve(i, j, 0, matrix);
                res = max(res, g[i][j]);
            }
        }
        return res;                
    }
};
