class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
            }
        }
        int res = 0;
        
        while (!q.empty())
        {
            auto r = q.front();
            q.pop();
            auto i = r[0];
            auto j = r[1];
            auto d = r[2];
            
            if (grid[i][j] == 1)
                res = std::max(res, d);
            
            grid[i][j] = 2;
            
            if (i > 0 && grid[i-1][j] == 1)
            {
                q.push({i-1, j, d+1});
            }
            if (j > 0 && grid[i][j-1] == 1)
            {
                q.push({i, j-1, d+1});
            }
            if (i < grid.size()-1 && grid[i+1][j] == 1)
            {
                q.push({i+1, j, d+1});
            }
            if (j < grid[0].size()-1 && grid[i][j+1] == 1)
            {
                q.push({i, j+1, d+1});
            }
        }
        
        for (auto& v : grid)
        {
            if (find(v.begin(), v.end(), 1) != v.end())
                return -1;
        }
        
        return res;
    }
        
};
