class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        queue<vector<int>> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            int i = x[0];
            int j = x[1];
            int l = x[2];
            // std::cout << i << "  " << j << " " << l << "\n";
            grid[i][j] = 1;
            if (i == n-1 && j == n-1)
                return l+1;
            
            for (int ii = -1; ii <= 1; ++ii) {
                for (int jj = -1; jj <= 1; ++jj) {
                    if (ii != 0 || jj != 0) {
                        if (i+ii >= 0 && j+jj >= 0 && i+ii < n && j+jj < n && grid[i+ii][j+jj] == 0) {
                            grid[i+ii][j+jj] = 1;
                            q.push({i+ii, j+jj, l+1});
                        }
                    }
                }
            }

        }
        return -1;
    }
};
