class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        vector<vector<long long>> sum(grid.size(), vector<long long>(grid[0].size(), 0));
        for (int i = 0; i < sum.size(); ++i) {
            for (int j = 0; j < sum[0].size(); ++j) {
                sum[i][j] = grid[i][j];
                if (j > 0)
                    sum[i][j] += sum[i][j-1];
                if (i > 0)
                    sum[i][j] += sum[i-1][j];
                if (i > 0 && j > 0) 
                    sum[i][j] -= sum[i-1][j-1];
            }
        }

        int res = 0;
        for (int i = 0; i < sum.size()-2; ++i) {
            for (int j = 0; j < sum[0].size()-2; ++j) {
                int i2 = i+2;
                int j2 = j+2;

                int rm = 0;
                if (i > 0)
                    rm += sum[i-1][j2];
                if (j > 0)
                    rm += sum[i2][j-1];
                
                if (i > 0 && j > 0)
                    rm -= sum[i-1][j-1];
                
                int total = sum[i2][j2] - rm;

                total -= grid[i+1][j];
                total -= grid[i+1][j+2];
                res = max(res, total);
            }
        }
        return res;
        
    }
};
