class Solution {
    int dp[70][5000];
    
    int solve(vector<vector<int>>& mat, int i, int sum, int target)
    {
        if (i >= mat.size()) {
            return std::abs(sum-target);
        }
        
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        
        int res = std::numeric_limits<int>::max();
        for (int j = 0; j < mat[0].size(); ++j) {
            res = std::min(res, solve(mat, i+1, sum + mat[i][j], target));
            if (res == 0) break;
        }
        dp[i][sum] = res;
        return res;
    }

public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        for (int i = 0; i < 70; ++i) for (int j = 0; j < 5000; ++j) dp[i][j] = -1;
        
        return solve(mat, 0, 0, target);
    }
};
