class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid.front().size();
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (i == 0 && j == 0) continue;
                int v = numeric_limits<int>::max();
                if (i > 0) v = min(v, grid[i-1][j]);
                if (j > 0) v = min(v, grid[i][j-1]);
                
                grid[i][j] += v;
            }
        }
        return grid[h-1][w-1];
    }
};
