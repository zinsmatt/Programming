class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][1] = std::max(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = dp[i-1][1] + nums[i];
        }
        return std::max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
