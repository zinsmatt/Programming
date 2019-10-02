class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<vector<bool>> maxi(grid.size(), vector<bool>(grid[0].size(), false));
        int h = grid.size();
        int w = grid[0].size();
        vector<int> col_max(h, 0);
        vector<int> row_max(w, 0);
        for (int i = 0; i < h; ++i)
        {
            auto max_element_iter = std::max_element(grid[i].begin(), grid[i].end());
            int max_idx = std::distance(grid[i].begin(), max_element_iter);
            maxi[i][max_idx] = true;
            row_max[i] = *max_element_iter;
        }
        
        for (int j = 0; j < w; ++j)
        {
            int max_idx = 0;
            int max = grid[0][j];
            for (int i = 1; i < h; ++i)
            {
                if (grid[i][j] > max)
                {
                    max = grid[i][j];
                    max_idx = i;
                }
            }
            maxi[max_idx][j] = true;
            col_max[j] = max;
        }
        
        int res = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (maxi[i][j] == false)
                {
                    res += min(col_max[j], row_max[i]) - grid[i][j];
                }
            }
        }
        return res;
    }
};
