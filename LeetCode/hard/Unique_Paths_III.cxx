class Solution {
    
    int solve(vector<vector<int>>& g, int i, int j, int count, int target)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1 || g[i][j] == 3)
            return 0;
        
        count++;
        if (g[i][j] == 2){
            return count == target;
        }
        
        g[i][j] = 3;
        int x = 0;
        x += solve(g, i+1, j, count, target);
        x += solve(g, i-1, j, count, target);
        x += solve(g, i, j+1, count, target);
        x += solve(g, i, j-1, count, target);
        g[i][j] = 0;
        return x;
    }
    
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int target = 0;
        for (auto& v : grid)
            for (auto& x : v)
                if (x != -1)
                    target++;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return solve(grid, i, j, 0, target);
                }
            }
        }
        return -1;
    }
};
