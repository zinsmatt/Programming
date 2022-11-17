class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto s = std::accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1)
            return false;

        // dp[i][j] means it is possible to get a sum of j with the i first numbers        
        // dp[i][j] = dp[i-1][j] (do not use the i-est num) OR dp[i-1][j - v[i-1]] (use the i-est num))
        vector<vector<bool>> dp(nums.size(), vector<bool>(s/2+1, false));
        for (int i = 0; i < dp.size(); ++i)
            dp[i][0] = true;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                dp[i][j] = dp[i-1][j];
                if (j - nums[i-1] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
