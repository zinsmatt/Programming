class Solution {

bool dfs(vector<vector<int>>& g, int i, int j) {
    if (i >= g.size() || i < 0 || j >= g[0].size() || j < 0)
        return false;
    if (g[i][j] == 1)
        return true;
    g[i][j] = 1;
    bool t = dfs(g, i-1, j);
    bool b = dfs(g, i+1, j);
    bool l = dfs(g, i, j-1);
    bool r = dfs(g, i, j+1);
    return t && b && l && r;
}

public:
    int closedIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int nb = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 0) {
                    bool ret = dfs(g, i, j);
                    nb += ret;
                }
            }
        }
        return nb;
    }
};
