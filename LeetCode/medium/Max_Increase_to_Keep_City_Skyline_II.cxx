class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> max_cols(n, 0);
        vector<int> max_rows(n, 0);
        for (int i = 0; i < n; ++i) {
            int max_c = 0;
            int max_r = 0;
            for (int j = 0; j < n; ++j) {
                max_c = std::max(max_c, grid[j][i]);
                max_cols[i] = max_c;
                
                max_r = std::max(max_r, grid[i][j]);
                max_rows[i] = max_r;                
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += std::min(max_cols[j], max_rows[i]) - grid[i][j];
            }
        }
        return res;
    }
};
