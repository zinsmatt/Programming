class Solution {
    vector<pair<int, int>> v1;
    int n;
    void fill(vector<vector<int>>& g, int i, int j) {
        if (g[i][j] == 1) {
            g[i][j] = 2;
            v1.emplace_back(i, j);            
        } else {
            return;
        }

        if (i > 0)
            fill(g, i-1, j);
        if (i < n-1)
            fill(g, i+1, j);
        if (j > 0)
            fill(g, i, j-1);
        if (j < n-1)
            fill(g, i, j+1);
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fill(grid, i, j);
                    ok = true;
                    break;
                }
            }
            if (ok)
                break;
        }


        int dmin = std::numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (auto& p : v1) {
                        dmin = min(dmin, std::abs(i-p.first)+std::abs(j-p.second));
                    }
                }
            }
        }
        return dmin-1;







    }
};
