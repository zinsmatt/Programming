class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        
        int res= 0;
        while (!q.empty()) {
            auto x = q.front();
            int u = x[0];
            int v = x[1];
            int d = x[2];
            q.pop();
            res = std::max(res, d);
            ++d;
            if (u > 0 && grid[u-1][v] == 1) {
                q.push({u-1, v, d});
                grid[u-1][v] = 2;
            }
            if (u < grid.size()-1 && grid[u+1][v] == 1) {
                q.push({u+1, v, d});
                grid[u+1][v] = 2;
            }
            if (v > 0 && grid[u][v-1] == 1) {
                q.push({u, v-1, d});
                grid[u][v-1] = 2;
            }
            if (v < grid[0].size()-1 && grid[u][v+1] == 1) {
                grid[u][v+1] = 2;
                q.push({u, v+1, d});
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = -1;
                }
            }
        }
        return res;
    }
};

